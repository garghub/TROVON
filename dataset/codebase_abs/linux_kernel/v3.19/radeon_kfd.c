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
. V_19 = 8 - 1 ,
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
static T_1 F_14 ( enum V_30 V_31 )
{
switch ( V_31 ) {
case V_32 : return V_33 ;
default: return V_34 ;
}
}
static int F_15 ( struct V_13 * V_35 , unsigned int V_36 )
{
struct V_9 * V_10 = (struct V_9 * ) V_35 ;
int V_28 ;
F_16 ( V_35 == NULL ) ;
V_28 = F_17 ( V_10 , & V_10 -> V_37 ,
V_36 ,
V_38 ,
V_34 ,
V_39 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_18 ( V_10 , & V_10 -> V_37 ) ;
if ( V_28 )
F_19 ( V_10 , & V_10 -> V_37 ) ;
return V_28 ;
}
static void F_20 ( struct V_13 * V_35 )
{
struct V_9 * V_10 = (struct V_9 * ) V_35 ;
F_16 ( V_35 == NULL ) ;
F_21 ( V_10 , & V_10 -> V_37 ) ;
F_19 ( V_10 , & V_10 -> V_37 ) ;
}
static int F_22 ( struct V_13 * V_35 , T_2 V_36 , T_2 V_40 ,
enum V_30 V_41 , struct V_42 * * V_43 )
{
struct V_9 * V_10 = (struct V_9 * ) V_35 ;
T_1 V_44 ;
int V_28 ;
F_16 ( V_35 == NULL ) ;
V_44 = F_14 ( V_41 ) ;
if ( V_44 != V_34 ) {
F_23 ( V_10 -> V_45 ,
L_1 ) ;
return - V_46 ;
}
* V_43 = F_24 ( sizeof( struct V_42 ) , V_47 ) ;
if ( ( * V_43 ) == NULL )
return - V_48 ;
V_28 = F_25 ( V_10 , & V_10 -> V_37 , & ( * V_43 ) -> V_49 , V_36 ,
V_40 ) ;
if ( V_28 ) {
F_23 ( V_10 -> V_45 , L_2 , V_28 ) ;
return V_28 ;
}
( * V_43 ) -> V_50 = F_26 ( ( * V_43 ) -> V_49 ) ;
( * V_43 ) -> V_51 = F_27 ( ( * V_43 ) -> V_49 ) ;
return 0 ;
}
static void F_28 ( struct V_13 * V_35 , struct V_42 * V_43 )
{
struct V_9 * V_10 = (struct V_9 * ) V_35 ;
F_16 ( V_35 == NULL ) ;
F_29 ( V_10 , & V_43 -> V_49 , NULL ) ;
F_30 ( V_43 ) ;
}
static T_3 F_31 ( struct V_13 * V_35 )
{
struct V_9 * V_10 = (struct V_9 * ) V_35 ;
F_16 ( V_35 == NULL ) ;
return V_10 -> V_52 . V_53 ;
}
static T_3 F_32 ( struct V_13 * V_35 )
{
struct V_9 * V_10 = (struct V_9 * ) V_35 ;
return V_10 -> V_54 -> F_32 ( V_10 ) ;
}
static T_4 F_33 ( struct V_13 * V_35 )
{
struct V_9 * V_10 = (struct V_9 * ) V_35 ;
return V_10 -> V_55 . V_56 . V_57 . V_58 . V_59 / 100 ;
}
static inline struct V_9 * F_34 ( struct V_13 * V_35 )
{
return (struct V_9 * ) V_35 ;
}
static void F_35 ( struct V_13 * V_35 , T_4 V_60 , T_4 V_61 )
{
struct V_9 * V_10 = F_34 ( V_35 ) ;
F_36 ( V_61 , ( void V_62 * ) ( V_10 -> V_63 + V_60 ) ) ;
}
static T_4 F_37 ( struct V_13 * V_35 , T_4 V_60 )
{
struct V_9 * V_10 = F_34 ( V_35 ) ;
return F_38 ( ( void V_62 * ) ( V_10 -> V_63 + V_60 ) ) ;
}
static void F_39 ( struct V_13 * V_35 , T_4 V_64 , T_4 V_65 ,
T_4 V_66 , T_4 V_67 )
{
struct V_9 * V_10 = F_34 ( V_35 ) ;
T_4 V_61 = F_40 ( V_65 ) | F_41 ( V_64 ) | F_42 ( V_67 ) | F_43 ( V_66 ) ;
F_44 ( & V_10 -> V_68 ) ;
F_35 ( V_35 , V_69 , V_61 ) ;
}
static void F_45 ( struct V_13 * V_35 )
{
struct V_9 * V_10 = F_34 ( V_35 ) ;
F_35 ( V_35 , V_69 , 0 ) ;
F_46 ( & V_10 -> V_68 ) ;
}
static void F_47 ( struct V_13 * V_35 , T_4 V_70 ,
T_4 V_71 )
{
T_4 V_64 = ( ++ V_70 / V_72 ) + 1 ;
T_4 V_65 = ( V_70 % V_72 ) ;
F_39 ( V_35 , V_64 , V_65 , V_71 , 0 ) ;
}
static void F_48 ( struct V_13 * V_35 )
{
F_45 ( V_35 ) ;
}
static void F_49 ( struct V_13 * V_35 , T_4 V_67 ,
T_4 V_73 ,
T_4 V_74 ,
T_4 V_75 ,
T_4 V_76 )
{
F_39 ( V_35 , 0 , 0 , 0 , V_67 ) ;
F_35 ( V_35 , V_77 , V_73 ) ;
F_35 ( V_35 , V_78 , V_74 ) ;
F_35 ( V_35 , V_79 , V_75 ) ;
F_35 ( V_35 , V_80 , V_76 ) ;
F_45 ( V_35 ) ;
}
static int F_50 ( struct V_13 * V_35 , unsigned int V_81 ,
unsigned int V_67 )
{
T_4 V_82 = ( V_81 == 0 ) ? 0 :
( T_4 ) V_81 | V_83 ;
F_35 ( V_35 , V_84 + V_67 * sizeof( T_4 ) ,
V_82 ) ;
while ( ! ( F_37 ( V_35 , V_85 ) &
( 1U << V_67 ) ) )
F_51 () ;
F_35 ( V_35 , V_85 , 1U << V_67 ) ;
F_35 ( V_35 , V_86 + V_67 * sizeof( T_4 ) ,
V_82 ) ;
return 0 ;
}
static int F_52 ( struct V_13 * V_35 )
{
int V_87 ;
T_4 V_76 = F_53 ( 0x6000 ) | F_54 ( 0x6000 ) ;
for ( V_87 = 8 ; V_87 < 16 ; V_87 ++ ) {
T_4 V_73 ;
F_39 ( V_35 , 0 , 0 , 0 , V_87 ) ;
V_73 = F_55 ( V_88 ) ;
V_73 |= F_56 ( V_89 ) ;
F_35 ( V_35 , V_77 , V_73 ) ;
F_35 ( V_35 , V_80 , V_76 ) ;
F_35 ( V_35 , V_90 , 0 ) ;
F_35 ( V_35 , V_78 , 1 ) ;
F_35 ( V_35 , V_79 , 0 ) ;
F_45 ( V_35 ) ;
}
return 0 ;
}
static int F_57 ( struct V_13 * V_35 , T_4 V_70 ,
T_4 V_91 , T_3 V_92 )
{
T_4 V_64 = ( V_70 / V_72 ) + 1 ;
T_4 V_65 = ( V_70 % V_72 ) ;
F_39 ( V_35 , V_64 , V_65 , 0 , 0 ) ;
F_35 ( V_35 , V_93 ,
F_58 ( V_92 >> 8 ) ) ;
F_35 ( V_35 , V_94 ,
F_59 ( V_92 >> 8 ) ) ;
F_35 ( V_35 , V_95 , 0 ) ;
F_35 ( V_35 , V_96 , V_91 ) ;
F_45 ( V_35 ) ;
return 0 ;
}
static inline struct V_97 * F_60 ( void * V_98 )
{
return (struct V_97 * ) V_98 ;
}
static int F_61 ( struct V_13 * V_35 , void * V_98 , T_4 V_70 ,
T_4 V_71 , T_4 T_5 * V_99 )
{
T_4 V_100 , V_101 ;
struct V_97 * V_102 ;
V_102 = F_60 ( V_98 ) ;
V_101 = ! F_62 ( V_100 , V_99 ) ;
F_47 ( V_35 , V_70 , V_71 ) ;
F_35 ( V_35 , V_103 , V_102 -> V_104 ) ;
F_35 ( V_35 , V_105 , V_102 -> V_106 ) ;
F_35 ( V_35 , V_107 , V_102 -> V_108 ) ;
F_35 ( V_35 , V_109 , V_102 -> V_110 ) ;
F_35 ( V_35 , V_111 , V_102 -> V_112 ) ;
F_35 ( V_35 , V_113 , V_102 -> V_114 ) ;
F_35 ( V_35 , V_115 , V_102 -> V_116 ) ;
F_35 ( V_35 , V_117 , V_102 -> V_118 ) ;
F_35 ( V_35 , V_119 , V_102 -> V_120 ) ;
F_35 ( V_35 , V_121 , V_102 -> V_122 ) ;
F_35 ( V_35 , V_123 ,
V_102 -> V_124 ) ;
F_35 ( V_35 , V_125 , V_102 -> V_126 ) ;
F_35 ( V_35 , V_127 , V_102 -> V_128 ) ;
F_35 ( V_35 , V_129 ,
V_102 -> V_130 ) ;
F_35 ( V_35 , V_131 ,
V_102 -> V_132 ) ;
F_35 ( V_35 , V_133 ,
V_102 -> V_134 ) ;
F_35 ( V_35 , V_135 ,
V_102 -> V_136 ) ;
F_35 ( V_35 , V_137 ,
V_102 -> V_138 ) ;
F_35 ( V_35 , V_139 ,
V_102 -> V_140 ) ;
F_35 ( V_35 , V_141 , V_102 -> V_142 ) ;
F_35 ( V_35 , V_143 ,
V_102 -> V_144 ) ;
F_35 ( V_35 , V_145 ,
V_102 -> V_146 ) ;
F_35 ( V_35 , V_147 ,
V_102 -> V_148 ) ;
F_35 ( V_35 , V_149 , V_102 -> V_150 ) ;
F_35 ( V_35 , V_151 , V_102 -> V_152 ) ;
F_35 ( V_35 , V_153 , V_102 -> V_154 ) ;
F_35 ( V_35 , V_155 , V_102 -> V_156 ) ;
F_35 ( V_35 , V_157 , V_102 -> V_158 ) ;
if ( V_101 )
F_35 ( V_35 , V_159 , V_100 ) ;
F_35 ( V_35 , V_160 , V_102 -> V_161 ) ;
F_48 ( V_35 ) ;
return 0 ;
}
static bool F_63 ( struct V_13 * V_35 , T_3 V_162 ,
T_4 V_70 , T_4 V_71 )
{
T_4 V_163 ;
bool V_164 = false ;
T_4 V_165 , V_166 ;
F_47 ( V_35 , V_70 , V_71 ) ;
V_163 = F_37 ( V_35 , V_160 ) ;
if ( V_163 ) {
V_165 = F_58 ( V_162 >> 8 ) ;
V_166 = F_59 ( V_162 >> 8 ) ;
if ( V_165 == F_37 ( V_35 , V_109 ) &&
V_166 == F_37 ( V_35 , V_111 ) )
V_164 = true ;
}
F_48 ( V_35 ) ;
return V_164 ;
}
static int F_64 ( struct V_13 * V_35 , T_4 V_167 ,
unsigned int V_168 , T_4 V_70 ,
T_4 V_71 )
{
T_4 V_169 ;
F_47 ( V_35 , V_70 , V_71 ) ;
F_35 ( V_35 , V_147 , 0 ) ;
F_35 ( V_35 , V_170 , V_167 ) ;
while ( true ) {
V_169 = F_37 ( V_35 , V_160 ) ;
if ( V_169 & 0x1 )
break;
if ( V_168 == 0 ) {
F_65 ( L_3 ,
V_169 ) ;
F_48 ( V_35 ) ;
return - V_171 ;
}
F_66 ( 20 ) ;
V_168 -= 20 ;
}
F_48 ( V_35 ) ;
return 0 ;
}
static T_6 F_67 ( struct V_13 * V_35 , enum V_172 type )
{
struct V_9 * V_10 = (struct V_9 * ) V_35 ;
const union V_173 * V_174 ;
F_16 ( V_35 == NULL || V_10 -> V_175 == NULL ) ;
switch ( type ) {
case V_176 :
V_174 = ( const union V_173 * ) V_10 -> V_177 -> V_178 ;
break;
case V_179 :
V_174 = ( const union V_173 * ) V_10 -> V_180 -> V_178 ;
break;
case V_181 :
V_174 = ( const union V_173 * ) V_10 -> V_182 -> V_178 ;
break;
case V_183 :
V_174 = ( const union V_173 * ) V_10 -> V_175 -> V_178 ;
break;
case V_184 :
V_174 = ( const union V_173 * )
V_10 -> V_185 -> V_178 ;
break;
case V_186 :
V_174 = ( const union V_173 * ) V_10 -> V_187 -> V_178 ;
break;
case V_188 :
V_174 = ( const union V_173 * )
V_10 -> V_189 -> V_178 ;
break;
default:
return 0 ;
}
if ( V_174 == NULL )
return 0 ;
return V_174 -> V_190 . V_191 ;
}
