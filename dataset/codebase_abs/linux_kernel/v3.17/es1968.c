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
F_12 ( V_2 -> V_15 -> V_16 , L_1 ) ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_13 = 100000 ;
while ( V_13 -- > 0 ) {
if ( ! ( F_10 ( V_2 -> V_5 + V_14 ) & 1 ) )
return 0 ;
}
F_12 ( V_2 -> V_15 -> V_16 , L_1 ) ;
return 1 ;
}
static void F_14 ( struct V_17 * V_18 , unsigned short V_3 , unsigned short V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
F_9 ( V_2 ) ;
F_2 ( V_19 , V_2 -> V_5 + V_21 ) ;
F_15 ( V_3 , V_2 -> V_5 + V_14 ) ;
}
static unsigned short F_16 ( struct V_17 * V_18 , unsigned short V_3 )
{
T_1 V_4 = 0 ;
struct V_1 * V_2 = V_18 -> V_20 ;
F_9 ( V_2 ) ;
F_15 ( V_3 | 0x80 , V_2 -> V_5 + V_14 ) ;
if ( ! F_13 ( V_2 ) ) {
V_4 = F_7 ( V_2 -> V_5 + V_21 ) ;
}
return V_4 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_22 )
{
int V_23 ;
F_1 ( V_2 , V_24 , V_22 ) ;
for ( V_23 = 0 ; V_23 < 1000 ; V_23 ++ )
if ( F_6 ( V_2 , V_24 ) == V_22 )
return;
F_12 ( V_2 -> V_15 -> V_16 , L_2 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_4 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 1000 ; V_23 ++ ) {
if ( F_6 ( V_2 , V_25 ) == V_4 )
return;
F_1 ( V_2 , V_25 , V_4 ) ;
}
F_12 ( V_2 -> V_15 -> V_16 , L_3 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_26 , T_2 V_3 , T_1 V_4 )
{
if ( F_20 ( V_26 >= V_27 ) )
return;
#ifdef F_21
V_2 -> V_28 [ V_26 ] [ V_3 ] = V_4 ;
#endif
V_3 |= ( V_26 << 4 ) ;
F_17 ( V_2 , V_3 ) ;
F_18 ( V_2 , V_4 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_26 , T_2 V_3 , T_1 V_4 )
{
unsigned long V_9 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_19 ( V_2 , V_26 , V_3 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 V_26 , T_2 V_3 )
{
if ( F_20 ( V_26 >= V_27 ) )
return 0 ;
V_3 |= ( V_26 << 4 ) ;
F_17 ( V_2 , V_3 ) ;
return F_6 ( V_2 , V_25 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_26 , T_2 V_3 )
{
unsigned long V_9 ;
T_1 V_29 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
V_29 = F_23 ( V_2 , V_26 , V_3 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
return V_29 ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_30 )
{
unsigned long V_9 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( V_3 , V_2 -> V_5 + V_31 ) ;
F_2 ( V_30 , V_2 -> V_5 + V_32 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_9 ;
T_1 V_30 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( V_3 , V_2 -> V_5 + V_31 ) ;
V_30 = F_7 ( V_2 -> V_5 + V_32 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
return V_30 ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_6 ( V_2 , 0x11 ) ;
V_3 &= ~ V_33 ;
F_1 ( V_2 , 0x11 , V_3 ) ;
V_3 = F_6 ( V_2 , 0x17 ) ;
V_3 &= ~ V_34 ;
F_1 ( V_2 , 0x17 , V_3 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_35 ;
int V_36 ;
for ( V_35 = 5 ; V_35 < 12 ; V_35 ++ )
if ( V_2 -> V_37 > ( V_38 >> ( V_35 + 9 ) ) )
break;
V_36 = 1 ;
while ( ( V_35 > 5 ) && ( V_36 < 32 ) ) {
V_35 -- ;
V_36 <<= 1 ;
}
V_36 >>= 1 ;
for (; V_36 < 31 ; V_36 ++ )
if ( V_2 -> V_37 >
( ( V_38 >> ( V_35 + 9 ) ) / ( V_36 + 1 ) ) ) break;
if ( V_36 == 0 ) {
V_36 ++ ;
if ( V_35 > 5 )
V_35 -- ;
} else if ( V_36 > 1 )
V_36 -- ;
F_1 ( V_2 , 6 , 0x9000 | ( V_35 << 5 ) | V_36 ) ;
F_1 ( V_2 , 0x11 , F_6 ( V_2 , 0x11 ) | 1 ) ;
F_1 ( V_2 , 0x17 , F_6 ( V_2 , 0x17 ) | 1 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_39 )
{
V_2 -> V_40 ++ ;
if ( V_2 -> V_40 == 1 ) {
V_2 -> V_37 = V_39 ;
F_28 ( V_2 ) ;
} else if ( V_2 -> V_37 < V_39 ) {
F_27 ( V_2 ) ;
V_2 -> V_37 = V_39 ;
F_28 ( V_2 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_40 -- ;
if ( V_2 -> V_40 <= 0 )
F_27 ( V_2 ) ;
else if ( V_2 -> V_37 > V_41 ) {
int V_42 = V_41 ;
struct V_43 * V_44 ;
F_31 (es, &chip->substream_list, list) {
if ( V_42 < V_44 -> V_37 )
V_42 = V_44 -> V_37 ;
}
if ( V_42 != V_2 -> V_37 ) {
F_27 ( V_2 ) ;
V_2 -> V_37 = V_42 ;
F_28 ( V_2 ) ;
}
}
}
static int
F_32 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_45 * V_46 )
{
int V_39 = V_46 -> V_47 * 4 ;
if ( V_44 -> V_48 & V_49 )
V_39 <<= 1 ;
if ( V_44 -> V_48 & V_50 )
V_39 <<= 1 ;
V_39 /= V_44 -> V_51 ;
if ( V_39 < V_41 )
V_39 = V_41 ;
else if ( V_39 > V_52 )
V_39 = V_52 ;
return V_39 ;
}
static T_3 F_33 ( struct V_1 * V_2 , T_3 V_39 )
{
T_3 V_47 = ( V_39 << 16 ) / V_2 -> clock ;
#if 0
if (rate > 0x10000)
rate = 0x10000;
#endif
return V_47 ;
}
static inline unsigned int
F_34 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned int V_53 ;
V_53 = F_24 ( V_2 , V_44 -> V_54 [ 0 ] , 5 ) ;
V_53 -= V_44 -> V_55 [ 0 ] ;
return ( V_53 & 0xFFFE ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_54 , int V_39 )
{
F_22 ( V_2 , V_54 , 2 ,
( F_24 ( V_2 , V_54 , 2 ) & 0x00FF ) |
( ( V_39 & 0xff ) << 8 ) | 0x10 ) ;
F_22 ( V_2 , V_54 , 3 , V_39 >> 8 ) ;
}
static inline void F_36 ( struct V_1 * V_56 , int V_54 , int V_57 )
{
F_19 ( V_56 , V_54 , 0 ,
( F_23 ( V_56 , V_54 , 0 ) & 0xff0f ) |
( V_57 << 4 ) ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
F_38 ( & V_2 -> V_10 ) ;
F_19 ( V_2 , V_44 -> V_54 [ 0 ] , 5 , V_44 -> V_55 [ 0 ] ) ;
F_36 ( V_2 , V_44 -> V_54 [ 0 ] , V_44 -> V_58 [ 0 ] ) ;
if ( V_44 -> V_57 == V_59 ) {
F_19 ( V_2 , V_44 -> V_54 [ 2 ] , 5 , V_44 -> V_55 [ 2 ] ) ;
F_36 ( V_2 , V_44 -> V_54 [ 2 ] , V_44 -> V_58 [ 2 ] ) ;
}
if ( V_44 -> V_48 & V_49 ) {
F_19 ( V_2 , V_44 -> V_54 [ 1 ] , 5 , V_44 -> V_55 [ 1 ] ) ;
F_36 ( V_2 , V_44 -> V_54 [ 1 ] , V_44 -> V_58 [ 1 ] ) ;
if ( V_44 -> V_57 == V_59 ) {
F_19 ( V_2 , V_44 -> V_54 [ 3 ] , 5 , V_44 -> V_55 [ 3 ] ) ;
F_36 ( V_2 , V_44 -> V_54 [ 3 ] , V_44 -> V_58 [ 3 ] ) ;
}
}
F_39 ( & V_2 -> V_10 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
F_38 ( & V_2 -> V_10 ) ;
F_36 ( V_2 , V_44 -> V_54 [ 0 ] , 0 ) ;
F_36 ( V_2 , V_44 -> V_54 [ 1 ] , 0 ) ;
if ( V_44 -> V_57 == V_59 ) {
F_36 ( V_2 , V_44 -> V_54 [ 2 ] , 0 ) ;
F_36 ( V_2 , V_44 -> V_54 [ 3 ] , 0 ) ;
}
F_39 ( & V_2 -> V_10 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_43 * V_44 ,
int V_26 , T_3 V_60 , int V_61 )
{
T_3 V_62 = ( V_60 - 0x10 ) & 0xFFF8 ;
if ( ! V_61 ) {
if ( ! ( V_44 -> V_48 & V_50 ) )
V_62 |= 4 ;
if ( V_44 -> V_48 & V_49 )
V_62 |= 2 ;
}
F_25 ( V_2 , V_44 -> V_54 [ V_26 ] << 3 , V_62 ) ;
#ifdef F_21
V_44 -> V_63 [ V_26 ] = V_62 ;
#endif
}
static void F_42 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_45 * V_46 )
{
T_3 V_64 ;
int V_65 = 0 ;
int V_26 , V_54 ;
int V_23 , V_66 ;
unsigned long V_9 ;
T_3 V_39 ;
V_66 = V_44 -> V_67 >> V_44 -> V_68 ;
if ( V_44 -> V_48 & V_49 )
V_65 ++ ;
for ( V_26 = 0 ; V_26 <= V_65 ; V_26 ++ ) {
V_54 = V_44 -> V_54 [ V_26 ] ;
F_41 ( V_2 , V_44 , V_26 , V_44 -> V_69 -> V_70 . V_60 , 0 ) ;
V_64 = V_44 -> V_69 -> V_70 . V_60 ;
V_64 -= V_2 -> V_71 . V_60 ;
V_64 >>= 1 ;
V_64 |= 0x00400000 ;
if ( V_44 -> V_48 & V_49 ) {
if ( V_26 )
V_64 |= 0x00800000 ;
if ( V_44 -> V_48 & V_50 )
V_64 >>= 1 ;
}
V_44 -> V_55 [ V_26 ] = V_64 & 0xFFFF ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ )
F_22 ( V_2 , V_54 , V_23 , 0x0000 ) ;
F_22 ( V_2 , V_54 , 4 , ( ( V_64 >> 16 ) & 0xFF ) << 8 ) ;
F_22 ( V_2 , V_54 , 5 , V_64 & 0xFFFF ) ;
F_22 ( V_2 , V_54 , 6 , ( V_64 + V_66 ) & 0xFFFF ) ;
F_22 ( V_2 , V_54 , 7 , V_66 ) ;
F_22 ( V_2 , V_54 , 8 , 0x0000 ) ;
F_22 ( V_2 , V_54 , 9 , 0xD000 ) ;
F_22 ( V_2 , V_54 , 11 , 0x0000 ) ;
F_22 ( V_2 , V_54 , 0 , 0x400F ) ;
if ( V_44 -> V_48 & V_50 )
V_44 -> V_58 [ V_26 ] = V_72 ;
else
V_44 -> V_58 [ V_26 ] = V_73 ;
if ( V_44 -> V_48 & V_49 ) {
F_22 ( V_2 , V_54 , 10 ,
0x8F00 | ( V_26 ? 0 : 0x10 ) ) ;
V_44 -> V_58 [ V_26 ] += 1 ;
} else
F_22 ( V_2 , V_54 , 10 , 0x8F08 ) ;
}
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_74 ) | V_75 , V_2 -> V_5 + V_74 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_39 = V_46 -> V_47 ;
if ( V_39 > 48000 )
V_39 = 48000 ;
if ( V_39 < 4000 )
V_39 = 4000 ;
if ( ! ( V_44 -> V_48 & V_50 ) && ! ( V_44 -> V_48 & V_49 ) )
V_39 >>= 1 ;
V_39 = F_33 ( V_2 , V_39 ) ;
F_35 ( V_2 , V_44 -> V_54 [ 0 ] , V_39 ) ;
F_35 ( V_2 , V_44 -> V_54 [ 1 ] , V_39 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_43 * V_44 , int V_26 ,
unsigned int V_64 , unsigned int V_76 ,
int V_57 , int V_77 )
{
int V_23 , V_54 = V_44 -> V_54 [ V_26 ] ;
V_44 -> V_58 [ V_26 ] = V_57 ;
F_41 ( V_2 , V_44 , V_26 , V_64 , 1 ) ;
V_64 -= V_2 -> V_71 . V_60 ;
V_64 >>= 1 ;
V_44 -> V_55 [ V_26 ] = V_64 & 0xFFFF ;
V_64 |= 0x00400000 ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ )
F_22 ( V_2 , V_54 , V_23 , 0x0000 ) ;
F_22 ( V_2 , V_54 , 2 , 0x8 ) ;
F_22 ( V_2 , V_54 , 4 , ( ( V_64 >> 16 ) & 0xFF ) << 8 ) ;
F_22 ( V_2 , V_54 , 5 , V_64 & 0xFFFF ) ;
F_22 ( V_2 , V_54 , 6 , ( V_64 + V_76 ) & 0xFFFF ) ;
F_22 ( V_2 , V_54 , 7 , V_76 ) ;
F_22 ( V_2 , V_54 , 8 , 0x00F0 ) ;
F_22 ( V_2 , V_54 , 9 , 0x0000 ) ;
F_22 ( V_2 , V_54 , 10 , 0x8F08 ) ;
F_22 ( V_2 , V_54 , 11 , V_77 ) ;
F_22 ( V_2 , V_54 , 0 , 0x400F ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_45 * V_46 )
{
int V_66 ;
T_3 V_39 ;
unsigned long V_9 ;
V_66 = V_44 -> V_67 >> V_44 -> V_68 ;
F_43 ( V_2 , V_44 , 2 ,
V_44 -> V_78 -> V_70 . V_60 , V_79 / 4 ,
V_80 , 0x14 ) ;
F_43 ( V_2 , V_44 , 0 , V_44 -> V_69 -> V_70 . V_60 , V_66 ,
V_81 , V_44 -> V_54 [ 2 ] ) ;
if ( V_44 -> V_48 & V_49 ) {
F_43 ( V_2 , V_44 , 3 ,
V_44 -> V_78 -> V_70 . V_60 + V_79 / 2 ,
V_79 / 4 ,
V_80 , 0x15 ) ;
F_43 ( V_2 , V_44 , 1 ,
V_44 -> V_69 -> V_70 . V_60 + V_66 * 2 , V_66 ,
V_81 , V_44 -> V_54 [ 3 ] ) ;
}
V_39 = V_46 -> V_47 ;
if ( V_39 > 47999 )
V_39 = 47999 ;
if ( V_39 < 4000 )
V_39 = 4000 ;
V_39 = F_33 ( V_2 , V_39 ) ;
F_35 ( V_2 , V_44 -> V_54 [ 0 ] , V_39 ) ;
F_35 ( V_2 , V_44 -> V_54 [ 1 ] , V_39 ) ;
V_39 = 0x10000 ;
F_35 ( V_2 , V_44 -> V_54 [ 2 ] , V_39 ) ;
F_35 ( V_2 , V_44 -> V_54 [ 3 ] , V_39 ) ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_74 ) | V_75 , V_2 -> V_5 + V_74 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static int F_45 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_45 * V_46 = V_83 -> V_46 ;
struct V_43 * V_44 = V_46 -> V_20 ;
V_44 -> V_67 = F_47 ( V_83 ) ;
V_44 -> V_51 = F_48 ( V_83 ) ;
V_44 -> V_68 = 1 ;
V_44 -> V_48 = 0 ;
if ( F_49 ( V_46 -> V_84 ) == 16 )
V_44 -> V_48 |= V_50 ;
if ( V_46 -> V_85 > 1 ) {
V_44 -> V_48 |= V_49 ;
if ( V_44 -> V_48 & V_50 )
V_44 -> V_68 ++ ;
}
V_44 -> V_37 = F_32 ( V_2 , V_44 , V_46 ) ;
switch ( V_44 -> V_57 ) {
case V_86 :
F_42 ( V_2 , V_44 , V_46 ) ;
break;
case V_59 :
F_44 ( V_2 , V_44 , V_46 ) ;
break;
}
return 0 ;
}
static int F_50 ( struct V_82 * V_83 , int V_87 )
{
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_43 * V_44 = V_83 -> V_46 -> V_20 ;
F_38 ( & V_2 -> V_88 ) ;
switch ( V_87 ) {
case V_89 :
case V_90 :
if ( V_44 -> V_91 )
break;
F_29 ( V_2 , V_44 -> V_37 ) ;
V_44 -> V_92 = 0 ;
V_44 -> V_93 = 0 ;
F_37 ( V_2 , V_44 ) ;
V_44 -> V_91 = 1 ;
break;
case V_94 :
case V_95 :
if ( ! V_44 -> V_91 )
break;
F_40 ( V_2 , V_44 ) ;
V_44 -> V_91 = 0 ;
F_30 ( V_2 ) ;
break;
}
F_39 ( & V_2 -> V_88 ) ;
return 0 ;
}
static T_4 F_51 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_43 * V_44 = V_83 -> V_46 -> V_20 ;
unsigned int V_96 ;
V_96 = F_34 ( V_2 , V_44 ) << V_44 -> V_68 ;
return F_52 ( V_83 -> V_46 , V_96 % V_44 -> V_67 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_97 = 0 ;
struct V_98 * V_70 ;
F_54 ( & V_2 -> V_99 ) ;
F_31 (buf, &chip->buf_list, list) {
if ( V_70 -> V_100 && V_70 -> V_70 . V_101 > V_97 )
V_97 = V_70 -> V_70 . V_101 ;
}
F_55 ( & V_2 -> V_99 ) ;
if ( V_97 >= 128 * 1024 )
V_97 = 127 * 1024 ;
return V_97 ;
}
static struct V_98 * F_56 ( struct V_1 * V_2 , int V_66 )
{
struct V_98 * V_70 ;
V_66 = F_57 ( V_66 , V_102 ) ;
F_54 ( & V_2 -> V_99 ) ;
F_31 (buf, &chip->buf_list, list) {
if ( V_70 -> V_100 && V_70 -> V_70 . V_101 >= V_66 )
goto V_103;
}
F_55 ( & V_2 -> V_99 ) ;
return NULL ;
V_103:
if ( V_70 -> V_70 . V_101 > V_66 ) {
struct V_98 * V_104 = F_58 ( sizeof( * V_104 ) , V_105 ) ;
if ( V_104 == NULL ) {
F_55 ( & V_2 -> V_99 ) ;
return NULL ;
}
V_104 -> V_70 = V_70 -> V_70 ;
V_104 -> V_70 . V_101 -= V_66 ;
V_104 -> V_70 . V_106 += V_66 ;
V_104 -> V_70 . V_60 += V_66 ;
V_104 -> V_100 = 1 ;
V_70 -> V_70 . V_101 = V_66 ;
F_59 ( & V_104 -> V_107 , & V_70 -> V_107 ) ;
}
V_70 -> V_100 = 0 ;
F_55 ( & V_2 -> V_99 ) ;
return V_70 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_98 * V_70 )
{
struct V_98 * V_104 ;
F_54 ( & V_2 -> V_99 ) ;
V_70 -> V_100 = 1 ;
if ( V_70 -> V_107 . V_108 != & V_2 -> V_109 ) {
V_104 = F_61 ( V_70 -> V_107 . V_108 , struct V_98 , V_107 ) ;
if ( V_104 -> V_100 ) {
V_104 -> V_70 . V_101 += V_70 -> V_70 . V_101 ;
F_62 ( & V_70 -> V_107 ) ;
F_63 ( V_70 ) ;
V_70 = V_104 ;
}
}
if ( V_70 -> V_107 . V_110 != & V_2 -> V_109 ) {
V_104 = F_61 ( V_70 -> V_107 . V_110 , struct V_98 , V_107 ) ;
if ( V_104 -> V_100 ) {
V_70 -> V_70 . V_101 += V_104 -> V_70 . V_101 ;
F_62 ( & V_104 -> V_107 ) ;
F_63 ( V_104 ) ;
}
}
F_55 ( & V_2 -> V_99 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
if ( ! V_2 -> V_71 . V_106 )
return;
F_65 ( & V_2 -> V_71 ) ;
while ( ( V_112 = V_2 -> V_109 . V_110 ) != & V_2 -> V_109 ) {
struct V_98 * V_104 = F_61 ( V_112 , struct V_98 , V_107 ) ;
F_62 ( V_112 ) ;
F_63 ( V_104 ) ;
}
}
static int
F_66 ( struct V_1 * V_2 )
{
int V_113 ;
struct V_98 * V_104 ;
V_2 -> V_71 . V_16 . type = V_114 ;
V_2 -> V_71 . V_16 . V_16 = F_67 ( V_2 -> V_115 ) ;
V_113 = F_68 ( V_114 ,
F_67 ( V_2 -> V_115 ) ,
V_2 -> V_116 , & V_2 -> V_71 ) ;
if ( V_113 < 0 || ! V_2 -> V_71 . V_106 ) {
F_69 ( V_2 -> V_15 -> V_16 ,
L_4 ,
V_2 -> V_116 ) ;
return - V_117 ;
}
if ( ( V_2 -> V_71 . V_60 + V_2 -> V_71 . V_101 - 1 ) & ~ ( ( 1 << 28 ) - 1 ) ) {
F_65 ( & V_2 -> V_71 ) ;
F_69 ( V_2 -> V_15 -> V_16 , L_5 ) ;
return - V_117 ;
}
F_70 ( & V_2 -> V_109 ) ;
V_104 = F_58 ( sizeof( * V_104 ) , V_105 ) ;
if ( V_104 == NULL ) {
F_64 ( V_2 ) ;
return - V_117 ;
}
memset ( V_2 -> V_71 . V_106 , 0 , V_102 ) ;
V_104 -> V_70 = V_2 -> V_71 ;
V_104 -> V_70 . V_106 += V_102 ;
V_104 -> V_70 . V_60 += V_102 ;
V_104 -> V_70 . V_101 -= V_102 ;
V_104 -> V_100 = 1 ;
F_59 ( & V_104 -> V_107 , & V_2 -> V_109 ) ;
return 0 ;
}
static int F_71 ( struct V_82 * V_83 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_45 * V_46 = V_83 -> V_46 ;
struct V_43 * V_120 = V_46 -> V_20 ;
int V_66 = F_72 ( V_119 ) ;
if ( V_120 -> V_69 ) {
if ( V_120 -> V_69 -> V_70 . V_101 >= V_66 ) {
V_46 -> V_121 = V_66 ;
return 0 ;
}
F_60 ( V_2 , V_120 -> V_69 ) ;
}
V_120 -> V_69 = F_56 ( V_2 , V_66 ) ;
if ( V_120 -> V_69 == NULL ) {
F_12 ( V_2 -> V_15 -> V_16 ,
L_6 , V_66 ) ;
return - V_117 ;
}
F_73 ( V_83 , & V_120 -> V_69 -> V_70 ) ;
return 1 ;
}
static int F_74 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_45 * V_46 = V_83 -> V_46 ;
struct V_43 * V_120 ;
if ( V_46 -> V_20 == NULL )
return 0 ;
V_120 = V_46 -> V_20 ;
if ( V_120 -> V_69 ) {
F_60 ( V_2 , V_120 -> V_69 ) ;
V_120 -> V_69 = NULL ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , int type )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_27 ; V_54 += 2 ) {
if ( V_2 -> V_54 [ V_54 ] == V_122 &&
V_2 -> V_54 [ V_54 + 1 ] == V_122 ) {
V_2 -> V_54 [ V_54 ] = V_2 -> V_54 [ V_54 + 1 ] = type ;
return V_54 ;
}
}
return - V_123 ;
}
static void F_76 ( struct V_1 * V_2 , int V_54 )
{
V_2 -> V_54 [ V_54 ] = V_2 -> V_54 [ V_54 + 1 ] = V_122 ;
}
static int F_77 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_45 * V_46 = V_83 -> V_46 ;
struct V_43 * V_44 ;
int V_124 ;
V_124 = F_75 ( V_2 , V_125 ) ;
if ( V_124 < 0 )
return V_124 ;
V_44 = F_78 ( sizeof( * V_44 ) , V_105 ) ;
if ( ! V_44 ) {
F_76 ( V_2 , V_124 ) ;
return - V_117 ;
}
V_44 -> V_54 [ 0 ] = V_124 ;
V_44 -> V_54 [ 1 ] = V_124 + 1 ;
V_44 -> V_58 [ 0 ] = 0 ;
V_44 -> V_58 [ 1 ] = 0 ;
V_44 -> V_91 = 0 ;
V_44 -> V_83 = V_83 ;
V_44 -> V_57 = V_86 ;
V_46 -> V_20 = V_44 ;
V_46 -> V_126 = V_127 ;
V_46 -> V_126 . V_128 = V_46 -> V_126 . V_129 =
F_53 ( V_2 ) ;
F_79 ( & V_2 -> V_88 ) ;
F_59 ( & V_44 -> V_107 , & V_2 -> V_130 ) ;
F_80 ( & V_2 -> V_88 ) ;
return 0 ;
}
static int F_81 ( struct V_82 * V_83 )
{
struct V_45 * V_46 = V_83 -> V_46 ;
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_43 * V_44 ;
int V_124 , V_131 ;
V_124 = F_75 ( V_2 , V_132 ) ;
if ( V_124 < 0 )
return V_124 ;
V_131 = F_75 ( V_2 , V_133 ) ;
if ( V_131 < 0 ) {
F_76 ( V_2 , V_124 ) ;
return V_131 ;
}
V_44 = F_78 ( sizeof( * V_44 ) , V_105 ) ;
if ( ! V_44 ) {
F_76 ( V_2 , V_124 ) ;
F_76 ( V_2 , V_131 ) ;
return - V_117 ;
}
V_44 -> V_54 [ 0 ] = V_124 ;
V_44 -> V_54 [ 1 ] = V_124 + 1 ;
V_44 -> V_54 [ 2 ] = V_131 ;
V_44 -> V_54 [ 3 ] = V_131 + 1 ;
V_44 -> V_58 [ 0 ] = 0 ;
V_44 -> V_58 [ 1 ] = 0 ;
V_44 -> V_58 [ 2 ] = 0 ;
V_44 -> V_58 [ 3 ] = 0 ;
V_44 -> V_91 = 0 ;
V_44 -> V_83 = V_83 ;
V_44 -> V_57 = V_59 ;
if ( ( V_44 -> V_78 = F_56 ( V_2 , V_79 ) ) == NULL ) {
F_76 ( V_2 , V_124 ) ;
F_76 ( V_2 , V_131 ) ;
F_63 ( V_44 ) ;
return - V_117 ;
}
memset ( V_44 -> V_78 -> V_70 . V_106 , 0 , V_79 ) ;
V_46 -> V_20 = V_44 ;
V_46 -> V_126 = V_134 ;
V_46 -> V_126 . V_128 = V_46 -> V_126 . V_129 =
F_53 ( V_2 ) - 1024 ;
F_82 ( V_46 , 0 , V_135 ) ;
F_79 ( & V_2 -> V_88 ) ;
F_59 ( & V_44 -> V_107 , & V_2 -> V_130 ) ;
F_80 ( & V_2 -> V_88 ) ;
return 0 ;
}
static int F_83 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_43 * V_44 ;
if ( V_83 -> V_46 -> V_20 == NULL )
return 0 ;
V_44 = V_83 -> V_46 -> V_20 ;
F_79 ( & V_2 -> V_88 ) ;
F_62 ( & V_44 -> V_107 ) ;
F_80 ( & V_2 -> V_88 ) ;
F_76 ( V_2 , V_44 -> V_54 [ 0 ] ) ;
F_63 ( V_44 ) ;
return 0 ;
}
static int F_84 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_46 ( V_83 ) ;
struct V_43 * V_44 ;
if ( V_83 -> V_46 -> V_20 == NULL )
return 0 ;
V_44 = V_83 -> V_46 -> V_20 ;
F_79 ( & V_2 -> V_88 ) ;
F_62 ( & V_44 -> V_107 ) ;
F_80 ( & V_2 -> V_88 ) ;
F_60 ( V_2 , V_44 -> V_78 ) ;
F_76 ( V_2 , V_44 -> V_54 [ 0 ] ) ;
F_76 ( V_2 , V_44 -> V_54 [ 2 ] ) ;
F_63 ( V_44 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
int V_23 , V_54 ;
unsigned int V_64 , V_53 , V_136 ;
struct V_98 * V_69 ;
struct V_137 V_138 , V_139 ;
if ( V_2 -> clock == 0 )
V_2 -> clock = 48000 ;
if ( ( V_54 = F_75 ( V_2 , V_125 ) ) < 0 ) {
F_69 ( V_2 -> V_15 -> V_16 , L_7 ) ;
return;
}
if ( ( V_69 = F_56 ( V_2 , V_140 ) ) == NULL ) {
F_86 ( V_2 -> V_15 -> V_16 ,
L_8 ,
V_2 -> clock ) ;
F_76 ( V_2 , V_54 ) ;
return;
}
memset ( V_69 -> V_70 . V_106 , 0 , V_140 ) ;
F_25 ( V_2 , V_54 << 3 , ( V_69 -> V_70 . V_60 - 0x10 ) & 0xfff8 ) ;
V_64 = ( unsigned int ) ( ( V_69 -> V_70 . V_60 - V_2 -> V_71 . V_60 ) >> 1 ) ;
V_64 |= 0x00400000 ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ )
F_22 ( V_2 , V_54 , V_23 , 0x0000 ) ;
F_22 ( V_2 , V_54 , 0 , 0x400f ) ;
F_22 ( V_2 , V_54 , 4 , ( ( V_64 >> 16 ) & 0xff ) << 8 ) ;
F_22 ( V_2 , V_54 , 5 , V_64 & 0xffff ) ;
F_22 ( V_2 , V_54 , 6 , ( V_64 + V_140 / 2 ) & 0xffff ) ;
F_22 ( V_2 , V_54 , 7 , V_140 / 2 ) ;
F_22 ( V_2 , V_54 , 8 , 0x0000 ) ;
F_22 ( V_2 , V_54 , 9 , 0xD000 ) ;
F_22 ( V_2 , V_54 , 10 , 0x8F08 ) ;
F_22 ( V_2 , V_54 , 11 , 0x0000 ) ;
F_79 ( & V_2 -> V_10 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_74 ) | V_75 , V_2 -> V_5 + V_74 ) ;
F_80 ( & V_2 -> V_10 ) ;
F_35 ( V_2 , V_54 , ( ( unsigned int ) 48000 << 16 ) / V_2 -> clock ) ;
V_2 -> V_141 = 1 ;
V_2 -> V_142 = V_54 ;
F_79 ( & V_2 -> V_10 ) ;
F_29 ( V_2 , V_41 ) ;
F_19 ( V_2 , V_54 , 5 , V_64 & 0xffff ) ;
F_36 ( V_2 , V_54 , V_72 ) ;
F_87 ( & V_138 ) ;
F_80 ( & V_2 -> V_10 ) ;
F_88 ( 50 ) ;
F_79 ( & V_2 -> V_10 ) ;
V_53 = F_23 ( V_2 , V_54 , 5 ) ;
F_87 ( & V_139 ) ;
F_36 ( V_2 , V_54 , 0 ) ;
F_30 ( V_2 ) ;
V_2 -> V_141 = 0 ;
F_80 ( & V_2 -> V_10 ) ;
V_53 -= ( V_64 & 0xffff ) ;
V_53 &= 0xfffe ;
V_53 += V_2 -> V_143 * ( V_140 / 2 ) ;
V_136 = V_139 . V_144 - V_138 . V_144 ;
V_136 *= 1000000 ;
if ( V_139 . V_145 < V_138 . V_145 )
V_136 -= V_138 . V_145 - V_139 . V_145 ;
else
V_136 += V_139 . V_145 - V_138 . V_145 ;
if ( V_136 == 0 ) {
F_69 ( V_2 -> V_15 -> V_16 , L_9 ) ;
} else {
V_53 *= 1000 ;
V_53 = ( V_53 / V_136 ) * 1000 + ( ( V_53 % V_136 ) * 1000 ) / V_136 ;
if ( V_53 < 47500 || V_53 > 48500 ) {
if ( V_53 >= 40000 && V_53 <= 50000 )
V_2 -> clock = ( V_2 -> clock * V_53 ) / 48000 ;
}
F_89 ( V_2 -> V_15 -> V_16 , L_10 , V_2 -> clock ) ;
}
F_60 ( V_2 , V_69 ) ;
F_76 ( V_2 , V_54 ) ;
}
static void F_90 ( struct V_146 * V_147 )
{
struct V_1 * V_56 = V_147 -> V_20 ;
F_64 ( V_56 ) ;
V_56 -> V_147 = NULL ;
}
static int
F_91 ( struct V_1 * V_2 , int V_148 )
{
struct V_146 * V_147 ;
int V_113 ;
if ( ( V_113 = F_66 ( V_2 ) ) < 0 )
return V_113 ;
F_25 ( V_2 , 0x01FC , V_2 -> V_71 . V_60 >> 12 ) ;
F_25 ( V_2 , 0x01FD , V_2 -> V_71 . V_60 >> 12 ) ;
F_25 ( V_2 , 0x01FE , V_2 -> V_71 . V_60 >> 12 ) ;
F_25 ( V_2 , 0x01FF , V_2 -> V_71 . V_60 >> 12 ) ;
if ( ( V_113 = F_92 ( V_2 -> V_15 , L_11 , V_148 ,
V_2 -> V_149 ,
V_2 -> V_150 , & V_147 ) ) < 0 )
return V_113 ;
V_147 -> V_20 = V_2 ;
V_147 -> V_151 = F_90 ;
F_93 ( V_147 , V_152 , & V_153 ) ;
F_93 ( V_147 , V_154 , & V_155 ) ;
V_147 -> V_156 = 0 ;
strcpy ( V_147 -> V_157 , L_11 ) ;
V_2 -> V_147 = V_147 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned int V_158 ;
unsigned int V_159 ;
unsigned int V_160 ;
V_158 = F_23 ( V_2 , 0 , 5 ) ;
V_159 = F_23 ( V_2 , 1 , 5 ) ;
V_160 = ( V_158 > V_159 ? V_158 - V_159 : V_159 - V_158 ) ;
if ( V_160 > 1 )
F_1 ( V_2 , V_25 , V_158 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned int V_93 ;
unsigned int V_160 ;
struct V_82 * V_161 = V_44 -> V_83 ;
if ( V_161 == NULL || ! V_44 -> V_91 )
return;
V_93 = F_34 ( V_2 , V_44 ) << V_44 -> V_68 ;
V_93 %= V_44 -> V_67 ;
V_160 = ( V_44 -> V_67 + V_93 - V_44 -> V_93 ) % V_44 -> V_67 ;
V_44 -> V_93 = V_93 ;
V_44 -> V_92 += V_160 ;
if ( V_44 -> V_92 > V_44 -> V_51 ) {
F_39 ( & V_2 -> V_88 ) ;
F_96 ( V_161 ) ;
F_38 ( & V_2 -> V_88 ) ;
V_44 -> V_92 %= V_44 -> V_51 ;
}
}
static void F_97 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = F_98 ( V_163 , struct V_1 , V_164 ) ;
int V_165 , V_19 ;
V_165 = F_10 ( V_2 -> V_5 + 0x1c ) & 0xee ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1c ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1d ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1e ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1f ) ;
if ( V_2 -> V_166 )
return;
#ifndef F_99
if ( ! V_2 -> V_167 || ! V_2 -> V_168 )
return;
V_19 = F_100 ( V_2 -> V_18 , V_169 ) ;
switch ( V_165 ) {
case 0x88 :
V_19 ^= 0x8000 ;
break;
case 0xaa :
if ( ( V_19 & 0x7f ) > 0 )
V_19 -- ;
if ( ( V_19 & 0x7f00 ) > 0 )
V_19 -= 0x0100 ;
break;
case 0x66 :
if ( ( V_19 & 0x7f ) < 0x1f )
V_19 ++ ;
if ( ( V_19 & 0x7f00 ) < 0x1f00 )
V_19 += 0x0100 ;
break;
}
if ( F_101 ( V_2 -> V_18 , V_169 , V_19 ) )
F_102 ( V_2 -> V_15 , V_170 ,
& V_2 -> V_168 -> V_171 ) ;
#else
if ( ! V_2 -> V_172 )
return;
V_19 = 0 ;
switch ( V_165 ) {
case 0x88 :
V_19 = V_173 ;
break;
case 0xaa :
V_19 = V_174 ;
break;
case 0x66 :
V_19 = V_175 ;
break;
}
if ( V_19 ) {
F_103 ( V_2 -> V_172 , V_19 , 1 ) ;
F_104 ( V_2 -> V_172 ) ;
F_103 ( V_2 -> V_172 , V_19 , 0 ) ;
F_104 ( V_2 -> V_172 ) ;
}
#endif
}
static T_5 F_105 ( int V_176 , void * V_177 )
{
struct V_1 * V_2 = V_177 ;
T_3 V_178 ;
if ( ! ( V_178 = F_10 ( V_2 -> V_5 + 0x1A ) ) )
return V_179 ;
F_2 ( F_7 ( V_2 -> V_5 + 4 ) & 1 , V_2 -> V_5 + 4 ) ;
if ( V_178 & V_180 )
F_106 ( & V_2 -> V_164 ) ;
F_15 ( 0xFF , V_2 -> V_5 + 0x1A ) ;
if ( ( V_178 & V_181 ) && V_2 -> V_182 ) {
F_107 ( V_176 , V_2 -> V_182 -> V_20 ) ;
}
if ( V_178 & V_183 ) {
struct V_43 * V_44 ;
F_38 ( & V_2 -> V_88 ) ;
F_31 (es, &chip->substream_list, list) {
if ( V_44 -> V_91 ) {
F_95 ( V_2 , V_44 ) ;
if ( V_44 -> V_48 & V_49 )
F_94 ( V_2 , V_44 ) ;
}
}
F_39 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_141 ) {
unsigned int V_184 = F_23 ( V_2 , V_2 -> V_142 , 5 ) ;
if ( V_184 < V_2 -> V_185 )
V_2 -> V_143 ++ ;
V_2 -> V_185 = V_184 ;
}
}
return V_186 ;
}
static int
F_108 ( struct V_1 * V_2 )
{
struct V_187 * V_188 ;
struct V_189 V_18 ;
#ifndef F_99
struct V_190 V_191 ;
#endif
int V_113 ;
static struct V_192 V_193 = {
. V_194 = F_14 ,
. V_195 = F_16 ,
} ;
if ( ( V_113 = V_187 ( V_2 -> V_15 , 0 , & V_193 , NULL , & V_188 ) ) < 0 )
return V_113 ;
V_188 -> V_196 = 1 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_20 = V_2 ;
if ( ( V_113 = F_109 ( V_188 , & V_18 , & V_2 -> V_18 ) ) < 0 )
return V_113 ;
#ifndef F_99
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
V_191 . V_197 = V_198 ;
strcpy ( V_191 . V_157 , L_12 ) ;
V_2 -> V_167 = F_110 ( V_2 -> V_15 , & V_191 ) ;
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
V_191 . V_197 = V_198 ;
strcpy ( V_191 . V_157 , L_13 ) ;
V_2 -> V_168 = F_110 ( V_2 -> V_15 , & V_191 ) ;
#endif
return 0 ;
}
static void F_111 ( struct V_1 * V_2 )
{
unsigned long V_199 = V_2 -> V_5 ;
unsigned short V_200 ;
unsigned short V_201 ;
unsigned short V_202 ;
unsigned int V_203 ;
V_200 = F_7 ( V_199 + 0x36 ) ;
F_2 ( F_7 ( V_199 + 0x3a ) & 0xfffc , V_199 + 0x3a ) ;
F_2 ( F_7 ( V_199 + 0x3c ) & 0xfffc , V_199 + 0x3c ) ;
F_2 ( 0x0000 , V_199 + 0x36 ) ;
V_201 = F_7 ( V_199 + 0x68 ) ;
F_112 ( V_2 -> V_115 , 0x58 , & V_202 ) ;
F_113 ( V_2 -> V_115 , V_204 , & V_203 ) ;
if ( V_202 & 1 )
V_201 |= 0x10 ;
F_2 ( 0xfffe , V_199 + 0x64 ) ;
F_2 ( 0x0001 , V_199 + 0x68 ) ;
F_2 ( 0x0000 , V_199 + 0x60 ) ;
F_114 ( 20 ) ;
F_2 ( 0x0001 , V_199 + 0x60 ) ;
F_88 ( 20 ) ;
F_2 ( V_201 | 0x1 , V_199 + 0x68 ) ;
F_2 ( ( F_7 ( V_199 + 0x38 ) & 0xfffc ) | 0x1 , V_199 + 0x38 ) ;
F_2 ( ( F_7 ( V_199 + 0x3a ) & 0xfffc ) | 0x1 , V_199 + 0x3a ) ;
F_2 ( ( F_7 ( V_199 + 0x3c ) & 0xfffc ) | 0x1 , V_199 + 0x3c ) ;
F_2 ( 0x0000 , V_199 + 0x36 ) ;
F_2 ( 0xfff7 , V_199 + 0x64 ) ;
V_201 = F_7 ( V_199 + 0x68 ) ;
F_2 ( 0x0009 , V_199 + 0x68 ) ;
F_2 ( 0x0001 , V_199 + 0x60 ) ;
F_114 ( 20 ) ;
F_2 ( 0x0009 , V_199 + 0x60 ) ;
F_88 ( 500 ) ;
F_2 ( F_7 ( V_199 + 0x3a ) & 0xfffc , V_199 + 0x3a ) ;
F_2 ( F_7 ( V_199 + 0x3c ) & 0xfffc , V_199 + 0x3c ) ;
#if 0
dev_info(chip->card->dev, "trying software reset\n");
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
if ( V_203 == V_205 || V_203 == V_206 ) {
F_2 ( 0xf9ff , V_199 + 0x64 ) ;
F_2 ( F_7 ( V_199 + 0x68 ) | 0x600 , V_199 + 0x68 ) ;
F_2 ( 0x0209 , V_199 + 0x60 ) ;
}
F_2 ( V_200 , V_199 + 0x36 ) ;
F_15 ( F_10 ( V_199 + 0xc0 ) | ( 1 << 5 ) , V_199 + 0xc0 ) ;
F_15 ( 0xff , V_199 + 0xc3 ) ;
F_15 ( 0xff , V_199 + 0xc4 ) ;
F_15 ( 0xff , V_199 + 0xc6 ) ;
F_15 ( 0xff , V_199 + 0xc8 ) ;
F_15 ( 0x3f , V_199 + 0xcf ) ;
F_15 ( 0x3f , V_199 + 0xd0 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_2 ( V_207 | V_208 ,
V_2 -> V_5 + V_74 ) ;
F_114 ( 10 ) ;
F_2 ( 0x0000 , V_2 -> V_5 + V_74 ) ;
F_114 ( 10 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_209 * V_115 = V_2 -> V_115 ;
int V_23 ;
unsigned long V_210 = V_2 -> V_5 ;
T_1 V_202 ;
T_3 V_211 ;
F_112 ( V_115 , V_212 , & V_202 ) ;
V_202 &= ~ V_213 ;
V_202 &= ~ ( V_214 | V_215 ) ;
V_202 &= ~ V_216 ;
V_202 |= V_217 ;
V_202 |= V_218 ;
V_202 &= ~ V_219 ;
V_202 &= ~ V_220 ;
F_117 ( V_115 , V_212 , V_202 ) ;
F_112 ( V_115 , V_221 , & V_202 ) ;
V_202 &= ~ ( 1 << 15 ) ;
V_202 &= ~ ( 1 << 14 ) ;
V_202 &= ~ V_222 ;
V_202 |= V_223 ;
V_202 |= V_224 ;
V_202 &= ~ V_225 ;
V_202 |= V_226 ;
V_202 &= ~ V_227 ;
V_202 &= ~ V_228 ;
V_202 &= ~ ( 1 << 1 ) ;
V_202 &= ~ V_229 ;
F_117 ( V_115 , V_221 , V_202 ) ;
F_112 ( V_115 , V_230 , & V_202 ) ;
V_202 &= ~ ( 1 << 0 ) ;
F_117 ( V_115 , V_230 , V_202 ) ;
F_112 ( V_115 , V_231 , & V_202 ) ;
V_202 |= V_232 ;
V_202 &= ~ V_233 ;
V_202 &= ~ ( 0x1f ) ;
F_117 ( V_115 , V_231 , V_202 ) ;
F_112 ( V_115 , 0x58 , & V_202 ) ;
V_202 |= 1 << 2 ;
V_202 |= 1 << 3 ;
V_202 &= ~ ( 1 << 11 ) ;
F_117 ( V_115 , 0x58 , V_202 ) ;
F_115 ( V_2 ) ;
F_2 ( 0xC090 , V_210 + V_234 ) ;
F_114 ( 20 ) ;
F_2 ( 0x3000 , V_210 + V_235 ) ;
F_114 ( 20 ) ;
F_111 ( V_2 ) ;
V_211 = F_118 ( V_210 + V_236 ) ;
V_211 &= ~ V_237 ;
F_119 ( V_211 , V_210 + V_236 ) ;
F_15 ( 0x88 , V_210 + 0x1c ) ;
F_15 ( 0x88 , V_210 + 0x1d ) ;
F_15 ( 0x88 , V_210 + 0x1e ) ;
F_15 ( 0x88 , V_210 + 0x1f ) ;
F_15 ( 0 , V_210 + V_238 ) ;
F_15 ( 3 , V_210 + V_239 ) ;
F_15 ( 0 , V_210 + V_240 ) ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ ) {
F_2 ( 0x01E0 + V_23 , V_210 + V_31 ) ;
F_2 ( 0x0000 , V_210 + V_32 ) ;
F_2 ( 0x01D0 + V_23 , V_210 + V_31 ) ;
F_2 ( 0x0000 , V_210 + V_32 ) ;
}
F_25 ( V_2 , V_241 ,
( F_26 ( V_2 , V_241 ) & 0xFF00 ) ) ;
F_25 ( V_2 , V_241 ,
F_26 ( V_2 , V_241 ) | 0x100 ) ;
F_25 ( V_2 , V_241 ,
F_26 ( V_2 , V_241 ) & ~ 0x200 ) ;
F_25 ( V_2 , V_241 ,
F_26 ( V_2 , V_241 ) | ~ 0x400 ) ;
F_3 ( V_2 , V_242 , 0x0000 ) ;
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
V_202 = F_7 ( V_210 + V_243 ) ;
V_202 &= ~ 0xFA00 ;
V_202 |= 0xA000 ;
V_202 &= ~ 0x0200 ;
V_202 |= 0x0100 ;
V_202 |= 0x0080 ;
V_202 &= ~ 0x0060 ;
V_202 |= 0x0020 ;
V_202 &= ~ 0x000C ;
V_202 &= ~ 0x0001 ;
F_2 ( V_202 , V_210 + V_243 ) ;
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ ) {
for ( V_202 = 0 ; V_202 < V_244 ; V_202 ++ )
F_22 ( V_2 , V_23 , V_202 , 0 ) ;
}
}
static void F_120 ( struct V_1 * V_2 )
{
unsigned short V_202 ;
V_202 = V_75 | V_245 ;
if ( V_2 -> V_182 )
V_202 |= V_246 ;
F_15 ( V_202 , V_2 -> V_5 + 0x1A ) ;
F_2 ( V_202 , V_2 -> V_5 + V_74 ) ;
}
static int F_121 ( struct V_148 * V_16 )
{
struct V_209 * V_115 = F_122 ( V_16 ) ;
struct V_247 * V_15 = F_123 ( V_16 ) ;
struct V_1 * V_2 = V_15 -> V_20 ;
if ( ! V_2 -> V_248 )
return 0 ;
V_2 -> V_166 = 1 ;
F_124 ( & V_2 -> V_164 ) ;
F_125 ( V_15 , V_249 ) ;
F_126 ( V_2 -> V_147 ) ;
F_127 ( V_2 -> V_18 ) ;
F_27 ( V_2 ) ;
F_128 ( V_115 ) ;
F_129 ( V_115 ) ;
F_130 ( V_115 , V_250 ) ;
return 0 ;
}
static int F_131 ( struct V_148 * V_16 )
{
struct V_209 * V_115 = F_122 ( V_16 ) ;
struct V_247 * V_15 = F_123 ( V_16 ) ;
struct V_1 * V_2 = V_15 -> V_20 ;
struct V_43 * V_44 ;
if ( ! V_2 -> V_248 )
return 0 ;
F_130 ( V_115 , V_251 ) ;
F_132 ( V_115 ) ;
if ( F_133 ( V_115 ) < 0 ) {
F_69 ( V_16 , L_14 ) ;
F_134 ( V_15 ) ;
return - V_252 ;
}
F_135 ( V_115 ) ;
F_116 ( V_2 ) ;
if ( V_2 -> V_71 . V_60 ) {
F_25 ( V_2 , 0x01FC , V_2 -> V_71 . V_60 >> 12 ) ;
}
F_120 ( V_2 ) ;
F_136 ( V_2 -> V_18 ) ;
F_31 (es, &chip->substream_list, list) {
switch ( V_44 -> V_57 ) {
case V_86 :
F_42 ( V_2 , V_44 , V_44 -> V_83 -> V_46 ) ;
break;
case V_59 :
F_44 ( V_2 , V_44 , V_44 -> V_83 -> V_46 ) ;
break;
}
}
if ( V_2 -> V_40 )
F_28 ( V_2 ) ;
F_125 ( V_15 , V_253 ) ;
V_2 -> V_166 = 0 ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , int V_16 )
{
struct V_254 * V_255 ;
struct V_256 * V_257 ;
T_1 V_19 ;
if ( ! V_258 [ V_16 ] )
return - V_259 ;
V_257 = F_138 ( V_260 , 8 , L_15 ) ;
if ( ! V_257 )
return - V_123 ;
V_2 -> V_254 = V_255 = F_139 () ;
if ( ! V_255 ) {
F_69 ( V_2 -> V_15 -> V_16 ,
L_16 ) ;
F_140 ( V_257 ) ;
return - V_117 ;
}
F_112 ( V_2 -> V_115 , V_231 , & V_19 ) ;
F_117 ( V_2 -> V_115 , V_231 , V_19 | 0x04 ) ;
F_141 ( V_255 , L_17 ) ;
F_142 ( V_255 , L_18 , F_143 ( V_2 -> V_115 ) ) ;
F_144 ( V_255 , & V_2 -> V_115 -> V_16 ) ;
V_255 -> V_261 = V_260 ;
F_145 ( V_255 , V_257 ) ;
F_146 ( V_255 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 )
{
if ( V_2 -> V_254 ) {
struct V_256 * V_257 = F_148 ( V_2 -> V_254 ) ;
F_149 ( V_2 -> V_254 ) ;
V_2 -> V_254 = NULL ;
F_140 ( V_257 ) ;
}
}
static inline int F_137 ( struct V_1 * V_2 , int V_16 ) { return - V_262 ; }
static inline void F_147 ( struct V_1 * V_2 ) { }
static int F_150 ( struct V_1 * V_2 )
{
struct V_172 * V_172 ;
int V_113 ;
V_172 = F_151 () ;
if ( ! V_172 )
return - V_117 ;
snprintf ( V_2 -> V_263 , sizeof( V_2 -> V_263 ) , L_19 ,
F_143 ( V_2 -> V_115 ) ) ;
V_172 -> V_157 = V_2 -> V_15 -> V_264 ;
V_172 -> V_263 = V_2 -> V_263 ;
V_172 -> V_171 . V_265 = V_266 ;
V_172 -> V_171 . V_267 = V_2 -> V_115 -> V_267 ;
V_172 -> V_171 . V_268 = V_2 -> V_115 -> V_148 ;
V_172 -> V_16 . V_269 = & V_2 -> V_115 -> V_16 ;
F_152 ( V_270 , V_172 -> V_271 ) ;
F_152 ( V_173 , V_172 -> V_272 ) ;
F_152 ( V_175 , V_172 -> V_272 ) ;
F_152 ( V_174 , V_172 -> V_272 ) ;
V_113 = F_153 ( V_172 ) ;
if ( V_113 ) {
F_154 ( V_172 ) ;
return V_113 ;
}
V_2 -> V_172 = V_172 ;
return 0 ;
}
static void F_155 ( struct V_273 * V_274 , T_2 V_275 )
{
struct V_1 * V_2 = V_274 -> V_20 ;
struct V_276 V_277 = * F_156 ( V_2 ) ;
T_1 V_19 = 0 ;
V_19 |= ( V_275 & V_278 ) ? ( 1 << V_277 . V_4 ) : 0 ;
V_19 |= ( V_275 & V_279 ) ? ( 1 << V_277 . V_280 ) : 0 ;
V_19 |= ( V_275 & V_281 ) ? ( 1 << V_277 . V_282 ) : 0 ;
F_2 ( V_19 , V_2 -> V_5 + V_283 ) ;
}
static T_2 F_157 ( struct V_273 * V_274 )
{
struct V_1 * V_2 = V_274 -> V_20 ;
struct V_276 V_277 = * F_156 ( V_2 ) ;
T_1 V_19 = F_7 ( V_2 -> V_5 + V_283 ) ;
T_2 V_284 = 0 ;
if ( V_19 & ( 1 << V_277 . V_4 ) )
V_284 |= V_278 ;
if ( V_19 & ( 1 << V_277 . V_285 ) )
V_284 |= V_286 ;
return V_284 ;
}
static void F_158 ( struct V_273 * V_274 , bool V_287 )
{
struct V_1 * V_2 = V_274 -> V_20 ;
unsigned long V_261 = V_2 -> V_5 + V_283 ;
T_1 V_288 = F_7 ( V_261 + V_289 ) ;
struct V_276 V_277 = * F_156 ( V_2 ) ;
if ( V_287 ) {
F_2 ( ~ ( ( 1 << V_277 . V_4 ) | ( 1 << V_277 . V_280 ) | ( 1 << V_277 . V_282 ) ) ,
V_261 + V_290 ) ;
F_2 ( V_288 | ( 1 << V_277 . V_4 ) | ( 1 << V_277 . V_280 ) | ( 1 << V_277 . V_282 ) ,
V_261 + V_289 ) ;
} else {
F_2 ( ~ ( ( 1 << V_277 . V_280 ) | ( 1 << V_277 . V_282 ) | ( 1 << V_277 . V_4 ) | ( 1 << V_277 . V_285 ) ) ,
V_261 + V_290 ) ;
F_2 ( ( V_288 & ~ ( ( 1 << V_277 . V_4 ) | ( 1 << V_277 . V_285 ) ) )
| ( 1 << V_277 . V_280 ) | ( 1 << V_277 . V_282 ) , V_261 + V_289 ) ;
}
}
static int F_159 ( struct V_1 * V_2 )
{
F_124 ( & V_2 -> V_164 ) ;
#ifdef F_99
if ( V_2 -> V_172 )
F_160 ( V_2 -> V_172 ) ;
#endif
if ( V_2 -> V_5 ) {
if ( V_2 -> V_176 >= 0 )
F_161 ( V_2 -> V_176 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( 0 , V_2 -> V_5 + V_74 ) ;
}
#ifdef F_162
F_163 ( & V_2 -> V_274 ) ;
F_164 ( & V_2 -> V_291 ) ;
#endif
if ( V_2 -> V_176 >= 0 )
F_165 ( V_2 -> V_176 , V_2 ) ;
F_147 ( V_2 ) ;
F_166 ( V_2 -> V_115 ) ;
F_128 ( V_2 -> V_115 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
static int F_167 ( struct V_292 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_293 ;
return F_159 ( V_2 ) ;
}
static int F_168 ( struct V_247 * V_15 ,
struct V_209 * V_115 ,
int V_116 ,
int V_294 ,
int V_295 ,
int V_296 ,
int V_248 ,
int V_297 ,
struct V_1 * * V_298 )
{
static struct V_299 V_193 = {
. V_300 = F_167 ,
} ;
struct V_1 * V_2 ;
int V_23 , V_113 ;
* V_298 = NULL ;
if ( ( V_113 = F_133 ( V_115 ) ) < 0 )
return V_113 ;
if ( F_169 ( V_115 , F_170 ( 28 ) ) < 0 ||
F_171 ( V_115 , F_170 ( 28 ) ) < 0 ) {
F_69 ( V_15 -> V_16 ,
L_20 ) ;
F_128 ( V_115 ) ;
return - V_301 ;
}
V_2 = F_78 ( sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 ) {
F_128 ( V_115 ) ;
return - V_117 ;
}
V_2 -> type = V_296 ;
F_172 ( & V_2 -> V_10 ) ;
F_172 ( & V_2 -> V_88 ) ;
F_70 ( & V_2 -> V_109 ) ;
F_70 ( & V_2 -> V_130 ) ;
F_173 ( & V_2 -> V_99 ) ;
F_174 ( & V_2 -> V_164 , F_97 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_115 = V_115 ;
V_2 -> V_176 = - 1 ;
V_2 -> V_116 = V_116 ;
V_2 -> V_149 = V_294 ;
V_2 -> V_150 = V_295 ;
if ( ( V_113 = F_175 ( V_115 , L_11 ) ) < 0 ) {
F_63 ( V_2 ) ;
F_128 ( V_115 ) ;
return V_113 ;
}
V_2 -> V_5 = F_176 ( V_115 , 0 ) ;
if ( F_177 ( V_115 -> V_176 , F_105 , V_302 ,
V_303 , V_2 ) ) {
F_69 ( V_15 -> V_16 , L_21 , V_115 -> V_176 ) ;
F_159 ( V_2 ) ;
return - V_123 ;
}
V_2 -> V_176 = V_115 -> V_176 ;
for ( V_23 = 0 ; V_23 < 32 ; V_23 ++ )
V_2 -> V_8 [ V_23 ] = 0 ;
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ )
V_2 -> V_54 [ V_23 ] = V_122 ;
F_135 ( V_115 ) ;
if ( V_248 > 1 ) {
unsigned short V_203 ;
F_112 ( V_2 -> V_115 , V_204 , & V_203 ) ;
for ( V_23 = 0 ; V_23 < ( int ) F_178 ( V_304 ) ; V_23 ++ ) {
if ( V_2 -> type == V_304 [ V_23 ] . type &&
V_203 == V_304 [ V_23 ] . V_267 ) {
V_248 = 1 ;
break;
}
}
if ( V_248 > 1 ) {
F_89 ( V_15 -> V_16 , L_22 ) ;
V_248 = 0 ;
}
}
V_2 -> V_248 = V_248 ;
F_116 ( V_2 ) ;
if ( ( V_113 = F_179 ( V_15 , V_305 , V_2 , & V_193 ) ) < 0 ) {
F_159 ( V_2 ) ;
return V_113 ;
}
#ifdef F_162
if ( V_2 -> V_115 -> V_306 != 0x125d )
goto V_307;
V_113 = F_180 ( & V_115 -> V_16 , & V_2 -> V_291 ) ;
if ( V_113 < 0 ) {
F_159 ( V_2 ) ;
return V_113 ;
}
V_2 -> V_274 . V_291 = & V_2 -> V_291 ;
V_2 -> V_274 . V_20 = V_2 ;
V_2 -> V_274 . V_297 = V_297 ;
V_2 -> V_274 . V_193 = & V_308 ;
sprintf ( V_2 -> V_274 . V_309 , L_23 , F_143 ( V_115 ) ) ;
for ( V_23 = 0 ; V_23 < F_178 ( V_310 ) ; V_23 ++ ) {
V_2 -> V_311 = V_23 ;
if ( ! F_181 ( & V_2 -> V_274 , V_312 ) ) {
F_89 ( V_15 -> V_16 , L_24 ,
F_156 ( V_2 ) -> V_157 ) ;
F_182 ( V_2 -> V_274 . V_15 , F_156 ( V_2 ) -> V_157 ,
sizeof( V_2 -> V_274 . V_15 ) ) ;
break;
}
}
V_307:
#endif
* V_298 = V_2 ;
return 0 ;
}
static int F_183 ( struct V_209 * V_115 ,
const struct V_313 * V_314 )
{
static int V_16 ;
struct V_247 * V_15 ;
struct V_1 * V_2 ;
unsigned int V_23 ;
int V_113 ;
if ( V_16 >= V_315 )
return - V_259 ;
if ( ! V_316 [ V_16 ] ) {
V_16 ++ ;
return - V_317 ;
}
V_113 = F_184 ( & V_115 -> V_16 , V_22 [ V_16 ] , V_171 [ V_16 ] , V_312 ,
0 , & V_15 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_116 [ V_16 ] < 128 )
V_116 [ V_16 ] = 128 ;
if ( V_116 [ V_16 ] > 4096 )
V_116 [ V_16 ] = 4096 ;
if ( ( V_113 = F_168 ( V_15 , V_115 ,
V_116 [ V_16 ] * 1024 ,
V_318 [ V_16 ] ,
V_319 [ V_16 ] ,
V_314 -> V_320 ,
V_321 [ V_16 ] ,
V_297 [ V_16 ] ,
& V_2 ) ) < 0 ) {
F_185 ( V_15 ) ;
return V_113 ;
}
V_15 -> V_20 = V_2 ;
switch ( V_2 -> type ) {
case V_322 :
strcpy ( V_15 -> V_264 , L_25 ) ;
strcpy ( V_15 -> V_323 , L_26 ) ;
break;
case V_324 :
strcpy ( V_15 -> V_264 , L_27 ) ;
strcpy ( V_15 -> V_323 , L_28 ) ;
break;
case V_325 :
strcpy ( V_15 -> V_264 , L_29 ) ;
strcpy ( V_15 -> V_323 , L_30 ) ;
break;
}
if ( ( V_113 = F_91 ( V_2 , 0 ) ) < 0 ) {
F_185 ( V_15 ) ;
return V_113 ;
}
if ( ( V_113 = F_108 ( V_2 ) ) < 0 ) {
F_185 ( V_15 ) ;
return V_113 ;
}
if ( V_326 [ V_16 ] == 2 ) {
unsigned short V_203 ;
F_112 ( V_2 -> V_115 , V_204 , & V_203 ) ;
for ( V_23 = 0 ; V_23 < F_178 ( V_327 ) ; V_23 ++ ) {
if ( V_2 -> type == V_327 [ V_23 ] . type &&
V_203 == V_327 [ V_23 ] . V_267 ) {
V_326 [ V_16 ] = 0 ;
break;
}
}
}
if ( V_326 [ V_16 ] ) {
if ( ( V_113 = F_186 ( V_15 , 0 , V_328 ,
V_2 -> V_5 + V_329 ,
V_330 |
V_331 ,
- 1 , & V_2 -> V_182 ) ) < 0 ) {
F_86 ( V_15 -> V_16 , L_31 ) ;
}
}
F_137 ( V_2 , V_16 ) ;
#ifdef F_99
V_113 = F_150 ( V_2 ) ;
if ( V_113 )
F_86 ( V_15 -> V_16 ,
L_32 , V_113 ) ;
#endif
F_120 ( V_2 ) ;
V_2 -> clock = clock [ V_16 ] ;
if ( ! V_2 -> clock )
F_85 ( V_2 ) ;
sprintf ( V_15 -> V_332 , L_33 ,
V_15 -> V_323 , V_2 -> V_5 , V_2 -> V_176 ) ;
if ( ( V_113 = F_187 ( V_15 ) ) < 0 ) {
F_185 ( V_15 ) ;
return V_113 ;
}
F_188 ( V_115 , V_15 ) ;
V_16 ++ ;
return 0 ;
}
static void F_189 ( struct V_209 * V_115 )
{
F_185 ( F_190 ( V_115 ) ) ;
}
