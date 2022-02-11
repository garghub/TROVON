static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= ( 1 << ( V_2 -> V_5 - V_6 ) ) ;
F_3 ( V_4 , V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 &= ~ ( 1 << ( V_2 -> V_5 - V_6 ) ) ;
F_3 ( V_4 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
F_6 () ;
}
void T_2 F_7 ( int V_7 )
{
int V_8 ;
F_3 ( V_4 , 0 ) ;
F_6 () ;
for ( V_8 = V_7 ; V_8 < V_7 + V_9 ; V_8 ++ )
F_8 ( V_8 , & V_10 ,
V_11 ) ;
for (; V_8 < V_7 + V_12 ; V_8 ++ )
F_9 ( V_8 , & V_13 ) ;
V_6 = V_7 ;
}
