int qib_enable_wc(struct qib_devdata *dd)
{
int ret = 0;
u64 pioaddr, piolen;
unsigned bits;
const unsigned long addr = pci_resource_start(dd->pcidev, 0);
const size_t len = pci_resource_len(dd->pcidev, 0);
if (dd->piobcnt2k && dd->piobcnt4k) {
unsigned long pio2kbase, pio4kbase;
pio2kbase = dd->piobufbase & 0xffffffffUL;
pio4kbase = (dd->piobufbase >> 32) & 0xffffffffUL;
if (pio2kbase < pio4kbase) {
pioaddr = addr + pio2kbase;
piolen = pio4kbase - pio2kbase +
dd->piobcnt4k * dd->align4k;
} else {
pioaddr = addr + pio4kbase;
piolen = pio2kbase - pio4kbase +
dd->piobcnt2k * dd->palign;
}
} else {
pioaddr = addr + dd->piobufbase;
piolen = dd->piobcnt2k * dd->palign +
dd->piobcnt4k * dd->align4k;
}
for (bits = 0; !(piolen & (1ULL << bits)); bits++)
;
if (piolen != (1ULL << bits)) {
piolen >>= bits;
while (piolen >>= 1)
bits++;
piolen = 1ULL << (bits + 1);
}
if (pioaddr & (piolen - 1)) {
u64 atmp = pioaddr & ~(piolen - 1);
if (atmp < addr || (atmp + piolen) > (addr + len)) {
qib_dev_err(dd,
"No way to align address/size (%llx/%llx), no WC mtrr\n",
(unsigned long long) atmp,
(unsigned long long) piolen << 1);
ret = -ENODEV;
} else {
pioaddr = atmp;
piolen <<= 1;
}
}
if (!ret) {
dd->wc_cookie = arch_phys_wc_add(pioaddr, piolen);
if (dd->wc_cookie < 0)
ret = dd->wc_cookie;
}
return ret;
}
void qib_disable_wc(struct qib_devdata *dd)
{
arch_phys_wc_del(dd->wc_cookie);
}
int qib_unordered_wc(void)
{
return boot_cpu_data.x86_vendor != X86_VENDOR_AMD;
}
