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
struct V_14 * V_15 ;
void T_1 * V_1 ;
const struct V_2 * V_3 ;
V_15 = F_6 ( V_13 , V_16 , 1 ) ;
if ( ! V_15 )
return - V_17 ;
V_1 = F_7 ( V_15 -> V_18 , F_8 ( V_15 ) ) ;
if ( ! V_1 )
return - V_17 ;
V_3 = F_9 () ;
F_1 ( V_1 , V_3 ) ;
F_10 ( V_1 ) ;
return 0 ;
}
