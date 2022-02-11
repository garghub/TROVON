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
if ( V_2 -> V_71 -> V_72 && ( V_62 != V_2 -> V_8 . V_73 ) ) {
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
F_6 ( & V_2 -> V_77 . V_25 ) ;
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
if ( V_2 -> V_77 . V_84 ) {
struct V_85 * V_86 ;
F_28 ( V_2 , 64 ) ;
F_29 ( V_2 , & V_86 ) ;
F_30 ( V_2 , V_86 ) ;
F_31 ( V_2 ) ;
F_32 ( V_86 , false ) ;
F_33 ( & V_86 ) ;
}
}
F_10 ( V_2 ) ;
if ( V_2 -> V_58 . V_80 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_87 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_56 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_88 |= ( 1 << V_6 ) ;
F_34 ( V_2 -> V_74 , V_6 ) ;
}
}
}
F_17 ( V_2 ) ;
if ( V_2 -> V_58 . V_80 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_87 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_88 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_88 &= ~ ( 1 << V_6 ) ;
F_35 ( V_2 -> V_74 , V_6 ) ;
}
}
}
F_36 ( V_2 ) ;
if ( V_2 -> V_8 . V_30 )
F_37 ( V_2 ) ;
V_2 -> V_8 . V_89 = V_90 ;
F_9 ( & V_2 -> V_77 . V_25 ) ;
F_9 ( & V_2 -> V_76 ) ;
F_9 ( & V_2 -> V_74 -> V_75 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
int V_6 , V_91 ;
struct V_92 * V_10 ;
struct V_93 * V_66 ;
F_5 ( L_6 , V_2 -> V_8 . V_9 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_9 ; V_6 ++ ) {
V_10 = & V_2 -> V_8 . V_10 [ V_6 ] ;
F_5 ( L_7 , V_6 ,
V_94 [ V_10 -> type ] ) ;
if ( V_6 == V_2 -> V_8 . V_11 )
F_5 ( L_8 ) ;
if ( ( V_2 -> V_95 & V_96 ) && ! ( V_2 -> V_95 & V_97 ) )
F_5 ( L_9 , V_10 -> V_98 ) ;
if ( V_10 -> V_95 & V_99 )
F_5 ( L_10 ) ;
F_5 ( L_11 , V_10 -> V_100 ) ;
for ( V_91 = 0 ; V_91 < V_10 -> V_100 ; V_91 ++ ) {
V_66 = & ( V_10 -> V_66 [ V_91 ] ) ;
if ( V_2 -> V_95 & V_97 )
F_5 ( L_12 ,
V_91 ,
V_66 -> V_61 * 10 ,
V_66 -> V_95 & V_101 ? L_13 : L_14 ) ;
else
F_5 ( L_15 ,
V_91 ,
V_66 -> V_61 * 10 ,
V_66 -> V_62 * 10 ,
V_66 -> V_102 . V_102 ,
V_66 -> V_95 & V_101 ? L_13 : L_14 ) ;
}
}
}
static T_2 F_39 ( struct V_103 * V_104 ,
struct V_105 * V_106 ,
char * V_107 )
{
struct V_108 * V_74 = F_40 ( F_41 ( V_104 ) ) ;
struct V_1 * V_2 = V_74 -> V_109 ;
int V_77 = V_2 -> V_8 . V_23 ;
return snprintf ( V_107 , V_110 , L_16 ,
( V_77 == V_24 ) ? L_17 :
( V_77 == V_35 ) ? L_18 :
( V_77 == V_38 ) ? L_19 :
( V_77 == V_39 ) ? L_20 : L_21 ) ;
}
static T_2 F_42 ( struct V_103 * V_104 ,
struct V_105 * V_106 ,
const char * V_107 ,
T_3 V_111 )
{
struct V_108 * V_74 = F_40 ( F_41 ( V_104 ) ) ;
struct V_1 * V_2 = V_74 -> V_109 ;
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_22 ) {
if ( strncmp ( L_21 , V_107 , strlen ( L_21 ) ) == 0 )
V_2 -> V_8 . V_23 = V_27 ;
else if ( strncmp ( L_17 , V_107 , strlen ( L_17 ) ) == 0 )
V_2 -> V_8 . V_23 = V_24 ;
else if ( strncmp ( L_18 , V_107 , strlen ( L_18 ) ) == 0 )
V_2 -> V_8 . V_23 = V_35 ;
else if ( strncmp ( L_19 , V_107 , strlen ( L_19 ) ) == 0 )
V_2 -> V_8 . V_23 = V_38 ;
else if ( strncmp ( L_20 , V_107 , strlen ( L_20 ) ) == 0 )
V_2 -> V_8 . V_23 = V_39 ;
else {
V_111 = - V_112 ;
goto V_113;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else
V_111 = - V_112 ;
V_113:
F_9 ( & V_2 -> V_8 . V_25 ) ;
return V_111 ;
}
static T_2 F_43 ( struct V_103 * V_104 ,
struct V_105 * V_106 ,
char * V_107 )
{
struct V_108 * V_74 = F_40 ( F_41 ( V_104 ) ) ;
struct V_1 * V_2 = V_74 -> V_109 ;
int V_8 = V_2 -> V_8 . V_21 ;
return snprintf ( V_107 , V_110 , L_16 ,
( V_8 == V_70 ) ? L_22 : L_23 ) ;
}
static T_2 F_44 ( struct V_103 * V_104 ,
struct V_105 * V_106 ,
const char * V_107 ,
T_3 V_111 )
{
struct V_108 * V_74 = F_40 ( F_41 ( V_104 ) ) ;
struct V_1 * V_2 = V_74 -> V_109 ;
if ( strncmp ( L_22 , V_107 , strlen ( L_22 ) ) == 0 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_21 = V_70 ;
V_2 -> V_8 . V_114 = V_115 ;
V_2 -> V_8 . V_89 = V_116 ;
F_9 ( & V_2 -> V_8 . V_25 ) ;
} else if ( strncmp ( L_23 , V_107 , strlen ( L_23 ) ) == 0 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_114 = V_117 ;
V_2 -> V_8 . V_89 = V_90 ;
V_2 -> V_8 . V_21 = V_22 ;
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_45 ( & V_2 -> V_8 . V_118 ) ;
} else {
V_111 = - V_112 ;
goto V_113;
}
F_46 ( V_2 ) ;
V_113:
return V_111 ;
}
static T_2 F_47 ( struct V_103 * V_104 ,
struct V_105 * V_106 ,
char * V_107 )
{
struct V_108 * V_74 = F_40 ( F_41 ( V_104 ) ) ;
struct V_1 * V_2 = V_74 -> V_109 ;
int V_119 ;
switch ( V_2 -> V_8 . V_120 ) {
case V_121 :
V_119 = F_48 ( V_2 ) ;
break;
case V_122 :
V_119 = F_49 ( V_2 ) ;
break;
case V_123 :
case V_124 :
V_119 = F_50 ( V_2 ) ;
break;
case V_125 :
V_119 = F_51 ( V_2 ) ;
break;
default:
V_119 = 0 ;
break;
}
return snprintf ( V_107 , V_110 , L_24 , V_119 ) ;
}
static T_2 F_52 ( struct V_103 * V_104 ,
struct V_105 * V_106 ,
char * V_107 )
{
return sprintf ( V_107 , L_25 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_126 = 0 ;
V_2 -> V_8 . V_127 = NULL ;
switch ( V_2 -> V_8 . V_120 ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_2 -> V_8 . V_127 = F_54 ( V_2 -> V_104 ) ;
if ( F_55 ( V_2 -> V_8 . V_127 ) ) {
V_126 = F_56 ( V_2 -> V_8 . V_127 ) ;
F_57 ( V_2 -> V_104 ,
L_26 , V_126 ) ;
break;
}
F_58 ( V_2 -> V_8 . V_127 , V_2 -> V_74 ) ;
V_126 = F_59 ( & V_2 -> V_8 . V_127 -> V_128 ,
& V_129 ) ;
if ( V_126 ) {
F_57 ( V_2 -> V_104 ,
L_27 , V_126 ) ;
F_60 ( V_2 -> V_104 ) ;
}
break;
default:
break;
}
return V_126 ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_127 ) {
F_62 ( & V_2 -> V_8 . V_127 -> V_128 , & V_129 ) ;
F_60 ( V_2 -> V_8 . V_127 ) ;
}
}
void F_63 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_70 ) {
if ( V_2 -> V_8 . V_114 == V_130 )
V_2 -> V_8 . V_114 = V_131 ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_45 ( & V_2 -> V_8 . V_118 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
if ( F_65 ( V_2 ) && V_2 -> V_132 ) {
if ( V_2 -> V_8 . V_133 )
F_66 ( V_2 , V_2 -> V_8 . V_133 ,
V_134 ) ;
if ( V_2 -> V_8 . V_135 )
F_66 ( V_2 , V_2 -> V_8 . V_135 ,
V_136 ) ;
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
V_2 -> V_8 . V_137 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_66 [ 0 ] . V_102 . V_102 ;
V_2 -> V_8 . V_138 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_66 [ 0 ] . V_102 . V_139 ;
if ( V_2 -> V_8 . V_21 == V_70
&& V_2 -> V_8 . V_114 == V_131 ) {
V_2 -> V_8 . V_114 = V_130 ;
F_67 ( & V_2 -> V_8 . V_118 ,
F_16 ( V_140 ) ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_46 ( V_2 ) ;
}
int F_68 ( struct V_1 * V_2 )
{
int V_141 ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_23 = V_27 ;
V_2 -> V_8 . V_114 = V_117 ;
V_2 -> V_8 . V_89 = V_90 ;
V_2 -> V_8 . V_142 = true ;
V_2 -> V_8 . V_143 = true ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_68 ;
V_2 -> V_8 . V_69 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_73 = V_2 -> clock . V_68 ;
V_2 -> V_8 . V_120 = V_144 ;
if ( V_2 -> V_145 ) {
if ( V_2 -> V_146 )
F_69 ( V_2 ) ;
else
F_70 ( V_2 ) ;
F_38 ( V_2 ) ;
F_71 ( V_2 ) ;
if ( F_65 ( V_2 ) && V_2 -> V_132 ) {
if ( V_2 -> V_8 . V_133 )
F_66 ( V_2 , V_2 -> V_8 . V_133 ,
V_134 ) ;
if ( V_2 -> V_8 . V_135 )
F_66 ( V_2 , V_2 -> V_8 . V_135 ,
V_136 ) ;
if ( V_2 -> V_8 . V_67 )
F_23 ( V_2 , V_2 -> V_8 . V_67 ) ;
if ( V_2 -> V_8 . V_68 )
F_24 ( V_2 , V_2 -> V_8 . V_68 ) ;
}
}
V_141 = F_53 ( V_2 ) ;
if ( V_141 )
return V_141 ;
F_72 ( & V_2 -> V_8 . V_118 , V_147 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_141 = F_73 ( V_2 -> V_104 , & V_148 ) ;
if ( V_141 )
F_74 ( L_28 ) ;
V_141 = F_73 ( V_2 -> V_104 , & V_149 ) ;
if ( V_141 )
F_74 ( L_29 ) ;
#ifdef F_75
V_2 -> V_16 . V_150 = F_2 ;
F_76 ( & V_2 -> V_16 ) ;
#endif
if ( F_77 ( V_2 ) ) {
F_74 ( L_30 ) ;
}
F_78 ( L_31 ) ;
}
return 0 ;
}
void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_22 ) {
V_2 -> V_8 . V_23 = V_27 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_21 == V_70 ) {
V_2 -> V_8 . V_114 = V_117 ;
V_2 -> V_8 . V_89 = V_116 ;
F_8 ( V_2 ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_45 ( & V_2 -> V_8 . V_118 ) ;
F_80 ( V_2 -> V_104 , & V_148 ) ;
F_80 ( V_2 -> V_104 , & V_149 ) ;
#ifdef F_75
F_81 ( & V_2 -> V_16 ) ;
#endif
}
if ( V_2 -> V_8 . V_10 )
F_82 ( V_2 -> V_8 . V_10 ) ;
F_61 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_108 * V_74 = V_2 -> V_74 ;
struct V_151 * V_152 ;
struct V_153 * V_153 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_56 = 0 ;
V_2 -> V_8 . V_30 = 0 ;
F_83 (crtc,
&ddev->mode_config.crtc_list, head) {
V_153 = F_84 ( V_152 ) ;
if ( V_153 -> V_154 ) {
V_2 -> V_8 . V_56 |= ( 1 << V_153 -> V_155 ) ;
V_2 -> V_8 . V_30 ++ ;
}
}
if ( V_2 -> V_8 . V_21 == V_22 ) {
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_21 == V_70 ) {
if ( V_2 -> V_8 . V_114 != V_117 ) {
if ( V_2 -> V_8 . V_30 > 1 ) {
if ( V_2 -> V_8 . V_114 == V_130 ) {
F_85 ( & V_2 -> V_8 . V_118 ) ;
V_2 -> V_8 . V_114 = V_115 ;
V_2 -> V_8 . V_89 = V_116 ;
F_86 ( V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( L_32 ) ;
}
} else if ( V_2 -> V_8 . V_30 == 1 ) {
if ( V_2 -> V_8 . V_114 == V_156 ) {
V_2 -> V_8 . V_114 = V_130 ;
V_2 -> V_8 . V_89 = V_157 ;
F_86 ( V_2 ) ;
F_8 ( V_2 ) ;
F_67 ( & V_2 -> V_8 . V_118 ,
F_16 ( V_140 ) ) ;
} else if ( V_2 -> V_8 . V_114 == V_115 ) {
V_2 -> V_8 . V_114 = V_130 ;
F_67 ( & V_2 -> V_8 . V_118 ,
F_16 ( V_140 ) ) ;
F_5 ( L_33 ) ;
}
} else {
if ( V_2 -> V_8 . V_114 != V_156 ) {
F_85 ( & V_2 -> V_8 . V_118 ) ;
V_2 -> V_8 . V_114 = V_156 ;
V_2 -> V_8 . V_89 = V_158 ;
F_86 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
int V_152 , V_159 , V_160 , V_161 ;
bool V_162 = true ;
for ( V_152 = 0 ; ( V_152 < V_2 -> V_87 ) && V_162 ; V_152 ++ ) {
if ( V_2 -> V_8 . V_56 & ( 1 << V_152 ) ) {
V_161 = F_87 ( V_2 -> V_74 , V_152 , & V_159 , & V_160 ) ;
if ( ( V_161 & V_163 ) &&
! ( V_161 & V_164 ) )
V_162 = false ;
}
}
return V_162 ;
}
static bool F_22 ( struct V_1 * V_2 , bool V_165 )
{
T_1 V_166 = 0 ;
bool V_162 = F_19 ( V_2 ) ;
if ( V_162 == false )
F_5 ( L_34 , V_166 ,
V_165 ? L_35 : L_36 ) ;
return V_162 ;
}
static void V_147 ( struct V_167 * V_168 )
{
struct V_1 * V_2 ;
int V_169 ;
V_2 = F_3 ( V_168 , struct V_1 ,
V_8 . V_118 . V_168 ) ;
V_169 = F_88 ( & V_2 -> V_170 . V_171 ) ;
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_114 == V_130 ) {
unsigned long V_172 ;
int V_173 = 0 ;
F_89 ( & V_2 -> V_174 . V_175 , V_172 ) ;
if ( ! F_11 ( & V_2 -> V_174 . V_176 ) ) {
struct V_177 * V_178 ;
F_90 (ptr, &rdev->fence_drv.emited) {
if ( ++ V_173 >= 3 )
break;
}
}
F_91 ( & V_2 -> V_174 . V_175 , V_172 ) ;
if ( V_173 >= 3 ) {
if ( V_2 -> V_8 . V_89 == V_179 ) {
V_2 -> V_8 . V_89 = V_90 ;
} else if ( V_2 -> V_8 . V_89 == V_90 &&
V_2 -> V_8 . V_142 ) {
V_2 -> V_8 . V_89 =
V_157 ;
V_2 -> V_8 . V_180 = V_181 +
F_16 ( V_182 ) ;
}
} else if ( V_173 == 0 ) {
if ( V_2 -> V_8 . V_89 == V_157 ) {
V_2 -> V_8 . V_89 = V_90 ;
} else if ( V_2 -> V_8 . V_89 == V_90 &&
V_2 -> V_8 . V_143 ) {
V_2 -> V_8 . V_89 =
V_179 ;
V_2 -> V_8 . V_180 = V_181 +
F_16 ( V_182 ) ;
}
}
if ( V_2 -> V_8 . V_89 != V_90 &&
V_181 > V_2 -> V_8 . V_180 ) {
F_86 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_67 ( & V_2 -> V_8 . V_118 ,
F_16 ( V_140 ) ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_92 ( & V_2 -> V_170 . V_171 , V_169 ) ;
}
static int F_93 ( struct V_183 * V_184 , void * V_15 )
{
struct V_185 * V_186 = (struct V_185 * ) V_184 -> V_187 ;
struct V_108 * V_104 = V_186 -> V_188 -> V_104 ;
struct V_1 * V_2 = V_104 -> V_109 ;
F_94 ( V_184 , L_37 , V_2 -> V_8 . V_67 ) ;
F_94 ( V_184 , L_38 , F_95 ( V_2 ) ) ;
F_94 ( V_184 , L_39 , V_2 -> V_8 . V_68 ) ;
if ( V_2 -> V_71 -> V_189 )
F_94 ( V_184 , L_40 , F_96 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_137 )
F_94 ( V_184 , L_41 , V_2 -> V_8 . V_137 ) ;
if ( V_2 -> V_71 -> V_190 )
F_94 ( V_184 , L_42 , F_97 ( V_2 ) ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
#if F_98 ( V_191 )
return F_99 ( V_2 , V_192 , F_100 ( V_192 ) ) ;
#else
return 0 ;
#endif
}
