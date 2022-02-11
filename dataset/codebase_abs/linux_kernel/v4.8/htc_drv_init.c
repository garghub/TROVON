static void F_1 ( struct V_1 * V_2 )
{
F_2 ( (struct V_3 * ) V_2 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( (struct V_3 * ) V_2 -> V_4 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
if ( F_6 ( & V_4 -> V_6 -> V_7 ) > 0 ) {
F_7 ( & V_4 -> V_6 -> V_7 ) ;
return 0 ;
}
V_5 = F_8 ( & V_4 -> V_6 -> V_8 , V_9 ) ;
if ( ! V_5 ) {
F_9 ( V_4 -> V_10 , L_1 ) ;
return - V_11 ;
}
F_7 ( & V_4 -> V_6 -> V_7 ) ;
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_11 ( V_4 -> V_12 ) ;
F_12 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
F_14 ( V_14 -> V_15 ) ;
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
F_17 ( V_14 ) ;
F_18 ( V_4 ) ;
F_19 ( V_4 ) ;
F_10 ( V_4 ) ;
}
static inline int F_20 ( struct V_3 * V_4 ,
T_1 V_16 ,
void (* F_21) ( void * ,
struct V_17 * ,
enum V_18 ,
bool V_19 ) ,
enum V_18 * V_20 )
{
struct V_21 V_22 ;
memset ( & V_22 , 0 , sizeof( struct V_21 ) ) ;
V_22 . V_16 = V_16 ;
V_22 . V_23 . V_4 = V_4 ;
V_22 . V_23 . V_24 = V_25 ;
V_22 . V_23 . F_21 = F_21 ;
return F_22 ( V_4 -> V_6 , & V_22 , V_20 ) ;
}
static int F_23 ( struct V_3 * V_4 , T_1 V_26 ,
T_2 V_27 )
{
int V_28 ;
V_28 = F_24 ( V_4 -> V_6 , V_4 -> V_29 , & V_4 -> V_30 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_32 , V_33 ,
& V_4 -> V_34 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_35 , V_36 ,
& V_4 -> V_37 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_38 , V_36 ,
& V_4 -> V_39 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_40 , V_36 ,
& V_4 -> V_41 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_42 , V_36 ,
& V_4 -> V_43 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_44 , V_36 ,
& V_4 -> V_45 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_46 , V_36 ,
& V_4 -> V_47 ) ;
if ( V_28 )
goto V_31;
V_28 = F_20 ( V_4 , V_48 , V_36 ,
& V_4 -> V_49 ) ;
if ( V_28 )
goto V_31;
if ( F_25 ( V_27 ) )
V_4 -> V_6 -> V_50 = 45 ;
else
V_4 -> V_6 -> V_50 = 33 ;
V_28 = F_26 ( V_4 -> V_6 ) ;
if ( V_28 )
goto V_31;
F_27 ( V_4 -> V_10 , L_2 ,
V_4 -> V_6 -> V_50 ) ;
return 0 ;
V_31:
F_9 ( V_4 -> V_10 , L_3 ) ;
return V_28 ;
}
static void F_28 ( struct V_15 * V_15 ,
struct V_51 * V_52 )
{
struct V_13 * V_14 = F_29 ( V_15 ) ;
struct V_3 * V_4 = V_14 -> V_4 ;
F_30 ( V_15 , V_52 ,
F_31 ( V_4 -> V_12 ) ) ;
}
static unsigned int F_32 ( void * V_53 , T_2 V_54 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
T_3 V_56 , V_57 = F_34 ( V_54 ) ;
int V_58 ;
V_58 = F_35 ( V_4 -> V_29 , V_59 ,
( V_60 * ) & V_57 , sizeof( V_57 ) ,
( V_60 * ) & V_56 , sizeof( V_56 ) ,
100 ) ;
if ( F_36 ( V_58 ) ) {
F_37 ( V_2 , V_61 , L_4 ,
V_54 , V_58 ) ;
return - V_62 ;
}
return F_38 ( V_56 ) ;
}
static void F_39 ( void * V_53 , T_2 * V_63 ,
T_2 * V_56 , T_1 V_64 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
T_3 V_65 [ 8 ] ;
T_3 V_66 [ 8 ] ;
int V_67 , V_28 ;
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ ) {
V_65 [ V_67 ] = F_34 ( V_63 [ V_67 ] ) ;
}
V_28 = F_35 ( V_4 -> V_29 , V_59 ,
( V_60 * ) V_65 , sizeof( T_2 ) * V_64 ,
( V_60 * ) V_66 , sizeof( T_2 ) * V_64 ,
100 ) ;
if ( F_36 ( V_28 ) ) {
F_37 ( V_2 , V_61 ,
L_5 , V_64 ) ;
}
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ ) {
V_56 [ V_67 ] = F_38 ( V_66 [ V_67 ] ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
T_2 V_68 ;
int V_58 ;
V_58 = F_35 ( V_4 -> V_29 , V_69 ,
( V_60 * ) & V_4 -> V_29 -> V_70 ,
sizeof( struct V_71 ) * V_4 -> V_29 -> V_72 ,
( V_60 * ) & V_68 , sizeof( V_68 ) ,
100 ) ;
if ( F_36 ( V_58 ) ) {
F_37 ( V_2 , V_61 ,
L_6 ,
V_4 -> V_29 -> V_72 ) ;
}
V_4 -> V_29 -> V_72 = 0 ;
}
static void F_41 ( void * V_53 , T_2 V_56 , T_2 V_54 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
const T_3 V_73 [ 2 ] = {
F_34 ( V_54 ) ,
F_34 ( V_56 ) ,
} ;
int V_58 ;
V_58 = F_35 ( V_4 -> V_29 , V_69 ,
( V_60 * ) & V_73 , sizeof( V_73 ) ,
( V_60 * ) & V_56 , sizeof( V_56 ) ,
100 ) ;
if ( F_36 ( V_58 ) ) {
F_37 ( V_2 , V_61 , L_7 ,
V_54 , V_58 ) ;
}
}
static void F_42 ( void * V_53 , T_2 V_56 , T_2 V_54 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
F_43 ( & V_4 -> V_29 -> V_74 ) ;
V_4 -> V_29 -> V_70 [ V_4 -> V_29 -> V_72 ] . V_57 =
F_34 ( V_54 ) ;
V_4 -> V_29 -> V_70 [ V_4 -> V_29 -> V_72 ] . V_56 =
F_34 ( V_56 ) ;
V_4 -> V_29 -> V_72 ++ ;
if ( V_4 -> V_29 -> V_72 == V_75 )
F_40 ( V_2 ) ;
F_44 ( & V_4 -> V_29 -> V_74 ) ;
}
static void F_45 ( void * V_53 , T_2 V_56 , T_2 V_54 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
if ( F_6 ( & V_4 -> V_29 -> V_76 ) )
F_42 ( V_53 , V_56 , V_54 ) ;
else
F_41 ( V_53 , V_56 , V_54 ) ;
}
static void F_46 ( void * V_53 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
F_47 ( & V_4 -> V_29 -> V_76 ) ;
}
static void F_48 ( void * V_53 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
F_7 ( & V_4 -> V_29 -> V_76 ) ;
F_43 ( & V_4 -> V_29 -> V_74 ) ;
if ( V_4 -> V_29 -> V_72 )
F_40 ( V_2 ) ;
F_44 ( & V_4 -> V_29 -> V_74 ) ;
}
static void F_49 ( void * V_53 ,
T_2 V_54 , T_2 V_77 , T_2 V_78 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
T_2 V_68 ;
int V_58 ;
F_43 ( & V_4 -> V_29 -> V_79 ) ;
V_4 -> V_29 -> V_80 [ V_4 -> V_29 -> V_81 ] . V_57 =
F_34 ( V_54 ) ;
V_4 -> V_29 -> V_80 [ V_4 -> V_29 -> V_81 ] . V_77 =
F_34 ( V_77 ) ;
V_4 -> V_29 -> V_80 [ V_4 -> V_29 -> V_81 ] . V_78 =
F_34 ( V_78 ) ;
V_4 -> V_29 -> V_81 ++ ;
if ( V_4 -> V_29 -> V_81 == V_82 ) {
V_58 = F_35 ( V_4 -> V_29 , V_83 ,
( V_60 * ) & V_4 -> V_29 -> V_80 ,
sizeof( struct V_71 ) * V_4 -> V_29 -> V_81 ,
( V_60 * ) & V_68 , sizeof( V_68 ) ,
100 ) ;
if ( F_36 ( V_58 ) ) {
F_37 ( V_2 , V_61 ,
L_8 ,
V_4 -> V_29 -> V_81 ) ;
}
V_4 -> V_29 -> V_81 = 0 ;
}
F_44 ( & V_4 -> V_29 -> V_79 ) ;
}
static void F_50 ( void * V_53 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
T_2 V_68 ;
int V_58 ;
if ( F_51 ( V_84 , & V_4 -> V_85 ) )
return;
F_7 ( & V_4 -> V_29 -> V_86 ) ;
F_43 ( & V_4 -> V_29 -> V_79 ) ;
if ( V_4 -> V_29 -> V_81 ) {
V_58 = F_35 ( V_4 -> V_29 , V_83 ,
( V_60 * ) & V_4 -> V_29 -> V_80 ,
sizeof( struct V_87 ) * V_4 -> V_29 -> V_81 ,
( V_60 * ) & V_68 , sizeof( V_68 ) ,
100 ) ;
if ( F_36 ( V_58 ) ) {
F_37 ( V_2 , V_61 ,
L_8 ,
V_4 -> V_29 -> V_81 ) ;
}
V_4 -> V_29 -> V_81 = 0 ;
}
F_44 ( & V_4 -> V_29 -> V_79 ) ;
}
static void F_52 ( void * V_53 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
if ( F_51 ( V_84 , & V_4 -> V_85 ) )
return;
F_47 ( & V_4 -> V_29 -> V_86 ) ;
}
static T_2 F_53 ( void * V_53 ,
T_2 V_54 , T_2 V_77 , T_2 V_78 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_87 V_73 , V_88 ;
int V_28 ;
T_2 V_56 = 0 ;
V_73 . V_57 = F_34 ( V_54 ) ;
V_73 . V_77 = F_34 ( V_77 ) ;
V_73 . V_78 = F_34 ( V_78 ) ;
V_28 = F_35 ( V_4 -> V_29 , V_83 ,
( V_60 * ) & V_73 , sizeof( V_73 ) ,
( V_60 * ) & V_88 , sizeof( V_88 ) ,
100 ) ;
if ( F_36 ( V_28 ) ) {
F_37 ( V_2 , V_61 , L_9 ,
V_54 , V_28 ) ;
}
return V_56 ;
}
static T_2 F_54 ( void * V_53 , T_2 V_54 , T_2 V_77 , T_2 V_78 )
{
struct V_55 * V_12 = (struct V_55 * ) V_53 ;
struct V_1 * V_2 = F_33 ( V_12 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
if ( F_51 ( V_84 , & V_4 -> V_85 ) ) {
T_2 V_56 ;
V_56 = F_55 ( V_12 , V_54 ) ;
V_56 &= ~ V_78 ;
V_56 |= V_77 ;
F_56 ( V_12 , V_54 , V_56 ) ;
return 0 ;
}
if ( F_6 ( & V_4 -> V_29 -> V_86 ) )
F_49 ( V_53 , V_54 , V_77 , V_78 ) ;
else
F_53 ( V_53 , V_54 , V_77 , V_78 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , int * V_89 )
{
* V_89 = V_90 >> 2 ;
}
static bool F_58 ( struct V_1 * V_2 , T_2 V_91 , T_1 * V_92 )
{
struct V_55 * V_12 = (struct V_55 * ) V_2 -> V_12 ;
( void ) F_55 ( V_12 , V_93 + ( V_91 << V_94 ) ) ;
if ( ! F_59 ( V_12 ,
V_95 ,
V_96 |
V_97 , 0 ,
V_98 ) )
return false ;
* V_92 = F_60 ( F_55 ( V_12 , V_95 ) ,
V_99 ) ;
return true ;
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 -> V_12 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < F_62 ( V_4 -> V_100 ) ; V_67 ++ )
V_4 -> V_100 [ V_67 ] = - 1 ;
V_4 -> V_101 . V_102 = F_63 ( V_4 -> V_12 ) ;
if ( V_4 -> V_101 . V_102 == - 1 ) {
F_64 ( V_2 , L_10 ) ;
goto V_31;
}
V_4 -> V_103 = F_65 ( V_4 ) ;
if ( V_4 -> V_103 == - 1 ) {
F_64 ( V_2 , L_11 ) ;
goto V_31;
}
if ( ! F_66 ( V_4 , V_104 ) ) {
F_64 ( V_2 , L_12 ) ;
goto V_31;
}
if ( ! F_66 ( V_4 , V_105 ) ) {
F_64 ( V_2 , L_13 ) ;
goto V_31;
}
if ( ! F_66 ( V_4 , V_106 ) ) {
F_64 ( V_2 , L_14 ) ;
goto V_31;
}
if ( ! F_66 ( V_4 , V_107 ) ) {
F_64 ( V_2 , L_15 ) ;
goto V_31;
}
return 0 ;
V_31:
return - V_108 ;
}
static void F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 -> V_12 ) ;
memcpy ( V_2 -> V_109 , V_110 , V_111 ) ;
V_2 -> V_112 = V_113 ;
V_4 -> V_12 -> V_114 = V_115 ;
V_4 -> V_116 . V_12 = V_4 -> V_12 ;
V_4 -> V_116 . V_117 . V_118 = 0 ;
V_4 -> V_116 . V_117 . V_119 = true ;
V_4 -> V_116 . V_117 . V_64 = 8 ;
V_4 -> V_116 . V_117 . V_120 = false ;
V_4 -> V_116 . V_117 . V_121 = 0x12 ;
V_4 -> V_116 . V_117 . V_122 = 0x02 ;
}
static int F_68 ( struct V_3 * V_4 ,
T_1 V_26 , char * V_123 ,
T_2 V_27 )
{
struct V_55 * V_12 = NULL ;
struct V_1 * V_2 ;
int V_67 , V_28 = 0 , V_89 = 0 ;
V_12 = F_69 ( sizeof( struct V_55 ) , V_124 ) ;
if ( ! V_12 )
return - V_125 ;
V_12 -> V_10 = V_4 -> V_10 ;
V_12 -> V_14 = V_4 -> V_14 ;
V_12 -> V_126 . V_26 = V_26 ;
V_12 -> V_126 . V_127 = V_27 ;
V_12 -> V_128 |= V_129 ;
V_12 -> V_130 . V_131 = F_32 ;
V_12 -> V_130 . V_132 = F_39 ;
V_12 -> V_130 . V_133 = F_45 ;
V_12 -> V_130 . V_134 = F_46 ;
V_12 -> V_130 . V_135 = F_48 ;
V_12 -> V_130 . V_136 = F_52 ;
V_12 -> V_130 . V_137 = F_50 ;
V_12 -> V_130 . V_138 = F_54 ;
V_4 -> V_12 = V_12 ;
V_2 = F_33 ( V_12 ) ;
V_2 -> V_139 = & V_12 -> V_130 ;
V_2 -> V_140 = & V_141 ;
V_2 -> V_142 = & V_143 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_14 = V_4 -> V_14 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_144 = V_145 ;
V_2 -> V_146 = V_147 == 1 ;
F_70 ( V_148 , & V_2 -> V_149 ) ;
F_71 ( & V_4 -> V_150 ) ;
F_71 ( & V_4 -> F_21 . V_151 ) ;
F_72 ( & V_4 -> V_152 ) ;
F_72 ( & V_4 -> V_153 ) ;
F_73 ( & V_4 -> V_154 , V_155 ,
( unsigned long ) V_4 ) ;
F_73 ( & V_4 -> V_156 , V_157 ,
( unsigned long ) V_4 ) ;
F_74 ( & V_4 -> V_158 , V_159 ) ;
F_75 ( & V_4 -> V_160 , V_161 ) ;
F_75 ( & V_4 -> V_162 , V_163 ) ;
F_76 ( & V_4 -> F_21 . V_164 , V_165 ,
( unsigned long ) V_4 ) ;
F_77 ( V_2 , & V_89 ) ;
V_2 -> V_166 = V_89 << 2 ;
V_28 = F_78 ( V_12 ) ;
if ( V_28 ) {
F_64 ( V_2 ,
L_16 ,
V_28 ) ;
goto V_167;
}
V_28 = F_61 ( V_4 ) ;
if ( V_28 )
goto V_168;
for ( V_67 = 0 ; V_67 < V_169 ; V_67 ++ )
V_4 -> V_101 . V_170 [ V_67 ] = NULL ;
V_4 -> V_101 . V_171 = 9 ;
F_79 ( V_2 ) ;
F_80 ( V_12 ) ;
F_67 ( V_4 ) ;
F_81 ( V_4 , V_123 ) ;
return 0 ;
V_168:
F_11 ( V_12 ) ;
V_167:
F_12 ( V_12 ) ;
V_4 -> V_12 = NULL ;
return V_28 ;
}
static void F_82 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_55 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = F_33 ( V_4 -> V_12 ) ;
struct V_172 * V_173 ;
F_83 ( V_14 , V_174 ) ;
F_83 ( V_14 , V_175 ) ;
F_83 ( V_14 , V_176 ) ;
F_83 ( V_14 , V_177 ) ;
F_83 ( V_14 , V_178 ) ;
F_83 ( V_14 , V_179 ) ;
F_83 ( V_14 , V_180 ) ;
F_83 ( V_14 , V_181 ) ;
F_83 ( V_14 , V_182 ) ;
if ( V_183 )
F_83 ( V_14 , V_184 ) ;
V_14 -> V_15 -> V_185 =
F_84 ( V_115 ) |
F_84 ( V_186 ) |
F_84 ( V_187 ) |
F_84 ( V_188 ) |
F_84 ( V_189 ) |
F_84 ( V_190 ) |
F_84 ( V_191 ) ;
V_14 -> V_15 -> V_192 = & V_193 ;
V_14 -> V_15 -> V_194 = 1 ;
V_14 -> V_15 -> V_195 &= ~ V_196 ;
V_14 -> V_15 -> V_195 |= V_197 |
V_198 |
V_199 ;
V_14 -> V_15 -> V_195 |= V_200 ;
V_14 -> V_201 = 4 ;
V_14 -> V_202 = 1 ;
V_14 -> V_203 = sizeof( struct V_204 ) ;
V_14 -> V_205 = sizeof( struct V_206 ) ;
V_14 -> V_207 = sizeof( struct V_208 ) +
sizeof( struct V_209 ) + 4 ;
if ( V_4 -> V_12 -> V_210 . V_211 & V_212 )
V_14 -> V_15 -> V_213 [ V_214 ] =
& V_2 -> V_215 [ V_214 ] ;
if ( V_4 -> V_12 -> V_210 . V_211 & V_216 )
V_14 -> V_15 -> V_213 [ V_217 ] =
& V_2 -> V_215 [ V_217 ] ;
F_85 ( V_12 ) ;
V_173 = F_86 ( V_4 ) ;
if ( V_173 ) {
V_14 -> V_15 -> V_218 = V_173 -> V_219 ;
V_14 -> V_15 -> V_220 = V_173 -> V_221 ;
}
F_87 ( V_14 , V_2 -> V_222 ) ;
}
static int F_88 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
struct V_223 V_224 ;
int V_28 ;
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
F_89 ( V_225 ) ;
if ( V_28 )
return - V_108 ;
V_4 -> V_226 = F_90 ( V_224 . V_227 ) ;
V_4 -> V_228 = F_90 ( V_224 . V_229 ) ;
snprintf ( V_14 -> V_15 -> V_230 , sizeof( V_14 -> V_15 -> V_230 ) , L_17 ,
V_4 -> V_226 ,
V_4 -> V_228 ) ;
F_27 ( V_4 -> V_10 , L_18 ,
V_4 -> V_226 ,
V_4 -> V_228 ) ;
if ( V_4 -> V_226 != V_231 ||
V_4 -> V_228 < V_232 ) {
F_9 ( V_4 -> V_10 , L_19 ,
V_231 , V_232 ) ;
return - V_108 ;
}
if ( V_4 -> V_226 == 1 && V_4 -> V_228 < 4 )
F_70 ( V_84 , & V_4 -> V_85 ) ;
F_27 ( V_4 -> V_10 , L_20 ,
F_51 ( V_84 , & V_4 -> V_85 ) ? L_21 : L_22 ) ;
return 0 ;
}
static int F_91 ( struct V_3 * V_4 ,
T_1 V_26 , char * V_123 , T_2 V_27 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
struct V_1 * V_2 ;
struct V_55 * V_12 ;
int error = 0 ;
struct V_233 * V_57 ;
char V_234 [ 64 ] ;
error = F_68 ( V_4 , V_26 , V_123 , V_27 ) ;
if ( error != 0 )
goto V_235;
V_12 = V_4 -> V_12 ;
V_2 = F_33 ( V_12 ) ;
F_82 ( V_4 , V_14 ) ;
error = F_88 ( V_4 ) ;
if ( error != 0 )
goto V_236;
error = F_92 ( & V_2 -> V_237 , V_4 -> V_14 -> V_15 ,
F_28 ) ;
if ( error )
goto V_238;
V_57 = & V_2 -> V_237 ;
error = F_93 ( V_4 ) ;
if ( error != 0 )
goto V_239;
error = F_94 ( V_4 ) ;
if ( error != 0 )
goto V_240;
F_95 ( V_4 -> V_12 ) ;
#ifdef F_96
V_4 -> V_241 . V_242 = F_97 ( V_4 -> V_14 ,
V_243 , V_244 ,
F_62 ( V_244 ) ) ;
#endif
error = F_98 ( V_14 ) ;
if ( error )
goto V_245;
if ( ! F_99 ( V_57 ) ) {
error = F_100 ( V_14 -> V_15 , V_57 -> V_246 ) ;
if ( error )
goto V_247;
}
error = F_101 ( V_4 -> V_12 ) ;
if ( error ) {
F_64 ( V_2 , L_23 ) ;
goto V_247;
}
F_37 ( V_2 , V_248 ,
L_24 ,
V_4 -> V_30 ,
V_4 -> V_34 ,
V_4 -> V_37 ,
V_4 -> V_39 ,
V_4 -> V_41 ,
V_4 -> V_43 ,
V_4 -> V_45 ,
V_4 -> V_47 ,
V_4 -> V_49 ) ;
F_102 ( V_4 -> V_12 , V_234 , sizeof( V_234 ) ) ;
F_103 ( V_14 -> V_15 , L_25 , V_234 ) ;
F_104 ( V_4 ) ;
F_105 ( V_4 ) ;
return 0 ;
V_247:
F_17 ( V_14 ) ;
V_245:
F_18 ( V_4 ) ;
V_240:
F_19 ( V_4 ) ;
V_239:
V_238:
V_236:
F_10 ( V_4 ) ;
V_235:
return error ;
}
int F_106 ( struct V_249 * V_250 , struct V_251 * V_10 ,
T_1 V_26 , char * V_123 , T_2 V_27 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_28 ;
V_14 = F_107 ( sizeof( struct V_3 ) , & V_252 ) ;
if ( ! V_14 )
return - V_125 ;
V_4 = V_14 -> V_4 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_6 = V_250 ;
V_4 -> V_10 = V_10 ;
V_250 -> V_253 = V_4 ;
F_108 ( V_14 , V_4 -> V_10 ) ;
V_28 = F_5 ( V_4 ) ;
if ( V_28 )
goto V_254;
V_4 -> V_29 = F_109 ( V_4 ) ;
if ( ! V_4 -> V_29 ) {
V_28 = - V_108 ;
goto V_254;
}
V_28 = F_23 ( V_4 , V_26 , V_27 ) ;
if ( V_28 )
goto V_235;
V_28 = F_91 ( V_4 , V_26 , V_123 , V_27 ) ;
if ( V_28 )
goto V_235;
return 0 ;
V_235:
F_110 ( V_4 ) ;
V_254:
F_111 ( V_14 ) ;
return V_28 ;
}
void F_112 ( struct V_249 * V_250 , bool V_255 )
{
if ( V_250 -> V_253 ) {
if ( V_255 )
V_250 -> V_253 -> V_12 -> V_128 |= V_256 ;
F_13 ( V_250 -> V_253 ) ;
F_110 ( V_250 -> V_253 ) ;
F_111 ( V_250 -> V_253 -> V_14 ) ;
}
}
void F_113 ( struct V_249 * V_250 )
{
F_114 ( V_250 -> V_253 , V_257 ) ;
}
int F_115 ( struct V_249 * V_250 )
{
struct V_3 * V_4 = V_250 -> V_253 ;
int V_28 ;
V_28 = F_5 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_23 ( V_4 , V_4 -> V_12 -> V_126 . V_26 ,
V_4 -> V_12 -> V_126 . V_127 ) ;
F_116 ( V_4 ) ;
return V_28 ;
}
static int T_4 F_117 ( void )
{
if ( F_118 () < 0 ) {
F_119 ( L_26 ) ;
return - V_258 ;
}
return 0 ;
}
static void T_5 F_120 ( void )
{
F_121 () ;
F_122 ( L_27 ) ;
}
