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
static void
F_9 ( struct V_1 * V_2 , enum V_26 V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_17 * V_28 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_29 * V_30 = V_2 -> V_31 ;
struct V_32 * V_33 ;
bool V_34 ;
int V_35 ;
V_28 = V_30 -> V_28 ( V_2 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( V_2 -> V_37 [ V_35 ] == 0 )
break;
V_33 = F_10 ( V_2 -> V_4 ,
V_2 -> V_37 [ V_35 ] ,
V_38 ) ;
if ( ! V_33 )
continue;
V_18 = F_11 ( V_33 ) ;
if ( ( V_18 == V_28 ) && ( V_27 == V_39 ) )
V_34 = true ;
else
V_34 = false ;
if ( V_6 -> V_40 )
F_12 ( V_2 , V_18 , V_34 ) ;
else
F_13 ( V_2 , V_18 , V_34 ) ;
}
}
struct V_17 * F_14 ( struct V_1 * V_2 , int V_41 )
{
struct V_32 * V_33 ;
struct V_17 * V_18 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( V_2 -> V_37 [ V_35 ] == 0 )
break;
V_33 = F_10 ( V_2 -> V_4 , V_2 -> V_37 [ V_35 ] , V_38 ) ;
if ( ! V_33 )
continue;
V_18 = F_11 ( V_33 ) ;
if ( V_18 -> V_41 == V_41 )
return V_18 ;
}
return NULL ;
}
struct V_17 * F_15 ( struct V_1 * V_2 )
{
int V_42 = V_2 -> V_37 [ 0 ] ;
struct V_32 * V_33 ;
struct V_17 * V_18 ;
if ( V_42 ) {
V_33 = F_10 ( V_2 -> V_4 , V_42 , V_38 ) ;
if ( ! V_33 )
return NULL ;
V_18 = F_11 ( V_33 ) ;
return V_18 ;
}
return NULL ;
}
static enum V_26
F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
enum V_26 V_43 ,
bool V_44 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_45 ;
struct V_8 * V_46 ;
int V_35 ;
F_17 (conflict, &dev->mode_config.connector_list, head) {
if ( V_45 == V_2 )
continue;
V_46 = F_2 ( V_45 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( V_45 -> V_37 [ V_35 ] == 0 )
break;
if ( V_45 -> V_37 [ V_35 ] == V_18 -> V_47 . V_48 ) {
if ( V_45 -> V_27 != V_39 )
continue;
if ( V_46 -> V_49 )
continue;
if ( V_44 == true ) {
F_18 ( L_1 , F_19 ( V_45 ) ) ;
F_18 ( L_2 , F_19 ( V_2 ) ) ;
V_45 -> V_27 = V_50 ;
F_9 ( V_45 , V_50 ) ;
} else {
F_18 ( L_3 , F_19 ( V_2 ) ) ;
F_18 ( L_2 , F_19 ( V_45 ) ) ;
V_43 = V_50 ;
}
break;
}
}
}
return V_43 ;
}
static struct V_51 * F_20 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_4 ;
struct V_52 * V_52 = F_21 ( V_18 ) ;
struct V_51 * V_22 = NULL ;
struct V_51 * V_53 = & V_52 -> V_53 ;
if ( V_53 -> V_54 != 0 &&
V_53 -> V_55 != 0 &&
V_53 -> clock != 0 ) {
V_22 = F_22 ( V_4 , V_53 ) ;
V_22 -> type = V_56 | V_57 ;
F_23 ( V_22 ) ;
F_18 ( L_4 , V_22 -> V_58 ) ;
} else if ( V_53 -> V_54 != 0 &&
V_53 -> V_55 != 0 ) {
V_22 = F_24 ( V_4 , V_53 -> V_54 , V_53 -> V_55 , 60 , true , false , false ) ;
V_22 -> type = V_56 | V_57 ;
F_18 ( L_5 , V_22 -> V_58 ) ;
}
return V_22 ;
}
static void F_25 ( struct V_17 * V_18 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_18 -> V_4 ;
struct V_52 * V_52 = F_21 ( V_18 ) ;
struct V_51 * V_22 = NULL ;
struct V_51 * V_53 = & V_52 -> V_53 ;
int V_35 ;
struct V_59 {
int V_60 ;
int V_61 ;
} V_62 [ 17 ] = {
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
for ( V_35 = 0 ; V_35 < 17 ; V_35 ++ ) {
if ( V_52 -> V_63 & ( V_64 ) ) {
if ( V_62 [ V_35 ] . V_60 > 1024 ||
V_62 [ V_35 ] . V_61 > 768 )
continue;
}
if ( V_52 -> V_63 & ( V_65 ) ) {
if ( V_62 [ V_35 ] . V_60 > V_53 -> V_54 ||
V_62 [ V_35 ] . V_61 > V_53 -> V_55 ||
( V_62 [ V_35 ] . V_60 == V_53 -> V_54 &&
V_62 [ V_35 ] . V_61 == V_53 -> V_55 ) )
continue;
}
if ( V_62 [ V_35 ] . V_60 < 320 || V_62 [ V_35 ] . V_61 < 200 )
continue;
V_22 = F_24 ( V_4 , V_62 [ V_35 ] . V_60 , V_62 [ V_35 ] . V_61 , 60 , false , false , false ) ;
F_26 ( V_2 , V_22 ) ;
}
}
int F_27 ( struct V_1 * V_2 , struct V_66 * V_67 ,
T_1 V_68 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_17 * V_18 ;
struct V_52 * V_52 ;
if ( V_67 == V_6 -> V_69 . V_70 ) {
struct V_71 * V_72 ;
bool V_73 ;
V_18 = F_14 ( V_2 , V_74 ) ;
if ( ! V_18 )
return 0 ;
V_52 = F_21 ( V_18 ) ;
if ( ! V_52 -> V_75 )
return 0 ;
V_72 = V_52 -> V_75 ;
V_73 = V_68 ? true : false ;
if ( V_72 -> V_76 != V_73 ) {
V_72 -> V_76 = V_73 ;
F_7 ( & V_52 -> V_47 ) ;
}
}
if ( V_67 == V_6 -> V_69 . V_77 ) {
V_18 = F_14 ( V_2 , V_74 ) ;
if ( ! V_18 )
return 0 ;
V_52 = F_21 ( V_18 ) ;
if ( V_52 -> V_78 != V_68 ) {
V_52 -> V_78 = V_68 ;
F_7 ( & V_52 -> V_47 ) ;
}
}
if ( V_67 == V_6 -> V_69 . V_79 ) {
V_18 = F_14 ( V_2 , V_74 ) ;
if ( ! V_18 )
return 0 ;
V_52 = F_21 ( V_18 ) ;
if ( V_52 -> V_80 != V_68 ) {
V_52 -> V_80 = V_68 ;
F_7 ( & V_52 -> V_47 ) ;
}
}
if ( V_67 == V_6 -> V_69 . V_81 ) {
V_18 = F_14 ( V_2 , V_74 ) ;
if ( ! V_18 )
return 0 ;
V_52 = F_21 ( V_18 ) ;
if ( V_52 -> V_82 != V_68 ) {
V_52 -> V_82 = V_68 ;
F_7 ( & V_52 -> V_47 ) ;
}
}
if ( V_67 == V_6 -> V_69 . V_83 ) {
V_18 = F_14 ( V_2 , V_84 ) ;
if ( ! V_18 ) {
V_18 = F_14 ( V_2 , V_85 ) ;
}
if ( ! V_18 )
return 0 ;
V_52 = F_21 ( V_18 ) ;
if ( ! V_52 -> V_75 )
return 0 ;
if ( F_28 ( V_6 ) || V_86 ) {
struct V_87 * V_88 ;
V_88 = V_52 -> V_75 ;
V_88 -> V_89 = V_68 ;
} else {
struct V_90 * V_88 ;
V_88 = V_52 -> V_75 ;
V_88 -> V_89 = V_68 ;
}
F_7 ( & V_52 -> V_47 ) ;
}
if ( V_67 == V_6 -> V_69 . V_91 ) {
struct V_8 * V_8 =
F_2 ( V_2 ) ;
if ( V_68 == 0 )
V_8 -> V_92 = false ;
else
V_8 -> V_92 = true ;
}
if ( V_67 == V_6 -> V_69 . V_93 ) {
struct V_94 * V_95 = NULL ;
bool V_96 = false ;
V_18 = F_14 ( V_2 , V_74 ) ;
if ( ! V_18 )
return 0 ;
V_52 = F_21 ( V_18 ) ;
V_95 = V_52 -> V_75 ;
if ( ! V_95 )
return 0 ;
if ( V_68 == 0 ) {
if ( V_6 -> V_40 )
V_96 = F_29 ( V_52 , V_95 ) ;
else
V_96 = F_30 ( V_52 , V_95 ) ;
}
if ( V_68 == 1 || V_96 == false ) {
F_31 ( V_52 , V_95 ) ;
}
F_7 ( & V_52 -> V_47 ) ;
}
return 0 ;
}
static void F_32 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_52 * V_52 = F_21 ( V_18 ) ;
struct V_51 * V_53 = & V_52 -> V_53 ;
struct V_51 * V_97 , * V_22 ;
F_33 (mode, t, &connector->probed_modes, head) {
if ( V_22 -> type & V_56 ) {
if ( V_22 -> V_54 != V_53 -> V_54 ||
V_22 -> V_55 != V_53 -> V_55 )
memcpy ( V_53 , V_22 , sizeof( * V_22 ) ) ;
}
}
if ( ! V_53 -> clock ) {
F_33 (mode, t, &connector->probed_modes, head) {
if ( V_22 -> V_54 == V_53 -> V_54 &&
V_22 -> V_55 == V_53 -> V_55 ) {
* V_53 = * V_22 ;
F_34 ( V_53 , V_98 ) ;
F_18 ( L_6 ) ;
break;
}
}
}
if ( ! V_53 -> clock ) {
F_18 ( L_7 ) ;
V_52 -> V_99 = V_100 ;
}
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_17 * V_18 ;
int V_96 = 0 ;
struct V_51 * V_22 ;
if ( V_8 -> V_101 ) {
V_96 = F_36 ( V_8 ) ;
if ( V_96 > 0 ) {
V_18 = F_15 ( V_2 ) ;
if ( V_18 ) {
F_32 ( V_18 , V_2 ) ;
F_25 ( V_18 , V_2 ) ;
}
return V_96 ;
}
}
V_18 = F_15 ( V_2 ) ;
if ( ! V_18 )
return 0 ;
V_22 = F_20 ( V_18 ) ;
if ( V_22 ) {
V_96 = 1 ;
F_26 ( V_2 , V_22 ) ;
V_2 -> V_102 . V_103 = V_22 -> V_103 ;
V_2 -> V_102 . V_104 = V_22 -> V_104 ;
F_25 ( V_18 , V_2 ) ;
}
return V_96 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_51 * V_22 )
{
struct V_17 * V_18 = F_15 ( V_2 ) ;
if ( ( V_22 -> V_54 < 320 ) || ( V_22 -> V_55 < 240 ) )
return V_105 ;
if ( V_18 ) {
struct V_52 * V_52 = F_21 ( V_18 ) ;
struct V_51 * V_53 = & V_52 -> V_53 ;
if ( ( V_22 -> V_54 > V_53 -> V_54 ) ||
( V_22 -> V_55 > V_53 -> V_55 ) )
return V_105 ;
if ( V_52 -> V_99 == V_100 ) {
if ( ( V_22 -> V_54 != V_53 -> V_54 ) ||
( V_22 -> V_55 != V_53 -> V_55 ) )
return V_105 ;
}
}
return V_106 ;
}
static enum V_26
F_38 ( struct V_1 * V_2 , bool V_107 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_15 ( V_2 ) ;
enum V_26 V_96 = V_50 ;
if ( V_18 ) {
struct V_52 * V_52 = F_21 ( V_18 ) ;
struct V_51 * V_53 = & V_52 -> V_53 ;
if ( V_53 -> V_54 >= 320 && V_53 -> V_55 >= 240 )
V_96 = V_39 ;
}
if ( V_8 -> V_108 )
V_96 = V_39 ;
else {
if ( V_8 -> V_101 ) {
V_8 -> V_108 = F_39 ( & V_8 -> V_47 ,
& V_8 -> V_101 -> V_109 ) ;
if ( V_8 -> V_108 )
V_96 = V_39 ;
}
}
F_9 ( V_2 , V_96 ) ;
return V_96 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_108 )
F_41 ( V_8 -> V_108 ) ;
F_41 ( V_8 -> V_110 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_41 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
T_1 V_111 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_52 * V_52 ;
enum V_112 V_99 ;
F_18 ( L_8 ) ;
if ( V_67 != V_4 -> V_113 . V_114 )
return 0 ;
if ( V_2 -> V_18 )
V_52 = F_21 ( V_2 -> V_18 ) ;
else {
struct V_29 * V_30 = V_2 -> V_31 ;
V_52 = F_21 ( V_30 -> V_28 ( V_2 ) ) ;
}
switch ( V_111 ) {
case V_115 : V_99 = V_100 ; break;
case V_116 : V_99 = V_117 ; break;
case V_118 : V_99 = V_119 ; break;
default:
case V_120 : V_99 = V_121 ; break;
}
if ( V_52 -> V_99 == V_99 )
return 0 ;
V_52 -> V_99 = V_99 ;
F_7 ( & V_52 -> V_47 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_96 ;
V_96 = F_36 ( V_8 ) ;
return V_96 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_51 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_22 -> clock / 10 ) > V_6 -> clock . V_122 )
return V_123 ;
return V_106 ;
}
static enum V_26
F_47 ( struct V_1 * V_2 , bool V_107 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_17 * V_18 ;
struct V_124 * V_125 ;
bool V_126 = false ;
enum V_26 V_96 = V_50 ;
V_18 = F_15 ( V_2 ) ;
if ( ! V_18 )
V_96 = V_50 ;
if ( V_8 -> V_101 )
V_126 = F_48 ( V_8 ) ;
if ( V_126 ) {
V_8 -> V_127 = false ;
if ( V_8 -> V_108 ) {
F_41 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
}
V_8 -> V_108 = F_39 ( & V_8 -> V_47 , & V_8 -> V_101 -> V_109 ) ;
if ( ! V_8 -> V_108 ) {
F_49 ( L_9 ,
F_19 ( V_2 ) ) ;
V_96 = V_39 ;
} else {
V_8 -> V_49 = ! ! ( V_8 -> V_108 -> V_128 & V_129 ) ;
if ( V_8 -> V_49 && V_8 -> V_130 ) {
F_41 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
V_96 = V_50 ;
} else
V_96 = V_39 ;
}
} else {
if ( ! V_107 ) {
if ( V_8 -> V_127 )
return V_2 -> V_27 ;
else
return V_96 ;
}
if ( V_8 -> V_92 && V_18 ) {
V_125 = V_18 -> V_31 ;
V_96 = V_125 -> V_131 ( V_18 , V_2 ) ;
if ( V_96 != V_50 )
V_8 -> V_127 = true ;
}
}
if ( V_96 == V_39 )
V_96 = F_16 ( V_2 , V_18 , V_96 , true ) ;
if ( ( ! V_6 -> V_40 ) &&
( V_96 == V_50 ) &&
V_6 -> V_69 . V_132 ) {
V_96 = V_39 ;
}
F_9 ( V_2 , V_96 ) ;
return V_96 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_133 ;
struct V_17 * V_18 ;
V_18 = F_15 ( V_2 ) ;
if ( ! V_18 )
return 0 ;
if ( V_6 -> V_134 >= V_135 )
F_25 ( V_18 , V_2 ) ;
else {
V_133 = F_24 ( V_4 , 800 , 600 , 60 , false , false , false ) ;
V_133 -> type = V_57 | V_56 ;
F_26 ( V_2 , V_133 ) ;
}
return 1 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_51 * V_22 )
{
if ( ( V_22 -> V_54 > 1024 ) || ( V_22 -> V_55 > 768 ) )
return V_136 ;
return V_106 ;
}
static enum V_26
F_52 ( struct V_1 * V_2 , bool V_107 )
{
struct V_17 * V_18 ;
struct V_124 * V_125 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_26 V_96 = V_50 ;
if ( ! V_8 -> V_92 )
return V_96 ;
V_18 = F_15 ( V_2 ) ;
if ( ! V_18 )
V_96 = V_50 ;
else {
V_125 = V_18 -> V_31 ;
V_96 = V_125 -> V_131 ( V_18 , V_2 ) ;
}
if ( V_96 == V_39 )
V_96 = F_16 ( V_2 , V_18 , V_96 , false ) ;
F_9 ( V_2 , V_96 ) ;
return V_96 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_96 ;
V_96 = F_36 ( V_8 ) ;
return V_96 ;
}
static enum V_26
F_54 ( struct V_1 * V_2 , bool V_107 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_17 * V_18 = NULL ;
struct V_124 * V_125 ;
struct V_32 * V_33 ;
int V_35 ;
enum V_26 V_96 = V_50 ;
bool V_126 = false ;
if ( V_8 -> V_101 )
V_126 = F_48 ( V_8 ) ;
if ( V_126 ) {
V_8 -> V_127 = false ;
if ( V_8 -> V_108 ) {
F_41 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
}
V_8 -> V_108 = F_39 ( & V_8 -> V_47 , & V_8 -> V_101 -> V_109 ) ;
if ( ! V_8 -> V_108 ) {
F_49 ( L_9 ,
F_19 ( V_2 ) ) ;
if ( ( V_6 -> V_134 == V_137 || V_6 -> V_134 == V_138 ) && V_8 -> V_47 . V_139 ) {
V_96 = V_50 ;
F_49 ( L_10 , F_19 ( V_2 ) ) ;
V_8 -> V_101 = NULL ;
}
} else {
V_8 -> V_49 = ! ! ( V_8 -> V_108 -> V_128 & V_129 ) ;
if ( ( ! V_8 -> V_49 ) && V_8 -> V_130 ) {
F_41 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
V_96 = V_50 ;
} else
V_96 = V_39 ;
if ( V_8 -> V_130 && ( V_96 == V_39 ) ) {
struct V_1 * V_140 ;
struct V_8 * V_141 ;
F_17 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_140 )
continue;
V_141 = F_2 ( V_140 ) ;
if ( V_141 -> V_130 &&
( V_141 -> V_101 -> V_142 . V_143 ==
V_8 -> V_101 -> V_142 . V_143 ) ) {
if ( V_140 -> V_13 != V_144 ) {
if ( ! F_4 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_41 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
V_96 = V_50 ;
}
}
}
}
}
}
}
if ( ( V_96 == V_39 ) && ( V_8 -> V_49 == true ) )
goto V_145;
if ( ( V_2 -> V_13 == V_146 ) ||
( V_2 -> V_13 == V_147 ) )
goto V_145;
if ( ! V_107 ) {
if ( V_8 -> V_127 )
V_96 = V_2 -> V_27 ;
goto V_145;
}
if ( V_8 -> V_92 ) {
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( V_2 -> V_37 [ V_35 ] == 0 )
break;
V_33 = F_10 ( V_2 -> V_4 ,
V_2 -> V_37 [ V_35 ] ,
V_38 ) ;
if ( ! V_33 )
continue;
V_18 = F_11 ( V_33 ) ;
V_125 = V_18 -> V_31 ;
if ( V_125 -> V_131 ) {
if ( V_96 != V_39 ) {
V_96 = V_125 -> V_131 ( V_18 , V_2 ) ;
if ( V_96 == V_39 ) {
V_8 -> V_49 = false ;
}
if ( V_96 != V_50 )
V_8 -> V_127 = true ;
}
break;
}
}
}
if ( ( V_96 == V_39 ) && ( V_8 -> V_49 == false ) &&
V_18 ) {
V_96 = F_16 ( V_2 , V_18 , V_96 , true ) ;
}
if ( ( ! V_6 -> V_40 ) &&
( V_96 == V_50 ) &&
V_6 -> V_69 . V_132 ) {
V_8 -> V_49 = true ;
V_96 = V_39 ;
}
V_145:
F_9 ( V_2 , V_96 ) ;
return V_96 ;
}
struct V_17 * F_55 ( struct V_1 * V_2 )
{
int V_42 = V_2 -> V_37 [ 0 ] ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_32 * V_33 ;
struct V_17 * V_18 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( V_2 -> V_37 [ V_35 ] == 0 )
break;
V_33 = F_10 ( V_2 -> V_4 , V_2 -> V_37 [ V_35 ] , V_38 ) ;
if ( ! V_33 )
continue;
V_18 = F_11 ( V_33 ) ;
if ( V_8 -> V_49 == true ) {
if ( V_18 -> V_41 == V_74 )
return V_18 ;
} else {
if ( V_18 -> V_41 == V_85 ||
V_18 -> V_41 == V_84 )
return V_18 ;
}
}
if ( V_42 ) {
V_33 = F_10 ( V_2 -> V_4 , V_42 , V_38 ) ;
if ( ! V_33 )
return NULL ;
V_18 = F_11 ( V_33 ) ;
return V_18 ;
}
return NULL ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_2 -> V_107 == V_148 )
V_8 -> V_49 = false ;
if ( V_2 -> V_107 == V_149 )
V_8 -> V_49 = true ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_51 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_49 &&
( V_6 -> V_134 == V_150 ) &&
( V_22 -> clock > 135000 ) )
return V_123 ;
if ( V_8 -> V_49 && ( V_22 -> clock > 165000 ) ) {
if ( ( V_8 -> V_151 == V_152 ) ||
( V_8 -> V_151 == V_153 ) ||
( V_8 -> V_151 == V_154 ) )
return V_106 ;
else if ( V_8 -> V_151 == V_155 ) {
if ( F_58 ( V_6 ) ) {
if ( V_22 -> clock > 340000 )
return V_123 ;
else
return V_106 ;
} else
return V_123 ;
} else
return V_123 ;
}
if ( ( V_22 -> clock / 10 ) > V_6 -> clock . V_122 )
return V_123 ;
return V_106 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_156 * V_157 = V_8 -> V_110 ;
if ( V_8 -> V_108 )
F_41 ( V_8 -> V_108 ) ;
if ( V_157 -> V_158 )
F_60 ( V_157 -> V_158 ) ;
F_41 ( V_8 -> V_110 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_41 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_156 * V_157 = V_8 -> V_110 ;
struct V_17 * V_18 = F_15 ( V_2 ) ;
int V_96 ;
if ( ( V_2 -> V_13 == V_159 ) ||
( V_2 -> V_13 == V_160 ) ) {
struct V_51 * V_22 ;
if ( ! V_157 -> V_161 )
F_62 ( V_2 ,
V_162 ) ;
V_96 = F_36 ( V_8 ) ;
if ( ! V_157 -> V_161 )
F_62 ( V_2 ,
V_163 ) ;
if ( V_96 > 0 ) {
if ( V_18 ) {
F_32 ( V_18 , V_2 ) ;
F_25 ( V_18 , V_2 ) ;
}
return V_96 ;
}
V_18 = F_15 ( V_2 ) ;
if ( ! V_18 )
return 0 ;
V_22 = F_20 ( V_18 ) ;
if ( V_22 ) {
V_96 = 1 ;
F_26 ( V_2 , V_22 ) ;
V_2 -> V_102 . V_103 = V_22 -> V_103 ;
V_2 -> V_102 . V_104 = V_22 -> V_104 ;
F_25 ( V_18 , V_2 ) ;
}
} else {
if ( F_63 ( V_2 ) !=
V_164 ) {
if ( V_18 )
F_64 ( V_18 ) ;
}
V_96 = F_36 ( V_8 ) ;
}
return V_96 ;
}
T_2 F_63 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_17 * V_18 ;
struct V_52 * V_52 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( V_2 -> V_37 [ V_35 ] == 0 )
break;
V_33 = F_10 ( V_2 -> V_4 , V_2 -> V_37 [ V_35 ] , V_38 ) ;
if ( ! V_33 )
continue;
V_18 = F_11 ( V_33 ) ;
V_52 = F_21 ( V_18 ) ;
switch ( V_52 -> V_165 ) {
case V_166 :
case V_167 :
return V_52 -> V_165 ;
default:
break;
}
}
return V_164 ;
}
bool F_65 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_17 * V_18 ;
struct V_52 * V_52 ;
int V_35 ;
bool V_168 = false ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( V_2 -> V_37 [ V_35 ] == 0 )
break;
V_33 = F_10 ( V_2 -> V_4 , V_2 -> V_37 [ V_35 ] , V_38 ) ;
if ( ! V_33 )
continue;
V_18 = F_11 ( V_33 ) ;
V_52 = F_21 ( V_18 ) ;
if ( V_52 -> V_169 & V_170 )
V_168 = true ;
}
return V_168 ;
}
bool F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_67 ( V_6 ) &&
( V_6 -> clock . V_171 >= 53900 ) &&
F_65 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_26
F_68 ( struct V_1 * V_2 , bool V_107 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_26 V_96 = V_50 ;
struct V_156 * V_157 = V_8 -> V_110 ;
struct V_17 * V_18 = F_15 ( V_2 ) ;
if ( V_8 -> V_108 ) {
F_41 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
}
if ( ( V_2 -> V_13 == V_159 ) ||
( V_2 -> V_13 == V_160 ) ) {
if ( V_18 ) {
struct V_52 * V_52 = F_21 ( V_18 ) ;
struct V_51 * V_53 = & V_52 -> V_53 ;
if ( V_53 -> V_54 >= 320 && V_53 -> V_55 >= 240 )
V_96 = V_39 ;
}
V_157 -> V_172 = V_173 ;
if ( ! V_157 -> V_161 )
F_62 ( V_2 ,
V_162 ) ;
if ( F_69 ( V_8 ) )
V_96 = V_39 ;
if ( ! V_157 -> V_161 )
F_62 ( V_2 ,
V_163 ) ;
} else if ( F_63 ( V_2 ) !=
V_164 ) {
V_157 -> V_172 = V_173 ;
F_69 ( V_8 ) ;
if ( V_18 ) {
F_64 ( V_18 ) ;
if ( F_48 ( V_8 ) )
V_96 = V_39 ;
else if ( V_8 -> V_92 ) {
struct V_124 * V_125 = V_18 -> V_31 ;
V_96 = V_125 -> V_131 ( V_18 , V_2 ) ;
}
}
} else {
V_157 -> V_172 = F_70 ( V_8 ) ;
if ( F_4 ( V_6 , V_8 -> V_9 . V_9 ) ) {
V_96 = V_39 ;
if ( V_157 -> V_172 == V_173 )
F_69 ( V_8 ) ;
} else {
if ( V_157 -> V_172 == V_173 ) {
if ( F_69 ( V_8 ) )
V_96 = V_39 ;
} else {
if ( F_48 ( V_8 ) )
V_96 = V_39 ;
}
}
}
F_9 ( V_2 , V_96 ) ;
return V_96 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_51 * V_22 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_156 * V_157 = V_8 -> V_110 ;
if ( ( V_2 -> V_13 == V_159 ) ||
( V_2 -> V_13 == V_160 ) ) {
struct V_17 * V_18 = F_15 ( V_2 ) ;
if ( ( V_22 -> V_54 < 320 ) || ( V_22 -> V_55 < 240 ) )
return V_105 ;
if ( V_18 ) {
struct V_52 * V_52 = F_21 ( V_18 ) ;
struct V_51 * V_53 = & V_52 -> V_53 ;
if ( ( V_22 -> V_54 > V_53 -> V_54 ) ||
( V_22 -> V_55 > V_53 -> V_55 ) )
return V_105 ;
if ( V_52 -> V_99 == V_100 ) {
if ( ( V_22 -> V_54 != V_53 -> V_54 ) ||
( V_22 -> V_55 != V_53 -> V_55 ) )
return V_105 ;
}
}
return V_106 ;
} else {
if ( ( V_157 -> V_172 == V_173 ) ||
( V_157 -> V_172 == V_174 ) )
return F_72 ( V_2 , V_22 ) ;
else
return V_106 ;
}
}
void
F_73 ( struct V_3 * V_4 ,
T_3 V_175 ,
T_3 V_176 ,
int V_13 ,
struct V_177 * V_178 ,
T_3 V_179 ,
T_4 V_151 ,
struct V_180 * V_9 ,
struct V_181 * V_182 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_156 * V_157 ;
struct V_17 * V_18 ;
struct V_52 * V_52 ;
T_3 V_183 = V_184 ;
bool V_130 = false ;
bool V_185 = false ;
if ( V_13 == V_186 )
return;
if ( ( ( V_13 == V_187 ) ||
( V_13 == V_188 ) ||
( V_13 == V_189 ) ) &&
( V_190 == 0 ) )
return;
F_17 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_175 == V_175 ) {
V_8 -> V_63 |= V_176 ;
return;
}
if ( V_8 -> V_101 && V_178 -> V_191 ) {
if ( V_8 -> V_101 -> V_142 . V_143 == V_178 -> V_143 ) {
V_8 -> V_130 = true ;
V_130 = true ;
}
if ( V_8 -> V_192 && V_182 -> V_193 &&
( V_8 -> V_182 . V_194 == V_182 -> V_194 ) ) {
V_8 -> V_130 = false ;
V_130 = false ;
}
}
}
F_17 (encoder, &dev->mode_config.encoder_list, head) {
V_52 = F_21 ( V_18 ) ;
if ( V_52 -> V_63 & V_176 ) {
switch ( V_52 -> V_165 ) {
case V_166 :
case V_167 :
V_185 = true ;
break;
default:
break;
}
}
}
V_8 = F_74 ( sizeof( struct V_8 ) , V_195 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_47 ;
V_8 -> V_175 = V_175 ;
V_8 -> V_63 = V_176 ;
V_8 -> V_130 = V_130 ;
V_8 -> V_151 = V_151 ;
V_8 -> V_9 = * V_9 ;
V_8 -> V_182 = * V_182 ;
if ( V_182 -> V_193 || V_182 -> V_196 ) {
V_8 -> V_192 = F_75 ( V_6 , & V_182 -> V_197 ) ;
if ( ! V_8 -> V_192 )
F_49 ( L_11 ) ;
}
if ( V_185 ) {
V_157 = F_74 ( sizeof( struct V_156 ) , V_195 ) ;
if ( ! V_157 )
goto V_198;
V_157 -> V_179 = V_179 ;
V_8 -> V_110 = V_157 ;
F_76 ( V_4 , & V_8 -> V_47 , & V_199 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_200 ) ;
if ( V_178 -> V_191 ) {
if ( V_13 == V_159 )
V_157 -> V_158 = F_78 ( V_4 , V_178 , L_12 ) ;
else
V_157 -> V_158 = F_78 ( V_4 , V_178 , L_13 ) ;
if ( ! V_157 -> V_158 )
F_49 ( L_14 ) ;
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_15 ) ;
}
switch ( V_13 ) {
case V_144 :
case V_201 :
default:
V_2 -> V_202 = true ;
V_2 -> V_203 = true ;
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
break;
case V_204 :
case V_146 :
case V_147 :
case V_205 :
case V_14 :
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_77 ,
V_206 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_79 ,
0 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_81 ,
0 ) ;
V_183 = V_207 ;
V_2 -> V_202 = true ;
if ( V_13 == V_205 )
V_2 -> V_203 = true ;
else
V_2 -> V_203 = false ;
if ( V_13 == V_204 ) {
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
}
break;
case V_160 :
case V_159 :
F_79 ( & V_8 -> V_47 ,
V_4 -> V_113 . V_114 ,
V_120 ) ;
V_183 = V_207 ;
V_2 -> V_202 = false ;
V_2 -> V_203 = false ;
break;
}
} else {
switch ( V_13 ) {
case V_144 :
F_76 ( V_4 , & V_8 -> V_47 , & V_208 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_209 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_16 ) ;
}
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_210 = V_211 ;
V_2 -> V_202 = true ;
V_2 -> V_203 = true ;
break;
case V_201 :
F_76 ( V_4 , & V_8 -> V_47 , & V_208 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_209 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_17 ) ;
}
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_202 = true ;
V_2 -> V_203 = true ;
break;
case V_204 :
case V_146 :
V_157 = F_74 ( sizeof( struct V_156 ) , V_195 ) ;
if ( ! V_157 )
goto V_198;
V_157 -> V_179 = V_179 ;
V_8 -> V_110 = V_157 ;
F_76 ( V_4 , & V_8 -> V_47 , & V_212 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_213 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_18 ) ;
}
V_183 = V_207 ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_70 ,
1 ) ;
if ( F_28 ( V_6 ) ) {
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_77 ,
V_206 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_79 ,
0 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_81 ,
0 ) ;
}
if ( V_13 == V_204 ) {
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
}
V_2 -> V_202 = true ;
if ( V_13 == V_204 )
V_2 -> V_203 = true ;
else
V_2 -> V_203 = false ;
break;
case V_147 :
case V_205 :
V_157 = F_74 ( sizeof( struct V_156 ) , V_195 ) ;
if ( ! V_157 )
goto V_198;
V_157 -> V_179 = V_179 ;
V_8 -> V_110 = V_157 ;
F_76 ( V_4 , & V_8 -> V_47 , & V_212 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_213 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_19 ) ;
}
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_70 ,
1 ) ;
if ( F_28 ( V_6 ) ) {
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_77 ,
V_206 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_79 ,
0 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_81 ,
0 ) ;
}
V_183 = V_207 ;
V_2 -> V_202 = true ;
if ( V_13 == V_205 )
V_2 -> V_203 = true ;
else
V_2 -> V_203 = false ;
break;
case V_14 :
V_157 = F_74 ( sizeof( struct V_156 ) , V_195 ) ;
if ( ! V_157 )
goto V_198;
V_157 -> V_179 = V_179 ;
V_8 -> V_110 = V_157 ;
F_76 ( V_4 , & V_8 -> V_47 , & V_199 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_200 ) ;
if ( V_178 -> V_191 ) {
V_157 -> V_158 = F_78 ( V_4 , V_178 , L_13 ) ;
if ( ! V_157 -> V_158 )
F_49 ( L_14 ) ;
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_15 ) ;
}
V_183 = V_207 ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_70 ,
1 ) ;
if ( F_28 ( V_6 ) ) {
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_77 ,
V_206 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_79 ,
0 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_81 ,
0 ) ;
}
V_2 -> V_202 = true ;
V_2 -> V_203 = false ;
break;
case V_159 :
V_157 = F_74 ( sizeof( struct V_156 ) , V_195 ) ;
if ( ! V_157 )
goto V_198;
V_157 -> V_179 = V_179 ;
V_8 -> V_110 = V_157 ;
F_76 ( V_4 , & V_8 -> V_47 , & V_199 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_200 ) ;
if ( V_178 -> V_191 ) {
V_157 -> V_158 = F_78 ( V_4 , V_178 , L_12 ) ;
if ( ! V_157 -> V_158 )
F_49 ( L_14 ) ;
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_15 ) ;
}
F_79 ( & V_8 -> V_47 ,
V_4 -> V_113 . V_114 ,
V_120 ) ;
V_183 = V_207 ;
V_2 -> V_202 = false ;
V_2 -> V_203 = false ;
break;
case V_187 :
case V_188 :
case V_189 :
F_76 ( V_4 , & V_8 -> V_47 , & V_214 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_215 ) ;
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_83 ,
F_80 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_202 = false ;
V_2 -> V_203 = false ;
break;
case V_160 :
V_157 = F_74 ( sizeof( struct V_156 ) , V_195 ) ;
if ( ! V_157 )
goto V_198;
V_157 -> V_179 = V_179 ;
V_8 -> V_110 = V_157 ;
F_76 ( V_4 , & V_8 -> V_47 , & V_216 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_217 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_20 ) ;
}
F_79 ( & V_8 -> V_47 ,
V_4 -> V_113 . V_114 ,
V_120 ) ;
V_183 = V_207 ;
V_2 -> V_202 = false ;
V_2 -> V_203 = false ;
break;
}
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_178 -> V_191 )
V_2 -> V_210 = V_211 ;
} else
V_2 -> V_210 = V_218 ;
V_2 -> V_102 . V_183 = V_183 ;
F_81 ( V_2 ) ;
return;
V_198:
F_43 ( V_2 ) ;
F_41 ( V_2 ) ;
}
void
F_82 ( struct V_3 * V_4 ,
T_3 V_175 ,
T_3 V_176 ,
int V_13 ,
struct V_177 * V_178 ,
T_4 V_151 ,
struct V_180 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
T_3 V_183 = V_184 ;
if ( V_13 == V_186 )
return;
if ( ( ( V_13 == V_187 ) ||
( V_13 == V_188 ) ||
( V_13 == V_189 ) ) &&
( V_190 == 0 ) )
return;
F_17 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_175 == V_175 ) {
V_8 -> V_63 |= V_176 ;
return;
}
}
V_8 = F_74 ( sizeof( struct V_8 ) , V_195 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_47 ;
V_8 -> V_175 = V_175 ;
V_8 -> V_63 = V_176 ;
V_8 -> V_151 = V_151 ;
V_8 -> V_9 = * V_9 ;
switch ( V_13 ) {
case V_144 :
F_76 ( V_4 , & V_8 -> V_47 , & V_208 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_209 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_16 ) ;
}
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_210 = V_211 ;
V_2 -> V_202 = true ;
V_2 -> V_203 = true ;
break;
case V_201 :
F_76 ( V_4 , & V_8 -> V_47 , & V_208 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_209 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_17 ) ;
}
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_202 = true ;
V_2 -> V_203 = true ;
break;
case V_204 :
case V_146 :
F_76 ( V_4 , & V_8 -> V_47 , & V_212 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_213 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_18 ) ;
}
if ( V_13 == V_204 ) {
V_8 -> V_92 = true ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
1 ) ;
}
V_183 = V_207 ;
V_2 -> V_202 = true ;
if ( V_13 == V_204 )
V_2 -> V_203 = true ;
else
V_2 -> V_203 = false ;
break;
case V_187 :
case V_188 :
case V_189 :
F_76 ( V_4 , & V_8 -> V_47 , & V_214 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_215 ) ;
V_8 -> V_92 = true ;
if ( V_6 -> V_134 == V_219 || V_6 -> V_134 == V_220 )
V_8 -> V_92 = false ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_91 ,
V_8 -> V_92 ) ;
F_79 ( & V_8 -> V_47 ,
V_6 -> V_69 . V_83 ,
F_83 ( V_6 ) ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_202 = false ;
V_2 -> V_203 = false ;
break;
case V_160 :
F_76 ( V_4 , & V_8 -> V_47 , & V_216 , V_13 ) ;
F_77 ( & V_8 -> V_47 , & V_217 ) ;
if ( V_178 -> V_191 ) {
V_8 -> V_101 = F_75 ( V_6 , V_178 ) ;
if ( ! V_8 -> V_101 )
F_49 ( L_20 ) ;
}
F_79 ( & V_8 -> V_47 ,
V_4 -> V_113 . V_114 ,
V_120 ) ;
V_183 = V_207 ;
V_2 -> V_202 = false ;
V_2 -> V_203 = false ;
break;
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_178 -> V_191 )
V_2 -> V_210 = V_211 ;
} else
V_2 -> V_210 = V_218 ;
V_2 -> V_102 . V_183 = V_183 ;
F_81 ( V_2 ) ;
if ( V_13 == V_160 ) {
struct V_17 * V_17 ;
F_17 (drm_encoder, &dev->mode_config.encoder_list, head) {
struct V_52 * V_52 ;
V_52 = F_21 ( V_17 ) ;
if ( V_52 -> V_165 == V_221 )
F_84 ( V_52 , V_2 ) ;
}
}
}
