int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
#ifndef F_2
return ( F_3 ( ( V_3 * ) V_1 , V_2 ,
V_4 , V_5 ) ) ;
#else
int V_6 ;
char V_7 [ 24 ] ;
V_3 V_8 = * ( V_3 * ) V_1 ;
V_6 = V_8 . V_9 ;
F_4 ( V_7 , V_8 . V_10 , ( V_6 >= sizeof V_7 ) ? sizeof V_7 : V_6 ) ;
V_8 . V_10 = V_7 ;
return F_3 ( & V_8 , V_2 , V_4 , V_5 ) ;
#endif
}
T_1 * F_5 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_9 )
{
T_1 * V_11 = NULL ;
V_11 = ( T_1 * ) F_6 ( ( V_3 * * ) V_1 , V_2 , V_9 ,
V_4 , V_5 ) ;
if ( V_11 == NULL )
{
F_7 ( V_12 , V_13 ) ;
return ( NULL ) ;
}
#ifdef F_2
F_8 ( V_11 -> V_10 , V_11 -> V_10 , V_11 -> V_9 ) ;
#endif
if ( ! F_9 ( V_11 ) )
{
F_7 ( V_12 , V_14 ) ;
goto V_15;
}
return ( V_11 ) ;
V_15:
if ( ( V_11 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_11 ) ) )
F_10 ( V_11 ) ;
return ( NULL ) ;
}
int F_9 ( T_1 * V_16 )
{
static int V_17 [ 8 ] = { 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ;
static int V_18 [ 8 ] = { 99 , 12 , 31 , 23 , 59 , 59 , 12 , 59 } ;
char * V_1 ;
int V_19 , V_20 , V_21 , V_22 ;
if ( V_16 -> type != V_4 ) return ( 0 ) ;
V_21 = V_16 -> V_9 ;
V_1 = ( char * ) V_16 -> V_10 ;
V_22 = 0 ;
if ( V_21 < 11 ) goto V_15;
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ )
{
if ( ( V_20 == 5 ) && ( ( V_1 [ V_22 ] == 'Z' ) ||
( V_1 [ V_22 ] == '+' ) || ( V_1 [ V_22 ] == '-' ) ) )
{ V_20 ++ ; break; }
if ( ( V_1 [ V_22 ] < '0' ) || ( V_1 [ V_22 ] > '9' ) ) goto V_15;
V_19 = V_1 [ V_22 ] - '0' ;
if ( ++ V_22 > V_21 ) goto V_15;
if ( ( V_1 [ V_22 ] < '0' ) || ( V_1 [ V_22 ] > '9' ) ) goto V_15;
V_19 = ( V_19 * 10 ) + V_1 [ V_22 ] - '0' ;
if ( ++ V_22 > V_21 ) goto V_15;
if ( ( V_19 < V_17 [ V_20 ] ) || ( V_19 > V_18 [ V_20 ] ) ) goto V_15;
}
if ( V_1 [ V_22 ] == 'Z' )
V_22 ++ ;
else if ( ( V_1 [ V_22 ] == '+' ) || ( V_1 [ V_22 ] == '-' ) )
{
V_22 ++ ;
if ( V_22 + 4 > V_21 ) goto V_15;
for ( V_20 = 6 ; V_20 < 8 ; V_20 ++ )
{
if ( ( V_1 [ V_22 ] < '0' ) || ( V_1 [ V_22 ] > '9' ) ) goto V_15;
V_19 = V_1 [ V_22 ] - '0' ;
V_22 ++ ;
if ( ( V_1 [ V_22 ] < '0' ) || ( V_1 [ V_22 ] > '9' ) ) goto V_15;
V_19 = ( V_19 * 10 ) + V_1 [ V_22 ] - '0' ;
if ( ( V_19 < V_17 [ V_20 ] ) || ( V_19 > V_18 [ V_20 ] ) ) goto V_15;
V_22 ++ ;
}
}
return ( V_22 == V_21 ) ;
V_15:
return ( 0 ) ;
}
int F_11 ( T_1 * V_23 , char * V_24 )
{
T_1 V_25 ;
V_25 . type = V_4 ;
V_25 . V_9 = strlen ( V_24 ) ;
V_25 . V_10 = ( unsigned char * ) V_24 ;
if ( F_9 ( & V_25 ) )
{
if ( V_23 != NULL )
{
F_12 ( ( V_3 * ) V_23 ,
( unsigned char * ) V_24 , V_25 . V_9 ) ;
}
return ( 1 ) ;
}
else
return ( 0 ) ;
}
T_1 * F_13 ( T_1 * V_23 , T_2 V_25 )
{
char * V_26 ;
struct V_27 * V_28 ;
#if F_14 ( V_29 ) && ! F_14 ( V_30 )
struct V_27 V_10 ;
#endif
if ( V_23 == NULL )
V_23 = F_15 () ;
if ( V_23 == NULL )
return ( NULL ) ;
#if F_14 ( V_29 ) && ! F_14 ( V_30 )
gmtime_r ( & V_25 , & V_10 ) ;
V_28 = & V_10 ;
#else
V_28 = gmtime ( & V_25 ) ;
#endif
#ifdef F_16
if ( V_28 == NULL )
{
static F_17 ( V_31 , L_1 ) ;
static F_17 ( V_32 , L_2 ) ;
char V_33 [ 256 ] ;
unsigned int V_34 = 0 ;
struct {
short V_35 ;
short V_36 ;
void * V_37 ;
unsigned int * V_34 ;
} V_38 [] = {
{ 0 , V_39 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 } ,
} ;
int V_40 ;
V_38 [ 0 ] . V_35 = sizeof( V_33 ) ;
V_38 [ 0 ] . V_37 = V_33 ;
V_38 [ 0 ] . V_34 = & V_34 ;
V_40 = F_18 ( 0 , & V_31 , & V_32 , 0 , V_38 ) ;
if ( ! ( V_40 & 1 ) )
return NULL ;
V_33 [ V_34 ] = '\0' ;
V_40 = atoi ( V_33 ) ;
V_25 -= V_40 ;
V_28 = (struct V_27 * ) localtime ( & V_25 ) ;
}
#endif
V_26 = ( char * ) V_23 -> V_10 ;
if ( ( V_26 == NULL ) || ( V_23 -> V_9 < 14 ) )
{
V_26 = Malloc ( 20 ) ;
if ( V_26 == NULL ) return ( NULL ) ;
if ( V_23 -> V_10 != NULL )
Free ( V_23 -> V_10 ) ;
V_23 -> V_10 = ( unsigned char * ) V_26 ;
}
sprintf ( V_26 , L_3 , V_28 -> V_41 % 100 ,
V_28 -> V_42 + 1 , V_28 -> V_43 , V_28 -> V_44 , V_28 -> V_45 , V_28 -> V_46 ) ;
V_23 -> V_9 = strlen ( V_26 ) ;
V_23 -> type = V_4 ;
#ifdef F_19
F_4 ( V_23 -> V_10 , V_23 -> V_10 , V_23 -> V_9 ) ;
#endif
return ( V_23 ) ;
}
