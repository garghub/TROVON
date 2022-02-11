static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 ) ;
unsigned int V_9 = V_2 -> V_10 [ 3 ] - '1' ;
unsigned int V_11 ;
if ( F_3 ( V_5 ) )
V_11 = V_12 ;
else
V_11 = 0 ;
F_4 ( V_8 -> V_13 , F_5 ( V_9 ) ,
V_12 , V_11 ) ;
if ( F_3 ( V_5 ) )
F_6 ( 5 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_14 ,
struct V_1 * V_15 )
{
struct V_6 * V_7 = V_14 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 ) ;
unsigned int V_16 ;
const char * V_17 ;
V_16 = V_15 -> V_10 [ 3 ] - '1' ;
if ( ! V_8 -> V_18 [ V_16 ] . V_19 )
return 0 ;
if ( V_8 -> V_18 [ V_16 ] . V_20 == V_21 )
V_17 = L_1 ;
else
V_17 = L_2 ;
return strcmp ( V_14 -> V_10 , V_17 ) == 0 ;
}
static int F_8 ( struct V_1 * V_14 ,
struct V_1 * V_15 )
{
struct V_6 * V_7 = V_14 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 ) ;
unsigned int V_16 ;
V_16 = V_15 -> V_10 [ 3 ] - '1' ;
return V_8 -> V_18 [ V_16 ] . V_22 ;
}
static int F_9 ( struct V_23 * V_24 ,
struct V_25 * V_26 , struct V_27 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 ) ;
struct V_28 * V_28 = & V_8 -> V_18 [ V_16 -> V_29 ] ;
unsigned int div ;
unsigned int V_30 ;
unsigned int V_31 ;
V_30 = V_28 -> V_32 ;
if ( V_30 % F_10 ( V_26 ) != 0 )
return - V_33 ;
switch ( V_30 / F_10 ( V_26 ) ) {
case 1024 :
div = 0 ;
break;
case 1536 :
div = 1 ;
break;
case 2048 :
div = 2 ;
break;
case 3072 :
div = 3 ;
break;
case 4096 :
div = 4 ;
break;
case 6144 :
div = 5 ;
break;
case 5632 :
div = 6 ;
break;
default:
return - V_33 ;
}
V_28 -> V_22 = ( div != 0 ) ;
F_4 ( V_8 -> V_13 , F_11 ( V_16 -> V_29 ) ,
V_34 | V_35 ,
( div << 2 ) | V_36 ) ;
switch ( F_12 ( V_26 ) ) {
case V_37 :
V_31 = V_38 ;
break;
case V_39 :
V_31 = V_40 ;
break;
case V_41 :
V_31 = V_42 ;
break;
case V_43 :
V_31 = V_44 ;
break;
default:
return - V_33 ;
}
return F_4 ( V_8 -> V_13 , F_13 ( V_16 -> V_29 ) ,
V_45 , V_31 ) ;
}
static int F_14 ( struct V_27 * V_16 , unsigned int V_46 )
{
struct V_6 * V_7 = V_16 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 ) ;
struct V_28 * V_28 = & V_8 -> V_18 [ V_16 -> V_29 ] ;
unsigned int V_31 ;
switch ( V_46 & V_47 ) {
case V_48 :
V_31 = V_49 ;
V_28 -> V_19 = true ;
break;
case V_50 :
V_31 = 0 ;
V_28 -> V_19 = false ;
break;
default:
return - V_33 ;
}
switch ( V_46 & V_51 ) {
case V_52 :
V_31 |= V_53 ;
break;
case V_54 :
V_31 |= V_55 ;
break;
case V_56 :
V_31 |= V_57 ;
break;
case V_58 :
V_31 |= V_59 ;
break;
default:
return - V_33 ;
}
switch ( V_46 & V_60 ) {
case V_61 :
break;
case V_62 :
V_31 |= V_63 ;
break;
case V_64 :
V_31 |= V_65 ;
break;
case V_66 :
V_31 |= V_65 | V_63 ;
break;
default:
return - V_33 ;
}
F_4 ( V_8 -> V_13 , F_13 ( V_16 -> V_29 ) ,
~ V_45 , V_31 ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_16 ,
int V_67 , unsigned int V_30 , int V_68 )
{
struct V_8 * V_8 = F_2 ( V_16 -> V_7 ) ;
struct V_28 * V_28 = & V_8 -> V_18 [ V_16 -> V_29 ] ;
switch ( V_67 ) {
case V_21 :
case V_69 :
break;
default:
return - V_33 ;
}
V_28 -> V_32 = V_30 ;
V_28 -> V_20 = V_67 ;
F_4 ( V_8 -> V_13 , F_11 ( V_16 -> V_29 ) ,
V_70 , V_67 << 5 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , int V_9 ,
int V_14 , unsigned int V_71 , unsigned int V_72 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
unsigned int V_73 = 0 ;
unsigned int V_74 , V_75 , V_76 , V_77 , V_78 , V_79 , V_80 ;
switch ( V_9 ) {
case V_81 :
case V_82 :
break;
default:
return - V_33 ;
}
switch ( V_14 ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
break;
default:
return - V_33 ;
}
if ( V_71 < 7813 || V_71 > 27000000 )
return - V_33 ;
if ( V_72 < 45158000 || V_72 > 49152000 )
return - V_33 ;
while ( V_71 < 8000000 ) {
V_71 *= 2 ;
V_73 ++ ;
}
if ( V_72 % V_71 != 0 ) {
V_74 = F_17 ( V_71 , 13500000 ) ;
V_71 /= V_74 ;
V_75 = V_72 / V_71 ;
V_78 = V_72 % V_71 ;
V_79 = F_18 ( V_78 , V_71 ) ;
V_76 = V_78 / V_79 ;
V_77 = V_71 / V_79 ;
V_74 -- ;
V_80 = 1 ;
} else {
V_75 = V_72 / V_71 ;
V_76 = 0 ;
V_77 = 0 ;
V_74 = 0 ;
V_80 = 0 ;
}
if ( V_75 < 2 || V_75 > 8 || V_74 > 3 || V_77 > 0xffff || V_76 > 0xffff )
return - V_33 ;
if ( V_73 ) {
V_73 = 11 - V_73 ;
F_4 ( V_8 -> V_13 , F_5 ( V_9 ) ,
V_95 , 0 ) ;
} else {
F_4 ( V_8 -> V_13 , F_5 ( V_9 ) ,
V_95 ,
V_95 ) ;
}
F_19 ( V_8 -> V_13 , F_20 ( V_9 ) ,
( V_14 << 4 ) | V_73 ) ;
F_19 ( V_8 -> V_13 , F_21 ( V_9 ) , ( V_77 >> 8 ) & 0xff ) ;
F_19 ( V_8 -> V_13 , F_22 ( V_9 ) , V_77 & 0xff ) ;
F_19 ( V_8 -> V_13 , F_23 ( V_9 ) , ( V_76 >> 8 ) & 0xff ) ;
F_19 ( V_8 -> V_13 , F_24 ( V_9 ) , V_76 & 0xff ) ;
F_19 ( V_8 -> V_13 , F_25 ( V_9 ) ,
( V_75 << 3 ) | ( V_74 << 1 ) | V_80 ) ;
F_4 ( V_8 -> V_13 , F_26 ( V_9 ) , 0x3f , 0x09 ) ;
return 0 ;
}
static void F_27 ( struct V_8 * V_8 ,
unsigned int V_96 , T_1 * V_97 )
{
unsigned int V_78 ;
for ( V_78 = 0 ; V_78 < V_98 ; ++ V_78 )
F_19 ( V_8 -> V_13 , F_28 ( V_96 ) + V_78 , V_97 [ V_78 ] ) ;
}
static bool F_29 ( enum V_99 V_100 )
{
switch ( V_100 ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
return true ;
default:
break;
}
return false ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
struct V_105 * V_106 = V_7 -> V_107 -> V_108 ;
bool V_109 = false ;
unsigned int V_11 ;
int V_110 ;
int V_78 ;
V_110 = F_31 ( V_7 , 0 , 0 , V_111 ) ;
if ( V_110 ) {
F_32 ( V_7 -> V_107 , L_3 , V_110 ) ;
return V_110 ;
}
if ( V_106 ) {
if ( V_106 -> V_112 > F_33 ( V_106 -> V_113 ) )
return - V_33 ;
if ( ! F_29 ( V_106 -> V_114 ) ||
! F_29 ( V_106 -> V_115 ) )
return - V_33 ;
for ( V_78 = 0 ; V_78 < V_106 -> V_112 ; ++ V_78 ) {
F_27 ( V_8 , V_78 ,
V_106 -> V_113 [ V_78 ] ) ;
}
F_34 ( V_7 , V_116 ,
V_106 -> V_112 ) ;
V_11 = 0 ;
for ( V_78 = 0 ; V_78 < 4 ; ++ V_78 ) {
if ( V_106 -> V_117 [ V_78 ] )
V_11 |= F_35 ( V_78 ) ;
}
F_19 ( V_8 -> V_13 , V_118 , V_11 ) ;
V_11 = 0 ;
if ( V_106 -> V_109 )
V_11 |= V_119 ;
if ( V_106 -> V_120 )
V_11 |= V_121 ;
F_19 ( V_8 -> V_13 , V_122 , V_11 ) ;
V_109 = V_106 -> V_109 ;
F_19 ( V_8 -> V_13 , V_123 ,
( V_106 -> V_114 << V_124 ) |
( V_106 -> V_115 << V_125 ) ) ;
}
if ( ! V_109 ) {
F_34 ( V_7 , V_126 ,
F_33 ( V_126 ) ) ;
}
F_19 ( V_8 -> V_13 , V_127 ,
V_128 | V_129 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
enum V_130 V_131 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
switch ( V_131 ) {
case V_132 :
break;
case V_133 :
break;
case V_134 :
F_4 ( V_8 -> V_13 , V_135 ,
V_136 , V_136 ) ;
break;
case V_137 :
F_4 ( V_8 -> V_13 , V_135 ,
V_136 , 0 ) ;
break;
}
V_7 -> V_138 . V_139 = V_131 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
F_36 ( V_7 , V_137 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
int V_110 ;
V_110 = F_36 ( V_7 , V_137 ) ;
F_39 ( V_8 -> V_13 , true ) ;
return V_110 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
F_39 ( V_8 -> V_13 , false ) ;
F_36 ( V_7 , V_134 ) ;
F_41 ( V_8 -> V_13 ) ;
return 0 ;
}
static bool F_42 ( struct V_140 * V_107 , unsigned int V_141 )
{
switch ( V_141 ) {
case V_142 :
case V_143 :
return true ;
default:
return false ;
}
}
static int F_43 ( struct V_144 * V_145 ,
const struct V_146 * V_29 )
{
struct V_8 * V_8 ;
int V_110 ;
V_8 = F_44 ( & V_145 -> V_107 , sizeof( * V_8 ) , V_147 ) ;
if ( ! V_8 )
return - V_148 ;
V_8 -> V_13 = F_45 ( V_145 ,
& V_149 ) ;
if ( F_46 ( V_8 -> V_13 ) )
return F_47 ( V_8 -> V_13 ) ;
F_19 ( V_8 -> V_13 , V_142 , 0x00 ) ;
F_48 ( & V_145 -> V_107 , V_8 ) ;
V_110 = F_49 ( & V_145 -> V_107 , & V_150 ,
V_151 , F_33 ( V_151 ) ) ;
return V_110 ;
}
static int F_50 ( struct V_144 * V_145 )
{
F_51 ( & V_145 -> V_107 ) ;
return 0 ;
}
