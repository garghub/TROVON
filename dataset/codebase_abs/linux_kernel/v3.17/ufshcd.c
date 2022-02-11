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
int F_39 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_67 * V_68 = & V_2 -> V_69 . V_70 . V_71 ;
memcpy ( & V_68 -> V_72 , & V_20 -> V_40 -> V_73 , V_74 ) ;
if ( V_20 -> V_40 -> V_73 . V_75 == V_76 ) {
T_2 * V_77 = ( T_2 * ) V_20 -> V_40 +
V_78 ;
T_3 V_79 ;
T_3 V_80 ;
V_79 = F_23 ( V_20 -> V_40 -> V_22 . V_23 ) &
V_81 ;
V_80 = F_37 (
V_2 -> V_69 . V_70 . V_82 . V_83 . V_84 ) ;
if ( F_40 ( V_80 >= V_79 ) ) {
memcpy ( V_2 -> V_69 . V_70 . V_85 , V_77 , V_79 ) ;
} else {
F_41 ( V_2 -> V_86 ,
L_1 ,
V_87 ) ;
return - V_88 ;
}
}
return 0 ;
}
static inline void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_89 = F_3 ( V_2 , V_90 ) ;
V_2 -> V_91 = ( V_2 -> V_89 & V_92 ) + 1 ;
V_2 -> V_32 =
( ( V_2 -> V_89 & V_93 ) >> 16 ) + 1 ;
}
static inline bool F_43 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_94 ) & V_95 )
return true ;
else
return false ;
}
static inline T_2 F_44 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_94 ) >> 8 ) & 0x7 ;
}
static inline void
F_45 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
F_46 ( V_2 -> V_98 ) ;
V_2 -> V_98 = V_97 ;
F_18 ( V_2 , V_97 -> V_99 , V_100 ) ;
F_18 ( V_2 , V_97 -> V_101 , V_36 ) ;
F_18 ( V_2 , V_97 -> V_102 , V_38 ) ;
F_18 ( V_2 , V_97 -> V_103 & V_104 ,
V_105 ) ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
int V_29 ;
unsigned long V_106 ;
if ( F_48 ( & V_97 -> V_107 ,
F_2 ( V_108 ) ) )
V_29 = V_97 -> V_101 & V_37 ;
else
V_29 = - V_11 ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_2 -> V_98 = NULL ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
return V_29 ;
}
static int
F_51 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
int V_29 ;
unsigned long V_106 ;
if ( ! F_43 ( V_2 ) ) {
F_52 ( V_2 -> V_86 ,
L_2 ) ;
return - V_111 ;
}
F_53 ( & V_97 -> V_107 ) ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_45 ( V_2 , V_97 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_29 = F_47 ( V_2 , V_97 ) ;
return V_29 ;
}
static int
F_54 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
int V_29 ;
F_55 ( & V_2 -> V_112 ) ;
V_29 = F_51 ( V_2 , V_97 ) ;
F_56 ( & V_2 -> V_112 ) ;
return V_29 ;
}
static int F_57 ( struct V_19 * V_20 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
int V_119 ;
int V_120 ;
V_118 = V_20 -> V_118 ;
V_119 = F_58 ( V_118 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_119 ) {
V_20 -> V_21 -> V_121 =
F_59 ( ( T_3 ) ( V_119 ) ) ;
V_114 = (struct V_113 * ) V_20 -> V_122 ;
F_60 (cmd, sg, sg_segments, i) {
V_114 [ V_120 ] . V_123 =
F_61 ( ( ( T_1 ) F_62 ( V_116 ) ) - 1 ) ;
V_114 [ V_120 ] . V_124 =
F_61 ( F_63 ( V_116 -> V_125 ) ) ;
V_114 [ V_120 ] . V_126 =
F_61 ( F_64 ( V_116 -> V_125 ) ) ;
}
} else {
V_20 -> V_21 -> V_121 = 0 ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , T_1 V_127 )
{
T_1 V_128 = F_3 ( V_2 , V_129 ) ;
if ( V_2 -> V_12 == V_13 ) {
T_1 V_130 ;
V_130 = V_128 & V_131 ;
V_128 = V_130 | ( ( V_128 ^ V_127 ) & V_127 ) ;
} else {
V_128 |= V_127 ;
}
F_18 ( V_2 , V_128 , V_129 ) ;
}
static void F_66 ( struct V_1 * V_2 , T_1 V_127 )
{
T_1 V_128 = F_3 ( V_2 , V_129 ) ;
if ( V_2 -> V_12 == V_13 ) {
T_1 V_130 ;
V_130 = ( V_128 & V_131 ) &
~ ( V_127 & V_131 ) ;
V_128 = V_130 | ( ( V_128 & V_127 ) & ~ V_131 ) ;
} else {
V_128 &= ~ V_127 ;
}
F_18 ( V_2 , V_128 , V_129 ) ;
}
static void F_67 ( struct V_19 * V_20 ,
T_1 * V_132 , enum V_133 V_134 )
{
struct V_135 * V_136 = V_20 -> V_21 ;
T_1 V_137 ;
T_1 V_41 ;
if ( V_134 == V_138 ) {
V_137 = V_139 ;
* V_132 = V_140 ;
} else if ( V_134 == V_141 ) {
V_137 = V_142 ;
* V_132 = V_143 ;
} else {
V_137 = V_144 ;
* V_132 = V_145 ;
}
V_41 = V_137 | ( V_20 -> V_146
<< V_147 ) ;
if ( V_20 -> V_148 )
V_41 |= V_149 ;
V_136 -> V_22 . V_41 = F_61 ( V_41 ) ;
V_136 -> V_22 . V_23 =
F_61 ( V_150 ) ;
}
static
void F_68 ( struct V_19 * V_20 , T_1 V_132 )
{
struct V_151 * V_152 = V_20 -> V_152 ;
V_152 -> V_22 . V_41 = F_69 (
V_153 , V_132 ,
V_20 -> V_154 , V_20 -> V_58 ) ;
V_152 -> V_22 . V_42 = F_69 (
V_155 , 0 , 0 , 0 ) ;
V_152 -> V_22 . V_23 = 0 ;
V_152 -> V_156 . V_157 =
F_70 ( V_20 -> V_118 -> V_158 . V_84 ) ;
memcpy ( V_152 -> V_156 . V_159 , V_20 -> V_118 -> V_160 ,
( F_38 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ) ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_19 * V_20 , T_1 V_132 )
{
struct V_151 * V_152 = V_20 -> V_152 ;
struct V_161 * V_70 = & V_2 -> V_69 . V_70 ;
T_3 V_61 = F_37 ( V_70 -> V_82 . V_83 . V_84 ) ;
T_2 * V_77 = ( T_2 * ) V_20 -> V_152 + V_78 ;
V_152 -> V_22 . V_41 = F_69 (
V_162 , V_132 ,
V_20 -> V_154 , V_20 -> V_58 ) ;
V_152 -> V_22 . V_42 = F_69 (
0 , V_70 -> V_82 . V_163 , 0 , 0 ) ;
V_152 -> V_22 . V_23 = F_69 (
0 , 0 , V_61 >> 8 , ( T_2 ) V_61 ) ;
memcpy ( & V_152 -> V_73 , & V_70 -> V_82 . V_83 ,
V_74 ) ;
if ( V_70 -> V_82 . V_83 . V_75 == V_164 )
memcpy ( V_77 , V_70 -> V_85 , V_61 ) ;
}
static inline void F_72 ( struct V_19 * V_20 )
{
struct V_151 * V_152 = V_20 -> V_152 ;
memset ( V_152 , 0 , sizeof( struct V_151 ) ) ;
V_152 -> V_22 . V_41 =
F_69 (
V_165 , 0 , 0 , V_20 -> V_58 ) ;
}
static int F_73 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
T_1 V_132 ;
int V_29 = 0 ;
switch ( V_20 -> V_146 ) {
case V_166 :
if ( F_40 ( V_20 -> V_118 ) ) {
F_67 ( V_20 , & V_132 ,
V_20 -> V_118 -> V_167 ) ;
F_68 ( V_20 , V_132 ) ;
} else {
V_29 = - V_88 ;
}
break;
case V_168 :
F_67 ( V_20 , & V_132 , V_169 ) ;
if ( V_2 -> V_69 . type == V_170 )
F_71 (
V_2 , V_20 , V_132 ) ;
else if ( V_2 -> V_69 . type == V_171 )
F_72 ( V_20 ) ;
else
V_29 = - V_88 ;
break;
case V_172 :
V_29 = - V_173 ;
F_52 ( V_2 -> V_86 , L_3 ,
V_87 ) ;
break;
default:
V_29 = - V_173 ;
F_52 ( V_2 -> V_86 , L_4 ,
V_87 , V_20 -> V_146 ) ;
break;
}
return V_29 ;
}
static int F_74 ( struct V_174 * V_109 , struct V_117 * V_118 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned long V_106 ;
int V_28 ;
int V_8 = 0 ;
V_2 = F_75 ( V_109 ) ;
V_28 = V_118 -> V_82 -> V_28 ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
switch ( V_2 -> V_175 ) {
case V_176 :
break;
case V_177 :
V_8 = V_178 ;
goto V_179;
case V_180 :
F_76 ( V_118 , V_181 ) ;
V_118 -> V_182 ( V_118 ) ;
goto V_179;
default:
F_77 ( V_2 -> V_86 , 1 , L_5 ,
V_87 , V_2 -> V_175 ) ;
F_76 ( V_118 , V_183 ) ;
V_118 -> V_182 ( V_118 ) ;
goto V_179;
}
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
if ( F_14 ( V_28 , & V_2 -> V_184 ) ) {
V_8 = V_178 ;
goto V_30;
}
V_20 = & V_2 -> V_185 [ V_28 ] ;
F_46 ( V_20 -> V_118 ) ;
V_20 -> V_118 = V_118 ;
V_20 -> V_186 = V_66 ;
V_20 -> V_62 = V_118 -> V_62 ;
V_20 -> V_58 = V_28 ;
V_20 -> V_154 = V_118 -> V_187 -> V_154 ;
V_20 -> V_148 = false ;
V_20 -> V_146 = V_166 ;
F_73 ( V_2 , V_20 ) ;
V_8 = F_57 ( V_20 ) ;
if ( V_8 ) {
V_20 -> V_118 = NULL ;
F_16 ( V_28 , & V_2 -> V_184 ) ;
goto V_30;
}
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_34 ( V_2 , V_28 ) ;
V_179:
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_30:
return V_8 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_19 * V_20 , enum V_188 V_189 , int V_28 )
{
V_20 -> V_118 = NULL ;
V_20 -> V_186 = 0 ;
V_20 -> V_62 = NULL ;
V_20 -> V_58 = V_28 ;
V_20 -> V_154 = 0 ;
V_20 -> V_146 = V_168 ;
V_20 -> V_148 = true ;
V_2 -> V_69 . type = V_189 ;
return F_73 ( V_2 , V_20 ) ;
}
static int
F_79 ( struct V_1 * V_2 , int V_28 )
{
int V_8 = 0 ;
unsigned long V_106 ;
T_1 V_4 = 1 << V_28 ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_17 ( V_2 , V_28 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_8 = F_1 ( V_2 ,
V_60 ,
V_4 , ~ V_4 , 1000 , 1000 ) ;
return V_8 ;
}
static int
F_80 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_67 * V_68 = & V_2 -> V_69 . V_70 . V_71 ;
V_68 -> V_71 = F_24 ( V_20 -> V_40 ) >>
V_190 ;
return V_68 -> V_71 ;
}
static int
F_81 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_191 ;
int V_8 = 0 ;
V_191 = F_22 ( V_20 -> V_40 ) ;
switch ( V_191 ) {
case V_192 :
if ( V_2 -> V_69 . type != V_171 ) {
V_8 = - V_88 ;
F_52 ( V_2 -> V_86 , L_6 ,
V_87 , V_191 ) ;
}
break;
case V_193 :
V_8 = F_80 ( V_2 , V_20 ) ;
if ( ! V_8 )
V_8 = F_39 ( V_2 , V_20 ) ;
break;
case V_194 :
V_8 = - V_195 ;
F_52 ( V_2 -> V_86 , L_7 ,
V_87 ) ;
break;
default:
V_8 = - V_88 ;
F_52 ( V_2 -> V_86 , L_8 ,
V_87 , V_191 ) ;
break;
}
return V_8 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_19 * V_20 , int V_196 )
{
int V_8 = 0 ;
unsigned long V_197 ;
unsigned long V_106 ;
V_197 = F_48 ( V_2 -> V_69 . V_198 ,
F_2 ( V_196 ) ) ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_2 -> V_69 . V_198 = NULL ;
if ( F_40 ( V_197 ) ) {
V_8 = F_9 ( V_20 ) ;
if ( ! V_8 )
V_8 = F_81 ( V_2 , V_20 ) ;
}
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
if ( ! V_197 ) {
V_8 = - V_11 ;
if ( ! F_79 ( V_2 , V_20 -> V_58 ) )
V_8 = - V_199 ;
}
return V_8 ;
}
static bool F_83 ( struct V_1 * V_2 , int * V_200 )
{
int V_28 ;
bool V_29 = false ;
unsigned long V_201 ;
if ( ! V_200 )
goto V_30;
do {
V_201 = ~ V_2 -> V_184 ;
V_28 = F_84 ( & V_201 , V_2 -> V_91 ) ;
if ( V_28 >= V_2 -> V_91 )
goto V_30;
} while ( F_14 ( V_28 , & V_2 -> V_184 ) );
* V_200 = V_28 ;
V_29 = true ;
V_30:
return V_29 ;
}
static inline void F_85 ( struct V_1 * V_2 , int V_28 )
{
F_16 ( V_28 , & V_2 -> V_184 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
enum V_188 V_189 , int V_9 )
{
struct V_19 * V_20 ;
int V_8 ;
int V_28 ;
struct V_202 V_203 ;
unsigned long V_106 ;
F_87 ( V_2 -> V_69 . V_204 , F_83 ( V_2 , & V_28 ) ) ;
F_53 ( & V_203 ) ;
V_20 = & V_2 -> V_185 [ V_28 ] ;
F_46 ( V_20 -> V_118 ) ;
V_8 = F_78 ( V_2 , V_20 , V_189 , V_28 ) ;
if ( F_88 ( V_8 ) )
goto V_205;
V_2 -> V_69 . V_198 = & V_203 ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_34 ( V_2 , V_28 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_8 = F_82 ( V_2 , V_20 , V_9 ) ;
V_205:
F_85 ( V_2 , V_28 ) ;
F_89 ( & V_2 -> V_69 . V_204 ) ;
return V_8 ;
}
static inline void F_90 ( struct V_1 * V_2 ,
struct V_206 * * V_82 , struct V_67 * * V_71 ,
enum V_207 V_75 , T_2 V_208 , T_2 V_209 , T_2 V_210 )
{
* V_82 = & V_2 -> V_69 . V_70 . V_82 ;
* V_71 = & V_2 -> V_69 . V_70 . V_71 ;
memset ( * V_82 , 0 , sizeof( struct V_206 ) ) ;
memset ( * V_71 , 0 , sizeof( struct V_67 ) ) ;
( * V_82 ) -> V_83 . V_75 = V_75 ;
( * V_82 ) -> V_83 . V_208 = V_208 ;
( * V_82 ) -> V_83 . V_209 = V_209 ;
( * V_82 ) -> V_83 . V_210 = V_210 ;
}
static int F_91 ( struct V_1 * V_2 , enum V_207 V_75 ,
enum V_211 V_208 , bool * V_212 )
{
struct V_206 * V_82 = NULL ;
struct V_67 * V_71 = NULL ;
int V_8 , V_209 = 0 , V_210 = 0 ;
F_92 ( ! V_2 ) ;
F_55 ( & V_2 -> V_69 . V_213 ) ;
F_90 ( V_2 , & V_82 , & V_71 , V_75 , V_208 , V_209 ,
V_210 ) ;
switch ( V_75 ) {
case V_214 :
case V_215 :
case V_216 :
V_82 -> V_163 = V_217 ;
break;
case V_218 :
V_82 -> V_163 = V_219 ;
if ( ! V_212 ) {
F_52 ( V_2 -> V_86 , L_9 ,
V_87 ) ;
V_8 = - V_88 ;
goto V_179;
}
break;
default:
F_52 ( V_2 -> V_86 ,
L_10 ,
V_87 , V_75 ) ;
V_8 = - V_88 ;
goto V_179;
}
V_8 = F_86 ( V_2 , V_170 , V_220 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 ,
L_11 ,
V_87 , V_208 , V_8 ) ;
goto V_179;
}
if ( V_212 )
* V_212 = ( F_23 ( V_71 -> V_72 . V_221 ) &
V_222 ) & 0x1 ;
V_179:
F_56 ( & V_2 -> V_69 . V_213 ) ;
return V_8 ;
}
static int F_93 ( struct V_1 * V_2 , enum V_207 V_75 ,
enum V_223 V_208 , T_2 V_209 , T_2 V_210 , T_1 * V_224 )
{
struct V_206 * V_82 = NULL ;
struct V_67 * V_71 = NULL ;
int V_8 ;
F_92 ( ! V_2 ) ;
if ( ! V_224 ) {
F_52 ( V_2 -> V_86 , L_12 ,
V_87 , V_75 ) ;
V_8 = - V_88 ;
goto V_30;
}
F_55 ( & V_2 -> V_69 . V_213 ) ;
F_90 ( V_2 , & V_82 , & V_71 , V_75 , V_208 , V_209 ,
V_210 ) ;
switch ( V_75 ) {
case V_225 :
V_82 -> V_163 = V_217 ;
V_82 -> V_83 . V_221 = F_70 ( * V_224 ) ;
break;
case V_226 :
V_82 -> V_163 = V_219 ;
break;
default:
F_52 ( V_2 -> V_86 , L_13 ,
V_87 , V_75 ) ;
V_8 = - V_88 ;
goto V_179;
}
V_8 = F_86 ( V_2 , V_170 , V_220 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_14 ,
V_87 , V_75 , V_208 , V_8 ) ;
goto V_179;
}
* V_224 = F_23 ( V_71 -> V_72 . V_221 ) ;
V_179:
F_56 ( & V_2 -> V_69 . V_213 ) ;
V_30:
return V_8 ;
}
static int F_94 ( struct V_1 * V_2 ,
enum V_207 V_75 , enum V_227 V_208 , T_2 V_209 ,
T_2 V_210 , T_2 * V_228 , int * V_80 )
{
struct V_206 * V_82 = NULL ;
struct V_67 * V_71 = NULL ;
int V_8 ;
F_92 ( ! V_2 ) ;
if ( ! V_228 ) {
F_52 ( V_2 -> V_86 , L_15 ,
V_87 , V_75 ) ;
V_8 = - V_88 ;
goto V_30;
}
if ( * V_80 <= V_229 || * V_80 > V_230 ) {
F_52 ( V_2 -> V_86 , L_16 ,
V_87 , * V_80 ) ;
V_8 = - V_88 ;
goto V_30;
}
F_55 ( & V_2 -> V_69 . V_213 ) ;
F_90 ( V_2 , & V_82 , & V_71 , V_75 , V_208 , V_209 ,
V_210 ) ;
V_2 -> V_69 . V_70 . V_85 = V_228 ;
V_82 -> V_83 . V_84 = F_95 ( * V_80 ) ;
switch ( V_75 ) {
case V_164 :
V_82 -> V_163 = V_217 ;
break;
case V_76 :
V_82 -> V_163 = V_219 ;
break;
default:
F_52 ( V_2 -> V_86 ,
L_17 ,
V_87 , V_75 ) ;
V_8 = - V_88 ;
goto V_179;
}
V_8 = F_86 ( V_2 , V_170 , V_220 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_14 ,
V_87 , V_75 , V_208 , V_8 ) ;
goto V_179;
}
V_2 -> V_69 . V_70 . V_85 = NULL ;
* V_80 = F_37 ( V_71 -> V_72 . V_84 ) ;
V_179:
F_56 ( & V_2 -> V_69 . V_213 ) ;
V_30:
return V_8 ;
}
static int F_96 ( struct V_1 * V_2 )
{
T_4 V_231 , V_232 , V_233 ;
V_233 = ( sizeof( struct V_234 ) * V_2 -> V_91 ) ;
V_2 -> V_235 = F_97 ( V_2 -> V_86 ,
V_233 ,
& V_2 -> V_236 ,
V_237 ) ;
if ( ! V_2 -> V_235 ||
F_46 ( V_2 -> V_236 & ( V_238 - 1 ) ) ) {
F_52 ( V_2 -> V_86 ,
L_18 ) ;
goto V_30;
}
V_232 = ( sizeof( struct V_135 ) * V_2 -> V_91 ) ;
V_2 -> V_239 = F_97 ( V_2 -> V_86 ,
V_232 ,
& V_2 -> V_240 ,
V_237 ) ;
if ( ! V_2 -> V_239 ||
F_46 ( V_2 -> V_240 & ( V_238 - 1 ) ) ) {
F_52 ( V_2 -> V_86 ,
L_19 ) ;
goto V_30;
}
V_231 = sizeof( struct V_25 ) * V_2 -> V_32 ;
V_2 -> V_241 = F_97 ( V_2 -> V_86 ,
V_231 ,
& V_2 -> V_242 ,
V_237 ) ;
if ( ! V_2 -> V_241 ||
F_46 ( V_2 -> V_242 & ( V_238 - 1 ) ) ) {
F_52 ( V_2 -> V_86 ,
L_20 ) ;
goto V_30;
}
V_2 -> V_185 = F_98 ( V_2 -> V_86 ,
V_2 -> V_91 * sizeof( struct V_19 ) ,
V_237 ) ;
if ( ! V_2 -> V_185 ) {
F_52 ( V_2 -> V_86 , L_21 ) ;
goto V_30;
}
return 0 ;
V_30:
return - V_243 ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_234 * V_244 ;
struct V_135 * V_245 ;
T_5 V_246 ;
T_5 V_247 ;
T_3 V_248 ;
T_3 V_249 ;
int V_250 ;
int V_120 ;
V_245 = V_2 -> V_239 ;
V_244 = V_2 -> V_235 ;
V_248 =
F_100 ( struct V_234 , V_251 ) ;
V_249 =
F_100 ( struct V_234 , V_114 ) ;
V_250 = sizeof( struct V_234 ) ;
V_246 = V_2 -> V_236 ;
for ( V_120 = 0 ; V_120 < V_2 -> V_91 ; V_120 ++ ) {
V_247 =
( V_246 + ( V_250 * V_120 ) ) ;
V_245 [ V_120 ] . V_252 =
F_61 ( F_63 ( V_247 ) ) ;
V_245 [ V_120 ] . V_253 =
F_61 ( F_64 ( V_247 ) ) ;
V_245 [ V_120 ] . V_254 =
F_59 ( ( V_248 >> 2 ) ) ;
V_245 [ V_120 ] . V_255 =
F_59 ( ( V_249 >> 2 ) ) ;
V_245 [ V_120 ] . V_256 =
F_59 ( V_257 >> 2 ) ;
V_2 -> V_185 [ V_120 ] . V_21 = ( V_245 + V_120 ) ;
V_2 -> V_185 [ V_120 ] . V_152 =
(struct V_151 * ) ( V_244 + V_120 ) ;
V_2 -> V_185 [ V_120 ] . V_40 =
(struct V_39 * ) V_244 [ V_120 ] . V_251 ;
V_2 -> V_185 [ V_120 ] . V_122 =
(struct V_113 * ) V_244 [ V_120 ] . V_114 ;
}
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_96 V_97 = { 0 } ;
int V_29 ;
V_97 . V_103 = V_258 ;
V_29 = F_54 ( V_2 , & V_97 ) ;
if ( V_29 )
F_52 ( V_2 -> V_86 ,
L_22 , V_29 ) ;
return V_29 ;
}
int F_102 ( struct V_1 * V_2 , T_1 V_259 ,
T_2 V_260 , T_1 V_261 , T_2 V_262 )
{
struct V_96 V_97 = { 0 } ;
static const char * const V_263 [] = {
L_23 ,
L_24
} ;
const char * V_128 = V_263 [ ! ! V_262 ] ;
int V_29 ;
V_97 . V_103 = V_262 ?
V_264 : V_265 ;
V_97 . V_99 = V_259 ;
V_97 . V_101 = F_103 ( V_260 ) ;
V_97 . V_102 = V_261 ;
V_29 = F_54 ( V_2 , & V_97 ) ;
if ( V_29 )
F_52 ( V_2 -> V_86 , L_25 ,
V_128 , F_104 ( V_259 ) , V_261 , V_29 ) ;
return V_29 ;
}
int F_105 ( struct V_1 * V_2 , T_1 V_259 ,
T_1 * V_261 , T_2 V_262 )
{
struct V_96 V_97 = { 0 } ;
static const char * const V_263 [] = {
L_26 ,
L_27
} ;
const char * V_266 = V_263 [ ! ! V_262 ] ;
int V_29 ;
V_97 . V_103 = V_262 ?
V_267 : V_268 ;
V_97 . V_99 = V_259 ;
V_29 = F_54 ( V_2 , & V_97 ) ;
if ( V_29 ) {
F_52 ( V_2 -> V_86 , L_28 ,
V_266 , F_104 ( V_259 ) , V_29 ) ;
goto V_30;
}
if ( V_261 )
* V_261 = V_97 . V_102 ;
V_30:
return V_29 ;
}
static int F_106 ( struct V_1 * V_2 , T_2 V_269 )
{
struct V_96 V_97 = { 0 } ;
struct V_202 V_270 ;
unsigned long V_106 ;
T_2 V_271 ;
int V_29 ;
V_97 . V_103 = V_265 ;
V_97 . V_99 = F_107 ( V_272 ) ;
V_97 . V_102 = V_269 ;
F_53 ( & V_270 ) ;
F_55 ( & V_2 -> V_112 ) ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_2 -> V_270 = & V_270 ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_29 = F_51 ( V_2 , & V_97 ) ;
if ( V_29 ) {
F_52 ( V_2 -> V_86 ,
L_29 ,
V_269 , V_29 ) ;
goto V_30;
}
if ( ! F_48 ( V_2 -> V_270 ,
F_2 ( V_108 ) ) ) {
F_52 ( V_2 -> V_86 ,
L_30 ,
V_269 ) ;
V_29 = - V_11 ;
goto V_30;
}
V_271 = F_44 ( V_2 ) ;
if ( V_271 != V_273 ) {
F_52 ( V_2 -> V_86 ,
L_31 ,
V_271 ) ;
V_29 = ( V_271 != V_274 ) ? V_271 : - 1 ;
}
V_30:
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_2 -> V_270 = NULL ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_56 ( & V_2 -> V_112 ) ;
return V_29 ;
}
static int F_108 ( struct V_1 * V_2 )
{
enum { V_275 = 0 , V_276 = 1 };
T_1 V_277 [] = { 1 , 1 } ;
T_1 V_278 [] = { 1 , 1 } ;
T_2 V_279 [] = { V_280 , V_280 } ;
int V_29 ;
F_109 ( V_2 , F_107 ( V_281 ) , & V_277 [ V_275 ] ) ;
F_109 ( V_2 , F_107 ( V_282 ) , & V_277 [ V_276 ] ) ;
F_109 ( V_2 , F_107 ( V_283 ) , & V_278 [ V_275 ] ) ;
if ( ! V_278 [ V_275 ] ) {
F_109 ( V_2 , F_107 ( V_284 ) , & V_278 [ V_275 ] ) ;
V_279 [ V_275 ] = V_285 ;
}
F_110 ( V_2 , F_107 ( V_283 ) , & V_278 [ V_276 ] ) ;
if ( ! V_278 [ V_276 ] ) {
F_110 ( V_2 , F_107 ( V_284 ) ,
& V_278 [ V_276 ] ) ;
V_279 [ V_276 ] = V_285 ;
}
F_111 ( V_2 , F_107 ( V_286 ) , V_278 [ V_275 ] ) ;
F_111 ( V_2 , F_107 ( V_287 ) , V_277 [ V_275 ] ) ;
if ( V_279 [ V_275 ] == V_280 )
F_111 ( V_2 , F_107 ( V_288 ) , TRUE ) ;
F_111 ( V_2 , F_107 ( V_289 ) , V_278 [ V_276 ] ) ;
F_111 ( V_2 , F_107 ( V_290 ) , V_277 [ V_276 ] ) ;
if ( V_279 [ V_276 ] == V_280 )
F_111 ( V_2 , F_107 ( V_291 ) , TRUE ) ;
if ( V_279 [ V_275 ] == V_280 || V_279 [ V_276 ] == V_280 )
F_111 ( V_2 , F_107 ( V_292 ) , V_293 ) ;
V_29 = F_106 ( V_2 , V_279 [ V_275 ] << 4 | V_279 [ V_276 ] ) ;
if ( V_29 )
F_52 ( V_2 -> V_86 ,
L_32 , V_29 ) ;
return V_29 ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_120 , V_294 , V_8 = 0 ;
bool V_212 = 1 ;
for ( V_294 = V_295 ; V_294 > 0 ; V_294 -- ) {
V_8 = F_91 ( V_2 , V_214 ,
V_296 , NULL ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_113 ( V_2 -> V_86 , L_33 , V_87 , V_8 ) ;
}
if ( V_8 ) {
F_52 ( V_2 -> V_86 ,
L_34 ,
V_87 , V_8 ) ;
goto V_30;
}
for ( V_120 = 0 ; V_120 < 100 && ! V_8 && V_212 ; V_120 ++ ) {
for ( V_294 = V_295 ; V_294 > 0 ; V_294 -- ) {
V_8 = F_91 ( V_2 ,
V_218 ,
V_296 , & V_212 ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_113 ( V_2 -> V_86 , L_33 , V_87 ,
V_8 ) ;
}
}
if ( V_8 )
F_52 ( V_2 -> V_86 ,
L_35 ,
V_87 , V_8 ) ;
else if ( V_212 )
F_52 ( V_2 -> V_86 ,
L_36 ,
V_87 ) ;
V_30:
return V_8 ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_94 ) ;
if ( ! F_8 ( V_3 ) ) {
F_52 ( V_2 -> V_86 , L_37 ) ;
V_8 = - V_297 ;
goto V_30;
}
F_65 ( V_2 , V_298 ) ;
F_28 ( V_2 , V_2 -> V_91 - 1 , V_299 ) ;
F_18 ( V_2 , F_63 ( V_2 -> V_240 ) ,
V_300 ) ;
F_18 ( V_2 , F_64 ( V_2 -> V_240 ) ,
V_301 ) ;
F_18 ( V_2 , F_63 ( V_2 -> V_242 ) ,
V_302 ) ;
F_18 ( V_2 , F_64 ( V_2 -> V_242 ) ,
V_303 ) ;
if ( ! ( F_19 ( V_3 ) ) ) {
F_31 ( V_2 ) ;
} else {
F_52 ( V_2 -> V_86 ,
L_38 ) ;
V_8 = - V_111 ;
goto V_30;
}
V_30:
return V_8 ;
}
static int F_115 ( struct V_1 * V_2 )
{
int V_304 ;
if ( ! F_33 ( V_2 ) ) {
F_116 ( V_2 ) ;
F_117 ( 5 ) ;
}
F_32 ( V_2 ) ;
F_117 ( 1 ) ;
V_304 = 10 ;
while ( F_33 ( V_2 ) ) {
if ( V_304 ) {
V_304 -- ;
} else {
F_52 ( V_2 -> V_86 ,
L_39 ) ;
return - V_111 ;
}
F_117 ( 5 ) ;
}
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
int V_29 ;
F_65 ( V_2 , V_305 ) ;
V_29 = F_101 ( V_2 ) ;
if ( V_29 )
goto V_30;
V_29 = F_114 ( V_2 ) ;
V_30:
if ( V_29 )
F_52 ( V_2 -> V_86 , L_40 , V_29 ) ;
return V_29 ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
int V_294 ;
F_55 ( & V_2 -> V_69 . V_213 ) ;
for ( V_294 = V_306 ; V_294 > 0 ; V_294 -- ) {
V_8 = F_86 ( V_2 , V_171 ,
V_307 ) ;
if ( ! V_8 || V_8 == - V_11 )
break;
F_113 ( V_2 -> V_86 , L_33 , V_87 , V_8 ) ;
}
F_56 ( & V_2 -> V_69 . V_213 ) ;
if ( V_8 )
F_52 ( V_2 -> V_86 , L_41 , V_87 , V_8 ) ;
return V_8 ;
}
static int F_120 ( struct V_308 * V_309 )
{
struct V_1 * V_2 ;
int V_310 ;
V_2 = F_75 ( V_309 -> V_109 ) ;
V_309 -> V_311 = 1 ;
V_309 -> V_312 = 1 ;
F_121 ( V_309 , V_313 ) ;
V_309 -> V_314 = 1 ;
V_309 -> V_315 = 1 ;
V_310 = F_122 ( V_2 , V_309 ) ;
if ( V_310 <= 0 )
V_310 = V_2 -> V_91 ;
else
V_310 = F_38 ( int , V_310 , V_2 -> V_91 ) ;
F_113 ( V_2 -> V_86 , L_42 ,
V_87 , V_310 ) ;
F_123 ( V_309 , V_310 ) ;
return 0 ;
}
static int F_124 ( struct V_308 * V_309 ,
int V_316 , int V_317 )
{
struct V_1 * V_2 = F_75 ( V_309 -> V_109 ) ;
if ( V_316 > V_2 -> V_91 )
V_316 = V_2 -> V_91 ;
switch ( V_317 ) {
case V_318 :
case V_319 :
if ( ! V_309 -> V_311 )
V_316 = 1 ;
F_125 ( V_309 , F_126 ( V_309 ) , V_316 ) ;
break;
case V_320 :
F_127 ( V_309 , V_316 ) ;
break;
default:
return - V_321 ;
}
return V_316 ;
}
static int F_128 ( struct V_308 * V_309 )
{
struct V_322 * V_323 = V_309 -> V_322 ;
F_129 ( V_323 , V_324 - 1 ) ;
F_130 ( V_323 , V_325 ) ;
return 0 ;
}
static void F_131 ( struct V_308 * V_309 )
{
struct V_1 * V_2 ;
V_2 = F_75 ( V_309 -> V_109 ) ;
F_132 ( V_309 , V_2 -> V_91 ) ;
}
static int F_133 ( struct V_1 * V_2 , T_1 V_209 , T_2 * V_191 )
{
struct V_25 * V_26 ;
struct V_326 * V_327 ;
unsigned long V_106 ;
int V_328 ;
int V_329 ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_134 ( V_209 , & V_2 -> V_330 ) ;
V_26 = V_2 -> V_241 ;
V_328 = F_11 ( & V_26 [ V_209 ] ) ;
if ( V_328 == V_331 ) {
V_327 = (struct V_326 * )
V_26 [ V_209 ] . V_332 ;
V_329 = F_23 ( V_327 -> V_22 . V_42 ) ;
V_329 = ( ( V_329 & V_333 ) >> 8 ) ;
if ( V_191 )
* V_191 = ( T_2 ) V_329 ;
} else {
F_52 ( V_2 -> V_86 , L_43 ,
V_87 , V_328 ) ;
}
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
return V_328 ;
}
static inline int
F_135 ( struct V_19 * V_20 , int V_334 )
{
int V_335 = 0 ;
switch ( V_334 ) {
case V_336 :
F_36 ( V_20 ) ;
case V_337 :
V_335 |= V_338 << 16 |
V_339 << 8 |
V_334 ;
break;
case V_340 :
case V_341 :
case V_342 :
F_36 ( V_20 ) ;
V_335 |= V_334 ;
break;
default:
V_335 |= V_181 << 16 ;
break;
}
return V_335 ;
}
static inline int
F_136 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_335 = 0 ;
int V_334 ;
int V_343 ;
V_343 = F_9 ( V_20 ) ;
switch ( V_343 ) {
case V_331 :
V_335 = F_22 ( V_20 -> V_40 ) ;
switch ( V_335 ) {
case V_344 :
V_335 = F_24 ( V_20 -> V_40 ) ;
V_334 = V_335 & V_345 ;
V_335 = F_135 ( V_20 , V_334 ) ;
if ( F_26 ( V_20 -> V_40 ) )
F_137 ( & V_2 -> V_346 ) ;
break;
case V_194 :
V_335 = V_181 << 16 ;
F_52 ( V_2 -> V_86 ,
L_44 ) ;
break;
default:
V_335 = V_181 << 16 ;
F_52 ( V_2 -> V_86 ,
L_45 ,
V_335 ) ;
break;
}
break;
case V_347 :
V_335 |= V_348 << 16 ;
break;
case V_150 :
V_335 |= V_349 << 16 ;
break;
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
default:
V_335 |= V_181 << 16 ;
F_52 ( V_2 -> V_86 ,
L_46 , V_343 ) ;
break;
}
return V_335 ;
}
static void F_138 ( struct V_1 * V_2 , T_1 V_356 )
{
if ( ( V_356 & V_305 ) && V_2 -> V_98 ) {
V_2 -> V_98 -> V_101 |=
F_20 ( V_2 ) ;
V_2 -> V_98 -> V_102 =
F_21 ( V_2 ) ;
V_198 ( & V_2 -> V_98 -> V_107 ) ;
}
if ( ( V_356 & V_357 ) && V_2 -> V_270 )
V_198 ( V_2 -> V_270 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_117 * V_118 ;
unsigned long V_358 ;
T_1 V_359 ;
int V_335 ;
int V_209 ;
F_27 ( V_2 ) ;
V_359 = F_3 ( V_2 , V_60 ) ;
V_358 = V_359 ^ V_2 -> V_59 ;
F_140 (index, &completed_reqs, hba->nutrs) {
V_20 = & V_2 -> V_185 [ V_209 ] ;
V_118 = V_20 -> V_118 ;
if ( V_118 ) {
V_335 = F_136 ( V_2 , V_20 ) ;
F_141 ( V_118 ) ;
V_118 -> V_335 = V_335 ;
V_20 -> V_118 = NULL ;
F_16 ( V_209 , & V_2 -> V_184 ) ;
V_118 -> V_182 ( V_118 ) ;
} else if ( V_20 -> V_146 == V_168 ) {
if ( V_2 -> V_69 . V_198 )
V_198 ( V_2 -> V_69 . V_198 ) ;
}
}
V_2 -> V_59 ^= V_358 ;
F_89 ( & V_2 -> V_69 . V_204 ) ;
}
static int F_142 ( struct V_1 * V_2 , T_3 V_4 )
{
int V_8 = 0 ;
T_1 V_5 ;
if ( ! ( V_2 -> V_360 & V_4 ) )
goto V_30;
V_5 = V_2 -> V_360 & ~ V_4 ;
V_5 &= 0xFFFF ;
V_8 = F_93 ( V_2 , V_225 ,
V_361 , 0 , 0 , & V_5 ) ;
if ( ! V_8 )
V_2 -> V_360 &= ~ V_4 ;
V_30:
return V_8 ;
}
static int F_143 ( struct V_1 * V_2 , T_3 V_4 )
{
int V_8 = 0 ;
T_1 V_5 ;
if ( V_2 -> V_360 & V_4 )
goto V_30;
V_5 = V_2 -> V_360 | V_4 ;
V_5 &= 0xFFFF ;
V_8 = F_93 ( V_2 , V_225 ,
V_361 , 0 , 0 , & V_5 ) ;
if ( ! V_8 )
V_2 -> V_360 |= V_4 ;
V_30:
return V_8 ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( V_2 -> V_362 )
goto V_30;
V_8 = F_91 ( V_2 , V_214 ,
V_363 , NULL ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_47 ,
V_87 , V_8 ) ;
goto V_30;
}
V_2 -> V_362 = true ;
V_8 = F_142 ( V_2 , V_364 ) ;
if ( V_8 )
F_52 ( V_2 -> V_86 , L_48 ,
V_87 , V_8 ) ;
V_30:
return V_8 ;
}
static int F_145 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( ! V_2 -> V_362 )
goto V_30;
V_8 = F_143 ( V_2 , V_364 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_49 ,
V_87 , V_8 ) ;
goto V_30;
}
V_8 = F_91 ( V_2 , V_215 ,
V_363 , NULL ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_50 ,
V_87 , V_8 ) ;
F_142 ( V_2 , V_364 ) ;
goto V_30;
}
V_2 -> V_362 = false ;
V_30:
return V_8 ;
}
static void F_146 ( struct V_1 * V_2 )
{
V_2 -> V_362 = false ;
V_2 -> V_360 |= V_364 ;
F_144 ( V_2 ) ;
}
static inline int F_147 ( struct V_1 * V_2 , T_1 * V_271 )
{
return F_93 ( V_2 , V_226 ,
V_365 , 0 , 0 , V_271 ) ;
}
static int F_148 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_271 = 0 ;
V_8 = F_147 ( V_2 , & V_271 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_51 ,
V_87 , V_8 ) ;
goto V_30;
}
V_271 = V_271 & 0xF ;
if ( V_271 >= V_366 )
V_8 = F_144 ( V_2 ) ;
V_30:
return V_8 ;
}
static inline int F_149 ( struct V_1 * V_2 , T_1 * V_271 )
{
return F_93 ( V_2 , V_226 ,
V_367 , 0 , 0 , V_271 ) ;
}
static void F_150 ( struct V_368 * V_369 )
{
struct V_1 * V_2 ;
int V_8 ;
T_1 V_271 = 0 ;
V_2 = F_151 ( V_369 , struct V_1 , V_346 ) ;
F_152 ( V_2 -> V_86 ) ;
V_8 = F_149 ( V_2 , & V_271 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_52 ,
V_87 , V_8 ) ;
goto V_30;
}
V_271 &= V_2 -> V_360 ;
if ( V_271 & V_364 ) {
V_8 = F_148 ( V_2 ) ;
if ( V_8 )
F_52 ( V_2 -> V_86 , L_53 ,
V_87 , V_8 ) ;
}
V_30:
F_153 ( V_2 -> V_86 ) ;
return;
}
static void F_154 ( struct V_368 * V_369 )
{
struct V_1 * V_2 ;
unsigned long V_106 ;
T_1 V_370 = 0 ;
T_1 V_371 = 0 ;
int V_8 = 0 ;
int V_28 ;
V_2 = F_151 ( V_369 , struct V_1 , V_372 ) ;
F_152 ( V_2 -> V_86 ) ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
if ( V_2 -> V_175 == V_177 ) {
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
goto V_30;
}
V_2 -> V_175 = V_177 ;
F_155 ( V_2 ) ;
F_139 ( V_2 ) ;
F_156 ( V_2 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_140 (tag, &hba->outstanding_reqs, hba->nutrs)
if ( F_79 ( V_2 , V_28 ) )
V_370 |= 1 << V_28 ;
F_140 (tag, &hba->outstanding_tasks, hba->nutmrs)
if ( F_157 ( V_2 , V_28 ) )
V_371 |= 1 << V_28 ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_139 ( V_2 ) ;
F_156 ( V_2 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
if ( V_370 || V_371 || ( V_2 -> V_373 & V_374 ) ||
( ( V_2 -> V_373 & V_375 ) &&
( V_2 -> V_376 & V_377 ) ) ) {
V_8 = F_158 ( V_2 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_54 ,
V_87 ) ;
V_2 -> V_175 = V_180 ;
}
F_159 ( V_2 -> V_109 , 0 ) ;
V_2 -> V_373 = 0 ;
V_2 -> V_376 = 0 ;
}
F_160 ( V_2 ) ;
V_30:
F_161 ( V_2 -> V_109 ) ;
F_153 ( V_2 -> V_86 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_378 ) ;
if ( V_3 & V_379 )
V_2 -> V_380 |= V_377 ;
V_3 = F_3 ( V_2 , V_381 ) ;
if ( V_3 )
V_2 -> V_380 |= V_382 ;
V_3 = F_3 ( V_2 , V_383 ) ;
if ( V_3 )
V_2 -> V_380 |= V_384 ;
V_3 = F_3 ( V_2 , V_385 ) ;
if ( V_3 )
V_2 -> V_380 |= V_386 ;
F_113 ( V_2 -> V_86 , L_55 ,
V_87 , V_2 -> V_380 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
bool V_387 = false ;
if ( V_2 -> V_388 & V_374 )
V_387 = true ;
if ( V_2 -> V_388 & V_375 ) {
V_2 -> V_380 = 0 ;
F_162 ( V_2 ) ;
if ( V_2 -> V_380 )
V_387 = true ;
}
if ( V_387 ) {
if ( V_2 -> V_175 == V_176 ) {
F_164 ( V_2 -> V_109 ) ;
V_2 -> V_373 |= V_2 -> V_388 ;
V_2 -> V_376 |= V_2 -> V_380 ;
V_2 -> V_175 = V_180 ;
F_137 ( & V_2 -> V_372 ) ;
}
}
}
static void F_156 ( struct V_1 * V_2 )
{
T_1 V_389 ;
V_389 = F_3 ( V_2 , V_390 ) ;
V_2 -> V_391 = V_389 ^ V_2 -> V_330 ;
F_89 ( & V_2 -> V_392 ) ;
}
static void F_165 ( struct V_1 * V_2 , T_1 V_356 )
{
V_2 -> V_388 = V_393 & V_356 ;
if ( V_2 -> V_388 )
F_163 ( V_2 ) ;
if ( V_356 & V_394 )
F_138 ( V_2 , V_356 ) ;
if ( V_356 & V_395 )
F_156 ( V_2 ) ;
if ( V_356 & V_396 )
F_139 ( V_2 ) ;
}
static T_6 F_166 ( int V_397 , void * V_398 )
{
T_1 V_356 ;
T_6 V_399 = V_400 ;
struct V_1 * V_2 = V_398 ;
F_167 ( V_2 -> V_109 -> V_110 ) ;
V_356 = F_3 ( V_2 , V_401 ) ;
if ( V_356 ) {
F_18 ( V_2 , V_356 , V_401 ) ;
F_165 ( V_2 , V_356 ) ;
V_399 = V_402 ;
}
F_168 ( V_2 -> V_109 -> V_110 ) ;
return V_399 ;
}
static int F_157 ( struct V_1 * V_2 , int V_28 )
{
int V_8 = 0 ;
T_1 V_4 = 1 << V_28 ;
unsigned long V_106 ;
if ( ! F_169 ( V_28 , & V_2 -> V_330 ) )
goto V_30;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_18 ( V_2 , ~ ( 1 << V_28 ) , V_403 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_8 = F_1 ( V_2 ,
V_390 ,
V_4 , 0 , 1000 , 1000 ) ;
V_30:
return V_8 ;
}
static int F_170 ( struct V_1 * V_2 , int V_404 , int V_405 ,
T_2 V_406 , T_2 * V_407 )
{
struct V_25 * V_26 ;
struct V_408 * V_409 ;
struct V_174 * V_109 ;
unsigned long V_106 ;
int V_27 ;
int V_8 ;
int V_58 ;
V_109 = V_2 -> V_109 ;
F_87 ( V_2 -> V_410 , F_12 ( V_2 , & V_27 ) ) ;
F_49 ( V_109 -> V_110 , V_106 ) ;
V_26 = V_2 -> V_241 ;
V_26 += V_27 ;
V_26 -> V_22 . V_41 = F_61 ( V_149 ) ;
V_26 -> V_22 . V_23 =
F_61 ( V_150 ) ;
V_409 =
(struct V_408 * ) V_26 -> V_411 ;
V_58 = V_2 -> V_91 + V_27 ;
V_409 -> V_22 . V_41 =
F_69 ( V_412 , 0 ,
V_404 , V_58 ) ;
V_409 -> V_22 . V_42 =
F_69 ( 0 , V_406 , 0 , 0 ) ;
V_409 -> V_413 = F_70 ( V_404 ) ;
V_409 -> V_414 = F_70 ( V_405 ) ;
F_35 ( V_27 , & V_2 -> V_330 ) ;
F_18 ( V_2 , 1 << V_27 , V_390 ) ;
F_50 ( V_109 -> V_110 , V_106 ) ;
V_8 = F_171 ( V_2 -> V_392 ,
F_169 ( V_27 , & V_2 -> V_391 ) ,
F_2 ( V_415 ) ) ;
if ( ! V_8 ) {
F_52 ( V_2 -> V_86 , L_56 ,
V_87 , V_406 ) ;
if ( F_157 ( V_2 , V_27 ) )
F_172 ( V_2 -> V_86 , L_57 ,
V_87 , V_27 ) ;
V_8 = - V_11 ;
} else {
V_8 = F_133 ( V_2 , V_27 , V_407 ) ;
}
F_173 ( V_27 , & V_2 -> V_391 ) ;
F_15 ( V_2 , V_27 ) ;
F_89 ( & V_2 -> V_410 ) ;
return V_8 ;
}
static int F_174 ( struct V_117 * V_118 )
{
struct V_174 * V_109 ;
struct V_1 * V_2 ;
unsigned int V_28 ;
T_1 V_34 ;
int V_8 ;
T_2 V_191 = 0xF ;
struct V_19 * V_20 ;
unsigned long V_106 ;
V_109 = V_118 -> V_187 -> V_109 ;
V_2 = F_75 ( V_109 ) ;
V_28 = V_118 -> V_82 -> V_28 ;
V_20 = & V_2 -> V_185 [ V_28 ] ;
V_8 = F_170 ( V_2 , V_20 -> V_154 , 0 , V_416 , & V_191 ) ;
if ( V_8 || V_191 != V_417 ) {
if ( ! V_8 )
V_8 = V_191 ;
goto V_30;
}
F_140 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_2 -> V_185 [ V_34 ] . V_154 == V_20 -> V_154 ) {
V_8 = F_79 ( V_2 , V_34 ) ;
if ( V_8 )
break;
}
}
F_49 ( V_109 -> V_110 , V_106 ) ;
F_139 ( V_2 ) ;
F_50 ( V_109 -> V_110 , V_106 ) ;
V_30:
if ( ! V_8 ) {
V_8 = V_418 ;
} else {
F_52 ( V_2 -> V_86 , L_58 , V_87 , V_8 ) ;
V_8 = V_419 ;
}
return V_8 ;
}
static int F_175 ( struct V_117 * V_118 )
{
struct V_174 * V_109 ;
struct V_1 * V_2 ;
unsigned long V_106 ;
unsigned int V_28 ;
int V_8 = 0 ;
int V_420 ;
T_2 V_191 = 0xF ;
struct V_19 * V_20 ;
T_1 V_3 ;
V_109 = V_118 -> V_187 -> V_109 ;
V_2 = F_75 ( V_109 ) ;
V_28 = V_118 -> V_82 -> V_28 ;
if ( ! ( F_169 ( V_28 , & V_2 -> V_59 ) ) )
goto V_30;
V_3 = F_3 ( V_2 , V_60 ) ;
if ( ! ( V_3 & ( 1 << V_28 ) ) ) {
F_52 ( V_2 -> V_86 ,
L_59 ,
V_87 , V_28 ) ;
}
V_20 = & V_2 -> V_185 [ V_28 ] ;
for ( V_420 = 100 ; V_420 ; V_420 -- ) {
V_8 = F_170 ( V_2 , V_20 -> V_154 , V_20 -> V_58 ,
V_421 , & V_191 ) ;
if ( ! V_8 && V_191 == V_422 ) {
break;
} else if ( ! V_8 && V_191 == V_417 ) {
V_3 = F_3 ( V_2 , V_60 ) ;
if ( V_3 & ( 1 << V_28 ) ) {
F_4 ( 100 , 200 ) ;
continue;
}
goto V_30;
} else {
if ( ! V_8 )
V_8 = V_191 ;
goto V_30;
}
}
if ( ! V_420 ) {
V_8 = - V_423 ;
goto V_30;
}
V_8 = F_170 ( V_2 , V_20 -> V_154 , V_20 -> V_58 ,
V_424 , & V_191 ) ;
if ( V_8 || V_191 != V_417 ) {
if ( ! V_8 )
V_8 = V_191 ;
goto V_30;
}
V_8 = F_79 ( V_2 , V_28 ) ;
if ( V_8 )
goto V_30;
F_141 ( V_118 ) ;
F_49 ( V_109 -> V_110 , V_106 ) ;
F_134 ( V_28 , & V_2 -> V_59 ) ;
V_2 -> V_185 [ V_28 ] . V_118 = NULL ;
F_50 ( V_109 -> V_110 , V_106 ) ;
F_16 ( V_28 , & V_2 -> V_184 ) ;
F_89 ( & V_2 -> V_69 . V_204 ) ;
V_30:
if ( ! V_8 ) {
V_8 = V_418 ;
} else {
F_52 ( V_2 -> V_86 , L_58 , V_87 , V_8 ) ;
V_8 = V_419 ;
}
return V_8 ;
}
static int F_176 ( struct V_1 * V_2 )
{
int V_8 ;
T_7 V_425 ;
unsigned long V_106 ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_116 ( V_2 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_8 = F_115 ( V_2 ) ;
if ( V_8 )
goto V_30;
V_425 = F_177 ( V_426 , V_2 ) ;
F_178 ( ++ V_425 ) ;
if ( V_2 -> V_175 != V_176 )
V_8 = - V_111 ;
V_30:
if ( V_8 )
F_52 ( V_2 -> V_86 , L_60 , V_87 , V_8 ) ;
return V_8 ;
}
static int F_158 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
unsigned long V_106 ;
V_8 = F_176 ( V_2 ) ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_139 ( V_2 ) ;
F_156 ( V_2 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
return V_8 ;
}
static int F_179 ( struct V_117 * V_118 )
{
int V_8 ;
unsigned long V_106 ;
struct V_1 * V_2 ;
V_2 = F_75 ( V_118 -> V_187 -> V_109 ) ;
do {
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
if ( ! ( F_180 ( & V_2 -> V_372 ) ||
V_2 -> V_175 == V_177 ) )
break;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
F_113 ( V_2 -> V_86 , L_61 , V_87 ) ;
F_181 ( & V_2 -> V_372 ) ;
} while ( 1 );
V_2 -> V_175 = V_177 ;
F_155 ( V_2 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
V_8 = F_158 ( V_2 ) ;
F_49 ( V_2 -> V_109 -> V_110 , V_106 ) ;
if ( ! V_8 ) {
V_8 = V_418 ;
V_2 -> V_175 = V_176 ;
} else {
V_8 = V_419 ;
V_2 -> V_175 = V_180 ;
}
F_160 ( V_2 ) ;
F_50 ( V_2 -> V_109 -> V_110 , V_106 ) ;
return V_8 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_308 * V_309 )
{
int V_29 ;
int V_427 = V_428 ;
T_2 V_228 [ V_428 ] ;
V_29 = F_94 ( V_2 , V_76 ,
V_429 , V_309 -> V_154 , 0 , V_228 , & V_427 ) ;
if ( V_29 || ( V_427 < V_430 ) ) {
F_52 ( V_2 -> V_86 ,
L_62
, V_87 , V_427 , V_29 ) ;
if ( ! V_29 )
V_29 = - V_88 ;
goto V_30;
}
V_29 = V_228 [ V_430 ] & 0xFF ;
V_30:
return V_29 ;
}
static void V_426 ( void * V_431 , T_7 V_425 )
{
struct V_1 * V_2 = (struct V_1 * ) V_431 ;
int V_29 ;
V_29 = F_118 ( V_2 ) ;
if ( V_29 )
goto V_30;
F_108 ( V_2 ) ;
V_29 = F_119 ( V_2 ) ;
if ( V_29 )
goto V_30;
V_29 = F_112 ( V_2 ) ;
if ( V_29 )
goto V_30;
F_146 ( V_2 ) ;
V_2 -> V_175 = V_176 ;
if ( ! F_182 ( V_2 ) ) {
F_183 ( V_2 -> V_109 ) ;
F_153 ( V_2 -> V_86 ) ;
}
V_30:
return;
}
int F_184 ( struct V_1 * V_2 , T_8 V_432 )
{
return - V_433 ;
}
int F_185 ( struct V_1 * V_2 )
{
return - V_433 ;
}
int F_186 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return F_144 ( V_2 ) ;
}
int F_187 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return F_145 ( V_2 ) ;
}
int F_188 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_189 ( struct V_1 * V_2 )
{
F_190 ( V_2 -> V_109 ) ;
F_66 ( V_2 , V_2 -> V_434 ) ;
F_116 ( V_2 ) ;
F_191 ( V_2 -> V_109 ) ;
}
static int F_192 ( struct V_1 * V_2 )
{
if ( V_2 -> V_89 & V_435 ) {
if ( ! F_193 ( V_2 -> V_86 , F_194 ( 64 ) ) )
return 0 ;
}
return F_193 ( V_2 -> V_86 , F_194 ( 32 ) ) ;
}
int F_195 ( struct V_187 * V_86 , struct V_1 * * V_436 ,
void T_9 * V_437 , unsigned int V_397 )
{
struct V_174 * V_109 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_86 ) {
F_52 ( V_86 ,
L_63 ) ;
V_8 = - V_438 ;
goto V_439;
}
if ( ! V_437 ) {
F_52 ( V_86 ,
L_64 ) ;
V_8 = - V_438 ;
goto V_439;
}
V_109 = F_196 ( & V_440 ,
sizeof( struct V_1 ) ) ;
if ( ! V_109 ) {
F_52 ( V_86 , L_65 ) ;
V_8 = - V_243 ;
goto V_439;
}
V_2 = F_75 ( V_109 ) ;
V_2 -> V_109 = V_109 ;
V_2 -> V_86 = V_86 ;
V_2 -> V_437 = V_437 ;
V_2 -> V_397 = V_397 ;
F_42 ( V_2 ) ;
V_2 -> V_12 = F_7 ( V_2 ) ;
V_2 -> V_434 = F_6 ( V_2 ) ;
V_8 = F_192 ( V_2 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_66 ) ;
goto V_441;
}
V_8 = F_96 ( V_2 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_67 ) ;
goto V_441;
}
F_99 ( V_2 ) ;
V_109 -> V_442 = V_2 -> V_91 ;
V_109 -> V_443 = V_2 -> V_91 ;
V_109 -> V_444 = V_445 ;
V_109 -> V_446 = V_447 ;
V_109 -> V_448 = V_449 ;
V_109 -> V_450 = V_109 -> V_451 ;
V_109 -> V_452 = V_453 ;
F_197 ( & V_2 -> V_392 ) ;
F_197 ( & V_2 -> V_410 ) ;
F_198 ( & V_2 -> V_372 , F_154 ) ;
F_198 ( & V_2 -> V_346 , F_150 ) ;
F_199 ( & V_2 -> V_112 ) ;
F_199 ( & V_2 -> V_69 . V_213 ) ;
F_197 ( & V_2 -> V_69 . V_204 ) ;
V_8 = F_200 ( V_86 , V_397 , F_166 , V_454 , V_455 , V_2 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_68 ) ;
goto V_441;
}
V_8 = F_201 ( V_109 , V_109 -> V_442 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_69 ) ;
goto V_441;
}
V_8 = F_202 ( V_109 , V_2 -> V_86 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_70 ) ;
goto V_441;
}
V_8 = F_115 ( V_2 ) ;
if ( V_8 ) {
F_52 ( V_2 -> V_86 , L_71 ) ;
goto V_456;
}
* V_436 = V_2 ;
F_152 ( V_86 ) ;
F_177 ( V_426 , V_2 ) ;
return 0 ;
V_456:
F_190 ( V_2 -> V_109 ) ;
V_441:
F_191 ( V_109 ) ;
V_439:
return V_8 ;
}
