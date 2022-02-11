void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
V_3 = F_3 () ;
V_2 -> V_4 = V_5 ;
} else {
V_3 = F_4 () ;
V_2 -> V_4 = V_6 ;
}
V_2 -> V_7 = V_3 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
V_2 -> V_8 = F_6 ( V_2 ) ;
}
int F_7 ( struct V_9 * V_2 , T_1 V_10 ,
struct V_11 * V_12 )
{
F_8 ( 3 , L_1 , V_12 -> V_13 ) ;
V_12 -> V_14 = F_9 ( V_2 , V_12 -> V_13 , & V_12 -> V_15 , V_16 ) ;
if ( ! V_12 -> V_14 ) {
F_10 ( L_2 ) ;
return - V_17 ;
}
if ( V_12 -> V_15 < V_10 ) {
F_10 ( L_3 ) ;
F_10 ( L_4 ,
& V_12 -> V_15 , & V_10 ) ;
F_11 ( V_2 , V_12 -> V_13 , V_12 -> V_14 , V_12 -> V_15 ) ;
return - V_17 ;
}
F_8 ( 3 , L_5 , V_12 -> V_14 , & V_12 -> V_15 ) ;
return 0 ;
}
void F_12 ( struct V_9 * V_2 ,
struct V_11 * V_12 )
{
if ( V_12 -> V_14 ) {
F_11 ( V_2 , V_12 -> V_13 , V_12 -> V_14 , V_12 -> V_15 ) ;
V_12 -> V_14 = NULL ;
V_12 -> V_15 = 0 ;
V_12 -> V_13 = 0 ;
}
}
