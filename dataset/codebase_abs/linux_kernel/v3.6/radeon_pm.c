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
F_26 ( & V_2 -> V_8 . V_76 ) ;
F_6 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 >= V_79 ) {
if ( V_2 -> V_58 . V_80 ) {
F_27 ( V_2 ) ;
}
} else {
struct V_81 * V_82 = & V_2 -> V_82 [ V_83 ] ;
if ( V_82 -> V_84 ) {
F_28 ( V_2 , V_83 ) ;
}
}
F_10 ( V_2 ) ;
if ( V_2 -> V_58 . V_80 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_85 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_56 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_86 |= ( 1 << V_6 ) ;
F_29 ( V_2 -> V_74 , V_6 ) ;
}
}
}
F_17 ( V_2 ) ;
if ( V_2 -> V_58 . V_80 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_85 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_86 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_86 &= ~ ( 1 << V_6 ) ;
F_30 ( V_2 -> V_74 , V_6 ) ;
}
}
}
F_31 ( V_2 ) ;
if ( V_2 -> V_8 . V_30 )
F_32 ( V_2 ) ;
V_2 -> V_8 . V_87 = V_88 ;
F_9 ( & V_2 -> V_77 ) ;
F_33 ( & V_2 -> V_8 . V_76 ) ;
F_9 ( & V_2 -> V_74 -> V_75 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_6 , V_89 ;
struct V_90 * V_10 ;
struct V_91 * V_66 ;
F_5 ( L_6 , V_2 -> V_8 . V_9 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_9 ; V_6 ++ ) {
V_10 = & V_2 -> V_8 . V_10 [ V_6 ] ;
F_5 ( L_7 , V_6 ,
V_92 [ V_10 -> type ] ) ;
if ( V_6 == V_2 -> V_8 . V_11 )
F_5 ( L_8 ) ;
if ( ( V_2 -> V_93 & V_94 ) && ! ( V_2 -> V_93 & V_95 ) )
F_5 ( L_9 , V_10 -> V_96 ) ;
if ( V_10 -> V_93 & V_97 )
F_5 ( L_10 ) ;
F_5 ( L_11 , V_10 -> V_98 ) ;
for ( V_89 = 0 ; V_89 < V_10 -> V_98 ; V_89 ++ ) {
V_66 = & ( V_10 -> V_66 [ V_89 ] ) ;
if ( V_2 -> V_93 & V_95 )
F_5 ( L_12 ,
V_89 ,
V_66 -> V_61 * 10 ,
V_66 -> V_93 & V_99 ? L_13 : L_14 ) ;
else
F_5 ( L_15 ,
V_89 ,
V_66 -> V_61 * 10 ,
V_66 -> V_62 * 10 ,
V_66 -> V_100 . V_100 ,
V_66 -> V_93 & V_99 ? L_13 : L_14 ) ;
}
}
}
static T_2 F_35 ( struct V_101 * V_102 ,
struct V_103 * V_104 ,
char * V_105 )
{
struct V_106 * V_74 = F_36 ( F_37 ( V_102 ) ) ;
struct V_1 * V_2 = V_74 -> V_107 ;
int V_108 = V_2 -> V_8 . V_23 ;
return snprintf ( V_105 , V_109 , L_16 ,
( V_108 == V_24 ) ? L_17 :
( V_108 == V_35 ) ? L_18 :
( V_108 == V_38 ) ? L_19 :
( V_108 == V_39 ) ? L_20 : L_21 ) ;
}
static T_2 F_38 ( struct V_101 * V_102 ,
struct V_103 * V_104 ,
const char * V_105 ,
T_3 V_110 )
{
struct V_106 * V_74 = F_36 ( F_37 ( V_102 ) ) ;
struct V_1 * V_2 = V_74 -> V_107 ;
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_22 ) {
if ( strncmp ( L_21 , V_105 , strlen ( L_21 ) ) == 0 )
V_2 -> V_8 . V_23 = V_27 ;
else if ( strncmp ( L_17 , V_105 , strlen ( L_17 ) ) == 0 )
V_2 -> V_8 . V_23 = V_24 ;
else if ( strncmp ( L_18 , V_105 , strlen ( L_18 ) ) == 0 )
V_2 -> V_8 . V_23 = V_35 ;
else if ( strncmp ( L_19 , V_105 , strlen ( L_19 ) ) == 0 )
V_2 -> V_8 . V_23 = V_38 ;
else if ( strncmp ( L_20 , V_105 , strlen ( L_20 ) ) == 0 )
V_2 -> V_8 . V_23 = V_39 ;
else {
V_110 = - V_111 ;
goto V_112;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else
V_110 = - V_111 ;
V_112:
F_9 ( & V_2 -> V_8 . V_25 ) ;
return V_110 ;
}
static T_2 F_39 ( struct V_101 * V_102 ,
struct V_103 * V_104 ,
char * V_105 )
{
struct V_106 * V_74 = F_36 ( F_37 ( V_102 ) ) ;
struct V_1 * V_2 = V_74 -> V_107 ;
int V_8 = V_2 -> V_8 . V_21 ;
return snprintf ( V_105 , V_109 , L_16 ,
( V_8 == V_70 ) ? L_22 : L_23 ) ;
}
static T_2 F_40 ( struct V_101 * V_102 ,
struct V_103 * V_104 ,
const char * V_105 ,
T_3 V_110 )
{
struct V_106 * V_74 = F_36 ( F_37 ( V_102 ) ) ;
struct V_1 * V_2 = V_74 -> V_107 ;
if ( strncmp ( L_22 , V_105 , strlen ( L_22 ) ) == 0 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_21 = V_70 ;
V_2 -> V_8 . V_113 = V_114 ;
V_2 -> V_8 . V_87 = V_115 ;
F_9 ( & V_2 -> V_8 . V_25 ) ;
} else if ( strncmp ( L_23 , V_105 , strlen ( L_23 ) ) == 0 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_113 = V_116 ;
V_2 -> V_8 . V_87 = V_88 ;
V_2 -> V_8 . V_21 = V_22 ;
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_41 ( & V_2 -> V_8 . V_117 ) ;
} else {
V_110 = - V_111 ;
goto V_112;
}
F_42 ( V_2 ) ;
V_112:
return V_110 ;
}
static T_2 F_43 ( struct V_101 * V_102 ,
struct V_103 * V_104 ,
char * V_105 )
{
struct V_106 * V_74 = F_36 ( F_37 ( V_102 ) ) ;
struct V_1 * V_2 = V_74 -> V_107 ;
int V_118 ;
switch ( V_2 -> V_8 . V_119 ) {
case V_120 :
V_118 = F_44 ( V_2 ) ;
break;
case V_121 :
V_118 = F_45 ( V_2 ) ;
break;
case V_122 :
case V_123 :
V_118 = F_46 ( V_2 ) ;
break;
case V_124 :
V_118 = F_47 ( V_2 ) ;
break;
case V_125 :
V_118 = F_48 ( V_2 ) ;
break;
default:
V_118 = 0 ;
break;
}
return snprintf ( V_105 , V_109 , L_24 , V_118 ) ;
}
static T_2 F_49 ( struct V_101 * V_102 ,
struct V_103 * V_104 ,
char * V_105 )
{
return sprintf ( V_105 , L_25 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_126 = 0 ;
V_2 -> V_8 . V_127 = NULL ;
switch ( V_2 -> V_8 . V_119 ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( V_2 -> V_78 == V_128 )
return V_126 ;
V_2 -> V_8 . V_127 = F_51 ( V_2 -> V_102 ) ;
if ( F_52 ( V_2 -> V_8 . V_127 ) ) {
V_126 = F_53 ( V_2 -> V_8 . V_127 ) ;
F_54 ( V_2 -> V_102 ,
L_26 , V_126 ) ;
break;
}
F_55 ( V_2 -> V_8 . V_127 , V_2 -> V_74 ) ;
V_126 = F_56 ( & V_2 -> V_8 . V_127 -> V_129 ,
& V_130 ) ;
if ( V_126 ) {
F_54 ( V_2 -> V_102 ,
L_27 , V_126 ) ;
F_57 ( V_2 -> V_102 ) ;
}
break;
default:
break;
}
return V_126 ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_127 ) {
F_59 ( & V_2 -> V_8 . V_127 -> V_129 , & V_130 ) ;
F_57 ( V_2 -> V_8 . V_127 ) ;
}
}
void F_60 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_70 ) {
if ( V_2 -> V_8 . V_113 == V_131 )
V_2 -> V_8 . V_113 = V_132 ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_41 ( & V_2 -> V_8 . V_117 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
if ( F_62 ( V_2 ) && V_2 -> V_133 ) {
if ( V_2 -> V_8 . V_134 )
F_63 ( V_2 , V_2 -> V_8 . V_134 ,
V_135 ) ;
if ( V_2 -> V_8 . V_136 )
F_63 ( V_2 , V_2 -> V_8 . V_136 ,
V_137 ) ;
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
V_2 -> V_8 . V_138 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_66 [ 0 ] . V_100 . V_100 ;
V_2 -> V_8 . V_139 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_66 [ 0 ] . V_100 . V_140 ;
if ( V_2 -> V_8 . V_21 == V_70
&& V_2 -> V_8 . V_113 == V_132 ) {
V_2 -> V_8 . V_113 = V_131 ;
F_64 ( & V_2 -> V_8 . V_117 ,
F_16 ( V_141 ) ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_42 ( V_2 ) ;
}
int F_65 ( struct V_1 * V_2 )
{
int V_142 ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_23 = V_27 ;
V_2 -> V_8 . V_113 = V_116 ;
V_2 -> V_8 . V_87 = V_88 ;
V_2 -> V_8 . V_143 = true ;
V_2 -> V_8 . V_144 = true ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_68 ;
V_2 -> V_8 . V_69 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_73 = V_2 -> clock . V_68 ;
V_2 -> V_8 . V_119 = V_145 ;
if ( V_2 -> V_146 ) {
if ( V_2 -> V_147 )
F_66 ( V_2 ) ;
else
F_67 ( V_2 ) ;
F_34 ( V_2 ) ;
F_68 ( V_2 ) ;
if ( F_62 ( V_2 ) && V_2 -> V_133 ) {
if ( V_2 -> V_8 . V_134 )
F_63 ( V_2 , V_2 -> V_8 . V_134 ,
V_135 ) ;
if ( V_2 -> V_8 . V_136 )
F_63 ( V_2 , V_2 -> V_8 . V_136 ,
V_137 ) ;
if ( V_2 -> V_8 . V_67 )
F_23 ( V_2 , V_2 -> V_8 . V_67 ) ;
if ( V_2 -> V_8 . V_68 )
F_24 ( V_2 , V_2 -> V_8 . V_68 ) ;
}
}
V_142 = F_50 ( V_2 ) ;
if ( V_142 )
return V_142 ;
F_69 ( & V_2 -> V_8 . V_117 , V_148 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_142 = F_70 ( V_2 -> V_102 , & V_149 ) ;
if ( V_142 )
F_71 ( L_28 ) ;
V_142 = F_70 ( V_2 -> V_102 , & V_150 ) ;
if ( V_142 )
F_71 ( L_29 ) ;
#ifdef F_72
V_2 -> V_16 . V_151 = F_2 ;
F_73 ( & V_2 -> V_16 ) ;
#endif
if ( F_74 ( V_2 ) ) {
F_71 ( L_30 ) ;
}
F_75 ( L_31 ) ;
}
return 0 ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_21 == V_22 ) {
V_2 -> V_8 . V_23 = V_27 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_21 == V_70 ) {
V_2 -> V_8 . V_113 = V_116 ;
V_2 -> V_8 . V_87 = V_115 ;
F_8 ( V_2 ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_41 ( & V_2 -> V_8 . V_117 ) ;
F_77 ( V_2 -> V_102 , & V_149 ) ;
F_77 ( V_2 -> V_102 , & V_150 ) ;
#ifdef F_72
F_78 ( & V_2 -> V_16 ) ;
#endif
}
if ( V_2 -> V_8 . V_10 )
F_79 ( V_2 -> V_8 . V_10 ) ;
F_58 ( V_2 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_106 * V_74 = V_2 -> V_74 ;
struct V_152 * V_153 ;
struct V_154 * V_154 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_6 ( & V_2 -> V_8 . V_25 ) ;
V_2 -> V_8 . V_56 = 0 ;
V_2 -> V_8 . V_30 = 0 ;
F_80 (crtc,
&ddev->mode_config.crtc_list, head) {
V_154 = F_81 ( V_153 ) ;
if ( V_154 -> V_155 ) {
V_2 -> V_8 . V_56 |= ( 1 << V_154 -> V_156 ) ;
V_2 -> V_8 . V_30 ++ ;
}
}
if ( V_2 -> V_8 . V_21 == V_22 ) {
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_21 == V_70 ) {
if ( V_2 -> V_8 . V_113 != V_116 ) {
if ( V_2 -> V_8 . V_30 > 1 ) {
if ( V_2 -> V_8 . V_113 == V_131 ) {
F_82 ( & V_2 -> V_8 . V_117 ) ;
V_2 -> V_8 . V_113 = V_114 ;
V_2 -> V_8 . V_87 = V_115 ;
F_83 ( V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( L_32 ) ;
}
} else if ( V_2 -> V_8 . V_30 == 1 ) {
if ( V_2 -> V_8 . V_113 == V_157 ) {
V_2 -> V_8 . V_113 = V_131 ;
V_2 -> V_8 . V_87 = V_158 ;
F_83 ( V_2 ) ;
F_8 ( V_2 ) ;
F_64 ( & V_2 -> V_8 . V_117 ,
F_16 ( V_141 ) ) ;
} else if ( V_2 -> V_8 . V_113 == V_114 ) {
V_2 -> V_8 . V_113 = V_131 ;
F_64 ( & V_2 -> V_8 . V_117 ,
F_16 ( V_141 ) ) ;
F_5 ( L_33 ) ;
}
} else {
if ( V_2 -> V_8 . V_113 != V_157 ) {
F_82 ( & V_2 -> V_8 . V_117 ) ;
V_2 -> V_8 . V_113 = V_157 ;
V_2 -> V_8 . V_87 = V_159 ;
F_83 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
int V_153 , V_160 , V_161 , V_162 ;
bool V_163 = true ;
for ( V_153 = 0 ; ( V_153 < V_2 -> V_85 ) && V_163 ; V_153 ++ ) {
if ( V_2 -> V_8 . V_56 & ( 1 << V_153 ) ) {
V_162 = F_84 ( V_2 -> V_74 , V_153 , & V_160 , & V_161 ) ;
if ( ( V_162 & V_164 ) &&
! ( V_162 & V_165 ) )
V_163 = false ;
}
}
return V_163 ;
}
static bool F_22 ( struct V_1 * V_2 , bool V_166 )
{
T_1 V_167 = 0 ;
bool V_163 = F_19 ( V_2 ) ;
if ( V_163 == false )
F_5 ( L_34 , V_167 ,
V_166 ? L_35 : L_36 ) ;
return V_163 ;
}
static void V_148 ( struct V_168 * V_169 )
{
struct V_1 * V_2 ;
int V_170 ;
V_2 = F_3 ( V_169 , struct V_1 ,
V_8 . V_117 . V_169 ) ;
V_170 = F_85 ( & V_2 -> V_171 . V_172 ) ;
F_6 ( & V_2 -> V_8 . V_25 ) ;
if ( V_2 -> V_8 . V_113 == V_131 ) {
int V_173 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_174 ; ++ V_6 ) {
struct V_81 * V_82 = & V_2 -> V_82 [ V_6 ] ;
if ( V_82 -> V_84 ) {
V_173 += F_86 ( V_2 , V_6 ) ;
if ( V_173 >= 3 )
break;
}
}
if ( V_173 >= 3 ) {
if ( V_2 -> V_8 . V_87 == V_175 ) {
V_2 -> V_8 . V_87 = V_88 ;
} else if ( V_2 -> V_8 . V_87 == V_88 &&
V_2 -> V_8 . V_143 ) {
V_2 -> V_8 . V_87 =
V_158 ;
V_2 -> V_8 . V_176 = V_177 +
F_16 ( V_178 ) ;
}
} else if ( V_173 == 0 ) {
if ( V_2 -> V_8 . V_87 == V_158 ) {
V_2 -> V_8 . V_87 = V_88 ;
} else if ( V_2 -> V_8 . V_87 == V_88 &&
V_2 -> V_8 . V_144 ) {
V_2 -> V_8 . V_87 =
V_175 ;
V_2 -> V_8 . V_176 = V_177 +
F_16 ( V_178 ) ;
}
}
if ( V_2 -> V_8 . V_87 != V_88 &&
V_177 > V_2 -> V_8 . V_176 ) {
F_83 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_64 ( & V_2 -> V_8 . V_117 ,
F_16 ( V_141 ) ) ;
}
F_9 ( & V_2 -> V_8 . V_25 ) ;
F_87 ( & V_2 -> V_171 . V_172 , V_170 ) ;
}
static int F_88 ( struct V_179 * V_180 , void * V_15 )
{
struct V_181 * V_182 = (struct V_181 * ) V_180 -> V_183 ;
struct V_106 * V_102 = V_182 -> V_184 -> V_102 ;
struct V_1 * V_2 = V_102 -> V_107 ;
F_89 ( V_180 , L_37 , V_2 -> V_8 . V_67 ) ;
F_89 ( V_180 , L_38 , F_90 ( V_2 ) ) ;
F_89 ( V_180 , L_39 , V_2 -> V_8 . V_68 ) ;
if ( V_2 -> V_71 -> V_8 . V_185 )
F_89 ( V_180 , L_40 , F_91 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_138 )
F_89 ( V_180 , L_41 , V_2 -> V_8 . V_138 ) ;
if ( V_2 -> V_71 -> V_8 . V_186 )
F_89 ( V_180 , L_42 , F_92 ( V_2 ) ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
#if F_93 ( V_187 )
return F_94 ( V_2 , V_188 , F_95 ( V_188 ) ) ;
#else
return 0 ;
#endif
}
