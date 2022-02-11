static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( F_5 ( & V_9 -> V_10 ) == V_11 )
return sprintf ( V_8 , L_1 ) ;
else
return sprintf ( V_8 , L_2 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 V_13 ;
V_14 -> V_15 -> V_16 ( V_9 -> V_17 , & V_13 ) ;
return sprintf ( V_8 , L_3 , V_13 . V_18 / 1000 ) ;
}
