static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 , * V_11 ;
int V_12 = V_6 -> V_12 ;
int V_13 = V_6 -> V_13 ;
if ( V_12 < 320 || V_13 < 240 ) {
F_2 ( V_2 , L_1 , V_12 , V_13 ) ;
V_12 = 1024 ;
V_13 = 768 ;
}
if ( V_12 * V_13 * 4 > 16 * 1024 * 1024 ) {
V_12 = 1024 ;
V_13 = 768 ;
}
F_3 (mode, t, &connector->probed_modes, head)
F_4 ( V_4 , V_10 ) ;
V_10 = F_5 ( V_8 , V_12 , V_13 , 60 , false , false , false ) ;
V_10 -> type |= V_14 ;
V_10 -> V_15 = V_16 ;
F_6 ( V_4 , V_10 ) ;
F_2 ( V_2 , L_2 , V_17 , V_12 , V_13 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_18 ;
struct V_7 * V_8 = V_2 -> V_19 ;
V_18 = 0 ;
F_2 ( V_2 , L_3 , V_17 ,
V_8 -> V_20 . V_21 ,
V_2 -> V_22 -> V_23 ) ;
F_8 (connector, &dev->mode_config.connector_list, head) {
if ( V_18 > V_2 -> V_22 -> V_23 ) {
continue;
}
F_1 ( V_2 , V_4 ,
& V_2 -> V_22 -> V_24 [ V_18 ] ) ;
++ V_18 ;
}
}
void F_9 ( struct V_1 * V_2 , unsigned V_23 )
{
if ( V_2 -> V_25 &&
V_23 > V_2 -> V_25 -> V_23 ) {
F_10 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
}
if ( ! V_2 -> V_25 ) {
V_2 -> V_25 = F_11 (
sizeof( struct V_26 ) +
sizeof( struct V_5 ) * V_23 , V_27 ) ;
if ( ! V_2 -> V_25 ) {
F_2 ( V_2 ,
L_4 ,
V_17 , V_23 ) ;
return;
}
}
V_2 -> V_25 -> V_23 = V_23 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_18 ;
int V_28 ;
T_1 V_29 ;
F_13 ( ! V_2 -> V_22 ) ;
V_28 = V_2 -> V_30 -> V_25 . V_23 ;
V_29 = F_14 ( 0 , ( const V_31 * ) & V_2 -> V_30 -> V_25 ,
sizeof( V_2 -> V_30 -> V_25 ) ) ;
if ( V_29 != V_2 -> V_30 -> V_32 ) {
F_2 ( V_2 , L_5 , V_29 ,
sizeof( V_2 -> V_30 -> V_25 ) ,
V_2 -> V_30 -> V_32 ) ;
return 1 ;
}
if ( V_28 > V_2 -> V_22 -> V_33 ) {
F_15 ( L_6 ,
V_2 -> V_22 -> V_33 , V_28 ) ;
V_28 = V_2 -> V_22 -> V_33 ;
} else {
V_28 = V_2 -> V_30 -> V_25 . V_23 ;
}
F_9 ( V_2 , V_28 ) ;
V_2 -> V_25 -> V_33 =
V_2 -> V_22 -> V_33 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_25 -> V_23 ; ++ V_18 ) {
struct V_34 * V_35 =
& V_2 -> V_30 -> V_25 . V_24 [ V_18 ] ;
struct V_5 * V_36 =
& V_2 -> V_25 -> V_24 [ V_18 ] ;
struct V_5 * V_6 = & V_2 -> V_22 -> V_24 [ V_18 ] ;
V_36 -> V_37 = V_6 -> V_37 = V_35 -> V_38 ;
V_36 -> V_39 = V_6 -> V_39 = V_35 -> V_40 ;
V_36 -> V_12 = V_6 -> V_12 =
V_35 -> V_41 - V_35 -> V_38 ;
V_36 -> V_13 = V_6 -> V_13 =
V_35 -> V_42 - V_35 -> V_40 ;
V_36 -> V_43 = V_6 -> V_43 = 0 ;
V_36 -> V_44 = V_6 -> V_44 = V_18 ;
V_36 -> V_45 = V_6 -> V_45 = 0 ;
F_16 ( V_2 , L_7 , V_6 -> V_12 , V_6 -> V_13 ,
V_6 -> V_37 , V_6 -> V_39 ) ;
}
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
while ( F_12 ( V_2 ) ) {
F_2 ( V_2 , L_8
L_9 ) ;
}
F_7 ( V_2 ) ;
F_2 ( V_2 , L_10 ) ;
F_18 ( V_2 -> V_19 ) ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_46 ;
struct V_47 * V_48 = F_20 ( V_4 ) ;
int V_49 = V_48 -> V_50 ;
struct V_9 * V_10 = NULL ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_22 )
return 0 ;
V_6 = & V_2 -> V_22 -> V_24 [ V_49 ] ;
V_10 = F_5 ( V_8 , V_6 -> V_12 , V_6 -> V_13 , 60 , false , false ,
false ) ;
V_10 -> type |= V_14 ;
F_6 ( V_4 , V_10 ) ;
return 1 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 = NULL ;
int V_18 ;
struct V_51 {
int V_52 ;
int V_49 ;
} V_53 [] = {
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
for ( V_18 = 0 ; V_18 < F_22 ( V_53 ) ; V_18 ++ ) {
if ( V_53 [ V_18 ] . V_52 < 320 || V_53 [ V_18 ] . V_49 < 200 )
continue;
V_10 = F_5 ( V_8 , V_53 [ V_18 ] . V_52 , V_53 [ V_18 ] . V_49 ,
60 , false , false , false ) ;
if ( V_53 [ V_18 ] . V_52 == 1024 && V_53 [ V_18 ] . V_49 == 768 )
V_10 -> type |= V_14 ;
F_6 ( V_4 , V_10 ) ;
}
return V_18 - 1 ;
}
static void F_23 ( struct V_54 * V_55 , T_2 * V_56 , T_2 * V_57 ,
T_2 * V_58 , T_1 V_59 , T_1 V_60 )
{
}
static void F_24 ( struct V_54 * V_55 )
{
struct V_61 * V_61 = F_25 ( V_55 ) ;
F_26 ( V_55 ) ;
F_10 ( V_61 ) ;
}
static void
F_27 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
int V_66 ;
V_66 = F_28 ( V_2 , sizeof( * V_65 ) , V_67 ,
& V_63 , NULL ) ;
V_65 = (struct V_64 * ) F_29 ( V_2 , V_63 ) ;
V_65 -> type = V_68 ;
F_30 ( V_2 , V_63 , & V_65 -> V_69 ) ;
F_31 ( V_2 , V_63 ) ;
F_32 ( V_2 , V_63 , V_70 , false ) ;
F_33 ( V_2 , V_63 ) ;
}
static int F_34 ( struct V_54 * V_55 ,
struct V_71 * V_72 ,
T_1 V_73 ,
T_1 V_12 ,
T_1 V_13 )
{
struct V_7 * V_8 = V_55 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_46 ;
struct V_61 * V_74 = F_25 ( V_55 ) ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_64 * V_65 ;
struct V_79 * V_80 , * V_81 ;
struct V_62 * V_63 ;
void * V_82 ;
int V_60 = 64 * 64 * 4 ;
int V_66 = 0 ;
if ( ! V_73 ) {
F_27 ( V_2 ) ;
return 0 ;
}
V_76 = F_35 ( V_55 -> V_8 , V_72 , V_73 ) ;
if ( ! V_76 ) {
F_36 ( L_11 ) ;
return - V_83 ;
}
V_81 = F_37 ( V_76 ) ;
V_66 = F_38 ( V_81 , false ) ;
if ( V_66 )
goto V_84;
V_66 = F_39 ( V_81 , V_85 , NULL ) ;
if ( V_66 )
goto V_86;
V_66 = F_40 ( V_81 , & V_82 ) ;
if ( V_66 )
goto V_87;
V_66 = F_28 ( V_2 , sizeof( * V_65 ) ,
V_67 ,
& V_63 , NULL ) ;
if ( V_66 )
goto V_88;
V_66 = F_41 ( V_2 , sizeof( struct V_77 ) + V_60 ,
& V_80 ) ;
if ( V_66 )
goto V_89;
V_66 = F_40 ( V_80 , ( void * * ) & V_78 ) ;
if ( V_66 )
goto V_90;
V_78 -> V_91 . V_92 = 0 ;
V_78 -> V_91 . type = V_93 ;
V_78 -> V_91 . V_12 = 64 ;
V_78 -> V_91 . V_13 = 64 ;
V_78 -> V_91 . V_94 = 0 ;
V_78 -> V_91 . V_95 = 0 ;
V_78 -> V_96 = V_60 ;
V_78 -> V_97 . V_98 = 0 ;
V_78 -> V_97 . V_99 = 0 ;
V_78 -> V_97 . V_96 = V_60 ;
memcpy ( V_78 -> V_97 . V_100 , V_82 , V_60 ) ;
F_42 ( V_80 ) ;
F_42 ( V_81 ) ;
F_43 ( V_81 ) ;
F_44 ( V_81 ) ;
F_45 ( V_76 ) ;
V_65 = (struct V_64 * ) F_29 ( V_2 , V_63 ) ;
V_65 -> type = V_101 ;
V_65 -> V_102 . V_103 . V_104 . V_37 = V_74 -> V_105 ;
V_65 -> V_102 . V_103 . V_104 . V_39 = V_74 -> V_106 ;
V_65 -> V_102 . V_103 . V_107 = F_46 ( V_2 , V_80 , 0 ) ;
F_47 ( V_2 , V_63 , V_80 ) ;
V_65 -> V_102 . V_103 . V_108 = 1 ;
F_30 ( V_2 , V_63 , & V_65 -> V_69 ) ;
F_31 ( V_2 , V_63 ) ;
F_32 ( V_2 , V_63 , V_70 , false ) ;
F_33 ( V_2 , V_63 ) ;
F_44 ( V_80 ) ;
F_48 ( & V_80 ) ;
return V_66 ;
V_90:
F_48 ( & V_80 ) ;
V_89:
F_33 ( V_2 , V_63 ) ;
F_49 ( V_2 , V_63 ) ;
V_88:
F_42 ( V_81 ) ;
V_87:
F_43 ( V_81 ) ;
V_86:
F_44 ( V_81 ) ;
V_84:
F_45 ( V_76 ) ;
return V_66 ;
}
static int F_50 ( struct V_54 * V_55 ,
int V_37 , int V_39 )
{
struct V_7 * V_8 = V_55 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_46 ;
struct V_61 * V_74 = F_25 ( V_55 ) ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
int V_66 ;
V_66 = F_28 ( V_2 , sizeof( * V_65 ) , V_67 ,
& V_63 , NULL ) ;
V_74 -> V_105 = V_37 ;
V_74 -> V_106 = V_39 ;
V_65 = (struct V_64 * ) F_29 ( V_2 , V_63 ) ;
V_65 -> type = V_109 ;
V_65 -> V_102 . V_104 . V_37 = V_74 -> V_105 ;
V_65 -> V_102 . V_104 . V_39 = V_74 -> V_106 ;
F_30 ( V_2 , V_63 , & V_65 -> V_69 ) ;
F_31 ( V_2 , V_63 ) ;
F_32 ( V_2 , V_63 , V_70 , false ) ;
F_33 ( V_2 , V_63 ) ;
return 0 ;
}
static void F_51 ( struct V_110 * V_111 )
{
struct V_112 * V_113 = F_52 ( V_111 ) ;
if ( V_113 -> V_76 )
F_45 ( V_113 -> V_76 ) ;
F_53 ( V_111 ) ;
F_10 ( V_113 ) ;
}
static int F_54 ( struct V_110 * V_111 ,
struct V_71 * V_72 ,
unsigned V_45 , unsigned V_114 ,
struct V_115 * V_116 ,
unsigned V_117 )
{
struct V_112 * V_113 = F_52 ( V_111 ) ;
struct V_1 * V_2 = V_113 -> V_118 . V_8 -> V_46 ;
struct V_115 V_119 ;
struct V_79 * V_120 ;
int V_121 = 1 ;
V_120 = F_37 ( V_113 -> V_76 ) ;
if ( ! V_120 -> V_122 )
return 0 ;
if ( ! V_117 ) {
V_117 = 1 ;
V_116 = & V_119 ;
V_119 . V_123 = V_119 . y1 = 0 ;
V_119 . V_124 = V_111 -> V_12 ;
V_119 . V_125 = V_111 -> V_13 ;
} else if ( V_45 & V_126 ) {
V_117 /= 2 ;
V_121 = 2 ;
}
F_55 ( V_2 , V_113 , V_120 , V_45 , V_114 ,
V_116 , V_117 , V_121 ) ;
return 0 ;
}
int
F_56 ( struct V_7 * V_8 ,
struct V_112 * V_127 ,
struct V_128 * V_129 ,
struct V_75 * V_76 )
{
int V_66 ;
V_127 -> V_76 = V_76 ;
V_66 = F_57 ( V_8 , & V_127 -> V_118 , & V_130 ) ;
if ( V_66 ) {
V_127 -> V_76 = NULL ;
return V_66 ;
}
F_58 ( & V_127 -> V_118 , V_129 ) ;
return 0 ;
}
static void F_59 ( struct V_54 * V_55 , int V_10 )
{
}
static bool F_60 ( struct V_54 * V_55 ,
const struct V_9 * V_10 ,
struct V_9 * V_131 )
{
struct V_7 * V_8 = V_55 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_46 ;
F_2 ( V_2 , L_12 ,
V_17 ,
V_10 -> V_132 , V_10 -> V_133 ,
V_131 -> V_132 ,
V_131 -> V_133 ) ;
return true ;
}
void
F_61 ( struct V_1 * V_2 )
{
int V_18 ;
F_13 ( ! V_2 -> V_134 -> V_22 ) ;
if ( V_2 -> V_22 -> V_23 == 0 ) {
F_2 ( V_2 , L_13 , V_17 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_22 -> V_23 ; ++ V_18 ) {
struct V_5 * V_6 = & V_2 -> V_22 -> V_24 [ V_18 ] ;
if ( V_6 -> V_39 > 8192 || V_6 -> V_39 < V_6 -> V_37 ||
V_6 -> V_12 > 8192 || V_6 -> V_13 > 8192 ) {
F_36 ( L_14 ,
V_18 , V_6 -> V_12 , V_6 -> V_13 ,
V_6 -> V_37 , V_6 -> V_39 ) ;
return;
}
}
F_62 ( V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
unsigned V_37 , unsigned V_39 ,
unsigned V_12 , unsigned V_13 )
{
F_64 ( L_15 , V_12 , V_13 , V_37 , V_39 ) ;
V_2 -> V_22 -> V_23 = 1 ;
V_2 -> V_22 -> V_24 [ 0 ] . V_37 = V_37 ;
V_2 -> V_22 -> V_24 [ 0 ] . V_39 = V_39 ;
V_2 -> V_22 -> V_24 [ 0 ] . V_12 = V_12 ;
V_2 -> V_22 -> V_24 [ 0 ] . V_13 = V_13 ;
}
static int F_65 ( struct V_54 * V_55 ,
struct V_9 * V_10 ,
struct V_9 * V_131 ,
int V_37 , int V_39 ,
struct V_110 * V_135 )
{
struct V_7 * V_8 = V_55 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_46 ;
struct V_136 * V_137 = ( void * ) V_10 -> V_138 ;
struct V_112 * V_127 ;
struct V_79 * V_139 , * V_140 = NULL ;
T_1 V_12 , V_13 , V_141 ;
bool V_142 = false ;
int V_66 ;
if ( ! V_55 -> V_111 ) {
F_66 ( L_16 ) ;
return 0 ;
}
if ( V_135 ) {
V_127 = F_52 ( V_135 ) ;
V_140 = F_37 ( V_127 -> V_76 ) ;
}
V_127 = F_52 ( V_55 -> V_111 ) ;
V_139 = F_37 ( V_127 -> V_76 ) ;
if ( ! V_137 )
F_64 ( L_17 , V_37 , V_39 ) ;
else
F_64 ( L_18 ,
V_10 -> V_132 , V_10 -> V_133 , V_137 -> V_44 ) ;
F_64 ( L_19 ,
V_37 , V_39 ,
V_10 -> V_132 , V_10 -> V_133 ,
V_131 -> V_132 ,
V_131 -> V_133 ) ;
V_142 = true ;
V_12 = V_10 -> V_132 ;
V_13 = V_10 -> V_133 ;
V_141 = 0 ;
V_66 = F_38 ( V_139 , false ) ;
if ( V_66 != 0 )
return V_66 ;
V_66 = F_39 ( V_139 , V_139 -> type , NULL ) ;
if ( V_66 != 0 ) {
F_44 ( V_139 ) ;
return - V_143 ;
}
F_44 ( V_139 ) ;
if ( V_142 ) {
F_67 ( V_2 ) ;
F_2 ( V_2 ,
L_20 ,
V_12 , V_13 , V_139 -> V_144 . V_12 ,
V_139 -> V_144 . V_13 , V_139 -> V_144 . V_145 , V_139 -> V_144 . V_146 ) ;
F_68 ( V_2 , V_12 , V_13 , V_141 , V_139 ) ;
V_139 -> V_122 = true ;
}
if ( V_140 && V_140 != V_139 ) {
V_140 -> V_122 = false ;
V_66 = F_38 ( V_140 , false ) ;
F_43 ( V_140 ) ;
F_44 ( V_140 ) ;
}
if ( V_2 -> V_22 -> V_23 == 0 ) {
F_63 ( V_2 , V_37 , V_39 ,
V_10 -> V_132 ,
V_10 -> V_133 ) ;
}
return 0 ;
}
static void F_69 ( struct V_54 * V_55 )
{
F_64 ( L_21 ,
V_55 -> V_10 . V_132 , V_55 -> V_10 . V_133 ,
V_55 -> V_37 , V_55 -> V_39 , V_55 -> V_147 ) ;
}
static void F_70 ( struct V_54 * V_55 )
{
F_64 ( L_22 ) ;
}
static void F_71 ( struct V_54 * V_55 )
{
F_64 ( L_22 ) ;
}
static int F_72 ( struct V_7 * V_8 , int V_148 )
{
struct V_61 * V_61 ;
V_61 = F_11 ( sizeof( struct V_61 ) , V_27 ) ;
if ( ! V_61 )
return - V_149 ;
F_73 ( V_8 , & V_61 -> V_118 , & V_150 ) ;
F_74 ( & V_61 -> V_118 , 256 ) ;
F_75 ( & V_61 -> V_118 , & V_151 ) ;
return 0 ;
}
static void F_76 ( struct V_152 * V_153 , int V_10 )
{
F_64 ( L_22 ) ;
}
static bool F_77 ( struct V_152 * V_153 ,
const struct V_9 * V_10 ,
struct V_9 * V_131 )
{
F_64 ( L_22 ) ;
return true ;
}
static void F_78 ( struct V_152 * V_153 )
{
F_64 ( L_22 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
int V_18 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
F_13 ( ! V_153 ) ;
for ( V_18 = 0 ; ( V_153 -> V_154 != ( 1 << V_18 ) ) && V_18 < 32 ; ++ V_18 )
;
if ( V_153 -> V_154 != ( 1 << V_18 ) ) {
F_36 ( L_23 ,
V_153 -> V_154 ) ;
return;
}
if ( ! V_2 -> V_22 ||
V_2 -> V_22 -> V_33 <= V_18 ) {
F_36 (
L_24 ,
V_2 -> V_22 ,
V_2 -> V_22 ?
V_2 -> V_22 -> V_33 : - 1 ) ;
return;
}
if ( ! V_153 -> V_55 ) {
F_36 ( L_25 , V_153 ) ;
return;
}
if ( V_18 != 0 )
F_64 ( L_26 ) ;
V_6 = & V_2 -> V_22 -> V_24 [ V_18 ] ;
V_6 -> V_44 = V_18 ;
V_6 -> V_43 = 0 ;
if ( V_153 -> V_55 -> V_147 ) {
V_10 = & V_153 -> V_55 -> V_10 ;
V_6 -> V_12 = V_10 -> V_132 ;
V_6 -> V_13 = V_10 -> V_133 ;
V_6 -> V_37 = V_153 -> V_55 -> V_37 ;
V_6 -> V_39 = V_153 -> V_55 -> V_39 ;
if ( V_2 -> V_22 -> V_23 < V_18 + 1 )
V_2 -> V_22 -> V_23 = V_18 + 1 ;
} else {
V_6 -> V_12 = 0 ;
V_6 -> V_13 = 0 ;
V_6 -> V_37 = 0 ;
V_6 -> V_39 = 0 ;
}
F_64 ( L_27 ,
V_18 , V_6 -> V_37 , V_6 -> V_39 , V_6 -> V_12 , V_6 -> V_13 ) ;
V_6 -> V_45 = 0 ;
F_61 ( V_2 ) ;
}
static void F_80 ( struct V_152 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_8 -> V_46 ;
F_79 ( V_2 , V_153 ) ;
F_64 ( L_22 ) ;
}
static void F_81 ( struct V_152 * V_153 ,
struct V_9 * V_10 ,
struct V_9 * V_131 )
{
F_64 ( L_22 ) ;
}
static int F_82 ( struct V_3 * V_4 )
{
int V_66 = 0 ;
struct V_1 * V_2 = V_4 -> V_8 -> V_46 ;
F_66 ( L_28 , V_2 -> V_22 ) ;
if ( V_2 -> V_22 && V_2 -> V_22 -> V_23 ) {
V_66 = F_19 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
}
V_66 += F_21 ( V_4 ) ;
return V_66 ;
}
static int F_83 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
F_64 ( L_29 , V_10 -> V_155 , V_10 -> V_132 ,
V_10 -> V_133 , V_10 -> V_15 ) ;
return V_16 ;
}
static struct V_152 * F_84 ( struct V_3 * V_4 )
{
struct V_47 * V_47 =
F_20 ( V_4 ) ;
F_64 ( L_22 ) ;
return & V_47 -> V_156 ;
}
static void F_85 ( struct V_3 * V_4 )
{
F_64 ( L_22 ) ;
}
static void F_86 ( struct V_3 * V_4 )
{
F_64 ( L_22 ) ;
}
static enum V_157 F_87 (
struct V_3 * V_4 ,
bool V_158 )
{
struct V_47 * V_48 =
F_20 ( V_4 ) ;
struct V_7 * V_19 = V_4 -> V_8 ;
struct V_1 * V_2 = V_19 -> V_46 ;
int V_159 ;
V_159 = ( V_48 -> V_50 == 0 ) ||
( V_2 -> V_22 &&
V_2 -> V_22 -> V_23 > V_48 -> V_50 ) ;
F_64 ( L_22 ) ;
return V_159 ? V_160
: V_161 ;
}
static int F_88 ( struct V_3 * V_4 ,
struct V_162 * V_163 ,
T_3 V_164 )
{
F_64 ( L_22 ) ;
return 0 ;
}
static void F_89 ( struct V_3 * V_4 )
{
struct V_47 * V_47 =
F_20 ( V_4 ) ;
F_90 ( V_4 ) ;
F_91 ( V_4 ) ;
F_10 ( V_47 ) ;
}
static void F_92 ( struct V_152 * V_153 )
{
F_93 ( V_153 ) ;
}
static int F_94 ( struct V_7 * V_8 , int V_165 )
{
struct V_47 * V_47 ;
struct V_3 * V_4 ;
struct V_152 * V_153 ;
V_47 = F_11 ( sizeof( struct V_47 ) , V_27 ) ;
if ( ! V_47 )
return - V_149 ;
V_47 -> V_50 = V_165 ;
V_4 = & V_47 -> V_118 ;
V_153 = & V_47 -> V_156 ;
F_95 ( V_8 , & V_47 -> V_118 ,
& V_166 , V_167 ) ;
F_96 ( V_8 , & V_47 -> V_156 , & V_168 ,
V_169 ) ;
V_153 -> V_154 = 1 << V_165 ;
F_97 ( & V_47 -> V_118 ,
& V_47 -> V_156 ) ;
F_98 ( V_153 , & V_170 ) ;
F_99 ( V_4 , & V_171 ) ;
F_100 ( V_4 ) ;
return 0 ;
}
static struct V_110 *
F_101 ( struct V_7 * V_8 ,
struct V_71 * V_72 ,
struct V_128 * V_129 )
{
struct V_75 * V_76 ;
struct V_112 * V_113 ;
int V_66 ;
V_76 = F_35 ( V_8 , V_72 , V_129 -> V_172 [ 0 ] ) ;
V_113 = F_11 ( sizeof( * V_113 ) , V_27 ) ;
if ( V_113 == NULL )
return NULL ;
V_66 = F_56 ( V_8 , V_113 , V_129 , V_76 ) ;
if ( V_66 ) {
F_10 ( V_113 ) ;
F_45 ( V_76 ) ;
return NULL ;
}
return & V_113 -> V_118 ;
}
int F_102 ( struct V_1 * V_2 )
{
int V_18 ;
int V_66 ;
struct V_75 * V_173 ;
int V_33 = V_174 ;
int V_175 = sizeof( struct V_26 ) +
V_33 * sizeof( struct V_5 ) ;
F_103 ( V_2 -> V_19 ) ;
V_66 = F_104 ( V_2 , V_175 , 0 ,
V_176 ,
false , false , NULL , & V_173 ) ;
if ( V_66 ) {
F_36 ( L_30 , V_17 , V_66 ) ;
return - V_149 ;
}
V_2 -> V_177 = F_37 ( V_173 ) ;
F_40 ( V_2 -> V_177 , NULL ) ;
V_2 -> V_22 = V_2 -> V_177 -> V_178 ;
V_2 -> V_134 -> V_22 =
F_46 ( V_2 , V_2 -> V_177 , 0 ) ;
memset ( V_2 -> V_22 , 0 , V_175 ) ;
V_2 -> V_22 -> V_33 = V_33 ;
V_2 -> V_19 -> V_20 . V_179 = ( void * ) & V_180 ;
V_2 -> V_19 -> V_20 . V_181 = 320 ;
V_2 -> V_19 -> V_20 . V_182 = 200 ;
V_2 -> V_19 -> V_20 . V_183 = 8192 ;
V_2 -> V_19 -> V_20 . V_184 = 8192 ;
V_2 -> V_19 -> V_20 . V_185 = V_2 -> V_186 ;
for ( V_18 = 0 ; V_18 < V_174 ; ++ V_18 ) {
F_72 ( V_2 -> V_19 , V_18 ) ;
F_94 ( V_2 -> V_19 , V_18 ) ;
}
V_2 -> V_187 . V_188 = true ;
F_105 ( V_2 ) ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 )
{
F_107 ( V_2 ) ;
if ( V_2 -> V_187 . V_188 ) {
F_108 ( V_2 -> V_19 ) ;
V_2 -> V_187 . V_188 = false ;
}
}
