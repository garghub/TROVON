static int F_1 ( T_1 * V_1 ,
const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
int V_6 ;
if ( V_4 )
V_6 = F_3 ( V_2 , V_1 -> V_7 * 8 , & V_5 -> V_8 ) ;
else
V_6 = F_4 ( V_2 , V_1 -> V_7 * 8 , & V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = V_5 -> V_9 ;
V_5 -> V_11 = V_5 -> V_9 ;
V_5 -> V_12 = 0 ;
return V_6 < 0 ? 0 : 1 ;
}
static void F_6 ( T_3 * V_13 , const void * F_2 , T_4 V_14 )
{ const unsigned char * V_15 = F_2 ;
T_4 V_16 ;
if ( ( V_16 = V_13 -> V_17 ) ) {
V_16 = V_18 - V_16 ;
if ( V_14 < V_16 ) V_16 = V_14 ;
F_7 ( V_13 , V_15 , V_16 ) ;
V_15 += V_16 ;
V_14 -= V_16 ;
}
V_16 = V_14 % V_18 ;
V_14 -= V_16 ;
if ( V_14 ) {
F_8 ( V_13 , V_15 , V_14 / V_18 ) ;
V_15 += V_14 ;
V_13 -> V_19 += V_14 >> 29 ;
V_13 -> V_20 += V_14 <<= 3 ;
if ( V_13 -> V_20 < ( unsigned int ) V_14 ) V_13 -> V_19 ++ ;
}
if ( V_16 )
F_7 ( V_13 , V_15 , V_16 ) ;
}
static int F_9 ( T_1 * V_1 , unsigned char * V_21 ,
const unsigned char * V_22 , T_4 V_14 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
unsigned int V_23 ;
T_4 V_24 = V_5 -> V_12 ,
V_3 = 0 ,
V_25 = 0 ;
#if F_10 ( V_26 )
T_4 V_27 = 0 ,
V_28 ;
V_25 = V_18 - V_5 -> V_11 . V_17 ;
#endif
if ( V_14 % V_29 ) return 0 ;
if ( V_1 -> V_30 ) {
if ( V_24 == 0 )
V_24 = V_14 ;
else if ( V_14 != ( ( V_24 + V_31 + V_29 ) & - V_29 ) )
return 0 ;
else if ( V_5 -> V_32 . V_33 >= V_34 )
V_3 = V_29 ;
#if F_10 ( V_26 )
if ( V_24 > ( V_25 + V_3 ) && ( V_28 = ( V_24 - ( V_25 + V_3 ) ) / V_18 ) ) {
F_7 ( & V_5 -> V_11 , V_22 + V_3 , V_25 ) ;
F_11 ( V_22 , V_21 , V_28 , & V_5 -> V_8 ,
V_1 -> V_3 , & V_5 -> V_11 , V_22 + V_3 + V_25 ) ;
V_28 *= V_18 ;
V_27 += V_28 ;
V_25 += V_28 ;
V_5 -> V_11 . V_19 += V_28 >> 29 ;
V_5 -> V_11 . V_20 += V_28 <<= 3 ;
if ( V_5 -> V_11 . V_20 < ( unsigned int ) V_28 ) V_5 -> V_11 . V_19 ++ ;
} else {
V_25 = 0 ;
}
#endif
V_25 += V_3 ;
F_7 ( & V_5 -> V_11 , V_22 + V_25 , V_24 - V_25 ) ;
if ( V_24 != V_14 ) {
if ( V_22 != V_21 )
memcpy ( V_21 + V_27 , V_22 + V_27 , V_24 - V_27 ) ;
F_12 ( V_21 + V_24 , & V_5 -> V_11 ) ;
V_5 -> V_11 = V_5 -> V_10 ;
F_7 ( & V_5 -> V_11 , V_21 + V_24 , V_31 ) ;
F_12 ( V_21 + V_24 , & V_5 -> V_11 ) ;
V_24 += V_31 ;
for ( V_23 = V_14 - V_24 - 1 ; V_24 < V_14 ; V_24 ++ ) V_21 [ V_24 ] = V_23 ;
F_13 ( V_21 + V_27 , V_21 + V_27 , V_14 - V_27 ,
& V_5 -> V_8 , V_1 -> V_3 , 1 ) ;
} else {
F_13 ( V_22 + V_27 , V_21 + V_27 , V_14 - V_27 ,
& V_5 -> V_8 , V_1 -> V_3 , 1 ) ;
}
} else {
unsigned char V_35 [ V_31 ] ;
F_13 ( V_22 , V_21 , V_14 ,
& V_5 -> V_8 , V_1 -> V_3 , 0 ) ;
if ( V_24 ) {
if ( V_14 < ( T_4 ) ( V_21 [ V_14 - 1 ] + 1 + V_31 ) )
return 0 ;
V_14 -= ( V_21 [ V_14 - 1 ] + 1 + V_31 ) ;
if ( ( V_5 -> V_32 . V_36 [ V_24 - 4 ] << 8 | V_5 -> V_32 . V_36 [ V_24 - 3 ] )
>= V_34 ) {
V_14 -= V_29 ;
V_3 = V_29 ;
}
V_5 -> V_32 . V_36 [ V_24 - 2 ] = V_14 >> 8 ;
V_5 -> V_32 . V_36 [ V_24 - 1 ] = V_14 ;
V_5 -> V_11 = V_5 -> V_9 ;
F_7 ( & V_5 -> V_11 , V_5 -> V_32 . V_36 , V_24 ) ;
F_7 ( & V_5 -> V_11 , V_21 + V_3 , V_14 ) ;
F_12 ( V_35 , & V_5 -> V_11 ) ;
V_5 -> V_11 = V_5 -> V_10 ;
F_7 ( & V_5 -> V_11 , V_35 , V_31 ) ;
F_12 ( V_35 , & V_5 -> V_11 ) ;
if ( memcmp ( V_21 + V_3 + V_14 , V_35 , V_31 ) )
return 0 ;
} else {
F_7 ( & V_5 -> V_11 , V_21 , V_14 ) ;
}
}
V_5 -> V_12 = 0 ;
return 1 ;
}
static int F_14 ( T_1 * V_1 , int type , int V_37 , void * V_15 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
switch ( type )
{
case V_38 :
{
unsigned int V_39 ;
unsigned char V_40 [ 64 ] ;
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
if ( V_37 > ( int ) sizeof( V_40 ) ) {
F_5 ( & V_5 -> V_9 ) ;
F_7 ( & V_5 -> V_9 , V_15 , V_37 ) ;
F_12 ( V_40 , & V_5 -> V_9 ) ;
} else {
memcpy ( V_40 , V_15 , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < sizeof( V_40 ) ; V_39 ++ )
V_40 [ V_39 ] ^= 0x36 ;
F_5 ( & V_5 -> V_9 ) ;
F_7 ( & V_5 -> V_9 , V_40 , sizeof( V_40 ) ) ;
for ( V_39 = 0 ; V_39 < sizeof( V_40 ) ; V_39 ++ )
V_40 [ V_39 ] ^= 0x36 ^ 0x5c ;
F_5 ( & V_5 -> V_10 ) ;
F_7 ( & V_5 -> V_10 , V_40 , sizeof( V_40 ) ) ;
return 1 ;
}
case V_41 :
{
unsigned char * V_42 = V_15 ;
unsigned int V_14 = V_42 [ V_37 - 2 ] << 8 | V_42 [ V_37 - 1 ] ;
if ( V_1 -> V_30 )
{
V_5 -> V_12 = V_14 ;
if ( ( V_5 -> V_32 . V_33 = V_42 [ V_37 - 4 ] << 8 | V_42 [ V_37 - 3 ] ) >= V_34 ) {
V_14 -= V_29 ;
V_42 [ V_37 - 2 ] = V_14 >> 8 ;
V_42 [ V_37 - 1 ] = V_14 ;
}
V_5 -> V_11 = V_5 -> V_9 ;
F_7 ( & V_5 -> V_11 , V_42 , V_37 ) ;
return ( int ) ( ( ( V_14 + V_31 + V_29 ) & - V_29 )
- V_14 ) ;
}
else
{
if ( V_37 > 13 ) V_37 = 13 ;
memcpy ( V_5 -> V_32 . V_36 , V_15 , V_37 ) ;
V_5 -> V_12 = V_37 ;
return V_31 ;
}
}
default:
return - 1 ;
}
}
const T_5 * F_15 ( void )
{
return ( V_43 [ 1 ] & V_44 ?
& V_45 : NULL ) ;
}
const T_5 * F_16 ( void )
{
return ( V_43 [ 1 ] & V_44 ?
& V_46 : NULL ) ;
}
const T_5 * F_15 ( void )
{
return NULL ;
}
const T_5 * F_16 ( void )
{
return NULL ;
}
