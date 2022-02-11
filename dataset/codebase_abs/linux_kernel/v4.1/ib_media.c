static int F_1 ( struct V_1 * V_2 , char * V_3 ,
int V_4 )
{
if ( V_4 < 60 )
return 1 ;
sprintf ( V_3 , L_1 , V_2 -> V_5 ) ;
return 0 ;
}
static int F_2 ( char * V_6 , struct V_1 * V_7 )
{
memset ( V_6 , 0 , V_8 ) ;
memcpy ( V_6 , V_7 -> V_5 , V_9 ) ;
return 0 ;
}
static int F_3 ( struct V_10 * V_11 ,
struct V_1 * V_7 ,
char * V_6 )
{
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
memcpy ( V_7 -> V_5 , V_6 , V_9 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_14 = ! memcmp ( V_6 , V_11 -> V_15 . V_5 ,
V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_11 ,
struct V_1 * V_7 ,
char * V_6 )
{
return F_3 ( V_11 , V_7 , V_6 ) ;
}
