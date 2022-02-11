int F_1 ( void )
{
int V_1 = 0 ;
V_2 = F_2 ( 0 , V_3 , & V_4 ) ;
V_1 = V_2 ;
if ( V_1 < 0 )
goto V_5;
V_6 = F_3 ( V_7 , V_3 ) ;
V_1 = F_4 ( V_6 ) ;
if ( F_5 ( V_6 ) )
goto V_8;
V_9 = F_6 ( V_6 , NULL ,
F_7 ( V_2 , 0 ) ,
NULL , V_3 ) ;
V_1 = F_4 ( V_9 ) ;
if ( F_5 ( V_9 ) )
goto V_10;
return 0 ;
V_10:
F_8 ( V_6 ) ;
V_8:
F_9 ( V_2 , V_3 ) ;
V_5:
return V_1 ;
}
void F_10 ( void )
{
F_11 ( V_6 , F_7 ( V_2 , 0 ) ) ;
F_8 ( V_6 ) ;
F_9 ( V_2 , V_3 ) ;
}
struct V_11 * F_12 ( void )
{
return V_9 ;
}
static int F_13 ( struct V_12 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 ;
bool V_17 ;
if ( F_14 ( V_12 ) != 0 )
return - V_18 ;
V_17 = F_15 () ;
if ( V_17 ) {
F_16 ( V_9 ,
L_1
L_2 ,
V_19 -> V_20 ) ;
return - V_21 ;
}
V_16 = F_17 ( V_19 ) ;
if ( F_5 ( V_16 ) )
return F_4 ( V_16 ) ;
F_18 ( V_9 , L_3 ,
V_16 -> V_22 , V_16 -> V_17 ) ;
return 0 ;
}
static int F_19 ( struct V_13 * V_14 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_25 * args = V_24 ;
args -> V_26 = V_27 ;
args -> V_28 = V_29 ;
return 0 ;
}
static int F_20 ( struct V_30 * V_31 ,
struct V_32 * args )
{
if ( args -> V_33 > V_34 ) {
F_21 ( L_4 ) ;
return - V_35 ;
}
if ( args -> V_36 > V_37 ) {
F_21 ( L_5 ) ;
return - V_35 ;
}
if ( ( args -> V_38 ) &&
( ! F_22 ( V_39 ,
( const void V_40 * ) args -> V_38 ,
sizeof( V_41 ) ) ) ) {
F_21 ( L_6 ) ;
return - V_42 ;
}
if ( ! F_23 ( args -> V_43 ) && ( args -> V_43 != 0 ) ) {
F_21 ( L_7 ) ;
return - V_35 ;
}
if ( ! F_22 ( V_39 ,
( const void V_40 * ) args -> V_44 ,
sizeof( V_45 ) ) ) {
F_21 ( L_8 ) ;
return - V_42 ;
}
if ( ! F_22 ( V_39 ,
( const void V_40 * ) args -> V_46 ,
sizeof( V_45 ) ) ) {
F_21 ( L_9 ) ;
return - V_42 ;
}
if ( args -> V_47 &&
! F_22 ( V_39 ,
( const void V_40 * ) args -> V_47 ,
sizeof( V_45 ) ) ) {
F_24 ( L_10 ) ;
return - V_42 ;
}
if ( args -> V_48 &&
! F_22 ( V_39 ,
( const void V_40 * ) args -> V_48 ,
sizeof( V_45 ) ) ) {
F_24 ( L_11 ) ;
return - V_42 ;
}
V_31 -> V_49 = false ;
V_31 -> V_50 = args -> V_33 ;
V_31 -> V_51 = args -> V_36 ;
V_31 -> V_52 = args -> V_38 ;
V_31 -> V_53 = args -> V_43 ;
V_31 -> V_54 = ( V_45 * ) args -> V_44 ;
V_31 -> V_55 = ( V_45 * ) args -> V_46 ;
V_31 -> V_56 = args -> V_47 ;
V_31 -> V_57 = args -> V_58 ;
V_31 -> V_59 =
args -> V_48 ;
V_31 -> V_60 = args -> V_61 ;
if ( args -> V_62 == V_63 ||
args -> V_62 == V_64 )
V_31 -> type = V_65 ;
else if ( args -> V_62 == V_66 )
V_31 -> type = V_67 ;
else
return - V_68 ;
if ( args -> V_62 == V_64 )
V_31 -> V_69 = V_70 ;
else
V_31 -> V_69 = V_71 ;
F_24 ( L_12 ,
V_31 -> V_50 , args -> V_33 ) ;
F_24 ( L_13 ,
V_31 -> V_51 , args -> V_36 ) ;
F_24 ( L_14 ,
V_31 -> V_52 , args -> V_38 ) ;
F_24 ( L_15 ,
V_31 -> V_53 , args -> V_43 ) ;
F_24 ( L_16 ,
( V_41 ) V_31 -> V_54 ,
( V_41 ) V_31 -> V_55 ) ;
F_24 ( L_17 , V_31 -> V_69 ) ;
F_24 ( L_18 , V_31 -> V_56 ) ;
F_24 ( L_19 ,
V_31 -> V_59 ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_32 * args = V_24 ;
struct V_72 * V_73 ;
int V_1 = 0 ;
unsigned int V_74 ;
struct V_75 * V_76 ;
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
F_24 ( L_20 ) ;
V_1 = F_20 ( & V_31 , args ) ;
if ( V_1 )
return V_1 ;
F_24 ( L_21 , args -> V_77 ) ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL ) {
F_24 ( L_22 , args -> V_77 ) ;
return - V_35 ;
}
F_27 ( & V_23 -> V_78 ) ;
V_76 = F_28 ( V_73 , V_23 ) ;
if ( F_5 ( V_76 ) ) {
V_1 = - V_79 ;
goto V_80;
}
F_24 ( L_23 ,
V_23 -> V_22 ,
V_73 -> V_81 ) ;
V_1 = F_29 ( & V_23 -> V_82 , V_73 , V_14 , & V_31 ,
0 , V_31 . type , & V_74 ) ;
if ( V_1 != 0 )
goto V_83;
args -> V_74 = V_74 ;
args -> V_84 = ( V_85 | args -> V_77 ) ;
args -> V_84 <<= V_86 ;
F_30 ( & V_23 -> V_78 ) ;
F_24 ( L_24 , args -> V_74 ) ;
F_24 ( L_25 ,
args -> V_38 ) ;
F_24 ( L_26 ,
args -> V_44 ) ;
F_24 ( L_27 ,
args -> V_46 ) ;
return 0 ;
V_83:
V_80:
F_30 ( & V_23 -> V_78 ) ;
return V_1 ;
}
static int F_31 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
int V_88 ;
struct V_89 * args = V_24 ;
F_24 ( L_28 ,
args -> V_74 ,
V_23 -> V_22 ) ;
F_27 ( & V_23 -> V_78 ) ;
V_88 = F_32 ( & V_23 -> V_82 , args -> V_74 ) ;
F_30 ( & V_23 -> V_78 ) ;
return V_88 ;
}
static int F_33 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
int V_88 ;
struct V_90 * args = V_24 ;
struct V_30 V_91 ;
if ( args -> V_33 > V_34 ) {
F_21 ( L_4 ) ;
return - V_35 ;
}
if ( args -> V_36 > V_37 ) {
F_21 ( L_5 ) ;
return - V_35 ;
}
if ( ( args -> V_38 ) &&
( ! F_22 ( V_39 ,
( const void V_40 * ) args -> V_38 ,
sizeof( V_41 ) ) ) ) {
F_21 ( L_6 ) ;
return - V_42 ;
}
if ( ! F_23 ( args -> V_43 ) && ( args -> V_43 != 0 ) ) {
F_21 ( L_7 ) ;
return - V_35 ;
}
V_91 . V_52 = args -> V_38 ;
V_91 . V_53 = args -> V_43 ;
V_91 . V_50 = args -> V_33 ;
V_91 . V_51 = args -> V_36 ;
F_24 ( L_29 ,
args -> V_74 , V_23 -> V_22 ) ;
F_27 ( & V_23 -> V_78 ) ;
V_88 = F_34 ( & V_23 -> V_82 , args -> V_74 , & V_91 ) ;
F_30 ( & V_23 -> V_78 ) ;
return V_88 ;
}
static int F_35 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_92 * args = V_24 ;
struct V_72 * V_73 ;
int V_1 = 0 ;
struct V_75 * V_76 ;
enum V_93 V_94 , V_95 ;
if ( args -> V_94 != V_96
&& args -> V_94 != V_97 ) {
return - V_35 ;
}
if ( args -> V_95 != V_96
&& args -> V_95 != V_97 ) {
return - V_35 ;
}
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
F_27 ( & V_23 -> V_78 ) ;
V_76 = F_28 ( V_73 , V_23 ) ;
if ( F_5 ( V_76 ) ) {
V_1 = - V_79 ;
goto V_98;
}
V_94 = ( args -> V_94 == V_96 )
? V_99 : V_100 ;
V_95 =
( args -> V_95 == V_96 )
? V_99 : V_100 ;
if ( ! V_73 -> V_101 -> V_102 . V_103 ( V_73 -> V_101 ,
& V_76 -> V_104 ,
V_94 ,
V_95 ,
( void V_40 * ) args -> V_105 ,
args -> V_106 ) )
V_1 = - V_35 ;
V_98:
F_30 ( & V_23 -> V_78 ) ;
return V_1 ;
}
static int F_36 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_107 * args = V_24 ;
struct V_72 * V_73 ;
struct V_108 * V_109 ;
struct V_75 * V_76 ;
bool V_110 ;
long V_111 = 0 ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
if ( V_73 -> V_112 -> V_113 == V_114 ) {
F_24 ( L_30 ) ;
return - V_35 ;
}
F_27 ( F_37 () ) ;
F_27 ( & V_23 -> V_78 ) ;
V_76 = F_28 ( V_73 , V_23 ) ;
if ( F_5 ( V_76 ) ) {
F_30 ( & V_23 -> V_78 ) ;
F_30 ( F_37 () ) ;
return F_4 ( V_76 ) ;
}
if ( V_73 -> V_115 == NULL ) {
V_110 = F_38 ( & V_109 , V_73 ) ;
if ( V_110 ) {
V_111 = F_39 ( V_109 , V_23 ) ;
if ( V_111 != 0 )
F_40 ( V_109 ) ;
else
V_73 -> V_115 = V_109 ;
}
} else {
F_24 ( L_31 ) ;
V_111 = - V_35 ;
}
F_30 ( & V_23 -> V_78 ) ;
F_30 ( F_37 () ) ;
return V_111 ;
}
static int F_41 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_116 * args = V_24 ;
struct V_72 * V_73 ;
long V_111 ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
if ( V_73 -> V_112 -> V_113 == V_114 ) {
F_24 ( L_32 ) ;
return - V_35 ;
}
F_27 ( F_37 () ) ;
V_111 = F_42 ( V_73 -> V_115 , V_23 ) ;
if ( V_111 == 0 ) {
F_40 ( V_73 -> V_115 ) ;
V_73 -> V_115 = NULL ;
}
F_30 ( F_37 () ) ;
return V_111 ;
}
static int F_43 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_117 * args = V_24 ;
struct V_72 * V_73 ;
struct V_118 V_119 ;
unsigned char * V_120 ;
long V_111 ;
void V_40 * V_121 ;
V_41 V_122 = 0 ;
unsigned int V_123 = 0 ;
memset ( ( void * ) & V_119 , 0 , sizeof( struct V_118 ) ) ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
if ( V_73 -> V_112 -> V_113 == V_114 ) {
F_24 ( L_33 ) ;
return - V_35 ;
}
V_121 = ( void V_40 * ) args -> V_124 ;
if ( ( args -> V_125 > V_126 ) ||
( args -> V_125 <= sizeof( * args ) + sizeof( int ) * 2 ) ||
( V_121 == NULL ) )
return - V_35 ;
V_120 = F_44 ( V_121 ,
args -> V_125 - sizeof( * args ) ) ;
if ( F_5 ( V_120 ) )
return F_4 ( V_120 ) ;
V_119 . V_16 = V_23 ;
V_119 . V_127 = * ( ( V_45 * ) ( & V_120 [ V_123 ] ) ) ;
V_123 += sizeof( V_119 . V_127 ) ;
V_119 . V_128 = (enum V_129 * ) & V_120 [ V_123 ] ;
V_123 += sizeof( enum V_129 ) * V_119 . V_127 ;
V_119 . V_130 = ( V_41 * ) & V_120 [ V_123 ] ;
V_123 += sizeof( V_119 . V_130 ) * V_119 . V_127 ;
if ( V_123 >= args -> V_125 - sizeof( * args ) ) {
F_45 ( V_120 ) ;
return - V_35 ;
}
V_122 = ( V_41 ) V_120 [ V_123 ] ;
if ( V_122 > 0 ) {
V_119 . V_131 = ( V_41 * ) & V_120 [ V_123 ] ;
V_123 += sizeof( V_119 . V_131 ) *
V_119 . V_127 ;
} else {
V_119 . V_131 = NULL ;
V_123 += sizeof( V_119 . V_131 ) ;
}
if ( V_123 >= args -> V_125 - sizeof( args ) ) {
F_45 ( V_120 ) ;
return - V_35 ;
}
V_119 . V_132 = NULL ;
F_27 ( F_37 () ) ;
V_111 = F_46 ( V_73 -> V_115 , & V_119 ) ;
F_30 ( F_37 () ) ;
F_45 ( V_120 ) ;
return V_111 ;
}
static int F_47 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_133 * args = V_24 ;
struct V_72 * V_73 ;
struct V_134 V_135 ;
unsigned char * V_120 ;
V_45 V_136 ;
long V_111 ;
void V_40 * V_121 ;
unsigned int V_123 = 0 ;
memset ( ( void * ) & V_135 , 0 , sizeof( struct V_134 ) ) ;
V_136 = sizeof( * args ) +
sizeof( V_135 . V_137 ) +
sizeof( V_135 . V_138 ) +
sizeof( V_135 . V_139 . V_140 ) +
sizeof( V_135 . V_139 . V_141 ) +
sizeof( V_135 . V_142 ) ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
if ( V_73 -> V_112 -> V_113 == V_114 ) {
F_24 ( L_33 ) ;
return - V_35 ;
}
if ( args -> V_125 != V_136 ) {
F_24 ( L_34 ,
args -> V_125 , V_136 ) ;
return - V_35 ;
}
V_121 = ( void V_40 * ) args -> V_124 ;
if ( V_121 == NULL )
return - V_35 ;
V_120 = F_44 ( V_121 ,
args -> V_125 - sizeof( * args ) ) ;
if ( F_5 ( V_120 ) )
return F_4 ( V_120 ) ;
V_135 . V_16 = V_23 ;
V_135 . V_138 = * ( (enum V_143 * ) ( & V_120 [ V_123 ] ) ) ;
V_123 += sizeof( V_135 . V_138 ) ;
V_135 . V_137 = * ( (enum V_144 * ) ( & V_120 [ V_123 ] ) ) ;
V_123 += sizeof( V_135 . V_137 ) ;
V_135 . V_142 = * ( ( V_45 * ) ( & V_120 [ V_123 ] ) ) ;
V_123 += sizeof( V_135 . V_142 ) ;
V_135 . V_139 . V_140 . V_145 . V_146 =
* ( ( V_45 * ) ( & V_120 [ V_123 ] ) ) ;
V_135 . V_139 . V_141 = NULL ;
F_27 ( F_37 () ) ;
F_24 ( L_35 ,
V_135 . V_16 , V_135 . V_138 ,
V_135 . V_137 , V_135 . V_142 ,
V_135 . V_139 . V_140 . V_145 . V_146 ) ;
V_111 = F_48 ( V_73 -> V_115 , & V_135 ) ;
F_24 ( L_36 , V_111 ) ;
F_30 ( F_37 () ) ;
F_45 ( V_120 ) ;
return V_111 ;
}
static int F_49 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_147 * args = V_24 ;
struct V_72 * V_73 ;
struct V_148 time ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
args -> V_149 =
V_73 -> V_150 -> V_151 ( V_73 -> V_152 ) ;
F_50 ( & time ) ;
args -> V_153 = ( V_41 ) F_51 ( & time ) ;
F_52 ( & time ) ;
args -> V_154 = ( V_41 ) F_51 ( & time ) ;
args -> V_155 = 1000000000 ;
return 0 ;
}
static int F_53 ( struct V_13 * V_87 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_156 * args = V_24 ;
struct V_157 * V_158 ;
struct V_75 * V_76 ;
F_18 ( V_9 , L_37 , V_23 -> V_22 ) ;
args -> V_159 = 0 ;
F_27 ( & V_23 -> V_78 ) ;
if ( F_54 ( V_23 ) ) {
V_76 = F_55 ( V_23 ) ;
do {
V_158 =
& args -> V_160 [ args -> V_159 ] ;
V_158 -> V_77 = V_76 -> V_73 -> V_81 ;
V_158 -> V_161 = V_76 -> V_161 ;
V_158 -> V_162 = V_76 -> V_162 ;
V_158 -> V_163 = V_76 -> V_163 ;
V_158 -> V_164 = V_76 -> V_164 ;
V_158 -> V_165 = V_76 -> V_165 ;
V_158 -> V_166 = V_76 -> V_166 ;
F_18 ( V_9 ,
L_38 , args -> V_159 ) ;
F_18 ( V_9 ,
L_39 , V_76 -> V_73 -> V_81 ) ;
F_18 ( V_9 ,
L_40 , V_76 -> V_161 ) ;
F_18 ( V_9 ,
L_41 , V_76 -> V_162 ) ;
F_18 ( V_9 ,
L_42 , V_76 -> V_163 ) ;
F_18 ( V_9 ,
L_43 , V_76 -> V_164 ) ;
F_18 ( V_9 ,
L_44 , V_76 -> V_165 ) ;
F_18 ( V_9 ,
L_45 , V_76 -> V_166 ) ;
args -> V_159 ++ ;
} while ( ( V_76 = F_56 ( V_23 , V_76 ) ) != NULL &&
( args -> V_159 < V_167 ) );
}
F_30 ( & V_23 -> V_78 ) ;
return 0 ;
}
static int F_57 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_168 * args = V_24 ;
int V_1 ;
V_1 = F_58 ( V_87 , V_23 , args -> V_169 ,
args -> V_170 != 0 , args -> V_171 ,
& args -> V_172 , & args -> V_173 ,
& args -> V_174 ,
& args -> V_175 ) ;
return V_1 ;
}
static int F_59 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_176 * args = V_24 ;
return F_60 ( V_23 , args -> V_172 ) ;
}
static int F_61 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_177 * args = V_24 ;
return F_62 ( V_23 , args -> V_172 ) ;
}
static int F_63 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_178 * args = V_24 ;
return F_64 ( V_23 , args -> V_172 ) ;
}
static int F_65 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_179 * args = V_24 ;
enum V_180 V_181 ;
int V_1 ;
V_1 = F_66 ( V_23 , args -> V_182 ,
( void V_40 * ) args -> V_183 ,
( args -> V_184 != 0 ) ,
args -> V_185 , & V_181 ) ;
args -> V_181 = V_181 ;
return V_1 ;
}
static long F_67 ( struct V_13 * V_14 , unsigned int V_186 , unsigned long V_187 )
{
struct V_15 * V_16 ;
T_1 * V_188 ;
const struct V_189 * V_190 = NULL ;
unsigned int V_191 = F_68 ( V_186 ) ;
char V_192 [ 128 ] ;
char * V_193 = NULL ;
unsigned int V_194 , V_195 ;
int V_196 = - V_35 ;
if ( V_191 >= V_197 )
goto V_198;
if ( ( V_191 >= V_199 ) && ( V_191 < V_200 ) ) {
T_2 V_201 ;
V_190 = & V_202 [ V_191 ] ;
V_201 = F_69 ( V_190 -> V_186 ) ;
V_194 = V_195 = F_69 ( V_186 ) ;
if ( V_201 > V_195 )
V_195 = V_201 ;
V_186 = V_190 -> V_186 ;
} else
goto V_198;
F_18 ( V_9 , L_46 , V_186 , V_191 , V_187 ) ;
V_16 = F_70 ( V_19 ) ;
if ( F_5 ( V_16 ) ) {
F_18 ( V_9 , L_47 ) ;
goto V_198;
}
V_188 = V_190 -> V_188 ;
if ( F_71 ( ! V_188 ) ) {
F_18 ( V_9 , L_48 ) ;
V_196 = - V_35 ;
goto V_198;
}
if ( V_186 & ( V_203 | V_204 ) ) {
if ( V_195 <= sizeof( V_192 ) ) {
V_193 = V_192 ;
} else {
V_193 = F_72 ( V_195 , V_205 ) ;
if ( ! V_193 ) {
V_196 = - V_206 ;
goto V_198;
}
}
if ( V_195 > V_194 )
memset ( V_193 + V_194 , 0 , V_195 - V_194 ) ;
}
if ( V_186 & V_203 ) {
if ( F_73 ( V_193 , ( void V_40 * ) V_187 , V_194 ) != 0 ) {
V_196 = - V_42 ;
goto V_198;
}
} else if ( V_186 & V_204 ) {
memset ( V_193 , 0 , V_194 ) ;
}
V_196 = V_188 ( V_14 , V_16 , V_193 ) ;
if ( V_186 & V_204 )
if ( F_74 ( ( void V_40 * ) V_187 , V_193 , V_194 ) != 0 )
V_196 = - V_42 ;
V_198:
if ( ! V_190 )
F_18 ( V_9 , L_49 ,
F_75 ( V_19 ) , V_186 , V_191 ) ;
if ( V_193 != V_192 )
F_45 ( V_193 ) ;
if ( V_196 )
F_18 ( V_9 , L_50 , V_196 ) ;
return V_196 ;
}
static int F_76 ( struct V_13 * V_87 , struct V_207 * V_208 )
{
struct V_15 * V_16 ;
V_16 = F_70 ( V_19 ) ;
if ( F_5 ( V_16 ) )
return F_4 ( V_16 ) ;
if ( ( V_208 -> V_209 & V_85 ) ==
V_85 ) {
V_208 -> V_209 = V_208 -> V_209 ^ V_85 ;
return F_77 ( V_16 , V_208 ) ;
} else if ( ( V_208 -> V_209 & V_210 ) ==
V_210 ) {
V_208 -> V_209 = V_208 -> V_209 ^ V_210 ;
return F_78 ( V_16 , V_208 ) ;
}
return - V_42 ;
}
