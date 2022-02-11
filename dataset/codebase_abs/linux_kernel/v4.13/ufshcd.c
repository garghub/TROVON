static inline enum V_1
F_1 ( enum V_2 V_3 )
{
return V_4 [ V_3 ] . V_5 ;
}
static inline enum V_6
F_2 ( enum V_2 V_3 )
{
return V_4 [ V_3 ] . V_7 ;
}
static inline enum V_2
F_3 ( enum V_1 V_5 ,
enum V_6 V_7 )
{
enum V_2 V_3 ;
for ( V_3 = V_8 ; V_3 < V_9 ; V_3 ++ ) {
if ( ( V_4 [ V_3 ] . V_5 == V_5 ) &&
( V_4 [ V_3 ] . V_7 == V_7 ) )
return V_3 ;
}
return V_8 ;
}
static inline bool F_4 ( struct V_10 * V_11 , int V_12 )
{
return V_12 >= 0 && V_12 < V_11 -> V_13 ;
}
static inline int F_5 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
if ( ! V_11 -> V_15 ) {
V_14 = F_6 ( V_11 -> V_16 , V_17 , V_18 , V_19 ,
V_11 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 , L_1 ,
V_21 , V_14 ) ;
V_11 -> V_15 = true ;
}
return V_14 ;
}
static inline void F_8 ( struct V_10 * V_11 )
{
if ( V_11 -> V_15 ) {
F_9 ( V_11 -> V_16 , V_11 ) ;
V_11 -> V_15 = false ;
}
}
static inline void F_10 ( char * V_22 )
{
if ( ! V_22 )
return;
if ( * V_22 < 0x20 || * V_22 > 0x7e )
* V_22 = ' ' ;
}
static void F_11 ( struct V_10 * V_11 ,
unsigned int V_12 , const char * V_23 )
{
T_1 V_24 = - 1 ;
T_2 V_25 = 0 ;
T_3 V_26 , V_27 ;
struct V_28 * V_29 ;
int V_30 = - 1 ;
if ( ! F_12 () )
return;
V_29 = & V_11 -> V_31 [ V_12 ] ;
if ( V_29 -> V_32 ) {
V_25 = ( T_2 ) ( * V_29 -> V_32 -> V_33 ) ;
if ( ( V_25 == V_34 ) || ( V_25 == V_35 ) ) {
if ( V_29 -> V_32 -> V_36 && V_29 -> V_32 -> V_36 -> V_37 )
V_24 =
V_29 -> V_32 -> V_36 -> V_37 -> V_38 . V_39 ;
V_30 = F_13 (
V_29 -> V_40 -> V_41 . V_42 ) ;
}
}
V_26 = F_14 ( V_11 , V_43 ) ;
V_27 = F_14 ( V_11 , V_44 ) ;
F_15 ( F_16 ( V_11 -> V_20 ) , V_23 , V_12 ,
V_27 , V_30 , V_26 , V_24 , V_25 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
if ( F_18 ( V_48 ) )
return;
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) && V_46 -> V_51 &&
V_46 -> V_52 )
F_7 ( V_11 -> V_20 , L_2 ,
V_46 -> V_53 , V_46 -> V_54 ) ;
}
}
static void F_21 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_57 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
int V_60 = ( V_58 + V_56 -> V_61 - 1 ) % V_59 ;
if ( V_56 -> V_62 [ V_60 ] == 0 )
continue;
F_7 ( V_11 -> V_20 , L_3 , V_57 , V_58 ,
V_56 -> V_62 [ V_60 ] , F_22 ( V_56 -> V_63 [ V_60 ] ) ) ;
}
}
static void F_23 ( struct V_10 * V_11 )
{
F_24 ( L_4 , V_11 -> V_64 , V_65 ) ;
F_7 ( V_11 -> V_20 , L_5 ,
V_11 -> V_66 , V_11 -> V_67 ) ;
F_7 ( V_11 -> V_20 ,
L_6 ,
( T_3 ) V_11 -> V_68 , ( T_3 ) V_11 -> V_69 ) ;
F_7 ( V_11 -> V_20 ,
L_7 ,
F_22 ( V_11 -> V_70 . V_71 ) ,
V_11 -> V_70 . V_72 ) ;
F_21 ( V_11 , & V_11 -> V_70 . V_73 , L_8 ) ;
F_21 ( V_11 , & V_11 -> V_70 . V_74 , L_9 ) ;
F_21 ( V_11 , & V_11 -> V_70 . V_75 , L_10 ) ;
F_21 ( V_11 , & V_11 -> V_70 . V_76 , L_11 ) ;
F_21 ( V_11 , & V_11 -> V_70 . V_77 , L_12 ) ;
F_17 ( V_11 ) ;
if ( V_11 -> V_78 && V_11 -> V_78 -> V_79 )
V_11 -> V_78 -> V_79 ( V_11 ) ;
}
static
void F_25 ( struct V_10 * V_11 , unsigned long V_80 , bool V_81 )
{
struct V_28 * V_29 ;
int V_82 ;
int V_12 ;
F_26 (tag, &bitmap, hba->nutrs) {
V_29 = & V_11 -> V_31 [ V_12 ] ;
F_7 ( V_11 -> V_20 , L_13 ,
V_12 , F_22 ( V_29 -> V_83 ) ) ;
F_7 ( V_11 -> V_20 ,
L_14 ,
V_12 , ( V_84 ) V_29 -> V_85 ) ;
F_24 ( L_15 , V_29 -> V_86 ,
sizeof( struct V_87 ) ) ;
F_7 ( V_11 -> V_20 , L_16 , V_12 ,
( V_84 ) V_29 -> V_88 ) ;
F_24 ( L_17 , V_29 -> V_40 ,
sizeof( struct V_89 ) ) ;
F_7 ( V_11 -> V_20 , L_18 , V_12 ,
( V_84 ) V_29 -> V_90 ) ;
F_24 ( L_19 , V_29 -> V_91 ,
sizeof( struct V_92 ) ) ;
V_82 = F_27 (
V_29 -> V_86 -> V_93 ) ;
F_7 ( V_11 -> V_20 ,
L_20 ,
V_12 , V_82 ,
( V_84 ) V_29 -> V_94 ) ;
if ( V_81 )
F_24 ( L_21 , V_29 -> V_95 ,
sizeof( struct V_96 ) * V_82 ) ;
}
}
static void F_28 ( struct V_10 * V_11 , unsigned long V_80 )
{
struct V_97 * V_98 ;
int V_12 ;
F_26 (tag, &bitmap, hba->nutmrs) {
V_98 = & V_11 -> V_99 [ V_12 ] ;
F_7 ( V_11 -> V_20 , L_22 , V_12 ) ;
F_24 ( L_23 , & V_98 -> V_100 ,
sizeof( struct V_101 ) ) ;
F_7 ( V_11 -> V_20 , L_24 ,
V_12 ) ;
F_24 ( L_25 , V_98 -> V_102 ,
sizeof( struct V_89 ) ) ;
F_7 ( V_11 -> V_20 , L_26 ,
V_12 ) ;
F_24 ( L_27 , V_98 -> V_103 ,
sizeof( struct V_97 ) ) ;
}
}
static void F_29 ( struct V_10 * V_11 )
{
F_7 ( V_11 -> V_20 , L_28 , V_11 -> V_104 ) ;
F_7 ( V_11 -> V_20 , L_29 ,
V_11 -> V_105 , V_11 -> V_69 , V_11 -> V_68 ) ;
F_7 ( V_11 -> V_20 , L_30 ,
V_11 -> V_106 , V_11 -> V_107 ) ;
F_7 ( V_11 -> V_20 , L_31 ,
V_11 -> V_108 , V_11 -> V_6 ) ;
F_7 ( V_11 -> V_20 , L_32 ,
V_11 -> V_109 , V_11 -> V_110 ) ;
F_7 ( V_11 -> V_20 , L_33 ,
V_11 -> V_111 , V_11 -> V_112 -> V_113 ) ;
F_7 ( V_11 -> V_20 , L_34 , V_11 -> V_114 . V_115 ) ;
F_7 ( V_11 -> V_20 , L_35 ,
V_11 -> V_116 , V_11 -> V_117 ) ;
F_7 ( V_11 -> V_20 , L_36 ,
V_11 -> V_67 , V_11 -> V_118 ) ;
F_7 ( V_11 -> V_20 , L_37 , V_11 -> V_119 ,
V_11 -> V_120 ) ;
}
static void F_30 ( struct V_10 * V_11 )
{
static const char * const V_121 [] = {
L_38 ,
L_39 ,
L_40 ,
L_38 ,
L_41 ,
L_42 ,
L_38 ,
} ;
F_7 ( V_11 -> V_20 , L_43 ,
V_21 ,
V_11 -> V_122 . V_123 , V_11 -> V_122 . V_124 ,
V_11 -> V_122 . V_125 , V_11 -> V_122 . V_126 ,
V_121 [ V_11 -> V_122 . V_127 ] ,
V_121 [ V_11 -> V_122 . V_128 ] ,
V_11 -> V_122 . V_129 ) ;
}
int F_31 ( struct V_10 * V_11 , T_3 V_62 , T_3 V_130 ,
T_3 V_22 , unsigned long V_131 ,
unsigned long V_132 , bool V_133 )
{
int V_134 = 0 ;
unsigned long V_135 = V_136 + F_32 ( V_132 ) ;
V_22 = V_22 & V_130 ;
while ( ( F_14 ( V_11 , V_62 ) & V_130 ) != V_22 ) {
if ( V_133 )
F_33 ( V_131 , V_131 + 50 ) ;
else
F_34 ( V_131 ) ;
if ( F_35 ( V_136 , V_135 ) ) {
if ( ( F_14 ( V_11 , V_62 ) & V_130 ) != V_22 )
V_134 = - V_137 ;
break;
}
}
return V_134 ;
}
static inline T_3 F_36 ( struct V_10 * V_11 )
{
T_3 V_138 = 0 ;
switch ( V_11 -> V_66 ) {
case V_139 :
V_138 = V_140 ;
break;
case V_141 :
case V_142 :
V_138 = V_143 ;
break;
case V_144 :
default:
V_138 = V_145 ;
break;
}
return V_138 ;
}
static inline T_3 F_37 ( struct V_10 * V_11 )
{
if ( V_11 -> V_119 & V_146 )
return F_38 ( V_11 ) ;
return F_14 ( V_11 , V_147 ) ;
}
static inline bool F_39 ( struct V_10 * V_11 )
{
return ( F_14 ( V_11 , V_148 ) &
V_149 ) ? true : false ;
}
static inline int F_40 ( struct V_28 * V_29 )
{
return F_41 ( V_29 -> V_86 -> V_100 . V_150 ) & V_151 ;
}
static inline int
F_42 ( struct V_97 * V_152 )
{
return F_41 ( V_152 -> V_100 . V_150 ) & V_151 ;
}
static bool F_43 ( struct V_10 * V_11 , int * V_153 )
{
int V_12 ;
bool V_14 = false ;
if ( ! V_153 )
goto V_154;
do {
V_12 = F_44 ( & V_11 -> V_155 , V_11 -> V_156 ) ;
if ( V_12 >= V_11 -> V_156 )
goto V_154;
} while ( F_45 ( V_12 , & V_11 -> V_155 ) );
* V_153 = V_12 ;
V_14 = true ;
V_154:
return V_14 ;
}
static inline void F_46 ( struct V_10 * V_11 , int V_157 )
{
F_47 ( V_157 , & V_11 -> V_155 ) ;
}
static inline void F_48 ( struct V_10 * V_11 , T_3 V_61 )
{
F_49 ( V_11 , ~ ( 1 << V_61 ) , V_158 ) ;
}
static inline void F_50 ( struct V_10 * V_11 , int V_12 )
{
F_51 ( V_12 , & V_11 -> V_68 ) ;
}
static inline int F_52 ( T_3 V_62 )
{
return ! ( ( V_62 & V_159 ) == V_159 ) ;
}
static inline int F_53 ( struct V_10 * V_11 )
{
return F_14 ( V_11 , V_160 ) &
V_161 ;
}
static inline T_3 F_54 ( struct V_10 * V_11 )
{
return F_14 ( V_11 , V_162 ) ;
}
static inline int
F_55 ( struct V_92 * V_91 )
{
return F_13 ( V_91 -> V_100 . V_163 ) >> 24 ;
}
static inline int
F_56 ( struct V_92 * V_91 )
{
return F_13 ( V_91 -> V_100 . V_164 ) & V_165 ;
}
static inline unsigned int
F_57 ( struct V_92 * V_91 )
{
return F_13 ( V_91 -> V_100 . V_150 ) &
V_166 ;
}
static inline bool F_58 ( struct V_92 * V_91 )
{
return F_13 ( V_91 -> V_100 . V_150 ) &
V_167 ? true : false ;
}
static inline void
F_59 ( struct V_10 * V_11 )
{
F_49 ( V_11 , V_168 |
V_169 ,
V_170 ) ;
}
static inline void
F_60 ( struct V_10 * V_11 , T_2 V_171 , T_2 V_172 )
{
F_49 ( V_11 , V_168 | V_173 |
F_61 ( V_171 ) |
F_62 ( V_172 ) ,
V_170 ) ;
}
static inline void F_63 ( struct V_10 * V_11 )
{
F_49 ( V_11 , 0 , V_170 ) ;
}
static void F_64 ( struct V_10 * V_11 )
{
F_49 ( V_11 , V_174 ,
V_175 ) ;
F_49 ( V_11 , V_176 ,
V_177 ) ;
}
static inline void F_65 ( struct V_10 * V_11 )
{
F_49 ( V_11 , V_178 , V_179 ) ;
}
static inline bool F_66 ( struct V_10 * V_11 )
{
return ( F_14 ( V_11 , V_179 ) & V_178 )
? false : true ;
}
static const char * F_67 (
enum V_6 V_115 )
{
switch ( V_115 ) {
case V_180 : return L_44 ;
case V_181 : return L_45 ;
case V_182 : return L_46 ;
default: return L_47 ;
}
}
static const char * F_68 (
enum V_1 V_115 )
{
switch ( V_115 ) {
case V_183 : return L_45 ;
case V_184 : return L_48 ;
case V_185 : return L_49 ;
default: return L_47 ;
}
}
T_3 F_69 ( struct V_10 * V_11 )
{
if ( ( V_11 -> V_66 == V_139 ) ||
( V_11 -> V_66 == V_141 ) )
return V_186 ;
else
return V_187 ;
}
static bool F_70 ( struct V_10 * V_11 )
{
if ( F_69 ( V_11 ) < V_187 )
return true ;
else
return false ;
}
static int F_71 ( struct V_10 * V_11 , bool V_188 )
{
int V_14 = 0 ;
struct V_45 * V_46 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
T_4 V_189 = F_72 () ;
bool V_190 = false ;
if ( F_18 ( V_48 ) )
goto V_154;
V_14 = F_73 ( V_11 , V_188 , V_191 ) ;
if ( V_14 )
return V_14 ;
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) ) {
if ( V_188 && V_46 -> V_52 ) {
if ( V_46 -> V_54 == V_46 -> V_52 )
continue;
V_190 = true ;
V_14 = F_74 ( V_46 -> V_50 , V_46 -> V_52 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_50 ,
V_21 , V_46 -> V_53 ,
V_46 -> V_52 , V_14 ) ;
break;
}
F_75 ( F_16 ( V_11 -> V_20 ) ,
L_51 , V_46 -> V_53 ,
V_46 -> V_54 ,
V_46 -> V_52 ) ;
V_46 -> V_54 = V_46 -> V_52 ;
} else if ( ! V_188 && V_46 -> V_51 ) {
if ( V_46 -> V_54 == V_46 -> V_51 )
continue;
V_190 = true ;
V_14 = F_74 ( V_46 -> V_50 , V_46 -> V_51 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_50 ,
V_21 , V_46 -> V_53 ,
V_46 -> V_51 , V_14 ) ;
break;
}
F_75 ( F_16 ( V_11 -> V_20 ) ,
L_52 , V_46 -> V_53 ,
V_46 -> V_54 ,
V_46 -> V_51 ) ;
V_46 -> V_54 = V_46 -> V_51 ;
}
}
F_76 ( V_11 -> V_20 , L_53 , V_21 ,
V_46 -> V_53 , F_77 ( V_46 -> V_50 ) ) ;
}
V_14 = F_73 ( V_11 , V_188 , V_192 ) ;
V_154:
if ( V_190 )
F_78 ( F_16 ( V_11 -> V_20 ) ,
( V_188 ? L_54 : L_55 ) ,
F_22 ( F_79 ( F_72 () , V_189 ) ) , V_14 ) ;
return V_14 ;
}
static bool F_80 ( struct V_10 * V_11 ,
bool V_188 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
if ( F_18 ( V_48 ) )
return false ;
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) ) {
if ( V_188 && V_46 -> V_52 ) {
if ( V_46 -> V_54 == V_46 -> V_52 )
continue;
return true ;
} else if ( ! V_188 && V_46 -> V_51 ) {
if ( V_46 -> V_54 == V_46 -> V_51 )
continue;
return true ;
}
}
}
return false ;
}
static int F_81 ( struct V_10 * V_11 ,
V_84 V_193 )
{
unsigned long V_194 ;
int V_14 = 0 ;
T_3 V_195 ;
T_3 V_196 ;
bool V_135 = false , V_197 = false ;
T_4 V_189 ;
F_82 ( V_11 , false ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_189 = F_72 () ;
do {
if ( V_11 -> V_104 != V_199 ) {
V_14 = - V_200 ;
goto V_154;
}
V_195 = F_14 ( V_11 , V_201 ) ;
V_196 = F_14 ( V_11 , V_44 ) ;
if ( ! V_195 && ! V_196 ) {
V_135 = false ;
break;
} else if ( V_197 ) {
break;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_85 () ;
if ( F_22 ( F_79 ( F_72 () , V_189 ) ) >
V_193 ) {
V_135 = true ;
V_197 = true ;
}
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
} while ( V_195 || V_196 );
if ( V_135 ) {
F_7 ( V_11 -> V_20 ,
L_56 ,
V_21 , V_195 , V_196 ) ;
V_14 = - V_200 ;
}
V_154:
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_86 ( V_11 ) ;
return V_14 ;
}
static int F_87 ( struct V_10 * V_11 , bool V_188 )
{
#define F_88 UFS_HS_G1
int V_14 = 0 ;
struct V_202 V_203 ;
if ( V_188 ) {
memcpy ( & V_203 , & V_11 -> V_204 . V_205 . V_206 ,
sizeof( struct V_202 ) ) ;
} else {
memcpy ( & V_203 , & V_11 -> V_122 ,
sizeof( struct V_202 ) ) ;
if ( V_11 -> V_122 . V_124 > F_88
|| V_11 -> V_122 . V_123 > F_88 ) {
memcpy ( & V_11 -> V_204 . V_205 . V_206 ,
& V_11 -> V_122 ,
sizeof( struct V_202 ) ) ;
V_203 . V_124 = F_88 ;
V_203 . V_123 = F_88 ;
}
}
V_14 = F_89 ( V_11 , & V_203 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 , L_57 ,
V_21 , V_14 ,
V_11 -> V_122 . V_124 , V_11 -> V_122 . V_123 ,
V_203 . V_124 , V_203 . V_123 ) ;
return V_14 ;
}
static int F_90 ( struct V_10 * V_11 )
{
#define F_91 (1000 * 1000)
int V_14 = 0 ;
F_92 ( V_11 -> V_112 ) ;
F_93 ( & V_11 -> V_207 ) ;
if ( F_81 ( V_11 , F_91 ) ) {
V_14 = - V_200 ;
F_94 ( & V_11 -> V_207 ) ;
F_95 ( V_11 -> V_112 ) ;
}
return V_14 ;
}
static void F_96 ( struct V_10 * V_11 )
{
F_94 ( & V_11 -> V_207 ) ;
F_95 ( V_11 -> V_112 ) ;
}
static int F_97 ( struct V_10 * V_11 , bool V_188 )
{
int V_14 = 0 ;
F_82 ( V_11 , false ) ;
V_14 = F_90 ( V_11 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_188 ) {
V_14 = F_87 ( V_11 , false ) ;
if ( V_14 )
goto V_154;
}
V_14 = F_71 ( V_11 , V_188 ) ;
if ( V_14 ) {
if ( ! V_188 )
F_87 ( V_11 , true ) ;
goto V_154;
}
if ( V_188 ) {
V_14 = F_87 ( V_11 , true ) ;
if ( V_14 ) {
F_71 ( V_11 , false ) ;
goto V_154;
}
}
V_14 = F_73 ( V_11 , V_188 , V_192 ) ;
V_154:
F_96 ( V_11 ) ;
F_86 ( V_11 ) ;
return V_14 ;
}
static void F_98 ( struct V_208 * V_209 )
{
struct V_10 * V_11 = F_99 ( V_209 , struct V_10 ,
V_204 . V_210 ) ;
unsigned long V_211 ;
F_83 ( V_11 -> V_112 -> V_198 , V_211 ) ;
if ( V_11 -> V_204 . V_212 || V_11 -> V_204 . V_213 ) {
F_84 ( V_11 -> V_112 -> V_198 , V_211 ) ;
return;
}
V_11 -> V_204 . V_213 = true ;
F_84 ( V_11 -> V_112 -> V_198 , V_211 ) ;
F_100 ( V_11 ) ;
}
static void F_101 ( struct V_208 * V_209 )
{
struct V_10 * V_11 = F_99 ( V_209 , struct V_10 ,
V_204 . V_214 ) ;
unsigned long V_211 ;
F_83 ( V_11 -> V_112 -> V_198 , V_211 ) ;
if ( ! V_11 -> V_204 . V_213 ) {
F_84 ( V_11 -> V_112 -> V_198 , V_211 ) ;
return;
}
V_11 -> V_204 . V_213 = false ;
F_84 ( V_11 -> V_112 -> V_198 , V_211 ) ;
F_102 ( V_11 -> V_215 ) ;
}
static int F_103 ( struct V_216 * V_20 ,
unsigned long * V_217 , T_3 V_194 )
{
int V_14 = 0 ;
struct V_10 * V_11 = F_104 ( V_20 ) ;
T_4 V_189 ;
bool V_188 , V_218 = false ;
unsigned long V_211 ;
if ( ! F_105 ( V_11 ) )
return - V_219 ;
if ( ( * V_217 > 0 ) && ( * V_217 < V_220 ) ) {
F_7 ( V_11 -> V_20 , L_58 , V_21 , * V_217 ) ;
return - V_219 ;
}
F_83 ( V_11 -> V_112 -> V_198 , V_211 ) ;
if ( F_106 ( V_11 ) ) {
F_84 ( V_11 -> V_112 -> V_198 , V_211 ) ;
return 0 ;
}
if ( ! V_11 -> V_204 . V_212 )
V_218 = true ;
V_188 = ( * V_217 == V_220 ) ? true : false ;
if ( ! F_80 ( V_11 , V_188 ) ) {
F_84 ( V_11 -> V_112 -> V_198 , V_211 ) ;
V_14 = 0 ;
goto V_154;
}
F_84 ( V_11 -> V_112 -> V_198 , V_211 ) ;
V_189 = F_72 () ;
V_14 = F_97 ( V_11 , V_188 ) ;
F_78 ( F_16 ( V_11 -> V_20 ) ,
( V_188 ? L_54 : L_55 ) ,
F_22 ( F_79 ( F_72 () , V_189 ) ) , V_14 ) ;
V_154:
if ( V_218 )
F_107 ( V_11 -> V_204 . V_221 ,
& V_11 -> V_204 . V_210 ) ;
return V_14 ;
}
static int F_108 ( struct V_216 * V_20 ,
struct V_222 * V_223 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
struct V_224 * V_225 = & V_11 -> V_204 ;
unsigned long V_194 ;
if ( ! F_105 ( V_11 ) )
return - V_219 ;
memset ( V_223 , 0 , sizeof( * V_223 ) ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( ! V_225 -> V_226 )
goto V_227;
if ( V_225 -> V_228 )
V_225 -> V_229 += F_22 ( F_79 ( F_72 () ,
V_225 -> V_230 ) ) ;
V_223 -> V_231 = F_109 ( ( long ) V_136 -
( long ) V_225 -> V_226 ) ;
V_223 -> V_232 = V_225 -> V_229 ;
V_227:
V_225 -> V_226 = V_136 ;
V_225 -> V_229 = 0 ;
if ( V_11 -> V_68 ) {
V_225 -> V_230 = F_72 () ;
V_225 -> V_228 = true ;
} else {
V_225 -> V_230 = 0 ;
V_225 -> V_228 = false ;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
return 0 ;
}
static void F_100 ( struct V_10 * V_11 )
{
unsigned long V_194 ;
F_110 ( V_11 -> V_215 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_204 . V_226 = 0 ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
}
static void F_111 ( struct V_10 * V_11 )
{
unsigned long V_194 ;
bool V_233 = false ;
if ( ! F_105 ( V_11 ) )
return;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( ! V_11 -> V_204 . V_213 ) {
V_233 = true ;
V_11 -> V_204 . V_213 = true ;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_233 )
F_100 ( V_11 ) ;
}
static void F_112 ( struct V_10 * V_11 )
{
unsigned long V_194 ;
bool V_234 = false ;
if ( ! F_105 ( V_11 ) )
return;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_11 -> V_204 . V_213 ) {
V_234 = true ;
V_11 -> V_204 . V_213 = false ;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_234 )
F_102 ( V_11 -> V_215 ) ;
}
static T_5 F_113 ( struct V_216 * V_20 ,
struct V_235 * V_236 , char * V_237 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
return snprintf ( V_237 , V_238 , L_59 , V_11 -> V_204 . V_239 ) ;
}
static T_5 F_114 ( struct V_216 * V_20 ,
struct V_235 * V_236 , const char * V_237 , T_6 V_240 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
T_3 V_241 ;
int V_134 ;
if ( F_115 ( V_237 , 0 , & V_241 ) )
return - V_219 ;
V_241 = ! ! V_241 ;
if ( V_241 == V_11 -> V_204 . V_239 )
goto V_154;
F_116 ( V_11 -> V_20 ) ;
F_82 ( V_11 , false ) ;
F_117 ( & V_11 -> V_204 . V_210 ) ;
F_117 ( & V_11 -> V_204 . V_214 ) ;
V_11 -> V_204 . V_239 = V_241 ;
if ( V_241 ) {
F_112 ( V_11 ) ;
} else {
F_111 ( V_11 ) ;
V_134 = F_97 ( V_11 , true ) ;
if ( V_134 )
F_7 ( V_11 -> V_20 , L_60 ,
V_21 , V_134 ) ;
}
F_86 ( V_11 ) ;
F_118 ( V_11 -> V_20 ) ;
V_154:
return V_240 ;
}
static void F_119 ( struct V_10 * V_11 )
{
V_11 -> V_204 . V_242 . V_243 = F_113 ;
V_11 -> V_204 . V_242 . V_244 = F_114 ;
F_120 ( & V_11 -> V_204 . V_242 . V_236 ) ;
V_11 -> V_204 . V_242 . V_236 . V_53 = L_61 ;
V_11 -> V_204 . V_242 . V_236 . V_245 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_204 . V_242 ) )
F_7 ( V_11 -> V_20 , L_62 ) ;
}
static void F_122 ( struct V_208 * V_209 )
{
int V_14 ;
unsigned long V_194 ;
struct V_10 * V_11 = F_99 ( V_209 , struct V_10 ,
V_114 . V_246 ) ;
F_123 ( & V_11 -> V_114 . V_247 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_11 -> V_114 . V_115 == V_248 ) {
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
goto V_249;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_124 ( V_11 , true ) ;
if ( F_125 ( V_11 ) ) {
V_11 -> V_114 . V_213 = true ;
if ( F_126 ( V_11 ) ) {
V_14 = F_127 ( V_11 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 , L_63 ,
V_21 , V_14 ) ;
else
F_128 ( V_11 ) ;
}
V_11 -> V_114 . V_213 = false ;
}
V_249:
F_95 ( V_11 -> V_112 ) ;
}
int F_82 ( struct V_10 * V_11 , bool V_250 )
{
int V_251 = 0 ;
unsigned long V_194 ;
if ( ! F_129 ( V_11 ) )
goto V_154;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_114 . V_212 ++ ;
if ( F_106 ( V_11 ) ) {
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
return 0 ;
}
V_189:
switch ( V_11 -> V_114 . V_115 ) {
case V_248 :
if ( F_125 ( V_11 ) &&
F_126 ( V_11 ) ) {
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_130 ( & V_11 -> V_114 . V_246 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
goto V_189;
}
break;
case V_252 :
if ( F_131 ( & V_11 -> V_114 . V_247 ) ) {
V_11 -> V_114 . V_115 = V_248 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
break;
}
case V_253 :
F_92 ( V_11 -> V_112 ) ;
V_11 -> V_114 . V_115 = V_254 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
F_133 ( & V_11 -> V_114 . V_246 ) ;
case V_254 :
if ( V_250 ) {
V_251 = - V_255 ;
V_11 -> V_114 . V_212 -- ;
break;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_130 ( & V_11 -> V_114 . V_246 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
goto V_189;
default:
F_7 ( V_11 -> V_20 , L_64 ,
V_21 , V_11 -> V_114 . V_115 ) ;
break;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_154:
return V_251 ;
}
static void F_134 ( struct V_208 * V_209 )
{
struct V_10 * V_11 = F_99 ( V_209 , struct V_10 ,
V_114 . V_247 . V_209 ) ;
unsigned long V_194 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_11 -> V_114 . V_213 ||
( V_11 -> V_114 . V_115 == V_254 ) ) {
V_11 -> V_114 . V_115 = V_248 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
goto V_256;
}
if ( V_11 -> V_114 . V_212
|| V_11 -> V_104 != V_199
|| V_11 -> V_105 || V_11 -> V_69
|| V_11 -> V_257 || V_11 -> V_258 )
goto V_256;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( F_125 ( V_11 ) ) {
if ( F_135 ( V_11 ) ) {
V_11 -> V_114 . V_115 = V_248 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
goto V_154;
}
F_136 ( V_11 ) ;
}
if ( ! F_137 ( V_11 ) )
F_124 ( V_11 , false ) ;
else
F_138 ( V_11 , false , true ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_11 -> V_114 . V_115 == V_252 ) {
V_11 -> V_114 . V_115 = V_253 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
}
V_256:
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_154:
return;
}
static void F_139 ( struct V_10 * V_11 )
{
if ( ! F_129 ( V_11 ) )
return;
V_11 -> V_114 . V_212 -- ;
if ( V_11 -> V_114 . V_212 || V_11 -> V_114 . V_213
|| V_11 -> V_104 != V_199
|| V_11 -> V_105 || V_11 -> V_69
|| V_11 -> V_257 || V_11 -> V_258
|| F_106 ( V_11 ) )
return;
V_11 -> V_114 . V_115 = V_252 ;
F_132 ( F_16 ( V_11 -> V_20 ) , V_11 -> V_114 . V_115 ) ;
F_140 ( & V_11 -> V_114 . V_247 ,
F_32 ( V_11 -> V_114 . V_259 ) ) ;
}
void F_86 ( struct V_10 * V_11 )
{
unsigned long V_194 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_139 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
}
static T_5 F_141 ( struct V_216 * V_20 ,
struct V_235 * V_236 , char * V_237 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
return snprintf ( V_237 , V_238 , L_65 , V_11 -> V_114 . V_259 ) ;
}
static T_5 F_142 ( struct V_216 * V_20 ,
struct V_235 * V_236 , const char * V_237 , T_6 V_240 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
unsigned long V_194 , V_241 ;
if ( F_143 ( V_237 , 0 , & V_241 ) )
return - V_219 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_114 . V_259 = V_241 ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
return V_240 ;
}
static T_5 F_144 ( struct V_216 * V_20 ,
struct V_235 * V_236 , char * V_237 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
return snprintf ( V_237 , V_238 , L_59 , V_11 -> V_114 . V_260 ) ;
}
static T_5 F_145 ( struct V_216 * V_20 ,
struct V_235 * V_236 , const char * V_237 , T_6 V_240 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
unsigned long V_194 ;
T_3 V_241 ;
if ( F_115 ( V_237 , 0 , & V_241 ) )
return - V_219 ;
V_241 = ! ! V_241 ;
if ( V_241 == V_11 -> V_114 . V_260 )
goto V_154;
if ( V_241 ) {
F_86 ( V_11 ) ;
} else {
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_114 . V_212 ++ ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
}
V_11 -> V_114 . V_260 = V_241 ;
V_154:
return V_240 ;
}
static void F_146 ( struct V_10 * V_11 )
{
if ( ! F_129 ( V_11 ) )
return;
V_11 -> V_114 . V_259 = 150 ;
F_147 ( & V_11 -> V_114 . V_247 , F_134 ) ;
F_148 ( & V_11 -> V_114 . V_246 , F_122 ) ;
V_11 -> V_114 . V_260 = true ;
V_11 -> V_114 . V_261 . V_243 = F_141 ;
V_11 -> V_114 . V_261 . V_244 = F_142 ;
F_120 ( & V_11 -> V_114 . V_261 . V_236 ) ;
V_11 -> V_114 . V_261 . V_236 . V_53 = L_66 ;
V_11 -> V_114 . V_261 . V_236 . V_245 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_114 . V_261 ) )
F_7 ( V_11 -> V_20 , L_67 ) ;
V_11 -> V_114 . V_242 . V_243 = F_144 ;
V_11 -> V_114 . V_242 . V_244 = F_145 ;
F_120 ( & V_11 -> V_114 . V_242 . V_236 ) ;
V_11 -> V_114 . V_242 . V_236 . V_53 = L_68 ;
V_11 -> V_114 . V_242 . V_236 . V_245 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_114 . V_242 ) )
F_7 ( V_11 -> V_20 , L_69 ) ;
}
static void F_149 ( struct V_10 * V_11 )
{
if ( ! F_129 ( V_11 ) )
return;
F_150 ( V_11 -> V_20 , & V_11 -> V_114 . V_261 ) ;
F_150 ( V_11 -> V_20 , & V_11 -> V_114 . V_242 ) ;
F_117 ( & V_11 -> V_114 . V_246 ) ;
F_123 ( & V_11 -> V_114 . V_247 ) ;
}
static void F_151 ( struct V_10 * V_11 )
{
bool V_262 = false ;
if ( ! F_105 ( V_11 ) )
return;
if ( ! V_11 -> V_204 . V_212 ++ )
V_262 = true ;
if ( ! V_11 -> V_204 . V_239 || V_11 -> V_109 )
return;
if ( V_262 )
F_107 ( V_11 -> V_204 . V_221 ,
& V_11 -> V_204 . V_214 ) ;
if ( ! V_11 -> V_204 . V_226 ) {
V_11 -> V_204 . V_226 = V_136 ;
V_11 -> V_204 . V_229 = 0 ;
V_11 -> V_204 . V_228 = false ;
}
if ( ! V_11 -> V_204 . V_228 ) {
V_11 -> V_204 . V_230 = F_72 () ;
V_11 -> V_204 . V_228 = true ;
}
}
static void F_152 ( struct V_10 * V_11 )
{
struct V_224 * V_225 = & V_11 -> V_204 ;
if ( ! F_105 ( V_11 ) )
return;
if ( ! V_11 -> V_68 && V_225 -> V_228 ) {
V_225 -> V_229 += F_22 ( F_79 ( F_72 () ,
V_225 -> V_230 ) ) ;
V_225 -> V_230 = 0 ;
V_225 -> V_228 = false ;
}
}
static inline
void F_153 ( struct V_10 * V_11 , unsigned int V_263 )
{
V_11 -> V_31 [ V_263 ] . V_83 = F_72 () ;
F_151 ( V_11 ) ;
F_154 ( V_263 , & V_11 -> V_68 ) ;
F_49 ( V_11 , 1 << V_263 , V_44 ) ;
F_155 () ;
F_11 ( V_11 , V_263 , L_70 ) ;
}
static inline void F_156 ( struct V_28 * V_29 )
{
int V_264 ;
if ( V_29 -> V_265 &&
F_57 ( V_29 -> V_91 ) ) {
int V_266 ;
V_264 = F_157 ( V_29 -> V_91 -> V_267 . V_268 ) ;
V_266 = F_158 ( int , V_269 , V_264 ) ;
memcpy ( V_29 -> V_265 ,
V_29 -> V_91 -> V_267 . V_270 ,
F_158 ( int , V_266 , V_271 ) ) ;
}
}
static
int F_159 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
struct V_272 * V_273 = & V_11 -> V_274 . V_275 . V_276 ;
memcpy ( & V_273 -> V_277 , & V_29 -> V_91 -> V_278 , V_279 ) ;
if ( V_29 -> V_91 -> V_278 . V_25 == V_280 ) {
T_2 * V_281 = ( T_2 * ) V_29 -> V_91 +
V_282 ;
T_7 V_283 ;
T_7 V_284 ;
V_283 = F_13 ( V_29 -> V_91 -> V_100 . V_150 ) &
V_285 ;
V_284 = F_157 (
V_11 -> V_274 . V_275 . V_36 . V_286 . V_287 ) ;
if ( F_160 ( V_284 >= V_283 ) ) {
memcpy ( V_11 -> V_274 . V_275 . V_288 , V_281 , V_283 ) ;
} else {
F_161 ( V_11 -> V_20 ,
L_71 ,
V_21 ) ;
return - V_219 ;
}
}
return 0 ;
}
static inline void F_162 ( struct V_10 * V_11 )
{
V_11 -> V_67 = F_14 ( V_11 , V_289 ) ;
V_11 -> V_13 = ( V_11 -> V_67 & V_290 ) + 1 ;
V_11 -> V_156 =
( ( V_11 -> V_67 & V_291 ) >> 16 ) + 1 ;
}
static inline bool F_163 ( struct V_10 * V_11 )
{
if ( F_14 ( V_11 , V_148 ) & V_292 )
return true ;
else
return false ;
}
static inline T_2 F_164 ( struct V_10 * V_11 )
{
return ( F_14 ( V_11 , V_148 ) >> 8 ) & 0x7 ;
}
static inline void
F_165 ( struct V_10 * V_11 , struct V_293 * V_294 )
{
F_166 ( V_11 -> V_257 ) ;
V_11 -> V_257 = V_294 ;
F_49 ( V_11 , V_294 -> V_295 , V_296 ) ;
F_49 ( V_11 , V_294 -> V_297 , V_160 ) ;
F_49 ( V_11 , V_294 -> V_298 , V_162 ) ;
F_49 ( V_11 , V_294 -> V_299 & V_300 ,
V_301 ) ;
}
static int
F_167 ( struct V_10 * V_11 , struct V_293 * V_294 )
{
int V_14 ;
unsigned long V_194 ;
if ( F_168 ( & V_294 -> V_302 ,
F_32 ( V_303 ) ) )
V_14 = V_294 -> V_297 & V_161 ;
else
V_14 = - V_137 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_257 = NULL ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
return V_14 ;
}
static int
F_169 ( struct V_10 * V_11 , struct V_293 * V_294 ,
bool V_304 )
{
if ( ! F_163 ( V_11 ) ) {
F_7 ( V_11 -> V_20 ,
L_72 ) ;
return - V_305 ;
}
if ( V_304 )
F_170 ( & V_294 -> V_302 ) ;
F_165 ( V_11 , V_294 ) ;
return 0 ;
}
static int
F_171 ( struct V_10 * V_11 , struct V_293 * V_294 )
{
int V_14 ;
unsigned long V_194 ;
F_82 ( V_11 , false ) ;
F_172 ( & V_11 -> V_306 ) ;
F_173 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_14 = F_169 ( V_11 , V_294 , true ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( ! V_14 )
V_14 = F_167 ( V_11 , V_294 ) ;
F_174 ( & V_11 -> V_306 ) ;
F_86 ( V_11 ) ;
return V_14 ;
}
static int F_175 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
struct V_96 * V_307 ;
struct V_308 * V_309 ;
struct V_310 * V_32 ;
int V_311 ;
int V_58 ;
V_32 = V_29 -> V_32 ;
V_311 = F_176 ( V_32 ) ;
if ( V_311 < 0 )
return V_311 ;
if ( V_311 ) {
if ( V_11 -> V_119 & V_312 )
V_29 -> V_86 -> V_93 =
F_177 ( ( T_7 ) ( V_311 *
sizeof( struct V_96 ) ) ) ;
else
V_29 -> V_86 -> V_93 =
F_177 ( ( T_7 ) ( V_311 ) ) ;
V_307 = (struct V_96 * ) V_29 -> V_95 ;
F_178 (cmd, sg, sg_segments, i) {
V_307 [ V_58 ] . V_313 =
F_179 ( ( ( T_3 ) F_180 ( V_309 ) ) - 1 ) ;
V_307 [ V_58 ] . V_314 =
F_179 ( F_181 ( V_309 -> V_315 ) ) ;
V_307 [ V_58 ] . V_316 =
F_179 ( F_182 ( V_309 -> V_315 ) ) ;
V_307 [ V_58 ] . V_317 = 0 ;
}
} else {
V_29 -> V_86 -> V_93 = 0 ;
}
return 0 ;
}
static void F_183 ( struct V_10 * V_11 , T_3 V_318 )
{
T_3 V_319 = F_14 ( V_11 , V_320 ) ;
if ( V_11 -> V_66 == V_139 ) {
T_3 V_321 ;
V_321 = V_319 & V_322 ;
V_319 = V_321 | ( ( V_319 ^ V_318 ) & V_318 ) ;
} else {
V_319 |= V_318 ;
}
F_49 ( V_11 , V_319 , V_320 ) ;
}
static void F_184 ( struct V_10 * V_11 , T_3 V_318 )
{
T_3 V_319 = F_14 ( V_11 , V_320 ) ;
if ( V_11 -> V_66 == V_139 ) {
T_3 V_321 ;
V_321 = ( V_319 & V_322 ) &
~ ( V_318 & V_322 ) ;
V_319 = V_321 | ( ( V_319 & V_318 ) & ~ V_322 ) ;
} else {
V_319 &= ~ V_318 ;
}
F_49 ( V_11 , V_319 , V_320 ) ;
}
static void F_185 ( struct V_28 * V_29 ,
T_3 * V_323 , enum V_324 V_325 )
{
struct V_87 * V_326 = V_29 -> V_86 ;
T_3 V_327 ;
T_3 V_163 ;
if ( V_325 == V_328 ) {
V_327 = V_329 ;
* V_323 = V_330 ;
} else if ( V_325 == V_331 ) {
V_327 = V_332 ;
* V_323 = V_333 ;
} else {
V_327 = V_334 ;
* V_323 = V_335 ;
}
V_163 = V_327 | ( V_29 -> V_336
<< V_337 ) ;
if ( V_29 -> V_338 )
V_163 |= V_339 ;
V_326 -> V_100 . V_163 = F_179 ( V_163 ) ;
V_326 -> V_100 . V_164 = 0 ;
V_326 -> V_100 . V_150 =
F_179 ( V_340 ) ;
V_326 -> V_100 . V_341 = 0 ;
V_326 -> V_93 = 0 ;
}
static
void F_186 ( struct V_28 * V_29 , T_3 V_323 )
{
struct V_89 * V_40 = V_29 -> V_40 ;
unsigned short V_342 ;
V_40 -> V_100 . V_163 = F_187 (
V_343 , V_323 ,
V_29 -> V_344 , V_29 -> V_263 ) ;
V_40 -> V_100 . V_164 = F_187 (
V_345 , 0 , 0 , 0 ) ;
V_40 -> V_100 . V_150 = 0 ;
V_40 -> V_41 . V_42 =
F_188 ( V_29 -> V_32 -> V_346 . V_287 ) ;
V_342 = F_158 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ;
memset ( V_40 -> V_41 . V_347 , 0 , V_348 ) ;
memcpy ( V_40 -> V_41 . V_347 , V_29 -> V_32 -> V_33 , V_342 ) ;
memset ( V_29 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
}
static void F_189 ( struct V_10 * V_11 ,
struct V_28 * V_29 , T_3 V_323 )
{
struct V_89 * V_40 = V_29 -> V_40 ;
struct V_349 * V_275 = & V_11 -> V_274 . V_275 ;
T_7 V_264 = F_157 ( V_275 -> V_36 . V_286 . V_287 ) ;
T_2 * V_281 = ( T_2 * ) V_29 -> V_40 + V_282 ;
V_40 -> V_100 . V_163 = F_187 (
V_350 , V_323 ,
V_29 -> V_344 , V_29 -> V_263 ) ;
V_40 -> V_100 . V_164 = F_187 (
0 , V_275 -> V_36 . V_351 , 0 , 0 ) ;
if ( V_275 -> V_36 . V_286 . V_25 == V_352 )
V_40 -> V_100 . V_150 =
F_187 ( 0 , 0 , ( V_264 >> 8 ) , ( T_2 ) V_264 ) ;
else
V_40 -> V_100 . V_150 = 0 ;
memcpy ( & V_40 -> V_278 , & V_275 -> V_36 . V_286 ,
V_279 ) ;
if ( V_275 -> V_36 . V_286 . V_25 == V_352 )
memcpy ( V_281 , V_275 -> V_288 , V_264 ) ;
memset ( V_29 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
}
static inline void F_190 ( struct V_28 * V_29 )
{
struct V_89 * V_40 = V_29 -> V_40 ;
memset ( V_40 , 0 , sizeof( struct V_89 ) ) ;
V_40 -> V_100 . V_163 =
F_187 (
V_353 , 0 , 0 , V_29 -> V_263 ) ;
V_40 -> V_100 . V_164 = 0 ;
V_40 -> V_100 . V_150 = 0 ;
memset ( V_29 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
}
static int F_191 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
T_3 V_323 ;
int V_14 = 0 ;
if ( V_11 -> V_66 == V_142 )
V_29 -> V_336 = V_354 ;
else
V_29 -> V_336 = V_355 ;
F_185 ( V_29 , & V_323 , V_356 ) ;
if ( V_11 -> V_274 . type == V_357 )
F_189 ( V_11 , V_29 , V_323 ) ;
else if ( V_11 -> V_274 . type == V_358 )
F_190 ( V_29 ) ;
else
V_14 = - V_219 ;
return V_14 ;
}
static int F_192 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
T_3 V_323 ;
int V_14 = 0 ;
if ( V_11 -> V_66 == V_142 )
V_29 -> V_336 = V_354 ;
else
V_29 -> V_336 = V_359 ;
if ( F_160 ( V_29 -> V_32 ) ) {
F_185 ( V_29 , & V_323 ,
V_29 -> V_32 -> V_360 ) ;
F_186 ( V_29 , V_323 ) ;
} else {
V_14 = - V_219 ;
}
return V_14 ;
}
static inline T_2 F_193 ( unsigned int V_361 )
{
if ( F_194 ( V_361 ) )
return ( V_361 & V_362 )
| V_363 ;
else
return V_361 & V_362 ;
}
static inline T_7 F_195 ( T_2 V_364 )
{
return ( V_364 & ~ V_363 ) | V_365 ;
}
static int F_196 ( struct V_366 * V_112 , struct V_310 * V_32 )
{
struct V_28 * V_29 ;
struct V_10 * V_11 ;
unsigned long V_194 ;
int V_12 ;
int V_134 = 0 ;
V_11 = F_197 ( V_112 ) ;
V_12 = V_32 -> V_36 -> V_12 ;
if ( ! F_4 ( V_11 , V_12 ) ) {
F_7 ( V_11 -> V_20 ,
L_73 ,
V_21 , V_12 , V_32 , V_32 -> V_36 ) ;
F_198 () ;
}
if ( ! F_199 ( & V_11 -> V_207 ) )
return V_367 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
switch ( V_11 -> V_104 ) {
case V_199 :
break;
case V_368 :
case V_369 :
V_134 = V_367 ;
goto V_370;
case V_371 :
F_200 ( V_32 , V_372 ) ;
V_32 -> V_373 ( V_32 ) ;
goto V_370;
default:
F_201 ( V_11 -> V_20 , 1 , L_74 ,
V_21 , V_11 -> V_104 ) ;
F_200 ( V_32 , V_374 ) ;
V_32 -> V_373 ( V_32 ) ;
goto V_370;
}
if ( F_106 ( V_11 ) ) {
F_200 ( V_32 , V_372 ) ;
V_32 -> V_373 ( V_32 ) ;
goto V_370;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_117 = 0 ;
if ( F_45 ( V_12 , & V_11 -> V_105 ) ) {
V_134 = V_367 ;
goto V_154;
}
V_134 = F_82 ( V_11 , true ) ;
if ( V_134 ) {
V_134 = V_367 ;
F_47 ( V_12 , & V_11 -> V_105 ) ;
goto V_154;
}
F_166 ( V_11 -> V_114 . V_115 != V_248 ) ;
V_29 = & V_11 -> V_31 [ V_12 ] ;
F_166 ( V_29 -> V_32 ) ;
V_29 -> V_32 = V_32 ;
V_29 -> V_375 = V_271 ;
V_29 -> V_265 = V_32 -> V_265 ;
V_29 -> V_263 = V_12 ;
V_29 -> V_344 = F_193 ( V_32 -> V_216 -> V_344 ) ;
V_29 -> V_338 = ! F_202 ( V_11 ) ? true : false ;
V_29 -> V_376 = false ;
F_192 ( V_11 , V_29 ) ;
V_134 = F_175 ( V_11 , V_29 ) ;
if ( V_134 ) {
V_29 -> V_32 = NULL ;
F_47 ( V_12 , & V_11 -> V_105 ) ;
goto V_154;
}
F_155 () ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_203 ( V_11 , V_12 , ( V_29 -> V_32 ? true : false ) ) ;
F_153 ( V_11 , V_12 ) ;
V_370:
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_154:
F_204 ( & V_11 -> V_207 ) ;
return V_134 ;
}
static int F_205 ( struct V_10 * V_11 ,
struct V_28 * V_29 , enum V_377 V_378 , int V_12 )
{
V_29 -> V_32 = NULL ;
V_29 -> V_375 = 0 ;
V_29 -> V_265 = NULL ;
V_29 -> V_263 = V_12 ;
V_29 -> V_344 = 0 ;
V_29 -> V_338 = true ;
V_11 -> V_274 . type = V_378 ;
return F_191 ( V_11 , V_29 ) ;
}
static int
F_206 ( struct V_10 * V_11 , int V_12 )
{
int V_134 = 0 ;
unsigned long V_194 ;
T_3 V_130 = 1 << V_12 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_48 ( V_11 , V_12 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_134 = F_31 ( V_11 ,
V_44 ,
V_130 , ~ V_130 , 1000 , 1000 , true ) ;
return V_134 ;
}
static int
F_207 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
struct V_272 * V_273 = & V_11 -> V_274 . V_275 . V_276 ;
V_273 -> V_276 = F_56 ( V_29 -> V_91 ) >>
V_379 ;
return V_273 -> V_276 ;
}
static int
F_208 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
int V_380 ;
int V_134 = 0 ;
V_11 -> V_70 . V_71 = F_209 ( 0 , 0 ) ;
V_380 = F_55 ( V_29 -> V_91 ) ;
switch ( V_380 ) {
case V_381 :
if ( V_11 -> V_274 . type != V_358 ) {
V_134 = - V_219 ;
F_7 ( V_11 -> V_20 , L_75 ,
V_21 , V_380 ) ;
}
break;
case V_382 :
V_134 = F_207 ( V_11 , V_29 ) ;
if ( ! V_134 )
V_134 = F_159 ( V_11 , V_29 ) ;
break;
case V_383 :
V_134 = - V_384 ;
F_7 ( V_11 -> V_20 , L_76 ,
V_21 ) ;
break;
default:
V_134 = - V_219 ;
F_7 ( V_11 -> V_20 , L_77 ,
V_21 , V_380 ) ;
break;
}
return V_134 ;
}
static int F_210 ( struct V_10 * V_11 ,
struct V_28 * V_29 , int V_385 )
{
int V_134 = 0 ;
unsigned long V_386 ;
unsigned long V_194 ;
V_386 = F_168 ( V_11 -> V_274 . V_387 ,
F_32 ( V_385 ) ) ;
F_155 () ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_274 . V_387 = NULL ;
if ( F_160 ( V_386 ) ) {
V_134 = F_40 ( V_29 ) ;
if ( ! V_134 )
V_134 = F_208 ( V_11 , V_29 ) ;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( ! V_386 ) {
V_134 = - V_137 ;
F_76 ( V_11 -> V_20 , L_78 ,
V_21 , V_29 -> V_263 ) ;
if ( ! F_206 ( V_11 , V_29 -> V_263 ) )
V_134 = - V_255 ;
F_50 ( V_11 , V_29 -> V_263 ) ;
}
return V_134 ;
}
static bool F_211 ( struct V_10 * V_11 , int * V_388 )
{
int V_12 ;
bool V_14 = false ;
unsigned long V_389 ;
if ( ! V_388 )
goto V_154;
do {
V_389 = ~ V_11 -> V_105 ;
V_12 = F_212 ( & V_389 , V_11 -> V_13 ) ;
if ( V_12 >= V_11 -> V_13 )
goto V_154;
} while ( F_45 ( V_12 , & V_11 -> V_105 ) );
* V_388 = V_12 ;
V_14 = true ;
V_154:
return V_14 ;
}
static inline void F_213 ( struct V_10 * V_11 , int V_12 )
{
F_47 ( V_12 , & V_11 -> V_105 ) ;
}
static int F_214 ( struct V_10 * V_11 ,
enum V_377 V_378 , int V_135 )
{
struct V_28 * V_29 ;
int V_134 ;
int V_12 ;
struct V_304 V_390 ;
unsigned long V_194 ;
F_215 ( & V_11 -> V_207 ) ;
F_216 ( V_11 -> V_274 . V_391 , F_211 ( V_11 , & V_12 ) ) ;
F_170 ( & V_390 ) ;
V_29 = & V_11 -> V_31 [ V_12 ] ;
F_166 ( V_29 -> V_32 ) ;
V_134 = F_205 ( V_11 , V_29 , V_378 , V_12 ) ;
if ( F_217 ( V_134 ) )
goto V_392;
V_11 -> V_274 . V_387 = & V_390 ;
F_155 () ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_203 ( V_11 , V_12 , ( V_29 -> V_32 ? true : false ) ) ;
F_153 ( V_11 , V_12 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_134 = F_210 ( V_11 , V_29 , V_135 ) ;
V_392:
F_213 ( V_11 , V_12 ) ;
F_218 ( & V_11 -> V_274 . V_391 ) ;
F_204 ( & V_11 -> V_207 ) ;
return V_134 ;
}
static inline void F_219 ( struct V_10 * V_11 ,
struct V_393 * * V_36 , struct V_272 * * V_276 ,
enum V_394 V_25 , T_2 V_395 , T_2 V_396 , T_2 V_397 )
{
* V_36 = & V_11 -> V_274 . V_275 . V_36 ;
* V_276 = & V_11 -> V_274 . V_275 . V_276 ;
memset ( * V_36 , 0 , sizeof( struct V_393 ) ) ;
memset ( * V_276 , 0 , sizeof( struct V_272 ) ) ;
( * V_36 ) -> V_286 . V_25 = V_25 ;
( * V_36 ) -> V_286 . V_395 = V_395 ;
( * V_36 ) -> V_286 . V_396 = V_396 ;
( * V_36 ) -> V_286 . V_397 = V_397 ;
}
static int F_220 ( struct V_10 * V_11 ,
enum V_394 V_25 , enum V_398 V_395 , bool * V_399 )
{
int V_14 ;
int V_400 ;
for ( V_400 = 0 ; V_400 < V_401 ; V_400 ++ ) {
V_14 = F_221 ( V_11 , V_25 , V_395 , V_399 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 ,
L_79 ,
V_21 , V_14 , V_400 ) ;
else
break;
}
if ( V_14 )
F_7 ( V_11 -> V_20 ,
L_80 ,
V_21 , V_25 , V_395 , V_14 , V_400 ) ;
return V_14 ;
}
int F_221 ( struct V_10 * V_11 , enum V_394 V_25 ,
enum V_398 V_395 , bool * V_399 )
{
struct V_393 * V_36 = NULL ;
struct V_272 * V_276 = NULL ;
int V_134 , V_396 = 0 , V_397 = 0 ;
int V_135 = V_402 ;
F_222 ( ! V_11 ) ;
F_82 ( V_11 , false ) ;
F_172 ( & V_11 -> V_274 . V_403 ) ;
F_219 ( V_11 , & V_36 , & V_276 , V_25 , V_395 , V_396 ,
V_397 ) ;
switch ( V_25 ) {
case V_404 :
case V_405 :
case V_406 :
V_36 -> V_351 = V_407 ;
break;
case V_408 :
V_36 -> V_351 = V_409 ;
if ( ! V_399 ) {
F_7 ( V_11 -> V_20 , L_81 ,
V_21 ) ;
V_134 = - V_219 ;
goto V_370;
}
break;
default:
F_7 ( V_11 -> V_20 ,
L_82 ,
V_21 , V_25 ) ;
V_134 = - V_219 ;
goto V_370;
}
V_134 = F_214 ( V_11 , V_357 , V_135 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 ,
L_83 ,
V_21 , V_395 , V_134 ) ;
goto V_370;
}
if ( V_399 )
* V_399 = ( F_13 ( V_276 -> V_277 . V_241 ) &
V_410 ) & 0x1 ;
V_370:
F_174 ( & V_11 -> V_274 . V_403 ) ;
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_223 ( struct V_10 * V_11 , enum V_394 V_25 ,
enum V_411 V_395 , T_2 V_396 , T_2 V_397 , T_3 * V_412 )
{
struct V_393 * V_36 = NULL ;
struct V_272 * V_276 = NULL ;
int V_134 ;
F_222 ( ! V_11 ) ;
F_82 ( V_11 , false ) ;
if ( ! V_412 ) {
F_7 ( V_11 -> V_20 , L_84 ,
V_21 , V_25 ) ;
V_134 = - V_219 ;
goto V_154;
}
F_172 ( & V_11 -> V_274 . V_403 ) ;
F_219 ( V_11 , & V_36 , & V_276 , V_25 , V_395 , V_396 ,
V_397 ) ;
switch ( V_25 ) {
case V_413 :
V_36 -> V_351 = V_407 ;
V_36 -> V_286 . V_241 = F_188 ( * V_412 ) ;
break;
case V_414 :
V_36 -> V_351 = V_409 ;
break;
default:
F_7 ( V_11 -> V_20 , L_85 ,
V_21 , V_25 ) ;
V_134 = - V_219 ;
goto V_370;
}
V_134 = F_214 ( V_11 , V_357 , V_402 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_86 ,
V_21 , V_25 , V_395 , V_396 , V_134 ) ;
goto V_370;
}
* V_412 = F_13 ( V_276 -> V_277 . V_241 ) ;
V_370:
F_174 ( & V_11 -> V_274 . V_403 ) ;
V_154:
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_224 ( struct V_10 * V_11 ,
enum V_394 V_25 , enum V_411 V_395 , T_2 V_396 , T_2 V_397 ,
T_3 * V_412 )
{
int V_14 = 0 ;
T_3 V_400 ;
for ( V_400 = V_401 ; V_400 > 0 ; V_400 -- ) {
V_14 = F_223 ( V_11 , V_25 , V_395 , V_396 ,
V_397 , V_412 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 , L_79 ,
V_21 , V_14 , V_400 ) ;
else
break;
}
if ( V_14 )
F_7 ( V_11 -> V_20 ,
L_87 ,
V_21 , V_395 , V_14 , V_401 ) ;
return V_14 ;
}
static int F_225 ( struct V_10 * V_11 ,
enum V_394 V_25 , enum V_415 V_395 , T_2 V_396 ,
T_2 V_397 , T_2 * V_416 , int * V_284 )
{
struct V_393 * V_36 = NULL ;
struct V_272 * V_276 = NULL ;
int V_134 ;
F_222 ( ! V_11 ) ;
F_82 ( V_11 , false ) ;
if ( ! V_416 ) {
F_7 ( V_11 -> V_20 , L_88 ,
V_21 , V_25 ) ;
V_134 = - V_219 ;
goto V_154;
}
if ( * V_284 < V_417 || * V_284 > V_418 ) {
F_7 ( V_11 -> V_20 , L_89 ,
V_21 , * V_284 ) ;
V_134 = - V_219 ;
goto V_154;
}
F_172 ( & V_11 -> V_274 . V_403 ) ;
F_219 ( V_11 , & V_36 , & V_276 , V_25 , V_395 , V_396 ,
V_397 ) ;
V_11 -> V_274 . V_275 . V_288 = V_416 ;
V_36 -> V_286 . V_287 = F_226 ( * V_284 ) ;
switch ( V_25 ) {
case V_352 :
V_36 -> V_351 = V_407 ;
break;
case V_280 :
V_36 -> V_351 = V_409 ;
break;
default:
F_7 ( V_11 -> V_20 ,
L_90 ,
V_21 , V_25 ) ;
V_134 = - V_219 ;
goto V_370;
}
V_134 = F_214 ( V_11 , V_357 , V_402 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_86 ,
V_21 , V_25 , V_395 , V_396 , V_134 ) ;
goto V_370;
}
V_11 -> V_274 . V_275 . V_288 = NULL ;
* V_284 = F_157 ( V_276 -> V_277 . V_287 ) ;
V_370:
F_174 ( & V_11 -> V_274 . V_403 ) ;
V_154:
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_227 ( struct V_10 * V_11 ,
enum V_394 V_25 ,
enum V_415 V_395 , T_2 V_396 ,
T_2 V_397 ,
T_2 * V_416 , int * V_284 )
{
int V_134 ;
int V_400 ;
for ( V_400 = V_401 ; V_400 > 0 ; V_400 -- ) {
V_134 = F_225 ( V_11 , V_25 , V_395 , V_396 ,
V_397 , V_416 , V_284 ) ;
if ( ! V_134 || V_134 == - V_219 )
break;
}
return V_134 ;
}
static int F_228 ( struct V_10 * V_11 ,
enum V_415 V_419 ,
int V_420 ,
int * V_421 )
{
int V_14 ;
T_2 V_100 [ V_422 ] ;
int V_423 = V_422 ;
if ( V_419 >= V_424 )
return - V_219 ;
V_14 = F_227 ( V_11 , V_280 ,
V_419 , V_420 , 0 , V_100 ,
& V_423 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_91 ,
V_21 , V_419 ) ;
return V_14 ;
} else if ( V_419 != V_100 [ V_425 ] ) {
F_161 ( V_11 -> V_20 , L_92 ,
V_21 , V_100 [ V_425 ] ,
V_419 ) ;
V_14 = - V_219 ;
}
* V_421 = V_100 [ V_426 ] ;
return V_14 ;
}
int F_229 ( struct V_10 * V_11 ,
enum V_415 V_419 , int * V_427 )
{
switch ( V_419 ) {
case V_428 :
* V_427 = V_11 -> V_429 . V_430 ;
break;
case V_431 :
* V_427 = V_11 -> V_429 . V_432 ;
break;
case V_433 :
* V_427 = V_11 -> V_429 . V_434 ;
break;
case V_435 :
* V_427 = V_11 -> V_429 . V_436 ;
break;
case V_437 :
* V_427 = V_11 -> V_429 . V_438 ;
break;
case V_439 :
* V_427 = V_11 -> V_429 . V_440 ;
break;
case V_441 :
* V_427 = V_418 ;
break;
case V_442 :
case V_443 :
* V_427 = 0 ;
break;
default:
* V_427 = 0 ;
return - V_219 ;
}
return 0 ;
}
static int F_230 ( struct V_10 * V_11 ,
enum V_415 V_419 ,
int V_420 ,
T_2 V_444 ,
T_2 * V_445 ,
T_2 V_446 )
{
int V_14 ;
T_2 * V_416 ;
int V_447 ;
bool V_448 = true ;
if ( V_419 >= V_424 || ! V_446 )
return - V_219 ;
V_14 = F_229 ( V_11 , V_419 , & V_447 ) ;
if ( V_14 || ! V_447 ) {
F_7 ( V_11 -> V_20 , L_93 ,
V_21 ) ;
return V_14 ;
}
if ( V_444 != 0 || V_446 < V_447 ) {
V_416 = F_231 ( V_447 , V_449 ) ;
if ( ! V_416 )
return - V_450 ;
} else {
V_416 = V_445 ;
V_448 = false ;
}
V_14 = F_227 ( V_11 , V_280 ,
V_419 , V_420 , 0 ,
V_416 , & V_447 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_94 ,
V_21 , V_419 , V_420 , V_444 , V_14 ) ;
goto V_154;
}
if ( V_416 [ V_425 ] != V_419 ) {
F_7 ( V_11 -> V_20 , L_95 ,
V_21 , V_416 [ V_425 ] ) ;
V_14 = - V_219 ;
goto V_154;
}
if ( V_448 && V_446 > V_447 )
V_446 = V_447 ;
if ( V_448 )
memcpy ( V_445 , & V_416 [ V_444 ] , V_446 ) ;
V_154:
if ( V_448 )
F_232 ( V_416 ) ;
return V_14 ;
}
static inline int F_233 ( struct V_10 * V_11 ,
enum V_415 V_419 ,
int V_420 ,
T_2 * V_237 ,
T_3 V_313 )
{
return F_230 ( V_11 , V_419 , V_420 , 0 , V_237 , V_313 ) ;
}
static inline int F_234 ( struct V_10 * V_11 ,
T_2 * V_237 ,
T_3 V_313 )
{
return F_233 ( V_11 , V_431 , 0 , V_237 , V_313 ) ;
}
static int F_235 ( struct V_10 * V_11 , T_2 * V_237 , T_3 V_313 )
{
return F_233 ( V_11 , V_428 , 0 , V_237 , V_313 ) ;
}
static int F_236 ( struct V_10 * V_11 , int V_420 ,
T_2 * V_237 , T_3 V_313 , bool V_451 )
{
int V_134 = 0 ;
V_134 = F_233 ( V_11 ,
V_441 , V_420 , V_237 , V_313 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_96 ,
V_21 , V_401 , V_134 ) ;
goto V_154;
}
if ( V_451 ) {
int V_427 ;
int V_452 ;
int V_58 ;
char * V_453 ;
V_427 = V_237 [ 0 ] ;
V_452 = ( V_427 - V_422 ) / 2 + 1 ;
if ( V_313 < V_452 + V_422 ) {
F_7 ( V_11 -> V_20 , L_97 ,
V_21 ) ;
V_134 = - V_450 ;
goto V_154;
}
V_453 = F_231 ( V_452 , V_449 ) ;
if ( ! V_453 ) {
V_134 = - V_450 ;
goto V_154;
}
F_237 ( ( V_454 * ) & V_237 [ V_422 ] ,
V_427 - V_422 ,
V_455 , V_453 , V_452 ) ;
for ( V_58 = 0 ; V_58 < V_452 ; V_58 ++ )
F_10 ( & V_453 [ V_58 ] ) ;
memset ( V_237 + V_422 , 0 ,
V_313 - V_422 ) ;
memcpy ( V_237 + V_422 , V_453 , V_452 ) ;
V_237 [ V_426 ] = V_452 + V_422 ;
F_232 ( V_453 ) ;
}
V_154:
return V_134 ;
}
static inline int F_238 ( struct V_10 * V_11 ,
int V_344 ,
enum V_456 V_444 ,
T_2 * V_445 ,
T_3 V_446 )
{
if ( V_344 != V_457 && ( V_344 >= V_458 ) )
return - V_459 ;
return F_230 ( V_11 , V_437 , V_344 ,
V_444 , V_445 , V_446 ) ;
}
static int F_239 ( struct V_10 * V_11 )
{
T_6 V_460 , V_461 , V_462 ;
V_462 = ( sizeof( struct V_463 ) * V_11 -> V_13 ) ;
V_11 -> V_464 = F_240 ( V_11 -> V_20 ,
V_462 ,
& V_11 -> V_465 ,
V_449 ) ;
if ( ! V_11 -> V_464 ||
F_166 ( V_11 -> V_465 & ( V_238 - 1 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_98 ) ;
goto V_154;
}
V_461 = ( sizeof( struct V_87 ) * V_11 -> V_13 ) ;
V_11 -> V_466 = F_240 ( V_11 -> V_20 ,
V_461 ,
& V_11 -> V_467 ,
V_449 ) ;
if ( ! V_11 -> V_466 ||
F_166 ( V_11 -> V_467 & ( V_238 - 1 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_99 ) ;
goto V_154;
}
V_460 = sizeof( struct V_97 ) * V_11 -> V_156 ;
V_11 -> V_99 = F_240 ( V_11 -> V_20 ,
V_460 ,
& V_11 -> V_468 ,
V_449 ) ;
if ( ! V_11 -> V_99 ||
F_166 ( V_11 -> V_468 & ( V_238 - 1 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_100 ) ;
goto V_154;
}
V_11 -> V_31 = F_241 ( V_11 -> V_20 ,
V_11 -> V_13 * sizeof( struct V_28 ) ,
V_449 ) ;
if ( ! V_11 -> V_31 ) {
F_7 ( V_11 -> V_20 , L_101 ) ;
goto V_154;
}
return 0 ;
V_154:
return - V_450 ;
}
static void F_242 ( struct V_10 * V_11 )
{
struct V_463 * V_469 ;
struct V_87 * V_470 ;
T_8 V_471 ;
T_8 V_472 ;
T_7 V_473 ;
T_7 V_474 ;
int V_475 ;
int V_58 ;
V_470 = V_11 -> V_466 ;
V_469 = V_11 -> V_464 ;
V_473 =
F_243 ( struct V_463 , V_476 ) ;
V_474 =
F_243 ( struct V_463 , V_307 ) ;
V_475 = sizeof( struct V_463 ) ;
V_471 = V_11 -> V_465 ;
for ( V_58 = 0 ; V_58 < V_11 -> V_13 ; V_58 ++ ) {
V_472 =
( V_471 + ( V_475 * V_58 ) ) ;
V_470 [ V_58 ] . V_477 =
F_179 ( F_181 ( V_472 ) ) ;
V_470 [ V_58 ] . V_478 =
F_179 ( F_182 ( V_472 ) ) ;
if ( V_11 -> V_119 & V_312 ) {
V_470 [ V_58 ] . V_479 =
F_177 ( V_473 ) ;
V_470 [ V_58 ] . V_480 =
F_177 ( V_474 ) ;
V_470 [ V_58 ] . V_481 =
F_177 ( V_482 ) ;
} else {
V_470 [ V_58 ] . V_479 =
F_177 ( ( V_473 >> 2 ) ) ;
V_470 [ V_58 ] . V_480 =
F_177 ( ( V_474 >> 2 ) ) ;
V_470 [ V_58 ] . V_481 =
F_177 ( V_482 >> 2 ) ;
}
V_11 -> V_31 [ V_58 ] . V_86 = ( V_470 + V_58 ) ;
V_11 -> V_31 [ V_58 ] . V_85 = V_11 -> V_467 +
( V_58 * sizeof( struct V_87 ) ) ;
V_11 -> V_31 [ V_58 ] . V_40 =
(struct V_89 * ) ( V_469 + V_58 ) ;
V_11 -> V_31 [ V_58 ] . V_88 = V_472 ;
V_11 -> V_31 [ V_58 ] . V_91 =
(struct V_92 * ) V_469 [ V_58 ] . V_476 ;
V_11 -> V_31 [ V_58 ] . V_90 = V_472 +
V_473 ;
V_11 -> V_31 [ V_58 ] . V_95 =
(struct V_96 * ) V_469 [ V_58 ] . V_307 ;
V_11 -> V_31 [ V_58 ] . V_94 = V_472 +
V_474 ;
}
}
static int F_244 ( struct V_10 * V_11 )
{
struct V_293 V_294 = { 0 } ;
int V_14 ;
V_294 . V_299 = V_483 ;
V_14 = F_171 ( V_11 , & V_294 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 ,
L_102 , V_14 ) ;
return V_14 ;
}
static inline void F_173 ( struct V_10 * V_11 )
{
#define F_245 1000
unsigned long V_484 ;
if ( ! ( V_11 -> V_119 & V_485 ) )
return;
if ( F_217 ( ! F_22 ( V_11 -> V_486 ) ) ) {
V_484 = F_245 ;
} else {
unsigned long V_487 =
( unsigned long ) F_22 (
F_79 ( F_72 () ,
V_11 -> V_486 ) ) ;
if ( V_487 < F_245 )
V_484 =
F_245 - V_487 ;
else
return;
}
F_33 ( V_484 , V_484 + 50 ) ;
}
int F_246 ( struct V_10 * V_11 , T_3 V_488 ,
T_2 V_489 , T_3 V_490 , T_2 V_491 )
{
struct V_293 V_294 = { 0 } ;
static const char * const V_492 [] = {
L_103 ,
L_104
} ;
const char * V_319 = V_492 [ ! ! V_491 ] ;
int V_14 ;
int V_400 = V_493 ;
V_294 . V_299 = V_491 ?
V_494 : V_495 ;
V_294 . V_295 = V_488 ;
V_294 . V_297 = F_247 ( V_489 ) ;
V_294 . V_298 = V_490 ;
do {
V_14 = F_171 ( V_11 , & V_294 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 , L_105 ,
V_319 , F_248 ( V_488 ) , V_490 , V_14 ) ;
} while ( V_14 && V_491 && -- V_400 );
if ( V_14 )
F_7 ( V_11 -> V_20 , L_106 ,
V_319 , F_248 ( V_488 ) , V_490 ,
V_493 - V_400 ) ;
return V_14 ;
}
int F_249 ( struct V_10 * V_11 , T_3 V_488 ,
T_3 * V_490 , T_2 V_491 )
{
struct V_293 V_294 = { 0 } ;
static const char * const V_492 [] = {
L_107 ,
L_108
} ;
const char * V_496 = V_492 [ ! ! V_491 ] ;
int V_14 ;
int V_400 = V_493 ;
struct V_202 V_497 ;
struct V_202 V_498 ;
bool V_499 = false ;
if ( V_491 && ( V_11 -> V_119 & V_500 ) ) {
V_497 = V_11 -> V_122 ;
V_498 = V_497 ;
if ( V_497 . V_128 == V_501 ||
V_497 . V_127 == V_501 ) {
V_498 . V_128 = V_502 ;
V_498 . V_127 = V_502 ;
V_499 = true ;
} else if ( V_497 . V_128 == V_503 ||
V_497 . V_127 == V_503 ) {
V_498 . V_128 = V_504 ;
V_498 . V_127 = V_504 ;
V_499 = true ;
}
if ( V_499 ) {
V_14 = F_89 ( V_11 , & V_498 ) ;
if ( V_14 )
goto V_154;
}
}
V_294 . V_299 = V_491 ?
V_505 : V_506 ;
V_294 . V_295 = V_488 ;
do {
V_14 = F_171 ( V_11 , & V_294 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 , L_109 ,
V_496 , F_248 ( V_488 ) , V_14 ) ;
} while ( V_14 && V_491 && -- V_400 );
if ( V_14 )
F_7 ( V_11 -> V_20 , L_110 ,
V_496 , F_248 ( V_488 ) ,
V_493 - V_400 ) ;
if ( V_490 && ! V_14 )
* V_490 = V_294 . V_298 ;
if ( V_491 && ( V_11 -> V_119 & V_500 )
&& V_499 )
F_89 ( V_11 , & V_497 ) ;
V_154:
return V_14 ;
}
static int F_250 ( struct V_10 * V_11 , struct V_293 * V_32 )
{
struct V_304 V_258 ;
unsigned long V_194 ;
T_2 V_507 ;
int V_14 ;
bool V_508 = false ;
F_172 ( & V_11 -> V_306 ) ;
F_170 ( & V_258 ) ;
F_173 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_258 = & V_258 ;
if ( F_14 ( V_11 , V_320 ) & V_509 ) {
F_184 ( V_11 , V_509 ) ;
F_155 () ;
V_508 = true ;
}
V_14 = F_169 ( V_11 , V_32 , false ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 ,
L_111 ,
V_32 -> V_299 , V_32 -> V_298 , V_14 ) ;
goto V_154;
}
if ( ! F_168 ( V_11 -> V_258 ,
F_32 ( V_303 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_112 ,
V_32 -> V_299 , V_32 -> V_298 ) ;
V_14 = - V_137 ;
goto V_154;
}
V_507 = F_164 ( V_11 ) ;
if ( V_507 != V_510 ) {
F_7 ( V_11 -> V_20 ,
L_113 ,
V_32 -> V_299 , V_507 ) ;
V_14 = ( V_507 != V_511 ) ? V_507 : - 1 ;
}
V_154:
if ( V_14 ) {
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
F_23 ( V_11 ) ;
}
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_257 = NULL ;
V_11 -> V_258 = NULL ;
if ( V_508 )
F_183 ( V_11 , V_509 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_174 ( & V_11 -> V_306 ) ;
return V_14 ;
}
static int F_251 ( struct V_10 * V_11 , T_2 V_245 )
{
struct V_293 V_294 = { 0 } ;
int V_14 ;
if ( V_11 -> V_119 & V_512 ) {
V_14 = F_252 ( V_11 ,
F_253 ( V_513 , 0 ) , 1 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_114 ,
V_21 , V_14 ) ;
goto V_154;
}
}
V_294 . V_299 = V_495 ;
V_294 . V_295 = F_254 ( V_514 ) ;
V_294 . V_298 = V_245 ;
F_82 ( V_11 , false ) ;
V_14 = F_250 ( V_11 , & V_294 ) ;
F_86 ( V_11 ) ;
V_154:
return V_14 ;
}
static int F_255 ( struct V_10 * V_11 )
{
int V_14 ;
unsigned long V_194 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_104 = V_369 ;
F_256 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_14 = F_257 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_14 )
V_11 -> V_104 = V_371 ;
F_258 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 , L_115 ,
V_21 , V_14 ) ;
return V_14 ;
}
static int F_259 ( struct V_10 * V_11 )
{
int V_14 ;
struct V_293 V_294 = { 0 } ;
T_4 V_189 = F_72 () ;
F_260 ( V_11 , V_515 , V_191 ) ;
V_294 . V_299 = V_515 ;
V_14 = F_250 ( V_11 , & V_294 ) ;
F_261 ( F_16 ( V_11 -> V_20 ) , L_116 ,
F_22 ( F_79 ( F_72 () , V_189 ) ) , V_14 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_117 ,
V_21 , V_14 ) ;
if ( F_255 ( V_11 ) )
V_14 = - V_516 ;
} else
F_260 ( V_11 , V_515 ,
V_192 ) ;
return V_14 ;
}
static int F_135 ( struct V_10 * V_11 )
{
int V_14 = 0 , V_400 ;
for ( V_400 = V_517 ; V_400 > 0 ; V_400 -- ) {
V_14 = F_259 ( V_11 ) ;
if ( ! V_14 || V_14 == - V_516 )
goto V_154;
}
V_154:
return V_14 ;
}
static int F_127 ( struct V_10 * V_11 )
{
struct V_293 V_294 = { 0 } ;
int V_14 ;
T_4 V_189 = F_72 () ;
F_260 ( V_11 , V_518 , V_191 ) ;
V_294 . V_299 = V_518 ;
V_14 = F_250 ( V_11 , & V_294 ) ;
F_261 ( F_16 ( V_11 -> V_20 ) , L_118 ,
F_22 ( F_79 ( F_72 () , V_189 ) ) , V_14 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_119 ,
V_21 , V_14 ) ;
V_14 = F_255 ( V_11 ) ;
} else {
F_260 ( V_11 , V_518 ,
V_192 ) ;
V_11 -> V_70 . V_71 = F_72 () ;
V_11 -> V_70 . V_72 ++ ;
}
return V_14 ;
}
static void F_262 ( struct V_10 * V_11 )
{
V_11 -> V_122 . V_123 = V_519 ;
V_11 -> V_122 . V_124 = V_519 ;
V_11 -> V_122 . V_125 = 1 ;
V_11 -> V_122 . V_126 = 1 ;
V_11 -> V_122 . V_127 = V_504 ;
V_11 -> V_122 . V_128 = V_504 ;
V_11 -> V_122 . V_129 = 0 ;
}
static int F_263 ( struct V_10 * V_11 )
{
struct V_202 * V_122 = & V_11 -> V_520 . V_206 ;
if ( V_11 -> V_520 . V_521 )
return 0 ;
V_122 -> V_128 = V_501 ;
V_122 -> V_127 = V_501 ;
V_122 -> V_129 = V_522 ;
F_264 ( V_11 , F_254 ( V_523 ) ,
& V_122 -> V_125 ) ;
F_264 ( V_11 , F_254 ( V_524 ) ,
& V_122 -> V_126 ) ;
if ( ! V_122 -> V_125 || ! V_122 -> V_126 ) {
F_7 ( V_11 -> V_20 , L_120 ,
V_21 ,
V_122 -> V_125 ,
V_122 -> V_126 ) ;
return - V_219 ;
}
F_264 ( V_11 , F_254 ( V_525 ) , & V_122 -> V_123 ) ;
if ( ! V_122 -> V_123 ) {
F_264 ( V_11 , F_254 ( V_526 ) ,
& V_122 -> V_123 ) ;
if ( ! V_122 -> V_123 ) {
F_7 ( V_11 -> V_20 , L_121 ,
V_21 , V_122 -> V_123 ) ;
return - V_219 ;
}
V_122 -> V_127 = V_503 ;
}
F_265 ( V_11 , F_254 ( V_525 ) ,
& V_122 -> V_124 ) ;
if ( ! V_122 -> V_124 ) {
F_265 ( V_11 , F_254 ( V_526 ) ,
& V_122 -> V_124 ) ;
if ( ! V_122 -> V_124 ) {
F_7 ( V_11 -> V_20 , L_122 ,
V_21 , V_122 -> V_124 ) ;
return - V_219 ;
}
V_122 -> V_128 = V_503 ;
}
V_11 -> V_520 . V_521 = true ;
return 0 ;
}
static int F_89 ( struct V_10 * V_11 ,
struct V_202 * V_527 )
{
int V_14 ;
if ( V_527 -> V_123 == V_11 -> V_122 . V_123 &&
V_527 -> V_124 == V_11 -> V_122 . V_124 &&
V_527 -> V_125 == V_11 -> V_122 . V_125 &&
V_527 -> V_126 == V_11 -> V_122 . V_126 &&
V_527 -> V_127 == V_11 -> V_122 . V_127 &&
V_527 -> V_128 == V_11 -> V_122 . V_128 &&
V_527 -> V_129 == V_11 -> V_122 . V_129 ) {
F_76 ( V_11 -> V_20 , L_123 , V_21 ) ;
return 0 ;
}
F_252 ( V_11 , F_254 ( V_528 ) , V_527 -> V_123 ) ;
F_252 ( V_11 , F_254 ( V_529 ) ,
V_527 -> V_125 ) ;
if ( V_527 -> V_127 == V_502 ||
V_527 -> V_127 == V_501 )
F_252 ( V_11 , F_254 ( V_530 ) , TRUE ) ;
else
F_252 ( V_11 , F_254 ( V_530 ) , FALSE ) ;
F_252 ( V_11 , F_254 ( V_531 ) , V_527 -> V_124 ) ;
F_252 ( V_11 , F_254 ( V_532 ) ,
V_527 -> V_126 ) ;
if ( V_527 -> V_128 == V_502 ||
V_527 -> V_128 == V_501 )
F_252 ( V_11 , F_254 ( V_533 ) , TRUE ) ;
else
F_252 ( V_11 , F_254 ( V_533 ) , FALSE ) ;
if ( V_527 -> V_127 == V_502 ||
V_527 -> V_128 == V_502 ||
V_527 -> V_127 == V_501 ||
V_527 -> V_128 == V_501 )
F_252 ( V_11 , F_254 ( V_534 ) ,
V_527 -> V_129 ) ;
V_14 = F_251 ( V_11 , V_527 -> V_127 << 4
| V_527 -> V_128 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 ,
L_124 , V_21 , V_14 ) ;
} else {
F_266 ( V_11 , V_192 , NULL ,
V_527 ) ;
memcpy ( & V_11 -> V_122 , V_527 ,
sizeof( struct V_202 ) ) ;
}
return V_14 ;
}
static int F_267 ( struct V_10 * V_11 ,
struct V_202 * V_535 )
{
struct V_202 V_536 = { 0 } ;
int V_14 ;
V_14 = F_266 ( V_11 , V_191 ,
V_535 , & V_536 ) ;
if ( V_14 )
memcpy ( & V_536 , V_535 , sizeof( V_536 ) ) ;
V_14 = F_89 ( V_11 , & V_536 ) ;
if ( ! V_14 )
F_30 ( V_11 ) ;
return V_14 ;
}
static int F_268 ( struct V_10 * V_11 )
{
int V_58 ;
int V_134 ;
bool V_399 = 1 ;
V_134 = F_220 ( V_11 , V_404 ,
V_537 , NULL ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 ,
L_125 ,
V_21 , V_134 ) ;
goto V_154;
}
for ( V_58 = 0 ; V_58 < 1000 && ! V_134 && V_399 ; V_58 ++ )
V_134 = F_220 ( V_11 , V_408 ,
V_537 , & V_399 ) ;
if ( V_134 )
F_7 ( V_11 -> V_20 ,
L_126 ,
V_21 , V_134 ) ;
else if ( V_399 )
F_7 ( V_11 -> V_20 ,
L_127 ,
V_21 ) ;
V_154:
return V_134 ;
}
static int F_269 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
T_3 V_62 ;
F_183 ( V_11 , V_538 ) ;
if ( F_202 ( V_11 ) )
F_60 ( V_11 , V_11 -> V_13 - 1 , V_539 ) ;
else
F_63 ( V_11 ) ;
F_49 ( V_11 , F_181 ( V_11 -> V_467 ) ,
V_540 ) ;
F_49 ( V_11 , F_182 ( V_11 -> V_467 ) ,
V_541 ) ;
F_49 ( V_11 , F_181 ( V_11 -> V_468 ) ,
V_542 ) ;
F_49 ( V_11 , F_182 ( V_11 -> V_468 ) ,
V_543 ) ;
F_155 () ;
V_62 = F_14 ( V_11 , V_148 ) ;
if ( ! ( F_52 ( V_62 ) ) ) {
F_64 ( V_11 ) ;
} else {
F_7 ( V_11 -> V_20 ,
L_128 ) ;
V_134 = - V_305 ;
goto V_154;
}
V_154:
return V_134 ;
}
static inline void F_270 ( struct V_10 * V_11 , bool V_133 )
{
int V_134 ;
F_49 ( V_11 , V_544 , V_179 ) ;
V_134 = F_31 ( V_11 , V_179 ,
V_178 , V_544 ,
10 , 1 , V_133 ) ;
if ( V_134 )
F_7 ( V_11 -> V_20 , L_129 , V_21 ) ;
}
static int F_271 ( struct V_10 * V_11 )
{
int V_545 ;
if ( ! F_66 ( V_11 ) )
F_270 ( V_11 , true ) ;
F_272 ( V_11 ) ;
F_273 ( V_11 , V_191 ) ;
F_65 ( V_11 ) ;
F_274 ( 1 ) ;
V_545 = 10 ;
while ( F_66 ( V_11 ) ) {
if ( V_545 ) {
V_545 -- ;
} else {
F_7 ( V_11 -> V_20 ,
L_130 ) ;
return - V_305 ;
}
F_274 ( 5 ) ;
}
F_183 ( V_11 , V_546 ) ;
F_273 ( V_11 , V_192 ) ;
return 0 ;
}
static int F_275 ( struct V_10 * V_11 , bool V_491 )
{
int V_547 , V_58 , V_134 = 0 ;
if ( ! V_491 )
F_264 ( V_11 , F_254 ( V_524 ) ,
& V_547 ) ;
else
F_265 ( V_11 , F_254 ( V_524 ) ,
& V_547 ) ;
for ( V_58 = 0 ; V_58 < V_547 ; V_58 ++ ) {
if ( ! V_491 )
V_134 = F_252 ( V_11 ,
F_253 ( V_548 ,
F_276 ( V_58 ) ) ,
0 ) ;
else
V_134 = F_277 ( V_11 ,
F_253 ( V_548 ,
F_276 ( V_58 ) ) ,
0 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_131 ,
V_21 , V_491 , V_58 , V_134 ) ;
break;
}
}
return V_134 ;
}
static inline int F_278 ( struct V_10 * V_11 )
{
return F_275 ( V_11 , true ) ;
}
static int F_279 ( struct V_10 * V_11 )
{
int V_14 ;
int V_400 = V_549 ;
bool V_550 = false ;
if ( ! F_280 ( V_11 ) )
V_550 = true ;
V_551:
do {
F_281 ( V_11 , V_191 ) ;
V_14 = F_244 ( V_11 ) ;
if ( ! V_14 && ! F_39 ( V_11 ) ) {
F_7 ( V_11 -> V_20 , L_132 , V_21 ) ;
V_14 = - V_552 ;
goto V_154;
}
if ( V_14 && F_271 ( V_11 ) )
goto V_154;
} while ( V_14 && V_400 -- );
if ( V_14 )
goto V_154;
if ( V_550 ) {
V_550 = false ;
V_400 = V_549 ;
goto V_551;
}
F_262 ( V_11 ) ;
F_30 ( V_11 ) ;
if ( V_11 -> V_119 & V_553 ) {
V_14 = F_278 ( V_11 ) ;
if ( V_14 )
goto V_154;
}
V_14 = F_281 ( V_11 , V_192 ) ;
if ( V_14 )
goto V_154;
V_14 = F_269 ( V_11 ) ;
V_154:
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_133 , V_14 ) ;
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
F_23 ( V_11 ) ;
}
return V_14 ;
}
static int F_282 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
int V_400 ;
F_82 ( V_11 , false ) ;
F_172 ( & V_11 -> V_274 . V_403 ) ;
for ( V_400 = V_554 ; V_400 > 0 ; V_400 -- ) {
V_134 = F_214 ( V_11 , V_358 ,
V_555 ) ;
if ( ! V_134 || V_134 == - V_137 )
break;
F_76 ( V_11 -> V_20 , L_134 , V_21 , V_134 ) ;
}
F_174 ( & V_11 -> V_274 . V_403 ) ;
F_86 ( V_11 ) ;
if ( V_134 )
F_7 ( V_11 -> V_20 , L_135 , V_21 , V_134 ) ;
return V_134 ;
}
static void F_283 ( struct V_556 * V_557 )
{
int V_14 = 0 ;
T_2 V_558 ;
struct V_10 * V_11 ;
V_11 = F_197 ( V_557 -> V_112 ) ;
V_558 = V_11 -> V_13 ;
V_14 = F_238 ( V_11 ,
F_193 ( V_557 -> V_344 ) ,
V_559 ,
& V_558 ,
sizeof( V_558 ) ) ;
if ( V_14 == - V_459 )
V_558 = 1 ;
else if ( ! V_558 )
V_558 = V_11 -> V_13 ;
else
V_558 = F_158 ( int , V_558 , V_11 -> V_13 ) ;
F_76 ( V_11 -> V_20 , L_136 ,
V_21 , V_558 ) ;
F_284 ( V_557 , V_558 ) ;
}
static int F_285 ( struct V_10 * V_11 ,
T_2 V_344 ,
T_2 * V_560 )
{
int V_14 ;
if ( ! V_560 )
V_14 = - V_219 ;
else if ( V_344 >= V_458 )
V_14 = - V_561 ;
else
V_14 = F_238 ( V_11 ,
V_344 ,
V_562 ,
V_560 ,
sizeof( * V_560 ) ) ;
return V_14 ;
}
static inline void F_286 ( struct V_10 * V_11 ,
struct V_556 * V_557 )
{
if ( V_11 -> V_563 . V_564 &&
! V_11 -> V_563 . V_565 ) {
T_2 V_560 ;
if ( ! F_285 ( V_11 , F_193 ( V_557 -> V_344 ) ,
& V_560 ) &&
( V_560 == V_566 ) )
V_11 -> V_563 . V_565 = true ;
}
}
static int F_287 ( struct V_556 * V_557 )
{
struct V_10 * V_11 ;
V_11 = F_197 ( V_557 -> V_112 ) ;
V_557 -> V_567 = 1 ;
V_557 -> V_568 = 1 ;
V_557 -> V_569 = 1 ;
F_283 ( V_557 ) ;
F_286 ( V_11 , V_557 ) ;
return 0 ;
}
static int F_288 ( struct V_556 * V_557 , int V_570 )
{
struct V_10 * V_11 = F_197 ( V_557 -> V_112 ) ;
if ( V_570 > V_11 -> V_13 )
V_570 = V_11 -> V_13 ;
return F_284 ( V_557 , V_570 ) ;
}
static int F_289 ( struct V_556 * V_557 )
{
struct V_571 * V_572 = V_557 -> V_571 ;
F_290 ( V_572 , V_573 - 1 ) ;
F_291 ( V_572 , V_574 ) ;
return 0 ;
}
static void F_292 ( struct V_556 * V_557 )
{
struct V_10 * V_11 ;
V_11 = F_197 ( V_557 -> V_112 ) ;
if ( F_193 ( V_557 -> V_344 ) == V_575 ) {
unsigned long V_194 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_576 = NULL ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
}
}
static int F_293 ( struct V_10 * V_11 , T_3 V_396 , T_2 * V_380 )
{
struct V_97 * V_152 ;
struct V_577 * V_578 ;
unsigned long V_194 ;
int V_579 ;
int V_580 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_51 ( V_396 , & V_11 -> V_69 ) ;
V_152 = V_11 -> V_99 ;
V_579 = F_42 ( & V_152 [ V_396 ] ) ;
if ( V_579 == V_581 ) {
V_578 = (struct V_577 * )
V_152 [ V_396 ] . V_103 ;
V_580 = F_13 ( V_578 -> V_582 ) ;
V_580 = V_580 & V_583 ;
if ( V_380 )
* V_380 = ( T_2 ) V_580 ;
} else {
F_7 ( V_11 -> V_20 , L_137 ,
V_21 , V_579 ) ;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
return V_579 ;
}
static inline int
F_294 ( struct V_28 * V_29 , int V_584 )
{
int V_585 = 0 ;
switch ( V_584 ) {
case V_586 :
F_156 ( V_29 ) ;
case V_587 :
V_585 |= V_588 << 16 |
V_589 << 8 |
V_584 ;
break;
case V_590 :
case V_591 :
case V_592 :
F_156 ( V_29 ) ;
V_585 |= V_584 ;
break;
default:
V_585 |= V_372 << 16 ;
break;
}
return V_585 ;
}
static inline int
F_295 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
int V_585 = 0 ;
int V_584 ;
int V_593 ;
V_593 = F_40 ( V_29 ) ;
switch ( V_593 ) {
case V_581 :
V_585 = F_55 ( V_29 -> V_91 ) ;
V_11 -> V_70 . V_71 = F_209 ( 0 , 0 ) ;
switch ( V_585 ) {
case V_594 :
V_585 = F_56 ( V_29 -> V_91 ) ;
V_584 = V_585 & V_595 ;
V_585 = F_294 ( V_29 , V_584 ) ;
if ( ! V_11 -> V_109 &&
F_58 ( V_29 -> V_91 ) )
F_133 ( & V_11 -> V_596 ) ;
break;
case V_383 :
V_585 = V_372 << 16 ;
F_7 ( V_11 -> V_20 ,
L_138 ) ;
break;
default:
V_585 = V_372 << 16 ;
F_7 ( V_11 -> V_20 ,
L_139 ,
V_585 ) ;
break;
}
break;
case V_597 :
V_585 |= V_598 << 16 ;
break;
case V_340 :
V_585 |= V_599 << 16 ;
break;
case V_600 :
case V_601 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
default:
V_585 |= V_372 << 16 ;
F_7 ( V_11 -> V_20 ,
L_140 ,
V_593 , V_29 -> V_263 ) ;
F_23 ( V_11 ) ;
F_29 ( V_11 ) ;
break;
}
if ( F_296 ( V_585 ) != V_588 )
F_25 ( V_11 , 1 << V_29 -> V_263 , true ) ;
return V_585 ;
}
static void F_297 ( struct V_10 * V_11 , T_3 V_606 )
{
if ( ( V_606 & V_509 ) && V_11 -> V_257 ) {
V_11 -> V_257 -> V_297 |=
F_53 ( V_11 ) ;
V_11 -> V_257 -> V_298 =
F_54 ( V_11 ) ;
V_387 ( & V_11 -> V_257 -> V_302 ) ;
}
if ( ( V_606 & V_607 ) && V_11 -> V_258 )
V_387 ( V_11 -> V_258 ) ;
}
static void F_298 ( struct V_10 * V_11 ,
unsigned long V_608 )
{
struct V_28 * V_29 ;
struct V_310 * V_32 ;
int V_585 ;
int V_396 ;
F_26 (index, &completed_reqs, hba->nutrs) {
V_29 = & V_11 -> V_31 [ V_396 ] ;
V_32 = V_29 -> V_32 ;
if ( V_32 ) {
F_11 ( V_11 , V_396 , L_141 ) ;
V_585 = F_295 ( V_11 , V_29 ) ;
F_299 ( V_32 ) ;
V_32 -> V_585 = V_585 ;
V_29 -> V_32 = NULL ;
F_47 ( V_396 , & V_11 -> V_105 ) ;
V_32 -> V_373 ( V_32 ) ;
F_139 ( V_11 ) ;
} else if ( V_29 -> V_336 == V_355 ||
V_29 -> V_336 == V_354 ) {
if ( V_11 -> V_274 . V_387 ) {
F_11 ( V_11 , V_396 ,
L_142 ) ;
V_387 ( V_11 -> V_274 . V_387 ) ;
}
}
if ( F_105 ( V_11 ) )
V_11 -> V_204 . V_212 -- ;
}
V_11 -> V_68 ^= V_608 ;
F_152 ( V_11 ) ;
F_218 ( & V_11 -> V_274 . V_391 ) ;
}
static void F_300 ( struct V_10 * V_11 )
{
unsigned long V_608 ;
T_3 V_196 ;
if ( F_202 ( V_11 ) )
F_59 ( V_11 ) ;
V_196 = F_14 ( V_11 , V_44 ) ;
V_608 = V_196 ^ V_11 -> V_68 ;
F_298 ( V_11 , V_608 ) ;
}
static int F_301 ( struct V_10 * V_11 , T_7 V_130 )
{
int V_134 = 0 ;
T_3 V_22 ;
if ( ! ( V_11 -> V_609 & V_130 ) )
goto V_154;
V_22 = V_11 -> V_609 & ~ V_130 ;
V_22 &= V_610 ;
V_134 = F_224 ( V_11 , V_413 ,
V_611 , 0 , 0 , & V_22 ) ;
if ( ! V_134 )
V_11 -> V_609 &= ~ V_130 ;
V_154:
return V_134 ;
}
static int F_302 ( struct V_10 * V_11 , T_7 V_130 )
{
int V_134 = 0 ;
T_3 V_22 ;
if ( V_11 -> V_609 & V_130 )
goto V_154;
V_22 = V_11 -> V_609 | V_130 ;
V_22 &= V_610 ;
V_134 = F_224 ( V_11 , V_413 ,
V_611 , 0 , 0 , & V_22 ) ;
if ( ! V_134 )
V_11 -> V_609 |= V_130 ;
V_154:
return V_134 ;
}
static int F_303 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
if ( V_11 -> V_111 )
goto V_154;
V_134 = F_220 ( V_11 , V_404 ,
V_612 , NULL ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_143 ,
V_21 , V_134 ) ;
goto V_154;
}
V_11 -> V_111 = true ;
F_304 ( F_16 ( V_11 -> V_20 ) , L_144 ) ;
V_134 = F_301 ( V_11 , V_613 ) ;
if ( V_134 )
F_7 ( V_11 -> V_20 , L_145 ,
V_21 , V_134 ) ;
V_154:
return V_134 ;
}
static int F_305 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
if ( ! V_11 -> V_111 )
goto V_154;
V_134 = F_302 ( V_11 , V_613 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_146 ,
V_21 , V_134 ) ;
goto V_154;
}
V_134 = F_220 ( V_11 , V_405 ,
V_612 , NULL ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_147 ,
V_21 , V_134 ) ;
F_301 ( V_11 , V_613 ) ;
goto V_154;
}
V_11 -> V_111 = false ;
F_304 ( F_16 ( V_11 -> V_20 ) , L_148 ) ;
V_154:
return V_134 ;
}
static void F_306 ( struct V_10 * V_11 )
{
if ( F_307 ( V_11 ) ) {
V_11 -> V_111 = false ;
V_11 -> V_609 |= V_613 ;
F_303 ( V_11 ) ;
} else {
V_11 -> V_111 = true ;
V_11 -> V_609 &= ~ V_613 ;
F_305 ( V_11 ) ;
}
}
static inline int F_308 ( struct V_10 * V_11 , T_3 * V_507 )
{
return F_224 ( V_11 , V_414 ,
V_614 , 0 , 0 , V_507 ) ;
}
static int F_309 ( struct V_10 * V_11 ,
enum V_615 V_507 )
{
int V_134 ;
T_3 V_616 = 0 ;
V_134 = F_308 ( V_11 , & V_616 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_149 ,
V_21 , V_134 ) ;
goto V_154;
} else if ( V_616 > V_617 ) {
F_7 ( V_11 -> V_20 , L_150 ,
V_21 , V_616 ) ;
V_134 = - V_219 ;
goto V_154;
}
if ( V_616 >= V_507 )
V_134 = F_303 ( V_11 ) ;
else
V_134 = F_305 ( V_11 ) ;
V_154:
return V_134 ;
}
static int F_310 ( struct V_10 * V_11 )
{
return F_309 ( V_11 , V_11 -> V_618 ) ;
}
static inline int F_311 ( struct V_10 * V_11 , T_3 * V_507 )
{
return F_224 ( V_11 , V_414 ,
V_619 , 0 , 0 , V_507 ) ;
}
static void F_312 ( struct V_10 * V_11 )
{
int V_134 ;
T_3 V_616 = 0 ;
if ( V_11 -> V_620 )
goto V_621;
V_134 = F_308 ( V_11 , & V_616 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_149 ,
V_21 , V_134 ) ;
goto V_154;
}
if ( V_616 < V_622 ) {
F_7 ( V_11 -> V_20 , L_151 ,
V_21 , V_616 ) ;
V_11 -> V_618 = V_616 ;
V_11 -> V_620 = true ;
}
V_621:
V_134 = F_303 ( V_11 ) ;
V_154:
if ( V_134 < 0 )
F_7 ( V_11 -> V_20 , L_152 ,
V_21 , V_134 ) ;
}
static void F_313 ( struct V_208 * V_209 )
{
struct V_10 * V_11 ;
int V_134 ;
T_3 V_507 = 0 ;
V_11 = F_99 ( V_209 , struct V_10 , V_596 ) ;
F_116 ( V_11 -> V_20 ) ;
V_134 = F_311 ( V_11 , & V_507 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_153 ,
V_21 , V_134 ) ;
goto V_154;
}
V_507 &= V_11 -> V_609 ;
if ( V_507 & V_613 )
F_312 ( V_11 ) ;
V_154:
F_118 ( V_11 -> V_20 ) ;
return;
}
static void F_314 ( struct V_10 * V_11 )
{
F_300 ( V_11 ) ;
F_315 ( V_11 ) ;
}
static bool F_316 ( struct V_10 * V_11 )
{
unsigned long V_194 ;
bool V_623 = true ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_11 -> V_106 & ( V_624 | V_625 ) )
goto V_154;
if ( ( V_11 -> V_106 & V_626 ) ||
( ( V_11 -> V_106 & V_627 ) &&
( V_11 -> V_107 & V_628 ) ) )
goto V_154;
if ( ( V_11 -> V_106 & V_627 ) &&
( V_11 -> V_107 & V_629 ) ) {
int V_134 ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_274 ( 50 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( ( V_11 -> V_106 & V_630 ) ||
( ( V_11 -> V_106 & V_627 ) &&
( V_11 -> V_107 & ~ V_629 ) ) )
goto V_154;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_134 = F_282 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_134 )
goto V_154;
if ( V_11 -> V_107 == V_629 )
V_11 -> V_106 &= ~ V_627 ;
V_11 -> V_107 &= ~ V_629 ;
if ( ! V_11 -> V_107 ) {
V_623 = false ;
goto V_154;
}
}
V_154:
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
return V_623 ;
}
static void F_317 ( struct V_208 * V_209 )
{
struct V_10 * V_11 ;
unsigned long V_194 ;
T_3 V_631 = 0 ;
T_3 V_632 = 0 ;
int V_134 = 0 ;
int V_12 ;
bool V_633 = false ;
V_11 = F_99 ( V_209 , struct V_10 , V_634 ) ;
F_116 ( V_11 -> V_20 ) ;
F_82 ( V_11 , false ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_11 -> V_104 == V_369 )
goto V_154;
V_11 -> V_104 = V_369 ;
F_256 ( V_11 ) ;
F_314 ( V_11 ) ;
if ( V_11 -> V_120 & V_635 ) {
bool V_14 ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_14 = F_316 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( ! V_14 )
goto V_636;
}
if ( ( V_11 -> V_106 & V_630 ) ||
( ( V_11 -> V_106 & V_627 ) &&
( V_11 -> V_107 & ( V_637 |
V_629 |
V_628 ) ) ) )
V_633 = true ;
if ( V_633 )
goto V_638;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_26 (tag, &hba->outstanding_reqs, hba->nutrs) {
if ( F_206 ( V_11 , V_12 ) ) {
V_631 = true ;
goto V_639;
}
}
F_26 (tag, &hba->outstanding_tasks, hba->nutmrs) {
if ( F_318 ( V_11 , V_12 ) ) {
V_632 = true ;
goto V_639;
}
}
V_639:
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_314 ( V_11 ) ;
if ( V_631 || V_632 )
V_633 = true ;
V_638:
if ( V_633 ) {
unsigned long V_640 = ( 1UL << V_11 -> V_13 ) - 1 ;
if ( V_11 -> V_68 == V_640 )
F_298 ( V_11 ,
( 1UL << ( V_11 -> V_13 - 1 ) ) ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_134 = F_319 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_154 ,
V_21 ) ;
V_11 -> V_104 = V_371 ;
}
F_320 ( V_11 -> V_112 , 0 ) ;
V_11 -> V_106 = 0 ;
V_11 -> V_107 = 0 ;
}
V_636:
if ( ! V_633 ) {
V_11 -> V_104 = V_199 ;
if ( V_11 -> V_106 || V_11 -> V_107 )
F_321 ( V_11 -> V_20 , L_155 ,
V_21 , V_11 -> V_106 , V_11 -> V_107 ) ;
}
F_258 ( V_11 ) ;
V_154:
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_95 ( V_11 -> V_112 ) ;
F_86 ( V_11 ) ;
F_118 ( V_11 -> V_20 ) ;
}
static void F_322 ( struct V_55 * V_641 ,
T_3 V_62 )
{
V_641 -> V_62 [ V_641 -> V_61 ] = V_62 ;
V_641 -> V_63 [ V_641 -> V_61 ] = F_72 () ;
V_641 -> V_61 = ( V_641 -> V_61 + 1 ) % V_59 ;
}
static void F_323 ( struct V_10 * V_11 )
{
T_3 V_62 ;
V_62 = F_14 ( V_11 , V_642 ) ;
if ( ( V_62 & V_643 ) &&
( V_62 & V_644 ) ) {
F_76 ( V_11 -> V_20 , L_156 , V_21 ) ;
F_322 ( & V_11 -> V_70 . V_73 , V_62 ) ;
}
V_62 = F_14 ( V_11 , V_645 ) ;
if ( V_62 )
F_322 ( & V_11 -> V_70 . V_74 , V_62 ) ;
if ( V_62 & V_646 )
V_11 -> V_647 |= V_637 ;
else if ( V_11 -> V_120 &
V_635 ) {
if ( V_62 & V_648 )
V_11 -> V_647 |=
V_629 ;
else if ( V_62 & V_649 )
V_11 -> V_647 |= V_628 ;
}
V_62 = F_14 ( V_11 , V_650 ) ;
if ( V_62 ) {
F_322 ( & V_11 -> V_70 . V_75 , V_62 ) ;
V_11 -> V_647 |= V_651 ;
}
V_62 = F_14 ( V_11 , V_652 ) ;
if ( V_62 ) {
F_322 ( & V_11 -> V_70 . V_76 , V_62 ) ;
V_11 -> V_647 |= V_653 ;
}
V_62 = F_14 ( V_11 , V_654 ) ;
if ( V_62 ) {
F_322 ( & V_11 -> V_70 . V_77 , V_62 ) ;
V_11 -> V_647 |= V_655 ;
}
F_76 ( V_11 -> V_20 , L_157 ,
V_21 , V_11 -> V_647 ) ;
}
static void F_324 ( struct V_10 * V_11 )
{
bool V_656 = false ;
if ( V_11 -> V_657 & V_630 )
V_656 = true ;
if ( V_11 -> V_657 & V_627 ) {
V_11 -> V_647 = 0 ;
F_323 ( V_11 ) ;
if ( V_11 -> V_647 )
V_656 = true ;
}
if ( V_656 ) {
V_11 -> V_106 |= V_11 -> V_657 ;
V_11 -> V_107 |= V_11 -> V_647 ;
if ( V_11 -> V_104 == V_199 ) {
F_92 ( V_11 -> V_112 ) ;
V_11 -> V_104 = V_368 ;
if ( V_11 -> V_106 & ( V_630 | V_627 ) ) {
bool V_81 = ! ! ( V_11 -> V_106 &
V_625 ) ;
F_7 ( V_11 -> V_20 , L_158 ,
V_21 , V_11 -> V_106 ,
V_11 -> V_107 ) ;
F_23 ( V_11 ) ;
F_30 ( V_11 ) ;
F_28 ( V_11 , V_11 -> V_69 ) ;
F_25 ( V_11 , V_11 -> V_68 ,
V_81 ) ;
}
F_133 ( & V_11 -> V_634 ) ;
}
}
}
static void F_315 ( struct V_10 * V_11 )
{
T_3 V_195 ;
V_195 = F_14 ( V_11 , V_201 ) ;
V_11 -> V_658 = V_195 ^ V_11 -> V_69 ;
F_218 ( & V_11 -> V_659 ) ;
}
static void F_325 ( struct V_10 * V_11 , T_3 V_606 )
{
V_11 -> V_657 = V_660 & V_606 ;
if ( V_11 -> V_657 )
F_324 ( V_11 ) ;
if ( V_606 & V_546 )
F_297 ( V_11 , V_606 ) ;
if ( V_606 & V_661 )
F_315 ( V_11 ) ;
if ( V_606 & V_662 )
F_300 ( V_11 ) ;
}
static T_9 V_17 ( int V_16 , void * V_663 )
{
T_3 V_606 , V_664 ;
T_9 V_665 = V_666 ;
struct V_10 * V_11 = V_663 ;
F_326 ( V_11 -> V_112 -> V_198 ) ;
V_606 = F_14 ( V_11 , V_43 ) ;
V_664 =
V_606 & F_14 ( V_11 , V_320 ) ;
if ( V_606 )
F_49 ( V_11 , V_606 , V_43 ) ;
if ( V_664 ) {
F_325 ( V_11 , V_664 ) ;
V_665 = V_667 ;
}
F_327 ( V_11 -> V_112 -> V_198 ) ;
return V_665 ;
}
static int F_318 ( struct V_10 * V_11 , int V_12 )
{
int V_134 = 0 ;
T_3 V_130 = 1 << V_12 ;
unsigned long V_194 ;
if ( ! F_328 ( V_12 , & V_11 -> V_69 ) )
goto V_154;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_49 ( V_11 , ~ ( 1 << V_12 ) , V_668 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_134 = F_31 ( V_11 ,
V_201 ,
V_130 , 0 , 1000 , 1000 , true ) ;
V_154:
return V_134 ;
}
static int F_329 ( struct V_10 * V_11 , int V_669 , int V_670 ,
T_2 V_671 , T_2 * V_672 )
{
struct V_97 * V_152 ;
struct V_673 * V_674 ;
struct V_366 * V_112 ;
unsigned long V_194 ;
int V_153 ;
int V_134 ;
int V_263 ;
V_112 = V_11 -> V_112 ;
F_216 ( V_11 -> V_675 , F_43 ( V_11 , & V_153 ) ) ;
F_82 ( V_11 , false ) ;
F_83 ( V_112 -> V_198 , V_194 ) ;
V_152 = V_11 -> V_99 ;
V_152 += V_153 ;
V_152 -> V_100 . V_163 = F_179 ( V_339 ) ;
V_152 -> V_100 . V_150 =
F_179 ( V_340 ) ;
V_674 =
(struct V_673 * ) V_152 -> V_102 ;
V_263 = V_11 -> V_13 + V_153 ;
V_674 -> V_100 . V_163 =
F_187 ( V_676 , 0 ,
V_669 , V_263 ) ;
V_674 -> V_100 . V_164 =
F_187 ( 0 , V_671 , 0 , 0 ) ;
V_674 -> V_677 = F_188 ( V_669 ) ;
V_674 -> V_678 = F_188 ( V_670 ) ;
F_330 ( V_11 , V_153 , V_671 ) ;
F_154 ( V_153 , & V_11 -> V_69 ) ;
F_155 () ;
F_49 ( V_11 , 1 << V_153 , V_201 ) ;
F_155 () ;
F_84 ( V_112 -> V_198 , V_194 ) ;
V_134 = F_331 ( V_11 -> V_659 ,
F_328 ( V_153 , & V_11 -> V_658 ) ,
F_32 ( V_679 ) ) ;
if ( ! V_134 ) {
F_7 ( V_11 -> V_20 , L_159 ,
V_21 , V_671 ) ;
if ( F_318 ( V_11 , V_153 ) )
F_332 ( V_11 -> V_20 , L_160 ,
V_21 , V_153 ) ;
V_134 = - V_137 ;
} else {
V_134 = F_293 ( V_11 , V_153 , V_672 ) ;
}
F_333 ( V_153 , & V_11 -> V_658 ) ;
F_46 ( V_11 , V_153 ) ;
F_218 ( & V_11 -> V_675 ) ;
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_334 ( struct V_310 * V_32 )
{
struct V_366 * V_112 ;
struct V_10 * V_11 ;
unsigned int V_12 ;
T_3 V_61 ;
int V_134 ;
T_2 V_380 = 0xF ;
struct V_28 * V_29 ;
unsigned long V_194 ;
V_112 = V_32 -> V_216 -> V_112 ;
V_11 = F_197 ( V_112 ) ;
V_12 = V_32 -> V_36 -> V_12 ;
V_29 = & V_11 -> V_31 [ V_12 ] ;
V_134 = F_329 ( V_11 , V_29 -> V_344 , 0 , V_680 , & V_380 ) ;
if ( V_134 || V_380 != V_681 ) {
if ( ! V_134 )
V_134 = V_380 ;
goto V_154;
}
F_26 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_11 -> V_31 [ V_61 ] . V_344 == V_29 -> V_344 ) {
V_134 = F_206 ( V_11 , V_61 ) ;
if ( V_134 )
break;
}
}
F_83 ( V_112 -> V_198 , V_194 ) ;
F_300 ( V_11 ) ;
F_84 ( V_112 -> V_198 , V_194 ) ;
V_154:
V_11 -> V_117 = 0 ;
if ( ! V_134 ) {
V_134 = V_682 ;
} else {
F_7 ( V_11 -> V_20 , L_161 , V_21 , V_134 ) ;
V_134 = V_683 ;
}
return V_134 ;
}
static void F_335 ( struct V_10 * V_11 , unsigned long V_80 )
{
struct V_28 * V_29 ;
int V_12 ;
F_26 (tag, &bitmap, hba->nutrs) {
V_29 = & V_11 -> V_31 [ V_12 ] ;
V_29 -> V_376 = true ;
}
}
static int F_336 ( struct V_310 * V_32 )
{
struct V_366 * V_112 ;
struct V_10 * V_11 ;
unsigned long V_194 ;
unsigned int V_12 ;
int V_134 = 0 ;
int V_684 ;
T_2 V_380 = 0xF ;
struct V_28 * V_29 ;
T_3 V_62 ;
V_112 = V_32 -> V_216 -> V_112 ;
V_11 = F_197 ( V_112 ) ;
V_12 = V_32 -> V_36 -> V_12 ;
V_29 = & V_11 -> V_31 [ V_12 ] ;
if ( ! F_4 ( V_11 , V_12 ) ) {
F_7 ( V_11 -> V_20 ,
L_73 ,
V_21 , V_12 , V_32 , V_32 -> V_36 ) ;
F_198 () ;
}
if ( V_29 -> V_344 == V_575 )
return F_337 ( V_32 ) ;
F_82 ( V_11 , false ) ;
V_62 = F_14 ( V_11 , V_44 ) ;
if ( ! ( F_328 ( V_12 , & V_11 -> V_68 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_162 ,
V_21 , V_12 , V_11 -> V_68 , V_62 ) ;
goto V_154;
}
if ( ! ( V_62 & ( 1 << V_12 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_163 ,
V_21 , V_12 ) ;
}
F_7 ( V_11 -> V_20 , L_164 , V_21 , V_12 ) ;
F_338 ( V_11 -> V_31 [ V_12 ] . V_32 ) ;
if ( ! V_11 -> V_117 ) {
F_23 ( V_11 ) ;
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
F_25 ( V_11 , 1 << V_12 , true ) ;
} else {
F_25 ( V_11 , 1 << V_12 , false ) ;
}
V_11 -> V_117 ++ ;
if ( V_29 -> V_376 ) {
V_134 = - V_305 ;
goto V_154;
}
for ( V_684 = 100 ; V_684 ; V_684 -- ) {
V_134 = F_329 ( V_11 , V_29 -> V_344 , V_29 -> V_263 ,
V_685 , & V_380 ) ;
if ( ! V_134 && V_380 == V_686 ) {
F_7 ( V_11 -> V_20 , L_165 ,
V_21 , V_12 ) ;
break;
} else if ( ! V_134 && V_380 == V_681 ) {
F_7 ( V_11 -> V_20 , L_166 ,
V_21 , V_12 ) ;
V_62 = F_14 ( V_11 , V_44 ) ;
if ( V_62 & ( 1 << V_12 ) ) {
F_33 ( 100 , 200 ) ;
continue;
}
F_7 ( V_11 -> V_20 , L_167 ,
V_21 , V_12 ) ;
goto V_154;
} else {
F_7 ( V_11 -> V_20 ,
L_168 ,
V_21 , V_12 , V_134 ) ;
if ( ! V_134 )
V_134 = V_380 ;
goto V_154;
}
}
if ( ! V_684 ) {
V_134 = - V_200 ;
goto V_154;
}
V_134 = F_329 ( V_11 , V_29 -> V_344 , V_29 -> V_263 ,
V_687 , & V_380 ) ;
if ( V_134 || V_380 != V_681 ) {
if ( ! V_134 ) {
V_134 = V_380 ;
F_7 ( V_11 -> V_20 , L_169 ,
V_21 , V_12 , V_134 ) ;
}
goto V_154;
}
V_134 = F_206 ( V_11 , V_12 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_170 ,
V_21 , V_12 , V_134 ) ;
goto V_154;
}
F_299 ( V_32 ) ;
F_83 ( V_112 -> V_198 , V_194 ) ;
F_50 ( V_11 , V_12 ) ;
V_11 -> V_31 [ V_12 ] . V_32 = NULL ;
F_84 ( V_112 -> V_198 , V_194 ) ;
F_47 ( V_12 , & V_11 -> V_105 ) ;
F_218 ( & V_11 -> V_274 . V_391 ) ;
V_154:
if ( ! V_134 ) {
V_134 = V_682 ;
} else {
F_7 ( V_11 -> V_20 , L_161 , V_21 , V_134 ) ;
F_335 ( V_11 , V_11 -> V_68 ) ;
V_134 = V_683 ;
}
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_257 ( struct V_10 * V_11 )
{
int V_134 ;
unsigned long V_194 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_270 ( V_11 , false ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_71 ( V_11 , true ) ;
V_134 = F_271 ( V_11 ) ;
if ( V_134 )
goto V_154;
V_134 = F_339 ( V_11 ) ;
if ( ! V_134 && ( V_11 -> V_104 != V_199 ) )
V_134 = - V_305 ;
V_154:
if ( V_134 )
F_7 ( V_11 -> V_20 , L_171 , V_21 , V_134 ) ;
return V_134 ;
}
static int F_319 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
unsigned long V_194 ;
int V_400 = V_688 ;
do {
V_134 = F_257 ( V_11 ) ;
} while ( V_134 && -- V_400 );
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_300 ( V_11 ) ;
F_315 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
return V_134 ;
}
static int F_337 ( struct V_310 * V_32 )
{
int V_134 ;
unsigned long V_194 ;
struct V_10 * V_11 ;
V_11 = F_197 ( V_32 -> V_216 -> V_112 ) ;
F_82 ( V_11 , false ) ;
do {
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( ! ( F_340 ( & V_11 -> V_634 ) ||
V_11 -> V_104 == V_369 ||
V_11 -> V_104 == V_368 ) )
break;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_76 ( V_11 -> V_20 , L_172 , V_21 ) ;
F_130 ( & V_11 -> V_634 ) ;
} while ( 1 );
V_11 -> V_104 = V_369 ;
F_256 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_134 = F_319 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( ! V_134 ) {
V_134 = V_682 ;
V_11 -> V_104 = V_199 ;
} else {
V_134 = V_683 ;
V_11 -> V_104 = V_371 ;
}
F_258 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
F_86 ( V_11 ) ;
return V_134 ;
}
static T_3 F_341 ( int V_689 , T_3 V_690 , char * V_691 )
{
int V_58 ;
int V_692 ;
T_7 V_693 ;
T_7 V_694 ;
for ( V_58 = V_690 ; V_58 >= 0 ; V_58 -- ) {
V_693 = F_342 ( ( V_695 * ) & V_691 [ 2 * V_58 ] ) ;
V_694 = ( V_693 & V_696 ) >>
V_697 ;
V_692 = V_693 & V_698 ;
switch ( V_694 ) {
case V_699 :
V_692 = V_692 / 1000 ;
break;
case V_700 :
V_692 = V_692 * 1000 ;
break;
case V_701 :
V_692 = V_692 * 1000 * 1000 ;
break;
case V_702 :
default:
break;
}
if ( V_689 >= V_692 )
break;
}
if ( V_58 < 0 ) {
V_58 = 0 ;
F_343 ( L_173 , V_21 , V_58 ) ;
}
return ( T_3 ) V_58 ;
}
static T_3 F_344 ( struct V_10 * V_11 ,
T_2 * V_416 , int V_264 )
{
T_3 V_703 = 0 ;
if ( ! V_11 -> V_704 . V_705 || ! V_11 -> V_704 . V_706 ||
! V_11 -> V_704 . V_707 ) {
F_7 ( V_11 -> V_20 ,
L_174 ,
V_21 , V_703 ) ;
goto V_154;
}
if ( V_11 -> V_704 . V_705 )
V_703 = F_341 (
V_11 -> V_704 . V_705 -> V_708 ,
V_709 - 1 ,
& V_416 [ V_710 ] ) ;
if ( V_11 -> V_704 . V_706 )
V_703 = F_341 (
V_11 -> V_704 . V_706 -> V_708 ,
V_703 ,
& V_416 [ V_711 ] ) ;
if ( V_11 -> V_704 . V_707 )
V_703 = F_341 (
V_11 -> V_704 . V_707 -> V_708 ,
V_703 ,
& V_416 [ V_712 ] ) ;
V_154:
return V_703 ;
}
static void F_345 ( struct V_10 * V_11 )
{
int V_14 ;
int V_447 = V_11 -> V_429 . V_432 ;
T_2 V_416 [ V_11 -> V_429 . V_432 ] ;
V_14 = F_234 ( V_11 , V_416 , V_447 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 ,
L_175 ,
V_21 , V_447 , V_14 ) ;
return;
}
V_11 -> V_713 . V_703 =
F_344 ( V_11 ,
V_416 , V_447 ) ;
F_76 ( V_11 -> V_20 , L_176 ,
V_21 , V_11 -> V_713 . V_703 ) ;
V_14 = F_224 ( V_11 , V_413 ,
V_714 , 0 , 0 ,
& V_11 -> V_713 . V_703 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 ,
L_177 ,
V_21 , V_11 -> V_713 . V_703 , V_14 ) ;
}
static int F_346 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
struct V_556 * V_715 ;
struct V_556 * V_716 ;
V_11 -> V_576 = F_347 ( V_11 -> V_112 , 0 , 0 ,
F_195 ( V_575 ) , NULL ) ;
if ( F_348 ( V_11 -> V_576 ) ) {
V_14 = F_349 ( V_11 -> V_576 ) ;
V_11 -> V_576 = NULL ;
goto V_154;
}
F_350 ( V_11 -> V_576 ) ;
V_716 = F_347 ( V_11 -> V_112 , 0 , 0 ,
F_195 ( V_717 ) , NULL ) ;
if ( F_348 ( V_716 ) ) {
V_14 = F_349 ( V_716 ) ;
goto V_718;
}
F_350 ( V_716 ) ;
V_715 = F_347 ( V_11 -> V_112 , 0 , 0 ,
F_195 ( V_457 ) , NULL ) ;
if ( F_348 ( V_715 ) ) {
V_14 = F_349 ( V_715 ) ;
goto V_719;
}
F_350 ( V_715 ) ;
goto V_154;
V_719:
F_351 ( V_716 ) ;
V_718:
F_351 ( V_11 -> V_576 ) ;
V_154:
return V_14 ;
}
static int F_352 ( struct V_10 * V_11 ,
struct V_720 * V_430 )
{
int V_134 ;
T_2 V_721 ;
T_2 V_722 [ V_418 + 1 ] = { 0 } ;
T_2 V_416 [ V_11 -> V_429 . V_430 ] ;
V_134 = F_235 ( V_11 , V_416 , V_11 -> V_429 . V_430 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_178 ,
V_21 , V_134 ) ;
goto V_154;
}
V_430 -> V_723 = V_416 [ V_724 ] << 8 |
V_416 [ V_724 + 1 ] ;
V_721 = V_416 [ V_725 ] ;
V_134 = F_236 ( V_11 , V_721 , V_722 ,
V_418 , V_726 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_179 ,
V_21 , V_134 ) ;
goto V_154;
}
V_722 [ V_418 ] = '\0' ;
F_353 ( V_430 -> V_727 , ( V_722 + V_422 ) ,
F_158 ( T_2 , V_722 [ V_426 ] ,
V_728 ) ) ;
V_430 -> V_727 [ V_728 ] = '\0' ;
V_154:
return V_134 ;
}
static void F_354 ( struct V_10 * V_11 ,
struct V_720 * V_430 )
{
struct V_729 * V_730 ;
for ( V_730 = V_731 ; V_730 -> V_732 ; V_730 ++ ) {
if ( ( V_730 -> V_733 . V_723 == V_430 -> V_723 ||
V_730 -> V_733 . V_723 == V_734 ) &&
( F_355 ( V_730 -> V_733 . V_727 , V_430 -> V_727 ) ||
! strcmp ( V_730 -> V_733 . V_727 , V_735 ) ) )
V_11 -> V_120 |= V_730 -> V_732 ;
}
}
static int F_356 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_3 V_736 = 0 , V_737 ;
V_14 = F_265 ( V_11 ,
F_253 (
V_738 ,
F_357 ( 0 ) ) ,
& V_736 ) ;
if ( V_14 )
goto V_154;
V_737 =
( ( V_736 * V_739 )
/ V_740 ) ;
V_14 = F_252 ( V_11 , F_254 ( V_741 ) ,
V_737 ) ;
V_154:
return V_14 ;
}
static int F_358 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_3 V_742 = 0 , V_743 = 0 ;
T_3 V_744 , V_745 ;
V_14 = F_264 ( V_11 ,
F_253 ( V_746 ,
F_276 ( 0 ) ) ,
& V_742 ) ;
if ( V_14 )
goto V_154;
V_14 = F_265 ( V_11 ,
F_253 ( V_747 ,
F_357 ( 0 ) ) ,
& V_743 ) ;
if ( V_14 )
goto V_154;
V_744 = F_359 ( V_742 ,
V_743 ) ;
V_745 = ( ( V_744 * V_748 )
/ V_749 ) ;
V_14 = F_252 ( V_11 , F_254 ( V_750 ) ,
V_745 ) ;
V_154:
return V_14 ;
}
static int F_360 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_3 V_751 , V_752 ;
T_3 V_753 , V_754 ;
T_3 V_755 , V_756 ;
T_2 V_757 [] = { 1 , 4 , 8 , 16 , 32 , 100 } ;
V_14 = F_264 ( V_11 , F_254 ( V_758 ) ,
& V_751 ) ;
if ( V_14 )
goto V_154;
V_14 = F_265 ( V_11 , F_254 ( V_758 ) ,
& V_752 ) ;
if ( V_14 )
goto V_154;
if ( ( V_751 < V_759 ) ||
( V_751 > V_760 ) ) {
F_7 ( V_11 -> V_20 , L_180 ,
V_21 , V_751 ) ;
return - V_219 ;
}
if ( ( V_752 < V_759 ) ||
( V_752 > V_760 ) ) {
F_7 ( V_11 -> V_20 , L_181 ,
V_21 , V_752 ) ;
return - V_219 ;
}
V_14 = F_264 ( V_11 , F_254 ( V_741 ) , & V_753 ) ;
if ( V_14 )
goto V_154;
V_14 = F_265 ( V_11 , F_254 ( V_741 ) ,
& V_754 ) ;
if ( V_14 )
goto V_154;
V_755 = V_753 * V_757 [ V_751 - 1 ] ;
V_756 = V_754 *
V_757 [ V_752 - 1 ] ;
if ( V_755 > V_756 ) {
T_3 V_761 ;
V_761 = V_755 /
V_757 [ V_752 - 1 ] ;
V_761 ++ ;
V_14 = F_277 ( V_11 , F_254 ( V_741 ) ,
V_761 ) ;
}
V_154:
return V_14 ;
}
static void F_361 ( struct V_10 * V_11 )
{
if ( F_70 ( V_11 ) ) {
F_356 ( V_11 ) ;
F_358 ( V_11 ) ;
}
if ( V_11 -> V_120 & V_762 )
F_252 ( V_11 , F_254 ( V_741 ) , 10 ) ;
if ( V_11 -> V_120 & V_763 )
F_360 ( V_11 ) ;
F_362 ( V_11 ) ;
}
static void F_363 ( struct V_10 * V_11 )
{
int V_764 = sizeof( struct V_55 ) ;
V_11 -> V_70 . V_72 = 0 ;
V_11 -> V_70 . V_71 = F_209 ( 0 , 0 ) ;
memset ( & V_11 -> V_70 . V_73 , 0 , V_764 ) ;
memset ( & V_11 -> V_70 . V_74 , 0 , V_764 ) ;
memset ( & V_11 -> V_70 . V_75 , 0 , V_764 ) ;
memset ( & V_11 -> V_70 . V_76 , 0 , V_764 ) ;
memset ( & V_11 -> V_70 . V_77 , 0 , V_764 ) ;
V_11 -> V_117 = 0 ;
}
static void F_364 ( struct V_10 * V_11 )
{
int V_134 ;
V_134 = F_228 ( V_11 , V_428 , 0 ,
& V_11 -> V_429 . V_430 ) ;
if ( V_134 )
V_11 -> V_429 . V_430 = V_765 ;
V_134 = F_228 ( V_11 , V_431 , 0 ,
& V_11 -> V_429 . V_432 ) ;
if ( V_134 )
V_11 -> V_429 . V_432 = V_766 ;
V_134 = F_228 ( V_11 , V_439 , 0 ,
& V_11 -> V_429 . V_440 ) ;
if ( V_134 )
V_11 -> V_429 . V_440 = V_767 ;
V_134 = F_228 ( V_11 , V_435 , 0 ,
& V_11 -> V_429 . V_436 ) ;
if ( V_134 )
V_11 -> V_429 . V_436 = V_768 ;
V_134 = F_228 ( V_11 , V_437 , 0 ,
& V_11 -> V_429 . V_438 ) ;
if ( V_134 )
V_11 -> V_429 . V_438 = V_769 ;
V_134 = F_228 ( V_11 , V_433 , 0 ,
& V_11 -> V_429 . V_434 ) ;
if ( V_134 )
V_11 -> V_429 . V_434 = V_770 ;
}
static void F_365 ( struct V_10 * V_11 )
{
V_11 -> V_429 . V_430 = V_765 ;
V_11 -> V_429 . V_432 = V_766 ;
V_11 -> V_429 . V_440 = V_767 ;
V_11 -> V_429 . V_436 = V_768 ;
V_11 -> V_429 . V_438 = V_769 ;
V_11 -> V_429 . V_434 = V_770 ;
}
static int F_339 ( struct V_10 * V_11 )
{
struct V_720 V_733 = { 0 } ;
int V_14 ;
T_4 V_189 = F_72 () ;
V_14 = F_279 ( V_11 ) ;
if ( V_14 )
goto V_154;
V_11 -> V_618 = V_622 ;
V_11 -> V_620 = false ;
F_363 ( V_11 ) ;
F_128 ( V_11 ) ;
V_14 = F_282 ( V_11 ) ;
if ( V_14 )
goto V_154;
V_14 = F_268 ( V_11 ) ;
if ( V_14 )
goto V_154;
F_364 ( V_11 ) ;
V_14 = F_352 ( V_11 , & V_733 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_182 ,
V_21 , V_14 ) ;
goto V_154;
}
F_354 ( V_11 , & V_733 ) ;
F_361 ( V_11 ) ;
V_14 = F_366 ( V_11 ,
( V_11 -> V_120 & V_771 ) ? true : false ) ;
if ( V_14 )
goto V_154;
F_367 ( V_11 ) ;
F_306 ( V_11 ) ;
V_11 -> V_772 = true ;
if ( F_263 ( V_11 ) ) {
F_7 ( V_11 -> V_20 ,
L_183 ,
V_21 ) ;
} else {
V_14 = F_267 ( V_11 , & V_11 -> V_520 . V_206 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_184 ,
V_21 , V_14 ) ;
goto V_154;
}
}
V_11 -> V_104 = V_199 ;
if ( ! F_106 ( V_11 ) && ! V_11 -> V_109 ) {
bool V_773 ;
memset ( & V_11 -> V_563 , 0 , sizeof( V_11 -> V_563 ) ) ;
if ( ! F_220 ( V_11 , V_408 ,
V_774 , & V_773 ) )
V_11 -> V_563 . V_564 = V_773 ;
if ( ! V_11 -> V_775 )
F_345 ( V_11 ) ;
if ( F_346 ( V_11 ) )
goto V_154;
if ( F_105 ( V_11 ) ) {
memcpy ( & V_11 -> V_204 . V_205 . V_206 ,
& V_11 -> V_122 ,
sizeof( struct V_202 ) ) ;
V_11 -> V_204 . V_205 . V_521 = true ;
if ( ! V_11 -> V_215 ) {
V_11 -> V_215 = F_368 ( V_11 -> V_20 ,
& V_776 ,
L_185 ,
NULL ) ;
if ( F_348 ( V_11 -> V_215 ) ) {
V_14 = F_349 ( V_11 -> V_215 ) ;
F_7 ( V_11 -> V_20 , L_186 ,
V_14 ) ;
goto V_154;
}
}
V_11 -> V_204 . V_239 = true ;
}
F_369 ( V_11 -> V_112 ) ;
F_118 ( V_11 -> V_20 ) ;
}
if ( ! V_11 -> V_775 )
V_11 -> V_775 = true ;
V_154:
if ( V_14 && ! F_106 ( V_11 ) && ! V_11 -> V_109 ) {
F_118 ( V_11 -> V_20 ) ;
F_370 ( V_11 ) ;
}
F_371 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_189 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
return V_14 ;
}
static void F_372 ( void * V_693 , T_10 V_777 )
{
struct V_10 * V_11 = (struct V_10 * ) V_693 ;
F_339 ( V_11 ) ;
}
static enum V_778 F_373 ( struct V_310 * V_779 )
{
unsigned long V_194 ;
struct V_366 * V_112 ;
struct V_10 * V_11 ;
int V_396 ;
bool V_780 = false ;
if ( ! V_779 || ! V_779 -> V_216 || ! V_779 -> V_216 -> V_112 )
return V_781 ;
V_112 = V_779 -> V_216 -> V_112 ;
V_11 = F_197 ( V_112 ) ;
if ( ! V_11 )
return V_781 ;
F_83 ( V_112 -> V_198 , V_194 ) ;
F_26 (index, &hba->outstanding_reqs, hba->nutrs) {
if ( V_11 -> V_31 [ V_396 ] . V_32 == V_779 ) {
V_780 = true ;
break;
}
}
F_84 ( V_112 -> V_198 , V_194 ) ;
return V_780 ? V_781 : V_782 ;
}
static int F_374 ( struct V_216 * V_20 , struct V_783 * V_784 ,
int V_785 )
{
int V_14 ;
if ( ! V_784 )
return 0 ;
V_14 = F_375 ( V_784 -> V_62 , V_785 ) ;
if ( V_14 < 0 ) {
F_7 ( V_20 , L_187 ,
V_21 , V_784 -> V_53 , V_785 , V_14 ) ;
}
return V_14 ;
}
static inline int F_376 ( struct V_10 * V_11 ,
struct V_783 * V_784 )
{
if ( ! V_784 )
return 0 ;
else if ( V_784 -> V_786 )
return 0 ;
else
return F_374 ( V_11 -> V_20 , V_784 ,
V_787 ) ;
}
static inline int F_377 ( struct V_10 * V_11 ,
struct V_783 * V_784 )
{
if ( ! V_784 )
return 0 ;
else if ( V_784 -> V_786 )
return 0 ;
else
return F_374 ( V_11 -> V_20 , V_784 , V_784 -> V_708 ) ;
}
static int F_378 ( struct V_216 * V_20 ,
struct V_783 * V_784 , bool V_788 )
{
int V_14 = 0 ;
struct V_789 * V_62 = V_784 -> V_62 ;
const char * V_53 = V_784 -> V_53 ;
int V_790 , V_791 ;
F_222 ( ! V_784 ) ;
if ( F_379 ( V_62 ) > 0 ) {
V_790 = V_788 ? V_784 -> V_790 : 0 ;
V_14 = F_380 ( V_62 , V_790 , V_784 -> V_792 ) ;
if ( V_14 ) {
F_7 ( V_20 , L_188 ,
V_21 , V_53 , V_14 ) ;
goto V_154;
}
V_791 = V_788 ? V_784 -> V_708 : 0 ;
V_14 = F_374 ( V_20 , V_784 , V_791 ) ;
if ( V_14 )
goto V_154;
}
V_154:
return V_14 ;
}
static int F_381 ( struct V_216 * V_20 , struct V_783 * V_784 )
{
int V_14 = 0 ;
if ( ! V_784 )
goto V_154;
else if ( V_784 -> V_793 || V_784 -> V_786 )
goto V_154;
V_14 = F_378 ( V_20 , V_784 , true ) ;
if ( ! V_14 )
V_14 = F_382 ( V_784 -> V_62 ) ;
if ( ! V_14 )
V_784 -> V_793 = true ;
else
F_7 ( V_20 , L_189 ,
V_21 , V_784 -> V_53 , V_14 ) ;
V_154:
return V_14 ;
}
static int F_383 ( struct V_216 * V_20 , struct V_783 * V_784 )
{
int V_14 = 0 ;
if ( ! V_784 )
goto V_154;
else if ( ! V_784 -> V_793 || V_784 -> V_786 )
goto V_154;
V_14 = F_384 ( V_784 -> V_62 ) ;
if ( ! V_14 ) {
F_378 ( V_20 , V_784 , false ) ;
V_784 -> V_793 = false ;
} else {
F_7 ( V_20 , L_190 ,
V_21 , V_784 -> V_53 , V_14 ) ;
}
V_154:
return V_14 ;
}
static int F_385 ( struct V_10 * V_11 , bool V_788 )
{
int V_14 = 0 ;
struct V_216 * V_20 = V_11 -> V_20 ;
struct V_794 * V_206 = & V_11 -> V_704 ;
if ( ! V_206 )
goto V_154;
V_14 = F_386 ( V_20 , V_206 -> V_705 , V_788 ) ;
if ( V_14 )
goto V_154;
V_14 = F_386 ( V_20 , V_206 -> V_706 , V_788 ) ;
if ( V_14 )
goto V_154;
V_14 = F_386 ( V_20 , V_206 -> V_707 , V_788 ) ;
if ( V_14 )
goto V_154;
V_154:
if ( V_14 ) {
F_386 ( V_20 , V_206 -> V_707 , false ) ;
F_386 ( V_20 , V_206 -> V_706 , false ) ;
F_386 ( V_20 , V_206 -> V_705 , false ) ;
}
return V_14 ;
}
static int F_387 ( struct V_10 * V_11 , bool V_788 )
{
struct V_794 * V_206 = & V_11 -> V_704 ;
if ( V_206 )
return F_386 ( V_11 -> V_20 , V_206 -> V_795 , V_788 ) ;
return 0 ;
}
static int F_388 ( struct V_216 * V_20 , struct V_783 * V_784 )
{
int V_14 = 0 ;
if ( ! V_784 )
goto V_154;
V_784 -> V_62 = F_389 ( V_20 , V_784 -> V_53 ) ;
if ( F_348 ( V_784 -> V_62 ) ) {
V_14 = F_349 ( V_784 -> V_62 ) ;
F_7 ( V_20 , L_191 ,
V_21 , V_784 -> V_53 , V_14 ) ;
}
V_154:
return V_14 ;
}
static int F_390 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
struct V_216 * V_20 = V_11 -> V_20 ;
struct V_794 * V_206 = & V_11 -> V_704 ;
if ( ! V_206 )
goto V_154;
V_14 = F_388 ( V_20 , V_206 -> V_705 ) ;
if ( V_14 )
goto V_154;
V_14 = F_388 ( V_20 , V_206 -> V_706 ) ;
if ( V_14 )
goto V_154;
V_14 = F_388 ( V_20 , V_206 -> V_707 ) ;
V_154:
return V_14 ;
}
static int F_391 ( struct V_10 * V_11 )
{
struct V_794 * V_206 = & V_11 -> V_704 ;
if ( V_206 )
return F_388 ( V_11 -> V_20 , V_206 -> V_795 ) ;
return 0 ;
}
static int F_366 ( struct V_10 * V_11 , bool V_786 )
{
int V_14 = 0 ;
struct V_794 * V_206 = & V_11 -> V_704 ;
if ( ! V_206 )
goto V_154;
else if ( ! V_206 -> V_706 )
goto V_154;
if ( V_786 ) {
V_14 = F_386 ( V_11 -> V_20 , V_206 -> V_706 , false ) ;
if ( ! V_14 )
V_206 -> V_706 -> V_786 = true ;
} else {
V_206 -> V_706 -> V_786 = false ;
}
V_154:
return V_14 ;
}
static int F_138 ( struct V_10 * V_11 , bool V_788 ,
bool V_796 )
{
int V_14 = 0 ;
struct V_45 * V_46 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
unsigned long V_194 ;
T_4 V_189 = F_72 () ;
bool V_190 = false ;
if ( F_18 ( V_48 ) )
goto V_154;
V_14 = F_392 ( V_11 , V_788 , V_191 ) ;
if ( V_14 )
return V_14 ;
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) ) {
if ( V_796 && ! strcmp ( V_46 -> V_53 , L_192 ) )
continue;
V_190 = V_788 ^ V_46 -> V_793 ;
if ( V_788 && ! V_46 -> V_793 ) {
V_14 = F_393 ( V_46 -> V_50 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_193 ,
V_21 , V_46 -> V_53 , V_14 ) ;
goto V_154;
}
} else if ( ! V_788 && V_46 -> V_793 ) {
F_394 ( V_46 -> V_50 ) ;
}
V_46 -> V_793 = V_788 ;
F_76 ( V_11 -> V_20 , L_194 , V_21 ,
V_46 -> V_53 , V_788 ? L_195 : L_196 ) ;
}
}
V_14 = F_392 ( V_11 , V_788 , V_192 ) ;
if ( V_14 )
return V_14 ;
V_154:
if ( V_14 ) {
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) && V_46 -> V_793 )
F_394 ( V_46 -> V_50 ) ;
}
} else if ( ! V_14 && V_788 ) {
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_11 -> V_114 . V_115 = V_248 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
}
if ( V_190 )
F_395 ( F_16 ( V_11 -> V_20 ) ,
( V_788 ? L_197 : L_198 ) ,
F_22 ( F_79 ( F_72 () , V_189 ) ) , V_14 ) ;
return V_14 ;
}
static int F_124 ( struct V_10 * V_11 , bool V_788 )
{
return F_138 ( V_11 , V_788 , false ) ;
}
static int F_396 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
struct V_45 * V_46 ;
struct V_216 * V_20 = V_11 -> V_20 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
if ( F_18 ( V_48 ) )
goto V_154;
F_19 (clki, head, list) {
if ( ! V_46 -> V_53 )
continue;
V_46 -> V_50 = F_397 ( V_20 , V_46 -> V_53 ) ;
if ( F_348 ( V_46 -> V_50 ) ) {
V_14 = F_349 ( V_46 -> V_50 ) ;
F_7 ( V_20 , L_199 ,
V_21 , V_46 -> V_53 , V_14 ) ;
goto V_154;
}
if ( V_46 -> V_52 ) {
V_14 = F_74 ( V_46 -> V_50 , V_46 -> V_52 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_50 ,
V_21 , V_46 -> V_53 ,
V_46 -> V_52 , V_14 ) ;
goto V_154;
}
V_46 -> V_54 = V_46 -> V_52 ;
}
F_76 ( V_20 , L_53 , V_21 ,
V_46 -> V_53 , F_77 ( V_46 -> V_50 ) ) ;
}
V_154:
return V_14 ;
}
static int F_398 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
if ( ! V_11 -> V_78 )
goto V_154;
V_134 = F_399 ( V_11 ) ;
if ( V_134 )
goto V_154;
V_134 = F_400 ( V_11 , true ) ;
if ( V_134 )
goto V_797;
goto V_154;
V_797:
F_401 ( V_11 ) ;
V_154:
if ( V_134 )
F_7 ( V_11 -> V_20 , L_200 ,
V_21 , F_402 ( V_11 ) , V_134 ) ;
return V_134 ;
}
static void F_403 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_78 )
return;
F_400 ( V_11 , false ) ;
F_401 ( V_11 ) ;
}
static int F_404 ( struct V_10 * V_11 )
{
int V_134 ;
V_134 = F_391 ( V_11 ) ;
if ( V_134 )
goto V_154;
V_134 = F_387 ( V_11 , true ) ;
if ( V_134 )
goto V_154;
V_134 = F_396 ( V_11 ) ;
if ( V_134 )
goto V_798;
V_134 = F_124 ( V_11 , true ) ;
if ( V_134 )
goto V_798;
V_134 = F_390 ( V_11 ) ;
if ( V_134 )
goto V_799;
V_134 = F_385 ( V_11 , true ) ;
if ( V_134 )
goto V_799;
V_134 = F_398 ( V_11 ) ;
if ( V_134 )
goto V_800;
V_11 -> V_801 = true ;
goto V_154;
V_800:
F_385 ( V_11 , false ) ;
V_799:
F_124 ( V_11 , false ) ;
V_798:
F_387 ( V_11 , false ) ;
V_154:
return V_134 ;
}
static void F_370 ( struct V_10 * V_11 )
{
if ( V_11 -> V_801 ) {
F_403 ( V_11 ) ;
F_385 ( V_11 , false ) ;
F_111 ( V_11 ) ;
if ( F_105 ( V_11 ) ) {
if ( V_11 -> V_215 )
F_111 ( V_11 ) ;
F_405 ( V_11 -> V_204 . V_221 ) ;
}
F_124 ( V_11 , false ) ;
F_387 ( V_11 , false ) ;
V_11 -> V_801 = false ;
}
}
static int
F_406 ( struct V_10 * V_11 , struct V_556 * V_802 )
{
unsigned char V_32 [ 6 ] = { V_803 ,
0 ,
0 ,
0 ,
V_271 ,
0 } ;
char * V_804 ;
int V_14 ;
V_804 = F_407 ( V_271 , V_449 ) ;
if ( ! V_804 ) {
V_14 = - V_450 ;
goto V_154;
}
V_14 = F_408 ( V_802 , V_32 , V_328 , V_804 ,
V_271 , NULL , NULL ,
F_32 ( 1000 ) , 3 , 0 , V_805 , NULL ) ;
if ( V_14 )
F_343 ( L_161 , V_21 , V_14 ) ;
F_232 ( V_804 ) ;
V_154:
return V_14 ;
}
static int F_409 ( struct V_10 * V_11 ,
enum V_1 V_527 )
{
unsigned char V_32 [ 6 ] = { V_806 } ;
struct V_807 V_808 ;
struct V_556 * V_802 ;
unsigned long V_194 ;
int V_14 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
V_802 = V_11 -> V_576 ;
if ( V_802 ) {
V_14 = F_410 ( V_802 ) ;
if ( ! V_14 && ! F_411 ( V_802 ) ) {
V_14 = - V_809 ;
F_350 ( V_802 ) ;
}
} else {
V_14 = - V_809 ;
}
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_14 )
return V_14 ;
V_11 -> V_112 -> V_810 = 1 ;
if ( V_11 -> V_772 ) {
V_14 = F_406 ( V_11 , V_802 ) ;
if ( V_14 )
goto V_154;
V_11 -> V_772 = false ;
}
V_32 [ 4 ] = V_527 << 4 ;
V_14 = F_408 ( V_802 , V_32 , V_356 , NULL , 0 , NULL , & V_808 ,
V_811 , 0 , 0 , V_805 , NULL ) ;
if ( V_14 ) {
F_412 ( V_812 , V_802 ,
L_201 ,
V_527 , V_14 ) ;
if ( F_413 ( V_14 ) & V_813 )
F_414 ( V_802 , NULL , & V_808 ) ;
}
if ( ! V_14 )
V_11 -> V_108 = V_527 ;
V_154:
F_350 ( V_802 ) ;
V_11 -> V_112 -> V_810 = 0 ;
return V_14 ;
}
static int F_415 ( struct V_10 * V_11 ,
enum V_6 V_814 ,
int V_815 )
{
int V_14 = 0 ;
if ( V_814 == V_11 -> V_6 )
return 0 ;
if ( V_814 == V_182 ) {
V_14 = F_135 ( V_11 ) ;
if ( ! V_14 )
F_136 ( V_11 ) ;
else
goto V_154;
}
else if ( ( V_814 == V_180 ) &&
( ! V_815 || ( V_815 &&
! V_11 -> V_111 ) ) ) {
V_14 = F_135 ( V_11 ) ;
if ( V_14 )
goto V_154;
F_270 ( V_11 , true ) ;
F_272 ( V_11 ) ;
}
V_154:
return V_14 ;
}
static void F_416 ( struct V_10 * V_11 )
{
if ( ! F_137 ( V_11 ) &&
V_11 -> V_120 & V_816 )
F_33 ( 2000 , 2100 ) ;
if ( F_417 ( V_11 ) && F_418 ( V_11 ) &&
! V_11 -> V_563 . V_565 ) {
F_385 ( V_11 , false ) ;
} else if ( ! F_280 ( V_11 ) ) {
F_386 ( V_11 -> V_20 , V_11 -> V_704 . V_705 , false ) ;
if ( ! F_137 ( V_11 ) ) {
F_376 ( V_11 , V_11 -> V_704 . V_706 ) ;
F_376 ( V_11 , V_11 -> V_704 . V_707 ) ;
}
}
}
static int F_419 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
if ( F_417 ( V_11 ) && F_418 ( V_11 ) &&
! V_11 -> V_563 . V_565 ) {
V_14 = F_385 ( V_11 , true ) ;
} else if ( ! F_280 ( V_11 ) ) {
if ( ! V_14 && ! F_137 ( V_11 ) ) {
V_14 = F_377 ( V_11 , V_11 -> V_704 . V_706 ) ;
if ( V_14 )
goto V_817;
V_14 = F_377 ( V_11 , V_11 -> V_704 . V_707 ) ;
if ( V_14 )
goto V_818;
}
V_14 = F_386 ( V_11 -> V_20 , V_11 -> V_704 . V_705 , true ) ;
}
goto V_154;
V_818:
F_376 ( V_11 , V_11 -> V_704 . V_706 ) ;
V_817:
F_386 ( V_11 -> V_20 , V_11 -> V_704 . V_705 , false ) ;
V_154:
return V_14 ;
}
static void F_420 ( struct V_10 * V_11 )
{
if ( F_418 ( V_11 ) )
F_387 ( V_11 , false ) ;
}
static void F_421 ( struct V_10 * V_11 )
{
if ( F_418 ( V_11 ) )
F_387 ( V_11 , true ) ;
}
static int F_422 ( struct V_10 * V_11 , enum V_819 V_820 )
{
int V_14 = 0 ;
enum V_2 V_821 ;
enum V_1 V_822 ;
enum V_6 V_814 ;
V_11 -> V_109 = 1 ;
if ( ! F_423 ( V_820 ) ) {
V_821 = F_424 ( V_820 ) ?
V_11 -> V_823 : V_11 -> V_824 ;
V_822 = F_1 ( V_821 ) ;
V_814 = F_2 ( V_821 ) ;
} else {
V_822 = V_185 ;
V_814 = V_180 ;
}
F_82 ( V_11 , false ) ;
V_11 -> V_114 . V_213 = true ;
if ( V_11 -> V_204 . V_239 ) {
F_117 ( & V_11 -> V_204 . V_210 ) ;
F_117 ( & V_11 -> V_204 . V_214 ) ;
F_111 ( V_11 ) ;
}
if ( V_822 == V_183 &&
V_814 == V_181 ) {
goto V_825;
}
if ( ( V_822 == V_11 -> V_108 ) &&
( V_814 == V_11 -> V_6 ) )
goto V_826;
if ( ! F_280 ( V_11 ) || ! F_137 ( V_11 ) ) {
V_14 = - V_219 ;
goto V_826;
}
if ( F_424 ( V_820 ) ) {
if ( F_425 ( V_11 ) ) {
V_14 = F_310 ( V_11 ) ;
if ( V_14 )
goto V_826;
} else {
F_305 ( V_11 ) ;
}
}
if ( ( V_822 != V_11 -> V_108 ) &&
( ( F_424 ( V_820 ) && ! V_11 -> V_111 ) ||
! F_424 ( V_820 ) ) ) {
F_305 ( V_11 ) ;
V_14 = F_409 ( V_11 , V_822 ) ;
if ( V_14 )
goto V_826;
}
V_14 = F_415 ( V_11 , V_814 , 1 ) ;
if ( V_14 )
goto V_827;
F_416 ( V_11 ) ;
V_825:
V_14 = F_426 ( V_11 , V_820 ) ;
if ( V_14 )
goto V_828;
if ( ! F_137 ( V_11 ) )
F_124 ( V_11 , false ) ;
else
F_138 ( V_11 , false , true ) ;
V_11 -> V_114 . V_115 = V_253 ;
F_132 ( F_16 ( V_11 -> V_20 ) , V_11 -> V_114 . V_115 ) ;
F_8 ( V_11 ) ;
F_420 ( V_11 ) ;
goto V_154;
V_828:
if ( V_11 -> V_204 . V_239 )
F_112 ( V_11 ) ;
F_419 ( V_11 ) ;
if ( F_126 ( V_11 ) && ! F_127 ( V_11 ) )
F_128 ( V_11 ) ;
else if ( F_418 ( V_11 ) )
F_257 ( V_11 ) ;
V_827:
if ( ! F_409 ( V_11 , V_183 ) )
F_305 ( V_11 ) ;
V_826:
if ( V_11 -> V_204 . V_239 )
F_112 ( V_11 ) ;
V_11 -> V_114 . V_213 = false ;
F_86 ( V_11 ) ;
V_154:
V_11 -> V_109 = 0 ;
return V_14 ;
}
static int F_427 ( struct V_10 * V_11 , enum V_819 V_820 )
{
int V_14 ;
enum V_6 V_829 ;
V_11 -> V_109 = 1 ;
V_829 = V_11 -> V_6 ;
F_421 ( V_11 ) ;
V_14 = F_124 ( V_11 , true ) ;
if ( V_14 )
goto V_154;
V_14 = F_5 ( V_11 ) ;
if ( V_14 )
goto V_830;
V_14 = F_419 ( V_11 ) ;
if ( V_14 )
goto V_830;
V_14 = F_428 ( V_11 , V_820 ) ;
if ( V_14 )
goto V_831;
if ( F_126 ( V_11 ) ) {
V_14 = F_127 ( V_11 ) ;
if ( ! V_14 )
F_128 ( V_11 ) ;
else
goto V_832;
} else if ( F_418 ( V_11 ) ) {
V_14 = F_257 ( V_11 ) ;
if ( V_14 || ! F_137 ( V_11 ) )
goto V_832;
}
if ( ! F_280 ( V_11 ) ) {
V_14 = F_409 ( V_11 , V_183 ) ;
if ( V_14 )
goto V_833;
}
if ( F_307 ( V_11 ) )
F_303 ( V_11 ) ;
else
F_310 ( V_11 ) ;
V_11 -> V_114 . V_213 = false ;
if ( V_11 -> V_204 . V_239 )
F_112 ( V_11 ) ;
F_86 ( V_11 ) ;
goto V_154;
V_833:
F_415 ( V_11 , V_829 , 0 ) ;
V_832:
F_426 ( V_11 , V_820 ) ;
V_831:
F_416 ( V_11 ) ;
V_830:
F_8 ( V_11 ) ;
if ( V_11 -> V_204 . V_239 )
F_111 ( V_11 ) ;
F_124 ( V_11 , false ) ;
V_154:
V_11 -> V_109 = 0 ;
return V_14 ;
}
int F_429 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_4 V_189 = F_72 () ;
if ( ! V_11 || ! V_11 -> V_801 )
return 0 ;
if ( ( F_1 ( V_11 -> V_824 ) ==
V_11 -> V_108 ) &&
( F_2 ( V_11 -> V_824 ) ==
V_11 -> V_6 ) )
goto V_154;
if ( F_430 ( V_11 -> V_20 ) ) {
V_14 = F_431 ( V_11 ) ;
if ( V_14 )
goto V_154;
}
V_14 = F_422 ( V_11 , V_834 ) ;
V_154:
F_432 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_189 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
if ( ! V_14 )
V_11 -> V_110 = true ;
return V_14 ;
}
int F_433 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_4 V_189 = F_72 () ;
if ( ! V_11 )
return - V_219 ;
if ( ! V_11 -> V_801 || F_430 ( V_11 -> V_20 ) )
goto V_154;
else
V_14 = F_427 ( V_11 , V_834 ) ;
V_154:
F_434 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_189 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
return V_14 ;
}
int F_435 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_4 V_189 = F_72 () ;
if ( ! V_11 )
return - V_219 ;
if ( ! V_11 -> V_801 )
goto V_154;
else
V_14 = F_422 ( V_11 , V_835 ) ;
V_154:
F_436 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_189 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
return V_14 ;
}
int F_431 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_4 V_189 = F_72 () ;
if ( ! V_11 )
return - V_219 ;
if ( ! V_11 -> V_801 )
goto V_154;
else
V_14 = F_427 ( V_11 , V_835 ) ;
V_154:
F_437 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_189 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
return V_14 ;
}
int F_438 ( struct V_10 * V_11 )
{
return 0 ;
}
static inline T_5 F_439 ( struct V_216 * V_20 ,
struct V_235 * V_236 ,
const char * V_237 , T_6 V_240 ,
bool V_836 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
unsigned long V_194 , V_241 ;
if ( F_143 ( V_237 , 0 , & V_241 ) )
return - V_219 ;
if ( V_241 >= V_9 )
return - V_219 ;
F_83 ( V_11 -> V_112 -> V_198 , V_194 ) ;
if ( V_836 )
V_11 -> V_823 = V_241 ;
else
V_11 -> V_824 = V_241 ;
F_84 ( V_11 -> V_112 -> V_198 , V_194 ) ;
return V_240 ;
}
static T_5 F_440 ( struct V_216 * V_20 ,
struct V_235 * V_236 , char * V_237 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
int V_837 ;
T_2 V_3 ;
V_837 = snprintf ( V_237 , V_238 ,
L_202 ,
V_11 -> V_823 ,
F_68 (
V_4 [ V_11 -> V_823 ] . V_5 ) ,
F_67 (
V_4 [ V_11 -> V_823 ] . V_7 ) ) ;
V_837 += snprintf ( ( V_237 + V_837 ) , ( V_238 - V_837 ) ,
L_203 ) ;
for ( V_3 = V_8 ; V_3 < V_9 ; V_3 ++ )
V_837 += snprintf ( ( V_237 + V_837 ) , ( V_238 - V_837 ) ,
L_204 ,
V_3 ,
F_68 (
V_4 [ V_3 ] . V_5 ) ,
F_67 (
V_4 [ V_3 ] . V_7 ) ) ;
return V_837 ;
}
static T_5 F_441 ( struct V_216 * V_20 ,
struct V_235 * V_236 , const char * V_237 , T_6 V_240 )
{
return F_439 ( V_20 , V_236 , V_237 , V_240 , true ) ;
}
static void F_442 ( struct V_10 * V_11 )
{
V_11 -> V_838 . V_243 = F_440 ;
V_11 -> V_838 . V_244 = F_441 ;
F_120 ( & V_11 -> V_838 . V_236 ) ;
V_11 -> V_838 . V_236 . V_53 = L_205 ;
V_11 -> V_838 . V_236 . V_245 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_838 ) )
F_7 ( V_11 -> V_20 , L_206 ) ;
}
static T_5 F_443 ( struct V_216 * V_20 ,
struct V_235 * V_236 , char * V_237 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
int V_837 ;
T_2 V_3 ;
V_837 = snprintf ( V_237 , V_238 ,
L_207 ,
V_11 -> V_824 ,
F_68 (
V_4 [ V_11 -> V_824 ] . V_5 ) ,
F_67 (
V_4 [ V_11 -> V_824 ] . V_7 ) ) ;
V_837 += snprintf ( ( V_237 + V_837 ) , ( V_238 - V_837 ) ,
L_208 ) ;
for ( V_3 = V_8 ; V_3 < V_9 ; V_3 ++ )
V_837 += snprintf ( ( V_237 + V_837 ) , ( V_238 - V_837 ) ,
L_209 ,
V_3 ,
F_68 (
V_4 [ V_3 ] . V_5 ) ,
F_67 (
V_4 [ V_3 ] . V_7 ) ) ;
return V_837 ;
}
static T_5 F_444 ( struct V_216 * V_20 ,
struct V_235 * V_236 , const char * V_237 , T_6 V_240 )
{
return F_439 ( V_20 , V_236 , V_237 , V_240 , false ) ;
}
static void F_445 ( struct V_10 * V_11 )
{
V_11 -> V_839 . V_243 = F_443 ;
V_11 -> V_839 . V_244 = F_444 ;
F_120 ( & V_11 -> V_839 . V_236 ) ;
V_11 -> V_839 . V_236 . V_53 = L_210 ;
V_11 -> V_839 . V_236 . V_245 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_839 ) )
F_7 ( V_11 -> V_20 , L_211 ) ;
}
static inline void F_446 ( struct V_10 * V_11 )
{
F_442 ( V_11 ) ;
F_445 ( V_11 ) ;
}
static inline void F_447 ( struct V_10 * V_11 )
{
F_150 ( V_11 -> V_20 , & V_11 -> V_838 ) ;
F_150 ( V_11 -> V_20 , & V_11 -> V_839 ) ;
}
int F_448 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
if ( F_417 ( V_11 ) && F_418 ( V_11 ) )
goto V_154;
if ( F_430 ( V_11 -> V_20 ) ) {
V_14 = F_431 ( V_11 ) ;
if ( V_14 )
goto V_154;
}
V_14 = F_422 ( V_11 , V_840 ) ;
V_154:
if ( V_14 )
F_7 ( V_11 -> V_20 , L_212 , V_21 , V_14 ) ;
return 0 ;
}
void F_449 ( struct V_10 * V_11 )
{
F_447 ( V_11 ) ;
F_450 ( V_11 -> V_112 ) ;
F_184 ( V_11 , V_11 -> V_138 ) ;
F_270 ( V_11 , true ) ;
F_149 ( V_11 ) ;
if ( F_105 ( V_11 ) )
F_150 ( V_11 -> V_20 , & V_11 -> V_204 . V_242 ) ;
F_370 ( V_11 ) ;
}
void F_451 ( struct V_10 * V_11 )
{
F_452 ( V_11 -> V_112 ) ;
}
static int F_453 ( struct V_10 * V_11 )
{
if ( V_11 -> V_67 & V_841 ) {
if ( ! F_454 ( V_11 -> V_20 , F_455 ( 64 ) ) )
return 0 ;
}
return F_454 ( V_11 -> V_20 , F_455 ( 32 ) ) ;
}
int F_456 ( struct V_216 * V_20 , struct V_10 * * V_842 )
{
struct V_366 * V_112 ;
struct V_10 * V_11 ;
int V_134 = 0 ;
if ( ! V_20 ) {
F_7 ( V_20 ,
L_213 ) ;
V_134 = - V_809 ;
goto V_843;
}
V_112 = F_457 ( & V_844 ,
sizeof( struct V_10 ) ) ;
if ( ! V_112 ) {
F_7 ( V_20 , L_214 ) ;
V_134 = - V_450 ;
goto V_843;
}
V_11 = F_197 ( V_112 ) ;
V_11 -> V_112 = V_112 ;
V_11 -> V_20 = V_20 ;
* V_842 = V_11 ;
F_458 ( & V_11 -> V_49 ) ;
V_843:
return V_134 ;
}
int F_459 ( struct V_10 * V_11 , void T_11 * V_64 , unsigned int V_16 )
{
int V_134 ;
struct V_366 * V_112 = V_11 -> V_112 ;
struct V_216 * V_20 = V_11 -> V_20 ;
if ( ! V_64 ) {
F_7 ( V_11 -> V_20 ,
L_215 ) ;
V_134 = - V_809 ;
goto V_843;
}
V_11 -> V_64 = V_64 ;
V_11 -> V_16 = V_16 ;
F_365 ( V_11 ) ;
V_134 = F_404 ( V_11 ) ;
if ( V_134 )
goto V_843;
F_162 ( V_11 ) ;
V_11 -> V_66 = F_37 ( V_11 ) ;
if ( ( V_11 -> V_66 != V_139 ) &&
( V_11 -> V_66 != V_141 ) &&
( V_11 -> V_66 != V_142 ) &&
( V_11 -> V_66 != V_144 ) )
F_7 ( V_11 -> V_20 , L_216 ,
V_11 -> V_66 ) ;
V_11 -> V_138 = F_36 ( V_11 ) ;
V_134 = F_453 ( V_11 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_217 ) ;
goto V_845;
}
V_134 = F_239 ( V_11 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_218 ) ;
goto V_845;
}
F_242 ( V_11 ) ;
V_112 -> V_846 = V_11 -> V_13 ;
V_112 -> V_847 = V_11 -> V_13 ;
V_112 -> V_848 = V_849 ;
V_112 -> V_850 = V_851 ;
V_112 -> V_852 = V_853 ;
V_112 -> V_854 = V_112 -> V_855 ;
V_112 -> V_856 = V_348 ;
V_11 -> V_520 . V_521 = false ;
F_460 ( & V_11 -> V_659 ) ;
F_460 ( & V_11 -> V_675 ) ;
F_148 ( & V_11 -> V_634 , F_317 ) ;
F_148 ( & V_11 -> V_596 , F_313 ) ;
F_461 ( & V_11 -> V_306 ) ;
F_461 ( & V_11 -> V_274 . V_403 ) ;
F_462 ( & V_11 -> V_207 ) ;
F_460 ( & V_11 -> V_274 . V_391 ) ;
F_146 ( V_11 ) ;
F_49 ( V_11 , F_14 ( V_11 , V_43 ) ,
V_43 ) ;
F_49 ( V_11 , 0 , V_320 ) ;
F_463 () ;
V_134 = F_464 ( V_20 , V_16 , V_17 , V_18 , V_19 , V_11 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_219 ) ;
goto V_857;
} else {
V_11 -> V_15 = true ;
}
V_134 = F_465 ( V_112 , V_11 -> V_20 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_220 ) ;
goto V_857;
}
V_134 = F_271 ( V_11 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_221 ) ;
F_23 ( V_11 ) ;
F_29 ( V_11 ) ;
goto V_858;
}
if ( F_105 ( V_11 ) ) {
char V_859 [ sizeof( L_222 ) ] ;
F_148 ( & V_11 -> V_204 . V_210 ,
F_98 ) ;
F_148 ( & V_11 -> V_204 . V_214 ,
F_101 ) ;
snprintf ( V_859 , sizeof( V_859 ) , L_223 ,
V_112 -> V_855 ) ;
V_11 -> V_204 . V_221 = F_466 ( V_859 ) ;
F_119 ( V_11 ) ;
}
V_11 -> V_823 = F_3 (
V_184 ,
V_182 ) ;
V_11 -> V_824 = F_3 (
V_184 ,
V_182 ) ;
F_116 ( V_20 ) ;
F_367 ( V_11 ) ;
F_467 ( F_372 , V_11 ) ;
F_446 ( V_11 ) ;
return 0 ;
V_858:
F_450 ( V_11 -> V_112 ) ;
V_857:
F_149 ( V_11 ) ;
V_845:
V_11 -> V_15 = false ;
F_370 ( V_11 ) ;
V_843:
return V_134 ;
}
