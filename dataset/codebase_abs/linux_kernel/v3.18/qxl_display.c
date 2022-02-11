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
static int F_21 ( struct V_51 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_53 * V_59 = F_19 ( V_52 ) ;
struct V_60 * V_61 = F_22 ( V_55 ) ;
struct V_60 * V_62 = F_22 ( V_52 -> V_63 -> V_55 ) ;
struct V_64 * V_65 = F_23 ( V_62 -> V_66 ) ;
struct V_64 * V_67 = F_23 ( V_61 -> V_66 ) ;
unsigned long V_32 ;
struct V_68 V_69 = {
. V_70 = 0 ,
. y1 = 0 ,
. V_71 = V_55 -> V_3 ,
. V_72 = V_55 -> V_4
} ;
int V_73 = 1 ;
int V_74 = 1 ;
int V_75 = 0 ;
V_52 -> V_63 -> V_55 = V_55 ;
V_65 -> V_76 = false ;
V_67 -> V_76 = true ;
V_75 = F_24 ( V_67 , false ) ;
if ( V_75 )
return V_75 ;
F_25 ( V_6 , V_61 , V_67 , 0 , 0 ,
& V_69 , V_74 , V_73 ) ;
F_26 ( V_39 , V_59 -> V_44 ) ;
if ( V_57 ) {
F_27 ( & V_39 -> V_77 , V_32 ) ;
F_28 ( V_39 , V_59 -> V_44 , V_57 ) ;
F_29 ( & V_39 -> V_77 , V_32 ) ;
}
F_30 ( V_39 , V_59 -> V_44 ) ;
F_31 ( V_67 ) ;
return 0 ;
}
static int
F_32 ( struct V_5 * V_6 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_75 ;
V_75 = F_33 ( V_6 , sizeof( * V_81 ) , V_82 ,
& V_79 , NULL ) ;
if ( V_75 )
return V_75 ;
V_75 = F_34 ( V_79 , true ) ;
if ( V_75 ) {
F_35 ( V_6 , V_79 ) ;
return V_75 ;
}
V_81 = (struct V_80 * ) F_36 ( V_6 , V_79 ) ;
V_81 -> type = V_83 ;
F_37 ( V_6 , V_79 , & V_81 -> V_84 ) ;
F_38 ( V_6 , V_79 , V_85 , false ) ;
F_39 ( V_79 ) ;
return 0 ;
}
static int F_40 ( struct V_51 * V_52 ,
struct V_86 * V_87 ,
T_1 V_88 ,
T_1 V_3 ,
T_1 V_4 , T_2 V_89 , T_2 V_90 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_53 * V_59 = F_19 ( V_52 ) ;
struct V_91 * V_66 ;
struct V_92 * V_93 ;
struct V_80 * V_81 ;
struct V_64 * V_94 , * V_95 ;
struct V_78 * V_79 ;
void * V_96 ;
int V_97 = 64 * 64 * 4 ;
int V_75 = 0 ;
if ( ! V_88 )
return F_32 ( V_6 ) ;
V_66 = F_41 ( V_52 -> V_39 , V_87 , V_88 ) ;
if ( ! V_66 ) {
F_42 ( L_7 ) ;
return - V_98 ;
}
V_95 = F_23 ( V_66 ) ;
V_75 = F_24 ( V_95 , false ) ;
if ( V_75 )
goto V_99;
V_75 = F_43 ( V_95 , V_100 , NULL ) ;
F_31 ( V_95 ) ;
if ( V_75 )
goto V_99;
V_75 = F_44 ( V_95 , & V_96 ) ;
if ( V_75 )
goto V_101;
V_75 = F_33 ( V_6 , sizeof( * V_81 ) ,
V_82 ,
& V_79 , NULL ) ;
if ( V_75 )
goto V_102;
V_75 = F_45 ( V_6 , V_79 , sizeof( struct V_92 ) + V_97 ,
& V_94 ) ;
if ( V_75 )
goto V_103;
V_75 = F_34 ( V_79 , false ) ;
if ( V_75 )
goto V_104;
V_75 = F_44 ( V_94 , ( void * * ) & V_93 ) ;
if ( V_75 )
goto V_105;
V_93 -> V_106 . V_107 = 0 ;
V_93 -> V_106 . type = V_108 ;
V_93 -> V_106 . V_3 = 64 ;
V_93 -> V_106 . V_4 = 64 ;
V_93 -> V_106 . V_109 = V_89 ;
V_93 -> V_106 . V_110 = V_90 ;
V_93 -> V_111 = V_97 ;
V_93 -> V_112 . V_113 = 0 ;
V_93 -> V_112 . V_114 = 0 ;
V_93 -> V_112 . V_111 = V_97 ;
memcpy ( V_93 -> V_112 . V_115 , V_96 , V_97 ) ;
F_46 ( V_94 ) ;
F_46 ( V_95 ) ;
V_81 = (struct V_80 * ) F_36 ( V_6 , V_79 ) ;
V_81 -> type = V_116 ;
V_81 -> V_117 . V_118 . V_119 . V_24 = V_59 -> V_120 ;
V_81 -> V_117 . V_118 . V_119 . V_26 = V_59 -> V_121 ;
V_81 -> V_117 . V_118 . V_122 = F_47 ( V_6 , V_94 , 0 ) ;
V_81 -> V_117 . V_118 . V_123 = 1 ;
F_37 ( V_6 , V_79 , & V_81 -> V_84 ) ;
F_38 ( V_6 , V_79 , V_85 , false ) ;
F_39 ( V_79 ) ;
V_75 = F_24 ( V_95 , false ) ;
if ( ! V_75 ) {
F_48 ( V_95 ) ;
F_31 ( V_95 ) ;
}
F_49 ( V_66 ) ;
F_50 ( & V_94 ) ;
return V_75 ;
V_105:
F_51 ( V_79 ) ;
V_104:
F_50 ( & V_94 ) ;
V_103:
F_35 ( V_6 , V_79 ) ;
V_102:
F_46 ( V_95 ) ;
V_101:
F_48 ( V_95 ) ;
V_99:
F_49 ( V_66 ) ;
return V_75 ;
}
static int F_52 ( struct V_51 * V_52 ,
int V_24 , int V_26 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_53 * V_59 = F_19 ( V_52 ) ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_75 ;
V_75 = F_33 ( V_6 , sizeof( * V_81 ) , V_82 ,
& V_79 , NULL ) ;
if ( V_75 )
return V_75 ;
V_75 = F_34 ( V_79 , true ) ;
if ( V_75 ) {
F_35 ( V_6 , V_79 ) ;
return V_75 ;
}
V_59 -> V_120 = V_24 ;
V_59 -> V_121 = V_26 ;
V_81 = (struct V_80 * ) F_36 ( V_6 , V_79 ) ;
V_81 -> type = V_124 ;
V_81 -> V_117 . V_119 . V_24 = V_59 -> V_120 ;
V_81 -> V_117 . V_119 . V_26 = V_59 -> V_121 ;
F_37 ( V_6 , V_79 , & V_81 -> V_84 ) ;
F_38 ( V_6 , V_79 , V_85 , false ) ;
F_39 ( V_79 ) ;
return 0 ;
}
static void F_53 ( struct V_54 * V_55 )
{
struct V_60 * V_125 = F_22 ( V_55 ) ;
if ( V_125 -> V_66 )
F_49 ( V_125 -> V_66 ) ;
F_54 ( V_55 ) ;
F_3 ( V_125 ) ;
}
static int F_55 ( struct V_54 * V_55 ,
struct V_86 * V_87 ,
unsigned V_32 , unsigned V_126 ,
struct V_68 * V_127 ,
unsigned V_128 )
{
struct V_60 * V_125 = F_22 ( V_55 ) ;
struct V_5 * V_6 = V_125 -> V_129 . V_39 -> V_40 ;
struct V_68 V_69 ;
struct V_64 * V_130 ;
int V_73 = 1 ;
F_56 ( V_55 -> V_39 ) ;
V_130 = F_23 ( V_125 -> V_66 ) ;
if ( ! V_130 -> V_76 ) {
F_57 ( V_55 -> V_39 ) ;
return 0 ;
}
if ( ! V_128 ) {
V_128 = 1 ;
V_127 = & V_69 ;
V_69 . V_70 = V_69 . y1 = 0 ;
V_69 . V_71 = V_55 -> V_3 ;
V_69 . V_72 = V_55 -> V_4 ;
} else if ( V_32 & V_131 ) {
V_128 /= 2 ;
V_73 = 2 ;
}
F_25 ( V_6 , V_125 , V_130 , V_32 , V_126 ,
V_127 , V_128 , V_73 ) ;
F_57 ( V_55 -> V_39 ) ;
return 0 ;
}
int
F_58 ( struct V_38 * V_39 ,
struct V_60 * V_132 ,
struct V_133 * V_134 ,
struct V_91 * V_66 )
{
int V_75 ;
V_132 -> V_66 = V_66 ;
V_75 = F_59 ( V_39 , & V_132 -> V_129 , & V_135 ) ;
if ( V_75 ) {
V_132 -> V_66 = NULL ;
return V_75 ;
}
F_60 ( & V_132 -> V_129 , V_134 ) ;
return 0 ;
}
static void F_61 ( struct V_51 * V_52 , int V_46 )
{
}
static bool F_62 ( struct V_51 * V_52 ,
const struct V_45 * V_46 ,
struct V_45 * V_136 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
F_5 ( V_6 , L_8 ,
V_11 ,
V_46 -> V_137 , V_46 -> V_138 ,
V_136 -> V_137 ,
V_136 -> V_138 ) ;
return true ;
}
void
F_63 ( struct V_5 * V_6 )
{
int V_12 ;
F_64 ( ! V_6 -> V_139 -> V_18 ) ;
if ( V_6 -> V_18 -> V_7 == 0 ) {
F_5 ( V_6 , L_9 , V_11 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_6 -> V_18 -> V_7 ; ++ V_12 ) {
struct V_1 * V_2 = & V_6 -> V_18 -> V_22 [ V_12 ] ;
if ( V_2 -> V_26 > 8192 || V_2 -> V_24 > 8192 ||
V_2 -> V_3 > 8192 || V_2 -> V_4 > 8192 ) {
F_42 ( L_10 ,
V_12 , V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_24 , V_2 -> V_26 ) ;
return;
}
}
F_65 ( V_6 ) ;
}
static void F_66 ( struct V_5 * V_6 ,
int V_44 ,
unsigned V_24 , unsigned V_26 ,
unsigned V_3 , unsigned V_4 ,
unsigned V_140 )
{
F_8 ( L_11 , V_44 , V_3 , V_4 , V_24 , V_26 ) ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_24 = V_24 ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_26 = V_26 ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_3 = V_3 ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_4 = V_4 ;
V_6 -> V_18 -> V_22 [ V_44 ] . V_30 = V_140 ;
}
static int F_67 ( struct V_51 * V_52 ,
struct V_45 * V_46 ,
struct V_45 * V_136 ,
int V_24 , int V_26 ,
struct V_54 * V_141 )
{
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_142 * V_143 = ( void * ) V_46 -> V_144 ;
struct V_60 * V_132 ;
struct V_64 * V_67 , * V_145 = NULL ;
struct V_53 * V_59 = F_19 ( V_52 ) ;
bool V_146 = false ;
int V_75 ;
int V_140 ;
if ( ! V_52 -> V_63 -> V_55 ) {
F_8 ( L_12 ) ;
return 0 ;
}
if ( V_141 ) {
V_132 = F_22 ( V_141 ) ;
V_145 = F_23 ( V_132 -> V_66 ) ;
}
V_132 = F_22 ( V_52 -> V_63 -> V_55 ) ;
V_67 = F_23 ( V_132 -> V_66 ) ;
if ( ! V_143 )
F_68 ( L_13 , V_24 , V_26 ) ;
else
F_68 ( L_14 ,
V_46 -> V_137 , V_46 -> V_138 , V_143 -> V_31 ) ;
F_68 ( L_15 ,
V_24 , V_26 ,
V_46 -> V_137 , V_46 -> V_138 ,
V_136 -> V_137 ,
V_136 -> V_138 ) ;
if ( V_59 -> V_44 == 0 )
V_146 = true ;
if ( V_67 -> V_147 . V_148 * V_67 -> V_147 . V_4 > V_6 -> V_149 ) {
F_42 ( L_16 ) ;
return - V_150 ;
}
V_75 = F_24 ( V_67 , false ) ;
if ( V_75 != 0 )
return V_75 ;
V_75 = F_43 ( V_67 , V_67 -> type , NULL ) ;
if ( V_75 != 0 ) {
F_31 ( V_67 ) ;
return - V_150 ;
}
F_31 ( V_67 ) ;
if ( V_146 ) {
F_69 ( V_6 ) ;
F_5 ( V_6 ,
L_17 ,
V_67 -> V_147 . V_3 , V_67 -> V_147 . V_4 ,
V_67 -> V_147 . V_148 , V_67 -> V_147 . V_151 ) ;
F_70 ( V_6 , 0 , V_67 ) ;
V_67 -> V_76 = true ;
}
if ( V_67 -> V_76 ) {
F_8 ( L_18 , V_67 -> V_30 , V_59 -> V_44 ) ;
V_140 = 0 ;
} else {
V_140 = V_67 -> V_30 ;
}
if ( V_145 && V_145 != V_67 ) {
V_145 -> V_76 = false ;
V_75 = F_24 ( V_145 , false ) ;
F_48 ( V_145 ) ;
F_31 ( V_145 ) ;
}
F_66 ( V_6 , V_59 -> V_44 , V_24 , V_26 ,
V_46 -> V_137 ,
V_46 -> V_138 , V_140 ) ;
return 0 ;
}
static void F_71 ( struct V_51 * V_52 )
{
F_68 ( L_19 ,
V_52 -> V_46 . V_137 , V_52 -> V_46 . V_138 ,
V_52 -> V_24 , V_52 -> V_26 , V_52 -> V_152 ) ;
}
static void F_72 ( struct V_51 * V_52 )
{
F_68 ( L_20 ) ;
}
static void F_73 ( struct V_51 * V_52 )
{
struct V_53 * V_59 = F_19 ( V_52 ) ;
struct V_38 * V_39 = V_52 -> V_39 ;
struct V_5 * V_6 = V_39 -> V_40 ;
if ( V_52 -> V_63 -> V_55 ) {
struct V_60 * V_132 = F_22 ( V_52 -> V_63 -> V_55 ) ;
struct V_64 * V_67 = F_23 ( V_132 -> V_66 ) ;
int V_75 ;
V_75 = F_24 ( V_67 , false ) ;
F_48 ( V_67 ) ;
F_31 ( V_67 ) ;
V_52 -> V_63 -> V_55 = NULL ;
}
F_66 ( V_6 , V_59 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
F_63 ( V_6 ) ;
}
static int F_74 ( struct V_38 * V_39 , int V_153 )
{
struct V_53 * V_53 ;
V_53 = F_4 ( sizeof( struct V_53 ) , V_10 ) ;
if ( ! V_53 )
return - V_154 ;
F_75 ( V_39 , & V_53 -> V_129 , & V_155 ) ;
V_53 -> V_44 = V_153 ;
F_76 ( & V_53 -> V_129 , 256 ) ;
F_77 ( & V_53 -> V_129 , & V_156 ) ;
return 0 ;
}
static void F_78 ( struct V_157 * V_158 , int V_46 )
{
F_68 ( L_20 ) ;
}
static bool F_79 ( struct V_157 * V_158 ,
const struct V_45 * V_46 ,
struct V_45 * V_136 )
{
F_68 ( L_20 ) ;
return true ;
}
static void F_80 ( struct V_157 * V_158 )
{
F_68 ( L_20 ) ;
}
static void F_81 ( struct V_5 * V_6 ,
struct V_157 * V_158 )
{
int V_12 ;
struct V_41 * V_42 = F_82 ( V_158 ) ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
F_64 ( ! V_158 ) ;
V_12 = V_42 -> V_44 ;
if ( ! V_6 -> V_18 ||
V_6 -> V_18 -> V_19 <= V_12 ) {
F_42 (
L_21 ,
V_6 -> V_18 ,
V_6 -> V_18 ?
V_6 -> V_18 -> V_19 : - 1 ) ;
return;
}
if ( ! V_158 -> V_52 ) {
F_42 ( L_22 , V_158 ) ;
return;
}
if ( V_12 != 0 )
F_68 ( L_23 ) ;
V_2 = & V_6 -> V_18 -> V_22 [ V_12 ] ;
V_2 -> V_31 = V_12 ;
if ( V_158 -> V_52 -> V_152 ) {
V_46 = & V_158 -> V_52 -> V_46 ;
V_2 -> V_3 = V_46 -> V_137 ;
V_2 -> V_4 = V_46 -> V_138 ;
V_2 -> V_24 = V_158 -> V_52 -> V_24 ;
V_2 -> V_26 = V_158 -> V_52 -> V_26 ;
if ( V_6 -> V_18 -> V_7 < V_12 + 1 )
V_6 -> V_18 -> V_7 = V_12 + 1 ;
} else {
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_26 = 0 ;
}
F_8 ( L_24 ,
V_12 , V_2 -> V_24 , V_2 -> V_26 , V_2 -> V_3 , V_2 -> V_4 , V_6 -> V_18 -> V_7 ) ;
V_2 -> V_32 = 0 ;
F_63 ( V_6 ) ;
}
static void F_83 ( struct V_157 * V_158 )
{
struct V_5 * V_6 = V_158 -> V_39 -> V_40 ;
F_81 ( V_6 , V_158 ) ;
F_68 ( L_20 ) ;
}
static void F_84 ( struct V_157 * V_158 ,
struct V_45 * V_46 ,
struct V_45 * V_136 )
{
F_68 ( L_20 ) ;
}
static int F_85 ( struct V_34 * V_35 )
{
int V_75 = 0 ;
struct V_5 * V_6 = V_35 -> V_39 -> V_40 ;
unsigned V_36 = 1024 ;
unsigned V_37 = 768 ;
F_8 ( L_25 , V_6 -> V_18 ) ;
if ( V_6 -> V_18 && V_6 -> V_18 -> V_7 ) {
V_75 = F_12 ( V_35 , & V_36 , & V_37 ) ;
if ( V_75 < 0 )
return V_75 ;
}
V_75 += F_16 ( V_35 , V_36 , V_37 ) ;
return V_75 ;
}
static int F_86 ( struct V_34 * V_35 ,
struct V_45 * V_46 )
{
F_68 ( L_26 , V_46 -> V_159 , V_46 -> V_137 ,
V_46 -> V_138 , V_46 -> V_160 ) ;
return V_161 ;
}
static struct V_157 * F_87 ( struct V_34 * V_35 )
{
struct V_41 * V_41 =
F_13 ( V_35 ) ;
F_68 ( L_20 ) ;
return & V_41 -> V_162 ;
}
static void F_88 ( struct V_34 * V_35 )
{
F_68 ( L_20 ) ;
}
static void F_89 ( struct V_34 * V_35 )
{
F_68 ( L_20 ) ;
}
static enum V_163 F_90 (
struct V_34 * V_35 ,
bool V_164 )
{
struct V_41 * V_42 =
F_13 ( V_35 ) ;
struct V_38 * V_33 = V_35 -> V_39 ;
struct V_5 * V_6 = V_33 -> V_40 ;
int V_165 ;
V_165 = ( V_42 -> V_44 == 0 ) ||
( V_6 -> V_8 &&
V_6 -> V_8 -> V_7 > V_42 -> V_44 &&
F_1 ( & V_6 -> V_8 -> V_22 [ V_42 -> V_44 ] ) ) ;
F_68 ( L_27 , V_42 -> V_44 , V_165 ) ;
if ( ! V_165 )
F_66 ( V_6 , V_42 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
return V_165 ? V_166
: V_167 ;
}
static int F_91 ( struct V_34 * V_35 ,
struct V_168 * V_169 ,
T_3 V_170 )
{
F_68 ( L_20 ) ;
return 0 ;
}
static void F_92 ( struct V_34 * V_35 )
{
struct V_41 * V_41 =
F_13 ( V_35 ) ;
F_93 ( V_35 ) ;
F_94 ( V_35 ) ;
F_3 ( V_41 ) ;
}
static void F_95 ( struct V_157 * V_158 )
{
F_96 ( V_158 ) ;
}
static int F_97 ( struct V_5 * V_6 )
{
if ( V_6 -> V_171 )
return 0 ;
V_6 -> V_171 =
F_98 ( V_6 -> V_33 , V_172 ,
L_28 , 0 , 1 ) ;
return 0 ;
}
static int F_99 ( struct V_38 * V_39 , int V_173 )
{
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_41 * V_41 ;
struct V_34 * V_35 ;
struct V_157 * V_158 ;
V_41 = F_4 ( sizeof( struct V_41 ) , V_10 ) ;
if ( ! V_41 )
return - V_154 ;
V_41 -> V_44 = V_173 ;
V_35 = & V_41 -> V_129 ;
V_158 = & V_41 -> V_162 ;
F_100 ( V_39 , & V_41 -> V_129 ,
& V_174 , V_175 ) ;
F_101 ( V_39 , & V_41 -> V_162 , & V_176 ,
V_177 ) ;
V_35 -> V_178 = V_179 ;
V_158 -> V_180 = 1 << V_173 ;
F_102 ( & V_41 -> V_129 ,
& V_41 -> V_162 ) ;
F_103 ( V_158 , & V_181 ) ;
F_104 ( V_35 , & V_182 ) ;
F_105 ( & V_35 -> V_129 ,
V_6 -> V_171 , 0 ) ;
F_106 ( V_35 ) ;
return 0 ;
}
static struct V_54 *
F_107 ( struct V_38 * V_39 ,
struct V_86 * V_87 ,
struct V_133 * V_134 )
{
struct V_91 * V_66 ;
struct V_60 * V_125 ;
int V_75 ;
V_66 = F_41 ( V_39 , V_87 , V_134 -> V_183 [ 0 ] ) ;
V_125 = F_4 ( sizeof( * V_125 ) , V_10 ) ;
if ( V_125 == NULL )
return NULL ;
V_75 = F_58 ( V_39 , V_125 , V_134 , V_66 ) ;
if ( V_75 ) {
F_3 ( V_125 ) ;
F_49 ( V_66 ) ;
return NULL ;
}
return & V_125 -> V_129 ;
}
int F_108 ( struct V_5 * V_6 )
{
int V_75 ;
struct V_91 * V_184 ;
int V_19 = V_185 ;
int V_186 = sizeof( struct V_9 ) +
V_19 * sizeof( struct V_1 ) ;
V_75 = F_109 ( V_6 , V_186 , 0 ,
V_187 ,
false , false , NULL , & V_184 ) ;
if ( V_75 ) {
F_42 ( L_29 , V_11 , V_75 ) ;
return - V_154 ;
}
V_6 -> V_188 = F_23 ( V_184 ) ;
V_75 = F_24 ( V_6 -> V_188 , false ) ;
if ( V_75 )
return V_75 ;
V_75 = F_43 ( V_6 -> V_188 , V_187 , NULL ) ;
if ( V_75 ) {
F_31 ( V_6 -> V_188 ) ;
return V_75 ;
}
F_31 ( V_6 -> V_188 ) ;
F_44 ( V_6 -> V_188 , NULL ) ;
V_6 -> V_18 = V_6 -> V_188 -> V_189 ;
V_6 -> V_139 -> V_18 =
F_47 ( V_6 , V_6 -> V_188 , 0 ) ;
memset ( V_6 -> V_18 , 0 , V_186 ) ;
V_6 -> V_18 -> V_19 = V_19 ;
return 0 ;
}
int F_110 ( struct V_5 * V_6 )
{
int V_75 ;
V_6 -> V_18 = NULL ;
V_6 -> V_139 -> V_18 = 0 ;
F_46 ( V_6 -> V_188 ) ;
V_75 = F_24 ( V_6 -> V_188 , false ) ;
if ( V_75 )
return V_75 ;
F_48 ( V_6 -> V_188 ) ;
F_31 ( V_6 -> V_188 ) ;
F_50 ( & V_6 -> V_188 ) ;
return 0 ;
}
int F_111 ( struct V_5 * V_6 )
{
int V_12 ;
int V_75 ;
F_112 ( V_6 -> V_33 ) ;
V_75 = F_108 ( V_6 ) ;
if ( V_75 )
return V_75 ;
V_6 -> V_33 -> V_190 . V_191 = ( void * ) & V_192 ;
V_6 -> V_33 -> V_190 . V_193 = 320 ;
V_6 -> V_33 -> V_190 . V_194 = 200 ;
V_6 -> V_33 -> V_190 . V_195 = 8192 ;
V_6 -> V_33 -> V_190 . V_196 = 8192 ;
V_6 -> V_33 -> V_190 . V_197 = V_6 -> V_198 ;
F_97 ( V_6 ) ;
for ( V_12 = 0 ; V_12 < V_185 ; ++ V_12 ) {
F_74 ( V_6 -> V_33 , V_12 ) ;
F_99 ( V_6 -> V_33 , V_12 ) ;
}
V_6 -> V_199 . V_200 = true ;
F_113 ( V_6 ) ;
return 0 ;
}
void F_114 ( struct V_5 * V_6 )
{
F_115 ( V_6 ) ;
F_110 ( V_6 ) ;
if ( V_6 -> V_199 . V_200 ) {
F_116 ( V_6 -> V_33 ) ;
V_6 -> V_199 . V_200 = false ;
}
}
