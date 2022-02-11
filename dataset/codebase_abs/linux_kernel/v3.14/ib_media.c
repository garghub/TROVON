static int F_1 ( struct V_1 * V_2 , char * V_3 ,
int V_4 )
{
if ( V_4 < 60 )
return 1 ;
sprintf ( V_3 , L_1 , V_2 -> V_5 ) ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , char * V_6 )
{
memset ( V_6 , 0 , V_7 ) ;
V_6 [ V_8 ] = V_9 ;
memcpy ( V_6 , V_2 -> V_5 , V_10 ) ;
return 0 ;
}
static int F_3 ( const struct V_11 * V_12 ,
struct V_1 * V_2 , char * V_6 )
{
F_4 ( V_12 , V_2 , V_6 ) ;
return 0 ;
}
