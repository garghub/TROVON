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
F_14 ( V_1 ) ;
F_15 ( & V_1 -> V_18 . V_35 ) ;
* V_2 = V_8 ;
V_29 = 0 ;
} else {
V_29 = F_1 ( V_1 , V_2 ) ;
V_8 = * V_2 ;
}
V_34:
F_16 ( & V_1 -> V_31 ) ;
return V_29 ;
}
void F_17 ( struct V_1 * V_1 )
{
F_18 ( V_1 -> V_18 . V_28 ) ;
F_19 ( V_1 -> V_18 . V_26 ) ;
if ( V_1 -> V_18 . V_19 )
F_8 ( V_1 -> V_18 . V_19 ) ;
else
F_9 ( V_1 -> V_18 . V_21 ,
V_1 -> V_18 . V_22 - V_15 ) ;
}
static inline unsigned long F_20 ( unsigned long V_36 )
{
return ( V_36 > 0x1000 ) ? V_37 : 0 ;
}
static inline unsigned long F_21 ( unsigned long V_36 )
{
return ( V_36 == 0x10000 ) ? 0x1000 : 0 ;
}
void F_22 ( struct V_38 * V_39 , struct V_40 * V_41 ,
unsigned long V_42 )
{
unsigned long V_43 ;
unsigned long V_44 ;
unsigned long V_45 , V_46 ;
unsigned long V_47 , V_48 ;
unsigned long V_49 ;
unsigned long V_50 , V_51 ;
unsigned long V_52 ;
long V_53 ;
struct V_1 * V_1 = V_39 -> V_1 ;
V_49 = 1ul << V_42 ;
V_44 = V_41 -> V_44 >> ( V_42 - V_15 ) ;
if ( V_44 > 1ul << ( 40 - V_42 ) )
V_44 = 1ul << ( 40 - V_42 ) ;
if ( V_44 > V_1 -> V_18 . V_24 + 1 )
V_44 = V_1 -> V_18 . V_24 + 1 ;
V_50 = V_54 | ( V_55 << ( 40 - 16 ) ) |
V_56 | F_20 ( V_49 ) ;
V_51 = F_21 ( V_49 ) |
V_57 | V_58 | V_59 | V_60 ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
V_47 = V_43 << V_42 ;
V_48 = ( V_43 ^ ( V_55 ^ ( V_55 << 25 ) ) ) & V_1 -> V_18 . V_24 ;
V_48 = ( V_48 << 3 ) + 7 ;
V_45 = V_50 | ( ( V_47 >> 16 ) & ~ 0x7fUL ) ;
V_46 = V_51 | V_47 ;
V_53 = F_23 ( V_1 , V_61 , V_48 , V_45 , V_46 ,
& V_52 ) ;
if ( V_53 != V_62 ) {
F_5 ( L_3 ,
V_47 , V_53 ) ;
break;
}
}
}
int F_24 ( void )
{
unsigned long V_63 , V_64 ;
if ( ! F_25 ( V_65 ) )
return - V_66 ;
if ( F_25 ( V_67 ) ) {
V_63 = F_26 ( V_68 ) ;
V_64 = V_69 ;
} else {
V_63 = 0 ;
V_64 = V_70 ;
}
F_27 ( V_64 + 1 ) ;
F_28 ( V_63 ) ;
F_28 ( V_64 ) ;
return 0 ;
}
void F_29 ( struct V_38 * V_39 )
{
}
static void F_30 ( struct V_38 * V_39 )
{
F_31 ( V_39 , V_71 | V_72 ) ;
}
static long F_32 ( struct V_1 * V_1 , unsigned long V_73 ,
struct V_40 * V_41 ,
unsigned long V_49 )
{
unsigned long V_74 ;
long V_75 , V_29 ;
struct V_76 * V_76 , * V_77 , * V_78 [ 1 ] ;
unsigned long V_79 , V_36 ;
unsigned long * V_80 ;
unsigned int V_81 , V_82 , V_83 ;
struct V_84 * V_85 ;
unsigned long V_86 , V_43 , V_44 ;
V_80 = V_41 -> V_18 . V_87 ;
if ( ! V_80 )
return - V_66 ;
if ( V_80 [ V_73 - V_41 -> V_88 ] )
return 0 ;
V_81 = 0 ;
V_82 = 0 ;
V_76 = NULL ;
V_36 = V_49 ;
V_29 = - V_66 ;
V_74 = F_33 ( V_41 , V_73 ) ;
V_75 = F_34 ( V_74 , 1 , 1 , V_78 ) ;
if ( V_75 != 1 ) {
F_35 ( & V_89 -> V_90 -> V_91 ) ;
V_85 = F_36 ( V_89 -> V_90 , V_74 ) ;
if ( ! V_85 || V_85 -> V_92 > V_74 ||
V_74 + V_49 > V_85 -> V_93 ||
! ( V_85 -> V_94 & V_95 ) )
goto V_96;
V_81 = F_37 ( F_38 ( V_85 -> V_97 ) ) ;
V_86 = V_85 -> V_98 + ( ( V_74 - V_85 -> V_92 ) >> V_15 ) ;
if ( V_49 > V_99 && ( V_86 & ( ( V_49 >> V_15 ) - 1 ) ) )
goto V_96;
F_39 ( & V_89 -> V_90 -> V_91 ) ;
} else {
V_76 = V_78 [ 0 ] ;
V_82 = V_100 ;
V_79 = V_99 ;
if ( F_40 ( V_76 ) ) {
V_77 = F_41 ( V_76 ) ;
V_79 <<= F_42 ( V_77 ) ;
if ( V_79 > V_49 && F_43 ( V_41 , V_79 ) &&
! ( V_41 -> V_101 & ( V_79 - 1 ) ) ) {
V_74 &= ~ ( V_79 - 1 ) ;
V_36 = V_79 ;
F_44 ( V_77 ) ;
F_45 ( V_76 ) ;
V_76 = V_77 ;
}
}
if ( V_79 < V_49 )
goto V_34;
V_86 = F_46 ( V_76 ) ;
}
V_44 = V_36 >> V_15 ;
V_83 = F_47 ( V_44 ) ;
V_80 += ( V_73 - V_41 -> V_88 ) & ~ ( V_44 - 1 ) ;
F_48 ( & V_1 -> V_18 . V_102 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
if ( ! V_80 [ V_43 ] ) {
V_80 [ V_43 ] = ( ( V_86 + V_43 ) << V_15 ) +
V_82 + V_81 + V_83 ;
V_82 = 0 ;
}
}
F_49 ( & V_1 -> V_18 . V_102 ) ;
V_29 = 0 ;
V_34:
if ( V_82 )
F_45 ( V_76 ) ;
return V_29 ;
V_96:
F_39 ( & V_89 -> V_90 -> V_91 ) ;
return V_29 ;
}
long F_23 ( struct V_1 * V_1 , unsigned long V_103 ,
long V_104 , unsigned long V_105 ,
unsigned long V_106 , unsigned long * V_107 )
{
unsigned long V_49 , V_108 , V_73 ;
struct V_40 * V_41 ;
long V_53 ;
if ( V_1 -> V_18 . V_109 )
goto V_110;
V_49 = F_50 ( V_105 , V_106 ) ;
if ( ! V_49 )
return V_111 ;
V_105 &= ~ ( V_112 | V_113 | V_114 ) ;
V_108 = ( V_106 & V_115 ) & ~ ( V_49 - 1 ) ;
V_73 = V_108 >> V_15 ;
V_41 = F_51 ( V_1 , V_73 ) ;
if ( V_41 && ! ( V_41 -> V_103 & V_116 ) ) {
if ( ! F_43 ( V_41 , V_49 ) )
return V_111 ;
if ( F_32 ( V_1 , V_73 , V_41 , V_49 ) < 0 )
return V_111 ;
}
V_110:
F_52 () ;
V_53 = F_53 ( V_1 , V_103 , V_104 , V_105 , V_106 ,
V_89 -> V_90 -> V_117 , false , V_107 ) ;
F_54 () ;
if ( V_53 == V_118 ) {
F_5 ( L_4 ) ;
V_53 = V_119 ;
}
return V_53 ;
}
long F_55 ( struct V_38 * V_39 , unsigned long V_103 ,
long V_104 , unsigned long V_105 ,
unsigned long V_106 )
{
return F_23 ( V_39 -> V_1 , V_103 , V_104 ,
V_105 , V_106 , & V_39 -> V_18 . V_120 [ 4 ] ) ;
}
static struct V_121 * F_56 ( struct V_38 * V_39 ,
T_2 V_122 )
{
T_3 V_123 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_39 -> V_18 . V_124 ; V_43 ++ ) {
if ( ! ( V_39 -> V_18 . V_125 [ V_43 ] . V_126 & V_127 ) )
continue;
if ( V_39 -> V_18 . V_125 [ V_43 ] . V_128 & V_129 )
V_123 = V_130 ;
else
V_123 = V_131 ;
if ( ( ( V_39 -> V_18 . V_125 [ V_43 ] . V_126 ^ V_122 ) & V_123 ) == 0 )
return & V_39 -> V_18 . V_125 [ V_43 ] ;
}
return NULL ;
}
static unsigned long F_57 ( unsigned long V_132 , unsigned long V_133 ,
unsigned long V_134 )
{
unsigned long V_135 ;
V_135 = F_50 ( V_132 , V_133 ) - 1 ;
return ( V_133 & V_115 & ~ V_135 ) | ( V_134 & V_135 ) ;
}
static int F_58 ( struct V_38 * V_39 , T_2 V_122 ,
struct V_136 * V_137 , bool V_138 )
{
struct V_1 * V_1 = V_39 -> V_1 ;
struct V_121 * V_139 ;
unsigned long V_140 ;
unsigned long V_141 , V_142 ;
unsigned long V_132 , V_143 ;
unsigned long * V_144 ;
int V_145 ;
int V_146 = V_39 -> V_18 . V_147 . V_148 & ( V_138 ? V_149 : V_150 ) ;
if ( V_146 ) {
V_139 = F_56 ( V_39 , V_122 ) ;
if ( ! V_139 )
return - V_66 ;
V_140 = V_139 -> V_128 ;
} else {
V_140 = V_39 -> V_1 -> V_18 . V_151 ;
}
V_145 = F_59 ( V_1 , V_122 , V_140 ,
V_114 | V_113 ) ;
if ( V_145 < 0 )
return - V_152 ;
V_144 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_145 << 4 ) ) ;
V_132 = V_144 [ 0 ] & ~ V_112 ;
V_143 = V_1 -> V_18 . V_26 [ V_145 ] . V_153 ;
asm volatile("lwsync" : : : "memory");
V_144 [ 0 ] = V_132 ;
V_137 -> V_122 = V_122 ;
V_137 -> V_154 = ( ( V_132 & V_155 ) << 4 ) | ( ( V_122 >> 12 ) & 0xfff ) ;
V_141 = V_143 & ( V_156 | V_157 ) ;
V_142 = ( V_39 -> V_18 . V_147 . V_148 & V_158 ) ? V_159 : V_160 ;
V_142 &= V_140 ;
V_137 -> V_161 = F_60 ( V_141 , V_142 ) ;
V_137 -> V_162 = F_61 ( V_141 , V_142 ) ;
V_137 -> V_163 = V_137 -> V_161 && ! ( V_143 & ( V_164 | V_165 ) ) ;
if ( V_138 && V_146 && F_25 ( V_67 ) ) {
int V_166 = F_62 ( V_143 , V_39 -> V_18 . V_167 ) ;
if ( V_166 & 1 )
V_137 -> V_161 = 0 ;
if ( V_166 & 2 )
V_137 -> V_162 = 0 ;
}
V_137 -> V_168 = F_57 ( V_132 , V_143 , V_122 ) ;
return 0 ;
}
static int F_63 ( unsigned int V_169 )
{
unsigned int V_123 ;
V_123 = 0x10000000 ;
if ( ( V_169 & 0xfc000000 ) == 0x7c000000 )
V_123 = 0x100 ;
return ( V_169 & V_123 ) != 0 ;
}
static int F_64 ( struct V_170 * V_171 , struct V_38 * V_39 ,
unsigned long V_108 , T_2 V_134 , int V_172 )
{
int V_53 ;
T_1 V_173 ;
unsigned long V_174 = F_65 ( V_39 ) ;
if ( V_39 -> V_18 . V_173 == V_175 ) {
V_53 = F_66 ( V_39 , & V_174 , sizeof( T_1 ) , & V_173 , false ) ;
if ( V_53 != V_176 || V_173 == V_175 )
return V_177 ;
V_39 -> V_18 . V_173 = V_173 ;
}
if ( F_63 ( V_39 -> V_18 . V_173 ) != ! ! V_172 )
return V_177 ;
V_39 -> V_18 . V_178 = V_108 ;
V_39 -> V_18 . V_179 = V_134 ;
return F_67 ( V_171 , V_39 ) ;
}
int F_68 ( struct V_170 * V_171 , struct V_38 * V_39 ,
unsigned long V_134 , unsigned long V_180 )
{
struct V_1 * V_1 = V_39 -> V_1 ;
unsigned long * V_144 , V_181 [ 3 ] , V_133 ;
unsigned long V_182 , V_49 , V_183 ;
unsigned long V_108 , V_73 , V_184 , V_86 ;
struct V_40 * V_41 ;
unsigned long * V_185 ;
struct V_4 * V_5 ;
struct V_76 * V_76 , * V_78 [ 1 ] ;
long V_145 , V_53 , V_44 ;
unsigned long V_81 ;
unsigned int V_186 , V_187 ;
struct V_84 * V_85 ;
unsigned long V_188 ;
if ( V_134 != V_39 -> V_18 . V_189 )
return V_177 ;
V_145 = V_39 -> V_18 . V_190 ;
V_144 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_145 << 4 ) ) ;
V_5 = & V_1 -> V_18 . V_26 [ V_145 ] ;
F_69 () ;
while ( ! F_70 ( V_144 , V_112 ) )
F_71 () ;
V_181 [ 0 ] = V_144 [ 0 ] & ~ V_112 ;
V_181 [ 1 ] = V_144 [ 1 ] ;
V_181 [ 2 ] = V_133 = V_5 -> V_153 ;
asm volatile("lwsync" : : : "memory");
V_144 [ 0 ] = V_181 [ 0 ] ;
F_72 () ;
if ( V_181 [ 0 ] != V_39 -> V_18 . V_191 [ 0 ] ||
V_181 [ 1 ] != V_39 -> V_18 . V_191 [ 1 ] )
return V_177 ;
V_49 = F_50 ( V_181 [ 0 ] , V_133 ) ;
V_108 = ( V_133 & V_115 & ~ ( V_49 - 1 ) ) | ( V_134 & ( V_49 - 1 ) ) ;
V_73 = V_108 >> V_15 ;
V_41 = F_51 ( V_1 , V_73 ) ;
if ( ! V_41 || ( V_41 -> V_103 & V_116 ) )
return F_64 ( V_171 , V_39 , V_108 , V_134 ,
V_180 & V_192 ) ;
if ( ! V_1 -> V_18 . V_109 )
return - V_193 ;
V_182 = V_1 -> V_194 ;
F_73 () ;
V_81 = 0 ;
V_86 = 0 ;
V_76 = NULL ;
V_183 = V_99 ;
V_186 = ( V_180 & V_192 ) != 0 ;
V_187 = V_186 ;
V_184 = F_33 ( V_41 , V_73 ) ;
V_44 = F_34 ( V_184 , 1 , V_186 , V_78 ) ;
if ( V_44 < 1 ) {
F_35 ( & V_89 -> V_90 -> V_91 ) ;
V_85 = F_36 ( V_89 -> V_90 , V_184 ) ;
if ( V_85 && V_85 -> V_92 <= V_184 && V_184 + V_49 <= V_85 -> V_93 &&
( V_85 -> V_94 & V_95 ) ) {
V_86 = V_85 -> V_98 +
( ( V_184 - V_85 -> V_92 ) >> V_15 ) ;
V_183 = V_49 ;
V_81 = F_37 ( F_38 ( V_85 -> V_97 ) ) ;
V_187 = V_85 -> V_94 & V_195 ;
}
F_39 ( & V_89 -> V_90 -> V_91 ) ;
if ( ! V_86 )
return - V_193 ;
} else {
V_76 = V_78 [ 0 ] ;
if ( F_40 ( V_76 ) ) {
V_76 = F_41 ( V_76 ) ;
V_183 <<= F_42 ( V_76 ) ;
}
if ( ! V_186 && F_74 ( V_133 ) ) {
T_4 * V_196 , V_197 ;
F_52 () ;
V_196 = F_75 ( V_89 -> V_90 -> V_117 ,
V_184 , NULL ) ;
if ( V_196 && F_76 ( * V_196 ) ) {
V_197 = F_77 ( V_196 , 1 ) ;
if ( F_78 ( V_197 ) )
V_187 = 1 ;
}
F_54 () ;
}
V_86 = F_46 ( V_76 ) ;
}
V_53 = - V_193 ;
if ( V_49 > V_183 )
goto V_198;
if ( ! F_79 ( V_133 , V_81 ) ) {
if ( V_81 )
return - V_193 ;
V_133 = ( V_133 & ~ ( V_199 | V_200 | V_165 ) ) | V_59 ;
}
V_133 = ( V_133 & ~ ( V_156 - V_183 ) ) | ( V_86 << V_15 ) ;
if ( F_74 ( V_133 ) && ! V_187 )
V_133 = F_80 ( V_133 ) ;
V_53 = V_177 ;
F_69 () ;
while ( ! F_70 ( V_144 , V_112 ) )
F_71 () ;
if ( ( V_144 [ 0 ] & ~ V_112 ) != V_181 [ 0 ] || V_144 [ 1 ] != V_181 [ 1 ] ||
V_5 -> V_153 != V_181 [ 2 ] )
goto V_201;
V_181 [ 0 ] = ( V_181 [ 0 ] & ~ V_113 ) | V_114 ;
V_185 = & V_41 -> V_18 . V_185 [ V_73 - V_41 -> V_88 ] ;
F_81 ( V_185 ) ;
V_53 = V_177 ;
if ( F_82 ( V_39 -> V_1 , V_182 ) ) {
F_83 ( V_185 ) ;
goto V_201;
}
V_188 = * V_185 >> V_202 ;
V_133 &= V_188 | ~ ( V_57 | V_58 ) ;
if ( V_144 [ 0 ] & V_114 ) {
F_83 ( V_185 ) ;
V_144 [ 0 ] |= V_113 ;
F_84 ( V_1 , V_144 , V_145 ) ;
V_133 |= V_144 [ 1 ] & ( V_57 | V_58 ) ;
} else {
F_85 ( V_1 , V_5 , V_185 , V_145 , 0 ) ;
}
V_144 [ 1 ] = V_133 ;
F_86 () ;
V_144 [ 0 ] = V_181 [ 0 ] ;
asm volatile("ptesync" : : : "memory");
F_72 () ;
if ( V_76 && F_74 ( V_133 ) )
F_87 ( V_76 ) ;
V_198:
if ( V_76 ) {
F_45 ( V_78 [ 0 ] ) ;
}
return V_53 ;
V_201:
V_144 [ 0 ] &= ~ V_112 ;
F_72 () ;
goto V_198;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_203 * V_204 ;
struct V_40 * V_41 ;
int V_205 ;
V_205 = F_88 ( & V_1 -> V_206 ) ;
V_204 = V_1 -> V_207 ;
F_89 (memslot, slots) {
memset ( V_41 -> V_18 . V_185 , 0 ,
V_41 -> V_44 * sizeof( * V_41 -> V_18 . V_185 ) ) ;
}
F_90 ( & V_1 -> V_206 , V_205 ) ;
}
static int F_91 ( struct V_1 * V_1 ,
unsigned long V_74 ,
unsigned long V_208 ,
int (* F_92)( struct V_1 * V_1 ,
unsigned long * V_209 ,
unsigned long V_73 ) )
{
int V_53 ;
int V_210 = 0 ;
struct V_203 * V_204 ;
struct V_40 * V_41 ;
V_204 = V_203 ( V_1 ) ;
F_89 (memslot, slots) {
unsigned long V_211 , V_212 ;
T_5 V_73 , V_213 ;
V_211 = F_93 ( V_74 , V_41 -> V_101 ) ;
V_212 = F_94 ( V_208 , V_41 -> V_101 +
( V_41 -> V_44 << V_15 ) ) ;
if ( V_211 >= V_212 )
continue;
V_73 = F_95 ( V_211 , V_41 ) ;
V_213 = F_95 ( V_212 + V_99 - 1 , V_41 ) ;
for (; V_73 < V_213 ; ++ V_73 ) {
T_5 V_214 = V_73 - V_41 -> V_88 ;
V_53 = F_92 ( V_1 , & V_41 -> V_18 . V_185 [ V_214 ] , V_73 ) ;
V_210 |= V_53 ;
}
}
return V_210 ;
}
static int F_96 ( struct V_1 * V_1 , unsigned long V_184 ,
int (* F_92)( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_73 ) )
{
return F_91 ( V_1 , V_184 , V_184 + 1 , F_92 ) ;
}
static int F_97 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_73 )
{
struct V_4 * V_5 = V_1 -> V_18 . V_26 ;
unsigned long V_215 , V_43 , V_216 ;
unsigned long * V_144 ;
unsigned long V_106 , V_49 , V_188 ;
for (; ; ) {
F_81 ( V_209 ) ;
if ( ! ( * V_209 & V_217 ) ) {
F_83 ( V_209 ) ;
break;
}
V_43 = * V_209 & V_218 ;
V_144 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 << 4 ) ) ;
if ( ! F_70 ( V_144 , V_112 ) ) {
F_83 ( V_209 ) ;
while ( V_144 [ 0 ] & V_112 )
F_71 () ;
continue;
}
V_216 = V_5 [ V_43 ] . V_219 ;
if ( V_216 == V_43 ) {
* V_209 &= ~ ( V_217 | V_218 ) ;
} else {
V_215 = V_5 [ V_43 ] . V_220 ;
V_5 [ V_215 ] . V_219 = V_216 ;
V_5 [ V_216 ] . V_220 = V_215 ;
V_5 [ V_43 ] . V_219 = V_5 [ V_43 ] . V_220 = V_43 ;
* V_209 = ( * V_209 & ~ V_218 ) | V_216 ;
}
V_106 = V_5 [ V_43 ] . V_153 ;
V_49 = F_50 ( V_144 [ 0 ] , V_106 ) ;
if ( ( V_144 [ 0 ] & V_114 ) &&
F_98 ( V_106 , V_49 ) == V_73 ) {
if ( V_1 -> V_18 . V_109 )
V_144 [ 0 ] |= V_113 ;
F_84 ( V_1 , V_144 , V_43 ) ;
V_188 = V_144 [ 1 ] & ( V_57 | V_58 ) ;
* V_209 |= V_188 << V_202 ;
if ( V_188 & ~ V_5 [ V_43 ] . V_153 ) {
V_5 [ V_43 ] . V_153 = V_106 | V_188 ;
F_99 ( V_1 , & V_5 [ V_43 ] ) ;
}
}
F_83 ( V_209 ) ;
V_144 [ 0 ] &= ~ V_112 ;
}
return 0 ;
}
int F_100 ( struct V_1 * V_1 , unsigned long V_184 )
{
if ( V_1 -> V_18 . V_109 )
F_96 ( V_1 , V_184 , F_97 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_1 , unsigned long V_74 , unsigned long V_208 )
{
if ( V_1 -> V_18 . V_109 )
F_91 ( V_1 , V_74 , V_208 , F_97 ) ;
return 0 ;
}
void F_102 ( struct V_1 * V_1 , struct V_40 * V_41 )
{
unsigned long * V_209 ;
unsigned long V_73 ;
unsigned long V_221 ;
V_209 = V_41 -> V_18 . V_185 ;
V_73 = V_41 -> V_88 ;
for ( V_221 = V_41 -> V_44 ; V_221 ; -- V_221 ) {
if ( * V_209 & V_217 )
F_97 ( V_1 , V_209 , V_73 ) ;
++ V_209 ;
++ V_73 ;
}
}
static int F_103 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_73 )
{
struct V_4 * V_5 = V_1 -> V_18 . V_26 ;
unsigned long V_222 , V_43 , V_216 ;
unsigned long * V_144 ;
int V_53 = 0 ;
V_223:
F_81 ( V_209 ) ;
if ( * V_209 & V_224 ) {
* V_209 &= ~ V_224 ;
V_53 = 1 ;
}
if ( ! ( * V_209 & V_217 ) ) {
F_83 ( V_209 ) ;
return V_53 ;
}
V_43 = V_222 = * V_209 & V_218 ;
do {
V_144 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 << 4 ) ) ;
V_216 = V_5 [ V_43 ] . V_219 ;
if ( ! ( V_144 [ 1 ] & V_57 ) )
continue;
if ( ! F_70 ( V_144 , V_112 ) ) {
F_83 ( V_209 ) ;
while ( V_144 [ 0 ] & V_112 )
F_71 () ;
goto V_223;
}
if ( ( V_144 [ 0 ] & V_114 ) && ( V_144 [ 1 ] & V_57 ) ) {
F_104 ( V_1 , V_144 , V_43 ) ;
if ( ! ( V_5 [ V_43 ] . V_153 & V_57 ) ) {
V_5 [ V_43 ] . V_153 |= V_57 ;
F_99 ( V_1 , & V_5 [ V_43 ] ) ;
}
V_53 = 1 ;
}
V_144 [ 0 ] &= ~ V_112 ;
} while ( ( V_43 = V_216 ) != V_222 );
F_83 ( V_209 ) ;
return V_53 ;
}
int F_105 ( struct V_1 * V_1 , unsigned long V_184 )
{
if ( ! V_1 -> V_18 . V_109 )
return 0 ;
return F_96 ( V_1 , V_184 , F_103 ) ;
}
static int F_106 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_73 )
{
struct V_4 * V_5 = V_1 -> V_18 . V_26 ;
unsigned long V_222 , V_43 , V_216 ;
unsigned long * V_225 ;
int V_53 = 1 ;
if ( * V_209 & V_224 )
return 1 ;
F_81 ( V_209 ) ;
if ( * V_209 & V_224 )
goto V_34;
if ( * V_209 & V_217 ) {
V_43 = V_222 = * V_209 & V_218 ;
do {
V_225 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 << 4 ) ) ;
V_216 = V_5 [ V_43 ] . V_219 ;
if ( V_225 [ 1 ] & V_57 )
goto V_34;
} while ( ( V_43 = V_216 ) != V_222 );
}
V_53 = 0 ;
V_34:
F_83 ( V_209 ) ;
return V_53 ;
}
int F_107 ( struct V_1 * V_1 , unsigned long V_184 )
{
if ( ! V_1 -> V_18 . V_109 )
return 0 ;
return F_96 ( V_1 , V_184 , F_106 ) ;
}
void F_108 ( struct V_1 * V_1 , unsigned long V_184 , T_4 V_197 )
{
if ( ! V_1 -> V_18 . V_109 )
return;
F_96 ( V_1 , V_184 , F_97 ) ;
}
static int F_109 ( struct V_1 * V_1 , unsigned long * V_209 )
{
struct V_4 * V_5 = V_1 -> V_18 . V_26 ;
unsigned long V_222 , V_43 , V_216 ;
unsigned long * V_144 ;
int V_53 = 0 ;
V_223:
F_81 ( V_209 ) ;
if ( * V_209 & V_226 ) {
* V_209 &= ~ V_226 ;
V_53 = 1 ;
}
if ( ! ( * V_209 & V_217 ) ) {
F_83 ( V_209 ) ;
return V_53 ;
}
V_43 = V_222 = * V_209 & V_218 ;
do {
V_144 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 << 4 ) ) ;
V_216 = V_5 [ V_43 ] . V_219 ;
if ( ! ( V_144 [ 1 ] & V_58 ) )
continue;
if ( ! F_70 ( V_144 , V_112 ) ) {
F_83 ( V_209 ) ;
while ( V_144 [ 0 ] & V_112 )
F_71 () ;
goto V_223;
}
if ( ( V_144 [ 0 ] & V_114 ) && ( V_144 [ 1 ] & V_58 ) ) {
V_144 [ 0 ] |= V_113 ;
F_84 ( V_1 , V_144 , V_43 ) ;
V_144 [ 1 ] &= ~ V_58 ;
F_86 () ;
V_144 [ 0 ] = ( V_144 [ 0 ] & ~ V_113 ) | V_114 ;
if ( ! ( V_5 [ V_43 ] . V_153 & V_58 ) ) {
V_5 [ V_43 ] . V_153 |= V_58 ;
F_99 ( V_1 , & V_5 [ V_43 ] ) ;
}
V_53 = 1 ;
}
V_144 [ 0 ] &= ~ V_112 ;
} while ( ( V_43 = V_216 ) != V_222 );
F_83 ( V_209 ) ;
return V_53 ;
}
static void F_110 ( struct V_227 * V_228 ,
struct V_40 * V_41 ,
unsigned long * V_229 )
{
unsigned long V_73 ;
if ( ! V_228 -> V_230 || ! V_228 -> V_231 )
return;
V_73 = V_228 -> V_108 >> V_15 ;
if ( V_73 < V_41 -> V_88 ||
V_73 >= V_41 -> V_88 + V_41 -> V_44 )
return;
V_228 -> V_230 = false ;
if ( V_229 )
F_111 ( V_73 - V_41 -> V_88 , V_229 ) ;
}
long F_112 ( struct V_1 * V_1 , struct V_40 * V_41 ,
unsigned long * V_229 )
{
unsigned long V_43 ;
unsigned long * V_209 ;
struct V_38 * V_39 ;
F_69 () ;
V_209 = V_41 -> V_18 . V_185 ;
for ( V_43 = 0 ; V_43 < V_41 -> V_44 ; ++ V_43 ) {
if ( F_109 ( V_1 , V_209 ) && V_229 )
F_111 ( V_43 , V_229 ) ;
++ V_209 ;
}
F_113 (i, vcpu, kvm) {
F_48 ( & V_39 -> V_18 . V_232 ) ;
F_110 ( & V_39 -> V_18 . V_228 , V_41 , V_229 ) ;
F_110 ( & V_39 -> V_18 . V_233 , V_41 , V_229 ) ;
F_49 ( & V_39 -> V_18 . V_232 ) ;
}
F_72 () ;
return 0 ;
}
void * F_114 ( struct V_1 * V_1 , unsigned long V_108 ,
unsigned long * V_234 )
{
struct V_40 * V_41 ;
unsigned long V_73 = V_108 >> V_15 ;
struct V_76 * V_76 , * V_78 [ 1 ] ;
int V_44 ;
unsigned long V_184 , V_235 ;
unsigned long V_236 ;
unsigned long * V_80 ;
int V_205 ;
V_205 = F_88 ( & V_1 -> V_206 ) ;
V_41 = F_51 ( V_1 , V_73 ) ;
if ( ! V_41 || ( V_41 -> V_103 & V_116 ) )
goto V_29;
if ( ! V_1 -> V_18 . V_109 ) {
V_80 = V_41 -> V_18 . V_87 ;
if ( ! V_80 )
goto V_29;
V_80 += V_73 - V_41 -> V_88 ;
V_236 = * V_80 ;
if ( ! V_236 ) {
if ( F_32 ( V_1 , V_73 , V_41 ,
V_99 ) < 0 )
goto V_29;
V_236 = * V_80 ;
}
V_76 = F_115 ( V_236 >> V_15 ) ;
F_44 ( V_76 ) ;
} else {
V_184 = F_33 ( V_41 , V_73 ) ;
V_44 = F_34 ( V_184 , 1 , 1 , V_78 ) ;
if ( V_44 < 1 )
goto V_29;
V_76 = V_78 [ 0 ] ;
}
F_90 ( & V_1 -> V_206 , V_205 ) ;
V_235 = V_108 & ( V_99 - 1 ) ;
if ( V_234 )
* V_234 = V_99 - V_235 ;
return F_116 ( V_76 ) + V_235 ;
V_29:
F_90 ( & V_1 -> V_206 , V_205 ) ;
return NULL ;
}
void F_117 ( struct V_1 * V_1 , void * V_237 , unsigned long V_108 ,
bool V_230 )
{
struct V_76 * V_76 = F_118 ( V_237 ) ;
struct V_40 * V_41 ;
unsigned long V_73 ;
unsigned long * V_185 ;
int V_205 ;
F_45 ( V_76 ) ;
if ( ! V_230 || ! V_1 -> V_18 . V_109 )
return;
V_73 = V_108 >> V_15 ;
V_205 = F_88 ( & V_1 -> V_206 ) ;
V_41 = F_51 ( V_1 , V_73 ) ;
if ( V_41 ) {
V_185 = & V_41 -> V_18 . V_185 [ V_73 - V_41 -> V_88 ] ;
F_81 ( V_185 ) ;
* V_185 |= V_226 ;
F_83 ( V_185 ) ;
}
F_90 ( & V_1 -> V_206 , V_205 ) ;
}
static int F_119 ( struct V_4 * V_238 , unsigned long * V_239 )
{
unsigned long V_240 ;
if ( V_238 -> V_153 & V_241 )
return 1 ;
V_240 = ~ V_238 -> V_153 & ( V_57 | V_58 ) ;
if ( ( V_239 [ 0 ] & V_114 ) && ( V_239 [ 1 ] & V_240 ) )
return 1 ;
return 0 ;
}
static long F_120 ( unsigned long V_103 , unsigned long * V_239 ,
unsigned long * V_181 , struct V_4 * V_238 ,
int V_242 , int V_243 )
{
unsigned long V_132 , V_133 ;
unsigned long V_240 ;
int V_244 = 1 ;
int V_245 , V_230 ;
V_230 = F_119 ( V_238 , V_239 ) ;
if ( ! V_243 && ! V_230 )
return 0 ;
V_245 = 0 ;
if ( V_239 [ 0 ] & ( V_114 | V_113 ) ) {
V_245 = 1 ;
if ( ( V_103 & V_246 ) &&
! ( V_239 [ 0 ] & V_56 ) )
V_245 = 0 ;
}
if ( V_245 != V_242 )
return 0 ;
V_132 = V_133 = 0 ;
if ( V_245 || V_230 ) {
F_69 () ;
while ( ! F_70 ( V_239 , V_112 ) )
F_71 () ;
V_132 = V_239 [ 0 ] ;
V_245 = ! ! ( V_132 & V_114 ) ;
V_230 = ! ! ( V_238 -> V_153 & V_241 ) ;
V_240 = ~ V_238 -> V_153 & ( V_57 | V_58 ) ;
if ( V_245 && ( V_240 & V_239 [ 1 ] ) ) {
V_238 -> V_153 |= ( V_239 [ 1 ] & ( V_57 | V_58 ) ) |
V_241 ;
V_230 = 1 ;
}
if ( V_132 & V_113 ) {
V_132 &= ~ V_113 ;
V_132 |= V_114 ;
V_245 = 1 ;
}
if ( ( V_103 & V_246 ) && ! ( V_132 & V_56 ) )
V_245 = 0 ;
V_133 = V_238 -> V_153 ;
if ( V_245 == V_242 && V_230 ) {
V_133 &= ~ V_241 ;
V_238 -> V_153 = V_133 ;
}
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_239 [ 0 ] &= ~ V_112 ;
F_72 () ;
if ( ! ( V_245 == V_242 && ( V_243 || V_230 ) ) )
V_244 = 0 ;
}
V_181 [ 0 ] = V_132 ;
V_181 [ 1 ] = V_133 ;
return V_244 ;
}
static T_6 F_121 ( struct V_247 * V_247 , char T_7 * V_248 ,
T_8 V_249 , T_9 * V_250 )
{
struct V_251 * V_252 = V_247 -> V_253 ;
struct V_1 * V_1 = V_252 -> V_1 ;
struct V_254 V_255 ;
unsigned long * V_239 ;
struct V_4 * V_238 ;
unsigned long V_43 , V_256 , V_257 ;
unsigned long T_7 * V_258 ;
struct V_254 T_7 * V_259 ;
unsigned long V_103 ;
int V_243 ;
unsigned long V_181 [ 2 ] ;
if ( ! F_122 ( V_260 , V_248 , V_249 ) )
return - V_193 ;
V_243 = V_252 -> V_243 ;
V_103 = V_252 -> V_103 ;
V_43 = V_252 -> V_145 ;
V_239 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 * V_261 ) ) ;
V_238 = V_1 -> V_18 . V_26 + V_43 ;
V_258 = ( unsigned long T_7 * ) V_248 ;
V_256 = 0 ;
while ( V_256 + sizeof( V_255 ) + V_261 < V_249 ) {
V_259 = (struct V_254 T_7 * ) V_248 ;
V_255 . V_262 = 0 ;
V_255 . V_263 = 0 ;
V_257 = V_256 ;
V_256 += sizeof( V_255 ) ;
V_258 = ( unsigned long T_7 * ) ( V_248 + sizeof( V_255 ) ) ;
if ( ! V_243 ) {
while ( V_43 < V_1 -> V_18 . V_23 &&
! F_119 ( V_238 , V_239 ) ) {
++ V_43 ;
V_239 += 2 ;
++ V_238 ;
}
}
V_255 . V_145 = V_43 ;
while ( V_43 < V_1 -> V_18 . V_23 &&
V_255 . V_262 < 0xffff &&
V_256 + V_261 < V_249 &&
F_120 ( V_103 , V_239 , V_181 , V_238 , 1 , V_243 ) ) {
++ V_255 . V_262 ;
if ( F_123 ( V_181 [ 0 ] , V_258 ) ||
F_123 ( V_181 [ 1 ] , V_258 + 1 ) )
return - V_193 ;
V_256 += V_261 ;
V_258 += 2 ;
++ V_43 ;
V_239 += 2 ;
++ V_238 ;
}
while ( V_43 < V_1 -> V_18 . V_23 &&
V_255 . V_263 < 0xffff &&
F_120 ( V_103 , V_239 , V_181 , V_238 , 0 , V_243 ) ) {
++ V_255 . V_263 ;
++ V_43 ;
V_239 += 2 ;
++ V_238 ;
}
if ( V_255 . V_262 || V_255 . V_263 ) {
if ( F_124 ( V_259 , & V_255 , sizeof( V_255 ) ) )
return - V_193 ;
V_257 = V_256 ;
V_248 = ( char T_7 * ) V_258 ;
} else {
V_256 = V_257 ;
}
if ( V_43 >= V_1 -> V_18 . V_23 ) {
V_43 = 0 ;
V_252 -> V_243 = 0 ;
break;
}
}
V_252 -> V_145 = V_43 ;
return V_256 ;
}
static T_6 F_125 ( struct V_247 * V_247 , const char T_7 * V_248 ,
T_8 V_249 , T_9 * V_250 )
{
struct V_251 * V_252 = V_247 -> V_253 ;
struct V_1 * V_1 = V_252 -> V_1 ;
struct V_254 V_255 ;
unsigned long V_43 , V_216 ;
unsigned long V_132 , V_133 ;
unsigned long T_7 * V_258 ;
unsigned long * V_239 ;
unsigned long V_264 [ 2 ] ;
T_6 V_256 ;
long int V_29 , V_53 ;
int V_265 ;
if ( ! F_122 ( V_266 , V_248 , V_249 ) )
return - V_193 ;
F_11 ( & V_1 -> V_31 ) ;
V_265 = V_1 -> V_18 . V_32 ;
if ( V_265 ) {
V_1 -> V_18 . V_32 = 0 ;
F_12 () ;
if ( F_13 ( & V_1 -> V_18 . V_33 ) ) {
V_1 -> V_18 . V_32 = 1 ;
F_16 ( & V_1 -> V_31 ) ;
return - V_30 ;
}
}
V_29 = 0 ;
for ( V_256 = 0 ; V_256 + sizeof( V_255 ) <= V_249 ; ) {
V_29 = - V_193 ;
if ( F_126 ( & V_255 , V_248 , sizeof( V_255 ) ) )
break;
V_29 = 0 ;
if ( V_256 + V_255 . V_262 * V_261 > V_249 )
break;
V_256 += sizeof( V_255 ) ;
V_248 += sizeof( V_255 ) ;
V_29 = - V_66 ;
V_43 = V_255 . V_145 ;
if ( V_43 >= V_1 -> V_18 . V_23 ||
V_43 + V_255 . V_262 + V_255 . V_263 > V_1 -> V_18 . V_23 )
break;
V_239 = ( unsigned long * ) ( V_1 -> V_18 . V_21 + ( V_43 * V_261 ) ) ;
V_258 = ( unsigned long T_7 * ) V_248 ;
for ( V_216 = 0 ; V_216 < V_255 . V_262 ; ++ V_216 ) {
V_29 = - V_193 ;
if ( F_127 ( V_132 , V_258 ) || F_127 ( V_133 , V_258 + 1 ) )
goto V_34;
V_29 = - V_66 ;
if ( ! ( V_132 & V_114 ) )
goto V_34;
V_258 += 2 ;
V_256 += V_261 ;
if ( V_239 [ 0 ] & ( V_114 | V_113 ) )
F_128 ( V_1 , 0 , V_43 , 0 , V_264 ) ;
V_29 = - V_267 ;
V_53 = F_23 ( V_1 , V_61 , V_43 , V_132 , V_133 ,
V_264 ) ;
if ( V_53 != V_62 ) {
F_5 ( L_5
L_6 , V_53 , V_43 , V_132 , V_133 ) ;
goto V_34;
}
if ( ! V_265 && F_129 ( V_132 ) ) {
unsigned long V_49 = F_50 ( V_132 , V_133 ) ;
unsigned long V_268 = F_130 ( V_49 ) ;
unsigned long V_269 ;
V_1 -> V_18 . V_151 = V_268 | V_129 |
( V_55 << V_270 ) ;
V_269 = V_1 -> V_18 . V_269 & ~ V_271 ;
V_269 |= V_268 << ( V_272 - 4 ) ;
V_1 -> V_18 . V_269 = V_269 ;
V_265 = 1 ;
}
++ V_43 ;
V_239 += 2 ;
}
for ( V_216 = 0 ; V_216 < V_255 . V_263 ; ++ V_216 ) {
if ( V_239 [ 0 ] & ( V_114 | V_113 ) )
F_128 ( V_1 , 0 , V_43 , 0 , V_264 ) ;
++ V_43 ;
V_239 += 2 ;
}
V_29 = 0 ;
}
V_34:
F_131 () ;
V_1 -> V_18 . V_32 = V_265 ;
F_16 ( & V_1 -> V_31 ) ;
if ( V_29 )
return V_29 ;
return V_256 ;
}
static int F_132 ( struct V_273 * V_273 , struct V_247 * V_274 )
{
struct V_251 * V_252 = V_274 -> V_253 ;
V_274 -> V_253 = NULL ;
if ( ! ( V_252 -> V_103 & V_275 ) )
F_133 ( & V_252 -> V_1 -> V_18 . V_276 ) ;
F_134 ( V_252 -> V_1 ) ;
F_135 ( V_252 ) ;
return 0 ;
}
int F_136 ( struct V_1 * V_1 , struct V_277 * V_278 )
{
int V_53 ;
struct V_251 * V_252 ;
int V_279 ;
if ( V_278 -> V_103 & ~ ( V_246 | V_275 ) )
return - V_66 ;
V_252 = F_137 ( sizeof( * V_252 ) , V_11 ) ;
if ( ! V_252 )
return - V_20 ;
F_138 ( V_1 ) ;
V_252 -> V_1 = V_1 ;
V_252 -> V_145 = V_278 -> V_280 ;
V_252 -> V_103 = V_278 -> V_103 ;
V_252 -> V_243 = 1 ;
V_279 = ( V_278 -> V_103 & V_275 ) ? V_281 : V_282 ;
V_53 = F_139 ( L_7 , & V_283 , V_252 , V_279 ) ;
if ( V_53 < 0 ) {
F_134 ( V_1 ) ;
return V_53 ;
}
if ( V_279 == V_282 ) {
F_11 ( & V_1 -> V_284 ) ;
F_140 ( & V_1 -> V_18 . V_276 ) ;
F_141 ( & V_1 -> V_206 ) ;
F_16 ( & V_1 -> V_284 ) ;
}
return V_53 ;
}
void F_142 ( struct V_38 * V_39 )
{
struct V_285 * V_286 = & V_39 -> V_18 . V_286 ;
if ( F_25 ( V_67 ) )
V_39 -> V_18 . V_124 = 32 ;
else
V_39 -> V_18 . V_124 = 64 ;
V_286 -> V_287 = F_58 ;
V_286 -> V_288 = F_30 ;
V_39 -> V_18 . V_289 |= V_290 ;
}
