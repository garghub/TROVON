static T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
return snprintf ( V_5 , V_7 , L_1 , V_6 -> V_8 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
return snprintf ( V_5 , V_7 , L_1 ,
V_9 [ F_5 ( V_6 ) ] ) ;
}
static T_1
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return snprintf ( V_5 , V_7 , L_1 , V_10 ) ;
}
static T_1
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_6 -> V_11 . V_12 == V_13 )
V_6 -> V_14 = F_8 ( V_6 -> V_15 ) ;
return snprintf ( V_5 , V_7 , L_1 ,
( V_6 -> V_14 ) ? L_2 : L_3 ) ;
}
