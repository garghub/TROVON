static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 ) ;
F_3 ( F_4 ( & V_6 -> V_7 ) ) ;
F_5 ( V_8 , V_6 ) ;
}
int F_6 ( const struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_12 , const struct V_13 * V_14 )
{
struct V_5 * V_15 ;
int V_16 ;
V_15 = F_7 ( V_8 , V_17 ) ;
if ( V_15 ) {
F_8 ( & V_15 -> V_7 ) ;
F_9 ( V_12 , & V_15 -> V_18 , V_10 , & V_19 ) ;
V_16 = 0 ;
} else {
V_16 = - V_20 ;
}
return V_16 ;
}
