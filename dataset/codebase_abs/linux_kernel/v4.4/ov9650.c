static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & F_2 ( V_3 -> V_4 , struct V_5 , V_6 . V_4 ) -> V_7 ;
}
static inline struct V_5 * F_3 ( struct V_1 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
static int F_4 ( struct V_8 * V_9 , T_1 V_10 , T_1 * V_11 )
{
T_1 V_12 = V_10 ;
struct V_13 V_14 = {
. V_10 = V_9 -> V_10 ,
. V_15 = 0 ,
. V_16 = 1 ,
. V_12 = & V_12
} ;
int V_17 ;
V_17 = F_5 ( V_9 -> V_18 , & V_14 , 1 ) ;
if ( V_17 == 1 ) {
V_14 . V_15 = V_19 ;
V_17 = F_5 ( V_9 -> V_18 , & V_14 , 1 ) ;
if ( V_17 == 1 )
* V_11 = V_12 ;
}
F_6 ( 2 , V_20 , V_9 , L_1 ,
V_21 , * V_11 , V_10 , V_17 ) ;
return V_17 == 1 ? 0 : V_17 ;
}
static int F_7 ( struct V_8 * V_9 , T_1 V_10 , T_1 V_11 )
{
T_1 V_12 [ 2 ] = { V_10 , V_11 } ;
int V_17 = F_8 ( V_9 , V_12 , 2 ) ;
F_6 ( 2 , V_20 , V_9 , L_2 ,
V_21 , V_11 , V_10 , V_17 ) ;
return V_17 == 2 ? 0 : V_17 ;
}
static int F_9 ( struct V_8 * V_9 ,
const struct V_22 * V_23 )
{
int V_24 , V_17 = 0 ;
for ( V_24 = 0 ; V_17 == 0 && V_23 [ V_24 ] . V_10 != V_25 ; V_24 ++ )
V_17 = F_7 ( V_9 , V_23 [ V_24 ] . V_10 , V_23 [ V_24 ] . V_26 ) ;
return V_17 ;
}
static int F_10 ( struct V_5 * V_5 )
{
static const T_1 V_27 [] = {
0x40 , 0x30 , 0x4b , 0x60 , 0x70 , 0x70 , 0x70 , 0x70 ,
0x60 , 0x60 , 0x50 , 0x48 , 0x3a , 0x2e , 0x28 , 0x22 ,
0x04 , 0x07 , 0x10 , 0x28 , 0x36 , 0x44 , 0x52 , 0x60 ,
0x6c , 0x78 , 0x8c , 0x9e , 0xbb , 0xd2 , 0xe6
} ;
T_1 V_10 = V_28 ;
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < F_11 ( V_27 ) ; V_24 ++ ) {
int V_17 = F_7 ( V_5 -> V_9 , V_10 , V_27 [ V_24 ] ) ;
if ( V_17 < 0 )
return V_17 ;
V_10 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_5 * V_5 )
{
static const T_1 V_29 [] = {
0x3a , 0x3d , 0x03 , 0x12 , 0x26 , 0x38 , 0x40 , 0x40 , 0x40 , 0x0d
} ;
T_1 V_10 = F_13 ( 1 ) ;
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < F_11 ( V_29 ) ; V_24 ++ ) {
int V_17 = F_7 ( V_5 -> V_9 , V_10 , V_29 [ V_24 ] ) ;
if ( V_17 < 0 )
return V_17 ;
V_10 ++ ;
}
return 0 ;
}
static void F_14 ( int V_30 , int V_11 )
{
if ( F_15 ( V_30 ) )
F_16 ( V_30 , V_11 ) ;
}
static void F_17 ( struct V_5 * V_5 , int V_31 )
{
if ( V_31 ) {
F_14 ( V_5 -> V_32 [ V_33 ] , 0 ) ;
F_14 ( V_5 -> V_32 [ V_34 ] , 0 ) ;
F_18 ( 25000 , 26000 ) ;
} else {
F_14 ( V_5 -> V_32 [ V_34 ] , 1 ) ;
F_14 ( V_5 -> V_32 [ V_33 ] , 1 ) ;
}
V_5 -> V_35 = 0 ;
}
static int F_19 ( struct V_1 * V_7 , int V_31 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_8 * V_9 = V_5 -> V_9 ;
int V_17 = 0 ;
F_6 ( 1 , V_20 , V_9 , L_3 , V_21 , V_31 ) ;
F_20 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_37 == ! V_31 ) {
F_17 ( V_5 , V_31 ) ;
if ( V_31 ) {
V_17 = F_9 ( V_9 ,
V_38 ) ;
V_5 -> V_39 = 1 ;
V_5 -> V_6 . V_40 = 1 ;
}
}
if ( ! V_17 )
V_5 -> V_37 += V_31 ? 1 : - 1 ;
F_21 ( V_5 -> V_37 < 0 ) ;
F_22 ( & V_5 -> V_36 ) ;
return V_17 ;
}
static void F_23 ( struct V_5 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_6 . V_41 ;
unsigned long V_42 , V_43 ;
int V_44 , V_45 , V_46 ;
T_1 V_47 ;
F_20 ( & V_5 -> V_36 ) ;
if ( F_21 ( ! V_3 || ! V_5 -> V_48 ) ) {
F_22 ( & V_5 -> V_36 ) ;
return;
}
V_47 = V_49 + V_5 -> V_50 -> V_51 ;
V_42 = V_5 -> V_52 * ( ( V_47 >> 7 ) + 1 ) /
( ( 2 * ( ( V_47 & 0x3f ) + 1 ) ) ) ;
V_43 = ( 2 * 1520 * 1000000UL ) / V_42 ;
V_45 = V_5 -> V_48 -> V_53 * V_43 ;
V_5 -> V_54 = V_43 ;
F_22 ( & V_5 -> V_36 ) ;
F_6 ( 1 , V_20 , & V_5 -> V_7 , L_4 ,
V_47 , V_42 , V_43 , V_45 ) ;
V_44 = ( V_43 + 100 ) / 100 ;
V_45 = ( V_45 - 100 ) / 100 ;
V_46 = V_44 + ( V_45 - V_44 ) / 2 ;
if ( F_24 ( V_3 , V_44 , V_45 , 1 , V_46 ) )
F_25 ( & V_5 -> V_7 , L_5 ) ;
}
static int F_26 ( struct V_5 * V_5 , int V_26 )
{
unsigned long V_55 , V_56 ;
int V_17 ;
T_1 V_57 ;
V_17 = F_4 ( V_5 -> V_9 , V_58 , & V_57 ) ;
if ( ! V_17 ) {
if ( V_26 == V_59 )
V_57 &= ~ V_60 ;
else
V_57 |= V_60 ;
V_17 = F_7 ( V_5 -> V_9 , V_58 , V_57 ) ;
}
if ( V_26 == V_59 )
return 0 ;
if ( F_21 ( V_5 -> V_50 == NULL ) )
return - V_61 ;
if ( V_26 == V_62 )
V_56 = 50 ;
else
V_56 = 60 ;
V_55 = ( 1000UL * V_5 -> V_50 -> V_63 . V_64 *
V_5 -> V_48 -> V_53 ) /
V_5 -> V_50 -> V_63 . V_65 ;
V_55 = ( ( V_55 / ( V_56 * 2 ) ) + 500 ) / 1000UL ;
return F_7 ( V_5 -> V_9 , V_66 , V_55 ) ;
}
static int F_27 ( struct V_5 * V_5 , int V_67 )
{
int V_17 ;
T_1 V_57 ;
V_17 = F_4 ( V_5 -> V_9 , V_58 , & V_57 ) ;
if ( ! V_17 ) {
V_57 = V_67 ? V_57 | V_58 : V_57 & ~ V_58 ;
V_17 = F_7 ( V_5 -> V_9 , V_58 , V_57 ) ;
}
if ( ! V_17 && ! V_67 ) {
V_17 = F_7 ( V_5 -> V_9 , V_68 ,
V_5 -> V_6 . V_69 -> V_11 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_7 ( V_5 -> V_9 , V_70 ,
V_5 -> V_6 . V_71 -> V_11 ) ;
}
return V_17 ;
}
static int F_28 ( struct V_5 * V_5 , int V_11 )
{
static const T_1 V_23 [ V_72 + 1 ] [ V_73 ] = {
{ V_74 , V_75 , V_76 } ,
{ 0x1c , 0x12 , 0x50 } ,
{ 0x3d , 0x30 , 0x71 } ,
{ 0x50 , 0x44 , 0x92 } ,
{ 0x70 , 0x64 , 0xc3 } ,
{ 0x90 , 0x84 , 0xd4 } ,
{ 0xc4 , 0xbf , 0xf9 } ,
{ 0xd8 , 0xd0 , 0xfa } ,
} ;
int V_24 , V_17 = 0 ;
V_11 += ( V_72 / 2 + 1 ) ;
if ( V_11 > V_72 )
return - V_61 ;
for ( V_24 = 0 ; V_24 < V_73 && ! V_17 ; V_24 ++ )
V_17 = F_7 ( V_5 -> V_9 , V_23 [ 0 ] [ V_24 ] ,
V_23 [ V_11 ] [ V_24 ] ) ;
return V_17 ;
}
static int F_29 ( struct V_5 * V_5 , int V_77 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
struct V_78 * V_6 = & V_5 -> V_6 ;
int V_17 = 0 ;
T_1 V_57 ;
if ( V_6 -> V_77 -> V_79 ) {
V_17 = F_4 ( V_9 , V_58 , & V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_6 -> V_77 -> V_11 )
V_57 |= V_80 ;
else
V_57 &= ~ V_80 ;
V_17 = F_7 ( V_9 , V_58 , V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_6 -> V_81 -> V_79 && ! V_77 ) {
unsigned int V_81 = V_6 -> V_81 -> V_11 ;
unsigned int V_82 ;
int V_83 ;
for ( V_83 = 6 ; V_83 >= 0 ; V_83 -- )
if ( V_81 >= ( 1 << V_83 ) * 16 )
break;
V_82 = ( V_81 - ( ( 1 << V_83 ) * 16 ) ) / ( 1 << V_83 ) ;
V_82 |= ( ( ( 1 << V_83 ) - 1 ) << 4 ) ;
V_17 = F_7 ( V_9 , V_84 , V_82 & 0xff ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_4 ( V_9 , V_85 , & V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
V_57 &= ~ V_86 ;
V_57 |= ( ( ( V_82 >> 8 ) & 0x3 ) << 6 ) ;
V_17 = F_7 ( V_9 , V_85 , V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
V_6 -> V_81 -> V_11 = ( 1 << V_83 ) * ( 16 + ( V_82 & 0xf ) ) ;
}
return V_17 ;
}
static int F_30 ( struct V_5 * V_5 , unsigned int V_26 )
{
T_1 V_87 , V_88 ;
int V_17 ;
V_17 = F_4 ( V_5 -> V_9 , V_89 , & V_87 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_4 ( V_5 -> V_9 , V_90 , & V_88 ) ;
if ( V_17 < 0 )
return V_17 ;
V_87 = V_26 ? V_87 | V_91 : V_87 & ~ V_91 ;
V_26 -- ;
if ( V_26 > 0x0f ) {
V_87 |= V_92 ;
V_26 >>= 1 ;
} else {
V_87 &= ~ V_92 ;
}
V_17 = F_7 ( V_5 -> V_9 , V_89 , V_87 ) ;
if ( V_17 < 0 )
return V_17 ;
V_88 &= ~ V_93 ;
V_88 |= ( ( T_1 ) V_26 & 0x0f ) ;
return F_7 ( V_5 -> V_9 , V_90 , V_88 ) ;
}
static int F_31 ( struct V_5 * V_5 , int exp )
{
struct V_8 * V_9 = V_5 -> V_9 ;
struct V_78 * V_6 = & V_5 -> V_6 ;
bool V_94 = ( exp == V_95 ) ;
int V_17 ;
T_1 V_57 ;
if ( V_6 -> V_96 -> V_79 ) {
V_17 = F_4 ( V_9 , V_58 , & V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_94 )
V_57 |= ( V_97 | V_80 ) ;
else
V_57 &= ~ ( V_97 | V_80 ) ;
V_17 = F_7 ( V_9 , V_58 , V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( ! V_94 && V_6 -> V_41 -> V_79 ) {
unsigned int V_41 = ( V_6 -> V_41 -> V_11 * 100 )
/ V_5 -> V_54 ;
V_17 = F_7 ( V_9 , V_98 , V_41 & 0x3 ) ;
if ( ! V_17 )
V_17 = F_7 ( V_9 , V_99 ,
( V_41 >> 2 ) & 0xff ) ;
if ( ! V_17 )
V_17 = F_7 ( V_9 , V_100 ,
( V_41 >> 10 ) & 0x3f ) ;
V_6 -> V_41 -> V_11 = ( ( V_41 * V_5 -> V_54 )
+ 50 ) / 100 ;
if ( V_17 < 0 )
return V_17 ;
}
F_32 ( V_5 -> V_6 . V_101 , ! exp ) ;
return 0 ;
}
static int F_33 ( struct V_5 * V_5 )
{
T_1 V_102 = 0 ;
if ( V_5 -> V_6 . V_103 -> V_11 )
V_102 |= V_104 ;
if ( V_5 -> V_6 . V_105 -> V_11 )
V_102 |= V_106 ;
return F_7 ( V_5 -> V_9 , V_107 , V_102 ) ;
}
static int F_34 ( struct V_5 * V_5 , int V_11 )
{
static const T_1 V_23 [ V_108 ] [ V_109 ] = {
{ 0x1d , 0x1f , 0x02 , 0x09 , 0x13 , 0x1c } ,
{ 0x2e , 0x31 , 0x02 , 0x0e , 0x1e , 0x2d } ,
{ 0x3a , 0x3d , 0x03 , 0x12 , 0x26 , 0x38 } ,
{ 0x46 , 0x49 , 0x04 , 0x16 , 0x2e , 0x43 } ,
{ 0x57 , 0x5c , 0x05 , 0x1b , 0x39 , 0x54 } ,
} ;
T_1 V_10 = F_13 ( 1 ) ;
int V_24 , V_17 = 0 ;
V_11 += ( V_108 / 2 ) ;
if ( V_11 >= V_108 )
return - V_61 ;
for ( V_24 = 0 ; V_24 < V_109 && ! V_17 ; V_24 ++ )
V_17 = F_7 ( V_5 -> V_9 , V_10 + V_24 , V_23 [ V_11 ] [ V_24 ] ) ;
return V_17 ;
}
static int F_35 ( struct V_5 * V_5 , int V_26 )
{
int V_17 ;
T_1 V_57 ;
V_17 = F_4 ( V_5 -> V_9 , V_110 , & V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
V_57 = V_26 ? V_57 | V_111 : V_57 & ~ V_111 ;
return F_7 ( V_5 -> V_9 , V_110 , V_57 ) ;
}
static int F_36 ( struct V_5 * V_5 , struct V_2 * V_3 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
unsigned int V_41 , V_81 , V_83 ;
T_1 V_112 , V_113 , V_114 ;
int V_17 ;
if ( ! V_5 -> V_37 )
return 0 ;
switch ( V_3 -> V_115 ) {
case V_116 :
if ( ! V_3 -> V_11 )
return 0 ;
V_17 = F_4 ( V_9 , V_84 , & V_112 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_4 ( V_9 , V_85 , & V_113 ) ;
if ( V_17 < 0 )
return V_17 ;
V_81 = ( ( V_113 >> 6 ) << 8 ) | V_112 ;
V_83 = 0x01 << F_37 ( V_81 >> 4 ) ;
V_5 -> V_6 . V_81 -> V_11 = V_83 * ( 16 + ( V_81 & 0xf ) ) ;
break;
case V_117 :
if ( V_3 -> V_11 == V_118 )
return 0 ;
V_17 = F_4 ( V_9 , V_98 , & V_112 ) ;
if ( ! V_17 )
V_17 = F_4 ( V_9 , V_99 , & V_113 ) ;
if ( ! V_17 )
V_17 = F_4 ( V_9 , V_100 , & V_114 ) ;
if ( V_17 < 0 )
return V_17 ;
V_41 = ( ( V_114 & 0x3f ) << 10 ) | ( V_113 << 2 ) |
( V_112 & 0x3 ) ;
V_5 -> V_6 . V_41 -> V_11 = ( ( V_41 *
V_5 -> V_54 ) + 50 ) / 100 ;
break;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_17 ;
F_6 ( 1 , V_20 , V_7 , L_6 , V_3 -> V_119 ) ;
F_20 ( & V_5 -> V_36 ) ;
V_17 = F_36 ( V_5 , V_3 ) ;
F_22 ( & V_5 -> V_36 ) ;
return V_17 ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_17 = - V_61 ;
F_6 ( 1 , V_20 , V_7 , L_7 ,
V_3 -> V_119 , V_3 -> V_11 , V_5 -> V_37 ) ;
F_20 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_37 == 0 ) {
F_22 ( & V_5 -> V_36 ) ;
return 0 ;
}
switch ( V_3 -> V_115 ) {
case V_120 :
V_17 = F_27 ( V_5 , V_3 -> V_11 ) ;
break;
case V_121 :
V_17 = F_28 ( V_5 , V_3 -> V_11 ) ;
break;
case V_117 :
V_17 = F_31 ( V_5 , V_3 -> V_11 ) ;
break;
case V_116 :
V_17 = F_29 ( V_5 , V_3 -> V_11 ) ;
break;
case V_122 :
V_17 = F_33 ( V_5 ) ;
break;
case V_123 :
V_17 = F_26 ( V_5 , V_3 -> V_11 ) ;
break;
case V_124 :
V_17 = F_34 ( V_5 , V_3 -> V_11 ) ;
break;
case V_125 :
V_17 = F_30 ( V_5 , V_3 -> V_11 ) ;
break;
case V_126 :
V_17 = F_35 ( V_5 , V_3 -> V_11 ) ;
break;
}
F_22 ( & V_5 -> V_36 ) ;
return V_17 ;
}
static int F_40 ( struct V_5 * V_5 )
{
const struct V_127 * V_128 = & V_129 ;
struct V_78 * V_6 = & V_5 -> V_6 ;
struct V_130 * V_131 = & V_6 -> V_4 ;
int V_17 ;
V_17 = F_41 ( V_131 , 16 ) ;
if ( V_17 < 0 )
return V_17 ;
V_6 -> V_132 = F_42 ( V_131 , V_128 ,
V_120 ,
0 , 1 , 1 , 1 ) ;
V_6 -> V_69 = F_42 ( V_131 , V_128 , V_133 ,
0 , 0xff , 1 , 0x80 ) ;
V_6 -> V_71 = F_42 ( V_131 , V_128 , V_134 ,
0 , 0xff , 1 , 0x80 ) ;
V_6 -> V_96 = F_43 ( V_131 , V_128 ,
V_117 ,
V_118 , 0 , V_95 ) ;
V_6 -> V_41 = F_42 ( V_131 , V_128 ,
V_135 ,
2 , 1500 , 1 , 500 ) ;
V_6 -> V_77 = F_42 ( V_131 , V_128 , V_116 ,
0 , 1 , 1 , 1 ) ;
V_6 -> V_81 = F_42 ( V_131 , V_128 , V_136 ,
16 , 64 * ( 16 + 15 ) , 1 , 64 * 16 ) ;
V_6 -> V_137 = F_42 ( V_131 , V_128 , V_124 ,
- 2 , 2 , 1 , 0 ) ;
V_6 -> V_101 = F_42 ( V_131 , V_128 , V_121 ,
- 3 , 3 , 1 , 0 ) ;
V_6 -> V_138 = F_42 ( V_131 , V_128 , V_125 ,
0 , 32 , 1 , 6 ) ;
V_6 -> V_103 = F_42 ( V_131 , V_128 , V_122 , 0 , 1 , 1 , 0 ) ;
V_6 -> V_105 = F_42 ( V_131 , V_128 , V_139 , 0 , 1 , 1 , 0 ) ;
V_6 -> V_56 = F_43 ( V_131 , V_128 ,
V_123 ,
V_140 , ~ 0x7 ,
V_62 ) ;
F_44 ( V_131 , V_128 , V_126 ,
F_11 ( V_141 ) - 1 , 0 , 0 ,
V_141 ) ;
if ( V_131 -> error ) {
V_17 = V_131 -> error ;
F_45 ( V_131 ) ;
return V_17 ;
}
V_6 -> V_81 -> V_15 |= V_142 ;
V_6 -> V_41 -> V_15 |= V_142 ;
F_46 ( 3 , & V_6 -> V_132 , 0 , false ) ;
F_46 ( 3 , & V_6 -> V_77 , 0 , true ) ;
F_46 ( 3 , & V_6 -> V_96 , 1 , true ) ;
F_47 ( 2 , & V_6 -> V_103 ) ;
V_5 -> V_7 . V_143 = V_131 ;
return 0 ;
}
static void F_48 ( struct V_144 * V_145 )
{
V_145 -> V_146 = V_147 [ 0 ] . V_146 ;
V_145 -> V_148 = V_147 [ 0 ] . V_148 ;
V_145 -> V_149 = V_150 [ 0 ] . V_149 ;
V_145 -> V_151 = V_150 [ 0 ] . V_151 ;
V_145 -> V_152 = V_153 ;
}
static int F_49 ( struct V_1 * V_7 ,
struct V_154 * V_155 ,
struct V_156 * V_151 )
{
if ( V_151 -> V_157 >= F_11 ( V_150 ) )
return - V_61 ;
V_151 -> V_151 = V_150 [ V_151 -> V_157 ] . V_151 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_7 ,
struct V_154 * V_155 ,
struct V_158 * V_159 )
{
int V_24 = F_11 ( V_150 ) ;
if ( V_159 -> V_157 >= F_11 ( V_147 ) )
return - V_61 ;
while ( -- V_24 )
if ( V_159 -> V_151 == V_150 [ V_24 ] . V_151 )
break;
V_159 -> V_151 = V_150 [ V_24 ] . V_151 ;
V_159 -> V_160 = V_147 [ V_159 -> V_157 ] . V_146 ;
V_159 -> V_161 = V_159 -> V_160 ;
V_159 -> V_162 = V_147 [ V_159 -> V_157 ] . V_148 ;
V_159 -> V_163 = V_159 -> V_162 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_7 ,
struct V_164 * V_165 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
F_20 ( & V_5 -> V_36 ) ;
V_165 -> V_63 = V_5 -> V_50 -> V_63 ;
F_22 ( & V_5 -> V_36 ) ;
return 0 ;
}
static int F_52 ( struct V_5 * V_5 ,
struct V_164 * V_165 )
{
struct V_144 * V_166 = & V_5 -> V_167 ;
const struct V_168 * V_50 = & V_169 [ 0 ] ;
T_2 V_170 , V_171 , V_172 = ~ 0ULL ;
unsigned int V_24 ;
if ( V_165 -> V_63 . V_64 == 0 )
return - V_61 ;
V_170 = ( T_2 ) ( V_165 -> V_63 . V_65 * 10000 ) /
V_165 -> V_63 . V_64 ;
for ( V_24 = 0 ; V_24 < F_11 ( V_169 ) ; V_24 ++ ) {
const struct V_168 * V_173 = & V_169 [ V_24 ] ;
if ( V_166 -> V_146 != V_173 -> V_174 . V_146 ||
V_166 -> V_148 != V_173 -> V_174 . V_148 )
continue;
V_171 = abs ( ( T_2 ) ( V_173 -> V_63 . V_65 * 10000 ) /
V_173 -> V_63 . V_64 - V_170 ) ;
if ( V_171 < V_172 ) {
V_50 = V_173 ;
V_172 = V_171 ;
}
}
V_5 -> V_50 = V_50 ;
F_6 ( 1 , V_20 , & V_5 -> V_7 , L_8 ,
V_50 -> V_63 . V_65 * 1000000 / V_50 -> V_63 . V_64 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_7 ,
struct V_164 * V_165 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_17 ;
F_6 ( 1 , V_20 , V_7 , L_9 ,
V_165 -> V_63 . V_65 , V_165 -> V_63 . V_64 ) ;
F_20 ( & V_5 -> V_36 ) ;
V_17 = F_52 ( V_5 , V_165 ) ;
V_5 -> V_39 = 1 ;
F_22 ( & V_5 -> V_36 ) ;
return V_17 ;
}
static int F_54 ( struct V_1 * V_7 , struct V_154 * V_155 ,
struct V_175 * V_176 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_144 * V_145 ;
if ( V_176 -> V_177 == V_178 ) {
V_145 = F_55 ( V_7 , V_155 , 0 ) ;
V_176 -> V_167 = * V_145 ;
return 0 ;
}
F_20 ( & V_5 -> V_36 ) ;
V_176 -> V_167 = V_5 -> V_167 ;
F_22 ( & V_5 -> V_36 ) ;
return 0 ;
}
static void F_56 ( struct V_144 * V_145 ,
const struct V_179 * * V_174 )
{
const struct V_179 * V_180 = & V_147 [ 0 ] ,
* V_181 = NULL ;
int V_24 = F_11 ( V_147 ) ;
unsigned int V_172 = V_182 ;
while ( V_24 -- ) {
int V_171 = abs ( V_180 -> V_146 - V_145 -> V_146 )
+ abs ( V_180 -> V_148 - V_145 -> V_148 ) ;
if ( V_171 < V_172 ) {
V_172 = V_171 ;
V_181 = V_180 ;
}
V_180 ++ ;
}
if ( ! V_181 )
V_181 = & V_147 [ 0 ] ;
V_145 -> V_146 = V_181 -> V_146 ;
V_145 -> V_148 = V_181 -> V_148 ;
if ( V_174 )
* V_174 = V_181 ;
}
static int F_57 ( struct V_1 * V_7 , struct V_154 * V_155 ,
struct V_175 * V_176 )
{
unsigned int V_157 = F_11 ( V_150 ) ;
struct V_144 * V_145 = & V_176 -> V_167 ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
const struct V_179 * V_174 = NULL ;
int V_17 = 0 ;
F_56 ( V_145 , & V_174 ) ;
while ( -- V_157 )
if ( V_150 [ V_157 ] . V_151 == V_145 -> V_151 )
break;
V_145 -> V_149 = V_183 ;
V_145 -> V_151 = V_150 [ V_157 ] . V_151 ;
V_145 -> V_152 = V_153 ;
F_20 ( & V_5 -> V_36 ) ;
if ( V_176 -> V_177 == V_178 ) {
if ( V_155 != NULL ) {
V_145 = F_55 ( V_7 , V_155 , V_176 -> V_184 ) ;
* V_145 = V_176 -> V_167 ;
}
} else {
if ( V_5 -> V_35 ) {
V_17 = - V_185 ;
} else {
V_5 -> V_48 = V_174 ;
V_5 -> V_167 = V_176 -> V_167 ;
V_5 -> V_186 = V_150 [ V_157 ] . V_186 ;
V_5 -> V_39 = 1 ;
}
}
if ( ! V_17 && V_176 -> V_177 == V_187 ) {
struct V_164 V_50 = {
. V_63 = { 0 , 1 }
} ;
F_52 ( V_5 , & V_50 ) ;
}
F_22 ( & V_5 -> V_36 ) ;
if ( ! V_17 )
F_23 ( V_5 ) ;
return V_17 ;
}
static int F_58 ( struct V_5 * V_5 )
{
int V_24 , V_17 = 0 ;
for ( V_24 = 0 ; V_17 == 0 && V_24 < V_188 ; V_24 ++ )
V_17 = F_7 ( V_5 -> V_9 , V_189 [ V_24 ] ,
V_5 -> V_48 -> V_23 [ V_24 ] ) ;
return V_17 ;
}
static int F_59 ( struct V_5 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
struct V_78 * V_6 = & V_5 -> V_6 ;
int V_17 = 0 ;
T_1 V_57 ;
if ( V_5 -> V_39 ) {
V_57 = V_49 + V_5 -> V_50 -> V_51 ;
V_17 = F_7 ( V_9 , V_190 , V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_58 ( V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_4 ( V_9 , V_191 , & V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
V_57 &= ~ V_192 ;
V_57 |= V_5 -> V_186 ;
V_17 = F_7 ( V_9 , V_191 , V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
}
V_17 = F_10 ( V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_12 ( V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_4 ( V_9 , V_193 , & V_57 ) ;
if ( ! V_17 )
V_57 |= V_194 ;
V_17 = F_7 ( V_9 , V_193 , V_57 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_26 ( V_5 , V_6 -> V_56 -> V_11 ) ;
}
static int F_60 ( struct V_1 * V_7 , int V_31 )
{
struct V_8 * V_9 = F_61 ( V_7 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_78 * V_6 = & V_5 -> V_6 ;
int V_17 = 0 ;
F_6 ( 1 , V_20 , V_9 , L_3 , V_21 , V_31 ) ;
F_20 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_35 == ! V_31 ) {
if ( V_31 )
V_17 = F_59 ( V_5 ) ;
if ( ! V_17 && V_6 -> V_40 ) {
F_22 ( & V_5 -> V_36 ) ;
V_17 = F_62 ( & V_6 -> V_4 ) ;
F_20 ( & V_5 -> V_36 ) ;
if ( ! V_17 )
V_6 -> V_40 = 0 ;
}
if ( ! V_17 )
V_17 = F_7 ( V_9 , V_195 ,
V_31 ? 0x01 : 0x11 ) ;
}
if ( ! V_17 )
V_5 -> V_35 += V_31 ? 1 : - 1 ;
F_21 ( V_5 -> V_35 < 0 ) ;
F_22 ( & V_5 -> V_36 ) ;
return V_17 ;
}
static int F_63 ( struct V_1 * V_7 , struct V_196 * V_197 )
{
struct V_144 * V_145 = F_55 ( V_7 , V_197 -> V_184 , 0 ) ;
F_48 ( V_145 ) ;
return 0 ;
}
static int F_64 ( struct V_5 * V_5 ,
const struct V_198 * V_199 )
{
int V_17 , V_24 ;
V_5 -> V_32 [ V_33 ] = V_199 -> V_200 ;
V_5 -> V_32 [ V_34 ] = V_199 -> V_201 ;
for ( V_24 = 0 ; V_24 < F_11 ( V_5 -> V_32 ) ; V_24 ++ ) {
int V_30 = V_5 -> V_32 [ V_24 ] ;
if ( ! F_15 ( V_30 ) )
continue;
V_17 = F_65 ( & V_5 -> V_9 -> V_202 , V_30 ,
V_203 , L_10 ) ;
if ( V_17 < 0 )
return V_17 ;
F_6 ( 1 , V_20 , & V_5 -> V_7 , L_11 , V_30 ) ;
F_16 ( V_30 , 1 ) ;
F_66 ( V_30 , 0 ) ;
V_5 -> V_32 [ V_24 ] = V_30 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = F_61 ( V_7 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
T_1 V_204 , V_205 ;
int V_17 ;
F_20 ( & V_5 -> V_36 ) ;
F_17 ( V_5 , 1 ) ;
F_18 ( 25000 , 26000 ) ;
V_17 = F_4 ( V_9 , V_206 , & V_204 ) ;
if ( ! V_17 )
V_17 = F_4 ( V_9 , V_207 , & V_205 ) ;
F_17 ( V_5 , 0 ) ;
if ( ! V_17 ) {
V_5 -> V_115 = F_68 ( V_204 , V_205 ) ;
if ( V_5 -> V_115 == V_208 || V_5 -> V_115 == V_209 ) {
F_69 ( V_7 , L_12 , V_5 -> V_115 ) ;
} else {
F_25 ( V_7 , L_13 ,
V_5 -> V_115 , V_17 ) ;
V_17 = - V_210 ;
}
}
F_22 ( & V_5 -> V_36 ) ;
return V_17 ;
}
static int F_70 ( struct V_8 * V_9 ,
const struct V_211 * V_115 )
{
const struct V_198 * V_199 = V_9 -> V_202 . V_212 ;
struct V_1 * V_7 ;
struct V_5 * V_5 ;
int V_17 ;
if ( V_199 == NULL ) {
F_71 ( & V_9 -> V_202 , L_14 ) ;
return - V_61 ;
}
if ( V_199 -> V_52 == 0 ) {
F_71 ( & V_9 -> V_202 , L_15 ) ;
return - V_61 ;
}
V_5 = F_72 ( & V_9 -> V_202 , sizeof( * V_5 ) , V_213 ) ;
if ( ! V_5 )
return - V_214 ;
F_73 ( & V_5 -> V_36 ) ;
V_5 -> V_9 = V_9 ;
V_5 -> V_52 = V_199 -> V_52 ;
V_7 = & V_5 -> V_7 ;
F_74 ( V_7 , V_9 , & V_215 ) ;
F_75 ( V_7 -> V_119 , V_216 , sizeof( V_7 -> V_119 ) ) ;
V_7 -> V_217 = & V_218 ;
V_7 -> V_15 |= V_219 |
V_220 ;
V_17 = F_64 ( V_5 , V_199 ) ;
if ( V_17 < 0 )
return V_17 ;
V_5 -> V_184 . V_15 = V_221 ;
V_7 -> V_222 . type = V_223 ;
V_17 = F_76 ( & V_7 -> V_222 , 1 , & V_5 -> V_184 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_40 ( V_5 ) ;
if ( V_17 < 0 )
goto V_224;
F_48 ( & V_5 -> V_167 ) ;
V_5 -> V_48 = & V_147 [ 0 ] ;
V_5 -> V_50 = & V_169 [ 0 ] ;
V_17 = F_67 ( V_7 ) ;
if ( V_17 < 0 )
goto V_225;
F_23 ( V_5 ) ;
return 0 ;
V_225:
F_45 ( V_7 -> V_143 ) ;
V_224:
F_77 ( & V_7 -> V_222 ) ;
return V_17 ;
}
static int F_78 ( struct V_8 * V_9 )
{
struct V_1 * V_7 = F_79 ( V_9 ) ;
F_80 ( V_7 ) ;
F_45 ( V_7 -> V_143 ) ;
F_77 ( & V_7 -> V_222 ) ;
return 0 ;
}
