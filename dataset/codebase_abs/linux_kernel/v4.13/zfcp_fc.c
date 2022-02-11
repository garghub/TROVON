unsigned int F_1 ( void )
{
if ( ! V_1 )
return 0 ;
return F_2 () % V_1 ;
}
static void F_3 ( struct V_2 * V_3 )
{
unsigned long V_4 = F_4 ( V_5 ) ;
unsigned long V_6 = F_4 ( F_1 () ) ;
V_3 -> V_7 = V_8 + V_4 + V_6 ;
}
static void F_5 ( struct V_2 * V_3 )
{
unsigned long V_9 = V_8 ;
unsigned long V_10 = V_3 -> V_7 ;
unsigned long V_11 = 0 , V_12 ;
if ( F_6 ( V_9 , V_10 ) ) {
V_11 = V_10 - V_9 ;
V_12 = F_4 ( V_5 + V_1 ) ;
V_11 = F_7 ( V_11 , V_12 ) ;
}
F_8 ( V_3 -> V_13 , & V_3 -> V_14 , V_11 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
if ( V_15 )
return;
F_5 ( V_3 ) ;
}
void F_10 ( struct V_2 * V_3 )
{
if ( ! V_15 )
return;
F_5 ( V_3 ) ;
}
void F_11 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = NULL , * V_20 = NULL ;
F_12 ( V_21 ) ;
struct V_22 * V_23 = F_13 ( V_17 ,
struct V_22 , V_17 ) ;
struct V_2 * V_3 = F_13 ( V_23 , struct V_2 ,
V_23 ) ;
F_14 ( & V_23 -> V_24 ) ;
F_15 ( & V_23 -> V_25 , & V_21 ) ;
F_16 ( & V_23 -> V_24 ) ;
F_17 (event, tmp, &tmp_lh, list) {
F_18 ( V_3 -> V_26 , F_19 () ,
V_19 -> V_27 , V_19 -> V_28 ) ;
F_20 ( & V_19 -> V_25 ) ;
F_21 ( V_19 ) ;
}
}
void F_22 ( struct V_2 * V_3 ,
enum V_29 V_30 , T_1 V_31 )
{
struct V_18 * V_19 ;
V_19 = F_23 ( sizeof( struct V_18 ) , V_32 ) ;
if ( ! V_19 )
return;
V_19 -> V_27 = V_30 ;
V_19 -> V_28 = V_31 ;
F_24 ( & V_3 -> V_23 . V_24 ) ;
F_25 ( & V_19 -> V_25 , & V_3 -> V_23 . V_25 ) ;
F_26 ( & V_3 -> V_23 . V_24 ) ;
F_27 ( V_3 -> V_13 , & V_3 -> V_23 . V_17 ) ;
}
static int F_28 ( struct V_33 * V_34 )
{
if ( F_29 ( & V_34 -> V_35 ) )
return - V_36 ;
if ( V_34 -> V_37 == V_38 ||
V_34 -> V_37 == V_39 ) {
V_34 -> V_37 = V_40 ;
if ( F_30 ( V_34 ) )
V_34 -> V_37 = V_38 ;
}
F_31 ( & V_34 -> V_35 ) ;
F_32 ( V_34 -> V_41 ,
V_34 -> V_37 == V_42 ||
V_34 -> V_37 == V_38 ) ;
if ( V_34 -> V_37 == V_42 ) {
F_33 ( & V_34 -> V_43 ) ;
return 0 ;
}
return - V_44 ;
}
static void F_34 ( struct V_16 * V_17 )
{
struct V_45 * V_46 = F_35 ( V_17 ) ;
struct V_33 * V_34 =
F_13 ( V_46 , struct V_33 , V_17 ) ;
F_36 ( & V_34 -> V_35 ) ;
if ( ( F_37 ( & V_34 -> V_43 ) != 0 ) ||
( V_34 -> V_37 != V_42 ) )
goto V_47;
V_34 -> V_37 = V_39 ;
if ( F_38 ( V_34 ) ) {
V_34 -> V_37 = V_38 ;
F_39 ( & V_34 -> V_41 ) ;
}
V_47:
F_31 ( & V_34 -> V_35 ) ;
}
static void F_40 ( struct V_33 * V_34 )
{
if ( F_41 ( & V_34 -> V_43 ) != 0 )
return;
F_42 ( & V_34 -> V_17 , V_48 / 100 ) ;
}
static void F_43 ( struct V_33 * V_34 , T_1 V_49 ,
struct V_2 * V_3 )
{
F_44 ( & V_34 -> V_41 ) ;
V_34 -> V_3 = V_3 ;
V_34 -> V_49 = V_49 ;
V_34 -> V_37 = V_38 ;
F_45 ( & V_34 -> V_43 , 0 ) ;
F_46 ( & V_34 -> V_35 ) ;
F_47 ( & V_34 -> V_17 , F_34 ) ;
}
static void F_48 ( struct V_33 * V_50 )
{
F_49 ( & V_50 -> V_17 ) ;
F_36 ( & V_50 -> V_35 ) ;
V_50 -> V_37 = V_38 ;
F_31 ( & V_50 -> V_35 ) ;
}
void F_50 ( struct V_51 * V_52 )
{
if ( ! V_52 )
return;
F_48 ( & V_52 -> V_53 ) ;
F_48 ( & V_52 -> V_54 ) ;
F_48 ( & V_52 -> V_55 ) ;
F_48 ( & V_52 -> V_56 ) ;
}
static void F_51 ( struct V_57 * V_58 , T_1 V_59 ,
struct V_60 * V_61 )
{
unsigned long V_62 ;
struct V_2 * V_3 = V_58 -> V_3 ;
struct V_63 * V_64 ;
F_52 ( & V_3 -> V_65 , V_62 ) ;
F_53 (port, &adapter->port_list, list) {
if ( ( V_64 -> V_49 & V_59 ) == ( F_54 ( V_61 -> V_66 ) & V_59 ) )
F_55 ( V_64 ) ;
if ( ! V_64 -> V_49 )
F_56 ( V_64 ,
V_67 ,
L_1 ) ;
}
F_57 ( & V_3 -> V_65 , V_62 ) ;
}
static void F_58 ( struct V_57 * V_58 )
{
struct V_68 * V_69 = ( void * ) V_58 -> V_28 ;
struct V_70 * V_71 ;
struct V_60 * V_61 ;
T_2 V_72 ;
T_2 V_73 ;
unsigned int V_74 ;
V_71 = (struct V_70 * ) V_69 -> V_75 . V_28 ;
V_61 = (struct V_60 * ) V_71 ;
V_73 = V_71 -> V_76 / sizeof( struct V_60 ) ;
for ( V_72 = 1 ; V_72 < V_73 ; V_72 ++ ) {
V_61 ++ ;
V_74 = V_61 -> V_77 & V_78 ;
F_51 ( V_58 , V_79 [ V_74 ] ,
V_61 ) ;
F_22 ( V_58 -> V_3 , V_80 ,
* ( T_1 * ) V_61 ) ;
}
F_9 ( V_58 -> V_3 ) ;
}
static void F_59 ( struct V_57 * V_81 , T_3 V_82 )
{
unsigned long V_62 ;
struct V_2 * V_3 = V_81 -> V_3 ;
struct V_63 * V_64 ;
F_52 ( & V_3 -> V_65 , V_62 ) ;
F_53 (port, &adapter->port_list, list)
if ( V_64 -> V_82 == V_82 ) {
F_60 ( V_64 , 0 , L_2 ) ;
break;
}
F_57 ( & V_3 -> V_65 , V_62 ) ;
}
static void F_61 ( struct V_57 * V_81 )
{
struct V_68 * V_69 ;
struct V_83 * V_84 ;
V_69 = (struct V_68 * ) V_81 -> V_28 ;
V_84 = (struct V_83 * ) V_69 -> V_75 . V_28 ;
F_59 ( V_81 , V_84 -> V_85 ) ;
}
static void F_62 ( struct V_57 * V_81 )
{
struct V_68 * V_69 =
(struct V_68 * ) V_81 -> V_28 ;
struct V_86 * V_87 =
(struct V_86 * ) V_69 -> V_75 . V_28 ;
F_59 ( V_81 , V_87 -> V_88 ) ;
}
void F_63 ( struct V_57 * V_58 )
{
struct V_68 * V_69 =
(struct V_68 * ) V_58 -> V_28 ;
unsigned int V_89 = V_69 -> V_75 . V_28 [ 0 ] ;
F_64 ( L_3 , V_58 ) ;
if ( V_89 == V_90 )
F_61 ( V_58 ) ;
else if ( V_89 == V_91 )
F_62 ( V_58 ) ;
else if ( V_89 == V_92 )
F_58 ( V_58 ) ;
}
static void F_65 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = & V_94 -> V_96 ;
struct V_97 * V_98 = & V_94 -> V_99 . V_100 . V_101 ;
if ( V_96 -> V_37 )
return;
if ( V_98 -> V_102 . V_103 != V_104 )
return;
V_96 -> V_64 -> V_49 = F_54 ( V_98 -> V_100 . V_105 ) ;
}
static void F_66 ( void * V_28 )
{
F_67 ( V_28 ) ;
}
static void F_68 ( struct V_106 * V_102 , T_2 V_107 , T_2 V_108 )
{
V_102 -> V_109 = V_110 ;
V_102 -> V_111 = V_112 ;
V_102 -> V_113 = V_114 ;
V_102 -> V_103 = V_107 ;
V_102 -> V_115 = V_108 / 4 ;
}
static int F_69 ( struct V_63 * V_64 ,
struct V_93 * V_94 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
F_70 ( V_116 ) ;
struct V_117 * V_118 = & V_94 -> V_99 . V_100 . V_81 ;
struct V_97 * V_98 = & V_94 -> V_99 . V_100 . V_101 ;
int V_119 ;
V_94 -> V_96 . V_64 = V_64 ;
V_94 -> V_96 . V_120 = F_66 ;
V_94 -> V_96 . V_121 = & V_116 ;
V_94 -> V_96 . V_81 = & V_94 -> V_122 ;
V_94 -> V_96 . V_123 = & V_94 -> V_124 ;
F_71 ( & V_94 -> V_122 , V_118 , sizeof( * V_118 ) ) ;
F_71 ( & V_94 -> V_124 , V_98 , sizeof( * V_98 ) ) ;
F_68 ( & V_118 -> V_102 ,
V_125 , V_126 ) ;
V_118 -> V_100 . V_127 = V_64 -> V_82 ;
V_119 = F_72 ( & V_3 -> V_52 -> V_55 , & V_94 -> V_96 ,
V_3 -> V_128 . V_118 ,
V_129 ) ;
if ( ! V_119 ) {
F_73 ( & V_116 ) ;
F_65 ( V_94 ) ;
}
return V_119 ;
}
static int F_74 ( struct V_63 * V_64 )
{
int V_119 ;
struct V_93 * V_94 ;
struct V_2 * V_3 = V_64 -> V_3 ;
V_94 = F_75 ( V_3 -> V_128 . V_100 , V_32 ) ;
if ( ! V_94 )
return - V_130 ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_119 = F_28 ( & V_3 -> V_52 -> V_55 ) ;
if ( V_119 )
goto V_47;
V_119 = F_69 ( V_64 , V_94 ) ;
F_40 ( & V_3 -> V_52 -> V_55 ) ;
V_47:
F_76 ( V_94 , V_3 -> V_128 . V_100 ) ;
return V_119 ;
}
void F_77 ( struct V_16 * V_17 )
{
int V_119 ;
struct V_63 * V_64 = F_13 ( V_17 , struct V_63 ,
V_131 ) ;
V_119 = F_74 ( V_64 ) ;
if ( V_119 ) {
F_78 ( V_64 -> V_3 , 0 , L_4 ) ;
goto V_47;
}
if ( ! V_64 -> V_49 ) {
F_79 ( V_64 , V_67 ) ;
goto V_47;
}
F_56 ( V_64 , 0 , L_5 ) ;
V_47:
F_80 ( & V_64 -> V_132 ) ;
}
void F_81 ( struct V_63 * V_64 )
{
F_82 ( & V_64 -> V_132 ) ;
if ( ! F_27 ( V_64 -> V_3 -> V_13 , & V_64 -> V_131 ) )
F_80 ( & V_64 -> V_132 ) ;
}
void F_83 ( struct V_63 * V_64 , struct V_83 * V_84 )
{
if ( V_84 -> V_85 != V_64 -> V_82 ) {
V_64 -> V_49 = 0 ;
F_84 ( & V_64 -> V_3 -> V_133 -> V_132 ,
L_6
L_7 ,
( unsigned long long ) V_64 -> V_82 ,
( unsigned long long ) V_84 -> V_85 ) ;
return;
}
V_64 -> V_134 = V_84 -> V_135 ;
V_64 -> V_136 = V_84 -> V_137 . V_138 ;
if ( V_84 -> V_139 [ 0 ] . V_140 & V_141 )
V_64 -> V_142 |= V_143 ;
if ( V_84 -> V_139 [ 1 ] . V_140 & V_141 )
V_64 -> V_142 |= V_144 ;
if ( V_84 -> V_139 [ 2 ] . V_140 & V_141 )
V_64 -> V_142 |= V_145 ;
if ( V_84 -> V_139 [ 3 ] . V_140 & V_141 )
V_64 -> V_142 |= V_146 ;
}
static void F_85 ( void * V_28 )
{
struct V_93 * V_94 = V_28 ;
struct V_63 * V_64 = V_94 -> V_96 . V_64 ;
struct V_147 * V_148 = & V_94 -> V_99 . V_149 . V_101 ;
if ( V_94 -> V_96 . V_37 ) {
F_60 ( V_64 , V_67 ,
L_8 ) ;
goto V_47;
}
if ( ! V_64 -> V_134 )
V_64 -> V_134 = V_148 -> V_150 ;
if ( ( V_64 -> V_82 != V_148 -> V_151 ) ||
! ( F_37 ( & V_64 -> V_37 ) & V_152 ) ) {
F_56 ( V_64 , V_67 ,
L_9 ) ;
goto V_47;
}
F_86 ( V_64 ) ;
V_47:
F_87 ( V_153 , & V_64 -> V_37 ) ;
F_80 ( & V_64 -> V_132 ) ;
F_88 ( V_154 , V_94 ) ;
}
static int F_89 ( struct V_63 * V_64 )
{
struct V_93 * V_94 ;
struct V_2 * V_3 = V_64 -> V_3 ;
struct V_155 * V_156 = V_3 -> V_26 ;
int V_119 ;
V_94 = F_90 ( V_154 , V_32 ) ;
if ( ! V_94 )
return - V_130 ;
V_94 -> V_96 . V_64 = V_64 ;
V_94 -> V_96 . V_81 = & V_94 -> V_122 ;
V_94 -> V_96 . V_123 = & V_94 -> V_124 ;
F_71 ( & V_94 -> V_122 , & V_94 -> V_99 . V_149 . V_81 ,
sizeof( struct V_147 ) ) ;
F_71 ( & V_94 -> V_124 , & V_94 -> V_99 . V_149 . V_101 ,
sizeof( struct V_147 ) ) ;
V_94 -> V_96 . V_120 = F_85 ;
V_94 -> V_96 . V_121 = V_94 ;
V_94 -> V_99 . V_149 . V_81 . V_151 = F_91 ( V_156 ) ;
V_94 -> V_99 . V_149 . V_81 . V_150 = F_92 ( V_156 ) ;
V_94 -> V_99 . V_149 . V_81 . V_157 = V_158 ;
F_93 ( V_94 -> V_99 . V_149 . V_81 . V_159 , F_94 ( V_156 ) ) ;
V_119 = F_95 ( V_3 , V_64 -> V_49 , & V_94 -> V_96 ,
V_129 ) ;
if ( V_119 )
F_88 ( V_154 , V_94 ) ;
return V_119 ;
}
void F_96 ( struct V_16 * V_17 )
{
struct V_63 * V_64 =
F_13 ( V_17 , struct V_63 , V_160 ) ;
int V_161 ;
F_82 ( & V_64 -> V_132 ) ;
V_64 -> V_162 = V_163 ;
F_97 ( & V_64 -> V_164 ) ;
if ( F_37 ( & V_64 -> V_37 ) & V_153 )
goto V_47;
F_98 ( V_153 , & V_64 -> V_37 ) ;
V_161 = F_89 ( V_64 ) ;
if ( V_161 == 0 )
return;
F_87 ( V_153 , & V_64 -> V_37 ) ;
F_60 ( V_64 , 0 , L_10 ) ;
V_47:
F_80 ( & V_64 -> V_132 ) ;
}
void F_55 ( struct V_63 * V_64 )
{
F_82 ( & V_64 -> V_132 ) ;
if ( ! F_27 ( V_64 -> V_3 -> V_13 , & V_64 -> V_160 ) )
F_80 ( & V_64 -> V_132 ) ;
}
static struct V_93 * F_99 ( int V_165 )
{
struct V_93 * V_94 ;
V_94 = F_90 ( V_154 , V_166 ) ;
if ( ! V_94 )
return NULL ;
if ( F_100 ( & V_94 -> V_124 , V_165 ) ) {
F_88 ( V_154 , V_94 ) ;
return NULL ;
}
F_71 ( & V_94 -> V_122 , & V_94 -> V_99 . V_167 . V_81 ,
sizeof( struct V_168 ) ) ;
return V_94 ;
}
static int F_101 ( struct V_93 * V_94 ,
struct V_2 * V_3 , int V_169 )
{
struct V_95 * V_96 = & V_94 -> V_96 ;
struct V_168 * V_81 = & V_94 -> V_99 . V_167 . V_81 ;
F_70 ( V_116 ) ;
int V_119 ;
F_68 ( & V_81 -> V_102 , V_170 , V_169 ) ;
V_81 -> V_167 . V_171 = V_172 ;
V_96 -> V_120 = F_66 ;
V_96 -> V_121 = & V_116 ;
V_96 -> V_81 = & V_94 -> V_122 ;
V_96 -> V_123 = & V_94 -> V_124 ;
V_119 = F_72 ( & V_3 -> V_52 -> V_55 , V_96 , NULL ,
V_129 ) ;
if ( ! V_119 )
F_73 ( & V_116 ) ;
return V_119 ;
}
static void F_102 ( struct V_63 * V_64 , struct V_173 * V_174 )
{
if ( ! ( F_37 ( & V_64 -> V_37 ) & V_175 ) )
return;
F_87 ( V_175 , & V_64 -> V_37 ) ;
if ( ( V_64 -> V_142 != 0 ) ||
! F_103 ( & V_64 -> V_176 ) )
return;
F_104 ( & V_64 -> V_25 , V_174 ) ;
}
static int F_105 ( struct V_93 * V_94 ,
struct V_2 * V_3 , int V_177 )
{
struct V_95 * V_96 = & V_94 -> V_96 ;
struct V_178 * V_179 = & V_94 -> V_124 ;
struct V_106 * V_180 = F_106 ( V_179 ) ;
struct V_181 * V_182 = F_106 ( V_179 ) ;
struct V_63 * V_64 , * V_20 ;
unsigned long V_62 ;
F_12 ( V_183 ) ;
T_1 V_49 ;
int V_119 = 0 , V_184 , V_185 = 0 ;
if ( V_96 -> V_37 )
return - V_44 ;
if ( V_180 -> V_103 != V_104 ) {
if ( V_180 -> V_186 == V_187 )
return - V_188 ;
return - V_44 ;
}
if ( V_180 -> V_115 ) {
F_84 ( & V_3 -> V_133 -> V_132 ,
L_11 ,
V_180 -> V_115 ) ;
return - V_189 ;
}
for ( V_184 = 1 ; V_184 < V_177 && ! V_185 ; V_184 ++ ) {
if ( V_184 % ( V_190 + 1 ) )
V_182 ++ ;
else
V_182 = F_106 ( ++ V_179 ) ;
V_185 = V_182 -> V_191 & V_192 ;
V_49 = F_54 ( V_182 -> V_105 ) ;
if ( V_49 >= V_193 )
continue;
if ( V_182 -> V_194 == F_91 ( V_3 -> V_26 ) )
continue;
V_64 = F_107 ( V_3 , V_182 -> V_194 ,
V_175 , V_49 ) ;
if ( ! F_108 ( V_64 ) )
F_56 ( V_64 , 0 , L_12 ) ;
else if ( F_109 ( V_64 ) != - V_195 )
V_119 = F_109 ( V_64 ) ;
}
F_110 ( V_3 ) ;
F_111 ( & V_3 -> V_65 , V_62 ) ;
F_17 (port, tmp, &adapter->port_list, list)
F_102 ( V_64 , & V_183 ) ;
F_112 ( & V_3 -> V_65 , V_62 ) ;
F_17 (port, tmp, &remove_lh, list) {
F_113 ( V_64 , 0 , L_13 ) ;
F_114 ( & V_64 -> V_132 ) ;
}
return V_119 ;
}
void F_115 ( struct V_16 * V_17 )
{
struct V_45 * V_46 = F_35 ( V_17 ) ;
struct V_2 * V_3 = F_13 ( V_46 , struct V_2 ,
V_14 ) ;
int V_119 , V_72 ;
struct V_93 * V_94 ;
int V_196 , V_177 , V_165 , V_169 ;
F_3 ( V_3 ) ;
V_196 = V_3 -> V_197 & V_198 ;
V_165 = V_196 ? V_199 : 1 ;
V_177 = V_196 ? V_200 : V_190 ;
V_169 = V_196 ? V_201 : V_126 ;
if ( F_116 ( V_3 -> V_26 ) != V_202 &&
F_116 ( V_3 -> V_26 ) != V_203 )
return;
if ( F_28 ( & V_3 -> V_52 -> V_55 ) )
return;
V_94 = F_99 ( V_165 ) ;
if ( ! V_94 )
goto V_47;
for ( V_72 = 0 ; V_72 < 3 ; V_72 ++ ) {
V_119 = F_101 ( V_94 , V_3 , V_169 ) ;
if ( ! V_119 ) {
V_119 = F_105 ( V_94 , V_3 , V_177 ) ;
if ( V_119 == - V_188 )
F_117 ( 1 ) ;
else
break;
}
}
F_118 ( & V_94 -> V_124 , V_165 ) ;
F_88 ( V_154 , V_94 ) ;
V_47:
F_40 ( & V_3 -> V_52 -> V_55 ) ;
}
static int F_119 ( struct V_2 * V_3 ,
struct V_93 * V_94 )
{
F_70 ( V_116 ) ;
char V_204 [] = L_14 ;
struct V_95 * V_96 = & V_94 -> V_96 ;
struct V_205 * V_206 = & V_94 -> V_99 . V_207 . V_81 ;
struct V_208 * V_209 = & V_94 -> V_99 . V_207 . V_101 ;
int V_119 ;
F_68 ( & V_206 -> V_102 , V_210 ,
V_211 ) ;
F_93 ( V_206 -> V_207 . V_105 , F_94 ( V_3 -> V_26 ) ) ;
F_71 ( & V_94 -> V_122 , V_206 , sizeof( * V_206 ) ) ;
F_71 ( & V_94 -> V_124 , V_209 , sizeof( * V_209 ) ) ;
V_96 -> V_120 = F_66 ;
V_96 -> V_121 = & V_116 ;
V_96 -> V_81 = & V_94 -> V_122 ;
V_96 -> V_123 = & V_94 -> V_124 ;
V_119 = F_72 ( & V_3 -> V_52 -> V_55 , V_96 , NULL ,
V_129 ) ;
if ( V_119 )
return V_119 ;
F_73 ( & V_116 ) ;
if ( V_96 -> V_37 )
return V_96 -> V_37 ;
if ( F_116 ( V_3 -> V_26 ) == V_203 &&
! ( strstr ( V_209 -> V_207 . V_212 , V_204 ) ) )
snprintf ( F_120 ( V_3 -> V_26 ) ,
V_211 , L_15 ,
V_209 -> V_207 . V_212 , V_204 ,
F_121 ( & V_3 -> V_133 -> V_132 ) ,
F_122 () -> V_213 ) ;
else
F_123 ( F_120 ( V_3 -> V_26 ) ,
V_209 -> V_207 . V_212 , V_211 ) ;
return 0 ;
}
static void F_124 ( struct V_2 * V_3 ,
struct V_93 * V_94 )
{
F_70 ( V_116 ) ;
struct V_155 * V_156 = V_3 -> V_26 ;
struct V_95 * V_96 = & V_94 -> V_96 ;
struct V_214 * V_215 = & V_94 -> V_99 . V_216 . V_81 ;
struct V_106 * V_217 = & V_94 -> V_99 . V_216 . V_101 ;
int V_119 , V_218 ;
F_68 ( & V_215 -> V_102 , V_219 ,
V_211 ) ;
F_93 ( V_215 -> V_216 . V_220 . V_105 , F_94 ( V_156 ) ) ;
V_218 = F_123 ( V_215 -> V_216 . V_221 , F_120 ( V_156 ) ,
V_211 ) ;
V_215 -> V_216 . V_222 = V_218 ;
F_71 ( & V_94 -> V_122 , V_215 , sizeof( * V_215 ) ) ;
F_71 ( & V_94 -> V_124 , V_217 , sizeof( * V_217 ) ) ;
V_96 -> V_120 = F_66 ;
V_96 -> V_121 = & V_116 ;
V_96 -> V_81 = & V_94 -> V_122 ;
V_96 -> V_123 = & V_94 -> V_124 ;
V_119 = F_72 ( & V_3 -> V_52 -> V_55 , V_96 , NULL ,
V_129 ) ;
if ( ! V_119 )
F_73 ( & V_116 ) ;
}
void F_125 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = F_13 ( V_17 , struct V_2 ,
V_223 ) ;
int V_119 ;
struct V_93 * V_94 ;
if ( F_116 ( V_3 -> V_26 ) != V_202 &&
F_116 ( V_3 -> V_26 ) != V_203 )
return;
V_94 = F_90 ( V_154 , V_166 ) ;
if ( ! V_94 )
return;
V_119 = F_28 ( & V_3 -> V_52 -> V_55 ) ;
if ( V_119 )
goto V_224;
V_119 = F_119 ( V_3 , V_94 ) ;
if ( V_119 || F_116 ( V_3 -> V_26 ) != V_203 )
goto V_225;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
F_124 ( V_3 , V_94 ) ;
V_225:
F_40 ( & V_3 -> V_52 -> V_55 ) ;
V_224:
F_88 ( V_154 , V_94 ) ;
}
static void F_126 ( void * V_28 )
{
struct V_226 * V_227 = V_28 ;
struct V_95 * V_228 = V_227 -> V_229 ;
struct V_230 * V_231 = V_227 -> V_232 ;
V_231 -> V_233 = V_227 -> V_234 . V_235 ;
V_231 -> V_236 . V_237 . V_37 = V_238 ;
V_231 -> V_239 = V_228 -> V_37 ? - V_44 : 0 ;
F_127 ( V_227 , V_231 -> V_239 , V_231 -> V_233 ) ;
}
static struct V_33 * F_128 ( struct V_226 * V_227 )
{
T_1 V_240 ;
T_4 V_241 ;
struct V_2 * V_3 ;
struct V_242 * V_243 = V_227 -> V_244 ;
struct V_245 * V_246 = F_129 ( V_227 ) ;
struct V_155 * V_156 ;
V_240 = V_243 -> V_247 . V_248 . V_240 ;
V_241 = ( V_240 & 0xff000000 ) >> 24 ;
V_156 = V_246 ? F_130 ( V_246 ) : F_131 ( V_227 ) ;
V_3 = (struct V_2 * ) V_156 -> V_249 [ 0 ] ;
switch ( V_241 ) {
case V_250 :
return & V_3 -> V_52 -> V_56 ;
case V_251 :
return & V_3 -> V_52 -> V_53 ;
case V_252 :
return & V_3 -> V_52 -> V_54 ;
break;
case V_112 :
return & V_3 -> V_52 -> V_55 ;
break;
default:
return NULL ;
}
}
static void F_132 ( void * V_28 )
{
struct V_226 * V_227 = V_28 ;
struct V_33 * V_34 ;
V_34 = F_128 ( V_227 ) ;
F_40 ( V_34 ) ;
F_126 ( V_28 ) ;
}
static int F_133 ( struct V_226 * V_227 ,
struct V_2 * V_3 )
{
struct V_95 * V_253 = V_227 -> V_229 ;
struct V_245 * V_246 = F_129 ( V_227 ) ;
struct V_242 * V_243 = V_227 -> V_244 ;
struct V_63 * V_64 ;
T_1 V_49 ;
if ( V_246 ) {
V_64 = F_134 ( V_3 , V_246 -> V_254 ) ;
if ( ! V_64 )
return - V_255 ;
V_49 = V_64 -> V_49 ;
F_80 ( & V_64 -> V_132 ) ;
} else
V_49 = F_54 ( V_243 -> V_247 . V_256 . V_257 ) ;
V_253 -> V_120 = F_126 ;
return F_95 ( V_3 , V_49 , V_253 , V_227 -> V_81 -> V_258 / V_48 ) ;
}
static int F_135 ( struct V_226 * V_227 ,
struct V_2 * V_3 )
{
int V_119 ;
struct V_95 * V_259 = V_227 -> V_229 ;
struct V_33 * V_34 ;
V_34 = F_128 ( V_227 ) ;
if ( ! V_34 )
return - V_255 ;
V_119 = F_28 ( V_34 ) ;
if ( V_119 )
return V_119 ;
V_259 -> V_120 = F_132 ;
V_119 = F_72 ( V_34 , V_259 , NULL , V_227 -> V_81 -> V_258 / V_48 ) ;
if ( V_119 )
F_40 ( V_34 ) ;
return V_119 ;
}
int F_136 ( struct V_226 * V_227 )
{
struct V_155 * V_156 ;
struct V_2 * V_3 ;
struct V_95 * V_96 = V_227 -> V_229 ;
struct V_242 * V_243 = V_227 -> V_244 ;
struct V_245 * V_246 = F_129 ( V_227 ) ;
V_156 = V_246 ? F_130 ( V_246 ) : F_131 ( V_227 ) ;
V_3 = (struct V_2 * ) V_156 -> V_249 [ 0 ] ;
if ( ! ( F_37 ( & V_3 -> V_37 ) & V_152 ) )
return - V_255 ;
V_96 -> V_81 = V_227 -> V_260 . V_261 ;
V_96 -> V_123 = V_227 -> V_234 . V_261 ;
V_96 -> V_121 = V_227 ;
switch ( V_243 -> V_262 ) {
case V_263 :
case V_264 :
return F_133 ( V_227 , V_3 ) ;
case V_265 :
case V_266 :
return F_135 ( V_227 , V_3 ) ;
default:
return - V_255 ;
}
}
int F_137 ( struct V_226 * V_227 )
{
return - V_188 ;
}
int F_138 ( struct V_2 * V_3 )
{
struct V_51 * V_267 ;
V_267 = F_139 ( sizeof( struct V_51 ) , V_166 ) ;
if ( ! V_267 )
return - V_130 ;
V_3 -> V_52 = V_267 ;
F_43 ( & V_267 -> V_53 , V_268 , V_3 ) ;
F_43 ( & V_267 -> V_54 , V_269 , V_3 ) ;
F_43 ( & V_267 -> V_55 , V_270 , V_3 ) ;
F_43 ( & V_267 -> V_56 , V_271 , V_3 ) ;
return 0 ;
}
void F_140 ( struct V_2 * V_3 )
{
F_21 ( V_3 -> V_52 ) ;
V_3 -> V_52 = NULL ;
}
