int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
int V_5 )
{
int V_6 ;
int V_7 = - 1 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_9 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_10 [ V_6 ] . type == V_4 ) {
V_7 ++ ;
if ( V_7 == V_5 )
return V_6 ;
}
}
return V_2 -> V_8 . V_11 ;
}
void F_2 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_8 . V_12 == V_13 ) && V_2 -> V_8 . V_14 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( F_4 () > 0 )
V_2 -> V_8 . V_16 . V_17 = true ;
else
V_2 -> V_8 . V_16 . V_17 = false ;
if ( V_2 -> V_18 == V_19 ) {
if ( V_2 -> V_20 -> V_16 . V_21 )
F_5 ( V_2 , V_2 -> V_8 . V_16 . V_17 ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else if ( V_2 -> V_8 . V_12 == V_22 ) {
if ( V_2 -> V_8 . V_23 == V_24 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_23 ) {
case V_25 :
V_2 -> V_8 . V_26 = V_27 ;
break;
case V_24 :
if ( F_4 () > 0 ) {
if ( V_2 -> V_8 . V_28 > 1 )
V_2 -> V_8 . V_26 = V_29 ;
else
V_2 -> V_8 . V_26 = V_30 ;
} else {
if ( V_2 -> V_8 . V_28 > 1 )
V_2 -> V_8 . V_26 = V_31 ;
else
V_2 -> V_8 . V_26 = V_32 ;
}
break;
case V_33 :
if ( V_2 -> V_8 . V_28 > 1 )
V_2 -> V_8 . V_26 = V_34 ;
else
V_2 -> V_8 . V_26 = V_35 ;
break;
case V_36 :
if ( V_2 -> V_8 . V_28 > 1 )
V_2 -> V_8 . V_26 = V_31 ;
else
V_2 -> V_8 . V_26 = V_32 ;
break;
case V_37 :
if ( V_2 -> V_8 . V_28 > 1 )
V_2 -> V_8 . V_26 = V_29 ;
else
V_2 -> V_8 . V_26 = V_30 ;
break;
}
if ( V_2 -> V_8 . V_28 == 0 ) {
V_2 -> V_8 . V_38 =
V_2 -> V_8 . V_39 [ V_2 -> V_8 . V_26 ] . V_40 ;
V_2 -> V_8 . V_41 =
V_2 -> V_8 . V_39 [ V_2 -> V_8 . V_26 ] . V_42 ;
} else {
V_2 -> V_8 . V_38 =
V_2 -> V_8 . V_39 [ V_2 -> V_8 . V_26 ] . V_43 ;
V_2 -> V_8 . V_41 =
V_2 -> V_8 . V_39 [ V_2 -> V_8 . V_26 ] . V_44 ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_45 * V_46 , * V_47 ;
if ( F_10 ( & V_2 -> V_48 . V_49 ) )
return;
F_11 (bo, n, &rdev->gem.objects, list) {
if ( V_46 -> V_50 . V_51 . V_52 == V_53 )
F_12 ( & V_46 -> V_50 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_54 ) {
V_2 -> V_8 . V_55 = false ;
F_14 (
V_2 -> V_56 . V_57 , V_2 -> V_8 . V_55 ,
F_15 ( V_58 ) ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_59 , V_60 ;
bool V_61 = false ;
if ( ( V_2 -> V_8 . V_41 == V_2 -> V_8 . V_62 ) &&
( V_2 -> V_8 . V_38 == V_2 -> V_8 . V_63 ) )
return;
if ( F_17 ( V_2 ) ) {
V_59 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_38 ] .
V_64 [ V_2 -> V_8 . V_41 ] . V_59 ;
if ( V_59 > V_2 -> V_8 . V_65 )
V_59 = V_2 -> V_8 . V_65 ;
if ( ( V_2 -> V_8 . V_12 == V_22 ) &&
( V_2 -> V_18 >= V_66 ) &&
V_2 -> V_8 . V_28 &&
( ( V_2 -> V_8 . V_26 == V_31 ) ||
( V_2 -> V_8 . V_26 == V_34 ) ) )
V_60 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_38 ] .
V_64 [ V_2 -> V_8 . V_39 [ V_29 ] . V_44 ] . V_60 ;
else
V_60 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_38 ] .
V_64 [ V_2 -> V_8 . V_41 ] . V_60 ;
if ( V_60 > V_2 -> V_8 . V_67 )
V_60 = V_2 -> V_8 . V_67 ;
if ( V_59 < V_2 -> V_8 . V_68 )
V_61 = true ;
F_13 ( V_2 ) ;
if ( V_2 -> V_8 . V_12 == V_69 ) {
if ( ! F_18 ( V_2 ) )
return;
}
F_19 ( V_2 ) ;
if ( ! V_61 )
F_20 ( V_2 ) ;
if ( V_59 != V_2 -> V_8 . V_68 ) {
F_21 ( V_2 , false ) ;
F_22 ( V_2 , V_59 ) ;
F_21 ( V_2 , true ) ;
V_2 -> V_8 . V_68 = V_59 ;
F_23 ( L_1 , V_59 ) ;
}
if ( V_2 -> V_20 -> V_8 . V_70 && ( V_60 != V_2 -> V_8 . V_71 ) ) {
F_21 ( V_2 , false ) ;
F_24 ( V_2 , V_60 ) ;
F_21 ( V_2 , true ) ;
V_2 -> V_8 . V_71 = V_60 ;
F_23 ( L_2 , V_60 ) ;
}
if ( V_61 )
F_20 ( V_2 ) ;
F_25 ( V_2 ) ;
V_2 -> V_8 . V_63 = V_2 -> V_8 . V_38 ;
V_2 -> V_8 . V_62 = V_2 -> V_8 . V_41 ;
} else
F_23 ( L_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
int V_6 , V_74 ;
if ( ( V_2 -> V_8 . V_41 == V_2 -> V_8 . V_62 ) &&
( V_2 -> V_8 . V_38 == V_2 -> V_8 . V_63 ) )
return;
F_26 ( & V_2 -> V_8 . V_75 ) ;
F_3 ( & V_2 -> V_76 ) ;
for ( V_6 = 0 ; V_6 < V_77 ; V_6 ++ ) {
struct V_78 * V_79 = & V_2 -> V_79 [ V_6 ] ;
if ( ! V_79 -> V_80 ) {
continue;
}
V_74 = F_27 ( V_2 , V_6 ) ;
if ( V_74 ) {
F_6 ( & V_2 -> V_76 ) ;
F_28 ( & V_2 -> V_8 . V_75 ) ;
return;
}
}
F_9 ( V_2 ) ;
if ( V_2 -> V_56 . V_81 ) {
V_6 = 0 ;
F_29 (crtc, rdev->ddev) {
if ( V_2 -> V_8 . V_54 & ( 1 << V_6 ) ) {
if ( F_30 ( V_73 ) == 0 )
V_2 -> V_8 . V_82 |= ( 1 << V_6 ) ;
else
F_23 ( L_4 ,
V_6 ) ;
}
V_6 ++ ;
}
}
F_16 ( V_2 ) ;
if ( V_2 -> V_56 . V_81 ) {
V_6 = 0 ;
F_29 (crtc, rdev->ddev) {
if ( V_2 -> V_8 . V_82 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_82 &= ~ ( 1 << V_6 ) ;
F_31 ( V_73 ) ;
}
V_6 ++ ;
}
}
F_32 ( V_2 ) ;
if ( V_2 -> V_8 . V_28 )
F_33 ( V_2 ) ;
V_2 -> V_8 . V_83 = V_84 ;
F_6 ( & V_2 -> V_76 ) ;
F_28 ( & V_2 -> V_8 . V_75 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_6 , V_85 ;
struct V_86 * V_10 ;
struct V_87 * V_64 ;
F_23 ( L_5 , V_2 -> V_8 . V_9 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_9 ; V_6 ++ ) {
V_10 = & V_2 -> V_8 . V_10 [ V_6 ] ;
F_23 ( L_6 , V_6 ,
V_88 [ V_10 -> type ] ) ;
if ( V_6 == V_2 -> V_8 . V_11 )
F_23 ( L_7 ) ;
if ( ( V_2 -> V_89 & V_90 ) && ! ( V_2 -> V_89 & V_91 ) )
F_23 ( L_8 , V_10 -> V_92 ) ;
if ( V_10 -> V_89 & V_93 )
F_23 ( L_9 ) ;
F_23 ( L_10 , V_10 -> V_94 ) ;
for ( V_85 = 0 ; V_85 < V_10 -> V_94 ; V_85 ++ ) {
V_64 = & ( V_10 -> V_64 [ V_85 ] ) ;
if ( V_2 -> V_89 & V_91 )
F_23 ( L_11 ,
V_85 ,
V_64 -> V_59 * 10 ) ;
else
F_23 ( L_12 ,
V_85 ,
V_64 -> V_59 * 10 ,
V_64 -> V_60 * 10 ,
V_64 -> V_95 . V_95 ) ;
}
}
}
static T_2 F_35 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_102 = F_36 ( V_97 ) ;
struct V_1 * V_2 = V_102 -> V_103 ;
int V_104 = V_2 -> V_8 . V_23 ;
return snprintf ( V_100 , V_105 , L_13 ,
( V_104 == V_24 ) ? L_14 :
( V_104 == V_33 ) ? L_15 :
( V_104 == V_36 ) ? L_16 :
( V_104 == V_37 ) ? L_17 : L_18 ) ;
}
static T_2 F_37 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_106 )
{
struct V_101 * V_102 = F_36 ( V_97 ) ;
struct V_1 * V_2 = V_102 -> V_103 ;
if ( ( V_2 -> V_89 & V_107 ) &&
( V_102 -> V_108 != V_109 ) )
return - V_110 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_22 ) {
if ( strncmp ( L_18 , V_100 , strlen ( L_18 ) ) == 0 )
V_2 -> V_8 . V_23 = V_25 ;
else if ( strncmp ( L_14 , V_100 , strlen ( L_14 ) ) == 0 )
V_2 -> V_8 . V_23 = V_24 ;
else if ( strncmp ( L_15 , V_100 , strlen ( L_15 ) ) == 0 )
V_2 -> V_8 . V_23 = V_33 ;
else if ( strncmp ( L_16 , V_100 , strlen ( L_16 ) ) == 0 )
V_2 -> V_8 . V_23 = V_36 ;
else if ( strncmp ( L_17 , V_100 , strlen ( L_17 ) ) == 0 )
V_2 -> V_8 . V_23 = V_37 ;
else {
V_106 = - V_110 ;
goto V_111;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else
V_106 = - V_110 ;
V_111:
F_6 ( & V_2 -> V_8 . V_15 ) ;
return V_106 ;
}
static T_2 F_38 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_102 = F_36 ( V_97 ) ;
struct V_1 * V_2 = V_102 -> V_103 ;
int V_8 = V_2 -> V_8 . V_12 ;
return snprintf ( V_100 , V_105 , L_13 ,
( V_8 == V_69 ) ? L_19 :
( V_8 == V_22 ) ? L_20 : L_21 ) ;
}
static T_2 F_39 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_106 )
{
struct V_101 * V_102 = F_36 ( V_97 ) ;
struct V_1 * V_2 = V_102 -> V_103 ;
if ( ( V_2 -> V_89 & V_107 ) &&
( V_102 -> V_108 != V_109 ) ) {
V_106 = - V_110 ;
goto V_111;
}
if ( V_2 -> V_8 . V_12 == V_13 ) {
V_106 = - V_110 ;
goto V_111;
}
if ( strncmp ( L_19 , V_100 , strlen ( L_19 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_12 = V_69 ;
V_2 -> V_8 . V_112 = V_113 ;
V_2 -> V_8 . V_83 = V_114 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else if ( strncmp ( L_20 , V_100 , strlen ( L_20 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_112 = V_115 ;
V_2 -> V_8 . V_83 = V_84 ;
V_2 -> V_8 . V_12 = V_22 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( & V_2 -> V_8 . V_116 ) ;
} else {
V_106 = - V_110 ;
goto V_111;
}
F_41 ( V_2 ) ;
V_111:
return V_106 ;
}
static T_2 F_42 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_102 = F_36 ( V_97 ) ;
struct V_1 * V_2 = V_102 -> V_103 ;
enum V_3 V_8 = V_2 -> V_8 . V_16 . V_117 ;
return snprintf ( V_100 , V_105 , L_13 ,
( V_8 == V_118 ) ? L_22 :
( V_8 == V_119 ) ? L_23 : L_24 ) ;
}
static T_2 F_43 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_106 )
{
struct V_101 * V_102 = F_36 ( V_97 ) ;
struct V_1 * V_2 = V_102 -> V_103 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_22 , V_100 , strlen ( L_22 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_118 ;
else if ( strncmp ( L_23 , V_100 , strlen ( L_23 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_119 ;
else if ( strncmp ( L_24 , V_100 , strlen ( L_24 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_120 ;
else {
F_6 ( & V_2 -> V_8 . V_15 ) ;
V_106 = - V_110 ;
goto V_111;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( ! ( V_2 -> V_89 & V_107 ) ||
( V_102 -> V_108 == V_109 ) )
F_41 ( V_2 ) ;
V_111:
return V_106 ;
}
static T_2 F_44 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_102 = F_36 ( V_97 ) ;
struct V_1 * V_2 = V_102 -> V_103 ;
enum V_121 V_122 = V_2 -> V_8 . V_16 . V_123 ;
if ( ( V_2 -> V_89 & V_107 ) &&
( V_102 -> V_108 != V_109 ) )
return snprintf ( V_100 , V_105 , L_25 ) ;
return snprintf ( V_100 , V_105 , L_13 ,
( V_122 == V_124 ) ? L_14 :
( V_122 == V_125 ) ? L_15 : L_17 ) ;
}
static T_2 F_45 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_106 )
{
struct V_101 * V_102 = F_36 ( V_97 ) ;
struct V_1 * V_2 = V_102 -> V_103 ;
enum V_121 V_122 ;
int V_126 = 0 ;
if ( ( V_2 -> V_89 & V_107 ) &&
( V_102 -> V_108 != V_109 ) )
return - V_110 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_15 , V_100 , strlen ( L_15 ) ) == 0 ) {
V_122 = V_125 ;
} else if ( strncmp ( L_17 , V_100 , strlen ( L_17 ) ) == 0 ) {
V_122 = V_127 ;
} else if ( strncmp ( L_14 , V_100 , strlen ( L_14 ) ) == 0 ) {
V_122 = V_124 ;
} else {
V_106 = - V_110 ;
goto V_111;
}
if ( V_2 -> V_20 -> V_16 . V_128 ) {
if ( V_2 -> V_8 . V_16 . V_129 ) {
V_106 = - V_110 ;
goto V_111;
}
V_126 = F_46 ( V_2 , V_122 ) ;
if ( V_126 )
V_106 = - V_110 ;
}
V_111:
F_6 ( & V_2 -> V_8 . V_15 ) ;
return V_106 ;
}
static T_2 F_47 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_36 ( V_97 ) ;
T_1 V_130 = 0 ;
if ( V_2 -> V_20 -> V_16 . V_131 )
V_130 = V_2 -> V_20 -> V_16 . V_131 ( V_2 ) ;
return sprintf ( V_100 , L_26 , V_130 == V_132 ? 1 : 2 ) ;
}
static T_2 F_48 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_106 )
{
struct V_1 * V_2 = F_36 ( V_97 ) ;
int V_133 ;
int V_134 ;
if( ! V_2 -> V_20 -> V_16 . V_135 )
return - V_110 ;
V_133 = F_49 ( V_100 , 10 , & V_134 ) ;
if ( V_133 )
return V_133 ;
switch ( V_134 ) {
case 1 :
V_2 -> V_20 -> V_16 . V_135 ( V_2 , V_132 ) ;
break;
default:
V_2 -> V_20 -> V_16 . V_135 ( V_2 , 0 ) ;
break;
}
return V_106 ;
}
static T_2 F_50 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
return sprintf ( V_100 , L_26 , 0 ) ;
}
static T_2 F_51 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
return sprintf ( V_100 , L_26 , 255 ) ;
}
static T_2 F_52 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 , T_3 V_106 )
{
struct V_1 * V_2 = F_36 ( V_97 ) ;
int V_133 ;
T_1 V_134 ;
V_133 = F_53 ( V_100 , 10 , & V_134 ) ;
if ( V_133 )
return V_133 ;
V_134 = ( V_134 * 100 ) / 255 ;
V_133 = V_2 -> V_20 -> V_16 . V_136 ( V_2 , V_134 ) ;
if ( V_133 )
return V_133 ;
return V_106 ;
}
static T_2 F_54 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_36 ( V_97 ) ;
int V_133 ;
T_1 V_137 ;
V_133 = V_2 -> V_20 -> V_16 . V_138 ( V_2 , & V_137 ) ;
if ( V_133 )
return V_133 ;
V_137 = ( V_137 * 255 ) / 100 ;
return sprintf ( V_100 , L_26 , V_137 ) ;
}
static T_2 F_55 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_36 ( V_97 ) ;
struct V_101 * V_102 = V_2 -> V_102 ;
int V_139 ;
if ( ( V_2 -> V_89 & V_107 ) &&
( V_102 -> V_108 != V_109 ) )
return - V_110 ;
if ( V_2 -> V_20 -> V_8 . V_140 )
V_139 = F_56 ( V_2 ) ;
else
V_139 = 0 ;
return snprintf ( V_100 , V_105 , L_27 , V_139 ) ;
}
static T_2 F_57 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_36 ( V_97 ) ;
int V_141 = F_58 ( V_99 ) -> V_142 ;
int V_139 ;
if ( V_141 )
V_139 = V_2 -> V_8 . V_16 . V_143 . V_144 ;
else
V_139 = V_2 -> V_8 . V_16 . V_143 . V_145 ;
return snprintf ( V_100 , V_105 , L_27 , V_139 ) ;
}
static T_4 F_59 ( struct V_146 * V_147 ,
struct V_148 * V_99 , int V_142 )
{
struct V_96 * V_97 = F_60 ( V_147 ) ;
struct V_1 * V_2 = F_36 ( V_97 ) ;
T_4 V_149 = V_99 -> V_150 ;
if ( V_2 -> V_8 . V_12 != V_13 &&
( V_99 == & V_151 . V_152 . V_99 ||
V_99 == & V_153 . V_152 . V_99 ||
V_99 == & V_154 . V_152 . V_99 ||
V_99 == & V_155 . V_152 . V_99 ||
V_99 == & V_156 . V_152 . V_99 ||
V_99 == & V_157 . V_152 . V_99 ) )
return 0 ;
if ( V_2 -> V_8 . V_158 &&
( V_99 == & V_154 . V_152 . V_99 ||
V_99 == & V_155 . V_152 . V_99 ||
V_99 == & V_156 . V_152 . V_99 ||
V_99 == & V_157 . V_152 . V_99 ) )
return 0 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_138 &&
V_99 == & V_154 . V_152 . V_99 ) ||
( ! V_2 -> V_20 -> V_16 . V_131 &&
V_99 == & V_155 . V_152 . V_99 ) )
V_149 &= ~ V_159 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_136 &&
V_99 == & V_154 . V_152 . V_99 ) ||
( ! V_2 -> V_20 -> V_16 . V_135 &&
V_99 == & V_155 . V_152 . V_99 ) )
V_149 &= ~ V_160 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_136 &&
! V_2 -> V_20 -> V_16 . V_138 ) &&
( V_99 == & V_156 . V_152 . V_99 ||
V_99 == & V_157 . V_152 . V_99 ) )
return 0 ;
return V_149 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_133 = 0 ;
switch ( V_2 -> V_8 . V_161 ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
if ( V_2 -> V_20 -> V_8 . V_140 == NULL )
return V_133 ;
V_2 -> V_8 . V_170 = F_62 ( V_2 -> V_97 ,
L_28 , V_2 ,
V_171 ) ;
if ( F_63 ( V_2 -> V_8 . V_170 ) ) {
V_133 = F_64 ( V_2 -> V_8 . V_170 ) ;
F_65 ( V_2 -> V_97 ,
L_29 , V_133 ) ;
}
break;
default:
break;
}
return V_133 ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_170 )
F_67 ( V_2 -> V_8 . V_170 ) ;
}
static void F_68 ( struct V_172 * V_173 )
{
struct V_1 * V_2 =
F_69 ( V_173 , struct V_1 ,
V_8 . V_16 . V_143 . V_173 ) ;
enum V_3 V_174 = V_175 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_20 -> V_8 . V_140 ) {
int V_139 = F_56 ( V_2 ) ;
if ( V_139 < V_2 -> V_8 . V_16 . V_143 . V_144 )
V_174 = V_2 -> V_8 . V_16 . V_117 ;
} else {
if ( V_2 -> V_8 . V_16 . V_143 . V_176 )
V_174 = V_2 -> V_8 . V_16 . V_117 ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_174 == V_175 )
V_2 -> V_8 . V_16 . V_129 = true ;
else
V_2 -> V_8 . V_16 . V_129 = false ;
V_2 -> V_8 . V_16 . V_177 = V_174 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_41 ( V_2 ) ;
}
static bool F_70 ( struct V_1 * V_2 )
{
bool V_178 = ( V_2 -> V_8 . V_16 . V_179 < 2 ) ?
true : false ;
if ( V_178 && V_2 -> V_20 -> V_16 . V_180 ) {
if ( F_71 ( V_2 ) )
V_178 = false ;
}
if ( V_178 && ( F_72 ( V_2 ) >= 120 ) )
V_178 = false ;
return V_178 ;
}
static struct V_181 * F_73 ( struct V_1 * V_2 ,
enum V_3 V_174 )
{
int V_6 ;
struct V_181 * V_182 ;
T_1 V_183 ;
bool V_178 = F_70 ( V_2 ) ;
if ( V_174 == V_120 )
V_174 = V_184 ;
if ( V_174 == V_119 )
V_174 = V_120 ;
V_185:
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_186 ; V_6 ++ ) {
V_182 = & V_2 -> V_8 . V_16 . V_182 [ V_6 ] ;
V_183 = V_182 -> V_187 & V_188 ;
switch ( V_174 ) {
case V_118 :
if ( V_183 == V_189 ) {
if ( V_182 -> V_190 & V_191 ) {
if ( V_178 )
return V_182 ;
} else
return V_182 ;
}
break;
case V_119 :
if ( V_183 == V_192 ) {
if ( V_182 -> V_190 & V_191 ) {
if ( V_178 )
return V_182 ;
} else
return V_182 ;
}
break;
case V_120 :
if ( V_183 == V_193 ) {
if ( V_182 -> V_190 & V_191 ) {
if ( V_178 )
return V_182 ;
} else
return V_182 ;
}
break;
case V_194 :
if ( V_2 -> V_8 . V_16 . V_195 )
return V_2 -> V_8 . V_16 . V_195 ;
else
break;
case V_196 :
if ( V_182 -> V_187 & V_197 )
return V_182 ;
break;
case V_198 :
if ( V_182 -> V_187 & V_199 )
return V_182 ;
break;
case V_200 :
if ( V_182 -> V_187 & V_201 )
return V_182 ;
break;
case V_202 :
if ( V_182 -> V_203 & V_204 )
return V_182 ;
break;
case V_205 :
return V_2 -> V_8 . V_16 . V_206 ;
case V_175 :
if ( V_182 -> V_187 & V_207 )
return V_182 ;
break;
case V_208 :
if ( V_182 -> V_187 & V_209 )
return V_182 ;
break;
case V_210 :
if ( V_182 -> V_203 & V_211 )
return V_182 ;
break;
case V_184 :
if ( V_182 -> V_187 & V_212 )
return V_182 ;
break;
default:
break;
}
}
switch ( V_174 ) {
case V_196 :
V_174 = V_198 ;
goto V_185;
case V_198 :
case V_200 :
case V_202 :
if ( V_2 -> V_8 . V_16 . V_195 ) {
return V_2 -> V_8 . V_16 . V_195 ;
} else {
V_174 = V_120 ;
goto V_185;
}
case V_175 :
V_174 = V_208 ;
goto V_185;
case V_208 :
V_174 = V_118 ;
goto V_185;
case V_118 :
case V_119 :
case V_184 :
V_174 = V_120 ;
goto V_185;
default:
break;
}
return NULL ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_181 * V_182 ;
enum V_3 V_174 ;
int V_126 ;
bool V_178 = F_70 ( V_2 ) ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_8 . V_16 . V_117 != V_2 -> V_8 . V_16 . V_177 ) {
if ( ( ! V_2 -> V_8 . V_16 . V_129 ) &&
( ! V_2 -> V_8 . V_16 . V_213 ) )
V_2 -> V_8 . V_16 . V_177 = V_2 -> V_8 . V_16 . V_117 ;
}
V_174 = V_2 -> V_8 . V_16 . V_177 ;
V_182 = F_73 ( V_2 , V_174 ) ;
if ( V_182 )
V_2 -> V_8 . V_16 . V_214 = V_182 ;
else
return;
if ( V_2 -> V_8 . V_16 . V_215 == V_2 -> V_8 . V_16 . V_214 ) {
if ( V_182 -> V_216 != V_2 -> V_8 . V_16 . V_216 )
goto V_217;
if ( V_2 -> V_8 . V_16 . V_178 != V_178 )
goto V_217;
if ( ( V_2 -> V_18 < V_66 ) || ( V_2 -> V_89 & V_91 ) ) {
if ( V_2 -> V_8 . V_16 . V_218 != V_2 -> V_8 . V_16 . V_219 ) {
F_33 ( V_2 ) ;
F_75 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_219 = V_2 -> V_8 . V_16 . V_218 ;
V_2 -> V_8 . V_16 . V_220 = V_2 -> V_8 . V_16 . V_179 ;
}
return;
} else {
if ( V_2 -> V_8 . V_16 . V_218 ==
V_2 -> V_8 . V_16 . V_219 ) {
return;
} else {
if ( ( V_2 -> V_8 . V_16 . V_220 > 1 ) &&
( V_2 -> V_8 . V_16 . V_179 > 1 ) ) {
F_33 ( V_2 ) ;
F_75 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_219 = V_2 -> V_8 . V_16 . V_218 ;
V_2 -> V_8 . V_16 . V_220 = V_2 -> V_8 . V_16 . V_179 ;
return;
}
}
}
}
V_217:
if ( V_221 == 1 ) {
F_76 ( L_30 ) ;
F_77 ( V_2 , V_2 -> V_8 . V_16 . V_215 ) ;
F_76 ( L_31 ) ;
F_77 ( V_2 , V_2 -> V_8 . V_16 . V_214 ) ;
}
F_26 ( & V_2 -> V_8 . V_75 ) ;
F_3 ( & V_2 -> V_76 ) ;
V_182 -> V_216 = V_2 -> V_8 . V_16 . V_216 ;
V_126 = F_78 ( V_2 ) ;
if ( V_126 )
goto V_222;
F_33 ( V_2 ) ;
F_75 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_77 ; V_6 ++ ) {
struct V_78 * V_79 = & V_2 -> V_79 [ V_6 ] ;
if ( V_79 -> V_80 )
F_27 ( V_2 , V_6 ) ;
}
F_79 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_215 = V_2 -> V_8 . V_16 . V_214 ;
F_80 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_219 = V_2 -> V_8 . V_16 . V_218 ;
V_2 -> V_8 . V_16 . V_220 = V_2 -> V_8 . V_16 . V_179 ;
V_2 -> V_8 . V_16 . V_178 = V_178 ;
if ( V_2 -> V_20 -> V_16 . V_128 ) {
if ( V_2 -> V_8 . V_16 . V_129 ) {
enum V_121 V_122 = V_2 -> V_8 . V_16 . V_123 ;
F_46 ( V_2 , V_125 ) ;
V_2 -> V_8 . V_16 . V_123 = V_122 ;
} else {
F_46 ( V_2 , V_2 -> V_8 . V_16 . V_123 ) ;
}
}
V_222:
F_6 ( & V_2 -> V_76 ) ;
F_28 ( & V_2 -> V_8 . V_75 ) ;
}
void F_81 ( struct V_1 * V_2 , bool V_223 )
{
enum V_3 V_174 ;
if ( V_2 -> V_20 -> V_16 . V_224 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_223 |= V_2 -> V_8 . V_16 . V_225 > 0 ;
V_223 |= V_2 -> V_8 . V_16 . V_226 > 0 ;
F_82 ( V_2 , ! V_223 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
if ( V_223 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_213 = true ;
#if 0
if ((rdev->pm.dpm.sd == 1) && (rdev->pm.dpm.hd == 0))
dpm_state = POWER_STATE_TYPE_INTERNAL_UVD_SD;
else if ((rdev->pm.dpm.sd == 2) && (rdev->pm.dpm.hd == 0))
dpm_state = POWER_STATE_TYPE_INTERNAL_UVD_HD;
else if ((rdev->pm.dpm.sd == 0) && (rdev->pm.dpm.hd == 1))
dpm_state = POWER_STATE_TYPE_INTERNAL_UVD_HD;
else if ((rdev->pm.dpm.sd == 0) && (rdev->pm.dpm.hd == 2))
dpm_state = POWER_STATE_TYPE_INTERNAL_UVD_HD2;
else
#endif
V_174 = V_194 ;
V_2 -> V_8 . V_16 . V_177 = V_174 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_213 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_41 ( V_2 ) ;
}
}
void F_83 ( struct V_1 * V_2 , bool V_223 )
{
if ( V_223 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_216 = true ;
V_2 -> V_8 . V_16 . V_227 = V_228 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_216 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_41 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_69 ) {
if ( V_2 -> V_8 . V_112 == V_229 )
V_2 -> V_8 . V_112 = V_230 ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( & V_2 -> V_8 . V_116 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_86 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_215 = V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_206 ;
V_2 -> V_8 . V_14 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_85 ( V_2 ) ;
else
F_84 ( V_2 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_231 ) &&
V_2 -> V_232 ) {
if ( V_2 -> V_8 . V_233 )
F_89 ( V_2 , V_2 -> V_8 . V_233 ,
V_234 ) ;
if ( V_2 -> V_8 . V_235 )
F_89 ( V_2 , V_2 -> V_8 . V_235 ,
V_236 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_63 = V_2 -> V_8 . V_11 ;
V_2 -> V_8 . V_62 = 0 ;
V_2 -> V_8 . V_68 = V_2 -> V_8 . V_65 ;
V_2 -> V_8 . V_71 = V_2 -> V_8 . V_67 ;
if ( V_2 -> V_8 . V_10 ) {
V_2 -> V_8 . V_237 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_64 [ 0 ] . V_95 . V_95 ;
V_2 -> V_8 . V_238 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_64 [ 0 ] . V_95 . V_239 ;
}
if ( V_2 -> V_8 . V_12 == V_69
&& V_2 -> V_8 . V_112 == V_230 ) {
V_2 -> V_8 . V_112 = V_229 ;
F_90 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_240 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_41 ( V_2 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_126 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_215 = V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_206 ;
F_92 ( V_2 ) ;
V_126 = F_93 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_126 )
goto V_241;
V_2 -> V_8 . V_14 = true ;
return;
V_241:
F_94 ( L_32 ) ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_231 ) &&
V_2 -> V_232 ) {
if ( V_2 -> V_8 . V_233 )
F_89 ( V_2 , V_2 -> V_8 . V_233 ,
V_234 ) ;
if ( V_2 -> V_8 . V_235 )
F_89 ( V_2 , V_2 -> V_8 . V_235 ,
V_236 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
}
void F_95 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_91 ( V_2 ) ;
else
F_88 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_126 ;
V_2 -> V_8 . V_23 = V_25 ;
V_2 -> V_8 . V_112 = V_115 ;
V_2 -> V_8 . V_83 = V_84 ;
V_2 -> V_8 . V_242 = true ;
V_2 -> V_8 . V_243 = true ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_71 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_161 = V_244 ;
if ( V_2 -> V_245 ) {
if ( V_2 -> V_246 )
F_97 ( V_2 ) ;
else
F_98 ( V_2 ) ;
F_34 ( V_2 ) ;
F_99 ( V_2 ) ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_231 ) &&
V_2 -> V_232 ) {
if ( V_2 -> V_8 . V_233 )
F_89 ( V_2 , V_2 -> V_8 . V_233 ,
V_234 ) ;
if ( V_2 -> V_8 . V_235 )
F_89 ( V_2 , V_2 -> V_8 . V_235 ,
V_236 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
}
V_126 = F_61 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_100 ( & V_2 -> V_8 . V_116 , V_247 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
if ( F_101 ( V_2 ) ) {
F_94 ( L_33 ) ;
}
F_102 ( L_34 ) ;
}
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_186 ; V_6 ++ ) {
F_76 ( L_35 , V_6 ) ;
F_77 ( V_2 , & V_2 -> V_8 . V_16 . V_182 [ V_6 ] ) ;
}
}
static int F_104 ( struct V_1 * V_2 )
{
int V_126 ;
V_2 -> V_8 . V_16 . V_177 = V_119 ;
V_2 -> V_8 . V_16 . V_117 = V_119 ;
V_2 -> V_8 . V_16 . V_123 = V_124 ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_71 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_161 = V_244 ;
if ( V_2 -> V_245 && V_2 -> V_246 )
F_97 ( V_2 ) ;
else
return - V_110 ;
V_126 = F_61 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_105 ( & V_2 -> V_8 . V_16 . V_143 . V_173 , F_68 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_106 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_215 = V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_206 ;
if ( V_221 == 1 )
F_103 ( V_2 ) ;
F_92 ( V_2 ) ;
V_126 = F_93 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_126 )
goto V_248;
V_2 -> V_8 . V_14 = true ;
if ( F_101 ( V_2 ) ) {
F_94 ( L_36 ) ;
}
F_102 ( L_37 ) ;
return 0 ;
V_248:
V_2 -> V_8 . V_14 = false ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_231 ) &&
V_2 -> V_232 ) {
if ( V_2 -> V_8 . V_233 )
F_89 ( V_2 , V_2 -> V_8 . V_233 ,
V_234 ) ;
if ( V_2 -> V_8 . V_235 )
F_89 ( V_2 , V_2 -> V_8 . V_235 ,
V_236 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
F_94 ( L_38 ) ;
return V_126 ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_249 * V_250 = V_251 ;
bool V_252 = false ;
while ( V_250 && V_250 -> V_253 != 0 ) {
if ( V_2 -> V_254 -> V_255 == V_250 -> V_256 &&
V_2 -> V_254 -> V_96 == V_250 -> V_253 &&
V_2 -> V_254 -> V_257 == V_250 -> V_258 &&
V_2 -> V_254 -> V_259 == V_250 -> V_260 ) {
V_252 = true ;
break;
}
++ V_250 ;
}
switch ( V_2 -> V_18 ) {
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
if ( ! V_2 -> V_269 )
V_2 -> V_8 . V_12 = V_22 ;
else if ( ( V_2 -> V_18 >= V_268 ) &&
( ! ( V_2 -> V_89 & V_91 ) ) &&
( ! V_2 -> V_270 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_221 == 1 )
V_2 -> V_8 . V_12 = V_13 ;
else
V_2 -> V_8 . V_12 = V_22 ;
break;
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_66 :
case V_282 :
case V_283 :
case V_231 :
case V_19 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
if ( ! V_2 -> V_269 )
V_2 -> V_8 . V_12 = V_22 ;
else if ( ( V_2 -> V_18 >= V_268 ) &&
( ! ( V_2 -> V_89 & V_91 ) ) &&
( ! V_2 -> V_270 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_252 && ( V_221 == - 1 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_221 == 0 )
V_2 -> V_8 . V_12 = V_22 ;
else
V_2 -> V_8 . V_12 = V_13 ;
break;
default:
V_2 -> V_8 . V_12 = V_22 ;
break;
}
if ( V_2 -> V_8 . V_12 == V_13 )
return F_104 ( V_2 ) ;
else
return F_96 ( V_2 ) ;
}
int F_108 ( struct V_1 * V_2 )
{
int V_126 = 0 ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
if ( V_2 -> V_8 . V_14 ) {
if ( ! V_2 -> V_8 . V_294 ) {
V_126 = F_109 ( V_2 -> V_97 , & V_295 ) ;
if ( V_126 )
F_94 ( L_39 ) ;
V_126 = F_109 ( V_2 -> V_97 , & V_296 ) ;
if ( V_126 )
F_94 ( L_39 ) ;
V_126 = F_109 ( V_2 -> V_97 , & V_297 ) ;
if ( V_126 )
F_94 ( L_40 ) ;
V_126 = F_109 ( V_2 -> V_97 , & V_298 ) ;
if ( V_126 )
F_94 ( L_41 ) ;
V_2 -> V_8 . V_294 = true ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_126 = F_110 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_126 ) {
V_2 -> V_8 . V_14 = false ;
F_94 ( L_42 ) ;
} else {
F_41 ( V_2 ) ;
}
}
} else {
if ( ( V_2 -> V_8 . V_9 > 1 ) &&
( ! V_2 -> V_8 . V_294 ) ) {
V_126 = F_109 ( V_2 -> V_97 , & V_297 ) ;
if ( V_126 )
F_94 ( L_40 ) ;
V_126 = F_109 ( V_2 -> V_97 , & V_298 ) ;
if ( V_126 )
F_94 ( L_41 ) ;
if ( ! V_126 )
V_2 -> V_8 . V_294 = true ;
}
}
return V_126 ;
}
static void F_111 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_22 ) {
V_2 -> V_8 . V_23 = V_25 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_69 ) {
V_2 -> V_8 . V_112 = V_115 ;
V_2 -> V_8 . V_83 = V_114 ;
F_8 ( V_2 ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( & V_2 -> V_8 . V_116 ) ;
F_112 ( V_2 -> V_97 , & V_297 ) ;
F_112 ( V_2 -> V_97 , & V_298 ) ;
}
F_66 ( V_2 ) ;
F_113 ( V_2 -> V_8 . V_10 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_86 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_112 ( V_2 -> V_97 , & V_295 ) ;
F_112 ( V_2 -> V_97 , & V_296 ) ;
F_112 ( V_2 -> V_97 , & V_297 ) ;
F_112 ( V_2 -> V_97 , & V_298 ) ;
}
F_115 ( V_2 ) ;
F_66 ( V_2 ) ;
F_113 ( V_2 -> V_8 . V_10 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_114 ( V_2 ) ;
else
F_111 ( V_2 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = V_2 -> V_102 ;
struct V_72 * V_73 ;
struct V_299 * V_299 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_54 = 0 ;
V_2 -> V_8 . V_28 = 0 ;
if ( V_2 -> V_300 && V_2 -> V_301 . V_302 ) {
F_118 (crtc,
&ddev->mode_config.crtc_list, head) {
V_299 = F_119 ( V_73 ) ;
if ( V_299 -> V_303 ) {
V_2 -> V_8 . V_54 |= ( 1 << V_299 -> V_304 ) ;
V_2 -> V_8 . V_28 ++ ;
}
}
}
if ( V_2 -> V_8 . V_12 == V_22 ) {
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_69 ) {
if ( V_2 -> V_8 . V_112 != V_115 ) {
if ( V_2 -> V_8 . V_28 > 1 ) {
if ( V_2 -> V_8 . V_112 == V_229 ) {
F_120 ( & V_2 -> V_8 . V_116 ) ;
V_2 -> V_8 . V_112 = V_113 ;
V_2 -> V_8 . V_83 = V_114 ;
F_121 ( V_2 ) ;
F_8 ( V_2 ) ;
F_23 ( L_43 ) ;
}
} else if ( V_2 -> V_8 . V_28 == 1 ) {
if ( V_2 -> V_8 . V_112 == V_305 ) {
V_2 -> V_8 . V_112 = V_229 ;
V_2 -> V_8 . V_83 = V_306 ;
F_121 ( V_2 ) ;
F_8 ( V_2 ) ;
F_90 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_240 ) ) ;
} else if ( V_2 -> V_8 . V_112 == V_113 ) {
V_2 -> V_8 . V_112 = V_229 ;
F_90 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_240 ) ) ;
F_23 ( L_44 ) ;
}
} else {
if ( V_2 -> V_8 . V_112 != V_305 ) {
F_120 ( & V_2 -> V_8 . V_116 ) ;
V_2 -> V_8 . V_112 = V_305 ;
V_2 -> V_8 . V_83 = V_307 ;
F_121 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = V_2 -> V_102 ;
struct V_72 * V_73 ;
struct V_299 * V_299 ;
if ( ! V_2 -> V_8 . V_14 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_218 = 0 ;
V_2 -> V_8 . V_16 . V_179 = 0 ;
if ( V_2 -> V_300 && V_2 -> V_301 . V_302 ) {
F_118 (crtc,
&ddev->mode_config.crtc_list, head) {
V_299 = F_119 ( V_73 ) ;
if ( V_73 -> V_303 ) {
V_2 -> V_8 . V_16 . V_218 |= ( 1 << V_299 -> V_304 ) ;
V_2 -> V_8 . V_16 . V_179 ++ ;
}
}
}
if ( F_4 () > 0 )
V_2 -> V_8 . V_16 . V_17 = true ;
else
V_2 -> V_8 . V_16 . V_17 = false ;
F_74 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_122 ( V_2 ) ;
else
F_117 ( V_2 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
int V_73 , V_308 , V_309 , V_310 ;
bool V_311 = true ;
for ( V_73 = 0 ; ( V_73 < V_2 -> V_300 ) && V_311 ; V_73 ++ ) {
if ( V_2 -> V_8 . V_54 & ( 1 << V_73 ) ) {
V_310 = F_123 ( V_2 -> V_102 ,
V_73 ,
V_312 ,
& V_308 , & V_309 , NULL , NULL ,
& V_2 -> V_301 . V_313 [ V_73 ] -> V_314 . V_315 ) ;
if ( ( V_310 & V_316 ) &&
! ( V_310 & V_317 ) )
V_311 = false ;
}
}
return V_311 ;
}
static bool F_21 ( struct V_1 * V_2 , bool V_318 )
{
T_1 V_319 = 0 ;
bool V_311 = F_18 ( V_2 ) ;
if ( V_311 == false )
F_23 ( L_45 , V_319 ,
V_318 ? L_46 : L_47 ) ;
return V_311 ;
}
static void V_247 ( struct V_172 * V_173 )
{
struct V_1 * V_2 ;
int V_320 ;
V_2 = F_69 ( V_173 , struct V_1 ,
V_8 . V_116 . V_173 ) ;
V_320 = F_124 ( & V_2 -> V_321 . V_322 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_112 == V_229 ) {
int V_323 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_77 ; ++ V_6 ) {
struct V_78 * V_79 = & V_2 -> V_79 [ V_6 ] ;
if ( V_79 -> V_80 ) {
V_323 += F_125 ( V_2 , V_6 ) ;
if ( V_323 >= 3 )
break;
}
}
if ( V_323 >= 3 ) {
if ( V_2 -> V_8 . V_83 == V_324 ) {
V_2 -> V_8 . V_83 = V_84 ;
} else if ( V_2 -> V_8 . V_83 == V_84 &&
V_2 -> V_8 . V_242 ) {
V_2 -> V_8 . V_83 =
V_306 ;
V_2 -> V_8 . V_325 = V_326 +
F_15 ( V_327 ) ;
}
} else if ( V_323 == 0 ) {
if ( V_2 -> V_8 . V_83 == V_306 ) {
V_2 -> V_8 . V_83 = V_84 ;
} else if ( V_2 -> V_8 . V_83 == V_84 &&
V_2 -> V_8 . V_243 ) {
V_2 -> V_8 . V_83 =
V_324 ;
V_2 -> V_8 . V_325 = V_326 +
F_15 ( V_327 ) ;
}
}
if ( V_2 -> V_8 . V_83 != V_84 &&
V_326 > V_2 -> V_8 . V_325 ) {
F_121 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_90 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_240 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_126 ( & V_2 -> V_321 . V_322 , V_320 ) ;
}
static int F_127 ( struct V_328 * V_329 , void * V_330 )
{
struct V_331 * V_332 = (struct V_331 * ) V_329 -> V_333 ;
struct V_101 * V_97 = V_332 -> V_334 -> V_97 ;
struct V_1 * V_2 = V_97 -> V_103 ;
struct V_101 * V_102 = V_2 -> V_102 ;
if ( ( V_2 -> V_89 & V_107 ) &&
( V_102 -> V_108 != V_109 ) ) {
F_128 ( V_329 , L_48 ) ;
} else if ( V_2 -> V_8 . V_14 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_20 -> V_16 . V_335 )
F_129 ( V_2 , V_329 ) ;
else
F_128 ( V_329 , L_49 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_128 ( V_329 , L_50 , V_2 -> V_8 . V_65 ) ;
if ( ( V_2 -> V_18 >= V_279 ) && ( V_2 -> V_89 & V_91 ) )
F_128 ( V_329 , L_51 , V_2 -> V_8 . V_68 ) ;
else
F_128 ( V_329 , L_51 , F_130 ( V_2 ) ) ;
F_128 ( V_329 , L_52 , V_2 -> V_8 . V_67 ) ;
if ( V_2 -> V_20 -> V_8 . V_336 )
F_128 ( V_329 , L_53 , F_131 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_237 )
F_128 ( V_329 , L_54 , V_2 -> V_8 . V_237 ) ;
if ( V_2 -> V_20 -> V_8 . V_337 )
F_128 ( V_329 , L_55 , F_132 ( V_2 ) ) ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
#if F_133 ( V_338 )
return F_134 ( V_2 , V_339 , F_135 ( V_339 ) ) ;
#else
return 0 ;
#endif
}
