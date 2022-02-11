static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 [ V_7 [ V_3 ] ] + V_8 [ V_3 ] ;
}
static unsigned char F_3 ( struct V_1 * V_5 , int V_9 )
{
return F_4 ( F_1 ( V_5 , V_9 ) ) ;
}
static void F_5 ( struct V_1 * V_5 , int V_9 , unsigned char V_10 )
{
F_6 ( V_10 , F_1 ( V_5 , V_9 ) ) ;
}
static unsigned int F_7 ( struct V_1 * V_5 , int V_9 )
{
return F_8 ( F_1 ( V_5 , V_9 ) ) ;
}
static void F_9 ( struct V_1 * V_5 , int V_9 , unsigned int V_10 )
{
F_10 ( V_10 , F_1 ( V_5 , V_9 ) ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( V_5 , V_11 , V_5 -> V_12 & ~ V_13 ) ;
F_13 ( V_14 ) ;
V_5 -> V_12 |= V_13 ;
F_12 ( V_5 , V_11 , V_5 -> V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_15 ;
F_15 ( V_2 -> V_16 -> V_17 , L_1 ) ;
F_12 ( V_5 , V_11 , V_5 -> V_12 | V_18 ) ;
F_16 ( V_5 , V_19 ) ;
V_15 = F_16 ( V_5 , V_20 ) ;
if ( ( V_15 & V_21 ) == V_21 ) {
F_15 ( V_2 -> V_16 -> V_17 , L_2 ) ;
return - V_22 ;
}
F_12 ( V_5 , V_11 , V_5 -> V_12 & ~ V_18 ) ;
F_16 ( V_5 , V_19 ) ;
V_15 = F_16 ( V_5 , V_20 ) ;
if ( ! ( V_15 & V_21 ) ) {
F_15 ( V_2 -> V_16 -> V_17 , L_3 ) ;
return - V_22 ;
}
if ( V_2 -> type == V_23 ) {
F_12 ( V_5 , V_11 , V_5 -> V_12 | V_24 ) ;
F_16 ( V_5 , V_19 ) ;
V_15 = F_16 ( V_5 , V_20 ) ;
if ( ( V_15 & V_25 ) == V_25 ) {
F_15 ( V_2 -> V_16 -> V_17 , L_4 ) ;
return - V_22 ;
}
F_12 ( V_5 , V_11 , V_5 -> V_12 & ~ V_24 ) ;
F_16 ( V_5 , V_19 ) ;
V_15 = F_16 ( V_5 , V_20 ) ;
if ( ! ( V_15 & V_25 ) ) {
F_15 ( V_2 -> V_16 -> V_17 , L_5 ) ;
return - V_22 ;
}
}
F_15 ( V_2 -> V_16 -> V_17 , L_6 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_5 , int V_26 )
{
F_12 ( V_5 , V_27 , V_26 ? V_28 : V_29 ) ;
F_12 ( V_5 , V_30 , 0 ) ;
}
static inline void F_18 ( struct V_1 * V_5 )
{
F_12 ( V_5 , V_27 , 0 ) ;
}
static void F_19 ( struct V_1 * V_5 , struct V_31 * V_32 ,
struct V_33 * V_34 , int V_35 )
{
unsigned long V_6 = F_1 ( V_5 , V_36 ) ;
int V_9 = V_34 -> V_37 ;
T_1 * V_38 = ( T_1 * ) ( V_32 -> V_39 + V_9 ) ;
if ( F_20 ( V_35 % 4 ) )
return;
F_17 ( V_5 , 1 ) ;
if ( V_9 + V_35 >= V_34 -> V_40 ) {
int V_41 = V_34 -> V_40 - V_9 ;
V_35 -= V_41 ;
V_41 >>= 2 ;
for (; V_41 > 0 ; V_41 -- ) {
F_10 ( F_21 ( * V_38 ) , V_6 ) ;
V_38 ++ ;
}
V_38 = ( T_1 * ) V_32 -> V_39 ;
V_34 -> V_37 = 0 ;
}
V_34 -> V_37 += V_35 ;
V_35 >>= 2 ;
for (; V_35 > 0 ; V_35 -- ) {
F_10 ( F_21 ( * V_38 ) , V_6 ) ;
V_38 ++ ;
}
F_18 ( V_5 ) ;
}
static void F_22 ( struct V_1 * V_5 , struct V_31 * V_32 ,
struct V_33 * V_34 , int V_35 )
{
int V_9 = V_34 -> V_37 ;
T_1 * V_38 = ( T_1 * ) ( V_32 -> V_39 + V_9 ) ;
unsigned long V_6 = F_1 ( V_5 , V_36 ) ;
if ( F_20 ( V_35 % 4 ) )
return;
F_17 ( V_5 , 0 ) ;
if ( V_9 + V_35 >= V_34 -> V_40 ) {
int V_41 = V_34 -> V_40 - V_9 ;
V_35 -= V_41 ;
V_41 >>= 2 ;
for (; V_41 > 0 ; V_41 -- )
* V_38 ++ = F_23 ( F_8 ( V_6 ) ) ;
V_38 = ( T_1 * ) V_32 -> V_39 ;
V_34 -> V_37 = 0 ;
}
V_34 -> V_37 += V_35 ;
V_35 >>= 2 ;
for (; V_35 > 0 ; V_35 -- )
* V_38 ++ = F_23 ( F_8 ( V_6 ) ) ;
F_18 ( V_5 ) ;
}
static int F_24 ( struct V_1 * V_5 , unsigned int V_6 , unsigned int V_42 , unsigned char V_15 )
{
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
unsigned int V_10 ;
V_10 = V_44 & ~ V_45 ;
F_9 ( V_5 , V_6 , V_10 ) ;
F_7 ( V_5 , V_6 ) ;
F_25 ( 1 ) ;
if ( V_15 & ( 1 << V_43 ) )
V_10 |= V_46 ;
else
V_10 &= ~ V_46 ;
F_9 ( V_5 , V_6 , V_10 ) ;
F_7 ( V_5 , V_6 ) ;
V_10 |= V_45 ;
F_9 ( V_5 , V_6 , V_10 ) ;
F_7 ( V_5 , V_6 ) ;
F_25 ( 1 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_5 , const struct V_47 * V_48 )
{
unsigned int V_43 ;
unsigned int V_6 ;
const unsigned char * V_49 ;
F_12 ( V_5 , V_50 , V_44 | V_51 ) ;
F_16 ( V_5 , V_50 ) ;
F_27 ( 10 ) ;
F_12 ( V_5 , V_50 , V_44 ) ;
F_16 ( V_5 , V_50 ) ;
F_27 ( 10 ) ;
if ( V_5 -> type == V_23 )
V_6 = V_52 ;
else
V_6 = V_53 ;
V_49 = V_48 -> V_15 ;
for ( V_43 = 0 ; V_43 < V_48 -> V_54 ; V_43 ++ , V_49 ++ ) {
if ( F_24 ( V_5 , V_6 , 8 , * V_49 ) < 0 )
return - V_55 ;
F_28 () ;
}
F_24 ( V_5 , V_6 , 4 , 0xff ) ;
F_27 ( 200 ) ;
if ( V_5 -> type != V_23 ) {
V_43 = F_16 ( V_5 , V_56 ) ;
if ( V_43 & 0x0100 )
return 0 ;
F_29 ( V_5 -> V_16 -> V_17 ,
L_7 , V_43 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_57 , int V_58 , const struct V_47 * V_59 )
{
int V_60 ;
switch ( V_58 ) {
case 1 :
if ( ( V_60 = F_26 ( V_57 , V_59 ) ) < 0 )
return V_60 ;
if ( ( V_60 = F_14 ( V_57 ) ) < 0 )
return V_60 ;
return 0 ;
case 2 :
return F_31 ( V_57 , V_59 ) ;
case 3 :
return F_32 ( V_57 , V_59 ) ;
default:
F_33 () ;
return - V_55 ;
}
}
static int F_34 ( struct V_1 * V_5 )
{
if ( ! ( V_5 -> V_61 & V_62 ) )
return - V_63 ;
if ( ! ( F_16 ( V_5 , V_20 ) & V_64 ) )
return - V_65 ;
F_12 ( V_5 , V_20 , 0 ) ;
F_16 ( V_5 , V_20 ) ;
F_12 ( V_5 , V_20 , V_64 ) ;
F_16 ( V_5 , V_20 ) ;
F_12 ( V_5 , V_20 , 0 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , int V_66 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_66 ) {
F_12 ( V_5 , V_67 , V_68 | V_69 ) ;
V_5 -> V_12 |= V_70 ;
} else {
F_12 ( V_5 , V_67 , V_68 & ~ V_69 ) ;
V_5 -> V_12 &= ~ V_70 ;
}
F_12 ( V_5 , V_11 , V_5 -> V_12 ) ;
}
static void F_36 ( struct V_1 * V_5 , unsigned int V_15 )
{
unsigned int V_43 ;
F_16 ( V_5 , V_71 ) ;
for ( V_43 = 0 ; V_43 < 24 ; V_43 ++ , V_15 <<= 1 )
F_12 ( V_5 , V_72 , ( ( V_15 & 0x800000 ) ? V_73 : 0 ) ) ;
F_16 ( V_5 , V_74 ) ;
}
static void F_37 ( struct V_1 * V_5 , int V_3 , unsigned int V_15 )
{
unsigned int V_10 ;
if ( V_3 == V_75 ) {
F_36 ( V_5 , V_15 ? V_76 : V_77 ) ;
return;
}
if ( F_20 ( V_15 >= sizeof( V_78 ) ) )
return;
switch ( V_3 ) {
case V_79 :
V_10 = V_80 ;
break;
case V_81 :
V_10 = V_82 ;
break;
default:
F_33 () ;
return;
}
V_10 |= V_78 [ V_15 ] ;
F_36 ( V_5 , V_10 ) ;
}
static void F_38 ( struct V_1 * V_5 , int V_83 , unsigned int V_15 )
{
int V_43 ;
F_16 ( V_5 , V_71 ) ;
for ( V_43 = 0 ; V_43 < 24 ; V_43 ++ , V_15 <<= 1 )
F_12 ( V_5 , V_72 , ( ( V_15 & 0x800000 ) ? V_73 : 0 ) ) ;
F_16 ( V_5 , V_74 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( V_5 , V_11 , V_5 -> V_12 & ~ V_84 ) ;
F_16 ( V_5 , V_11 ) ;
F_27 ( 10 ) ;
V_5 -> V_12 |= V_84 ;
F_12 ( V_5 , V_11 , V_5 -> V_12 ) ;
F_16 ( V_5 , V_11 ) ;
if ( V_2 -> type == V_23 ) {
F_27 ( 1 ) ;
return;
}
F_27 ( 5 ) ;
F_36 ( V_2 , V_85 ) ;
F_36 ( V_2 , V_86 ) ;
F_36 ( V_2 , V_76 ) ;
F_36 ( V_2 , V_87 ) ;
if ( V_2 -> type == V_88 ) {
V_5 -> V_89 = V_90 |
V_91 |
V_92 ;
V_5 -> V_89 &= ~ V_93 ;
F_12 ( V_2 , V_94 , V_5 -> V_89 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , int V_95 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_95 ) {
case V_96 :
V_5 -> V_97 |= V_98 ;
break;
default:
V_5 -> V_97 &= ~ V_98 ;
break;
}
F_12 ( V_5 , V_99 , V_5 -> V_97 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_100 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_100 == V_101 )
V_5 -> V_97 &= ~ V_102 ;
else
V_5 -> V_97 |= V_102 ;
F_12 ( V_5 , V_99 , V_5 -> V_97 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_103 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_12 = V_84 | V_13 ;
V_5 -> V_97 = 0 ;
}
static void F_43 ( struct V_4 * V_5 )
{
int V_43 , V_104 , V_105 ;
unsigned int V_15 ;
V_104 = V_5 -> V_106 ;
V_104 += V_107 ;
V_105 = 0 ;
while ( V_104 > 210 ) {
V_105 ++ ;
V_104 -= ( 18 * 2 ) ;
}
if ( F_20 ( V_105 >= 4 ) )
return;
V_5 -> V_89 &= ~ V_108 ;
V_5 -> V_89 |= ( V_105 << V_109 ) & V_108 ;
F_12 ( V_5 , V_94 , V_5 -> V_89 ) ;
V_15 = ( unsigned int ) V_104 << 16 |
( unsigned int ) V_5 -> V_110 [ 1 ] << 8 |
( unsigned int ) V_5 -> V_110 [ 0 ] ;
F_16 ( V_5 , V_72 ) ;
for ( V_43 = 0 ; V_43 < 32 ; V_43 ++ , V_15 <<= 1 )
F_12 ( V_5 , V_72 , ( ( V_15 & 0x80000000 ) ? V_73 : 0 ) ) ;
F_16 ( V_5 , V_74 ) ;
}
static int F_44 ( struct V_111 * V_112 , struct V_113 * V_114 )
{
V_114 -> type = V_115 ;
V_114 -> V_35 = 2 ;
V_114 -> V_116 . integer . V_117 = 0 ;
V_114 -> V_116 . integer . V_118 = V_119 ;
return 0 ;
}
static int F_45 ( struct V_111 * V_112 , struct V_120 * V_121 )
{
struct V_1 * V_2 = F_46 ( V_112 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_47 ( & V_2 -> V_122 ) ;
V_121 -> V_116 . integer . V_116 [ 0 ] = V_5 -> V_110 [ 0 ] ;
V_121 -> V_116 . integer . V_116 [ 1 ] = V_5 -> V_110 [ 1 ] ;
F_48 ( & V_2 -> V_122 ) ;
return 0 ;
}
static int F_49 ( struct V_111 * V_112 , struct V_120 * V_121 )
{
struct V_1 * V_2 = F_46 ( V_112 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_121 -> V_116 . integer . V_116 [ 0 ] < 0 ||
V_121 -> V_116 . integer . V_116 [ 0 ] > V_119 )
return - V_55 ;
if ( V_121 -> V_116 . integer . V_116 [ 1 ] < 0 ||
V_121 -> V_116 . integer . V_116 [ 1 ] > V_119 )
return - V_55 ;
F_47 ( & V_2 -> V_122 ) ;
if ( V_5 -> V_110 [ 0 ] != V_121 -> V_116 . integer . V_116 [ 0 ] ||
V_5 -> V_110 [ 1 ] != V_121 -> V_116 . integer . V_116 [ 1 ] ) {
V_5 -> V_110 [ 0 ] = V_121 -> V_116 . integer . V_116 [ 0 ] ;
V_5 -> V_110 [ 1 ] = V_121 -> V_116 . integer . V_116 [ 1 ] ;
F_43 ( V_5 ) ;
F_48 ( & V_2 -> V_122 ) ;
return 1 ;
}
F_48 ( & V_2 -> V_122 ) ;
return 0 ;
}
static int F_50 ( struct V_111 * V_112 , struct V_113 * V_114 )
{
V_114 -> type = V_115 ;
V_114 -> V_35 = 1 ;
V_114 -> V_116 . integer . V_117 = 0 ;
V_114 -> V_116 . integer . V_118 = V_119 ;
return 0 ;
}
static int F_51 ( struct V_111 * V_112 , struct V_120 * V_121 )
{
struct V_1 * V_2 = F_46 ( V_112 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_121 -> V_116 . integer . V_116 [ 0 ] = V_5 -> V_106 ;
return 0 ;
}
static int F_52 ( struct V_111 * V_112 , struct V_120 * V_121 )
{
struct V_1 * V_2 = F_46 ( V_112 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_121 -> V_116 . integer . V_116 [ 0 ] < 0 ||
V_121 -> V_116 . integer . V_116 [ 0 ] > V_119 )
return - V_55 ;
F_47 ( & V_2 -> V_122 ) ;
if ( V_5 -> V_106 != V_121 -> V_116 . integer . V_116 [ 0 ] ) {
V_5 -> V_106 = V_121 -> V_116 . integer . V_116 [ 0 ] ;
F_43 ( V_5 ) ;
F_48 ( & V_2 -> V_122 ) ;
return 1 ;
}
F_48 ( & V_2 -> V_122 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_60 ;
if ( V_2 -> type != V_88 )
return 0 ;
V_5 -> V_110 [ 0 ] = V_5 -> V_110 [ 1 ] = 0 ;
V_5 -> V_106 = 0 ;
F_43 ( V_5 ) ;
if ( ( V_60 = F_54 ( V_2 -> V_16 , F_55 ( & V_123 , V_5 ) ) ) < 0 )
return V_60 ;
if ( ( V_60 = F_54 ( V_2 -> V_16 , F_55 ( & V_124 , V_5 ) ) ) < 0 )
return V_60 ;
return 0 ;
}
