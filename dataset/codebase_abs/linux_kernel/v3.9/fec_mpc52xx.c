static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_3 ( & V_2 -> V_2 , L_1 ) ;
F_4 ( & V_4 -> V_6 , V_5 ) ;
F_5 ( V_2 ) ;
V_2 -> V_7 . V_8 ++ ;
F_6 ( & V_4 -> V_6 , V_5 ) ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
F_9 ( & V_11 -> V_12 , * ( V_13 * ) ( & V_9 [ 0 ] ) ) ;
F_9 ( & V_11 -> V_14 , ( * ( V_15 * ) ( & V_9 [ 4 ] ) << 16 ) | V_16 ) ;
}
static int F_10 ( struct V_1 * V_2 , void * V_17 )
{
struct V_18 * V_19 = V_17 ;
memcpy ( V_2 -> V_20 , V_19 -> V_21 , V_2 -> V_22 ) ;
F_8 ( V_2 , V_19 -> V_21 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
while ( ! F_12 ( V_24 ) ) {
struct V_25 * V_26 ;
struct V_27 * V_28 ;
V_28 = F_13 ( V_24 , NULL , (struct V_29 * * ) & V_26 ) ;
F_14 ( V_2 -> V_2 . V_30 , V_26 -> V_31 , V_28 -> V_32 ,
V_33 ) ;
F_15 ( V_28 ) ;
}
}
static void
F_16 ( struct V_1 * V_2 , struct V_27 * V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_25 * V_26 ;
V_26 = (struct V_25 * ) F_17 ( V_4 -> V_35 ) ;
V_26 -> V_36 = V_37 ;
V_26 -> V_31 = F_18 ( V_2 -> V_2 . V_30 , V_34 -> V_38 ,
V_37 , V_33 ) ;
F_19 ( V_4 -> V_35 , V_34 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_23 * V_39 )
{
struct V_27 * V_28 ;
while ( ! F_21 ( V_39 ) ) {
V_28 = F_22 ( V_2 , V_37 ) ;
if ( ! V_28 )
return - V_40 ;
memset ( V_28 -> V_38 , 0 , V_37 ) ;
F_16 ( V_2 , V_28 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_41 * V_42 = V_4 -> V_42 ;
int V_43 = 0 ;
if ( V_42 -> V_44 != V_45 ) {
if ( V_42 -> V_46 != V_4 -> V_46 ) {
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
V_13 V_47 ;
V_13 V_48 ;
V_43 = 1 ;
V_4 -> V_46 = V_42 -> V_46 ;
V_47 = F_24 ( & V_11 -> V_49 ) ;
V_48 = F_24 ( & V_11 -> V_50 ) ;
V_47 &= ~ V_51 ;
V_48 &= ~ V_52 ;
if ( V_42 -> V_46 == V_53 )
V_48 |= V_52 ;
else
V_47 |= V_51 ;
F_9 ( & V_11 -> V_49 , V_47 ) ;
F_9 ( & V_11 -> V_50 , V_48 ) ;
}
if ( V_42 -> V_54 != V_4 -> V_54 ) {
V_43 = 1 ;
V_4 -> V_54 = V_42 -> V_54 ;
}
if ( V_4 -> V_44 == V_45 ) {
V_43 = 1 ;
V_4 -> V_44 = V_42 -> V_44 ;
}
} else if ( V_4 -> V_44 ) {
V_43 = 1 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_54 = 0 ;
V_4 -> V_46 = - 1 ;
}
if ( V_43 && F_25 ( V_4 ) )
F_26 ( V_42 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_55 = - V_56 ;
if ( V_4 -> V_57 ) {
V_4 -> V_42 = F_28 ( V_4 -> V_58 , V_4 -> V_57 ,
F_23 , 0 , 0 ) ;
if ( ! V_4 -> V_42 ) {
F_29 ( & V_2 -> V_2 , L_2 ) ;
return - V_59 ;
}
F_30 ( V_4 -> V_42 ) ;
}
if ( F_31 ( V_2 -> V_60 , V_61 , V_62 ,
V_63 L_3 , V_2 ) ) {
F_29 ( & V_2 -> V_2 , L_4 ) ;
goto V_64;
}
if ( F_31 ( V_4 -> V_65 , V_66 , 0 ,
V_63 L_5 , V_2 ) ) {
F_29 ( & V_2 -> V_2 , L_6 ) ;
goto V_67;
}
if ( F_31 ( V_4 -> V_68 , V_69 , 0 ,
V_63 L_7 , V_2 ) ) {
F_29 ( & V_2 -> V_2 , L_8 ) ;
goto V_70;
}
F_32 ( V_4 -> V_35 ) ;
F_33 ( V_4 -> V_71 ) ;
V_55 = F_20 ( V_2 , V_4 -> V_35 ) ;
if ( V_55 ) {
F_29 ( & V_2 -> V_2 , L_9 ) ;
goto V_72;
}
F_34 ( V_4 -> V_35 ) ;
F_34 ( V_4 -> V_71 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
V_72:
F_37 ( V_4 -> V_68 , V_2 ) ;
V_70:
F_37 ( V_4 -> V_65 , V_2 ) ;
V_67:
F_37 ( V_2 -> V_60 , V_2 ) ;
V_64:
if ( V_4 -> V_42 ) {
F_38 ( V_4 -> V_42 ) ;
F_39 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
}
return V_55 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_11 ( V_2 , V_4 -> V_35 ) ;
F_37 ( V_2 -> V_60 , V_2 ) ;
F_37 ( V_4 -> V_65 , V_2 ) ;
F_37 ( V_4 -> V_68 , V_2 ) ;
if ( V_4 -> V_42 ) {
F_38 ( V_4 -> V_42 ) ;
F_39 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
}
return 0 ;
}
static int F_43 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_25 * V_26 ;
unsigned long V_5 ;
if ( F_21 ( V_4 -> V_71 ) ) {
if ( F_44 () )
F_29 ( & V_2 -> V_2 , L_10 ) ;
return V_73 ;
}
F_4 ( & V_4 -> V_6 , V_5 ) ;
V_26 = (struct V_25 * )
F_17 ( V_4 -> V_71 ) ;
V_26 -> V_36 = V_28 -> V_32 | V_74 | V_75 ;
V_26 -> V_31 = F_18 ( V_2 -> V_2 . V_30 , V_28 -> V_38 , V_28 -> V_32 ,
V_76 ) ;
F_45 ( V_28 ) ;
F_19 ( V_4 -> V_71 , V_28 ) ;
F_6 ( & V_4 -> V_6 , V_5 ) ;
if ( F_21 ( V_4 -> V_71 ) ) {
F_41 ( V_2 ) ;
}
return V_77 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_47 ( V_4 -> V_68 ) ;
V_69 ( V_4 -> V_68 , V_2 ) ;
F_48 ( V_4 -> V_68 ) ;
F_47 ( V_4 -> V_65 ) ;
V_66 ( V_4 -> V_65 , V_2 ) ;
F_48 ( V_4 -> V_65 ) ;
}
static T_3 V_69 ( int V_60 , void * V_78 )
{
struct V_1 * V_2 = V_78 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_49 ( & V_4 -> V_6 ) ;
while ( F_50 ( V_4 -> V_71 ) ) {
struct V_27 * V_28 ;
struct V_25 * V_26 ;
V_28 = F_13 ( V_4 -> V_71 , NULL ,
(struct V_29 * * ) & V_26 ) ;
F_14 ( V_2 -> V_2 . V_30 , V_26 -> V_31 , V_28 -> V_32 ,
V_76 ) ;
F_51 ( V_28 ) ;
}
F_52 ( & V_4 -> V_6 ) ;
F_7 ( V_2 ) ;
return V_79 ;
}
static T_3 V_66 ( int V_60 , void * V_78 )
{
struct V_1 * V_2 = V_78 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_34 ;
struct V_27 * V_28 ;
struct V_25 * V_26 ;
V_13 V_36 , V_80 ;
int V_81 ;
F_49 ( & V_4 -> V_6 ) ;
while ( F_50 ( V_4 -> V_35 ) ) {
V_34 = F_13 ( V_4 -> V_35 , & V_36 ,
(struct V_29 * * ) & V_26 ) ;
V_80 = V_26 -> V_31 ;
if ( V_36 & V_82 ) {
F_16 ( V_2 , V_34 ) ;
V_2 -> V_7 . V_83 ++ ;
continue;
}
V_28 = F_22 ( V_2 , V_37 ) ;
if ( ! V_28 ) {
F_53 ( & V_2 -> V_2 , L_11 ) ;
F_16 ( V_2 , V_34 ) ;
V_2 -> V_7 . V_83 ++ ;
continue;
}
F_16 ( V_2 , V_28 ) ;
F_52 ( & V_4 -> V_6 ) ;
F_14 ( V_2 -> V_2 . V_30 , V_80 , V_34 -> V_32 ,
V_33 ) ;
V_81 = V_36 & V_84 ;
F_54 ( V_34 , V_81 - 4 ) ;
V_34 -> V_85 = F_55 ( V_34 , V_2 ) ;
if ( ! F_56 ( V_34 ) )
F_57 ( V_34 ) ;
F_49 ( & V_4 -> V_6 ) ;
}
F_52 ( & V_4 -> V_6 ) ;
return V_79 ;
}
static T_3 V_61 ( int V_60 , void * V_78 )
{
struct V_1 * V_2 = V_78 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
V_13 V_86 ;
V_86 = F_24 ( & V_11 -> V_86 ) ;
V_86 &= ~ V_87 ;
if ( ! V_86 )
return V_88 ;
F_9 ( & V_11 -> V_86 , V_86 ) ;
if ( V_86 & ( V_89 | V_90 ) ) {
if ( F_44 () && ( V_86 & V_89 ) )
F_3 ( & V_2 -> V_2 , L_12 ) ;
if ( F_44 () && ( V_86 & V_90 ) )
F_3 ( & V_2 -> V_2 , L_13 ) ;
F_49 ( & V_4 -> V_6 ) ;
F_5 ( V_2 ) ;
F_52 ( & V_4 -> V_6 ) ;
return V_79 ;
}
if ( V_86 & ~ V_91 )
F_58 ( & V_2 -> V_2 , L_14 , V_86 ) ;
return V_79 ;
}
static struct V_92 * F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_92 * V_7 = & V_2 -> V_7 ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
V_7 -> V_93 = F_24 ( & V_11 -> V_94 ) ;
V_7 -> V_95 = F_24 ( & V_11 -> V_96 ) ;
V_7 -> V_97 = F_24 ( & V_11 -> V_98 ) +
F_24 ( & V_11 -> V_99 ) +
F_24 ( & V_11 -> V_100 ) +
F_24 ( & V_11 -> V_101 ) +
F_24 ( & V_11 -> V_102 ) ;
V_7 -> V_103 = F_24 ( & V_11 -> V_104 ) ;
V_7 -> V_105 = F_24 ( & V_11 -> V_106 ) ;
V_7 -> V_8 = F_24 ( & V_11 -> V_107 ) +
F_24 ( & V_11 -> V_108 ) +
F_24 ( & V_11 -> V_109 ) +
F_24 ( & V_11 -> V_110 ) +
F_24 ( & V_11 -> V_111 ) ;
V_7 -> V_112 = F_24 ( & V_11 -> V_113 ) ;
V_7 -> V_114 = F_24 ( & V_11 -> V_115 ) ;
V_7 -> V_116 = F_24 ( & V_11 -> V_99 )
+ F_24 ( & V_11 -> V_100 )
+ F_24 ( & V_11 -> V_101 )
+ F_24 ( & V_11 -> V_102 ) ;
V_7 -> V_117 = F_24 ( & V_11 -> V_118 ) ;
V_7 -> V_119 = F_24 ( & V_11 -> V_120 ) ;
V_7 -> V_121 = F_24 ( & V_11 -> V_122 ) ;
V_7 -> V_123 = F_24 ( & V_11 -> V_124 ) ;
V_7 -> V_125 = F_24 ( & V_11 -> V_124 ) ;
V_7 -> V_126 = 0 ;
V_7 -> V_127 = F_24 ( & V_11 -> V_128 ) ;
V_7 -> V_129 = F_24 ( & V_11 -> V_130 ) ;
V_7 -> V_131 = F_24 ( & V_11 -> V_132 ) ;
V_7 -> V_133 = F_24 ( & V_11 -> V_134 ) ;
return V_7 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
F_9 ( & V_11 -> V_135 , V_136 ) ;
F_61 ( & V_11 -> V_130 , 0 ,
F_62 ( struct V_10 , V_137 ) -
F_62 ( struct V_10 , V_130 ) ) ;
F_9 ( & V_11 -> V_135 , 0 ) ;
memset ( & V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
V_13 V_138 ;
V_138 = F_24 ( & V_11 -> V_49 ) ;
if ( V_2 -> V_5 & V_139 ) {
V_138 |= V_140 ;
F_9 ( & V_11 -> V_49 , V_138 ) ;
} else {
V_138 &= ~ V_140 ;
F_9 ( & V_11 -> V_49 , V_138 ) ;
if ( V_2 -> V_5 & V_141 ) {
F_9 ( & V_11 -> V_142 , 0xffffffff ) ;
F_9 ( & V_11 -> V_143 , 0xffffffff ) ;
} else {
V_13 V_144 ;
struct V_145 * V_146 ;
V_13 V_142 = 0x00000000 ;
V_13 V_143 = 0x00000000 ;
F_64 (ha, dev) {
V_144 = F_65 ( 6 , V_146 -> V_17 ) >> 26 ;
if ( V_144 >= 32 )
V_142 |= 1 << ( V_144 - 32 ) ;
else
V_143 |= 1 << V_144 ;
}
F_9 ( & V_11 -> V_142 , V_142 ) ;
F_9 ( & V_11 -> V_143 , V_143 ) ;
}
}
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
int V_147 ;
F_9 ( & V_11 -> V_148 , V_149 ) ;
for ( V_147 = 0 ; V_147 < V_150 ; ++ V_147 ) {
if ( ( F_24 ( & V_11 -> V_148 ) & V_149 ) == 0 )
break;
F_67 ( 1 ) ;
}
if ( V_147 == V_150 )
F_29 ( & V_2 -> V_2 , L_15 ) ;
F_9 ( & V_11 -> V_151 , V_152 | 0x20 ) ;
F_9 ( & V_11 -> V_153 , V_154 | V_155 ) ;
F_9 ( & V_11 -> V_156 , V_154 | V_155 ) ;
F_9 ( & V_11 -> V_157 , 0x0000030c ) ;
F_9 ( & V_11 -> V_158 , 0x00000100 ) ;
F_9 ( & V_11 -> V_159 , V_160 ) ;
F_9 ( & V_11 -> V_161 , V_162 | V_163 ) ;
F_9 ( & V_11 -> V_164 , 0x00000000 ) ;
F_9 ( & V_11 -> V_165 , 0x00000000 ) ;
F_9 ( & V_11 -> V_166 , V_4 -> V_167 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
V_13 V_47 ;
V_13 V_48 ;
V_13 V_168 ;
V_168 = V_169 | V_170 | V_171 ;
F_9 ( & V_11 -> V_172 , F_24 ( & V_11 -> V_172 ) & V_168 ) ;
F_9 ( & V_11 -> V_173 , F_24 ( & V_11 -> V_173 ) & V_168 ) ;
F_9 ( & V_11 -> V_174 , V_175 ) ;
F_8 ( V_2 , V_2 -> V_20 ) ;
F_63 ( V_2 ) ;
V_47 = V_37 << 16 ;
V_47 |= V_176 ;
if ( ! V_4 -> V_177 )
V_47 |= V_178 ;
if ( V_4 -> V_46 == V_53 )
V_48 = V_52 ;
else {
V_47 |= V_51 ;
V_48 = 0 ;
}
F_9 ( & V_11 -> V_49 , V_47 ) ;
F_9 ( & V_11 -> V_50 , V_48 ) ;
F_9 ( & V_11 -> V_86 , 0xffffffff ) ;
F_9 ( & V_11 -> V_179 , V_180 ) ;
F_9 ( & V_11 -> V_148 , V_181 ) ;
F_9 ( & V_11 -> V_182 , 0x01000000 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
unsigned long V_183 ;
F_9 ( & V_11 -> V_179 , 0 ) ;
F_68 ( V_4 -> V_35 ) ;
if ( ! F_69 () ) {
V_183 = V_184 + F_70 ( 2000 ) ;
while ( F_71 ( V_184 , V_183 ) &&
! F_12 ( V_4 -> V_71 ) )
F_72 ( 100 ) ;
if ( F_73 ( V_184 , V_183 ) )
F_29 ( & V_2 -> V_2 , L_16 ) ;
#if 1
if ( F_73 ( V_184 , V_183 ) ) {
F_29 ( & V_2 -> V_2 , L_17 ,
V_4 -> V_71 -> V_185 ,
V_4 -> V_71 -> V_186 ) ;
F_29 ( & V_2 -> V_2 , L_18 ,
V_4 -> V_35 -> V_185 ,
V_4 -> V_35 -> V_186 ) ;
}
#endif
}
F_68 ( V_4 -> V_71 ) ;
F_9 ( & V_11 -> V_148 , F_24 ( & V_11 -> V_148 ) & ~ V_181 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
F_42 ( V_2 ) ;
F_9 ( & V_11 -> V_172 , F_24 ( & V_11 -> V_172 ) ) ;
F_9 ( & V_11 -> V_174 , V_187 ) ;
F_11 ( V_2 , V_4 -> V_35 ) ;
F_66 ( V_2 ) ;
F_32 ( V_4 -> V_35 ) ;
F_33 ( V_4 -> V_71 ) ;
F_20 ( V_2 , V_4 -> V_35 ) ;
F_34 ( V_4 -> V_35 ) ;
F_34 ( V_4 -> V_71 ) ;
F_35 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_42 )
return - V_59 ;
return F_75 ( V_4 -> V_42 , V_189 ) ;
}
static int F_76 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_42 )
return - V_59 ;
return F_77 ( V_4 -> V_42 , V_189 ) ;
}
static V_13 F_78 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_190 ;
}
static void F_79 ( struct V_1 * V_2 , V_13 V_191 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_190 = V_191 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_192 * V_193 , int V_189 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_42 )
return - V_194 ;
return F_81 ( V_4 -> V_42 , V_193 , V_189 ) ;
}
static int F_82 ( struct V_195 * V_196 )
{
int V_197 ;
struct V_1 * V_58 ;
struct V_3 * V_4 = NULL ;
struct V_198 V_199 ;
const V_13 * V_200 ;
int V_201 ;
struct V_202 * V_203 = V_196 -> V_2 . V_204 ;
const char * V_205 ;
T_4 V_206 ;
T_4 V_207 ;
V_58 = F_83 ( sizeof( struct V_3 ) ) ;
if ( ! V_58 )
return - V_208 ;
V_4 = F_2 ( V_58 ) ;
V_4 -> V_58 = V_58 ;
V_197 = F_84 ( V_203 , 0 , & V_199 ) ;
if ( V_197 ) {
F_85 (KERN_ERR DRIVER_NAME L_19
L_20 ) ;
goto V_209;
}
if ( F_86 ( & V_199 ) < sizeof( struct V_10 ) ) {
F_85 (KERN_ERR DRIVER_NAME
L_21 ,
(unsigned long)resource_size(&mem),
sizeof(struct mpc52xx_fec)) ;
V_197 = - V_210 ;
goto V_209;
}
if ( ! F_87 ( V_199 . V_211 , sizeof( struct V_10 ) ,
V_63 ) ) {
V_197 = - V_56 ;
goto V_209;
}
V_58 -> V_212 = & V_213 ;
V_58 -> V_214 = & V_215 ;
V_58 -> V_216 = V_217 ;
V_58 -> V_218 = V_199 . V_211 ;
F_88 ( V_58 , & V_196 -> V_2 ) ;
F_89 ( & V_4 -> V_6 ) ;
V_4 -> V_11 = F_90 ( V_199 . V_211 , sizeof( struct V_10 ) ) ;
if ( ! V_4 -> V_11 ) {
V_197 = - V_208 ;
goto V_219;
}
V_206 = V_58 -> V_218 + F_62 ( struct V_10 , V_220 ) ;
V_207 = V_58 -> V_218 + F_62 ( struct V_10 , V_221 ) ;
V_4 -> V_35 = F_91 ( V_222 , V_206 , V_37 ) ;
V_4 -> V_71 = F_92 ( V_223 , V_207 ) ;
if ( ! V_4 -> V_35 || ! V_4 -> V_71 ) {
F_85 (KERN_ERR DRIVER_NAME L_22 ) ;
V_197 = - V_208 ;
goto V_224;
}
V_58 -> V_60 = F_93 ( V_203 , 0 ) ;
V_4 -> V_65 = F_94 ( V_4 -> V_35 ) ;
V_4 -> V_68 = F_94 ( V_4 -> V_71 ) ;
V_205 = F_95 ( V_203 ) ;
if ( V_205 ) {
memcpy ( V_58 -> V_20 , V_205 , V_225 ) ;
} else {
struct V_10 T_2 * V_11 = V_4 -> V_11 ;
* ( V_13 * ) ( & V_58 -> V_20 [ 0 ] ) = F_24 ( & V_11 -> V_12 ) ;
* ( V_15 * ) ( & V_58 -> V_20 [ 4 ] ) = F_24 ( & V_11 -> V_14 ) >> 16 ;
}
if ( ! F_96 ( V_58 -> V_20 ) ) {
F_97 ( V_58 ) ;
F_3 ( & V_58 -> V_2 , L_23 ,
V_58 -> V_20 ) ;
}
V_4 -> V_190 = F_98 ( V_226 , V_227 ) ;
V_4 -> V_54 = 100 ;
V_4 -> V_46 = V_228 ;
V_4 -> V_167 = ( ( F_99 ( V_203 ) >> 20 ) / 5 ) << 1 ;
V_200 = F_100 ( V_203 , L_24 , & V_201 ) ;
if ( V_200 && ( V_201 >= sizeof( V_13 ) * 2 ) ) {
V_4 -> V_54 = V_200 [ 0 ] ;
V_4 -> V_46 = V_200 [ 1 ] ? V_53 : V_228 ;
}
V_4 -> V_57 = F_101 ( V_203 , L_25 , 0 ) ;
if ( F_102 ( V_203 , L_26 , NULL ) ) {
V_4 -> V_177 = 1 ;
F_103 ( & V_58 -> V_2 , L_27 ) ;
}
F_66 ( V_58 ) ;
F_60 ( V_58 ) ;
V_197 = F_104 ( V_58 ) ;
if ( V_197 < 0 )
goto V_229;
F_105 ( & V_196 -> V_2 , V_58 ) ;
F_85 ( V_230 L_28 ,
V_58 -> V_231 , V_196 -> V_2 . V_204 -> V_232 , V_58 -> V_20 ) ;
return 0 ;
V_229:
F_106 ( V_4 -> V_57 ) ;
F_107 ( V_58 -> V_60 ) ;
V_224:
if ( V_4 -> V_35 )
F_108 ( V_4 -> V_35 ) ;
if ( V_4 -> V_71 )
F_109 ( V_4 -> V_71 ) ;
F_110 ( V_4 -> V_11 ) ;
V_219:
F_111 ( V_199 . V_211 , sizeof( struct V_10 ) ) ;
V_209:
F_112 ( V_58 ) ;
return V_197 ;
}
static int
F_113 ( struct V_195 * V_196 )
{
struct V_1 * V_58 ;
struct V_3 * V_4 ;
V_58 = F_114 ( & V_196 -> V_2 ) ;
V_4 = F_2 ( V_58 ) ;
F_115 ( V_58 ) ;
if ( V_4 -> V_57 )
F_106 ( V_4 -> V_57 ) ;
V_4 -> V_57 = NULL ;
F_107 ( V_58 -> V_60 ) ;
F_108 ( V_4 -> V_35 ) ;
F_109 ( V_4 -> V_71 ) ;
F_110 ( V_4 -> V_11 ) ;
F_111 ( V_58 -> V_218 , sizeof( struct V_10 ) ) ;
F_112 ( V_58 ) ;
F_105 ( & V_196 -> V_2 , NULL ) ;
return 0 ;
}
static int F_116 ( struct V_195 * V_196 , T_5 V_233 )
{
struct V_1 * V_2 = F_114 ( & V_196 -> V_2 ) ;
if ( F_117 ( V_2 ) )
F_40 ( V_2 ) ;
return 0 ;
}
static int F_118 ( struct V_195 * V_196 )
{
struct V_1 * V_2 = F_114 ( & V_196 -> V_2 ) ;
F_66 ( V_2 ) ;
F_60 ( V_2 ) ;
if ( F_117 ( V_2 ) )
F_27 ( V_2 ) ;
return 0 ;
}
static int T_6
F_119 ( void )
{
#ifdef F_120
int V_234 ;
V_234 = F_121 ( & V_235 ) ;
if ( V_234 ) {
F_85 (KERN_ERR DRIVER_NAME L_29 ) ;
return V_234 ;
}
#endif
return F_121 ( & V_236 ) ;
}
static void T_7
F_122 ( void )
{
F_123 ( & V_236 ) ;
#ifdef F_120
F_123 ( & V_235 ) ;
#endif
}
