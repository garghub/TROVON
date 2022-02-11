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
unsigned int V_44 = V_42 -> V_45 ;
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
static int F_63 ( struct V_65 * V_43 , int V_116 ,
int V_117 , char T_6 * V_118 , unsigned int V_17 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_119 = 0 , V_28 ;
if ( ( ( 1 << V_117 ) & ( ( 1 << V_11 ) | ( 1 << V_120 ) |
( 1 << V_18 ) | ( 1 << V_121 ) |
( 1 << V_23 ) | ( 1 << V_14 ) |
( 1 << V_13 ) | ( 1 << V_122 ) |
( 1 << V_123 ) | ( 1 << V_111 ) |
( 1 << V_124 ) | ( 1 << V_125 ) |
( 1 << V_126 ) | ( 1 << V_127 ) |
( 1 << V_128 ) | ( 1 << V_129 ) ) ) ||
V_117 == V_130 ||
V_117 == V_131 ||
V_117 == V_132 ||
V_117 == V_133 ||
V_117 == V_134 ) {
if ( V_17 >= sizeof( int ) ) {
if ( F_64 ( V_119 , ( int T_6 * ) V_118 ) )
return - V_135 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_136 ;
if ( F_64 ( V_136 , ( unsigned char T_6 * ) V_118 ) )
return - V_135 ;
V_119 = ( int ) V_136 ;
}
}
if ( F_65 ( V_117 ) )
return F_66 ( V_43 , V_117 , V_118 , V_17 ) ;
V_28 = 0 ;
F_67 ( V_43 ) ;
switch ( V_117 ) {
case V_137 :
{
struct V_138 * V_139 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_140;
V_28 = F_68 ( F_69 ( V_43 ) , & V_16 ,
V_118 , V_17 ) ;
if ( V_28 )
break;
V_139 = F_37 ( V_42 -> V_141 ,
F_70 ( V_43 ) ) ;
if ( V_42 -> V_142 ) {
struct V_143 * V_144 = F_71 ( V_43 ) ;
#if F_72 ( V_145 )
if ( V_43 -> V_146 == V_147 ||
( ! ( ( 1 << V_43 -> V_148 ) &
( V_149 | V_150 ) ) &&
V_42 -> V_151 != V_152 ) ) {
#endif
if ( V_139 )
V_144 -> V_153 -= V_139 -> V_16 . V_17 ;
if ( V_16 )
V_144 -> V_153 += V_16 -> V_16 . V_17 ;
V_144 -> V_154 ( V_43 , V_144 -> V_155 ) ;
#if F_72 ( V_145 )
}
#endif
}
F_40 ( V_42 -> V_141 , V_16 ) ;
if ( V_139 )
F_73 ( V_139 , V_63 ) ;
break;
}
case V_11 :
if ( V_119 )
V_42 -> V_45 |= V_156 ;
else
V_42 -> V_45 &= ~ V_156 ;
break;
case V_120 :
if ( V_119 )
V_42 -> V_45 |= V_157 ;
else
V_42 -> V_45 &= ~ V_157 ;
break;
case V_121 :
if ( V_119 )
V_42 -> V_45 |= V_158 ;
else
V_42 -> V_45 &= ~ V_158 ;
break;
case V_18 :
if ( V_119 )
V_42 -> V_45 |= V_159 ;
else
V_42 -> V_45 &= ~ V_159 ;
break;
case V_23 :
if ( V_119 )
V_42 -> V_45 |= V_160 ;
else
V_42 -> V_45 &= ~ V_160 ;
break;
case V_126 :
if ( V_119 )
V_42 -> V_45 |= V_161 ;
else
V_42 -> V_45 &= ~ V_161 ;
break;
case V_134 :
if ( V_119 )
V_42 -> V_45 |= V_162 ;
else
V_42 -> V_45 &= ~ V_162 ;
break;
case V_14 :
if ( V_43 -> V_69 == V_163 ) {
V_119 &= ~ V_164 ;
V_119 |= V_42 -> V_15 & V_164 ;
}
if ( V_42 -> V_15 != V_119 ) {
V_42 -> V_15 = V_119 ;
V_43 -> V_165 = F_74 ( V_119 ) ;
F_75 ( V_43 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_140;
if ( V_119 != - 1 && ( V_119 < 0 || V_119 > 255 ) )
goto V_140;
V_42 -> V_166 = V_119 ;
break;
case V_122 :
if ( V_43 -> V_69 != V_70 ) {
V_28 = - V_167 ;
break;
}
V_42 -> V_168 = V_119 ? 1 : 0 ;
break;
case V_129 :
if ( V_43 -> V_69 != V_70 ) {
V_28 = - V_167 ;
break;
}
V_42 -> V_169 = V_119 ? 1 : 0 ;
break;
case V_123 :
if ( V_119 < V_170 || V_119 > V_171 )
goto V_140;
V_42 -> V_172 = V_119 ;
break;
case V_111 :
V_42 -> V_95 = ! ! V_119 ;
if ( ! V_119 )
F_76 ( & V_43 -> V_103 ) ;
break;
case V_131 :
if ( V_43 -> V_69 == V_163 )
goto V_140;
if ( V_17 < 1 )
goto V_140;
if ( V_119 == - 1 )
V_119 = 1 ;
if ( V_119 < 0 || V_119 > 255 )
goto V_140;
V_42 -> V_173 = V_119 ;
break;
case V_133 :
if ( V_17 < 1 )
goto V_140;
V_42 -> V_174 = ! ! V_119 ;
break;
case V_130 :
{
struct V_175 * V_176 = NULL ;
int V_177 ;
if ( V_17 != sizeof( int ) )
goto V_140;
V_177 = ( V_178 int ) F_77 ( ( V_178 T_5 ) V_119 ) ;
if ( V_177 == 0 ) {
V_42 -> V_179 = 0 ;
V_28 = 0 ;
break;
}
V_176 = F_78 ( F_69 ( V_43 ) , V_177 ) ;
V_28 = - V_180 ;
if ( ! V_176 )
break;
F_79 ( V_176 ) ;
V_28 = - V_51 ;
if ( V_43 -> V_181 )
break;
V_42 -> V_179 = V_177 ;
V_28 = 0 ;
break;
}
case V_182 :
{
struct V_183 V_184 ;
struct V_175 * V_176 = NULL ;
if ( V_43 -> V_69 == V_163 )
goto V_140;
if ( V_17 < sizeof( struct V_185 ) )
goto V_140;
V_28 = - V_135 ;
if ( V_17 >= sizeof( struct V_183 ) ) {
if ( F_80 ( & V_184 , V_118 , sizeof( V_184 ) ) )
break;
} else {
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
if ( V_17 >= sizeof( struct V_186 ) ) {
if ( F_80 ( & V_184 , V_118 ,
sizeof( struct V_186 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_185 ) ) {
if ( F_80 ( & V_184 . V_187 , V_118 ,
sizeof( struct V_185 ) ) )
break;
}
}
if ( ! V_184 . V_188 ) {
if ( V_184 . V_187 . V_8 == F_81 ( V_189 ) ) {
V_42 -> V_190 = 0 ;
V_42 -> V_191 = 0 ;
V_28 = 0 ;
break;
}
V_176 = F_82 ( F_69 ( V_43 ) , V_184 . V_187 . V_8 ) ;
if ( V_176 )
V_184 . V_188 = V_176 -> V_177 ;
} else
V_176 = F_78 ( F_69 ( V_43 ) , V_184 . V_188 ) ;
V_28 = - V_180 ;
if ( ! V_176 )
break;
F_79 ( V_176 ) ;
V_28 = - V_51 ;
if ( V_43 -> V_181 &&
V_184 . V_188 != V_43 -> V_181 )
break;
V_42 -> V_190 = V_184 . V_188 ;
V_42 -> V_191 = V_184 . V_187 . V_8 ;
V_28 = 0 ;
break;
}
case V_192 :
case V_193 :
{
struct V_183 V_184 ;
V_28 = - V_194 ;
if ( F_20 ( V_43 ) -> V_142 )
break;
if ( V_17 < sizeof( struct V_186 ) )
goto V_140;
V_28 = - V_135 ;
if ( V_17 >= sizeof( struct V_183 ) ) {
if ( F_80 ( & V_184 , V_118 , sizeof( V_184 ) ) )
break;
} else {
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
if ( F_80 ( & V_184 , V_118 , sizeof( struct V_186 ) ) )
break;
}
if ( V_117 == V_192 )
V_28 = F_83 ( V_43 , & V_184 ) ;
else
V_28 = F_84 ( V_43 , & V_184 ) ;
break;
}
case V_195 :
{
struct V_196 * V_197 ;
if ( V_17 < F_85 ( 0 ) )
goto V_140;
if ( V_17 > V_198 ) {
V_28 = - V_77 ;
break;
}
V_197 = F_35 ( V_17 , V_73 ) ;
if ( ! V_197 ) {
V_28 = - V_77 ;
break;
}
V_28 = - V_135 ;
if ( F_80 ( V_197 , V_118 , V_17 ) ) {
F_32 ( V_197 ) ;
break;
}
if ( V_197 -> V_199 >= 0x3ffffffcU ||
V_197 -> V_199 > V_200 ) {
F_32 ( V_197 ) ;
V_28 = - V_77 ;
break;
}
if ( F_85 ( V_197 -> V_199 ) > V_17 ) {
F_32 ( V_197 ) ;
V_28 = - V_51 ;
break;
}
V_28 = F_86 ( V_43 , V_197 , 0 ) ;
F_32 ( V_197 ) ;
break;
}
case V_201 :
case V_202 :
case V_203 :
case V_204 :
{
struct V_205 V_206 ;
int V_207 , V_208 ;
if ( V_17 != sizeof( struct V_205 ) )
goto V_140;
if ( F_80 ( & V_206 , V_118 , sizeof( V_206 ) ) ) {
V_28 = - V_135 ;
break;
}
if ( V_117 == V_201 ) {
V_207 = V_209 ;
V_208 = 1 ;
} else if ( V_117 == V_202 ) {
V_207 = V_209 ;
V_208 = 0 ;
} else if ( V_117 == V_203 ) {
struct V_183 V_184 ;
V_184 . V_210 . V_8 = V_206 . V_210 ;
V_184 . V_187 . V_8 = V_206 . V_211 ;
V_184 . V_188 = 0 ;
V_28 = F_83 ( V_43 , & V_184 ) ;
if ( V_28 && V_28 != - V_76 )
break;
V_207 = V_212 ;
V_208 = 1 ;
} else {
V_207 = V_212 ;
V_208 = 0 ;
}
V_28 = F_87 ( V_208 , V_207 , V_43 , & V_206 , 0 ) ;
break;
}
case V_213 :
case V_214 :
{
struct V_215 V_216 ;
struct V_30 * V_217 ;
struct V_183 V_184 ;
if ( V_17 < sizeof( struct V_215 ) )
goto V_140;
V_28 = - V_135 ;
if ( F_80 ( & V_216 , V_118 , sizeof( V_216 ) ) )
break;
V_217 = (struct V_30 * ) & V_216 . V_218 ;
if ( V_217 -> V_35 != V_36 )
goto V_140;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_184 . V_210 = V_217 -> V_37 ;
V_184 . V_188 = V_216 . V_219 ;
if ( V_117 == V_213 )
V_28 = F_83 ( V_43 , & V_184 ) ;
else
V_28 = F_84 ( V_43 , & V_184 ) ;
break;
}
case V_220 :
case V_221 :
case V_222 :
case V_223 :
{
struct V_224 V_225 ;
struct V_205 V_206 ;
struct V_30 * V_217 ;
int V_207 , V_208 ;
if ( V_17 != sizeof( struct V_224 ) )
goto V_140;
if ( F_80 ( & V_225 , V_118 , sizeof( V_225 ) ) ) {
V_28 = - V_135 ;
break;
}
if ( V_225 . V_226 . V_227 != V_36 ||
V_225 . V_228 . V_227 != V_36 ) {
V_28 = - V_180 ;
break;
}
V_217 = (struct V_30 * ) & V_225 . V_226 ;
V_206 . V_210 = V_217 -> V_37 . V_8 ;
V_217 = (struct V_30 * ) & V_225 . V_228 ;
V_206 . V_229 = V_217 -> V_37 . V_8 ;
V_206 . V_211 = 0 ;
if ( V_117 == V_222 ) {
V_207 = V_209 ;
V_208 = 1 ;
} else if ( V_117 == V_223 ) {
V_207 = V_209 ;
V_208 = 0 ;
} else if ( V_117 == V_220 ) {
struct V_183 V_184 ;
V_217 = (struct V_30 * ) & V_225 . V_226 ;
V_184 . V_210 = V_217 -> V_37 ;
V_184 . V_187 . V_8 = 0 ;
V_184 . V_188 = V_225 . V_230 ;
V_28 = F_83 ( V_43 , & V_184 ) ;
if ( V_28 && V_28 != - V_76 )
break;
V_225 . V_230 = V_184 . V_188 ;
V_207 = V_212 ;
V_208 = 1 ;
} else {
V_207 = V_212 ;
V_208 = 0 ;
}
V_28 = F_87 ( V_208 , V_207 , V_43 , & V_206 ,
V_225 . V_230 ) ;
break;
}
case V_231 :
{
struct V_30 * V_217 ;
struct V_196 * V_197 = NULL ;
struct V_232 * V_233 = NULL ;
int V_234 , V_235 , V_177 ;
if ( V_17 < F_88 ( 0 ) )
goto V_140;
if ( V_17 > V_198 ) {
V_28 = - V_77 ;
break;
}
V_233 = F_35 ( V_17 , V_73 ) ;
if ( ! V_233 ) {
V_28 = - V_77 ;
break;
}
V_28 = - V_135 ;
if ( F_80 ( V_233 , V_118 , V_17 ) )
goto V_236;
if ( V_233 -> V_237 >= 0x1ffffff ||
V_233 -> V_237 > V_200 ) {
V_28 = - V_77 ;
goto V_236;
}
if ( F_88 ( V_233 -> V_237 ) > V_17 ) {
V_28 = - V_51 ;
goto V_236;
}
V_234 = F_85 ( V_233 -> V_237 ) ;
V_197 = F_35 ( V_234 , V_73 ) ;
if ( ! V_197 ) {
V_28 = - V_77 ;
goto V_236;
}
V_177 = V_233 -> V_238 ;
V_217 = (struct V_30 * ) & V_233 -> V_239 ;
if ( V_217 -> V_35 != V_36 ) {
V_28 = - V_180 ;
goto V_236;
}
V_197 -> V_240 = V_217 -> V_37 . V_8 ;
V_197 -> V_241 = 0 ;
V_197 -> V_242 = V_233 -> V_243 ;
V_197 -> V_199 = V_233 -> V_237 ;
V_28 = - V_180 ;
for ( V_235 = 0 ; V_235 < V_233 -> V_237 ; ++ V_235 ) {
V_217 = (struct V_30 * ) & V_233 -> V_244 [ V_235 ] ;
if ( V_217 -> V_35 != V_36 )
goto V_236;
V_197 -> V_245 [ V_235 ] = V_217 -> V_37 . V_8 ;
}
F_32 ( V_233 ) ;
V_233 = NULL ;
V_28 = F_86 ( V_43 , V_197 , V_177 ) ;
V_236:
F_32 ( V_197 ) ;
F_32 ( V_233 ) ;
break;
}
case V_132 :
if ( V_17 < 1 )
goto V_140;
if ( V_119 != 0 && V_119 != 1 )
goto V_140;
V_42 -> V_246 = V_119 ;
break;
case V_124 :
V_28 = F_33 ( V_43 , V_119 ? 1 : 0 , NULL ) ;
break;
case V_125 :
if ( V_17 < 1 )
goto V_140;
V_42 -> V_247 = ! ! V_119 ;
break;
case V_248 :
case V_249 :
V_28 = - V_250 ;
if ( ! F_89 ( V_251 ) )
break;
V_28 = F_90 ( V_43 , V_117 , V_118 , V_17 ) ;
break;
case V_127 :
if ( ! ! V_119 && ! F_89 ( V_252 ) && ! F_89 ( V_251 ) ) {
V_28 = - V_250 ;
break;
}
if ( V_17 < 1 )
goto V_140;
V_42 -> V_253 = ! ! V_119 ;
break;
case V_128 :
if ( V_17 < 1 )
goto V_140;
if ( V_119 < 0 || V_119 > 255 )
goto V_140;
V_42 -> V_254 = V_119 ;
break;
default:
V_28 = - V_167 ;
break;
}
F_91 ( V_43 ) ;
return V_28 ;
V_140:
F_91 ( V_43 ) ;
return - V_51 ;
}
void F_92 ( struct V_3 * V_4 )
{
struct V_5 * V_255 = F_2 ( V_4 ) ;
if ( F_93 ( V_4 ) ) {
V_255 -> V_56 = F_94 ( V_4 ) ;
V_255 -> V_58 . V_8 = F_95 ( V_4 ) ;
} else {
V_255 -> V_56 = 0 ;
V_255 -> V_58 . V_8 = 0 ;
}
F_96 ( V_4 ) ;
}
int F_97 ( struct V_65 * V_43 , int V_116 ,
int V_117 , char T_6 * V_118 , unsigned int V_17 )
{
int V_28 ;
if ( V_116 != V_10 )
return - V_167 ;
V_28 = F_63 ( V_43 , V_116 , V_117 , V_118 , V_17 ) ;
#ifdef F_98
if ( V_28 == - V_167 && V_117 != V_122 &&
V_117 != V_248 &&
V_117 != V_249 &&
! F_65 ( V_117 ) ) {
F_67 ( V_43 ) ;
V_28 = F_99 ( V_43 , V_147 , V_117 , V_118 , V_17 ) ;
F_91 ( V_43 ) ;
}
#endif
return V_28 ;
}
int F_100 ( struct V_65 * V_43 , int V_116 , int V_117 ,
char T_6 * V_118 , unsigned int V_17 )
{
int V_28 ;
if ( V_116 != V_10 )
return - V_167 ;
if ( V_117 >= V_213 && V_117 <= V_231 )
return F_101 ( V_43 , V_116 , V_117 , V_118 , V_17 ,
F_97 ) ;
V_28 = F_63 ( V_43 , V_116 , V_117 , V_118 , V_17 ) ;
#ifdef F_98
if ( V_28 == - V_167 && V_117 != V_122 &&
V_117 != V_248 &&
V_117 != V_249 &&
! F_65 ( V_117 ) ) {
F_67 ( V_43 ) ;
V_28 = F_102 ( V_43 , V_147 , V_117 ,
V_118 , V_17 ) ;
F_91 ( V_43 ) ;
}
#endif
return V_28 ;
}
static int F_103 ( struct V_65 * V_43 , int V_116 , int V_117 ,
char T_6 * V_118 , int T_6 * V_17 , unsigned int V_44 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_119 ;
int V_34 ;
if ( V_116 != V_10 )
return - V_256 ;
if ( F_65 ( V_117 ) )
return F_104 ( V_43 , V_117 , V_118 , V_17 ) ;
if ( F_64 ( V_34 , V_17 ) )
return - V_135 ;
if ( V_34 < 0 )
return - V_51 ;
F_67 ( V_43 ) ;
switch ( V_117 ) {
case V_137 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_138 * V_141 ;
V_141 = F_37 ( V_42 -> V_141 ,
F_70 ( V_43 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_141 )
memcpy ( V_19 , & V_141 -> V_16 ,
sizeof( struct V_20 ) +
V_141 -> V_16 . V_17 ) ;
F_91 ( V_43 ) ;
if ( V_16 -> V_17 == 0 )
return F_105 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_34 = F_106 (unsigned int, len, opt->optlen) ;
if ( F_105 ( V_34 , V_17 ) )
return - V_135 ;
if ( F_107 ( V_118 , V_16 -> V_24 , V_34 ) )
return - V_135 ;
return 0 ;
}
case V_11 :
V_119 = ( V_42 -> V_45 & V_156 ) != 0 ;
break;
case V_120 :
V_119 = ( V_42 -> V_45 & V_157 ) != 0 ;
break;
case V_121 :
V_119 = ( V_42 -> V_45 & V_158 ) != 0 ;
break;
case V_18 :
V_119 = ( V_42 -> V_45 & V_159 ) != 0 ;
break;
case V_23 :
V_119 = ( V_42 -> V_45 & V_160 ) != 0 ;
break;
case V_126 :
V_119 = ( V_42 -> V_45 & V_161 ) != 0 ;
break;
case V_134 :
V_119 = ( V_42 -> V_45 & V_162 ) != 0 ;
break;
case V_14 :
V_119 = V_42 -> V_15 ;
break;
case V_13 :
V_119 = ( V_42 -> V_166 == - 1 ?
V_257 :
V_42 -> V_166 ) ;
break;
case V_122 :
V_119 = V_42 -> V_168 ;
break;
case V_129 :
V_119 = V_42 -> V_169 ;
break;
case V_123 :
V_119 = V_42 -> V_172 ;
break;
case V_258 :
{
struct V_259 * V_260 ;
V_119 = 0 ;
V_260 = F_108 ( V_43 ) ;
if ( V_260 ) {
V_119 = F_109 ( V_260 ) ;
F_110 ( V_260 ) ;
}
if ( ! V_119 ) {
F_91 ( V_43 ) ;
return - V_261 ;
}
break;
}
case V_111 :
V_119 = V_42 -> V_95 ;
break;
case V_131 :
V_119 = V_42 -> V_173 ;
break;
case V_133 :
V_119 = V_42 -> V_174 ;
break;
case V_130 :
V_119 = ( V_178 int ) F_81 ( ( V_262 ) V_42 -> V_179 ) ;
break;
case V_182 :
{
struct V_185 V_57 ;
V_34 = F_106 (unsigned int, len, sizeof(struct in_addr)) ;
V_57 . V_8 = V_42 -> V_191 ;
F_91 ( V_43 ) ;
if ( F_105 ( V_34 , V_17 ) )
return - V_135 ;
if ( F_107 ( V_118 , & V_57 , V_34 ) )
return - V_135 ;
return 0 ;
}
case V_195 :
{
struct V_196 V_197 ;
int V_28 ;
if ( V_34 < F_85 ( 0 ) ) {
F_91 ( V_43 ) ;
return - V_51 ;
}
if ( F_80 ( & V_197 , V_118 , F_85 ( 0 ) ) ) {
F_91 ( V_43 ) ;
return - V_135 ;
}
V_28 = F_111 ( V_43 , & V_197 ,
(struct V_196 T_6 * ) V_118 , V_17 ) ;
F_91 ( V_43 ) ;
return V_28 ;
}
case V_231 :
{
struct V_232 V_233 ;
int V_28 ;
if ( V_34 < F_88 ( 0 ) ) {
F_91 ( V_43 ) ;
return - V_51 ;
}
if ( F_80 ( & V_233 , V_118 , F_88 ( 0 ) ) ) {
F_91 ( V_43 ) ;
return - V_135 ;
}
V_28 = F_112 ( V_43 , & V_233 ,
(struct V_232 T_6 * ) V_118 ,
V_17 ) ;
F_91 ( V_43 ) ;
return V_28 ;
}
case V_132 :
V_119 = V_42 -> V_246 ;
break;
case V_263 :
{
struct V_1 V_2 ;
F_91 ( V_43 ) ;
if ( V_43 -> V_69 != V_163 )
return - V_167 ;
V_2 . V_264 = V_118 ;
V_2 . V_265 = V_34 ;
V_2 . V_21 = V_44 ;
if ( V_42 -> V_45 & V_156 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_42 -> V_266 ;
V_6 . V_58 . V_8 = V_42 -> V_266 ;
V_6 . V_56 = V_42 -> V_190 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_42 -> V_45 & V_157 ) {
int V_267 = V_42 -> V_173 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_267 ) , & V_267 ) ;
}
if ( V_42 -> V_45 & V_158 ) {
int V_15 = V_42 -> V_268 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_34 -= V_2 . V_265 ;
return F_105 ( V_34 , V_17 ) ;
}
case V_125 :
V_119 = V_42 -> V_247 ;
break;
case V_127 :
V_119 = V_42 -> V_253 ;
break;
case V_128 :
V_119 = V_42 -> V_254 ;
break;
default:
F_91 ( V_43 ) ;
return - V_167 ;
}
F_91 ( V_43 ) ;
if ( V_34 < sizeof( int ) && V_34 > 0 && V_119 >= 0 && V_119 <= 255 ) {
unsigned char V_136 = ( unsigned char ) V_119 ;
V_34 = 1 ;
if ( F_105 ( V_34 , V_17 ) )
return - V_135 ;
if ( F_107 ( V_118 , & V_136 , 1 ) )
return - V_135 ;
} else {
V_34 = F_106 (unsigned int, sizeof(int), len) ;
if ( F_105 ( V_34 , V_17 ) )
return - V_135 ;
if ( F_107 ( V_118 , & V_119 , V_34 ) )
return - V_135 ;
}
return 0 ;
}
int F_113 ( struct V_65 * V_43 , int V_116 ,
int V_117 , char T_6 * V_118 , int T_6 * V_17 )
{
int V_28 ;
V_28 = F_103 ( V_43 , V_116 , V_117 , V_118 , V_17 , 0 ) ;
#ifdef F_98
if ( V_28 == - V_167 && V_117 != V_263 &&
! F_65 ( V_117 ) ) {
int V_34 ;
if ( F_64 ( V_34 , V_17 ) )
return - V_135 ;
F_67 ( V_43 ) ;
V_28 = F_114 ( V_43 , V_147 , V_117 , V_118 ,
& V_34 ) ;
F_91 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_105 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
int F_115 ( struct V_65 * V_43 , int V_116 , int V_117 ,
char T_6 * V_118 , int T_6 * V_17 )
{
int V_28 ;
if ( V_117 == V_231 )
return F_116 ( V_43 , V_116 , V_117 , V_118 , V_17 ,
F_113 ) ;
V_28 = F_103 ( V_43 , V_116 , V_117 , V_118 , V_17 ,
V_269 ) ;
#ifdef F_98
if ( V_28 == - V_167 && V_117 != V_263 &&
! F_65 ( V_117 ) ) {
int V_34 ;
if ( F_64 ( V_34 , V_17 ) )
return - V_135 ;
F_67 ( V_43 ) ;
V_28 = F_117 ( V_43 , V_147 , V_117 , V_118 , & V_34 ) ;
F_91 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_105 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
