static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_4 ) -> V_8 ;
int V_9 ;
V_9 = F_4 ( V_6 , V_7 , 0 , 0 ) * V_10 ;
V_9 = F_5 ( V_9 , 1000 ) ;
return sprintf ( V_5 , L_1 , V_9 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_7 = F_3 ( V_4 ) -> V_8 ;
return sprintf ( V_5 , L_2 , V_11 [ V_7 ] ) ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_6 * V_6 = F_8 ( V_13 ) ;
struct V_1 * V_14 ;
V_14 = F_9 ( & V_13 -> V_2 , L_3 ,
V_6 ,
V_15 ) ;
return F_10 ( V_14 ) ;
}
