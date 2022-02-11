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
T_5 V_137 , V_138 ;
T_5 V_139 ;
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
V_137 = F_87 () ;
F_80 ( & V_2 -> V_10 ) ;
F_88 ( 50 ) ;
F_79 ( & V_2 -> V_10 ) ;
V_53 = F_23 ( V_2 , V_54 , 5 ) ;
V_138 = F_87 () ;
F_36 ( V_2 , V_54 , 0 ) ;
F_30 ( V_2 ) ;
V_2 -> V_141 = 0 ;
F_80 ( & V_2 -> V_10 ) ;
V_53 -= ( V_64 & 0xffff ) ;
V_53 &= 0xfffe ;
V_53 += V_2 -> V_143 * ( V_140 / 2 ) ;
V_139 = F_89 ( V_138 , V_137 ) ;
V_136 = F_90 ( V_139 ) ;
if ( V_136 == 0 ) {
F_69 ( V_2 -> V_15 -> V_16 , L_9 ) ;
} else {
V_53 *= 1000 ;
V_53 = ( V_53 / V_136 ) * 1000 + ( ( V_53 % V_136 ) * 1000 ) / V_136 ;
if ( V_53 < 47500 || V_53 > 48500 ) {
if ( V_53 >= 40000 && V_53 <= 50000 )
V_2 -> clock = ( V_2 -> clock * V_53 ) / 48000 ;
}
F_91 ( V_2 -> V_15 -> V_16 , L_10 , V_2 -> clock ) ;
}
F_60 ( V_2 , V_69 ) ;
F_76 ( V_2 , V_54 ) ;
}
static void F_92 ( struct V_144 * V_145 )
{
struct V_1 * V_56 = V_145 -> V_20 ;
F_64 ( V_56 ) ;
V_56 -> V_145 = NULL ;
}
static int
F_93 ( struct V_1 * V_2 , int V_146 )
{
struct V_144 * V_145 ;
int V_113 ;
if ( ( V_113 = F_66 ( V_2 ) ) < 0 )
return V_113 ;
F_25 ( V_2 , 0x01FC , V_2 -> V_71 . V_60 >> 12 ) ;
F_25 ( V_2 , 0x01FD , V_2 -> V_71 . V_60 >> 12 ) ;
F_25 ( V_2 , 0x01FE , V_2 -> V_71 . V_60 >> 12 ) ;
F_25 ( V_2 , 0x01FF , V_2 -> V_71 . V_60 >> 12 ) ;
if ( ( V_113 = F_94 ( V_2 -> V_15 , L_11 , V_146 ,
V_2 -> V_147 ,
V_2 -> V_148 , & V_145 ) ) < 0 )
return V_113 ;
V_145 -> V_20 = V_2 ;
V_145 -> V_149 = F_92 ;
F_95 ( V_145 , V_150 , & V_151 ) ;
F_95 ( V_145 , V_152 , & V_153 ) ;
V_145 -> V_154 = 0 ;
strcpy ( V_145 -> V_155 , L_11 ) ;
V_2 -> V_145 = V_145 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned int V_156 ;
unsigned int V_157 ;
unsigned int V_139 ;
V_156 = F_23 ( V_2 , 0 , 5 ) ;
V_157 = F_23 ( V_2 , 1 , 5 ) ;
V_139 = ( V_156 > V_157 ? V_156 - V_157 : V_157 - V_156 ) ;
if ( V_139 > 1 )
F_1 ( V_2 , V_25 , V_156 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned int V_93 ;
unsigned int V_139 ;
struct V_82 * V_158 = V_44 -> V_83 ;
if ( V_158 == NULL || ! V_44 -> V_91 )
return;
V_93 = F_34 ( V_2 , V_44 ) << V_44 -> V_68 ;
V_93 %= V_44 -> V_67 ;
V_139 = ( V_44 -> V_67 + V_93 - V_44 -> V_93 ) % V_44 -> V_67 ;
V_44 -> V_93 = V_93 ;
V_44 -> V_92 += V_139 ;
if ( V_44 -> V_92 > V_44 -> V_51 ) {
F_39 ( & V_2 -> V_88 ) ;
F_98 ( V_158 ) ;
F_38 ( & V_2 -> V_88 ) ;
V_44 -> V_92 %= V_44 -> V_51 ;
}
}
static void F_99 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = F_100 ( V_160 , struct V_1 , V_161 ) ;
int V_162 , V_19 ;
V_162 = F_10 ( V_2 -> V_5 + 0x1c ) & 0xee ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1c ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1d ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1e ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1f ) ;
if ( V_2 -> V_163 )
return;
#ifndef F_101
if ( ! V_2 -> V_164 || ! V_2 -> V_165 )
return;
V_19 = F_102 ( V_2 -> V_18 , V_166 ) ;
switch ( V_162 ) {
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
if ( F_103 ( V_2 -> V_18 , V_166 , V_19 ) )
F_104 ( V_2 -> V_15 , V_167 ,
& V_2 -> V_165 -> V_168 ) ;
#else
if ( ! V_2 -> V_169 )
return;
V_19 = 0 ;
switch ( V_162 ) {
case 0x88 :
V_19 = V_170 ;
break;
case 0xaa :
V_19 = V_171 ;
break;
case 0x66 :
V_19 = V_172 ;
break;
}
if ( V_19 ) {
F_105 ( V_2 -> V_169 , V_19 , 1 ) ;
F_106 ( V_2 -> V_169 ) ;
F_105 ( V_2 -> V_169 , V_19 , 0 ) ;
F_106 ( V_2 -> V_169 ) ;
}
#endif
}
static T_6 F_107 ( int V_173 , void * V_174 )
{
struct V_1 * V_2 = V_174 ;
T_3 V_175 ;
if ( ! ( V_175 = F_10 ( V_2 -> V_5 + 0x1A ) ) )
return V_176 ;
F_2 ( F_7 ( V_2 -> V_5 + 4 ) & 1 , V_2 -> V_5 + 4 ) ;
if ( V_175 & V_177 )
F_108 ( & V_2 -> V_161 ) ;
F_15 ( 0xFF , V_2 -> V_5 + 0x1A ) ;
if ( ( V_175 & V_178 ) && V_2 -> V_179 ) {
F_109 ( V_173 , V_2 -> V_179 -> V_20 ) ;
}
if ( V_175 & V_180 ) {
struct V_43 * V_44 ;
F_38 ( & V_2 -> V_88 ) ;
F_31 (es, &chip->substream_list, list) {
if ( V_44 -> V_91 ) {
F_97 ( V_2 , V_44 ) ;
if ( V_44 -> V_48 & V_49 )
F_96 ( V_2 , V_44 ) ;
}
}
F_39 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_141 ) {
unsigned int V_181 = F_23 ( V_2 , V_2 -> V_142 , 5 ) ;
if ( V_181 < V_2 -> V_182 )
V_2 -> V_143 ++ ;
V_2 -> V_182 = V_181 ;
}
}
return V_183 ;
}
static int
F_110 ( struct V_1 * V_2 )
{
struct V_184 * V_185 ;
struct V_186 V_18 ;
#ifndef F_101
struct V_187 V_188 ;
#endif
int V_113 ;
static struct V_189 V_190 = {
. V_191 = F_14 ,
. V_192 = F_16 ,
} ;
if ( ( V_113 = V_184 ( V_2 -> V_15 , 0 , & V_190 , NULL , & V_185 ) ) < 0 )
return V_113 ;
V_185 -> V_193 = 1 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_20 = V_2 ;
if ( ( V_113 = F_111 ( V_185 , & V_18 , & V_2 -> V_18 ) ) < 0 )
return V_113 ;
#ifndef F_101
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_194 = V_195 ;
strcpy ( V_188 . V_155 , L_12 ) ;
V_2 -> V_164 = F_112 ( V_2 -> V_15 , & V_188 ) ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_194 = V_195 ;
strcpy ( V_188 . V_155 , L_13 ) ;
V_2 -> V_165 = F_112 ( V_2 -> V_15 , & V_188 ) ;
#endif
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
unsigned long V_196 = V_2 -> V_5 ;
unsigned short V_197 ;
unsigned short V_198 ;
unsigned short V_199 ;
unsigned int V_200 ;
V_197 = F_7 ( V_196 + 0x36 ) ;
F_2 ( F_7 ( V_196 + 0x3a ) & 0xfffc , V_196 + 0x3a ) ;
F_2 ( F_7 ( V_196 + 0x3c ) & 0xfffc , V_196 + 0x3c ) ;
F_2 ( 0x0000 , V_196 + 0x36 ) ;
V_198 = F_7 ( V_196 + 0x68 ) ;
F_114 ( V_2 -> V_115 , 0x58 , & V_199 ) ;
F_115 ( V_2 -> V_115 , V_201 , & V_200 ) ;
if ( V_199 & 1 )
V_198 |= 0x10 ;
F_2 ( 0xfffe , V_196 + 0x64 ) ;
F_2 ( 0x0001 , V_196 + 0x68 ) ;
F_2 ( 0x0000 , V_196 + 0x60 ) ;
F_116 ( 20 ) ;
F_2 ( 0x0001 , V_196 + 0x60 ) ;
F_88 ( 20 ) ;
F_2 ( V_198 | 0x1 , V_196 + 0x68 ) ;
F_2 ( ( F_7 ( V_196 + 0x38 ) & 0xfffc ) | 0x1 , V_196 + 0x38 ) ;
F_2 ( ( F_7 ( V_196 + 0x3a ) & 0xfffc ) | 0x1 , V_196 + 0x3a ) ;
F_2 ( ( F_7 ( V_196 + 0x3c ) & 0xfffc ) | 0x1 , V_196 + 0x3c ) ;
F_2 ( 0x0000 , V_196 + 0x36 ) ;
F_2 ( 0xfff7 , V_196 + 0x64 ) ;
V_198 = F_7 ( V_196 + 0x68 ) ;
F_2 ( 0x0009 , V_196 + 0x68 ) ;
F_2 ( 0x0001 , V_196 + 0x60 ) ;
F_116 ( 20 ) ;
F_2 ( 0x0009 , V_196 + 0x60 ) ;
F_88 ( 500 ) ;
F_2 ( F_7 ( V_196 + 0x3a ) & 0xfffc , V_196 + 0x3a ) ;
F_2 ( F_7 ( V_196 + 0x3c ) & 0xfffc , V_196 + 0x3c ) ;
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
if ( V_200 == V_202 || V_200 == V_203 ) {
F_2 ( 0xf9ff , V_196 + 0x64 ) ;
F_2 ( F_7 ( V_196 + 0x68 ) | 0x600 , V_196 + 0x68 ) ;
F_2 ( 0x0209 , V_196 + 0x60 ) ;
}
F_2 ( V_197 , V_196 + 0x36 ) ;
F_15 ( F_10 ( V_196 + 0xc0 ) | ( 1 << 5 ) , V_196 + 0xc0 ) ;
F_15 ( 0xff , V_196 + 0xc3 ) ;
F_15 ( 0xff , V_196 + 0xc4 ) ;
F_15 ( 0xff , V_196 + 0xc6 ) ;
F_15 ( 0xff , V_196 + 0xc8 ) ;
F_15 ( 0x3f , V_196 + 0xcf ) ;
F_15 ( 0x3f , V_196 + 0xd0 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_2 ( V_204 | V_205 ,
V_2 -> V_5 + V_74 ) ;
F_116 ( 10 ) ;
F_2 ( 0x0000 , V_2 -> V_5 + V_74 ) ;
F_116 ( 10 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_206 * V_115 = V_2 -> V_115 ;
int V_23 ;
unsigned long V_207 = V_2 -> V_5 ;
T_1 V_199 ;
T_3 V_208 ;
F_114 ( V_115 , V_209 , & V_199 ) ;
V_199 &= ~ V_210 ;
V_199 &= ~ ( V_211 | V_212 ) ;
V_199 &= ~ V_213 ;
V_199 |= V_214 ;
V_199 |= V_215 ;
V_199 &= ~ V_216 ;
V_199 &= ~ V_217 ;
F_119 ( V_115 , V_209 , V_199 ) ;
F_114 ( V_115 , V_218 , & V_199 ) ;
V_199 &= ~ ( 1 << 15 ) ;
V_199 &= ~ ( 1 << 14 ) ;
V_199 &= ~ V_219 ;
V_199 |= V_220 ;
V_199 |= V_221 ;
V_199 &= ~ V_222 ;
V_199 |= V_223 ;
V_199 &= ~ V_224 ;
V_199 &= ~ V_225 ;
V_199 &= ~ ( 1 << 1 ) ;
V_199 &= ~ V_226 ;
F_119 ( V_115 , V_218 , V_199 ) ;
F_114 ( V_115 , V_227 , & V_199 ) ;
V_199 &= ~ ( 1 << 0 ) ;
F_119 ( V_115 , V_227 , V_199 ) ;
F_114 ( V_115 , V_228 , & V_199 ) ;
V_199 |= V_229 ;
V_199 &= ~ V_230 ;
V_199 &= ~ ( 0x1f ) ;
F_119 ( V_115 , V_228 , V_199 ) ;
F_114 ( V_115 , 0x58 , & V_199 ) ;
V_199 |= 1 << 2 ;
V_199 |= 1 << 3 ;
V_199 &= ~ ( 1 << 11 ) ;
F_119 ( V_115 , 0x58 , V_199 ) ;
F_117 ( V_2 ) ;
F_2 ( 0xC090 , V_207 + V_231 ) ;
F_116 ( 20 ) ;
F_2 ( 0x3000 , V_207 + V_232 ) ;
F_116 ( 20 ) ;
F_113 ( V_2 ) ;
V_208 = F_120 ( V_207 + V_233 ) ;
V_208 &= ~ V_234 ;
F_121 ( V_208 , V_207 + V_233 ) ;
F_15 ( 0x88 , V_207 + 0x1c ) ;
F_15 ( 0x88 , V_207 + 0x1d ) ;
F_15 ( 0x88 , V_207 + 0x1e ) ;
F_15 ( 0x88 , V_207 + 0x1f ) ;
F_15 ( 0 , V_207 + V_235 ) ;
F_15 ( 3 , V_207 + V_236 ) ;
F_15 ( 0 , V_207 + V_237 ) ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ ) {
F_2 ( 0x01E0 + V_23 , V_207 + V_31 ) ;
F_2 ( 0x0000 , V_207 + V_32 ) ;
F_2 ( 0x01D0 + V_23 , V_207 + V_31 ) ;
F_2 ( 0x0000 , V_207 + V_32 ) ;
}
F_25 ( V_2 , V_238 ,
( F_26 ( V_2 , V_238 ) & 0xFF00 ) ) ;
F_25 ( V_2 , V_238 ,
F_26 ( V_2 , V_238 ) | 0x100 ) ;
F_25 ( V_2 , V_238 ,
F_26 ( V_2 , V_238 ) & ~ 0x200 ) ;
F_25 ( V_2 , V_238 ,
F_26 ( V_2 , V_238 ) | ~ 0x400 ) ;
F_3 ( V_2 , V_239 , 0x0000 ) ;
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
V_199 = F_7 ( V_207 + V_240 ) ;
V_199 &= ~ 0xFA00 ;
V_199 |= 0xA000 ;
V_199 &= ~ 0x0200 ;
V_199 |= 0x0100 ;
V_199 |= 0x0080 ;
V_199 &= ~ 0x0060 ;
V_199 |= 0x0020 ;
V_199 &= ~ 0x000C ;
V_199 &= ~ 0x0001 ;
F_2 ( V_199 , V_207 + V_240 ) ;
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ ) {
for ( V_199 = 0 ; V_199 < V_241 ; V_199 ++ )
F_22 ( V_2 , V_23 , V_199 , 0 ) ;
}
}
static void F_122 ( struct V_1 * V_2 )
{
unsigned short V_199 ;
V_199 = V_75 | V_242 ;
if ( V_2 -> V_179 )
V_199 |= V_243 ;
F_15 ( V_199 , V_2 -> V_5 + 0x1A ) ;
F_2 ( V_199 , V_2 -> V_5 + V_74 ) ;
}
static int F_123 ( struct V_146 * V_16 )
{
struct V_244 * V_15 = F_124 ( V_16 ) ;
struct V_1 * V_2 = V_15 -> V_20 ;
if ( ! V_2 -> V_245 )
return 0 ;
V_2 -> V_163 = 1 ;
F_125 ( & V_2 -> V_161 ) ;
F_126 ( V_15 , V_246 ) ;
F_127 ( V_2 -> V_145 ) ;
F_128 ( V_2 -> V_18 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int F_129 ( struct V_146 * V_16 )
{
struct V_244 * V_15 = F_124 ( V_16 ) ;
struct V_1 * V_2 = V_15 -> V_20 ;
struct V_43 * V_44 ;
if ( ! V_2 -> V_245 )
return 0 ;
F_118 ( V_2 ) ;
if ( V_2 -> V_71 . V_60 ) {
F_25 ( V_2 , 0x01FC , V_2 -> V_71 . V_60 >> 12 ) ;
}
F_122 ( V_2 ) ;
F_130 ( V_2 -> V_18 ) ;
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
F_126 ( V_15 , V_247 ) ;
V_2 -> V_163 = 0 ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , int V_16 )
{
struct V_248 * V_249 ;
struct V_250 * V_251 ;
T_1 V_19 ;
if ( ! V_252 [ V_16 ] )
return - V_253 ;
V_251 = F_132 ( V_254 , 8 , L_14 ) ;
if ( ! V_251 )
return - V_123 ;
V_2 -> V_248 = V_249 = F_133 () ;
if ( ! V_249 ) {
F_69 ( V_2 -> V_15 -> V_16 ,
L_15 ) ;
F_134 ( V_251 ) ;
return - V_117 ;
}
F_114 ( V_2 -> V_115 , V_228 , & V_19 ) ;
F_119 ( V_2 -> V_115 , V_228 , V_19 | 0x04 ) ;
F_135 ( V_249 , L_16 ) ;
F_136 ( V_249 , L_17 , F_137 ( V_2 -> V_115 ) ) ;
F_138 ( V_249 , & V_2 -> V_115 -> V_16 ) ;
V_249 -> V_255 = V_254 ;
F_139 ( V_249 , V_251 ) ;
F_140 ( V_249 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_2 )
{
if ( V_2 -> V_248 ) {
struct V_250 * V_251 = F_142 ( V_2 -> V_248 ) ;
F_143 ( V_2 -> V_248 ) ;
V_2 -> V_248 = NULL ;
F_134 ( V_251 ) ;
}
}
static inline int F_131 ( struct V_1 * V_2 , int V_16 ) { return - V_256 ; }
static inline void F_141 ( struct V_1 * V_2 ) { }
static int F_144 ( struct V_1 * V_2 )
{
struct V_169 * V_169 ;
int V_113 ;
V_169 = F_145 () ;
if ( ! V_169 )
return - V_117 ;
snprintf ( V_2 -> V_257 , sizeof( V_2 -> V_257 ) , L_18 ,
F_137 ( V_2 -> V_115 ) ) ;
V_169 -> V_155 = V_2 -> V_15 -> V_258 ;
V_169 -> V_257 = V_2 -> V_257 ;
V_169 -> V_168 . V_259 = V_260 ;
V_169 -> V_168 . V_261 = V_2 -> V_115 -> V_261 ;
V_169 -> V_168 . V_262 = V_2 -> V_115 -> V_146 ;
V_169 -> V_16 . V_263 = & V_2 -> V_115 -> V_16 ;
F_146 ( V_264 , V_169 -> V_265 ) ;
F_146 ( V_170 , V_169 -> V_266 ) ;
F_146 ( V_172 , V_169 -> V_266 ) ;
F_146 ( V_171 , V_169 -> V_266 ) ;
V_113 = F_147 ( V_169 ) ;
if ( V_113 ) {
F_148 ( V_169 ) ;
return V_113 ;
}
V_2 -> V_169 = V_169 ;
return 0 ;
}
static void F_149 ( struct V_267 * V_268 , T_2 V_269 )
{
struct V_1 * V_2 = V_268 -> V_20 ;
struct V_270 V_271 = * F_150 ( V_2 ) ;
T_1 V_19 = 0 ;
V_19 |= ( V_269 & V_272 ) ? ( 1 << V_271 . V_4 ) : 0 ;
V_19 |= ( V_269 & V_273 ) ? ( 1 << V_271 . V_274 ) : 0 ;
V_19 |= ( V_269 & V_275 ) ? ( 1 << V_271 . V_276 ) : 0 ;
F_2 ( V_19 , V_2 -> V_5 + V_277 ) ;
}
static T_2 F_151 ( struct V_267 * V_268 )
{
struct V_1 * V_2 = V_268 -> V_20 ;
struct V_270 V_271 = * F_150 ( V_2 ) ;
T_1 V_19 = F_7 ( V_2 -> V_5 + V_277 ) ;
T_2 V_278 = 0 ;
if ( V_19 & ( 1 << V_271 . V_4 ) )
V_278 |= V_272 ;
if ( V_19 & ( 1 << V_271 . V_279 ) )
V_278 |= V_280 ;
return V_278 ;
}
static void F_152 ( struct V_267 * V_268 , bool V_281 )
{
struct V_1 * V_2 = V_268 -> V_20 ;
unsigned long V_255 = V_2 -> V_5 + V_277 ;
T_1 V_282 = F_7 ( V_255 + V_283 ) ;
struct V_270 V_271 = * F_150 ( V_2 ) ;
if ( V_281 ) {
F_2 ( ~ ( ( 1 << V_271 . V_4 ) | ( 1 << V_271 . V_274 ) | ( 1 << V_271 . V_276 ) ) ,
V_255 + V_284 ) ;
F_2 ( V_282 | ( 1 << V_271 . V_4 ) | ( 1 << V_271 . V_274 ) | ( 1 << V_271 . V_276 ) ,
V_255 + V_283 ) ;
} else {
F_2 ( ~ ( ( 1 << V_271 . V_274 ) | ( 1 << V_271 . V_276 ) | ( 1 << V_271 . V_4 ) | ( 1 << V_271 . V_279 ) ) ,
V_255 + V_284 ) ;
F_2 ( ( V_282 & ~ ( ( 1 << V_271 . V_4 ) | ( 1 << V_271 . V_279 ) ) )
| ( 1 << V_271 . V_274 ) | ( 1 << V_271 . V_276 ) , V_255 + V_283 ) ;
}
}
static int F_153 ( struct V_1 * V_2 )
{
F_125 ( & V_2 -> V_161 ) ;
#ifdef F_101
if ( V_2 -> V_169 )
F_154 ( V_2 -> V_169 ) ;
#endif
if ( V_2 -> V_5 ) {
if ( V_2 -> V_173 >= 0 )
F_155 ( V_2 -> V_173 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( 0 , V_2 -> V_5 + V_74 ) ;
}
#ifdef F_156
F_157 ( & V_2 -> V_268 ) ;
F_158 ( & V_2 -> V_285 ) ;
#endif
if ( V_2 -> V_173 >= 0 )
F_159 ( V_2 -> V_173 , V_2 ) ;
F_141 ( V_2 ) ;
F_160 ( V_2 -> V_115 ) ;
F_161 ( V_2 -> V_115 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
static int F_162 ( struct V_286 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_287 ;
return F_153 ( V_2 ) ;
}
static int F_163 ( struct V_244 * V_15 ,
struct V_206 * V_115 ,
int V_116 ,
int V_288 ,
int V_289 ,
int V_290 ,
int V_245 ,
int V_291 ,
struct V_1 * * V_292 )
{
static struct V_293 V_190 = {
. V_294 = F_162 ,
} ;
struct V_1 * V_2 ;
int V_23 , V_113 ;
* V_292 = NULL ;
if ( ( V_113 = F_164 ( V_115 ) ) < 0 )
return V_113 ;
if ( F_165 ( V_115 , F_166 ( 28 ) ) < 0 ||
F_167 ( V_115 , F_166 ( 28 ) ) < 0 ) {
F_69 ( V_15 -> V_16 ,
L_19 ) ;
F_161 ( V_115 ) ;
return - V_295 ;
}
V_2 = F_78 ( sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 ) {
F_161 ( V_115 ) ;
return - V_117 ;
}
V_2 -> type = V_290 ;
F_168 ( & V_2 -> V_10 ) ;
F_168 ( & V_2 -> V_88 ) ;
F_70 ( & V_2 -> V_109 ) ;
F_70 ( & V_2 -> V_130 ) ;
F_169 ( & V_2 -> V_99 ) ;
F_170 ( & V_2 -> V_161 , F_99 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_115 = V_115 ;
V_2 -> V_173 = - 1 ;
V_2 -> V_116 = V_116 ;
V_2 -> V_147 = V_288 ;
V_2 -> V_148 = V_289 ;
if ( ( V_113 = F_171 ( V_115 , L_11 ) ) < 0 ) {
F_63 ( V_2 ) ;
F_161 ( V_115 ) ;
return V_113 ;
}
V_2 -> V_5 = F_172 ( V_115 , 0 ) ;
if ( F_173 ( V_115 -> V_173 , F_107 , V_296 ,
V_297 , V_2 ) ) {
F_69 ( V_15 -> V_16 , L_20 , V_115 -> V_173 ) ;
F_153 ( V_2 ) ;
return - V_123 ;
}
V_2 -> V_173 = V_115 -> V_173 ;
for ( V_23 = 0 ; V_23 < 32 ; V_23 ++ )
V_2 -> V_8 [ V_23 ] = 0 ;
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ )
V_2 -> V_54 [ V_23 ] = V_122 ;
F_174 ( V_115 ) ;
if ( V_245 > 1 ) {
unsigned short V_200 ;
F_114 ( V_2 -> V_115 , V_201 , & V_200 ) ;
for ( V_23 = 0 ; V_23 < ( int ) F_175 ( V_298 ) ; V_23 ++ ) {
if ( V_2 -> type == V_298 [ V_23 ] . type &&
V_200 == V_298 [ V_23 ] . V_261 ) {
V_245 = 1 ;
break;
}
}
if ( V_245 > 1 ) {
F_91 ( V_15 -> V_16 , L_21 ) ;
V_245 = 0 ;
}
}
V_2 -> V_245 = V_245 ;
F_118 ( V_2 ) ;
if ( ( V_113 = F_176 ( V_15 , V_299 , V_2 , & V_190 ) ) < 0 ) {
F_153 ( V_2 ) ;
return V_113 ;
}
#ifdef F_156
if ( V_2 -> V_115 -> V_300 != 0x125d )
goto V_301;
V_113 = F_177 ( & V_115 -> V_16 , & V_2 -> V_285 ) ;
if ( V_113 < 0 ) {
F_153 ( V_2 ) ;
return V_113 ;
}
V_2 -> V_268 . V_285 = & V_2 -> V_285 ;
V_2 -> V_268 . V_20 = V_2 ;
V_2 -> V_268 . V_291 = V_291 ;
V_2 -> V_268 . V_190 = & V_302 ;
sprintf ( V_2 -> V_268 . V_303 , L_22 , F_137 ( V_115 ) ) ;
for ( V_23 = 0 ; V_23 < F_175 ( V_304 ) ; V_23 ++ ) {
V_2 -> V_305 = V_23 ;
if ( ! F_178 ( & V_2 -> V_268 , V_306 ) ) {
F_91 ( V_15 -> V_16 , L_23 ,
F_150 ( V_2 ) -> V_155 ) ;
F_179 ( V_2 -> V_268 . V_15 , F_150 ( V_2 ) -> V_155 ,
sizeof( V_2 -> V_268 . V_15 ) ) ;
break;
}
}
V_301:
#endif
* V_292 = V_2 ;
return 0 ;
}
static int F_180 ( struct V_206 * V_115 ,
const struct V_307 * V_308 )
{
static int V_16 ;
struct V_244 * V_15 ;
struct V_1 * V_2 ;
unsigned int V_23 ;
int V_113 ;
if ( V_16 >= V_309 )
return - V_253 ;
if ( ! V_310 [ V_16 ] ) {
V_16 ++ ;
return - V_311 ;
}
V_113 = F_181 ( & V_115 -> V_16 , V_22 [ V_16 ] , V_168 [ V_16 ] , V_306 ,
0 , & V_15 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_116 [ V_16 ] < 128 )
V_116 [ V_16 ] = 128 ;
if ( V_116 [ V_16 ] > 4096 )
V_116 [ V_16 ] = 4096 ;
if ( ( V_113 = F_163 ( V_15 , V_115 ,
V_116 [ V_16 ] * 1024 ,
V_312 [ V_16 ] ,
V_313 [ V_16 ] ,
V_308 -> V_314 ,
V_315 [ V_16 ] ,
V_291 [ V_16 ] ,
& V_2 ) ) < 0 ) {
F_182 ( V_15 ) ;
return V_113 ;
}
V_15 -> V_20 = V_2 ;
switch ( V_2 -> type ) {
case V_316 :
strcpy ( V_15 -> V_258 , L_24 ) ;
strcpy ( V_15 -> V_317 , L_25 ) ;
break;
case V_318 :
strcpy ( V_15 -> V_258 , L_26 ) ;
strcpy ( V_15 -> V_317 , L_27 ) ;
break;
case V_319 :
strcpy ( V_15 -> V_258 , L_28 ) ;
strcpy ( V_15 -> V_317 , L_29 ) ;
break;
}
if ( ( V_113 = F_93 ( V_2 , 0 ) ) < 0 ) {
F_182 ( V_15 ) ;
return V_113 ;
}
if ( ( V_113 = F_110 ( V_2 ) ) < 0 ) {
F_182 ( V_15 ) ;
return V_113 ;
}
if ( V_320 [ V_16 ] == 2 ) {
unsigned short V_200 ;
F_114 ( V_2 -> V_115 , V_201 , & V_200 ) ;
for ( V_23 = 0 ; V_23 < F_175 ( V_321 ) ; V_23 ++ ) {
if ( V_2 -> type == V_321 [ V_23 ] . type &&
V_200 == V_321 [ V_23 ] . V_261 ) {
V_320 [ V_16 ] = 0 ;
break;
}
}
}
if ( V_320 [ V_16 ] ) {
if ( ( V_113 = F_183 ( V_15 , 0 , V_322 ,
V_2 -> V_5 + V_323 ,
V_324 |
V_325 ,
- 1 , & V_2 -> V_179 ) ) < 0 ) {
F_86 ( V_15 -> V_16 , L_30 ) ;
}
}
F_131 ( V_2 , V_16 ) ;
#ifdef F_101
V_113 = F_144 ( V_2 ) ;
if ( V_113 )
F_86 ( V_15 -> V_16 ,
L_31 , V_113 ) ;
#endif
F_122 ( V_2 ) ;
V_2 -> clock = clock [ V_16 ] ;
if ( ! V_2 -> clock )
F_85 ( V_2 ) ;
sprintf ( V_15 -> V_326 , L_32 ,
V_15 -> V_317 , V_2 -> V_5 , V_2 -> V_173 ) ;
if ( ( V_113 = F_184 ( V_15 ) ) < 0 ) {
F_182 ( V_15 ) ;
return V_113 ;
}
F_185 ( V_115 , V_15 ) ;
V_16 ++ ;
return 0 ;
}
static void F_186 ( struct V_206 * V_115 )
{
F_182 ( F_187 ( V_115 ) ) ;
}
