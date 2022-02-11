static T_1 F_1 ( void )
{
int V_1 ;
T_1 V_2 ;
T_1 V_3 ;
V_1 = F_2 ( & V_2 , & V_3 ) ;
F_3 ( V_1 ) ;
return V_2 ;
}
static int F_4 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
F_5 ( F_1 () + F_6 () , V_7 ) ;
return F_7 ( V_7 ) ;
}
static int F_8 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
unsigned long V_8 ;
F_9 ( V_7 , & V_8 ) ;
F_10 ( V_8 - F_1 () ) ;
return 0 ;
}
static int T_2 F_11 ( struct V_9 * V_5 )
{
struct V_10 * V_11 ;
V_11 = F_12 ( & V_5 -> V_5 , L_1 , & V_12 ,
V_13 ) ;
if ( F_13 ( V_11 ) )
return F_14 ( V_11 ) ;
F_15 ( V_5 , V_11 ) ;
return 0 ;
}
static int T_3 F_16 ( struct V_9 * V_5 )
{
return 0 ;
}
