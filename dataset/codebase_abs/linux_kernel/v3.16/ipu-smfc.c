int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
T_1 V_9 , V_10 ;
F_2 ( & V_6 -> V_11 , V_8 ) ;
V_10 = V_3 * 4 ;
V_9 = F_3 ( V_6 -> V_12 + V_13 ) ;
V_9 &= ~ ( 0xf << V_10 ) ;
V_9 |= V_4 << V_10 ;
F_4 ( V_9 , V_6 -> V_12 + V_13 ) ;
F_5 ( & V_6 -> V_11 , V_8 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 , int V_14 , int V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
T_1 V_9 , V_10 ;
F_2 ( & V_6 -> V_11 , V_8 ) ;
V_10 = V_3 * 3 ;
V_9 = F_3 ( V_6 -> V_12 + V_16 ) ;
V_9 &= ~ ( 0x7 << V_10 ) ;
V_9 |= ( ( V_14 << 2 ) | V_15 ) << V_10 ;
F_4 ( V_9 , V_6 -> V_12 + V_16 ) ;
F_5 ( & V_6 -> V_11 , V_8 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , struct V_17 * V_18 ,
unsigned long V_12 )
{
struct V_5 * V_6 ;
V_6 = F_8 ( V_18 , sizeof( * V_6 ) , V_19 ) ;
if ( ! V_6 )
return - V_20 ;
V_2 -> V_7 = V_6 ;
F_9 ( & V_6 -> V_11 ) ;
V_6 -> V_12 = F_10 ( V_18 , V_12 , V_21 ) ;
if ( ! V_6 -> V_12 )
return - V_20 ;
F_11 ( L_1 , V_22 , V_12 , V_6 -> V_12 ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
}
