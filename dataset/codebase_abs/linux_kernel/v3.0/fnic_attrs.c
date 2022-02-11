static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
struct V_8 * V_8 = F_4 ( V_7 ) ;
return snprintf ( V_5 , V_9 , L_1 , V_10 [ V_8 -> V_11 ] ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_9 , L_1 , V_12 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return snprintf ( V_5 , V_9 , L_1 , ( V_7 -> V_13 )
? L_2 : L_3 ) ;
}
