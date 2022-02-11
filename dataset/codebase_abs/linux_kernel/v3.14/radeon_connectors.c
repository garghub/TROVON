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
V_25 -> V_28 , V_25 -> V_29 , V_25 -> V_30 ) ;
}
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_16 ;
int V_31 = 8 ;
switch ( V_2 -> V_13 ) {
case V_32 :
case V_33 :
if ( V_8 -> V_34 ) {
if ( F_11 ( V_8 -> V_35 ) ) {
if ( V_2 -> V_36 . V_31 )
V_31 = V_2 -> V_36 . V_31 ;
}
}
break;
case V_37 :
case V_38 :
if ( F_11 ( V_8 -> V_35 ) ) {
if ( V_2 -> V_36 . V_31 )
V_31 = V_2 -> V_36 . V_31 ;
}
break;
case V_14 :
V_16 = V_8 -> V_17 ;
if ( ( V_16 -> V_18 == V_19 ) ||
( V_16 -> V_18 == V_39 ) ||
F_11 ( V_8 -> V_35 ) ) {
if ( V_2 -> V_36 . V_31 )
V_31 = V_2 -> V_36 . V_31 ;
}
break;
case V_40 :
case V_41 :
if ( V_2 -> V_36 . V_31 )
V_31 = V_2 -> V_36 . V_31 ;
else if ( F_12 ( V_6 ) || F_13 ( V_6 ) ) {
struct V_42 * V_43 =
V_2 -> V_44 ;
struct V_22 * V_23 = V_43 -> V_45 ( V_2 ) ;
struct V_46 * V_46 = F_14 ( V_23 ) ;
struct V_47 * V_48 = V_46 -> V_49 ;
if ( V_48 -> V_50 & V_51 )
V_31 = 6 ;
else if ( V_48 -> V_50 & V_52 )
V_31 = 8 ;
}
break;
}
return V_31 ;
}
static void
F_15 ( struct V_1 * V_2 , enum V_53 V_54 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_45 = NULL ;
struct V_22 * V_23 = NULL ;
struct V_42 * V_43 = V_2 -> V_44 ;
struct V_55 * V_56 ;
bool V_57 ;
int V_58 ;
V_45 = V_43 -> V_45 ( V_2 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_16 ( V_2 -> V_4 ,
V_2 -> V_60 [ V_58 ] ,
V_61 ) ;
if ( ! V_56 )
continue;
V_23 = F_17 ( V_56 ) ;
if ( ( V_23 == V_45 ) && ( V_54 == V_62 ) )
V_57 = true ;
else
V_57 = false ;
if ( V_6 -> V_63 )
F_18 ( V_2 , V_23 , V_57 ) ;
else
F_19 ( V_2 , V_23 , V_57 ) ;
}
}
static struct V_22 * F_20 ( struct V_1 * V_2 , int V_64 )
{
struct V_55 * V_56 ;
struct V_22 * V_23 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_16 ( V_2 -> V_4 , V_2 -> V_60 [ V_58 ] , V_61 ) ;
if ( ! V_56 )
continue;
V_23 = F_17 ( V_56 ) ;
if ( V_23 -> V_64 == V_64 )
return V_23 ;
}
return NULL ;
}
static struct V_22 * F_21 ( struct V_1 * V_2 )
{
int V_65 = V_2 -> V_60 [ 0 ] ;
struct V_55 * V_56 ;
struct V_22 * V_23 ;
if ( V_65 ) {
V_56 = F_16 ( V_2 -> V_4 , V_65 , V_61 ) ;
if ( ! V_56 )
return NULL ;
V_23 = F_17 ( V_56 ) ;
return V_23 ;
}
return NULL ;
}
static enum V_53
F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
enum V_53 V_66 ,
bool V_67 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_68 ;
struct V_8 * V_69 ;
int V_58 ;
F_23 (conflict, &dev->mode_config.connector_list, head) {
if ( V_68 == V_2 )
continue;
V_69 = F_2 ( V_68 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_68 -> V_60 [ V_58 ] == 0 )
break;
if ( V_68 -> V_60 [ V_58 ] == V_23 -> V_70 . V_71 ) {
if ( V_68 -> V_54 != V_62 )
continue;
if ( V_69 -> V_34 )
continue;
if ( V_67 == true ) {
F_24 ( L_1 , F_25 ( V_68 ) ) ;
F_24 ( L_2 , F_25 ( V_2 ) ) ;
V_68 -> V_54 = V_72 ;
F_15 ( V_68 , V_72 ) ;
} else {
F_24 ( L_3 , F_25 ( V_2 ) ) ;
F_24 ( L_2 , F_25 ( V_68 ) ) ;
V_66 = V_72 ;
}
break;
}
}
}
return V_66 ;
}
static struct V_73 * F_26 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_46 * V_46 = F_14 ( V_23 ) ;
struct V_73 * V_27 = NULL ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( V_74 -> V_75 != 0 &&
V_74 -> V_76 != 0 &&
V_74 -> clock != 0 ) {
V_27 = F_27 ( V_4 , V_74 ) ;
V_27 -> type = V_77 | V_78 ;
F_28 ( V_27 ) ;
F_24 ( L_4 , V_27 -> V_79 ) ;
} else if ( V_74 -> V_75 != 0 &&
V_74 -> V_76 != 0 ) {
V_27 = F_29 ( V_4 , V_74 -> V_75 , V_74 -> V_76 , 60 , true , false , false ) ;
V_27 -> type = V_77 | V_78 ;
F_24 ( L_5 , V_27 -> V_79 ) ;
}
return V_27 ;
}
static void F_30 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_46 * V_46 = F_14 ( V_23 ) ;
struct V_73 * V_27 = NULL ;
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
V_27 = F_29 ( V_4 , V_83 [ V_58 ] . V_81 , V_83 [ V_58 ] . V_82 , 60 , false , false , false ) ;
F_31 ( V_2 , V_27 ) ;
}
}
static int F_32 ( struct V_1 * V_2 , struct V_87 * V_88 ,
T_1 V_89 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_23 ;
struct V_46 * V_46 ;
if ( V_88 == V_6 -> V_90 . V_91 ) {
struct V_47 * V_48 ;
bool V_92 ;
V_23 = F_20 ( V_2 , V_93 ) ;
if ( ! V_23 )
return 0 ;
V_46 = F_14 ( V_23 ) ;
if ( ! V_46 -> V_49 )
return 0 ;
V_48 = V_46 -> V_49 ;
V_92 = V_89 ? true : false ;
if ( V_48 -> V_94 != V_92 ) {
V_48 -> V_94 = V_92 ;
F_8 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_95 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_20 ( V_2 , V_93 ) ;
if ( ! V_23 )
return 0 ;
V_46 = F_14 ( V_23 ) ;
if ( V_8 -> V_96 != V_89 ) {
V_8 -> V_96 = V_89 ;
F_8 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_97 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_20 ( V_2 , V_93 ) ;
if ( ! V_23 )
return 0 ;
V_46 = F_14 ( V_23 ) ;
if ( V_8 -> V_98 != V_89 ) {
V_8 -> V_98 = V_89 ;
F_8 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_99 ) {
V_23 = F_20 ( V_2 , V_93 ) ;
if ( ! V_23 )
return 0 ;
V_46 = F_14 ( V_23 ) ;
if ( V_46 -> V_100 != V_89 ) {
V_46 -> V_100 = V_89 ;
F_8 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_101 ) {
V_23 = F_20 ( V_2 , V_93 ) ;
if ( ! V_23 )
return 0 ;
V_46 = F_14 ( V_23 ) ;
if ( V_46 -> V_102 != V_89 ) {
V_46 -> V_102 = V_89 ;
F_8 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_103 ) {
V_23 = F_20 ( V_2 , V_93 ) ;
if ( ! V_23 )
return 0 ;
V_46 = F_14 ( V_23 ) ;
if ( V_46 -> V_104 != V_89 ) {
V_46 -> V_104 = V_89 ;
F_8 ( & V_46 -> V_70 ) ;
}
}
if ( V_88 == V_6 -> V_90 . V_105 ) {
V_23 = F_20 ( V_2 , V_106 ) ;
if ( ! V_23 ) {
V_23 = F_20 ( V_2 , V_107 ) ;
}
if ( ! V_23 )
return 0 ;
V_46 = F_14 ( V_23 ) ;
if ( ! V_46 -> V_49 )
return 0 ;
if ( F_33 ( V_6 ) || V_108 ) {
struct V_109 * V_110 ;
V_110 = V_46 -> V_49 ;
V_110 -> V_111 = V_89 ;
} else {
struct V_112 * V_110 ;
V_110 = V_46 -> V_49 ;
V_110 -> V_111 = V_89 ;
}
F_8 ( & V_46 -> V_70 ) ;
}
if ( V_88 == V_6 -> V_90 . V_113 ) {
struct V_8 * V_8 =
F_2 ( V_2 ) ;
if ( V_89 == 0 )
V_8 -> V_114 = false ;
else
V_8 -> V_114 = true ;
}
if ( V_88 == V_6 -> V_90 . V_115 ) {
struct V_116 * V_117 = NULL ;
bool V_118 = false ;
V_23 = F_20 ( V_2 , V_93 ) ;
if ( ! V_23 )
return 0 ;
V_46 = F_14 ( V_23 ) ;
V_117 = V_46 -> V_49 ;
if ( ! V_117 )
return 0 ;
if ( V_89 == 0 ) {
if ( V_6 -> V_63 )
V_118 = F_34 ( V_46 , V_117 ) ;
else
V_118 = F_35 ( V_46 , V_117 ) ;
}
if ( V_89 == 1 || V_118 == false ) {
F_36 ( V_46 , V_117 ) ;
}
F_8 ( & V_46 -> V_70 ) ;
}
return 0 ;
}
static void F_37 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_46 * V_46 = F_14 ( V_23 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
struct V_73 * V_119 , * V_27 ;
F_38 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> type & V_77 ) {
if ( V_27 -> V_75 != V_74 -> V_75 ||
V_27 -> V_76 != V_74 -> V_76 )
memcpy ( V_74 , V_27 , sizeof( * V_27 ) ) ;
}
}
if ( ! V_74 -> clock ) {
F_38 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> V_75 == V_74 -> V_75 &&
V_27 -> V_76 == V_74 -> V_76 ) {
* V_74 = * V_27 ;
F_39 ( V_74 , V_120 ) ;
F_24 ( L_6 ) ;
break;
}
}
}
if ( ! V_74 -> clock ) {
F_24 ( L_7 ) ;
V_46 -> V_121 = V_122 ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
int V_118 = 0 ;
struct V_73 * V_27 ;
if ( V_8 -> V_123 ) {
V_118 = F_41 ( V_8 ) ;
if ( V_118 > 0 ) {
V_23 = F_21 ( V_2 ) ;
if ( V_23 ) {
F_37 ( V_23 , V_2 ) ;
F_30 ( V_23 , V_2 ) ;
}
return V_118 ;
}
}
V_23 = F_21 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
V_27 = F_26 ( V_23 ) ;
if ( V_27 ) {
V_118 = 1 ;
F_31 ( V_2 , V_27 ) ;
V_2 -> V_36 . V_124 = V_27 -> V_124 ;
V_2 -> V_36 . V_125 = V_27 -> V_125 ;
F_30 ( V_23 , V_2 ) ;
}
return V_118 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_73 * V_27 )
{
struct V_22 * V_23 = F_21 ( V_2 ) ;
if ( ( V_27 -> V_75 < 320 ) || ( V_27 -> V_76 < 240 ) )
return V_126 ;
if ( V_23 ) {
struct V_46 * V_46 = F_14 ( V_23 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( ( V_27 -> V_75 > V_74 -> V_75 ) ||
( V_27 -> V_76 > V_74 -> V_76 ) )
return V_126 ;
if ( V_46 -> V_121 == V_122 ) {
if ( ( V_27 -> V_75 != V_74 -> V_75 ) ||
( V_27 -> V_76 != V_74 -> V_76 ) )
return V_126 ;
}
}
return V_127 ;
}
static enum V_53
F_43 ( struct V_1 * V_2 , bool V_128 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = F_21 ( V_2 ) ;
enum V_53 V_118 = V_72 ;
int V_129 ;
V_129 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_129 < 0 )
return V_72 ;
if ( V_23 ) {
struct V_46 * V_46 = F_14 ( V_23 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( V_74 -> V_75 >= 320 && V_74 -> V_76 >= 240 )
V_118 = V_62 ;
}
if ( V_8 -> V_35 )
V_118 = V_62 ;
else {
if ( V_8 -> V_123 ) {
V_8 -> V_35 = F_45 ( & V_8 -> V_70 ,
& V_8 -> V_123 -> V_130 ) ;
if ( V_8 -> V_35 )
V_118 = V_62 ;
}
}
F_15 ( V_2 , V_118 ) ;
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_118 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_35 )
F_49 ( V_8 -> V_35 ) ;
F_49 ( V_8 -> V_17 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_49 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
T_1 V_131 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_46 * V_46 ;
enum V_132 V_121 ;
F_24 ( L_8 ) ;
if ( V_88 != V_4 -> V_133 . V_134 )
return 0 ;
if ( V_2 -> V_23 )
V_46 = F_14 ( V_2 -> V_23 ) ;
else {
struct V_42 * V_43 = V_2 -> V_44 ;
V_46 = F_14 ( V_43 -> V_45 ( V_2 ) ) ;
}
switch ( V_131 ) {
case V_135 : V_121 = V_122 ; break;
case V_136 : V_121 = V_137 ; break;
case V_138 : V_121 = V_139 ; break;
default:
case V_140 : V_121 = V_141 ; break;
}
if ( V_46 -> V_121 == V_121 )
return 0 ;
V_46 -> V_121 = V_121 ;
F_8 ( & V_46 -> V_70 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_118 ;
V_118 = F_41 ( V_8 ) ;
return V_118 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_73 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_142 )
return V_143 ;
return V_127 ;
}
static enum V_53
F_55 ( struct V_1 * V_2 , bool V_128 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
struct V_144 * V_145 ;
bool V_146 = false ;
enum V_53 V_118 = V_72 ;
int V_129 ;
V_129 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_129 < 0 )
return V_72 ;
V_23 = F_21 ( V_2 ) ;
if ( ! V_23 )
V_118 = V_72 ;
if ( V_8 -> V_123 )
V_146 = F_56 ( V_8 , false ) ;
if ( V_146 ) {
V_8 -> V_147 = false ;
if ( V_8 -> V_35 ) {
F_49 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
}
V_8 -> V_35 = F_45 ( & V_8 -> V_70 , & V_8 -> V_123 -> V_130 ) ;
if ( ! V_8 -> V_35 ) {
F_57 ( L_9 ,
F_25 ( V_2 ) ) ;
V_118 = V_62 ;
} else {
V_8 -> V_34 = ! ! ( V_8 -> V_35 -> V_148 & V_149 ) ;
if ( V_8 -> V_34 && V_8 -> V_150 ) {
F_49 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
V_118 = V_72 ;
} else
V_118 = V_62 ;
}
} else {
if ( ! V_128 ) {
if ( V_8 -> V_147 )
V_118 = V_2 -> V_54 ;
goto V_151;
}
if ( V_8 -> V_114 && V_23 ) {
V_145 = V_23 -> V_44 ;
V_118 = V_145 -> V_152 ( V_23 , V_2 ) ;
if ( V_118 != V_72 )
V_8 -> V_147 = true ;
}
}
if ( V_118 == V_62 )
V_118 = F_22 ( V_2 , V_23 , V_118 , true ) ;
if ( ( ! V_6 -> V_63 ) &&
( V_118 == V_72 ) &&
V_6 -> V_90 . V_153 ) {
V_118 = V_62 ;
}
F_15 ( V_2 , V_118 ) ;
V_151:
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_118 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_73 * V_154 ;
struct V_22 * V_23 ;
V_23 = F_21 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
if ( V_6 -> V_155 >= V_156 )
F_30 ( V_23 , V_2 ) ;
else {
V_154 = F_29 ( V_4 , 800 , 600 , 60 , false , false , false ) ;
V_154 -> type = V_78 | V_77 ;
F_31 ( V_2 , V_154 ) ;
}
return 1 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_73 * V_27 )
{
if ( ( V_27 -> V_75 > 1024 ) || ( V_27 -> V_76 > 768 ) )
return V_157 ;
return V_127 ;
}
static enum V_53
F_60 ( struct V_1 * V_2 , bool V_128 )
{
struct V_22 * V_23 ;
struct V_144 * V_145 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_53 V_118 = V_72 ;
int V_129 ;
if ( ! V_8 -> V_114 )
return V_118 ;
V_129 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_129 < 0 )
return V_72 ;
V_23 = F_21 ( V_2 ) ;
if ( ! V_23 )
V_118 = V_72 ;
else {
V_145 = V_23 -> V_44 ;
V_118 = V_145 -> V_152 ( V_23 , V_2 ) ;
}
if ( V_118 == V_62 )
V_118 = F_22 ( V_2 , V_23 , V_118 , false ) ;
F_15 ( V_2 , V_118 ) ;
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_118 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_118 ;
V_118 = F_41 ( V_8 ) ;
return V_118 ;
}
static bool F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_53 V_54 ;
if ( V_6 -> V_155 >= V_158
&& V_8 -> V_9 . V_9 != V_10 ) {
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) )
V_54 = V_62 ;
else
V_54 = V_72 ;
if ( V_2 -> V_54 == V_54 )
return true ;
}
return false ;
}
static enum V_53
F_63 ( struct V_1 * V_2 , bool V_128 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = NULL ;
struct V_144 * V_145 ;
struct V_55 * V_56 ;
int V_58 , V_129 ;
enum V_53 V_118 = V_72 ;
bool V_146 = false , V_159 = false ;
V_129 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_129 < 0 )
return V_72 ;
if ( ! V_128 && F_62 ( V_2 ) ) {
V_118 = V_2 -> V_54 ;
goto exit;
}
if ( V_8 -> V_123 )
V_146 = F_56 ( V_8 , false ) ;
if ( V_146 ) {
V_8 -> V_147 = false ;
if ( V_8 -> V_35 ) {
F_49 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
}
V_8 -> V_35 = F_45 ( & V_8 -> V_70 , & V_8 -> V_123 -> V_130 ) ;
if ( ! V_8 -> V_35 ) {
F_57 ( L_9 ,
F_25 ( V_2 ) ) ;
if ( ( V_6 -> V_155 == V_160 || V_6 -> V_155 == V_161 ) && V_8 -> V_70 . V_162 ) {
V_118 = V_72 ;
F_57 ( L_10 , F_25 ( V_2 ) ) ;
V_8 -> V_123 = NULL ;
} else {
V_118 = V_62 ;
V_159 = true ;
}
} else {
V_8 -> V_34 = ! ! ( V_8 -> V_35 -> V_148 & V_149 ) ;
if ( ( ! V_8 -> V_34 ) && V_8 -> V_150 ) {
F_49 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
V_118 = V_72 ;
} else
V_118 = V_62 ;
if ( V_8 -> V_150 && ( V_118 == V_62 ) ) {
struct V_1 * V_163 ;
struct V_8 * V_164 ;
F_23 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_163 )
continue;
V_164 = F_2 ( V_163 ) ;
if ( V_164 -> V_150 &&
( V_164 -> V_123 -> V_165 . V_166 ==
V_8 -> V_123 -> V_165 . V_166 ) ) {
if ( V_163 -> V_13 != V_167 ) {
if ( ! F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_49 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
V_118 = V_72 ;
}
}
}
}
}
}
}
if ( ( V_118 == V_62 ) && ( V_8 -> V_34 == true ) )
goto V_151;
if ( ( V_2 -> V_13 == V_37 ) ||
( V_2 -> V_13 == V_38 ) )
goto V_151;
if ( ! V_128 ) {
if ( V_8 -> V_147 )
V_118 = V_2 -> V_54 ;
goto V_151;
}
if ( V_8 -> V_114 ) {
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_16 ( V_2 -> V_4 ,
V_2 -> V_60 [ V_58 ] ,
V_61 ) ;
if ( ! V_56 )
continue;
V_23 = F_17 ( V_56 ) ;
if ( V_23 -> V_64 != V_107 &&
V_23 -> V_64 != V_106 )
continue;
V_145 = V_23 -> V_44 ;
if ( V_145 -> V_152 ) {
if ( ! V_159 ) {
if ( V_118 != V_62 ) {
V_118 = V_145 -> V_152 ( V_23 , V_2 ) ;
if ( V_118 == V_62 ) {
V_8 -> V_34 = false ;
}
if ( V_118 != V_72 )
V_8 -> V_147 = true ;
}
} else {
enum V_53 V_168 ;
V_8 -> V_34 = true ;
V_168 = V_145 -> V_152 ( V_23 , V_2 ) ;
F_24 ( L_11 , V_23 -> V_64 , V_168 ) ;
if ( V_168 == V_62 )
V_8 -> V_34 = false ;
}
break;
}
}
}
if ( ( V_118 == V_62 ) && ( V_8 -> V_34 == false ) &&
V_23 ) {
V_118 = F_22 ( V_2 , V_23 , V_118 , true ) ;
}
V_151:
if ( ( ! V_6 -> V_63 ) &&
( V_118 == V_72 ) &&
V_6 -> V_90 . V_153 ) {
V_8 -> V_34 = true ;
V_118 = V_62 ;
}
F_15 ( V_2 , V_118 ) ;
exit:
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_118 ;
}
static struct V_22 * F_64 ( struct V_1 * V_2 )
{
int V_65 = V_2 -> V_60 [ 0 ] ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_55 * V_56 ;
struct V_22 * V_23 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_16 ( V_2 -> V_4 , V_2 -> V_60 [ V_58 ] , V_61 ) ;
if ( ! V_56 )
continue;
V_23 = F_17 ( V_56 ) ;
if ( V_8 -> V_34 == true ) {
if ( V_23 -> V_64 == V_93 )
return V_23 ;
} else {
if ( V_23 -> V_64 == V_107 ||
V_23 -> V_64 == V_106 )
return V_23 ;
}
}
if ( V_65 ) {
V_56 = F_16 ( V_2 -> V_4 , V_65 , V_61 ) ;
if ( ! V_56 )
return NULL ;
V_23 = F_17 ( V_56 ) ;
return V_23 ;
}
return NULL ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_2 -> V_128 == V_169 )
V_8 -> V_34 = false ;
if ( V_2 -> V_128 == V_170 )
V_8 -> V_34 = true ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_73 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_34 &&
( V_6 -> V_155 == V_171 ) &&
( V_27 -> clock > 135000 ) )
return V_143 ;
if ( V_8 -> V_34 && ( V_27 -> clock > 165000 ) ) {
if ( ( V_8 -> V_172 == V_173 ) ||
( V_8 -> V_172 == V_174 ) ||
( V_8 -> V_172 == V_175 ) )
return V_127 ;
else if ( V_8 -> V_172 == V_176 ) {
if ( F_67 ( V_6 ) ) {
if ( V_27 -> clock > 340000 )
return V_143 ;
else
return V_127 ;
} else
return V_143 ;
} else
return V_143 ;
}
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_142 )
return V_143 ;
return V_127 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_177 = V_8 -> V_17 ;
if ( V_8 -> V_35 )
F_49 ( V_8 -> V_35 ) ;
if ( V_177 -> V_178 )
F_69 ( V_177 -> V_178 ) ;
F_49 ( V_8 -> V_17 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_49 ( V_2 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_177 = V_8 -> V_17 ;
struct V_22 * V_23 = F_21 ( V_2 ) ;
int V_118 ;
if ( ( V_2 -> V_13 == V_40 ) ||
( V_2 -> V_13 == V_41 ) ) {
struct V_73 * V_27 ;
if ( V_2 -> V_13 == V_40 ) {
if ( ! V_177 -> V_179 )
F_71 ( V_2 ,
V_180 ) ;
V_118 = F_41 ( V_8 ) ;
if ( ! V_177 -> V_179 )
F_71 ( V_2 ,
V_181 ) ;
} else {
if ( F_72 ( V_2 ) !=
V_182 ) {
if ( V_23 )
F_73 ( V_23 ) ;
}
V_118 = F_41 ( V_8 ) ;
}
if ( V_118 > 0 ) {
if ( V_23 ) {
F_37 ( V_23 , V_2 ) ;
F_30 ( V_23 , V_2 ) ;
}
return V_118 ;
}
if ( ! V_23 )
return 0 ;
V_27 = F_26 ( V_23 ) ;
if ( V_27 ) {
V_118 = 1 ;
F_31 ( V_2 , V_27 ) ;
V_2 -> V_36 . V_124 = V_27 -> V_124 ;
V_2 -> V_36 . V_125 = V_27 -> V_125 ;
F_30 ( V_23 , V_2 ) ;
}
} else {
if ( F_72 ( V_2 ) !=
V_182 ) {
if ( V_23 )
F_73 ( V_23 ) ;
}
V_118 = F_41 ( V_8 ) ;
}
return V_118 ;
}
T_2 F_72 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_22 * V_23 ;
struct V_46 * V_46 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_16 ( V_2 -> V_4 , V_2 -> V_60 [ V_58 ] , V_61 ) ;
if ( ! V_56 )
continue;
V_23 = F_17 ( V_56 ) ;
V_46 = F_14 ( V_23 ) ;
switch ( V_46 -> V_183 ) {
case V_184 :
case V_185 :
return V_46 -> V_183 ;
default:
break;
}
}
return V_182 ;
}
bool F_74 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_22 * V_23 ;
struct V_46 * V_46 ;
int V_58 ;
bool V_186 = false ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_2 -> V_60 [ V_58 ] == 0 )
break;
V_56 = F_16 ( V_2 -> V_4 , V_2 -> V_60 [ V_58 ] , V_61 ) ;
if ( ! V_56 )
continue;
V_23 = F_17 ( V_56 ) ;
V_46 = F_14 ( V_23 ) ;
if ( V_46 -> V_187 & V_188 )
V_186 = true ;
}
return V_186 ;
}
bool F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_13 ( V_6 ) &&
( V_6 -> clock . V_189 >= 53900 ) &&
F_74 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_53
F_76 ( struct V_1 * V_2 , bool V_128 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_53 V_118 = V_72 ;
struct V_15 * V_177 = V_8 -> V_17 ;
struct V_22 * V_23 = F_21 ( V_2 ) ;
int V_129 ;
V_129 = F_44 ( V_2 -> V_4 -> V_4 ) ;
if ( V_129 < 0 )
return V_72 ;
if ( ! V_128 && F_62 ( V_2 ) ) {
V_118 = V_2 -> V_54 ;
goto V_151;
}
if ( V_8 -> V_35 ) {
F_49 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
}
if ( ( V_2 -> V_13 == V_40 ) ||
( V_2 -> V_13 == V_41 ) ) {
if ( V_23 ) {
struct V_46 * V_46 = F_14 ( V_23 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( V_74 -> V_75 >= 320 && V_74 -> V_76 >= 240 )
V_118 = V_62 ;
}
V_177 -> V_18 = V_19 ;
if ( ! V_177 -> V_179 )
F_71 ( V_2 ,
V_180 ) ;
if ( F_77 ( V_8 ) )
V_118 = V_62 ;
if ( ! V_177 -> V_179 )
F_71 ( V_2 ,
V_181 ) ;
} else if ( F_72 ( V_2 ) !=
V_182 ) {
V_177 -> V_18 = V_19 ;
F_77 ( V_8 ) ;
if ( V_23 ) {
F_73 ( V_23 ) ;
if ( F_56 ( V_8 , true ) )
V_118 = V_62 ;
else if ( V_8 -> V_114 ) {
struct V_144 * V_145 = V_23 -> V_44 ;
V_118 = V_145 -> V_152 ( V_23 , V_2 ) ;
}
}
} else {
V_177 -> V_18 = F_4 ( V_8 ) ;
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
V_118 = V_62 ;
if ( V_177 -> V_18 == V_19 )
F_77 ( V_8 ) ;
} else {
if ( V_177 -> V_18 == V_19 ) {
if ( F_77 ( V_8 ) )
V_118 = V_62 ;
} else {
if ( F_56 ( V_8 , false ) )
V_118 = V_62 ;
}
}
}
F_15 ( V_2 , V_118 ) ;
V_151:
F_46 ( V_2 -> V_4 -> V_4 ) ;
F_47 ( V_2 -> V_4 -> V_4 ) ;
return V_118 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_73 * V_27 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_177 = V_8 -> V_17 ;
if ( ( V_2 -> V_13 == V_40 ) ||
( V_2 -> V_13 == V_41 ) ) {
struct V_22 * V_23 = F_21 ( V_2 ) ;
if ( ( V_27 -> V_75 < 320 ) || ( V_27 -> V_76 < 240 ) )
return V_126 ;
if ( V_23 ) {
struct V_46 * V_46 = F_14 ( V_23 ) ;
struct V_73 * V_74 = & V_46 -> V_74 ;
if ( ( V_27 -> V_75 > V_74 -> V_75 ) ||
( V_27 -> V_76 > V_74 -> V_76 ) )
return V_126 ;
if ( V_46 -> V_121 == V_122 ) {
if ( ( V_27 -> V_75 != V_74 -> V_75 ) ||
( V_27 -> V_76 != V_74 -> V_76 ) )
return V_126 ;
}
}
return V_127 ;
} else {
if ( ( V_177 -> V_18 == V_19 ) ||
( V_177 -> V_18 == V_39 ) )
return F_79 ( V_2 , V_27 ) ;
else
return V_127 ;
}
}
void
F_80 ( struct V_3 * V_4 ,
T_3 V_190 ,
T_3 V_191 ,
int V_13 ,
struct V_192 * V_193 ,
T_3 V_194 ,
T_4 V_172 ,
struct V_195 * V_9 ,
struct V_196 * V_197 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_15 * V_177 ;
struct V_22 * V_23 ;
struct V_46 * V_46 ;
T_3 V_198 = V_199 ;
bool V_150 = false ;
bool V_200 = false ;
if ( V_13 == V_201 )
return;
if ( ( ( V_13 == V_202 ) ||
( V_13 == V_203 ) ||
( V_13 == V_204 ) ) &&
( V_205 == 0 ) )
return;
F_23 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_190 == V_190 ) {
V_8 -> V_84 |= V_191 ;
return;
}
if ( V_8 -> V_123 && V_193 -> V_206 ) {
if ( V_8 -> V_123 -> V_165 . V_166 == V_193 -> V_166 ) {
V_8 -> V_150 = true ;
V_150 = true ;
}
if ( V_8 -> V_207 && V_197 -> V_208 &&
( V_8 -> V_197 . V_209 == V_197 -> V_209 ) ) {
V_8 -> V_150 = false ;
V_150 = false ;
}
}
}
F_23 (encoder, &dev->mode_config.encoder_list, head) {
V_46 = F_14 ( V_23 ) ;
if ( V_46 -> V_84 & V_191 ) {
switch ( V_46 -> V_183 ) {
case V_184 :
case V_185 :
V_200 = true ;
break;
default:
break;
}
}
}
V_8 = F_81 ( sizeof( struct V_8 ) , V_210 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_70 ;
V_8 -> V_190 = V_190 ;
V_8 -> V_84 = V_191 ;
V_8 -> V_150 = V_150 ;
V_8 -> V_172 = V_172 ;
V_8 -> V_9 = * V_9 ;
V_8 -> V_197 = * V_197 ;
if ( V_197 -> V_208 || V_197 -> V_211 ) {
V_8 -> V_207 = F_82 ( V_6 , & V_197 -> V_212 ) ;
if ( ! V_8 -> V_207 )
F_57 ( L_12 ) ;
}
if ( V_200 ) {
V_177 = F_81 ( sizeof( struct V_15 ) , V_210 ) ;
if ( ! V_177 )
goto V_213;
V_177 -> V_194 = V_194 ;
V_8 -> V_17 = V_177 ;
if ( V_193 -> V_206 ) {
if ( V_13 == V_40 )
V_177 -> V_178 = F_83 ( V_4 , V_193 , L_13 ) ;
else
V_177 -> V_178 = F_83 ( V_4 , V_193 , L_14 ) ;
if ( ! V_177 -> V_178 )
F_57 ( L_15 ) ;
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_16 ) ;
}
switch ( V_13 ) {
case V_167 :
case V_214 :
default:
F_84 ( V_4 , & V_8 -> V_70 ,
& V_215 , V_13 ) ;
F_85 ( & V_8 -> V_70 ,
& V_216 ) ;
V_2 -> V_217 = true ;
V_2 -> V_218 = true ;
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
break;
case V_32 :
case V_37 :
case V_38 :
case V_33 :
case V_14 :
F_84 ( V_4 , & V_8 -> V_70 ,
& V_215 , V_13 ) ;
F_85 ( & V_8 -> V_70 ,
& V_216 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_99 ,
V_219 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_101 ,
0 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_103 ,
0 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_97 ,
V_220 ) ;
if ( V_221 != 0 )
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_95 ,
V_222 ) ;
V_198 = V_223 ;
V_2 -> V_217 = true ;
if ( V_13 == V_33 )
V_2 -> V_218 = true ;
else
V_2 -> V_218 = false ;
if ( V_13 == V_32 ) {
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
}
break;
case V_41 :
case V_40 :
F_84 ( V_4 , & V_8 -> V_70 ,
& V_224 , V_13 ) ;
F_85 ( & V_8 -> V_70 ,
& V_216 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_4 -> V_133 . V_134 ,
V_140 ) ;
V_198 = V_223 ;
V_2 -> V_217 = false ;
V_2 -> V_218 = false ;
break;
}
} else {
switch ( V_13 ) {
case V_167 :
F_84 ( V_4 , & V_8 -> V_70 , & V_225 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_226 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_17 ) ;
}
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_227 = V_228 ;
V_2 -> V_217 = true ;
V_2 -> V_218 = true ;
break;
case V_214 :
F_84 ( V_4 , & V_8 -> V_70 , & V_225 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_226 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_18 ) ;
}
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_217 = true ;
V_2 -> V_218 = true ;
break;
case V_32 :
case V_37 :
V_177 = F_81 ( sizeof( struct V_15 ) , V_210 ) ;
if ( ! V_177 )
goto V_213;
V_177 -> V_194 = V_194 ;
V_8 -> V_17 = V_177 ;
F_84 ( V_4 , & V_8 -> V_70 , & V_229 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_230 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_19 ) ;
}
V_198 = V_223 ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_91 ,
1 ) ;
if ( F_33 ( V_6 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_99 ,
V_219 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_101 ,
0 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_103 ,
0 ) ;
}
if ( F_87 ( V_6 ) && ( V_221 != 0 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_95 ,
V_222 ) ;
}
if ( F_33 ( V_6 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_97 ,
V_220 ) ;
}
if ( V_13 == V_32 ) {
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
}
V_2 -> V_217 = true ;
if ( V_13 == V_32 )
V_2 -> V_218 = true ;
else
V_2 -> V_218 = false ;
break;
case V_38 :
case V_33 :
V_177 = F_81 ( sizeof( struct V_15 ) , V_210 ) ;
if ( ! V_177 )
goto V_213;
V_177 -> V_194 = V_194 ;
V_8 -> V_17 = V_177 ;
F_84 ( V_4 , & V_8 -> V_70 , & V_229 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_230 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_20 ) ;
}
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_91 ,
1 ) ;
if ( F_33 ( V_6 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_99 ,
V_219 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_101 ,
0 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_103 ,
0 ) ;
}
if ( F_87 ( V_6 ) && ( V_221 != 0 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_95 ,
V_222 ) ;
}
if ( F_33 ( V_6 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_97 ,
V_220 ) ;
}
V_198 = V_223 ;
V_2 -> V_217 = true ;
if ( V_13 == V_33 )
V_2 -> V_218 = true ;
else
V_2 -> V_218 = false ;
break;
case V_14 :
V_177 = F_81 ( sizeof( struct V_15 ) , V_210 ) ;
if ( ! V_177 )
goto V_213;
V_177 -> V_194 = V_194 ;
V_8 -> V_17 = V_177 ;
F_84 ( V_4 , & V_8 -> V_70 , & V_215 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_216 ) ;
if ( V_193 -> V_206 ) {
V_177 -> V_178 = F_83 ( V_4 , V_193 , L_14 ) ;
if ( ! V_177 -> V_178 )
F_57 ( L_15 ) ;
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_16 ) ;
}
V_198 = V_223 ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_91 ,
1 ) ;
if ( F_33 ( V_6 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_99 ,
V_219 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_101 ,
0 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_103 ,
0 ) ;
}
if ( F_87 ( V_6 ) && ( V_221 != 0 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_95 ,
V_222 ) ;
}
if ( F_33 ( V_6 ) ) {
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_97 ,
V_220 ) ;
}
V_2 -> V_217 = true ;
V_2 -> V_218 = false ;
break;
case V_40 :
V_177 = F_81 ( sizeof( struct V_15 ) , V_210 ) ;
if ( ! V_177 )
goto V_213;
V_177 -> V_194 = V_194 ;
V_8 -> V_17 = V_177 ;
F_84 ( V_4 , & V_8 -> V_70 , & V_231 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_216 ) ;
if ( V_193 -> V_206 ) {
V_177 -> V_178 = F_83 ( V_4 , V_193 , L_13 ) ;
if ( ! V_177 -> V_178 )
F_57 ( L_15 ) ;
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_16 ) ;
}
F_86 ( & V_8 -> V_70 . V_70 ,
V_4 -> V_133 . V_134 ,
V_140 ) ;
V_198 = V_223 ;
V_2 -> V_217 = false ;
V_2 -> V_218 = false ;
break;
case V_202 :
case V_203 :
case V_204 :
F_84 ( V_4 , & V_8 -> V_70 , & V_232 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_233 ) ;
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_105 ,
F_88 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_217 = false ;
V_2 -> V_218 = false ;
break;
case V_41 :
V_177 = F_81 ( sizeof( struct V_15 ) , V_210 ) ;
if ( ! V_177 )
goto V_213;
V_177 -> V_194 = V_194 ;
V_8 -> V_17 = V_177 ;
F_84 ( V_4 , & V_8 -> V_70 , & V_234 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_235 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_21 ) ;
}
F_86 ( & V_8 -> V_70 . V_70 ,
V_4 -> V_133 . V_134 ,
V_140 ) ;
V_198 = V_223 ;
V_2 -> V_217 = false ;
V_2 -> V_218 = false ;
break;
}
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_193 -> V_206 )
V_2 -> V_227 = V_228 ;
} else
V_2 -> V_227 = V_236 ;
V_2 -> V_36 . V_198 = V_198 ;
F_89 ( V_2 ) ;
return;
V_213:
F_51 ( V_2 ) ;
F_49 ( V_2 ) ;
}
void
F_90 ( struct V_3 * V_4 ,
T_3 V_190 ,
T_3 V_191 ,
int V_13 ,
struct V_192 * V_193 ,
T_4 V_172 ,
struct V_195 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
T_3 V_198 = V_199 ;
if ( V_13 == V_201 )
return;
if ( ( ( V_13 == V_202 ) ||
( V_13 == V_203 ) ||
( V_13 == V_204 ) ) &&
( V_205 == 0 ) )
return;
F_23 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_190 == V_190 ) {
V_8 -> V_84 |= V_191 ;
return;
}
}
V_8 = F_81 ( sizeof( struct V_8 ) , V_210 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_70 ;
V_8 -> V_190 = V_190 ;
V_8 -> V_84 = V_191 ;
V_8 -> V_172 = V_172 ;
V_8 -> V_9 = * V_9 ;
switch ( V_13 ) {
case V_167 :
F_84 ( V_4 , & V_8 -> V_70 , & V_225 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_226 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_17 ) ;
}
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_227 = V_228 ;
V_2 -> V_217 = true ;
V_2 -> V_218 = true ;
break;
case V_214 :
F_84 ( V_4 , & V_8 -> V_70 , & V_225 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_226 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_18 ) ;
}
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_217 = true ;
V_2 -> V_218 = true ;
break;
case V_32 :
case V_37 :
F_84 ( V_4 , & V_8 -> V_70 , & V_229 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_230 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_19 ) ;
}
if ( V_13 == V_32 ) {
V_8 -> V_114 = true ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
1 ) ;
}
V_198 = V_223 ;
V_2 -> V_217 = true ;
if ( V_13 == V_32 )
V_2 -> V_218 = true ;
else
V_2 -> V_218 = false ;
break;
case V_202 :
case V_203 :
case V_204 :
F_84 ( V_4 , & V_8 -> V_70 , & V_232 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_233 ) ;
V_8 -> V_114 = true ;
if ( V_6 -> V_155 == V_237 || V_6 -> V_155 == V_238 )
V_8 -> V_114 = false ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_113 ,
V_8 -> V_114 ) ;
F_86 ( & V_8 -> V_70 . V_70 ,
V_6 -> V_90 . V_105 ,
F_91 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_217 = false ;
V_2 -> V_218 = false ;
break;
case V_41 :
F_84 ( V_4 , & V_8 -> V_70 , & V_234 , V_13 ) ;
F_85 ( & V_8 -> V_70 , & V_235 ) ;
if ( V_193 -> V_206 ) {
V_8 -> V_123 = F_82 ( V_6 , V_193 ) ;
if ( ! V_8 -> V_123 )
F_57 ( L_21 ) ;
}
F_86 ( & V_8 -> V_70 . V_70 ,
V_4 -> V_133 . V_134 ,
V_140 ) ;
V_198 = V_223 ;
V_2 -> V_217 = false ;
V_2 -> V_218 = false ;
break;
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_193 -> V_206 )
V_2 -> V_227 = V_228 ;
} else
V_2 -> V_227 = V_236 ;
V_2 -> V_36 . V_198 = V_198 ;
F_89 ( V_2 ) ;
}
