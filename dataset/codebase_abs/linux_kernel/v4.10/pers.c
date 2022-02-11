void F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
int V_4 )
{
int V_5 = V_4 * V_6 ;
F_2 ( V_7 < V_8 ) ;
F_3 ( V_4 < V_3 -> V_9 ) ;
F_3 ( V_3 -> V_10 <= V_7 ) ;
F_3 ( ! ( V_1 -> V_11 & ( V_12 | V_13 |
V_14 ) ) ) ;
V_1 -> V_15 = F_4 ( 0 , V_3 -> V_10 - V_4 * V_6 ) ;
V_1 -> V_15 = F_5 (unsigned int, LNET_MAX_IOV, md->length) ;
if ( F_6 ( V_3 -> V_16 ) ) {
V_1 -> V_11 |= V_13 ;
if ( F_7 ( V_3 ) )
V_1 -> V_17 = & F_8 ( V_3 , V_5 ) ;
else
V_1 -> V_17 = & F_9 ( V_3 , V_5 ) ;
} else {
V_1 -> V_11 |= V_12 ;
if ( F_10 ( V_3 ) )
V_1 -> V_17 = & F_11 ( V_3 , V_5 ) ;
else
V_1 -> V_17 = & F_12 ( V_3 , V_5 ) ;
}
}
