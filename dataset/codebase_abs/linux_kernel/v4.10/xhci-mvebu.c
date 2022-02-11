static void F_1 ( void T_1 * V_1 ,
const struct V_2 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
F_2 ( 0 , V_1 + F_3 ( V_4 ) ) ;
F_2 ( 0 , V_1 + F_4 ( V_4 ) ) ;
}
for ( V_4 = 0 ; V_4 < V_3 -> V_6 ; V_4 ++ ) {
const struct V_7 * V_8 = V_3 -> V_8 + V_4 ;
F_2 ( ( ( V_8 -> V_9 - 1 ) & 0xffff0000 ) | ( V_8 -> V_10 << 8 ) |
( V_3 -> V_11 << 4 ) | 1 ,
V_1 + F_3 ( V_4 ) ) ;
F_2 ( ( V_8 -> V_1 & 0xffff0000 ) , V_1 + F_4 ( V_4 ) ) ;
}
}
int F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 = F_6 ( V_15 ) ;
struct V_20 * V_21 ;
void T_1 * V_1 ;
const struct V_2 * V_3 ;
V_21 = F_7 ( V_19 , V_22 , 1 ) ;
if ( ! V_21 )
return - V_23 ;
V_1 = F_8 ( V_21 -> V_24 , F_9 ( V_21 ) ) ;
if ( ! V_1 )
return - V_23 ;
V_3 = F_10 () ;
F_1 ( V_1 , V_3 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
