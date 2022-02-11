void F_1 ( struct V_1 * V_2 )
{
if ( ( long ) V_2 -> V_3 . V_4 . V_5 != - 1L ) {
* ( V_2 -> V_3 . V_4 . V_5 ) = V_2 -> V_3 . V_4 . V_6 ;
V_2 -> V_3 . V_4 . V_5 = ( unsigned short * ) - 1L ;
}
}
static int F_2 ( struct V_1 * V_7 , int V_8 )
{
unsigned char V_9 = F_3 ( V_7 , V_10 ) ;
__asm__("bld #3,%w0\n\t"
"bxor #1,%w0\n\t"
"bst #4,%w0\n\t"
"bor #2,%w0\n\t"
"bst #5,%w0\n\t"
"bld #2,%w0\n\t"
"bor #0,%w0\n\t"
"bst #6,%w0\n\t"
: "=&r"(cond) : "0"(cond) : "cc");
V_9 &= V_11 [ V_8 >> 1 ] ;
if ( ! ( V_8 & 1 ) )
return V_9 == 0 ;
else
return V_9 != 0 ;
}
static unsigned short * F_4 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
char * V_14 , unsigned short * V_15 ,
unsigned char V_6 )
{
unsigned long V_5 ;
unsigned long * V_16 ;
int V_17 ;
switch ( V_13 -> type ) {
case V_18 :
return ( unsigned short * ) V_15 + V_13 -> V_19 ;
case V_20 :
V_5 = * ( unsigned long * ) V_15 ;
return ( unsigned short * ) ( V_5 & 0x00ffffff ) ;
case V_21 :
V_5 = * V_15 & 0xff ;
return ( unsigned short * ) ( * ( unsigned long * ) V_5 ) ;
case V_22 :
V_16 = ( unsigned long * ) F_3 ( V_2 , V_23 ) ;
return ( unsigned short * ) ( * ( V_16 + 2 ) & 0x00ffffff ) ;
case V_24 :
V_17 = ( * V_15 >> 4 ) & 0x07 ;
if ( V_17 == 0 )
V_5 = F_3 ( V_2 , V_25 ) ;
else
V_5 = F_3 ( V_2 , V_17 - 1 + V_26 ) ;
return ( unsigned short * ) V_5 ;
case V_27 :
if ( V_6 == 0x55 || F_2 ( V_2 , V_6 & 0x0f ) )
V_15 = ( unsigned short * ) ( ( unsigned long ) V_15 +
( ( signed char ) ( * V_14 ) ) ) ;
return V_15 + 1 ;
case V_28 :
if ( V_6 == 0x5c || F_2 ( V_2 , ( * V_14 & 0xf0 ) >> 4 ) )
V_15 = ( unsigned short * ) ( ( unsigned long ) V_15 +
( ( signed short ) ( * ( V_15 + 1 ) ) ) ) ;
return V_15 + 2 ;
default:
return NULL ;
}
}
static unsigned short * F_5 ( struct V_1 * V_2 , unsigned short * V_15 )
{
const struct V_12 * V_13 ;
unsigned char * V_14 ;
int V_29 ;
unsigned char V_6 ;
V_13 = V_30 [ 0 ] . V_31 ;
V_29 = V_30 [ 0 ] . V_32 ;
V_14 = ( unsigned char * ) V_15 ;
V_6 = * V_14 ++ ;
do {
if ( ( V_6 & V_13 -> V_33 ) == V_13 -> V_34 ) {
if ( V_13 -> V_19 < 0 ) {
V_13 = V_30 [ - V_13 -> V_19 ] . V_31 ;
V_29 = V_30 [ - V_13 -> V_19 ] . V_32 + 1 ;
V_6 = * V_14 ++ ;
} else
return F_4 ( V_2 , V_13 , V_14 , V_15 , V_6 ) ;
} else
V_13 ++ ;
} while ( -- V_29 > 0 );
return NULL ;
}
void F_6 ( struct V_1 * V_2 )
{
unsigned short * V_35 ;
V_35 = F_5 ( V_2 , ( unsigned short * ) F_3 ( V_2 , V_36 ) ) ;
V_2 -> V_3 . V_4 . V_5 = V_35 ;
V_2 -> V_3 . V_4 . V_6 = * V_35 ;
* V_35 = V_37 ;
}
T_1 void F_7 ( unsigned long V_38 )
{
if ( ( unsigned long ) V_39 -> V_3 . V_4 . V_5 == V_38 ) {
F_1 ( V_39 ) ;
F_8 ( V_40 , V_39 ) ;
} else
F_8 ( V_41 , V_39 ) ;
}
