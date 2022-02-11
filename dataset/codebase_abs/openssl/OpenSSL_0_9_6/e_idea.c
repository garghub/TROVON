static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , unsigned int V_4 )
{
F_2 ()
F_3 ( V_3 + V_5 , V_2 + V_5 , & V_1 -> V_6 . V_7 ) ;
return 1 ;
}
static int F_4 ( T_1 * V_1 , const unsigned char * V_8 ,
const unsigned char * V_9 , int V_10 )
{
if( ! V_10 ) {
if ( F_5 ( V_1 ) == V_11 ) V_10 = 1 ;
else if ( F_5 ( V_1 ) == V_12 ) V_10 = 1 ;
}
if ( V_10 ) F_6 ( V_8 , & ( V_1 -> V_6 . V_7 ) ) ;
else
{
T_2 V_13 ;
F_6 ( V_8 , & V_13 ) ;
F_7 ( & V_13 , & ( V_1 -> V_6 . V_7 ) ) ;
memset ( ( unsigned char * ) & V_13 , 0 ,
sizeof( T_2 ) ) ;
}
return 1 ;
}
