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
switch ( V_2 -> V_13 ) {
case V_33 :
case V_34 :
if ( V_8 -> V_35 ) {
if ( F_11 ( V_8 -> V_36 ) ) {
if ( V_2 -> V_37 . V_32 )
V_32 = V_2 -> V_37 . V_32 ;
}
}
break;
case V_38 :
case V_39 :
if ( F_11 ( V_8 -> V_36 ) ) {
if ( V_2 -> V_37 . V_32 )
V_32 = V_2 -> V_37 . V_32 ;
}
break;
case V_14 :
V_16 = V_8 -> V_17 ;
if ( ( V_16 -> V_18 == V_19 ) ||
( V_16 -> V_18 == V_40 ) ||
F_11 ( V_8 -> V_36 ) ) {
if ( V_2 -> V_37 . V_32 )
V_32 = V_2 -> V_37 . V_32 ;
}
break;
case V_41 :
case V_42 :
if ( V_2 -> V_37 . V_32 )
V_32 = V_2 -> V_37 . V_32 ;
else if ( F_12 ( V_6 ) || F_13 ( V_6 ) ) {
struct V_43 * V_44 =
V_2 -> V_45 ;
struct V_22 * V_23 = V_44 -> V_46 ( V_2 ) ;
struct V_47 * V_47 = F_14 ( V_23 ) ;
struct V_48 * V_49 = V_47 -> V_50 ;
if ( V_49 -> V_51 & V_52 )
V_32 = 6 ;
else if ( V_49 -> V_51 & V_53 )
V_32 = 8 ;
}
break;
}
return V_32 ;
}
static void
F_15 ( struct V_1 * V_2 , enum V_54 V_55 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_46 = NULL ;
struct V_22 * V_23 = NULL ;
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_56 * V_57 ;
bool V_58 ;
int V_59 ;
V_46 = V_44 -> V_46 ( V_2 ) ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( V_2 -> V_61 [ V_59 ] == 0 )
break;
V_57 = F_16 ( V_2 -> V_4 ,
V_2 -> V_61 [ V_59 ] ,
V_62 ) ;
if ( ! V_57 )
continue;
V_23 = F_17 ( V_57 ) ;
if ( ( V_23 == V_46 ) && ( V_55 == V_63 ) )
V_58 = true ;
else
V_58 = false ;
if ( V_6 -> V_64 )
F_18 ( V_2 , V_23 , V_58 ) ;
else
F_19 ( V_2 , V_23 , V_58 ) ;
}
}
static struct V_22 * F_20 ( struct V_1 * V_2 , int V_65 )
{
struct V_56 * V_57 ;
struct V_22 * V_23 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( V_2 -> V_61 [ V_59 ] == 0 )
break;
V_57 = F_16 ( V_2 -> V_4 , V_2 -> V_61 [ V_59 ] , V_62 ) ;
if ( ! V_57 )
continue;
V_23 = F_17 ( V_57 ) ;
if ( V_23 -> V_65 == V_65 )
return V_23 ;
}
return NULL ;
}
static struct V_22 * F_21 ( struct V_1 * V_2 )
{
int V_66 = V_2 -> V_61 [ 0 ] ;
struct V_56 * V_57 ;
struct V_22 * V_23 ;
if ( V_66 ) {
V_57 = F_16 ( V_2 -> V_4 , V_66 , V_62 ) ;
if ( ! V_57 )
return NULL ;
V_23 = F_17 ( V_57 ) ;
return V_23 ;
}
return NULL ;
}
static enum V_54
F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
enum V_54 V_67 ,
bool V_68 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_69 ;
struct V_8 * V_70 ;
int V_59 ;
F_23 (conflict, &dev->mode_config.connector_list, head) {
if ( V_69 == V_2 )
continue;
V_70 = F_2 ( V_69 ) ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( V_69 -> V_61 [ V_59 ] == 0 )
break;
if ( V_69 -> V_61 [ V_59 ] == V_23 -> V_71 . V_72 ) {
if ( V_69 -> V_55 != V_63 )
continue;
if ( V_70 -> V_35 )
continue;
if ( V_68 == true ) {
F_24 ( L_1 , F_25 ( V_69 ) ) ;
F_24 ( L_2 , F_25 ( V_2 ) ) ;
V_69 -> V_55 = V_73 ;
F_15 ( V_69 , V_73 ) ;
} else {
F_24 ( L_3 , F_25 ( V_2 ) ) ;
F_24 ( L_2 , F_25 ( V_69 ) ) ;
V_67 = V_73 ;
}
break;
}
}
}
return V_67 ;
}
static struct V_74 * F_26 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_47 * V_47 = F_14 ( V_23 ) ;
struct V_74 * V_27 = NULL ;
struct V_74 * V_75 = & V_47 -> V_75 ;
if ( V_75 -> V_76 != 0 &&
V_75 -> V_77 != 0 &&
V_75 -> clock != 0 ) {
V_27 = F_27 ( V_4 , V_75 ) ;
V_27 -> type = V_78 | V_79 ;
F_28 ( V_27 ) ;
F_24 ( L_4 , V_27 -> V_80 ) ;
} else if ( V_75 -> V_76 != 0 &&
V_75 -> V_77 != 0 ) {
V_27 = F_29 ( V_4 , V_75 -> V_76 , V_75 -> V_77 , 60 , true , false , false ) ;
V_27 -> type = V_78 | V_79 ;
F_24 ( L_5 , V_27 -> V_80 ) ;
}
return V_27 ;
}
static void F_30 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_47 * V_47 = F_14 ( V_23 ) ;
struct V_74 * V_27 = NULL ;
struct V_74 * V_75 = & V_47 -> V_75 ;
int V_59 ;
struct V_81 {
int V_82 ;
int V_83 ;
} V_84 [ 17 ] = {
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
for ( V_59 = 0 ; V_59 < 17 ; V_59 ++ ) {
if ( V_47 -> V_85 & ( V_86 ) ) {
if ( V_84 [ V_59 ] . V_82 > 1024 ||
V_84 [ V_59 ] . V_83 > 768 )
continue;
}
if ( V_47 -> V_85 & ( V_87 ) ) {
if ( V_84 [ V_59 ] . V_82 > V_75 -> V_76 ||
V_84 [ V_59 ] . V_83 > V_75 -> V_77 ||
( V_84 [ V_59 ] . V_82 == V_75 -> V_76 &&
V_84 [ V_59 ] . V_83 == V_75 -> V_77 ) )
continue;
}
if ( V_84 [ V_59 ] . V_82 < 320 || V_84 [ V_59 ] . V_83 < 200 )
continue;
V_27 = F_29 ( V_4 , V_84 [ V_59 ] . V_82 , V_84 [ V_59 ] . V_83 , 60 , false , false , false ) ;
F_31 ( V_2 , V_27 ) ;
}
}
static int F_32 ( struct V_1 * V_2 , struct V_88 * V_89 ,
T_1 V_90 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_23 ;
struct V_47 * V_47 ;
if ( V_89 == V_6 -> V_91 . V_92 ) {
struct V_48 * V_49 ;
bool V_93 ;
V_23 = F_20 ( V_2 , V_94 ) ;
if ( ! V_23 )
return 0 ;
V_47 = F_14 ( V_23 ) ;
if ( ! V_47 -> V_50 )
return 0 ;
V_49 = V_47 -> V_50 ;
V_93 = V_90 ? true : false ;
if ( V_49 -> V_95 != V_93 ) {
V_49 -> V_95 = V_93 ;
F_8 ( & V_47 -> V_71 ) ;
}
}
if ( V_89 == V_6 -> V_91 . V_96 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_20 ( V_2 , V_94 ) ;
if ( ! V_23 )
return 0 ;
V_47 = F_14 ( V_23 ) ;
if ( V_8 -> V_97 != V_90 ) {
V_8 -> V_97 = V_90 ;
F_8 ( & V_47 -> V_71 ) ;
}
}
if ( V_89 == V_6 -> V_91 . V_98 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_20 ( V_2 , V_94 ) ;
if ( ! V_23 )
return 0 ;
V_47 = F_14 ( V_23 ) ;
if ( V_8 -> V_99 != V_90 ) {
V_8 -> V_99 = V_90 ;
F_8 ( & V_47 -> V_71 ) ;
}
}
if ( V_89 == V_6 -> V_91 . V_100 ) {
V_23 = F_20 ( V_2 , V_94 ) ;
if ( ! V_23 )
return 0 ;
V_47 = F_14 ( V_23 ) ;
if ( V_47 -> V_101 != V_90 ) {
V_47 -> V_101 = V_90 ;
F_8 ( & V_47 -> V_71 ) ;
}
}
if ( V_89 == V_6 -> V_91 . V_102 ) {
V_23 = F_20 ( V_2 , V_94 ) ;
if ( ! V_23 )
return 0 ;
V_47 = F_14 ( V_23 ) ;
if ( V_47 -> V_103 != V_90 ) {
V_47 -> V_103 = V_90 ;
F_8 ( & V_47 -> V_71 ) ;
}
}
if ( V_89 == V_6 -> V_91 . V_104 ) {
V_23 = F_20 ( V_2 , V_94 ) ;
if ( ! V_23 )
return 0 ;
V_47 = F_14 ( V_23 ) ;
if ( V_47 -> V_105 != V_90 ) {
V_47 -> V_105 = V_90 ;
F_8 ( & V_47 -> V_71 ) ;
}
}
if ( V_89 == V_6 -> V_91 . V_106 ) {
V_23 = F_20 ( V_2 , V_107 ) ;
if ( ! V_23 ) {
V_23 = F_20 ( V_2 , V_108 ) ;
}
if ( ! V_23 )
return 0 ;
V_47 = F_14 ( V_23 ) ;
if ( ! V_47 -> V_50 )
return 0 ;
if ( F_33 ( V_6 ) || V_109 ) {
struct V_110 * V_111 ;
V_111 = V_47 -> V_50 ;
V_111 -> V_112 = V_90 ;
} else {
struct V_113 * V_111 ;
V_111 = V_47 -> V_50 ;
V_111 -> V_112 = V_90 ;
}
F_8 ( & V_47 -> V_71 ) ;
}
if ( V_89 == V_6 -> V_91 . V_114 ) {
struct V_8 * V_8 =
F_2 ( V_2 ) ;
if ( V_90 == 0 )
V_8 -> V_115 = false ;
else
V_8 -> V_115 = true ;
}
if ( V_89 == V_6 -> V_91 . V_116 ) {
struct V_117 * V_118 = NULL ;
bool V_119 = false ;
V_23 = F_20 ( V_2 , V_94 ) ;
if ( ! V_23 )
return 0 ;
V_47 = F_14 ( V_23 ) ;
V_118 = V_47 -> V_50 ;
if ( ! V_118 )
return 0 ;
if ( V_90 == 0 ) {
if ( V_6 -> V_64 )
V_119 = F_34 ( V_47 , V_118 ) ;
else
V_119 = F_35 ( V_47 , V_118 ) ;
}
if ( V_90 == 1 || V_119 == false ) {
F_36 ( V_47 , V_118 ) ;
}
F_8 ( & V_47 -> V_71 ) ;
}
return 0 ;
}
static void F_37 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_47 * V_47 = F_14 ( V_23 ) ;
struct V_74 * V_75 = & V_47 -> V_75 ;
struct V_74 * V_120 , * V_27 ;
F_38 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> type & V_78 ) {
if ( V_27 -> V_76 != V_75 -> V_76 ||
V_27 -> V_77 != V_75 -> V_77 )
memcpy ( V_75 , V_27 , sizeof( * V_27 ) ) ;
}
}
if ( ! V_75 -> clock ) {
F_38 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> V_76 == V_75 -> V_76 &&
V_27 -> V_77 == V_75 -> V_77 ) {
* V_75 = * V_27 ;
F_39 ( V_75 , V_121 ) ;
F_24 ( L_6 ) ;
break;
}
}
}
if ( ! V_75 -> clock ) {
F_24 ( L_7 ) ;
V_47 -> V_122 = V_123 ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
int V_119 = 0 ;
struct V_74 * V_27 ;
if ( V_8 -> V_124 ) {
V_119 = F_41 ( V_8 ) ;
if ( V_119 > 0 ) {
V_23 = F_21 ( V_2 ) ;
if ( V_23 ) {
F_37 ( V_23 , V_2 ) ;
F_30 ( V_23 , V_2 ) ;
}
return V_119 ;
}
}
V_23 = F_21 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
V_27 = F_26 ( V_23 ) ;
if ( V_27 ) {
V_119 = 1 ;
F_31 ( V_2 , V_27 ) ;
V_2 -> V_37 . V_125 = V_27 -> V_125 ;
V_2 -> V_37 . V_126 = V_27 -> V_126 ;
F_30 ( V_23 , V_2 ) ;
}
return V_119 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_74 * V_27 )
{
struct V_22 * V_23 = F_21 ( V_2 ) ;
if ( ( V_27 -> V_76 < 320 ) || ( V_27 -> V_77 < 240 ) )
return V_127 ;
if ( V_23 ) {
struct V_47 * V_47 = F_14 ( V_23 ) ;
struct V_74 * V_75 = & V_47 -> V_75 ;
if ( ( V_27 -> V_76 > V_75 -> V_76 ) ||
( V_27 -> V_77 > V_75 -> V_77 ) )
return V_127 ;
if ( V_47 -> V_122 == V_123 ) {
if ( ( V_27 -> V_76 != V_75 -> V_76 ) ||
( V_27 -> V_77 != V_75 -> V_77 ) )
return V_127 ;
}
}
return V_128 ;
}
static enum V_54
F_43 ( struct V_1 * V_2 , bool V_129 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = F_21 ( V_2 ) ;
enum V_54 V_119 = V_73 ;
int V_130 ;
V_130 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_130 < 0 )
return V_73 ;
if ( V_23 ) {
struct V_47 * V_47 = F_14 ( V_23 ) ;
struct V_74 * V_75 = & V_47 -> V_75 ;
if ( V_75 -> V_76 >= 320 && V_75 -> V_77 >= 240 )
V_119 = V_63 ;
}
if ( V_8 -> V_36 )
V_119 = V_63 ;
else {
if ( V_8 -> V_124 ) {
V_8 -> V_36 = F_45 ( & V_8 -> V_71 ,
& V_8 -> V_124 -> V_131 ) ;
if ( V_8 -> V_36 )
V_119 = V_63 ;
}
}
F_15 ( V_2 , V_119 ) ;
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_119 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_36 )
F_49 ( V_8 -> V_36 ) ;
F_49 ( V_8 -> V_17 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_49 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
T_1 V_132 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_47 * V_47 ;
enum V_133 V_122 ;
F_24 ( L_8 ) ;
if ( V_89 != V_4 -> V_134 . V_135 )
return 0 ;
if ( V_2 -> V_23 )
V_47 = F_14 ( V_2 -> V_23 ) ;
else {
struct V_43 * V_44 = V_2 -> V_45 ;
V_47 = F_14 ( V_44 -> V_46 ( V_2 ) ) ;
}
switch ( V_132 ) {
case V_136 : V_122 = V_123 ; break;
case V_137 : V_122 = V_138 ; break;
case V_139 : V_122 = V_140 ; break;
default:
case V_141 : V_122 = V_142 ; break;
}
if ( V_47 -> V_122 == V_122 )
return 0 ;
V_47 -> V_122 = V_122 ;
F_8 ( & V_47 -> V_71 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_119 ;
V_119 = F_41 ( V_8 ) ;
return V_119 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_74 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_143 )
return V_144 ;
return V_128 ;
}
static enum V_54
F_55 ( struct V_1 * V_2 , bool V_129 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
struct V_145 * V_146 ;
bool V_147 = false ;
enum V_54 V_119 = V_73 ;
int V_130 ;
V_130 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_130 < 0 )
return V_73 ;
V_23 = F_21 ( V_2 ) ;
if ( ! V_23 )
V_119 = V_73 ;
if ( V_8 -> V_124 )
V_147 = F_56 ( V_8 , false ) ;
if ( V_147 ) {
V_8 -> V_148 = false ;
if ( V_8 -> V_36 ) {
F_49 ( V_8 -> V_36 ) ;
V_8 -> V_36 = NULL ;
}
V_8 -> V_36 = F_45 ( & V_8 -> V_71 , & V_8 -> V_124 -> V_131 ) ;
if ( ! V_8 -> V_36 ) {
F_57 ( L_9 ,
F_25 ( V_2 ) ) ;
V_119 = V_63 ;
} else {
V_8 -> V_35 = ! ! ( V_8 -> V_36 -> V_149 & V_150 ) ;
if ( V_8 -> V_35 && V_8 -> V_151 ) {
F_49 ( V_8 -> V_36 ) ;
V_8 -> V_36 = NULL ;
V_119 = V_73 ;
} else
V_119 = V_63 ;
}
} else {
if ( ! V_129 ) {
if ( V_8 -> V_148 )
V_119 = V_2 -> V_55 ;
goto V_152;
}
if ( V_8 -> V_115 && V_23 ) {
V_146 = V_23 -> V_45 ;
V_119 = V_146 -> V_153 ( V_23 , V_2 ) ;
if ( V_119 != V_73 )
V_8 -> V_148 = true ;
}
}
if ( V_119 == V_63 )
V_119 = F_22 ( V_2 , V_23 , V_119 , true ) ;
if ( ( ! V_6 -> V_64 ) &&
( V_119 == V_73 ) &&
V_6 -> V_91 . V_154 ) {
V_119 = V_63 ;
}
F_15 ( V_2 , V_119 ) ;
V_152:
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_119 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_74 * V_155 ;
struct V_22 * V_23 ;
V_23 = F_21 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
if ( V_6 -> V_156 >= V_157 )
F_30 ( V_23 , V_2 ) ;
else {
V_155 = F_29 ( V_4 , 800 , 600 , 60 , false , false , false ) ;
V_155 -> type = V_79 | V_78 ;
F_31 ( V_2 , V_155 ) ;
}
return 1 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_74 * V_27 )
{
if ( ( V_27 -> V_76 > 1024 ) || ( V_27 -> V_77 > 768 ) )
return V_158 ;
return V_128 ;
}
static enum V_54
F_60 ( struct V_1 * V_2 , bool V_129 )
{
struct V_22 * V_23 ;
struct V_145 * V_146 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_54 V_119 = V_73 ;
int V_130 ;
if ( ! V_8 -> V_115 )
return V_119 ;
V_130 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_130 < 0 )
return V_73 ;
V_23 = F_21 ( V_2 ) ;
if ( ! V_23 )
V_119 = V_73 ;
else {
V_146 = V_23 -> V_45 ;
V_119 = V_146 -> V_153 ( V_23 , V_2 ) ;
}
if ( V_119 == V_63 )
V_119 = F_22 ( V_2 , V_23 , V_119 , false ) ;
F_15 ( V_2 , V_119 ) ;
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_119 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_119 ;
V_119 = F_41 ( V_8 ) ;
return V_119 ;
}
static bool F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_54 V_55 ;
if ( V_6 -> V_156 >= V_159
&& V_8 -> V_9 . V_9 != V_10 ) {
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) )
V_55 = V_63 ;
else
V_55 = V_73 ;
if ( V_2 -> V_55 == V_55 )
return true ;
}
return false ;
}
static enum V_54
F_63 ( struct V_1 * V_2 , bool V_129 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = NULL ;
struct V_145 * V_146 ;
struct V_56 * V_57 ;
int V_59 , V_130 ;
enum V_54 V_119 = V_73 ;
bool V_147 = false , V_160 = false ;
V_130 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_130 < 0 )
return V_73 ;
if ( ! V_129 && F_62 ( V_2 ) ) {
V_119 = V_2 -> V_55 ;
goto exit;
}
if ( V_8 -> V_124 )
V_147 = F_56 ( V_8 , false ) ;
if ( V_147 ) {
V_8 -> V_148 = false ;
if ( V_8 -> V_36 ) {
F_49 ( V_8 -> V_36 ) ;
V_8 -> V_36 = NULL ;
}
V_8 -> V_36 = F_45 ( & V_8 -> V_71 , & V_8 -> V_124 -> V_131 ) ;
if ( ! V_8 -> V_36 ) {
F_57 ( L_9 ,
F_25 ( V_2 ) ) ;
if ( ( V_6 -> V_156 == V_161 || V_6 -> V_156 == V_162 ) && V_8 -> V_71 . V_163 ) {
V_119 = V_73 ;
F_57 ( L_10 , F_25 ( V_2 ) ) ;
V_8 -> V_124 = NULL ;
} else {
V_119 = V_63 ;
V_160 = true ;
}
} else {
V_8 -> V_35 = ! ! ( V_8 -> V_36 -> V_149 & V_150 ) ;
if ( ( ! V_8 -> V_35 ) && V_8 -> V_151 ) {
F_49 ( V_8 -> V_36 ) ;
V_8 -> V_36 = NULL ;
V_119 = V_73 ;
} else
V_119 = V_63 ;
if ( V_8 -> V_151 && ( V_119 == V_63 ) ) {
struct V_1 * V_164 ;
struct V_8 * V_165 ;
F_23 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_164 )
continue;
V_165 = F_2 ( V_164 ) ;
if ( V_165 -> V_151 &&
( V_165 -> V_124 -> V_166 . V_167 ==
V_8 -> V_124 -> V_166 . V_167 ) ) {
if ( V_164 -> V_13 != V_168 ) {
if ( ! F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_49 ( V_8 -> V_36 ) ;
V_8 -> V_36 = NULL ;
V_119 = V_73 ;
}
}
}
}
}
}
}
if ( ( V_119 == V_63 ) && ( V_8 -> V_35 == true ) )
goto V_152;
if ( ( V_2 -> V_13 == V_38 ) ||
( V_2 -> V_13 == V_39 ) )
goto V_152;
if ( ! V_129 ) {
if ( V_8 -> V_148 )
V_119 = V_2 -> V_55 ;
goto V_152;
}
if ( V_8 -> V_115 ) {
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( V_2 -> V_61 [ V_59 ] == 0 )
break;
V_57 = F_16 ( V_2 -> V_4 ,
V_2 -> V_61 [ V_59 ] ,
V_62 ) ;
if ( ! V_57 )
continue;
V_23 = F_17 ( V_57 ) ;
if ( V_23 -> V_65 != V_108 &&
V_23 -> V_65 != V_107 )
continue;
V_146 = V_23 -> V_45 ;
if ( V_146 -> V_153 ) {
if ( ! V_160 ) {
if ( V_119 != V_63 ) {
V_119 = V_146 -> V_153 ( V_23 , V_2 ) ;
if ( V_119 == V_63 ) {
V_8 -> V_35 = false ;
}
if ( V_119 != V_73 )
V_8 -> V_148 = true ;
}
} else {
enum V_54 V_169 ;
V_8 -> V_35 = true ;
V_169 = V_146 -> V_153 ( V_23 , V_2 ) ;
F_24 ( L_11 , V_23 -> V_65 , V_169 ) ;
if ( V_169 == V_63 )
V_8 -> V_35 = false ;
}
break;
}
}
}
if ( ( V_119 == V_63 ) && ( V_8 -> V_35 == false ) &&
V_23 ) {
V_119 = F_22 ( V_2 , V_23 , V_119 , true ) ;
}
V_152:
if ( ( ! V_6 -> V_64 ) &&
( V_119 == V_73 ) &&
V_6 -> V_91 . V_154 ) {
V_8 -> V_35 = true ;
V_119 = V_63 ;
}
F_15 ( V_2 , V_119 ) ;
exit:
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_119 ;
}
static struct V_22 * F_64 ( struct V_1 * V_2 )
{
int V_66 = V_2 -> V_61 [ 0 ] ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_56 * V_57 ;
struct V_22 * V_23 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( V_2 -> V_61 [ V_59 ] == 0 )
break;
V_57 = F_16 ( V_2 -> V_4 , V_2 -> V_61 [ V_59 ] , V_62 ) ;
if ( ! V_57 )
continue;
V_23 = F_17 ( V_57 ) ;
if ( V_8 -> V_35 == true ) {
if ( V_23 -> V_65 == V_94 )
return V_23 ;
} else {
if ( V_23 -> V_65 == V_108 ||
V_23 -> V_65 == V_107 )
return V_23 ;
}
}
if ( V_66 ) {
V_57 = F_16 ( V_2 -> V_4 , V_66 , V_62 ) ;
if ( ! V_57 )
return NULL ;
V_23 = F_17 ( V_57 ) ;
return V_23 ;
}
return NULL ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_2 -> V_129 == V_170 )
V_8 -> V_35 = false ;
if ( V_2 -> V_129 == V_171 )
V_8 -> V_35 = true ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_74 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_35 &&
( V_6 -> V_156 == V_172 ) &&
( V_27 -> clock > 135000 ) )
return V_144 ;
if ( V_8 -> V_35 && ( V_27 -> clock > 165000 ) ) {
if ( ( V_8 -> V_173 == V_174 ) ||
( V_8 -> V_173 == V_175 ) ||
( V_8 -> V_173 == V_176 ) )
return V_128 ;
else if ( V_8 -> V_173 == V_177 ) {
if ( F_67 ( V_6 ) ) {
if ( V_27 -> clock > 340000 )
return V_144 ;
else
return V_128 ;
} else
return V_144 ;
} else
return V_144 ;
}
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_143 )
return V_144 ;
return V_128 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_178 = V_8 -> V_17 ;
struct V_22 * V_23 = F_21 ( V_2 ) ;
int V_119 ;
if ( ( V_2 -> V_13 == V_41 ) ||
( V_2 -> V_13 == V_42 ) ) {
struct V_74 * V_27 ;
if ( V_2 -> V_13 == V_41 ) {
if ( ! V_178 -> V_179 )
F_69 ( V_2 ,
V_180 ) ;
V_119 = F_41 ( V_8 ) ;
if ( ! V_178 -> V_179 )
F_69 ( V_2 ,
V_181 ) ;
} else {
if ( F_70 ( V_2 ) !=
V_182 ) {
if ( V_23 )
F_71 ( V_23 ) ;
}
V_119 = F_41 ( V_8 ) ;
}
if ( V_119 > 0 ) {
if ( V_23 ) {
F_37 ( V_23 , V_2 ) ;
F_30 ( V_23 , V_2 ) ;
}
return V_119 ;
}
if ( ! V_23 )
return 0 ;
V_27 = F_26 ( V_23 ) ;
if ( V_27 ) {
V_119 = 1 ;
F_31 ( V_2 , V_27 ) ;
V_2 -> V_37 . V_125 = V_27 -> V_125 ;
V_2 -> V_37 . V_126 = V_27 -> V_126 ;
F_30 ( V_23 , V_2 ) ;
}
} else {
if ( F_70 ( V_2 ) !=
V_182 ) {
if ( V_23 )
F_71 ( V_23 ) ;
}
V_119 = F_41 ( V_8 ) ;
}
return V_119 ;
}
T_2 F_70 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
struct V_22 * V_23 ;
struct V_47 * V_47 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( V_2 -> V_61 [ V_59 ] == 0 )
break;
V_57 = F_16 ( V_2 -> V_4 , V_2 -> V_61 [ V_59 ] , V_62 ) ;
if ( ! V_57 )
continue;
V_23 = F_17 ( V_57 ) ;
V_47 = F_14 ( V_23 ) ;
switch ( V_47 -> V_183 ) {
case V_184 :
case V_185 :
return V_47 -> V_183 ;
default:
break;
}
}
return V_182 ;
}
bool F_72 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
struct V_22 * V_23 ;
struct V_47 * V_47 ;
int V_59 ;
bool V_186 = false ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( V_2 -> V_61 [ V_59 ] == 0 )
break;
V_57 = F_16 ( V_2 -> V_4 , V_2 -> V_61 [ V_59 ] , V_62 ) ;
if ( ! V_57 )
continue;
V_23 = F_17 ( V_57 ) ;
V_47 = F_14 ( V_23 ) ;
if ( V_47 -> V_187 & V_188 )
V_186 = true ;
}
return V_186 ;
}
bool F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_13 ( V_6 ) &&
( V_6 -> clock . V_189 >= 53900 ) &&
F_72 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_54
F_74 ( struct V_1 * V_2 , bool V_129 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_54 V_119 = V_73 ;
struct V_15 * V_178 = V_8 -> V_17 ;
struct V_22 * V_23 = F_21 ( V_2 ) ;
int V_130 ;
V_130 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_130 < 0 )
return V_73 ;
if ( ! V_129 && F_62 ( V_2 ) ) {
V_119 = V_2 -> V_55 ;
goto V_152;
}
if ( V_8 -> V_36 ) {
F_49 ( V_8 -> V_36 ) ;
V_8 -> V_36 = NULL ;
}
if ( ( V_2 -> V_13 == V_41 ) ||
( V_2 -> V_13 == V_42 ) ) {
if ( V_23 ) {
struct V_47 * V_47 = F_14 ( V_23 ) ;
struct V_74 * V_75 = & V_47 -> V_75 ;
if ( V_75 -> V_76 >= 320 && V_75 -> V_77 >= 240 )
V_119 = V_63 ;
}
V_178 -> V_18 = V_19 ;
if ( ! V_178 -> V_179 )
F_69 ( V_2 ,
V_180 ) ;
if ( F_75 ( V_8 ) )
V_119 = V_63 ;
if ( ! V_178 -> V_179 )
F_69 ( V_2 ,
V_181 ) ;
} else if ( F_70 ( V_2 ) !=
V_182 ) {
V_178 -> V_18 = V_19 ;
F_75 ( V_8 ) ;
if ( V_23 ) {
F_71 ( V_23 ) ;
if ( F_56 ( V_8 , true ) )
V_119 = V_63 ;
else if ( V_8 -> V_115 ) {
struct V_145 * V_146 = V_23 -> V_45 ;
V_119 = V_146 -> V_153 ( V_23 , V_2 ) ;
}
}
} else {
V_178 -> V_18 = F_4 ( V_8 ) ;
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
V_119 = V_63 ;
if ( V_178 -> V_18 == V_19 )
F_75 ( V_8 ) ;
} else {
if ( V_178 -> V_18 == V_19 ) {
if ( F_75 ( V_8 ) )
V_119 = V_63 ;
} else {
if ( F_56 ( V_8 , false ) )
V_119 = V_63 ;
}
}
}
F_15 ( V_2 , V_119 ) ;
V_152:
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_119 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_74 * V_27 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_178 = V_8 -> V_17 ;
if ( ( V_2 -> V_13 == V_41 ) ||
( V_2 -> V_13 == V_42 ) ) {
struct V_22 * V_23 = F_21 ( V_2 ) ;
if ( ( V_27 -> V_76 < 320 ) || ( V_27 -> V_77 < 240 ) )
return V_127 ;
if ( V_23 ) {
struct V_47 * V_47 = F_14 ( V_23 ) ;
struct V_74 * V_75 = & V_47 -> V_75 ;
if ( ( V_27 -> V_76 > V_75 -> V_76 ) ||
( V_27 -> V_77 > V_75 -> V_77 ) )
return V_127 ;
if ( V_47 -> V_122 == V_123 ) {
if ( ( V_27 -> V_76 != V_75 -> V_76 ) ||
( V_27 -> V_77 != V_75 -> V_77 ) )
return V_127 ;
}
}
return V_128 ;
} else {
if ( ( V_178 -> V_18 == V_19 ) ||
( V_178 -> V_18 == V_40 ) )
return F_77 ( V_2 , V_27 ) ;
else
return V_128 ;
}
}
void
F_78 ( struct V_3 * V_4 ,
T_3 V_190 ,
T_3 V_191 ,
int V_13 ,
struct V_192 * V_193 ,
T_3 V_194 ,
T_4 V_173 ,
struct V_195 * V_9 ,
struct V_196 * V_197 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_15 * V_178 ;
struct V_22 * V_23 ;
struct V_47 * V_47 ;
T_3 V_198 = V_199 ;
bool V_151 = false ;
bool V_200 = false ;
bool V_201 = false ;
if ( V_13 == V_202 )
return;
if ( ( ( V_13 == V_203 ) ||
( V_13 == V_204 ) ||
( V_13 == V_205 ) ) &&
( V_206 == 0 ) )
return;
F_23 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_190 == V_190 ) {
V_8 -> V_85 |= V_191 ;
return;
}
if ( V_8 -> V_124 && V_193 -> V_207 ) {
if ( V_8 -> V_124 -> V_166 . V_167 == V_193 -> V_167 ) {
V_8 -> V_151 = true ;
V_151 = true ;
}
if ( V_8 -> V_208 && V_197 -> V_209 &&
( V_8 -> V_197 . V_210 == V_197 -> V_210 ) ) {
V_8 -> V_151 = false ;
V_151 = false ;
}
}
}
F_23 (encoder, &dev->mode_config.encoder_list, head) {
V_47 = F_14 ( V_23 ) ;
if ( V_47 -> V_85 & V_191 ) {
switch ( V_47 -> V_183 ) {
case V_184 :
case V_185 :
V_200 = true ;
break;
default:
break;
}
}
}
V_8 = F_79 ( sizeof( struct V_8 ) , V_211 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_71 ;
V_8 -> V_190 = V_190 ;
V_8 -> V_85 = V_191 ;
V_8 -> V_151 = V_151 ;
V_8 -> V_173 = V_173 ;
V_8 -> V_9 = * V_9 ;
V_8 -> V_197 = * V_197 ;
if ( V_197 -> V_209 || V_197 -> V_212 ) {
V_8 -> V_208 = F_80 ( V_6 , & V_197 -> V_213 ) ;
if ( ! V_8 -> V_208 )
F_57 ( L_12 ) ;
}
if ( V_200 ) {
V_178 = F_79 ( sizeof( struct V_15 ) , V_211 ) ;
if ( ! V_178 )
goto V_214;
V_178 -> V_194 = V_194 ;
V_8 -> V_17 = V_178 ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( V_8 -> V_124 )
V_201 = true ;
else
F_57 ( L_13 ) ;
}
switch ( V_13 ) {
case V_168 :
case V_215 :
default:
F_81 ( V_4 , & V_8 -> V_71 ,
& V_216 , V_13 ) ;
F_82 ( & V_8 -> V_71 ,
& V_217 ) ;
V_2 -> V_218 = true ;
V_2 -> V_219 = true ;
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
break;
case V_33 :
case V_38 :
case V_39 :
case V_34 :
case V_14 :
F_81 ( V_4 , & V_8 -> V_71 ,
& V_216 , V_13 ) ;
F_82 ( & V_8 -> V_71 ,
& V_217 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_100 ,
V_220 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_102 ,
0 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_104 ,
0 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_98 ,
V_221 ) ;
if ( V_222 != 0 )
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_96 ,
V_223 ) ;
V_198 = V_224 ;
V_2 -> V_218 = true ;
if ( V_13 == V_34 )
V_2 -> V_219 = true ;
else
V_2 -> V_219 = false ;
if ( V_13 == V_33 ) {
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
}
break;
case V_42 :
case V_41 :
F_81 ( V_4 , & V_8 -> V_71 ,
& V_225 , V_13 ) ;
F_82 ( & V_8 -> V_71 ,
& V_217 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_4 -> V_134 . V_135 ,
V_141 ) ;
V_198 = V_224 ;
V_2 -> V_218 = false ;
V_2 -> V_219 = false ;
break;
}
} else {
switch ( V_13 ) {
case V_168 :
F_81 ( V_4 , & V_8 -> V_71 , & V_226 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_227 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_14 ) ;
}
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_228 = V_229 ;
V_2 -> V_218 = true ;
V_2 -> V_219 = true ;
break;
case V_215 :
F_81 ( V_4 , & V_8 -> V_71 , & V_226 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_227 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_15 ) ;
}
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_218 = true ;
V_2 -> V_219 = true ;
break;
case V_33 :
case V_38 :
V_178 = F_79 ( sizeof( struct V_15 ) , V_211 ) ;
if ( ! V_178 )
goto V_214;
V_178 -> V_194 = V_194 ;
V_8 -> V_17 = V_178 ;
F_81 ( V_4 , & V_8 -> V_71 , & V_230 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_231 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_16 ) ;
}
V_198 = V_224 ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_92 ,
1 ) ;
if ( F_33 ( V_6 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_100 ,
V_220 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_102 ,
0 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_104 ,
0 ) ;
}
if ( F_84 ( V_6 ) && ( V_222 != 0 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_96 ,
V_223 ) ;
}
if ( F_33 ( V_6 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_98 ,
V_221 ) ;
}
if ( V_13 == V_33 ) {
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
}
V_2 -> V_218 = true ;
if ( V_13 == V_33 )
V_2 -> V_219 = true ;
else
V_2 -> V_219 = false ;
break;
case V_39 :
case V_34 :
V_178 = F_79 ( sizeof( struct V_15 ) , V_211 ) ;
if ( ! V_178 )
goto V_214;
V_178 -> V_194 = V_194 ;
V_8 -> V_17 = V_178 ;
F_81 ( V_4 , & V_8 -> V_71 , & V_230 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_231 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_17 ) ;
}
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_92 ,
1 ) ;
if ( F_33 ( V_6 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_100 ,
V_220 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_102 ,
0 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_104 ,
0 ) ;
}
if ( F_84 ( V_6 ) && ( V_222 != 0 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_96 ,
V_223 ) ;
}
if ( F_33 ( V_6 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_98 ,
V_221 ) ;
}
V_198 = V_224 ;
V_2 -> V_218 = true ;
if ( V_13 == V_34 )
V_2 -> V_219 = true ;
else
V_2 -> V_219 = false ;
break;
case V_14 :
V_178 = F_79 ( sizeof( struct V_15 ) , V_211 ) ;
if ( ! V_178 )
goto V_214;
V_178 -> V_194 = V_194 ;
V_8 -> V_17 = V_178 ;
F_81 ( V_4 , & V_8 -> V_71 , & V_216 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_217 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( V_8 -> V_124 )
V_201 = true ;
else
F_57 ( L_13 ) ;
}
V_198 = V_224 ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_92 ,
1 ) ;
if ( F_33 ( V_6 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_100 ,
V_220 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_102 ,
0 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_104 ,
0 ) ;
}
if ( F_84 ( V_6 ) && ( V_222 != 0 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_96 ,
V_223 ) ;
}
if ( F_33 ( V_6 ) ) {
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_98 ,
V_221 ) ;
}
V_2 -> V_218 = true ;
V_2 -> V_219 = false ;
break;
case V_41 :
V_178 = F_79 ( sizeof( struct V_15 ) , V_211 ) ;
if ( ! V_178 )
goto V_214;
V_178 -> V_194 = V_194 ;
V_8 -> V_17 = V_178 ;
F_81 ( V_4 , & V_8 -> V_71 , & V_232 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_217 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( V_8 -> V_124 )
V_201 = true ;
else
F_57 ( L_13 ) ;
}
F_83 ( & V_8 -> V_71 . V_71 ,
V_4 -> V_134 . V_135 ,
V_141 ) ;
V_198 = V_224 ;
V_2 -> V_218 = false ;
V_2 -> V_219 = false ;
break;
case V_203 :
case V_204 :
case V_205 :
F_81 ( V_4 , & V_8 -> V_71 , & V_233 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_234 ) ;
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_106 ,
F_85 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_218 = false ;
V_2 -> V_219 = false ;
break;
case V_42 :
V_178 = F_79 ( sizeof( struct V_15 ) , V_211 ) ;
if ( ! V_178 )
goto V_214;
V_178 -> V_194 = V_194 ;
V_8 -> V_17 = V_178 ;
F_81 ( V_4 , & V_8 -> V_71 , & V_235 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_236 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_18 ) ;
}
F_83 ( & V_8 -> V_71 . V_71 ,
V_4 -> V_134 . V_135 ,
V_141 ) ;
V_198 = V_224 ;
V_2 -> V_218 = false ;
V_2 -> V_219 = false ;
break;
}
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_193 -> V_207 )
V_2 -> V_228 = V_229 ;
} else
V_2 -> V_228 = V_237 ;
V_2 -> V_37 . V_198 = V_198 ;
F_86 ( V_2 ) ;
if ( V_201 )
F_87 ( V_8 ) ;
return;
V_214:
F_51 ( V_2 ) ;
F_49 ( V_2 ) ;
}
void
F_88 ( struct V_3 * V_4 ,
T_3 V_190 ,
T_3 V_191 ,
int V_13 ,
struct V_192 * V_193 ,
T_4 V_173 ,
struct V_195 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
T_3 V_198 = V_199 ;
if ( V_13 == V_202 )
return;
if ( ( ( V_13 == V_203 ) ||
( V_13 == V_204 ) ||
( V_13 == V_205 ) ) &&
( V_206 == 0 ) )
return;
F_23 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_190 == V_190 ) {
V_8 -> V_85 |= V_191 ;
return;
}
}
V_8 = F_79 ( sizeof( struct V_8 ) , V_211 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_71 ;
V_8 -> V_190 = V_190 ;
V_8 -> V_85 = V_191 ;
V_8 -> V_173 = V_173 ;
V_8 -> V_9 = * V_9 ;
switch ( V_13 ) {
case V_168 :
F_81 ( V_4 , & V_8 -> V_71 , & V_226 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_227 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_14 ) ;
}
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_228 = V_229 ;
V_2 -> V_218 = true ;
V_2 -> V_219 = true ;
break;
case V_215 :
F_81 ( V_4 , & V_8 -> V_71 , & V_226 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_227 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_15 ) ;
}
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_218 = true ;
V_2 -> V_219 = true ;
break;
case V_33 :
case V_38 :
F_81 ( V_4 , & V_8 -> V_71 , & V_230 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_231 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_16 ) ;
}
if ( V_13 == V_33 ) {
V_8 -> V_115 = true ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
1 ) ;
}
V_198 = V_224 ;
V_2 -> V_218 = true ;
if ( V_13 == V_33 )
V_2 -> V_219 = true ;
else
V_2 -> V_219 = false ;
break;
case V_203 :
case V_204 :
case V_205 :
F_81 ( V_4 , & V_8 -> V_71 , & V_233 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_234 ) ;
V_8 -> V_115 = true ;
if ( V_6 -> V_156 == V_238 || V_6 -> V_156 == V_239 )
V_8 -> V_115 = false ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_114 ,
V_8 -> V_115 ) ;
F_83 ( & V_8 -> V_71 . V_71 ,
V_6 -> V_91 . V_106 ,
F_89 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_218 = false ;
V_2 -> V_219 = false ;
break;
case V_42 :
F_81 ( V_4 , & V_8 -> V_71 , & V_235 , V_13 ) ;
F_82 ( & V_8 -> V_71 , & V_236 ) ;
if ( V_193 -> V_207 ) {
V_8 -> V_124 = F_80 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_124 )
F_57 ( L_18 ) ;
}
F_83 ( & V_8 -> V_71 . V_71 ,
V_4 -> V_134 . V_135 ,
V_141 ) ;
V_198 = V_224 ;
V_2 -> V_218 = false ;
V_2 -> V_219 = false ;
break;
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_193 -> V_207 )
V_2 -> V_228 = V_229 ;
} else
V_2 -> V_228 = V_237 ;
V_2 -> V_37 . V_198 = V_198 ;
F_86 ( V_2 ) ;
}
