static int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
const unsigned char * V_3 , T_2 V_4 )
{
F_2 ()
F_3 ( V_3 + V_5 , V_2 + V_5 , V_1 -> V_6 ) ;
return 1 ;
}
static int F_4 ( T_1 * V_1 , const unsigned char * V_7 ,
const unsigned char * V_8 , int V_9 )
{
if( ! V_9 ) {
if ( F_5 ( V_1 ) == V_10 ) V_9 = 1 ;
else if ( F_5 ( V_1 ) == V_11 ) V_9 = 1 ;
}
if ( V_9 ) F_6 ( V_7 , V_1 -> V_6 ) ;
else
{
T_3 V_12 ;
F_6 ( V_7 , & V_12 ) ;
F_7 ( & V_12 , V_1 -> V_6 ) ;
F_8 ( ( unsigned char * ) & V_12 ,
sizeof( T_3 ) ) ;
}
return 1 ;
}
