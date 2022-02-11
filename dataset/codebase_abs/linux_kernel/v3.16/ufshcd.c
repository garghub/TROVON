static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , unsigned long V_6 , unsigned long V_7 )
{
int V_8 = 0 ;
unsigned long V_9 = V_10 + F_2 ( V_7 ) ;
V_5 = V_5 & V_4 ;
while ( ( F_3 ( V_2 , V_3 ) & V_4 ) != V_5 ) {
F_4 ( V_6 , V_6 + 50 ) ;
if ( F_5 ( V_10 , V_9 ) ) {
if ( ( F_3 ( V_2 , V_3 ) & V_4 ) != V_5 )
V_8 = - V_11 ;
break;
}
}
return V_8 ;
}
static inline T_1 F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 == V_13 )
return V_14 ;
else
return V_15 ;
}
static inline T_1 F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_16 ) ;
}
static inline int F_8 ( T_1 V_17 )
{
return ( V_18 & V_17 ) ? 1 : 0 ;
}
static inline int F_9 ( struct V_19 * V_20 )
{
return F_10 ( V_20 -> V_21 -> V_22 . V_23 ) & V_24 ;
}
static inline int
F_11 ( struct V_25 * V_26 )
{
return F_10 ( V_26 -> V_22 . V_23 ) & V_24 ;
}
static bool F_12 ( struct V_1 * V_2 , int * V_27 )
{
int V_28 ;
bool V_29 = false ;
if ( ! V_27 )
goto V_30;
do {
V_28 = F_13 ( & V_2 -> V_31 , V_2 -> V_32 ) ;
if ( V_28 >= V_2 -> V_32 )
goto V_30;
} while ( F_14 ( V_28 , & V_2 -> V_31 ) );
* V_27 = V_28 ;
V_29 = true ;
V_30:
return V_29 ;
}
static inline void F_15 ( struct V_1 * V_2 , int V_33 )
{
F_16 ( V_33 , & V_2 -> V_31 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , T_1 V_34 )
{
F_18 ( V_2 , ~ ( 1 << V_34 ) , V_35 ) ;
}
static inline int F_19 ( T_1 V_3 )
{
return ( ( ( V_3 ) & ( 0xFF ) ) >> 1 ) ^ ( 0x07 ) ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_36 ) &
V_37 ;
}
static inline T_1 F_21 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_38 ) ;
}
static inline int
F_22 ( struct V_39 * V_40 )
{
return F_23 ( V_40 -> V_22 . V_41 ) >> 24 ;
}
static inline int
F_24 ( struct V_39 * V_40 )
{
return F_23 ( V_40 -> V_22 . V_42 ) & V_43 ;
}
static inline unsigned int
F_25 ( struct V_39 * V_40 )
{
return F_23 ( V_40 -> V_22 . V_23 ) &
V_44 ;
}
static inline bool F_26 ( struct V_39 * V_40 )
{
return F_23 ( V_40 -> V_22 . V_23 ) &
V_45 ? true : false ;
}
static inline void
F_27 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_46 |
V_47 ,
V_48 ) ;
}
static inline void
F_28 ( struct V_1 * V_2 , T_2 V_49 , T_2 V_50 )
{
F_18 ( V_2 , V_46 | V_51 |
F_29 ( V_49 ) |
F_30 ( V_50 ) ,
V_48 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_52 ,
V_53 ) ;
F_18 ( V_2 , V_54 ,
V_55 ) ;
}
static inline void F_32 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_56 , V_57 ) ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_57 ) & 0x1 ) ? 0 : 1 ;
}
static inline
void F_34 ( struct V_1 * V_2 , unsigned int V_58 )
{
F_35 ( V_58 , & V_2 -> V_59 ) ;
F_18 ( V_2 , 1 << V_58 , V_60 ) ;
}
static inline void F_36 ( struct V_19 * V_20 )
{
int V_61 ;
if ( V_20 -> V_62 &&
F_25 ( V_20 -> V_40 ) ) {
V_61 = F_37 ( V_20 -> V_40 -> V_63 . V_64 ) ;
memcpy ( V_20 -> V_62 ,
V_20 -> V_40 -> V_63 . V_65 ,
F_38 ( int , V_61 , V_66 ) ) ;
}
}
static
void F_39 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_67 * V_68 = & V_2 -> V_69 . V_70 . V_71 ;
V_68 -> V_71 = F_24 ( V_20 -> V_40 ) >>
V_72 ;
memcpy ( & V_68 -> V_73 , & V_20 -> V_40 -> V_74 , V_75 ) ;
if ( V_20 -> V_40 -> V_74 . V_76 == V_77 ) {
T_2 * V_78 = ( T_2 * ) & V_20 -> V_40 +
V_79 ;
T_3 V_61 ;
V_61 = F_23 ( V_20 -> V_40 -> V_22 . V_23 ) &
V_80 ;
memcpy ( V_2 -> V_69 . V_70 . V_81 , V_78 ,
F_38 ( T_3 , V_61 , V_82 ) ) ;
}
}
static inline void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_83 = F_3 ( V_2 , V_84 ) ;
V_2 -> V_85 = ( V_2 -> V_83 & V_86 ) + 1 ;
V_2 -> V_32 =
( ( V_2 -> V_83 & V_87 ) >> 16 ) + 1 ;
}
static inline bool F_41 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_88 ) & V_89 )
return true ;
else
return false ;
}
static inline T_2 F_42 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_88 ) >> 8 ) & 0x7 ;
}
static inline void
F_43 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
F_44 ( V_2 -> V_92 ) ;
V_2 -> V_92 = V_91 ;
F_18 ( V_2 , V_91 -> V_93 , V_94 ) ;
F_18 ( V_2 , V_91 -> V_95 , V_36 ) ;
F_18 ( V_2 , V_91 -> V_96 , V_38 ) ;
F_18 ( V_2 , V_91 -> V_97 & V_98 ,
V_99 ) ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
int V_29 ;
unsigned long V_100 ;
if ( F_46 ( & V_91 -> V_101 ,
F_2 ( V_102 ) ) )
V_29 = V_91 -> V_95 & V_37 ;
else
V_29 = - V_11 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_92 = NULL ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
return V_29 ;
}
static int
F_49 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
int V_29 ;
unsigned long V_100 ;
if ( ! F_41 ( V_2 ) ) {
F_50 ( V_2 -> V_105 ,
L_1 ) ;
return - V_106 ;
}
F_51 ( & V_91 -> V_101 ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_43 ( V_2 , V_91 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_29 = F_45 ( V_2 , V_91 ) ;
return V_29 ;
}
static int
F_52 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
int V_29 ;
F_53 ( & V_2 -> V_107 ) ;
V_29 = F_49 ( V_2 , V_91 ) ;
F_54 ( & V_2 -> V_107 ) ;
return V_29 ;
}
static int F_55 ( struct V_19 * V_20 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
int V_114 ;
int V_115 ;
V_113 = V_20 -> V_113 ;
V_114 = F_56 ( V_113 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( V_114 ) {
V_20 -> V_21 -> V_116 =
F_57 ( ( T_3 ) ( V_114 ) ) ;
V_109 = (struct V_108 * ) V_20 -> V_117 ;
F_58 (cmd, sg, sg_segments, i) {
V_109 [ V_115 ] . V_118 =
F_59 ( ( ( T_1 ) F_60 ( V_111 ) ) - 1 ) ;
V_109 [ V_115 ] . V_119 =
F_59 ( F_61 ( V_111 -> V_120 ) ) ;
V_109 [ V_115 ] . V_121 =
F_59 ( F_62 ( V_111 -> V_120 ) ) ;
}
} else {
V_20 -> V_21 -> V_116 = 0 ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_122 )
{
T_1 V_123 = F_3 ( V_2 , V_124 ) ;
if ( V_2 -> V_12 == V_13 ) {
T_1 V_125 ;
V_125 = V_123 & V_126 ;
V_123 = V_125 | ( ( V_123 ^ V_122 ) & V_122 ) ;
} else {
V_123 |= V_122 ;
}
F_18 ( V_2 , V_123 , V_124 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_1 V_122 )
{
T_1 V_123 = F_3 ( V_2 , V_124 ) ;
if ( V_2 -> V_12 == V_13 ) {
T_1 V_125 ;
V_125 = ( V_123 & V_126 ) &
~ ( V_122 & V_126 ) ;
V_123 = V_125 | ( ( V_123 & V_122 ) & ~ V_126 ) ;
} else {
V_123 &= ~ V_122 ;
}
F_18 ( V_2 , V_123 , V_124 ) ;
}
static void F_65 ( struct V_19 * V_20 ,
T_1 * V_127 , enum V_128 V_129 )
{
struct V_130 * V_131 = V_20 -> V_21 ;
T_1 V_132 ;
T_1 V_41 ;
if ( V_129 == V_133 ) {
V_132 = V_134 ;
* V_127 = V_135 ;
} else if ( V_129 == V_136 ) {
V_132 = V_137 ;
* V_127 = V_138 ;
} else {
V_132 = V_139 ;
* V_127 = V_140 ;
}
V_41 = V_132 | ( V_20 -> V_141
<< V_142 ) ;
if ( V_20 -> V_143 )
V_41 |= V_144 ;
V_131 -> V_22 . V_41 = F_59 ( V_41 ) ;
V_131 -> V_22 . V_23 =
F_59 ( V_145 ) ;
}
static
void F_66 ( struct V_19 * V_20 , T_1 V_127 )
{
struct V_146 * V_147 = V_20 -> V_147 ;
V_147 -> V_22 . V_41 = F_67 (
V_148 , V_127 ,
V_20 -> V_149 , V_20 -> V_58 ) ;
V_147 -> V_22 . V_42 = F_67 (
V_150 , 0 , 0 , 0 ) ;
V_147 -> V_22 . V_23 = 0 ;
V_147 -> V_151 . V_152 =
F_68 ( V_20 -> V_113 -> V_153 . V_154 ) ;
memcpy ( V_147 -> V_151 . V_155 , V_20 -> V_113 -> V_156 ,
( F_38 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ) ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_19 * V_20 , T_1 V_127 )
{
struct V_146 * V_147 = V_20 -> V_147 ;
struct V_157 * V_70 = & V_2 -> V_69 . V_70 ;
T_3 V_61 = F_37 ( V_70 -> V_158 . V_159 . V_154 ) ;
T_2 * V_78 = ( T_2 * ) V_20 -> V_147 + V_79 ;
V_147 -> V_22 . V_41 = F_67 (
V_160 , V_127 ,
V_20 -> V_149 , V_20 -> V_58 ) ;
V_147 -> V_22 . V_42 = F_67 (
0 , V_70 -> V_158 . V_161 , 0 , 0 ) ;
V_147 -> V_22 . V_23 = F_67 (
0 , 0 , V_61 >> 8 , ( T_2 ) V_61 ) ;
memcpy ( & V_147 -> V_74 , & V_70 -> V_158 . V_159 ,
V_75 ) ;
if ( ( V_61 > 0 ) && ( V_70 -> V_158 . V_159 . V_76 ==
V_162 ) ) {
memcpy ( V_78 , V_70 -> V_81 ,
F_38 ( T_3 , V_61 , V_82 ) ) ;
}
}
static inline void F_70 ( struct V_19 * V_20 )
{
struct V_146 * V_147 = V_20 -> V_147 ;
memset ( V_147 , 0 , sizeof( struct V_146 ) ) ;
V_147 -> V_22 . V_41 =
F_67 (
V_163 , 0 , 0 , V_20 -> V_58 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
T_1 V_127 ;
int V_29 = 0 ;
switch ( V_20 -> V_141 ) {
case V_164 :
if ( F_72 ( V_20 -> V_113 ) ) {
F_65 ( V_20 , & V_127 ,
V_20 -> V_113 -> V_165 ) ;
F_66 ( V_20 , V_127 ) ;
} else {
V_29 = - V_166 ;
}
break;
case V_167 :
F_65 ( V_20 , & V_127 , V_168 ) ;
if ( V_2 -> V_69 . type == V_169 )
F_69 (
V_2 , V_20 , V_127 ) ;
else if ( V_2 -> V_69 . type == V_170 )
F_70 ( V_20 ) ;
else
V_29 = - V_166 ;
break;
case V_171 :
V_29 = - V_172 ;
F_50 ( V_2 -> V_105 , L_2 ,
V_173 ) ;
break;
default:
V_29 = - V_172 ;
F_50 ( V_2 -> V_105 , L_3 ,
V_173 , V_20 -> V_141 ) ;
break;
}
return V_29 ;
}
static int F_73 ( struct V_174 * V_103 , struct V_112 * V_113 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned long V_100 ;
int V_28 ;
int V_8 = 0 ;
V_2 = F_74 ( V_103 ) ;
V_28 = V_113 -> V_158 -> V_28 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
switch ( V_2 -> V_175 ) {
case V_176 :
break;
case V_177 :
V_8 = V_178 ;
goto V_179;
case V_180 :
F_75 ( V_113 , V_181 ) ;
V_113 -> V_182 ( V_113 ) ;
goto V_179;
default:
F_76 ( V_2 -> V_105 , 1 , L_4 ,
V_173 , V_2 -> V_175 ) ;
F_75 ( V_113 , V_183 ) ;
V_113 -> V_182 ( V_113 ) ;
goto V_179;
}
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
if ( F_14 ( V_28 , & V_2 -> V_184 ) ) {
V_8 = V_178 ;
goto V_30;
}
V_20 = & V_2 -> V_185 [ V_28 ] ;
F_44 ( V_20 -> V_113 ) ;
V_20 -> V_113 = V_113 ;
V_20 -> V_186 = V_66 ;
V_20 -> V_62 = V_113 -> V_62 ;
V_20 -> V_58 = V_28 ;
V_20 -> V_149 = V_113 -> V_187 -> V_149 ;
V_20 -> V_143 = false ;
V_20 -> V_141 = V_164 ;
F_71 ( V_2 , V_20 ) ;
V_8 = F_55 ( V_20 ) ;
if ( V_8 ) {
V_20 -> V_113 = NULL ;
F_16 ( V_28 , & V_2 -> V_184 ) ;
goto V_30;
}
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_34 ( V_2 , V_28 ) ;
V_179:
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_30:
return V_8 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_19 * V_20 , enum V_188 V_189 , int V_28 )
{
V_20 -> V_113 = NULL ;
V_20 -> V_186 = 0 ;
V_20 -> V_62 = NULL ;
V_20 -> V_58 = V_28 ;
V_20 -> V_149 = 0 ;
V_20 -> V_141 = V_167 ;
V_20 -> V_143 = true ;
V_2 -> V_69 . type = V_189 ;
return F_71 ( V_2 , V_20 ) ;
}
static int
F_78 ( struct V_1 * V_2 , int V_28 )
{
int V_8 = 0 ;
unsigned long V_100 ;
T_1 V_4 = 1 << V_28 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_17 ( V_2 , V_28 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_8 = F_1 ( V_2 ,
V_60 ,
V_4 , ~ V_4 , 1000 , 1000 ) ;
return V_8 ;
}
static int
F_79 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_190 ;
int V_8 = 0 ;
V_190 = F_22 ( V_20 -> V_40 ) ;
switch ( V_190 ) {
case V_191 :
if ( V_2 -> V_69 . type != V_170 ) {
V_8 = - V_166 ;
F_50 ( V_2 -> V_105 , L_5 ,
V_173 , V_190 ) ;
}
break;
case V_192 :
F_39 ( V_2 , V_20 ) ;
break;
case V_193 :
V_8 = - V_194 ;
F_50 ( V_2 -> V_105 , L_6 ,
V_173 ) ;
break;
default:
V_8 = - V_166 ;
F_50 ( V_2 -> V_105 , L_7 ,
V_173 , V_190 ) ;
break;
}
return V_8 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_19 * V_20 , int V_195 )
{
int V_8 = 0 ;
unsigned long V_196 ;
unsigned long V_100 ;
V_196 = F_46 ( V_2 -> V_69 . V_197 ,
F_2 ( V_195 ) ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_69 . V_197 = NULL ;
if ( F_72 ( V_196 ) ) {
V_8 = F_9 ( V_20 ) ;
if ( ! V_8 )
V_8 = F_79 ( V_2 , V_20 ) ;
}
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
if ( ! V_196 ) {
V_8 = - V_11 ;
if ( ! F_78 ( V_2 , V_20 -> V_58 ) )
V_8 = - V_198 ;
}
return V_8 ;
}
static bool F_81 ( struct V_1 * V_2 , int * V_199 )
{
int V_28 ;
bool V_29 = false ;
unsigned long V_200 ;
if ( ! V_199 )
goto V_30;
do {
V_200 = ~ V_2 -> V_184 ;
V_28 = F_82 ( & V_200 , V_2 -> V_85 ) ;
if ( V_28 >= V_2 -> V_85 )
goto V_30;
} while ( F_14 ( V_28 , & V_2 -> V_184 ) );
* V_199 = V_28 ;
V_29 = true ;
V_30:
return V_29 ;
}
static inline void F_83 ( struct V_1 * V_2 , int V_28 )
{
F_16 ( V_28 , & V_2 -> V_184 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
enum V_188 V_189 , int V_9 )
{
struct V_19 * V_20 ;
int V_8 ;
int V_28 ;
struct V_201 V_202 ;
unsigned long V_100 ;
F_85 ( V_2 -> V_69 . V_203 , F_81 ( V_2 , & V_28 ) ) ;
F_51 ( & V_202 ) ;
V_20 = & V_2 -> V_185 [ V_28 ] ;
F_44 ( V_20 -> V_113 ) ;
V_8 = F_77 ( V_2 , V_20 , V_189 , V_28 ) ;
if ( F_86 ( V_8 ) )
goto V_204;
V_2 -> V_69 . V_197 = & V_202 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_34 ( V_2 , V_28 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_8 = F_80 ( V_2 , V_20 , V_9 ) ;
V_204:
F_83 ( V_2 , V_28 ) ;
F_87 ( & V_2 -> V_69 . V_203 ) ;
return V_8 ;
}
static int F_88 ( struct V_1 * V_2 , enum V_205 V_76 ,
enum V_206 V_207 , bool * V_208 )
{
struct V_209 * V_158 ;
struct V_67 * V_71 ;
int V_8 ;
F_89 ( ! V_2 ) ;
F_53 ( & V_2 -> V_69 . V_210 ) ;
V_158 = & V_2 -> V_69 . V_70 . V_158 ;
V_71 = & V_2 -> V_69 . V_70 . V_71 ;
memset ( V_158 , 0 , sizeof( struct V_209 ) ) ;
memset ( V_71 , 0 , sizeof( struct V_67 ) ) ;
switch ( V_76 ) {
case V_211 :
case V_212 :
case V_213 :
V_158 -> V_161 = V_214 ;
break;
case V_215 :
V_158 -> V_161 = V_216 ;
if ( ! V_208 ) {
F_50 ( V_2 -> V_105 , L_8 ,
V_173 ) ;
V_8 = - V_166 ;
goto V_179;
}
break;
default:
F_50 ( V_2 -> V_105 ,
L_9 ,
V_173 , V_76 ) ;
V_8 = - V_166 ;
goto V_179;
}
V_158 -> V_159 . V_76 = V_76 ;
V_158 -> V_159 . V_207 = V_207 ;
V_8 = F_84 ( V_2 , V_169 ,
V_217 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 ,
L_10 ,
V_173 , V_207 , V_8 ) ;
goto V_179;
}
if ( V_208 )
* V_208 = ( F_23 ( V_71 -> V_73 . V_218 ) &
V_219 ) & 0x1 ;
V_179:
F_54 ( & V_2 -> V_69 . V_210 ) ;
return V_8 ;
}
static int F_90 ( struct V_1 * V_2 , enum V_205 V_76 ,
enum V_220 V_207 , T_2 V_221 , T_2 V_222 , T_1 * V_223 )
{
struct V_209 * V_158 ;
struct V_67 * V_71 ;
int V_8 ;
F_89 ( ! V_2 ) ;
if ( ! V_223 ) {
F_50 ( V_2 -> V_105 , L_11 ,
V_173 , V_76 ) ;
V_8 = - V_166 ;
goto V_30;
}
F_53 ( & V_2 -> V_69 . V_210 ) ;
V_158 = & V_2 -> V_69 . V_70 . V_158 ;
V_71 = & V_2 -> V_69 . V_70 . V_71 ;
memset ( V_158 , 0 , sizeof( struct V_209 ) ) ;
memset ( V_71 , 0 , sizeof( struct V_67 ) ) ;
switch ( V_76 ) {
case V_224 :
V_158 -> V_161 = V_214 ;
V_158 -> V_159 . V_218 = F_68 ( * V_223 ) ;
break;
case V_225 :
V_158 -> V_161 = V_216 ;
break;
default:
F_50 ( V_2 -> V_105 , L_12 ,
V_173 , V_76 ) ;
V_8 = - V_166 ;
goto V_179;
}
V_158 -> V_159 . V_76 = V_76 ;
V_158 -> V_159 . V_207 = V_207 ;
V_158 -> V_159 . V_221 = V_221 ;
V_158 -> V_159 . V_222 = V_222 ;
V_8 = F_84 ( V_2 , V_169 ,
V_217 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_13 ,
V_173 , V_76 , V_207 , V_8 ) ;
goto V_179;
}
* V_223 = F_23 ( V_71 -> V_73 . V_218 ) ;
V_179:
F_54 ( & V_2 -> V_69 . V_210 ) ;
V_30:
return V_8 ;
}
static int F_91 ( struct V_1 * V_2 )
{
T_4 V_226 , V_227 , V_228 ;
V_228 = ( sizeof( struct V_229 ) * V_2 -> V_85 ) ;
V_2 -> V_230 = F_92 ( V_2 -> V_105 ,
V_228 ,
& V_2 -> V_231 ,
V_232 ) ;
if ( ! V_2 -> V_230 ||
F_44 ( V_2 -> V_231 & ( V_233 - 1 ) ) ) {
F_50 ( V_2 -> V_105 ,
L_14 ) ;
goto V_30;
}
V_227 = ( sizeof( struct V_130 ) * V_2 -> V_85 ) ;
V_2 -> V_234 = F_92 ( V_2 -> V_105 ,
V_227 ,
& V_2 -> V_235 ,
V_232 ) ;
if ( ! V_2 -> V_234 ||
F_44 ( V_2 -> V_235 & ( V_233 - 1 ) ) ) {
F_50 ( V_2 -> V_105 ,
L_15 ) ;
goto V_30;
}
V_226 = sizeof( struct V_25 ) * V_2 -> V_32 ;
V_2 -> V_236 = F_92 ( V_2 -> V_105 ,
V_226 ,
& V_2 -> V_237 ,
V_232 ) ;
if ( ! V_2 -> V_236 ||
F_44 ( V_2 -> V_237 & ( V_233 - 1 ) ) ) {
F_50 ( V_2 -> V_105 ,
L_16 ) ;
goto V_30;
}
V_2 -> V_185 = F_93 ( V_2 -> V_105 ,
V_2 -> V_85 * sizeof( struct V_19 ) ,
V_232 ) ;
if ( ! V_2 -> V_185 ) {
F_50 ( V_2 -> V_105 , L_17 ) ;
goto V_30;
}
return 0 ;
V_30:
return - V_238 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_229 * V_239 ;
struct V_130 * V_240 ;
T_5 V_241 ;
T_5 V_242 ;
T_3 V_243 ;
T_3 V_244 ;
int V_245 ;
int V_115 ;
V_240 = V_2 -> V_234 ;
V_239 = V_2 -> V_230 ;
V_243 =
F_95 ( struct V_229 , V_246 ) ;
V_244 =
F_95 ( struct V_229 , V_109 ) ;
V_245 = sizeof( struct V_229 ) ;
V_241 = V_2 -> V_231 ;
for ( V_115 = 0 ; V_115 < V_2 -> V_85 ; V_115 ++ ) {
V_242 =
( V_241 + ( V_245 * V_115 ) ) ;
V_240 [ V_115 ] . V_247 =
F_59 ( F_61 ( V_242 ) ) ;
V_240 [ V_115 ] . V_248 =
F_59 ( F_62 ( V_242 ) ) ;
V_240 [ V_115 ] . V_249 =
F_57 ( ( V_243 >> 2 ) ) ;
V_240 [ V_115 ] . V_250 =
F_57 ( ( V_244 >> 2 ) ) ;
V_240 [ V_115 ] . V_251 =
F_57 ( V_252 >> 2 ) ;
V_2 -> V_185 [ V_115 ] . V_21 = ( V_240 + V_115 ) ;
V_2 -> V_185 [ V_115 ] . V_147 =
(struct V_146 * ) ( V_239 + V_115 ) ;
V_2 -> V_185 [ V_115 ] . V_40 =
(struct V_39 * ) V_239 [ V_115 ] . V_246 ;
V_2 -> V_185 [ V_115 ] . V_117 =
(struct V_108 * ) V_239 [ V_115 ] . V_109 ;
}
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_90 V_91 = { 0 } ;
int V_29 ;
V_91 . V_97 = V_253 ;
V_29 = F_52 ( V_2 , & V_91 ) ;
if ( V_29 )
F_50 ( V_2 -> V_105 ,
L_18 , V_29 ) ;
return V_29 ;
}
int F_97 ( struct V_1 * V_2 , T_1 V_254 ,
T_2 V_255 , T_1 V_256 , T_2 V_257 )
{
struct V_90 V_91 = { 0 } ;
static const char * const V_258 [] = {
L_19 ,
L_20
} ;
const char * V_123 = V_258 [ ! ! V_257 ] ;
int V_29 ;
V_91 . V_97 = V_257 ?
V_259 : V_260 ;
V_91 . V_93 = V_254 ;
V_91 . V_95 = F_98 ( V_255 ) ;
V_91 . V_96 = V_256 ;
V_29 = F_52 ( V_2 , & V_91 ) ;
if ( V_29 )
F_50 ( V_2 -> V_105 , L_21 ,
V_123 , F_99 ( V_254 ) , V_256 , V_29 ) ;
return V_29 ;
}
int F_100 ( struct V_1 * V_2 , T_1 V_254 ,
T_1 * V_256 , T_2 V_257 )
{
struct V_90 V_91 = { 0 } ;
static const char * const V_258 [] = {
L_22 ,
L_23
} ;
const char * V_261 = V_258 [ ! ! V_257 ] ;
int V_29 ;
V_91 . V_97 = V_257 ?
V_262 : V_263 ;
V_91 . V_93 = V_254 ;
V_29 = F_52 ( V_2 , & V_91 ) ;
if ( V_29 ) {
F_50 ( V_2 -> V_105 , L_24 ,
V_261 , F_99 ( V_254 ) , V_29 ) ;
goto V_30;
}
if ( V_256 )
* V_256 = V_91 . V_96 ;
V_30:
return V_29 ;
}
static int F_101 ( struct V_1 * V_2 , T_2 V_264 )
{
struct V_90 V_91 = { 0 } ;
struct V_201 V_265 ;
unsigned long V_100 ;
T_2 V_266 ;
int V_29 ;
V_91 . V_97 = V_260 ;
V_91 . V_93 = F_102 ( V_267 ) ;
V_91 . V_96 = V_264 ;
F_51 ( & V_265 ) ;
F_53 ( & V_2 -> V_107 ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_265 = & V_265 ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_29 = F_49 ( V_2 , & V_91 ) ;
if ( V_29 ) {
F_50 ( V_2 -> V_105 ,
L_25 ,
V_264 , V_29 ) ;
goto V_30;
}
if ( ! F_46 ( V_2 -> V_265 ,
F_2 ( V_102 ) ) ) {
F_50 ( V_2 -> V_105 ,
L_26 ,
V_264 ) ;
V_29 = - V_11 ;
goto V_30;
}
V_266 = F_42 ( V_2 ) ;
if ( V_266 != V_268 ) {
F_50 ( V_2 -> V_105 ,
L_27 ,
V_266 ) ;
V_29 = ( V_266 != V_269 ) ? V_266 : - 1 ;
}
V_30:
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_265 = NULL ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_54 ( & V_2 -> V_107 ) ;
return V_29 ;
}
static int F_103 ( struct V_1 * V_2 )
{
enum { V_270 = 0 , V_271 = 1 };
T_1 V_272 [] = { 1 , 1 } ;
T_1 V_273 [] = { 1 , 1 } ;
T_2 V_274 [] = { V_275 , V_275 } ;
int V_29 ;
F_104 ( V_2 , F_102 ( V_276 ) , & V_272 [ V_270 ] ) ;
F_104 ( V_2 , F_102 ( V_277 ) , & V_272 [ V_271 ] ) ;
F_104 ( V_2 , F_102 ( V_278 ) , & V_273 [ V_270 ] ) ;
if ( ! V_273 [ V_270 ] ) {
F_104 ( V_2 , F_102 ( V_279 ) , & V_273 [ V_270 ] ) ;
V_274 [ V_270 ] = V_280 ;
}
F_105 ( V_2 , F_102 ( V_278 ) , & V_273 [ V_271 ] ) ;
if ( ! V_273 [ V_271 ] ) {
F_105 ( V_2 , F_102 ( V_279 ) ,
& V_273 [ V_271 ] ) ;
V_274 [ V_271 ] = V_280 ;
}
F_106 ( V_2 , F_102 ( V_281 ) , V_273 [ V_270 ] ) ;
F_106 ( V_2 , F_102 ( V_282 ) , V_272 [ V_270 ] ) ;
if ( V_274 [ V_270 ] == V_275 )
F_106 ( V_2 , F_102 ( V_283 ) , TRUE ) ;
F_106 ( V_2 , F_102 ( V_284 ) , V_273 [ V_271 ] ) ;
F_106 ( V_2 , F_102 ( V_285 ) , V_272 [ V_271 ] ) ;
if ( V_274 [ V_271 ] == V_275 )
F_106 ( V_2 , F_102 ( V_286 ) , TRUE ) ;
if ( V_274 [ V_270 ] == V_275 || V_274 [ V_271 ] == V_275 )
F_106 ( V_2 , F_102 ( V_287 ) , V_288 ) ;
V_29 = F_101 ( V_2 , V_274 [ V_270 ] << 4 | V_274 [ V_271 ] ) ;
if ( V_29 )
F_50 ( V_2 -> V_105 ,
L_28 , V_29 ) ;
return V_29 ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_115 , V_289 , V_8 = 0 ;
bool V_208 = 1 ;
for ( V_289 = V_290 ; V_289 > 0 ; V_289 -- ) {
V_8 = F_88 ( V_2 , V_211 ,
V_291 , NULL ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_108 ( V_2 -> V_105 , L_29 , V_173 , V_8 ) ;
}
if ( V_8 ) {
F_50 ( V_2 -> V_105 ,
L_30 ,
V_173 , V_8 ) ;
goto V_30;
}
for ( V_115 = 0 ; V_115 < 100 && ! V_8 && V_208 ; V_115 ++ ) {
for ( V_289 = V_290 ; V_289 > 0 ; V_289 -- ) {
V_8 = F_88 ( V_2 ,
V_215 ,
V_291 , & V_208 ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_108 ( V_2 -> V_105 , L_29 , V_173 ,
V_8 ) ;
}
}
if ( V_8 )
F_50 ( V_2 -> V_105 ,
L_31 ,
V_173 , V_8 ) ;
else if ( V_208 )
F_50 ( V_2 -> V_105 ,
L_32 ,
V_173 ) ;
V_30:
return V_8 ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_88 ) ;
if ( ! F_8 ( V_3 ) ) {
F_50 ( V_2 -> V_105 , L_33 ) ;
V_8 = - V_292 ;
goto V_30;
}
F_63 ( V_2 , V_293 ) ;
F_28 ( V_2 , V_2 -> V_85 - 1 , V_294 ) ;
F_18 ( V_2 , F_61 ( V_2 -> V_235 ) ,
V_295 ) ;
F_18 ( V_2 , F_62 ( V_2 -> V_235 ) ,
V_296 ) ;
F_18 ( V_2 , F_61 ( V_2 -> V_237 ) ,
V_297 ) ;
F_18 ( V_2 , F_62 ( V_2 -> V_237 ) ,
V_298 ) ;
if ( ! ( F_19 ( V_3 ) ) ) {
F_31 ( V_2 ) ;
} else {
F_50 ( V_2 -> V_105 ,
L_34 ) ;
V_8 = - V_106 ;
goto V_30;
}
V_30:
return V_8 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_299 ;
if ( ! F_33 ( V_2 ) ) {
F_111 ( V_2 ) ;
F_112 ( 5 ) ;
}
F_32 ( V_2 ) ;
F_112 ( 1 ) ;
V_299 = 10 ;
while ( F_33 ( V_2 ) ) {
if ( V_299 ) {
V_299 -- ;
} else {
F_50 ( V_2 -> V_105 ,
L_35 ) ;
return - V_106 ;
}
F_112 ( 5 ) ;
}
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
int V_29 ;
F_63 ( V_2 , V_300 ) ;
V_29 = F_96 ( V_2 ) ;
if ( V_29 )
goto V_30;
V_29 = F_109 ( V_2 ) ;
V_30:
if ( V_29 )
F_50 ( V_2 -> V_105 , L_36 , V_29 ) ;
return V_29 ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
int V_289 ;
F_53 ( & V_2 -> V_69 . V_210 ) ;
for ( V_289 = V_301 ; V_289 > 0 ; V_289 -- ) {
V_8 = F_84 ( V_2 , V_170 ,
V_302 ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_108 ( V_2 -> V_105 , L_29 , V_173 , V_8 ) ;
}
F_54 ( & V_2 -> V_69 . V_210 ) ;
if ( V_8 )
F_50 ( V_2 -> V_105 , L_37 , V_173 , V_8 ) ;
return V_8 ;
}
static int F_115 ( struct V_303 * V_304 )
{
struct V_1 * V_2 ;
V_2 = F_74 ( V_304 -> V_103 ) ;
V_304 -> V_305 = 1 ;
V_304 -> V_306 = 1 ;
F_116 ( V_304 , V_307 ) ;
V_304 -> V_308 = 1 ;
F_117 ( V_304 , V_2 -> V_85 ) ;
return 0 ;
}
static void F_118 ( struct V_303 * V_304 )
{
struct V_1 * V_2 ;
V_2 = F_74 ( V_304 -> V_103 ) ;
F_119 ( V_304 , V_2 -> V_85 ) ;
}
static int F_120 ( struct V_1 * V_2 , T_1 V_221 , T_2 * V_190 )
{
struct V_25 * V_26 ;
struct V_309 * V_310 ;
unsigned long V_100 ;
int V_311 ;
int V_312 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_121 ( V_221 , & V_2 -> V_313 ) ;
V_26 = V_2 -> V_236 ;
V_311 = F_11 ( & V_26 [ V_221 ] ) ;
if ( V_311 == V_314 ) {
V_310 = (struct V_309 * )
V_26 [ V_221 ] . V_315 ;
V_312 = F_23 ( V_310 -> V_22 . V_42 ) ;
V_312 = ( ( V_312 & V_316 ) >> 8 ) ;
if ( V_190 )
* V_190 = ( T_2 ) V_312 ;
} else {
F_50 ( V_2 -> V_105 , L_38 ,
V_173 , V_311 ) ;
}
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
return V_311 ;
}
static void F_122 ( struct V_112 * V_113 )
{
struct V_1 * V_2 ;
int V_115 ;
int V_317 = 0 ;
V_2 = F_74 ( V_113 -> V_187 -> V_103 ) ;
for ( V_115 = 0 ; V_115 < V_2 -> V_85 ; V_115 ++ ) {
if ( F_123 ( V_115 , & V_2 -> V_59 ) ) {
if ( V_113 -> V_187 -> V_149 == V_2 -> V_185 [ V_115 ] . V_149 )
V_317 ++ ;
}
}
F_124 ( V_113 -> V_187 , V_307 , V_317 - 1 ) ;
}
static inline int
F_125 ( struct V_19 * V_20 , int V_318 )
{
int V_319 = 0 ;
switch ( V_318 ) {
case V_320 :
F_36 ( V_20 ) ;
case V_321 :
V_319 |= V_322 << 16 |
V_323 << 8 |
V_318 ;
break;
case V_324 :
F_122 ( V_20 -> V_113 ) ;
case V_325 :
case V_326 :
F_36 ( V_20 ) ;
V_319 |= V_318 ;
break;
default:
V_319 |= V_181 << 16 ;
break;
}
return V_319 ;
}
static inline int
F_126 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_319 = 0 ;
int V_318 ;
int V_327 ;
V_327 = F_9 ( V_20 ) ;
switch ( V_327 ) {
case V_314 :
V_319 = F_22 ( V_20 -> V_40 ) ;
switch ( V_319 ) {
case V_328 :
V_319 = F_24 ( V_20 -> V_40 ) ;
V_318 = V_319 & V_329 ;
V_319 = F_125 ( V_20 , V_318 ) ;
if ( F_26 ( V_20 -> V_40 ) )
F_127 ( & V_2 -> V_330 ) ;
break;
case V_193 :
V_319 = V_181 << 16 ;
F_50 ( V_2 -> V_105 ,
L_39 ) ;
break;
default:
V_319 = V_181 << 16 ;
F_50 ( V_2 -> V_105 ,
L_40 ,
V_319 ) ;
break;
}
break;
case V_331 :
V_319 |= V_332 << 16 ;
break;
case V_145 :
V_319 |= V_333 << 16 ;
break;
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
default:
V_319 |= V_181 << 16 ;
F_50 ( V_2 -> V_105 ,
L_41 , V_327 ) ;
break;
}
return V_319 ;
}
static void F_128 ( struct V_1 * V_2 , T_1 V_340 )
{
if ( ( V_340 & V_300 ) && V_2 -> V_92 ) {
V_2 -> V_92 -> V_95 |=
F_20 ( V_2 ) ;
V_2 -> V_92 -> V_96 =
F_21 ( V_2 ) ;
V_197 ( & V_2 -> V_92 -> V_101 ) ;
}
if ( ( V_340 & V_341 ) && V_2 -> V_265 )
V_197 ( V_2 -> V_265 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_112 * V_113 ;
unsigned long V_342 ;
T_1 V_343 ;
int V_319 ;
int V_221 ;
bool V_344 = false ;
V_343 = F_3 ( V_2 , V_60 ) ;
V_342 = V_343 ^ V_2 -> V_59 ;
for ( V_221 = 0 ; V_221 < V_2 -> V_85 ; V_221 ++ ) {
if ( F_123 ( V_221 , & V_342 ) ) {
V_20 = & V_2 -> V_185 [ V_221 ] ;
V_113 = V_20 -> V_113 ;
V_344 |= ! V_20 -> V_143 ;
if ( V_113 ) {
V_319 = F_126 ( V_2 , V_20 ) ;
F_130 ( V_113 ) ;
V_113 -> V_319 = V_319 ;
V_20 -> V_113 = NULL ;
F_16 ( V_221 , & V_2 -> V_184 ) ;
V_113 -> V_182 ( V_113 ) ;
} else if ( V_20 -> V_141 ==
V_167 ) {
if ( V_2 -> V_69 . V_197 )
V_197 ( V_2 -> V_69 . V_197 ) ;
}
}
}
V_2 -> V_59 ^= V_342 ;
F_87 ( & V_2 -> V_69 . V_203 ) ;
if ( V_344 )
F_27 ( V_2 ) ;
}
static int F_131 ( struct V_1 * V_2 , T_3 V_4 )
{
int V_8 = 0 ;
T_1 V_5 ;
if ( ! ( V_2 -> V_345 & V_4 ) )
goto V_30;
V_5 = V_2 -> V_345 & ~ V_4 ;
V_5 &= 0xFFFF ;
V_8 = F_90 ( V_2 , V_224 ,
V_346 , 0 , 0 , & V_5 ) ;
if ( ! V_8 )
V_2 -> V_345 &= ~ V_4 ;
V_30:
return V_8 ;
}
static int F_132 ( struct V_1 * V_2 , T_3 V_4 )
{
int V_8 = 0 ;
T_1 V_5 ;
if ( V_2 -> V_345 & V_4 )
goto V_30;
V_5 = V_2 -> V_345 | V_4 ;
V_5 &= 0xFFFF ;
V_8 = F_90 ( V_2 , V_224 ,
V_346 , 0 , 0 , & V_5 ) ;
if ( ! V_8 )
V_2 -> V_345 |= V_4 ;
V_30:
return V_8 ;
}
static int F_133 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( V_2 -> V_347 )
goto V_30;
V_8 = F_88 ( V_2 , V_211 ,
V_348 , NULL ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_42 ,
V_173 , V_8 ) ;
goto V_30;
}
V_2 -> V_347 = true ;
V_8 = F_131 ( V_2 , V_349 ) ;
if ( V_8 )
F_50 ( V_2 -> V_105 , L_43 ,
V_173 , V_8 ) ;
V_30:
return V_8 ;
}
static int F_134 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( ! V_2 -> V_347 )
goto V_30;
V_8 = F_132 ( V_2 , V_349 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_44 ,
V_173 , V_8 ) ;
goto V_30;
}
V_8 = F_88 ( V_2 , V_212 ,
V_348 , NULL ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_45 ,
V_173 , V_8 ) ;
F_131 ( V_2 , V_349 ) ;
goto V_30;
}
V_2 -> V_347 = false ;
V_30:
return V_8 ;
}
static void F_135 ( struct V_1 * V_2 )
{
V_2 -> V_347 = false ;
V_2 -> V_345 |= V_349 ;
F_133 ( V_2 ) ;
}
static inline int F_136 ( struct V_1 * V_2 , T_1 * V_266 )
{
return F_90 ( V_2 , V_225 ,
V_350 , 0 , 0 , V_266 ) ;
}
static int F_137 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_266 = 0 ;
V_8 = F_136 ( V_2 , & V_266 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_46 ,
V_173 , V_8 ) ;
goto V_30;
}
V_266 = V_266 & 0xF ;
if ( V_266 >= V_351 )
V_8 = F_133 ( V_2 ) ;
V_30:
return V_8 ;
}
static inline int F_138 ( struct V_1 * V_2 , T_1 * V_266 )
{
return F_90 ( V_2 , V_225 ,
V_352 , 0 , 0 , V_266 ) ;
}
static void F_139 ( struct V_353 * V_354 )
{
struct V_1 * V_2 ;
int V_8 ;
T_1 V_266 = 0 ;
V_2 = F_140 ( V_354 , struct V_1 , V_330 ) ;
F_141 ( V_2 -> V_105 ) ;
V_8 = F_138 ( V_2 , & V_266 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_47 ,
V_173 , V_8 ) ;
goto V_30;
}
V_266 &= V_2 -> V_345 ;
if ( V_266 & V_349 ) {
V_8 = F_137 ( V_2 ) ;
if ( V_8 )
F_50 ( V_2 -> V_105 , L_48 ,
V_173 , V_8 ) ;
}
V_30:
F_142 ( V_2 -> V_105 ) ;
return;
}
static void F_143 ( struct V_353 * V_354 )
{
struct V_1 * V_2 ;
unsigned long V_100 ;
T_1 V_355 = 0 ;
T_1 V_356 = 0 ;
int V_8 = 0 ;
int V_28 ;
V_2 = F_140 ( V_354 , struct V_1 , V_357 ) ;
F_141 ( V_2 -> V_105 ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
if ( V_2 -> V_175 == V_177 ) {
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
goto V_30;
}
V_2 -> V_175 = V_177 ;
F_144 ( V_2 ) ;
F_129 ( V_2 ) ;
F_145 ( V_2 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_146 (tag, &hba->outstanding_reqs, hba->nutrs)
if ( F_78 ( V_2 , V_28 ) )
V_355 |= 1 << V_28 ;
F_146 (tag, &hba->outstanding_tasks, hba->nutmrs)
if ( F_147 ( V_2 , V_28 ) )
V_356 |= 1 << V_28 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_129 ( V_2 ) ;
F_145 ( V_2 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
if ( V_355 || V_356 || ( V_2 -> V_358 & V_359 ) ||
( ( V_2 -> V_358 & V_360 ) &&
( V_2 -> V_361 & V_362 ) ) ) {
V_8 = F_148 ( V_2 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_49 ,
V_173 ) ;
V_2 -> V_175 = V_180 ;
}
F_149 ( V_2 -> V_103 , 0 ) ;
V_2 -> V_358 = 0 ;
V_2 -> V_361 = 0 ;
}
F_150 ( V_2 ) ;
V_30:
F_151 ( V_2 -> V_103 ) ;
F_142 ( V_2 -> V_105 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_363 ) ;
if ( V_3 & V_364 )
V_2 -> V_365 |= V_362 ;
V_3 = F_3 ( V_2 , V_366 ) ;
if ( V_3 )
V_2 -> V_365 |= V_367 ;
V_3 = F_3 ( V_2 , V_368 ) ;
if ( V_3 )
V_2 -> V_365 |= V_369 ;
V_3 = F_3 ( V_2 , V_370 ) ;
if ( V_3 )
V_2 -> V_365 |= V_371 ;
F_108 ( V_2 -> V_105 , L_50 ,
V_173 , V_2 -> V_365 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
bool V_372 = false ;
if ( V_2 -> V_373 & V_359 )
V_372 = true ;
if ( V_2 -> V_373 & V_360 ) {
V_2 -> V_365 = 0 ;
F_152 ( V_2 ) ;
if ( V_2 -> V_365 )
V_372 = true ;
}
if ( V_372 ) {
if ( V_2 -> V_175 == V_176 ) {
F_154 ( V_2 -> V_103 ) ;
V_2 -> V_358 |= V_2 -> V_373 ;
V_2 -> V_361 |= V_2 -> V_365 ;
V_2 -> V_175 = V_180 ;
F_127 ( & V_2 -> V_357 ) ;
}
}
}
static void F_145 ( struct V_1 * V_2 )
{
T_1 V_374 ;
V_374 = F_3 ( V_2 , V_375 ) ;
V_2 -> V_376 = V_374 ^ V_2 -> V_313 ;
F_87 ( & V_2 -> V_377 ) ;
}
static void F_155 ( struct V_1 * V_2 , T_1 V_340 )
{
V_2 -> V_373 = V_378 & V_340 ;
if ( V_2 -> V_373 )
F_153 ( V_2 ) ;
if ( V_340 & V_379 )
F_128 ( V_2 , V_340 ) ;
if ( V_340 & V_380 )
F_145 ( V_2 ) ;
if ( V_340 & V_381 )
F_129 ( V_2 ) ;
}
static T_6 F_156 ( int V_382 , void * V_383 )
{
T_1 V_340 ;
T_6 V_384 = V_385 ;
struct V_1 * V_2 = V_383 ;
F_157 ( V_2 -> V_103 -> V_104 ) ;
V_340 = F_3 ( V_2 , V_386 ) ;
if ( V_340 ) {
F_18 ( V_2 , V_340 , V_386 ) ;
F_155 ( V_2 , V_340 ) ;
V_384 = V_387 ;
}
F_158 ( V_2 -> V_103 -> V_104 ) ;
return V_384 ;
}
static int F_147 ( struct V_1 * V_2 , int V_28 )
{
int V_8 = 0 ;
T_1 V_4 = 1 << V_28 ;
unsigned long V_100 ;
if ( ! F_123 ( V_28 , & V_2 -> V_313 ) )
goto V_30;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_18 ( V_2 , ~ ( 1 << V_28 ) , V_388 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_8 = F_1 ( V_2 ,
V_375 ,
V_4 , 0 , 1000 , 1000 ) ;
V_30:
return V_8 ;
}
static int F_159 ( struct V_1 * V_2 , int V_389 , int V_390 ,
T_2 V_391 , T_2 * V_392 )
{
struct V_25 * V_26 ;
struct V_393 * V_394 ;
struct V_174 * V_103 ;
unsigned long V_100 ;
int V_27 ;
int V_8 ;
int V_58 ;
V_103 = V_2 -> V_103 ;
F_85 ( V_2 -> V_395 , F_12 ( V_2 , & V_27 ) ) ;
F_47 ( V_103 -> V_104 , V_100 ) ;
V_26 = V_2 -> V_236 ;
V_26 += V_27 ;
V_26 -> V_22 . V_41 = F_59 ( V_144 ) ;
V_26 -> V_22 . V_23 =
F_59 ( V_145 ) ;
V_394 =
(struct V_393 * ) V_26 -> V_396 ;
V_58 = V_2 -> V_85 + V_27 ;
V_394 -> V_22 . V_41 =
F_67 ( V_397 , 0 ,
V_389 , V_58 ) ;
V_394 -> V_22 . V_42 =
F_67 ( 0 , V_391 , 0 , 0 ) ;
V_394 -> V_398 = F_68 ( V_389 ) ;
V_394 -> V_399 = F_68 ( V_390 ) ;
F_35 ( V_27 , & V_2 -> V_313 ) ;
F_18 ( V_2 , 1 << V_27 , V_375 ) ;
F_48 ( V_103 -> V_104 , V_100 ) ;
V_8 = F_160 ( V_2 -> V_377 ,
F_123 ( V_27 , & V_2 -> V_376 ) ,
F_2 ( V_400 ) ) ;
if ( ! V_8 ) {
F_50 ( V_2 -> V_105 , L_51 ,
V_173 , V_391 ) ;
if ( F_147 ( V_2 , V_27 ) )
F_161 ( V_2 -> V_105 , L_52 ,
V_173 , V_27 ) ;
V_8 = - V_11 ;
} else {
V_8 = F_120 ( V_2 , V_27 , V_392 ) ;
}
F_162 ( V_27 , & V_2 -> V_376 ) ;
F_15 ( V_2 , V_27 ) ;
F_87 ( & V_2 -> V_395 ) ;
return V_8 ;
}
static int F_163 ( struct V_112 * V_113 )
{
struct V_174 * V_103 ;
struct V_1 * V_2 ;
unsigned int V_28 ;
T_1 V_34 ;
int V_8 ;
T_2 V_190 = 0xF ;
struct V_19 * V_20 ;
unsigned long V_100 ;
V_103 = V_113 -> V_187 -> V_103 ;
V_2 = F_74 ( V_103 ) ;
V_28 = V_113 -> V_158 -> V_28 ;
V_20 = & V_2 -> V_185 [ V_28 ] ;
V_8 = F_159 ( V_2 , V_20 -> V_149 , 0 , V_401 , & V_190 ) ;
if ( V_8 || V_190 != V_402 ) {
if ( ! V_8 )
V_8 = V_190 ;
goto V_30;
}
F_146 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_2 -> V_185 [ V_34 ] . V_149 == V_20 -> V_149 ) {
V_8 = F_78 ( V_2 , V_34 ) ;
if ( V_8 )
break;
}
}
F_47 ( V_103 -> V_104 , V_100 ) ;
F_129 ( V_2 ) ;
F_48 ( V_103 -> V_104 , V_100 ) ;
V_30:
if ( ! V_8 ) {
V_8 = V_403 ;
} else {
F_50 ( V_2 -> V_105 , L_53 , V_173 , V_8 ) ;
V_8 = V_404 ;
}
return V_8 ;
}
static int F_164 ( struct V_112 * V_113 )
{
struct V_174 * V_103 ;
struct V_1 * V_2 ;
unsigned long V_100 ;
unsigned int V_28 ;
int V_8 = 0 ;
int V_405 ;
T_2 V_190 = 0xF ;
struct V_19 * V_20 ;
V_103 = V_113 -> V_187 -> V_103 ;
V_2 = F_74 ( V_103 ) ;
V_28 = V_113 -> V_158 -> V_28 ;
if ( ! ( F_123 ( V_28 , & V_2 -> V_59 ) ) )
goto V_30;
V_20 = & V_2 -> V_185 [ V_28 ] ;
for ( V_405 = 100 ; V_405 ; V_405 -- ) {
V_8 = F_159 ( V_2 , V_20 -> V_149 , V_20 -> V_58 ,
V_406 , & V_190 ) ;
if ( ! V_8 && V_190 == V_407 ) {
break;
} else if ( ! V_8 && V_190 == V_402 ) {
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_60 ) ;
if ( V_3 & ( 1 << V_28 ) ) {
F_4 ( 100 , 200 ) ;
continue;
}
goto V_30;
} else {
if ( ! V_8 )
V_8 = V_190 ;
goto V_30;
}
}
if ( ! V_405 ) {
V_8 = - V_408 ;
goto V_30;
}
V_8 = F_159 ( V_2 , V_20 -> V_149 , V_20 -> V_58 ,
V_409 , & V_190 ) ;
if ( V_8 || V_190 != V_402 ) {
if ( ! V_8 )
V_8 = V_190 ;
goto V_30;
}
V_8 = F_78 ( V_2 , V_28 ) ;
if ( V_8 )
goto V_30;
F_130 ( V_113 ) ;
F_47 ( V_103 -> V_104 , V_100 ) ;
F_121 ( V_28 , & V_2 -> V_59 ) ;
V_2 -> V_185 [ V_28 ] . V_113 = NULL ;
F_48 ( V_103 -> V_104 , V_100 ) ;
F_16 ( V_28 , & V_2 -> V_184 ) ;
F_87 ( & V_2 -> V_69 . V_203 ) ;
V_30:
if ( ! V_8 ) {
V_8 = V_403 ;
} else {
F_50 ( V_2 -> V_105 , L_53 , V_173 , V_8 ) ;
V_8 = V_404 ;
}
return V_8 ;
}
static int F_165 ( struct V_1 * V_2 )
{
int V_8 ;
T_7 V_410 ;
unsigned long V_100 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_111 ( V_2 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_8 = F_110 ( V_2 ) ;
if ( V_8 )
goto V_30;
V_410 = F_166 ( V_411 , V_2 ) ;
F_167 ( ++ V_410 ) ;
if ( V_2 -> V_175 != V_176 )
V_8 = - V_106 ;
V_30:
if ( V_8 )
F_50 ( V_2 -> V_105 , L_54 , V_173 , V_8 ) ;
return V_8 ;
}
static int F_148 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
unsigned long V_100 ;
V_8 = F_165 ( V_2 ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_129 ( V_2 ) ;
F_145 ( V_2 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
return V_8 ;
}
static int F_168 ( struct V_112 * V_113 )
{
int V_8 ;
unsigned long V_100 ;
struct V_1 * V_2 ;
V_2 = F_74 ( V_113 -> V_187 -> V_103 ) ;
do {
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
if ( ! ( F_169 ( & V_2 -> V_357 ) ||
V_2 -> V_175 == V_177 ) )
break;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_108 ( V_2 -> V_105 , L_55 , V_173 ) ;
F_170 ( & V_2 -> V_357 ) ;
} while ( 1 );
V_2 -> V_175 = V_177 ;
F_144 ( V_2 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_8 = F_148 ( V_2 ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
if ( ! V_8 ) {
V_8 = V_403 ;
V_2 -> V_175 = V_176 ;
} else {
V_8 = V_404 ;
V_2 -> V_175 = V_180 ;
}
F_150 ( V_2 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
return V_8 ;
}
static void V_411 ( void * V_412 , T_7 V_410 )
{
struct V_1 * V_2 = (struct V_1 * ) V_412 ;
int V_29 ;
V_29 = F_113 ( V_2 ) ;
if ( V_29 )
goto V_30;
F_103 ( V_2 ) ;
V_29 = F_114 ( V_2 ) ;
if ( V_29 )
goto V_30;
V_29 = F_107 ( V_2 ) ;
if ( V_29 )
goto V_30;
F_135 ( V_2 ) ;
V_2 -> V_175 = V_176 ;
if ( ! F_171 ( V_2 ) ) {
F_172 ( V_2 -> V_103 ) ;
F_142 ( V_2 -> V_105 ) ;
}
V_30:
return;
}
int F_173 ( struct V_1 * V_2 , T_8 V_413 )
{
return - V_414 ;
}
int F_174 ( struct V_1 * V_2 )
{
return - V_414 ;
}
int F_175 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return F_133 ( V_2 ) ;
}
int F_176 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return F_134 ( V_2 ) ;
}
int F_177 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_178 ( struct V_1 * V_2 )
{
F_179 ( V_2 -> V_103 ) ;
F_64 ( V_2 , V_2 -> V_415 ) ;
F_111 ( V_2 ) ;
F_180 ( V_2 -> V_103 ) ;
}
int F_181 ( struct V_187 * V_105 , struct V_1 * * V_416 ,
void T_9 * V_417 , unsigned int V_382 )
{
struct V_174 * V_103 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_105 ) {
F_50 ( V_105 ,
L_56 ) ;
V_8 = - V_418 ;
goto V_419;
}
if ( ! V_417 ) {
F_50 ( V_105 ,
L_57 ) ;
V_8 = - V_418 ;
goto V_419;
}
V_103 = F_182 ( & V_420 ,
sizeof( struct V_1 ) ) ;
if ( ! V_103 ) {
F_50 ( V_105 , L_58 ) ;
V_8 = - V_238 ;
goto V_419;
}
V_2 = F_74 ( V_103 ) ;
V_2 -> V_103 = V_103 ;
V_2 -> V_105 = V_105 ;
V_2 -> V_417 = V_417 ;
V_2 -> V_382 = V_382 ;
F_40 ( V_2 ) ;
V_2 -> V_12 = F_7 ( V_2 ) ;
V_2 -> V_415 = F_6 ( V_2 ) ;
V_8 = F_91 ( V_2 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_59 ) ;
goto V_421;
}
F_94 ( V_2 ) ;
V_103 -> V_422 = V_2 -> V_85 ;
V_103 -> V_423 = V_2 -> V_85 ;
V_103 -> V_424 = V_425 ;
V_103 -> V_426 = V_427 ;
V_103 -> V_428 = V_429 ;
V_103 -> V_430 = V_103 -> V_431 ;
V_103 -> V_432 = V_433 ;
F_183 ( & V_2 -> V_377 ) ;
F_183 ( & V_2 -> V_395 ) ;
F_184 ( & V_2 -> V_357 , F_143 ) ;
F_184 ( & V_2 -> V_330 , F_139 ) ;
F_185 ( & V_2 -> V_107 ) ;
F_185 ( & V_2 -> V_69 . V_210 ) ;
F_183 ( & V_2 -> V_69 . V_203 ) ;
V_8 = F_186 ( V_105 , V_382 , F_156 , V_434 , V_435 , V_2 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_60 ) ;
goto V_421;
}
V_8 = F_187 ( V_103 , V_103 -> V_422 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_61 ) ;
goto V_421;
}
V_8 = F_188 ( V_103 , V_2 -> V_105 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_62 ) ;
goto V_421;
}
V_8 = F_110 ( V_2 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_63 ) ;
goto V_436;
}
* V_416 = V_2 ;
F_141 ( V_105 ) ;
F_166 ( V_411 , V_2 ) ;
return 0 ;
V_436:
F_179 ( V_2 -> V_103 ) ;
V_421:
F_180 ( V_103 ) ;
V_419:
return V_8 ;
}
