int F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{
unsigned char * V_5 = NULL ;
int V_6 = 0 , V_7 , V_8 , V_9 ;
T_2 V_10 ;
V_8 = ( V_2 + 7 ) / 8 ;
V_7 = ( V_2 - 1 ) % 8 ;
V_9 = 0xff << V_7 ;
V_5 = ( unsigned char * ) Malloc ( V_8 ) ;
if ( V_5 == NULL )
{
F_2 ( V_11 , V_12 ) ;
goto V_13;
}
time ( & V_10 ) ;
F_3 ( & V_10 , sizeof( V_10 ) ) ;
F_4 ( V_5 , ( int ) V_8 ) ;
if ( V_3 )
{
if ( V_7 == 0 )
{
V_5 [ 0 ] = 1 ;
V_5 [ 1 ] |= 0x80 ;
}
else
{
V_5 [ 0 ] |= ( 3 << ( V_7 - 1 ) ) ;
V_5 [ 0 ] &= ~ ( V_9 << 1 ) ;
}
}
else
{
V_5 [ 0 ] |= ( 1 << V_7 ) ;
V_5 [ 0 ] &= ~ ( V_9 << 1 ) ;
}
if ( V_4 )
V_5 [ V_8 - 1 ] |= 1 ;
if ( ! F_5 ( V_5 , V_8 , V_1 ) ) goto V_13;
V_6 = 1 ;
V_13:
if ( V_5 != NULL )
{
memset ( V_5 , 0 , V_8 ) ;
Free ( V_5 ) ;
}
return ( V_6 ) ;
}
