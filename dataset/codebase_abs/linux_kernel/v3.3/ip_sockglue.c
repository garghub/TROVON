static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = * F_2 ( V_4 ) ;
V_6 . V_7 . V_8 = F_3 ( V_4 ) -> V_9 ;
F_4 ( V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 = F_3 ( V_4 ) -> V_12 ;
F_4 ( V_2 , V_10 , V_13 , sizeof( int ) , & V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( V_2 , V_10 , V_14 , 1 , & F_3 ( V_4 ) -> V_15 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_8 ( V_4 ) -> V_16 . V_17 == 0 )
return;
F_4 ( V_2 , V_10 , V_18 , F_8 ( V_4 ) -> V_16 . V_17 ,
F_3 ( V_4 ) + 1 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
if ( F_8 ( V_4 ) -> V_16 . V_17 == 0 )
return;
if ( F_10 ( V_16 , V_4 ) ) {
V_2 -> V_21 |= V_22 ;
return;
}
F_11 ( V_16 ) ;
F_4 ( V_2 , V_10 , V_23 , V_16 -> V_17 , V_16 -> V_24 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_25 ;
T_1 V_26 , V_27 ;
int V_28 ;
V_28 = F_13 ( NULL , V_4 , & V_27 ) ;
if ( V_28 )
return;
V_28 = F_14 ( V_27 , & V_25 , & V_26 ) ;
if ( V_28 )
return;
F_4 ( V_2 , V_10 , V_29 , V_26 , V_25 ) ;
F_15 ( V_25 , V_26 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_30 sin ;
const struct V_31 * V_32 = F_3 ( V_4 ) ;
T_2 * V_33 = ( T_2 * ) F_17 ( V_4 ) ;
if ( F_18 ( V_4 ) + 4 > V_4 -> V_34 )
return;
sin . V_35 = V_36 ;
sin . V_37 . V_8 = V_32 -> V_9 ;
sin . V_38 = V_33 [ 1 ] ;
memset ( sin . V_39 , 0 , sizeof( sin . V_39 ) ) ;
F_4 ( V_2 , V_10 , V_40 , sizeof( sin ) , & sin ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_41 * V_42 = F_20 ( V_4 -> V_43 ) ;
unsigned V_44 = V_42 -> V_45 ;
if ( V_44 & 1 )
F_1 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_5 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_6 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_7 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_9 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_12 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_16 ( V_2 , V_4 ) ;
}
int F_21 ( struct V_46 * V_46 , struct V_1 * V_2 , struct V_47 * V_48 )
{
int V_28 ;
struct V_49 * V_50 ;
for ( V_50 = F_22 ( V_2 ) ; V_50 ; V_50 = F_23 ( V_2 , V_50 ) ) {
if ( ! F_24 ( V_2 , V_50 ) )
return - V_51 ;
if ( V_50 -> V_52 != V_10 )
continue;
switch ( V_50 -> V_53 ) {
case V_23 :
V_28 = V_50 -> V_54 - F_25 ( sizeof( struct V_49 ) ) ;
V_28 = F_26 ( V_46 , & V_48 -> V_16 , F_27 ( V_50 ) ,
V_28 < 40 ? V_28 : 40 ) ;
if ( V_28 )
return V_28 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_50 -> V_54 != F_28 ( sizeof( struct V_5 ) ) )
return - V_51 ;
V_6 = (struct V_5 * ) F_27 ( V_50 ) ;
V_48 -> V_55 = V_6 -> V_56 ;
V_48 -> V_57 = V_6 -> V_58 . V_8 ;
break;
}
default:
return - V_51 ;
}
}
return 0 ;
}
static void F_29 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_30 ( V_60 , struct V_61 , V_63 ) ;
F_31 ( V_62 -> V_64 ) ;
F_32 ( V_62 ) ;
}
int F_33 ( struct V_65 * V_43 , unsigned char V_66 ,
void (* F_34)( struct V_65 * ) )
{
struct V_61 * V_62 , * V_67 ;
struct V_61 T_3 * * V_68 ;
if ( V_43 -> V_69 != V_70 || F_20 ( V_43 ) -> V_71 == V_72 )
return - V_51 ;
V_67 = V_66 ? F_35 ( sizeof( * V_67 ) , V_73 ) : NULL ;
F_36 ( & V_74 ) ;
for ( V_68 = & V_61 ;
( V_62 = F_37 ( * V_68 ,
F_38 ( & V_74 ) ) ) != NULL ;
V_68 = & V_62 -> V_75 ) {
if ( V_62 -> V_43 == V_43 ) {
if ( V_66 ) {
F_39 ( & V_74 ) ;
F_32 ( V_67 ) ;
return - V_76 ;
}
V_62 -> V_43 = NULL ;
F_40 ( * V_68 , V_62 -> V_75 ) ;
F_39 ( & V_74 ) ;
if ( V_62 -> F_34 )
V_62 -> F_34 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
F_41 ( & V_62 -> V_63 , F_29 ) ;
return 0 ;
}
}
if ( V_67 == NULL ) {
F_39 ( & V_74 ) ;
return - V_77 ;
}
V_67 -> V_43 = V_43 ;
V_67 -> F_34 = F_34 ;
V_67 -> V_75 = V_62 ;
F_40 ( * V_68 , V_67 ) ;
F_42 ( V_43 ) ;
F_39 ( & V_74 ) ;
return 0 ;
}
void F_43 ( struct V_65 * V_43 , struct V_3 * V_4 , int V_28 ,
T_2 V_78 , T_1 V_6 , T_4 * V_79 )
{
struct V_80 * V_81 ;
V_4 = F_44 ( V_4 , V_82 ) ;
if ( ! V_4 )
return;
V_81 = F_45 ( V_4 ) ;
V_81 -> V_83 . V_84 = V_28 ;
V_81 -> V_83 . V_85 = V_86 ;
V_81 -> V_83 . V_87 = F_46 ( V_4 ) -> type ;
V_81 -> V_83 . V_88 = F_46 ( V_4 ) -> V_89 ;
V_81 -> V_83 . V_90 = 0 ;
V_81 -> V_83 . V_91 = V_6 ;
V_81 -> V_83 . V_92 = 0 ;
V_81 -> V_93 = ( T_4 * ) & ( ( (struct V_31 * ) ( F_46 ( V_4 ) + 1 ) ) -> V_9 ) -
F_47 ( V_4 ) ;
V_81 -> V_78 = V_78 ;
if ( F_48 ( V_4 , V_79 - V_4 -> V_94 ) != NULL ) {
F_49 ( V_4 ) ;
if ( F_50 ( V_43 , V_4 ) == 0 )
return;
}
F_51 ( V_4 ) ;
}
void F_52 ( struct V_65 * V_43 , int V_28 , T_5 V_9 , T_2 V_78 , T_1 V_6 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
struct V_80 * V_81 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
if ( ! V_42 -> V_95 )
return;
V_4 = F_53 ( sizeof( struct V_31 ) , V_82 ) ;
if ( ! V_4 )
return;
F_54 ( V_4 , sizeof( struct V_31 ) ) ;
F_55 ( V_4 ) ;
V_32 = F_3 ( V_4 ) ;
V_32 -> V_9 = V_9 ;
V_81 = F_45 ( V_4 ) ;
V_81 -> V_83 . V_84 = V_28 ;
V_81 -> V_83 . V_85 = V_96 ;
V_81 -> V_83 . V_87 = 0 ;
V_81 -> V_83 . V_88 = 0 ;
V_81 -> V_83 . V_90 = 0 ;
V_81 -> V_83 . V_91 = V_6 ;
V_81 -> V_83 . V_92 = 0 ;
V_81 -> V_93 = ( T_4 * ) & V_32 -> V_9 - F_47 ( V_4 ) ;
V_81 -> V_78 = V_78 ;
F_56 ( V_4 , F_57 ( V_4 ) - V_4 -> V_94 ) ;
F_49 ( V_4 ) ;
if ( F_50 ( V_43 , V_4 ) )
F_51 ( V_4 ) ;
}
int F_58 ( struct V_65 * V_43 , struct V_1 * V_2 , int V_34 )
{
struct V_80 * V_81 ;
struct V_3 * V_4 , * V_97 ;
struct V_30 * sin ;
struct {
struct V_98 V_83 ;
struct V_30 V_99 ;
} V_100 ;
int V_28 ;
int V_101 ;
V_28 = - V_102 ;
V_4 = F_59 ( & V_43 -> V_103 ) ;
if ( V_4 == NULL )
goto V_104;
V_101 = V_4 -> V_34 ;
if ( V_101 > V_34 ) {
V_2 -> V_21 |= V_105 ;
V_101 = V_34 ;
}
V_28 = F_60 ( V_4 , 0 , V_2 -> V_106 , V_101 ) ;
if ( V_28 )
goto V_107;
F_61 ( V_2 , V_43 , V_4 ) ;
V_81 = F_45 ( V_4 ) ;
sin = (struct V_30 * ) V_2 -> V_108 ;
if ( sin ) {
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = * ( T_5 * ) ( F_47 ( V_4 ) +
V_81 -> V_93 ) ;
sin -> V_38 = V_81 -> V_78 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
}
memcpy ( & V_100 . V_83 , & V_81 -> V_83 , sizeof( struct V_98 ) ) ;
sin = & V_100 . V_99 ;
sin -> V_35 = V_109 ;
if ( V_81 -> V_83 . V_85 == V_86 ) {
struct V_41 * V_42 = F_20 ( V_43 ) ;
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = F_3 ( V_4 ) -> V_110 ;
sin -> V_38 = 0 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
if ( V_42 -> V_45 )
F_19 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_111 , sizeof( V_100 ) , & V_100 ) ;
V_2 -> V_21 |= V_112 ;
V_28 = V_101 ;
F_36 ( & V_43 -> V_103 . V_113 ) ;
V_43 -> V_114 = 0 ;
V_97 = F_62 ( & V_43 -> V_103 ) ;
if ( V_97 != NULL ) {
V_43 -> V_114 = F_45 ( V_97 ) -> V_83 . V_84 ;
F_39 ( & V_43 -> V_103 . V_113 ) ;
V_43 -> V_115 ( V_43 ) ;
} else
F_39 ( & V_43 -> V_103 . V_113 ) ;
V_107:
F_51 ( V_4 ) ;
V_104:
return V_28 ;
}
static void F_63 ( struct V_59 * V_60 )
{
F_32 ( F_30 ( V_60 , struct V_116 , V_63 ) ) ;
}
static int F_64 ( struct V_65 * V_43 , int V_117 ,
int V_118 , char T_6 * V_119 , unsigned int V_17 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_120 = 0 , V_28 ;
if ( ( ( 1 << V_118 ) & ( ( 1 << V_11 ) | ( 1 << V_121 ) |
( 1 << V_18 ) | ( 1 << V_122 ) |
( 1 << V_23 ) | ( 1 << V_14 ) |
( 1 << V_13 ) | ( 1 << V_123 ) |
( 1 << V_124 ) | ( 1 << V_111 ) |
( 1 << V_125 ) | ( 1 << V_126 ) |
( 1 << V_127 ) | ( 1 << V_128 ) |
( 1 << V_129 ) | ( 1 << V_130 ) ) ) ||
V_118 == V_131 ||
V_118 == V_132 ||
V_118 == V_133 ||
V_118 == V_134 ) {
if ( V_17 >= sizeof( int ) ) {
if ( F_65 ( V_120 , ( int T_6 * ) V_119 ) )
return - V_135 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_136 ;
if ( F_65 ( V_136 , ( unsigned char T_6 * ) V_119 ) )
return - V_135 ;
V_120 = ( int ) V_136 ;
}
}
if ( F_66 ( V_118 ) )
return F_67 ( V_43 , V_118 , V_119 , V_17 ) ;
V_28 = 0 ;
F_68 ( V_43 ) ;
switch ( V_118 ) {
case V_137 :
{
struct V_116 * V_138 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_139;
V_28 = F_69 ( F_70 ( V_43 ) , & V_16 ,
V_119 , V_17 ) ;
if ( V_28 )
break;
V_138 = F_37 ( V_42 -> V_140 ,
F_71 ( V_43 ) ) ;
if ( V_42 -> V_141 ) {
struct V_142 * V_143 = F_72 ( V_43 ) ;
#if F_73 ( V_144 )
if ( V_43 -> V_145 == V_146 ||
( ! ( ( 1 << V_43 -> V_147 ) &
( V_148 | V_149 ) ) &&
V_42 -> V_150 != V_151 ) ) {
#endif
if ( V_138 )
V_143 -> V_152 -= V_138 -> V_16 . V_17 ;
if ( V_16 )
V_143 -> V_152 += V_16 -> V_16 . V_17 ;
V_143 -> V_153 ( V_43 , V_143 -> V_154 ) ;
#if F_73 ( V_144 )
}
#endif
}
F_40 ( V_42 -> V_140 , V_16 ) ;
if ( V_138 )
F_41 ( & V_138 -> V_63 , F_63 ) ;
break;
}
case V_11 :
if ( V_120 )
V_42 -> V_45 |= V_155 ;
else
V_42 -> V_45 &= ~ V_155 ;
break;
case V_121 :
if ( V_120 )
V_42 -> V_45 |= V_156 ;
else
V_42 -> V_45 &= ~ V_156 ;
break;
case V_122 :
if ( V_120 )
V_42 -> V_45 |= V_157 ;
else
V_42 -> V_45 &= ~ V_157 ;
break;
case V_18 :
if ( V_120 )
V_42 -> V_45 |= V_158 ;
else
V_42 -> V_45 &= ~ V_158 ;
break;
case V_23 :
if ( V_120 )
V_42 -> V_45 |= V_159 ;
else
V_42 -> V_45 &= ~ V_159 ;
break;
case V_127 :
if ( V_120 )
V_42 -> V_45 |= V_160 ;
else
V_42 -> V_45 &= ~ V_160 ;
break;
case V_134 :
if ( V_120 )
V_42 -> V_45 |= V_161 ;
else
V_42 -> V_45 &= ~ V_161 ;
break;
case V_14 :
if ( V_43 -> V_69 == V_162 ) {
V_120 &= ~ V_163 ;
V_120 |= V_42 -> V_15 & V_163 ;
}
if ( V_42 -> V_15 != V_120 ) {
V_42 -> V_15 = V_120 ;
V_43 -> V_164 = F_74 ( V_120 ) ;
F_75 ( V_43 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_139;
if ( V_120 != - 1 && ( V_120 < 0 || V_120 > 255 ) )
goto V_139;
V_42 -> V_165 = V_120 ;
break;
case V_123 :
if ( V_43 -> V_69 != V_70 ) {
V_28 = - V_166 ;
break;
}
V_42 -> V_167 = V_120 ? 1 : 0 ;
break;
case V_130 :
if ( V_43 -> V_69 != V_70 ) {
V_28 = - V_166 ;
break;
}
V_42 -> V_168 = V_120 ? 1 : 0 ;
break;
case V_124 :
if ( V_120 < V_169 || V_120 > V_170 )
goto V_139;
V_42 -> V_171 = V_120 ;
break;
case V_111 :
V_42 -> V_95 = ! ! V_120 ;
if ( ! V_120 )
F_76 ( & V_43 -> V_103 ) ;
break;
case V_131 :
if ( V_43 -> V_69 == V_162 )
goto V_139;
if ( V_17 < 1 )
goto V_139;
if ( V_120 == - 1 )
V_120 = 1 ;
if ( V_120 < 0 || V_120 > 255 )
goto V_139;
V_42 -> V_172 = V_120 ;
break;
case V_133 :
if ( V_17 < 1 )
goto V_139;
V_42 -> V_173 = ! ! V_120 ;
break;
case V_174 :
{
struct V_175 V_176 ;
struct V_177 * V_178 = NULL ;
if ( V_43 -> V_69 == V_162 )
goto V_139;
if ( V_17 < sizeof( struct V_179 ) )
goto V_139;
V_28 = - V_135 ;
if ( V_17 >= sizeof( struct V_175 ) ) {
if ( F_77 ( & V_176 , V_119 , sizeof( V_176 ) ) )
break;
} else {
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
if ( V_17 >= sizeof( struct V_179 ) &&
F_77 ( & V_176 . V_180 , V_119 ,
sizeof( struct V_179 ) ) )
break;
}
if ( ! V_176 . V_181 ) {
if ( V_176 . V_180 . V_8 == F_78 ( V_182 ) ) {
V_42 -> V_183 = 0 ;
V_42 -> V_184 = 0 ;
V_28 = 0 ;
break;
}
V_178 = F_79 ( F_70 ( V_43 ) , V_176 . V_180 . V_8 ) ;
if ( V_178 )
V_176 . V_181 = V_178 -> V_185 ;
} else
V_178 = F_80 ( F_70 ( V_43 ) , V_176 . V_181 ) ;
V_28 = - V_186 ;
if ( ! V_178 )
break;
F_81 ( V_178 ) ;
V_28 = - V_51 ;
if ( V_43 -> V_187 &&
V_176 . V_181 != V_43 -> V_187 )
break;
V_42 -> V_183 = V_176 . V_181 ;
V_42 -> V_184 = V_176 . V_180 . V_8 ;
V_28 = 0 ;
break;
}
case V_188 :
case V_189 :
{
struct V_175 V_176 ;
V_28 = - V_190 ;
if ( F_20 ( V_43 ) -> V_141 )
break;
if ( V_17 < sizeof( struct V_191 ) )
goto V_139;
V_28 = - V_135 ;
if ( V_17 >= sizeof( struct V_175 ) ) {
if ( F_77 ( & V_176 , V_119 , sizeof( V_176 ) ) )
break;
} else {
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
if ( F_77 ( & V_176 , V_119 , sizeof( struct V_191 ) ) )
break;
}
if ( V_118 == V_188 )
V_28 = F_82 ( V_43 , & V_176 ) ;
else
V_28 = F_83 ( V_43 , & V_176 ) ;
break;
}
case V_192 :
{
struct V_193 * V_194 ;
if ( V_17 < F_84 ( 0 ) )
goto V_139;
if ( V_17 > V_195 ) {
V_28 = - V_77 ;
break;
}
V_194 = F_35 ( V_17 , V_73 ) ;
if ( ! V_194 ) {
V_28 = - V_77 ;
break;
}
V_28 = - V_135 ;
if ( F_77 ( V_194 , V_119 , V_17 ) ) {
F_32 ( V_194 ) ;
break;
}
if ( V_194 -> V_196 >= 0x3ffffffcU ||
V_194 -> V_196 > V_197 ) {
F_32 ( V_194 ) ;
V_28 = - V_77 ;
break;
}
if ( F_84 ( V_194 -> V_196 ) > V_17 ) {
F_32 ( V_194 ) ;
V_28 = - V_51 ;
break;
}
V_28 = F_85 ( V_43 , V_194 , 0 ) ;
F_32 ( V_194 ) ;
break;
}
case V_198 :
case V_199 :
case V_200 :
case V_201 :
{
struct V_202 V_203 ;
int V_204 , V_205 ;
if ( V_17 != sizeof( struct V_202 ) )
goto V_139;
if ( F_77 ( & V_203 , V_119 , sizeof( V_203 ) ) ) {
V_28 = - V_135 ;
break;
}
if ( V_118 == V_198 ) {
V_204 = V_206 ;
V_205 = 1 ;
} else if ( V_118 == V_199 ) {
V_204 = V_206 ;
V_205 = 0 ;
} else if ( V_118 == V_200 ) {
struct V_175 V_176 ;
V_176 . V_207 . V_8 = V_203 . V_207 ;
V_176 . V_180 . V_8 = V_203 . V_208 ;
V_176 . V_181 = 0 ;
V_28 = F_82 ( V_43 , & V_176 ) ;
if ( V_28 && V_28 != - V_76 )
break;
V_204 = V_209 ;
V_205 = 1 ;
} else {
V_204 = V_209 ;
V_205 = 0 ;
}
V_28 = F_86 ( V_205 , V_204 , V_43 , & V_203 , 0 ) ;
break;
}
case V_210 :
case V_211 :
{
struct V_212 V_213 ;
struct V_30 * V_214 ;
struct V_175 V_176 ;
if ( V_17 < sizeof( struct V_212 ) )
goto V_139;
V_28 = - V_135 ;
if ( F_77 ( & V_213 , V_119 , sizeof( V_213 ) ) )
break;
V_214 = (struct V_30 * ) & V_213 . V_215 ;
if ( V_214 -> V_35 != V_36 )
goto V_139;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_207 = V_214 -> V_37 ;
V_176 . V_181 = V_213 . V_216 ;
if ( V_118 == V_210 )
V_28 = F_82 ( V_43 , & V_176 ) ;
else
V_28 = F_83 ( V_43 , & V_176 ) ;
break;
}
case V_217 :
case V_218 :
case V_219 :
case V_220 :
{
struct V_221 V_222 ;
struct V_202 V_203 ;
struct V_30 * V_214 ;
int V_204 , V_205 ;
if ( V_17 != sizeof( struct V_221 ) )
goto V_139;
if ( F_77 ( & V_222 , V_119 , sizeof( V_222 ) ) ) {
V_28 = - V_135 ;
break;
}
if ( V_222 . V_223 . V_224 != V_36 ||
V_222 . V_225 . V_224 != V_36 ) {
V_28 = - V_186 ;
break;
}
V_214 = (struct V_30 * ) & V_222 . V_223 ;
V_203 . V_207 = V_214 -> V_37 . V_8 ;
V_214 = (struct V_30 * ) & V_222 . V_225 ;
V_203 . V_226 = V_214 -> V_37 . V_8 ;
V_203 . V_208 = 0 ;
if ( V_118 == V_219 ) {
V_204 = V_206 ;
V_205 = 1 ;
} else if ( V_118 == V_220 ) {
V_204 = V_206 ;
V_205 = 0 ;
} else if ( V_118 == V_217 ) {
struct V_175 V_176 ;
V_214 = (struct V_30 * ) & V_222 . V_223 ;
V_176 . V_207 = V_214 -> V_37 ;
V_176 . V_180 . V_8 = 0 ;
V_176 . V_181 = V_222 . V_227 ;
V_28 = F_82 ( V_43 , & V_176 ) ;
if ( V_28 && V_28 != - V_76 )
break;
V_222 . V_227 = V_176 . V_181 ;
V_204 = V_209 ;
V_205 = 1 ;
} else {
V_204 = V_209 ;
V_205 = 0 ;
}
V_28 = F_86 ( V_205 , V_204 , V_43 , & V_203 ,
V_222 . V_227 ) ;
break;
}
case V_228 :
{
struct V_30 * V_214 ;
struct V_193 * V_194 = NULL ;
struct V_229 * V_230 = NULL ;
int V_231 , V_232 , V_185 ;
if ( V_17 < F_87 ( 0 ) )
goto V_139;
if ( V_17 > V_195 ) {
V_28 = - V_77 ;
break;
}
V_230 = F_35 ( V_17 , V_73 ) ;
if ( ! V_230 ) {
V_28 = - V_77 ;
break;
}
V_28 = - V_135 ;
if ( F_77 ( V_230 , V_119 , V_17 ) )
goto V_233;
if ( V_230 -> V_234 >= 0x1ffffff ||
V_230 -> V_234 > V_197 ) {
V_28 = - V_77 ;
goto V_233;
}
if ( F_87 ( V_230 -> V_234 ) > V_17 ) {
V_28 = - V_51 ;
goto V_233;
}
V_231 = F_84 ( V_230 -> V_234 ) ;
V_194 = F_35 ( V_231 , V_73 ) ;
if ( ! V_194 ) {
V_28 = - V_77 ;
goto V_233;
}
V_185 = V_230 -> V_235 ;
V_214 = (struct V_30 * ) & V_230 -> V_236 ;
if ( V_214 -> V_35 != V_36 ) {
V_28 = - V_186 ;
goto V_233;
}
V_194 -> V_237 = V_214 -> V_37 . V_8 ;
V_194 -> V_238 = 0 ;
V_194 -> V_239 = V_230 -> V_240 ;
V_194 -> V_196 = V_230 -> V_234 ;
V_28 = - V_186 ;
for ( V_232 = 0 ; V_232 < V_230 -> V_234 ; ++ V_232 ) {
V_214 = (struct V_30 * ) & V_230 -> V_241 [ V_232 ] ;
if ( V_214 -> V_35 != V_36 )
goto V_233;
V_194 -> V_242 [ V_232 ] = V_214 -> V_37 . V_8 ;
}
F_32 ( V_230 ) ;
V_230 = NULL ;
V_28 = F_85 ( V_43 , V_194 , V_185 ) ;
V_233:
F_32 ( V_194 ) ;
F_32 ( V_230 ) ;
break;
}
case V_132 :
if ( V_17 < 1 )
goto V_139;
if ( V_120 != 0 && V_120 != 1 )
goto V_139;
V_42 -> V_243 = V_120 ;
break;
case V_125 :
V_28 = F_33 ( V_43 , V_120 ? 1 : 0 , NULL ) ;
break;
case V_126 :
if ( V_17 < 1 )
goto V_139;
V_42 -> V_244 = ! ! V_120 ;
break;
case V_245 :
case V_246 :
V_28 = - V_247 ;
if ( ! F_88 ( V_248 ) )
break;
V_28 = F_89 ( V_43 , V_118 , V_119 , V_17 ) ;
break;
case V_128 :
if ( ! ! V_120 && ! F_88 ( V_249 ) && ! F_88 ( V_248 ) ) {
V_28 = - V_247 ;
break;
}
if ( V_17 < 1 )
goto V_139;
V_42 -> V_250 = ! ! V_120 ;
break;
case V_129 :
if ( V_17 < 1 )
goto V_139;
if ( V_120 < 0 || V_120 > 255 )
goto V_139;
V_42 -> V_251 = V_120 ;
break;
default:
V_28 = - V_166 ;
break;
}
F_90 ( V_43 ) ;
return V_28 ;
V_139:
F_90 ( V_43 ) ;
return - V_51 ;
}
void F_91 ( struct V_3 * V_4 )
{
struct V_5 * V_252 = F_2 ( V_4 ) ;
const struct V_253 * V_254 = F_92 ( V_4 ) ;
if ( V_254 ) {
V_252 -> V_56 = V_254 -> V_255 ;
V_252 -> V_58 . V_8 = V_254 -> V_256 ;
} else {
V_252 -> V_56 = 0 ;
V_252 -> V_58 . V_8 = 0 ;
}
F_93 ( V_4 ) ;
}
int F_94 ( struct V_65 * V_43 , int V_117 ,
int V_118 , char T_6 * V_119 , unsigned int V_17 )
{
int V_28 ;
if ( V_117 != V_10 )
return - V_166 ;
V_28 = F_64 ( V_43 , V_117 , V_118 , V_119 , V_17 ) ;
#ifdef F_95
if ( V_28 == - V_166 && V_118 != V_123 &&
V_118 != V_245 &&
V_118 != V_246 &&
! F_66 ( V_118 ) ) {
F_68 ( V_43 ) ;
V_28 = F_96 ( V_43 , V_146 , V_118 , V_119 , V_17 ) ;
F_90 ( V_43 ) ;
}
#endif
return V_28 ;
}
int F_97 ( struct V_65 * V_43 , int V_117 , int V_118 ,
char T_6 * V_119 , unsigned int V_17 )
{
int V_28 ;
if ( V_117 != V_10 )
return - V_166 ;
if ( V_118 >= V_210 && V_118 <= V_228 )
return F_98 ( V_43 , V_117 , V_118 , V_119 , V_17 ,
F_94 ) ;
V_28 = F_64 ( V_43 , V_117 , V_118 , V_119 , V_17 ) ;
#ifdef F_95
if ( V_28 == - V_166 && V_118 != V_123 &&
V_118 != V_245 &&
V_118 != V_246 &&
! F_66 ( V_118 ) ) {
F_68 ( V_43 ) ;
V_28 = F_99 ( V_43 , V_146 , V_118 ,
V_119 , V_17 ) ;
F_90 ( V_43 ) ;
}
#endif
return V_28 ;
}
static int F_100 ( struct V_65 * V_43 , int V_117 , int V_118 ,
char T_6 * V_119 , int T_6 * V_17 , unsigned V_44 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_120 ;
int V_34 ;
if ( V_117 != V_10 )
return - V_257 ;
if ( F_66 ( V_118 ) )
return F_101 ( V_43 , V_118 , V_119 , V_17 ) ;
if ( F_65 ( V_34 , V_17 ) )
return - V_135 ;
if ( V_34 < 0 )
return - V_51 ;
F_68 ( V_43 ) ;
switch ( V_118 ) {
case V_137 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_116 * V_140 ;
V_140 = F_37 ( V_42 -> V_140 ,
F_71 ( V_43 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_140 )
memcpy ( V_19 , & V_140 -> V_16 ,
sizeof( struct V_20 ) +
V_140 -> V_16 . V_17 ) ;
F_90 ( V_43 ) ;
if ( V_16 -> V_17 == 0 )
return F_102 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_34 = F_103 (unsigned int, len, opt->optlen) ;
if ( F_102 ( V_34 , V_17 ) )
return - V_135 ;
if ( F_104 ( V_119 , V_16 -> V_24 , V_34 ) )
return - V_135 ;
return 0 ;
}
case V_11 :
V_120 = ( V_42 -> V_45 & V_155 ) != 0 ;
break;
case V_121 :
V_120 = ( V_42 -> V_45 & V_156 ) != 0 ;
break;
case V_122 :
V_120 = ( V_42 -> V_45 & V_157 ) != 0 ;
break;
case V_18 :
V_120 = ( V_42 -> V_45 & V_158 ) != 0 ;
break;
case V_23 :
V_120 = ( V_42 -> V_45 & V_159 ) != 0 ;
break;
case V_127 :
V_120 = ( V_42 -> V_45 & V_160 ) != 0 ;
break;
case V_134 :
V_120 = ( V_42 -> V_45 & V_161 ) != 0 ;
break;
case V_14 :
V_120 = V_42 -> V_15 ;
break;
case V_13 :
V_120 = ( V_42 -> V_165 == - 1 ?
V_258 :
V_42 -> V_165 ) ;
break;
case V_123 :
V_120 = V_42 -> V_167 ;
break;
case V_130 :
V_120 = V_42 -> V_168 ;
break;
case V_124 :
V_120 = V_42 -> V_171 ;
break;
case V_259 :
{
struct V_260 * V_261 ;
V_120 = 0 ;
V_261 = F_105 ( V_43 ) ;
if ( V_261 ) {
V_120 = F_106 ( V_261 ) ;
F_107 ( V_261 ) ;
}
if ( ! V_120 ) {
F_90 ( V_43 ) ;
return - V_262 ;
}
break;
}
case V_111 :
V_120 = V_42 -> V_95 ;
break;
case V_131 :
V_120 = V_42 -> V_172 ;
break;
case V_133 :
V_120 = V_42 -> V_173 ;
break;
case V_174 :
{
struct V_179 V_57 ;
V_34 = F_103 (unsigned int, len, sizeof(struct in_addr)) ;
V_57 . V_8 = V_42 -> V_184 ;
F_90 ( V_43 ) ;
if ( F_102 ( V_34 , V_17 ) )
return - V_135 ;
if ( F_104 ( V_119 , & V_57 , V_34 ) )
return - V_135 ;
return 0 ;
}
case V_192 :
{
struct V_193 V_194 ;
int V_28 ;
if ( V_34 < F_84 ( 0 ) ) {
F_90 ( V_43 ) ;
return - V_51 ;
}
if ( F_77 ( & V_194 , V_119 , F_84 ( 0 ) ) ) {
F_90 ( V_43 ) ;
return - V_135 ;
}
V_28 = F_108 ( V_43 , & V_194 ,
(struct V_193 T_6 * ) V_119 , V_17 ) ;
F_90 ( V_43 ) ;
return V_28 ;
}
case V_228 :
{
struct V_229 V_230 ;
int V_28 ;
if ( V_34 < F_87 ( 0 ) ) {
F_90 ( V_43 ) ;
return - V_51 ;
}
if ( F_77 ( & V_230 , V_119 , F_87 ( 0 ) ) ) {
F_90 ( V_43 ) ;
return - V_135 ;
}
V_28 = F_109 ( V_43 , & V_230 ,
(struct V_229 T_6 * ) V_119 ,
V_17 ) ;
F_90 ( V_43 ) ;
return V_28 ;
}
case V_132 :
V_120 = V_42 -> V_243 ;
break;
case V_263 :
{
struct V_1 V_2 ;
F_90 ( V_43 ) ;
if ( V_43 -> V_69 != V_162 )
return - V_166 ;
V_2 . V_264 = V_119 ;
V_2 . V_265 = V_34 ;
V_2 . V_21 = V_44 ;
if ( V_42 -> V_45 & V_155 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_42 -> V_266 ;
V_6 . V_58 . V_8 = V_42 -> V_266 ;
V_6 . V_56 = V_42 -> V_183 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_42 -> V_45 & V_156 ) {
int V_267 = V_42 -> V_172 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_267 ) , & V_267 ) ;
}
V_34 -= V_2 . V_265 ;
return F_102 ( V_34 , V_17 ) ;
}
case V_126 :
V_120 = V_42 -> V_244 ;
break;
case V_128 :
V_120 = V_42 -> V_250 ;
break;
case V_129 :
V_120 = V_42 -> V_251 ;
break;
default:
F_90 ( V_43 ) ;
return - V_166 ;
}
F_90 ( V_43 ) ;
if ( V_34 < sizeof( int ) && V_34 > 0 && V_120 >= 0 && V_120 <= 255 ) {
unsigned char V_136 = ( unsigned char ) V_120 ;
V_34 = 1 ;
if ( F_102 ( V_34 , V_17 ) )
return - V_135 ;
if ( F_104 ( V_119 , & V_136 , 1 ) )
return - V_135 ;
} else {
V_34 = F_103 (unsigned int, sizeof(int), len) ;
if ( F_102 ( V_34 , V_17 ) )
return - V_135 ;
if ( F_104 ( V_119 , & V_120 , V_34 ) )
return - V_135 ;
}
return 0 ;
}
int F_110 ( struct V_65 * V_43 , int V_117 ,
int V_118 , char T_6 * V_119 , int T_6 * V_17 )
{
int V_28 ;
V_28 = F_100 ( V_43 , V_117 , V_118 , V_119 , V_17 , 0 ) ;
#ifdef F_95
if ( V_28 == - V_166 && V_118 != V_263 &&
! F_66 ( V_118 ) ) {
int V_34 ;
if ( F_65 ( V_34 , V_17 ) )
return - V_135 ;
F_68 ( V_43 ) ;
V_28 = F_111 ( V_43 , V_146 , V_118 , V_119 ,
& V_34 ) ;
F_90 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_102 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
int F_112 ( struct V_65 * V_43 , int V_117 , int V_118 ,
char T_6 * V_119 , int T_6 * V_17 )
{
int V_28 ;
if ( V_118 == V_228 )
return F_113 ( V_43 , V_117 , V_118 , V_119 , V_17 ,
F_110 ) ;
V_28 = F_100 ( V_43 , V_117 , V_118 , V_119 , V_17 ,
V_268 ) ;
#ifdef F_95
if ( V_28 == - V_166 && V_118 != V_263 &&
! F_66 ( V_118 ) ) {
int V_34 ;
if ( F_65 ( V_34 , V_17 ) )
return - V_135 ;
F_68 ( V_43 ) ;
V_28 = F_114 ( V_43 , V_146 , V_118 , V_119 , & V_34 ) ;
F_90 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_102 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
