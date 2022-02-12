int mtk_infracfg_set_bus_protection(struct regmap *infracfg, u32 mask)
{
unsigned long expired;
u32 val;
int ret;
regmap_update_bits(infracfg, INFRA_TOPAXI_PROTECTEN, mask, mask);
expired = jiffies + HZ;
while (1) {
ret = regmap_read(infracfg, INFRA_TOPAXI_PROTECTSTA1, &val);
if (ret)
return ret;
if ((val & mask) == mask)
break;
cpu_relax();
if (time_after(jiffies, expired))
return -EIO;
}
return 0;
}
int mtk_infracfg_clear_bus_protection(struct regmap *infracfg, u32 mask)
{
unsigned long expired;
int ret;
regmap_update_bits(infracfg, INFRA_TOPAXI_PROTECTEN, mask, 0);
expired = jiffies + HZ;
while (1) {
u32 val;
ret = regmap_read(infracfg, INFRA_TOPAXI_PROTECTSTA1, &val);
if (ret)
return ret;
if (!(val & mask))
break;
cpu_relax();
if (time_after(jiffies, expired))
return -EIO;
}
return 0;
}
