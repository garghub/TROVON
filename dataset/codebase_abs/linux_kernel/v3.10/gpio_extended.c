static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 ) ;
const unsigned V_6 = F_3 ( V_3 ) ;
return F_4 ( V_5 -> V_7 ) & ( 1 << V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned V_3 , int V_8 )
{
struct V_4 * V_5 =
F_2 ( V_2 ) ;
const unsigned V_6 = F_6 ( V_3 ) ;
F_7 ( 1 << ( V_6 + ( V_8 ? 1 : 0 ) ) , V_5 -> V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_8 )
{
struct V_4 * V_5 =
F_2 ( V_2 ) ;
F_5 ( V_2 , V_3 , V_8 ) ;
F_7 ( 1 << F_9 ( V_3 ) , V_5 -> V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 ) ;
F_7 ( 1 << F_11 ( V_3 ) , V_5 -> V_7 ) ;
return 0 ;
}
void T_1 F_12 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_13 ( V_10 ) ; V_9 ++ )
F_14 ( & V_10 [ V_9 ] . V_2 ) ;
}
