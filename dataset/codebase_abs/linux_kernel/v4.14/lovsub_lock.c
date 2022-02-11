static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 ) ;
F_3 ( V_7 , V_6 ) ;
}
int F_4 ( const struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_10 * V_11 , const struct V_12 * V_13 )
{
struct V_5 * V_14 ;
int V_15 ;
V_14 = F_5 ( V_7 , V_16 ) ;
if ( V_14 ) {
F_6 ( V_11 , & V_14 -> V_17 , V_9 , & V_18 ) ;
V_15 = 0 ;
} else {
V_15 = - V_19 ;
}
return V_15 ;
}
