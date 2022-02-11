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
int F_2 ( T_1 * V_13 , const char * V_14 )
{
T_1 V_15 ;
V_15 . type = V_9 ;
V_15 . V_10 = strlen ( V_14 ) ;
V_15 . V_11 = ( unsigned char * ) V_14 ;
if ( F_1 ( & V_15 ) )
{
if ( V_13 != NULL )
{
if ( ! F_3 ( ( V_16 * ) V_13 ,
( unsigned char * ) V_14 , V_15 . V_10 ) )
return 0 ;
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
T_3 V_20 = 20 ;
if ( V_13 == NULL )
V_13 = F_5 () ;
if ( V_13 == NULL )
return ( NULL ) ;
V_19 = F_6 ( & V_15 , & V_11 ) ;
if ( V_19 == NULL )
return ( NULL ) ;
V_17 = ( char * ) V_13 -> V_11 ;
if ( ( V_17 == NULL ) || ( ( T_3 ) V_13 -> V_10 < V_20 ) )
{
V_17 = F_7 ( V_20 ) ;
if ( V_17 == NULL )
{
F_8 ( V_21 , V_22 ) ;
return ( NULL ) ;
}
if ( V_13 -> V_11 != NULL )
F_9 ( V_13 -> V_11 ) ;
V_13 -> V_11 = ( unsigned char * ) V_17 ;
}
F_10 ( V_17 , V_20 , L_1 , V_19 -> V_23 % 100 ,
V_19 -> V_24 + 1 , V_19 -> V_25 , V_19 -> V_26 , V_19 -> V_27 , V_19 -> V_28 ) ;
V_13 -> V_10 = strlen ( V_17 ) ;
V_13 -> type = V_9 ;
#ifdef F_11
F_12 ( V_13 -> V_11 , V_13 -> V_11 , V_13 -> V_10 ) ;
#endif
return ( V_13 ) ;
}
int F_13 ( const T_1 * V_13 , T_2 V_15 )
{
struct V_18 * V_18 ;
struct V_18 V_11 ;
int V_29 ;
int V_30 ;
#define F_14 ( V_17 ) (((p)[0]-'0')*10+(p)[1]-'0')
if ( V_13 -> V_11 [ 12 ] == 'Z' )
V_29 = 0 ;
else
{
V_29 = F_14 ( V_13 -> V_11 + 13 ) * 60 + F_14 ( V_13 -> V_11 + 15 ) ;
if ( V_13 -> V_11 [ 12 ] == '-' )
V_29 = - V_29 ;
}
V_15 -= V_29 * 60 ;
V_18 = F_6 ( & V_15 , & V_11 ) ;
#define F_15 ( V_4 , T_4 ) if ((a)<(b)) return -1; else if ((a)>(b)) return 1
V_30 = F_14 ( V_13 -> V_11 ) ;
if ( V_30 < 50 )
V_30 += 100 ;
F_15 ( V_30 , V_18 -> V_23 ) ;
F_15 ( F_14 ( V_13 -> V_11 + 2 ) - 1 , V_18 -> V_24 ) ;
F_15 ( F_14 ( V_13 -> V_11 + 4 ) , V_18 -> V_25 ) ;
F_15 ( F_14 ( V_13 -> V_11 + 6 ) , V_18 -> V_26 ) ;
F_15 ( F_14 ( V_13 -> V_11 + 8 ) , V_18 -> V_27 ) ;
F_15 ( F_14 ( V_13 -> V_11 + 10 ) , V_18 -> V_28 ) ;
#undef F_14
#undef F_15
return 0 ;
}
