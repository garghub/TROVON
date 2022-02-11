static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
F_2 ( V_5 , V_6 , 0xab ) ;
F_2 ( V_5 , V_7 , 0x00000040 ) ;
F_2 ( V_5 , V_8 , V_9 ) ;
F_3 ( V_5 , V_10 ,
V_11 , V_11 ) ;
return V_12 ;
}
static int F_4 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_17 ;
V_5 = F_5 ( V_16 -> V_18 , L_1 ) ;
if ( F_6 ( V_5 ) ) {
F_7 ( L_2 , V_16 -> V_18 -> V_19 ) ;
return F_8 ( V_5 ) ;
}
V_17 = F_9 ( & V_20 ) ;
if ( V_17 )
F_10 ( V_16 , L_3 , V_17 ) ;
return V_17 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_21 ) ;
}
