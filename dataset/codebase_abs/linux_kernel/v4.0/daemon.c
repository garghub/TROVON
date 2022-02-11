static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 = 0x00000000 ;
T_1 V_8 = 0x00000001 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_2 ( V_6 -> signal ) && V_6 -> signal [ V_9 ] ; V_9 ++ )
V_7 |= 1 << ( V_6 -> signal [ V_9 ] - V_4 -> signal ) ;
F_3 ( V_2 , 0x10a504 + ( V_6 -> V_10 * 0x10 ) , V_7 ) ;
F_3 ( V_2 , 0x10a50c + ( V_6 -> V_10 * 0x10 ) , V_8 ) ;
F_3 ( V_2 , 0x10a50c + ( V_2 -> V_11 * 0x10 ) , 0x00000003 ) ;
}
static void
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_6 = V_2 -> V_12 [ V_6 -> V_10 ] ;
V_6 -> V_13 = V_2 -> V_12 [ V_2 -> V_11 ] ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 <= V_2 -> V_11 ; V_9 ++ ) {
V_2 -> V_12 [ V_9 ] = F_6 ( V_2 , 0x10a508 + ( V_9 * 0x10 ) ) ;
F_3 ( V_2 , 0x10a508 + ( V_9 * 0x10 ) , 0x80000000 ) ;
}
}
