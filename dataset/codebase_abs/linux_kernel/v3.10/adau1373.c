static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned int V_8 = V_2 -> V_9 [ 3 ] - '1' ;
unsigned int V_10 ;
if ( F_2 ( V_5 ) )
V_10 = V_11 ;
else
V_10 = 0 ;
F_3 ( V_7 , F_4 ( V_8 ) ,
V_11 , V_10 ) ;
if ( F_2 ( V_5 ) )
F_5 ( 5 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_12 ,
struct V_1 * V_13 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_14 * V_14 = F_7 ( V_7 ) ;
unsigned int V_15 ;
const char * V_16 ;
V_15 = V_13 -> V_9 [ 3 ] - '1' ;
if ( ! V_14 -> V_17 [ V_15 ] . V_18 )
return 0 ;
if ( V_14 -> V_17 [ V_15 ] . V_19 == V_20 )
V_16 = L_1 ;
else
V_16 = L_2 ;
return strcmp ( V_12 -> V_9 , V_16 ) == 0 ;
}
static int F_8 ( struct V_1 * V_12 ,
struct V_1 * V_13 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_14 * V_14 = F_7 ( V_7 ) ;
unsigned int V_15 ;
V_15 = V_13 -> V_9 [ 3 ] - '1' ;
return V_14 -> V_17 [ V_15 ] . V_21 ;
}
static int F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 , struct V_26 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_14 * V_14 = F_7 ( V_7 ) ;
struct V_27 * V_27 = & V_14 -> V_17 [ V_15 -> V_28 ] ;
unsigned int div ;
unsigned int V_29 ;
unsigned int V_30 ;
V_29 = V_27 -> V_31 ;
if ( V_29 % F_10 ( V_25 ) != 0 )
return - V_32 ;
switch ( V_29 / F_10 ( V_25 ) ) {
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
return - V_32 ;
}
V_27 -> V_21 = ( div != 0 ) ;
F_3 ( V_7 , F_11 ( V_15 -> V_28 ) ,
V_33 | V_34 ,
( div << 2 ) | V_35 ) ;
switch ( F_12 ( V_25 ) ) {
case V_36 :
V_30 = V_37 ;
break;
case V_38 :
V_30 = V_39 ;
break;
case V_40 :
V_30 = V_41 ;
break;
case V_42 :
V_30 = V_43 ;
break;
default:
return - V_32 ;
}
return F_3 ( V_7 , F_13 ( V_15 -> V_28 ) ,
V_44 , V_30 ) ;
}
static int F_14 ( struct V_26 * V_15 , unsigned int V_45 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_14 * V_14 = F_7 ( V_7 ) ;
struct V_27 * V_27 = & V_14 -> V_17 [ V_15 -> V_28 ] ;
unsigned int V_30 ;
switch ( V_45 & V_46 ) {
case V_47 :
V_30 = V_48 ;
V_27 -> V_18 = true ;
break;
case V_49 :
V_30 = 0 ;
V_27 -> V_18 = false ;
break;
default:
return - V_32 ;
}
switch ( V_45 & V_50 ) {
case V_51 :
V_30 |= V_52 ;
break;
case V_53 :
V_30 |= V_54 ;
break;
case V_55 :
V_30 |= V_56 ;
break;
case V_57 :
V_30 |= V_58 ;
break;
default:
return - V_32 ;
}
switch ( V_45 & V_59 ) {
case V_60 :
break;
case V_61 :
V_30 |= V_62 ;
break;
case V_63 :
V_30 |= V_64 ;
break;
case V_65 :
V_30 |= V_64 | V_62 ;
break;
default:
return - V_32 ;
}
F_3 ( V_7 , F_13 ( V_15 -> V_28 ) ,
~ V_44 , V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_15 ,
int V_66 , unsigned int V_29 , int V_67 )
{
struct V_14 * V_14 = F_7 ( V_15 -> V_7 ) ;
struct V_27 * V_27 = & V_14 -> V_17 [ V_15 -> V_28 ] ;
switch ( V_66 ) {
case V_20 :
case V_68 :
break;
default:
return - V_32 ;
}
V_27 -> V_31 = V_29 ;
V_27 -> V_19 = V_66 ;
F_3 ( V_15 -> V_7 , F_11 ( V_15 -> V_28 ) ,
V_69 , V_66 << 5 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , int V_8 ,
int V_12 , unsigned int V_70 , unsigned int V_71 )
{
unsigned int V_72 = 0 ;
unsigned int V_73 , V_74 , V_75 , V_76 , V_77 , V_78 , V_79 ;
switch ( V_8 ) {
case V_80 :
case V_81 :
break;
default:
return - V_32 ;
}
switch ( V_12 ) {
case V_82 :
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
break;
default:
return - V_32 ;
}
if ( V_70 < 7813 || V_70 > 27000000 )
return - V_32 ;
if ( V_71 < 45158000 || V_71 > 49152000 )
return - V_32 ;
while ( V_70 < 8000000 ) {
V_70 *= 2 ;
V_72 ++ ;
}
if ( V_71 % V_70 != 0 ) {
V_73 = F_17 ( V_70 , 13500000 ) ;
V_70 /= V_73 ;
V_74 = V_71 / V_70 ;
V_77 = V_71 % V_70 ;
V_78 = F_18 ( V_77 , V_70 ) ;
V_75 = V_77 / V_78 ;
V_76 = V_70 / V_78 ;
V_73 -- ;
V_79 = 1 ;
} else {
V_74 = V_71 / V_70 ;
V_75 = 0 ;
V_76 = 0 ;
V_73 = 0 ;
V_79 = 0 ;
}
if ( V_74 < 2 || V_74 > 8 || V_73 > 3 || V_76 > 0xffff || V_75 > 0xffff )
return - V_32 ;
if ( V_72 ) {
V_72 = 11 - V_72 ;
F_3 ( V_7 , F_4 ( V_8 ) ,
V_94 , 0 ) ;
} else {
F_3 ( V_7 , F_4 ( V_8 ) ,
V_94 ,
V_94 ) ;
}
F_19 ( V_7 , F_20 ( V_8 ) ,
( V_12 << 4 ) | V_72 ) ;
F_19 ( V_7 , F_21 ( V_8 ) , ( V_76 >> 8 ) & 0xff ) ;
F_19 ( V_7 , F_22 ( V_8 ) , V_76 & 0xff ) ;
F_19 ( V_7 , F_23 ( V_8 ) , ( V_75 >> 8 ) & 0xff ) ;
F_19 ( V_7 , F_24 ( V_8 ) , V_75 & 0xff ) ;
F_19 ( V_7 , F_25 ( V_8 ) ,
( V_74 << 3 ) | ( V_73 << 1 ) | V_79 ) ;
F_3 ( V_7 , F_26 ( V_8 ) , 0x3f , 0x09 ) ;
return 0 ;
}
static void F_27 ( struct V_6 * V_7 ,
unsigned int V_95 , T_1 * V_96 )
{
unsigned int V_77 ;
for ( V_77 = 0 ; V_77 < V_97 ; ++ V_77 )
F_19 ( V_7 , F_28 ( V_95 ) + V_77 , V_96 [ V_77 ] ) ;
}
static bool F_29 ( enum V_98 V_99 )
{
switch ( V_99 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
return true ;
default:
break;
}
return false ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_104 * V_105 = V_7 -> V_106 -> V_107 ;
bool V_108 = false ;
unsigned int V_10 ;
int V_109 ;
int V_77 ;
V_109 = F_31 ( V_7 , 8 , 8 , V_110 ) ;
if ( V_109 ) {
F_32 ( V_7 -> V_106 , L_3 , V_109 ) ;
return V_109 ;
}
if ( V_105 ) {
if ( V_105 -> V_111 > F_33 ( V_105 -> V_112 ) )
return - V_32 ;
if ( ! F_29 ( V_105 -> V_113 ) ||
! F_29 ( V_105 -> V_114 ) )
return - V_32 ;
for ( V_77 = 0 ; V_77 < V_105 -> V_111 ; ++ V_77 ) {
F_27 ( V_7 , V_77 ,
V_105 -> V_112 [ V_77 ] ) ;
}
F_34 ( V_7 , V_115 ,
V_105 -> V_111 ) ;
V_10 = 0 ;
for ( V_77 = 0 ; V_77 < 4 ; ++ V_77 ) {
if ( V_105 -> V_116 [ V_77 ] )
V_10 |= F_35 ( V_77 ) ;
}
F_19 ( V_7 , V_117 , V_10 ) ;
V_10 = 0 ;
if ( V_105 -> V_108 )
V_10 |= V_118 ;
if ( V_105 -> V_119 )
V_10 |= V_120 ;
F_19 ( V_7 , V_121 , V_10 ) ;
V_108 = V_105 -> V_108 ;
F_19 ( V_7 , V_122 ,
( V_105 -> V_113 << V_123 ) |
( V_105 -> V_114 << V_124 ) ) ;
}
if ( ! V_108 ) {
F_34 ( V_7 , V_125 ,
F_33 ( V_125 ) ) ;
}
F_19 ( V_7 , V_126 ,
V_127 | V_128 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
enum V_129 V_130 )
{
switch ( V_130 ) {
case V_131 :
break;
case V_132 :
break;
case V_133 :
F_3 ( V_7 , V_134 ,
V_135 , V_135 ) ;
break;
case V_136 :
F_3 ( V_7 , V_134 ,
V_135 , 0 ) ;
break;
}
V_7 -> V_137 . V_138 = V_130 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
F_36 ( V_7 , V_136 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
return F_36 ( V_7 , V_136 ) ;
}
static int F_39 ( struct V_6 * V_7 )
{
F_36 ( V_7 , V_133 ) ;
F_40 ( V_7 ) ;
return 0 ;
}
static int F_41 ( struct V_139 * V_140 ,
const struct V_141 * V_28 )
{
struct V_14 * V_14 ;
int V_109 ;
V_14 = F_42 ( & V_140 -> V_106 , sizeof( * V_14 ) , V_142 ) ;
if ( ! V_14 )
return - V_143 ;
F_43 ( & V_140 -> V_106 , V_14 ) ;
V_109 = F_44 ( & V_140 -> V_106 , & V_144 ,
V_145 , F_33 ( V_145 ) ) ;
return V_109 ;
}
static int F_45 ( struct V_139 * V_140 )
{
F_46 ( & V_140 -> V_106 ) ;
return 0 ;
}
