static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
F_2 (nf_nat_snmp_hook) V_8 ;
F_3 ( V_2 , V_3 , V_5 , V_7 , V_9 ) ;
V_8 = F_4 ( V_10 ) ;
if ( V_8 && V_5 -> V_11 & V_12 )
return V_8 ( V_2 , V_3 , V_5 , V_7 ) ;
return V_13 ;
}
static int T_1 F_5 ( void )
{
V_14 . V_9 = V_9 ;
return F_6 ( & V_15 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_15 ) ;
}
