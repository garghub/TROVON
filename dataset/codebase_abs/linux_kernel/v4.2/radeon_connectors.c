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
V_2 -> V_20 = V_25 ;
F_8 ( V_2 , V_21 ) ;
}
V_2 -> V_20 = V_24 ;
}
}
}
static void F_10 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_29 ;
if ( V_29 && V_29 -> V_30 ) {
F_11 ( V_29 , & V_29 -> V_31 ,
V_29 -> V_32 , V_29 -> V_33 , V_29 -> V_34 -> V_35 ) ;
}
}
int F_12 ( struct V_1 * V_2 )
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
if ( F_13 ( F_14 ( V_2 ) ) ) {
if ( V_2 -> V_42 . V_36 )
V_36 = V_2 -> V_42 . V_36 ;
}
}
break;
case V_43 :
case V_44 :
if ( F_13 ( F_14 ( V_2 ) ) ) {
if ( V_2 -> V_42 . V_36 )
V_36 = V_2 -> V_42 . V_36 ;
}
break;
case V_12 :
V_14 = V_3 -> V_15 ;
if ( ( V_14 -> V_22 == V_23 ) ||
( V_14 -> V_22 == V_45 ) ||
F_13 ( F_14 ( V_2 ) ) ) {
if ( V_2 -> V_42 . V_36 )
V_36 = V_2 -> V_42 . V_36 ;
}
break;
case V_46 :
case V_47 :
if ( V_2 -> V_42 . V_36 )
V_36 = V_2 -> V_42 . V_36 ;
else if ( F_15 ( V_9 ) || F_16 ( V_9 ) ) {
const struct V_48 * V_49 =
V_2 -> V_50 ;
struct V_26 * V_27 = V_49 -> V_51 ( V_2 ) ;
struct V_52 * V_52 = F_17 ( V_27 ) ;
struct V_53 * V_54 = V_52 -> V_55 ;
if ( V_54 -> V_56 & V_57 )
V_36 = 6 ;
else if ( V_54 -> V_56 & V_58 )
V_36 = 8 ;
}
break;
}
if ( F_13 ( F_14 ( V_2 ) ) ) {
if ( ( V_36 > 8 ) && ! F_18 ( V_9 ) ) {
F_19 ( L_1 ,
V_2 -> V_59 , V_36 ) ;
V_36 = 8 ;
}
if ( V_36 > 12 ) {
F_19 ( L_2 ,
V_2 -> V_59 , V_36 ) ;
V_36 = 12 ;
}
if ( V_2 -> V_38 > 0 ) {
V_37 = V_3 -> V_60 ;
V_38 = V_2 -> V_38 * 1000 ;
F_19 ( L_3 ,
V_2 -> V_59 , V_37 , V_38 ) ;
if ( ( V_36 == 12 ) && ( V_37 * 3 / 2 > V_38 ) ) {
if ( ( V_2 -> V_42 . V_61 & V_62 ) &&
( V_37 * 5 / 4 <= V_38 ) )
V_36 = 10 ;
else
V_36 = 8 ;
F_19 ( L_4 ,
V_2 -> V_59 , V_36 ) ;
}
if ( ( V_36 == 10 ) && ( V_37 * 5 / 4 > V_38 ) ) {
V_36 = 8 ;
F_19 ( L_5 ,
V_2 -> V_59 , V_36 ) ;
}
}
else if ( V_36 > 8 ) {
F_19 ( L_6 ,
V_2 -> V_59 ) ;
V_36 = 8 ;
}
}
if ( ( V_63 == 0 ) && ( V_36 > 8 ) ) {
F_19 ( L_7 ,
V_2 -> V_59 ) ;
V_36 = 8 ;
}
F_19 ( L_8 ,
V_2 -> V_59 , V_2 -> V_42 . V_36 , V_36 ) ;
return V_36 ;
}
static void
F_20 ( struct V_1 * V_2 , enum V_64 V_65 )
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
V_27 = F_21 ( V_2 -> V_7 ,
V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
if ( ( V_27 == V_51 ) && ( V_65 == V_70 ) )
V_66 = true ;
else
V_66 = false ;
if ( V_9 -> V_71 )
F_22 ( V_2 , V_27 , V_66 ) ;
else
F_23 ( V_2 , V_27 , V_66 ) ;
}
}
static struct V_26 * F_24 ( struct V_1 * V_2 , int V_72 )
{
struct V_26 * V_27 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_21 ( V_2 -> V_7 , V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
if ( V_27 -> V_72 == V_72 )
return V_27 ;
}
return NULL ;
}
struct V_73 * F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_74 * V_75 = V_2 -> V_76 ;
if ( V_3 -> V_73 ) {
return V_3 -> V_73 ;
} else if ( V_75 ) {
struct V_73 * V_73 = F_25 ( V_75 -> V_77 , V_75 -> V_78 , V_79 ) ;
if ( V_73 )
V_3 -> V_73 = V_73 ;
}
return V_3 -> V_73 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_73 )
return;
if ( V_3 -> V_80 . V_81 )
F_27 ( V_3 ) ;
if ( ( F_28 ( V_2 ) !=
V_82 ) &&
V_3 -> V_83 -> V_84 ) {
V_3 -> V_73 = F_29 ( V_2 ,
& V_3 -> V_83 -> V_85 . V_86 ) ;
} else if ( ( V_2 -> V_11 == V_12 ) ||
( V_2 -> V_11 == V_46 ) ) {
struct V_13 * V_54 = V_3 -> V_15 ;
if ( ( V_54 -> V_22 == V_23 ||
V_54 -> V_22 == V_45 ) &&
V_3 -> V_83 -> V_84 )
V_3 -> V_73 = F_29 ( & V_3 -> V_87 ,
& V_3 -> V_83 -> V_85 . V_86 ) ;
else if ( V_3 -> V_83 )
V_3 -> V_73 = F_29 ( & V_3 -> V_87 ,
& V_3 -> V_83 -> V_88 ) ;
} else if ( V_3 -> V_83 ) {
V_3 -> V_73 = F_29 ( & V_3 -> V_87 ,
& V_3 -> V_83 -> V_88 ) ;
}
if ( ! V_3 -> V_73 ) {
if ( ( V_9 -> V_89 & V_90 ) && ( V_91 != 0 ) )
return;
if ( V_9 -> V_71 ) {
if ( ( ( V_2 -> V_11 == V_47 ) ||
( V_2 -> V_11 == V_46 ) ) )
V_3 -> V_73 = F_30 ( V_9 ) ;
} else {
V_3 -> V_73 = F_30 ( V_9 ) ;
}
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_73 ) {
F_32 ( V_3 -> V_73 ) ;
V_3 -> V_73 = NULL ;
}
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
if ( V_3 -> V_73 ) {
F_34 ( V_2 , V_3 -> V_73 ) ;
V_4 = F_35 ( V_2 , V_3 -> V_73 ) ;
F_36 ( V_2 , V_3 -> V_73 ) ;
return V_4 ;
}
F_34 ( V_2 , NULL ) ;
return 0 ;
}
static struct V_26 * F_37 ( struct V_1 * V_2 )
{
int V_92 = V_2 -> V_69 [ 0 ] ;
if ( V_92 )
return F_21 ( V_2 -> V_7 , V_92 ) ;
return NULL ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_37 ( V_2 ) ;
struct V_52 * V_52 ;
if ( V_27 == NULL )
return;
V_52 = F_17 ( V_27 ) ;
if ( ! F_39 ( & V_2 -> V_93 ) ) {
struct V_94 * V_95 =
F_40 ( & V_2 -> V_93 ,
struct V_94 , V_96 ) ;
V_52 -> V_97 = * V_95 ;
} else {
V_52 -> V_97 . clock = 0 ;
}
}
static enum V_64
F_41 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
enum V_64 V_98 ,
bool V_99 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_100 ;
struct V_3 * V_101 ;
int V_67 ;
F_42 (conflict, &dev->mode_config.connector_list, head) {
if ( V_100 == V_2 )
continue;
V_101 = F_2 ( V_100 ) ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_100 -> V_69 [ V_67 ] == 0 )
break;
if ( V_100 -> V_69 [ V_67 ] == V_27 -> V_87 . V_102 ) {
if ( V_100 -> V_65 != V_70 )
continue;
if ( V_101 -> V_41 )
continue;
if ( V_99 == true ) {
F_43 ( L_9 ,
V_100 -> V_59 ) ;
F_43 ( L_10 ,
V_2 -> V_59 ) ;
V_100 -> V_65 = V_103 ;
F_20 ( V_100 , V_103 ) ;
} else {
F_43 ( L_11 ,
V_2 -> V_59 ) ;
F_43 ( L_10 ,
V_100 -> V_59 ) ;
V_98 = V_103 ;
}
break;
}
}
}
return V_98 ;
}
static struct V_94 * F_44 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_7 ;
struct V_52 * V_52 = F_17 ( V_27 ) ;
struct V_94 * V_31 = NULL ;
struct V_94 * V_97 = & V_52 -> V_97 ;
if ( V_97 -> V_104 != 0 &&
V_97 -> V_105 != 0 &&
V_97 -> clock != 0 ) {
V_31 = F_45 ( V_7 , V_97 ) ;
V_31 -> type = V_106 | V_107 ;
F_46 ( V_31 ) ;
F_43 ( L_12 , V_31 -> V_59 ) ;
} else if ( V_97 -> V_104 != 0 &&
V_97 -> V_105 != 0 ) {
V_31 = F_47 ( V_7 , V_97 -> V_104 , V_97 -> V_105 , 60 , true , false , false ) ;
V_31 -> type = V_106 | V_107 ;
F_43 ( L_13 , V_31 -> V_59 ) ;
}
return V_31 ;
}
static void F_48 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_27 -> V_7 ;
struct V_52 * V_52 = F_17 ( V_27 ) ;
struct V_94 * V_31 = NULL ;
struct V_94 * V_97 = & V_52 -> V_97 ;
int V_67 ;
struct V_108 {
int V_109 ;
int V_110 ;
} V_111 [ 17 ] = {
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
if ( V_52 -> V_112 & ( V_113 ) ) {
if ( V_111 [ V_67 ] . V_109 > 1024 ||
V_111 [ V_67 ] . V_110 > 768 )
continue;
}
if ( V_52 -> V_112 & ( V_114 ) ) {
if ( V_111 [ V_67 ] . V_109 > V_97 -> V_104 ||
V_111 [ V_67 ] . V_110 > V_97 -> V_105 ||
( V_111 [ V_67 ] . V_109 == V_97 -> V_104 &&
V_111 [ V_67 ] . V_110 == V_97 -> V_105 ) )
continue;
}
if ( V_111 [ V_67 ] . V_109 < 320 || V_111 [ V_67 ] . V_110 < 200 )
continue;
V_31 = F_47 ( V_7 , V_111 [ V_67 ] . V_109 , V_111 [ V_67 ] . V_110 , 60 , false , false , false ) ;
F_49 ( V_2 , V_31 ) ;
}
}
static int F_50 ( struct V_1 * V_2 , struct V_115 * V_116 ,
T_1 V_117 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_26 * V_27 ;
struct V_52 * V_52 ;
if ( V_116 == V_9 -> V_118 . V_119 ) {
struct V_53 * V_54 ;
bool V_120 ;
V_27 = F_24 ( V_2 , V_121 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_17 ( V_27 ) ;
if ( ! V_52 -> V_55 )
return 0 ;
V_54 = V_52 -> V_55 ;
V_120 = V_117 ? true : false ;
if ( V_54 -> V_122 != V_120 ) {
V_54 -> V_122 = V_120 ;
F_10 ( & V_52 -> V_87 ) ;
}
}
if ( V_116 == V_9 -> V_118 . V_123 ) {
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_27 = F_24 ( V_2 , V_121 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_17 ( V_27 ) ;
if ( V_3 -> V_124 != V_117 ) {
V_3 -> V_124 = V_117 ;
F_10 ( & V_52 -> V_87 ) ;
}
}
if ( V_116 == V_9 -> V_118 . V_125 ) {
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_27 = F_24 ( V_2 , V_121 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_17 ( V_27 ) ;
if ( V_3 -> V_126 != V_117 ) {
V_3 -> V_126 = V_117 ;
F_10 ( & V_52 -> V_87 ) ;
}
}
if ( V_116 == V_9 -> V_118 . V_127 ) {
V_27 = F_24 ( V_2 , V_121 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_17 ( V_27 ) ;
if ( V_52 -> V_128 != V_117 ) {
V_52 -> V_128 = V_117 ;
F_10 ( & V_52 -> V_87 ) ;
}
}
if ( V_116 == V_9 -> V_118 . V_129 ) {
V_27 = F_24 ( V_2 , V_121 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_17 ( V_27 ) ;
if ( V_52 -> V_130 != V_117 ) {
V_52 -> V_130 = V_117 ;
F_10 ( & V_52 -> V_87 ) ;
}
}
if ( V_116 == V_9 -> V_118 . V_131 ) {
V_27 = F_24 ( V_2 , V_121 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_17 ( V_27 ) ;
if ( V_52 -> V_132 != V_117 ) {
V_52 -> V_132 = V_117 ;
F_10 ( & V_52 -> V_87 ) ;
}
}
if ( V_116 == V_9 -> V_118 . V_133 ) {
V_27 = F_24 ( V_2 , V_134 ) ;
if ( ! V_27 ) {
V_27 = F_24 ( V_2 , V_135 ) ;
}
if ( ! V_27 )
return 0 ;
V_52 = F_17 ( V_27 ) ;
if ( ! V_52 -> V_55 )
return 0 ;
if ( F_51 ( V_9 ) || V_136 ) {
struct V_137 * V_138 ;
V_138 = V_52 -> V_55 ;
V_138 -> V_139 = V_117 ;
} else {
struct V_140 * V_138 ;
V_138 = V_52 -> V_55 ;
V_138 -> V_139 = V_117 ;
}
F_10 ( & V_52 -> V_87 ) ;
}
if ( V_116 == V_9 -> V_118 . V_141 ) {
struct V_3 * V_3 =
F_2 ( V_2 ) ;
if ( V_117 == 0 )
V_3 -> V_142 = false ;
else
V_3 -> V_142 = true ;
}
if ( V_116 == V_9 -> V_118 . V_143 ) {
struct V_144 * V_145 = NULL ;
bool V_4 = false ;
V_27 = F_24 ( V_2 , V_121 ) ;
if ( ! V_27 )
return 0 ;
V_52 = F_17 ( V_27 ) ;
V_145 = V_52 -> V_55 ;
if ( ! V_145 )
return 0 ;
if ( V_117 == 0 ) {
if ( V_9 -> V_71 )
V_4 = F_52 ( V_52 , V_145 ) ;
else
V_4 = F_53 ( V_52 , V_145 ) ;
}
if ( V_117 == 1 || V_4 == false ) {
F_54 ( V_52 , V_145 ) ;
}
F_10 ( & V_52 -> V_87 ) ;
}
if ( V_116 == V_7 -> V_146 . V_147 ) {
enum V_148 V_149 ;
if ( V_2 -> V_27 )
V_52 = F_17 ( V_2 -> V_27 ) ;
else {
const struct V_48 * V_49 = V_2 -> V_50 ;
V_52 = F_17 ( V_49 -> V_51 ( V_2 ) ) ;
}
switch ( V_117 ) {
default:
case V_150 : V_149 = V_151 ; break;
case V_152 : V_149 = V_153 ; break;
case V_154 : V_149 = V_155 ; break;
case V_156 : V_149 = V_157 ; break;
}
if ( V_52 -> V_149 == V_149 )
return 0 ;
if ( ( V_149 != V_150 ) &&
( V_52 -> V_97 . clock == 0 ) )
return 0 ;
V_52 -> V_149 = V_149 ;
F_10 ( & V_52 -> V_87 ) ;
}
if ( V_116 == V_9 -> V_118 . V_158 ) {
if ( V_2 -> V_27 )
V_52 = F_17 ( V_2 -> V_27 ) ;
else {
const struct V_48 * V_49 = V_2 -> V_50 ;
V_52 = F_17 ( V_49 -> V_51 ( V_2 ) ) ;
}
if ( V_52 -> V_159 == V_117 )
return 0 ;
V_52 -> V_159 = V_117 ;
if ( V_2 -> V_27 -> V_29 ) {
struct V_28 * V_29 = V_2 -> V_27 -> V_29 ;
const struct V_160 * V_161 = V_29 -> V_50 ;
struct V_162 * V_162 = F_55 ( V_29 ) ;
V_162 -> V_159 = V_52 -> V_159 ;
(* V_161 -> V_163 )( V_29 ) ;
}
}
return 0 ;
}
static void F_56 ( struct V_26 * V_27 ,
struct V_1 * V_2 )
{
struct V_52 * V_52 = F_17 ( V_27 ) ;
struct V_94 * V_97 = & V_52 -> V_97 ;
struct V_94 * V_164 , * V_31 ;
F_57 (mode, t, &connector->probed_modes, head) {
if ( V_31 -> type & V_106 ) {
if ( V_31 -> V_104 != V_97 -> V_104 ||
V_31 -> V_105 != V_97 -> V_105 )
memcpy ( V_97 , V_31 , sizeof( * V_31 ) ) ;
}
}
if ( ! V_97 -> clock ) {
F_57 (mode, t, &connector->probed_modes, head) {
if ( V_31 -> V_104 == V_97 -> V_104 &&
V_31 -> V_105 == V_97 -> V_105 ) {
* V_97 = * V_31 ;
F_58 ( V_97 , V_165 ) ;
F_43 ( L_14 ) ;
break;
}
}
}
if ( ! V_97 -> clock ) {
F_43 ( L_15 ) ;
V_52 -> V_149 = V_151 ;
}
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_4 = 0 ;
struct V_94 * V_31 ;
F_26 ( V_2 ) ;
V_4 = F_33 ( V_2 ) ;
if ( V_4 > 0 ) {
V_27 = F_37 ( V_2 ) ;
if ( V_27 ) {
F_56 ( V_27 , V_2 ) ;
F_48 ( V_27 , V_2 ) ;
}
return V_4 ;
}
V_27 = F_37 ( V_2 ) ;
if ( ! V_27 )
return 0 ;
V_31 = F_44 ( V_27 ) ;
if ( V_31 ) {
V_4 = 1 ;
F_49 ( V_2 , V_31 ) ;
V_2 -> V_42 . V_166 = V_31 -> V_166 ;
V_2 -> V_42 . V_167 = V_31 -> V_167 ;
F_48 ( V_27 , V_2 ) ;
}
return V_4 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_94 * V_31 )
{
struct V_26 * V_27 = F_37 ( V_2 ) ;
if ( ( V_31 -> V_104 < 320 ) || ( V_31 -> V_105 < 240 ) )
return V_168 ;
if ( V_27 ) {
struct V_52 * V_52 = F_17 ( V_27 ) ;
struct V_94 * V_97 = & V_52 -> V_97 ;
if ( ( V_31 -> V_104 > V_97 -> V_104 ) ||
( V_31 -> V_105 > V_97 -> V_105 ) )
return V_168 ;
if ( V_52 -> V_149 == V_151 ) {
if ( ( V_31 -> V_104 != V_97 -> V_104 ) ||
( V_31 -> V_105 != V_97 -> V_105 ) )
return V_168 ;
}
}
return V_169 ;
}
static enum V_64
F_61 ( struct V_1 * V_2 , bool V_170 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_26 * V_27 = F_37 ( V_2 ) ;
enum V_64 V_4 = V_103 ;
int V_171 ;
V_171 = F_62 ( V_2 -> V_7 -> V_7 ) ;
if ( V_171 < 0 )
return V_103 ;
if ( V_27 ) {
struct V_52 * V_52 = F_17 ( V_27 ) ;
struct V_94 * V_97 = & V_52 -> V_97 ;
if ( V_97 -> V_104 >= 320 && V_97 -> V_105 >= 240 )
V_4 = V_70 ;
if ( ( V_9 -> V_89 & V_90 ) && ( V_91 != 0 ) )
V_4 = V_103 ;
}
F_26 ( V_2 ) ;
if ( V_3 -> V_73 )
V_4 = V_70 ;
F_20 ( V_2 , V_4 ) ;
F_63 ( V_2 -> V_7 -> V_7 ) ;
F_64 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_3 -> V_15 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_115 * V_116 ,
T_1 V_172 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_52 * V_52 ;
enum V_148 V_149 ;
F_43 ( L_16 ) ;
if ( V_116 != V_7 -> V_146 . V_147 )
return 0 ;
if ( V_2 -> V_27 )
V_52 = F_17 ( V_2 -> V_27 ) ;
else {
const struct V_48 * V_49 = V_2 -> V_50 ;
V_52 = F_17 ( V_49 -> V_51 ( V_2 ) ) ;
}
switch ( V_172 ) {
case V_150 : V_149 = V_151 ; break;
case V_152 : V_149 = V_153 ; break;
case V_154 : V_149 = V_155 ; break;
default:
case V_156 : V_149 = V_157 ; break;
}
if ( V_52 -> V_149 == V_149 )
return 0 ;
V_52 -> V_149 = V_149 ;
F_10 ( & V_52 -> V_87 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_4 ;
F_26 ( V_2 ) ;
V_4 = F_33 ( V_2 ) ;
F_38 ( V_2 ) ;
return V_4 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_94 * V_31 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( ( V_31 -> clock / 10 ) > V_9 -> clock . V_173 )
return V_174 ;
return V_169 ;
}
static enum V_64
F_71 ( struct V_1 * V_2 , bool V_170 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
const struct V_175 * V_176 ;
bool V_177 = false ;
enum V_64 V_4 = V_103 ;
int V_171 ;
V_171 = F_62 ( V_2 -> V_7 -> V_7 ) ;
if ( V_171 < 0 )
return V_103 ;
V_27 = F_37 ( V_2 ) ;
if ( ! V_27 )
V_4 = V_103 ;
if ( V_3 -> V_83 )
V_177 = F_72 ( V_3 , false ) ;
if ( V_177 ) {
V_3 -> V_178 = false ;
F_31 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( ! V_3 -> V_73 ) {
F_73 ( L_17 ,
V_2 -> V_59 ) ;
V_4 = V_70 ;
} else {
V_3 -> V_41 =
! ! ( V_3 -> V_73 -> V_179 & V_180 ) ;
if ( V_3 -> V_41 && V_3 -> V_181 ) {
F_31 ( V_2 ) ;
V_4 = V_103 ;
} else {
V_4 = V_70 ;
}
}
} else {
if ( ! V_170 ) {
if ( V_3 -> V_178 )
V_4 = V_2 -> V_65 ;
goto V_182;
}
if ( V_3 -> V_142 && V_27 ) {
V_176 = V_27 -> V_50 ;
V_4 = V_176 -> V_183 ( V_27 , V_2 ) ;
if ( V_4 != V_103 )
V_3 -> V_178 = true ;
}
}
if ( V_4 == V_70 )
V_4 = F_41 ( V_2 , V_27 , V_4 , true ) ;
if ( ( ! V_9 -> V_71 ) &&
( V_4 == V_103 ) &&
V_9 -> V_118 . V_184 ) {
V_4 = V_70 ;
}
F_20 ( V_2 , V_4 ) ;
V_182:
F_63 ( V_2 -> V_7 -> V_7 ) ;
F_64 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_94 * V_185 ;
struct V_26 * V_27 ;
V_27 = F_37 ( V_2 ) ;
if ( ! V_27 )
return 0 ;
if ( V_9 -> V_186 >= V_187 )
F_48 ( V_27 , V_2 ) ;
else {
V_185 = F_47 ( V_7 , 800 , 600 , 60 , false , false , false ) ;
V_185 -> type = V_107 | V_106 ;
F_49 ( V_2 , V_185 ) ;
}
return 1 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_94 * V_31 )
{
if ( ( V_31 -> V_104 > 1024 ) || ( V_31 -> V_105 > 768 ) )
return V_188 ;
return V_169 ;
}
static enum V_64
F_76 ( struct V_1 * V_2 , bool V_170 )
{
struct V_26 * V_27 ;
const struct V_175 * V_176 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_64 V_4 = V_103 ;
int V_171 ;
if ( ! V_3 -> V_142 )
return V_4 ;
V_171 = F_62 ( V_2 -> V_7 -> V_7 ) ;
if ( V_171 < 0 )
return V_103 ;
V_27 = F_37 ( V_2 ) ;
if ( ! V_27 )
V_4 = V_103 ;
else {
V_176 = V_27 -> V_50 ;
V_4 = V_176 -> V_183 ( V_27 , V_2 ) ;
}
if ( V_4 == V_70 )
V_4 = F_41 ( V_2 , V_27 , V_4 , false ) ;
F_20 ( V_2 , V_4 ) ;
F_63 ( V_2 -> V_7 -> V_7 ) ;
F_64 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static bool F_77 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_64 V_65 ;
if ( V_9 -> V_186 >= V_189
&& V_3 -> V_18 . V_18 != V_19 ) {
if ( F_7 ( V_9 , V_3 -> V_18 . V_18 ) )
V_65 = V_70 ;
else
V_65 = V_103 ;
if ( V_2 -> V_65 == V_65 )
return true ;
}
return false ;
}
static enum V_64
F_78 ( struct V_1 * V_2 , bool V_170 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_26 * V_27 = NULL ;
const struct V_175 * V_176 ;
int V_67 , V_171 ;
enum V_64 V_4 = V_103 ;
bool V_177 = false , V_190 = false ;
V_171 = F_62 ( V_2 -> V_7 -> V_7 ) ;
if ( V_171 < 0 )
return V_103 ;
if ( ! V_170 && F_77 ( V_2 ) ) {
V_4 = V_2 -> V_65 ;
goto exit;
}
if ( V_3 -> V_83 )
V_177 = F_72 ( V_3 , false ) ;
if ( V_177 ) {
V_3 -> V_178 = false ;
F_31 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( ! V_3 -> V_73 ) {
F_73 ( L_17 ,
V_2 -> V_59 ) ;
if ( ( V_9 -> V_186 == V_191 || V_9 -> V_186 == V_192 ) &&
V_3 -> V_87 . V_193 ) {
V_4 = V_103 ;
F_73 ( L_18 ,
V_2 -> V_59 ) ;
V_3 -> V_83 = NULL ;
} else {
V_4 = V_70 ;
V_190 = true ;
}
} else {
V_3 -> V_41 =
! ! ( V_3 -> V_73 -> V_179 & V_180 ) ;
if ( ( ! V_3 -> V_41 ) && V_3 -> V_181 ) {
F_31 ( V_2 ) ;
V_4 = V_103 ;
} else {
V_4 = V_70 ;
}
if ( V_3 -> V_181 && ( V_4 == V_70 ) ) {
struct V_1 * V_194 ;
struct V_3 * V_195 ;
F_42 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_194 )
continue;
V_195 = F_2 ( V_194 ) ;
if ( V_195 -> V_181 &&
( V_195 -> V_83 -> V_196 . V_197 ==
V_3 -> V_83 -> V_196 . V_197 ) ) {
if ( V_194 -> V_11 != V_198 ) {
if ( ! F_7 ( V_9 , V_3 -> V_18 . V_18 ) ) {
F_31 ( V_2 ) ;
V_4 = V_103 ;
}
}
}
}
}
}
}
if ( ( V_4 == V_70 ) && ( V_3 -> V_41 == true ) )
goto V_182;
if ( ( V_2 -> V_11 == V_43 ) ||
( V_2 -> V_11 == V_44 ) )
goto V_182;
if ( ! V_170 ) {
if ( V_3 -> V_178 )
V_4 = V_2 -> V_65 ;
goto V_182;
}
if ( V_3 -> V_142 ) {
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_21 ( V_2 -> V_7 ,
V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
if ( V_27 -> V_72 != V_135 &&
V_27 -> V_72 != V_134 )
continue;
V_176 = V_27 -> V_50 ;
if ( V_176 -> V_183 ) {
if ( ! V_190 ) {
if ( V_4 != V_70 ) {
V_4 = V_176 -> V_183 ( V_27 , V_2 ) ;
if ( V_4 == V_70 ) {
V_3 -> V_41 = false ;
}
if ( V_4 != V_103 )
V_3 -> V_178 = true ;
}
} else {
enum V_64 V_199 ;
V_3 -> V_41 = true ;
V_199 = V_176 -> V_183 ( V_27 , V_2 ) ;
F_43 ( L_19 , V_27 -> V_72 , V_199 ) ;
if ( V_199 == V_70 )
V_3 -> V_41 = false ;
}
break;
}
}
}
if ( ( V_4 == V_70 ) && ( V_3 -> V_41 == false ) &&
V_27 ) {
V_4 = F_41 ( V_2 , V_27 , V_4 , true ) ;
}
V_182:
if ( ( ! V_9 -> V_71 ) &&
( V_4 == V_103 ) &&
V_9 -> V_118 . V_184 ) {
V_3 -> V_41 = true ;
V_4 = V_70 ;
}
F_20 ( V_2 , V_4 ) ;
if ( ( V_200 != 0 ) && V_3 -> V_41 ) {
const struct V_48 * V_49 =
V_2 -> V_50 ;
V_27 = V_49 -> V_51 ( V_2 ) ;
if ( V_27 && ( V_27 -> V_72 == V_121 ) ) {
F_26 ( V_2 ) ;
F_79 ( V_2 , V_27 , V_4 ) ;
}
}
exit:
F_63 ( V_2 -> V_7 -> V_7 ) ;
F_64 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static struct V_26 * F_80 ( struct V_1 * V_2 )
{
int V_92 = V_2 -> V_69 [ 0 ] ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_21 ( V_2 -> V_7 , V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
if ( V_3 -> V_41 == true ) {
if ( V_27 -> V_72 == V_121 )
return V_27 ;
} else {
if ( V_27 -> V_72 == V_135 ||
V_27 -> V_72 == V_134 )
return V_27 ;
}
}
if ( V_92 )
return F_21 ( V_2 -> V_7 , V_92 ) ;
return NULL ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_2 -> V_170 == V_201 )
V_3 -> V_41 = false ;
if ( V_2 -> V_170 == V_202 )
V_3 -> V_41 = true ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_94 * V_31 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_41 &&
( V_9 -> V_186 == V_203 ) &&
( V_31 -> clock > 135000 ) )
return V_174 ;
if ( V_3 -> V_41 && ( V_31 -> clock > 165000 ) ) {
if ( ( V_3 -> V_204 == V_205 ) ||
( V_3 -> V_204 == V_206 ) ||
( V_3 -> V_204 == V_207 ) )
return V_169 ;
else if ( F_83 ( V_9 ) && F_13 ( F_14 ( V_2 ) ) ) {
if ( V_31 -> clock > 340000 )
return V_174 ;
else
return V_169 ;
} else {
return V_174 ;
}
}
if ( ( V_31 -> clock / 10 ) > V_9 -> clock . V_173 )
return V_174 ;
return V_169 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_13 * V_208 = V_3 -> V_15 ;
struct V_26 * V_27 = F_37 ( V_2 ) ;
int V_4 ;
if ( ( V_2 -> V_11 == V_46 ) ||
( V_2 -> V_11 == V_47 ) ) {
struct V_94 * V_31 ;
if ( V_2 -> V_11 == V_46 ) {
if ( ! V_208 -> V_209 )
F_85 ( V_2 ,
V_210 ) ;
F_26 ( V_2 ) ;
V_4 = F_33 ( V_2 ) ;
if ( ! V_208 -> V_209 )
F_85 ( V_2 ,
V_211 ) ;
} else {
if ( F_28 ( V_2 ) !=
V_82 ) {
if ( V_27 )
F_86 ( V_27 ) ;
}
F_26 ( V_2 ) ;
V_4 = F_33 ( V_2 ) ;
}
if ( V_4 > 0 ) {
if ( V_27 ) {
F_56 ( V_27 , V_2 ) ;
F_48 ( V_27 , V_2 ) ;
}
return V_4 ;
}
if ( ! V_27 )
return 0 ;
V_31 = F_44 ( V_27 ) ;
if ( V_31 ) {
V_4 = 1 ;
F_49 ( V_2 , V_31 ) ;
V_2 -> V_42 . V_166 = V_31 -> V_166 ;
V_2 -> V_42 . V_167 = V_31 -> V_167 ;
F_48 ( V_27 , V_2 ) ;
}
} else {
if ( F_28 ( V_2 ) !=
V_82 ) {
if ( V_27 )
F_86 ( V_27 ) ;
}
F_26 ( V_2 ) ;
V_4 = F_33 ( V_2 ) ;
F_38 ( V_2 ) ;
}
return V_4 ;
}
T_2 F_28 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_52 * V_52 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_21 ( V_2 -> V_7 , V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
V_52 = F_17 ( V_27 ) ;
switch ( V_52 -> V_212 ) {
case V_213 :
case V_214 :
return V_52 -> V_212 ;
default:
break;
}
}
return V_82 ;
}
static bool F_87 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_52 * V_52 ;
int V_67 ;
bool V_215 = false ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] == 0 )
break;
V_27 = F_21 ( V_2 -> V_7 , V_2 -> V_69 [ V_67 ] ) ;
if ( ! V_27 )
continue;
V_52 = F_17 ( V_27 ) ;
if ( V_52 -> V_216 & V_217 )
V_215 = true ;
}
return V_215 ;
}
bool F_88 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_16 ( V_9 ) &&
( V_9 -> clock . V_218 >= 53900 ) &&
F_87 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_64
F_89 ( struct V_1 * V_2 , bool V_170 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_64 V_4 = V_103 ;
struct V_13 * V_208 = V_3 -> V_15 ;
struct V_26 * V_27 = F_37 ( V_2 ) ;
int V_171 ;
if ( V_208 -> V_17 )
return V_103 ;
V_171 = F_62 ( V_2 -> V_7 -> V_7 ) ;
if ( V_171 < 0 )
return V_103 ;
if ( ! V_170 && F_77 ( V_2 ) ) {
V_4 = V_2 -> V_65 ;
goto V_182;
}
F_31 ( V_2 ) ;
if ( ( V_2 -> V_11 == V_46 ) ||
( V_2 -> V_11 == V_47 ) ) {
if ( V_27 ) {
struct V_52 * V_52 = F_17 ( V_27 ) ;
struct V_94 * V_97 = & V_52 -> V_97 ;
if ( V_97 -> V_104 >= 320 && V_97 -> V_105 >= 240 )
V_4 = V_70 ;
if ( ( V_9 -> V_89 & V_90 ) && ( V_91 != 0 ) )
V_4 = V_103 ;
}
V_208 -> V_22 = V_23 ;
if ( ! V_208 -> V_209 )
F_85 ( V_2 ,
V_210 ) ;
if ( F_90 ( V_3 ) )
V_4 = V_70 ;
if ( ! V_208 -> V_209 )
F_85 ( V_2 ,
V_211 ) ;
} else if ( F_28 ( V_2 ) !=
V_82 ) {
V_208 -> V_22 = V_23 ;
F_90 ( V_3 ) ;
if ( V_27 ) {
F_86 ( V_27 ) ;
if ( F_72 ( V_3 , true ) )
V_4 = V_70 ;
else if ( V_3 -> V_142 ) {
const struct V_175 * V_176 = V_27 -> V_50 ;
V_4 = V_176 -> V_183 ( V_27 , V_2 ) ;
}
}
} else {
V_208 -> V_22 = F_6 ( V_3 ) ;
if ( F_7 ( V_9 , V_3 -> V_18 . V_18 ) ) {
V_4 = V_70 ;
if ( V_208 -> V_22 == V_23 ) {
F_90 ( V_3 ) ;
V_171 = F_91 ( V_3 ) ;
if ( V_171 == 1 )
V_4 = V_103 ;
}
} else {
if ( V_208 -> V_22 == V_23 ) {
if ( F_90 ( V_3 ) ) {
V_171 = F_91 ( V_3 ) ;
if ( V_171 == 1 )
V_4 = V_103 ;
else
V_4 = V_70 ;
}
} else {
if ( F_72 ( V_3 , false ) )
V_4 = V_70 ;
}
}
}
F_20 ( V_2 , V_4 ) ;
if ( ( V_200 != 0 ) && V_27 ) {
F_26 ( V_2 ) ;
F_79 ( V_2 , V_27 , V_4 ) ;
}
V_182:
F_63 ( V_2 -> V_7 -> V_7 ) ;
F_64 ( V_2 -> V_7 -> V_7 ) ;
return V_4 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_94 * V_31 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_13 * V_208 = V_3 -> V_15 ;
if ( ( V_2 -> V_11 == V_46 ) ||
( V_2 -> V_11 == V_47 ) ) {
struct V_26 * V_27 = F_37 ( V_2 ) ;
if ( ( V_31 -> V_104 < 320 ) || ( V_31 -> V_105 < 240 ) )
return V_168 ;
if ( V_27 ) {
struct V_52 * V_52 = F_17 ( V_27 ) ;
struct V_94 * V_97 = & V_52 -> V_97 ;
if ( ( V_31 -> V_104 > V_97 -> V_104 ) ||
( V_31 -> V_105 > V_97 -> V_105 ) )
return V_168 ;
if ( V_52 -> V_149 == V_151 ) {
if ( ( V_31 -> V_104 != V_97 -> V_104 ) ||
( V_31 -> V_105 != V_97 -> V_105 ) )
return V_168 ;
}
}
} else {
if ( ( V_208 -> V_22 == V_23 ) ||
( V_208 -> V_22 == V_45 ) ) {
return F_93 ( V_2 , V_31 ) ;
} else {
if ( F_83 ( V_9 ) && F_13 ( F_14 ( V_2 ) ) ) {
if ( V_31 -> clock > 340000 )
return V_174 ;
} else {
if ( V_31 -> clock > 165000 )
return V_174 ;
}
}
}
return V_169 ;
}
void
F_94 ( struct V_6 * V_7 ,
T_3 V_219 ,
T_3 V_220 ,
int V_11 ,
struct V_221 * V_222 ,
T_3 V_223 ,
T_4 V_204 ,
struct V_224 * V_18 ,
struct V_225 * V_80 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
struct V_13 * V_208 ;
struct V_26 * V_27 ;
struct V_52 * V_52 ;
T_3 V_226 = V_227 ;
bool V_181 = false ;
bool V_228 = false ;
bool V_84 = false ;
if ( V_11 == V_229 )
return;
if ( ( ( V_11 == V_230 ) ||
( V_11 == V_231 ) ||
( V_11 == V_232 ) ) &&
( V_233 == 0 ) )
return;
F_42 (connector, &dev->mode_config.connector_list, head) {
V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_219 == V_219 ) {
V_3 -> V_112 |= V_220 ;
return;
}
if ( V_3 -> V_83 && V_222 -> V_234 ) {
if ( V_3 -> V_83 -> V_196 . V_197 == V_222 -> V_197 ) {
V_3 -> V_181 = true ;
V_181 = true ;
}
if ( V_3 -> V_235 && V_80 -> V_81 &&
( V_3 -> V_80 . V_236 == V_80 -> V_236 ) ) {
V_3 -> V_181 = false ;
V_181 = false ;
}
}
}
F_42 (encoder, &dev->mode_config.encoder_list, head) {
V_52 = F_17 ( V_27 ) ;
if ( V_52 -> V_112 & V_220 ) {
switch ( V_52 -> V_212 ) {
case V_213 :
case V_214 :
V_228 = true ;
break;
default:
break;
}
}
}
V_3 = F_95 ( sizeof( struct V_3 ) , V_79 ) ;
if ( ! V_3 )
return;
V_2 = & V_3 -> V_87 ;
V_3 -> V_219 = V_219 ;
V_3 -> V_112 = V_220 ;
V_3 -> V_181 = V_181 ;
V_3 -> V_204 = V_204 ;
V_3 -> V_18 = * V_18 ;
V_3 -> V_80 = * V_80 ;
if ( V_80 -> V_81 || V_80 -> V_237 ) {
V_3 -> V_235 = F_96 ( V_9 , & V_80 -> V_238 ) ;
if ( ! V_3 -> V_235 )
F_73 ( L_20 ) ;
}
if ( V_228 ) {
V_208 = F_95 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_208 )
goto V_239;
V_208 -> V_223 = V_223 ;
V_3 -> V_15 = V_208 ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( V_3 -> V_83 )
V_84 = true ;
else
F_73 ( L_21 ) ;
}
switch ( V_11 ) {
case V_198 :
case V_240 :
default:
F_97 ( V_7 , & V_3 -> V_87 ,
& V_241 , V_11 ) ;
F_98 ( & V_3 -> V_87 ,
& V_242 ) ;
V_2 -> V_243 = true ;
V_2 -> V_244 = true ;
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_150 ) ;
if ( F_16 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_158 ,
V_245 ) ;
break;
case V_39 :
case V_43 :
case V_44 :
case V_40 :
case V_12 :
F_97 ( V_7 , & V_3 -> V_87 ,
& V_241 , V_11 ) ;
F_98 ( & V_3 -> V_87 ,
& V_242 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_127 ,
V_246 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_129 ,
0 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_131 ,
0 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_150 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_125 ,
V_247 ) ;
if ( V_200 != 0 )
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_123 ,
V_248 ) ;
if ( F_16 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_158 ,
V_245 ) ;
V_226 = V_249 ;
V_2 -> V_243 = true ;
if ( V_11 == V_40 )
V_2 -> V_244 = true ;
else
V_2 -> V_244 = false ;
if ( V_11 == V_39 ) {
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
}
break;
case V_47 :
case V_46 :
F_97 ( V_7 , & V_3 -> V_87 ,
& V_250 , V_11 ) ;
F_98 ( & V_3 -> V_87 ,
& V_242 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_156 ) ;
V_226 = V_249 ;
V_2 -> V_243 = false ;
V_2 -> V_244 = false ;
break;
}
} else {
switch ( V_11 ) {
case V_198 :
F_97 ( V_7 , & V_3 -> V_87 , & V_251 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_252 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_22 ) ;
}
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
if ( F_51 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_150 ) ;
if ( F_16 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_158 ,
V_245 ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_253 = V_254 ;
V_2 -> V_243 = true ;
V_2 -> V_244 = true ;
break;
case V_240 :
F_97 ( V_7 , & V_3 -> V_87 , & V_251 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_252 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_23 ) ;
}
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
if ( F_51 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_150 ) ;
if ( F_16 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_158 ,
V_245 ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_243 = true ;
V_2 -> V_244 = true ;
break;
case V_39 :
case V_43 :
V_208 = F_95 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_208 )
goto V_239;
V_208 -> V_223 = V_223 ;
V_3 -> V_15 = V_208 ;
F_97 ( V_7 , & V_3 -> V_87 , & V_255 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_256 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_24 ) ;
}
V_226 = V_249 ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_119 ,
1 ) ;
if ( F_51 ( V_9 ) ) {
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_127 ,
V_246 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_129 ,
0 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_131 ,
0 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_125 ,
V_247 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_150 ) ;
}
if ( F_100 ( V_9 ) && ( V_200 != 0 ) ) {
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_123 ,
V_248 ) ;
}
if ( V_11 == V_39 ) {
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
}
if ( F_16 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_158 ,
V_245 ) ;
V_2 -> V_243 = true ;
if ( V_11 == V_39 )
V_2 -> V_244 = true ;
else
V_2 -> V_244 = false ;
break;
case V_44 :
case V_40 :
V_208 = F_95 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_208 )
goto V_239;
V_208 -> V_223 = V_223 ;
V_3 -> V_15 = V_208 ;
F_97 ( V_7 , & V_3 -> V_87 , & V_255 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_256 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_25 ) ;
}
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_119 ,
1 ) ;
if ( F_51 ( V_9 ) ) {
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_127 ,
V_246 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_129 ,
0 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_131 ,
0 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_125 ,
V_247 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_150 ) ;
}
if ( F_100 ( V_9 ) && ( V_200 != 0 ) ) {
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_123 ,
V_248 ) ;
}
if ( F_16 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_158 ,
V_245 ) ;
V_226 = V_249 ;
V_2 -> V_243 = true ;
if ( V_11 == V_40 )
V_2 -> V_244 = true ;
else
V_2 -> V_244 = false ;
break;
case V_12 :
V_208 = F_95 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_208 )
goto V_239;
V_208 -> V_223 = V_223 ;
V_3 -> V_15 = V_208 ;
F_97 ( V_7 , & V_3 -> V_87 , & V_241 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_242 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( V_3 -> V_83 )
V_84 = true ;
else
F_73 ( L_21 ) ;
}
V_226 = V_249 ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_119 ,
1 ) ;
if ( F_51 ( V_9 ) ) {
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_127 ,
V_246 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_129 ,
0 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_131 ,
0 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_125 ,
V_247 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_150 ) ;
}
if ( F_100 ( V_9 ) && ( V_200 != 0 ) ) {
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_123 ,
V_248 ) ;
}
if ( F_16 ( V_9 ) )
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_158 ,
V_245 ) ;
V_2 -> V_243 = true ;
V_2 -> V_244 = false ;
break;
case V_46 :
V_208 = F_95 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_208 )
goto V_239;
V_208 -> V_223 = V_223 ;
V_3 -> V_15 = V_208 ;
F_97 ( V_7 , & V_3 -> V_87 , & V_257 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_242 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( V_3 -> V_83 )
V_84 = true ;
else
F_73 ( L_21 ) ;
}
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_156 ) ;
V_226 = V_249 ;
V_2 -> V_243 = false ;
V_2 -> V_244 = false ;
break;
case V_230 :
case V_231 :
case V_232 :
F_97 ( V_7 , & V_3 -> V_87 , & V_258 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_259 ) ;
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_133 ,
F_101 ( V_9 ) ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_243 = false ;
V_2 -> V_244 = false ;
break;
case V_47 :
V_208 = F_95 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_208 )
goto V_239;
V_208 -> V_223 = V_223 ;
V_3 -> V_15 = V_208 ;
F_97 ( V_7 , & V_3 -> V_87 , & V_260 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_261 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_26 ) ;
}
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_156 ) ;
V_226 = V_249 ;
V_2 -> V_243 = false ;
V_2 -> V_244 = false ;
break;
}
}
if ( V_3 -> V_18 . V_18 == V_19 ) {
if ( V_222 -> V_234 )
V_2 -> V_253 = V_254 ;
} else
V_2 -> V_253 = V_262 ;
V_2 -> V_42 . V_226 = V_226 ;
F_102 ( V_2 ) ;
if ( V_84 )
F_103 ( V_3 ) ;
return;
V_239:
F_67 ( V_2 ) ;
F_32 ( V_2 ) ;
}
void
F_104 ( struct V_6 * V_7 ,
T_3 V_219 ,
T_3 V_220 ,
int V_11 ,
struct V_221 * V_222 ,
T_4 V_204 ,
struct V_224 * V_18 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
T_3 V_226 = V_227 ;
if ( V_11 == V_229 )
return;
if ( ( ( V_11 == V_230 ) ||
( V_11 == V_231 ) ||
( V_11 == V_232 ) ) &&
( V_233 == 0 ) )
return;
F_42 (connector, &dev->mode_config.connector_list, head) {
V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_219 == V_219 ) {
V_3 -> V_112 |= V_220 ;
return;
}
}
V_3 = F_95 ( sizeof( struct V_3 ) , V_79 ) ;
if ( ! V_3 )
return;
V_2 = & V_3 -> V_87 ;
V_3 -> V_219 = V_219 ;
V_3 -> V_112 = V_220 ;
V_3 -> V_204 = V_204 ;
V_3 -> V_18 = * V_18 ;
switch ( V_11 ) {
case V_198 :
F_97 ( V_7 , & V_3 -> V_87 , & V_251 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_252 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_22 ) ;
}
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_253 = V_254 ;
V_2 -> V_243 = true ;
V_2 -> V_244 = true ;
break;
case V_240 :
F_97 ( V_7 , & V_3 -> V_87 , & V_251 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_252 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_23 ) ;
}
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_243 = true ;
V_2 -> V_244 = true ;
break;
case V_39 :
case V_43 :
F_97 ( V_7 , & V_3 -> V_87 , & V_255 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_256 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_24 ) ;
}
if ( V_11 == V_39 ) {
V_3 -> V_142 = true ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
1 ) ;
}
V_226 = V_249 ;
V_2 -> V_243 = true ;
if ( V_11 == V_39 )
V_2 -> V_244 = true ;
else
V_2 -> V_244 = false ;
break;
case V_230 :
case V_231 :
case V_232 :
F_97 ( V_7 , & V_3 -> V_87 , & V_258 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_259 ) ;
V_3 -> V_142 = true ;
if ( V_9 -> V_186 == V_263 || V_9 -> V_186 == V_264 )
V_3 -> V_142 = false ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_141 ,
V_3 -> V_142 ) ;
F_99 ( & V_3 -> V_87 . V_87 ,
V_9 -> V_118 . V_133 ,
F_105 ( V_9 ) ) ;
V_3 -> V_18 . V_18 = V_19 ;
V_2 -> V_243 = false ;
V_2 -> V_244 = false ;
break;
case V_47 :
F_97 ( V_7 , & V_3 -> V_87 , & V_260 , V_11 ) ;
F_98 ( & V_3 -> V_87 , & V_261 ) ;
if ( V_222 -> V_234 ) {
V_3 -> V_83 = F_96 ( V_9 , V_222 ) ;
if ( ! V_3 -> V_83 )
F_73 ( L_26 ) ;
}
F_99 ( & V_3 -> V_87 . V_87 ,
V_7 -> V_146 . V_147 ,
V_156 ) ;
V_226 = V_249 ;
V_2 -> V_243 = false ;
V_2 -> V_244 = false ;
break;
}
if ( V_3 -> V_18 . V_18 == V_19 ) {
if ( V_222 -> V_234 )
V_2 -> V_253 = V_254 ;
} else
V_2 -> V_253 = V_262 ;
V_2 -> V_42 . V_226 = V_226 ;
F_102 ( V_2 ) ;
}
void F_106 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
if ( ! F_16 ( V_9 ) )
return;
if ( V_265 == 0 )
return;
F_42 (connector, &dev->mode_config.connector_list, head) {
int V_4 ;
V_3 = F_2 ( V_2 ) ;
if ( V_2 -> V_11 != V_12 )
continue;
V_4 = F_107 ( V_3 ) ;
}
}
