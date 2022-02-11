int F_1 ( int V_1 , const void * V_2 , int V_3 ,
T_1 V_4 , T_2 * V_5 )
{
#ifdef F_2
extern int F_3 ();
extern unsigned long time ();
extern int F_4 ();
extern int F_5 ();
#endif
const unsigned char * V_6 = V_2 ;
long V_7 ;
int V_8 , V_9 , V_10 , V_11 ;
static unsigned char * V_12 = NULL ;
unsigned char V_13 [ 8 ] ;
unsigned char * V_14 ;
const unsigned char * V_15 ;
static int V_16 = 1 ;
if ( V_12 == NULL )
{
V_12 = Malloc ( V_17 + V_18 ) ;
if ( V_12 == NULL ) return ( - 1 ) ;
}
if ( V_16 )
{
V_16 = 0 ;
F_3 ( time ( NULL ) ) ;
}
if ( V_3 > V_19 )
{
V_9 = 0 ;
for ( V_8 = 0 ; V_8 < V_3 ; V_8 += V_10 )
{
V_10 = F_1 ( V_1 , & ( V_6 [ V_8 ] ) ,
( ( V_3 - V_8 ) > V_19 ) ? V_19 : ( V_3 - V_8 ) , V_4 , V_5 ) ;
if ( V_10 < 0 )
return ( V_10 ) ;
else
V_9 += V_10 ;
}
return ( V_9 ) ;
}
V_14 = V_12 ;
F_6 ( V_3 , V_14 ) ;
if ( V_3 < 8 )
{
V_15 = V_13 ;
memcpy ( V_13 , V_6 , V_3 ) ;
for ( V_8 = V_3 ; V_8 < 8 ; V_8 ++ )
V_13 [ V_8 ] = F_4 () ;
V_7 = 8 ;
}
else
{
V_15 = ( unsigned char * ) V_6 ;
V_7 = ( ( V_3 + 7 ) / 8 * 8 ) ;
}
if ( V_20 & V_21 )
F_7 ( V_15 , & ( V_12 [ V_18 ] ) , ( V_3 < 8 ) ? 8 : V_3 , V_4 , V_5 ,
V_22 ) ;
else
F_8 ( V_15 , & ( V_12 [ V_18 ] ) , ( V_3 < 8 ) ? 8 : V_3 , V_4 , V_5 ,
V_22 ) ;
V_11 = V_7 + V_18 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 += V_8 )
{
V_8 = F_5 ( V_1 , & ( V_12 [ V_9 ] ) , V_11 - V_9 ) ;
if ( V_8 == - 1 )
{
if ( V_23 == V_24 )
V_8 = 0 ;
else
return ( - 1 ) ;
}
}
return ( V_3 ) ;
}
