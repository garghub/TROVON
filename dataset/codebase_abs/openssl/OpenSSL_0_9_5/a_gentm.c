T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_2 , unsigned char * * V_3 )
{
#ifdef F_6
int V_4 ;
char V_5 [ 24 ] ;
T_2 V_6 = * ( T_2 * ) V_2 ;
V_4 = V_6 . V_7 ;
F_7 ( V_5 , V_6 . V_8 , ( V_4 >= sizeof V_5 ) ? sizeof V_5 : V_4 ) ;
V_6 . V_8 = V_5 ;
V_2 = ( T_1 * ) & V_6 ;
#endif
return ( F_8 ( ( T_2 * ) V_2 , V_3 ,
V_9 , V_10 ) ) ;
}
T_1 * F_9 ( T_1 * * V_2 ,
unsigned char * * V_3 , long V_7 )
{
T_1 * V_11 = NULL ;
V_11 = ( T_1 * ) F_10 ( ( T_2 * * ) V_2 , V_3 , V_7 ,
V_9 , V_10 ) ;
if ( V_11 == NULL )
{
F_11 ( V_12 , V_13 ) ;
return ( NULL ) ;
}
#ifdef F_6
F_12 ( V_11 -> V_8 , V_11 -> V_8 , V_11 -> V_7 ) ;
#endif
if ( ! F_13 ( V_11 ) )
{
F_11 ( V_12 , V_14 ) ;
goto V_15;
}
return ( V_11 ) ;
V_15:
if ( ( V_11 != NULL ) && ( ( V_2 == NULL ) || ( * V_2 != V_11 ) ) )
F_4 ( V_11 ) ;
return ( NULL ) ;
}
int F_13 ( T_1 * V_16 )
{
static int V_17 [ 9 ] = { 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ;
static int V_18 [ 9 ] = { 99 , 99 , 12 , 31 , 23 , 59 , 59 , 12 , 59 } ;
char * V_2 ;
int V_19 , V_20 , V_21 , V_22 ;
if ( V_16 -> type != V_9 ) return ( 0 ) ;
V_21 = V_16 -> V_7 ;
V_2 = ( char * ) V_16 -> V_8 ;
V_22 = 0 ;
if ( V_21 < 13 ) goto V_15;
for ( V_20 = 0 ; V_20 < 7 ; V_20 ++ )
{
if ( ( V_20 == 6 ) && ( ( V_2 [ V_22 ] == 'Z' ) ||
( V_2 [ V_22 ] == '+' ) || ( V_2 [ V_22 ] == '-' ) ) )
{ V_20 ++ ; break; }
if ( ( V_2 [ V_22 ] < '0' ) || ( V_2 [ V_22 ] > '9' ) ) goto V_15;
V_19 = V_2 [ V_22 ] - '0' ;
if ( ++ V_22 > V_21 ) goto V_15;
if ( ( V_2 [ V_22 ] < '0' ) || ( V_2 [ V_22 ] > '9' ) ) goto V_15;
V_19 = ( V_19 * 10 ) + V_2 [ V_22 ] - '0' ;
if ( ++ V_22 > V_21 ) goto V_15;
if ( ( V_19 < V_17 [ V_20 ] ) || ( V_19 > V_18 [ V_20 ] ) ) goto V_15;
}
if ( V_2 [ V_22 ] == 'Z' )
V_22 ++ ;
else if ( ( V_2 [ V_22 ] == '+' ) || ( V_2 [ V_22 ] == '-' ) )
{
V_22 ++ ;
if ( V_22 + 4 > V_21 ) goto V_15;
for ( V_20 = 7 ; V_20 < 9 ; V_20 ++ )
{
if ( ( V_2 [ V_22 ] < '0' ) || ( V_2 [ V_22 ] > '9' ) ) goto V_15;
V_19 = V_2 [ V_22 ] - '0' ;
V_22 ++ ;
if ( ( V_2 [ V_22 ] < '0' ) || ( V_2 [ V_22 ] > '9' ) ) goto V_15;
V_19 = ( V_19 * 10 ) + V_2 [ V_22 ] - '0' ;
if ( ( V_19 < V_17 [ V_20 ] ) || ( V_19 > V_18 [ V_20 ] ) ) goto V_15;
V_22 ++ ;
}
}
return ( V_22 == V_21 ) ;
V_15:
return ( 0 ) ;
}
int F_14 ( T_1 * V_23 , char * V_24 )
{
T_1 V_25 ;
V_25 . type = V_9 ;
V_25 . V_7 = strlen ( V_24 ) ;
V_25 . V_8 = ( unsigned char * ) V_24 ;
if ( F_13 ( & V_25 ) )
{
if ( V_23 != NULL )
{
F_15 ( ( T_2 * ) V_23 ,
( unsigned char * ) V_24 , V_25 . V_7 ) ;
}
return ( 1 ) ;
}
else
return ( 0 ) ;
}
T_1 * F_16 ( T_1 * V_23 ,
T_3 V_25 )
{
char * V_26 ;
struct V_27 * V_28 ;
#if F_17 ( V_29 ) && ! F_17 ( V_30 )
struct V_27 V_8 ;
#endif
if ( V_23 == NULL )
V_23 = F_2 () ;
if ( V_23 == NULL )
return ( NULL ) ;
#if F_17 ( V_29 ) && ! F_17 ( V_30 )
gmtime_r ( & V_25 , & V_8 ) ;
V_28 = & V_8 ;
#else
V_28 = gmtime ( & V_25 ) ;
#endif
V_26 = ( char * ) V_23 -> V_8 ;
if ( ( V_26 == NULL ) || ( V_23 -> V_7 < 16 ) )
{
V_26 = Malloc ( 20 ) ;
if ( V_26 == NULL ) return ( NULL ) ;
if ( V_23 -> V_8 != NULL )
Free ( V_23 -> V_8 ) ;
V_23 -> V_8 = ( unsigned char * ) V_26 ;
}
sprintf ( V_26 , L_1 , V_28 -> V_31 + 1900 ,
V_28 -> V_32 + 1 , V_28 -> V_33 , V_28 -> V_34 , V_28 -> V_35 , V_28 -> V_36 ) ;
V_23 -> V_7 = strlen ( V_26 ) ;
V_23 -> type = V_9 ;
#ifdef F_18
F_7 ( V_23 -> V_8 , V_23 -> V_8 , V_23 -> V_7 ) ;
#endif
return ( V_23 ) ;
}
