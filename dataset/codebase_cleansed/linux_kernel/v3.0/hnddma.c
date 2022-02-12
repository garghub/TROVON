struct hnddma_pub *dma_attach(char *name, si_t *sih,
void *dmaregstx, void *dmaregsrx, uint ntxd,
uint nrxd, uint rxbufsize, int rxextheadroom,
uint nrxpost, uint rxoffset, uint *msg_level)
{
dma_info_t *di;
uint size;
di = kzalloc(sizeof(dma_info_t), GFP_ATOMIC);
if (di == NULL) {
#ifdef BCMDBG
printk(KERN_ERR "dma_attach: out of memory\n");
#endif
return NULL;
}
di->msg_level = msg_level ? msg_level : &dma_msg_level;
di->dma64 = ((ai_core_sflags(sih, 0, 0) & SISF_DMA64) == SISF_DMA64);
di->d64txregs = (dma64regs_t *) dmaregstx;
di->d64rxregs = (dma64regs_t *) dmaregsrx;
di->hnddma.di_fn = (const di_fcn_t *)&dma64proc;
di->hnddma.di_fn->ctrlflags(&di->hnddma, DMA_CTRL_ROC | DMA_CTRL_PEN,
0);
DMA_TRACE(("%s: dma_attach: %s flags 0x%x ntxd %d nrxd %d "
"rxbufsize %d rxextheadroom %d nrxpost %d rxoffset %d "
"dmaregstx %p dmaregsrx %p\n", name, "DMA64",
di->hnddma.dmactrlflags, ntxd, nrxd, rxbufsize,
rxextheadroom, nrxpost, rxoffset, dmaregstx, dmaregsrx));
strncpy(di->name, name, MAXNAMEL);
di->name[MAXNAMEL - 1] = '\0';
di->pbus = ((struct si_info *)sih)->pbus;
di->ntxd = (u16) ntxd;
di->nrxd = (u16) nrxd;
di->rxextrahdrroom =
(rxextheadroom == -1) ? BCMEXTRAHDROOM : rxextheadroom;
if (rxbufsize > BCMEXTRAHDROOM)
di->rxbufsize = (u16) (rxbufsize - di->rxextrahdrroom);
else
di->rxbufsize = (u16) rxbufsize;
di->nrxpost = (u16) nrxpost;
di->rxoffset = (u8) rxoffset;
di->ddoffsetlow = 0;
di->dataoffsetlow = 0;
if (sih->bustype == PCI_BUS) {
di->ddoffsetlow = 0;
di->ddoffsethigh = SI_PCIE_DMA_H32;
di->dataoffsetlow = di->ddoffsetlow;
di->dataoffsethigh = di->ddoffsethigh;
}
#if defined(__mips__) && defined(IL_BIGENDIAN)
di->dataoffsetlow = di->dataoffsetlow + SI_SDRAM_SWAPPED;
#endif
if ((ai_coreid(sih) == SDIOD_CORE_ID)
&& ((ai_corerev(sih) > 0) && (ai_corerev(sih) <= 2)))
di->addrext = 0;
else if ((ai_coreid(sih) == I2S_CORE_ID) &&
((ai_corerev(sih) == 0) || (ai_corerev(sih) == 1)))
di->addrext = 0;
else
di->addrext = _dma_isaddrext(di);
di->aligndesc_4k = _dma_descriptor_align(di);
if (di->aligndesc_4k) {
di->dmadesc_align = D64RINGALIGN_BITS;
if ((ntxd < D64MAXDD / 2) && (nrxd < D64MAXDD / 2)) {
di->dmadesc_align = D64RINGALIGN_BITS - 1;
}
} else
di->dmadesc_align = 4;
DMA_NONE(("DMA descriptor align_needed %d, align %d\n",
di->aligndesc_4k, di->dmadesc_align));
if (ntxd) {
size = ntxd * sizeof(void *);
di->txp = kzalloc(size, GFP_ATOMIC);
if (di->txp == NULL) {
DMA_ERROR(("%s: dma_attach: out of tx memory\n", di->name));
goto fail;
}
}
if (nrxd) {
size = nrxd * sizeof(void *);
di->rxp = kzalloc(size, GFP_ATOMIC);
if (di->rxp == NULL) {
DMA_ERROR(("%s: dma_attach: out of rx memory\n", di->name));
goto fail;
}
}
if (ntxd) {
if (!_dma_alloc(di, DMA_TX))
goto fail;
}
if (nrxd) {
if (!_dma_alloc(di, DMA_RX))
goto fail;
}
if ((di->ddoffsetlow != 0) && !di->addrext) {
if (PHYSADDRLO(di->txdpa) > SI_PCI_DMA_SZ) {
DMA_ERROR(("%s: dma_attach: txdpa 0x%x: addrext not supported\n", di->name, (u32) PHYSADDRLO(di->txdpa)));
goto fail;
}
if (PHYSADDRLO(di->rxdpa) > SI_PCI_DMA_SZ) {
DMA_ERROR(("%s: dma_attach: rxdpa 0x%x: addrext not supported\n", di->name, (u32) PHYSADDRLO(di->rxdpa)));
goto fail;
}
}
DMA_TRACE(("ddoffsetlow 0x%x ddoffsethigh 0x%x dataoffsetlow 0x%x dataoffsethigh " "0x%x addrext %d\n", di->ddoffsetlow, di->ddoffsethigh, di->dataoffsetlow, di->dataoffsethigh, di->addrext));
if (DMASGLIST_ENAB) {
if (ntxd) {
size = ntxd * sizeof(hnddma_seg_map_t);
di->txp_dmah = kzalloc(size, GFP_ATOMIC);
if (di->txp_dmah == NULL)
goto fail;
}
if (nrxd) {
size = nrxd * sizeof(hnddma_seg_map_t);
di->rxp_dmah = kzalloc(size, GFP_ATOMIC);
if (di->rxp_dmah == NULL)
goto fail;
}
}
return (struct hnddma_pub *) di;
fail:
_dma_detach(di);
return NULL;
}
static inline u32 parity32(u32 data)
{
data ^= data >> 16;
data ^= data >> 8;
data ^= data >> 4;
data ^= data >> 2;
data ^= data >> 1;
return data & 1;
}
static bool _dma_alloc(dma_info_t *di, uint direction)
{
return dma64_alloc(di, direction);
}
void *dma_alloc_consistent(struct pci_dev *pdev, uint size, u16 align_bits,
uint *alloced, unsigned long *pap)
{
if (align_bits) {
u16 align = (1 << align_bits);
if (!IS_ALIGNED(PAGE_SIZE, align))
size += align;
*alloced = size;
}
return pci_alloc_consistent(pdev, size, (dma_addr_t *) pap);
}
static void _dma_detach(dma_info_t *di)
{
DMA_TRACE(("%s: dma_detach\n", di->name));
if (di->txd64)
pci_free_consistent(di->pbus, di->txdalloc,
((s8 *)di->txd64 - di->txdalign),
(di->txdpaorig));
if (di->rxd64)
pci_free_consistent(di->pbus, di->rxdalloc,
((s8 *)di->rxd64 - di->rxdalign),
(di->rxdpaorig));
kfree(di->txp);
kfree(di->rxp);
kfree(di->txp_dmah);
kfree(di->rxp_dmah);
kfree(di);
}
static bool _dma_descriptor_align(dma_info_t *di)
{
u32 addrl;
if (di->d64txregs != NULL) {
W_REG(&di->d64txregs->addrlow, 0xff0);
addrl = R_REG(&di->d64txregs->addrlow);
if (addrl != 0)
return false;
} else if (di->d64rxregs != NULL) {
W_REG(&di->d64rxregs->addrlow, 0xff0);
addrl = R_REG(&di->d64rxregs->addrlow);
if (addrl != 0)
return false;
}
return true;
}
static bool _dma_isaddrext(dma_info_t *di)
{
if (di->d64txregs != NULL) {
if (!_dma64_addrext(di->d64txregs)) {
DMA_ERROR(("%s: _dma_isaddrext: DMA64 tx doesn't have "
"AE set\n", di->name));
}
return true;
} else if (di->d64rxregs != NULL) {
if (!_dma64_addrext(di->d64rxregs)) {
DMA_ERROR(("%s: _dma_isaddrext: DMA64 rx doesn't have "
"AE set\n", di->name));
}
return true;
}
return false;
}
static void _dma_ddtable_init(dma_info_t *di, uint direction, dmaaddr_t pa)
{
if (!di->aligndesc_4k) {
if (direction == DMA_TX)
di->xmtptrbase = PHYSADDRLO(pa);
else
di->rcvptrbase = PHYSADDRLO(pa);
}
if ((di->ddoffsetlow == 0)
|| !(PHYSADDRLO(pa) & PCI32ADDR_HIGH)) {
if (direction == DMA_TX) {
W_REG(&di->d64txregs->addrlow,
(PHYSADDRLO(pa) + di->ddoffsetlow));
W_REG(&di->d64txregs->addrhigh,
(PHYSADDRHI(pa) + di->ddoffsethigh));
} else {
W_REG(&di->d64rxregs->addrlow,
(PHYSADDRLO(pa) + di->ddoffsetlow));
W_REG(&di->d64rxregs->addrhigh,
(PHYSADDRHI(pa) + di->ddoffsethigh));
}
} else {
u32 ae;
ae = (PHYSADDRLO(pa) & PCI32ADDR_HIGH) >>
PCI32ADDR_HIGH_SHIFT;
PHYSADDRLO(pa) &= ~PCI32ADDR_HIGH;
if (direction == DMA_TX) {
W_REG(&di->d64txregs->addrlow,
(PHYSADDRLO(pa) + di->ddoffsetlow));
W_REG(&di->d64txregs->addrhigh,
di->ddoffsethigh);
SET_REG(&di->d64txregs->control,
D64_XC_AE, (ae << D64_XC_AE_SHIFT));
} else {
W_REG(&di->d64rxregs->addrlow,
(PHYSADDRLO(pa) + di->ddoffsetlow));
W_REG(&di->d64rxregs->addrhigh,
di->ddoffsethigh);
SET_REG(&di->d64rxregs->control,
D64_RC_AE, (ae << D64_RC_AE_SHIFT));
}
}
}
static void _dma_fifoloopbackenable(dma_info_t *di)
{
DMA_TRACE(("%s: dma_fifoloopbackenable\n", di->name));
OR_REG(&di->d64txregs->control, D64_XC_LE);
}
static void _dma_rxinit(dma_info_t *di)
{
DMA_TRACE(("%s: dma_rxinit\n", di->name));
if (di->nrxd == 0)
return;
di->rxin = di->rxout = 0;
memset((void *)di->rxd64, '\0',
(di->nrxd * sizeof(dma64dd_t)));
if (!di->aligndesc_4k)
_dma_ddtable_init(di, DMA_RX, di->rxdpa);
_dma_rxenable(di);
if (di->aligndesc_4k)
_dma_ddtable_init(di, DMA_RX, di->rxdpa);
}
static void _dma_rxenable(dma_info_t *di)
{
uint dmactrlflags = di->hnddma.dmactrlflags;
u32 control;
DMA_TRACE(("%s: dma_rxenable\n", di->name));
control =
(R_REG(&di->d64rxregs->control) & D64_RC_AE) |
D64_RC_RE;
if ((dmactrlflags & DMA_CTRL_PEN) == 0)
control |= D64_RC_PD;
if (dmactrlflags & DMA_CTRL_ROC)
control |= D64_RC_OC;
W_REG(&di->d64rxregs->control,
((di->rxoffset << D64_RC_RO_SHIFT) | control));
}
static void
_dma_rx_param_get(dma_info_t *di, u16 *rxoffset, u16 *rxbufsize)
{
*rxoffset = (u16) di->rxoffset;
*rxbufsize = (u16) di->rxbufsize;
}
static void *_dma_rx(dma_info_t *di)
{
struct sk_buff *p, *head, *tail;
uint len;
uint pkt_len;
int resid = 0;
next_frame:
head = _dma_getnextrxp(di, false);
if (head == NULL)
return NULL;
len = le16_to_cpu(*(u16 *) (head->data));
DMA_TRACE(("%s: dma_rx len %d\n", di->name, len));
dma_spin_for_len(len, head);
pkt_len = min((di->rxoffset + len), di->rxbufsize);
__skb_trim(head, pkt_len);
resid = len - (di->rxbufsize - di->rxoffset);
if (resid > 0) {
tail = head;
while ((resid > 0) && (p = _dma_getnextrxp(di, false))) {
tail->next = p;
pkt_len = min(resid, (int)di->rxbufsize);
__skb_trim(p, pkt_len);
tail = p;
resid -= di->rxbufsize;
}
#ifdef BCMDBG
if (resid > 0) {
uint cur;
cur =
B2I(((R_REG(&di->d64rxregs->status0) &
D64_RS0_CD_MASK) -
di->rcvptrbase) & D64_RS0_CD_MASK,
dma64dd_t);
DMA_ERROR(("_dma_rx, rxin %d rxout %d, hw_curr %d\n",
di->rxin, di->rxout, cur));
}
#endif
if ((di->hnddma.dmactrlflags & DMA_CTRL_RXMULTI) == 0) {
DMA_ERROR(("%s: dma_rx: bad frame length (%d)\n",
di->name, len));
bcm_pkt_buf_free_skb(head);
di->hnddma.rxgiants++;
goto next_frame;
}
}
return head;
}
static bool _dma_rxfill(dma_info_t *di)
{
struct sk_buff *p;
u16 rxin, rxout;
u32 flags = 0;
uint n;
uint i;
dmaaddr_t pa;
uint extra_offset = 0;
bool ring_empty;
ring_empty = false;
rxin = di->rxin;
rxout = di->rxout;
n = di->nrxpost - NRXDACTIVE(rxin, rxout);
DMA_TRACE(("%s: dma_rxfill: post %d\n", di->name, n));
if (di->rxbufsize > BCMEXTRAHDROOM)
extra_offset = di->rxextrahdrroom;
for (i = 0; i < n; i++) {
p = bcm_pkt_buf_get_skb(di->rxbufsize + extra_offset);
if (p == NULL) {
DMA_ERROR(("%s: dma_rxfill: out of rxbufs\n",
di->name));
if (i == 0 && dma64_rxidle(di)) {
DMA_ERROR(("%s: rxfill64: ring is empty !\n",
di->name));
ring_empty = true;
}
di->hnddma.rxnobuf++;
break;
}
if (extra_offset)
skb_pull(p, extra_offset);
*(u32 *) (p->data) = 0;
if (DMASGLIST_ENAB)
memset(&di->rxp_dmah[rxout], 0,
sizeof(hnddma_seg_map_t));
pa = pci_map_single(di->pbus, p->data,
di->rxbufsize, PCI_DMA_FROMDEVICE);
di->rxp[rxout] = p;
flags = 0;
if (rxout == (di->nrxd - 1))
flags = D64_CTRL1_EOT;
dma64_dd_upd(di, di->rxd64, pa, rxout, &flags,
di->rxbufsize);
rxout = NEXTRXD(rxout);
}
di->rxout = rxout;
W_REG(&di->d64rxregs->ptr,
di->rcvptrbase + I2B(rxout, dma64dd_t));
return ring_empty;
}
static void *_dma_peeknexttxp(dma_info_t *di)
{
uint end, i;
if (di->ntxd == 0)
return NULL;
end =
B2I(((R_REG(&di->d64txregs->status0) &
D64_XS0_CD_MASK) - di->xmtptrbase) & D64_XS0_CD_MASK,
dma64dd_t);
for (i = di->txin; i != end; i = NEXTTXD(i))
if (di->txp[i])
return di->txp[i];
return NULL;
}
static void *_dma_peeknextrxp(dma_info_t *di)
{
uint end, i;
if (di->nrxd == 0)
return NULL;
end =
B2I(((R_REG(&di->d64rxregs->status0) &
D64_RS0_CD_MASK) - di->rcvptrbase) & D64_RS0_CD_MASK,
dma64dd_t);
for (i = di->rxin; i != end; i = NEXTRXD(i))
if (di->rxp[i])
return di->rxp[i];
return NULL;
}
static void _dma_rxreclaim(dma_info_t *di)
{
void *p;
DMA_TRACE(("%s: dma_rxreclaim\n", di->name));
while ((p = _dma_getnextrxp(di, true)))
bcm_pkt_buf_free_skb(p);
}
static void *_dma_getnextrxp(dma_info_t *di, bool forceall)
{
if (di->nrxd == 0)
return NULL;
return dma64_getnextrxp(di, forceall);
}
static void _dma_txblock(dma_info_t *di)
{
di->hnddma.txavail = 0;
}
static void _dma_txunblock(dma_info_t *di)
{
di->hnddma.txavail = di->ntxd - NTXDACTIVE(di->txin, di->txout) - 1;
}
static uint _dma_txactive(dma_info_t *di)
{
return NTXDACTIVE(di->txin, di->txout);
}
static uint _dma_txpending(dma_info_t *di)
{
uint curr;
curr =
B2I(((R_REG(&di->d64txregs->status0) &
D64_XS0_CD_MASK) - di->xmtptrbase) & D64_XS0_CD_MASK,
dma64dd_t);
return NTXDACTIVE(curr, di->txout);
}
static uint _dma_txcommitted(dma_info_t *di)
{
uint ptr;
uint txin = di->txin;
if (txin == di->txout)
return 0;
ptr = B2I(R_REG(&di->d64txregs->ptr), dma64dd_t);
return NTXDACTIVE(di->txin, ptr);
}
static uint _dma_rxactive(dma_info_t *di)
{
return NRXDACTIVE(di->rxin, di->rxout);
}
static void _dma_counterreset(dma_info_t *di)
{
di->hnddma.rxgiants = 0;
di->hnddma.rxnobuf = 0;
di->hnddma.txnobuf = 0;
}
static uint _dma_ctrlflags(dma_info_t *di, uint mask, uint flags)
{
uint dmactrlflags = di->hnddma.dmactrlflags;
if (di == NULL) {
DMA_ERROR(("%s: _dma_ctrlflags: NULL dma handle\n", di->name));
return 0;
}
dmactrlflags &= ~mask;
dmactrlflags |= flags;
if (dmactrlflags & DMA_CTRL_PEN) {
u32 control;
control = R_REG(&di->d64txregs->control);
W_REG(&di->d64txregs->control,
control | D64_XC_PD);
if (R_REG(&di->d64txregs->control) & D64_XC_PD) {
W_REG(&di->d64txregs->control,
control);
} else {
dmactrlflags &= ~DMA_CTRL_PEN;
}
}
di->hnddma.dmactrlflags = dmactrlflags;
return dmactrlflags;
}
static unsigned long _dma_getvar(dma_info_t *di, const char *name)
{
if (!strcmp(name, "&txavail"))
return (unsigned long)&(di->hnddma.txavail);
return 0;
}
static
u8 dma_align_sizetobits(uint size)
{
u8 bitpos = 0;
while (size >>= 1) {
bitpos++;
}
return bitpos;
}
static void *dma_ringalloc(dma_info_t *di, u32 boundary, uint size,
u16 *alignbits, uint *alloced,
dmaaddr_t *descpa)
{
void *va;
u32 desc_strtaddr;
u32 alignbytes = 1 << *alignbits;
va = dma_alloc_consistent(di->pbus, size, *alignbits, alloced, descpa);
if (NULL == va)
return NULL;
desc_strtaddr = (u32) roundup((unsigned long)va, alignbytes);
if (((desc_strtaddr + size - 1) & boundary) != (desc_strtaddr
& boundary)) {
*alignbits = dma_align_sizetobits(size);
pci_free_consistent(di->pbus, size, va, *descpa);
va = dma_alloc_consistent(di->pbus, size, *alignbits,
alloced, descpa);
}
return va;
}
static void dma64_txinit(dma_info_t *di)
{
u32 control = D64_XC_XE;
DMA_TRACE(("%s: dma_txinit\n", di->name));
if (di->ntxd == 0)
return;
di->txin = di->txout = 0;
di->hnddma.txavail = di->ntxd - 1;
memset((void *)di->txd64, '\0', (di->ntxd * sizeof(dma64dd_t)));
if (!di->aligndesc_4k)
_dma_ddtable_init(di, DMA_TX, di->txdpa);
if ((di->hnddma.dmactrlflags & DMA_CTRL_PEN) == 0)
control |= D64_XC_PD;
OR_REG(&di->d64txregs->control, control);
if (di->aligndesc_4k)
_dma_ddtable_init(di, DMA_TX, di->txdpa);
}
static bool dma64_txenabled(dma_info_t *di)
{
u32 xc;
xc = R_REG(&di->d64txregs->control);
return (xc != 0xffffffff) && (xc & D64_XC_XE);
}
static void dma64_txsuspend(dma_info_t *di)
{
DMA_TRACE(("%s: dma_txsuspend\n", di->name));
if (di->ntxd == 0)
return;
OR_REG(&di->d64txregs->control, D64_XC_SE);
}
static void dma64_txresume(dma_info_t *di)
{
DMA_TRACE(("%s: dma_txresume\n", di->name));
if (di->ntxd == 0)
return;
AND_REG(&di->d64txregs->control, ~D64_XC_SE);
}
static bool dma64_txsuspended(dma_info_t *di)
{
return (di->ntxd == 0) ||
((R_REG(&di->d64txregs->control) & D64_XC_SE) ==
D64_XC_SE);
}
static void dma64_txreclaim(dma_info_t *di, txd_range_t range)
{
void *p;
DMA_TRACE(("%s: dma_txreclaim %s\n", di->name,
(range == HNDDMA_RANGE_ALL) ? "all" :
((range ==
HNDDMA_RANGE_TRANSMITTED) ? "transmitted" :
"transferred")));
if (di->txin == di->txout)
return;
while ((p = dma64_getnexttxp(di, range))) {
if (!(di->hnddma.dmactrlflags & DMA_CTRL_UNFRAMED))
bcm_pkt_buf_free_skb(p);
}
}
static bool dma64_txstopped(dma_info_t *di)
{
return ((R_REG(&di->d64txregs->status0) & D64_XS0_XS_MASK) ==
D64_XS0_XS_STOPPED);
}
static bool dma64_rxstopped(dma_info_t *di)
{
return ((R_REG(&di->d64rxregs->status0) & D64_RS0_RS_MASK) ==
D64_RS0_RS_STOPPED);
}
static bool dma64_alloc(dma_info_t *di, uint direction)
{
u16 size;
uint ddlen;
void *va;
uint alloced = 0;
u16 align;
u16 align_bits;
ddlen = sizeof(dma64dd_t);
size = (direction == DMA_TX) ? (di->ntxd * ddlen) : (di->nrxd * ddlen);
align_bits = di->dmadesc_align;
align = (1 << align_bits);
if (direction == DMA_TX) {
va = dma_ringalloc(di, D64RINGALIGN, size, &align_bits,
&alloced, &di->txdpaorig);
if (va == NULL) {
DMA_ERROR(("%s: dma64_alloc: DMA_ALLOC_CONSISTENT(ntxd) failed\n", di->name));
return false;
}
align = (1 << align_bits);
di->txd64 = (dma64dd_t *) roundup((unsigned long)va, align);
di->txdalign = (uint) ((s8 *)di->txd64 - (s8 *) va);
PHYSADDRLOSET(di->txdpa,
PHYSADDRLO(di->txdpaorig) + di->txdalign);
PHYSADDRHISET(di->txdpa, PHYSADDRHI(di->txdpaorig));
di->txdalloc = alloced;
} else {
va = dma_ringalloc(di, D64RINGALIGN, size, &align_bits,
&alloced, &di->rxdpaorig);
if (va == NULL) {
DMA_ERROR(("%s: dma64_alloc: DMA_ALLOC_CONSISTENT(nrxd) failed\n", di->name));
return false;
}
align = (1 << align_bits);
di->rxd64 = (dma64dd_t *) roundup((unsigned long)va, align);
di->rxdalign = (uint) ((s8 *)di->rxd64 - (s8 *) va);
PHYSADDRLOSET(di->rxdpa,
PHYSADDRLO(di->rxdpaorig) + di->rxdalign);
PHYSADDRHISET(di->rxdpa, PHYSADDRHI(di->rxdpaorig));
di->rxdalloc = alloced;
}
return true;
}
static bool dma64_txreset(dma_info_t *di)
{
u32 status;
if (di->ntxd == 0)
return true;
W_REG(&di->d64txregs->control, D64_XC_SE);
SPINWAIT(((status =
(R_REG(&di->d64txregs->status0) & D64_XS0_XS_MASK))
!= D64_XS0_XS_DISABLED) && (status != D64_XS0_XS_IDLE)
&& (status != D64_XS0_XS_STOPPED), 10000);
W_REG(&di->d64txregs->control, 0);
SPINWAIT(((status =
(R_REG(&di->d64txregs->status0) & D64_XS0_XS_MASK))
!= D64_XS0_XS_DISABLED), 10000);
udelay(300);
return status == D64_XS0_XS_DISABLED;
}
static bool dma64_rxidle(dma_info_t *di)
{
DMA_TRACE(("%s: dma_rxidle\n", di->name));
if (di->nrxd == 0)
return true;
return ((R_REG(&di->d64rxregs->status0) & D64_RS0_CD_MASK) ==
(R_REG(&di->d64rxregs->ptr) & D64_RS0_CD_MASK));
}
static bool dma64_rxreset(dma_info_t *di)
{
u32 status;
if (di->nrxd == 0)
return true;
W_REG(&di->d64rxregs->control, 0);
SPINWAIT(((status =
(R_REG(&di->d64rxregs->status0) & D64_RS0_RS_MASK))
!= D64_RS0_RS_DISABLED), 10000);
return status == D64_RS0_RS_DISABLED;
}
static bool dma64_rxenabled(dma_info_t *di)
{
u32 rc;
rc = R_REG(&di->d64rxregs->control);
return (rc != 0xffffffff) && (rc & D64_RC_RE);
}
static bool dma64_txsuspendedidle(dma_info_t *di)
{
if (di->ntxd == 0)
return true;
if (!(R_REG(&di->d64txregs->control) & D64_XC_SE))
return 0;
if ((R_REG(&di->d64txregs->status0) & D64_XS0_XS_MASK) ==
D64_XS0_XS_IDLE)
return 1;
return 0;
}
static void *dma64_getpos(dma_info_t *di, bool direction)
{
void *va;
bool idle;
u32 cd_offset;
if (direction == DMA_TX) {
cd_offset =
R_REG(&di->d64txregs->status0) & D64_XS0_CD_MASK;
idle = !NTXDACTIVE(di->txin, di->txout);
va = di->txp[B2I(cd_offset, dma64dd_t)];
} else {
cd_offset =
R_REG(&di->d64rxregs->status0) & D64_XS0_CD_MASK;
idle = !NRXDACTIVE(di->rxin, di->rxout);
va = di->rxp[B2I(cd_offset, dma64dd_t)];
}
if (idle) {
DMA_TRACE(("%s: DMA idle, return NULL\n", __func__));
va = NULL;
}
return va;
}
static int dma64_txunframed(dma_info_t *di, void *buf, uint len, bool commit)
{
u16 txout;
u32 flags = 0;
dmaaddr_t pa;
txout = di->txout;
if (NEXTTXD(txout) == di->txin)
goto outoftxd;
if (len == 0)
return 0;
pa = pci_map_single(di->pbus, buf, len, PCI_DMA_TODEVICE);
flags = (D64_CTRL1_SOF | D64_CTRL1_IOC | D64_CTRL1_EOF);
if (txout == (di->ntxd - 1))
flags |= D64_CTRL1_EOT;
dma64_dd_upd(di, di->txd64, pa, txout, &flags, len);
di->txp[txout] = buf;
txout = NEXTTXD(txout);
di->txout = txout;
if (commit) {
W_REG(&di->d64txregs->ptr,
di->xmtptrbase + I2B(txout, dma64dd_t));
}
di->hnddma.txavail = di->ntxd - NTXDACTIVE(di->txin, di->txout) - 1;
return 0;
outoftxd:
DMA_ERROR(("%s: %s: out of txds !!!\n", di->name, __func__));
di->hnddma.txavail = 0;
di->hnddma.txnobuf++;
return -1;
}
static int dma64_txfast(dma_info_t *di, struct sk_buff *p0,
bool commit)
{
struct sk_buff *p, *next;
unsigned char *data;
uint len;
u16 txout;
u32 flags = 0;
dmaaddr_t pa;
DMA_TRACE(("%s: dma_txfast\n", di->name));
txout = di->txout;
for (p = p0; p; p = next) {
uint nsegs, j;
hnddma_seg_map_t *map;
data = p->data;
len = p->len;
next = p->next;
if (NEXTTXD(txout) == di->txin)
goto outoftxd;
if (len == 0)
continue;
if (DMASGLIST_ENAB)
memset(&di->txp_dmah[txout], 0,
sizeof(hnddma_seg_map_t));
pa = pci_map_single(di->pbus, data, len, PCI_DMA_TODEVICE);
if (DMASGLIST_ENAB) {
map = &di->txp_dmah[txout];
if (map->nsegs >
(uint) (di->ntxd - NTXDACTIVE(di->txin, di->txout) -
1))
goto outoftxd;
nsegs = map->nsegs;
} else
nsegs = 1;
for (j = 1; j <= nsegs; j++) {
flags = 0;
if (p == p0 && j == 1)
flags |= D64_CTRL1_SOF;
if ((!DMASGLIST_ENAB && next == NULL) ||
(DMASGLIST_ENAB && j == nsegs))
flags |= (D64_CTRL1_IOC | D64_CTRL1_EOF);
if (txout == (di->ntxd - 1))
flags |= D64_CTRL1_EOT;
if (DMASGLIST_ENAB) {
len = map->segs[j - 1].length;
pa = map->segs[j - 1].addr;
}
dma64_dd_upd(di, di->txd64, pa, txout, &flags, len);
txout = NEXTTXD(txout);
}
if (DMASGLIST_ENAB)
break;
}
if (!(flags & D64_CTRL1_EOF))
W_SM(&di->txd64[PREVTXD(txout)].ctrl1,
BUS_SWAP32(flags | D64_CTRL1_IOC | D64_CTRL1_EOF));
di->txp[PREVTXD(txout)] = p0;
di->txout = txout;
if (commit)
W_REG(&di->d64txregs->ptr,
di->xmtptrbase + I2B(txout, dma64dd_t));
di->hnddma.txavail = di->ntxd - NTXDACTIVE(di->txin, di->txout) - 1;
return 0;
outoftxd:
DMA_ERROR(("%s: dma_txfast: out of txds !!!\n", di->name));
bcm_pkt_buf_free_skb(p0);
di->hnddma.txavail = 0;
di->hnddma.txnobuf++;
return -1;
}
static void *dma64_getnexttxp(dma_info_t *di, txd_range_t range)
{
u16 start, end, i;
u16 active_desc;
void *txp;
DMA_TRACE(("%s: dma_getnexttxp %s\n", di->name,
(range == HNDDMA_RANGE_ALL) ? "all" :
((range ==
HNDDMA_RANGE_TRANSMITTED) ? "transmitted" :
"transferred")));
if (di->ntxd == 0)
return NULL;
txp = NULL;
start = di->txin;
if (range == HNDDMA_RANGE_ALL)
end = di->txout;
else {
dma64regs_t *dregs = di->d64txregs;
end =
(u16) (B2I
(((R_REG(&dregs->status0) &
D64_XS0_CD_MASK) -
di->xmtptrbase) & D64_XS0_CD_MASK, dma64dd_t));
if (range == HNDDMA_RANGE_TRANSFERED) {
active_desc =
(u16) (R_REG(&dregs->status1) &
D64_XS1_AD_MASK);
active_desc =
(active_desc - di->xmtptrbase) & D64_XS0_CD_MASK;
active_desc = B2I(active_desc, dma64dd_t);
if (end != active_desc)
end = PREVTXD(active_desc);
}
}
if ((start == 0) && (end > di->txout))
goto bogus;
for (i = start; i != end && !txp; i = NEXTTXD(i)) {
dmaaddr_t pa;
hnddma_seg_map_t *map = NULL;
uint size, j, nsegs;
PHYSADDRLOSET(pa,
(BUS_SWAP32(R_SM(&di->txd64[i].addrlow)) -
di->dataoffsetlow));
PHYSADDRHISET(pa,
(BUS_SWAP32(R_SM(&di->txd64[i].addrhigh)) -
di->dataoffsethigh));
if (DMASGLIST_ENAB) {
map = &di->txp_dmah[i];
size = map->origsize;
nsegs = map->nsegs;
} else {
size =
(BUS_SWAP32(R_SM(&di->txd64[i].ctrl2)) &
D64_CTRL2_BC_MASK);
nsegs = 1;
}
for (j = nsegs; j > 0; j--) {
W_SM(&di->txd64[i].addrlow, 0xdeadbeef);
W_SM(&di->txd64[i].addrhigh, 0xdeadbeef);
txp = di->txp[i];
di->txp[i] = NULL;
if (j > 1)
i = NEXTTXD(i);
}
pci_unmap_single(di->pbus, pa, size, PCI_DMA_TODEVICE);
}
di->txin = i;
di->hnddma.txavail = di->ntxd - NTXDACTIVE(di->txin, di->txout) - 1;
return txp;
bogus:
DMA_NONE(("dma_getnexttxp: bogus curr: start %d end %d txout %d force %d\n", start, end, di->txout, forceall));
return NULL;
}
static void *dma64_getnextrxp(dma_info_t *di, bool forceall)
{
uint i, curr;
void *rxp;
dmaaddr_t pa;
i = di->rxin;
if (i == di->rxout)
return NULL;
curr =
B2I(((R_REG(&di->d64rxregs->status0) & D64_RS0_CD_MASK) -
di->rcvptrbase) & D64_RS0_CD_MASK, dma64dd_t);
if (!forceall && (i == curr))
return NULL;
rxp = di->rxp[i];
di->rxp[i] = NULL;
PHYSADDRLOSET(pa,
(BUS_SWAP32(R_SM(&di->rxd64[i].addrlow)) -
di->dataoffsetlow));
PHYSADDRHISET(pa,
(BUS_SWAP32(R_SM(&di->rxd64[i].addrhigh)) -
di->dataoffsethigh));
pci_unmap_single(di->pbus, pa, di->rxbufsize, PCI_DMA_FROMDEVICE);
W_SM(&di->rxd64[i].addrlow, 0xdeadbeef);
W_SM(&di->rxd64[i].addrhigh, 0xdeadbeef);
di->rxin = NEXTRXD(i);
return rxp;
}
static bool _dma64_addrext(dma64regs_t *dma64regs)
{
u32 w;
OR_REG(&dma64regs->control, D64_XC_AE);
w = R_REG(&dma64regs->control);
AND_REG(&dma64regs->control, ~D64_XC_AE);
return (w & D64_XC_AE) == D64_XC_AE;
}
static void dma64_txrotate(dma_info_t *di)
{
u16 ad;
uint nactive;
uint rot;
u16 old, new;
u32 w;
u16 first, last;
nactive = _dma_txactive(di);
ad = (u16) (B2I
((((R_REG(&di->d64txregs->status1) &
D64_XS1_AD_MASK)
- di->xmtptrbase) & D64_XS1_AD_MASK), dma64dd_t));
rot = TXD(ad - di->txin);
if (rot >= (di->ntxd - nactive)) {
DMA_ERROR(("%s: dma_txrotate: ring full - punt\n", di->name));
return;
}
first = di->txin;
last = PREVTXD(di->txout);
for (old = last; old != PREVTXD(first); old = PREVTXD(old)) {
new = TXD(old + rot);
w = BUS_SWAP32(R_SM(&di->txd64[old].ctrl1)) & ~D64_CTRL1_EOT;
if (new == (di->ntxd - 1))
w |= D64_CTRL1_EOT;
W_SM(&di->txd64[new].ctrl1, BUS_SWAP32(w));
w = BUS_SWAP32(R_SM(&di->txd64[old].ctrl2));
W_SM(&di->txd64[new].ctrl2, BUS_SWAP32(w));
W_SM(&di->txd64[new].addrlow, R_SM(&di->txd64[old].addrlow));
W_SM(&di->txd64[new].addrhigh, R_SM(&di->txd64[old].addrhigh));
W_SM(&di->txd64[old].addrlow, BUS_SWAP32(0xdeadbeef));
W_SM(&di->txd64[old].addrhigh, BUS_SWAP32(0xdeadbeef));
di->txp[new] = di->txp[old];
if (DMASGLIST_ENAB) {
memcpy(&di->txp_dmah[new], &di->txp_dmah[old],
sizeof(hnddma_seg_map_t));
memset(&di->txp_dmah[old], 0, sizeof(hnddma_seg_map_t));
}
di->txp[old] = NULL;
}
di->txin = ad;
di->txout = TXD(di->txout + rot);
di->hnddma.txavail = di->ntxd - NTXDACTIVE(di->txin, di->txout) - 1;
W_REG(&di->d64txregs->ptr,
di->xmtptrbase + I2B(di->txout, dma64dd_t));
}
uint dma_addrwidth(si_t *sih, void *dmaregs)
{
if ((ai_core_sflags(sih, 0, 0) & SISF_DMA64) == SISF_DMA64) {
if (ai_backplane64(sih))
if ((sih->bustype == SI_BUS) ||
((sih->bustype == PCI_BUS) &&
(sih->buscoretype == PCIE_CORE_ID)))
return DMADDRWIDTH_64;
}
return DMADDRWIDTH_64;
}
void dma_walk_packets(struct hnddma_pub *dmah, void (*callback_fnc)
(void *pkt, void *arg_a), void *arg_a)
{
dma_info_t *di = (dma_info_t *) dmah;
uint i = di->txin;
uint end = di->txout;
struct sk_buff *skb;
struct ieee80211_tx_info *tx_info;
while (i != end) {
skb = (struct sk_buff *)di->txp[i];
if (skb != NULL) {
tx_info = (struct ieee80211_tx_info *)skb->cb;
(callback_fnc)(tx_info, arg_a);
}
i = NEXTTXD(i);
}
}
