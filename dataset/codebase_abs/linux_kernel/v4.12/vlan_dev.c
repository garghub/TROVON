static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_10 * V_11 ;
unsigned int V_12 = 0 ;
T_1 V_13 = 0 ;
int V_14 ;
if ( ! ( V_9 -> V_15 & V_16 ) ) {
V_11 = (struct V_10 * ) F_2 ( V_2 , V_17 ) ;
V_13 = V_9 -> V_18 ;
V_13 |= F_3 ( V_4 , V_2 -> V_19 ) ;
V_11 -> V_20 = F_4 ( V_13 ) ;
if ( type != V_21 && type != V_22 )
V_11 -> V_23 = F_4 ( type ) ;
else
V_11 -> V_23 = F_4 ( V_7 ) ;
V_2 -> V_24 = V_9 -> V_25 ;
type = F_5 ( V_9 -> V_25 ) ;
V_12 = V_17 ;
}
if ( V_6 == NULL )
V_6 = V_4 -> V_26 ;
V_4 = V_9 -> V_27 ;
V_14 = F_6 ( V_2 , V_4 , type , V_5 , V_6 , V_7 + V_12 ) ;
if ( V_14 > 0 )
V_14 += V_12 ;
return V_14 ;
}
static inline T_2 F_7 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
#ifdef F_8
if ( V_9 -> V_28 )
F_9 ( V_9 -> V_28 , V_2 ) ;
#else
F_10 () ;
#endif
return V_29 ;
}
static T_2 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_30 * V_31 = (struct V_30 * ) ( V_2 -> V_32 ) ;
unsigned int V_7 ;
int V_33 ;
if ( V_31 -> V_34 != V_9 -> V_25 ||
V_9 -> V_15 & V_16 ) {
T_1 V_13 ;
V_13 = V_9 -> V_18 ;
V_13 |= F_3 ( V_4 , V_2 -> V_19 ) ;
F_12 ( V_2 , V_9 -> V_25 , V_13 ) ;
}
V_2 -> V_4 = V_9 -> V_27 ;
V_7 = V_2 -> V_7 ;
if ( F_13 ( F_14 ( V_4 ) ) )
return F_7 ( V_9 , V_2 ) ;
V_33 = F_15 ( V_2 ) ;
if ( F_16 ( V_33 == V_35 || V_33 == V_36 ) ) {
struct V_37 * V_38 ;
V_38 = F_17 ( V_9 -> V_37 ) ;
F_18 ( & V_38 -> V_39 ) ;
V_38 -> V_40 ++ ;
V_38 -> V_41 += V_7 ;
F_19 ( & V_38 -> V_39 ) ;
} else {
F_20 ( V_9 -> V_37 -> V_42 ) ;
}
return V_33 ;
}
static int F_21 ( struct V_3 * V_4 , int V_43 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
unsigned int V_44 = V_27 -> V_45 ;
if ( F_22 ( V_27 ) )
V_44 -= V_17 ;
if ( V_44 < V_43 )
return - V_46 ;
V_4 -> V_45 = V_43 ;
return 0 ;
}
void F_23 ( const struct V_3 * V_4 ,
T_3 V_47 , T_1 V_48 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
if ( V_9 -> V_49 [ V_48 & 0x7 ] && ! V_47 )
V_9 -> V_50 -- ;
else if ( ! V_9 -> V_49 [ V_48 & 0x7 ] && V_47 )
V_9 -> V_50 ++ ;
V_9 -> V_49 [ V_48 & 0x7 ] = V_47 ;
}
int F_24 ( const struct V_3 * V_4 ,
T_3 V_47 , T_1 V_48 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_51 * V_52 = NULL ;
struct V_51 * V_53 ;
T_3 V_54 = ( V_48 << V_55 ) & V_56 ;
V_52 = V_9 -> V_57 [ V_47 & 0xF ] ;
while ( V_52 ) {
if ( V_52 -> V_19 == V_47 ) {
if ( V_52 -> V_54 && ! V_54 )
V_9 -> V_58 -- ;
else if ( ! V_52 -> V_54 && V_54 )
V_9 -> V_58 ++ ;
V_52 -> V_54 = V_54 ;
return 0 ;
}
V_52 = V_52 -> V_59 ;
}
V_52 = V_9 -> V_57 [ V_47 & 0xF ] ;
V_53 = F_25 ( sizeof( struct V_51 ) , V_60 ) ;
if ( ! V_53 )
return - V_61 ;
V_53 -> V_59 = V_52 ;
V_53 -> V_19 = V_47 ;
V_53 -> V_54 = V_54 ;
F_26 () ;
V_9 -> V_57 [ V_47 & 0xF ] = V_53 ;
if ( V_54 )
V_9 -> V_58 ++ ;
return 0 ;
}
int F_27 ( const struct V_3 * V_4 , T_3 V_15 , T_3 V_62 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
T_3 V_63 = V_9 -> V_15 ;
if ( V_62 & ~ ( V_16 | V_64 |
V_65 | V_66 ) )
return - V_67 ;
V_9 -> V_15 = ( V_63 & ~ V_62 ) | ( V_15 & V_62 ) ;
if ( F_28 ( V_4 ) && ( V_9 -> V_15 ^ V_63 ) & V_64 ) {
if ( V_9 -> V_15 & V_64 )
F_29 ( V_4 ) ;
else
F_30 ( V_4 ) ;
}
if ( F_28 ( V_4 ) && ( V_9 -> V_15 ^ V_63 ) & V_66 ) {
if ( V_9 -> V_15 & V_66 )
F_31 ( V_4 ) ;
else
F_32 ( V_4 ) ;
}
return 0 ;
}
void F_33 ( const struct V_3 * V_4 , char * V_68 )
{
strncpy ( V_68 , V_8 ( V_4 ) -> V_27 -> V_69 , 23 ) ;
}
bool F_34 ( struct V_3 * V_4 ,
struct V_3 * V_27 )
{
if ( V_4 -> V_70 != V_71 )
return false ;
F_35 ( V_4 -> V_26 , V_27 -> V_26 ) ;
F_36 ( V_72 , V_4 ) ;
return true ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_3 * V_27 = V_9 -> V_27 ;
int V_73 ;
if ( ! ( V_27 -> V_15 & V_74 ) &&
! ( V_9 -> V_15 & V_65 ) )
return - V_75 ;
if ( ! F_38 ( V_4 -> V_26 , V_27 -> V_26 ) &&
! F_34 ( V_4 , V_27 ) ) {
V_73 = F_39 ( V_27 , V_4 -> V_26 ) ;
if ( V_73 < 0 )
goto V_76;
}
if ( V_4 -> V_15 & V_77 ) {
V_73 = F_40 ( V_27 , 1 ) ;
if ( V_73 < 0 )
goto V_78;
}
if ( V_4 -> V_15 & V_79 ) {
V_73 = F_41 ( V_27 , 1 ) ;
if ( V_73 < 0 )
goto V_80;
}
F_35 ( V_9 -> V_81 , V_27 -> V_26 ) ;
if ( V_9 -> V_15 & V_64 )
F_29 ( V_4 ) ;
if ( V_9 -> V_15 & V_66 )
F_31 ( V_4 ) ;
if ( F_42 ( V_27 ) )
F_43 ( V_4 ) ;
return 0 ;
V_80:
if ( V_4 -> V_15 & V_77 )
F_40 ( V_27 , - 1 ) ;
V_78:
if ( ! F_38 ( V_4 -> V_26 , V_27 -> V_26 ) )
F_44 ( V_27 , V_4 -> V_26 ) ;
V_76:
F_45 ( V_4 ) ;
return V_73 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_3 * V_27 = V_9 -> V_27 ;
F_47 ( V_27 , V_4 ) ;
F_48 ( V_27 , V_4 ) ;
if ( V_4 -> V_15 & V_77 )
F_40 ( V_27 , - 1 ) ;
if ( V_4 -> V_15 & V_79 )
F_41 ( V_27 , - 1 ) ;
if ( ! F_38 ( V_4 -> V_26 , V_27 -> V_26 ) )
F_44 ( V_27 , V_4 -> V_26 ) ;
F_45 ( V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , void * V_82 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
struct V_83 * V_84 = V_82 ;
int V_73 ;
if ( ! F_50 ( V_84 -> V_85 ) )
return - V_86 ;
if ( ! ( V_4 -> V_15 & V_74 ) )
goto V_76;
if ( ! F_38 ( V_84 -> V_85 , V_27 -> V_26 ) ) {
V_73 = F_39 ( V_27 , V_84 -> V_85 ) ;
if ( V_73 < 0 )
return V_73 ;
}
if ( ! F_38 ( V_4 -> V_26 , V_27 -> V_26 ) )
F_44 ( V_27 , V_4 -> V_26 ) ;
V_76:
F_35 ( V_4 -> V_26 , V_84 -> V_85 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , struct V_87 * V_88 , int V_89 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_90 * V_91 = V_27 -> V_92 ;
struct V_87 V_93 ;
int V_73 = - V_94 ;
strncpy ( V_93 . V_95 , V_27 -> V_69 , V_96 ) ;
V_93 . V_97 = V_88 -> V_97 ;
switch ( V_89 ) {
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
if ( F_52 ( V_27 ) && V_91 -> V_103 )
V_73 = V_91 -> V_103 ( V_27 , & V_93 , V_89 ) ;
break;
}
if ( ! V_73 )
V_88 -> V_97 = V_93 . V_97 ;
return V_73 ;
}
static int F_53 ( struct V_3 * V_4 , struct V_104 * V_105 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_90 * V_91 = V_27 -> V_92 ;
int V_73 = 0 ;
if ( F_52 ( V_27 ) && V_91 -> V_106 )
V_73 = V_91 -> V_106 ( V_27 , V_105 ) ;
return V_73 ;
}
static int F_54 ( struct V_3 * V_4 , T_1 V_107 ,
struct V_108 * V_109 , unsigned int V_110 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_90 * V_91 = V_27 -> V_92 ;
int V_14 = 0 ;
if ( V_91 -> V_111 )
V_14 = V_91 -> V_111 ( V_27 , V_107 , V_109 , V_110 ) ;
return V_14 ;
}
static int F_55 ( struct V_3 * V_4 , T_1 V_107 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_90 * V_91 = V_27 -> V_92 ;
int V_7 = 0 ;
if ( V_91 -> V_112 )
V_7 = V_91 -> V_112 ( V_27 , V_107 ) ;
return V_7 ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_90 * V_91 = V_27 -> V_92 ;
int V_14 = - V_67 ;
if ( V_91 -> V_113 )
V_14 = V_91 -> V_113 ( V_27 ) ;
return V_14 ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_90 * V_91 = V_27 -> V_92 ;
int V_14 = - V_67 ;
if ( V_91 -> V_114 )
V_14 = V_91 -> V_114 ( V_27 ) ;
return V_14 ;
}
static int F_58 ( struct V_3 * V_4 , T_4 * V_115 , int type )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_90 * V_91 = V_27 -> V_92 ;
int V_14 = - V_67 ;
if ( V_91 -> V_116 )
V_14 = V_91 -> V_116 ( V_27 , V_115 , type ) ;
return V_14 ;
}
static int F_59 ( struct V_3 * V_4 , T_1 V_107 ,
struct V_108 * V_109 , unsigned int V_110 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_90 * V_91 = V_27 -> V_92 ;
int V_14 = 0 ;
if ( V_91 -> V_117 )
V_14 = V_91 -> V_117 ( V_27 , V_107 , V_109 , V_110 ) ;
return V_14 ;
}
static void F_60 ( struct V_3 * V_4 , int V_118 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
if ( V_4 -> V_15 & V_74 ) {
if ( V_118 & V_77 )
F_40 ( V_27 , V_4 -> V_15 & V_77 ? 1 : - 1 ) ;
if ( V_118 & V_79 )
F_41 ( V_27 , V_4 -> V_15 & V_79 ? 1 : - 1 ) ;
}
}
static void F_61 ( struct V_3 * V_119 )
{
F_62 ( V_8 ( V_119 ) -> V_27 , V_119 ) ;
F_63 ( V_8 ( V_119 ) -> V_27 , V_119 ) ;
}
static void F_64 ( struct V_3 * V_4 ,
struct V_120 * V_121 ,
void * V_122 )
{
F_65 ( & V_121 -> V_123 ,
& V_124 ,
* ( int * ) V_122 ) ;
}
static void F_66 ( struct V_3 * V_4 , int V_125 )
{
F_65 ( & V_4 -> V_126 ,
& V_127 ,
V_125 ) ;
F_67 ( V_4 , F_64 , & V_125 ) ;
}
static int F_68 ( struct V_3 * V_4 )
{
return V_8 ( V_4 ) -> V_128 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_3 * V_27 = V_9 -> V_27 ;
if ( V_6 == NULL )
V_6 = V_4 -> V_26 ;
return F_6 ( V_2 , V_27 , type , V_5 , V_6 , V_7 ) ;
}
static int F_70 ( struct V_3 * V_4 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
F_45 ( V_4 ) ;
V_4 -> V_15 = V_27 -> V_15 & ~ ( V_74 | V_79 | V_77 |
V_129 | V_130 ) ;
V_4 -> V_131 = ( V_27 -> V_131 & ( ( 1 << V_132 ) |
( 1 << V_133 ) ) ) |
( 1 << V_134 ) ;
V_4 -> V_135 = V_136 | V_137 |
V_138 | V_139 |
V_140 | V_141 |
V_142 ;
V_4 -> V_143 |= V_4 -> V_135 | V_144 ;
V_4 -> V_145 = V_27 -> V_145 ;
V_4 -> V_146 = V_27 -> V_146 ;
if ( V_4 -> V_143 & V_147 )
F_71 ( V_27 , L_1 ) ;
V_4 -> V_148 = V_27 -> V_148 & ~ V_142 ;
V_4 -> V_149 = V_27 -> V_149 ;
if ( F_72 ( V_4 -> V_26 ) ) {
F_35 ( V_4 -> V_26 , V_27 -> V_26 ) ;
V_4 -> V_70 = V_71 ;
}
if ( F_72 ( V_4 -> V_150 ) )
memcpy ( V_4 -> V_150 , V_27 -> V_150 , V_4 -> V_151 ) ;
#if F_73 ( V_152 )
V_4 -> V_153 = V_27 -> V_153 ;
#endif
V_4 -> V_154 = V_27 -> V_154 ;
if ( F_74 ( V_27 -> V_143 ,
V_8 ( V_4 ) -> V_25 ) ) {
V_4 -> V_155 = & V_156 ;
V_4 -> V_157 = V_27 -> V_157 ;
} else {
V_4 -> V_155 = & V_158 ;
V_4 -> V_157 = V_27 -> V_157 + V_17 ;
}
V_4 -> V_92 = & V_159 ;
F_75 ( V_4 , & V_160 ) ;
F_66 ( V_4 , F_68 ( V_4 ) ) ;
V_8 ( V_4 ) -> V_37 = F_76 ( struct V_37 ) ;
if ( ! V_8 ( V_4 ) -> V_37 )
return - V_161 ;
return 0 ;
}
static void F_77 ( struct V_3 * V_4 )
{
struct V_51 * V_162 ;
struct V_8 * V_9 = V_8 ( V_4 ) ;
int V_163 ;
for ( V_163 = 0 ; V_163 < F_78 ( V_9 -> V_57 ) ; V_163 ++ ) {
while ( ( V_162 = V_9 -> V_57 [ V_163 ] ) != NULL ) {
V_9 -> V_57 [ V_163 ] = V_162 -> V_59 ;
F_79 ( V_162 ) ;
}
}
}
static T_5 F_80 ( struct V_3 * V_4 ,
T_5 V_143 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
T_5 V_164 = V_143 ;
T_5 V_165 ;
V_165 = F_81 ( ( V_27 -> V_148 |
V_166 ) ,
V_27 -> V_143 ) ;
if ( V_165 & ( V_167 | V_168 ) )
V_165 |= V_136 ;
V_143 = F_81 ( V_143 , V_165 ) ;
V_143 |= V_164 & ( V_169 | V_139 ) ;
V_143 |= V_144 ;
return V_143 ;
}
static int F_82 ( struct V_3 * V_4 ,
struct V_170 * V_89 )
{
const struct V_8 * V_9 = V_8 ( V_4 ) ;
return F_83 ( V_9 -> V_27 , V_89 ) ;
}
static void F_84 ( struct V_3 * V_4 ,
struct V_171 * V_172 )
{
F_85 ( V_172 -> V_173 , V_174 , sizeof( V_172 -> V_173 ) ) ;
F_85 ( V_172 -> V_175 , V_176 , sizeof( V_172 -> V_175 ) ) ;
F_85 ( V_172 -> V_177 , L_2 , sizeof( V_172 -> V_177 ) ) ;
}
static int F_86 ( struct V_3 * V_4 ,
struct V_178 * V_172 )
{
const struct V_8 * V_9 = V_8 ( V_4 ) ;
const struct V_179 * V_91 = V_9 -> V_27 -> V_179 ;
if ( V_91 -> V_180 ) {
return V_91 -> V_180 ( V_9 -> V_27 , V_172 ) ;
} else {
V_172 -> V_181 = V_182 |
V_183 ;
V_172 -> V_184 = - 1 ;
}
return 0 ;
}
static void F_87 ( struct V_3 * V_4 ,
struct V_185 * V_38 )
{
struct V_37 * V_82 ;
T_3 V_186 = 0 , V_42 = 0 ;
int V_163 ;
F_88 (i) {
T_4 V_187 , V_188 , V_189 , V_190 , V_191 ;
unsigned int V_192 ;
V_82 = F_89 ( V_8 ( V_4 ) -> V_37 , V_163 ) ;
do {
V_192 = F_90 ( & V_82 -> V_39 ) ;
V_187 = V_82 -> V_193 ;
V_188 = V_82 -> V_194 ;
V_189 = V_82 -> V_195 ;
V_190 = V_82 -> V_40 ;
V_191 = V_82 -> V_41 ;
} while ( F_91 ( & V_82 -> V_39 , V_192 ) );
V_38 -> V_193 += V_187 ;
V_38 -> V_194 += V_188 ;
V_38 -> V_196 += V_189 ;
V_38 -> V_40 += V_190 ;
V_38 -> V_41 += V_191 ;
V_186 += V_82 -> V_186 ;
V_42 += V_82 -> V_42 ;
}
V_38 -> V_186 = V_186 ;
V_38 -> V_42 = V_42 ;
}
static void F_92 ( struct V_3 * V_4 )
{
return;
}
static int F_93 ( struct V_3 * V_4 , struct V_197 * V_198 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_3 * V_27 = V_9 -> V_27 ;
struct V_28 * V_28 ;
int V_73 = 0 ;
V_28 = F_94 ( sizeof( * V_28 ) , V_60 ) ;
V_73 = - V_161 ;
if ( ! V_28 )
goto V_76;
V_73 = F_95 ( V_28 , V_27 ) ;
if ( V_73 ) {
F_79 ( V_28 ) ;
goto V_76;
}
V_9 -> V_28 = V_28 ;
V_76:
return V_73 ;
}
static void F_96 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_28 * V_28 = V_9 -> V_28 ;
if ( ! V_28 )
return;
V_9 -> V_28 = NULL ;
F_97 ( V_28 ) ;
}
static int F_98 ( const struct V_3 * V_4 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
return V_27 -> V_199 ;
}
static void F_99 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
F_100 ( V_9 -> V_37 ) ;
V_9 -> V_37 = NULL ;
}
void F_101 ( struct V_3 * V_4 )
{
F_102 ( V_4 ) ;
V_4 -> V_200 |= V_201 | V_202 ;
V_4 -> V_200 |= V_203 ;
V_4 -> V_200 &= ~ V_204 ;
F_103 ( V_4 ) ;
V_4 -> V_92 = & V_159 ;
V_4 -> V_205 = true ;
V_4 -> V_206 = F_99 ;
V_4 -> V_179 = & V_207 ;
V_4 -> V_208 = 0 ;
V_4 -> V_44 = V_209 ;
F_104 ( V_4 -> V_150 ) ;
}
