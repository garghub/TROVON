static inline T_1 F_1 ( T_2 V_1 )
{
F_2 ( V_1 > 0xffff || V_1 < - 0x10000 ,
V_2 L_1 ) ;
F_2 ( V_1 & 0x3 , V_2 L_2 ) ;
return ( ( V_1 < 0 ) ? ( 1 << 15 ) : 0 ) | ( ( V_1 >> 1 ) & 0x7fff ) ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
F_2 ( V_1 & ~ ( ( V_3 << 2 ) | 1 ) ,
V_2 L_1 ) ;
return ( V_1 >> 1 ) & V_3 ;
}
static void F_4 ( T_1 * * V_4 , enum V_5 V_6 , ... )
{
const struct V_7 * V_8 ;
T_3 V_9 ;
T_1 V_10 ;
if ( V_6 < 0 || V_6 >= V_11 ||
( V_6 == V_12 && F_5 () ) ||
( V_13 [ V_6 ] . V_14 == 0 && V_13 [ V_6 ] . V_15 == 0 ) )
F_6 ( L_3 , V_6 ) ;
V_8 = & V_13 [ V_6 ] ;
V_10 = V_8 -> V_14 ;
va_start ( V_9 , V_6 ) ;
if ( V_8 -> V_15 & V_16 ) {
if ( V_6 == V_17 || V_6 == V_18 ||
V_6 == V_19 || V_6 == V_20 )
V_10 |= F_7 ( va_arg ( V_9 , T_1 ) ) ;
else
V_10 |= F_8 ( va_arg ( V_9 , T_1 ) ) ;
}
if ( V_8 -> V_15 & V_21 ) {
if ( V_6 == V_17 || V_6 == V_18 ||
V_6 == V_19 || V_6 == V_20 )
V_10 |= F_8 ( va_arg ( V_9 , T_1 ) ) ;
else
V_10 |= F_7 ( va_arg ( V_9 , T_1 ) ) ;
}
if ( V_8 -> V_15 & V_22 )
V_10 |= F_9 ( va_arg ( V_9 , T_1 ) ) ;
if ( V_8 -> V_15 & V_23 )
V_10 |= F_10 ( va_arg ( V_9 , T_1 ) ) ;
if ( V_8 -> V_15 & V_24 )
V_10 |= F_11 ( va_arg ( V_9 , T_2 ) ) ;
if ( V_8 -> V_15 & V_25 )
V_10 |= F_12 ( va_arg ( V_9 , T_1 ) ) ;
if ( V_8 -> V_15 & V_26 )
V_10 |= F_1 ( va_arg ( V_9 , T_2 ) ) ;
if ( V_8 -> V_15 & V_27 )
V_10 |= F_3 ( va_arg ( V_9 , T_1 ) ) ;
if ( V_8 -> V_15 & V_28 )
V_10 |= F_13 ( va_arg ( V_9 , T_1 ) ) ;
if ( V_8 -> V_15 & V_29 )
V_10 |= F_14 ( va_arg ( V_9 , T_1 ) ) ;
if ( V_8 -> V_15 & V_30 )
V_10 |= F_15 ( va_arg ( V_9 , T_1 ) ) ;
va_end ( V_9 ) ;
#ifdef F_16
* * V_4 = ( ( V_10 & 0xffff ) << 16 ) | ( V_10 >> 16 ) ;
#else
* * V_4 = V_10 ;
#endif
( * V_4 ) ++ ;
}
static inline void
F_17 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
long V_35 = ( long ) V_34 -> V_36 ;
long V_37 = ( long ) V_32 -> V_36 ;
switch ( V_32 -> type ) {
case V_38 :
#ifdef F_16
* V_32 -> V_36 |= ( F_1 ( V_35 - ( V_37 + 4 ) ) << 16 ) ;
#else
* V_32 -> V_36 |= F_1 ( V_35 - ( V_37 + 4 ) ) ;
#endif
break;
default:
F_6 ( L_4 ,
V_32 -> type ) ;
}
}
