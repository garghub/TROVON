unsigned long ltq_danube_fpi_hz(void)
{
unsigned long ddr_clock = DDR_HZ;
if (ltq_cgu_r32(CGU_SYS) & 0x40)
return ddr_clock >> 1;
return ddr_clock;
}
unsigned long ltq_danube_cpu_hz(void)
{
switch (ltq_cgu_r32(CGU_SYS) & 0xc) {
case 0:
return CLOCK_333M;
case 4:
return DDR_HZ;
case 8:
return DDR_HZ << 1;
default:
return DDR_HZ >> 1;
}
}
unsigned long ltq_ar9_sys_hz(void)
{
if (((ltq_cgu_r32(CGU_SYS) >> 3) & 0x3) == 0x2)
return CLOCK_393M;
return CLOCK_333M;
}
unsigned long ltq_ar9_fpi_hz(void)
{
unsigned long sys = ltq_ar9_sys_hz();
if (ltq_cgu_r32(CGU_SYS) & BIT(0))
return sys;
return sys >> 1;
}
unsigned long ltq_ar9_cpu_hz(void)
{
if (ltq_cgu_r32(CGU_SYS) & BIT(2))
return ltq_ar9_fpi_hz();
else
return ltq_ar9_sys_hz();
}
unsigned long ltq_vr9_cpu_hz(void)
{
unsigned int cpu_sel;
unsigned long clk;
cpu_sel = (ltq_cgu_r32(CGU_SYS_VR9) >> 4) & 0xf;
switch (cpu_sel) {
case 0:
clk = CLOCK_600M;
break;
case 1:
clk = CLOCK_500M;
break;
case 2:
clk = CLOCK_393M;
break;
case 3:
clk = CLOCK_333M;
break;
case 5:
case 6:
clk = CLOCK_196_608M;
break;
case 7:
clk = CLOCK_167M;
break;
case 4:
case 8:
case 9:
clk = CLOCK_125M;
break;
default:
clk = 0;
break;
}
return clk;
}
unsigned long ltq_vr9_fpi_hz(void)
{
unsigned int ocp_sel, cpu_clk;
unsigned long clk;
cpu_clk = ltq_vr9_cpu_hz();
ocp_sel = ltq_cgu_r32(CGU_SYS_VR9) & 0x3;
switch (ocp_sel) {
case 0:
clk = cpu_clk;
break;
case 2:
clk = cpu_clk / 2;
break;
case 3:
clk = (cpu_clk * 2) / 5;
break;
case 4:
clk = cpu_clk / 3;
break;
default:
clk = 0;
break;
}
return clk;
}
