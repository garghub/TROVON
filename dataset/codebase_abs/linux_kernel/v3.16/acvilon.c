static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
return;
if ( V_4 & V_9 )
F_2 ( V_3 , V_6 -> V_10 + ( 1 << V_11 ) ) ;
else
F_2 ( V_3 , V_6 -> V_10 + ( 1 << V_12 ) ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_13 ) ;
}
static void F_5 ( void )
{
F_6 ( V_13 , L_1 ) ;
}
static void F_5 ( void )
{
}
static int T_1 F_7 ( void )
{
int V_14 ;
F_8 ( V_15 L_2 , V_16 ) ;
F_5 () ;
V_14 =
F_9 ( V_17 , F_10 ( V_17 ) ) ;
if ( V_14 < 0 )
return V_14 ;
F_11 ( 0 , V_18 ,
F_10 ( V_18 ) ) ;
F_12 ( 1 << 14 ) ;
F_13 ( 5 ) ;
F_14 ( 1 << 14 ) ;
F_15 ( V_19 ,
F_10 ( V_19 ) ) ;
return 0 ;
}
void T_1 F_16 ( void )
{
F_8 ( V_15 L_3 ) ;
F_17 ( V_20 ,
F_10 ( V_20 ) ) ;
}
