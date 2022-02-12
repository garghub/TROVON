static struct mbox_chan *get_pcc_channel(int id)
{
if (id < 0 || id > pcc_mbox_ctrl.num_chans)
return ERR_PTR(-ENOENT);
return &pcc_mbox_channels[id];
}
struct mbox_chan *pcc_mbox_request_channel(struct mbox_client *cl,
int subspace_id)
{
struct device *dev = pcc_mbox_ctrl.dev;
struct mbox_chan *chan;
unsigned long flags;
chan = get_pcc_channel(subspace_id);
if (IS_ERR(chan) || chan->cl) {
dev_err(dev, "Channel not found for idx: %d\n", subspace_id);
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
static int read_register(void __iomem *vaddr, u64 *val, unsigned int bit_width)
{
int ret_val = 0;
switch (bit_width) {
case 8:
*val = readb(vaddr);
break;
case 16:
*val = readw(vaddr);
break;
case 32:
*val = readl(vaddr);
break;
case 64:
*val = readq(vaddr);
break;
default:
pr_debug("Error: Cannot read register of %u bit width",
bit_width);
ret_val = -EFAULT;
break;
}
return ret_val;
}
static int write_register(void __iomem *vaddr, u64 val, unsigned int bit_width)
{
int ret_val = 0;
switch (bit_width) {
case 8:
writeb(val, vaddr);
break;
case 16:
writew(val, vaddr);
break;
case 32:
writel(val, vaddr);
break;
case 64:
writeq(val, vaddr);
break;
default:
pr_debug("Error: Cannot write register of %u bit width",
bit_width);
ret_val = -EFAULT;
break;
}
return ret_val;
}
static int pcc_send_data(struct mbox_chan *chan, void *data)
{
struct acpi_pcct_hw_reduced *pcct_ss = chan->con_priv;
struct acpi_generic_address *doorbell;
u64 doorbell_preserve;
u64 doorbell_val;
u64 doorbell_write;
u32 id = chan - pcc_mbox_channels;
int ret = 0;
if (id >= pcc_mbox_ctrl.num_chans) {
pr_debug("pcc_send_data: Invalid mbox_chan passed\n");
return -ENOENT;
}
doorbell = &pcct_ss->doorbell_register;
doorbell_preserve = pcct_ss->preserve_mask;
doorbell_write = pcct_ss->write_mask;
if (pcc_doorbell_vaddr[id]) {
ret = read_register(pcc_doorbell_vaddr[id], &doorbell_val,
doorbell->bit_width);
if (ret)
return ret;
ret = write_register(pcc_doorbell_vaddr[id],
(doorbell_val & doorbell_preserve) | doorbell_write,
doorbell->bit_width);
} else {
ret = acpi_read(&doorbell_val, doorbell);
if (ret)
return ret;
ret = acpi_write((doorbell_val & doorbell_preserve) | doorbell_write,
doorbell);
}
return ret;
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
pcc_doorbell_vaddr = kcalloc(count, sizeof(void *), GFP_KERNEL);
if (!pcc_doorbell_vaddr) {
kfree(pcc_mbox_channels);
return -ENOMEM;
}
pcct_entry = (struct acpi_subtable_header *) (
(unsigned long) pcct_tbl + sizeof(struct acpi_table_pcct));
for (i = 0; i < count; i++) {
struct acpi_generic_address *db_reg;
struct acpi_pcct_hw_reduced *pcct_ss;
pcc_mbox_channels[i].con_priv = pcct_entry;
pcct_ss = (struct acpi_pcct_hw_reduced *)pcct_entry;
db_reg = &pcct_ss->doorbell_register;
if (db_reg->space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY)
pcc_doorbell_vaddr[i] = acpi_os_ioremap(db_reg->address,
db_reg->bit_width/8);
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
pr_debug("ACPI PCC probe failed.\n");
return -ENODEV;
}
pcc_pdev = platform_create_bundle(&pcc_mbox_driver,
pcc_mbox_probe, NULL, 0, NULL, 0);
if (IS_ERR(pcc_pdev)) {
pr_debug("Err creating PCC platform bundle\n");
return PTR_ERR(pcc_pdev);
}
return 0;
}
