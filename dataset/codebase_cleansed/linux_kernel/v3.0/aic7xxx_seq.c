static int
aic7xxx_patch15_func(struct aic7xxx_host *p)
{
return ((p->bugs & AHC_BUG_SCBCHAN_UPLOAD) != 0);
}
static int
aic7xxx_patch14_func(struct aic7xxx_host *p)
{
return ((p->bugs & AHC_BUG_PCI_2_1_RETRY) != 0);
}
static int
aic7xxx_patch13_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_WIDE) != 0);
}
static int
aic7xxx_patch12_func(struct aic7xxx_host *p)
{
return ((p->bugs & AHC_BUG_AUTOFLUSH) != 0);
}
static int
aic7xxx_patch11_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_ULTRA2) == 0);
}
static int
aic7xxx_patch10_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_CMD_CHAN) == 0);
}
static int
aic7xxx_patch9_func(struct aic7xxx_host *p)
{
return ((p->chip & AHC_CHIPID_MASK) == AHC_AIC7895);
}
static int
aic7xxx_patch8_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_ULTRA) != 0);
}
static int
aic7xxx_patch7_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_ULTRA2) != 0);
}
static int
aic7xxx_patch6_func(struct aic7xxx_host *p)
{
return ((p->flags & AHC_PAGESCBS) == 0);
}
static int
aic7xxx_patch5_func(struct aic7xxx_host *p)
{
return ((p->flags & AHC_PAGESCBS) != 0);
}
static int
aic7xxx_patch4_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_QUEUE_REGS) != 0);
}
static int
aic7xxx_patch3_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_TWIN) != 0);
}
static int
aic7xxx_patch2_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_QUEUE_REGS) == 0);
}
static int
aic7xxx_patch1_func(struct aic7xxx_host *p)
{
return ((p->features & AHC_CMD_CHAN) != 0);
}
static int
aic7xxx_patch0_func(struct aic7xxx_host *p)
{
return (0);
}
