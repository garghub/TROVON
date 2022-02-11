static int F_1 ( T_1 * V_1 ,
const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
F_3 ( & V_5 -> V_6 , F_4 ( V_1 ) , V_2 ) ;
F_5 ( & V_5 -> V_7 ) ;
V_5 -> V_8 = V_5 -> V_7 ;
V_5 -> V_9 = V_5 -> V_7 ;
V_5 -> V_10 = V_11 ;
return 1 ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_12 ,
const unsigned char * V_13 , T_3 V_14 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
# if F_7 ( V_15 )
T_3 V_16 = 32 - 1 - ( V_5 -> V_6 . V_17 & ( 32 - 1 ) ) ,
V_18 = V_19 - V_5 -> V_9 . V_20 , V_21 ;
unsigned int V_22 ;
extern unsigned int V_23 [] ;
# endif
T_3 V_24 = V_5 -> V_10 ;
if ( V_24 != V_11 && V_14 != ( V_24 + V_25 ) )
return 0 ;
if ( V_1 -> V_26 ) {
if ( V_24 == V_11 )
V_24 = V_14 ;
# if F_7 ( V_15 )
if ( V_16 > V_18 )
V_18 += V_19 ;
if ( V_24 > V_18 && ( V_21 = ( V_24 - V_18 ) / V_19 ) &&
( V_23 [ 0 ] & ( 1 << 20 ) ) == 0 ) {
F_8 ( & V_5 -> V_9 , V_13 , V_18 ) ;
F_9 ( & V_5 -> V_6 , V_16 , V_13 , V_12 ) ;
F_10 ( & V_5 -> V_6 , V_13 + V_16 , V_12 + V_16 ,
& V_5 -> V_9 , V_13 + V_18 , V_21 ) ;
V_21 *= V_19 ;
V_16 += V_21 ;
V_18 += V_21 ;
V_5 -> V_9 . V_27 += V_21 >> 29 ;
V_5 -> V_9 . V_28 += V_21 <<= 3 ;
if ( V_5 -> V_9 . V_28 < ( unsigned int ) V_21 )
V_5 -> V_9 . V_27 ++ ;
} else {
V_16 = 0 ;
V_18 = 0 ;
}
# endif
F_8 ( & V_5 -> V_9 , V_13 + V_18 , V_24 - V_18 ) ;
if ( V_24 != V_14 ) {
if ( V_13 != V_12 )
memcpy ( V_12 + V_16 , V_13 + V_16 , V_24 - V_16 ) ;
F_11 ( V_12 + V_24 , & V_5 -> V_9 ) ;
V_5 -> V_9 = V_5 -> V_8 ;
F_8 ( & V_5 -> V_9 , V_12 + V_24 , V_25 ) ;
F_11 ( V_12 + V_24 , & V_5 -> V_9 ) ;
F_9 ( & V_5 -> V_6 , V_14 - V_16 , V_12 + V_16 , V_12 + V_16 ) ;
} else {
F_9 ( & V_5 -> V_6 , V_14 - V_16 , V_13 + V_16 , V_12 + V_16 ) ;
}
} else {
unsigned char V_29 [ V_25 ] ;
# if F_7 ( V_15 )
if ( V_18 > V_16 )
V_16 += 2 * V_19 ;
else
V_16 += V_19 ;
if ( V_14 > V_16 && ( V_21 = ( V_14 - V_16 ) / V_19 ) &&
( V_23 [ 0 ] & ( 1 << 20 ) ) == 0 ) {
F_9 ( & V_5 -> V_6 , V_16 , V_13 , V_12 ) ;
F_8 ( & V_5 -> V_9 , V_12 , V_18 ) ;
F_10 ( & V_5 -> V_6 , V_13 + V_16 , V_12 + V_16 ,
& V_5 -> V_9 , V_12 + V_18 , V_21 ) ;
V_21 *= V_19 ;
V_16 += V_21 ;
V_18 += V_21 ;
V_22 = ( V_5 -> V_9 . V_28 + ( V_21 << 3 ) ) & 0xffffffffU ;
if ( V_22 < V_5 -> V_9 . V_28 )
V_5 -> V_9 . V_27 ++ ;
V_5 -> V_9 . V_28 = V_22 ;
V_5 -> V_9 . V_27 += V_21 >> 29 ;
} else {
V_18 = 0 ;
V_16 = 0 ;
}
# endif
F_9 ( & V_5 -> V_6 , V_14 - V_16 , V_13 + V_16 , V_12 + V_16 ) ;
if ( V_24 != V_11 ) {
F_8 ( & V_5 -> V_9 , V_12 + V_18 , V_24 - V_18 ) ;
F_11 ( V_29 , & V_5 -> V_9 ) ;
V_5 -> V_9 = V_5 -> V_8 ;
F_8 ( & V_5 -> V_9 , V_29 , V_25 ) ;
F_11 ( V_29 , & V_5 -> V_9 ) ;
if ( memcmp ( V_12 + V_24 , V_29 , V_25 ) )
return 0 ;
} else {
F_8 ( & V_5 -> V_9 , V_12 + V_18 , V_14 - V_18 ) ;
}
}
V_5 -> V_10 = V_11 ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , int type , int V_30 ,
void * V_31 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
switch ( type ) {
case V_32 :
{
unsigned int V_33 ;
unsigned char V_34 [ 64 ] ;
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
if ( V_30 > ( int ) sizeof( V_34 ) ) {
F_5 ( & V_5 -> V_7 ) ;
F_8 ( & V_5 -> V_7 , V_31 , V_30 ) ;
F_11 ( V_34 , & V_5 -> V_7 ) ;
} else {
memcpy ( V_34 , V_31 , V_30 ) ;
}
for ( V_33 = 0 ; V_33 < sizeof( V_34 ) ; V_33 ++ )
V_34 [ V_33 ] ^= 0x36 ;
F_5 ( & V_5 -> V_7 ) ;
F_8 ( & V_5 -> V_7 , V_34 , sizeof( V_34 ) ) ;
for ( V_33 = 0 ; V_33 < sizeof( V_34 ) ; V_33 ++ )
V_34 [ V_33 ] ^= 0x36 ^ 0x5c ;
F_5 ( & V_5 -> V_8 ) ;
F_8 ( & V_5 -> V_8 , V_34 , sizeof( V_34 ) ) ;
return 1 ;
}
case V_35 :
{
unsigned char * V_36 = V_31 ;
unsigned int V_14 = V_36 [ V_30 - 2 ] << 8 | V_36 [ V_30 - 1 ] ;
if ( ! V_1 -> V_26 ) {
V_14 -= V_25 ;
V_36 [ V_30 - 2 ] = V_14 >> 8 ;
V_36 [ V_30 - 1 ] = V_14 ;
}
V_5 -> V_10 = V_14 ;
V_5 -> V_9 = V_5 -> V_7 ;
F_8 ( & V_5 -> V_9 , V_36 , V_30 ) ;
return V_25 ;
}
default:
return - 1 ;
}
}
const T_4 * F_13 ( void )
{
return ( & V_37 ) ;
}
