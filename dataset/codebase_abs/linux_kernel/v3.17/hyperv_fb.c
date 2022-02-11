static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static T_1 V_5 = F_2 ( 0 ) ;
int V_6 ;
V_4 -> V_7 . type = V_8 ;
V_4 -> V_7 . V_9 = V_4 -> V_10 . V_9 ;
V_6 = F_3 ( V_2 -> V_11 , V_4 ,
V_4 -> V_10 . V_9 + sizeof( struct V_12 ) ,
F_4 ( & V_5 ) ,
V_13 , 0 ) ;
if ( V_6 )
F_5 ( L_1 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_3 V_4 ;
if ( ! V_15 )
return - V_16 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_10 . type = V_17 ;
V_4 . V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_19 ) ;
V_4 . V_20 . V_21 = 0 ;
V_4 . V_20 . V_22 = 1 ;
V_4 . V_20 . V_23 [ 0 ] . V_24 = 1 ;
V_4 . V_20 . V_23 [ 0 ] . V_25 = 0 ;
V_4 . V_20 . V_23 [ 0 ] . V_26 = V_15 -> V_27 . V_28 ;
V_4 . V_20 . V_23 [ 0 ] . V_29 = V_15 -> V_27 . V_30 ;
V_4 . V_20 . V_23 [ 0 ] . V_31 = V_15 -> V_27 . V_32 ;
V_4 . V_20 . V_23 [ 0 ] . V_33 = V_15 -> V_34 . V_35 ;
F_1 ( V_2 , & V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_10 . type = V_36 ;
V_4 . V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_37 ) ;
V_4 . V_38 . V_39 = 1 ;
V_4 . V_38 . V_23 = 0 ;
V_4 . V_38 . V_40 = 0 ;
V_4 . V_38 . V_41 = 0 ;
F_1 ( V_2 , & V_4 ) ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_10 . type = V_42 ;
V_4 . V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_43 ) ;
V_4 . V_44 . V_45 = V_46 ;
V_4 . V_44 . V_47 = 1 ;
V_4 . V_44 . V_48 = 1 ;
V_4 . V_44 . V_49 = 1 ;
V_4 . V_44 . V_50 = 0 ;
V_4 . V_44 . V_51 = 0 ;
V_4 . V_44 . V_52 [ 0 ] = 0 ;
V_4 . V_44 . V_52 [ 1 ] = 1 ;
V_4 . V_44 . V_52 [ 2 ] = 1 ;
V_4 . V_44 . V_52 [ 3 ] = 1 ;
F_1 ( V_2 , & V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 -> V_53 ) ;
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_10 . type = V_54 ;
V_4 . V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_55 ) ;
V_4 . V_56 . V_23 = 0 ;
V_4 . V_56 . V_57 = 1 ;
V_4 . V_56 . V_58 [ 0 ] . V_59 = 0 ;
V_4 . V_56 . V_58 [ 0 ] . y1 = 0 ;
V_4 . V_56 . V_58 [ 0 ] . V_60 = V_15 -> V_27 . V_30 ;
V_4 . V_56 . V_58 [ 0 ] . V_61 = V_15 -> V_27 . V_32 ;
F_1 ( V_2 , & V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 ;
struct V_3 * V_4 ;
if ( ! V_15 )
return;
V_63 = V_15 -> V_63 ;
V_4 = (struct V_3 * ) V_63 -> V_64 ;
if ( V_4 -> V_10 . type == V_65 ||
V_4 -> V_10 . type == V_66 ) {
memcpy ( V_63 -> V_67 , V_4 , V_68 ) ;
F_12 ( & V_63 -> V_69 ) ;
return;
}
if ( V_4 -> V_10 . type == V_70 ) {
if ( V_63 -> V_71 ) {
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
}
V_63 -> V_72 = V_4 -> V_73 . V_74 ;
if ( V_63 -> V_72 )
F_13 ( & V_63 -> V_75 , V_76 ) ;
}
}
static void F_14 ( void * V_77 )
{
struct V_1 * V_2 = V_77 ;
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 ;
struct V_3 * V_64 ;
T_2 V_78 ;
T_3 V_79 ;
int V_6 ;
if ( ! V_15 )
return;
V_63 = V_15 -> V_63 ;
V_64 = (struct V_3 * ) V_63 -> V_64 ;
do {
V_6 = F_15 ( V_2 -> V_11 , V_64 ,
V_68 ,
& V_78 , & V_79 ) ;
if ( V_78 > 0 &&
V_64 -> V_7 . type == V_8 )
F_11 ( V_2 ) ;
} while ( V_78 > 0 && V_6 == 0 );
}
static int F_16 ( struct V_1 * V_2 , T_2 V_80 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 = V_15 -> V_63 ;
struct V_3 * V_4 = (struct V_3 * ) V_63 -> V_67 ;
int V_81 , V_6 = 0 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_10 . type = V_82 ;
V_4 -> V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_83 ) ;
V_4 -> V_84 . V_85 = V_80 ;
F_1 ( V_2 , V_4 ) ;
V_81 = F_17 ( & V_63 -> V_69 , V_86 ) ;
if ( ! V_81 ) {
F_5 ( L_2 ) ;
V_6 = - V_87 ;
goto V_88;
}
if ( ! V_4 -> V_89 . V_90 ) {
V_6 = - V_16 ;
goto V_88;
}
V_63 -> V_91 = V_80 ;
V_88:
return V_6 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 = V_15 -> V_63 ;
int V_6 ;
V_6 = F_19 ( V_2 -> V_11 , V_92 , V_92 ,
NULL , 0 , F_14 , V_2 ) ;
if ( V_6 ) {
F_5 ( L_3 ) ;
return V_6 ;
}
if ( V_93 == V_94 ||
V_93 == V_95 )
V_6 = F_16 ( V_2 , V_96 ) ;
else
V_6 = F_16 ( V_2 , V_97 ) ;
if ( V_6 ) {
F_5 ( L_4 ) ;
goto error;
}
if ( V_63 -> V_91 == V_96 )
V_98 = V_99 ;
else
V_98 = V_100 ;
V_101 = V_2 -> V_11 -> V_102 . V_103 .
V_104 * 1024 * 1024 ;
return 0 ;
error:
F_20 ( V_2 -> V_11 ) ;
return V_6 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 = V_15 -> V_63 ;
struct V_3 * V_4 = (struct V_3 * ) V_63 -> V_67 ;
int V_81 , V_6 = 0 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_10 . type = V_105 ;
V_4 -> V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_106 ) ;
V_4 -> V_107 . V_21 = V_4 -> V_107 . V_108 = V_15 -> V_34 . V_109 ;
V_4 -> V_107 . V_110 = 1 ;
F_1 ( V_2 , V_4 ) ;
V_81 = F_17 ( & V_63 -> V_69 , V_86 ) ;
if ( ! V_81 ) {
F_5 ( L_5 ) ;
V_6 = - V_87 ;
goto V_88;
}
if ( V_4 -> V_111 . V_21 != V_15 -> V_34 . V_109 ) {
F_5 ( L_6 ) ;
V_6 = - V_16 ;
goto V_88;
}
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
V_88:
return V_6 ;
}
static void F_22 ( struct V_112 * V_113 )
{
struct V_62 * V_63 = F_23 ( V_113 , struct V_62 , V_75 . V_114 ) ;
struct V_14 * V_15 = V_63 -> V_15 ;
if ( V_63 -> V_71 )
F_9 ( V_15 ) ;
if ( V_63 -> V_72 )
F_13 ( & V_63 -> V_75 , V_76 ) ;
}
static int F_24 ( struct V_115 * V_116 ,
unsigned long V_117 , void * V_118 )
{
struct V_62 * V_63 ;
struct V_14 * V_15 ;
V_63 = F_23 ( V_116 , struct V_62 , V_119 ) ;
V_63 -> V_120 = true ;
V_15 = V_63 -> V_15 ;
F_9 ( V_15 ) ;
return V_121 ;
}
static int F_25 ( struct V_122 * V_27 , struct V_14 * V_15 )
{
if ( V_27 -> V_30 < V_123 || V_27 -> V_32 < V_124 ||
V_27 -> V_30 > V_125 || V_27 -> V_32 > V_126 ||
V_27 -> V_28 != V_98 )
return - V_127 ;
V_27 -> V_128 = V_27 -> V_30 ;
V_27 -> V_129 = V_27 -> V_32 ;
return 0 ;
}
static int F_26 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 -> V_53 ) ;
return F_6 ( V_2 ) ;
}
static inline T_2 F_27 ( T_2 V_130 , struct V_131 * V_132 )
{
return ( ( V_130 & 0xffff ) >> ( 16 - V_132 -> V_133 ) ) << V_132 -> V_134 ;
}
static int F_28 ( unsigned V_135 , unsigned V_136 , unsigned V_137 ,
unsigned V_138 , unsigned V_139 , struct V_14 * V_15 )
{
T_2 * V_140 = V_15 -> V_141 ;
if ( V_135 > 15 )
return - V_127 ;
V_140 [ V_135 ] = F_27 ( V_136 , & V_15 -> V_27 . V_136 )
| F_27 ( V_137 , & V_15 -> V_27 . V_137 )
| F_27 ( V_138 , & V_15 -> V_27 . V_138 )
| F_27 ( V_139 , & V_15 -> V_27 . V_139 ) ;
return 0 ;
}
static int F_29 ( int V_142 , struct V_14 * V_15 )
{
return 1 ;
}
static void F_30 ( struct V_14 * V_118 ,
const struct V_143 * V_58 )
{
struct V_62 * V_63 = V_118 -> V_63 ;
F_31 ( V_118 , V_58 ) ;
if ( V_63 -> V_120 )
F_9 ( V_118 ) ;
}
static void F_32 ( struct V_14 * V_118 ,
const struct V_144 * V_145 )
{
struct V_62 * V_63 = V_118 -> V_63 ;
F_33 ( V_118 , V_145 ) ;
if ( V_63 -> V_120 )
F_9 ( V_118 ) ;
}
static void F_34 ( struct V_14 * V_118 ,
const struct V_146 * V_147 )
{
struct V_62 * V_63 = V_118 -> V_63 ;
F_35 ( V_118 , V_147 ) ;
if ( V_63 -> V_120 )
F_9 ( V_118 ) ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_62 * V_63 = V_15 -> V_63 ;
char * V_148 = NULL , * V_118 ;
T_4 V_149 = 0 , V_150 = 0 ;
if ( F_37 ( V_151 , & V_148 ) || ! V_148 || ! * V_148 )
return;
V_118 = F_38 ( & V_148 , L_7 ) ;
if ( ! * V_118 || F_39 ( V_118 , 0 , & V_149 ) ||
! V_148 || ! * V_148 || F_39 ( V_148 , 0 , & V_150 ) ) {
F_5 ( L_8 ) ;
return;
}
if ( V_149 < V_123 || V_150 < V_124 ||
( V_63 -> V_91 == V_97 &&
V_149 * V_150 * V_98 / 8 > V_152 ) ||
( V_63 -> V_91 == V_96 &&
( V_149 > V_153 || V_150 > V_154 ) ) ) {
F_5 ( L_9 ) ;
return;
}
V_125 = V_149 ;
V_126 = V_150 ;
return;
}
static int F_40 ( struct V_14 * V_15 )
{
struct V_62 * V_63 = V_15 -> V_63 ;
struct V_155 * V_156 = NULL ;
void T_5 * V_157 ;
int V_158 = F_41 ( V_159 ) ;
int V_6 ;
V_63 -> V_160 . V_161 = V_151 ;
V_63 -> V_160 . V_162 = V_163 | V_164 ;
if ( V_158 ) {
V_6 = F_42 ( & V_165 , & V_63 -> V_160 ,
V_101 ,
0 , - 1 ,
V_101 ,
NULL , NULL ) ;
if ( V_6 != 0 ) {
F_5 ( L_10 ) ;
return - V_16 ;
}
} else {
V_156 = F_43 ( V_166 ,
V_167 , NULL ) ;
if ( ! V_156 ) {
F_5 ( L_11 ) ;
return - V_16 ;
}
if ( ! ( F_44 ( V_156 , 0 ) & V_163 ) ||
F_45 ( V_156 , 0 ) < V_101 )
goto V_168;
V_63 -> V_160 . V_169 = F_46 ( V_156 , 0 ) ;
V_63 -> V_160 . V_170 = V_63 -> V_160 . V_169 - V_101 + 1 ;
V_6 = F_47 ( & V_156 -> V_171 [ 0 ] , & V_63 -> V_160 ) ;
if ( V_6 != 0 ) {
F_5 ( L_12 ) ;
goto V_168;
}
}
V_157 = F_48 ( V_63 -> V_160 . V_170 , V_101 ) ;
if ( ! V_157 )
goto V_172;
V_15 -> V_173 = F_49 ( 1 ) ;
if ( ! V_15 -> V_173 )
goto V_174;
if ( V_158 ) {
V_15 -> V_173 -> V_175 [ 0 ] . V_176 = V_177 . V_178 ;
V_15 -> V_173 -> V_175 [ 0 ] . V_9 = V_177 . V_179 ;
F_50 ( V_15 -> V_173 ,
V_151 , false ) ;
} else {
V_15 -> V_173 -> V_175 [ 0 ] . V_176 = F_51 ( V_156 , 0 ) ;
V_15 -> V_173 -> V_175 [ 0 ] . V_9 = F_45 ( V_156 , 0 ) ;
}
V_15 -> V_34 . V_109 = V_63 -> V_160 . V_170 ;
V_15 -> V_34 . V_180 = V_101 ;
V_15 -> V_181 = V_157 ;
V_15 -> V_182 = V_101 ;
if ( ! V_158 )
F_52 ( V_156 ) ;
return 0 ;
V_174:
F_53 ( V_157 ) ;
V_172:
F_54 ( & V_63 -> V_160 ) ;
V_168:
if ( ! V_158 )
F_52 ( V_156 ) ;
return - V_183 ;
}
static void F_55 ( struct V_14 * V_15 )
{
struct V_62 * V_63 = V_15 -> V_63 ;
F_53 ( V_15 -> V_181 ) ;
F_54 ( & V_63 -> V_160 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
const struct V_184 * V_185 )
{
struct V_14 * V_15 ;
struct V_62 * V_63 ;
int V_6 ;
V_15 = F_57 ( sizeof( struct V_62 ) , & V_2 -> V_53 ) ;
if ( ! V_15 ) {
F_5 ( L_13 ) ;
return - V_183 ;
}
V_63 = V_15 -> V_63 ;
V_63 -> V_15 = V_15 ;
V_63 -> V_71 = false ;
F_58 ( & V_63 -> V_69 ) ;
F_59 ( & V_63 -> V_75 , F_22 ) ;
F_60 ( V_2 , V_15 ) ;
V_6 = F_18 ( V_2 ) ;
if ( V_6 ) {
F_5 ( L_14 ) ;
goto V_186;
}
V_6 = F_40 ( V_15 ) ;
if ( V_6 ) {
F_5 ( L_15 ) ;
goto V_187;
}
F_36 ( V_15 ) ;
F_61 ( L_16 ,
V_125 , V_126 , V_98 ) ;
V_15 -> V_162 = V_188 ;
V_15 -> V_27 . V_128 = V_15 -> V_27 . V_30 = V_125 ;
V_15 -> V_27 . V_129 = V_15 -> V_27 . V_32 = V_126 ;
V_15 -> V_27 . V_28 = V_98 ;
if ( V_15 -> V_27 . V_28 == 16 ) {
V_15 -> V_27 . V_136 = (struct V_131 ) { 11 , 5 , 0 } ;
V_15 -> V_27 . V_137 = (struct V_131 ) { 5 , 6 , 0 } ;
V_15 -> V_27 . V_138 = (struct V_131 ) { 0 , 5 , 0 } ;
V_15 -> V_27 . V_139 = (struct V_131 ) { 0 , 0 , 0 } ;
} else {
V_15 -> V_27 . V_136 = (struct V_131 ) { 16 , 8 , 0 } ;
V_15 -> V_27 . V_137 = (struct V_131 ) { 8 , 8 , 0 } ;
V_15 -> V_27 . V_138 = (struct V_131 ) { 0 , 8 , 0 } ;
V_15 -> V_27 . V_139 = (struct V_131 ) { 24 , 8 , 0 } ;
}
V_15 -> V_27 . V_189 = V_190 ;
V_15 -> V_27 . V_49 = - 1 ;
V_15 -> V_27 . V_48 = - 1 ;
V_15 -> V_27 . V_191 = V_192 ;
strcpy ( V_15 -> V_34 . V_193 , V_151 ) ;
V_15 -> V_34 . type = V_194 ;
V_15 -> V_34 . V_195 = V_196 ;
V_15 -> V_34 . V_35 = V_125 * V_98 / 8 ;
V_15 -> V_34 . V_197 = V_198 ;
V_15 -> V_199 = & V_200 ;
V_15 -> V_141 = V_63 -> V_141 ;
V_6 = F_21 ( V_2 ) ;
if ( V_6 )
goto error;
V_6 = F_62 ( V_15 ) ;
if ( V_6 ) {
F_5 ( L_17 ) ;
goto error;
}
V_63 -> V_71 = true ;
V_63 -> V_120 = false ;
V_63 -> V_119 . V_201 = F_24 ;
F_63 ( & V_202 ,
& V_63 -> V_119 ) ;
return 0 ;
error:
F_55 ( V_15 ) ;
V_187:
F_20 ( V_2 -> V_11 ) ;
V_186:
F_64 ( & V_63 -> V_75 ) ;
F_60 ( V_2 , NULL ) ;
F_65 ( V_15 ) ;
return V_6 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 = V_15 -> V_63 ;
F_67 ( & V_202 ,
& V_63 -> V_119 ) ;
V_63 -> V_72 = false ;
V_63 -> V_71 = false ;
F_68 ( V_15 ) ;
F_64 ( & V_63 -> V_75 ) ;
F_20 ( V_2 -> V_11 ) ;
F_60 ( V_2 , NULL ) ;
F_55 ( V_15 ) ;
F_65 ( V_15 ) ;
return 0 ;
}
static int F_69 ( struct V_155 * V_156 ,
const struct V_203 * V_204 )
{
return 0 ;
}
static void F_70 ( struct V_155 * V_156 )
{
}
static int T_6 F_71 ( void )
{
int V_6 ;
V_6 = F_72 ( & V_205 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_73 ( & V_206 ) ;
if ( V_6 != 0 ) {
F_74 ( & V_205 ) ;
return V_6 ;
}
return 0 ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_206 ) ;
F_74 ( & V_205 ) ;
}
