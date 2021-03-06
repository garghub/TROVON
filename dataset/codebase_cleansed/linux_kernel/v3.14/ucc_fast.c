void ucc_fast_dump_regs(struct ucc_fast_private * uccf)
{
printk(KERN_INFO "UCC%u Fast registers:\n", uccf->uf_info->ucc_num);
printk(KERN_INFO "Base address: 0x%p\n", uccf->uf_regs);
printk(KERN_INFO "gumr : addr=0x%p, val=0x%08x\n",
&uccf->uf_regs->gumr, in_be32(&uccf->uf_regs->gumr));
printk(KERN_INFO "upsmr : addr=0x%p, val=0x%08x\n",
&uccf->uf_regs->upsmr, in_be32(&uccf->uf_regs->upsmr));
printk(KERN_INFO "utodr : addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->utodr, in_be16(&uccf->uf_regs->utodr));
printk(KERN_INFO "udsr : addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->udsr, in_be16(&uccf->uf_regs->udsr));
printk(KERN_INFO "ucce : addr=0x%p, val=0x%08x\n",
&uccf->uf_regs->ucce, in_be32(&uccf->uf_regs->ucce));
printk(KERN_INFO "uccm : addr=0x%p, val=0x%08x\n",
&uccf->uf_regs->uccm, in_be32(&uccf->uf_regs->uccm));
printk(KERN_INFO "uccs : addr=0x%p, val=0x%02x\n",
&uccf->uf_regs->uccs, in_8(&uccf->uf_regs->uccs));
printk(KERN_INFO "urfb : addr=0x%p, val=0x%08x\n",
&uccf->uf_regs->urfb, in_be32(&uccf->uf_regs->urfb));
printk(KERN_INFO "urfs : addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->urfs, in_be16(&uccf->uf_regs->urfs));
printk(KERN_INFO "urfet : addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->urfet, in_be16(&uccf->uf_regs->urfet));
printk(KERN_INFO "urfset: addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->urfset, in_be16(&uccf->uf_regs->urfset));
printk(KERN_INFO "utfb : addr=0x%p, val=0x%08x\n",
&uccf->uf_regs->utfb, in_be32(&uccf->uf_regs->utfb));
printk(KERN_INFO "utfs : addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->utfs, in_be16(&uccf->uf_regs->utfs));
printk(KERN_INFO "utfet : addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->utfet, in_be16(&uccf->uf_regs->utfet));
printk(KERN_INFO "utftt : addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->utftt, in_be16(&uccf->uf_regs->utftt));
printk(KERN_INFO "utpt : addr=0x%p, val=0x%04x\n",
&uccf->uf_regs->utpt, in_be16(&uccf->uf_regs->utpt));
printk(KERN_INFO "urtry : addr=0x%p, val=0x%08x\n",
&uccf->uf_regs->urtry, in_be32(&uccf->uf_regs->urtry));
printk(KERN_INFO "guemr : addr=0x%p, val=0x%02x\n",
&uccf->uf_regs->guemr, in_8(&uccf->uf_regs->guemr));
}
u32 ucc_fast_get_qe_cr_subblock(int uccf_num)
{
switch (uccf_num) {
case 0: return QE_CR_SUBBLOCK_UCCFAST1;
case 1: return QE_CR_SUBBLOCK_UCCFAST2;
case 2: return QE_CR_SUBBLOCK_UCCFAST3;
case 3: return QE_CR_SUBBLOCK_UCCFAST4;
case 4: return QE_CR_SUBBLOCK_UCCFAST5;
case 5: return QE_CR_SUBBLOCK_UCCFAST6;
case 6: return QE_CR_SUBBLOCK_UCCFAST7;
case 7: return QE_CR_SUBBLOCK_UCCFAST8;
default: return QE_CR_SUBBLOCK_INVALID;
}
}
void ucc_fast_transmit_on_demand(struct ucc_fast_private * uccf)
{
out_be16(&uccf->uf_regs->utodr, UCC_FAST_TOD);
}
void ucc_fast_enable(struct ucc_fast_private * uccf, enum comm_dir mode)
{
struct ucc_fast __iomem *uf_regs;
u32 gumr;
uf_regs = uccf->uf_regs;
gumr = in_be32(&uf_regs->gumr);
if (mode & COMM_DIR_TX) {
gumr |= UCC_FAST_GUMR_ENT;
uccf->enabled_tx = 1;
}
if (mode & COMM_DIR_RX) {
gumr |= UCC_FAST_GUMR_ENR;
uccf->enabled_rx = 1;
}
out_be32(&uf_regs->gumr, gumr);
}
void ucc_fast_disable(struct ucc_fast_private * uccf, enum comm_dir mode)
{
struct ucc_fast __iomem *uf_regs;
u32 gumr;
uf_regs = uccf->uf_regs;
gumr = in_be32(&uf_regs->gumr);
if (mode & COMM_DIR_TX) {
gumr &= ~UCC_FAST_GUMR_ENT;
uccf->enabled_tx = 0;
}
if (mode & COMM_DIR_RX) {
gumr &= ~UCC_FAST_GUMR_ENR;
uccf->enabled_rx = 0;
}
out_be32(&uf_regs->gumr, gumr);
}
int ucc_fast_init(struct ucc_fast_info * uf_info, struct ucc_fast_private ** uccf_ret)
{
struct ucc_fast_private *uccf;
struct ucc_fast __iomem *uf_regs;
u32 gumr;
int ret;
if (!uf_info)
return -EINVAL;
if ((uf_info->ucc_num < 0) || (uf_info->ucc_num > UCC_MAX_NUM - 1)) {
printk(KERN_ERR "%s: illegal UCC number\n", __func__);
return -EINVAL;
}
if (uf_info->max_rx_buf_length & (UCC_FAST_MRBLR_ALIGNMENT - 1)) {
printk(KERN_ERR "%s: max_rx_buf_length not aligned\n",
__func__);
return -EINVAL;
}
if (uf_info->urfs < UCC_FAST_URFS_MIN_VAL) {
printk(KERN_ERR "%s: urfs is too small\n", __func__);
return -EINVAL;
}
if (uf_info->urfs & (UCC_FAST_VIRT_FIFO_REGS_ALIGNMENT - 1)) {
printk(KERN_ERR "%s: urfs is not aligned\n", __func__);
return -EINVAL;
}
if (uf_info->urfet & (UCC_FAST_VIRT_FIFO_REGS_ALIGNMENT - 1)) {
printk(KERN_ERR "%s: urfet is not aligned.\n", __func__);
return -EINVAL;
}
if (uf_info->urfset & (UCC_FAST_VIRT_FIFO_REGS_ALIGNMENT - 1)) {
printk(KERN_ERR "%s: urfset is not aligned\n", __func__);
return -EINVAL;
}
if (uf_info->utfs & (UCC_FAST_VIRT_FIFO_REGS_ALIGNMENT - 1)) {
printk(KERN_ERR "%s: utfs is not aligned\n", __func__);
return -EINVAL;
}
if (uf_info->utfet & (UCC_FAST_VIRT_FIFO_REGS_ALIGNMENT - 1)) {
printk(KERN_ERR "%s: utfet is not aligned\n", __func__);
return -EINVAL;
}
if (uf_info->utftt & (UCC_FAST_VIRT_FIFO_REGS_ALIGNMENT - 1)) {
printk(KERN_ERR "%s: utftt is not aligned\n", __func__);
return -EINVAL;
}
uccf = kzalloc(sizeof(struct ucc_fast_private), GFP_KERNEL);
if (!uccf) {
printk(KERN_ERR "%s: Cannot allocate private data\n",
__func__);
return -ENOMEM;
}
uccf->uf_info = uf_info;
uccf->uf_regs = ioremap(uf_info->regs, sizeof(struct ucc_fast));
if (uccf->uf_regs == NULL) {
printk(KERN_ERR "%s: Cannot map UCC registers\n", __func__);
kfree(uccf);
return -ENOMEM;
}
uccf->enabled_tx = 0;
uccf->enabled_rx = 0;
uccf->stopped_tx = 0;
uccf->stopped_rx = 0;
uf_regs = uccf->uf_regs;
uccf->p_ucce = &uf_regs->ucce;
uccf->p_uccm = &uf_regs->uccm;
#ifdef CONFIG_UGETH_TX_ON_DEMAND
uccf->p_utodr = &uf_regs->utodr;
#endif
#ifdef STATISTICS
uccf->tx_frames = 0;
uccf->rx_frames = 0;
uccf->rx_discarded = 0;
#endif
ret = ucc_set_type(uf_info->ucc_num, UCC_SPEED_TYPE_FAST);
if (ret) {
printk(KERN_ERR "%s: cannot set UCC type\n", __func__);
ucc_fast_free(uccf);
return ret;
}
uccf->mrblr = uf_info->max_rx_buf_length;
gumr = uf_info->ttx_trx;
if (uf_info->tci)
gumr |= UCC_FAST_GUMR_TCI;
if (uf_info->cdp)
gumr |= UCC_FAST_GUMR_CDP;
if (uf_info->ctsp)
gumr |= UCC_FAST_GUMR_CTSP;
if (uf_info->cds)
gumr |= UCC_FAST_GUMR_CDS;
if (uf_info->ctss)
gumr |= UCC_FAST_GUMR_CTSS;
if (uf_info->txsy)
gumr |= UCC_FAST_GUMR_TXSY;
if (uf_info->rsyn)
gumr |= UCC_FAST_GUMR_RSYN;
gumr |= uf_info->synl;
if (uf_info->rtsm)
gumr |= UCC_FAST_GUMR_RTSM;
gumr |= uf_info->renc;
if (uf_info->revd)
gumr |= UCC_FAST_GUMR_REVD;
gumr |= uf_info->tenc;
gumr |= uf_info->tcrc;
gumr |= uf_info->mode;
out_be32(&uf_regs->gumr, gumr);
uccf->ucc_fast_tx_virtual_fifo_base_offset =
qe_muram_alloc(uf_info->utfs, UCC_FAST_VIRT_FIFO_REGS_ALIGNMENT);
if (IS_ERR_VALUE(uccf->ucc_fast_tx_virtual_fifo_base_offset)) {
printk(KERN_ERR "%s: cannot allocate MURAM for TX FIFO\n",
__func__);
uccf->ucc_fast_tx_virtual_fifo_base_offset = 0;
ucc_fast_free(uccf);
return -ENOMEM;
}
uccf->ucc_fast_rx_virtual_fifo_base_offset =
qe_muram_alloc(uf_info->urfs +
UCC_FAST_RECEIVE_VIRTUAL_FIFO_SIZE_FUDGE_FACTOR,
UCC_FAST_VIRT_FIFO_REGS_ALIGNMENT);
if (IS_ERR_VALUE(uccf->ucc_fast_rx_virtual_fifo_base_offset)) {
printk(KERN_ERR "%s: cannot allocate MURAM for RX FIFO\n",
__func__);
uccf->ucc_fast_rx_virtual_fifo_base_offset = 0;
ucc_fast_free(uccf);
return -ENOMEM;
}
out_be16(&uf_regs->urfs, uf_info->urfs);
out_be16(&uf_regs->urfet, uf_info->urfet);
out_be16(&uf_regs->urfset, uf_info->urfset);
out_be16(&uf_regs->utfs, uf_info->utfs);
out_be16(&uf_regs->utfet, uf_info->utfet);
out_be16(&uf_regs->utftt, uf_info->utftt);
out_be32(&uf_regs->utfb, uccf->ucc_fast_tx_virtual_fifo_base_offset);
out_be32(&uf_regs->urfb, uccf->ucc_fast_rx_virtual_fifo_base_offset);
ucc_set_qe_mux_grant(uf_info->ucc_num, uf_info->grant_support);
ucc_set_qe_mux_bkpt(uf_info->ucc_num, uf_info->brkpt_support);
ucc_set_qe_mux_tsa(uf_info->ucc_num, uf_info->tsa);
if (!uf_info->tsa) {
if ((uf_info->rx_clock != QE_CLK_NONE) &&
ucc_set_qe_mux_rxtx(uf_info->ucc_num, uf_info->rx_clock,
COMM_DIR_RX)) {
printk(KERN_ERR "%s: illegal value for RX clock\n",
__func__);
ucc_fast_free(uccf);
return -EINVAL;
}
if ((uf_info->tx_clock != QE_CLK_NONE) &&
ucc_set_qe_mux_rxtx(uf_info->ucc_num, uf_info->tx_clock,
COMM_DIR_TX)) {
printk(KERN_ERR "%s: illegal value for TX clock\n",
__func__);
ucc_fast_free(uccf);
return -EINVAL;
}
}
out_be32(&uf_regs->uccm, uf_info->uccm_mask);
out_be32(&uf_regs->ucce, 0xffffffff);
*uccf_ret = uccf;
return 0;
}
void ucc_fast_free(struct ucc_fast_private * uccf)
{
if (!uccf)
return;
if (uccf->ucc_fast_tx_virtual_fifo_base_offset)
qe_muram_free(uccf->ucc_fast_tx_virtual_fifo_base_offset);
if (uccf->ucc_fast_rx_virtual_fifo_base_offset)
qe_muram_free(uccf->ucc_fast_rx_virtual_fifo_base_offset);
if (uccf->uf_regs)
iounmap(uccf->uf_regs);
kfree(uccf);
}
