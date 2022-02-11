static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( V_1 -> V_3 & V_2 ) != 0 ) {
V_1 -> V_3 &= ~ V_2 ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_3 ( V_4 ) ;
}
}
static inline void
F_4 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( V_1 -> V_3 & V_2 ) != V_2 ) {
V_1 -> V_3 |= V_2 ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_3 ( V_4 ) ;
}
}
void
F_5 ( T_1 * V_1 , int V_5 , T_2 V_2 )
{
if ( ( V_1 -> V_6 [ V_5 ] & V_2 ) != V_2 ) {
T_2 V_7 = F_6 ( V_5 ) ;
V_1 -> V_6 [ V_5 ] |= V_2 ;
F_2 ( V_7 , V_1 -> V_6 [ V_5 ] | ( V_2 >> 16 ) ) ;
F_3 ( V_7 ) ;
}
}
void
F_7 ( T_1 * V_1 , int V_5 , T_2 V_2 )
{
if ( ( V_1 -> V_6 [ V_5 ] & V_2 ) != 0 ) {
T_2 V_7 = F_6 ( V_5 ) ;
V_1 -> V_6 [ V_5 ] &= ~ V_2 ;
F_2 ( V_7 , V_1 -> V_6 [ V_5 ] ) ;
F_3 ( V_7 ) ;
}
}
void F_8 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
unsigned long V_11 ;
if ( F_9 ( V_9 ) )
return;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( F_11 ( V_9 ) )
F_1 ( V_1 , V_13 ) ;
else {
F_5 ( V_1 , 1 ,
V_14 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , 0 ,
V_14 ) ;
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static int
F_14 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
return F_15 ( F_16 ( V_5 ) ) & V_16 ;
}
static T_2 F_17 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_17 ;
unsigned long V_18 ;
T_2 V_19 , V_20 , V_21 ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_18 ( L_1
L_2 , F_19 ( V_5 ) ) ;
return 0 ;
}
V_17 = F_20 ( V_5 ) ;
V_18 = F_21 ( V_5 ) ;
do {
V_19 = F_15 ( V_17 ) & V_22 ;
V_21 = F_15 ( V_18 ) & V_23 ;
V_20 = F_15 ( V_17 ) & V_22 ;
} while ( V_19 != V_20 );
V_19 >>= V_24 ;
V_21 >>= V_25 ;
return ( V_19 << 8 ) | V_21 ;
}
static T_2 F_22 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_7 = F_23 ( V_5 ) ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_18 ( L_1
L_2 , F_19 ( V_5 ) ) ;
return 0 ;
}
return F_15 ( V_7 ) ;
}
static int F_24 ( struct V_8 * V_9 , int V_5 ,
int * V_26 , int * V_27 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_28 = 0 , V_29 = 0 ;
int V_30 , V_31 , V_32 , V_33 ;
bool V_34 = true ;
int V_35 = 0 ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_18 ( L_3
L_2 , F_19 ( V_5 ) ) ;
return 0 ;
}
V_33 = 1 + ( ( F_15 ( F_25 ( V_5 ) ) >> 16 ) & 0x1fff ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
V_29 = F_15 ( F_26 ( V_5 ) ) ;
* V_26 = V_29 & 0x1fff ;
* V_27 = 0 ;
} else {
V_29 = ( F_15 ( F_21 ( V_5 ) ) & V_36 ) >> V_37 ;
V_32 = 1 + ( ( F_15 ( F_27 ( V_5 ) ) >> 16 ) & 0x1fff ) ;
* V_26 = V_29 / V_32 ;
* V_27 = V_29 - ( * V_26 * V_32 ) ;
}
V_28 = F_15 ( F_28 ( V_5 ) ) ;
V_30 = V_28 & 0x1fff ;
V_31 = ( V_28 >> 16 ) & 0x1fff ;
if ( ( * V_26 < V_30 ) || ( * V_26 > V_31 ) )
V_34 = false ;
if ( V_34 && ( * V_26 >= V_30 ) )
* V_26 = * V_26 - V_33 ;
if ( V_28 > 0 )
V_35 |= V_38 | V_39 ;
if ( V_34 )
V_35 |= V_40 ;
return V_35 ;
}
static int F_29 ( struct V_8 * V_9 , int V_5 ,
int * V_41 ,
struct V_42 * V_43 ,
unsigned V_44 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_46 * V_47 ;
if ( V_5 < 0 || V_5 >= V_1 -> V_48 ) {
F_30 ( L_4 , V_5 ) ;
return - V_49 ;
}
V_47 = F_31 ( V_9 , V_5 ) ;
if ( V_47 == NULL ) {
F_30 ( L_4 , V_5 ) ;
return - V_49 ;
}
if ( ! V_47 -> V_50 ) {
F_32 ( L_5 , V_5 ) ;
return - V_51 ;
}
return F_33 ( V_9 , V_5 , V_41 ,
V_43 , V_44 ,
V_47 ) ;
}
static void F_34 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_54 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
struct V_55 * V_56 = & V_9 -> V_56 ;
struct V_57 * V_58 ;
F_36 ( & V_56 -> V_59 ) ;
F_32 ( L_6 ) ;
F_37 (encoder, &mode_config->encoder_list, base.head)
if ( V_58 -> V_60 )
V_58 -> V_60 ( V_58 ) ;
F_38 ( & V_56 -> V_59 ) ;
F_39 ( V_9 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
T_2 V_61 , V_62 , V_63 , V_64 ;
T_3 V_65 = V_1 -> V_66 ;
F_41 ( V_67 , V_68 ) ;
V_61 = F_15 ( V_69 ) ;
V_62 = F_15 ( V_70 ) ;
V_63 = F_15 ( V_71 ) ;
V_64 = F_15 ( V_72 ) ;
if ( V_61 > V_63 ) {
if ( V_1 -> V_66 != V_1 -> V_73 )
V_65 = V_1 -> V_66 - 1 ;
if ( V_65 < V_1 -> V_73 )
V_65 = V_1 -> V_73 ;
} else if ( V_62 < V_64 ) {
if ( V_1 -> V_66 != V_1 -> V_74 )
V_65 = V_1 -> V_66 + 1 ;
if ( V_65 > V_1 -> V_74 )
V_65 = V_1 -> V_74 ;
}
if ( F_42 ( V_9 , V_65 ) )
V_1 -> V_66 = V_65 ;
return;
}
static void F_43 ( struct V_8 * V_9 ,
struct V_75 * V_76 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
if ( V_76 -> V_77 == NULL )
return;
F_44 ( V_76 , V_76 -> V_78 ( V_76 ) ) ;
F_45 ( & V_76 -> V_79 ) ;
if ( V_80 ) {
V_1 -> V_81 = 0 ;
F_46 ( & V_1 -> V_82 ,
V_83 +
F_47 ( V_84 ) ) ;
}
}
static void F_48 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_85 ) ;
T_2 V_86 , V_87 ;
T_3 V_65 ;
F_49 ( & V_1 -> V_88 ) ;
V_86 = V_1 -> V_86 ;
V_1 -> V_86 = 0 ;
V_87 = F_15 ( V_89 ) ;
F_2 ( V_89 , 0 ) ;
F_50 ( & V_1 -> V_88 ) ;
if ( ( V_86 & V_90 ) == 0 )
return;
F_36 ( & V_1 -> V_9 -> V_91 ) ;
if ( V_86 & V_92 )
V_65 = V_1 -> V_66 + 1 ;
else
V_65 = V_1 -> V_66 - 1 ;
F_51 ( V_1 -> V_9 , V_65 ) ;
F_38 ( & V_1 -> V_9 -> V_91 ) ;
}
static void F_52 ( struct V_8 * V_9 ,
struct V_45 * V_1 ,
T_2 V_93 )
{
if ( V_93 & ( V_94 |
V_95 ) )
F_43 ( V_9 , & V_1 -> V_76 [ V_96 ] ) ;
if ( V_93 & V_97 )
F_43 ( V_9 , & V_1 -> V_76 [ V_98 ] ) ;
if ( V_93 & V_99 )
F_43 ( V_9 , & V_1 -> V_76 [ V_100 ] ) ;
if ( V_93 & ( V_101 |
V_102 |
V_103 ) ) {
F_30 ( L_7 , V_93 ) ;
F_53 ( V_9 , false ) ;
}
}
static void F_54 ( struct V_45 * V_1 ,
T_2 V_86 )
{
unsigned long V_44 ;
F_10 ( & V_1 -> V_88 , V_44 ) ;
V_1 -> V_86 |= V_86 ;
F_2 ( V_89 , V_1 -> V_86 ) ;
F_3 ( V_89 ) ;
F_13 ( & V_1 -> V_88 , V_44 ) ;
F_55 ( V_1 -> V_104 , & V_1 -> V_85 ) ;
}
static T_4 F_56 ( T_5 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_106 , V_93 , V_86 ;
T_4 V_35 = V_107 ;
unsigned long V_11 ;
int V_5 ;
T_2 V_108 [ V_109 ] ;
T_2 V_110 ;
int V_111 = 0 ;
bool V_112 ;
F_57 ( & V_1 -> V_113 ) ;
V_110 = V_114 |
V_115 ;
while ( true ) {
V_106 = F_15 ( V_116 ) ;
V_93 = F_15 ( V_117 ) ;
V_86 = F_15 ( V_118 ) ;
if ( V_93 == 0 && V_86 == 0 && V_106 == 0 )
goto V_119;
V_35 = V_120 ;
F_52 ( V_9 , V_1 , V_93 ) ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_58 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_108 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_108 [ V_5 ] & 0x8000ffff ) {
if ( V_108 [ V_5 ] & V_121 )
F_18 ( L_8 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_108 [ V_5 ] ) ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( V_106 & V_122 ) {
T_2 V_123 = F_15 ( V_124 ) ;
F_18 ( L_9 ,
V_123 ) ;
if ( V_123 & V_1 -> V_125 )
F_55 ( V_1 -> V_104 ,
& V_1 -> V_54 ) ;
F_2 ( V_124 , V_123 ) ;
F_15 ( V_124 ) ;
}
if ( V_106 & V_126 ) {
F_59 ( V_9 , 0 ) ;
V_111 ++ ;
F_60 ( V_9 , 0 ) ;
}
if ( V_106 & V_127 ) {
F_59 ( V_9 , 1 ) ;
V_111 ++ ;
F_60 ( V_9 , 0 ) ;
}
if ( V_108 [ V_5 ] & V_128 )
V_112 = true ;
if ( V_86 & V_90 )
F_54 ( V_1 , V_86 ) ;
F_2 ( V_117 , V_93 ) ;
F_2 ( V_118 , V_86 ) ;
F_2 ( V_116 , V_106 ) ;
}
V_119:
return V_35 ;
}
static void F_61 ( struct V_8 * V_9 , T_2 V_129 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_129 & V_130 )
F_18 ( L_10 ,
( V_129 & V_130 ) >>
V_131 ) ;
if ( V_129 & V_132 )
F_18 ( L_11 ) ;
if ( V_129 & V_133 )
F_18 ( L_12 ) ;
if ( V_129 & V_134 )
F_18 ( L_13 ) ;
if ( V_129 & V_135 )
F_30 ( L_14 ) ;
if ( V_129 & V_136 )
F_58 (pipe)
F_18 ( L_15 ,
F_19 ( V_5 ) ,
F_15 ( F_62 ( V_5 ) ) ) ;
if ( V_129 & ( V_137 | V_138 ) )
F_18 ( L_16 ) ;
if ( V_129 & ( V_139 | V_140 ) )
F_18 ( L_17 ) ;
if ( V_129 & V_141 )
F_18 ( L_18 ) ;
if ( V_129 & V_142 )
F_18 ( L_19 ) ;
}
static void F_63 ( struct V_8 * V_9 , T_2 V_129 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_129 & V_143 )
F_18 ( L_10 ,
( V_129 & V_143 ) >>
V_144 ) ;
if ( V_129 & V_145 )
F_18 ( L_20 ) ;
if ( V_129 & V_146 )
F_18 ( L_11 ) ;
if ( V_129 & V_147 )
F_18 ( L_21 ) ;
if ( V_129 & V_148 )
F_18 ( L_22 ) ;
if ( V_129 & V_149 )
F_58 (pipe)
F_18 ( L_15 ,
F_19 ( V_5 ) ,
F_15 ( F_62 ( V_5 ) ) ) ;
}
static T_4 F_64 ( T_5 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_150 , V_93 , V_151 , V_86 ;
T_4 V_35 = V_107 ;
int V_152 ;
F_57 ( & V_1 -> V_113 ) ;
V_151 = F_15 ( V_153 ) ;
F_2 ( V_153 , V_151 & ~ V_154 ) ;
V_93 = F_15 ( V_117 ) ;
if ( V_93 ) {
F_52 ( V_9 , V_1 , V_93 ) ;
F_2 ( V_117 , V_93 ) ;
V_35 = V_120 ;
}
V_150 = F_15 ( V_155 ) ;
if ( V_150 ) {
if ( V_150 & V_156 )
F_65 ( V_9 ) ;
for ( V_152 = 0 ; V_152 < 3 ; V_152 ++ ) {
if ( V_150 & ( V_157 << ( 5 * V_152 ) ) ) {
F_66 ( V_9 , V_152 ) ;
F_67 ( V_9 , V_152 ) ;
}
if ( V_150 & ( V_158 << ( 5 * V_152 ) ) )
F_59 ( V_9 , V_152 ) ;
}
if ( V_150 & V_159 ) {
T_2 V_129 = F_15 ( V_160 ) ;
if ( V_129 & V_161 )
F_55 ( V_1 -> V_104 , & V_1 -> V_54 ) ;
F_63 ( V_9 , V_129 ) ;
F_2 ( V_160 , V_129 ) ;
}
F_2 ( V_155 , V_150 ) ;
V_35 = V_120 ;
}
V_86 = F_15 ( V_118 ) ;
if ( V_86 ) {
if ( V_86 & V_90 )
F_54 ( V_1 , V_86 ) ;
F_2 ( V_118 , V_86 ) ;
V_35 = V_120 ;
}
F_2 ( V_153 , V_151 ) ;
F_3 ( V_153 ) ;
return V_35 ;
}
static void F_68 ( struct V_8 * V_9 ,
struct V_45 * V_1 ,
T_2 V_93 )
{
if ( V_93 & ( V_162 | V_163 ) )
F_43 ( V_9 , & V_1 -> V_76 [ V_96 ] ) ;
if ( V_93 & V_164 )
F_43 ( V_9 , & V_1 -> V_76 [ V_98 ] ) ;
}
static T_4 F_69 ( T_5 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_35 = V_107 ;
T_2 V_150 , V_93 , V_151 , V_129 , V_86 ;
T_2 V_165 ;
F_57 ( & V_1 -> V_113 ) ;
V_151 = F_15 ( V_153 ) ;
F_2 ( V_153 , V_151 & ~ V_154 ) ;
F_3 ( V_153 ) ;
V_150 = F_15 ( V_155 ) ;
V_93 = F_15 ( V_117 ) ;
V_129 = F_15 ( V_160 ) ;
V_86 = F_15 ( V_118 ) ;
if ( V_150 == 0 && V_93 == 0 && V_129 == 0 &&
( ! F_70 ( V_9 ) || V_86 == 0 ) )
goto V_166;
if ( F_71 ( V_9 ) )
V_165 = V_161 ;
else
V_165 = V_167 ;
V_35 = V_120 ;
if ( F_72 ( V_9 ) )
F_68 ( V_9 , V_1 , V_93 ) ;
else
F_52 ( V_9 , V_1 , V_93 ) ;
if ( V_150 & V_13 )
F_65 ( V_9 ) ;
if ( V_150 & V_168 ) {
F_66 ( V_9 , 0 ) ;
F_67 ( V_9 , 0 ) ;
}
if ( V_150 & V_169 ) {
F_66 ( V_9 , 1 ) ;
F_67 ( V_9 , 1 ) ;
}
if ( V_150 & V_170 )
F_59 ( V_9 , 0 ) ;
if ( V_150 & V_171 )
F_59 ( V_9 , 1 ) ;
if ( V_150 & V_172 ) {
if ( V_129 & V_165 )
F_55 ( V_1 -> V_104 , & V_1 -> V_54 ) ;
if ( F_71 ( V_9 ) )
F_63 ( V_9 , V_129 ) ;
else
F_61 ( V_9 , V_129 ) ;
}
if ( V_150 & V_173 ) {
F_41 ( V_67 , F_15 ( V_67 ) ) ;
F_40 ( V_9 ) ;
}
if ( F_70 ( V_9 ) && V_86 & V_90 )
F_54 ( V_1 , V_86 ) ;
F_2 ( V_160 , V_129 ) ;
F_2 ( V_117 , V_93 ) ;
F_2 ( V_155 , V_150 ) ;
F_2 ( V_118 , V_86 ) ;
V_166:
F_2 ( V_153 , V_151 ) ;
F_3 ( V_153 ) ;
return V_35 ;
}
static void F_73 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_174 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
char * V_175 [] = { L_23 , NULL } ;
char * V_176 [] = { L_24 , NULL } ;
char * V_177 [] = { L_25 , NULL } ;
F_74 ( & V_9 -> V_178 -> V_179 . V_180 , V_181 , V_175 ) ;
if ( F_75 ( & V_1 -> V_182 . V_183 ) ) {
F_18 ( L_26 ) ;
F_74 ( & V_9 -> V_178 -> V_179 . V_180 , V_181 , V_176 ) ;
if ( ! F_76 ( V_9 ) ) {
F_77 ( & V_1 -> V_182 . V_183 , 0 ) ;
F_74 ( & V_9 -> V_178 -> V_179 . V_180 , V_181 , V_177 ) ;
}
F_78 ( & V_1 -> V_184 ) ;
}
}
static struct V_185 *
F_79 ( struct V_45 * V_1 ,
struct V_186 * V_187 )
{
struct V_185 * V_188 ;
int V_189 , V_190 ;
T_2 V_191 ;
if ( V_187 == NULL || V_187 -> V_192 == NULL )
return NULL ;
V_190 = V_187 -> V_193 . V_194 / V_195 ;
V_188 = F_80 ( sizeof( * V_188 ) + V_190 * sizeof( T_2 * ) , V_196 ) ;
if ( V_188 == NULL )
return NULL ;
V_191 = V_187 -> V_197 ;
for ( V_189 = 0 ; V_189 < V_190 ; V_189 ++ ) {
unsigned long V_44 ;
void * V_198 ;
V_198 = F_80 ( V_195 , V_196 ) ;
if ( V_198 == NULL )
goto V_199;
F_81 ( V_44 ) ;
if ( V_191 < V_1 -> V_182 . V_200 &&
V_187 -> V_201 ) {
void T_6 * V_202 ;
V_202 = F_82 ( V_1 -> V_182 . V_203 ,
V_191 ) ;
F_83 ( V_198 , V_202 , V_195 ) ;
F_84 ( V_202 ) ;
} else {
void * V_202 ;
F_85 ( & V_187 -> V_192 [ V_189 ] , 1 ) ;
V_202 = F_86 ( V_187 -> V_192 [ V_189 ] ) ;
memcpy ( V_198 , V_202 , V_195 ) ;
F_87 ( V_202 ) ;
F_85 ( & V_187 -> V_192 [ V_189 ] , 1 ) ;
}
F_88 ( V_44 ) ;
V_188 -> V_192 [ V_189 ] = V_198 ;
V_191 += V_195 ;
}
V_188 -> V_190 = V_190 ;
V_188 -> V_197 = V_187 -> V_197 ;
return V_188 ;
V_199:
while ( V_189 -- )
F_89 ( V_188 -> V_192 [ V_189 ] ) ;
F_89 ( V_188 ) ;
return NULL ;
}
static void
F_90 ( struct V_185 * V_77 )
{
int V_189 ;
if ( V_77 == NULL )
return;
for ( V_189 = 0 ; V_189 < V_77 -> V_190 ; V_189 ++ )
F_89 ( V_77 -> V_192 [ V_189 ] ) ;
F_89 ( V_77 ) ;
}
void
F_91 ( struct V_204 * V_205 )
{
struct V_206 * error = F_35 ( V_205 ,
F_92 ( * error ) , V_207 ) ;
int V_152 ;
for ( V_152 = 0 ; V_152 < F_93 ( error -> V_76 ) ; V_152 ++ ) {
F_90 ( error -> V_76 [ V_152 ] . V_208 ) ;
F_90 ( error -> V_76 [ V_152 ] . V_209 ) ;
F_89 ( error -> V_76 [ V_152 ] . V_210 ) ;
}
F_89 ( error -> V_211 ) ;
F_89 ( error -> V_212 ) ;
F_89 ( error ) ;
}
static void F_94 ( struct V_213 * V_214 ,
struct V_186 * V_77 )
{
V_214 -> V_194 = V_77 -> V_193 . V_194 ;
V_214 -> V_215 = V_77 -> V_193 . V_215 ;
V_214 -> V_216 = V_77 -> V_217 ;
V_214 -> V_197 = V_77 -> V_197 ;
V_214 -> V_218 = V_77 -> V_193 . V_218 ;
V_214 -> V_219 = V_77 -> V_193 . V_219 ;
V_214 -> V_220 = V_77 -> V_220 ;
V_214 -> V_221 = 0 ;
if ( V_77 -> V_222 > 0 )
V_214 -> V_221 = 1 ;
if ( V_77 -> V_223 > 0 )
V_214 -> V_221 = - 1 ;
V_214 -> V_224 = V_77 -> V_225 ;
V_214 -> V_226 = V_77 -> V_226 ;
V_214 -> V_227 = V_77 -> V_228 != V_229 ;
V_214 -> V_76 = V_77 -> V_76 ? V_77 -> V_76 -> V_230 : - 1 ;
V_214 -> V_231 = V_77 -> V_231 ;
}
static T_2 F_95 ( struct V_213 * V_214 ,
int V_232 , struct V_233 * V_234 )
{
struct V_186 * V_77 ;
int V_152 = 0 ;
F_37 (obj, head, mm_list) {
F_94 ( V_214 ++ , V_77 ) ;
if ( ++ V_152 == V_232 )
break;
}
return V_152 ;
}
static T_2 F_96 ( struct V_213 * V_214 ,
int V_232 , struct V_233 * V_234 )
{
struct V_186 * V_77 ;
int V_152 = 0 ;
F_37 (obj, head, gtt_list) {
if ( V_77 -> V_222 == 0 )
continue;
F_94 ( V_214 ++ , V_77 ) ;
if ( ++ V_152 == V_232 )
break;
}
return V_152 ;
}
static void F_97 ( struct V_8 * V_9 ,
struct V_206 * error )
{
struct V_45 * V_1 = V_9 -> V_10 ;
int V_152 ;
switch ( F_12 ( V_9 ) -> V_15 ) {
case 7 :
case 6 :
for ( V_152 = 0 ; V_152 < 16 ; V_152 ++ )
error -> V_235 [ V_152 ] = F_98 ( V_236 + ( V_152 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_152 = 0 ; V_152 < 16 ; V_152 ++ )
error -> V_235 [ V_152 ] = F_98 ( V_237 + ( V_152 * 8 ) ) ;
break;
case 3 :
if ( F_99 ( V_9 ) || F_100 ( V_9 ) || F_101 ( V_9 ) )
for ( V_152 = 0 ; V_152 < 8 ; V_152 ++ )
error -> V_235 [ V_152 + 8 ] = F_15 ( V_238 + ( V_152 * 4 ) ) ;
case 2 :
for ( V_152 = 0 ; V_152 < 8 ; V_152 ++ )
error -> V_235 [ V_152 ] = F_15 ( V_239 + ( V_152 * 4 ) ) ;
break;
}
}
static struct V_185 *
F_102 ( struct V_45 * V_1 ,
struct V_75 * V_76 )
{
struct V_186 * V_77 ;
T_2 V_216 ;
if ( ! V_76 -> V_78 )
return NULL ;
V_216 = V_76 -> V_78 ( V_76 ) ;
F_37 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_77 -> V_76 != V_76 )
continue;
if ( F_103 ( V_216 , V_77 -> V_217 ) )
continue;
if ( ( V_77 -> V_193 . V_218 & V_240 ) == 0 )
continue;
return F_79 ( V_1 , V_77 ) ;
}
return NULL ;
}
static void F_104 ( struct V_8 * V_9 ,
struct V_206 * error ,
struct V_75 * V_76 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> V_241 [ V_76 -> V_230 ] = F_15 ( F_105 ( V_76 ) ) ;
error -> V_242 [ V_76 -> V_230 ] [ 0 ]
= F_15 ( F_106 ( V_76 -> V_243 ) ) ;
error -> V_242 [ V_76 -> V_230 ] [ 1 ]
= F_15 ( F_107 ( V_76 -> V_243 ) ) ;
}
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
error -> V_244 [ V_76 -> V_230 ] = F_15 ( F_108 ( V_76 -> V_243 ) ) ;
error -> V_245 [ V_76 -> V_230 ] = F_15 ( F_109 ( V_76 -> V_243 ) ) ;
error -> V_246 [ V_76 -> V_230 ] = F_15 ( F_110 ( V_76 -> V_243 ) ) ;
error -> V_247 [ V_76 -> V_230 ] = F_15 ( F_111 ( V_76 -> V_243 ) ) ;
error -> V_248 [ V_76 -> V_230 ] = F_15 ( F_112 ( V_76 -> V_243 ) ) ;
if ( V_76 -> V_230 == V_96 ) {
error -> V_249 = F_15 ( V_250 ) ;
error -> V_251 = F_98 ( V_252 ) ;
}
} else {
error -> V_244 [ V_76 -> V_230 ] = F_15 ( V_253 ) ;
error -> V_245 [ V_76 -> V_230 ] = F_15 ( V_254 ) ;
error -> V_246 [ V_76 -> V_230 ] = F_15 ( V_255 ) ;
error -> V_247 [ V_76 -> V_230 ] = F_15 ( V_256 ) ;
}
error -> V_257 [ V_76 -> V_230 ] = F_113 ( & V_76 -> V_79 ) ;
error -> V_258 [ V_76 -> V_230 ] = F_15 ( F_114 ( V_76 -> V_243 ) ) ;
error -> V_216 [ V_76 -> V_230 ] = V_76 -> V_78 ( V_76 ) ;
error -> V_259 [ V_76 -> V_230 ] = F_115 ( V_76 ) ;
error -> V_234 [ V_76 -> V_230 ] = F_116 ( V_76 ) ;
error -> V_260 [ V_76 -> V_230 ] = F_117 ( V_76 ) ;
error -> V_261 [ V_76 -> V_230 ] = V_76 -> V_234 ;
error -> V_262 [ V_76 -> V_230 ] = V_76 -> V_260 ;
}
static void F_118 ( struct V_8 * V_9 ,
struct V_206 * error )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_75 * V_76 ;
struct V_263 * V_264 ;
int V_152 , V_232 ;
F_119 (ring, dev_priv, i) {
F_104 ( V_9 , error , V_76 ) ;
error -> V_76 [ V_152 ] . V_208 =
F_102 ( V_1 , V_76 ) ;
error -> V_76 [ V_152 ] . V_209 =
F_79 ( V_1 , V_76 -> V_77 ) ;
V_232 = 0 ;
F_37 (request, &ring->request_list, list)
V_232 ++ ;
error -> V_76 [ V_152 ] . V_265 = V_232 ;
error -> V_76 [ V_152 ] . V_210 =
F_80 ( V_232 * sizeof( struct V_266 ) ,
V_196 ) ;
if ( error -> V_76 [ V_152 ] . V_210 == NULL ) {
error -> V_76 [ V_152 ] . V_265 = 0 ;
continue;
}
V_232 = 0 ;
F_37 (request, &ring->request_list, list) {
struct V_266 * V_267 ;
V_267 = & error -> V_76 [ V_152 ] . V_210 [ V_232 ++ ] ;
V_267 -> V_216 = V_264 -> V_216 ;
V_267 -> V_83 = V_264 -> V_268 ;
V_267 -> V_260 = V_264 -> V_260 ;
}
}
}
static void F_120 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_186 * V_77 ;
struct V_206 * error ;
unsigned long V_44 ;
int V_152 , V_5 ;
F_10 ( & V_1 -> V_269 , V_44 ) ;
error = V_1 -> V_270 ;
F_13 ( & V_1 -> V_269 , V_44 ) ;
if ( error )
return;
error = F_121 ( sizeof( * error ) , V_196 ) ;
if ( ! error ) {
F_18 ( L_27 ) ;
return;
}
F_122 ( L_28 ,
V_9 -> V_178 -> V_271 ) ;
F_123 ( & error -> V_207 ) ;
error -> V_272 = F_15 ( V_273 ) ;
error -> V_274 = F_15 ( V_275 ) ;
if ( F_11 ( V_9 ) )
error -> V_276 = F_15 ( V_153 ) | F_15 ( V_277 ) ;
else if ( F_9 ( V_9 ) )
error -> V_276 = F_15 ( V_277 ) | F_15 ( V_278 ) ;
else if ( F_124 ( V_9 ) )
error -> V_276 = F_125 ( V_279 ) ;
else
error -> V_276 = F_15 ( V_279 ) ;
F_58 ( V_5 )
error -> V_6 [ V_5 ] = F_15 ( F_6 ( V_5 ) ) ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> error = F_15 ( V_280 ) ;
error -> V_281 = F_15 ( V_282 ) ;
}
F_97 ( V_9 , error ) ;
F_118 ( V_9 , error ) ;
error -> V_211 = NULL ;
error -> V_283 = NULL ;
V_152 = 0 ;
F_37 (obj, &dev_priv->mm.active_list, mm_list)
V_152 ++ ;
error -> V_284 = V_152 ;
F_37 (obj, &dev_priv->mm.gtt_list, gtt_list)
if ( V_77 -> V_222 )
V_152 ++ ;
error -> V_285 = V_152 - error -> V_284 ;
error -> V_211 = NULL ;
error -> V_283 = NULL ;
if ( V_152 ) {
error -> V_211 = F_80 ( sizeof( * error -> V_211 ) * V_152 ,
V_196 ) ;
if ( error -> V_211 )
error -> V_283 =
error -> V_211 + error -> V_284 ;
}
if ( error -> V_211 )
error -> V_284 =
F_95 ( error -> V_211 ,
error -> V_284 ,
& V_1 -> V_182 . V_286 ) ;
if ( error -> V_283 )
error -> V_285 =
F_96 ( error -> V_283 ,
error -> V_285 ,
& V_1 -> V_182 . V_287 ) ;
F_126 ( & error -> time ) ;
error -> V_212 = F_127 ( V_9 ) ;
error -> V_288 = F_128 ( V_9 ) ;
F_10 ( & V_1 -> V_269 , V_44 ) ;
if ( V_1 -> V_270 == NULL ) {
V_1 -> V_270 = error ;
error = NULL ;
}
F_13 ( & V_1 -> V_269 , V_44 ) ;
if ( error )
F_91 ( & error -> V_207 ) ;
}
void F_129 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_206 * error ;
unsigned long V_44 ;
F_10 ( & V_1 -> V_269 , V_44 ) ;
error = V_1 -> V_270 ;
V_1 -> V_270 = NULL ;
F_13 ( & V_1 -> V_269 , V_44 ) ;
if ( error )
F_130 ( & error -> V_207 , F_91 ) ;
}
static void F_131 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
T_2 V_272 = F_15 ( V_273 ) ;
int V_5 ;
if ( ! V_272 )
return;
F_132 ( L_29 , V_272 ) ;
if ( F_133 ( V_9 ) ) {
if ( V_272 & ( V_289 | V_290 ) ) {
T_2 V_245 = F_15 ( V_291 ) ;
F_132 ( L_30 , F_15 ( V_291 ) ) ;
F_132 ( L_31 , F_15 ( V_292 ) ) ;
F_132 ( L_32 ,
F_15 ( V_293 ) ) ;
F_132 ( L_33 , F_15 ( V_294 ) ) ;
F_132 ( L_34 , F_15 ( V_250 ) ) ;
F_132 ( L_35 , F_15 ( V_295 ) ) ;
F_2 ( V_291 , V_245 ) ;
F_3 ( V_291 ) ;
}
if ( V_272 & V_296 ) {
T_2 V_297 = F_15 ( V_275 ) ;
F_132 ( L_36 ) ;
F_132 ( L_37 , V_297 ) ;
F_2 ( V_275 , V_297 ) ;
F_3 ( V_275 ) ;
}
}
if ( ! F_124 ( V_9 ) ) {
if ( V_272 & V_298 ) {
T_2 V_297 = F_15 ( V_275 ) ;
F_132 ( L_36 ) ;
F_132 ( L_37 , V_297 ) ;
F_2 ( V_275 , V_297 ) ;
F_3 ( V_275 ) ;
}
}
if ( V_272 & V_299 ) {
F_132 ( L_38 ) ;
F_58 (pipe)
F_132 ( L_39 ,
F_19 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
if ( V_272 & V_300 ) {
F_132 ( L_40 ) ;
F_132 ( L_41 , F_15 ( V_301 ) ) ;
if ( F_12 ( V_9 ) -> V_15 < 4 ) {
T_2 V_245 = F_15 ( V_254 ) ;
F_132 ( L_30 , F_15 ( V_254 ) ) ;
F_132 ( L_31 , F_15 ( V_255 ) ) ;
F_132 ( L_32 , F_15 ( V_256 ) ) ;
F_132 ( L_35 , F_15 ( V_302 ) ) ;
F_2 ( V_254 , V_245 ) ;
F_3 ( V_254 ) ;
} else {
T_2 V_245 = F_15 ( V_291 ) ;
F_132 ( L_30 , F_15 ( V_291 ) ) ;
F_132 ( L_31 , F_15 ( V_292 ) ) ;
F_132 ( L_32 ,
F_15 ( V_293 ) ) ;
F_132 ( L_33 , F_15 ( V_294 ) ) ;
F_132 ( L_34 , F_15 ( V_250 ) ) ;
F_132 ( L_35 , F_15 ( V_295 ) ) ;
F_2 ( V_291 , V_245 ) ;
F_3 ( V_291 ) ;
}
}
F_2 ( V_273 , V_272 ) ;
F_3 ( V_273 ) ;
V_272 = F_15 ( V_273 ) ;
if ( V_272 ) {
F_30 ( L_42 , V_272 ) ;
F_2 ( V_303 , F_15 ( V_303 ) | V_272 ) ;
F_2 ( V_304 , V_305 ) ;
}
}
void F_53 ( struct V_8 * V_9 , bool V_183 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_75 * V_76 ;
int V_152 ;
F_120 ( V_9 ) ;
F_131 ( V_9 ) ;
if ( V_183 ) {
F_134 ( V_1 -> V_184 ) ;
F_77 ( & V_1 -> V_182 . V_183 , 1 ) ;
F_119 (ring, dev_priv, i)
F_45 ( & V_76 -> V_79 ) ;
}
F_55 ( V_1 -> V_104 , & V_1 -> V_174 ) ;
}
static void F_135 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = V_9 -> V_10 ;
struct V_46 * V_47 = V_1 -> V_306 [ V_5 ] ;
struct V_307 * V_307 = F_136 ( V_47 ) ;
struct V_186 * V_77 ;
struct V_308 * V_53 ;
unsigned long V_44 ;
bool V_309 ;
if ( V_307 == NULL )
return;
F_10 ( & V_9 -> V_310 , V_44 ) ;
V_53 = V_307 -> V_311 ;
if ( V_53 == NULL || V_53 -> V_312 || ! V_53 -> V_313 ) {
F_13 ( & V_9 -> V_310 , V_44 ) ;
return;
}
V_77 = V_53 -> V_314 ;
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
int V_315 = F_137 ( V_307 -> V_316 ) ;
V_309 = F_138 ( F_15 ( V_315 ) ) ==
V_77 -> V_197 ;
} else {
int V_317 = F_139 ( V_307 -> V_316 ) ;
V_309 = F_15 ( V_317 ) == ( V_77 -> V_197 +
V_47 -> V_318 * V_47 -> V_319 -> V_320 [ 0 ] +
V_47 -> V_321 * V_47 -> V_319 -> V_322 / 8 ) ;
}
F_13 ( & V_9 -> V_310 , V_44 ) ;
if ( V_309 ) {
F_18 ( L_43 ) ;
F_66 ( V_9 , V_307 -> V_316 ) ;
}
}
static int F_140 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , V_5 ,
V_323 ) ;
else
F_5 ( V_1 , V_5 ,
V_324 ) ;
if ( V_1 -> V_325 -> V_15 == 3 )
F_2 ( V_301 , F_141 ( V_326 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_142 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 , ( V_5 == 0 ) ?
V_170 : V_171 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_143 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 ,
V_158 << ( 5 * V_5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_144 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_327 , V_328 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
V_327 = F_15 ( V_329 ) ;
V_328 = F_15 ( V_330 ) ;
if ( V_5 == 0 ) {
V_327 |= V_331 ;
V_328 &= ~ V_126 ;
} else {
V_327 |= V_331 ;
V_328 &= ~ V_127 ;
}
F_2 ( V_329 , V_327 ) ;
F_2 ( V_330 , V_328 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static void F_145 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_1 -> V_325 -> V_15 == 3 )
F_2 ( V_301 , F_146 ( V_326 ) ) ;
F_7 ( V_1 , V_5 ,
V_324 |
V_323 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_147 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 , ( V_5 == 0 ) ?
V_170 : V_171 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_148 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 ,
V_158 << ( V_5 * 5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_149 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_327 , V_328 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
V_327 = F_15 ( V_329 ) ;
V_328 = F_15 ( V_330 ) ;
if ( V_5 == 0 ) {
V_327 &= ~ V_331 ;
V_328 |= V_126 ;
} else {
V_327 &= ~ V_332 ;
V_328 |= V_127 ;
}
F_2 ( V_330 , V_328 ) ;
F_2 ( V_329 , V_327 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static T_2
F_150 ( struct V_75 * V_76 )
{
return F_151 ( V_76 -> V_333 . V_334 ,
struct V_263 , V_335 ) -> V_216 ;
}
static bool F_152 ( struct V_75 * V_76 , bool * V_214 )
{
if ( F_153 ( & V_76 -> V_333 ) ||
F_103 ( V_76 -> V_78 ( V_76 ) , F_150 ( V_76 ) ) ) {
if ( F_113 ( & V_76 -> V_79 ) ) {
F_30 ( L_44 ,
V_76 -> V_215 ) ;
F_45 ( & V_76 -> V_79 ) ;
* V_214 = true ;
}
return true ;
}
return false ;
}
static bool F_154 ( struct V_75 * V_76 )
{
struct V_8 * V_9 = V_76 -> V_9 ;
struct V_45 * V_1 = V_9 -> V_10 ;
T_2 V_336 = F_155 ( V_76 ) ;
if ( V_336 & V_337 ) {
F_30 ( L_45 ,
V_76 -> V_215 ) ;
F_156 ( V_76 , V_336 ) ;
return true ;
}
return false ;
}
static bool F_157 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
if ( V_1 -> V_81 ++ > 1 ) {
bool V_338 = true ;
F_30 ( L_46 ) ;
F_53 ( V_9 , true ) ;
if ( ! F_124 ( V_9 ) ) {
struct V_75 * V_76 ;
int V_152 ;
F_119 (ring, dev_priv, i)
V_338 &= ! F_154 ( V_76 ) ;
}
return V_338 ;
}
return false ;
}
void F_158 ( unsigned long V_339 )
{
struct V_8 * V_9 = (struct V_8 * ) V_339 ;
T_1 * V_1 = V_9 -> V_10 ;
T_7 V_259 [ V_340 ] , V_247 , V_249 ;
struct V_75 * V_76 ;
bool V_214 = false , V_341 ;
int V_152 ;
if ( ! V_80 )
return;
memset ( V_259 , 0 , sizeof( V_259 ) ) ;
V_341 = true ;
F_119 (ring, dev_priv, i) {
V_341 &= F_152 ( V_76 , & V_214 ) ;
V_259 [ V_152 ] = F_115 ( V_76 ) ;
}
if ( V_341 ) {
if ( V_214 ) {
if ( F_157 ( V_9 ) )
return;
goto V_342;
}
V_1 -> V_81 = 0 ;
return;
}
if ( F_12 ( V_9 ) -> V_15 < 4 ) {
V_247 = F_15 ( V_256 ) ;
V_249 = 0 ;
} else {
V_247 = F_15 ( V_293 ) ;
V_249 = F_15 ( V_250 ) ;
}
if ( memcmp ( V_1 -> V_343 , V_259 , sizeof( V_259 ) ) == 0 &&
V_1 -> V_344 == V_247 &&
V_1 -> V_345 == V_249 ) {
if ( F_157 ( V_9 ) )
return;
} else {
V_1 -> V_81 = 0 ;
memcpy ( V_1 -> V_343 , V_259 , sizeof( V_259 ) ) ;
V_1 -> V_344 = V_247 ;
V_1 -> V_345 = V_249 ;
}
V_342:
F_46 ( & V_1 -> V_82 ,
V_83 + F_47 ( V_84 ) ) ;
}
static void F_159 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_77 ( & V_1 -> V_113 , 0 ) ;
F_2 ( V_346 , 0xeffe ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_153 , 0x0 ) ;
F_3 ( V_153 ) ;
F_2 ( V_347 , 0xffffffff ) ;
F_2 ( V_277 , 0x0 ) ;
F_3 ( V_277 ) ;
F_2 ( V_348 , 0xffffffff ) ;
F_2 ( V_349 , 0x0 ) ;
F_3 ( V_349 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_77 ( & V_1 -> V_113 , 0 ) ;
F_2 ( V_330 , 0 ) ;
F_2 ( F_161 ( V_350 ) , 0 ) ;
F_2 ( F_161 ( V_351 ) , 0 ) ;
F_2 ( F_161 ( V_352 ) , 0 ) ;
F_2 ( V_117 , F_15 ( V_117 ) ) ;
F_2 ( V_117 , F_15 ( V_117 ) ) ;
F_2 ( V_347 , 0xffffffff ) ;
F_2 ( V_277 , 0x0 ) ;
F_3 ( V_277 ) ;
F_2 ( V_353 , 0xff ) ;
F_2 ( V_354 , 0 ) ;
F_2 ( V_124 , F_15 ( V_124 ) ) ;
F_58 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_116 , 0xffffffff ) ;
F_2 ( V_330 , 0xffffffff ) ;
F_2 ( V_278 , 0x0 ) ;
F_3 ( V_278 ) ;
}
static void F_162 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_355 ;
V_355 = F_15 ( V_356 ) ;
V_355 &= ~ ( V_357 | V_358 | V_359 ) ;
V_355 |= V_360 | V_361 ;
V_355 |= V_362 | V_363 ;
V_355 |= V_364 | V_365 ;
F_2 ( V_356 , V_355 ) ;
}
static int F_163 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_366 = V_154 | V_13 | V_172 |
V_168 | V_169 ;
T_2 V_367 ;
T_2 V_165 ;
V_1 -> V_3 = ~ V_366 ;
F_2 ( V_155 , F_15 ( V_155 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_153 , V_366 | V_170 | V_171 ) ;
F_3 ( V_153 ) ;
V_1 -> V_368 = ~ 0 ;
F_2 ( V_117 , F_15 ( V_117 ) ) ;
F_2 ( V_347 , V_1 -> V_368 ) ;
if ( F_70 ( V_9 ) )
V_367 =
V_162 |
V_97 |
V_99 ;
else
V_367 =
V_162 |
V_163 |
V_164 ;
F_2 ( V_277 , V_367 ) ;
F_3 ( V_277 ) ;
if ( F_71 ( V_9 ) ) {
V_165 = ( V_369 |
V_370 |
V_371 |
V_372 ) ;
} else {
V_165 = ( V_373 |
V_374 |
V_375 |
V_376 |
V_377 ) ;
}
V_1 -> V_378 = ~ V_165 ;
F_2 ( V_160 , F_15 ( V_160 ) ) ;
F_2 ( V_348 , V_1 -> V_378 ) ;
F_2 ( V_349 , V_165 ) ;
F_3 ( V_349 ) ;
F_162 ( V_9 ) ;
if ( F_164 ( V_9 ) ) {
F_2 ( V_155 , V_173 ) ;
F_2 ( V_153 , F_15 ( V_153 ) | V_173 ) ;
F_1 ( V_1 , V_173 ) ;
}
return 0 ;
}
static int F_165 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_366 =
V_154 | V_156 | V_159 |
V_379 |
V_380 |
V_157 ;
T_2 V_367 ;
T_2 V_165 ;
V_1 -> V_3 = ~ V_366 ;
F_2 ( V_155 , F_15 ( V_155 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_153 ,
V_366 |
V_381 |
V_382 |
V_158 ) ;
F_3 ( V_153 ) ;
V_1 -> V_368 = ~ 0 ;
F_2 ( V_117 , F_15 ( V_117 ) ) ;
F_2 ( V_347 , V_1 -> V_368 ) ;
V_367 = V_162 | V_97 |
V_99 ;
F_2 ( V_277 , V_367 ) ;
F_3 ( V_277 ) ;
V_165 = ( V_369 |
V_370 |
V_371 |
V_372 ) ;
V_1 -> V_378 = ~ V_165 ;
F_2 ( V_160 , F_15 ( V_160 ) ) ;
F_2 ( V_348 , V_1 -> V_378 ) ;
F_2 ( V_349 , V_165 ) ;
F_3 ( V_349 ) ;
F_162 ( V_9 ) ;
return 0 ;
}
static int F_166 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_367 ;
T_2 V_383 ;
T_2 V_384 = F_15 ( V_354 ) ;
T_8 V_385 ;
V_383 = V_122 ;
V_383 |= V_126 |
V_127 ;
V_1 -> V_3 = ~ V_383 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_167 ( V_1 -> V_9 -> V_386 , 0x94 , 0xfee00000 ) ;
F_168 ( V_9 -> V_386 , 0x98 , & V_385 ) ;
V_385 &= 0xff ;
V_385 |= ( 1 << 14 ) ;
F_169 ( V_1 -> V_9 -> V_386 , 0x98 , V_385 ) ;
F_2 ( V_330 , V_1 -> V_3 ) ;
F_2 ( V_278 , V_383 ) ;
F_2 ( V_116 , 0xffffffff ) ;
F_2 ( F_6 ( 0 ) , 0xffff ) ;
F_2 ( F_6 ( 1 ) , 0xffff ) ;
F_3 ( V_278 ) ;
F_2 ( V_116 , 0xffffffff ) ;
F_2 ( V_116 , 0xffffffff ) ;
V_367 = V_387 |
V_101 |
V_388 |
V_389 |
V_102 |
V_390 |
V_163 |
V_103 |
V_391 |
V_162 ;
V_1 -> V_368 = ~ V_367 ;
F_2 ( V_117 , F_15 ( V_117 ) ) ;
F_2 ( V_117 , F_15 ( V_117 ) ) ;
F_2 ( V_347 , 0 ) ;
F_2 ( V_277 , V_367 ) ;
F_3 ( V_277 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_2 ( V_392 , V_393 ) ;
#if 0
if (dev_priv->hotplug_supported_mask & HDMIB_HOTPLUG_INT_STATUS)
hotplug_en |= HDMIB_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & HDMIC_HOTPLUG_INT_STATUS)
hotplug_en |= HDMIC_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & HDMID_HOTPLUG_INT_STATUS)
hotplug_en |= HDMID_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & SDVOC_HOTPLUG_INT_STATUS)
hotplug_en |= SDVOC_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & SDVOB_HOTPLUG_INT_STATUS)
hotplug_en |= SDVOB_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & CRT_HOTPLUG_INT_STATUS) {
hotplug_en |= CRT_HOTPLUG_INT_EN;
hotplug_en |= CRT_HOTPLUG_VOLTAGE_COMPARE_50;
}
#endif
F_2 ( V_354 , V_384 ) ;
return 0 ;
}
static void F_170 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_58 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_346 , 0xffffffff ) ;
F_2 ( V_354 , 0 ) ;
F_2 ( V_124 , F_15 ( V_124 ) ) ;
F_58 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_116 , 0xffffffff ) ;
F_2 ( V_330 , 0xffffffff ) ;
F_2 ( V_278 , 0x0 ) ;
F_3 ( V_278 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( ! V_1 )
return;
F_2 ( V_346 , 0xffffffff ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_153 , 0x0 ) ;
F_2 ( V_155 , F_15 ( V_155 ) ) ;
F_2 ( V_347 , 0xffffffff ) ;
F_2 ( V_277 , 0x0 ) ;
F_2 ( V_117 , F_15 ( V_117 ) ) ;
F_2 ( V_348 , 0xffffffff ) ;
F_2 ( V_349 , 0x0 ) ;
F_2 ( V_160 , F_15 ( V_160 ) ) ;
}
static void F_172 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_77 ( & V_1 -> V_113 , 0 ) ;
F_58 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_41 ( V_394 , 0xffff ) ;
F_41 ( V_279 , 0x0 ) ;
F_173 ( V_279 ) ;
}
static int F_174 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_41 ( V_303 ,
~ ( V_298 | V_299 ) ) ;
V_1 -> V_3 =
~ ( V_395 |
V_396 |
V_397 |
V_398 |
V_305 ) ;
F_41 ( V_394 , V_1 -> V_3 ) ;
F_41 ( V_279 ,
V_395 |
V_396 |
V_305 |
V_399 ) ;
F_173 ( V_279 ) ;
return 0 ;
}
static T_4 F_175 ( T_5 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_8 V_106 , V_400 ;
T_2 V_108 [ 2 ] ;
unsigned long V_11 ;
int V_113 ;
int V_5 ;
T_8 V_401 =
V_397 |
V_398 ;
F_57 ( & V_1 -> V_113 ) ;
V_106 = F_125 ( V_304 ) ;
if ( V_106 == 0 )
return V_107 ;
while ( V_106 & ~ V_401 ) {
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_106 & V_305 )
F_53 ( V_9 , false ) ;
F_58 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_108 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_108 [ V_5 ] & 0x8000ffff ) {
if ( V_108 [ V_5 ] & V_121 )
F_18 ( L_8 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_108 [ V_5 ] ) ;
V_113 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_41 ( V_304 , V_106 & ~ V_401 ) ;
V_400 = F_125 ( V_304 ) ;
F_176 ( V_9 ) ;
if ( V_106 & V_399 )
F_43 ( V_9 , & V_1 -> V_76 [ V_96 ] ) ;
if ( V_108 [ 0 ] & V_115 &&
F_59 ( V_9 , 0 ) ) {
if ( V_106 & V_397 ) {
F_66 ( V_9 , 0 ) ;
F_60 ( V_9 , 0 ) ;
V_401 &= ~ V_397 ;
}
}
if ( V_108 [ 1 ] & V_115 &&
F_59 ( V_9 , 1 ) ) {
if ( V_106 & V_398 ) {
F_66 ( V_9 , 1 ) ;
F_60 ( V_9 , 1 ) ;
V_401 &= ~ V_398 ;
}
}
V_106 = V_400 ;
}
return V_120 ;
}
static void F_177 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_58 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
F_41 ( V_394 , 0xffff ) ;
F_41 ( V_279 , 0x0 ) ;
F_41 ( V_304 , F_125 ( V_304 ) ) ;
}
static void F_178 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_77 ( & V_1 -> V_113 , 0 ) ;
if ( F_179 ( V_9 ) ) {
F_2 ( V_354 , 0 ) ;
F_2 ( V_124 , F_15 ( V_124 ) ) ;
}
F_41 ( V_346 , 0xeffe ) ;
F_58 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_394 , 0xffffffff ) ;
F_2 ( V_279 , 0x0 ) ;
F_3 ( V_279 ) ;
}
static int F_180 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_383 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_2 ( V_303 , ~ ( V_298 | V_299 ) ) ;
V_1 -> V_3 =
~ ( V_402 |
V_395 |
V_396 |
V_397 |
V_398 |
V_305 ) ;
V_383 =
V_402 |
V_395 |
V_396 |
V_305 |
V_399 ;
if ( F_179 ( V_9 ) ) {
V_383 |= V_122 ;
V_1 -> V_3 &= ~ V_122 ;
}
F_2 ( V_394 , V_1 -> V_3 ) ;
F_2 ( V_279 , V_383 ) ;
F_3 ( V_279 ) ;
if ( F_179 ( V_9 ) ) {
T_2 V_384 = F_15 ( V_354 ) ;
if ( V_1 -> V_125 & V_403 )
V_384 |= V_404 ;
if ( V_1 -> V_125 & V_405 )
V_384 |= V_406 ;
if ( V_1 -> V_125 & V_407 )
V_384 |= V_408 ;
if ( V_1 -> V_125 & V_409 )
V_384 |= V_410 ;
if ( V_1 -> V_125 & V_411 )
V_384 |= V_412 ;
if ( V_1 -> V_125 & V_413 ) {
V_384 |= V_414 ;
V_384 |= V_415 ;
}
F_2 ( V_354 , V_384 ) ;
}
F_181 ( V_9 ) ;
return 0 ;
}
static T_4 F_182 ( T_5 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_106 , V_400 , V_108 [ V_109 ] ;
unsigned long V_11 ;
T_2 V_401 =
V_397 |
V_398 ;
T_2 V_416 [ 2 ] = {
V_397 ,
V_398
} ;
int V_5 , V_35 = V_107 ;
F_57 ( & V_1 -> V_113 ) ;
V_106 = F_15 ( V_304 ) ;
do {
bool V_113 = ( V_106 & ~ V_401 ) != 0 ;
bool V_112 = false ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_106 & V_305 )
F_53 ( V_9 , false ) ;
F_58 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_108 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_108 [ V_5 ] & 0x8000ffff ) {
if ( V_108 [ V_5 ] & V_121 )
F_18 ( L_8 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_108 [ V_5 ] ) ;
V_113 = true ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_113 )
break;
if ( ( F_179 ( V_9 ) ) &&
( V_106 & V_122 ) ) {
T_2 V_123 = F_15 ( V_124 ) ;
F_18 ( L_9 ,
V_123 ) ;
if ( V_123 & V_1 -> V_125 )
F_55 ( V_1 -> V_104 ,
& V_1 -> V_54 ) ;
F_2 ( V_124 , V_123 ) ;
F_3 ( V_124 ) ;
}
F_2 ( V_304 , V_106 & ~ V_401 ) ;
V_400 = F_15 ( V_304 ) ;
if ( V_106 & V_399 )
F_43 ( V_9 , & V_1 -> V_76 [ V_96 ] ) ;
F_58 (pipe) {
int V_316 = V_5 ;
if ( F_183 ( V_9 ) )
V_316 = ! V_316 ;
if ( V_108 [ V_5 ] & V_115 &&
F_59 ( V_9 , V_5 ) ) {
if ( V_106 & V_416 [ V_316 ] ) {
F_66 ( V_9 , V_316 ) ;
F_60 ( V_9 , V_5 ) ;
V_401 &= ~ V_416 [ V_316 ] ;
}
}
if ( V_108 [ V_5 ] & V_128 )
V_112 = true ;
}
if ( V_112 || ( V_106 & V_402 ) )
F_184 ( V_9 ) ;
V_35 = V_120 ;
V_106 = V_400 ;
} while ( V_106 & ~ V_401 );
F_176 ( V_9 ) ;
return V_35 ;
}
static void F_185 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( F_179 ( V_9 ) ) {
F_2 ( V_354 , 0 ) ;
F_2 ( V_124 , F_15 ( V_124 ) ) ;
}
F_41 ( V_346 , 0xffff ) ;
F_58 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
F_2 ( V_394 , 0xffffffff ) ;
F_2 ( V_279 , 0x0 ) ;
F_2 ( V_304 , F_15 ( V_304 ) ) ;
}
static void F_186 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_77 ( & V_1 -> V_113 , 0 ) ;
if ( F_179 ( V_9 ) ) {
F_2 ( V_354 , 0 ) ;
F_2 ( V_124 , F_15 ( V_124 ) ) ;
}
F_2 ( V_346 , 0xeffe ) ;
F_58 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_394 , 0xffffffff ) ;
F_2 ( V_279 , 0x0 ) ;
F_3 ( V_279 ) ;
}
static int F_187 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_383 ;
T_2 V_417 ;
V_1 -> V_3 = ~ ( V_402 |
V_395 |
V_396 |
V_397 |
V_398 |
V_305 ) ;
V_383 = ~ V_1 -> V_3 ;
V_383 |= V_399 ;
if ( F_133 ( V_9 ) )
V_383 |= V_418 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
if ( F_179 ( V_9 ) ) {
V_383 |= V_122 ;
V_1 -> V_3 &= ~ V_122 ;
}
if ( F_133 ( V_9 ) ) {
V_417 = ~ ( V_296 |
V_289 |
V_290 |
V_299 ) ;
} else {
V_417 = ~ ( V_298 |
V_299 ) ;
}
F_2 ( V_303 , V_417 ) ;
F_2 ( V_394 , V_1 -> V_3 ) ;
F_2 ( V_279 , V_383 ) ;
F_3 ( V_279 ) ;
if ( F_179 ( V_9 ) ) {
T_2 V_384 = F_15 ( V_354 ) ;
if ( V_1 -> V_125 & V_403 )
V_384 |= V_404 ;
if ( V_1 -> V_125 & V_405 )
V_384 |= V_406 ;
if ( V_1 -> V_125 & V_407 )
V_384 |= V_408 ;
if ( V_1 -> V_125 & V_409 )
V_384 |= V_410 ;
if ( V_1 -> V_125 & V_411 )
V_384 |= V_412 ;
if ( V_1 -> V_125 & V_413 ) {
V_384 |= V_414 ;
if ( F_133 ( V_9 ) )
V_384 |= V_419 ;
V_384 |= V_415 ;
}
F_2 ( V_354 , V_384 ) ;
}
F_181 ( V_9 ) ;
return 0 ;
}
static T_4 F_188 ( T_5 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_106 , V_400 ;
T_2 V_108 [ V_109 ] ;
unsigned long V_11 ;
int V_113 ;
int V_35 = V_107 , V_5 ;
F_57 ( & V_1 -> V_113 ) ;
V_106 = F_15 ( V_304 ) ;
for (; ; ) {
bool V_112 = false ;
V_113 = V_106 != 0 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_106 & V_305 )
F_53 ( V_9 , false ) ;
F_58 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_108 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_108 [ V_5 ] & 0x8000ffff ) {
if ( V_108 [ V_5 ] & V_121 )
F_18 ( L_8 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_108 [ V_5 ] ) ;
V_113 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_113 )
break;
V_35 = V_120 ;
if ( ( F_179 ( V_9 ) ) &&
( V_106 & V_122 ) ) {
T_2 V_123 = F_15 ( V_124 ) ;
F_18 ( L_9 ,
V_123 ) ;
if ( V_123 & V_1 -> V_125 )
F_55 ( V_1 -> V_104 ,
& V_1 -> V_54 ) ;
F_2 ( V_124 , V_123 ) ;
F_15 ( V_124 ) ;
}
F_2 ( V_304 , V_106 ) ;
V_400 = F_15 ( V_304 ) ;
if ( V_106 & V_399 )
F_43 ( V_9 , & V_1 -> V_76 [ V_96 ] ) ;
if ( V_106 & V_418 )
F_43 ( V_9 , & V_1 -> V_76 [ V_98 ] ) ;
if ( V_106 & V_397 )
F_66 ( V_9 , 0 ) ;
if ( V_106 & V_398 )
F_66 ( V_9 , 1 ) ;
F_58 (pipe) {
if ( V_108 [ V_5 ] & V_114 &&
F_59 ( V_9 , V_5 ) ) {
F_135 ( V_9 , V_5 ) ;
F_60 ( V_9 , V_5 ) ;
}
if ( V_108 [ V_5 ] & V_128 )
V_112 = true ;
}
if ( V_112 || ( V_106 & V_402 ) )
F_184 ( V_9 ) ;
V_106 = V_400 ;
}
F_176 ( V_9 ) ;
return V_35 ;
}
static void F_189 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
if ( F_179 ( V_9 ) ) {
F_2 ( V_354 , 0 ) ;
F_2 ( V_124 , F_15 ( V_124 ) ) ;
}
F_2 ( V_346 , 0xffffffff ) ;
F_58 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_394 , 0xffffffff ) ;
F_2 ( V_279 , 0x0 ) ;
F_58 (pipe)
F_2 ( F_6 ( V_5 ) ,
F_15 ( F_6 ( V_5 ) ) & 0x8000ffff ) ;
F_2 ( V_304 , F_15 ( V_304 ) ) ;
}
void F_190 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
F_191 ( & V_1 -> V_54 , F_34 ) ;
F_191 ( & V_1 -> V_174 , F_73 ) ;
F_191 ( & V_1 -> V_85 , F_48 ) ;
V_9 -> V_420 -> V_421 = F_17 ;
V_9 -> V_422 = 0xffffff ;
if ( F_133 ( V_9 ) || F_12 ( V_9 ) -> V_15 >= 5 ) {
V_9 -> V_422 = 0xffffffff ;
V_9 -> V_420 -> V_421 = F_22 ;
}
if ( F_192 ( V_9 , V_423 ) )
V_9 -> V_420 -> V_424 = F_29 ;
else
V_9 -> V_420 -> V_424 = NULL ;
V_9 -> V_420 -> V_425 = F_24 ;
if ( F_9 ( V_9 ) ) {
V_9 -> V_420 -> V_426 = F_56 ;
V_9 -> V_420 -> V_427 = F_160 ;
V_9 -> V_420 -> V_428 = F_166 ;
V_9 -> V_420 -> V_429 = F_170 ;
V_9 -> V_420 -> V_430 = F_144 ;
V_9 -> V_420 -> V_431 = F_149 ;
} else if ( F_193 ( V_9 ) ) {
V_9 -> V_420 -> V_426 = F_64 ;
V_9 -> V_420 -> V_427 = F_159 ;
V_9 -> V_420 -> V_428 = F_165 ;
V_9 -> V_420 -> V_429 = F_171 ;
V_9 -> V_420 -> V_430 = F_143 ;
V_9 -> V_420 -> V_431 = F_148 ;
} else if ( F_194 ( V_9 ) ) {
V_9 -> V_420 -> V_426 = F_64 ;
V_9 -> V_420 -> V_427 = F_159 ;
V_9 -> V_420 -> V_428 = F_165 ;
V_9 -> V_420 -> V_429 = F_171 ;
V_9 -> V_420 -> V_430 = F_143 ;
V_9 -> V_420 -> V_431 = F_148 ;
} else if ( F_11 ( V_9 ) ) {
V_9 -> V_420 -> V_426 = F_69 ;
V_9 -> V_420 -> V_427 = F_159 ;
V_9 -> V_420 -> V_428 = F_163 ;
V_9 -> V_420 -> V_429 = F_171 ;
V_9 -> V_420 -> V_430 = F_142 ;
V_9 -> V_420 -> V_431 = F_147 ;
} else {
if ( F_12 ( V_9 ) -> V_15 == 2 ) {
V_9 -> V_420 -> V_427 = F_172 ;
V_9 -> V_420 -> V_428 = F_174 ;
V_9 -> V_420 -> V_426 = F_175 ;
V_9 -> V_420 -> V_429 = F_177 ;
} else if ( F_12 ( V_9 ) -> V_15 == 3 ) {
F_2 ( V_432 , F_141 ( V_433 ) ) ;
V_9 -> V_420 -> V_427 = F_178 ;
V_9 -> V_420 -> V_428 = F_180 ;
V_9 -> V_420 -> V_429 = F_185 ;
V_9 -> V_420 -> V_426 = F_182 ;
} else {
V_9 -> V_420 -> V_427 = F_186 ;
V_9 -> V_420 -> V_428 = F_187 ;
V_9 -> V_420 -> V_429 = F_189 ;
V_9 -> V_420 -> V_426 = F_188 ;
}
V_9 -> V_420 -> V_430 = F_140 ;
V_9 -> V_420 -> V_431 = F_145 ;
}
}
