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
F_26 ( & V_2 -> V_8 . V_73 ) ;
F_3 ( & V_2 -> V_74 ) ;
for ( V_6 = 0 ; V_6 < V_75 ; V_6 ++ ) {
struct V_76 * V_77 = & V_2 -> V_77 [ V_6 ] ;
if ( ! V_77 -> V_78 ) {
continue;
}
V_72 = F_27 ( V_2 , V_6 ) ;
if ( V_72 ) {
F_6 ( & V_2 -> V_74 ) ;
F_28 ( & V_2 -> V_8 . V_73 ) ;
return;
}
}
F_9 ( V_2 ) ;
if ( V_2 -> V_56 . V_79 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_80 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_54 & ( 1 << V_6 ) ) {
if ( F_29 ( V_2 -> V_81 , V_6 ) == 0 )
V_2 -> V_8 . V_82 |= ( 1 << V_6 ) ;
else
F_23 ( L_4 ,
V_6 ) ;
}
}
}
F_16 ( V_2 ) ;
if ( V_2 -> V_56 . V_79 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_80 ; V_6 ++ ) {
if ( V_2 -> V_8 . V_82 & ( 1 << V_6 ) ) {
V_2 -> V_8 . V_82 &= ~ ( 1 << V_6 ) ;
F_30 ( V_2 -> V_81 , V_6 ) ;
}
}
}
F_31 ( V_2 ) ;
if ( V_2 -> V_8 . V_28 )
F_32 ( V_2 ) ;
V_2 -> V_8 . V_83 = V_84 ;
F_6 ( & V_2 -> V_74 ) ;
F_28 ( & V_2 -> V_8 . V_73 ) ;
}
static void F_33 ( struct V_1 * V_2 )
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
static T_2 F_34 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_81 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_81 -> V_102 ;
int V_103 = V_2 -> V_8 . V_23 ;
return snprintf ( V_100 , V_104 , L_13 ,
( V_103 == V_24 ) ? L_14 :
( V_103 == V_33 ) ? L_15 :
( V_103 == V_36 ) ? L_16 :
( V_103 == V_37 ) ? L_17 : L_18 ) ;
}
static T_2 F_36 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_81 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_81 -> V_102 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_81 -> V_107 != V_108 ) )
return - V_109 ;
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
struct V_101 * V_81 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_81 -> V_102 ;
int V_8 = V_2 -> V_8 . V_12 ;
return snprintf ( V_100 , V_104 , L_13 ,
( V_8 == V_69 ) ? L_19 :
( V_8 == V_22 ) ? L_20 : L_21 ) ;
}
static T_2 F_38 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_81 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_81 -> V_102 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_81 -> V_107 != V_108 ) ) {
V_105 = - V_109 ;
goto V_110;
}
if ( V_2 -> V_8 . V_12 == V_13 ) {
V_105 = - V_109 ;
goto V_110;
}
if ( strncmp ( L_19 , V_100 , strlen ( L_19 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_12 = V_69 ;
V_2 -> V_8 . V_111 = V_112 ;
V_2 -> V_8 . V_83 = V_113 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else if ( strncmp ( L_20 , V_100 , strlen ( L_20 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_111 = V_114 ;
V_2 -> V_8 . V_83 = V_84 ;
V_2 -> V_8 . V_12 = V_22 ;
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
struct V_101 * V_81 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_81 -> V_102 ;
enum V_3 V_8 = V_2 -> V_8 . V_16 . V_116 ;
return snprintf ( V_100 , V_104 , L_13 ,
( V_8 == V_117 ) ? L_22 :
( V_8 == V_118 ) ? L_23 : L_24 ) ;
}
static T_2 F_42 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_81 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_81 -> V_102 ;
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
if ( ! ( V_2 -> V_89 & V_106 ) ||
( V_81 -> V_107 == V_108 ) )
F_40 ( V_2 ) ;
V_110:
return V_105 ;
}
static T_2 F_43 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_101 * V_81 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_81 -> V_102 ;
enum V_120 V_121 = V_2 -> V_8 . V_16 . V_122 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_81 -> V_107 != V_108 ) )
return snprintf ( V_100 , V_104 , L_25 ) ;
return snprintf ( V_100 , V_104 , L_13 ,
( V_121 == V_123 ) ? L_14 :
( V_121 == V_124 ) ? L_15 : L_17 ) ;
}
static T_2 F_44 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_101 * V_81 = F_35 ( V_97 ) ;
struct V_1 * V_2 = V_81 -> V_102 ;
enum V_120 V_121 ;
int V_125 = 0 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_81 -> V_107 != V_108 ) )
return - V_109 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_15 , V_100 , strlen ( L_15 ) ) == 0 ) {
V_121 = V_124 ;
} else if ( strncmp ( L_17 , V_100 , strlen ( L_17 ) ) == 0 ) {
V_121 = V_126 ;
} else if ( strncmp ( L_14 , V_100 , strlen ( L_14 ) ) == 0 ) {
V_121 = V_123 ;
} else {
V_105 = - V_109 ;
goto V_110;
}
if ( V_2 -> V_20 -> V_16 . V_127 ) {
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
T_1 V_129 = 0 ;
if ( V_2 -> V_20 -> V_16 . V_130 )
V_129 = V_2 -> V_20 -> V_16 . V_130 ( V_2 ) ;
return sprintf ( V_100 , L_26 , V_129 == V_131 ? 1 : 2 ) ;
}
static T_2 F_47 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 ,
T_3 V_105 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
int V_132 ;
int V_133 ;
if( ! V_2 -> V_20 -> V_16 . V_134 )
return - V_109 ;
V_132 = F_48 ( V_100 , 10 , & V_133 ) ;
if ( V_132 )
return V_132 ;
switch ( V_133 ) {
case 1 :
V_2 -> V_20 -> V_16 . V_134 ( V_2 , V_131 ) ;
break;
default:
V_2 -> V_20 -> V_16 . V_134 ( V_2 , 0 ) ;
break;
}
return V_105 ;
}
static T_2 F_49 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
return sprintf ( V_100 , L_26 , 0 ) ;
}
static T_2 F_50 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
return sprintf ( V_100 , L_26 , 255 ) ;
}
static T_2 F_51 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
const char * V_100 , T_3 V_105 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
int V_132 ;
T_1 V_133 ;
V_132 = F_52 ( V_100 , 10 , & V_133 ) ;
if ( V_132 )
return V_132 ;
V_133 = ( V_133 * 100 ) / 255 ;
V_132 = V_2 -> V_20 -> V_16 . V_135 ( V_2 , V_133 ) ;
if ( V_132 )
return V_132 ;
return V_105 ;
}
static T_2 F_53 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
int V_132 ;
T_1 V_136 ;
V_132 = V_2 -> V_20 -> V_16 . V_137 ( V_2 , & V_136 ) ;
if ( V_132 )
return V_132 ;
V_136 = ( V_136 * 255 ) / 100 ;
return sprintf ( V_100 , L_26 , V_136 ) ;
}
static T_2 F_54 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
struct V_101 * V_81 = V_2 -> V_81 ;
int V_138 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_81 -> V_107 != V_108 ) )
return - V_109 ;
if ( V_2 -> V_20 -> V_8 . V_139 )
V_138 = F_55 ( V_2 ) ;
else
V_138 = 0 ;
return snprintf ( V_100 , V_104 , L_27 , V_138 ) ;
}
static T_2 F_56 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
int V_140 = F_57 ( V_99 ) -> V_141 ;
int V_138 ;
if ( V_140 )
V_138 = V_2 -> V_8 . V_16 . V_142 . V_143 ;
else
V_138 = V_2 -> V_8 . V_16 . V_142 . V_144 ;
return snprintf ( V_100 , V_104 , L_27 , V_138 ) ;
}
static T_4 F_58 ( struct V_145 * V_146 ,
struct V_147 * V_99 , int V_141 )
{
struct V_96 * V_97 = F_59 ( V_146 ) ;
struct V_1 * V_2 = F_35 ( V_97 ) ;
T_4 V_148 = V_99 -> V_149 ;
if ( V_2 -> V_8 . V_12 != V_13 &&
( V_99 == & V_150 . V_151 . V_99 ||
V_99 == & V_152 . V_151 . V_99 ||
V_99 == & V_153 . V_151 . V_99 ||
V_99 == & V_154 . V_151 . V_99 ||
V_99 == & V_155 . V_151 . V_99 ||
V_99 == & V_156 . V_151 . V_99 ) )
return 0 ;
if ( V_2 -> V_8 . V_157 &&
( V_99 == & V_153 . V_151 . V_99 ||
V_99 == & V_154 . V_151 . V_99 ||
V_99 == & V_155 . V_151 . V_99 ||
V_99 == & V_156 . V_151 . V_99 ) )
return 0 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_137 &&
V_99 == & V_153 . V_151 . V_99 ) ||
( ! V_2 -> V_20 -> V_16 . V_130 &&
V_99 == & V_154 . V_151 . V_99 ) )
V_148 &= ~ V_158 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_135 &&
V_99 == & V_153 . V_151 . V_99 ) ||
( ! V_2 -> V_20 -> V_16 . V_134 &&
V_99 == & V_154 . V_151 . V_99 ) )
V_148 &= ~ V_159 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_135 &&
! V_2 -> V_20 -> V_16 . V_137 ) &&
( V_99 == & V_155 . V_151 . V_99 ||
V_99 == & V_156 . V_151 . V_99 ) )
return 0 ;
return V_148 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_132 = 0 ;
switch ( V_2 -> V_8 . V_160 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
if ( V_2 -> V_20 -> V_8 . V_139 == NULL )
return V_132 ;
V_2 -> V_8 . V_169 = F_61 ( V_2 -> V_97 ,
L_28 , V_2 ,
V_170 ) ;
if ( F_62 ( V_2 -> V_8 . V_169 ) ) {
V_132 = F_63 ( V_2 -> V_8 . V_169 ) ;
F_64 ( V_2 -> V_97 ,
L_29 , V_132 ) ;
}
break;
default:
break;
}
return V_132 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_169 )
F_66 ( V_2 -> V_8 . V_169 ) ;
}
static void F_67 ( struct V_171 * V_172 )
{
struct V_1 * V_2 =
F_68 ( V_172 , struct V_1 ,
V_8 . V_16 . V_142 . V_172 ) ;
enum V_3 V_173 = V_174 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_20 -> V_8 . V_139 ) {
int V_138 = F_55 ( V_2 ) ;
if ( V_138 < V_2 -> V_8 . V_16 . V_142 . V_143 )
V_173 = V_2 -> V_8 . V_16 . V_116 ;
} else {
if ( V_2 -> V_8 . V_16 . V_142 . V_175 )
V_173 = V_2 -> V_8 . V_16 . V_116 ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_173 == V_174 )
V_2 -> V_8 . V_16 . V_128 = true ;
else
V_2 -> V_8 . V_16 . V_128 = false ;
V_2 -> V_8 . V_16 . V_176 = V_173 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static bool F_69 ( struct V_1 * V_2 )
{
bool V_177 = ( V_2 -> V_8 . V_16 . V_178 < 2 ) ?
true : false ;
if ( V_177 && V_2 -> V_20 -> V_16 . V_179 ) {
if ( F_70 ( V_2 ) )
V_177 = false ;
}
if ( V_177 && ( F_71 ( V_2 ) >= 120 ) )
V_177 = false ;
return V_177 ;
}
static struct V_180 * F_72 ( struct V_1 * V_2 ,
enum V_3 V_173 )
{
int V_6 ;
struct V_180 * V_181 ;
T_1 V_182 ;
bool V_177 = F_69 ( V_2 ) ;
if ( V_173 == V_119 )
V_173 = V_183 ;
if ( V_173 == V_118 )
V_173 = V_119 ;
V_184:
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_185 ; V_6 ++ ) {
V_181 = & V_2 -> V_8 . V_16 . V_181 [ V_6 ] ;
V_182 = V_181 -> V_186 & V_187 ;
switch ( V_173 ) {
case V_117 :
if ( V_182 == V_188 ) {
if ( V_181 -> V_189 & V_190 ) {
if ( V_177 )
return V_181 ;
} else
return V_181 ;
}
break;
case V_118 :
if ( V_182 == V_191 ) {
if ( V_181 -> V_189 & V_190 ) {
if ( V_177 )
return V_181 ;
} else
return V_181 ;
}
break;
case V_119 :
if ( V_182 == V_192 ) {
if ( V_181 -> V_189 & V_190 ) {
if ( V_177 )
return V_181 ;
} else
return V_181 ;
}
break;
case V_193 :
if ( V_2 -> V_8 . V_16 . V_194 )
return V_2 -> V_8 . V_16 . V_194 ;
else
break;
case V_195 :
if ( V_181 -> V_186 & V_196 )
return V_181 ;
break;
case V_197 :
if ( V_181 -> V_186 & V_198 )
return V_181 ;
break;
case V_199 :
if ( V_181 -> V_186 & V_200 )
return V_181 ;
break;
case V_201 :
if ( V_181 -> V_202 & V_203 )
return V_181 ;
break;
case V_204 :
return V_2 -> V_8 . V_16 . V_205 ;
case V_174 :
if ( V_181 -> V_186 & V_206 )
return V_181 ;
break;
case V_207 :
if ( V_181 -> V_186 & V_208 )
return V_181 ;
break;
case V_209 :
if ( V_181 -> V_202 & V_210 )
return V_181 ;
break;
case V_183 :
if ( V_181 -> V_186 & V_211 )
return V_181 ;
break;
default:
break;
}
}
switch ( V_173 ) {
case V_195 :
V_173 = V_197 ;
goto V_184;
case V_197 :
case V_199 :
case V_201 :
if ( V_2 -> V_8 . V_16 . V_194 ) {
return V_2 -> V_8 . V_16 . V_194 ;
} else {
V_173 = V_119 ;
goto V_184;
}
case V_174 :
V_173 = V_207 ;
goto V_184;
case V_207 :
V_173 = V_117 ;
goto V_184;
case V_117 :
case V_118 :
case V_183 :
V_173 = V_119 ;
goto V_184;
default:
break;
}
return NULL ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_180 * V_181 ;
enum V_3 V_173 ;
int V_125 ;
bool V_177 = F_69 ( V_2 ) ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_8 . V_16 . V_116 != V_2 -> V_8 . V_16 . V_176 ) {
if ( ( ! V_2 -> V_8 . V_16 . V_128 ) &&
( ! V_2 -> V_8 . V_16 . V_212 ) )
V_2 -> V_8 . V_16 . V_176 = V_2 -> V_8 . V_16 . V_116 ;
}
V_173 = V_2 -> V_8 . V_16 . V_176 ;
V_181 = F_72 ( V_2 , V_173 ) ;
if ( V_181 )
V_2 -> V_8 . V_16 . V_213 = V_181 ;
else
return;
if ( V_2 -> V_8 . V_16 . V_214 == V_2 -> V_8 . V_16 . V_213 ) {
if ( V_181 -> V_215 != V_2 -> V_8 . V_16 . V_215 )
goto V_216;
if ( V_2 -> V_8 . V_16 . V_177 != V_177 )
goto V_216;
if ( ( V_2 -> V_18 < V_66 ) || ( V_2 -> V_89 & V_91 ) ) {
if ( V_2 -> V_8 . V_16 . V_217 != V_2 -> V_8 . V_16 . V_218 ) {
F_32 ( V_2 ) ;
F_74 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_218 = V_2 -> V_8 . V_16 . V_217 ;
V_2 -> V_8 . V_16 . V_219 = V_2 -> V_8 . V_16 . V_178 ;
}
return;
} else {
if ( V_2 -> V_8 . V_16 . V_217 ==
V_2 -> V_8 . V_16 . V_218 ) {
return;
} else {
if ( ( V_2 -> V_8 . V_16 . V_219 > 1 ) &&
( V_2 -> V_8 . V_16 . V_178 > 1 ) ) {
F_32 ( V_2 ) ;
F_74 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_218 = V_2 -> V_8 . V_16 . V_217 ;
V_2 -> V_8 . V_16 . V_219 = V_2 -> V_8 . V_16 . V_178 ;
return;
}
}
}
}
V_216:
if ( V_220 == 1 ) {
F_75 ( L_30 ) ;
F_76 ( V_2 , V_2 -> V_8 . V_16 . V_214 ) ;
F_75 ( L_31 ) ;
F_76 ( V_2 , V_2 -> V_8 . V_16 . V_213 ) ;
}
F_26 ( & V_2 -> V_8 . V_73 ) ;
F_3 ( & V_2 -> V_74 ) ;
V_181 -> V_215 = V_2 -> V_8 . V_16 . V_215 ;
V_125 = F_77 ( V_2 ) ;
if ( V_125 )
goto V_221;
F_32 ( V_2 ) ;
F_74 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_75 ; V_6 ++ ) {
struct V_76 * V_77 = & V_2 -> V_77 [ V_6 ] ;
if ( V_77 -> V_78 )
F_27 ( V_2 , V_6 ) ;
}
F_78 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_213 ;
F_79 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_218 = V_2 -> V_8 . V_16 . V_217 ;
V_2 -> V_8 . V_16 . V_219 = V_2 -> V_8 . V_16 . V_178 ;
V_2 -> V_8 . V_16 . V_177 = V_177 ;
if ( V_2 -> V_20 -> V_16 . V_127 ) {
if ( V_2 -> V_8 . V_16 . V_128 ) {
enum V_120 V_121 = V_2 -> V_8 . V_16 . V_122 ;
F_45 ( V_2 , V_124 ) ;
V_2 -> V_8 . V_16 . V_122 = V_121 ;
} else {
F_45 ( V_2 , V_2 -> V_8 . V_16 . V_122 ) ;
}
}
V_221:
F_6 ( & V_2 -> V_74 ) ;
F_28 ( & V_2 -> V_8 . V_73 ) ;
}
void F_80 ( struct V_1 * V_2 , bool V_222 )
{
enum V_3 V_173 ;
if ( V_2 -> V_20 -> V_16 . V_223 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_222 |= V_2 -> V_8 . V_16 . V_224 > 0 ;
V_222 |= V_2 -> V_8 . V_16 . V_225 > 0 ;
F_81 ( V_2 , ! V_222 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
if ( V_222 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_212 = true ;
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
V_173 = V_193 ;
V_2 -> V_8 . V_16 . V_176 = V_173 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_212 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_40 ( V_2 ) ;
}
}
void F_82 ( struct V_1 * V_2 , bool V_222 )
{
if ( V_222 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_215 = true ;
V_2 -> V_8 . V_16 . V_226 = V_227 ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_215 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
F_40 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_69 ) {
if ( V_2 -> V_8 . V_111 == V_228 )
V_2 -> V_8 . V_111 = V_229 ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_115 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_85 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_213 = V_2 -> V_8 . V_16 . V_205 ;
V_2 -> V_8 . V_14 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_84 ( V_2 ) ;
else
F_83 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_230 ) &&
V_2 -> V_231 ) {
if ( V_2 -> V_8 . V_232 )
F_88 ( V_2 , V_2 -> V_8 . V_232 ,
V_233 ) ;
if ( V_2 -> V_8 . V_234 )
F_88 ( V_2 , V_2 -> V_8 . V_234 ,
V_235 ) ;
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
V_2 -> V_8 . V_236 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_64 [ 0 ] . V_95 . V_95 ;
V_2 -> V_8 . V_237 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_64 [ 0 ] . V_95 . V_238 ;
}
if ( V_2 -> V_8 . V_12 == V_69
&& V_2 -> V_8 . V_111 == V_229 ) {
V_2 -> V_8 . V_111 = V_228 ;
F_89 ( & V_2 -> V_8 . V_115 ,
F_15 ( V_239 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
int V_125 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_213 = V_2 -> V_8 . V_16 . V_205 ;
F_91 ( V_2 ) ;
V_125 = F_92 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_125 )
goto V_240;
V_2 -> V_8 . V_14 = true ;
return;
V_240:
F_93 ( L_32 ) ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_230 ) &&
V_2 -> V_231 ) {
if ( V_2 -> V_8 . V_232 )
F_88 ( V_2 , V_2 -> V_8 . V_232 ,
V_233 ) ;
if ( V_2 -> V_8 . V_234 )
F_88 ( V_2 , V_2 -> V_8 . V_234 ,
V_235 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
}
void F_94 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_90 ( V_2 ) ;
else
F_87 ( V_2 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_125 ;
V_2 -> V_8 . V_23 = V_25 ;
V_2 -> V_8 . V_111 = V_114 ;
V_2 -> V_8 . V_83 = V_84 ;
V_2 -> V_8 . V_241 = true ;
V_2 -> V_8 . V_242 = true ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_71 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_160 = V_243 ;
if ( V_2 -> V_244 ) {
if ( V_2 -> V_245 )
F_96 ( V_2 ) ;
else
F_97 ( V_2 ) ;
F_33 ( V_2 ) ;
F_98 ( V_2 ) ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_230 ) &&
V_2 -> V_231 ) {
if ( V_2 -> V_8 . V_232 )
F_88 ( V_2 , V_2 -> V_8 . V_232 ,
V_233 ) ;
if ( V_2 -> V_8 . V_234 )
F_88 ( V_2 , V_2 -> V_8 . V_234 ,
V_235 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
}
V_125 = F_60 ( V_2 ) ;
if ( V_125 )
return V_125 ;
F_99 ( & V_2 -> V_8 . V_115 , V_246 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
if ( F_100 ( V_2 ) ) {
F_93 ( L_33 ) ;
}
F_101 ( L_34 ) ;
}
return 0 ;
}
static void F_102 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_185 ; V_6 ++ ) {
F_75 ( L_35 , V_6 ) ;
F_76 ( V_2 , & V_2 -> V_8 . V_16 . V_181 [ V_6 ] ) ;
}
}
static int F_103 ( struct V_1 * V_2 )
{
int V_125 ;
V_2 -> V_8 . V_16 . V_176 = V_118 ;
V_2 -> V_8 . V_16 . V_116 = V_118 ;
V_2 -> V_8 . V_16 . V_122 = V_123 ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_71 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_160 = V_243 ;
if ( V_2 -> V_244 && V_2 -> V_245 )
F_96 ( V_2 ) ;
else
return - V_109 ;
V_125 = F_60 ( V_2 ) ;
if ( V_125 )
return V_125 ;
F_104 ( & V_2 -> V_8 . V_16 . V_142 . V_172 , F_67 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_105 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_213 = V_2 -> V_8 . V_16 . V_205 ;
if ( V_220 == 1 )
F_102 ( V_2 ) ;
F_91 ( V_2 ) ;
V_125 = F_92 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_125 )
goto V_247;
V_2 -> V_8 . V_14 = true ;
if ( F_100 ( V_2 ) ) {
F_93 ( L_36 ) ;
}
F_101 ( L_37 ) ;
return 0 ;
V_247:
V_2 -> V_8 . V_14 = false ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_230 ) &&
V_2 -> V_231 ) {
if ( V_2 -> V_8 . V_232 )
F_88 ( V_2 , V_2 -> V_8 . V_232 ,
V_233 ) ;
if ( V_2 -> V_8 . V_234 )
F_88 ( V_2 , V_2 -> V_8 . V_234 ,
V_235 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
F_93 ( L_38 ) ;
return V_125 ;
}
int F_106 ( struct V_1 * V_2 )
{
struct V_248 * V_249 = V_250 ;
bool V_251 = false ;
while ( V_249 && V_249 -> V_252 != 0 ) {
if ( V_2 -> V_253 -> V_254 == V_249 -> V_255 &&
V_2 -> V_253 -> V_96 == V_249 -> V_252 &&
V_2 -> V_253 -> V_256 == V_249 -> V_257 &&
V_2 -> V_253 -> V_258 == V_249 -> V_259 ) {
V_251 = true ;
break;
}
++ V_249 ;
}
switch ( V_2 -> V_18 ) {
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
if ( ! V_2 -> V_268 )
V_2 -> V_8 . V_12 = V_22 ;
else if ( ( V_2 -> V_18 >= V_267 ) &&
( ! ( V_2 -> V_89 & V_91 ) ) &&
( ! V_2 -> V_269 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_220 == 1 )
V_2 -> V_8 . V_12 = V_13 ;
else
V_2 -> V_8 . V_12 = V_22 ;
break;
case V_270 :
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
case V_66 :
case V_281 :
case V_282 :
case V_230 :
case V_19 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
if ( ! V_2 -> V_268 )
V_2 -> V_8 . V_12 = V_22 ;
else if ( ( V_2 -> V_18 >= V_267 ) &&
( ! ( V_2 -> V_89 & V_91 ) ) &&
( ! V_2 -> V_269 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_251 && ( V_220 == - 1 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_220 == 0 )
V_2 -> V_8 . V_12 = V_22 ;
else
V_2 -> V_8 . V_12 = V_13 ;
break;
default:
V_2 -> V_8 . V_12 = V_22 ;
break;
}
if ( V_2 -> V_8 . V_12 == V_13 )
return F_103 ( V_2 ) ;
else
return F_95 ( V_2 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_125 = 0 ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
if ( V_2 -> V_8 . V_14 ) {
if ( ! V_2 -> V_8 . V_293 ) {
V_125 = F_108 ( V_2 -> V_97 , & V_294 ) ;
if ( V_125 )
F_93 ( L_39 ) ;
V_125 = F_108 ( V_2 -> V_97 , & V_295 ) ;
if ( V_125 )
F_93 ( L_39 ) ;
V_125 = F_108 ( V_2 -> V_97 , & V_296 ) ;
if ( V_125 )
F_93 ( L_40 ) ;
V_125 = F_108 ( V_2 -> V_97 , & V_297 ) ;
if ( V_125 )
F_93 ( L_41 ) ;
V_2 -> V_8 . V_293 = true ;
}
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_125 = F_109 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_125 ) {
V_2 -> V_8 . V_14 = false ;
F_93 ( L_42 ) ;
} else {
F_40 ( V_2 ) ;
}
}
} else {
if ( ( V_2 -> V_8 . V_9 > 1 ) &&
( ! V_2 -> V_8 . V_293 ) ) {
V_125 = F_108 ( V_2 -> V_97 , & V_296 ) ;
if ( V_125 )
F_93 ( L_40 ) ;
V_125 = F_108 ( V_2 -> V_97 , & V_297 ) ;
if ( V_125 )
F_93 ( L_41 ) ;
if ( ! V_125 )
V_2 -> V_8 . V_293 = true ;
}
}
return V_125 ;
}
static void F_110 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_22 ) {
V_2 -> V_8 . V_23 = V_25 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_69 ) {
V_2 -> V_8 . V_111 = V_114 ;
V_2 -> V_8 . V_83 = V_113 ;
F_8 ( V_2 ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_115 ) ;
F_111 ( V_2 -> V_97 , & V_296 ) ;
F_111 ( V_2 -> V_97 , & V_297 ) ;
}
F_65 ( V_2 ) ;
F_112 ( V_2 -> V_8 . V_10 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_85 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_111 ( V_2 -> V_97 , & V_294 ) ;
F_111 ( V_2 -> V_97 , & V_295 ) ;
F_111 ( V_2 -> V_97 , & V_296 ) ;
F_111 ( V_2 -> V_97 , & V_297 ) ;
}
F_114 ( V_2 ) ;
F_65 ( V_2 ) ;
F_112 ( V_2 -> V_8 . V_10 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_113 ( V_2 ) ;
else
F_110 ( V_2 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_101 * V_81 = V_2 -> V_81 ;
struct V_298 * V_299 ;
struct V_300 * V_300 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_54 = 0 ;
V_2 -> V_8 . V_28 = 0 ;
if ( V_2 -> V_80 && V_2 -> V_301 . V_302 ) {
F_117 (crtc,
&ddev->mode_config.crtc_list, head) {
V_300 = F_118 ( V_299 ) ;
if ( V_300 -> V_303 ) {
V_2 -> V_8 . V_54 |= ( 1 << V_300 -> V_304 ) ;
V_2 -> V_8 . V_28 ++ ;
}
}
}
if ( V_2 -> V_8 . V_12 == V_22 ) {
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_69 ) {
if ( V_2 -> V_8 . V_111 != V_114 ) {
if ( V_2 -> V_8 . V_28 > 1 ) {
if ( V_2 -> V_8 . V_111 == V_228 ) {
F_119 ( & V_2 -> V_8 . V_115 ) ;
V_2 -> V_8 . V_111 = V_112 ;
V_2 -> V_8 . V_83 = V_113 ;
F_120 ( V_2 ) ;
F_8 ( V_2 ) ;
F_23 ( L_43 ) ;
}
} else if ( V_2 -> V_8 . V_28 == 1 ) {
if ( V_2 -> V_8 . V_111 == V_305 ) {
V_2 -> V_8 . V_111 = V_228 ;
V_2 -> V_8 . V_83 = V_306 ;
F_120 ( V_2 ) ;
F_8 ( V_2 ) ;
F_89 ( & V_2 -> V_8 . V_115 ,
F_15 ( V_239 ) ) ;
} else if ( V_2 -> V_8 . V_111 == V_112 ) {
V_2 -> V_8 . V_111 = V_228 ;
F_89 ( & V_2 -> V_8 . V_115 ,
F_15 ( V_239 ) ) ;
F_23 ( L_44 ) ;
}
} else {
if ( V_2 -> V_8 . V_111 != V_305 ) {
F_119 ( & V_2 -> V_8 . V_115 ) ;
V_2 -> V_8 . V_111 = V_305 ;
V_2 -> V_8 . V_83 = V_307 ;
F_120 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_101 * V_81 = V_2 -> V_81 ;
struct V_298 * V_299 ;
struct V_300 * V_300 ;
if ( ! V_2 -> V_8 . V_14 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_217 = 0 ;
V_2 -> V_8 . V_16 . V_178 = 0 ;
if ( V_2 -> V_80 && V_2 -> V_301 . V_302 ) {
F_117 (crtc,
&ddev->mode_config.crtc_list, head) {
V_300 = F_118 ( V_299 ) ;
if ( V_299 -> V_303 ) {
V_2 -> V_8 . V_16 . V_217 |= ( 1 << V_300 -> V_304 ) ;
V_2 -> V_8 . V_16 . V_178 ++ ;
}
}
}
if ( F_4 () > 0 )
V_2 -> V_8 . V_16 . V_17 = true ;
else
V_2 -> V_8 . V_16 . V_17 = false ;
F_73 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_121 ( V_2 ) ;
else
F_116 ( V_2 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
int V_299 , V_308 , V_309 , V_310 ;
bool V_311 = true ;
for ( V_299 = 0 ; ( V_299 < V_2 -> V_80 ) && V_311 ; V_299 ++ ) {
if ( V_2 -> V_8 . V_54 & ( 1 << V_299 ) ) {
V_310 = F_122 ( V_2 -> V_81 ,
V_299 ,
V_312 ,
& V_308 , & V_309 , NULL , NULL ,
& V_2 -> V_301 . V_313 [ V_299 ] -> V_314 . V_315 ) ;
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
static void V_246 ( struct V_171 * V_172 )
{
struct V_1 * V_2 ;
int V_320 ;
V_2 = F_68 ( V_172 , struct V_1 ,
V_8 . V_115 . V_172 ) ;
V_320 = F_123 ( & V_2 -> V_321 . V_322 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_111 == V_228 ) {
int V_323 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_75 ; ++ V_6 ) {
struct V_76 * V_77 = & V_2 -> V_77 [ V_6 ] ;
if ( V_77 -> V_78 ) {
V_323 += F_124 ( V_2 , V_6 ) ;
if ( V_323 >= 3 )
break;
}
}
if ( V_323 >= 3 ) {
if ( V_2 -> V_8 . V_83 == V_324 ) {
V_2 -> V_8 . V_83 = V_84 ;
} else if ( V_2 -> V_8 . V_83 == V_84 &&
V_2 -> V_8 . V_241 ) {
V_2 -> V_8 . V_83 =
V_306 ;
V_2 -> V_8 . V_325 = V_326 +
F_15 ( V_327 ) ;
}
} else if ( V_323 == 0 ) {
if ( V_2 -> V_8 . V_83 == V_306 ) {
V_2 -> V_8 . V_83 = V_84 ;
} else if ( V_2 -> V_8 . V_83 == V_84 &&
V_2 -> V_8 . V_242 ) {
V_2 -> V_8 . V_83 =
V_324 ;
V_2 -> V_8 . V_325 = V_326 +
F_15 ( V_327 ) ;
}
}
if ( V_2 -> V_8 . V_83 != V_84 &&
V_326 > V_2 -> V_8 . V_325 ) {
F_120 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_89 ( & V_2 -> V_8 . V_115 ,
F_15 ( V_239 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_125 ( & V_2 -> V_321 . V_322 , V_320 ) ;
}
static int F_126 ( struct V_328 * V_329 , void * V_330 )
{
struct V_331 * V_332 = (struct V_331 * ) V_329 -> V_333 ;
struct V_101 * V_97 = V_332 -> V_334 -> V_97 ;
struct V_1 * V_2 = V_97 -> V_102 ;
struct V_101 * V_81 = V_2 -> V_81 ;
if ( ( V_2 -> V_89 & V_106 ) &&
( V_81 -> V_107 != V_108 ) ) {
F_127 ( V_329 , L_48 ) ;
} else if ( V_2 -> V_8 . V_14 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_20 -> V_16 . V_335 )
F_128 ( V_2 , V_329 ) ;
else
F_127 ( V_329 , L_49 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_127 ( V_329 , L_50 , V_2 -> V_8 . V_65 ) ;
if ( ( V_2 -> V_18 >= V_278 ) && ( V_2 -> V_89 & V_91 ) )
F_127 ( V_329 , L_51 , V_2 -> V_8 . V_68 ) ;
else
F_127 ( V_329 , L_51 , F_129 ( V_2 ) ) ;
F_127 ( V_329 , L_52 , V_2 -> V_8 . V_67 ) ;
if ( V_2 -> V_20 -> V_8 . V_336 )
F_127 ( V_329 , L_53 , F_130 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_236 )
F_127 ( V_329 , L_54 , V_2 -> V_8 . V_236 ) ;
if ( V_2 -> V_20 -> V_8 . V_337 )
F_127 ( V_329 , L_55 , F_131 ( V_2 ) ) ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
#if F_132 ( V_338 )
return F_133 ( V_2 , V_339 , F_134 ( V_339 ) ) ;
#else
return 0 ;
#endif
}
