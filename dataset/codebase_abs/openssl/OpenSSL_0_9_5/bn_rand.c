static int F_1 ( int V_1 , T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
unsigned char * V_6 = NULL ;
int V_7 = 0 , V_8 , V_9 , V_10 ;
T_2 V_11 ;
V_9 = ( V_3 + 7 ) / 8 ;
V_8 = ( V_3 - 1 ) % 8 ;
V_10 = 0xff << V_8 ;
V_6 = ( unsigned char * ) Malloc ( V_9 ) ;
if ( V_6 == NULL )
{
F_2 ( V_12 , V_13 ) ;
goto V_14;
}
time ( & V_11 ) ;
F_3 ( & V_11 , sizeof( V_11 ) , 0 ) ;
if ( V_1 )
{
if ( F_4 ( V_6 , V_9 ) == - 1 )
goto V_14;
}
else
{
if ( F_5 ( V_6 , V_9 ) <= 0 )
goto V_14;
}
if ( V_4 )
{
if ( V_8 == 0 )
{
V_6 [ 0 ] = 1 ;
V_6 [ 1 ] |= 0x80 ;
}
else
{
V_6 [ 0 ] |= ( 3 << ( V_8 - 1 ) ) ;
V_6 [ 0 ] &= ~ ( V_10 << 1 ) ;
}
}
else
{
V_6 [ 0 ] |= ( 1 << V_8 ) ;
V_6 [ 0 ] &= ~ ( V_10 << 1 ) ;
}
if ( V_5 )
V_6 [ V_9 - 1 ] |= 1 ;
if ( ! F_6 ( V_6 , V_9 , V_2 ) ) goto V_14;
V_7 = 1 ;
V_14:
if ( V_6 != NULL )
{
memset ( V_6 , 0 , V_9 ) ;
Free ( V_6 ) ;
}
return ( V_7 ) ;
}
int F_7 ( T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_1 ( 0 , V_2 , V_3 , V_4 , V_5 ) ;
}
int F_8 ( T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_1 ( 1 , V_2 , V_3 , V_4 , V_5 ) ;
}
