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
struct V_15 * V_16 =
V_8 -> V_17 ;
if ( V_16 -> V_18 != V_19 )
return;
V_16 -> V_18 = F_4 ( V_8 ) ;
if ( V_16 -> V_18 == V_19 ) {
int V_20 = V_2 -> V_11 ;
if ( ! F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_6 ( V_2 , V_21 ) ;
} else if ( F_7 ( V_8 ) ) {
V_2 -> V_11 = V_21 ;
F_6 ( V_2 , V_12 ) ;
}
V_2 -> V_11 = V_20 ;
}
}
}
static void F_8 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_25 ;
if ( V_25 && V_25 -> V_26 ) {
F_9 ( V_25 , & V_25 -> V_27 ,
V_25 -> V_28 , V_25 -> V_29 , V_25 -> V_30 -> V_31 ) ;
}
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_16 ;
int V_32 = 8 ;
int V_33 , V_34 ;
switch ( V_2 -> V_13 ) {
case V_35 :
case V_36 :
if ( V_8 -> V_37 ) {
if ( F_11 ( V_8 -> V_38 ) ) {
if ( V_2 -> V_39 . V_32 )
V_32 = V_2 -> V_39 . V_32 ;
}
}
break;
case V_40 :
case V_41 :
if ( F_11 ( V_8 -> V_38 ) ) {
if ( V_2 -> V_39 . V_32 )
V_32 = V_2 -> V_39 . V_32 ;
}
break;
case V_14 :
V_16 = V_8 -> V_17 ;
if ( ( V_16 -> V_18 == V_19 ) ||
( V_16 -> V_18 == V_42 ) ||
F_11 ( V_8 -> V_38 ) ) {
if ( V_2 -> V_39 . V_32 )
V_32 = V_2 -> V_39 . V_32 ;
}
break;
case V_43 :
case V_44 :
if ( V_2 -> V_39 . V_32 )
V_32 = V_2 -> V_39 . V_32 ;
else if ( F_12 ( V_6 ) || F_13 ( V_6 ) ) {
struct V_45 * V_46 =
V_2 -> V_47 ;
struct V_22 * V_23 = V_46 -> V_48 ( V_2 ) ;
struct V_49 * V_49 = F_14 ( V_23 ) ;
struct V_50 * V_51 = V_49 -> V_52 ;
if ( V_51 -> V_53 & V_54 )
V_32 = 6 ;
else if ( V_51 -> V_53 & V_55 )
V_32 = 8 ;
}
break;
}
if ( F_11 ( V_8 -> V_38 ) ) {
if ( ( V_32 > 8 ) && ! F_15 ( V_6 ) ) {
F_16 ( L_1 ,
V_2 -> V_56 , V_32 ) ;
V_32 = 8 ;
}
if ( V_32 > 12 ) {
F_16 ( L_2 ,
V_2 -> V_56 , V_32 ) ;
V_32 = 12 ;
}
if ( V_2 -> V_34 > 0 ) {
V_33 = V_8 -> V_57 ;
V_34 = V_2 -> V_34 * 1000 ;
F_16 ( L_3 ,
V_2 -> V_56 , V_33 , V_34 ) ;
if ( ( V_32 == 12 ) && ( V_33 * 3 / 2 > V_34 ) ) {
if ( ( V_2 -> V_39 . V_58 & V_59 ) &&
( V_33 * 5 / 4 <= V_34 ) )
V_32 = 10 ;
else
V_32 = 8 ;
F_16 ( L_4 ,
V_2 -> V_56 , V_32 ) ;
}
if ( ( V_32 == 10 ) && ( V_33 * 5 / 4 > V_34 ) ) {
V_32 = 8 ;
F_16 ( L_5 ,
V_2 -> V_56 , V_32 ) ;
}
}
}
if ( ( V_60 == 0 ) && ( V_32 > 8 ) )
V_32 = 8 ;
F_16 ( L_6 ,
V_2 -> V_56 , V_2 -> V_39 . V_32 , V_32 ) ;
return V_32 ;
}
static void
F_17 ( struct V_1 * V_2 , enum V_61 V_62 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_48 = NULL ;
struct V_22 * V_23 = NULL ;
struct V_45 * V_46 = V_2 -> V_47 ;
struct V_63 * V_64 ;
bool V_65 ;
int V_66 ;
V_48 = V_46 -> V_48 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] == 0 )
break;
V_64 = F_18 ( V_2 -> V_4 ,
V_2 -> V_68 [ V_66 ] ,
V_69 ) ;
if ( ! V_64 )
continue;
V_23 = F_19 ( V_64 ) ;
if ( ( V_23 == V_48 ) && ( V_62 == V_70 ) )
V_65 = true ;
else
V_65 = false ;
if ( V_6 -> V_71 )
F_20 ( V_2 , V_23 , V_65 ) ;
else
F_21 ( V_2 , V_23 , V_65 ) ;
}
}
static struct V_22 * F_22 ( struct V_1 * V_2 , int V_72 )
{
struct V_63 * V_64 ;
struct V_22 * V_23 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] == 0 )
break;
V_64 = F_18 ( V_2 -> V_4 , V_2 -> V_68 [ V_66 ] , V_69 ) ;
if ( ! V_64 )
continue;
V_23 = F_19 ( V_64 ) ;
if ( V_23 -> V_72 == V_72 )
return V_23 ;
}
return NULL ;
}
static struct V_22 * F_23 ( struct V_1 * V_2 )
{
int V_73 = V_2 -> V_68 [ 0 ] ;
struct V_63 * V_64 ;
struct V_22 * V_23 ;
if ( V_73 ) {
V_64 = F_18 ( V_2 -> V_4 , V_73 , V_69 ) ;
if ( ! V_64 )
return NULL ;
V_23 = F_19 ( V_64 ) ;
return V_23 ;
}
return NULL ;
}
static enum V_61
F_24 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
enum V_61 V_74 ,
bool V_75 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_76 ;
struct V_8 * V_77 ;
int V_66 ;
F_25 (conflict, &dev->mode_config.connector_list, head) {
if ( V_76 == V_2 )
continue;
V_77 = F_2 ( V_76 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( V_76 -> V_68 [ V_66 ] == 0 )
break;
if ( V_76 -> V_68 [ V_66 ] == V_23 -> V_78 . V_79 ) {
if ( V_76 -> V_62 != V_70 )
continue;
if ( V_77 -> V_37 )
continue;
if ( V_75 == true ) {
F_26 ( L_7 ,
V_76 -> V_56 ) ;
F_26 ( L_8 ,
V_2 -> V_56 ) ;
V_76 -> V_62 = V_80 ;
F_17 ( V_76 , V_80 ) ;
} else {
F_26 ( L_9 ,
V_2 -> V_56 ) ;
F_26 ( L_8 ,
V_76 -> V_56 ) ;
V_74 = V_80 ;
}
break;
}
}
}
return V_74 ;
}
static struct V_81 * F_27 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_49 * V_49 = F_14 ( V_23 ) ;
struct V_81 * V_27 = NULL ;
struct V_81 * V_82 = & V_49 -> V_82 ;
if ( V_82 -> V_83 != 0 &&
V_82 -> V_84 != 0 &&
V_82 -> clock != 0 ) {
V_27 = F_28 ( V_4 , V_82 ) ;
V_27 -> type = V_85 | V_86 ;
F_29 ( V_27 ) ;
F_26 ( L_10 , V_27 -> V_56 ) ;
} else if ( V_82 -> V_83 != 0 &&
V_82 -> V_84 != 0 ) {
V_27 = F_30 ( V_4 , V_82 -> V_83 , V_82 -> V_84 , 60 , true , false , false ) ;
V_27 -> type = V_85 | V_86 ;
F_26 ( L_11 , V_27 -> V_56 ) ;
}
return V_27 ;
}
static void F_31 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_49 * V_49 = F_14 ( V_23 ) ;
struct V_81 * V_27 = NULL ;
struct V_81 * V_82 = & V_49 -> V_82 ;
int V_66 ;
struct V_87 {
int V_88 ;
int V_89 ;
} V_90 [ 17 ] = {
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
for ( V_66 = 0 ; V_66 < 17 ; V_66 ++ ) {
if ( V_49 -> V_91 & ( V_92 ) ) {
if ( V_90 [ V_66 ] . V_88 > 1024 ||
V_90 [ V_66 ] . V_89 > 768 )
continue;
}
if ( V_49 -> V_91 & ( V_93 ) ) {
if ( V_90 [ V_66 ] . V_88 > V_82 -> V_83 ||
V_90 [ V_66 ] . V_89 > V_82 -> V_84 ||
( V_90 [ V_66 ] . V_88 == V_82 -> V_83 &&
V_90 [ V_66 ] . V_89 == V_82 -> V_84 ) )
continue;
}
if ( V_90 [ V_66 ] . V_88 < 320 || V_90 [ V_66 ] . V_89 < 200 )
continue;
V_27 = F_30 ( V_4 , V_90 [ V_66 ] . V_88 , V_90 [ V_66 ] . V_89 , 60 , false , false , false ) ;
F_32 ( V_2 , V_27 ) ;
}
}
static int F_33 ( struct V_1 * V_2 , struct V_94 * V_95 ,
T_1 V_96 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_23 ;
struct V_49 * V_49 ;
if ( V_95 == V_6 -> V_97 . V_98 ) {
struct V_50 * V_51 ;
bool V_99 ;
V_23 = F_22 ( V_2 , V_100 ) ;
if ( ! V_23 )
return 0 ;
V_49 = F_14 ( V_23 ) ;
if ( ! V_49 -> V_52 )
return 0 ;
V_51 = V_49 -> V_52 ;
V_99 = V_96 ? true : false ;
if ( V_51 -> V_101 != V_99 ) {
V_51 -> V_101 = V_99 ;
F_8 ( & V_49 -> V_78 ) ;
}
}
if ( V_95 == V_6 -> V_97 . V_102 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_22 ( V_2 , V_100 ) ;
if ( ! V_23 )
return 0 ;
V_49 = F_14 ( V_23 ) ;
if ( V_8 -> V_103 != V_96 ) {
V_8 -> V_103 = V_96 ;
F_8 ( & V_49 -> V_78 ) ;
}
}
if ( V_95 == V_6 -> V_97 . V_104 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_22 ( V_2 , V_100 ) ;
if ( ! V_23 )
return 0 ;
V_49 = F_14 ( V_23 ) ;
if ( V_8 -> V_105 != V_96 ) {
V_8 -> V_105 = V_96 ;
F_8 ( & V_49 -> V_78 ) ;
}
}
if ( V_95 == V_6 -> V_97 . V_106 ) {
V_23 = F_22 ( V_2 , V_100 ) ;
if ( ! V_23 )
return 0 ;
V_49 = F_14 ( V_23 ) ;
if ( V_49 -> V_107 != V_96 ) {
V_49 -> V_107 = V_96 ;
F_8 ( & V_49 -> V_78 ) ;
}
}
if ( V_95 == V_6 -> V_97 . V_108 ) {
V_23 = F_22 ( V_2 , V_100 ) ;
if ( ! V_23 )
return 0 ;
V_49 = F_14 ( V_23 ) ;
if ( V_49 -> V_109 != V_96 ) {
V_49 -> V_109 = V_96 ;
F_8 ( & V_49 -> V_78 ) ;
}
}
if ( V_95 == V_6 -> V_97 . V_110 ) {
V_23 = F_22 ( V_2 , V_100 ) ;
if ( ! V_23 )
return 0 ;
V_49 = F_14 ( V_23 ) ;
if ( V_49 -> V_111 != V_96 ) {
V_49 -> V_111 = V_96 ;
F_8 ( & V_49 -> V_78 ) ;
}
}
if ( V_95 == V_6 -> V_97 . V_112 ) {
V_23 = F_22 ( V_2 , V_113 ) ;
if ( ! V_23 ) {
V_23 = F_22 ( V_2 , V_114 ) ;
}
if ( ! V_23 )
return 0 ;
V_49 = F_14 ( V_23 ) ;
if ( ! V_49 -> V_52 )
return 0 ;
if ( F_34 ( V_6 ) || V_115 ) {
struct V_116 * V_117 ;
V_117 = V_49 -> V_52 ;
V_117 -> V_118 = V_96 ;
} else {
struct V_119 * V_117 ;
V_117 = V_49 -> V_52 ;
V_117 -> V_118 = V_96 ;
}
F_8 ( & V_49 -> V_78 ) ;
}
if ( V_95 == V_6 -> V_97 . V_120 ) {
struct V_8 * V_8 =
F_2 ( V_2 ) ;
if ( V_96 == 0 )
V_8 -> V_121 = false ;
else
V_8 -> V_121 = true ;
}
if ( V_95 == V_6 -> V_97 . V_122 ) {
struct V_123 * V_124 = NULL ;
bool V_125 = false ;
V_23 = F_22 ( V_2 , V_100 ) ;
if ( ! V_23 )
return 0 ;
V_49 = F_14 ( V_23 ) ;
V_124 = V_49 -> V_52 ;
if ( ! V_124 )
return 0 ;
if ( V_96 == 0 ) {
if ( V_6 -> V_71 )
V_125 = F_35 ( V_49 , V_124 ) ;
else
V_125 = F_36 ( V_49 , V_124 ) ;
}
if ( V_96 == 1 || V_125 == false ) {
F_37 ( V_49 , V_124 ) ;
}
F_8 ( & V_49 -> V_78 ) ;
}
return 0 ;
}
static void F_38 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_49 * V_49 = F_14 ( V_23 ) ;
struct V_81 * V_82 = & V_49 -> V_82 ;
struct V_81 * V_126 , * V_27 ;
F_39 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> type & V_85 ) {
if ( V_27 -> V_83 != V_82 -> V_83 ||
V_27 -> V_84 != V_82 -> V_84 )
memcpy ( V_82 , V_27 , sizeof( * V_27 ) ) ;
}
}
if ( ! V_82 -> clock ) {
F_39 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> V_83 == V_82 -> V_83 &&
V_27 -> V_84 == V_82 -> V_84 ) {
* V_82 = * V_27 ;
F_40 ( V_82 , V_127 ) ;
F_26 ( L_12 ) ;
break;
}
}
}
if ( ! V_82 -> clock ) {
F_26 ( L_13 ) ;
V_49 -> V_128 = V_129 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
int V_125 = 0 ;
struct V_81 * V_27 ;
if ( V_8 -> V_130 ) {
V_125 = F_42 ( V_8 ) ;
if ( V_125 > 0 ) {
V_23 = F_23 ( V_2 ) ;
if ( V_23 ) {
F_38 ( V_23 , V_2 ) ;
F_31 ( V_23 , V_2 ) ;
}
return V_125 ;
}
}
V_23 = F_23 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
V_27 = F_27 ( V_23 ) ;
if ( V_27 ) {
V_125 = 1 ;
F_32 ( V_2 , V_27 ) ;
V_2 -> V_39 . V_131 = V_27 -> V_131 ;
V_2 -> V_39 . V_132 = V_27 -> V_132 ;
F_31 ( V_23 , V_2 ) ;
}
return V_125 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_81 * V_27 )
{
struct V_22 * V_23 = F_23 ( V_2 ) ;
if ( ( V_27 -> V_83 < 320 ) || ( V_27 -> V_84 < 240 ) )
return V_133 ;
if ( V_23 ) {
struct V_49 * V_49 = F_14 ( V_23 ) ;
struct V_81 * V_82 = & V_49 -> V_82 ;
if ( ( V_27 -> V_83 > V_82 -> V_83 ) ||
( V_27 -> V_84 > V_82 -> V_84 ) )
return V_133 ;
if ( V_49 -> V_128 == V_129 ) {
if ( ( V_27 -> V_83 != V_82 -> V_83 ) ||
( V_27 -> V_84 != V_82 -> V_84 ) )
return V_133 ;
}
}
return V_134 ;
}
static enum V_61
F_44 ( struct V_1 * V_2 , bool V_135 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = F_23 ( V_2 ) ;
enum V_61 V_125 = V_80 ;
int V_136 ;
V_136 = F_45 ( V_2 -> V_4 -> V_4 ) ;
if ( V_136 < 0 )
return V_80 ;
if ( V_23 ) {
struct V_49 * V_49 = F_14 ( V_23 ) ;
struct V_81 * V_82 = & V_49 -> V_82 ;
if ( V_82 -> V_83 >= 320 && V_82 -> V_84 >= 240 )
V_125 = V_70 ;
}
if ( V_8 -> V_38 )
V_125 = V_70 ;
else {
if ( V_8 -> V_130 ) {
V_8 -> V_38 = F_46 ( & V_8 -> V_78 ,
& V_8 -> V_130 -> V_137 ) ;
if ( V_8 -> V_38 )
V_125 = V_70 ;
}
}
F_17 ( V_2 , V_125 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
F_48 ( V_2 -> V_4 -> V_4 ) ;
return V_125 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_38 )
F_50 ( V_8 -> V_38 ) ;
F_50 ( V_8 -> V_17 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
T_1 V_138 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_49 ;
enum V_139 V_128 ;
F_26 ( L_14 ) ;
if ( V_95 != V_4 -> V_140 . V_141 )
return 0 ;
if ( V_2 -> V_23 )
V_49 = F_14 ( V_2 -> V_23 ) ;
else {
struct V_45 * V_46 = V_2 -> V_47 ;
V_49 = F_14 ( V_46 -> V_48 ( V_2 ) ) ;
}
switch ( V_138 ) {
case V_142 : V_128 = V_129 ; break;
case V_143 : V_128 = V_144 ; break;
case V_145 : V_128 = V_146 ; break;
default:
case V_147 : V_128 = V_148 ; break;
}
if ( V_49 -> V_128 == V_128 )
return 0 ;
V_49 -> V_128 = V_128 ;
F_8 ( & V_49 -> V_78 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_125 ;
V_125 = F_42 ( V_8 ) ;
return V_125 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_81 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_149 )
return V_150 ;
return V_134 ;
}
static enum V_61
F_56 ( struct V_1 * V_2 , bool V_135 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
struct V_151 * V_152 ;
bool V_153 = false ;
enum V_61 V_125 = V_80 ;
int V_136 ;
V_136 = F_45 ( V_2 -> V_4 -> V_4 ) ;
if ( V_136 < 0 )
return V_80 ;
V_23 = F_23 ( V_2 ) ;
if ( ! V_23 )
V_125 = V_80 ;
if ( V_8 -> V_130 )
V_153 = F_57 ( V_8 , false ) ;
if ( V_153 ) {
V_8 -> V_154 = false ;
if ( V_8 -> V_38 ) {
F_50 ( V_8 -> V_38 ) ;
V_8 -> V_38 = NULL ;
}
V_8 -> V_38 = F_46 ( & V_8 -> V_78 , & V_8 -> V_130 -> V_137 ) ;
if ( ! V_8 -> V_38 ) {
F_58 ( L_15 ,
V_2 -> V_56 ) ;
V_125 = V_70 ;
} else {
V_8 -> V_37 = ! ! ( V_8 -> V_38 -> V_155 & V_156 ) ;
if ( V_8 -> V_37 && V_8 -> V_157 ) {
F_50 ( V_8 -> V_38 ) ;
V_8 -> V_38 = NULL ;
V_125 = V_80 ;
} else
V_125 = V_70 ;
}
} else {
if ( ! V_135 ) {
if ( V_8 -> V_154 )
V_125 = V_2 -> V_62 ;
goto V_158;
}
if ( V_8 -> V_121 && V_23 ) {
V_152 = V_23 -> V_47 ;
V_125 = V_152 -> V_159 ( V_23 , V_2 ) ;
if ( V_125 != V_80 )
V_8 -> V_154 = true ;
}
}
if ( V_125 == V_70 )
V_125 = F_24 ( V_2 , V_23 , V_125 , true ) ;
if ( ( ! V_6 -> V_71 ) &&
( V_125 == V_80 ) &&
V_6 -> V_97 . V_160 ) {
V_125 = V_70 ;
}
F_17 ( V_2 , V_125 ) ;
V_158:
F_47 ( V_2 -> V_4 -> V_4 ) ;
F_48 ( V_2 -> V_4 -> V_4 ) ;
return V_125 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_81 * V_161 ;
struct V_22 * V_23 ;
V_23 = F_23 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
if ( V_6 -> V_162 >= V_163 )
F_31 ( V_23 , V_2 ) ;
else {
V_161 = F_30 ( V_4 , 800 , 600 , 60 , false , false , false ) ;
V_161 -> type = V_86 | V_85 ;
F_32 ( V_2 , V_161 ) ;
}
return 1 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_81 * V_27 )
{
if ( ( V_27 -> V_83 > 1024 ) || ( V_27 -> V_84 > 768 ) )
return V_164 ;
return V_134 ;
}
static enum V_61
F_61 ( struct V_1 * V_2 , bool V_135 )
{
struct V_22 * V_23 ;
struct V_151 * V_152 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_61 V_125 = V_80 ;
int V_136 ;
if ( ! V_8 -> V_121 )
return V_125 ;
V_136 = F_45 ( V_2 -> V_4 -> V_4 ) ;
if ( V_136 < 0 )
return V_80 ;
V_23 = F_23 ( V_2 ) ;
if ( ! V_23 )
V_125 = V_80 ;
else {
V_152 = V_23 -> V_47 ;
V_125 = V_152 -> V_159 ( V_23 , V_2 ) ;
}
if ( V_125 == V_70 )
V_125 = F_24 ( V_2 , V_23 , V_125 , false ) ;
F_17 ( V_2 , V_125 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
F_48 ( V_2 -> V_4 -> V_4 ) ;
return V_125 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_125 ;
V_125 = F_42 ( V_8 ) ;
return V_125 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_61 V_62 ;
if ( V_6 -> V_162 >= V_165
&& V_8 -> V_9 . V_9 != V_10 ) {
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) )
V_62 = V_70 ;
else
V_62 = V_80 ;
if ( V_2 -> V_62 == V_62 )
return true ;
}
return false ;
}
static enum V_61
F_64 ( struct V_1 * V_2 , bool V_135 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = NULL ;
struct V_151 * V_152 ;
struct V_63 * V_64 ;
int V_66 , V_136 ;
enum V_61 V_125 = V_80 ;
bool V_153 = false , V_166 = false ;
V_136 = F_45 ( V_2 -> V_4 -> V_4 ) ;
if ( V_136 < 0 )
return V_80 ;
if ( ! V_135 && F_63 ( V_2 ) ) {
V_125 = V_2 -> V_62 ;
goto exit;
}
if ( V_8 -> V_130 )
V_153 = F_57 ( V_8 , false ) ;
if ( V_153 ) {
V_8 -> V_154 = false ;
if ( V_8 -> V_38 ) {
F_50 ( V_8 -> V_38 ) ;
V_8 -> V_38 = NULL ;
}
V_8 -> V_38 = F_46 ( & V_8 -> V_78 , & V_8 -> V_130 -> V_137 ) ;
if ( ! V_8 -> V_38 ) {
F_58 ( L_15 ,
V_2 -> V_56 ) ;
if ( ( V_6 -> V_162 == V_167 || V_6 -> V_162 == V_168 ) && V_8 -> V_78 . V_169 ) {
V_125 = V_80 ;
F_58 ( L_16 ,
V_2 -> V_56 ) ;
V_8 -> V_130 = NULL ;
} else {
V_125 = V_70 ;
V_166 = true ;
}
} else {
V_8 -> V_37 = ! ! ( V_8 -> V_38 -> V_155 & V_156 ) ;
if ( ( ! V_8 -> V_37 ) && V_8 -> V_157 ) {
F_50 ( V_8 -> V_38 ) ;
V_8 -> V_38 = NULL ;
V_125 = V_80 ;
} else
V_125 = V_70 ;
if ( V_8 -> V_157 && ( V_125 == V_70 ) ) {
struct V_1 * V_170 ;
struct V_8 * V_171 ;
F_25 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_170 )
continue;
V_171 = F_2 ( V_170 ) ;
if ( V_171 -> V_157 &&
( V_171 -> V_130 -> V_172 . V_173 ==
V_8 -> V_130 -> V_172 . V_173 ) ) {
if ( V_170 -> V_13 != V_174 ) {
if ( ! F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_50 ( V_8 -> V_38 ) ;
V_8 -> V_38 = NULL ;
V_125 = V_80 ;
}
}
}
}
}
}
}
if ( ( V_125 == V_70 ) && ( V_8 -> V_37 == true ) )
goto V_158;
if ( ( V_2 -> V_13 == V_40 ) ||
( V_2 -> V_13 == V_41 ) )
goto V_158;
if ( ! V_135 ) {
if ( V_8 -> V_154 )
V_125 = V_2 -> V_62 ;
goto V_158;
}
if ( V_8 -> V_121 ) {
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] == 0 )
break;
V_64 = F_18 ( V_2 -> V_4 ,
V_2 -> V_68 [ V_66 ] ,
V_69 ) ;
if ( ! V_64 )
continue;
V_23 = F_19 ( V_64 ) ;
if ( V_23 -> V_72 != V_114 &&
V_23 -> V_72 != V_113 )
continue;
V_152 = V_23 -> V_47 ;
if ( V_152 -> V_159 ) {
if ( ! V_166 ) {
if ( V_125 != V_70 ) {
V_125 = V_152 -> V_159 ( V_23 , V_2 ) ;
if ( V_125 == V_70 ) {
V_8 -> V_37 = false ;
}
if ( V_125 != V_80 )
V_8 -> V_154 = true ;
}
} else {
enum V_61 V_175 ;
V_8 -> V_37 = true ;
V_175 = V_152 -> V_159 ( V_23 , V_2 ) ;
F_26 ( L_17 , V_23 -> V_72 , V_175 ) ;
if ( V_175 == V_70 )
V_8 -> V_37 = false ;
}
break;
}
}
}
if ( ( V_125 == V_70 ) && ( V_8 -> V_37 == false ) &&
V_23 ) {
V_125 = F_24 ( V_2 , V_23 , V_125 , true ) ;
}
V_158:
if ( ( ! V_6 -> V_71 ) &&
( V_125 == V_80 ) &&
V_6 -> V_97 . V_160 ) {
V_8 -> V_37 = true ;
V_125 = V_70 ;
}
F_17 ( V_2 , V_125 ) ;
exit:
F_47 ( V_2 -> V_4 -> V_4 ) ;
F_48 ( V_2 -> V_4 -> V_4 ) ;
return V_125 ;
}
static struct V_22 * F_65 ( struct V_1 * V_2 )
{
int V_73 = V_2 -> V_68 [ 0 ] ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_63 * V_64 ;
struct V_22 * V_23 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] == 0 )
break;
V_64 = F_18 ( V_2 -> V_4 , V_2 -> V_68 [ V_66 ] , V_69 ) ;
if ( ! V_64 )
continue;
V_23 = F_19 ( V_64 ) ;
if ( V_8 -> V_37 == true ) {
if ( V_23 -> V_72 == V_100 )
return V_23 ;
} else {
if ( V_23 -> V_72 == V_114 ||
V_23 -> V_72 == V_113 )
return V_23 ;
}
}
if ( V_73 ) {
V_64 = F_18 ( V_2 -> V_4 , V_73 , V_69 ) ;
if ( ! V_64 )
return NULL ;
V_23 = F_19 ( V_64 ) ;
return V_23 ;
}
return NULL ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_2 -> V_135 == V_176 )
V_8 -> V_37 = false ;
if ( V_2 -> V_135 == V_177 )
V_8 -> V_37 = true ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_81 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_37 &&
( V_6 -> V_162 == V_178 ) &&
( V_27 -> clock > 135000 ) )
return V_150 ;
if ( V_8 -> V_37 && ( V_27 -> clock > 165000 ) ) {
if ( ( V_8 -> V_179 == V_180 ) ||
( V_8 -> V_179 == V_181 ) ||
( V_8 -> V_179 == V_182 ) )
return V_134 ;
else if ( F_68 ( V_6 ) && F_11 ( V_8 -> V_38 ) ) {
if ( V_27 -> clock > 340000 )
return V_150 ;
else
return V_134 ;
} else {
return V_150 ;
}
}
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_149 )
return V_150 ;
return V_134 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_183 = V_8 -> V_17 ;
struct V_22 * V_23 = F_23 ( V_2 ) ;
int V_125 ;
if ( ( V_2 -> V_13 == V_43 ) ||
( V_2 -> V_13 == V_44 ) ) {
struct V_81 * V_27 ;
if ( V_2 -> V_13 == V_43 ) {
if ( ! V_183 -> V_184 )
F_70 ( V_2 ,
V_185 ) ;
V_125 = F_42 ( V_8 ) ;
if ( ! V_183 -> V_184 )
F_70 ( V_2 ,
V_186 ) ;
} else {
if ( F_71 ( V_2 ) !=
V_187 ) {
if ( V_23 )
F_72 ( V_23 ) ;
}
V_125 = F_42 ( V_8 ) ;
}
if ( V_125 > 0 ) {
if ( V_23 ) {
F_38 ( V_23 , V_2 ) ;
F_31 ( V_23 , V_2 ) ;
}
return V_125 ;
}
if ( ! V_23 )
return 0 ;
V_27 = F_27 ( V_23 ) ;
if ( V_27 ) {
V_125 = 1 ;
F_32 ( V_2 , V_27 ) ;
V_2 -> V_39 . V_131 = V_27 -> V_131 ;
V_2 -> V_39 . V_132 = V_27 -> V_132 ;
F_31 ( V_23 , V_2 ) ;
}
} else {
if ( F_71 ( V_2 ) !=
V_187 ) {
if ( V_23 )
F_72 ( V_23 ) ;
}
V_125 = F_42 ( V_8 ) ;
}
return V_125 ;
}
T_2 F_71 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_22 * V_23 ;
struct V_49 * V_49 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] == 0 )
break;
V_64 = F_18 ( V_2 -> V_4 , V_2 -> V_68 [ V_66 ] , V_69 ) ;
if ( ! V_64 )
continue;
V_23 = F_19 ( V_64 ) ;
V_49 = F_14 ( V_23 ) ;
switch ( V_49 -> V_188 ) {
case V_189 :
case V_190 :
return V_49 -> V_188 ;
default:
break;
}
}
return V_187 ;
}
bool F_73 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_22 * V_23 ;
struct V_49 * V_49 ;
int V_66 ;
bool V_191 = false ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( V_2 -> V_68 [ V_66 ] == 0 )
break;
V_64 = F_18 ( V_2 -> V_4 , V_2 -> V_68 [ V_66 ] , V_69 ) ;
if ( ! V_64 )
continue;
V_23 = F_19 ( V_64 ) ;
V_49 = F_14 ( V_23 ) ;
if ( V_49 -> V_192 & V_193 )
V_191 = true ;
}
return V_191 ;
}
bool F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_13 ( V_6 ) &&
( V_6 -> clock . V_194 >= 53900 ) &&
F_73 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_61
F_75 ( struct V_1 * V_2 , bool V_135 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_61 V_125 = V_80 ;
struct V_15 * V_183 = V_8 -> V_17 ;
struct V_22 * V_23 = F_23 ( V_2 ) ;
int V_136 ;
V_136 = F_45 ( V_2 -> V_4 -> V_4 ) ;
if ( V_136 < 0 )
return V_80 ;
if ( ! V_135 && F_63 ( V_2 ) ) {
V_125 = V_2 -> V_62 ;
goto V_158;
}
if ( V_8 -> V_38 ) {
F_50 ( V_8 -> V_38 ) ;
V_8 -> V_38 = NULL ;
}
if ( ( V_2 -> V_13 == V_43 ) ||
( V_2 -> V_13 == V_44 ) ) {
if ( V_23 ) {
struct V_49 * V_49 = F_14 ( V_23 ) ;
struct V_81 * V_82 = & V_49 -> V_82 ;
if ( V_82 -> V_83 >= 320 && V_82 -> V_84 >= 240 )
V_125 = V_70 ;
}
V_183 -> V_18 = V_19 ;
if ( ! V_183 -> V_184 )
F_70 ( V_2 ,
V_185 ) ;
if ( F_76 ( V_8 ) )
V_125 = V_70 ;
if ( ! V_183 -> V_184 )
F_70 ( V_2 ,
V_186 ) ;
} else if ( F_71 ( V_2 ) !=
V_187 ) {
V_183 -> V_18 = V_19 ;
F_76 ( V_8 ) ;
if ( V_23 ) {
F_72 ( V_23 ) ;
if ( F_57 ( V_8 , true ) )
V_125 = V_70 ;
else if ( V_8 -> V_121 ) {
struct V_151 * V_152 = V_23 -> V_47 ;
V_125 = V_152 -> V_159 ( V_23 , V_2 ) ;
}
}
} else {
V_183 -> V_18 = F_4 ( V_8 ) ;
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
V_125 = V_70 ;
if ( V_183 -> V_18 == V_19 )
F_76 ( V_8 ) ;
} else {
if ( V_183 -> V_18 == V_19 ) {
if ( F_76 ( V_8 ) )
V_125 = V_70 ;
} else {
if ( F_57 ( V_8 , false ) )
V_125 = V_70 ;
}
}
}
F_17 ( V_2 , V_125 ) ;
V_158:
F_47 ( V_2 -> V_4 -> V_4 ) ;
F_48 ( V_2 -> V_4 -> V_4 ) ;
return V_125 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_81 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_183 = V_8 -> V_17 ;
if ( ( V_2 -> V_13 == V_43 ) ||
( V_2 -> V_13 == V_44 ) ) {
struct V_22 * V_23 = F_23 ( V_2 ) ;
if ( ( V_27 -> V_83 < 320 ) || ( V_27 -> V_84 < 240 ) )
return V_133 ;
if ( V_23 ) {
struct V_49 * V_49 = F_14 ( V_23 ) ;
struct V_81 * V_82 = & V_49 -> V_82 ;
if ( ( V_27 -> V_83 > V_82 -> V_83 ) ||
( V_27 -> V_84 > V_82 -> V_84 ) )
return V_133 ;
if ( V_49 -> V_128 == V_129 ) {
if ( ( V_27 -> V_83 != V_82 -> V_83 ) ||
( V_27 -> V_84 != V_82 -> V_84 ) )
return V_133 ;
}
}
} else {
if ( ( V_183 -> V_18 == V_19 ) ||
( V_183 -> V_18 == V_42 ) ) {
return F_78 ( V_2 , V_27 ) ;
} else {
if ( F_68 ( V_6 ) && F_11 ( V_8 -> V_38 ) ) {
if ( V_27 -> clock > 340000 )
return V_150 ;
} else {
if ( V_27 -> clock > 165000 )
return V_150 ;
}
}
}
return V_134 ;
}
void
F_79 ( struct V_3 * V_4 ,
T_3 V_195 ,
T_3 V_196 ,
int V_13 ,
struct V_197 * V_198 ,
T_3 V_199 ,
T_4 V_179 ,
struct V_200 * V_9 ,
struct V_201 * V_202 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_15 * V_183 ;
struct V_22 * V_23 ;
struct V_49 * V_49 ;
T_3 V_203 = V_204 ;
bool V_157 = false ;
bool V_205 = false ;
bool V_206 = false ;
if ( V_13 == V_207 )
return;
if ( ( ( V_13 == V_208 ) ||
( V_13 == V_209 ) ||
( V_13 == V_210 ) ) &&
( V_211 == 0 ) )
return;
F_25 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_195 == V_195 ) {
V_8 -> V_91 |= V_196 ;
return;
}
if ( V_8 -> V_130 && V_198 -> V_212 ) {
if ( V_8 -> V_130 -> V_172 . V_173 == V_198 -> V_173 ) {
V_8 -> V_157 = true ;
V_157 = true ;
}
if ( V_8 -> V_213 && V_202 -> V_214 &&
( V_8 -> V_202 . V_215 == V_202 -> V_215 ) ) {
V_8 -> V_157 = false ;
V_157 = false ;
}
}
}
F_25 (encoder, &dev->mode_config.encoder_list, head) {
V_49 = F_14 ( V_23 ) ;
if ( V_49 -> V_91 & V_196 ) {
switch ( V_49 -> V_188 ) {
case V_189 :
case V_190 :
V_205 = true ;
break;
default:
break;
}
}
}
V_8 = F_80 ( sizeof( struct V_8 ) , V_216 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_78 ;
V_8 -> V_195 = V_195 ;
V_8 -> V_91 = V_196 ;
V_8 -> V_157 = V_157 ;
V_8 -> V_179 = V_179 ;
V_8 -> V_9 = * V_9 ;
V_8 -> V_202 = * V_202 ;
if ( V_202 -> V_214 || V_202 -> V_217 ) {
V_8 -> V_213 = F_81 ( V_6 , & V_202 -> V_218 ) ;
if ( ! V_8 -> V_213 )
F_58 ( L_18 ) ;
}
if ( V_205 ) {
V_183 = F_80 ( sizeof( struct V_15 ) , V_216 ) ;
if ( ! V_183 )
goto V_219;
V_183 -> V_199 = V_199 ;
V_8 -> V_17 = V_183 ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( V_8 -> V_130 )
V_206 = true ;
else
F_58 ( L_19 ) ;
}
switch ( V_13 ) {
case V_174 :
case V_220 :
default:
F_82 ( V_4 , & V_8 -> V_78 ,
& V_221 , V_13 ) ;
F_83 ( & V_8 -> V_78 ,
& V_222 ) ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
break;
case V_35 :
case V_40 :
case V_41 :
case V_36 :
case V_14 :
F_82 ( V_4 , & V_8 -> V_78 ,
& V_221 , V_13 ) ;
F_83 ( & V_8 -> V_78 ,
& V_222 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_106 ,
V_225 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_108 ,
0 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_110 ,
0 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_104 ,
V_226 ) ;
if ( V_227 != 0 )
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_102 ,
V_228 ) ;
V_203 = V_229 ;
V_2 -> V_223 = true ;
if ( V_13 == V_36 )
V_2 -> V_224 = true ;
else
V_2 -> V_224 = false ;
if ( V_13 == V_35 ) {
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
}
break;
case V_44 :
case V_43 :
F_82 ( V_4 , & V_8 -> V_78 ,
& V_230 , V_13 ) ;
F_83 ( & V_8 -> V_78 ,
& V_222 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_4 -> V_140 . V_141 ,
V_147 ) ;
V_203 = V_229 ;
V_2 -> V_223 = false ;
V_2 -> V_224 = false ;
break;
}
} else {
switch ( V_13 ) {
case V_174 :
F_82 ( V_4 , & V_8 -> V_78 , & V_231 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_232 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_20 ) ;
}
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_233 = V_234 ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
break;
case V_220 :
F_82 ( V_4 , & V_8 -> V_78 , & V_231 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_232 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_21 ) ;
}
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
break;
case V_35 :
case V_40 :
V_183 = F_80 ( sizeof( struct V_15 ) , V_216 ) ;
if ( ! V_183 )
goto V_219;
V_183 -> V_199 = V_199 ;
V_8 -> V_17 = V_183 ;
F_82 ( V_4 , & V_8 -> V_78 , & V_235 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_236 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_22 ) ;
}
V_203 = V_229 ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_98 ,
1 ) ;
if ( F_34 ( V_6 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_106 ,
V_225 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_108 ,
0 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_110 ,
0 ) ;
}
if ( F_85 ( V_6 ) && ( V_227 != 0 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_102 ,
V_228 ) ;
}
if ( F_34 ( V_6 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_104 ,
V_226 ) ;
}
if ( V_13 == V_35 ) {
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
}
V_2 -> V_223 = true ;
if ( V_13 == V_35 )
V_2 -> V_224 = true ;
else
V_2 -> V_224 = false ;
break;
case V_41 :
case V_36 :
V_183 = F_80 ( sizeof( struct V_15 ) , V_216 ) ;
if ( ! V_183 )
goto V_219;
V_183 -> V_199 = V_199 ;
V_8 -> V_17 = V_183 ;
F_82 ( V_4 , & V_8 -> V_78 , & V_235 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_236 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_23 ) ;
}
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_98 ,
1 ) ;
if ( F_34 ( V_6 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_106 ,
V_225 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_108 ,
0 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_110 ,
0 ) ;
}
if ( F_85 ( V_6 ) && ( V_227 != 0 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_102 ,
V_228 ) ;
}
if ( F_34 ( V_6 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_104 ,
V_226 ) ;
}
V_203 = V_229 ;
V_2 -> V_223 = true ;
if ( V_13 == V_36 )
V_2 -> V_224 = true ;
else
V_2 -> V_224 = false ;
break;
case V_14 :
V_183 = F_80 ( sizeof( struct V_15 ) , V_216 ) ;
if ( ! V_183 )
goto V_219;
V_183 -> V_199 = V_199 ;
V_8 -> V_17 = V_183 ;
F_82 ( V_4 , & V_8 -> V_78 , & V_221 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_222 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( V_8 -> V_130 )
V_206 = true ;
else
F_58 ( L_19 ) ;
}
V_203 = V_229 ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_98 ,
1 ) ;
if ( F_34 ( V_6 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_106 ,
V_225 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_108 ,
0 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_110 ,
0 ) ;
}
if ( F_85 ( V_6 ) && ( V_227 != 0 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_102 ,
V_228 ) ;
}
if ( F_34 ( V_6 ) ) {
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_104 ,
V_226 ) ;
}
V_2 -> V_223 = true ;
V_2 -> V_224 = false ;
break;
case V_43 :
V_183 = F_80 ( sizeof( struct V_15 ) , V_216 ) ;
if ( ! V_183 )
goto V_219;
V_183 -> V_199 = V_199 ;
V_8 -> V_17 = V_183 ;
F_82 ( V_4 , & V_8 -> V_78 , & V_237 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_222 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( V_8 -> V_130 )
V_206 = true ;
else
F_58 ( L_19 ) ;
}
F_84 ( & V_8 -> V_78 . V_78 ,
V_4 -> V_140 . V_141 ,
V_147 ) ;
V_203 = V_229 ;
V_2 -> V_223 = false ;
V_2 -> V_224 = false ;
break;
case V_208 :
case V_209 :
case V_210 :
F_82 ( V_4 , & V_8 -> V_78 , & V_238 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_239 ) ;
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_112 ,
F_86 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_223 = false ;
V_2 -> V_224 = false ;
break;
case V_44 :
V_183 = F_80 ( sizeof( struct V_15 ) , V_216 ) ;
if ( ! V_183 )
goto V_219;
V_183 -> V_199 = V_199 ;
V_8 -> V_17 = V_183 ;
F_82 ( V_4 , & V_8 -> V_78 , & V_240 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_241 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_24 ) ;
}
F_84 ( & V_8 -> V_78 . V_78 ,
V_4 -> V_140 . V_141 ,
V_147 ) ;
V_203 = V_229 ;
V_2 -> V_223 = false ;
V_2 -> V_224 = false ;
break;
}
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_198 -> V_212 )
V_2 -> V_233 = V_234 ;
} else
V_2 -> V_233 = V_242 ;
V_2 -> V_39 . V_203 = V_203 ;
F_87 ( V_2 ) ;
if ( V_206 )
F_88 ( V_8 ) ;
return;
V_219:
F_52 ( V_2 ) ;
F_50 ( V_2 ) ;
}
void
F_89 ( struct V_3 * V_4 ,
T_3 V_195 ,
T_3 V_196 ,
int V_13 ,
struct V_197 * V_198 ,
T_4 V_179 ,
struct V_200 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
T_3 V_203 = V_204 ;
if ( V_13 == V_207 )
return;
if ( ( ( V_13 == V_208 ) ||
( V_13 == V_209 ) ||
( V_13 == V_210 ) ) &&
( V_211 == 0 ) )
return;
F_25 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_195 == V_195 ) {
V_8 -> V_91 |= V_196 ;
return;
}
}
V_8 = F_80 ( sizeof( struct V_8 ) , V_216 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_78 ;
V_8 -> V_195 = V_195 ;
V_8 -> V_91 = V_196 ;
V_8 -> V_179 = V_179 ;
V_8 -> V_9 = * V_9 ;
switch ( V_13 ) {
case V_174 :
F_82 ( V_4 , & V_8 -> V_78 , & V_231 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_232 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_20 ) ;
}
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_233 = V_234 ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
break;
case V_220 :
F_82 ( V_4 , & V_8 -> V_78 , & V_231 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_232 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_21 ) ;
}
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_223 = true ;
V_2 -> V_224 = true ;
break;
case V_35 :
case V_40 :
F_82 ( V_4 , & V_8 -> V_78 , & V_235 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_236 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_22 ) ;
}
if ( V_13 == V_35 ) {
V_8 -> V_121 = true ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
1 ) ;
}
V_203 = V_229 ;
V_2 -> V_223 = true ;
if ( V_13 == V_35 )
V_2 -> V_224 = true ;
else
V_2 -> V_224 = false ;
break;
case V_208 :
case V_209 :
case V_210 :
F_82 ( V_4 , & V_8 -> V_78 , & V_238 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_239 ) ;
V_8 -> V_121 = true ;
if ( V_6 -> V_162 == V_243 || V_6 -> V_162 == V_244 )
V_8 -> V_121 = false ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_120 ,
V_8 -> V_121 ) ;
F_84 ( & V_8 -> V_78 . V_78 ,
V_6 -> V_97 . V_112 ,
F_90 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_223 = false ;
V_2 -> V_224 = false ;
break;
case V_44 :
F_82 ( V_4 , & V_8 -> V_78 , & V_240 , V_13 ) ;
F_83 ( & V_8 -> V_78 , & V_241 ) ;
if ( V_198 -> V_212 ) {
V_8 -> V_130 = F_81 ( V_6 , V_198 ) ;
if ( ! V_8 -> V_130 )
F_58 ( L_24 ) ;
}
F_84 ( & V_8 -> V_78 . V_78 ,
V_4 -> V_140 . V_141 ,
V_147 ) ;
V_203 = V_229 ;
V_2 -> V_223 = false ;
V_2 -> V_224 = false ;
break;
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_198 -> V_212 )
V_2 -> V_233 = V_234 ;
} else
V_2 -> V_233 = V_242 ;
V_2 -> V_39 . V_203 = V_203 ;
F_87 ( V_2 ) ;
}
