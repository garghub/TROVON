unsigned int convert_ifc_address(phys_addr_t addr_base)
{
return addr_base & CSPR_BA;
}
int fsl_ifc_find(phys_addr_t addr_base)
{
int i = 0;
if (!fsl_ifc_ctrl_dev || !fsl_ifc_ctrl_dev->regs)
return -ENODEV;
for (i = 0; i < ARRAY_SIZE(fsl_ifc_ctrl_dev->regs->cspr_cs); i++) {
u32 cspr = in_be32(&fsl_ifc_ctrl_dev->regs->cspr_cs[i].cspr);
if (cspr & CSPR_V && (cspr & CSPR_BA) ==
convert_ifc_address(addr_base))
return i;
}
return -ENOENT;
}
static int fsl_ifc_ctrl_init(struct fsl_ifc_ctrl *ctrl)
{
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
if (in_be32(&ifc->cm_evter_stat) & IFC_CM_EVTER_STAT_CSER)
out_be32(&ifc->cm_evter_stat, IFC_CM_EVTER_STAT_CSER);
out_be32(&ifc->cm_evter_en, IFC_CM_EVTER_EN_CSEREN);
out_be32(&ifc->cm_evter_intr_en, IFC_CM_EVTER_INTR_EN_CSERIREN);
out_be32(&ifc->cm_erattr0, 0x0);
out_be32(&ifc->cm_erattr1, 0x0);
return 0;
}
static int fsl_ifc_ctrl_remove(struct platform_device *dev)
{
struct fsl_ifc_ctrl *ctrl = dev_get_drvdata(&dev->dev);
free_irq(ctrl->nand_irq, ctrl);
free_irq(ctrl->irq, ctrl);
irq_dispose_mapping(ctrl->nand_irq);
irq_dispose_mapping(ctrl->irq);
iounmap(ctrl->regs);
dev_set_drvdata(&dev->dev, NULL);
kfree(ctrl);
return 0;
}
static u32 check_nand_stat(struct fsl_ifc_ctrl *ctrl)
{
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
unsigned long flags;
u32 stat;
spin_lock_irqsave(&nand_irq_lock, flags);
stat = in_be32(&ifc->ifc_nand.nand_evter_stat);
if (stat) {
out_be32(&ifc->ifc_nand.nand_evter_stat, stat);
ctrl->nand_stat = stat;
wake_up(&ctrl->nand_wait);
}
spin_unlock_irqrestore(&nand_irq_lock, flags);
return stat;
}
static irqreturn_t fsl_ifc_nand_irq(int irqno, void *data)
{
struct fsl_ifc_ctrl *ctrl = data;
if (check_nand_stat(ctrl))
return IRQ_HANDLED;
return IRQ_NONE;
}
static irqreturn_t fsl_ifc_ctrl_irq(int irqno, void *data)
{
struct fsl_ifc_ctrl *ctrl = data;
struct fsl_ifc_regs __iomem *ifc = ctrl->regs;
u32 err_axiid, err_srcid, status, cs_err, err_addr;
irqreturn_t ret = IRQ_NONE;
cs_err = in_be32(&ifc->cm_evter_stat);
if (cs_err) {
dev_err(ctrl->dev, "transaction sent to IFC is not mapped to"
"any memory bank 0x%08X\n", cs_err);
out_be32(&ifc->cm_evter_stat, IFC_CM_EVTER_STAT_CSER);
status = in_be32(&ifc->cm_erattr0);
err_addr = in_be32(&ifc->cm_erattr1);
if (status & IFC_CM_ERATTR0_ERTYP_READ)
dev_err(ctrl->dev, "Read transaction error"
"CM_ERATTR0 0x%08X\n", status);
else
dev_err(ctrl->dev, "Write transaction error"
"CM_ERATTR0 0x%08X\n", status);
err_axiid = (status & IFC_CM_ERATTR0_ERAID) >>
IFC_CM_ERATTR0_ERAID_SHIFT;
dev_err(ctrl->dev, "AXI ID of the error"
"transaction 0x%08X\n", err_axiid);
err_srcid = (status & IFC_CM_ERATTR0_ESRCID) >>
IFC_CM_ERATTR0_ESRCID_SHIFT;
dev_err(ctrl->dev, "SRC ID of the error"
"transaction 0x%08X\n", err_srcid);
dev_err(ctrl->dev, "Transaction Address corresponding to error"
"ERADDR 0x%08X\n", err_addr);
ret = IRQ_HANDLED;
}
if (check_nand_stat(ctrl))
ret = IRQ_HANDLED;
return ret;
}
static int fsl_ifc_ctrl_probe(struct platform_device *dev)
{
int ret = 0;
dev_info(&dev->dev, "Freescale Integrated Flash Controller\n");
fsl_ifc_ctrl_dev = kzalloc(sizeof(*fsl_ifc_ctrl_dev), GFP_KERNEL);
if (!fsl_ifc_ctrl_dev)
return -ENOMEM;
dev_set_drvdata(&dev->dev, fsl_ifc_ctrl_dev);
fsl_ifc_ctrl_dev->regs = of_iomap(dev->dev.of_node, 0);
if (!fsl_ifc_ctrl_dev->regs) {
dev_err(&dev->dev, "failed to get memory region\n");
ret = -ENODEV;
goto err;
}
fsl_ifc_ctrl_dev->irq = irq_of_parse_and_map(dev->dev.of_node, 0);
if (fsl_ifc_ctrl_dev->irq == NO_IRQ) {
dev_err(&dev->dev, "failed to get irq resource "
"for IFC\n");
ret = -ENODEV;
goto err;
}
fsl_ifc_ctrl_dev->nand_irq =
irq_of_parse_and_map(dev->dev.of_node, 1);
fsl_ifc_ctrl_dev->dev = &dev->dev;
ret = fsl_ifc_ctrl_init(fsl_ifc_ctrl_dev);
if (ret < 0)
goto err;
init_waitqueue_head(&fsl_ifc_ctrl_dev->nand_wait);
ret = request_irq(fsl_ifc_ctrl_dev->irq, fsl_ifc_ctrl_irq, IRQF_SHARED,
"fsl-ifc", fsl_ifc_ctrl_dev);
if (ret != 0) {
dev_err(&dev->dev, "failed to install irq (%d)\n",
fsl_ifc_ctrl_dev->irq);
goto err_irq;
}
if (fsl_ifc_ctrl_dev->nand_irq) {
ret = request_irq(fsl_ifc_ctrl_dev->nand_irq, fsl_ifc_nand_irq,
0, "fsl-ifc-nand", fsl_ifc_ctrl_dev);
if (ret != 0) {
dev_err(&dev->dev, "failed to install irq (%d)\n",
fsl_ifc_ctrl_dev->nand_irq);
goto err_nandirq;
}
}
return 0;
err_nandirq:
free_irq(fsl_ifc_ctrl_dev->nand_irq, fsl_ifc_ctrl_dev);
irq_dispose_mapping(fsl_ifc_ctrl_dev->nand_irq);
err_irq:
free_irq(fsl_ifc_ctrl_dev->irq, fsl_ifc_ctrl_dev);
irq_dispose_mapping(fsl_ifc_ctrl_dev->irq);
err:
return ret;
}
static int __init fsl_ifc_init(void)
{
return platform_driver_register(&fsl_ifc_ctrl_driver);
}
