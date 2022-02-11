long F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
unsigned long V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
long V_8 = V_9 ;
if ( V_2 ) {
V_8 = * V_2 ;
if ( V_8 < V_10 )
V_8 = V_10 ;
}
V_3 = 0 ;
if ( V_8 != V_9 ) {
V_3 = F_2 ( V_11 | V_12 | V_13 |
V_14 , V_8 - V_15 ) ;
if ( ! V_3 )
-- V_8 ;
}
if ( ! V_3 ) {
V_7 = F_3 () ;
if ( V_7 ) {
V_3 = ( V_16 ) V_7 -> V_17 ;
V_1 -> V_18 . V_19 = V_7 ;
V_8 = V_9 ;
}
}
while ( ! V_3 && V_8 > V_10 ) {
V_3 = F_2 ( V_11 | V_12 | V_13 |
V_14 , V_8 - V_15 ) ;
if ( ! V_3 )
-- V_8 ;
}
if ( ! V_3 )
return - V_20 ;
V_1 -> V_18 . V_21 = V_3 ;
V_1 -> V_18 . V_22 = V_8 ;
V_1 -> V_18 . V_23 = 1ul << ( V_8 - 4 ) ;
V_1 -> V_18 . V_24 = ( 1ul << ( V_8 - 7 ) ) - 1 ;
V_5 = F_4 ( sizeof( struct V_4 ) * V_1 -> V_18 . V_23 ) ;
if ( ! V_5 ) {
F_5 ( L_1 ) ;
goto V_25;
}
V_1 -> V_18 . V_26 = V_5 ;
V_1 -> V_18 . V_27 = F_6 ( V_3 ) | ( V_8 - 18 ) ;
F_7 ( L_2 ,
V_3 , V_8 , V_1 -> V_18 . V_28 ) ;
if ( V_2 )
* V_2 = V_8 ;
return 0 ;
V_25:
if ( V_1 -> V_18 . V_19 )
F_8 ( V_1 -> V_18 . V_19 ) ;
else
F_9 ( V_3 , V_8 - V_15 ) ;
return - V_20 ;
}
long F_10 ( struct V_1 * V_1 , T_1 * V_2 )
{
long V_29 = - V_30 ;
long V_8 ;
F_11 ( & V_1 -> V_31 ) ;
if ( V_1 -> V_18 . V_32 ) {
V_1 -> V_18 . V_32 = 0 ;
F_12 () ;
if ( F_13 ( & V_1 -> V_18 . V_33 ) ) {
V_1 -> V_18 . V_32 = 1 ;
goto V_34;
}
}
if ( V_1 -> V_18 . V_21 ) {
V_8 = V_1 -> V_18 . V_22 ;
memset ( ( void * ) V_1 -> V_18 . V_21 , 0 , 1ul << V_8 ) ;
memset ( V_1 -> V_18 . V_35 , 0xff , sizeof( V_1 -> V_18 . V_35 ) ) ;
* V_2 = V_8 ;
V_29 = 0 ;
} else {
V_29 = F_1 ( V_1 , V_2 ) ;
V_8 = * V_2 ;
}
V_34:
F_14 ( & V_1 -> V_31 ) ;
return V_29 ;
}
void F_15 ( struct V_1 * V_1 )
{
F_16 ( V_1 -> V_18 . V_28 ) ;
F_17 ( V_1 -> V_18 . V_26 ) ;
if ( V_1 -> V_18 . V_19 )
F_8 ( V_1 -> V_18 . V_19 ) ;
else
F_9 ( V_1 -> V_18 . V_21 ,
V_1 -> V_18 . V_22 - V_15 ) ;
}
static inline unsigned long F_18 ( unsigned long V_36 )
{
return ( V_36 > 0x1000 ) ? V_37 : 0 ;
}
static inline unsigned long F_19 ( unsigned long V_36 )
{
return ( V_36 == 0x10000 ) ? 0x1000 : 0 ;
}
void F_20 ( struct V_38 * V_39 , struct V_40 * V_41 ,
unsigned long V_42 )
{
unsigned long V_43 ;
unsigned long V_44 ;
unsigned long V_45 , V_46 ;
unsigned long V_47 , V_48 ;
unsigned long V_49 ;
unsigned long V_50 , V_51 ;
long V_52 ;
struct V_1 * V_1 = V_39 -> V_1 ;
V_49 = 1ul << V_42 ;
V_44 = V_41 -> V_44 >> ( V_42 - V_15 ) ;
if ( V_44 > 1ul << ( 40 - V_42 ) )
V_44 = 1ul << ( 40 - V_42 ) ;
if ( V_44 > V_1 -> V_18 . V_24 + 1 )
V_44 = V_1 -> V_18 . V_24 + 1 ;
V_50 = V_53 | ( V_54 << ( 40 - 16 ) ) |
V_55 | F_18 ( V_49 ) ;
V_51 = F_19 ( V_49 ) |
V_56 | V_57 | V_58 | V_59 ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
V_47 = V_43 << V_42 ;
V_48 = ( V_43 ^ ( V_54 ^ ( V_54 << 25 ) ) ) & V_1 -> V_18 . V_24 ;
V_48 = ( V_48 << 3 ) + 7 ;
V_45 = V_50 | ( ( V_47 >> 16 ) & ~ 0x7fUL ) ;
V_46 = V_51 | V_47 ;
V_52 = F_21 ( V_39 , V_60 , V_48 , V_45 , V_46 ) ;
if ( V_52 != V_61 ) {
F_5 ( L_3 ,
V_47 , V_52 ) ;
break;
}
}
}
int F_22 ( void )
{
unsigned long V_62 , V_63 ;
if ( ! F_23 ( V_64 ) )
return - V_65 ;
if ( F_23 ( V_66 ) ) {
V_62 = F_24 ( V_67 ) ;
V_63 = V_68 ;
} else {
V_62 = 0 ;
V_63 = V_69 ;
}
F_25 ( V_63 + 1 ) ;
F_26 ( V_62 ) ;
F_26 ( V_63 ) ;
return 0 ;
}
void F_27 ( struct V_38 * V_39 )
{
}
static void F_28 ( struct V_38 * V_39 )
{
F_29 ( V_39 , V_70 | V_71 ) ;
}
static long F_30 ( struct V_1 * V_1 , unsigned long V_72 ,
struct V_40 * V_41 ,
unsigned long V_49 )
{
unsigned long V_73 ;
long V_74 , V_29 ;
struct V_75 * V_75 , * V_76 , * V_77 [ 1 ] ;
unsigned long V_78 , V_36 ;
unsigned long * V_79 ;
unsigned int V_80 , V_81 , V_82 ;
struct V_83 * V_84 ;
unsigned long V_85 , V_43 , V_44 ;
V_79 = V_1 -> V_18 . V_86 [ V_41 -> V_87 ] ;
if ( ! V_79 )
return - V_65 ;
if ( V_79 [ V_72 - V_41 -> V_88 ] )
return 0 ;
V_80 = 0 ;
V_81 = 0 ;
V_75 = NULL ;
V_36 = V_49 ;
V_29 = - V_65 ;
V_73 = F_31 ( V_41 , V_72 ) ;
V_74 = F_32 ( V_73 , 1 , 1 , V_77 ) ;
if ( V_74 != 1 ) {
F_33 ( & V_89 -> V_90 -> V_91 ) ;
V_84 = F_34 ( V_89 -> V_90 , V_73 ) ;
if ( ! V_84 || V_84 -> V_92 > V_73 ||
V_73 + V_49 > V_84 -> V_93 ||
! ( V_84 -> V_94 & V_95 ) )
goto V_96;
V_80 = F_35 ( F_36 ( V_84 -> V_97 ) ) ;
V_85 = V_84 -> V_98 + ( ( V_73 - V_84 -> V_92 ) >> V_15 ) ;
if ( V_49 > V_99 && ( V_85 & ( ( V_49 >> V_15 ) - 1 ) ) )
goto V_96;
F_37 ( & V_89 -> V_90 -> V_91 ) ;
} else {
V_75 = V_77 [ 0 ] ;
V_81 = V_100 ;
V_78 = V_99 ;
if ( F_38 ( V_75 ) ) {
V_76 = F_39 ( V_75 ) ;
V_78 <<= F_40 ( V_76 ) ;
if ( V_78 > V_49 && F_41 ( V_41 , V_78 ) &&
! ( V_41 -> V_101 & ( V_78 - 1 ) ) ) {
V_73 &= ~ ( V_78 - 1 ) ;
V_36 = V_78 ;
F_42 ( V_76 ) ;
F_43 ( V_75 ) ;
V_75 = V_76 ;
}
}
if ( V_78 < V_49 )
goto V_34;
V_85 = F_44 ( V_75 ) ;
}
V_44 = V_36 >> V_15 ;
V_82 = F_45 ( V_44 ) ;
V_79 += ( V_72 - V_41 -> V_88 ) & ~ ( V_44 - 1 ) ;
F_46 ( & V_1 -> V_18 . V_102 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
if ( ! V_79 [ V_43 ] ) {
V_79 [ V_43 ] = ( ( V_85 + V_43 ) << V_15 ) +
V_81 + V_80 + V_82 ;
V_81 = 0 ;
}
}
F_47 ( & V_1 -> V_18 . V_102 ) ;
V_29 = 0 ;
V_34:
if ( V_81 )
F_43 ( V_75 ) ;
return V_29 ;
V_96:
F_37 ( & V_89 -> V_90 -> V_91 ) ;
return V_29 ;
}
long F_21 ( struct V_38 * V_39 , unsigned long V_103 ,
long V_104 , unsigned long V_105 , unsigned long V_106 )
{
struct V_1 * V_1 = V_39 -> V_1 ;
unsigned long V_49 , V_107 , V_72 ;
struct V_40 * V_41 ;
long V_52 ;
if ( V_1 -> V_18 . V_108 )
goto V_109;
V_49 = F_48 ( V_105 , V_106 ) ;
if ( ! V_49 )
return V_110 ;
V_105 &= ~ ( V_111 | V_112 | V_113 ) ;
V_107 = ( V_106 & V_114 ) & ~ ( V_49 - 1 ) ;
V_72 = V_107 >> V_15 ;
V_41 = F_49 ( V_1 , V_72 ) ;
if ( V_41 && ! ( V_41 -> V_103 & V_115 ) ) {
if ( ! F_41 ( V_41 , V_49 ) )
return V_110 ;
if ( F_30 ( V_1 , V_72 , V_41 , V_49 ) < 0 )
return V_110 ;
}
V_109:
F_50 () ;
V_39 -> V_18 . V_116 = V_89 -> V_90 -> V_117 ;
V_52 = F_51 ( V_39 , V_103 , V_104 , V_105 , V_106 ) ;
F_52 () ;
if ( V_52 == V_118 ) {
F_5 ( L_4 ) ;
V_52 = V_119 ;
}
return V_52 ;
}
static struct V_120 * F_53 ( struct V_38 * V_39 ,
T_2 V_121 )
{
T_3 V_122 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_39 -> V_18 . V_123 ; V_43 ++ ) {
if ( ! ( V_39 -> V_18 . V_124 [ V_43 ] . V_125 & V_126 ) )
continue;
if ( V_39 -> V_18 . V_124 [ V_43 ] . V_127 & V_128 )
V_122 = V_129 ;
else
V_122 = V_130 ;
if ( ( ( V_39 -> V_18 . V_124 [ V_43 ] . V_125 ^ V_121 ) & V_122 ) == 0 )
return & V_39 -> V_18 . V_124 [ V_43 ] ;
}
return NULL ;
}
static unsigned long F_54 ( unsigned long V_131 , unsigned long V_132 ,
unsigned long V_133 )
{
unsigned long V_134 ;
V_134 = F_48 ( V_131 , V_132 ) - 1 ;
return ( V_132 & V_114 & ~ V_134 ) | ( V_133 & V_134 ) ;
}
static int F_55 ( struct V_38 * V_39 , T_2 V_121 ,
struct V_135 * V_136 , bool V_137 )
{
struct V_1 * V_1 = V_39 -> V_1 ;
struct V_120 * V_138 ;
unsigned long V_139 ;
unsigned long V_140 , V_141 ;
unsigned long V_131 , V_142 ;
unsigned long * V_143 ;
int V_144 ;
int V_145 = V_39 -> V_18 . V_146 . V_147 & ( V_137 ? V_148 : V_149 ) ;
if ( V_145 ) {
V_138 = F_53 ( V_39 , V_121 ) ;
if ( ! V_138 )
return - V_65 ;
V_139 = V_138 -> V_127 ;
} else {
V_139 = V_39 -> V_1 -> V_18 . V_150 ;
}
V_144 = F_56 ( V_1 , V_121 , V_139 ,
V_113 | V_112 ) ;
if ( V_144 < 0 )
return - V_151 ;
V_143 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_144 << 4 ) ) ;
V_131 = V_143 [ 0 ] & ~ V_111 ;
V_142 = V_1 -> V_18 . V_26 [ V_144 ] . V_152 ;
asm volatile("lwsync" : : : "memory");
V_143 [ 0 ] = V_131 ;
V_136 -> V_121 = V_121 ;
V_136 -> V_153 = ( ( V_131 & V_154 ) << 4 ) | ( ( V_121 >> 12 ) & 0xfff ) ;
V_140 = V_142 & ( V_155 | V_156 ) ;
V_141 = ( V_39 -> V_18 . V_146 . V_147 & V_157 ) ? V_158 : V_159 ;
V_141 &= V_139 ;
V_136 -> V_160 = F_57 ( V_140 , V_141 ) ;
V_136 -> V_161 = F_58 ( V_140 , V_141 ) ;
V_136 -> V_162 = V_136 -> V_160 && ! ( V_142 & ( V_163 | V_164 ) ) ;
if ( V_137 && V_145 && F_23 ( V_66 ) ) {
int V_165 = F_59 ( V_142 , V_39 -> V_18 . V_166 ) ;
if ( V_165 & 1 )
V_136 -> V_160 = 0 ;
if ( V_165 & 2 )
V_136 -> V_161 = 0 ;
}
V_136 -> V_167 = F_54 ( V_131 , V_142 , V_121 ) ;
return 0 ;
}
static int F_60 ( unsigned int V_168 )
{
unsigned int V_122 ;
V_122 = 0x10000000 ;
if ( ( V_168 & 0xfc000000 ) == 0x7c000000 )
V_122 = 0x100 ;
return ( V_168 & V_122 ) != 0 ;
}
static int F_61 ( struct V_169 * V_170 , struct V_38 * V_39 ,
unsigned long V_107 , T_2 V_133 , int V_171 )
{
int V_52 ;
T_1 V_172 ;
unsigned long V_173 = F_62 ( V_39 ) ;
if ( V_39 -> V_18 . V_172 == V_174 ) {
V_52 = F_63 ( V_39 , & V_173 , sizeof( T_1 ) , & V_172 , false ) ;
if ( V_52 != V_175 || V_172 == V_174 )
return V_176 ;
V_39 -> V_18 . V_172 = V_172 ;
}
if ( F_60 ( V_39 -> V_18 . V_172 ) != ! ! V_171 )
return V_176 ;
V_39 -> V_18 . V_177 = V_107 ;
V_39 -> V_18 . V_178 = V_133 ;
return F_64 ( V_170 , V_39 ) ;
}
int F_65 ( struct V_169 * V_170 , struct V_38 * V_39 ,
unsigned long V_133 , unsigned long V_179 )
{
struct V_1 * V_1 = V_39 -> V_1 ;
unsigned long * V_143 , V_180 [ 3 ] , V_132 ;
unsigned long V_181 , V_49 , V_182 ;
unsigned long V_72 , V_183 , V_85 ;
struct V_40 * V_41 ;
unsigned long * V_184 ;
struct V_4 * V_5 ;
struct V_75 * V_75 , * V_77 [ 1 ] ;
long V_144 , V_52 , V_44 ;
unsigned long V_80 ;
unsigned int V_185 , V_186 ;
struct V_83 * V_84 ;
unsigned long V_187 ;
if ( V_133 != V_39 -> V_18 . V_188 )
return V_176 ;
V_144 = V_39 -> V_18 . V_189 ;
V_143 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_144 << 4 ) ) ;
V_5 = & V_1 -> V_18 . V_26 [ V_144 ] ;
F_66 () ;
while ( ! F_67 ( V_143 , V_111 ) )
F_68 () ;
V_180 [ 0 ] = V_143 [ 0 ] & ~ V_111 ;
V_180 [ 1 ] = V_143 [ 1 ] ;
V_180 [ 2 ] = V_132 = V_5 -> V_152 ;
asm volatile("lwsync" : : : "memory");
V_143 [ 0 ] = V_180 [ 0 ] ;
F_69 () ;
if ( V_180 [ 0 ] != V_39 -> V_18 . V_190 [ 0 ] ||
V_180 [ 1 ] != V_39 -> V_18 . V_190 [ 1 ] )
return V_176 ;
V_49 = F_48 ( V_180 [ 0 ] , V_132 ) ;
V_72 = F_70 ( V_132 , V_49 ) ;
V_41 = F_49 ( V_1 , V_72 ) ;
if ( ! V_41 || ( V_41 -> V_103 & V_115 ) ) {
unsigned long V_107 = ( V_72 << V_15 ) | ( V_133 & ( V_49 - 1 ) ) ;
return F_61 ( V_170 , V_39 , V_107 , V_133 ,
V_179 & V_191 ) ;
}
if ( ! V_1 -> V_18 . V_108 )
return - V_192 ;
V_181 = V_1 -> V_193 ;
F_71 () ;
V_80 = 0 ;
V_85 = 0 ;
V_75 = NULL ;
V_182 = V_99 ;
V_185 = ( V_179 & V_191 ) != 0 ;
V_186 = V_185 ;
V_183 = F_31 ( V_41 , V_72 ) ;
V_44 = F_32 ( V_183 , 1 , V_185 , V_77 ) ;
if ( V_44 < 1 ) {
F_33 ( & V_89 -> V_90 -> V_91 ) ;
V_84 = F_34 ( V_89 -> V_90 , V_183 ) ;
if ( V_84 && V_84 -> V_92 <= V_183 && V_183 + V_49 <= V_84 -> V_93 &&
( V_84 -> V_94 & V_95 ) ) {
V_85 = V_84 -> V_98 +
( ( V_183 - V_84 -> V_92 ) >> V_15 ) ;
V_182 = V_49 ;
V_80 = F_35 ( F_36 ( V_84 -> V_97 ) ) ;
V_186 = V_84 -> V_94 & V_194 ;
}
F_37 ( & V_89 -> V_90 -> V_91 ) ;
if ( ! V_85 )
return - V_192 ;
} else {
V_75 = V_77 [ 0 ] ;
if ( F_38 ( V_75 ) ) {
V_75 = F_39 ( V_75 ) ;
V_182 <<= F_40 ( V_75 ) ;
}
if ( ! V_185 && F_72 ( V_132 ) ) {
T_4 * V_195 , V_196 ;
F_50 () ;
V_195 = F_73 ( V_89 -> V_90 -> V_117 ,
V_183 , NULL ) ;
if ( V_195 && F_74 ( * V_195 ) ) {
V_196 = F_75 ( V_195 , 1 ) ;
if ( F_76 ( V_196 ) )
V_186 = 1 ;
}
F_52 () ;
}
V_85 = F_44 ( V_75 ) ;
}
V_52 = - V_192 ;
if ( V_49 > V_182 )
goto V_197;
if ( ! F_77 ( V_132 , V_80 ) ) {
if ( V_80 )
return - V_192 ;
V_132 = ( V_132 & ~ ( V_198 | V_199 | V_164 ) ) | V_58 ;
}
V_132 = ( V_132 & ~ ( V_155 - V_182 ) ) | ( V_85 << V_15 ) ;
if ( F_72 ( V_132 ) && ! V_186 )
V_132 = F_78 ( V_132 ) ;
V_52 = V_176 ;
F_66 () ;
while ( ! F_67 ( V_143 , V_111 ) )
F_68 () ;
if ( ( V_143 [ 0 ] & ~ V_111 ) != V_180 [ 0 ] || V_143 [ 1 ] != V_180 [ 1 ] ||
V_5 -> V_152 != V_180 [ 2 ] )
goto V_200;
V_180 [ 0 ] = ( V_180 [ 0 ] & ~ V_112 ) | V_113 ;
V_184 = & V_41 -> V_18 . V_184 [ V_72 - V_41 -> V_88 ] ;
F_79 ( V_184 ) ;
V_52 = V_176 ;
if ( F_80 ( V_39 , V_181 ) ) {
F_81 ( V_184 ) ;
goto V_200;
}
V_187 = * V_184 >> V_201 ;
V_132 &= V_187 | ~ ( V_56 | V_57 ) ;
if ( V_143 [ 0 ] & V_113 ) {
F_81 ( V_184 ) ;
V_143 [ 0 ] |= V_112 ;
F_82 ( V_1 , V_143 , V_144 ) ;
V_132 |= V_143 [ 1 ] & ( V_56 | V_57 ) ;
} else {
F_83 ( V_1 , V_5 , V_184 , V_144 , 0 ) ;
}
V_143 [ 1 ] = V_132 ;
F_84 () ;
V_143 [ 0 ] = V_180 [ 0 ] ;
asm volatile("ptesync" : : : "memory");
F_69 () ;
if ( V_75 && F_72 ( V_132 ) )
F_85 ( V_75 ) ;
V_197:
if ( V_75 ) {
F_43 ( V_77 [ 0 ] ) ;
}
return V_52 ;
V_200:
V_143 [ 0 ] &= ~ V_111 ;
F_69 () ;
goto V_197;
}
static int F_86 ( struct V_1 * V_1 ,
unsigned long V_73 ,
unsigned long V_202 ,
int (* F_87)( struct V_1 * V_1 ,
unsigned long * V_203 ,
unsigned long V_72 ) )
{
int V_52 ;
int V_204 = 0 ;
struct V_205 * V_206 ;
struct V_40 * V_41 ;
V_206 = V_205 ( V_1 ) ;
F_88 (memslot, slots) {
unsigned long V_207 , V_208 ;
T_5 V_72 , V_209 ;
V_207 = F_89 ( V_73 , V_41 -> V_101 ) ;
V_208 = F_90 ( V_202 , V_41 -> V_101 +
( V_41 -> V_44 << V_15 ) ) ;
if ( V_207 >= V_208 )
continue;
V_72 = F_91 ( V_207 , V_41 ) ;
V_209 = F_91 ( V_208 + V_99 - 1 , V_41 ) ;
for (; V_72 < V_209 ; ++ V_72 ) {
T_5 V_210 = V_72 - V_41 -> V_88 ;
V_52 = F_87 ( V_1 , & V_41 -> V_18 . V_184 [ V_210 ] , V_72 ) ;
V_204 |= V_52 ;
}
}
return V_204 ;
}
static int F_92 ( struct V_1 * V_1 , unsigned long V_183 ,
int (* F_87)( struct V_1 * V_1 , unsigned long * V_203 ,
unsigned long V_72 ) )
{
return F_86 ( V_1 , V_183 , V_183 + 1 , F_87 ) ;
}
static int F_93 ( struct V_1 * V_1 , unsigned long * V_203 ,
unsigned long V_72 )
{
struct V_4 * V_5 = V_1 -> V_18 . V_26 ;
unsigned long V_211 , V_43 , V_212 ;
unsigned long * V_143 ;
unsigned long V_106 , V_49 , V_187 ;
for (; ; ) {
F_79 ( V_203 ) ;
if ( ! ( * V_203 & V_213 ) ) {
F_81 ( V_203 ) ;
break;
}
V_43 = * V_203 & V_214 ;
V_143 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 << 4 ) ) ;
if ( ! F_67 ( V_143 , V_111 ) ) {
F_81 ( V_203 ) ;
while ( V_143 [ 0 ] & V_111 )
F_68 () ;
continue;
}
V_212 = V_5 [ V_43 ] . V_215 ;
if ( V_212 == V_43 ) {
* V_203 &= ~ ( V_213 | V_214 ) ;
} else {
V_211 = V_5 [ V_43 ] . V_216 ;
V_5 [ V_211 ] . V_215 = V_212 ;
V_5 [ V_212 ] . V_216 = V_211 ;
V_5 [ V_43 ] . V_215 = V_5 [ V_43 ] . V_216 = V_43 ;
* V_203 = ( * V_203 & ~ V_214 ) | V_212 ;
}
V_106 = V_5 [ V_43 ] . V_152 ;
V_49 = F_48 ( V_143 [ 0 ] , V_106 ) ;
if ( ( V_143 [ 0 ] & V_113 ) &&
F_70 ( V_106 , V_49 ) == V_72 ) {
V_143 [ 0 ] |= V_112 ;
F_82 ( V_1 , V_143 , V_43 ) ;
V_187 = V_143 [ 1 ] & ( V_56 | V_57 ) ;
* V_203 |= V_187 << V_201 ;
V_5 [ V_43 ] . V_152 = V_106 | V_187 ;
}
F_81 ( V_203 ) ;
V_143 [ 0 ] &= ~ V_111 ;
}
return 0 ;
}
int F_94 ( struct V_1 * V_1 , unsigned long V_183 )
{
if ( V_1 -> V_18 . V_108 )
F_92 ( V_1 , V_183 , F_93 ) ;
return 0 ;
}
int F_95 ( struct V_1 * V_1 , unsigned long V_73 , unsigned long V_202 )
{
if ( V_1 -> V_18 . V_108 )
F_86 ( V_1 , V_73 , V_202 , F_93 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_1 , unsigned long * V_203 ,
unsigned long V_72 )
{
struct V_4 * V_5 = V_1 -> V_18 . V_26 ;
unsigned long V_217 , V_43 , V_212 ;
unsigned long * V_143 ;
int V_52 = 0 ;
V_218:
F_79 ( V_203 ) ;
if ( * V_203 & V_219 ) {
* V_203 &= ~ V_219 ;
V_52 = 1 ;
}
if ( ! ( * V_203 & V_213 ) ) {
F_81 ( V_203 ) ;
return V_52 ;
}
V_43 = V_217 = * V_203 & V_214 ;
do {
V_143 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 << 4 ) ) ;
V_212 = V_5 [ V_43 ] . V_215 ;
if ( ! ( V_143 [ 1 ] & V_56 ) )
continue;
if ( ! F_67 ( V_143 , V_111 ) ) {
F_81 ( V_203 ) ;
while ( V_143 [ 0 ] & V_111 )
F_68 () ;
goto V_218;
}
if ( ( V_143 [ 0 ] & V_113 ) && ( V_143 [ 1 ] & V_56 ) ) {
F_97 ( V_1 , V_143 , V_43 ) ;
V_5 [ V_43 ] . V_152 |= V_56 ;
V_52 = 1 ;
}
V_143 [ 0 ] &= ~ V_111 ;
} while ( ( V_43 = V_212 ) != V_217 );
F_81 ( V_203 ) ;
return V_52 ;
}
int F_98 ( struct V_1 * V_1 , unsigned long V_183 )
{
if ( ! V_1 -> V_18 . V_108 )
return 0 ;
return F_92 ( V_1 , V_183 , F_96 ) ;
}
static int F_99 ( struct V_1 * V_1 , unsigned long * V_203 ,
unsigned long V_72 )
{
struct V_4 * V_5 = V_1 -> V_18 . V_26 ;
unsigned long V_217 , V_43 , V_212 ;
unsigned long * V_220 ;
int V_52 = 1 ;
if ( * V_203 & V_219 )
return 1 ;
F_79 ( V_203 ) ;
if ( * V_203 & V_219 )
goto V_34;
if ( * V_203 & V_213 ) {
V_43 = V_217 = * V_203 & V_214 ;
do {
V_220 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 << 4 ) ) ;
V_212 = V_5 [ V_43 ] . V_215 ;
if ( V_220 [ 1 ] & V_56 )
goto V_34;
} while ( ( V_43 = V_212 ) != V_217 );
}
V_52 = 0 ;
V_34:
F_81 ( V_203 ) ;
return V_52 ;
}
int F_100 ( struct V_1 * V_1 , unsigned long V_183 )
{
if ( ! V_1 -> V_18 . V_108 )
return 0 ;
return F_92 ( V_1 , V_183 , F_99 ) ;
}
void F_101 ( struct V_1 * V_1 , unsigned long V_183 , T_4 V_196 )
{
if ( ! V_1 -> V_18 . V_108 )
return;
F_92 ( V_1 , V_183 , F_93 ) ;
}
static int F_102 ( struct V_1 * V_1 , unsigned long * V_203 )
{
struct V_4 * V_5 = V_1 -> V_18 . V_26 ;
unsigned long V_217 , V_43 , V_212 ;
unsigned long * V_143 ;
int V_52 = 0 ;
V_218:
F_79 ( V_203 ) ;
if ( * V_203 & V_221 ) {
* V_203 &= ~ V_221 ;
V_52 = 1 ;
}
if ( ! ( * V_203 & V_213 ) ) {
F_81 ( V_203 ) ;
return V_52 ;
}
V_43 = V_217 = * V_203 & V_214 ;
do {
V_143 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 << 4 ) ) ;
V_212 = V_5 [ V_43 ] . V_215 ;
if ( ! ( V_143 [ 1 ] & V_57 ) )
continue;
if ( ! F_67 ( V_143 , V_111 ) ) {
F_81 ( V_203 ) ;
while ( V_143 [ 0 ] & V_111 )
F_68 () ;
goto V_218;
}
if ( ( V_143 [ 0 ] & V_113 ) && ( V_143 [ 1 ] & V_57 ) ) {
V_143 [ 0 ] |= V_112 ;
F_82 ( V_1 , V_143 , V_43 ) ;
V_143 [ 1 ] &= ~ V_57 ;
F_84 () ;
V_143 [ 0 ] = ( V_143 [ 0 ] & ~ V_112 ) | V_113 ;
V_5 [ V_43 ] . V_152 |= V_57 ;
V_52 = 1 ;
}
V_143 [ 0 ] &= ~ V_111 ;
} while ( ( V_43 = V_212 ) != V_217 );
F_81 ( V_203 ) ;
return V_52 ;
}
long F_103 ( struct V_1 * V_1 , struct V_40 * V_41 )
{
unsigned long V_43 ;
unsigned long * V_203 , * V_222 ;
F_66 () ;
V_203 = V_41 -> V_18 . V_184 ;
V_222 = V_41 -> V_223 ;
for ( V_43 = 0 ; V_43 < V_41 -> V_44 ; ++ V_43 ) {
if ( F_102 ( V_1 , V_203 ) )
F_104 ( V_43 , V_222 ) ;
++ V_203 ;
}
F_69 () ;
return 0 ;
}
void * F_105 ( struct V_1 * V_1 , unsigned long V_107 ,
unsigned long * V_224 )
{
struct V_40 * V_41 ;
unsigned long V_72 = V_107 >> V_15 ;
struct V_75 * V_75 , * V_77 [ 1 ] ;
int V_44 ;
unsigned long V_183 , V_49 , V_225 ;
unsigned long V_226 ;
unsigned long * V_79 ;
V_41 = F_49 ( V_1 , V_72 ) ;
if ( ! V_41 || ( V_41 -> V_103 & V_115 ) )
return NULL ;
if ( ! V_1 -> V_18 . V_108 ) {
V_79 = V_1 -> V_18 . V_86 [ V_41 -> V_87 ] ;
if ( ! V_79 )
return NULL ;
V_79 += V_72 - V_41 -> V_88 ;
V_226 = * V_79 ;
if ( ! V_226 ) {
if ( F_30 ( V_1 , V_72 , V_41 ,
V_99 ) < 0 )
return NULL ;
V_226 = * V_79 ;
}
V_75 = F_106 ( V_226 >> V_15 ) ;
F_42 ( V_75 ) ;
} else {
V_183 = F_31 ( V_41 , V_72 ) ;
V_44 = F_32 ( V_183 , 1 , 1 , V_77 ) ;
if ( V_44 < 1 )
return NULL ;
V_75 = V_77 [ 0 ] ;
}
V_49 = V_99 ;
if ( F_38 ( V_75 ) ) {
V_75 = F_39 ( V_75 ) ;
V_49 <<= F_40 ( V_75 ) ;
}
V_225 = V_107 & ( V_49 - 1 ) ;
if ( V_224 )
* V_224 = V_49 - V_225 ;
return F_107 ( V_75 ) + V_225 ;
}
void F_108 ( struct V_1 * V_1 , void * V_227 )
{
struct V_75 * V_75 = F_109 ( V_227 ) ;
F_43 ( V_75 ) ;
}
void F_110 ( struct V_38 * V_39 )
{
struct V_228 * V_229 = & V_39 -> V_18 . V_229 ;
if ( F_23 ( V_66 ) )
V_39 -> V_18 . V_123 = 32 ;
else
V_39 -> V_18 . V_123 = 64 ;
V_229 -> V_230 = F_55 ;
V_229 -> V_231 = F_28 ;
V_39 -> V_18 . V_232 |= V_233 ;
}
