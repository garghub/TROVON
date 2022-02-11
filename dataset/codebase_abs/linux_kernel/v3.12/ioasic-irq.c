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
void F_7 ( unsigned int V_5 )
{
T_1 V_7 ;
V_7 = ~ ( 1 << ( V_5 - V_6 ) ) ;
F_3 ( V_8 , V_7 ) ;
}
void T_2 F_8 ( int V_9 )
{
int V_10 ;
F_3 ( V_4 , 0 ) ;
F_6 () ;
for ( V_10 = V_9 ; V_10 < V_9 + V_11 ; V_10 ++ )
F_9 ( V_10 , & V_12 ,
V_13 ) ;
for (; V_10 < V_9 + V_14 ; V_10 ++ )
F_10 ( V_10 , & V_15 ) ;
V_6 = V_9 ;
}
