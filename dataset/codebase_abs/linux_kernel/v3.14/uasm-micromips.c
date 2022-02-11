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
struct V_7 * V_8 = NULL ;
unsigned int V_9 ;
T_3 V_10 ;
T_1 V_11 ;
for ( V_9 = 0 ; V_12 [ V_9 ] . V_5 != V_13 ; V_9 ++ )
if ( V_12 [ V_9 ] . V_5 == V_6 ) {
V_8 = & V_12 [ V_9 ] ;
break;
}
if ( ! V_8 || ( V_6 == V_14 && F_5 () ) )
F_6 ( L_3 , V_6 ) ;
V_11 = V_8 -> V_15 ;
va_start ( V_10 , V_6 ) ;
if ( V_8 -> V_16 & V_17 ) {
if ( V_6 == V_18 || V_6 == V_19 )
V_11 |= F_7 ( va_arg ( V_10 , T_1 ) ) ;
else
V_11 |= F_8 ( va_arg ( V_10 , T_1 ) ) ;
}
if ( V_8 -> V_16 & V_20 ) {
if ( V_6 == V_18 || V_6 == V_19 )
V_11 |= F_8 ( va_arg ( V_10 , T_1 ) ) ;
else
V_11 |= F_7 ( va_arg ( V_10 , T_1 ) ) ;
}
if ( V_8 -> V_16 & V_21 )
V_11 |= F_9 ( va_arg ( V_10 , T_1 ) ) ;
if ( V_8 -> V_16 & V_22 )
V_11 |= F_10 ( va_arg ( V_10 , T_1 ) ) ;
if ( V_8 -> V_16 & V_23 )
V_11 |= F_11 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_24 )
V_11 |= F_12 ( va_arg ( V_10 , T_1 ) ) ;
if ( V_8 -> V_16 & V_25 )
V_11 |= F_1 ( va_arg ( V_10 , T_2 ) ) ;
if ( V_8 -> V_16 & V_26 )
V_11 |= F_3 ( va_arg ( V_10 , T_1 ) ) ;
if ( V_8 -> V_16 & V_27 )
V_11 |= F_13 ( va_arg ( V_10 , T_1 ) ) ;
if ( V_8 -> V_16 & V_28 )
V_11 |= F_14 ( va_arg ( V_10 , T_1 ) ) ;
if ( V_8 -> V_16 & V_29 )
V_11 |= F_15 ( va_arg ( V_10 , T_1 ) ) ;
va_end ( V_10 ) ;
#ifdef F_16
* * V_4 = ( ( V_11 & 0xffff ) << 16 ) | ( V_11 >> 16 ) ;
#else
* * V_4 = V_11 ;
#endif
( * V_4 ) ++ ;
}
static inline void
F_17 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
long V_34 = ( long ) V_33 -> V_35 ;
long V_36 = ( long ) V_31 -> V_35 ;
switch ( V_31 -> type ) {
case V_37 :
#ifdef F_16
* V_31 -> V_35 |= ( F_1 ( V_34 - ( V_36 + 4 ) ) << 16 ) ;
#else
* V_31 -> V_35 |= F_1 ( V_34 - ( V_36 + 4 ) ) ;
#endif
break;
default:
F_6 ( L_4 ,
V_31 -> type ) ;
}
}
