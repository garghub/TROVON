void armv7m_restart(enum reboot_mode mode, const char *cmd)
{
dsb();
__raw_writel(V7M_SCB_AIRCR_VECTKEY | V7M_SCB_AIRCR_SYSRESETREQ,
BASEADDR_V7M_SCB + V7M_SCB_AIRCR);
dsb();
}
