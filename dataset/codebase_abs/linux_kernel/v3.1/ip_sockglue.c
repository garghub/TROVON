static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
V_6 . V_9 . V_10 = F_3 ( V_4 ) -> V_11 ;
if ( V_8 ) {
V_6 . V_12 = V_8 -> V_13 ;
V_6 . V_14 . V_10 = V_8 -> V_15 ;
} else {
V_6 . V_12 = 0 ;
V_6 . V_14 . V_10 = 0 ;
}
F_4 ( V_2 , V_16 , V_17 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_18 = F_3 ( V_4 ) -> V_18 ;
F_4 ( V_2 , V_16 , V_19 , sizeof( int ) , & V_18 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( V_2 , V_16 , V_20 , 1 , & F_3 ( V_4 ) -> V_21 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_8 ( V_4 ) -> V_22 . V_23 == 0 )
return;
F_4 ( V_2 , V_16 , V_24 , F_8 ( V_4 ) -> V_22 . V_23 ,
F_3 ( V_4 ) + 1 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_25 [ sizeof( struct V_26 ) + 40 ] ;
struct V_26 * V_22 = (struct V_26 * ) V_25 ;
if ( F_8 ( V_4 ) -> V_22 . V_23 == 0 )
return;
if ( F_10 ( V_22 , V_4 ) ) {
V_2 -> V_27 |= V_28 ;
return;
}
F_11 ( V_22 ) ;
F_4 ( V_2 , V_16 , V_29 , V_22 -> V_23 , V_22 -> V_30 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_31 ;
T_1 V_32 , V_33 ;
int V_34 ;
V_34 = F_13 ( NULL , V_4 , & V_33 ) ;
if ( V_34 )
return;
V_34 = F_14 ( V_33 , & V_31 , & V_32 ) ;
if ( V_34 )
return;
F_4 ( V_2 , V_16 , V_35 , V_32 , V_31 ) ;
F_15 ( V_31 , V_32 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 sin ;
const struct V_37 * V_38 = F_3 ( V_4 ) ;
T_2 * V_39 = ( T_2 * ) F_17 ( V_4 ) ;
if ( F_18 ( V_4 ) + 4 > V_4 -> V_40 )
return;
sin . V_41 = V_42 ;
sin . V_43 . V_10 = V_38 -> V_11 ;
sin . V_44 = V_39 [ 1 ] ;
memset ( sin . V_45 , 0 , sizeof( sin . V_45 ) ) ;
F_4 ( V_2 , V_16 , V_46 , sizeof( sin ) , & sin ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_47 * V_48 = F_20 ( V_4 -> V_49 ) ;
unsigned V_50 = V_48 -> V_51 ;
if ( V_50 & 1 )
F_1 ( V_2 , V_4 ) ;
if ( ( V_50 >>= 1 ) == 0 )
return;
if ( V_50 & 1 )
F_5 ( V_2 , V_4 ) ;
if ( ( V_50 >>= 1 ) == 0 )
return;
if ( V_50 & 1 )
F_6 ( V_2 , V_4 ) ;
if ( ( V_50 >>= 1 ) == 0 )
return;
if ( V_50 & 1 )
F_7 ( V_2 , V_4 ) ;
if ( ( V_50 >>= 1 ) == 0 )
return;
if ( V_50 & 1 )
F_9 ( V_2 , V_4 ) ;
if ( ( V_50 >>= 1 ) == 0 )
return;
if ( V_50 & 1 )
F_12 ( V_2 , V_4 ) ;
if ( ( V_50 >>= 1 ) == 0 )
return;
if ( V_50 & 1 )
F_16 ( V_2 , V_4 ) ;
}
int F_21 ( struct V_52 * V_52 , struct V_1 * V_2 , struct V_53 * V_54 )
{
int V_34 ;
struct V_55 * V_56 ;
for ( V_56 = F_22 ( V_2 ) ; V_56 ; V_56 = F_23 ( V_2 , V_56 ) ) {
if ( ! F_24 ( V_2 , V_56 ) )
return - V_57 ;
if ( V_56 -> V_58 != V_16 )
continue;
switch ( V_56 -> V_59 ) {
case V_29 :
V_34 = V_56 -> V_60 - F_25 ( sizeof( struct V_55 ) ) ;
V_34 = F_26 ( V_52 , & V_54 -> V_22 , F_27 ( V_56 ) ,
V_34 < 40 ? V_34 : 40 ) ;
if ( V_34 )
return V_34 ;
break;
case V_17 :
{
struct V_5 * V_6 ;
if ( V_56 -> V_60 != F_28 ( sizeof( struct V_5 ) ) )
return - V_57 ;
V_6 = (struct V_5 * ) F_27 ( V_56 ) ;
V_54 -> V_61 = V_6 -> V_12 ;
V_54 -> V_62 = V_6 -> V_14 . V_10 ;
break;
}
default:
return - V_57 ;
}
}
return 0 ;
}
static void F_29 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_30 ( V_64 , struct V_65 , V_67 ) ;
F_31 ( V_66 -> V_68 ) ;
F_32 ( V_66 ) ;
}
int F_33 ( struct V_69 * V_49 , unsigned char V_70 ,
void (* F_34)( struct V_69 * ) )
{
struct V_65 * V_66 , * V_71 ;
struct V_65 T_3 * * V_72 ;
if ( V_49 -> V_73 != V_74 || F_20 ( V_49 ) -> V_75 == V_76 )
return - V_57 ;
V_71 = V_70 ? F_35 ( sizeof( * V_71 ) , V_77 ) : NULL ;
F_36 ( & V_78 ) ;
for ( V_72 = & V_65 ;
( V_66 = F_37 ( * V_72 ,
F_38 ( & V_78 ) ) ) != NULL ;
V_72 = & V_66 -> V_79 ) {
if ( V_66 -> V_49 == V_49 ) {
if ( V_70 ) {
F_39 ( & V_78 ) ;
F_32 ( V_71 ) ;
return - V_80 ;
}
V_66 -> V_49 = NULL ;
F_40 ( * V_72 , V_66 -> V_79 ) ;
F_39 ( & V_78 ) ;
if ( V_66 -> F_34 )
V_66 -> F_34 ( V_49 ) ;
V_66 -> V_68 = V_49 ;
F_41 ( & V_66 -> V_67 , F_29 ) ;
return 0 ;
}
}
if ( V_71 == NULL ) {
F_39 ( & V_78 ) ;
return - V_81 ;
}
V_71 -> V_49 = V_49 ;
V_71 -> F_34 = F_34 ;
V_71 -> V_79 = V_66 ;
F_40 ( * V_72 , V_71 ) ;
F_42 ( V_49 ) ;
F_39 ( & V_78 ) ;
return 0 ;
}
void F_43 ( struct V_69 * V_49 , struct V_3 * V_4 , int V_34 ,
T_2 V_82 , T_1 V_6 , T_4 * V_83 )
{
struct V_84 * V_85 ;
V_4 = F_44 ( V_4 , V_86 ) ;
if ( ! V_4 )
return;
V_85 = F_45 ( V_4 ) ;
V_85 -> V_87 . V_88 = V_34 ;
V_85 -> V_87 . V_89 = V_90 ;
V_85 -> V_87 . V_91 = F_46 ( V_4 ) -> type ;
V_85 -> V_87 . V_92 = F_46 ( V_4 ) -> V_93 ;
V_85 -> V_87 . V_94 = 0 ;
V_85 -> V_87 . V_95 = V_6 ;
V_85 -> V_87 . V_96 = 0 ;
V_85 -> V_97 = ( T_4 * ) & ( ( (struct V_37 * ) ( F_46 ( V_4 ) + 1 ) ) -> V_11 ) -
F_47 ( V_4 ) ;
V_85 -> V_82 = V_82 ;
if ( F_48 ( V_4 , V_83 - V_4 -> V_98 ) != NULL ) {
F_49 ( V_4 ) ;
if ( F_50 ( V_49 , V_4 ) == 0 )
return;
}
F_51 ( V_4 ) ;
}
void F_52 ( struct V_69 * V_49 , int V_34 , T_5 V_11 , T_2 V_82 , T_1 V_6 )
{
struct V_47 * V_48 = F_20 ( V_49 ) ;
struct V_84 * V_85 ;
struct V_37 * V_38 ;
struct V_3 * V_4 ;
if ( ! V_48 -> V_99 )
return;
V_4 = F_53 ( sizeof( struct V_37 ) , V_86 ) ;
if ( ! V_4 )
return;
F_54 ( V_4 , sizeof( struct V_37 ) ) ;
F_55 ( V_4 ) ;
V_38 = F_3 ( V_4 ) ;
V_38 -> V_11 = V_11 ;
V_85 = F_45 ( V_4 ) ;
V_85 -> V_87 . V_88 = V_34 ;
V_85 -> V_87 . V_89 = V_100 ;
V_85 -> V_87 . V_91 = 0 ;
V_85 -> V_87 . V_92 = 0 ;
V_85 -> V_87 . V_94 = 0 ;
V_85 -> V_87 . V_95 = V_6 ;
V_85 -> V_87 . V_96 = 0 ;
V_85 -> V_97 = ( T_4 * ) & V_38 -> V_11 - F_47 ( V_4 ) ;
V_85 -> V_82 = V_82 ;
F_56 ( V_4 , F_57 ( V_4 ) - V_4 -> V_98 ) ;
F_49 ( V_4 ) ;
if ( F_50 ( V_49 , V_4 ) )
F_51 ( V_4 ) ;
}
int F_58 ( struct V_69 * V_49 , struct V_1 * V_2 , int V_40 )
{
struct V_84 * V_85 ;
struct V_3 * V_4 , * V_101 ;
struct V_36 * sin ;
struct {
struct V_102 V_87 ;
struct V_36 V_103 ;
} V_104 ;
int V_34 ;
int V_105 ;
V_34 = - V_106 ;
V_4 = F_59 ( & V_49 -> V_107 ) ;
if ( V_4 == NULL )
goto V_108;
V_105 = V_4 -> V_40 ;
if ( V_105 > V_40 ) {
V_2 -> V_27 |= V_109 ;
V_105 = V_40 ;
}
V_34 = F_60 ( V_4 , 0 , V_2 -> V_110 , V_105 ) ;
if ( V_34 )
goto V_111;
F_61 ( V_2 , V_49 , V_4 ) ;
V_85 = F_45 ( V_4 ) ;
sin = (struct V_36 * ) V_2 -> V_112 ;
if ( sin ) {
sin -> V_41 = V_42 ;
sin -> V_43 . V_10 = * ( T_5 * ) ( F_47 ( V_4 ) +
V_85 -> V_97 ) ;
sin -> V_44 = V_85 -> V_82 ;
memset ( & sin -> V_45 , 0 , sizeof( sin -> V_45 ) ) ;
}
memcpy ( & V_104 . V_87 , & V_85 -> V_87 , sizeof( struct V_102 ) ) ;
sin = & V_104 . V_103 ;
sin -> V_41 = V_113 ;
if ( V_85 -> V_87 . V_89 == V_90 ) {
struct V_47 * V_48 = F_20 ( V_49 ) ;
sin -> V_41 = V_42 ;
sin -> V_43 . V_10 = F_3 ( V_4 ) -> V_114 ;
sin -> V_44 = 0 ;
memset ( & sin -> V_45 , 0 , sizeof( sin -> V_45 ) ) ;
if ( V_48 -> V_51 )
F_19 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_16 , V_115 , sizeof( V_104 ) , & V_104 ) ;
V_2 -> V_27 |= V_116 ;
V_34 = V_105 ;
F_36 ( & V_49 -> V_107 . V_117 ) ;
V_49 -> V_118 = 0 ;
V_101 = F_62 ( & V_49 -> V_107 ) ;
if ( V_101 != NULL ) {
V_49 -> V_118 = F_45 ( V_101 ) -> V_87 . V_88 ;
F_39 ( & V_49 -> V_107 . V_117 ) ;
V_49 -> V_119 ( V_49 ) ;
} else
F_39 ( & V_49 -> V_107 . V_117 ) ;
V_111:
F_51 ( V_4 ) ;
V_108:
return V_34 ;
}
static void F_63 ( struct V_63 * V_64 )
{
F_32 ( F_30 ( V_64 , struct V_120 , V_67 ) ) ;
}
static int F_64 ( struct V_69 * V_49 , int V_121 ,
int V_122 , char T_6 * V_123 , unsigned int V_23 )
{
struct V_47 * V_48 = F_20 ( V_49 ) ;
int V_124 = 0 , V_34 ;
if ( ( ( 1 << V_122 ) & ( ( 1 << V_17 ) | ( 1 << V_125 ) |
( 1 << V_24 ) | ( 1 << V_126 ) |
( 1 << V_29 ) | ( 1 << V_20 ) |
( 1 << V_19 ) | ( 1 << V_127 ) |
( 1 << V_128 ) | ( 1 << V_115 ) |
( 1 << V_129 ) | ( 1 << V_130 ) |
( 1 << V_131 ) | ( 1 << V_132 ) |
( 1 << V_133 ) | ( 1 << V_134 ) ) ) ||
V_122 == V_135 ||
V_122 == V_136 ||
V_122 == V_137 ||
V_122 == V_138 ) {
if ( V_23 >= sizeof( int ) ) {
if ( F_65 ( V_124 , ( int T_6 * ) V_123 ) )
return - V_139 ;
} else if ( V_23 >= sizeof( char ) ) {
unsigned char V_140 ;
if ( F_65 ( V_140 , ( unsigned char T_6 * ) V_123 ) )
return - V_139 ;
V_124 = ( int ) V_140 ;
}
}
if ( F_66 ( V_122 ) )
return F_67 ( V_49 , V_122 , V_123 , V_23 ) ;
V_34 = 0 ;
F_68 ( V_49 ) ;
switch ( V_122 ) {
case V_141 :
{
struct V_120 * V_142 , * V_22 = NULL ;
if ( V_23 > 40 )
goto V_143;
V_34 = F_69 ( F_70 ( V_49 ) , & V_22 ,
V_123 , V_23 ) ;
if ( V_34 )
break;
V_142 = F_37 ( V_48 -> V_144 ,
F_71 ( V_49 ) ) ;
if ( V_48 -> V_145 ) {
struct V_146 * V_147 = F_72 ( V_49 ) ;
#if F_73 ( V_148 ) || F_73 ( V_149 )
if ( V_49 -> V_150 == V_151 ||
( ! ( ( 1 << V_49 -> V_152 ) &
( V_153 | V_154 ) ) &&
V_48 -> V_155 != V_156 ) ) {
#endif
if ( V_142 )
V_147 -> V_157 -= V_142 -> V_22 . V_23 ;
if ( V_22 )
V_147 -> V_157 += V_22 -> V_22 . V_23 ;
V_147 -> V_158 ( V_49 , V_147 -> V_159 ) ;
#if F_73 ( V_148 ) || F_73 ( V_149 )
}
#endif
}
F_40 ( V_48 -> V_144 , V_22 ) ;
if ( V_142 )
F_41 ( & V_142 -> V_67 , F_63 ) ;
break;
}
case V_17 :
if ( V_124 )
V_48 -> V_51 |= V_160 ;
else
V_48 -> V_51 &= ~ V_160 ;
break;
case V_125 :
if ( V_124 )
V_48 -> V_51 |= V_161 ;
else
V_48 -> V_51 &= ~ V_161 ;
break;
case V_126 :
if ( V_124 )
V_48 -> V_51 |= V_162 ;
else
V_48 -> V_51 &= ~ V_162 ;
break;
case V_24 :
if ( V_124 )
V_48 -> V_51 |= V_163 ;
else
V_48 -> V_51 &= ~ V_163 ;
break;
case V_29 :
if ( V_124 )
V_48 -> V_51 |= V_164 ;
else
V_48 -> V_51 &= ~ V_164 ;
break;
case V_131 :
if ( V_124 )
V_48 -> V_51 |= V_165 ;
else
V_48 -> V_51 &= ~ V_165 ;
break;
case V_138 :
if ( V_124 )
V_48 -> V_51 |= V_166 ;
else
V_48 -> V_51 &= ~ V_166 ;
break;
case V_20 :
if ( V_49 -> V_73 == V_167 ) {
V_124 &= ~ 3 ;
V_124 |= V_48 -> V_21 & 3 ;
}
if ( V_48 -> V_21 != V_124 ) {
V_48 -> V_21 = V_124 ;
V_49 -> V_168 = F_74 ( V_124 ) ;
F_75 ( V_49 ) ;
}
break;
case V_19 :
if ( V_23 < 1 )
goto V_143;
if ( V_124 != - 1 && ( V_124 < 0 || V_124 > 255 ) )
goto V_143;
V_48 -> V_169 = V_124 ;
break;
case V_127 :
if ( V_49 -> V_73 != V_74 ) {
V_34 = - V_170 ;
break;
}
V_48 -> V_171 = V_124 ? 1 : 0 ;
break;
case V_134 :
if ( V_49 -> V_73 != V_74 ) {
V_34 = - V_170 ;
break;
}
V_48 -> V_172 = V_124 ? 1 : 0 ;
break;
case V_128 :
if ( V_124 < V_173 || V_124 > V_174 )
goto V_143;
V_48 -> V_175 = V_124 ;
break;
case V_115 :
V_48 -> V_99 = ! ! V_124 ;
if ( ! V_124 )
F_76 ( & V_49 -> V_107 ) ;
break;
case V_135 :
if ( V_49 -> V_73 == V_167 )
goto V_143;
if ( V_23 < 1 )
goto V_143;
if ( V_124 == - 1 )
V_124 = 1 ;
if ( V_124 < 0 || V_124 > 255 )
goto V_143;
V_48 -> V_176 = V_124 ;
break;
case V_137 :
if ( V_23 < 1 )
goto V_143;
V_48 -> V_177 = ! ! V_124 ;
break;
case V_178 :
{
struct V_179 V_180 ;
struct V_181 * V_182 = NULL ;
if ( V_49 -> V_73 == V_167 )
goto V_143;
if ( V_23 < sizeof( struct V_183 ) )
goto V_143;
V_34 = - V_139 ;
if ( V_23 >= sizeof( struct V_179 ) ) {
if ( F_77 ( & V_180 , V_123 , sizeof( V_180 ) ) )
break;
} else {
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
if ( V_23 >= sizeof( struct V_183 ) &&
F_77 ( & V_180 . V_184 , V_123 ,
sizeof( struct V_183 ) ) )
break;
}
if ( ! V_180 . V_185 ) {
if ( V_180 . V_184 . V_10 == F_78 ( V_186 ) ) {
V_48 -> V_187 = 0 ;
V_48 -> V_188 = 0 ;
V_34 = 0 ;
break;
}
V_182 = F_79 ( F_70 ( V_49 ) , V_180 . V_184 . V_10 ) ;
if ( V_182 )
V_180 . V_185 = V_182 -> V_189 ;
} else
V_182 = F_80 ( F_70 ( V_49 ) , V_180 . V_185 ) ;
V_34 = - V_190 ;
if ( ! V_182 )
break;
F_81 ( V_182 ) ;
V_34 = - V_57 ;
if ( V_49 -> V_191 &&
V_180 . V_185 != V_49 -> V_191 )
break;
V_48 -> V_187 = V_180 . V_185 ;
V_48 -> V_188 = V_180 . V_184 . V_10 ;
V_34 = 0 ;
break;
}
case V_192 :
case V_193 :
{
struct V_179 V_180 ;
V_34 = - V_194 ;
if ( F_20 ( V_49 ) -> V_145 )
break;
if ( V_23 < sizeof( struct V_195 ) )
goto V_143;
V_34 = - V_139 ;
if ( V_23 >= sizeof( struct V_179 ) ) {
if ( F_77 ( & V_180 , V_123 , sizeof( V_180 ) ) )
break;
} else {
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
if ( F_77 ( & V_180 , V_123 , sizeof( struct V_195 ) ) )
break;
}
if ( V_122 == V_192 )
V_34 = F_82 ( V_49 , & V_180 ) ;
else
V_34 = F_83 ( V_49 , & V_180 ) ;
break;
}
case V_196 :
{
struct V_197 * V_198 ;
if ( V_23 < F_84 ( 0 ) )
goto V_143;
if ( V_23 > V_199 ) {
V_34 = - V_81 ;
break;
}
V_198 = F_35 ( V_23 , V_77 ) ;
if ( ! V_198 ) {
V_34 = - V_81 ;
break;
}
V_34 = - V_139 ;
if ( F_77 ( V_198 , V_123 , V_23 ) ) {
F_32 ( V_198 ) ;
break;
}
if ( V_198 -> V_200 >= 0x3ffffffcU ||
V_198 -> V_200 > V_201 ) {
F_32 ( V_198 ) ;
V_34 = - V_81 ;
break;
}
if ( F_84 ( V_198 -> V_200 ) > V_23 ) {
F_32 ( V_198 ) ;
V_34 = - V_57 ;
break;
}
V_34 = F_85 ( V_49 , V_198 , 0 ) ;
F_32 ( V_198 ) ;
break;
}
case V_202 :
case V_203 :
case V_204 :
case V_205 :
{
struct V_206 V_207 ;
int V_208 , V_209 ;
if ( V_23 != sizeof( struct V_206 ) )
goto V_143;
if ( F_77 ( & V_207 , V_123 , sizeof( V_207 ) ) ) {
V_34 = - V_139 ;
break;
}
if ( V_122 == V_202 ) {
V_208 = V_210 ;
V_209 = 1 ;
} else if ( V_122 == V_203 ) {
V_208 = V_210 ;
V_209 = 0 ;
} else if ( V_122 == V_204 ) {
struct V_179 V_180 ;
V_180 . V_211 . V_10 = V_207 . V_211 ;
V_180 . V_184 . V_10 = V_207 . V_212 ;
V_180 . V_185 = 0 ;
V_34 = F_82 ( V_49 , & V_180 ) ;
if ( V_34 && V_34 != - V_80 )
break;
V_208 = V_213 ;
V_209 = 1 ;
} else {
V_208 = V_213 ;
V_209 = 0 ;
}
V_34 = F_86 ( V_209 , V_208 , V_49 , & V_207 , 0 ) ;
break;
}
case V_214 :
case V_215 :
{
struct V_216 V_217 ;
struct V_36 * V_218 ;
struct V_179 V_180 ;
if ( V_23 < sizeof( struct V_216 ) )
goto V_143;
V_34 = - V_139 ;
if ( F_77 ( & V_217 , V_123 , sizeof( V_217 ) ) )
break;
V_218 = (struct V_36 * ) & V_217 . V_219 ;
if ( V_218 -> V_41 != V_42 )
goto V_143;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_211 = V_218 -> V_43 ;
V_180 . V_185 = V_217 . V_220 ;
if ( V_122 == V_214 )
V_34 = F_82 ( V_49 , & V_180 ) ;
else
V_34 = F_83 ( V_49 , & V_180 ) ;
break;
}
case V_221 :
case V_222 :
case V_223 :
case V_224 :
{
struct V_225 V_226 ;
struct V_206 V_207 ;
struct V_36 * V_218 ;
int V_208 , V_209 ;
if ( V_23 != sizeof( struct V_225 ) )
goto V_143;
if ( F_77 ( & V_226 , V_123 , sizeof( V_226 ) ) ) {
V_34 = - V_139 ;
break;
}
if ( V_226 . V_227 . V_228 != V_42 ||
V_226 . V_229 . V_228 != V_42 ) {
V_34 = - V_190 ;
break;
}
V_218 = (struct V_36 * ) & V_226 . V_227 ;
V_207 . V_211 = V_218 -> V_43 . V_10 ;
V_218 = (struct V_36 * ) & V_226 . V_229 ;
V_207 . V_230 = V_218 -> V_43 . V_10 ;
V_207 . V_212 = 0 ;
if ( V_122 == V_223 ) {
V_208 = V_210 ;
V_209 = 1 ;
} else if ( V_122 == V_224 ) {
V_208 = V_210 ;
V_209 = 0 ;
} else if ( V_122 == V_221 ) {
struct V_179 V_180 ;
V_218 = (struct V_36 * ) & V_226 . V_227 ;
V_180 . V_211 = V_218 -> V_43 ;
V_180 . V_184 . V_10 = 0 ;
V_180 . V_185 = V_226 . V_231 ;
V_34 = F_82 ( V_49 , & V_180 ) ;
if ( V_34 && V_34 != - V_80 )
break;
V_226 . V_231 = V_180 . V_185 ;
V_208 = V_213 ;
V_209 = 1 ;
} else {
V_208 = V_213 ;
V_209 = 0 ;
}
V_34 = F_86 ( V_209 , V_208 , V_49 , & V_207 ,
V_226 . V_231 ) ;
break;
}
case V_232 :
{
struct V_36 * V_218 ;
struct V_197 * V_198 = NULL ;
struct V_233 * V_234 = NULL ;
int V_235 , V_236 , V_189 ;
if ( V_23 < F_87 ( 0 ) )
goto V_143;
if ( V_23 > V_199 ) {
V_34 = - V_81 ;
break;
}
V_234 = F_35 ( V_23 , V_77 ) ;
if ( ! V_234 ) {
V_34 = - V_81 ;
break;
}
V_34 = - V_139 ;
if ( F_77 ( V_234 , V_123 , V_23 ) )
goto V_237;
if ( V_234 -> V_238 >= 0x1ffffff ||
V_234 -> V_238 > V_201 ) {
V_34 = - V_81 ;
goto V_237;
}
if ( F_87 ( V_234 -> V_238 ) > V_23 ) {
V_34 = - V_57 ;
goto V_237;
}
V_235 = F_84 ( V_234 -> V_238 ) ;
V_198 = F_35 ( V_235 , V_77 ) ;
if ( ! V_198 ) {
V_34 = - V_81 ;
goto V_237;
}
V_189 = V_234 -> V_239 ;
V_218 = (struct V_36 * ) & V_234 -> V_240 ;
if ( V_218 -> V_41 != V_42 ) {
V_34 = - V_190 ;
goto V_237;
}
V_198 -> V_241 = V_218 -> V_43 . V_10 ;
V_198 -> V_242 = 0 ;
V_198 -> V_243 = V_234 -> V_244 ;
V_198 -> V_200 = V_234 -> V_238 ;
V_34 = - V_190 ;
for ( V_236 = 0 ; V_236 < V_234 -> V_238 ; ++ V_236 ) {
V_218 = (struct V_36 * ) & V_234 -> V_245 [ V_236 ] ;
if ( V_218 -> V_41 != V_42 )
goto V_237;
V_198 -> V_246 [ V_236 ] = V_218 -> V_43 . V_10 ;
}
F_32 ( V_234 ) ;
V_234 = NULL ;
V_34 = F_85 ( V_49 , V_198 , V_189 ) ;
V_237:
F_32 ( V_198 ) ;
F_32 ( V_234 ) ;
break;
}
case V_136 :
if ( V_23 < 1 )
goto V_143;
if ( V_124 != 0 && V_124 != 1 )
goto V_143;
V_48 -> V_247 = V_124 ;
break;
case V_129 :
V_34 = F_33 ( V_49 , V_124 ? 1 : 0 , NULL ) ;
break;
case V_130 :
if ( V_23 < 1 )
goto V_143;
V_48 -> V_248 = ! ! V_124 ;
break;
case V_249 :
case V_250 :
V_34 = - V_251 ;
if ( ! F_88 ( V_252 ) )
break;
V_34 = F_89 ( V_49 , V_122 , V_123 , V_23 ) ;
break;
case V_132 :
if ( ! F_88 ( V_252 ) ) {
V_34 = - V_251 ;
break;
}
if ( V_23 < 1 )
goto V_143;
V_48 -> V_253 = ! ! V_124 ;
break;
case V_133 :
if ( V_23 < 1 )
goto V_143;
if ( V_124 < 0 || V_124 > 255 )
goto V_143;
V_48 -> V_254 = V_124 ;
break;
default:
V_34 = - V_170 ;
break;
}
F_90 ( V_49 ) ;
return V_34 ;
V_143:
F_90 ( V_49 ) ;
return - V_57 ;
}
int F_91 ( struct V_69 * V_49 , struct V_3 * V_4 )
{
if ( ! ( F_20 ( V_49 ) -> V_51 & V_160 ) )
F_92 ( V_4 ) ;
return F_93 ( V_49 , V_4 ) ;
}
int F_94 ( struct V_69 * V_49 , int V_121 ,
int V_122 , char T_6 * V_123 , unsigned int V_23 )
{
int V_34 ;
if ( V_121 != V_16 )
return - V_170 ;
V_34 = F_64 ( V_49 , V_121 , V_122 , V_123 , V_23 ) ;
#ifdef F_95
if ( V_34 == - V_170 && V_122 != V_127 &&
V_122 != V_249 &&
V_122 != V_250 &&
! F_66 ( V_122 ) ) {
F_68 ( V_49 ) ;
V_34 = F_96 ( V_49 , V_151 , V_122 , V_123 , V_23 ) ;
F_90 ( V_49 ) ;
}
#endif
return V_34 ;
}
int F_97 ( struct V_69 * V_49 , int V_121 , int V_122 ,
char T_6 * V_123 , unsigned int V_23 )
{
int V_34 ;
if ( V_121 != V_16 )
return - V_170 ;
if ( V_122 >= V_214 && V_122 <= V_232 )
return F_98 ( V_49 , V_121 , V_122 , V_123 , V_23 ,
F_94 ) ;
V_34 = F_64 ( V_49 , V_121 , V_122 , V_123 , V_23 ) ;
#ifdef F_95
if ( V_34 == - V_170 && V_122 != V_127 &&
V_122 != V_249 &&
V_122 != V_250 &&
! F_66 ( V_122 ) ) {
F_68 ( V_49 ) ;
V_34 = F_99 ( V_49 , V_151 , V_122 ,
V_123 , V_23 ) ;
F_90 ( V_49 ) ;
}
#endif
return V_34 ;
}
static int F_100 ( struct V_69 * V_49 , int V_121 , int V_122 ,
char T_6 * V_123 , int T_6 * V_23 , unsigned V_50 )
{
struct V_47 * V_48 = F_20 ( V_49 ) ;
int V_124 ;
int V_40 ;
if ( V_121 != V_16 )
return - V_255 ;
if ( F_66 ( V_122 ) )
return F_101 ( V_49 , V_122 , V_123 , V_23 ) ;
if ( F_65 ( V_40 , V_23 ) )
return - V_139 ;
if ( V_40 < 0 )
return - V_57 ;
F_68 ( V_49 ) ;
switch ( V_122 ) {
case V_141 :
{
unsigned char V_25 [ sizeof( struct V_26 ) + 40 ] ;
struct V_26 * V_22 = (struct V_26 * ) V_25 ;
struct V_120 * V_144 ;
V_144 = F_37 ( V_48 -> V_144 ,
F_71 ( V_49 ) ) ;
V_22 -> V_23 = 0 ;
if ( V_144 )
memcpy ( V_25 , & V_144 -> V_22 ,
sizeof( struct V_26 ) +
V_144 -> V_22 . V_23 ) ;
F_90 ( V_49 ) ;
if ( V_22 -> V_23 == 0 )
return F_102 ( 0 , V_23 ) ;
F_11 ( V_22 ) ;
V_40 = F_103 (unsigned int, len, opt->optlen) ;
if ( F_102 ( V_40 , V_23 ) )
return - V_139 ;
if ( F_104 ( V_123 , V_22 -> V_30 , V_40 ) )
return - V_139 ;
return 0 ;
}
case V_17 :
V_124 = ( V_48 -> V_51 & V_160 ) != 0 ;
break;
case V_125 :
V_124 = ( V_48 -> V_51 & V_161 ) != 0 ;
break;
case V_126 :
V_124 = ( V_48 -> V_51 & V_162 ) != 0 ;
break;
case V_24 :
V_124 = ( V_48 -> V_51 & V_163 ) != 0 ;
break;
case V_29 :
V_124 = ( V_48 -> V_51 & V_164 ) != 0 ;
break;
case V_131 :
V_124 = ( V_48 -> V_51 & V_165 ) != 0 ;
break;
case V_138 :
V_124 = ( V_48 -> V_51 & V_166 ) != 0 ;
break;
case V_20 :
V_124 = V_48 -> V_21 ;
break;
case V_19 :
V_124 = ( V_48 -> V_169 == - 1 ?
V_256 :
V_48 -> V_169 ) ;
break;
case V_127 :
V_124 = V_48 -> V_171 ;
break;
case V_134 :
V_124 = V_48 -> V_172 ;
break;
case V_128 :
V_124 = V_48 -> V_175 ;
break;
case V_257 :
{
struct V_258 * V_259 ;
V_124 = 0 ;
V_259 = F_105 ( V_49 ) ;
if ( V_259 ) {
V_124 = F_106 ( V_259 ) ;
F_107 ( V_259 ) ;
}
if ( ! V_124 ) {
F_90 ( V_49 ) ;
return - V_260 ;
}
break;
}
case V_115 :
V_124 = V_48 -> V_99 ;
break;
case V_135 :
V_124 = V_48 -> V_176 ;
break;
case V_137 :
V_124 = V_48 -> V_177 ;
break;
case V_178 :
{
struct V_183 V_62 ;
V_40 = F_103 (unsigned int, len, sizeof(struct in_addr)) ;
V_62 . V_10 = V_48 -> V_188 ;
F_90 ( V_49 ) ;
if ( F_102 ( V_40 , V_23 ) )
return - V_139 ;
if ( F_104 ( V_123 , & V_62 , V_40 ) )
return - V_139 ;
return 0 ;
}
case V_196 :
{
struct V_197 V_198 ;
int V_34 ;
if ( V_40 < F_84 ( 0 ) ) {
F_90 ( V_49 ) ;
return - V_57 ;
}
if ( F_77 ( & V_198 , V_123 , F_84 ( 0 ) ) ) {
F_90 ( V_49 ) ;
return - V_139 ;
}
V_34 = F_108 ( V_49 , & V_198 ,
(struct V_197 T_6 * ) V_123 , V_23 ) ;
F_90 ( V_49 ) ;
return V_34 ;
}
case V_232 :
{
struct V_233 V_234 ;
int V_34 ;
if ( V_40 < F_87 ( 0 ) ) {
F_90 ( V_49 ) ;
return - V_57 ;
}
if ( F_77 ( & V_234 , V_123 , F_87 ( 0 ) ) ) {
F_90 ( V_49 ) ;
return - V_139 ;
}
V_34 = F_109 ( V_49 , & V_234 ,
(struct V_233 T_6 * ) V_123 ,
V_23 ) ;
F_90 ( V_49 ) ;
return V_34 ;
}
case V_136 :
V_124 = V_48 -> V_247 ;
break;
case V_261 :
{
struct V_1 V_2 ;
F_90 ( V_49 ) ;
if ( V_49 -> V_73 != V_167 )
return - V_170 ;
V_2 . V_262 = V_123 ;
V_2 . V_263 = V_40 ;
V_2 . V_27 = V_50 ;
if ( V_48 -> V_51 & V_160 ) {
struct V_5 V_6 ;
V_6 . V_9 . V_10 = V_48 -> V_264 ;
V_6 . V_14 . V_10 = V_48 -> V_264 ;
V_6 . V_12 = V_48 -> V_187 ;
F_4 ( & V_2 , V_16 , V_17 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_48 -> V_51 & V_161 ) {
int V_265 = V_48 -> V_176 ;
F_4 ( & V_2 , V_16 , V_19 , sizeof( V_265 ) , & V_265 ) ;
}
V_40 -= V_2 . V_263 ;
return F_102 ( V_40 , V_23 ) ;
}
case V_130 :
V_124 = V_48 -> V_248 ;
break;
case V_132 :
V_124 = V_48 -> V_253 ;
break;
case V_133 :
V_124 = V_48 -> V_254 ;
break;
default:
F_90 ( V_49 ) ;
return - V_170 ;
}
F_90 ( V_49 ) ;
if ( V_40 < sizeof( int ) && V_40 > 0 && V_124 >= 0 && V_124 <= 255 ) {
unsigned char V_140 = ( unsigned char ) V_124 ;
V_40 = 1 ;
if ( F_102 ( V_40 , V_23 ) )
return - V_139 ;
if ( F_104 ( V_123 , & V_140 , 1 ) )
return - V_139 ;
} else {
V_40 = F_103 (unsigned int, sizeof(int), len) ;
if ( F_102 ( V_40 , V_23 ) )
return - V_139 ;
if ( F_104 ( V_123 , & V_124 , V_40 ) )
return - V_139 ;
}
return 0 ;
}
int F_110 ( struct V_69 * V_49 , int V_121 ,
int V_122 , char T_6 * V_123 , int T_6 * V_23 )
{
int V_34 ;
V_34 = F_100 ( V_49 , V_121 , V_122 , V_123 , V_23 , 0 ) ;
#ifdef F_95
if ( V_34 == - V_170 && V_122 != V_261 &&
! F_66 ( V_122 ) ) {
int V_40 ;
if ( F_65 ( V_40 , V_23 ) )
return - V_139 ;
F_68 ( V_49 ) ;
V_34 = F_111 ( V_49 , V_151 , V_122 , V_123 ,
& V_40 ) ;
F_90 ( V_49 ) ;
if ( V_34 >= 0 )
V_34 = F_102 ( V_40 , V_23 ) ;
return V_34 ;
}
#endif
return V_34 ;
}
int F_112 ( struct V_69 * V_49 , int V_121 , int V_122 ,
char T_6 * V_123 , int T_6 * V_23 )
{
int V_34 ;
if ( V_122 == V_232 )
return F_113 ( V_49 , V_121 , V_122 , V_123 , V_23 ,
F_110 ) ;
V_34 = F_100 ( V_49 , V_121 , V_122 , V_123 , V_23 ,
V_266 ) ;
#ifdef F_95
if ( V_34 == - V_170 && V_122 != V_261 &&
! F_66 ( V_122 ) ) {
int V_40 ;
if ( F_65 ( V_40 , V_23 ) )
return - V_139 ;
F_68 ( V_49 ) ;
V_34 = F_114 ( V_49 , V_151 , V_122 , V_123 , & V_40 ) ;
F_90 ( V_49 ) ;
if ( V_34 >= 0 )
V_34 = F_102 ( V_40 , V_23 ) ;
return V_34 ;
}
#endif
return V_34 ;
}
