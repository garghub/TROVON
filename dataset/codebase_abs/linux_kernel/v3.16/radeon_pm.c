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
int V_6 , V_72 ;
if ( ( V_2 -> V_8 . V_41 == V_2 -> V_8 . V_62 ) &&
( V_2 -> V_8 . V_38 == V_2 -> V_8 . V_63 ) )
return;
F_3 ( & V_2 -> V_73 -> V_74 ) ;
F_26 ( & V_2 -> V_8 . V_75 ) ;
F_3 ( & V_2 -> V_76 ) ;
for ( V_6 = 0 ; V_6 < V_77 ; V_6 ++ ) {
struct V_78 * V_79 = & V_2 -> V_79 [ V_6 ] ;
if ( ! V_79 -> V_80 ) {
continue;
}
V_72 = F_27 ( V_2 , V_6 ) ;
if ( V_72 ) {
F_6 ( & V_2 -> V_76 ) ;
F_28 ( & V_2 -> V_8 . V_75 ) ;
F_6 ( & V_2 -> V_73 -> V_74 ) ;
return;
}
}
F_9 ( V_2 ) ;
if ( V_2 -> V_56 . V_81 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_82 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_54 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_83 |= ( 1 << V_6 ) ;
F_29 ( V_2 -> V_73 , V_6 ) ;
}
}
}
F_16 ( V_2 ) ;
if ( V_2 -> V_56 . V_81 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_82 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_83 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_83 &= ~ ( 1 << V_6 ) ;
F_30 ( V_2 -> V_73 , V_6 ) ;
}
}
}
F_31 ( V_2 ) ;
if ( V_2 -> V_8 . V_28 )
F_32 ( V_2 ) ;
V_2 -> V_8 . V_84 = V_85 ;
F_6 ( & V_2 -> V_76 ) ;
F_28 ( & V_2 -> V_8 . V_75 ) ;
F_6 ( & V_2 -> V_73 -> V_74 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_6 , V_86 ;
struct V_87 * V_10 ;
struct V_88 * V_64 ;
F_23 ( L_4 , V_2 -> V_8 . V_9 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_9 ; V_6 ++ ) {
V_10 = & V_2 -> V_8 . V_10 [ V_6 ] ;
F_23 ( L_5 , V_6 ,
V_89 [ V_10 -> type ] ) ;
if ( V_6 == V_2 -> V_8 . V_11 )
F_23 ( L_6 ) ;
if ( ( V_2 -> V_90 & V_91 ) && ! ( V_2 -> V_90 & V_92 ) )
F_23 ( L_7 , V_10 -> V_93 ) ;
if ( V_10 -> V_90 & V_94 )
F_23 ( L_8 ) ;
F_23 ( L_9 , V_10 -> V_95 ) ;
for ( V_86 = 0 ; V_86 < V_10 -> V_95 ; V_86 ++ ) {
V_64 = & ( V_10 -> V_64 [ V_86 ] ) ;
if ( V_2 -> V_90 & V_92 )
F_23 ( L_10 ,
V_86 ,
V_64 -> V_59 * 10 ) ;
else
F_23 ( L_11 ,
V_86 ,
V_64 -> V_59 * 10 ,
V_64 -> V_60 * 10 ,
V_64 -> V_96 . V_96 ) ;
}
}
}
static T_2 F_34 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
int V_104 = V_2 -> V_8 . V_23 ;
return snprintf ( V_101 , V_105 , L_12 ,
( V_104 == V_24 ) ? L_13 :
( V_104 == V_33 ) ? L_14 :
( V_104 == V_36 ) ? L_15 :
( V_104 == V_37 ) ? L_16 : L_17 ) ;
}
static T_2 F_36 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_101 ,
T_3 V_106 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) )
return - V_110 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_22 ) {
if ( strncmp ( L_17 , V_101 , strlen ( L_17 ) ) == 0 )
V_2 -> V_8 . V_23 = V_25 ;
else if ( strncmp ( L_13 , V_101 , strlen ( L_13 ) ) == 0 )
V_2 -> V_8 . V_23 = V_24 ;
else if ( strncmp ( L_14 , V_101 , strlen ( L_14 ) ) == 0 )
V_2 -> V_8 . V_23 = V_33 ;
else if ( strncmp ( L_15 , V_101 , strlen ( L_15 ) ) == 0 )
V_2 -> V_8 . V_23 = V_36 ;
else if ( strncmp ( L_16 , V_101 , strlen ( L_16 ) ) == 0 )
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
static T_2 F_37 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
int V_8 = V_2 -> V_8 . V_12 ;
return snprintf ( V_101 , V_105 , L_12 ,
( V_8 == V_69 ) ? L_18 :
( V_8 == V_22 ) ? L_19 : L_20 ) ;
}
static T_2 F_38 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_101 ,
T_3 V_106 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) ) {
V_106 = - V_110 ;
goto V_111;
}
if ( V_2 -> V_8 . V_12 == V_13 ) {
V_106 = - V_110 ;
goto V_111;
}
if ( strncmp ( L_18 , V_101 , strlen ( L_18 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_12 = V_69 ;
V_2 -> V_8 . V_112 = V_113 ;
V_2 -> V_8 . V_84 = V_114 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else if ( strncmp ( L_19 , V_101 , strlen ( L_19 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_112 = V_115 ;
V_2 -> V_8 . V_84 = V_85 ;
V_2 -> V_8 . V_12 = V_22 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_116 ) ;
} else {
V_106 = - V_110 ;
goto V_111;
}
F_40 ( V_2 ) ;
V_111:
return V_106 ;
}
static T_2 F_41 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
enum V_3 V_8 = V_2 -> V_8 . V_16 . V_117 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) )
return snprintf ( V_101 , V_105 , L_21 ) ;
return snprintf ( V_101 , V_105 , L_12 ,
( V_8 == V_118 ) ? L_22 :
( V_8 == V_119 ) ? L_23 : L_24 ) ;
}
static T_2 F_42 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_101 ,
T_3 V_106 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) )
return - V_110 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_22 , V_101 , strlen ( L_22 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_118 ;
else if ( strncmp ( L_23 , V_101 , strlen ( L_23 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_119 ;
else if ( strncmp ( L_24 , V_101 , strlen ( L_24 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_120 ;
else {
F_6 ( & V_2 -> V_8 . V_15 ) ;
V_106 = - V_110 ;
goto V_111;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
V_111:
return V_106 ;
}
static T_2 F_43 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
enum V_121 V_122 = V_2 -> V_8 . V_16 . V_123 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) )
return snprintf ( V_101 , V_105 , L_21 ) ;
return snprintf ( V_101 , V_105 , L_12 ,
( V_122 == V_124 ) ? L_13 :
( V_122 == V_125 ) ? L_14 : L_16 ) ;
}
static T_2 F_44 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_101 ,
T_3 V_106 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
enum V_121 V_122 ;
int V_126 = 0 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) )
return - V_110 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_14 , V_101 , strlen ( L_14 ) ) == 0 ) {
V_122 = V_125 ;
} else if ( strncmp ( L_16 , V_101 , strlen ( L_16 ) ) == 0 ) {
V_122 = V_127 ;
} else if ( strncmp ( L_13 , V_101 , strlen ( L_13 ) ) == 0 ) {
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
V_126 = F_45 ( V_2 , V_122 ) ;
if ( V_126 )
V_106 = - V_110 ;
}
V_111:
F_6 ( & V_2 -> V_8 . V_15 ) ;
return V_106 ;
}
static T_2 F_46 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_1 * V_2 = F_35 ( V_98 ) ;
struct V_102 * V_73 = V_2 -> V_73 ;
int V_130 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) )
return - V_110 ;
if ( V_2 -> V_20 -> V_8 . V_131 )
V_130 = F_47 ( V_2 ) ;
else
V_130 = 0 ;
return snprintf ( V_101 , V_105 , L_25 , V_130 ) ;
}
static T_2 F_48 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_1 * V_2 = F_35 ( V_98 ) ;
int V_132 = F_49 ( V_100 ) -> V_133 ;
int V_130 ;
if ( V_132 )
V_130 = V_2 -> V_8 . V_16 . V_134 . V_135 ;
else
V_130 = V_2 -> V_8 . V_16 . V_134 . V_136 ;
return snprintf ( V_101 , V_105 , L_25 , V_130 ) ;
}
static T_4 F_50 ( struct V_137 * V_138 ,
struct V_139 * V_100 , int V_133 )
{
struct V_97 * V_98 = F_51 ( V_138 , struct V_97 , V_138 ) ;
struct V_1 * V_2 = F_35 ( V_98 ) ;
if ( V_2 -> V_8 . V_12 != V_13 &&
( V_100 == & V_140 . V_141 . V_100 ||
V_100 == & V_142 . V_141 . V_100 ) )
return 0 ;
return V_100 -> V_143 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_144 = 0 ;
switch ( V_2 -> V_8 . V_145 ) {
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
if ( V_2 -> V_20 -> V_8 . V_131 == NULL )
return V_144 ;
V_2 -> V_8 . V_154 = F_53 ( V_2 -> V_98 ,
L_26 , V_2 ,
V_155 ) ;
if ( F_54 ( V_2 -> V_8 . V_154 ) ) {
V_144 = F_55 ( V_2 -> V_8 . V_154 ) ;
F_56 ( V_2 -> V_98 ,
L_27 , V_144 ) ;
}
break;
default:
break;
}
return V_144 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_154 )
F_58 ( V_2 -> V_8 . V_154 ) ;
}
static void F_59 ( struct V_156 * V_157 )
{
struct V_1 * V_2 =
F_51 ( V_157 , struct V_1 ,
V_8 . V_16 . V_134 . V_157 ) ;
enum V_3 V_158 = V_159 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_20 -> V_8 . V_131 ) {
int V_130 = F_47 ( V_2 ) ;
if ( V_130 < V_2 -> V_8 . V_16 . V_134 . V_135 )
V_158 = V_2 -> V_8 . V_16 . V_117 ;
} else {
if ( V_2 -> V_8 . V_16 . V_134 . V_160 )
V_158 = V_2 -> V_8 . V_16 . V_117 ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_158 == V_159 )
V_2 -> V_8 . V_16 . V_129 = true ;
else
V_2 -> V_8 . V_16 . V_129 = false ;
V_2 -> V_8 . V_16 . V_161 = V_158 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static struct V_162 * F_60 ( struct V_1 * V_2 ,
enum V_3 V_158 )
{
int V_6 ;
struct V_162 * V_163 ;
T_1 V_164 ;
bool V_165 = ( V_2 -> V_8 . V_16 . V_166 < 2 ) ?
true : false ;
if ( V_165 && V_2 -> V_20 -> V_16 . V_167 ) {
if ( F_61 ( V_2 ) )
V_165 = false ;
}
if ( V_158 == V_120 )
V_158 = V_168 ;
if ( V_158 == V_119 )
V_158 = V_120 ;
V_169:
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_170 ; V_6 ++ ) {
V_163 = & V_2 -> V_8 . V_16 . V_163 [ V_6 ] ;
V_164 = V_163 -> V_171 & V_172 ;
switch ( V_158 ) {
case V_118 :
if ( V_164 == V_173 ) {
if ( V_163 -> V_174 & V_175 ) {
if ( V_165 )
return V_163 ;
} else
return V_163 ;
}
break;
case V_119 :
if ( V_164 == V_176 ) {
if ( V_163 -> V_174 & V_175 ) {
if ( V_165 )
return V_163 ;
} else
return V_163 ;
}
break;
case V_120 :
if ( V_164 == V_177 ) {
if ( V_163 -> V_174 & V_175 ) {
if ( V_165 )
return V_163 ;
} else
return V_163 ;
}
break;
case V_178 :
if ( V_2 -> V_8 . V_16 . V_179 )
return V_2 -> V_8 . V_16 . V_179 ;
else
break;
case V_180 :
if ( V_163 -> V_171 & V_181 )
return V_163 ;
break;
case V_182 :
if ( V_163 -> V_171 & V_183 )
return V_163 ;
break;
case V_184 :
if ( V_163 -> V_171 & V_185 )
return V_163 ;
break;
case V_186 :
if ( V_163 -> V_187 & V_188 )
return V_163 ;
break;
case V_189 :
return V_2 -> V_8 . V_16 . V_190 ;
case V_159 :
if ( V_163 -> V_171 & V_191 )
return V_163 ;
break;
case V_192 :
if ( V_163 -> V_171 & V_193 )
return V_163 ;
break;
case V_194 :
if ( V_163 -> V_187 & V_195 )
return V_163 ;
break;
case V_168 :
if ( V_163 -> V_171 & V_196 )
return V_163 ;
break;
default:
break;
}
}
switch ( V_158 ) {
case V_180 :
V_158 = V_182 ;
goto V_169;
case V_182 :
case V_184 :
case V_186 :
if ( V_2 -> V_8 . V_16 . V_179 ) {
return V_2 -> V_8 . V_16 . V_179 ;
} else {
V_158 = V_120 ;
goto V_169;
}
case V_159 :
V_158 = V_192 ;
goto V_169;
case V_192 :
V_158 = V_118 ;
goto V_169;
case V_118 :
case V_119 :
case V_168 :
V_158 = V_120 ;
goto V_169;
default:
break;
}
return NULL ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_162 * V_163 ;
enum V_3 V_158 ;
int V_126 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_8 . V_16 . V_117 != V_2 -> V_8 . V_16 . V_161 ) {
if ( ( ! V_2 -> V_8 . V_16 . V_129 ) &&
( ! V_2 -> V_8 . V_16 . V_197 ) )
V_2 -> V_8 . V_16 . V_161 = V_2 -> V_8 . V_16 . V_117 ;
}
V_158 = V_2 -> V_8 . V_16 . V_161 ;
V_163 = F_60 ( V_2 , V_158 ) ;
if ( V_163 )
V_2 -> V_8 . V_16 . V_198 = V_163 ;
else
return;
if ( V_2 -> V_8 . V_16 . V_199 == V_2 -> V_8 . V_16 . V_198 ) {
if ( V_163 -> V_200 != V_2 -> V_8 . V_16 . V_200 )
goto V_201;
if ( ( V_2 -> V_18 < V_66 ) || ( V_2 -> V_90 & V_92 ) ) {
if ( V_2 -> V_8 . V_16 . V_202 != V_2 -> V_8 . V_16 . V_203 ) {
F_32 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_203 = V_2 -> V_8 . V_16 . V_202 ;
V_2 -> V_8 . V_16 . V_204 = V_2 -> V_8 . V_16 . V_166 ;
}
return;
} else {
if ( V_2 -> V_8 . V_16 . V_202 ==
V_2 -> V_8 . V_16 . V_203 ) {
return;
} else {
if ( ( V_2 -> V_8 . V_16 . V_204 > 1 ) &&
( V_2 -> V_8 . V_16 . V_166 > 1 ) ) {
F_32 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_203 = V_2 -> V_8 . V_16 . V_202 ;
V_2 -> V_8 . V_16 . V_204 = V_2 -> V_8 . V_16 . V_166 ;
return;
}
}
}
}
V_201:
if ( V_205 == 1 ) {
F_64 ( L_28 ) ;
F_65 ( V_2 , V_2 -> V_8 . V_16 . V_199 ) ;
F_64 ( L_29 ) ;
F_65 ( V_2 , V_2 -> V_8 . V_16 . V_198 ) ;
}
F_3 ( & V_2 -> V_73 -> V_74 ) ;
F_26 ( & V_2 -> V_8 . V_75 ) ;
F_3 ( & V_2 -> V_76 ) ;
V_163 -> V_200 = V_2 -> V_8 . V_16 . V_200 ;
V_126 = F_66 ( V_2 ) ;
if ( V_126 )
goto V_206;
F_32 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_203 = V_2 -> V_8 . V_16 . V_202 ;
V_2 -> V_8 . V_16 . V_204 = V_2 -> V_8 . V_16 . V_166 ;
for ( V_6 = 0 ; V_6 < V_77 ; V_6 ++ ) {
struct V_78 * V_79 = & V_2 -> V_79 [ V_6 ] ;
if ( V_79 -> V_80 )
F_27 ( V_2 , V_6 ) ;
}
F_67 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_199 = V_2 -> V_8 . V_16 . V_198 ;
F_68 ( V_2 ) ;
if ( V_2 -> V_20 -> V_16 . V_128 ) {
if ( V_2 -> V_8 . V_16 . V_129 ) {
enum V_121 V_122 = V_2 -> V_8 . V_16 . V_123 ;
F_45 ( V_2 , V_125 ) ;
V_2 -> V_8 . V_16 . V_123 = V_122 ;
} else {
F_45 ( V_2 , V_2 -> V_8 . V_16 . V_123 ) ;
}
}
V_206:
F_6 ( & V_2 -> V_76 ) ;
F_28 ( & V_2 -> V_8 . V_75 ) ;
F_6 ( & V_2 -> V_73 -> V_74 ) ;
}
void F_69 ( struct V_1 * V_2 , bool V_207 )
{
enum V_3 V_158 ;
if ( V_2 -> V_20 -> V_16 . V_208 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_207 |= V_2 -> V_8 . V_16 . V_209 > 0 ;
V_207 |= V_2 -> V_8 . V_16 . V_210 > 0 ;
F_70 ( V_2 , ! V_207 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
if ( V_207 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_197 = true ;
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
V_158 = V_178 ;
V_2 -> V_8 . V_16 . V_161 = V_158 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_197 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_40 ( V_2 ) ;
}
}
void F_71 ( struct V_1 * V_2 , bool V_207 )
{
if ( V_207 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_200 = true ;
V_2 -> V_8 . V_16 . V_211 = V_212 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_200 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_40 ( V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_69 ) {
if ( V_2 -> V_8 . V_112 == V_213 )
V_2 -> V_8 . V_112 = V_214 ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_116 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_74 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_199 = V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_190 ;
V_2 -> V_8 . V_14 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_73 ( V_2 ) ;
else
F_72 ( V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_215 ) &&
V_2 -> V_216 ) {
if ( V_2 -> V_8 . V_217 )
F_77 ( V_2 , V_2 -> V_8 . V_217 ,
V_218 ) ;
if ( V_2 -> V_8 . V_219 )
F_77 ( V_2 , V_2 -> V_8 . V_219 ,
V_220 ) ;
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
V_2 -> V_8 . V_221 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_64 [ 0 ] . V_96 . V_96 ;
V_2 -> V_8 . V_222 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_64 [ 0 ] . V_96 . V_223 ;
}
if ( V_2 -> V_8 . V_12 == V_69
&& V_2 -> V_8 . V_112 == V_214 ) {
V_2 -> V_8 . V_112 = V_213 ;
F_78 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_224 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
int V_126 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_199 = V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_190 ;
F_80 ( V_2 ) ;
V_126 = F_81 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_126 )
goto V_225;
V_2 -> V_8 . V_14 = true ;
return;
V_225:
F_82 ( L_30 ) ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_215 ) &&
V_2 -> V_216 ) {
if ( V_2 -> V_8 . V_217 )
F_77 ( V_2 , V_2 -> V_8 . V_217 ,
V_218 ) ;
if ( V_2 -> V_8 . V_219 )
F_77 ( V_2 , V_2 -> V_8 . V_219 ,
V_220 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
}
void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_79 ( V_2 ) ;
else
F_76 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_126 ;
V_2 -> V_8 . V_23 = V_25 ;
V_2 -> V_8 . V_112 = V_115 ;
V_2 -> V_8 . V_84 = V_85 ;
V_2 -> V_8 . V_226 = true ;
V_2 -> V_8 . V_227 = true ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_71 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_145 = V_228 ;
if ( V_2 -> V_229 ) {
if ( V_2 -> V_230 )
F_85 ( V_2 ) ;
else
F_86 ( V_2 ) ;
F_33 ( V_2 ) ;
F_87 ( V_2 ) ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_215 ) &&
V_2 -> V_216 ) {
if ( V_2 -> V_8 . V_217 )
F_77 ( V_2 , V_2 -> V_8 . V_217 ,
V_218 ) ;
if ( V_2 -> V_8 . V_219 )
F_77 ( V_2 , V_2 -> V_8 . V_219 ,
V_220 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
}
V_126 = F_52 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_88 ( & V_2 -> V_8 . V_116 , V_231 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_126 = F_89 ( V_2 -> V_98 , & V_232 ) ;
if ( V_126 )
F_82 ( L_31 ) ;
V_126 = F_89 ( V_2 -> V_98 , & V_233 ) ;
if ( V_126 )
F_82 ( L_32 ) ;
if ( F_90 ( V_2 ) ) {
F_82 ( L_33 ) ;
}
F_91 ( L_34 ) ;
}
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_170 ; V_6 ++ ) {
F_64 ( L_35 , V_6 ) ;
F_65 ( V_2 , & V_2 -> V_8 . V_16 . V_163 [ V_6 ] ) ;
}
}
static int F_93 ( struct V_1 * V_2 )
{
int V_126 ;
V_2 -> V_8 . V_16 . V_161 = V_119 ;
V_2 -> V_8 . V_16 . V_117 = V_119 ;
V_2 -> V_8 . V_16 . V_123 = V_124 ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_71 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_145 = V_228 ;
if ( V_2 -> V_229 && V_2 -> V_230 )
F_85 ( V_2 ) ;
else
return - V_110 ;
V_126 = F_52 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_94 ( & V_2 -> V_8 . V_16 . V_134 . V_157 , F_59 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_95 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_199 = V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_190 ;
if ( V_205 == 1 )
F_92 ( V_2 ) ;
F_80 ( V_2 ) ;
V_126 = F_81 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_126 )
goto V_234;
V_2 -> V_8 . V_14 = true ;
V_126 = F_89 ( V_2 -> V_98 , & V_235 ) ;
if ( V_126 )
F_82 ( L_36 ) ;
V_126 = F_89 ( V_2 -> V_98 , & V_236 ) ;
if ( V_126 )
F_82 ( L_36 ) ;
V_126 = F_89 ( V_2 -> V_98 , & V_232 ) ;
if ( V_126 )
F_82 ( L_31 ) ;
V_126 = F_89 ( V_2 -> V_98 , & V_233 ) ;
if ( V_126 )
F_82 ( L_32 ) ;
if ( F_90 ( V_2 ) ) {
F_82 ( L_37 ) ;
}
F_91 ( L_38 ) ;
return 0 ;
V_234:
V_2 -> V_8 . V_14 = false ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_215 ) &&
V_2 -> V_216 ) {
if ( V_2 -> V_8 . V_217 )
F_77 ( V_2 , V_2 -> V_8 . V_217 ,
V_218 ) ;
if ( V_2 -> V_8 . V_219 )
F_77 ( V_2 , V_2 -> V_8 . V_219 ,
V_220 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
F_82 ( L_39 ) ;
return V_126 ;
}
int F_96 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 ) {
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_66 :
case V_245 :
case V_246 :
case V_215 :
if ( ! V_2 -> V_247 )
V_2 -> V_8 . V_12 = V_22 ;
else if ( ( V_2 -> V_18 >= V_244 ) &&
( ! ( V_2 -> V_90 & V_92 ) ) &&
( ! V_2 -> V_248 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_205 == 1 )
V_2 -> V_8 . V_12 = V_13 ;
else
V_2 -> V_8 . V_12 = V_22 ;
break;
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_19 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
if ( ! V_2 -> V_247 )
V_2 -> V_8 . V_12 = V_22 ;
else if ( ( V_2 -> V_18 >= V_244 ) &&
( ! ( V_2 -> V_90 & V_92 ) ) &&
( ! V_2 -> V_248 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_205 == 0 )
V_2 -> V_8 . V_12 = V_22 ;
else
V_2 -> V_8 . V_12 = V_13 ;
break;
default:
V_2 -> V_8 . V_12 = V_22 ;
break;
}
if ( V_2 -> V_8 . V_12 == V_13 )
return F_93 ( V_2 ) ;
else
return F_84 ( V_2 ) ;
}
int F_97 ( struct V_1 * V_2 )
{
int V_126 = 0 ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_126 = F_98 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
return V_126 ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_22 ) {
V_2 -> V_8 . V_23 = V_25 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_69 ) {
V_2 -> V_8 . V_112 = V_115 ;
V_2 -> V_8 . V_84 = V_114 ;
F_8 ( V_2 ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_116 ) ;
F_100 ( V_2 -> V_98 , & V_232 ) ;
F_100 ( V_2 -> V_98 , & V_233 ) ;
}
F_57 ( V_2 ) ;
if ( V_2 -> V_8 . V_10 )
F_101 ( V_2 -> V_8 . V_10 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_74 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_100 ( V_2 -> V_98 , & V_235 ) ;
F_100 ( V_2 -> V_98 , & V_236 ) ;
F_100 ( V_2 -> V_98 , & V_232 ) ;
F_100 ( V_2 -> V_98 , & V_233 ) ;
}
F_103 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> V_8 . V_10 )
F_101 ( V_2 -> V_8 . V_10 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_102 ( V_2 ) ;
else
F_99 ( V_2 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_102 * V_73 = V_2 -> V_73 ;
struct V_270 * V_271 ;
struct V_272 * V_272 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_54 = 0 ;
V_2 -> V_8 . V_28 = 0 ;
if ( V_2 -> V_82 && V_2 -> V_273 . V_274 ) {
F_106 (crtc,
&ddev->mode_config.crtc_list, head) {
V_272 = F_107 ( V_271 ) ;
if ( V_272 -> V_275 ) {
V_2 -> V_8 . V_54 |= ( 1 << V_272 -> V_276 ) ;
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
if ( V_2 -> V_8 . V_112 == V_213 ) {
F_108 ( & V_2 -> V_8 . V_116 ) ;
V_2 -> V_8 . V_112 = V_113 ;
V_2 -> V_8 . V_84 = V_114 ;
F_109 ( V_2 ) ;
F_8 ( V_2 ) ;
F_23 ( L_40 ) ;
}
} else if ( V_2 -> V_8 . V_28 == 1 ) {
if ( V_2 -> V_8 . V_112 == V_277 ) {
V_2 -> V_8 . V_112 = V_213 ;
V_2 -> V_8 . V_84 = V_278 ;
F_109 ( V_2 ) ;
F_8 ( V_2 ) ;
F_78 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_224 ) ) ;
} else if ( V_2 -> V_8 . V_112 == V_113 ) {
V_2 -> V_8 . V_112 = V_213 ;
F_78 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_224 ) ) ;
F_23 ( L_41 ) ;
}
} else {
if ( V_2 -> V_8 . V_112 != V_277 ) {
F_108 ( & V_2 -> V_8 . V_116 ) ;
V_2 -> V_8 . V_112 = V_277 ;
V_2 -> V_8 . V_84 = V_279 ;
F_109 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_102 * V_73 = V_2 -> V_73 ;
struct V_270 * V_271 ;
struct V_272 * V_272 ;
if ( ! V_2 -> V_8 . V_14 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_202 = 0 ;
V_2 -> V_8 . V_16 . V_166 = 0 ;
if ( V_2 -> V_82 && V_2 -> V_273 . V_274 ) {
F_106 (crtc,
&ddev->mode_config.crtc_list, head) {
V_272 = F_107 ( V_271 ) ;
if ( V_271 -> V_275 ) {
V_2 -> V_8 . V_16 . V_202 |= ( 1 << V_272 -> V_276 ) ;
V_2 -> V_8 . V_16 . V_166 ++ ;
}
}
}
if ( F_4 () > 0 )
V_2 -> V_8 . V_16 . V_17 = true ;
else
V_2 -> V_8 . V_16 . V_17 = false ;
F_62 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_110 ( V_2 ) ;
else
F_105 ( V_2 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
int V_271 , V_280 , V_281 , V_282 ;
bool V_283 = true ;
for ( V_271 = 0 ; ( V_271 < V_2 -> V_82 ) && V_283 ; V_271 ++ ) {
if ( V_2 -> V_8 . V_54 & ( 1 << V_271 ) ) {
V_282 = F_111 ( V_2 -> V_73 , V_271 , 0 , & V_280 , & V_281 , NULL , NULL ) ;
if ( ( V_282 & V_284 ) &&
! ( V_282 & V_285 ) )
V_283 = false ;
}
}
return V_283 ;
}
static bool F_21 ( struct V_1 * V_2 , bool V_286 )
{
T_1 V_287 = 0 ;
bool V_283 = F_18 ( V_2 ) ;
if ( V_283 == false )
F_23 ( L_42 , V_287 ,
V_286 ? L_43 : L_44 ) ;
return V_283 ;
}
static void V_231 ( struct V_156 * V_157 )
{
struct V_1 * V_2 ;
int V_288 ;
V_2 = F_51 ( V_157 , struct V_1 ,
V_8 . V_116 . V_157 ) ;
V_288 = F_112 ( & V_2 -> V_289 . V_290 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_112 == V_213 ) {
int V_291 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_77 ; ++ V_6 ) {
struct V_78 * V_79 = & V_2 -> V_79 [ V_6 ] ;
if ( V_79 -> V_80 ) {
V_291 += F_113 ( V_2 , V_6 ) ;
if ( V_291 >= 3 )
break;
}
}
if ( V_291 >= 3 ) {
if ( V_2 -> V_8 . V_84 == V_292 ) {
V_2 -> V_8 . V_84 = V_85 ;
} else if ( V_2 -> V_8 . V_84 == V_85 &&
V_2 -> V_8 . V_226 ) {
V_2 -> V_8 . V_84 =
V_278 ;
V_2 -> V_8 . V_293 = V_294 +
F_15 ( V_295 ) ;
}
} else if ( V_291 == 0 ) {
if ( V_2 -> V_8 . V_84 == V_278 ) {
V_2 -> V_8 . V_84 = V_85 ;
} else if ( V_2 -> V_8 . V_84 == V_85 &&
V_2 -> V_8 . V_227 ) {
V_2 -> V_8 . V_84 =
V_292 ;
V_2 -> V_8 . V_293 = V_294 +
F_15 ( V_295 ) ;
}
}
if ( V_2 -> V_8 . V_84 != V_85 &&
V_294 > V_2 -> V_8 . V_293 ) {
F_109 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_78 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_224 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_114 ( & V_2 -> V_289 . V_290 , V_288 ) ;
}
static int F_115 ( struct V_296 * V_297 , void * V_298 )
{
struct V_299 * V_300 = (struct V_299 * ) V_297 -> V_301 ;
struct V_102 * V_98 = V_300 -> V_302 -> V_98 ;
struct V_1 * V_2 = V_98 -> V_103 ;
struct V_102 * V_73 = V_2 -> V_73 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) ) {
F_116 ( V_297 , L_45 ) ;
} else if ( V_2 -> V_8 . V_14 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_20 -> V_16 . V_303 )
F_117 ( V_2 , V_297 ) ;
else
F_116 ( V_297 , L_46 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_116 ( V_297 , L_47 , V_2 -> V_8 . V_65 ) ;
if ( ( V_2 -> V_18 >= V_257 ) && ( V_2 -> V_90 & V_92 ) )
F_116 ( V_297 , L_48 , V_2 -> V_8 . V_68 ) ;
else
F_116 ( V_297 , L_48 , F_118 ( V_2 ) ) ;
F_116 ( V_297 , L_49 , V_2 -> V_8 . V_67 ) ;
if ( V_2 -> V_20 -> V_8 . V_304 )
F_116 ( V_297 , L_50 , F_119 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_221 )
F_116 ( V_297 , L_51 , V_2 -> V_8 . V_221 ) ;
if ( V_2 -> V_20 -> V_8 . V_305 )
F_116 ( V_297 , L_52 , F_120 ( V_2 ) ) ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
#if F_121 ( V_306 )
return F_122 ( V_2 , V_307 , F_123 ( V_307 ) ) ;
#else
return 0 ;
#endif
}
