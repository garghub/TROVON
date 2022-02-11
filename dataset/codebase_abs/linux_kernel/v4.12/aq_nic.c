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
V_5 -> V_30 = V_5 -> V_28 ?
V_31 : 0U ;
V_5 -> V_32 = V_33 ;
V_5 -> V_3 = V_34 ;
V_5 -> V_9 . V_35 = V_36 ;
V_5 -> V_37 = V_38 ;
V_5 -> V_39 = V_40 ;
V_5 -> V_41 = V_42 ;
V_5 -> V_43 = V_44 ;
V_5 -> V_45 = V_46 ;
V_5 -> V_47 = 0U ;
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
V_5 -> V_48 = F_6 ( V_2 -> V_49 ) ;
if ( ( V_5 -> V_48 == V_50 ) ||
( V_2 -> V_17 . V_18 == 1U ) ||
( V_5 -> V_18 == 1U ) ) {
V_5 -> V_32 = 0U ;
V_5 -> V_18 = 1U ;
}
V_5 -> V_41 &= V_2 -> V_17 . V_41 ;
V_5 -> V_51 = V_2 -> V_17 . V_51 ;
return 0 ;
}
static void F_7 ( unsigned long V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
struct V_53 * V_54 = F_8 ( V_2 ) ;
int V_55 = 0 ;
unsigned int V_10 = 0U ;
struct V_56 V_57 ;
struct V_58 V_59 ;
struct V_60 V_61 ;
if ( F_9 ( & V_2 -> V_62 . V_63 , V_64 ) )
goto V_65;
V_55 = V_2 -> V_66 . V_67 ( V_2 -> V_68 , & V_57 ) ;
if ( V_55 < 0 )
goto V_65;
V_2 -> V_66 . V_69 ( V_2 -> V_68 ,
V_2 -> V_6 . V_28 ) ;
if ( memcmp ( & V_57 , & V_2 -> V_57 , sizeof( V_57 ) ) ) {
if ( V_57 . V_70 ) {
F_10 ( & V_2 -> V_62 . V_63 ,
V_71 ) ;
F_11 ( & V_2 -> V_62 . V_63 ,
V_72 ) ;
F_12 ( V_2 -> V_54 ) ;
} else {
F_13 ( V_2 -> V_54 ) ;
F_10 ( & V_2 -> V_62 . V_63 , V_72 ) ;
}
V_2 -> V_57 = V_57 ;
}
memset ( & V_59 , 0U , sizeof( struct V_58 ) ) ;
memset ( & V_61 , 0U , sizeof( struct V_60 ) ) ;
for ( V_10 = F_14 ( V_2 -> V_73 ) ; V_10 -- ; ) {
if ( V_2 -> V_73 [ V_10 ] )
F_15 ( V_2 -> V_73 [ V_10 ] , & V_59 , & V_61 ) ;
}
V_54 -> V_74 . V_75 = V_59 . V_76 ;
V_54 -> V_74 . V_77 = V_59 . V_78 ;
V_54 -> V_74 . V_79 = V_59 . V_80 ;
V_54 -> V_74 . V_81 = V_61 . V_76 ;
V_54 -> V_74 . V_82 = V_61 . V_78 ;
V_54 -> V_74 . V_83 = V_61 . V_80 ;
V_65:
F_16 ( & V_2 -> V_84 ,
V_85 + V_86 ) ;
}
static void F_17 ( unsigned long V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
struct V_87 * V_73 = NULL ;
unsigned int V_10 = 0U ;
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] )
F_18 ( V_10 , ( void * ) V_73 ) ;
F_16 ( & V_2 -> V_89 , V_85 +
V_90 ) ;
}
static struct V_53 * F_19 ( void )
{
return F_20 ( sizeof( struct V_1 ) , V_91 ) ;
}
struct V_1 * F_21 ( const struct V_92 * V_93 ,
const struct V_94 * V_95 ,
struct V_96 * V_97 ,
struct V_98 * V_49 ,
unsigned int V_99 ,
const struct V_66 * V_66 )
{
struct V_53 * V_54 = NULL ;
struct V_1 * V_2 = NULL ;
int V_55 = 0 ;
V_54 = F_19 () ;
if ( ! V_54 ) {
V_55 = - V_100 ;
goto V_65;
}
V_2 = F_22 ( V_54 ) ;
V_54 -> V_101 = V_93 ;
V_54 -> V_94 = V_95 ;
F_23 ( V_54 , V_97 ) ;
V_54 -> V_102 = V_99 ;
V_54 -> V_103 = V_104 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_66 = * V_66 ;
V_2 -> V_99 = ( T_1 ) V_99 ;
V_2 -> V_68 = V_2 -> V_66 . V_105 ( V_49 , V_2 -> V_99 ,
& V_2 -> V_66 ) ;
V_55 = V_2 -> V_66 . V_106 ( V_2 -> V_68 , & V_2 -> V_17 ) ;
if ( V_55 < 0 )
goto V_65;
F_2 ( V_2 ) ;
V_65:
if ( V_55 < 0 ) {
F_24 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_55 = 0 ;
unsigned int V_10 = 0U ;
if ( ! V_2 -> V_54 ) {
V_55 = - V_107 ;
goto V_65;
}
V_55 = V_2 -> V_66 . V_108 ( V_2 -> V_68 ,
V_2 -> V_6 . V_17 ,
V_2 -> V_54 -> V_109 ) ;
if ( V_55 < 0 )
goto V_65;
#if F_26 ( V_110 )
{
static T_1 V_111 [] = V_110 ;
F_27 ( V_2 -> V_54 -> V_109 , V_111 ) ;
}
#endif
F_13 ( V_2 -> V_54 ) ;
for ( V_10 = V_91 ; V_10 -- ; )
F_28 ( V_2 , V_10 ) ;
V_55 = F_29 ( V_2 -> V_54 ) ;
if ( V_55 < 0 )
goto V_65;
V_65:
return V_55 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_112 * V_17 = V_2 -> V_6 . V_17 ;
struct V_4 * V_6 = & V_2 -> V_6 ;
V_2 -> V_54 -> V_51 |= V_17 -> V_51 ;
V_2 -> V_54 -> V_113 = V_17 -> V_51 ;
V_2 -> V_54 -> V_114 = V_17 -> V_115 ;
V_2 -> V_54 -> V_39 = V_6 -> V_39 - V_116 ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_54 )
goto V_65;
if ( V_2 -> V_54 -> V_117 == V_118 )
F_32 ( V_2 -> V_54 ) ;
if ( V_2 -> V_68 )
V_2 -> V_66 . V_119 ( V_2 -> V_68 ) ;
F_33 ( V_2 -> V_54 ) ;
V_65: ;
}
struct V_1 * F_34 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = NULL ;
int V_55 = 0 ;
if ( ! V_54 ) {
V_55 = - V_107 ;
goto V_65;
}
V_2 = F_22 ( V_54 ) ;
if ( ! V_2 ) {
V_55 = - V_107 ;
goto V_65;
}
if ( F_35 ( V_54 ) ) {
unsigned int V_10 ;
for ( V_10 = V_91 ; V_10 -- ; )
F_36 ( V_54 , V_10 ) ;
}
for ( V_2 -> V_88 = 0 ; V_2 -> V_88 < V_2 -> V_6 . V_18 ;
V_2 -> V_88 ++ ) {
V_2 -> V_73 [ V_2 -> V_88 ] =
F_37 ( V_2 , V_2 -> V_88 , & V_2 -> V_6 ) ;
if ( ! V_2 -> V_73 [ V_2 -> V_88 ] ) {
V_55 = - V_100 ;
goto V_65;
}
}
V_65:
if ( V_55 < 0 ) {
F_24 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_38 ( struct V_1 * V_2 , unsigned int V_120 ,
struct V_121 * V_122 )
{
V_2 -> V_123 [ V_120 ] = V_122 ;
}
struct V_96 * F_39 ( struct V_1 * V_2 )
{
return V_2 -> V_54 -> V_97 . V_124 ;
}
struct V_53 * F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_54 ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_87 * V_73 = NULL ;
int V_55 = 0 ;
unsigned int V_10 = 0U ;
V_2 -> V_125 = V_126 ;
V_55 = V_2 -> V_66 . V_127 ( V_2 -> V_68 ) ;
if ( V_55 < 0 )
goto V_65;
V_55 = V_2 -> V_66 . V_128 ( V_2 -> V_68 , & V_2 -> V_6 ,
F_8 ( V_2 ) -> V_109 ) ;
if ( V_55 < 0 )
goto V_65;
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] )
F_41 ( V_73 , & V_2 -> V_66 , V_2 -> V_68 ) ;
V_65:
return V_55 ;
}
void F_42 ( struct V_1 * V_2 , unsigned int V_120 )
{
F_43 ( V_2 -> V_54 , V_120 ) ;
}
void F_28 ( struct V_1 * V_2 , unsigned int V_120 )
{
F_36 ( V_2 -> V_54 , V_120 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_87 * V_73 = NULL ;
int V_55 = 0 ;
unsigned int V_10 = 0U ;
V_55 = V_2 -> V_66 . V_129 ( V_2 -> V_68 ,
V_2 -> V_130 . V_131 ,
V_2 -> V_130 . V_132 ) ;
if ( V_55 < 0 )
goto V_65;
V_55 = V_2 -> V_66 . V_133 ( V_2 -> V_68 ,
V_2 -> V_134 ) ;
if ( V_55 < 0 )
goto V_65;
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] ) {
V_55 = F_45 ( V_73 ) ;
if ( V_55 < 0 )
goto V_65;
}
V_55 = V_2 -> V_66 . V_135 ( V_2 -> V_68 ) ;
if ( V_55 < 0 )
goto V_65;
V_55 = V_2 -> V_66 . V_69 ( V_2 -> V_68 ,
V_2 -> V_6 . V_28 ) ;
if ( V_55 < 0 )
goto V_65;
F_46 ( & V_2 -> V_84 , & F_7 ,
( unsigned long ) V_2 ) ;
F_16 ( & V_2 -> V_84 , V_85 +
V_86 ) ;
if ( V_2 -> V_6 . V_26 ) {
F_46 ( & V_2 -> V_89 , & F_17 ,
( unsigned long ) V_2 ) ;
F_16 ( & V_2 -> V_89 , V_85 +
V_90 ) ;
} else {
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] ) {
V_55 = F_47 ( V_2 -> V_49 , V_10 ,
V_2 -> V_54 -> V_136 , V_73 ,
F_48 ( V_73 ) ) ;
if ( V_55 < 0 )
goto V_65;
}
V_55 = V_2 -> V_66 . V_137 ( V_2 -> V_68 ,
V_138 ) ;
if ( V_55 < 0 )
goto V_65;
}
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] )
F_42 ( V_2 , V_10 ) ;
V_55 = F_49 ( V_2 -> V_54 , V_2 -> V_88 ) ;
if ( V_55 < 0 )
goto V_65;
V_55 = F_50 ( V_2 -> V_54 , V_2 -> V_88 ) ;
if ( V_55 < 0 )
goto V_65;
V_65:
return V_55 ;
}
static unsigned int F_51 ( struct V_1 * V_2 ,
struct V_139 * V_140 ,
struct V_121 * V_122 )
{
unsigned int V_141 = 0U ;
unsigned int V_142 = F_52 ( V_140 ) -> V_142 ;
unsigned int V_143 = 0U ;
unsigned int V_144 = V_122 -> V_145 ;
struct V_146 * V_147 = & V_122 -> V_148 [ V_144 ] ;
if ( F_53 ( F_54 ( V_140 ) ) ) {
V_147 -> V_63 = 0U ;
V_147 -> V_149 = V_140 -> V_150 ;
V_147 -> V_151 = V_116 ;
V_147 -> V_152 = F_55 ( V_140 ) ;
V_147 -> V_153 = F_56 ( V_140 ) ;
V_147 -> V_154 = F_52 ( V_140 ) -> V_155 ;
V_147 -> V_156 = 1U ;
V_147 -> V_157 =
( F_57 ( V_140 ) -> V_158 == 6 ) ? 1U : 0U ;
V_144 = F_58 ( V_122 , V_144 ) ;
V_147 = & V_122 -> V_148 [ V_144 ] ;
++ V_141 ;
}
V_147 -> V_63 = 0U ;
V_147 -> V_150 = F_59 ( V_140 ) ;
V_147 -> V_159 = F_60 ( F_39 ( V_2 ) ,
V_140 -> V_160 ,
V_147 -> V_150 ,
V_161 ) ;
if ( F_53 ( F_61 ( F_39 ( V_2 ) , V_147 -> V_159 ) ) )
goto exit;
V_147 -> V_149 = V_140 -> V_150 ;
V_147 -> V_162 = 1U ;
V_147 -> V_163 = 1U ;
++ V_141 ;
if ( V_140 -> V_164 == V_165 ) {
V_147 -> V_166 = ( F_62 ( V_167 ) == V_140 -> V_168 ) ?
1U : 0U ;
if ( F_57 ( V_140 ) -> V_158 == 4 ) {
V_147 -> V_169 =
( F_57 ( V_140 ) -> V_168 == V_170 ) ?
1U : 0U ;
V_147 -> V_171 =
( F_57 ( V_140 ) -> V_168 == V_172 ) ?
1U : 0U ;
} else if ( F_57 ( V_140 ) -> V_158 == 6 ) {
V_147 -> V_169 =
( F_63 ( V_140 ) -> V_173 == V_174 ) ?
1U : 0U ;
V_147 -> V_171 =
( F_63 ( V_140 ) -> V_173 == V_175 ) ?
1U : 0U ;
}
}
for (; V_142 -- ; ++ V_143 ) {
unsigned int V_176 = 0U ;
T_2 V_177 ;
T_3 * V_178 = & F_52 ( V_140 ) -> V_179 [ V_143 ] ;
V_176 = F_64 ( V_178 ) ;
V_177 = F_65 ( F_39 ( V_2 ) , V_178 , 0 ,
V_176 , V_161 ) ;
if ( F_53 ( F_61 ( F_39 ( V_2 ) , V_177 ) ) )
goto V_180;
while ( V_176 > V_181 ) {
V_144 = F_58 ( V_122 , V_144 ) ;
V_147 = & V_122 -> V_148 [ V_144 ] ;
V_147 -> V_63 = 0U ;
V_147 -> V_150 = V_181 ;
V_147 -> V_159 = V_177 ;
V_147 -> V_163 = 1U ;
V_176 -= V_181 ;
V_177 += V_181 ;
++ V_141 ;
}
V_144 = F_58 ( V_122 , V_144 ) ;
V_147 = & V_122 -> V_148 [ V_144 ] ;
V_147 -> V_63 = 0U ;
V_147 -> V_150 = V_176 ;
V_147 -> V_159 = V_177 ;
V_147 -> V_163 = 1U ;
++ V_141 ;
}
V_147 -> V_182 = 1U ;
V_147 -> V_140 = V_140 ;
goto exit;
V_180:
for ( V_144 = V_122 -> V_145 ;
V_141 > 0 ;
-- V_141 , V_144 = F_58 ( V_122 , V_144 ) ) {
V_147 = & V_122 -> V_148 [ V_144 ] ;
if ( ! V_147 -> V_156 && V_147 -> V_159 ) {
if ( F_53 ( V_147 -> V_162 ) ) {
F_66 ( F_39 ( V_2 ) ,
V_147 -> V_159 ,
V_147 -> V_150 ,
V_161 ) ;
} else {
F_67 ( F_39 ( V_2 ) ,
V_147 -> V_159 ,
V_147 -> V_150 ,
V_161 ) ;
}
}
}
exit:
return V_141 ;
}
int F_68 ( struct V_1 * V_2 , struct V_139 * V_140 )
__releases( &ring->lock
int F_69 ( struct V_1 * V_2 , unsigned int V_63 )
{
int V_55 = 0 ;
V_55 = V_2 -> V_66 . V_133 ( V_2 -> V_68 , V_63 ) ;
if ( V_55 < 0 )
goto V_65;
V_2 -> V_134 = V_63 ;
V_65:
return V_55 ;
}
int F_70 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_183 * V_184 = NULL ;
unsigned int V_10 = 0U ;
V_2 -> V_130 . V_132 = 0U ;
F_71 (ha, ndev) {
F_27 ( V_2 -> V_130 . V_131 [ V_10 ++ ] , V_184 -> V_185 ) ;
++ V_2 -> V_130 . V_132 ;
}
return V_2 -> V_66 . V_129 ( V_2 -> V_68 ,
V_2 -> V_130 . V_131 ,
V_2 -> V_130 . V_132 ) ;
}
int F_72 ( struct V_1 * V_2 , int V_186 )
{
int V_55 = 0 ;
if ( V_186 > V_2 -> V_17 . V_39 ) {
V_55 = - V_107 ;
goto V_65;
}
V_2 -> V_6 . V_39 = V_186 ;
V_65:
return V_55 ;
}
int F_73 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
return V_2 -> V_66 . V_187 ( V_2 -> V_68 , V_54 -> V_109 ) ;
}
unsigned int F_74 ( struct V_1 * V_2 )
{
return V_2 -> V_57 . V_70 ;
}
int F_75 ( struct V_1 * V_2 , struct V_188 * V_189 , void * V_190 )
{
T_4 * V_191 = V_190 ;
int V_55 = 0 ;
V_189 -> V_158 = 1 ;
V_55 = V_2 -> V_66 . V_192 ( V_2 -> V_68 ,
& V_2 -> V_17 , V_191 ) ;
if ( V_55 < 0 )
goto V_65;
V_65:
return V_55 ;
}
int F_76 ( struct V_1 * V_2 )
{
return V_2 -> V_17 . V_193 ;
}
void F_77 ( struct V_1 * V_2 , T_5 * V_160 )
{
struct V_87 * V_73 = NULL ;
unsigned int V_10 = 0U ;
unsigned int V_132 = 0U ;
int V_55 = 0 ;
V_55 = V_2 -> V_66 . V_194 ( V_2 -> V_68 , V_160 , & V_132 ) ;
if ( V_55 < 0 )
goto V_65;
V_160 += V_132 ;
V_132 = 0U ;
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_73 && V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] ) {
V_160 += V_132 ;
F_78 ( V_73 , V_160 , & V_132 ) ;
}
V_65: ;
( void ) V_55 ;
}
void F_79 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
V_196 -> V_197 . V_99 = V_198 ;
V_196 -> V_197 . V_199 = V_200 ;
V_196 -> V_197 . V_201 = V_2 -> V_6 . V_43 ;
F_80 ( V_196 , V_202 ) ;
if ( V_2 -> V_17 . V_41 & V_203 )
F_81 ( V_196 , V_202 ,
10000baseT_Full ) ;
if ( V_2 -> V_17 . V_41 & V_204 )
F_81 ( V_196 , V_202 ,
5000baseT_Full ) ;
if ( V_2 -> V_17 . V_41 & V_205 )
F_81 ( V_196 , V_202 ,
2500baseT_Full ) ;
if ( V_2 -> V_17 . V_41 & V_206 )
F_81 ( V_196 , V_202 ,
1000baseT_Full ) ;
if ( V_2 -> V_17 . V_41 & V_207 )
F_81 ( V_196 , V_202 ,
100baseT_Full ) ;
if ( V_2 -> V_17 . V_37 )
F_81 ( V_196 , V_202 ,
V_208 ) ;
F_81 ( V_196 , V_202 , V_209 ) ;
F_81 ( V_196 , V_202 , V_210 ) ;
F_80 ( V_196 , V_211 ) ;
if ( V_2 -> V_6 . V_43 )
F_81 ( V_196 , V_211 , V_209 ) ;
if ( V_2 -> V_6 . V_41 & V_203 )
F_81 ( V_196 , V_211 ,
10000baseT_Full ) ;
if ( V_2 -> V_6 . V_41 & V_204 )
F_81 ( V_196 , V_211 ,
5000baseT_Full ) ;
if ( V_2 -> V_6 . V_41 & V_205 )
F_81 ( V_196 , V_211 ,
2500baseT_Full ) ;
if ( V_2 -> V_6 . V_41 & V_206 )
F_81 ( V_196 , V_211 ,
1000baseT_Full ) ;
if ( V_2 -> V_6 . V_41 & V_207 )
F_81 ( V_196 , V_211 ,
100baseT_Full ) ;
if ( V_2 -> V_6 . V_37 )
F_81 ( V_196 , V_211 ,
V_208 ) ;
F_81 ( V_196 , V_211 , V_210 ) ;
}
int F_82 ( struct V_1 * V_2 ,
const struct V_195 * V_196 )
{
T_4 V_212 = 0U ;
T_4 V_213 = 0U ;
int V_55 = 0 ;
if ( V_196 -> V_197 . V_201 == V_214 ) {
V_213 = V_2 -> V_17 . V_41 ;
V_2 -> V_6 . V_43 = true ;
} else {
V_212 = V_196 -> V_197 . V_212 ;
switch ( V_212 ) {
case V_215 :
V_213 = V_207 ;
break;
case V_216 :
V_213 = V_206 ;
break;
case V_217 :
V_213 = V_205 ;
break;
case V_218 :
V_213 = V_204 ;
break;
case V_219 :
V_213 = V_203 ;
break;
default:
V_55 = - 1 ;
goto V_65;
break;
}
if ( ! ( V_2 -> V_17 . V_41 & V_213 ) ) {
V_55 = - 1 ;
goto V_65;
}
V_2 -> V_6 . V_43 = false ;
}
V_55 = V_2 -> V_66 . V_220 ( V_2 -> V_68 , V_213 ) ;
if ( V_55 < 0 )
goto V_65;
V_2 -> V_6 . V_41 = V_213 ;
V_65:
return V_55 ;
}
struct V_4 * F_83 ( struct V_1 * V_2 )
{
return & V_2 -> V_6 ;
}
T_4 F_84 ( struct V_1 * V_2 )
{
T_4 V_221 = 0U ;
V_2 -> V_66 . V_222 ( V_2 -> V_68 , & V_221 ) ;
return V_221 ;
}
int F_85 ( struct V_1 * V_2 )
{
struct V_87 * V_73 = NULL ;
unsigned int V_10 = 0U ;
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] )
F_28 ( V_2 , V_10 ) ;
F_86 ( & V_2 -> V_84 ) ;
V_2 -> V_66 . V_223 ( V_2 -> V_68 , V_138 ) ;
if ( V_2 -> V_6 . V_26 )
F_86 ( & V_2 -> V_89 ) ;
else
F_87 ( V_2 -> V_49 ) ;
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] )
F_88 ( V_73 ) ;
return V_2 -> V_66 . V_224 ( V_2 -> V_68 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_87 * V_73 = NULL ;
unsigned int V_10 = 0U ;
if ( ! V_2 )
goto V_65;
for ( V_10 = 0U , V_73 = V_2 -> V_73 [ 0 ] ;
V_2 -> V_88 > V_10 ; ++ V_10 , V_73 = V_2 -> V_73 [ V_10 ] )
F_90 ( V_73 ) ;
if ( V_2 -> V_125 == V_126 ) {
( void ) V_2 -> V_66 . V_225 ( V_2 -> V_68 ) ;
} else {
( void ) V_2 -> V_66 . V_226 ( V_2 -> V_68 ,
V_2 -> V_125 ) ;
}
V_65: ;
}
void F_24 ( struct V_1 * V_2 )
{
unsigned int V_10 = 0U ;
if ( ! V_2 )
goto V_65;
for ( V_10 = F_14 ( V_2 -> V_73 ) ; V_10 -- ; ) {
if ( V_2 -> V_73 [ V_10 ] ) {
F_91 ( V_2 -> V_73 [ V_10 ] ) ;
V_2 -> V_73 [ V_10 ] = NULL ;
}
}
V_65: ;
}
int F_92 ( struct V_1 * V_2 , T_6 * V_227 )
{
int V_55 = 0 ;
if ( ! F_35 ( V_2 -> V_54 ) ) {
V_55 = 0 ;
goto V_228;
}
F_93 () ;
if ( V_227 -> V_229 & V_230 || V_227 -> V_229 & V_231 ) {
V_2 -> V_125 = V_232 ;
F_94 ( V_2 -> V_54 ) ;
F_95 ( V_2 -> V_54 ) ;
V_55 = F_85 ( V_2 ) ;
if ( V_55 < 0 )
goto V_65;
F_89 ( V_2 ) ;
} else {
V_55 = F_40 ( V_2 ) ;
if ( V_55 < 0 )
goto V_65;
V_55 = F_44 ( V_2 ) ;
if ( V_55 < 0 )
goto V_65;
F_96 ( V_2 -> V_54 ) ;
F_97 ( V_2 -> V_54 ) ;
}
V_65:
F_98 () ;
V_228:
return V_55 ;
}
