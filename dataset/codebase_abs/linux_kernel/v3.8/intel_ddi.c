static enum V_1 F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int type = V_2 -> type ;
if ( type == V_6 || type == V_7 ||
type == V_8 || type == V_9 ) {
struct V_10 * V_11 =
F_2 ( V_4 ) ;
return V_11 -> V_1 ;
} else if ( type == V_12 ) {
return V_13 ;
} else {
F_3 ( L_1 , type ) ;
F_4 () ;
}
}
void F_5 ( struct V_14 * V_15 , enum V_1 V_1 , bool V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
T_1 V_20 ;
int V_21 ;
const T_1 * V_22 = ( ( V_16 ) ?
V_23 :
V_24 ) ;
F_6 ( L_2 ,
F_7 ( V_1 ) ,
V_16 ? L_3 : L_4 ) ;
F_8 ( ( V_16 && ( V_1 != V_13 ) ) ,
L_5 ,
F_7 ( V_1 ) ) ;
for ( V_21 = 0 , V_20 = F_9 ( V_1 ) ; V_21 < F_10 ( V_23 ) ; V_21 ++ ) {
F_11 ( V_20 , V_22 [ V_21 ] ) ;
V_20 += 4 ;
}
}
void F_12 ( struct V_14 * V_15 )
{
int V_1 ;
if ( F_13 ( V_15 ) ) {
for ( V_1 = V_25 ; V_1 < V_13 ; V_1 ++ )
F_5 ( V_15 , V_1 , false ) ;
F_5 ( V_15 , V_13 , true ) ;
}
}
static void F_14 ( struct V_17 * V_18 ,
enum V_1 V_1 )
{
T_2 V_20 = F_15 ( V_1 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
F_16 ( 1 ) ;
if ( F_17 ( V_20 ) & V_26 )
return;
}
F_3 ( L_6 , F_7 ( V_1 ) ) ;
}
void F_18 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
T_1 V_30 , V_21 , V_31 ;
F_11 ( V_32 , F_20 ( 2 ) |
F_21 ( 2 ) |
V_33 | V_34 ) ;
V_31 = V_35 | V_36 |
( ( V_29 -> V_37 - 1 ) << 19 ) ;
if ( V_18 -> V_38 )
V_31 |= V_39 ;
F_11 ( V_40 , V_31 ) ;
F_22 ( V_40 ) ;
F_16 ( 220 ) ;
V_31 |= V_41 ;
F_11 ( V_40 , V_31 ) ;
F_11 ( F_23 ( V_13 ) , V_29 -> V_42 ) ;
for ( V_21 = 0 ; V_21 < F_10 ( V_43 ) * 2 ; V_21 ++ ) {
F_11 ( F_24 ( V_13 ) ,
V_44 |
V_45 |
V_46 |
V_47 ) ;
F_11 ( F_15 ( V_13 ) ,
V_48 |
( ( V_29 -> V_37 - 1 ) << 1 ) |
V_43 [ V_21 / 2 ] ) ;
F_22 ( F_15 ( V_13 ) ) ;
F_16 ( 600 ) ;
F_11 ( V_49 , F_25 ( 64 ) ) ;
V_31 |= V_50 | V_51 ;
F_11 ( V_40 , V_31 ) ;
F_22 ( V_40 ) ;
F_16 ( 30 ) ;
V_30 = F_17 ( V_32 ) ;
V_30 &= ~ ( V_52 | V_53 ) ;
F_11 ( V_32 , V_30 ) ;
F_22 ( V_32 ) ;
F_16 ( 5 ) ;
V_30 = F_17 ( F_26 ( V_13 ) ) ;
if ( V_30 & V_54 ) {
F_27 ( L_7 , V_21 ) ;
F_11 ( F_24 ( V_13 ) ,
V_44 |
V_55 |
V_45 |
V_47 ) ;
return;
}
V_30 = F_17 ( F_15 ( V_13 ) ) ;
V_30 &= ~ V_48 ;
F_11 ( F_15 ( V_13 ) , V_30 ) ;
F_22 ( F_15 ( V_13 ) ) ;
V_30 = F_17 ( F_24 ( V_13 ) ) ;
V_30 &= ~ ( V_47 | V_56 ) ;
V_30 |= V_46 ;
F_11 ( F_24 ( V_13 ) , V_30 ) ;
F_22 ( F_24 ( V_13 ) ) ;
F_14 ( V_18 , V_13 ) ;
V_31 &= ~ V_50 ;
F_11 ( V_40 , V_31 ) ;
F_22 ( V_40 ) ;
V_30 = F_17 ( V_32 ) ;
V_30 &= ~ ( V_52 | V_53 ) ;
V_30 |= F_20 ( 2 ) | F_21 ( 2 ) ;
F_11 ( V_32 , V_30 ) ;
F_22 ( V_32 ) ;
}
F_3 ( L_8 ) ;
}
static void F_28 ( struct V_3 * V_4 ,
struct V_57 * V_58 ,
struct V_57 * V_59 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_29 ( V_4 ) ;
int V_1 = F_1 ( V_2 ) ;
int V_60 = V_29 -> V_60 ;
int type = V_2 -> type ;
F_27 ( L_9 ,
F_7 ( V_1 ) , F_30 ( V_60 ) ) ;
if ( type == V_6 || type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
V_61 -> V_62 = V_48 | V_63 ;
switch ( V_61 -> V_64 ) {
case 1 :
V_61 -> V_62 |= V_65 ;
break;
case 2 :
V_61 -> V_62 |= V_66 ;
break;
case 4 :
V_61 -> V_62 |= V_67 ;
break;
default:
V_61 -> V_62 |= V_67 ;
F_8 ( 1 , L_10 ,
V_61 -> V_64 ) ;
break;
}
if ( V_61 -> V_68 ) {
F_6 ( L_11 ,
F_30 ( V_29 -> V_60 ) ) ;
F_6 ( L_12 ) ;
F_32 ( V_4 , V_59 ) ;
}
F_33 ( V_61 ) ;
} else if ( type == V_8 ) {
struct V_69 * V_69 = F_34 ( V_4 ) ;
if ( V_69 -> V_68 ) {
F_6 ( L_13 ,
F_30 ( V_29 -> V_60 ) ) ;
F_6 ( L_14 ) ;
F_32 ( V_4 , V_59 ) ;
}
V_69 -> V_70 ( V_4 , V_59 ) ;
}
}
static struct V_2 *
F_35 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 , * V_71 = NULL ;
int V_72 = 0 ;
F_36 (dev, crtc, intel_encoder) {
V_71 = V_2 ;
V_72 ++ ;
}
if ( V_72 != 1 )
F_8 ( 1 , L_15 , V_72 ,
V_29 -> V_60 ) ;
F_37 ( V_71 == NULL ) ;
return V_71 ;
}
void F_38 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_73 * V_74 = & V_18 -> V_75 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
T_2 V_76 ;
switch ( V_29 -> V_42 ) {
case V_77 :
V_74 -> V_78 -- ;
if ( V_74 -> V_78 == 0 ) {
F_27 ( L_16 ) ;
V_76 = F_17 ( V_79 ) ;
F_39 ( ! ( V_76 & V_80 ) ) ;
F_11 ( V_79 , V_76 & ~ V_80 ) ;
F_22 ( V_79 ) ;
}
break;
case V_81 :
V_74 -> V_82 -- ;
if ( V_74 -> V_82 == 0 ) {
F_27 ( L_17 ) ;
V_76 = F_17 ( V_83 ) ;
F_39 ( ! ( V_76 & V_84 ) ) ;
F_11 ( V_83 , V_76 & ~ V_84 ) ;
F_22 ( V_83 ) ;
}
break;
case V_85 :
V_74 -> V_86 -- ;
if ( V_74 -> V_86 == 0 ) {
F_27 ( L_18 ) ;
V_76 = F_17 ( V_87 ) ;
F_39 ( ! ( V_76 & V_84 ) ) ;
F_11 ( V_87 , V_76 & ~ V_84 ) ;
F_22 ( V_87 ) ;
}
break;
}
F_8 ( V_74 -> V_78 < 0 , L_19 ) ;
F_8 ( V_74 -> V_82 < 0 , L_20 ) ;
F_8 ( V_74 -> V_86 < 0 , L_21 ) ;
V_29 -> V_42 = V_88 ;
}
static void F_40 ( int clock , int * V_89 , int * V_90 , int * V_91 )
{
T_1 V_21 ;
for ( V_21 = 0 ; V_21 < F_10 ( V_92 ) ; V_21 ++ )
if ( clock <= V_92 [ V_21 ] . clock )
break;
if ( V_21 == F_10 ( V_92 ) )
V_21 -- ;
* V_89 = V_92 [ V_21 ] . V_89 ;
* V_90 = V_92 [ V_21 ] . V_90 ;
* V_91 = V_92 [ V_21 ] . V_91 ;
if ( V_92 [ V_21 ] . clock != clock )
F_41 ( L_22 ,
V_92 [ V_21 ] . clock , clock ) ;
F_27 ( L_23 ,
clock , * V_89 , * V_90 , * V_91 ) ;
}
bool F_42 ( struct V_27 * V_28 , int clock )
{
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_73 * V_74 = & V_18 -> V_75 ;
int type = V_2 -> type ;
enum V_60 V_60 = V_29 -> V_60 ;
T_2 V_20 , V_76 ;
F_38 ( V_28 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
switch ( V_61 -> V_93 ) {
case V_94 :
V_29 -> V_42 = V_95 ;
break;
case V_96 :
V_29 -> V_42 = V_97 ;
break;
case V_98 :
V_29 -> V_42 = V_99 ;
break;
default:
F_3 ( L_24 ,
V_61 -> V_93 ) ;
return false ;
}
return true ;
} else if ( type == V_8 ) {
int V_89 , V_90 , V_91 ;
if ( V_74 -> V_82 == 0 ) {
F_27 ( L_25 ,
F_30 ( V_60 ) ) ;
V_74 -> V_82 ++ ;
V_20 = V_83 ;
V_29 -> V_42 = V_81 ;
} else if ( V_74 -> V_86 == 0 ) {
F_27 ( L_26 ,
F_30 ( V_60 ) ) ;
V_74 -> V_86 ++ ;
V_20 = V_87 ;
V_29 -> V_42 = V_85 ;
} else {
F_3 ( L_27 ) ;
return false ;
}
F_8 ( F_17 ( V_20 ) & V_84 ,
L_28 ) ;
F_40 ( clock , & V_89 , & V_90 , & V_91 ) ;
V_76 = V_84 | V_100 |
F_43 ( V_91 ) | F_44 ( V_90 ) |
F_45 ( V_89 ) ;
} else if ( type == V_12 ) {
if ( V_74 -> V_78 == 0 ) {
F_27 ( L_29 ,
F_30 ( V_60 ) ) ;
V_74 -> V_78 ++ ;
V_20 = V_79 ;
V_29 -> V_42 = V_77 ;
}
F_8 ( F_17 ( V_20 ) & V_80 ,
L_30 ) ;
V_76 = V_80 | V_101 | V_102 ;
} else {
F_8 ( 1 , L_1 , type ) ;
return false ;
}
F_11 ( V_20 , V_76 ) ;
F_16 ( 20 ) ;
return true ;
}
void F_46 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
enum V_103 V_104 = V_29 -> V_104 ;
int type = V_2 -> type ;
T_2 V_30 ;
if ( type == V_6 || type == V_7 ) {
V_30 = V_105 ;
switch ( V_29 -> V_106 ) {
case 18 :
V_30 |= V_107 ;
break;
case 24 :
V_30 |= V_108 ;
break;
case 30 :
V_30 |= V_109 ;
break;
case 36 :
V_30 |= V_110 ;
break;
default:
V_30 |= V_108 ;
F_8 ( 1 , L_31 ,
V_29 -> V_106 ) ;
}
F_11 ( F_47 ( V_104 ) , V_30 ) ;
}
}
void F_48 ( struct V_27 * V_28 )
{
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
enum V_60 V_60 = V_29 -> V_60 ;
enum V_103 V_104 = V_29 -> V_104 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_30 ;
V_30 = V_111 ;
V_30 |= F_49 ( V_1 ) ;
switch ( V_29 -> V_106 ) {
case 18 :
V_30 |= V_112 ;
break;
case 24 :
V_30 |= V_113 ;
break;
case 30 :
V_30 |= V_114 ;
break;
case 36 :
V_30 |= V_115 ;
break;
default:
F_8 ( 1 , L_32 ,
V_29 -> V_106 ) ;
}
if ( V_28 -> V_58 . V_116 & V_117 )
V_30 |= V_118 ;
if ( V_28 -> V_58 . V_116 & V_119 )
V_30 |= V_120 ;
if ( V_104 == V_121 ) {
switch ( V_60 ) {
case V_122 :
V_30 |= V_123 ;
break;
case V_124 :
V_30 |= V_125 ;
break;
case V_126 :
V_30 |= V_127 ;
break;
default:
F_4 () ;
break;
}
}
if ( type == V_8 ) {
struct V_69 * V_69 = F_34 ( V_4 ) ;
if ( V_69 -> V_128 )
V_30 |= V_129 ;
else
V_30 |= V_130 ;
} else if ( type == V_12 ) {
V_30 |= V_131 ;
V_30 |= ( V_29 -> V_37 - 1 ) << 1 ;
} else if ( type == V_6 ||
type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
V_30 |= V_132 ;
switch ( V_61 -> V_64 ) {
case 1 :
V_30 |= V_133 ;
break;
case 2 :
V_30 |= V_134 ;
break;
case 4 :
V_30 |= V_135 ;
break;
default:
V_30 |= V_135 ;
F_8 ( 1 , L_33 ,
V_61 -> V_64 ) ;
}
} else {
F_8 ( 1 , L_34 ,
V_2 -> type , V_60 ) ;
}
F_11 ( F_50 ( V_104 ) , V_30 ) ;
}
void F_51 ( struct V_17 * V_18 ,
enum V_103 V_104 )
{
T_2 V_20 = F_50 ( V_104 ) ;
T_2 V_76 = F_17 ( V_20 ) ;
V_76 &= ~ ( V_111 | V_136 ) ;
V_76 |= V_137 ;
F_11 ( V_20 , V_76 ) ;
}
bool F_52 ( struct V_138 * V_138 )
{
struct V_14 * V_15 = V_138 -> V_5 . V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_2 * V_2 = V_138 -> V_4 ;
int type = V_138 -> V_5 . V_139 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_60 V_60 = 0 ;
enum V_103 V_104 ;
T_2 V_140 ;
if ( ! V_2 -> V_141 ( V_2 , & V_60 ) )
return false ;
if ( V_1 == V_25 )
V_104 = V_121 ;
else
V_104 = V_60 ;
V_140 = F_17 ( F_50 ( V_104 ) ) ;
switch ( V_140 & V_142 ) {
case V_129 :
case V_130 :
return ( type == V_143 ) ;
case V_132 :
if ( type == V_144 )
return true ;
case V_145 :
return ( type == V_146 ) ;
case V_131 :
return ( type == V_147 ) ;
default:
return false ;
}
}
bool F_53 ( struct V_2 * V_4 ,
enum V_60 * V_60 )
{
struct V_14 * V_15 = V_4 -> V_5 . V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
T_1 V_140 ;
int V_21 ;
V_140 = F_17 ( F_15 ( V_1 ) ) ;
if ( ! ( V_140 & V_48 ) )
return false ;
if ( V_1 == V_25 ) {
V_140 = F_17 ( F_50 ( V_121 ) ) ;
switch ( V_140 & V_148 ) {
case V_149 :
case V_123 :
* V_60 = V_122 ;
break;
case V_125 :
* V_60 = V_124 ;
break;
case V_127 :
* V_60 = V_126 ;
break;
}
return true ;
} else {
for ( V_21 = V_150 ; V_21 <= V_151 ; V_21 ++ ) {
V_140 = F_17 ( F_50 ( V_21 ) ) ;
if ( ( V_140 & V_136 )
== F_49 ( V_1 ) ) {
* V_60 = V_21 ;
return true ;
}
}
}
F_27 ( L_35 , V_1 ) ;
return true ;
}
static T_2 F_54 ( struct V_17 * V_18 ,
enum V_60 V_60 )
{
T_2 V_30 , V_71 ;
enum V_1 V_1 ;
enum V_103 V_104 = F_55 ( V_18 ,
V_60 ) ;
int V_21 ;
if ( V_104 == V_121 ) {
V_1 = V_25 ;
} else {
V_30 = F_17 ( F_50 ( V_104 ) ) ;
V_30 &= V_136 ;
for ( V_21 = V_152 ; V_21 <= V_13 ; V_21 ++ )
if ( V_30 == F_49 ( V_21 ) )
V_1 = V_21 ;
}
V_71 = F_17 ( F_23 ( V_1 ) ) ;
F_27 ( L_36 ,
F_30 ( V_60 ) , F_7 ( V_1 ) , V_71 ) ;
return V_71 ;
}
void F_56 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_60 V_60 ;
struct V_29 * V_29 ;
F_57 (pipe) {
V_29 =
F_19 ( V_18 -> V_153 [ V_60 ] ) ;
if ( ! V_29 -> V_154 )
continue;
V_29 -> V_42 = F_54 ( V_18 ,
V_60 ) ;
switch ( V_29 -> V_42 ) {
case V_77 :
V_18 -> V_75 . V_78 ++ ;
break;
case V_81 :
V_18 -> V_75 . V_82 ++ ;
break;
case V_85 :
V_18 -> V_75 . V_86 ++ ;
break;
}
}
}
void F_58 ( struct V_29 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_5 ;
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_103 V_104 = V_29 -> V_104 ;
if ( V_104 != V_121 )
F_11 ( F_59 ( V_104 ) ,
F_60 ( V_1 ) ) ;
}
void F_61 ( struct V_29 * V_29 )
{
struct V_17 * V_18 = V_29 -> V_5 . V_15 -> V_19 ;
enum V_103 V_104 = V_29 -> V_104 ;
if ( V_104 != V_121 )
F_11 ( F_59 ( V_104 ) ,
V_155 ) ;
}
static void F_62 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_17 * V_18 = V_4 -> V_15 -> V_19 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_63 ( V_61 ) ;
F_64 ( V_61 ) ;
F_65 ( V_61 , true ) ;
}
F_39 ( V_29 -> V_42 == V_88 ) ;
F_11 ( F_23 ( V_1 ) , V_29 -> V_42 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_66 ( V_61 , V_156 ) ;
F_67 ( V_61 ) ;
F_68 ( V_61 ) ;
}
}
static void F_69 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * V_18 = V_4 -> V_15 -> V_19 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_76 ;
bool V_157 = false ;
V_76 = F_17 ( F_15 ( V_1 ) ) ;
if ( V_76 & V_48 ) {
V_76 &= ~ V_48 ;
F_11 ( F_15 ( V_1 ) , V_76 ) ;
V_157 = true ;
}
V_76 = F_17 ( F_24 ( V_1 ) ) ;
V_76 &= ~ ( V_47 | V_56 ) ;
V_76 |= V_46 ;
F_11 ( F_24 ( V_1 ) , V_76 ) ;
if ( V_157 )
F_14 ( V_18 , V_1 ) ;
if ( type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_63 ( V_61 ) ;
F_70 ( V_61 ) ;
}
F_11 ( F_23 ( V_1 ) , V_88 ) ;
}
static void F_71 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_8 ) {
F_11 ( F_15 ( V_1 ) , V_48 ) ;
} else if ( type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_72 ( V_61 ) ;
}
}
static void F_73 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int type = V_2 -> type ;
if ( type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_74 ( V_61 ) ;
}
}
int F_75 ( struct V_17 * V_18 )
{
if ( F_17 ( V_158 ) & V_159 )
return 450 ;
else if ( ( F_17 ( V_160 ) & V_161 ) ==
V_162 )
return 450 ;
else if ( F_76 ( V_18 -> V_15 ) )
return 338 ;
else
return 540 ;
}
void F_77 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
T_2 V_76 = F_17 ( V_160 ) ;
F_27 ( L_37 ,
F_75 ( V_18 ) ) ;
if ( V_76 & V_163 )
F_3 ( L_38 ) ;
if ( V_76 & V_164 )
F_3 ( L_39 ) ;
}
void F_78 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
struct V_61 * V_61 = & V_11 -> V_165 ;
struct V_17 * V_18 = V_4 -> V_15 -> V_19 ;
enum V_1 V_1 = V_11 -> V_1 ;
bool V_157 ;
T_2 V_76 ;
if ( F_17 ( F_24 ( V_1 ) ) & V_47 ) {
V_76 = F_17 ( F_15 ( V_1 ) ) ;
if ( V_76 & V_48 ) {
V_76 &= ~ V_48 ;
F_11 ( F_15 ( V_1 ) , V_76 ) ;
V_157 = true ;
}
V_76 = F_17 ( F_24 ( V_1 ) ) ;
V_76 &= ~ ( V_47 | V_56 ) ;
V_76 |= V_46 ;
F_11 ( F_24 ( V_1 ) , V_76 ) ;
F_22 ( F_24 ( V_1 ) ) ;
if ( V_157 )
F_14 ( V_18 , V_1 ) ;
}
V_76 = V_47 | V_166 |
V_46 | V_167 ;
if ( V_61 -> V_168 [ 1 ] & V_169 )
V_76 |= V_45 ;
F_11 ( F_24 ( V_1 ) , V_76 ) ;
F_22 ( F_24 ( V_1 ) ) ;
V_61 -> V_62 |= V_48 ;
F_11 ( F_15 ( V_1 ) , V_61 -> V_62 ) ;
F_22 ( F_15 ( V_1 ) ) ;
F_16 ( 600 ) ;
}
void F_79 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
T_2 V_76 ;
F_69 ( V_2 ) ;
V_76 = F_17 ( V_40 ) ;
V_76 &= ~ V_50 ;
F_11 ( V_40 , V_76 ) ;
V_76 = F_17 ( V_32 ) ;
V_76 &= ~ ( V_52 | V_53 ) ;
V_76 |= F_20 ( 2 ) | F_21 ( 2 ) ;
F_11 ( V_32 , V_76 ) ;
V_76 = F_17 ( V_40 ) ;
V_76 &= ~ V_41 ;
F_11 ( V_40 , V_76 ) ;
V_76 = F_17 ( V_40 ) ;
V_76 &= ~ V_35 ;
F_11 ( V_40 , V_76 ) ;
}
static void F_80 ( struct V_2 * V_2 )
{
struct V_61 * V_61 = F_31 ( & V_2 -> V_5 ) ;
int type = V_2 -> type ;
if ( type == V_6 || type == V_7 )
F_81 ( V_61 ) ;
}
static void F_82 ( struct V_3 * V_4 )
{
F_83 ( V_4 ) ;
}
static bool F_84 ( struct V_3 * V_4 ,
const struct V_57 * V_58 ,
struct V_57 * V_59 )
{
struct V_2 * V_2 = F_29 ( V_4 ) ;
int type = V_2 -> type ;
F_8 ( type == V_9 , L_40 ) ;
if ( type == V_8 )
return F_85 ( V_4 , V_58 , V_59 ) ;
else
return F_86 ( V_4 , V_58 , V_59 ) ;
}
void F_87 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_10 * V_11 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
struct V_138 * V_170 = NULL ;
struct V_138 * V_171 = NULL ;
V_11 = F_88 ( sizeof( struct V_10 ) , V_172 ) ;
if ( ! V_11 )
return;
V_171 = F_88 ( sizeof( struct V_138 ) , V_172 ) ;
if ( ! V_171 ) {
F_89 ( V_11 ) ;
return;
}
if ( V_1 != V_25 ) {
V_170 = F_88 ( sizeof( struct V_138 ) ,
V_172 ) ;
if ( ! V_170 ) {
F_89 ( V_171 ) ;
F_89 ( V_11 ) ;
return;
}
}
V_2 = & V_11 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_90 ( V_15 , V_4 , & V_173 ,
V_174 ) ;
F_91 ( V_4 , & V_175 ) ;
V_2 -> V_176 = F_71 ;
V_2 -> V_177 = F_62 ;
V_2 -> V_178 = F_73 ;
V_2 -> V_179 = F_69 ;
V_2 -> V_141 = F_53 ;
V_11 -> V_1 = V_1 ;
if ( V_170 )
V_11 -> V_180 . V_181 = F_15 ( V_1 ) ;
else
V_11 -> V_180 . V_181 = 0 ;
V_11 -> V_165 . V_182 = F_15 ( V_1 ) ;
V_2 -> type = V_9 ;
V_2 -> V_183 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_184 = false ;
V_2 -> V_185 = F_80 ;
if ( V_170 )
F_92 ( V_11 , V_170 ) ;
F_93 ( V_11 , V_171 ) ;
}
