int F_1 ( T_1 * V_1 )
{
static int V_2 [ 8 ] = { 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ;
static int V_3 [ 8 ] = { 99 , 12 , 31 , 23 , 59 , 59 , 12 , 59 } ;
char * V_4 ;
int V_5 , V_6 , V_7 , V_8 ;
if ( V_1 -> type != V_9 ) return ( 0 ) ;
V_7 = V_1 -> V_10 ;
V_4 = ( char * ) V_1 -> V_11 ;
V_8 = 0 ;
if ( V_7 < 11 ) goto V_12;
for ( V_6 = 0 ; V_6 < 6 ; V_6 ++ )
{
if ( ( V_6 == 5 ) && ( ( V_4 [ V_8 ] == 'Z' ) ||
( V_4 [ V_8 ] == '+' ) || ( V_4 [ V_8 ] == '-' ) ) )
{ V_6 ++ ; break; }
if ( ( V_4 [ V_8 ] < '0' ) || ( V_4 [ V_8 ] > '9' ) ) goto V_12;
V_5 = V_4 [ V_8 ] - '0' ;
if ( ++ V_8 > V_7 ) goto V_12;
if ( ( V_4 [ V_8 ] < '0' ) || ( V_4 [ V_8 ] > '9' ) ) goto V_12;
V_5 = ( V_5 * 10 ) + V_4 [ V_8 ] - '0' ;
if ( ++ V_8 > V_7 ) goto V_12;
if ( ( V_5 < V_2 [ V_6 ] ) || ( V_5 > V_3 [ V_6 ] ) ) goto V_12;
}
if ( V_4 [ V_8 ] == 'Z' )
V_8 ++ ;
else if ( ( V_4 [ V_8 ] == '+' ) || ( V_4 [ V_8 ] == '-' ) )
{
V_8 ++ ;
if ( V_8 + 4 > V_7 ) goto V_12;
for ( V_6 = 6 ; V_6 < 8 ; V_6 ++ )
{
if ( ( V_4 [ V_8 ] < '0' ) || ( V_4 [ V_8 ] > '9' ) ) goto V_12;
V_5 = V_4 [ V_8 ] - '0' ;
V_8 ++ ;
if ( ( V_4 [ V_8 ] < '0' ) || ( V_4 [ V_8 ] > '9' ) ) goto V_12;
V_5 = ( V_5 * 10 ) + V_4 [ V_8 ] - '0' ;
if ( ( V_5 < V_2 [ V_6 ] ) || ( V_5 > V_3 [ V_6 ] ) ) goto V_12;
V_8 ++ ;
}
}
return ( V_8 == V_7 ) ;
V_12:
return ( 0 ) ;
}
int F_2 ( T_1 * V_13 , char * V_14 )
{
T_1 V_15 ;
V_15 . type = V_9 ;
V_15 . V_10 = strlen ( V_14 ) ;
V_15 . V_11 = ( unsigned char * ) V_14 ;
if ( F_1 ( & V_15 ) )
{
if ( V_13 != NULL )
{
F_3 ( ( V_16 * ) V_13 ,
( unsigned char * ) V_14 , V_15 . V_10 ) ;
V_13 -> type = V_9 ;
}
return ( 1 ) ;
}
else
return ( 0 ) ;
}
T_1 * F_4 ( T_1 * V_13 , T_2 V_15 )
{
char * V_17 ;
struct V_18 * V_19 ;
struct V_18 V_11 ;
if ( V_13 == NULL )
V_13 = F_5 () ;
if ( V_13 == NULL )
return ( NULL ) ;
V_19 = F_6 ( & V_15 , & V_11 ) ;
if ( V_19 == NULL )
return ( NULL ) ;
V_17 = ( char * ) V_13 -> V_11 ;
if ( ( V_17 == NULL ) || ( V_13 -> V_10 < 14 ) )
{
V_17 = F_7 ( 20 ) ;
if ( V_17 == NULL ) return ( NULL ) ;
if ( V_13 -> V_11 != NULL )
F_8 ( V_13 -> V_11 ) ;
V_13 -> V_11 = ( unsigned char * ) V_17 ;
}
sprintf ( V_17 , L_1 , V_19 -> V_20 % 100 ,
V_19 -> V_21 + 1 , V_19 -> V_22 , V_19 -> V_23 , V_19 -> V_24 , V_19 -> V_25 ) ;
V_13 -> V_10 = strlen ( V_17 ) ;
V_13 -> type = V_9 ;
#ifdef F_9
F_10 ( V_13 -> V_11 , V_13 -> V_11 , V_13 -> V_10 ) ;
#endif
return ( V_13 ) ;
}
int F_11 ( const T_1 * V_13 , T_2 V_15 )
{
struct V_18 * V_18 ;
struct V_18 V_11 ;
int V_26 ;
int V_27 ;
#define F_12 ( V_17 ) (((p)[0]-'0')*10+(p)[1]-'0')
if ( V_13 -> V_11 [ 12 ] == 'Z' )
V_26 = 0 ;
else
{
V_26 = F_12 ( V_13 -> V_11 + 13 ) * 60 + F_12 ( V_13 -> V_11 + 15 ) ;
if ( V_13 -> V_11 [ 12 ] == '-' )
V_26 = - V_26 ;
}
V_15 -= V_26 * 60 ;
V_18 = F_6 ( & V_15 , & V_11 ) ;
#define F_13 ( V_4 , T_3 ) if ((a)<(b)) return -1; else if ((a)>(b)) return 1
V_27 = F_12 ( V_13 -> V_11 ) ;
if ( V_27 < 50 )
V_27 += 100 ;
F_13 ( V_27 , V_18 -> V_20 ) ;
F_13 ( F_12 ( V_13 -> V_11 + 2 ) - 1 , V_18 -> V_21 ) ;
F_13 ( F_12 ( V_13 -> V_11 + 4 ) , V_18 -> V_22 ) ;
F_13 ( F_12 ( V_13 -> V_11 + 6 ) , V_18 -> V_23 ) ;
F_13 ( F_12 ( V_13 -> V_11 + 8 ) , V_18 -> V_24 ) ;
F_13 ( F_12 ( V_13 -> V_11 + 10 ) , V_18 -> V_25 ) ;
#undef F_12
#undef F_13
return 0 ;
}
