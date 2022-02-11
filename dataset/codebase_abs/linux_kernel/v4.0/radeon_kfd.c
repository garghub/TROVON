bool F_1 ( void )
{
#if F_2 ( V_1 )
bool (* F_3)( unsigned , const struct V_2 * ,
const struct V_3 * * );
F_3 = F_4 ( V_4 ) ;
if ( F_3 == NULL )
return false ;
if ( ! F_3 ( V_5 , & V_6 , & V_7 ) ) {
F_5 ( V_4 ) ;
V_7 = NULL ;
return false ;
}
return true ;
#elif F_2 ( V_8 )
if ( ! V_4 ( V_5 , & V_6 , & V_7 ) ) {
V_7 = NULL ;
return false ;
}
return true ;
#else
return false ;
#endif
}
void F_6 ( void )
{
if ( V_7 ) {
V_7 -> exit () ;
F_5 ( V_4 ) ;
}
}
void F_7 ( struct V_9 * V_10 )
{
if ( V_7 )
V_10 -> V_11 = V_7 -> V_12 ( (struct V_13 * ) V_10 , V_10 -> V_14 ) ;
}
void F_8 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 ) {
struct V_15 V_16 = {
. V_17 = 0xFF00 ,
. V_18 = 1 ,
. V_19 = 4 - 1 ,
} ;
F_9 ( V_10 ,
& V_16 . V_20 ,
& V_16 . V_21 ,
& V_16 . V_22 ) ;
V_7 -> V_23 ( V_10 -> V_11 , & V_16 ) ;
}
}
void F_10 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 ) {
V_7 -> V_24 ( V_10 -> V_11 ) ;
V_10 -> V_11 = NULL ;
}
}
void F_11 ( struct V_9 * V_10 , const void * V_25 )
{
if ( V_10 -> V_11 )
V_7 -> V_26 ( V_10 -> V_11 , V_25 ) ;
}
void F_12 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 )
V_7 -> V_27 ( V_10 -> V_11 ) ;
}
int F_13 ( struct V_9 * V_10 )
{
int V_28 = 0 ;
if ( V_10 -> V_11 )
V_28 = V_7 -> V_29 ( V_10 -> V_11 ) ;
return V_28 ;
}
static int F_14 ( struct V_13 * V_30 , T_1 V_31 ,
void * * V_32 , T_2 * V_33 ,
void * * V_34 )
{
struct V_9 * V_10 = (struct V_9 * ) V_30 ;
struct V_35 * * V_36 = (struct V_35 * * ) V_32 ;
int V_28 ;
F_15 ( V_30 == NULL ) ;
F_15 ( V_33 == NULL ) ;
F_15 ( V_34 == NULL ) ;
* V_36 = F_16 ( sizeof( struct V_35 ) , V_37 ) ;
if ( ( * V_36 ) == NULL )
return - V_38 ;
V_28 = F_17 ( V_10 , V_31 , V_39 , true , V_40 ,
V_41 , NULL , NULL , & ( * V_36 ) -> V_42 ) ;
if ( V_28 ) {
F_18 ( V_10 -> V_43 ,
L_1 , V_28 ) ;
return V_28 ;
}
V_28 = F_19 ( ( * V_36 ) -> V_42 , true ) ;
if ( V_28 ) {
F_18 ( V_10 -> V_43 , L_2 , V_28 ) ;
goto V_44;
}
V_28 = F_20 ( ( * V_36 ) -> V_42 , V_40 ,
& ( * V_36 ) -> V_33 ) ;
if ( V_28 ) {
F_18 ( V_10 -> V_43 , L_3 , V_28 ) ;
goto V_45;
}
* V_33 = ( * V_36 ) -> V_33 ;
V_28 = F_21 ( ( * V_36 ) -> V_42 , & ( * V_36 ) -> V_34 ) ;
if ( V_28 ) {
F_18 ( V_10 -> V_43 ,
L_4 , V_28 ) ;
goto V_46;
}
* V_34 = ( * V_36 ) -> V_34 ;
F_22 ( ( * V_36 ) -> V_42 ) ;
return 0 ;
V_46:
F_23 ( ( * V_36 ) -> V_42 ) ;
V_45:
F_22 ( ( * V_36 ) -> V_42 ) ;
V_44:
F_24 ( & ( * V_36 ) -> V_42 ) ;
return V_28 ;
}
static void F_25 ( struct V_13 * V_30 , void * V_32 )
{
struct V_35 * V_36 = (struct V_35 * ) V_32 ;
F_15 ( V_36 == NULL ) ;
F_19 ( V_36 -> V_42 , true ) ;
F_26 ( V_36 -> V_42 ) ;
F_23 ( V_36 -> V_42 ) ;
F_22 ( V_36 -> V_42 ) ;
F_24 ( & ( V_36 -> V_42 ) ) ;
F_27 ( V_36 ) ;
}
static T_2 F_28 ( struct V_13 * V_30 )
{
struct V_9 * V_10 = (struct V_9 * ) V_30 ;
F_15 ( V_30 == NULL ) ;
return V_10 -> V_47 . V_48 ;
}
static T_2 F_29 ( struct V_13 * V_30 )
{
struct V_9 * V_10 = (struct V_9 * ) V_30 ;
return V_10 -> V_49 -> F_29 ( V_10 ) ;
}
static T_3 F_30 ( struct V_13 * V_30 )
{
struct V_9 * V_10 = (struct V_9 * ) V_30 ;
return V_10 -> V_50 . V_51 . V_52 . V_53 . V_54 / 100 ;
}
static inline struct V_9 * F_31 ( struct V_13 * V_30 )
{
return (struct V_9 * ) V_30 ;
}
static void F_32 ( struct V_13 * V_30 , T_3 V_55 , T_3 V_56 )
{
struct V_9 * V_10 = F_31 ( V_30 ) ;
F_33 ( V_56 , ( void V_57 * ) ( V_10 -> V_58 + V_55 ) ) ;
}
static T_3 F_34 ( struct V_13 * V_30 , T_3 V_55 )
{
struct V_9 * V_10 = F_31 ( V_30 ) ;
return F_35 ( ( void V_57 * ) ( V_10 -> V_58 + V_55 ) ) ;
}
static void F_36 ( struct V_13 * V_30 , T_3 V_59 , T_3 V_60 ,
T_3 V_61 , T_3 V_62 )
{
struct V_9 * V_10 = F_31 ( V_30 ) ;
T_3 V_56 = F_37 ( V_60 ) | F_38 ( V_59 ) | F_39 ( V_62 ) | F_40 ( V_61 ) ;
F_41 ( & V_10 -> V_63 ) ;
F_32 ( V_30 , V_64 , V_56 ) ;
}
static void F_42 ( struct V_13 * V_30 )
{
struct V_9 * V_10 = F_31 ( V_30 ) ;
F_32 ( V_30 , V_64 , 0 ) ;
F_43 ( & V_10 -> V_63 ) ;
}
static void F_44 ( struct V_13 * V_30 , T_3 V_65 ,
T_3 V_66 )
{
T_3 V_59 = ( ++ V_65 / V_67 ) + 1 ;
T_3 V_60 = ( V_65 % V_67 ) ;
F_36 ( V_30 , V_59 , V_60 , V_66 , 0 ) ;
}
static void F_45 ( struct V_13 * V_30 )
{
F_42 ( V_30 ) ;
}
static void F_46 ( struct V_13 * V_30 , T_3 V_62 ,
T_3 V_68 ,
T_3 V_69 ,
T_3 V_70 ,
T_3 V_71 )
{
F_36 ( V_30 , 0 , 0 , 0 , V_62 ) ;
F_32 ( V_30 , V_72 , V_68 ) ;
F_32 ( V_30 , V_73 , V_69 ) ;
F_32 ( V_30 , V_74 , V_70 ) ;
F_32 ( V_30 , V_75 , V_71 ) ;
F_42 ( V_30 ) ;
}
static int F_47 ( struct V_13 * V_30 , unsigned int V_76 ,
unsigned int V_62 )
{
T_3 V_77 = ( V_76 == 0 ) ? 0 :
( T_3 ) V_76 | V_78 ;
F_32 ( V_30 , V_79 + V_62 * sizeof( T_3 ) ,
V_77 ) ;
while ( ! ( F_34 ( V_30 , V_80 ) &
( 1U << V_62 ) ) )
F_48 () ;
F_32 ( V_30 , V_80 , 1U << V_62 ) ;
F_32 ( V_30 , V_81 + V_62 * sizeof( T_3 ) ,
V_77 ) ;
return 0 ;
}
static int F_49 ( struct V_13 * V_30 , T_3 V_65 ,
T_3 V_82 , T_2 V_83 )
{
T_3 V_59 = ( V_65 / V_67 ) + 1 ;
T_3 V_60 = ( V_65 % V_67 ) ;
F_36 ( V_30 , V_59 , V_60 , 0 , 0 ) ;
F_32 ( V_30 , V_84 ,
F_50 ( V_83 >> 8 ) ) ;
F_32 ( V_30 , V_85 ,
F_51 ( V_83 >> 8 ) ) ;
F_32 ( V_30 , V_86 , 0 ) ;
F_32 ( V_30 , V_87 , V_82 ) ;
F_42 ( V_30 ) ;
return 0 ;
}
static inline T_3 F_52 ( struct V_88 * V_89 )
{
T_3 V_90 ;
V_90 = V_89 -> V_91 * V_92 +
V_89 -> V_93 * V_94 ;
F_53 ( L_5 , V_90 ) ;
return V_90 ;
}
static inline struct V_95 * F_54 ( void * V_96 )
{
return (struct V_95 * ) V_96 ;
}
static inline struct V_88 * F_55 ( void * V_96 )
{
return (struct V_88 * ) V_96 ;
}
static int F_56 ( struct V_13 * V_30 , void * V_96 , T_3 V_65 ,
T_3 V_66 , T_3 T_4 * V_97 )
{
T_3 V_98 , V_99 ;
struct V_95 * V_89 ;
V_89 = F_54 ( V_96 ) ;
V_99 = ! F_57 ( V_98 , V_97 ) ;
F_44 ( V_30 , V_65 , V_66 ) ;
F_32 ( V_30 , V_100 , V_89 -> V_101 ) ;
F_32 ( V_30 , V_102 , V_89 -> V_103 ) ;
F_32 ( V_30 , V_104 , V_89 -> V_105 ) ;
F_32 ( V_30 , V_106 , V_89 -> V_107 ) ;
F_32 ( V_30 , V_108 , V_89 -> V_109 ) ;
F_32 ( V_30 , V_110 , V_89 -> V_111 ) ;
F_32 ( V_30 , V_112 , V_89 -> V_113 ) ;
F_32 ( V_30 , V_114 , V_89 -> V_115 ) ;
F_32 ( V_30 , V_116 , V_89 -> V_117 ) ;
F_32 ( V_30 , V_118 , V_89 -> V_119 ) ;
F_32 ( V_30 , V_120 ,
V_89 -> V_121 ) ;
F_32 ( V_30 , V_122 , V_89 -> V_123 ) ;
F_32 ( V_30 , V_124 , V_89 -> V_125 ) ;
F_32 ( V_30 , V_126 ,
V_89 -> V_127 ) ;
F_32 ( V_30 , V_128 ,
V_89 -> V_129 ) ;
F_32 ( V_30 , V_130 ,
V_89 -> V_131 ) ;
F_32 ( V_30 , V_132 ,
V_89 -> V_133 ) ;
F_32 ( V_30 , V_134 ,
V_89 -> V_135 ) ;
F_32 ( V_30 , V_136 ,
V_89 -> V_137 ) ;
F_32 ( V_30 , V_138 , V_89 -> V_139 ) ;
F_32 ( V_30 , V_140 ,
V_89 -> V_141 ) ;
F_32 ( V_30 , V_142 ,
V_89 -> V_143 ) ;
F_32 ( V_30 , V_144 ,
V_89 -> V_145 ) ;
F_32 ( V_30 , V_146 , V_89 -> V_147 ) ;
F_32 ( V_30 , V_148 , V_89 -> V_149 ) ;
F_32 ( V_30 , V_150 , V_89 -> V_151 ) ;
F_32 ( V_30 , V_152 , V_89 -> V_153 ) ;
F_32 ( V_30 , V_154 , V_89 -> V_155 ) ;
if ( V_99 )
F_32 ( V_30 , V_156 , V_98 ) ;
F_32 ( V_30 , V_157 , V_89 -> V_158 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_58 ( struct V_13 * V_30 , void * V_96 )
{
struct V_88 * V_89 ;
T_3 V_159 ;
V_89 = F_55 ( V_96 ) ;
V_159 = F_52 ( V_89 ) ;
F_32 ( V_30 ,
V_159 + V_160 ,
V_89 -> V_161 ) ;
F_32 ( V_30 ,
V_159 + V_162 ,
V_89 -> V_163 ) ;
F_32 ( V_30 ,
V_159 + V_164 ,
V_89 -> V_165 ) ;
F_32 ( V_30 ,
V_159 + V_166 ,
V_89 -> V_167 ) ;
F_32 ( V_30 ,
V_159 + V_168 ,
V_89 -> V_169 ) ;
F_32 ( V_30 ,
V_159 + V_170 ,
V_89 -> V_171 ) ;
F_32 ( V_30 ,
V_159 + V_172 ,
V_89 -> V_173 ) ;
return 0 ;
}
static bool F_59 ( struct V_13 * V_30 , T_2 V_174 ,
T_3 V_65 , T_3 V_66 )
{
T_3 V_175 ;
bool V_90 = false ;
T_3 V_176 , V_177 ;
F_44 ( V_30 , V_65 , V_66 ) ;
V_175 = F_34 ( V_30 , V_157 ) ;
if ( V_175 ) {
V_176 = F_50 ( V_174 >> 8 ) ;
V_177 = F_51 ( V_174 >> 8 ) ;
if ( V_176 == F_34 ( V_30 , V_106 ) &&
V_177 == F_34 ( V_30 , V_108 ) )
V_90 = true ;
}
F_45 ( V_30 ) ;
return V_90 ;
}
static bool F_60 ( struct V_13 * V_30 , void * V_96 )
{
struct V_88 * V_89 ;
T_3 V_159 ;
T_3 V_173 ;
V_89 = F_55 ( V_96 ) ;
V_159 = F_52 ( V_89 ) ;
V_173 = F_34 ( V_30 ,
V_159 + V_172 ) ;
if ( V_173 & V_178 )
return true ;
return false ;
}
static int F_61 ( struct V_13 * V_30 , T_3 V_179 ,
unsigned int V_180 , T_3 V_65 ,
T_3 V_66 )
{
T_3 V_181 ;
F_44 ( V_30 , V_65 , V_66 ) ;
F_32 ( V_30 , V_144 , 0 ) ;
F_32 ( V_30 , V_182 , V_179 ) ;
while ( true ) {
V_181 = F_34 ( V_30 , V_157 ) ;
if ( V_181 & 0x1 )
break;
if ( V_180 == 0 ) {
F_62 ( L_6 ,
V_181 ) ;
F_45 ( V_30 ) ;
return - V_183 ;
}
F_63 ( 20 ) ;
V_180 -= 20 ;
}
F_45 ( V_30 ) ;
return 0 ;
}
static int F_64 ( struct V_13 * V_30 , void * V_96 ,
unsigned int V_180 )
{
struct V_88 * V_89 ;
T_3 V_159 ;
T_3 V_181 ;
V_89 = F_55 ( V_96 ) ;
V_159 = F_52 ( V_89 ) ;
V_181 = F_34 ( V_30 , V_159 + V_172 ) ;
V_181 = V_181 & ~ V_178 ;
F_32 ( V_30 , V_159 + V_172 , V_181 ) ;
while ( true ) {
V_181 = F_34 ( V_30 , V_159 +
V_184 ) ;
if ( V_181 & V_185 )
break;
if ( V_180 == 0 )
return - V_183 ;
F_63 ( 20 ) ;
V_180 -= 20 ;
}
F_32 ( V_30 , V_159 + V_170 , 0 ) ;
F_32 ( V_30 , V_159 + V_186 , 0 ) ;
F_32 ( V_30 , V_159 + V_187 , 0 ) ;
F_32 ( V_30 , V_159 + V_162 , 0 ) ;
return 0 ;
}
static T_5 F_65 ( struct V_13 * V_30 , enum V_188 type )
{
struct V_9 * V_10 = (struct V_9 * ) V_30 ;
const union V_189 * V_190 ;
F_15 ( V_30 == NULL || V_10 -> V_191 == NULL ) ;
switch ( type ) {
case V_192 :
V_190 = ( const union V_189 * ) V_10 -> V_193 -> V_194 ;
break;
case V_195 :
V_190 = ( const union V_189 * ) V_10 -> V_196 -> V_194 ;
break;
case V_197 :
V_190 = ( const union V_189 * ) V_10 -> V_198 -> V_194 ;
break;
case V_199 :
V_190 = ( const union V_189 * ) V_10 -> V_191 -> V_194 ;
break;
case V_200 :
V_190 = ( const union V_189 * )
V_10 -> V_201 -> V_194 ;
break;
case V_202 :
V_190 = ( const union V_189 * ) V_10 -> V_203 -> V_194 ;
break;
case V_204 :
V_190 = ( const union V_189 * )
V_10 -> V_205 -> V_194 ;
break;
default:
return 0 ;
}
if ( V_190 == NULL )
return 0 ;
return V_190 -> V_206 . V_207 ;
}
