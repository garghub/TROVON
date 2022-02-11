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
case 16 :
V_31 = V_37 ;
break;
case 20 :
V_31 = V_38 ;
break;
case 24 :
V_31 = V_39 ;
break;
case 32 :
V_31 = V_40 ;
break;
default:
return - V_33 ;
}
return F_4 ( V_8 -> V_13 , F_13 ( V_16 -> V_29 ) ,
V_41 , V_31 ) ;
}
static int F_14 ( struct V_27 * V_16 , unsigned int V_42 )
{
struct V_6 * V_7 = V_16 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 ) ;
struct V_28 * V_28 = & V_8 -> V_18 [ V_16 -> V_29 ] ;
unsigned int V_31 ;
switch ( V_42 & V_43 ) {
case V_44 :
V_31 = V_45 ;
V_28 -> V_19 = true ;
break;
case V_46 :
V_31 = 0 ;
V_28 -> V_19 = false ;
break;
default:
return - V_33 ;
}
switch ( V_42 & V_47 ) {
case V_48 :
V_31 |= V_49 ;
break;
case V_50 :
V_31 |= V_51 ;
break;
case V_52 :
V_31 |= V_53 ;
break;
case V_54 :
V_31 |= V_55 ;
break;
default:
return - V_33 ;
}
switch ( V_42 & V_56 ) {
case V_57 :
break;
case V_58 :
V_31 |= V_59 ;
break;
case V_60 :
V_31 |= V_61 ;
break;
case V_62 :
V_31 |= V_61 | V_59 ;
break;
default:
return - V_33 ;
}
F_4 ( V_8 -> V_13 , F_13 ( V_16 -> V_29 ) ,
~ V_41 , V_31 ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_16 ,
int V_63 , unsigned int V_30 , int V_64 )
{
struct V_8 * V_8 = F_2 ( V_16 -> V_7 ) ;
struct V_28 * V_28 = & V_8 -> V_18 [ V_16 -> V_29 ] ;
switch ( V_63 ) {
case V_21 :
case V_65 :
break;
default:
return - V_33 ;
}
V_28 -> V_32 = V_30 ;
V_28 -> V_20 = V_63 ;
F_4 ( V_8 -> V_13 , F_11 ( V_16 -> V_29 ) ,
V_66 , V_63 << 5 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , int V_9 ,
int V_14 , unsigned int V_67 , unsigned int V_68 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
unsigned int V_69 = 0 ;
unsigned int V_70 , V_71 , V_72 , V_73 , V_74 , V_75 , V_76 ;
switch ( V_9 ) {
case V_77 :
case V_78 :
break;
default:
return - V_33 ;
}
switch ( V_14 ) {
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
break;
default:
return - V_33 ;
}
if ( V_67 < 7813 || V_67 > 27000000 )
return - V_33 ;
if ( V_68 < 45158000 || V_68 > 49152000 )
return - V_33 ;
while ( V_67 < 8000000 ) {
V_67 *= 2 ;
V_69 ++ ;
}
if ( V_68 % V_67 != 0 ) {
V_70 = F_17 ( V_67 , 13500000 ) ;
V_67 /= V_70 ;
V_71 = V_68 / V_67 ;
V_74 = V_68 % V_67 ;
V_75 = F_18 ( V_74 , V_67 ) ;
V_72 = V_74 / V_75 ;
V_73 = V_67 / V_75 ;
V_70 -- ;
V_76 = 1 ;
} else {
V_71 = V_68 / V_67 ;
V_72 = 0 ;
V_73 = 0 ;
V_70 = 0 ;
V_76 = 0 ;
}
if ( V_71 < 2 || V_71 > 8 || V_70 > 3 || V_73 > 0xffff || V_72 > 0xffff )
return - V_33 ;
if ( V_69 ) {
V_69 = 11 - V_69 ;
F_4 ( V_8 -> V_13 , F_5 ( V_9 ) ,
V_91 , 0 ) ;
} else {
F_4 ( V_8 -> V_13 , F_5 ( V_9 ) ,
V_91 ,
V_91 ) ;
}
F_19 ( V_8 -> V_13 , F_20 ( V_9 ) ,
( V_14 << 4 ) | V_69 ) ;
F_19 ( V_8 -> V_13 , F_21 ( V_9 ) , ( V_73 >> 8 ) & 0xff ) ;
F_19 ( V_8 -> V_13 , F_22 ( V_9 ) , V_73 & 0xff ) ;
F_19 ( V_8 -> V_13 , F_23 ( V_9 ) , ( V_72 >> 8 ) & 0xff ) ;
F_19 ( V_8 -> V_13 , F_24 ( V_9 ) , V_72 & 0xff ) ;
F_19 ( V_8 -> V_13 , F_25 ( V_9 ) ,
( V_71 << 3 ) | ( V_70 << 1 ) | V_76 ) ;
F_4 ( V_8 -> V_13 , F_26 ( V_9 ) , 0x3f , 0x09 ) ;
return 0 ;
}
static void F_27 ( struct V_8 * V_8 ,
unsigned int V_92 , T_1 * V_93 )
{
unsigned int V_74 ;
for ( V_74 = 0 ; V_74 < V_94 ; ++ V_74 )
F_19 ( V_8 -> V_13 , F_28 ( V_92 ) + V_74 , V_93 [ V_74 ] ) ;
}
static bool F_29 ( enum V_95 V_96 )
{
switch ( V_96 ) {
case V_97 :
case V_98 :
case V_99 :
case V_100 :
return true ;
default:
break;
}
return false ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
struct V_101 * V_102 = V_7 -> V_103 -> V_104 ;
bool V_105 = false ;
unsigned int V_11 ;
int V_106 ;
int V_74 ;
V_106 = F_31 ( V_7 , 0 , 0 , V_107 ) ;
if ( V_106 ) {
F_32 ( V_7 -> V_103 , L_3 , V_106 ) ;
return V_106 ;
}
if ( V_102 ) {
if ( V_102 -> V_108 > F_33 ( V_102 -> V_109 ) )
return - V_33 ;
if ( ! F_29 ( V_102 -> V_110 ) ||
! F_29 ( V_102 -> V_111 ) )
return - V_33 ;
for ( V_74 = 0 ; V_74 < V_102 -> V_108 ; ++ V_74 ) {
F_27 ( V_8 , V_74 ,
V_102 -> V_109 [ V_74 ] ) ;
}
F_34 ( V_7 , V_112 ,
V_102 -> V_108 ) ;
V_11 = 0 ;
for ( V_74 = 0 ; V_74 < 4 ; ++ V_74 ) {
if ( V_102 -> V_113 [ V_74 ] )
V_11 |= F_35 ( V_74 ) ;
}
F_19 ( V_8 -> V_13 , V_114 , V_11 ) ;
V_11 = 0 ;
if ( V_102 -> V_105 )
V_11 |= V_115 ;
if ( V_102 -> V_116 )
V_11 |= V_117 ;
F_19 ( V_8 -> V_13 , V_118 , V_11 ) ;
V_105 = V_102 -> V_105 ;
F_19 ( V_8 -> V_13 , V_119 ,
( V_102 -> V_110 << V_120 ) |
( V_102 -> V_111 << V_121 ) ) ;
}
if ( ! V_105 ) {
F_34 ( V_7 , V_122 ,
F_33 ( V_122 ) ) ;
}
F_19 ( V_8 -> V_13 , V_123 ,
V_124 | V_125 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
enum V_126 V_127 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
switch ( V_127 ) {
case V_128 :
break;
case V_129 :
break;
case V_130 :
F_4 ( V_8 -> V_13 , V_131 ,
V_132 , V_132 ) ;
break;
case V_133 :
F_4 ( V_8 -> V_13 , V_131 ,
V_132 , 0 ) ;
break;
}
V_7 -> V_134 . V_135 = V_127 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
F_36 ( V_7 , V_133 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
int V_106 ;
V_106 = F_36 ( V_7 , V_133 ) ;
F_39 ( V_8 -> V_13 , true ) ;
return V_106 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
F_39 ( V_8 -> V_13 , false ) ;
F_36 ( V_7 , V_130 ) ;
F_41 ( V_8 -> V_13 ) ;
return 0 ;
}
static bool F_42 ( struct V_136 * V_103 , unsigned int V_137 )
{
switch ( V_137 ) {
case V_138 :
case V_139 :
return true ;
default:
return false ;
}
}
static int F_43 ( struct V_140 * V_141 ,
const struct V_142 * V_29 )
{
struct V_8 * V_8 ;
int V_106 ;
V_8 = F_44 ( & V_141 -> V_103 , sizeof( * V_8 ) , V_143 ) ;
if ( ! V_8 )
return - V_144 ;
V_8 -> V_13 = F_45 ( V_141 ,
& V_145 ) ;
if ( F_46 ( V_8 -> V_13 ) )
return F_47 ( V_8 -> V_13 ) ;
F_19 ( V_8 -> V_13 , V_138 , 0x00 ) ;
F_48 ( & V_141 -> V_103 , V_8 ) ;
V_106 = F_49 ( & V_141 -> V_103 , & V_146 ,
V_147 , F_33 ( V_147 ) ) ;
return V_106 ;
}
static int F_50 ( struct V_140 * V_141 )
{
F_51 ( & V_141 -> V_103 ) ;
return 0 ;
}
