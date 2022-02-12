static struct mbox_chan *get_pcc_channel(int id)
{
struct mbox_chan *pcc_chan;
if (id < 0 || id > pcc_mbox_ctrl.num_chans)
return ERR_PTR(-ENOENT);
pcc_chan = (struct mbox_chan *)
(unsigned long) pcc_mbox_channels +
(id * sizeof(*pcc_chan));
return pcc_chan;
}
static int get_subspace_id(struct mbox_chan *chan)
{
unsigned int id = chan - pcc_mbox_channels;
if (id < 0 || id > pcc_mbox_ctrl.num_chans)
return -ENOENT;
return id;
}
struct mbox_chan *pcc_mbox_request_channel(struct mbox_client *cl,
int subspace_id)
{
struct device *dev = pcc_mbox_ctrl.dev;
struct mbox_chan *chan;
unsigned long flags;
chan = get_pcc_channel(subspace_id);
if (!chan || chan->cl) {
dev_err(dev, "%s: PCC mailbox not free\n", __func__);
return ERR_PTR(-EBUSY);
}
spin_lock_irqsave(&chan->lock, flags);
chan->msg_free = 0;
chan->msg_count = 0;
chan->active_req = NULL;
chan->cl = cl;
init_completion(&chan->tx_complete);
if (chan->txdone_method == TXDONE_BY_POLL && cl->knows_txdone)
chan->txdone_method |= TXDONE_BY_ACK;
spin_unlock_irqrestore(&chan->lock, flags);
return chan;
}
void pcc_mbox_free_channel(struct mbox_chan *chan)
{
unsigned long flags;
if (!chan || !chan->cl)
return;
spin_lock_irqsave(&chan->lock, flags);
chan->cl = NULL;
chan->active_req = NULL;
if (chan->txdone_method == (TXDONE_BY_POLL | TXDONE_BY_ACK))
chan->txdone_method = TXDONE_BY_POLL;
spin_unlock_irqrestore(&chan->lock, flags);
}
static bool pcc_tx_done(struct mbox_chan *chan)
{
struct acpi_pcct_hw_reduced *pcct_ss = chan->con_priv;
struct acpi_pcct_shared_memory *generic_comm_base =
(struct acpi_pcct_shared_memory *) pcct_ss->base_address;
u16 cmd_delay = pcct_ss->latency;
unsigned int retries = 0;
while (!(readw_relaxed(&generic_comm_base->status)
& PCC_CMD_COMPLETE)) {
if (retries++ < 5)
udelay(cmd_delay);
else {
pr_err("PCC platform did not respond.\n");
return false;
}
}
return true;
}
static int pcc_send_data(struct mbox_chan *chan, void *data)
{
struct acpi_pcct_hw_reduced *pcct_ss = chan->con_priv;
struct acpi_pcct_shared_memory *generic_comm_base =
(struct acpi_pcct_shared_memory *) pcct_ss->base_address;
struct acpi_generic_address doorbell;
u64 doorbell_preserve;
u64 doorbell_val;
u64 doorbell_write;
u16 cmd = *(u16 *) data;
u16 ss_idx = -1;
ss_idx = get_subspace_id(chan);
if (ss_idx < 0) {
pr_err("Invalid Subspace ID from PCC client\n");
return -EINVAL;
}
doorbell = pcct_ss->doorbell_register;
doorbell_preserve = pcct_ss->preserve_mask;
doorbell_write = pcct_ss->write_mask;
writew(cmd, &generic_comm_base->command);
writel((PCCS_SS_SIG_MAGIC | ss_idx), &generic_comm_base->signature);
writew(0, &generic_comm_base->status);
acpi_read(&doorbell_val, &doorbell);
acpi_write((doorbell_val & doorbell_preserve) | doorbell_write,
&doorbell);
return 0;
}
static int parse_pcc_subspace(struct acpi_subtable_header *header,
const unsigned long end)
{
struct acpi_pcct_hw_reduced *pcct_ss;
if (pcc_mbox_ctrl.num_chans <= MAX_PCC_SUBSPACES) {
pcct_ss = (struct acpi_pcct_hw_reduced *) header;
if (pcct_ss->header.type !=
ACPI_PCCT_TYPE_HW_REDUCED_SUBSPACE) {
pr_err("Incorrect PCC Subspace type detected\n");
return -EINVAL;
}
}
return 0;
}
static int __init acpi_pcc_probe(void)
{
acpi_size pcct_tbl_header_size;
struct acpi_table_header *pcct_tbl;
struct acpi_subtable_header *pcct_entry;
int count, i;
acpi_status status = AE_OK;
status = acpi_get_table_with_size(ACPI_SIG_PCCT, 0,
&pcct_tbl,
&pcct_tbl_header_size);
if (ACPI_FAILURE(status) || !pcct_tbl) {
pr_warn("PCCT header not found.\n");
return -ENODEV;
}
count = acpi_table_parse_entries(ACPI_SIG_PCCT,
sizeof(struct acpi_table_pcct),
ACPI_PCCT_TYPE_HW_REDUCED_SUBSPACE,
parse_pcc_subspace, MAX_PCC_SUBSPACES);
if (count <= 0) {
pr_err("Error parsing PCC subspaces from PCCT\n");
return -EINVAL;
}
pcc_mbox_channels = kzalloc(sizeof(struct mbox_chan) *
count, GFP_KERNEL);
if (!pcc_mbox_channels) {
pr_err("Could not allocate space for PCC mbox channels\n");
return -ENOMEM;
}
pcct_entry = (struct acpi_subtable_header *) (
(unsigned long) pcct_tbl + sizeof(struct acpi_table_pcct));
for (i = 0; i < count; i++) {
pcc_mbox_channels[i].con_priv = pcct_entry;
pcct_entry = (struct acpi_subtable_header *)
((unsigned long) pcct_entry + pcct_entry->length);
}
pcc_mbox_ctrl.num_chans = count;
pr_info("Detected %d PCC Subspaces\n", pcc_mbox_ctrl.num_chans);
return 0;
}
static int pcc_mbox_probe(struct platform_device *pdev)
{
int ret = 0;
pcc_mbox_ctrl.chans = pcc_mbox_channels;
pcc_mbox_ctrl.ops = &pcc_chan_ops;
pcc_mbox_ctrl.txdone_poll = true;
pcc_mbox_ctrl.txpoll_period = 10;
pcc_mbox_ctrl.dev = &pdev->dev;
pr_info("Registering PCC driver as Mailbox controller\n");
ret = mbox_controller_register(&pcc_mbox_ctrl);
if (ret) {
pr_err("Err registering PCC as Mailbox controller: %d\n", ret);
ret = -ENODEV;
}
return ret;
}
static int __init pcc_init(void)
{
int ret;
struct platform_device *pcc_pdev;
if (acpi_disabled)
return -ENODEV;
ret = acpi_pcc_probe();
if (ret) {
pr_err("ACPI PCC probe failed.\n");
return -ENODEV;
}
pcc_pdev = platform_create_bundle(&pcc_mbox_driver,
pcc_mbox_probe, NULL, 0, NULL, 0);
if (!pcc_pdev) {
pr_err("Err creating PCC platform bundle\n");
return -ENODEV;
}
return 0;
}
