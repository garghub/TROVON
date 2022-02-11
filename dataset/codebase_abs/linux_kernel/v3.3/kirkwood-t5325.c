static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 ;
V_10 = F_2 ( V_4 ) * 256 ;
return F_3 ( V_9 , 0 , V_10 , V_11 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
F_5 ( V_15 , L_1 ) ;
F_5 ( V_15 , L_2 ) ;
F_5 ( V_15 , L_3 ) ;
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_16 ;
if ( ! F_7 () )
return 0 ;
V_17 = F_8 ( L_4 , - 1 ) ;
if ( ! V_17 )
return - V_18 ;
F_9 ( V_17 ,
& V_19 ) ;
V_16 = F_10 ( V_17 ) ;
if ( V_16 ) {
F_11 ( V_20 L_5 , V_21 ) ;
F_12 ( V_17 ) ;
}
return V_16 ;
}
static void T_2 F_13 ( void )
{
F_14 ( V_17 ) ;
}
