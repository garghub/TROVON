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
F_10 ( V_6 -> V_33 ) ;
}
static int F_11 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_5 * V_6 = V_37 -> V_38 ;
struct V_39 * V_40 = F_12 ( V_35 ) ;
int V_41 = V_40 -> V_42 ;
struct V_43 * V_44 = NULL ;
struct V_1 * V_2 ;
if ( ! V_6 -> V_8 )
return 0 ;
V_2 = & V_6 -> V_8 -> V_22 [ V_41 ] ;
V_44 = F_13 ( V_37 , V_2 -> V_3 , V_2 -> V_4 , 60 , false , false ,
false ) ;
V_44 -> type |= V_45 ;
F_14 ( V_35 , V_44 ) ;
return 1 ;
}
static int F_15 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_43 * V_44 = NULL ;
int V_12 ;
struct V_46 {
int V_47 ;
int V_41 ;
} V_48 [] = {
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
for ( V_12 = 0 ; V_12 < F_16 ( V_48 ) ; V_12 ++ ) {
if ( V_48 [ V_12 ] . V_47 < 320 || V_48 [ V_12 ] . V_41 < 200 )
continue;
V_44 = F_13 ( V_37 , V_48 [ V_12 ] . V_47 , V_48 [ V_12 ] . V_41 ,
60 , false , false , false ) ;
if ( V_48 [ V_12 ] . V_47 == 1024 && V_48 [ V_12 ] . V_41 == 768 )
V_44 -> type |= V_45 ;
F_14 ( V_35 , V_44 ) ;
}
return V_12 - 1 ;
}
static void F_17 ( struct V_49 * V_50 )
{
struct V_51 * V_51 = F_18 ( V_50 ) ;
F_19 ( V_50 ) ;
F_3 ( V_51 ) ;
}
static int
F_20 ( struct V_5 * V_6 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_56 ;
V_56 = F_21 ( V_6 , sizeof( * V_55 ) , V_57 ,
& V_53 , NULL ) ;
if ( V_56 )
return V_56 ;
V_56 = F_22 ( V_53 , true ) ;
if ( V_56 ) {
F_23 ( V_6 , V_53 ) ;
return V_56 ;
}
V_55 = (struct V_54 * ) F_24 ( V_6 , V_53 ) ;
V_55 -> type = V_58 ;
F_25 ( V_6 , V_53 , & V_55 -> V_59 ) ;
F_26 ( V_6 , V_53 , V_60 , false ) ;
F_27 ( V_53 ) ;
return 0 ;
}
static int F_28 ( struct V_49 * V_50 ,
struct V_61 * V_62 ,
T_1 V_63 ,
T_1 V_3 ,
T_1 V_4 , T_2 V_64 , T_2 V_65 )
{
struct V_36 * V_37 = V_50 -> V_37 ;
struct V_5 * V_6 = V_37 -> V_38 ;
struct V_51 * V_66 = F_18 ( V_50 ) ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_54 * V_55 ;
struct V_71 * V_72 , * V_73 ;
struct V_52 * V_53 ;
void * V_74 ;
int V_75 = 64 * 64 * 4 ;
int V_56 = 0 ;
if ( ! V_63 )
return F_20 ( V_6 ) ;
V_68 = F_29 ( V_50 -> V_37 , V_62 , V_63 ) ;
if ( ! V_68 ) {
F_30 ( L_7 ) ;
return - V_76 ;
}
V_73 = F_31 ( V_68 ) ;
V_56 = F_32 ( V_73 , false ) ;
if ( V_56 )
goto V_77;
V_56 = F_33 ( V_73 , V_78 , NULL ) ;
F_34 ( V_73 ) ;
if ( V_56 )
goto V_77;
V_56 = F_35 ( V_73 , & V_74 ) ;
if ( V_56 )
goto V_79;
V_56 = F_21 ( V_6 , sizeof( * V_55 ) ,
V_57 ,
& V_53 , NULL ) ;
if ( V_56 )
goto V_80;
V_56 = F_36 ( V_6 , V_53 , sizeof( struct V_69 ) + V_75 ,
& V_72 ) ;
if ( V_56 )
goto V_81;
V_56 = F_22 ( V_53 , false ) ;
if ( V_56 )
goto V_82;
V_56 = F_35 ( V_72 , ( void * * ) & V_70 ) ;
if ( V_56 )
goto V_83;
V_70 -> V_84 . V_85 = 0 ;
V_70 -> V_84 . type = V_86 ;
V_70 -> V_84 . V_3 = 64 ;
V_70 -> V_84 . V_4 = 64 ;
V_70 -> V_84 . V_87 = V_64 ;
V_70 -> V_84 . V_88 = V_65 ;
V_70 -> V_89 = V_75 ;
V_70 -> V_90 . V_91 = 0 ;
V_70 -> V_90 . V_92 = 0 ;
V_70 -> V_90 . V_89 = V_75 ;
memcpy ( V_70 -> V_90 . V_93 , V_74 , V_75 ) ;
F_37 ( V_72 ) ;
F_37 ( V_73 ) ;
V_55 = (struct V_54 * ) F_24 ( V_6 , V_53 ) ;
V_55 -> type = V_94 ;
V_55 -> V_95 . V_96 . V_97 . V_24 = V_66 -> V_98 ;
V_55 -> V_95 . V_96 . V_97 . V_26 = V_66 -> V_99 ;
V_55 -> V_95 . V_96 . V_100 = F_38 ( V_6 , V_72 , 0 ) ;
V_55 -> V_95 . V_96 . V_101 = 1 ;
F_25 ( V_6 , V_53 , & V_55 -> V_59 ) ;
F_26 ( V_6 , V_53 , V_60 , false ) ;
F_27 ( V_53 ) ;
V_56 = F_32 ( V_73 , false ) ;
if ( ! V_56 ) {
F_39 ( V_73 ) ;
F_34 ( V_73 ) ;
}
F_40 ( V_68 ) ;
F_41 ( & V_72 ) ;
return V_56 ;
V_83:
F_42 ( V_53 ) ;
V_82:
F_41 ( & V_72 ) ;
V_81:
F_23 ( V_6 , V_53 ) ;
V_80:
F_37 ( V_73 ) ;
V_79:
F_39 ( V_73 ) ;
V_77:
F_40 ( V_68 ) ;
return V_56 ;
}
static int F_43 ( struct V_49 * V_50 ,
int V_24 , int V_26 )
{
struct V_36 * V_37 = V_50 -> V_37 ;
struct V_5 * V_6 = V_37 -> V_38 ;
struct V_51 * V_66 = F_18 ( V_50 ) ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_56 ;
V_56 = F_21 ( V_6 , sizeof( * V_55 ) , V_57 ,
& V_53 , NULL ) ;
if ( V_56 )
return V_56 ;
V_56 = F_22 ( V_53 , true ) ;
if ( V_56 ) {
F_23 ( V_6 , V_53 ) ;
return V_56 ;
}
V_66 -> V_98 = V_24 ;
V_66 -> V_99 = V_26 ;
V_55 = (struct V_54 * ) F_24 ( V_6 , V_53 ) ;
V_55 -> type = V_102 ;
V_55 -> V_95 . V_97 . V_24 = V_66 -> V_98 ;
V_55 -> V_95 . V_97 . V_26 = V_66 -> V_99 ;
F_25 ( V_6 , V_53 , & V_55 -> V_59 ) ;
F_26 ( V_6 , V_53 , V_60 , false ) ;
F_27 ( V_53 ) ;
return 0 ;
}
static void F_44 ( struct V_103 * V_104 )
{
struct V_105 * V_106 = F_45 ( V_104 ) ;
if ( V_106 -> V_68 )
F_40 ( V_106 -> V_68 ) ;
F_46 ( V_104 ) ;
F_3 ( V_106 ) ;
}
static int F_47 ( struct V_103 * V_104 ,
struct V_61 * V_62 ,
unsigned V_32 , unsigned V_107 ,
struct V_108 * V_109 ,
unsigned V_110 )
{
struct V_105 * V_106 = F_45 ( V_104 ) ;
struct V_5 * V_6 = V_106 -> V_111 . V_37 -> V_38 ;
struct V_108 V_112 ;
struct V_71 * V_113 ;
int V_114 = 1 ;
V_113 = F_31 ( V_106 -> V_68 ) ;
if ( ! V_113 -> V_115 )
return 0 ;
if ( ! V_110 ) {
V_110 = 1 ;
V_109 = & V_112 ;
V_112 . V_116 = V_112 . y1 = 0 ;
V_112 . V_117 = V_104 -> V_3 ;
V_112 . V_118 = V_104 -> V_4 ;
} else if ( V_32 & V_119 ) {
V_110 /= 2 ;
V_114 = 2 ;
}
F_48 ( V_6 , V_106 , V_113 , V_32 , V_107 ,
V_109 , V_110 , V_114 ) ;
return 0 ;
}
int
F_49 ( struct V_36 * V_37 ,
struct V_105 * V_120 ,
struct V_121 * V_122 ,
struct V_67 * V_68 )
{
int V_56 ;
V_120 -> V_68 = V_68 ;
V_56 = F_50 ( V_37 , & V_120 -> V_111 , & V_123 ) ;
if ( V_56 ) {
V_120 -> V_68 = NULL ;
return V_56 ;
}
F_51 ( & V_120 -> V_111 , V_122 ) ;
return 0 ;
}
static void F_52 ( struct V_49 * V_50 , int V_44 )
{
}
static bool F_53 ( struct V_49 * V_50 ,
const struct V_43 * V_44 ,
struct V_43 * V_124 )
{
struct V_36 * V_37 = V_50 -> V_37 ;
struct V_5 * V_6 = V_37 -> V_38 ;
F_5 ( V_6 , L_8 ,
V_11 ,
V_44 -> V_125 , V_44 -> V_126 ,
V_124 -> V_125 ,
V_124 -> V_126 ) ;
return true ;
}
void
F_54 ( struct V_5 * V_6 )
{
int V_12 ;
F_55 ( ! V_6 -> V_127 -> V_18 ) ;
if ( V_6 -> V_18 -> V_7 == 0 ) {
F_5 ( V_6 , L_9 , V_11 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_6 -> V_18 -> V_7 ; ++ V_12 ) {
struct V_1 * V_2 = & V_6 -> V_18 -> V_22 [ V_12 ] ;
if ( V_2 -> V_26 > 8192 || V_2 -> V_24 > 8192 ||
V_2 -> V_3 > 8192 || V_2 -> V_4 > 8192 ) {
F_30 ( L_10 ,
V_12 , V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_24 , V_2 -> V_26 ) ;
return;
}
}
F_56 ( V_6 ) ;
}
static void F_57 ( struct V_5 * V_6 ,
int V_42 ,
unsigned V_24 , unsigned V_26 ,
unsigned V_3 , unsigned V_4 ,
unsigned V_128 )
{
F_8 ( L_11 , V_42 , V_3 , V_4 , V_24 , V_26 ) ;
V_6 -> V_18 -> V_22 [ V_42 ] . V_24 = V_24 ;
V_6 -> V_18 -> V_22 [ V_42 ] . V_26 = V_26 ;
V_6 -> V_18 -> V_22 [ V_42 ] . V_3 = V_3 ;
V_6 -> V_18 -> V_22 [ V_42 ] . V_4 = V_4 ;
V_6 -> V_18 -> V_22 [ V_42 ] . V_30 = V_128 ;
}
static int F_58 ( struct V_49 * V_50 ,
struct V_43 * V_44 ,
struct V_43 * V_124 ,
int V_24 , int V_26 ,
struct V_103 * V_129 )
{
struct V_36 * V_37 = V_50 -> V_37 ;
struct V_5 * V_6 = V_37 -> V_38 ;
struct V_130 * V_131 = ( void * ) V_44 -> V_132 ;
struct V_105 * V_120 ;
struct V_71 * V_133 , * V_134 = NULL ;
struct V_51 * V_66 = F_18 ( V_50 ) ;
T_1 V_3 , V_4 , V_135 ;
bool V_136 = false ;
int V_56 ;
int V_128 ;
if ( ! V_50 -> V_104 ) {
F_8 ( L_12 ) ;
return 0 ;
}
if ( V_129 ) {
V_120 = F_45 ( V_129 ) ;
V_134 = F_31 ( V_120 -> V_68 ) ;
}
V_120 = F_45 ( V_50 -> V_104 ) ;
V_133 = F_31 ( V_120 -> V_68 ) ;
if ( ! V_131 )
F_59 ( L_13 , V_24 , V_26 ) ;
else
F_59 ( L_14 ,
V_44 -> V_125 , V_44 -> V_126 , V_131 -> V_31 ) ;
F_59 ( L_15 ,
V_24 , V_26 ,
V_44 -> V_125 , V_44 -> V_126 ,
V_124 -> V_125 ,
V_124 -> V_126 ) ;
if ( V_66 -> V_42 == 0 )
V_136 = true ;
V_3 = V_44 -> V_125 ;
V_4 = V_44 -> V_126 ;
V_135 = 0 ;
V_56 = F_32 ( V_133 , false ) ;
if ( V_56 != 0 )
return V_56 ;
V_56 = F_33 ( V_133 , V_133 -> type , NULL ) ;
if ( V_56 != 0 ) {
F_34 ( V_133 ) ;
return - V_137 ;
}
F_34 ( V_133 ) ;
if ( V_136 ) {
F_60 ( V_6 ) ;
F_5 ( V_6 ,
L_16 ,
V_3 , V_4 , V_133 -> V_138 . V_3 ,
V_133 -> V_138 . V_4 , V_133 -> V_138 . V_139 , V_133 -> V_138 . V_140 ) ;
F_61 ( V_6 , V_135 , V_133 ) ;
V_133 -> V_115 = true ;
V_128 = 0 ;
} else {
V_128 = V_133 -> V_30 ;
}
if ( V_134 && V_134 != V_133 ) {
V_134 -> V_115 = false ;
V_56 = F_32 ( V_134 , false ) ;
F_39 ( V_134 ) ;
F_34 ( V_134 ) ;
}
F_57 ( V_6 , V_66 -> V_42 , V_24 , V_26 ,
V_44 -> V_125 ,
V_44 -> V_126 , V_128 ) ;
return 0 ;
}
static void F_62 ( struct V_49 * V_50 )
{
F_59 ( L_17 ,
V_50 -> V_44 . V_125 , V_50 -> V_44 . V_126 ,
V_50 -> V_24 , V_50 -> V_26 , V_50 -> V_141 ) ;
}
static void F_63 ( struct V_49 * V_50 )
{
F_59 ( L_18 ) ;
}
static void F_64 ( struct V_49 * V_50 )
{
struct V_51 * V_66 = F_18 ( V_50 ) ;
struct V_36 * V_37 = V_50 -> V_37 ;
struct V_5 * V_6 = V_37 -> V_38 ;
if ( V_50 -> V_104 ) {
struct V_105 * V_120 = F_45 ( V_50 -> V_104 ) ;
struct V_71 * V_133 = F_31 ( V_120 -> V_68 ) ;
int V_56 ;
V_56 = F_32 ( V_133 , false ) ;
F_39 ( V_133 ) ;
F_34 ( V_133 ) ;
V_50 -> V_104 = NULL ;
}
F_57 ( V_6 , V_66 -> V_42 , 0 , 0 , 0 , 0 , 0 ) ;
F_54 ( V_6 ) ;
}
static int F_65 ( struct V_36 * V_37 , int V_142 )
{
struct V_51 * V_51 ;
V_51 = F_4 ( sizeof( struct V_51 ) , V_10 ) ;
if ( ! V_51 )
return - V_143 ;
F_66 ( V_37 , & V_51 -> V_111 , & V_144 ) ;
V_51 -> V_42 = V_142 ;
F_67 ( & V_51 -> V_111 , 256 ) ;
F_68 ( & V_51 -> V_111 , & V_145 ) ;
return 0 ;
}
static void F_69 ( struct V_146 * V_147 , int V_44 )
{
F_59 ( L_18 ) ;
}
static bool F_70 ( struct V_146 * V_147 ,
const struct V_43 * V_44 ,
struct V_43 * V_124 )
{
F_59 ( L_18 ) ;
return true ;
}
static void F_71 ( struct V_146 * V_147 )
{
F_59 ( L_18 ) ;
}
static void F_72 ( struct V_5 * V_6 ,
struct V_146 * V_147 )
{
int V_12 ;
struct V_39 * V_40 = F_73 ( V_147 ) ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
F_55 ( ! V_147 ) ;
V_12 = V_40 -> V_42 ;
if ( ! V_6 -> V_18 ||
V_6 -> V_18 -> V_19 <= V_12 ) {
F_30 (
L_19 ,
V_6 -> V_18 ,
V_6 -> V_18 ?
V_6 -> V_18 -> V_19 : - 1 ) ;
return;
}
if ( ! V_147 -> V_50 ) {
F_30 ( L_20 , V_147 ) ;
return;
}
if ( V_12 != 0 )
F_59 ( L_21 ) ;
V_2 = & V_6 -> V_18 -> V_22 [ V_12 ] ;
V_2 -> V_31 = V_12 ;
if ( V_147 -> V_50 -> V_141 ) {
V_44 = & V_147 -> V_50 -> V_44 ;
V_2 -> V_3 = V_44 -> V_125 ;
V_2 -> V_4 = V_44 -> V_126 ;
V_2 -> V_24 = V_147 -> V_50 -> V_24 ;
V_2 -> V_26 = V_147 -> V_50 -> V_26 ;
if ( V_6 -> V_18 -> V_7 < V_12 + 1 )
V_6 -> V_18 -> V_7 = V_12 + 1 ;
} else {
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_26 = 0 ;
}
F_8 ( L_22 ,
V_12 , V_2 -> V_24 , V_2 -> V_26 , V_2 -> V_3 , V_2 -> V_4 , V_6 -> V_18 -> V_7 ) ;
V_2 -> V_32 = 0 ;
F_54 ( V_6 ) ;
}
static void F_74 ( struct V_146 * V_147 )
{
struct V_5 * V_6 = V_147 -> V_37 -> V_38 ;
F_72 ( V_6 , V_147 ) ;
F_59 ( L_18 ) ;
}
static void F_75 ( struct V_146 * V_147 ,
struct V_43 * V_44 ,
struct V_43 * V_124 )
{
F_59 ( L_18 ) ;
}
static int F_76 ( struct V_34 * V_35 )
{
int V_56 = 0 ;
struct V_5 * V_6 = V_35 -> V_37 -> V_38 ;
F_8 ( L_23 , V_6 -> V_18 ) ;
if ( V_6 -> V_18 && V_6 -> V_18 -> V_7 ) {
V_56 = F_11 ( V_35 ) ;
if ( V_56 < 0 )
return V_56 ;
}
V_56 += F_15 ( V_35 ) ;
return V_56 ;
}
static int F_77 ( struct V_34 * V_35 ,
struct V_43 * V_44 )
{
F_59 ( L_24 , V_44 -> V_148 , V_44 -> V_125 ,
V_44 -> V_126 , V_44 -> V_149 ) ;
return V_150 ;
}
static struct V_146 * F_78 ( struct V_34 * V_35 )
{
struct V_39 * V_39 =
F_12 ( V_35 ) ;
F_59 ( L_18 ) ;
return & V_39 -> V_151 ;
}
static void F_79 ( struct V_34 * V_35 )
{
F_59 ( L_18 ) ;
}
static void F_80 ( struct V_34 * V_35 )
{
F_59 ( L_18 ) ;
}
static enum V_152 F_81 (
struct V_34 * V_35 ,
bool V_153 )
{
struct V_39 * V_40 =
F_12 ( V_35 ) ;
struct V_36 * V_33 = V_35 -> V_37 ;
struct V_5 * V_6 = V_33 -> V_38 ;
int V_154 ;
V_154 = ( V_40 -> V_42 == 0 ) ||
( V_6 -> V_8 &&
V_6 -> V_8 -> V_7 > V_40 -> V_42 &&
F_1 ( & V_6 -> V_8 -> V_22 [ V_40 -> V_42 ] ) ) ;
F_59 ( L_18 ) ;
return V_154 ? V_155
: V_156 ;
}
static int F_82 ( struct V_34 * V_35 ,
struct V_157 * V_158 ,
T_3 V_159 )
{
F_59 ( L_18 ) ;
return 0 ;
}
static void F_83 ( struct V_34 * V_35 )
{
struct V_39 * V_39 =
F_12 ( V_35 ) ;
F_84 ( V_35 ) ;
F_85 ( V_35 ) ;
F_3 ( V_39 ) ;
}
static void F_86 ( struct V_146 * V_147 )
{
F_87 ( V_147 ) ;
}
static int F_88 ( struct V_36 * V_37 , int V_160 )
{
struct V_39 * V_39 ;
struct V_34 * V_35 ;
struct V_146 * V_147 ;
V_39 = F_4 ( sizeof( struct V_39 ) , V_10 ) ;
if ( ! V_39 )
return - V_143 ;
V_39 -> V_42 = V_160 ;
V_35 = & V_39 -> V_111 ;
V_147 = & V_39 -> V_151 ;
F_89 ( V_37 , & V_39 -> V_111 ,
& V_161 , V_162 ) ;
F_90 ( V_37 , & V_39 -> V_151 , & V_163 ,
V_164 ) ;
V_35 -> V_165 = V_166 ;
V_147 -> V_167 = 1 << V_160 ;
F_91 ( & V_39 -> V_111 ,
& V_39 -> V_151 ) ;
F_92 ( V_147 , & V_168 ) ;
F_93 ( V_35 , & V_169 ) ;
F_94 ( V_35 ) ;
return 0 ;
}
static struct V_103 *
F_95 ( struct V_36 * V_37 ,
struct V_61 * V_62 ,
struct V_121 * V_122 )
{
struct V_67 * V_68 ;
struct V_105 * V_106 ;
int V_56 ;
V_68 = F_29 ( V_37 , V_62 , V_122 -> V_170 [ 0 ] ) ;
V_106 = F_4 ( sizeof( * V_106 ) , V_10 ) ;
if ( V_106 == NULL )
return NULL ;
V_56 = F_49 ( V_37 , V_106 , V_122 , V_68 ) ;
if ( V_56 ) {
F_3 ( V_106 ) ;
F_40 ( V_68 ) ;
return NULL ;
}
return & V_106 -> V_111 ;
}
int F_96 ( struct V_5 * V_6 )
{
int V_56 ;
struct V_67 * V_171 ;
int V_19 = V_172 ;
int V_173 = sizeof( struct V_9 ) +
V_19 * sizeof( struct V_1 ) ;
V_56 = F_97 ( V_6 , V_173 , 0 ,
V_174 ,
false , false , NULL , & V_171 ) ;
if ( V_56 ) {
F_30 ( L_25 , V_11 , V_56 ) ;
return - V_143 ;
}
V_6 -> V_175 = F_31 ( V_171 ) ;
V_56 = F_32 ( V_6 -> V_175 , false ) ;
if ( V_56 )
return V_56 ;
V_56 = F_33 ( V_6 -> V_175 , V_174 , NULL ) ;
if ( V_56 ) {
F_34 ( V_6 -> V_175 ) ;
return V_56 ;
}
F_34 ( V_6 -> V_175 ) ;
F_35 ( V_6 -> V_175 , NULL ) ;
V_6 -> V_18 = V_6 -> V_175 -> V_176 ;
V_6 -> V_127 -> V_18 =
F_38 ( V_6 , V_6 -> V_175 , 0 ) ;
memset ( V_6 -> V_18 , 0 , V_173 ) ;
V_6 -> V_18 -> V_19 = V_19 ;
return 0 ;
}
int F_98 ( struct V_5 * V_6 )
{
int V_56 ;
V_6 -> V_18 = NULL ;
V_6 -> V_127 -> V_18 = 0 ;
F_37 ( V_6 -> V_175 ) ;
V_56 = F_32 ( V_6 -> V_175 , false ) ;
if ( V_56 )
return V_56 ;
F_39 ( V_6 -> V_175 ) ;
F_34 ( V_6 -> V_175 ) ;
F_41 ( & V_6 -> V_175 ) ;
return 0 ;
}
int F_99 ( struct V_5 * V_6 )
{
int V_12 ;
int V_56 ;
F_100 ( V_6 -> V_33 ) ;
V_56 = F_96 ( V_6 ) ;
if ( V_56 )
return V_56 ;
V_6 -> V_33 -> V_177 . V_178 = ( void * ) & V_179 ;
V_6 -> V_33 -> V_177 . V_180 = 320 ;
V_6 -> V_33 -> V_177 . V_181 = 200 ;
V_6 -> V_33 -> V_177 . V_182 = 8192 ;
V_6 -> V_33 -> V_177 . V_183 = 8192 ;
V_6 -> V_33 -> V_177 . V_184 = V_6 -> V_185 ;
for ( V_12 = 0 ; V_12 < V_172 ; ++ V_12 ) {
F_65 ( V_6 -> V_33 , V_12 ) ;
F_88 ( V_6 -> V_33 , V_12 ) ;
}
V_6 -> V_186 . V_187 = true ;
F_101 ( V_6 ) ;
return 0 ;
}
void F_102 ( struct V_5 * V_6 )
{
F_103 ( V_6 ) ;
F_98 ( V_6 ) ;
if ( V_6 -> V_186 . V_187 ) {
F_104 ( V_6 -> V_33 ) ;
V_6 -> V_186 . V_187 = false ;
}
}
