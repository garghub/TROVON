void *
octeon_alloc_soft_command_resp(struct octeon_device *oct,
struct octeon_instr_64B *cmd,
size_t rdatasize)
{
struct octeon_soft_command *sc;
struct octeon_instr_ih *ih;
struct octeon_instr_irh *irh;
struct octeon_instr_rdp *rdp;
sc = (struct octeon_soft_command *)
octeon_alloc_soft_command(oct, 0, rdatasize, 0);
if (!sc)
return NULL;
memcpy(&sc->cmd, cmd, sizeof(struct octeon_instr_64B));
ih = (struct octeon_instr_ih *)&sc->cmd.ih;
ih->fsz = 40;
irh = (struct octeon_instr_irh *)&sc->cmd.irh;
irh->rflag = 1;
irh->len = 4;
rdp = (struct octeon_instr_rdp *)&sc->cmd.rdp;
rdp->pcie_port = oct->pcie_port;
rdp->rlen = rdatasize;
*sc->status_word = COMPLETION_WORD_INIT;
sc->wait_time = 1000;
sc->timeout = jiffies + sc->wait_time;
return sc;
}
int octnet_send_nic_data_pkt(struct octeon_device *oct,
struct octnic_data_pkt *ndata,
u32 xmit_more)
{
int ring_doorbell;
ring_doorbell = !xmit_more;
return octeon_send_command(oct, ndata->q_no, ring_doorbell, &ndata->cmd,
ndata->buf, ndata->datasize,
ndata->reqtype);
}
static void octnet_link_ctrl_callback(struct octeon_device *oct,
u32 status,
void *sc_ptr)
{
struct octeon_soft_command *sc = (struct octeon_soft_command *)sc_ptr;
struct octnic_ctrl_pkt *nctrl;
nctrl = (struct octnic_ctrl_pkt *)sc->ctxptr;
if (!status && nctrl->cb_fn)
nctrl->cb_fn(nctrl);
octeon_free_soft_command(oct, sc);
}
static inline struct octeon_soft_command
*octnic_alloc_ctrl_pkt_sc(struct octeon_device *oct,
struct octnic_ctrl_pkt *nctrl,
struct octnic_ctrl_params nparams)
{
struct octeon_soft_command *sc = NULL;
u8 *data;
size_t rdatasize;
u32 uddsize = 0, datasize = 0;
uddsize = (u32)(nctrl->ncmd.s.more * 8);
datasize = OCTNET_CMD_SIZE + uddsize;
rdatasize = (nctrl->wait_time) ? 16 : 0;
sc = (struct octeon_soft_command *)
octeon_alloc_soft_command(oct, datasize, rdatasize,
sizeof(struct octnic_ctrl_pkt));
if (!sc)
return NULL;
memcpy(sc->ctxptr, nctrl, sizeof(struct octnic_ctrl_pkt));
data = (u8 *)sc->virtdptr;
memcpy(data, &nctrl->ncmd, OCTNET_CMD_SIZE);
octeon_swap_8B_data((u64 *)data, (OCTNET_CMD_SIZE >> 3));
if (uddsize) {
memcpy(data + OCTNET_CMD_SIZE, nctrl->udd, uddsize);
}
octeon_prepare_soft_command(oct, sc, OPCODE_NIC, OPCODE_NIC_CMD,
0, 0, 0);
sc->callback = octnet_link_ctrl_callback;
sc->callback_arg = sc;
sc->wait_time = nctrl->wait_time;
return sc;
}
int
octnet_send_nic_ctrl_pkt(struct octeon_device *oct,
struct octnic_ctrl_pkt *nctrl,
struct octnic_ctrl_params nparams)
{
int retval;
struct octeon_soft_command *sc = NULL;
sc = octnic_alloc_ctrl_pkt_sc(oct, nctrl, nparams);
if (!sc) {
dev_err(&oct->pci_dev->dev, "%s soft command alloc failed\n",
__func__);
return -1;
}
retval = octeon_send_soft_command(oct, sc);
if (retval) {
octeon_free_soft_command(oct, sc);
dev_err(&oct->pci_dev->dev, "%s soft command send failed status: %x\n",
__func__, retval);
return -1;
}
return retval;
}
