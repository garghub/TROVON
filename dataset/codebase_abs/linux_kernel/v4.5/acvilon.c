static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_3 == V_7 )
return;
if ( V_4 & V_8 )
F_3 ( V_3 , V_6 -> V_9 + ( 1 << V_10 ) ) ;
else
F_3 ( V_3 , V_6 -> V_9 + ( 1 << V_11 ) ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_12 ) ;
}
static void F_6 ( void )
{
F_7 ( V_12 , L_1 ) ;
}
static void F_6 ( void )
{
}
static int T_1 F_8 ( void )
{
int V_13 ;
F_9 ( V_14 L_2 , V_15 ) ;
F_6 () ;
V_13 =
F_10 ( V_16 , F_11 ( V_16 ) ) ;
if ( V_13 < 0 )
return V_13 ;
F_12 ( 0 , V_17 ,
F_11 ( V_17 ) ) ;
F_13 ( 1 << 14 ) ;
F_14 ( 5 ) ;
F_15 ( 1 << 14 ) ;
F_16 ( V_18 ,
F_11 ( V_18 ) ) ;
return 0 ;
}
void T_1 F_17 ( void )
{
F_9 ( V_14 L_3 ) ;
F_18 ( V_19 ,
F_11 ( V_19 ) ) ;
}
