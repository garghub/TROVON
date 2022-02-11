static void F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( V_7 , V_6 ) ;
}
static int F_4 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_8 * V_9 , struct V_10 * V_11 )
{
F_5 ( V_2 , V_4 -> V_12 , F_6 ( V_4 -> V_12 ) ) ;
return 0 ;
}
int F_7 ( const struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_15 * V_16 , const struct V_8 * V_9 )
{
struct V_5 * V_6 ;
int V_17 ;
F_5 ( V_2 , V_14 , F_6 ( V_14 ) ) ;
V_6 = F_8 ( V_7 , V_18 ) ;
if ( V_6 ) {
F_9 ( V_16 , & V_6 -> V_19 , V_14 , & V_20 ) ;
V_17 = 0 ;
} else {
V_17 = - V_21 ;
}
return V_17 ;
}
