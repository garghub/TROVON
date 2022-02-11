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
if ( F_8 ( V_8 ) )
return;
V_2 -> V_11 = V_21 ;
F_6 ( V_2 , V_12 ) ;
}
V_2 -> V_11 = V_20 ;
}
}
}
static void F_9 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_25 ;
if ( V_25 && V_25 -> V_26 ) {
F_10 ( V_25 , & V_25 -> V_27 ,
V_25 -> V_28 , V_25 -> V_29 , V_25 -> V_30 -> V_31 ) ;
}
}
int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_16 ;
int V_32 = 8 ;
unsigned V_33 , V_34 ;
switch ( V_2 -> V_13 ) {
case V_35 :
case V_36 :
if ( V_8 -> V_37 ) {
if ( F_12 ( F_13 ( V_2 ) ) ) {
if ( V_2 -> V_38 . V_32 )
V_32 = V_2 -> V_38 . V_32 ;
}
}
break;
case V_39 :
case V_40 :
if ( F_12 ( F_13 ( V_2 ) ) ) {
if ( V_2 -> V_38 . V_32 )
V_32 = V_2 -> V_38 . V_32 ;
}
break;
case V_14 :
V_16 = V_8 -> V_17 ;
if ( ( V_16 -> V_18 == V_19 ) ||
( V_16 -> V_18 == V_41 ) ||
F_12 ( F_13 ( V_2 ) ) ) {
if ( V_2 -> V_38 . V_32 )
V_32 = V_2 -> V_38 . V_32 ;
}
break;
case V_42 :
case V_43 :
if ( V_2 -> V_38 . V_32 )
V_32 = V_2 -> V_38 . V_32 ;
else {
const struct V_44 * V_45 =
V_2 -> V_46 ;
struct V_22 * V_23 = V_45 -> V_47 ( V_2 ) ;
struct V_48 * V_48 = F_14 ( V_23 ) ;
struct V_49 * V_50 = V_48 -> V_51 ;
if ( V_50 -> V_52 & V_53 )
V_32 = 6 ;
else if ( V_50 -> V_52 & V_54 )
V_32 = 8 ;
}
break;
}
if ( F_12 ( F_13 ( V_2 ) ) ) {
if ( V_32 > 12 ) {
F_15 ( L_1 ,
V_2 -> V_55 , V_32 ) ;
V_32 = 12 ;
}
if ( V_2 -> V_34 > 0 ) {
V_33 = V_8 -> V_56 ;
V_34 = V_2 -> V_34 * 1000 ;
F_15 ( L_2 ,
V_2 -> V_55 , V_33 , V_34 ) ;
if ( ( V_32 == 12 ) && ( V_33 * 3 / 2 > V_34 ) ) {
if ( ( V_2 -> V_38 . V_57 & V_58 ) &&
( V_33 * 5 / 4 <= V_34 ) )
V_32 = 10 ;
else
V_32 = 8 ;
F_15 ( L_3 ,
V_2 -> V_55 , V_32 ) ;
}
if ( ( V_32 == 10 ) && ( V_33 * 5 / 4 > V_34 ) ) {
V_32 = 8 ;
F_15 ( L_4 ,
V_2 -> V_55 , V_32 ) ;
}
} else if ( V_32 > 8 ) {
F_15 ( L_5 ,
V_2 -> V_55 ) ;
V_32 = 8 ;
}
}
if ( ( V_59 == 0 ) && ( V_32 > 8 ) ) {
F_15 ( L_6 ,
V_2 -> V_55 ) ;
V_32 = 8 ;
}
F_15 ( L_7 ,
V_2 -> V_55 , V_2 -> V_38 . V_32 , V_32 ) ;
return V_32 ;
}
static void
F_16 ( struct V_1 * V_2 ,
enum V_60 V_61 )
{
struct V_22 * V_47 = NULL ;
struct V_22 * V_23 = NULL ;
const struct V_44 * V_45 = V_2 -> V_46 ;
bool V_62 ;
int V_63 ;
V_47 = V_45 -> V_47 ( V_2 ) ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_17 ( V_2 -> V_4 ,
V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( ( V_23 == V_47 ) && ( V_61 == V_66 ) )
V_62 = true ;
else
V_62 = false ;
F_18 ( V_2 , V_23 , V_62 ) ;
}
}
static struct V_22 *
F_19 ( struct V_1 * V_2 ,
int V_67 )
{
struct V_22 * V_23 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_17 ( V_2 -> V_4 ,
V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( V_23 -> V_67 == V_67 )
return V_23 ;
}
return NULL ;
}
struct V_68 * F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_69 * V_70 = V_2 -> V_71 ;
if ( V_8 -> V_68 ) {
return V_8 -> V_68 ;
} else if ( V_70 ) {
struct V_68 * V_68 = F_20 ( V_70 -> V_72 , V_70 -> V_73 , V_74 ) ;
if ( V_68 )
V_8 -> V_68 = V_68 ;
}
return V_8 -> V_68 ;
}
static struct V_68 *
F_21 ( struct V_5 * V_6 )
{
struct V_68 * V_68 ;
if ( V_6 -> V_75 . V_76 ) {
V_68 = F_22 ( V_6 -> V_75 . V_77 , V_74 ) ;
if ( V_68 ) {
memcpy ( ( unsigned char * ) V_68 ,
( unsigned char * ) V_6 -> V_75 . V_76 ,
V_6 -> V_75 . V_77 ) ;
return V_68 ;
}
}
return NULL ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_68 )
return;
if ( V_8 -> V_78 . V_79 )
F_24 ( V_8 ) ;
if ( ( F_25 ( V_2 ) !=
V_80 ) &&
V_8 -> V_81 -> V_82 ) {
V_8 -> V_68 = F_26 ( V_2 ,
& V_8 -> V_81 -> V_83 . V_84 ) ;
} else if ( ( V_2 -> V_13 == V_14 ) ||
( V_2 -> V_13 == V_42 ) ) {
struct V_15 * V_50 = V_8 -> V_17 ;
if ( ( V_50 -> V_18 == V_19 ||
V_50 -> V_18 == V_41 ) &&
V_8 -> V_81 -> V_82 )
V_8 -> V_68 = F_26 ( V_2 ,
& V_8 -> V_81 -> V_83 . V_84 ) ;
else if ( V_8 -> V_81 )
V_8 -> V_68 = F_26 ( V_2 ,
& V_8 -> V_81 -> V_85 ) ;
} else if ( V_8 -> V_81 ) {
V_8 -> V_68 = F_26 ( V_2 ,
& V_8 -> V_81 -> V_85 ) ;
}
if ( ! V_8 -> V_68 ) {
if ( ( ( V_2 -> V_13 == V_43 ) ||
( V_2 -> V_13 == V_42 ) ) )
V_8 -> V_68 = F_21 ( V_6 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_68 ) {
F_28 ( V_8 -> V_68 ) ;
V_8 -> V_68 = NULL ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_86 ;
if ( V_8 -> V_68 ) {
F_30 ( V_2 , V_8 -> V_68 ) ;
V_86 = F_31 ( V_2 , V_8 -> V_68 ) ;
F_32 ( V_2 , V_8 -> V_68 ) ;
return V_86 ;
}
F_30 ( V_2 , NULL ) ;
return 0 ;
}
static struct V_22 *
F_33 ( struct V_1 * V_2 )
{
int V_87 = V_2 -> V_65 [ 0 ] ;
if ( V_87 )
return F_17 ( V_2 -> V_4 , V_87 ) ;
return NULL ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_33 ( V_2 ) ;
struct V_48 * V_48 ;
if ( V_23 == NULL )
return;
V_48 = F_14 ( V_23 ) ;
if ( ! F_35 ( & V_2 -> V_88 ) ) {
struct V_89 * V_90 =
F_36 ( & V_2 -> V_88 ,
struct V_89 , V_91 ) ;
V_48 -> V_92 = * V_90 ;
} else {
V_48 -> V_92 . clock = 0 ;
}
}
static struct V_89 *
F_37 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_48 * V_48 = F_14 ( V_23 ) ;
struct V_89 * V_27 = NULL ;
struct V_89 * V_92 = & V_48 -> V_92 ;
if ( V_92 -> V_93 != 0 &&
V_92 -> V_94 != 0 &&
V_92 -> clock != 0 ) {
V_27 = F_38 ( V_4 , V_92 ) ;
V_27 -> type = V_95 | V_96 ;
F_39 ( V_27 ) ;
F_40 ( L_8 , V_27 -> V_55 ) ;
} else if ( V_92 -> V_93 != 0 &&
V_92 -> V_94 != 0 ) {
V_27 = F_41 ( V_4 , V_92 -> V_93 , V_92 -> V_94 , 60 , true , false , false ) ;
V_27 -> type = V_95 | V_96 ;
F_40 ( L_9 , V_27 -> V_55 ) ;
}
return V_27 ;
}
static void F_42 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_48 * V_48 = F_14 ( V_23 ) ;
struct V_89 * V_27 = NULL ;
struct V_89 * V_92 = & V_48 -> V_92 ;
int V_63 ;
static const struct V_97 {
int V_98 ;
int V_99 ;
} V_100 [ 17 ] = {
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
if ( V_48 -> V_101 & ( V_102 ) ) {
if ( V_100 [ V_63 ] . V_98 > 1024 ||
V_100 [ V_63 ] . V_99 > 768 )
continue;
}
if ( V_48 -> V_101 & ( V_103 ) ) {
if ( V_100 [ V_63 ] . V_98 > V_92 -> V_93 ||
V_100 [ V_63 ] . V_99 > V_92 -> V_94 ||
( V_100 [ V_63 ] . V_98 == V_92 -> V_93 &&
V_100 [ V_63 ] . V_99 == V_92 -> V_94 ) )
continue;
}
if ( V_100 [ V_63 ] . V_98 < 320 || V_100 [ V_63 ] . V_99 < 200 )
continue;
V_27 = F_41 ( V_4 , V_100 [ V_63 ] . V_98 , V_100 [ V_63 ] . V_99 , 60 , false , false , false ) ;
F_43 ( V_2 , V_27 ) ;
}
}
static int F_44 ( struct V_1 * V_2 ,
struct V_104 * V_105 ,
T_1 V_106 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_23 ;
struct V_48 * V_48 ;
if ( V_105 == V_6 -> V_75 . V_107 ) {
struct V_49 * V_50 ;
bool V_108 ;
V_23 = F_19 ( V_2 , V_109 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_14 ( V_23 ) ;
if ( ! V_48 -> V_51 )
return 0 ;
V_50 = V_48 -> V_51 ;
V_108 = V_106 ? true : false ;
if ( V_50 -> V_110 != V_108 ) {
V_50 -> V_110 = V_108 ;
F_9 ( & V_48 -> V_111 ) ;
}
}
if ( V_105 == V_6 -> V_75 . V_112 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_19 ( V_2 , V_109 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_14 ( V_23 ) ;
if ( V_8 -> V_113 != V_106 ) {
V_8 -> V_113 = V_106 ;
F_9 ( & V_48 -> V_111 ) ;
}
}
if ( V_105 == V_6 -> V_75 . V_114 ) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
V_23 = F_19 ( V_2 , V_109 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_14 ( V_23 ) ;
if ( V_8 -> V_115 != V_106 ) {
V_8 -> V_115 = V_106 ;
F_9 ( & V_48 -> V_111 ) ;
}
}
if ( V_105 == V_6 -> V_75 . V_116 ) {
V_23 = F_19 ( V_2 , V_109 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_14 ( V_23 ) ;
if ( V_48 -> V_117 != V_106 ) {
V_48 -> V_117 = V_106 ;
F_9 ( & V_48 -> V_111 ) ;
}
}
if ( V_105 == V_6 -> V_75 . V_118 ) {
V_23 = F_19 ( V_2 , V_109 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_14 ( V_23 ) ;
if ( V_48 -> V_119 != V_106 ) {
V_48 -> V_119 = V_106 ;
F_9 ( & V_48 -> V_111 ) ;
}
}
if ( V_105 == V_6 -> V_75 . V_120 ) {
V_23 = F_19 ( V_2 , V_109 ) ;
if ( ! V_23 )
return 0 ;
V_48 = F_14 ( V_23 ) ;
if ( V_48 -> V_121 != V_106 ) {
V_48 -> V_121 = V_106 ;
F_9 ( & V_48 -> V_111 ) ;
}
}
if ( V_105 == V_6 -> V_75 . V_122 ) {
struct V_8 * V_8 =
F_2 ( V_2 ) ;
if ( V_106 == 0 )
V_8 -> V_123 = false ;
else
V_8 -> V_123 = true ;
}
if ( V_105 == V_4 -> V_124 . V_125 ) {
enum V_126 V_127 ;
if ( V_2 -> V_23 ) {
V_48 = F_14 ( V_2 -> V_23 ) ;
} else {
const struct V_44 * V_45 = V_2 -> V_46 ;
V_48 = F_14 ( V_45 -> V_47 ( V_2 ) ) ;
}
switch ( V_106 ) {
default:
case V_128 : V_127 = V_129 ; break;
case V_130 : V_127 = V_131 ; break;
case V_132 : V_127 = V_133 ; break;
case V_134 : V_127 = V_135 ; break;
}
if ( V_48 -> V_127 == V_127 )
return 0 ;
if ( ( V_127 != V_128 ) &&
( V_48 -> V_92 . clock == 0 ) )
return 0 ;
V_48 -> V_127 = V_127 ;
F_9 ( & V_48 -> V_111 ) ;
}
return 0 ;
}
static void
F_45 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_48 * V_48 = F_14 ( V_23 ) ;
struct V_89 * V_92 = & V_48 -> V_92 ;
struct V_89 * V_136 , * V_27 ;
F_46 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> type & V_95 ) {
if ( V_27 -> V_93 != V_92 -> V_93 ||
V_27 -> V_94 != V_92 -> V_94 )
memcpy ( V_92 , V_27 , sizeof( * V_27 ) ) ;
}
}
if ( ! V_92 -> clock ) {
F_46 (mode, t, &connector->probed_modes, head) {
if ( V_27 -> V_93 == V_92 -> V_93 &&
V_27 -> V_94 == V_92 -> V_94 ) {
* V_92 = * V_27 ;
F_47 ( V_92 , V_137 ) ;
F_40 ( L_10 ) ;
break;
}
}
}
if ( ! V_92 -> clock ) {
F_40 ( L_11 ) ;
V_48 -> V_127 = V_129 ;
}
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_86 = 0 ;
struct V_89 * V_27 ;
F_23 ( V_2 ) ;
V_86 = F_29 ( V_2 ) ;
if ( V_86 > 0 ) {
V_23 = F_33 ( V_2 ) ;
if ( V_23 ) {
F_45 ( V_23 , V_2 ) ;
F_42 ( V_23 , V_2 ) ;
}
return V_86 ;
}
V_23 = F_33 ( V_2 ) ;
if ( ! V_23 )
return 0 ;
V_27 = F_37 ( V_23 ) ;
if ( V_27 ) {
V_86 = 1 ;
F_43 ( V_2 , V_27 ) ;
V_2 -> V_38 . V_138 = V_27 -> V_138 ;
V_2 -> V_38 . V_139 = V_27 -> V_139 ;
F_42 ( V_23 , V_2 ) ;
}
return V_86 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_89 * V_27 )
{
struct V_22 * V_23 = F_33 ( V_2 ) ;
if ( ( V_27 -> V_93 < 320 ) || ( V_27 -> V_94 < 240 ) )
return V_140 ;
if ( V_23 ) {
struct V_48 * V_48 = F_14 ( V_23 ) ;
struct V_89 * V_92 = & V_48 -> V_92 ;
if ( ( V_27 -> V_93 > V_92 -> V_93 ) ||
( V_27 -> V_94 > V_92 -> V_94 ) )
return V_140 ;
if ( V_48 -> V_127 == V_129 ) {
if ( ( V_27 -> V_93 != V_92 -> V_93 ) ||
( V_27 -> V_94 != V_92 -> V_94 ) )
return V_140 ;
}
}
return V_141 ;
}
static enum V_60
F_50 ( struct V_1 * V_2 , bool V_142 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = F_33 ( V_2 ) ;
enum V_60 V_86 = V_143 ;
int V_144 ;
V_144 = F_51 ( V_2 -> V_4 -> V_4 ) ;
if ( V_144 < 0 )
return V_143 ;
if ( V_23 ) {
struct V_48 * V_48 = F_14 ( V_23 ) ;
struct V_89 * V_92 = & V_48 -> V_92 ;
if ( V_92 -> V_93 >= 320 && V_92 -> V_94 >= 240 )
V_86 = V_66 ;
}
F_23 ( V_2 ) ;
if ( V_8 -> V_68 )
V_86 = V_66 ;
F_16 ( V_2 , V_86 ) ;
F_52 ( V_2 -> V_4 -> V_4 ) ;
F_53 ( V_2 -> V_4 -> V_4 ) ;
return V_86 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_81 -> V_82 )
F_55 ( & V_8 -> V_81 -> V_83 ) ;
F_27 ( V_2 ) ;
F_28 ( V_8 -> V_17 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_28 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_104 * V_105 ,
T_1 V_145 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_48 * V_48 ;
enum V_126 V_127 ;
F_40 ( L_12 ) ;
if ( V_105 != V_4 -> V_124 . V_125 )
return 0 ;
if ( V_2 -> V_23 )
V_48 = F_14 ( V_2 -> V_23 ) ;
else {
const struct V_44 * V_45 = V_2 -> V_46 ;
V_48 = F_14 ( V_45 -> V_47 ( V_2 ) ) ;
}
switch ( V_145 ) {
case V_128 : V_127 = V_129 ; break;
case V_130 : V_127 = V_131 ; break;
case V_132 : V_127 = V_133 ; break;
default:
case V_134 : V_127 = V_135 ; break;
}
if ( V_48 -> V_127 == V_127 )
return 0 ;
V_48 -> V_127 = V_127 ;
F_9 ( & V_48 -> V_111 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_86 ;
F_23 ( V_2 ) ;
V_86 = F_29 ( V_2 ) ;
return V_86 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_89 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_146 )
return V_147 ;
return V_141 ;
}
static enum V_60
F_61 ( struct V_1 * V_2 , bool V_142 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
const struct V_148 * V_149 ;
bool V_150 = false ;
enum V_60 V_86 = V_143 ;
int V_144 ;
V_144 = F_51 ( V_2 -> V_4 -> V_4 ) ;
if ( V_144 < 0 )
return V_143 ;
V_23 = F_33 ( V_2 ) ;
if ( ! V_23 )
V_86 = V_143 ;
if ( V_8 -> V_81 )
V_150 = F_62 ( V_8 , false ) ;
if ( V_150 ) {
V_8 -> V_151 = false ;
F_27 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( ! V_8 -> V_68 ) {
F_63 ( L_13 ,
V_2 -> V_55 ) ;
V_86 = V_66 ;
} else {
V_8 -> V_37 =
! ! ( V_8 -> V_68 -> V_152 & V_153 ) ;
if ( V_8 -> V_37 && V_8 -> V_154 ) {
F_27 ( V_2 ) ;
V_86 = V_143 ;
} else {
V_86 = V_66 ;
}
}
} else {
if ( ! V_142 ) {
if ( V_8 -> V_151 )
V_86 = V_2 -> V_61 ;
goto V_155;
}
if ( V_8 -> V_123 && V_23 ) {
V_149 = V_23 -> V_46 ;
V_86 = V_149 -> V_156 ( V_23 , V_2 ) ;
if ( V_86 != V_143 )
V_8 -> V_151 = true ;
}
}
F_16 ( V_2 , V_86 ) ;
V_155:
F_52 ( V_2 -> V_4 -> V_4 ) ;
F_53 ( V_2 -> V_4 -> V_4 ) ;
return V_86 ;
}
static bool
F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_60 V_61 ;
if ( V_8 -> V_9 . V_9 != V_10 ) {
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) )
V_61 = V_66 ;
else
V_61 = V_143 ;
if ( V_2 -> V_61 == V_61 )
return true ;
}
return false ;
}
static enum V_60
F_65 ( struct V_1 * V_2 , bool V_142 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = NULL ;
const struct V_148 * V_149 ;
int V_63 , V_144 ;
enum V_60 V_86 = V_143 ;
bool V_150 = false , V_157 = false ;
V_144 = F_51 ( V_2 -> V_4 -> V_4 ) ;
if ( V_144 < 0 )
return V_143 ;
if ( ! V_142 && F_64 ( V_2 ) ) {
V_86 = V_2 -> V_61 ;
goto exit;
}
if ( V_8 -> V_81 )
V_150 = F_62 ( V_8 , false ) ;
if ( V_150 ) {
V_8 -> V_151 = false ;
F_27 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( ! V_8 -> V_68 ) {
F_63 ( L_13 ,
V_2 -> V_55 ) ;
V_86 = V_66 ;
V_157 = true ;
} else {
V_8 -> V_37 =
! ! ( V_8 -> V_68 -> V_152 & V_153 ) ;
if ( ( ! V_8 -> V_37 ) && V_8 -> V_154 ) {
F_27 ( V_2 ) ;
V_86 = V_143 ;
} else {
V_86 = V_66 ;
}
if ( V_8 -> V_154 && ( V_86 == V_66 ) ) {
struct V_1 * V_158 ;
struct V_8 * V_159 ;
F_66 (list_connector, &dev->mode_config.connector_list, head) {
if ( V_2 == V_158 )
continue;
V_159 = F_2 ( V_158 ) ;
if ( V_159 -> V_154 &&
( V_159 -> V_81 -> V_160 . V_161 ==
V_8 -> V_81 -> V_160 . V_161 ) ) {
if ( V_158 -> V_13 != V_162 ) {
if ( ! F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
F_27 ( V_2 ) ;
V_86 = V_143 ;
}
}
}
}
}
}
}
if ( ( V_86 == V_66 ) && ( V_8 -> V_37 == true ) )
goto V_155;
if ( ( V_2 -> V_13 == V_39 ) ||
( V_2 -> V_13 == V_40 ) )
goto V_155;
if ( ! V_142 ) {
if ( V_8 -> V_151 )
V_86 = V_2 -> V_61 ;
goto V_155;
}
if ( V_8 -> V_123 ) {
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_17 ( V_2 -> V_4 , V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( V_23 -> V_67 != V_163 &&
V_23 -> V_67 != V_164 )
continue;
V_149 = V_23 -> V_46 ;
if ( V_149 -> V_156 ) {
if ( ! V_157 ) {
if ( V_86 != V_66 ) {
V_86 = V_149 -> V_156 ( V_23 , V_2 ) ;
if ( V_86 == V_66 ) {
V_8 -> V_37 = false ;
}
if ( V_86 != V_143 )
V_8 -> V_151 = true ;
}
} else {
enum V_60 V_165 ;
V_8 -> V_37 = true ;
V_165 = V_149 -> V_156 ( V_23 , V_2 ) ;
F_40 ( L_14 , V_23 -> V_67 , V_165 ) ;
if ( V_165 == V_66 )
V_8 -> V_37 = false ;
}
break;
}
}
}
V_155:
F_16 ( V_2 , V_86 ) ;
exit:
F_52 ( V_2 -> V_4 -> V_4 ) ;
F_53 ( V_2 -> V_4 -> V_4 ) ;
return V_86 ;
}
static struct V_22 *
F_67 ( struct V_1 * V_2 )
{
int V_87 = V_2 -> V_65 [ 0 ] ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_17 ( V_2 -> V_4 , V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
if ( V_8 -> V_37 == true ) {
if ( V_23 -> V_67 == V_109 )
return V_23 ;
} else {
if ( V_23 -> V_67 == V_163 ||
V_23 -> V_67 == V_164 )
return V_23 ;
}
}
if ( V_87 )
return F_17 ( V_2 -> V_4 , V_87 ) ;
return NULL ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_2 -> V_142 == V_166 )
V_8 -> V_37 = false ;
if ( V_2 -> V_142 == V_167 )
V_8 -> V_37 = true ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_89 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_37 && ( V_27 -> clock > 165000 ) ) {
if ( ( V_8 -> V_168 == V_169 ) ||
( V_8 -> V_168 == V_170 ) ||
( V_8 -> V_168 == V_171 ) ) {
return V_141 ;
} else if ( F_12 ( F_13 ( V_2 ) ) ) {
if ( V_27 -> clock > 340000 )
return V_147 ;
else
return V_141 ;
} else {
return V_147 ;
}
}
if ( ( V_27 -> clock / 10 ) > V_6 -> clock . V_146 )
return V_147 ;
return V_141 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_172 = V_8 -> V_17 ;
struct V_22 * V_23 = F_33 ( V_2 ) ;
int V_86 ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
struct V_89 * V_27 ;
if ( V_2 -> V_13 == V_42 ) {
if ( ! V_172 -> V_173 )
F_71 ( V_2 ,
V_174 ) ;
F_23 ( V_2 ) ;
V_86 = F_29 ( V_2 ) ;
if ( ! V_172 -> V_173 )
F_71 ( V_2 ,
V_175 ) ;
} else {
if ( F_25 ( V_2 ) !=
V_80 ) {
if ( V_23 )
F_72 ( V_23 ) ;
}
F_23 ( V_2 ) ;
V_86 = F_29 ( V_2 ) ;
}
if ( V_86 > 0 ) {
if ( V_23 ) {
F_45 ( V_23 , V_2 ) ;
F_42 ( V_23 , V_2 ) ;
}
return V_86 ;
}
if ( ! V_23 )
return 0 ;
V_27 = F_37 ( V_23 ) ;
if ( V_27 ) {
V_86 = 1 ;
F_43 ( V_2 , V_27 ) ;
V_2 -> V_38 . V_138 = V_27 -> V_138 ;
V_2 -> V_38 . V_139 = V_27 -> V_139 ;
F_42 ( V_23 , V_2 ) ;
}
} else {
if ( F_25 ( V_2 ) !=
V_80 ) {
if ( V_23 )
F_72 ( V_23 ) ;
}
F_23 ( V_2 ) ;
V_86 = F_29 ( V_2 ) ;
F_34 ( V_2 ) ;
}
return V_86 ;
}
T_2 F_25 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_48 * V_48 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_17 ( V_2 -> V_4 ,
V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
V_48 = F_14 ( V_23 ) ;
switch ( V_48 -> V_176 ) {
case V_177 :
case V_178 :
return V_48 -> V_176 ;
default:
break;
}
}
return V_80 ;
}
static bool F_73 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_48 * V_48 ;
int V_63 ;
bool V_179 = false ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] == 0 )
break;
V_23 = F_17 ( V_2 -> V_4 ,
V_2 -> V_65 [ V_63 ] ) ;
if ( ! V_23 )
continue;
V_48 = F_14 ( V_23 ) ;
if ( V_48 -> V_180 & V_181 )
V_179 = true ;
}
return V_179 ;
}
bool F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( V_6 -> clock . V_182 >= 53900 ) &&
F_73 ( V_2 ) ) {
return true ;
}
return false ;
}
static enum V_60
F_75 ( struct V_1 * V_2 , bool V_142 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
enum V_60 V_86 = V_143 ;
struct V_15 * V_172 = V_8 -> V_17 ;
struct V_22 * V_23 = F_33 ( V_2 ) ;
int V_144 ;
V_144 = F_51 ( V_2 -> V_4 -> V_4 ) ;
if ( V_144 < 0 )
return V_143 ;
if ( ! V_142 && F_64 ( V_2 ) ) {
V_86 = V_2 -> V_61 ;
goto V_155;
}
F_27 ( V_2 ) ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
if ( V_23 ) {
struct V_48 * V_48 = F_14 ( V_23 ) ;
struct V_89 * V_92 = & V_48 -> V_92 ;
if ( V_92 -> V_93 >= 320 && V_92 -> V_94 >= 240 )
V_86 = V_66 ;
}
V_172 -> V_18 = V_19 ;
if ( ! V_172 -> V_173 )
F_71 ( V_2 ,
V_174 ) ;
if ( ! F_8 ( V_8 ) )
V_86 = V_66 ;
if ( ! V_172 -> V_173 )
F_71 ( V_2 ,
V_175 ) ;
} else if ( F_25 ( V_2 ) !=
V_80 ) {
V_172 -> V_18 = V_19 ;
F_8 ( V_8 ) ;
if ( V_23 ) {
F_72 ( V_23 ) ;
if ( F_62 ( V_8 , true ) )
V_86 = V_66 ;
else if ( V_8 -> V_123 ) {
const struct V_148 * V_149 = V_23 -> V_46 ;
V_86 = V_149 -> V_156 ( V_23 , V_2 ) ;
}
}
} else {
V_172 -> V_18 =
F_4 ( V_8 ) ;
if ( F_5 ( V_6 , V_8 -> V_9 . V_9 ) ) {
V_86 = V_66 ;
if ( V_172 -> V_18 == V_19 )
F_8 ( V_8 ) ;
} else {
if ( V_172 -> V_18 == V_19 ) {
if ( ! F_8 ( V_8 ) )
V_86 = V_66 ;
} else {
if ( F_62 ( V_8 , false ) )
V_86 = V_66 ;
}
}
}
F_16 ( V_2 , V_86 ) ;
V_155:
F_52 ( V_2 -> V_4 -> V_4 ) ;
F_53 ( V_2 -> V_4 -> V_4 ) ;
return V_86 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_89 * V_27 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_15 * V_172 = V_8 -> V_17 ;
if ( ( V_2 -> V_13 == V_42 ) ||
( V_2 -> V_13 == V_43 ) ) {
struct V_22 * V_23 = F_33 ( V_2 ) ;
if ( ( V_27 -> V_93 < 320 ) || ( V_27 -> V_94 < 240 ) )
return V_140 ;
if ( V_23 ) {
struct V_48 * V_48 = F_14 ( V_23 ) ;
struct V_89 * V_92 = & V_48 -> V_92 ;
if ( ( V_27 -> V_93 > V_92 -> V_93 ) ||
( V_27 -> V_94 > V_92 -> V_94 ) )
return V_140 ;
if ( V_48 -> V_127 == V_129 ) {
if ( ( V_27 -> V_93 != V_92 -> V_93 ) ||
( V_27 -> V_94 != V_92 -> V_94 ) )
return V_140 ;
}
}
return V_141 ;
} else {
if ( ( V_172 -> V_18 == V_19 ) ||
( V_172 -> V_18 == V_41 ) ) {
return F_77 ( V_2 , V_27 ) ;
} else {
if ( F_12 ( F_13 ( V_2 ) ) ) {
if ( V_27 -> clock > 340000 )
return V_147 ;
} else {
if ( V_27 -> clock > 165000 )
return V_147 ;
}
}
}
return V_141 ;
}
void
F_78 ( struct V_5 * V_6 ,
T_3 V_183 ,
T_3 V_184 ,
int V_13 ,
struct V_185 * V_186 ,
T_4 V_168 ,
struct V_187 * V_9 ,
struct V_188 * V_78 )
{
struct V_3 * V_4 = V_6 -> V_189 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_15 * V_172 ;
struct V_22 * V_23 ;
struct V_48 * V_48 ;
T_3 V_190 = V_191 ;
bool V_154 = false ;
bool V_192 = false ;
bool V_82 = false ;
if ( V_13 == V_193 )
return;
F_66 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_183 == V_183 ) {
V_8 -> V_101 |= V_184 ;
return;
}
if ( V_8 -> V_81 && V_186 -> V_194 ) {
if ( V_8 -> V_81 -> V_160 . V_161 == V_186 -> V_161 ) {
V_8 -> V_154 = true ;
V_154 = true ;
}
if ( V_8 -> V_195 && V_78 -> V_79 &&
( V_8 -> V_78 . V_196 == V_78 -> V_196 ) ) {
V_8 -> V_154 = false ;
V_154 = false ;
}
}
}
F_66 (encoder, &dev->mode_config.encoder_list, head) {
V_48 = F_14 ( V_23 ) ;
if ( V_48 -> V_101 & V_184 ) {
switch ( V_48 -> V_176 ) {
case V_177 :
case V_178 :
V_192 = true ;
break;
default:
break;
}
}
}
V_8 = F_79 ( sizeof( struct V_8 ) , V_74 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_111 ;
V_8 -> V_183 = V_183 ;
V_8 -> V_101 = V_184 ;
V_8 -> V_154 = V_154 ;
V_8 -> V_168 = V_168 ;
V_8 -> V_9 = * V_9 ;
V_8 -> V_78 = * V_78 ;
if ( V_78 -> V_79 || V_78 -> V_197 ) {
V_8 -> V_195 = F_80 ( V_6 , & V_78 -> V_198 ) ;
if ( ! V_8 -> V_195 )
F_63 ( L_15 ) ;
}
if ( V_192 ) {
V_172 = F_79 ( sizeof( struct V_15 ) , V_74 ) ;
if ( ! V_172 )
goto V_199;
V_8 -> V_17 = V_172 ;
if ( V_186 -> V_194 ) {
V_8 -> V_81 = F_80 ( V_6 , V_186 ) ;
if ( V_8 -> V_81 )
V_82 = true ;
else
F_63 ( L_16 ) ;
}
switch ( V_13 ) {
case V_162 :
case V_200 :
default:
F_81 ( V_4 , & V_8 -> V_111 ,
& V_201 , V_13 ) ;
F_82 ( & V_8 -> V_111 ,
& V_202 ) ;
V_2 -> V_203 = true ;
V_2 -> V_204 = true ;
V_8 -> V_123 = true ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_122 ,
1 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_128 ) ;
break;
case V_35 :
case V_39 :
case V_40 :
case V_36 :
case V_14 :
F_81 ( V_4 , & V_8 -> V_111 ,
& V_201 , V_13 ) ;
F_82 ( & V_8 -> V_111 ,
& V_202 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_116 ,
V_205 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_118 ,
0 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_120 ,
0 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_128 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_114 ,
V_206 ) ;
if ( V_207 != 0 )
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_112 ,
V_208 ) ;
V_190 = V_209 ;
V_2 -> V_203 = true ;
if ( V_13 == V_36 )
V_2 -> V_204 = true ;
else
V_2 -> V_204 = false ;
if ( V_13 == V_35 ) {
V_8 -> V_123 = true ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_122 ,
1 ) ;
}
break;
case V_43 :
case V_42 :
F_81 ( V_4 , & V_8 -> V_111 ,
& V_210 , V_13 ) ;
F_82 ( & V_8 -> V_111 ,
& V_202 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_134 ) ;
V_190 = V_209 ;
V_2 -> V_203 = false ;
V_2 -> V_204 = false ;
break;
}
} else {
switch ( V_13 ) {
case V_162 :
F_81 ( V_4 , & V_8 -> V_111 , & V_211 , V_13 ) ;
F_82 ( & V_8 -> V_111 , & V_212 ) ;
if ( V_186 -> V_194 ) {
V_8 -> V_81 = F_80 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_81 )
F_63 ( L_17 ) ;
}
V_8 -> V_123 = true ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_122 ,
1 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_128 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_203 = true ;
V_2 -> V_204 = true ;
break;
case V_200 :
F_81 ( V_4 , & V_8 -> V_111 , & V_211 , V_13 ) ;
F_82 ( & V_8 -> V_111 , & V_212 ) ;
if ( V_186 -> V_194 ) {
V_8 -> V_81 = F_80 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_81 )
F_63 ( L_18 ) ;
}
V_8 -> V_123 = true ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_122 ,
1 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_128 ) ;
V_8 -> V_9 . V_9 = V_10 ;
V_2 -> V_203 = true ;
V_2 -> V_204 = true ;
break;
case V_35 :
case V_39 :
V_172 = F_79 ( sizeof( struct V_15 ) , V_74 ) ;
if ( ! V_172 )
goto V_199;
V_8 -> V_17 = V_172 ;
F_81 ( V_4 , & V_8 -> V_111 , & V_213 , V_13 ) ;
F_82 ( & V_8 -> V_111 , & V_214 ) ;
if ( V_186 -> V_194 ) {
V_8 -> V_81 = F_80 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_81 )
F_63 ( L_19 ) ;
}
V_190 = V_209 ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_107 ,
1 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_116 ,
V_205 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_118 ,
0 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_120 ,
0 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_128 ) ;
if ( V_207 != 0 ) {
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_112 ,
V_208 ) ;
}
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_114 ,
V_206 ) ;
if ( V_13 == V_35 ) {
V_8 -> V_123 = true ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_122 ,
1 ) ;
}
V_2 -> V_203 = true ;
if ( V_13 == V_35 )
V_2 -> V_204 = true ;
else
V_2 -> V_204 = false ;
break;
case V_40 :
case V_36 :
V_172 = F_79 ( sizeof( struct V_15 ) , V_74 ) ;
if ( ! V_172 )
goto V_199;
V_8 -> V_17 = V_172 ;
F_81 ( V_4 , & V_8 -> V_111 , & V_213 , V_13 ) ;
F_82 ( & V_8 -> V_111 , & V_214 ) ;
if ( V_186 -> V_194 ) {
V_8 -> V_81 = F_80 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_81 )
F_63 ( L_20 ) ;
}
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_107 ,
1 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_116 ,
V_205 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_118 ,
0 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_120 ,
0 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_128 ) ;
if ( V_207 != 0 ) {
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_112 ,
V_208 ) ;
}
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_114 ,
V_206 ) ;
V_190 = V_209 ;
V_2 -> V_203 = true ;
if ( V_13 == V_36 )
V_2 -> V_204 = true ;
else
V_2 -> V_204 = false ;
break;
case V_14 :
V_172 = F_79 ( sizeof( struct V_15 ) , V_74 ) ;
if ( ! V_172 )
goto V_199;
V_8 -> V_17 = V_172 ;
F_81 ( V_4 , & V_8 -> V_111 , & V_201 , V_13 ) ;
F_82 ( & V_8 -> V_111 , & V_202 ) ;
if ( V_186 -> V_194 ) {
V_8 -> V_81 = F_80 ( V_6 , V_186 ) ;
if ( V_8 -> V_81 )
V_82 = true ;
else
F_63 ( L_16 ) ;
}
V_190 = V_209 ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_107 ,
1 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_116 ,
V_205 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_118 ,
0 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_120 ,
0 ) ;
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_128 ) ;
if ( V_207 != 0 ) {
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_112 ,
V_208 ) ;
}
F_83 ( & V_8 -> V_111 . V_111 ,
V_6 -> V_75 . V_114 ,
V_206 ) ;
V_2 -> V_203 = true ;
V_2 -> V_204 = false ;
break;
case V_42 :
V_172 = F_79 ( sizeof( struct V_15 ) , V_74 ) ;
if ( ! V_172 )
goto V_199;
V_8 -> V_17 = V_172 ;
F_81 ( V_4 , & V_8 -> V_111 , & V_210 , V_13 ) ;
F_82 ( & V_8 -> V_111 , & V_202 ) ;
if ( V_186 -> V_194 ) {
V_8 -> V_81 = F_80 ( V_6 , V_186 ) ;
if ( V_8 -> V_81 )
V_82 = true ;
else
F_63 ( L_16 ) ;
}
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_134 ) ;
V_190 = V_209 ;
V_2 -> V_203 = false ;
V_2 -> V_204 = false ;
break;
case V_43 :
V_172 = F_79 ( sizeof( struct V_15 ) , V_74 ) ;
if ( ! V_172 )
goto V_199;
V_8 -> V_17 = V_172 ;
F_81 ( V_4 , & V_8 -> V_111 , & V_215 , V_13 ) ;
F_82 ( & V_8 -> V_111 , & V_216 ) ;
if ( V_186 -> V_194 ) {
V_8 -> V_81 = F_80 ( V_6 , V_186 ) ;
if ( ! V_8 -> V_81 )
F_63 ( L_21 ) ;
}
F_83 ( & V_8 -> V_111 . V_111 ,
V_4 -> V_124 . V_125 ,
V_134 ) ;
V_190 = V_209 ;
V_2 -> V_203 = false ;
V_2 -> V_204 = false ;
break;
}
}
if ( V_8 -> V_9 . V_9 == V_10 ) {
if ( V_186 -> V_194 ) {
V_2 -> V_217 = V_218 |
V_219 ;
}
} else
V_2 -> V_217 = V_220 ;
V_2 -> V_38 . V_190 = V_190 ;
F_84 ( V_2 ) ;
if ( V_82 )
F_85 ( V_8 ) ;
return;
V_199:
F_57 ( V_2 ) ;
F_28 ( V_2 ) ;
}
