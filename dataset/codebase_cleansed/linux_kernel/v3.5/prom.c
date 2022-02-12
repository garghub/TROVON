void __init ltq_soc_detect(struct ltq_soc_info *i)
{
i->partnum = (ltq_r32(LTQ_MPS_CHIPID) & PART_MASK) >> PART_SHIFT;
i->rev = (ltq_r32(LTQ_MPS_CHIPID) & REV_MASK) >> REV_SHIFT;
sprintf(i->rev_type, "1.%d", i->rev);
switch (i->partnum) {
case SOC_ID_DANUBE1:
case SOC_ID_DANUBE2:
i->name = SOC_DANUBE;
i->type = SOC_TYPE_DANUBE;
i->compatible = COMP_DANUBE;
break;
case SOC_ID_TWINPASS:
i->name = SOC_TWINPASS;
i->type = SOC_TYPE_DANUBE;
i->compatible = COMP_TWINPASS;
break;
case SOC_ID_ARX188:
case SOC_ID_ARX168_1:
case SOC_ID_ARX168_2:
case SOC_ID_ARX182:
i->name = SOC_AR9;
i->type = SOC_TYPE_AR9;
i->compatible = COMP_AR9;
break;
case SOC_ID_GRX188:
case SOC_ID_GRX168:
i->name = SOC_GR9;
i->type = SOC_TYPE_AR9;
i->compatible = COMP_GR9;
break;
case SOC_ID_AMAZON_SE_1:
case SOC_ID_AMAZON_SE_2:
#ifdef CONFIG_PCI
panic("ase is only supported for non pci kernels");
#endif
i->name = SOC_AMAZON_SE;
i->type = SOC_TYPE_AMAZON_SE;
i->compatible = COMP_AMAZON_SE;
break;
case SOC_ID_VRX282:
case SOC_ID_VRX268:
case SOC_ID_VRX288:
i->name = SOC_VR9;
i->type = SOC_TYPE_VR9;
i->compatible = COMP_VR9;
break;
case SOC_ID_GRX268:
case SOC_ID_GRX288:
i->name = SOC_GR9;
i->type = SOC_TYPE_VR9;
i->compatible = COMP_GR9;
break;
case SOC_ID_VRX268_2:
case SOC_ID_VRX288_2:
i->name = SOC_VR9;
i->type = SOC_TYPE_VR9_2;
i->compatible = COMP_VR9;
break;
case SOC_ID_GRX282_2:
case SOC_ID_GRX288_2:
i->name = SOC_GR9;
i->type = SOC_TYPE_VR9_2;
i->compatible = COMP_GR9;
break;
default:
unreachable();
break;
}
}
