long F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
unsigned long V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_6 = NULL ;
long V_7 = V_8 ;
if ( V_2 ) {
V_7 = * V_2 ;
if ( V_7 < V_9 )
V_7 = V_9 ;
}
V_1 -> V_10 . V_11 = 0 ;
V_3 = F_2 ( V_12 | V_13 | V_14 |
V_15 , V_7 - V_16 ) ;
if ( ! V_3 ) {
F_3 ( V_7 < V_17 ) ;
V_6 = F_4 ( 1 << ( V_7 - V_16 ) ) ;
if ( V_6 ) {
V_3 = ( unsigned long ) F_5 ( F_6 ( V_6 ) ) ;
V_1 -> V_10 . V_11 = 1 ;
} else
-- V_7 ;
}
while ( ! V_3 && V_7 > V_9 ) {
V_3 = F_2 ( V_12 | V_13 | V_14 |
V_15 , V_7 - V_16 ) ;
if ( ! V_3 )
-- V_7 ;
}
if ( ! V_3 )
return - V_18 ;
V_1 -> V_10 . V_19 = V_3 ;
V_1 -> V_10 . V_20 = V_7 ;
V_1 -> V_10 . V_21 = 1ul << ( V_7 - 4 ) ;
V_1 -> V_10 . V_22 = ( 1ul << ( V_7 - 7 ) ) - 1 ;
V_5 = F_7 ( sizeof( struct V_4 ) * V_1 -> V_10 . V_21 ) ;
if ( ! V_5 ) {
F_8 ( L_1 ) ;
goto V_23;
}
V_1 -> V_10 . V_24 = V_5 ;
V_1 -> V_10 . V_25 = F_9 ( V_3 ) | ( V_7 - 18 ) ;
F_10 ( L_2 ,
V_3 , V_7 , V_1 -> V_10 . V_26 ) ;
if ( V_2 )
* V_2 = V_7 ;
return 0 ;
V_23:
if ( V_1 -> V_10 . V_11 )
F_11 ( V_6 , 1 << ( V_7 - V_16 ) ) ;
else
F_12 ( V_3 , V_7 - V_16 ) ;
return - V_18 ;
}
long F_13 ( struct V_1 * V_1 , T_1 * V_2 )
{
long V_27 = - V_28 ;
long V_7 ;
F_14 ( & V_1 -> V_29 ) ;
if ( V_1 -> V_10 . V_30 ) {
V_1 -> V_10 . V_30 = 0 ;
F_15 () ;
if ( F_16 ( & V_1 -> V_10 . V_31 ) ) {
V_1 -> V_10 . V_30 = 1 ;
goto V_32;
}
}
if ( V_1 -> V_10 . V_19 ) {
V_7 = V_1 -> V_10 . V_20 ;
memset ( ( void * ) V_1 -> V_10 . V_19 , 0 , 1ul << V_7 ) ;
F_17 ( V_1 ) ;
F_18 ( & V_1 -> V_10 . V_33 ) ;
* V_2 = V_7 ;
V_27 = 0 ;
} else {
V_27 = F_1 ( V_1 , V_2 ) ;
V_7 = * V_2 ;
}
V_32:
F_19 ( & V_1 -> V_29 ) ;
return V_27 ;
}
void F_20 ( struct V_1 * V_1 )
{
F_21 ( V_1 -> V_10 . V_26 ) ;
F_22 ( V_1 -> V_10 . V_24 ) ;
if ( V_1 -> V_10 . V_11 )
F_11 ( F_23 ( V_1 -> V_10 . V_19 ) ,
1 << ( V_1 -> V_10 . V_20 - V_16 ) ) ;
else
F_12 ( V_1 -> V_10 . V_19 ,
V_1 -> V_10 . V_20 - V_16 ) ;
}
static inline unsigned long F_24 ( unsigned long V_34 )
{
return ( V_34 > 0x1000 ) ? V_35 : 0 ;
}
static inline unsigned long F_25 ( unsigned long V_34 )
{
return ( V_34 == 0x10000 ) ? 0x1000 : 0 ;
}
void F_26 ( struct V_36 * V_37 , struct V_38 * V_39 ,
unsigned long V_40 )
{
unsigned long V_41 ;
unsigned long V_42 ;
unsigned long V_43 , V_44 ;
unsigned long V_45 , V_46 ;
unsigned long V_47 ;
unsigned long V_48 , V_49 ;
unsigned long V_50 ;
long V_51 ;
struct V_1 * V_1 = V_37 -> V_1 ;
V_47 = 1ul << V_40 ;
V_42 = V_39 -> V_42 >> ( V_40 - V_16 ) ;
if ( V_42 > 1ul << ( 40 - V_40 ) )
V_42 = 1ul << ( 40 - V_40 ) ;
if ( V_42 > V_1 -> V_10 . V_22 + 1 )
V_42 = V_1 -> V_10 . V_22 + 1 ;
V_48 = V_52 | ( V_53 << ( 40 - 16 ) ) |
V_54 | F_24 ( V_47 ) ;
V_49 = F_25 ( V_47 ) |
V_55 | V_56 | V_57 | V_58 ;
for ( V_41 = 0 ; V_41 < V_42 ; ++ V_41 ) {
V_45 = V_41 << V_40 ;
V_46 = ( V_41 ^ ( V_53 ^ ( V_53 << 25 ) ) ) & V_1 -> V_10 . V_22 ;
V_46 = ( V_46 << 3 ) + 7 ;
V_43 = V_48 | ( ( V_45 >> 16 ) & ~ 0x7fUL ) ;
V_44 = V_49 | V_45 ;
V_51 = F_27 ( V_1 , V_59 , V_46 , V_43 , V_44 ,
& V_50 ) ;
if ( V_51 != V_60 ) {
F_8 ( L_3 ,
V_45 , V_51 ) ;
break;
}
}
}
int F_28 ( void )
{
unsigned long V_61 , V_62 ;
if ( ! F_29 ( V_63 ) )
return - V_64 ;
if ( F_29 ( V_65 ) ) {
V_61 = F_30 ( V_66 ) ;
V_62 = V_67 ;
} else {
V_61 = 0 ;
V_62 = V_68 ;
}
F_31 ( V_62 + 1 ) ;
F_32 ( V_61 ) ;
F_32 ( V_62 ) ;
return 0 ;
}
static void F_33 ( struct V_36 * V_37 )
{
F_34 ( V_37 , V_69 | V_70 ) ;
}
static long F_35 ( struct V_1 * V_1 , unsigned long V_71 ,
struct V_38 * V_39 ,
unsigned long V_47 )
{
unsigned long V_72 ;
long V_73 , V_27 ;
struct V_6 * V_6 , * V_74 , * V_75 [ 1 ] ;
unsigned long V_76 , V_34 ;
unsigned long * V_77 ;
unsigned int V_78 , V_79 , V_80 ;
struct V_81 * V_82 ;
unsigned long V_83 , V_41 , V_42 ;
V_77 = V_39 -> V_10 . V_84 ;
if ( ! V_77 )
return - V_64 ;
if ( V_77 [ V_71 - V_39 -> V_85 ] )
return 0 ;
V_78 = 0 ;
V_79 = 0 ;
V_6 = NULL ;
V_34 = V_47 ;
V_27 = - V_64 ;
V_72 = F_36 ( V_39 , V_71 ) ;
V_73 = F_37 ( V_72 , 1 , 1 , V_75 ) ;
if ( V_73 != 1 ) {
F_38 ( & V_86 -> V_87 -> V_88 ) ;
V_82 = F_39 ( V_86 -> V_87 , V_72 ) ;
if ( ! V_82 || V_82 -> V_89 > V_72 ||
V_72 + V_47 > V_82 -> V_90 ||
! ( V_82 -> V_91 & V_92 ) )
goto V_93;
V_78 = F_40 ( F_41 ( V_82 -> V_94 ) ) ;
V_83 = V_82 -> V_95 + ( ( V_72 - V_82 -> V_89 ) >> V_16 ) ;
if ( V_47 > V_96 && ( V_83 & ( ( V_47 >> V_16 ) - 1 ) ) )
goto V_93;
F_42 ( & V_86 -> V_87 -> V_88 ) ;
} else {
V_6 = V_75 [ 0 ] ;
V_79 = V_97 ;
V_76 = V_96 ;
if ( F_43 ( V_6 ) ) {
V_74 = F_44 ( V_6 ) ;
V_76 <<= F_45 ( V_74 ) ;
if ( V_76 > V_47 && F_46 ( V_39 , V_76 ) &&
! ( V_39 -> V_98 & ( V_76 - 1 ) ) ) {
V_72 &= ~ ( V_76 - 1 ) ;
V_34 = V_76 ;
F_47 ( V_74 ) ;
F_48 ( V_6 ) ;
V_6 = V_74 ;
}
}
if ( V_76 < V_47 )
goto V_32;
V_83 = F_6 ( V_6 ) ;
}
V_42 = V_34 >> V_16 ;
V_80 = F_49 ( V_42 ) ;
V_77 += ( V_71 - V_39 -> V_85 ) & ~ ( V_42 - 1 ) ;
F_50 ( & V_1 -> V_10 . V_99 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; ++ V_41 ) {
if ( ! V_77 [ V_41 ] ) {
V_77 [ V_41 ] = ( ( V_83 + V_41 ) << V_16 ) +
V_79 + V_78 + V_80 ;
V_79 = 0 ;
}
}
F_51 ( & V_1 -> V_10 . V_99 ) ;
V_27 = 0 ;
V_32:
if ( V_79 )
F_48 ( V_6 ) ;
return V_27 ;
V_93:
F_42 ( & V_86 -> V_87 -> V_88 ) ;
return V_27 ;
}
long F_27 ( struct V_1 * V_1 , unsigned long V_100 ,
long V_101 , unsigned long V_102 ,
unsigned long V_103 , unsigned long * V_104 )
{
unsigned long V_47 , V_105 , V_71 ;
struct V_38 * V_39 ;
long V_51 ;
if ( V_1 -> V_10 . V_106 )
goto V_107;
V_47 = F_52 ( V_102 , V_103 ) ;
if ( ! V_47 )
return V_108 ;
V_102 &= ~ ( V_109 | V_110 | V_111 ) ;
V_105 = ( V_103 & V_112 ) & ~ ( V_47 - 1 ) ;
V_71 = V_105 >> V_16 ;
V_39 = F_53 ( V_1 , V_71 ) ;
if ( V_39 && ! ( V_39 -> V_100 & V_113 ) ) {
if ( ! F_46 ( V_39 , V_47 ) )
return V_108 ;
if ( F_35 ( V_1 , V_71 , V_39 , V_47 ) < 0 )
return V_108 ;
}
V_107:
F_54 () ;
V_51 = F_55 ( V_1 , V_100 , V_101 , V_102 , V_103 ,
V_86 -> V_87 -> V_114 , false , V_104 ) ;
F_56 () ;
if ( V_51 == V_115 ) {
F_8 ( L_4 ) ;
V_51 = V_116 ;
}
return V_51 ;
}
long F_57 ( struct V_36 * V_37 , unsigned long V_100 ,
long V_101 , unsigned long V_102 ,
unsigned long V_103 )
{
return F_27 ( V_37 -> V_1 , V_100 , V_101 ,
V_102 , V_103 , & V_37 -> V_10 . V_117 [ 4 ] ) ;
}
static struct V_118 * F_58 ( struct V_36 * V_37 ,
T_2 V_119 )
{
T_3 V_120 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_37 -> V_10 . V_121 ; V_41 ++ ) {
if ( ! ( V_37 -> V_10 . V_122 [ V_41 ] . V_123 & V_124 ) )
continue;
if ( V_37 -> V_10 . V_122 [ V_41 ] . V_125 & V_126 )
V_120 = V_127 ;
else
V_120 = V_128 ;
if ( ( ( V_37 -> V_10 . V_122 [ V_41 ] . V_123 ^ V_119 ) & V_120 ) == 0 )
return & V_37 -> V_10 . V_122 [ V_41 ] ;
}
return NULL ;
}
static unsigned long F_59 ( unsigned long V_129 , unsigned long V_130 ,
unsigned long V_131 )
{
unsigned long V_132 ;
V_132 = F_52 ( V_129 , V_130 ) - 1 ;
return ( V_130 & V_112 & ~ V_132 ) | ( V_131 & V_132 ) ;
}
static int F_60 ( struct V_36 * V_37 , T_2 V_119 ,
struct V_133 * V_134 , bool V_135 , bool V_136 )
{
struct V_1 * V_1 = V_37 -> V_1 ;
struct V_118 * V_137 ;
unsigned long V_138 ;
unsigned long V_139 , V_140 ;
unsigned long V_129 , V_141 ;
unsigned long * V_142 ;
int V_143 ;
int V_144 = V_37 -> V_10 . V_145 . V_146 & ( V_135 ? V_147 : V_148 ) ;
if ( V_144 ) {
V_137 = F_58 ( V_37 , V_119 ) ;
if ( ! V_137 )
return - V_64 ;
V_138 = V_137 -> V_125 ;
} else {
V_138 = V_37 -> V_1 -> V_10 . V_149 ;
}
F_61 () ;
V_143 = F_62 ( V_1 , V_119 , V_138 ,
V_111 | V_110 ) ;
if ( V_143 < 0 ) {
F_63 () ;
return - V_150 ;
}
V_142 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_143 << 4 ) ) ;
V_129 = V_142 [ 0 ] & ~ V_109 ;
V_141 = V_1 -> V_10 . V_24 [ V_143 ] . V_151 ;
asm volatile("lwsync" : : : "memory");
V_142 [ 0 ] = V_129 ;
F_63 () ;
V_134 -> V_119 = V_119 ;
V_134 -> V_152 = ( ( V_129 & V_153 ) << 4 ) | ( ( V_119 >> 12 ) & 0xfff ) ;
V_139 = V_141 & ( V_154 | V_155 ) ;
V_140 = ( V_37 -> V_10 . V_145 . V_146 & V_156 ) ? V_157 : V_158 ;
V_140 &= V_138 ;
V_134 -> V_159 = F_64 ( V_139 , V_140 ) ;
V_134 -> V_160 = F_65 ( V_139 , V_140 ) ;
V_134 -> V_161 = V_134 -> V_159 && ! ( V_141 & ( V_162 | V_163 ) ) ;
if ( V_135 && V_144 && F_29 ( V_65 ) ) {
int V_164 = F_66 ( V_141 , V_37 -> V_10 . V_165 ) ;
if ( V_164 & 1 )
V_134 -> V_159 = 0 ;
if ( V_164 & 2 )
V_134 -> V_160 = 0 ;
}
V_134 -> V_166 = F_59 ( V_129 , V_141 , V_119 ) ;
return 0 ;
}
static int F_67 ( unsigned int V_167 )
{
unsigned int V_120 ;
V_120 = 0x10000000 ;
if ( ( V_167 & 0xfc000000 ) == 0x7c000000 )
V_120 = 0x100 ;
return ( V_167 & V_120 ) != 0 ;
}
static int F_68 ( struct V_168 * V_169 , struct V_36 * V_37 ,
unsigned long V_105 , T_2 V_131 , int V_170 )
{
int V_51 ;
T_1 V_171 ;
unsigned long V_172 = F_69 ( V_37 ) ;
if ( V_37 -> V_10 . V_171 == V_173 ) {
V_51 = F_70 ( V_37 , & V_172 , sizeof( T_1 ) , & V_171 , false ) ;
if ( V_51 != V_174 || V_171 == V_173 )
return V_175 ;
V_37 -> V_10 . V_171 = V_171 ;
}
if ( F_67 ( V_37 -> V_10 . V_171 ) != ! ! V_170 )
return V_175 ;
V_37 -> V_10 . V_176 = V_105 ;
V_37 -> V_10 . V_177 = V_131 ;
return F_71 ( V_169 , V_37 ) ;
}
int F_72 ( struct V_168 * V_169 , struct V_36 * V_37 ,
unsigned long V_131 , unsigned long V_178 )
{
struct V_1 * V_1 = V_37 -> V_1 ;
unsigned long * V_142 , V_179 [ 3 ] , V_130 ;
unsigned long V_180 , V_47 , V_181 ;
unsigned long V_105 , V_71 , V_182 , V_83 ;
struct V_38 * V_39 ;
unsigned long * V_183 ;
struct V_4 * V_5 ;
struct V_6 * V_6 , * V_75 [ 1 ] ;
long V_143 , V_51 , V_42 ;
unsigned long V_78 ;
unsigned int V_184 , V_185 ;
struct V_81 * V_82 ;
unsigned long V_186 ;
if ( V_131 != V_37 -> V_10 . V_187 )
return V_175 ;
V_143 = V_37 -> V_10 . V_188 ;
V_142 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_143 << 4 ) ) ;
V_5 = & V_1 -> V_10 . V_24 [ V_143 ] ;
F_61 () ;
while ( ! F_73 ( V_142 , V_109 ) )
F_74 () ;
V_179 [ 0 ] = V_142 [ 0 ] & ~ V_109 ;
V_179 [ 1 ] = V_142 [ 1 ] ;
V_179 [ 2 ] = V_130 = V_5 -> V_151 ;
asm volatile("lwsync" : : : "memory");
V_142 [ 0 ] = V_179 [ 0 ] ;
F_63 () ;
if ( V_179 [ 0 ] != V_37 -> V_10 . V_189 [ 0 ] ||
V_179 [ 1 ] != V_37 -> V_10 . V_189 [ 1 ] )
return V_175 ;
V_47 = F_52 ( V_179 [ 0 ] , V_130 ) ;
V_105 = ( V_130 & V_112 & ~ ( V_47 - 1 ) ) | ( V_131 & ( V_47 - 1 ) ) ;
V_71 = V_105 >> V_16 ;
V_39 = F_53 ( V_1 , V_71 ) ;
if ( ! V_39 || ( V_39 -> V_100 & V_113 ) )
return F_68 ( V_169 , V_37 , V_105 , V_131 ,
V_178 & V_190 ) ;
if ( ! V_1 -> V_10 . V_106 )
return - V_191 ;
V_180 = V_1 -> V_192 ;
F_75 () ;
V_78 = 0 ;
V_83 = 0 ;
V_6 = NULL ;
V_181 = V_96 ;
V_184 = ( V_178 & V_190 ) != 0 ;
V_185 = V_184 ;
V_182 = F_36 ( V_39 , V_71 ) ;
V_42 = F_37 ( V_182 , 1 , V_184 , V_75 ) ;
if ( V_42 < 1 ) {
F_38 ( & V_86 -> V_87 -> V_88 ) ;
V_82 = F_39 ( V_86 -> V_87 , V_182 ) ;
if ( V_82 && V_82 -> V_89 <= V_182 && V_182 + V_47 <= V_82 -> V_90 &&
( V_82 -> V_91 & V_92 ) ) {
V_83 = V_82 -> V_95 +
( ( V_182 - V_82 -> V_89 ) >> V_16 ) ;
V_181 = V_47 ;
V_78 = F_40 ( F_41 ( V_82 -> V_94 ) ) ;
V_185 = V_82 -> V_91 & V_193 ;
}
F_42 ( & V_86 -> V_87 -> V_88 ) ;
if ( ! V_83 )
return - V_191 ;
} else {
V_6 = V_75 [ 0 ] ;
V_83 = F_6 ( V_6 ) ;
if ( F_43 ( V_6 ) ) {
V_6 = F_44 ( V_6 ) ;
V_181 <<= F_45 ( V_6 ) ;
}
if ( ! V_184 && F_76 ( V_130 ) ) {
unsigned int V_194 ;
T_4 * V_195 , V_196 ;
F_54 () ;
V_195 = F_77 ( V_86 -> V_87 -> V_114 ,
V_182 , & V_194 ) ;
if ( V_195 ) {
V_196 = F_78 ( V_195 , 1 ,
V_194 ) ;
if ( F_79 ( V_196 ) )
V_185 = 1 ;
}
F_56 () ;
}
}
V_51 = - V_191 ;
if ( V_47 > V_181 )
goto V_197;
if ( ! F_80 ( V_130 , V_78 ) ) {
if ( V_78 )
return - V_191 ;
V_130 = ( V_130 & ~ ( V_198 | V_199 | V_163 ) ) | V_57 ;
}
if ( V_47 < V_96 )
V_47 = V_96 ;
V_130 = ( V_130 & ~ ( V_154 - V_47 ) ) | ( ( V_83 << V_16 ) & ~ ( V_47 - 1 ) ) ;
if ( F_76 ( V_130 ) && ! V_185 )
V_130 = F_81 ( V_130 ) ;
V_51 = V_175 ;
F_61 () ;
while ( ! F_73 ( V_142 , V_109 ) )
F_74 () ;
if ( ( V_142 [ 0 ] & ~ V_109 ) != V_179 [ 0 ] || V_142 [ 1 ] != V_179 [ 1 ] ||
V_5 -> V_151 != V_179 [ 2 ] )
goto V_200;
V_179 [ 0 ] = ( V_179 [ 0 ] & ~ V_110 ) | V_111 ;
V_183 = & V_39 -> V_10 . V_183 [ V_71 - V_39 -> V_85 ] ;
F_82 ( V_183 ) ;
V_51 = V_175 ;
if ( F_83 ( V_37 -> V_1 , V_180 ) ) {
F_84 ( V_183 ) ;
goto V_200;
}
V_186 = * V_183 >> V_201 ;
V_130 &= V_186 | ~ ( V_55 | V_56 ) ;
if ( V_142 [ 0 ] & V_111 ) {
F_84 ( V_183 ) ;
V_142 [ 0 ] |= V_110 ;
F_85 ( V_1 , V_142 , V_143 ) ;
V_130 |= V_142 [ 1 ] & ( V_55 | V_56 ) ;
} else {
F_86 ( V_1 , V_5 , V_183 , V_143 , 0 ) ;
}
V_142 [ 1 ] = V_130 ;
F_87 () ;
V_142 [ 0 ] = V_179 [ 0 ] ;
asm volatile("ptesync" : : : "memory");
F_63 () ;
if ( V_6 && F_76 ( V_130 ) )
F_88 ( V_6 ) ;
V_197:
if ( V_6 ) {
F_48 ( V_75 [ 0 ] ) ;
}
return V_51 ;
V_200:
V_142 [ 0 ] &= ~ V_109 ;
F_63 () ;
goto V_197;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_202 * V_203 ;
struct V_38 * V_39 ;
int V_204 ;
V_204 = F_89 ( & V_1 -> V_205 ) ;
V_203 = V_1 -> V_206 ;
F_90 (memslot, slots) {
memset ( V_39 -> V_10 . V_183 , 0 ,
V_39 -> V_42 * sizeof( * V_39 -> V_10 . V_183 ) ) ;
}
F_91 ( & V_1 -> V_205 , V_204 ) ;
}
static int F_92 ( struct V_1 * V_1 ,
unsigned long V_72 ,
unsigned long V_207 ,
int (* F_93)( struct V_1 * V_1 ,
unsigned long * V_208 ,
unsigned long V_71 ) )
{
int V_51 ;
int V_209 = 0 ;
struct V_202 * V_203 ;
struct V_38 * V_39 ;
V_203 = V_202 ( V_1 ) ;
F_90 (memslot, slots) {
unsigned long V_210 , V_211 ;
T_5 V_71 , V_212 ;
V_210 = F_94 ( V_72 , V_39 -> V_98 ) ;
V_211 = F_95 ( V_207 , V_39 -> V_98 +
( V_39 -> V_42 << V_16 ) ) ;
if ( V_210 >= V_211 )
continue;
V_71 = F_96 ( V_210 , V_39 ) ;
V_212 = F_96 ( V_211 + V_96 - 1 , V_39 ) ;
for (; V_71 < V_212 ; ++ V_71 ) {
T_5 V_213 = V_71 - V_39 -> V_85 ;
V_51 = F_93 ( V_1 , & V_39 -> V_10 . V_183 [ V_213 ] , V_71 ) ;
V_209 |= V_51 ;
}
}
return V_209 ;
}
static int F_97 ( struct V_1 * V_1 , unsigned long V_182 ,
int (* F_93)( struct V_1 * V_1 , unsigned long * V_208 ,
unsigned long V_71 ) )
{
return F_92 ( V_1 , V_182 , V_182 + 1 , F_93 ) ;
}
static int F_98 ( struct V_1 * V_1 , unsigned long * V_208 ,
unsigned long V_71 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_214 , V_41 , V_215 ;
unsigned long * V_142 ;
unsigned long V_103 , V_47 , V_186 ;
for (; ; ) {
F_82 ( V_208 ) ;
if ( ! ( * V_208 & V_216 ) ) {
F_84 ( V_208 ) ;
break;
}
V_41 = * V_208 & V_217 ;
V_142 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
if ( ! F_73 ( V_142 , V_109 ) ) {
F_84 ( V_208 ) ;
while ( V_142 [ 0 ] & V_109 )
F_74 () ;
continue;
}
V_215 = V_5 [ V_41 ] . V_218 ;
if ( V_215 == V_41 ) {
* V_208 &= ~ ( V_216 | V_217 ) ;
} else {
V_214 = V_5 [ V_41 ] . V_219 ;
V_5 [ V_214 ] . V_218 = V_215 ;
V_5 [ V_215 ] . V_219 = V_214 ;
V_5 [ V_41 ] . V_218 = V_5 [ V_41 ] . V_219 = V_41 ;
* V_208 = ( * V_208 & ~ V_217 ) | V_215 ;
}
V_103 = V_5 [ V_41 ] . V_151 ;
V_47 = F_52 ( V_142 [ 0 ] , V_103 ) ;
if ( ( V_142 [ 0 ] & V_111 ) &&
F_99 ( V_103 , V_47 ) == V_71 ) {
if ( V_1 -> V_10 . V_106 )
V_142 [ 0 ] |= V_110 ;
F_85 ( V_1 , V_142 , V_41 ) ;
V_186 = V_142 [ 1 ] & ( V_55 | V_56 ) ;
* V_208 |= V_186 << V_201 ;
if ( V_186 & ~ V_5 [ V_41 ] . V_151 ) {
V_5 [ V_41 ] . V_151 = V_103 | V_186 ;
F_100 ( V_1 , & V_5 [ V_41 ] ) ;
}
}
F_84 ( V_208 ) ;
V_142 [ 0 ] &= ~ V_109 ;
}
return 0 ;
}
int F_101 ( struct V_1 * V_1 , unsigned long V_182 )
{
if ( V_1 -> V_10 . V_106 )
F_97 ( V_1 , V_182 , F_98 ) ;
return 0 ;
}
int F_102 ( struct V_1 * V_1 , unsigned long V_72 , unsigned long V_207 )
{
if ( V_1 -> V_10 . V_106 )
F_92 ( V_1 , V_72 , V_207 , F_98 ) ;
return 0 ;
}
void F_103 ( struct V_1 * V_1 ,
struct V_38 * V_39 )
{
unsigned long * V_208 ;
unsigned long V_71 ;
unsigned long V_220 ;
V_208 = V_39 -> V_10 . V_183 ;
V_71 = V_39 -> V_85 ;
for ( V_220 = V_39 -> V_42 ; V_220 ; -- V_220 ) {
if ( * V_208 & V_216 )
F_98 ( V_1 , V_208 , V_71 ) ;
++ V_208 ;
++ V_71 ;
}
}
static int F_104 ( struct V_1 * V_1 , unsigned long * V_208 ,
unsigned long V_71 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_221 , V_41 , V_215 ;
unsigned long * V_142 ;
int V_51 = 0 ;
V_222:
F_82 ( V_208 ) ;
if ( * V_208 & V_223 ) {
* V_208 &= ~ V_223 ;
V_51 = 1 ;
}
if ( ! ( * V_208 & V_216 ) ) {
F_84 ( V_208 ) ;
return V_51 ;
}
V_41 = V_221 = * V_208 & V_217 ;
do {
V_142 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_215 = V_5 [ V_41 ] . V_218 ;
if ( ! ( V_142 [ 1 ] & V_55 ) )
continue;
if ( ! F_73 ( V_142 , V_109 ) ) {
F_84 ( V_208 ) ;
while ( V_142 [ 0 ] & V_109 )
F_74 () ;
goto V_222;
}
if ( ( V_142 [ 0 ] & V_111 ) && ( V_142 [ 1 ] & V_55 ) ) {
F_105 ( V_1 , V_142 , V_41 ) ;
if ( ! ( V_5 [ V_41 ] . V_151 & V_55 ) ) {
V_5 [ V_41 ] . V_151 |= V_55 ;
F_100 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_51 = 1 ;
}
V_142 [ 0 ] &= ~ V_109 ;
} while ( ( V_41 = V_215 ) != V_221 );
F_84 ( V_208 ) ;
return V_51 ;
}
int F_106 ( struct V_1 * V_1 , unsigned long V_182 )
{
if ( ! V_1 -> V_10 . V_106 )
return 0 ;
return F_97 ( V_1 , V_182 , F_104 ) ;
}
static int F_107 ( struct V_1 * V_1 , unsigned long * V_208 ,
unsigned long V_71 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_221 , V_41 , V_215 ;
unsigned long * V_224 ;
int V_51 = 1 ;
if ( * V_208 & V_223 )
return 1 ;
F_82 ( V_208 ) ;
if ( * V_208 & V_223 )
goto V_32;
if ( * V_208 & V_216 ) {
V_41 = V_221 = * V_208 & V_217 ;
do {
V_224 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_215 = V_5 [ V_41 ] . V_218 ;
if ( V_224 [ 1 ] & V_55 )
goto V_32;
} while ( ( V_41 = V_215 ) != V_221 );
}
V_51 = 0 ;
V_32:
F_84 ( V_208 ) ;
return V_51 ;
}
int F_108 ( struct V_1 * V_1 , unsigned long V_182 )
{
if ( ! V_1 -> V_10 . V_106 )
return 0 ;
return F_97 ( V_1 , V_182 , F_107 ) ;
}
void F_109 ( struct V_1 * V_1 , unsigned long V_182 , T_4 V_196 )
{
if ( ! V_1 -> V_10 . V_106 )
return;
F_97 ( V_1 , V_182 , F_98 ) ;
}
static int F_110 ( struct V_1 * V_1 , unsigned long * V_208 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_221 , V_41 , V_215 ;
unsigned long * V_142 ;
int V_51 = 0 ;
V_222:
F_82 ( V_208 ) ;
if ( * V_208 & V_225 ) {
* V_208 &= ~ V_225 ;
V_51 = 1 ;
}
if ( ! ( * V_208 & V_216 ) ) {
F_84 ( V_208 ) ;
return V_51 ;
}
V_41 = V_221 = * V_208 & V_217 ;
do {
V_142 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_215 = V_5 [ V_41 ] . V_218 ;
if ( ! ( V_142 [ 1 ] & V_56 ) )
continue;
if ( ! F_73 ( V_142 , V_109 ) ) {
F_84 ( V_208 ) ;
while ( V_142 [ 0 ] & V_109 )
F_74 () ;
goto V_222;
}
if ( ( V_142 [ 0 ] & V_111 ) && ( V_142 [ 1 ] & V_56 ) ) {
V_142 [ 0 ] |= V_110 ;
F_85 ( V_1 , V_142 , V_41 ) ;
V_142 [ 1 ] &= ~ V_56 ;
F_87 () ;
V_142 [ 0 ] = ( V_142 [ 0 ] & ~ V_110 ) | V_111 ;
if ( ! ( V_5 [ V_41 ] . V_151 & V_56 ) ) {
V_5 [ V_41 ] . V_151 |= V_56 ;
F_100 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_51 = 1 ;
}
V_142 [ 0 ] &= ~ V_109 ;
} while ( ( V_41 = V_215 ) != V_221 );
F_84 ( V_208 ) ;
return V_51 ;
}
static void F_111 ( struct V_226 * V_227 ,
struct V_38 * V_39 ,
unsigned long * V_228 )
{
unsigned long V_71 ;
if ( ! V_227 -> V_229 || ! V_227 -> V_230 )
return;
V_71 = V_227 -> V_105 >> V_16 ;
if ( V_71 < V_39 -> V_85 ||
V_71 >= V_39 -> V_85 + V_39 -> V_42 )
return;
V_227 -> V_229 = false ;
if ( V_228 )
F_112 ( V_71 - V_39 -> V_85 , V_228 ) ;
}
long F_113 ( struct V_1 * V_1 , struct V_38 * V_39 ,
unsigned long * V_228 )
{
unsigned long V_41 ;
unsigned long * V_208 ;
struct V_36 * V_37 ;
F_61 () ;
V_208 = V_39 -> V_10 . V_183 ;
for ( V_41 = 0 ; V_41 < V_39 -> V_42 ; ++ V_41 ) {
if ( F_110 ( V_1 , V_208 ) && V_228 )
F_112 ( V_41 , V_228 ) ;
++ V_208 ;
}
F_114 (i, vcpu, kvm) {
F_50 ( & V_37 -> V_10 . V_231 ) ;
F_111 ( & V_37 -> V_10 . V_227 , V_39 , V_228 ) ;
F_111 ( & V_37 -> V_10 . V_232 , V_39 , V_228 ) ;
F_51 ( & V_37 -> V_10 . V_231 ) ;
}
F_63 () ;
return 0 ;
}
void * F_115 ( struct V_1 * V_1 , unsigned long V_105 ,
unsigned long * V_233 )
{
struct V_38 * V_39 ;
unsigned long V_71 = V_105 >> V_16 ;
struct V_6 * V_6 , * V_75 [ 1 ] ;
int V_42 ;
unsigned long V_182 , V_234 ;
unsigned long V_235 ;
unsigned long * V_77 ;
int V_204 ;
V_204 = F_89 ( & V_1 -> V_205 ) ;
V_39 = F_53 ( V_1 , V_71 ) ;
if ( ! V_39 || ( V_39 -> V_100 & V_113 ) )
goto V_27;
if ( ! V_1 -> V_10 . V_106 ) {
V_77 = V_39 -> V_10 . V_84 ;
if ( ! V_77 )
goto V_27;
V_77 += V_71 - V_39 -> V_85 ;
V_235 = * V_77 ;
if ( ! V_235 ) {
if ( F_35 ( V_1 , V_71 , V_39 ,
V_96 ) < 0 )
goto V_27;
V_235 = * V_77 ;
}
V_6 = F_116 ( V_235 >> V_16 ) ;
F_47 ( V_6 ) ;
} else {
V_182 = F_36 ( V_39 , V_71 ) ;
V_42 = F_37 ( V_182 , 1 , 1 , V_75 ) ;
if ( V_42 < 1 )
goto V_27;
V_6 = V_75 [ 0 ] ;
}
F_91 ( & V_1 -> V_205 , V_204 ) ;
V_234 = V_105 & ( V_96 - 1 ) ;
if ( V_233 )
* V_233 = V_96 - V_234 ;
return F_117 ( V_6 ) + V_234 ;
V_27:
F_91 ( & V_1 -> V_205 , V_204 ) ;
return NULL ;
}
void F_118 ( struct V_1 * V_1 , void * V_236 , unsigned long V_105 ,
bool V_229 )
{
struct V_6 * V_6 = F_23 ( V_236 ) ;
struct V_38 * V_39 ;
unsigned long V_71 ;
unsigned long * V_183 ;
int V_204 ;
F_48 ( V_6 ) ;
if ( ! V_229 || ! V_1 -> V_10 . V_106 )
return;
V_71 = V_105 >> V_16 ;
V_204 = F_89 ( & V_1 -> V_205 ) ;
V_39 = F_53 ( V_1 , V_71 ) ;
if ( V_39 ) {
V_183 = & V_39 -> V_10 . V_183 [ V_71 - V_39 -> V_85 ] ;
F_82 ( V_183 ) ;
* V_183 |= V_225 ;
F_84 ( V_183 ) ;
}
F_91 ( & V_1 -> V_205 , V_204 ) ;
}
static int F_119 ( struct V_4 * V_237 , unsigned long * V_238 )
{
unsigned long V_239 ;
if ( V_237 -> V_151 & V_240 )
return 1 ;
V_239 = ~ V_237 -> V_151 & ( V_55 | V_56 ) ;
if ( ( V_238 [ 0 ] & V_111 ) && ( V_238 [ 1 ] & V_239 ) )
return 1 ;
return 0 ;
}
static long F_120 ( unsigned long V_100 , unsigned long * V_238 ,
unsigned long * V_179 , struct V_4 * V_237 ,
int V_241 , int V_242 )
{
unsigned long V_129 , V_130 ;
unsigned long V_239 ;
int V_243 = 1 ;
int V_244 , V_229 ;
V_229 = F_119 ( V_237 , V_238 ) ;
if ( ! V_242 && ! V_229 )
return 0 ;
V_244 = 0 ;
if ( V_238 [ 0 ] & ( V_111 | V_110 ) ) {
V_244 = 1 ;
if ( ( V_100 & V_245 ) &&
! ( V_238 [ 0 ] & V_54 ) )
V_244 = 0 ;
}
if ( V_244 != V_241 )
return 0 ;
V_129 = V_130 = 0 ;
if ( V_244 || V_229 ) {
F_61 () ;
while ( ! F_73 ( V_238 , V_109 ) )
F_74 () ;
V_129 = V_238 [ 0 ] ;
V_244 = ! ! ( V_129 & V_111 ) ;
V_229 = ! ! ( V_237 -> V_151 & V_240 ) ;
V_239 = ~ V_237 -> V_151 & ( V_55 | V_56 ) ;
if ( V_244 && ( V_239 & V_238 [ 1 ] ) ) {
V_237 -> V_151 |= ( V_238 [ 1 ] & ( V_55 | V_56 ) ) |
V_240 ;
V_229 = 1 ;
}
if ( V_129 & V_110 ) {
V_129 &= ~ V_110 ;
V_129 |= V_111 ;
V_244 = 1 ;
}
if ( ( V_100 & V_245 ) && ! ( V_129 & V_54 ) )
V_244 = 0 ;
V_130 = V_237 -> V_151 ;
if ( V_244 == V_241 && V_229 ) {
V_130 &= ~ V_240 ;
V_237 -> V_151 = V_130 ;
}
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_238 [ 0 ] &= ~ V_109 ;
F_63 () ;
if ( ! ( V_244 == V_241 && ( V_242 || V_229 ) ) )
V_243 = 0 ;
}
V_179 [ 0 ] = V_129 ;
V_179 [ 1 ] = V_130 ;
return V_243 ;
}
static T_6 F_121 ( struct V_246 * V_246 , char T_7 * V_247 ,
T_8 V_248 , T_9 * V_249 )
{
struct V_250 * V_251 = V_246 -> V_252 ;
struct V_1 * V_1 = V_251 -> V_1 ;
struct V_253 V_254 ;
unsigned long * V_238 ;
struct V_4 * V_237 ;
unsigned long V_41 , V_255 , V_256 ;
unsigned long T_7 * V_257 ;
struct V_253 T_7 * V_258 ;
unsigned long V_100 ;
int V_242 ;
unsigned long V_179 [ 2 ] ;
if ( ! F_122 ( V_259 , V_247 , V_248 ) )
return - V_191 ;
V_242 = V_251 -> V_242 ;
V_100 = V_251 -> V_100 ;
V_41 = V_251 -> V_143 ;
V_238 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 * V_260 ) ) ;
V_237 = V_1 -> V_10 . V_24 + V_41 ;
V_257 = ( unsigned long T_7 * ) V_247 ;
V_255 = 0 ;
while ( V_255 + sizeof( V_254 ) + V_260 < V_248 ) {
V_258 = (struct V_253 T_7 * ) V_247 ;
V_254 . V_261 = 0 ;
V_254 . V_262 = 0 ;
V_256 = V_255 ;
V_255 += sizeof( V_254 ) ;
V_257 = ( unsigned long T_7 * ) ( V_247 + sizeof( V_254 ) ) ;
if ( ! V_242 ) {
while ( V_41 < V_1 -> V_10 . V_21 &&
! F_119 ( V_237 , V_238 ) ) {
++ V_41 ;
V_238 += 2 ;
++ V_237 ;
}
}
V_254 . V_143 = V_41 ;
while ( V_41 < V_1 -> V_10 . V_21 &&
V_254 . V_261 < 0xffff &&
V_255 + V_260 < V_248 &&
F_120 ( V_100 , V_238 , V_179 , V_237 , 1 , V_242 ) ) {
++ V_254 . V_261 ;
if ( F_123 ( V_179 [ 0 ] , V_257 ) ||
F_123 ( V_179 [ 1 ] , V_257 + 1 ) )
return - V_191 ;
V_255 += V_260 ;
V_257 += 2 ;
++ V_41 ;
V_238 += 2 ;
++ V_237 ;
}
while ( V_41 < V_1 -> V_10 . V_21 &&
V_254 . V_262 < 0xffff &&
F_120 ( V_100 , V_238 , V_179 , V_237 , 0 , V_242 ) ) {
++ V_254 . V_262 ;
++ V_41 ;
V_238 += 2 ;
++ V_237 ;
}
if ( V_254 . V_261 || V_254 . V_262 ) {
if ( F_124 ( V_258 , & V_254 , sizeof( V_254 ) ) )
return - V_191 ;
V_256 = V_255 ;
V_247 = ( char T_7 * ) V_257 ;
} else {
V_255 = V_256 ;
}
if ( V_41 >= V_1 -> V_10 . V_21 ) {
V_41 = 0 ;
V_251 -> V_242 = 0 ;
break;
}
}
V_251 -> V_143 = V_41 ;
return V_255 ;
}
static T_6 F_125 ( struct V_246 * V_246 , const char T_7 * V_247 ,
T_8 V_248 , T_9 * V_249 )
{
struct V_250 * V_251 = V_246 -> V_252 ;
struct V_1 * V_1 = V_251 -> V_1 ;
struct V_253 V_254 ;
unsigned long V_41 , V_215 ;
unsigned long V_129 , V_130 ;
unsigned long T_7 * V_257 ;
unsigned long * V_238 ;
unsigned long V_263 [ 2 ] ;
T_6 V_255 ;
long int V_27 , V_51 ;
int V_264 ;
if ( ! F_122 ( V_265 , V_247 , V_248 ) )
return - V_191 ;
F_14 ( & V_1 -> V_29 ) ;
V_264 = V_1 -> V_10 . V_30 ;
if ( V_264 ) {
V_1 -> V_10 . V_30 = 0 ;
F_15 () ;
if ( F_16 ( & V_1 -> V_10 . V_31 ) ) {
V_1 -> V_10 . V_30 = 1 ;
F_19 ( & V_1 -> V_29 ) ;
return - V_28 ;
}
}
V_27 = 0 ;
for ( V_255 = 0 ; V_255 + sizeof( V_254 ) <= V_248 ; ) {
V_27 = - V_191 ;
if ( F_126 ( & V_254 , V_247 , sizeof( V_254 ) ) )
break;
V_27 = 0 ;
if ( V_255 + V_254 . V_261 * V_260 > V_248 )
break;
V_255 += sizeof( V_254 ) ;
V_247 += sizeof( V_254 ) ;
V_27 = - V_64 ;
V_41 = V_254 . V_143 ;
if ( V_41 >= V_1 -> V_10 . V_21 ||
V_41 + V_254 . V_261 + V_254 . V_262 > V_1 -> V_10 . V_21 )
break;
V_238 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 * V_260 ) ) ;
V_257 = ( unsigned long T_7 * ) V_247 ;
for ( V_215 = 0 ; V_215 < V_254 . V_261 ; ++ V_215 ) {
V_27 = - V_191 ;
if ( F_127 ( V_129 , V_257 ) || F_127 ( V_130 , V_257 + 1 ) )
goto V_32;
V_27 = - V_64 ;
if ( ! ( V_129 & V_111 ) )
goto V_32;
V_257 += 2 ;
V_255 += V_260 ;
if ( V_238 [ 0 ] & ( V_111 | V_110 ) )
F_128 ( V_1 , 0 , V_41 , 0 , V_263 ) ;
V_27 = - V_266 ;
V_51 = F_27 ( V_1 , V_59 , V_41 , V_129 , V_130 ,
V_263 ) ;
if ( V_51 != V_60 ) {
F_8 ( L_5
L_6 , V_51 , V_41 , V_129 , V_130 ) ;
goto V_32;
}
if ( ! V_264 && F_129 ( V_129 ) ) {
unsigned long V_47 = F_52 ( V_129 , V_130 ) ;
unsigned long V_267 = F_130 ( V_47 ) ;
unsigned long V_268 ;
V_1 -> V_10 . V_149 = V_267 | V_126 |
( V_53 << V_269 ) ;
V_268 = V_267 << ( V_270 - 4 ) ;
F_131 ( V_1 , V_268 , V_271 ) ;
V_264 = 1 ;
}
++ V_41 ;
V_238 += 2 ;
}
for ( V_215 = 0 ; V_215 < V_254 . V_262 ; ++ V_215 ) {
if ( V_238 [ 0 ] & ( V_111 | V_110 ) )
F_128 ( V_1 , 0 , V_41 , 0 , V_263 ) ;
++ V_41 ;
V_238 += 2 ;
}
V_27 = 0 ;
}
V_32:
F_132 () ;
V_1 -> V_10 . V_30 = V_264 ;
F_19 ( & V_1 -> V_29 ) ;
if ( V_27 )
return V_27 ;
return V_255 ;
}
static int F_133 ( struct V_272 * V_272 , struct V_246 * V_273 )
{
struct V_250 * V_251 = V_273 -> V_252 ;
V_273 -> V_252 = NULL ;
if ( ! ( V_251 -> V_100 & V_274 ) )
F_134 ( & V_251 -> V_1 -> V_10 . V_275 ) ;
F_135 ( V_251 -> V_1 ) ;
F_136 ( V_251 ) ;
return 0 ;
}
int F_137 ( struct V_1 * V_1 , struct V_276 * V_277 )
{
int V_51 ;
struct V_250 * V_251 ;
int V_278 ;
if ( V_277 -> V_100 & ~ ( V_245 | V_274 ) )
return - V_64 ;
V_251 = F_138 ( sizeof( * V_251 ) , V_12 ) ;
if ( ! V_251 )
return - V_18 ;
F_139 ( V_1 ) ;
V_251 -> V_1 = V_1 ;
V_251 -> V_143 = V_277 -> V_279 ;
V_251 -> V_100 = V_277 -> V_100 ;
V_251 -> V_242 = 1 ;
V_278 = ( V_277 -> V_100 & V_274 ) ? V_280 : V_281 ;
V_51 = F_140 ( L_7 , & V_282 , V_251 , V_278 | V_283 ) ;
if ( V_51 < 0 ) {
F_135 ( V_1 ) ;
return V_51 ;
}
if ( V_278 == V_281 ) {
F_14 ( & V_1 -> V_284 ) ;
F_141 ( & V_1 -> V_10 . V_275 ) ;
F_142 ( & V_1 -> V_205 ) ;
F_19 ( & V_1 -> V_284 ) ;
}
return V_51 ;
}
void F_143 ( struct V_36 * V_37 )
{
struct V_285 * V_286 = & V_37 -> V_10 . V_286 ;
if ( F_29 ( V_65 ) )
V_37 -> V_10 . V_121 = 32 ;
else
V_37 -> V_10 . V_121 = 64 ;
V_286 -> V_287 = F_60 ;
V_286 -> V_288 = F_33 ;
V_37 -> V_10 . V_289 |= V_290 ;
}
