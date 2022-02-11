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
return V_20 -> V_21 -> V_22 . V_23 & V_24 ;
}
static inline int
F_10 ( struct V_25 * V_26 )
{
return V_26 -> V_22 . V_23 & V_24 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
return F_12 ( & V_2 -> V_27 , V_2 -> V_28 ) ;
}
static inline void F_13 ( struct V_1 * V_2 , T_1 V_29 )
{
F_14 ( V_2 , ~ ( 1 << V_29 ) , V_30 ) ;
}
static inline int F_15 ( T_1 V_3 )
{
return ( ( ( V_3 ) & ( 0xFF ) ) >> 1 ) ^ ( 0x07 ) ;
}
static inline int F_16 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_31 ) &
V_32 ;
}
static inline T_1 F_17 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_33 ) ;
}
static inline int
F_18 ( struct V_34 * V_35 )
{
return F_19 ( V_35 -> V_22 . V_36 ) >> 24 ;
}
static inline int
F_20 ( struct V_34 * V_35 )
{
return F_19 ( V_35 -> V_22 . V_37 ) & V_38 ;
}
static inline unsigned int
F_21 ( struct V_34 * V_35 )
{
return F_19 ( V_35 -> V_22 . V_23 ) &
V_39 ;
}
static inline bool F_22 ( struct V_34 * V_35 )
{
return F_19 ( V_35 -> V_22 . V_23 ) &
V_40 ? true : false ;
}
static inline void
F_23 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_41 |
V_42 ,
V_43 ) ;
}
static inline void
F_24 ( struct V_1 * V_2 , T_2 V_44 , T_2 V_45 )
{
F_14 ( V_2 , V_41 | V_46 |
F_25 ( V_44 ) |
F_26 ( V_45 ) ,
V_43 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_47 ,
V_48 ) ;
F_14 ( V_2 , V_49 ,
V_50 ) ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_51 , V_52 ) ;
}
static inline int F_29 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_52 ) & 0x1 ) ? 0 : 1 ;
}
static inline
void F_30 ( struct V_1 * V_2 , unsigned int V_53 )
{
F_31 ( V_53 , & V_2 -> V_54 ) ;
F_14 ( V_2 , 1 << V_53 , V_55 ) ;
}
static inline void F_32 ( struct V_19 * V_20 )
{
int V_56 ;
if ( V_20 -> V_57 &&
F_21 ( V_20 -> V_35 ) ) {
V_56 = F_33 ( V_20 -> V_35 -> V_58 . V_59 ) ;
memcpy ( V_20 -> V_57 ,
V_20 -> V_35 -> V_58 . V_60 ,
F_34 ( int , V_56 , V_61 ) ) ;
}
}
static inline void F_35 ( struct V_62 * V_63 )
{
V_63 -> V_64 = F_33 ( V_63 -> V_64 ) ;
V_63 -> V_65 = F_19 ( V_63 -> V_65 ) ;
}
static inline void F_36 ( struct V_62 * V_66 )
{
V_66 -> V_64 = F_37 ( V_66 -> V_64 ) ;
V_66 -> V_65 = F_38 ( V_66 -> V_65 ) ;
}
static
void F_39 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_67 * V_68 = & V_2 -> V_69 . V_70 . V_63 ;
V_68 -> V_63 = F_20 ( V_20 -> V_35 ) >>
V_71 ;
memcpy ( & V_68 -> V_72 , & V_20 -> V_35 -> V_73 , V_74 ) ;
F_35 ( & V_68 -> V_72 ) ;
if ( V_20 -> V_35 -> V_73 . V_75 == V_76 ) {
T_2 * V_77 = ( T_2 * ) & V_20 -> V_35 +
V_78 ;
T_3 V_56 ;
V_56 = F_19 ( V_20 -> V_35 -> V_22 . V_23 ) &
V_79 ;
memcpy ( V_2 -> V_69 . V_70 . V_80 , V_77 ,
F_34 ( T_3 , V_56 , V_81 ) ) ;
}
}
static inline void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_82 = F_3 ( V_2 , V_83 ) ;
V_2 -> V_84 = ( V_2 -> V_82 & V_85 ) + 1 ;
V_2 -> V_28 =
( ( V_2 -> V_82 & V_86 ) >> 16 ) + 1 ;
}
static inline bool F_41 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_87 ) & V_88 )
return true ;
else
return false ;
}
static inline T_2 F_42 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_87 ) >> 8 ) & 0x7 ;
}
static inline void
F_43 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
F_44 ( V_2 -> V_91 ) ;
V_2 -> V_91 = V_90 ;
F_14 ( V_2 , V_90 -> V_92 , V_93 ) ;
F_14 ( V_2 , V_90 -> V_94 , V_31 ) ;
F_14 ( V_2 , V_90 -> V_95 , V_33 ) ;
F_14 ( V_2 , V_90 -> V_96 & V_97 ,
V_98 ) ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
int V_99 ;
unsigned long V_100 ;
if ( F_46 ( & V_90 -> V_101 ,
F_2 ( V_102 ) ) )
V_99 = V_90 -> V_94 & V_32 ;
else
V_99 = - V_11 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_91 = NULL ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
return V_99 ;
}
static int
F_49 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
int V_99 ;
unsigned long V_100 ;
if ( ! F_41 ( V_2 ) ) {
F_50 ( V_2 -> V_105 ,
L_1 ) ;
return - V_106 ;
}
F_51 ( & V_90 -> V_101 ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_43 ( V_2 , V_90 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_99 = F_45 ( V_2 , V_90 ) ;
return V_99 ;
}
static int
F_52 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
int V_99 ;
F_53 ( & V_2 -> V_107 ) ;
V_99 = F_49 ( V_2 , V_90 ) ;
F_54 ( & V_2 -> V_107 ) ;
return V_99 ;
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
F_14 ( V_2 , V_123 , V_124 ) ;
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
F_14 ( V_2 , V_123 , V_124 ) ;
}
static void F_65 ( struct V_19 * V_20 ,
T_1 * V_127 , enum V_128 V_129 )
{
struct V_130 * V_131 = V_20 -> V_21 ;
T_1 V_132 ;
T_1 V_36 ;
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
V_36 = V_132 | ( V_20 -> V_141
<< V_142 ) ;
if ( V_20 -> V_143 )
V_36 |= V_144 ;
V_131 -> V_22 . V_36 = F_59 ( V_36 ) ;
V_131 -> V_22 . V_23 =
F_59 ( V_145 ) ;
}
static
void F_66 ( struct V_19 * V_20 , T_1 V_127 )
{
struct V_146 * V_147 = V_20 -> V_147 ;
V_147 -> V_22 . V_36 = F_67 (
V_148 , V_127 ,
V_20 -> V_149 , V_20 -> V_53 ) ;
V_147 -> V_22 . V_37 = F_67 (
V_150 , 0 , 0 , 0 ) ;
V_147 -> V_22 . V_23 = 0 ;
V_147 -> V_151 . V_152 =
F_38 ( V_20 -> V_113 -> V_153 . V_64 ) ;
memcpy ( V_147 -> V_151 . V_154 , V_20 -> V_113 -> V_155 ,
( F_34 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ) ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_19 * V_20 , T_1 V_127 )
{
struct V_146 * V_147 = V_20 -> V_147 ;
struct V_156 * V_70 = & V_2 -> V_69 . V_70 ;
T_3 V_56 = V_70 -> V_66 . V_157 . V_64 ;
T_2 * V_77 = ( T_2 * ) V_20 -> V_147 + V_78 ;
V_147 -> V_22 . V_36 = F_67 (
V_158 , V_127 ,
V_20 -> V_149 , V_20 -> V_53 ) ;
V_147 -> V_22 . V_37 = F_67 (
0 , V_70 -> V_66 . V_159 , 0 , 0 ) ;
V_147 -> V_22 . V_23 = F_67 (
0 , 0 , V_56 >> 8 , ( T_2 ) V_56 ) ;
memcpy ( & V_147 -> V_73 , & V_70 -> V_66 . V_157 ,
V_74 ) ;
F_36 ( & V_147 -> V_73 ) ;
if ( ( V_56 > 0 ) && ( V_70 -> V_66 . V_157 . V_75 ==
V_160 ) ) {
memcpy ( V_77 , V_70 -> V_80 ,
F_34 ( T_3 , V_56 , V_81 ) ) ;
}
}
static inline void F_69 ( struct V_19 * V_20 )
{
struct V_146 * V_147 = V_20 -> V_147 ;
memset ( V_147 , 0 , sizeof( struct V_146 ) ) ;
V_147 -> V_22 . V_36 =
F_67 (
V_161 , 0 , 0 , V_20 -> V_53 ) ;
}
static int F_70 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
T_1 V_127 ;
int V_99 = 0 ;
switch ( V_20 -> V_141 ) {
case V_162 :
if ( F_71 ( V_20 -> V_113 ) ) {
F_65 ( V_20 , & V_127 ,
V_20 -> V_113 -> V_163 ) ;
F_66 ( V_20 , V_127 ) ;
} else {
V_99 = - V_164 ;
}
break;
case V_165 :
F_65 ( V_20 , & V_127 , V_166 ) ;
if ( V_2 -> V_69 . type == V_167 )
F_68 (
V_2 , V_20 , V_127 ) ;
else if ( V_2 -> V_69 . type == V_168 )
F_69 ( V_20 ) ;
else
V_99 = - V_164 ;
break;
case V_169 :
V_99 = - V_170 ;
F_50 ( V_2 -> V_105 , L_2 ,
V_171 ) ;
break;
default:
V_99 = - V_170 ;
F_50 ( V_2 -> V_105 , L_3 ,
V_171 , V_20 -> V_141 ) ;
break;
}
return V_99 ;
}
static int F_72 ( struct V_172 * V_103 , struct V_112 * V_113 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned long V_100 ;
int V_173 ;
int V_8 = 0 ;
V_2 = F_73 ( V_103 ) ;
V_173 = V_113 -> V_66 -> V_173 ;
if ( V_2 -> V_174 != V_175 ) {
V_8 = V_176 ;
goto V_177;
}
if ( F_74 ( V_173 , & V_2 -> V_178 ) ) {
V_8 = V_176 ;
goto V_177;
}
V_20 = & V_2 -> V_179 [ V_173 ] ;
F_44 ( V_20 -> V_113 ) ;
V_20 -> V_113 = V_113 ;
V_20 -> V_180 = V_61 ;
V_20 -> V_57 = V_113 -> V_57 ;
V_20 -> V_53 = V_173 ;
V_20 -> V_149 = V_113 -> V_181 -> V_149 ;
V_20 -> V_143 = false ;
V_20 -> V_141 = V_162 ;
F_70 ( V_2 , V_20 ) ;
V_8 = F_55 ( V_20 ) ;
if ( V_8 ) {
V_20 -> V_113 = NULL ;
F_75 ( V_173 , & V_2 -> V_178 ) ;
goto V_177;
}
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_30 ( V_2 , V_173 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_177:
return V_8 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_19 * V_20 , enum V_182 V_183 , int V_173 )
{
V_20 -> V_113 = NULL ;
V_20 -> V_180 = 0 ;
V_20 -> V_57 = NULL ;
V_20 -> V_53 = V_173 ;
V_20 -> V_149 = 0 ;
V_20 -> V_141 = V_165 ;
V_20 -> V_143 = true ;
V_2 -> V_69 . type = V_183 ;
return F_70 ( V_2 , V_20 ) ;
}
static int
F_77 ( struct V_1 * V_2 , int V_173 )
{
int V_8 = 0 ;
unsigned long V_100 ;
T_1 V_4 = 1 << V_173 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_13 ( V_2 , V_173 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_8 = F_1 ( V_2 ,
V_55 ,
V_4 , ~ V_4 , 1000 , 1000 ) ;
return V_8 ;
}
static int
F_78 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_184 ;
int V_8 = 0 ;
V_184 = F_18 ( V_20 -> V_35 ) ;
switch ( V_184 ) {
case V_185 :
if ( V_2 -> V_69 . type != V_168 ) {
V_8 = - V_164 ;
F_50 ( V_2 -> V_105 , L_4 ,
V_171 , V_184 ) ;
}
break;
case V_186 :
F_39 ( V_2 , V_20 ) ;
break;
case V_187 :
V_8 = - V_188 ;
F_50 ( V_2 -> V_105 , L_5 ,
V_171 ) ;
break;
default:
V_8 = - V_164 ;
F_50 ( V_2 -> V_105 , L_6 ,
V_171 , V_184 ) ;
break;
}
return V_8 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_19 * V_20 , int V_189 )
{
int V_8 = 0 ;
unsigned long V_190 ;
unsigned long V_100 ;
V_190 = F_46 ( V_2 -> V_69 . V_191 ,
F_2 ( V_189 ) ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_69 . V_191 = NULL ;
if ( F_71 ( V_190 ) ) {
V_8 = F_9 ( V_20 ) ;
if ( ! V_8 )
V_8 = F_78 ( V_2 , V_20 ) ;
}
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
if ( ! V_190 ) {
V_8 = - V_11 ;
if ( ! F_77 ( V_2 , V_20 -> V_53 ) )
V_8 = - V_192 ;
}
return V_8 ;
}
static bool F_80 ( struct V_1 * V_2 , int * V_193 )
{
int V_173 ;
bool V_99 = false ;
unsigned long V_194 ;
if ( ! V_193 )
goto V_177;
do {
V_194 = ~ V_2 -> V_178 ;
V_173 = F_81 ( & V_194 , V_2 -> V_84 ) ;
if ( V_173 >= V_2 -> V_84 )
goto V_177;
} while ( F_74 ( V_173 , & V_2 -> V_178 ) );
* V_193 = V_173 ;
V_99 = true ;
V_177:
return V_99 ;
}
static inline void F_82 ( struct V_1 * V_2 , int V_173 )
{
F_75 ( V_173 , & V_2 -> V_178 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
enum V_182 V_183 , int V_9 )
{
struct V_19 * V_20 ;
int V_8 ;
int V_173 ;
struct V_195 V_196 ;
unsigned long V_100 ;
F_84 ( V_2 -> V_69 . V_197 , F_80 ( V_2 , & V_173 ) ) ;
F_51 ( & V_196 ) ;
V_20 = & V_2 -> V_179 [ V_173 ] ;
F_44 ( V_20 -> V_113 ) ;
V_8 = F_76 ( V_2 , V_20 , V_183 , V_173 ) ;
if ( F_85 ( V_8 ) )
goto V_198;
V_2 -> V_69 . V_191 = & V_196 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_30 ( V_2 , V_173 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_8 = F_79 ( V_2 , V_20 , V_9 ) ;
V_198:
F_82 ( V_2 , V_173 ) ;
F_86 ( & V_2 -> V_69 . V_197 ) ;
return V_8 ;
}
static int F_87 ( struct V_1 * V_2 , enum V_199 V_75 ,
enum V_200 V_201 , bool * V_202 )
{
struct V_203 * V_66 ;
struct V_67 * V_63 ;
int V_8 ;
F_88 ( ! V_2 ) ;
F_53 ( & V_2 -> V_69 . V_204 ) ;
V_66 = & V_2 -> V_69 . V_70 . V_66 ;
V_63 = & V_2 -> V_69 . V_70 . V_63 ;
memset ( V_66 , 0 , sizeof( struct V_203 ) ) ;
memset ( V_63 , 0 , sizeof( struct V_67 ) ) ;
switch ( V_75 ) {
case V_205 :
case V_206 :
case V_207 :
V_66 -> V_159 = V_208 ;
break;
case V_209 :
V_66 -> V_159 = V_210 ;
if ( ! V_202 ) {
F_50 ( V_2 -> V_105 , L_7 ,
V_171 ) ;
V_8 = - V_164 ;
goto V_211;
}
break;
default:
F_50 ( V_2 -> V_105 ,
L_8 ,
V_171 , V_75 ) ;
V_8 = - V_164 ;
goto V_211;
}
V_66 -> V_157 . V_75 = V_75 ;
V_66 -> V_157 . V_201 = V_201 ;
V_8 = F_83 ( V_2 , V_167 ,
V_212 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 ,
L_9 ,
V_171 , V_201 , V_8 ) ;
goto V_211;
}
if ( V_202 )
* V_202 = ( V_63 -> V_72 . V_65 &
V_213 ) & 0x1 ;
V_211:
F_54 ( & V_2 -> V_69 . V_204 ) ;
return V_8 ;
}
int F_89 ( struct V_1 * V_2 , enum V_199 V_75 ,
enum V_214 V_201 , T_2 V_215 , T_2 V_216 , T_1 * V_217 )
{
struct V_203 * V_66 ;
struct V_67 * V_63 ;
int V_8 ;
F_88 ( ! V_2 ) ;
if ( ! V_217 ) {
F_50 ( V_2 -> V_105 , L_10 ,
V_171 , V_75 ) ;
V_8 = - V_164 ;
goto V_177;
}
F_53 ( & V_2 -> V_69 . V_204 ) ;
V_66 = & V_2 -> V_69 . V_70 . V_66 ;
V_63 = & V_2 -> V_69 . V_70 . V_63 ;
memset ( V_66 , 0 , sizeof( struct V_203 ) ) ;
memset ( V_63 , 0 , sizeof( struct V_67 ) ) ;
switch ( V_75 ) {
case V_218 :
V_66 -> V_159 = V_208 ;
V_66 -> V_157 . V_65 = * V_217 ;
break;
case V_219 :
V_66 -> V_159 = V_210 ;
break;
default:
F_50 ( V_2 -> V_105 , L_11 ,
V_171 , V_75 ) ;
V_8 = - V_164 ;
goto V_211;
}
V_66 -> V_157 . V_75 = V_75 ;
V_66 -> V_157 . V_201 = V_201 ;
V_66 -> V_157 . V_215 = V_215 ;
V_66 -> V_157 . V_216 = V_216 ;
V_8 = F_83 ( V_2 , V_167 ,
V_212 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_12 ,
V_171 , V_75 , V_201 , V_8 ) ;
goto V_211;
}
* V_217 = V_63 -> V_72 . V_65 ;
V_211:
F_54 ( & V_2 -> V_69 . V_204 ) ;
V_177:
return V_8 ;
}
static int F_90 ( struct V_1 * V_2 )
{
T_4 V_220 , V_221 , V_222 ;
V_222 = ( sizeof( struct V_223 ) * V_2 -> V_84 ) ;
V_2 -> V_224 = F_91 ( V_2 -> V_105 ,
V_222 ,
& V_2 -> V_225 ,
V_226 ) ;
if ( ! V_2 -> V_224 ||
F_44 ( V_2 -> V_225 & ( V_227 - 1 ) ) ) {
F_50 ( V_2 -> V_105 ,
L_13 ) ;
goto V_177;
}
V_221 = ( sizeof( struct V_130 ) * V_2 -> V_84 ) ;
V_2 -> V_228 = F_91 ( V_2 -> V_105 ,
V_221 ,
& V_2 -> V_229 ,
V_226 ) ;
if ( ! V_2 -> V_228 ||
F_44 ( V_2 -> V_229 & ( V_227 - 1 ) ) ) {
F_50 ( V_2 -> V_105 ,
L_14 ) ;
goto V_177;
}
V_220 = sizeof( struct V_25 ) * V_2 -> V_28 ;
V_2 -> V_230 = F_91 ( V_2 -> V_105 ,
V_220 ,
& V_2 -> V_231 ,
V_226 ) ;
if ( ! V_2 -> V_230 ||
F_44 ( V_2 -> V_231 & ( V_227 - 1 ) ) ) {
F_50 ( V_2 -> V_105 ,
L_15 ) ;
goto V_177;
}
V_2 -> V_179 = F_92 ( V_2 -> V_105 ,
V_2 -> V_84 * sizeof( struct V_19 ) ,
V_226 ) ;
if ( ! V_2 -> V_179 ) {
F_50 ( V_2 -> V_105 , L_16 ) ;
goto V_177;
}
return 0 ;
V_177:
return - V_232 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_223 * V_233 ;
struct V_130 * V_234 ;
T_5 V_235 ;
T_5 V_236 ;
T_3 V_237 ;
T_3 V_238 ;
int V_239 ;
int V_115 ;
V_234 = V_2 -> V_228 ;
V_233 = V_2 -> V_224 ;
V_237 =
F_94 ( struct V_223 , V_240 ) ;
V_238 =
F_94 ( struct V_223 , V_109 ) ;
V_239 = sizeof( struct V_223 ) ;
V_235 = V_2 -> V_225 ;
for ( V_115 = 0 ; V_115 < V_2 -> V_84 ; V_115 ++ ) {
V_236 =
( V_235 + ( V_239 * V_115 ) ) ;
V_234 [ V_115 ] . V_241 =
F_59 ( F_61 ( V_236 ) ) ;
V_234 [ V_115 ] . V_242 =
F_59 ( F_62 ( V_236 ) ) ;
V_234 [ V_115 ] . V_243 =
F_57 ( ( V_237 >> 2 ) ) ;
V_234 [ V_115 ] . V_244 =
F_57 ( ( V_238 >> 2 ) ) ;
V_234 [ V_115 ] . V_245 =
F_57 ( V_246 >> 2 ) ;
V_2 -> V_179 [ V_115 ] . V_21 = ( V_234 + V_115 ) ;
V_2 -> V_179 [ V_115 ] . V_147 =
(struct V_146 * ) ( V_233 + V_115 ) ;
V_2 -> V_179 [ V_115 ] . V_35 =
(struct V_34 * ) V_233 [ V_115 ] . V_240 ;
V_2 -> V_179 [ V_115 ] . V_117 =
(struct V_108 * ) V_233 [ V_115 ] . V_109 ;
}
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_89 V_90 = { 0 } ;
int V_99 ;
V_90 . V_96 = V_247 ;
V_99 = F_52 ( V_2 , & V_90 ) ;
if ( V_99 )
F_50 ( V_2 -> V_105 ,
L_17 , V_99 ) ;
return V_99 ;
}
int F_96 ( struct V_1 * V_2 , T_1 V_248 ,
T_2 V_249 , T_1 V_250 , T_2 V_251 )
{
struct V_89 V_90 = { 0 } ;
static const char * const V_252 [] = {
L_18 ,
L_19
} ;
const char * V_123 = V_252 [ ! ! V_251 ] ;
int V_99 ;
V_90 . V_96 = V_251 ?
V_253 : V_254 ;
V_90 . V_92 = V_248 ;
V_90 . V_94 = F_97 ( V_249 ) ;
V_90 . V_95 = V_250 ;
V_99 = F_52 ( V_2 , & V_90 ) ;
if ( V_99 )
F_50 ( V_2 -> V_105 , L_20 ,
V_123 , F_98 ( V_248 ) , V_250 , V_99 ) ;
return V_99 ;
}
int F_99 ( struct V_1 * V_2 , T_1 V_248 ,
T_1 * V_250 , T_2 V_251 )
{
struct V_89 V_90 = { 0 } ;
static const char * const V_252 [] = {
L_21 ,
L_22
} ;
const char * V_255 = V_252 [ ! ! V_251 ] ;
int V_99 ;
V_90 . V_96 = V_251 ?
V_256 : V_257 ;
V_90 . V_92 = V_248 ;
V_99 = F_52 ( V_2 , & V_90 ) ;
if ( V_99 ) {
F_50 ( V_2 -> V_105 , L_23 ,
V_255 , F_98 ( V_248 ) , V_99 ) ;
goto V_177;
}
if ( V_250 )
* V_250 = V_90 . V_95 ;
V_177:
return V_99 ;
}
int F_100 ( struct V_1 * V_2 , T_2 V_258 )
{
struct V_89 V_90 = { 0 } ;
struct V_195 V_259 ;
unsigned long V_100 ;
T_2 V_260 ;
int V_99 ;
V_90 . V_96 = V_254 ;
V_90 . V_92 = F_101 ( V_261 ) ;
V_90 . V_95 = V_258 ;
F_51 ( & V_259 ) ;
F_53 ( & V_2 -> V_107 ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_259 = & V_259 ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_99 = F_49 ( V_2 , & V_90 ) ;
if ( V_99 ) {
F_50 ( V_2 -> V_105 ,
L_24 ,
V_258 , V_99 ) ;
goto V_177;
}
if ( ! F_46 ( V_2 -> V_259 ,
F_2 ( V_102 ) ) ) {
F_50 ( V_2 -> V_105 ,
L_25 ,
V_258 ) ;
V_99 = - V_11 ;
goto V_177;
}
V_260 = F_42 ( V_2 ) ;
if ( V_260 != V_262 ) {
F_50 ( V_2 -> V_105 ,
L_26 ,
V_260 ) ;
V_99 = ( V_260 != V_263 ) ? V_260 : - 1 ;
}
V_177:
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_259 = NULL ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_54 ( & V_2 -> V_107 ) ;
return V_99 ;
}
static int F_102 ( struct V_1 * V_2 )
{
enum { V_264 = 0 , V_265 = 1 };
T_1 V_266 [] = { 1 , 1 } ;
T_1 V_267 [] = { 1 , 1 } ;
T_2 V_268 [] = { V_269 , V_269 } ;
int V_99 ;
F_103 ( V_2 , F_101 ( V_270 ) , & V_266 [ V_264 ] ) ;
F_103 ( V_2 , F_101 ( V_271 ) , & V_266 [ V_265 ] ) ;
F_103 ( V_2 , F_101 ( V_272 ) , & V_267 [ V_264 ] ) ;
if ( ! V_267 [ V_264 ] ) {
F_103 ( V_2 , F_101 ( V_273 ) , & V_267 [ V_264 ] ) ;
V_268 [ V_264 ] = V_274 ;
}
F_104 ( V_2 , F_101 ( V_272 ) , & V_267 [ V_265 ] ) ;
if ( ! V_267 [ V_265 ] ) {
F_104 ( V_2 , F_101 ( V_273 ) ,
& V_267 [ V_265 ] ) ;
V_268 [ V_265 ] = V_274 ;
}
F_105 ( V_2 , F_101 ( V_275 ) , V_267 [ V_264 ] ) ;
F_105 ( V_2 , F_101 ( V_276 ) , V_266 [ V_264 ] ) ;
if ( V_268 [ V_264 ] == V_269 )
F_105 ( V_2 , F_101 ( V_277 ) , TRUE ) ;
F_105 ( V_2 , F_101 ( V_278 ) , V_267 [ V_265 ] ) ;
F_105 ( V_2 , F_101 ( V_279 ) , V_266 [ V_265 ] ) ;
if ( V_268 [ V_265 ] == V_269 )
F_105 ( V_2 , F_101 ( V_280 ) , TRUE ) ;
if ( V_268 [ V_264 ] == V_269 || V_268 [ V_265 ] == V_269 )
F_105 ( V_2 , F_101 ( V_281 ) , V_282 ) ;
V_99 = F_100 ( V_2 , V_268 [ V_264 ] << 4 | V_268 [ V_265 ] ) ;
if ( V_99 )
F_50 ( V_2 -> V_105 ,
L_27 , V_99 ) ;
return V_99 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_115 , V_283 , V_8 = 0 ;
bool V_202 = 1 ;
for ( V_283 = V_284 ; V_283 > 0 ; V_283 -- ) {
V_8 = F_87 ( V_2 , V_205 ,
V_285 , NULL ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_107 ( V_2 -> V_105 , L_28 , V_171 , V_8 ) ;
}
if ( V_8 ) {
F_50 ( V_2 -> V_105 ,
L_29 ,
V_171 , V_8 ) ;
goto V_177;
}
for ( V_115 = 0 ; V_115 < 100 && ! V_8 && V_202 ; V_115 ++ ) {
for ( V_283 = V_284 ; V_283 > 0 ; V_283 -- ) {
V_8 = F_87 ( V_2 ,
V_209 ,
V_285 , & V_202 ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_107 ( V_2 -> V_105 , L_28 , V_171 ,
V_8 ) ;
}
}
if ( V_8 )
F_50 ( V_2 -> V_105 ,
L_30 ,
V_171 , V_8 ) ;
else if ( V_202 )
F_50 ( V_2 -> V_105 ,
L_31 ,
V_171 ) ;
V_177:
return V_8 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_87 ) ;
if ( ! F_8 ( V_3 ) ) {
F_50 ( V_2 -> V_105 , L_32 ) ;
V_8 = - V_286 ;
goto V_177;
}
F_63 ( V_2 , V_287 ) ;
F_24 ( V_2 , V_2 -> V_84 - 1 , V_288 ) ;
F_14 ( V_2 , F_61 ( V_2 -> V_229 ) ,
V_289 ) ;
F_14 ( V_2 , F_62 ( V_2 -> V_229 ) ,
V_290 ) ;
F_14 ( V_2 , F_61 ( V_2 -> V_231 ) ,
V_291 ) ;
F_14 ( V_2 , F_62 ( V_2 -> V_231 ) ,
V_292 ) ;
if ( ! ( F_15 ( V_3 ) ) ) {
F_27 ( V_2 ) ;
} else {
F_50 ( V_2 -> V_105 ,
L_33 ) ;
V_8 = - V_106 ;
goto V_177;
}
if ( V_2 -> V_174 == V_293 )
F_109 ( V_2 -> V_103 ) ;
V_2 -> V_174 = V_175 ;
V_177:
return V_8 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_294 ;
if ( ! F_29 ( V_2 ) ) {
F_111 ( V_2 ) ;
F_112 ( 5 ) ;
}
F_28 ( V_2 ) ;
F_112 ( 1 ) ;
V_294 = 10 ;
while ( F_29 ( V_2 ) ) {
if ( V_294 ) {
V_294 -- ;
} else {
F_50 ( V_2 -> V_105 ,
L_34 ) ;
return - V_106 ;
}
F_112 ( 5 ) ;
}
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
int V_99 ;
F_63 ( V_2 , V_295 ) ;
V_99 = F_95 ( V_2 ) ;
if ( V_99 )
goto V_177;
V_99 = F_108 ( V_2 ) ;
V_177:
if ( V_99 )
F_50 ( V_2 -> V_105 , L_35 , V_99 ) ;
return V_99 ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
int V_283 ;
F_53 ( & V_2 -> V_69 . V_204 ) ;
for ( V_283 = V_296 ; V_283 > 0 ; V_283 -- ) {
V_8 = F_83 ( V_2 , V_168 ,
V_297 ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_107 ( V_2 -> V_105 , L_28 , V_171 , V_8 ) ;
}
F_54 ( & V_2 -> V_69 . V_204 ) ;
if ( V_8 )
F_50 ( V_2 -> V_105 , L_36 , V_171 , V_8 ) ;
return V_8 ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
unsigned long V_100 ;
int V_173 ;
F_116 ( V_2 -> V_103 ) ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
V_2 -> V_174 = V_293 ;
F_111 ( V_2 ) ;
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
for ( V_173 = 0 ; V_173 < V_2 -> V_84 ; V_173 ++ ) {
if ( F_117 ( V_173 , & V_2 -> V_54 ) ) {
V_20 = & V_2 -> V_179 [ V_173 ] ;
if ( V_20 -> V_113 ) {
F_118 ( V_20 -> V_113 ) ;
V_20 -> V_113 -> V_298 = V_299 << 16 ;
V_20 -> V_113 -> V_300 ( V_20 -> V_113 ) ;
V_20 -> V_113 = NULL ;
F_75 ( V_173 , & V_2 -> V_178 ) ;
}
}
}
if ( V_2 -> V_69 . V_191 )
V_191 ( V_2 -> V_69 . V_191 ) ;
V_2 -> V_54 = 0 ;
V_2 -> V_27 = 0 ;
if ( F_110 ( V_2 ) ) {
F_50 ( V_2 -> V_105 ,
L_37 ) ;
return V_301 ;
}
if ( F_113 ( V_2 ) ) {
F_50 ( V_2 -> V_105 ,
L_38 ) ;
return V_301 ;
}
return V_302 ;
}
static int F_119 ( struct V_303 * V_304 )
{
struct V_1 * V_2 ;
V_2 = F_73 ( V_304 -> V_103 ) ;
V_304 -> V_305 = 1 ;
V_304 -> V_306 = 1 ;
F_120 ( V_304 , V_307 ) ;
F_121 ( V_304 , V_2 -> V_84 ) ;
return 0 ;
}
static void F_122 ( struct V_303 * V_304 )
{
struct V_1 * V_2 ;
V_2 = F_73 ( V_304 -> V_103 ) ;
F_123 ( V_304 , V_2 -> V_84 ) ;
}
static int F_124 ( struct V_1 * V_2 , T_1 V_215 )
{
struct V_25 * V_26 ;
struct V_308 * V_309 ;
unsigned long V_100 ;
int V_310 ;
int V_311 ;
F_47 ( V_2 -> V_103 -> V_104 , V_100 ) ;
F_125 ( V_215 , & V_2 -> V_27 ) ;
V_26 = V_2 -> V_230 ;
V_310 = F_10 ( & V_26 [ V_215 ] ) ;
if ( V_310 == V_312 ) {
V_309 = (struct V_308 * )
V_26 [ V_215 ] . V_313 ;
V_311 = F_19 ( V_309 -> V_22 . V_37 ) ;
V_311 = ( ( V_311 & V_314 ) >> 8 ) ;
if ( V_311 != V_315 &&
V_311 != V_316 )
V_311 = V_301 ;
else
V_311 = V_302 ;
} else {
V_311 = V_301 ;
F_50 ( V_2 -> V_105 ,
L_39 , V_310 ) ;
}
F_48 ( V_2 -> V_103 -> V_104 , V_100 ) ;
return V_311 ;
}
static void F_126 ( struct V_112 * V_113 )
{
struct V_1 * V_2 ;
int V_115 ;
int V_317 = 0 ;
V_2 = F_73 ( V_113 -> V_181 -> V_103 ) ;
for ( V_115 = 0 ; V_115 < V_2 -> V_84 ; V_115 ++ ) {
if ( F_117 ( V_115 , & V_2 -> V_54 ) ) {
if ( V_113 -> V_181 -> V_149 == V_2 -> V_179 [ V_115 ] . V_149 )
V_317 ++ ;
}
}
F_127 ( V_113 -> V_181 , V_307 , V_317 - 1 ) ;
}
static inline int
F_128 ( struct V_19 * V_20 , int V_318 )
{
int V_298 = 0 ;
switch ( V_318 ) {
case V_319 :
F_32 ( V_20 ) ;
case V_320 :
V_298 |= V_321 << 16 |
V_322 << 8 |
V_318 ;
break;
case V_323 :
F_126 ( V_20 -> V_113 ) ;
case V_324 :
case V_325 :
F_32 ( V_20 ) ;
V_298 |= V_318 ;
break;
default:
V_298 |= V_326 << 16 ;
break;
}
return V_298 ;
}
static inline int
F_129 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_298 = 0 ;
int V_318 ;
int V_327 ;
V_327 = F_9 ( V_20 ) ;
switch ( V_327 ) {
case V_312 :
V_298 = F_18 ( V_20 -> V_35 ) ;
switch ( V_298 ) {
case V_328 :
V_298 = F_20 ( V_20 -> V_35 ) ;
V_318 = V_298 & V_329 ;
V_298 = F_128 ( V_20 , V_318 ) ;
if ( F_22 ( V_20 -> V_35 ) )
F_130 ( & V_2 -> V_330 ) ;
break;
case V_187 :
V_298 = V_326 << 16 ;
F_50 ( V_2 -> V_105 ,
L_40 ) ;
break;
default:
V_298 = V_326 << 16 ;
F_50 ( V_2 -> V_105 ,
L_41 ,
V_298 ) ;
break;
}
break;
case V_331 :
V_298 |= V_332 << 16 ;
break;
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
default:
V_298 |= V_326 << 16 ;
F_50 ( V_2 -> V_105 ,
L_42 , V_327 ) ;
break;
}
return V_298 ;
}
static void F_131 ( struct V_1 * V_2 , T_1 V_339 )
{
if ( ( V_339 & V_295 ) && V_2 -> V_91 ) {
V_2 -> V_91 -> V_94 |=
F_16 ( V_2 ) ;
V_2 -> V_91 -> V_95 =
F_17 ( V_2 ) ;
V_191 ( & V_2 -> V_91 -> V_101 ) ;
}
if ( ( V_339 & V_340 ) && V_2 -> V_259 )
V_191 ( V_2 -> V_259 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_112 * V_113 ;
unsigned long V_341 ;
T_1 V_342 ;
int V_298 ;
int V_215 ;
bool V_343 = false ;
V_342 = F_3 ( V_2 , V_55 ) ;
V_341 = V_342 ^ V_2 -> V_54 ;
for ( V_215 = 0 ; V_215 < V_2 -> V_84 ; V_215 ++ ) {
if ( F_117 ( V_215 , & V_341 ) ) {
V_20 = & V_2 -> V_179 [ V_215 ] ;
V_113 = V_20 -> V_113 ;
V_343 |= ! V_20 -> V_143 ;
if ( V_113 ) {
V_298 = F_129 ( V_2 , V_20 ) ;
F_118 ( V_113 ) ;
V_113 -> V_298 = V_298 ;
V_20 -> V_113 = NULL ;
F_75 ( V_215 , & V_2 -> V_178 ) ;
V_113 -> V_300 ( V_113 ) ;
} else if ( V_20 -> V_141 ==
V_165 ) {
if ( V_2 -> V_69 . V_191 )
V_191 ( V_2 -> V_69 . V_191 ) ;
}
}
}
V_2 -> V_54 ^= V_341 ;
F_86 ( & V_2 -> V_69 . V_197 ) ;
if ( V_343 )
F_23 ( V_2 ) ;
}
static int F_133 ( struct V_1 * V_2 , T_3 V_4 )
{
int V_8 = 0 ;
T_1 V_5 ;
if ( ! ( V_2 -> V_344 & V_4 ) )
goto V_177;
V_5 = V_2 -> V_344 & ~ V_4 ;
V_5 &= 0xFFFF ;
V_8 = F_89 ( V_2 , V_218 ,
V_345 , 0 , 0 , & V_5 ) ;
if ( ! V_8 )
V_2 -> V_344 &= ~ V_4 ;
V_177:
return V_8 ;
}
static int F_134 ( struct V_1 * V_2 , T_3 V_4 )
{
int V_8 = 0 ;
T_1 V_5 ;
if ( V_2 -> V_344 & V_4 )
goto V_177;
V_5 = V_2 -> V_344 | V_4 ;
V_5 &= 0xFFFF ;
V_8 = F_89 ( V_2 , V_218 ,
V_345 , 0 , 0 , & V_5 ) ;
if ( ! V_8 )
V_2 -> V_344 |= V_4 ;
V_177:
return V_8 ;
}
static int F_135 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( V_2 -> V_346 )
goto V_177;
V_8 = F_87 ( V_2 , V_205 ,
V_347 , NULL ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_43 ,
V_171 , V_8 ) ;
goto V_177;
}
V_2 -> V_346 = true ;
V_8 = F_133 ( V_2 , V_348 ) ;
if ( V_8 )
F_50 ( V_2 -> V_105 , L_44 ,
V_171 , V_8 ) ;
V_177:
return V_8 ;
}
static int F_136 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( ! V_2 -> V_346 )
goto V_177;
V_8 = F_134 ( V_2 , V_348 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_45 ,
V_171 , V_8 ) ;
goto V_177;
}
V_8 = F_87 ( V_2 , V_206 ,
V_347 , NULL ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_46 ,
V_171 , V_8 ) ;
F_133 ( V_2 , V_348 ) ;
goto V_177;
}
V_2 -> V_346 = false ;
V_177:
return V_8 ;
}
static void F_137 ( struct V_1 * V_2 )
{
V_2 -> V_346 = false ;
V_2 -> V_344 |= V_348 ;
F_135 ( V_2 ) ;
}
static inline int F_138 ( struct V_1 * V_2 , T_1 * V_260 )
{
return F_89 ( V_2 , V_219 ,
V_349 , 0 , 0 , V_260 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_260 = 0 ;
V_8 = F_138 ( V_2 , & V_260 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_47 ,
V_171 , V_8 ) ;
goto V_177;
}
V_260 = V_260 & 0xF ;
if ( V_260 >= V_350 )
V_8 = F_135 ( V_2 ) ;
V_177:
return V_8 ;
}
static inline int F_140 ( struct V_1 * V_2 , T_1 * V_260 )
{
return F_89 ( V_2 , V_219 ,
V_351 , 0 , 0 , V_260 ) ;
}
static void F_141 ( struct V_352 * V_353 )
{
struct V_1 * V_2 ;
int V_8 ;
T_1 V_260 = 0 ;
V_2 = F_142 ( V_353 , struct V_1 , V_330 ) ;
F_143 ( V_2 -> V_105 ) ;
V_8 = F_140 ( V_2 , & V_260 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_48 ,
V_171 , V_8 ) ;
goto V_177;
}
V_260 &= V_2 -> V_344 ;
if ( V_260 & V_348 ) {
V_8 = F_139 ( V_2 ) ;
if ( V_8 )
F_50 ( V_2 -> V_105 , L_49 ,
V_171 , V_8 ) ;
}
V_177:
F_144 ( V_2 -> V_105 ) ;
return;
}
static void F_145 ( struct V_352 * V_353 )
{
struct V_1 * V_2 ;
V_2 = F_142 ( V_353 , struct V_1 , V_354 ) ;
F_143 ( V_2 -> V_105 ) ;
if ( V_2 -> V_174 != V_293 )
F_115 ( V_2 ) ;
F_144 ( V_2 -> V_105 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_355 & V_356 )
goto V_357;
if ( V_2 -> V_355 & V_358 ) {
V_3 = F_3 ( V_2 , V_359 ) ;
if ( V_3 & V_360 )
goto V_357;
}
return;
V_357:
V_2 -> V_174 = V_361 ;
F_130 ( & V_2 -> V_354 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
T_1 V_362 ;
V_362 = F_3 ( V_2 , V_363 ) ;
V_2 -> V_364 = V_362 ^ V_2 -> V_27 ;
F_148 ( & V_2 -> V_365 ) ;
}
static void F_149 ( struct V_1 * V_2 , T_1 V_339 )
{
V_2 -> V_355 = V_366 & V_339 ;
if ( V_2 -> V_355 )
F_146 ( V_2 ) ;
if ( V_339 & V_367 )
F_131 ( V_2 , V_339 ) ;
if ( V_339 & V_368 )
F_147 ( V_2 ) ;
if ( V_339 & V_369 )
F_132 ( V_2 ) ;
}
static T_6 F_150 ( int V_370 , void * V_371 )
{
T_1 V_339 ;
T_6 V_372 = V_373 ;
struct V_1 * V_2 = V_371 ;
F_151 ( V_2 -> V_103 -> V_104 ) ;
V_339 = F_3 ( V_2 , V_374 ) ;
if ( V_339 ) {
F_14 ( V_2 , V_339 , V_374 ) ;
F_149 ( V_2 , V_339 ) ;
V_372 = V_375 ;
}
F_152 ( V_2 -> V_103 -> V_104 ) ;
return V_372 ;
}
static int
F_153 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_2 V_376 )
{
struct V_25 * V_26 ;
struct V_377 * V_378 ;
struct V_172 * V_103 ;
unsigned long V_100 ;
int V_379 = 0 ;
int V_8 ;
V_103 = V_2 -> V_103 ;
F_47 ( V_103 -> V_104 , V_100 ) ;
V_379 = F_11 ( V_2 ) ;
if ( V_379 >= V_2 -> V_28 ) {
F_48 ( V_103 -> V_104 , V_100 ) ;
F_50 ( V_2 -> V_105 , L_50 ) ;
V_8 = V_301 ;
goto V_177;
}
V_26 = V_2 -> V_230 ;
V_26 += V_379 ;
V_26 -> V_22 . V_36 = F_59 ( V_144 ) ;
V_26 -> V_22 . V_23 =
F_59 ( V_145 ) ;
V_378 =
(struct V_377 * ) V_26 -> V_380 ;
V_378 -> V_22 . V_36 =
F_67 ( V_381 , 0 ,
V_20 -> V_149 , V_20 -> V_53 ) ;
V_378 -> V_22 . V_37 =
F_67 ( 0 , V_376 , 0 , 0 ) ;
V_378 -> V_382 = V_20 -> V_149 ;
V_378 -> V_382 =
F_38 ( V_378 -> V_382 ) ;
V_378 -> V_383 = V_20 -> V_53 ;
V_378 -> V_383 =
F_38 ( V_378 -> V_383 ) ;
F_31 ( V_379 , & V_2 -> V_27 ) ;
F_14 ( V_2 , 1 << V_379 , V_363 ) ;
F_48 ( V_103 -> V_104 , V_100 ) ;
V_8 =
F_154 ( V_2 -> V_365 ,
( F_117 ( V_379 ,
& V_2 -> V_364 ) != 0 ) ,
60 * V_384 ) ;
if ( ! V_8 ) {
F_50 ( V_2 -> V_105 ,
L_51 ) ;
V_8 = V_301 ;
goto V_177;
}
F_155 ( V_379 , & V_2 -> V_364 ) ;
V_8 = F_124 ( V_2 , V_379 ) ;
V_177:
return V_8 ;
}
static int F_156 ( struct V_112 * V_113 )
{
struct V_172 * V_103 ;
struct V_1 * V_2 ;
unsigned int V_173 ;
T_1 V_29 ;
int V_8 ;
V_103 = V_113 -> V_181 -> V_103 ;
V_2 = F_73 ( V_103 ) ;
V_173 = V_113 -> V_66 -> V_173 ;
V_8 = F_153 ( V_2 , & V_2 -> V_179 [ V_173 ] , V_385 ) ;
if ( V_8 == V_301 )
goto V_177;
for ( V_29 = 0 ; V_29 < V_2 -> V_84 ; V_29 ++ ) {
if ( F_117 ( V_29 , & V_2 -> V_54 ) &&
( V_2 -> V_179 [ V_173 ] . V_149 == V_2 -> V_179 [ V_29 ] . V_149 ) ) {
F_13 ( V_2 , V_29 ) ;
F_155 ( V_29 , & V_2 -> V_54 ) ;
if ( V_2 -> V_179 [ V_29 ] . V_113 ) {
F_118 ( V_2 -> V_179 [ V_29 ] . V_113 ) ;
V_2 -> V_179 [ V_29 ] . V_113 -> V_298 =
V_332 << 16 ;
V_2 -> V_179 [ V_29 ] . V_113 -> V_300 ( V_113 ) ;
V_2 -> V_179 [ V_29 ] . V_113 = NULL ;
F_75 ( V_29 , & V_2 -> V_178 ) ;
F_86 ( & V_2 -> V_69 . V_197 ) ;
}
}
}
V_177:
return V_8 ;
}
static int F_157 ( struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_2 = F_73 ( V_113 -> V_181 -> V_103 ) ;
if ( V_2 -> V_174 == V_293 )
return V_302 ;
return F_115 ( V_2 ) ;
}
static int F_158 ( struct V_112 * V_113 )
{
struct V_172 * V_103 ;
struct V_1 * V_2 ;
unsigned long V_100 ;
unsigned int V_173 ;
int V_8 ;
V_103 = V_113 -> V_181 -> V_103 ;
V_2 = F_73 ( V_103 ) ;
V_173 = V_113 -> V_66 -> V_173 ;
F_47 ( V_103 -> V_104 , V_100 ) ;
if ( ! ( F_117 ( V_173 , & V_2 -> V_54 ) ) ) {
V_8 = V_301 ;
F_48 ( V_103 -> V_104 , V_100 ) ;
goto V_177;
}
F_48 ( V_103 -> V_104 , V_100 ) ;
V_8 = F_153 ( V_2 , & V_2 -> V_179 [ V_173 ] , V_386 ) ;
if ( V_8 == V_301 )
goto V_177;
F_118 ( V_113 ) ;
F_47 ( V_103 -> V_104 , V_100 ) ;
F_13 ( V_2 , V_173 ) ;
F_125 ( V_173 , & V_2 -> V_54 ) ;
V_2 -> V_179 [ V_173 ] . V_113 = NULL ;
F_48 ( V_103 -> V_104 , V_100 ) ;
F_75 ( V_173 , & V_2 -> V_178 ) ;
F_86 ( & V_2 -> V_69 . V_197 ) ;
V_177:
return V_8 ;
}
static void F_159 ( void * V_387 , T_7 V_388 )
{
struct V_1 * V_2 = (struct V_1 * ) V_387 ;
int V_99 ;
V_99 = F_113 ( V_2 ) ;
if ( V_99 )
goto V_177;
F_102 ( V_2 ) ;
V_99 = F_114 ( V_2 ) ;
if ( V_99 )
goto V_177;
V_99 = F_106 ( V_2 ) ;
if ( V_99 )
goto V_177;
F_137 ( V_2 ) ;
F_160 ( V_2 -> V_103 ) ;
F_144 ( V_2 -> V_105 ) ;
V_177:
return;
}
int F_161 ( struct V_1 * V_2 , T_8 V_389 )
{
return - V_390 ;
}
int F_162 ( struct V_1 * V_2 )
{
return - V_390 ;
}
int F_163 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return F_135 ( V_2 ) ;
}
int F_164 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return F_136 ( V_2 ) ;
}
int F_165 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_166 ( struct V_1 * V_2 )
{
F_167 ( V_2 -> V_103 ) ;
F_64 ( V_2 , V_2 -> V_391 ) ;
F_111 ( V_2 ) ;
F_168 ( V_2 -> V_103 ) ;
}
int F_169 ( struct V_181 * V_105 , struct V_1 * * V_392 ,
void T_9 * V_393 , unsigned int V_370 )
{
struct V_172 * V_103 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_105 ) {
F_50 ( V_105 ,
L_52 ) ;
V_8 = - V_394 ;
goto V_395;
}
if ( ! V_393 ) {
F_50 ( V_105 ,
L_53 ) ;
V_8 = - V_394 ;
goto V_395;
}
V_103 = F_170 ( & V_396 ,
sizeof( struct V_1 ) ) ;
if ( ! V_103 ) {
F_50 ( V_105 , L_54 ) ;
V_8 = - V_232 ;
goto V_395;
}
V_2 = F_73 ( V_103 ) ;
V_2 -> V_103 = V_103 ;
V_2 -> V_105 = V_105 ;
V_2 -> V_393 = V_393 ;
V_2 -> V_370 = V_370 ;
F_40 ( V_2 ) ;
V_2 -> V_12 = F_7 ( V_2 ) ;
V_2 -> V_391 = F_6 ( V_2 ) ;
V_8 = F_90 ( V_2 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_55 ) ;
goto V_397;
}
F_93 ( V_2 ) ;
V_103 -> V_398 = V_2 -> V_84 ;
V_103 -> V_399 = V_2 -> V_84 ;
V_103 -> V_400 = V_401 ;
V_103 -> V_402 = V_403 ;
V_103 -> V_404 = V_405 ;
V_103 -> V_406 = V_103 -> V_407 ;
V_103 -> V_408 = V_409 ;
F_171 ( & V_2 -> V_365 ) ;
F_172 ( & V_2 -> V_354 , F_145 ) ;
F_172 ( & V_2 -> V_330 , F_141 ) ;
F_173 ( & V_2 -> V_107 ) ;
F_173 ( & V_2 -> V_69 . V_204 ) ;
F_171 ( & V_2 -> V_69 . V_197 ) ;
V_8 = F_174 ( V_105 , V_370 , F_150 , V_410 , V_411 , V_2 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_56 ) ;
goto V_397;
}
V_8 = F_175 ( V_103 , V_103 -> V_398 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_57 ) ;
goto V_397;
}
V_8 = F_176 ( V_103 , V_2 -> V_105 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_58 ) ;
goto V_397;
}
V_8 = F_110 ( V_2 ) ;
if ( V_8 ) {
F_50 ( V_2 -> V_105 , L_59 ) ;
goto V_412;
}
* V_392 = V_2 ;
F_143 ( V_105 ) ;
F_177 ( F_159 , V_2 ) ;
return 0 ;
V_412:
F_167 ( V_2 -> V_103 ) ;
V_397:
F_168 ( V_103 ) ;
V_395:
return V_8 ;
}
