static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
F_2 ( V_4 , V_2 -> V_5 + V_7 ) ;
V_2 -> V_8 [ V_3 ] = V_4 ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_9 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_11 & ( 1 << V_3 ) ) {
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
V_2 -> V_8 [ V_3 ] = F_7 ( V_2 -> V_5 + V_7 ) ;
}
return V_2 -> V_8 [ V_3 ] ;
}
static inline T_1 F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_9 ;
T_1 V_12 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
V_12 = F_6 ( V_2 , V_3 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_13 = 100000 ;
while ( V_13 -- > 0 ) {
if ( ! ( F_10 ( V_2 -> V_5 + V_14 ) & 1 ) )
return 0 ;
F_11 () ;
}
F_12 ( L_1 ) ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_13 = 100000 ;
while ( V_13 -- > 0 ) {
if ( ! ( F_10 ( V_2 -> V_5 + V_14 ) & 1 ) )
return 0 ;
}
F_12 ( L_1 ) ;
return 1 ;
}
static void F_14 ( struct V_15 * V_16 , unsigned short V_3 , unsigned short V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
#ifndef F_15
unsigned long V_9 ;
#endif
F_9 ( V_2 ) ;
#ifndef F_15
F_4 ( & V_2 -> V_19 , V_9 ) ;
#endif
F_2 ( V_17 , V_2 -> V_5 + V_20 ) ;
F_16 ( V_3 , V_2 -> V_5 + V_14 ) ;
#ifndef F_15
F_5 ( & V_2 -> V_19 , V_9 ) ;
#endif
}
static unsigned short F_17 ( struct V_15 * V_16 , unsigned short V_3 )
{
T_1 V_4 = 0 ;
struct V_1 * V_2 = V_16 -> V_18 ;
#ifndef F_15
unsigned long V_9 ;
#endif
F_9 ( V_2 ) ;
#ifndef F_15
F_4 ( & V_2 -> V_19 , V_9 ) ;
#endif
F_16 ( V_3 | 0x80 , V_2 -> V_5 + V_14 ) ;
if ( ! F_13 ( V_2 ) ) {
V_4 = F_7 ( V_2 -> V_5 + V_20 ) ;
}
#ifndef F_15
F_5 ( & V_2 -> V_19 , V_9 ) ;
#endif
return V_4 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_21 )
{
int V_22 ;
F_1 ( V_2 , V_23 , V_21 ) ;
for ( V_22 = 0 ; V_22 < 1000 ; V_22 ++ )
if ( F_6 ( V_2 , V_23 ) == V_21 )
return;
F_12 ( L_2 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_4 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 1000 ; V_22 ++ ) {
if ( F_6 ( V_2 , V_24 ) == V_4 )
return;
F_1 ( V_2 , V_24 , V_4 ) ;
}
F_12 ( L_3 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_25 , T_2 V_3 , T_1 V_4 )
{
if ( F_21 ( V_25 >= V_26 ) )
return;
#ifdef F_22
V_2 -> V_27 [ V_25 ] [ V_3 ] = V_4 ;
#endif
V_3 |= ( V_25 << 4 ) ;
F_18 ( V_2 , V_3 ) ;
F_19 ( V_2 , V_4 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_25 , T_2 V_3 , T_1 V_4 )
{
unsigned long V_9 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_20 ( V_2 , V_25 , V_3 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_25 , T_2 V_3 )
{
if ( F_21 ( V_25 >= V_26 ) )
return 0 ;
V_3 |= ( V_25 << 4 ) ;
F_18 ( V_2 , V_3 ) ;
return F_6 ( V_2 , V_24 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_25 , T_2 V_3 )
{
unsigned long V_9 ;
T_1 V_28 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
V_28 = F_24 ( V_2 , V_25 , V_3 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
return V_28 ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_29 )
{
unsigned long V_9 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( V_3 , V_2 -> V_5 + V_30 ) ;
F_2 ( V_29 , V_2 -> V_5 + V_31 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_9 ;
T_1 V_29 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( V_3 , V_2 -> V_5 + V_30 ) ;
V_29 = F_7 ( V_2 -> V_5 + V_31 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
return V_29 ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_6 ( V_2 , 0x11 ) ;
V_3 &= ~ V_32 ;
F_1 ( V_2 , 0x11 , V_3 ) ;
V_3 = F_6 ( V_2 , 0x17 ) ;
V_3 &= ~ V_33 ;
F_1 ( V_2 , 0x17 , V_3 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_34 ;
int V_35 ;
for ( V_34 = 5 ; V_34 < 12 ; V_34 ++ )
if ( V_2 -> V_36 > ( V_37 >> ( V_34 + 9 ) ) )
break;
V_35 = 1 ;
while ( ( V_34 > 5 ) && ( V_35 < 32 ) ) {
V_34 -- ;
V_35 <<= 1 ;
}
V_35 >>= 1 ;
for (; V_35 < 31 ; V_35 ++ )
if ( V_2 -> V_36 >
( ( V_37 >> ( V_34 + 9 ) ) / ( V_35 + 1 ) ) ) break;
if ( V_35 == 0 ) {
V_35 ++ ;
if ( V_34 > 5 )
V_34 -- ;
} else if ( V_35 > 1 )
V_35 -- ;
F_1 ( V_2 , 6 , 0x9000 | ( V_34 << 5 ) | V_35 ) ;
F_1 ( V_2 , 0x11 , F_6 ( V_2 , 0x11 ) | 1 ) ;
F_1 ( V_2 , 0x17 , F_6 ( V_2 , 0x17 ) | 1 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_38 )
{
V_2 -> V_39 ++ ;
if ( V_2 -> V_39 == 1 ) {
V_2 -> V_36 = V_38 ;
F_29 ( V_2 ) ;
} else if ( V_2 -> V_36 < V_38 ) {
F_28 ( V_2 ) ;
V_2 -> V_36 = V_38 ;
F_29 ( V_2 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_39 -- ;
if ( V_2 -> V_39 <= 0 )
F_28 ( V_2 ) ;
else if ( V_2 -> V_36 > V_40 ) {
int V_41 = V_40 ;
struct V_42 * V_43 ;
F_32 (es, &chip->substream_list, list) {
if ( V_41 < V_43 -> V_36 )
V_41 = V_43 -> V_36 ;
}
if ( V_41 != V_2 -> V_36 ) {
F_28 ( V_2 ) ;
V_2 -> V_36 = V_41 ;
F_29 ( V_2 ) ;
}
}
}
static int
F_33 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_38 = V_45 -> V_46 * 4 ;
if ( V_43 -> V_47 & V_48 )
V_38 <<= 1 ;
if ( V_43 -> V_47 & V_49 )
V_38 <<= 1 ;
V_38 /= V_43 -> V_50 ;
if ( V_38 < V_40 )
V_38 = V_40 ;
else if ( V_38 > V_51 )
V_38 = V_51 ;
return V_38 ;
}
static T_3 F_34 ( struct V_1 * V_2 , T_3 V_38 )
{
T_3 V_46 = ( V_38 << 16 ) / V_2 -> clock ;
#if 0
if (rate > 0x10000)
rate = 0x10000;
#endif
return V_46 ;
}
static inline unsigned int
F_35 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned int V_52 ;
V_52 = F_25 ( V_2 , V_43 -> V_53 [ 0 ] , 5 ) ;
V_52 -= V_43 -> V_54 [ 0 ] ;
return ( V_52 & 0xFFFE ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_53 , int V_38 )
{
F_23 ( V_2 , V_53 , 2 ,
( F_25 ( V_2 , V_53 , 2 ) & 0x00FF ) |
( ( V_38 & 0xff ) << 8 ) | 0x10 ) ;
F_23 ( V_2 , V_53 , 3 , V_38 >> 8 ) ;
}
static inline void F_37 ( struct V_1 * V_55 , int V_53 , int V_56 )
{
F_20 ( V_55 , V_53 , 0 ,
( F_24 ( V_55 , V_53 , 0 ) & 0xff0f ) |
( V_56 << 4 ) ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
F_39 ( & V_2 -> V_10 ) ;
F_20 ( V_2 , V_43 -> V_53 [ 0 ] , 5 , V_43 -> V_54 [ 0 ] ) ;
F_37 ( V_2 , V_43 -> V_53 [ 0 ] , V_43 -> V_57 [ 0 ] ) ;
if ( V_43 -> V_56 == V_58 ) {
F_20 ( V_2 , V_43 -> V_53 [ 2 ] , 5 , V_43 -> V_54 [ 2 ] ) ;
F_37 ( V_2 , V_43 -> V_53 [ 2 ] , V_43 -> V_57 [ 2 ] ) ;
}
if ( V_43 -> V_47 & V_48 ) {
F_20 ( V_2 , V_43 -> V_53 [ 1 ] , 5 , V_43 -> V_54 [ 1 ] ) ;
F_37 ( V_2 , V_43 -> V_53 [ 1 ] , V_43 -> V_57 [ 1 ] ) ;
if ( V_43 -> V_56 == V_58 ) {
F_20 ( V_2 , V_43 -> V_53 [ 3 ] , 5 , V_43 -> V_54 [ 3 ] ) ;
F_37 ( V_2 , V_43 -> V_53 [ 3 ] , V_43 -> V_57 [ 3 ] ) ;
}
}
F_40 ( & V_2 -> V_10 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
F_39 ( & V_2 -> V_10 ) ;
F_37 ( V_2 , V_43 -> V_53 [ 0 ] , 0 ) ;
F_37 ( V_2 , V_43 -> V_53 [ 1 ] , 0 ) ;
if ( V_43 -> V_56 == V_58 ) {
F_37 ( V_2 , V_43 -> V_53 [ 2 ] , 0 ) ;
F_37 ( V_2 , V_43 -> V_53 [ 3 ] , 0 ) ;
}
F_40 ( & V_2 -> V_10 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_42 * V_43 ,
int V_25 , T_3 V_59 , int V_60 )
{
T_3 V_61 = ( V_59 - 0x10 ) & 0xFFF8 ;
if ( ! V_60 ) {
if ( ! ( V_43 -> V_47 & V_49 ) )
V_61 |= 4 ;
if ( V_43 -> V_47 & V_48 )
V_61 |= 2 ;
}
F_26 ( V_2 , V_43 -> V_53 [ V_25 ] << 3 , V_61 ) ;
#ifdef F_22
V_43 -> V_62 [ V_25 ] = V_61 ;
#endif
}
static void F_43 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_44 * V_45 )
{
T_3 V_63 ;
int V_64 = 0 ;
int V_25 , V_53 ;
int V_22 , V_65 ;
unsigned long V_9 ;
T_3 V_38 ;
V_65 = V_43 -> V_66 >> V_43 -> V_67 ;
if ( V_43 -> V_47 & V_48 )
V_64 ++ ;
for ( V_25 = 0 ; V_25 <= V_64 ; V_25 ++ ) {
V_53 = V_43 -> V_53 [ V_25 ] ;
F_42 ( V_2 , V_43 , V_25 , V_43 -> V_68 -> V_69 . V_59 , 0 ) ;
V_63 = V_43 -> V_68 -> V_69 . V_59 ;
V_63 -= V_2 -> V_70 . V_59 ;
V_63 >>= 1 ;
V_63 |= 0x00400000 ;
if ( V_43 -> V_47 & V_48 ) {
if ( V_25 )
V_63 |= 0x00800000 ;
if ( V_43 -> V_47 & V_49 )
V_63 >>= 1 ;
}
V_43 -> V_54 [ V_25 ] = V_63 & 0xFFFF ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ )
F_23 ( V_2 , V_53 , V_22 , 0x0000 ) ;
F_23 ( V_2 , V_53 , 4 , ( ( V_63 >> 16 ) & 0xFF ) << 8 ) ;
F_23 ( V_2 , V_53 , 5 , V_63 & 0xFFFF ) ;
F_23 ( V_2 , V_53 , 6 , ( V_63 + V_65 ) & 0xFFFF ) ;
F_23 ( V_2 , V_53 , 7 , V_65 ) ;
F_23 ( V_2 , V_53 , 8 , 0x0000 ) ;
F_23 ( V_2 , V_53 , 9 , 0xD000 ) ;
F_23 ( V_2 , V_53 , 11 , 0x0000 ) ;
F_23 ( V_2 , V_53 , 0 , 0x400F ) ;
if ( V_43 -> V_47 & V_49 )
V_43 -> V_57 [ V_25 ] = V_71 ;
else
V_43 -> V_57 [ V_25 ] = V_72 ;
if ( V_43 -> V_47 & V_48 ) {
F_23 ( V_2 , V_53 , 10 ,
0x8F00 | ( V_25 ? 0 : 0x10 ) ) ;
V_43 -> V_57 [ V_25 ] += 1 ;
} else
F_23 ( V_2 , V_53 , 10 , 0x8F08 ) ;
}
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_73 ) | V_74 , V_2 -> V_5 + V_73 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_38 = V_45 -> V_46 ;
if ( V_38 > 48000 )
V_38 = 48000 ;
if ( V_38 < 4000 )
V_38 = 4000 ;
if ( ! ( V_43 -> V_47 & V_49 ) && ! ( V_43 -> V_47 & V_48 ) )
V_38 >>= 1 ;
V_38 = F_34 ( V_2 , V_38 ) ;
F_36 ( V_2 , V_43 -> V_53 [ 0 ] , V_38 ) ;
F_36 ( V_2 , V_43 -> V_53 [ 1 ] , V_38 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_42 * V_43 , int V_25 ,
unsigned int V_63 , unsigned int V_75 ,
int V_56 , int V_76 )
{
int V_22 , V_53 = V_43 -> V_53 [ V_25 ] ;
V_43 -> V_57 [ V_25 ] = V_56 ;
F_42 ( V_2 , V_43 , V_25 , V_63 , 1 ) ;
V_63 -= V_2 -> V_70 . V_59 ;
V_63 >>= 1 ;
V_43 -> V_54 [ V_25 ] = V_63 & 0xFFFF ;
V_63 |= 0x00400000 ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ )
F_23 ( V_2 , V_53 , V_22 , 0x0000 ) ;
F_23 ( V_2 , V_53 , 2 , 0x8 ) ;
F_23 ( V_2 , V_53 , 4 , ( ( V_63 >> 16 ) & 0xFF ) << 8 ) ;
F_23 ( V_2 , V_53 , 5 , V_63 & 0xFFFF ) ;
F_23 ( V_2 , V_53 , 6 , ( V_63 + V_75 ) & 0xFFFF ) ;
F_23 ( V_2 , V_53 , 7 , V_75 ) ;
F_23 ( V_2 , V_53 , 8 , 0x00F0 ) ;
F_23 ( V_2 , V_53 , 9 , 0x0000 ) ;
F_23 ( V_2 , V_53 , 10 , 0x8F08 ) ;
F_23 ( V_2 , V_53 , 11 , V_76 ) ;
F_23 ( V_2 , V_53 , 0 , 0x400F ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_65 ;
T_3 V_38 ;
unsigned long V_9 ;
V_65 = V_43 -> V_66 >> V_43 -> V_67 ;
F_44 ( V_2 , V_43 , 2 ,
V_43 -> V_77 -> V_69 . V_59 , V_78 / 4 ,
V_79 , 0x14 ) ;
F_44 ( V_2 , V_43 , 0 , V_43 -> V_68 -> V_69 . V_59 , V_65 ,
V_80 , V_43 -> V_53 [ 2 ] ) ;
if ( V_43 -> V_47 & V_48 ) {
F_44 ( V_2 , V_43 , 3 ,
V_43 -> V_77 -> V_69 . V_59 + V_78 / 2 ,
V_78 / 4 ,
V_79 , 0x15 ) ;
F_44 ( V_2 , V_43 , 1 ,
V_43 -> V_68 -> V_69 . V_59 + V_65 * 2 , V_65 ,
V_80 , V_43 -> V_53 [ 3 ] ) ;
}
V_38 = V_45 -> V_46 ;
if ( V_38 > 47999 )
V_38 = 47999 ;
if ( V_38 < 4000 )
V_38 = 4000 ;
V_38 = F_34 ( V_2 , V_38 ) ;
F_36 ( V_2 , V_43 -> V_53 [ 0 ] , V_38 ) ;
F_36 ( V_2 , V_43 -> V_53 [ 1 ] , V_38 ) ;
V_38 = 0x10000 ;
F_36 ( V_2 , V_43 -> V_53 [ 2 ] , V_38 ) ;
F_36 ( V_2 , V_43 -> V_53 [ 3 ] , V_38 ) ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_73 ) | V_74 , V_2 -> V_5 + V_73 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static int F_46 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_44 * V_45 = V_82 -> V_45 ;
struct V_42 * V_43 = V_45 -> V_18 ;
V_43 -> V_66 = F_48 ( V_82 ) ;
V_43 -> V_50 = F_49 ( V_82 ) ;
V_43 -> V_67 = 1 ;
V_43 -> V_47 = 0 ;
if ( F_50 ( V_45 -> V_83 ) == 16 )
V_43 -> V_47 |= V_49 ;
if ( V_45 -> V_84 > 1 ) {
V_43 -> V_47 |= V_48 ;
if ( V_43 -> V_47 & V_49 )
V_43 -> V_67 ++ ;
}
V_43 -> V_36 = F_33 ( V_2 , V_43 , V_45 ) ;
switch ( V_43 -> V_56 ) {
case V_85 :
F_43 ( V_2 , V_43 , V_45 ) ;
break;
case V_58 :
F_45 ( V_2 , V_43 , V_45 ) ;
break;
}
return 0 ;
}
static int F_51 ( struct V_81 * V_82 , int V_86 )
{
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_42 * V_43 = V_82 -> V_45 -> V_18 ;
F_39 ( & V_2 -> V_87 ) ;
switch ( V_86 ) {
case V_88 :
case V_89 :
if ( V_43 -> V_90 )
break;
F_30 ( V_2 , V_43 -> V_36 ) ;
V_43 -> V_91 = 0 ;
V_43 -> V_92 = 0 ;
F_38 ( V_2 , V_43 ) ;
V_43 -> V_90 = 1 ;
break;
case V_93 :
case V_94 :
if ( ! V_43 -> V_90 )
break;
F_41 ( V_2 , V_43 ) ;
V_43 -> V_90 = 0 ;
F_31 ( V_2 ) ;
break;
}
F_40 ( & V_2 -> V_87 ) ;
return 0 ;
}
static T_4 F_52 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_42 * V_43 = V_82 -> V_45 -> V_18 ;
unsigned int V_95 ;
V_95 = F_35 ( V_2 , V_43 ) << V_43 -> V_67 ;
return F_53 ( V_82 -> V_45 , V_95 % V_43 -> V_66 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_96 = 0 ;
struct V_97 * V_69 ;
F_55 ( & V_2 -> V_98 ) ;
F_32 (buf, &chip->buf_list, list) {
if ( V_69 -> V_99 && V_69 -> V_69 . V_100 > V_96 )
V_96 = V_69 -> V_69 . V_100 ;
}
F_56 ( & V_2 -> V_98 ) ;
if ( V_96 >= 128 * 1024 )
V_96 = 127 * 1024 ;
return V_96 ;
}
static struct V_97 * F_57 ( struct V_1 * V_2 , int V_65 )
{
struct V_97 * V_69 ;
V_65 = F_58 ( V_65 , V_101 ) ;
F_55 ( & V_2 -> V_98 ) ;
F_32 (buf, &chip->buf_list, list) {
if ( V_69 -> V_99 && V_69 -> V_69 . V_100 >= V_65 )
goto V_102;
}
F_56 ( & V_2 -> V_98 ) ;
return NULL ;
V_102:
if ( V_69 -> V_69 . V_100 > V_65 ) {
struct V_97 * V_103 = F_59 ( sizeof( * V_103 ) , V_104 ) ;
if ( V_103 == NULL ) {
F_56 ( & V_2 -> V_98 ) ;
return NULL ;
}
V_103 -> V_69 = V_69 -> V_69 ;
V_103 -> V_69 . V_100 -= V_65 ;
V_103 -> V_69 . V_105 += V_65 ;
V_103 -> V_69 . V_59 += V_65 ;
V_103 -> V_99 = 1 ;
V_69 -> V_69 . V_100 = V_65 ;
F_60 ( & V_103 -> V_106 , & V_69 -> V_106 ) ;
}
V_69 -> V_99 = 0 ;
F_56 ( & V_2 -> V_98 ) ;
return V_69 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_97 * V_69 )
{
struct V_97 * V_103 ;
F_55 ( & V_2 -> V_98 ) ;
V_69 -> V_99 = 1 ;
if ( V_69 -> V_106 . V_107 != & V_2 -> V_108 ) {
V_103 = F_62 ( V_69 -> V_106 . V_107 , struct V_97 , V_106 ) ;
if ( V_103 -> V_99 ) {
V_103 -> V_69 . V_100 += V_69 -> V_69 . V_100 ;
F_63 ( & V_69 -> V_106 ) ;
F_64 ( V_69 ) ;
V_69 = V_103 ;
}
}
if ( V_69 -> V_106 . V_109 != & V_2 -> V_108 ) {
V_103 = F_62 ( V_69 -> V_106 . V_109 , struct V_97 , V_106 ) ;
if ( V_103 -> V_99 ) {
V_69 -> V_69 . V_100 += V_103 -> V_69 . V_100 ;
F_63 ( & V_103 -> V_106 ) ;
F_64 ( V_103 ) ;
}
}
F_56 ( & V_2 -> V_98 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_110 * V_111 ;
if ( ! V_2 -> V_70 . V_105 )
return;
F_66 ( & V_2 -> V_70 , F_67 ( V_2 -> V_112 ) ) ;
while ( ( V_111 = V_2 -> V_108 . V_109 ) != & V_2 -> V_108 ) {
struct V_97 * V_103 = F_62 ( V_111 , struct V_97 , V_106 ) ;
F_63 ( V_111 ) ;
F_64 ( V_103 ) ;
}
}
static int T_5
F_68 ( struct V_1 * V_2 )
{
int V_113 ;
struct V_97 * V_103 ;
V_2 -> V_70 . V_114 . type = V_115 ;
V_2 -> V_70 . V_114 . V_114 = F_69 ( V_2 -> V_112 ) ;
if ( ! F_70 ( & V_2 -> V_70 , F_67 ( V_2 -> V_112 ) ) ) {
V_113 = F_71 ( V_115 ,
F_69 ( V_2 -> V_112 ) ,
V_2 -> V_116 , & V_2 -> V_70 ) ;
if ( V_113 < 0 || ! V_2 -> V_70 . V_105 ) {
F_72 ( V_117 L_4 ,
V_2 -> V_116 ) ;
return - V_118 ;
}
if ( ( V_2 -> V_70 . V_59 + V_2 -> V_70 . V_100 - 1 ) & ~ ( ( 1 << 28 ) - 1 ) ) {
F_73 ( & V_2 -> V_70 ) ;
F_72 ( V_117 L_5 ) ;
return - V_118 ;
}
}
F_74 ( & V_2 -> V_108 ) ;
V_103 = F_59 ( sizeof( * V_103 ) , V_104 ) ;
if ( V_103 == NULL ) {
F_65 ( V_2 ) ;
return - V_118 ;
}
memset ( V_2 -> V_70 . V_105 , 0 , V_101 ) ;
V_103 -> V_69 = V_2 -> V_70 ;
V_103 -> V_69 . V_105 += V_101 ;
V_103 -> V_69 . V_59 += V_101 ;
V_103 -> V_69 . V_100 -= V_101 ;
V_103 -> V_99 = 1 ;
F_60 ( & V_103 -> V_106 , & V_2 -> V_108 ) ;
return 0 ;
}
static int F_75 ( struct V_81 * V_82 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_44 * V_45 = V_82 -> V_45 ;
struct V_42 * V_121 = V_45 -> V_18 ;
int V_65 = F_76 ( V_120 ) ;
if ( V_121 -> V_68 ) {
if ( V_121 -> V_68 -> V_69 . V_100 >= V_65 ) {
V_45 -> V_122 = V_65 ;
return 0 ;
}
F_61 ( V_2 , V_121 -> V_68 ) ;
}
V_121 -> V_68 = F_57 ( V_2 , V_65 ) ;
if ( V_121 -> V_68 == NULL ) {
return - V_118 ;
}
F_77 ( V_82 , & V_121 -> V_68 -> V_69 ) ;
return 1 ;
}
static int F_78 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_44 * V_45 = V_82 -> V_45 ;
struct V_42 * V_121 ;
if ( V_45 -> V_18 == NULL )
return 0 ;
V_121 = V_45 -> V_18 ;
if ( V_121 -> V_68 ) {
F_61 ( V_2 , V_121 -> V_68 ) ;
V_121 -> V_68 = NULL ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , int type )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_26 ; V_53 += 2 ) {
if ( V_2 -> V_53 [ V_53 ] == V_123 &&
V_2 -> V_53 [ V_53 + 1 ] == V_123 ) {
V_2 -> V_53 [ V_53 ] = V_2 -> V_53 [ V_53 + 1 ] = type ;
return V_53 ;
}
}
return - V_124 ;
}
static void F_80 ( struct V_1 * V_2 , int V_53 )
{
V_2 -> V_53 [ V_53 ] = V_2 -> V_53 [ V_53 + 1 ] = V_123 ;
}
static int F_81 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_44 * V_45 = V_82 -> V_45 ;
struct V_42 * V_43 ;
int V_125 ;
V_125 = F_79 ( V_2 , V_126 ) ;
if ( V_125 < 0 )
return V_125 ;
V_43 = F_82 ( sizeof( * V_43 ) , V_104 ) ;
if ( ! V_43 ) {
F_80 ( V_2 , V_125 ) ;
return - V_118 ;
}
V_43 -> V_53 [ 0 ] = V_125 ;
V_43 -> V_53 [ 1 ] = V_125 + 1 ;
V_43 -> V_57 [ 0 ] = 0 ;
V_43 -> V_57 [ 1 ] = 0 ;
V_43 -> V_90 = 0 ;
V_43 -> V_82 = V_82 ;
V_43 -> V_56 = V_85 ;
V_45 -> V_18 = V_43 ;
V_45 -> V_127 = V_128 ;
V_45 -> V_127 . V_129 = V_45 -> V_127 . V_130 =
F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_87 ) ;
F_60 ( & V_43 -> V_106 , & V_2 -> V_131 ) ;
F_84 ( & V_2 -> V_87 ) ;
return 0 ;
}
static int F_85 ( struct V_81 * V_82 )
{
struct V_44 * V_45 = V_82 -> V_45 ;
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_42 * V_43 ;
int V_125 , V_132 ;
V_125 = F_79 ( V_2 , V_133 ) ;
if ( V_125 < 0 )
return V_125 ;
V_132 = F_79 ( V_2 , V_134 ) ;
if ( V_132 < 0 ) {
F_80 ( V_2 , V_125 ) ;
return V_132 ;
}
V_43 = F_82 ( sizeof( * V_43 ) , V_104 ) ;
if ( ! V_43 ) {
F_80 ( V_2 , V_125 ) ;
F_80 ( V_2 , V_132 ) ;
return - V_118 ;
}
V_43 -> V_53 [ 0 ] = V_125 ;
V_43 -> V_53 [ 1 ] = V_125 + 1 ;
V_43 -> V_53 [ 2 ] = V_132 ;
V_43 -> V_53 [ 3 ] = V_132 + 1 ;
V_43 -> V_57 [ 0 ] = 0 ;
V_43 -> V_57 [ 1 ] = 0 ;
V_43 -> V_57 [ 2 ] = 0 ;
V_43 -> V_57 [ 3 ] = 0 ;
V_43 -> V_90 = 0 ;
V_43 -> V_82 = V_82 ;
V_43 -> V_56 = V_58 ;
if ( ( V_43 -> V_77 = F_57 ( V_2 , V_78 ) ) == NULL ) {
F_80 ( V_2 , V_125 ) ;
F_80 ( V_2 , V_132 ) ;
F_64 ( V_43 ) ;
return - V_118 ;
}
memset ( V_43 -> V_77 -> V_69 . V_105 , 0 , V_78 ) ;
V_45 -> V_18 = V_43 ;
V_45 -> V_127 = V_135 ;
V_45 -> V_127 . V_129 = V_45 -> V_127 . V_130 =
F_54 ( V_2 ) - 1024 ;
F_86 ( V_45 , 0 , V_136 ) ;
F_83 ( & V_2 -> V_87 ) ;
F_60 ( & V_43 -> V_106 , & V_2 -> V_131 ) ;
F_84 ( & V_2 -> V_87 ) ;
return 0 ;
}
static int F_87 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_42 * V_43 ;
if ( V_82 -> V_45 -> V_18 == NULL )
return 0 ;
V_43 = V_82 -> V_45 -> V_18 ;
F_83 ( & V_2 -> V_87 ) ;
F_63 ( & V_43 -> V_106 ) ;
F_84 ( & V_2 -> V_87 ) ;
F_80 ( V_2 , V_43 -> V_53 [ 0 ] ) ;
F_64 ( V_43 ) ;
return 0 ;
}
static int F_88 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_47 ( V_82 ) ;
struct V_42 * V_43 ;
if ( V_82 -> V_45 -> V_18 == NULL )
return 0 ;
V_43 = V_82 -> V_45 -> V_18 ;
F_83 ( & V_2 -> V_87 ) ;
F_63 ( & V_43 -> V_106 ) ;
F_84 ( & V_2 -> V_87 ) ;
F_61 ( V_2 , V_43 -> V_77 ) ;
F_80 ( V_2 , V_43 -> V_53 [ 0 ] ) ;
F_80 ( V_2 , V_43 -> V_53 [ 2 ] ) ;
F_64 ( V_43 ) ;
return 0 ;
}
static void T_5 F_89 ( struct V_1 * V_2 )
{
int V_22 , V_53 ;
unsigned int V_63 , V_52 , V_137 ;
struct V_97 * V_68 ;
struct V_138 V_139 , V_140 ;
if ( V_2 -> clock == 0 )
V_2 -> clock = 48000 ;
if ( ( V_53 = F_79 ( V_2 , V_126 ) ) < 0 ) {
F_72 ( V_117 L_6 ) ;
return;
}
if ( ( V_68 = F_57 ( V_2 , V_141 ) ) == NULL ) {
F_72 ( V_117 L_7 , V_2 -> clock ) ;
F_80 ( V_2 , V_53 ) ;
return;
}
memset ( V_68 -> V_69 . V_105 , 0 , V_141 ) ;
F_26 ( V_2 , V_53 << 3 , ( V_68 -> V_69 . V_59 - 0x10 ) & 0xfff8 ) ;
V_63 = ( unsigned int ) ( ( V_68 -> V_69 . V_59 - V_2 -> V_70 . V_59 ) >> 1 ) ;
V_63 |= 0x00400000 ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ )
F_23 ( V_2 , V_53 , V_22 , 0x0000 ) ;
F_23 ( V_2 , V_53 , 0 , 0x400f ) ;
F_23 ( V_2 , V_53 , 4 , ( ( V_63 >> 16 ) & 0xff ) << 8 ) ;
F_23 ( V_2 , V_53 , 5 , V_63 & 0xffff ) ;
F_23 ( V_2 , V_53 , 6 , ( V_63 + V_141 / 2 ) & 0xffff ) ;
F_23 ( V_2 , V_53 , 7 , V_141 / 2 ) ;
F_23 ( V_2 , V_53 , 8 , 0x0000 ) ;
F_23 ( V_2 , V_53 , 9 , 0xD000 ) ;
F_23 ( V_2 , V_53 , 10 , 0x8F08 ) ;
F_23 ( V_2 , V_53 , 11 , 0x0000 ) ;
F_83 ( & V_2 -> V_10 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_73 ) | V_74 , V_2 -> V_5 + V_73 ) ;
F_84 ( & V_2 -> V_10 ) ;
F_36 ( V_2 , V_53 , ( ( unsigned int ) 48000 << 16 ) / V_2 -> clock ) ;
V_2 -> V_142 = 1 ;
V_2 -> V_143 = V_53 ;
F_83 ( & V_2 -> V_10 ) ;
F_30 ( V_2 , V_40 ) ;
F_20 ( V_2 , V_53 , 5 , V_63 & 0xffff ) ;
F_37 ( V_2 , V_53 , V_71 ) ;
F_90 ( & V_139 ) ;
F_84 ( & V_2 -> V_10 ) ;
F_91 ( 50 ) ;
F_83 ( & V_2 -> V_10 ) ;
V_52 = F_24 ( V_2 , V_53 , 5 ) ;
F_90 ( & V_140 ) ;
F_37 ( V_2 , V_53 , 0 ) ;
F_31 ( V_2 ) ;
V_2 -> V_142 = 0 ;
F_84 ( & V_2 -> V_10 ) ;
V_52 -= ( V_63 & 0xffff ) ;
V_52 &= 0xfffe ;
V_52 += V_2 -> V_144 * ( V_141 / 2 ) ;
V_137 = V_140 . V_145 - V_139 . V_145 ;
V_137 *= 1000000 ;
if ( V_140 . V_146 < V_139 . V_146 )
V_137 -= V_139 . V_146 - V_140 . V_146 ;
else
V_137 += V_140 . V_146 - V_139 . V_146 ;
if ( V_137 == 0 ) {
F_72 ( V_117 L_8 ) ;
} else {
V_52 *= 1000 ;
V_52 = ( V_52 / V_137 ) * 1000 + ( ( V_52 % V_137 ) * 1000 ) / V_137 ;
if ( V_52 < 47500 || V_52 > 48500 ) {
if ( V_52 >= 40000 && V_52 <= 50000 )
V_2 -> clock = ( V_2 -> clock * V_52 ) / 48000 ;
}
F_92 ( V_147 L_9 , V_2 -> clock ) ;
}
F_61 ( V_2 , V_68 ) ;
F_80 ( V_2 , V_53 ) ;
}
static void F_93 ( struct V_148 * V_149 )
{
struct V_1 * V_55 = V_149 -> V_18 ;
F_65 ( V_55 ) ;
V_55 -> V_149 = NULL ;
}
static int T_5
F_94 ( struct V_1 * V_2 , int V_150 )
{
struct V_148 * V_149 ;
int V_113 ;
if ( ( V_113 = F_68 ( V_2 ) ) < 0 )
return V_113 ;
F_26 ( V_2 , 0x01FC , V_2 -> V_70 . V_59 >> 12 ) ;
F_26 ( V_2 , 0x01FD , V_2 -> V_70 . V_59 >> 12 ) ;
F_26 ( V_2 , 0x01FE , V_2 -> V_70 . V_59 >> 12 ) ;
F_26 ( V_2 , 0x01FF , V_2 -> V_70 . V_59 >> 12 ) ;
if ( ( V_113 = F_95 ( V_2 -> V_151 , L_10 , V_150 ,
V_2 -> V_152 ,
V_2 -> V_153 , & V_149 ) ) < 0 )
return V_113 ;
V_149 -> V_18 = V_2 ;
V_149 -> V_154 = F_93 ;
F_96 ( V_149 , V_155 , & V_156 ) ;
F_96 ( V_149 , V_157 , & V_158 ) ;
V_149 -> V_159 = 0 ;
strcpy ( V_149 -> V_160 , L_10 ) ;
V_2 -> V_149 = V_149 ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned int V_161 ;
unsigned int V_162 ;
unsigned int V_163 ;
V_161 = F_24 ( V_2 , 0 , 5 ) ;
V_162 = F_24 ( V_2 , 1 , 5 ) ;
V_163 = ( V_161 > V_162 ? V_161 - V_162 : V_162 - V_161 ) ;
if ( V_163 > 1 )
F_1 ( V_2 , V_24 , V_161 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned int V_92 ;
unsigned int V_163 ;
struct V_81 * V_164 = V_43 -> V_82 ;
if ( V_164 == NULL || ! V_43 -> V_90 )
return;
V_92 = F_35 ( V_2 , V_43 ) << V_43 -> V_67 ;
V_92 %= V_43 -> V_66 ;
V_163 = ( V_43 -> V_66 + V_92 - V_43 -> V_92 ) % V_43 -> V_66 ;
V_43 -> V_92 = V_92 ;
V_43 -> V_91 += V_163 ;
if ( V_43 -> V_91 > V_43 -> V_50 ) {
F_40 ( & V_2 -> V_87 ) ;
F_99 ( V_164 ) ;
F_39 ( & V_2 -> V_87 ) ;
V_43 -> V_91 %= V_43 -> V_50 ;
}
}
static void F_100 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
int V_165 , V_17 ;
#ifndef F_15
unsigned long V_9 ;
#endif
V_165 = F_10 ( V_2 -> V_5 + 0x1c ) & 0xee ;
F_16 ( 0x88 , V_2 -> V_5 + 0x1c ) ;
F_16 ( 0x88 , V_2 -> V_5 + 0x1d ) ;
F_16 ( 0x88 , V_2 -> V_5 + 0x1e ) ;
F_16 ( 0x88 , V_2 -> V_5 + 0x1f ) ;
if ( V_2 -> V_166 )
return;
#ifndef F_15
if ( ! V_2 -> V_167 || ! V_2 -> V_168 )
return;
F_4 ( & V_2 -> V_19 , V_9 ) ;
V_17 = V_2 -> V_16 -> V_169 [ V_170 ] ;
switch ( V_165 ) {
case 0x88 :
V_17 ^= 0x8000 ;
V_2 -> V_16 -> V_169 [ V_170 ] = V_17 ;
F_2 ( V_17 , V_2 -> V_5 + V_20 ) ;
F_16 ( V_170 , V_2 -> V_5 + V_14 ) ;
F_101 ( V_2 -> V_151 , V_171 ,
& V_2 -> V_167 -> V_172 ) ;
break;
case 0xaa :
if ( ( V_17 & 0x7f ) > 0 )
V_17 -- ;
if ( ( V_17 & 0x7f00 ) > 0 )
V_17 -= 0x0100 ;
V_2 -> V_16 -> V_169 [ V_170 ] = V_17 ;
F_2 ( V_17 , V_2 -> V_5 + V_20 ) ;
F_16 ( V_170 , V_2 -> V_5 + V_14 ) ;
F_101 ( V_2 -> V_151 , V_171 ,
& V_2 -> V_168 -> V_172 ) ;
break;
case 0x66 :
if ( ( V_17 & 0x7f ) < 0x1f )
V_17 ++ ;
if ( ( V_17 & 0x7f00 ) < 0x1f00 )
V_17 += 0x0100 ;
V_2 -> V_16 -> V_169 [ V_170 ] = V_17 ;
F_2 ( V_17 , V_2 -> V_5 + V_20 ) ;
F_16 ( V_170 , V_2 -> V_5 + V_14 ) ;
F_101 ( V_2 -> V_151 , V_171 ,
& V_2 -> V_168 -> V_172 ) ;
break;
}
F_5 ( & V_2 -> V_19 , V_9 ) ;
#else
if ( ! V_2 -> V_173 )
return;
V_17 = 0 ;
switch ( V_165 ) {
case 0x88 :
V_17 = V_174 ;
break;
case 0xaa :
V_17 = V_175 ;
break;
case 0x66 :
V_17 = V_176 ;
break;
}
if ( V_17 ) {
F_102 ( V_2 -> V_173 , V_17 , 1 ) ;
F_103 ( V_2 -> V_173 ) ;
F_102 ( V_2 -> V_173 , V_17 , 0 ) ;
F_103 ( V_2 -> V_173 ) ;
}
#endif
}
static T_6 F_104 ( int V_177 , void * V_178 )
{
struct V_1 * V_2 = V_178 ;
T_3 V_179 ;
if ( ! ( V_179 = F_10 ( V_2 -> V_5 + 0x1A ) ) )
return V_180 ;
F_2 ( F_7 ( V_2 -> V_5 + 4 ) & 1 , V_2 -> V_5 + 4 ) ;
if ( V_179 & V_181 )
#ifdef F_15
F_100 ( ( unsigned long ) V_2 ) ;
#else
F_105 ( & V_2 -> V_182 ) ;
#endif
F_16 ( 0xFF , V_2 -> V_5 + 0x1A ) ;
if ( ( V_179 & V_183 ) && V_2 -> V_184 ) {
F_106 ( V_177 , V_2 -> V_184 -> V_18 ) ;
}
if ( V_179 & V_185 ) {
struct V_42 * V_43 ;
F_39 ( & V_2 -> V_87 ) ;
F_32 (es, &chip->substream_list, list) {
if ( V_43 -> V_90 ) {
F_98 ( V_2 , V_43 ) ;
if ( V_43 -> V_47 & V_48 )
F_97 ( V_2 , V_43 ) ;
}
}
F_40 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_142 ) {
unsigned int V_186 = F_24 ( V_2 , V_2 -> V_143 , 5 ) ;
if ( V_186 < V_2 -> V_187 )
V_2 -> V_144 ++ ;
V_2 -> V_187 = V_186 ;
}
}
return V_188 ;
}
static int T_5
F_107 ( struct V_1 * V_2 )
{
struct V_189 * V_190 ;
struct V_191 V_16 ;
#ifndef F_15
struct V_192 V_193 ;
#endif
int V_113 ;
static struct V_194 V_195 = {
. V_196 = F_14 ,
. V_197 = F_17 ,
} ;
if ( ( V_113 = V_189 ( V_2 -> V_151 , 0 , & V_195 , NULL , & V_190 ) ) < 0 )
return V_113 ;
V_190 -> V_198 = 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_18 = V_2 ;
if ( ( V_113 = F_108 ( V_190 , & V_16 , & V_2 -> V_16 ) ) < 0 )
return V_113 ;
#ifndef F_15
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_199 = V_200 ;
strcpy ( V_193 . V_160 , L_11 ) ;
V_2 -> V_167 = F_109 ( V_2 -> V_151 , & V_193 ) ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_199 = V_200 ;
strcpy ( V_193 . V_160 , L_12 ) ;
V_2 -> V_168 = F_109 ( V_2 -> V_151 , & V_193 ) ;
#endif
return 0 ;
}
static void F_110 ( struct V_1 * V_2 )
{
unsigned long V_201 = V_2 -> V_5 ;
unsigned short V_202 ;
unsigned short V_203 ;
unsigned short V_204 ;
unsigned int V_205 ;
V_202 = F_7 ( V_201 + 0x36 ) ;
F_2 ( F_7 ( V_201 + 0x3a ) & 0xfffc , V_201 + 0x3a ) ;
F_2 ( F_7 ( V_201 + 0x3c ) & 0xfffc , V_201 + 0x3c ) ;
F_2 ( 0x0000 , V_201 + 0x36 ) ;
V_203 = F_7 ( V_201 + 0x68 ) ;
F_111 ( V_2 -> V_112 , 0x58 , & V_204 ) ;
F_112 ( V_2 -> V_112 , V_206 , & V_205 ) ;
if ( V_204 & 1 )
V_203 |= 0x10 ;
F_2 ( 0xfffe , V_201 + 0x64 ) ;
F_2 ( 0x0001 , V_201 + 0x68 ) ;
F_2 ( 0x0000 , V_201 + 0x60 ) ;
F_113 ( 20 ) ;
F_2 ( 0x0001 , V_201 + 0x60 ) ;
F_91 ( 20 ) ;
F_2 ( V_203 | 0x1 , V_201 + 0x68 ) ;
F_2 ( ( F_7 ( V_201 + 0x38 ) & 0xfffc ) | 0x1 , V_201 + 0x38 ) ;
F_2 ( ( F_7 ( V_201 + 0x3a ) & 0xfffc ) | 0x1 , V_201 + 0x3a ) ;
F_2 ( ( F_7 ( V_201 + 0x3c ) & 0xfffc ) | 0x1 , V_201 + 0x3c ) ;
F_2 ( 0x0000 , V_201 + 0x36 ) ;
F_2 ( 0xfff7 , V_201 + 0x64 ) ;
V_203 = F_7 ( V_201 + 0x68 ) ;
F_2 ( 0x0009 , V_201 + 0x68 ) ;
F_2 ( 0x0001 , V_201 + 0x60 ) ;
F_113 ( 20 ) ;
F_2 ( 0x0009 , V_201 + 0x60 ) ;
F_91 ( 500 ) ;
F_2 ( F_7 ( V_201 + 0x3a ) & 0xfffc , V_201 + 0x3a ) ;
F_2 ( F_7 ( V_201 + 0x3c ) & 0xfffc , V_201 + 0x3c ) ;
#if 0
snd_printk(KERN_INFO "trying software reset\n");
outb(0x80 | 0x7c, ioaddr + 0x30);
for (w = 0;; w++) {
if ((inw(ioaddr + 0x30) & 1) == 0) {
if (inb(ioaddr + 0x32) != 0)
break;
outb(0x80 | 0x7d, ioaddr + 0x30);
if (((inw(ioaddr + 0x30) & 1) == 0)
&& (inb(ioaddr + 0x32) != 0))
break;
outb(0x80 | 0x7f, ioaddr + 0x30);
if (((inw(ioaddr + 0x30) & 1) == 0)
&& (inb(ioaddr + 0x32) != 0))
break;
}
if (w > 10000) {
outb(inb(ioaddr + 0x37) | 0x08, ioaddr + 0x37);
msleep(500);
outb(inb(ioaddr + 0x37) & ~0x08,
ioaddr + 0x37);
udelay(1);
outw(0x80, ioaddr + 0x30);
for (w = 0; w < 10000; w++) {
if ((inw(ioaddr + 0x30) & 1) == 0)
break;
}
}
}
#endif
if ( V_205 == V_207 || V_205 == V_208 ) {
F_2 ( 0xf9ff , V_201 + 0x64 ) ;
F_2 ( F_7 ( V_201 + 0x68 ) | 0x600 , V_201 + 0x68 ) ;
F_2 ( 0x0209 , V_201 + 0x60 ) ;
}
F_2 ( V_202 , V_201 + 0x36 ) ;
F_16 ( F_10 ( V_201 + 0xc0 ) | ( 1 << 5 ) , V_201 + 0xc0 ) ;
F_16 ( 0xff , V_201 + 0xc3 ) ;
F_16 ( 0xff , V_201 + 0xc4 ) ;
F_16 ( 0xff , V_201 + 0xc6 ) ;
F_16 ( 0xff , V_201 + 0xc8 ) ;
F_16 ( 0x3f , V_201 + 0xcf ) ;
F_16 ( 0x3f , V_201 + 0xd0 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_2 ( V_209 | V_210 ,
V_2 -> V_5 + V_73 ) ;
F_113 ( 10 ) ;
F_2 ( 0x0000 , V_2 -> V_5 + V_73 ) ;
F_113 ( 10 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_211 * V_112 = V_2 -> V_112 ;
int V_22 ;
unsigned long V_212 = V_2 -> V_5 ;
T_1 V_204 ;
T_3 V_213 ;
F_111 ( V_112 , V_214 , & V_204 ) ;
V_204 &= ~ V_215 ;
V_204 &= ~ ( V_216 | V_217 ) ;
V_204 &= ~ V_218 ;
V_204 |= V_219 ;
V_204 |= V_220 ;
V_204 &= ~ V_221 ;
V_204 &= ~ V_222 ;
F_116 ( V_112 , V_214 , V_204 ) ;
F_111 ( V_112 , V_223 , & V_204 ) ;
V_204 &= ~ ( 1 << 15 ) ;
V_204 &= ~ ( 1 << 14 ) ;
V_204 &= ~ V_224 ;
V_204 |= V_225 ;
V_204 |= V_226 ;
V_204 &= ~ V_227 ;
V_204 |= V_228 ;
V_204 &= ~ V_229 ;
V_204 &= ~ V_230 ;
V_204 &= ~ ( 1 << 1 ) ;
V_204 &= ~ V_231 ;
F_116 ( V_112 , V_223 , V_204 ) ;
F_111 ( V_112 , V_232 , & V_204 ) ;
V_204 &= ~ ( 1 << 0 ) ;
F_116 ( V_112 , V_232 , V_204 ) ;
F_111 ( V_112 , V_233 , & V_204 ) ;
V_204 |= V_234 ;
V_204 &= ~ V_235 ;
V_204 &= ~ ( 0x1f ) ;
F_116 ( V_112 , V_233 , V_204 ) ;
F_111 ( V_112 , 0x58 , & V_204 ) ;
V_204 |= 1 << 2 ;
V_204 |= 1 << 3 ;
V_204 &= ~ ( 1 << 11 ) ;
F_116 ( V_112 , 0x58 , V_204 ) ;
F_114 ( V_2 ) ;
F_2 ( 0xC090 , V_212 + V_236 ) ;
F_113 ( 20 ) ;
F_2 ( 0x3000 , V_212 + V_237 ) ;
F_113 ( 20 ) ;
F_110 ( V_2 ) ;
V_213 = F_117 ( V_212 + V_238 ) ;
V_213 &= ~ V_239 ;
F_118 ( V_213 , V_212 + V_238 ) ;
F_16 ( 0x88 , V_212 + 0x1c ) ;
F_16 ( 0x88 , V_212 + 0x1d ) ;
F_16 ( 0x88 , V_212 + 0x1e ) ;
F_16 ( 0x88 , V_212 + 0x1f ) ;
F_16 ( 0 , V_212 + V_240 ) ;
F_16 ( 3 , V_212 + V_241 ) ;
F_16 ( 0 , V_212 + V_242 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ ) {
F_2 ( 0x01E0 + V_22 , V_212 + V_30 ) ;
F_2 ( 0x0000 , V_212 + V_31 ) ;
F_2 ( 0x01D0 + V_22 , V_212 + V_30 ) ;
F_2 ( 0x0000 , V_212 + V_31 ) ;
}
F_26 ( V_2 , V_243 ,
( F_27 ( V_2 , V_243 ) & 0xFF00 ) ) ;
F_26 ( V_2 , V_243 ,
F_27 ( V_2 , V_243 ) | 0x100 ) ;
F_26 ( V_2 , V_243 ,
F_27 ( V_2 , V_243 ) & ~ 0x200 ) ;
F_26 ( V_2 , V_243 ,
F_27 ( V_2 , V_243 ) | ~ 0x400 ) ;
F_3 ( V_2 , V_244 , 0x0000 ) ;
F_3 ( V_2 , 0x08 , 0xB004 ) ;
F_3 ( V_2 , 0x09 , 0x001B ) ;
F_3 ( V_2 , 0x0A , 0x8000 ) ;
F_3 ( V_2 , 0x0B , 0x3F37 ) ;
F_3 ( V_2 , 0x0C , 0x0098 ) ;
F_3 ( V_2 , 0x0C ,
( F_8 ( V_2 , 0x0C ) & ~ 0xF000 ) | 0x8000 ) ;
F_3 ( V_2 , 0x0C ,
( F_8 ( V_2 , 0x0C ) & ~ 0x0F00 ) | 0x0500 ) ;
F_3 ( V_2 , 0x0D , 0x7632 ) ;
V_204 = F_7 ( V_212 + V_245 ) ;
V_204 &= ~ 0xFA00 ;
V_204 |= 0xA000 ;
V_204 &= ~ 0x0200 ;
V_204 |= 0x0100 ;
V_204 |= 0x0080 ;
V_204 &= ~ 0x0060 ;
V_204 |= 0x0020 ;
V_204 &= ~ 0x000C ;
V_204 &= ~ 0x0001 ;
F_2 ( V_204 , V_212 + V_245 ) ;
for ( V_22 = 0 ; V_22 < V_26 ; V_22 ++ ) {
for ( V_204 = 0 ; V_204 < V_246 ; V_204 ++ )
F_23 ( V_2 , V_22 , V_204 , 0 ) ;
}
}
static void F_119 ( struct V_1 * V_2 )
{
unsigned short V_204 ;
V_204 = V_74 | V_247 ;
if ( V_2 -> V_184 )
V_204 |= V_248 ;
F_16 ( V_204 , V_2 -> V_5 + 0x1A ) ;
F_2 ( V_204 , V_2 -> V_5 + V_73 ) ;
}
static int F_120 ( struct V_211 * V_112 , T_7 V_249 )
{
struct V_250 * V_151 = F_121 ( V_112 ) ;
struct V_1 * V_2 = V_151 -> V_18 ;
if ( ! V_2 -> V_251 )
return 0 ;
V_2 -> V_166 = 1 ;
F_122 ( V_151 , V_252 ) ;
F_123 ( V_2 -> V_149 ) ;
F_124 ( V_2 -> V_16 ) ;
F_28 ( V_2 ) ;
F_125 ( V_112 ) ;
F_126 ( V_112 ) ;
F_127 ( V_112 , F_128 ( V_112 , V_249 ) ) ;
return 0 ;
}
static int F_129 ( struct V_211 * V_112 )
{
struct V_250 * V_151 = F_121 ( V_112 ) ;
struct V_1 * V_2 = V_151 -> V_18 ;
struct V_42 * V_43 ;
if ( ! V_2 -> V_251 )
return 0 ;
F_127 ( V_112 , V_253 ) ;
F_130 ( V_112 ) ;
if ( F_131 ( V_112 ) < 0 ) {
F_92 ( V_117 L_13
L_14 ) ;
F_132 ( V_151 ) ;
return - V_254 ;
}
F_133 ( V_112 ) ;
F_115 ( V_2 ) ;
if ( V_2 -> V_70 . V_59 ) {
F_26 ( V_2 , 0x01FC , V_2 -> V_70 . V_59 >> 12 ) ;
}
F_119 ( V_2 ) ;
F_134 ( V_2 -> V_16 ) ;
F_32 (es, &chip->substream_list, list) {
switch ( V_43 -> V_56 ) {
case V_85 :
F_43 ( V_2 , V_43 , V_43 -> V_82 -> V_45 ) ;
break;
case V_58 :
F_45 ( V_2 , V_43 , V_43 -> V_82 -> V_45 ) ;
break;
}
}
if ( V_2 -> V_39 )
F_29 ( V_2 ) ;
F_122 ( V_151 , V_255 ) ;
V_2 -> V_166 = 0 ;
return 0 ;
}
static int T_5 F_135 ( struct V_1 * V_2 , int V_114 )
{
struct V_256 * V_257 ;
struct V_258 * V_259 ;
T_1 V_17 ;
if ( ! V_260 [ V_114 ] )
return - V_261 ;
V_259 = F_136 ( V_262 , 8 , L_15 ) ;
if ( ! V_259 )
return - V_124 ;
V_2 -> V_256 = V_257 = F_137 () ;
if ( ! V_257 ) {
F_92 ( V_117 L_16 ) ;
F_138 ( V_259 ) ;
return - V_118 ;
}
F_111 ( V_2 -> V_112 , V_233 , & V_17 ) ;
F_116 ( V_2 -> V_112 , V_233 , V_17 | 0x04 ) ;
F_139 ( V_257 , L_17 ) ;
F_140 ( V_257 , L_18 , F_141 ( V_2 -> V_112 ) ) ;
F_142 ( V_257 , & V_2 -> V_112 -> V_114 ) ;
V_257 -> V_263 = V_262 ;
F_143 ( V_257 , V_259 ) ;
F_144 ( V_257 ) ;
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_256 ) {
struct V_258 * V_259 = F_146 ( V_2 -> V_256 ) ;
F_147 ( V_2 -> V_256 ) ;
V_2 -> V_256 = NULL ;
F_138 ( V_259 ) ;
}
}
static inline int F_135 ( struct V_1 * V_2 , int V_114 ) { return - V_264 ; }
static inline void F_145 ( struct V_1 * V_2 ) { }
static int T_5 F_148 ( struct V_1 * V_2 )
{
struct V_173 * V_173 ;
int V_113 ;
V_173 = F_149 () ;
if ( ! V_173 )
return - V_118 ;
snprintf ( V_2 -> V_265 , sizeof( V_2 -> V_265 ) , L_19 ,
F_141 ( V_2 -> V_112 ) ) ;
V_173 -> V_160 = V_2 -> V_151 -> V_266 ;
V_173 -> V_265 = V_2 -> V_265 ;
V_173 -> V_172 . V_267 = V_268 ;
V_173 -> V_172 . V_269 = V_2 -> V_112 -> V_269 ;
V_173 -> V_172 . V_270 = V_2 -> V_112 -> V_150 ;
V_173 -> V_114 . V_271 = & V_2 -> V_112 -> V_114 ;
F_150 ( V_272 , V_173 -> V_273 ) ;
F_150 ( V_174 , V_173 -> V_274 ) ;
F_150 ( V_176 , V_173 -> V_274 ) ;
F_150 ( V_175 , V_173 -> V_274 ) ;
V_113 = F_151 ( V_173 ) ;
if ( V_113 ) {
F_152 ( V_173 ) ;
return V_113 ;
}
V_2 -> V_173 = V_173 ;
return 0 ;
}
static void F_153 ( struct V_275 * V_276 , T_2 V_277 )
{
struct V_1 * V_2 = V_276 -> V_18 ;
unsigned long V_263 = V_2 -> V_5 + V_278 ;
T_1 V_17 = 0 ;
V_17 |= ( V_277 & V_279 ) ? V_280 : 0 ;
V_17 |= ( V_277 & V_281 ) ? V_282 : 0 ;
V_17 |= ( V_277 & V_283 ) ? V_284 : 0 ;
F_2 ( V_17 , V_263 ) ;
}
static T_2 F_154 ( struct V_275 * V_276 )
{
struct V_1 * V_2 = V_276 -> V_18 ;
unsigned long V_263 = V_2 -> V_5 + V_278 ;
T_1 V_17 = F_7 ( V_263 ) ;
return ( V_17 & V_280 ) ? V_279 : 0 |
( V_17 & V_285 ) ? V_286 : 0 ;
}
static void F_155 ( struct V_275 * V_276 , bool V_287 )
{
struct V_1 * V_2 = V_276 -> V_18 ;
unsigned long V_263 = V_2 -> V_5 + V_278 ;
T_1 V_288 = F_7 ( V_263 + V_289 ) ;
if ( V_287 ) {
F_2 ( ~ ( V_280 | V_282 | V_284 ) , V_263 + V_290 ) ;
F_2 ( V_288 | V_280 | V_282 | V_284 , V_263 + V_289 ) ;
} else {
F_2 ( ~ ( V_282 | V_284 | V_280 | V_285 ) , V_263 + V_290 ) ;
F_2 ( ( V_288 & ~ ( V_280 | V_285 ) ) | V_282 | V_284 , V_263 + V_289 ) ;
}
}
static int F_156 ( struct V_1 * V_2 )
{
#ifdef F_15
if ( V_2 -> V_173 )
F_157 ( V_2 -> V_173 ) ;
#endif
if ( V_2 -> V_5 ) {
if ( V_2 -> V_177 >= 0 )
F_158 ( V_2 -> V_177 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( 0 , V_2 -> V_5 + V_73 ) ;
}
#ifdef F_159
F_160 ( & V_2 -> V_276 ) ;
#endif
if ( V_2 -> V_177 >= 0 )
F_161 ( V_2 -> V_177 , V_2 ) ;
F_145 ( V_2 ) ;
F_162 ( V_2 -> V_112 ) ;
F_125 ( V_2 -> V_112 ) ;
F_64 ( V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_291 * V_150 )
{
struct V_1 * V_2 = V_150 -> V_292 ;
return F_156 ( V_2 ) ;
}
static int T_5 F_164 ( struct V_250 * V_151 ,
struct V_211 * V_112 ,
int V_116 ,
int V_293 ,
int V_294 ,
int V_295 ,
int V_251 ,
struct V_1 * * V_296 )
{
static struct V_297 V_195 = {
. V_298 = F_163 ,
} ;
struct V_1 * V_2 ;
int V_22 , V_113 ;
* V_296 = NULL ;
if ( ( V_113 = F_131 ( V_112 ) ) < 0 )
return V_113 ;
if ( F_165 ( V_112 , F_166 ( 28 ) ) < 0 ||
F_167 ( V_112 , F_166 ( 28 ) ) < 0 ) {
F_72 ( V_117 L_20 ) ;
F_125 ( V_112 ) ;
return - V_299 ;
}
V_2 = F_82 ( sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 ) {
F_125 ( V_112 ) ;
return - V_118 ;
}
V_2 -> type = V_295 ;
F_168 ( & V_2 -> V_10 ) ;
F_168 ( & V_2 -> V_87 ) ;
F_74 ( & V_2 -> V_108 ) ;
F_74 ( & V_2 -> V_131 ) ;
F_169 ( & V_2 -> V_98 ) ;
#ifndef F_15
F_168 ( & V_2 -> V_19 ) ;
F_170 ( & V_2 -> V_182 , F_100 , ( unsigned long ) V_2 ) ;
#endif
V_2 -> V_151 = V_151 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_177 = - 1 ;
V_2 -> V_116 = V_116 ;
V_2 -> V_152 = V_293 ;
V_2 -> V_153 = V_294 ;
if ( ( V_113 = F_171 ( V_112 , L_10 ) ) < 0 ) {
F_64 ( V_2 ) ;
F_125 ( V_112 ) ;
return V_113 ;
}
V_2 -> V_5 = F_172 ( V_112 , 0 ) ;
if ( F_173 ( V_112 -> V_177 , F_104 , V_300 ,
L_10 , V_2 ) ) {
F_72 ( V_117 L_21 , V_112 -> V_177 ) ;
F_156 ( V_2 ) ;
return - V_124 ;
}
V_2 -> V_177 = V_112 -> V_177 ;
for ( V_22 = 0 ; V_22 < 32 ; V_22 ++ )
V_2 -> V_8 [ V_22 ] = 0 ;
for ( V_22 = 0 ; V_22 < V_26 ; V_22 ++ )
V_2 -> V_53 [ V_22 ] = V_123 ;
F_133 ( V_112 ) ;
if ( V_251 > 1 ) {
unsigned short V_205 ;
F_111 ( V_2 -> V_112 , V_206 , & V_205 ) ;
for ( V_22 = 0 ; V_22 < ( int ) F_174 ( V_301 ) ; V_22 ++ ) {
if ( V_2 -> type == V_301 [ V_22 ] . type &&
V_205 == V_301 [ V_22 ] . V_269 ) {
V_251 = 1 ;
break;
}
}
if ( V_251 > 1 ) {
F_92 ( V_147 L_22 ) ;
V_251 = 0 ;
}
}
V_2 -> V_251 = V_251 ;
F_115 ( V_2 ) ;
if ( ( V_113 = F_175 ( V_151 , V_302 , V_2 , & V_195 ) ) < 0 ) {
F_156 ( V_2 ) ;
return V_113 ;
}
F_176 ( V_151 , & V_112 -> V_114 ) ;
#ifdef F_159
V_2 -> V_276 . V_18 = V_2 ;
V_2 -> V_276 . V_195 = & V_303 ;
F_177 ( V_2 -> V_276 . V_151 , L_23 , sizeof( V_2 -> V_276 . V_151 ) ) ;
sprintf ( V_2 -> V_276 . V_304 , L_24 , F_141 ( V_112 ) ) ;
if ( ! F_178 ( & V_2 -> V_276 ) )
F_92 ( V_147 L_25 ) ;
#endif
* V_296 = V_2 ;
return 0 ;
}
static int T_5 F_179 ( struct V_211 * V_112 ,
const struct V_305 * V_306 )
{
static int V_114 ;
struct V_250 * V_151 ;
struct V_1 * V_2 ;
unsigned int V_22 ;
int V_113 ;
if ( V_114 >= V_307 )
return - V_261 ;
if ( ! V_308 [ V_114 ] ) {
V_114 ++ ;
return - V_309 ;
}
V_113 = F_180 ( V_21 [ V_114 ] , V_172 [ V_114 ] , V_310 , 0 , & V_151 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_116 [ V_114 ] < 128 )
V_116 [ V_114 ] = 128 ;
if ( V_116 [ V_114 ] > 4096 )
V_116 [ V_114 ] = 4096 ;
if ( ( V_113 = F_164 ( V_151 , V_112 ,
V_116 [ V_114 ] * 1024 ,
V_311 [ V_114 ] ,
V_312 [ V_114 ] ,
V_306 -> V_313 ,
V_314 [ V_114 ] ,
& V_2 ) ) < 0 ) {
F_181 ( V_151 ) ;
return V_113 ;
}
V_151 -> V_18 = V_2 ;
switch ( V_2 -> type ) {
case V_315 :
strcpy ( V_151 -> V_266 , L_26 ) ;
strcpy ( V_151 -> V_316 , L_27 ) ;
break;
case V_317 :
strcpy ( V_151 -> V_266 , L_28 ) ;
strcpy ( V_151 -> V_316 , L_29 ) ;
break;
case V_318 :
strcpy ( V_151 -> V_266 , L_30 ) ;
strcpy ( V_151 -> V_316 , L_31 ) ;
break;
}
if ( ( V_113 = F_94 ( V_2 , 0 ) ) < 0 ) {
F_181 ( V_151 ) ;
return V_113 ;
}
if ( ( V_113 = F_107 ( V_2 ) ) < 0 ) {
F_181 ( V_151 ) ;
return V_113 ;
}
if ( V_319 [ V_114 ] == 2 ) {
unsigned short V_205 ;
F_111 ( V_2 -> V_112 , V_206 , & V_205 ) ;
for ( V_22 = 0 ; V_22 < F_174 ( V_320 ) ; V_22 ++ ) {
if ( V_2 -> type == V_320 [ V_22 ] . type &&
V_205 == V_320 [ V_22 ] . V_269 ) {
V_319 [ V_114 ] = 0 ;
break;
}
}
}
if ( V_319 [ V_114 ] ) {
if ( ( V_113 = F_182 ( V_151 , 0 , V_321 ,
V_2 -> V_5 + V_322 ,
V_323 ,
V_2 -> V_177 , 0 , & V_2 -> V_184 ) ) < 0 ) {
F_92 ( V_324 L_32 ) ;
}
}
F_135 ( V_2 , V_114 ) ;
#ifdef F_15
V_113 = F_148 ( V_2 ) ;
if ( V_113 )
F_72 ( V_324 L_33
L_34 , V_113 ) ;
#endif
F_119 ( V_2 ) ;
V_2 -> clock = clock [ V_114 ] ;
if ( ! V_2 -> clock )
F_89 ( V_2 ) ;
sprintf ( V_151 -> V_325 , L_35 ,
V_151 -> V_316 , V_2 -> V_5 , V_2 -> V_177 ) ;
if ( ( V_113 = F_183 ( V_151 ) ) < 0 ) {
F_181 ( V_151 ) ;
return V_113 ;
}
F_184 ( V_112 , V_151 ) ;
V_114 ++ ;
return 0 ;
}
static void T_8 F_185 ( struct V_211 * V_112 )
{
F_181 ( F_121 ( V_112 ) ) ;
F_184 ( V_112 , NULL ) ;
}
static int T_9 F_186 ( void )
{
return F_187 ( & V_266 ) ;
}
static void T_10 F_188 ( void )
{
F_189 ( & V_266 ) ;
}
