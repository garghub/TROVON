void F_1 ( T_1 * V_1 )
{
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
}
void F_2 ( T_1 * V_1 , const T_2 * V_2 ,
unsigned char * V_3 , unsigned char * V_4 , int V_5 )
{
if ( V_5 )
F_3 ( V_1 , V_2 , V_3 , V_4 ) ;
else
F_4 ( V_1 , V_2 , V_3 , V_4 ) ;
}
void F_5 ( T_1 * V_1 , unsigned char * V_6 , int * V_7 ,
unsigned char * V_8 , int V_9 )
{
if ( V_1 -> V_10 )
F_6 ( V_1 , V_6 , V_7 , V_8 , V_9 ) ;
else F_7 ( V_1 , V_6 , V_7 , V_8 , V_9 ) ;
}
int F_8 ( T_1 * V_1 , unsigned char * V_6 , int * V_7 )
{
if ( V_1 -> V_10 )
{
F_9 ( V_1 , V_6 , V_7 ) ;
return ( 1 ) ;
}
else return ( F_10 ( V_1 , V_6 , V_7 ) ) ;
}
void F_3 ( T_1 * V_1 , const T_2 * V_11 ,
unsigned char * V_3 , unsigned char * V_4 )
{
if ( V_11 != NULL )
V_1 -> V_11 = V_11 ;
V_1 -> V_11 -> V_12 ( V_1 , V_3 , V_4 , 1 ) ;
V_1 -> V_10 = 1 ;
V_1 -> V_13 = 0 ;
}
void F_4 ( T_1 * V_1 , const T_2 * V_11 ,
unsigned char * V_3 , unsigned char * V_4 )
{
if ( V_11 != NULL )
V_1 -> V_11 = V_11 ;
V_1 -> V_11 -> V_12 ( V_1 , V_3 , V_4 , 0 ) ;
V_1 -> V_10 = 0 ;
V_1 -> V_13 = 0 ;
}
void F_6 ( T_1 * V_1 , unsigned char * V_6 , int * V_7 ,
unsigned char * V_8 , int V_9 )
{
int V_14 , V_15 , V_16 ;
V_14 = V_1 -> V_13 ;
V_16 = V_1 -> V_11 -> V_17 ;
* V_7 = 0 ;
if ( ( V_9 == 0 ) && ( V_14 != V_16 ) ) return;
if ( V_14 != 0 )
{
if ( V_14 + V_9 < V_16 )
{
memcpy ( & ( V_1 -> V_18 [ V_14 ] ) , V_8 , V_9 ) ;
V_1 -> V_13 += V_9 ;
return;
}
else
{
V_15 = V_16 - V_14 ;
if ( V_15 != 0 ) memcpy ( & ( V_1 -> V_18 [ V_14 ] ) , V_8 , V_15 ) ;
V_1 -> V_11 -> V_19 ( V_1 , V_6 , V_1 -> V_18 , V_16 ) ;
V_9 -= V_15 ;
V_8 += V_15 ;
V_6 += V_16 ;
* V_7 += V_16 ;
}
}
V_14 = V_9 % V_16 ;
V_9 -= V_14 ;
if ( V_9 > 0 )
{
V_1 -> V_11 -> V_19 ( V_1 , V_6 , V_8 , V_9 ) ;
* V_7 += V_9 ;
}
if ( V_14 != 0 )
memcpy ( V_1 -> V_18 , & ( V_8 [ V_9 ] ) , V_14 ) ;
V_1 -> V_13 = V_14 ;
}
void F_9 ( T_1 * V_1 , unsigned char * V_6 , int * V_7 )
{
int V_14 , V_20 , V_21 , V_16 ;
V_21 = V_1 -> V_11 -> V_17 ;
if ( V_21 == 1 )
{
* V_7 = 0 ;
return;
}
V_16 = V_1 -> V_13 ;
V_20 = V_21 - V_16 ;
for ( V_14 = V_16 ; V_14 < V_21 ; V_14 ++ )
V_1 -> V_18 [ V_14 ] = V_20 ;
V_1 -> V_11 -> V_19 ( V_1 , V_6 , V_1 -> V_18 , V_21 ) ;
* V_7 = V_21 ;
}
void F_7 ( T_1 * V_1 , unsigned char * V_6 , int * V_7 ,
unsigned char * V_8 , int V_9 )
{
int V_21 , V_16 , V_20 ;
int V_22 = 0 ;
* V_7 = 0 ;
if ( V_9 == 0 ) return;
V_21 = V_1 -> V_11 -> V_17 ;
if ( V_21 > 1 )
{
V_16 = V_1 -> V_13 ;
V_20 = V_9 + V_16 ;
if ( V_20 % V_21 == 0 )
{
if ( V_9 < V_21 )
{
memcpy ( & ( V_1 -> V_18 [ V_16 ] ) , V_8 , V_9 ) ;
V_1 -> V_13 = V_21 ;
* V_7 = 0 ;
return;
}
V_22 = 1 ;
V_9 -= V_21 ;
}
}
F_6 ( V_1 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_22 )
{
memcpy ( & ( V_1 -> V_18 [ 0 ] ) , & ( V_8 [ V_9 ] ) , V_21 ) ;
#ifdef F_11
if ( V_1 -> V_13 != 0 )
{
abort () ;
}
#endif
V_1 -> V_13 = V_21 ;
}
}
int F_10 ( T_1 * V_1 , unsigned char * V_6 , int * V_7 )
{
int V_14 , V_21 ;
int V_20 ;
* V_7 = 0 ;
V_21 = V_1 -> V_11 -> V_17 ;
if ( V_21 > 1 )
{
if ( V_1 -> V_13 != V_21 )
{
F_12 ( V_23 , V_24 ) ;
return ( 0 ) ;
}
F_6 ( V_1 , V_1 -> V_18 , & V_20 , V_1 -> V_18 , 0 ) ;
if ( V_20 != V_21 )
return ( 0 ) ;
V_20 = V_1 -> V_18 [ V_21 - 1 ] ;
if ( V_20 > V_21 )
{
F_12 ( V_23 , V_25 ) ;
return ( 0 ) ;
}
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ )
{
if ( V_1 -> V_18 [ -- V_21 ] != V_20 )
{
F_12 ( V_23 , V_25 ) ;
return ( 0 ) ;
}
}
V_20 = V_1 -> V_11 -> V_17 - V_20 ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ )
V_6 [ V_14 ] = V_1 -> V_18 [ V_14 ] ;
* V_7 = V_20 ;
}
else
* V_7 = 0 ;
return ( 1 ) ;
}
void F_13 ( T_1 * V_26 )
{
if ( ( V_26 -> V_11 != NULL ) && ( V_26 -> V_11 -> V_27 != NULL ) )
V_26 -> V_11 -> V_27 ( V_26 ) ;
memset ( V_26 , 0 , sizeof( T_1 ) ) ;
}
