void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_9 . V_9 == V_10 )
return;
F_3 ( V_6 , V_8 -> V_9 . V_9 ) ;
if ( V_2 -> V_11 != V_12 )
return;
if ( V_2 -> V_13 == V_14 ) {
int V_15 = V_2 -> V_11 ;
if ( ! F_4 ( V_6 , V_8 -> V_9 . V_9 ) )
F_5 ( V_2 , V_16 ) ;
else if ( F_6 ( V_8 ) )
F_5 ( V_2 , V_12 ) ;
V_2 -> V_11 = V_15 ;
}
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
if ( V_20 && V_20 -> V_21 ) {
F_8 ( V_20 , & V_20 -> V_22 ,
V_20 -> V_23 , V_20 -> V_24 , V_20 -> V_25 ) ;
}
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
int V_28 = 8 ;
switch ( V_2 -> V_13 ) {
case V_29 :
case V_30 :
if ( V_8 -> V_31 ) {
if ( F_10 ( V_8 -> V_32 ) ) {
if ( V_2 -> V_33 . V_28 )
V_28 = V_2 -> V_33 . V_28 ;
}
}
break;
case V_34 :
case V_35 :
if ( F_10 ( V_8 -> V_32 ) ) {
if ( V_2 -> V_33 . V_28 )
V_28 = V_2 -> V_33 . V_28 ;
}
break;
case V_14 :
V_27 = V_8 -> V_36 ;
if ( ( V_27 -> V_37 == V_38 ) ||
( V_27 -> V_37 == V_39 ) ||
F_10 ( V_8 -> V_32 ) ) {
if ( V_2 -> V_33 . V_28 )
V_28 = V_2 -> V_33 . V_28 ;
}
break;
case V_40 :
case V_41 :
if ( V_2 -> V_33 . V_28 )
V_28 = V_2 -> V_33 . V_28 ;
else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
struct V_42 * V_43 =
V_2 -> V_44 ;
struct V_17 * V_18 = V_43 -> V_45 ( V_2 ) ;
struct V_46 * V_46 = F_13 ( V_18 ) ;
struct V_47 * V_48 = V_46 -> V_49 ;
if ( V_48 -> V_50 & V_51 )
V_28 = 6 ;
else if ( V_48 -> V_50 & V_52 )
V_28 = 8 ;
}
break;
}
return V_28 ;
}
static void
F_14 ( struct V_1 * V_2 , enum V_53 V_54 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_17 * V_45 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_42 * V_43 = V_2 -> V_44 ;
struct V_55 * V_56 ;
bool V_57 ;
int V_58 ;
V_45 = V_43 -> V_45 ( V_2 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_15 ( V_2 -> V_4 ,
V_2 -> V_60 [ V_58 ] ,
V_61 ) ;
if ( ! V_56 )
continue;
V_18 = F_16 ( V_56 ) ;
if ( ( V_18 == V_45 ) && ( V_54 == V_62 ) )
V_57 = true ;
else
V_57 = false ;
if ( V_6 -> V_63 )
F_17 ( V_2 , V_18 , V_57 ) ;
else
F_18 ( V_2 , V_18 , V_57 ) ;
}
}
struct V_17 * F_19 ( struct V_1 * V_2 , int V_64 )
{
struct V_55 * V_56 ;
struct V_17 * V_18 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_15 ( V_2 -> V_4 , V_2 -> V_60 [ V_58 ] , V_61 ) ;
if ( ! V_56 )
continue;
V_18 = F_16 ( V_56 ) ;
if ( V_18 -> V_64 == V_64 )
return V_18 ;
}
return NULL ;
}
struct V_17 * F_20 ( struct V_1 * V_2 )
{
int V_65 = V_2 -> V_60 [ 0 ] ;
struct V_55 * V_56 ;
struct V_17 * V_18 ;
if ( V_65 ) {
V_56 = F_15 ( V_2 -> V_4 , V_65 , V_61 ) ;
if ( ! V_56 )
return NULL ;
V_18 = F_16 ( V_56 ) ;
return V_18 ;
}
return NULL ;
}
static enum V_53
F_21 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
enum V_53 V_66 ,
bool V_67 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_68 ;
struct V_8 * V_69 ;
int V_58 ;
F_22 (conflict, &dev->mode_config.connector_list, head) {
if ( V_68 == V_2 )
continue;
V_69 = F_2 ( V_68 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_68 -> V_60 [ V_58 ] == 0 )
break;
if ( V_68 -> V_60 [ V_58 ] == V_18 -> V_70 . V_71 ) {
if ( V_68 -> V_54 != V_62 )
continue;
if ( V_69 -> V_31 )
continue;
if ( V_67 == true ) {
F_23 ( L_1 , F_24 ( V_68 ) ) ;
F_23 ( L_2 , F_24 ( V_2 ) ) ;
V_68 -> V_54 = V_72 ;
F_14 ( V_68 , V_72 ) ;
} else {
F_23 ( L_3 , F_24 ( V_2 ) ) ;
F_23 ( L_2 , F_24 ( V_68 ) ) ;
V_66 = V_72 ;
}
break;
}
}
}
return V_66 ;
}
static struct V_73 * F_25 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_4 ;
struct V_46 * V_46 = F_13 ( V_18 ) ;
struct V_73 * V_22 = NULL ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( V_74 -> V_75 != 0 &&
V_74 -> V_76 != 0 &&
V_74 -> clock != 0 ) {
V_22 = F_26 ( V_4 , V_74 ) ;
V_22 -> type = V_77 | V_78 ;
F_27 ( V_22 ) ;
F_23 ( L_4 , V_22 -> V_79 ) ;
} else if ( V_74 -> V_75 != 0 &&
V_74 -> V_76 != 0 ) {
V_22 = F_28 ( V_4 , V_74 -> V_75 , V_74 -> V_76 , 60 , true , false , false ) ;
V_22 -> type = V_77 | V_78 ;
F_23 ( L_5 , V_22 -> V_79 ) ;
}
return V_22 ;
}
static void F_29 ( struct V_17 * V_18 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_18 -> V_4 ;
struct V_46 * V_46 = F_13 ( V_18 ) ;
struct V_73 * V_22 = NULL ;
struct V_73 * V_74 = & V_46 -> V_74 ;
int V_58 ;
struct V_80 {
int V_81 ;
int V_82 ;
} V_83 [ 17 ] = {
{ 640 , 480 } ,
{ 720 , 480 } ,
{ 800 , 600 } ,
{ 848 , 480 } ,
{ 1024 , 768 } ,
{ 1152 , 768 } ,
{ 1280 , 720 } ,
{ 1280 , 800 } ,
{ 1280 , 854 } ,
{ 1280 , 960 } ,
{ 1280 , 1024 } ,
{ 1440 , 900 } ,
{ 1400 , 1050 } ,
{ 1680 , 1050 } ,
{ 1600 , 1200 } ,
{ 1920 , 1080 } ,
{ 1920 , 1200 }
} ;
for ( V_58 = 0 ; V_58 < 17 ; V_58 ++ ) {
if ( V_46 -> V_84 & ( V_85 ) ) {
if ( V_83 [ V_58 ] . V_81 > 1024 ||
V_83 [ V_58 ] . V_82 > 768 )
continue;
}
if ( V_46 -> V_84 & ( V_86 ) ) {
if ( V_83 [ V_58 ] . V_81 > V_74 -> V_75 ||
V_83 [ V_58 ] . V_82 > V_74 -> V_76 ||
( V_83 [ V_58 ] . V_81 == V_74 -> V_75 &&
V_83 [ V_58 ] . V_82 == V_74 -> V_76 ) )
continue;
}
if ( V_83 [ V_58 ] . V_81 < 320 || V_83 [ V_58 ] . V_82 < 200 )
continue;
V_22 = F_28 ( V_4 , V_83 [ V_58 ] . V_81 , V_83 [ V_58 ] . V_82 , 60 , false , false , false ) ;
F_30 ( V_2 , V_22 ) ;
}
}
int F_31 ( struct V_1 * V_2 , struct V_87 * V_88 ,
T_1 V_89 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_17 * V_18 ;
struct V_46 * V_46 ;
if ( V_88 == V_6 -> V_90 . V_91 ) {
struct V_47 * V_48 ;
bool V_92 ;
V_18 = F_19 ( V_2 , V_93 ) ;
if ( ! V_18 )
return 0 ;
V_46 = F_13 ( V_18 ) ;
if ( ! V_46 -> V_49 )
return 0 ;
V_48 = V_46 -> V_49 ;
V_92 = V_89 ? true : false ;
if ( V_48 -> V_94 != V_92 ) {
V_48 -> V_94 = V_92 ;
F_7 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_95 ) {
V_18 = F_19 ( V_2 , V_93 ) ;
if ( ! V_18 )
return 0 ;
V_46 = F_13 ( V_18 ) ;
if ( V_46 -> V_96 != V_89 ) {
V_46 -> V_96 = V_89 ;
F_7 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_97 ) {
V_18 = F_19 ( V_2 , V_93 ) ;
if ( ! V_18 )
return 0 ;
V_46 = F_13 ( V_18 ) ;
if ( V_46 -> V_98 != V_89 ) {
V_46 -> V_98 = V_89 ;
F_7 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_99 ) {
V_18 = F_19 ( V_2 , V_93 ) ;
if ( ! V_18 )
return 0 ;
V_46 = F_13 ( V_18 ) ;
if ( V_46 -> V_100 != V_89 ) {
V_46 -> V_100 = V_89 ;
F_7 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_101 ) {
V_18 = F_19 ( V_2 , V_102 ) ;
if ( ! V_18 ) {
V_18 = F_19 ( V_2 , V_103 ) ;
}
if ( ! V_18 )
return 0 ;
V_46 = F_13 ( V_18 ) ;
if ( ! V_46 -> V_49 )
return 0 ;
if ( F_32 ( V_6 ) || V_104 ) {
struct V_105 * V_106 ;
V_106 = V_46 -> V_49 ;
V_106 -> V_107 = V_89 ;
} else {
struct V_108 * V_106 ;
V_106 = V_46 -> V_49 ;
V_106 -> V_107 = V_89 ;
}
F_7 ( & V_46 -> V_70 ) ;
}
if ( V_88 == V_6 -> V_90 . V_109 ) {
struct V_8 * V_8 =
F_2 ( V_2 ) ;
if ( V_89 == 0 )
V_8 -> V_110 = false ;
else
V_8 -> V_110 = true ;
}
if ( V_88 == V_6 -> V_90 . V_111 ) {
struct V_112 * V_113 = NULL ;
bool V_114 = false ;
V_18 = F_19 ( V_2 , V_93 ) ;
if ( ! V_18 )
return 0 ;
V_46 = F_13 ( V_18 ) ;
V_113 = V_46 -> V_49 ;
if ( ! V_113 )
return 0 ;
if ( V_89 == 0 ) {
if ( V_6 -> V_63 )
V_114 = F_33 ( V_46 , V_113 ) ;
else
V_114 = F_34 ( V_46 , V_113 ) ;
}
if ( V_89 == 1 || V_114 == false ) {
F_35 ( V_46 , V_113 ) ;
}
F_7 ( & V_46 -> V_70 ) ;
}
return 0 ;
}
static void F_36 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_46 * V_46 = F_13 ( V_18 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
struct V_73 * V_115 , * V_22 ;
F_37 (mode, t, &connector->probed_modes, head) {
if ( V_22 -> type & V_77 ) {
if ( V_22 -> V_75 != V_74 -> V_75 ||
V_22 -> V_76 != V_74 -> V_76 )
memcpy ( V_74 , V_22 , sizeof( * V_22 ) ) ;
}
}
if ( ! V_74 -> clock ) {
F_37 (mode, t, &connector->probed_modes, head) {
if ( V_22 -> V_75 == V_74 -> V_75 &&
V_22 -> V_76 == V_74 -> V_76 ) {
* V_74 = * V_22 ;
F_38 ( V_74 , V_116 ) ;
F_23 ( L_6 ) ;
break;
}
}
}
if ( ! V_74 -> clock ) {
F_23 ( L_7 ) ;
V_46 -> V_117 = V_118 ;
}
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_17 * V_18 ;
int V_114 = 0 ;
struct V_73 * V_22 ;
if ( V_8 -> V_119 ) {
V_114 = F_40 ( V_8 ) ;
if ( V_114 > 0 ) {
V_18 = F_20 ( V_2 ) ;
if ( V_18 ) {
F_36 ( V_18 , V_2 ) ;
F_29 ( V_18 , V_2 ) ;
}
return V_114 ;
}
}
V_18 = F_20 ( V_2 ) ;
if ( ! V_18 )
return 0 ;
V_22 = F_25 ( V_18 ) ;
if ( V_22 ) {
V_114 = 1 ;
F_30 ( V_2 , V_22 ) ;
V_2 -> V_33 . V_120 = V_22 -> V_120 ;
V_2 -> V_33 . V_121 = V_22 -> V_121 ;
F_29 ( V_18 , V_2 ) ;
}
return V_114 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_73 * V_22 )
{
struct V_17 * V_18 = F_20 ( V_2 ) ;
if ( ( V_22 -> V_75 < 320 ) || ( V_22 -> V_76 < 240 ) )
return V_122 ;
if ( V_18 ) {
struct V_46 * V_46 = F_13 ( V_18 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( ( V_22 -> V_75 > V_74 -> V_75 ) ||
( V_22 -> V_76 > V_74 -> V_76 ) )
return V_122 ;
if ( V_46 -> V_117 == V_118 ) {
if ( ( V_22 -> V_75 != V_74 -> V_75 ) ||
( V_22 -> V_76 != V_74 -> V_76 ) )
return V_122 ;
}
}
return V_123 ;
}
static enum V_53
F_42 ( struct V_1 * V_2 , bool V_124 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_20 ( V_2 ) ;
enum V_53 V_114 = V_72 ;
if ( V_18 ) {
struct V_46 * V_46 = F_13 ( V_18 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( V_74 -> V_75 >= 320 && V_74 -> V_76 >= 240 )
V_114 = V_62 ;
}
if ( V_8 -> V_32 )
V_114 = V_62 ;
else {
if ( V_8 -> V_119 ) {
V_8 -> V_32 = F_43 ( & V_8 -> V_70 ,
& V_8 -> V_119 -> V_125 ) ;
if ( V_8 -> V_32 )
V_114 = V_62 ;
}
}
F_14 ( V_2 , V_114 ) ;
return V_114 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_32 )
F_45 ( V_8 -> V_32 ) ;
F_45 ( V_8 -> V_36 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
T_1 V_126 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_46 * V_46 ;
enum V_127 V_117 ;
F_23 ( L_8 ) ;
if ( V_88 != V_4 -> V_128 . V_129 )
return 0 ;
if ( V_2 -> V_18 )
V_46 = F_13 ( V_2 -> V_18 ) ;
else {
struct V_42 * V_43 = V_2 -> V_44 ;
V_46 = F_13 ( V_43 -> V_45 ( V_2 ) ) ;
}
switch ( V_126 ) {
case V_130 : V_117 = V_118 ; break;
case V_131 : V_117 = V_132 ; break;
case V_133 : V_117 = V_134 ; break;
default:
case V_135 : V_117 = V_136 ; break;
}
if ( V_46 -> V_117 == V_117 )
return 0 ;
V_46 -> V_117 = V_117 ;
F_7 ( & V_46 -> V_70 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_114 ;
V_114 = F_40 ( V_8 ) ;
return V_114 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_73 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_22 -> clock / 10 ) > V_6 -> clock . V_137 )
return V_138 ;
return V_123 ;
}
static enum V_53
F_51 ( struct V_1 * V_2 , bool V_124 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_17 * V_18 ;
struct V_139 * V_140 ;
bool V_141 = false ;
enum V_53 V_114 = V_72 ;
V_18 = F_20 ( V_2 ) ;
if ( ! V_18 )
V_114 = V_72 ;
if ( V_8 -> V_119 )
V_141 = F_52 ( V_8 ) ;
if ( V_141 ) {
V_8 -> V_142 = false ;
if ( V_8 -> V_32 ) {
F_45 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
}
V_8 -> V_32 = F_43 ( & V_8 -> V_70 , & V_8 -> V_119 -> V_125 ) ;
if ( ! V_8 -> V_32 ) {
F_53 ( L_9 ,
F_24 ( V_2 ) ) ;
V_114 = V_62 ;
} else {
V_8 -> V_31 = ! ! ( V_8 -> V_32 -> V_143 & V_144 ) ;
if ( V_8 -> V_31 && V_8 -> V_145 ) {
F_45 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
V_114 = V_72 ;
} else
V_114 = V_62 ;
}
} else {
if ( ! V_124 ) {
if ( V_8 -> V_142 )
return V_2 -> V_54 ;
else
return V_114 ;
}
if ( V_8 -> V_110 && V_18 ) {
V_140 = V_18 -> V_44 ;
V_114 = V_140 -> V_146 ( V_18 , V_2 ) ;
if ( V_114 != V_72 )
V_8 -> V_142 = true ;
}
}
if ( V_114 == V_62 )
V_114 = F_21 ( V_2 , V_18 , V_114 , true ) ;
if ( ( ! V_6 -> V_63 ) &&
( V_114 == V_72 ) &&
V_6 -> V_90 . V_147 ) {
V_114 = V_62 ;
}
F_14 ( V_2 , V_114 ) ;
return V_114 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_73 * V_148 ;
struct V_17 * V_18 ;
V_18 = F_20 ( V_2 ) ;
if ( ! V_18 )
return 0 ;
if ( V_6 -> V_149 >= V_150 )
F_29 ( V_18 , V_2 ) ;
else {
V_148 = F_28 ( V_4 , 800 , 600 , 60 , false , false , false ) ;
V_148 -> type = V_78 | V_77 ;
F_30 ( V_2 , V_148 ) ;
}
return 1 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_73 * V_22 )
{
if ( ( V_22 -> V_75 > 1024 ) || ( V_22 -> V_76 > 768 ) )
return V_151 ;
return V_123 ;
}
static enum V_53
F_56 ( struct V_1 * V_2 , bool V_124 )
{
struct V_17 * V_18 ;
struct V_139 * V_140 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_53 V_114 = V_72 ;
if ( ! V_8 -> V_110 )
return V_114 ;
V_18 = F_20 ( V_2 ) ;
if ( ! V_18 )
V_114 = V_72 ;
else {
V_140 = V_18 -> V_44 ;
V_114 = V_140 -> V_146 ( V_18 , V_2 ) ;
}
if ( V_114 == V_62 )
V_114 = F_21 ( V_2 , V_18 , V_114 , false ) ;
F_14 ( V_2 , V_114 ) ;
return V_114 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_114 ;
V_114 = F_40 ( V_8 ) ;
return V_114 ;
}
static bool F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_53 V_54 ;
if ( V_6 -> V_149 >= V_152
&& V_8 -> V_9 . V_9 != V_10 ) {
if ( F_4 ( V_6 , V_8 -> V_9 . V_9 ) )
V_54 = V_62 ;
else
V_54 = V_72 ;
if ( V_2 -> V_54 == V_54 )
return true ;
}
return false ;
}
static enum V_53
F_59 ( struct V_1 * V_2 , bool V_124 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_17 * V_18 = NULL ;
struct V_139 * V_140 ;
struct V_55 * V_56 ;
int V_58 ;
enum V_53 V_114 = V_72 ;
bool V_141 = false ;
if ( ! V_124 && F_58 ( V_2 ) )
return V_2 -> V_54 ;
if ( V_8 -> V_119 )
V_141 = F_52 ( V_8 ) ;
if ( V_141 ) {
V_8 -> V_142 = false ;
if ( V_8 -> V_32 ) {
F_45 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
}
V_8 -> V_32 = F_43 ( & V_8 -> V_70 , & V_8 -> V_119 -> V_125 ) ;
if ( ! V_8 -> V_32 ) {
F_53 ( L_9 ,
F_24 ( V_2 ) ) ;
if ( ( V_6 -> V_149 == V_153 || V_6 -> V_149 == V_154 ) && V_8 -> V_70 . V_155 ) {
V_114 = V_72 ;
F_53 ( L_10 , F_24 ( V_2 ) ) ;
V_8 -> V_119 = NULL ;
}
} else {
V_8 -> V_31 = ! ! ( V_8 -> V_32 -> V_143 & V_144 ) ;
if ( ( ! V_8 -> V_31 ) && V_8 -> V_145 ) {
F_45 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
V_114 = V_72 ;
} else
V_114 = V_62 ;
if ( V_8 -> V_145 && ( V_114 == V_62 ) ) {
struct V_1 * V_156 ;
struct V_8 * V_157 ;
F_22 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_156 )
continue;
V_157 = F_2 ( V_156 ) ;
if ( V_157 -> V_145 &&
( V_157 -> V_119 -> V_158 . V_159 ==
V_8 -> V_119 -> V_158 . V_159 ) ) {
if ( V_156 -> V_13 != V_160 ) {
if ( ! F_4 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_45 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
V_114 = V_72 ;
}
}
}
}
}
}
}
if ( ( V_114 == V_62 ) && ( V_8 -> V_31 == true ) )
goto V_161;
if ( ( V_2 -> V_13 == V_34 ) ||
( V_2 -> V_13 == V_35 ) )
goto V_161;
if ( ! V_124 ) {
if ( V_8 -> V_142 )
V_114 = V_2 -> V_54 ;
goto V_161;
}
if ( V_8 -> V_110 ) {
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_15 ( V_2 -> V_4 ,
V_2 -> V_60 [ V_58 ] ,
V_61 ) ;
if ( ! V_56 )
continue;
V_18 = F_16 ( V_56 ) ;
if ( V_18 -> V_64 != V_103 &&
V_18 -> V_64 != V_102 )
continue;
V_140 = V_18 -> V_44 ;
if ( V_140 -> V_146 ) {
if ( V_114 != V_62 ) {
V_114 = V_140 -> V_146 ( V_18 , V_2 ) ;
if ( V_114 == V_62 ) {
V_8 -> V_31 = false ;
}
if ( V_114 != V_72 )
V_8 -> V_142 = true ;
}
break;
}
}
}
if ( ( V_114 == V_62 ) && ( V_8 -> V_31 == false ) &&
V_18 ) {
V_114 = F_21 ( V_2 , V_18 , V_114 , true ) ;
}
V_161:
if ( ( ! V_6 -> V_63 ) &&
( V_114 == V_72 ) &&
V_6 -> V_90 . V_147 ) {
V_8 -> V_31 = true ;
V_114 = V_62 ;
}
F_14 ( V_2 , V_114 ) ;
return V_114 ;
}
struct V_17 * F_60 ( struct V_1 * V_2 )
{
int V_65 = V_2 -> V_60 [ 0 ] ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_55 * V_56 ;
struct V_17 * V_18 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_15 ( V_2 -> V_4 , V_2 -> V_60 [ V_58 ] , V_61 ) ;
if ( ! V_56 )
continue;
V_18 = F_16 ( V_56 ) ;
if ( V_8 -> V_31 == true ) {
if ( V_18 -> V_64 == V_93 )
return V_18 ;
} else {
if ( V_18 -> V_64 == V_103 ||
V_18 -> V_64 == V_102 )
return V_18 ;
}
}
if ( V_65 ) {
V_56 = F_15 ( V_2 -> V_4 , V_65 , V_61 ) ;
if ( ! V_56 )
return NULL ;
V_18 = F_16 ( V_56 ) ;
return V_18 ;
}
return NULL ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_2 -> V_124 == V_162 )
V_8 -> V_31 = false ;
if ( V_2 -> V_124 == V_163 )
V_8 -> V_31 = true ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_73 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_31 &&
( V_6 -> V_149 == V_164 ) &&
( V_22 -> clock > 135000 ) )
return V_138 ;
if ( V_8 -> V_31 && ( V_22 -> clock > 165000 ) ) {
if ( ( V_8 -> V_165 == V_166 ) ||
( V_8 -> V_165 == V_167 ) ||
( V_8 -> V_165 == V_168 ) )
return V_123 ;
else if ( V_8 -> V_165 == V_169 ) {
if ( F_63 ( V_6 ) ) {
if ( V_22 -> clock > 340000 )
return V_138 ;
else
return V_123 ;
} else
return V_138 ;
} else
return V_138 ;
}
if ( ( V_22 -> clock / 10 ) > V_6 -> clock . V_137 )
return V_138 ;
return V_123 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_26 * V_170 = V_8 -> V_36 ;
if ( V_8 -> V_32 )
F_45 ( V_8 -> V_32 ) ;
if ( V_170 -> V_171 )
F_65 ( V_170 -> V_171 ) ;
F_45 ( V_8 -> V_36 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_26 * V_170 = V_8 -> V_36 ;
struct V_17 * V_18 = F_20 ( V_2 ) ;
int V_114 ;
if ( ( V_2 -> V_13 == V_40 ) ||
( V_2 -> V_13 == V_41 ) ) {
struct V_73 * V_22 ;
if ( V_2 -> V_13 == V_40 ) {
if ( ! V_170 -> V_172 )
F_67 ( V_2 ,
V_173 ) ;
V_114 = F_40 ( V_8 ) ;
if ( ! V_170 -> V_172 )
F_67 ( V_2 ,
V_174 ) ;
} else {
if ( F_68 ( V_2 ) !=
V_175 ) {
if ( V_18 )
F_69 ( V_18 ) ;
}
V_114 = F_40 ( V_8 ) ;
}
if ( V_114 > 0 ) {
if ( V_18 ) {
F_36 ( V_18 , V_2 ) ;
F_29 ( V_18 , V_2 ) ;
}
return V_114 ;
}
if ( ! V_18 )
return 0 ;
V_22 = F_25 ( V_18 ) ;
if ( V_22 ) {
V_114 = 1 ;
F_30 ( V_2 , V_22 ) ;
V_2 -> V_33 . V_120 = V_22 -> V_120 ;
V_2 -> V_33 . V_121 = V_22 -> V_121 ;
F_29 ( V_18 , V_2 ) ;
}
} else {
if ( F_68 ( V_2 ) !=
V_175 ) {
if ( V_18 )
F_69 ( V_18 ) ;
}
V_114 = F_40 ( V_8 ) ;
}
return V_114 ;
}
T_2 F_68 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_17 * V_18 ;
struct V_46 * V_46 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_15 ( V_2 -> V_4 , V_2 -> V_60 [ V_58 ] , V_61 ) ;
if ( ! V_56 )
continue;
V_18 = F_16 ( V_56 ) ;
V_46 = F_13 ( V_18 ) ;
switch ( V_46 -> V_176 ) {
case V_177 :
case V_178 :
return V_46 -> V_176 ;
default:
break;
}
}
return V_175 ;
}
bool F_70 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_17 * V_18 ;
struct V_46 * V_46 ;
int V_58 ;
bool V_179 = false ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_15 ( V_2 -> V_4 , V_2 -> V_60 [ V_58 ] , V_61 ) ;
if ( ! V_56 )
continue;
V_18 = F_16 ( V_56 ) ;
V_46 = F_13 ( V_18 ) ;
if ( V_46 -> V_180 & V_181 )
V_179 = true ;
}
return V_179 ;
}
bool F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_12 ( V_6 ) &&
( V_6 -> clock . V_182 >= 53900 ) &&
F_70 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_53
F_72 ( struct V_1 * V_2 , bool V_124 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_53 V_114 = V_72 ;
struct V_26 * V_170 = V_8 -> V_36 ;
struct V_17 * V_18 = F_20 ( V_2 ) ;
if ( ! V_124 && F_58 ( V_2 ) )
return V_2 -> V_54 ;
if ( V_8 -> V_32 ) {
F_45 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
}
if ( ( V_2 -> V_13 == V_40 ) ||
( V_2 -> V_13 == V_41 ) ) {
if ( V_18 ) {
struct V_46 * V_46 = F_13 ( V_18 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( V_74 -> V_75 >= 320 && V_74 -> V_76 >= 240 )
V_114 = V_62 ;
}
V_170 -> V_37 = V_38 ;
if ( ! V_170 -> V_172 )
F_67 ( V_2 ,
V_173 ) ;
if ( F_73 ( V_8 ) )
V_114 = V_62 ;
if ( ! V_170 -> V_172 )
F_67 ( V_2 ,
V_174 ) ;
} else if ( F_68 ( V_2 ) !=
V_175 ) {
V_170 -> V_37 = V_38 ;
F_73 ( V_8 ) ;
if ( V_18 ) {
F_69 ( V_18 ) ;
if ( F_52 ( V_8 ) )
V_114 = V_62 ;
else if ( V_8 -> V_110 ) {
struct V_139 * V_140 = V_18 -> V_44 ;
V_114 = V_140 -> V_146 ( V_18 , V_2 ) ;
}
}
} else {
V_170 -> V_37 = F_74 ( V_8 ) ;
if ( F_4 ( V_6 , V_8 -> V_9 . V_9 ) ) {
V_114 = V_62 ;
if ( V_170 -> V_37 == V_38 )
F_73 ( V_8 ) ;
} else {
if ( V_170 -> V_37 == V_38 ) {
if ( F_73 ( V_8 ) )
V_114 = V_62 ;
} else {
if ( F_52 ( V_8 ) )
V_114 = V_62 ;
}
}
}
F_14 ( V_2 , V_114 ) ;
return V_114 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_73 * V_22 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_26 * V_170 = V_8 -> V_36 ;
if ( ( V_2 -> V_13 == V_40 ) ||
( V_2 -> V_13 == V_41 ) ) {
struct V_17 * V_18 = F_20 ( V_2 ) ;
if ( ( V_22 -> V_75 < 320 ) || ( V_22 -> V_76 < 240 ) )
return V_122 ;
if ( V_18 ) {
struct V_46 * V_46 = F_13 ( V_18 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( ( V_22 -> V_75 > V_74 -> V_75 ) ||
( V_22 -> V_76 > V_74 -> V_76 ) )
return V_122 ;
if ( V_46 -> V_117 == V_118 ) {
if ( ( V_22 -> V_75 != V_74 -> V_75 ) ||
( V_22 -> V_76 != V_74 -> V_76 ) )
return V_122 ;
}
}
return V_123 ;
} else {
if ( ( V_170 -> V_37 == V_38 ) ||
( V_170 -> V_37 == V_39 ) )
return F_76 ( V_2 , V_22 ) ;
else
return V_123 ;
}
}
void
F_77 ( struct V_3 * V_4 ,
T_3 V_183 ,
T_3 V_184 ,
int V_13 ,
struct V_185 * V_186 ,
T_3 V_187 ,
T_4 V_165 ,
struct V_188 * V_9 ,
struct V_189 * V_190 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_26 * V_170 ;
struct V_17 * V_18 ;
struct V_46 * V_46 ;
T_3 V_191 = V_192 ;
bool V_145 = false ;
bool V_193 = false ;
if ( V_13 == V_194 )
return;
if ( ( ( V_13 == V_195 ) ||
( V_13 == V_196 ) ||
( V_13 == V_197 ) ) &&
( V_198 == 0 ) )
return;
F_22 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_183 == V_183 ) {
V_8 -> V_84 |= V_184 ;
return;
}
if ( V_8 -> V_119 && V_186 -> V_199 ) {
if ( V_8 -> V_119 -> V_158 . V_159 == V_186 -> V_159 ) {
V_8 -> V_145 = true ;
V_145 = true ;
}
if ( V_8 -> V_200 && V_190 -> V_201 &&
( V_8 -> V_190 . V_202 == V_190 -> V_202 ) ) {
V_8 -> V_145 = false ;
V_145 = false ;
}
}
}
F_22 (encoder, &dev->mode_config.encoder_list, head) {
V_46 = F_13 ( V_18 ) ;
if ( V_46 -> V_84 & V_184 ) {
switch ( V_46 -> V_176 ) {
case V_177 :
case V_178 :
V_193 = true ;
break;
default:
break;
}
}
}
V_8 = F_78 ( sizeof( struct V_8 ) , V_203 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_70 ;
V_8 -> V_183 = V_183 ;
V_8 -> V_84 = V_184 ;
V_8 -> V_145 = V_145 ;
V_8 -> V_165 = V_165 ;
V_8 -> V_9 = * V_9 ;
V_8 -> V_190 = * V_190 ;
if ( V_190 -> V_201 || V_190 -> V_204 ) {
V_8 -> V_200 = F_79 ( V_6 , & V_190 -> V_205 ) ;
if ( ! V_8 -> V_200 )
F_53 ( L_11 ) ;
}
if ( V_193 ) {
V_170 = F_78 ( sizeof( struct V_26 ) , V_203 ) ;
if ( ! V_170 )
goto V_206;
V_170 -> V_187 = V_187 ;
V_8 -> V_36 = V_170 ;
F_80 ( V_4 , & V_8 -> V_70 , & V_207 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_208 ) ;
if ( V_186 -> V_199 ) {
if ( V_13 == V_40 )
V_170 -> V_171 = F_82 ( V_4 , V_186 , L_12 ) ;
else
V_170 -> V_171 = F_82 ( V_4 , V_186 , L_13 ) ;
if ( ! V_170 -> V_171 )
F_53 ( L_14 ) ;
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_15 ) ;
}
switch ( V_13 ) {
case V_160 :
case V_209 :
default:
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
break;
case V_29 :
case V_34 :
case V_35 :
case V_30 :
case V_14 :
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_95 ,
V_212 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_97 ,
0 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_99 ,
0 ) ;
V_191 = V_213 ;
V_2 -> V_210 = true ;
if ( V_13 == V_30 )
V_2 -> V_211 = true ;
else
V_2 -> V_211 = false ;
if ( V_13 == V_29 ) {
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
}
break;
case V_41 :
case V_40 :
F_83 ( & V_8 -> V_70 ,
V_4 -> V_128 . V_129 ,
V_135 ) ;
V_191 = V_213 ;
V_2 -> V_210 = false ;
V_2 -> V_211 = false ;
break;
}
} else {
switch ( V_13 ) {
case V_160 :
F_80 ( V_4 , & V_8 -> V_70 , & V_214 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_215 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_16 ) ;
}
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_216 = V_217 ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
break;
case V_209 :
F_80 ( V_4 , & V_8 -> V_70 , & V_214 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_215 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_17 ) ;
}
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
break;
case V_29 :
case V_34 :
V_170 = F_78 ( sizeof( struct V_26 ) , V_203 ) ;
if ( ! V_170 )
goto V_206;
V_170 -> V_187 = V_187 ;
V_8 -> V_36 = V_170 ;
F_80 ( V_4 , & V_8 -> V_70 , & V_218 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_219 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_18 ) ;
}
V_191 = V_213 ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_91 ,
1 ) ;
if ( F_32 ( V_6 ) ) {
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_95 ,
V_212 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_97 ,
0 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_99 ,
0 ) ;
}
if ( V_13 == V_29 ) {
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
}
V_2 -> V_210 = true ;
if ( V_13 == V_29 )
V_2 -> V_211 = true ;
else
V_2 -> V_211 = false ;
break;
case V_35 :
case V_30 :
V_170 = F_78 ( sizeof( struct V_26 ) , V_203 ) ;
if ( ! V_170 )
goto V_206;
V_170 -> V_187 = V_187 ;
V_8 -> V_36 = V_170 ;
F_80 ( V_4 , & V_8 -> V_70 , & V_218 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_219 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_19 ) ;
}
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_91 ,
1 ) ;
if ( F_32 ( V_6 ) ) {
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_95 ,
V_212 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_97 ,
0 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_99 ,
0 ) ;
}
V_191 = V_213 ;
V_2 -> V_210 = true ;
if ( V_13 == V_30 )
V_2 -> V_211 = true ;
else
V_2 -> V_211 = false ;
break;
case V_14 :
V_170 = F_78 ( sizeof( struct V_26 ) , V_203 ) ;
if ( ! V_170 )
goto V_206;
V_170 -> V_187 = V_187 ;
V_8 -> V_36 = V_170 ;
F_80 ( V_4 , & V_8 -> V_70 , & V_207 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_208 ) ;
if ( V_186 -> V_199 ) {
V_170 -> V_171 = F_82 ( V_4 , V_186 , L_13 ) ;
if ( ! V_170 -> V_171 )
F_53 ( L_14 ) ;
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_15 ) ;
}
V_191 = V_213 ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_91 ,
1 ) ;
if ( F_32 ( V_6 ) ) {
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_95 ,
V_212 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_97 ,
0 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_99 ,
0 ) ;
}
V_2 -> V_210 = true ;
V_2 -> V_211 = false ;
break;
case V_40 :
V_170 = F_78 ( sizeof( struct V_26 ) , V_203 ) ;
if ( ! V_170 )
goto V_206;
V_170 -> V_187 = V_187 ;
V_8 -> V_36 = V_170 ;
F_80 ( V_4 , & V_8 -> V_70 , & V_207 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_208 ) ;
if ( V_186 -> V_199 ) {
V_170 -> V_171 = F_82 ( V_4 , V_186 , L_12 ) ;
if ( ! V_170 -> V_171 )
F_53 ( L_14 ) ;
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_15 ) ;
}
F_83 ( & V_8 -> V_70 ,
V_4 -> V_128 . V_129 ,
V_135 ) ;
V_191 = V_213 ;
V_2 -> V_210 = false ;
V_2 -> V_211 = false ;
break;
case V_195 :
case V_196 :
case V_197 :
F_80 ( V_4 , & V_8 -> V_70 , & V_220 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_221 ) ;
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_101 ,
F_84 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_210 = false ;
V_2 -> V_211 = false ;
break;
case V_41 :
V_170 = F_78 ( sizeof( struct V_26 ) , V_203 ) ;
if ( ! V_170 )
goto V_206;
V_170 -> V_187 = V_187 ;
V_8 -> V_36 = V_170 ;
F_80 ( V_4 , & V_8 -> V_70 , & V_222 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_223 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_20 ) ;
}
F_83 ( & V_8 -> V_70 ,
V_4 -> V_128 . V_129 ,
V_135 ) ;
V_191 = V_213 ;
V_2 -> V_210 = false ;
V_2 -> V_211 = false ;
break;
}
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_186 -> V_199 )
V_2 -> V_216 = V_217 ;
} else
V_2 -> V_216 = V_224 ;
V_2 -> V_33 . V_191 = V_191 ;
F_85 ( V_2 ) ;
return;
V_206:
F_47 ( V_2 ) ;
F_45 ( V_2 ) ;
}
void
F_86 ( struct V_3 * V_4 ,
T_3 V_183 ,
T_3 V_184 ,
int V_13 ,
struct V_185 * V_186 ,
T_4 V_165 ,
struct V_188 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
T_3 V_191 = V_192 ;
if ( V_13 == V_194 )
return;
if ( ( ( V_13 == V_195 ) ||
( V_13 == V_196 ) ||
( V_13 == V_197 ) ) &&
( V_198 == 0 ) )
return;
F_22 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_183 == V_183 ) {
V_8 -> V_84 |= V_184 ;
return;
}
}
V_8 = F_78 ( sizeof( struct V_8 ) , V_203 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_70 ;
V_8 -> V_183 = V_183 ;
V_8 -> V_84 = V_184 ;
V_8 -> V_165 = V_165 ;
V_8 -> V_9 = * V_9 ;
switch ( V_13 ) {
case V_160 :
F_80 ( V_4 , & V_8 -> V_70 , & V_214 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_215 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_16 ) ;
}
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_216 = V_217 ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
break;
case V_209 :
F_80 ( V_4 , & V_8 -> V_70 , & V_214 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_215 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_17 ) ;
}
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
break;
case V_29 :
case V_34 :
F_80 ( V_4 , & V_8 -> V_70 , & V_218 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_219 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_18 ) ;
}
if ( V_13 == V_29 ) {
V_8 -> V_110 = true ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
1 ) ;
}
V_191 = V_213 ;
V_2 -> V_210 = true ;
if ( V_13 == V_29 )
V_2 -> V_211 = true ;
else
V_2 -> V_211 = false ;
break;
case V_195 :
case V_196 :
case V_197 :
F_80 ( V_4 , & V_8 -> V_70 , & V_220 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_221 ) ;
V_8 -> V_110 = true ;
if ( V_6 -> V_149 == V_225 || V_6 -> V_149 == V_226 )
V_8 -> V_110 = false ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_109 ,
V_8 -> V_110 ) ;
F_83 ( & V_8 -> V_70 ,
V_6 -> V_90 . V_101 ,
F_87 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_210 = false ;
V_2 -> V_211 = false ;
break;
case V_41 :
F_80 ( V_4 , & V_8 -> V_70 , & V_222 , V_13 ) ;
F_81 ( & V_8 -> V_70 , & V_223 ) ;
if ( V_186 -> V_199 ) {
V_8 -> V_119 = F_79 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_119 )
F_53 ( L_20 ) ;
}
F_83 ( & V_8 -> V_70 ,
V_4 -> V_128 . V_129 ,
V_135 ) ;
V_191 = V_213 ;
V_2 -> V_210 = false ;
V_2 -> V_211 = false ;
break;
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_186 -> V_199 )
V_2 -> V_216 = V_217 ;
} else
V_2 -> V_216 = V_224 ;
V_2 -> V_33 . V_191 = V_191 ;
F_85 ( V_2 ) ;
if ( V_13 == V_41 ) {
struct V_17 * V_17 ;
F_22 (drm_encoder, &dev->mode_config.encoder_list, head) {
struct V_46 * V_46 ;
V_46 = F_13 ( V_17 ) ;
if ( V_46 -> V_176 == V_227 )
F_88 ( V_46 , V_2 ) ;
}
}
}
