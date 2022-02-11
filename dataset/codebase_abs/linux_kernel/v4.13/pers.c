void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
int V_6 = V_5 * V_7 ;
F_2 ( V_8 >= V_9 ) ;
F_3 ( V_5 < V_4 -> V_10 ) ;
F_3 ( V_4 -> V_11 <= V_8 ) ;
F_3 ( ! ( V_2 -> V_12 & ( V_13 | V_14 |
V_15 ) ) ) ;
V_2 -> V_16 = F_4 ( 0 , V_4 -> V_11 - V_5 * V_7 ) ;
V_2 -> V_16 = F_5 (unsigned int, LNET_MAX_IOV, md->length) ;
if ( F_6 ( V_4 -> V_17 ) ) {
V_2 -> V_12 |= V_14 ;
if ( F_7 ( V_4 ) )
V_2 -> V_18 = & F_8 ( V_4 , V_6 ) ;
else
V_2 -> V_18 = & F_9 ( V_4 , V_6 ) ;
} else {
V_2 -> V_12 |= V_13 ;
if ( F_10 ( V_4 ) )
V_2 -> V_18 = & F_11 ( V_4 , V_6 ) ;
else
V_2 -> V_18 = & F_12 ( V_4 , V_6 ) ;
}
}
