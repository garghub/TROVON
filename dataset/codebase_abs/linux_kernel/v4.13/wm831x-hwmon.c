static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_4 ) -> V_8 ;
int V_9 ;
V_9 = F_4 ( V_6 , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
return sprintf ( V_5 , L_1 , F_5 ( V_9 , 1000 ) ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_4 ) -> V_8 ;
int V_9 ;
V_9 = F_7 ( V_6 , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = 512180 - ( V_9 * 1000 ) ;
V_9 = F_5 ( V_9 * 10000 , 10983 ) ;
return sprintf ( V_5 , L_1 , V_9 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_7 = F_3 ( V_4 ) -> V_8 ;
return sprintf ( V_5 , L_2 , V_10 [ V_7 ] ) ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_6 * V_6 = F_2 ( V_12 -> V_2 . V_13 ) ;
struct V_1 * V_14 ;
V_14 = F_10 ( & V_12 -> V_2 , L_3 ,
V_6 ,
V_15 ) ;
return F_11 ( V_14 ) ;
}
