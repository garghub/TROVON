long F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_4 :
return V_2 -> V_5 . V_6 + sizeof( long ) * 2 ;
case V_7 :
return * ( unsigned short * ) ( V_2 -> V_5 . V_8 + V_9 [ V_3 ] ) ;
default:
return * ( unsigned long * ) ( V_2 -> V_5 . V_8 + V_9 [ V_3 ] ) ;
}
}
int F_2 ( struct V_1 * V_2 , int V_3 , unsigned long V_10 )
{
unsigned short V_11 ;
switch ( V_3 ) {
case V_4 :
V_2 -> V_5 . V_6 = V_10 - sizeof( long ) * 2 ;
case V_7 :
V_11 = * ( unsigned short * ) ( V_2 -> V_5 . V_8 + V_9 [ V_3 ] ) ;
V_11 &= ~ V_12 ;
V_10 &= V_12 ;
V_10 |= V_11 ;
* ( unsigned short * ) ( V_2 -> V_5 . V_8 + V_9 [ V_3 ] ) = V_10 ;
break;
default:
* ( unsigned long * ) ( V_2 -> V_5 . V_8 + V_9 [ V_3 ] ) = V_10 ;
break;
}
return 0 ;
}
void F_3 ( struct V_1 * V_13 )
{
if( ( long ) V_13 -> V_5 . V_14 . V_15 != - 1L ) {
* V_13 -> V_5 . V_14 . V_15 = V_13 -> V_5 . V_14 . V_16 ;
V_13 -> V_5 . V_14 . V_15 = ( unsigned short * ) - 1L ;
}
}
static int F_4 ( struct V_1 * V_2 , int V_17 )
{
unsigned char V_18 = F_1 ( V_2 , V_7 ) ;
__asm__("bld #3,%w0\n\t"
"bxor #1,%w0\n\t"
"bst #4,%w0\n\t"
"bor #2,%w0\n\t"
"bst #5,%w0\n\t"
"bld #2,%w0\n\t"
"bor #0,%w0\n\t"
"bst #6,%w0\n\t"
:"=&r"(cond)::"cc");
V_18 &= V_19 [ V_17 >> 1 ] ;
if ( ! ( V_17 & 1 ) )
return V_18 == 0 ;
else
return V_18 != 0 ;
}
static unsigned short * F_5 ( struct V_1 * V_13 , unsigned short * V_20 )
{
const struct V_21 * V_22 ;
unsigned char * V_23 ;
unsigned char V_16 ;
unsigned long V_15 ;
unsigned long * V_24 ;
int V_25 , V_3 ;
V_22 = V_26 [ 0 ] . V_27 ;
V_25 = V_26 [ 0 ] . V_28 ;
V_23 = ( unsigned char * ) V_20 ;
V_16 = * V_23 ++ ;
do {
if ( ( V_16 & V_22 -> V_29 ) == V_22 -> V_30 ) {
if ( V_22 -> V_31 < 0 ) {
V_22 = V_26 [ - V_22 -> V_31 ] . V_27 ;
V_25 = V_26 [ - V_22 -> V_31 ] . V_28 + 1 ;
V_16 = * V_23 ++ ;
} else {
switch ( V_22 -> type ) {
case V_32 :
return V_20 + V_22 -> V_31 ;
case V_33 :
V_15 = * ( unsigned long * ) V_20 ;
return ( unsigned short * ) ( V_15 & 0x00ffffff ) ;
case V_34 :
V_15 = * V_20 & 0xff ;
return ( unsigned short * ) ( * ( unsigned long * ) V_15 ) ;
case V_35 :
V_24 = ( unsigned long * ) F_1 ( V_13 , V_4 ) ;
return ( unsigned short * ) ( * ( V_24 + 2 ) & 0x00ffffff ) ;
case V_36 :
V_3 = ( * V_20 >> 4 ) & 0x07 ;
if ( V_3 == 0 )
V_15 = F_1 ( V_13 , V_37 ) ;
else
V_15 = F_1 ( V_13 , V_3 - 1 + V_38 ) ;
return ( unsigned short * ) V_15 ;
case V_39 :
if ( V_16 == 0x55 || F_4 ( V_13 , V_16 & 0x0f ) )
V_20 = ( unsigned short * ) ( ( unsigned long ) V_20 +
( ( signed char ) ( * V_23 ) ) ) ;
return V_20 + 1 ;
case V_40 :
if ( V_16 == 0x5c || F_4 ( V_13 , ( * V_23 & 0xf0 ) >> 4 ) )
V_20 = ( unsigned short * ) ( ( unsigned long ) V_20 +
( ( signed short ) ( * ( V_20 + 1 ) ) ) ) ;
return V_20 + 2 ;
}
}
} else
V_22 ++ ;
} while( -- V_25 > 0 );
return NULL ;
}
void F_6 ( struct V_1 * V_13 )
{
unsigned short * V_41 ;
V_41 = F_5 ( V_13 , ( unsigned short * ) F_1 ( V_13 , V_42 ) ) ;
V_13 -> V_5 . V_14 . V_15 = V_41 ;
V_13 -> V_5 . V_14 . V_16 = * V_41 ;
* V_41 = V_43 ;
}
T_1 void F_7 ( unsigned long V_44 )
{
if ( ( unsigned long ) V_45 -> V_5 . V_14 . V_15 == V_44 ) {
F_3 ( V_45 ) ;
F_8 ( V_46 , V_45 ) ;
} else
F_8 ( V_47 , V_45 ) ;
}
