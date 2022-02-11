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
T_1 V_71 [ 5 ] ;
int V_72 ;
switch ( V_10 ) {
case V_73 :
case V_74 :
break;
default:
return - V_34 ;
}
switch ( V_15 ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
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
V_72 = F_18 ( V_68 , V_69 , V_71 ) ;
if ( V_72 )
return - V_34 ;
if ( V_70 ) {
V_70 = 11 - V_70 ;
F_5 ( V_9 -> V_14 , F_6 ( V_10 ) ,
V_87 , 0 ) ;
} else {
F_5 ( V_9 -> V_14 , F_6 ( V_10 ) ,
V_87 ,
V_87 ) ;
}
F_19 ( V_9 -> V_14 , F_20 ( V_10 ) ,
( V_15 << 4 ) | V_70 ) ;
F_19 ( V_9 -> V_14 , F_21 ( V_10 ) , V_71 [ 0 ] ) ;
F_19 ( V_9 -> V_14 , F_22 ( V_10 ) , V_71 [ 1 ] ) ;
F_19 ( V_9 -> V_14 , F_23 ( V_10 ) , V_71 [ 2 ] ) ;
F_19 ( V_9 -> V_14 , F_24 ( V_10 ) , V_71 [ 3 ] ) ;
F_19 ( V_9 -> V_14 , F_25 ( V_10 ) , V_71 [ 4 ] ) ;
F_5 ( V_9 -> V_14 , F_26 ( V_10 ) , 0x3f , 0x09 ) ;
return 0 ;
}
static void F_27 ( struct V_9 * V_9 ,
unsigned int V_88 , T_1 * V_89 )
{
unsigned int V_90 ;
for ( V_90 = 0 ; V_90 < V_91 ; ++ V_90 )
F_19 ( V_9 -> V_14 , F_28 ( V_88 ) + V_90 , V_89 [ V_90 ] ) ;
}
static bool F_29 ( enum V_92 V_93 )
{
switch ( V_93 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
return true ;
default:
break;
}
return false ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_98 * V_99 = V_7 -> V_100 -> V_101 ;
bool V_102 = false ;
unsigned int V_12 ;
int V_90 ;
if ( V_99 ) {
if ( V_99 -> V_103 > F_31 ( V_99 -> V_104 ) )
return - V_34 ;
if ( ! F_29 ( V_99 -> V_105 ) ||
! F_29 ( V_99 -> V_106 ) )
return - V_34 ;
for ( V_90 = 0 ; V_90 < V_99 -> V_103 ; ++ V_90 ) {
F_27 ( V_9 , V_90 ,
V_99 -> V_104 [ V_90 ] ) ;
}
F_32 ( V_7 , V_107 ,
V_99 -> V_103 ) ;
V_12 = 0 ;
for ( V_90 = 0 ; V_90 < 4 ; ++ V_90 ) {
if ( V_99 -> V_108 [ V_90 ] )
V_12 |= F_33 ( V_90 ) ;
}
F_19 ( V_9 -> V_14 , V_109 , V_12 ) ;
V_12 = 0 ;
if ( V_99 -> V_102 )
V_12 |= V_110 ;
if ( V_99 -> V_111 )
V_12 |= V_112 ;
F_19 ( V_9 -> V_14 , V_113 , V_12 ) ;
V_102 = V_99 -> V_102 ;
F_19 ( V_9 -> V_14 , V_114 ,
( V_99 -> V_105 << V_115 ) |
( V_99 -> V_106 << V_116 ) ) ;
}
if ( ! V_102 ) {
F_32 ( V_7 , V_117 ,
F_31 ( V_117 ) ) ;
}
F_19 ( V_9 -> V_14 , V_118 ,
V_119 | V_120 ) ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 ,
enum V_121 V_122 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
switch ( V_122 ) {
case V_123 :
break;
case V_124 :
break;
case V_125 :
F_5 ( V_9 -> V_14 , V_126 ,
V_127 , V_127 ) ;
break;
case V_128 :
F_5 ( V_9 -> V_14 , V_126 ,
V_127 , 0 ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
F_36 ( V_9 -> V_14 ) ;
return 0 ;
}
static bool F_37 ( struct V_129 * V_100 , unsigned int V_130 )
{
switch ( V_130 ) {
case V_131 :
case V_132 :
return true ;
default:
return false ;
}
}
static int F_38 ( struct V_133 * V_134 ,
const struct V_135 * V_30 )
{
struct V_9 * V_9 ;
int V_72 ;
V_9 = F_39 ( & V_134 -> V_100 , sizeof( * V_9 ) , V_136 ) ;
if ( ! V_9 )
return - V_137 ;
V_9 -> V_14 = F_40 ( V_134 ,
& V_138 ) ;
if ( F_41 ( V_9 -> V_14 ) )
return F_42 ( V_9 -> V_14 ) ;
F_19 ( V_9 -> V_14 , V_131 , 0x00 ) ;
F_43 ( & V_134 -> V_100 , V_9 ) ;
V_72 = F_44 ( & V_134 -> V_100 , & V_139 ,
V_140 , F_31 ( V_140 ) ) ;
return V_72 ;
}
static int F_45 ( struct V_133 * V_134 )
{
F_46 ( & V_134 -> V_100 ) ;
return 0 ;
}
