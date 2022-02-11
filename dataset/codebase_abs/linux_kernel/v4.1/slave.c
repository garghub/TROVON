static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 & ( 1 << V_3 ) )
return V_6 -> V_9 -> V_10 ( V_6 , V_3 , V_4 ) ;
return 0xffff ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_11 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 & ( 1 << V_3 ) )
return V_6 -> V_9 -> V_12 ( V_6 , V_3 , V_4 , V_11 ) ;
return 0 ;
}
void F_3 ( struct V_5 * V_6 )
{
V_6 -> V_13 -> V_7 = ( void * ) V_6 ;
V_6 -> V_13 -> V_14 = L_1 ;
V_6 -> V_13 -> V_15 = F_1 ;
V_6 -> V_13 -> V_16 = F_2 ;
snprintf ( V_6 -> V_13 -> V_17 , V_18 , L_2 ,
V_6 -> V_19 , V_6 -> V_20 -> V_21 ) ;
V_6 -> V_13 -> V_22 = V_6 -> V_23 ;
V_6 -> V_13 -> V_24 = ~ V_6 -> V_8 ;
}
static int F_4 ( const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
return V_28 -> V_22 -> V_29 -> V_30 -> V_31 ;
}
static inline bool F_6 ( struct V_27 * V_28 )
{
return ! ! V_28 -> V_32 ;
}
static int F_7 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
struct V_5 * V_6 = V_28 -> V_22 ;
T_2 V_34 = F_6 ( V_28 ) ?
V_35 : V_36 ;
int V_37 ;
if ( ! ( V_33 -> V_38 & V_39 ) )
return - V_40 ;
if ( ! F_8 ( V_26 -> V_41 , V_33 -> V_41 ) ) {
V_37 = F_9 ( V_33 , V_26 -> V_41 ) ;
if ( V_37 < 0 )
goto V_42;
}
if ( V_26 -> V_38 & V_43 ) {
V_37 = F_10 ( V_33 , 1 ) ;
if ( V_37 < 0 )
goto V_44;
}
if ( V_26 -> V_38 & V_45 ) {
V_37 = F_11 ( V_33 , 1 ) ;
if ( V_37 < 0 )
goto V_46;
}
if ( V_6 -> V_9 -> V_47 ) {
V_37 = V_6 -> V_9 -> V_47 ( V_6 , V_28 -> V_48 , V_28 -> V_49 ) ;
if ( V_37 )
goto V_50;
}
if ( V_6 -> V_9 -> V_51 )
V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 , V_34 ) ;
if ( V_28 -> V_49 )
F_12 ( V_28 -> V_49 ) ;
return 0 ;
V_50:
if ( V_26 -> V_38 & V_45 )
F_11 ( V_33 , 0 ) ;
V_46:
if ( V_26 -> V_38 & V_43 )
F_10 ( V_33 , - 1 ) ;
V_44:
if ( ! F_8 ( V_26 -> V_41 , V_33 -> V_41 ) )
F_13 ( V_33 , V_26 -> V_41 ) ;
V_42:
return V_37 ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_28 -> V_49 )
F_15 ( V_28 -> V_49 ) ;
F_16 ( V_33 , V_26 ) ;
F_17 ( V_33 , V_26 ) ;
if ( V_26 -> V_38 & V_43 )
F_10 ( V_33 , - 1 ) ;
if ( V_26 -> V_38 & V_45 )
F_11 ( V_33 , - 1 ) ;
if ( ! F_8 ( V_26 -> V_41 , V_33 -> V_41 ) )
F_13 ( V_33 , V_26 -> V_41 ) ;
if ( V_6 -> V_9 -> V_52 )
V_6 -> V_9 -> V_52 ( V_6 , V_28 -> V_48 , V_28 -> V_49 ) ;
if ( V_6 -> V_9 -> V_51 )
V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 , V_53 ) ;
return 0 ;
}
static void F_18 ( struct V_25 * V_26 , int V_54 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
if ( V_54 & V_43 )
F_10 ( V_33 , V_26 -> V_38 & V_43 ? 1 : - 1 ) ;
if ( V_54 & V_45 )
F_11 ( V_33 , V_26 -> V_38 & V_45 ? 1 : - 1 ) ;
}
static void F_19 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
F_20 ( V_33 , V_26 ) ;
F_21 ( V_33 , V_26 ) ;
}
static int F_22 ( struct V_25 * V_26 , void * V_55 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
struct V_56 * V_3 = V_55 ;
int V_37 ;
if ( ! F_23 ( V_3 -> V_57 ) )
return - V_58 ;
if ( ! ( V_26 -> V_38 & V_39 ) )
goto V_42;
if ( ! F_8 ( V_3 -> V_57 , V_33 -> V_41 ) ) {
V_37 = F_9 ( V_33 , V_3 -> V_57 ) ;
if ( V_37 < 0 )
return V_37 ;
}
if ( ! F_8 ( V_26 -> V_41 , V_33 -> V_41 ) )
F_13 ( V_33 , V_26 -> V_41 ) ;
V_42:
F_24 ( V_26 -> V_41 , V_3 -> V_57 ) ;
return 0 ;
}
static int F_25 ( struct V_59 * V_60 , struct V_61 * V_62 [] ,
struct V_25 * V_26 ,
const unsigned char * V_3 , T_1 V_63 , T_1 V_64 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_65 = - V_66 ;
if ( V_6 -> V_9 -> V_67 )
V_65 = V_6 -> V_9 -> V_67 ( V_6 , V_28 -> V_48 , V_3 , V_63 ) ;
return V_65 ;
}
static int F_26 ( struct V_59 * V_60 , struct V_61 * V_62 [] ,
struct V_25 * V_26 ,
const unsigned char * V_3 , T_1 V_63 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_65 = - V_66 ;
if ( V_6 -> V_9 -> V_68 )
V_65 = V_6 -> V_9 -> V_68 ( V_6 , V_28 -> V_48 , V_3 , V_63 ) ;
return V_65 ;
}
static int F_27 ( struct V_25 * V_26 , struct V_69 * V_70 ,
const unsigned char * V_3 , T_1 V_63 ,
bool V_71 ,
T_3 V_72 , T_3 V_73 , int type ,
unsigned int V_38 )
{
struct V_74 * V_75 ;
struct V_59 * V_60 ;
V_75 = F_28 ( V_70 , V_72 , V_73 , type , sizeof( * V_60 ) , V_38 ) ;
if ( ! V_75 )
return - V_76 ;
V_60 = F_29 ( V_75 ) ;
V_60 -> V_77 = V_78 ;
V_60 -> V_79 = 0 ;
V_60 -> V_80 = 0 ;
V_60 -> V_81 = V_82 ;
V_60 -> V_83 = 0 ;
V_60 -> V_84 = V_26 -> V_31 ;
V_60 -> V_85 = V_71 ? V_86 : V_87 ;
if ( F_30 ( V_70 , V_88 , V_89 , V_3 ) )
goto V_90;
if ( V_63 && F_31 ( V_70 , V_91 , V_63 ) )
goto V_90;
F_32 ( V_70 , V_75 ) ;
return 0 ;
V_90:
F_33 ( V_70 , V_75 ) ;
return - V_76 ;
}
static int F_34 ( struct V_69 * V_70 , struct V_92 * V_93 ,
struct V_25 * V_26 ,
struct V_25 * V_94 , int V_95 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
unsigned char V_3 [ V_89 ] = { 0 } ;
int V_65 ;
if ( ! V_6 -> V_9 -> V_96 )
return - V_66 ;
for (; ; V_95 ++ ) {
bool V_71 ;
V_65 = V_6 -> V_9 -> V_96 ( V_6 , V_28 -> V_48 , V_3 , & V_71 ) ;
if ( V_65 < 0 )
break;
if ( V_95 < V_93 -> args [ 0 ] )
continue;
V_65 = F_27 ( V_26 , V_70 , V_3 , 0 ,
V_71 ,
F_35 ( V_93 -> V_70 ) . V_72 ,
V_93 -> V_75 -> V_97 ,
V_98 , V_99 ) ;
if ( V_65 < 0 )
break;
}
return V_95 ;
}
static int F_36 ( struct V_25 * V_26 , struct V_100 * V_101 , int V_102 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_37 ( V_28 -> V_49 , V_101 , V_102 ) ;
return - V_66 ;
}
static T_3 F_38 ( struct V_5 * V_6 ,
struct V_25 * V_103 )
{
struct V_27 * V_28 ;
unsigned int V_48 ;
T_3 V_104 = 0 ;
for ( V_48 = 0 ; V_48 < V_105 ; V_48 ++ ) {
if ( ! F_39 ( V_6 , V_48 ) )
continue;
V_28 = F_5 ( V_6 -> V_106 [ V_48 ] ) ;
if ( V_6 -> V_106 [ V_48 ] -> V_107 & V_108 &&
V_28 -> V_32 == V_103 )
V_104 |= 1 << V_48 ;
}
return V_104 ;
}
static int F_40 ( struct V_25 * V_26 , T_2 V_109 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_65 = - V_66 ;
if ( V_6 -> V_9 -> V_51 )
V_65 = V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 , V_109 ) ;
return V_65 ;
}
static int F_41 ( struct V_25 * V_26 ,
struct V_25 * V_110 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_65 = - V_66 ;
V_28 -> V_32 = V_110 ;
if ( V_6 -> V_9 -> V_111 )
V_65 = V_6 -> V_9 -> V_111 ( V_6 , V_28 -> V_48 ,
F_38 ( V_6 , V_110 ) ) ;
return V_65 ;
}
static int F_42 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_65 = - V_66 ;
if ( V_6 -> V_9 -> V_112 )
V_65 = V_6 -> V_9 -> V_112 ( V_6 , V_28 -> V_48 ,
F_38 ( V_6 , V_28 -> V_32 ) ) ;
V_28 -> V_32 = NULL ;
F_40 ( V_26 , V_36 ) ;
return V_65 ;
}
static int F_43 ( struct V_25 * V_26 ,
struct V_113 * V_114 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
V_114 -> V_115 = sizeof( V_6 -> V_19 ) ;
memcpy ( & V_114 -> V_17 , & V_6 -> V_19 , V_114 -> V_115 ) ;
return 0 ;
}
static T_4 F_44 ( struct V_69 * V_70 , struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
return V_28 -> V_116 ( V_70 , V_26 ) ;
}
static T_4 F_45 ( struct V_69 * V_70 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
V_70 -> V_26 = V_28 -> V_22 -> V_29 -> V_30 ;
F_46 ( V_70 ) ;
return V_117 ;
}
static int
F_47 ( struct V_25 * V_26 , struct V_118 * V_102 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_37 ;
V_37 = - V_66 ;
if ( V_28 -> V_49 != NULL ) {
V_37 = F_48 ( V_28 -> V_49 ) ;
if ( V_37 == 0 )
V_37 = F_49 ( V_28 -> V_49 , V_102 ) ;
}
return V_37 ;
}
static int
F_50 ( struct V_25 * V_26 , struct V_118 * V_102 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_51 ( V_28 -> V_49 , V_102 ) ;
return - V_66 ;
}
static void F_52 ( struct V_25 * V_26 ,
struct V_119 * V_120 )
{
F_53 ( V_120 -> V_121 , L_3 , sizeof( V_120 -> V_121 ) ) ;
F_53 ( V_120 -> V_122 , V_123 , sizeof( V_120 -> V_122 ) ) ;
F_53 ( V_120 -> V_124 , L_4 , sizeof( V_120 -> V_124 ) ) ;
F_53 ( V_120 -> V_125 , L_5 , sizeof( V_120 -> V_125 ) ) ;
}
static int F_54 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_126 )
return V_6 -> V_9 -> V_126 ( V_6 , V_28 -> V_48 ) ;
return - V_66 ;
}
static void
F_55 ( struct V_25 * V_26 , struct V_127 * V_128 , void * V_129 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_130 )
V_6 -> V_9 -> V_130 ( V_6 , V_28 -> V_48 , V_128 , V_129 ) ;
}
static int F_56 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_57 ( V_28 -> V_49 ) ;
return - V_66 ;
}
static T_3 F_58 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL ) {
F_59 ( V_28 -> V_49 ) ;
return V_28 -> V_49 -> V_131 ;
}
return - V_66 ;
}
static int F_60 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_20 -> V_132 )
return V_6 -> V_20 -> V_132 ;
if ( V_6 -> V_9 -> V_133 )
return V_6 -> V_9 -> V_133 ( V_6 ) ;
return 0 ;
}
static int F_61 ( struct V_25 * V_26 ,
struct V_134 * V_135 , T_2 * V_136 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_137 )
return V_6 -> V_9 -> V_137 ( V_6 , V_135 , V_136 ) ;
return - V_66 ;
}
static int F_62 ( struct V_25 * V_26 ,
struct V_134 * V_135 , T_2 * V_136 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_138 )
return V_6 -> V_9 -> V_138 ( V_6 , V_135 , V_136 ) ;
return - V_66 ;
}
static void F_63 ( struct V_25 * V_26 ,
T_5 V_139 , T_6 * V_136 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_139 == V_140 ) {
int V_141 = V_142 ;
strncpy ( V_136 , L_6 , V_141 ) ;
strncpy ( V_136 + V_141 , L_7 , V_141 ) ;
strncpy ( V_136 + 2 * V_141 , L_8 , V_141 ) ;
strncpy ( V_136 + 3 * V_141 , L_9 , V_141 ) ;
if ( V_6 -> V_9 -> V_143 != NULL )
V_6 -> V_9 -> V_143 ( V_6 , V_28 -> V_48 , V_136 + 4 * V_141 ) ;
}
}
static void F_64 ( struct V_25 * V_26 ,
struct V_144 * V_145 ,
T_7 * V_136 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
V_136 [ 0 ] = V_28 -> V_26 -> V_145 . V_146 ;
V_136 [ 1 ] = V_28 -> V_26 -> V_145 . V_147 ;
V_136 [ 2 ] = V_28 -> V_26 -> V_145 . V_148 ;
V_136 [ 3 ] = V_28 -> V_26 -> V_145 . V_149 ;
if ( V_6 -> V_9 -> V_150 != NULL )
V_6 -> V_9 -> V_150 ( V_6 , V_28 -> V_48 , V_136 + 4 ) ;
}
static int F_65 ( struct V_25 * V_26 , int V_151 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_151 == V_140 ) {
int V_152 ;
V_152 = 4 ;
if ( V_6 -> V_9 -> V_153 != NULL )
V_152 += V_6 -> V_9 -> V_153 ( V_6 ) ;
return V_152 ;
}
return - V_66 ;
}
static void F_66 ( struct V_25 * V_26 , struct V_154 * V_155 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_156 )
V_6 -> V_9 -> V_156 ( V_6 , V_28 -> V_48 , V_155 ) ;
}
static int F_67 ( struct V_25 * V_26 , struct V_154 * V_155 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_65 = - V_66 ;
if ( V_6 -> V_9 -> V_157 )
V_65 = V_6 -> V_9 -> V_157 ( V_6 , V_28 -> V_48 , V_155 ) ;
return V_65 ;
}
static int F_68 ( struct V_25 * V_26 , struct V_158 * V_159 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_65 ;
if ( ! V_6 -> V_9 -> V_160 )
return - V_66 ;
V_65 = V_6 -> V_9 -> V_160 ( V_6 , V_28 -> V_48 , V_28 -> V_49 , V_159 ) ;
if ( V_65 )
return V_65 ;
if ( V_28 -> V_49 )
V_65 = F_69 ( V_28 -> V_49 , V_159 ) ;
return V_65 ;
}
static int F_70 ( struct V_25 * V_26 , struct V_158 * V_159 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_65 ;
if ( ! V_6 -> V_9 -> V_161 )
return - V_66 ;
V_65 = V_6 -> V_9 -> V_161 ( V_6 , V_28 -> V_48 , V_159 ) ;
if ( V_65 )
return V_65 ;
if ( V_28 -> V_49 )
V_65 = F_71 ( V_28 -> V_49 , V_159 ) ;
return V_65 ;
}
static void F_72 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
unsigned int V_162 = 0 ;
if ( V_28 -> V_163 != V_28 -> V_49 -> V_131 ) {
V_162 = 1 ;
V_28 -> V_163 = V_28 -> V_49 -> V_131 ;
}
if ( V_28 -> V_164 != V_28 -> V_49 -> V_165 ) {
V_162 = 1 ;
V_28 -> V_164 = V_28 -> V_49 -> V_165 ;
}
if ( V_28 -> V_166 != V_28 -> V_49 -> V_167 ) {
V_162 = 1 ;
V_28 -> V_166 = V_28 -> V_49 -> V_167 ;
}
if ( V_6 -> V_9 -> V_168 && V_162 )
V_6 -> V_9 -> V_168 ( V_6 , V_28 -> V_48 , V_28 -> V_49 ) ;
if ( V_162 )
F_73 ( V_28 -> V_49 ) ;
}
static int F_74 ( struct V_25 * V_26 ,
struct V_169 * V_170 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_171 )
V_6 -> V_9 -> V_171 ( V_6 , V_28 -> V_48 , V_170 ) ;
return 0 ;
}
static int F_75 ( struct V_27 * V_28 ,
struct V_25 * V_172 ,
int V_3 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
V_28 -> V_49 = V_6 -> V_13 -> V_173 [ V_3 ] ;
if ( ! V_28 -> V_49 )
return - V_174 ;
V_28 -> V_175 = V_28 -> V_49 -> V_176 ;
F_76 ( V_172 , V_28 -> V_49 , F_72 ,
V_28 -> V_175 ) ;
return 0 ;
}
static int F_77 ( struct V_27 * V_28 ,
struct V_25 * V_172 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
struct V_177 * V_178 = V_6 -> V_20 ;
struct V_179 * V_180 , * V_181 ;
bool V_182 = false ;
T_3 V_183 = 0 ;
int V_184 , V_65 ;
V_181 = V_178 -> V_181 [ V_28 -> V_48 ] ;
V_184 = F_78 ( V_181 ) ;
if ( V_184 < 0 )
V_184 = V_185 ;
V_28 -> V_175 = V_184 ;
V_180 = F_79 ( V_181 , L_10 , 0 ) ;
if ( F_80 ( V_181 ) ) {
V_65 = F_81 ( V_181 ) ;
if ( V_65 ) {
F_82 ( V_172 , L_11 ) ;
return V_65 ;
}
V_182 = true ;
V_180 = V_181 ;
}
if ( V_6 -> V_9 -> V_186 )
V_183 = V_6 -> V_9 -> V_186 ( V_6 , V_28 -> V_48 ) ;
if ( V_180 ) {
V_65 = F_83 ( & V_172 -> V_26 , V_180 ) ;
if ( ! V_182 && V_65 >= 0 &&
( V_6 -> V_8 & ( 1 << V_65 ) ) ) {
V_65 = F_75 ( V_28 , V_172 , V_65 ) ;
if ( V_65 )
return V_65 ;
} else {
V_28 -> V_49 = F_84 ( V_172 , V_180 ,
F_72 ,
V_183 ,
V_28 -> V_175 ) ;
}
}
if ( V_28 -> V_49 && V_182 )
F_85 ( V_28 -> V_49 , F_74 ) ;
if ( ! V_28 -> V_49 ) {
V_65 = F_75 ( V_28 , V_172 , V_28 -> V_48 ) ;
if ( V_65 )
return V_65 ;
} else {
F_86 ( V_172 , L_12 ,
V_28 -> V_49 -> V_3 , V_28 -> V_49 -> V_9 -> V_14 ) ;
}
return 0 ;
}
int F_87 ( struct V_25 * V_172 )
{
struct V_27 * V_28 = F_5 ( V_172 ) ;
F_88 ( V_172 ) ;
if ( V_28 -> V_49 ) {
F_15 ( V_28 -> V_49 ) ;
V_28 -> V_166 = - 1 ;
V_28 -> V_163 = - 1 ;
V_28 -> V_164 = - 1 ;
F_89 ( V_28 -> V_49 ) ;
}
return 0 ;
}
int F_90 ( struct V_25 * V_172 )
{
struct V_27 * V_28 = F_5 ( V_172 ) ;
F_91 ( V_172 ) ;
if ( V_28 -> V_49 ) {
F_92 ( V_28 -> V_49 ) ;
F_12 ( V_28 -> V_49 ) ;
}
return 0 ;
}
int F_93 ( struct V_5 * V_6 , struct V_187 * V_22 ,
int V_48 , char * V_14 )
{
struct V_25 * V_33 = V_6 -> V_29 -> V_30 ;
struct V_25 * V_172 ;
struct V_27 * V_28 ;
int V_65 ;
V_172 = F_94 ( sizeof( struct V_27 ) , V_14 ,
V_188 , V_189 ) ;
if ( V_172 == NULL )
return - V_190 ;
V_172 -> V_191 = V_33 -> V_192 ;
V_172 -> V_193 = & V_194 ;
F_95 ( V_172 , V_33 ) ;
V_172 -> V_195 = 0 ;
V_172 -> V_196 = & V_197 ;
V_172 -> V_198 = & V_199 ;
F_96 ( V_172 , V_22 ) ;
V_172 -> V_26 . V_200 = V_6 -> V_20 -> V_181 [ V_48 ] ;
V_172 -> V_192 = V_33 -> V_192 ;
V_28 = F_5 ( V_172 ) ;
V_28 -> V_26 = V_172 ;
V_28 -> V_22 = V_6 ;
V_28 -> V_48 = V_48 ;
switch ( V_6 -> V_29 -> V_201 ) {
#ifdef F_97
case V_202 :
V_28 -> V_116 = V_203 . V_116 ;
break;
#endif
#ifdef F_98
case V_204 :
V_28 -> V_116 = V_205 . V_116 ;
break;
#endif
#ifdef F_99
case V_206 :
V_28 -> V_116 = V_207 . V_116 ;
break;
#endif
#ifdef F_100
case V_208 :
V_28 -> V_116 = V_209 . V_116 ;
break;
#endif
default:
V_28 -> V_116 = F_45 ;
break;
}
V_28 -> V_166 = - 1 ;
V_28 -> V_163 = - 1 ;
V_28 -> V_164 = - 1 ;
V_65 = F_77 ( V_28 , V_172 ) ;
if ( V_65 ) {
F_101 ( V_172 ) ;
return V_65 ;
}
V_6 -> V_106 [ V_48 ] = V_172 ;
V_65 = F_102 ( V_172 ) ;
if ( V_65 ) {
F_82 ( V_33 , L_13 ,
V_65 , V_172 -> V_14 ) ;
F_103 ( V_28 -> V_49 ) ;
V_6 -> V_106 [ V_48 ] = NULL ;
F_101 ( V_172 ) ;
return V_65 ;
}
F_104 ( V_172 ) ;
return 0 ;
}
static bool F_105 ( struct V_25 * V_26 )
{
return V_26 -> V_196 == & V_197 ;
}
static int F_106 ( struct V_25 * V_26 )
{
struct V_25 * V_33 = F_107 ( V_26 ) ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_37 = 0 ;
if ( V_33 && V_33 -> V_210 &&
! strcmp ( V_33 -> V_210 -> V_211 , L_14 ) )
V_37 = F_41 ( V_26 , V_33 ) ;
else if ( F_6 ( V_28 ) )
V_37 = F_42 ( V_26 ) ;
return V_37 ;
}
int F_108 ( struct V_212 * V_213 ,
unsigned long V_214 , void * V_215 )
{
struct V_25 * V_26 ;
int V_37 = 0 ;
switch ( V_214 ) {
case V_216 :
V_26 = F_109 ( V_215 ) ;
if ( ! F_105 ( V_26 ) )
goto V_42;
V_37 = F_106 ( V_26 ) ;
if ( V_37 )
F_110 ( V_26 , L_15 ) ;
break;
}
V_42:
return V_217 ;
}
