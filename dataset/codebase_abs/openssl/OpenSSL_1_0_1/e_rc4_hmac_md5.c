static int F_1 ( T_1 * V_1 ,
const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
F_3 ( & V_5 -> V_6 , F_4 ( V_1 ) ,
V_2 ) ;
F_5 ( & V_5 -> V_7 ) ;
V_5 -> V_8 = V_5 -> V_7 ;
V_5 -> V_9 = V_5 -> V_7 ;
V_5 -> V_10 = 0 ;
return 1 ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_11 ,
const unsigned char * V_12 , T_3 V_13 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
#if F_7 ( V_14 )
T_3 V_15 = 32 - 1 - ( V_5 -> V_6 . V_16 & ( 32 - 1 ) ) ,
V_17 = V_18 - V_5 -> V_9 . V_19 ,
V_20 ;
unsigned int V_21 ;
#endif
T_3 V_22 = V_5 -> V_10 ;
if ( V_22 && V_13 != ( V_22 + V_23 ) ) return 0 ;
if ( V_1 -> V_24 ) {
if ( V_22 == 0 ) V_22 = V_13 ;
#if F_7 ( V_14 )
if ( V_15 > V_17 ) V_17 += V_18 ;
if ( V_22 > V_17 && ( V_20 = ( V_22 - V_17 ) / V_18 ) ) {
F_8 ( & V_5 -> V_9 , V_12 , V_17 ) ;
F_9 ( & V_5 -> V_6 , V_15 , V_12 , V_11 ) ;
F_10 ( & V_5 -> V_6 , V_12 + V_15 , V_11 + V_15 ,
& V_5 -> V_9 , V_12 + V_17 , V_20 ) ;
V_20 *= V_18 ;
V_15 += V_20 ;
V_17 += V_20 ;
V_5 -> V_9 . V_25 += V_20 >> 29 ;
V_5 -> V_9 . V_26 += V_20 <<= 3 ;
if ( V_5 -> V_9 . V_26 < ( unsigned int ) V_20 ) V_5 -> V_9 . V_25 ++ ;
} else {
V_15 = 0 ;
V_17 = 0 ;
}
#endif
F_8 ( & V_5 -> V_9 , V_12 + V_17 , V_22 - V_17 ) ;
if ( V_22 != V_13 ) {
if ( V_12 != V_11 )
memcpy ( V_11 + V_15 , V_12 + V_15 , V_22 - V_15 ) ;
F_11 ( V_11 + V_22 , & V_5 -> V_9 ) ;
V_5 -> V_9 = V_5 -> V_8 ;
F_8 ( & V_5 -> V_9 , V_11 + V_22 , V_23 ) ;
F_11 ( V_11 + V_22 , & V_5 -> V_9 ) ;
F_9 ( & V_5 -> V_6 , V_13 - V_15 , V_11 + V_15 , V_11 + V_15 ) ;
} else {
F_9 ( & V_5 -> V_6 , V_13 - V_15 , V_12 + V_15 , V_11 + V_15 ) ;
}
} else {
unsigned char V_27 [ V_23 ] ;
#if F_7 ( V_14 )
if ( V_17 > V_15 ) V_15 += 2 * V_18 ;
else V_15 += V_18 ;
if ( V_13 > V_15 && ( V_20 = ( V_13 - V_15 ) / V_18 ) ) {
F_9 ( & V_5 -> V_6 , V_15 , V_12 , V_11 ) ;
F_8 ( & V_5 -> V_9 , V_11 , V_17 ) ;
F_10 ( & V_5 -> V_6 , V_12 + V_15 , V_11 + V_15 ,
& V_5 -> V_9 , V_11 + V_17 , V_20 ) ;
V_20 *= V_18 ;
V_15 += V_20 ;
V_17 += V_20 ;
V_21 = ( V_5 -> V_9 . V_26 + ( V_20 << 3 ) ) & 0xffffffffU ;
if ( V_21 < V_5 -> V_9 . V_26 ) V_5 -> V_9 . V_25 ++ ;
V_5 -> V_9 . V_26 = V_21 ;
V_5 -> V_9 . V_25 += V_20 >> 29 ;
} else {
V_17 = 0 ;
V_15 = 0 ;
}
#endif
F_9 ( & V_5 -> V_6 , V_13 - V_15 , V_12 + V_15 , V_11 + V_15 ) ;
if ( V_22 ) {
F_8 ( & V_5 -> V_9 , V_11 + V_17 , V_22 - V_17 ) ;
F_11 ( V_27 , & V_5 -> V_9 ) ;
V_5 -> V_9 = V_5 -> V_8 ;
F_8 ( & V_5 -> V_9 , V_27 , V_23 ) ;
F_11 ( V_27 , & V_5 -> V_9 ) ;
if ( memcmp ( V_11 + V_22 , V_27 , V_23 ) )
return 0 ;
} else {
F_8 ( & V_5 -> V_9 , V_11 + V_17 , V_13 - V_17 ) ;
}
}
V_5 -> V_10 = 0 ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , int type , int V_28 , void * V_29 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
switch ( type )
{
case V_30 :
{
unsigned int V_31 ;
unsigned char V_32 [ 64 ] ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
if ( V_28 > ( int ) sizeof( V_32 ) ) {
F_5 ( & V_5 -> V_7 ) ;
F_8 ( & V_5 -> V_7 , V_29 , V_28 ) ;
F_11 ( V_32 , & V_5 -> V_7 ) ;
} else {
memcpy ( V_32 , V_29 , V_28 ) ;
}
for ( V_31 = 0 ; V_31 < sizeof( V_32 ) ; V_31 ++ )
V_32 [ V_31 ] ^= 0x36 ;
F_5 ( & V_5 -> V_7 ) ;
F_8 ( & V_5 -> V_7 , V_32 , sizeof( V_32 ) ) ;
for ( V_31 = 0 ; V_31 < sizeof( V_32 ) ; V_31 ++ )
V_32 [ V_31 ] ^= 0x36 ^ 0x5c ;
F_5 ( & V_5 -> V_8 ) ;
F_8 ( & V_5 -> V_8 , V_32 , sizeof( V_32 ) ) ;
return 1 ;
}
case V_33 :
{
unsigned char * V_34 = V_29 ;
unsigned int V_13 = V_34 [ V_28 - 2 ] << 8 | V_34 [ V_28 - 1 ] ;
if ( ! V_1 -> V_24 )
{
V_13 -= V_23 ;
V_34 [ V_28 - 2 ] = V_13 >> 8 ;
V_34 [ V_28 - 1 ] = V_13 ;
}
V_5 -> V_10 = V_13 ;
V_5 -> V_9 = V_5 -> V_7 ;
F_8 ( & V_5 -> V_9 , V_34 , V_28 ) ;
return V_23 ;
}
default:
return - 1 ;
}
}
const T_4 * F_13 ( void )
{
return ( & V_35 ) ;
}
