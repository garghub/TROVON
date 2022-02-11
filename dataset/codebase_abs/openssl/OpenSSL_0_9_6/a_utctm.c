T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_2 , unsigned char * * V_3 )
{
#ifndef F_6
return ( F_7 ( ( V_4 * ) V_2 , V_3 ,
V_5 , V_6 ) ) ;
#else
int V_7 ;
char V_8 [ 24 ] ;
V_4 V_1 = * ( V_4 * ) V_2 ;
V_7 = V_1 . V_9 ;
F_8 ( V_8 , V_1 . V_10 , ( V_7 >= sizeof V_8 ) ? sizeof V_8 : V_7 ) ;
V_1 . V_10 = V_8 ;
return F_7 ( & V_1 , V_3 , V_5 , V_6 ) ;
#endif
}
T_1 * F_9 ( T_1 * * V_2 , unsigned char * * V_3 ,
long V_9 )
{
T_1 * V_11 = NULL ;
V_11 = ( T_1 * ) F_10 ( ( V_4 * * ) V_2 , V_3 , V_9 ,
V_5 , V_6 ) ;
if ( V_11 == NULL )
{
F_11 ( V_12 , V_13 ) ;
return ( NULL ) ;
}
#ifdef F_6
F_12 ( V_11 -> V_10 , V_11 -> V_10 , V_11 -> V_9 ) ;
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
static int V_17 [ 8 ] = { 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ;
static int V_18 [ 8 ] = { 99 , 12 , 31 , 23 , 59 , 59 , 12 , 59 } ;
char * V_2 ;
int V_19 , V_20 , V_21 , V_22 ;
if ( V_16 -> type != V_5 ) return ( 0 ) ;
V_21 = V_16 -> V_9 ;
V_2 = ( char * ) V_16 -> V_10 ;
V_22 = 0 ;
if ( V_21 < 11 ) goto V_15;
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ )
{
if ( ( V_20 == 5 ) && ( ( V_2 [ V_22 ] == 'Z' ) ||
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
for ( V_20 = 6 ; V_20 < 8 ; V_20 ++ )
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
V_25 . type = V_5 ;
V_25 . V_9 = strlen ( V_24 ) ;
V_25 . V_10 = ( unsigned char * ) V_24 ;
if ( F_13 ( & V_25 ) )
{
if ( V_23 != NULL )
{
F_15 ( ( V_4 * ) V_23 ,
( unsigned char * ) V_24 , V_25 . V_9 ) ;
}
return ( 1 ) ;
}
else
return ( 0 ) ;
}
T_1 * F_16 ( T_1 * V_23 , T_2 V_25 )
{
char * V_26 ;
struct V_27 * V_28 ;
#if F_17 ( V_29 ) && ! F_17 ( V_30 ) && ! F_17 ( V_31 )
struct V_27 V_10 ;
#endif
if ( V_23 == NULL )
V_23 = F_2 () ;
if ( V_23 == NULL )
return ( NULL ) ;
#if F_17 ( V_29 ) && ! F_17 ( V_30 ) && ! F_17 ( V_31 )
gmtime_r ( & V_25 , & V_10 ) ;
V_28 = & V_10 ;
#else
V_28 = gmtime ( & V_25 ) ;
#endif
#ifdef F_18
if ( V_28 == NULL )
{
static F_19 ( V_32 , L_1 ) ;
static F_19 ( V_33 , L_2 ) ;
char V_34 [ 256 ] ;
unsigned int V_35 = 0 ;
struct {
short V_36 ;
short V_37 ;
void * V_38 ;
unsigned int * V_35 ;
} V_39 [] = {
{ 0 , V_40 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 } ,
} ;
int V_41 ;
V_39 [ 0 ] . V_36 = sizeof( V_34 ) ;
V_39 [ 0 ] . V_38 = V_34 ;
V_39 [ 0 ] . V_35 = & V_35 ;
V_41 = F_20 ( 0 , & V_32 , & V_33 , 0 , V_39 ) ;
if ( ! ( V_41 & 1 ) )
return NULL ;
V_34 [ V_35 ] = '\0' ;
V_41 = atoi ( V_34 ) ;
V_25 -= V_41 ;
V_28 = (struct V_27 * ) localtime ( & V_25 ) ;
}
#endif
V_26 = ( char * ) V_23 -> V_10 ;
if ( ( V_26 == NULL ) || ( V_23 -> V_9 < 14 ) )
{
V_26 = F_21 ( 20 ) ;
if ( V_26 == NULL ) return ( NULL ) ;
if ( V_23 -> V_10 != NULL )
F_22 ( V_23 -> V_10 ) ;
V_23 -> V_10 = ( unsigned char * ) V_26 ;
}
sprintf ( V_26 , L_3 , V_28 -> V_42 % 100 ,
V_28 -> V_43 + 1 , V_28 -> V_44 , V_28 -> V_45 , V_28 -> V_46 , V_28 -> V_47 ) ;
V_23 -> V_9 = strlen ( V_26 ) ;
V_23 -> type = V_5 ;
#ifdef F_23
F_8 ( V_23 -> V_10 , V_23 -> V_10 , V_23 -> V_9 ) ;
#endif
return ( V_23 ) ;
}
int F_24 ( const T_1 * V_23 , T_2 V_25 )
{
struct V_27 * V_27 ;
int V_48 ;
int V_49 ;
#define F_25 ( V_26 ) (((p)[0]-'0')*10+(p)[1]-'0')
if ( V_23 -> V_10 [ 12 ] == 'Z' )
V_48 = 0 ;
else
{
V_48 = F_25 ( V_23 -> V_10 + 13 ) * 60 + F_25 ( V_23 -> V_10 + 15 ) ;
if ( V_23 -> V_10 [ 12 ] == '-' )
V_48 = - V_48 ;
}
V_25 -= V_48 * 60 ;
#if F_17 ( V_29 ) && ! F_17 ( V_30 ) && ! F_17 ( V_31 )
{ struct V_27 V_10 ; gmtime_r ( & V_25 , & V_10 ) ; V_27 = & V_10 ; }
#else
V_27 = gmtime ( & V_25 ) ;
#endif
#define F_26 ( V_2 , T_3 ) if ((a)<(b)) return -1; else if ((a)>(b)) return 1
V_49 = F_25 ( V_23 -> V_10 ) ;
if ( V_49 < 50 )
V_49 += 100 ;
F_26 ( V_49 , V_27 -> V_42 ) ;
F_26 ( F_25 ( V_23 -> V_10 + 2 ) - 1 , V_27 -> V_43 ) ;
F_26 ( F_25 ( V_23 -> V_10 + 4 ) , V_27 -> V_44 ) ;
F_26 ( F_25 ( V_23 -> V_10 + 6 ) , V_27 -> V_45 ) ;
F_26 ( F_25 ( V_23 -> V_10 + 8 ) , V_27 -> V_46 ) ;
F_26 ( F_25 ( V_23 -> V_10 + 10 ) , V_27 -> V_47 ) ;
#undef F_25
#undef F_26
return 0 ;
}
