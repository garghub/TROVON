void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 , V_6 ;
T_2 V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_7 = ( V_8 + 1 ) & ( V_9 - 1 ) ;
V_6 = V_2 -> V_10 + ( V_7 * V_11 ) ;
V_4 -> V_12 = F_2 ( F_3 ( V_13 , 1 ) |
F_3 ( V_14 , V_15 ) ) ;
V_5 = F_4 ( V_6 ) ;
V_4 -> V_16 = F_2 ( F_3 ( V_17 , V_6 ) |
F_3 ( V_18 , V_5 ) ) ;
}
}
void F_5 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_10 = V_2 -> V_10 ;
F_6 ( V_20 , V_22 , V_10 ) ;
F_6 ( V_20 , V_23 , F_4 ( V_10 ) ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
}
void F_7 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_26 ;
T_1 V_10 = V_2 -> V_10 ;
F_6 ( V_20 , V_27 , V_10 ) ;
F_6 ( V_20 , V_28 , F_4 ( V_10 ) ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
}
void F_8 ( struct V_19 * V_20 )
{
T_3 V_29 ;
V_29 = V_30 | V_31 ;
F_6 ( V_20 , V_32 , V_29 ) ;
}
void F_9 ( struct V_19 * V_20 )
{
F_6 ( V_20 , V_32 , 0 ) ;
}
