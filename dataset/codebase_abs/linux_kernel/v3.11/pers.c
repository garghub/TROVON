void F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
int V_4 )
{
F_2 ( V_5 < V_6 ) ;
F_3 ( V_4 < V_3 -> V_7 ) ;
F_3 ( V_3 -> V_8 <= V_5 ) ;
F_3 ( ! ( V_1 -> V_9 & ( V_10 | V_11 |
V_12 ) ) ) ;
V_1 -> V_9 |= V_11 ;
V_1 -> V_13 = F_4 ( 0 , V_3 -> V_8 - V_4 * V_14 ) ;
V_1 -> V_13 = F_5 (unsigned int, LNET_MAX_IOV, md->length) ;
if ( V_3 -> V_15 )
V_1 -> V_16 = & V_3 -> V_15 [ V_4 * V_14 ] ;
else
V_1 -> V_16 = & V_3 -> V_17 [ V_4 * V_14 ] ;
}
void F_6 ( struct V_2 * V_3 , struct V_18 * V_18 ,
int V_19 , int V_20 )
{
T_2 * V_21 = & V_3 -> V_17 [ V_3 -> V_8 ] ;
V_21 -> V_22 = V_18 ;
V_21 -> V_23 = V_19 ;
V_21 -> V_24 = V_20 ;
V_3 -> V_8 ++ ;
}
