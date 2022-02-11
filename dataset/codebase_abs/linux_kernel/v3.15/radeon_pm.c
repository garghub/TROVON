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
if ( ( V_2 -> V_89 & V_106 ) &&
( V_72 -> V_107 != V_108 ) )
return - V_109 ;
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
V_105 = - V_109 ;
goto V_110;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else
V_105 = - V_109 ;
V_110:
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
if ( ( V_2 -> V_89 & V_106 ) &&
( V_72 -> V_107 != V_108 ) ) {
V_105 = - V_109 ;
goto V_110;
}
if ( V_2 -> V_8 . V_12 == V_13 ) {
V_105 = - V_109 ;
goto V_110;
}
if ( strncmp ( L_18 , V_100 , strlen ( L_18 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_12 = V_68 ;
V_2 -> V_8 . V_111 = V_112 ;
V_2 -> V_8 . V_83 = V_113 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else if ( strncmp ( L_19 , V_100 , strlen ( L_19 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_111 = V_114 ;
V_2 -> V_8 . V_83 = V_84 ;
V_2 -> V_8 . V_12 = V_20 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_115 ) ;
} else {
V_105 = - V_109 ;
goto V_110;
}
F_40 ( V_2 ) ;
V_110:
return V_105 ;
}
static T_2 F_41 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
enum V_3 V_8 = V_2 -> V_8 . V_16 . V_116 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_72 -> V_107 != V_108 ) )
return snprintf ( V_100 , V_104 , L_21 ) ;
return snprintf ( V_100 , V_104 , L_12 ,
( V_8 == V_117 ) ? L_22 :
( V_8 == V_118 ) ? L_23 : L_24 ) ;
}
static T_2 F_42 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_72 -> V_107 != V_108 ) )
return - V_109 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_22 , V_100 , strlen ( L_22 ) ) == 0 )
V_2 -> V_8 . V_16 . V_116 = V_117 ;
else if ( strncmp ( L_23 , V_100 , strlen ( L_23 ) ) == 0 )
V_2 -> V_8 . V_16 . V_116 = V_118 ;
else if ( strncmp ( L_24 , V_100 , strlen ( L_24 ) ) == 0 )
V_2 -> V_8 . V_16 . V_116 = V_119 ;
else {
F_6 ( & V_2 -> V_8 . V_15 ) ;
V_105 = - V_109 ;
goto V_110;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
V_110:
return V_105 ;
}
static T_2 F_43 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
enum V_120 V_121 = V_2 -> V_8 . V_16 . V_122 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_72 -> V_107 != V_108 ) )
return snprintf ( V_100 , V_104 , L_21 ) ;
return snprintf ( V_100 , V_104 , L_12 ,
( V_121 == V_123 ) ? L_13 :
( V_121 == V_124 ) ? L_14 : L_16 ) ;
}
static T_2 F_44 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_72 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_72 -> V_102 ;
enum V_120 V_121 ;
int V_125 = 0 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_72 -> V_107 != V_108 ) )
return - V_109 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_14 , V_100 , strlen ( L_14 ) ) == 0 ) {
V_121 = V_124 ;
} else if ( strncmp ( L_16 , V_100 , strlen ( L_16 ) ) == 0 ) {
V_121 = V_126 ;
} else if ( strncmp ( L_13 , V_100 , strlen ( L_13 ) ) == 0 ) {
V_121 = V_123 ;
} else {
V_105 = - V_109 ;
goto V_110;
}
if ( V_2 -> V_18 -> V_16 . V_127 ) {
if ( V_2 -> V_8 . V_16 . V_128 ) {
V_105 = - V_109 ;
goto V_110;
}
V_125 = F_45 ( V_2 , V_121 ) ;
if ( V_125 )
V_105 = - V_109 ;
}
V_110:
F_6 ( & V_2 -> V_8 . V_15 ) ;
return V_105 ;
}
static T_2 F_46 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
struct V_101 * V_72 = V_2 -> V_72 ;
int V_129 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_72 -> V_107 != V_108 ) )
return - V_109 ;
if ( V_2 -> V_18 -> V_8 . V_130 )
V_129 = F_47 ( V_2 ) ;
else
V_129 = 0 ;
return snprintf ( V_100 , V_104 , L_25 , V_129 ) ;
}
static T_2 F_48 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
int V_131 = F_49 ( V_99 ) -> V_132 ;
int V_129 ;
if ( V_131 )
V_129 = V_2 -> V_8 . V_16 . V_133 . V_134 ;
else
V_129 = V_2 -> V_8 . V_16 . V_133 . V_135 ;
return snprintf ( V_100 , V_104 , L_25 , V_129 ) ;
}
static T_4 F_50 ( struct V_136 * V_137 ,
struct V_138 * V_99 , int V_132 )
{
struct V_96 * V_97 = F_51 ( V_137 , struct V_96 , V_137 ) ;
struct V_1 * V_2 = F_35 ( V_97 ) ;
if ( V_2 -> V_8 . V_12 != V_13 &&
( V_99 == & V_139 . V_140 . V_99 ||
V_99 == & V_141 . V_140 . V_99 ) )
return 0 ;
return V_99 -> V_142 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_143 = 0 ;
switch ( V_2 -> V_8 . V_144 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
if ( V_2 -> V_18 -> V_8 . V_130 == NULL )
return V_143 ;
V_2 -> V_8 . V_153 = F_53 ( V_2 -> V_97 ,
L_26 , V_2 ,
V_154 ) ;
if ( F_54 ( V_2 -> V_8 . V_153 ) ) {
V_143 = F_55 ( V_2 -> V_8 . V_153 ) ;
F_56 ( V_2 -> V_97 ,
L_27 , V_143 ) ;
}
break;
default:
break;
}
return V_143 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_153 )
F_58 ( V_2 -> V_8 . V_153 ) ;
}
static void F_59 ( struct V_155 * V_156 )
{
struct V_1 * V_2 =
F_51 ( V_156 , struct V_1 ,
V_8 . V_16 . V_133 . V_156 ) ;
enum V_3 V_157 = V_158 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_18 -> V_8 . V_130 ) {
int V_129 = F_47 ( V_2 ) ;
if ( V_129 < V_2 -> V_8 . V_16 . V_133 . V_134 )
V_157 = V_2 -> V_8 . V_16 . V_116 ;
} else {
if ( V_2 -> V_8 . V_16 . V_133 . V_159 )
V_157 = V_2 -> V_8 . V_16 . V_116 ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_157 == V_158 )
V_2 -> V_8 . V_16 . V_128 = true ;
else
V_2 -> V_8 . V_16 . V_128 = false ;
V_2 -> V_8 . V_16 . V_160 = V_157 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static struct V_161 * F_60 ( struct V_1 * V_2 ,
enum V_3 V_157 )
{
int V_6 ;
struct V_161 * V_162 ;
T_1 V_163 ;
bool V_164 = ( V_2 -> V_8 . V_16 . V_165 < 2 ) ?
true : false ;
if ( V_164 && V_2 -> V_18 -> V_16 . V_166 ) {
if ( F_61 ( V_2 ) )
V_164 = false ;
}
if ( V_157 == V_119 )
V_157 = V_167 ;
if ( V_157 == V_118 )
V_157 = V_119 ;
V_168:
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_169 ; V_6 ++ ) {
V_162 = & V_2 -> V_8 . V_16 . V_162 [ V_6 ] ;
V_163 = V_162 -> V_170 & V_171 ;
switch ( V_157 ) {
case V_117 :
if ( V_163 == V_172 ) {
if ( V_162 -> V_173 & V_174 ) {
if ( V_164 )
return V_162 ;
} else
return V_162 ;
}
break;
case V_118 :
if ( V_163 == V_175 ) {
if ( V_162 -> V_173 & V_174 ) {
if ( V_164 )
return V_162 ;
} else
return V_162 ;
}
break;
case V_119 :
if ( V_163 == V_176 ) {
if ( V_162 -> V_173 & V_174 ) {
if ( V_164 )
return V_162 ;
} else
return V_162 ;
}
break;
case V_177 :
if ( V_2 -> V_8 . V_16 . V_178 )
return V_2 -> V_8 . V_16 . V_178 ;
else
break;
case V_179 :
if ( V_162 -> V_170 & V_180 )
return V_162 ;
break;
case V_181 :
if ( V_162 -> V_170 & V_182 )
return V_162 ;
break;
case V_183 :
if ( V_162 -> V_170 & V_184 )
return V_162 ;
break;
case V_185 :
if ( V_162 -> V_186 & V_187 )
return V_162 ;
break;
case V_188 :
return V_2 -> V_8 . V_16 . V_189 ;
case V_158 :
if ( V_162 -> V_170 & V_190 )
return V_162 ;
break;
case V_191 :
if ( V_162 -> V_170 & V_192 )
return V_162 ;
break;
case V_193 :
if ( V_162 -> V_186 & V_194 )
return V_162 ;
break;
case V_167 :
if ( V_162 -> V_170 & V_195 )
return V_162 ;
break;
default:
break;
}
}
switch ( V_157 ) {
case V_179 :
V_157 = V_181 ;
goto V_168;
case V_181 :
case V_183 :
case V_185 :
if ( V_2 -> V_8 . V_16 . V_178 ) {
return V_2 -> V_8 . V_16 . V_178 ;
} else {
V_157 = V_119 ;
goto V_168;
}
case V_158 :
V_157 = V_191 ;
goto V_168;
case V_191 :
V_157 = V_117 ;
goto V_168;
case V_117 :
case V_118 :
case V_167 :
V_157 = V_119 ;
goto V_168;
default:
break;
}
return NULL ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_161 * V_162 ;
enum V_3 V_157 ;
int V_125 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_8 . V_16 . V_116 != V_2 -> V_8 . V_16 . V_160 ) {
if ( ( ! V_2 -> V_8 . V_16 . V_128 ) &&
( ! V_2 -> V_8 . V_16 . V_196 ) )
V_2 -> V_8 . V_16 . V_160 = V_2 -> V_8 . V_16 . V_116 ;
}
V_157 = V_2 -> V_8 . V_16 . V_160 ;
V_162 = F_60 ( V_2 , V_157 ) ;
if ( V_162 )
V_2 -> V_8 . V_16 . V_197 = V_162 ;
else
return;
if ( V_2 -> V_8 . V_16 . V_198 == V_2 -> V_8 . V_16 . V_197 ) {
if ( V_162 -> V_199 != V_2 -> V_8 . V_16 . V_199 )
goto V_200;
if ( ( V_2 -> V_64 < V_65 ) || ( V_2 -> V_89 & V_91 ) ) {
if ( V_2 -> V_8 . V_16 . V_201 != V_2 -> V_8 . V_16 . V_202 ) {
F_32 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_202 = V_2 -> V_8 . V_16 . V_201 ;
V_2 -> V_8 . V_16 . V_203 = V_2 -> V_8 . V_16 . V_165 ;
}
return;
} else {
if ( V_2 -> V_8 . V_16 . V_201 ==
V_2 -> V_8 . V_16 . V_202 ) {
return;
} else {
if ( ( V_2 -> V_8 . V_16 . V_203 > 1 ) &&
( V_2 -> V_8 . V_16 . V_165 > 1 ) ) {
F_32 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_202 = V_2 -> V_8 . V_16 . V_201 ;
V_2 -> V_8 . V_16 . V_203 = V_2 -> V_8 . V_16 . V_165 ;
return;
}
}
}
}
V_200:
if ( V_204 == 1 ) {
F_64 ( L_28 ) ;
F_65 ( V_2 , V_2 -> V_8 . V_16 . V_198 ) ;
F_64 ( L_29 ) ;
F_65 ( V_2 , V_2 -> V_8 . V_16 . V_197 ) ;
}
F_3 ( & V_2 -> V_72 -> V_73 ) ;
F_26 ( & V_2 -> V_8 . V_74 ) ;
F_3 ( & V_2 -> V_75 ) ;
V_162 -> V_199 = V_2 -> V_8 . V_16 . V_199 ;
V_125 = F_66 ( V_2 ) ;
if ( V_125 )
goto V_205;
F_32 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_202 = V_2 -> V_8 . V_16 . V_201 ;
V_2 -> V_8 . V_16 . V_203 = V_2 -> V_8 . V_16 . V_165 ;
for ( V_6 = 0 ; V_6 < V_76 ; V_6 ++ ) {
struct V_77 * V_78 = & V_2 -> V_78 [ V_6 ] ;
if ( V_78 -> V_79 )
F_27 ( V_2 , V_6 ) ;
}
F_67 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_197 ;
F_68 ( V_2 ) ;
if ( V_2 -> V_18 -> V_16 . V_127 ) {
if ( V_2 -> V_8 . V_16 . V_128 ) {
enum V_120 V_121 = V_2 -> V_8 . V_16 . V_122 ;
F_45 ( V_2 , V_124 ) ;
V_2 -> V_8 . V_16 . V_122 = V_121 ;
} else {
F_45 ( V_2 , V_2 -> V_8 . V_16 . V_122 ) ;
}
}
V_205:
F_6 ( & V_2 -> V_75 ) ;
F_28 ( & V_2 -> V_8 . V_74 ) ;
F_6 ( & V_2 -> V_72 -> V_73 ) ;
}
void F_69 ( struct V_1 * V_2 , bool V_206 )
{
enum V_3 V_157 ;
if ( V_2 -> V_18 -> V_16 . V_207 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_206 |= V_2 -> V_8 . V_16 . V_208 > 0 ;
V_206 |= V_2 -> V_8 . V_16 . V_209 > 0 ;
F_70 ( V_2 , ! V_206 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
if ( V_206 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_196 = true ;
if ( ( V_2 -> V_8 . V_16 . V_208 == 1 ) && ( V_2 -> V_8 . V_16 . V_209 == 0 ) )
V_157 = V_179 ;
else if ( ( V_2 -> V_8 . V_16 . V_208 == 2 ) && ( V_2 -> V_8 . V_16 . V_209 == 0 ) )
V_157 = V_181 ;
else if ( ( V_2 -> V_8 . V_16 . V_208 == 0 ) && ( V_2 -> V_8 . V_16 . V_209 == 1 ) )
V_157 = V_181 ;
else if ( ( V_2 -> V_8 . V_16 . V_208 == 0 ) && ( V_2 -> V_8 . V_16 . V_209 == 2 ) )
V_157 = V_183 ;
else
V_157 = V_177 ;
V_2 -> V_8 . V_16 . V_160 = V_157 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_196 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_40 ( V_2 ) ;
}
}
void F_71 ( struct V_1 * V_2 , bool V_206 )
{
if ( V_206 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_199 = true ;
V_2 -> V_8 . V_16 . V_210 = V_211 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_199 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_40 ( V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_68 ) {
if ( V_2 -> V_8 . V_111 == V_212 )
V_2 -> V_8 . V_111 = V_213 ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_115 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_74 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_197 = V_2 -> V_8 . V_16 . V_189 ;
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
if ( ( V_2 -> V_64 >= V_65 ) &&
( V_2 -> V_64 <= V_214 ) &&
V_2 -> V_215 ) {
if ( V_2 -> V_8 . V_216 )
F_77 ( V_2 , V_2 -> V_8 . V_216 ,
V_217 ) ;
if ( V_2 -> V_8 . V_218 )
F_77 ( V_2 , V_2 -> V_8 . V_218 ,
V_219 ) ;
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
if ( V_2 -> V_8 . V_10 ) {
V_2 -> V_8 . V_220 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_62 [ 0 ] . V_95 . V_95 ;
V_2 -> V_8 . V_221 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_62 [ 0 ] . V_95 . V_222 ;
}
if ( V_2 -> V_8 . V_12 == V_68
&& V_2 -> V_8 . V_111 == V_213 ) {
V_2 -> V_8 . V_111 = V_212 ;
F_78 ( & V_2 -> V_8 . V_115 ,
F_15 ( V_223 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
int V_125 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_197 = V_2 -> V_8 . V_16 . V_189 ;
F_80 ( V_2 ) ;
V_125 = F_81 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_125 )
goto V_224;
V_2 -> V_8 . V_14 = true ;
return;
V_224:
F_82 ( L_30 ) ;
if ( ( V_2 -> V_64 >= V_65 ) &&
( V_2 -> V_64 <= V_214 ) &&
V_2 -> V_215 ) {
if ( V_2 -> V_8 . V_216 )
F_77 ( V_2 , V_2 -> V_8 . V_216 ,
V_217 ) ;
if ( V_2 -> V_8 . V_218 )
F_77 ( V_2 , V_2 -> V_8 . V_218 ,
V_219 ) ;
if ( V_2 -> V_8 . V_63 )
F_22 ( V_2 , V_2 -> V_8 . V_63 ) ;
if ( V_2 -> V_8 . V_66 )
F_24 ( V_2 , V_2 -> V_8 . V_66 ) ;
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
int V_125 ;
V_2 -> V_8 . V_21 = V_23 ;
V_2 -> V_8 . V_111 = V_114 ;
V_2 -> V_8 . V_83 = V_84 ;
V_2 -> V_8 . V_225 = true ;
V_2 -> V_8 . V_226 = true ;
V_2 -> V_8 . V_63 = V_2 -> clock . V_63 ;
V_2 -> V_8 . V_66 = V_2 -> clock . V_66 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_63 ;
V_2 -> V_8 . V_70 = V_2 -> clock . V_66 ;
V_2 -> V_8 . V_144 = V_227 ;
if ( V_2 -> V_228 ) {
if ( V_2 -> V_229 )
F_85 ( V_2 ) ;
else
F_86 ( V_2 ) ;
F_33 ( V_2 ) ;
F_87 ( V_2 ) ;
if ( ( V_2 -> V_64 >= V_65 ) &&
( V_2 -> V_64 <= V_214 ) &&
V_2 -> V_215 ) {
if ( V_2 -> V_8 . V_216 )
F_77 ( V_2 , V_2 -> V_8 . V_216 ,
V_217 ) ;
if ( V_2 -> V_8 . V_218 )
F_77 ( V_2 , V_2 -> V_8 . V_218 ,
V_219 ) ;
if ( V_2 -> V_8 . V_63 )
F_22 ( V_2 , V_2 -> V_8 . V_63 ) ;
if ( V_2 -> V_8 . V_66 )
F_24 ( V_2 , V_2 -> V_8 . V_66 ) ;
}
}
V_125 = F_52 ( V_2 ) ;
if ( V_125 )
return V_125 ;
F_88 ( & V_2 -> V_8 . V_115 , V_230 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_125 = F_89 ( V_2 -> V_97 , & V_231 ) ;
if ( V_125 )
F_82 ( L_31 ) ;
V_125 = F_89 ( V_2 -> V_97 , & V_232 ) ;
if ( V_125 )
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
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_169 ; V_6 ++ ) {
F_64 ( L_35 , V_6 ) ;
F_65 ( V_2 , & V_2 -> V_8 . V_16 . V_162 [ V_6 ] ) ;
}
}
static int F_93 ( struct V_1 * V_2 )
{
int V_125 ;
V_2 -> V_8 . V_16 . V_160 = V_118 ;
V_2 -> V_8 . V_16 . V_116 = V_118 ;
V_2 -> V_8 . V_16 . V_122 = V_123 ;
V_2 -> V_8 . V_63 = V_2 -> clock . V_63 ;
V_2 -> V_8 . V_66 = V_2 -> clock . V_66 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_63 ;
V_2 -> V_8 . V_70 = V_2 -> clock . V_66 ;
V_2 -> V_8 . V_144 = V_227 ;
if ( V_2 -> V_228 && V_2 -> V_229 )
F_85 ( V_2 ) ;
else
return - V_109 ;
V_125 = F_52 ( V_2 ) ;
if ( V_125 )
return V_125 ;
F_94 ( & V_2 -> V_8 . V_16 . V_133 . V_156 , F_59 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_95 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_198 = V_2 -> V_8 . V_16 . V_197 = V_2 -> V_8 . V_16 . V_189 ;
if ( V_204 == 1 )
F_92 ( V_2 ) ;
F_80 ( V_2 ) ;
V_125 = F_81 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_125 )
goto V_233;
V_2 -> V_8 . V_14 = true ;
V_125 = F_89 ( V_2 -> V_97 , & V_234 ) ;
if ( V_125 )
F_82 ( L_36 ) ;
V_125 = F_89 ( V_2 -> V_97 , & V_235 ) ;
if ( V_125 )
F_82 ( L_36 ) ;
V_125 = F_89 ( V_2 -> V_97 , & V_231 ) ;
if ( V_125 )
F_82 ( L_31 ) ;
V_125 = F_89 ( V_2 -> V_97 , & V_232 ) ;
if ( V_125 )
F_82 ( L_32 ) ;
if ( F_90 ( V_2 ) ) {
F_82 ( L_37 ) ;
}
F_91 ( L_38 ) ;
return 0 ;
V_233:
V_2 -> V_8 . V_14 = false ;
if ( ( V_2 -> V_64 >= V_65 ) &&
( V_2 -> V_64 <= V_214 ) &&
V_2 -> V_215 ) {
if ( V_2 -> V_8 . V_216 )
F_77 ( V_2 , V_2 -> V_8 . V_216 ,
V_217 ) ;
if ( V_2 -> V_8 . V_218 )
F_77 ( V_2 , V_2 -> V_8 . V_218 ,
V_219 ) ;
if ( V_2 -> V_8 . V_63 )
F_22 ( V_2 , V_2 -> V_8 . V_63 ) ;
if ( V_2 -> V_8 . V_66 )
F_24 ( V_2 , V_2 -> V_8 . V_66 ) ;
}
F_82 ( L_39 ) ;
return V_125 ;
}
int F_96 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_64 ) {
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_65 :
case V_244 :
case V_245 :
case V_214 :
if ( ! V_2 -> V_246 )
V_2 -> V_8 . V_12 = V_20 ;
else if ( ( V_2 -> V_64 >= V_243 ) &&
( ! ( V_2 -> V_89 & V_91 ) ) &&
( ! V_2 -> V_247 ) )
V_2 -> V_8 . V_12 = V_20 ;
else if ( V_204 == 1 )
V_2 -> V_8 . V_12 = V_13 ;
else
V_2 -> V_8 . V_12 = V_20 ;
break;
case V_248 :
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
if ( ! V_2 -> V_246 )
V_2 -> V_8 . V_12 = V_20 ;
else if ( ( V_2 -> V_64 >= V_243 ) &&
( ! ( V_2 -> V_89 & V_91 ) ) &&
( ! V_2 -> V_247 ) )
V_2 -> V_8 . V_12 = V_20 ;
else if ( V_204 == 0 )
V_2 -> V_8 . V_12 = V_20 ;
else
V_2 -> V_8 . V_12 = V_13 ;
break;
default:
V_2 -> V_8 . V_12 = V_20 ;
break;
}
if ( V_2 -> V_8 . V_12 == V_13 )
return F_93 ( V_2 ) ;
else
return F_84 ( V_2 ) ;
}
int F_97 ( struct V_1 * V_2 )
{
int V_125 = 0 ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_125 = F_98 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
return V_125 ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_20 ) {
V_2 -> V_8 . V_21 = V_23 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_68 ) {
V_2 -> V_8 . V_111 = V_114 ;
V_2 -> V_8 . V_83 = V_113 ;
F_8 ( V_2 ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_115 ) ;
F_100 ( V_2 -> V_97 , & V_231 ) ;
F_100 ( V_2 -> V_97 , & V_232 ) ;
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
F_100 ( V_2 -> V_97 , & V_234 ) ;
F_100 ( V_2 -> V_97 , & V_235 ) ;
F_100 ( V_2 -> V_97 , & V_231 ) ;
F_100 ( V_2 -> V_97 , & V_232 ) ;
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
struct V_101 * V_72 = V_2 -> V_72 ;
struct V_270 * V_271 ;
struct V_272 * V_272 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_52 = 0 ;
V_2 -> V_8 . V_26 = 0 ;
if ( V_2 -> V_81 && V_2 -> V_273 . V_274 ) {
F_106 (crtc,
&ddev->mode_config.crtc_list, head) {
V_272 = F_107 ( V_271 ) ;
if ( V_272 -> V_275 ) {
V_2 -> V_8 . V_52 |= ( 1 << V_272 -> V_276 ) ;
V_2 -> V_8 . V_26 ++ ;
}
}
}
if ( V_2 -> V_8 . V_12 == V_20 ) {
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_68 ) {
if ( V_2 -> V_8 . V_111 != V_114 ) {
if ( V_2 -> V_8 . V_26 > 1 ) {
if ( V_2 -> V_8 . V_111 == V_212 ) {
F_108 ( & V_2 -> V_8 . V_115 ) ;
V_2 -> V_8 . V_111 = V_112 ;
V_2 -> V_8 . V_83 = V_113 ;
F_109 ( V_2 ) ;
F_8 ( V_2 ) ;
F_23 ( L_40 ) ;
}
} else if ( V_2 -> V_8 . V_26 == 1 ) {
if ( V_2 -> V_8 . V_111 == V_277 ) {
V_2 -> V_8 . V_111 = V_212 ;
V_2 -> V_8 . V_83 = V_278 ;
F_109 ( V_2 ) ;
F_8 ( V_2 ) ;
F_78 ( & V_2 -> V_8 . V_115 ,
F_15 ( V_223 ) ) ;
} else if ( V_2 -> V_8 . V_111 == V_112 ) {
V_2 -> V_8 . V_111 = V_212 ;
F_78 ( & V_2 -> V_8 . V_115 ,
F_15 ( V_223 ) ) ;
F_23 ( L_41 ) ;
}
} else {
if ( V_2 -> V_8 . V_111 != V_277 ) {
F_108 ( & V_2 -> V_8 . V_115 ) ;
V_2 -> V_8 . V_111 = V_277 ;
V_2 -> V_8 . V_83 = V_279 ;
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
struct V_101 * V_72 = V_2 -> V_72 ;
struct V_270 * V_271 ;
struct V_272 * V_272 ;
if ( ! V_2 -> V_8 . V_14 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_201 = 0 ;
V_2 -> V_8 . V_16 . V_165 = 0 ;
if ( V_2 -> V_81 && V_2 -> V_273 . V_274 ) {
F_106 (crtc,
&ddev->mode_config.crtc_list, head) {
V_272 = F_107 ( V_271 ) ;
if ( V_271 -> V_275 ) {
V_2 -> V_8 . V_16 . V_201 |= ( 1 << V_272 -> V_276 ) ;
V_2 -> V_8 . V_16 . V_165 ++ ;
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
for ( V_271 = 0 ; ( V_271 < V_2 -> V_81 ) && V_283 ; V_271 ++ ) {
if ( V_2 -> V_8 . V_52 & ( 1 << V_271 ) ) {
V_282 = F_111 ( V_2 -> V_72 , V_271 , 0 , & V_280 , & V_281 , NULL , NULL ) ;
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
static void V_230 ( struct V_155 * V_156 )
{
struct V_1 * V_2 ;
int V_288 ;
V_2 = F_51 ( V_156 , struct V_1 ,
V_8 . V_115 . V_156 ) ;
V_288 = F_112 ( & V_2 -> V_289 . V_290 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_111 == V_212 ) {
int V_291 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_76 ; ++ V_6 ) {
struct V_77 * V_78 = & V_2 -> V_78 [ V_6 ] ;
if ( V_78 -> V_79 ) {
V_291 += F_113 ( V_2 , V_6 ) ;
if ( V_291 >= 3 )
break;
}
}
if ( V_291 >= 3 ) {
if ( V_2 -> V_8 . V_83 == V_292 ) {
V_2 -> V_8 . V_83 = V_84 ;
} else if ( V_2 -> V_8 . V_83 == V_84 &&
V_2 -> V_8 . V_225 ) {
V_2 -> V_8 . V_83 =
V_278 ;
V_2 -> V_8 . V_293 = V_294 +
F_15 ( V_295 ) ;
}
} else if ( V_291 == 0 ) {
if ( V_2 -> V_8 . V_83 == V_278 ) {
V_2 -> V_8 . V_83 = V_84 ;
} else if ( V_2 -> V_8 . V_83 == V_84 &&
V_2 -> V_8 . V_226 ) {
V_2 -> V_8 . V_83 =
V_292 ;
V_2 -> V_8 . V_293 = V_294 +
F_15 ( V_295 ) ;
}
}
if ( V_2 -> V_8 . V_83 != V_84 &&
V_294 > V_2 -> V_8 . V_293 ) {
F_109 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_78 ( & V_2 -> V_8 . V_115 ,
F_15 ( V_223 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_114 ( & V_2 -> V_289 . V_290 , V_288 ) ;
}
static int F_115 ( struct V_296 * V_297 , void * V_298 )
{
struct V_299 * V_300 = (struct V_299 * ) V_297 -> V_301 ;
struct V_101 * V_97 = V_300 -> V_302 -> V_97 ;
struct V_1 * V_2 = V_97 -> V_102 ;
struct V_101 * V_72 = V_2 -> V_72 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_72 -> V_107 != V_108 ) ) {
F_116 ( V_297 , L_45 ) ;
} else if ( V_2 -> V_8 . V_14 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_18 -> V_16 . V_303 )
F_117 ( V_2 , V_297 ) ;
else
F_116 ( V_297 , L_46 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_116 ( V_297 , L_47 , V_2 -> V_8 . V_63 ) ;
if ( ( V_2 -> V_64 >= V_256 ) && ( V_2 -> V_89 & V_91 ) )
F_116 ( V_297 , L_48 , V_2 -> V_8 . V_67 ) ;
else
F_116 ( V_297 , L_48 , F_118 ( V_2 ) ) ;
F_116 ( V_297 , L_49 , V_2 -> V_8 . V_66 ) ;
if ( V_2 -> V_18 -> V_8 . V_304 )
F_116 ( V_297 , L_50 , F_119 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_220 )
F_116 ( V_297 , L_51 , V_2 -> V_8 . V_220 ) ;
if ( V_2 -> V_18 -> V_8 . V_305 )
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
