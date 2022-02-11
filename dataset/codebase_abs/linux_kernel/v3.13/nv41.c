void
F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 )
{
F_2 ( V_2 , 0x100604 + ( V_3 * 0x10 ) , V_5 -> V_6 ) ;
F_2 ( V_2 , 0x100608 + ( V_3 * 0x10 ) , V_5 -> V_7 ) ;
F_2 ( V_2 , 0x100600 + ( V_3 * 0x10 ) , V_5 -> V_8 ) ;
F_3 ( V_2 , 0x100600 + ( V_3 * 0x10 ) ) ;
F_2 ( V_2 , 0x100700 + ( V_3 * 0x04 ) , V_5 -> V_9 ) ;
}
int
F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 ;
int V_14 ;
V_14 = F_5 ( & V_13 -> V_15 ) ;
if ( V_14 )
return V_14 ;
F_2 ( V_13 , 0x100800 , 0x00000001 ) ;
return 0 ;
}
