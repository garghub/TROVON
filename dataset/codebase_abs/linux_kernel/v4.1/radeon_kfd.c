bool F_1 ( void )
{
#if F_2 ( V_1 )
bool (* F_3)( unsigned , const struct V_2 * * );
F_3 = F_4 ( V_3 ) ;
if ( F_3 == NULL )
return false ;
if ( ! F_3 ( V_4 , & V_5 ) ) {
F_5 ( V_3 ) ;
V_5 = NULL ;
return false ;
}
return true ;
#elif F_2 ( V_6 )
if ( ! V_3 ( V_4 , & V_5 ) ) {
V_5 = NULL ;
return false ;
}
return true ;
#else
return false ;
#endif
}
void F_6 ( void )
{
if ( V_5 ) {
V_5 -> exit () ;
F_5 ( V_3 ) ;
}
}
void F_7 ( struct V_7 * V_8 )
{
if ( V_5 )
V_8 -> V_9 = V_5 -> V_10 ( (struct V_11 * ) V_8 ,
V_8 -> V_12 , & V_13 ) ;
}
void F_8 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 ) {
struct V_14 V_15 = {
. V_16 = 0xFF00 ,
. V_17 = 1 ,
. V_18 = 4 - 1 ,
} ;
F_9 ( V_8 ,
& V_15 . V_19 ,
& V_15 . V_20 ,
& V_15 . V_21 ) ;
V_5 -> V_22 ( V_8 -> V_9 , & V_15 ) ;
}
}
void F_10 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 ) {
V_5 -> V_23 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
}
}
void F_11 ( struct V_7 * V_8 , const void * V_24 )
{
if ( V_8 -> V_9 )
V_5 -> V_25 ( V_8 -> V_9 , V_24 ) ;
}
void F_12 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 )
V_5 -> V_26 ( V_8 -> V_9 ) ;
}
int F_13 ( struct V_7 * V_8 )
{
int V_27 = 0 ;
if ( V_8 -> V_9 )
V_27 = V_5 -> V_28 ( V_8 -> V_9 ) ;
return V_27 ;
}
static int F_14 ( struct V_11 * V_29 , T_1 V_30 ,
void * * V_31 , T_2 * V_32 ,
void * * V_33 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
struct V_34 * * V_35 = (struct V_34 * * ) V_31 ;
int V_27 ;
F_15 ( V_29 == NULL ) ;
F_15 ( V_32 == NULL ) ;
F_15 ( V_33 == NULL ) ;
* V_35 = F_16 ( sizeof( struct V_34 ) , V_36 ) ;
if ( ( * V_35 ) == NULL )
return - V_37 ;
V_27 = F_17 ( V_8 , V_30 , V_38 , true , V_39 ,
V_40 , NULL , NULL , & ( * V_35 ) -> V_41 ) ;
if ( V_27 ) {
F_18 ( V_8 -> V_42 ,
L_1 , V_27 ) ;
return V_27 ;
}
V_27 = F_19 ( ( * V_35 ) -> V_41 , true ) ;
if ( V_27 ) {
F_18 ( V_8 -> V_42 , L_2 , V_27 ) ;
goto V_43;
}
V_27 = F_20 ( ( * V_35 ) -> V_41 , V_39 ,
& ( * V_35 ) -> V_32 ) ;
if ( V_27 ) {
F_18 ( V_8 -> V_42 , L_3 , V_27 ) ;
goto V_44;
}
* V_32 = ( * V_35 ) -> V_32 ;
V_27 = F_21 ( ( * V_35 ) -> V_41 , & ( * V_35 ) -> V_33 ) ;
if ( V_27 ) {
F_18 ( V_8 -> V_42 ,
L_4 , V_27 ) ;
goto V_45;
}
* V_33 = ( * V_35 ) -> V_33 ;
F_22 ( ( * V_35 ) -> V_41 ) ;
return 0 ;
V_45:
F_23 ( ( * V_35 ) -> V_41 ) ;
V_44:
F_22 ( ( * V_35 ) -> V_41 ) ;
V_43:
F_24 ( & ( * V_35 ) -> V_41 ) ;
return V_27 ;
}
static void F_25 ( struct V_11 * V_29 , void * V_31 )
{
struct V_34 * V_35 = (struct V_34 * ) V_31 ;
F_15 ( V_35 == NULL ) ;
F_19 ( V_35 -> V_41 , true ) ;
F_26 ( V_35 -> V_41 ) ;
F_23 ( V_35 -> V_41 ) ;
F_22 ( V_35 -> V_41 ) ;
F_24 ( & ( V_35 -> V_41 ) ) ;
F_27 ( V_35 ) ;
}
static T_2 F_28 ( struct V_11 * V_29 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
F_15 ( V_29 == NULL ) ;
return V_8 -> V_46 . V_47 ;
}
static T_2 F_29 ( struct V_11 * V_29 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
return V_8 -> V_48 -> F_29 ( V_8 ) ;
}
static T_3 F_30 ( struct V_11 * V_29 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
return V_8 -> V_49 . V_50 . V_51 . V_52 . V_53 / 100 ;
}
static inline struct V_7 * F_31 ( struct V_11 * V_29 )
{
return (struct V_7 * ) V_29 ;
}
static void F_32 ( struct V_11 * V_29 , T_3 V_54 , T_3 V_55 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
F_33 ( V_55 , ( void V_56 * ) ( V_8 -> V_57 + V_54 ) ) ;
}
static T_3 F_34 ( struct V_11 * V_29 , T_3 V_54 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
return F_35 ( ( void V_56 * ) ( V_8 -> V_57 + V_54 ) ) ;
}
static void F_36 ( struct V_11 * V_29 , T_3 V_58 , T_3 V_59 ,
T_3 V_60 , T_3 V_61 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
T_3 V_55 = F_37 ( V_59 ) | F_38 ( V_58 ) | F_39 ( V_61 ) | F_40 ( V_60 ) ;
F_41 ( & V_8 -> V_62 ) ;
F_32 ( V_29 , V_63 , V_55 ) ;
}
static void F_42 ( struct V_11 * V_29 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
F_32 ( V_29 , V_63 , 0 ) ;
F_43 ( & V_8 -> V_62 ) ;
}
static void F_44 ( struct V_11 * V_29 , T_3 V_64 ,
T_3 V_65 )
{
T_3 V_58 = ( ++ V_64 / V_66 ) + 1 ;
T_3 V_59 = ( V_64 % V_66 ) ;
F_36 ( V_29 , V_58 , V_59 , V_65 , 0 ) ;
}
static void F_45 ( struct V_11 * V_29 )
{
F_42 ( V_29 ) ;
}
static void F_46 ( struct V_11 * V_29 , T_3 V_61 ,
T_3 V_67 ,
T_3 V_68 ,
T_3 V_69 ,
T_3 V_70 )
{
F_36 ( V_29 , 0 , 0 , 0 , V_61 ) ;
F_32 ( V_29 , V_71 , V_67 ) ;
F_32 ( V_29 , V_72 , V_68 ) ;
F_32 ( V_29 , V_73 , V_69 ) ;
F_32 ( V_29 , V_74 , V_70 ) ;
F_42 ( V_29 ) ;
}
static int F_47 ( struct V_11 * V_29 , unsigned int V_75 ,
unsigned int V_61 )
{
T_3 V_76 = ( V_75 == 0 ) ? 0 :
( T_3 ) V_75 | V_77 ;
F_32 ( V_29 , V_78 + V_61 * sizeof( T_3 ) ,
V_76 ) ;
while ( ! ( F_34 ( V_29 , V_79 ) &
( 1U << V_61 ) ) )
F_48 () ;
F_32 ( V_29 , V_79 , 1U << V_61 ) ;
F_32 ( V_29 , V_80 + V_61 * sizeof( T_3 ) ,
V_76 ) ;
return 0 ;
}
static int F_49 ( struct V_11 * V_29 , T_3 V_64 ,
T_3 V_81 , T_2 V_82 )
{
T_3 V_58 = ( V_64 / V_66 ) + 1 ;
T_3 V_59 = ( V_64 % V_66 ) ;
F_36 ( V_29 , V_58 , V_59 , 0 , 0 ) ;
F_32 ( V_29 , V_83 ,
F_50 ( V_82 >> 8 ) ) ;
F_32 ( V_29 , V_84 ,
F_51 ( V_82 >> 8 ) ) ;
F_32 ( V_29 , V_85 , 0 ) ;
F_32 ( V_29 , V_86 , V_81 ) ;
F_42 ( V_29 ) ;
return 0 ;
}
static inline T_3 F_52 ( struct V_87 * V_88 )
{
T_3 V_89 ;
V_89 = V_88 -> V_90 * V_91 +
V_88 -> V_92 * V_93 ;
F_53 ( L_5 , V_89 ) ;
return V_89 ;
}
static inline struct V_94 * F_54 ( void * V_95 )
{
return (struct V_94 * ) V_95 ;
}
static inline struct V_87 * F_55 ( void * V_95 )
{
return (struct V_87 * ) V_95 ;
}
static int F_56 ( struct V_11 * V_29 , void * V_95 , T_3 V_64 ,
T_3 V_65 , T_3 T_4 * V_96 )
{
T_3 V_97 , V_98 ;
struct V_94 * V_88 ;
V_88 = F_54 ( V_95 ) ;
V_98 = ! F_57 ( V_97 , V_96 ) ;
F_44 ( V_29 , V_64 , V_65 ) ;
F_32 ( V_29 , V_99 , V_88 -> V_100 ) ;
F_32 ( V_29 , V_101 , V_88 -> V_102 ) ;
F_32 ( V_29 , V_103 , V_88 -> V_104 ) ;
F_32 ( V_29 , V_105 , V_88 -> V_106 ) ;
F_32 ( V_29 , V_107 , V_88 -> V_108 ) ;
F_32 ( V_29 , V_109 , V_88 -> V_110 ) ;
F_32 ( V_29 , V_111 , V_88 -> V_112 ) ;
F_32 ( V_29 , V_113 , V_88 -> V_114 ) ;
F_32 ( V_29 , V_115 , V_88 -> V_116 ) ;
F_32 ( V_29 , V_117 , V_88 -> V_118 ) ;
F_32 ( V_29 , V_119 ,
V_88 -> V_120 ) ;
F_32 ( V_29 , V_121 , V_88 -> V_122 ) ;
F_32 ( V_29 , V_123 , V_88 -> V_124 ) ;
F_32 ( V_29 , V_125 ,
V_88 -> V_126 ) ;
F_32 ( V_29 , V_127 ,
V_88 -> V_128 ) ;
F_32 ( V_29 , V_129 ,
V_88 -> V_130 ) ;
F_32 ( V_29 , V_131 ,
V_88 -> V_132 ) ;
F_32 ( V_29 , V_133 ,
V_88 -> V_134 ) ;
F_32 ( V_29 , V_135 ,
V_88 -> V_136 ) ;
F_32 ( V_29 , V_137 , V_88 -> V_138 ) ;
F_32 ( V_29 , V_139 ,
V_88 -> V_140 ) ;
F_32 ( V_29 , V_141 ,
V_88 -> V_142 ) ;
F_32 ( V_29 , V_143 ,
V_88 -> V_144 ) ;
F_32 ( V_29 , V_145 , V_88 -> V_146 ) ;
F_32 ( V_29 , V_147 , V_88 -> V_148 ) ;
F_32 ( V_29 , V_149 , V_88 -> V_150 ) ;
F_32 ( V_29 , V_151 , V_88 -> V_152 ) ;
F_32 ( V_29 , V_153 , V_88 -> V_154 ) ;
if ( V_98 )
F_32 ( V_29 , V_155 , V_97 ) ;
F_32 ( V_29 , V_156 , V_88 -> V_157 ) ;
F_45 ( V_29 ) ;
return 0 ;
}
static int F_58 ( struct V_11 * V_29 , void * V_95 )
{
struct V_87 * V_88 ;
T_3 V_158 ;
V_88 = F_55 ( V_95 ) ;
V_158 = F_52 ( V_88 ) ;
F_32 ( V_29 ,
V_158 + V_159 ,
V_88 -> V_160 ) ;
F_32 ( V_29 ,
V_158 + V_161 ,
V_88 -> V_162 ) ;
F_32 ( V_29 ,
V_158 + V_163 ,
V_88 -> V_164 ) ;
F_32 ( V_29 ,
V_158 + V_165 ,
V_88 -> V_166 ) ;
F_32 ( V_29 ,
V_158 + V_167 ,
V_88 -> V_168 ) ;
F_32 ( V_29 ,
V_158 + V_169 ,
V_88 -> V_170 ) ;
F_32 ( V_29 ,
V_158 + V_171 ,
V_88 -> V_172 ) ;
return 0 ;
}
static bool F_59 ( struct V_11 * V_29 , T_2 V_173 ,
T_3 V_64 , T_3 V_65 )
{
T_3 V_174 ;
bool V_89 = false ;
T_3 V_175 , V_176 ;
F_44 ( V_29 , V_64 , V_65 ) ;
V_174 = F_34 ( V_29 , V_156 ) ;
if ( V_174 ) {
V_175 = F_50 ( V_173 >> 8 ) ;
V_176 = F_51 ( V_173 >> 8 ) ;
if ( V_175 == F_34 ( V_29 , V_105 ) &&
V_176 == F_34 ( V_29 , V_107 ) )
V_89 = true ;
}
F_45 ( V_29 ) ;
return V_89 ;
}
static bool F_60 ( struct V_11 * V_29 , void * V_95 )
{
struct V_87 * V_88 ;
T_3 V_158 ;
T_3 V_172 ;
V_88 = F_55 ( V_95 ) ;
V_158 = F_52 ( V_88 ) ;
V_172 = F_34 ( V_29 ,
V_158 + V_171 ) ;
if ( V_172 & V_177 )
return true ;
return false ;
}
static int F_61 ( struct V_11 * V_29 , T_3 V_178 ,
unsigned int V_179 , T_3 V_64 ,
T_3 V_65 )
{
T_3 V_180 ;
F_44 ( V_29 , V_64 , V_65 ) ;
F_32 ( V_29 , V_143 , 0 ) ;
F_32 ( V_29 , V_181 , V_178 ) ;
while ( true ) {
V_180 = F_34 ( V_29 , V_156 ) ;
if ( V_180 & 0x1 )
break;
if ( V_179 == 0 ) {
F_62 ( L_6 ,
V_180 ) ;
F_45 ( V_29 ) ;
return - V_182 ;
}
F_63 ( 20 ) ;
V_179 -= 20 ;
}
F_45 ( V_29 ) ;
return 0 ;
}
static int F_64 ( struct V_11 * V_29 , void * V_95 ,
unsigned int V_179 )
{
struct V_87 * V_88 ;
T_3 V_158 ;
T_3 V_180 ;
V_88 = F_55 ( V_95 ) ;
V_158 = F_52 ( V_88 ) ;
V_180 = F_34 ( V_29 , V_158 + V_171 ) ;
V_180 = V_180 & ~ V_177 ;
F_32 ( V_29 , V_158 + V_171 , V_180 ) ;
while ( true ) {
V_180 = F_34 ( V_29 , V_158 +
V_183 ) ;
if ( V_180 & V_184 )
break;
if ( V_179 == 0 )
return - V_182 ;
F_63 ( 20 ) ;
V_179 -= 20 ;
}
F_32 ( V_29 , V_158 + V_169 , 0 ) ;
F_32 ( V_29 , V_158 + V_185 , 0 ) ;
F_32 ( V_29 , V_158 + V_186 , 0 ) ;
F_32 ( V_29 , V_158 + V_161 , 0 ) ;
return 0 ;
}
static T_5 F_65 ( struct V_11 * V_29 , enum V_187 type )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
const union V_188 * V_189 ;
F_15 ( V_29 == NULL || V_8 -> V_190 == NULL ) ;
switch ( type ) {
case V_191 :
V_189 = ( const union V_188 * ) V_8 -> V_192 -> V_193 ;
break;
case V_194 :
V_189 = ( const union V_188 * ) V_8 -> V_195 -> V_193 ;
break;
case V_196 :
V_189 = ( const union V_188 * ) V_8 -> V_197 -> V_193 ;
break;
case V_198 :
V_189 = ( const union V_188 * ) V_8 -> V_190 -> V_193 ;
break;
case V_199 :
V_189 = ( const union V_188 * )
V_8 -> V_200 -> V_193 ;
break;
case V_201 :
V_189 = ( const union V_188 * ) V_8 -> V_202 -> V_193 ;
break;
case V_203 :
V_189 = ( const union V_188 * )
V_8 -> V_204 -> V_193 ;
break;
default:
return 0 ;
}
if ( V_189 == NULL )
return 0 ;
return V_189 -> V_205 . V_206 ;
}
