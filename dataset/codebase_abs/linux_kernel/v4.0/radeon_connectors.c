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
if ( F_11 ( F_12 ( V_2 ) ) ) {
if ( V_2 -> V_38 . V_32 )
V_32 = V_2 -> V_38 . V_32 ;
}
}
break;
case V_39 :
case V_40 :
if ( F_11 ( F_12 ( V_2 ) ) ) {
if ( V_2 -> V_38 . V_32 )
V_32 = V_2 -> V_38 . V_32 ;
}
break;
case V_14 :
V_16 = V_8 -> V_17 ;
if ( ( V_16 -> V_18 == V_19 ) ||
( V_16 -> V_18 == V_41 ) ||
F_11 ( F_12 ( V_2 ) ) ) {
if ( V_2 -> V_38 . V_32 )
V_32 = V_2 -> V_38 . V_32 ;
}
break;
case V_42 :
case V_43 :
if ( V_2 -> V_38 . V_32 )
V_32 = V_2 -> V_38 . V_32 ;
else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
struct V_44 * V_45 =
V_2 -> V_46 ;
struct V_22 * V_23 = V_45 -> V_47 ( V_2 ) ;
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_49 * V_50 = V_48 -> V_51 ;
if ( V_50 -> V_52 & V_53 )
V_32 = 6 ;
else if ( V_50 -> V_52 & V_54 )
V_32 = 8 ;
}
break;
}
if ( F_11 ( F_12 ( V_2 ) ) ) {
if ( ( V_32 > 8 ) && ! F_16 ( V_6 ) ) {
F_17 ( L_1 ,
V_2 -> V_55 , V_32 ) ;
V_32 = 8 ;
}
if ( V_32 > 12 ) {
F_17 ( L_2 ,
V_2 -> V_55 , V_32 ) ;
V_32 = 12 ;
}
if ( V_2 -> V_34 > 0 ) {
V_33 = V_8 -> V_56 ;
V_34 = V_2 -> V_34 * 1000 ;
F_17 ( L_3 ,
V_2 -> V_55 , V_33 , V_34 ) ;
if ( ( V_32 == 12 ) && ( V_33 * 3 / 2 > V_34 ) ) {
if ( ( V_2 -> V_38 . V_57 & V_58 ) &&
( V_33 * 5 / 4 <= V_34 ) )
V_32 = 10 ;
else
V_32 = 8 ;
F_17 ( L_4 ,
V_2 -> V_55 , V_32 ) ;
}
if ( ( V_32 == 10 ) && ( V_33 * 5 / 4 > V_34 ) ) {
V_32 = 8 ;
F_17 ( L_5 ,
V_2 -> V_55 , V_32 ) ;
}
}
else if ( V_32 > 8 ) {
F_17 ( L_6 ,
V_2 -> V_55 ) ;
V_32 = 8 ;
}
}
if ( ( V_59 == 0 ) && ( V_32 > 8 ) ) {
F_17 ( L_7 ,
V_2 -> V_55 ) ;
V_32 = 8 ;
}
F_17 ( L_8 ,
V_2 -> V_55 , V_2 -> V_38 . V_32 , V_32 ) ;
return V_32 ;
}
static void
F_18 ( struct V_1 * V_2 , enum V_60 V_61 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_47 = NULL ;
struct V_22 * V_23 = NULL ;
struct V_44 * V_45 = V_2 -> V_46 ;
bool V_62 ;
int V_63 ;
V_47 = V_45 -> V_47 ( V_2 ) ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_19 ( V_2 -> V_4 ,
V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( ( V_23 == V_47 ) && ( V_61 == V_66 ) )
V_62 = true ;
else
V_62 = false ;
if ( V_6 -> V_67 )
F_20 ( V_2 , V_23 , V_62 ) ;
else
F_21 ( V_2 , V_23 , V_62 ) ;
}
}
static struct V_22 * F_22 ( struct V_1 * V_2 , int V_68 )
{
struct V_22 * V_23 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_19 ( V_2 -> V_4 , V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( V_23 -> V_68 == V_68 )
return V_23 ;
}
return NULL ;
}
struct V_69 * F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_70 * V_71 = V_2 -> V_72 ;
if ( V_8 -> V_69 ) {
return V_8 -> V_69 ;
} else if ( V_71 ) {
struct V_69 * V_69 = F_23 ( V_71 -> V_73 , V_71 -> V_74 , V_75 ) ;
if ( V_69 )
V_8 -> V_69 = V_69 ;
}
return V_8 -> V_69 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_69 )
return;
if ( V_8 -> V_76 . V_77 )
F_25 ( V_8 ) ;
if ( ( F_26 ( V_2 ) !=
V_78 ) &&
V_8 -> V_79 -> V_80 ) {
V_8 -> V_69 = F_27 ( V_2 ,
& V_8 -> V_79 -> V_81 . V_82 ) ;
} else if ( ( V_2 -> V_13 == V_14 ) ||
( V_2 -> V_13 == V_42 ) ) {
struct V_15 * V_50 = V_8 -> V_17 ;
if ( ( V_50 -> V_18 == V_19 ||
V_50 -> V_18 == V_41 ) &&
V_8 -> V_79 -> V_80 )
V_8 -> V_69 = F_27 ( & V_8 -> V_83 ,
& V_8 -> V_79 -> V_81 . V_82 ) ;
else if ( V_8 -> V_79 )
V_8 -> V_69 = F_27 ( & V_8 -> V_83 ,
& V_8 -> V_79 -> V_84 ) ;
} else if ( V_8 -> V_79 ) {
V_8 -> V_69 = F_27 ( & V_8 -> V_83 ,
& V_8 -> V_79 -> V_84 ) ;
}
if ( ! V_8 -> V_69 ) {
if ( ( V_6 -> V_85 & V_86 ) && ( V_87 != 0 ) )
return;
if ( V_6 -> V_67 ) {
if ( ( ( V_2 -> V_13 == V_43 ) ||
( V_2 -> V_13 == V_42 ) ) )
V_8 -> V_69 = F_28 ( V_6 ) ;
} else {
V_8 -> V_69 = F_28 ( V_6 ) ;
}
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_69 ) {
F_30 ( V_8 -> V_69 ) ;
V_8 -> V_69 = NULL ;
}
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_88 ;
if ( V_8 -> V_69 ) {
F_32 ( V_2 , V_8 -> V_69 ) ;
V_88 = F_33 ( V_2 , V_8 -> V_69 ) ;
F_34 ( V_2 , V_8 -> V_69 ) ;
return V_88 ;
}
F_32 ( V_2 , NULL ) ;
return 0 ;
}
static struct V_22 * F_35 ( struct V_1 * V_2 )
{
int V_89 = V_2 -> V_65 [ 0 ] ;
if ( V_89 )
return F_19 ( V_2 -> V_4 , V_89 ) ;
return NULL ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_35 ( V_2 ) ;
struct V_48 * V_48 ;
if ( V_23 == NULL )
return;
V_48 = F_15 ( V_23 ) ;
if ( ! F_37 ( & V_2 -> V_90 ) ) {
struct V_91 * V_92 =
F_38 ( & V_2 -> V_90 ,
struct V_91 , V_93 ) ;
V_48 -> V_94 = * V_92 ;
} else {
V_48 -> V_94 . clock = 0 ;
}
}
static enum V_60
F_39 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
enum V_60 V_95 ,
bool V_96 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_97 ;
struct V_8 * V_98 ;
int V_63 ;
F_40 (conflict, &dev->mode_config.connector_list, head) {
if ( V_97 == V_2 )
continue;
V_98 = F_2 ( V_97 ) ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_97 -> V_65 [ V_63 ] == 0 )
break;
if ( V_97 -> V_65 [ V_63 ] == V_23 -> V_83 . V_99 ) {
if ( V_97 -> V_61 != V_66 )
continue;
if ( V_98 -> V_37 )
continue;
if ( V_96 == true ) {
F_41 ( L_9 ,
V_97 -> V_55 ) ;
F_41 ( L_10 ,
V_2 -> V_55 ) ;
V_97 -> V_61 = V_100 ;
F_18 ( V_97 , V_100 ) ;
} else {
F_41 ( L_11 ,
V_2 -> V_55 ) ;
F_41 ( L_10 ,
V_97 -> V_55 ) ;
V_95 = V_100 ;
}
break;
}
}
}
return V_95 ;
}
static struct V_91 * F_42 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_91 * V_27 = NULL ;
struct V_91 * V_94 = & V_48 -> V_94 ;
if ( V_94 -> V_101 != 0 &&
V_94 -> V_102 != 0 &&
V_94 -> clock != 0 ) {
V_27 = F_43 ( V_4 , V_94 ) ;
V_27 -> type = V_103 | V_104 ;
F_44 ( V_27 ) ;
F_41 ( L_12 , V_27 -> V_55 ) ;
} else if ( V_94 -> V_101 != 0 &&
V_94 -> V_102 != 0 ) {
V_27 = F_45 ( V_4 , V_94 -> V_101 , V_94 -> V_102 , 60 , true , false , false ) ;
V_27 -> type = V_103 | V_104 ;
F_41 ( L_13 , V_27 -> V_55 ) ;
}
return V_27 ;
}
static void F_46 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_91 * V_27 = NULL ;
struct V_91 * V_94 = & V_48 -> V_94 ;
int V_63 ;
struct V_105 {
int V_106 ;
int V_107 ;
} V_108 [ 17 ] = {
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
for ( V_63 = 0 ; V_63 < 17 ; V_63 ++ ) {
if ( V_48 -> V_109 & ( V_110 ) ) {
if ( V_108 [ V_63 ] . V_106 > 1024 ||
V_108 [ V_63 ] . V_107 > 768 )
continue;
}
if ( V_48 -> V_109 & ( V_111 ) ) {
if ( V_108 [ V_63 ] . V_106 > V_94 -> V_101 ||
V_108 [ V_63 ] . V_107 > V_94 -> V_102 ||
( V_108 [ V_63 ] . V_106 == V_94 -> V_101 &&
V_108 [ V_63 ] . V_107 == V_94 -> V_102 ) )
continue;
}
if ( V_108 [ V_63 ] . V_106 < 320 || V_108 [ V_63 ] . V_107 < 200 )
continue;
V_27 = F_45 ( V_4 , V_108 [ V_63 ] . V_106 , V_108 [ V_63 ] . V_107 , 60 , false , false , false ) ;
F_47 ( V_2 , V_27 ) ;
}
}
static int F_48 ( struct V_1 * V_2 , struct V_112 * V_113 ,
T_1 V_114 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_23 ;
struct V_48 * V_48 ;
if ( V_113 == V_6 -> V_115 . V_116 ) {
struct V_49 * V_50 ;
bool V_117 ;
V_23 = F_22 ( V_2 , V_118 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( ! V_48 -> V_51 )
return 0 ;
V_50 = V_48 -> V_51 ;
V_117 = V_114 ? true : false ;
if ( V_50 -> V_119 != V_117 ) {
V_50 -> V_119 = V_117 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_113 == V_6 -> V_115 . V_120 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_22 ( V_2 , V_118 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_8 -> V_121 != V_114 ) {
V_8 -> V_121 = V_114 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_113 == V_6 -> V_115 . V_122 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_22 ( V_2 , V_118 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_8 -> V_123 != V_114 ) {
V_8 -> V_123 = V_114 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_113 == V_6 -> V_115 . V_124 ) {
V_23 = F_22 ( V_2 , V_118 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_125 != V_114 ) {
V_48 -> V_125 = V_114 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_113 == V_6 -> V_115 . V_126 ) {
V_23 = F_22 ( V_2 , V_118 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_127 != V_114 ) {
V_48 -> V_127 = V_114 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_113 == V_6 -> V_115 . V_128 ) {
V_23 = F_22 ( V_2 , V_118 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_129 != V_114 ) {
V_48 -> V_129 = V_114 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_113 == V_6 -> V_115 . V_130 ) {
V_23 = F_22 ( V_2 , V_131 ) ;
if ( ! V_23 ) {
V_23 = F_22 ( V_2 , V_132 ) ;
}
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( ! V_48 -> V_51 )
return 0 ;
if ( F_49 ( V_6 ) || V_133 ) {
struct V_134 * V_135 ;
V_135 = V_48 -> V_51 ;
V_135 -> V_136 = V_114 ;
} else {
struct V_137 * V_135 ;
V_135 = V_48 -> V_51 ;
V_135 -> V_136 = V_114 ;
}
F_8 ( & V_48 -> V_83 ) ;
}
if ( V_113 == V_6 -> V_115 . V_138 ) {
struct V_8 * V_8 =
F_2 ( V_2 ) ;
if ( V_114 == 0 )
V_8 -> V_139 = false ;
else
V_8 -> V_139 = true ;
}
if ( V_113 == V_6 -> V_115 . V_140 ) {
struct V_141 * V_142 = NULL ;
bool V_88 = false ;
V_23 = F_22 ( V_2 , V_118 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
V_142 = V_48 -> V_51 ;
if ( ! V_142 )
return 0 ;
if ( V_114 == 0 ) {
if ( V_6 -> V_67 )
V_88 = F_50 ( V_48 , V_142 ) ;
else
V_88 = F_51 ( V_48 , V_142 ) ;
}
if ( V_114 == 1 || V_88 == false ) {
F_52 ( V_48 , V_142 ) ;
}
F_8 ( & V_48 -> V_83 ) ;
}
if ( V_113 == V_4 -> V_143 . V_144 ) {
enum V_145 V_146 ;
if ( V_2 -> V_23 )
V_48 = F_15 ( V_2 -> V_23 ) ;
else {
struct V_44 * V_45 = V_2 -> V_46 ;
V_48 = F_15 ( V_45 -> V_47 ( V_2 ) ) ;
}
switch ( V_114 ) {
default:
case V_147 : V_146 = V_148 ; break;
case V_149 : V_146 = V_150 ; break;
case V_151 : V_146 = V_152 ; break;
case V_153 : V_146 = V_154 ; break;
}
if ( V_48 -> V_146 == V_146 )
return 0 ;
if ( ( V_146 != V_147 ) &&
( V_48 -> V_94 . clock == 0 ) )
return 0 ;
V_48 -> V_146 = V_146 ;
F_8 ( & V_48 -> V_83 ) ;
}
return 0 ;
}
static void F_53 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_91 * V_94 = & V_48 -> V_94 ;
struct V_91 * V_155 , * V_27 ;
F_54 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> type & V_103 ) {
if ( V_27 -> V_101 != V_94 -> V_101 ||
V_27 -> V_102 != V_94 -> V_102 )
memcpy ( V_94 , V_27 , sizeof( * V_27 ) ) ;
}
}
if ( ! V_94 -> clock ) {
F_54 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> V_101 == V_94 -> V_101 &&
V_27 -> V_102 == V_94 -> V_102 ) {
* V_94 = * V_27 ;
F_55 ( V_94 , V_156 ) ;
F_41 ( L_14 ) ;
break;
}
}
}
if ( ! V_94 -> clock ) {
F_41 ( L_15 ) ;
V_48 -> V_146 = V_148 ;
}
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_88 = 0 ;
struct V_91 * V_27 ;
F_24 ( V_2 ) ;
V_88 = F_31 ( V_2 ) ;
if ( V_88 > 0 ) {
V_23 = F_35 ( V_2 ) ;
if ( V_23 ) {
F_53 ( V_23 , V_2 ) ;
F_46 ( V_23 , V_2 ) ;
}
return V_88 ;
}
V_23 = F_35 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
V_27 = F_42 ( V_23 ) ;
if ( V_27 ) {
V_88 = 1 ;
F_47 ( V_2 , V_27 ) ;
V_2 -> V_38 . V_157 = V_27 -> V_157 ;
V_2 -> V_38 . V_158 = V_27 -> V_158 ;
F_46 ( V_23 , V_2 ) ;
}
return V_88 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_91 * V_27 )
{
struct V_22 * V_23 = F_35 ( V_2 ) ;
if ( ( V_27 -> V_101 < 320 ) || ( V_27 -> V_102 < 240 ) )
return V_159 ;
if ( V_23 ) {
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_91 * V_94 = & V_48 -> V_94 ;
if ( ( V_27 -> V_101 > V_94 -> V_101 ) ||
( V_27 -> V_102 > V_94 -> V_102 ) )
return V_159 ;
if ( V_48 -> V_146 == V_148 ) {
if ( ( V_27 -> V_101 != V_94 -> V_101 ) ||
( V_27 -> V_102 != V_94 -> V_102 ) )
return V_159 ;
}
}
return V_160 ;
}
static enum V_60
F_58 ( struct V_1 * V_2 , bool V_161 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = F_35 ( V_2 ) ;
enum V_60 V_88 = V_100 ;
int V_162 ;
V_162 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_162 < 0 )
return V_100 ;
if ( V_23 ) {
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_91 * V_94 = & V_48 -> V_94 ;
if ( V_94 -> V_101 >= 320 && V_94 -> V_102 >= 240 )
V_88 = V_66 ;
if ( ( V_6 -> V_85 & V_86 ) && ( V_87 != 0 ) )
V_88 = V_100 ;
}
F_24 ( V_2 ) ;
if ( V_8 -> V_69 )
V_88 = V_66 ;
F_18 ( V_2 , V_88 ) ;
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_88 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( V_8 -> V_17 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
T_1 V_163 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_48 * V_48 ;
enum V_145 V_146 ;
F_41 ( L_16 ) ;
if ( V_113 != V_4 -> V_143 . V_144 )
return 0 ;
if ( V_2 -> V_23 )
V_48 = F_15 ( V_2 -> V_23 ) ;
else {
struct V_44 * V_45 = V_2 -> V_46 ;
V_48 = F_15 ( V_45 -> V_47 ( V_2 ) ) ;
}
switch ( V_163 ) {
case V_147 : V_146 = V_148 ; break;
case V_149 : V_146 = V_150 ; break;
case V_151 : V_146 = V_152 ; break;
default:
case V_153 : V_146 = V_154 ; break;
}
if ( V_48 -> V_146 == V_146 )
return 0 ;
V_48 -> V_146 = V_146 ;
F_8 ( & V_48 -> V_83 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_88 ;
F_24 ( V_2 ) ;
V_88 = F_31 ( V_2 ) ;
F_36 ( V_2 ) ;
return V_88 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_91 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_164 )
return V_165 ;
return V_160 ;
}
static enum V_60
F_68 ( struct V_1 * V_2 , bool V_161 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
struct V_166 * V_167 ;
bool V_168 = false ;
enum V_60 V_88 = V_100 ;
int V_162 ;
V_162 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_162 < 0 )
return V_100 ;
V_23 = F_35 ( V_2 ) ;
if ( ! V_23 )
V_88 = V_100 ;
if ( V_8 -> V_79 )
V_168 = F_69 ( V_8 , false ) ;
if ( V_168 ) {
V_8 -> V_169 = false ;
F_29 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( ! V_8 -> V_69 ) {
F_70 ( L_17 ,
V_2 -> V_55 ) ;
V_88 = V_66 ;
} else {
V_8 -> V_37 =
! ! ( V_8 -> V_69 -> V_170 & V_171 ) ;
if ( V_8 -> V_37 && V_8 -> V_172 ) {
F_29 ( V_2 ) ;
V_88 = V_100 ;
} else {
V_88 = V_66 ;
}
}
} else {
if ( ! V_161 ) {
if ( V_8 -> V_169 )
V_88 = V_2 -> V_61 ;
goto V_173;
}
if ( V_8 -> V_139 && V_23 ) {
V_167 = V_23 -> V_46 ;
V_88 = V_167 -> V_174 ( V_23 , V_2 ) ;
if ( V_88 != V_100 )
V_8 -> V_169 = true ;
}
}
if ( V_88 == V_66 )
V_88 = F_39 ( V_2 , V_23 , V_88 , true ) ;
if ( ( ! V_6 -> V_67 ) &&
( V_88 == V_100 ) &&
V_6 -> V_115 . V_175 ) {
V_88 = V_66 ;
}
F_18 ( V_2 , V_88 ) ;
V_173:
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_88 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_91 * V_176 ;
struct V_22 * V_23 ;
V_23 = F_35 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
if ( V_6 -> V_177 >= V_178 )
F_46 ( V_23 , V_2 ) ;
else {
V_176 = F_45 ( V_4 , 800 , 600 , 60 , false , false , false ) ;
V_176 -> type = V_104 | V_103 ;
F_47 ( V_2 , V_176 ) ;
}
return 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_91 * V_27 )
{
if ( ( V_27 -> V_101 > 1024 ) || ( V_27 -> V_102 > 768 ) )
return V_179 ;
return V_160 ;
}
static enum V_60
F_73 ( struct V_1 * V_2 , bool V_161 )
{
struct V_22 * V_23 ;
struct V_166 * V_167 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_60 V_88 = V_100 ;
int V_162 ;
if ( ! V_8 -> V_139 )
return V_88 ;
V_162 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_162 < 0 )
return V_100 ;
V_23 = F_35 ( V_2 ) ;
if ( ! V_23 )
V_88 = V_100 ;
else {
V_167 = V_23 -> V_46 ;
V_88 = V_167 -> V_174 ( V_23 , V_2 ) ;
}
if ( V_88 == V_66 )
V_88 = F_39 ( V_2 , V_23 , V_88 , false ) ;
F_18 ( V_2 , V_88 ) ;
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_88 ;
}
static bool F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_60 V_61 ;
if ( V_6 -> V_177 >= V_180
&& V_8 -> V_9 . V_9 != V_10 ) {
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) )
V_61 = V_66 ;
else
V_61 = V_100 ;
if ( V_2 -> V_61 == V_61 )
return true ;
}
return false ;
}
static enum V_60
F_75 ( struct V_1 * V_2 , bool V_161 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = NULL ;
struct V_166 * V_167 ;
int V_63 , V_162 ;
enum V_60 V_88 = V_100 ;
bool V_168 = false , V_181 = false ;
V_162 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_162 < 0 )
return V_100 ;
if ( ! V_161 && F_74 ( V_2 ) ) {
V_88 = V_2 -> V_61 ;
goto exit;
}
if ( V_8 -> V_79 )
V_168 = F_69 ( V_8 , false ) ;
if ( V_168 ) {
V_8 -> V_169 = false ;
F_29 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( ! V_8 -> V_69 ) {
F_70 ( L_17 ,
V_2 -> V_55 ) ;
if ( ( V_6 -> V_177 == V_182 || V_6 -> V_177 == V_183 ) &&
V_8 -> V_83 . V_184 ) {
V_88 = V_100 ;
F_70 ( L_18 ,
V_2 -> V_55 ) ;
V_8 -> V_79 = NULL ;
} else {
V_88 = V_66 ;
V_181 = true ;
}
} else {
V_8 -> V_37 =
! ! ( V_8 -> V_69 -> V_170 & V_171 ) ;
if ( ( ! V_8 -> V_37 ) && V_8 -> V_172 ) {
F_29 ( V_2 ) ;
V_88 = V_100 ;
} else {
V_88 = V_66 ;
}
if ( V_8 -> V_172 && ( V_88 == V_66 ) ) {
struct V_1 * V_185 ;
struct V_8 * V_186 ;
F_40 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_185 )
continue;
V_186 = F_2 ( V_185 ) ;
if ( V_186 -> V_172 &&
( V_186 -> V_79 -> V_187 . V_188 ==
V_8 -> V_79 -> V_187 . V_188 ) ) {
if ( V_185 -> V_13 != V_189 ) {
if ( ! F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_29 ( V_2 ) ;
V_88 = V_100 ;
}
}
}
}
}
}
}
if ( ( V_88 == V_66 ) && ( V_8 -> V_37 == true ) )
goto V_173;
if ( ( V_2 -> V_13 == V_39 ) ||
( V_2 -> V_13 == V_40 ) )
goto V_173;
if ( ! V_161 ) {
if ( V_8 -> V_169 )
V_88 = V_2 -> V_61 ;
goto V_173;
}
if ( V_8 -> V_139 ) {
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_19 ( V_2 -> V_4 ,
V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( V_23 -> V_68 != V_132 &&
V_23 -> V_68 != V_131 )
continue;
V_167 = V_23 -> V_46 ;
if ( V_167 -> V_174 ) {
if ( ! V_181 ) {
if ( V_88 != V_66 ) {
V_88 = V_167 -> V_174 ( V_23 , V_2 ) ;
if ( V_88 == V_66 ) {
V_8 -> V_37 = false ;
}
if ( V_88 != V_100 )
V_8 -> V_169 = true ;
}
} else {
enum V_60 V_190 ;
V_8 -> V_37 = true ;
V_190 = V_167 -> V_174 ( V_23 , V_2 ) ;
F_41 ( L_19 , V_23 -> V_68 , V_190 ) ;
if ( V_190 == V_66 )
V_8 -> V_37 = false ;
}
break;
}
}
}
if ( ( V_88 == V_66 ) && ( V_8 -> V_37 == false ) &&
V_23 ) {
V_88 = F_39 ( V_2 , V_23 , V_88 , true ) ;
}
V_173:
if ( ( ! V_6 -> V_67 ) &&
( V_88 == V_100 ) &&
V_6 -> V_115 . V_175 ) {
V_8 -> V_37 = true ;
V_88 = V_66 ;
}
F_18 ( V_2 , V_88 ) ;
if ( V_191 != 0 )
F_76 ( V_2 , V_88 ) ;
exit:
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_88 ;
}
static struct V_22 * F_77 ( struct V_1 * V_2 )
{
int V_89 = V_2 -> V_65 [ 0 ] ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_19 ( V_2 -> V_4 , V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( V_8 -> V_37 == true ) {
if ( V_23 -> V_68 == V_118 )
return V_23 ;
} else {
if ( V_23 -> V_68 == V_132 ||
V_23 -> V_68 == V_131 )
return V_23 ;
}
}
if ( V_89 )
return F_19 ( V_2 -> V_4 , V_89 ) ;
return NULL ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_2 -> V_161 == V_192 )
V_8 -> V_37 = false ;
if ( V_2 -> V_161 == V_193 )
V_8 -> V_37 = true ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_91 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_37 &&
( V_6 -> V_177 == V_194 ) &&
( V_27 -> clock > 135000 ) )
return V_165 ;
if ( V_8 -> V_37 && ( V_27 -> clock > 165000 ) ) {
if ( ( V_8 -> V_195 == V_196 ) ||
( V_8 -> V_195 == V_197 ) ||
( V_8 -> V_195 == V_198 ) )
return V_160 ;
else if ( F_80 ( V_6 ) && F_11 ( F_12 ( V_2 ) ) ) {
if ( V_27 -> clock > 340000 )
return V_165 ;
else
return V_160 ;
} else {
return V_165 ;
}
}
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_164 )
return V_165 ;
return V_160 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_199 = V_8 -> V_17 ;
struct V_22 * V_23 = F_35 ( V_2 ) ;
int V_88 ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
struct V_91 * V_27 ;
if ( V_2 -> V_13 == V_42 ) {
if ( ! V_199 -> V_200 )
F_82 ( V_2 ,
V_201 ) ;
F_24 ( V_2 ) ;
V_88 = F_31 ( V_2 ) ;
if ( ! V_199 -> V_200 )
F_82 ( V_2 ,
V_202 ) ;
} else {
if ( F_26 ( V_2 ) !=
V_78 ) {
if ( V_23 )
F_83 ( V_23 ) ;
}
F_24 ( V_2 ) ;
V_88 = F_31 ( V_2 ) ;
}
if ( V_88 > 0 ) {
if ( V_23 ) {
F_53 ( V_23 , V_2 ) ;
F_46 ( V_23 , V_2 ) ;
}
return V_88 ;
}
if ( ! V_23 )
return 0 ;
V_27 = F_42 ( V_23 ) ;
if ( V_27 ) {
V_88 = 1 ;
F_47 ( V_2 , V_27 ) ;
V_2 -> V_38 . V_157 = V_27 -> V_157 ;
V_2 -> V_38 . V_158 = V_27 -> V_158 ;
F_46 ( V_23 , V_2 ) ;
}
} else {
if ( F_26 ( V_2 ) !=
V_78 ) {
if ( V_23 )
F_83 ( V_23 ) ;
}
F_24 ( V_2 ) ;
V_88 = F_31 ( V_2 ) ;
F_36 ( V_2 ) ;
}
return V_88 ;
}
T_2 F_26 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_48 * V_48 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_19 ( V_2 -> V_4 , V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
V_48 = F_15 ( V_23 ) ;
switch ( V_48 -> V_203 ) {
case V_204 :
case V_205 :
return V_48 -> V_203 ;
default:
break;
}
}
return V_78 ;
}
static bool F_84 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_48 * V_48 ;
int V_63 ;
bool V_206 = false ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_19 ( V_2 -> V_4 , V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_207 & V_208 )
V_206 = true ;
}
return V_206 ;
}
bool F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_14 ( V_6 ) &&
( V_6 -> clock . V_209 >= 53900 ) &&
F_84 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_60
F_86 ( struct V_1 * V_2 , bool V_161 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_60 V_88 = V_100 ;
struct V_15 * V_199 = V_8 -> V_17 ;
struct V_22 * V_23 = F_35 ( V_2 ) ;
int V_162 ;
V_162 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_162 < 0 )
return V_100 ;
if ( ! V_161 && F_74 ( V_2 ) ) {
V_88 = V_2 -> V_61 ;
goto V_173;
}
F_29 ( V_2 ) ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
if ( V_23 ) {
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_91 * V_94 = & V_48 -> V_94 ;
if ( V_94 -> V_101 >= 320 && V_94 -> V_102 >= 240 )
V_88 = V_66 ;
if ( ( V_6 -> V_85 & V_86 ) && ( V_87 != 0 ) )
V_88 = V_100 ;
}
V_199 -> V_18 = V_19 ;
if ( ! V_199 -> V_200 )
F_82 ( V_2 ,
V_201 ) ;
if ( F_87 ( V_8 ) )
V_88 = V_66 ;
if ( ! V_199 -> V_200 )
F_82 ( V_2 ,
V_202 ) ;
} else if ( F_26 ( V_2 ) !=
V_78 ) {
V_199 -> V_18 = V_19 ;
F_87 ( V_8 ) ;
if ( V_23 ) {
F_83 ( V_23 ) ;
if ( F_69 ( V_8 , true ) )
V_88 = V_66 ;
else if ( V_8 -> V_139 ) {
struct V_166 * V_167 = V_23 -> V_46 ;
V_88 = V_167 -> V_174 ( V_23 , V_2 ) ;
}
}
} else {
V_199 -> V_18 = F_4 ( V_8 ) ;
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
V_88 = V_66 ;
if ( V_199 -> V_18 == V_19 )
F_87 ( V_8 ) ;
} else {
if ( V_199 -> V_18 == V_19 ) {
if ( F_87 ( V_8 ) )
V_88 = V_66 ;
} else {
if ( F_69 ( V_8 , false ) )
V_88 = V_66 ;
}
}
}
F_18 ( V_2 , V_88 ) ;
if ( V_191 != 0 )
F_76 ( V_2 , V_88 ) ;
V_173:
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_88 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_91 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_199 = V_8 -> V_17 ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
struct V_22 * V_23 = F_35 ( V_2 ) ;
if ( ( V_27 -> V_101 < 320 ) || ( V_27 -> V_102 < 240 ) )
return V_159 ;
if ( V_23 ) {
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_91 * V_94 = & V_48 -> V_94 ;
if ( ( V_27 -> V_101 > V_94 -> V_101 ) ||
( V_27 -> V_102 > V_94 -> V_102 ) )
return V_159 ;
if ( V_48 -> V_146 == V_148 ) {
if ( ( V_27 -> V_101 != V_94 -> V_101 ) ||
( V_27 -> V_102 != V_94 -> V_102 ) )
return V_159 ;
}
}
} else {
if ( ( V_199 -> V_18 == V_19 ) ||
( V_199 -> V_18 == V_41 ) ) {
return F_89 ( V_2 , V_27 ) ;
} else {
if ( F_80 ( V_6 ) && F_11 ( F_12 ( V_2 ) ) ) {
if ( V_27 -> clock > 340000 )
return V_165 ;
} else {
if ( V_27 -> clock > 165000 )
return V_165 ;
}
}
}
return V_160 ;
}
void
F_90 ( struct V_3 * V_4 ,
T_3 V_210 ,
T_3 V_211 ,
int V_13 ,
struct V_212 * V_213 ,
T_3 V_214 ,
T_4 V_195 ,
struct V_215 * V_9 ,
struct V_216 * V_76 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_15 * V_199 ;
struct V_22 * V_23 ;
struct V_48 * V_48 ;
T_3 V_217 = V_218 ;
bool V_172 = false ;
bool V_219 = false ;
bool V_80 = false ;
if ( V_13 == V_220 )
return;
if ( ( ( V_13 == V_221 ) ||
( V_13 == V_222 ) ||
( V_13 == V_223 ) ) &&
( V_224 == 0 ) )
return;
F_40 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_210 == V_210 ) {
V_8 -> V_109 |= V_211 ;
return;
}
if ( V_8 -> V_79 && V_213 -> V_225 ) {
if ( V_8 -> V_79 -> V_187 . V_188 == V_213 -> V_188 ) {
V_8 -> V_172 = true ;
V_172 = true ;
}
if ( V_8 -> V_226 && V_76 -> V_77 &&
( V_8 -> V_76 . V_227 == V_76 -> V_227 ) ) {
V_8 -> V_172 = false ;
V_172 = false ;
}
}
}
F_40 (encoder, &dev->mode_config.encoder_list, head) {
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_109 & V_211 ) {
switch ( V_48 -> V_203 ) {
case V_204 :
case V_205 :
V_219 = true ;
break;
default:
break;
}
}
}
V_8 = F_91 ( sizeof( struct V_8 ) , V_75 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_83 ;
V_8 -> V_210 = V_210 ;
V_8 -> V_109 = V_211 ;
V_8 -> V_172 = V_172 ;
V_8 -> V_195 = V_195 ;
V_8 -> V_9 = * V_9 ;
V_8 -> V_76 = * V_76 ;
if ( V_76 -> V_77 || V_76 -> V_228 ) {
V_8 -> V_226 = F_92 ( V_6 , & V_76 -> V_229 ) ;
if ( ! V_8 -> V_226 )
F_70 ( L_20 ) ;
}
if ( V_219 ) {
V_199 = F_91 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_199 )
goto V_230;
V_199 -> V_214 = V_214 ;
V_8 -> V_17 = V_199 ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( V_8 -> V_79 )
V_80 = true ;
else
F_70 ( L_21 ) ;
}
switch ( V_13 ) {
case V_189 :
case V_231 :
default:
F_93 ( V_4 , & V_8 -> V_83 ,
& V_232 , V_13 ) ;
F_94 ( & V_8 -> V_83 ,
& V_233 ) ;
V_2 -> V_234 = true ;
V_2 -> V_235 = true ;
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_147 ) ;
break;
case V_35 :
case V_39 :
case V_40 :
case V_36 :
case V_14 :
F_93 ( V_4 , & V_8 -> V_83 ,
& V_232 , V_13 ) ;
F_94 ( & V_8 -> V_83 ,
& V_233 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_124 ,
V_236 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_126 ,
0 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_128 ,
0 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_147 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_122 ,
V_237 ) ;
if ( V_191 != 0 )
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_120 ,
V_238 ) ;
V_217 = V_239 ;
V_2 -> V_234 = true ;
if ( V_13 == V_36 )
V_2 -> V_235 = true ;
else
V_2 -> V_235 = false ;
if ( V_13 == V_35 ) {
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
}
break;
case V_43 :
case V_42 :
F_93 ( V_4 , & V_8 -> V_83 ,
& V_240 , V_13 ) ;
F_94 ( & V_8 -> V_83 ,
& V_233 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_153 ) ;
V_217 = V_239 ;
V_2 -> V_234 = false ;
V_2 -> V_235 = false ;
break;
}
} else {
switch ( V_13 ) {
case V_189 :
F_93 ( V_4 , & V_8 -> V_83 , & V_241 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_242 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_22 ) ;
}
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
if ( F_49 ( V_6 ) )
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_147 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_243 = V_244 ;
V_2 -> V_234 = true ;
V_2 -> V_235 = true ;
break;
case V_231 :
F_93 ( V_4 , & V_8 -> V_83 , & V_241 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_242 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_23 ) ;
}
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
if ( F_49 ( V_6 ) )
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_147 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_234 = true ;
V_2 -> V_235 = true ;
break;
case V_35 :
case V_39 :
V_199 = F_91 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_199 )
goto V_230;
V_199 -> V_214 = V_214 ;
V_8 -> V_17 = V_199 ;
F_93 ( V_4 , & V_8 -> V_83 , & V_245 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_246 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_24 ) ;
}
V_217 = V_239 ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_116 ,
1 ) ;
if ( F_49 ( V_6 ) ) {
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_124 ,
V_236 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_126 ,
0 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_128 ,
0 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_122 ,
V_237 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_147 ) ;
}
if ( F_96 ( V_6 ) && ( V_191 != 0 ) ) {
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_120 ,
V_238 ) ;
}
if ( V_13 == V_35 ) {
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
}
V_2 -> V_234 = true ;
if ( V_13 == V_35 )
V_2 -> V_235 = true ;
else
V_2 -> V_235 = false ;
break;
case V_40 :
case V_36 :
V_199 = F_91 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_199 )
goto V_230;
V_199 -> V_214 = V_214 ;
V_8 -> V_17 = V_199 ;
F_93 ( V_4 , & V_8 -> V_83 , & V_245 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_246 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_25 ) ;
}
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_116 ,
1 ) ;
if ( F_49 ( V_6 ) ) {
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_124 ,
V_236 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_126 ,
0 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_128 ,
0 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_122 ,
V_237 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_147 ) ;
}
if ( F_96 ( V_6 ) && ( V_191 != 0 ) ) {
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_120 ,
V_238 ) ;
}
V_217 = V_239 ;
V_2 -> V_234 = true ;
if ( V_13 == V_36 )
V_2 -> V_235 = true ;
else
V_2 -> V_235 = false ;
break;
case V_14 :
V_199 = F_91 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_199 )
goto V_230;
V_199 -> V_214 = V_214 ;
V_8 -> V_17 = V_199 ;
F_93 ( V_4 , & V_8 -> V_83 , & V_232 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_233 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( V_8 -> V_79 )
V_80 = true ;
else
F_70 ( L_21 ) ;
}
V_217 = V_239 ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_116 ,
1 ) ;
if ( F_49 ( V_6 ) ) {
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_124 ,
V_236 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_126 ,
0 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_128 ,
0 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_122 ,
V_237 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_147 ) ;
}
if ( F_96 ( V_6 ) && ( V_191 != 0 ) ) {
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_120 ,
V_238 ) ;
}
V_2 -> V_234 = true ;
V_2 -> V_235 = false ;
break;
case V_42 :
V_199 = F_91 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_199 )
goto V_230;
V_199 -> V_214 = V_214 ;
V_8 -> V_17 = V_199 ;
F_93 ( V_4 , & V_8 -> V_83 , & V_247 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_233 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( V_8 -> V_79 )
V_80 = true ;
else
F_70 ( L_21 ) ;
}
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_153 ) ;
V_217 = V_239 ;
V_2 -> V_234 = false ;
V_2 -> V_235 = false ;
break;
case V_221 :
case V_222 :
case V_223 :
F_93 ( V_4 , & V_8 -> V_83 , & V_248 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_249 ) ;
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_130 ,
F_97 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_234 = false ;
V_2 -> V_235 = false ;
break;
case V_43 :
V_199 = F_91 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_199 )
goto V_230;
V_199 -> V_214 = V_214 ;
V_8 -> V_17 = V_199 ;
F_93 ( V_4 , & V_8 -> V_83 , & V_250 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_251 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_26 ) ;
}
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_153 ) ;
V_217 = V_239 ;
V_2 -> V_234 = false ;
V_2 -> V_235 = false ;
break;
}
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_213 -> V_225 )
V_2 -> V_243 = V_244 ;
} else
V_2 -> V_243 = V_252 ;
V_2 -> V_38 . V_217 = V_217 ;
F_98 ( V_2 ) ;
if ( V_80 )
F_99 ( V_8 ) ;
return;
V_230:
F_64 ( V_2 ) ;
F_30 ( V_2 ) ;
}
void
F_100 ( struct V_3 * V_4 ,
T_3 V_210 ,
T_3 V_211 ,
int V_13 ,
struct V_212 * V_213 ,
T_4 V_195 ,
struct V_215 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
T_3 V_217 = V_218 ;
if ( V_13 == V_220 )
return;
if ( ( ( V_13 == V_221 ) ||
( V_13 == V_222 ) ||
( V_13 == V_223 ) ) &&
( V_224 == 0 ) )
return;
F_40 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_210 == V_210 ) {
V_8 -> V_109 |= V_211 ;
return;
}
}
V_8 = F_91 ( sizeof( struct V_8 ) , V_75 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_83 ;
V_8 -> V_210 = V_210 ;
V_8 -> V_109 = V_211 ;
V_8 -> V_195 = V_195 ;
V_8 -> V_9 = * V_9 ;
switch ( V_13 ) {
case V_189 :
F_93 ( V_4 , & V_8 -> V_83 , & V_241 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_242 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_22 ) ;
}
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_243 = V_244 ;
V_2 -> V_234 = true ;
V_2 -> V_235 = true ;
break;
case V_231 :
F_93 ( V_4 , & V_8 -> V_83 , & V_241 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_242 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_23 ) ;
}
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_234 = true ;
V_2 -> V_235 = true ;
break;
case V_35 :
case V_39 :
F_93 ( V_4 , & V_8 -> V_83 , & V_245 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_246 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_24 ) ;
}
if ( V_13 == V_35 ) {
V_8 -> V_139 = true ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
1 ) ;
}
V_217 = V_239 ;
V_2 -> V_234 = true ;
if ( V_13 == V_35 )
V_2 -> V_235 = true ;
else
V_2 -> V_235 = false ;
break;
case V_221 :
case V_222 :
case V_223 :
F_93 ( V_4 , & V_8 -> V_83 , & V_248 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_249 ) ;
V_8 -> V_139 = true ;
if ( V_6 -> V_177 == V_253 || V_6 -> V_177 == V_254 )
V_8 -> V_139 = false ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_138 ,
V_8 -> V_139 ) ;
F_95 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_115 . V_130 ,
F_101 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_234 = false ;
V_2 -> V_235 = false ;
break;
case V_43 :
F_93 ( V_4 , & V_8 -> V_83 , & V_250 , V_13 ) ;
F_94 ( & V_8 -> V_83 , & V_251 ) ;
if ( V_213 -> V_225 ) {
V_8 -> V_79 = F_92 ( V_6 , V_213 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_26 ) ;
}
F_95 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_143 . V_144 ,
V_153 ) ;
V_217 = V_239 ;
V_2 -> V_234 = false ;
V_2 -> V_235 = false ;
break;
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_213 -> V_225 )
V_2 -> V_243 = V_244 ;
} else
V_2 -> V_243 = V_252 ;
V_2 -> V_38 . V_217 = V_217 ;
F_98 ( V_2 ) ;
}
