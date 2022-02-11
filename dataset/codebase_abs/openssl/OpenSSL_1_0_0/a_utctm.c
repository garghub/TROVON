int F_1 ( T_1 * V_1 )
{
static const int V_2 [ 8 ] = { 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ;
static const int V_3 [ 8 ] = { 99 , 12 , 31 , 23 , 59 , 59 , 12 , 59 } ;
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
return F_5 ( V_13 , V_15 , 0 , 0 ) ;
}
T_1 * F_5 ( T_1 * V_13 , T_2 V_15 ,
int V_17 , long V_18 )
{
char * V_19 ;
struct V_20 * V_21 ;
struct V_20 V_11 ;
T_3 V_22 = 20 ;
if ( V_13 == NULL )
V_13 = F_6 () ;
if ( V_13 == NULL )
return ( NULL ) ;
V_21 = F_7 ( & V_15 , & V_11 ) ;
if ( V_21 == NULL )
return ( NULL ) ;
if ( V_17 || V_18 )
{
if ( ! F_8 ( V_21 , V_17 , V_18 ) )
return NULL ;
}
if( ( V_21 -> V_23 < 50 ) || ( V_21 -> V_23 >= 150 ) )
return NULL ;
V_19 = ( char * ) V_13 -> V_11 ;
if ( ( V_19 == NULL ) || ( ( T_3 ) V_13 -> V_10 < V_22 ) )
{
V_19 = F_9 ( V_22 ) ;
if ( V_19 == NULL )
{
F_10 ( V_24 , V_25 ) ;
return ( NULL ) ;
}
if ( V_13 -> V_11 != NULL )
F_11 ( V_13 -> V_11 ) ;
V_13 -> V_11 = ( unsigned char * ) V_19 ;
}
F_12 ( V_19 , V_22 , L_1 , V_21 -> V_23 % 100 ,
V_21 -> V_26 + 1 , V_21 -> V_27 , V_21 -> V_28 , V_21 -> V_29 , V_21 -> V_30 ) ;
V_13 -> V_10 = strlen ( V_19 ) ;
V_13 -> type = V_9 ;
#ifdef F_13
F_14 ( V_13 -> V_11 , V_13 -> V_11 , V_13 -> V_10 ) ;
#endif
return ( V_13 ) ;
}
int F_15 ( const T_1 * V_13 , T_2 V_15 )
{
struct V_20 * V_20 ;
struct V_20 V_11 ;
int V_31 ;
int V_32 ;
#define F_16 ( V_19 ) (((p)[0]-'0')*10+(p)[1]-'0')
if ( V_13 -> V_11 [ 12 ] == 'Z' )
V_31 = 0 ;
else
{
V_31 = F_16 ( V_13 -> V_11 + 13 ) * 60 + F_16 ( V_13 -> V_11 + 15 ) ;
if ( V_13 -> V_11 [ 12 ] == '-' )
V_31 = - V_31 ;
}
V_15 -= V_31 * 60 ;
V_20 = F_7 ( & V_15 , & V_11 ) ;
#define F_17 ( V_4 , T_4 ) if ((a)<(b)) return -1; else if ((a)>(b)) return 1
V_32 = F_16 ( V_13 -> V_11 ) ;
if ( V_32 < 50 )
V_32 += 100 ;
F_17 ( V_32 , V_20 -> V_23 ) ;
F_17 ( F_16 ( V_13 -> V_11 + 2 ) - 1 , V_20 -> V_26 ) ;
F_17 ( F_16 ( V_13 -> V_11 + 4 ) , V_20 -> V_27 ) ;
F_17 ( F_16 ( V_13 -> V_11 + 6 ) , V_20 -> V_28 ) ;
F_17 ( F_16 ( V_13 -> V_11 + 8 ) , V_20 -> V_29 ) ;
F_17 ( F_16 ( V_13 -> V_11 + 10 ) , V_20 -> V_30 ) ;
#undef F_16
#undef F_17
return 0 ;
}
