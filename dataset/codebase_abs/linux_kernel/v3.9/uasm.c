static inline T_1 T_2 F_1 ( T_2 V_1 )
{
F_2 ( V_1 & ~ V_2 , V_3 L_1 ) ;
return ( V_1 & V_2 ) << V_4 ;
}
static inline T_1 T_2 F_3 ( T_2 V_1 )
{
F_2 ( V_1 & ~ V_5 , V_3 L_1 ) ;
return ( V_1 & V_5 ) << V_6 ;
}
static inline T_1 T_2 F_4 ( T_2 V_1 )
{
F_2 ( V_1 & ~ V_7 , V_3 L_1 ) ;
return ( V_1 & V_7 ) << V_8 ;
}
static inline T_1 T_2 F_5 ( T_2 V_1 )
{
F_2 ( V_1 & ~ V_9 , V_3 L_1 ) ;
return ( V_1 & V_9 ) << V_10 ;
}
static inline T_1 T_2 F_6 ( T_3 V_1 )
{
F_2 ( V_1 > 0x7fff || V_1 < - 0x8000 ,
V_3 L_1 ) ;
return V_1 & 0xffff ;
}
static inline T_1 T_2 F_7 ( T_2 V_1 )
{
F_2 ( V_1 & ~ V_11 , V_3 L_1 ) ;
return V_1 & V_11 ;
}
static inline T_1 T_2 F_8 ( T_3 V_1 )
{
F_2 ( V_1 > 0x1ffff || V_1 < - 0x20000 ,
V_3 L_1 ) ;
F_2 ( V_1 & 0x3 , V_3 L_2 ) ;
return ( ( V_1 < 0 ) ? ( 1 << 15 ) : 0 ) | ( ( V_1 >> 2 ) & 0x7fff ) ;
}
static inline T_1 T_2 F_9 ( T_2 V_1 )
{
F_2 ( V_1 & ~ ( V_12 << 2 ) ,
V_3 L_1 ) ;
return ( V_1 >> 2 ) & V_12 ;
}
static inline T_1 T_2 F_10 ( T_2 V_1 )
{
F_2 ( V_1 & ~ V_13 ,
V_3 L_1 ) ;
return ( V_1 & V_13 ) << V_14 ;
}
static inline T_1 T_2 F_11 ( T_2 V_1 )
{
F_2 ( V_1 & ~ V_15 , V_3 L_1 ) ;
return V_1 & V_15 ;
}
static inline T_1 T_2 F_12 ( T_2 V_1 )
{
F_2 ( V_1 & ~ V_16 , V_3 L_1 ) ;
return V_1 & V_16 ;
}
static void T_1 F_13 ( T_2 * * V_17 , enum V_18 V_19 , ... )
{
struct V_20 * V_21 = NULL ;
unsigned int V_22 ;
T_4 V_23 ;
T_2 V_24 ;
for ( V_22 = 0 ; V_25 [ V_22 ] . V_18 != V_26 ; V_22 ++ )
if ( V_25 [ V_22 ] . V_18 == V_19 ) {
V_21 = & V_25 [ V_22 ] ;
break;
}
if ( ! V_21 || ( V_19 == V_27 && F_14 () ) )
F_15 ( L_3 , V_19 ) ;
V_24 = V_21 -> V_28 ;
va_start ( V_23 , V_19 ) ;
if ( V_21 -> V_29 & V_30 )
V_24 |= F_1 ( va_arg ( V_23 , T_2 ) ) ;
if ( V_21 -> V_29 & V_31 )
V_24 |= F_3 ( va_arg ( V_23 , T_2 ) ) ;
if ( V_21 -> V_29 & V_32 )
V_24 |= F_4 ( va_arg ( V_23 , T_2 ) ) ;
if ( V_21 -> V_29 & V_33 )
V_24 |= F_5 ( va_arg ( V_23 , T_2 ) ) ;
if ( V_21 -> V_29 & V_34 )
V_24 |= F_6 ( va_arg ( V_23 , T_3 ) ) ;
if ( V_21 -> V_29 & V_35 )
V_24 |= F_7 ( va_arg ( V_23 , T_2 ) ) ;
if ( V_21 -> V_29 & V_36 )
V_24 |= F_8 ( va_arg ( V_23 , T_3 ) ) ;
if ( V_21 -> V_29 & V_37 )
V_24 |= F_9 ( va_arg ( V_23 , T_2 ) ) ;
if ( V_21 -> V_29 & V_38 )
V_24 |= F_11 ( va_arg ( V_23 , T_2 ) ) ;
if ( V_21 -> V_29 & V_39 )
V_24 |= F_12 ( va_arg ( V_23 , T_2 ) ) ;
if ( V_21 -> V_29 & V_40 )
V_24 |= F_10 ( va_arg ( V_23 , T_2 ) ) ;
va_end ( V_23 ) ;
* * V_17 = V_24 ;
( * V_17 ) ++ ;
}
void T_1 F_16 ( T_2 * * V_17 , unsigned int V_41 , signed int V_42 ,
unsigned int V_43 )
{
if ( F_17 ( V_44 ) && V_41 <= 24 && V_41 != 5 )
F_13 ( V_17 , V_45 , V_43 , 28 , V_42 ) ;
else
F_13 ( V_17 , V_45 , V_43 , V_41 , V_42 ) ;
}
void T_1 F_18 ( struct V_46 * * V_47 , T_2 * V_48 , int V_49 )
{
( * V_47 ) -> V_48 = V_48 ;
( * V_47 ) -> V_47 = V_49 ;
( * V_47 ) ++ ;
}
int T_1 F_19 ( long V_48 )
{
#ifdef F_20
return ( ( ( V_48 ) & 0xffffffff00000000L ) == 0xffffffff00000000L ) ;
#else
return 1 ;
#endif
}
static int T_1 F_21 ( long V_50 )
{
#ifdef F_20
return ( ( ( ( V_50 + 0x800080008000L ) >> 48 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
#else
return 0 ;
#endif
}
static int T_1 F_22 ( long V_50 )
{
#ifdef F_20
return ( ( ( ( V_50 + 0x80008000L ) >> 32 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
#else
return 0 ;
#endif
}
int T_1 F_23 ( long V_50 )
{
return ( ( ( ( V_50 + 0x8000L ) >> 16 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
}
int T_1 F_24 ( long V_50 )
{
return ( ( V_50 & 0xffff ) ^ 0x8000 ) - 0x8000 ;
}
void T_1 F_25 ( T_2 * * V_17 , unsigned int V_51 , long V_48 )
{
if ( ! F_19 ( V_48 ) ) {
F_26 ( V_17 , V_51 , F_21 ( V_48 ) ) ;
if ( F_22 ( V_48 ) )
F_27 ( V_17 , V_51 , V_51 , F_22 ( V_48 ) ) ;
if ( F_23 ( V_48 ) ) {
F_28 ( V_17 , V_51 , V_51 , 16 ) ;
F_27 ( V_17 , V_51 , V_51 , F_23 ( V_48 ) ) ;
F_28 ( V_17 , V_51 , V_51 , 16 ) ;
} else
F_29 ( V_17 , V_51 , V_51 , 0 ) ;
} else
F_26 ( V_17 , V_51 , F_23 ( V_48 ) ) ;
}
void T_1 F_30 ( T_2 * * V_17 , unsigned int V_51 , long V_48 )
{
F_25 ( V_17 , V_51 , V_48 ) ;
if ( F_24 ( V_48 ) ) {
if ( ! F_19 ( V_48 ) )
F_27 ( V_17 , V_51 , V_51 , F_24 ( V_48 ) ) ;
else
F_31 ( V_17 , V_51 , V_51 , F_24 ( V_48 ) ) ;
}
}
void T_1
F_32 ( struct V_52 * * V_53 , T_2 * V_48 , int V_49 )
{
( * V_53 ) -> V_48 = V_48 ;
( * V_53 ) -> type = V_54 ;
( * V_53 ) -> V_47 = V_49 ;
( * V_53 ) ++ ;
}
static inline void T_1
F_33 ( struct V_52 * V_53 , struct V_46 * V_47 )
{
long V_55 = ( long ) V_47 -> V_48 ;
long V_56 = ( long ) V_53 -> V_48 ;
switch ( V_53 -> type ) {
case V_54 :
* V_53 -> V_48 |= F_8 ( V_55 - ( V_56 + 4 ) ) ;
break;
default:
F_15 ( L_4 ,
V_53 -> type ) ;
}
}
void T_1
F_34 ( struct V_52 * V_53 , struct V_46 * V_47 )
{
struct V_46 * V_57 ;
for (; V_53 -> V_47 != V_58 ; V_53 ++ )
for ( V_57 = V_47 ; V_57 -> V_47 != V_58 ; V_57 ++ )
if ( V_53 -> V_47 == V_57 -> V_47 )
F_33 ( V_53 , V_57 ) ;
}
void T_1
F_35 ( struct V_52 * V_53 , T_2 * V_59 , T_2 * V_60 , long V_61 )
{
for (; V_53 -> V_47 != V_58 ; V_53 ++ )
if ( V_53 -> V_48 >= V_59 && V_53 -> V_48 < V_60 )
V_53 -> V_48 += V_61 ;
}
void T_1
F_36 ( struct V_46 * V_47 , T_2 * V_59 , T_2 * V_60 , long V_61 )
{
for (; V_47 -> V_47 != V_58 ; V_47 ++ )
if ( V_47 -> V_48 >= V_59 && V_47 -> V_48 < V_60 )
V_47 -> V_48 += V_61 ;
}
void T_1
F_37 ( struct V_52 * V_53 , struct V_46 * V_47 , T_2 * V_59 ,
T_2 * V_60 , T_2 * V_62 )
{
long V_61 = ( long ) ( V_62 - V_59 ) ;
memcpy ( V_62 , V_59 , ( V_60 - V_59 ) * sizeof( T_2 ) ) ;
F_35 ( V_53 , V_59 , V_60 , V_61 ) ;
F_36 ( V_47 , V_59 , V_60 , V_61 ) ;
}
int T_1 F_38 ( struct V_52 * V_53 , T_2 * V_48 )
{
for (; V_53 -> V_47 != V_58 ; V_53 ++ ) {
if ( V_53 -> V_48 == V_48
&& ( V_53 -> type == V_54
|| V_53 -> type == V_63 ) )
return 1 ;
}
return 0 ;
}
void T_1
F_39 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_66 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_40 ( V_64 , V_66 , 0 ) ;
}
void T_1
F_41 ( T_2 * * V_64 , struct V_52 * * V_65 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_42 ( V_64 , 0 ) ;
}
void T_1
F_43 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_66 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_44 ( V_64 , V_66 , 0 ) ;
}
void T_1
F_45 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_66 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_46 ( V_64 , V_66 , 0 ) ;
}
void T_1
F_47 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_67 ,
unsigned int V_68 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_48 ( V_64 , V_67 , V_68 , 0 ) ;
}
void T_1
F_49 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_66 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_50 ( V_64 , V_66 , 0 ) ;
}
void T_1
F_51 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_66 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_52 ( V_64 , V_66 , 0 ) ;
}
void T_1
F_53 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_66 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_54 ( V_64 , V_66 , 0 ) ;
}
void T_1
F_55 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_66 ,
unsigned int V_69 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_56 ( V_64 , V_66 , V_69 , 0 ) ;
}
void T_1
F_57 ( T_2 * * V_64 , struct V_52 * * V_65 , unsigned int V_66 ,
unsigned int V_69 , int V_49 )
{
F_32 ( V_65 , * V_64 , V_49 ) ;
F_58 ( V_64 , V_66 , V_69 , 0 ) ;
}
