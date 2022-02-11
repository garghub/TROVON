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
static int F_2 ( struct V_12 * V_13 ,
unsigned long V_14 ,
void * V_15 )
{
struct V_1 * V_2 = F_3 ( V_13 , struct V_1 , V_16 ) ;
struct V_17 * V_18 = (struct V_17 * ) V_15 ;
if ( strcmp ( V_18 -> V_19 , V_20 ) == 0 ) {
if ( F_4 () > 0 )
F_5 ( L_1 ) ;
else
F_5 ( L_2 ) ;
if ( V_2 -> V_8 . V_21 == V_22 ) {
if ( V_2 -> V_8 . V_23 == V_24 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( & V_2 -> V_8 . V_25 ) ;
}
}
}
return V_26 ;
}
static void F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 . V_23 ) {
case V_27 :
V_2 -> V_8 . V_28 = V_29 ;
break;
case V_24 :
if ( F_4 () > 0 ) {
if ( V_2 -> V_8 . V_30 > 1 )
V_2 -> V_8 . V_28 = V_31 ;
else
V_2 -> V_8 . V_28 = V_32 ;
} else {
if ( V_2 -> V_8 . V_30 > 1 )
V_2 -> V_8 . V_28 = V_33 ;
else
V_2 -> V_8 . V_28 = V_34 ;
}
break;
case V_35 :
if ( V_2 -> V_8 . V_30 > 1 )
V_2 -> V_8 . V_28 = V_36 ;
else
V_2 -> V_8 . V_28 = V_37 ;
break;
case V_38 :
if ( V_2 -> V_8 . V_30 > 1 )
V_2 -> V_8 . V_28 = V_33 ;
else
V_2 -> V_8 . V_28 = V_34 ;
break;
case V_39 :
if ( V_2 -> V_8 . V_30 > 1 )
V_2 -> V_8 . V_28 = V_31 ;
else
V_2 -> V_8 . V_28 = V_32 ;
break;
}
if ( V_2 -> V_8 . V_30 == 0 ) {
V_2 -> V_8 . V_40 =
V_2 -> V_8 . V_41 [ V_2 -> V_8 . V_28 ] . V_42 ;
V_2 -> V_8 . V_43 =
V_2 -> V_8 . V_41 [ V_2 -> V_8 . V_28 ] . V_44 ;
} else {
V_2 -> V_8 . V_40 =
V_2 -> V_8 . V_41 [ V_2 -> V_8 . V_28 ] . V_45 ;
V_2 -> V_8 . V_43 =
V_2 -> V_8 . V_41 [ V_2 -> V_8 . V_28 ] . V_46 ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_47 * V_48 , * V_49 ;
if ( F_11 ( & V_2 -> V_50 . V_51 ) )
return;
F_12 (bo, n, &rdev->gem.objects, list) {
if ( V_48 -> V_52 . V_53 . V_54 == V_55 )
F_13 ( & V_48 -> V_52 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_56 ) {
V_2 -> V_8 . V_57 = false ;
F_15 (
V_2 -> V_58 . V_59 , V_2 -> V_8 . V_57 ,
F_16 ( V_60 ) ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_61 , V_62 ;
bool V_63 = false ;
if ( ( V_2 -> V_8 . V_43 == V_2 -> V_8 . V_64 ) &&
( V_2 -> V_8 . V_40 == V_2 -> V_8 . V_65 ) )
return;
if ( F_18 ( V_2 ) ) {
V_61 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_40 ] .
V_66 [ V_2 -> V_8 . V_43 ] . V_61 ;
if ( V_61 > V_2 -> V_8 . V_67 )
V_61 = V_2 -> V_8 . V_67 ;
V_62 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_40 ] .
V_66 [ V_2 -> V_8 . V_43 ] . V_62 ;
if ( V_62 > V_2 -> V_8 . V_68 )
V_62 = V_2 -> V_8 . V_68 ;
if ( V_61 < V_2 -> V_8 . V_69 )
V_63 = true ;
F_14 ( V_2 ) ;
if ( V_2 -> V_8 . V_21 == V_70 ) {
if ( ! F_19 ( V_2 ) )
return;
}
F_20 ( V_2 ) ;
if ( ! V_63 )
F_21 ( V_2 ) ;
if ( V_61 != V_2 -> V_8 . V_69 ) {
F_22 ( V_2 , false ) ;
F_23 ( V_2 , V_61 ) ;
F_22 ( V_2 , true ) ;
V_2 -> V_8 . V_69 = V_61 ;
F_5 ( L_3 , V_61 ) ;
}
if ( V_2 -> V_71 -> V_8 . V_72 && ( V_62 != V_2 -> V_8 . V_73 ) ) {
F_22 ( V_2 , false ) ;
F_24 ( V_2 , V_62 ) ;
F_22 ( V_2 , true ) ;
V_2 -> V_8 . V_73 = V_62 ;
F_5 ( L_4 , V_62 ) ;
}
if ( V_63 )
F_21 ( V_2 ) ;
F_25 ( V_2 ) ;
V_2 -> V_8 . V_65 = V_2 -> V_8 . V_40 ;
V_2 -> V_8 . V_64 = V_2 -> V_8 . V_43 ;
} else
F_5 ( L_5 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ( V_2 -> V_8 . V_43 == V_2 -> V_8 . V_64 ) &&
( V_2 -> V_8 . V_40 == V_2 -> V_8 . V_65 ) )
return;
F_6 ( & V_2 -> V_74 -> V_75 ) ;
F_6 ( & V_2 -> V_76 ) ;
F_6 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 >= V_79 ) {
if ( V_2 -> V_58 . V_80 ) {
V_2 -> V_8 . V_81 = false ;
V_2 -> V_58 . V_81 = true ;
F_26 ( V_2 ) ;
F_27 (
V_2 -> V_58 . V_82 , V_2 -> V_8 . V_81 ,
F_16 ( V_83 ) ) ;
V_2 -> V_58 . V_81 = false ;
F_26 ( V_2 ) ;
}
} else {
struct V_84 * V_85 = & V_2 -> V_85 [ V_86 ] ;
if ( V_85 -> V_87 ) {
F_28 ( V_2 , V_86 ) ;
}
}
F_10 ( V_2 ) ;
if ( V_2 -> V_58 . V_80 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_88 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_56 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_89 |= ( 1 << V_6 ) ;
F_29 ( V_2 -> V_74 , V_6 ) ;
}
}
}
F_17 ( V_2 ) ;
if ( V_2 -> V_58 . V_80 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_88 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_89 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_89 &= ~ ( 1 << V_6 ) ;
F_30 ( V_2 -> V_74 , V_6 ) ;
}
}
}
F_31 ( V_2 ) ;
if ( V_2 -> V_8 . V_30 )
F_32 ( V_2 ) ;
V_2 -> V_8 . V_90 = V_91 ;
F_9 ( & V_2 -> V_77 ) ;
F_9 ( & V_2 -> V_76 ) ;
F_9 ( & V_2 -> V_74 -> V_75 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_6 , V_92 ;
struct V_93 * V_10 ;
struct V_94 * V_66 ;
F_5 ( L_6 , V_2 -> V_8 . V_9 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_9 ; V_6 ++ ) {
V_10 = & V_2 -> V_8 . V_10 [ V_6 ] ;
F_5 ( L_7 , V_6 ,
V_95 [ V_10 -> type ] ) ;
if ( V_6 == V_2 -> V_8 . V_11 )
F_5 ( L_8 ) ;
if ( ( V_2 -> V_96 & V_97 ) && ! ( V_2 -> V_96 & V_98 ) )
F_5 ( L_9 , V_10 -> V_99 ) ;
if ( V_10 -> V_96 & V_100 )
F_5 ( L_10 ) ;
F_5 ( L_11 , V_10 -> V_101 ) ;
for ( V_92 = 0 ; V_92 < V_10 -> V_101 ; V_92 ++ ) {
V_66 = & ( V_10 -> V_66 [ V_92 ] ) ;
if ( V_2 -> V_96 & V_98 )
F_5 ( L_12 ,
V_92 ,
V_66 -> V_61 * 10 ,
V_66 -> V_96 & V_102 ? L_13 : L_14 ) ;
else
F_5 ( L_15 ,
V_92 ,
V_66 -> V_61 * 10 ,
V_66 -> V_62 * 10 ,
V_66 -> V_103 . V_103 ,
V_66 -> V_96 & V_102 ? L_13 : L_14 ) ;
}
}
}
static T_2 F_34 ( struct V_104 * V_105 ,
struct V_106 * V_107 ,
char * V_108 )
{
struct V_109 * V_74 = F_35 ( F_36 ( V_105 ) ) ;
struct V_1 * V_2 = V_74 -> V_110 ;
int V_111 = V_2 -> V_8 . V_23 ;
return snprintf ( V_108 , V_112 , L_16 ,
( V_111 == V_24 ) ? L_17 :
( V_111 == V_35 ) ? L_18 :
( V_111 == V_38 ) ? L_19 :
( V_111 == V_39 ) ? L_20 : L_21 ) ;
}
static T_2 F_37 ( struct V_104 * V_105 ,
struct V_106 * V_107 ,
const char * V_108 ,
T_3 V_113 )
{
struct V_109 * V_74 = F_35 ( F_36 ( V_105 ) ) ;
struct V_1 * V_2 = V_74 -> V_110 ;
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_22 ) {
if ( strncmp ( L_21 , V_108 , strlen ( L_21 ) ) == 0 )
V_2 -> V_8 . V_23 = V_27 ;
else if ( strncmp ( L_17 , V_108 , strlen ( L_17 ) ) == 0 )
V_2 -> V_8 . V_23 = V_24 ;
else if ( strncmp ( L_18 , V_108 , strlen ( L_18 ) ) == 0 )
V_2 -> V_8 . V_23 = V_35 ;
else if ( strncmp ( L_19 , V_108 , strlen ( L_19 ) ) == 0 )
V_2 -> V_8 . V_23 = V_38 ;
else if ( strncmp ( L_20 , V_108 , strlen ( L_20 ) ) == 0 )
V_2 -> V_8 . V_23 = V_39 ;
else {
V_113 = - V_114 ;
goto V_115;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else
V_113 = - V_114 ;
V_115:
F_9 ( & V_2 -> V_8 . V_25 ) ;
return V_113 ;
}
static T_2 F_38 ( struct V_104 * V_105 ,
struct V_106 * V_107 ,
char * V_108 )
{
struct V_109 * V_74 = F_35 ( F_36 ( V_105 ) ) ;
struct V_1 * V_2 = V_74 -> V_110 ;
int V_8 = V_2 -> V_8 . V_21 ;
return snprintf ( V_108 , V_112 , L_16 ,
( V_8 == V_70 ) ? L_22 : L_23 ) ;
}
static T_2 F_39 ( struct V_104 * V_105 ,
struct V_106 * V_107 ,
const char * V_108 ,
T_3 V_113 )
{
struct V_109 * V_74 = F_35 ( F_36 ( V_105 ) ) ;
struct V_1 * V_2 = V_74 -> V_110 ;
if ( strncmp ( L_22 , V_108 , strlen ( L_22 ) ) == 0 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_21 = V_70 ;
V_2 -> V_8 . V_116 = V_117 ;
V_2 -> V_8 . V_90 = V_118 ;
F_9 ( & V_2 -> V_8 . V_25 ) ;
} else if ( strncmp ( L_23 , V_108 , strlen ( L_23 ) ) == 0 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_116 = V_119 ;
V_2 -> V_8 . V_90 = V_91 ;
V_2 -> V_8 . V_21 = V_22 ;
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_40 ( & V_2 -> V_8 . V_120 ) ;
} else {
V_113 = - V_114 ;
goto V_115;
}
F_41 ( V_2 ) ;
V_115:
return V_113 ;
}
static T_2 F_42 ( struct V_104 * V_105 ,
struct V_106 * V_107 ,
char * V_108 )
{
struct V_109 * V_74 = F_35 ( F_36 ( V_105 ) ) ;
struct V_1 * V_2 = V_74 -> V_110 ;
int V_121 ;
switch ( V_2 -> V_8 . V_122 ) {
case V_123 :
V_121 = F_43 ( V_2 ) ;
break;
case V_124 :
V_121 = F_44 ( V_2 ) ;
break;
case V_125 :
case V_126 :
V_121 = F_45 ( V_2 ) ;
break;
case V_127 :
V_121 = F_46 ( V_2 ) ;
break;
case V_128 :
V_121 = F_47 ( V_2 ) ;
break;
default:
V_121 = 0 ;
break;
}
return snprintf ( V_108 , V_112 , L_24 , V_121 ) ;
}
static T_2 F_48 ( struct V_104 * V_105 ,
struct V_106 * V_107 ,
char * V_108 )
{
return sprintf ( V_108 , L_25 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_129 = 0 ;
V_2 -> V_8 . V_130 = NULL ;
switch ( V_2 -> V_8 . V_122 ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
if ( V_2 -> V_78 == V_131 )
return V_129 ;
V_2 -> V_8 . V_130 = F_50 ( V_2 -> V_105 ) ;
if ( F_51 ( V_2 -> V_8 . V_130 ) ) {
V_129 = F_52 ( V_2 -> V_8 . V_130 ) ;
F_53 ( V_2 -> V_105 ,
L_26 , V_129 ) ;
break;
}
F_54 ( V_2 -> V_8 . V_130 , V_2 -> V_74 ) ;
V_129 = F_55 ( & V_2 -> V_8 . V_130 -> V_132 ,
& V_133 ) ;
if ( V_129 ) {
F_53 ( V_2 -> V_105 ,
L_27 , V_129 ) ;
F_56 ( V_2 -> V_105 ) ;
}
break;
default:
break;
}
return V_129 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_130 ) {
F_58 ( & V_2 -> V_8 . V_130 -> V_132 , & V_133 ) ;
F_56 ( V_2 -> V_8 . V_130 ) ;
}
}
void F_59 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_70 ) {
if ( V_2 -> V_8 . V_116 == V_134 )
V_2 -> V_8 . V_116 = V_135 ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_40 ( & V_2 -> V_8 . V_120 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
if ( F_61 ( V_2 ) && V_2 -> V_136 ) {
if ( V_2 -> V_8 . V_137 )
F_62 ( V_2 , V_2 -> V_8 . V_137 ,
V_138 ) ;
if ( V_2 -> V_8 . V_139 )
F_62 ( V_2 , V_2 -> V_8 . V_139 ,
V_140 ) ;
if ( V_2 -> V_8 . V_67 )
F_23 ( V_2 , V_2 -> V_8 . V_67 ) ;
if ( V_2 -> V_8 . V_68 )
F_24 ( V_2 , V_2 -> V_8 . V_68 ) ;
}
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_65 = V_2 -> V_8 . V_11 ;
V_2 -> V_8 . V_64 = 0 ;
V_2 -> V_8 . V_69 = V_2 -> V_8 . V_67 ;
V_2 -> V_8 . V_73 = V_2 -> V_8 . V_68 ;
V_2 -> V_8 . V_141 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_66 [ 0 ] . V_103 . V_103 ;
V_2 -> V_8 . V_142 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_66 [ 0 ] . V_103 . V_143 ;
if ( V_2 -> V_8 . V_21 == V_70
&& V_2 -> V_8 . V_116 == V_135 ) {
V_2 -> V_8 . V_116 = V_134 ;
F_63 ( & V_2 -> V_8 . V_120 ,
F_16 ( V_144 ) ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_41 ( V_2 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_145 ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_23 = V_27 ;
V_2 -> V_8 . V_116 = V_119 ;
V_2 -> V_8 . V_90 = V_91 ;
V_2 -> V_8 . V_146 = true ;
V_2 -> V_8 . V_147 = true ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_68 ;
V_2 -> V_8 . V_69 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_73 = V_2 -> clock . V_68 ;
V_2 -> V_8 . V_122 = V_148 ;
if ( V_2 -> V_149 ) {
if ( V_2 -> V_150 )
F_65 ( V_2 ) ;
else
F_66 ( V_2 ) ;
F_33 ( V_2 ) ;
F_67 ( V_2 ) ;
if ( F_61 ( V_2 ) && V_2 -> V_136 ) {
if ( V_2 -> V_8 . V_137 )
F_62 ( V_2 , V_2 -> V_8 . V_137 ,
V_138 ) ;
if ( V_2 -> V_8 . V_139 )
F_62 ( V_2 , V_2 -> V_8 . V_139 ,
V_140 ) ;
if ( V_2 -> V_8 . V_67 )
F_23 ( V_2 , V_2 -> V_8 . V_67 ) ;
if ( V_2 -> V_8 . V_68 )
F_24 ( V_2 , V_2 -> V_8 . V_68 ) ;
}
}
V_145 = F_49 ( V_2 ) ;
if ( V_145 )
return V_145 ;
F_68 ( & V_2 -> V_8 . V_120 , V_151 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_145 = F_69 ( V_2 -> V_105 , & V_152 ) ;
if ( V_145 )
F_70 ( L_28 ) ;
V_145 = F_69 ( V_2 -> V_105 , & V_153 ) ;
if ( V_145 )
F_70 ( L_29 ) ;
#ifdef F_71
V_2 -> V_16 . V_154 = F_2 ;
F_72 ( & V_2 -> V_16 ) ;
#endif
if ( F_73 ( V_2 ) ) {
F_70 ( L_30 ) ;
}
F_74 ( L_31 ) ;
}
return 0 ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_22 ) {
V_2 -> V_8 . V_23 = V_27 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_21 == V_70 ) {
V_2 -> V_8 . V_116 = V_119 ;
V_2 -> V_8 . V_90 = V_118 ;
F_8 ( V_2 ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_40 ( & V_2 -> V_8 . V_120 ) ;
F_76 ( V_2 -> V_105 , & V_152 ) ;
F_76 ( V_2 -> V_105 , & V_153 ) ;
#ifdef F_71
F_77 ( & V_2 -> V_16 ) ;
#endif
}
if ( V_2 -> V_8 . V_10 )
F_78 ( V_2 -> V_8 . V_10 ) ;
F_57 ( V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_109 * V_74 = V_2 -> V_74 ;
struct V_155 * V_156 ;
struct V_157 * V_157 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_56 = 0 ;
V_2 -> V_8 . V_30 = 0 ;
F_79 (crtc,
&ddev->mode_config.crtc_list, head) {
V_157 = F_80 ( V_156 ) ;
if ( V_157 -> V_158 ) {
V_2 -> V_8 . V_56 |= ( 1 << V_157 -> V_159 ) ;
V_2 -> V_8 . V_30 ++ ;
}
}
if ( V_2 -> V_8 . V_21 == V_22 ) {
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_21 == V_70 ) {
if ( V_2 -> V_8 . V_116 != V_119 ) {
if ( V_2 -> V_8 . V_30 > 1 ) {
if ( V_2 -> V_8 . V_116 == V_134 ) {
F_81 ( & V_2 -> V_8 . V_120 ) ;
V_2 -> V_8 . V_116 = V_117 ;
V_2 -> V_8 . V_90 = V_118 ;
F_82 ( V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( L_32 ) ;
}
} else if ( V_2 -> V_8 . V_30 == 1 ) {
if ( V_2 -> V_8 . V_116 == V_160 ) {
V_2 -> V_8 . V_116 = V_134 ;
V_2 -> V_8 . V_90 = V_161 ;
F_82 ( V_2 ) ;
F_8 ( V_2 ) ;
F_63 ( & V_2 -> V_8 . V_120 ,
F_16 ( V_144 ) ) ;
} else if ( V_2 -> V_8 . V_116 == V_117 ) {
V_2 -> V_8 . V_116 = V_134 ;
F_63 ( & V_2 -> V_8 . V_120 ,
F_16 ( V_144 ) ) ;
F_5 ( L_33 ) ;
}
} else {
if ( V_2 -> V_8 . V_116 != V_160 ) {
F_81 ( & V_2 -> V_8 . V_120 ) ;
V_2 -> V_8 . V_116 = V_160 ;
V_2 -> V_8 . V_90 = V_162 ;
F_82 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
int V_156 , V_163 , V_164 , V_165 ;
bool V_166 = true ;
for ( V_156 = 0 ; ( V_156 < V_2 -> V_88 ) && V_166 ; V_156 ++ ) {
if ( V_2 -> V_8 . V_56 & ( 1 << V_156 ) ) {
V_165 = F_83 ( V_2 -> V_74 , V_156 , & V_163 , & V_164 ) ;
if ( ( V_165 & V_167 ) &&
! ( V_165 & V_168 ) )
V_166 = false ;
}
}
return V_166 ;
}
static bool F_22 ( struct V_1 * V_2 , bool V_169 )
{
T_1 V_170 = 0 ;
bool V_166 = F_19 ( V_2 ) ;
if ( V_166 == false )
F_5 ( L_34 , V_170 ,
V_169 ? L_35 : L_36 ) ;
return V_166 ;
}
static void V_151 ( struct V_171 * V_172 )
{
struct V_1 * V_2 ;
int V_173 ;
V_2 = F_3 ( V_172 , struct V_1 ,
V_8 . V_120 . V_172 ) ;
V_173 = F_84 ( & V_2 -> V_174 . V_175 ) ;
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_116 == V_134 ) {
int V_176 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_177 ; ++ V_6 ) {
struct V_84 * V_85 = & V_2 -> V_85 [ V_6 ] ;
if ( V_85 -> V_87 ) {
V_176 += F_85 ( V_2 , V_6 ) ;
if ( V_176 >= 3 )
break;
}
}
if ( V_176 >= 3 ) {
if ( V_2 -> V_8 . V_90 == V_178 ) {
V_2 -> V_8 . V_90 = V_91 ;
} else if ( V_2 -> V_8 . V_90 == V_91 &&
V_2 -> V_8 . V_146 ) {
V_2 -> V_8 . V_90 =
V_161 ;
V_2 -> V_8 . V_179 = V_180 +
F_16 ( V_181 ) ;
}
} else if ( V_176 == 0 ) {
if ( V_2 -> V_8 . V_90 == V_161 ) {
V_2 -> V_8 . V_90 = V_91 ;
} else if ( V_2 -> V_8 . V_90 == V_91 &&
V_2 -> V_8 . V_147 ) {
V_2 -> V_8 . V_90 =
V_178 ;
V_2 -> V_8 . V_179 = V_180 +
F_16 ( V_181 ) ;
}
}
if ( V_2 -> V_8 . V_90 != V_91 &&
V_180 > V_2 -> V_8 . V_179 ) {
F_82 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_63 ( & V_2 -> V_8 . V_120 ,
F_16 ( V_144 ) ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_86 ( & V_2 -> V_174 . V_175 , V_173 ) ;
}
static int F_87 ( struct V_182 * V_183 , void * V_15 )
{
struct V_184 * V_185 = (struct V_184 * ) V_183 -> V_186 ;
struct V_109 * V_105 = V_185 -> V_187 -> V_105 ;
struct V_1 * V_2 = V_105 -> V_110 ;
F_88 ( V_183 , L_37 , V_2 -> V_8 . V_67 ) ;
F_88 ( V_183 , L_38 , F_89 ( V_2 ) ) ;
F_88 ( V_183 , L_39 , V_2 -> V_8 . V_68 ) ;
if ( V_2 -> V_71 -> V_8 . V_188 )
F_88 ( V_183 , L_40 , F_90 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_141 )
F_88 ( V_183 , L_41 , V_2 -> V_8 . V_141 ) ;
if ( V_2 -> V_71 -> V_8 . V_189 )
F_88 ( V_183 , L_42 , F_91 ( V_2 ) ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
#if F_92 ( V_190 )
return F_93 ( V_2 , V_191 , F_94 ( V_191 ) ) ;
#else
return 0 ;
#endif
}
