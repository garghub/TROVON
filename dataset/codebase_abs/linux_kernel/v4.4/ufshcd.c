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
static inline int F_3 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( ! V_9 -> V_11 ) {
V_10 = F_4 ( V_9 -> V_12 , V_13 , V_14 , V_15 ,
V_9 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_1 ,
V_17 , V_10 ) ;
V_9 -> V_11 = true ;
}
return V_10 ;
}
static inline void F_6 ( struct V_8 * V_9 )
{
if ( V_9 -> V_11 ) {
F_7 ( V_9 -> V_12 , V_9 ) ;
V_9 -> V_11 = false ;
}
}
static int F_8 ( struct V_8 * V_9 , T_1 V_18 , T_1 V_19 ,
T_1 V_20 , unsigned long V_21 , unsigned long V_22 )
{
int V_23 = 0 ;
unsigned long V_24 = V_25 + F_9 ( V_22 ) ;
V_20 = V_20 & V_19 ;
while ( ( F_10 ( V_9 , V_18 ) & V_19 ) != V_20 ) {
F_11 ( V_21 , V_21 + 50 ) ;
if ( F_12 ( V_25 , V_24 ) ) {
if ( ( F_10 ( V_9 , V_18 ) & V_19 ) != V_20 )
V_23 = - V_26 ;
break;
}
}
return V_23 ;
}
static inline T_1 F_13 ( struct V_8 * V_9 )
{
if ( V_9 -> V_27 == V_28 )
return V_29 ;
else
return V_30 ;
}
static inline T_1 F_14 ( struct V_8 * V_9 )
{
if ( V_9 -> V_31 & V_32 )
return F_15 ( V_9 ) ;
return F_10 ( V_9 , V_33 ) ;
}
static inline int F_16 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_34 ) &
V_35 ) ? 1 : 0 ;
}
static inline int F_17 ( struct V_36 * V_37 )
{
return F_18 ( V_37 -> V_38 -> V_39 . V_40 ) & V_41 ;
}
static inline int
F_19 ( struct V_42 * V_43 )
{
return F_18 ( V_43 -> V_39 . V_40 ) & V_41 ;
}
static bool F_20 ( struct V_8 * V_9 , int * V_44 )
{
int V_45 ;
bool V_10 = false ;
if ( ! V_44 )
goto V_46;
do {
V_45 = F_21 ( & V_9 -> V_47 , V_9 -> V_48 ) ;
if ( V_45 >= V_9 -> V_48 )
goto V_46;
} while ( F_22 ( V_45 , & V_9 -> V_47 ) );
* V_44 = V_45 ;
V_10 = true ;
V_46:
return V_10 ;
}
static inline void F_23 ( struct V_8 * V_9 , int V_49 )
{
F_24 ( V_49 , & V_9 -> V_47 ) ;
}
static inline void F_25 ( struct V_8 * V_9 , T_1 V_50 )
{
F_26 ( V_9 , ~ ( 1 << V_50 ) , V_51 ) ;
}
static inline int F_27 ( T_1 V_18 )
{
return ( ( ( V_18 ) & ( 0xFF ) ) >> 1 ) ^ ( 0x07 ) ;
}
static inline int F_28 ( struct V_8 * V_9 )
{
return F_10 ( V_9 , V_52 ) &
V_53 ;
}
static inline T_1 F_29 ( struct V_8 * V_9 )
{
return F_10 ( V_9 , V_54 ) ;
}
static inline int
F_30 ( struct V_55 * V_56 )
{
return F_31 ( V_56 -> V_39 . V_57 ) >> 24 ;
}
static inline int
F_32 ( struct V_55 * V_56 )
{
return F_31 ( V_56 -> V_39 . V_58 ) & V_59 ;
}
static inline unsigned int
F_33 ( struct V_55 * V_56 )
{
return F_31 ( V_56 -> V_39 . V_40 ) &
V_60 ;
}
static inline bool F_34 ( struct V_55 * V_56 )
{
return F_31 ( V_56 -> V_39 . V_40 ) &
V_61 ? true : false ;
}
static inline void
F_35 ( struct V_8 * V_9 )
{
F_26 ( V_9 , V_62 |
V_63 ,
V_64 ) ;
}
static inline void
F_36 ( struct V_8 * V_9 , T_2 V_65 , T_2 V_66 )
{
F_26 ( V_9 , V_62 | V_67 |
F_37 ( V_65 ) |
F_38 ( V_66 ) ,
V_64 ) ;
}
static inline void F_39 ( struct V_8 * V_9 )
{
F_26 ( V_9 , 0 , V_64 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
F_26 ( V_9 , V_68 ,
V_69 ) ;
F_26 ( V_9 , V_70 ,
V_71 ) ;
}
static inline void F_41 ( struct V_8 * V_9 )
{
F_26 ( V_9 , V_72 , V_73 ) ;
}
static inline int F_42 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_73 ) & 0x1 ) ? 0 : 1 ;
}
static void F_43 ( struct V_74 * V_75 )
{
int V_10 ;
unsigned long V_76 ;
struct V_8 * V_9 = F_44 ( V_75 , struct V_8 ,
V_77 . V_78 ) ;
F_45 ( & V_9 -> V_77 . V_79 ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( V_9 -> V_77 . V_82 == V_83 ) {
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
goto V_84;
}
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_48 ( V_9 , true ) ;
if ( F_49 ( V_9 ) ) {
V_9 -> V_77 . V_85 = true ;
if ( F_50 ( V_9 ) ) {
V_10 = F_51 ( V_9 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_2 ,
V_17 , V_10 ) ;
else
F_52 ( V_9 ) ;
}
V_9 -> V_77 . V_85 = false ;
}
V_84:
if ( F_53 ( V_9 ) )
F_54 ( V_9 -> V_86 ) ;
F_55 ( V_9 -> V_80 ) ;
}
int F_56 ( struct V_8 * V_9 , bool V_87 )
{
int V_88 = 0 ;
unsigned long V_76 ;
if ( ! F_57 ( V_9 ) )
goto V_46;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_9 -> V_77 . V_89 ++ ;
V_90:
switch ( V_9 -> V_77 . V_82 ) {
case V_83 :
break;
case V_91 :
if ( F_58 ( & V_9 -> V_77 . V_79 ) ) {
V_9 -> V_77 . V_82 = V_83 ;
break;
}
case V_92 :
F_59 ( V_9 -> V_80 ) ;
V_9 -> V_77 . V_82 = V_93 ;
F_60 ( & V_9 -> V_77 . V_78 ) ;
case V_93 :
if ( V_87 ) {
V_88 = - V_94 ;
V_9 -> V_77 . V_89 -- ;
break;
}
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_61 ( & V_9 -> V_77 . V_78 ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
goto V_90;
default:
F_5 ( V_9 -> V_16 , L_3 ,
V_17 , V_9 -> V_77 . V_82 ) ;
break;
}
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_46:
return V_88 ;
}
static void F_62 ( struct V_74 * V_75 )
{
struct V_8 * V_9 = F_44 ( V_75 , struct V_8 ,
V_77 . V_79 . V_75 ) ;
unsigned long V_76 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( V_9 -> V_77 . V_85 ) {
V_9 -> V_77 . V_82 = V_83 ;
goto V_95;
}
if ( V_9 -> V_77 . V_89
|| V_9 -> V_96 != V_97
|| V_9 -> V_98 || V_9 -> V_99
|| V_9 -> V_100 || V_9 -> V_101 )
goto V_95;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( F_49 ( V_9 ) ) {
if ( F_63 ( V_9 ) ) {
V_9 -> V_77 . V_82 = V_83 ;
goto V_46;
}
F_64 ( V_9 ) ;
}
if ( F_53 ( V_9 ) ) {
F_65 ( V_9 -> V_86 ) ;
V_9 -> V_102 . V_103 = 0 ;
}
if ( ! F_66 ( V_9 ) )
F_48 ( V_9 , false ) ;
else
F_67 ( V_9 , false , true ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( V_9 -> V_77 . V_82 == V_91 )
V_9 -> V_77 . V_82 = V_92 ;
V_95:
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_46:
return;
}
static void F_68 ( struct V_8 * V_9 )
{
if ( ! F_57 ( V_9 ) )
return;
V_9 -> V_77 . V_89 -- ;
if ( V_9 -> V_77 . V_89 || V_9 -> V_77 . V_85
|| V_9 -> V_96 != V_97
|| V_9 -> V_98 || V_9 -> V_99
|| V_9 -> V_100 || V_9 -> V_101 )
return;
V_9 -> V_77 . V_82 = V_91 ;
F_69 ( & V_9 -> V_77 . V_79 ,
F_9 ( V_9 -> V_77 . V_104 ) ) ;
}
void F_70 ( struct V_8 * V_9 )
{
unsigned long V_76 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_68 ( V_9 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
}
static T_3 F_71 ( struct V_105 * V_16 ,
struct V_106 * V_107 , char * V_108 )
{
struct V_8 * V_9 = F_72 ( V_16 ) ;
return snprintf ( V_108 , V_109 , L_4 , V_9 -> V_77 . V_104 ) ;
}
static T_3 F_73 ( struct V_105 * V_16 ,
struct V_106 * V_107 , const char * V_108 , T_4 V_110 )
{
struct V_8 * V_9 = F_72 ( V_16 ) ;
unsigned long V_76 , V_111 ;
if ( F_74 ( V_108 , 0 , & V_111 ) )
return - V_112 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_9 -> V_77 . V_104 = V_111 ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
return V_110 ;
}
static void F_75 ( struct V_8 * V_9 )
{
if ( ! F_57 ( V_9 ) )
return;
V_9 -> V_77 . V_104 = 150 ;
F_76 ( & V_9 -> V_77 . V_79 , F_62 ) ;
F_77 ( & V_9 -> V_77 . V_78 , F_43 ) ;
V_9 -> V_77 . V_113 . V_114 = F_71 ;
V_9 -> V_77 . V_113 . V_115 = F_73 ;
F_78 ( & V_9 -> V_77 . V_113 . V_107 ) ;
V_9 -> V_77 . V_113 . V_107 . V_116 = L_5 ;
V_9 -> V_77 . V_113 . V_107 . V_117 = V_118 | V_119 ;
if ( F_79 ( V_9 -> V_16 , & V_9 -> V_77 . V_113 ) )
F_5 ( V_9 -> V_16 , L_6 ) ;
}
static void F_80 ( struct V_8 * V_9 )
{
if ( ! F_57 ( V_9 ) )
return;
F_81 ( V_9 -> V_16 , & V_9 -> V_77 . V_113 ) ;
F_82 ( & V_9 -> V_77 . V_78 ) ;
F_45 ( & V_9 -> V_77 . V_79 ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
if ( ! F_53 ( V_9 ) )
return;
if ( ! V_9 -> V_102 . V_120 ) {
V_9 -> V_102 . V_121 = F_84 () ;
V_9 -> V_102 . V_120 = true ;
}
}
static void F_85 ( struct V_8 * V_9 )
{
struct V_122 * V_123 = & V_9 -> V_102 ;
if ( ! F_53 ( V_9 ) )
return;
if ( ! V_9 -> V_124 && V_123 -> V_120 ) {
V_123 -> V_125 += F_86 ( F_87 ( F_84 () ,
V_123 -> V_121 ) ) ;
V_123 -> V_121 = F_88 ( 0 , 0 ) ;
V_123 -> V_120 = false ;
}
}
static inline
void F_89 ( struct V_8 * V_9 , unsigned int V_126 )
{
F_83 ( V_9 ) ;
F_90 ( V_126 , & V_9 -> V_124 ) ;
F_26 ( V_9 , 1 << V_126 , V_127 ) ;
}
static inline void F_91 ( struct V_36 * V_37 )
{
int V_128 ;
if ( V_37 -> V_129 &&
F_33 ( V_37 -> V_56 ) ) {
V_128 = F_92 ( V_37 -> V_56 -> V_130 . V_131 ) ;
memcpy ( V_37 -> V_129 ,
V_37 -> V_56 -> V_130 . V_132 ,
F_93 ( int , V_128 , V_133 ) ) ;
}
}
static
int F_94 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
struct V_134 * V_135 = & V_9 -> V_136 . V_137 . V_138 ;
memcpy ( & V_135 -> V_139 , & V_37 -> V_56 -> V_140 , V_141 ) ;
if ( V_37 -> V_56 -> V_140 . V_142 == V_143 ) {
T_2 * V_144 = ( T_2 * ) V_37 -> V_56 +
V_145 ;
T_5 V_146 ;
T_5 V_147 ;
V_146 = F_31 ( V_37 -> V_56 -> V_39 . V_40 ) &
V_148 ;
V_147 = F_92 (
V_9 -> V_136 . V_137 . V_149 . V_150 . V_151 ) ;
if ( F_95 ( V_147 >= V_146 ) ) {
memcpy ( V_9 -> V_136 . V_137 . V_152 , V_144 , V_146 ) ;
} else {
F_96 ( V_9 -> V_16 ,
L_7 ,
V_17 ) ;
return - V_112 ;
}
}
return 0 ;
}
static inline void F_97 ( struct V_8 * V_9 )
{
V_9 -> V_153 = F_10 ( V_9 , V_154 ) ;
V_9 -> V_155 = ( V_9 -> V_153 & V_156 ) + 1 ;
V_9 -> V_48 =
( ( V_9 -> V_153 & V_157 ) >> 16 ) + 1 ;
}
static inline bool F_98 ( struct V_8 * V_9 )
{
if ( F_10 ( V_9 , V_34 ) & V_158 )
return true ;
else
return false ;
}
static inline T_2 F_99 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_34 ) >> 8 ) & 0x7 ;
}
static inline void
F_100 ( struct V_8 * V_9 , struct V_159 * V_160 )
{
F_101 ( V_9 -> V_100 ) ;
V_9 -> V_100 = V_160 ;
F_26 ( V_9 , V_160 -> V_161 , V_162 ) ;
F_26 ( V_9 , V_160 -> V_163 , V_52 ) ;
F_26 ( V_9 , V_160 -> V_164 , V_54 ) ;
F_26 ( V_9 , V_160 -> V_165 & V_166 ,
V_167 ) ;
}
static int
F_102 ( struct V_8 * V_9 , struct V_159 * V_160 )
{
int V_10 ;
unsigned long V_76 ;
if ( F_103 ( & V_160 -> V_168 ,
F_9 ( V_169 ) ) )
V_10 = V_160 -> V_163 & V_53 ;
else
V_10 = - V_26 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_9 -> V_100 = NULL ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
return V_10 ;
}
static int
F_104 ( struct V_8 * V_9 , struct V_159 * V_160 )
{
if ( ! F_98 ( V_9 ) ) {
F_5 ( V_9 -> V_16 ,
L_8 ) ;
return - V_170 ;
}
F_105 ( & V_160 -> V_168 ) ;
F_100 ( V_9 , V_160 ) ;
return 0 ;
}
static int
F_106 ( struct V_8 * V_9 , struct V_159 * V_160 )
{
int V_10 ;
unsigned long V_76 ;
F_56 ( V_9 , false ) ;
F_107 ( & V_9 -> V_171 ) ;
F_108 ( V_9 ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_10 = F_104 ( V_9 , V_160 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( ! V_10 )
V_10 = F_102 ( V_9 , V_160 ) ;
F_109 ( & V_9 -> V_171 ) ;
F_70 ( V_9 ) ;
return V_10 ;
}
static int F_110 ( struct V_36 * V_37 )
{
struct V_172 * V_173 ;
struct V_174 * V_175 ;
struct V_176 * V_177 ;
int V_178 ;
int V_179 ;
V_177 = V_37 -> V_177 ;
V_178 = F_111 ( V_177 ) ;
if ( V_178 < 0 )
return V_178 ;
if ( V_178 ) {
V_37 -> V_38 -> V_180 =
F_112 ( ( T_5 ) ( V_178 ) ) ;
V_173 = (struct V_172 * ) V_37 -> V_181 ;
F_113 (cmd, sg, sg_segments, i) {
V_173 [ V_179 ] . V_182 =
F_114 ( ( ( T_1 ) F_115 ( V_175 ) ) - 1 ) ;
V_173 [ V_179 ] . V_183 =
F_114 ( F_116 ( V_175 -> V_184 ) ) ;
V_173 [ V_179 ] . V_185 =
F_114 ( F_117 ( V_175 -> V_184 ) ) ;
}
} else {
V_37 -> V_38 -> V_180 = 0 ;
}
return 0 ;
}
static void F_118 ( struct V_8 * V_9 , T_1 V_186 )
{
T_1 V_187 = F_10 ( V_9 , V_188 ) ;
if ( V_9 -> V_27 == V_28 ) {
T_1 V_189 ;
V_189 = V_187 & V_190 ;
V_187 = V_189 | ( ( V_187 ^ V_186 ) & V_186 ) ;
} else {
V_187 |= V_186 ;
}
F_26 ( V_9 , V_187 , V_188 ) ;
}
static void F_119 ( struct V_8 * V_9 , T_1 V_186 )
{
T_1 V_187 = F_10 ( V_9 , V_188 ) ;
if ( V_9 -> V_27 == V_28 ) {
T_1 V_189 ;
V_189 = ( V_187 & V_190 ) &
~ ( V_186 & V_190 ) ;
V_187 = V_189 | ( ( V_187 & V_186 ) & ~ V_190 ) ;
} else {
V_187 &= ~ V_186 ;
}
F_26 ( V_9 , V_187 , V_188 ) ;
}
static void F_120 ( struct V_36 * V_37 ,
T_1 * V_191 , enum V_192 V_193 )
{
struct V_194 * V_195 = V_37 -> V_38 ;
T_1 V_196 ;
T_1 V_57 ;
if ( V_193 == V_197 ) {
V_196 = V_198 ;
* V_191 = V_199 ;
} else if ( V_193 == V_200 ) {
V_196 = V_201 ;
* V_191 = V_202 ;
} else {
V_196 = V_203 ;
* V_191 = V_204 ;
}
V_57 = V_196 | ( V_37 -> V_205
<< V_206 ) ;
if ( V_37 -> V_207 )
V_57 |= V_208 ;
V_195 -> V_39 . V_57 = F_114 ( V_57 ) ;
V_195 -> V_39 . V_40 =
F_114 ( V_209 ) ;
}
static
void F_121 ( struct V_36 * V_37 , T_1 V_191 )
{
struct V_210 * V_211 = V_37 -> V_211 ;
V_211 -> V_39 . V_57 = F_122 (
V_212 , V_191 ,
V_37 -> V_213 , V_37 -> V_126 ) ;
V_211 -> V_39 . V_58 = F_122 (
V_214 , 0 , 0 , 0 ) ;
V_211 -> V_39 . V_40 = 0 ;
V_211 -> V_215 . V_216 =
F_123 ( V_37 -> V_177 -> V_217 . V_151 ) ;
memcpy ( V_211 -> V_215 . V_218 , V_37 -> V_177 -> V_219 ,
( F_93 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ) ) ;
}
static void F_124 ( struct V_8 * V_9 ,
struct V_36 * V_37 , T_1 V_191 )
{
struct V_210 * V_211 = V_37 -> V_211 ;
struct V_220 * V_137 = & V_9 -> V_136 . V_137 ;
T_5 V_128 = F_92 ( V_137 -> V_149 . V_150 . V_151 ) ;
T_2 * V_144 = ( T_2 * ) V_37 -> V_211 + V_145 ;
V_211 -> V_39 . V_57 = F_122 (
V_221 , V_191 ,
V_37 -> V_213 , V_37 -> V_126 ) ;
V_211 -> V_39 . V_58 = F_122 (
0 , V_137 -> V_149 . V_222 , 0 , 0 ) ;
V_211 -> V_39 . V_40 = F_122 (
0 , 0 , V_128 >> 8 , ( T_2 ) V_128 ) ;
memcpy ( & V_211 -> V_140 , & V_137 -> V_149 . V_150 ,
V_141 ) ;
if ( V_137 -> V_149 . V_150 . V_142 == V_223 )
memcpy ( V_144 , V_137 -> V_152 , V_128 ) ;
}
static inline void F_125 ( struct V_36 * V_37 )
{
struct V_210 * V_211 = V_37 -> V_211 ;
memset ( V_211 , 0 , sizeof( struct V_210 ) ) ;
V_211 -> V_39 . V_57 =
F_122 (
V_224 , 0 , 0 , V_37 -> V_126 ) ;
}
static int F_126 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
T_1 V_191 ;
int V_10 = 0 ;
switch ( V_37 -> V_205 ) {
case V_225 :
if ( F_95 ( V_37 -> V_177 ) ) {
F_120 ( V_37 , & V_191 ,
V_37 -> V_177 -> V_226 ) ;
F_121 ( V_37 , V_191 ) ;
} else {
V_10 = - V_112 ;
}
break;
case V_227 :
F_120 ( V_37 , & V_191 , V_228 ) ;
if ( V_9 -> V_136 . type == V_229 )
F_124 (
V_9 , V_37 , V_191 ) ;
else if ( V_9 -> V_136 . type == V_230 )
F_125 ( V_37 ) ;
else
V_10 = - V_112 ;
break;
case V_231 :
V_10 = - V_232 ;
F_5 ( V_9 -> V_16 , L_9 ,
V_17 ) ;
break;
default:
V_10 = - V_232 ;
F_5 ( V_9 -> V_16 , L_10 ,
V_17 , V_37 -> V_205 ) ;
break;
}
return V_10 ;
}
static inline T_2 F_127 ( unsigned int V_233 )
{
if ( F_128 ( V_233 ) )
return ( V_233 & V_234 )
| V_235 ;
else
return V_233 & V_234 ;
}
static inline T_5 F_129 ( T_2 V_236 )
{
return ( V_236 & ~ V_235 ) | V_237 ;
}
static int F_130 ( struct V_238 * V_80 , struct V_176 * V_177 )
{
struct V_36 * V_37 ;
struct V_8 * V_9 ;
unsigned long V_76 ;
int V_45 ;
int V_23 = 0 ;
V_9 = F_131 ( V_80 ) ;
V_45 = V_177 -> V_149 -> V_45 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
switch ( V_9 -> V_96 ) {
case V_97 :
break;
case V_239 :
V_23 = V_240 ;
goto V_241;
case V_242 :
F_132 ( V_177 , V_243 ) ;
V_177 -> V_244 ( V_177 ) ;
goto V_241;
default:
F_133 ( V_9 -> V_16 , 1 , L_11 ,
V_17 , V_9 -> V_96 ) ;
F_132 ( V_177 , V_245 ) ;
V_177 -> V_244 ( V_177 ) ;
goto V_241;
}
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( F_22 ( V_45 , & V_9 -> V_98 ) ) {
V_23 = V_240 ;
goto V_46;
}
V_23 = F_56 ( V_9 , true ) ;
if ( V_23 ) {
V_23 = V_240 ;
F_24 ( V_45 , & V_9 -> V_98 ) ;
goto V_46;
}
F_101 ( V_9 -> V_77 . V_82 != V_83 ) ;
V_37 = & V_9 -> V_246 [ V_45 ] ;
F_101 ( V_37 -> V_177 ) ;
V_37 -> V_177 = V_177 ;
V_37 -> V_247 = V_133 ;
V_37 -> V_129 = V_177 -> V_129 ;
V_37 -> V_126 = V_45 ;
V_37 -> V_213 = F_127 ( V_177 -> V_105 -> V_213 ) ;
V_37 -> V_207 = ! F_134 ( V_9 ) ? true : false ;
V_37 -> V_205 = V_225 ;
F_126 ( V_9 , V_37 ) ;
V_23 = F_110 ( V_37 ) ;
if ( V_23 ) {
V_37 -> V_177 = NULL ;
F_24 ( V_45 , & V_9 -> V_98 ) ;
goto V_46;
}
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_89 ( V_9 , V_45 ) ;
V_241:
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_46:
return V_23 ;
}
static int F_135 ( struct V_8 * V_9 ,
struct V_36 * V_37 , enum V_248 V_249 , int V_45 )
{
V_37 -> V_177 = NULL ;
V_37 -> V_247 = 0 ;
V_37 -> V_129 = NULL ;
V_37 -> V_126 = V_45 ;
V_37 -> V_213 = 0 ;
V_37 -> V_205 = V_227 ;
V_37 -> V_207 = true ;
V_9 -> V_136 . type = V_249 ;
return F_126 ( V_9 , V_37 ) ;
}
static int
F_136 ( struct V_8 * V_9 , int V_45 )
{
int V_23 = 0 ;
unsigned long V_76 ;
T_1 V_19 = 1 << V_45 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_25 ( V_9 , V_45 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_23 = F_8 ( V_9 ,
V_127 ,
V_19 , ~ V_19 , 1000 , 1000 ) ;
return V_23 ;
}
static int
F_137 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
struct V_134 * V_135 = & V_9 -> V_136 . V_137 . V_138 ;
V_135 -> V_138 = F_32 ( V_37 -> V_56 ) >>
V_250 ;
return V_135 -> V_138 ;
}
static int
F_138 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
int V_251 ;
int V_23 = 0 ;
V_251 = F_30 ( V_37 -> V_56 ) ;
switch ( V_251 ) {
case V_252 :
if ( V_9 -> V_136 . type != V_230 ) {
V_23 = - V_112 ;
F_5 ( V_9 -> V_16 , L_12 ,
V_17 , V_251 ) ;
}
break;
case V_253 :
V_23 = F_137 ( V_9 , V_37 ) ;
if ( ! V_23 )
V_23 = F_94 ( V_9 , V_37 ) ;
break;
case V_254 :
V_23 = - V_255 ;
F_5 ( V_9 -> V_16 , L_13 ,
V_17 ) ;
break;
default:
V_23 = - V_112 ;
F_5 ( V_9 -> V_16 , L_14 ,
V_17 , V_251 ) ;
break;
}
return V_23 ;
}
static int F_139 ( struct V_8 * V_9 ,
struct V_36 * V_37 , int V_256 )
{
int V_23 = 0 ;
unsigned long V_257 ;
unsigned long V_76 ;
V_257 = F_103 ( V_9 -> V_136 . V_258 ,
F_9 ( V_256 ) ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_9 -> V_136 . V_258 = NULL ;
if ( F_95 ( V_257 ) ) {
V_23 = F_17 ( V_37 ) ;
if ( ! V_23 )
V_23 = F_138 ( V_9 , V_37 ) ;
}
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( ! V_257 ) {
V_23 = - V_26 ;
if ( ! F_136 ( V_9 , V_37 -> V_126 ) )
V_23 = - V_94 ;
}
return V_23 ;
}
static bool F_140 ( struct V_8 * V_9 , int * V_259 )
{
int V_45 ;
bool V_10 = false ;
unsigned long V_260 ;
if ( ! V_259 )
goto V_46;
do {
V_260 = ~ V_9 -> V_98 ;
V_45 = F_141 ( & V_260 , V_9 -> V_155 ) ;
if ( V_45 >= V_9 -> V_155 )
goto V_46;
} while ( F_22 ( V_45 , & V_9 -> V_98 ) );
* V_259 = V_45 ;
V_10 = true ;
V_46:
return V_10 ;
}
static inline void F_142 ( struct V_8 * V_9 , int V_45 )
{
F_24 ( V_45 , & V_9 -> V_98 ) ;
}
static int F_143 ( struct V_8 * V_9 ,
enum V_248 V_249 , int V_24 )
{
struct V_36 * V_37 ;
int V_23 ;
int V_45 ;
struct V_261 V_262 ;
unsigned long V_76 ;
F_144 ( V_9 -> V_136 . V_263 , F_140 ( V_9 , & V_45 ) ) ;
F_105 ( & V_262 ) ;
V_37 = & V_9 -> V_246 [ V_45 ] ;
F_101 ( V_37 -> V_177 ) ;
V_23 = F_135 ( V_9 , V_37 , V_249 , V_45 ) ;
if ( F_145 ( V_23 ) )
goto V_264;
V_9 -> V_136 . V_258 = & V_262 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_89 ( V_9 , V_45 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_23 = F_139 ( V_9 , V_37 , V_24 ) ;
V_264:
F_142 ( V_9 , V_45 ) ;
F_146 ( & V_9 -> V_136 . V_263 ) ;
return V_23 ;
}
static inline void F_147 ( struct V_8 * V_9 ,
struct V_265 * * V_149 , struct V_134 * * V_138 ,
enum V_266 V_142 , T_2 V_267 , T_2 V_268 , T_2 V_269 )
{
* V_149 = & V_9 -> V_136 . V_137 . V_149 ;
* V_138 = & V_9 -> V_136 . V_137 . V_138 ;
memset ( * V_149 , 0 , sizeof( struct V_265 ) ) ;
memset ( * V_138 , 0 , sizeof( struct V_134 ) ) ;
( * V_149 ) -> V_150 . V_142 = V_142 ;
( * V_149 ) -> V_150 . V_267 = V_267 ;
( * V_149 ) -> V_150 . V_268 = V_268 ;
( * V_149 ) -> V_150 . V_269 = V_269 ;
}
static int F_148 ( struct V_8 * V_9 , enum V_266 V_142 ,
enum V_270 V_267 , bool * V_271 )
{
struct V_265 * V_149 = NULL ;
struct V_134 * V_138 = NULL ;
int V_23 , V_268 = 0 , V_269 = 0 ;
F_149 ( ! V_9 ) ;
F_56 ( V_9 , false ) ;
F_107 ( & V_9 -> V_136 . V_272 ) ;
F_147 ( V_9 , & V_149 , & V_138 , V_142 , V_267 , V_268 ,
V_269 ) ;
switch ( V_142 ) {
case V_273 :
case V_274 :
case V_275 :
V_149 -> V_222 = V_276 ;
break;
case V_277 :
V_149 -> V_222 = V_278 ;
if ( ! V_271 ) {
F_5 ( V_9 -> V_16 , L_15 ,
V_17 ) ;
V_23 = - V_112 ;
goto V_241;
}
break;
default:
F_5 ( V_9 -> V_16 ,
L_16 ,
V_17 , V_142 ) ;
V_23 = - V_112 ;
goto V_241;
}
V_23 = F_143 ( V_9 , V_229 , V_279 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 ,
L_17 ,
V_17 , V_267 , V_23 ) ;
goto V_241;
}
if ( V_271 )
* V_271 = ( F_31 ( V_138 -> V_139 . V_111 ) &
V_280 ) & 0x1 ;
V_241:
F_109 ( & V_9 -> V_136 . V_272 ) ;
F_70 ( V_9 ) ;
return V_23 ;
}
static int F_150 ( struct V_8 * V_9 , enum V_266 V_142 ,
enum V_281 V_267 , T_2 V_268 , T_2 V_269 , T_1 * V_282 )
{
struct V_265 * V_149 = NULL ;
struct V_134 * V_138 = NULL ;
int V_23 ;
F_149 ( ! V_9 ) ;
F_56 ( V_9 , false ) ;
if ( ! V_282 ) {
F_5 ( V_9 -> V_16 , L_18 ,
V_17 , V_142 ) ;
V_23 = - V_112 ;
goto V_46;
}
F_107 ( & V_9 -> V_136 . V_272 ) ;
F_147 ( V_9 , & V_149 , & V_138 , V_142 , V_267 , V_268 ,
V_269 ) ;
switch ( V_142 ) {
case V_283 :
V_149 -> V_222 = V_276 ;
V_149 -> V_150 . V_111 = F_123 ( * V_282 ) ;
break;
case V_284 :
V_149 -> V_222 = V_278 ;
break;
default:
F_5 ( V_9 -> V_16 , L_19 ,
V_17 , V_142 ) ;
V_23 = - V_112 ;
goto V_241;
}
V_23 = F_143 ( V_9 , V_229 , V_279 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_20 ,
V_17 , V_142 , V_267 , V_23 ) ;
goto V_241;
}
* V_282 = F_31 ( V_138 -> V_139 . V_111 ) ;
V_241:
F_109 ( & V_9 -> V_136 . V_272 ) ;
V_46:
F_70 ( V_9 ) ;
return V_23 ;
}
static int F_151 ( struct V_8 * V_9 ,
enum V_266 V_142 , enum V_285 V_267 , T_2 V_268 ,
T_2 V_269 , T_2 * V_286 , int * V_147 )
{
struct V_265 * V_149 = NULL ;
struct V_134 * V_138 = NULL ;
int V_23 ;
F_149 ( ! V_9 ) ;
F_56 ( V_9 , false ) ;
if ( ! V_286 ) {
F_5 ( V_9 -> V_16 , L_21 ,
V_17 , V_142 ) ;
V_23 = - V_112 ;
goto V_46;
}
if ( * V_147 <= V_287 || * V_147 > V_288 ) {
F_5 ( V_9 -> V_16 , L_22 ,
V_17 , * V_147 ) ;
V_23 = - V_112 ;
goto V_46;
}
F_107 ( & V_9 -> V_136 . V_272 ) ;
F_147 ( V_9 , & V_149 , & V_138 , V_142 , V_267 , V_268 ,
V_269 ) ;
V_9 -> V_136 . V_137 . V_152 = V_286 ;
V_149 -> V_150 . V_151 = F_152 ( * V_147 ) ;
switch ( V_142 ) {
case V_223 :
V_149 -> V_222 = V_276 ;
break;
case V_143 :
V_149 -> V_222 = V_278 ;
break;
default:
F_5 ( V_9 -> V_16 ,
L_23 ,
V_17 , V_142 ) ;
V_23 = - V_112 ;
goto V_241;
}
V_23 = F_143 ( V_9 , V_229 , V_279 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_20 ,
V_17 , V_142 , V_267 , V_23 ) ;
goto V_241;
}
V_9 -> V_136 . V_137 . V_152 = NULL ;
* V_147 = F_92 ( V_138 -> V_139 . V_151 ) ;
V_241:
F_109 ( & V_9 -> V_136 . V_272 ) ;
V_46:
F_70 ( V_9 ) ;
return V_23 ;
}
static int F_153 ( struct V_8 * V_9 ,
enum V_285 V_289 ,
int V_290 ,
T_1 V_291 ,
T_2 * V_292 ,
T_1 V_293 )
{
int V_10 ;
T_2 * V_286 ;
T_1 V_294 ;
bool V_295 = true ;
if ( V_289 >= V_296 )
return - V_112 ;
V_294 = V_297 [ V_289 ] ;
if ( ( V_291 + V_293 ) > V_294 )
return - V_112 ;
if ( ! V_291 && ( V_293 == V_294 ) ) {
V_286 = V_292 ;
V_295 = false ;
} else {
V_286 = F_154 ( V_294 , V_298 ) ;
if ( ! V_286 )
return - V_299 ;
}
V_10 = F_151 ( V_9 , V_143 ,
V_289 , V_290 , 0 , V_286 ,
& V_294 ) ;
if ( V_10 || ( V_294 < V_297 [ V_289 ] ) ||
( V_286 [ V_300 ] !=
V_297 [ V_289 ] )
|| ( V_286 [ V_301 ] != V_289 ) ) {
F_5 ( V_9 -> V_16 , L_24 ,
V_17 , V_289 , V_291 , V_294 , V_10 ) ;
if ( ! V_10 )
V_10 = - V_112 ;
goto V_46;
}
if ( V_295 )
memcpy ( V_292 , & V_286 [ V_291 ] , V_293 ) ;
V_46:
if ( V_295 )
F_155 ( V_286 ) ;
return V_10 ;
}
static inline int F_156 ( struct V_8 * V_9 ,
enum V_285 V_289 ,
int V_290 ,
T_2 * V_108 ,
T_1 V_182 )
{
return F_153 ( V_9 , V_289 , V_290 , 0 , V_108 , V_182 ) ;
}
static inline int F_157 ( struct V_8 * V_9 ,
T_2 * V_108 ,
T_1 V_182 )
{
return F_156 ( V_9 , V_302 , 0 , V_108 , V_182 ) ;
}
static inline int F_158 ( struct V_8 * V_9 ,
int V_213 ,
enum V_303 V_291 ,
T_2 * V_292 ,
T_1 V_293 )
{
if ( V_213 != V_304 && ( V_213 >= V_305 ) )
return - V_306 ;
return F_153 ( V_9 , V_307 , V_213 ,
V_291 , V_292 , V_293 ) ;
}
static int F_159 ( struct V_8 * V_9 )
{
T_4 V_308 , V_309 , V_310 ;
V_310 = ( sizeof( struct V_311 ) * V_9 -> V_155 ) ;
V_9 -> V_312 = F_160 ( V_9 -> V_16 ,
V_310 ,
& V_9 -> V_313 ,
V_298 ) ;
if ( ! V_9 -> V_312 ||
F_101 ( V_9 -> V_313 & ( V_109 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_25 ) ;
goto V_46;
}
V_309 = ( sizeof( struct V_194 ) * V_9 -> V_155 ) ;
V_9 -> V_314 = F_160 ( V_9 -> V_16 ,
V_309 ,
& V_9 -> V_315 ,
V_298 ) ;
if ( ! V_9 -> V_314 ||
F_101 ( V_9 -> V_315 & ( V_109 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_26 ) ;
goto V_46;
}
V_308 = sizeof( struct V_42 ) * V_9 -> V_48 ;
V_9 -> V_316 = F_160 ( V_9 -> V_16 ,
V_308 ,
& V_9 -> V_317 ,
V_298 ) ;
if ( ! V_9 -> V_316 ||
F_101 ( V_9 -> V_317 & ( V_109 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_27 ) ;
goto V_46;
}
V_9 -> V_246 = F_161 ( V_9 -> V_16 ,
V_9 -> V_155 * sizeof( struct V_36 ) ,
V_298 ) ;
if ( ! V_9 -> V_246 ) {
F_5 ( V_9 -> V_16 , L_28 ) ;
goto V_46;
}
return 0 ;
V_46:
return - V_299 ;
}
static void F_162 ( struct V_8 * V_9 )
{
struct V_311 * V_318 ;
struct V_194 * V_319 ;
T_6 V_320 ;
T_6 V_321 ;
T_5 V_322 ;
T_5 V_323 ;
int V_324 ;
int V_179 ;
V_319 = V_9 -> V_314 ;
V_318 = V_9 -> V_312 ;
V_322 =
F_163 ( struct V_311 , V_325 ) ;
V_323 =
F_163 ( struct V_311 , V_173 ) ;
V_324 = sizeof( struct V_311 ) ;
V_320 = V_9 -> V_313 ;
for ( V_179 = 0 ; V_179 < V_9 -> V_155 ; V_179 ++ ) {
V_321 =
( V_320 + ( V_324 * V_179 ) ) ;
V_319 [ V_179 ] . V_326 =
F_114 ( F_116 ( V_321 ) ) ;
V_319 [ V_179 ] . V_327 =
F_114 ( F_117 ( V_321 ) ) ;
V_319 [ V_179 ] . V_328 =
F_112 ( ( V_322 >> 2 ) ) ;
V_319 [ V_179 ] . V_329 =
F_112 ( ( V_323 >> 2 ) ) ;
V_319 [ V_179 ] . V_330 =
F_112 ( V_331 >> 2 ) ;
V_9 -> V_246 [ V_179 ] . V_38 = ( V_319 + V_179 ) ;
V_9 -> V_246 [ V_179 ] . V_211 =
(struct V_210 * ) ( V_318 + V_179 ) ;
V_9 -> V_246 [ V_179 ] . V_56 =
(struct V_55 * ) V_318 [ V_179 ] . V_325 ;
V_9 -> V_246 [ V_179 ] . V_181 =
(struct V_172 * ) V_318 [ V_179 ] . V_173 ;
}
}
static int F_164 ( struct V_8 * V_9 )
{
struct V_159 V_160 = { 0 } ;
int V_10 ;
V_160 . V_165 = V_332 ;
V_10 = F_106 ( V_9 , & V_160 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 ,
L_29 , V_10 ) ;
return V_10 ;
}
static inline void F_108 ( struct V_8 * V_9 )
{
#define F_165 1000
unsigned long V_333 ;
if ( ! ( V_9 -> V_31 & V_334 ) )
return;
if ( F_145 ( ! F_86 ( V_9 -> V_335 ) ) ) {
V_333 = F_165 ;
} else {
unsigned long V_336 =
( unsigned long ) F_86 (
F_87 ( F_84 () ,
V_9 -> V_335 ) ) ;
if ( V_336 < F_165 )
V_333 =
F_165 - V_336 ;
else
return;
}
F_11 ( V_333 , V_333 + 50 ) ;
}
int F_166 ( struct V_8 * V_9 , T_1 V_337 ,
T_2 V_338 , T_1 V_339 , T_2 V_340 )
{
struct V_159 V_160 = { 0 } ;
static const char * const V_341 [] = {
L_30 ,
L_31
} ;
const char * V_187 = V_341 [ ! ! V_340 ] ;
int V_10 ;
V_160 . V_165 = V_340 ?
V_342 : V_343 ;
V_160 . V_161 = V_337 ;
V_160 . V_163 = F_167 ( V_338 ) ;
V_160 . V_164 = V_339 ;
V_10 = F_106 ( V_9 , & V_160 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_32 ,
V_187 , F_168 ( V_337 ) , V_339 , V_10 ) ;
return V_10 ;
}
int F_169 ( struct V_8 * V_9 , T_1 V_337 ,
T_1 * V_339 , T_2 V_340 )
{
struct V_159 V_160 = { 0 } ;
static const char * const V_341 [] = {
L_33 ,
L_34
} ;
const char * V_344 = V_341 [ ! ! V_340 ] ;
int V_10 ;
struct V_345 V_346 ;
struct V_345 V_347 ;
bool V_348 = false ;
if ( V_340 && ( V_9 -> V_31 & V_349 ) ) {
V_346 = V_9 -> V_350 ;
V_347 = V_346 ;
if ( V_346 . V_351 == V_352 ||
V_346 . V_353 == V_352 ) {
V_347 . V_351 = V_354 ;
V_347 . V_353 = V_354 ;
V_348 = true ;
} else if ( V_346 . V_351 == V_355 ||
V_346 . V_353 == V_355 ) {
V_347 . V_351 = V_356 ;
V_347 . V_353 = V_356 ;
V_348 = true ;
}
if ( V_348 ) {
V_10 = F_170 ( V_9 , & V_347 ) ;
if ( V_10 )
goto V_46;
}
}
V_160 . V_165 = V_340 ?
V_357 : V_358 ;
V_160 . V_161 = V_337 ;
V_10 = F_106 ( V_9 , & V_160 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_35 ,
V_344 , F_168 ( V_337 ) , V_10 ) ;
goto V_46;
}
if ( V_339 )
* V_339 = V_160 . V_164 ;
if ( V_340 && ( V_9 -> V_31 & V_349 )
&& V_348 )
F_170 ( V_9 , & V_346 ) ;
V_46:
return V_10 ;
}
static int F_171 ( struct V_8 * V_9 , struct V_159 * V_177 )
{
struct V_261 V_101 ;
unsigned long V_76 ;
T_2 V_359 ;
int V_10 ;
F_107 ( & V_9 -> V_171 ) ;
F_105 ( & V_101 ) ;
F_108 ( V_9 ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_9 -> V_101 = & V_101 ;
V_10 = F_104 ( V_9 , V_177 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_36 ,
V_177 -> V_165 , V_177 -> V_164 , V_10 ) ;
goto V_46;
}
V_10 = F_102 ( V_9 , V_177 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_36 ,
V_177 -> V_165 , V_177 -> V_164 , V_10 ) ;
goto V_46;
}
if ( ! F_103 ( V_9 -> V_101 ,
F_9 ( V_169 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_37 ,
V_177 -> V_165 , V_177 -> V_164 ) ;
V_10 = - V_26 ;
goto V_46;
}
V_359 = F_99 ( V_9 ) ;
if ( V_359 != V_360 ) {
F_5 ( V_9 -> V_16 ,
L_38 ,
V_177 -> V_165 , V_359 ) ;
V_10 = ( V_359 != V_361 ) ? V_359 : - 1 ;
}
V_46:
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_9 -> V_101 = NULL ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_109 ( & V_9 -> V_171 ) ;
return V_10 ;
}
static int F_172 ( struct V_8 * V_9 , T_2 V_117 )
{
struct V_159 V_160 = { 0 } ;
int V_10 ;
if ( V_9 -> V_31 & V_362 ) {
V_10 = F_173 ( V_9 ,
F_174 ( V_363 , 0 ) , 1 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_39 ,
V_17 , V_10 ) ;
goto V_46;
}
}
V_160 . V_165 = V_343 ;
V_160 . V_161 = F_175 ( V_364 ) ;
V_160 . V_164 = V_117 ;
F_56 ( V_9 , false ) ;
V_10 = F_171 ( V_9 , & V_160 ) ;
F_70 ( V_9 ) ;
V_46:
return V_10 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_159 V_160 = { 0 } ;
V_160 . V_165 = V_365 ;
return F_171 ( V_9 , & V_160 ) ;
}
static int F_51 ( struct V_8 * V_9 )
{
struct V_159 V_160 = { 0 } ;
int V_10 ;
V_160 . V_165 = V_366 ;
V_10 = F_171 ( V_9 , & V_160 ) ;
if ( V_10 ) {
F_176 ( V_9 ) ;
V_10 = F_177 ( V_9 ) ;
}
return V_10 ;
}
static void F_178 ( struct V_8 * V_9 )
{
V_9 -> V_350 . V_367 = V_368 ;
V_9 -> V_350 . V_369 = V_368 ;
V_9 -> V_350 . V_370 = 1 ;
V_9 -> V_350 . V_371 = 1 ;
V_9 -> V_350 . V_353 = V_356 ;
V_9 -> V_350 . V_351 = V_356 ;
V_9 -> V_350 . V_372 = 0 ;
}
static int F_179 ( struct V_8 * V_9 )
{
struct V_345 * V_350 = & V_9 -> V_373 . V_374 ;
if ( V_9 -> V_373 . V_375 )
return 0 ;
V_350 -> V_351 = V_354 ;
V_350 -> V_353 = V_354 ;
V_350 -> V_372 = V_376 ;
F_180 ( V_9 , F_175 ( V_377 ) ,
& V_350 -> V_370 ) ;
F_180 ( V_9 , F_175 ( V_378 ) ,
& V_350 -> V_371 ) ;
if ( ! V_350 -> V_370 || ! V_350 -> V_371 ) {
F_5 ( V_9 -> V_16 , L_40 ,
V_17 ,
V_350 -> V_370 ,
V_350 -> V_371 ) ;
return - V_112 ;
}
F_180 ( V_9 , F_175 ( V_379 ) , & V_350 -> V_367 ) ;
if ( ! V_350 -> V_367 ) {
F_180 ( V_9 , F_175 ( V_380 ) ,
& V_350 -> V_367 ) ;
if ( ! V_350 -> V_367 ) {
F_5 ( V_9 -> V_16 , L_41 ,
V_17 , V_350 -> V_367 ) ;
return - V_112 ;
}
V_350 -> V_353 = V_356 ;
}
F_181 ( V_9 , F_175 ( V_379 ) ,
& V_350 -> V_369 ) ;
if ( ! V_350 -> V_369 ) {
F_181 ( V_9 , F_175 ( V_380 ) ,
& V_350 -> V_369 ) ;
if ( ! V_350 -> V_369 ) {
F_5 ( V_9 -> V_16 , L_42 ,
V_17 , V_350 -> V_369 ) ;
return - V_112 ;
}
V_350 -> V_351 = V_356 ;
}
V_9 -> V_373 . V_375 = true ;
return 0 ;
}
static int F_170 ( struct V_8 * V_9 ,
struct V_345 * V_381 )
{
int V_10 ;
if ( V_381 -> V_367 == V_9 -> V_350 . V_367 &&
V_381 -> V_369 == V_9 -> V_350 . V_369 &&
V_381 -> V_370 == V_9 -> V_350 . V_370 &&
V_381 -> V_371 == V_9 -> V_350 . V_371 &&
V_381 -> V_353 == V_9 -> V_350 . V_353 &&
V_381 -> V_351 == V_9 -> V_350 . V_351 &&
V_381 -> V_372 == V_9 -> V_350 . V_372 ) {
F_182 ( V_9 -> V_16 , L_43 , V_17 ) ;
return 0 ;
}
F_173 ( V_9 , F_175 ( V_382 ) , V_381 -> V_367 ) ;
F_173 ( V_9 , F_175 ( V_383 ) ,
V_381 -> V_370 ) ;
if ( V_381 -> V_353 == V_354 ||
V_381 -> V_353 == V_352 )
F_173 ( V_9 , F_175 ( V_384 ) , TRUE ) ;
else
F_173 ( V_9 , F_175 ( V_384 ) , FALSE ) ;
F_173 ( V_9 , F_175 ( V_385 ) , V_381 -> V_369 ) ;
F_173 ( V_9 , F_175 ( V_386 ) ,
V_381 -> V_371 ) ;
if ( V_381 -> V_351 == V_354 ||
V_381 -> V_351 == V_352 )
F_173 ( V_9 , F_175 ( V_387 ) , TRUE ) ;
else
F_173 ( V_9 , F_175 ( V_387 ) , FALSE ) ;
if ( V_381 -> V_353 == V_354 ||
V_381 -> V_351 == V_354 ||
V_381 -> V_353 == V_352 ||
V_381 -> V_351 == V_352 )
F_173 ( V_9 , F_175 ( V_388 ) ,
V_381 -> V_372 ) ;
V_10 = F_172 ( V_9 , V_381 -> V_353 << 4
| V_381 -> V_351 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_44 , V_17 , V_10 ) ;
} else {
F_183 ( V_9 , V_389 , NULL ,
V_381 ) ;
memcpy ( & V_9 -> V_350 , V_381 ,
sizeof( struct V_345 ) ) ;
}
return V_10 ;
}
static int F_184 ( struct V_8 * V_9 ,
struct V_345 * V_390 )
{
struct V_345 V_391 = { 0 } ;
int V_10 ;
V_10 = F_183 ( V_9 , V_392 ,
V_390 , & V_391 ) ;
if ( V_10 )
memcpy ( & V_391 , V_390 , sizeof( V_391 ) ) ;
V_10 = F_170 ( V_9 , & V_391 ) ;
return V_10 ;
}
static int F_185 ( struct V_8 * V_9 )
{
int V_179 , V_393 , V_23 = 0 ;
bool V_271 = 1 ;
for ( V_393 = V_394 ; V_393 > 0 ; V_393 -- ) {
V_23 = F_148 ( V_9 , V_273 ,
V_395 , NULL ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_182 ( V_9 -> V_16 , L_45 , V_17 , V_23 ) ;
}
if ( V_23 ) {
F_5 ( V_9 -> V_16 ,
L_46 ,
V_17 , V_23 ) ;
goto V_46;
}
for ( V_179 = 0 ; V_179 < 100 && ! V_23 && V_271 ; V_179 ++ ) {
for ( V_393 = V_394 ; V_393 > 0 ; V_393 -- ) {
V_23 = F_148 ( V_9 ,
V_277 ,
V_395 , & V_271 ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_182 ( V_9 -> V_16 , L_45 , V_17 ,
V_23 ) ;
}
}
if ( V_23 )
F_5 ( V_9 -> V_16 ,
L_47 ,
V_17 , V_23 ) ;
else if ( V_271 )
F_5 ( V_9 -> V_16 ,
L_48 ,
V_17 ) ;
V_46:
return V_23 ;
}
static int F_186 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
T_1 V_18 ;
F_118 ( V_9 , V_396 ) ;
if ( F_134 ( V_9 ) )
F_36 ( V_9 , V_9 -> V_155 - 1 , V_397 ) ;
else
F_39 ( V_9 ) ;
F_26 ( V_9 , F_116 ( V_9 -> V_315 ) ,
V_398 ) ;
F_26 ( V_9 , F_117 ( V_9 -> V_315 ) ,
V_399 ) ;
F_26 ( V_9 , F_116 ( V_9 -> V_317 ) ,
V_400 ) ;
F_26 ( V_9 , F_117 ( V_9 -> V_317 ) ,
V_401 ) ;
V_18 = F_10 ( V_9 , V_34 ) ;
if ( ! ( F_27 ( V_18 ) ) ) {
F_40 ( V_9 ) ;
} else {
F_5 ( V_9 -> V_16 ,
L_49 ) ;
V_23 = - V_170 ;
goto V_46;
}
V_46:
return V_23 ;
}
static int F_187 ( struct V_8 * V_9 )
{
int V_402 ;
if ( ! F_42 ( V_9 ) ) {
F_188 ( V_9 ) ;
F_189 ( 5 ) ;
}
F_176 ( V_9 ) ;
F_190 ( V_9 , V_392 ) ;
F_41 ( V_9 ) ;
F_189 ( 1 ) ;
V_402 = 10 ;
while ( F_42 ( V_9 ) ) {
if ( V_402 ) {
V_402 -- ;
} else {
F_5 ( V_9 -> V_16 ,
L_50 ) ;
return - V_170 ;
}
F_189 ( 5 ) ;
}
F_118 ( V_9 , V_403 ) ;
F_190 ( V_9 , V_389 ) ;
return 0 ;
}
static int F_191 ( struct V_8 * V_9 , bool V_340 )
{
int V_404 , V_179 , V_23 = 0 ;
if ( ! V_340 )
F_180 ( V_9 , F_175 ( V_378 ) ,
& V_404 ) ;
else
F_181 ( V_9 , F_175 ( V_378 ) ,
& V_404 ) ;
for ( V_179 = 0 ; V_179 < V_404 ; V_179 ++ ) {
if ( ! V_340 )
V_23 = F_173 ( V_9 ,
F_174 ( V_405 ,
F_192 ( V_179 ) ) ,
0 ) ;
else
V_23 = F_193 ( V_9 ,
F_174 ( V_405 ,
F_192 ( V_179 ) ) ,
0 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_51 ,
V_17 , V_340 , V_179 , V_23 ) ;
break;
}
}
return V_23 ;
}
static inline int F_194 ( struct V_8 * V_9 )
{
return F_191 ( V_9 , true ) ;
}
static int F_195 ( struct V_8 * V_9 )
{
int V_10 ;
int V_393 = V_406 ;
do {
F_196 ( V_9 , V_392 ) ;
V_10 = F_164 ( V_9 ) ;
if ( ! V_10 && ! F_16 ( V_9 ) ) {
F_5 ( V_9 -> V_16 , L_52 , V_17 ) ;
V_10 = - V_407 ;
goto V_46;
}
if ( V_10 && F_187 ( V_9 ) )
goto V_46;
} while ( V_10 && V_393 -- );
if ( V_10 )
goto V_46;
if ( V_9 -> V_31 & V_408 ) {
V_10 = F_194 ( V_9 ) ;
if ( V_10 )
goto V_46;
}
V_10 = F_196 ( V_9 , V_389 ) ;
if ( V_10 )
goto V_46;
V_10 = F_186 ( V_9 ) ;
V_46:
if ( V_10 )
F_5 ( V_9 -> V_16 , L_53 , V_10 ) ;
return V_10 ;
}
static int F_197 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
int V_393 ;
F_56 ( V_9 , false ) ;
F_107 ( & V_9 -> V_136 . V_272 ) ;
for ( V_393 = V_409 ; V_393 > 0 ; V_393 -- ) {
V_23 = F_143 ( V_9 , V_230 ,
V_410 ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_182 ( V_9 -> V_16 , L_45 , V_17 , V_23 ) ;
}
F_109 ( & V_9 -> V_136 . V_272 ) ;
F_70 ( V_9 ) ;
if ( V_23 )
F_5 ( V_9 -> V_16 , L_54 , V_17 , V_23 ) ;
return V_23 ;
}
static void F_198 ( struct V_411 * V_412 )
{
int V_10 = 0 ;
T_2 V_413 ;
struct V_8 * V_9 ;
V_9 = F_131 ( V_412 -> V_80 ) ;
V_413 = V_9 -> V_155 ;
V_10 = F_158 ( V_9 ,
F_127 ( V_412 -> V_213 ) ,
V_414 ,
& V_413 ,
sizeof( V_413 ) ) ;
if ( V_10 == - V_306 )
V_413 = 1 ;
else if ( ! V_413 )
V_413 = V_9 -> V_155 ;
else
V_413 = F_93 ( int , V_413 , V_9 -> V_155 ) ;
F_182 ( V_9 -> V_16 , L_55 ,
V_17 , V_413 ) ;
F_199 ( V_412 , V_413 ) ;
}
static int F_200 ( struct V_8 * V_9 ,
T_2 V_213 ,
T_2 * V_415 )
{
int V_10 ;
if ( ! V_415 )
V_10 = - V_112 ;
else if ( V_213 >= V_305 )
V_10 = - V_232 ;
else
V_10 = F_158 ( V_9 ,
V_213 ,
V_416 ,
V_415 ,
sizeof( * V_415 ) ) ;
return V_10 ;
}
static inline void F_201 ( struct V_8 * V_9 ,
struct V_411 * V_412 )
{
if ( V_9 -> V_417 . V_418 &&
! V_9 -> V_417 . V_419 ) {
T_2 V_415 ;
if ( ! F_200 ( V_9 , F_127 ( V_412 -> V_213 ) ,
& V_415 ) &&
( V_415 == V_420 ) )
V_9 -> V_417 . V_419 = true ;
}
}
static int F_202 ( struct V_411 * V_412 )
{
struct V_8 * V_9 ;
V_9 = F_131 ( V_412 -> V_80 ) ;
V_412 -> V_421 = 1 ;
V_412 -> V_422 = 1 ;
V_412 -> V_423 = 1 ;
F_198 ( V_412 ) ;
F_201 ( V_9 , V_412 ) ;
return 0 ;
}
static int F_203 ( struct V_411 * V_412 , int V_424 )
{
struct V_8 * V_9 = F_131 ( V_412 -> V_80 ) ;
if ( V_424 > V_9 -> V_155 )
V_424 = V_9 -> V_155 ;
return F_199 ( V_412 , V_424 ) ;
}
static int F_204 ( struct V_411 * V_412 )
{
struct V_425 * V_426 = V_412 -> V_425 ;
F_205 ( V_426 , V_427 - 1 ) ;
F_206 ( V_426 , V_428 ) ;
return 0 ;
}
static void F_207 ( struct V_411 * V_412 )
{
struct V_8 * V_9 ;
V_9 = F_131 ( V_412 -> V_80 ) ;
if ( F_127 ( V_412 -> V_213 ) == V_429 ) {
unsigned long V_76 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_9 -> V_430 = NULL ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
}
}
static int F_208 ( struct V_8 * V_9 , T_1 V_268 , T_2 * V_251 )
{
struct V_42 * V_43 ;
struct V_431 * V_432 ;
unsigned long V_76 ;
int V_433 ;
int V_434 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_209 ( V_268 , & V_9 -> V_99 ) ;
V_43 = V_9 -> V_316 ;
V_433 = F_19 ( & V_43 [ V_268 ] ) ;
if ( V_433 == V_435 ) {
V_432 = (struct V_431 * )
V_43 [ V_268 ] . V_436 ;
V_434 = F_31 ( V_432 -> V_39 . V_58 ) ;
V_434 = ( ( V_434 & V_437 ) >> 8 ) ;
if ( V_251 )
* V_251 = ( T_2 ) V_434 ;
} else {
F_5 ( V_9 -> V_16 , L_56 ,
V_17 , V_433 ) ;
}
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
return V_433 ;
}
static inline int
F_210 ( struct V_36 * V_37 , int V_438 )
{
int V_439 = 0 ;
switch ( V_438 ) {
case V_440 :
F_91 ( V_37 ) ;
case V_441 :
V_439 |= V_442 << 16 |
V_443 << 8 |
V_438 ;
break;
case V_444 :
case V_445 :
case V_446 :
F_91 ( V_37 ) ;
V_439 |= V_438 ;
break;
default:
V_439 |= V_243 << 16 ;
break;
}
return V_439 ;
}
static inline int
F_211 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
int V_439 = 0 ;
int V_438 ;
int V_447 ;
V_447 = F_17 ( V_37 ) ;
switch ( V_447 ) {
case V_435 :
V_439 = F_30 ( V_37 -> V_56 ) ;
switch ( V_439 ) {
case V_448 :
V_439 = F_32 ( V_37 -> V_56 ) ;
V_438 = V_439 & V_449 ;
V_439 = F_210 ( V_37 , V_438 ) ;
if ( F_34 ( V_37 -> V_56 ) )
F_60 ( & V_9 -> V_450 ) ;
break;
case V_254 :
V_439 = V_243 << 16 ;
F_5 ( V_9 -> V_16 ,
L_57 ) ;
break;
default:
V_439 = V_243 << 16 ;
F_5 ( V_9 -> V_16 ,
L_58 ,
V_439 ) ;
break;
}
break;
case V_451 :
V_439 |= V_452 << 16 ;
break;
case V_209 :
V_439 |= V_453 << 16 ;
break;
case V_454 :
case V_455 :
case V_456 :
case V_457 :
case V_458 :
case V_459 :
default:
V_439 |= V_243 << 16 ;
F_5 ( V_9 -> V_16 ,
L_59 , V_447 ) ;
break;
}
return V_439 ;
}
static void F_212 ( struct V_8 * V_9 , T_1 V_460 )
{
if ( ( V_460 & V_461 ) && V_9 -> V_100 ) {
V_9 -> V_100 -> V_163 |=
F_28 ( V_9 ) ;
V_9 -> V_100 -> V_164 =
F_29 ( V_9 ) ;
V_258 ( & V_9 -> V_100 -> V_168 ) ;
}
if ( ( V_460 & V_462 ) && V_9 -> V_101 )
V_258 ( V_9 -> V_101 ) ;
}
static void F_213 ( struct V_8 * V_9 )
{
struct V_36 * V_37 ;
struct V_176 * V_177 ;
unsigned long V_463 ;
T_1 V_464 ;
int V_439 ;
int V_268 ;
if ( F_134 ( V_9 ) )
F_35 ( V_9 ) ;
V_464 = F_10 ( V_9 , V_127 ) ;
V_463 = V_464 ^ V_9 -> V_124 ;
F_214 (index, &completed_reqs, hba->nutrs) {
V_37 = & V_9 -> V_246 [ V_268 ] ;
V_177 = V_37 -> V_177 ;
if ( V_177 ) {
V_439 = F_211 ( V_9 , V_37 ) ;
F_215 ( V_177 ) ;
V_177 -> V_439 = V_439 ;
V_37 -> V_177 = NULL ;
F_24 ( V_268 , & V_9 -> V_98 ) ;
V_177 -> V_244 ( V_177 ) ;
F_68 ( V_9 ) ;
} else if ( V_37 -> V_205 == V_227 ) {
if ( V_9 -> V_136 . V_258 )
V_258 ( V_9 -> V_136 . V_258 ) ;
}
}
V_9 -> V_124 ^= V_463 ;
F_85 ( V_9 ) ;
F_146 ( & V_9 -> V_136 . V_263 ) ;
}
static int F_216 ( struct V_8 * V_9 , T_5 V_19 )
{
int V_23 = 0 ;
T_1 V_20 ;
if ( ! ( V_9 -> V_465 & V_19 ) )
goto V_46;
V_20 = V_9 -> V_465 & ~ V_19 ;
V_20 &= 0xFFFF ;
V_23 = F_150 ( V_9 , V_283 ,
V_466 , 0 , 0 , & V_20 ) ;
if ( ! V_23 )
V_9 -> V_465 &= ~ V_19 ;
V_46:
return V_23 ;
}
static int F_217 ( struct V_8 * V_9 , T_5 V_19 )
{
int V_23 = 0 ;
T_1 V_20 ;
if ( V_9 -> V_465 & V_19 )
goto V_46;
V_20 = V_9 -> V_465 | V_19 ;
V_20 &= 0xFFFF ;
V_23 = F_150 ( V_9 , V_283 ,
V_466 , 0 , 0 , & V_20 ) ;
if ( ! V_23 )
V_9 -> V_465 |= V_19 ;
V_46:
return V_23 ;
}
static int F_218 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( V_9 -> V_467 )
goto V_46;
V_23 = F_148 ( V_9 , V_273 ,
V_468 , NULL ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_60 ,
V_17 , V_23 ) ;
goto V_46;
}
V_9 -> V_467 = true ;
V_23 = F_216 ( V_9 , V_469 ) ;
if ( V_23 )
F_5 ( V_9 -> V_16 , L_61 ,
V_17 , V_23 ) ;
V_46:
return V_23 ;
}
static int F_219 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( ! V_9 -> V_467 )
goto V_46;
V_23 = F_217 ( V_9 , V_469 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_62 ,
V_17 , V_23 ) ;
goto V_46;
}
V_23 = F_148 ( V_9 , V_274 ,
V_468 , NULL ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_63 ,
V_17 , V_23 ) ;
F_216 ( V_9 , V_469 ) ;
goto V_46;
}
V_9 -> V_467 = false ;
V_46:
return V_23 ;
}
static void F_220 ( struct V_8 * V_9 )
{
V_9 -> V_467 = false ;
V_9 -> V_465 |= V_469 ;
F_218 ( V_9 ) ;
}
static inline int F_221 ( struct V_8 * V_9 , T_1 * V_359 )
{
return F_150 ( V_9 , V_284 ,
V_470 , 0 , 0 , V_359 ) ;
}
static int F_222 ( struct V_8 * V_9 ,
enum V_471 V_359 )
{
int V_23 ;
T_1 V_472 = 0 ;
V_23 = F_221 ( V_9 , & V_472 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_64 ,
V_17 , V_23 ) ;
goto V_46;
} else if ( V_472 > V_473 ) {
F_5 ( V_9 -> V_16 , L_65 ,
V_17 , V_472 ) ;
V_23 = - V_112 ;
goto V_46;
}
if ( V_472 >= V_359 )
V_23 = F_218 ( V_9 ) ;
else
V_23 = F_219 ( V_9 ) ;
V_46:
return V_23 ;
}
static int F_223 ( struct V_8 * V_9 )
{
return F_222 ( V_9 , V_474 ) ;
}
static inline int F_224 ( struct V_8 * V_9 , T_1 * V_359 )
{
return F_150 ( V_9 , V_284 ,
V_475 , 0 , 0 , V_359 ) ;
}
static void F_225 ( struct V_74 * V_75 )
{
struct V_8 * V_9 ;
int V_23 ;
T_1 V_359 = 0 ;
V_9 = F_44 ( V_75 , struct V_8 , V_450 ) ;
F_226 ( V_9 -> V_16 ) ;
V_23 = F_224 ( V_9 , & V_359 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_66 ,
V_17 , V_23 ) ;
goto V_46;
}
V_359 &= V_9 -> V_465 ;
if ( V_359 & V_469 ) {
V_23 = F_223 ( V_9 ) ;
if ( V_23 < 0 )
F_5 ( V_9 -> V_16 , L_67 ,
V_17 , V_23 ) ;
}
V_46:
F_227 ( V_9 -> V_16 ) ;
return;
}
static void F_228 ( struct V_74 * V_75 )
{
struct V_8 * V_9 ;
unsigned long V_76 ;
T_1 V_476 = 0 ;
T_1 V_477 = 0 ;
int V_23 = 0 ;
int V_45 ;
V_9 = F_44 ( V_75 , struct V_8 , V_478 ) ;
F_226 ( V_9 -> V_16 ) ;
F_56 ( V_9 , false ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( V_9 -> V_96 == V_239 ) {
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
goto V_46;
}
V_9 -> V_96 = V_239 ;
F_229 ( V_9 ) ;
F_213 ( V_9 ) ;
F_230 ( V_9 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_214 (tag, &hba->outstanding_reqs, hba->nutrs)
if ( F_136 ( V_9 , V_45 ) )
V_476 |= 1 << V_45 ;
F_214 (tag, &hba->outstanding_tasks, hba->nutmrs)
if ( F_231 ( V_9 , V_45 ) )
V_477 |= 1 << V_45 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_213 ( V_9 ) ;
F_230 ( V_9 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( V_476 || V_477 || ( V_9 -> V_479 & V_480 ) ||
( ( V_9 -> V_479 & V_481 ) &&
( V_9 -> V_482 & V_483 ) ) ) {
V_23 = F_232 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_68 ,
V_17 ) ;
V_9 -> V_96 = V_242 ;
}
F_233 ( V_9 -> V_80 , 0 ) ;
V_9 -> V_479 = 0 ;
V_9 -> V_482 = 0 ;
}
F_234 ( V_9 ) ;
V_46:
F_55 ( V_9 -> V_80 ) ;
F_70 ( V_9 ) ;
F_227 ( V_9 -> V_16 ) ;
}
static void F_235 ( struct V_8 * V_9 )
{
T_1 V_18 ;
V_18 = F_10 ( V_9 , V_484 ) ;
if ( V_18 & V_485 )
V_9 -> V_486 |= V_483 ;
V_18 = F_10 ( V_9 , V_487 ) ;
if ( V_18 )
V_9 -> V_486 |= V_488 ;
V_18 = F_10 ( V_9 , V_489 ) ;
if ( V_18 )
V_9 -> V_486 |= V_490 ;
V_18 = F_10 ( V_9 , V_491 ) ;
if ( V_18 )
V_9 -> V_486 |= V_492 ;
F_182 ( V_9 -> V_16 , L_69 ,
V_17 , V_9 -> V_486 ) ;
}
static void F_236 ( struct V_8 * V_9 )
{
bool V_493 = false ;
if ( V_9 -> V_494 & V_480 )
V_493 = true ;
if ( V_9 -> V_494 & V_481 ) {
V_9 -> V_486 = 0 ;
F_235 ( V_9 ) ;
if ( V_9 -> V_486 )
V_493 = true ;
}
if ( V_493 ) {
if ( V_9 -> V_96 == V_97 ) {
F_59 ( V_9 -> V_80 ) ;
V_9 -> V_479 |= V_9 -> V_494 ;
V_9 -> V_482 |= V_9 -> V_486 ;
V_9 -> V_96 = V_242 ;
F_60 ( & V_9 -> V_478 ) ;
}
}
}
static void F_230 ( struct V_8 * V_9 )
{
T_1 V_495 ;
V_495 = F_10 ( V_9 , V_496 ) ;
V_9 -> V_497 = V_495 ^ V_9 -> V_99 ;
F_146 ( & V_9 -> V_498 ) ;
}
static void F_237 ( struct V_8 * V_9 , T_1 V_460 )
{
V_9 -> V_494 = V_499 & V_460 ;
if ( V_9 -> V_494 )
F_236 ( V_9 ) ;
if ( V_460 & V_403 )
F_212 ( V_9 , V_460 ) ;
if ( V_460 & V_500 )
F_230 ( V_9 ) ;
if ( V_460 & V_501 )
F_213 ( V_9 ) ;
}
static T_7 V_13 ( int V_12 , void * V_502 )
{
T_1 V_460 ;
T_7 V_503 = V_504 ;
struct V_8 * V_9 = V_502 ;
F_238 ( V_9 -> V_80 -> V_81 ) ;
V_460 = F_10 ( V_9 , V_505 ) ;
if ( V_460 ) {
F_26 ( V_9 , V_460 , V_505 ) ;
F_237 ( V_9 , V_460 ) ;
V_503 = V_506 ;
}
F_239 ( V_9 -> V_80 -> V_81 ) ;
return V_503 ;
}
static int F_231 ( struct V_8 * V_9 , int V_45 )
{
int V_23 = 0 ;
T_1 V_19 = 1 << V_45 ;
unsigned long V_76 ;
if ( ! F_240 ( V_45 , & V_9 -> V_99 ) )
goto V_46;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_26 ( V_9 , ~ ( 1 << V_45 ) , V_507 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_23 = F_8 ( V_9 ,
V_496 ,
V_19 , 0 , 1000 , 1000 ) ;
V_46:
return V_23 ;
}
static int F_241 ( struct V_8 * V_9 , int V_508 , int V_509 ,
T_2 V_510 , T_2 * V_511 )
{
struct V_42 * V_43 ;
struct V_512 * V_513 ;
struct V_238 * V_80 ;
unsigned long V_76 ;
int V_44 ;
int V_23 ;
int V_126 ;
V_80 = V_9 -> V_80 ;
F_144 ( V_9 -> V_514 , F_20 ( V_9 , & V_44 ) ) ;
F_56 ( V_9 , false ) ;
F_46 ( V_80 -> V_81 , V_76 ) ;
V_43 = V_9 -> V_316 ;
V_43 += V_44 ;
V_43 -> V_39 . V_57 = F_114 ( V_208 ) ;
V_43 -> V_39 . V_40 =
F_114 ( V_209 ) ;
V_513 =
(struct V_512 * ) V_43 -> V_515 ;
V_126 = V_9 -> V_155 + V_44 ;
V_513 -> V_39 . V_57 =
F_122 ( V_516 , 0 ,
V_508 , V_126 ) ;
V_513 -> V_39 . V_58 =
F_122 ( 0 , V_510 , 0 , 0 ) ;
V_513 -> V_517 = F_123 ( V_508 ) ;
V_513 -> V_518 = F_123 ( V_509 ) ;
F_90 ( V_44 , & V_9 -> V_99 ) ;
F_26 ( V_9 , 1 << V_44 , V_496 ) ;
F_47 ( V_80 -> V_81 , V_76 ) ;
V_23 = F_242 ( V_9 -> V_498 ,
F_240 ( V_44 , & V_9 -> V_497 ) ,
F_9 ( V_519 ) ) ;
if ( ! V_23 ) {
F_5 ( V_9 -> V_16 , L_70 ,
V_17 , V_510 ) ;
if ( F_231 ( V_9 , V_44 ) )
F_243 ( V_9 -> V_16 , L_71 ,
V_17 , V_44 ) ;
V_23 = - V_26 ;
} else {
V_23 = F_208 ( V_9 , V_44 , V_511 ) ;
}
F_244 ( V_44 , & V_9 -> V_497 ) ;
F_23 ( V_9 , V_44 ) ;
F_146 ( & V_9 -> V_514 ) ;
F_70 ( V_9 ) ;
return V_23 ;
}
static int F_245 ( struct V_176 * V_177 )
{
struct V_238 * V_80 ;
struct V_8 * V_9 ;
unsigned int V_45 ;
T_1 V_50 ;
int V_23 ;
T_2 V_251 = 0xF ;
struct V_36 * V_37 ;
unsigned long V_76 ;
V_80 = V_177 -> V_105 -> V_80 ;
V_9 = F_131 ( V_80 ) ;
V_45 = V_177 -> V_149 -> V_45 ;
V_37 = & V_9 -> V_246 [ V_45 ] ;
V_23 = F_241 ( V_9 , V_37 -> V_213 , 0 , V_520 , & V_251 ) ;
if ( V_23 || V_251 != V_521 ) {
if ( ! V_23 )
V_23 = V_251 ;
goto V_46;
}
F_214 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_9 -> V_246 [ V_50 ] . V_213 == V_37 -> V_213 ) {
V_23 = F_136 ( V_9 , V_50 ) ;
if ( V_23 )
break;
}
}
F_46 ( V_80 -> V_81 , V_76 ) ;
F_213 ( V_9 ) ;
F_47 ( V_80 -> V_81 , V_76 ) ;
V_46:
if ( ! V_23 ) {
V_23 = V_522 ;
} else {
F_5 ( V_9 -> V_16 , L_72 , V_17 , V_23 ) ;
V_23 = V_523 ;
}
return V_23 ;
}
static int F_246 ( struct V_176 * V_177 )
{
struct V_238 * V_80 ;
struct V_8 * V_9 ;
unsigned long V_76 ;
unsigned int V_45 ;
int V_23 = 0 ;
int V_524 ;
T_2 V_251 = 0xF ;
struct V_36 * V_37 ;
T_1 V_18 ;
V_80 = V_177 -> V_105 -> V_80 ;
V_9 = F_131 ( V_80 ) ;
V_45 = V_177 -> V_149 -> V_45 ;
F_56 ( V_9 , false ) ;
if ( ! ( F_240 ( V_45 , & V_9 -> V_124 ) ) )
goto V_46;
V_18 = F_10 ( V_9 , V_127 ) ;
if ( ! ( V_18 & ( 1 << V_45 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_73 ,
V_17 , V_45 ) ;
}
V_37 = & V_9 -> V_246 [ V_45 ] ;
for ( V_524 = 100 ; V_524 ; V_524 -- ) {
V_23 = F_241 ( V_9 , V_37 -> V_213 , V_37 -> V_126 ,
V_525 , & V_251 ) ;
if ( ! V_23 && V_251 == V_526 ) {
break;
} else if ( ! V_23 && V_251 == V_521 ) {
V_18 = F_10 ( V_9 , V_127 ) ;
if ( V_18 & ( 1 << V_45 ) ) {
F_11 ( 100 , 200 ) ;
continue;
}
goto V_46;
} else {
if ( ! V_23 )
V_23 = V_251 ;
goto V_46;
}
}
if ( ! V_524 ) {
V_23 = - V_527 ;
goto V_46;
}
V_23 = F_241 ( V_9 , V_37 -> V_213 , V_37 -> V_126 ,
V_528 , & V_251 ) ;
if ( V_23 || V_251 != V_521 ) {
if ( ! V_23 )
V_23 = V_251 ;
goto V_46;
}
V_23 = F_136 ( V_9 , V_45 ) ;
if ( V_23 )
goto V_46;
F_215 ( V_177 ) ;
F_46 ( V_80 -> V_81 , V_76 ) ;
F_209 ( V_45 , & V_9 -> V_124 ) ;
V_9 -> V_246 [ V_45 ] . V_177 = NULL ;
F_47 ( V_80 -> V_81 , V_76 ) ;
F_24 ( V_45 , & V_9 -> V_98 ) ;
F_146 ( & V_9 -> V_136 . V_263 ) ;
V_46:
if ( ! V_23 ) {
V_23 = V_522 ;
} else {
F_5 ( V_9 -> V_16 , L_72 , V_17 , V_23 ) ;
V_23 = V_523 ;
}
F_70 ( V_9 ) ;
return V_23 ;
}
static int F_177 ( struct V_8 * V_9 )
{
int V_23 ;
unsigned long V_76 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_188 ( V_9 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_23 = F_187 ( V_9 ) ;
if ( V_23 )
goto V_46;
V_23 = F_247 ( V_9 ) ;
if ( ! V_23 && ( V_9 -> V_96 != V_97 ) )
V_23 = - V_170 ;
V_46:
if ( V_23 )
F_5 ( V_9 -> V_16 , L_74 , V_17 , V_23 ) ;
return V_23 ;
}
static int F_232 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
unsigned long V_76 ;
int V_393 = V_529 ;
do {
V_23 = F_177 ( V_9 ) ;
} while ( V_23 && -- V_393 );
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_213 ( V_9 ) ;
F_230 ( V_9 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
return V_23 ;
}
static int F_248 ( struct V_176 * V_177 )
{
int V_23 ;
unsigned long V_76 ;
struct V_8 * V_9 ;
V_9 = F_131 ( V_177 -> V_105 -> V_80 ) ;
F_56 ( V_9 , false ) ;
do {
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( ! ( F_249 ( & V_9 -> V_478 ) ||
V_9 -> V_96 == V_239 ) )
break;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_182 ( V_9 -> V_16 , L_75 , V_17 ) ;
F_61 ( & V_9 -> V_478 ) ;
} while ( 1 );
V_9 -> V_96 = V_239 ;
F_229 ( V_9 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_23 = F_232 ( V_9 ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( ! V_23 ) {
V_23 = V_522 ;
V_9 -> V_96 = V_97 ;
} else {
V_23 = V_523 ;
V_9 -> V_96 = V_242 ;
}
F_234 ( V_9 ) ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
F_70 ( V_9 ) ;
return V_23 ;
}
static T_1 F_250 ( int V_530 , T_1 V_531 , char * V_532 )
{
int V_179 ;
int V_533 ;
T_5 V_534 ;
T_5 V_535 ;
for ( V_179 = V_531 ; V_179 >= 0 ; V_179 -- ) {
V_534 = F_92 ( * ( ( T_5 * ) ( V_532 + 2 * V_179 ) ) ) ;
V_535 = ( V_534 & V_536 ) >>
V_537 ;
V_533 = V_534 & V_538 ;
switch ( V_535 ) {
case V_539 :
V_533 = V_533 / 1000 ;
break;
case V_540 :
V_533 = V_533 * 1000 ;
break;
case V_541 :
V_533 = V_533 * 1000 * 1000 ;
break;
case V_542 :
default:
break;
}
if ( V_530 >= V_533 )
break;
}
if ( V_179 < 0 ) {
V_179 = 0 ;
F_251 ( L_76 , V_17 , V_179 ) ;
}
return ( T_1 ) V_179 ;
}
static T_1 F_252 ( struct V_8 * V_9 ,
T_2 * V_286 , int V_128 )
{
T_1 V_543 = 0 ;
if ( ! V_9 -> V_544 . V_545 || ! V_9 -> V_544 . V_546 ||
! V_9 -> V_544 . V_547 ) {
F_5 ( V_9 -> V_16 ,
L_77 ,
V_17 , V_543 ) ;
goto V_46;
}
if ( V_9 -> V_544 . V_545 )
V_543 = F_250 (
V_9 -> V_544 . V_545 -> V_548 ,
V_549 - 1 ,
& V_286 [ V_550 ] ) ;
if ( V_9 -> V_544 . V_546 )
V_543 = F_250 (
V_9 -> V_544 . V_546 -> V_548 ,
V_543 ,
& V_286 [ V_551 ] ) ;
if ( V_9 -> V_544 . V_547 )
V_543 = F_250 (
V_9 -> V_544 . V_547 -> V_548 ,
V_543 ,
& V_286 [ V_552 ] ) ;
V_46:
return V_543 ;
}
static void F_253 ( struct V_8 * V_9 )
{
int V_10 ;
int V_294 = V_553 ;
T_2 V_286 [ V_553 ] ;
V_10 = F_157 ( V_9 , V_286 , V_294 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_78 ,
V_17 , V_294 , V_10 ) ;
return;
}
V_9 -> V_554 . V_543 =
F_252 ( V_9 ,
V_286 , V_294 ) ;
F_182 ( V_9 -> V_16 , L_79 ,
V_17 , V_9 -> V_554 . V_543 ) ;
V_10 = F_150 ( V_9 , V_283 ,
V_555 , 0 , 0 ,
& V_9 -> V_554 . V_543 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 ,
L_80 ,
V_17 , V_9 -> V_554 . V_543 , V_10 ) ;
}
static int F_254 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_411 * V_556 ;
struct V_411 * V_557 ;
V_9 -> V_430 = F_255 ( V_9 -> V_80 , 0 , 0 ,
F_129 ( V_429 ) , NULL ) ;
if ( F_256 ( V_9 -> V_430 ) ) {
V_10 = F_257 ( V_9 -> V_430 ) ;
V_9 -> V_430 = NULL ;
goto V_46;
}
F_258 ( V_9 -> V_430 ) ;
V_557 = F_255 ( V_9 -> V_80 , 0 , 0 ,
F_129 ( V_558 ) , NULL ) ;
if ( F_256 ( V_557 ) ) {
V_10 = F_257 ( V_557 ) ;
goto V_559;
}
F_258 ( V_557 ) ;
V_556 = F_255 ( V_9 -> V_80 , 0 , 0 ,
F_129 ( V_304 ) , NULL ) ;
if ( F_256 ( V_556 ) ) {
V_10 = F_257 ( V_556 ) ;
goto V_560;
}
F_258 ( V_556 ) ;
goto V_46;
V_560:
F_259 ( V_557 ) ;
V_559:
F_259 ( V_9 -> V_430 ) ;
V_46:
return V_10 ;
}
static int F_247 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = F_195 ( V_9 ) ;
if ( V_10 )
goto V_46;
F_178 ( V_9 ) ;
F_52 ( V_9 ) ;
V_10 = F_197 ( V_9 ) ;
if ( V_10 )
goto V_46;
V_10 = F_185 ( V_9 ) ;
if ( V_10 )
goto V_46;
F_260 ( V_9 ) ;
F_220 ( V_9 ) ;
V_9 -> V_96 = V_97 ;
V_9 -> V_561 = true ;
if ( F_179 ( V_9 ) ) {
F_5 ( V_9 -> V_16 ,
L_81 ,
V_17 ) ;
} else {
V_10 = F_184 ( V_9 , & V_9 -> V_373 . V_374 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_82 ,
V_17 , V_10 ) ;
}
if ( ! F_261 ( V_9 ) && ! V_9 -> V_562 ) {
bool V_563 ;
memset ( & V_9 -> V_417 , 0 , sizeof( V_9 -> V_417 ) ) ;
if ( ! F_148 ( V_9 , V_277 ,
V_564 , & V_563 ) )
V_9 -> V_417 . V_418 = V_563 ;
if ( ! V_9 -> V_565 )
F_253 ( V_9 ) ;
if ( F_254 ( V_9 ) )
goto V_46;
F_262 ( V_9 -> V_80 ) ;
F_227 ( V_9 -> V_16 ) ;
}
if ( ! V_9 -> V_565 )
V_9 -> V_565 = true ;
if ( F_53 ( V_9 ) )
F_54 ( V_9 -> V_86 ) ;
V_46:
if ( V_10 && ! F_261 ( V_9 ) && ! V_9 -> V_562 ) {
F_227 ( V_9 -> V_16 ) ;
F_263 ( V_9 ) ;
}
return V_10 ;
}
static void F_264 ( void * V_534 , T_8 V_566 )
{
struct V_8 * V_9 = (struct V_8 * ) V_534 ;
F_247 ( V_9 ) ;
}
static int F_265 ( struct V_105 * V_16 , struct V_567 * V_568 ,
int V_569 )
{
int V_10 ;
if ( ! V_568 )
return 0 ;
V_10 = F_266 ( V_568 -> V_18 , V_569 ) ;
if ( V_10 < 0 ) {
F_5 ( V_16 , L_83 ,
V_17 , V_568 -> V_116 , V_569 , V_10 ) ;
}
return V_10 ;
}
static inline int F_267 ( struct V_8 * V_9 ,
struct V_567 * V_568 )
{
return F_265 ( V_9 -> V_16 , V_568 , V_570 ) ;
}
static inline int F_268 ( struct V_8 * V_9 ,
struct V_567 * V_568 )
{
return F_265 ( V_9 -> V_16 , V_568 , V_568 -> V_548 ) ;
}
static int F_269 ( struct V_105 * V_16 ,
struct V_567 * V_568 , bool V_571 )
{
int V_10 = 0 ;
struct V_572 * V_18 = V_568 -> V_18 ;
const char * V_116 = V_568 -> V_116 ;
int V_573 , V_574 ;
F_149 ( ! V_568 ) ;
if ( F_270 ( V_18 ) > 0 ) {
V_573 = V_571 ? V_568 -> V_573 : 0 ;
V_10 = F_271 ( V_18 , V_573 , V_568 -> V_575 ) ;
if ( V_10 ) {
F_5 ( V_16 , L_84 ,
V_17 , V_116 , V_10 ) ;
goto V_46;
}
V_574 = V_571 ? V_568 -> V_548 : 0 ;
V_10 = F_265 ( V_16 , V_568 , V_574 ) ;
if ( V_10 )
goto V_46;
}
V_46:
return V_10 ;
}
static int F_272 ( struct V_105 * V_16 , struct V_567 * V_568 )
{
int V_10 = 0 ;
if ( ! V_568 || V_568 -> V_576 )
goto V_46;
V_10 = F_269 ( V_16 , V_568 , true ) ;
if ( ! V_10 )
V_10 = F_273 ( V_568 -> V_18 ) ;
if ( ! V_10 )
V_568 -> V_576 = true ;
else
F_5 ( V_16 , L_85 ,
V_17 , V_568 -> V_116 , V_10 ) ;
V_46:
return V_10 ;
}
static int F_274 ( struct V_105 * V_16 , struct V_567 * V_568 )
{
int V_10 = 0 ;
if ( ! V_568 || ! V_568 -> V_576 )
goto V_46;
V_10 = F_275 ( V_568 -> V_18 ) ;
if ( ! V_10 ) {
F_269 ( V_16 , V_568 , false ) ;
V_568 -> V_576 = false ;
} else {
F_5 ( V_16 , L_86 ,
V_17 , V_568 -> V_116 , V_10 ) ;
}
V_46:
return V_10 ;
}
static int F_276 ( struct V_8 * V_9 , bool V_571 )
{
int V_10 = 0 ;
struct V_105 * V_16 = V_9 -> V_16 ;
struct V_577 * V_374 = & V_9 -> V_544 ;
if ( ! V_374 )
goto V_46;
V_10 = F_277 ( V_16 , V_374 -> V_545 , V_571 ) ;
if ( V_10 )
goto V_46;
V_10 = F_277 ( V_16 , V_374 -> V_546 , V_571 ) ;
if ( V_10 )
goto V_46;
V_10 = F_277 ( V_16 , V_374 -> V_547 , V_571 ) ;
if ( V_10 )
goto V_46;
V_46:
if ( V_10 ) {
F_277 ( V_16 , V_374 -> V_547 , false ) ;
F_277 ( V_16 , V_374 -> V_546 , false ) ;
F_277 ( V_16 , V_374 -> V_545 , false ) ;
}
return V_10 ;
}
static int F_278 ( struct V_8 * V_9 , bool V_571 )
{
struct V_577 * V_374 = & V_9 -> V_544 ;
if ( V_374 )
return F_277 ( V_9 -> V_16 , V_374 -> V_578 , V_571 ) ;
return 0 ;
}
static int F_279 ( struct V_105 * V_16 , struct V_567 * V_568 )
{
int V_10 = 0 ;
if ( ! V_568 )
goto V_46;
V_568 -> V_18 = F_280 ( V_16 , V_568 -> V_116 ) ;
if ( F_256 ( V_568 -> V_18 ) ) {
V_10 = F_257 ( V_568 -> V_18 ) ;
F_5 ( V_16 , L_87 ,
V_17 , V_568 -> V_116 , V_10 ) ;
}
V_46:
return V_10 ;
}
static int F_281 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_105 * V_16 = V_9 -> V_16 ;
struct V_577 * V_374 = & V_9 -> V_544 ;
if ( ! V_374 )
goto V_46;
V_10 = F_279 ( V_16 , V_374 -> V_545 ) ;
if ( V_10 )
goto V_46;
V_10 = F_279 ( V_16 , V_374 -> V_546 ) ;
if ( V_10 )
goto V_46;
V_10 = F_279 ( V_16 , V_374 -> V_547 ) ;
V_46:
return V_10 ;
}
static int F_282 ( struct V_8 * V_9 )
{
struct V_577 * V_374 = & V_9 -> V_544 ;
if ( V_374 )
return F_279 ( V_9 -> V_16 , V_374 -> V_578 ) ;
return 0 ;
}
static int F_67 ( struct V_8 * V_9 , bool V_571 ,
bool V_579 )
{
int V_10 = 0 ;
struct V_580 * V_581 ;
struct V_582 * V_583 = & V_9 -> V_584 ;
unsigned long V_76 ;
if ( ! V_583 || F_283 ( V_583 ) )
goto V_46;
F_284 (clki, head, list) {
if ( ! F_285 ( V_581 -> V_585 ) ) {
if ( V_579 && ! strcmp ( V_581 -> V_116 , L_88 ) )
continue;
if ( V_571 && ! V_581 -> V_576 ) {
V_10 = F_286 ( V_581 -> V_585 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_89 ,
V_17 , V_581 -> V_116 , V_10 ) ;
goto V_46;
}
} else if ( ! V_571 && V_581 -> V_576 ) {
F_287 ( V_581 -> V_585 ) ;
}
V_581 -> V_576 = V_571 ;
F_182 ( V_9 -> V_16 , L_90 , V_17 ,
V_581 -> V_116 , V_571 ? L_91 : L_92 ) ;
}
}
V_10 = F_288 ( V_9 , V_571 ) ;
V_46:
if ( V_10 ) {
F_284 (clki, head, list) {
if ( ! F_285 ( V_581 -> V_585 ) && V_581 -> V_576 )
F_287 ( V_581 -> V_585 ) ;
}
} else if ( V_571 ) {
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_9 -> V_77 . V_82 = V_83 ;
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
}
return V_10 ;
}
static int F_48 ( struct V_8 * V_9 , bool V_571 )
{
return F_67 ( V_9 , V_571 , false ) ;
}
static int F_289 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_580 * V_581 ;
struct V_105 * V_16 = V_9 -> V_16 ;
struct V_582 * V_583 = & V_9 -> V_584 ;
if ( ! V_583 || F_283 ( V_583 ) )
goto V_46;
F_284 (clki, head, list) {
if ( ! V_581 -> V_116 )
continue;
V_581 -> V_585 = F_290 ( V_16 , V_581 -> V_116 ) ;
if ( F_256 ( V_581 -> V_585 ) ) {
V_10 = F_257 ( V_581 -> V_585 ) ;
F_5 ( V_16 , L_93 ,
V_17 , V_581 -> V_116 , V_10 ) ;
goto V_46;
}
if ( V_581 -> V_586 ) {
V_10 = F_291 ( V_581 -> V_585 , V_581 -> V_586 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_94 ,
V_17 , V_581 -> V_116 ,
V_581 -> V_586 , V_10 ) ;
goto V_46;
}
V_581 -> V_587 = V_581 -> V_586 ;
}
F_182 ( V_16 , L_95 , V_17 ,
V_581 -> V_116 , F_292 ( V_581 -> V_585 ) ) ;
}
V_46:
return V_10 ;
}
static int F_293 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( ! V_9 -> V_588 )
goto V_46;
V_23 = F_294 ( V_9 ) ;
if ( V_23 )
goto V_46;
V_23 = F_295 ( V_9 , true ) ;
if ( V_23 )
goto V_589;
goto V_46;
V_589:
F_296 ( V_9 ) ;
V_46:
if ( V_23 )
F_5 ( V_9 -> V_16 , L_96 ,
V_17 , F_297 ( V_9 ) , V_23 ) ;
return V_23 ;
}
static void F_298 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_588 )
return;
F_288 ( V_9 , false ) ;
F_295 ( V_9 , false ) ;
F_296 ( V_9 ) ;
}
static int F_299 ( struct V_8 * V_9 )
{
int V_23 ;
V_23 = F_282 ( V_9 ) ;
if ( V_23 )
goto V_46;
V_23 = F_278 ( V_9 , true ) ;
if ( V_23 )
goto V_46;
V_23 = F_289 ( V_9 ) ;
if ( V_23 )
goto V_590;
V_23 = F_48 ( V_9 , true ) ;
if ( V_23 )
goto V_590;
V_23 = F_281 ( V_9 ) ;
if ( V_23 )
goto V_591;
V_23 = F_276 ( V_9 , true ) ;
if ( V_23 )
goto V_591;
V_23 = F_293 ( V_9 ) ;
if ( V_23 )
goto V_592;
V_9 -> V_593 = true ;
goto V_46;
V_592:
F_276 ( V_9 , false ) ;
V_591:
F_48 ( V_9 , false ) ;
V_590:
F_278 ( V_9 , false ) ;
V_46:
return V_23 ;
}
static void F_263 ( struct V_8 * V_9 )
{
if ( V_9 -> V_593 ) {
F_298 ( V_9 ) ;
F_276 ( V_9 , false ) ;
F_48 ( V_9 , false ) ;
F_278 ( V_9 , false ) ;
V_9 -> V_593 = false ;
}
}
static int
F_300 ( struct V_8 * V_9 , struct V_411 * V_594 )
{
unsigned char V_177 [ 6 ] = { V_595 ,
0 ,
0 ,
0 ,
V_133 ,
0 } ;
char * V_596 ;
int V_10 ;
V_596 = F_301 ( V_133 , V_298 ) ;
if ( ! V_596 ) {
V_10 = - V_299 ;
goto V_46;
}
V_10 = F_302 ( V_594 , V_177 , V_197 , V_596 ,
V_133 , NULL ,
F_9 ( 1000 ) , 3 , NULL , V_597 ) ;
if ( V_10 )
F_251 ( L_72 , V_17 , V_10 ) ;
F_155 ( V_596 ) ;
V_46:
return V_10 ;
}
static int F_303 ( struct V_8 * V_9 ,
enum V_1 V_381 )
{
unsigned char V_177 [ 6 ] = { V_598 } ;
struct V_599 V_600 ;
struct V_411 * V_594 ;
unsigned long V_76 ;
int V_10 ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
V_594 = V_9 -> V_430 ;
if ( V_594 ) {
V_10 = F_304 ( V_594 ) ;
if ( ! V_10 && ! F_305 ( V_594 ) ) {
V_10 = - V_601 ;
F_258 ( V_594 ) ;
}
} else {
V_10 = - V_601 ;
}
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( V_10 )
return V_10 ;
V_9 -> V_80 -> V_602 = 1 ;
if ( V_9 -> V_561 ) {
V_10 = F_300 ( V_9 , V_594 ) ;
if ( V_10 )
goto V_46;
V_9 -> V_561 = false ;
}
V_177 [ 4 ] = V_381 << 4 ;
V_10 = F_302 ( V_594 , V_177 , V_228 , NULL , 0 , & V_600 ,
V_603 , 0 , NULL , V_597 ) ;
if ( V_10 ) {
F_306 ( V_604 , V_594 ,
L_97 ,
V_381 , V_10 ) ;
if ( F_307 ( V_10 ) & V_605 )
F_308 ( V_594 , NULL , & V_600 ) ;
}
if ( ! V_10 )
V_9 -> V_606 = V_381 ;
V_46:
F_258 ( V_594 ) ;
V_9 -> V_80 -> V_602 = 0 ;
return V_10 ;
}
static int F_309 ( struct V_8 * V_9 ,
enum V_6 V_607 ,
int V_608 )
{
int V_10 = 0 ;
if ( V_607 == V_9 -> V_6 )
return 0 ;
if ( V_607 == V_609 ) {
V_10 = F_63 ( V_9 ) ;
if ( ! V_10 )
F_64 ( V_9 ) ;
else
goto V_46;
}
else if ( ( V_607 == V_610 ) &&
( ! V_608 || ( V_608 &&
! V_9 -> V_467 ) ) ) {
F_188 ( V_9 ) ;
F_176 ( V_9 ) ;
}
V_46:
return V_10 ;
}
static void F_310 ( struct V_8 * V_9 )
{
if ( F_311 ( V_9 ) && F_312 ( V_9 ) &&
! V_9 -> V_417 . V_419 ) {
F_276 ( V_9 , false ) ;
} else if ( ! F_313 ( V_9 ) ) {
F_277 ( V_9 -> V_16 , V_9 -> V_544 . V_545 , false ) ;
if ( ! F_66 ( V_9 ) ) {
F_267 ( V_9 , V_9 -> V_544 . V_546 ) ;
F_267 ( V_9 , V_9 -> V_544 . V_547 ) ;
}
}
}
static int F_314 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( F_311 ( V_9 ) && F_312 ( V_9 ) &&
! V_9 -> V_417 . V_419 ) {
V_10 = F_276 ( V_9 , true ) ;
} else if ( ! F_313 ( V_9 ) ) {
V_10 = F_277 ( V_9 -> V_16 , V_9 -> V_544 . V_545 , true ) ;
if ( ! V_10 && ! F_66 ( V_9 ) ) {
V_10 = F_268 ( V_9 , V_9 -> V_544 . V_546 ) ;
if ( V_10 )
goto V_611;
V_10 = F_268 ( V_9 , V_9 -> V_544 . V_547 ) ;
if ( V_10 )
goto V_612;
}
}
goto V_46;
V_612:
F_267 ( V_9 , V_9 -> V_544 . V_546 ) ;
V_611:
F_277 ( V_9 -> V_16 , V_9 -> V_544 . V_545 , false ) ;
V_46:
return V_10 ;
}
static void F_315 ( struct V_8 * V_9 )
{
if ( F_312 ( V_9 ) )
F_278 ( V_9 , false ) ;
}
static void F_316 ( struct V_8 * V_9 )
{
if ( F_312 ( V_9 ) )
F_278 ( V_9 , true ) ;
}
static int F_317 ( struct V_8 * V_9 , enum V_613 V_614 )
{
int V_10 = 0 ;
enum V_2 V_615 ;
enum V_1 V_616 ;
enum V_6 V_607 ;
V_9 -> V_562 = 1 ;
if ( ! F_318 ( V_614 ) ) {
V_615 = F_319 ( V_614 ) ?
V_9 -> V_617 : V_9 -> V_618 ;
V_616 = F_1 ( V_615 ) ;
V_607 = F_2 ( V_615 ) ;
} else {
V_616 = V_619 ;
V_607 = V_610 ;
}
F_56 ( V_9 , false ) ;
V_9 -> V_77 . V_85 = true ;
if ( V_616 == V_620 &&
V_607 == V_621 ) {
goto V_622;
}
if ( ( V_616 == V_9 -> V_606 ) &&
( V_607 == V_9 -> V_6 ) )
goto V_46;
if ( ! F_313 ( V_9 ) || ! F_66 ( V_9 ) ) {
V_10 = - V_112 ;
goto V_46;
}
if ( F_319 ( V_614 ) ) {
if ( F_320 ( V_9 ) ) {
V_10 = F_223 ( V_9 ) ;
if ( V_10 )
goto V_623;
} else {
F_219 ( V_9 ) ;
}
}
if ( ( V_616 != V_9 -> V_606 ) &&
( ( F_319 ( V_614 ) && ! V_9 -> V_467 ) ||
! F_319 ( V_614 ) ) ) {
F_219 ( V_9 ) ;
V_10 = F_303 ( V_9 , V_616 ) ;
if ( V_10 )
goto V_623;
}
V_10 = F_309 ( V_9 , V_607 , 1 ) ;
if ( V_10 )
goto V_624;
F_310 ( V_9 ) ;
V_622:
if ( F_53 ( V_9 ) ) {
F_65 ( V_9 -> V_86 ) ;
V_9 -> V_102 . V_103 = 0 ;
}
V_10 = F_321 ( V_9 , V_614 ) ;
if ( V_10 )
goto V_625;
V_10 = F_288 ( V_9 , false ) ;
if ( V_10 )
goto V_626;
if ( ! F_66 ( V_9 ) )
F_48 ( V_9 , false ) ;
else
F_67 ( V_9 , false , true ) ;
V_9 -> V_77 . V_82 = V_92 ;
F_6 ( V_9 ) ;
F_315 ( V_9 ) ;
goto V_46;
V_626:
F_322 ( V_9 , V_614 ) ;
V_625:
F_314 ( V_9 ) ;
if ( F_50 ( V_9 ) && ! F_51 ( V_9 ) )
F_52 ( V_9 ) ;
else if ( F_312 ( V_9 ) )
F_177 ( V_9 ) ;
V_624:
if ( ! F_303 ( V_9 , V_620 ) )
F_219 ( V_9 ) ;
V_623:
V_9 -> V_77 . V_85 = false ;
F_70 ( V_9 ) ;
V_46:
V_9 -> V_562 = 0 ;
return V_10 ;
}
static int F_323 ( struct V_8 * V_9 , enum V_613 V_614 )
{
int V_10 ;
enum V_6 V_627 ;
V_9 -> V_562 = 1 ;
V_627 = V_9 -> V_6 ;
F_316 ( V_9 ) ;
V_10 = F_48 ( V_9 , true ) ;
if ( V_10 )
goto V_46;
V_10 = F_3 ( V_9 ) ;
if ( V_10 )
goto V_628;
V_10 = F_314 ( V_9 ) ;
if ( V_10 )
goto V_628;
V_10 = F_322 ( V_9 , V_614 ) ;
if ( V_10 )
goto V_629;
if ( F_50 ( V_9 ) ) {
V_10 = F_51 ( V_9 ) ;
if ( ! V_10 )
F_52 ( V_9 ) ;
else
goto V_630;
} else if ( F_312 ( V_9 ) ) {
V_10 = F_177 ( V_9 ) ;
if ( V_10 || ! F_66 ( V_9 ) )
goto V_630;
}
if ( ! F_313 ( V_9 ) ) {
V_10 = F_303 ( V_9 , V_620 ) ;
if ( V_10 )
goto V_631;
}
F_223 ( V_9 ) ;
V_9 -> V_77 . V_85 = false ;
if ( F_53 ( V_9 ) )
F_54 ( V_9 -> V_86 ) ;
F_70 ( V_9 ) ;
goto V_46;
V_631:
F_309 ( V_9 , V_627 , 0 ) ;
V_630:
F_321 ( V_9 , V_614 ) ;
V_629:
F_310 ( V_9 ) ;
V_628:
F_6 ( V_9 ) ;
F_48 ( V_9 , false ) ;
V_46:
V_9 -> V_562 = 0 ;
return V_10 ;
}
int F_324 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( ! V_9 || ! V_9 -> V_593 )
return 0 ;
if ( F_325 ( V_9 -> V_16 ) ) {
if ( V_9 -> V_617 == V_9 -> V_618 )
if ( ( F_1 ( V_9 -> V_618 ) ==
V_9 -> V_606 ) && ! V_9 -> V_467 )
goto V_46;
V_10 = F_326 ( V_9 ) ;
if ( V_10 )
goto V_46;
}
V_10 = F_317 ( V_9 , V_632 ) ;
V_46:
if ( ! V_10 )
V_9 -> V_633 = true ;
return V_10 ;
}
int F_327 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_593 || F_325 ( V_9 -> V_16 ) )
return 0 ;
return F_323 ( V_9 , V_632 ) ;
}
int F_328 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_593 )
return 0 ;
return F_317 ( V_9 , V_634 ) ;
}
int F_326 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_593 )
return 0 ;
else
return F_323 ( V_9 , V_634 ) ;
}
int F_329 ( struct V_8 * V_9 )
{
return 0 ;
}
int F_330 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( F_311 ( V_9 ) && F_312 ( V_9 ) )
goto V_46;
if ( F_325 ( V_9 -> V_16 ) ) {
V_10 = F_326 ( V_9 ) ;
if ( V_10 )
goto V_46;
}
V_10 = F_317 ( V_9 , V_635 ) ;
V_46:
if ( V_10 )
F_5 ( V_9 -> V_16 , L_98 , V_17 , V_10 ) ;
return 0 ;
}
void F_331 ( struct V_8 * V_9 )
{
F_332 ( V_9 -> V_80 ) ;
F_119 ( V_9 , V_9 -> V_636 ) ;
F_188 ( V_9 ) ;
F_333 ( V_9 -> V_80 ) ;
F_80 ( V_9 ) ;
if ( F_53 ( V_9 ) )
F_334 ( V_9 -> V_86 ) ;
F_263 ( V_9 ) ;
}
void F_335 ( struct V_8 * V_9 )
{
F_333 ( V_9 -> V_80 ) ;
}
static int F_336 ( struct V_8 * V_9 )
{
if ( V_9 -> V_153 & V_637 ) {
if ( ! F_337 ( V_9 -> V_16 , F_338 ( 64 ) ) )
return 0 ;
}
return F_337 ( V_9 -> V_16 , F_338 ( 32 ) ) ;
}
int F_339 ( struct V_105 * V_16 , struct V_8 * * V_638 )
{
struct V_238 * V_80 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
if ( ! V_16 ) {
F_5 ( V_16 ,
L_99 ) ;
V_23 = - V_601 ;
goto V_639;
}
V_80 = F_340 ( & V_640 ,
sizeof( struct V_8 ) ) ;
if ( ! V_80 ) {
F_5 ( V_16 , L_100 ) ;
V_23 = - V_299 ;
goto V_639;
}
V_9 = F_131 ( V_80 ) ;
V_9 -> V_80 = V_80 ;
V_9 -> V_16 = V_16 ;
* V_638 = V_9 ;
V_639:
return V_23 ;
}
static int F_341 ( struct V_8 * V_9 , bool V_641 )
{
int V_10 = 0 ;
struct V_580 * V_581 ;
struct V_582 * V_583 = & V_9 -> V_584 ;
if ( ! V_583 || F_283 ( V_583 ) )
goto V_46;
V_10 = F_342 ( V_9 , V_641 , V_392 ) ;
if ( V_10 )
return V_10 ;
F_284 (clki, head, list) {
if ( ! F_285 ( V_581 -> V_585 ) ) {
if ( V_641 && V_581 -> V_586 ) {
if ( V_581 -> V_587 == V_581 -> V_586 )
continue;
V_10 = F_291 ( V_581 -> V_585 , V_581 -> V_586 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_94 ,
V_17 , V_581 -> V_116 ,
V_581 -> V_586 , V_10 ) ;
break;
}
V_581 -> V_587 = V_581 -> V_586 ;
} else if ( ! V_641 && V_581 -> V_642 ) {
if ( V_581 -> V_587 == V_581 -> V_642 )
continue;
V_10 = F_291 ( V_581 -> V_585 , V_581 -> V_642 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_94 ,
V_17 , V_581 -> V_116 ,
V_581 -> V_642 , V_10 ) ;
break;
}
V_581 -> V_587 = V_581 -> V_642 ;
}
}
F_182 ( V_9 -> V_16 , L_95 , V_17 ,
V_581 -> V_116 , F_292 ( V_581 -> V_585 ) ) ;
}
V_10 = F_342 ( V_9 , V_641 , V_389 ) ;
V_46:
return V_10 ;
}
static int F_343 ( struct V_105 * V_16 ,
unsigned long * V_643 , T_1 V_76 )
{
int V_23 = 0 ;
struct V_8 * V_9 = F_72 ( V_16 ) ;
if ( ! F_53 ( V_9 ) )
return - V_112 ;
if ( * V_643 == V_644 )
V_23 = F_341 ( V_9 , true ) ;
else if ( * V_643 == 0 )
V_23 = F_341 ( V_9 , false ) ;
return V_23 ;
}
static int F_344 ( struct V_105 * V_16 ,
struct V_645 * V_646 )
{
struct V_8 * V_9 = F_72 ( V_16 ) ;
struct V_122 * V_123 = & V_9 -> V_102 ;
unsigned long V_76 ;
if ( ! F_53 ( V_9 ) )
return - V_112 ;
memset ( V_646 , 0 , sizeof( * V_646 ) ) ;
F_46 ( V_9 -> V_80 -> V_81 , V_76 ) ;
if ( ! V_123 -> V_103 )
goto V_647;
if ( V_123 -> V_120 )
V_123 -> V_125 += F_86 ( F_87 ( F_84 () ,
V_123 -> V_121 ) ) ;
V_646 -> V_648 = F_345 ( ( long ) V_25 -
( long ) V_123 -> V_103 ) ;
V_646 -> V_649 = V_123 -> V_125 ;
V_647:
V_123 -> V_103 = V_25 ;
V_123 -> V_125 = 0 ;
if ( V_9 -> V_124 ) {
V_123 -> V_121 = F_84 () ;
V_123 -> V_120 = true ;
} else {
V_123 -> V_121 = F_88 ( 0 , 0 ) ;
V_123 -> V_120 = false ;
}
F_47 ( V_9 -> V_80 -> V_81 , V_76 ) ;
return 0 ;
}
int F_346 ( struct V_8 * V_9 , void T_9 * V_650 , unsigned int V_12 )
{
int V_23 ;
struct V_238 * V_80 = V_9 -> V_80 ;
struct V_105 * V_16 = V_9 -> V_16 ;
if ( ! V_650 ) {
F_5 ( V_9 -> V_16 ,
L_101 ) ;
V_23 = - V_601 ;
goto V_639;
}
V_9 -> V_650 = V_650 ;
V_9 -> V_12 = V_12 ;
V_23 = F_299 ( V_9 ) ;
if ( V_23 )
goto V_639;
F_97 ( V_9 ) ;
V_9 -> V_27 = F_14 ( V_9 ) ;
V_9 -> V_636 = F_13 ( V_9 ) ;
V_23 = F_336 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_102 ) ;
goto V_651;
}
V_23 = F_159 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_103 ) ;
goto V_651;
}
F_162 ( V_9 ) ;
V_80 -> V_652 = V_9 -> V_155 ;
V_80 -> V_653 = V_9 -> V_155 ;
V_80 -> V_654 = V_655 ;
V_80 -> V_656 = V_657 ;
V_80 -> V_658 = V_659 ;
V_80 -> V_660 = V_80 -> V_661 ;
V_80 -> V_662 = V_663 ;
V_9 -> V_373 . V_375 = false ;
F_347 ( & V_9 -> V_498 ) ;
F_347 ( & V_9 -> V_514 ) ;
F_77 ( & V_9 -> V_478 , F_228 ) ;
F_77 ( & V_9 -> V_450 , F_225 ) ;
F_348 ( & V_9 -> V_171 ) ;
F_348 ( & V_9 -> V_136 . V_272 ) ;
F_347 ( & V_9 -> V_136 . V_263 ) ;
F_75 ( V_9 ) ;
V_23 = F_349 ( V_16 , V_12 , V_13 , V_14 , V_15 , V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_104 ) ;
goto V_664;
} else {
V_9 -> V_11 = true ;
}
V_23 = F_350 ( V_80 , V_9 -> V_16 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_105 ) ;
goto V_664;
}
V_23 = F_187 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_106 ) ;
goto V_665;
}
if ( F_53 ( V_9 ) ) {
V_9 -> V_86 = F_351 ( V_16 , & V_666 ,
L_107 , NULL ) ;
if ( F_256 ( V_9 -> V_86 ) ) {
F_5 ( V_9 -> V_16 , L_108 ,
F_257 ( V_9 -> V_86 ) ) ;
goto V_665;
}
F_65 ( V_9 -> V_86 ) ;
V_9 -> V_102 . V_103 = 0 ;
}
F_226 ( V_16 ) ;
F_352 ( V_9 ) ;
F_353 ( F_264 , V_9 ) ;
return 0 ;
V_665:
F_332 ( V_9 -> V_80 ) ;
V_664:
F_80 ( V_9 ) ;
V_651:
V_9 -> V_11 = false ;
F_333 ( V_80 ) ;
F_263 ( V_9 ) ;
V_639:
return V_23 ;
}
