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
if ( V_17 == true ) {
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
int V_1 = 0 ;
args -> V_26 = V_27 ;
args -> V_28 = V_29 ;
return V_1 ;
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
V_120 = F_44 ( args -> V_125 -
sizeof( * args ) , V_127 ) ;
if ( V_120 == NULL )
return - V_128 ;
V_111 = F_45 ( V_120 , V_121 ,
args -> V_125 - sizeof( * args ) ) ;
if ( V_111 != 0 ) {
F_24 ( L_34 ) ;
F_46 ( V_120 ) ;
return - V_35 ;
}
V_119 . V_16 = V_23 ;
V_119 . V_129 = * ( ( V_45 * ) ( & V_120 [ V_123 ] ) ) ;
V_123 += sizeof( V_119 . V_129 ) ;
V_119 . V_130 = (enum V_131 * ) & V_120 [ V_123 ] ;
V_123 += sizeof( enum V_131 ) * V_119 . V_129 ;
V_119 . V_132 = ( V_41 * ) & V_120 [ V_123 ] ;
V_123 += sizeof( V_119 . V_132 ) * V_119 . V_129 ;
if ( V_123 >= args -> V_125 - sizeof( * args ) ) {
F_46 ( V_120 ) ;
return - V_35 ;
}
V_122 = ( V_41 ) V_120 [ V_123 ] ;
if ( V_122 > 0 ) {
V_119 . V_133 = ( V_41 * ) & V_120 [ V_123 ] ;
V_123 += sizeof( V_119 . V_133 ) *
V_119 . V_129 ;
} else {
V_119 . V_133 = NULL ;
V_123 += sizeof( V_119 . V_133 ) ;
}
if ( V_123 >= args -> V_125 - sizeof( args ) ) {
F_46 ( V_120 ) ;
return - V_35 ;
}
V_119 . V_134 = NULL ;
F_27 ( F_37 () ) ;
V_111 = F_47 ( V_73 -> V_115 , & V_119 ) ;
F_30 ( F_37 () ) ;
F_46 ( V_120 ) ;
return V_111 ;
}
static int F_48 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_135 * args = V_24 ;
struct V_72 * V_73 ;
struct V_136 V_137 ;
unsigned char * V_120 ;
V_45 V_138 ;
long V_111 ;
void V_40 * V_121 ;
unsigned int V_123 = 0 ;
memset ( ( void * ) & V_137 , 0 , sizeof( struct V_136 ) ) ;
V_138 = sizeof( * args ) +
sizeof( V_137 . V_139 ) +
sizeof( V_137 . V_140 ) +
sizeof( V_137 . V_141 . V_142 ) +
sizeof( V_137 . V_141 . V_143 ) +
sizeof( V_137 . V_144 ) ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
if ( V_73 -> V_112 -> V_113 == V_114 ) {
F_24 ( L_33 ) ;
return - V_35 ;
}
if ( args -> V_125 != V_138 ) {
F_24 ( L_35 ,
args -> V_125 , V_138 ) ;
return - V_35 ;
}
V_121 = ( void V_40 * ) args -> V_124 ;
if ( V_121 == NULL )
return - V_35 ;
V_120 = F_44 ( args -> V_125 - sizeof( * args ) ,
V_127 ) ;
if ( V_120 == NULL )
return - V_128 ;
V_111 = F_45 ( V_120 , V_121 ,
args -> V_125 - sizeof( * args ) ) ;
if ( V_111 != 0 ) {
F_24 ( L_36 ) ;
F_46 ( V_120 ) ;
return - V_35 ;
}
V_137 . V_16 = V_23 ;
V_137 . V_140 = * ( (enum V_145 * ) ( & V_120 [ V_123 ] ) ) ;
V_123 += sizeof( V_137 . V_140 ) ;
V_137 . V_139 = * ( (enum V_146 * ) ( & V_120 [ V_123 ] ) ) ;
V_123 += sizeof( V_137 . V_139 ) ;
V_137 . V_144 = * ( ( V_45 * ) ( & V_120 [ V_123 ] ) ) ;
V_123 += sizeof( V_137 . V_144 ) ;
V_137 . V_141 . V_142 . V_147 . V_148 =
* ( ( V_45 * ) ( & V_120 [ V_123 ] ) ) ;
V_137 . V_141 . V_143 = NULL ;
F_27 ( F_37 () ) ;
F_24 ( L_37 ,
V_137 . V_16 , V_137 . V_140 ,
V_137 . V_139 , V_137 . V_144 ,
V_137 . V_141 . V_142 . V_147 . V_148 ) ;
V_111 = F_49 ( V_73 -> V_115 , & V_137 ) ;
F_24 ( L_38 , V_111 ) ;
F_30 ( F_37 () ) ;
F_46 ( V_120 ) ;
return V_111 ;
}
static int F_50 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_149 * args = V_24 ;
struct V_72 * V_73 ;
struct V_150 time ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
args -> V_151 =
V_73 -> V_152 -> V_153 ( V_73 -> V_154 ) ;
F_51 ( & time ) ;
args -> V_155 = ( V_41 ) F_52 ( & time ) ;
F_53 ( & time ) ;
args -> V_156 = ( V_41 ) F_52 ( & time ) ;
args -> V_157 = 1000000000 ;
return 0 ;
}
static int F_54 ( struct V_13 * V_87 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_158 * args = V_24 ;
struct V_159 * V_160 ;
struct V_75 * V_76 ;
F_18 ( V_9 , L_39 , V_23 -> V_22 ) ;
args -> V_161 = 0 ;
F_27 ( & V_23 -> V_78 ) ;
if ( F_55 ( V_23 ) ) {
V_76 = F_56 ( V_23 ) ;
do {
V_160 =
& args -> V_162 [ args -> V_161 ] ;
V_160 -> V_77 = V_76 -> V_73 -> V_81 ;
V_160 -> V_163 = V_76 -> V_163 ;
V_160 -> V_164 = V_76 -> V_164 ;
V_160 -> V_165 = V_76 -> V_165 ;
V_160 -> V_166 = V_76 -> V_166 ;
V_160 -> V_167 = V_76 -> V_167 ;
V_160 -> V_168 = V_76 -> V_168 ;
F_18 ( V_9 ,
L_40 , args -> V_161 ) ;
F_18 ( V_9 ,
L_41 , V_76 -> V_73 -> V_81 ) ;
F_18 ( V_9 ,
L_42 , V_76 -> V_163 ) ;
F_18 ( V_9 ,
L_43 , V_76 -> V_164 ) ;
F_18 ( V_9 ,
L_44 , V_76 -> V_165 ) ;
F_18 ( V_9 ,
L_45 , V_76 -> V_166 ) ;
F_18 ( V_9 ,
L_46 , V_76 -> V_167 ) ;
F_18 ( V_9 ,
L_47 , V_76 -> V_168 ) ;
args -> V_161 ++ ;
} while ( ( V_76 = F_57 ( V_23 , V_76 ) ) != NULL &&
( args -> V_161 < V_169 ) );
}
F_30 ( & V_23 -> V_78 ) ;
return 0 ;
}
static int F_58 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_170 * args = V_24 ;
int V_1 ;
V_1 = F_59 ( V_87 , V_23 , args -> V_171 ,
args -> V_172 != 0 , args -> V_173 ,
& args -> V_174 , & args -> V_175 ,
& args -> V_176 ,
& args -> V_177 ) ;
return V_1 ;
}
static int F_60 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_178 * args = V_24 ;
return F_61 ( V_23 , args -> V_174 ) ;
}
static int F_62 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_179 * args = V_24 ;
return F_63 ( V_23 , args -> V_174 ) ;
}
static int F_64 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_180 * args = V_24 ;
return F_65 ( V_23 , args -> V_174 ) ;
}
static int F_66 ( struct V_13 * V_87 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_181 * args = V_24 ;
enum V_182 V_183 ;
int V_1 ;
V_1 = F_67 ( V_23 , args -> V_184 ,
( void V_40 * ) args -> V_185 ,
( args -> V_186 != 0 ) ,
args -> V_187 , & V_183 ) ;
args -> V_183 = V_183 ;
return V_1 ;
}
static long F_68 ( struct V_13 * V_14 , unsigned int V_188 , unsigned long V_189 )
{
struct V_15 * V_16 ;
T_1 * V_190 ;
const struct V_191 * V_192 = NULL ;
unsigned int V_193 = F_69 ( V_188 ) ;
char V_194 [ 128 ] ;
char * V_195 = NULL ;
unsigned int V_196 , V_197 ;
int V_198 = - V_35 ;
if ( V_193 >= V_199 )
goto V_200;
if ( ( V_193 >= V_201 ) && ( V_193 < V_202 ) ) {
T_2 V_203 ;
V_192 = & V_204 [ V_193 ] ;
V_203 = F_70 ( V_192 -> V_188 ) ;
V_196 = V_197 = F_70 ( V_188 ) ;
if ( V_203 > V_197 )
V_197 = V_203 ;
V_188 = V_192 -> V_188 ;
} else
goto V_200;
F_18 ( V_9 , L_48 , V_188 , V_193 , V_189 ) ;
V_16 = F_71 ( V_19 ) ;
if ( F_5 ( V_16 ) ) {
F_18 ( V_9 , L_49 ) ;
goto V_200;
}
V_190 = V_192 -> V_190 ;
if ( F_72 ( ! V_190 ) ) {
F_18 ( V_9 , L_50 ) ;
V_198 = - V_35 ;
goto V_200;
}
if ( V_188 & ( V_205 | V_206 ) ) {
if ( V_197 <= sizeof( V_194 ) ) {
V_195 = V_194 ;
} else {
V_195 = F_44 ( V_197 , V_127 ) ;
if ( ! V_195 ) {
V_198 = - V_128 ;
goto V_200;
}
}
if ( V_197 > V_196 )
memset ( V_195 + V_196 , 0 , V_197 - V_196 ) ;
}
if ( V_188 & V_205 ) {
if ( F_45 ( V_195 , ( void V_40 * ) V_189 , V_196 ) != 0 ) {
V_198 = - V_42 ;
goto V_200;
}
} else if ( V_188 & V_206 ) {
memset ( V_195 , 0 , V_196 ) ;
}
V_198 = V_190 ( V_14 , V_16 , V_195 ) ;
if ( V_188 & V_206 )
if ( F_73 ( ( void V_40 * ) V_189 , V_195 , V_196 ) != 0 )
V_198 = - V_42 ;
V_200:
if ( ! V_192 )
F_18 ( V_9 , L_51 ,
F_74 ( V_19 ) , V_188 , V_193 ) ;
if ( V_195 != V_194 )
F_46 ( V_195 ) ;
if ( V_198 )
F_18 ( V_9 , L_52 , V_198 ) ;
return V_198 ;
}
static int F_75 ( struct V_13 * V_87 , struct V_207 * V_208 )
{
struct V_15 * V_16 ;
V_16 = F_71 ( V_19 ) ;
if ( F_5 ( V_16 ) )
return F_4 ( V_16 ) ;
if ( ( V_208 -> V_209 & V_85 ) ==
V_85 ) {
V_208 -> V_209 = V_208 -> V_209 ^ V_85 ;
return F_76 ( V_16 , V_208 ) ;
} else if ( ( V_208 -> V_209 & V_210 ) ==
V_210 ) {
V_208 -> V_209 = V_208 -> V_209 ^ V_210 ;
return F_77 ( V_16 , V_208 ) ;
}
return - V_42 ;
}
