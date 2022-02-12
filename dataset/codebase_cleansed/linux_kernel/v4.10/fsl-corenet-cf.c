static irqreturn_t ccf_irq(int irq, void *dev_id)
{
struct ccf_private *ccf = dev_id;
static DEFINE_RATELIMIT_STATE(ratelimit, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
u32 errdet, cecar, cecar2;
u64 addr;
u32 src_id;
bool uvt = false;
bool cap_valid = false;
errdet = ioread32be(&ccf->err_regs->errdet);
cecar = ioread32be(&ccf->err_regs->cecar);
cecar2 = ioread32be(&ccf->err_regs->cecar2);
addr = ioread32be(&ccf->err_regs->cecaddrl);
addr |= ((u64)(ioread32be(&ccf->err_regs->cecaddrh) &
CECADDRH_ADDRH)) << 32;
if (!__ratelimit(&ratelimit))
goto out;
switch (ccf->info->version) {
case CCF1:
if (cecar & CECAR_VAL) {
if (cecar & CECAR_UVT)
uvt = true;
src_id = (cecar & CECAR_SRCID_MASK_CCF1) >>
CECAR_SRCID_SHIFT_CCF1;
cap_valid = true;
}
break;
case CCF2:
if (errdet & ERRDET_CAP) {
src_id = (cecar & CECAR_SRCID_MASK_CCF2) >>
CECAR_SRCID_SHIFT_CCF2;
cap_valid = true;
}
break;
}
dev_crit(ccf->dev, "errdet 0x%08x cecar 0x%08x cecar2 0x%08x\n",
errdet, cecar, cecar2);
if (errdet & ERRDET_LAE) {
if (uvt)
dev_crit(ccf->dev, "LAW Unavailable Target ID\n");
else
dev_crit(ccf->dev, "Local Access Window Error\n");
}
if (errdet & ERRDET_CV)
dev_crit(ccf->dev, "Coherency Violation\n");
if (errdet & ERRDET_UTID)
dev_crit(ccf->dev, "Unavailable Target ID\n");
if (errdet & ERRDET_MCST)
dev_crit(ccf->dev, "Multicast Stash\n");
if (cap_valid) {
dev_crit(ccf->dev, "address 0x%09llx, src id 0x%x\n",
addr, src_id);
}
out:
iowrite32be(errdet, &ccf->err_regs->errdet);
return errdet ? IRQ_HANDLED : IRQ_NONE;
}
static int ccf_probe(struct platform_device *pdev)
{
struct ccf_private *ccf;
struct resource *r;
const struct of_device_id *match;
u32 errinten;
int ret, irq;
match = of_match_device(ccf_matches, &pdev->dev);
if (WARN_ON(!match))
return -ENODEV;
ccf = devm_kzalloc(&pdev->dev, sizeof(*ccf), GFP_KERNEL);
if (!ccf)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "%s: no mem resource\n", __func__);
return -ENXIO;
}
ccf->regs = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(ccf->regs)) {
dev_err(&pdev->dev, "%s: can't map mem resource\n", __func__);
return PTR_ERR(ccf->regs);
}
ccf->dev = &pdev->dev;
ccf->info = match->data;
ccf->err_regs = ccf->regs + ccf->info->err_reg_offs;
if (ccf->info->has_brr) {
u32 brr = ioread32be(ccf->regs + CCF_BRR);
if ((brr & CCF_BRR_IPID) == CCF_BRR_IPID_T1040)
ccf->t1040 = true;
}
dev_set_drvdata(&pdev->dev, ccf);
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "%s: no irq\n", __func__);
return -ENXIO;
}
ret = devm_request_irq(&pdev->dev, irq, ccf_irq, 0, pdev->name, ccf);
if (ret) {
dev_err(&pdev->dev, "%s: can't request irq\n", __func__);
return ret;
}
errinten = ERRDET_LAE | ERRDET_CV;
if (ccf->t1040)
errinten |= ERRDET_UTID | ERRDET_MCST;
switch (ccf->info->version) {
case CCF1:
iowrite32be(errinten, &ccf->err_regs->errdis);
break;
case CCF2:
iowrite32be(0, &ccf->err_regs->errdis);
iowrite32be(errinten, &ccf->err_regs->errinten);
break;
}
return 0;
}
static int ccf_remove(struct platform_device *pdev)
{
struct ccf_private *ccf = dev_get_drvdata(&pdev->dev);
switch (ccf->info->version) {
case CCF1:
iowrite32be(0, &ccf->err_regs->errdis);
break;
case CCF2:
iowrite32be(0, &ccf->err_regs->errinten);
break;
}
return 0;
}
