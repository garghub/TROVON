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
( V_8 == V_62 ) ? L_18 : L_19 ) ;
}
static T_2 F_38 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_95 ,
T_3 V_100 )
{
struct V_96 * V_67 = F_34 ( F_35 ( V_92 ) ) ;
struct V_1 * V_2 = V_67 -> V_97 ;
if ( strncmp ( L_18 , V_95 , strlen ( L_18 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_12 = V_62 ;
V_2 -> V_8 . V_103 = V_104 ;
V_2 -> V_8 . V_78 = V_105 ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
} else if ( strncmp ( L_19 , V_95 , strlen ( L_19 ) ) == 0 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_103 = V_106 ;
V_2 -> V_8 . V_78 = V_79 ;
V_2 -> V_8 . V_12 = V_13 ;
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_39 ( & V_2 -> V_8 . V_107 ) ;
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
int V_108 ;
switch ( V_2 -> V_8 . V_109 ) {
case V_110 :
V_108 = F_42 ( V_2 ) ;
break;
case V_111 :
V_108 = F_43 ( V_2 ) ;
break;
case V_112 :
case V_113 :
V_108 = F_44 ( V_2 ) ;
break;
case V_114 :
V_108 = F_45 ( V_2 ) ;
break;
case V_115 :
V_108 = F_46 ( V_2 ) ;
break;
default:
V_108 = 0 ;
break;
}
return snprintf ( V_95 , V_99 , L_20 , V_108 ) ;
}
static T_2 F_47 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
return sprintf ( V_95 , L_21 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_116 = 0 ;
V_2 -> V_8 . V_117 = NULL ;
switch ( V_2 -> V_8 . V_109 ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
if ( V_2 -> V_58 == V_118 )
return V_116 ;
V_2 -> V_8 . V_117 = F_49 ( V_2 -> V_92 ) ;
if ( F_50 ( V_2 -> V_8 . V_117 ) ) {
V_116 = F_51 ( V_2 -> V_8 . V_117 ) ;
F_52 ( V_2 -> V_92 ,
L_22 , V_116 ) ;
break;
}
F_53 ( V_2 -> V_8 . V_117 , V_2 -> V_67 ) ;
V_116 = F_54 ( & V_2 -> V_8 . V_117 -> V_119 ,
& V_120 ) ;
if ( V_116 ) {
F_52 ( V_2 -> V_92 ,
L_23 , V_116 ) ;
F_55 ( V_2 -> V_92 ) ;
}
break;
default:
break;
}
return V_116 ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_117 ) {
F_57 ( & V_2 -> V_8 . V_117 -> V_119 , & V_120 ) ;
F_55 ( V_2 -> V_8 . V_117 ) ;
}
}
void F_58 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( V_2 -> V_8 . V_12 == V_62 ) {
if ( V_2 -> V_8 . V_103 == V_121 )
V_2 -> V_8 . V_103 = V_122 ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_39 ( & V_2 -> V_8 . V_107 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_58 >= V_59 ) &&
( V_2 -> V_58 <= V_123 ) &&
V_2 -> V_124 ) {
if ( V_2 -> V_8 . V_125 )
F_60 ( V_2 , V_2 -> V_8 . V_125 ,
V_126 ) ;
if ( V_2 -> V_8 . V_127 )
F_60 ( V_2 , V_2 -> V_8 . V_127 ,
V_128 ) ;
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
V_2 -> V_8 . V_129 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_56 [ 0 ] . V_90 . V_90 ;
V_2 -> V_8 . V_130 = V_2 -> V_8 . V_10 [ V_2 -> V_8 . V_11 ] . V_56 [ 0 ] . V_90 . V_131 ;
if ( V_2 -> V_8 . V_12 == V_62
&& V_2 -> V_8 . V_103 == V_122 ) {
V_2 -> V_8 . V_103 = V_121 ;
F_61 ( & V_2 -> V_8 . V_107 ,
F_14 ( V_132 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_40 ( V_2 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_133 ;
V_2 -> V_8 . V_12 = V_13 ;
V_2 -> V_8 . V_14 = V_17 ;
V_2 -> V_8 . V_103 = V_106 ;
V_2 -> V_8 . V_78 = V_79 ;
V_2 -> V_8 . V_134 = true ;
V_2 -> V_8 . V_135 = true ;
V_2 -> V_8 . V_57 = V_2 -> clock . V_57 ;
V_2 -> V_8 . V_60 = V_2 -> clock . V_60 ;
V_2 -> V_8 . V_61 = V_2 -> clock . V_57 ;
V_2 -> V_8 . V_65 = V_2 -> clock . V_60 ;
V_2 -> V_8 . V_109 = V_136 ;
if ( V_2 -> V_137 ) {
if ( V_2 -> V_138 )
F_63 ( V_2 ) ;
else
F_64 ( V_2 ) ;
F_32 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( ( V_2 -> V_58 >= V_59 ) &&
( V_2 -> V_58 <= V_123 ) &&
V_2 -> V_124 ) {
if ( V_2 -> V_8 . V_125 )
F_60 ( V_2 , V_2 -> V_8 . V_125 ,
V_126 ) ;
if ( V_2 -> V_8 . V_127 )
F_60 ( V_2 , V_2 -> V_8 . V_127 ,
V_128 ) ;
if ( V_2 -> V_8 . V_57 )
F_21 ( V_2 , V_2 -> V_8 . V_57 ) ;
if ( V_2 -> V_8 . V_60 )
F_23 ( V_2 , V_2 -> V_8 . V_60 ) ;
}
}
V_133 = F_48 ( V_2 ) ;
if ( V_133 )
return V_133 ;
F_66 ( & V_2 -> V_8 . V_107 , V_139 ) ;
if ( V_2 -> V_8 . V_9 > 1 ) {
V_133 = F_67 ( V_2 -> V_92 , & V_140 ) ;
if ( V_133 )
F_68 ( L_24 ) ;
V_133 = F_67 ( V_2 -> V_92 , & V_141 ) ;
if ( V_133 )
F_68 ( L_25 ) ;
if ( F_69 ( V_2 ) ) {
F_68 ( L_26 ) ;
}
F_70 ( L_27 ) ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 > 1 ) {
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( V_2 -> V_8 . V_12 == V_13 ) {
V_2 -> V_8 . V_14 = V_17 ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_62 ) {
V_2 -> V_8 . V_103 = V_106 ;
V_2 -> V_8 . V_78 = V_105 ;
F_5 ( V_2 ) ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_39 ( & V_2 -> V_8 . V_107 ) ;
F_72 ( V_2 -> V_92 , & V_140 ) ;
F_72 ( V_2 -> V_92 , & V_141 ) ;
}
if ( V_2 -> V_8 . V_10 )
F_73 ( V_2 -> V_8 . V_10 ) ;
F_56 ( V_2 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_96 * V_67 = V_2 -> V_67 ;
struct V_142 * V_143 ;
struct V_144 * V_144 ;
if ( V_2 -> V_8 . V_9 < 2 )
return;
F_3 ( & V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_46 = 0 ;
V_2 -> V_8 . V_20 = 0 ;
F_74 (crtc,
&ddev->mode_config.crtc_list, head) {
V_144 = F_75 ( V_143 ) ;
if ( V_144 -> V_145 ) {
V_2 -> V_8 . V_46 |= ( 1 << V_144 -> V_146 ) ;
V_2 -> V_8 . V_20 ++ ;
}
}
if ( V_2 -> V_8 . V_12 == V_13 ) {
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
} else if ( V_2 -> V_8 . V_12 == V_62 ) {
if ( V_2 -> V_8 . V_103 != V_106 ) {
if ( V_2 -> V_8 . V_20 > 1 ) {
if ( V_2 -> V_8 . V_103 == V_121 ) {
F_76 ( & V_2 -> V_8 . V_107 ) ;
V_2 -> V_8 . V_103 = V_104 ;
V_2 -> V_8 . V_78 = V_105 ;
F_77 ( V_2 ) ;
F_5 ( V_2 ) ;
F_22 ( L_28 ) ;
}
} else if ( V_2 -> V_8 . V_20 == 1 ) {
if ( V_2 -> V_8 . V_103 == V_147 ) {
V_2 -> V_8 . V_103 = V_121 ;
V_2 -> V_8 . V_78 = V_148 ;
F_77 ( V_2 ) ;
F_5 ( V_2 ) ;
F_61 ( & V_2 -> V_8 . V_107 ,
F_14 ( V_132 ) ) ;
} else if ( V_2 -> V_8 . V_103 == V_104 ) {
V_2 -> V_8 . V_103 = V_121 ;
F_61 ( & V_2 -> V_8 . V_107 ,
F_14 ( V_132 ) ) ;
F_22 ( L_29 ) ;
}
} else {
if ( V_2 -> V_8 . V_103 != V_147 ) {
F_76 ( & V_2 -> V_8 . V_107 ) ;
V_2 -> V_8 . V_103 = V_147 ;
V_2 -> V_8 . V_78 = V_149 ;
F_77 ( V_2 ) ;
F_5 ( V_2 ) ;
}
}
}
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
int V_143 , V_150 , V_151 , V_152 ;
bool V_153 = true ;
for ( V_143 = 0 ; ( V_143 < V_2 -> V_76 ) && V_153 ; V_143 ++ ) {
if ( V_2 -> V_8 . V_46 & ( 1 << V_143 ) ) {
V_152 = F_78 ( V_2 -> V_67 , V_143 , & V_150 , & V_151 ) ;
if ( ( V_152 & V_154 ) &&
! ( V_152 & V_155 ) )
V_153 = false ;
}
}
return V_153 ;
}
static bool F_20 ( struct V_1 * V_2 , bool V_156 )
{
T_1 V_157 = 0 ;
bool V_153 = F_17 ( V_2 ) ;
if ( V_153 == false )
F_22 ( L_30 , V_157 ,
V_156 ? L_31 : L_32 ) ;
return V_153 ;
}
static void V_139 ( struct V_158 * V_159 )
{
struct V_1 * V_2 ;
int V_160 ;
V_2 = F_79 ( V_159 , struct V_1 ,
V_8 . V_107 . V_159 ) ;
V_160 = F_80 ( & V_2 -> V_161 . V_162 ) ;
F_3 ( & V_2 -> V_8 . V_16 ) ;
if ( V_2 -> V_8 . V_103 == V_121 ) {
int V_163 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_71 ; ++ V_6 ) {
struct V_72 * V_73 = & V_2 -> V_73 [ V_6 ] ;
if ( V_73 -> V_74 ) {
V_163 += F_81 ( V_2 , V_6 ) ;
if ( V_163 >= 3 )
break;
}
}
if ( V_163 >= 3 ) {
if ( V_2 -> V_8 . V_78 == V_164 ) {
V_2 -> V_8 . V_78 = V_79 ;
} else if ( V_2 -> V_8 . V_78 == V_79 &&
V_2 -> V_8 . V_134 ) {
V_2 -> V_8 . V_78 =
V_148 ;
V_2 -> V_8 . V_165 = V_166 +
F_14 ( V_167 ) ;
}
} else if ( V_163 == 0 ) {
if ( V_2 -> V_8 . V_78 == V_148 ) {
V_2 -> V_8 . V_78 = V_79 ;
} else if ( V_2 -> V_8 . V_78 == V_79 &&
V_2 -> V_8 . V_135 ) {
V_2 -> V_8 . V_78 =
V_164 ;
V_2 -> V_8 . V_165 = V_166 +
F_14 ( V_167 ) ;
}
}
if ( V_2 -> V_8 . V_78 != V_79 &&
V_166 > V_2 -> V_8 . V_165 ) {
F_77 ( V_2 ) ;
F_5 ( V_2 ) ;
}
F_61 ( & V_2 -> V_8 . V_107 ,
F_14 ( V_132 ) ) ;
}
F_6 ( & V_2 -> V_8 . V_16 ) ;
F_82 ( & V_2 -> V_161 . V_162 , V_160 ) ;
}
static int F_83 ( struct V_168 * V_169 , void * V_170 )
{
struct V_171 * V_172 = (struct V_171 * ) V_169 -> V_173 ;
struct V_96 * V_92 = V_172 -> V_174 -> V_92 ;
struct V_1 * V_2 = V_92 -> V_97 ;
F_84 ( V_169 , L_33 , V_2 -> V_8 . V_57 ) ;
if ( ( V_2 -> V_58 >= V_175 ) && ( V_2 -> V_84 & V_86 ) )
F_84 ( V_169 , L_34 , V_2 -> V_8 . V_61 ) ;
else
F_84 ( V_169 , L_34 , F_85 ( V_2 ) ) ;
F_84 ( V_169 , L_35 , V_2 -> V_8 . V_60 ) ;
if ( V_2 -> V_63 -> V_8 . V_176 )
F_84 ( V_169 , L_36 , F_86 ( V_2 ) ) ;
if ( V_2 -> V_8 . V_129 )
F_84 ( V_169 , L_37 , V_2 -> V_8 . V_129 ) ;
if ( V_2 -> V_63 -> V_8 . V_177 )
F_84 ( V_169 , L_38 , F_87 ( V_2 ) ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
#if F_88 ( V_178 )
return F_89 ( V_2 , V_179 , F_90 ( V_179 ) ) ;
#else
return 0 ;
#endif
}
