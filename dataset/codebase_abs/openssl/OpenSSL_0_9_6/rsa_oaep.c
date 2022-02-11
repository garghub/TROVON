int F_1 ( unsigned char * V_1 , int V_2 ,
unsigned char * V_3 , int V_4 , unsigned char * V_5 , int V_6 )
{
int V_7 , V_8 = V_2 - 1 ;
unsigned char * V_9 , * V_10 ;
unsigned char * V_11 , V_12 [ V_13 ] ;
if ( V_4 > V_8 - 2 * V_13 - 1 )
{
F_2 ( V_14 ,
V_15 ) ;
return ( 0 ) ;
}
if ( V_8 < 2 * V_13 + 1 )
{
F_2 ( V_14 , V_16 ) ;
return ( 0 ) ;
}
V_11 = F_3 ( V_8 - V_13 ) ;
if ( V_11 == NULL )
{
F_2 ( V_14 , V_17 ) ;
return ( 0 ) ;
}
V_1 [ 0 ] = 0 ;
V_10 = V_1 + 1 ;
V_9 = V_1 + V_13 + 1 ;
F_4 ( V_5 , V_6 , V_9 ) ;
memset ( V_9 + V_13 , 0 ,
V_8 - V_4 - 2 * V_13 - 1 ) ;
V_9 [ V_8 - V_4 - V_13 - 1 ] = 0x01 ;
memcpy ( V_9 + V_8 - V_4 - V_13 , V_3 , ( unsigned int ) V_4 ) ;
if ( F_5 ( V_10 , V_13 ) <= 0 )
return ( 0 ) ;
#ifdef F_6
memcpy ( V_10 ,
L_1 ,
20 ) ;
#endif
F_7 ( V_11 , V_8 - V_13 , V_10 , V_13 ) ;
for ( V_7 = 0 ; V_7 < V_8 - V_13 ; V_7 ++ )
V_9 [ V_7 ] ^= V_11 [ V_7 ] ;
F_7 ( V_12 , V_13 , V_9 , V_8 - V_13 ) ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ )
V_10 [ V_7 ] ^= V_12 [ V_7 ] ;
F_8 ( V_11 ) ;
return ( 1 ) ;
}
int F_9 ( unsigned char * V_1 , int V_2 ,
unsigned char * V_3 , int V_4 , int V_18 , unsigned char * V_5 ,
int V_6 )
{
int V_7 , V_19 , V_20 = - 1 ;
unsigned char * V_21 ;
int V_22 ;
unsigned char * V_9 , V_10 [ V_13 ] , V_23 [ V_13 ] ;
if ( -- V_18 < 2 * V_13 + 1 )
{
F_2 ( V_24 , V_25 ) ;
return ( - 1 ) ;
}
V_19 = V_18 - V_13 ;
V_9 = F_3 ( V_19 ) ;
if ( V_9 == NULL )
{
F_2 ( V_14 , V_17 ) ;
return ( - 1 ) ;
}
V_22 = V_18 - V_4 ;
V_21 = V_3 - V_22 + V_13 ;
F_7 ( V_10 , V_13 , V_21 , V_19 ) ;
for ( V_7 = V_22 ; V_7 < V_13 ; V_7 ++ )
V_10 [ V_7 ] ^= V_3 [ V_7 - V_22 ] ;
F_7 ( V_9 , V_19 , V_10 , V_13 ) ;
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ )
V_9 [ V_7 ] ^= V_21 [ V_7 ] ;
F_4 ( V_5 , V_6 , V_23 ) ;
if ( memcmp ( V_9 , V_23 , V_13 ) != 0 )
F_2 ( V_24 , V_25 ) ;
else
{
for ( V_7 = V_13 ; V_7 < V_19 ; V_7 ++ )
if ( V_9 [ V_7 ] != 0x00 )
break;
if ( V_9 [ V_7 ] != 0x01 || V_7 ++ >= V_19 )
F_2 ( V_24 ,
V_25 ) ;
else
{
V_20 = V_19 - V_7 ;
if ( V_2 < V_20 )
{
F_2 ( V_14 , V_26 ) ;
V_20 = - 1 ;
}
else
memcpy ( V_1 , V_9 + V_7 , V_20 ) ;
}
}
F_8 ( V_9 ) ;
return ( V_20 ) ;
}
int F_7 ( unsigned char * V_27 , long V_28 , unsigned char * V_10 , long V_29 )
{
long V_7 , V_30 = 0 ;
unsigned char V_31 [ 4 ] ;
T_1 V_32 ;
unsigned char V_33 [ V_13 ] ;
for ( V_7 = 0 ; V_30 < V_28 ; V_7 ++ )
{
V_31 [ 0 ] = ( V_7 >> 24 ) & 255 , V_31 [ 1 ] = ( V_7 >> 16 ) & 255 ,
V_31 [ 2 ] = ( V_7 >> 8 ) & 255 , V_31 [ 3 ] = V_7 & 255 ;
F_10 ( & V_32 ) ;
F_11 ( & V_32 , V_10 , V_29 ) ;
F_11 ( & V_32 , V_31 , 4 ) ;
if ( V_30 + V_13 <= V_28 )
{
F_12 ( V_27 + V_30 , & V_32 ) ;
V_30 += V_13 ;
}
else
{
F_12 ( V_33 , & V_32 ) ;
memcpy ( V_27 + V_30 , V_33 , V_28 - V_30 ) ;
V_30 = V_28 ;
}
}
return ( 0 ) ;
}
