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
static int F_14 ( struct V_1 * V_2 , int type , T_1 V_4 ,
const struct V_28 * V_28 )
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
if ( ! F_19 ( V_2 , type ) )
return - V_36 ;
V_35 = F_20 ( V_2 ) -> V_37 [ type ] . V_38 -> V_39 ;
if ( F_21 ( V_34 , & V_35 , sizeof( V_35 ) ) )
return - V_40 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int type , void T_2 * V_34 )
{
struct V_41 V_42 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
int V_21 ;
F_23 ( V_22 > V_47 ) ;
if ( ! V_2 -> V_18 -> V_48 )
return - V_31 ;
V_21 = V_2 -> V_18 -> V_48 ( V_2 , & V_42 ) ;
if ( V_21 )
return V_21 ;
V_44 = V_42 . V_49 + type ;
if ( ! ( V_44 -> V_50 & V_51 ) )
return - V_36 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_52 = V_44 -> V_53 ;
V_46 . V_54 = V_44 -> V_55 ;
if ( V_44 -> V_50 & V_56 )
V_46 . V_57 |= V_58 ;
if ( V_44 -> V_50 & V_59 )
V_46 . V_57 |= V_60 ;
V_46 . V_61 = V_62 ;
if ( F_21 ( V_34 , & V_46 , sizeof( V_46 ) ) )
return - V_40 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int type , void T_2 * V_34 )
{
struct V_45 V_37 ;
struct V_63 V_64 ;
if ( F_25 ( & V_37 , V_34 , sizeof( V_37 ) ) )
return - V_40 ;
if ( ! V_2 -> V_18 -> V_65 )
return - V_31 ;
if ( V_37 . V_61 & ~ ( V_66 | V_67 | V_68 ) )
return - V_23 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_37 . V_61 & V_66 ) {
if ( V_37 . V_57 & ~ V_69 )
return - V_23 ;
if ( V_37 . V_57 & V_60 )
V_64 . V_70 |= V_59 ;
V_64 . V_71 |= V_72 ;
}
if ( V_37 . V_61 & V_67 ) {
V_64 . V_73 = V_37 . V_52 ;
V_64 . V_71 |= V_74 ;
}
if ( V_37 . V_61 & V_68 ) {
V_64 . V_75 = V_37 . V_54 ;
V_64 . V_71 |= V_76 ;
}
return V_2 -> V_18 -> V_65 ( V_2 , type , & V_64 ) ;
}
static inline T_4 F_26 ( T_4 V_77 )
{
return V_77 << V_78 ;
}
static inline T_4 F_27 ( T_4 V_79 )
{
return ( V_79 + V_80 - 1 ) >> V_78 ;
}
static void F_28 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> V_85 = F_27 ( V_84 -> V_86 ) ;
V_82 -> V_87 = F_27 ( V_84 -> V_88 ) ;
V_82 -> V_89 = V_84 -> V_90 ;
V_82 -> V_91 = V_84 -> V_92 ;
V_82 -> V_93 = V_84 -> V_94 ;
V_82 -> V_95 = V_84 -> V_96 ;
V_82 -> V_97 = V_84 -> V_98 ;
V_82 -> V_99 = V_84 -> V_100 ;
V_82 -> V_101 = V_102 ;
}
static int F_29 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_103 V_104 ;
struct V_83 V_105 ;
struct V_81 V_106 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_107 )
return - V_31 ;
V_104 = F_30 ( F_5 () , type , V_4 ) ;
if ( ! F_31 ( V_2 -> V_108 , V_104 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_107 ( V_2 , V_104 , & V_105 ) ;
if ( V_21 )
return V_21 ;
F_28 ( & V_106 , & V_105 ) ;
if ( F_21 ( V_34 , & V_106 , sizeof( V_106 ) ) )
return - V_40 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_103 V_104 ;
struct V_83 V_105 ;
struct V_109 V_106 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_110 )
return - V_31 ;
V_104 = F_30 ( F_5 () , type , V_4 ) ;
if ( ! F_31 ( V_2 -> V_108 , V_104 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_110 ( V_2 , & V_104 , & V_105 ) ;
if ( V_21 )
return V_21 ;
F_28 ( (struct V_81 * ) & V_106 , & V_105 ) ;
V_106 . V_111 = F_33 ( F_5 () , V_104 ) ;
if ( F_21 ( V_34 , & V_106 , sizeof( V_106 ) ) )
return - V_40 ;
return 0 ;
}
static void F_34 ( struct V_83 * V_82 , struct V_81 * V_84 )
{
V_82 -> V_86 = F_26 ( V_84 -> V_85 ) ;
V_82 -> V_88 = F_26 ( V_84 -> V_87 ) ;
V_82 -> V_90 = V_84 -> V_89 ;
V_82 -> V_92 = V_84 -> V_91 ;
V_82 -> V_94 = V_84 -> V_93 ;
V_82 -> V_96 = V_84 -> V_95 ;
V_82 -> V_98 = V_84 -> V_97 ;
V_82 -> V_100 = V_84 -> V_99 ;
V_82 -> V_112 = 0 ;
if ( V_84 -> V_101 & V_113 )
V_82 -> V_112 |= V_114 | V_115 ;
if ( V_84 -> V_101 & V_116 )
V_82 -> V_112 |= V_117 ;
if ( V_84 -> V_101 & V_118 )
V_82 -> V_112 |= V_119 | V_120 ;
if ( V_84 -> V_101 & V_121 )
V_82 -> V_112 |= V_122 ;
if ( V_84 -> V_101 & V_123 )
V_82 -> V_112 |= V_74 ;
if ( V_84 -> V_101 & V_124 )
V_82 -> V_112 |= V_76 ;
}
static int F_35 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_83 V_105 ;
struct V_81 V_106 ;
struct V_103 V_104 ;
if ( F_25 ( & V_106 , V_34 , sizeof( V_106 ) ) )
return - V_40 ;
if ( ! V_2 -> V_18 -> V_125 )
return - V_31 ;
V_104 = F_30 ( F_5 () , type , V_4 ) ;
if ( ! F_31 ( V_2 -> V_108 , V_104 ) )
return - V_23 ;
F_34 ( & V_105 , & V_106 ) ;
return V_2 -> V_18 -> V_125 ( V_2 , V_104 , & V_105 ) ;
}
static int V_30 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_50 ;
if ( F_25 ( & V_50 , V_34 , sizeof( V_50 ) ) )
return - V_40 ;
if ( ! V_2 -> V_18 -> V_30 )
return - V_31 ;
return V_2 -> V_18 -> V_30 ( V_2 , V_50 ) ;
}
static int V_33 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_50 ;
if ( F_25 ( & V_50 , V_34 , sizeof( V_50 ) ) )
return - V_40 ;
if ( ! V_2 -> V_18 -> V_33 )
return - V_31 ;
return V_2 -> V_18 -> V_33 ( V_2 , V_50 ) ;
}
static int F_36 ( struct V_41 * V_42 )
{
int V_50 = 0 ;
if ( V_42 -> V_49 [ V_13 ] . V_50 & V_51 )
V_50 |= V_126 ;
if ( V_42 -> V_49 [ V_13 ] . V_50 & V_127 )
V_50 |= V_24 ;
if ( V_42 -> V_49 [ V_14 ] . V_50 & V_51 )
V_50 |= V_128 ;
if ( V_42 -> V_49 [ V_14 ] . V_50 & V_127 )
V_50 |= V_25 ;
if ( V_42 -> V_49 [ V_26 ] . V_50 & V_51 )
V_50 |= V_129 ;
if ( V_42 -> V_49 [ V_26 ] . V_50 & V_127 )
V_50 |= V_27 ;
return V_50 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_130 * V_131 )
{
int type ;
struct V_41 V_42 ;
int V_21 ;
memset ( & V_42 , 0 , sizeof ( struct V_41 ) ) ;
V_21 = V_2 -> V_18 -> V_48 ( V_2 , & V_42 ) ;
if ( V_21 < 0 )
return V_21 ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_132 = V_133 ;
V_131 -> V_134 = F_36 ( & V_42 ) ;
if ( ! V_131 -> V_134 )
return - V_31 ;
V_131 -> V_135 = V_42 . V_136 ;
for ( type = 0 ; type < V_47 ; type ++ )
if ( V_42 . V_49 [ type ] . V_50 & V_51 )
break;
F_38 ( type == V_47 ) ;
V_131 -> V_137 = V_42 . V_49 [ type ] . V_53 ;
V_131 -> V_138 = V_42 . V_49 [ type ] . V_55 ;
V_131 -> V_139 = V_42 . V_49 [ type ] . V_140 ;
V_131 -> V_141 = V_42 . V_49 [ type ] . V_142 ;
V_131 -> V_143 = V_42 . V_49 [ type ] . V_144 ;
if ( V_42 . V_49 [ V_13 ] . V_145 ) {
V_131 -> V_146 . V_147 = V_42 . V_49 [ V_13 ] . V_145 ;
V_131 -> V_146 . V_148 = V_42 . V_49 [ V_13 ] . V_77 ;
V_131 -> V_146 . V_149 = V_42 . V_49 [ V_13 ] . V_150 ;
}
if ( V_42 . V_49 [ V_14 ] . V_145 ) {
V_131 -> V_151 . V_147 = V_42 . V_49 [ V_14 ] . V_145 ;
V_131 -> V_151 . V_148 = V_42 . V_49 [ V_14 ] . V_77 ;
V_131 -> V_151 . V_149 = V_42 . V_49 [ V_14 ] . V_150 ;
}
if ( V_42 . V_49 [ V_26 ] . V_145 ) {
if ( ! ( V_42 . V_49 [ V_14 ] . V_50 & V_51 ) ) {
V_131 -> V_151 . V_147 = V_42 . V_49 [ V_26 ] . V_145 ;
V_131 -> V_151 . V_148 =
V_42 . V_49 [ V_26 ] . V_77 ;
V_131 -> V_151 . V_149 =
V_42 . V_49 [ V_26 ] . V_150 ;
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , void T_2 * V_34 )
{
struct V_130 V_131 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_48 )
return - V_31 ;
V_21 = F_37 ( V_2 , & V_131 ) ;
if ( ! V_21 && F_21 ( V_34 , & V_131 , sizeof( V_131 ) ) )
return - V_40 ;
return V_21 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_152 * V_131 )
{
int type ;
struct V_41 V_42 ;
int V_21 ;
memset ( & V_42 , 0 , sizeof ( struct V_41 ) ) ;
V_21 = V_2 -> V_18 -> V_48 ( V_2 , & V_42 ) ;
if ( V_21 < 0 )
return V_21 ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_132 = V_133 ;
V_131 -> V_134 = F_36 ( & V_42 ) ;
if ( ! V_131 -> V_134 )
return - V_31 ;
V_131 -> V_135 = V_42 . V_136 ;
for ( type = 0 ; type < V_47 ; type ++ )
if ( V_42 . V_49 [ type ] . V_50 & V_51 )
break;
F_38 ( type == V_47 ) ;
V_131 -> V_137 = V_42 . V_49 [ type ] . V_53 ;
V_131 -> V_138 = V_42 . V_49 [ type ] . V_55 ;
V_131 -> V_139 = V_42 . V_49 [ type ] . V_140 ;
V_131 -> V_141 = V_42 . V_49 [ type ] . V_142 ;
V_131 -> V_143 = V_42 . V_49 [ type ] . V_144 ;
if ( V_42 . V_49 [ V_13 ] . V_145 ) {
V_131 -> V_146 . V_147 = V_42 . V_49 [ V_13 ] . V_145 ;
V_131 -> V_146 . V_148 = V_42 . V_49 [ V_13 ] . V_77 ;
V_131 -> V_146 . V_149 = V_42 . V_49 [ V_13 ] . V_150 ;
}
if ( V_42 . V_49 [ V_14 ] . V_145 ) {
V_131 -> V_151 . V_147 = V_42 . V_49 [ V_14 ] . V_145 ;
V_131 -> V_151 . V_148 = V_42 . V_49 [ V_14 ] . V_77 ;
V_131 -> V_151 . V_149 = V_42 . V_49 [ V_14 ] . V_150 ;
}
if ( V_42 . V_49 [ V_26 ] . V_145 ) {
V_131 -> V_153 . V_147 = V_42 . V_49 [ V_26 ] . V_145 ;
V_131 -> V_153 . V_148 = V_42 . V_49 [ V_26 ] . V_77 ;
V_131 -> V_153 . V_149 = V_42 . V_49 [ V_26 ] . V_150 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , void T_2 * V_34 )
{
struct V_152 V_131 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_48 )
return - V_31 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
if ( F_25 ( & V_131 , V_34 , 1 ) )
return - V_40 ;
switch ( V_131 . V_132 ) {
case V_154 :
break;
default:
return - V_23 ;
}
V_21 = F_40 ( V_2 , & V_131 ) ;
if ( ! V_21 && F_21 ( V_34 , & V_131 , sizeof( V_131 ) ) )
return - V_40 ;
return V_21 ;
}
static inline T_5 F_42 ( T_5 V_77 )
{
return V_77 << V_155 ;
}
static inline T_5 F_43 ( T_5 V_156 )
{
return ( V_156 + ( 1 << V_155 ) - 1 ) >> V_155 ;
}
static void F_44 ( struct V_83 * V_82 , struct V_157 * V_84 )
{
V_82 -> V_86 = F_42 ( V_84 -> V_158 ) ;
V_82 -> V_88 = F_42 ( V_84 -> V_159 ) ;
V_82 -> V_92 = V_84 -> V_92 ;
V_82 -> V_94 = V_84 -> V_94 ;
V_82 -> V_90 = F_42 ( V_84 -> V_160 ) ;
V_82 -> V_96 = V_84 -> V_161 ;
V_82 -> V_100 = V_84 -> V_162 ;
V_82 -> V_98 = V_84 -> V_163 ;
V_82 -> V_164 = V_84 -> V_165 ;
V_82 -> V_166 = V_84 -> V_167 ;
V_82 -> V_168 = F_42 ( V_84 -> V_169 ) ;
V_82 -> V_170 = F_42 ( V_84 -> V_171 ) ;
V_82 -> V_172 = F_42 ( V_84 -> V_173 ) ;
V_82 -> V_174 = V_84 -> V_175 ;
V_82 -> V_176 = V_84 -> V_177 ;
V_82 -> V_112 = 0 ;
if ( V_84 -> V_112 & V_178 )
V_82 -> V_112 |= V_119 ;
if ( V_84 -> V_112 & V_179 )
V_82 -> V_112 |= V_120 ;
if ( V_84 -> V_112 & V_180 )
V_82 -> V_112 |= V_114 ;
if ( V_84 -> V_112 & V_181 )
V_82 -> V_112 |= V_115 ;
if ( V_84 -> V_112 & V_182 )
V_82 -> V_112 |= V_183 ;
if ( V_84 -> V_112 & V_184 )
V_82 -> V_112 |= V_185 ;
if ( V_84 -> V_112 & V_186 )
V_82 -> V_112 |= V_74 ;
if ( V_84 -> V_112 & V_187 )
V_82 -> V_112 |= V_76 ;
if ( V_84 -> V_112 & V_188 )
V_82 -> V_112 |= V_189 ;
if ( V_84 -> V_112 & V_190 )
V_82 -> V_112 |= V_191 ;
if ( V_84 -> V_112 & V_192 )
V_82 -> V_112 |= V_193 ;
if ( V_84 -> V_112 & V_194 )
V_82 -> V_112 |= V_195 ;
if ( V_84 -> V_112 & V_196 )
V_82 -> V_112 |= V_117 ;
if ( V_84 -> V_112 & V_197 )
V_82 -> V_112 |= V_122 ;
if ( V_84 -> V_112 & V_198 )
V_82 -> V_112 |= V_199 ;
}
static void F_45 ( struct V_63 * V_82 ,
struct V_157 * V_84 )
{
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> V_73 = V_84 -> V_163 ;
V_82 -> V_75 = V_84 -> V_162 ;
V_82 -> V_200 = V_84 -> V_175 ;
V_82 -> V_201 = V_84 -> V_165 ;
V_82 -> V_202 = V_84 -> V_167 ;
V_82 -> V_203 = V_84 -> V_177 ;
if ( V_84 -> V_112 & V_190 )
V_82 -> V_71 |= V_191 ;
if ( V_84 -> V_112 & V_192 )
V_82 -> V_71 |= V_193 ;
if ( V_84 -> V_112 & V_194 )
V_82 -> V_71 |= V_195 ;
if ( V_84 -> V_112 & V_186 )
V_82 -> V_71 |= V_74 ;
if ( V_84 -> V_112 & V_187 )
V_82 -> V_71 |= V_76 ;
if ( V_84 -> V_112 & V_188 )
V_82 -> V_71 |= V_189 ;
}
static int F_46 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_157 V_105 ;
struct V_83 V_204 ;
struct V_103 V_104 ;
if ( F_25 ( & V_105 , V_34 , sizeof( V_105 ) ) )
return - V_40 ;
if ( ! V_2 -> V_18 -> V_125 )
return - V_31 ;
V_104 = F_30 ( F_5 () , type , V_4 ) ;
if ( ! F_31 ( V_2 -> V_108 , V_104 ) )
return - V_23 ;
if ( F_33 ( V_2 -> V_108 , V_104 ) == 0 &&
V_105 . V_112 & ( V_205 | V_206 ) ) {
struct V_63 V_64 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_65 )
return - V_23 ;
F_45 ( & V_64 , & V_105 ) ;
V_21 = V_2 -> V_18 -> V_65 ( V_2 , type , & V_64 ) ;
if ( V_21 )
return V_21 ;
V_105 . V_112 &= ~ ( V_205 | V_206 ) ;
}
F_44 ( & V_204 , & V_105 ) ;
return V_2 -> V_18 -> V_125 ( V_2 , V_104 , & V_204 ) ;
}
static void F_47 ( struct V_157 * V_82 , struct V_83 * V_84 ,
int type , T_1 V_4 )
{
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> V_207 = V_208 ;
V_82 -> V_209 = V_4 ;
if ( type == V_13 )
V_82 -> V_210 = V_211 ;
else if ( type == V_26 )
V_82 -> V_210 = V_212 ;
else
V_82 -> V_210 = V_213 ;
V_82 -> V_158 = F_43 ( V_84 -> V_86 ) ;
V_82 -> V_159 = F_43 ( V_84 -> V_88 ) ;
V_82 -> V_92 = V_84 -> V_92 ;
V_82 -> V_94 = V_84 -> V_94 ;
V_82 -> V_160 = F_43 ( V_84 -> V_90 ) ;
V_82 -> V_161 = V_84 -> V_96 ;
V_82 -> V_162 = V_84 -> V_100 ;
V_82 -> V_163 = V_84 -> V_98 ;
V_82 -> V_165 = V_84 -> V_164 ;
V_82 -> V_167 = V_84 -> V_166 ;
V_82 -> V_169 = F_43 ( V_84 -> V_168 ) ;
V_82 -> V_171 = F_43 ( V_84 -> V_170 ) ;
V_82 -> V_173 = F_43 ( V_84 -> V_172 ) ;
V_82 -> V_175 = V_84 -> V_174 ;
V_82 -> V_177 = V_84 -> V_176 ;
}
static int F_48 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_157 V_105 ;
struct V_83 V_204 ;
struct V_103 V_104 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_107 )
return - V_31 ;
V_104 = F_30 ( F_5 () , type , V_4 ) ;
if ( ! F_31 ( V_2 -> V_108 , V_104 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_107 ( V_2 , V_104 , & V_204 ) ;
if ( V_21 )
return V_21 ;
F_47 ( & V_105 , & V_204 , type , V_4 ) ;
if ( F_21 ( V_34 , & V_105 , sizeof( V_105 ) ) )
return - V_40 ;
return V_21 ;
}
static int F_49 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_34 )
{
struct V_157 V_105 ;
struct V_83 V_204 ;
struct V_103 V_104 ;
T_1 V_214 ;
int V_21 ;
if ( ! V_2 -> V_18 -> V_110 )
return - V_31 ;
V_104 = F_30 ( F_5 () , type , V_4 ) ;
if ( ! F_31 ( V_2 -> V_108 , V_104 ) )
return - V_23 ;
V_21 = V_2 -> V_18 -> V_110 ( V_2 , & V_104 , & V_204 ) ;
if ( V_21 )
return V_21 ;
V_214 = F_33 ( F_5 () , V_104 ) ;
F_47 ( & V_105 , & V_204 , type , V_214 ) ;
if ( F_21 ( V_34 , & V_105 , sizeof( V_105 ) ) )
return - V_40 ;
return V_21 ;
}
static int F_50 ( struct V_1 * V_2 , void T_2 * V_34 )
{
T_3 V_50 ;
if ( F_25 ( & V_50 , V_34 , sizeof( V_50 ) ) )
return - V_40 ;
if ( ! V_2 -> V_18 -> V_215 )
return - V_31 ;
return V_2 -> V_18 -> V_215 ( V_2 , V_50 ) ;
}
static int F_51 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
void T_2 * V_34 , const struct V_28 * V_28 )
{
int V_21 ;
if ( type >= ( F_52 ( V_3 ) ? V_47 : V_22 ) )
return - V_23 ;
if ( ! V_2 -> V_18 )
return - V_31 ;
if ( ! ( V_2 -> V_20 & ( 1 << type ) ) )
return - V_23 ;
V_21 = F_1 ( V_2 , type , V_3 , V_4 ) ;
if ( V_21 < 0 )
return V_21 ;
switch ( V_3 ) {
case V_216 :
return F_14 ( V_2 , type , V_4 , V_28 ) ;
case V_217 :
return F_17 ( V_2 , type ) ;
case V_5 :
return F_18 ( V_2 , type , V_34 ) ;
case V_7 :
return F_22 ( V_2 , type , V_34 ) ;
case V_218 :
return F_24 ( V_2 , type , V_34 ) ;
case V_11 :
return F_29 ( V_2 , type , V_4 , V_34 ) ;
case V_219 :
return F_32 ( V_2 , type , V_4 , V_34 ) ;
case V_220 :
return F_35 ( V_2 , type , V_4 , V_34 ) ;
case V_6 :
if ( ! V_2 -> V_18 -> V_19 )
return - V_31 ;
return V_2 -> V_18 -> V_19 ( V_2 , type ) ;
case V_221 :
return V_30 ( V_2 , V_34 ) ;
case V_222 :
return V_33 ( V_2 , V_34 ) ;
case V_223 :
return F_50 ( V_2 , V_34 ) ;
case V_8 :
return F_39 ( V_2 , V_34 ) ;
case V_9 :
return F_41 ( V_2 , V_34 ) ;
case V_224 :
return F_46 ( V_2 , type , V_4 , V_34 ) ;
case V_12 :
return F_48 ( V_2 , type , V_4 , V_34 ) ;
case V_225 :
return F_49 ( V_2 , type , V_4 , V_34 ) ;
case V_10 :
if ( F_53 ( V_2 ) )
return - V_226 ;
return 0 ;
default:
return - V_23 ;
}
}
static int F_54 ( int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_7 :
case V_6 :
case V_8 :
case V_9 :
case V_12 :
case V_225 :
case V_10 :
return 0 ;
}
return 1 ;
}
static bool F_55 ( int V_3 )
{
return ( V_3 == V_216 ) || ( V_3 == V_217 ) ;
}
static struct V_1 * F_56 ( const char T_2 * V_227 , int V_3 )
{
#ifdef F_57
struct V_228 * V_229 ;
struct V_1 * V_2 ;
struct V_230 * V_231 = F_58 ( V_227 ) ;
if ( F_15 ( V_231 ) )
return F_59 ( V_231 ) ;
V_229 = F_60 ( V_231 -> V_232 ) ;
F_61 ( V_231 ) ;
if ( F_15 ( V_229 ) )
return F_59 ( V_229 ) ;
if ( F_55 ( V_3 ) )
V_2 = F_62 ( V_229 ) ;
else if ( F_54 ( V_3 ) )
V_2 = F_63 ( V_229 ) ;
else
V_2 = F_64 ( V_229 ) ;
F_65 ( V_229 ) ;
if ( ! V_2 )
return F_66 ( - V_233 ) ;
return V_2 ;
#else
return F_66 ( - V_233 ) ;
#endif
}
