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
int F_5 ( struct V_8 * V_2 ,
struct V_9 * V_10 )
{
F_6 ( 3 , L_1 , V_10 -> V_11 ) ;
V_10 -> V_12 = F_7 ( V_2 , V_10 -> V_11 , & V_10 -> V_13 , V_14 ) ;
if ( ! V_10 -> V_12 ) {
F_8 ( L_2 ) ;
return - V_15 ;
}
F_6 ( 3 , L_3 , V_10 -> V_12 , V_10 -> V_13 ) ;
return 0 ;
}
void F_9 ( struct V_8 * V_2 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_12 ) {
F_10 ( V_2 , V_10 -> V_11 , V_10 -> V_12 , V_10 -> V_13 ) ;
V_10 -> V_12 = NULL ;
V_10 -> V_13 = 0 ;
V_10 -> V_11 = 0 ;
}
}
