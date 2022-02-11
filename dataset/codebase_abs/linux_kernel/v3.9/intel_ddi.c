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
static void F_5 ( struct V_14 * V_15 , enum V_1 V_1 ,
bool V_16 )
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
if ( ! F_13 ( V_15 ) )
return;
for ( V_1 = V_25 ; V_1 < V_13 ; V_1 ++ )
F_5 ( V_15 , V_1 , false ) ;
F_5 ( V_15 , V_13 , true ) ;
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
V_31 = V_18 -> V_35 | V_36 |
V_37 | ( ( V_29 -> V_38 - 1 ) << 19 ) ;
F_11 ( V_39 , V_31 ) ;
F_22 ( V_39 ) ;
F_16 ( 220 ) ;
V_31 |= V_40 ;
F_11 ( V_39 , V_31 ) ;
F_11 ( F_23 ( V_13 ) , V_29 -> V_41 ) ;
for ( V_21 = 0 ; V_21 < F_10 ( V_42 ) * 2 ; V_21 ++ ) {
F_11 ( F_24 ( V_13 ) ,
V_43 |
V_44 |
V_45 |
V_46 ) ;
F_11 ( F_15 ( V_13 ) ,
V_47 |
( ( V_29 -> V_38 - 1 ) << 1 ) |
V_42 [ V_21 / 2 ] ) ;
F_22 ( F_15 ( V_13 ) ) ;
F_16 ( 600 ) ;
F_11 ( V_48 , F_25 ( 64 ) ) ;
V_31 |= V_49 | V_50 ;
F_11 ( V_39 , V_31 ) ;
F_22 ( V_39 ) ;
F_16 ( 30 ) ;
V_30 = F_17 ( V_32 ) ;
V_30 &= ~ ( V_51 | V_52 ) ;
F_11 ( V_32 , V_30 ) ;
F_22 ( V_32 ) ;
F_16 ( 5 ) ;
V_30 = F_17 ( F_26 ( V_13 ) ) ;
if ( V_30 & V_53 ) {
F_27 ( L_7 , V_21 ) ;
F_11 ( F_24 ( V_13 ) ,
V_43 |
V_54 |
V_44 |
V_46 ) ;
return;
}
V_30 = F_17 ( F_15 ( V_13 ) ) ;
V_30 &= ~ V_47 ;
F_11 ( F_15 ( V_13 ) , V_30 ) ;
F_22 ( F_15 ( V_13 ) ) ;
V_30 = F_17 ( F_24 ( V_13 ) ) ;
V_30 &= ~ ( V_46 | V_55 ) ;
V_30 |= V_45 ;
F_11 ( F_24 ( V_13 ) , V_30 ) ;
F_22 ( F_24 ( V_13 ) ) ;
F_14 ( V_18 , V_13 ) ;
V_31 &= ~ V_49 ;
F_11 ( V_39 , V_31 ) ;
F_22 ( V_39 ) ;
V_30 = F_17 ( V_32 ) ;
V_30 &= ~ ( V_51 | V_52 ) ;
V_30 |= F_20 ( 2 ) | F_21 ( 2 ) ;
F_11 ( V_32 , V_30 ) ;
F_22 ( V_32 ) ;
}
F_3 ( L_8 ) ;
}
static void F_28 ( struct V_3 * V_4 ,
struct V_56 * V_57 ,
struct V_56 * V_58 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_29 ( V_4 ) ;
int V_1 = F_1 ( V_2 ) ;
int V_59 = V_29 -> V_59 ;
int type = V_2 -> type ;
F_27 ( L_9 ,
F_7 ( V_1 ) , F_30 ( V_59 ) ) ;
V_29 -> V_60 = false ;
if ( type == V_6 || type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
struct V_10 * V_11 =
F_2 ( V_4 ) ;
V_61 -> V_62 = V_11 -> V_63 |
V_47 | V_64 ;
switch ( V_61 -> V_65 ) {
case 1 :
V_61 -> V_62 |= V_66 ;
break;
case 2 :
V_61 -> V_62 |= V_67 ;
break;
case 4 :
V_61 -> V_62 |= V_68 ;
break;
default:
V_61 -> V_62 |= V_68 ;
F_8 ( 1 , L_10 ,
V_61 -> V_65 ) ;
break;
}
if ( V_61 -> V_69 ) {
F_6 ( L_11 ,
F_30 ( V_29 -> V_59 ) ) ;
F_6 ( L_12 ) ;
F_32 ( V_4 , V_58 ) ;
}
F_33 ( V_61 ) ;
} else if ( type == V_8 ) {
struct V_70 * V_70 = F_34 ( V_4 ) ;
if ( V_70 -> V_69 ) {
F_6 ( L_13 ,
F_30 ( V_29 -> V_59 ) ) ;
F_6 ( L_14 ) ;
F_32 ( V_4 , V_58 ) ;
}
V_70 -> V_71 ( V_4 , V_58 ) ;
}
}
static struct V_2 *
F_35 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 , * V_72 = NULL ;
int V_73 = 0 ;
F_36 (dev, crtc, intel_encoder) {
V_72 = V_2 ;
V_73 ++ ;
}
if ( V_73 != 1 )
F_8 ( 1 , L_15 , V_73 ,
V_29 -> V_59 ) ;
F_37 ( V_72 == NULL ) ;
return V_72 ;
}
void F_38 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_74 * V_75 = & V_18 -> V_76 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
T_2 V_77 ;
switch ( V_29 -> V_41 ) {
case V_78 :
V_75 -> V_79 -- ;
if ( V_75 -> V_79 == 0 ) {
F_27 ( L_16 ) ;
V_77 = F_17 ( V_80 ) ;
F_39 ( ! ( V_77 & V_81 ) ) ;
F_11 ( V_80 , V_77 & ~ V_81 ) ;
F_22 ( V_80 ) ;
}
break;
case V_82 :
V_75 -> V_83 -- ;
if ( V_75 -> V_83 == 0 ) {
F_27 ( L_17 ) ;
V_77 = F_17 ( V_84 ) ;
F_39 ( ! ( V_77 & V_85 ) ) ;
F_11 ( V_84 , V_77 & ~ V_85 ) ;
F_22 ( V_84 ) ;
}
break;
case V_86 :
V_75 -> V_87 -- ;
if ( V_75 -> V_87 == 0 ) {
F_27 ( L_18 ) ;
V_77 = F_17 ( V_88 ) ;
F_39 ( ! ( V_77 & V_85 ) ) ;
F_11 ( V_88 , V_77 & ~ V_85 ) ;
F_22 ( V_88 ) ;
}
break;
}
F_8 ( V_75 -> V_79 < 0 , L_19 ) ;
F_8 ( V_75 -> V_83 < 0 , L_20 ) ;
F_8 ( V_75 -> V_87 < 0 , L_21 ) ;
V_29 -> V_41 = V_89 ;
}
static void F_40 ( int clock , int * V_90 , int * V_91 , int * V_92 )
{
T_1 V_21 ;
for ( V_21 = 0 ; V_21 < F_10 ( V_93 ) ; V_21 ++ )
if ( clock <= V_93 [ V_21 ] . clock )
break;
if ( V_21 == F_10 ( V_93 ) )
V_21 -- ;
* V_90 = V_93 [ V_21 ] . V_90 ;
* V_91 = V_93 [ V_21 ] . V_91 ;
* V_92 = V_93 [ V_21 ] . V_92 ;
if ( V_93 [ V_21 ] . clock != clock )
F_41 ( L_22 ,
V_93 [ V_21 ] . clock , clock ) ;
F_27 ( L_23 ,
clock , * V_90 , * V_91 , * V_92 ) ;
}
bool F_42 ( struct V_27 * V_28 , int clock )
{
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_74 * V_75 = & V_18 -> V_76 ;
int type = V_2 -> type ;
enum V_59 V_59 = V_29 -> V_59 ;
T_2 V_20 , V_77 ;
F_38 ( V_28 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
switch ( V_61 -> V_94 ) {
case V_95 :
V_29 -> V_41 = V_96 ;
break;
case V_97 :
V_29 -> V_41 = V_98 ;
break;
case V_99 :
V_29 -> V_41 = V_100 ;
break;
default:
F_3 ( L_24 ,
V_61 -> V_94 ) ;
return false ;
}
return true ;
} else if ( type == V_8 ) {
int V_90 , V_91 , V_92 ;
if ( V_75 -> V_83 == 0 ) {
F_27 ( L_25 ,
F_30 ( V_59 ) ) ;
V_75 -> V_83 ++ ;
V_20 = V_84 ;
V_29 -> V_41 = V_82 ;
} else if ( V_75 -> V_87 == 0 ) {
F_27 ( L_26 ,
F_30 ( V_59 ) ) ;
V_75 -> V_87 ++ ;
V_20 = V_88 ;
V_29 -> V_41 = V_86 ;
} else {
F_3 ( L_27 ) ;
return false ;
}
F_8 ( F_17 ( V_20 ) & V_85 ,
L_28 ) ;
F_40 ( clock , & V_90 , & V_91 , & V_92 ) ;
V_77 = V_85 | V_101 |
F_43 ( V_92 ) | F_44 ( V_91 ) |
F_45 ( V_90 ) ;
} else if ( type == V_12 ) {
if ( V_75 -> V_79 == 0 ) {
F_27 ( L_29 ,
F_30 ( V_59 ) ) ;
V_75 -> V_79 ++ ;
V_20 = V_80 ;
V_29 -> V_41 = V_78 ;
}
F_8 ( F_17 ( V_20 ) & V_81 ,
L_30 ) ;
V_77 = V_81 | V_102 | V_103 ;
} else {
F_8 ( 1 , L_1 , type ) ;
return false ;
}
F_11 ( V_20 , V_77 ) ;
F_16 ( 20 ) ;
return true ;
}
void F_46 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
enum V_104 V_105 = V_29 -> V_105 ;
int type = V_2 -> type ;
T_2 V_30 ;
if ( type == V_6 || type == V_7 ) {
V_30 = V_106 ;
switch ( V_29 -> V_107 ) {
case 18 :
V_30 |= V_108 ;
break;
case 24 :
V_30 |= V_109 ;
break;
case 30 :
V_30 |= V_110 ;
break;
case 36 :
V_30 |= V_111 ;
break;
default:
V_30 |= V_109 ;
F_8 ( 1 , L_31 ,
V_29 -> V_107 ) ;
}
F_11 ( F_47 ( V_105 ) , V_30 ) ;
}
}
void F_48 ( struct V_27 * V_28 )
{
struct V_29 * V_29 = F_19 ( V_28 ) ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
enum V_59 V_59 = V_29 -> V_59 ;
enum V_104 V_105 = V_29 -> V_105 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_30 ;
V_30 = V_112 ;
V_30 |= F_49 ( V_1 ) ;
switch ( V_29 -> V_107 ) {
case 18 :
V_30 |= V_113 ;
break;
case 24 :
V_30 |= V_114 ;
break;
case 30 :
V_30 |= V_115 ;
break;
case 36 :
V_30 |= V_116 ;
break;
default:
F_8 ( 1 , L_32 ,
V_29 -> V_107 ) ;
}
if ( V_28 -> V_57 . V_117 & V_118 )
V_30 |= V_119 ;
if ( V_28 -> V_57 . V_117 & V_120 )
V_30 |= V_121 ;
if ( V_105 == V_122 ) {
switch ( V_59 ) {
case V_123 :
if ( V_18 -> V_124 )
V_30 |= V_125 ;
else
V_30 |= V_126 ;
break;
case V_127 :
V_30 |= V_128 ;
break;
case V_129 :
V_30 |= V_130 ;
break;
default:
F_4 () ;
break;
}
}
if ( type == V_8 ) {
struct V_70 * V_70 = F_34 ( V_4 ) ;
if ( V_70 -> V_131 )
V_30 |= V_132 ;
else
V_30 |= V_133 ;
} else if ( type == V_12 ) {
V_30 |= V_134 ;
V_30 |= ( V_29 -> V_38 - 1 ) << 1 ;
} else if ( type == V_6 ||
type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
V_30 |= V_135 ;
switch ( V_61 -> V_65 ) {
case 1 :
V_30 |= V_136 ;
break;
case 2 :
V_30 |= V_137 ;
break;
case 4 :
V_30 |= V_138 ;
break;
default:
V_30 |= V_138 ;
F_8 ( 1 , L_33 ,
V_61 -> V_65 ) ;
}
} else {
F_8 ( 1 , L_34 ,
V_2 -> type , V_59 ) ;
}
F_11 ( F_50 ( V_105 ) , V_30 ) ;
}
void F_51 ( struct V_17 * V_18 ,
enum V_104 V_105 )
{
T_2 V_20 = F_50 ( V_105 ) ;
T_2 V_77 = F_17 ( V_20 ) ;
V_77 &= ~ ( V_112 | V_139 ) ;
V_77 |= V_140 ;
F_11 ( V_20 , V_77 ) ;
}
bool F_52 ( struct V_141 * V_141 )
{
struct V_14 * V_15 = V_141 -> V_5 . V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_2 * V_2 = V_141 -> V_4 ;
int type = V_141 -> V_5 . V_142 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_59 V_59 = 0 ;
enum V_104 V_105 ;
T_2 V_143 ;
if ( ! V_2 -> V_144 ( V_2 , & V_59 ) )
return false ;
if ( V_1 == V_25 )
V_105 = V_122 ;
else
V_105 = (enum V_104 ) V_59 ;
V_143 = F_17 ( F_50 ( V_105 ) ) ;
switch ( V_143 & V_145 ) {
case V_132 :
case V_133 :
return ( type == V_146 ) ;
case V_135 :
if ( type == V_147 )
return true ;
case V_148 :
return ( type == V_149 ) ;
case V_134 :
return ( type == V_150 ) ;
default:
return false ;
}
}
bool F_53 ( struct V_2 * V_4 ,
enum V_59 * V_59 )
{
struct V_14 * V_15 = V_4 -> V_5 . V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_1 V_1 = F_1 ( V_4 ) ;
T_1 V_143 ;
int V_21 ;
V_143 = F_17 ( F_15 ( V_1 ) ) ;
if ( ! ( V_143 & V_47 ) )
return false ;
if ( V_1 == V_25 ) {
V_143 = F_17 ( F_50 ( V_122 ) ) ;
switch ( V_143 & V_151 ) {
case V_126 :
case V_125 :
* V_59 = V_123 ;
break;
case V_128 :
* V_59 = V_127 ;
break;
case V_130 :
* V_59 = V_129 ;
break;
}
return true ;
} else {
for ( V_21 = V_152 ; V_21 <= V_153 ; V_21 ++ ) {
V_143 = F_17 ( F_50 ( V_21 ) ) ;
if ( ( V_143 & V_139 )
== F_49 ( V_1 ) ) {
* V_59 = V_21 ;
return true ;
}
}
}
F_27 ( L_35 , V_1 ) ;
return true ;
}
static T_2 F_54 ( struct V_17 * V_18 ,
enum V_59 V_59 )
{
T_2 V_30 , V_72 ;
enum V_1 V_1 ;
enum V_104 V_105 = F_55 ( V_18 ,
V_59 ) ;
int V_21 ;
if ( V_105 == V_122 ) {
V_1 = V_25 ;
} else {
V_30 = F_17 ( F_50 ( V_105 ) ) ;
V_30 &= V_139 ;
for ( V_21 = V_154 ; V_21 <= V_13 ; V_21 ++ )
if ( V_30 == F_49 ( V_21 ) )
V_1 = V_21 ;
}
V_72 = F_17 ( F_23 ( V_1 ) ) ;
F_27 ( L_36 ,
F_30 ( V_59 ) , F_7 ( V_1 ) , V_72 ) ;
return V_72 ;
}
void F_56 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_59 V_59 ;
struct V_29 * V_29 ;
F_57 (pipe) {
V_29 =
F_19 ( V_18 -> V_155 [ V_59 ] ) ;
if ( ! V_29 -> V_156 )
continue;
V_29 -> V_41 = F_54 ( V_18 ,
V_59 ) ;
switch ( V_29 -> V_41 ) {
case V_78 :
V_18 -> V_76 . V_79 ++ ;
break;
case V_82 :
V_18 -> V_76 . V_83 ++ ;
break;
case V_86 :
V_18 -> V_76 . V_87 ++ ;
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
enum V_104 V_105 = V_29 -> V_105 ;
if ( V_105 != V_122 )
F_11 ( F_59 ( V_105 ) ,
F_60 ( V_1 ) ) ;
}
void F_61 ( struct V_29 * V_29 )
{
struct V_17 * V_18 = V_29 -> V_5 . V_15 -> V_19 ;
enum V_104 V_105 = V_29 -> V_105 ;
if ( V_105 != V_122 )
F_11 ( F_59 ( V_105 ) ,
V_157 ) ;
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
F_39 ( V_29 -> V_41 == V_89 ) ;
F_11 ( F_23 ( V_1 ) , V_29 -> V_41 ) ;
if ( type == V_6 || type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_66 ( V_61 , V_158 ) ;
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
T_2 V_77 ;
bool V_159 = false ;
V_77 = F_17 ( F_15 ( V_1 ) ) ;
if ( V_77 & V_47 ) {
V_77 &= ~ V_47 ;
F_11 ( F_15 ( V_1 ) , V_77 ) ;
V_159 = true ;
}
V_77 = F_17 ( F_24 ( V_1 ) ) ;
V_77 &= ~ ( V_46 | V_55 ) ;
V_77 |= V_45 ;
F_11 ( F_24 ( V_1 ) , V_77 ) ;
if ( V_159 )
F_14 ( V_18 , V_1 ) ;
if ( type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_63 ( V_61 ) ;
F_70 ( V_61 ) ;
}
F_11 ( F_23 ( V_1 ) , V_89 ) ;
}
static void F_71 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
int V_59 = V_29 -> V_59 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_2 V_143 ;
if ( type == V_8 ) {
struct V_10 * V_11 =
F_2 ( V_4 ) ;
F_11 ( F_15 ( V_1 ) ,
V_11 -> V_63 | V_47 ) ;
} else if ( type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_72 ( V_61 ) ;
}
if ( V_29 -> V_60 ) {
V_143 = F_17 ( V_160 ) ;
V_143 |= ( ( V_161 | V_162 ) << ( V_59 * 4 ) ) ;
F_11 ( V_160 , V_143 ) ;
}
}
static void F_73 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_29 * V_29 = F_19 ( V_28 ) ;
int V_59 = V_29 -> V_59 ;
int type = V_2 -> type ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_19 ;
T_2 V_143 ;
if ( type == V_7 ) {
struct V_61 * V_61 = F_31 ( V_4 ) ;
F_74 ( V_61 ) ;
}
V_143 = F_17 ( V_160 ) ;
V_143 &= ~ ( ( V_161 | V_162 ) << ( V_59 * 4 ) ) ;
F_11 ( V_160 , V_143 ) ;
}
int F_75 ( struct V_17 * V_18 )
{
if ( F_17 ( V_163 ) & V_164 )
return 450 ;
else if ( ( F_17 ( V_165 ) & V_166 ) ==
V_167 )
return 450 ;
else if ( F_76 ( V_18 -> V_15 ) )
return 338 ;
else
return 540 ;
}
void F_77 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
T_2 V_77 = F_17 ( V_165 ) ;
F_27 ( L_37 ,
F_75 ( V_18 ) ) ;
if ( V_77 & V_168 )
F_3 ( L_38 ) ;
if ( V_77 & V_169 )
F_3 ( L_39 ) ;
}
void F_78 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
struct V_61 * V_61 = & V_11 -> V_170 ;
struct V_17 * V_18 = V_4 -> V_15 -> V_19 ;
enum V_1 V_1 = V_11 -> V_1 ;
T_2 V_77 ;
bool V_159 = false ;
if ( F_17 ( F_24 ( V_1 ) ) & V_46 ) {
V_77 = F_17 ( F_15 ( V_1 ) ) ;
if ( V_77 & V_47 ) {
V_77 &= ~ V_47 ;
F_11 ( F_15 ( V_1 ) , V_77 ) ;
V_159 = true ;
}
V_77 = F_17 ( F_24 ( V_1 ) ) ;
V_77 &= ~ ( V_46 | V_55 ) ;
V_77 |= V_45 ;
F_11 ( F_24 ( V_1 ) , V_77 ) ;
F_22 ( F_24 ( V_1 ) ) ;
if ( V_159 )
F_14 ( V_18 , V_1 ) ;
}
V_77 = V_46 | V_171 |
V_45 | V_172 ;
if ( V_61 -> V_173 [ 1 ] & V_174 )
V_77 |= V_44 ;
F_11 ( F_24 ( V_1 ) , V_77 ) ;
F_22 ( F_24 ( V_1 ) ) ;
V_61 -> V_62 |= V_47 ;
F_11 ( F_15 ( V_1 ) , V_61 -> V_62 ) ;
F_22 ( F_15 ( V_1 ) ) ;
F_16 ( 600 ) ;
}
void F_79 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_15 -> V_19 ;
struct V_2 * V_2 = F_35 ( V_28 ) ;
T_2 V_77 ;
F_69 ( V_2 ) ;
V_77 = F_17 ( V_39 ) ;
V_77 &= ~ V_49 ;
F_11 ( V_39 , V_77 ) ;
V_77 = F_17 ( V_32 ) ;
V_77 &= ~ ( V_51 | V_52 ) ;
V_77 |= F_20 ( 2 ) | F_21 ( 2 ) ;
F_11 ( V_32 , V_77 ) ;
V_77 = F_17 ( V_39 ) ;
V_77 &= ~ V_40 ;
F_11 ( V_39 , V_77 ) ;
V_77 = F_17 ( V_39 ) ;
V_77 &= ~ V_37 ;
F_11 ( V_39 , V_77 ) ;
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
const struct V_56 * V_57 ,
struct V_56 * V_58 )
{
struct V_2 * V_2 = F_29 ( V_4 ) ;
int type = V_2 -> type ;
F_8 ( type == V_9 , L_40 ) ;
if ( type == V_8 )
return F_85 ( V_4 , V_57 , V_58 ) ;
else
return F_86 ( V_4 , V_57 , V_58 ) ;
}
void F_87 ( struct V_14 * V_15 , enum V_1 V_1 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_10 * V_11 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
struct V_141 * V_175 = NULL ;
struct V_141 * V_176 = NULL ;
V_11 = F_88 ( sizeof( struct V_10 ) , V_177 ) ;
if ( ! V_11 )
return;
V_176 = F_88 ( sizeof( struct V_141 ) , V_177 ) ;
if ( ! V_176 ) {
F_89 ( V_11 ) ;
return;
}
if ( V_1 != V_25 ) {
V_175 = F_88 ( sizeof( struct V_141 ) ,
V_177 ) ;
if ( ! V_175 ) {
F_89 ( V_176 ) ;
F_89 ( V_11 ) ;
return;
}
}
V_2 = & V_11 -> V_5 ;
V_4 = & V_2 -> V_5 ;
F_90 ( V_15 , V_4 , & V_178 ,
V_179 ) ;
F_91 ( V_4 , & V_180 ) ;
V_2 -> V_181 = F_71 ;
V_2 -> V_182 = F_62 ;
V_2 -> V_183 = F_73 ;
V_2 -> V_184 = F_69 ;
V_2 -> V_144 = F_53 ;
V_11 -> V_1 = V_1 ;
V_11 -> V_63 = F_17 ( F_15 ( V_1 ) ) &
V_185 ;
if ( V_175 )
V_11 -> V_186 . V_187 = F_15 ( V_1 ) ;
else
V_11 -> V_186 . V_187 = 0 ;
V_11 -> V_170 . V_188 = F_15 ( V_1 ) ;
V_2 -> type = V_9 ;
V_2 -> V_189 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_190 = false ;
V_2 -> V_191 = F_80 ;
if ( V_175 )
F_92 ( V_11 , V_175 ) ;
F_93 ( V_11 , V_176 ) ;
}
