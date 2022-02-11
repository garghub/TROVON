static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
for ( V_3 = V_5 ; V_3 <= V_6 ; V_3 ++ ) {
F_2 ( V_7 , & V_4 , V_3 ) ;
V_2 -> V_8 [ V_3 - V_5 ] = V_4 ;
}
}
static unsigned int F_3 ( struct V_9 * V_10 , unsigned int V_11 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_12 = 0 ;
if ( V_11 >= V_13 )
return - V_14 ;
switch ( V_11 ) {
case V_5 :
case V_15 :
case V_16 :
case V_17 :
case V_6 :
case V_18 :
V_12 = V_2 -> V_8 [ V_11 - V_5 ] ;
break;
default:
F_2 ( V_7 , & V_12 , V_11 ) ;
break;
}
return V_12 ;
}
static bool F_5 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
bool V_19 = false ;
switch ( V_11 ) {
case V_5 :
if ( V_2 -> V_20 )
V_19 = true ;
break;
case V_15 :
if ( V_2 -> V_21 )
V_19 = true ;
break;
case V_16 :
if ( V_2 -> V_22 )
V_19 = true ;
break;
case V_17 :
if ( V_2 -> V_23 )
V_19 = true ;
break;
case V_6 :
if ( V_2 -> V_24 )
V_19 = true ;
break;
case V_18 :
if ( V_2 -> V_25 || V_2 -> V_26 )
V_19 = true ;
break;
default:
V_19 = true ;
break;
}
return V_19 ;
}
static int F_6 ( struct V_9 * V_10 , unsigned int V_11 ,
unsigned int V_12 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
switch ( V_11 ) {
case V_5 :
case V_15 :
case V_16 :
case V_17 :
case V_6 :
case V_18 :
V_2 -> V_8 [ V_11 - V_5 ] = V_12 ;
break;
default:
break;
}
if ( F_5 ( V_2 , V_11 ) )
return F_7 ( V_7 , V_12 , V_11 ) ;
return 0 ;
}
static inline void F_8 ( int time )
{
if ( time < 60 ) {
time *= 1000 ;
F_9 ( time , time + 500 ) ;
} else {
F_10 ( time ) ;
}
}
static void F_11 ( struct V_9 * V_10 , int V_27 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
int V_28 ;
if ( V_27 == V_2 -> V_29 )
return;
if ( V_27 )
V_28 = F_12 ( V_30 ) ;
else
V_28 = F_13 ( V_30 ) ;
if ( V_28 >= 0 )
V_2 -> V_29 = V_27 ;
F_14 ( 10 ) ;
}
static void F_15 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_12 ;
F_16 ( V_34 , L_1 ,
& V_32 -> V_35 ) ;
F_16 ( V_34 , L_2 ,
& V_32 -> V_36 ) ;
F_16 ( V_34 , L_3 ,
& V_32 -> V_37 ) ;
if ( ! F_16 ( V_34 , L_4 , & V_12 ) )
V_32 -> V_38 = V_12 ;
V_32 -> V_39 = F_17 ( V_34 ,
L_5 , 0 ) ;
if ( F_18 ( V_32 -> V_39 ) )
V_32 -> V_38 = 1 ;
}
static struct V_31 * F_19 ( struct V_9 * V_10 )
{
struct V_31 * V_32 = F_20 ( V_10 -> V_40 ) ;
struct V_33 * V_41 = NULL ;
V_41 = F_21 ( V_10 -> V_40 -> V_42 -> V_43 ,
L_6 ) ;
if ( ! V_32 && V_41 ) {
V_32 = F_22 ( V_10 -> V_40 ,
sizeof( struct V_31 ) ,
V_44 ) ;
if ( ! V_32 ) {
F_23 ( V_10 -> V_40 , L_7 ) ;
return NULL ;
}
F_15 ( V_32 , V_41 ) ;
}
return V_32 ;
}
static void F_24 ( struct V_9 * V_10 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_11 , V_4 ;
int V_3 = 0 ;
V_32 = F_19 ( V_10 ) ;
if ( V_32 && V_32 -> V_38 ) {
if ( F_18 ( V_32 -> V_39 ) ) {
int V_45 ;
if ( ! V_32 -> V_39 )
F_25 ( V_10 -> V_40 ,
L_8 ) ;
V_45 = F_26 ( V_32 -> V_39 ,
V_46 ,
L_9 ) ;
if ( V_45 ) {
F_23 ( V_10 -> V_40 ,
L_10 ) ;
V_32 -> V_39 = - 1 ;
}
} else {
T_1 V_47 ;
F_2 ( V_48 , & V_47 ,
V_49 ) ;
V_47 &= ~ F_27 ( 0x03 ) ;
V_47 |= F_27 ( 0x02 ) ;
F_7 ( V_48 , V_47 ,
V_49 ) ;
}
}
F_1 ( V_2 ) ;
V_11 = F_3 ( V_10 , V_50 ) ;
F_6 ( V_10 , V_50 ,
V_11 | V_51 ) ;
F_6 ( V_10 , V_52 ,
V_53 | V_54 |
V_55 | V_56 ) ;
F_6 ( V_10 , V_57 , 0x32 ) ;
if ( ! V_32 )
return;
V_2 -> V_32 = V_32 ;
V_11 = F_3 ( V_10 , V_58 ) ;
V_11 &= ~ V_59 ;
V_11 |= ( V_32 -> V_36 << 2 ) ;
F_6 ( V_10 , V_58 , V_11 ) ;
F_11 ( V_10 , 1 ) ;
V_11 = F_3 ( V_10 , V_60 ) ;
V_11 &= ~ V_61 ;
V_11 |= V_32 -> V_37 ;
F_6 ( V_10 , V_60 ,
V_11 | V_62 ) ;
F_10 ( 20 ) ;
do {
F_9 ( 1000 , 2000 ) ;
F_28 ( V_7 , true ) ;
F_2 ( V_7 , & V_4 ,
V_60 ) ;
F_28 ( V_7 , false ) ;
} while ( ( V_3 ++ < 100 ) &&
( ( V_4 & V_62 ) ==
V_62 ) );
F_11 ( V_10 , 0 ) ;
}
static void F_29 ( struct V_9 * V_10 , int V_27 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_27 ) {
V_2 -> V_63 ++ ;
if ( V_2 -> V_63 == 1 )
F_12 (
V_64 ) ;
} else {
V_2 -> V_63 -- ;
if ( ! V_2 -> V_63 )
F_13 (
V_64 ) ;
}
}
static void F_30 ( struct V_9 * V_10 , int V_11 , int V_65 )
{
unsigned char V_66 ;
V_66 = F_3 ( V_10 , V_11 ) ;
if ( V_65 ) {
V_66 |= V_67 ;
F_6 ( V_10 , V_11 , V_66 ) ;
F_14 ( 10 ) ;
V_66 |= V_68 ;
F_6 ( V_10 , V_11 , V_66 ) ;
F_14 ( 40 ) ;
V_66 |= V_69 ;
V_66 |= V_70 ;
F_6 ( V_10 , V_11 , V_66 ) ;
} else {
V_66 &= ~ V_69 ;
V_66 &= ~ V_70 ;
F_6 ( V_10 , V_11 , V_66 ) ;
V_66 &= ~ V_68 ;
F_6 ( V_10 , V_11 , V_66 ) ;
F_14 ( 40 ) ;
V_66 &= ~ V_67 ;
F_6 ( V_10 , V_11 , V_66 ) ;
}
}
static int F_31 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_9 * V_10 = F_32 ( V_72 -> V_76 ) ;
switch ( V_75 ) {
case V_77 :
F_30 ( V_10 , V_78 , 1 ) ;
break;
case V_79 :
F_30 ( V_10 , V_78 , 0 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_9 * V_10 = F_32 ( V_72 -> V_76 ) ;
switch ( V_75 ) {
case V_77 :
F_30 ( V_10 , V_80 , 1 ) ;
break;
case V_79 :
F_30 ( V_10 , V_80 , 0 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_9 * V_10 = F_32 ( V_72 -> V_76 ) ;
F_6 ( V_10 , V_81 , 0xff ) ;
return 0 ;
}
static int F_35 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_9 * V_10 = F_32 ( V_72 -> V_76 ) ;
switch ( V_75 ) {
case V_82 :
F_29 ( V_10 , 1 ) ;
break;
case V_79 :
F_29 ( V_10 , 0 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_9 * V_10 = F_32 ( V_72 -> V_76 ) ;
T_1 V_83 ;
V_83 = F_3 ( V_10 , V_84 ) ;
switch ( V_75 ) {
case V_82 :
F_29 ( V_10 , 1 ) ;
F_6 ( V_10 , V_84 ,
V_83 | V_85 ) ;
break;
case V_79 :
F_6 ( V_10 , V_84 ,
V_83 & ~ V_85 ) ;
F_29 ( V_10 , 0 ) ;
break;
}
return 0 ;
}
static void F_37 ( struct V_9 * V_10 , int V_65 )
{
unsigned char V_86 , V_87 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
unsigned int V_88 [] = { 524288 , 1048576 , 2097152 , 4194304 ,
8388608 , 16777216 , 33554432 , 67108864 } ;
unsigned int V_89 ;
V_86 = F_3 ( V_10 , V_18 ) ;
V_87 = F_3 ( V_10 , V_58 ) ;
V_89 = ( V_88 [ ( V_87 & V_59 ) >> 2 ] /
V_2 -> V_90 ) + 1 ;
if ( V_32 && V_32 -> V_38 ) {
if ( F_18 ( V_32 -> V_39 ) ) {
F_38 ( V_32 -> V_39 , 1 ) ;
} else {
V_87 |= V_91 ;
F_6 ( V_10 , V_58 , V_87 ) ;
}
}
if ( V_65 ) {
V_87 |= V_92 ;
F_6 ( V_10 , V_58 , V_87 ) ;
F_7 ( V_7 , V_86 ,
V_18 ) ;
V_87 |= V_93 ;
F_6 ( V_10 , V_58 , V_87 ) ;
F_8 ( V_89 ) ;
} else {
V_87 &= ~ V_93 ;
F_6 ( V_10 , V_58 , V_87 ) ;
F_8 ( V_89 ) ;
F_7 ( V_7 , V_86 & ( ~ 0x0f ) ,
V_18 ) ;
V_87 &= ~ V_92 ;
F_6 ( V_10 , V_58 , V_87 ) ;
}
if ( V_32 && V_32 -> V_38 ) {
if ( F_18 ( V_32 -> V_39 ) ) {
F_38 ( V_32 -> V_39 , 0 ) ;
} else {
V_87 &= ~ V_91 ;
F_6 ( V_10 , V_58 , V_87 ) ;
}
}
}
static int F_39 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_9 * V_10 = F_32 ( V_72 -> V_76 ) ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
switch ( V_75 ) {
case V_77 :
if ( ! V_2 -> V_26 )
F_37 ( V_10 , 1 ) ;
V_2 -> V_25 = 1 ;
break;
case V_79 :
if ( ! V_2 -> V_26 )
F_37 ( V_10 , 0 ) ;
V_2 -> V_25 = 0 ;
break;
}
return 0 ;
}
static int F_40 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_9 * V_10 = F_32 ( V_72 -> V_76 ) ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
switch ( V_75 ) {
case V_77 :
if ( ! V_2 -> V_25 )
F_37 ( V_10 , 1 ) ;
V_2 -> V_26 = 1 ;
break;
case V_79 :
if ( ! V_2 -> V_25 )
F_37 ( V_10 , 0 ) ;
V_2 -> V_26 = 0 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_9 * V_10 = F_32 ( V_72 -> V_76 ) ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
if ( V_32 && V_32 -> V_35 )
F_8 ( V_32 -> V_35 ) ;
return 0 ;
}
static int F_42 ( struct V_73 * V_74 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_74 -> V_98 ;
struct V_9 * V_10 = F_43 ( V_74 ) ;
unsigned int V_11 = V_97 -> V_11 ;
unsigned int V_99 = V_97 -> V_99 ;
unsigned int V_100 = V_97 -> V_100 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_44 ( V_101 ) ) - 1 ;
V_95 -> V_12 . integer . V_12 [ 0 ] =
( F_45 ( V_10 , V_11 ) >> V_99 ) & V_102 ;
if ( V_95 -> V_12 . integer . V_12 [ 0 ] )
V_95 -> V_12 . integer . V_12 [ 0 ] =
V_101 + 1 - V_95 -> V_12 . integer . V_12 [ 0 ] ;
if ( V_99 != V_100 ) {
V_95 -> V_12 . integer . V_12 [ 1 ] =
( F_45 ( V_10 , V_11 ) >> V_100 ) & V_102 ;
if ( V_95 -> V_12 . integer . V_12 [ 1 ] )
V_95 -> V_12 . integer . V_12 [ 1 ] =
V_101 + 1 - V_95 -> V_12 . integer . V_12 [ 1 ] ;
}
return 0 ;
}
static int F_46 ( struct V_73 * V_74 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_74 -> V_98 ;
struct V_9 * V_10 = F_43 ( V_74 ) ;
unsigned int V_11 = V_97 -> V_11 ;
unsigned int V_99 = V_97 -> V_99 ;
unsigned int V_100 = V_97 -> V_100 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_44 ( V_101 ) ) - 1 ;
unsigned short V_103 , V_104 , V_105 ;
V_103 = ( V_95 -> V_12 . integer . V_12 [ 0 ] & V_102 ) ;
V_105 = V_102 << V_99 ;
if ( V_103 )
V_103 = V_101 + 1 - V_103 ;
V_103 = V_103 << V_99 ;
if ( V_99 != V_100 ) {
V_104 = ( V_95 -> V_12 . integer . V_12 [ 1 ] & V_102 ) ;
V_105 |= V_102 << V_100 ;
if ( V_104 )
V_104 = V_101 + 1 - V_104 ;
V_103 |= V_104 << V_100 ;
}
return F_47 ( V_10 , V_11 , V_105 , V_103 ) ;
}
static int F_48 ( struct V_73 * V_74 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_74 -> V_98 ;
struct V_9 * V_10 = F_43 ( V_74 ) ;
unsigned int V_11 = V_97 -> V_11 ;
unsigned int V_106 = V_97 -> V_107 ;
unsigned int V_99 = V_97 -> V_99 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_44 ( V_101 ) ) - 1 ;
V_95 -> V_12 . integer . V_12 [ 0 ] =
( F_45 ( V_10 , V_11 ) >> V_99 ) & V_102 ;
V_95 -> V_12 . integer . V_12 [ 1 ] =
( F_45 ( V_10 , V_106 ) >> V_99 ) & V_102 ;
if ( V_95 -> V_12 . integer . V_12 [ 0 ] )
V_95 -> V_12 . integer . V_12 [ 0 ] =
V_101 + 1 - V_95 -> V_12 . integer . V_12 [ 0 ] ;
if ( V_95 -> V_12 . integer . V_12 [ 1 ] )
V_95 -> V_12 . integer . V_12 [ 1 ] =
V_101 + 1 - V_95 -> V_12 . integer . V_12 [ 1 ] ;
return 0 ;
}
static int F_49 ( struct V_73 * V_74 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_74 -> V_98 ;
struct V_9 * V_10 = F_43 ( V_74 ) ;
unsigned int V_11 = V_97 -> V_11 ;
unsigned int V_106 = V_97 -> V_107 ;
unsigned int V_99 = V_97 -> V_99 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_44 ( V_101 ) ) - 1 ;
int V_108 ;
unsigned short V_103 , V_104 , V_105 ;
V_105 = V_102 << V_99 ;
V_103 = ( V_95 -> V_12 . integer . V_12 [ 0 ] & V_102 ) ;
V_104 = ( V_95 -> V_12 . integer . V_12 [ 1 ] & V_102 ) ;
if ( V_103 )
V_103 = V_101 + 1 - V_103 ;
if ( V_104 )
V_104 = V_101 + 1 - V_104 ;
V_103 = V_103 << V_99 ;
V_104 = V_104 << V_99 ;
V_108 = F_47 ( V_10 , V_11 , V_105 , V_103 ) ;
if ( V_108 < 0 )
return V_108 ;
V_108 = F_47 ( V_10 , V_106 , V_105 , V_104 ) ;
return V_108 ;
}
static int F_50 ( struct V_73 * V_74 ,
struct V_94 * V_95 )
{
struct V_9 * V_10 = F_43 ( V_74 ) ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_109 ) {
F_23 ( V_10 -> V_40 ,
L_11 ) ;
return - V_110 ;
}
return F_51 ( V_74 , V_95 ) ;
}
static int F_52 ( struct V_9 * V_10 ,
enum V_111 V_112 )
{
switch ( V_112 ) {
case V_113 :
break;
case V_114 :
break;
case V_115 :
if ( F_53 ( V_10 ) == V_116 )
F_11 ( V_10 , 1 ) ;
break;
case V_116 :
F_11 ( V_10 , 0 ) ;
break;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
struct V_117 * V_119 ;
if ( V_118 == V_2 -> V_120 )
V_119 = V_2 -> V_121 ;
else if ( V_118 == V_2 -> V_121 )
V_119 = V_2 -> V_120 ;
else
return;
F_55 ( V_119 -> V_122 ,
V_123 ,
V_2 -> V_124 ) ;
F_55 ( V_119 -> V_122 ,
V_125 ,
V_2 -> V_126 ) ;
F_55 ( V_119 -> V_122 ,
V_127 ,
V_2 -> V_128 ) ;
}
static void F_56 ( struct V_9 * V_10 , int V_129 ,
int V_27 )
{
T_1 V_11 , V_102 ;
V_11 = F_3 ( V_10 , V_52 ) ;
if ( V_129 == V_130 )
V_102 = V_131 | V_132 ;
else
V_102 = V_133 | V_134 ;
if ( V_27 )
V_11 |= V_102 ;
else
V_11 &= ~ V_102 ;
F_6 ( V_10 , V_52 , V_11 ) ;
}
static int F_57 ( struct V_117 * V_135 ,
struct V_136 * V_137 )
{
struct V_9 * V_10 = V_137 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_120 ) {
V_2 -> V_121 = V_135 ;
if ( V_2 -> V_109 )
F_54 ( V_2 , V_2 -> V_120 ) ;
} else {
if ( ! ( F_3 ( V_10 , V_138 ) &
V_139 ) ) {
F_55 ( V_135 -> V_122 ,
V_127 ,
2 ) ;
}
V_2 -> V_120 = V_135 ;
}
return 0 ;
}
static void F_58 ( struct V_117 * V_135 ,
struct V_136 * V_137 )
{
struct V_9 * V_10 = V_137 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_120 == V_135 )
V_2 -> V_120 = V_2 -> V_121 ;
V_2 -> V_121 = NULL ;
if ( ! V_2 -> V_120 )
V_2 -> V_109 = 0 ;
else if ( ! V_2 -> V_120 -> V_122 -> V_128 )
V_2 -> V_109 = 0 ;
if ( V_135 -> V_122 -> V_128 == 4 )
F_56 ( V_10 , V_135 -> V_140 , 0 ) ;
}
static int F_59 ( struct V_117 * V_135 ,
struct V_141 * V_142 ,
struct V_136 * V_137 )
{
struct V_9 * V_10 = V_137 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_28 , V_143 , V_144 , V_145 ;
if ( F_60 ( V_142 ) == 4 ) {
V_144 = F_3 ( V_10 , V_84 ) ;
V_28 = F_3 ( V_10 , V_138 ) ;
if ( ( V_28 & V_139 ) &&
( ( V_144 & V_146 ) == V_147 ) )
F_56 ( V_10 , V_135 -> V_140 , 1 ) ;
else
return - V_148 ;
}
if ( V_2 -> V_109 )
return 0 ;
V_143 = F_3 ( V_10 ,
V_138 ) & ~ V_149 ;
V_28 = V_143 & ~ V_150 ;
switch ( F_61 ( V_142 ) ) {
case 8000 :
V_28 |= V_151 ;
break;
case 11025 :
V_28 |= V_152 ;
break;
case 12000 :
V_28 |= V_153 ;
break;
case 16000 :
V_28 |= V_154 ;
break;
case 22050 :
V_28 |= V_155 ;
break;
case 24000 :
V_28 |= V_156 ;
break;
case 32000 :
V_28 |= V_157 ;
break;
case 44100 :
V_28 |= V_158 ;
break;
case 48000 :
V_28 |= V_159 ;
break;
case 96000 :
V_28 |= V_160 ;
break;
default:
F_23 ( V_10 -> V_40 , L_12 , V_161 ,
F_61 ( V_142 ) ) ;
return - V_148 ;
}
V_145 = F_3 ( V_10 , V_84 ) ;
V_144 = V_145 ;
V_144 &= ~ V_162 ;
switch ( F_62 ( V_142 ) ) {
case 16 :
V_144 |= V_163 ;
break;
case 32 :
V_144 |= V_164 ;
break;
default:
F_23 ( V_10 -> V_40 , L_13 ,
V_161 , F_62 ( V_142 ) ) ;
return - V_148 ;
}
if ( V_144 != V_145 || V_28 != V_143 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_138 , V_28 ) ;
F_6 ( V_10 , V_84 , V_144 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_138 , V_28 ) ;
F_6 ( V_10 , V_84 , V_144 ) ;
}
}
V_2 -> V_109 = 1 ;
V_2 -> V_124 = F_61 ( V_142 ) ;
V_2 -> V_126 = F_63 ( V_142 ,
V_125 ) -> V_165 ;
V_2 -> V_128 = F_60 ( V_142 ) ;
if ( V_2 -> V_121 )
F_54 ( V_2 , V_135 ) ;
return 0 ;
}
static int F_64 ( struct V_136 * V_166 , int V_167 ,
unsigned int V_168 , int V_169 )
{
struct V_9 * V_10 = V_166 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
switch ( V_168 ) {
case 19200000 :
case 26000000 :
case 38400000 :
break;
default:
F_23 ( V_10 -> V_40 , L_14 , V_168 ) ;
return - V_148 ;
}
if ( ( V_168 / 1000 ) != V_2 -> V_90 ) {
F_23 ( V_10 -> V_40 ,
L_15 ,
V_168 , V_2 -> V_90 * 1000 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_65 ( struct V_136 * V_166 , unsigned int V_170 )
{
struct V_9 * V_10 = V_166 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_145 , V_144 ;
V_145 = F_3 ( V_10 , V_84 ) ;
V_144 = V_145 ;
switch ( V_170 & V_171 ) {
case V_172 :
V_144 &= ~ ( V_173 ) ;
V_144 &= ~ ( V_174 ) ;
break;
case V_175 :
V_144 |= V_173 ;
V_144 |= V_174 ;
break;
default:
return - V_148 ;
}
V_144 &= ~ V_146 ;
switch ( V_170 & V_176 ) {
case V_177 :
V_144 |= V_178 ;
break;
case V_179 :
V_144 |= V_147 ;
break;
default:
return - V_148 ;
}
if ( V_144 != V_145 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_84 , V_144 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_84 , V_144 ) ;
}
}
return 0 ;
}
static int F_66 ( struct V_136 * V_137 , int V_180 )
{
struct V_9 * V_10 = V_137 -> V_10 ;
T_1 V_11 = F_3 ( V_10 , V_84 ) ;
if ( V_180 )
V_11 |= V_181 ;
else
V_11 &= ~ V_181 ;
return F_6 ( V_10 , V_84 , V_11 ) ;
}
static void F_67 ( struct V_9 * V_10 , int V_129 ,
int V_27 )
{
T_1 V_11 , V_102 ;
V_11 = F_3 ( V_10 , V_52 ) ;
if ( V_129 == V_130 )
V_102 = V_131 ;
else
V_102 = V_133 | V_134 ;
if ( V_27 )
V_11 |= V_102 ;
else
V_11 &= ~ V_102 ;
F_6 ( V_10 , V_52 , V_11 ) ;
}
static int F_68 ( struct V_117 * V_135 ,
struct V_136 * V_137 )
{
struct V_9 * V_10 = V_137 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_28 ;
if ( V_2 -> V_90 != 26000 ) {
F_23 ( V_10 -> V_40 ,
L_16 ,
V_161 , V_2 -> V_90 ) ;
return - V_148 ;
}
V_28 = F_3 ( V_10 , V_138 )
& V_182 ;
if ( V_28 != V_183 ) {
F_23 ( V_10 -> V_40 , L_17 ,
V_161 ) ;
return - V_148 ;
}
return 0 ;
}
static void F_69 ( struct V_117 * V_135 ,
struct V_136 * V_137 )
{
struct V_9 * V_10 = V_137 -> V_10 ;
F_67 ( V_10 , V_135 -> V_140 , 0 ) ;
}
static int F_70 ( struct V_117 * V_135 ,
struct V_141 * V_142 ,
struct V_136 * V_137 )
{
struct V_9 * V_10 = V_137 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_143 , V_28 ;
F_67 ( V_10 , V_135 -> V_140 , 1 ) ;
V_143 = F_3 ( V_10 ,
V_138 ) & ~ V_149 ;
V_28 = V_143 ;
switch ( F_61 ( V_142 ) ) {
case 8000 :
V_28 &= ~ ( V_184 ) ;
break;
case 16000 :
V_28 |= V_184 ;
break;
default:
F_23 ( V_10 -> V_40 , L_12 , V_161 ,
F_61 ( V_142 ) ) ;
return - V_148 ;
}
if ( V_28 != V_143 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_138 , V_28 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_138 , V_28 ) ;
}
}
return 0 ;
}
static int F_71 ( struct V_136 * V_166 ,
int V_167 , unsigned int V_168 , int V_169 )
{
struct V_9 * V_10 = V_166 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_168 != 26000000 ) {
F_23 ( V_10 -> V_40 ,
L_16 ,
V_161 , V_168 / 1000 ) ;
return - V_148 ;
}
if ( ( V_168 / 1000 ) != V_2 -> V_90 ) {
F_23 ( V_10 -> V_40 ,
L_15 ,
V_168 , V_2 -> V_90 * 1000 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_72 ( struct V_136 * V_166 ,
unsigned int V_170 )
{
struct V_9 * V_10 = V_166 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_145 , V_144 ;
V_145 = F_3 ( V_10 , V_185 ) ;
V_144 = V_145 ;
switch ( V_170 & V_171 ) {
case V_172 :
V_144 &= ~ ( V_186 ) ;
break;
case V_175 :
V_144 |= V_186 ;
break;
default:
return - V_148 ;
}
switch ( V_170 & V_187 ) {
case V_188 :
V_144 &= ~ ( V_189 ) ;
break;
case V_190 :
V_144 |= V_189 ;
break;
default:
return - V_148 ;
}
if ( V_144 != V_145 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_185 , V_144 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_185 , V_144 ) ;
}
}
return 0 ;
}
static int F_73 ( struct V_136 * V_137 , int V_180 )
{
struct V_9 * V_10 = V_137 -> V_10 ;
T_1 V_11 = F_3 ( V_10 , V_185 ) ;
if ( V_180 )
V_11 |= V_191 ;
else
V_11 &= ~ V_191 ;
return F_6 ( V_10 , V_185 , V_11 ) ;
}
static int F_74 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_10 -> V_40 , sizeof( struct V_1 ) ,
V_44 ) ;
if ( ! V_2 )
return - V_192 ;
F_75 ( V_10 , V_2 ) ;
V_2 -> V_90 = F_76 () / 1000 ;
F_24 ( V_10 ) ;
return 0 ;
}
static int F_77 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
if ( V_32 && V_32 -> V_38 && F_18 ( V_32 -> V_39 ) )
F_78 ( V_32 -> V_39 ) ;
return 0 ;
}
static int F_79 ( struct V_193 * V_194 )
{
return F_80 ( & V_194 -> V_40 , & V_195 ,
V_196 , F_81 ( V_196 ) ) ;
}
static int F_82 ( struct V_193 * V_194 )
{
F_83 ( & V_194 -> V_40 ) ;
return 0 ;
}
