static int F_1 ( struct V_1 * V_2 , int type , int V_3 ,
T_1 V_4 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
break;
case V_11 :
case V_12 :
if ( ( type == V_13 && F_2 ( F_3 () , F_4 ( F_5 () , V_4 ) ) ) ||
( type == V_14 && F_6 ( F_7 ( F_5 () , V_4 ) ) ) )
break;
default:
if ( ! F_8 ( V_15 ) )
return - V_16 ;
}
return F_9 ( V_3 , type , V_4 , V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_17 )
{
int type = * ( int * ) V_17 ;
if ( V_2 -> V_18 && V_2 -> V_18 -> V_19 &&
( V_2 -> V_20 & ( 1 << type ) ) )
V_2 -> V_18 -> V_19 ( V_2 , type ) ;
}
static int F_11 ( int type )
{
int V_21 ;
if ( type >= V_22 )
return - V_23 ;
V_21 = F_9 ( V_6 , type , 0 , NULL ) ;
if ( ! V_21 )
F_12 ( F_10 , & type ) ;
return V_21 ;
}
unsigned int F_13 ( int type )
{
switch ( type ) {
case V_13 :
return V_24 ;
case V_14 :
return V_25 ;
case V_26 :
return V_27 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
struct V_28 * V_28 )
{
if ( ! V_2 -> V_18 -> V_29 && ! V_2 -> V_18 -> V_30 )
return - V_31 ;
if ( V_2 -> V_18 -> V_30 )
return V_2 -> V_18 -> V_30 ( V_2 , F_13 ( type ) ) ;
if ( F_15 ( V_28 ) )
return F_16 ( V_28 ) ;
return V_2 -> V_18 -> V_29 ( V_2 , type , V_4 , V_28 ) ;
}
static int F_17 ( struct V_1 * V_2 , int type )
{
if ( ! V_2 -> V_18 -> V_32 && ! V_2 -> V_18 -> V_33 )
return - V_31 ;
if ( V_2 -> V_18 -> V_33 )
return V_2 -> V_18 -> V_33 ( V_2 , F_13 ( type ) ) ;
return V_2 -> V_18 -> V_32 ( V_2 , type ) ;
}
static int F_18 ( struct V_1 * V_2 , int type , void T_2 * V_34 )
{
T_3 V_35 ;
F_19 ( & F_20 ( V_2 ) -> V_36 ) ;
if ( ! F_21 ( V_2 , type ) ) {
F_22 ( & F_20 ( V_2 ) -> V_36 ) ;
return - V_37 ;
}
V_35 = F_20 ( V_2 ) -> V_38 [ type ] . V_39 -> V_40 ;
F_22 ( & F_20 ( V_2 ) -> V_36 ) ;
if ( F_23 ( V_34 , & V_35 , sizeof( V_35 ) ) )
return - V_41 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int type , void T_2 * V_34 )
{
struct V_42 V_43 ;
struct V_44 * V_45 ;
struct V_46 V_47 ;
int V_21 ;
F_25 ( V_22 > V_48 ) ;
if ( ! V_2 -> V_18 -> V_49 )
return - V_31 ;
V_21 = V_2 -> V_18 -> V_49 ( V_2 , & V_43 ) ;
if ( V_21 )
return V_21 ;
V_45 = V_43 . V_50 + type ;
if ( ! ( V_45 -> V_51 & V_52 ) )
return - V_37 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_53 = V_45 -> V_54 ;
V_47 . V_55 = V_45 -> V_56 ;
if ( V_45 -> V_51 & V_57 )
V_47 . V_58 |= V_59 ;
if ( V_45 -> V_51 & V_60 )
V_47 . V_58 |= V_61 ;
V_47 . V_62 = V_63 ;
if ( ! V_21 && F_23 ( V_34 , & V_47 , sizeof( V_47 ) ) )
return - V_41 ;
return V_21 ;
}
static int F_26 ( struct V_1 * V_2 , int type , void T_2 * V_34 )
{
struct V_46 V_38 ;
struct V_64 V_65 ;
if ( F_27 ( & V_38 , V_34 , sizeof( V_38 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_66 )
return - V_31 ;
if ( V_38 . V_62 & ~ ( V_67 | V_68 | V_69 ) )
return - V_23 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
if ( V_38 . V_62 & V_67 ) {
if ( V_38 . V_58 & ~ V_70 )
return - V_23 ;
if ( V_38 . V_58 & V_61 )
V_65 . V_71 |= V_60 ;
V_65 . V_72 |= V_73 ;
}
if ( V_38 . V_62 & V_68 ) {
V_65 . V_74 = V_38 . V_53 ;
V_65 . V_72 |= V_75 ;
}
if ( V_38 . V_62 & V_69 ) {
V_65 . V_76 = V_38 . V_55 ;
V_65 . V_72 |= V_77 ;
}
return V_2 -> V_18 -> V_66 ( V_2 , type , & V_65 ) ;
}
static inline T_4 F_28 ( T_4 V_78 )
{
return V_78 << V_79 ;
}
static inline T_4 F_29 ( T_4 V_80 )
{
return ( V_80 + V_81 - 1 ) >> V_79 ;
}
static void F_30 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_86 = F_29 ( V_85 -> V_87 ) ;
V_83 -> V_88 = F_29 ( V_85 -> V_89 ) ;
V_83 -> V_90 = V_85 -> V_91 ;
V_83 -> V_92 = V_85 -> V_93 ;
V_83 -> V_94 = V_85 -> V_95 ;
V_83 -> V_96 = V_85 -> V_97 ;
V_83 -> V_98 = V_85 -> V_99 ;
V_83 -> V_100 = V_85 -> V_101 ;
V_83 -> V_102 = V_103 ;
}
static int F_31 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_104 V_105 ;
struct V_84 V_106 ;
struct V_82 V_107 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_108 )
return - V_31 ;
V_105 = F_32 ( F_5 () , type , V_4 ) ;
if ( ! F_33 ( V_105 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_108 ( V_2 , V_105 , & V_106 ) ;
if ( V_21 )
return V_21 ;
F_30 ( & V_107 , & V_106 ) ;
if ( F_23 ( V_34 , & V_107 , sizeof( V_107 ) ) )
return - V_41 ;
return 0 ;
}
static void F_34 ( struct V_84 * V_83 , struct V_82 * V_85 )
{
V_83 -> V_87 = F_28 ( V_85 -> V_86 ) ;
V_83 -> V_89 = F_28 ( V_85 -> V_88 ) ;
V_83 -> V_91 = V_85 -> V_90 ;
V_83 -> V_93 = V_85 -> V_92 ;
V_83 -> V_95 = V_85 -> V_94 ;
V_83 -> V_97 = V_85 -> V_96 ;
V_83 -> V_99 = V_85 -> V_98 ;
V_83 -> V_101 = V_85 -> V_100 ;
V_83 -> V_109 = 0 ;
if ( V_85 -> V_102 & V_110 )
V_83 -> V_109 |= V_111 | V_112 ;
if ( V_85 -> V_102 & V_113 )
V_83 -> V_109 |= V_114 ;
if ( V_85 -> V_102 & V_115 )
V_83 -> V_109 |= V_116 | V_117 ;
if ( V_85 -> V_102 & V_118 )
V_83 -> V_109 |= V_119 ;
if ( V_85 -> V_102 & V_120 )
V_83 -> V_109 |= V_75 ;
if ( V_85 -> V_102 & V_121 )
V_83 -> V_109 |= V_77 ;
}
static int F_35 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_84 V_106 ;
struct V_82 V_107 ;
struct V_104 V_105 ;
if ( F_27 ( & V_107 , V_34 , sizeof( V_107 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_122 )
return - V_31 ;
V_105 = F_32 ( F_5 () , type , V_4 ) ;
if ( ! F_33 ( V_105 ) )
return - V_23 ;
F_34 ( & V_106 , & V_107 ) ;
return V_2 -> V_18 -> V_122 ( V_2 , V_105 , & V_106 ) ;
}
static int V_30 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_51 ;
if ( F_27 ( & V_51 , V_34 , sizeof( V_51 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_30 )
return - V_31 ;
return V_2 -> V_18 -> V_30 ( V_2 , V_51 ) ;
}
static int V_33 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_51 ;
if ( F_27 ( & V_51 , V_34 , sizeof( V_51 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_33 )
return - V_31 ;
return V_2 -> V_18 -> V_33 ( V_2 , V_51 ) ;
}
static int F_36 ( struct V_42 * V_43 )
{
int V_51 = 0 ;
if ( V_43 -> V_50 [ V_13 ] . V_51 & V_52 )
V_51 |= V_123 ;
if ( V_43 -> V_50 [ V_13 ] . V_51 & V_124 )
V_51 |= V_24 ;
if ( V_43 -> V_50 [ V_14 ] . V_51 & V_52 )
V_51 |= V_125 ;
if ( V_43 -> V_50 [ V_14 ] . V_51 & V_124 )
V_51 |= V_25 ;
if ( V_43 -> V_50 [ V_26 ] . V_51 & V_52 )
V_51 |= V_126 ;
if ( V_43 -> V_50 [ V_26 ] . V_51 & V_124 )
V_51 |= V_27 ;
return V_51 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
int type ;
struct V_42 V_43 ;
int V_21 ;
V_21 = V_2 -> V_18 -> V_49 ( V_2 , & V_43 ) ;
if ( V_21 < 0 )
return V_21 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
V_128 -> V_129 = V_130 ;
V_128 -> V_131 = F_36 ( & V_43 ) ;
if ( ! V_128 -> V_131 )
return - V_31 ;
V_128 -> V_132 = V_43 . V_133 ;
for ( type = 0 ; type < V_48 ; type ++ )
if ( V_43 . V_50 [ type ] . V_51 & V_52 )
break;
F_38 ( type == V_48 ) ;
V_128 -> V_134 = V_43 . V_50 [ type ] . V_54 ;
V_128 -> V_135 = V_43 . V_50 [ type ] . V_56 ;
V_128 -> V_136 = V_43 . V_50 [ type ] . V_137 ;
V_128 -> V_138 = V_43 . V_50 [ type ] . V_139 ;
V_128 -> V_140 = V_43 . V_50 [ type ] . V_141 ;
if ( V_43 . V_50 [ V_13 ] . V_51 & V_52 ) {
V_128 -> V_142 . V_143 = V_43 . V_50 [ V_13 ] . V_144 ;
V_128 -> V_142 . V_145 = V_43 . V_50 [ V_13 ] . V_78 ;
V_128 -> V_142 . V_146 = V_43 . V_50 [ V_13 ] . V_147 ;
}
if ( V_43 . V_50 [ V_14 ] . V_51 & V_52 ) {
V_128 -> V_148 . V_143 = V_43 . V_50 [ V_14 ] . V_144 ;
V_128 -> V_148 . V_145 = V_43 . V_50 [ V_14 ] . V_78 ;
V_128 -> V_148 . V_146 = V_43 . V_50 [ V_14 ] . V_147 ;
}
if ( V_43 . V_50 [ V_26 ] . V_51 & V_52 ) {
if ( ! ( V_43 . V_50 [ V_14 ] . V_51 & V_52 ) ) {
V_128 -> V_148 . V_143 = V_43 . V_50 [ V_26 ] . V_144 ;
V_128 -> V_148 . V_145 =
V_43 . V_50 [ V_26 ] . V_78 ;
V_128 -> V_148 . V_146 =
V_43 . V_50 [ V_26 ] . V_147 ;
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , void T_2 * V_34 )
{
struct V_127 V_128 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_49 )
return - V_31 ;
V_21 = F_37 ( V_2 , & V_128 ) ;
if ( ! V_21 && F_23 ( V_34 , & V_128 , sizeof( V_128 ) ) )
return - V_41 ;
return V_21 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_149 * V_128 )
{
int type ;
struct V_42 V_43 ;
int V_21 ;
V_21 = V_2 -> V_18 -> V_49 ( V_2 , & V_43 ) ;
if ( V_21 < 0 )
return V_21 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
V_128 -> V_129 = V_130 ;
V_128 -> V_131 = F_36 ( & V_43 ) ;
if ( ! V_128 -> V_131 )
return - V_31 ;
V_128 -> V_132 = V_43 . V_133 ;
for ( type = 0 ; type < V_48 ; type ++ )
if ( V_43 . V_50 [ type ] . V_51 & V_52 )
break;
F_38 ( type == V_48 ) ;
V_128 -> V_134 = V_43 . V_50 [ type ] . V_54 ;
V_128 -> V_135 = V_43 . V_50 [ type ] . V_56 ;
V_128 -> V_136 = V_43 . V_50 [ type ] . V_137 ;
V_128 -> V_138 = V_43 . V_50 [ type ] . V_139 ;
V_128 -> V_140 = V_43 . V_50 [ type ] . V_141 ;
if ( V_43 . V_50 [ V_13 ] . V_51 & V_52 ) {
V_128 -> V_142 . V_143 = V_43 . V_50 [ V_13 ] . V_144 ;
V_128 -> V_142 . V_145 = V_43 . V_50 [ V_13 ] . V_78 ;
V_128 -> V_142 . V_146 = V_43 . V_50 [ V_13 ] . V_147 ;
}
if ( V_43 . V_50 [ V_14 ] . V_51 & V_52 ) {
V_128 -> V_148 . V_143 = V_43 . V_50 [ V_14 ] . V_144 ;
V_128 -> V_148 . V_145 = V_43 . V_50 [ V_14 ] . V_78 ;
V_128 -> V_148 . V_146 = V_43 . V_50 [ V_14 ] . V_147 ;
}
if ( V_43 . V_50 [ V_26 ] . V_51 & V_52 ) {
V_128 -> V_150 . V_143 = V_43 . V_50 [ V_26 ] . V_144 ;
V_128 -> V_150 . V_145 = V_43 . V_50 [ V_26 ] . V_78 ;
V_128 -> V_150 . V_146 = V_43 . V_50 [ V_26 ] . V_147 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , void T_2 * V_34 )
{
struct V_149 V_128 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_49 )
return - V_31 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( F_27 ( & V_128 , V_34 , 1 ) )
return - V_41 ;
switch ( V_128 . V_129 ) {
case V_151 :
break;
default:
return - V_23 ;
}
V_21 = F_40 ( V_2 , & V_128 ) ;
if ( ! V_21 && F_23 ( V_34 , & V_128 , sizeof( V_128 ) ) )
return - V_41 ;
return V_21 ;
}
static inline T_5 F_42 ( T_5 V_78 )
{
return V_78 << V_152 ;
}
static inline T_5 F_43 ( T_5 V_153 )
{
return ( V_153 + ( 1 << V_152 ) - 1 ) >> V_152 ;
}
static void F_44 ( struct V_84 * V_83 , struct V_154 * V_85 )
{
V_83 -> V_87 = F_42 ( V_85 -> V_155 ) ;
V_83 -> V_89 = F_42 ( V_85 -> V_156 ) ;
V_83 -> V_93 = V_85 -> V_93 ;
V_83 -> V_95 = V_85 -> V_95 ;
V_83 -> V_91 = F_42 ( V_85 -> V_157 ) ;
V_83 -> V_97 = V_85 -> V_158 ;
V_83 -> V_101 = V_85 -> V_159 ;
V_83 -> V_99 = V_85 -> V_160 ;
V_83 -> V_161 = V_85 -> V_162 ;
V_83 -> V_163 = V_85 -> V_164 ;
V_83 -> V_165 = F_42 ( V_85 -> V_166 ) ;
V_83 -> V_167 = F_42 ( V_85 -> V_168 ) ;
V_83 -> V_169 = F_42 ( V_85 -> V_170 ) ;
V_83 -> V_171 = V_85 -> V_172 ;
V_83 -> V_173 = V_85 -> V_174 ;
V_83 -> V_109 = 0 ;
if ( V_85 -> V_109 & V_175 )
V_83 -> V_109 |= V_116 ;
if ( V_85 -> V_109 & V_176 )
V_83 -> V_109 |= V_117 ;
if ( V_85 -> V_109 & V_177 )
V_83 -> V_109 |= V_111 ;
if ( V_85 -> V_109 & V_178 )
V_83 -> V_109 |= V_112 ;
if ( V_85 -> V_109 & V_179 )
V_83 -> V_109 |= V_180 ;
if ( V_85 -> V_109 & V_181 )
V_83 -> V_109 |= V_182 ;
if ( V_85 -> V_109 & V_183 )
V_83 -> V_109 |= V_75 ;
if ( V_85 -> V_109 & V_184 )
V_83 -> V_109 |= V_77 ;
if ( V_85 -> V_109 & V_185 )
V_83 -> V_109 |= V_186 ;
if ( V_85 -> V_109 & V_187 )
V_83 -> V_109 |= V_188 ;
if ( V_85 -> V_109 & V_189 )
V_83 -> V_109 |= V_190 ;
if ( V_85 -> V_109 & V_191 )
V_83 -> V_109 |= V_192 ;
if ( V_85 -> V_109 & V_193 )
V_83 -> V_109 |= V_114 ;
if ( V_85 -> V_109 & V_194 )
V_83 -> V_109 |= V_119 ;
if ( V_85 -> V_109 & V_195 )
V_83 -> V_109 |= V_196 ;
}
static void F_45 ( struct V_64 * V_83 ,
struct V_154 * V_85 )
{
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_74 = V_85 -> V_160 ;
V_83 -> V_76 = V_85 -> V_159 ;
V_83 -> V_197 = V_85 -> V_172 ;
V_83 -> V_198 = V_85 -> V_162 ;
V_83 -> V_199 = V_85 -> V_164 ;
V_83 -> V_200 = V_85 -> V_174 ;
if ( V_85 -> V_109 & V_187 )
V_83 -> V_72 |= V_188 ;
if ( V_85 -> V_109 & V_189 )
V_83 -> V_72 |= V_190 ;
if ( V_85 -> V_109 & V_191 )
V_83 -> V_72 |= V_192 ;
if ( V_85 -> V_109 & V_183 )
V_83 -> V_72 |= V_75 ;
if ( V_85 -> V_109 & V_184 )
V_83 -> V_72 |= V_77 ;
if ( V_85 -> V_109 & V_185 )
V_83 -> V_72 |= V_186 ;
}
static int F_46 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_154 V_106 ;
struct V_84 V_201 ;
struct V_104 V_105 ;
if ( F_27 ( & V_106 , V_34 , sizeof( V_106 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_122 )
return - V_31 ;
V_105 = F_32 ( F_5 () , type , V_4 ) ;
if ( ! F_33 ( V_105 ) )
return - V_23 ;
if ( F_47 ( & V_202 , V_105 ) == 0 &&
V_106 . V_109 & ( V_203 | V_204 ) ) {
struct V_64 V_65 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_66 )
return - V_23 ;
F_45 ( & V_65 , & V_106 ) ;
V_21 = V_2 -> V_18 -> V_66 ( V_2 , type , & V_65 ) ;
if ( V_21 )
return V_21 ;
V_106 . V_109 &= ~ ( V_203 | V_204 ) ;
}
F_44 ( & V_201 , & V_106 ) ;
return V_2 -> V_18 -> V_122 ( V_2 , V_105 , & V_201 ) ;
}
static void F_48 ( struct V_154 * V_83 , struct V_84 * V_85 ,
int type , T_1 V_4 )
{
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_205 = V_206 ;
V_83 -> V_207 = V_4 ;
if ( type == V_13 )
V_83 -> V_208 = V_209 ;
else if ( type == V_26 )
V_83 -> V_208 = V_210 ;
else
V_83 -> V_208 = V_211 ;
V_83 -> V_155 = F_43 ( V_85 -> V_87 ) ;
V_83 -> V_156 = F_43 ( V_85 -> V_89 ) ;
V_83 -> V_93 = V_85 -> V_93 ;
V_83 -> V_95 = V_85 -> V_95 ;
V_83 -> V_157 = F_43 ( V_85 -> V_91 ) ;
V_83 -> V_158 = V_85 -> V_97 ;
V_83 -> V_159 = V_85 -> V_101 ;
V_83 -> V_160 = V_85 -> V_99 ;
V_83 -> V_162 = V_85 -> V_161 ;
V_83 -> V_164 = V_85 -> V_163 ;
V_83 -> V_166 = F_43 ( V_85 -> V_165 ) ;
V_83 -> V_168 = F_43 ( V_85 -> V_167 ) ;
V_83 -> V_170 = F_43 ( V_85 -> V_169 ) ;
V_83 -> V_172 = V_85 -> V_171 ;
V_83 -> V_174 = V_85 -> V_173 ;
}
static int F_49 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_154 V_106 ;
struct V_84 V_201 ;
struct V_104 V_105 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_108 )
return - V_31 ;
V_105 = F_32 ( F_5 () , type , V_4 ) ;
if ( ! F_33 ( V_105 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_108 ( V_2 , V_105 , & V_201 ) ;
if ( V_21 )
return V_21 ;
F_48 ( & V_106 , & V_201 , type , V_4 ) ;
if ( F_23 ( V_34 , & V_106 , sizeof( V_106 ) ) )
return - V_41 ;
return V_21 ;
}
static int F_50 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_51 ;
if ( F_27 ( & V_51 , V_34 , sizeof( V_51 ) ) )
return - V_41 ;
if ( ! V_2 -> V_18 -> V_212 )
return - V_31 ;
return V_2 -> V_18 -> V_212 ( V_2 , V_51 ) ;
}
static int F_51 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
void T_2 * V_34 , struct V_28 * V_28 )
{
int V_21 ;
if ( type >= ( F_52 ( V_3 ) ? V_48 : V_22 ) )
return - V_23 ;
if ( ! V_2 -> V_18 )
return - V_31 ;
if ( ! ( V_2 -> V_20 & ( 1 << type ) ) )
return - V_23 ;
V_21 = F_1 ( V_2 , type , V_3 , V_4 ) ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_3 ) {
case V_213 :
return F_14 ( V_2 , type , V_3 , V_4 , V_28 ) ;
case V_214 :
return F_17 ( V_2 , type ) ;
case V_5 :
return F_18 ( V_2 , type , V_34 ) ;
case V_7 :
return F_24 ( V_2 , type , V_34 ) ;
case V_215 :
return F_26 ( V_2 , type , V_34 ) ;
case V_11 :
return F_31 ( V_2 , type , V_4 , V_34 ) ;
case V_216 :
return F_35 ( V_2 , type , V_4 , V_34 ) ;
case V_6 :
if ( ! V_2 -> V_18 -> V_19 )
return - V_31 ;
return V_2 -> V_18 -> V_19 ( V_2 , type ) ;
case V_217 :
return V_30 ( V_2 , V_34 ) ;
case V_218 :
return V_33 ( V_2 , V_34 ) ;
case V_219 :
return F_50 ( V_2 , V_34 ) ;
case V_8 :
return F_39 ( V_2 , V_34 ) ;
case V_9 :
return F_41 ( V_2 , V_34 ) ;
case V_220 :
return F_46 ( V_2 , type , V_4 , V_34 ) ;
case V_12 :
return F_49 ( V_2 , type , V_4 , V_34 ) ;
case V_10 :
if ( V_2 -> V_221 & V_222 )
return - V_223 ;
return 0 ;
default:
return - V_23 ;
}
}
static int F_53 ( int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_7 :
case V_6 :
case V_8 :
case V_9 :
case V_12 :
case V_10 :
return 0 ;
}
return 1 ;
}
static struct V_1 * F_54 ( const char T_2 * V_224 , int V_3 )
{
#ifdef F_55
struct V_225 * V_226 ;
struct V_1 * V_2 ;
struct V_227 * V_228 = F_56 ( V_224 ) ;
if ( F_15 ( V_228 ) )
return F_57 ( V_228 ) ;
V_226 = F_58 ( V_228 -> V_229 ) ;
F_59 ( V_228 ) ;
if ( F_15 ( V_226 ) )
return F_57 ( V_226 ) ;
if ( F_53 ( V_3 ) )
V_2 = F_60 ( V_226 ) ;
else
V_2 = F_61 ( V_226 ) ;
F_62 ( V_226 ) ;
if ( ! V_2 )
return F_63 ( - V_230 ) ;
return V_2 ;
#else
return F_63 ( - V_230 ) ;
#endif
}
