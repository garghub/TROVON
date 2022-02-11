int F_1 ( int V_1 , void * V_2 , int V_3 , T_1 * V_4 ,
T_2 * V_5 )
{
#if F_2 ( V_6 )
return ( 0 ) ;
#else
int V_7 = 0 ;
static unsigned char * V_8 = NULL ;
static unsigned char * V_9 = NULL ;
static int V_10 = 0 ;
static int V_11 = 0 ;
static unsigned char * V_12 = NULL ;
int V_13 ;
long V_14 = 0 , V_15 ;
unsigned char * V_16 ;
if ( V_12 == NULL )
{
V_12 = F_3 ( V_17 ) ;
if ( V_12 == NULL ) return ( - 1 ) ;
}
if ( V_8 == NULL )
{
V_8 = F_3 ( V_17 ) ;
if ( V_8 == NULL ) return ( - 1 ) ;
}
if ( V_9 == NULL )
{
V_9 = F_3 ( V_17 ) ;
if ( V_9 == NULL ) return ( - 1 ) ;
}
if ( V_11 != 0 )
{
if ( V_11 < V_3 )
{
memcpy ( V_2 , & ( V_9 [ V_10 ] ) ,
V_11 ) ;
V_13 = V_11 ;
V_10 = V_11 = 0 ;
}
else
{
memcpy ( V_2 , & ( V_9 [ V_10 ] ) , V_3 ) ;
V_10 += V_3 ;
V_11 -= V_3 ;
V_13 = V_3 ;
}
return ( V_13 ) ;
}
if ( V_3 > V_18 ) V_3 = V_18 ;
while ( V_7 < V_19 )
{
#ifndef F_4
V_13 = F_5 ( V_1 , ( void * ) & ( V_8 [ V_7 ] ) , V_19 - V_7 ) ;
#else
V_13 = F_6 ( V_1 , ( void * ) & ( V_8 [ V_7 ] ) , V_19 - V_7 ) ;
#endif
#ifdef F_7
if ( ( V_13 == - 1 ) && ( V_20 == F_7 ) ) continue;
#endif
if ( V_13 <= 0 ) return ( 0 ) ;
V_7 += V_13 ;
}
V_16 = V_8 ;
F_8 ( V_16 , V_14 ) ;
if ( ( V_14 > V_18 ) || ( V_14 < 0 ) )
return ( - 1 ) ;
V_15 = ( V_14 < 8 ) ? 8 : ( ( V_14 + 7 ) / 8 * 8 ) ;
V_7 = 0 ;
while ( V_7 < V_15 )
{
#ifndef F_4
V_13 = F_5 ( V_1 , ( void * ) & ( V_8 [ V_7 ] ) , V_15 - V_7 ) ;
#else
V_13 = F_6 ( V_1 , ( void * ) & ( V_8 [ V_7 ] ) , V_15 - V_7 ) ;
#endif
#ifdef F_7
if ( ( V_13 == - 1 ) && ( V_20 == F_7 ) ) continue;
#endif
if ( V_13 <= 0 ) return ( 0 ) ;
V_7 += V_13 ;
}
if ( V_3 < V_14 )
{
if ( V_21 & V_22 )
F_9 ( V_8 , V_9 , V_14 , V_4 , V_5 , V_23 ) ;
else
F_10 ( V_8 , V_9 , V_14 , V_4 , V_5 , V_23 ) ;
memcpy ( V_2 , V_9 , V_3 ) ;
V_10 = V_3 ;
V_11 = V_14 - V_3 ;
V_14 = V_3 ;
}
else
{
if ( V_3 < V_15 )
{
if ( V_21 & V_22 )
F_9 ( V_8 , V_12 , V_14 , V_4 , V_5 ,
V_23 ) ;
else
F_10 ( V_8 , V_12 , V_14 , V_4 , V_5 ,
V_23 ) ;
memcpy ( V_2 , V_12 , V_14 ) ;
}
else
{
if ( V_21 & V_22 )
F_9 ( V_8 , V_2 , V_14 , V_4 , V_5 ,
V_23 ) ;
else
F_10 ( V_8 , V_2 , V_14 , V_4 , V_5 ,
V_23 ) ;
}
}
return V_14 ;
#endif
}
