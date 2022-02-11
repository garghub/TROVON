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
~ V_33 , ( div << 2 ) | V_34 ) ;
switch ( F_12 ( V_25 ) ) {
case V_35 :
V_30 = V_36 ;
break;
case V_37 :
V_30 = V_38 ;
break;
case V_39 :
V_30 = V_40 ;
break;
case V_41 :
V_30 = V_42 ;
break;
default:
return - V_32 ;
}
return F_3 ( V_7 , F_13 ( V_15 -> V_28 ) ,
V_43 , V_30 ) ;
}
static int F_14 ( struct V_26 * V_15 , unsigned int V_44 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_14 * V_14 = F_7 ( V_7 ) ;
struct V_27 * V_27 = & V_14 -> V_17 [ V_15 -> V_28 ] ;
unsigned int V_30 ;
switch ( V_44 & V_45 ) {
case V_46 :
V_30 = V_47 ;
V_27 -> V_18 = true ;
break;
case V_48 :
V_30 = 0 ;
V_27 -> V_18 = false ;
break;
default:
return - V_32 ;
}
switch ( V_44 & V_49 ) {
case V_50 :
V_30 |= V_51 ;
break;
case V_52 :
V_30 |= V_53 ;
break;
case V_54 :
V_30 |= V_55 ;
break;
case V_56 :
V_30 |= V_57 ;
break;
default:
return - V_32 ;
}
switch ( V_44 & V_58 ) {
case V_59 :
break;
case V_60 :
V_30 |= V_61 ;
break;
case V_62 :
V_30 |= V_63 ;
break;
case V_64 :
V_30 |= V_63 | V_61 ;
break;
default:
return - V_32 ;
}
F_3 ( V_7 , F_13 ( V_15 -> V_28 ) ,
~ V_43 , V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_15 ,
int V_65 , unsigned int V_29 , int V_66 )
{
struct V_14 * V_14 = F_7 ( V_15 -> V_7 ) ;
struct V_27 * V_27 = & V_14 -> V_17 [ V_15 -> V_28 ] ;
switch ( V_65 ) {
case V_20 :
case V_67 :
break;
default:
return - V_32 ;
}
V_27 -> V_31 = V_29 ;
V_27 -> V_19 = V_65 ;
F_3 ( V_15 -> V_7 , F_11 ( V_15 -> V_28 ) ,
V_33 , V_65 << 5 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , int V_8 ,
int V_12 , unsigned int V_68 , unsigned int V_69 )
{
unsigned int V_70 = 0 ;
unsigned int V_71 , V_72 , V_73 , V_74 , V_75 , V_76 , V_77 ;
switch ( V_8 ) {
case V_78 :
case V_79 :
break;
default:
return - V_32 ;
}
switch ( V_12 ) {
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
case V_91 :
break;
default:
return - V_32 ;
}
if ( V_68 < 7813 || V_68 > 27000000 )
return - V_32 ;
if ( V_69 < 45158000 || V_69 > 49152000 )
return - V_32 ;
while ( V_68 < 8000000 ) {
V_68 *= 2 ;
V_70 ++ ;
}
if ( V_69 % V_68 != 0 ) {
V_71 = F_17 ( V_68 , 13500000 ) ;
V_68 /= V_71 ;
V_72 = V_69 / V_68 ;
V_75 = V_69 % V_68 ;
V_76 = F_18 ( V_75 , V_68 ) ;
V_73 = V_75 / V_76 ;
V_74 = V_68 / V_76 ;
V_71 -- ;
V_77 = 1 ;
} else {
V_72 = V_69 / V_68 ;
V_73 = 0 ;
V_74 = 0 ;
V_71 = 0 ;
V_77 = 0 ;
}
if ( V_72 < 2 || V_72 > 8 || V_71 > 3 || V_74 > 0xffff || V_73 > 0xffff )
return - V_32 ;
if ( V_70 ) {
V_70 = 11 - V_70 ;
F_3 ( V_7 , F_4 ( V_8 ) ,
V_92 , 0 ) ;
} else {
F_3 ( V_7 , F_4 ( V_8 ) ,
V_92 ,
V_92 ) ;
}
F_19 ( V_7 , F_20 ( V_8 ) ,
( V_12 << 4 ) | V_70 ) ;
F_19 ( V_7 , F_21 ( V_8 ) , ( V_74 >> 8 ) & 0xff ) ;
F_19 ( V_7 , F_22 ( V_8 ) , V_74 & 0xff ) ;
F_19 ( V_7 , F_23 ( V_8 ) , ( V_73 >> 8 ) & 0xff ) ;
F_19 ( V_7 , F_24 ( V_8 ) , V_73 & 0xff ) ;
F_19 ( V_7 , F_25 ( V_8 ) ,
( V_72 << 3 ) | ( V_71 << 1 ) | V_77 ) ;
F_3 ( V_7 , F_26 ( V_8 ) , 0x3f , 0x09 ) ;
return 0 ;
}
static void F_27 ( struct V_6 * V_7 ,
unsigned int V_93 , T_1 * V_94 )
{
unsigned int V_75 ;
for ( V_75 = 0 ; V_75 < V_95 ; ++ V_75 )
F_19 ( V_7 , F_28 ( V_93 ) + V_75 , V_94 [ V_75 ] ) ;
}
static bool F_29 ( enum V_96 V_97 )
{
switch ( V_97 ) {
case V_98 :
case V_99 :
case V_100 :
case V_101 :
return true ;
default:
break;
}
return false ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_102 * V_103 = V_7 -> V_104 -> V_105 ;
bool V_106 = false ;
unsigned int V_10 ;
int V_107 ;
int V_75 ;
V_107 = F_31 ( V_7 , 8 , 8 , V_108 ) ;
if ( V_107 ) {
F_32 ( V_7 -> V_104 , L_3 , V_107 ) ;
return V_107 ;
}
V_7 -> V_109 . V_110 = true ;
if ( V_103 ) {
if ( V_103 -> V_111 > F_33 ( V_103 -> V_112 ) )
return - V_32 ;
if ( ! F_29 ( V_103 -> V_113 ) ||
! F_29 ( V_103 -> V_114 ) )
return - V_32 ;
for ( V_75 = 0 ; V_75 < V_103 -> V_111 ; ++ V_75 ) {
F_27 ( V_7 , V_75 ,
V_103 -> V_112 [ V_75 ] ) ;
}
F_34 ( V_7 , V_115 ,
V_103 -> V_111 ) ;
V_10 = 0 ;
for ( V_75 = 0 ; V_75 < 4 ; ++ V_75 ) {
if ( V_103 -> V_116 [ V_75 ] )
V_10 |= F_35 ( V_75 ) ;
}
F_19 ( V_7 , V_117 , V_10 ) ;
V_10 = 0 ;
if ( V_103 -> V_106 )
V_10 |= V_118 ;
if ( V_103 -> V_119 )
V_10 |= V_120 ;
F_19 ( V_7 , V_121 , V_10 ) ;
V_106 = V_103 -> V_106 ;
F_19 ( V_7 , V_122 ,
( V_103 -> V_113 << V_123 ) |
( V_103 -> V_114 << V_124 ) ) ;
}
if ( ! V_106 ) {
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
V_7 -> V_109 . V_137 = V_130 ;
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
static int T_2 F_41 ( struct V_138 * V_139 ,
const struct V_140 * V_28 )
{
struct V_14 * V_14 ;
int V_107 ;
V_14 = F_42 ( & V_139 -> V_104 , sizeof( * V_14 ) , V_141 ) ;
if ( ! V_14 )
return - V_142 ;
F_43 ( & V_139 -> V_104 , V_14 ) ;
V_107 = F_44 ( & V_139 -> V_104 , & V_143 ,
V_144 , F_33 ( V_144 ) ) ;
return V_107 ;
}
static int T_3 F_45 ( struct V_138 * V_139 )
{
F_46 ( & V_139 -> V_104 ) ;
return 0 ;
}
static int T_4 F_47 ( void )
{
return F_48 ( & V_145 ) ;
}
static void T_5 F_49 ( void )
{
F_50 ( & V_145 ) ;
}
