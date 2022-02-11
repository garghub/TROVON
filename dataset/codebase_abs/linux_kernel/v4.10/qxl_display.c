static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 && V_2 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 , unsigned V_7 )
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
int V_15 = V_16 ;
V_13 = V_6 -> V_17 -> V_8 . V_7 ;
V_14 = F_7 ( 0 , ( const V_18 * ) & V_6 -> V_17 -> V_8 ,
sizeof( V_6 -> V_17 -> V_8 ) ) ;
if ( V_14 != V_6 -> V_17 -> V_19 ) {
F_5 ( V_6 , L_2 , V_14 ,
sizeof( V_6 -> V_17 -> V_8 ) ,
V_6 -> V_17 -> V_19 ) ;
return V_20 ;
}
if ( V_13 > V_6 -> V_21 -> V_22 ) {
F_8 ( L_3 ,
V_6 -> V_21 -> V_22 , V_13 ) ;
V_13 = V_6 -> V_21 -> V_22 ;
} else {
V_13 = V_6 -> V_17 -> V_8 . V_7 ;
}
if ( V_6 -> V_8
&& ( V_13 != V_6 -> V_8 -> V_7 ) ) {
V_15 = V_23 ;
}
F_2 ( V_6 , V_13 ) ;
V_6 -> V_8 -> V_22 =
V_6 -> V_21 -> V_22 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_8 -> V_7 ; ++ V_12 ) {
struct V_24 * V_25 =
& V_6 -> V_17 -> V_8 . V_26 [ V_12 ] ;
struct V_1 * V_27 =
& V_6 -> V_8 -> V_26 [ V_12 ] ;
if ( V_27 -> V_28 != V_25 -> V_29 ) {
V_27 -> V_28 = V_25 -> V_29 ;
V_15 = V_23 ;
}
if ( V_27 -> V_30 != V_25 -> V_31 ) {
V_27 -> V_30 = V_25 -> V_31 ;
V_15 = V_23 ;
}
if ( V_27 -> V_3 != V_25 -> V_32 - V_25 -> V_29 ) {
V_27 -> V_3 = V_25 -> V_32 - V_25 -> V_29 ;
V_15 = V_23 ;
}
if ( V_27 -> V_4 != V_25 -> V_33 - V_25 -> V_31 ) {
V_27 -> V_4 = V_25 -> V_33 - V_25 -> V_31 ;
V_15 = V_23 ;
}
if ( V_27 -> V_34 != 0 ) {
V_27 -> V_34 = 0 ;
V_15 = V_23 ;
}
if ( V_27 -> V_35 != V_12 ) {
V_27 -> V_35 = V_12 ;
V_15 = V_23 ;
}
if ( V_27 -> V_36 != 0 ) {
V_27 -> V_36 = 0 ;
V_15 = V_23 ;
}
F_8 ( L_4 , V_27 -> V_3 , V_27 -> V_4 ,
V_27 -> V_28 , V_27 -> V_30 ) ;
}
return V_15 ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_37 * V_38 = V_6 -> V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_1 * V_2 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
V_43 = F_11 ( V_41 ) ;
V_2 = & V_6 -> V_8 -> V_26 [ V_43 -> V_44 ] ;
F_12 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_47 , V_2 -> V_28 ) ;
F_12 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_48 , V_2 -> V_30 ) ;
}
}
void F_13 ( struct V_5 * V_6 )
{
struct V_37 * V_38 = V_6 -> V_39 ;
int V_15 ;
V_15 = F_6 ( V_6 ) ;
while ( V_15 == V_20 ) {
F_5 ( V_6 , L_5
L_6 ) ;
V_15 = F_6 ( V_6 ) ;
}
if ( V_15 == V_16 ) {
F_5 ( V_6 , L_7 ) ;
F_14 ( L_8 ) ;
return;
}
F_15 ( V_38 ) ;
F_9 ( V_6 ) ;
F_16 ( V_38 ) ;
if ( ! F_17 ( V_6 -> V_39 ) ) {
F_18 ( V_6 -> V_39 ) ;
}
}
static int F_19 ( struct V_40 * V_41 ,
unsigned * V_49 ,
unsigned * V_50 )
{
struct V_37 * V_38 = V_41 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_51 ;
struct V_42 * V_43 = F_11 ( V_41 ) ;
int V_52 = V_43 -> V_44 ;
struct V_53 * V_54 = NULL ;
struct V_1 * V_2 ;
if ( ! V_6 -> V_8 )
return 0 ;
V_2 = & V_6 -> V_8 -> V_26 [ V_52 ] ;
V_54 = F_20 ( V_38 , V_2 -> V_3 , V_2 -> V_4 , 60 , false , false ,
false ) ;
V_54 -> type |= V_55 ;
V_54 -> V_56 = V_2 -> V_3 ;
V_54 -> V_57 = V_2 -> V_4 ;
F_21 ( V_54 ) ;
* V_49 = V_2 -> V_3 ;
* V_50 = V_2 -> V_4 ;
F_22 ( V_41 , V_54 ) ;
V_6 -> V_58 = V_54 -> V_56 ;
V_6 -> V_59 = V_54 -> V_57 ;
return 1 ;
}
static int F_23 ( struct V_40 * V_41 ,
unsigned V_49 ,
unsigned V_50 )
{
struct V_37 * V_38 = V_41 -> V_38 ;
struct V_53 * V_54 = NULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_24 ( V_60 ) ; V_12 ++ ) {
V_54 = F_20 ( V_38 , V_60 [ V_12 ] . V_61 , V_60 [ V_12 ] . V_52 ,
60 , false , false , false ) ;
if ( V_60 [ V_12 ] . V_61 == V_49 && V_60 [ V_12 ] . V_52 == V_50 )
V_54 -> type |= V_55 ;
F_22 ( V_41 , V_54 ) ;
}
return V_12 - 1 ;
}
static void F_25 ( struct V_62 * V_63 )
{
struct V_64 * V_64 = F_26 ( V_63 ) ;
F_27 ( V_63 ) ;
F_28 ( & V_64 -> V_65 ) ;
F_3 ( V_64 ) ;
}
static int F_29 ( struct V_62 * V_63 ,
struct V_66 * V_67 ,
struct V_68 * V_69 ,
T_1 V_70 )
{
struct V_37 * V_38 = V_63 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_51 ;
struct V_71 * V_72 = F_30 ( V_67 ) ;
struct V_71 * V_73 = F_30 ( V_63 -> V_74 -> V_67 ) ;
struct V_75 * V_76 = F_31 ( V_73 -> V_77 ) ;
struct V_75 * V_78 = F_31 ( V_72 -> V_77 ) ;
unsigned long V_36 ;
struct V_79 V_80 = {
. V_81 = 0 ,
. y1 = 0 ,
. V_82 = V_67 -> V_3 ,
. V_83 = V_67 -> V_4
} ;
int V_84 = 1 ;
int V_85 = 1 ;
int V_86 = 0 ;
V_63 -> V_74 -> V_67 = V_67 ;
V_76 -> V_87 = false ;
V_78 -> V_87 = true ;
V_86 = F_32 ( V_78 , false ) ;
if ( V_86 )
return V_86 ;
V_86 = F_33 ( V_78 , V_78 -> type , NULL ) ;
F_34 ( V_78 ) ;
if ( V_86 )
return V_86 ;
F_35 ( V_6 , V_72 , V_78 , 0 , 0 ,
& V_80 , V_85 , V_84 ) ;
F_36 ( V_63 ) ;
if ( V_69 ) {
F_37 ( & V_38 -> V_88 , V_36 ) ;
F_38 ( V_63 , V_69 ) ;
F_39 ( & V_38 -> V_88 , V_36 ) ;
}
F_40 ( V_63 ) ;
V_86 = F_32 ( V_78 , false ) ;
if ( ! V_86 ) {
F_41 ( V_78 ) ;
F_34 ( V_78 ) ;
}
return 0 ;
}
static int
F_42 ( struct V_5 * V_6 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
int V_86 ;
V_86 = F_43 ( V_6 , sizeof( * V_92 ) , V_93 ,
& V_90 , NULL ) ;
if ( V_86 )
return V_86 ;
V_86 = F_44 ( V_90 , true ) ;
if ( V_86 ) {
F_45 ( V_6 , V_90 ) ;
return V_86 ;
}
V_92 = (struct V_91 * ) F_46 ( V_6 , V_90 ) ;
V_92 -> type = V_94 ;
F_47 ( V_6 , V_90 , & V_92 -> V_95 ) ;
F_48 ( V_6 , V_90 , V_96 , false ) ;
F_49 ( V_90 ) ;
return 0 ;
}
static int F_50 ( struct V_62 * V_63 )
{
struct V_64 * V_97 = F_26 ( V_63 ) ;
struct V_37 * V_38 = V_63 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_51 ;
struct V_91 * V_92 ;
struct V_89 * V_90 ;
int V_86 = 0 ;
if ( ! V_97 -> V_65 )
return 0 ;
V_86 = F_43 ( V_6 , sizeof( * V_92 ) ,
V_93 ,
& V_90 , NULL ) ;
if ( V_86 )
return V_86 ;
V_86 = F_51 ( V_90 , V_97 -> V_65 ) ;
if ( V_86 )
goto V_98;
V_86 = F_44 ( V_90 , false ) ;
if ( V_86 )
goto V_98;
V_92 = (struct V_91 * ) F_46 ( V_6 , V_90 ) ;
V_92 -> type = V_99 ;
V_92 -> V_100 . V_101 . V_102 . V_28 = V_97 -> V_103 + V_97 -> V_104 ;
V_92 -> V_100 . V_101 . V_102 . V_30 = V_97 -> V_105 + V_97 -> V_106 ;
V_92 -> V_100 . V_101 . V_107 = F_52 ( V_6 , V_97 -> V_65 , 0 ) ;
V_92 -> V_100 . V_101 . V_108 = 1 ;
F_47 ( V_6 , V_90 , & V_92 -> V_95 ) ;
F_48 ( V_6 , V_90 , V_96 , false ) ;
F_49 ( V_90 ) ;
return V_86 ;
V_98:
F_45 ( V_6 , V_90 ) ;
return V_86 ;
}
static int F_53 ( struct V_62 * V_63 ,
struct V_109 * V_110 ,
T_1 V_111 ,
T_1 V_3 ,
T_1 V_4 , T_2 V_112 , T_2 V_113 )
{
struct V_37 * V_38 = V_63 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_51 ;
struct V_64 * V_97 = F_26 ( V_63 ) ;
struct V_114 * V_77 ;
struct V_115 * V_116 ;
struct V_91 * V_92 ;
struct V_75 * V_65 , * V_117 ;
struct V_89 * V_90 ;
void * V_118 ;
int V_119 = 64 * 64 * 4 ;
int V_86 = 0 ;
if ( ! V_111 )
return F_42 ( V_6 ) ;
V_77 = F_54 ( V_110 , V_111 ) ;
if ( ! V_77 ) {
F_55 ( L_9 ) ;
return - V_120 ;
}
V_117 = F_31 ( V_77 ) ;
V_86 = F_32 ( V_117 , false ) ;
if ( V_86 )
goto V_121;
V_86 = F_33 ( V_117 , V_122 , NULL ) ;
F_34 ( V_117 ) ;
if ( V_86 )
goto V_121;
V_86 = F_56 ( V_117 , & V_118 ) ;
if ( V_86 )
goto V_123;
V_86 = F_43 ( V_6 , sizeof( * V_92 ) ,
V_93 ,
& V_90 , NULL ) ;
if ( V_86 )
goto V_124;
V_86 = F_57 ( V_6 , V_90 , sizeof( struct V_115 ) + V_119 ,
& V_65 ) ;
if ( V_86 )
goto V_98;
V_86 = F_44 ( V_90 , false ) ;
if ( V_86 )
goto V_125;
V_86 = F_56 ( V_65 , ( void * * ) & V_116 ) ;
if ( V_86 )
goto V_126;
V_116 -> V_127 . V_128 = 0 ;
V_116 -> V_127 . type = V_129 ;
V_116 -> V_127 . V_3 = 64 ;
V_116 -> V_127 . V_4 = 64 ;
V_116 -> V_127 . V_104 = V_112 ;
V_116 -> V_127 . V_106 = V_113 ;
V_116 -> V_130 = V_119 ;
V_116 -> V_131 . V_132 = 0 ;
V_116 -> V_131 . V_133 = 0 ;
V_116 -> V_131 . V_130 = V_119 ;
memcpy ( V_116 -> V_131 . V_134 , V_118 , V_119 ) ;
F_58 ( V_65 ) ;
F_58 ( V_117 ) ;
V_97 -> V_103 += V_97 -> V_104 - V_112 ;
V_97 -> V_105 += V_97 -> V_106 - V_113 ;
V_97 -> V_104 = V_112 ;
V_97 -> V_106 = V_113 ;
V_92 = (struct V_91 * ) F_46 ( V_6 , V_90 ) ;
V_92 -> type = V_99 ;
V_92 -> V_100 . V_101 . V_102 . V_28 = V_97 -> V_103 + V_97 -> V_104 ;
V_92 -> V_100 . V_101 . V_102 . V_30 = V_97 -> V_105 + V_97 -> V_106 ;
V_92 -> V_100 . V_101 . V_107 = F_52 ( V_6 , V_65 , 0 ) ;
V_92 -> V_100 . V_101 . V_108 = 1 ;
F_47 ( V_6 , V_90 , & V_92 -> V_95 ) ;
F_48 ( V_6 , V_90 , V_96 , false ) ;
F_49 ( V_90 ) ;
V_86 = F_32 ( V_117 , false ) ;
if ( ! V_86 ) {
F_41 ( V_117 ) ;
F_34 ( V_117 ) ;
}
F_59 ( V_77 ) ;
F_28 ( & V_97 -> V_65 ) ;
V_97 -> V_65 = V_65 ;
return V_86 ;
V_126:
F_60 ( V_90 ) ;
V_125:
F_28 ( & V_65 ) ;
V_98:
F_45 ( V_6 , V_90 ) ;
V_124:
F_58 ( V_117 ) ;
V_123:
F_41 ( V_117 ) ;
V_121:
F_59 ( V_77 ) ;
return V_86 ;
}
static int F_61 ( struct V_62 * V_63 ,
int V_28 , int V_30 )
{
struct V_37 * V_38 = V_63 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_51 ;
struct V_64 * V_97 = F_26 ( V_63 ) ;
struct V_89 * V_90 ;
struct V_91 * V_92 ;
int V_86 ;
V_86 = F_43 ( V_6 , sizeof( * V_92 ) , V_93 ,
& V_90 , NULL ) ;
if ( V_86 )
return V_86 ;
V_86 = F_44 ( V_90 , true ) ;
if ( V_86 ) {
F_45 ( V_6 , V_90 ) ;
return V_86 ;
}
V_97 -> V_103 = V_28 ;
V_97 -> V_105 = V_30 ;
V_92 = (struct V_91 * ) F_46 ( V_6 , V_90 ) ;
V_92 -> type = V_135 ;
V_92 -> V_100 . V_102 . V_28 = V_97 -> V_103 + V_97 -> V_104 ;
V_92 -> V_100 . V_102 . V_30 = V_97 -> V_105 + V_97 -> V_106 ;
F_47 ( V_6 , V_90 , & V_92 -> V_95 ) ;
F_48 ( V_6 , V_90 , V_96 , false ) ;
F_49 ( V_90 ) ;
return 0 ;
}
void F_62 ( struct V_66 * V_67 )
{
struct V_71 * V_136 = F_30 ( V_67 ) ;
F_59 ( V_136 -> V_77 ) ;
F_63 ( V_67 ) ;
F_3 ( V_136 ) ;
}
static int F_64 ( struct V_66 * V_67 ,
struct V_109 * V_110 ,
unsigned V_36 , unsigned V_137 ,
struct V_79 * V_138 ,
unsigned V_139 )
{
struct V_71 * V_136 = F_30 ( V_67 ) ;
struct V_5 * V_6 = V_136 -> V_45 . V_38 -> V_51 ;
struct V_79 V_80 ;
struct V_75 * V_140 ;
int V_84 = 1 ;
F_15 ( V_67 -> V_38 ) ;
V_140 = F_31 ( V_136 -> V_77 ) ;
if ( ! V_140 -> V_87 ) {
F_16 ( V_67 -> V_38 ) ;
return 0 ;
}
if ( ! V_139 ) {
V_139 = 1 ;
V_138 = & V_80 ;
V_80 . V_81 = V_80 . y1 = 0 ;
V_80 . V_82 = V_67 -> V_3 ;
V_80 . V_83 = V_67 -> V_4 ;
} else if ( V_36 & V_141 ) {
V_139 /= 2 ;
V_84 = 2 ;
}
F_35 ( V_6 , V_136 , V_140 , V_36 , V_137 ,
V_138 , V_139 , V_84 ) ;
F_16 ( V_67 -> V_38 ) ;
return 0 ;
}
int
F_65 ( struct V_37 * V_38 ,
struct V_71 * V_142 ,
const struct V_143 * V_144 ,
struct V_114 * V_77 ,
const struct V_145 * V_146 )
{
int V_86 ;
V_142 -> V_77 = V_77 ;
V_86 = F_66 ( V_38 , & V_142 -> V_45 , V_146 ) ;
if ( V_86 ) {
V_142 -> V_77 = NULL ;
return V_86 ;
}
F_67 ( & V_142 -> V_45 , V_144 ) ;
return 0 ;
}
static void F_68 ( struct V_62 * V_63 , int V_54 )
{
}
static bool F_69 ( struct V_62 * V_63 ,
const struct V_53 * V_54 ,
struct V_53 * V_147 )
{
struct V_37 * V_38 = V_63 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_51 ;
F_5 ( V_6 , L_10 ,
V_11 ,
V_54 -> V_56 , V_54 -> V_57 ,
V_147 -> V_56 ,
V_147 -> V_57 ) ;
return true ;
}
static void
F_70 ( struct V_5 * V_6 )
{
int V_12 ;
F_71 ( ! V_6 -> V_148 -> V_21 ) ;
if ( V_6 -> V_21 -> V_7 == 0 ) {
F_5 ( V_6 , L_11 , V_11 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_6 -> V_21 -> V_7 ; ++ V_12 ) {
struct V_1 * V_2 = & V_6 -> V_21 -> V_26 [ V_12 ] ;
if ( V_2 -> V_30 > 8192 || V_2 -> V_28 > 8192 ||
V_2 -> V_3 > 8192 || V_2 -> V_4 > 8192 ) {
F_55 ( L_12 ,
V_12 , V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_28 , V_2 -> V_30 ) ;
return;
}
}
F_72 ( V_6 ) ;
}
static void F_73 ( struct V_5 * V_6 ,
int V_44 ,
unsigned V_28 , unsigned V_30 ,
unsigned V_3 , unsigned V_4 ,
unsigned V_149 )
{
F_8 ( L_13 , V_44 , V_3 , V_4 , V_28 , V_30 ) ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_28 = V_28 ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_30 = V_30 ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_3 = V_3 ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_4 = V_4 ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_34 = V_149 ;
}
static int F_74 ( struct V_62 * V_63 ,
struct V_53 * V_54 ,
struct V_53 * V_147 ,
int V_28 , int V_30 ,
struct V_66 * V_150 )
{
struct V_37 * V_38 = V_63 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_51 ;
struct V_71 * V_142 ;
struct V_75 * V_78 , * V_151 = NULL ;
struct V_64 * V_97 = F_26 ( V_63 ) ;
bool V_152 = false ;
int V_86 ;
int V_149 ;
if ( ! V_63 -> V_74 -> V_67 ) {
F_8 ( L_14 ) ;
return 0 ;
}
if ( V_150 ) {
V_142 = F_30 ( V_150 ) ;
V_151 = F_31 ( V_142 -> V_77 ) ;
}
V_142 = F_30 ( V_63 -> V_74 -> V_67 ) ;
V_78 = F_31 ( V_142 -> V_77 ) ;
F_14 ( L_15 ,
V_28 , V_30 ,
V_54 -> V_56 , V_54 -> V_57 ,
V_147 -> V_56 ,
V_147 -> V_57 ) ;
if ( V_78 -> V_87 == false )
V_152 = true ;
if ( V_78 -> V_153 . V_154 * V_78 -> V_153 . V_4 > V_6 -> V_155 ) {
F_55 ( L_16 ) ;
return - V_156 ;
}
V_86 = F_32 ( V_78 , false ) ;
if ( V_86 != 0 )
return V_86 ;
V_86 = F_33 ( V_78 , V_78 -> type , NULL ) ;
if ( V_86 != 0 ) {
F_34 ( V_78 ) ;
return - V_156 ;
}
F_34 ( V_78 ) ;
if ( V_152 ) {
F_75 ( V_6 ) ;
F_5 ( V_6 ,
L_17 ,
V_78 -> V_153 . V_3 , V_78 -> V_153 . V_4 ,
V_78 -> V_153 . V_154 , V_78 -> V_153 . V_157 ) ;
F_76 ( V_6 , 0 , V_78 ) ;
V_78 -> V_87 = true ;
V_86 = F_50 ( V_63 ) ;
if ( V_86 ) {
F_55 ( L_18 ) ;
V_86 = 0 ;
}
}
if ( V_78 -> V_87 ) {
F_8 ( L_19 , V_78 -> V_34 , V_97 -> V_44 ) ;
V_149 = 0 ;
} else {
V_149 = V_78 -> V_34 ;
}
if ( V_151 && V_151 != V_78 ) {
V_151 -> V_87 = false ;
V_86 = F_32 ( V_151 , false ) ;
F_41 ( V_151 ) ;
F_34 ( V_151 ) ;
}
F_73 ( V_6 , V_97 -> V_44 , V_28 , V_30 ,
V_54 -> V_56 ,
V_54 -> V_57 , V_149 ) ;
return 0 ;
}
static void F_77 ( struct V_62 * V_63 )
{
F_14 ( L_20 ,
V_63 -> V_54 . V_56 , V_63 -> V_54 . V_57 ,
V_63 -> V_28 , V_63 -> V_30 , V_63 -> V_158 ) ;
}
static void F_78 ( struct V_62 * V_63 )
{
F_14 ( L_21 ) ;
}
static void F_79 ( struct V_62 * V_63 )
{
struct V_64 * V_97 = F_26 ( V_63 ) ;
struct V_37 * V_38 = V_63 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_51 ;
if ( V_63 -> V_74 -> V_67 ) {
struct V_71 * V_142 = F_30 ( V_63 -> V_74 -> V_67 ) ;
struct V_75 * V_78 = F_31 ( V_142 -> V_77 ) ;
int V_86 ;
V_86 = F_32 ( V_78 , false ) ;
F_41 ( V_78 ) ;
F_34 ( V_78 ) ;
V_63 -> V_74 -> V_67 = NULL ;
}
F_73 ( V_6 , V_97 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
F_70 ( V_6 ) ;
}
static int F_80 ( struct V_37 * V_38 , int V_159 )
{
struct V_64 * V_64 ;
V_64 = F_4 ( sizeof( struct V_64 ) , V_10 ) ;
if ( ! V_64 )
return - V_160 ;
F_81 ( V_38 , & V_64 -> V_45 , & V_161 ) ;
V_64 -> V_44 = V_159 ;
F_82 ( & V_64 -> V_45 , & V_162 ) ;
return 0 ;
}
static void F_83 ( struct V_163 * V_164 , int V_54 )
{
F_14 ( L_21 ) ;
}
static void F_84 ( struct V_163 * V_164 )
{
F_14 ( L_21 ) ;
}
static void F_85 ( struct V_5 * V_6 ,
struct V_163 * V_164 )
{
int V_12 ;
struct V_42 * V_43 = F_86 ( V_164 ) ;
struct V_1 * V_2 ;
struct V_53 * V_54 ;
F_71 ( ! V_164 ) ;
V_12 = V_43 -> V_44 ;
if ( ! V_6 -> V_21 ||
V_6 -> V_21 -> V_22 <= V_12 ) {
F_55 (
L_22 ,
V_6 -> V_21 ,
V_6 -> V_21 ?
V_6 -> V_21 -> V_22 : - 1 ) ;
return;
}
if ( ! V_164 -> V_63 ) {
F_55 ( L_23 , V_164 ) ;
return;
}
if ( V_12 != 0 )
F_14 ( L_24 ) ;
V_2 = & V_6 -> V_21 -> V_26 [ V_12 ] ;
V_2 -> V_35 = V_12 ;
if ( V_164 -> V_63 -> V_158 ) {
V_54 = & V_164 -> V_63 -> V_54 ;
V_2 -> V_3 = V_54 -> V_56 ;
V_2 -> V_4 = V_54 -> V_57 ;
V_2 -> V_28 = V_164 -> V_63 -> V_28 ;
V_2 -> V_30 = V_164 -> V_63 -> V_30 ;
if ( V_6 -> V_21 -> V_7 < V_12 + 1 )
V_6 -> V_21 -> V_7 = V_12 + 1 ;
} else {
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_30 = 0 ;
}
F_8 ( L_25 ,
V_12 , V_2 -> V_28 , V_2 -> V_30 , V_2 -> V_3 , V_2 -> V_4 , V_6 -> V_21 -> V_7 ) ;
V_2 -> V_36 = 0 ;
F_70 ( V_6 ) ;
}
static void F_87 ( struct V_163 * V_164 )
{
struct V_5 * V_6 = V_164 -> V_38 -> V_51 ;
F_85 ( V_6 , V_164 ) ;
F_14 ( L_21 ) ;
}
static void F_88 ( struct V_163 * V_164 ,
struct V_53 * V_54 ,
struct V_53 * V_147 )
{
F_14 ( L_21 ) ;
}
static int F_89 ( struct V_40 * V_41 )
{
int V_86 = 0 ;
struct V_5 * V_6 = V_41 -> V_38 -> V_51 ;
unsigned V_49 = 1024 ;
unsigned V_50 = 768 ;
F_8 ( L_26 , V_6 -> V_21 ) ;
if ( V_6 -> V_21 && V_6 -> V_21 -> V_7 ) {
V_86 = F_19 ( V_41 , & V_49 , & V_50 ) ;
if ( V_86 < 0 )
return V_86 ;
}
V_86 += F_23 ( V_41 , V_49 , V_50 ) ;
return V_86 ;
}
static int F_90 ( struct V_40 * V_41 ,
struct V_53 * V_54 )
{
struct V_37 * V_39 = V_41 -> V_38 ;
struct V_5 * V_6 = V_39 -> V_51 ;
int V_12 ;
if( V_6 -> V_58 == V_54 -> V_56 &&
V_6 -> V_59 == V_54 -> V_57 )
return V_165 ;
for ( V_12 = 0 ; V_12 < F_24 ( V_60 ) ; V_12 ++ ) {
if ( V_60 [ V_12 ] . V_61 == V_54 -> V_56 && V_60 [ V_12 ] . V_52 == V_54 -> V_57 )
return V_165 ;
}
return V_166 ;
}
static struct V_163 * F_91 ( struct V_40 * V_41 )
{
struct V_42 * V_42 =
F_11 ( V_41 ) ;
F_14 ( L_21 ) ;
return & V_42 -> V_167 ;
}
static enum V_168 F_92 (
struct V_40 * V_41 ,
bool V_169 )
{
struct V_42 * V_43 =
F_11 ( V_41 ) ;
struct V_37 * V_39 = V_41 -> V_38 ;
struct V_5 * V_6 = V_39 -> V_51 ;
bool V_170 = false ;
if ( ! V_6 -> V_8 ) {
if ( V_43 -> V_44 == 0 )
V_170 = true ;
} else
V_170 = V_6 -> V_8 -> V_7 > V_43 -> V_44 &&
F_1 ( & V_6 -> V_8 -> V_26 [ V_43 -> V_44 ] ) ;
F_14 ( L_27 , V_43 -> V_44 , V_170 ) ;
if ( ! V_170 )
F_73 ( V_6 , V_43 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
return V_170 ? V_171
: V_172 ;
}
static int F_93 ( struct V_40 * V_41 ,
struct V_173 * V_174 ,
T_3 V_175 )
{
F_14 ( L_21 ) ;
return 0 ;
}
static void F_94 ( struct V_40 * V_41 )
{
struct V_42 * V_42 =
F_11 ( V_41 ) ;
F_95 ( V_41 ) ;
F_96 ( V_41 ) ;
F_3 ( V_42 ) ;
}
static void F_97 ( struct V_163 * V_164 )
{
F_98 ( V_164 ) ;
}
static int F_99 ( struct V_5 * V_6 )
{
if ( V_6 -> V_176 )
return 0 ;
V_6 -> V_176 =
F_100 ( V_6 -> V_39 , V_177 ,
L_28 , 0 , 1 ) ;
return 0 ;
}
static int F_101 ( struct V_37 * V_38 , int V_178 )
{
struct V_5 * V_6 = V_38 -> V_51 ;
struct V_42 * V_42 ;
struct V_40 * V_41 ;
struct V_163 * V_164 ;
V_42 = F_4 ( sizeof( struct V_42 ) , V_10 ) ;
if ( ! V_42 )
return - V_160 ;
V_42 -> V_44 = V_178 ;
V_41 = & V_42 -> V_45 ;
V_164 = & V_42 -> V_167 ;
F_102 ( V_38 , & V_42 -> V_45 ,
& V_179 , V_180 ) ;
F_103 ( V_38 , & V_42 -> V_167 , & V_181 ,
V_182 , NULL ) ;
V_41 -> V_183 = V_184 ;
V_164 -> V_185 = 1 << V_178 ;
F_104 ( & V_42 -> V_45 ,
& V_42 -> V_167 ) ;
F_105 ( V_164 , & V_186 ) ;
F_106 ( V_41 , & V_187 ) ;
F_107 ( & V_41 -> V_45 ,
V_6 -> V_176 , 0 ) ;
F_107 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_47 , 0 ) ;
F_107 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_48 , 0 ) ;
F_108 ( V_41 ) ;
return 0 ;
}
static struct V_66 *
F_109 ( struct V_37 * V_38 ,
struct V_109 * V_110 ,
const struct V_143 * V_144 )
{
struct V_114 * V_77 ;
struct V_71 * V_136 ;
int V_86 ;
V_77 = F_54 ( V_110 , V_144 -> V_188 [ 0 ] ) ;
if ( ! V_77 )
return NULL ;
V_136 = F_4 ( sizeof( * V_136 ) , V_10 ) ;
if ( V_136 == NULL )
return NULL ;
V_86 = F_65 ( V_38 , V_136 , V_144 , V_77 , & V_189 ) ;
if ( V_86 ) {
F_3 ( V_136 ) ;
F_59 ( V_77 ) ;
return NULL ;
}
return & V_136 -> V_45 ;
}
int F_110 ( struct V_5 * V_6 )
{
int V_86 ;
struct V_114 * V_190 ;
int V_22 = V_191 ;
int V_192 = sizeof( struct V_9 ) +
V_22 * sizeof( struct V_1 ) ;
V_86 = F_111 ( V_6 , V_192 , 0 ,
V_193 ,
false , false , NULL , & V_190 ) ;
if ( V_86 ) {
F_55 ( L_29 , V_11 , V_86 ) ;
return - V_160 ;
}
V_6 -> V_194 = F_31 ( V_190 ) ;
V_86 = F_32 ( V_6 -> V_194 , false ) ;
if ( V_86 )
return V_86 ;
V_86 = F_33 ( V_6 -> V_194 , V_193 , NULL ) ;
if ( V_86 ) {
F_34 ( V_6 -> V_194 ) ;
return V_86 ;
}
F_34 ( V_6 -> V_194 ) ;
F_56 ( V_6 -> V_194 , NULL ) ;
V_6 -> V_21 = V_6 -> V_194 -> V_195 ;
V_6 -> V_148 -> V_21 =
F_52 ( V_6 , V_6 -> V_194 , 0 ) ;
memset ( V_6 -> V_21 , 0 , V_192 ) ;
V_6 -> V_21 -> V_22 = V_22 ;
return 0 ;
}
int F_112 ( struct V_5 * V_6 )
{
int V_86 ;
V_6 -> V_21 = NULL ;
V_6 -> V_148 -> V_21 = 0 ;
F_58 ( V_6 -> V_194 ) ;
V_86 = F_32 ( V_6 -> V_194 , false ) ;
if ( V_86 )
return V_86 ;
F_41 ( V_6 -> V_194 ) ;
F_34 ( V_6 -> V_194 ) ;
F_28 ( & V_6 -> V_194 ) ;
return 0 ;
}
int F_113 ( struct V_5 * V_6 )
{
int V_12 ;
int V_86 ;
F_114 ( V_6 -> V_39 ) ;
V_86 = F_110 ( V_6 ) ;
if ( V_86 )
return V_86 ;
V_6 -> V_39 -> V_46 . V_146 = ( void * ) & V_196 ;
V_6 -> V_39 -> V_46 . V_197 = 320 ;
V_6 -> V_39 -> V_46 . V_198 = 200 ;
V_6 -> V_39 -> V_46 . V_199 = 8192 ;
V_6 -> V_39 -> V_46 . V_200 = 8192 ;
V_6 -> V_39 -> V_46 . V_201 = V_6 -> V_202 ;
F_115 ( V_6 -> V_39 ) ;
F_99 ( V_6 ) ;
for ( V_12 = 0 ; V_12 < V_191 ; ++ V_12 ) {
F_80 ( V_6 -> V_39 , V_12 ) ;
F_101 ( V_6 -> V_39 , V_12 ) ;
}
V_6 -> V_203 . V_204 = true ;
F_116 ( V_6 ) ;
return 0 ;
}
void F_117 ( struct V_5 * V_6 )
{
F_118 ( V_6 ) ;
F_112 ( V_6 ) ;
if ( V_6 -> V_203 . V_204 ) {
F_119 ( V_6 -> V_39 ) ;
V_6 -> V_203 . V_204 = false ;
}
}
