void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_3 ( & V_2 [ V_1 ] . V_3 ) ;
}
void F_4 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_5 ( & V_2 [ V_1 ] . V_3 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 ;
char * V_9 = NULL ;
if ( F_7 ( V_5 -> V_10 , & V_9 ) )
return;
if ( ! F_8 ( V_9 ,
V_5 ,
V_7 ) )
return;
if ( V_7 -> V_11 ) {
const char * V_12 ;
switch ( V_7 -> V_11 ) {
case V_13 :
V_12 = L_1 ;
break;
case V_14 :
V_12 = L_2 ;
break;
default:
case V_15 :
V_12 = L_3 ;
break;
}
F_9 ( L_4 , V_5 -> V_10 , V_12 ) ;
V_5 -> V_11 = V_7 -> V_11 ;
}
F_10 ( L_5 ,
V_5 -> V_10 ,
V_7 -> V_16 , V_7 -> V_17 ,
V_7 -> V_18 ? V_7 -> V_19 : 60 ,
V_7 -> V_20 ? L_6 : L_7 ,
V_7 -> V_21 ? L_8 : L_7 ,
V_7 -> V_22 ? L_9 : L_7 ) ;
}
static void F_11 ( struct V_23 * V_23 )
{
struct V_4 * V_5 =
F_12 ( V_23 , struct V_4 , V_24 . V_25 ) ;
struct V_26 * V_27 = V_5 -> V_27 ;
F_13 ( V_27 , & V_5 -> V_24 ) ;
V_5 -> V_28 -> V_29 ( V_5 ) ;
}
int F_14 ( struct V_26 * V_27 ,
struct V_4 * V_5 ,
const struct V_30 * V_28 ,
int V_31 )
{
struct V_32 * V_33 = & V_27 -> V_34 ;
int V_35 ;
struct V_3 * V_36 =
& V_2 [ V_31 ] . V_3 ;
F_15 ( V_27 ) ;
V_35 = F_16 ( V_27 , & V_5 -> V_24 ,
V_37 ,
false , F_11 ) ;
if ( V_35 )
goto V_38;
V_5 -> V_24 . V_39 = & V_5 -> V_39 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_28 = V_28 ;
V_35 = F_17 ( & V_33 -> V_36 , 0 , 0 , V_40 ) ;
if ( V_35 < 0 )
goto V_41;
V_5 -> V_42 = V_35 ;
V_35 = 0 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_43 =
F_17 ( V_36 , 1 , 0 , V_40 ) ;
if ( V_5 -> V_43 < 0 ) {
V_35 = V_5 -> V_43 ;
goto V_44;
}
V_5 -> V_10 =
F_18 ( V_40 , L_10 ,
V_2 [ V_31 ] . V_10 ,
V_5 -> V_43 ) ;
if ( ! V_5 -> V_10 ) {
V_35 = - V_45 ;
goto V_46;
}
F_19 ( & V_5 -> V_47 ) ;
F_19 ( & V_5 -> V_48 ) ;
V_5 -> V_49 = NULL ;
V_5 -> V_50 = V_51 ;
F_6 ( V_5 ) ;
F_20 ( & V_5 -> V_52 , & V_33 -> V_53 ) ;
V_33 -> V_54 ++ ;
if ( V_31 != V_55 )
F_21 ( & V_5 -> V_24 ,
V_33 -> V_56 ,
0 ) ;
F_21 ( & V_5 -> V_24 ,
V_33 -> V_57 , 0 ) ;
if ( F_22 ( V_27 , V_58 ) ) {
F_21 ( & V_5 -> V_24 , V_33 -> V_59 , 0 ) ;
}
V_5 -> V_60 = NULL ;
V_46:
if ( V_35 )
F_23 ( V_36 , V_5 -> V_43 ) ;
V_44:
if ( V_35 )
F_23 ( & V_33 -> V_36 , V_5 -> V_42 ) ;
V_41:
if ( V_35 )
F_13 ( V_27 , & V_5 -> V_24 ) ;
V_38:
F_24 ( V_27 ) ;
return V_35 ;
}
int F_25 ( struct V_4 * V_5 ,
struct V_61 * V_62 )
{
int V_1 ;
if ( F_26 ( V_5 -> V_62 ) )
return - V_63 ;
for ( V_1 = 0 ; V_1 < V_64 ; V_1 ++ ) {
if ( V_5 -> V_65 [ V_1 ] == 0 ) {
V_5 -> V_65 [ V_1 ] = V_62 -> V_24 . V_66 ;
return 0 ;
}
}
return - V_45 ;
}
static void F_27 ( struct V_4 * V_5 ,
struct V_67 * V_7 )
{
F_28 ( & V_7 -> V_52 ) ;
F_29 ( V_5 -> V_27 , V_7 ) ;
}
void F_30 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
struct V_67 * V_7 , * V_68 ;
if ( F_26 ( V_5 -> V_69 ) )
F_31 ( V_5 ) ;
if ( V_5 -> V_70 ) {
F_32 ( V_27 , V_5 -> V_70 ) ;
V_5 -> V_70 = NULL ;
}
F_33 (mode, t, &connector->probed_modes, head)
F_27 ( V_5 , V_7 ) ;
F_33 (mode, t, &connector->modes, head)
F_27 ( V_5 , V_7 ) ;
F_23 ( & V_2 [ V_5 -> V_31 ] . V_3 ,
V_5 -> V_43 ) ;
F_23 ( & V_27 -> V_34 . V_36 ,
V_5 -> V_42 ) ;
F_34 ( V_5 -> V_71 . V_72 ) ;
F_13 ( V_27 , & V_5 -> V_24 ) ;
F_34 ( V_5 -> V_10 ) ;
V_5 -> V_10 = NULL ;
F_28 ( & V_5 -> V_52 ) ;
V_27 -> V_34 . V_54 -- ;
F_26 ( V_5 -> V_73 && ! V_5 -> V_28 -> V_74 ) ;
if ( V_5 -> V_73 && V_5 -> V_28 -> V_74 )
V_5 -> V_28 -> V_74 ( V_5 ,
V_5 -> V_73 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
int F_35 ( struct V_4 * V_5 )
{
int V_35 ;
if ( V_5 -> V_69 )
return 0 ;
V_35 = F_36 ( V_5 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_37 ( V_5 ) ;
if ( V_35 ) {
goto V_75;
}
if ( V_5 -> V_28 -> V_76 ) {
V_35 = V_5 -> V_28 -> V_76 ( V_5 ) ;
if ( V_35 )
goto V_77;
}
F_38 ( V_5 -> V_27 , & V_5 -> V_24 ) ;
V_5 -> V_69 = true ;
return 0 ;
V_77:
F_39 ( V_5 ) ;
V_75:
F_40 ( V_5 ) ;
return V_35 ;
}
void F_31 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_69 )
return;
if ( V_5 -> V_28 -> V_78 )
V_5 -> V_28 -> V_78 ( V_5 ) ;
F_40 ( V_5 ) ;
F_39 ( V_5 ) ;
V_5 -> V_69 = false ;
}
void F_41 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
F_42 (connector, &dev->mode_config.connector_list, head)
F_31 ( V_5 ) ;
}
int F_43 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_35 ;
F_42 (connector, &dev->mode_config.connector_list, head) {
V_35 = F_35 ( V_5 ) ;
if ( V_35 )
goto V_79;
}
return 0 ;
V_79:
F_44 ( & V_27 -> V_34 . V_80 ) ;
F_41 ( V_27 ) ;
return V_35 ;
}
const char * F_45 ( enum V_81 V_50 )
{
if ( V_50 == V_82 )
return L_11 ;
else if ( V_50 == V_83 )
return L_12 ;
else
return L_13 ;
}
const char * F_46 ( enum V_84 V_85 )
{
return V_86 [ V_85 ] . V_10 ;
}
int F_47 ( struct V_87 * V_88 ,
const T_1 * V_89 ,
unsigned int V_90 )
{
T_1 * V_91 = NULL ;
if ( ! V_89 && V_90 )
return - V_63 ;
if ( V_89 && V_90 ) {
V_91 = F_48 ( V_89 , sizeof( * V_89 ) * V_90 ,
V_40 ) ;
if ( ! V_91 )
return - V_45 ;
}
F_34 ( V_88 -> V_72 ) ;
V_88 -> V_72 = V_91 ;
V_88 -> V_92 = V_90 ;
return 0 ;
}
int F_49 ( struct V_26 * V_27 )
{
struct V_93 * V_94 ;
V_94 = F_50 ( V_27 , V_95 |
V_96 ,
L_14 , 0 ) ;
if ( ! V_94 )
return - V_45 ;
V_27 -> V_34 . V_56 = V_94 ;
V_94 = F_51 ( V_27 , 0 ,
L_15 , V_97 ,
F_2 ( V_97 ) ) ;
if ( ! V_94 )
return - V_45 ;
V_27 -> V_34 . V_57 = V_94 ;
V_94 = F_50 ( V_27 ,
V_95 |
V_96 ,
L_16 , 0 ) ;
if ( ! V_94 )
return - V_45 ;
V_27 -> V_34 . V_98 = V_94 ;
V_94 = F_50 ( V_27 ,
V_95 |
V_96 ,
L_17 , 0 ) ;
if ( ! V_94 )
return - V_45 ;
V_27 -> V_34 . V_99 = V_94 ;
return 0 ;
}
int F_52 ( struct V_26 * V_27 )
{
struct V_93 * V_100 ;
struct V_93 * V_101 ;
if ( V_27 -> V_34 . V_102 )
return 0 ;
V_100 =
F_51 ( V_27 , 0 ,
L_18 ,
V_103 ,
F_2 ( V_103 ) ) ;
V_27 -> V_34 . V_102 = V_100 ;
V_101 = F_51 ( V_27 , V_96 ,
L_19 ,
V_104 ,
F_2 ( V_104 ) ) ;
V_27 -> V_34 . V_105 = V_101 ;
return 0 ;
}
int F_53 ( struct V_26 * V_27 ,
unsigned int V_106 ,
const char * const V_48 [] )
{
struct V_93 * V_107 ;
struct V_93 * V_108 ;
unsigned int V_1 ;
if ( V_27 -> V_34 . V_109 )
return 0 ;
V_107 = F_51 ( V_27 , 0 ,
L_18 ,
V_110 ,
F_2 ( V_110 ) ) ;
if ( ! V_107 )
goto V_111;
V_27 -> V_34 . V_109 = V_107 ;
V_108 =
F_51 ( V_27 , V_96 ,
L_19 ,
V_112 ,
F_2 ( V_112 ) ) ;
if ( ! V_108 )
goto V_111;
V_27 -> V_34 . V_113 = V_108 ;
V_27 -> V_34 . V_114 =
F_54 ( V_27 , 0 , L_20 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_114 )
goto V_111;
V_27 -> V_34 . V_115 =
F_54 ( V_27 , 0 , L_21 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_115 )
goto V_111;
V_27 -> V_34 . V_116 =
F_54 ( V_27 , 0 , L_22 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_116 )
goto V_111;
V_27 -> V_34 . V_117 =
F_54 ( V_27 , 0 , L_23 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_117 )
goto V_111;
V_27 -> V_34 . V_118 =
F_50 ( V_27 , V_119 ,
L_24 , V_106 ) ;
if ( ! V_27 -> V_34 . V_118 )
goto V_111;
for ( V_1 = 0 ; V_1 < V_106 ; V_1 ++ )
F_55 ( V_27 -> V_34 . V_118 , V_1 ,
V_1 , V_48 [ V_1 ] ) ;
V_27 -> V_34 . V_120 =
F_54 ( V_27 , 0 , L_25 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_120 )
goto V_111;
V_27 -> V_34 . V_121 =
F_54 ( V_27 , 0 , L_26 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_121 )
goto V_111;
V_27 -> V_34 . V_122 =
F_54 ( V_27 , 0 , L_27 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_122 )
goto V_111;
V_27 -> V_34 . V_123 =
F_54 ( V_27 , 0 , L_28 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_123 )
goto V_111;
V_27 -> V_34 . V_124 =
F_54 ( V_27 , 0 , L_29 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_124 )
goto V_111;
V_27 -> V_34 . V_125 =
F_54 ( V_27 , 0 , L_30 , 0 , 100 ) ;
if ( ! V_27 -> V_34 . V_125 )
goto V_111;
return 0 ;
V_111:
return - V_45 ;
}
int F_56 ( struct V_26 * V_27 )
{
struct V_93 * V_126 ;
if ( V_27 -> V_34 . V_127 )
return 0 ;
V_126 =
F_51 ( V_27 , 0 , L_31 ,
V_128 ,
F_2 ( V_128 ) ) ;
V_27 -> V_34 . V_127 = V_126 ;
return 0 ;
}
int F_57 ( struct V_26 * V_27 )
{
if ( V_27 -> V_34 . V_129 )
return 0 ;
V_27 -> V_34 . V_129 =
F_51 ( V_27 , 0 , L_32 ,
V_130 ,
F_2 ( V_130 ) ) ;
if ( V_27 -> V_34 . V_129 == NULL )
return - V_45 ;
return 0 ;
}
int F_58 ( struct V_26 * V_27 )
{
if ( V_27 -> V_34 . V_131 && V_27 -> V_34 . V_132 )
return 0 ;
V_27 -> V_34 . V_131 =
F_54 ( V_27 , V_96 , L_33 , 0 , 0xffffffff ) ;
V_27 -> V_34 . V_132 =
F_54 ( V_27 , V_96 , L_34 , 0 , 0xffffffff ) ;
if ( V_27 -> V_34 . V_131 == NULL ||
V_27 -> V_34 . V_132 == NULL )
return - V_45 ;
return 0 ;
}
int F_59 ( struct V_4 * V_5 ,
const char * V_133 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
int V_35 ;
V_35 = F_60 ( V_27 ,
& V_5 -> V_134 ,
strlen ( V_133 ) + 1 ,
V_133 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_98 ) ;
return V_35 ;
}
int F_61 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
char V_135 [ 256 ] ;
int V_35 ;
if ( ! V_5 -> V_136 ) {
V_35 = F_60 ( V_27 ,
& V_5 -> V_137 ,
0 ,
NULL ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_99 ) ;
return V_35 ;
}
snprintf ( V_135 , 256 , L_35 ,
V_5 -> V_70 -> V_66 , V_5 -> V_138 ,
V_5 -> V_139 , V_5 -> V_140 ,
V_5 -> V_141 , V_5 -> V_142 ,
V_5 -> V_143 , V_5 -> V_144 ) ;
V_35 = F_60 ( V_27 ,
& V_5 -> V_137 ,
strlen ( V_135 ) + 1 ,
V_135 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_99 ) ;
return V_35 ;
}
int F_62 ( struct V_4 * V_5 ,
const struct V_145 * V_145 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
T_2 V_146 = 0 ;
int V_35 ;
if ( V_5 -> V_147 )
return 0 ;
if ( V_145 )
V_146 = V_148 * ( 1 + V_145 -> V_149 ) ;
V_35 = F_60 ( V_27 ,
& V_5 -> V_49 ,
V_146 ,
V_145 ,
& V_5 -> V_24 ,
V_27 -> V_34 . V_56 ) ;
return V_35 ;
}
int F_63 ( struct V_150 * V_151 ,
struct V_93 * V_152 ,
T_3 V_153 )
{
int V_35 = - V_63 ;
struct V_4 * V_5 = F_64 ( V_151 ) ;
if ( V_152 == V_5 -> V_27 -> V_34 . V_57 ) {
V_35 = (* V_5 -> V_28 -> V_154 )( V_5 , ( int ) V_153 ) ;
} else if ( V_5 -> V_28 -> V_155 )
V_35 = V_5 -> V_28 -> V_155 ( V_5 , V_152 , V_153 ) ;
if ( ! V_35 )
F_65 ( & V_5 -> V_24 , V_152 , V_153 ) ;
return V_35 ;
}
int F_66 ( struct V_26 * V_27 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_159 * V_160 = V_156 ;
struct V_161 V_162 = {
. V_153 = V_160 -> V_153 ,
. V_163 = V_160 -> V_163 ,
. V_164 = V_160 -> V_165 ,
. V_166 = V_37
} ;
return F_67 ( V_27 , & V_162 , V_158 ) ;
}
static struct V_61 * F_68 ( struct V_4 * V_5 )
{
if ( V_5 -> V_73 )
return V_5 -> V_73 -> V_167 ;
return V_5 -> V_62 ;
}
static bool F_69 ( const struct V_67 * V_7 ,
const struct V_157 * V_158 )
{
if ( ! V_158 -> V_168 && F_70 ( V_7 ) )
return false ;
return true ;
}
int F_71 ( struct V_26 * V_27 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_169 * V_170 = V_156 ;
struct V_4 * V_5 ;
struct V_61 * V_62 ;
struct V_67 * V_7 ;
int V_171 = 0 ;
int V_172 = 0 ;
int V_35 = 0 ;
int V_173 = 0 ;
int V_1 ;
struct V_174 V_175 ;
struct V_174 T_4 * V_176 ;
T_5 T_4 * V_177 ;
if ( ! F_22 ( V_27 , V_178 ) )
return - V_63 ;
memset ( & V_175 , 0 , sizeof( struct V_174 ) ) ;
F_72 ( & V_27 -> V_34 . V_80 ) ;
V_5 = F_73 ( V_27 , V_170 -> V_165 ) ;
if ( ! V_5 ) {
V_35 = - V_179 ;
goto V_38;
}
for ( V_1 = 0 ; V_1 < V_64 ; V_1 ++ )
if ( V_5 -> V_65 [ V_1 ] != 0 )
V_172 ++ ;
if ( V_170 -> V_180 == 0 ) {
V_5 -> V_28 -> V_181 ( V_5 ,
V_27 -> V_34 . V_182 ,
V_27 -> V_34 . V_183 ) ;
}
F_42 (mode, &connector->modes, head)
if ( F_69 ( V_7 , V_158 ) )
V_171 ++ ;
V_170 -> V_165 = V_5 -> V_24 . V_66 ;
V_170 -> V_31 = V_5 -> V_31 ;
V_170 -> V_43 = V_5 -> V_43 ;
V_170 -> V_184 = V_5 -> V_71 . V_185 ;
V_170 -> V_186 = V_5 -> V_71 . V_187 ;
V_170 -> V_188 = V_5 -> V_71 . V_84 ;
V_170 -> V_189 = V_5 -> V_50 ;
F_74 ( & V_27 -> V_34 . V_190 , NULL ) ;
V_62 = F_68 ( V_5 ) ;
if ( V_62 )
V_170 -> V_191 = V_62 -> V_24 . V_66 ;
else
V_170 -> V_191 = 0 ;
if ( ( V_170 -> V_180 >= V_171 ) && V_171 ) {
V_173 = 0 ;
V_176 = (struct V_174 T_4 * ) ( unsigned long ) V_170 -> V_192 ;
F_42 (mode, &connector->modes, head) {
if ( ! F_69 ( V_7 , V_158 ) )
continue;
F_75 ( & V_175 , V_7 ) ;
if ( F_76 ( V_176 + V_173 ,
& V_175 , sizeof( V_175 ) ) ) {
V_35 = - V_193 ;
goto V_194;
}
V_173 ++ ;
}
}
V_170 -> V_180 = V_171 ;
V_35 = F_77 ( & V_5 -> V_24 , V_158 -> V_195 ,
( T_5 T_4 * ) ( unsigned long ) ( V_170 -> V_196 ) ,
( T_3 T_4 * ) ( unsigned long ) ( V_170 -> V_197 ) ,
& V_170 -> V_198 ) ;
if ( V_35 )
goto V_194;
if ( ( V_170 -> V_199 >= V_172 ) && V_172 ) {
V_173 = 0 ;
V_177 = ( T_5 T_4 * ) ( unsigned long ) ( V_170 -> V_200 ) ;
for ( V_1 = 0 ; V_1 < V_64 ; V_1 ++ ) {
if ( V_5 -> V_65 [ V_1 ] != 0 ) {
if ( F_78 ( V_5 -> V_65 [ V_1 ] ,
V_177 + V_173 ) ) {
V_35 = - V_193 ;
goto V_194;
}
V_173 ++ ;
}
}
}
V_170 -> V_199 = V_172 ;
V_194:
F_79 ( & V_27 -> V_34 . V_190 ) ;
F_80 ( V_5 ) ;
V_38:
F_44 ( & V_27 -> V_34 . V_80 ) ;
return V_35 ;
}
