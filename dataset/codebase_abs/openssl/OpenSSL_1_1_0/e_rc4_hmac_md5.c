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
if ( F_8 ( V_1 ) ) {
if ( V_24 == V_11 )
V_24 = V_14 ;
# if F_7 ( V_15 )
if ( V_16 > V_18 )
V_18 += V_19 ;
if ( V_24 > V_18 && ( V_21 = ( V_24 - V_18 ) / V_19 ) &&
( V_23 [ 0 ] & ( 1 << 20 ) ) == 0 ) {
F_9 ( & V_5 -> V_9 , V_13 , V_18 ) ;
F_10 ( & V_5 -> V_6 , V_16 , V_13 , V_12 ) ;
F_11 ( & V_5 -> V_6 , V_13 + V_16 , V_12 + V_16 ,
& V_5 -> V_9 , V_13 + V_18 , V_21 ) ;
V_21 *= V_19 ;
V_16 += V_21 ;
V_18 += V_21 ;
V_5 -> V_9 . V_26 += V_21 >> 29 ;
V_5 -> V_9 . V_27 += V_21 <<= 3 ;
if ( V_5 -> V_9 . V_27 < ( unsigned int ) V_21 )
V_5 -> V_9 . V_26 ++ ;
} else {
V_16 = 0 ;
V_18 = 0 ;
}
# endif
F_9 ( & V_5 -> V_9 , V_13 + V_18 , V_24 - V_18 ) ;
if ( V_24 != V_14 ) {
if ( V_13 != V_12 )
memcpy ( V_12 + V_16 , V_13 + V_16 , V_24 - V_16 ) ;
F_12 ( V_12 + V_24 , & V_5 -> V_9 ) ;
V_5 -> V_9 = V_5 -> V_8 ;
F_9 ( & V_5 -> V_9 , V_12 + V_24 , V_25 ) ;
F_12 ( V_12 + V_24 , & V_5 -> V_9 ) ;
F_10 ( & V_5 -> V_6 , V_14 - V_16 , V_12 + V_16 , V_12 + V_16 ) ;
} else {
F_10 ( & V_5 -> V_6 , V_14 - V_16 , V_13 + V_16 , V_12 + V_16 ) ;
}
} else {
unsigned char V_28 [ V_25 ] ;
# if F_7 ( V_15 )
if ( V_18 > V_16 )
V_16 += 2 * V_19 ;
else
V_16 += V_19 ;
if ( V_14 > V_16 && ( V_21 = ( V_14 - V_16 ) / V_19 ) &&
( V_23 [ 0 ] & ( 1 << 20 ) ) == 0 ) {
F_10 ( & V_5 -> V_6 , V_16 , V_13 , V_12 ) ;
F_9 ( & V_5 -> V_9 , V_12 , V_18 ) ;
F_11 ( & V_5 -> V_6 , V_13 + V_16 , V_12 + V_16 ,
& V_5 -> V_9 , V_12 + V_18 , V_21 ) ;
V_21 *= V_19 ;
V_16 += V_21 ;
V_18 += V_21 ;
V_22 = ( V_5 -> V_9 . V_27 + ( V_21 << 3 ) ) & 0xffffffffU ;
if ( V_22 < V_5 -> V_9 . V_27 )
V_5 -> V_9 . V_26 ++ ;
V_5 -> V_9 . V_27 = V_22 ;
V_5 -> V_9 . V_26 += V_21 >> 29 ;
} else {
V_18 = 0 ;
V_16 = 0 ;
}
# endif
F_10 ( & V_5 -> V_6 , V_14 - V_16 , V_13 + V_16 , V_12 + V_16 ) ;
if ( V_24 != V_11 ) {
F_9 ( & V_5 -> V_9 , V_12 + V_18 , V_24 - V_18 ) ;
F_12 ( V_28 , & V_5 -> V_9 ) ;
V_5 -> V_9 = V_5 -> V_8 ;
F_9 ( & V_5 -> V_9 , V_28 , V_25 ) ;
F_12 ( V_28 , & V_5 -> V_9 ) ;
if ( F_13 ( V_12 + V_24 , V_28 , V_25 ) )
return 0 ;
} else {
F_9 ( & V_5 -> V_9 , V_12 + V_18 , V_14 - V_18 ) ;
}
}
V_5 -> V_10 = V_11 ;
return 1 ;
}
static int F_14 ( T_1 * V_1 , int type , int V_29 ,
void * V_30 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
switch ( type ) {
case V_31 :
{
unsigned int V_32 ;
unsigned char V_33 [ 64 ] ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
if ( V_29 > ( int ) sizeof( V_33 ) ) {
F_5 ( & V_5 -> V_7 ) ;
F_9 ( & V_5 -> V_7 , V_30 , V_29 ) ;
F_12 ( V_33 , & V_5 -> V_7 ) ;
} else {
memcpy ( V_33 , V_30 , V_29 ) ;
}
for ( V_32 = 0 ; V_32 < sizeof( V_33 ) ; V_32 ++ )
V_33 [ V_32 ] ^= 0x36 ;
F_5 ( & V_5 -> V_7 ) ;
F_9 ( & V_5 -> V_7 , V_33 , sizeof( V_33 ) ) ;
for ( V_32 = 0 ; V_32 < sizeof( V_33 ) ; V_32 ++ )
V_33 [ V_32 ] ^= 0x36 ^ 0x5c ;
F_5 ( & V_5 -> V_8 ) ;
F_9 ( & V_5 -> V_8 , V_33 , sizeof( V_33 ) ) ;
F_15 ( V_33 , sizeof( V_33 ) ) ;
return 1 ;
}
case V_34 :
{
unsigned char * V_35 = V_30 ;
unsigned int V_14 ;
if ( V_29 != V_36 )
return - 1 ;
V_14 = V_35 [ V_29 - 2 ] << 8 | V_35 [ V_29 - 1 ] ;
if ( ! F_8 ( V_1 ) ) {
V_14 -= V_25 ;
V_35 [ V_29 - 2 ] = V_14 >> 8 ;
V_35 [ V_29 - 1 ] = V_14 ;
}
V_5 -> V_10 = V_14 ;
V_5 -> V_9 = V_5 -> V_7 ;
F_9 ( & V_5 -> V_9 , V_35 , V_29 ) ;
return V_25 ;
}
default:
return - 1 ;
}
}
const T_4 * F_16 ( void )
{
return ( & V_37 ) ;
}
