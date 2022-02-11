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
if ( V_2 -> V_8 . V_12 == V_13 ) {
if ( V_2 -> V_8 . V_14 == V_15 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
}
}
}
static void F_4 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_14 ) {
case V_17 :
V_2 -> V_8 . V_18 = V_19 ;
break;
case V_15 :
if ( F_7 () > 0 ) {
if ( V_2 -> V_8 . V_20 > 1 )
V_2 -> V_8 . V_18 = V_21 ;
else
V_2 -> V_8 . V_18 = V_22 ;
} else {
if ( V_2 -> V_8 . V_20 > 1 )
V_2 -> V_8 . V_18 = V_23 ;
else
V_2 -> V_8 . V_18 = V_24 ;
}
break;
case V_25 :
if ( V_2 -> V_8 . V_20 > 1 )
V_2 -> V_8 . V_18 = V_26 ;
else
V_2 -> V_8 . V_18 = V_27 ;
break;
case V_28 :
if ( V_2 -> V_8 . V_20 > 1 )
V_2 -> V_8 . V_18 = V_23 ;
else
V_2 -> V_8 . V_18 = V_24 ;
break;
case V_29 :
if ( V_2 -> V_8 . V_20 > 1 )
V_2 -> V_8 . V_18 = V_21 ;
else
V_2 -> V_8 . V_18 = V_22 ;
break;
}
if ( V_2 -> V_8 . V_20 == 0 ) {
V_2 -> V_8 . V_30 =
V_2 -> V_8 . V_31 [ V_2 -> V_8 . V_18 ] . V_32 ;
V_2 -> V_8 . V_33 =
V_2 -> V_8 . V_31 [ V_2 -> V_8 . V_18 ] . V_34 ;
} else {
V_2 -> V_8 . V_30 =
V_2 -> V_8 . V_31 [ V_2 -> V_8 . V_18 ] . V_35 ;
V_2 -> V_8 . V_33 =
V_2 -> V_8 . V_31 [ V_2 -> V_8 . V_18 ] . V_36 ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_37 * V_38 , * V_39 ;
if ( F_9 ( & V_2 -> V_40 . V_41 ) )
return;
F_10 (bo, n, &rdev->gem.objects, list) {
if ( V_38 -> V_42 . V_43 . V_44 == V_45 )
F_11 ( & V_38 -> V_42 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_46 ) {
V_2 -> V_8 . V_47 = false ;
F_13 (
V_2 -> V_48 . V_49 , V_2 -> V_8 . V_47 ,
F_14 ( V_50 ) ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_51 , V_52 ;
bool V_53 = false ;
if ( ( V_2 -> V_8 . V_33 == V_2 -> V_8 . V_54 ) &&
( V_2 -> V_8 . V_30 == V_2 -> V_8 . V_55 ) )
return;
if ( F_16 ( V_2 ) ) {
V_51 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_30 ] .
V_56 [ V_2 -> V_8 . V_33 ] . V_51 ;
if ( V_51 > V_2 -> V_8 . V_57 )
V_51 = V_2 -> V_8 . V_57 ;
if ( ( V_2 -> V_8 . V_12 == V_13 ) &&
( V_2 -> V_58 >= V_59 ) &&
V_2 -> V_8 . V_20 &&
( ( V_2 -> V_8 . V_18 == V_23 ) ||
( V_2 -> V_8 . V_18 == V_26 ) ) )
V_52 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_30 ] .
V_56 [ V_2 -> V_8 . V_31 [ V_21 ] . V_36 ] . V_52 ;
else
V_52 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_30 ] .
V_56 [ V_2 -> V_8 . V_33 ] . V_52 ;
if ( V_52 > V_2 -> V_8 . V_60 )
V_52 = V_2 -> V_8 . V_60 ;
if ( V_51 < V_2 -> V_8 . V_61 )
V_53 = true ;
F_12 ( V_2 ) ;
if ( V_2 -> V_8 . V_12 == V_62 ) {
if ( ! F_17 ( V_2 ) )
return;
}
F_18 ( V_2 ) ;
if ( ! V_53 )
F_19 ( V_2 ) ;
if ( V_51 != V_2 -> V_8 . V_61 ) {
F_20 ( V_2 , false ) ;
F_21 ( V_2 , V_51 ) ;
F_20 ( V_2 , true ) ;
V_2 -> V_8 . V_61 = V_51 ;
F_22 ( L_1 , V_51 ) ;
}
if ( V_2 -> V_63 -> V_8 . V_64 && ( V_52 != V_2 -> V_8 . V_65 ) ) {
F_20 ( V_2 , false ) ;
F_23 ( V_2 , V_52 ) ;
F_20 ( V_2 , true ) ;
V_2 -> V_8 . V_65 = V_52 ;
F_22 ( L_2 , V_52 ) ;
}
if ( V_53 )
F_19 ( V_2 ) ;
F_24 ( V_2 ) ;
V_2 -> V_8 . V_55 = V_2 -> V_8 . V_30 ;
V_2 -> V_8 . V_54 = V_2 -> V_8 . V_33 ;
} else
F_22 ( L_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_6 , V_66 ;
if ( ( V_2 -> V_8 . V_33 == V_2 -> V_8 . V_54 ) &&
( V_2 -> V_8 . V_30 == V_2 -> V_8 . V_55 ) )
return;
F_3 ( & V_2 -> V_67 -> V_68 ) ;
F_25 ( & V_2 -> V_8 . V_69 ) ;
F_3 ( & V_2 -> V_70 ) ;
for ( V_6 = 0 ; V_6 < V_71 ; V_6 ++ ) {
struct V_72 * V_73 = & V_2 -> V_73 [ V_6 ] ;
if ( ! V_73 -> V_74 ) {
continue;
}
V_66 = F_26 ( V_2 , V_6 ) ;
if ( V_66 ) {
F_6 ( & V_2 -> V_70 ) ;
F_27 ( & V_2 -> V_8 . V_69 ) ;
F_6 ( & V_2 -> V_67 -> V_68 ) ;
return;
}
}
F_8 ( V_2 ) ;
if ( V_2 -> V_48 . V_75 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_76 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_46 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_77 |= ( 1 << V_6 ) ;
F_28 ( V_2 -> V_67 , V_6 ) ;
}
}
}
F_15 ( V_2 ) ;
if ( V_2 -> V_48 . V_75 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_76 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_77 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_77 &= ~ ( 1 << V_6 ) ;
F_29 ( V_2 -> V_67 , V_6 ) ;
}
}
}
F_30 ( V_2 ) ;
if ( V_2 -> V_8 . V_20 )
F_31 ( V_2 ) ;
V_2 -> V_8 . V_78 = V_79 ;
F_6 ( & V_2 -> V_70 ) ;
F_27 ( & V_2 -> V_8 . V_69 ) ;
F_6 ( & V_2 -> V_67 -> V_68 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_6 , V_80 ;
struct V_81 * V_10 ;
struct V_82 * V_56 ;
F_22 ( L_4 , V_2 -> V_8 . V_9 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_9 ; V_6 ++ ) {
V_10 = & V_2 -> V_8 . V_10 [ V_6 ] ;
F_22 ( L_5 , V_6 ,
V_83 [ V_10 -> type ] ) ;
if ( V_6 == V_2 -> V_8 . V_11 )
F_22 ( L_6 ) ;
if ( ( V_2 -> V_84 & V_85 ) && ! ( V_2 -> V_84 & V_86 ) )
F_22 ( L_7 , V_10 -> V_87 ) ;
if ( V_10 -> V_84 & V_88 )
F_22 ( L_8 ) ;
F_22 ( L_9 , V_10 -> V_89 ) ;
for ( V_80 = 0 ; V_80 < V_10 -> V_89 ; V_80 ++ ) {
V_56 = & ( V_10 -> V_56 [ V_80 ] ) ;
if ( V_2 -> V_84 & V_86 )
F_22 ( L_10 ,
V_80 ,
V_56 -> V_51 * 10 ) ;
else
F_22 ( L_11 ,
V_80 ,
V_56 -> V_51 * 10 ,
V_56 -> V_52 * 10 ,
V_56 -> V_90 . V_90 ) ;
}
}
}
static T_2 F_33 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
int V_98 = V_2 -> V_8 . V_14 ;
return snprintf ( V_95 , V_99 , L_12 ,
( V_98 == V_15 ) ? L_13 :
( V_98 == V_25 ) ? L_14 :
( V_98 == V_28 ) ? L_15 :
( V_98 == V_29 ) ? L_16 : L_17 ) ;
}
static T_2 F_36 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_95 ,
T_3 V_100 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
if ( strncmp ( L_17 , V_95 , strlen ( L_17 ) ) == 0 )
V_2 -> V_8 . V_14 = V_17 ;
else if ( strncmp ( L_13 , V_95 , strlen ( L_13 ) ) == 0 )
V_2 -> V_8 . V_14 = V_15 ;
else if ( strncmp ( L_14 , V_95 , strlen ( L_14 ) ) == 0 )
V_2 -> V_8 . V_14 = V_25 ;
else if ( strncmp ( L_15 , V_95 , strlen ( L_15 ) ) == 0 )
V_2 -> V_8 . V_14 = V_28 ;
else if ( strncmp ( L_16 , V_95 , strlen ( L_16 ) ) == 0 )
V_2 -> V_8 . V_14 = V_29 ;
else {
V_100 = - V_101 ;
goto V_102;
}
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
} else
V_100 = - V_101 ;
V_102:
F_6 ( & V_2 -> V_8 . V_16 ) ;
return V_100 ;
}
static T_2 F_37 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
int V_8 = V_2 -> V_8 . V_12 ;
return snprintf ( V_95 , V_99 , L_12 ,
( V_8 == V_62 ) ? L_18 :
( V_8 == V_13 ) ? L_19 : L_20 ) ;
}
static T_2 F_38 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_95 ,
T_3 V_100 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
if ( V_2 -> V_8 . V_12 == V_103 ) {
V_100 = - V_101 ;
goto V_102;
}
if ( strncmp ( L_18 , V_95 , strlen ( L_18 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_12 = V_62 ;
V_2 -> V_8 . V_104 = V_105 ;
V_2 -> V_8 . V_78 = V_106 ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
} else if ( strncmp ( L_19 , V_95 , strlen ( L_19 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_104 = V_107 ;
V_2 -> V_8 . V_78 = V_79 ;
V_2 -> V_8 . V_12 = V_13 ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_39 ( & V_2 -> V_8 . V_108 ) ;
} else {
V_100 = - V_101 ;
goto V_102;
}
F_40 ( V_2 ) ;
V_102:
return V_100 ;
}
static T_2 F_41 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
enum V_3 V_8 = V_2 -> V_8 . V_109 . V_110 ;
return snprintf ( V_95 , V_99 , L_12 ,
( V_8 == V_111 ) ? L_21 :
( V_8 == V_112 ) ? L_22 : L_23 ) ;
}
static T_2 F_42 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_95 ,
T_3 V_100 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( strncmp ( L_21 , V_95 , strlen ( L_21 ) ) == 0 )
V_2 -> V_8 . V_109 . V_110 = V_111 ;
else if ( strncmp ( L_22 , V_95 , strlen ( L_22 ) ) == 0 )
V_2 -> V_8 . V_109 . V_110 = V_112 ;
else if ( strncmp ( L_23 , V_95 , strlen ( L_23 ) ) == 0 )
V_2 -> V_8 . V_109 . V_110 = V_113 ;
else {
F_6 ( & V_2 -> V_8 . V_16 ) ;
V_100 = - V_101 ;
goto V_102;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_40 ( V_2 ) ;
V_102:
return V_100 ;
}
static T_2 F_43 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
enum V_114 V_115 = V_2 -> V_8 . V_109 . V_116 ;
return snprintf ( V_95 , V_99 , L_12 ,
( V_115 == V_117 ) ? L_13 :
( V_115 == V_118 ) ? L_14 : L_16 ) ;
}
static T_2 F_44 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_95 ,
T_3 V_100 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
enum V_114 V_115 ;
int V_119 = 0 ;
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( strncmp ( L_14 , V_95 , strlen ( L_14 ) ) == 0 ) {
V_115 = V_118 ;
} else if ( strncmp ( L_16 , V_95 , strlen ( L_16 ) ) == 0 ) {
V_115 = V_120 ;
} else if ( strncmp ( L_13 , V_95 , strlen ( L_13 ) ) == 0 ) {
V_115 = V_117 ;
} else {
F_6 ( & V_2 -> V_8 . V_16 ) ;
V_100 = - V_101 ;
goto V_102;
}
if ( V_2 -> V_63 -> V_109 . V_121 ) {
V_119 = F_45 ( V_2 , V_115 ) ;
if ( V_119 )
V_100 = - V_101 ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
V_102:
return V_100 ;
}
static T_2 F_46 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
int V_122 ;
if ( V_2 -> V_63 -> V_8 . V_123 )
V_122 = F_47 ( V_2 ) ;
else
V_122 = 0 ;
return snprintf ( V_95 , V_99 , L_24 , V_122 ) ;
}
static T_2 F_48 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
return sprintf ( V_95 , L_25 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_124 = 0 ;
V_2 -> V_8 . V_125 = NULL ;
switch ( V_2 -> V_8 . V_126 ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
if ( V_2 -> V_63 -> V_8 . V_123 == NULL )
return V_124 ;
V_2 -> V_8 . V_125 = F_50 ( V_2 -> V_92 ) ;
if ( F_51 ( V_2 -> V_8 . V_125 ) ) {
V_124 = F_52 ( V_2 -> V_8 . V_125 ) ;
F_53 ( V_2 -> V_92 ,
L_26 , V_124 ) ;
break;
}
F_54 ( V_2 -> V_8 . V_125 , V_2 -> V_67 ) ;
V_124 = F_55 ( & V_2 -> V_8 . V_125 -> V_133 ,
& V_134 ) ;
if ( V_124 ) {
F_53 ( V_2 -> V_92 ,
L_27 , V_124 ) ;
F_56 ( V_2 -> V_92 ) ;
}
break;
default:
break;
}
return V_124 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_125 ) {
F_58 ( & V_2 -> V_8 . V_125 -> V_133 , & V_134 ) ;
F_56 ( V_2 -> V_8 . V_125 ) ;
}
}
static void F_59 ( struct V_135 * V_136 )
{
struct V_1 * V_2 =
F_60 ( V_136 , struct V_1 ,
V_8 . V_109 . V_137 . V_136 ) ;
enum V_3 V_138 = V_139 ;
if ( ! V_2 -> V_8 . V_140 )
return;
if ( V_2 -> V_63 -> V_8 . V_123 ) {
int V_122 = F_47 ( V_2 ) ;
if ( V_122 < V_2 -> V_8 . V_109 . V_137 . V_141 )
V_138 = V_2 -> V_8 . V_109 . V_110 ;
} else {
if ( V_2 -> V_8 . V_109 . V_137 . V_142 )
V_138 = V_2 -> V_8 . V_109 . V_110 ;
}
F_61 ( V_2 , V_138 ) ;
}
static struct V_143 * F_62 ( struct V_1 * V_2 ,
enum V_3 V_138 )
{
int V_6 ;
struct V_143 * V_144 ;
T_1 V_145 ;
bool V_146 = ( V_2 -> V_8 . V_109 . V_147 < 2 ) ?
true : false ;
if ( V_146 && V_2 -> V_63 -> V_109 . V_148 ) {
if ( F_63 ( V_2 ) )
V_146 = false ;
}
if ( V_138 == V_113 )
V_138 = V_149 ;
if ( V_138 == V_112 )
V_138 = V_113 ;
V_150:
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_109 . V_151 ; V_6 ++ ) {
V_144 = & V_2 -> V_8 . V_109 . V_144 [ V_6 ] ;
V_145 = V_144 -> V_152 & V_153 ;
switch ( V_138 ) {
case V_111 :
if ( V_145 == V_154 ) {
if ( V_144 -> V_155 & V_156 ) {
if ( V_146 )
return V_144 ;
} else
return V_144 ;
}
break;
case V_112 :
if ( V_145 == V_157 ) {
if ( V_144 -> V_155 & V_156 ) {
if ( V_146 )
return V_144 ;
} else
return V_144 ;
}
break;
case V_113 :
if ( V_145 == V_158 ) {
if ( V_144 -> V_155 & V_156 ) {
if ( V_146 )
return V_144 ;
} else
return V_144 ;
}
break;
case V_159 :
return V_2 -> V_8 . V_109 . V_160 ;
case V_161 :
if ( V_144 -> V_152 & V_162 )
return V_144 ;
break;
case V_163 :
if ( V_144 -> V_152 & V_164 )
return V_144 ;
break;
case V_165 :
if ( V_144 -> V_152 & V_166 )
return V_144 ;
break;
case V_167 :
if ( V_144 -> V_168 & V_169 )
return V_144 ;
break;
case V_170 :
return V_2 -> V_8 . V_109 . V_171 ;
case V_139 :
if ( V_144 -> V_152 & V_172 )
return V_144 ;
break;
case V_173 :
if ( V_144 -> V_152 & V_174 )
return V_144 ;
break;
case V_175 :
if ( V_144 -> V_168 & V_176 )
return V_144 ;
break;
case V_149 :
if ( V_144 -> V_152 & V_177 )
return V_144 ;
break;
default:
break;
}
}
switch ( V_138 ) {
case V_161 :
case V_163 :
case V_165 :
case V_167 :
return V_2 -> V_8 . V_109 . V_160 ;
case V_139 :
V_138 = V_173 ;
goto V_150;
case V_173 :
V_138 = V_111 ;
goto V_150;
case V_111 :
case V_112 :
case V_149 :
V_138 = V_113 ;
goto V_150;
default:
break;
}
return NULL ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_143 * V_144 ;
enum V_3 V_138 ;
int V_119 ;
if ( ! V_2 -> V_8 . V_140 )
return;
if ( V_2 -> V_8 . V_109 . V_110 != V_2 -> V_8 . V_109 . V_178 ) {
if ( ( ! V_2 -> V_8 . V_109 . V_179 ) &&
( ! V_2 -> V_8 . V_109 . V_180 ) )
V_2 -> V_8 . V_109 . V_178 = V_2 -> V_8 . V_109 . V_110 ;
}
V_138 = V_2 -> V_8 . V_109 . V_178 ;
V_144 = F_62 ( V_2 , V_138 ) ;
if ( V_144 )
V_2 -> V_8 . V_109 . V_181 = V_144 ;
else
return;
if ( V_2 -> V_8 . V_109 . V_182 == V_2 -> V_8 . V_109 . V_181 ) {
if ( ( V_2 -> V_58 < V_59 ) || ( V_2 -> V_84 & V_86 ) ) {
if ( V_2 -> V_8 . V_109 . V_183 != V_2 -> V_8 . V_109 . V_184 ) {
F_31 ( V_2 ) ;
F_65 ( V_2 ) ;
V_2 -> V_8 . V_109 . V_184 = V_2 -> V_8 . V_109 . V_183 ;
V_2 -> V_8 . V_109 . V_185 = V_2 -> V_8 . V_109 . V_147 ;
}
return;
} else {
if ( V_2 -> V_8 . V_109 . V_183 ==
V_2 -> V_8 . V_109 . V_184 ) {
return;
} else {
if ( ( V_2 -> V_8 . V_109 . V_185 > 1 ) &&
( V_2 -> V_8 . V_109 . V_147 > 1 ) ) {
F_31 ( V_2 ) ;
F_65 ( V_2 ) ;
V_2 -> V_8 . V_109 . V_184 = V_2 -> V_8 . V_109 . V_183 ;
V_2 -> V_8 . V_109 . V_185 = V_2 -> V_8 . V_109 . V_147 ;
return;
}
}
}
}
F_66 ( L_28 ) ;
F_67 ( V_2 , V_2 -> V_8 . V_109 . V_182 ) ;
F_66 ( L_29 ) ;
F_67 ( V_2 , V_2 -> V_8 . V_109 . V_181 ) ;
F_3 ( & V_2 -> V_67 -> V_68 ) ;
F_25 ( & V_2 -> V_8 . V_69 ) ;
F_3 ( & V_2 -> V_70 ) ;
V_119 = F_68 ( V_2 ) ;
if ( V_119 )
goto V_186;
F_31 ( V_2 ) ;
F_65 ( V_2 ) ;
V_2 -> V_8 . V_109 . V_184 = V_2 -> V_8 . V_109 . V_183 ;
V_2 -> V_8 . V_109 . V_185 = V_2 -> V_8 . V_109 . V_147 ;
for ( V_6 = 0 ; V_6 < V_71 ; V_6 ++ ) {
struct V_72 * V_73 = & V_2 -> V_73 [ V_6 ] ;
if ( V_73 -> V_74 )
F_26 ( V_2 , V_6 ) ;
}
F_69 ( V_2 ) ;
V_2 -> V_8 . V_109 . V_182 = V_2 -> V_8 . V_109 . V_181 ;
F_70 ( V_2 ) ;
V_186:
F_6 ( & V_2 -> V_70 ) ;
F_27 ( & V_2 -> V_8 . V_69 ) ;
F_6 ( & V_2 -> V_67 -> V_68 ) ;
}
void F_61 ( struct V_1 * V_2 ,
enum V_3 V_138 )
{
if ( ! V_2 -> V_8 . V_140 )
return;
F_3 ( & V_2 -> V_8 . V_16 ) ;
switch ( V_138 ) {
case V_139 :
V_2 -> V_8 . V_109 . V_179 = true ;
break;
case V_159 :
case V_161 :
case V_163 :
case V_165 :
case V_167 :
V_2 -> V_8 . V_109 . V_180 = true ;
break;
default:
V_2 -> V_8 . V_109 . V_179 = false ;
V_2 -> V_8 . V_109 . V_180 = false ;
break;
}
V_2 -> V_8 . V_109 . V_178 = V_138 ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_40 ( V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( V_2 -> V_8 . V_12 == V_62 ) {
if ( V_2 -> V_8 . V_104 == V_187 )
V_2 -> V_8 . V_104 = V_188 ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_39 ( & V_2 -> V_8 . V_108 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_16 ) ;
F_73 ( V_2 ) ;
V_2 -> V_8 . V_109 . V_182 = V_2 -> V_8 . V_109 . V_181 = V_2 -> V_8 . V_109 . V_171 ;
V_2 -> V_8 . V_140 = false ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_103 )
F_72 ( V_2 ) ;
else
F_71 ( V_2 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_58 >= V_59 ) &&
( V_2 -> V_58 <= V_189 ) &&
V_2 -> V_190 ) {
if ( V_2 -> V_8 . V_191 )
F_76 ( V_2 , V_2 -> V_8 . V_191 ,
V_192 ) ;
if ( V_2 -> V_8 . V_193 )
F_76 ( V_2 , V_2 -> V_8 . V_193 ,
V_194 ) ;
if ( V_2 -> V_8 . V_57 )
F_21 ( V_2 , V_2 -> V_8 . V_57 ) ;
if ( V_2 -> V_8 . V_60 )
F_23 ( V_2 , V_2 -> V_8 . V_60 ) ;
}
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_55 = V_2 -> V_8 . V_11 ;
V_2 -> V_8 . V_54 = 0 ;
V_2 -> V_8 . V_61 = V_2 -> V_8 . V_57 ;
V_2 -> V_8 . V_65 = V_2 -> V_8 . V_60 ;
V_2 -> V_8 . V_195 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_56 [ 0 ] . V_90 . V_90 ;
V_2 -> V_8 . V_196 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_56 [ 0 ] . V_90 . V_197 ;
if ( V_2 -> V_8 . V_12 == V_62
&& V_2 -> V_8 . V_104 == V_188 ) {
V_2 -> V_8 . V_104 = V_187 ;
F_77 ( & V_2 -> V_8 . V_108 ,
F_14 ( V_198 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_40 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
int V_119 ;
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_109 . V_182 = V_2 -> V_8 . V_109 . V_181 = V_2 -> V_8 . V_109 . V_171 ;
F_79 ( V_2 ) ;
V_119 = F_80 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
if ( V_119 ) {
F_81 ( L_30 ) ;
if ( ( V_2 -> V_58 >= V_59 ) &&
( V_2 -> V_58 <= V_189 ) &&
V_2 -> V_190 ) {
if ( V_2 -> V_8 . V_191 )
F_76 ( V_2 , V_2 -> V_8 . V_191 ,
V_192 ) ;
if ( V_2 -> V_8 . V_193 )
F_76 ( V_2 , V_2 -> V_8 . V_193 ,
V_194 ) ;
if ( V_2 -> V_8 . V_57 )
F_21 ( V_2 , V_2 -> V_8 . V_57 ) ;
if ( V_2 -> V_8 . V_60 )
F_23 ( V_2 , V_2 -> V_8 . V_60 ) ;
}
} else {
V_2 -> V_8 . V_140 = true ;
F_40 ( V_2 ) ;
}
}
void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_103 )
F_78 ( V_2 ) ;
else
F_75 ( V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_119 ;
V_2 -> V_8 . V_14 = V_17 ;
V_2 -> V_8 . V_104 = V_107 ;
V_2 -> V_8 . V_78 = V_79 ;
V_2 -> V_8 . V_199 = true ;
V_2 -> V_8 . V_200 = true ;
V_2 -> V_8 . V_57 = V_2 -> clock . V_57 ;
V_2 -> V_8 . V_60 = V_2 -> clock . V_60 ;
V_2 -> V_8 . V_61 = V_2 -> clock . V_57 ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_60 ;
V_2 -> V_8 . V_126 = V_201 ;
if ( V_2 -> V_202 ) {
if ( V_2 -> V_203 )
F_84 ( V_2 ) ;
else
F_85 ( V_2 ) ;
F_32 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( ( V_2 -> V_58 >= V_59 ) &&
( V_2 -> V_58 <= V_189 ) &&
V_2 -> V_190 ) {
if ( V_2 -> V_8 . V_191 )
F_76 ( V_2 , V_2 -> V_8 . V_191 ,
V_192 ) ;
if ( V_2 -> V_8 . V_193 )
F_76 ( V_2 , V_2 -> V_8 . V_193 ,
V_194 ) ;
if ( V_2 -> V_8 . V_57 )
F_21 ( V_2 , V_2 -> V_8 . V_57 ) ;
if ( V_2 -> V_8 . V_60 )
F_23 ( V_2 , V_2 -> V_8 . V_60 ) ;
}
}
V_119 = F_49 ( V_2 ) ;
if ( V_119 )
return V_119 ;
F_87 ( & V_2 -> V_8 . V_108 , V_204 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_119 = F_88 ( V_2 -> V_92 , & V_205 ) ;
if ( V_119 )
F_81 ( L_31 ) ;
V_119 = F_88 ( V_2 -> V_92 , & V_206 ) ;
if ( V_119 )
F_81 ( L_32 ) ;
if ( F_89 ( V_2 ) ) {
F_81 ( L_33 ) ;
}
F_90 ( L_34 ) ;
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_109 . V_151 ; V_6 ++ ) {
F_66 ( L_35 , V_6 ) ;
F_67 ( V_2 , & V_2 -> V_8 . V_109 . V_144 [ V_6 ] ) ;
}
}
static int F_92 ( struct V_1 * V_2 )
{
int V_119 ;
V_2 -> V_8 . V_109 . V_178 = V_112 ;
V_2 -> V_8 . V_109 . V_110 = V_112 ;
V_2 -> V_8 . V_57 = V_2 -> clock . V_57 ;
V_2 -> V_8 . V_60 = V_2 -> clock . V_60 ;
V_2 -> V_8 . V_61 = V_2 -> clock . V_57 ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_60 ;
V_2 -> V_8 . V_126 = V_201 ;
if ( V_2 -> V_202 && V_2 -> V_203 )
F_84 ( V_2 ) ;
else
return - V_101 ;
V_119 = F_49 ( V_2 ) ;
if ( V_119 )
return V_119 ;
F_93 ( & V_2 -> V_8 . V_109 . V_137 . V_136 , F_59 ) ;
F_3 ( & V_2 -> V_8 . V_16 ) ;
F_94 ( V_2 ) ;
V_2 -> V_8 . V_109 . V_182 = V_2 -> V_8 . V_109 . V_181 = V_2 -> V_8 . V_109 . V_171 ;
F_91 ( V_2 ) ;
F_79 ( V_2 ) ;
V_119 = F_80 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
if ( V_119 ) {
V_2 -> V_8 . V_140 = false ;
if ( ( V_2 -> V_58 >= V_59 ) &&
( V_2 -> V_58 <= V_189 ) &&
V_2 -> V_190 ) {
if ( V_2 -> V_8 . V_191 )
F_76 ( V_2 , V_2 -> V_8 . V_191 ,
V_192 ) ;
if ( V_2 -> V_8 . V_193 )
F_76 ( V_2 , V_2 -> V_8 . V_193 ,
V_194 ) ;
if ( V_2 -> V_8 . V_57 )
F_21 ( V_2 , V_2 -> V_8 . V_57 ) ;
if ( V_2 -> V_8 . V_60 )
F_23 ( V_2 , V_2 -> V_8 . V_60 ) ;
}
F_81 ( L_36 ) ;
return V_119 ;
}
V_2 -> V_8 . V_140 = true ;
F_40 ( V_2 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_119 = F_88 ( V_2 -> V_92 , & V_207 ) ;
if ( V_119 )
F_81 ( L_37 ) ;
V_119 = F_88 ( V_2 -> V_92 , & V_208 ) ;
if ( V_119 )
F_81 ( L_37 ) ;
V_119 = F_88 ( V_2 -> V_92 , & V_205 ) ;
if ( V_119 )
F_81 ( L_31 ) ;
V_119 = F_88 ( V_2 -> V_92 , & V_206 ) ;
if ( V_119 )
F_81 ( L_32 ) ;
if ( F_89 ( V_2 ) ) {
F_81 ( L_38 ) ;
}
F_90 ( L_39 ) ;
}
return 0 ;
}
int F_95 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_58 ) {
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_59 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_189 :
if ( ! V_2 -> V_236 )
V_2 -> V_8 . V_12 = V_13 ;
else if ( ( V_2 -> V_58 >= V_216 ) &&
( ! ( V_2 -> V_84 & V_86 ) ) &&
( ! V_2 -> V_237 ) )
V_2 -> V_8 . V_12 = V_13 ;
else if ( V_238 == 1 )
V_2 -> V_8 . V_12 = V_103 ;
else
V_2 -> V_8 . V_12 = V_13 ;
break;
default:
V_2 -> V_8 . V_12 = V_13 ;
break;
}
if ( V_2 -> V_8 . V_12 == V_103 )
return F_92 ( V_2 ) ;
else
return F_83 ( V_2 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
V_2 -> V_8 . V_14 = V_17 ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_62 ) {
V_2 -> V_8 . V_104 = V_107 ;
V_2 -> V_8 . V_78 = V_106 ;
F_5 ( V_2 ) ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_39 ( & V_2 -> V_8 . V_108 ) ;
F_97 ( V_2 -> V_92 , & V_205 ) ;
F_97 ( V_2 -> V_92 , & V_206 ) ;
}
if ( V_2 -> V_8 . V_10 )
F_98 ( V_2 -> V_8 . V_10 ) ;
F_57 ( V_2 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
F_73 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_97 ( V_2 -> V_92 , & V_207 ) ;
F_97 ( V_2 -> V_92 , & V_208 ) ;
F_97 ( V_2 -> V_92 , & V_205 ) ;
F_97 ( V_2 -> V_92 , & V_206 ) ;
}
F_100 ( V_2 ) ;
if ( V_2 -> V_8 . V_10 )
F_98 ( V_2 -> V_8 . V_10 ) ;
F_57 ( V_2 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_103 )
F_99 ( V_2 ) ;
else
F_96 ( V_2 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_96 * V_67 = V_2 -> V_67 ;
struct V_239 * V_240 ;
struct V_241 * V_241 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_46 = 0 ;
V_2 -> V_8 . V_20 = 0 ;
F_103 (crtc,
&ddev->mode_config.crtc_list, head) {
V_241 = F_104 ( V_240 ) ;
if ( V_241 -> V_242 ) {
V_2 -> V_8 . V_46 |= ( 1 << V_241 -> V_243 ) ;
V_2 -> V_8 . V_20 ++ ;
}
}
if ( V_2 -> V_8 . V_12 == V_13 ) {
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_62 ) {
if ( V_2 -> V_8 . V_104 != V_107 ) {
if ( V_2 -> V_8 . V_20 > 1 ) {
if ( V_2 -> V_8 . V_104 == V_187 ) {
F_105 ( & V_2 -> V_8 . V_108 ) ;
V_2 -> V_8 . V_104 = V_105 ;
V_2 -> V_8 . V_78 = V_106 ;
F_106 ( V_2 ) ;
F_5 ( V_2 ) ;
F_22 ( L_40 ) ;
}
} else if ( V_2 -> V_8 . V_20 == 1 ) {
if ( V_2 -> V_8 . V_104 == V_244 ) {
V_2 -> V_8 . V_104 = V_187 ;
V_2 -> V_8 . V_78 = V_245 ;
F_106 ( V_2 ) ;
F_5 ( V_2 ) ;
F_77 ( & V_2 -> V_8 . V_108 ,
F_14 ( V_198 ) ) ;
} else if ( V_2 -> V_8 . V_104 == V_105 ) {
V_2 -> V_8 . V_104 = V_187 ;
F_77 ( & V_2 -> V_8 . V_108 ,
F_14 ( V_198 ) ) ;
F_22 ( L_41 ) ;
}
} else {
if ( V_2 -> V_8 . V_104 != V_244 ) {
F_105 ( & V_2 -> V_8 . V_108 ) ;
V_2 -> V_8 . V_104 = V_244 ;
V_2 -> V_8 . V_78 = V_246 ;
F_106 ( V_2 ) ;
F_5 ( V_2 ) ;
}
}
}
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_96 * V_67 = V_2 -> V_67 ;
struct V_239 * V_240 ;
struct V_241 * V_241 ;
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_109 . V_183 = 0 ;
V_2 -> V_8 . V_109 . V_147 = 0 ;
F_103 (crtc,
&ddev->mode_config.crtc_list, head) {
V_241 = F_104 ( V_240 ) ;
if ( V_240 -> V_242 ) {
V_2 -> V_8 . V_109 . V_183 |= ( 1 << V_241 -> V_243 ) ;
V_2 -> V_8 . V_109 . V_147 ++ ;
}
}
if ( F_7 () > 0 )
V_2 -> V_8 . V_109 . V_247 = true ;
else
V_2 -> V_8 . V_109 . V_247 = false ;
F_64 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_103 )
F_107 ( V_2 ) ;
else
F_102 ( V_2 ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
int V_240 , V_248 , V_249 , V_250 ;
bool V_251 = true ;
for ( V_240 = 0 ; ( V_240 < V_2 -> V_76 ) && V_251 ; V_240 ++ ) {
if ( V_2 -> V_8 . V_46 & ( 1 << V_240 ) ) {
V_250 = F_108 ( V_2 -> V_67 , V_240 , & V_248 , & V_249 ) ;
if ( ( V_250 & V_252 ) &&
! ( V_250 & V_253 ) )
V_251 = false ;
}
}
return V_251 ;
}
static bool F_20 ( struct V_1 * V_2 , bool V_254 )
{
T_1 V_255 = 0 ;
bool V_251 = F_17 ( V_2 ) ;
if ( V_251 == false )
F_22 ( L_42 , V_255 ,
V_254 ? L_43 : L_44 ) ;
return V_251 ;
}
static void V_204 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
int V_256 ;
V_2 = F_60 ( V_136 , struct V_1 ,
V_8 . V_108 . V_136 ) ;
V_256 = F_109 ( & V_2 -> V_257 . V_258 ) ;
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( V_2 -> V_8 . V_104 == V_187 ) {
int V_259 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_71 ; ++ V_6 ) {
struct V_72 * V_73 = & V_2 -> V_73 [ V_6 ] ;
if ( V_73 -> V_74 ) {
V_259 += F_110 ( V_2 , V_6 ) ;
if ( V_259 >= 3 )
break;
}
}
if ( V_259 >= 3 ) {
if ( V_2 -> V_8 . V_78 == V_260 ) {
V_2 -> V_8 . V_78 = V_79 ;
} else if ( V_2 -> V_8 . V_78 == V_79 &&
V_2 -> V_8 . V_199 ) {
V_2 -> V_8 . V_78 =
V_245 ;
V_2 -> V_8 . V_261 = V_262 +
F_14 ( V_263 ) ;
}
} else if ( V_259 == 0 ) {
if ( V_2 -> V_8 . V_78 == V_245 ) {
V_2 -> V_8 . V_78 = V_79 ;
} else if ( V_2 -> V_8 . V_78 == V_79 &&
V_2 -> V_8 . V_200 ) {
V_2 -> V_8 . V_78 =
V_260 ;
V_2 -> V_8 . V_261 = V_262 +
F_14 ( V_263 ) ;
}
}
if ( V_2 -> V_8 . V_78 != V_79 &&
V_262 > V_2 -> V_8 . V_261 ) {
F_106 ( V_2 ) ;
F_5 ( V_2 ) ;
}
F_77 ( & V_2 -> V_8 . V_108 ,
F_14 ( V_198 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_111 ( & V_2 -> V_257 . V_258 , V_256 ) ;
}
static int F_112 ( struct V_264 * V_265 , void * V_266 )
{
struct V_267 * V_268 = (struct V_267 * ) V_265 -> V_269 ;
struct V_96 * V_92 = V_268 -> V_270 -> V_92 ;
struct V_1 * V_2 = V_92 -> V_97 ;
if ( V_2 -> V_8 . V_140 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( V_2 -> V_63 -> V_109 . V_271 )
F_113 ( V_2 , V_265 ) ;
else
F_114 ( V_265 , L_45 ) ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
} else {
F_114 ( V_265 , L_46 , V_2 -> V_8 . V_57 ) ;
if ( ( V_2 -> V_58 >= V_225 ) && ( V_2 -> V_84 & V_86 ) )
F_114 ( V_265 , L_47 , V_2 -> V_8 . V_61 ) ;
else
F_114 ( V_265 , L_47 , F_115 ( V_2 ) ) ;
F_114 ( V_265 , L_48 , V_2 -> V_8 . V_60 ) ;
if ( V_2 -> V_63 -> V_8 . V_272 )
F_114 ( V_265 , L_49 , F_116 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_195 )
F_114 ( V_265 , L_50 , V_2 -> V_8 . V_195 ) ;
if ( V_2 -> V_63 -> V_8 . V_273 )
F_114 ( V_265 , L_51 , F_117 ( V_2 ) ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
#if F_118 ( V_274 )
return F_119 ( V_2 , V_275 , F_120 ( V_275 ) ) ;
#else
return 0 ;
#endif
}
