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
static void F_9 ( struct V_5 * V_6 )
{
struct V_33 * V_34 = V_6 -> V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_1 * V_2 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
V_39 = F_11 ( V_37 ) ;
V_2 = & V_6 -> V_8 -> V_22 [ V_39 -> V_40 ] ;
F_12 ( & V_37 -> V_41 ,
V_34 -> V_42 . V_43 , V_2 -> V_24 ) ;
F_12 ( & V_37 -> V_41 ,
V_34 -> V_42 . V_44 , V_2 -> V_26 ) ;
}
}
void F_13 ( struct V_5 * V_6 )
{
struct V_33 * V_34 = V_6 -> V_35 ;
while ( F_6 ( V_6 ) ) {
F_5 ( V_6 , L_5
L_6 ) ;
}
F_14 ( V_34 ) ;
F_9 ( V_6 ) ;
F_15 ( V_34 ) ;
if ( ! F_16 ( V_6 -> V_35 ) ) {
F_17 ( V_6 -> V_35 ) ;
}
}
static int F_18 ( struct V_36 * V_37 ,
unsigned * V_45 ,
unsigned * V_46 )
{
struct V_33 * V_34 = V_37 -> V_34 ;
struct V_5 * V_6 = V_34 -> V_47 ;
struct V_38 * V_39 = F_11 ( V_37 ) ;
int V_48 = V_39 -> V_40 ;
struct V_49 * V_50 = NULL ;
struct V_1 * V_2 ;
if ( ! V_6 -> V_8 )
return 0 ;
V_2 = & V_6 -> V_8 -> V_22 [ V_48 ] ;
V_50 = F_19 ( V_34 , V_2 -> V_3 , V_2 -> V_4 , 60 , false , false ,
false ) ;
V_50 -> type |= V_51 ;
* V_45 = V_2 -> V_3 ;
* V_46 = V_2 -> V_4 ;
F_20 ( V_37 , V_50 ) ;
V_6 -> V_52 = V_50 -> V_53 ;
V_6 -> V_54 = V_50 -> V_55 ;
return 1 ;
}
static int F_21 ( struct V_36 * V_37 ,
unsigned V_45 ,
unsigned V_46 )
{
struct V_33 * V_34 = V_37 -> V_34 ;
struct V_49 * V_50 = NULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_22 ( V_56 ) ; V_12 ++ ) {
V_50 = F_19 ( V_34 , V_56 [ V_12 ] . V_57 , V_56 [ V_12 ] . V_48 ,
60 , false , false , false ) ;
if ( V_56 [ V_12 ] . V_57 == V_45 && V_56 [ V_12 ] . V_48 == V_46 )
V_50 -> type |= V_51 ;
F_20 ( V_37 , V_50 ) ;
}
return V_12 - 1 ;
}
static void F_23 ( struct V_58 * V_59 )
{
struct V_60 * V_60 = F_24 ( V_59 ) ;
F_25 ( V_59 ) ;
F_3 ( V_60 ) ;
}
static int F_26 ( struct V_58 * V_59 ,
struct V_61 * V_62 ,
struct V_63 * V_64 ,
T_1 V_65 )
{
struct V_33 * V_34 = V_59 -> V_34 ;
struct V_5 * V_6 = V_34 -> V_47 ;
struct V_60 * V_66 = F_24 ( V_59 ) ;
struct V_67 * V_68 = F_27 ( V_62 ) ;
struct V_67 * V_69 = F_27 ( V_59 -> V_70 -> V_62 ) ;
struct V_71 * V_72 = F_28 ( V_69 -> V_73 ) ;
struct V_71 * V_74 = F_28 ( V_68 -> V_73 ) ;
unsigned long V_32 ;
struct V_75 V_76 = {
. V_77 = 0 ,
. y1 = 0 ,
. V_78 = V_62 -> V_3 ,
. V_79 = V_62 -> V_4
} ;
int V_80 = 1 ;
int V_81 = 1 ;
int V_82 = 0 ;
V_59 -> V_70 -> V_62 = V_62 ;
V_72 -> V_83 = false ;
V_74 -> V_83 = true ;
V_82 = F_29 ( V_74 , false ) ;
if ( V_82 )
return V_82 ;
V_82 = F_30 ( V_74 , V_74 -> type , NULL ) ;
F_31 ( V_74 ) ;
if ( V_82 )
return V_82 ;
F_32 ( V_6 , V_68 , V_74 , 0 , 0 ,
& V_76 , V_81 , V_80 ) ;
F_33 ( V_34 , V_66 -> V_40 ) ;
if ( V_64 ) {
F_34 ( & V_34 -> V_84 , V_32 ) ;
F_35 ( V_34 , V_66 -> V_40 , V_64 ) ;
F_36 ( & V_34 -> V_84 , V_32 ) ;
}
F_37 ( V_34 , V_66 -> V_40 ) ;
V_82 = F_29 ( V_74 , false ) ;
if ( ! V_82 ) {
F_38 ( V_74 ) ;
F_31 ( V_74 ) ;
}
return 0 ;
}
static int
F_39 ( struct V_5 * V_6 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
int V_82 ;
V_82 = F_40 ( V_6 , sizeof( * V_88 ) , V_89 ,
& V_86 , NULL ) ;
if ( V_82 )
return V_82 ;
V_82 = F_41 ( V_86 , true ) ;
if ( V_82 ) {
F_42 ( V_6 , V_86 ) ;
return V_82 ;
}
V_88 = (struct V_87 * ) F_43 ( V_6 , V_86 ) ;
V_88 -> type = V_90 ;
F_44 ( V_6 , V_86 , & V_88 -> V_91 ) ;
F_45 ( V_6 , V_86 , V_92 , false ) ;
F_46 ( V_86 ) ;
return 0 ;
}
static int F_47 ( struct V_58 * V_59 ,
struct V_93 * V_94 ,
T_1 V_95 ,
T_1 V_3 ,
T_1 V_4 , T_2 V_96 , T_2 V_97 )
{
struct V_33 * V_34 = V_59 -> V_34 ;
struct V_5 * V_6 = V_34 -> V_47 ;
struct V_60 * V_66 = F_24 ( V_59 ) ;
struct V_98 * V_73 ;
struct V_99 * V_100 ;
struct V_87 * V_88 ;
struct V_71 * V_101 , * V_102 ;
struct V_85 * V_86 ;
void * V_103 ;
int V_104 = 64 * 64 * 4 ;
int V_82 = 0 ;
if ( ! V_95 )
return F_39 ( V_6 ) ;
V_73 = F_48 ( V_59 -> V_34 , V_94 , V_95 ) ;
if ( ! V_73 ) {
F_49 ( L_7 ) ;
return - V_105 ;
}
V_102 = F_28 ( V_73 ) ;
V_82 = F_29 ( V_102 , false ) ;
if ( V_82 )
goto V_106;
V_82 = F_30 ( V_102 , V_107 , NULL ) ;
F_31 ( V_102 ) ;
if ( V_82 )
goto V_106;
V_82 = F_50 ( V_102 , & V_103 ) ;
if ( V_82 )
goto V_108;
V_82 = F_40 ( V_6 , sizeof( * V_88 ) ,
V_89 ,
& V_86 , NULL ) ;
if ( V_82 )
goto V_109;
V_82 = F_51 ( V_6 , V_86 , sizeof( struct V_99 ) + V_104 ,
& V_101 ) ;
if ( V_82 )
goto V_110;
V_82 = F_41 ( V_86 , false ) ;
if ( V_82 )
goto V_111;
V_82 = F_50 ( V_101 , ( void * * ) & V_100 ) ;
if ( V_82 )
goto V_112;
V_100 -> V_113 . V_114 = 0 ;
V_100 -> V_113 . type = V_115 ;
V_100 -> V_113 . V_3 = 64 ;
V_100 -> V_113 . V_4 = 64 ;
V_100 -> V_113 . V_116 = V_96 ;
V_100 -> V_113 . V_117 = V_97 ;
V_100 -> V_118 = V_104 ;
V_100 -> V_119 . V_120 = 0 ;
V_100 -> V_119 . V_121 = 0 ;
V_100 -> V_119 . V_118 = V_104 ;
memcpy ( V_100 -> V_119 . V_122 , V_103 , V_104 ) ;
F_52 ( V_101 ) ;
F_52 ( V_102 ) ;
V_88 = (struct V_87 * ) F_43 ( V_6 , V_86 ) ;
V_88 -> type = V_123 ;
V_88 -> V_124 . V_125 . V_126 . V_24 = V_66 -> V_127 ;
V_88 -> V_124 . V_125 . V_126 . V_26 = V_66 -> V_128 ;
V_88 -> V_124 . V_125 . V_129 = F_53 ( V_6 , V_101 , 0 ) ;
V_88 -> V_124 . V_125 . V_130 = 1 ;
F_44 ( V_6 , V_86 , & V_88 -> V_91 ) ;
F_45 ( V_6 , V_86 , V_92 , false ) ;
F_46 ( V_86 ) ;
V_82 = F_29 ( V_102 , false ) ;
if ( ! V_82 ) {
F_38 ( V_102 ) ;
F_31 ( V_102 ) ;
}
F_54 ( V_73 ) ;
F_55 ( & V_101 ) ;
return V_82 ;
V_112:
F_56 ( V_86 ) ;
V_111:
F_55 ( & V_101 ) ;
V_110:
F_42 ( V_6 , V_86 ) ;
V_109:
F_52 ( V_102 ) ;
V_108:
F_38 ( V_102 ) ;
V_106:
F_54 ( V_73 ) ;
return V_82 ;
}
static int F_57 ( struct V_58 * V_59 ,
int V_24 , int V_26 )
{
struct V_33 * V_34 = V_59 -> V_34 ;
struct V_5 * V_6 = V_34 -> V_47 ;
struct V_60 * V_66 = F_24 ( V_59 ) ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
int V_82 ;
V_82 = F_40 ( V_6 , sizeof( * V_88 ) , V_89 ,
& V_86 , NULL ) ;
if ( V_82 )
return V_82 ;
V_82 = F_41 ( V_86 , true ) ;
if ( V_82 ) {
F_42 ( V_6 , V_86 ) ;
return V_82 ;
}
V_66 -> V_127 = V_24 ;
V_66 -> V_128 = V_26 ;
V_88 = (struct V_87 * ) F_43 ( V_6 , V_86 ) ;
V_88 -> type = V_131 ;
V_88 -> V_124 . V_126 . V_24 = V_66 -> V_127 ;
V_88 -> V_124 . V_126 . V_26 = V_66 -> V_128 ;
F_44 ( V_6 , V_86 , & V_88 -> V_91 ) ;
F_45 ( V_6 , V_86 , V_92 , false ) ;
F_46 ( V_86 ) ;
return 0 ;
}
static void F_58 ( struct V_61 * V_62 )
{
struct V_67 * V_132 = F_27 ( V_62 ) ;
if ( V_132 -> V_73 )
F_54 ( V_132 -> V_73 ) ;
F_59 ( V_62 ) ;
F_3 ( V_132 ) ;
}
static int F_60 ( struct V_61 * V_62 ,
struct V_93 * V_94 ,
unsigned V_32 , unsigned V_133 ,
struct V_75 * V_134 ,
unsigned V_135 )
{
struct V_67 * V_132 = F_27 ( V_62 ) ;
struct V_5 * V_6 = V_132 -> V_41 . V_34 -> V_47 ;
struct V_75 V_76 ;
struct V_71 * V_136 ;
int V_80 = 1 ;
F_14 ( V_62 -> V_34 ) ;
V_136 = F_28 ( V_132 -> V_73 ) ;
if ( ! V_136 -> V_83 ) {
F_15 ( V_62 -> V_34 ) ;
return 0 ;
}
if ( ! V_135 ) {
V_135 = 1 ;
V_134 = & V_76 ;
V_76 . V_77 = V_76 . y1 = 0 ;
V_76 . V_78 = V_62 -> V_3 ;
V_76 . V_79 = V_62 -> V_4 ;
} else if ( V_32 & V_137 ) {
V_135 /= 2 ;
V_80 = 2 ;
}
F_32 ( V_6 , V_132 , V_136 , V_32 , V_133 ,
V_134 , V_135 , V_80 ) ;
F_15 ( V_62 -> V_34 ) ;
return 0 ;
}
int
F_61 ( struct V_33 * V_34 ,
struct V_67 * V_138 ,
struct V_139 * V_140 ,
struct V_98 * V_73 )
{
int V_82 ;
V_138 -> V_73 = V_73 ;
V_82 = F_62 ( V_34 , & V_138 -> V_41 , & V_141 ) ;
if ( V_82 ) {
V_138 -> V_73 = NULL ;
return V_82 ;
}
F_63 ( & V_138 -> V_41 , V_140 ) ;
return 0 ;
}
static void F_64 ( struct V_58 * V_59 , int V_50 )
{
}
static bool F_65 ( struct V_58 * V_59 ,
const struct V_49 * V_50 ,
struct V_49 * V_142 )
{
struct V_33 * V_34 = V_59 -> V_34 ;
struct V_5 * V_6 = V_34 -> V_47 ;
F_5 ( V_6 , L_8 ,
V_11 ,
V_50 -> V_53 , V_50 -> V_55 ,
V_142 -> V_53 ,
V_142 -> V_55 ) ;
return true ;
}
void
F_66 ( struct V_5 * V_6 )
{
int V_12 ;
F_67 ( ! V_6 -> V_143 -> V_18 ) ;
if ( V_6 -> V_18 -> V_7 == 0 ) {
F_5 ( V_6 , L_9 , V_11 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_6 -> V_18 -> V_7 ; ++ V_12 ) {
struct V_1 * V_2 = & V_6 -> V_18 -> V_22 [ V_12 ] ;
if ( V_2 -> V_26 > 8192 || V_2 -> V_24 > 8192 ||
V_2 -> V_3 > 8192 || V_2 -> V_4 > 8192 ) {
F_49 ( L_10 ,
V_12 , V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_24 , V_2 -> V_26 ) ;
return;
}
}
F_68 ( V_6 ) ;
}
static void F_69 ( struct V_5 * V_6 ,
int V_40 ,
unsigned V_24 , unsigned V_26 ,
unsigned V_3 , unsigned V_4 ,
unsigned V_144 )
{
F_8 ( L_11 , V_40 , V_3 , V_4 , V_24 , V_26 ) ;
V_6 -> V_18 -> V_22 [ V_40 ] . V_24 = V_24 ;
V_6 -> V_18 -> V_22 [ V_40 ] . V_26 = V_26 ;
V_6 -> V_18 -> V_22 [ V_40 ] . V_3 = V_3 ;
V_6 -> V_18 -> V_22 [ V_40 ] . V_4 = V_4 ;
V_6 -> V_18 -> V_22 [ V_40 ] . V_30 = V_144 ;
}
static int F_70 ( struct V_58 * V_59 ,
struct V_49 * V_50 ,
struct V_49 * V_142 ,
int V_24 , int V_26 ,
struct V_61 * V_145 )
{
struct V_33 * V_34 = V_59 -> V_34 ;
struct V_5 * V_6 = V_34 -> V_47 ;
struct V_67 * V_138 ;
struct V_71 * V_74 , * V_146 = NULL ;
struct V_60 * V_66 = F_24 ( V_59 ) ;
bool V_147 = false ;
int V_82 ;
int V_144 ;
if ( ! V_59 -> V_70 -> V_62 ) {
F_8 ( L_12 ) ;
return 0 ;
}
if ( V_145 ) {
V_138 = F_27 ( V_145 ) ;
V_146 = F_28 ( V_138 -> V_73 ) ;
}
V_138 = F_27 ( V_59 -> V_70 -> V_62 ) ;
V_74 = F_28 ( V_138 -> V_73 ) ;
F_71 ( L_13 ,
V_24 , V_26 ,
V_50 -> V_53 , V_50 -> V_55 ,
V_142 -> V_53 ,
V_142 -> V_55 ) ;
if ( V_74 -> V_83 == false )
V_147 = true ;
if ( V_74 -> V_148 . V_149 * V_74 -> V_148 . V_4 > V_6 -> V_150 ) {
F_49 ( L_14 ) ;
return - V_151 ;
}
V_82 = F_29 ( V_74 , false ) ;
if ( V_82 != 0 )
return V_82 ;
V_82 = F_30 ( V_74 , V_74 -> type , NULL ) ;
if ( V_82 != 0 ) {
F_31 ( V_74 ) ;
return - V_151 ;
}
F_31 ( V_74 ) ;
if ( V_147 ) {
F_72 ( V_6 ) ;
F_5 ( V_6 ,
L_15 ,
V_74 -> V_148 . V_3 , V_74 -> V_148 . V_4 ,
V_74 -> V_148 . V_149 , V_74 -> V_148 . V_152 ) ;
F_73 ( V_6 , 0 , V_74 ) ;
V_74 -> V_83 = true ;
}
if ( V_74 -> V_83 ) {
F_8 ( L_16 , V_74 -> V_30 , V_66 -> V_40 ) ;
V_144 = 0 ;
} else {
V_144 = V_74 -> V_30 ;
}
if ( V_146 && V_146 != V_74 ) {
V_146 -> V_83 = false ;
V_82 = F_29 ( V_146 , false ) ;
F_38 ( V_146 ) ;
F_31 ( V_146 ) ;
}
F_69 ( V_6 , V_66 -> V_40 , V_24 , V_26 ,
V_50 -> V_53 ,
V_50 -> V_55 , V_144 ) ;
return 0 ;
}
static void F_74 ( struct V_58 * V_59 )
{
F_71 ( L_17 ,
V_59 -> V_50 . V_53 , V_59 -> V_50 . V_55 ,
V_59 -> V_24 , V_59 -> V_26 , V_59 -> V_153 ) ;
}
static void F_75 ( struct V_58 * V_59 )
{
F_71 ( L_18 ) ;
}
static void F_76 ( struct V_58 * V_59 )
{
struct V_60 * V_66 = F_24 ( V_59 ) ;
struct V_33 * V_34 = V_59 -> V_34 ;
struct V_5 * V_6 = V_34 -> V_47 ;
if ( V_59 -> V_70 -> V_62 ) {
struct V_67 * V_138 = F_27 ( V_59 -> V_70 -> V_62 ) ;
struct V_71 * V_74 = F_28 ( V_138 -> V_73 ) ;
int V_82 ;
V_82 = F_29 ( V_74 , false ) ;
F_38 ( V_74 ) ;
F_31 ( V_74 ) ;
V_59 -> V_70 -> V_62 = NULL ;
}
F_69 ( V_6 , V_66 -> V_40 , 0 , 0 , 0 , 0 , 0 ) ;
F_66 ( V_6 ) ;
}
static int F_77 ( struct V_33 * V_34 , int V_154 )
{
struct V_60 * V_60 ;
V_60 = F_4 ( sizeof( struct V_60 ) , V_10 ) ;
if ( ! V_60 )
return - V_155 ;
F_78 ( V_34 , & V_60 -> V_41 , & V_156 ) ;
V_60 -> V_40 = V_154 ;
F_79 ( & V_60 -> V_41 , 256 ) ;
F_80 ( & V_60 -> V_41 , & V_157 ) ;
return 0 ;
}
static void F_81 ( struct V_158 * V_159 , int V_50 )
{
F_71 ( L_18 ) ;
}
static bool F_82 ( struct V_158 * V_159 ,
const struct V_49 * V_50 ,
struct V_49 * V_142 )
{
F_71 ( L_18 ) ;
return true ;
}
static void F_83 ( struct V_158 * V_159 )
{
F_71 ( L_18 ) ;
}
static void F_84 ( struct V_5 * V_6 ,
struct V_158 * V_159 )
{
int V_12 ;
struct V_38 * V_39 = F_85 ( V_159 ) ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
F_67 ( ! V_159 ) ;
V_12 = V_39 -> V_40 ;
if ( ! V_6 -> V_18 ||
V_6 -> V_18 -> V_19 <= V_12 ) {
F_49 (
L_19 ,
V_6 -> V_18 ,
V_6 -> V_18 ?
V_6 -> V_18 -> V_19 : - 1 ) ;
return;
}
if ( ! V_159 -> V_59 ) {
F_49 ( L_20 , V_159 ) ;
return;
}
if ( V_12 != 0 )
F_71 ( L_21 ) ;
V_2 = & V_6 -> V_18 -> V_22 [ V_12 ] ;
V_2 -> V_31 = V_12 ;
if ( V_159 -> V_59 -> V_153 ) {
V_50 = & V_159 -> V_59 -> V_50 ;
V_2 -> V_3 = V_50 -> V_53 ;
V_2 -> V_4 = V_50 -> V_55 ;
V_2 -> V_24 = V_159 -> V_59 -> V_24 ;
V_2 -> V_26 = V_159 -> V_59 -> V_26 ;
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
F_66 ( V_6 ) ;
}
static void F_86 ( struct V_158 * V_159 )
{
struct V_5 * V_6 = V_159 -> V_34 -> V_47 ;
F_84 ( V_6 , V_159 ) ;
F_71 ( L_18 ) ;
}
static void F_87 ( struct V_158 * V_159 ,
struct V_49 * V_50 ,
struct V_49 * V_142 )
{
F_71 ( L_18 ) ;
}
static int F_88 ( struct V_36 * V_37 )
{
int V_82 = 0 ;
struct V_5 * V_6 = V_37 -> V_34 -> V_47 ;
unsigned V_45 = 1024 ;
unsigned V_46 = 768 ;
F_8 ( L_23 , V_6 -> V_18 ) ;
if ( V_6 -> V_18 && V_6 -> V_18 -> V_7 ) {
V_82 = F_18 ( V_37 , & V_45 , & V_46 ) ;
if ( V_82 < 0 )
return V_82 ;
}
V_82 += F_21 ( V_37 , V_45 , V_46 ) ;
return V_82 ;
}
static int F_89 ( struct V_36 * V_37 ,
struct V_49 * V_50 )
{
struct V_33 * V_35 = V_37 -> V_34 ;
struct V_5 * V_6 = V_35 -> V_47 ;
int V_12 ;
if( V_6 -> V_52 == V_50 -> V_53 &&
V_6 -> V_54 == V_50 -> V_55 )
return V_160 ;
for ( V_12 = 0 ; V_12 < F_22 ( V_56 ) ; V_12 ++ ) {
if ( V_56 [ V_12 ] . V_57 == V_50 -> V_53 && V_56 [ V_12 ] . V_48 == V_50 -> V_55 )
return V_160 ;
}
return V_161 ;
}
static struct V_158 * F_90 ( struct V_36 * V_37 )
{
struct V_38 * V_38 =
F_11 ( V_37 ) ;
F_71 ( L_18 ) ;
return & V_38 -> V_162 ;
}
static void F_91 ( struct V_36 * V_37 )
{
F_71 ( L_18 ) ;
}
static void F_92 ( struct V_36 * V_37 )
{
F_71 ( L_18 ) ;
}
static enum V_163 F_93 (
struct V_36 * V_37 ,
bool V_164 )
{
struct V_38 * V_39 =
F_11 ( V_37 ) ;
struct V_33 * V_35 = V_37 -> V_34 ;
struct V_5 * V_6 = V_35 -> V_47 ;
bool V_165 = false ;
if ( ! V_6 -> V_8 ) {
if ( V_39 -> V_40 == 0 )
V_165 = true ;
} else
V_165 = V_6 -> V_8 -> V_7 > V_39 -> V_40 &&
F_1 ( & V_6 -> V_8 -> V_22 [ V_39 -> V_40 ] ) ;
F_71 ( L_24 , V_39 -> V_40 , V_165 ) ;
if ( ! V_165 )
F_69 ( V_6 , V_39 -> V_40 , 0 , 0 , 0 , 0 , 0 ) ;
return V_165 ? V_166
: V_167 ;
}
static int F_94 ( struct V_36 * V_37 ,
struct V_168 * V_169 ,
T_3 V_170 )
{
F_71 ( L_18 ) ;
return 0 ;
}
static void F_95 ( struct V_36 * V_37 )
{
struct V_38 * V_38 =
F_11 ( V_37 ) ;
F_96 ( V_37 ) ;
F_97 ( V_37 ) ;
F_3 ( V_38 ) ;
}
static void F_98 ( struct V_158 * V_159 )
{
F_99 ( V_159 ) ;
}
static int F_100 ( struct V_5 * V_6 )
{
if ( V_6 -> V_171 )
return 0 ;
V_6 -> V_171 =
F_101 ( V_6 -> V_35 , V_172 ,
L_25 , 0 , 1 ) ;
return 0 ;
}
static int F_102 ( struct V_33 * V_34 , int V_173 )
{
struct V_5 * V_6 = V_34 -> V_47 ;
struct V_38 * V_38 ;
struct V_36 * V_37 ;
struct V_158 * V_159 ;
V_38 = F_4 ( sizeof( struct V_38 ) , V_10 ) ;
if ( ! V_38 )
return - V_155 ;
V_38 -> V_40 = V_173 ;
V_37 = & V_38 -> V_41 ;
V_159 = & V_38 -> V_162 ;
F_103 ( V_34 , & V_38 -> V_41 ,
& V_174 , V_175 ) ;
F_104 ( V_34 , & V_38 -> V_162 , & V_176 ,
V_177 ) ;
V_37 -> V_178 = V_179 ;
V_159 -> V_180 = 1 << V_173 ;
F_105 ( & V_38 -> V_41 ,
& V_38 -> V_162 ) ;
F_106 ( V_159 , & V_181 ) ;
F_107 ( V_37 , & V_182 ) ;
F_108 ( & V_37 -> V_41 ,
V_6 -> V_171 , 0 ) ;
F_108 ( & V_37 -> V_41 ,
V_34 -> V_42 . V_43 , 0 ) ;
F_108 ( & V_37 -> V_41 ,
V_34 -> V_42 . V_44 , 0 ) ;
F_109 ( V_37 ) ;
return 0 ;
}
static struct V_61 *
F_110 ( struct V_33 * V_34 ,
struct V_93 * V_94 ,
struct V_139 * V_140 )
{
struct V_98 * V_73 ;
struct V_67 * V_132 ;
int V_82 ;
V_73 = F_48 ( V_34 , V_94 , V_140 -> V_183 [ 0 ] ) ;
V_132 = F_4 ( sizeof( * V_132 ) , V_10 ) ;
if ( V_132 == NULL )
return NULL ;
V_82 = F_61 ( V_34 , V_132 , V_140 , V_73 ) ;
if ( V_82 ) {
F_3 ( V_132 ) ;
F_54 ( V_73 ) ;
return NULL ;
}
return & V_132 -> V_41 ;
}
int F_111 ( struct V_5 * V_6 )
{
int V_82 ;
struct V_98 * V_184 ;
int V_19 = V_185 ;
int V_186 = sizeof( struct V_9 ) +
V_19 * sizeof( struct V_1 ) ;
V_82 = F_112 ( V_6 , V_186 , 0 ,
V_187 ,
false , false , NULL , & V_184 ) ;
if ( V_82 ) {
F_49 ( L_26 , V_11 , V_82 ) ;
return - V_155 ;
}
V_6 -> V_188 = F_28 ( V_184 ) ;
V_82 = F_29 ( V_6 -> V_188 , false ) ;
if ( V_82 )
return V_82 ;
V_82 = F_30 ( V_6 -> V_188 , V_187 , NULL ) ;
if ( V_82 ) {
F_31 ( V_6 -> V_188 ) ;
return V_82 ;
}
F_31 ( V_6 -> V_188 ) ;
F_50 ( V_6 -> V_188 , NULL ) ;
V_6 -> V_18 = V_6 -> V_188 -> V_189 ;
V_6 -> V_143 -> V_18 =
F_53 ( V_6 , V_6 -> V_188 , 0 ) ;
memset ( V_6 -> V_18 , 0 , V_186 ) ;
V_6 -> V_18 -> V_19 = V_19 ;
return 0 ;
}
int F_113 ( struct V_5 * V_6 )
{
int V_82 ;
V_6 -> V_18 = NULL ;
V_6 -> V_143 -> V_18 = 0 ;
F_52 ( V_6 -> V_188 ) ;
V_82 = F_29 ( V_6 -> V_188 , false ) ;
if ( V_82 )
return V_82 ;
F_38 ( V_6 -> V_188 ) ;
F_31 ( V_6 -> V_188 ) ;
F_55 ( & V_6 -> V_188 ) ;
return 0 ;
}
int F_114 ( struct V_5 * V_6 )
{
int V_12 ;
int V_82 ;
F_115 ( V_6 -> V_35 ) ;
V_82 = F_111 ( V_6 ) ;
if ( V_82 )
return V_82 ;
V_6 -> V_35 -> V_42 . V_190 = ( void * ) & V_191 ;
V_6 -> V_35 -> V_42 . V_192 = 320 ;
V_6 -> V_35 -> V_42 . V_193 = 200 ;
V_6 -> V_35 -> V_42 . V_194 = 8192 ;
V_6 -> V_35 -> V_42 . V_195 = 8192 ;
V_6 -> V_35 -> V_42 . V_196 = V_6 -> V_197 ;
F_116 ( V_6 -> V_35 ) ;
F_100 ( V_6 ) ;
for ( V_12 = 0 ; V_12 < V_185 ; ++ V_12 ) {
F_77 ( V_6 -> V_35 , V_12 ) ;
F_102 ( V_6 -> V_35 , V_12 ) ;
}
V_6 -> V_198 . V_199 = true ;
F_117 ( V_6 ) ;
return 0 ;
}
void F_118 ( struct V_5 * V_6 )
{
F_119 ( V_6 ) ;
F_113 ( V_6 ) ;
if ( V_6 -> V_198 . V_199 ) {
F_120 ( V_6 -> V_35 ) ;
V_6 -> V_198 . V_199 = false ;
}
}
