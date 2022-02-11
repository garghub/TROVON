static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_10 = V_2 -> V_11 [ 3 ] - '1' ;
unsigned int V_12 ;
if ( F_4 ( V_5 ) )
V_12 = V_13 ;
else
V_12 = 0 ;
F_5 ( V_9 -> V_14 , F_6 ( V_10 ) ,
V_13 , V_12 ) ;
if ( F_4 ( V_5 ) )
F_7 ( 5 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_15 ,
struct V_1 * V_16 )
{
struct V_6 * V_7 = F_2 ( V_15 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_17 ;
const char * V_18 ;
V_17 = V_16 -> V_11 [ 3 ] - '1' ;
if ( ! V_9 -> V_19 [ V_17 ] . V_20 )
return 0 ;
if ( V_9 -> V_19 [ V_17 ] . V_21 == V_22 )
V_18 = L_1 ;
else
V_18 = L_2 ;
return strcmp ( V_15 -> V_11 , V_18 ) == 0 ;
}
static int F_9 ( struct V_1 * V_15 ,
struct V_1 * V_16 )
{
struct V_6 * V_7 = F_2 ( V_15 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_17 ;
V_17 = V_16 -> V_11 [ 3 ] - '1' ;
return V_9 -> V_19 [ V_17 ] . V_23 ;
}
static int F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 , struct V_28 * V_17 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_29 * V_29 = & V_9 -> V_19 [ V_17 -> V_30 ] ;
unsigned int div ;
unsigned int V_31 ;
unsigned int V_32 ;
V_31 = V_29 -> V_33 ;
if ( V_31 % F_11 ( V_27 ) != 0 )
return - V_34 ;
switch ( V_31 / F_11 ( V_27 ) ) {
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
return - V_34 ;
}
V_29 -> V_23 = ( div != 0 ) ;
F_5 ( V_9 -> V_14 , F_12 ( V_17 -> V_30 ) ,
V_35 | V_36 ,
( div << 2 ) | V_37 ) ;
switch ( F_13 ( V_27 ) ) {
case 16 :
V_32 = V_38 ;
break;
case 20 :
V_32 = V_39 ;
break;
case 24 :
V_32 = V_40 ;
break;
case 32 :
V_32 = V_41 ;
break;
default:
return - V_34 ;
}
return F_5 ( V_9 -> V_14 , F_14 ( V_17 -> V_30 ) ,
V_42 , V_32 ) ;
}
static int F_15 ( struct V_28 * V_17 , unsigned int V_43 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_29 * V_29 = & V_9 -> V_19 [ V_17 -> V_30 ] ;
unsigned int V_32 ;
switch ( V_43 & V_44 ) {
case V_45 :
V_32 = V_46 ;
V_29 -> V_20 = true ;
break;
case V_47 :
V_32 = 0 ;
V_29 -> V_20 = false ;
break;
default:
return - V_34 ;
}
switch ( V_43 & V_48 ) {
case V_49 :
V_32 |= V_50 ;
break;
case V_51 :
V_32 |= V_52 ;
break;
case V_53 :
V_32 |= V_54 ;
break;
case V_55 :
V_32 |= V_56 ;
break;
default:
return - V_34 ;
}
switch ( V_43 & V_57 ) {
case V_58 :
break;
case V_59 :
V_32 |= V_60 ;
break;
case V_61 :
V_32 |= V_62 ;
break;
case V_63 :
V_32 |= V_62 | V_60 ;
break;
default:
return - V_34 ;
}
F_5 ( V_9 -> V_14 , F_14 ( V_17 -> V_30 ) ,
~ V_42 , V_32 ) ;
return 0 ;
}
static int F_16 ( struct V_28 * V_17 ,
int V_64 , unsigned int V_31 , int V_65 )
{
struct V_9 * V_9 = F_3 ( V_17 -> V_7 ) ;
struct V_29 * V_29 = & V_9 -> V_19 [ V_17 -> V_30 ] ;
switch ( V_64 ) {
case V_22 :
case V_66 :
break;
default:
return - V_34 ;
}
V_29 -> V_33 = V_31 ;
V_29 -> V_21 = V_64 ;
F_5 ( V_9 -> V_14 , F_12 ( V_17 -> V_30 ) ,
V_67 , V_64 << 5 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , int V_10 ,
int V_15 , unsigned int V_68 , unsigned int V_69 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
unsigned int V_70 = 0 ;
unsigned int V_71 , V_72 , V_73 , V_74 , V_75 , V_76 , V_77 ;
switch ( V_10 ) {
case V_78 :
case V_79 :
break;
default:
return - V_34 ;
}
switch ( V_15 ) {
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
return - V_34 ;
}
if ( V_68 < 7813 || V_68 > 27000000 )
return - V_34 ;
if ( V_69 < 45158000 || V_69 > 49152000 )
return - V_34 ;
while ( V_68 < 8000000 ) {
V_68 *= 2 ;
V_70 ++ ;
}
if ( V_69 % V_68 != 0 ) {
V_71 = F_18 ( V_68 , 13500000 ) ;
V_68 /= V_71 ;
V_72 = V_69 / V_68 ;
V_75 = V_69 % V_68 ;
V_76 = F_19 ( V_75 , V_68 ) ;
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
return - V_34 ;
if ( V_70 ) {
V_70 = 11 - V_70 ;
F_5 ( V_9 -> V_14 , F_6 ( V_10 ) ,
V_92 , 0 ) ;
} else {
F_5 ( V_9 -> V_14 , F_6 ( V_10 ) ,
V_92 ,
V_92 ) ;
}
F_20 ( V_9 -> V_14 , F_21 ( V_10 ) ,
( V_15 << 4 ) | V_70 ) ;
F_20 ( V_9 -> V_14 , F_22 ( V_10 ) , ( V_74 >> 8 ) & 0xff ) ;
F_20 ( V_9 -> V_14 , F_23 ( V_10 ) , V_74 & 0xff ) ;
F_20 ( V_9 -> V_14 , F_24 ( V_10 ) , ( V_73 >> 8 ) & 0xff ) ;
F_20 ( V_9 -> V_14 , F_25 ( V_10 ) , V_73 & 0xff ) ;
F_20 ( V_9 -> V_14 , F_26 ( V_10 ) ,
( V_72 << 3 ) | ( V_71 << 1 ) | V_77 ) ;
F_5 ( V_9 -> V_14 , F_27 ( V_10 ) , 0x3f , 0x09 ) ;
return 0 ;
}
static void F_28 ( struct V_9 * V_9 ,
unsigned int V_93 , T_1 * V_94 )
{
unsigned int V_75 ;
for ( V_75 = 0 ; V_75 < V_95 ; ++ V_75 )
F_20 ( V_9 -> V_14 , F_29 ( V_93 ) + V_75 , V_94 [ V_75 ] ) ;
}
static bool F_30 ( enum V_96 V_97 )
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
static int F_31 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_102 * V_103 = V_7 -> V_104 -> V_105 ;
bool V_106 = false ;
unsigned int V_12 ;
int V_75 ;
if ( V_103 ) {
if ( V_103 -> V_107 > F_32 ( V_103 -> V_108 ) )
return - V_34 ;
if ( ! F_30 ( V_103 -> V_109 ) ||
! F_30 ( V_103 -> V_110 ) )
return - V_34 ;
for ( V_75 = 0 ; V_75 < V_103 -> V_107 ; ++ V_75 ) {
F_28 ( V_9 , V_75 ,
V_103 -> V_108 [ V_75 ] ) ;
}
F_33 ( V_7 , V_111 ,
V_103 -> V_107 ) ;
V_12 = 0 ;
for ( V_75 = 0 ; V_75 < 4 ; ++ V_75 ) {
if ( V_103 -> V_112 [ V_75 ] )
V_12 |= F_34 ( V_75 ) ;
}
F_20 ( V_9 -> V_14 , V_113 , V_12 ) ;
V_12 = 0 ;
if ( V_103 -> V_106 )
V_12 |= V_114 ;
if ( V_103 -> V_115 )
V_12 |= V_116 ;
F_20 ( V_9 -> V_14 , V_117 , V_12 ) ;
V_106 = V_103 -> V_106 ;
F_20 ( V_9 -> V_14 , V_118 ,
( V_103 -> V_109 << V_119 ) |
( V_103 -> V_110 << V_120 ) ) ;
}
if ( ! V_106 ) {
F_33 ( V_7 , V_121 ,
F_32 ( V_121 ) ) ;
}
F_20 ( V_9 -> V_14 , V_122 ,
V_123 | V_124 ) ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 ,
enum V_125 V_126 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
switch ( V_126 ) {
case V_127 :
break;
case V_128 :
break;
case V_129 :
F_5 ( V_9 -> V_14 , V_130 ,
V_131 , V_131 ) ;
break;
case V_132 :
F_5 ( V_9 -> V_14 , V_130 ,
V_131 , 0 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
F_37 ( V_9 -> V_14 ) ;
return 0 ;
}
static bool F_38 ( struct V_133 * V_104 , unsigned int V_134 )
{
switch ( V_134 ) {
case V_135 :
case V_136 :
return true ;
default:
return false ;
}
}
static int F_39 ( struct V_137 * V_138 ,
const struct V_139 * V_30 )
{
struct V_9 * V_9 ;
int V_140 ;
V_9 = F_40 ( & V_138 -> V_104 , sizeof( * V_9 ) , V_141 ) ;
if ( ! V_9 )
return - V_142 ;
V_9 -> V_14 = F_41 ( V_138 ,
& V_143 ) ;
if ( F_42 ( V_9 -> V_14 ) )
return F_43 ( V_9 -> V_14 ) ;
F_20 ( V_9 -> V_14 , V_135 , 0x00 ) ;
F_44 ( & V_138 -> V_104 , V_9 ) ;
V_140 = F_45 ( & V_138 -> V_104 , & V_144 ,
V_145 , F_32 ( V_145 ) ) ;
return V_140 ;
}
static int F_46 ( struct V_137 * V_138 )
{
F_47 ( & V_138 -> V_104 ) ;
return 0 ;
}
