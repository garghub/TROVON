static T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
if ( F_4 ( V_7 ) )
return snprintf ( V_5 , V_8 , L_1 ,
V_7 -> V_9 [ 0 ] ,
V_7 -> V_9 [ 1 ] ,
V_7 -> V_10 , V_7 -> V_11 ) ;
else
return snprintf ( V_5 , V_8 , L_2 ,
V_7 -> V_9 [ 0 ] ,
V_7 -> V_9 [ 1 ] ,
V_7 -> V_10 , V_7 -> V_11 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return snprintf ( V_5 , V_8 , L_3 , V_7 -> V_12 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return snprintf ( V_5 , V_8 , L_4 , V_7 -> V_13 ,
V_7 -> V_14 ) ;
}
static T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return snprintf ( V_5 , V_8 , L_2 ,
V_7 -> V_15 , V_7 -> V_16 ,
V_7 -> V_17 , V_7 -> V_18 ) ;
}
