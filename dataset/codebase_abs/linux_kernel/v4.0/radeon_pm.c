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
return snprintf ( V_101 , V_105 , L_12 ,
( V_8 == V_118 ) ? L_21 :
( V_8 == V_119 ) ? L_22 : L_23 ) ;
}
static T_2 F_42 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_101 ,
T_3 V_106 )
{
struct V_102 * V_73 = F_35 ( V_98 ) ;
struct V_1 * V_2 = V_73 -> V_103 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( strncmp ( L_21 , V_101 , strlen ( L_21 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_118 ;
else if ( strncmp ( L_22 , V_101 , strlen ( L_22 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_119 ;
else if ( strncmp ( L_23 , V_101 , strlen ( L_23 ) ) == 0 )
V_2 -> V_8 . V_16 . V_117 = V_120 ;
else {
F_6 ( & V_2 -> V_8 . V_15 ) ;
V_106 = - V_110 ;
goto V_111;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( ! ( V_2 -> V_90 & V_107 ) ||
( V_73 -> V_108 == V_109 ) )
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
return snprintf ( V_101 , V_105 , L_24 ) ;
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
T_1 V_130 = 0 ;
if ( V_2 -> V_20 -> V_16 . V_131 )
V_130 = V_2 -> V_20 -> V_16 . V_131 ( V_2 ) ;
return sprintf ( V_101 , L_25 , V_130 == V_132 ? 1 : 2 ) ;
}
static T_2 F_47 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_101 ,
T_3 V_106 )
{
struct V_1 * V_2 = F_35 ( V_98 ) ;
int V_133 ;
int V_134 ;
if( ! V_2 -> V_20 -> V_16 . V_135 )
return - V_110 ;
V_133 = F_48 ( V_101 , 10 , & V_134 ) ;
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
static T_2 F_49 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
return sprintf ( V_101 , L_25 , 0 ) ;
}
static T_2 F_50 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
return sprintf ( V_101 , L_25 , 255 ) ;
}
static T_2 F_51 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_101 , T_3 V_106 )
{
struct V_1 * V_2 = F_35 ( V_98 ) ;
int V_133 ;
T_1 V_134 ;
V_133 = F_52 ( V_101 , 10 , & V_134 ) ;
if ( V_133 )
return V_133 ;
V_134 = ( V_134 * 100 ) / 255 ;
V_133 = V_2 -> V_20 -> V_16 . V_136 ( V_2 , V_134 ) ;
if ( V_133 )
return V_133 ;
return V_106 ;
}
static T_2 F_53 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_1 * V_2 = F_35 ( V_98 ) ;
int V_133 ;
T_1 V_137 ;
V_133 = V_2 -> V_20 -> V_16 . V_138 ( V_2 , & V_137 ) ;
if ( V_133 )
return V_133 ;
V_137 = ( V_137 * 255 ) / 100 ;
return sprintf ( V_101 , L_25 , V_137 ) ;
}
static T_2 F_54 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_1 * V_2 = F_35 ( V_98 ) ;
struct V_102 * V_73 = V_2 -> V_73 ;
int V_139 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) )
return - V_110 ;
if ( V_2 -> V_20 -> V_8 . V_140 )
V_139 = F_55 ( V_2 ) ;
else
V_139 = 0 ;
return snprintf ( V_101 , V_105 , L_26 , V_139 ) ;
}
static T_2 F_56 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_1 * V_2 = F_35 ( V_98 ) ;
int V_141 = F_57 ( V_100 ) -> V_142 ;
int V_139 ;
if ( V_141 )
V_139 = V_2 -> V_8 . V_16 . V_143 . V_144 ;
else
V_139 = V_2 -> V_8 . V_16 . V_143 . V_145 ;
return snprintf ( V_101 , V_105 , L_26 , V_139 ) ;
}
static T_4 F_58 ( struct V_146 * V_147 ,
struct V_148 * V_100 , int V_142 )
{
struct V_97 * V_98 = F_59 ( V_147 , struct V_97 , V_147 ) ;
struct V_1 * V_2 = F_35 ( V_98 ) ;
T_4 V_149 = V_100 -> V_150 ;
if ( V_2 -> V_8 . V_12 != V_13 &&
( V_100 == & V_151 . V_152 . V_100 ||
V_100 == & V_153 . V_152 . V_100 ) )
return 0 ;
if ( V_2 -> V_8 . V_154 &&
( V_100 == & V_155 . V_152 . V_100 ||
V_100 == & V_156 . V_152 . V_100 ||
V_100 == & V_157 . V_152 . V_100 ||
V_100 == & V_158 . V_152 . V_100 ) )
return 0 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_138 &&
V_100 == & V_155 . V_152 . V_100 ) ||
( ! V_2 -> V_20 -> V_16 . V_131 &&
V_100 == & V_156 . V_152 . V_100 ) )
V_149 &= ~ V_159 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_136 &&
V_100 == & V_155 . V_152 . V_100 ) ||
( ! V_2 -> V_20 -> V_16 . V_135 &&
V_100 == & V_156 . V_152 . V_100 ) )
V_149 &= ~ V_160 ;
if ( ( ! V_2 -> V_20 -> V_16 . V_136 &&
! V_2 -> V_20 -> V_16 . V_138 ) &&
( V_100 == & V_157 . V_152 . V_100 ||
V_100 == & V_158 . V_152 . V_100 ) )
return 0 ;
return V_149 ;
}
static int F_60 ( struct V_1 * V_2 )
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
V_2 -> V_8 . V_170 = F_61 ( V_2 -> V_98 ,
L_27 , V_2 ,
V_171 ) ;
if ( F_62 ( V_2 -> V_8 . V_170 ) ) {
V_133 = F_63 ( V_2 -> V_8 . V_170 ) ;
F_64 ( V_2 -> V_98 ,
L_28 , V_133 ) ;
}
break;
default:
break;
}
return V_133 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_170 )
F_66 ( V_2 -> V_8 . V_170 ) ;
}
static void F_67 ( struct V_172 * V_173 )
{
struct V_1 * V_2 =
F_59 ( V_173 , struct V_1 ,
V_8 . V_16 . V_143 . V_173 ) ;
enum V_3 V_174 = V_175 ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_20 -> V_8 . V_140 ) {
int V_139 = F_55 ( V_2 ) ;
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
F_40 ( V_2 ) ;
}
static bool F_68 ( struct V_1 * V_2 )
{
bool V_178 = ( V_2 -> V_8 . V_16 . V_179 < 2 ) ?
true : false ;
if ( V_178 && V_2 -> V_20 -> V_16 . V_180 ) {
if ( F_69 ( V_2 ) )
V_178 = false ;
}
if ( V_178 && ( F_70 ( V_2 ) >= 120 ) )
V_178 = false ;
return V_178 ;
}
static struct V_181 * F_71 ( struct V_1 * V_2 ,
enum V_3 V_174 )
{
int V_6 ;
struct V_181 * V_182 ;
T_1 V_183 ;
bool V_178 = F_68 ( V_2 ) ;
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
static void F_72 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_181 * V_182 ;
enum V_3 V_174 ;
int V_126 ;
bool V_178 = F_68 ( V_2 ) ;
if ( ! V_2 -> V_8 . V_14 )
return;
if ( V_2 -> V_8 . V_16 . V_117 != V_2 -> V_8 . V_16 . V_177 ) {
if ( ( ! V_2 -> V_8 . V_16 . V_129 ) &&
( ! V_2 -> V_8 . V_16 . V_213 ) )
V_2 -> V_8 . V_16 . V_177 = V_2 -> V_8 . V_16 . V_117 ;
}
V_174 = V_2 -> V_8 . V_16 . V_177 ;
V_182 = F_71 ( V_2 , V_174 ) ;
if ( V_182 )
V_2 -> V_8 . V_16 . V_214 = V_182 ;
else
return;
if ( V_2 -> V_8 . V_16 . V_215 == V_2 -> V_8 . V_16 . V_214 ) {
if ( V_182 -> V_216 != V_2 -> V_8 . V_16 . V_216 )
goto V_217;
if ( V_2 -> V_8 . V_16 . V_178 != V_178 )
goto V_217;
if ( ( V_2 -> V_18 < V_66 ) || ( V_2 -> V_90 & V_92 ) ) {
if ( V_2 -> V_8 . V_16 . V_218 != V_2 -> V_8 . V_16 . V_219 ) {
F_32 ( V_2 ) ;
F_73 ( V_2 ) ;
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
F_32 ( V_2 ) ;
F_73 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_219 = V_2 -> V_8 . V_16 . V_218 ;
V_2 -> V_8 . V_16 . V_220 = V_2 -> V_8 . V_16 . V_179 ;
return;
}
}
}
}
V_217:
if ( V_221 == 1 ) {
F_74 ( L_29 ) ;
F_75 ( V_2 , V_2 -> V_8 . V_16 . V_215 ) ;
F_74 ( L_30 ) ;
F_75 ( V_2 , V_2 -> V_8 . V_16 . V_214 ) ;
}
F_3 ( & V_2 -> V_73 -> V_74 ) ;
F_26 ( & V_2 -> V_8 . V_75 ) ;
F_3 ( & V_2 -> V_76 ) ;
V_182 -> V_216 = V_2 -> V_8 . V_16 . V_216 ;
V_126 = F_76 ( V_2 ) ;
if ( V_126 )
goto V_222;
F_32 ( V_2 ) ;
F_73 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_219 = V_2 -> V_8 . V_16 . V_218 ;
V_2 -> V_8 . V_16 . V_220 = V_2 -> V_8 . V_16 . V_179 ;
V_2 -> V_8 . V_16 . V_178 = V_178 ;
for ( V_6 = 0 ; V_6 < V_77 ; V_6 ++ ) {
struct V_78 * V_79 = & V_2 -> V_79 [ V_6 ] ;
if ( V_79 -> V_80 )
F_27 ( V_2 , V_6 ) ;
}
F_77 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_215 = V_2 -> V_8 . V_16 . V_214 ;
F_78 ( V_2 ) ;
if ( V_2 -> V_20 -> V_16 . V_128 ) {
if ( V_2 -> V_8 . V_16 . V_129 ) {
enum V_121 V_122 = V_2 -> V_8 . V_16 . V_123 ;
F_45 ( V_2 , V_125 ) ;
V_2 -> V_8 . V_16 . V_123 = V_122 ;
} else {
F_45 ( V_2 , V_2 -> V_8 . V_16 . V_123 ) ;
}
}
V_222:
F_6 ( & V_2 -> V_76 ) ;
F_28 ( & V_2 -> V_8 . V_75 ) ;
F_6 ( & V_2 -> V_73 -> V_74 ) ;
}
void F_79 ( struct V_1 * V_2 , bool V_223 )
{
enum V_3 V_174 ;
if ( V_2 -> V_20 -> V_16 . V_224 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_223 |= V_2 -> V_8 . V_16 . V_225 > 0 ;
V_223 |= V_2 -> V_8 . V_16 . V_226 > 0 ;
F_80 ( V_2 , ! V_223 ) ;
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
F_40 ( V_2 ) ;
}
}
void F_81 ( struct V_1 * V_2 , bool V_223 )
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
F_40 ( V_2 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_12 == V_69 ) {
if ( V_2 -> V_8 . V_112 == V_229 )
V_2 -> V_8 . V_112 = V_230 ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_39 ( & V_2 -> V_8 . V_116 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_84 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_215 = V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_206 ;
V_2 -> V_8 . V_14 = false ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_83 ( V_2 ) ;
else
F_82 ( V_2 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_231 ) &&
V_2 -> V_232 ) {
if ( V_2 -> V_8 . V_233 )
F_87 ( V_2 , V_2 -> V_8 . V_233 ,
V_234 ) ;
if ( V_2 -> V_8 . V_235 )
F_87 ( V_2 , V_2 -> V_8 . V_235 ,
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
V_2 -> V_8 . V_237 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_64 [ 0 ] . V_96 . V_96 ;
V_2 -> V_8 . V_238 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_64 [ 0 ] . V_96 . V_239 ;
}
if ( V_2 -> V_8 . V_12 == V_69
&& V_2 -> V_8 . V_112 == V_230 ) {
V_2 -> V_8 . V_112 = V_229 ;
F_88 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_240 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_40 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_126 ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_215 = V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_206 ;
F_90 ( V_2 ) ;
V_126 = F_91 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_126 )
goto V_241;
V_2 -> V_8 . V_14 = true ;
return;
V_241:
F_92 ( L_31 ) ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_231 ) &&
V_2 -> V_232 ) {
if ( V_2 -> V_8 . V_233 )
F_87 ( V_2 , V_2 -> V_8 . V_233 ,
V_234 ) ;
if ( V_2 -> V_8 . V_235 )
F_87 ( V_2 , V_2 -> V_8 . V_235 ,
V_236 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
}
void F_93 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_89 ( V_2 ) ;
else
F_86 ( V_2 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_126 ;
V_2 -> V_8 . V_23 = V_25 ;
V_2 -> V_8 . V_112 = V_115 ;
V_2 -> V_8 . V_84 = V_85 ;
V_2 -> V_8 . V_242 = true ;
V_2 -> V_8 . V_243 = true ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_67 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_68 = V_2 -> clock . V_65 ;
V_2 -> V_8 . V_71 = V_2 -> clock . V_67 ;
V_2 -> V_8 . V_161 = V_244 ;
if ( V_2 -> V_245 ) {
if ( V_2 -> V_246 )
F_95 ( V_2 ) ;
else
F_96 ( V_2 ) ;
F_33 ( V_2 ) ;
F_97 ( V_2 ) ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_231 ) &&
V_2 -> V_232 ) {
if ( V_2 -> V_8 . V_233 )
F_87 ( V_2 , V_2 -> V_8 . V_233 ,
V_234 ) ;
if ( V_2 -> V_8 . V_235 )
F_87 ( V_2 , V_2 -> V_8 . V_235 ,
V_236 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
}
V_126 = F_60 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_98 ( & V_2 -> V_8 . V_116 , V_247 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_126 = F_99 ( V_2 -> V_98 , & V_248 ) ;
if ( V_126 )
F_92 ( L_32 ) ;
V_126 = F_99 ( V_2 -> V_98 , & V_249 ) ;
if ( V_126 )
F_92 ( L_33 ) ;
if ( F_100 ( V_2 ) ) {
F_92 ( L_34 ) ;
}
F_101 ( L_35 ) ;
}
return 0 ;
}
static void F_102 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_8 . V_16 . V_186 ; V_6 ++ ) {
F_74 ( L_36 , V_6 ) ;
F_75 ( V_2 , & V_2 -> V_8 . V_16 . V_182 [ V_6 ] ) ;
}
}
static int F_103 ( struct V_1 * V_2 )
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
F_95 ( V_2 ) ;
else
return - V_110 ;
V_126 = F_60 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_104 ( & V_2 -> V_8 . V_16 . V_143 . V_173 , F_67 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_105 ( V_2 ) ;
V_2 -> V_8 . V_16 . V_215 = V_2 -> V_8 . V_16 . V_214 = V_2 -> V_8 . V_16 . V_206 ;
if ( V_221 == 1 )
F_102 ( V_2 ) ;
F_90 ( V_2 ) ;
V_126 = F_91 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
if ( V_126 )
goto V_250;
V_2 -> V_8 . V_14 = true ;
V_126 = F_99 ( V_2 -> V_98 , & V_251 ) ;
if ( V_126 )
F_92 ( L_37 ) ;
V_126 = F_99 ( V_2 -> V_98 , & V_252 ) ;
if ( V_126 )
F_92 ( L_37 ) ;
V_126 = F_99 ( V_2 -> V_98 , & V_248 ) ;
if ( V_126 )
F_92 ( L_32 ) ;
V_126 = F_99 ( V_2 -> V_98 , & V_249 ) ;
if ( V_126 )
F_92 ( L_33 ) ;
if ( F_100 ( V_2 ) ) {
F_92 ( L_38 ) ;
}
F_101 ( L_39 ) ;
return 0 ;
V_250:
V_2 -> V_8 . V_14 = false ;
if ( ( V_2 -> V_18 >= V_66 ) &&
( V_2 -> V_18 <= V_231 ) &&
V_2 -> V_232 ) {
if ( V_2 -> V_8 . V_233 )
F_87 ( V_2 , V_2 -> V_8 . V_233 ,
V_234 ) ;
if ( V_2 -> V_8 . V_235 )
F_87 ( V_2 , V_2 -> V_8 . V_235 ,
V_236 ) ;
if ( V_2 -> V_8 . V_65 )
F_22 ( V_2 , V_2 -> V_8 . V_65 ) ;
if ( V_2 -> V_8 . V_67 )
F_24 ( V_2 , V_2 -> V_8 . V_67 ) ;
}
F_92 ( L_40 ) ;
return V_126 ;
}
int F_106 ( struct V_1 * V_2 )
{
struct V_253 * V_254 = V_255 ;
bool V_256 = false ;
while ( V_254 && V_254 -> V_257 != 0 ) {
if ( V_2 -> V_258 -> V_259 == V_254 -> V_260 &&
V_2 -> V_258 -> V_97 == V_254 -> V_257 &&
V_2 -> V_258 -> V_261 == V_254 -> V_262 &&
V_2 -> V_258 -> V_263 == V_254 -> V_264 ) {
V_256 = true ;
break;
}
++ V_254 ;
}
switch ( V_2 -> V_18 ) {
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
if ( ! V_2 -> V_273 )
V_2 -> V_8 . V_12 = V_22 ;
else if ( ( V_2 -> V_18 >= V_272 ) &&
( ! ( V_2 -> V_90 & V_92 ) ) &&
( ! V_2 -> V_274 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_221 == 1 )
V_2 -> V_8 . V_12 = V_13 ;
else
V_2 -> V_8 . V_12 = V_22 ;
break;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_66 :
case V_286 :
case V_287 :
case V_231 :
case V_19 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
if ( ! V_2 -> V_273 )
V_2 -> V_8 . V_12 = V_22 ;
else if ( ( V_2 -> V_18 >= V_272 ) &&
( ! ( V_2 -> V_90 & V_92 ) ) &&
( ! V_2 -> V_274 ) )
V_2 -> V_8 . V_12 = V_22 ;
else if ( V_256 && ( V_221 == - 1 ) )
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
return F_103 ( V_2 ) ;
else
return F_94 ( V_2 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_126 = 0 ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_126 = F_108 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
return V_126 ;
}
static void F_109 ( struct V_1 * V_2 )
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
F_110 ( V_2 -> V_98 , & V_248 ) ;
F_110 ( V_2 -> V_98 , & V_249 ) ;
}
F_65 ( V_2 ) ;
F_111 ( V_2 -> V_8 . V_10 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
F_84 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_110 ( V_2 -> V_98 , & V_251 ) ;
F_110 ( V_2 -> V_98 , & V_252 ) ;
F_110 ( V_2 -> V_98 , & V_248 ) ;
F_110 ( V_2 -> V_98 , & V_249 ) ;
}
F_113 ( V_2 ) ;
F_65 ( V_2 ) ;
F_111 ( V_2 -> V_8 . V_10 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_112 ( V_2 ) ;
else
F_109 ( V_2 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_102 * V_73 = V_2 -> V_73 ;
struct V_298 * V_299 ;
struct V_300 * V_300 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_54 = 0 ;
V_2 -> V_8 . V_28 = 0 ;
if ( V_2 -> V_82 && V_2 -> V_301 . V_302 ) {
F_116 (crtc,
&ddev->mode_config.crtc_list, head) {
V_300 = F_117 ( V_299 ) ;
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
if ( V_2 -> V_8 . V_112 != V_115 ) {
if ( V_2 -> V_8 . V_28 > 1 ) {
if ( V_2 -> V_8 . V_112 == V_229 ) {
F_118 ( & V_2 -> V_8 . V_116 ) ;
V_2 -> V_8 . V_112 = V_113 ;
V_2 -> V_8 . V_84 = V_114 ;
F_119 ( V_2 ) ;
F_8 ( V_2 ) ;
F_23 ( L_41 ) ;
}
} else if ( V_2 -> V_8 . V_28 == 1 ) {
if ( V_2 -> V_8 . V_112 == V_305 ) {
V_2 -> V_8 . V_112 = V_229 ;
V_2 -> V_8 . V_84 = V_306 ;
F_119 ( V_2 ) ;
F_8 ( V_2 ) ;
F_88 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_240 ) ) ;
} else if ( V_2 -> V_8 . V_112 == V_113 ) {
V_2 -> V_8 . V_112 = V_229 ;
F_88 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_240 ) ) ;
F_23 ( L_42 ) ;
}
} else {
if ( V_2 -> V_8 . V_112 != V_305 ) {
F_118 ( & V_2 -> V_8 . V_116 ) ;
V_2 -> V_8 . V_112 = V_305 ;
V_2 -> V_8 . V_84 = V_307 ;
F_119 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_102 * V_73 = V_2 -> V_73 ;
struct V_298 * V_299 ;
struct V_300 * V_300 ;
if ( ! V_2 -> V_8 . V_14 )
return;
F_3 ( & V_2 -> V_8 . V_15 ) ;
V_2 -> V_8 . V_16 . V_218 = 0 ;
V_2 -> V_8 . V_16 . V_179 = 0 ;
if ( V_2 -> V_82 && V_2 -> V_301 . V_302 ) {
F_116 (crtc,
&ddev->mode_config.crtc_list, head) {
V_300 = F_117 ( V_299 ) ;
if ( V_299 -> V_303 ) {
V_2 -> V_8 . V_16 . V_218 |= ( 1 << V_300 -> V_304 ) ;
V_2 -> V_8 . V_16 . V_179 ++ ;
}
}
}
if ( F_4 () > 0 )
V_2 -> V_8 . V_16 . V_17 = true ;
else
V_2 -> V_8 . V_16 . V_17 = false ;
F_72 ( V_2 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_12 == V_13 )
F_120 ( V_2 ) ;
else
F_115 ( V_2 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
int V_299 , V_308 , V_309 , V_310 ;
bool V_311 = true ;
for ( V_299 = 0 ; ( V_299 < V_2 -> V_82 ) && V_311 ; V_299 ++ ) {
if ( V_2 -> V_8 . V_54 & ( 1 << V_299 ) ) {
V_310 = F_121 ( V_2 -> V_73 , V_299 , 0 , & V_308 , & V_309 , NULL , NULL ) ;
if ( ( V_310 & V_312 ) &&
! ( V_310 & V_313 ) )
V_311 = false ;
}
}
return V_311 ;
}
static bool F_21 ( struct V_1 * V_2 , bool V_314 )
{
T_1 V_315 = 0 ;
bool V_311 = F_18 ( V_2 ) ;
if ( V_311 == false )
F_23 ( L_43 , V_315 ,
V_314 ? L_44 : L_45 ) ;
return V_311 ;
}
static void V_247 ( struct V_172 * V_173 )
{
struct V_1 * V_2 ;
int V_316 ;
V_2 = F_59 ( V_173 , struct V_1 ,
V_8 . V_116 . V_173 ) ;
V_316 = F_122 ( & V_2 -> V_317 . V_318 ) ;
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_8 . V_112 == V_229 ) {
int V_319 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_77 ; ++ V_6 ) {
struct V_78 * V_79 = & V_2 -> V_79 [ V_6 ] ;
if ( V_79 -> V_80 ) {
V_319 += F_123 ( V_2 , V_6 ) ;
if ( V_319 >= 3 )
break;
}
}
if ( V_319 >= 3 ) {
if ( V_2 -> V_8 . V_84 == V_320 ) {
V_2 -> V_8 . V_84 = V_85 ;
} else if ( V_2 -> V_8 . V_84 == V_85 &&
V_2 -> V_8 . V_242 ) {
V_2 -> V_8 . V_84 =
V_306 ;
V_2 -> V_8 . V_321 = V_322 +
F_15 ( V_323 ) ;
}
} else if ( V_319 == 0 ) {
if ( V_2 -> V_8 . V_84 == V_306 ) {
V_2 -> V_8 . V_84 = V_85 ;
} else if ( V_2 -> V_8 . V_84 == V_85 &&
V_2 -> V_8 . V_243 ) {
V_2 -> V_8 . V_84 =
V_320 ;
V_2 -> V_8 . V_321 = V_322 +
F_15 ( V_323 ) ;
}
}
if ( V_2 -> V_8 . V_84 != V_85 &&
V_322 > V_2 -> V_8 . V_321 ) {
F_119 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_88 ( & V_2 -> V_8 . V_116 ,
F_15 ( V_240 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_15 ) ;
F_124 ( & V_2 -> V_317 . V_318 , V_316 ) ;
}
static int F_125 ( struct V_324 * V_325 , void * V_326 )
{
struct V_327 * V_328 = (struct V_327 * ) V_325 -> V_329 ;
struct V_102 * V_98 = V_328 -> V_330 -> V_98 ;
struct V_1 * V_2 = V_98 -> V_103 ;
struct V_102 * V_73 = V_2 -> V_73 ;
if ( ( V_2 -> V_90 & V_107 ) &&
( V_73 -> V_108 != V_109 ) ) {
F_126 ( V_325 , L_46 ) ;
} else if ( V_2 -> V_8 . V_14 ) {
F_3 ( & V_2 -> V_8 . V_15 ) ;
if ( V_2 -> V_20 -> V_16 . V_331 )
F_127 ( V_2 , V_325 ) ;
else
F_126 ( V_325 , L_47 ) ;
F_6 ( & V_2 -> V_8 . V_15 ) ;
} else {
F_126 ( V_325 , L_48 , V_2 -> V_8 . V_65 ) ;
if ( ( V_2 -> V_18 >= V_283 ) && ( V_2 -> V_90 & V_92 ) )
F_126 ( V_325 , L_49 , V_2 -> V_8 . V_68 ) ;
else
F_126 ( V_325 , L_49 , F_128 ( V_2 ) ) ;
F_126 ( V_325 , L_50 , V_2 -> V_8 . V_67 ) ;
if ( V_2 -> V_20 -> V_8 . V_332 )
F_126 ( V_325 , L_51 , F_129 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_237 )
F_126 ( V_325 , L_52 , V_2 -> V_8 . V_237 ) ;
if ( V_2 -> V_20 -> V_8 . V_333 )
F_126 ( V_325 , L_53 , F_130 ( V_2 ) ) ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
#if F_131 ( V_334 )
return F_132 ( V_2 , V_335 , F_133 ( V_335 ) ) ;
#else
return 0 ;
#endif
}
