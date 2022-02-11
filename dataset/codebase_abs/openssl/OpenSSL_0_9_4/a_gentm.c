int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
#ifdef F_2
int V_3 ;
char V_4 [ 24 ] ;
T_2 V_5 = * ( T_2 * ) V_1 ;
V_3 = V_5 . V_6 ;
F_3 ( V_4 , V_5 . V_7 , ( V_3 >= sizeof V_4 ) ? sizeof V_4 : V_3 ) ;
V_5 . V_7 = V_4 ;
V_1 = ( T_1 * ) & V_5 ;
#endif
return ( F_4 ( ( T_2 * ) V_1 , V_2 ,
V_8 , V_9 ) ) ;
}
T_1 * F_5 ( T_1 * * V_1 ,
unsigned char * * V_2 , long V_6 )
{
T_1 * V_10 = NULL ;
V_10 = ( T_1 * ) F_6 ( ( T_2 * * ) V_1 , V_2 , V_6 ,
V_8 , V_9 ) ;
if ( V_10 == NULL )
{
F_7 ( V_11 , V_12 ) ;
return ( NULL ) ;
}
#ifdef F_2
F_8 ( V_10 -> V_7 , V_10 -> V_7 , V_10 -> V_6 ) ;
#endif
if ( ! F_9 ( V_10 ) )
{
F_7 ( V_11 , V_13 ) ;
goto V_14;
}
return ( V_10 ) ;
V_14:
if ( ( V_10 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_10 ) ) )
F_10 ( V_10 ) ;
return ( NULL ) ;
}
int F_9 ( T_1 * V_15 )
{
static int V_16 [ 9 ] = { 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ;
static int V_17 [ 9 ] = { 99 , 99 , 12 , 31 , 23 , 59 , 59 , 12 , 59 } ;
char * V_1 ;
int V_18 , V_19 , V_20 , V_21 ;
if ( V_15 -> type != V_8 ) return ( 0 ) ;
V_20 = V_15 -> V_6 ;
V_1 = ( char * ) V_15 -> V_7 ;
V_21 = 0 ;
if ( V_20 < 13 ) goto V_14;
for ( V_19 = 0 ; V_19 < 7 ; V_19 ++ )
{
if ( ( V_19 == 6 ) && ( ( V_1 [ V_21 ] == 'Z' ) ||
( V_1 [ V_21 ] == '+' ) || ( V_1 [ V_21 ] == '-' ) ) )
{ V_19 ++ ; break; }
if ( ( V_1 [ V_21 ] < '0' ) || ( V_1 [ V_21 ] > '9' ) ) goto V_14;
V_18 = V_1 [ V_21 ] - '0' ;
if ( ++ V_21 > V_20 ) goto V_14;
if ( ( V_1 [ V_21 ] < '0' ) || ( V_1 [ V_21 ] > '9' ) ) goto V_14;
V_18 = ( V_18 * 10 ) + V_1 [ V_21 ] - '0' ;
if ( ++ V_21 > V_20 ) goto V_14;
if ( ( V_18 < V_16 [ V_19 ] ) || ( V_18 > V_17 [ V_19 ] ) ) goto V_14;
}
if ( V_1 [ V_21 ] == 'Z' )
V_21 ++ ;
else if ( ( V_1 [ V_21 ] == '+' ) || ( V_1 [ V_21 ] == '-' ) )
{
V_21 ++ ;
if ( V_21 + 4 > V_20 ) goto V_14;
for ( V_19 = 7 ; V_19 < 9 ; V_19 ++ )
{
if ( ( V_1 [ V_21 ] < '0' ) || ( V_1 [ V_21 ] > '9' ) ) goto V_14;
V_18 = V_1 [ V_21 ] - '0' ;
V_21 ++ ;
if ( ( V_1 [ V_21 ] < '0' ) || ( V_1 [ V_21 ] > '9' ) ) goto V_14;
V_18 = ( V_18 * 10 ) + V_1 [ V_21 ] - '0' ;
if ( ( V_18 < V_16 [ V_19 ] ) || ( V_18 > V_17 [ V_19 ] ) ) goto V_14;
V_21 ++ ;
}
}
return ( V_21 == V_20 ) ;
V_14:
return ( 0 ) ;
}
int F_11 ( T_1 * V_22 , char * V_23 )
{
T_1 V_24 ;
V_24 . type = V_8 ;
V_24 . V_6 = strlen ( V_23 ) ;
V_24 . V_7 = ( unsigned char * ) V_23 ;
if ( F_9 ( & V_24 ) )
{
if ( V_22 != NULL )
{
F_12 ( ( T_2 * ) V_22 ,
( unsigned char * ) V_23 , V_24 . V_6 ) ;
}
return ( 1 ) ;
}
else
return ( 0 ) ;
}
T_1 * F_13 ( T_1 * V_22 ,
T_3 V_24 )
{
char * V_25 ;
struct V_26 * V_27 ;
#if F_14 ( V_28 ) && ! F_14 ( V_29 )
struct V_26 V_7 ;
#endif
if ( V_22 == NULL )
V_22 = F_15 () ;
if ( V_22 == NULL )
return ( NULL ) ;
#if F_14 ( V_28 ) && ! F_14 ( V_29 )
gmtime_r ( & V_24 , & V_7 ) ;
V_27 = & V_7 ;
#else
V_27 = gmtime ( & V_24 ) ;
#endif
V_25 = ( char * ) V_22 -> V_7 ;
if ( ( V_25 == NULL ) || ( V_22 -> V_6 < 16 ) )
{
V_25 = Malloc ( 20 ) ;
if ( V_25 == NULL ) return ( NULL ) ;
if ( V_22 -> V_7 != NULL )
Free ( V_22 -> V_7 ) ;
V_22 -> V_7 = ( unsigned char * ) V_25 ;
}
sprintf ( V_25 , L_1 , V_27 -> V_30 + 1900 ,
V_27 -> V_31 + 1 , V_27 -> V_32 , V_27 -> V_33 , V_27 -> V_34 , V_27 -> V_35 ) ;
V_22 -> V_6 = strlen ( V_25 ) ;
V_22 -> type = V_8 ;
#ifdef F_16
F_3 ( V_22 -> V_7 , V_22 -> V_7 , V_22 -> V_6 ) ;
#endif
return ( V_22 ) ;
}
