int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned V_5 , V_6 , V_7 ;
struct V_8 * V_9 ;
V_4 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_4 -> V_10 . V_11 ) ;
V_6 = F_3 ( V_4 -> V_10 . V_12 ) ;
V_7 = F_3 ( V_4 -> V_10 . V_13 ) ;
for ( V_9 = V_14 ; V_9 -> V_5 ; ++ V_9 ) {
if ( V_9 -> V_5 == V_5 && V_9 -> V_6 == V_6 &&
V_9 -> V_15 <= V_7 && V_9 -> V_16 >= V_7 )
return - V_17 ;
}
return 0 ;
}
