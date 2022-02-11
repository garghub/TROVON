int F_1 ( int V_1 , void * V_2 , int V_3 , T_1 V_4 ,
T_2 * V_5 )
{
int V_6 = 0 ;
static unsigned char * V_7 = NULL ;
static unsigned char * V_8 = NULL ;
static int V_9 = 0 ;
static int V_10 = 0 ;
static unsigned char * V_11 = NULL ;
int V_12 ;
long V_13 = 0 , V_14 ;
unsigned char * V_15 ;
if ( V_11 == NULL )
{
V_11 = Malloc ( V_16 ) ;
if ( V_11 == NULL ) return ( - 1 ) ;
}
if ( V_7 == NULL )
{
V_7 = Malloc ( V_16 ) ;
if ( V_7 == NULL ) return ( - 1 ) ;
}
if ( V_8 == NULL )
{
V_8 = Malloc ( V_16 ) ;
if ( V_8 == NULL ) return ( - 1 ) ;
}
if ( V_10 != 0 )
{
if ( V_10 < V_3 )
{
memcpy ( V_2 , & ( V_8 [ V_9 ] ) ,
V_10 ) ;
V_12 = V_10 ;
V_9 = V_10 = 0 ;
}
else
{
memcpy ( V_2 , & ( V_8 [ V_9 ] ) , V_3 ) ;
V_9 += V_3 ;
V_10 -= V_3 ;
V_12 = V_3 ;
}
return ( V_12 ) ;
}
if ( V_3 > V_17 ) V_3 = V_17 ;
while ( V_6 < V_18 )
{
V_12 = F_2 ( V_1 , & ( V_7 [ V_6 ] ) , V_18 - V_6 ) ;
#ifdef F_3
if ( ( V_12 == - 1 ) && ( V_19 == F_3 ) ) continue;
#endif
if ( V_12 <= 0 ) return ( 0 ) ;
V_6 += V_12 ;
}
V_15 = V_7 ;
F_4 ( V_15 , V_13 ) ;
if ( ( V_13 > V_17 ) || ( V_13 < 0 ) )
return ( - 1 ) ;
V_14 = ( V_13 < 8 ) ? 8 : ( ( V_13 + 7 ) / 8 * 8 ) ;
V_6 = 0 ;
while ( V_6 < V_14 )
{
V_12 = F_2 ( V_1 , & ( V_7 [ V_6 ] ) , V_14 - V_6 ) ;
#ifdef F_3
if ( ( V_12 == - 1 ) && ( V_19 == F_3 ) ) continue;
#endif
if ( V_12 <= 0 ) return ( 0 ) ;
V_6 += V_12 ;
}
if ( V_3 < V_13 )
{
if ( V_20 & V_21 )
F_5 ( V_7 , V_8 , V_13 , V_4 , V_5 , V_22 ) ;
else
F_6 ( V_7 , V_8 , V_13 , V_4 , V_5 , V_22 ) ;
memcpy ( V_2 , V_8 , V_3 ) ;
V_9 = V_3 ;
V_10 = V_13 - V_3 ;
V_13 = V_3 ;
}
else
{
if ( V_3 < V_14 )
{
if ( V_20 & V_21 )
F_5 ( V_7 , V_11 , V_13 , V_4 , V_5 ,
V_22 ) ;
else
F_6 ( V_7 , V_11 , V_13 , V_4 , V_5 ,
V_22 ) ;
memcpy ( V_2 , V_11 , V_13 ) ;
}
else
{
if ( V_20 & V_21 )
F_5 ( V_7 , V_2 , V_13 , V_4 , V_5 ,
V_22 ) ;
else
F_6 ( V_7 , V_2 , V_13 , V_4 , V_5 ,
V_22 ) ;
}
}
return V_13 ;
}
