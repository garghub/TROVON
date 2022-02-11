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
if ( ! V_48 || F_18 ( V_48 ) )
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
}
return V_138 ;
}
static inline T_3 F_37 ( struct V_10 * V_11 )
{
if ( V_11 -> V_119 & V_146 )
return F_38 ( V_11 ) ;
return F_14 ( V_11 , V_147 ) ;
}
static inline int F_39 ( struct V_10 * V_11 )
{
return ( F_14 ( V_11 , V_148 ) &
V_149 ) ? 1 : 0 ;
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
return ( ( V_62 & 0xFF ) >> 1 ) ^ 0x07 ;
}
static inline int F_53 ( struct V_10 * V_11 )
{
return F_14 ( V_11 , V_159 ) &
V_160 ;
}
static inline T_3 F_54 ( struct V_10 * V_11 )
{
return F_14 ( V_11 , V_161 ) ;
}
static inline int
F_55 ( struct V_92 * V_91 )
{
return F_13 ( V_91 -> V_100 . V_162 ) >> 24 ;
}
static inline int
F_56 ( struct V_92 * V_91 )
{
return F_13 ( V_91 -> V_100 . V_163 ) & V_164 ;
}
static inline unsigned int
F_57 ( struct V_92 * V_91 )
{
return F_13 ( V_91 -> V_100 . V_150 ) &
V_165 ;
}
static inline bool F_58 ( struct V_92 * V_91 )
{
return F_13 ( V_91 -> V_100 . V_150 ) &
V_166 ? true : false ;
}
static inline void
F_59 ( struct V_10 * V_11 )
{
F_49 ( V_11 , V_167 |
V_168 ,
V_169 ) ;
}
static inline void
F_60 ( struct V_10 * V_11 , T_2 V_170 , T_2 V_171 )
{
F_49 ( V_11 , V_167 | V_172 |
F_61 ( V_170 ) |
F_62 ( V_171 ) ,
V_169 ) ;
}
static inline void F_63 ( struct V_10 * V_11 )
{
F_49 ( V_11 , 0 , V_169 ) ;
}
static void F_64 ( struct V_10 * V_11 )
{
F_49 ( V_11 , V_173 ,
V_174 ) ;
F_49 ( V_11 , V_175 ,
V_176 ) ;
}
static inline void F_65 ( struct V_10 * V_11 )
{
F_49 ( V_11 , V_177 , V_178 ) ;
}
static inline int F_66 ( struct V_10 * V_11 )
{
return ( F_14 ( V_11 , V_178 ) & 0x1 ) ? 0 : 1 ;
}
static const char * F_67 (
enum V_6 V_115 )
{
switch ( V_115 ) {
case V_179 : return L_44 ;
case V_180 : return L_45 ;
case V_181 : return L_46 ;
default: return L_47 ;
}
}
static const char * F_68 (
enum V_1 V_115 )
{
switch ( V_115 ) {
case V_182 : return L_45 ;
case V_183 : return L_48 ;
case V_184 : return L_49 ;
default: return L_47 ;
}
}
T_3 F_69 ( struct V_10 * V_11 )
{
if ( ( V_11 -> V_66 == V_139 ) ||
( V_11 -> V_66 == V_141 ) )
return V_185 ;
else
return V_186 ;
}
static bool F_70 ( struct V_10 * V_11 )
{
if ( F_69 ( V_11 ) < V_186 )
return true ;
else
return false ;
}
static int F_71 ( struct V_10 * V_11 , bool V_187 )
{
int V_14 = 0 ;
struct V_45 * V_46 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
T_4 V_188 = F_72 () ;
bool V_189 = false ;
if ( ! V_48 || F_18 ( V_48 ) )
goto V_154;
V_14 = F_73 ( V_11 , V_187 , V_190 ) ;
if ( V_14 )
return V_14 ;
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) ) {
if ( V_187 && V_46 -> V_52 ) {
if ( V_46 -> V_54 == V_46 -> V_52 )
continue;
V_189 = true ;
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
} else if ( ! V_187 && V_46 -> V_51 ) {
if ( V_46 -> V_54 == V_46 -> V_51 )
continue;
V_189 = true ;
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
V_14 = F_73 ( V_11 , V_187 , V_191 ) ;
V_154:
if ( V_189 )
F_78 ( F_16 ( V_11 -> V_20 ) ,
( V_187 ? L_54 : L_55 ) ,
F_22 ( F_79 ( F_72 () , V_188 ) ) , V_14 ) ;
return V_14 ;
}
static bool F_80 ( struct V_10 * V_11 ,
bool V_187 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
if ( ! V_48 || F_18 ( V_48 ) )
return false ;
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) ) {
if ( V_187 && V_46 -> V_52 ) {
if ( V_46 -> V_54 == V_46 -> V_52 )
continue;
return true ;
} else if ( ! V_187 && V_46 -> V_51 ) {
if ( V_46 -> V_54 == V_46 -> V_51 )
continue;
return true ;
}
}
}
return false ;
}
static int F_81 ( struct V_10 * V_11 ,
V_84 V_192 )
{
unsigned long V_193 ;
int V_14 = 0 ;
T_3 V_194 ;
T_3 V_195 ;
bool V_135 = false , V_196 = false ;
T_4 V_188 ;
F_82 ( V_11 , false ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_188 = F_72 () ;
do {
if ( V_11 -> V_104 != V_198 ) {
V_14 = - V_199 ;
goto V_154;
}
V_194 = F_14 ( V_11 , V_200 ) ;
V_195 = F_14 ( V_11 , V_44 ) ;
if ( ! V_194 && ! V_195 ) {
V_135 = false ;
break;
} else if ( V_196 ) {
break;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_85 () ;
if ( F_22 ( F_79 ( F_72 () , V_188 ) ) >
V_192 ) {
V_135 = true ;
V_196 = true ;
}
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
} while ( V_194 || V_195 );
if ( V_135 ) {
F_7 ( V_11 -> V_20 ,
L_56 ,
V_21 , V_194 , V_195 ) ;
V_14 = - V_199 ;
}
V_154:
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_86 ( V_11 ) ;
return V_14 ;
}
static int F_87 ( struct V_10 * V_11 , bool V_187 )
{
#define F_88 UFS_HS_G1
int V_14 = 0 ;
struct V_201 V_202 ;
if ( V_187 ) {
memcpy ( & V_202 , & V_11 -> V_203 . V_204 . V_205 ,
sizeof( struct V_201 ) ) ;
} else {
memcpy ( & V_202 , & V_11 -> V_122 ,
sizeof( struct V_201 ) ) ;
if ( V_11 -> V_122 . V_124 > F_88
|| V_11 -> V_122 . V_123 > F_88 ) {
memcpy ( & V_11 -> V_203 . V_204 . V_205 ,
& V_11 -> V_122 ,
sizeof( struct V_201 ) ) ;
V_202 . V_124 = F_88 ;
V_202 . V_123 = F_88 ;
}
}
V_14 = F_89 ( V_11 , & V_202 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 , L_57 ,
V_21 , V_14 ,
V_11 -> V_122 . V_124 , V_11 -> V_122 . V_123 ,
V_202 . V_124 , V_202 . V_123 ) ;
return V_14 ;
}
static int F_90 ( struct V_10 * V_11 )
{
#define F_91 (1000 * 1000)
int V_14 = 0 ;
F_92 ( V_11 -> V_112 ) ;
F_93 ( & V_11 -> V_206 ) ;
if ( F_81 ( V_11 , F_91 ) ) {
V_14 = - V_199 ;
F_94 ( & V_11 -> V_206 ) ;
F_95 ( V_11 -> V_112 ) ;
}
return V_14 ;
}
static void F_96 ( struct V_10 * V_11 )
{
F_94 ( & V_11 -> V_206 ) ;
F_95 ( V_11 -> V_112 ) ;
}
static int F_97 ( struct V_10 * V_11 , bool V_187 )
{
int V_14 = 0 ;
F_82 ( V_11 , false ) ;
V_14 = F_90 ( V_11 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_187 ) {
V_14 = F_87 ( V_11 , false ) ;
if ( V_14 )
goto V_154;
}
V_14 = F_71 ( V_11 , V_187 ) ;
if ( V_14 ) {
if ( ! V_187 )
F_87 ( V_11 , true ) ;
goto V_154;
}
if ( V_187 ) {
V_14 = F_87 ( V_11 , true ) ;
if ( V_14 ) {
F_71 ( V_11 , false ) ;
goto V_154;
}
}
V_14 = F_73 ( V_11 , V_187 , V_191 ) ;
V_154:
F_96 ( V_11 ) ;
F_86 ( V_11 ) ;
return V_14 ;
}
static void F_98 ( struct V_207 * V_208 )
{
struct V_10 * V_11 = F_99 ( V_208 , struct V_10 ,
V_203 . V_209 ) ;
unsigned long V_210 ;
F_83 ( V_11 -> V_112 -> V_197 , V_210 ) ;
if ( V_11 -> V_203 . V_211 || V_11 -> V_203 . V_212 ) {
F_84 ( V_11 -> V_112 -> V_197 , V_210 ) ;
return;
}
V_11 -> V_203 . V_212 = true ;
F_84 ( V_11 -> V_112 -> V_197 , V_210 ) ;
F_100 ( V_11 ) ;
}
static void F_101 ( struct V_207 * V_208 )
{
struct V_10 * V_11 = F_99 ( V_208 , struct V_10 ,
V_203 . V_213 ) ;
unsigned long V_210 ;
F_83 ( V_11 -> V_112 -> V_197 , V_210 ) ;
if ( ! V_11 -> V_203 . V_212 ) {
F_84 ( V_11 -> V_112 -> V_197 , V_210 ) ;
return;
}
V_11 -> V_203 . V_212 = false ;
F_84 ( V_11 -> V_112 -> V_197 , V_210 ) ;
F_102 ( V_11 -> V_214 ) ;
}
static int F_103 ( struct V_215 * V_20 ,
unsigned long * V_216 , T_3 V_193 )
{
int V_14 = 0 ;
struct V_10 * V_11 = F_104 ( V_20 ) ;
T_4 V_188 ;
bool V_187 , V_217 = false ;
unsigned long V_210 ;
if ( ! F_105 ( V_11 ) )
return - V_218 ;
if ( ( * V_216 > 0 ) && ( * V_216 < V_219 ) ) {
F_7 ( V_11 -> V_20 , L_58 , V_21 , * V_216 ) ;
return - V_218 ;
}
F_83 ( V_11 -> V_112 -> V_197 , V_210 ) ;
if ( F_106 ( V_11 ) ) {
F_84 ( V_11 -> V_112 -> V_197 , V_210 ) ;
return 0 ;
}
if ( ! V_11 -> V_203 . V_211 )
V_217 = true ;
V_187 = ( * V_216 == V_219 ) ? true : false ;
if ( ! F_80 ( V_11 , V_187 ) ) {
F_84 ( V_11 -> V_112 -> V_197 , V_210 ) ;
V_14 = 0 ;
goto V_154;
}
F_84 ( V_11 -> V_112 -> V_197 , V_210 ) ;
V_188 = F_72 () ;
V_14 = F_97 ( V_11 , V_187 ) ;
F_78 ( F_16 ( V_11 -> V_20 ) ,
( V_187 ? L_54 : L_55 ) ,
F_22 ( F_79 ( F_72 () , V_188 ) ) , V_14 ) ;
V_154:
if ( V_217 )
F_107 ( V_11 -> V_203 . V_220 ,
& V_11 -> V_203 . V_209 ) ;
return V_14 ;
}
static int F_108 ( struct V_215 * V_20 ,
struct V_221 * V_222 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
struct V_223 * V_224 = & V_11 -> V_203 ;
unsigned long V_193 ;
if ( ! F_105 ( V_11 ) )
return - V_218 ;
memset ( V_222 , 0 , sizeof( * V_222 ) ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( ! V_224 -> V_225 )
goto V_226;
if ( V_224 -> V_227 )
V_224 -> V_228 += F_22 ( F_79 ( F_72 () ,
V_224 -> V_229 ) ) ;
V_222 -> V_230 = F_109 ( ( long ) V_136 -
( long ) V_224 -> V_225 ) ;
V_222 -> V_231 = V_224 -> V_228 ;
V_226:
V_224 -> V_225 = V_136 ;
V_224 -> V_228 = 0 ;
if ( V_11 -> V_68 ) {
V_224 -> V_229 = F_72 () ;
V_224 -> V_227 = true ;
} else {
V_224 -> V_229 = 0 ;
V_224 -> V_227 = false ;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
return 0 ;
}
static void F_100 ( struct V_10 * V_11 )
{
unsigned long V_193 ;
F_110 ( V_11 -> V_214 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_203 . V_225 = 0 ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
}
static void F_111 ( struct V_10 * V_11 )
{
unsigned long V_193 ;
bool V_232 = false ;
if ( ! F_105 ( V_11 ) )
return;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( ! V_11 -> V_203 . V_212 ) {
V_232 = true ;
V_11 -> V_203 . V_212 = true ;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_232 )
F_100 ( V_11 ) ;
}
static void F_112 ( struct V_10 * V_11 )
{
unsigned long V_193 ;
bool V_233 = false ;
if ( ! F_105 ( V_11 ) )
return;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_11 -> V_203 . V_212 ) {
V_233 = true ;
V_11 -> V_203 . V_212 = false ;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_233 )
F_102 ( V_11 -> V_214 ) ;
}
static T_5 F_113 ( struct V_215 * V_20 ,
struct V_234 * V_235 , char * V_236 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
return snprintf ( V_236 , V_237 , L_59 , V_11 -> V_203 . V_238 ) ;
}
static T_5 F_114 ( struct V_215 * V_20 ,
struct V_234 * V_235 , const char * V_236 , T_6 V_239 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
T_3 V_240 ;
int V_134 ;
if ( F_115 ( V_236 , 0 , & V_240 ) )
return - V_218 ;
V_240 = ! ! V_240 ;
if ( V_240 == V_11 -> V_203 . V_238 )
goto V_154;
F_116 ( V_11 -> V_20 ) ;
F_82 ( V_11 , false ) ;
F_117 ( & V_11 -> V_203 . V_209 ) ;
F_117 ( & V_11 -> V_203 . V_213 ) ;
V_11 -> V_203 . V_238 = V_240 ;
if ( V_240 ) {
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
return V_239 ;
}
static void F_119 ( struct V_10 * V_11 )
{
V_11 -> V_203 . V_241 . V_242 = F_113 ;
V_11 -> V_203 . V_241 . V_243 = F_114 ;
F_120 ( & V_11 -> V_203 . V_241 . V_235 ) ;
V_11 -> V_203 . V_241 . V_235 . V_53 = L_61 ;
V_11 -> V_203 . V_241 . V_235 . V_244 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_203 . V_241 ) )
F_7 ( V_11 -> V_20 , L_62 ) ;
}
static void F_122 ( struct V_207 * V_208 )
{
int V_14 ;
unsigned long V_193 ;
struct V_10 * V_11 = F_99 ( V_208 , struct V_10 ,
V_114 . V_245 ) ;
F_123 ( & V_11 -> V_114 . V_246 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_11 -> V_114 . V_115 == V_247 ) {
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
goto V_248;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_124 ( V_11 , true ) ;
if ( F_125 ( V_11 ) ) {
V_11 -> V_114 . V_212 = true ;
if ( F_126 ( V_11 ) ) {
V_14 = F_127 ( V_11 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 , L_63 ,
V_21 , V_14 ) ;
else
F_128 ( V_11 ) ;
}
V_11 -> V_114 . V_212 = false ;
}
V_248:
F_95 ( V_11 -> V_112 ) ;
}
int F_82 ( struct V_10 * V_11 , bool V_249 )
{
int V_250 = 0 ;
unsigned long V_193 ;
if ( ! F_129 ( V_11 ) )
goto V_154;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_114 . V_211 ++ ;
if ( F_106 ( V_11 ) ) {
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
return 0 ;
}
V_188:
switch ( V_11 -> V_114 . V_115 ) {
case V_247 :
if ( F_125 ( V_11 ) &&
F_126 ( V_11 ) ) {
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_130 ( & V_11 -> V_114 . V_245 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
goto V_188;
}
break;
case V_251 :
if ( F_131 ( & V_11 -> V_114 . V_246 ) ) {
V_11 -> V_114 . V_115 = V_247 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
break;
}
case V_252 :
F_92 ( V_11 -> V_112 ) ;
V_11 -> V_114 . V_115 = V_253 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
F_133 ( & V_11 -> V_114 . V_245 ) ;
case V_253 :
if ( V_249 ) {
V_250 = - V_254 ;
V_11 -> V_114 . V_211 -- ;
break;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_130 ( & V_11 -> V_114 . V_245 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
goto V_188;
default:
F_7 ( V_11 -> V_20 , L_64 ,
V_21 , V_11 -> V_114 . V_115 ) ;
break;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_154:
return V_250 ;
}
static void F_134 ( struct V_207 * V_208 )
{
struct V_10 * V_11 = F_99 ( V_208 , struct V_10 ,
V_114 . V_246 . V_208 ) ;
unsigned long V_193 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_11 -> V_114 . V_212 ||
( V_11 -> V_114 . V_115 == V_253 ) ) {
V_11 -> V_114 . V_115 = V_247 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
goto V_255;
}
if ( V_11 -> V_114 . V_211
|| V_11 -> V_104 != V_198
|| V_11 -> V_105 || V_11 -> V_69
|| V_11 -> V_256 || V_11 -> V_257 )
goto V_255;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( F_125 ( V_11 ) ) {
if ( F_135 ( V_11 ) ) {
V_11 -> V_114 . V_115 = V_247 ;
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
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_11 -> V_114 . V_115 == V_251 ) {
V_11 -> V_114 . V_115 = V_252 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
}
V_255:
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_154:
return;
}
static void F_139 ( struct V_10 * V_11 )
{
if ( ! F_129 ( V_11 ) )
return;
V_11 -> V_114 . V_211 -- ;
if ( V_11 -> V_114 . V_211 || V_11 -> V_114 . V_212
|| V_11 -> V_104 != V_198
|| V_11 -> V_105 || V_11 -> V_69
|| V_11 -> V_256 || V_11 -> V_257
|| F_106 ( V_11 ) )
return;
V_11 -> V_114 . V_115 = V_251 ;
F_132 ( F_16 ( V_11 -> V_20 ) , V_11 -> V_114 . V_115 ) ;
F_140 ( & V_11 -> V_114 . V_246 ,
F_32 ( V_11 -> V_114 . V_258 ) ) ;
}
void F_86 ( struct V_10 * V_11 )
{
unsigned long V_193 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_139 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
}
static T_5 F_141 ( struct V_215 * V_20 ,
struct V_234 * V_235 , char * V_236 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
return snprintf ( V_236 , V_237 , L_65 , V_11 -> V_114 . V_258 ) ;
}
static T_5 F_142 ( struct V_215 * V_20 ,
struct V_234 * V_235 , const char * V_236 , T_6 V_239 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
unsigned long V_193 , V_240 ;
if ( F_143 ( V_236 , 0 , & V_240 ) )
return - V_218 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_114 . V_258 = V_240 ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
return V_239 ;
}
static T_5 F_144 ( struct V_215 * V_20 ,
struct V_234 * V_235 , char * V_236 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
return snprintf ( V_236 , V_237 , L_59 , V_11 -> V_114 . V_259 ) ;
}
static T_5 F_145 ( struct V_215 * V_20 ,
struct V_234 * V_235 , const char * V_236 , T_6 V_239 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
unsigned long V_193 ;
T_3 V_240 ;
if ( F_115 ( V_236 , 0 , & V_240 ) )
return - V_218 ;
V_240 = ! ! V_240 ;
if ( V_240 == V_11 -> V_114 . V_259 )
goto V_154;
if ( V_240 ) {
F_86 ( V_11 ) ;
} else {
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_114 . V_211 ++ ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
}
V_11 -> V_114 . V_259 = V_240 ;
V_154:
return V_239 ;
}
static void F_146 ( struct V_10 * V_11 )
{
if ( ! F_129 ( V_11 ) )
return;
V_11 -> V_114 . V_258 = 150 ;
F_147 ( & V_11 -> V_114 . V_246 , F_134 ) ;
F_148 ( & V_11 -> V_114 . V_245 , F_122 ) ;
V_11 -> V_114 . V_259 = true ;
V_11 -> V_114 . V_260 . V_242 = F_141 ;
V_11 -> V_114 . V_260 . V_243 = F_142 ;
F_120 ( & V_11 -> V_114 . V_260 . V_235 ) ;
V_11 -> V_114 . V_260 . V_235 . V_53 = L_66 ;
V_11 -> V_114 . V_260 . V_235 . V_244 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_114 . V_260 ) )
F_7 ( V_11 -> V_20 , L_67 ) ;
V_11 -> V_114 . V_241 . V_242 = F_144 ;
V_11 -> V_114 . V_241 . V_243 = F_145 ;
F_120 ( & V_11 -> V_114 . V_241 . V_235 ) ;
V_11 -> V_114 . V_241 . V_235 . V_53 = L_68 ;
V_11 -> V_114 . V_241 . V_235 . V_244 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_114 . V_241 ) )
F_7 ( V_11 -> V_20 , L_69 ) ;
}
static void F_149 ( struct V_10 * V_11 )
{
if ( ! F_129 ( V_11 ) )
return;
F_150 ( V_11 -> V_20 , & V_11 -> V_114 . V_260 ) ;
F_150 ( V_11 -> V_20 , & V_11 -> V_114 . V_241 ) ;
F_117 ( & V_11 -> V_114 . V_245 ) ;
F_123 ( & V_11 -> V_114 . V_246 ) ;
}
static void F_151 ( struct V_10 * V_11 )
{
bool V_261 = false ;
if ( ! F_105 ( V_11 ) )
return;
if ( ! V_11 -> V_203 . V_211 ++ )
V_261 = true ;
if ( ! V_11 -> V_203 . V_238 || V_11 -> V_109 )
return;
if ( V_261 )
F_107 ( V_11 -> V_203 . V_220 ,
& V_11 -> V_203 . V_213 ) ;
if ( ! V_11 -> V_203 . V_225 ) {
V_11 -> V_203 . V_225 = V_136 ;
V_11 -> V_203 . V_228 = 0 ;
V_11 -> V_203 . V_227 = false ;
}
if ( ! V_11 -> V_203 . V_227 ) {
V_11 -> V_203 . V_229 = F_72 () ;
V_11 -> V_203 . V_227 = true ;
}
}
static void F_152 ( struct V_10 * V_11 )
{
struct V_223 * V_224 = & V_11 -> V_203 ;
if ( ! F_105 ( V_11 ) )
return;
if ( ! V_11 -> V_68 && V_224 -> V_227 ) {
V_224 -> V_228 += F_22 ( F_79 ( F_72 () ,
V_224 -> V_229 ) ) ;
V_224 -> V_229 = 0 ;
V_224 -> V_227 = false ;
}
}
static inline
void F_153 ( struct V_10 * V_11 , unsigned int V_262 )
{
V_11 -> V_31 [ V_262 ] . V_83 = F_72 () ;
F_151 ( V_11 ) ;
F_154 ( V_262 , & V_11 -> V_68 ) ;
F_49 ( V_11 , 1 << V_262 , V_44 ) ;
F_155 () ;
F_11 ( V_11 , V_262 , L_70 ) ;
}
static inline void F_156 ( struct V_28 * V_29 )
{
int V_263 ;
if ( V_29 -> V_264 &&
F_57 ( V_29 -> V_91 ) ) {
int V_265 ;
V_263 = F_157 ( V_29 -> V_91 -> V_266 . V_267 ) ;
V_265 = F_158 ( int , V_268 , V_263 ) ;
memcpy ( V_29 -> V_264 ,
V_29 -> V_91 -> V_266 . V_269 ,
F_158 ( int , V_265 , V_270 ) ) ;
}
}
static
int F_159 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
struct V_271 * V_272 = & V_11 -> V_273 . V_274 . V_275 ;
memcpy ( & V_272 -> V_276 , & V_29 -> V_91 -> V_277 , V_278 ) ;
if ( V_29 -> V_91 -> V_277 . V_25 == V_279 ) {
T_2 * V_280 = ( T_2 * ) V_29 -> V_91 +
V_281 ;
T_7 V_282 ;
T_7 V_283 ;
V_282 = F_13 ( V_29 -> V_91 -> V_100 . V_150 ) &
V_284 ;
V_283 = F_157 (
V_11 -> V_273 . V_274 . V_36 . V_285 . V_286 ) ;
if ( F_160 ( V_283 >= V_282 ) ) {
memcpy ( V_11 -> V_273 . V_274 . V_287 , V_280 , V_282 ) ;
} else {
F_161 ( V_11 -> V_20 ,
L_71 ,
V_21 ) ;
return - V_218 ;
}
}
return 0 ;
}
static inline void F_162 ( struct V_10 * V_11 )
{
V_11 -> V_67 = F_14 ( V_11 , V_288 ) ;
V_11 -> V_13 = ( V_11 -> V_67 & V_289 ) + 1 ;
V_11 -> V_156 =
( ( V_11 -> V_67 & V_290 ) >> 16 ) + 1 ;
}
static inline bool F_163 ( struct V_10 * V_11 )
{
if ( F_14 ( V_11 , V_148 ) & V_291 )
return true ;
else
return false ;
}
static inline T_2 F_164 ( struct V_10 * V_11 )
{
return ( F_14 ( V_11 , V_148 ) >> 8 ) & 0x7 ;
}
static inline void
F_165 ( struct V_10 * V_11 , struct V_292 * V_293 )
{
F_166 ( V_11 -> V_256 ) ;
V_11 -> V_256 = V_293 ;
F_49 ( V_11 , V_293 -> V_294 , V_295 ) ;
F_49 ( V_11 , V_293 -> V_296 , V_159 ) ;
F_49 ( V_11 , V_293 -> V_297 , V_161 ) ;
F_49 ( V_11 , V_293 -> V_298 & V_299 ,
V_300 ) ;
}
static int
F_167 ( struct V_10 * V_11 , struct V_292 * V_293 )
{
int V_14 ;
unsigned long V_193 ;
if ( F_168 ( & V_293 -> V_301 ,
F_32 ( V_302 ) ) )
V_14 = V_293 -> V_296 & V_160 ;
else
V_14 = - V_137 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_256 = NULL ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
return V_14 ;
}
static int
F_169 ( struct V_10 * V_11 , struct V_292 * V_293 ,
bool V_303 )
{
if ( ! F_163 ( V_11 ) ) {
F_7 ( V_11 -> V_20 ,
L_72 ) ;
return - V_304 ;
}
if ( V_303 )
F_170 ( & V_293 -> V_301 ) ;
F_165 ( V_11 , V_293 ) ;
return 0 ;
}
static int
F_171 ( struct V_10 * V_11 , struct V_292 * V_293 )
{
int V_14 ;
unsigned long V_193 ;
F_82 ( V_11 , false ) ;
F_172 ( & V_11 -> V_305 ) ;
F_173 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_14 = F_169 ( V_11 , V_293 , true ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( ! V_14 )
V_14 = F_167 ( V_11 , V_293 ) ;
F_174 ( & V_11 -> V_305 ) ;
F_86 ( V_11 ) ;
return V_14 ;
}
static int F_175 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
struct V_96 * V_306 ;
struct V_307 * V_308 ;
struct V_309 * V_32 ;
int V_310 ;
int V_58 ;
V_32 = V_29 -> V_32 ;
V_310 = F_176 ( V_32 ) ;
if ( V_310 < 0 )
return V_310 ;
if ( V_310 ) {
if ( V_11 -> V_119 & V_311 )
V_29 -> V_86 -> V_93 =
F_177 ( ( T_7 ) ( V_310 *
sizeof( struct V_96 ) ) ) ;
else
V_29 -> V_86 -> V_93 =
F_177 ( ( T_7 ) ( V_310 ) ) ;
V_306 = (struct V_96 * ) V_29 -> V_95 ;
F_178 (cmd, sg, sg_segments, i) {
V_306 [ V_58 ] . V_312 =
F_179 ( ( ( T_3 ) F_180 ( V_308 ) ) - 1 ) ;
V_306 [ V_58 ] . V_313 =
F_179 ( F_181 ( V_308 -> V_314 ) ) ;
V_306 [ V_58 ] . V_315 =
F_179 ( F_182 ( V_308 -> V_314 ) ) ;
V_306 [ V_58 ] . V_316 = 0 ;
}
} else {
V_29 -> V_86 -> V_93 = 0 ;
}
return 0 ;
}
static void F_183 ( struct V_10 * V_11 , T_3 V_317 )
{
T_3 V_318 = F_14 ( V_11 , V_319 ) ;
if ( V_11 -> V_66 == V_139 ) {
T_3 V_320 ;
V_320 = V_318 & V_321 ;
V_318 = V_320 | ( ( V_318 ^ V_317 ) & V_317 ) ;
} else {
V_318 |= V_317 ;
}
F_49 ( V_11 , V_318 , V_319 ) ;
}
static void F_184 ( struct V_10 * V_11 , T_3 V_317 )
{
T_3 V_318 = F_14 ( V_11 , V_319 ) ;
if ( V_11 -> V_66 == V_139 ) {
T_3 V_320 ;
V_320 = ( V_318 & V_321 ) &
~ ( V_317 & V_321 ) ;
V_318 = V_320 | ( ( V_318 & V_317 ) & ~ V_321 ) ;
} else {
V_318 &= ~ V_317 ;
}
F_49 ( V_11 , V_318 , V_319 ) ;
}
static void F_185 ( struct V_28 * V_29 ,
T_3 * V_322 , enum V_323 V_324 )
{
struct V_87 * V_325 = V_29 -> V_86 ;
T_3 V_326 ;
T_3 V_162 ;
if ( V_324 == V_327 ) {
V_326 = V_328 ;
* V_322 = V_329 ;
} else if ( V_324 == V_330 ) {
V_326 = V_331 ;
* V_322 = V_332 ;
} else {
V_326 = V_333 ;
* V_322 = V_334 ;
}
V_162 = V_326 | ( V_29 -> V_335
<< V_336 ) ;
if ( V_29 -> V_337 )
V_162 |= V_338 ;
V_325 -> V_100 . V_162 = F_179 ( V_162 ) ;
V_325 -> V_100 . V_163 = 0 ;
V_325 -> V_100 . V_150 =
F_179 ( V_339 ) ;
V_325 -> V_100 . V_340 = 0 ;
V_325 -> V_93 = 0 ;
}
static
void F_186 ( struct V_28 * V_29 , T_3 V_322 )
{
struct V_89 * V_40 = V_29 -> V_40 ;
unsigned short V_341 ;
V_40 -> V_100 . V_162 = F_187 (
V_342 , V_322 ,
V_29 -> V_343 , V_29 -> V_262 ) ;
V_40 -> V_100 . V_163 = F_187 (
V_344 , 0 , 0 , 0 ) ;
V_40 -> V_100 . V_150 = 0 ;
V_40 -> V_41 . V_42 =
F_188 ( V_29 -> V_32 -> V_345 . V_286 ) ;
V_341 = F_158 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ;
memset ( V_40 -> V_41 . V_346 , 0 , V_347 ) ;
memcpy ( V_40 -> V_41 . V_346 , V_29 -> V_32 -> V_33 , V_341 ) ;
memset ( V_29 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
}
static void F_189 ( struct V_10 * V_11 ,
struct V_28 * V_29 , T_3 V_322 )
{
struct V_89 * V_40 = V_29 -> V_40 ;
struct V_348 * V_274 = & V_11 -> V_273 . V_274 ;
T_7 V_263 = F_157 ( V_274 -> V_36 . V_285 . V_286 ) ;
T_2 * V_280 = ( T_2 * ) V_29 -> V_40 + V_281 ;
V_40 -> V_100 . V_162 = F_187 (
V_349 , V_322 ,
V_29 -> V_343 , V_29 -> V_262 ) ;
V_40 -> V_100 . V_163 = F_187 (
0 , V_274 -> V_36 . V_350 , 0 , 0 ) ;
if ( V_274 -> V_36 . V_285 . V_25 == V_351 )
V_40 -> V_100 . V_150 =
F_187 ( 0 , 0 , ( V_263 >> 8 ) , ( T_2 ) V_263 ) ;
else
V_40 -> V_100 . V_150 = 0 ;
memcpy ( & V_40 -> V_277 , & V_274 -> V_36 . V_285 ,
V_278 ) ;
if ( V_274 -> V_36 . V_285 . V_25 == V_351 )
memcpy ( V_280 , V_274 -> V_287 , V_263 ) ;
memset ( V_29 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
}
static inline void F_190 ( struct V_28 * V_29 )
{
struct V_89 * V_40 = V_29 -> V_40 ;
memset ( V_40 , 0 , sizeof( struct V_89 ) ) ;
V_40 -> V_100 . V_162 =
F_187 (
V_352 , 0 , 0 , V_29 -> V_262 ) ;
V_40 -> V_100 . V_163 = 0 ;
V_40 -> V_100 . V_150 = 0 ;
memset ( V_29 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
}
static int F_191 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
T_3 V_322 ;
int V_14 = 0 ;
if ( V_11 -> V_66 == V_142 )
V_29 -> V_335 = V_353 ;
else
V_29 -> V_335 = V_354 ;
F_185 ( V_29 , & V_322 , V_355 ) ;
if ( V_11 -> V_273 . type == V_356 )
F_189 ( V_11 , V_29 , V_322 ) ;
else if ( V_11 -> V_273 . type == V_357 )
F_190 ( V_29 ) ;
else
V_14 = - V_218 ;
return V_14 ;
}
static int F_192 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
T_3 V_322 ;
int V_14 = 0 ;
if ( V_11 -> V_66 == V_142 )
V_29 -> V_335 = V_353 ;
else
V_29 -> V_335 = V_358 ;
if ( F_160 ( V_29 -> V_32 ) ) {
F_185 ( V_29 , & V_322 ,
V_29 -> V_32 -> V_359 ) ;
F_186 ( V_29 , V_322 ) ;
} else {
V_14 = - V_218 ;
}
return V_14 ;
}
static inline T_2 F_193 ( unsigned int V_360 )
{
if ( F_194 ( V_360 ) )
return ( V_360 & V_361 )
| V_362 ;
else
return V_360 & V_361 ;
}
static inline T_7 F_195 ( T_2 V_363 )
{
return ( V_363 & ~ V_362 ) | V_364 ;
}
static int F_196 ( struct V_365 * V_112 , struct V_309 * V_32 )
{
struct V_28 * V_29 ;
struct V_10 * V_11 ;
unsigned long V_193 ;
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
if ( ! F_199 ( & V_11 -> V_206 ) )
return V_366 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
switch ( V_11 -> V_104 ) {
case V_198 :
break;
case V_367 :
case V_368 :
V_134 = V_366 ;
goto V_369;
case V_370 :
F_200 ( V_32 , V_371 ) ;
V_32 -> V_372 ( V_32 ) ;
goto V_369;
default:
F_201 ( V_11 -> V_20 , 1 , L_74 ,
V_21 , V_11 -> V_104 ) ;
F_200 ( V_32 , V_373 ) ;
V_32 -> V_372 ( V_32 ) ;
goto V_369;
}
if ( F_106 ( V_11 ) ) {
F_200 ( V_32 , V_371 ) ;
V_32 -> V_372 ( V_32 ) ;
goto V_369;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_117 = 0 ;
if ( F_45 ( V_12 , & V_11 -> V_105 ) ) {
V_134 = V_366 ;
goto V_154;
}
V_134 = F_82 ( V_11 , true ) ;
if ( V_134 ) {
V_134 = V_366 ;
F_47 ( V_12 , & V_11 -> V_105 ) ;
goto V_154;
}
F_166 ( V_11 -> V_114 . V_115 != V_247 ) ;
V_29 = & V_11 -> V_31 [ V_12 ] ;
F_166 ( V_29 -> V_32 ) ;
V_29 -> V_32 = V_32 ;
V_29 -> V_374 = V_270 ;
V_29 -> V_264 = V_32 -> V_264 ;
V_29 -> V_262 = V_12 ;
V_29 -> V_343 = F_193 ( V_32 -> V_215 -> V_343 ) ;
V_29 -> V_337 = ! F_202 ( V_11 ) ? true : false ;
V_29 -> V_375 = false ;
F_192 ( V_11 , V_29 ) ;
V_134 = F_175 ( V_11 , V_29 ) ;
if ( V_134 ) {
V_29 -> V_32 = NULL ;
F_47 ( V_12 , & V_11 -> V_105 ) ;
goto V_154;
}
F_155 () ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_203 ( V_11 , V_12 , ( V_29 -> V_32 ? true : false ) ) ;
F_153 ( V_11 , V_12 ) ;
V_369:
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_154:
F_204 ( & V_11 -> V_206 ) ;
return V_134 ;
}
static int F_205 ( struct V_10 * V_11 ,
struct V_28 * V_29 , enum V_376 V_377 , int V_12 )
{
V_29 -> V_32 = NULL ;
V_29 -> V_374 = 0 ;
V_29 -> V_264 = NULL ;
V_29 -> V_262 = V_12 ;
V_29 -> V_343 = 0 ;
V_29 -> V_337 = true ;
V_11 -> V_273 . type = V_377 ;
return F_191 ( V_11 , V_29 ) ;
}
static int
F_206 ( struct V_10 * V_11 , int V_12 )
{
int V_134 = 0 ;
unsigned long V_193 ;
T_3 V_130 = 1 << V_12 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_48 ( V_11 , V_12 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_134 = F_31 ( V_11 ,
V_44 ,
V_130 , ~ V_130 , 1000 , 1000 , true ) ;
return V_134 ;
}
static int
F_207 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
struct V_271 * V_272 = & V_11 -> V_273 . V_274 . V_275 ;
V_272 -> V_275 = F_56 ( V_29 -> V_91 ) >>
V_378 ;
return V_272 -> V_275 ;
}
static int
F_208 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
int V_379 ;
int V_134 = 0 ;
V_11 -> V_70 . V_71 = F_209 ( 0 , 0 ) ;
V_379 = F_55 ( V_29 -> V_91 ) ;
switch ( V_379 ) {
case V_380 :
if ( V_11 -> V_273 . type != V_357 ) {
V_134 = - V_218 ;
F_7 ( V_11 -> V_20 , L_75 ,
V_21 , V_379 ) ;
}
break;
case V_381 :
V_134 = F_207 ( V_11 , V_29 ) ;
if ( ! V_134 )
V_134 = F_159 ( V_11 , V_29 ) ;
break;
case V_382 :
V_134 = - V_383 ;
F_7 ( V_11 -> V_20 , L_76 ,
V_21 ) ;
break;
default:
V_134 = - V_218 ;
F_7 ( V_11 -> V_20 , L_77 ,
V_21 , V_379 ) ;
break;
}
return V_134 ;
}
static int F_210 ( struct V_10 * V_11 ,
struct V_28 * V_29 , int V_384 )
{
int V_134 = 0 ;
unsigned long V_385 ;
unsigned long V_193 ;
V_385 = F_168 ( V_11 -> V_273 . V_386 ,
F_32 ( V_384 ) ) ;
F_155 () ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_273 . V_386 = NULL ;
if ( F_160 ( V_385 ) ) {
V_134 = F_40 ( V_29 ) ;
if ( ! V_134 )
V_134 = F_208 ( V_11 , V_29 ) ;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( ! V_385 ) {
V_134 = - V_137 ;
F_76 ( V_11 -> V_20 , L_78 ,
V_21 , V_29 -> V_262 ) ;
if ( ! F_206 ( V_11 , V_29 -> V_262 ) )
V_134 = - V_254 ;
F_50 ( V_11 , V_29 -> V_262 ) ;
}
return V_134 ;
}
static bool F_211 ( struct V_10 * V_11 , int * V_387 )
{
int V_12 ;
bool V_14 = false ;
unsigned long V_388 ;
if ( ! V_387 )
goto V_154;
do {
V_388 = ~ V_11 -> V_105 ;
V_12 = F_212 ( & V_388 , V_11 -> V_13 ) ;
if ( V_12 >= V_11 -> V_13 )
goto V_154;
} while ( F_45 ( V_12 , & V_11 -> V_105 ) );
* V_387 = V_12 ;
V_14 = true ;
V_154:
return V_14 ;
}
static inline void F_213 ( struct V_10 * V_11 , int V_12 )
{
F_47 ( V_12 , & V_11 -> V_105 ) ;
}
static int F_214 ( struct V_10 * V_11 ,
enum V_376 V_377 , int V_135 )
{
struct V_28 * V_29 ;
int V_134 ;
int V_12 ;
struct V_303 V_389 ;
unsigned long V_193 ;
F_215 ( & V_11 -> V_206 ) ;
F_216 ( V_11 -> V_273 . V_390 , F_211 ( V_11 , & V_12 ) ) ;
F_170 ( & V_389 ) ;
V_29 = & V_11 -> V_31 [ V_12 ] ;
F_166 ( V_29 -> V_32 ) ;
V_134 = F_205 ( V_11 , V_29 , V_377 , V_12 ) ;
if ( F_217 ( V_134 ) )
goto V_391;
V_11 -> V_273 . V_386 = & V_389 ;
F_155 () ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_203 ( V_11 , V_12 , ( V_29 -> V_32 ? true : false ) ) ;
F_153 ( V_11 , V_12 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_134 = F_210 ( V_11 , V_29 , V_135 ) ;
V_391:
F_213 ( V_11 , V_12 ) ;
F_218 ( & V_11 -> V_273 . V_390 ) ;
F_204 ( & V_11 -> V_206 ) ;
return V_134 ;
}
static inline void F_219 ( struct V_10 * V_11 ,
struct V_392 * * V_36 , struct V_271 * * V_275 ,
enum V_393 V_25 , T_2 V_394 , T_2 V_395 , T_2 V_396 )
{
* V_36 = & V_11 -> V_273 . V_274 . V_36 ;
* V_275 = & V_11 -> V_273 . V_274 . V_275 ;
memset ( * V_36 , 0 , sizeof( struct V_392 ) ) ;
memset ( * V_275 , 0 , sizeof( struct V_271 ) ) ;
( * V_36 ) -> V_285 . V_25 = V_25 ;
( * V_36 ) -> V_285 . V_394 = V_394 ;
( * V_36 ) -> V_285 . V_395 = V_395 ;
( * V_36 ) -> V_285 . V_396 = V_396 ;
}
static int F_220 ( struct V_10 * V_11 ,
enum V_393 V_25 , enum V_397 V_394 , bool * V_398 )
{
int V_14 ;
int V_399 ;
for ( V_399 = 0 ; V_399 < V_400 ; V_399 ++ ) {
V_14 = F_221 ( V_11 , V_25 , V_394 , V_398 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 ,
L_79 ,
V_21 , V_14 , V_399 ) ;
else
break;
}
if ( V_14 )
F_7 ( V_11 -> V_20 ,
L_80 ,
V_21 , V_25 , V_394 , V_14 , V_399 ) ;
return V_14 ;
}
int F_221 ( struct V_10 * V_11 , enum V_393 V_25 ,
enum V_397 V_394 , bool * V_398 )
{
struct V_392 * V_36 = NULL ;
struct V_271 * V_275 = NULL ;
int V_134 , V_395 = 0 , V_396 = 0 ;
int V_135 = V_401 ;
F_222 ( ! V_11 ) ;
F_82 ( V_11 , false ) ;
F_172 ( & V_11 -> V_273 . V_402 ) ;
F_219 ( V_11 , & V_36 , & V_275 , V_25 , V_394 , V_395 ,
V_396 ) ;
switch ( V_25 ) {
case V_403 :
case V_404 :
case V_405 :
V_36 -> V_350 = V_406 ;
break;
case V_407 :
V_36 -> V_350 = V_408 ;
if ( ! V_398 ) {
F_7 ( V_11 -> V_20 , L_81 ,
V_21 ) ;
V_134 = - V_218 ;
goto V_369;
}
break;
default:
F_7 ( V_11 -> V_20 ,
L_82 ,
V_21 , V_25 ) ;
V_134 = - V_218 ;
goto V_369;
}
V_134 = F_214 ( V_11 , V_356 , V_135 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 ,
L_83 ,
V_21 , V_394 , V_134 ) ;
goto V_369;
}
if ( V_398 )
* V_398 = ( F_13 ( V_275 -> V_276 . V_240 ) &
V_409 ) & 0x1 ;
V_369:
F_174 ( & V_11 -> V_273 . V_402 ) ;
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_223 ( struct V_10 * V_11 , enum V_393 V_25 ,
enum V_410 V_394 , T_2 V_395 , T_2 V_396 , T_3 * V_411 )
{
struct V_392 * V_36 = NULL ;
struct V_271 * V_275 = NULL ;
int V_134 ;
F_222 ( ! V_11 ) ;
F_82 ( V_11 , false ) ;
if ( ! V_411 ) {
F_7 ( V_11 -> V_20 , L_84 ,
V_21 , V_25 ) ;
V_134 = - V_218 ;
goto V_154;
}
F_172 ( & V_11 -> V_273 . V_402 ) ;
F_219 ( V_11 , & V_36 , & V_275 , V_25 , V_394 , V_395 ,
V_396 ) ;
switch ( V_25 ) {
case V_412 :
V_36 -> V_350 = V_406 ;
V_36 -> V_285 . V_240 = F_188 ( * V_411 ) ;
break;
case V_413 :
V_36 -> V_350 = V_408 ;
break;
default:
F_7 ( V_11 -> V_20 , L_85 ,
V_21 , V_25 ) ;
V_134 = - V_218 ;
goto V_369;
}
V_134 = F_214 ( V_11 , V_356 , V_401 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_86 ,
V_21 , V_25 , V_394 , V_395 , V_134 ) ;
goto V_369;
}
* V_411 = F_13 ( V_275 -> V_276 . V_240 ) ;
V_369:
F_174 ( & V_11 -> V_273 . V_402 ) ;
V_154:
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_224 ( struct V_10 * V_11 ,
enum V_393 V_25 , enum V_410 V_394 , T_2 V_395 , T_2 V_396 ,
T_3 * V_411 )
{
int V_14 = 0 ;
T_3 V_399 ;
for ( V_399 = V_400 ; V_399 > 0 ; V_399 -- ) {
V_14 = F_223 ( V_11 , V_25 , V_394 , V_395 ,
V_396 , V_411 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 , L_79 ,
V_21 , V_14 , V_399 ) ;
else
break;
}
if ( V_14 )
F_7 ( V_11 -> V_20 ,
L_87 ,
V_21 , V_394 , V_14 , V_400 ) ;
return V_14 ;
}
static int F_225 ( struct V_10 * V_11 ,
enum V_393 V_25 , enum V_414 V_394 , T_2 V_395 ,
T_2 V_396 , T_2 * V_415 , int * V_283 )
{
struct V_392 * V_36 = NULL ;
struct V_271 * V_275 = NULL ;
int V_134 ;
F_222 ( ! V_11 ) ;
F_82 ( V_11 , false ) ;
if ( ! V_415 ) {
F_7 ( V_11 -> V_20 , L_88 ,
V_21 , V_25 ) ;
V_134 = - V_218 ;
goto V_154;
}
if ( * V_283 < V_416 || * V_283 > V_417 ) {
F_7 ( V_11 -> V_20 , L_89 ,
V_21 , * V_283 ) ;
V_134 = - V_218 ;
goto V_154;
}
F_172 ( & V_11 -> V_273 . V_402 ) ;
F_219 ( V_11 , & V_36 , & V_275 , V_25 , V_394 , V_395 ,
V_396 ) ;
V_11 -> V_273 . V_274 . V_287 = V_415 ;
V_36 -> V_285 . V_286 = F_226 ( * V_283 ) ;
switch ( V_25 ) {
case V_351 :
V_36 -> V_350 = V_406 ;
break;
case V_279 :
V_36 -> V_350 = V_408 ;
break;
default:
F_7 ( V_11 -> V_20 ,
L_90 ,
V_21 , V_25 ) ;
V_134 = - V_218 ;
goto V_369;
}
V_134 = F_214 ( V_11 , V_356 , V_401 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_86 ,
V_21 , V_25 , V_394 , V_395 , V_134 ) ;
goto V_369;
}
V_11 -> V_273 . V_274 . V_287 = NULL ;
* V_283 = F_157 ( V_275 -> V_276 . V_286 ) ;
V_369:
F_174 ( & V_11 -> V_273 . V_402 ) ;
V_154:
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_227 ( struct V_10 * V_11 ,
enum V_393 V_25 ,
enum V_414 V_394 , T_2 V_395 ,
T_2 V_396 ,
T_2 * V_415 , int * V_283 )
{
int V_134 ;
int V_399 ;
for ( V_399 = V_400 ; V_399 > 0 ; V_399 -- ) {
V_134 = F_225 ( V_11 , V_25 , V_394 , V_395 ,
V_396 , V_415 , V_283 ) ;
if ( ! V_134 || V_134 == - V_218 )
break;
}
return V_134 ;
}
static int F_228 ( struct V_10 * V_11 ,
enum V_414 V_418 ,
int V_419 ,
int * V_420 )
{
int V_14 ;
T_2 V_100 [ V_421 ] ;
int V_422 = V_421 ;
if ( V_418 >= V_423 )
return - V_218 ;
V_14 = F_227 ( V_11 , V_279 ,
V_418 , V_419 , 0 , V_100 ,
& V_422 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_91 ,
V_21 , V_418 ) ;
return V_14 ;
} else if ( V_418 != V_100 [ V_424 ] ) {
F_161 ( V_11 -> V_20 , L_92 ,
V_21 , V_100 [ V_424 ] ,
V_418 ) ;
V_14 = - V_218 ;
}
* V_420 = V_100 [ V_425 ] ;
return V_14 ;
}
int F_229 ( struct V_10 * V_11 ,
enum V_414 V_418 , int * V_426 )
{
switch ( V_418 ) {
case V_427 :
* V_426 = V_11 -> V_428 . V_429 ;
break;
case V_430 :
* V_426 = V_11 -> V_428 . V_431 ;
break;
case V_432 :
* V_426 = V_11 -> V_428 . V_433 ;
break;
case V_434 :
* V_426 = V_11 -> V_428 . V_435 ;
break;
case V_436 :
* V_426 = V_11 -> V_428 . V_437 ;
break;
case V_438 :
* V_426 = V_11 -> V_428 . V_439 ;
break;
case V_440 :
* V_426 = V_417 ;
break;
case V_441 :
case V_442 :
* V_426 = 0 ;
break;
default:
* V_426 = 0 ;
return - V_218 ;
}
return 0 ;
}
static int F_230 ( struct V_10 * V_11 ,
enum V_414 V_418 ,
int V_419 ,
T_2 V_443 ,
T_2 * V_444 ,
T_2 V_445 )
{
int V_14 ;
T_2 * V_415 ;
int V_446 ;
bool V_447 = true ;
if ( V_418 >= V_423 || ! V_445 )
return - V_218 ;
V_14 = F_229 ( V_11 , V_418 , & V_446 ) ;
if ( V_14 || ! V_446 ) {
F_7 ( V_11 -> V_20 , L_93 ,
V_21 ) ;
return V_14 ;
}
if ( V_443 != 0 || V_445 < V_446 ) {
V_415 = F_231 ( V_446 , V_448 ) ;
if ( ! V_415 )
return - V_449 ;
} else {
V_415 = V_444 ;
V_447 = false ;
}
V_14 = F_227 ( V_11 , V_279 ,
V_418 , V_419 , 0 ,
V_415 , & V_446 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_94 ,
V_21 , V_418 , V_419 , V_443 , V_14 ) ;
goto V_154;
}
if ( V_415 [ V_424 ] != V_418 ) {
F_7 ( V_11 -> V_20 , L_95 ,
V_21 , V_415 [ V_424 ] ) ;
V_14 = - V_218 ;
goto V_154;
}
if ( V_447 && V_445 > V_446 )
V_445 = V_446 ;
if ( V_447 )
memcpy ( V_444 , & V_415 [ V_443 ] , V_445 ) ;
V_154:
if ( V_447 )
F_232 ( V_415 ) ;
return V_14 ;
}
static inline int F_233 ( struct V_10 * V_11 ,
enum V_414 V_418 ,
int V_419 ,
T_2 * V_236 ,
T_3 V_312 )
{
return F_230 ( V_11 , V_418 , V_419 , 0 , V_236 , V_312 ) ;
}
static inline int F_234 ( struct V_10 * V_11 ,
T_2 * V_236 ,
T_3 V_312 )
{
int V_134 = 0 ;
int V_399 ;
for ( V_399 = V_400 ; V_399 > 0 ; V_399 -- ) {
V_134 = F_233 ( V_11 , V_430 , 0 , V_236 , V_312 ) ;
if ( ! V_134 )
break;
F_76 ( V_11 -> V_20 , L_96 , V_21 , V_134 ) ;
}
return V_134 ;
}
static int F_235 ( struct V_10 * V_11 , T_2 * V_236 , T_3 V_312 )
{
return F_233 ( V_11 , V_427 , 0 , V_236 , V_312 ) ;
}
static int F_236 ( struct V_10 * V_11 , int V_419 ,
T_2 * V_236 , T_3 V_312 , bool V_450 )
{
int V_134 = 0 ;
V_134 = F_233 ( V_11 ,
V_440 , V_419 , V_236 , V_312 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_97 ,
V_21 , V_400 , V_134 ) ;
goto V_154;
}
if ( V_450 ) {
int V_426 ;
int V_451 ;
int V_58 ;
char * V_452 ;
V_426 = V_236 [ 0 ] ;
V_451 = ( V_426 - V_421 ) / 2 + 1 ;
if ( V_312 < V_451 + V_421 ) {
F_7 ( V_11 -> V_20 , L_98 ,
V_21 ) ;
V_134 = - V_449 ;
goto V_154;
}
V_452 = F_231 ( V_451 , V_448 ) ;
if ( ! V_452 ) {
V_134 = - V_449 ;
goto V_154;
}
F_237 ( ( V_453 * ) & V_236 [ V_421 ] ,
V_426 - V_421 ,
V_454 , V_452 , V_451 ) ;
for ( V_58 = 0 ; V_58 < V_451 ; V_58 ++ )
F_10 ( & V_452 [ V_58 ] ) ;
memset ( V_236 + V_421 , 0 ,
V_312 - V_421 ) ;
memcpy ( V_236 + V_421 , V_452 , V_451 ) ;
V_236 [ V_425 ] = V_451 + V_421 ;
F_232 ( V_452 ) ;
}
V_154:
return V_134 ;
}
static inline int F_238 ( struct V_10 * V_11 ,
int V_343 ,
enum V_455 V_443 ,
T_2 * V_444 ,
T_3 V_445 )
{
if ( V_343 != V_456 && ( V_343 >= V_457 ) )
return - V_458 ;
return F_230 ( V_11 , V_436 , V_343 ,
V_443 , V_444 , V_445 ) ;
}
static int F_239 ( struct V_10 * V_11 )
{
T_6 V_459 , V_460 , V_461 ;
V_461 = ( sizeof( struct V_462 ) * V_11 -> V_13 ) ;
V_11 -> V_463 = F_240 ( V_11 -> V_20 ,
V_461 ,
& V_11 -> V_464 ,
V_448 ) ;
if ( ! V_11 -> V_463 ||
F_166 ( V_11 -> V_464 & ( V_237 - 1 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_99 ) ;
goto V_154;
}
V_460 = ( sizeof( struct V_87 ) * V_11 -> V_13 ) ;
V_11 -> V_465 = F_240 ( V_11 -> V_20 ,
V_460 ,
& V_11 -> V_466 ,
V_448 ) ;
if ( ! V_11 -> V_465 ||
F_166 ( V_11 -> V_466 & ( V_237 - 1 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_100 ) ;
goto V_154;
}
V_459 = sizeof( struct V_97 ) * V_11 -> V_156 ;
V_11 -> V_99 = F_240 ( V_11 -> V_20 ,
V_459 ,
& V_11 -> V_467 ,
V_448 ) ;
if ( ! V_11 -> V_99 ||
F_166 ( V_11 -> V_467 & ( V_237 - 1 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_101 ) ;
goto V_154;
}
V_11 -> V_31 = F_241 ( V_11 -> V_20 ,
V_11 -> V_13 * sizeof( struct V_28 ) ,
V_448 ) ;
if ( ! V_11 -> V_31 ) {
F_7 ( V_11 -> V_20 , L_102 ) ;
goto V_154;
}
return 0 ;
V_154:
return - V_449 ;
}
static void F_242 ( struct V_10 * V_11 )
{
struct V_462 * V_468 ;
struct V_87 * V_469 ;
T_8 V_470 ;
T_8 V_471 ;
T_7 V_472 ;
T_7 V_473 ;
int V_474 ;
int V_58 ;
V_469 = V_11 -> V_465 ;
V_468 = V_11 -> V_463 ;
V_472 =
F_243 ( struct V_462 , V_475 ) ;
V_473 =
F_243 ( struct V_462 , V_306 ) ;
V_474 = sizeof( struct V_462 ) ;
V_470 = V_11 -> V_464 ;
for ( V_58 = 0 ; V_58 < V_11 -> V_13 ; V_58 ++ ) {
V_471 =
( V_470 + ( V_474 * V_58 ) ) ;
V_469 [ V_58 ] . V_476 =
F_179 ( F_181 ( V_471 ) ) ;
V_469 [ V_58 ] . V_477 =
F_179 ( F_182 ( V_471 ) ) ;
if ( V_11 -> V_119 & V_311 ) {
V_469 [ V_58 ] . V_478 =
F_177 ( V_472 ) ;
V_469 [ V_58 ] . V_479 =
F_177 ( V_473 ) ;
V_469 [ V_58 ] . V_480 =
F_177 ( V_481 ) ;
} else {
V_469 [ V_58 ] . V_478 =
F_177 ( ( V_472 >> 2 ) ) ;
V_469 [ V_58 ] . V_479 =
F_177 ( ( V_473 >> 2 ) ) ;
V_469 [ V_58 ] . V_480 =
F_177 ( V_481 >> 2 ) ;
}
V_11 -> V_31 [ V_58 ] . V_86 = ( V_469 + V_58 ) ;
V_11 -> V_31 [ V_58 ] . V_85 = V_11 -> V_466 +
( V_58 * sizeof( struct V_87 ) ) ;
V_11 -> V_31 [ V_58 ] . V_40 =
(struct V_89 * ) ( V_468 + V_58 ) ;
V_11 -> V_31 [ V_58 ] . V_88 = V_471 ;
V_11 -> V_31 [ V_58 ] . V_91 =
(struct V_92 * ) V_468 [ V_58 ] . V_475 ;
V_11 -> V_31 [ V_58 ] . V_90 = V_471 +
V_472 ;
V_11 -> V_31 [ V_58 ] . V_95 =
(struct V_96 * ) V_468 [ V_58 ] . V_306 ;
V_11 -> V_31 [ V_58 ] . V_94 = V_471 +
V_473 ;
}
}
static int F_244 ( struct V_10 * V_11 )
{
struct V_292 V_293 = { 0 } ;
int V_14 ;
V_293 . V_298 = V_482 ;
V_14 = F_171 ( V_11 , & V_293 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 ,
L_103 , V_14 ) ;
return V_14 ;
}
static inline void F_173 ( struct V_10 * V_11 )
{
#define F_245 1000
unsigned long V_483 ;
if ( ! ( V_11 -> V_119 & V_484 ) )
return;
if ( F_217 ( ! F_22 ( V_11 -> V_485 ) ) ) {
V_483 = F_245 ;
} else {
unsigned long V_486 =
( unsigned long ) F_22 (
F_79 ( F_72 () ,
V_11 -> V_485 ) ) ;
if ( V_486 < F_245 )
V_483 =
F_245 - V_486 ;
else
return;
}
F_33 ( V_483 , V_483 + 50 ) ;
}
int F_246 ( struct V_10 * V_11 , T_3 V_487 ,
T_2 V_488 , T_3 V_489 , T_2 V_490 )
{
struct V_292 V_293 = { 0 } ;
static const char * const V_491 [] = {
L_104 ,
L_105
} ;
const char * V_318 = V_491 [ ! ! V_490 ] ;
int V_14 ;
int V_399 = V_492 ;
V_293 . V_298 = V_490 ?
V_493 : V_494 ;
V_293 . V_294 = V_487 ;
V_293 . V_296 = F_247 ( V_488 ) ;
V_293 . V_297 = V_489 ;
do {
V_14 = F_171 ( V_11 , & V_293 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 , L_106 ,
V_318 , F_248 ( V_487 ) , V_489 , V_14 ) ;
} while ( V_14 && V_490 && -- V_399 );
if ( V_14 )
F_7 ( V_11 -> V_20 , L_107 ,
V_318 , F_248 ( V_487 ) , V_489 ,
V_492 - V_399 ) ;
return V_14 ;
}
int F_249 ( struct V_10 * V_11 , T_3 V_487 ,
T_3 * V_489 , T_2 V_490 )
{
struct V_292 V_293 = { 0 } ;
static const char * const V_491 [] = {
L_108 ,
L_109
} ;
const char * V_495 = V_491 [ ! ! V_490 ] ;
int V_14 ;
int V_399 = V_492 ;
struct V_201 V_496 ;
struct V_201 V_497 ;
bool V_498 = false ;
if ( V_490 && ( V_11 -> V_119 & V_499 ) ) {
V_496 = V_11 -> V_122 ;
V_497 = V_496 ;
if ( V_496 . V_128 == V_500 ||
V_496 . V_127 == V_500 ) {
V_497 . V_128 = V_501 ;
V_497 . V_127 = V_501 ;
V_498 = true ;
} else if ( V_496 . V_128 == V_502 ||
V_496 . V_127 == V_502 ) {
V_497 . V_128 = V_503 ;
V_497 . V_127 = V_503 ;
V_498 = true ;
}
if ( V_498 ) {
V_14 = F_89 ( V_11 , & V_497 ) ;
if ( V_14 )
goto V_154;
}
}
V_293 . V_298 = V_490 ?
V_504 : V_505 ;
V_293 . V_294 = V_487 ;
do {
V_14 = F_171 ( V_11 , & V_293 ) ;
if ( V_14 )
F_76 ( V_11 -> V_20 , L_110 ,
V_495 , F_248 ( V_487 ) , V_14 ) ;
} while ( V_14 && V_490 && -- V_399 );
if ( V_14 )
F_7 ( V_11 -> V_20 , L_111 ,
V_495 , F_248 ( V_487 ) ,
V_492 - V_399 ) ;
if ( V_489 && ! V_14 )
* V_489 = V_293 . V_297 ;
if ( V_490 && ( V_11 -> V_119 & V_499 )
&& V_498 )
F_89 ( V_11 , & V_496 ) ;
V_154:
return V_14 ;
}
static int F_250 ( struct V_10 * V_11 , struct V_292 * V_32 )
{
struct V_303 V_257 ;
unsigned long V_193 ;
T_2 V_506 ;
int V_14 ;
bool V_507 = false ;
F_172 ( & V_11 -> V_305 ) ;
F_170 ( & V_257 ) ;
F_173 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_257 = & V_257 ;
if ( F_14 ( V_11 , V_319 ) & V_508 ) {
F_184 ( V_11 , V_508 ) ;
F_155 () ;
V_507 = true ;
}
V_14 = F_169 ( V_11 , V_32 , false ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 ,
L_112 ,
V_32 -> V_298 , V_32 -> V_297 , V_14 ) ;
goto V_154;
}
if ( ! F_168 ( V_11 -> V_257 ,
F_32 ( V_302 ) ) ) {
F_7 ( V_11 -> V_20 ,
L_113 ,
V_32 -> V_298 , V_32 -> V_297 ) ;
V_14 = - V_137 ;
goto V_154;
}
V_506 = F_164 ( V_11 ) ;
if ( V_506 != V_509 ) {
F_7 ( V_11 -> V_20 ,
L_114 ,
V_32 -> V_298 , V_506 ) ;
V_14 = ( V_506 != V_510 ) ? V_506 : - 1 ;
}
V_154:
if ( V_14 ) {
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
F_23 ( V_11 ) ;
}
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_256 = NULL ;
V_11 -> V_257 = NULL ;
if ( V_507 )
F_183 ( V_11 , V_508 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_174 ( & V_11 -> V_305 ) ;
return V_14 ;
}
static int F_251 ( struct V_10 * V_11 , T_2 V_244 )
{
struct V_292 V_293 = { 0 } ;
int V_14 ;
if ( V_11 -> V_119 & V_511 ) {
V_14 = F_252 ( V_11 ,
F_253 ( V_512 , 0 ) , 1 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_115 ,
V_21 , V_14 ) ;
goto V_154;
}
}
V_293 . V_298 = V_494 ;
V_293 . V_294 = F_254 ( V_513 ) ;
V_293 . V_297 = V_244 ;
F_82 ( V_11 , false ) ;
V_14 = F_250 ( V_11 , & V_293 ) ;
F_86 ( V_11 ) ;
V_154:
return V_14 ;
}
static int F_255 ( struct V_10 * V_11 )
{
int V_14 ;
unsigned long V_193 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_104 = V_368 ;
F_256 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_14 = F_257 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_14 )
V_11 -> V_104 = V_370 ;
F_258 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 , L_116 ,
V_21 , V_14 ) ;
return V_14 ;
}
static int F_259 ( struct V_10 * V_11 )
{
int V_14 ;
struct V_292 V_293 = { 0 } ;
T_4 V_188 = F_72 () ;
F_260 ( V_11 , V_514 , V_190 ) ;
V_293 . V_298 = V_514 ;
V_14 = F_250 ( V_11 , & V_293 ) ;
F_261 ( F_16 ( V_11 -> V_20 ) , L_117 ,
F_22 ( F_79 ( F_72 () , V_188 ) ) , V_14 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_118 ,
V_21 , V_14 ) ;
if ( F_255 ( V_11 ) )
V_14 = - V_515 ;
} else
F_260 ( V_11 , V_514 ,
V_191 ) ;
return V_14 ;
}
static int F_135 ( struct V_10 * V_11 )
{
int V_14 = 0 , V_399 ;
for ( V_399 = V_516 ; V_399 > 0 ; V_399 -- ) {
V_14 = F_259 ( V_11 ) ;
if ( ! V_14 || V_14 == - V_515 )
goto V_154;
}
V_154:
return V_14 ;
}
static int F_127 ( struct V_10 * V_11 )
{
struct V_292 V_293 = { 0 } ;
int V_14 ;
T_4 V_188 = F_72 () ;
F_260 ( V_11 , V_517 , V_190 ) ;
V_293 . V_298 = V_517 ;
V_14 = F_250 ( V_11 , & V_293 ) ;
F_261 ( F_16 ( V_11 -> V_20 ) , L_119 ,
F_22 ( F_79 ( F_72 () , V_188 ) ) , V_14 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_120 ,
V_21 , V_14 ) ;
V_14 = F_255 ( V_11 ) ;
} else {
F_260 ( V_11 , V_517 ,
V_191 ) ;
V_11 -> V_70 . V_71 = F_72 () ;
V_11 -> V_70 . V_72 ++ ;
}
return V_14 ;
}
static void F_262 ( struct V_10 * V_11 )
{
V_11 -> V_122 . V_123 = V_518 ;
V_11 -> V_122 . V_124 = V_518 ;
V_11 -> V_122 . V_125 = 1 ;
V_11 -> V_122 . V_126 = 1 ;
V_11 -> V_122 . V_127 = V_503 ;
V_11 -> V_122 . V_128 = V_503 ;
V_11 -> V_122 . V_129 = 0 ;
}
static int F_263 ( struct V_10 * V_11 )
{
struct V_201 * V_122 = & V_11 -> V_519 . V_205 ;
if ( V_11 -> V_519 . V_520 )
return 0 ;
V_122 -> V_128 = V_500 ;
V_122 -> V_127 = V_500 ;
V_122 -> V_129 = V_521 ;
F_264 ( V_11 , F_254 ( V_522 ) ,
& V_122 -> V_125 ) ;
F_264 ( V_11 , F_254 ( V_523 ) ,
& V_122 -> V_126 ) ;
if ( ! V_122 -> V_125 || ! V_122 -> V_126 ) {
F_7 ( V_11 -> V_20 , L_121 ,
V_21 ,
V_122 -> V_125 ,
V_122 -> V_126 ) ;
return - V_218 ;
}
F_264 ( V_11 , F_254 ( V_524 ) , & V_122 -> V_123 ) ;
if ( ! V_122 -> V_123 ) {
F_264 ( V_11 , F_254 ( V_525 ) ,
& V_122 -> V_123 ) ;
if ( ! V_122 -> V_123 ) {
F_7 ( V_11 -> V_20 , L_122 ,
V_21 , V_122 -> V_123 ) ;
return - V_218 ;
}
V_122 -> V_127 = V_502 ;
}
F_265 ( V_11 , F_254 ( V_524 ) ,
& V_122 -> V_124 ) ;
if ( ! V_122 -> V_124 ) {
F_265 ( V_11 , F_254 ( V_525 ) ,
& V_122 -> V_124 ) ;
if ( ! V_122 -> V_124 ) {
F_7 ( V_11 -> V_20 , L_123 ,
V_21 , V_122 -> V_124 ) ;
return - V_218 ;
}
V_122 -> V_128 = V_502 ;
}
V_11 -> V_519 . V_520 = true ;
return 0 ;
}
static int F_89 ( struct V_10 * V_11 ,
struct V_201 * V_526 )
{
int V_14 ;
if ( V_526 -> V_123 == V_11 -> V_122 . V_123 &&
V_526 -> V_124 == V_11 -> V_122 . V_124 &&
V_526 -> V_125 == V_11 -> V_122 . V_125 &&
V_526 -> V_126 == V_11 -> V_122 . V_126 &&
V_526 -> V_127 == V_11 -> V_122 . V_127 &&
V_526 -> V_128 == V_11 -> V_122 . V_128 &&
V_526 -> V_129 == V_11 -> V_122 . V_129 ) {
F_76 ( V_11 -> V_20 , L_124 , V_21 ) ;
return 0 ;
}
F_252 ( V_11 , F_254 ( V_527 ) , V_526 -> V_123 ) ;
F_252 ( V_11 , F_254 ( V_528 ) ,
V_526 -> V_125 ) ;
if ( V_526 -> V_127 == V_501 ||
V_526 -> V_127 == V_500 )
F_252 ( V_11 , F_254 ( V_529 ) , TRUE ) ;
else
F_252 ( V_11 , F_254 ( V_529 ) , FALSE ) ;
F_252 ( V_11 , F_254 ( V_530 ) , V_526 -> V_124 ) ;
F_252 ( V_11 , F_254 ( V_531 ) ,
V_526 -> V_126 ) ;
if ( V_526 -> V_128 == V_501 ||
V_526 -> V_128 == V_500 )
F_252 ( V_11 , F_254 ( V_532 ) , TRUE ) ;
else
F_252 ( V_11 , F_254 ( V_532 ) , FALSE ) ;
if ( V_526 -> V_127 == V_501 ||
V_526 -> V_128 == V_501 ||
V_526 -> V_127 == V_500 ||
V_526 -> V_128 == V_500 )
F_252 ( V_11 , F_254 ( V_533 ) ,
V_526 -> V_129 ) ;
V_14 = F_251 ( V_11 , V_526 -> V_127 << 4
| V_526 -> V_128 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 ,
L_125 , V_21 , V_14 ) ;
} else {
F_266 ( V_11 , V_191 , NULL ,
V_526 ) ;
memcpy ( & V_11 -> V_122 , V_526 ,
sizeof( struct V_201 ) ) ;
}
return V_14 ;
}
static int F_267 ( struct V_10 * V_11 ,
struct V_201 * V_534 )
{
struct V_201 V_535 = { 0 } ;
int V_14 ;
V_14 = F_266 ( V_11 , V_190 ,
V_534 , & V_535 ) ;
if ( V_14 )
memcpy ( & V_535 , V_534 , sizeof( V_535 ) ) ;
V_14 = F_89 ( V_11 , & V_535 ) ;
if ( ! V_14 )
F_30 ( V_11 ) ;
return V_14 ;
}
static int F_268 ( struct V_10 * V_11 )
{
int V_58 ;
int V_134 ;
bool V_398 = 1 ;
V_134 = F_220 ( V_11 , V_403 ,
V_536 , NULL ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 ,
L_126 ,
V_21 , V_134 ) ;
goto V_154;
}
for ( V_58 = 0 ; V_58 < 1000 && ! V_134 && V_398 ; V_58 ++ )
V_134 = F_220 ( V_11 , V_407 ,
V_536 , & V_398 ) ;
if ( V_134 )
F_7 ( V_11 -> V_20 ,
L_127 ,
V_21 , V_134 ) ;
else if ( V_398 )
F_7 ( V_11 -> V_20 ,
L_128 ,
V_21 ) ;
V_154:
return V_134 ;
}
static int F_269 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
T_3 V_62 ;
F_183 ( V_11 , V_537 ) ;
if ( F_202 ( V_11 ) )
F_60 ( V_11 , V_11 -> V_13 - 1 , V_538 ) ;
else
F_63 ( V_11 ) ;
F_49 ( V_11 , F_181 ( V_11 -> V_466 ) ,
V_539 ) ;
F_49 ( V_11 , F_182 ( V_11 -> V_466 ) ,
V_540 ) ;
F_49 ( V_11 , F_181 ( V_11 -> V_467 ) ,
V_541 ) ;
F_49 ( V_11 , F_182 ( V_11 -> V_467 ) ,
V_542 ) ;
F_155 () ;
V_62 = F_14 ( V_11 , V_148 ) ;
if ( ! ( F_52 ( V_62 ) ) ) {
F_64 ( V_11 ) ;
} else {
F_7 ( V_11 -> V_20 ,
L_129 ) ;
V_134 = - V_304 ;
goto V_154;
}
V_154:
return V_134 ;
}
static inline void F_270 ( struct V_10 * V_11 , bool V_133 )
{
int V_134 ;
F_49 ( V_11 , V_543 , V_178 ) ;
V_134 = F_31 ( V_11 , V_178 ,
V_177 , V_543 ,
10 , 1 , V_133 ) ;
if ( V_134 )
F_7 ( V_11 -> V_20 , L_130 , V_21 ) ;
}
static int F_271 ( struct V_10 * V_11 )
{
int V_544 ;
if ( ! F_66 ( V_11 ) )
F_270 ( V_11 , true ) ;
F_272 ( V_11 ) ;
F_273 ( V_11 , V_190 ) ;
F_65 ( V_11 ) ;
F_274 ( 1 ) ;
V_544 = 10 ;
while ( F_66 ( V_11 ) ) {
if ( V_544 ) {
V_544 -- ;
} else {
F_7 ( V_11 -> V_20 ,
L_131 ) ;
return - V_304 ;
}
F_274 ( 5 ) ;
}
F_183 ( V_11 , V_545 ) ;
F_273 ( V_11 , V_191 ) ;
return 0 ;
}
static int F_275 ( struct V_10 * V_11 , bool V_490 )
{
int V_546 , V_58 , V_134 = 0 ;
if ( ! V_490 )
F_264 ( V_11 , F_254 ( V_523 ) ,
& V_546 ) ;
else
F_265 ( V_11 , F_254 ( V_523 ) ,
& V_546 ) ;
for ( V_58 = 0 ; V_58 < V_546 ; V_58 ++ ) {
if ( ! V_490 )
V_134 = F_252 ( V_11 ,
F_253 ( V_547 ,
F_276 ( V_58 ) ) ,
0 ) ;
else
V_134 = F_277 ( V_11 ,
F_253 ( V_547 ,
F_276 ( V_58 ) ) ,
0 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_132 ,
V_21 , V_490 , V_58 , V_134 ) ;
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
int V_399 = V_548 ;
bool V_549 = false ;
if ( ! F_280 ( V_11 ) )
V_549 = true ;
V_550:
do {
F_281 ( V_11 , V_190 ) ;
V_14 = F_244 ( V_11 ) ;
if ( ! V_14 && ! F_39 ( V_11 ) ) {
F_7 ( V_11 -> V_20 , L_133 , V_21 ) ;
V_14 = - V_551 ;
goto V_154;
}
if ( V_14 && F_271 ( V_11 ) )
goto V_154;
} while ( V_14 && V_399 -- );
if ( V_14 )
goto V_154;
if ( V_549 ) {
V_549 = false ;
V_399 = V_548 ;
goto V_550;
}
F_262 ( V_11 ) ;
F_30 ( V_11 ) ;
if ( V_11 -> V_119 & V_552 ) {
V_14 = F_278 ( V_11 ) ;
if ( V_14 )
goto V_154;
}
V_14 = F_281 ( V_11 , V_191 ) ;
if ( V_14 )
goto V_154;
V_14 = F_269 ( V_11 ) ;
V_154:
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_134 , V_14 ) ;
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
F_23 ( V_11 ) ;
}
return V_14 ;
}
static int F_282 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
int V_399 ;
F_82 ( V_11 , false ) ;
F_172 ( & V_11 -> V_273 . V_402 ) ;
for ( V_399 = V_553 ; V_399 > 0 ; V_399 -- ) {
V_134 = F_214 ( V_11 , V_357 ,
V_554 ) ;
if ( ! V_134 || V_134 == - V_137 )
break;
F_76 ( V_11 -> V_20 , L_96 , V_21 , V_134 ) ;
}
F_174 ( & V_11 -> V_273 . V_402 ) ;
F_86 ( V_11 ) ;
if ( V_134 )
F_7 ( V_11 -> V_20 , L_135 , V_21 , V_134 ) ;
return V_134 ;
}
static void F_283 ( struct V_555 * V_556 )
{
int V_14 = 0 ;
T_2 V_557 ;
int V_399 ;
struct V_10 * V_11 ;
V_11 = F_197 ( V_556 -> V_112 ) ;
V_557 = V_11 -> V_13 ;
for ( V_399 = V_400 ; V_399 > 0 ; V_399 -- ) {
V_14 = F_238 ( V_11 ,
F_193 ( V_556 -> V_343 ) ,
V_558 ,
& V_557 ,
sizeof( V_557 ) ) ;
if ( ! V_14 || V_14 == - V_559 )
break;
F_76 ( V_11 -> V_20 , L_96 , V_21 , V_14 ) ;
}
if ( V_14 == - V_458 )
V_557 = 1 ;
else if ( ! V_557 )
V_557 = V_11 -> V_13 ;
else
V_557 = F_158 ( int , V_557 , V_11 -> V_13 ) ;
F_76 ( V_11 -> V_20 , L_136 ,
V_21 , V_557 ) ;
F_284 ( V_556 , V_557 ) ;
}
static int F_285 ( struct V_10 * V_11 ,
T_2 V_343 ,
T_2 * V_560 )
{
int V_14 ;
if ( ! V_560 )
V_14 = - V_218 ;
else if ( V_343 >= V_457 )
V_14 = - V_559 ;
else
V_14 = F_238 ( V_11 ,
V_343 ,
V_561 ,
V_560 ,
sizeof( * V_560 ) ) ;
return V_14 ;
}
static inline void F_286 ( struct V_10 * V_11 ,
struct V_555 * V_556 )
{
if ( V_11 -> V_562 . V_563 &&
! V_11 -> V_562 . V_564 ) {
T_2 V_560 ;
if ( ! F_285 ( V_11 , F_193 ( V_556 -> V_343 ) ,
& V_560 ) &&
( V_560 == V_565 ) )
V_11 -> V_562 . V_564 = true ;
}
}
static int F_287 ( struct V_555 * V_556 )
{
struct V_10 * V_11 ;
V_11 = F_197 ( V_556 -> V_112 ) ;
V_556 -> V_566 = 1 ;
V_556 -> V_567 = 1 ;
V_556 -> V_568 = 1 ;
F_283 ( V_556 ) ;
F_286 ( V_11 , V_556 ) ;
return 0 ;
}
static int F_288 ( struct V_555 * V_556 , int V_569 )
{
struct V_10 * V_11 = F_197 ( V_556 -> V_112 ) ;
if ( V_569 > V_11 -> V_13 )
V_569 = V_11 -> V_13 ;
return F_284 ( V_556 , V_569 ) ;
}
static int F_289 ( struct V_555 * V_556 )
{
struct V_570 * V_571 = V_556 -> V_570 ;
F_290 ( V_571 , V_572 - 1 ) ;
F_291 ( V_571 , V_573 ) ;
return 0 ;
}
static void F_292 ( struct V_555 * V_556 )
{
struct V_10 * V_11 ;
V_11 = F_197 ( V_556 -> V_112 ) ;
if ( F_193 ( V_556 -> V_343 ) == V_574 ) {
unsigned long V_193 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_575 = NULL ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
}
}
static int F_293 ( struct V_10 * V_11 , T_3 V_395 , T_2 * V_379 )
{
struct V_97 * V_152 ;
struct V_576 * V_577 ;
unsigned long V_193 ;
int V_578 ;
int V_579 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_51 ( V_395 , & V_11 -> V_69 ) ;
V_152 = V_11 -> V_99 ;
V_578 = F_42 ( & V_152 [ V_395 ] ) ;
if ( V_578 == V_580 ) {
V_577 = (struct V_576 * )
V_152 [ V_395 ] . V_103 ;
V_579 = F_13 ( V_577 -> V_581 ) ;
V_579 = V_579 & V_582 ;
if ( V_379 )
* V_379 = ( T_2 ) V_579 ;
} else {
F_7 ( V_11 -> V_20 , L_137 ,
V_21 , V_578 ) ;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
return V_578 ;
}
static inline int
F_294 ( struct V_28 * V_29 , int V_583 )
{
int V_584 = 0 ;
switch ( V_583 ) {
case V_585 :
F_156 ( V_29 ) ;
case V_586 :
V_584 |= V_587 << 16 |
V_588 << 8 |
V_583 ;
break;
case V_589 :
case V_590 :
case V_591 :
F_156 ( V_29 ) ;
V_584 |= V_583 ;
break;
default:
V_584 |= V_371 << 16 ;
break;
}
return V_584 ;
}
static inline int
F_295 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
int V_584 = 0 ;
int V_583 ;
int V_592 ;
V_592 = F_40 ( V_29 ) ;
switch ( V_592 ) {
case V_580 :
V_584 = F_55 ( V_29 -> V_91 ) ;
V_11 -> V_70 . V_71 = F_209 ( 0 , 0 ) ;
switch ( V_584 ) {
case V_593 :
V_584 = F_56 ( V_29 -> V_91 ) ;
V_583 = V_584 & V_594 ;
V_584 = F_294 ( V_29 , V_583 ) ;
if ( ! V_11 -> V_109 &&
F_58 ( V_29 -> V_91 ) )
F_133 ( & V_11 -> V_595 ) ;
break;
case V_382 :
V_584 = V_371 << 16 ;
F_7 ( V_11 -> V_20 ,
L_138 ) ;
break;
default:
V_584 = V_371 << 16 ;
F_7 ( V_11 -> V_20 ,
L_139 ,
V_584 ) ;
break;
}
break;
case V_596 :
V_584 |= V_597 << 16 ;
break;
case V_339 :
V_584 |= V_598 << 16 ;
break;
case V_599 :
case V_600 :
case V_601 :
case V_602 :
case V_603 :
case V_604 :
default:
V_584 |= V_371 << 16 ;
F_7 ( V_11 -> V_20 ,
L_140 ,
V_592 , V_29 -> V_262 ) ;
F_23 ( V_11 ) ;
F_29 ( V_11 ) ;
break;
}
if ( F_296 ( V_584 ) != V_587 )
F_25 ( V_11 , 1 << V_29 -> V_262 , true ) ;
return V_584 ;
}
static void F_297 ( struct V_10 * V_11 , T_3 V_605 )
{
if ( ( V_605 & V_508 ) && V_11 -> V_256 ) {
V_11 -> V_256 -> V_296 |=
F_53 ( V_11 ) ;
V_11 -> V_256 -> V_297 =
F_54 ( V_11 ) ;
V_386 ( & V_11 -> V_256 -> V_301 ) ;
}
if ( ( V_605 & V_606 ) && V_11 -> V_257 )
V_386 ( V_11 -> V_257 ) ;
}
static void F_298 ( struct V_10 * V_11 ,
unsigned long V_607 )
{
struct V_28 * V_29 ;
struct V_309 * V_32 ;
int V_584 ;
int V_395 ;
F_26 (index, &completed_reqs, hba->nutrs) {
V_29 = & V_11 -> V_31 [ V_395 ] ;
V_32 = V_29 -> V_32 ;
if ( V_32 ) {
F_11 ( V_11 , V_395 , L_141 ) ;
V_584 = F_295 ( V_11 , V_29 ) ;
F_299 ( V_32 ) ;
V_32 -> V_584 = V_584 ;
V_29 -> V_32 = NULL ;
F_47 ( V_395 , & V_11 -> V_105 ) ;
V_32 -> V_372 ( V_32 ) ;
F_139 ( V_11 ) ;
} else if ( V_29 -> V_335 == V_354 ||
V_29 -> V_335 == V_353 ) {
if ( V_11 -> V_273 . V_386 ) {
F_11 ( V_11 , V_395 ,
L_142 ) ;
V_386 ( V_11 -> V_273 . V_386 ) ;
}
}
if ( F_105 ( V_11 ) )
V_11 -> V_203 . V_211 -- ;
}
V_11 -> V_68 ^= V_607 ;
F_152 ( V_11 ) ;
F_218 ( & V_11 -> V_273 . V_390 ) ;
}
static void F_300 ( struct V_10 * V_11 )
{
unsigned long V_607 ;
T_3 V_195 ;
if ( F_202 ( V_11 ) )
F_59 ( V_11 ) ;
V_195 = F_14 ( V_11 , V_44 ) ;
V_607 = V_195 ^ V_11 -> V_68 ;
F_298 ( V_11 , V_607 ) ;
}
static int F_301 ( struct V_10 * V_11 , T_7 V_130 )
{
int V_134 = 0 ;
T_3 V_22 ;
if ( ! ( V_11 -> V_608 & V_130 ) )
goto V_154;
V_22 = V_11 -> V_608 & ~ V_130 ;
V_22 &= 0xFFFF ;
V_134 = F_224 ( V_11 , V_412 ,
V_609 , 0 , 0 , & V_22 ) ;
if ( ! V_134 )
V_11 -> V_608 &= ~ V_130 ;
V_154:
return V_134 ;
}
static int F_302 ( struct V_10 * V_11 , T_7 V_130 )
{
int V_134 = 0 ;
T_3 V_22 ;
if ( V_11 -> V_608 & V_130 )
goto V_154;
V_22 = V_11 -> V_608 | V_130 ;
V_22 &= 0xFFFF ;
V_134 = F_224 ( V_11 , V_412 ,
V_609 , 0 , 0 , & V_22 ) ;
if ( ! V_134 )
V_11 -> V_608 |= V_130 ;
V_154:
return V_134 ;
}
static int F_303 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
if ( V_11 -> V_111 )
goto V_154;
V_134 = F_220 ( V_11 , V_403 ,
V_610 , NULL ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_143 ,
V_21 , V_134 ) ;
goto V_154;
}
V_11 -> V_111 = true ;
F_304 ( F_16 ( V_11 -> V_20 ) , L_144 ) ;
V_134 = F_301 ( V_11 , V_611 ) ;
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
V_134 = F_302 ( V_11 , V_611 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_146 ,
V_21 , V_134 ) ;
goto V_154;
}
V_134 = F_220 ( V_11 , V_404 ,
V_610 , NULL ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_147 ,
V_21 , V_134 ) ;
F_301 ( V_11 , V_611 ) ;
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
V_11 -> V_608 |= V_611 ;
F_303 ( V_11 ) ;
} else {
V_11 -> V_111 = true ;
V_11 -> V_608 &= ~ V_611 ;
F_305 ( V_11 ) ;
}
}
static inline int F_308 ( struct V_10 * V_11 , T_3 * V_506 )
{
return F_224 ( V_11 , V_413 ,
V_612 , 0 , 0 , V_506 ) ;
}
static int F_309 ( struct V_10 * V_11 ,
enum V_613 V_506 )
{
int V_134 ;
T_3 V_614 = 0 ;
V_134 = F_308 ( V_11 , & V_614 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_149 ,
V_21 , V_134 ) ;
goto V_154;
} else if ( V_614 > V_615 ) {
F_7 ( V_11 -> V_20 , L_150 ,
V_21 , V_614 ) ;
V_134 = - V_218 ;
goto V_154;
}
if ( V_614 >= V_506 )
V_134 = F_303 ( V_11 ) ;
else
V_134 = F_305 ( V_11 ) ;
V_154:
return V_134 ;
}
static int F_310 ( struct V_10 * V_11 )
{
return F_309 ( V_11 , V_11 -> V_616 ) ;
}
static inline int F_311 ( struct V_10 * V_11 , T_3 * V_506 )
{
return F_224 ( V_11 , V_413 ,
V_617 , 0 , 0 , V_506 ) ;
}
static void F_312 ( struct V_10 * V_11 )
{
int V_134 ;
T_3 V_614 = 0 ;
if ( V_11 -> V_618 )
goto V_619;
V_134 = F_308 ( V_11 , & V_614 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_149 ,
V_21 , V_134 ) ;
goto V_154;
}
if ( V_614 < V_620 ) {
F_7 ( V_11 -> V_20 , L_151 ,
V_21 , V_614 ) ;
V_11 -> V_616 = V_614 ;
V_11 -> V_618 = true ;
}
V_619:
V_134 = F_303 ( V_11 ) ;
V_154:
if ( V_134 < 0 )
F_7 ( V_11 -> V_20 , L_152 ,
V_21 , V_134 ) ;
}
static void F_313 ( struct V_207 * V_208 )
{
struct V_10 * V_11 ;
int V_134 ;
T_3 V_506 = 0 ;
V_11 = F_99 ( V_208 , struct V_10 , V_595 ) ;
F_116 ( V_11 -> V_20 ) ;
V_134 = F_311 ( V_11 , & V_506 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_153 ,
V_21 , V_134 ) ;
goto V_154;
}
V_506 &= V_11 -> V_608 ;
if ( V_506 & V_611 )
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
unsigned long V_193 ;
bool V_621 = true ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_11 -> V_106 & ( V_622 | V_623 ) )
goto V_154;
if ( ( V_11 -> V_106 & V_624 ) ||
( ( V_11 -> V_106 & V_625 ) &&
( V_11 -> V_107 & V_626 ) ) )
goto V_154;
if ( ( V_11 -> V_106 & V_625 ) &&
( V_11 -> V_107 & V_627 ) ) {
int V_134 ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_274 ( 50 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( ( V_11 -> V_106 & V_628 ) ||
( ( V_11 -> V_106 & V_625 ) &&
( V_11 -> V_107 & ~ V_627 ) ) )
goto V_154;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_134 = F_282 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_134 )
goto V_154;
if ( V_11 -> V_107 == V_627 )
V_11 -> V_106 &= ~ V_625 ;
V_11 -> V_107 &= ~ V_627 ;
if ( ! V_11 -> V_107 ) {
V_621 = false ;
goto V_154;
}
}
V_154:
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
return V_621 ;
}
static void F_317 ( struct V_207 * V_208 )
{
struct V_10 * V_11 ;
unsigned long V_193 ;
T_3 V_629 = 0 ;
T_3 V_630 = 0 ;
int V_134 = 0 ;
int V_12 ;
bool V_631 = false ;
V_11 = F_99 ( V_208 , struct V_10 , V_632 ) ;
F_116 ( V_11 -> V_20 ) ;
F_82 ( V_11 , false ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_11 -> V_104 == V_368 )
goto V_154;
V_11 -> V_104 = V_368 ;
F_256 ( V_11 ) ;
F_314 ( V_11 ) ;
if ( V_11 -> V_120 & V_633 ) {
bool V_14 ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_14 = F_316 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( ! V_14 )
goto V_634;
}
if ( ( V_11 -> V_106 & V_628 ) ||
( ( V_11 -> V_106 & V_625 ) &&
( V_11 -> V_107 & ( V_635 |
V_627 |
V_626 ) ) ) )
V_631 = true ;
if ( V_631 )
goto V_636;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_26 (tag, &hba->outstanding_reqs, hba->nutrs) {
if ( F_206 ( V_11 , V_12 ) ) {
V_629 = true ;
goto V_637;
}
}
F_26 (tag, &hba->outstanding_tasks, hba->nutmrs) {
if ( F_318 ( V_11 , V_12 ) ) {
V_630 = true ;
goto V_637;
}
}
V_637:
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_314 ( V_11 ) ;
if ( V_629 || V_630 )
V_631 = true ;
V_636:
if ( V_631 ) {
unsigned long V_638 = ( 1UL << V_11 -> V_13 ) - 1 ;
if ( V_11 -> V_68 == V_638 )
F_298 ( V_11 ,
( 1UL << ( V_11 -> V_13 - 1 ) ) ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_134 = F_319 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_154 ,
V_21 ) ;
V_11 -> V_104 = V_370 ;
}
F_320 ( V_11 -> V_112 , 0 ) ;
V_11 -> V_106 = 0 ;
V_11 -> V_107 = 0 ;
}
V_634:
if ( ! V_631 ) {
V_11 -> V_104 = V_198 ;
if ( V_11 -> V_106 || V_11 -> V_107 )
F_321 ( V_11 -> V_20 , L_155 ,
V_21 , V_11 -> V_106 , V_11 -> V_107 ) ;
}
F_258 ( V_11 ) ;
V_154:
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_95 ( V_11 -> V_112 ) ;
F_86 ( V_11 ) ;
F_118 ( V_11 -> V_20 ) ;
}
static void F_322 ( struct V_55 * V_639 ,
T_3 V_62 )
{
V_639 -> V_62 [ V_639 -> V_61 ] = V_62 ;
V_639 -> V_63 [ V_639 -> V_61 ] = F_72 () ;
V_639 -> V_61 = ( V_639 -> V_61 + 1 ) % V_59 ;
}
static void F_323 ( struct V_10 * V_11 )
{
T_3 V_62 ;
V_62 = F_14 ( V_11 , V_640 ) ;
if ( ( V_62 & V_641 ) &&
( V_62 & V_642 ) ) {
F_76 ( V_11 -> V_20 , L_156 , V_21 ) ;
F_322 ( & V_11 -> V_70 . V_73 , V_62 ) ;
}
V_62 = F_14 ( V_11 , V_643 ) ;
if ( V_62 )
F_322 ( & V_11 -> V_70 . V_74 , V_62 ) ;
if ( V_62 & V_644 )
V_11 -> V_645 |= V_635 ;
else if ( V_11 -> V_120 &
V_633 ) {
if ( V_62 & V_646 )
V_11 -> V_645 |=
V_627 ;
else if ( V_62 & V_647 )
V_11 -> V_645 |= V_626 ;
}
V_62 = F_14 ( V_11 , V_648 ) ;
if ( V_62 ) {
F_322 ( & V_11 -> V_70 . V_75 , V_62 ) ;
V_11 -> V_645 |= V_649 ;
}
V_62 = F_14 ( V_11 , V_650 ) ;
if ( V_62 ) {
F_322 ( & V_11 -> V_70 . V_76 , V_62 ) ;
V_11 -> V_645 |= V_651 ;
}
V_62 = F_14 ( V_11 , V_652 ) ;
if ( V_62 ) {
F_322 ( & V_11 -> V_70 . V_77 , V_62 ) ;
V_11 -> V_645 |= V_653 ;
}
F_76 ( V_11 -> V_20 , L_157 ,
V_21 , V_11 -> V_645 ) ;
}
static void F_324 ( struct V_10 * V_11 )
{
bool V_654 = false ;
if ( V_11 -> V_655 & V_628 )
V_654 = true ;
if ( V_11 -> V_655 & V_625 ) {
V_11 -> V_645 = 0 ;
F_323 ( V_11 ) ;
if ( V_11 -> V_645 )
V_654 = true ;
}
if ( V_654 ) {
V_11 -> V_106 |= V_11 -> V_655 ;
V_11 -> V_107 |= V_11 -> V_645 ;
if ( V_11 -> V_104 == V_198 ) {
F_92 ( V_11 -> V_112 ) ;
V_11 -> V_104 = V_367 ;
if ( V_11 -> V_106 & ( V_628 | V_625 ) ) {
bool V_81 = ! ! ( V_11 -> V_106 &
V_623 ) ;
F_7 ( V_11 -> V_20 , L_158 ,
V_21 , V_11 -> V_106 ,
V_11 -> V_107 ) ;
F_23 ( V_11 ) ;
F_30 ( V_11 ) ;
F_28 ( V_11 , V_11 -> V_69 ) ;
F_25 ( V_11 , V_11 -> V_68 ,
V_81 ) ;
}
F_133 ( & V_11 -> V_632 ) ;
}
}
}
static void F_315 ( struct V_10 * V_11 )
{
T_3 V_194 ;
V_194 = F_14 ( V_11 , V_200 ) ;
V_11 -> V_656 = V_194 ^ V_11 -> V_69 ;
F_218 ( & V_11 -> V_657 ) ;
}
static void F_325 ( struct V_10 * V_11 , T_3 V_605 )
{
V_11 -> V_655 = V_658 & V_605 ;
if ( V_11 -> V_655 )
F_324 ( V_11 ) ;
if ( V_605 & V_545 )
F_297 ( V_11 , V_605 ) ;
if ( V_605 & V_659 )
F_315 ( V_11 ) ;
if ( V_605 & V_660 )
F_300 ( V_11 ) ;
}
static T_9 V_17 ( int V_16 , void * V_661 )
{
T_3 V_605 , V_662 ;
T_9 V_663 = V_664 ;
struct V_10 * V_11 = V_661 ;
F_326 ( V_11 -> V_112 -> V_197 ) ;
V_605 = F_14 ( V_11 , V_43 ) ;
V_662 =
V_605 & F_14 ( V_11 , V_319 ) ;
if ( V_605 )
F_49 ( V_11 , V_605 , V_43 ) ;
if ( V_662 ) {
F_325 ( V_11 , V_662 ) ;
V_663 = V_665 ;
}
F_327 ( V_11 -> V_112 -> V_197 ) ;
return V_663 ;
}
static int F_318 ( struct V_10 * V_11 , int V_12 )
{
int V_134 = 0 ;
T_3 V_130 = 1 << V_12 ;
unsigned long V_193 ;
if ( ! F_328 ( V_12 , & V_11 -> V_69 ) )
goto V_154;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_49 ( V_11 , ~ ( 1 << V_12 ) , V_666 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_134 = F_31 ( V_11 ,
V_200 ,
V_130 , 0 , 1000 , 1000 , true ) ;
V_154:
return V_134 ;
}
static int F_329 ( struct V_10 * V_11 , int V_667 , int V_668 ,
T_2 V_669 , T_2 * V_670 )
{
struct V_97 * V_152 ;
struct V_671 * V_672 ;
struct V_365 * V_112 ;
unsigned long V_193 ;
int V_153 ;
int V_134 ;
int V_262 ;
V_112 = V_11 -> V_112 ;
F_216 ( V_11 -> V_673 , F_43 ( V_11 , & V_153 ) ) ;
F_82 ( V_11 , false ) ;
F_83 ( V_112 -> V_197 , V_193 ) ;
V_152 = V_11 -> V_99 ;
V_152 += V_153 ;
V_152 -> V_100 . V_162 = F_179 ( V_338 ) ;
V_152 -> V_100 . V_150 =
F_179 ( V_339 ) ;
V_672 =
(struct V_671 * ) V_152 -> V_102 ;
V_262 = V_11 -> V_13 + V_153 ;
V_672 -> V_100 . V_162 =
F_187 ( V_674 , 0 ,
V_667 , V_262 ) ;
V_672 -> V_100 . V_163 =
F_187 ( 0 , V_669 , 0 , 0 ) ;
V_672 -> V_675 = F_188 ( V_667 ) ;
V_672 -> V_676 = F_188 ( V_668 ) ;
F_330 ( V_11 , V_153 , V_669 ) ;
F_154 ( V_153 , & V_11 -> V_69 ) ;
F_155 () ;
F_49 ( V_11 , 1 << V_153 , V_200 ) ;
F_155 () ;
F_84 ( V_112 -> V_197 , V_193 ) ;
V_134 = F_331 ( V_11 -> V_657 ,
F_328 ( V_153 , & V_11 -> V_656 ) ,
F_32 ( V_677 ) ) ;
if ( ! V_134 ) {
F_7 ( V_11 -> V_20 , L_159 ,
V_21 , V_669 ) ;
if ( F_318 ( V_11 , V_153 ) )
F_332 ( V_11 -> V_20 , L_160 ,
V_21 , V_153 ) ;
V_134 = - V_137 ;
} else {
V_134 = F_293 ( V_11 , V_153 , V_670 ) ;
}
F_333 ( V_153 , & V_11 -> V_656 ) ;
F_46 ( V_11 , V_153 ) ;
F_218 ( & V_11 -> V_673 ) ;
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_334 ( struct V_309 * V_32 )
{
struct V_365 * V_112 ;
struct V_10 * V_11 ;
unsigned int V_12 ;
T_3 V_61 ;
int V_134 ;
T_2 V_379 = 0xF ;
struct V_28 * V_29 ;
unsigned long V_193 ;
V_112 = V_32 -> V_215 -> V_112 ;
V_11 = F_197 ( V_112 ) ;
V_12 = V_32 -> V_36 -> V_12 ;
V_29 = & V_11 -> V_31 [ V_12 ] ;
V_134 = F_329 ( V_11 , V_29 -> V_343 , 0 , V_678 , & V_379 ) ;
if ( V_134 || V_379 != V_679 ) {
if ( ! V_134 )
V_134 = V_379 ;
goto V_154;
}
F_26 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_11 -> V_31 [ V_61 ] . V_343 == V_29 -> V_343 ) {
V_134 = F_206 ( V_11 , V_61 ) ;
if ( V_134 )
break;
}
}
F_83 ( V_112 -> V_197 , V_193 ) ;
F_300 ( V_11 ) ;
F_84 ( V_112 -> V_197 , V_193 ) ;
V_154:
V_11 -> V_117 = 0 ;
if ( ! V_134 ) {
V_134 = V_680 ;
} else {
F_7 ( V_11 -> V_20 , L_161 , V_21 , V_134 ) ;
V_134 = V_681 ;
}
return V_134 ;
}
static void F_335 ( struct V_10 * V_11 , unsigned long V_80 )
{
struct V_28 * V_29 ;
int V_12 ;
F_26 (tag, &bitmap, hba->nutrs) {
V_29 = & V_11 -> V_31 [ V_12 ] ;
V_29 -> V_375 = true ;
}
}
static int F_336 ( struct V_309 * V_32 )
{
struct V_365 * V_112 ;
struct V_10 * V_11 ;
unsigned long V_193 ;
unsigned int V_12 ;
int V_134 = 0 ;
int V_682 ;
T_2 V_379 = 0xF ;
struct V_28 * V_29 ;
T_3 V_62 ;
V_112 = V_32 -> V_215 -> V_112 ;
V_11 = F_197 ( V_112 ) ;
V_12 = V_32 -> V_36 -> V_12 ;
V_29 = & V_11 -> V_31 [ V_12 ] ;
if ( ! F_4 ( V_11 , V_12 ) ) {
F_7 ( V_11 -> V_20 ,
L_73 ,
V_21 , V_12 , V_32 , V_32 -> V_36 ) ;
F_198 () ;
}
if ( V_29 -> V_343 == V_574 )
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
if ( V_29 -> V_375 ) {
V_134 = - V_304 ;
goto V_154;
}
for ( V_682 = 100 ; V_682 ; V_682 -- ) {
V_134 = F_329 ( V_11 , V_29 -> V_343 , V_29 -> V_262 ,
V_683 , & V_379 ) ;
if ( ! V_134 && V_379 == V_684 ) {
F_7 ( V_11 -> V_20 , L_165 ,
V_21 , V_12 ) ;
break;
} else if ( ! V_134 && V_379 == V_679 ) {
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
V_134 = V_379 ;
goto V_154;
}
}
if ( ! V_682 ) {
V_134 = - V_199 ;
goto V_154;
}
V_134 = F_329 ( V_11 , V_29 -> V_343 , V_29 -> V_262 ,
V_685 , & V_379 ) ;
if ( V_134 || V_379 != V_679 ) {
if ( ! V_134 ) {
V_134 = V_379 ;
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
F_83 ( V_112 -> V_197 , V_193 ) ;
F_50 ( V_11 , V_12 ) ;
V_11 -> V_31 [ V_12 ] . V_32 = NULL ;
F_84 ( V_112 -> V_197 , V_193 ) ;
F_47 ( V_12 , & V_11 -> V_105 ) ;
F_218 ( & V_11 -> V_273 . V_390 ) ;
V_154:
if ( ! V_134 ) {
V_134 = V_680 ;
} else {
F_7 ( V_11 -> V_20 , L_161 , V_21 , V_134 ) ;
F_335 ( V_11 , V_11 -> V_68 ) ;
V_134 = V_681 ;
}
F_86 ( V_11 ) ;
return V_134 ;
}
static int F_257 ( struct V_10 * V_11 )
{
int V_134 ;
unsigned long V_193 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_270 ( V_11 , false ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_71 ( V_11 , true ) ;
V_134 = F_271 ( V_11 ) ;
if ( V_134 )
goto V_154;
V_134 = F_339 ( V_11 ) ;
if ( ! V_134 && ( V_11 -> V_104 != V_198 ) )
V_134 = - V_304 ;
V_154:
if ( V_134 )
F_7 ( V_11 -> V_20 , L_171 , V_21 , V_134 ) ;
return V_134 ;
}
static int F_319 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
unsigned long V_193 ;
int V_399 = V_686 ;
do {
V_134 = F_257 ( V_11 ) ;
} while ( V_134 && -- V_399 );
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_300 ( V_11 ) ;
F_315 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
return V_134 ;
}
static int F_337 ( struct V_309 * V_32 )
{
int V_134 ;
unsigned long V_193 ;
struct V_10 * V_11 ;
V_11 = F_197 ( V_32 -> V_215 -> V_112 ) ;
F_82 ( V_11 , false ) ;
do {
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( ! ( F_340 ( & V_11 -> V_632 ) ||
V_11 -> V_104 == V_368 ) )
break;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_76 ( V_11 -> V_20 , L_172 , V_21 ) ;
F_130 ( & V_11 -> V_632 ) ;
} while ( 1 );
V_11 -> V_104 = V_368 ;
F_256 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_134 = F_319 ( V_11 ) ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( ! V_134 ) {
V_134 = V_680 ;
V_11 -> V_104 = V_198 ;
} else {
V_134 = V_681 ;
V_11 -> V_104 = V_370 ;
}
F_258 ( V_11 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
F_86 ( V_11 ) ;
return V_134 ;
}
static T_3 F_341 ( int V_687 , T_3 V_688 , char * V_689 )
{
int V_58 ;
int V_690 ;
T_7 V_691 ;
T_7 V_692 ;
for ( V_58 = V_688 ; V_58 >= 0 ; V_58 -- ) {
V_691 = F_342 ( ( V_693 * ) & V_689 [ 2 * V_58 ] ) ;
V_692 = ( V_691 & V_694 ) >>
V_695 ;
V_690 = V_691 & V_696 ;
switch ( V_692 ) {
case V_697 :
V_690 = V_690 / 1000 ;
break;
case V_698 :
V_690 = V_690 * 1000 ;
break;
case V_699 :
V_690 = V_690 * 1000 * 1000 ;
break;
case V_700 :
default:
break;
}
if ( V_687 >= V_690 )
break;
}
if ( V_58 < 0 ) {
V_58 = 0 ;
F_343 ( L_173 , V_21 , V_58 ) ;
}
return ( T_3 ) V_58 ;
}
static T_3 F_344 ( struct V_10 * V_11 ,
T_2 * V_415 , int V_263 )
{
T_3 V_701 = 0 ;
if ( ! V_11 -> V_702 . V_703 || ! V_11 -> V_702 . V_704 ||
! V_11 -> V_702 . V_705 ) {
F_7 ( V_11 -> V_20 ,
L_174 ,
V_21 , V_701 ) ;
goto V_154;
}
if ( V_11 -> V_702 . V_703 )
V_701 = F_341 (
V_11 -> V_702 . V_703 -> V_706 ,
V_707 - 1 ,
& V_415 [ V_708 ] ) ;
if ( V_11 -> V_702 . V_704 )
V_701 = F_341 (
V_11 -> V_702 . V_704 -> V_706 ,
V_701 ,
& V_415 [ V_709 ] ) ;
if ( V_11 -> V_702 . V_705 )
V_701 = F_341 (
V_11 -> V_702 . V_705 -> V_706 ,
V_701 ,
& V_415 [ V_710 ] ) ;
V_154:
return V_701 ;
}
static int F_345 ( struct V_10 * V_11 , T_3 V_701 )
{
int V_14 = 0 ;
int V_399 ;
for ( V_399 = V_400 ; V_399 > 0 ; V_399 -- ) {
V_14 = F_223 ( V_11 , V_412 ,
V_711 , 0 , 0 , & V_701 ) ;
if ( ! V_14 )
break;
F_76 ( V_11 -> V_20 , L_175 , V_21 , V_14 ) ;
}
return V_14 ;
}
static void F_346 ( struct V_10 * V_11 )
{
int V_14 ;
int V_446 = V_11 -> V_428 . V_431 ;
T_2 V_415 [ V_11 -> V_428 . V_431 ] ;
V_14 = F_234 ( V_11 , V_415 , V_446 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 ,
L_176 ,
V_21 , V_446 , V_14 ) ;
return;
}
V_11 -> V_712 . V_701 =
F_344 ( V_11 ,
V_415 , V_446 ) ;
F_76 ( V_11 -> V_20 , L_177 ,
V_21 , V_11 -> V_712 . V_701 ) ;
V_14 = F_345 ( V_11 ,
V_11 -> V_712 . V_701 ) ;
if ( V_14 )
F_7 ( V_11 -> V_20 ,
L_178 ,
V_21 , V_11 -> V_712 . V_701 , V_14 ) ;
}
static int F_347 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
struct V_555 * V_713 ;
struct V_555 * V_714 ;
V_11 -> V_575 = F_348 ( V_11 -> V_112 , 0 , 0 ,
F_195 ( V_574 ) , NULL ) ;
if ( F_349 ( V_11 -> V_575 ) ) {
V_14 = F_350 ( V_11 -> V_575 ) ;
V_11 -> V_575 = NULL ;
goto V_154;
}
F_351 ( V_11 -> V_575 ) ;
V_714 = F_348 ( V_11 -> V_112 , 0 , 0 ,
F_195 ( V_715 ) , NULL ) ;
if ( F_349 ( V_714 ) ) {
V_14 = F_350 ( V_714 ) ;
goto V_716;
}
F_351 ( V_714 ) ;
V_713 = F_348 ( V_11 -> V_112 , 0 , 0 ,
F_195 ( V_456 ) , NULL ) ;
if ( F_349 ( V_713 ) ) {
V_14 = F_350 ( V_713 ) ;
goto V_717;
}
F_351 ( V_713 ) ;
goto V_154;
V_717:
F_352 ( V_714 ) ;
V_716:
F_352 ( V_11 -> V_575 ) ;
V_154:
return V_14 ;
}
static int F_353 ( struct V_10 * V_11 ,
struct V_718 * V_429 )
{
int V_134 ;
T_2 V_719 ;
T_2 V_720 [ V_417 + 1 ] = { 0 } ;
T_2 V_415 [ V_11 -> V_428 . V_429 ] ;
V_134 = F_235 ( V_11 , V_415 , V_11 -> V_428 . V_429 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_179 ,
V_21 , V_134 ) ;
goto V_154;
}
V_429 -> V_721 = V_415 [ V_722 ] << 8 |
V_415 [ V_722 + 1 ] ;
V_719 = V_415 [ V_723 ] ;
V_134 = F_236 ( V_11 , V_719 , V_720 ,
V_417 , V_724 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_180 ,
V_21 , V_134 ) ;
goto V_154;
}
V_720 [ V_417 ] = '\0' ;
F_354 ( V_429 -> V_725 , ( V_720 + V_421 ) ,
F_158 ( T_2 , V_720 [ V_425 ] ,
V_726 ) ) ;
V_429 -> V_725 [ V_726 ] = '\0' ;
V_154:
return V_134 ;
}
static void F_355 ( struct V_10 * V_11 ,
struct V_718 * V_429 )
{
struct V_727 * V_728 ;
for ( V_728 = V_729 ; V_728 -> V_730 ; V_728 ++ ) {
if ( ( V_728 -> V_731 . V_721 == V_429 -> V_721 ||
V_728 -> V_731 . V_721 == V_732 ) &&
( F_356 ( V_728 -> V_731 . V_725 , V_429 -> V_725 ) ||
! strcmp ( V_728 -> V_731 . V_725 , V_733 ) ) )
V_11 -> V_120 |= V_728 -> V_730 ;
}
}
static int F_357 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_3 V_734 = 0 , V_735 ;
V_14 = F_265 ( V_11 ,
F_253 (
V_736 ,
F_358 ( 0 ) ) ,
& V_734 ) ;
if ( V_14 )
goto V_154;
V_735 =
( ( V_734 * V_737 )
/ V_738 ) ;
V_14 = F_252 ( V_11 , F_254 ( V_739 ) ,
V_735 ) ;
V_154:
return V_14 ;
}
static int F_359 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_3 V_740 = 0 , V_741 = 0 ;
T_3 V_742 , V_743 ;
V_14 = F_264 ( V_11 ,
F_253 ( V_744 ,
F_276 ( 0 ) ) ,
& V_740 ) ;
if ( V_14 )
goto V_154;
V_14 = F_265 ( V_11 ,
F_253 ( V_745 ,
F_358 ( 0 ) ) ,
& V_741 ) ;
if ( V_14 )
goto V_154;
V_742 = F_360 ( V_740 ,
V_741 ) ;
V_743 = ( ( V_742 * V_746 )
/ V_747 ) ;
V_14 = F_252 ( V_11 , F_254 ( V_748 ) ,
V_743 ) ;
V_154:
return V_14 ;
}
static int F_361 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_3 V_749 , V_750 ;
T_3 V_751 , V_752 ;
T_3 V_753 , V_754 ;
T_2 V_755 [] = { 1 , 4 , 8 , 16 , 32 , 100 } ;
V_14 = F_264 ( V_11 , F_254 ( V_756 ) ,
& V_749 ) ;
if ( V_14 )
goto V_154;
V_14 = F_265 ( V_11 , F_254 ( V_756 ) ,
& V_750 ) ;
if ( V_14 )
goto V_154;
if ( ( V_749 < V_757 ) ||
( V_749 > V_758 ) ) {
F_7 ( V_11 -> V_20 , L_181 ,
V_21 , V_749 ) ;
return - V_218 ;
}
if ( ( V_750 < V_757 ) ||
( V_750 > V_758 ) ) {
F_7 ( V_11 -> V_20 , L_182 ,
V_21 , V_750 ) ;
return - V_218 ;
}
V_14 = F_264 ( V_11 , F_254 ( V_739 ) , & V_751 ) ;
if ( V_14 )
goto V_154;
V_14 = F_265 ( V_11 , F_254 ( V_739 ) ,
& V_752 ) ;
if ( V_14 )
goto V_154;
V_753 = V_751 * V_755 [ V_749 - 1 ] ;
V_754 = V_752 *
V_755 [ V_750 - 1 ] ;
if ( V_753 > V_754 ) {
T_3 V_759 ;
V_759 = V_753 /
V_755 [ V_750 - 1 ] ;
V_759 ++ ;
V_14 = F_277 ( V_11 , F_254 ( V_739 ) ,
V_759 ) ;
}
V_154:
return V_14 ;
}
static void F_362 ( struct V_10 * V_11 )
{
if ( F_70 ( V_11 ) ) {
F_357 ( V_11 ) ;
F_359 ( V_11 ) ;
}
if ( V_11 -> V_120 & V_760 )
F_252 ( V_11 , F_254 ( V_739 ) , 10 ) ;
if ( V_11 -> V_120 & V_761 )
F_361 ( V_11 ) ;
F_363 ( V_11 ) ;
}
static void F_364 ( struct V_10 * V_11 )
{
int V_762 = sizeof( struct V_55 ) ;
V_11 -> V_70 . V_72 = 0 ;
V_11 -> V_70 . V_71 = F_209 ( 0 , 0 ) ;
memset ( & V_11 -> V_70 . V_73 , 0 , V_762 ) ;
memset ( & V_11 -> V_70 . V_74 , 0 , V_762 ) ;
memset ( & V_11 -> V_70 . V_75 , 0 , V_762 ) ;
memset ( & V_11 -> V_70 . V_76 , 0 , V_762 ) ;
memset ( & V_11 -> V_70 . V_77 , 0 , V_762 ) ;
V_11 -> V_117 = 0 ;
}
static void F_365 ( struct V_10 * V_11 )
{
int V_134 ;
V_134 = F_228 ( V_11 , V_427 , 0 ,
& V_11 -> V_428 . V_429 ) ;
if ( V_134 )
V_11 -> V_428 . V_429 = V_763 ;
V_134 = F_228 ( V_11 , V_430 , 0 ,
& V_11 -> V_428 . V_431 ) ;
if ( V_134 )
V_11 -> V_428 . V_431 = V_764 ;
V_134 = F_228 ( V_11 , V_438 , 0 ,
& V_11 -> V_428 . V_439 ) ;
if ( V_134 )
V_11 -> V_428 . V_439 = V_765 ;
V_134 = F_228 ( V_11 , V_434 , 0 ,
& V_11 -> V_428 . V_435 ) ;
if ( V_134 )
V_11 -> V_428 . V_435 = V_766 ;
V_134 = F_228 ( V_11 , V_436 , 0 ,
& V_11 -> V_428 . V_437 ) ;
if ( V_134 )
V_11 -> V_428 . V_437 = V_767 ;
V_134 = F_228 ( V_11 , V_432 , 0 ,
& V_11 -> V_428 . V_433 ) ;
if ( V_134 )
V_11 -> V_428 . V_433 = V_768 ;
}
static void F_366 ( struct V_10 * V_11 )
{
V_11 -> V_428 . V_429 = V_763 ;
V_11 -> V_428 . V_431 = V_764 ;
V_11 -> V_428 . V_439 = V_765 ;
V_11 -> V_428 . V_435 = V_766 ;
V_11 -> V_428 . V_437 = V_767 ;
V_11 -> V_428 . V_433 = V_768 ;
}
static int F_339 ( struct V_10 * V_11 )
{
struct V_718 V_731 = { 0 } ;
int V_14 ;
T_4 V_188 = F_72 () ;
V_14 = F_279 ( V_11 ) ;
if ( V_14 )
goto V_154;
V_11 -> V_616 = V_620 ;
V_11 -> V_618 = false ;
F_364 ( V_11 ) ;
F_128 ( V_11 ) ;
V_14 = F_282 ( V_11 ) ;
if ( V_14 )
goto V_154;
V_14 = F_268 ( V_11 ) ;
if ( V_14 )
goto V_154;
F_365 ( V_11 ) ;
V_14 = F_353 ( V_11 , & V_731 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_183 ,
V_21 , V_14 ) ;
goto V_154;
}
F_355 ( V_11 , & V_731 ) ;
F_362 ( V_11 ) ;
V_14 = F_367 ( V_11 ,
( V_11 -> V_120 & V_769 ) ? true : false ) ;
if ( V_14 )
goto V_154;
F_368 ( V_11 ) ;
F_306 ( V_11 ) ;
V_11 -> V_770 = true ;
if ( F_263 ( V_11 ) ) {
F_7 ( V_11 -> V_20 ,
L_184 ,
V_21 ) ;
} else {
V_14 = F_267 ( V_11 , & V_11 -> V_519 . V_205 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_185 ,
V_21 , V_14 ) ;
goto V_154;
}
}
V_11 -> V_104 = V_198 ;
if ( ! F_106 ( V_11 ) && ! V_11 -> V_109 ) {
bool V_771 ;
memset ( & V_11 -> V_562 , 0 , sizeof( V_11 -> V_562 ) ) ;
if ( ! F_220 ( V_11 , V_407 ,
V_772 , & V_771 ) )
V_11 -> V_562 . V_563 = V_771 ;
if ( ! V_11 -> V_773 )
F_346 ( V_11 ) ;
if ( F_347 ( V_11 ) )
goto V_154;
if ( F_105 ( V_11 ) ) {
memcpy ( & V_11 -> V_203 . V_204 . V_205 ,
& V_11 -> V_122 ,
sizeof( struct V_201 ) ) ;
V_11 -> V_203 . V_204 . V_520 = true ;
if ( ! V_11 -> V_214 ) {
V_11 -> V_214 = F_369 ( V_11 -> V_20 ,
& V_774 ,
L_186 ,
NULL ) ;
if ( F_349 ( V_11 -> V_214 ) ) {
V_14 = F_350 ( V_11 -> V_214 ) ;
F_7 ( V_11 -> V_20 , L_187 ,
V_14 ) ;
goto V_154;
}
}
V_11 -> V_203 . V_238 = true ;
}
F_370 ( V_11 -> V_112 ) ;
F_118 ( V_11 -> V_20 ) ;
}
if ( ! V_11 -> V_773 )
V_11 -> V_773 = true ;
V_154:
if ( V_14 && ! F_106 ( V_11 ) && ! V_11 -> V_109 ) {
F_118 ( V_11 -> V_20 ) ;
F_371 ( V_11 ) ;
}
F_372 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_188 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
return V_14 ;
}
static void F_373 ( void * V_691 , T_10 V_775 )
{
struct V_10 * V_11 = (struct V_10 * ) V_691 ;
F_339 ( V_11 ) ;
}
static enum V_776 F_374 ( struct V_309 * V_777 )
{
unsigned long V_193 ;
struct V_365 * V_112 ;
struct V_10 * V_11 ;
int V_395 ;
bool V_778 = false ;
if ( ! V_777 || ! V_777 -> V_215 || ! V_777 -> V_215 -> V_112 )
return V_779 ;
V_112 = V_777 -> V_215 -> V_112 ;
V_11 = F_197 ( V_112 ) ;
if ( ! V_11 )
return V_779 ;
F_83 ( V_112 -> V_197 , V_193 ) ;
F_26 (index, &hba->outstanding_reqs, hba->nutrs) {
if ( V_11 -> V_31 [ V_395 ] . V_32 == V_777 ) {
V_778 = true ;
break;
}
}
F_84 ( V_112 -> V_197 , V_193 ) ;
return V_778 ? V_779 : V_780 ;
}
static int F_375 ( struct V_215 * V_20 , struct V_781 * V_782 ,
int V_783 )
{
int V_14 ;
if ( ! V_782 )
return 0 ;
V_14 = F_376 ( V_782 -> V_62 , V_783 ) ;
if ( V_14 < 0 ) {
F_7 ( V_20 , L_188 ,
V_21 , V_782 -> V_53 , V_783 , V_14 ) ;
}
return V_14 ;
}
static inline int F_377 ( struct V_10 * V_11 ,
struct V_781 * V_782 )
{
if ( ! V_782 )
return 0 ;
else if ( V_782 -> V_784 )
return 0 ;
else
return F_375 ( V_11 -> V_20 , V_782 ,
V_785 ) ;
}
static inline int F_378 ( struct V_10 * V_11 ,
struct V_781 * V_782 )
{
if ( ! V_782 )
return 0 ;
else if ( V_782 -> V_784 )
return 0 ;
else
return F_375 ( V_11 -> V_20 , V_782 , V_782 -> V_706 ) ;
}
static int F_379 ( struct V_215 * V_20 ,
struct V_781 * V_782 , bool V_786 )
{
int V_14 = 0 ;
struct V_787 * V_62 = V_782 -> V_62 ;
const char * V_53 = V_782 -> V_53 ;
int V_788 , V_789 ;
F_222 ( ! V_782 ) ;
if ( F_380 ( V_62 ) > 0 ) {
V_788 = V_786 ? V_782 -> V_788 : 0 ;
V_14 = F_381 ( V_62 , V_788 , V_782 -> V_790 ) ;
if ( V_14 ) {
F_7 ( V_20 , L_189 ,
V_21 , V_53 , V_14 ) ;
goto V_154;
}
V_789 = V_786 ? V_782 -> V_706 : 0 ;
V_14 = F_375 ( V_20 , V_782 , V_789 ) ;
if ( V_14 )
goto V_154;
}
V_154:
return V_14 ;
}
static int F_382 ( struct V_215 * V_20 , struct V_781 * V_782 )
{
int V_14 = 0 ;
if ( ! V_782 )
goto V_154;
else if ( V_782 -> V_791 || V_782 -> V_784 )
goto V_154;
V_14 = F_379 ( V_20 , V_782 , true ) ;
if ( ! V_14 )
V_14 = F_383 ( V_782 -> V_62 ) ;
if ( ! V_14 )
V_782 -> V_791 = true ;
else
F_7 ( V_20 , L_190 ,
V_21 , V_782 -> V_53 , V_14 ) ;
V_154:
return V_14 ;
}
static int F_384 ( struct V_215 * V_20 , struct V_781 * V_782 )
{
int V_14 = 0 ;
if ( ! V_782 )
goto V_154;
else if ( ! V_782 -> V_791 || V_782 -> V_784 )
goto V_154;
V_14 = F_385 ( V_782 -> V_62 ) ;
if ( ! V_14 ) {
F_379 ( V_20 , V_782 , false ) ;
V_782 -> V_791 = false ;
} else {
F_7 ( V_20 , L_191 ,
V_21 , V_782 -> V_53 , V_14 ) ;
}
V_154:
return V_14 ;
}
static int F_386 ( struct V_10 * V_11 , bool V_786 )
{
int V_14 = 0 ;
struct V_215 * V_20 = V_11 -> V_20 ;
struct V_792 * V_205 = & V_11 -> V_702 ;
if ( ! V_205 )
goto V_154;
V_14 = F_387 ( V_20 , V_205 -> V_703 , V_786 ) ;
if ( V_14 )
goto V_154;
V_14 = F_387 ( V_20 , V_205 -> V_704 , V_786 ) ;
if ( V_14 )
goto V_154;
V_14 = F_387 ( V_20 , V_205 -> V_705 , V_786 ) ;
if ( V_14 )
goto V_154;
V_154:
if ( V_14 ) {
F_387 ( V_20 , V_205 -> V_705 , false ) ;
F_387 ( V_20 , V_205 -> V_704 , false ) ;
F_387 ( V_20 , V_205 -> V_703 , false ) ;
}
return V_14 ;
}
static int F_388 ( struct V_10 * V_11 , bool V_786 )
{
struct V_792 * V_205 = & V_11 -> V_702 ;
if ( V_205 )
return F_387 ( V_11 -> V_20 , V_205 -> V_793 , V_786 ) ;
return 0 ;
}
static int F_389 ( struct V_215 * V_20 , struct V_781 * V_782 )
{
int V_14 = 0 ;
if ( ! V_782 )
goto V_154;
V_782 -> V_62 = F_390 ( V_20 , V_782 -> V_53 ) ;
if ( F_349 ( V_782 -> V_62 ) ) {
V_14 = F_350 ( V_782 -> V_62 ) ;
F_7 ( V_20 , L_192 ,
V_21 , V_782 -> V_53 , V_14 ) ;
}
V_154:
return V_14 ;
}
static int F_391 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
struct V_215 * V_20 = V_11 -> V_20 ;
struct V_792 * V_205 = & V_11 -> V_702 ;
if ( ! V_205 )
goto V_154;
V_14 = F_389 ( V_20 , V_205 -> V_703 ) ;
if ( V_14 )
goto V_154;
V_14 = F_389 ( V_20 , V_205 -> V_704 ) ;
if ( V_14 )
goto V_154;
V_14 = F_389 ( V_20 , V_205 -> V_705 ) ;
V_154:
return V_14 ;
}
static int F_392 ( struct V_10 * V_11 )
{
struct V_792 * V_205 = & V_11 -> V_702 ;
if ( V_205 )
return F_389 ( V_11 -> V_20 , V_205 -> V_793 ) ;
return 0 ;
}
static int F_367 ( struct V_10 * V_11 , bool V_784 )
{
int V_14 = 0 ;
struct V_792 * V_205 = & V_11 -> V_702 ;
if ( ! V_205 )
goto V_154;
else if ( ! V_205 -> V_704 )
goto V_154;
if ( V_784 ) {
V_14 = F_387 ( V_11 -> V_20 , V_205 -> V_704 , false ) ;
if ( ! V_14 )
V_205 -> V_704 -> V_784 = true ;
} else {
V_205 -> V_704 -> V_784 = false ;
}
V_154:
return V_14 ;
}
static int F_138 ( struct V_10 * V_11 , bool V_786 ,
bool V_794 )
{
int V_14 = 0 ;
struct V_45 * V_46 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
unsigned long V_193 ;
T_4 V_188 = F_72 () ;
bool V_189 = false ;
if ( ! V_48 || F_18 ( V_48 ) )
goto V_154;
V_14 = F_393 ( V_11 , V_786 , V_190 ) ;
if ( V_14 )
return V_14 ;
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) ) {
if ( V_794 && ! strcmp ( V_46 -> V_53 , L_193 ) )
continue;
V_189 = V_786 ^ V_46 -> V_791 ;
if ( V_786 && ! V_46 -> V_791 ) {
V_14 = F_394 ( V_46 -> V_50 ) ;
if ( V_14 ) {
F_7 ( V_11 -> V_20 , L_194 ,
V_21 , V_46 -> V_53 , V_14 ) ;
goto V_154;
}
} else if ( ! V_786 && V_46 -> V_791 ) {
F_395 ( V_46 -> V_50 ) ;
}
V_46 -> V_791 = V_786 ;
F_76 ( V_11 -> V_20 , L_195 , V_21 ,
V_46 -> V_53 , V_786 ? L_196 : L_197 ) ;
}
}
V_14 = F_393 ( V_11 , V_786 , V_191 ) ;
if ( V_14 )
return V_14 ;
V_154:
if ( V_14 ) {
F_19 (clki, head, list) {
if ( ! F_20 ( V_46 -> V_50 ) && V_46 -> V_791 )
F_395 ( V_46 -> V_50 ) ;
}
} else if ( ! V_14 && V_786 ) {
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_11 -> V_114 . V_115 = V_247 ;
F_132 ( F_16 ( V_11 -> V_20 ) ,
V_11 -> V_114 . V_115 ) ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
}
if ( V_189 )
F_396 ( F_16 ( V_11 -> V_20 ) ,
( V_786 ? L_198 : L_199 ) ,
F_22 ( F_79 ( F_72 () , V_188 ) ) , V_14 ) ;
return V_14 ;
}
static int F_124 ( struct V_10 * V_11 , bool V_786 )
{
return F_138 ( V_11 , V_786 , false ) ;
}
static int F_397 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
struct V_45 * V_46 ;
struct V_215 * V_20 = V_11 -> V_20 ;
struct V_47 * V_48 = & V_11 -> V_49 ;
if ( ! V_48 || F_18 ( V_48 ) )
goto V_154;
F_19 (clki, head, list) {
if ( ! V_46 -> V_53 )
continue;
V_46 -> V_50 = F_398 ( V_20 , V_46 -> V_53 ) ;
if ( F_349 ( V_46 -> V_50 ) ) {
V_14 = F_350 ( V_46 -> V_50 ) ;
F_7 ( V_20 , L_200 ,
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
static int F_399 ( struct V_10 * V_11 )
{
int V_134 = 0 ;
if ( ! V_11 -> V_78 )
goto V_154;
V_134 = F_400 ( V_11 ) ;
if ( V_134 )
goto V_154;
V_134 = F_401 ( V_11 , true ) ;
if ( V_134 )
goto V_795;
goto V_154;
V_795:
F_402 ( V_11 ) ;
V_154:
if ( V_134 )
F_7 ( V_11 -> V_20 , L_201 ,
V_21 , F_403 ( V_11 ) , V_134 ) ;
return V_134 ;
}
static void F_404 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_78 )
return;
F_401 ( V_11 , false ) ;
F_402 ( V_11 ) ;
}
static int F_405 ( struct V_10 * V_11 )
{
int V_134 ;
V_134 = F_392 ( V_11 ) ;
if ( V_134 )
goto V_154;
V_134 = F_388 ( V_11 , true ) ;
if ( V_134 )
goto V_154;
V_134 = F_397 ( V_11 ) ;
if ( V_134 )
goto V_796;
V_134 = F_124 ( V_11 , true ) ;
if ( V_134 )
goto V_796;
V_134 = F_391 ( V_11 ) ;
if ( V_134 )
goto V_797;
V_134 = F_386 ( V_11 , true ) ;
if ( V_134 )
goto V_797;
V_134 = F_399 ( V_11 ) ;
if ( V_134 )
goto V_798;
V_11 -> V_799 = true ;
goto V_154;
V_798:
F_386 ( V_11 , false ) ;
V_797:
F_124 ( V_11 , false ) ;
V_796:
F_388 ( V_11 , false ) ;
V_154:
return V_134 ;
}
static void F_371 ( struct V_10 * V_11 )
{
if ( V_11 -> V_799 ) {
F_404 ( V_11 ) ;
F_386 ( V_11 , false ) ;
F_111 ( V_11 ) ;
if ( F_105 ( V_11 ) ) {
if ( V_11 -> V_214 )
F_111 ( V_11 ) ;
F_406 ( V_11 -> V_203 . V_220 ) ;
}
F_124 ( V_11 , false ) ;
F_388 ( V_11 , false ) ;
V_11 -> V_799 = false ;
}
}
static int
F_407 ( struct V_10 * V_11 , struct V_555 * V_800 )
{
unsigned char V_32 [ 6 ] = { V_801 ,
0 ,
0 ,
0 ,
V_270 ,
0 } ;
char * V_802 ;
int V_14 ;
V_802 = F_408 ( V_270 , V_448 ) ;
if ( ! V_802 ) {
V_14 = - V_449 ;
goto V_154;
}
V_14 = F_409 ( V_800 , V_32 , V_327 , V_802 ,
V_270 , NULL , NULL ,
F_32 ( 1000 ) , 3 , 0 , V_803 , NULL ) ;
if ( V_14 )
F_343 ( L_161 , V_21 , V_14 ) ;
F_232 ( V_802 ) ;
V_154:
return V_14 ;
}
static int F_410 ( struct V_10 * V_11 ,
enum V_1 V_526 )
{
unsigned char V_32 [ 6 ] = { V_804 } ;
struct V_805 V_806 ;
struct V_555 * V_800 ;
unsigned long V_193 ;
int V_14 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
V_800 = V_11 -> V_575 ;
if ( V_800 ) {
V_14 = F_411 ( V_800 ) ;
if ( ! V_14 && ! F_412 ( V_800 ) ) {
V_14 = - V_807 ;
F_351 ( V_800 ) ;
}
} else {
V_14 = - V_807 ;
}
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_14 )
return V_14 ;
V_11 -> V_112 -> V_808 = 1 ;
if ( V_11 -> V_770 ) {
V_14 = F_407 ( V_11 , V_800 ) ;
if ( V_14 )
goto V_154;
V_11 -> V_770 = false ;
}
V_32 [ 4 ] = V_526 << 4 ;
V_14 = F_409 ( V_800 , V_32 , V_355 , NULL , 0 , NULL , & V_806 ,
V_809 , 0 , 0 , V_803 , NULL ) ;
if ( V_14 ) {
F_413 ( V_810 , V_800 ,
L_202 ,
V_526 , V_14 ) ;
if ( F_414 ( V_14 ) & V_811 )
F_415 ( V_800 , NULL , & V_806 ) ;
}
if ( ! V_14 )
V_11 -> V_108 = V_526 ;
V_154:
F_351 ( V_800 ) ;
V_11 -> V_112 -> V_808 = 0 ;
return V_14 ;
}
static int F_416 ( struct V_10 * V_11 ,
enum V_6 V_812 ,
int V_813 )
{
int V_14 = 0 ;
if ( V_812 == V_11 -> V_6 )
return 0 ;
if ( V_812 == V_181 ) {
V_14 = F_135 ( V_11 ) ;
if ( ! V_14 )
F_136 ( V_11 ) ;
else
goto V_154;
}
else if ( ( V_812 == V_179 ) &&
( ! V_813 || ( V_813 &&
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
static void F_417 ( struct V_10 * V_11 )
{
if ( ! F_137 ( V_11 ) &&
V_11 -> V_120 & V_814 )
F_33 ( 2000 , 2100 ) ;
if ( F_418 ( V_11 ) && F_419 ( V_11 ) &&
! V_11 -> V_562 . V_564 ) {
F_386 ( V_11 , false ) ;
} else if ( ! F_280 ( V_11 ) ) {
F_387 ( V_11 -> V_20 , V_11 -> V_702 . V_703 , false ) ;
if ( ! F_137 ( V_11 ) ) {
F_377 ( V_11 , V_11 -> V_702 . V_704 ) ;
F_377 ( V_11 , V_11 -> V_702 . V_705 ) ;
}
}
}
static int F_420 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
if ( F_418 ( V_11 ) && F_419 ( V_11 ) &&
! V_11 -> V_562 . V_564 ) {
V_14 = F_386 ( V_11 , true ) ;
} else if ( ! F_280 ( V_11 ) ) {
if ( ! V_14 && ! F_137 ( V_11 ) ) {
V_14 = F_378 ( V_11 , V_11 -> V_702 . V_704 ) ;
if ( V_14 )
goto V_815;
V_14 = F_378 ( V_11 , V_11 -> V_702 . V_705 ) ;
if ( V_14 )
goto V_816;
}
V_14 = F_387 ( V_11 -> V_20 , V_11 -> V_702 . V_703 , true ) ;
}
goto V_154;
V_816:
F_377 ( V_11 , V_11 -> V_702 . V_704 ) ;
V_815:
F_387 ( V_11 -> V_20 , V_11 -> V_702 . V_703 , false ) ;
V_154:
return V_14 ;
}
static void F_421 ( struct V_10 * V_11 )
{
if ( F_419 ( V_11 ) )
F_388 ( V_11 , false ) ;
}
static void F_422 ( struct V_10 * V_11 )
{
if ( F_419 ( V_11 ) )
F_388 ( V_11 , true ) ;
}
static int F_423 ( struct V_10 * V_11 , enum V_817 V_818 )
{
int V_14 = 0 ;
enum V_2 V_819 ;
enum V_1 V_820 ;
enum V_6 V_812 ;
V_11 -> V_109 = 1 ;
if ( ! F_424 ( V_818 ) ) {
V_819 = F_425 ( V_818 ) ?
V_11 -> V_821 : V_11 -> V_822 ;
V_820 = F_1 ( V_819 ) ;
V_812 = F_2 ( V_819 ) ;
} else {
V_820 = V_184 ;
V_812 = V_179 ;
}
F_82 ( V_11 , false ) ;
V_11 -> V_114 . V_212 = true ;
if ( V_11 -> V_203 . V_238 ) {
F_117 ( & V_11 -> V_203 . V_209 ) ;
F_117 ( & V_11 -> V_203 . V_213 ) ;
F_111 ( V_11 ) ;
}
if ( V_820 == V_182 &&
V_812 == V_180 ) {
goto V_823;
}
if ( ( V_820 == V_11 -> V_108 ) &&
( V_812 == V_11 -> V_6 ) )
goto V_824;
if ( ! F_280 ( V_11 ) || ! F_137 ( V_11 ) ) {
V_14 = - V_218 ;
goto V_824;
}
if ( F_425 ( V_818 ) ) {
if ( F_426 ( V_11 ) ) {
V_14 = F_310 ( V_11 ) ;
if ( V_14 )
goto V_824;
} else {
F_305 ( V_11 ) ;
}
}
if ( ( V_820 != V_11 -> V_108 ) &&
( ( F_425 ( V_818 ) && ! V_11 -> V_111 ) ||
! F_425 ( V_818 ) ) ) {
F_305 ( V_11 ) ;
V_14 = F_410 ( V_11 , V_820 ) ;
if ( V_14 )
goto V_824;
}
V_14 = F_416 ( V_11 , V_812 , 1 ) ;
if ( V_14 )
goto V_825;
F_417 ( V_11 ) ;
V_823:
V_14 = F_427 ( V_11 , V_818 ) ;
if ( V_14 )
goto V_826;
if ( ! F_137 ( V_11 ) )
F_124 ( V_11 , false ) ;
else
F_138 ( V_11 , false , true ) ;
V_11 -> V_114 . V_115 = V_252 ;
F_132 ( F_16 ( V_11 -> V_20 ) , V_11 -> V_114 . V_115 ) ;
F_8 ( V_11 ) ;
F_421 ( V_11 ) ;
goto V_154;
V_826:
if ( V_11 -> V_203 . V_238 )
F_112 ( V_11 ) ;
F_420 ( V_11 ) ;
if ( F_126 ( V_11 ) && ! F_127 ( V_11 ) )
F_128 ( V_11 ) ;
else if ( F_419 ( V_11 ) )
F_257 ( V_11 ) ;
V_825:
if ( ! F_410 ( V_11 , V_182 ) )
F_305 ( V_11 ) ;
V_824:
if ( V_11 -> V_203 . V_238 )
F_112 ( V_11 ) ;
V_11 -> V_114 . V_212 = false ;
F_86 ( V_11 ) ;
V_154:
V_11 -> V_109 = 0 ;
return V_14 ;
}
static int F_428 ( struct V_10 * V_11 , enum V_817 V_818 )
{
int V_14 ;
enum V_6 V_827 ;
V_11 -> V_109 = 1 ;
V_827 = V_11 -> V_6 ;
F_422 ( V_11 ) ;
V_14 = F_124 ( V_11 , true ) ;
if ( V_14 )
goto V_154;
V_14 = F_5 ( V_11 ) ;
if ( V_14 )
goto V_828;
V_14 = F_420 ( V_11 ) ;
if ( V_14 )
goto V_828;
V_14 = F_429 ( V_11 , V_818 ) ;
if ( V_14 )
goto V_829;
if ( F_126 ( V_11 ) ) {
V_14 = F_127 ( V_11 ) ;
if ( ! V_14 )
F_128 ( V_11 ) ;
else
goto V_830;
} else if ( F_419 ( V_11 ) ) {
V_14 = F_257 ( V_11 ) ;
if ( V_14 || ! F_137 ( V_11 ) )
goto V_830;
}
if ( ! F_280 ( V_11 ) ) {
V_14 = F_410 ( V_11 , V_182 ) ;
if ( V_14 )
goto V_831;
}
if ( F_307 ( V_11 ) )
F_303 ( V_11 ) ;
else
F_310 ( V_11 ) ;
V_11 -> V_114 . V_212 = false ;
if ( V_11 -> V_203 . V_238 )
F_112 ( V_11 ) ;
F_86 ( V_11 ) ;
goto V_154;
V_831:
F_416 ( V_11 , V_827 , 0 ) ;
V_830:
F_427 ( V_11 , V_818 ) ;
V_829:
F_417 ( V_11 ) ;
V_828:
F_8 ( V_11 ) ;
if ( V_11 -> V_203 . V_238 )
F_111 ( V_11 ) ;
F_124 ( V_11 , false ) ;
V_154:
V_11 -> V_109 = 0 ;
return V_14 ;
}
int F_430 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_4 V_188 = F_72 () ;
if ( ! V_11 || ! V_11 -> V_799 )
return 0 ;
if ( ( F_1 ( V_11 -> V_822 ) ==
V_11 -> V_108 ) &&
( F_2 ( V_11 -> V_822 ) ==
V_11 -> V_6 ) )
goto V_154;
if ( F_431 ( V_11 -> V_20 ) ) {
V_14 = F_432 ( V_11 ) ;
if ( V_14 )
goto V_154;
}
V_14 = F_423 ( V_11 , V_832 ) ;
V_154:
F_433 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_188 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
if ( ! V_14 )
V_11 -> V_110 = true ;
return V_14 ;
}
int F_434 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_4 V_188 = F_72 () ;
if ( ! V_11 )
return - V_218 ;
if ( ! V_11 -> V_799 || F_431 ( V_11 -> V_20 ) )
goto V_154;
else
V_14 = F_428 ( V_11 , V_832 ) ;
V_154:
F_435 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_188 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
return V_14 ;
}
int F_436 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_4 V_188 = F_72 () ;
if ( ! V_11 )
return - V_218 ;
if ( ! V_11 -> V_799 )
goto V_154;
else
V_14 = F_423 ( V_11 , V_833 ) ;
V_154:
F_437 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_188 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
return V_14 ;
}
int F_432 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
T_4 V_188 = F_72 () ;
if ( ! V_11 )
return - V_218 ;
if ( ! V_11 -> V_799 )
goto V_154;
else
V_14 = F_428 ( V_11 , V_833 ) ;
V_154:
F_438 ( F_16 ( V_11 -> V_20 ) , V_14 ,
F_22 ( F_79 ( F_72 () , V_188 ) ) ,
V_11 -> V_108 , V_11 -> V_6 ) ;
return V_14 ;
}
int F_439 ( struct V_10 * V_11 )
{
return 0 ;
}
static inline T_5 F_440 ( struct V_215 * V_20 ,
struct V_234 * V_235 ,
const char * V_236 , T_6 V_239 ,
bool V_834 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
unsigned long V_193 , V_240 ;
if ( F_143 ( V_236 , 0 , & V_240 ) )
return - V_218 ;
if ( V_240 >= V_9 )
return - V_218 ;
F_83 ( V_11 -> V_112 -> V_197 , V_193 ) ;
if ( V_834 )
V_11 -> V_821 = V_240 ;
else
V_11 -> V_822 = V_240 ;
F_84 ( V_11 -> V_112 -> V_197 , V_193 ) ;
return V_239 ;
}
static T_5 F_441 ( struct V_215 * V_20 ,
struct V_234 * V_235 , char * V_236 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
int V_835 ;
T_2 V_3 ;
V_835 = snprintf ( V_236 , V_237 ,
L_203 ,
V_11 -> V_821 ,
F_68 (
V_4 [ V_11 -> V_821 ] . V_5 ) ,
F_67 (
V_4 [ V_11 -> V_821 ] . V_7 ) ) ;
V_835 += snprintf ( ( V_236 + V_835 ) , ( V_237 - V_835 ) ,
L_204 ) ;
for ( V_3 = V_8 ; V_3 < V_9 ; V_3 ++ )
V_835 += snprintf ( ( V_236 + V_835 ) , ( V_237 - V_835 ) ,
L_205 ,
V_3 ,
F_68 (
V_4 [ V_3 ] . V_5 ) ,
F_67 (
V_4 [ V_3 ] . V_7 ) ) ;
return V_835 ;
}
static T_5 F_442 ( struct V_215 * V_20 ,
struct V_234 * V_235 , const char * V_236 , T_6 V_239 )
{
return F_440 ( V_20 , V_235 , V_236 , V_239 , true ) ;
}
static void F_443 ( struct V_10 * V_11 )
{
V_11 -> V_836 . V_242 = F_441 ;
V_11 -> V_836 . V_243 = F_442 ;
F_120 ( & V_11 -> V_836 . V_235 ) ;
V_11 -> V_836 . V_235 . V_53 = L_206 ;
V_11 -> V_836 . V_235 . V_244 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_836 ) )
F_7 ( V_11 -> V_20 , L_207 ) ;
}
static T_5 F_444 ( struct V_215 * V_20 ,
struct V_234 * V_235 , char * V_236 )
{
struct V_10 * V_11 = F_104 ( V_20 ) ;
int V_835 ;
T_2 V_3 ;
V_835 = snprintf ( V_236 , V_237 ,
L_208 ,
V_11 -> V_822 ,
F_68 (
V_4 [ V_11 -> V_822 ] . V_5 ) ,
F_67 (
V_4 [ V_11 -> V_822 ] . V_7 ) ) ;
V_835 += snprintf ( ( V_236 + V_835 ) , ( V_237 - V_835 ) ,
L_209 ) ;
for ( V_3 = V_8 ; V_3 < V_9 ; V_3 ++ )
V_835 += snprintf ( ( V_236 + V_835 ) , ( V_237 - V_835 ) ,
L_210 ,
V_3 ,
F_68 (
V_4 [ V_3 ] . V_5 ) ,
F_67 (
V_4 [ V_3 ] . V_7 ) ) ;
return V_835 ;
}
static T_5 F_445 ( struct V_215 * V_20 ,
struct V_234 * V_235 , const char * V_236 , T_6 V_239 )
{
return F_440 ( V_20 , V_235 , V_236 , V_239 , false ) ;
}
static void F_446 ( struct V_10 * V_11 )
{
V_11 -> V_837 . V_242 = F_444 ;
V_11 -> V_837 . V_243 = F_445 ;
F_120 ( & V_11 -> V_837 . V_235 ) ;
V_11 -> V_837 . V_235 . V_53 = L_211 ;
V_11 -> V_837 . V_235 . V_244 = 0644 ;
if ( F_121 ( V_11 -> V_20 , & V_11 -> V_837 ) )
F_7 ( V_11 -> V_20 , L_212 ) ;
}
static inline void F_447 ( struct V_10 * V_11 )
{
F_443 ( V_11 ) ;
F_446 ( V_11 ) ;
}
int F_448 ( struct V_10 * V_11 )
{
int V_14 = 0 ;
if ( F_418 ( V_11 ) && F_419 ( V_11 ) )
goto V_154;
if ( F_431 ( V_11 -> V_20 ) ) {
V_14 = F_432 ( V_11 ) ;
if ( V_14 )
goto V_154;
}
V_14 = F_423 ( V_11 , V_838 ) ;
V_154:
if ( V_14 )
F_7 ( V_11 -> V_20 , L_213 , V_21 , V_14 ) ;
return 0 ;
}
void F_449 ( struct V_10 * V_11 )
{
F_450 ( V_11 -> V_112 ) ;
F_184 ( V_11 , V_11 -> V_138 ) ;
F_270 ( V_11 , true ) ;
F_149 ( V_11 ) ;
if ( F_105 ( V_11 ) )
F_150 ( V_11 -> V_20 , & V_11 -> V_203 . V_241 ) ;
F_371 ( V_11 ) ;
}
void F_451 ( struct V_10 * V_11 )
{
F_452 ( V_11 -> V_112 ) ;
}
static int F_453 ( struct V_10 * V_11 )
{
if ( V_11 -> V_67 & V_839 ) {
if ( ! F_454 ( V_11 -> V_20 , F_455 ( 64 ) ) )
return 0 ;
}
return F_454 ( V_11 -> V_20 , F_455 ( 32 ) ) ;
}
int F_456 ( struct V_215 * V_20 , struct V_10 * * V_840 )
{
struct V_365 * V_112 ;
struct V_10 * V_11 ;
int V_134 = 0 ;
if ( ! V_20 ) {
F_7 ( V_20 ,
L_214 ) ;
V_134 = - V_807 ;
goto V_841;
}
V_112 = F_457 ( & V_842 ,
sizeof( struct V_10 ) ) ;
if ( ! V_112 ) {
F_7 ( V_20 , L_215 ) ;
V_134 = - V_449 ;
goto V_841;
}
V_11 = F_197 ( V_112 ) ;
V_11 -> V_112 = V_112 ;
V_11 -> V_20 = V_20 ;
* V_840 = V_11 ;
V_841:
return V_134 ;
}
int F_458 ( struct V_10 * V_11 , void T_11 * V_64 , unsigned int V_16 )
{
int V_134 ;
struct V_365 * V_112 = V_11 -> V_112 ;
struct V_215 * V_20 = V_11 -> V_20 ;
if ( ! V_64 ) {
F_7 ( V_11 -> V_20 ,
L_216 ) ;
V_134 = - V_807 ;
goto V_841;
}
V_11 -> V_64 = V_64 ;
V_11 -> V_16 = V_16 ;
F_366 ( V_11 ) ;
V_134 = F_405 ( V_11 ) ;
if ( V_134 )
goto V_841;
F_162 ( V_11 ) ;
V_11 -> V_66 = F_37 ( V_11 ) ;
if ( ( V_11 -> V_66 != V_139 ) &&
( V_11 -> V_66 != V_141 ) &&
( V_11 -> V_66 != V_142 ) &&
( V_11 -> V_66 != V_144 ) )
F_7 ( V_11 -> V_20 , L_217 ,
V_11 -> V_66 ) ;
V_11 -> V_138 = F_36 ( V_11 ) ;
V_134 = F_453 ( V_11 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_218 ) ;
goto V_843;
}
V_134 = F_239 ( V_11 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_219 ) ;
goto V_843;
}
F_242 ( V_11 ) ;
V_112 -> V_844 = V_11 -> V_13 ;
V_112 -> V_845 = V_11 -> V_13 ;
V_112 -> V_846 = V_847 ;
V_112 -> V_848 = V_849 ;
V_112 -> V_850 = V_851 ;
V_112 -> V_852 = V_112 -> V_853 ;
V_112 -> V_854 = V_347 ;
V_11 -> V_519 . V_520 = false ;
F_459 ( & V_11 -> V_657 ) ;
F_459 ( & V_11 -> V_673 ) ;
F_148 ( & V_11 -> V_632 , F_317 ) ;
F_148 ( & V_11 -> V_595 , F_313 ) ;
F_460 ( & V_11 -> V_305 ) ;
F_460 ( & V_11 -> V_273 . V_402 ) ;
F_461 ( & V_11 -> V_206 ) ;
F_459 ( & V_11 -> V_273 . V_390 ) ;
F_146 ( V_11 ) ;
F_49 ( V_11 , F_14 ( V_11 , V_43 ) ,
V_43 ) ;
F_49 ( V_11 , 0 , V_319 ) ;
F_462 () ;
V_134 = F_463 ( V_20 , V_16 , V_17 , V_18 , V_19 , V_11 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_220 ) ;
goto V_855;
} else {
V_11 -> V_15 = true ;
}
V_134 = F_464 ( V_112 , V_11 -> V_20 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_221 ) ;
goto V_855;
}
V_134 = F_271 ( V_11 ) ;
if ( V_134 ) {
F_7 ( V_11 -> V_20 , L_222 ) ;
F_23 ( V_11 ) ;
F_29 ( V_11 ) ;
goto V_856;
}
if ( F_105 ( V_11 ) ) {
char V_857 [ sizeof( L_223 ) ] ;
F_148 ( & V_11 -> V_203 . V_209 ,
F_98 ) ;
F_148 ( & V_11 -> V_203 . V_213 ,
F_101 ) ;
snprintf ( V_857 , F_465 ( V_857 ) , L_224 ,
V_112 -> V_853 ) ;
V_11 -> V_203 . V_220 = F_466 ( V_857 ) ;
F_119 ( V_11 ) ;
}
V_11 -> V_821 = F_3 (
V_183 ,
V_181 ) ;
V_11 -> V_822 = F_3 (
V_183 ,
V_181 ) ;
F_116 ( V_20 ) ;
F_368 ( V_11 ) ;
F_467 ( F_373 , V_11 ) ;
F_447 ( V_11 ) ;
return 0 ;
V_856:
F_450 ( V_11 -> V_112 ) ;
V_855:
F_149 ( V_11 ) ;
V_843:
V_11 -> V_15 = false ;
F_371 ( V_11 ) ;
V_841:
return V_134 ;
}
