int F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_1 * V_10 ;
int V_11 = 0 ;
* V_2 = NULL ;
F_2 ( V_4 , & V_7 ) ;
V_11 =
(* V_7 -> F_1 ) ( & V_10 , V_4 , V_5 ) ;
if ( ! V_11 ) {
V_9 = (struct V_8 * ) V_10 ;
V_9 -> V_7 = V_7 ;
* V_2 = V_10 ;
} else {
V_11 = - V_12 ;
}
return V_11 ;
}
void F_3 ( struct V_1 * V_10 )
{
struct V_8 * V_9 = (struct V_8 * ) V_10 ;
struct V_6 * V_7 ;
if ( V_9 ) {
V_7 = V_9 -> V_7 ;
(* V_7 -> F_3 ) ( V_10 ) ;
} else {
F_4 ( V_13 , L_1 ,
V_14 , V_10 ) ;
}
}
