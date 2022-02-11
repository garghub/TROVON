static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
F_5 ( & V_2 ) ;
F_6 ( 0 , 1 ) ;
F_6 ( 1 , 2 ) ;
F_6 ( 2 , 3 ) ;
V_3 |= V_4 ;
}
static void F_7 ( struct V_5 * V_6 , T_2 V_7 , T_2 V_8 )
{
}
static void F_8 ( struct V_5 * V_6 , T_2 V_9 )
{
#if 0
if (port->mapbase == _Ser1UTCR0) {
u_int set = 0, clear = 0;
if (mctrl & TIOCM_RTS)
set |= PT_CTRL2_RS1_RTS;
else
clear |= PT_CTRL2_RS1_RTS;
if (mctrl & TIOCM_DTR)
set |= PT_CTRL2_RS1_DTR;
else
clear |= PT_CTRL2_RS1_DTR;
PTCTRL2_clear(clear);
PTCTRL2_set(set);
}
#endif
}
static T_2 F_9 ( struct V_5 * V_6 )
{
T_2 V_10 = 0 ;
#if 0
u_int irqsr = PT_IRQSR;
irqsr = PT_IRQSR;
#endif
V_10 = V_11 | V_12 | V_13 ;
return V_10 ;
}
static void T_1 F_10 ( void )
{
F_11 ( & V_14 , & V_15 , 1 ) ;
F_12 ( & V_16 ) ;
}
