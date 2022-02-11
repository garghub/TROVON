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
int V_85 ;
if ( V_8 -> V_69 ) {
F_32 ( V_2 , V_8 -> V_69 ) ;
V_85 = F_33 ( V_2 , V_8 -> V_69 ) ;
F_34 ( V_2 , V_8 -> V_69 ) ;
return V_85 ;
}
F_32 ( V_2 , NULL ) ;
return 0 ;
}
static struct V_22 * F_35 ( struct V_1 * V_2 )
{
int V_86 = V_2 -> V_65 [ 0 ] ;
if ( V_86 )
return F_19 ( V_2 -> V_4 , V_86 ) ;
return NULL ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_35 ( V_2 ) ;
struct V_48 * V_48 ;
if ( V_23 == NULL )
return;
V_48 = F_15 ( V_23 ) ;
if ( ! F_37 ( & V_2 -> V_87 ) ) {
struct V_88 * V_89 =
F_38 ( & V_2 -> V_87 ,
struct V_88 , V_90 ) ;
V_48 -> V_91 = * V_89 ;
} else {
V_48 -> V_91 . clock = 0 ;
}
}
static enum V_60
F_39 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
enum V_60 V_92 ,
bool V_93 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_94 ;
struct V_8 * V_95 ;
int V_63 ;
F_40 (conflict, &dev->mode_config.connector_list, head) {
if ( V_94 == V_2 )
continue;
V_95 = F_2 ( V_94 ) ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_94 -> V_65 [ V_63 ] == 0 )
break;
if ( V_94 -> V_65 [ V_63 ] == V_23 -> V_83 . V_96 ) {
if ( V_94 -> V_61 != V_66 )
continue;
if ( V_95 -> V_37 )
continue;
if ( V_93 == true ) {
F_41 ( L_9 ,
V_94 -> V_55 ) ;
F_41 ( L_10 ,
V_2 -> V_55 ) ;
V_94 -> V_61 = V_97 ;
F_18 ( V_94 , V_97 ) ;
} else {
F_41 ( L_11 ,
V_2 -> V_55 ) ;
F_41 ( L_10 ,
V_94 -> V_55 ) ;
V_92 = V_97 ;
}
break;
}
}
}
return V_92 ;
}
static struct V_88 * F_42 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_88 * V_27 = NULL ;
struct V_88 * V_91 = & V_48 -> V_91 ;
if ( V_91 -> V_98 != 0 &&
V_91 -> V_99 != 0 &&
V_91 -> clock != 0 ) {
V_27 = F_43 ( V_4 , V_91 ) ;
V_27 -> type = V_100 | V_101 ;
F_44 ( V_27 ) ;
F_41 ( L_12 , V_27 -> V_55 ) ;
} else if ( V_91 -> V_98 != 0 &&
V_91 -> V_99 != 0 ) {
V_27 = F_45 ( V_4 , V_91 -> V_98 , V_91 -> V_99 , 60 , true , false , false ) ;
V_27 -> type = V_100 | V_101 ;
F_41 ( L_13 , V_27 -> V_55 ) ;
}
return V_27 ;
}
static void F_46 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_88 * V_27 = NULL ;
struct V_88 * V_91 = & V_48 -> V_91 ;
int V_63 ;
struct V_102 {
int V_103 ;
int V_104 ;
} V_105 [ 17 ] = {
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
if ( V_48 -> V_106 & ( V_107 ) ) {
if ( V_105 [ V_63 ] . V_103 > 1024 ||
V_105 [ V_63 ] . V_104 > 768 )
continue;
}
if ( V_48 -> V_106 & ( V_108 ) ) {
if ( V_105 [ V_63 ] . V_103 > V_91 -> V_98 ||
V_105 [ V_63 ] . V_104 > V_91 -> V_99 ||
( V_105 [ V_63 ] . V_103 == V_91 -> V_98 &&
V_105 [ V_63 ] . V_104 == V_91 -> V_99 ) )
continue;
}
if ( V_105 [ V_63 ] . V_103 < 320 || V_105 [ V_63 ] . V_104 < 200 )
continue;
V_27 = F_45 ( V_4 , V_105 [ V_63 ] . V_103 , V_105 [ V_63 ] . V_104 , 60 , false , false , false ) ;
F_47 ( V_2 , V_27 ) ;
}
}
static int F_48 ( struct V_1 * V_2 , struct V_109 * V_110 ,
T_1 V_111 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_23 ;
struct V_48 * V_48 ;
if ( V_110 == V_6 -> V_112 . V_113 ) {
struct V_49 * V_50 ;
bool V_114 ;
V_23 = F_22 ( V_2 , V_115 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( ! V_48 -> V_51 )
return 0 ;
V_50 = V_48 -> V_51 ;
V_114 = V_111 ? true : false ;
if ( V_50 -> V_116 != V_114 ) {
V_50 -> V_116 = V_114 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_110 == V_6 -> V_112 . V_117 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_22 ( V_2 , V_115 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_8 -> V_118 != V_111 ) {
V_8 -> V_118 = V_111 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_110 == V_6 -> V_112 . V_119 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_22 ( V_2 , V_115 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_8 -> V_120 != V_111 ) {
V_8 -> V_120 = V_111 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_110 == V_6 -> V_112 . V_121 ) {
V_23 = F_22 ( V_2 , V_115 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_122 != V_111 ) {
V_48 -> V_122 = V_111 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_110 == V_6 -> V_112 . V_123 ) {
V_23 = F_22 ( V_2 , V_115 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_124 != V_111 ) {
V_48 -> V_124 = V_111 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_110 == V_6 -> V_112 . V_125 ) {
V_23 = F_22 ( V_2 , V_115 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_126 != V_111 ) {
V_48 -> V_126 = V_111 ;
F_8 ( & V_48 -> V_83 ) ;
}
}
if ( V_110 == V_6 -> V_112 . V_127 ) {
V_23 = F_22 ( V_2 , V_128 ) ;
if ( ! V_23 ) {
V_23 = F_22 ( V_2 , V_129 ) ;
}
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
if ( ! V_48 -> V_51 )
return 0 ;
if ( F_49 ( V_6 ) || V_130 ) {
struct V_131 * V_132 ;
V_132 = V_48 -> V_51 ;
V_132 -> V_133 = V_111 ;
} else {
struct V_134 * V_132 ;
V_132 = V_48 -> V_51 ;
V_132 -> V_133 = V_111 ;
}
F_8 ( & V_48 -> V_83 ) ;
}
if ( V_110 == V_6 -> V_112 . V_135 ) {
struct V_8 * V_8 =
F_2 ( V_2 ) ;
if ( V_111 == 0 )
V_8 -> V_136 = false ;
else
V_8 -> V_136 = true ;
}
if ( V_110 == V_6 -> V_112 . V_137 ) {
struct V_138 * V_139 = NULL ;
bool V_85 = false ;
V_23 = F_22 ( V_2 , V_115 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_15 ( V_23 ) ;
V_139 = V_48 -> V_51 ;
if ( ! V_139 )
return 0 ;
if ( V_111 == 0 ) {
if ( V_6 -> V_67 )
V_85 = F_50 ( V_48 , V_139 ) ;
else
V_85 = F_51 ( V_48 , V_139 ) ;
}
if ( V_111 == 1 || V_85 == false ) {
F_52 ( V_48 , V_139 ) ;
}
F_8 ( & V_48 -> V_83 ) ;
}
if ( V_110 == V_4 -> V_140 . V_141 ) {
enum V_142 V_143 ;
if ( V_2 -> V_23 )
V_48 = F_15 ( V_2 -> V_23 ) ;
else {
struct V_44 * V_45 = V_2 -> V_46 ;
V_48 = F_15 ( V_45 -> V_47 ( V_2 ) ) ;
}
switch ( V_111 ) {
default:
case V_144 : V_143 = V_145 ; break;
case V_146 : V_143 = V_147 ; break;
case V_148 : V_143 = V_149 ; break;
case V_150 : V_143 = V_151 ; break;
}
if ( V_48 -> V_143 == V_143 )
return 0 ;
if ( ( V_143 != V_144 ) &&
( V_48 -> V_91 . clock == 0 ) )
return 0 ;
V_48 -> V_143 = V_143 ;
F_8 ( & V_48 -> V_83 ) ;
}
return 0 ;
}
static void F_53 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_88 * V_91 = & V_48 -> V_91 ;
struct V_88 * V_152 , * V_27 ;
F_54 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> type & V_100 ) {
if ( V_27 -> V_98 != V_91 -> V_98 ||
V_27 -> V_99 != V_91 -> V_99 )
memcpy ( V_91 , V_27 , sizeof( * V_27 ) ) ;
}
}
if ( ! V_91 -> clock ) {
F_54 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> V_98 == V_91 -> V_98 &&
V_27 -> V_99 == V_91 -> V_99 ) {
* V_91 = * V_27 ;
F_55 ( V_91 , V_153 ) ;
F_41 ( L_14 ) ;
break;
}
}
}
if ( ! V_91 -> clock ) {
F_41 ( L_15 ) ;
V_48 -> V_143 = V_145 ;
}
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_85 = 0 ;
struct V_88 * V_27 ;
F_24 ( V_2 ) ;
V_85 = F_31 ( V_2 ) ;
if ( V_85 > 0 ) {
V_23 = F_35 ( V_2 ) ;
if ( V_23 ) {
F_53 ( V_23 , V_2 ) ;
F_46 ( V_23 , V_2 ) ;
}
return V_85 ;
}
V_23 = F_35 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
V_27 = F_42 ( V_23 ) ;
if ( V_27 ) {
V_85 = 1 ;
F_47 ( V_2 , V_27 ) ;
V_2 -> V_38 . V_154 = V_27 -> V_154 ;
V_2 -> V_38 . V_155 = V_27 -> V_155 ;
F_46 ( V_23 , V_2 ) ;
}
return V_85 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_88 * V_27 )
{
struct V_22 * V_23 = F_35 ( V_2 ) ;
if ( ( V_27 -> V_98 < 320 ) || ( V_27 -> V_99 < 240 ) )
return V_156 ;
if ( V_23 ) {
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_88 * V_91 = & V_48 -> V_91 ;
if ( ( V_27 -> V_98 > V_91 -> V_98 ) ||
( V_27 -> V_99 > V_91 -> V_99 ) )
return V_156 ;
if ( V_48 -> V_143 == V_145 ) {
if ( ( V_27 -> V_98 != V_91 -> V_98 ) ||
( V_27 -> V_99 != V_91 -> V_99 ) )
return V_156 ;
}
}
return V_157 ;
}
static enum V_60
F_58 ( struct V_1 * V_2 , bool V_158 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = F_35 ( V_2 ) ;
enum V_60 V_85 = V_97 ;
int V_159 ;
V_159 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_159 < 0 )
return V_97 ;
if ( V_23 ) {
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_88 * V_91 = & V_48 -> V_91 ;
if ( V_91 -> V_98 >= 320 && V_91 -> V_99 >= 240 )
V_85 = V_66 ;
}
F_24 ( V_2 ) ;
if ( V_8 -> V_69 )
V_85 = V_66 ;
F_18 ( V_2 , V_85 ) ;
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_85 ;
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
struct V_109 * V_110 ,
T_1 V_160 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_48 * V_48 ;
enum V_142 V_143 ;
F_41 ( L_16 ) ;
if ( V_110 != V_4 -> V_140 . V_141 )
return 0 ;
if ( V_2 -> V_23 )
V_48 = F_15 ( V_2 -> V_23 ) ;
else {
struct V_44 * V_45 = V_2 -> V_46 ;
V_48 = F_15 ( V_45 -> V_47 ( V_2 ) ) ;
}
switch ( V_160 ) {
case V_144 : V_143 = V_145 ; break;
case V_146 : V_143 = V_147 ; break;
case V_148 : V_143 = V_149 ; break;
default:
case V_150 : V_143 = V_151 ; break;
}
if ( V_48 -> V_143 == V_143 )
return 0 ;
V_48 -> V_143 = V_143 ;
F_8 ( & V_48 -> V_83 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_85 ;
F_24 ( V_2 ) ;
V_85 = F_31 ( V_2 ) ;
F_36 ( V_2 ) ;
return V_85 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_88 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_161 )
return V_162 ;
return V_157 ;
}
static enum V_60
F_68 ( struct V_1 * V_2 , bool V_158 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
struct V_163 * V_164 ;
bool V_165 = false ;
enum V_60 V_85 = V_97 ;
int V_159 ;
V_159 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_159 < 0 )
return V_97 ;
V_23 = F_35 ( V_2 ) ;
if ( ! V_23 )
V_85 = V_97 ;
if ( V_8 -> V_79 )
V_165 = F_69 ( V_8 , false ) ;
if ( V_165 ) {
V_8 -> V_166 = false ;
F_29 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( ! V_8 -> V_69 ) {
F_70 ( L_17 ,
V_2 -> V_55 ) ;
V_85 = V_66 ;
} else {
V_8 -> V_37 =
! ! ( V_8 -> V_69 -> V_167 & V_168 ) ;
if ( V_8 -> V_37 && V_8 -> V_169 ) {
F_29 ( V_2 ) ;
V_85 = V_97 ;
} else {
V_85 = V_66 ;
}
}
} else {
if ( ! V_158 ) {
if ( V_8 -> V_166 )
V_85 = V_2 -> V_61 ;
goto V_170;
}
if ( V_8 -> V_136 && V_23 ) {
V_164 = V_23 -> V_46 ;
V_85 = V_164 -> V_171 ( V_23 , V_2 ) ;
if ( V_85 != V_97 )
V_8 -> V_166 = true ;
}
}
if ( V_85 == V_66 )
V_85 = F_39 ( V_2 , V_23 , V_85 , true ) ;
if ( ( ! V_6 -> V_67 ) &&
( V_85 == V_97 ) &&
V_6 -> V_112 . V_172 ) {
V_85 = V_66 ;
}
F_18 ( V_2 , V_85 ) ;
V_170:
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_85 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_88 * V_173 ;
struct V_22 * V_23 ;
V_23 = F_35 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
if ( V_6 -> V_174 >= V_175 )
F_46 ( V_23 , V_2 ) ;
else {
V_173 = F_45 ( V_4 , 800 , 600 , 60 , false , false , false ) ;
V_173 -> type = V_101 | V_100 ;
F_47 ( V_2 , V_173 ) ;
}
return 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_88 * V_27 )
{
if ( ( V_27 -> V_98 > 1024 ) || ( V_27 -> V_99 > 768 ) )
return V_176 ;
return V_157 ;
}
static enum V_60
F_73 ( struct V_1 * V_2 , bool V_158 )
{
struct V_22 * V_23 ;
struct V_163 * V_164 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_60 V_85 = V_97 ;
int V_159 ;
if ( ! V_8 -> V_136 )
return V_85 ;
V_159 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_159 < 0 )
return V_97 ;
V_23 = F_35 ( V_2 ) ;
if ( ! V_23 )
V_85 = V_97 ;
else {
V_164 = V_23 -> V_46 ;
V_85 = V_164 -> V_171 ( V_23 , V_2 ) ;
}
if ( V_85 == V_66 )
V_85 = F_39 ( V_2 , V_23 , V_85 , false ) ;
F_18 ( V_2 , V_85 ) ;
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_85 ;
}
static bool F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_60 V_61 ;
if ( V_6 -> V_174 >= V_177
&& V_8 -> V_9 . V_9 != V_10 ) {
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) )
V_61 = V_66 ;
else
V_61 = V_97 ;
if ( V_2 -> V_61 == V_61 )
return true ;
}
return false ;
}
static enum V_60
F_75 ( struct V_1 * V_2 , bool V_158 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = NULL ;
struct V_163 * V_164 ;
int V_63 , V_159 ;
enum V_60 V_85 = V_97 ;
bool V_165 = false , V_178 = false ;
V_159 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_159 < 0 )
return V_97 ;
if ( ! V_158 && F_74 ( V_2 ) ) {
V_85 = V_2 -> V_61 ;
goto exit;
}
if ( V_8 -> V_79 )
V_165 = F_69 ( V_8 , false ) ;
if ( V_165 ) {
V_8 -> V_166 = false ;
F_29 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( ! V_8 -> V_69 ) {
F_70 ( L_17 ,
V_2 -> V_55 ) ;
if ( ( V_6 -> V_174 == V_179 || V_6 -> V_174 == V_180 ) &&
V_8 -> V_83 . V_181 ) {
V_85 = V_97 ;
F_70 ( L_18 ,
V_2 -> V_55 ) ;
V_8 -> V_79 = NULL ;
} else {
V_85 = V_66 ;
V_178 = true ;
}
} else {
V_8 -> V_37 =
! ! ( V_8 -> V_69 -> V_167 & V_168 ) ;
if ( ( ! V_8 -> V_37 ) && V_8 -> V_169 ) {
F_29 ( V_2 ) ;
V_85 = V_97 ;
} else {
V_85 = V_66 ;
}
if ( V_8 -> V_169 && ( V_85 == V_66 ) ) {
struct V_1 * V_182 ;
struct V_8 * V_183 ;
F_40 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_182 )
continue;
V_183 = F_2 ( V_182 ) ;
if ( V_183 -> V_169 &&
( V_183 -> V_79 -> V_184 . V_185 ==
V_8 -> V_79 -> V_184 . V_185 ) ) {
if ( V_182 -> V_13 != V_186 ) {
if ( ! F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_29 ( V_2 ) ;
V_85 = V_97 ;
}
}
}
}
}
}
}
if ( ( V_85 == V_66 ) && ( V_8 -> V_37 == true ) )
goto V_170;
if ( ( V_2 -> V_13 == V_39 ) ||
( V_2 -> V_13 == V_40 ) )
goto V_170;
if ( ! V_158 ) {
if ( V_8 -> V_166 )
V_85 = V_2 -> V_61 ;
goto V_170;
}
if ( V_8 -> V_136 ) {
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_19 ( V_2 -> V_4 ,
V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( V_23 -> V_68 != V_129 &&
V_23 -> V_68 != V_128 )
continue;
V_164 = V_23 -> V_46 ;
if ( V_164 -> V_171 ) {
if ( ! V_178 ) {
if ( V_85 != V_66 ) {
V_85 = V_164 -> V_171 ( V_23 , V_2 ) ;
if ( V_85 == V_66 ) {
V_8 -> V_37 = false ;
}
if ( V_85 != V_97 )
V_8 -> V_166 = true ;
}
} else {
enum V_60 V_187 ;
V_8 -> V_37 = true ;
V_187 = V_164 -> V_171 ( V_23 , V_2 ) ;
F_41 ( L_19 , V_23 -> V_68 , V_187 ) ;
if ( V_187 == V_66 )
V_8 -> V_37 = false ;
}
break;
}
}
}
if ( ( V_85 == V_66 ) && ( V_8 -> V_37 == false ) &&
V_23 ) {
V_85 = F_39 ( V_2 , V_23 , V_85 , true ) ;
}
V_170:
if ( ( ! V_6 -> V_67 ) &&
( V_85 == V_97 ) &&
V_6 -> V_112 . V_172 ) {
V_8 -> V_37 = true ;
V_85 = V_66 ;
}
F_18 ( V_2 , V_85 ) ;
exit:
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_85 ;
}
static struct V_22 * F_76 ( struct V_1 * V_2 )
{
int V_86 = V_2 -> V_65 [ 0 ] ;
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
if ( V_23 -> V_68 == V_115 )
return V_23 ;
} else {
if ( V_23 -> V_68 == V_129 ||
V_23 -> V_68 == V_128 )
return V_23 ;
}
}
if ( V_86 )
return F_19 ( V_2 -> V_4 , V_86 ) ;
return NULL ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_2 -> V_158 == V_188 )
V_8 -> V_37 = false ;
if ( V_2 -> V_158 == V_189 )
V_8 -> V_37 = true ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_88 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_37 &&
( V_6 -> V_174 == V_190 ) &&
( V_27 -> clock > 135000 ) )
return V_162 ;
if ( V_8 -> V_37 && ( V_27 -> clock > 165000 ) ) {
if ( ( V_8 -> V_191 == V_192 ) ||
( V_8 -> V_191 == V_193 ) ||
( V_8 -> V_191 == V_194 ) )
return V_157 ;
else if ( F_79 ( V_6 ) && F_11 ( F_12 ( V_2 ) ) ) {
if ( V_27 -> clock > 340000 )
return V_162 ;
else
return V_157 ;
} else {
return V_162 ;
}
}
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_161 )
return V_162 ;
return V_157 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_195 = V_8 -> V_17 ;
struct V_22 * V_23 = F_35 ( V_2 ) ;
int V_85 ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
struct V_88 * V_27 ;
if ( V_2 -> V_13 == V_42 ) {
if ( ! V_195 -> V_196 )
F_81 ( V_2 ,
V_197 ) ;
F_24 ( V_2 ) ;
V_85 = F_31 ( V_2 ) ;
if ( ! V_195 -> V_196 )
F_81 ( V_2 ,
V_198 ) ;
} else {
if ( F_26 ( V_2 ) !=
V_78 ) {
if ( V_23 )
F_82 ( V_23 ) ;
}
F_24 ( V_2 ) ;
V_85 = F_31 ( V_2 ) ;
}
if ( V_85 > 0 ) {
if ( V_23 ) {
F_53 ( V_23 , V_2 ) ;
F_46 ( V_23 , V_2 ) ;
}
return V_85 ;
}
if ( ! V_23 )
return 0 ;
V_27 = F_42 ( V_23 ) ;
if ( V_27 ) {
V_85 = 1 ;
F_47 ( V_2 , V_27 ) ;
V_2 -> V_38 . V_154 = V_27 -> V_154 ;
V_2 -> V_38 . V_155 = V_27 -> V_155 ;
F_46 ( V_23 , V_2 ) ;
}
} else {
if ( F_26 ( V_2 ) !=
V_78 ) {
if ( V_23 )
F_82 ( V_23 ) ;
}
F_24 ( V_2 ) ;
V_85 = F_31 ( V_2 ) ;
F_36 ( V_2 ) ;
}
return V_85 ;
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
switch ( V_48 -> V_199 ) {
case V_200 :
case V_201 :
return V_48 -> V_199 ;
default:
break;
}
}
return V_78 ;
}
static bool F_83 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_48 * V_48 ;
int V_63 ;
bool V_202 = false ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_19 ( V_2 -> V_4 , V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_203 & V_204 )
V_202 = true ;
}
return V_202 ;
}
bool F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_14 ( V_6 ) &&
( V_6 -> clock . V_205 >= 53900 ) &&
F_83 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_60
F_85 ( struct V_1 * V_2 , bool V_158 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_60 V_85 = V_97 ;
struct V_15 * V_195 = V_8 -> V_17 ;
struct V_22 * V_23 = F_35 ( V_2 ) ;
int V_159 ;
V_159 = F_59 ( V_2 -> V_4 -> V_4 ) ;
if ( V_159 < 0 )
return V_97 ;
if ( ! V_158 && F_74 ( V_2 ) ) {
V_85 = V_2 -> V_61 ;
goto V_170;
}
F_29 ( V_2 ) ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
if ( V_23 ) {
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_88 * V_91 = & V_48 -> V_91 ;
if ( V_91 -> V_98 >= 320 && V_91 -> V_99 >= 240 )
V_85 = V_66 ;
}
V_195 -> V_18 = V_19 ;
if ( ! V_195 -> V_196 )
F_81 ( V_2 ,
V_197 ) ;
if ( F_86 ( V_8 ) )
V_85 = V_66 ;
if ( ! V_195 -> V_196 )
F_81 ( V_2 ,
V_198 ) ;
} else if ( F_26 ( V_2 ) !=
V_78 ) {
V_195 -> V_18 = V_19 ;
F_86 ( V_8 ) ;
if ( V_23 ) {
F_82 ( V_23 ) ;
if ( F_69 ( V_8 , true ) )
V_85 = V_66 ;
else if ( V_8 -> V_136 ) {
struct V_163 * V_164 = V_23 -> V_46 ;
V_85 = V_164 -> V_171 ( V_23 , V_2 ) ;
}
}
} else {
V_195 -> V_18 = F_4 ( V_8 ) ;
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
V_85 = V_66 ;
if ( V_195 -> V_18 == V_19 )
F_86 ( V_8 ) ;
} else {
if ( V_195 -> V_18 == V_19 ) {
if ( F_86 ( V_8 ) )
V_85 = V_66 ;
} else {
if ( F_69 ( V_8 , false ) )
V_85 = V_66 ;
}
}
}
F_18 ( V_2 , V_85 ) ;
V_170:
F_60 ( V_2 -> V_4 -> V_4 ) ;
F_61 ( V_2 -> V_4 -> V_4 ) ;
return V_85 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_88 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_195 = V_8 -> V_17 ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
struct V_22 * V_23 = F_35 ( V_2 ) ;
if ( ( V_27 -> V_98 < 320 ) || ( V_27 -> V_99 < 240 ) )
return V_156 ;
if ( V_23 ) {
struct V_48 * V_48 = F_15 ( V_23 ) ;
struct V_88 * V_91 = & V_48 -> V_91 ;
if ( ( V_27 -> V_98 > V_91 -> V_98 ) ||
( V_27 -> V_99 > V_91 -> V_99 ) )
return V_156 ;
if ( V_48 -> V_143 == V_145 ) {
if ( ( V_27 -> V_98 != V_91 -> V_98 ) ||
( V_27 -> V_99 != V_91 -> V_99 ) )
return V_156 ;
}
}
} else {
if ( ( V_195 -> V_18 == V_19 ) ||
( V_195 -> V_18 == V_41 ) ) {
return F_88 ( V_2 , V_27 ) ;
} else {
if ( F_79 ( V_6 ) && F_11 ( F_12 ( V_2 ) ) ) {
if ( V_27 -> clock > 340000 )
return V_162 ;
} else {
if ( V_27 -> clock > 165000 )
return V_162 ;
}
}
}
return V_157 ;
}
void
F_89 ( struct V_3 * V_4 ,
T_3 V_206 ,
T_3 V_207 ,
int V_13 ,
struct V_208 * V_209 ,
T_3 V_210 ,
T_4 V_191 ,
struct V_211 * V_9 ,
struct V_212 * V_76 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_15 * V_195 ;
struct V_22 * V_23 ;
struct V_48 * V_48 ;
T_3 V_213 = V_214 ;
bool V_169 = false ;
bool V_215 = false ;
bool V_80 = false ;
if ( V_13 == V_216 )
return;
if ( ( ( V_13 == V_217 ) ||
( V_13 == V_218 ) ||
( V_13 == V_219 ) ) &&
( V_220 == 0 ) )
return;
F_40 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_206 == V_206 ) {
V_8 -> V_106 |= V_207 ;
return;
}
if ( V_8 -> V_79 && V_209 -> V_221 ) {
if ( V_8 -> V_79 -> V_184 . V_185 == V_209 -> V_185 ) {
V_8 -> V_169 = true ;
V_169 = true ;
}
if ( V_8 -> V_222 && V_76 -> V_77 &&
( V_8 -> V_76 . V_223 == V_76 -> V_223 ) ) {
V_8 -> V_169 = false ;
V_169 = false ;
}
}
}
F_40 (encoder, &dev->mode_config.encoder_list, head) {
V_48 = F_15 ( V_23 ) ;
if ( V_48 -> V_106 & V_207 ) {
switch ( V_48 -> V_199 ) {
case V_200 :
case V_201 :
V_215 = true ;
break;
default:
break;
}
}
}
V_8 = F_90 ( sizeof( struct V_8 ) , V_75 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_83 ;
V_8 -> V_206 = V_206 ;
V_8 -> V_106 = V_207 ;
V_8 -> V_169 = V_169 ;
V_8 -> V_191 = V_191 ;
V_8 -> V_9 = * V_9 ;
V_8 -> V_76 = * V_76 ;
if ( V_76 -> V_77 || V_76 -> V_224 ) {
V_8 -> V_222 = F_91 ( V_6 , & V_76 -> V_225 ) ;
if ( ! V_8 -> V_222 )
F_70 ( L_20 ) ;
}
if ( V_215 ) {
V_195 = F_90 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_195 )
goto V_226;
V_195 -> V_210 = V_210 ;
V_8 -> V_17 = V_195 ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( V_8 -> V_79 )
V_80 = true ;
else
F_70 ( L_21 ) ;
}
switch ( V_13 ) {
case V_186 :
case V_227 :
default:
F_92 ( V_4 , & V_8 -> V_83 ,
& V_228 , V_13 ) ;
F_93 ( & V_8 -> V_83 ,
& V_229 ) ;
V_2 -> V_230 = true ;
V_2 -> V_231 = true ;
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_144 ) ;
break;
case V_35 :
case V_39 :
case V_40 :
case V_36 :
case V_14 :
F_92 ( V_4 , & V_8 -> V_83 ,
& V_228 , V_13 ) ;
F_93 ( & V_8 -> V_83 ,
& V_229 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_121 ,
V_232 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_123 ,
0 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_125 ,
0 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_144 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_119 ,
V_233 ) ;
if ( V_234 != 0 )
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_117 ,
V_235 ) ;
V_213 = V_236 ;
V_2 -> V_230 = true ;
if ( V_13 == V_36 )
V_2 -> V_231 = true ;
else
V_2 -> V_231 = false ;
if ( V_13 == V_35 ) {
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
}
break;
case V_43 :
case V_42 :
F_92 ( V_4 , & V_8 -> V_83 ,
& V_237 , V_13 ) ;
F_93 ( & V_8 -> V_83 ,
& V_229 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_150 ) ;
V_213 = V_236 ;
V_2 -> V_230 = false ;
V_2 -> V_231 = false ;
break;
}
} else {
switch ( V_13 ) {
case V_186 :
F_92 ( V_4 , & V_8 -> V_83 , & V_238 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_239 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_22 ) ;
}
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
if ( F_49 ( V_6 ) )
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_144 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_240 = V_241 ;
V_2 -> V_230 = true ;
V_2 -> V_231 = true ;
break;
case V_227 :
F_92 ( V_4 , & V_8 -> V_83 , & V_238 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_239 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_23 ) ;
}
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
if ( F_49 ( V_6 ) )
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_144 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_230 = true ;
V_2 -> V_231 = true ;
break;
case V_35 :
case V_39 :
V_195 = F_90 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_195 )
goto V_226;
V_195 -> V_210 = V_210 ;
V_8 -> V_17 = V_195 ;
F_92 ( V_4 , & V_8 -> V_83 , & V_242 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_243 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_24 ) ;
}
V_213 = V_236 ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_113 ,
1 ) ;
if ( F_49 ( V_6 ) ) {
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_121 ,
V_232 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_123 ,
0 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_125 ,
0 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_119 ,
V_233 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_144 ) ;
}
if ( F_95 ( V_6 ) && ( V_234 != 0 ) ) {
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_117 ,
V_235 ) ;
}
if ( V_13 == V_35 ) {
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
}
V_2 -> V_230 = true ;
if ( V_13 == V_35 )
V_2 -> V_231 = true ;
else
V_2 -> V_231 = false ;
break;
case V_40 :
case V_36 :
V_195 = F_90 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_195 )
goto V_226;
V_195 -> V_210 = V_210 ;
V_8 -> V_17 = V_195 ;
F_92 ( V_4 , & V_8 -> V_83 , & V_242 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_243 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_25 ) ;
}
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_113 ,
1 ) ;
if ( F_49 ( V_6 ) ) {
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_121 ,
V_232 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_123 ,
0 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_125 ,
0 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_119 ,
V_233 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_144 ) ;
}
if ( F_95 ( V_6 ) && ( V_234 != 0 ) ) {
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_117 ,
V_235 ) ;
}
V_213 = V_236 ;
V_2 -> V_230 = true ;
if ( V_13 == V_36 )
V_2 -> V_231 = true ;
else
V_2 -> V_231 = false ;
break;
case V_14 :
V_195 = F_90 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_195 )
goto V_226;
V_195 -> V_210 = V_210 ;
V_8 -> V_17 = V_195 ;
F_92 ( V_4 , & V_8 -> V_83 , & V_228 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_229 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( V_8 -> V_79 )
V_80 = true ;
else
F_70 ( L_21 ) ;
}
V_213 = V_236 ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_113 ,
1 ) ;
if ( F_49 ( V_6 ) ) {
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_121 ,
V_232 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_123 ,
0 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_125 ,
0 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_119 ,
V_233 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_144 ) ;
}
if ( F_95 ( V_6 ) && ( V_234 != 0 ) ) {
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_117 ,
V_235 ) ;
}
V_2 -> V_230 = true ;
V_2 -> V_231 = false ;
break;
case V_42 :
V_195 = F_90 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_195 )
goto V_226;
V_195 -> V_210 = V_210 ;
V_8 -> V_17 = V_195 ;
F_92 ( V_4 , & V_8 -> V_83 , & V_244 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_229 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( V_8 -> V_79 )
V_80 = true ;
else
F_70 ( L_21 ) ;
}
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_150 ) ;
V_213 = V_236 ;
V_2 -> V_230 = false ;
V_2 -> V_231 = false ;
break;
case V_217 :
case V_218 :
case V_219 :
F_92 ( V_4 , & V_8 -> V_83 , & V_245 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_246 ) ;
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_127 ,
F_96 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_230 = false ;
V_2 -> V_231 = false ;
break;
case V_43 :
V_195 = F_90 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_195 )
goto V_226;
V_195 -> V_210 = V_210 ;
V_8 -> V_17 = V_195 ;
F_92 ( V_4 , & V_8 -> V_83 , & V_247 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_248 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_26 ) ;
}
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_150 ) ;
V_213 = V_236 ;
V_2 -> V_230 = false ;
V_2 -> V_231 = false ;
break;
}
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_209 -> V_221 )
V_2 -> V_240 = V_241 ;
} else
V_2 -> V_240 = V_249 ;
V_2 -> V_38 . V_213 = V_213 ;
F_97 ( V_2 ) ;
if ( V_80 )
F_98 ( V_8 ) ;
return;
V_226:
F_64 ( V_2 ) ;
F_30 ( V_2 ) ;
}
void
F_99 ( struct V_3 * V_4 ,
T_3 V_206 ,
T_3 V_207 ,
int V_13 ,
struct V_208 * V_209 ,
T_4 V_191 ,
struct V_211 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
T_3 V_213 = V_214 ;
if ( V_13 == V_216 )
return;
if ( ( ( V_13 == V_217 ) ||
( V_13 == V_218 ) ||
( V_13 == V_219 ) ) &&
( V_220 == 0 ) )
return;
F_40 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_206 == V_206 ) {
V_8 -> V_106 |= V_207 ;
return;
}
}
V_8 = F_90 ( sizeof( struct V_8 ) , V_75 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_83 ;
V_8 -> V_206 = V_206 ;
V_8 -> V_106 = V_207 ;
V_8 -> V_191 = V_191 ;
V_8 -> V_9 = * V_9 ;
switch ( V_13 ) {
case V_186 :
F_92 ( V_4 , & V_8 -> V_83 , & V_238 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_239 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_22 ) ;
}
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_240 = V_241 ;
V_2 -> V_230 = true ;
V_2 -> V_231 = true ;
break;
case V_227 :
F_92 ( V_4 , & V_8 -> V_83 , & V_238 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_239 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_23 ) ;
}
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_230 = true ;
V_2 -> V_231 = true ;
break;
case V_35 :
case V_39 :
F_92 ( V_4 , & V_8 -> V_83 , & V_242 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_243 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_24 ) ;
}
if ( V_13 == V_35 ) {
V_8 -> V_136 = true ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
1 ) ;
}
V_213 = V_236 ;
V_2 -> V_230 = true ;
if ( V_13 == V_35 )
V_2 -> V_231 = true ;
else
V_2 -> V_231 = false ;
break;
case V_217 :
case V_218 :
case V_219 :
F_92 ( V_4 , & V_8 -> V_83 , & V_245 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_246 ) ;
V_8 -> V_136 = true ;
if ( V_6 -> V_174 == V_250 || V_6 -> V_174 == V_251 )
V_8 -> V_136 = false ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_135 ,
V_8 -> V_136 ) ;
F_94 ( & V_8 -> V_83 . V_83 ,
V_6 -> V_112 . V_127 ,
F_100 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_230 = false ;
V_2 -> V_231 = false ;
break;
case V_43 :
F_92 ( V_4 , & V_8 -> V_83 , & V_247 , V_13 ) ;
F_93 ( & V_8 -> V_83 , & V_248 ) ;
if ( V_209 -> V_221 ) {
V_8 -> V_79 = F_91 ( V_6 , V_209 ) ;
if ( ! V_8 -> V_79 )
F_70 ( L_26 ) ;
}
F_94 ( & V_8 -> V_83 . V_83 ,
V_4 -> V_140 . V_141 ,
V_150 ) ;
V_213 = V_236 ;
V_2 -> V_230 = false ;
V_2 -> V_231 = false ;
break;
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_209 -> V_221 )
V_2 -> V_240 = V_241 ;
} else
V_2 -> V_240 = V_249 ;
V_2 -> V_38 . V_213 = V_213 ;
F_97 ( V_2 ) ;
}
