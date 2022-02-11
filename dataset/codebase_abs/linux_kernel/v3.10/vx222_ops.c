static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
return V_5 -> V_6 [ V_7 [ V_3 ] ] + V_8 [ V_3 ] ;
}
static unsigned char F_2 ( struct V_1 * V_5 , int V_9 )
{
return F_3 ( F_1 ( V_5 , V_9 ) ) ;
}
static void F_4 ( struct V_1 * V_5 , int V_9 , unsigned char V_10 )
{
F_5 ( V_10 , F_1 ( V_5 , V_9 ) ) ;
}
static unsigned int F_6 ( struct V_1 * V_5 , int V_9 )
{
return F_7 ( F_1 ( V_5 , V_9 ) ) ;
}
static void F_8 ( struct V_1 * V_5 , int V_9 , unsigned int V_10 )
{
F_9 ( V_10 , F_1 ( V_5 , V_9 ) ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
F_11 ( V_5 , V_11 , V_5 -> V_12 & ~ V_13 ) ;
F_12 ( V_14 ) ;
V_5 -> V_12 |= V_13 ;
F_11 ( V_5 , V_11 , V_5 -> V_12 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
unsigned int V_15 ;
F_14 ( L_1 ) ;
F_11 ( V_5 , V_11 , V_5 -> V_12 | V_16 ) ;
F_15 ( V_5 , V_17 ) ;
V_15 = F_15 ( V_5 , V_18 ) ;
if ( ( V_15 & V_19 ) == V_19 ) {
F_14 ( L_2 ) ;
return - V_20 ;
}
F_11 ( V_5 , V_11 , V_5 -> V_12 & ~ V_16 ) ;
F_15 ( V_5 , V_17 ) ;
V_15 = F_15 ( V_5 , V_18 ) ;
if ( ! ( V_15 & V_19 ) ) {
F_14 ( L_3 ) ;
return - V_20 ;
}
if ( V_2 -> type == V_21 ) {
F_11 ( V_5 , V_11 , V_5 -> V_12 | V_22 ) ;
F_15 ( V_5 , V_17 ) ;
V_15 = F_15 ( V_5 , V_18 ) ;
if ( ( V_15 & V_23 ) == V_23 ) {
F_14 ( L_4 ) ;
return - V_20 ;
}
F_11 ( V_5 , V_11 , V_5 -> V_12 & ~ V_22 ) ;
F_15 ( V_5 , V_17 ) ;
V_15 = F_15 ( V_5 , V_18 ) ;
if ( ! ( V_15 & V_23 ) ) {
F_14 ( L_5 ) ;
return - V_20 ;
}
}
F_14 ( L_6 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_5 , int V_24 )
{
F_11 ( V_5 , V_25 , V_24 ? V_26 : V_27 ) ;
F_11 ( V_5 , V_28 , 0 ) ;
}
static inline void F_17 ( struct V_1 * V_5 )
{
F_11 ( V_5 , V_25 , 0 ) ;
}
static void F_18 ( struct V_1 * V_5 , struct V_29 * V_30 ,
struct V_31 * V_32 , int V_33 )
{
unsigned long V_6 = F_1 ( V_5 , V_34 ) ;
int V_9 = V_32 -> V_35 ;
T_1 * V_36 = ( T_1 * ) ( V_30 -> V_37 + V_9 ) ;
if ( F_19 ( V_33 % 4 ) )
return;
F_16 ( V_5 , 1 ) ;
if ( V_9 + V_33 > V_32 -> V_38 ) {
int V_39 = V_32 -> V_38 - V_9 ;
V_33 -= V_39 ;
V_39 >>= 2 ;
while ( V_39 -- > 0 ) {
F_9 ( F_20 ( * V_36 ) , V_6 ) ;
V_36 ++ ;
}
V_36 = ( T_1 * ) V_30 -> V_37 ;
V_32 -> V_35 = 0 ;
}
V_32 -> V_35 += V_33 ;
V_33 >>= 2 ;
while ( V_33 -- > 0 ) {
F_9 ( F_20 ( * V_36 ) , V_6 ) ;
V_36 ++ ;
}
F_17 ( V_5 ) ;
}
static void F_21 ( struct V_1 * V_5 , struct V_29 * V_30 ,
struct V_31 * V_32 , int V_33 )
{
int V_9 = V_32 -> V_35 ;
T_1 * V_36 = ( T_1 * ) ( V_30 -> V_37 + V_9 ) ;
unsigned long V_6 = F_1 ( V_5 , V_34 ) ;
if ( F_19 ( V_33 % 4 ) )
return;
F_16 ( V_5 , 0 ) ;
if ( V_9 + V_33 > V_32 -> V_38 ) {
int V_39 = V_32 -> V_38 - V_9 ;
V_33 -= V_39 ;
V_39 >>= 2 ;
while ( V_39 -- > 0 )
* V_36 ++ = F_22 ( F_7 ( V_6 ) ) ;
V_36 = ( T_1 * ) V_30 -> V_37 ;
V_32 -> V_35 = 0 ;
}
V_32 -> V_35 += V_33 ;
V_33 >>= 2 ;
while ( V_33 -- > 0 )
* V_36 ++ = F_22 ( F_7 ( V_6 ) ) ;
F_17 ( V_5 ) ;
}
static int F_23 ( struct V_1 * V_5 , unsigned int V_6 , unsigned int V_40 , unsigned char V_15 )
{
unsigned int V_41 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
unsigned int V_10 ;
V_10 = V_42 & ~ V_43 ;
F_8 ( V_5 , V_6 , V_10 ) ;
F_6 ( V_5 , V_6 ) ;
F_24 ( 1 ) ;
if ( V_15 & ( 1 << V_41 ) )
V_10 |= V_44 ;
else
V_10 &= ~ V_44 ;
F_8 ( V_5 , V_6 , V_10 ) ;
F_6 ( V_5 , V_6 ) ;
V_10 |= V_43 ;
F_8 ( V_5 , V_6 , V_10 ) ;
F_6 ( V_5 , V_6 ) ;
F_24 ( 1 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_5 , const struct V_45 * V_46 )
{
unsigned int V_41 ;
unsigned int V_6 ;
const unsigned char * V_47 ;
F_11 ( V_5 , V_48 , V_42 | V_49 ) ;
F_15 ( V_5 , V_48 ) ;
F_26 ( 10 ) ;
F_11 ( V_5 , V_48 , V_42 ) ;
F_15 ( V_5 , V_48 ) ;
F_26 ( 10 ) ;
if ( V_5 -> type == V_21 )
V_6 = V_50 ;
else
V_6 = V_51 ;
V_47 = V_46 -> V_15 ;
for ( V_41 = 0 ; V_41 < V_46 -> V_52 ; V_41 ++ , V_47 ++ ) {
if ( F_23 ( V_5 , V_6 , 8 , * V_47 ) < 0 )
return - V_53 ;
F_27 () ;
}
F_23 ( V_5 , V_6 , 4 , 0xff ) ;
F_26 ( 200 ) ;
if ( V_5 -> type != V_21 ) {
V_41 = F_15 ( V_5 , V_54 ) ;
if ( V_41 & 0x0100 )
return 0 ;
F_28 ( V_55 L_7 , V_41 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_56 , int V_57 , const struct V_45 * V_58 )
{
int V_59 ;
switch ( V_57 ) {
case 1 :
if ( ( V_59 = F_25 ( V_56 , V_58 ) ) < 0 )
return V_59 ;
if ( ( V_59 = F_13 ( V_56 ) ) < 0 )
return V_59 ;
return 0 ;
case 2 :
return F_30 ( V_56 , V_58 ) ;
case 3 :
return F_31 ( V_56 , V_58 ) ;
default:
F_32 () ;
return - V_53 ;
}
}
static int F_33 ( struct V_1 * V_5 )
{
if ( ! ( V_5 -> V_60 & V_61 ) )
return - V_62 ;
if ( ! ( F_15 ( V_5 , V_18 ) & V_63 ) )
return - V_64 ;
F_11 ( V_5 , V_18 , 0 ) ;
F_15 ( V_5 , V_18 ) ;
F_11 ( V_5 , V_18 , V_63 ) ;
F_15 ( V_5 , V_18 ) ;
F_11 ( V_5 , V_18 , 0 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 , int V_65 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
if ( V_65 ) {
F_11 ( V_5 , V_66 , V_67 | V_68 ) ;
V_5 -> V_12 |= V_69 ;
} else {
F_11 ( V_5 , V_66 , V_67 & ~ V_68 ) ;
V_5 -> V_12 &= ~ V_69 ;
}
F_11 ( V_5 , V_11 , V_5 -> V_12 ) ;
}
static void F_35 ( struct V_1 * V_5 , unsigned int V_15 )
{
unsigned int V_41 ;
F_15 ( V_5 , V_70 ) ;
for ( V_41 = 0 ; V_41 < 24 ; V_41 ++ , V_15 <<= 1 )
F_11 ( V_5 , V_71 , ( ( V_15 & 0x800000 ) ? V_72 : 0 ) ) ;
F_15 ( V_5 , V_73 ) ;
}
static void F_36 ( struct V_1 * V_5 , int V_3 , unsigned int V_15 )
{
unsigned int V_10 ;
if ( V_3 == V_74 ) {
F_35 ( V_5 , V_15 ? V_75 : V_76 ) ;
return;
}
if ( F_19 ( V_15 >= sizeof( V_77 ) ) )
return;
switch ( V_3 ) {
case V_78 :
V_10 = V_79 ;
break;
case V_80 :
V_10 = V_81 ;
break;
default:
F_32 () ;
return;
}
V_10 |= V_77 [ V_15 ] ;
F_35 ( V_5 , V_10 ) ;
}
static void F_37 ( struct V_1 * V_5 , int V_82 , unsigned int V_15 )
{
int V_41 ;
F_15 ( V_5 , V_70 ) ;
for ( V_41 = 0 ; V_41 < 24 ; V_41 ++ , V_15 <<= 1 )
F_11 ( V_5 , V_71 , ( ( V_15 & 0x800000 ) ? V_72 : 0 ) ) ;
F_15 ( V_5 , V_73 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
F_11 ( V_5 , V_11 , V_5 -> V_12 & ~ V_83 ) ;
F_15 ( V_5 , V_11 ) ;
F_26 ( 10 ) ;
V_5 -> V_12 |= V_83 ;
F_11 ( V_5 , V_11 , V_5 -> V_12 ) ;
F_15 ( V_5 , V_11 ) ;
if ( V_2 -> type == V_21 ) {
F_26 ( 1 ) ;
return;
}
F_26 ( 5 ) ;
F_35 ( V_2 , V_84 ) ;
F_35 ( V_2 , V_85 ) ;
F_35 ( V_2 , V_75 ) ;
F_35 ( V_2 , V_86 ) ;
if ( V_2 -> type == V_87 ) {
V_5 -> V_88 = V_89 |
V_90 |
V_91 ;
V_5 -> V_88 &= ~ V_92 ;
F_11 ( V_2 , V_93 , V_5 -> V_88 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , int V_94 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
switch ( V_94 ) {
case V_95 :
V_5 -> V_96 |= V_97 ;
break;
default:
V_5 -> V_96 &= ~ V_97 ;
break;
}
F_11 ( V_5 , V_98 , V_5 -> V_96 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_99 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
if ( V_99 == V_100 )
V_5 -> V_96 &= ~ V_101 ;
else
V_5 -> V_96 |= V_101 ;
F_11 ( V_5 , V_98 , V_5 -> V_96 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_102 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
V_5 -> V_12 = V_83 | V_13 ;
V_5 -> V_96 = 0 ;
}
static void F_42 ( struct V_4 * V_5 )
{
int V_41 , V_103 , V_104 ;
unsigned int V_15 ;
V_103 = V_5 -> V_105 ;
V_103 += V_106 ;
V_104 = 0 ;
while ( V_103 > 210 ) {
V_104 ++ ;
V_103 -= ( 18 * 2 ) ;
}
if ( F_19 ( V_104 >= 4 ) )
return;
V_5 -> V_88 &= ~ V_107 ;
V_5 -> V_88 |= ( V_104 << V_108 ) & V_107 ;
F_11 ( V_5 , V_93 , V_5 -> V_88 ) ;
V_15 = ( unsigned int ) V_103 << 16 |
( unsigned int ) V_5 -> V_109 [ 1 ] << 8 |
( unsigned int ) V_5 -> V_109 [ 0 ] ;
F_15 ( V_5 , V_71 ) ;
for ( V_41 = 0 ; V_41 < 32 ; V_41 ++ , V_15 <<= 1 )
F_11 ( V_5 , V_71 , ( ( V_15 & 0x80000000 ) ? V_72 : 0 ) ) ;
F_15 ( V_5 , V_73 ) ;
}
static int F_43 ( struct V_110 * V_111 , struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_33 = 2 ;
V_113 -> V_115 . integer . V_116 = 0 ;
V_113 -> V_115 . integer . V_117 = V_118 ;
return 0 ;
}
static int F_44 ( struct V_110 * V_111 , struct V_119 * V_120 )
{
struct V_1 * V_2 = F_45 ( V_111 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
F_46 ( & V_2 -> V_121 ) ;
V_120 -> V_115 . integer . V_115 [ 0 ] = V_5 -> V_109 [ 0 ] ;
V_120 -> V_115 . integer . V_115 [ 1 ] = V_5 -> V_109 [ 1 ] ;
F_47 ( & V_2 -> V_121 ) ;
return 0 ;
}
static int F_48 ( struct V_110 * V_111 , struct V_119 * V_120 )
{
struct V_1 * V_2 = F_45 ( V_111 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
if ( V_120 -> V_115 . integer . V_115 [ 0 ] < 0 ||
V_120 -> V_115 . integer . V_115 [ 0 ] > V_118 )
return - V_53 ;
if ( V_120 -> V_115 . integer . V_115 [ 1 ] < 0 ||
V_120 -> V_115 . integer . V_115 [ 1 ] > V_118 )
return - V_53 ;
F_46 ( & V_2 -> V_121 ) ;
if ( V_5 -> V_109 [ 0 ] != V_120 -> V_115 . integer . V_115 [ 0 ] ||
V_5 -> V_109 [ 1 ] != V_120 -> V_115 . integer . V_115 [ 1 ] ) {
V_5 -> V_109 [ 0 ] = V_120 -> V_115 . integer . V_115 [ 0 ] ;
V_5 -> V_109 [ 1 ] = V_120 -> V_115 . integer . V_115 [ 1 ] ;
F_42 ( V_5 ) ;
F_47 ( & V_2 -> V_121 ) ;
return 1 ;
}
F_47 ( & V_2 -> V_121 ) ;
return 0 ;
}
static int F_49 ( struct V_110 * V_111 , struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_33 = 1 ;
V_113 -> V_115 . integer . V_116 = 0 ;
V_113 -> V_115 . integer . V_117 = V_118 ;
return 0 ;
}
static int F_50 ( struct V_110 * V_111 , struct V_119 * V_120 )
{
struct V_1 * V_2 = F_45 ( V_111 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
V_120 -> V_115 . integer . V_115 [ 0 ] = V_5 -> V_105 ;
return 0 ;
}
static int F_51 ( struct V_110 * V_111 , struct V_119 * V_120 )
{
struct V_1 * V_2 = F_45 ( V_111 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
if ( V_120 -> V_115 . integer . V_115 [ 0 ] < 0 ||
V_120 -> V_115 . integer . V_115 [ 0 ] > V_118 )
return - V_53 ;
F_46 ( & V_2 -> V_121 ) ;
if ( V_5 -> V_105 != V_120 -> V_115 . integer . V_115 [ 0 ] ) {
V_5 -> V_105 = V_120 -> V_115 . integer . V_115 [ 0 ] ;
F_42 ( V_5 ) ;
F_47 ( & V_2 -> V_121 ) ;
return 1 ;
}
F_47 ( & V_2 -> V_121 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
int V_59 ;
if ( V_2 -> type != V_87 )
return 0 ;
V_5 -> V_109 [ 0 ] = V_5 -> V_109 [ 1 ] = 0 ;
V_5 -> V_105 = 0 ;
F_42 ( V_5 ) ;
if ( ( V_59 = F_53 ( V_2 -> V_122 , F_54 ( & V_123 , V_5 ) ) ) < 0 )
return V_59 ;
if ( ( V_59 = F_53 ( V_2 -> V_122 , F_54 ( & V_124 , V_5 ) ) ) < 0 )
return V_59 ;
return 0 ;
}
