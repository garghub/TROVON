void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
F_2 ( & V_2 -> V_3 . V_5 ) ;
if ( F_3 () > 0 )
V_2 -> V_3 . V_6 . V_7 = true ;
else
V_2 -> V_3 . V_6 . V_7 = false ;
if ( V_2 -> V_3 . V_8 -> V_9 )
F_4 ( V_2 , V_2 -> V_3 . V_6 . V_7 ) ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
}
}
static T_1 F_6 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_15 * V_16 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_18 V_3 = V_2 -> V_3 . V_6 . V_19 ;
return snprintf ( V_14 , V_20 , L_1 ,
( V_3 == V_21 ) ? L_2 :
( V_3 == V_22 ) ? L_3 : L_4 ) ;
}
static T_1 F_8 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_2 V_23 )
{
struct V_15 * V_16 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_2 ( & V_2 -> V_3 . V_5 ) ;
if ( strncmp ( L_2 , V_14 , strlen ( L_2 ) ) == 0 )
V_2 -> V_3 . V_6 . V_19 = V_21 ;
else if ( strncmp ( L_3 , V_14 , strlen ( L_3 ) ) == 0 )
V_2 -> V_3 . V_6 . V_19 = V_22 ;
else if ( strncmp ( L_4 , V_14 , strlen ( L_4 ) ) == 0 )
V_2 -> V_3 . V_6 . V_19 = V_24 ;
else {
F_5 ( & V_2 -> V_3 . V_5 ) ;
V_23 = - V_25 ;
goto V_26;
}
F_5 ( & V_2 -> V_3 . V_5 ) ;
if ( ! ( V_2 -> V_27 & V_28 ) ||
( V_16 -> V_29 == V_30 ) )
F_9 ( V_2 ) ;
V_26:
return V_23 ;
}
static T_1 F_10 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_15 * V_16 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_31 V_32 = V_2 -> V_3 . V_6 . V_33 ;
return snprintf ( V_14 , V_20 , L_1 ,
( V_32 == V_34 ) ? L_5 :
( V_32 == V_35 ) ? L_6 : L_7 ) ;
}
static T_1 F_11 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_2 V_23 )
{
struct V_15 * V_16 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_31 V_32 ;
int V_36 = 0 ;
F_2 ( & V_2 -> V_3 . V_5 ) ;
if ( strncmp ( L_6 , V_14 , strlen ( L_6 ) ) == 0 ) {
V_32 = V_35 ;
} else if ( strncmp ( L_7 , V_14 , strlen ( L_7 ) ) == 0 ) {
V_32 = V_37 ;
} else if ( strncmp ( L_5 , V_14 , strlen ( L_5 ) ) == 0 ) {
V_32 = V_34 ;
} else {
V_23 = - V_25 ;
goto V_26;
}
if ( V_2 -> V_3 . V_8 -> V_38 ) {
if ( V_2 -> V_3 . V_6 . V_39 ) {
V_23 = - V_25 ;
goto V_26;
}
V_36 = F_12 ( V_2 , V_32 ) ;
if ( V_36 )
V_23 = - V_25 ;
}
V_26:
F_5 ( & V_2 -> V_3 . V_5 ) ;
return V_23 ;
}
static T_1 F_13 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_40 ;
if ( V_2 -> V_3 . V_8 -> V_41 )
V_40 = F_14 ( V_2 ) ;
else
V_40 = 0 ;
return snprintf ( V_14 , V_20 , L_8 , V_40 ) ;
}
static T_1 F_15 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_42 = F_16 ( V_13 ) -> V_43 ;
int V_40 ;
if ( V_42 )
V_40 = V_2 -> V_3 . V_6 . V_44 . V_45 ;
else
V_40 = V_2 -> V_3 . V_6 . V_44 . V_46 ;
return snprintf ( V_14 , V_20 , L_8 , V_40 ) ;
}
static T_1 F_17 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
T_3 V_47 = 0 ;
if ( V_2 -> V_3 . V_8 -> V_48 )
V_47 = F_18 ( V_2 ) ;
return sprintf ( V_14 , L_9 , V_47 == V_49 ? 1 : 2 ) ;
}
static T_1 F_19 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char * V_14 ,
T_2 V_23 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_50 ;
int V_51 ;
if( ! V_2 -> V_3 . V_8 -> V_52 )
return - V_25 ;
V_50 = F_20 ( V_14 , 10 , & V_51 ) ;
if ( V_50 )
return V_50 ;
switch ( V_51 ) {
case 1 :
F_21 ( V_2 , V_49 ) ;
break;
default:
F_21 ( V_2 , 0 ) ;
break;
}
return V_23 ;
}
static T_1 F_22 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
return sprintf ( V_14 , L_9 , 0 ) ;
}
static T_1 F_23 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
return sprintf ( V_14 , L_9 , 255 ) ;
}
static T_1 F_24 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char * V_14 , T_2 V_23 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_50 ;
T_3 V_51 ;
V_50 = F_25 ( V_14 , 10 , & V_51 ) ;
if ( V_50 )
return V_50 ;
V_51 = ( V_51 * 100 ) / 255 ;
V_50 = F_26 ( V_2 , V_51 ) ;
if ( V_50 )
return V_50 ;
return V_23 ;
}
static T_1 F_27 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_50 ;
T_3 V_53 ;
V_50 = F_28 ( V_2 , & V_53 ) ;
if ( V_50 )
return V_50 ;
V_53 = ( V_53 * 255 ) / 100 ;
return sprintf ( V_14 , L_9 , V_53 ) ;
}
static T_4 F_29 ( struct V_54 * V_55 ,
struct V_56 * V_13 , int V_43 )
{
struct V_10 * V_11 = F_30 ( V_55 , struct V_10 , V_55 ) ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
T_4 V_57 = V_13 -> V_58 ;
if ( ! V_2 -> V_3 . V_4 &&
( V_13 == & V_59 . V_60 . V_13 ||
V_13 == & V_61 . V_60 . V_13 ) )
return 0 ;
if ( V_2 -> V_3 . V_62 &&
( V_13 == & V_63 . V_60 . V_13 ||
V_13 == & V_64 . V_60 . V_13 ||
V_13 == & V_65 . V_60 . V_13 ||
V_13 == & V_66 . V_60 . V_13 ) )
return 0 ;
if ( ( ! V_2 -> V_3 . V_8 -> V_67 &&
V_13 == & V_63 . V_60 . V_13 ) ||
( ! V_2 -> V_3 . V_8 -> V_48 &&
V_13 == & V_64 . V_60 . V_13 ) )
V_57 &= ~ V_68 ;
if ( ( ! V_2 -> V_3 . V_8 -> V_69 &&
V_13 == & V_63 . V_60 . V_13 ) ||
( ! V_2 -> V_3 . V_8 -> V_52 &&
V_13 == & V_64 . V_60 . V_13 ) )
V_57 &= ~ V_70 ;
if ( ( ! V_2 -> V_3 . V_8 -> V_69 &&
! V_2 -> V_3 . V_8 -> V_67 ) &&
( V_13 == & V_65 . V_60 . V_13 ||
V_13 == & V_66 . V_60 . V_13 ) )
return 0 ;
return V_57 ;
}
void F_31 ( struct V_71 * V_72 )
{
struct V_1 * V_2 =
F_30 ( V_72 , struct V_1 ,
V_3 . V_6 . V_44 . V_72 ) ;
enum V_18 V_73 = V_74 ;
if ( ! V_2 -> V_3 . V_4 )
return;
if ( V_2 -> V_3 . V_8 -> V_41 ) {
int V_40 = F_14 ( V_2 ) ;
if ( V_40 < V_2 -> V_3 . V_6 . V_44 . V_45 )
V_73 = V_2 -> V_3 . V_6 . V_19 ;
} else {
if ( V_2 -> V_3 . V_6 . V_44 . V_75 )
V_73 = V_2 -> V_3 . V_6 . V_19 ;
}
F_2 ( & V_2 -> V_3 . V_5 ) ;
if ( V_73 == V_74 )
V_2 -> V_3 . V_6 . V_39 = true ;
else
V_2 -> V_3 . V_6 . V_39 = false ;
V_2 -> V_3 . V_6 . V_76 = V_73 ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
F_9 ( V_2 ) ;
}
static struct V_77 * F_32 ( struct V_1 * V_2 ,
enum V_18 V_73 )
{
int V_78 ;
struct V_77 * V_79 ;
T_3 V_80 ;
bool V_81 = ( V_2 -> V_3 . V_6 . V_82 < 2 ) ?
true : false ;
if ( V_81 && V_2 -> V_3 . V_8 -> V_83 ) {
if ( F_33 ( V_2 ) )
V_81 = false ;
}
if ( V_73 == V_24 )
V_73 = V_84 ;
if ( V_73 == V_22 )
V_73 = V_24 ;
V_85:
for ( V_78 = 0 ; V_78 < V_2 -> V_3 . V_6 . V_86 ; V_78 ++ ) {
V_79 = & V_2 -> V_3 . V_6 . V_79 [ V_78 ] ;
V_80 = V_79 -> V_87 & V_88 ;
switch ( V_73 ) {
case V_21 :
if ( V_80 == V_89 ) {
if ( V_79 -> V_90 & V_91 ) {
if ( V_81 )
return V_79 ;
} else
return V_79 ;
}
break;
case V_22 :
if ( V_80 == V_92 ) {
if ( V_79 -> V_90 & V_91 ) {
if ( V_81 )
return V_79 ;
} else
return V_79 ;
}
break;
case V_24 :
if ( V_80 == V_93 ) {
if ( V_79 -> V_90 & V_91 ) {
if ( V_81 )
return V_79 ;
} else
return V_79 ;
}
break;
case V_94 :
if ( V_2 -> V_3 . V_6 . V_95 )
return V_2 -> V_3 . V_6 . V_95 ;
else
break;
case V_96 :
if ( V_79 -> V_87 & V_97 )
return V_79 ;
break;
case V_98 :
if ( V_79 -> V_87 & V_99 )
return V_79 ;
break;
case V_100 :
if ( V_79 -> V_87 & V_101 )
return V_79 ;
break;
case V_102 :
if ( V_79 -> V_103 & V_104 )
return V_79 ;
break;
case V_105 :
return V_2 -> V_3 . V_6 . V_106 ;
case V_74 :
if ( V_79 -> V_87 & V_107 )
return V_79 ;
break;
case V_108 :
if ( V_79 -> V_87 & V_109 )
return V_79 ;
break;
case V_110 :
if ( V_79 -> V_103 & V_111 )
return V_79 ;
break;
case V_84 :
if ( V_79 -> V_87 & V_112 )
return V_79 ;
break;
default:
break;
}
}
switch ( V_73 ) {
case V_96 :
V_73 = V_98 ;
goto V_85;
case V_98 :
case V_100 :
case V_102 :
if ( V_2 -> V_3 . V_6 . V_95 ) {
return V_2 -> V_3 . V_6 . V_95 ;
} else {
V_73 = V_24 ;
goto V_85;
}
case V_74 :
V_73 = V_108 ;
goto V_85;
case V_108 :
V_73 = V_21 ;
goto V_85;
case V_21 :
case V_22 :
case V_84 :
V_73 = V_24 ;
goto V_85;
default:
break;
}
return NULL ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_78 ;
struct V_77 * V_79 ;
enum V_18 V_73 ;
int V_36 ;
if ( ! V_2 -> V_3 . V_4 )
return;
if ( V_2 -> V_3 . V_6 . V_19 != V_2 -> V_3 . V_6 . V_76 ) {
if ( ( ! V_2 -> V_3 . V_6 . V_39 ) &&
( ! V_2 -> V_3 . V_6 . V_113 ) )
V_2 -> V_3 . V_6 . V_76 = V_2 -> V_3 . V_6 . V_19 ;
}
V_73 = V_2 -> V_3 . V_6 . V_76 ;
V_79 = F_32 ( V_2 , V_73 ) ;
if ( V_79 )
V_2 -> V_3 . V_6 . V_114 = V_79 ;
else
return;
if ( V_2 -> V_3 . V_6 . V_115 == V_2 -> V_3 . V_6 . V_114 ) {
if ( V_79 -> V_116 != V_2 -> V_3 . V_6 . V_116 )
goto V_117;
if ( V_2 -> V_27 & V_118 ) {
if ( V_2 -> V_3 . V_6 . V_119 != V_2 -> V_3 . V_6 . V_120 ) {
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
V_2 -> V_3 . V_6 . V_120 = V_2 -> V_3 . V_6 . V_119 ;
V_2 -> V_3 . V_6 . V_121 = V_2 -> V_3 . V_6 . V_82 ;
}
return;
} else {
if ( V_2 -> V_3 . V_6 . V_119 ==
V_2 -> V_3 . V_6 . V_120 ) {
return;
} else if ( ( V_2 -> V_3 . V_6 . V_121 > 1 ) &&
( V_2 -> V_3 . V_6 . V_82 > 1 ) ) {
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
V_2 -> V_3 . V_6 . V_120 = V_2 -> V_3 . V_6 . V_119 ;
V_2 -> V_3 . V_6 . V_121 = V_2 -> V_3 . V_6 . V_82 ;
return;
}
}
}
V_117:
if ( V_122 == 1 ) {
F_37 ( L_10 ) ;
F_38 ( V_2 , V_2 -> V_3 . V_6 . V_115 ) ;
F_37 ( L_11 ) ;
F_38 ( V_2 , V_2 -> V_3 . V_6 . V_114 ) ;
}
F_2 ( & V_2 -> V_16 -> V_123 ) ;
F_2 ( & V_2 -> V_124 ) ;
V_79 -> V_116 = V_2 -> V_3 . V_6 . V_116 ;
V_36 = F_39 ( V_2 ) ;
if ( V_36 )
goto V_125;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
V_2 -> V_3 . V_6 . V_120 = V_2 -> V_3 . V_6 . V_119 ;
V_2 -> V_3 . V_6 . V_121 = V_2 -> V_3 . V_6 . V_82 ;
for ( V_78 = 0 ; V_78 < V_126 ; V_78 ++ ) {
struct V_127 * V_128 = V_2 -> V_129 [ V_78 ] ;
if ( V_128 && V_128 -> V_130 )
F_40 ( V_128 ) ;
}
F_41 ( V_2 ) ;
V_2 -> V_3 . V_6 . V_115 = V_2 -> V_3 . V_6 . V_114 ;
F_42 ( V_2 ) ;
if ( V_2 -> V_3 . V_8 -> V_38 ) {
if ( V_2 -> V_3 . V_6 . V_39 ) {
enum V_31 V_32 = V_2 -> V_3 . V_6 . V_33 ;
F_12 ( V_2 , V_35 ) ;
V_2 -> V_3 . V_6 . V_33 = V_32 ;
} else {
F_12 ( V_2 , V_2 -> V_3 . V_6 . V_33 ) ;
}
}
V_125:
F_5 ( & V_2 -> V_124 ) ;
F_5 ( & V_2 -> V_16 -> V_123 ) ;
}
void F_43 ( struct V_1 * V_2 , bool V_131 )
{
if ( V_2 -> V_3 . V_8 -> V_132 ) {
F_2 ( & V_2 -> V_3 . V_5 ) ;
F_44 ( V_2 , ! V_131 ) ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
} else {
if ( V_131 ) {
F_2 ( & V_2 -> V_3 . V_5 ) ;
V_2 -> V_3 . V_6 . V_113 = true ;
V_2 -> V_3 . V_6 . V_76 = V_94 ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
} else {
F_2 ( & V_2 -> V_3 . V_5 ) ;
V_2 -> V_3 . V_6 . V_113 = false ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
}
F_9 ( V_2 ) ;
}
}
void F_45 ( struct V_1 * V_2 , bool V_131 )
{
if ( V_2 -> V_3 . V_8 -> V_133 ) {
F_2 ( & V_2 -> V_3 . V_5 ) ;
F_46 ( V_2 , ! V_131 ) ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
} else {
if ( V_131 ) {
F_2 ( & V_2 -> V_3 . V_5 ) ;
V_2 -> V_3 . V_6 . V_116 = true ;
V_2 -> V_3 . V_6 . V_134 = V_135 ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
} else {
F_2 ( & V_2 -> V_3 . V_5 ) ;
V_2 -> V_3 . V_6 . V_116 = false ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
}
F_9 ( V_2 ) ;
}
}
void F_47 ( struct V_1 * V_2 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_3 . V_6 . V_86 ; V_78 ++ ) {
F_37 ( L_12 , V_78 ) ;
F_38 ( V_2 , & V_2 -> V_3 . V_6 . V_79 [ V_78 ] ) ;
}
}
int F_48 ( struct V_1 * V_2 )
{
int V_36 ;
if ( V_2 -> V_3 . V_8 -> V_41 == NULL )
return 0 ;
V_2 -> V_3 . V_136 = F_49 ( V_2 -> V_11 ,
V_137 , V_2 ,
V_138 ) ;
if ( F_50 ( V_2 -> V_3 . V_136 ) ) {
V_36 = F_51 ( V_2 -> V_3 . V_136 ) ;
F_52 ( V_2 -> V_11 ,
L_13 , V_36 ) ;
return V_36 ;
}
V_36 = F_53 ( V_2 -> V_11 , & V_139 ) ;
if ( V_36 ) {
F_54 ( L_14 ) ;
return V_36 ;
}
V_36 = F_53 ( V_2 -> V_11 , & V_140 ) ;
if ( V_36 ) {
F_54 ( L_14 ) ;
return V_36 ;
}
V_36 = F_55 ( V_2 ) ;
if ( V_36 ) {
F_54 ( L_15 ) ;
return V_36 ;
}
return 0 ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_136 )
F_57 ( V_2 -> V_3 . V_136 ) ;
F_58 ( V_2 -> V_11 , & V_139 ) ;
F_58 ( V_2 -> V_11 , & V_140 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_141 * V_142 ;
struct V_143 * V_143 ;
if ( ! V_2 -> V_3 . V_4 )
return;
F_2 ( & V_2 -> V_3 . V_5 ) ;
V_2 -> V_3 . V_6 . V_119 = 0 ;
V_2 -> V_3 . V_6 . V_82 = 0 ;
if ( V_2 -> V_144 . V_145 && V_2 -> V_144 . V_146 ) {
F_59 (crtc,
&ddev->mode_config.crtc_list, head) {
V_143 = F_60 ( V_142 ) ;
if ( V_142 -> V_147 ) {
V_2 -> V_3 . V_6 . V_119 |= ( 1 << V_143 -> V_148 ) ;
V_2 -> V_3 . V_6 . V_82 ++ ;
}
}
}
if ( F_3 () > 0 )
V_2 -> V_3 . V_6 . V_7 = true ;
else
V_2 -> V_3 . V_6 . V_7 = false ;
F_34 ( V_2 ) ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
}
static int F_61 ( struct V_149 * V_150 , void * V_151 )
{
struct V_152 * V_153 = (struct V_152 * ) V_150 -> V_154 ;
struct V_15 * V_11 = V_153 -> V_155 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_17 ;
if ( V_2 -> V_3 . V_4 ) {
F_2 ( & V_2 -> V_3 . V_5 ) ;
if ( V_2 -> V_3 . V_8 -> V_156 )
F_62 ( V_2 , V_150 ) ;
else
F_63 ( V_150 , L_16 ) ;
F_5 ( & V_2 -> V_3 . V_5 ) ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
#if F_64 ( V_157 )
return F_65 ( V_2 , V_158 , F_66 ( V_158 ) ) ;
#else
return 0 ;
#endif
}
