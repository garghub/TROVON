static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 && V_2 -> V_4 ;
}
void F_2 ( struct V_5 * V_6 , unsigned V_7 )
{
if ( V_6 -> V_8 &&
V_7 > V_6 -> V_8 -> V_7 ) {
F_3 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
}
if ( ! V_6 -> V_8 ) {
V_6 -> V_8 = F_4 (
sizeof( struct V_9 ) +
sizeof( struct V_1 ) * V_7 , V_10 ) ;
if ( ! V_6 -> V_8 ) {
F_5 ( V_6 ,
L_1 ,
V_11 , V_7 ) ;
return;
}
}
V_6 -> V_8 -> V_7 = V_7 ;
}
static int F_6 ( struct V_5 * V_6 )
{
int V_12 ;
int V_13 ;
T_1 V_14 ;
V_13 = V_6 -> V_15 -> V_8 . V_7 ;
V_14 = F_7 ( 0 , ( const V_16 * ) & V_6 -> V_15 -> V_8 ,
sizeof( V_6 -> V_15 -> V_8 ) ) ;
if ( V_14 != V_6 -> V_15 -> V_17 ) {
F_5 ( V_6 , L_2 , V_14 ,
sizeof( V_6 -> V_15 -> V_8 ) ,
V_6 -> V_15 -> V_17 ) ;
return 1 ;
}
if ( V_13 > V_6 -> V_18 -> V_19 ) {
F_8 ( L_3 ,
V_6 -> V_18 -> V_19 , V_13 ) ;
V_13 = V_6 -> V_18 -> V_19 ;
} else {
V_13 = V_6 -> V_15 -> V_8 . V_7 ;
}
F_2 ( V_6 , V_13 ) ;
V_6 -> V_8 -> V_19 =
V_6 -> V_18 -> V_19 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_8 -> V_7 ; ++ V_12 ) {
struct V_20 * V_21 =
& V_6 -> V_15 -> V_8 . V_22 [ V_12 ] ;
struct V_1 * V_23 =
& V_6 -> V_8 -> V_22 [ V_12 ] ;
V_23 -> V_24 = V_21 -> V_25 ;
V_23 -> V_26 = V_21 -> V_27 ;
V_23 -> V_3 = V_21 -> V_28 - V_21 -> V_25 ;
V_23 -> V_4 = V_21 -> V_29 - V_21 -> V_27 ;
V_23 -> V_30 = 0 ;
V_23 -> V_31 = V_12 ;
V_23 -> V_32 = 0 ;
F_8 ( L_4 , V_23 -> V_3 , V_23 -> V_4 ,
V_23 -> V_24 , V_23 -> V_26 ) ;
}
return 0 ;
}
void F_9 ( struct V_5 * V_6 )
{
while ( F_6 ( V_6 ) ) {
F_5 ( V_6 , L_5
L_6 ) ;
}
if ( ! F_10 ( V_6 -> V_33 ) ) {
F_11 ( V_6 -> V_33 ) ;
}
}
static int F_12 ( struct V_34 * V_35 ,
unsigned * V_36 ,
unsigned * V_37 )
{
struct V_38 * V_39 = V_35 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_41 * V_42 = F_13 ( V_35 ) ;
int V_43 = V_42 -> V_44 ;
struct V_45 * V_46 = NULL ;
struct V_1 * V_2 ;
if ( ! V_6 -> V_8 )
return 0 ;
V_2 = & V_6 -> V_8 -> V_22 [ V_43 ] ;
V_46 = F_14 ( V_39 , V_2 -> V_3 , V_2 -> V_4 , 60 , false , false ,
false ) ;
V_46 -> type |= V_47 ;
* V_36 = V_2 -> V_3 ;
* V_37 = V_2 -> V_4 ;
F_15 ( V_35 , V_46 ) ;
return 1 ;
}
static int F_16 ( struct V_34 * V_35 ,
unsigned V_36 ,
unsigned V_37 )
{
struct V_38 * V_39 = V_35 -> V_39 ;
struct V_45 * V_46 = NULL ;
int V_12 ;
struct V_48 {
int V_49 ;
int V_43 ;
} V_50 [] = {
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
for ( V_12 = 0 ; V_12 < F_17 ( V_50 ) ; V_12 ++ ) {
V_46 = F_14 ( V_39 , V_50 [ V_12 ] . V_49 , V_50 [ V_12 ] . V_43 ,
60 , false , false , false ) ;
if ( V_50 [ V_12 ] . V_49 == V_36 && V_50 [ V_12 ] . V_43 == V_37 )
V_46 -> type |= V_47 ;
F_15 ( V_35 , V_46 ) ;
}
return V_12 - 1 ;
}
static void F_18 ( struct V_51 * V_52 )
{
struct V_53 * V_53 = F_19 ( V_52 ) ;
F_20 ( V_52 ) ;
F_3 ( V_53 ) ;
}
static int
F_21 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
int V_58 ;
V_58 = F_22 ( V_6 , sizeof( * V_57 ) , V_59 ,
& V_55 , NULL ) ;
if ( V_58 )
return V_58 ;
V_58 = F_23 ( V_55 , true ) ;
if ( V_58 ) {
F_24 ( V_6 , V_55 ) ;
return V_58 ;
}
V_57 = (struct V_56 * ) F_25 ( V_6 , V_55 ) ;
V_57 -> type = V_60 ;
F_26 ( V_6 , V_55 , & V_57 -> V_61 ) ;
F_27 ( V_6 , V_55 , V_62 , false ) ;
F_28 ( V_55 ) ;
return 0 ;
}
static int F_29 ( struct V_51 * V_52 ,
struct V_63 * V_64 ,
T_1 V_65 ,
T_1 V_3 ,
T_1 V_4 , T_2 V_66 , T_2 V_67 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_53 * V_68 = F_19 ( V_52 ) ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
struct V_56 * V_57 ;
struct V_73 * V_74 , * V_75 ;
struct V_54 * V_55 ;
void * V_76 ;
int V_77 = 64 * 64 * 4 ;
int V_58 = 0 ;
if ( ! V_65 )
return F_21 ( V_6 ) ;
V_70 = F_30 ( V_52 -> V_39 , V_64 , V_65 ) ;
if ( ! V_70 ) {
F_31 ( L_7 ) ;
return - V_78 ;
}
V_75 = F_32 ( V_70 ) ;
V_58 = F_33 ( V_75 , false ) ;
if ( V_58 )
goto V_79;
V_58 = F_34 ( V_75 , V_80 , NULL ) ;
F_35 ( V_75 ) ;
if ( V_58 )
goto V_79;
V_58 = F_36 ( V_75 , & V_76 ) ;
if ( V_58 )
goto V_81;
V_58 = F_22 ( V_6 , sizeof( * V_57 ) ,
V_59 ,
& V_55 , NULL ) ;
if ( V_58 )
goto V_82;
V_58 = F_37 ( V_6 , V_55 , sizeof( struct V_71 ) + V_77 ,
& V_74 ) ;
if ( V_58 )
goto V_83;
V_58 = F_23 ( V_55 , false ) ;
if ( V_58 )
goto V_84;
V_58 = F_36 ( V_74 , ( void * * ) & V_72 ) ;
if ( V_58 )
goto V_85;
V_72 -> V_86 . V_87 = 0 ;
V_72 -> V_86 . type = V_88 ;
V_72 -> V_86 . V_3 = 64 ;
V_72 -> V_86 . V_4 = 64 ;
V_72 -> V_86 . V_89 = V_66 ;
V_72 -> V_86 . V_90 = V_67 ;
V_72 -> V_91 = V_77 ;
V_72 -> V_92 . V_93 = 0 ;
V_72 -> V_92 . V_94 = 0 ;
V_72 -> V_92 . V_91 = V_77 ;
memcpy ( V_72 -> V_92 . V_95 , V_76 , V_77 ) ;
F_38 ( V_74 ) ;
F_38 ( V_75 ) ;
V_57 = (struct V_56 * ) F_25 ( V_6 , V_55 ) ;
V_57 -> type = V_96 ;
V_57 -> V_97 . V_98 . V_99 . V_24 = V_68 -> V_100 ;
V_57 -> V_97 . V_98 . V_99 . V_26 = V_68 -> V_101 ;
V_57 -> V_97 . V_98 . V_102 = F_39 ( V_6 , V_74 , 0 ) ;
V_57 -> V_97 . V_98 . V_103 = 1 ;
F_26 ( V_6 , V_55 , & V_57 -> V_61 ) ;
F_27 ( V_6 , V_55 , V_62 , false ) ;
F_28 ( V_55 ) ;
V_58 = F_33 ( V_75 , false ) ;
if ( ! V_58 ) {
F_40 ( V_75 ) ;
F_35 ( V_75 ) ;
}
F_41 ( V_70 ) ;
F_42 ( & V_74 ) ;
return V_58 ;
V_85:
F_43 ( V_55 ) ;
V_84:
F_42 ( & V_74 ) ;
V_83:
F_24 ( V_6 , V_55 ) ;
V_82:
F_38 ( V_75 ) ;
V_81:
F_40 ( V_75 ) ;
V_79:
F_41 ( V_70 ) ;
return V_58 ;
}
static int F_44 ( struct V_51 * V_52 ,
int V_24 , int V_26 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_53 * V_68 = F_19 ( V_52 ) ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
int V_58 ;
V_58 = F_22 ( V_6 , sizeof( * V_57 ) , V_59 ,
& V_55 , NULL ) ;
if ( V_58 )
return V_58 ;
V_58 = F_23 ( V_55 , true ) ;
if ( V_58 ) {
F_24 ( V_6 , V_55 ) ;
return V_58 ;
}
V_68 -> V_100 = V_24 ;
V_68 -> V_101 = V_26 ;
V_57 = (struct V_56 * ) F_25 ( V_6 , V_55 ) ;
V_57 -> type = V_104 ;
V_57 -> V_97 . V_99 . V_24 = V_68 -> V_100 ;
V_57 -> V_97 . V_99 . V_26 = V_68 -> V_101 ;
F_26 ( V_6 , V_55 , & V_57 -> V_61 ) ;
F_27 ( V_6 , V_55 , V_62 , false ) ;
F_28 ( V_55 ) ;
return 0 ;
}
static void F_45 ( struct V_105 * V_106 )
{
struct V_107 * V_108 = F_46 ( V_106 ) ;
if ( V_108 -> V_70 )
F_41 ( V_108 -> V_70 ) ;
F_47 ( V_106 ) ;
F_3 ( V_108 ) ;
}
static int F_48 ( struct V_105 * V_106 ,
struct V_63 * V_64 ,
unsigned V_32 , unsigned V_109 ,
struct V_110 * V_111 ,
unsigned V_112 )
{
struct V_107 * V_108 = F_46 ( V_106 ) ;
struct V_5 * V_6 = V_108 -> V_113 . V_39 -> V_40 ;
struct V_110 V_114 ;
struct V_73 * V_115 ;
int V_116 = 1 ;
F_49 ( V_106 -> V_39 ) ;
V_115 = F_32 ( V_108 -> V_70 ) ;
if ( ! V_115 -> V_117 ) {
F_50 ( V_106 -> V_39 ) ;
return 0 ;
}
if ( ! V_112 ) {
V_112 = 1 ;
V_111 = & V_114 ;
V_114 . V_118 = V_114 . y1 = 0 ;
V_114 . V_119 = V_106 -> V_3 ;
V_114 . V_120 = V_106 -> V_4 ;
} else if ( V_32 & V_121 ) {
V_112 /= 2 ;
V_116 = 2 ;
}
F_51 ( V_6 , V_108 , V_115 , V_32 , V_109 ,
V_111 , V_112 , V_116 ) ;
F_50 ( V_106 -> V_39 ) ;
return 0 ;
}
int
F_52 ( struct V_38 * V_39 ,
struct V_107 * V_122 ,
struct V_123 * V_124 ,
struct V_69 * V_70 )
{
int V_58 ;
V_122 -> V_70 = V_70 ;
V_58 = F_53 ( V_39 , & V_122 -> V_113 , & V_125 ) ;
if ( V_58 ) {
V_122 -> V_70 = NULL ;
return V_58 ;
}
F_54 ( & V_122 -> V_113 , V_124 ) ;
return 0 ;
}
static void F_55 ( struct V_51 * V_52 , int V_46 )
{
}
static bool F_56 ( struct V_51 * V_52 ,
const struct V_45 * V_46 ,
struct V_45 * V_126 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
F_5 ( V_6 , L_8 ,
V_11 ,
V_46 -> V_127 , V_46 -> V_128 ,
V_126 -> V_127 ,
V_126 -> V_128 ) ;
return true ;
}
void
F_57 ( struct V_5 * V_6 )
{
int V_12 ;
F_58 ( ! V_6 -> V_129 -> V_18 ) ;
if ( V_6 -> V_18 -> V_7 == 0 ) {
F_5 ( V_6 , L_9 , V_11 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_6 -> V_18 -> V_7 ; ++ V_12 ) {
struct V_1 * V_2 = & V_6 -> V_18 -> V_22 [ V_12 ] ;
if ( V_2 -> V_26 > 8192 || V_2 -> V_24 > 8192 ||
V_2 -> V_3 > 8192 || V_2 -> V_4 > 8192 ) {
F_31 ( L_10 ,
V_12 , V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_24 , V_2 -> V_26 ) ;
return;
}
}
F_59 ( V_6 ) ;
}
static void F_60 ( struct V_5 * V_6 ,
int V_44 ,
unsigned V_24 , unsigned V_26 ,
unsigned V_3 , unsigned V_4 ,
unsigned V_130 )
{
F_8 ( L_11 , V_44 , V_3 , V_4 , V_24 , V_26 ) ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_24 = V_24 ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_26 = V_26 ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_3 = V_3 ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_4 = V_4 ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_30 = V_130 ;
}
static int F_61 ( struct V_51 * V_52 ,
struct V_45 * V_46 ,
struct V_45 * V_126 ,
int V_24 , int V_26 ,
struct V_105 * V_131 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_132 * V_133 = ( void * ) V_46 -> V_134 ;
struct V_107 * V_122 ;
struct V_73 * V_135 , * V_136 = NULL ;
struct V_53 * V_68 = F_19 ( V_52 ) ;
T_1 V_3 , V_4 , V_137 ;
bool V_138 = false ;
int V_58 ;
int V_130 ;
if ( ! V_52 -> V_139 -> V_106 ) {
F_8 ( L_12 ) ;
return 0 ;
}
if ( V_131 ) {
V_122 = F_46 ( V_131 ) ;
V_136 = F_32 ( V_122 -> V_70 ) ;
}
V_122 = F_46 ( V_52 -> V_139 -> V_106 ) ;
V_135 = F_32 ( V_122 -> V_70 ) ;
if ( ! V_133 )
F_62 ( L_13 , V_24 , V_26 ) ;
else
F_62 ( L_14 ,
V_46 -> V_127 , V_46 -> V_128 , V_133 -> V_31 ) ;
F_62 ( L_15 ,
V_24 , V_26 ,
V_46 -> V_127 , V_46 -> V_128 ,
V_126 -> V_127 ,
V_126 -> V_128 ) ;
if ( V_68 -> V_44 == 0 )
V_138 = true ;
V_3 = V_46 -> V_127 ;
V_4 = V_46 -> V_128 ;
V_137 = 0 ;
V_58 = F_33 ( V_135 , false ) ;
if ( V_58 != 0 )
return V_58 ;
V_58 = F_34 ( V_135 , V_135 -> type , NULL ) ;
if ( V_58 != 0 ) {
F_35 ( V_135 ) ;
return - V_140 ;
}
F_35 ( V_135 ) ;
if ( V_138 ) {
F_63 ( V_6 ) ;
F_5 ( V_6 ,
L_16 ,
V_3 , V_4 , V_135 -> V_141 . V_3 ,
V_135 -> V_141 . V_4 , V_135 -> V_141 . V_142 , V_135 -> V_141 . V_143 ) ;
F_64 ( V_6 , V_137 , V_135 ) ;
V_135 -> V_117 = true ;
}
if ( V_135 -> V_117 ) {
F_8 ( L_17 , V_135 -> V_30 , V_68 -> V_44 ) ;
V_130 = 0 ;
} else {
V_130 = V_135 -> V_30 ;
}
if ( V_136 && V_136 != V_135 ) {
V_136 -> V_117 = false ;
V_58 = F_33 ( V_136 , false ) ;
F_40 ( V_136 ) ;
F_35 ( V_136 ) ;
}
F_60 ( V_6 , V_68 -> V_44 , V_24 , V_26 ,
V_46 -> V_127 ,
V_46 -> V_128 , V_130 ) ;
return 0 ;
}
static void F_65 ( struct V_51 * V_52 )
{
F_62 ( L_18 ,
V_52 -> V_46 . V_127 , V_52 -> V_46 . V_128 ,
V_52 -> V_24 , V_52 -> V_26 , V_52 -> V_144 ) ;
}
static void F_66 ( struct V_51 * V_52 )
{
F_62 ( L_19 ) ;
}
static void F_67 ( struct V_51 * V_52 )
{
struct V_53 * V_68 = F_19 ( V_52 ) ;
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
if ( V_52 -> V_139 -> V_106 ) {
struct V_107 * V_122 = F_46 ( V_52 -> V_139 -> V_106 ) ;
struct V_73 * V_135 = F_32 ( V_122 -> V_70 ) ;
int V_58 ;
V_58 = F_33 ( V_135 , false ) ;
F_40 ( V_135 ) ;
F_35 ( V_135 ) ;
V_52 -> V_139 -> V_106 = NULL ;
}
F_60 ( V_6 , V_68 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
F_57 ( V_6 ) ;
}
static int F_68 ( struct V_38 * V_39 , int V_145 )
{
struct V_53 * V_53 ;
V_53 = F_4 ( sizeof( struct V_53 ) , V_10 ) ;
if ( ! V_53 )
return - V_146 ;
F_69 ( V_39 , & V_53 -> V_113 , & V_147 ) ;
V_53 -> V_44 = V_145 ;
F_70 ( & V_53 -> V_113 , 256 ) ;
F_71 ( & V_53 -> V_113 , & V_148 ) ;
return 0 ;
}
static void F_72 ( struct V_149 * V_150 , int V_46 )
{
F_62 ( L_19 ) ;
}
static bool F_73 ( struct V_149 * V_150 ,
const struct V_45 * V_46 ,
struct V_45 * V_126 )
{
F_62 ( L_19 ) ;
return true ;
}
static void F_74 ( struct V_149 * V_150 )
{
F_62 ( L_19 ) ;
}
static void F_75 ( struct V_5 * V_6 ,
struct V_149 * V_150 )
{
int V_12 ;
struct V_41 * V_42 = F_76 ( V_150 ) ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
F_58 ( ! V_150 ) ;
V_12 = V_42 -> V_44 ;
if ( ! V_6 -> V_18 ||
V_6 -> V_18 -> V_19 <= V_12 ) {
F_31 (
L_20 ,
V_6 -> V_18 ,
V_6 -> V_18 ?
V_6 -> V_18 -> V_19 : - 1 ) ;
return;
}
if ( ! V_150 -> V_52 ) {
F_31 ( L_21 , V_150 ) ;
return;
}
if ( V_12 != 0 )
F_62 ( L_22 ) ;
V_2 = & V_6 -> V_18 -> V_22 [ V_12 ] ;
V_2 -> V_31 = V_12 ;
if ( V_150 -> V_52 -> V_144 ) {
V_46 = & V_150 -> V_52 -> V_46 ;
V_2 -> V_3 = V_46 -> V_127 ;
V_2 -> V_4 = V_46 -> V_128 ;
V_2 -> V_24 = V_150 -> V_52 -> V_24 ;
V_2 -> V_26 = V_150 -> V_52 -> V_26 ;
if ( V_6 -> V_18 -> V_7 < V_12 + 1 )
V_6 -> V_18 -> V_7 = V_12 + 1 ;
} else {
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_26 = 0 ;
}
F_8 ( L_23 ,
V_12 , V_2 -> V_24 , V_2 -> V_26 , V_2 -> V_3 , V_2 -> V_4 , V_6 -> V_18 -> V_7 ) ;
V_2 -> V_32 = 0 ;
F_57 ( V_6 ) ;
}
static void F_77 ( struct V_149 * V_150 )
{
struct V_5 * V_6 = V_150 -> V_39 -> V_40 ;
F_75 ( V_6 , V_150 ) ;
F_62 ( L_19 ) ;
}
static void F_78 ( struct V_149 * V_150 ,
struct V_45 * V_46 ,
struct V_45 * V_126 )
{
F_62 ( L_19 ) ;
}
static int F_79 ( struct V_34 * V_35 )
{
int V_58 = 0 ;
struct V_5 * V_6 = V_35 -> V_39 -> V_40 ;
unsigned V_36 = 1024 ;
unsigned V_37 = 768 ;
F_8 ( L_24 , V_6 -> V_18 ) ;
if ( V_6 -> V_18 && V_6 -> V_18 -> V_7 ) {
V_58 = F_12 ( V_35 , & V_36 , & V_37 ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_58 += F_16 ( V_35 , V_36 , V_37 ) ;
return V_58 ;
}
static int F_80 ( struct V_34 * V_35 ,
struct V_45 * V_46 )
{
F_62 ( L_25 , V_46 -> V_151 , V_46 -> V_127 ,
V_46 -> V_128 , V_46 -> V_152 ) ;
return V_153 ;
}
static struct V_149 * F_81 ( struct V_34 * V_35 )
{
struct V_41 * V_41 =
F_13 ( V_35 ) ;
F_62 ( L_19 ) ;
return & V_41 -> V_154 ;
}
static void F_82 ( struct V_34 * V_35 )
{
F_62 ( L_19 ) ;
}
static void F_83 ( struct V_34 * V_35 )
{
F_62 ( L_19 ) ;
}
static enum V_155 F_84 (
struct V_34 * V_35 ,
bool V_156 )
{
struct V_41 * V_42 =
F_13 ( V_35 ) ;
struct V_38 * V_33 = V_35 -> V_39 ;
struct V_5 * V_6 = V_33 -> V_40 ;
int V_157 ;
V_157 = ( V_42 -> V_44 == 0 ) ||
( V_6 -> V_8 &&
V_6 -> V_8 -> V_7 > V_42 -> V_44 &&
F_1 ( & V_6 -> V_8 -> V_22 [ V_42 -> V_44 ] ) ) ;
F_62 ( L_26 , V_42 -> V_44 , V_157 ) ;
if ( ! V_157 )
F_60 ( V_6 , V_42 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
return V_157 ? V_158
: V_159 ;
}
static int F_85 ( struct V_34 * V_35 ,
struct V_160 * V_161 ,
T_3 V_162 )
{
F_62 ( L_19 ) ;
return 0 ;
}
static void F_86 ( struct V_34 * V_35 )
{
struct V_41 * V_41 =
F_13 ( V_35 ) ;
F_87 ( V_35 ) ;
F_88 ( V_35 ) ;
F_3 ( V_41 ) ;
}
static void F_89 ( struct V_149 * V_150 )
{
F_90 ( V_150 ) ;
}
static int F_91 ( struct V_5 * V_6 )
{
if ( V_6 -> V_163 )
return 0 ;
V_6 -> V_163 =
F_92 ( V_6 -> V_33 , V_164 ,
L_27 , 0 , 1 ) ;
return 0 ;
}
static int F_93 ( struct V_38 * V_39 , int V_165 )
{
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_41 * V_41 ;
struct V_34 * V_35 ;
struct V_149 * V_150 ;
V_41 = F_4 ( sizeof( struct V_41 ) , V_10 ) ;
if ( ! V_41 )
return - V_146 ;
V_41 -> V_44 = V_165 ;
V_35 = & V_41 -> V_113 ;
V_150 = & V_41 -> V_154 ;
F_94 ( V_39 , & V_41 -> V_113 ,
& V_166 , V_167 ) ;
F_95 ( V_39 , & V_41 -> V_154 , & V_168 ,
V_169 ) ;
V_35 -> V_170 = V_171 ;
V_150 -> V_172 = 1 << V_165 ;
F_96 ( & V_41 -> V_113 ,
& V_41 -> V_154 ) ;
F_97 ( V_150 , & V_173 ) ;
F_98 ( V_35 , & V_174 ) ;
F_99 ( & V_35 -> V_113 ,
V_6 -> V_163 , 0 ) ;
F_100 ( V_35 ) ;
return 0 ;
}
static struct V_105 *
F_101 ( struct V_38 * V_39 ,
struct V_63 * V_64 ,
struct V_123 * V_124 )
{
struct V_69 * V_70 ;
struct V_107 * V_108 ;
int V_58 ;
V_70 = F_30 ( V_39 , V_64 , V_124 -> V_175 [ 0 ] ) ;
V_108 = F_4 ( sizeof( * V_108 ) , V_10 ) ;
if ( V_108 == NULL )
return NULL ;
V_58 = F_52 ( V_39 , V_108 , V_124 , V_70 ) ;
if ( V_58 ) {
F_3 ( V_108 ) ;
F_41 ( V_70 ) ;
return NULL ;
}
return & V_108 -> V_113 ;
}
int F_102 ( struct V_5 * V_6 )
{
int V_58 ;
struct V_69 * V_176 ;
int V_19 = V_177 ;
int V_178 = sizeof( struct V_9 ) +
V_19 * sizeof( struct V_1 ) ;
V_58 = F_103 ( V_6 , V_178 , 0 ,
V_179 ,
false , false , NULL , & V_176 ) ;
if ( V_58 ) {
F_31 ( L_28 , V_11 , V_58 ) ;
return - V_146 ;
}
V_6 -> V_180 = F_32 ( V_176 ) ;
V_58 = F_33 ( V_6 -> V_180 , false ) ;
if ( V_58 )
return V_58 ;
V_58 = F_34 ( V_6 -> V_180 , V_179 , NULL ) ;
if ( V_58 ) {
F_35 ( V_6 -> V_180 ) ;
return V_58 ;
}
F_35 ( V_6 -> V_180 ) ;
F_36 ( V_6 -> V_180 , NULL ) ;
V_6 -> V_18 = V_6 -> V_180 -> V_181 ;
V_6 -> V_129 -> V_18 =
F_39 ( V_6 , V_6 -> V_180 , 0 ) ;
memset ( V_6 -> V_18 , 0 , V_178 ) ;
V_6 -> V_18 -> V_19 = V_19 ;
return 0 ;
}
int F_104 ( struct V_5 * V_6 )
{
int V_58 ;
V_6 -> V_18 = NULL ;
V_6 -> V_129 -> V_18 = 0 ;
F_38 ( V_6 -> V_180 ) ;
V_58 = F_33 ( V_6 -> V_180 , false ) ;
if ( V_58 )
return V_58 ;
F_40 ( V_6 -> V_180 ) ;
F_35 ( V_6 -> V_180 ) ;
F_42 ( & V_6 -> V_180 ) ;
return 0 ;
}
int F_105 ( struct V_5 * V_6 )
{
int V_12 ;
int V_58 ;
F_106 ( V_6 -> V_33 ) ;
V_58 = F_102 ( V_6 ) ;
if ( V_58 )
return V_58 ;
V_6 -> V_33 -> V_182 . V_183 = ( void * ) & V_184 ;
V_6 -> V_33 -> V_182 . V_185 = 320 ;
V_6 -> V_33 -> V_182 . V_186 = 200 ;
V_6 -> V_33 -> V_182 . V_187 = 8192 ;
V_6 -> V_33 -> V_182 . V_188 = 8192 ;
V_6 -> V_33 -> V_182 . V_189 = V_6 -> V_190 ;
F_91 ( V_6 ) ;
for ( V_12 = 0 ; V_12 < V_177 ; ++ V_12 ) {
F_68 ( V_6 -> V_33 , V_12 ) ;
F_93 ( V_6 -> V_33 , V_12 ) ;
}
V_6 -> V_191 . V_192 = true ;
F_107 ( V_6 ) ;
return 0 ;
}
void F_108 ( struct V_5 * V_6 )
{
F_109 ( V_6 ) ;
F_104 ( V_6 ) ;
if ( V_6 -> V_191 . V_192 ) {
F_110 ( V_6 -> V_33 ) ;
V_6 -> V_191 . V_192 = false ;
}
}
