static void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , struct V_8 * V_9 )
{
V_9 -> V_4 = 0x00000001 ;
V_9 -> V_4 |= V_4 ;
V_9 -> V_10 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_9 -> V_6 = V_6 ;
}
void
F_3 ( struct V_1 * V_2 , int V_3 , struct V_8 * V_9 )
{
F_4 ( V_2 , 0x100604 + ( V_3 * 0x10 ) , V_9 -> V_10 ) ;
F_4 ( V_2 , 0x100608 + ( V_3 * 0x10 ) , V_9 -> V_6 ) ;
F_4 ( V_2 , 0x100600 + ( V_3 * 0x10 ) , V_9 -> V_4 ) ;
F_5 ( V_2 , 0x100600 + ( V_3 * 0x10 ) ) ;
}
int
F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = ( void * ) V_12 ;
int V_15 ;
V_15 = F_7 ( & V_14 -> V_16 ) ;
if ( V_15 )
return V_15 ;
F_4 ( V_14 , 0x100850 , 0x80000000 ) ;
F_4 ( V_14 , 0x100800 , 0x00000001 ) ;
return 0 ;
}
