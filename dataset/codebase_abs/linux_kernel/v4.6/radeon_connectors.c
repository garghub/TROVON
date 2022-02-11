static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
V_4 = F_3 ( V_3 ) ;
if ( V_4 == - V_5 )
return 1 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_2 -> V_11 == V_12 ) {
struct V_13 * V_14 =
V_3 -> V_15 ;
if ( V_3 -> V_16 )
return;
if ( V_14 -> V_17 ) {
F_1 ( V_2 ) ;
return;
}
}
if ( V_3 -> V_18 . V_18 == V_19 )
return;
F_5 ( V_9 , V_3 -> V_18 . V_18 ) ;
if ( V_2 -> V_20 != V_21 )
return;
if ( V_2 -> V_11 == V_12 ) {
struct V_13 * V_14 =
V_3 -> V_15 ;
if ( V_14 -> V_22 != V_23 )
return;
V_14 -> V_22 = F_6 ( V_3 ) ;
if ( V_14 -> V_22 == V_23 ) {
int V_24 = V_2 -> V_20 ;
if ( ! F_7 ( V_9 , V_3 -> V_18 . V_18 ) ) {
F_8 ( V_2 , V_25 ) ;
} else if ( F_9 ( V_3 ) ) {
if ( ! F_10 ( V_3 ) )
return;
V_2 -> V_20 = V_25 ;
F_8 ( V_2 , V_21 ) ;
}
V_2 -> V_20 = V_24 ;
}
}
}
static void F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_29 ;
if ( V_29 && V_29 -> V_30 ) {
F_12 ( V_29 , & V_29 -> V_31 ,
V_29 -> V_32 , V_29 -> V_33 , V_29 -> V_34 -> V_35 ) ;
}
}
int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
int V_36 = 8 ;
int V_37 , V_38 ;
switch ( V_2 -> V_11 ) {
case V_39 :
case V_40 :
if ( V_3 -> V_41 ) {
if ( F_14 ( F_15 ( V_2 ) ) ) {
if ( V_2 -> V_42 . V_36 )
V_36 = V_2 -> V_42 . V_36 ;
}
}
break;
case V_43 :
case V_44 :
if ( F_14 ( F_15 ( V_2 ) ) ) {
if ( V_2 -> V_42 . V_36 )
V_36 = V_2 -> V_42 . V_36 ;
}
break;
case V_12 :
V_14 = V_3 -> V_15 ;
if ( ( V_14 -> V_22 == V_23 ) ||
( V_14 -> V_22 == V_45 ) ||
F_14 ( F_15 ( V_2 ) ) ) {
if ( V_2 -> V_42 . V_36 )
V_36 = V_2 -> V_42 . V_36 ;
}
break;
case V_46 :
case V_47 :
if ( V_2 -> V_42 . V_36 )
V_36 = V_2 -> V_42 . V_36 ;
else if ( F_16 ( V_9 ) || F_17 ( V_9 ) ) {
const struct V_48 * V_49 =
V_2 -> V_50 ;
struct V_26 * V_27 = V_49 -> V_51 ( V_2 ) ;
struct V_52 * V_52 = F_18 ( V_27 ) ;
struct V_53 * V_54 = V_52 -> V_55 ;
if ( V_54 -> V_56 & V_57 )
V_36 = 6 ;
else if ( V_54 -> V_56 & V_58 )
V_36 = 8 ;
}
break;
}
if ( F_14 ( F_15 ( V_2 ) ) ) {
if ( ( V_36 > 8 ) && ! F_19 ( V_9 ) ) {
F_20 ( L_1 ,
V_2 -> V_59 , V_36 ) ;
V_36 = 8 ;
}
if ( V_36 > 12 ) {
F_20 ( L_2 ,
V_2 -> V_59 , V_36 ) ;
V_36 = 12 ;
}
if ( V_2 -> V_38 > 0 ) {
V_37 = V_3 -> V_60 ;
V_38 = V_2 -> V_38 * 1000 ;
F_20 ( L_3 ,
V_2 -> V_59 , V_37 , V_38 ) ;
if ( ( V_36 == 12 ) && ( V_37 * 3 / 2 > V_38 ) ) {
if ( ( V_2 -> V_42 . V_61 & V_62 ) &&
( V_37 * 5 / 4 <= V_38 ) )
V_36 = 10 ;
else
V_36 = 8 ;
F_20 ( L_4 ,
V_2 -> V_59 , V_36 ) ;
}
if ( ( V_36 == 10 ) && ( V_37 * 5 / 4 > V_38 ) ) {
V_36 = 8 ;
F_20 ( L_5 ,
V_2 -> V_59 , V_36 ) ;
}
}
else if ( V_36 > 8 ) {
F_20 ( L_6 ,
V_2 -> V_59 ) ;
V_36 = 8 ;
}
}
if ( ( V_63 == 0 ) && ( V_36 > 8 ) ) {
F_20 ( L_7 ,
V_2 -> V_59 ) ;
V_36 = 8 ;
}
F_20 ( L_8 ,
V_2 -> V_59 , V_2 -> V_42 . V_36 , V_36 ) ;
return V_36 ;
}
static void
F_21 ( struct V_1 * V_2 , enum V_64 V_65 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_26 * V_51 = NULL ;
struct V_26 * V_27 = NULL ;
const struct V_48 * V_49 = V_2 -> V_50 ;
bool V_66 ;
int V_67 ;
V_51 = V_49 -> V_51 ( V_2 ) ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_22 ( V_2 -> V_7 ,
V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
if ( ( V_27 == V_51 ) && ( V_65 == V_70 ) )
V_66 = true ;
else
V_66 = false ;
if ( V_9 -> V_71 )
F_23 ( V_2 , V_27 , V_66 ) ;
else
F_24 ( V_2 , V_27 , V_66 ) ;
}
}
static struct V_26 * F_25 ( struct V_1 * V_2 , int V_72 )
{
struct V_26 * V_27 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_22 ( V_2 -> V_7 , V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
if ( V_27 -> V_72 == V_72 )
return V_27 ;
}
return NULL ;
}
struct V_73 * F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_74 * V_75 = V_2 -> V_76 ;
if ( V_3 -> V_73 ) {
return V_3 -> V_73 ;
} else if ( V_75 ) {
struct V_73 * V_73 = F_26 ( V_75 -> V_77 , V_75 -> V_78 , V_79 ) ;
if ( V_73 )
V_3 -> V_73 = V_73 ;
}
return V_3 -> V_73 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_73 )
return;
if ( V_3 -> V_80 . V_81 )
F_28 ( V_3 ) ;
if ( ( F_29 ( V_2 ) !=
V_82 ) &&
V_3 -> V_83 -> V_84 ) {
V_3 -> V_73 = F_30 ( V_2 ,
& V_3 -> V_83 -> V_85 . V_86 ) ;
} else if ( ( V_2 -> V_11 == V_12 ) ||
( V_2 -> V_11 == V_46 ) ) {
struct V_13 * V_54 = V_3 -> V_15 ;
if ( ( V_54 -> V_22 == V_23 ||
V_54 -> V_22 == V_45 ) &&
V_3 -> V_83 -> V_84 )
V_3 -> V_73 = F_30 ( & V_3 -> V_87 ,
& V_3 -> V_83 -> V_85 . V_86 ) ;
else if ( V_3 -> V_83 )
V_3 -> V_73 = F_30 ( & V_3 -> V_87 ,
& V_3 -> V_83 -> V_88 ) ;
} else if ( F_31 () & V_89 &&
V_2 -> V_11 == V_47 &&
V_3 -> V_83 ) {
V_3 -> V_73 = F_32 ( & V_3 -> V_87 ,
& V_3 -> V_83 -> V_88 ) ;
} else if ( V_3 -> V_83 ) {
V_3 -> V_73 = F_30 ( & V_3 -> V_87 ,
& V_3 -> V_83 -> V_88 ) ;
}
if ( ! V_3 -> V_73 ) {
if ( ( V_9 -> V_90 & V_91 ) && ( V_92 != 0 ) )
return;
if ( V_9 -> V_71 ) {
if ( ( ( V_2 -> V_11 == V_47 ) ||
( V_2 -> V_11 == V_46 ) ) )
V_3 -> V_73 = F_33 ( V_9 ) ;
} else {
V_3 -> V_73 = F_33 ( V_9 ) ;
}
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_73 ) {
F_35 ( V_3 -> V_73 ) ;
V_3 -> V_73 = NULL ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
if ( V_3 -> V_73 ) {
F_37 ( V_2 , V_3 -> V_73 ) ;
V_4 = F_38 ( V_2 , V_3 -> V_73 ) ;
F_39 ( V_2 , V_3 -> V_73 ) ;
return V_4 ;
}
F_37 ( V_2 , NULL ) ;
return 0 ;
}
static struct V_26 * F_40 ( struct V_1 * V_2 )
{
int V_93 = V_2 -> V_69 [ 0 ] ;
if ( V_93 )
return F_22 ( V_2 -> V_7 , V_93 ) ;
return NULL ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_40 ( V_2 ) ;
struct V_52 * V_52 ;
if ( V_27 == NULL )
return;
V_52 = F_18 ( V_27 ) ;
if ( ! F_42 ( & V_2 -> V_94 ) ) {
struct V_95 * V_96 =
F_43 ( & V_2 -> V_94 ,
struct V_95 , V_97 ) ;
V_52 -> V_98 = * V_96 ;
} else {
V_52 -> V_98 . clock = 0 ;
}
}
static enum V_64
F_44 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
enum V_64 V_99 ,
bool V_100 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_101 ;
struct V_3 * V_102 ;
int V_67 ;
F_45 (conflict, &dev->mode_config.connector_list, head) {
if ( V_101 == V_2 )
continue;
V_102 = F_2 ( V_101 ) ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_101 -> V_69 [ V_67 ] == 0 )
break;
if ( V_101 -> V_69 [ V_67 ] == V_27 -> V_87 . V_103 ) {
if ( V_101 -> V_65 != V_70 )
continue;
if ( V_102 -> V_41 )
continue;
if ( V_100 == true ) {
F_46 ( L_9 ,
V_101 -> V_59 ) ;
F_46 ( L_10 ,
V_2 -> V_59 ) ;
V_101 -> V_65 = V_104 ;
F_21 ( V_101 , V_104 ) ;
} else {
F_46 ( L_11 ,
V_2 -> V_59 ) ;
F_46 ( L_10 ,
V_101 -> V_59 ) ;
V_99 = V_104 ;
}
break;
}
}
}
return V_99 ;
}
static struct V_95 * F_47 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_7 ;
struct V_52 * V_52 = F_18 ( V_27 ) ;
struct V_95 * V_31 = NULL ;
struct V_95 * V_98 = & V_52 -> V_98 ;
if ( V_98 -> V_105 != 0 &&
V_98 -> V_106 != 0 &&
V_98 -> clock != 0 ) {
V_31 = F_48 ( V_7 , V_98 ) ;
V_31 -> type = V_107 | V_108 ;
F_49 ( V_31 ) ;
F_46 ( L_12 , V_31 -> V_59 ) ;
} else if ( V_98 -> V_105 != 0 &&
V_98 -> V_106 != 0 ) {
V_31 = F_50 ( V_7 , V_98 -> V_105 , V_98 -> V_106 , 60 , true , false , false ) ;
V_31 -> type = V_107 | V_108 ;
F_46 ( L_13 , V_31 -> V_59 ) ;
}
return V_31 ;
}
static void F_51 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_27 -> V_7 ;
struct V_52 * V_52 = F_18 ( V_27 ) ;
struct V_95 * V_31 = NULL ;
struct V_95 * V_98 = & V_52 -> V_98 ;
int V_67 ;
struct V_109 {
int V_110 ;
int V_111 ;
} V_112 [ 17 ] = {
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
for ( V_67 = 0 ; V_67 < 17 ; V_67 ++ ) {
if ( V_52 -> V_113 & ( V_114 ) ) {
if ( V_112 [ V_67 ] . V_110 > 1024 ||
V_112 [ V_67 ] . V_111 > 768 )
continue;
}
if ( V_52 -> V_113 & ( V_115 ) ) {
if ( V_112 [ V_67 ] . V_110 > V_98 -> V_105 ||
V_112 [ V_67 ] . V_111 > V_98 -> V_106 ||
( V_112 [ V_67 ] . V_110 == V_98 -> V_105 &&
V_112 [ V_67 ] . V_111 == V_98 -> V_106 ) )
continue;
}
if ( V_112 [ V_67 ] . V_110 < 320 || V_112 [ V_67 ] . V_111 < 200 )
continue;
V_31 = F_50 ( V_7 , V_112 [ V_67 ] . V_110 , V_112 [ V_67 ] . V_111 , 60 , false , false , false ) ;
F_52 ( V_2 , V_31 ) ;
}
}
static int F_53 ( struct V_1 * V_2 , struct V_116 * V_117 ,
T_1 V_118 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_26 * V_27 ;
struct V_52 * V_52 ;
if ( V_117 == V_9 -> V_119 . V_120 ) {
struct V_53 * V_54 ;
bool V_121 ;
V_27 = F_25 ( V_2 , V_122 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_18 ( V_27 ) ;
if ( ! V_52 -> V_55 )
return 0 ;
V_54 = V_52 -> V_55 ;
V_121 = V_118 ? true : false ;
if ( V_54 -> V_123 != V_121 ) {
V_54 -> V_123 = V_121 ;
F_11 ( & V_52 -> V_87 ) ;
}
}
if ( V_117 == V_9 -> V_119 . V_124 ) {
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_27 = F_25 ( V_2 , V_122 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_18 ( V_27 ) ;
if ( V_3 -> V_125 != V_118 ) {
V_3 -> V_125 = V_118 ;
F_11 ( & V_52 -> V_87 ) ;
}
}
if ( V_117 == V_9 -> V_119 . V_126 ) {
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_27 = F_25 ( V_2 , V_122 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_18 ( V_27 ) ;
if ( V_3 -> V_127 != V_118 ) {
V_3 -> V_127 = V_118 ;
F_11 ( & V_52 -> V_87 ) ;
}
}
if ( V_117 == V_9 -> V_119 . V_128 ) {
V_27 = F_25 ( V_2 , V_122 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_18 ( V_27 ) ;
if ( V_52 -> V_129 != V_118 ) {
V_52 -> V_129 = V_118 ;
F_11 ( & V_52 -> V_87 ) ;
}
}
if ( V_117 == V_9 -> V_119 . V_130 ) {
V_27 = F_25 ( V_2 , V_122 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_18 ( V_27 ) ;
if ( V_52 -> V_131 != V_118 ) {
V_52 -> V_131 = V_118 ;
F_11 ( & V_52 -> V_87 ) ;
}
}
if ( V_117 == V_9 -> V_119 . V_132 ) {
V_27 = F_25 ( V_2 , V_122 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_18 ( V_27 ) ;
if ( V_52 -> V_133 != V_118 ) {
V_52 -> V_133 = V_118 ;
F_11 ( & V_52 -> V_87 ) ;
}
}
if ( V_117 == V_9 -> V_119 . V_134 ) {
V_27 = F_25 ( V_2 , V_135 ) ;
if ( ! V_27 ) {
V_27 = F_25 ( V_2 , V_136 ) ;
}
if ( ! V_27 )
return 0 ;
V_52 = F_18 ( V_27 ) ;
if ( ! V_52 -> V_55 )
return 0 ;
if ( F_54 ( V_9 ) || V_137 ) {
struct V_138 * V_139 ;
V_139 = V_52 -> V_55 ;
V_139 -> V_140 = V_118 ;
} else {
struct V_141 * V_139 ;
V_139 = V_52 -> V_55 ;
V_139 -> V_140 = V_118 ;
}
F_11 ( & V_52 -> V_87 ) ;
}
if ( V_117 == V_9 -> V_119 . V_142 ) {
struct V_3 * V_3 =
F_2 ( V_2 ) ;
if ( V_118 == 0 )
V_3 -> V_143 = false ;
else
V_3 -> V_143 = true ;
}
if ( V_117 == V_9 -> V_119 . V_144 ) {
struct V_145 * V_146 = NULL ;
bool V_4 = false ;
V_27 = F_25 ( V_2 , V_122 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_18 ( V_27 ) ;
V_146 = V_52 -> V_55 ;
if ( ! V_146 )
return 0 ;
if ( V_118 == 0 ) {
if ( V_9 -> V_71 )
V_4 = F_55 ( V_52 , V_146 ) ;
else
V_4 = F_56 ( V_52 , V_146 ) ;
}
if ( V_118 == 1 || V_4 == false ) {
F_57 ( V_52 , V_146 ) ;
}
F_11 ( & V_52 -> V_87 ) ;
}
if ( V_117 == V_7 -> V_147 . V_148 ) {
enum V_149 V_150 ;
if ( V_2 -> V_27 )
V_52 = F_18 ( V_2 -> V_27 ) ;
else {
const struct V_48 * V_49 = V_2 -> V_50 ;
V_52 = F_18 ( V_49 -> V_51 ( V_2 ) ) ;
}
switch ( V_118 ) {
default:
case V_151 : V_150 = V_152 ; break;
case V_153 : V_150 = V_154 ; break;
case V_155 : V_150 = V_156 ; break;
case V_157 : V_150 = V_158 ; break;
}
if ( V_52 -> V_150 == V_150 )
return 0 ;
if ( ( V_150 != V_151 ) &&
( V_52 -> V_98 . clock == 0 ) )
return 0 ;
V_52 -> V_150 = V_150 ;
F_11 ( & V_52 -> V_87 ) ;
}
if ( V_117 == V_9 -> V_119 . V_159 ) {
if ( V_2 -> V_27 )
V_52 = F_18 ( V_2 -> V_27 ) ;
else {
const struct V_48 * V_49 = V_2 -> V_50 ;
V_52 = F_18 ( V_49 -> V_51 ( V_2 ) ) ;
}
if ( V_52 -> V_160 == V_118 )
return 0 ;
V_52 -> V_160 = V_118 ;
if ( V_2 -> V_27 -> V_29 ) {
struct V_28 * V_29 = V_2 -> V_27 -> V_29 ;
const struct V_161 * V_162 = V_29 -> V_50 ;
struct V_163 * V_163 = F_58 ( V_29 ) ;
V_163 -> V_160 = V_52 -> V_160 ;
(* V_162 -> V_164 )( V_29 ) ;
}
}
return 0 ;
}
static void F_59 ( struct V_26 * V_27 ,
struct V_1 * V_2 )
{
struct V_52 * V_52 = F_18 ( V_27 ) ;
struct V_95 * V_98 = & V_52 -> V_98 ;
struct V_95 * V_165 , * V_31 ;
F_60 (mode, t, &connector->probed_modes, head) {
if ( V_31 -> type & V_107 ) {
if ( V_31 -> V_105 != V_98 -> V_105 ||
V_31 -> V_106 != V_98 -> V_106 )
memcpy ( V_98 , V_31 , sizeof( * V_31 ) ) ;
}
}
if ( ! V_98 -> clock ) {
F_60 (mode, t, &connector->probed_modes, head) {
if ( V_31 -> V_105 == V_98 -> V_105 &&
V_31 -> V_106 == V_98 -> V_106 ) {
* V_98 = * V_31 ;
F_61 ( V_98 , V_166 ) ;
F_46 ( L_14 ) ;
break;
}
}
}
if ( ! V_98 -> clock ) {
F_46 ( L_15 ) ;
V_52 -> V_150 = V_152 ;
}
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_4 = 0 ;
struct V_95 * V_31 ;
F_27 ( V_2 ) ;
V_4 = F_36 ( V_2 ) ;
if ( V_4 > 0 ) {
V_27 = F_40 ( V_2 ) ;
if ( V_27 ) {
F_59 ( V_27 , V_2 ) ;
F_51 ( V_27 , V_2 ) ;
}
return V_4 ;
}
V_27 = F_40 ( V_2 ) ;
if ( ! V_27 )
return 0 ;
V_31 = F_47 ( V_27 ) ;
if ( V_31 ) {
V_4 = 1 ;
F_52 ( V_2 , V_31 ) ;
V_2 -> V_42 . V_167 = V_31 -> V_167 ;
V_2 -> V_42 . V_168 = V_31 -> V_168 ;
F_51 ( V_27 , V_2 ) ;
}
return V_4 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_95 * V_31 )
{
struct V_26 * V_27 = F_40 ( V_2 ) ;
if ( ( V_31 -> V_105 < 320 ) || ( V_31 -> V_106 < 240 ) )
return V_169 ;
if ( V_27 ) {
struct V_52 * V_52 = F_18 ( V_27 ) ;
struct V_95 * V_98 = & V_52 -> V_98 ;
if ( ( V_31 -> V_105 > V_98 -> V_105 ) ||
( V_31 -> V_106 > V_98 -> V_106 ) )
return V_169 ;
if ( V_52 -> V_150 == V_152 ) {
if ( ( V_31 -> V_105 != V_98 -> V_105 ) ||
( V_31 -> V_106 != V_98 -> V_106 ) )
return V_169 ;
}
}
return V_170 ;
}
static enum V_64
F_64 ( struct V_1 * V_2 , bool V_171 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_26 * V_27 = F_40 ( V_2 ) ;
enum V_64 V_4 = V_104 ;
int V_172 ;
V_172 = F_65 ( V_2 -> V_7 -> V_7 ) ;
if ( V_172 < 0 )
return V_104 ;
if ( V_27 ) {
struct V_52 * V_52 = F_18 ( V_27 ) ;
struct V_95 * V_98 = & V_52 -> V_98 ;
if ( V_98 -> V_105 >= 320 && V_98 -> V_106 >= 240 )
V_4 = V_70 ;
if ( ( V_9 -> V_90 & V_91 ) && ( V_92 != 0 ) )
V_4 = V_104 ;
}
F_27 ( V_2 ) ;
if ( V_3 -> V_73 )
V_4 = V_70 ;
F_21 ( V_2 , V_4 ) ;
F_66 ( V_2 -> V_7 -> V_7 ) ;
F_67 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_3 -> V_15 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_35 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
T_1 V_173 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_52 * V_52 ;
enum V_149 V_150 ;
F_46 ( L_16 ) ;
if ( V_117 != V_7 -> V_147 . V_148 )
return 0 ;
if ( V_2 -> V_27 )
V_52 = F_18 ( V_2 -> V_27 ) ;
else {
const struct V_48 * V_49 = V_2 -> V_50 ;
V_52 = F_18 ( V_49 -> V_51 ( V_2 ) ) ;
}
switch ( V_173 ) {
case V_151 : V_150 = V_152 ; break;
case V_153 : V_150 = V_154 ; break;
case V_155 : V_150 = V_156 ; break;
default:
case V_157 : V_150 = V_158 ; break;
}
if ( V_52 -> V_150 == V_150 )
return 0 ;
V_52 -> V_150 = V_150 ;
F_11 ( & V_52 -> V_87 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_4 ;
F_27 ( V_2 ) ;
V_4 = F_36 ( V_2 ) ;
F_41 ( V_2 ) ;
return V_4 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_95 * V_31 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( ( V_31 -> clock / 10 ) > V_9 -> clock . V_174 )
return V_175 ;
return V_170 ;
}
static enum V_64
F_74 ( struct V_1 * V_2 , bool V_171 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
const struct V_176 * V_177 ;
bool V_178 = false ;
enum V_64 V_4 = V_104 ;
int V_172 ;
V_172 = F_65 ( V_2 -> V_7 -> V_7 ) ;
if ( V_172 < 0 )
return V_104 ;
V_27 = F_40 ( V_2 ) ;
if ( ! V_27 )
V_4 = V_104 ;
if ( V_3 -> V_83 )
V_178 = F_75 ( V_3 , false ) ;
if ( V_178 ) {
V_3 -> V_179 = false ;
F_34 ( V_2 ) ;
F_27 ( V_2 ) ;
if ( ! V_3 -> V_73 ) {
F_76 ( L_17 ,
V_2 -> V_59 ) ;
V_4 = V_70 ;
} else {
V_3 -> V_41 =
! ! ( V_3 -> V_73 -> V_180 & V_181 ) ;
if ( V_3 -> V_41 && V_3 -> V_182 ) {
F_34 ( V_2 ) ;
V_4 = V_104 ;
} else {
V_4 = V_70 ;
}
}
} else {
if ( ! V_171 ) {
if ( V_3 -> V_179 )
V_4 = V_2 -> V_65 ;
goto V_183;
}
if ( V_3 -> V_143 && V_27 ) {
V_177 = V_27 -> V_50 ;
V_4 = V_177 -> V_184 ( V_27 , V_2 ) ;
if ( V_4 != V_104 )
V_3 -> V_179 = true ;
}
}
if ( V_4 == V_70 )
V_4 = F_44 ( V_2 , V_27 , V_4 , true ) ;
if ( ( ! V_9 -> V_71 ) &&
( V_4 == V_104 ) &&
V_9 -> V_119 . V_185 ) {
V_4 = V_70 ;
}
F_21 ( V_2 , V_4 ) ;
V_183:
F_66 ( V_2 -> V_7 -> V_7 ) ;
F_67 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_95 * V_186 ;
struct V_26 * V_27 ;
V_27 = F_40 ( V_2 ) ;
if ( ! V_27 )
return 0 ;
if ( V_9 -> V_187 >= V_188 )
F_51 ( V_27 , V_2 ) ;
else {
V_186 = F_50 ( V_7 , 800 , 600 , 60 , false , false , false ) ;
V_186 -> type = V_108 | V_107 ;
F_52 ( V_2 , V_186 ) ;
}
return 1 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_95 * V_31 )
{
if ( ( V_31 -> V_105 > 1024 ) || ( V_31 -> V_106 > 768 ) )
return V_189 ;
return V_170 ;
}
static enum V_64
F_79 ( struct V_1 * V_2 , bool V_171 )
{
struct V_26 * V_27 ;
const struct V_176 * V_177 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_64 V_4 = V_104 ;
int V_172 ;
if ( ! V_3 -> V_143 )
return V_4 ;
V_172 = F_65 ( V_2 -> V_7 -> V_7 ) ;
if ( V_172 < 0 )
return V_104 ;
V_27 = F_40 ( V_2 ) ;
if ( ! V_27 )
V_4 = V_104 ;
else {
V_177 = V_27 -> V_50 ;
V_4 = V_177 -> V_184 ( V_27 , V_2 ) ;
}
if ( V_4 == V_70 )
V_4 = F_44 ( V_2 , V_27 , V_4 , false ) ;
F_21 ( V_2 , V_4 ) ;
F_66 ( V_2 -> V_7 -> V_7 ) ;
F_67 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static bool F_80 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_64 V_65 ;
if ( V_9 -> V_187 >= V_190
&& V_3 -> V_18 . V_18 != V_19 ) {
if ( F_7 ( V_9 , V_3 -> V_18 . V_18 ) )
V_65 = V_70 ;
else
V_65 = V_104 ;
if ( V_2 -> V_65 == V_65 )
return true ;
}
return false ;
}
static enum V_64
F_81 ( struct V_1 * V_2 , bool V_171 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_26 * V_27 = NULL ;
const struct V_176 * V_177 ;
int V_67 , V_172 ;
enum V_64 V_4 = V_104 ;
bool V_178 = false , V_191 = false ;
V_172 = F_65 ( V_2 -> V_7 -> V_7 ) ;
if ( V_172 < 0 )
return V_104 ;
if ( V_3 -> V_192 ) {
V_171 = true ;
V_3 -> V_192 = false ;
}
if ( ! V_171 && F_80 ( V_2 ) ) {
V_4 = V_2 -> V_65 ;
goto exit;
}
if ( V_3 -> V_83 ) {
V_178 = F_75 ( V_3 , false ) ;
if ( ! V_178 && ! V_171 &&
V_2 -> V_65 != V_70 ) {
F_46 ( L_18 ) ;
V_3 -> V_192 = true ;
F_82 ( & V_9 -> V_193 ,
F_83 ( 1000 ) ) ;
goto exit;
}
}
if ( V_178 ) {
V_3 -> V_179 = false ;
F_34 ( V_2 ) ;
F_27 ( V_2 ) ;
if ( ! V_3 -> V_73 ) {
F_76 ( L_17 ,
V_2 -> V_59 ) ;
if ( ( V_9 -> V_187 == V_194 || V_9 -> V_187 == V_195 ) &&
V_3 -> V_87 . V_196 ) {
V_4 = V_104 ;
F_76 ( L_19 ,
V_2 -> V_59 ) ;
V_3 -> V_83 = NULL ;
} else {
V_4 = V_70 ;
V_191 = true ;
}
} else {
V_3 -> V_41 =
! ! ( V_3 -> V_73 -> V_180 & V_181 ) ;
if ( ( ! V_3 -> V_41 ) && V_3 -> V_182 ) {
F_34 ( V_2 ) ;
V_4 = V_104 ;
} else {
V_4 = V_70 ;
}
if ( V_3 -> V_182 && ( V_4 == V_70 ) ) {
struct V_1 * V_197 ;
struct V_3 * V_198 ;
F_45 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_197 )
continue;
V_198 = F_2 ( V_197 ) ;
if ( V_198 -> V_182 &&
( V_198 -> V_83 -> V_199 . V_200 ==
V_3 -> V_83 -> V_199 . V_200 ) ) {
if ( V_197 -> V_11 != V_201 ) {
if ( ! F_7 ( V_9 , V_3 -> V_18 . V_18 ) ) {
F_34 ( V_2 ) ;
V_4 = V_104 ;
}
}
}
}
}
}
}
if ( ( V_4 == V_70 ) && ( V_3 -> V_41 == true ) )
goto V_183;
if ( ( V_2 -> V_11 == V_43 ) ||
( V_2 -> V_11 == V_44 ) )
goto V_183;
if ( ! V_171 ) {
if ( V_3 -> V_179 )
V_4 = V_2 -> V_65 ;
goto V_183;
}
if ( V_3 -> V_143 ) {
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_22 ( V_2 -> V_7 ,
V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
if ( V_27 -> V_72 != V_136 &&
V_27 -> V_72 != V_135 )
continue;
V_177 = V_27 -> V_50 ;
if ( V_177 -> V_184 ) {
if ( ! V_191 ) {
if ( V_4 != V_70 ) {
V_4 = V_177 -> V_184 ( V_27 , V_2 ) ;
if ( V_4 == V_70 ) {
V_3 -> V_41 = false ;
}
if ( V_4 != V_104 )
V_3 -> V_179 = true ;
}
} else {
enum V_64 V_202 ;
V_3 -> V_41 = true ;
V_202 = V_177 -> V_184 ( V_27 , V_2 ) ;
F_46 ( L_20 , V_27 -> V_72 , V_202 ) ;
if ( V_202 == V_70 )
V_3 -> V_41 = false ;
}
break;
}
}
}
if ( ( V_4 == V_70 ) && ( V_3 -> V_41 == false ) &&
V_27 ) {
V_4 = F_44 ( V_2 , V_27 , V_4 , true ) ;
}
V_183:
if ( ( ! V_9 -> V_71 ) &&
( V_4 == V_104 ) &&
V_9 -> V_119 . V_185 ) {
V_3 -> V_41 = true ;
V_4 = V_70 ;
}
F_21 ( V_2 , V_4 ) ;
if ( ( V_203 != 0 ) && V_3 -> V_41 ) {
const struct V_48 * V_49 =
V_2 -> V_50 ;
V_27 = V_49 -> V_51 ( V_2 ) ;
if ( V_27 && ( V_27 -> V_72 == V_122 ) ) {
F_27 ( V_2 ) ;
F_84 ( V_2 , V_27 , V_4 ) ;
}
}
exit:
F_66 ( V_2 -> V_7 -> V_7 ) ;
F_67 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static struct V_26 * F_85 ( struct V_1 * V_2 )
{
int V_93 = V_2 -> V_69 [ 0 ] ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_22 ( V_2 -> V_7 , V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
if ( V_3 -> V_41 == true ) {
if ( V_27 -> V_72 == V_122 )
return V_27 ;
} else {
if ( V_27 -> V_72 == V_136 ||
V_27 -> V_72 == V_135 )
return V_27 ;
}
}
if ( V_93 )
return F_22 ( V_2 -> V_7 , V_93 ) ;
return NULL ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_2 -> V_171 == V_204 )
V_3 -> V_41 = false ;
if ( V_2 -> V_171 == V_205 )
V_3 -> V_41 = true ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_95 * V_31 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_41 &&
( V_9 -> V_187 == V_206 ) &&
( V_31 -> clock > 135000 ) )
return V_175 ;
if ( V_3 -> V_41 && ( V_31 -> clock > 165000 ) ) {
if ( ( V_3 -> V_207 == V_208 ) ||
( V_3 -> V_207 == V_209 ) ||
( V_3 -> V_207 == V_210 ) )
return V_170 ;
else if ( F_88 ( V_9 ) && F_14 ( F_15 ( V_2 ) ) ) {
if ( V_31 -> clock > 340000 )
return V_175 ;
else
return V_170 ;
} else {
return V_175 ;
}
}
if ( ( V_31 -> clock / 10 ) > V_9 -> clock . V_174 )
return V_175 ;
return V_170 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_13 * V_211 = V_3 -> V_15 ;
struct V_26 * V_27 = F_40 ( V_2 ) ;
int V_4 ;
if ( ( V_2 -> V_11 == V_46 ) ||
( V_2 -> V_11 == V_47 ) ) {
struct V_95 * V_31 ;
if ( V_2 -> V_11 == V_46 ) {
if ( ! V_211 -> V_212 )
F_90 ( V_2 ,
V_213 ) ;
F_27 ( V_2 ) ;
V_4 = F_36 ( V_2 ) ;
if ( ! V_211 -> V_212 )
F_90 ( V_2 ,
V_214 ) ;
} else {
if ( F_29 ( V_2 ) !=
V_82 ) {
if ( V_27 )
F_91 ( V_27 ) ;
}
F_27 ( V_2 ) ;
V_4 = F_36 ( V_2 ) ;
}
if ( V_4 > 0 ) {
if ( V_27 ) {
F_59 ( V_27 , V_2 ) ;
F_51 ( V_27 , V_2 ) ;
}
return V_4 ;
}
if ( ! V_27 )
return 0 ;
V_31 = F_47 ( V_27 ) ;
if ( V_31 ) {
V_4 = 1 ;
F_52 ( V_2 , V_31 ) ;
V_2 -> V_42 . V_167 = V_31 -> V_167 ;
V_2 -> V_42 . V_168 = V_31 -> V_168 ;
F_51 ( V_27 , V_2 ) ;
}
} else {
if ( F_29 ( V_2 ) !=
V_82 ) {
if ( V_27 )
F_91 ( V_27 ) ;
}
F_27 ( V_2 ) ;
V_4 = F_36 ( V_2 ) ;
F_41 ( V_2 ) ;
}
return V_4 ;
}
T_2 F_29 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_52 * V_52 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_22 ( V_2 -> V_7 , V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
V_52 = F_18 ( V_27 ) ;
switch ( V_52 -> V_215 ) {
case V_216 :
case V_217 :
return V_52 -> V_215 ;
default:
break;
}
}
return V_82 ;
}
static bool F_92 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_52 * V_52 ;
int V_67 ;
bool V_218 = false ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_22 ( V_2 -> V_7 , V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
V_52 = F_18 ( V_27 ) ;
if ( V_52 -> V_219 & V_220 )
V_218 = true ;
}
return V_218 ;
}
bool F_93 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_17 ( V_9 ) &&
( V_9 -> clock . V_221 >= 53900 ) &&
F_92 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_64
F_94 ( struct V_1 * V_2 , bool V_171 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_64 V_4 = V_104 ;
struct V_13 * V_211 = V_3 -> V_15 ;
struct V_26 * V_27 = F_40 ( V_2 ) ;
int V_172 ;
if ( V_211 -> V_17 )
return V_104 ;
V_172 = F_65 ( V_2 -> V_7 -> V_7 ) ;
if ( V_172 < 0 )
return V_104 ;
if ( ! V_171 && F_80 ( V_2 ) ) {
V_4 = V_2 -> V_65 ;
goto V_183;
}
F_34 ( V_2 ) ;
if ( ( V_2 -> V_11 == V_46 ) ||
( V_2 -> V_11 == V_47 ) ) {
if ( V_27 ) {
struct V_52 * V_52 = F_18 ( V_27 ) ;
struct V_95 * V_98 = & V_52 -> V_98 ;
if ( V_98 -> V_105 >= 320 && V_98 -> V_106 >= 240 )
V_4 = V_70 ;
if ( ( V_9 -> V_90 & V_91 ) && ( V_92 != 0 ) )
V_4 = V_104 ;
}
V_211 -> V_22 = V_23 ;
if ( ! V_211 -> V_212 )
F_90 ( V_2 ,
V_213 ) ;
if ( F_10 ( V_3 ) )
V_4 = V_70 ;
if ( ! V_211 -> V_212 )
F_90 ( V_2 ,
V_214 ) ;
} else if ( F_29 ( V_2 ) !=
V_82 ) {
V_211 -> V_22 = V_23 ;
F_10 ( V_3 ) ;
if ( V_27 ) {
F_91 ( V_27 ) ;
if ( F_75 ( V_3 , true ) )
V_4 = V_70 ;
else if ( V_3 -> V_143 ) {
const struct V_176 * V_177 = V_27 -> V_50 ;
V_4 = V_177 -> V_184 ( V_27 , V_2 ) ;
}
}
} else {
V_211 -> V_22 = F_6 ( V_3 ) ;
if ( F_7 ( V_9 , V_3 -> V_18 . V_18 ) ) {
V_4 = V_70 ;
if ( V_211 -> V_22 == V_23 ) {
F_10 ( V_3 ) ;
V_172 = F_95 ( V_3 ) ;
if ( V_172 == 1 )
V_4 = V_104 ;
}
} else {
if ( V_211 -> V_22 == V_23 ) {
if ( F_10 ( V_3 ) ) {
V_172 = F_95 ( V_3 ) ;
if ( V_172 == 1 )
V_4 = V_104 ;
else
V_4 = V_70 ;
}
} else {
if ( F_75 ( V_3 , false ) )
V_4 = V_70 ;
}
}
}
F_21 ( V_2 , V_4 ) ;
if ( ( V_203 != 0 ) && V_27 ) {
F_27 ( V_2 ) ;
F_84 ( V_2 , V_27 , V_4 ) ;
}
V_183:
F_66 ( V_2 -> V_7 -> V_7 ) ;
F_67 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_95 * V_31 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_13 * V_211 = V_3 -> V_15 ;
if ( ( V_2 -> V_11 == V_46 ) ||
( V_2 -> V_11 == V_47 ) ) {
struct V_26 * V_27 = F_40 ( V_2 ) ;
if ( ( V_31 -> V_105 < 320 ) || ( V_31 -> V_106 < 240 ) )
return V_169 ;
if ( V_27 ) {
struct V_52 * V_52 = F_18 ( V_27 ) ;
struct V_95 * V_98 = & V_52 -> V_98 ;
if ( ( V_31 -> V_105 > V_98 -> V_105 ) ||
( V_31 -> V_106 > V_98 -> V_106 ) )
return V_169 ;
if ( V_52 -> V_150 == V_152 ) {
if ( ( V_31 -> V_105 != V_98 -> V_105 ) ||
( V_31 -> V_106 != V_98 -> V_106 ) )
return V_169 ;
}
}
} else {
if ( ( V_211 -> V_22 == V_23 ) ||
( V_211 -> V_22 == V_45 ) ) {
return F_97 ( V_2 , V_31 ) ;
} else {
if ( F_88 ( V_9 ) && F_14 ( F_15 ( V_2 ) ) ) {
if ( V_31 -> clock > 340000 )
return V_175 ;
} else {
if ( V_31 -> clock > 165000 )
return V_175 ;
}
}
}
return V_170 ;
}
void
F_98 ( struct V_6 * V_7 ,
T_3 V_222 ,
T_3 V_223 ,
int V_11 ,
struct V_224 * V_225 ,
T_3 V_226 ,
T_4 V_207 ,
struct V_227 * V_18 ,
struct V_228 * V_80 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
struct V_13 * V_211 ;
struct V_26 * V_27 ;
struct V_52 * V_52 ;
T_3 V_229 = V_230 ;
bool V_182 = false ;
bool V_231 = false ;
bool V_84 = false ;
if ( V_11 == V_232 )
return;
if ( ( ( V_11 == V_233 ) ||
( V_11 == V_234 ) ||
( V_11 == V_235 ) ) &&
( V_236 == 0 ) )
return;
F_45 (connector, &dev->mode_config.connector_list, head) {
V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_222 == V_222 ) {
V_3 -> V_113 |= V_223 ;
return;
}
if ( V_3 -> V_83 && V_225 -> V_237 ) {
if ( V_3 -> V_83 -> V_199 . V_200 == V_225 -> V_200 ) {
V_3 -> V_182 = true ;
V_182 = true ;
}
if ( V_3 -> V_238 && V_80 -> V_81 &&
( V_3 -> V_80 . V_239 == V_80 -> V_239 ) ) {
V_3 -> V_182 = false ;
V_182 = false ;
}
}
}
F_45 (encoder, &dev->mode_config.encoder_list, head) {
V_52 = F_18 ( V_27 ) ;
if ( V_52 -> V_113 & V_223 ) {
switch ( V_52 -> V_215 ) {
case V_216 :
case V_217 :
V_231 = true ;
break;
default:
break;
}
}
}
V_3 = F_99 ( sizeof( struct V_3 ) , V_79 ) ;
if ( ! V_3 )
return;
V_2 = & V_3 -> V_87 ;
V_3 -> V_222 = V_222 ;
V_3 -> V_113 = V_223 ;
V_3 -> V_182 = V_182 ;
V_3 -> V_207 = V_207 ;
V_3 -> V_18 = * V_18 ;
V_3 -> V_80 = * V_80 ;
if ( V_80 -> V_81 || V_80 -> V_240 ) {
V_3 -> V_238 = F_100 ( V_9 , & V_80 -> V_241 ) ;
if ( ! V_3 -> V_238 )
F_76 ( L_21 ) ;
}
if ( V_231 ) {
V_211 = F_99 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_211 )
goto V_242;
V_211 -> V_226 = V_226 ;
V_3 -> V_15 = V_211 ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( V_3 -> V_83 )
V_84 = true ;
else
F_76 ( L_22 ) ;
}
switch ( V_11 ) {
case V_201 :
case V_243 :
default:
F_101 ( V_7 , & V_3 -> V_87 ,
& V_244 , V_11 ) ;
F_102 ( & V_3 -> V_87 ,
& V_245 ) ;
V_2 -> V_246 = true ;
V_2 -> V_247 = true ;
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_151 ) ;
if ( F_17 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_159 ,
V_248 ) ;
break;
case V_39 :
case V_43 :
case V_44 :
case V_40 :
case V_12 :
F_101 ( V_7 , & V_3 -> V_87 ,
& V_244 , V_11 ) ;
F_102 ( & V_3 -> V_87 ,
& V_245 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_128 ,
V_249 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_130 ,
0 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_132 ,
0 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_151 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_126 ,
V_250 ) ;
if ( V_203 != 0 ) {
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_124 ,
V_251 ) ;
V_3 -> V_125 = V_251 ;
}
if ( F_17 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_159 ,
V_248 ) ;
V_229 = V_252 ;
V_2 -> V_246 = true ;
if ( V_11 == V_40 )
V_2 -> V_247 = true ;
else
V_2 -> V_247 = false ;
if ( V_11 == V_39 ) {
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
}
break;
case V_47 :
case V_46 :
F_101 ( V_7 , & V_3 -> V_87 ,
& V_253 , V_11 ) ;
F_102 ( & V_3 -> V_87 ,
& V_245 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_157 ) ;
V_229 = V_252 ;
V_2 -> V_246 = false ;
V_2 -> V_247 = false ;
break;
}
} else {
switch ( V_11 ) {
case V_201 :
F_101 ( V_7 , & V_3 -> V_87 , & V_254 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_255 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_23 ) ;
}
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
if ( F_54 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_151 ) ;
if ( F_17 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_159 ,
V_248 ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_256 = V_257 ;
V_2 -> V_246 = true ;
V_2 -> V_247 = true ;
break;
case V_243 :
F_101 ( V_7 , & V_3 -> V_87 , & V_254 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_255 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_24 ) ;
}
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
if ( F_54 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_151 ) ;
if ( F_17 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_159 ,
V_248 ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_246 = true ;
V_2 -> V_247 = true ;
break;
case V_39 :
case V_43 :
V_211 = F_99 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_211 )
goto V_242;
V_211 -> V_226 = V_226 ;
V_3 -> V_15 = V_211 ;
F_101 ( V_7 , & V_3 -> V_87 , & V_258 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_259 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_25 ) ;
}
V_229 = V_252 ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_120 ,
1 ) ;
if ( F_54 ( V_9 ) ) {
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_128 ,
V_249 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_130 ,
0 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_132 ,
0 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_126 ,
V_250 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_151 ) ;
}
if ( F_104 ( V_9 ) && ( V_203 != 0 ) ) {
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_124 ,
V_251 ) ;
V_3 -> V_125 = V_251 ;
}
if ( V_11 == V_39 ) {
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
}
if ( F_17 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_159 ,
V_248 ) ;
V_2 -> V_246 = true ;
if ( V_11 == V_39 )
V_2 -> V_247 = true ;
else
V_2 -> V_247 = false ;
break;
case V_44 :
case V_40 :
V_211 = F_99 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_211 )
goto V_242;
V_211 -> V_226 = V_226 ;
V_3 -> V_15 = V_211 ;
F_101 ( V_7 , & V_3 -> V_87 , & V_258 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_259 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_26 ) ;
}
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_120 ,
1 ) ;
if ( F_54 ( V_9 ) ) {
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_128 ,
V_249 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_130 ,
0 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_132 ,
0 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_126 ,
V_250 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_151 ) ;
}
if ( F_104 ( V_9 ) && ( V_203 != 0 ) ) {
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_124 ,
V_251 ) ;
V_3 -> V_125 = V_251 ;
}
if ( F_17 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_159 ,
V_248 ) ;
V_229 = V_252 ;
V_2 -> V_246 = true ;
if ( V_11 == V_40 )
V_2 -> V_247 = true ;
else
V_2 -> V_247 = false ;
break;
case V_12 :
V_211 = F_99 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_211 )
goto V_242;
V_211 -> V_226 = V_226 ;
V_3 -> V_15 = V_211 ;
F_101 ( V_7 , & V_3 -> V_87 , & V_244 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_245 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( V_3 -> V_83 )
V_84 = true ;
else
F_76 ( L_22 ) ;
}
V_229 = V_252 ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_120 ,
1 ) ;
if ( F_54 ( V_9 ) ) {
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_128 ,
V_249 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_130 ,
0 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_132 ,
0 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_126 ,
V_250 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_151 ) ;
}
if ( F_104 ( V_9 ) && ( V_203 != 0 ) ) {
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_124 ,
V_251 ) ;
V_3 -> V_125 = V_251 ;
}
if ( F_17 ( V_9 ) )
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_159 ,
V_248 ) ;
V_2 -> V_246 = true ;
V_2 -> V_247 = false ;
break;
case V_46 :
V_211 = F_99 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_211 )
goto V_242;
V_211 -> V_226 = V_226 ;
V_3 -> V_15 = V_211 ;
F_101 ( V_7 , & V_3 -> V_87 , & V_260 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_245 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( V_3 -> V_83 )
V_84 = true ;
else
F_76 ( L_22 ) ;
}
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_157 ) ;
V_229 = V_252 ;
V_2 -> V_246 = false ;
V_2 -> V_247 = false ;
break;
case V_233 :
case V_234 :
case V_235 :
F_101 ( V_7 , & V_3 -> V_87 , & V_261 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_262 ) ;
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_134 ,
F_105 ( V_9 ) ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_246 = false ;
V_2 -> V_247 = false ;
break;
case V_47 :
V_211 = F_99 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_211 )
goto V_242;
V_211 -> V_226 = V_226 ;
V_3 -> V_15 = V_211 ;
F_101 ( V_7 , & V_3 -> V_87 , & V_263 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_264 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_27 ) ;
}
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_157 ) ;
V_229 = V_252 ;
V_2 -> V_246 = false ;
V_2 -> V_247 = false ;
break;
}
}
if ( V_3 -> V_18 . V_18 == V_19 ) {
if ( V_225 -> V_237 )
V_2 -> V_256 = V_257 ;
} else
V_2 -> V_256 = V_265 ;
V_2 -> V_42 . V_229 = V_229 ;
F_106 ( V_2 ) ;
if ( V_84 )
F_107 ( V_3 ) ;
return;
V_242:
F_70 ( V_2 ) ;
F_35 ( V_2 ) ;
}
void
F_108 ( struct V_6 * V_7 ,
T_3 V_222 ,
T_3 V_223 ,
int V_11 ,
struct V_224 * V_225 ,
T_4 V_207 ,
struct V_227 * V_18 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
T_3 V_229 = V_230 ;
if ( V_11 == V_232 )
return;
if ( ( ( V_11 == V_233 ) ||
( V_11 == V_234 ) ||
( V_11 == V_235 ) ) &&
( V_236 == 0 ) )
return;
F_45 (connector, &dev->mode_config.connector_list, head) {
V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_222 == V_222 ) {
V_3 -> V_113 |= V_223 ;
return;
}
}
V_3 = F_99 ( sizeof( struct V_3 ) , V_79 ) ;
if ( ! V_3 )
return;
V_2 = & V_3 -> V_87 ;
V_3 -> V_222 = V_222 ;
V_3 -> V_113 = V_223 ;
V_3 -> V_207 = V_207 ;
V_3 -> V_18 = * V_18 ;
switch ( V_11 ) {
case V_201 :
F_101 ( V_7 , & V_3 -> V_87 , & V_254 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_255 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_23 ) ;
}
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_256 = V_257 ;
V_2 -> V_246 = true ;
V_2 -> V_247 = true ;
break;
case V_243 :
F_101 ( V_7 , & V_3 -> V_87 , & V_254 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_255 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_24 ) ;
}
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_246 = true ;
V_2 -> V_247 = true ;
break;
case V_39 :
case V_43 :
F_101 ( V_7 , & V_3 -> V_87 , & V_258 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_259 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_25 ) ;
}
if ( V_11 == V_39 ) {
V_3 -> V_143 = true ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
1 ) ;
}
V_229 = V_252 ;
V_2 -> V_246 = true ;
if ( V_11 == V_39 )
V_2 -> V_247 = true ;
else
V_2 -> V_247 = false ;
break;
case V_233 :
case V_234 :
case V_235 :
F_101 ( V_7 , & V_3 -> V_87 , & V_261 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_262 ) ;
V_3 -> V_143 = true ;
if ( V_9 -> V_187 == V_266 || V_9 -> V_187 == V_267 )
V_3 -> V_143 = false ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_142 ,
V_3 -> V_143 ) ;
F_103 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_119 . V_134 ,
F_109 ( V_9 ) ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_246 = false ;
V_2 -> V_247 = false ;
break;
case V_47 :
F_101 ( V_7 , & V_3 -> V_87 , & V_263 , V_11 ) ;
F_102 ( & V_3 -> V_87 , & V_264 ) ;
if ( V_225 -> V_237 ) {
V_3 -> V_83 = F_100 ( V_9 , V_225 ) ;
if ( ! V_3 -> V_83 )
F_76 ( L_27 ) ;
}
F_103 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_147 . V_148 ,
V_157 ) ;
V_229 = V_252 ;
V_2 -> V_246 = false ;
V_2 -> V_247 = false ;
break;
}
if ( V_3 -> V_18 . V_18 == V_19 ) {
if ( V_225 -> V_237 )
V_2 -> V_256 = V_257 ;
} else
V_2 -> V_256 = V_265 ;
V_2 -> V_42 . V_229 = V_229 ;
F_106 ( V_2 ) ;
}
void F_110 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
if ( ! F_17 ( V_9 ) )
return;
if ( V_268 == 0 )
return;
F_45 (connector, &dev->mode_config.connector_list, head) {
int V_4 ;
V_3 = F_2 ( V_2 ) ;
if ( V_2 -> V_11 != V_12 )
continue;
V_4 = F_111 ( V_3 ) ;
}
}
