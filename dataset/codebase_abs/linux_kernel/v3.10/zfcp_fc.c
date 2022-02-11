void F_1 ( struct V_1 * V_2 )
{
if ( V_3 )
return;
F_2 ( V_2 -> V_4 , & V_2 -> V_5 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( ! V_3 )
return;
F_2 ( V_2 -> V_4 , & V_2 -> V_5 ) ;
}
void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = NULL , * V_10 = NULL ;
F_5 ( V_11 ) ;
struct V_12 * V_13 = F_6 ( V_7 ,
struct V_12 , V_7 ) ;
struct V_1 * V_2 = F_6 ( V_13 , struct V_1 ,
V_13 ) ;
F_7 ( & V_13 -> V_14 ) ;
F_8 ( & V_13 -> V_15 , & V_11 ) ;
F_9 ( & V_13 -> V_14 ) ;
F_10 (event, tmp, &tmp_lh, list) {
F_11 ( V_2 -> V_16 , F_12 () ,
V_9 -> V_17 , V_9 -> V_18 ) ;
F_13 ( & V_9 -> V_15 ) ;
F_14 ( V_9 ) ;
}
}
void F_15 ( struct V_1 * V_2 ,
enum V_19 V_20 , T_1 V_21 )
{
struct V_8 * V_9 ;
V_9 = F_16 ( sizeof( struct V_8 ) , V_22 ) ;
if ( ! V_9 )
return;
V_9 -> V_17 = V_20 ;
V_9 -> V_18 = V_21 ;
F_17 ( & V_2 -> V_13 . V_14 ) ;
F_18 ( & V_9 -> V_15 , & V_2 -> V_13 . V_15 ) ;
F_19 ( & V_2 -> V_13 . V_14 ) ;
F_2 ( V_2 -> V_4 , & V_2 -> V_13 . V_7 ) ;
}
static int F_20 ( struct V_23 * V_24 )
{
if ( F_21 ( & V_24 -> V_25 ) )
return - V_26 ;
if ( V_24 -> V_27 == V_28 ||
V_24 -> V_27 == V_29 ) {
V_24 -> V_27 = V_30 ;
if ( F_22 ( V_24 ) )
V_24 -> V_27 = V_28 ;
}
F_23 ( & V_24 -> V_25 ) ;
F_24 ( V_24 -> V_31 ,
V_24 -> V_27 == V_32 ||
V_24 -> V_27 == V_28 ) ;
if ( V_24 -> V_27 == V_32 ) {
F_25 ( & V_24 -> V_33 ) ;
return 0 ;
}
return - V_34 ;
}
static void F_26 ( struct V_6 * V_7 )
{
struct V_35 * V_36 = F_27 ( V_7 ) ;
struct V_23 * V_24 =
F_6 ( V_36 , struct V_23 , V_7 ) ;
F_28 ( & V_24 -> V_25 ) ;
if ( ( F_29 ( & V_24 -> V_33 ) != 0 ) ||
( V_24 -> V_27 != V_32 ) )
goto V_37;
V_24 -> V_27 = V_29 ;
if ( F_30 ( V_24 ) ) {
V_24 -> V_27 = V_28 ;
F_31 ( & V_24 -> V_31 ) ;
}
V_37:
F_23 ( & V_24 -> V_25 ) ;
}
static void F_32 ( struct V_23 * V_24 )
{
if ( F_33 ( & V_24 -> V_33 ) != 0 )
return;
F_34 ( & V_24 -> V_7 , V_38 / 100 ) ;
}
static void F_35 ( struct V_23 * V_24 , T_1 V_39 ,
struct V_1 * V_2 )
{
F_36 ( & V_24 -> V_31 ) ;
V_24 -> V_2 = V_2 ;
V_24 -> V_39 = V_39 ;
V_24 -> V_27 = V_28 ;
F_37 ( & V_24 -> V_33 , 0 ) ;
F_38 ( & V_24 -> V_25 ) ;
F_39 ( & V_24 -> V_7 , F_26 ) ;
}
static void F_40 ( struct V_23 * V_40 )
{
F_41 ( & V_40 -> V_7 ) ;
F_28 ( & V_40 -> V_25 ) ;
V_40 -> V_27 = V_28 ;
F_23 ( & V_40 -> V_25 ) ;
}
void F_42 ( struct V_41 * V_42 )
{
if ( ! V_42 )
return;
F_40 ( & V_42 -> V_43 ) ;
F_40 ( & V_42 -> V_44 ) ;
F_40 ( & V_42 -> V_45 ) ;
F_40 ( & V_42 -> V_46 ) ;
}
static void F_43 ( struct V_47 * V_48 , T_1 V_49 ,
struct V_50 * V_51 )
{
unsigned long V_52 ;
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_53 * V_54 ;
F_44 ( & V_2 -> V_55 , V_52 ) ;
F_45 (port, &adapter->port_list, list) {
if ( ( V_54 -> V_39 & V_49 ) == ( F_46 ( V_51 -> V_56 ) & V_49 ) )
F_47 ( V_54 ) ;
if ( ! V_54 -> V_39 )
F_48 ( V_54 ,
V_57 ,
L_1 ) ;
}
F_49 ( & V_2 -> V_55 , V_52 ) ;
}
static void F_50 ( struct V_47 * V_48 )
{
struct V_58 * V_59 = ( void * ) V_48 -> V_18 ;
struct V_60 * V_61 ;
struct V_50 * V_51 ;
T_2 V_62 ;
T_2 V_63 ;
unsigned int V_64 ;
V_61 = (struct V_60 * ) V_59 -> V_65 . V_18 ;
V_51 = (struct V_50 * ) V_61 ;
V_63 = V_61 -> V_66 / sizeof( struct V_50 ) ;
for ( V_62 = 1 ; V_62 < V_63 ; V_62 ++ ) {
V_51 ++ ;
V_64 = V_51 -> V_67 & V_68 ;
F_43 ( V_48 , V_69 [ V_64 ] ,
V_51 ) ;
F_15 ( V_48 -> V_2 , V_70 ,
* ( T_1 * ) V_51 ) ;
}
F_1 ( V_48 -> V_2 ) ;
}
static void F_51 ( struct V_47 * V_71 , T_3 V_72 )
{
unsigned long V_52 ;
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_53 * V_54 ;
F_44 ( & V_2 -> V_55 , V_52 ) ;
F_45 (port, &adapter->port_list, list)
if ( V_54 -> V_72 == V_72 ) {
F_52 ( V_54 , 0 , L_2 ) ;
break;
}
F_49 ( & V_2 -> V_55 , V_52 ) ;
}
static void F_53 ( struct V_47 * V_71 )
{
struct V_58 * V_59 ;
struct V_73 * V_74 ;
V_59 = (struct V_58 * ) V_71 -> V_18 ;
V_74 = (struct V_73 * ) V_59 -> V_65 . V_18 ;
F_51 ( V_71 , V_74 -> V_75 ) ;
}
static void F_54 ( struct V_47 * V_71 )
{
struct V_58 * V_59 =
(struct V_58 * ) V_71 -> V_18 ;
struct V_76 * V_77 =
(struct V_76 * ) V_59 -> V_65 . V_18 ;
F_51 ( V_71 , V_77 -> V_78 ) ;
}
void F_55 ( struct V_47 * V_48 )
{
struct V_58 * V_59 =
(struct V_58 * ) V_48 -> V_18 ;
unsigned int V_79 = V_59 -> V_65 . V_18 [ 0 ] ;
F_56 ( L_3 , V_48 ) ;
if ( V_79 == V_80 )
F_53 ( V_48 ) ;
else if ( V_79 == V_81 )
F_54 ( V_48 ) ;
else if ( V_79 == V_82 )
F_50 ( V_48 ) ;
}
static void F_57 ( struct V_83 * V_84 )
{
struct V_85 * V_86 = & V_84 -> V_86 ;
struct V_87 * V_88 = & V_84 -> V_89 . V_90 . V_91 ;
if ( V_86 -> V_27 )
return;
if ( V_88 -> V_92 . V_93 != V_94 )
return;
V_86 -> V_54 -> V_39 = F_46 ( V_88 -> V_90 . V_95 ) ;
}
static void F_58 ( void * V_18 )
{
F_59 ( V_18 ) ;
}
static void F_60 ( struct V_96 * V_92 , T_2 V_97 , T_2 V_98 )
{
V_92 -> V_99 = V_100 ;
V_92 -> V_101 = V_102 ;
V_92 -> V_103 = V_104 ;
V_92 -> V_93 = V_97 ;
V_92 -> V_105 = V_98 / 4 ;
}
static int F_61 ( struct V_53 * V_54 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
F_62 ( V_106 ) ;
struct V_107 * V_108 = & V_84 -> V_89 . V_90 . V_71 ;
struct V_87 * V_88 = & V_84 -> V_89 . V_90 . V_91 ;
int V_109 ;
V_84 -> V_86 . V_54 = V_54 ;
V_84 -> V_86 . V_110 = F_58 ;
V_84 -> V_86 . V_111 = & V_106 ;
V_84 -> V_86 . V_71 = & V_84 -> V_112 ;
V_84 -> V_86 . V_113 = & V_84 -> V_114 ;
F_63 ( & V_84 -> V_112 , V_108 , sizeof( * V_108 ) ) ;
F_63 ( & V_84 -> V_114 , V_88 , sizeof( * V_88 ) ) ;
F_60 ( & V_108 -> V_92 ,
V_115 , V_116 ) ;
V_108 -> V_90 . V_117 = V_54 -> V_72 ;
V_109 = F_64 ( & V_2 -> V_42 -> V_45 , & V_84 -> V_86 ,
V_2 -> V_118 . V_108 ,
V_119 ) ;
if ( ! V_109 ) {
F_65 ( & V_106 ) ;
F_57 ( V_84 ) ;
}
return V_109 ;
}
static int F_66 ( struct V_53 * V_54 )
{
int V_109 ;
struct V_83 * V_84 ;
struct V_1 * V_2 = V_54 -> V_2 ;
V_84 = F_67 ( V_2 -> V_118 . V_90 , V_22 ) ;
if ( ! V_84 )
return - V_120 ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_109 = F_20 ( & V_2 -> V_42 -> V_45 ) ;
if ( V_109 )
goto V_37;
V_109 = F_61 ( V_54 , V_84 ) ;
F_32 ( & V_2 -> V_42 -> V_45 ) ;
V_37:
F_68 ( V_84 , V_2 -> V_118 . V_90 ) ;
return V_109 ;
}
void F_69 ( struct V_6 * V_7 )
{
int V_109 ;
struct V_53 * V_54 = F_6 ( V_7 , struct V_53 ,
V_121 ) ;
V_109 = F_66 ( V_54 ) ;
if ( V_109 ) {
F_70 ( V_54 -> V_2 , 0 , L_4 ) ;
goto V_37;
}
if ( ! V_54 -> V_39 ) {
F_71 ( V_54 , V_57 ) ;
goto V_37;
}
F_48 ( V_54 , 0 , L_5 ) ;
V_37:
F_72 ( & V_54 -> V_122 ) ;
}
void F_73 ( struct V_53 * V_54 )
{
F_74 ( & V_54 -> V_122 ) ;
if ( ! F_2 ( V_54 -> V_2 -> V_4 , & V_54 -> V_121 ) )
F_72 ( & V_54 -> V_122 ) ;
}
void F_75 ( struct V_53 * V_54 , struct V_73 * V_74 )
{
if ( V_74 -> V_75 != V_54 -> V_72 ) {
V_54 -> V_39 = 0 ;
F_76 ( & V_54 -> V_2 -> V_123 -> V_122 ,
L_6
L_7 ,
( unsigned long long ) V_54 -> V_72 ,
( unsigned long long ) V_74 -> V_75 ) ;
return;
}
V_54 -> V_124 = V_74 -> V_125 ;
V_54 -> V_126 = V_74 -> V_127 . V_128 ;
if ( V_74 -> V_129 [ 0 ] . V_130 & V_131 )
V_54 -> V_132 |= V_133 ;
if ( V_74 -> V_129 [ 1 ] . V_130 & V_131 )
V_54 -> V_132 |= V_134 ;
if ( V_74 -> V_129 [ 2 ] . V_130 & V_131 )
V_54 -> V_132 |= V_135 ;
if ( V_74 -> V_129 [ 3 ] . V_130 & V_131 )
V_54 -> V_132 |= V_136 ;
}
static void F_77 ( void * V_18 )
{
struct V_83 * V_84 = V_18 ;
struct V_53 * V_54 = V_84 -> V_86 . V_54 ;
struct V_137 * V_138 = & V_84 -> V_89 . V_139 . V_91 ;
if ( V_84 -> V_86 . V_27 ) {
F_52 ( V_54 , V_57 ,
L_8 ) ;
goto V_37;
}
if ( ! V_54 -> V_124 )
V_54 -> V_124 = V_138 -> V_140 ;
if ( ( V_54 -> V_72 != V_138 -> V_141 ) ||
! ( F_29 ( & V_54 -> V_27 ) & V_142 ) ) {
F_48 ( V_54 , V_57 ,
L_9 ) ;
goto V_37;
}
F_78 ( V_54 ) ;
V_37:
F_79 ( V_143 , & V_54 -> V_27 ) ;
F_72 ( & V_54 -> V_122 ) ;
F_80 ( V_144 , V_84 ) ;
}
static int F_81 ( struct V_53 * V_54 )
{
struct V_83 * V_84 ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_145 * V_146 = V_2 -> V_16 ;
int V_109 ;
V_84 = F_82 ( V_144 , V_22 ) ;
if ( ! V_84 )
return - V_120 ;
V_84 -> V_86 . V_54 = V_54 ;
V_84 -> V_86 . V_71 = & V_84 -> V_112 ;
V_84 -> V_86 . V_113 = & V_84 -> V_114 ;
F_63 ( & V_84 -> V_112 , & V_84 -> V_89 . V_139 . V_71 ,
sizeof( struct V_137 ) ) ;
F_63 ( & V_84 -> V_114 , & V_84 -> V_89 . V_139 . V_91 ,
sizeof( struct V_137 ) ) ;
V_84 -> V_86 . V_110 = F_77 ;
V_84 -> V_86 . V_111 = V_84 ;
V_84 -> V_89 . V_139 . V_71 . V_141 = F_83 ( V_146 ) ;
V_84 -> V_89 . V_139 . V_71 . V_140 = F_84 ( V_146 ) ;
V_84 -> V_89 . V_139 . V_71 . V_147 = V_148 ;
F_85 ( V_84 -> V_89 . V_139 . V_71 . V_149 , F_86 ( V_146 ) ) ;
V_109 = F_87 ( V_2 , V_54 -> V_39 , & V_84 -> V_86 ,
V_119 ) ;
if ( V_109 )
F_80 ( V_144 , V_84 ) ;
return V_109 ;
}
void F_88 ( struct V_6 * V_7 )
{
struct V_53 * V_54 =
F_6 ( V_7 , struct V_53 , V_150 ) ;
int V_151 ;
F_74 ( & V_54 -> V_122 ) ;
V_54 -> V_152 = V_153 ;
F_89 ( & V_54 -> V_154 ) ;
if ( F_29 ( & V_54 -> V_27 ) & V_143 )
goto V_37;
F_90 ( V_143 , & V_54 -> V_27 ) ;
V_151 = F_81 ( V_54 ) ;
if ( V_151 == 0 )
return;
F_79 ( V_143 , & V_54 -> V_27 ) ;
F_52 ( V_54 , 0 , L_10 ) ;
V_37:
F_72 ( & V_54 -> V_122 ) ;
}
void F_47 ( struct V_53 * V_54 )
{
F_74 ( & V_54 -> V_122 ) ;
if ( ! F_2 ( V_54 -> V_2 -> V_4 , & V_54 -> V_150 ) )
F_72 ( & V_54 -> V_122 ) ;
}
static struct V_83 * F_91 ( int V_155 )
{
struct V_83 * V_84 ;
V_84 = F_82 ( V_144 , V_156 ) ;
if ( ! V_84 )
return NULL ;
if ( F_92 ( & V_84 -> V_114 , V_155 ) ) {
F_80 ( V_144 , V_84 ) ;
return NULL ;
}
F_63 ( & V_84 -> V_112 , & V_84 -> V_89 . V_157 . V_71 ,
sizeof( struct V_158 ) ) ;
return V_84 ;
}
static int F_93 ( struct V_83 * V_84 ,
struct V_1 * V_2 , int V_159 )
{
struct V_85 * V_86 = & V_84 -> V_86 ;
struct V_158 * V_71 = & V_84 -> V_89 . V_157 . V_71 ;
F_62 ( V_106 ) ;
int V_109 ;
F_60 ( & V_71 -> V_92 , V_160 , V_159 ) ;
V_71 -> V_157 . V_161 = V_162 ;
V_86 -> V_110 = F_58 ;
V_86 -> V_111 = & V_106 ;
V_86 -> V_71 = & V_84 -> V_112 ;
V_86 -> V_113 = & V_84 -> V_114 ;
V_109 = F_64 ( & V_2 -> V_42 -> V_45 , V_86 , NULL ,
V_119 ) ;
if ( ! V_109 )
F_65 ( & V_106 ) ;
return V_109 ;
}
static void F_94 ( struct V_53 * V_54 , struct V_163 * V_164 )
{
if ( ! ( F_29 ( & V_54 -> V_27 ) & V_165 ) )
return;
F_79 ( V_165 , & V_54 -> V_27 ) ;
if ( ( V_54 -> V_132 != 0 ) ||
! F_95 ( & V_54 -> V_166 ) )
return;
F_96 ( & V_54 -> V_15 , V_164 ) ;
}
static int F_97 ( struct V_83 * V_84 ,
struct V_1 * V_2 , int V_167 )
{
struct V_85 * V_86 = & V_84 -> V_86 ;
struct V_168 * V_169 = & V_84 -> V_114 ;
struct V_96 * V_170 = F_98 ( V_169 ) ;
struct V_171 * V_172 = F_98 ( V_169 ) ;
struct V_53 * V_54 , * V_10 ;
unsigned long V_52 ;
F_5 ( V_173 ) ;
T_1 V_39 ;
int V_109 = 0 , V_174 , V_175 = 0 ;
if ( V_86 -> V_27 )
return - V_34 ;
if ( V_170 -> V_93 != V_94 ) {
if ( V_170 -> V_176 == V_177 )
return - V_178 ;
return - V_34 ;
}
if ( V_170 -> V_105 ) {
F_76 ( & V_2 -> V_123 -> V_122 ,
L_11 ,
V_170 -> V_105 ) ;
return - V_179 ;
}
for ( V_174 = 1 ; V_174 < V_167 && ! V_175 ; V_174 ++ ) {
if ( V_174 % ( V_180 + 1 ) )
V_172 ++ ;
else
V_172 = F_98 ( ++ V_169 ) ;
V_175 = V_172 -> V_181 & V_182 ;
V_39 = F_46 ( V_172 -> V_95 ) ;
if ( V_39 >= V_183 )
continue;
if ( V_172 -> V_184 == F_83 ( V_2 -> V_16 ) )
continue;
V_54 = F_99 ( V_2 , V_172 -> V_184 ,
V_165 , V_39 ) ;
if ( ! F_100 ( V_54 ) )
F_48 ( V_54 , 0 , L_12 ) ;
else if ( F_101 ( V_54 ) != - V_185 )
V_109 = F_101 ( V_54 ) ;
}
F_102 ( V_2 ) ;
F_103 ( & V_2 -> V_55 , V_52 ) ;
F_10 (port, tmp, &adapter->port_list, list)
F_94 ( V_54 , & V_173 ) ;
F_104 ( & V_2 -> V_55 , V_52 ) ;
F_10 (port, tmp, &remove_lh, list) {
F_105 ( V_54 , 0 , L_13 ) ;
F_106 ( & V_54 -> V_122 , & V_186 ) ;
}
return V_109 ;
}
void F_107 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 , struct V_1 ,
V_5 ) ;
int V_109 , V_62 ;
struct V_83 * V_84 ;
int V_187 , V_167 , V_155 , V_159 ;
V_187 = V_2 -> V_188 & V_189 ;
V_155 = V_187 ? V_190 : 1 ;
V_167 = V_187 ? V_191 : V_180 ;
V_159 = V_187 ? V_192 : V_116 ;
if ( F_108 ( V_2 -> V_16 ) != V_193 &&
F_108 ( V_2 -> V_16 ) != V_194 )
return;
if ( F_20 ( & V_2 -> V_42 -> V_45 ) )
return;
V_84 = F_91 ( V_155 ) ;
if ( ! V_84 )
goto V_37;
for ( V_62 = 0 ; V_62 < 3 ; V_62 ++ ) {
V_109 = F_93 ( V_84 , V_2 , V_159 ) ;
if ( ! V_109 ) {
V_109 = F_97 ( V_84 , V_2 , V_167 ) ;
if ( V_109 == - V_178 )
F_109 ( 1 ) ;
else
break;
}
}
F_110 ( & V_84 -> V_114 , V_155 ) ;
F_80 ( V_144 , V_84 ) ;
V_37:
F_32 ( & V_2 -> V_42 -> V_45 ) ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
F_62 ( V_106 ) ;
char V_195 [] = L_14 ;
struct V_85 * V_86 = & V_84 -> V_86 ;
struct V_196 * V_197 = & V_84 -> V_89 . V_198 . V_71 ;
struct V_199 * V_200 = & V_84 -> V_89 . V_198 . V_91 ;
int V_109 ;
F_60 ( & V_197 -> V_92 , V_201 ,
V_202 ) ;
F_85 ( V_197 -> V_198 . V_95 , F_86 ( V_2 -> V_16 ) ) ;
F_63 ( & V_84 -> V_112 , V_197 , sizeof( * V_197 ) ) ;
F_63 ( & V_84 -> V_114 , V_200 , sizeof( * V_200 ) ) ;
V_86 -> V_110 = F_58 ;
V_86 -> V_111 = & V_106 ;
V_86 -> V_71 = & V_84 -> V_112 ;
V_86 -> V_113 = & V_84 -> V_114 ;
V_109 = F_64 ( & V_2 -> V_42 -> V_45 , V_86 , NULL ,
V_119 ) ;
if ( V_109 )
return V_109 ;
F_65 ( & V_106 ) ;
if ( V_86 -> V_27 )
return V_86 -> V_27 ;
if ( F_108 ( V_2 -> V_16 ) == V_194 &&
! ( strstr ( V_200 -> V_198 . V_203 , V_195 ) ) )
snprintf ( F_112 ( V_2 -> V_16 ) ,
V_202 , L_15 ,
V_200 -> V_198 . V_203 , V_195 ,
F_113 ( & V_2 -> V_123 -> V_122 ) ,
F_114 () -> V_204 ) ;
else
F_115 ( F_112 ( V_2 -> V_16 ) ,
V_200 -> V_198 . V_203 , V_202 ) ;
return 0 ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
F_62 ( V_106 ) ;
struct V_145 * V_146 = V_2 -> V_16 ;
struct V_85 * V_86 = & V_84 -> V_86 ;
struct V_205 * V_206 = & V_84 -> V_89 . V_207 . V_71 ;
struct V_96 * V_208 = & V_84 -> V_89 . V_207 . V_91 ;
int V_109 , V_209 ;
F_60 ( & V_206 -> V_92 , V_210 ,
V_202 ) ;
F_85 ( V_206 -> V_207 . V_211 . V_95 , F_86 ( V_146 ) ) ;
V_209 = F_115 ( V_206 -> V_207 . V_212 , F_112 ( V_146 ) ,
V_202 ) ;
V_206 -> V_207 . V_213 = V_209 ;
F_63 ( & V_84 -> V_112 , V_206 , sizeof( * V_206 ) ) ;
F_63 ( & V_84 -> V_114 , V_208 , sizeof( * V_208 ) ) ;
V_86 -> V_110 = F_58 ;
V_86 -> V_111 = & V_106 ;
V_86 -> V_71 = & V_84 -> V_112 ;
V_86 -> V_113 = & V_84 -> V_114 ;
V_109 = F_64 ( & V_2 -> V_42 -> V_45 , V_86 , NULL ,
V_119 ) ;
if ( ! V_109 )
F_65 ( & V_106 ) ;
}
void F_117 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 , struct V_1 ,
V_214 ) ;
int V_109 ;
struct V_83 * V_84 ;
if ( F_108 ( V_2 -> V_16 ) != V_193 &&
F_108 ( V_2 -> V_16 ) != V_194 )
return;
V_84 = F_82 ( V_144 , V_156 ) ;
if ( ! V_84 )
return;
V_109 = F_20 ( & V_2 -> V_42 -> V_45 ) ;
if ( V_109 )
goto V_215;
V_109 = F_111 ( V_2 , V_84 ) ;
if ( V_109 || F_108 ( V_2 -> V_16 ) != V_194 )
goto V_216;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
F_116 ( V_2 , V_84 ) ;
V_216:
F_32 ( & V_2 -> V_42 -> V_45 ) ;
V_215:
F_80 ( V_144 , V_84 ) ;
}
static void F_118 ( void * V_18 )
{
struct V_217 * V_218 = V_18 ;
struct V_85 * V_219 = V_218 -> V_220 ;
struct V_221 * V_222 = V_218 -> V_223 ;
V_222 -> V_224 = V_218 -> V_225 . V_226 ;
V_222 -> V_227 . V_228 . V_27 = V_229 ;
V_222 -> V_230 = V_219 -> V_27 ? - V_34 : 0 ;
V_218 -> V_231 ( V_218 ) ;
}
static struct V_23 * F_119 ( struct V_217 * V_218 )
{
T_1 V_232 ;
T_4 V_233 ;
struct V_1 * V_2 ;
V_232 = V_218 -> V_234 -> V_235 . V_236 . V_232 ;
V_233 = ( V_232 & 0xff000000 ) >> 24 ;
V_2 = (struct V_1 * ) V_218 -> V_146 -> V_237 [ 0 ] ;
switch ( V_233 ) {
case V_238 :
return & V_2 -> V_42 -> V_46 ;
case V_239 :
return & V_2 -> V_42 -> V_43 ;
case V_240 :
return & V_2 -> V_42 -> V_44 ;
break;
case V_102 :
return & V_2 -> V_42 -> V_45 ;
break;
default:
return NULL ;
}
}
static void F_120 ( void * V_18 )
{
struct V_217 * V_218 = V_18 ;
struct V_23 * V_24 ;
V_24 = F_119 ( V_218 ) ;
F_32 ( V_24 ) ;
F_118 ( V_18 ) ;
}
static int F_121 ( struct V_217 * V_218 ,
struct V_1 * V_2 )
{
struct V_85 * V_241 = V_218 -> V_220 ;
struct V_242 * V_243 = V_218 -> V_243 ;
struct V_53 * V_54 ;
T_1 V_39 ;
if ( V_243 ) {
V_54 = F_122 ( V_2 , V_243 -> V_244 ) ;
if ( ! V_54 )
return - V_245 ;
V_39 = V_54 -> V_39 ;
F_72 ( & V_54 -> V_122 ) ;
} else
V_39 = F_46 ( V_218 -> V_234 -> V_235 . V_246 . V_247 ) ;
V_241 -> V_110 = F_118 ;
return F_87 ( V_2 , V_39 , V_241 , V_218 -> V_71 -> V_248 / V_38 ) ;
}
static int F_123 ( struct V_217 * V_218 ,
struct V_1 * V_2 )
{
int V_109 ;
struct V_85 * V_249 = V_218 -> V_220 ;
struct V_23 * V_24 ;
V_24 = F_119 ( V_218 ) ;
if ( ! V_24 )
return - V_245 ;
V_109 = F_20 ( V_24 ) ;
if ( V_109 )
return V_109 ;
V_249 -> V_110 = F_120 ;
V_109 = F_64 ( V_24 , V_249 , NULL , V_218 -> V_71 -> V_248 / V_38 ) ;
if ( V_109 )
F_32 ( V_24 ) ;
return V_109 ;
}
int F_124 ( struct V_217 * V_218 )
{
struct V_145 * V_146 ;
struct V_1 * V_2 ;
struct V_85 * V_86 = V_218 -> V_220 ;
V_146 = V_218 -> V_243 ? F_125 ( V_218 -> V_243 ) : V_218 -> V_146 ;
V_2 = (struct V_1 * ) V_146 -> V_237 [ 0 ] ;
if ( ! ( F_29 ( & V_2 -> V_27 ) & V_142 ) )
return - V_245 ;
V_86 -> V_71 = V_218 -> V_250 . V_251 ;
V_86 -> V_113 = V_218 -> V_225 . V_251 ;
V_86 -> V_111 = V_218 ;
switch ( V_218 -> V_234 -> V_252 ) {
case V_253 :
case V_254 :
return F_121 ( V_218 , V_2 ) ;
case V_255 :
case V_256 :
return F_123 ( V_218 , V_2 ) ;
default:
return - V_245 ;
}
}
int F_126 ( struct V_217 * V_218 )
{
return - V_178 ;
}
int F_127 ( struct V_1 * V_2 )
{
struct V_41 * V_257 ;
V_257 = F_128 ( sizeof( struct V_41 ) , V_156 ) ;
if ( ! V_257 )
return - V_120 ;
V_2 -> V_42 = V_257 ;
F_35 ( & V_257 -> V_43 , V_258 , V_2 ) ;
F_35 ( & V_257 -> V_44 , V_259 , V_2 ) ;
F_35 ( & V_257 -> V_45 , V_260 , V_2 ) ;
F_35 ( & V_257 -> V_46 , V_261 , V_2 ) ;
return 0 ;
}
void F_129 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
}
