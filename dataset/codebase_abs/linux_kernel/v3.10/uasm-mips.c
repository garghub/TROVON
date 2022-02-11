static inline T_1 T_2 F_1 ( T_3 V_1 )
{
F_2 ( V_1 > 0x1ffff || V_1 < - 0x20000 ,
V_2 L_1 ) ;
F_2 ( V_1 & 0x3 , V_2 L_2 ) ;
return ( ( V_1 < 0 ) ? ( 1 << 15 ) : 0 ) | ( ( V_1 >> 2 ) & 0x7fff ) ;
}
static inline T_1 T_2 F_3 ( T_2 V_1 )
{
F_2 ( V_1 & ~ ( V_3 << 2 ) ,
V_2 L_1 ) ;
return ( V_1 >> 2 ) & V_3 ;
}
static void T_1 F_4 ( T_2 * * V_4 , enum V_5 V_6 , ... )
{
struct V_7 * V_8 = NULL ;
unsigned int V_9 ;
T_4 V_10 ;
T_2 V_11 ;
for ( V_9 = 0 ; V_12 [ V_9 ] . V_5 != V_13 ; V_9 ++ )
if ( V_12 [ V_9 ] . V_5 == V_6 ) {
V_8 = & V_12 [ V_9 ] ;
break;
}
if ( ! V_8 || ( V_6 == V_14 && F_5 () ) )
F_6 ( L_3 , V_6 ) ;
V_11 = V_8 -> V_15 ;
va_start ( V_10 , V_6 ) ;
if ( V_8 -> V_16 & V_17 )
V_11 |= F_7 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_18 )
V_11 |= F_8 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_19 )
V_11 |= F_9 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_20 )
V_11 |= F_10 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_21 )
V_11 |= F_11 ( va_arg ( V_10 , T_3 ) ) ;
if ( V_8 -> V_16 & V_22 )
V_11 |= F_12 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_23 )
V_11 |= F_1 ( va_arg ( V_10 , T_3 ) ) ;
if ( V_8 -> V_16 & V_24 )
V_11 |= F_3 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_25 )
V_11 |= F_13 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_26 )
V_11 |= F_14 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_27 )
V_11 |= F_15 ( va_arg ( V_10 , T_2 ) ) ;
va_end ( V_10 ) ;
* * V_4 = V_11 ;
( * V_4 ) ++ ;
}
static inline void T_1
F_16 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
long V_32 = ( long ) V_31 -> V_33 ;
long V_34 = ( long ) V_29 -> V_33 ;
switch ( V_29 -> type ) {
case V_35 :
* V_29 -> V_33 |= F_1 ( V_32 - ( V_34 + 4 ) ) ;
break;
default:
F_6 ( L_4 ,
V_29 -> type ) ;
}
}
