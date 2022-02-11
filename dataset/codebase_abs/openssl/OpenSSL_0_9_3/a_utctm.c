int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
return ( F_2 ( ( V_3 * ) V_1 , V_2 ,
V_4 , V_5 ) ) ;
}
T_1 * F_3 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_6 )
{
T_1 * V_7 = NULL ;
V_7 = ( T_1 * ) F_4 ( ( V_3 * * ) V_1 , V_2 , V_6 ,
V_4 , V_5 ) ;
if ( V_7 == NULL )
{
F_5 ( V_8 , V_9 ) ;
return ( NULL ) ;
}
if ( ! F_6 ( V_7 ) )
{
F_5 ( V_8 , V_10 ) ;
goto V_11;
}
return ( V_7 ) ;
V_11:
if ( ( V_7 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_7 ) ) )
F_7 ( V_7 ) ;
return ( NULL ) ;
}
int F_6 ( T_1 * V_12 )
{
static int V_13 [ 8 ] = { 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ;
static int V_14 [ 8 ] = { 99 , 12 , 31 , 23 , 59 , 59 , 12 , 59 } ;
char * V_1 ;
int V_15 , V_16 , V_17 , V_18 ;
if ( V_12 -> type != V_4 ) return ( 0 ) ;
V_17 = V_12 -> V_6 ;
V_1 = ( char * ) V_12 -> V_19 ;
V_18 = 0 ;
if ( V_17 < 11 ) goto V_11;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ )
{
if ( ( V_16 == 5 ) && ( ( V_1 [ V_18 ] == 'Z' ) ||
( V_1 [ V_18 ] == '+' ) || ( V_1 [ V_18 ] == '-' ) ) )
{ V_16 ++ ; break; }
if ( ( V_1 [ V_18 ] < '0' ) || ( V_1 [ V_18 ] > '9' ) ) goto V_11;
V_15 = V_1 [ V_18 ] - '0' ;
if ( ++ V_18 > V_17 ) goto V_11;
if ( ( V_1 [ V_18 ] < '0' ) || ( V_1 [ V_18 ] > '9' ) ) goto V_11;
V_15 = ( V_15 * 10 ) + V_1 [ V_18 ] - '0' ;
if ( ++ V_18 > V_17 ) goto V_11;
if ( ( V_15 < V_13 [ V_16 ] ) || ( V_15 > V_14 [ V_16 ] ) ) goto V_11;
}
if ( V_1 [ V_18 ] == 'Z' )
V_18 ++ ;
else if ( ( V_1 [ V_18 ] == '+' ) || ( V_1 [ V_18 ] == '-' ) )
{
V_18 ++ ;
if ( V_18 + 4 > V_17 ) goto V_11;
for ( V_16 = 6 ; V_16 < 8 ; V_16 ++ )
{
if ( ( V_1 [ V_18 ] < '0' ) || ( V_1 [ V_18 ] > '9' ) ) goto V_11;
V_15 = V_1 [ V_18 ] - '0' ;
V_18 ++ ;
if ( ( V_1 [ V_18 ] < '0' ) || ( V_1 [ V_18 ] > '9' ) ) goto V_11;
V_15 = ( V_15 * 10 ) + V_1 [ V_18 ] - '0' ;
if ( ( V_15 < V_13 [ V_16 ] ) || ( V_15 > V_14 [ V_16 ] ) ) goto V_11;
V_18 ++ ;
}
}
return ( V_18 == V_17 ) ;
V_11:
return ( 0 ) ;
}
int F_8 ( T_1 * V_20 , char * V_21 )
{
T_1 V_22 ;
V_22 . type = V_4 ;
V_22 . V_6 = strlen ( V_21 ) ;
V_22 . V_19 = ( unsigned char * ) V_21 ;
if ( F_6 ( & V_22 ) )
{
if ( V_20 != NULL )
{
F_9 ( ( V_3 * ) V_20 ,
( unsigned char * ) V_21 , V_22 . V_6 ) ;
}
return ( 1 ) ;
}
else
return ( 0 ) ;
}
T_1 * F_10 ( T_1 * V_20 , T_2 V_22 )
{
char * V_23 ;
struct V_24 * V_25 ;
#if F_11 ( V_26 ) && ! F_11 ( V_27 )
struct V_24 V_19 ;
#endif
if ( V_20 == NULL )
V_20 = F_12 () ;
if ( V_20 == NULL )
return ( NULL ) ;
#if F_11 ( V_26 ) && ! F_11 ( V_27 )
gmtime_r ( & V_22 , & V_19 ) ;
V_25 = & V_19 ;
#else
V_25 = gmtime ( & V_22 ) ;
#endif
#ifdef F_13
if ( V_25 == NULL )
{
static F_14 ( V_28 , L_1 ) ;
static F_14 ( V_29 , L_2 ) ;
char V_30 [ 256 ] ;
unsigned int V_31 = 0 ;
struct {
short V_32 ;
short V_33 ;
void * V_34 ;
unsigned int * V_31 ;
} V_35 [] = {
{ 0 , V_36 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 } ,
} ;
int V_37 ;
V_35 [ 0 ] . V_32 = sizeof( V_30 ) ;
V_35 [ 0 ] . V_34 = V_30 ;
V_35 [ 0 ] . V_31 = & V_31 ;
V_37 = F_15 ( 0 , & V_28 , & V_29 , 0 , V_35 ) ;
if ( ! ( V_37 & 1 ) )
return NULL ;
V_30 [ V_31 ] = '\0' ;
V_37 = atoi ( V_30 ) ;
V_22 -= V_37 ;
V_25 = (struct V_24 * ) localtime ( & V_22 ) ;
}
#endif
V_23 = ( char * ) V_20 -> V_19 ;
if ( ( V_23 == NULL ) || ( V_20 -> V_6 < 14 ) )
{
V_23 = Malloc ( 20 ) ;
if ( V_23 == NULL ) return ( NULL ) ;
if ( V_20 -> V_19 != NULL )
Free ( V_20 -> V_19 ) ;
V_20 -> V_19 = ( unsigned char * ) V_23 ;
}
sprintf ( V_23 , L_3 , V_25 -> V_38 % 100 ,
V_25 -> V_39 + 1 , V_25 -> V_40 , V_25 -> V_41 , V_25 -> V_42 , V_25 -> V_43 ) ;
V_20 -> V_6 = strlen ( V_23 ) ;
V_20 -> type = V_4 ;
return ( V_20 ) ;
}
