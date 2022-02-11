static int F_1 ( struct V_1 * V_2 ,
char * V_3 , int V_4 )
{
if ( V_4 < 18 )
return 1 ;
sprintf ( V_3 , L_1 , V_2 -> V_5 ) ;
return 0 ;
}
static int F_2 ( char * V_6 , struct V_1 * V_2 )
{
memset ( V_6 , 0 , V_7 ) ;
V_6 [ V_8 ] = V_9 ;
memcpy ( V_6 + V_10 , V_2 -> V_5 , V_11 ) ;
return 0 ;
}
static int F_3 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
char * V_6 )
{
char V_14 [ V_11 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_4 ( V_2 -> V_5 , V_6 ) ;
V_2 -> V_15 = V_9 ;
V_2 -> V_16 = ! memcmp ( V_2 -> V_5 , V_14 , V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
char * V_6 )
{
V_6 += V_10 ;
return F_3 ( V_13 , V_2 , V_6 ) ;
}
