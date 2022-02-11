static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 ;
int V_10 = 0 ;
static T_1 V_11 [ 40 ] = {
0x1e , 0xad , 0x71 , 0x87 , 0x65 , 0xfc , 0x26 , 0x7d ,
0x0d , 0x45 , 0x67 , 0x74 , 0xcd , 0x06 , 0x1a , 0x18 ,
0xb6 , 0xc1 , 0xf0 , 0xc7 , 0xbb , 0x18 , 0xbe , 0xf8 ,
0x19 , 0x13 , 0x4b , 0xa9 , 0xd0 , 0x3e , 0xfe , 0x70 ,
0x25 , 0x03 , 0xab , 0x50 , 0x6a , 0x8b , 0x82 , 0x0c
} ;
V_8 -> V_12 = sizeof( V_11 ) ;
memcpy ( V_8 -> V_13 , V_11 , sizeof( V_11 ) ) ;
V_8 -> V_14 = V_15 ;
for ( V_10 = V_8 -> V_14 ; V_10 -- ; )
V_8 -> V_16 [ V_10 ] = V_10 & ( V_3 - 1 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
V_5 -> V_17 = & V_2 -> V_17 ;
V_5 -> V_18 = V_19 ;
V_5 -> V_20 = V_21 ;
V_5 -> V_22 = V_23 ;
V_5 -> V_24 = V_25 ;
V_5 -> V_26 = V_27 ;
V_5 -> V_28 = V_29 ;
V_5 -> V_30 = V_31 ;
V_5 -> V_32 = V_33 ;
V_5 -> V_34 = V_35 ;
V_5 -> V_3 = V_36 ;
V_5 -> V_9 . V_37 = V_38 ;
V_5 -> V_39 = V_40 ;
V_5 -> V_41 = V_42 ;
V_5 -> V_43 = V_44 ;
V_5 -> V_45 = V_46 ;
V_5 -> V_47 = V_48 ;
V_5 -> V_49 = 0U ;
F_1 ( V_2 , V_5 -> V_3 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
V_5 -> V_22 = F_4 ( V_5 -> V_22 , V_5 -> V_17 -> V_22 ) ;
V_5 -> V_24 = F_4 ( V_5 -> V_24 , V_5 -> V_17 -> V_24 ) ;
V_5 -> V_18 = F_4 ( V_5 -> V_18 , V_5 -> V_17 -> V_18 ) ;
V_5 -> V_18 = F_4 ( V_5 -> V_18 , F_5 () ) ;
if ( V_5 -> V_18 >= 8U )
V_5 -> V_18 = 8U ;
else if ( V_5 -> V_18 >= 4U )
V_5 -> V_18 = 4U ;
else if ( V_5 -> V_18 >= 2U )
V_5 -> V_18 = 2U ;
else
V_5 -> V_18 = 1U ;
V_5 -> V_3 = F_4 ( V_5 -> V_18 , V_36 ) ;
V_5 -> V_50 = F_6 ( V_2 -> V_51 ) ;
if ( ( V_5 -> V_50 == V_52 ) ||
( V_2 -> V_17 . V_18 == 1U ) ||
( V_5 -> V_18 == 1U ) ) {
V_5 -> V_34 = 0U ;
V_5 -> V_18 = 1U ;
}
V_5 -> V_43 &= V_2 -> V_17 . V_43 ;
V_5 -> V_53 = V_2 -> V_17 . V_53 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_54 = V_2 -> V_55 . V_56 ( V_2 -> V_57 ) ;
if ( V_54 )
return V_54 ;
if ( V_2 -> V_58 . V_59 != V_2 -> V_57 -> V_60 . V_59 ) {
F_8 ( L_1 ,
V_61 , V_2 -> V_58 . V_59 ,
V_2 -> V_57 -> V_60 . V_59 ) ;
F_9 ( V_2 ) ;
}
V_2 -> V_58 = V_2 -> V_57 -> V_60 ;
if ( ! F_10 ( V_2 -> V_62 ) && V_2 -> V_58 . V_59 ) {
F_11 ( & V_2 -> V_63 . V_64 ,
V_65 ) ;
F_12 ( & V_2 -> V_63 . V_64 ,
V_66 ) ;
F_13 ( V_2 -> V_62 ) ;
F_14 ( V_2 -> V_62 ) ;
}
if ( F_10 ( V_2 -> V_62 ) && ! V_2 -> V_58 . V_59 ) {
F_15 ( V_2 -> V_62 ) ;
F_16 ( V_2 -> V_62 ) ;
F_11 ( & V_2 -> V_63 . V_64 , V_66 ) ;
}
return 0 ;
}
static void F_17 ( unsigned long V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
struct V_68 * V_62 = F_18 ( V_2 ) ;
int V_54 = 0 ;
unsigned int V_10 = 0U ;
struct V_69 V_70 ;
struct V_71 V_72 ;
if ( F_19 ( & V_2 -> V_63 . V_64 , V_73 ) )
goto V_74;
V_54 = F_7 ( V_2 ) ;
if ( V_54 )
goto V_74;
if ( V_2 -> V_55 . V_75 )
V_2 -> V_55 . V_75 ( V_2 -> V_57 ) ;
memset ( & V_70 , 0U , sizeof( struct V_69 ) ) ;
memset ( & V_72 , 0U , sizeof( struct V_71 ) ) ;
for ( V_10 = F_20 ( V_2 -> V_76 ) ; V_10 -- ; ) {
if ( V_2 -> V_76 [ V_10 ] )
F_21 ( V_2 -> V_76 [ V_10 ] , & V_70 , & V_72 ) ;
}
V_62 -> V_77 . V_78 = V_70 . V_79 ;
V_62 -> V_77 . V_80 = V_70 . V_81 ;
V_62 -> V_77 . V_82 = V_70 . V_83 ;
V_62 -> V_77 . V_84 = V_72 . V_79 ;
V_62 -> V_77 . V_85 = V_72 . V_81 ;
V_62 -> V_77 . V_86 = V_72 . V_83 ;
V_74:
F_22 ( & V_2 -> V_87 ,
V_88 + V_89 ) ;
}
static void F_23 ( unsigned long V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
struct V_90 * V_76 = NULL ;
unsigned int V_10 = 0U ;
for ( V_10 = 0U , V_76 = V_2 -> V_76 [ 0 ] ;
V_2 -> V_91 > V_10 ; ++ V_10 , V_76 = V_2 -> V_76 [ V_10 ] )
F_24 ( V_10 , ( void * ) V_76 ) ;
F_22 ( & V_2 -> V_92 , V_88 +
V_93 ) ;
}
static struct V_68 * F_25 ( void )
{
return F_26 ( sizeof( struct V_1 ) , V_94 ) ;
}
struct V_1 * F_27 ( const struct V_95 * V_96 ,
const struct V_97 * V_98 ,
struct V_99 * V_100 ,
struct V_101 * V_51 ,
unsigned int V_102 ,
const struct V_55 * V_55 )
{
struct V_68 * V_62 = NULL ;
struct V_1 * V_2 = NULL ;
int V_54 = 0 ;
V_62 = F_25 () ;
if ( ! V_62 ) {
V_54 = - V_103 ;
goto V_74;
}
V_2 = F_28 ( V_62 ) ;
V_62 -> V_104 = V_96 ;
V_62 -> V_97 = V_98 ;
F_29 ( V_62 , V_100 ) ;
V_62 -> V_105 = V_102 ;
V_2 -> V_62 = V_62 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_55 = * V_55 ;
V_2 -> V_102 = ( T_1 ) V_102 ;
V_2 -> V_57 = V_2 -> V_55 . V_106 ( V_51 , V_2 -> V_102 ,
& V_2 -> V_55 ) ;
V_54 = V_2 -> V_55 . V_107 ( V_2 -> V_57 , & V_2 -> V_17 ) ;
if ( V_54 < 0 )
goto V_74;
F_2 ( V_2 ) ;
V_74:
if ( V_54 < 0 ) {
F_30 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_54 = 0 ;
if ( ! V_2 -> V_62 ) {
V_54 = - V_108 ;
goto V_74;
}
V_54 = V_2 -> V_55 . V_109 ( V_2 -> V_57 ,
V_2 -> V_6 . V_17 ,
V_2 -> V_62 -> V_110 ) ;
if ( V_54 < 0 )
goto V_74;
#if F_32 ( V_111 )
{
static T_1 V_112 [] = V_111 ;
F_33 ( V_2 -> V_62 -> V_110 , V_112 ) ;
}
#endif
F_15 ( V_2 -> V_62 ) ;
F_16 ( V_2 -> V_62 ) ;
V_54 = F_34 ( V_2 -> V_62 ) ;
if ( V_54 < 0 )
goto V_74;
V_74:
return V_54 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_113 * V_17 = V_2 -> V_6 . V_17 ;
struct V_4 * V_6 = & V_2 -> V_6 ;
V_2 -> V_62 -> V_53 |= V_17 -> V_53 ;
V_2 -> V_62 -> V_114 = V_17 -> V_53 ;
V_2 -> V_62 -> V_115 = V_17 -> V_116 ;
V_2 -> V_62 -> V_41 = V_6 -> V_41 - V_117 ;
V_2 -> V_62 -> V_118 = V_2 -> V_17 . V_41 - V_119 - V_117 ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_62 )
goto V_74;
if ( V_2 -> V_62 -> V_120 == V_121 )
F_37 ( V_2 -> V_62 ) ;
if ( V_2 -> V_57 )
V_2 -> V_55 . V_122 ( V_2 -> V_57 ) ;
F_38 ( V_2 -> V_62 ) ;
V_74: ;
}
struct V_1 * F_39 ( struct V_68 * V_62 )
{
struct V_1 * V_2 = NULL ;
int V_54 = 0 ;
if ( ! V_62 ) {
V_54 = - V_108 ;
goto V_74;
}
V_2 = F_28 ( V_62 ) ;
if ( ! V_2 ) {
V_54 = - V_108 ;
goto V_74;
}
if ( F_40 ( V_62 ) )
F_16 ( V_62 ) ;
F_15 ( V_2 -> V_62 ) ;
for ( V_2 -> V_91 = 0 ; V_2 -> V_91 < V_2 -> V_6 . V_18 ;
V_2 -> V_91 ++ ) {
V_2 -> V_76 [ V_2 -> V_91 ] =
F_41 ( V_2 , V_2 -> V_91 , & V_2 -> V_6 ) ;
if ( ! V_2 -> V_76 [ V_2 -> V_91 ] ) {
V_54 = - V_103 ;
goto V_74;
}
}
V_74:
if ( V_54 < 0 ) {
F_30 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_42 ( struct V_1 * V_2 , unsigned int V_123 ,
struct V_124 * V_125 )
{
V_2 -> V_126 [ V_123 ] = V_125 ;
}
struct V_99 * F_43 ( struct V_1 * V_2 )
{
return V_2 -> V_62 -> V_100 . V_127 ;
}
struct V_68 * F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_62 ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_90 * V_76 = NULL ;
int V_54 = 0 ;
unsigned int V_10 = 0U ;
V_2 -> V_128 = V_129 ;
V_54 = V_2 -> V_55 . V_130 ( V_2 -> V_57 ) ;
if ( V_54 < 0 )
goto V_74;
V_54 = V_2 -> V_55 . V_131 ( V_2 -> V_57 , & V_2 -> V_6 ,
F_18 ( V_2 ) -> V_110 ) ;
if ( V_54 < 0 )
goto V_74;
for ( V_10 = 0U , V_76 = V_2 -> V_76 [ 0 ] ;
V_2 -> V_91 > V_10 ; ++ V_10 , V_76 = V_2 -> V_76 [ V_10 ] )
F_45 ( V_76 , & V_2 -> V_55 , V_2 -> V_57 ) ;
V_74:
return V_54 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_90 * V_76 = NULL ;
int V_54 = 0 ;
unsigned int V_10 = 0U ;
V_54 = V_2 -> V_55 . V_132 ( V_2 -> V_57 ,
V_2 -> V_133 . V_134 ,
V_2 -> V_133 . V_135 ) ;
if ( V_54 < 0 )
goto V_74;
V_54 = V_2 -> V_55 . V_136 ( V_2 -> V_57 ,
V_2 -> V_137 ) ;
if ( V_54 < 0 )
goto V_74;
for ( V_10 = 0U , V_76 = V_2 -> V_76 [ 0 ] ;
V_2 -> V_91 > V_10 ; ++ V_10 , V_76 = V_2 -> V_76 [ V_10 ] ) {
V_54 = F_47 ( V_76 ) ;
if ( V_54 < 0 )
goto V_74;
}
V_54 = V_2 -> V_55 . V_138 ( V_2 -> V_57 ) ;
if ( V_54 < 0 )
goto V_74;
V_54 = F_9 ( V_2 ) ;
if ( V_54 )
goto V_74;
F_48 ( & V_2 -> V_87 , & F_17 ,
( unsigned long ) V_2 ) ;
F_22 ( & V_2 -> V_87 , V_88 +
V_89 ) ;
if ( V_2 -> V_6 . V_26 ) {
F_48 ( & V_2 -> V_92 , & F_23 ,
( unsigned long ) V_2 ) ;
F_22 ( & V_2 -> V_92 , V_88 +
V_93 ) ;
} else {
for ( V_10 = 0U , V_76 = V_2 -> V_76 [ 0 ] ;
V_2 -> V_91 > V_10 ; ++ V_10 , V_76 = V_2 -> V_76 [ V_10 ] ) {
V_54 = F_49 ( V_2 -> V_51 , V_10 ,
V_2 -> V_62 -> V_139 , V_76 ,
F_50 ( V_76 ) ) ;
if ( V_54 < 0 )
goto V_74;
}
V_54 = V_2 -> V_55 . V_140 ( V_2 -> V_57 ,
V_141 ) ;
if ( V_54 < 0 )
goto V_74;
}
V_54 = F_51 ( V_2 -> V_62 , V_2 -> V_91 ) ;
if ( V_54 < 0 )
goto V_74;
V_54 = F_52 ( V_2 -> V_62 , V_2 -> V_91 ) ;
if ( V_54 < 0 )
goto V_74;
F_53 ( V_2 -> V_62 ) ;
V_74:
return V_54 ;
}
static unsigned int F_54 ( struct V_1 * V_2 ,
struct V_142 * V_143 ,
struct V_124 * V_125 )
{
unsigned int V_144 = 0U ;
unsigned int V_145 = F_55 ( V_143 ) -> V_145 ;
unsigned int V_146 = 0U ;
unsigned int V_147 = V_125 -> V_148 ;
struct V_149 * V_150 = NULL ;
struct V_149 * V_151 = & V_125 -> V_152 [ V_147 ] ;
if ( F_56 ( F_57 ( V_143 ) ) ) {
V_151 -> V_64 = 0U ;
V_151 -> V_153 = V_143 -> V_154 ;
V_151 -> V_155 = V_117 ;
V_151 -> V_156 = F_58 ( V_143 ) ;
V_151 -> V_157 = F_59 ( V_143 ) ;
V_151 -> V_158 = F_55 ( V_143 ) -> V_159 ;
V_151 -> V_160 = 1U ;
V_151 -> V_161 = 0xffffU ;
V_151 -> V_162 =
( F_60 ( V_143 ) -> V_163 == 6 ) ? 1U : 0U ;
V_147 = F_61 ( V_125 , V_147 ) ;
V_151 = & V_125 -> V_152 [ V_147 ] ;
++ V_144 ;
}
V_151 -> V_64 = 0U ;
V_151 -> V_154 = F_62 ( V_143 ) ;
V_151 -> V_164 = F_63 ( F_43 ( V_2 ) ,
V_143 -> V_165 ,
V_151 -> V_154 ,
V_166 ) ;
if ( F_56 ( F_64 ( F_43 ( V_2 ) , V_151 -> V_164 ) ) )
goto exit;
V_150 = V_151 ;
V_151 -> V_153 = V_143 -> V_154 ;
V_151 -> V_167 = 1U ;
V_151 -> V_168 = 1U ;
++ V_144 ;
if ( V_143 -> V_169 == V_170 ) {
V_151 -> V_171 = ( F_65 ( V_172 ) == V_143 -> V_173 ) ?
1U : 0U ;
if ( F_60 ( V_143 ) -> V_163 == 4 ) {
V_151 -> V_174 =
( F_60 ( V_143 ) -> V_173 == V_175 ) ?
1U : 0U ;
V_151 -> V_176 =
( F_60 ( V_143 ) -> V_173 == V_177 ) ?
1U : 0U ;
} else if ( F_60 ( V_143 ) -> V_163 == 6 ) {
V_151 -> V_174 =
( F_66 ( V_143 ) -> V_178 == V_179 ) ?
1U : 0U ;
V_151 -> V_176 =
( F_66 ( V_143 ) -> V_178 == V_180 ) ?
1U : 0U ;
}
}
for (; V_145 -- ; ++ V_146 ) {
unsigned int V_181 = 0U ;
unsigned int V_182 = 0U ;
unsigned int V_183 = 0U ;
T_2 V_184 ;
T_3 * V_185 = & F_55 ( V_143 ) -> V_186 [ V_146 ] ;
V_181 = F_67 ( V_185 ) ;
while ( V_181 ) {
if ( V_181 > V_187 )
V_183 = V_187 ;
else
V_183 = V_181 ;
V_184 = F_68 ( F_43 ( V_2 ) ,
V_185 ,
V_182 ,
V_183 ,
V_166 ) ;
if ( F_56 ( F_64 ( F_43 ( V_2 ) ,
V_184 ) ) )
goto V_188;
V_147 = F_61 ( V_125 , V_147 ) ;
V_151 = & V_125 -> V_152 [ V_147 ] ;
V_151 -> V_64 = 0U ;
V_151 -> V_154 = V_183 ;
V_151 -> V_164 = V_184 ;
V_151 -> V_168 = 1U ;
V_151 -> V_161 = 0xffffU ;
V_181 -= V_183 ;
V_182 += V_183 ;
++ V_144 ;
}
}
V_150 -> V_161 = V_147 ;
V_151 -> V_189 = 1U ;
V_151 -> V_143 = V_143 ;
goto exit;
V_188:
for ( V_147 = V_125 -> V_148 ;
V_144 > 0 ;
-- V_144 , V_147 = F_61 ( V_125 , V_147 ) ) {
V_151 = & V_125 -> V_152 [ V_147 ] ;
if ( ! V_151 -> V_160 && V_151 -> V_164 ) {
if ( F_56 ( V_151 -> V_167 ) ) {
F_69 ( F_43 ( V_2 ) ,
V_151 -> V_164 ,
V_151 -> V_154 ,
V_166 ) ;
} else {
F_70 ( F_43 ( V_2 ) ,
V_151 -> V_164 ,
V_151 -> V_154 ,
V_166 ) ;
}
}
}
exit:
return V_144 ;
}
int F_71 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
struct V_124 * V_125 = NULL ;
unsigned int V_186 = 0U ;
unsigned int V_190 = V_143 -> V_191 % V_2 -> V_6 . V_18 ;
unsigned int V_192 = 0U ;
int V_54 = V_193 ;
V_186 = F_55 ( V_143 ) -> V_145 + 1 ;
V_125 = V_2 -> V_126 [ F_72 ( V_2 , V_192 , V_190 ) ] ;
if ( V_186 > V_194 ) {
F_73 ( V_143 ) ;
goto V_74;
}
F_74 ( V_125 ) ;
if ( F_75 ( V_2 -> V_62 , V_125 -> V_123 ) ) {
V_54 = V_195 ;
goto V_74;
}
V_186 = F_54 ( V_2 , V_143 , V_125 ) ;
if ( F_76 ( V_186 ) ) {
V_54 = V_2 -> V_55 . V_196 ( V_2 -> V_57 ,
V_125 ,
V_186 ) ;
if ( V_54 >= 0 ) {
++ V_125 -> V_77 . V_197 . V_79 ;
V_125 -> V_77 . V_197 . V_81 += V_143 -> V_154 ;
}
} else {
V_54 = V_195 ;
}
V_74:
return V_54 ;
}
int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_55 . V_198 ( V_2 -> V_57 ) ;
}
int F_77 ( struct V_1 * V_2 , unsigned int V_64 )
{
int V_54 = 0 ;
V_54 = V_2 -> V_55 . V_136 ( V_2 -> V_57 , V_64 ) ;
if ( V_54 < 0 )
goto V_74;
V_2 -> V_137 = V_64 ;
V_74:
return V_54 ;
}
int F_78 ( struct V_1 * V_2 , struct V_68 * V_62 )
{
struct V_199 * V_200 = NULL ;
unsigned int V_10 = 0U ;
V_2 -> V_133 . V_135 = 0U ;
F_79 (ha, ndev) {
F_33 ( V_2 -> V_133 . V_134 [ V_10 ++ ] , V_200 -> V_201 ) ;
++ V_2 -> V_133 . V_135 ;
if ( V_10 >= V_202 )
break;
}
if ( V_10 >= V_202 ) {
V_2 -> V_137 |= V_203 ;
V_2 -> V_57 -> V_6 -> V_204 = 0 ;
return V_2 -> V_55 . V_136 ( V_2 -> V_57 ,
V_2 -> V_137 ) ;
} else {
return V_2 -> V_55 . V_132 ( V_2 -> V_57 ,
V_2 -> V_133 . V_134 ,
V_2 -> V_133 . V_135 ) ;
}
}
int F_80 ( struct V_1 * V_2 , int V_205 )
{
V_2 -> V_6 . V_41 = V_205 ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 , struct V_68 * V_62 )
{
return V_2 -> V_55 . V_206 ( V_2 -> V_57 , V_62 -> V_110 ) ;
}
unsigned int F_82 ( struct V_1 * V_2 )
{
return V_2 -> V_58 . V_59 ;
}
int F_83 ( struct V_1 * V_2 , struct V_207 * V_208 , void * V_209 )
{
T_4 * V_210 = V_209 ;
int V_54 = 0 ;
V_208 -> V_163 = 1 ;
V_54 = V_2 -> V_55 . V_211 ( V_2 -> V_57 ,
& V_2 -> V_17 , V_210 ) ;
if ( V_54 < 0 )
goto V_74;
V_74:
return V_54 ;
}
int F_84 ( struct V_1 * V_2 )
{
return V_2 -> V_17 . V_212 ;
}
void F_85 ( struct V_1 * V_2 , T_5 * V_165 )
{
struct V_90 * V_76 = NULL ;
unsigned int V_10 = 0U ;
unsigned int V_135 = 0U ;
int V_54 = 0 ;
V_54 = V_2 -> V_55 . V_213 ( V_2 -> V_57 , V_165 , & V_135 ) ;
if ( V_54 < 0 )
goto V_74;
V_165 += V_135 ;
V_135 = 0U ;
for ( V_10 = 0U , V_76 = V_2 -> V_76 [ 0 ] ;
V_76 && V_2 -> V_91 > V_10 ; ++ V_10 , V_76 = V_2 -> V_76 [ V_10 ] ) {
V_165 += V_135 ;
F_86 ( V_76 , V_165 , & V_135 ) ;
}
V_74: ;
( void ) V_54 ;
}
void F_87 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
V_215 -> V_216 . V_102 = V_217 ;
V_215 -> V_216 . V_218 = V_219 ;
V_215 -> V_216 . V_220 = V_2 -> V_6 . V_45 ;
F_88 ( V_215 , V_221 ) ;
if ( V_2 -> V_17 . V_43 & V_222 )
F_89 ( V_215 , V_221 ,
10000baseT_Full ) ;
if ( V_2 -> V_17 . V_43 & V_223 )
F_89 ( V_215 , V_221 ,
5000baseT_Full ) ;
if ( V_2 -> V_17 . V_43 & V_224 )
F_89 ( V_215 , V_221 ,
2500baseT_Full ) ;
if ( V_2 -> V_17 . V_43 & V_225 )
F_89 ( V_215 , V_221 ,
1000baseT_Full ) ;
if ( V_2 -> V_17 . V_43 & V_226 )
F_89 ( V_215 , V_221 ,
100baseT_Full ) ;
if ( V_2 -> V_17 . V_39 )
F_89 ( V_215 , V_221 ,
V_227 ) ;
F_89 ( V_215 , V_221 , V_228 ) ;
F_89 ( V_215 , V_221 , V_229 ) ;
F_88 ( V_215 , V_230 ) ;
if ( V_2 -> V_6 . V_45 )
F_89 ( V_215 , V_230 , V_228 ) ;
if ( V_2 -> V_6 . V_43 & V_222 )
F_89 ( V_215 , V_230 ,
10000baseT_Full ) ;
if ( V_2 -> V_6 . V_43 & V_223 )
F_89 ( V_215 , V_230 ,
5000baseT_Full ) ;
if ( V_2 -> V_6 . V_43 & V_224 )
F_89 ( V_215 , V_230 ,
2500baseT_Full ) ;
if ( V_2 -> V_6 . V_43 & V_225 )
F_89 ( V_215 , V_230 ,
1000baseT_Full ) ;
if ( V_2 -> V_6 . V_43 & V_226 )
F_89 ( V_215 , V_230 ,
100baseT_Full ) ;
if ( V_2 -> V_6 . V_39 )
F_89 ( V_215 , V_230 ,
V_227 ) ;
F_89 ( V_215 , V_230 , V_229 ) ;
}
int F_90 ( struct V_1 * V_2 ,
const struct V_214 * V_215 )
{
T_4 V_231 = 0U ;
T_4 V_232 = 0U ;
int V_54 = 0 ;
if ( V_215 -> V_216 . V_220 == V_233 ) {
V_232 = V_2 -> V_17 . V_43 ;
V_2 -> V_6 . V_45 = true ;
} else {
V_231 = V_215 -> V_216 . V_231 ;
switch ( V_231 ) {
case V_234 :
V_232 = V_226 ;
break;
case V_235 :
V_232 = V_225 ;
break;
case V_236 :
V_232 = V_224 ;
break;
case V_237 :
V_232 = V_223 ;
break;
case V_238 :
V_232 = V_222 ;
break;
default:
V_54 = - 1 ;
goto V_74;
break;
}
if ( ! ( V_2 -> V_17 . V_43 & V_232 ) ) {
V_54 = - 1 ;
goto V_74;
}
V_2 -> V_6 . V_45 = false ;
}
V_54 = V_2 -> V_55 . V_239 ( V_2 -> V_57 , V_232 ) ;
if ( V_54 < 0 )
goto V_74;
V_2 -> V_6 . V_43 = V_232 ;
V_74:
return V_54 ;
}
struct V_4 * F_91 ( struct V_1 * V_2 )
{
return & V_2 -> V_6 ;
}
T_4 F_92 ( struct V_1 * V_2 )
{
T_4 V_240 = 0U ;
V_2 -> V_55 . V_241 ( V_2 -> V_57 , & V_240 ) ;
return V_240 ;
}
int F_93 ( struct V_1 * V_2 )
{
struct V_90 * V_76 = NULL ;
unsigned int V_10 = 0U ;
F_16 ( V_2 -> V_62 ) ;
F_15 ( V_2 -> V_62 ) ;
F_94 ( & V_2 -> V_87 ) ;
V_2 -> V_55 . V_242 ( V_2 -> V_57 , V_141 ) ;
if ( V_2 -> V_6 . V_26 )
F_94 ( & V_2 -> V_92 ) ;
else
F_95 ( V_2 -> V_51 ) ;
for ( V_10 = 0U , V_76 = V_2 -> V_76 [ 0 ] ;
V_2 -> V_91 > V_10 ; ++ V_10 , V_76 = V_2 -> V_76 [ V_10 ] )
F_96 ( V_76 ) ;
return V_2 -> V_55 . V_243 ( V_2 -> V_57 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_90 * V_76 = NULL ;
unsigned int V_10 = 0U ;
if ( ! V_2 )
goto V_74;
for ( V_10 = 0U , V_76 = V_2 -> V_76 [ 0 ] ;
V_2 -> V_91 > V_10 ; ++ V_10 , V_76 = V_2 -> V_76 [ V_10 ] )
F_98 ( V_76 ) ;
if ( V_2 -> V_128 == V_129 ) {
( void ) V_2 -> V_55 . V_244 ( V_2 -> V_57 ) ;
} else {
( void ) V_2 -> V_55 . V_245 ( V_2 -> V_57 ,
V_2 -> V_128 ) ;
}
V_74: ;
}
void F_30 ( struct V_1 * V_2 )
{
unsigned int V_10 = 0U ;
if ( ! V_2 )
goto V_74;
for ( V_10 = F_20 ( V_2 -> V_76 ) ; V_10 -- ; ) {
if ( V_2 -> V_76 [ V_10 ] ) {
F_99 ( V_2 -> V_76 [ V_10 ] ) ;
V_2 -> V_76 [ V_10 ] = NULL ;
}
}
V_74: ;
}
int F_100 ( struct V_1 * V_2 , T_6 * V_246 )
{
int V_54 = 0 ;
if ( ! F_40 ( V_2 -> V_62 ) ) {
V_54 = 0 ;
goto V_247;
}
F_101 () ;
if ( V_246 -> V_248 & V_249 || V_246 -> V_248 & V_250 ) {
V_2 -> V_128 = V_251 ;
F_102 ( V_2 -> V_62 ) ;
F_103 ( V_2 -> V_62 ) ;
V_54 = F_93 ( V_2 ) ;
if ( V_54 < 0 )
goto V_74;
F_97 ( V_2 ) ;
} else {
V_54 = F_44 ( V_2 ) ;
if ( V_54 < 0 )
goto V_74;
V_54 = F_46 ( V_2 ) ;
if ( V_54 < 0 )
goto V_74;
F_104 ( V_2 -> V_62 ) ;
F_53 ( V_2 -> V_62 ) ;
}
V_74:
F_105 () ;
V_247:
return V_54 ;
}
