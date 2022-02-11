static int F_1 ( int V_1 , T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
unsigned char * V_6 = NULL ;
int V_7 = 0 , V_8 , V_9 , V_10 ;
T_2 V_11 ;
if ( V_3 == 0 )
{
F_2 ( V_2 ) ;
return 1 ;
}
V_9 = ( V_3 + 7 ) / 8 ;
V_8 = ( V_3 - 1 ) % 8 ;
V_10 = 0xff << ( V_8 + 1 ) ;
V_6 = ( unsigned char * ) F_3 ( V_9 ) ;
if ( V_6 == NULL )
{
F_4 ( V_12 , V_13 ) ;
goto V_14;
}
time ( & V_11 ) ;
F_5 ( & V_11 , sizeof( V_11 ) , 0.0 ) ;
if ( V_1 )
{
if ( F_6 ( V_6 , V_9 ) == - 1 )
goto V_14;
}
else
{
if ( F_7 ( V_6 , V_9 ) <= 0 )
goto V_14;
}
#if 1
if ( V_1 == 2 )
{
int V_15 ;
unsigned char V_16 ;
for ( V_15 = 0 ; V_15 < V_9 ; V_15 ++ )
{
F_6 ( & V_16 , 1 ) ;
if ( V_16 >= 128 && V_15 > 0 )
V_6 [ V_15 ] = V_6 [ V_15 - 1 ] ;
else if ( V_16 < 42 )
V_6 [ V_15 ] = 0 ;
else if ( V_16 < 84 )
V_6 [ V_15 ] = 255 ;
}
}
#endif
if ( V_4 != - 1 )
{
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
}
}
else
{
V_6 [ 0 ] |= ( 1 << V_8 ) ;
}
}
V_6 [ 0 ] &= ~ V_10 ;
if ( V_5 )
V_6 [ V_9 - 1 ] |= 1 ;
if ( ! F_8 ( V_6 , V_9 , V_2 ) ) goto V_14;
V_7 = 1 ;
V_14:
if ( V_6 != NULL )
{
F_9 ( V_6 , V_9 ) ;
F_10 ( V_6 ) ;
}
F_11 ( V_2 ) ;
return ( V_7 ) ;
}
int F_12 ( T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_1 ( 0 , V_2 , V_3 , V_4 , V_5 ) ;
}
int F_13 ( T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_1 ( 1 , V_2 , V_3 , V_4 , V_5 ) ;
}
int F_14 ( T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_1 ( 2 , V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_15 ( int V_17 , T_1 * V_18 , T_1 * V_19 )
{
int (* F_16)( T_1 * , int , int , int ) = V_17 ? F_13 : F_12 ;
int V_20 ;
int V_21 = 100 ;
if ( V_19 -> V_22 || F_17 ( V_19 ) )
{
F_4 ( V_23 , V_24 ) ;
return 0 ;
}
V_20 = F_18 ( V_19 ) ;
if ( V_20 == 1 )
F_2 ( V_18 ) ;
else if ( ! F_19 ( V_19 , V_20 - 2 ) && ! F_19 ( V_19 , V_20 - 3 ) )
{
do
{
if ( ! F_16 ( V_18 , V_20 + 1 , - 1 , 0 ) ) return 0 ;
if ( F_20 ( V_18 , V_19 ) >= 0 )
{
if ( ! F_21 ( V_18 , V_18 , V_19 ) ) return 0 ;
if ( F_20 ( V_18 , V_19 ) >= 0 )
if ( ! F_21 ( V_18 , V_18 , V_19 ) ) return 0 ;
}
if ( ! -- V_21 )
{
F_4 ( V_23 , V_25 ) ;
return 0 ;
}
}
while ( F_20 ( V_18 , V_19 ) >= 0 );
}
else
{
do
{
if ( ! F_16 ( V_18 , V_20 , - 1 , 0 ) ) return 0 ;
if ( ! -- V_21 )
{
F_4 ( V_23 , V_25 ) ;
return 0 ;
}
}
while ( F_20 ( V_18 , V_19 ) >= 0 );
}
F_11 ( V_18 ) ;
return 1 ;
}
int F_22 ( T_1 * V_18 , T_1 * V_19 )
{
return F_15 ( 0 , V_18 , V_19 ) ;
}
int F_23 ( T_1 * V_18 , T_1 * V_19 )
{
return F_15 ( 1 , V_18 , V_19 ) ;
}
