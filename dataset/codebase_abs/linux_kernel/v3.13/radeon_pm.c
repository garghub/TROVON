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
if ( V_2 -> V_18 -> V_16 . V_19 )
F_5 ( V_2 , V_2 -> V_8 . V_16 . V_17 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else if ( V_2 -> V_8 . V_12 == V_20 ) {
if ( V_2 -> V_8 . V_21 == V_22 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_21 ) {
case V_23 :
V_2 -> V_8 . V_24 = V_25 ;
break;
case V_22 :
if ( F_4 () > 0 ) {
if ( V_2 -> V_8 . V_26 > 1 )
V_2 -> V_8 . V_24 = V_27 ;
else
V_2 -> V_8 . V_24 = V_28 ;
} else {
if ( V_2 -> V_8 . V_26 > 1 )
V_2 -> V_8 . V_24 = V_29 ;
else
V_2 -> V_8 . V_24 = V_30 ;
}
break;
case V_31 :
if ( V_2 -> V_8 . V_26 > 1 )
V_2 -> V_8 . V_24 = V_32 ;
else
V_2 -> V_8 . V_24 = V_33 ;
break;
case V_34 :
if ( V_2 -> V_8 . V_26 > 1 )
V_2 -> V_8 . V_24 = V_29 ;
else
V_2 -> V_8 . V_24 = V_30 ;
break;
case V_35 :
if ( V_2 -> V_8 . V_26 > 1 )
V_2 -> V_8 . V_24 = V_27 ;
else
V_2 -> V_8 . V_24 = V_28 ;
break;
}
if ( V_2 -> V_8 . V_26 == 0 ) {
V_2 -> V_8 . V_36 =
V_2 -> V_8 . V_37 [ V_2 -> V_8 . V_24 ] . V_38 ;
V_2 -> V_8 . V_39 =
V_2 -> V_8 . V_37 [ V_2 -> V_8 . V_24 ] . V_40 ;
} else {
V_2 -> V_8 . V_36 =
V_2 -> V_8 . V_37 [ V_2 -> V_8 . V_24 ] . V_41 ;
V_2 -> V_8 . V_39 =
V_2 -> V_8 . V_37 [ V_2 -> V_8 . V_24 ] . V_42 ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_43 * V_44 , * V_45 ;
if ( F_10 ( & V_2 -> V_46 . V_47 ) )
return;
F_11 (bo, n, &rdev->gem.objects, list) {
if ( V_44 -> V_48 . V_49 . V_50 == V_51 )
F_12 ( & V_44 -> V_48 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_52 ) {
V_2 -> V_8 . V_53 = false ;
F_14 (
V_2 -> V_54 . V_55 , V_2 -> V_8 . V_53 ,
F_15 ( V_56 ) ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_57 , V_58 ;
bool V_59 = false ;
if ( ( V_2 -> V_8 . V_39 == V_2 -> V_8 . V_60 ) &&
( V_2 -> V_8 . V_36 == V_2 -> V_8 . V_61 ) )
return;
if ( F_17 ( V_2 ) ) {
V_57 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_36 ] .
V_62 [ V_2 -> V_8 . V_39 ] . V_57 ;
if ( V_57 > V_2 -> V_8 . V_63 )
V_57 = V_2 -> V_8 . V_63 ;
if ( ( V_2 -> V_8 . V_12 == V_20 ) &&
( V_2 -> V_64 >= V_65 ) &&
V_2 -> V_8 . V_26 &&
( ( V_2 -> V_8 . V_24 == V_29 ) ||
( V_2 -> V_8 . V_24 == V_32 ) ) )
V_58 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_36 ] .
V_62 [ V_2 -> V_8 . V_37 [ V_27 ] . V_42 ] . V_58 ;
else
V_58 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_36 ] .
V_62 [ V_2 -> V_8 . V_39 ] . V_58 ;
if ( V_58 > V_2 -> V_8 . V_66 )
V_58 = V_2 -> V_8 . V_66 ;
if ( V_57 < V_2 -> V_8 . V_67 )
V_59 = true ;
F_13 ( V_2 ) ;
if ( V_2 -> V_8 . V_12 == V_68 ) {
if ( ! F_18 ( V_2 ) )
return;
}
F_19 ( V_2 ) ;
if ( ! V_59 )
F_20 ( V_2 ) ;
if ( V_57 != V_2 -> V_8 . V_67 ) {
F_21 ( V_2 , false ) ;
F_22 ( V_2 , V_57 ) ;
F_21 ( V_2 , true ) ;
V_2 -> V_8 . V_67 = V_57 ;
F_23 ( L_1 , V_57 ) ;
}
if ( V_2 -> V_18 -> V_8 . V_69 && ( V_58 != V_2 -> V_8 . V_70 ) ) {
F_21 ( V_2 , false ) ;
F_24 ( V_2 , V_58 ) ;
F_21 ( V_2 , true ) ;
V_2 -> V_8 . V_70 = V_58 ;
F_23 ( L_2 , V_58 ) ;
}
if ( V_59 )
F_20 ( V_2 ) ;
F_25 ( V_2 ) ;
V_2 -> V_8 . V_61 = V_2 -> V_8 . V_36 ;
V_2 -> V_8 . V_60 = V_2 -> V_8 . V_39 ;
} else
F_23 ( L_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_6 , V_71 ;
if ( ( V_2 -> V_8 . V_39 == V_2 -> V_8 . V_60 ) &&
( V_2 -> V_8 . V_36 == V_2 -> V_8 . V_61 ) )
return;
F_3 ( & V_2 -> V_72 -> V_73 ) ;
F_26 ( & V_2 -> V_8 . V_74 ) ;
F_3 ( & V_2 -> V_75 ) ;
for ( V_6 = 0 ; V_6 < V_76 ; V_6 ++ ) {
struct V_77 * V_78 = & V_2 -> V_78 [ V_6 ] ;
if ( ! V_78 -> V_79 ) {
continue;
}
V_71 = F_27 ( V_2 , V_6 ) ;
if ( V_71 ) {
F_6 ( & V_2 -> V_75 ) ;
F_28 ( & V_2 -> V_8 . V_74 ) ;
F_6 ( & V_2 -> V_72 -> V_73 ) ;
return;
}
}
F_9 ( V_2 ) ;
if ( V_2 -> V_54 . V_80 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_81 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_52 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_82 |= ( 1 << V_6 ) ;
F_29 ( V_2 -> V_72 , V_6 ) ;
}
}
}
F_16 ( V_2 ) ;
if ( V_2 -> V_54 . V_80 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_81 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_82 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_82 &= ~ ( 1 << V_6 ) ;
F_30 ( V_2 -> V_72 , V_6 ) ;
}
}
}
F_31 ( V_2 ) ;
if ( V_2 -> V_8 . V_26 )
F_32 ( V_2 ) ;
V_2 -> V_8 . V_83 = V_84 ;
F_6 ( & V_2 -> V_75 ) ;
F_28 ( & V_2 -> V_8 . V_74 ) ;
F_6 ( & V_2 -> V_72 -> V_73 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_6 , V_85 ;
struct V_86 * V_10 ;
struct V_87 * V_62 ;
F_23 ( L_4 , V_2 -> V_8 . V_9 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_9 ; V_6 ++ ) {
V_10 = & V_2 -> V_8 . V_10 [ V_6 ] ;
F_23 ( L_5 , V_6 ,
V_88 [ V_10 -> type ] ) ;
if ( V_6 == V_2 -> V_8 . V_11 )
F_23 ( L_6 ) ;
if ( ( V_2 -> V_89 & V_90 ) && ! ( V_2 -> V_89 & V_91 ) )
F_23 ( L_7 , V_10 -> V_92 ) ;
if ( V_10 -> V_89 & V_93 )
F_23 ( L_8 ) ;
F_23 ( L_9 , V_10 -> V_94 ) ;
for ( V_85 = 0 ; V_85 < V_10 -> V_94 ; V_85 ++ ) {
V_62 = & ( V_10 -> V_62 [ V_85 ] ) ;
if ( V_2 -> V_89 & V_91 )
F_23 ( L_10 ,
V_85 ,
V_62 -> V_57 * 10 ) ;
else
F_23 ( L_11 ,
V_85 ,
V_62 -> V_57 * 10 ,
V_62 -> V_58 * 10 ,
V_62 -> V_95 . V_95 ) ;
}
}
}
static T_2 F_34 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
int V_103 = V_2 -> V_8 . V_21 ;
return snprintf ( V_100 , V_104 , L_12 ,
( V_103 == V_22 ) ? L_13 :
( V_103 == V_31 ) ? L_14 :
( V_103 == V_34 ) ? L_15 :
( V_103 == V_35 ) ? L_16 : L_17 ) ;
}
static T_2 F_36 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_20 ) {
if ( strncmp ( L_17 , V_100 , strlen ( L_17 ) ) == 0 )
V_2 -> V_8 . V_21 = V_23 ;
else if ( strncmp ( L_13 , V_100 , strlen ( L_13 ) ) == 0 )
V_2 -> V_8 . V_21 = V_22 ;
else if ( strncmp ( L_14 , V_100 , strlen ( L_14 ) ) == 0 )
V_2 -> V_8 . V_21 = V_31 ;
else if ( strncmp ( L_15 , V_100 , strlen ( L_15 ) ) == 0 )
V_2 -> V_8 . V_21 = V_34 ;
else if ( strncmp ( L_16 , V_100 , strlen ( L_16 ) ) == 0 )
V_2 -> V_8 . V_21 = V_35 ;
else {
V_105 = - V_106 ;
goto V_107;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else
V_105 = - V_106 ;
V_107:
F_6 ( & V_2 -> V_8 . V_15 ) ;
return V_105 ;
}
static T_2 F_37 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
int V_8 = V_2 -> V_8 . V_12 ;
return snprintf ( V_100 , V_104 , L_12 ,
( V_8 == V_68 ) ? L_18 :
( V_8 == V_20 ) ? L_19 : L_20 ) ;
}
static T_2 F_38 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
V_105 = - V_106 ;
goto V_107;
}
if ( strncmp ( L_18 , V_100 , strlen ( L_18 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_12 = V_68 ;
V_2 -> V_8 . V_108 = V_109 ;
V_2 -> V_8 . V_83 = V_110 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else if ( strncmp ( L_19 , V_100 , strlen ( L_19 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_108 = V_111 ;
V_2 -> V_8 . V_83 = V_84 ;
V_2 -> V_8 . V_12 = V_20 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_112 ) ;
} else {
V_105 = - V_106 ;
goto V_107;
}
F_40 ( V_2 ) ;
V_107:
return V_105 ;
}
static T_2 F_41 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
enum V_3 V_8 = V_2 -> V_8 . V_16 . V_113 ;
return snprintf ( V_100 , V_104 , L_12 ,
( V_8 == V_114 ) ? L_21 :
( V_8 == V_115 ) ? L_22 : L_23 ) ;
}
static T_2 F_42 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_21 , V_100 , strlen ( L_21 ) ) == 0 )
V_2 -> V_8 . V_16 . V_113 = V_114 ;
else if ( strncmp ( L_22 , V_100 , strlen ( L_22 ) ) == 0 )
V_2 -> V_8 . V_16 . V_113 = V_115 ;
else if ( strncmp ( L_23 , V_100 , strlen ( L_23 ) ) == 0 )
V_2 -> V_8 . V_16 . V_113 = V_116 ;
else {
F_6 ( & V_2 -> V_8 . V_15 ) ;
V_105 = - V_106 ;
goto V_107;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
V_107:
return V_105 ;
}
static T_2 F_43 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
enum V_117 V_118 = V_2 -> V_8 . V_16 . V_119 ;
return snprintf ( V_100 , V_104 , L_12 ,
( V_118 == V_120 ) ? L_13 :
( V_118 == V_121 ) ? L_14 : L_16 ) ;
}
static T_2 F_44 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
enum V_117 V_118 ;
int V_122 = 0 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_14 , V_100 , strlen ( L_14 ) ) == 0 ) {
V_118 = V_121 ;
} else if ( strncmp ( L_16 , V_100 , strlen ( L_16 ) ) == 0 ) {
V_118 = V_123 ;
} else if ( strncmp ( L_13 , V_100 , strlen ( L_13 ) ) == 0 ) {
V_118 = V_120 ;
} else {
V_105 = - V_106 ;
goto V_107;
}
if ( V_2 -> V_18 -> V_16 . V_124 ) {
if ( V_2 -> V_8 . V_16 . V_125 ) {
V_105 = - V_106 ;
goto V_107;
}
V_122 = F_45 ( V_2 , V_118 ) ;
if ( V_122 )
V_105 = - V_106 ;
}
V_107:
F_6 ( & V_2 -> V_8 . V_15 ) ;
return V_105 ;
}
static T_2 F_46 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
int V_126 ;
if ( V_2 -> V_18 -> V_8 . V_127 )
V_126 = F_47 ( V_2 ) ;
else
V_126 = 0 ;
return snprintf ( V_100 , V_104 , L_24 , V_126 ) ;
}
static T_2 F_48 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
int V_128 = F_49 ( V_99 ) -> V_129 ;
int V_126 ;
if ( V_128 )
V_126 = V_2 -> V_8 . V_16 . V_130 . V_131 ;
else
V_126 = V_2 -> V_8 . V_16 . V_130 . V_132 ;
return snprintf ( V_100 , V_104 , L_24 , V_126 ) ;
}
static T_4 F_50 ( struct V_133 * V_134 ,
struct V_135 * V_99 , int V_129 )
{
struct V_96 * V_97 = F_51 ( V_134 , struct V_96 , V_134 ) ;
struct V_1 * V_2 = F_35 ( V_97 ) ;
if ( V_2 -> V_8 . V_12 != V_13 &&
( V_99 == & V_136 . V_137 . V_99 ||
V_99 == & V_138 . V_137 . V_99 ) )
return 0 ;
return V_99 -> V_139 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_140 = 0 ;
struct V_96 * V_141 ;
switch ( V_2 -> V_8 . V_142 ) {
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
if ( V_2 -> V_18 -> V_8 . V_127 == NULL )
return V_140 ;
V_141 = F_53 ( V_2 -> V_97 ,
L_25 , V_2 ,
V_151 ) ;
if ( F_54 ( V_141 ) ) {
V_140 = F_55 ( V_141 ) ;
F_56 ( V_2 -> V_97 ,
L_26 , V_140 ) ;
}
break;
default:
break;
}
return V_140 ;
}
static void F_57 ( struct V_152 * V_153 )
{
struct V_1 * V_2 =
F_51 ( V_153 , struct V_1 ,
V_8 . V_16 . V_130 . V_153 ) ;
enum V_3 V_154 = V_155 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_18 -> V_8 . V_127 ) {
int V_126 = F_47 ( V_2 ) ;
if ( V_126 < V_2 -> V_8 . V_16 . V_130 . V_131 )
V_154 = V_2 -> V_8 . V_16 . V_113 ;
} else {
if ( V_2 -> V_8 . V_16 . V_130 . V_156 )
V_154 = V_2 -> V_8 . V_16 . V_113 ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_154 == V_155 )
V_2 -> V_8 . V_16 . V_125 = true ;
else
V_2 -> V_8 . V_16 . V_125 = false ;
V_2 -> V_8 . V_16 . V_157 = V_154 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static struct V_158 * F_58 ( struct V_1 * V_2 ,
enum V_3 V_154 )
{
int V_6 ;
struct V_158 * V_159 ;
T_1 V_160 ;
bool V_161 = ( V_2 -> V_8 . V_16 . V_162 < 2 ) ?
true : false ;
if ( V_161 && V_2 -> V_18 -> V_16 . V_163 ) {
if ( F_59 ( V_2 ) )
V_161 = false ;
}
if ( V_154 == V_116 )
V_154 = V_164 ;
if ( V_154 == V_115 )
V_154 = V_116 ;
V_165:
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_166 ; V_6 ++ ) {
V_159 = & V_2 -> V_8 . V_16 . V_159 [ V_6 ] ;
V_160 = V_159 -> V_167 & V_168 ;
switch ( V_154 ) {
case V_114 :
if ( V_160 == V_169 ) {
if ( V_159 -> V_170 & V_171 ) {
if ( V_161 )
return V_159 ;
} else
return V_159 ;
}
break;
case V_115 :
if ( V_160 == V_172 ) {
if ( V_159 -> V_170 & V_171 ) {
if ( V_161 )
return V_159 ;
} else
return V_159 ;
}
break;
case V_116 :
if ( V_160 == V_173 ) {
if ( V_159 -> V_170 & V_171 ) {
if ( V_161 )
return V_159 ;
} else
return V_159 ;
}
break;
case V_174 :
if ( V_2 -> V_8 . V_16 . V_175 )
return V_2 -> V_8 . V_16 . V_175 ;
else
break;
case V_176 :
if ( V_159 -> V_167 & V_177 )
return V_159 ;
break;
case V_178 :
if ( V_159 -> V_167 & V_179 )
return V_159 ;
break;
case V_180 :
if ( V_159 -> V_167 & V_181 )
return V_159 ;
break;
case V_182 :
if ( V_159 -> V_183 & V_184 )
return V_159 ;
break;
case V_185 :
return V_2 -> V_8 . V_16 . V_186 ;
case V_155 :
if ( V_159 -> V_167 & V_187 )
return V_159 ;
break;
case V_188 :
if ( V_159 -> V_167 & V_189 )
return V_159 ;
break;
case V_190 :
if ( V_159 -> V_183 & V_191 )
return V_159 ;
break;
case V_164 :
if ( V_159 -> V_167 & V_192 )
return V_159 ;
break;
default:
break;
}
}
switch ( V_154 ) {
case V_176 :
V_154 = V_178 ;
goto V_165;
case V_178 :
case V_180 :
case V_182 :
if ( V_2 -> V_8 . V_16 . V_175 ) {
return V_2 -> V_8 . V_16 . V_175 ;
} else {
V_154 = V_116 ;
goto V_165;
}
case V_155 :
V_154 = V_188 ;
goto V_165;
case V_188 :
V_154 = V_114 ;
goto V_165;
case V_114 :
case V_115 :
case V_164 :
V_154 = V_116 ;
goto V_165;
default:
break;
}
return NULL ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_158 * V_159 ;
enum V_3 V_154 ;
int V_122 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_8 . V_16 . V_113 != V_2 -> V_8 . V_16 . V_157 ) {
if ( ( ! V_2 -> V_8 . V_16 . V_125 ) &&
( ! V_2 -> V_8 . V_16 . V_193 ) )
V_2 -> V_8 . V_16 . V_157 = V_2 -> V_8 . V_16 . V_113 ;
}
V_154 = V_2 -> V_8 . V_16 . V_157 ;
V_159 = F_58 ( V_2 , V_154 ) ;
if ( V_159 )
V_2 -> V_8 . V_16 . V_194 = V_159 ;
else
return;
if ( V_2 -> V_8 . V_16 . V_195 == V_2 -> V_8 . V_16 . V_194 ) {
if ( ( V_2 -> V_64 < V_65 ) || ( V_2 -> V_89 & V_91 ) ) {
if ( V_2 -> V_8 . V_16 . V_196 != V_2 -> V_8 . V_16 . V_197 ) {
F_32 ( V_2 ) ;
F_61 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_197 = V_2 -> V_8 . V_16 . V_196 ;
V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_162 ;
}
return;
} else {
if ( V_2 -> V_8 . V_16 . V_196 ==
V_2 -> V_8 . V_16 . V_197 ) {
return;
} else {
if ( ( V_2 -> V_8 . V_16 . V_198 > 1 ) &&
( V_2 -> V_8 . V_16 . V_162 > 1 ) ) {
F_32 ( V_2 ) ;
F_61 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_197 = V_2 -> V_8 . V_16 . V_196 ;
V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_162 ;
return;
}
}
}
}
if ( V_199 == 1 ) {
F_62 ( L_27 ) ;
F_63 ( V_2 , V_2 -> V_8 . V_16 . V_195 ) ;
F_62 ( L_28 ) ;
F_63 ( V_2 , V_2 -> V_8 . V_16 . V_194 ) ;
}
F_3 ( & V_2 -> V_72 -> V_73 ) ;
F_26 ( & V_2 -> V_8 . V_74 ) ;
F_3 ( & V_2 -> V_75 ) ;
V_122 = F_64 ( V_2 ) ;
if ( V_122 )
goto V_200;
F_32 ( V_2 ) ;
F_61 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_197 = V_2 -> V_8 . V_16 . V_196 ;
V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_162 ;
for ( V_6 = 0 ; V_6 < V_76 ; V_6 ++ ) {
struct V_77 * V_78 = & V_2 -> V_78 [ V_6 ] ;
if ( V_78 -> V_79 )
F_27 ( V_2 , V_6 ) ;
}
F_65 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_195 = V_2 -> V_8 . V_16 . V_194 ;
F_66 ( V_2 ) ;
if ( V_2 -> V_18 -> V_16 . V_124 ) {
if ( V_2 -> V_8 . V_16 . V_125 ) {
enum V_117 V_118 = V_2 -> V_8 . V_16 . V_119 ;
F_45 ( V_2 , V_121 ) ;
V_2 -> V_8 . V_16 . V_119 = V_118 ;
} else {
F_45 ( V_2 , V_2 -> V_8 . V_16 . V_119 ) ;
}
}
V_200:
F_6 ( & V_2 -> V_75 ) ;
F_28 ( & V_2 -> V_8 . V_74 ) ;
F_6 ( & V_2 -> V_72 -> V_73 ) ;
}
void F_67 ( struct V_1 * V_2 , bool V_201 )
{
enum V_3 V_154 ;
if ( V_2 -> V_18 -> V_16 . V_202 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_68 ( V_2 , ! V_201 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
if ( V_201 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_193 = true ;
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
V_154 = V_174 ;
V_2 -> V_8 . V_16 . V_157 = V_154 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_193 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_40 ( V_2 ) ;
}
}
static void F_69 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_68 ) {
if ( V_2 -> V_8 . V_108 == V_203 )
V_2 -> V_8 . V_108 = V_204 ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_112 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_71 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_195 = V_2 -> V_8 . V_16 . V_194 = V_2 -> V_8 . V_16 . V_186 ;
V_2 -> V_8 . V_14 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_70 ( V_2 ) ;
else
F_69 ( V_2 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_64 >= V_65 ) &&
( V_2 -> V_64 <= V_205 ) &&
V_2 -> V_206 ) {
if ( V_2 -> V_8 . V_207 )
F_74 ( V_2 , V_2 -> V_8 . V_207 ,
V_208 ) ;
if ( V_2 -> V_8 . V_209 )
F_74 ( V_2 , V_2 -> V_8 . V_209 ,
V_210 ) ;
if ( V_2 -> V_8 . V_63 )
F_22 ( V_2 , V_2 -> V_8 . V_63 ) ;
if ( V_2 -> V_8 . V_66 )
F_24 ( V_2 , V_2 -> V_8 . V_66 ) ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_61 = V_2 -> V_8 . V_11 ;
V_2 -> V_8 . V_60 = 0 ;
V_2 -> V_8 . V_67 = V_2 -> V_8 . V_63 ;
V_2 -> V_8 . V_70 = V_2 -> V_8 . V_66 ;
V_2 -> V_8 . V_211 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_62 [ 0 ] . V_95 . V_95 ;
V_2 -> V_8 . V_212 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_62 [ 0 ] . V_95 . V_213 ;
if ( V_2 -> V_8 . V_12 == V_68
&& V_2 -> V_8 . V_108 == V_204 ) {
V_2 -> V_8 . V_108 = V_203 ;
F_75 ( & V_2 -> V_8 . V_112 ,
F_15 ( V_214 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
int V_122 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_195 = V_2 -> V_8 . V_16 . V_194 = V_2 -> V_8 . V_16 . V_186 ;
F_77 ( V_2 ) ;
V_122 = F_78 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_122 ) {
F_79 ( L_29 ) ;
if ( ( V_2 -> V_64 >= V_65 ) &&
( V_2 -> V_64 <= V_205 ) &&
V_2 -> V_206 ) {
if ( V_2 -> V_8 . V_207 )
F_74 ( V_2 , V_2 -> V_8 . V_207 ,
V_208 ) ;
if ( V_2 -> V_8 . V_209 )
F_74 ( V_2 , V_2 -> V_8 . V_209 ,
V_210 ) ;
if ( V_2 -> V_8 . V_63 )
F_22 ( V_2 , V_2 -> V_8 . V_63 ) ;
if ( V_2 -> V_8 . V_66 )
F_24 ( V_2 , V_2 -> V_8 . V_66 ) ;
}
} else {
V_2 -> V_8 . V_14 = true ;
F_40 ( V_2 ) ;
}
}
void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_76 ( V_2 ) ;
else
F_73 ( V_2 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_122 ;
V_2 -> V_8 . V_21 = V_23 ;
V_2 -> V_8 . V_108 = V_111 ;
V_2 -> V_8 . V_83 = V_84 ;
V_2 -> V_8 . V_215 = true ;
V_2 -> V_8 . V_216 = true ;
V_2 -> V_8 . V_63 = V_2 -> clock . V_63 ;
V_2 -> V_8 . V_66 = V_2 -> clock . V_66 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_63 ;
V_2 -> V_8 . V_70 = V_2 -> clock . V_66 ;
V_2 -> V_8 . V_142 = V_217 ;
if ( V_2 -> V_218 ) {
if ( V_2 -> V_219 )
F_82 ( V_2 ) ;
else
F_83 ( V_2 ) ;
F_33 ( V_2 ) ;
F_84 ( V_2 ) ;
if ( ( V_2 -> V_64 >= V_65 ) &&
( V_2 -> V_64 <= V_205 ) &&
V_2 -> V_206 ) {
if ( V_2 -> V_8 . V_207 )
F_74 ( V_2 , V_2 -> V_8 . V_207 ,
V_208 ) ;
if ( V_2 -> V_8 . V_209 )
F_74 ( V_2 , V_2 -> V_8 . V_209 ,
V_210 ) ;
if ( V_2 -> V_8 . V_63 )
F_22 ( V_2 , V_2 -> V_8 . V_63 ) ;
if ( V_2 -> V_8 . V_66 )
F_24 ( V_2 , V_2 -> V_8 . V_66 ) ;
}
}
V_122 = F_52 ( V_2 ) ;
if ( V_122 )
return V_122 ;
F_85 ( & V_2 -> V_8 . V_112 , V_220 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_122 = F_86 ( V_2 -> V_97 , & V_221 ) ;
if ( V_122 )
F_79 ( L_30 ) ;
V_122 = F_86 ( V_2 -> V_97 , & V_222 ) ;
if ( V_122 )
F_79 ( L_31 ) ;
if ( F_87 ( V_2 ) ) {
F_79 ( L_32 ) ;
}
F_88 ( L_33 ) ;
}
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_166 ; V_6 ++ ) {
F_62 ( L_34 , V_6 ) ;
F_63 ( V_2 , & V_2 -> V_8 . V_16 . V_159 [ V_6 ] ) ;
}
}
static int F_90 ( struct V_1 * V_2 )
{
int V_122 ;
V_2 -> V_8 . V_16 . V_157 = V_115 ;
V_2 -> V_8 . V_16 . V_113 = V_115 ;
V_2 -> V_8 . V_16 . V_119 = V_120 ;
V_2 -> V_8 . V_63 = V_2 -> clock . V_63 ;
V_2 -> V_8 . V_66 = V_2 -> clock . V_66 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_63 ;
V_2 -> V_8 . V_70 = V_2 -> clock . V_66 ;
V_2 -> V_8 . V_142 = V_217 ;
if ( V_2 -> V_218 && V_2 -> V_219 )
F_82 ( V_2 ) ;
else
return - V_106 ;
V_122 = F_52 ( V_2 ) ;
if ( V_122 )
return V_122 ;
F_91 ( & V_2 -> V_8 . V_16 . V_130 . V_153 , F_57 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_92 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_195 = V_2 -> V_8 . V_16 . V_194 = V_2 -> V_8 . V_16 . V_186 ;
if ( V_199 == 1 )
F_89 ( V_2 ) ;
F_77 ( V_2 ) ;
V_122 = F_78 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_122 ) {
V_2 -> V_8 . V_14 = false ;
if ( ( V_2 -> V_64 >= V_65 ) &&
( V_2 -> V_64 <= V_205 ) &&
V_2 -> V_206 ) {
if ( V_2 -> V_8 . V_207 )
F_74 ( V_2 , V_2 -> V_8 . V_207 ,
V_208 ) ;
if ( V_2 -> V_8 . V_209 )
F_74 ( V_2 , V_2 -> V_8 . V_209 ,
V_210 ) ;
if ( V_2 -> V_8 . V_63 )
F_22 ( V_2 , V_2 -> V_8 . V_63 ) ;
if ( V_2 -> V_8 . V_66 )
F_24 ( V_2 , V_2 -> V_8 . V_66 ) ;
}
F_79 ( L_35 ) ;
return V_122 ;
}
V_2 -> V_8 . V_14 = true ;
F_40 ( V_2 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_122 = F_86 ( V_2 -> V_97 , & V_223 ) ;
if ( V_122 )
F_79 ( L_36 ) ;
V_122 = F_86 ( V_2 -> V_97 , & V_224 ) ;
if ( V_122 )
F_79 ( L_36 ) ;
V_122 = F_86 ( V_2 -> V_97 , & V_221 ) ;
if ( V_122 )
F_79 ( L_30 ) ;
V_122 = F_86 ( V_2 -> V_97 , & V_222 ) ;
if ( V_122 )
F_79 ( L_31 ) ;
if ( F_87 ( V_2 ) ) {
F_79 ( L_37 ) ;
}
F_88 ( L_38 ) ;
}
return 0 ;
}
int F_93 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_64 ) {
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_205 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
if ( ! V_2 -> V_236 )
V_2 -> V_8 . V_12 = V_20 ;
else if ( ( V_2 -> V_64 >= V_237 ) &&
( ! ( V_2 -> V_89 & V_91 ) ) &&
( ! V_2 -> V_238 ) )
V_2 -> V_8 . V_12 = V_20 ;
else if ( V_199 == 1 )
V_2 -> V_8 . V_12 = V_13 ;
else
V_2 -> V_8 . V_12 = V_20 ;
break;
case V_237 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_65 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
if ( ! V_2 -> V_236 )
V_2 -> V_8 . V_12 = V_20 ;
else if ( ( V_2 -> V_64 >= V_237 ) &&
( ! ( V_2 -> V_89 & V_91 ) ) &&
( ! V_2 -> V_238 ) )
V_2 -> V_8 . V_12 = V_20 ;
else if ( V_199 == 0 )
V_2 -> V_8 . V_12 = V_20 ;
else
V_2 -> V_8 . V_12 = V_13 ;
break;
default:
V_2 -> V_8 . V_12 = V_20 ;
break;
}
if ( V_2 -> V_8 . V_12 == V_13 )
return F_90 ( V_2 ) ;
else
return F_81 ( V_2 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_20 ) {
V_2 -> V_8 . V_21 = V_23 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_68 ) {
V_2 -> V_8 . V_108 = V_111 ;
V_2 -> V_8 . V_83 = V_110 ;
F_8 ( V_2 ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_112 ) ;
F_95 ( V_2 -> V_97 , & V_221 ) ;
F_95 ( V_2 -> V_97 , & V_222 ) ;
}
if ( V_2 -> V_8 . V_10 )
F_96 ( V_2 -> V_8 . V_10 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_71 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_95 ( V_2 -> V_97 , & V_223 ) ;
F_95 ( V_2 -> V_97 , & V_224 ) ;
F_95 ( V_2 -> V_97 , & V_221 ) ;
F_95 ( V_2 -> V_97 , & V_222 ) ;
}
F_98 ( V_2 ) ;
if ( V_2 -> V_8 . V_10 )
F_96 ( V_2 -> V_8 . V_10 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_97 ( V_2 ) ;
else
F_94 ( V_2 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_101 * V_72 = V_2 -> V_72 ;
struct V_258 * V_259 ;
struct V_260 * V_260 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_52 = 0 ;
V_2 -> V_8 . V_26 = 0 ;
F_101 (crtc,
&ddev->mode_config.crtc_list, head) {
V_260 = F_102 ( V_259 ) ;
if ( V_260 -> V_261 ) {
V_2 -> V_8 . V_52 |= ( 1 << V_260 -> V_262 ) ;
V_2 -> V_8 . V_26 ++ ;
}
}
if ( V_2 -> V_8 . V_12 == V_20 ) {
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_68 ) {
if ( V_2 -> V_8 . V_108 != V_111 ) {
if ( V_2 -> V_8 . V_26 > 1 ) {
if ( V_2 -> V_8 . V_108 == V_203 ) {
F_103 ( & V_2 -> V_8 . V_112 ) ;
V_2 -> V_8 . V_108 = V_109 ;
V_2 -> V_8 . V_83 = V_110 ;
F_104 ( V_2 ) ;
F_8 ( V_2 ) ;
F_23 ( L_39 ) ;
}
} else if ( V_2 -> V_8 . V_26 == 1 ) {
if ( V_2 -> V_8 . V_108 == V_263 ) {
V_2 -> V_8 . V_108 = V_203 ;
V_2 -> V_8 . V_83 = V_264 ;
F_104 ( V_2 ) ;
F_8 ( V_2 ) ;
F_75 ( & V_2 -> V_8 . V_112 ,
F_15 ( V_214 ) ) ;
} else if ( V_2 -> V_8 . V_108 == V_109 ) {
V_2 -> V_8 . V_108 = V_203 ;
F_75 ( & V_2 -> V_8 . V_112 ,
F_15 ( V_214 ) ) ;
F_23 ( L_40 ) ;
}
} else {
if ( V_2 -> V_8 . V_108 != V_263 ) {
F_103 ( & V_2 -> V_8 . V_112 ) ;
V_2 -> V_8 . V_108 = V_263 ;
V_2 -> V_8 . V_83 = V_265 ;
F_104 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_101 * V_72 = V_2 -> V_72 ;
struct V_258 * V_259 ;
struct V_260 * V_260 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_196 = 0 ;
V_2 -> V_8 . V_16 . V_162 = 0 ;
F_101 (crtc,
&ddev->mode_config.crtc_list, head) {
V_260 = F_102 ( V_259 ) ;
if ( V_259 -> V_261 ) {
V_2 -> V_8 . V_16 . V_196 |= ( 1 << V_260 -> V_262 ) ;
V_2 -> V_8 . V_16 . V_162 ++ ;
}
}
if ( F_4 () > 0 )
V_2 -> V_8 . V_16 . V_17 = true ;
else
V_2 -> V_8 . V_16 . V_17 = false ;
F_60 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_105 ( V_2 ) ;
else
F_100 ( V_2 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
int V_259 , V_266 , V_267 , V_268 ;
bool V_269 = true ;
for ( V_259 = 0 ; ( V_259 < V_2 -> V_81 ) && V_269 ; V_259 ++ ) {
if ( V_2 -> V_8 . V_52 & ( 1 << V_259 ) ) {
V_268 = F_106 ( V_2 -> V_72 , V_259 , & V_266 , & V_267 , NULL , NULL ) ;
if ( ( V_268 & V_270 ) &&
! ( V_268 & V_271 ) )
V_269 = false ;
}
}
return V_269 ;
}
static bool F_21 ( struct V_1 * V_2 , bool V_272 )
{
T_1 V_273 = 0 ;
bool V_269 = F_18 ( V_2 ) ;
if ( V_269 == false )
F_23 ( L_41 , V_273 ,
V_272 ? L_42 : L_43 ) ;
return V_269 ;
}
static void V_220 ( struct V_152 * V_153 )
{
struct V_1 * V_2 ;
int V_274 ;
V_2 = F_51 ( V_153 , struct V_1 ,
V_8 . V_112 . V_153 ) ;
V_274 = F_107 ( & V_2 -> V_275 . V_276 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_108 == V_203 ) {
int V_277 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_76 ; ++ V_6 ) {
struct V_77 * V_78 = & V_2 -> V_78 [ V_6 ] ;
if ( V_78 -> V_79 ) {
V_277 += F_108 ( V_2 , V_6 ) ;
if ( V_277 >= 3 )
break;
}
}
if ( V_277 >= 3 ) {
if ( V_2 -> V_8 . V_83 == V_278 ) {
V_2 -> V_8 . V_83 = V_84 ;
} else if ( V_2 -> V_8 . V_83 == V_84 &&
V_2 -> V_8 . V_215 ) {
V_2 -> V_8 . V_83 =
V_264 ;
V_2 -> V_8 . V_279 = V_280 +
F_15 ( V_281 ) ;
}
} else if ( V_277 == 0 ) {
if ( V_2 -> V_8 . V_83 == V_264 ) {
V_2 -> V_8 . V_83 = V_84 ;
} else if ( V_2 -> V_8 . V_83 == V_84 &&
V_2 -> V_8 . V_216 ) {
V_2 -> V_8 . V_83 =
V_278 ;
V_2 -> V_8 . V_279 = V_280 +
F_15 ( V_281 ) ;
}
}
if ( V_2 -> V_8 . V_83 != V_84 &&
V_280 > V_2 -> V_8 . V_279 ) {
F_104 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_75 ( & V_2 -> V_8 . V_112 ,
F_15 ( V_214 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_109 ( & V_2 -> V_275 . V_276 , V_274 ) ;
}
static int F_110 ( struct V_282 * V_283 , void * V_284 )
{
struct V_285 * V_286 = (struct V_285 * ) V_283 -> V_287 ;
struct V_101 * V_97 = V_286 -> V_288 -> V_97 ;
struct V_1 * V_2 = V_97 -> V_102 ;
if ( V_2 -> V_8 . V_14 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_18 -> V_16 . V_289 )
F_111 ( V_2 , V_283 ) ;
else
F_112 ( V_283 , L_44 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_112 ( V_283 , L_45 , V_2 -> V_8 . V_63 ) ;
if ( ( V_2 -> V_64 >= V_247 ) && ( V_2 -> V_89 & V_91 ) )
F_112 ( V_283 , L_46 , V_2 -> V_8 . V_67 ) ;
else
F_112 ( V_283 , L_46 , F_113 ( V_2 ) ) ;
F_112 ( V_283 , L_47 , V_2 -> V_8 . V_66 ) ;
if ( V_2 -> V_18 -> V_8 . V_290 )
F_112 ( V_283 , L_48 , F_114 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_211 )
F_112 ( V_283 , L_49 , V_2 -> V_8 . V_211 ) ;
if ( V_2 -> V_18 -> V_8 . V_291 )
F_112 ( V_283 , L_50 , F_115 ( V_2 ) ) ;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
#if F_116 ( V_292 )
return F_117 ( V_2 , V_293 , F_118 ( V_293 ) ) ;
#else
return 0 ;
#endif
}
