void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL , * V_5 = NULL ;
F_2 ( V_6 ) ;
struct V_7 * V_8 = F_3 ( V_2 ,
struct V_7 , V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 , struct V_9 ,
V_8 ) ;
F_4 ( & V_8 -> V_11 ) ;
F_5 ( & V_8 -> V_12 , & V_6 ) ;
F_6 ( & V_8 -> V_11 ) ;
F_7 (event, tmp, &tmp_lh, list) {
F_8 ( V_10 -> V_13 , F_9 () ,
V_4 -> V_14 , V_4 -> V_15 ) ;
F_10 ( & V_4 -> V_12 ) ;
F_11 ( V_4 ) ;
}
}
void F_12 ( struct V_9 * V_10 ,
enum V_16 V_17 , T_1 V_18 )
{
struct V_3 * V_4 ;
V_4 = F_13 ( sizeof( struct V_3 ) , V_19 ) ;
if ( ! V_4 )
return;
V_4 -> V_14 = V_17 ;
V_4 -> V_15 = V_18 ;
F_14 ( & V_10 -> V_8 . V_11 ) ;
F_15 ( & V_4 -> V_12 , & V_10 -> V_8 . V_12 ) ;
F_16 ( & V_10 -> V_8 . V_11 ) ;
F_17 ( V_10 -> V_20 , & V_10 -> V_8 . V_2 ) ;
}
static int F_18 ( struct V_21 * V_22 )
{
if ( F_19 ( & V_22 -> V_23 ) )
return - V_24 ;
if ( V_22 -> V_25 == V_26 ||
V_22 -> V_25 == V_27 ) {
V_22 -> V_25 = V_28 ;
if ( F_20 ( V_22 ) )
V_22 -> V_25 = V_26 ;
}
F_21 ( & V_22 -> V_23 ) ;
F_22 ( V_22 -> V_29 ,
V_22 -> V_25 == V_30 ||
V_22 -> V_25 == V_26 ) ;
if ( V_22 -> V_25 == V_30 ) {
F_23 ( & V_22 -> V_31 ) ;
return 0 ;
}
return - V_32 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_25 ( V_2 ) ;
struct V_21 * V_22 =
F_3 ( V_34 , struct V_21 , V_2 ) ;
F_26 ( & V_22 -> V_23 ) ;
if ( ( F_27 ( & V_22 -> V_31 ) != 0 ) ||
( V_22 -> V_25 != V_30 ) )
goto V_35;
V_22 -> V_25 = V_27 ;
if ( F_28 ( V_22 ) ) {
V_22 -> V_25 = V_26 ;
F_29 ( & V_22 -> V_29 ) ;
}
V_35:
F_21 ( & V_22 -> V_23 ) ;
}
static void F_30 ( struct V_21 * V_22 )
{
if ( F_31 ( & V_22 -> V_31 ) != 0 )
return;
F_32 ( & V_22 -> V_2 , V_36 / 100 ) ;
}
static void F_33 ( struct V_21 * V_22 , T_1 V_37 ,
struct V_9 * V_10 )
{
F_34 ( & V_22 -> V_29 ) ;
V_22 -> V_10 = V_10 ;
V_22 -> V_37 = V_37 ;
V_22 -> V_25 = V_26 ;
F_35 ( & V_22 -> V_31 , 0 ) ;
F_36 ( & V_22 -> V_23 ) ;
F_37 ( & V_22 -> V_2 , F_24 ) ;
}
static void F_38 ( struct V_21 * V_38 )
{
F_39 ( & V_38 -> V_2 ) ;
F_26 ( & V_38 -> V_23 ) ;
V_38 -> V_25 = V_26 ;
F_21 ( & V_38 -> V_23 ) ;
}
void F_40 ( struct V_39 * V_40 )
{
if ( ! V_40 )
return;
F_38 ( & V_40 -> V_41 ) ;
F_38 ( & V_40 -> V_42 ) ;
F_38 ( & V_40 -> V_43 ) ;
F_38 ( & V_40 -> V_44 ) ;
}
static void F_41 ( struct V_45 * V_46 , T_1 V_47 ,
struct V_48 * V_49 )
{
unsigned long V_50 ;
struct V_9 * V_10 = V_46 -> V_10 ;
struct V_51 * V_52 ;
F_42 ( & V_10 -> V_53 , V_50 ) ;
F_43 (port, &adapter->port_list, list) {
if ( ( V_52 -> V_37 & V_47 ) == ( F_44 ( V_49 -> V_54 ) & V_47 ) )
F_45 ( V_52 ) ;
if ( ! V_52 -> V_37 )
F_46 ( V_52 ,
V_55 ,
L_1 ) ;
}
F_47 ( & V_10 -> V_53 , V_50 ) ;
}
static void F_48 ( struct V_45 * V_46 )
{
struct V_56 * V_57 = ( void * ) V_46 -> V_15 ;
struct V_58 * V_59 ;
struct V_48 * V_49 ;
T_2 V_60 ;
T_2 V_61 ;
unsigned int V_62 ;
V_59 = (struct V_58 * ) V_57 -> V_63 . V_15 ;
V_49 = (struct V_48 * ) V_59 ;
V_61 = V_59 -> V_64 / sizeof( struct V_48 ) ;
for ( V_60 = 1 ; V_60 < V_61 ; V_60 ++ ) {
V_49 ++ ;
V_62 = V_49 -> V_65 & V_66 ;
F_41 ( V_46 , V_67 [ V_62 ] ,
V_49 ) ;
F_12 ( V_46 -> V_10 , V_68 ,
* ( T_1 * ) V_49 ) ;
}
F_17 ( V_46 -> V_10 -> V_20 , & V_46 -> V_10 -> V_69 ) ;
}
static void F_49 ( struct V_45 * V_70 , T_3 V_71 )
{
unsigned long V_50 ;
struct V_9 * V_10 = V_70 -> V_10 ;
struct V_51 * V_52 ;
F_42 ( & V_10 -> V_53 , V_50 ) ;
F_43 (port, &adapter->port_list, list)
if ( V_52 -> V_71 == V_71 ) {
F_50 ( V_52 , 0 , L_2 ) ;
break;
}
F_47 ( & V_10 -> V_53 , V_50 ) ;
}
static void F_51 ( struct V_45 * V_70 )
{
struct V_56 * V_57 ;
struct V_72 * V_73 ;
V_57 = (struct V_56 * ) V_70 -> V_15 ;
V_73 = (struct V_72 * ) V_57 -> V_63 . V_15 ;
F_49 ( V_70 , V_73 -> V_74 ) ;
}
static void F_52 ( struct V_45 * V_70 )
{
struct V_56 * V_57 =
(struct V_56 * ) V_70 -> V_15 ;
struct V_75 * V_76 =
(struct V_75 * ) V_57 -> V_63 . V_15 ;
F_49 ( V_70 , V_76 -> V_77 ) ;
}
void F_53 ( struct V_45 * V_46 )
{
struct V_56 * V_57 =
(struct V_56 * ) V_46 -> V_15 ;
unsigned int V_78 = V_57 -> V_63 . V_15 [ 0 ] ;
F_54 ( L_3 , V_46 ) ;
if ( V_78 == V_79 )
F_51 ( V_46 ) ;
else if ( V_78 == V_80 )
F_52 ( V_46 ) ;
else if ( V_78 == V_81 )
F_48 ( V_46 ) ;
}
static void F_55 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = & V_83 -> V_85 ;
struct V_86 * V_87 = & V_83 -> V_88 . V_89 . V_90 ;
if ( V_85 -> V_25 )
return;
if ( V_87 -> V_91 . V_92 != V_93 )
return;
V_85 -> V_52 -> V_37 = F_44 ( V_87 -> V_89 . V_94 ) ;
}
static void F_56 ( void * V_15 )
{
F_57 ( V_15 ) ;
}
static void F_58 ( struct V_95 * V_91 , T_2 V_96 , T_2 V_97 )
{
V_91 -> V_98 = V_99 ;
V_91 -> V_100 = V_101 ;
V_91 -> V_102 = V_103 ;
V_91 -> V_92 = V_96 ;
V_91 -> V_104 = V_97 / 4 ;
}
static int F_59 ( struct V_51 * V_52 ,
struct V_82 * V_83 )
{
struct V_9 * V_10 = V_52 -> V_10 ;
F_60 ( V_105 ) ;
struct V_106 * V_107 = & V_83 -> V_88 . V_89 . V_70 ;
struct V_86 * V_87 = & V_83 -> V_88 . V_89 . V_90 ;
int V_108 ;
V_83 -> V_85 . V_52 = V_52 ;
V_83 -> V_85 . V_109 = F_56 ;
V_83 -> V_85 . V_110 = & V_105 ;
V_83 -> V_85 . V_70 = & V_83 -> V_111 ;
V_83 -> V_85 . V_112 = & V_83 -> V_113 ;
F_61 ( & V_83 -> V_111 , V_107 , sizeof( * V_107 ) ) ;
F_61 ( & V_83 -> V_113 , V_87 , sizeof( * V_87 ) ) ;
F_58 ( & V_107 -> V_91 ,
V_114 , V_115 ) ;
V_107 -> V_89 . V_116 = V_52 -> V_71 ;
V_108 = F_62 ( & V_10 -> V_40 -> V_43 , & V_83 -> V_85 ,
V_10 -> V_117 . V_107 ,
V_118 ) ;
if ( ! V_108 ) {
F_63 ( & V_105 ) ;
F_55 ( V_83 ) ;
}
return V_108 ;
}
static int F_64 ( struct V_51 * V_52 )
{
int V_108 ;
struct V_82 * V_83 ;
struct V_9 * V_10 = V_52 -> V_10 ;
V_83 = F_65 ( V_10 -> V_117 . V_89 , V_19 ) ;
if ( ! V_83 )
return - V_119 ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_108 = F_18 ( & V_10 -> V_40 -> V_43 ) ;
if ( V_108 )
goto V_35;
V_108 = F_59 ( V_52 , V_83 ) ;
F_30 ( & V_10 -> V_40 -> V_43 ) ;
V_35:
F_66 ( V_83 , V_10 -> V_117 . V_89 ) ;
return V_108 ;
}
void F_67 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_51 * V_52 = F_3 ( V_2 , struct V_51 ,
V_120 ) ;
V_108 = F_64 ( V_52 ) ;
if ( V_108 ) {
F_68 ( V_52 -> V_10 , 0 , L_4 ) ;
goto V_35;
}
if ( ! V_52 -> V_37 ) {
F_69 ( V_52 , V_55 ) ;
goto V_35;
}
F_46 ( V_52 , 0 , L_5 ) ;
V_35:
F_70 ( & V_52 -> V_121 ) ;
}
void F_71 ( struct V_51 * V_52 )
{
F_72 ( & V_52 -> V_121 ) ;
if ( ! F_17 ( V_52 -> V_10 -> V_20 , & V_52 -> V_120 ) )
F_70 ( & V_52 -> V_121 ) ;
}
void F_73 ( struct V_51 * V_52 , struct V_72 * V_73 )
{
if ( V_73 -> V_74 != V_52 -> V_71 ) {
V_52 -> V_37 = 0 ;
F_74 ( & V_52 -> V_10 -> V_122 -> V_121 ,
L_6
L_7 ,
( unsigned long long ) V_52 -> V_71 ,
( unsigned long long ) V_73 -> V_74 ) ;
return;
}
V_52 -> V_123 = V_73 -> V_124 ;
V_52 -> V_125 = V_73 -> V_126 . V_127 ;
if ( V_73 -> V_128 [ 0 ] . V_129 & V_130 )
V_52 -> V_131 |= V_132 ;
if ( V_73 -> V_128 [ 1 ] . V_129 & V_130 )
V_52 -> V_131 |= V_133 ;
if ( V_73 -> V_128 [ 2 ] . V_129 & V_130 )
V_52 -> V_131 |= V_134 ;
if ( V_73 -> V_128 [ 3 ] . V_129 & V_130 )
V_52 -> V_131 |= V_135 ;
}
static void F_75 ( void * V_15 )
{
struct V_82 * V_83 = V_15 ;
struct V_51 * V_52 = V_83 -> V_85 . V_52 ;
struct V_136 * V_137 = & V_83 -> V_88 . V_138 . V_90 ;
if ( V_83 -> V_85 . V_25 ) {
F_50 ( V_52 , V_55 ,
L_8 ) ;
goto V_35;
}
if ( ! V_52 -> V_123 )
V_52 -> V_123 = V_137 -> V_139 ;
if ( ( V_52 -> V_71 != V_137 -> V_140 ) ||
! ( F_27 ( & V_52 -> V_25 ) & V_141 ) ) {
F_46 ( V_52 , V_55 ,
L_9 ) ;
goto V_35;
}
F_76 ( V_52 ) ;
V_35:
F_77 ( V_142 , & V_52 -> V_25 ) ;
F_70 ( & V_52 -> V_121 ) ;
F_78 ( V_143 , V_83 ) ;
}
static int F_79 ( struct V_51 * V_52 )
{
struct V_82 * V_83 ;
struct V_9 * V_10 = V_52 -> V_10 ;
struct V_144 * V_145 = V_10 -> V_13 ;
int V_108 ;
V_83 = F_80 ( V_143 , V_19 ) ;
if ( ! V_83 )
return - V_119 ;
V_83 -> V_85 . V_52 = V_52 ;
V_83 -> V_85 . V_70 = & V_83 -> V_111 ;
V_83 -> V_85 . V_112 = & V_83 -> V_113 ;
F_61 ( & V_83 -> V_111 , & V_83 -> V_88 . V_138 . V_70 ,
sizeof( struct V_136 ) ) ;
F_61 ( & V_83 -> V_113 , & V_83 -> V_88 . V_138 . V_90 ,
sizeof( struct V_136 ) ) ;
V_83 -> V_85 . V_109 = F_75 ;
V_83 -> V_85 . V_110 = V_83 ;
V_83 -> V_88 . V_138 . V_70 . V_140 = F_81 ( V_145 ) ;
V_83 -> V_88 . V_138 . V_70 . V_139 = F_82 ( V_145 ) ;
V_83 -> V_88 . V_138 . V_70 . V_146 = V_147 ;
F_83 ( V_83 -> V_88 . V_138 . V_70 . V_148 , F_84 ( V_145 ) ) ;
V_108 = F_85 ( V_10 , V_52 -> V_37 , & V_83 -> V_85 ,
V_118 ) ;
if ( V_108 )
F_78 ( V_143 , V_83 ) ;
return V_108 ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_51 * V_52 =
F_3 ( V_2 , struct V_51 , V_149 ) ;
int V_150 ;
F_72 ( & V_52 -> V_121 ) ;
V_52 -> V_151 = V_152 ;
F_87 ( & V_52 -> V_153 ) ;
if ( F_27 ( & V_52 -> V_25 ) & V_142 )
goto V_35;
F_88 ( V_142 , & V_52 -> V_25 ) ;
V_150 = F_79 ( V_52 ) ;
if ( V_150 == 0 )
return;
F_77 ( V_142 , & V_52 -> V_25 ) ;
F_50 ( V_52 , 0 , L_10 ) ;
V_35:
F_70 ( & V_52 -> V_121 ) ;
}
void F_45 ( struct V_51 * V_52 )
{
F_72 ( & V_52 -> V_121 ) ;
if ( ! F_17 ( V_52 -> V_10 -> V_20 , & V_52 -> V_149 ) )
F_70 ( & V_52 -> V_121 ) ;
}
static struct V_82 * F_89 ( int V_154 )
{
struct V_82 * V_83 ;
V_83 = F_80 ( V_143 , V_155 ) ;
if ( ! V_83 )
return NULL ;
if ( F_90 ( & V_83 -> V_113 , V_154 ) ) {
F_78 ( V_143 , V_83 ) ;
return NULL ;
}
F_61 ( & V_83 -> V_111 , & V_83 -> V_88 . V_156 . V_70 ,
sizeof( struct V_157 ) ) ;
return V_83 ;
}
static int F_91 ( struct V_82 * V_83 ,
struct V_9 * V_10 , int V_158 )
{
struct V_84 * V_85 = & V_83 -> V_85 ;
struct V_157 * V_70 = & V_83 -> V_88 . V_156 . V_70 ;
F_60 ( V_105 ) ;
int V_108 ;
F_58 ( & V_70 -> V_91 , V_159 , V_158 ) ;
V_70 -> V_156 . V_160 = V_161 ;
V_85 -> V_109 = F_56 ;
V_85 -> V_110 = & V_105 ;
V_85 -> V_70 = & V_83 -> V_111 ;
V_85 -> V_112 = & V_83 -> V_113 ;
V_108 = F_62 ( & V_10 -> V_40 -> V_43 , V_85 , NULL ,
V_118 ) ;
if ( ! V_108 )
F_63 ( & V_105 ) ;
return V_108 ;
}
static void F_92 ( struct V_51 * V_52 , struct V_162 * V_163 )
{
if ( ! ( F_27 ( & V_52 -> V_25 ) & V_164 ) )
return;
F_77 ( V_164 , & V_52 -> V_25 ) ;
if ( ( V_52 -> V_131 != 0 ) ||
! F_93 ( & V_52 -> V_165 ) )
return;
F_94 ( & V_52 -> V_12 , V_163 ) ;
}
static int F_95 ( struct V_82 * V_83 ,
struct V_9 * V_10 , int V_166 )
{
struct V_84 * V_85 = & V_83 -> V_85 ;
struct V_167 * V_168 = & V_83 -> V_113 ;
struct V_95 * V_169 = F_96 ( V_168 ) ;
struct V_170 * V_171 = F_96 ( V_168 ) ;
struct V_51 * V_52 , * V_5 ;
unsigned long V_50 ;
F_2 ( V_172 ) ;
T_1 V_37 ;
int V_108 = 0 , V_173 , V_174 = 0 ;
if ( V_85 -> V_25 )
return - V_32 ;
if ( V_169 -> V_92 != V_93 ) {
if ( V_169 -> V_175 == V_176 )
return - V_177 ;
return - V_32 ;
}
if ( V_169 -> V_104 ) {
F_74 ( & V_10 -> V_122 -> V_121 ,
L_11 ,
V_169 -> V_104 ) ;
return - V_178 ;
}
for ( V_173 = 1 ; V_173 < V_166 && ! V_174 ; V_173 ++ ) {
if ( V_173 % ( V_179 + 1 ) )
V_171 ++ ;
else
V_171 = F_96 ( ++ V_168 ) ;
V_174 = V_171 -> V_180 & V_181 ;
V_37 = F_44 ( V_171 -> V_94 ) ;
if ( V_37 >= V_182 )
continue;
if ( V_171 -> V_183 == F_81 ( V_10 -> V_13 ) )
continue;
V_52 = F_97 ( V_10 , V_171 -> V_183 ,
V_164 , V_37 ) ;
if ( ! F_98 ( V_52 ) )
F_46 ( V_52 , 0 , L_12 ) ;
else if ( F_99 ( V_52 ) != - V_184 )
V_108 = F_99 ( V_52 ) ;
}
F_100 ( V_10 ) ;
F_101 ( & V_10 -> V_53 , V_50 ) ;
F_7 (port, tmp, &adapter->port_list, list)
F_92 ( V_52 , & V_172 ) ;
F_102 ( & V_10 -> V_53 , V_50 ) ;
F_7 (port, tmp, &remove_lh, list) {
F_103 ( V_52 , 0 , L_13 ) ;
F_104 ( & V_52 -> V_121 , & V_185 ) ;
}
return V_108 ;
}
void F_105 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 , struct V_9 ,
V_69 ) ;
int V_108 , V_60 ;
struct V_82 * V_83 ;
int V_186 , V_166 , V_154 , V_158 ;
V_186 = V_10 -> V_187 & V_188 ;
V_154 = V_186 ? V_189 : 1 ;
V_166 = V_186 ? V_190 : V_179 ;
V_158 = V_186 ? V_191 : V_115 ;
if ( F_106 ( V_10 -> V_13 ) != V_192 &&
F_106 ( V_10 -> V_13 ) != V_193 )
return;
if ( F_18 ( & V_10 -> V_40 -> V_43 ) )
return;
V_83 = F_89 ( V_154 ) ;
if ( ! V_83 )
goto V_35;
for ( V_60 = 0 ; V_60 < 3 ; V_60 ++ ) {
V_108 = F_91 ( V_83 , V_10 , V_158 ) ;
if ( ! V_108 ) {
V_108 = F_95 ( V_83 , V_10 , V_166 ) ;
if ( V_108 == - V_177 )
F_107 ( 1 ) ;
else
break;
}
}
F_108 ( & V_83 -> V_113 , V_154 ) ;
F_78 ( V_143 , V_83 ) ;
V_35:
F_30 ( & V_10 -> V_40 -> V_43 ) ;
}
static int F_109 ( struct V_9 * V_10 ,
struct V_82 * V_83 )
{
F_60 ( V_105 ) ;
char V_194 [] = L_14 ;
struct V_84 * V_85 = & V_83 -> V_85 ;
struct V_195 * V_196 = & V_83 -> V_88 . V_197 . V_70 ;
struct V_198 * V_199 = & V_83 -> V_88 . V_197 . V_90 ;
int V_108 ;
F_58 ( & V_196 -> V_91 , V_200 ,
V_201 ) ;
F_83 ( V_196 -> V_197 . V_94 , F_84 ( V_10 -> V_13 ) ) ;
F_61 ( & V_83 -> V_111 , V_196 , sizeof( * V_196 ) ) ;
F_61 ( & V_83 -> V_113 , V_199 , sizeof( * V_199 ) ) ;
V_85 -> V_109 = F_56 ;
V_85 -> V_110 = & V_105 ;
V_85 -> V_70 = & V_83 -> V_111 ;
V_85 -> V_112 = & V_83 -> V_113 ;
V_108 = F_62 ( & V_10 -> V_40 -> V_43 , V_85 , NULL ,
V_118 ) ;
if ( V_108 )
return V_108 ;
F_63 ( & V_105 ) ;
if ( V_85 -> V_25 )
return V_85 -> V_25 ;
if ( F_106 ( V_10 -> V_13 ) == V_193 &&
! ( strstr ( V_199 -> V_197 . V_202 , V_194 ) ) )
snprintf ( F_110 ( V_10 -> V_13 ) ,
V_201 , L_15 ,
V_199 -> V_197 . V_202 , V_194 ,
F_111 ( & V_10 -> V_122 -> V_121 ) ,
F_112 () -> V_203 ) ;
else
F_113 ( F_110 ( V_10 -> V_13 ) ,
V_199 -> V_197 . V_202 , V_201 ) ;
return 0 ;
}
static void F_114 ( struct V_9 * V_10 ,
struct V_82 * V_83 )
{
F_60 ( V_105 ) ;
struct V_144 * V_145 = V_10 -> V_13 ;
struct V_84 * V_85 = & V_83 -> V_85 ;
struct V_204 * V_205 = & V_83 -> V_88 . V_206 . V_70 ;
struct V_95 * V_207 = & V_83 -> V_88 . V_206 . V_90 ;
int V_108 , V_208 ;
F_58 ( & V_205 -> V_91 , V_209 ,
V_201 ) ;
F_83 ( V_205 -> V_206 . V_210 . V_94 , F_84 ( V_145 ) ) ;
V_208 = F_113 ( V_205 -> V_206 . V_211 , F_110 ( V_145 ) ,
V_201 ) ;
V_205 -> V_206 . V_212 = V_208 ;
F_61 ( & V_83 -> V_111 , V_205 , sizeof( * V_205 ) ) ;
F_61 ( & V_83 -> V_113 , V_207 , sizeof( * V_207 ) ) ;
V_85 -> V_109 = F_56 ;
V_85 -> V_110 = & V_105 ;
V_85 -> V_70 = & V_83 -> V_111 ;
V_85 -> V_112 = & V_83 -> V_113 ;
V_108 = F_62 ( & V_10 -> V_40 -> V_43 , V_85 , NULL ,
V_118 ) ;
if ( ! V_108 )
F_63 ( & V_105 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 , struct V_9 ,
V_213 ) ;
int V_108 ;
struct V_82 * V_83 ;
if ( F_106 ( V_10 -> V_13 ) != V_192 &&
F_106 ( V_10 -> V_13 ) != V_193 )
return;
V_83 = F_80 ( V_143 , V_155 ) ;
if ( ! V_83 )
return;
V_108 = F_18 ( & V_10 -> V_40 -> V_43 ) ;
if ( V_108 )
goto V_214;
V_108 = F_109 ( V_10 , V_83 ) ;
if ( V_108 || F_106 ( V_10 -> V_13 ) != V_193 )
goto V_215;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
F_114 ( V_10 , V_83 ) ;
V_215:
F_30 ( & V_10 -> V_40 -> V_43 ) ;
V_214:
F_78 ( V_143 , V_83 ) ;
}
static void F_116 ( void * V_15 )
{
struct V_216 * V_217 = V_15 ;
struct V_84 * V_218 = V_217 -> V_219 ;
struct V_220 * V_221 = V_217 -> V_222 ;
V_221 -> V_223 = V_217 -> V_224 . V_225 ;
V_221 -> V_226 . V_227 . V_25 = V_228 ;
V_221 -> V_229 = V_218 -> V_25 ? - V_32 : 0 ;
V_217 -> V_230 ( V_217 ) ;
}
static struct V_21 * F_117 ( struct V_216 * V_217 )
{
T_1 V_231 ;
T_4 V_232 ;
struct V_9 * V_10 ;
V_231 = V_217 -> V_233 -> V_234 . V_235 . V_231 ;
V_232 = ( V_231 & 0xff000000 ) >> 24 ;
V_10 = (struct V_9 * ) V_217 -> V_145 -> V_236 [ 0 ] ;
switch ( V_232 ) {
case V_237 :
return & V_10 -> V_40 -> V_44 ;
case V_238 :
return & V_10 -> V_40 -> V_41 ;
case V_239 :
return & V_10 -> V_40 -> V_42 ;
break;
case V_101 :
return & V_10 -> V_40 -> V_43 ;
break;
default:
return NULL ;
}
}
static void F_118 ( void * V_15 )
{
struct V_216 * V_217 = V_15 ;
struct V_21 * V_22 ;
V_22 = F_117 ( V_217 ) ;
F_30 ( V_22 ) ;
F_116 ( V_15 ) ;
}
static int F_119 ( struct V_216 * V_217 ,
struct V_9 * V_10 )
{
struct V_84 * V_240 = V_217 -> V_219 ;
struct V_241 * V_242 = V_217 -> V_242 ;
struct V_51 * V_52 ;
T_1 V_37 ;
if ( V_242 ) {
V_52 = F_120 ( V_10 , V_242 -> V_243 ) ;
if ( ! V_52 )
return - V_244 ;
V_37 = V_52 -> V_37 ;
F_70 ( & V_52 -> V_121 ) ;
} else
V_37 = F_44 ( V_217 -> V_233 -> V_234 . V_245 . V_246 ) ;
V_240 -> V_109 = F_116 ;
return F_85 ( V_10 , V_37 , V_240 , V_217 -> V_70 -> V_247 / V_36 ) ;
}
static int F_121 ( struct V_216 * V_217 ,
struct V_9 * V_10 )
{
int V_108 ;
struct V_84 * V_248 = V_217 -> V_219 ;
struct V_21 * V_22 ;
V_22 = F_117 ( V_217 ) ;
if ( ! V_22 )
return - V_244 ;
V_108 = F_18 ( V_22 ) ;
if ( V_108 )
return V_108 ;
V_248 -> V_109 = F_118 ;
V_108 = F_62 ( V_22 , V_248 , NULL , V_217 -> V_70 -> V_247 / V_36 ) ;
if ( V_108 )
F_30 ( V_22 ) ;
return V_108 ;
}
int F_122 ( struct V_216 * V_217 )
{
struct V_144 * V_145 ;
struct V_9 * V_10 ;
struct V_84 * V_85 = V_217 -> V_219 ;
V_145 = V_217 -> V_242 ? F_123 ( V_217 -> V_242 ) : V_217 -> V_145 ;
V_10 = (struct V_9 * ) V_145 -> V_236 [ 0 ] ;
if ( ! ( F_27 ( & V_10 -> V_25 ) & V_141 ) )
return - V_244 ;
V_85 -> V_70 = V_217 -> V_249 . V_250 ;
V_85 -> V_112 = V_217 -> V_224 . V_250 ;
V_85 -> V_110 = V_217 ;
switch ( V_217 -> V_233 -> V_251 ) {
case V_252 :
case V_253 :
return F_119 ( V_217 , V_10 ) ;
case V_254 :
case V_255 :
return F_121 ( V_217 , V_10 ) ;
default:
return - V_244 ;
}
}
int F_124 ( struct V_216 * V_217 )
{
return - V_177 ;
}
int F_125 ( struct V_9 * V_10 )
{
struct V_39 * V_256 ;
V_256 = F_126 ( sizeof( struct V_39 ) , V_155 ) ;
if ( ! V_256 )
return - V_119 ;
V_10 -> V_40 = V_256 ;
F_33 ( & V_256 -> V_41 , V_257 , V_10 ) ;
F_33 ( & V_256 -> V_42 , V_258 , V_10 ) ;
F_33 ( & V_256 -> V_43 , V_259 , V_10 ) ;
F_33 ( & V_256 -> V_44 , V_260 , V_10 ) ;
return 0 ;
}
void F_127 ( struct V_9 * V_10 )
{
F_11 ( V_10 -> V_40 ) ;
V_10 -> V_40 = NULL ;
}
