int F_1 ( int V_1 , const void * V_2 , int V_3 ,
T_1 * V_4 , T_2 * V_5 )
{
#if F_2 ( V_6 )
return ( - 1 ) ;
#else
#ifdef F_3
extern unsigned long time ();
extern int F_4 ();
#endif
const unsigned char * V_7 = V_2 ;
long V_8 ;
int V_9 , V_10 , V_11 , V_12 ;
static unsigned char * V_13 = NULL ;
unsigned char V_14 [ 8 ] ;
unsigned char * V_15 ;
const unsigned char * V_16 ;
static int V_17 = 1 ;
if ( V_13 == NULL )
{
V_13 = F_5 ( V_18 + V_19 ) ;
if ( V_13 == NULL ) return ( - 1 ) ;
}
if ( V_17 )
{
V_17 = 0 ;
}
if ( V_3 > V_20 )
{
V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_3 ; V_9 += V_11 )
{
V_11 = F_1 ( V_1 , & ( V_7 [ V_9 ] ) ,
( ( V_3 - V_9 ) > V_20 ) ? V_20 : ( V_3 - V_9 ) , V_4 , V_5 ) ;
if ( V_11 < 0 )
return ( V_11 ) ;
else
V_10 += V_11 ;
}
return ( V_10 ) ;
}
V_15 = V_13 ;
F_6 ( V_3 , V_15 ) ;
if ( V_3 < 8 )
{
V_16 = V_14 ;
memcpy ( V_14 , V_7 , V_3 ) ;
F_7 ( V_14 + V_3 , 8 - V_3 ) ;
V_8 = 8 ;
}
else
{
V_16 = V_7 ;
V_8 = ( ( V_3 + 7 ) / 8 * 8 ) ;
}
if ( V_21 & V_22 )
F_8 ( V_16 , & ( V_13 [ V_19 ] ) , ( V_3 < 8 ) ? 8 : V_3 , V_4 , V_5 ,
V_23 ) ;
else
F_9 ( V_16 , & ( V_13 [ V_19 ] ) , ( V_3 < 8 ) ? 8 : V_3 , V_4 , V_5 ,
V_23 ) ;
V_12 = V_8 + V_19 ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 += V_9 )
{
#ifndef F_10
V_9 = F_4 ( V_1 , ( void * ) & ( V_13 [ V_10 ] ) , V_12 - V_10 ) ;
#else
V_9 = F_11 ( V_1 , ( void * ) & ( V_13 [ V_10 ] ) , V_12 - V_10 ) ;
#endif
if ( V_9 == - 1 )
{
#ifdef F_12
if ( V_24 == F_12 )
V_9 = 0 ;
else
#endif
return ( - 1 ) ;
}
}
return ( V_3 ) ;
#endif
}
