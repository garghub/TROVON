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
unsigned long V_69 = V_37 -> V_10 . V_70 ;
if ( F_34 ( V_37 -> V_10 . V_71 . V_69 ) )
V_69 |= V_72 ;
else
V_69 |= V_37 -> V_10 . V_71 . V_69 & V_73 ;
F_35 ( V_37 , V_69 ) ;
}
static long F_36 ( struct V_1 * V_1 , unsigned long V_74 ,
struct V_38 * V_39 ,
unsigned long V_47 )
{
unsigned long V_75 ;
long V_76 , V_27 ;
struct V_6 * V_6 , * V_77 , * V_78 [ 1 ] ;
unsigned long V_79 , V_34 ;
unsigned long * V_80 ;
unsigned int V_81 , V_82 , V_83 ;
struct V_84 * V_85 ;
unsigned long V_86 , V_41 , V_42 ;
V_80 = V_39 -> V_10 . V_87 ;
if ( ! V_80 )
return - V_64 ;
if ( V_80 [ V_74 - V_39 -> V_88 ] )
return 0 ;
V_81 = 0 ;
V_82 = 0 ;
V_6 = NULL ;
V_34 = V_47 ;
V_27 = - V_64 ;
V_75 = F_37 ( V_39 , V_74 ) ;
V_76 = F_38 ( V_75 , 1 , 1 , V_78 ) ;
if ( V_76 != 1 ) {
F_39 ( & V_89 -> V_90 -> V_91 ) ;
V_85 = F_40 ( V_89 -> V_90 , V_75 ) ;
if ( ! V_85 || V_85 -> V_92 > V_75 ||
V_75 + V_47 > V_85 -> V_93 ||
! ( V_85 -> V_94 & V_95 ) )
goto V_96;
V_81 = F_41 ( F_42 ( V_85 -> V_97 ) ) ;
V_86 = V_85 -> V_98 + ( ( V_75 - V_85 -> V_92 ) >> V_16 ) ;
if ( V_47 > V_99 && ( V_86 & ( ( V_47 >> V_16 ) - 1 ) ) )
goto V_96;
F_43 ( & V_89 -> V_90 -> V_91 ) ;
} else {
V_6 = V_78 [ 0 ] ;
V_82 = V_100 ;
V_79 = V_99 ;
if ( F_44 ( V_6 ) ) {
V_77 = F_45 ( V_6 ) ;
V_79 <<= F_46 ( V_77 ) ;
if ( V_79 > V_47 && F_47 ( V_39 , V_79 ) &&
! ( V_39 -> V_101 & ( V_79 - 1 ) ) ) {
V_75 &= ~ ( V_79 - 1 ) ;
V_34 = V_79 ;
F_48 ( V_77 ) ;
F_49 ( V_6 ) ;
V_6 = V_77 ;
}
}
if ( V_79 < V_47 )
goto V_32;
V_86 = F_6 ( V_6 ) ;
}
V_42 = V_34 >> V_16 ;
V_83 = F_50 ( V_42 ) ;
V_80 += ( V_74 - V_39 -> V_88 ) & ~ ( V_42 - 1 ) ;
F_51 ( & V_1 -> V_10 . V_102 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; ++ V_41 ) {
if ( ! V_80 [ V_41 ] ) {
V_80 [ V_41 ] = ( ( V_86 + V_41 ) << V_16 ) +
V_82 + V_81 + V_83 ;
V_82 = 0 ;
}
}
F_52 ( & V_1 -> V_10 . V_102 ) ;
V_27 = 0 ;
V_32:
if ( V_82 )
F_49 ( V_6 ) ;
return V_27 ;
V_96:
F_43 ( & V_89 -> V_90 -> V_91 ) ;
return V_27 ;
}
long F_27 ( struct V_1 * V_1 , unsigned long V_103 ,
long V_104 , unsigned long V_105 ,
unsigned long V_106 , unsigned long * V_107 )
{
unsigned long V_47 , V_108 , V_74 ;
struct V_38 * V_39 ;
long V_51 ;
if ( V_1 -> V_10 . V_109 )
goto V_110;
V_47 = F_53 ( V_105 , V_106 ) ;
if ( ! V_47 )
return V_111 ;
V_105 &= ~ ( V_112 | V_113 | V_114 ) ;
V_108 = ( V_106 & V_115 ) & ~ ( V_47 - 1 ) ;
V_74 = V_108 >> V_16 ;
V_39 = F_54 ( V_1 , V_74 ) ;
if ( V_39 && ! ( V_39 -> V_103 & V_116 ) ) {
if ( ! F_47 ( V_39 , V_47 ) )
return V_111 ;
if ( F_36 ( V_1 , V_74 , V_39 , V_47 ) < 0 )
return V_111 ;
}
V_110:
F_55 () ;
V_51 = F_56 ( V_1 , V_103 , V_104 , V_105 , V_106 ,
V_89 -> V_90 -> V_117 , false , V_107 ) ;
F_57 () ;
if ( V_51 == V_118 ) {
F_8 ( L_4 ) ;
V_51 = V_119 ;
}
return V_51 ;
}
long F_58 ( struct V_36 * V_37 , unsigned long V_103 ,
long V_104 , unsigned long V_105 ,
unsigned long V_106 )
{
return F_27 ( V_37 -> V_1 , V_103 , V_104 ,
V_105 , V_106 , & V_37 -> V_10 . V_120 [ 4 ] ) ;
}
static struct V_121 * F_59 ( struct V_36 * V_37 ,
T_2 V_122 )
{
T_3 V_123 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_37 -> V_10 . V_124 ; V_41 ++ ) {
if ( ! ( V_37 -> V_10 . V_125 [ V_41 ] . V_126 & V_127 ) )
continue;
if ( V_37 -> V_10 . V_125 [ V_41 ] . V_128 & V_129 )
V_123 = V_130 ;
else
V_123 = V_131 ;
if ( ( ( V_37 -> V_10 . V_125 [ V_41 ] . V_126 ^ V_122 ) & V_123 ) == 0 )
return & V_37 -> V_10 . V_125 [ V_41 ] ;
}
return NULL ;
}
static unsigned long F_60 ( unsigned long V_132 , unsigned long V_133 ,
unsigned long V_134 )
{
unsigned long V_135 ;
V_135 = F_53 ( V_132 , V_133 ) - 1 ;
return ( V_133 & V_115 & ~ V_135 ) | ( V_134 & V_135 ) ;
}
static int F_61 ( struct V_36 * V_37 , T_2 V_122 ,
struct V_136 * V_137 , bool V_138 , bool V_139 )
{
struct V_1 * V_1 = V_37 -> V_1 ;
struct V_121 * V_140 ;
unsigned long V_141 ;
unsigned long V_142 , V_143 ;
unsigned long V_132 , V_144 ;
unsigned long * V_145 ;
int V_146 ;
int V_147 = V_37 -> V_10 . V_71 . V_69 & ( V_138 ? V_148 : V_149 ) ;
if ( V_147 ) {
V_140 = F_59 ( V_37 , V_122 ) ;
if ( ! V_140 )
return - V_64 ;
V_141 = V_140 -> V_128 ;
} else {
V_141 = V_37 -> V_1 -> V_10 . V_150 ;
}
F_62 () ;
V_146 = F_63 ( V_1 , V_122 , V_141 ,
V_114 | V_113 ) ;
if ( V_146 < 0 ) {
F_64 () ;
return - V_151 ;
}
V_145 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_146 << 4 ) ) ;
V_132 = V_145 [ 0 ] & ~ V_112 ;
V_144 = V_1 -> V_10 . V_24 [ V_146 ] . V_152 ;
asm volatile("lwsync" : : : "memory");
V_145 [ 0 ] = V_132 ;
F_64 () ;
V_137 -> V_122 = V_122 ;
V_137 -> V_153 = ( ( V_132 & V_154 ) << 4 ) | ( ( V_122 >> 12 ) & 0xfff ) ;
V_142 = V_144 & ( V_155 | V_156 ) ;
V_143 = ( V_37 -> V_10 . V_71 . V_69 & V_157 ) ? V_158 : V_159 ;
V_143 &= V_141 ;
V_137 -> V_160 = F_65 ( V_142 , V_143 ) ;
V_137 -> V_161 = F_66 ( V_142 , V_143 ) ;
V_137 -> V_162 = V_137 -> V_160 && ! ( V_144 & ( V_163 | V_164 ) ) ;
if ( V_138 && V_147 && F_29 ( V_65 ) ) {
int V_165 = F_67 ( V_144 , V_37 -> V_10 . V_166 ) ;
if ( V_165 & 1 )
V_137 -> V_160 = 0 ;
if ( V_165 & 2 )
V_137 -> V_161 = 0 ;
}
V_137 -> V_167 = F_60 ( V_132 , V_144 , V_122 ) ;
return 0 ;
}
static int F_68 ( unsigned int V_168 )
{
unsigned int V_123 ;
V_123 = 0x10000000 ;
if ( ( V_168 & 0xfc000000 ) == 0x7c000000 )
V_123 = 0x100 ;
return ( V_168 & V_123 ) != 0 ;
}
static int F_69 ( struct V_169 * V_170 , struct V_36 * V_37 ,
unsigned long V_108 , T_2 V_134 , int V_171 )
{
int V_51 ;
T_1 V_172 ;
unsigned long V_173 = F_70 ( V_37 ) ;
if ( V_37 -> V_10 . V_172 == V_174 ) {
V_51 = F_71 ( V_37 , & V_173 , sizeof( T_1 ) , & V_172 , false ) ;
if ( V_51 != V_175 || V_172 == V_174 )
return V_176 ;
V_37 -> V_10 . V_172 = V_172 ;
}
if ( F_68 ( F_72 ( V_37 ) ) != ! ! V_171 )
return V_176 ;
V_37 -> V_10 . V_177 = V_108 ;
V_37 -> V_10 . V_178 = V_134 ;
return F_73 ( V_170 , V_37 ) ;
}
int F_74 ( struct V_169 * V_170 , struct V_36 * V_37 ,
unsigned long V_134 , unsigned long V_179 )
{
struct V_1 * V_1 = V_37 -> V_1 ;
unsigned long * V_145 , V_180 [ 3 ] , V_133 ;
unsigned long V_181 , V_47 , V_182 ;
unsigned long V_108 , V_74 , V_183 , V_86 ;
struct V_38 * V_39 ;
unsigned long * V_184 ;
struct V_4 * V_5 ;
struct V_6 * V_6 , * V_78 [ 1 ] ;
long V_146 , V_51 , V_42 ;
unsigned long V_81 ;
unsigned int V_185 , V_186 ;
struct V_84 * V_85 ;
unsigned long V_187 ;
if ( V_134 != V_37 -> V_10 . V_188 )
return V_176 ;
V_146 = V_37 -> V_10 . V_189 ;
V_145 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_146 << 4 ) ) ;
V_5 = & V_1 -> V_10 . V_24 [ V_146 ] ;
F_62 () ;
while ( ! F_75 ( V_145 , V_112 ) )
F_76 () ;
V_180 [ 0 ] = V_145 [ 0 ] & ~ V_112 ;
V_180 [ 1 ] = V_145 [ 1 ] ;
V_180 [ 2 ] = V_133 = V_5 -> V_152 ;
asm volatile("lwsync" : : : "memory");
V_145 [ 0 ] = V_180 [ 0 ] ;
F_64 () ;
if ( V_180 [ 0 ] != V_37 -> V_10 . V_190 [ 0 ] ||
V_180 [ 1 ] != V_37 -> V_10 . V_190 [ 1 ] )
return V_176 ;
V_47 = F_53 ( V_180 [ 0 ] , V_133 ) ;
V_108 = ( V_133 & V_115 & ~ ( V_47 - 1 ) ) | ( V_134 & ( V_47 - 1 ) ) ;
V_74 = V_108 >> V_16 ;
V_39 = F_54 ( V_1 , V_74 ) ;
if ( ! V_39 || ( V_39 -> V_103 & V_116 ) )
return F_69 ( V_170 , V_37 , V_108 , V_134 ,
V_179 & V_191 ) ;
if ( ! V_1 -> V_10 . V_109 )
return - V_192 ;
V_181 = V_1 -> V_193 ;
F_77 () ;
V_81 = 0 ;
V_86 = 0 ;
V_6 = NULL ;
V_182 = V_99 ;
V_185 = ( V_179 & V_191 ) != 0 ;
V_186 = V_185 ;
V_183 = F_37 ( V_39 , V_74 ) ;
V_42 = F_38 ( V_183 , 1 , V_185 , V_78 ) ;
if ( V_42 < 1 ) {
F_39 ( & V_89 -> V_90 -> V_91 ) ;
V_85 = F_40 ( V_89 -> V_90 , V_183 ) ;
if ( V_85 && V_85 -> V_92 <= V_183 && V_183 + V_47 <= V_85 -> V_93 &&
( V_85 -> V_94 & V_95 ) ) {
V_86 = V_85 -> V_98 +
( ( V_183 - V_85 -> V_92 ) >> V_16 ) ;
V_182 = V_47 ;
V_81 = F_41 ( F_42 ( V_85 -> V_97 ) ) ;
V_186 = V_85 -> V_94 & V_194 ;
}
F_43 ( & V_89 -> V_90 -> V_91 ) ;
if ( ! V_86 )
return - V_192 ;
} else {
V_6 = V_78 [ 0 ] ;
V_86 = F_6 ( V_6 ) ;
if ( F_44 ( V_6 ) ) {
V_6 = F_45 ( V_6 ) ;
V_182 <<= F_46 ( V_6 ) ;
}
if ( ! V_185 && F_78 ( V_133 ) ) {
unsigned int V_195 ;
T_4 * V_196 , V_197 ;
F_55 () ;
V_196 = F_79 ( V_89 -> V_90 -> V_117 ,
V_183 , & V_195 ) ;
if ( V_196 ) {
V_197 = F_80 ( V_196 , 1 ,
V_195 ) ;
if ( F_81 ( V_197 ) )
V_186 = 1 ;
}
F_57 () ;
}
}
V_51 = - V_192 ;
if ( V_47 > V_182 )
goto V_198;
if ( ! F_82 ( V_133 , V_81 ) ) {
if ( V_81 )
return - V_192 ;
V_133 = ( V_133 & ~ ( V_199 | V_200 | V_164 ) ) | V_57 ;
}
if ( V_47 < V_99 )
V_47 = V_99 ;
V_133 = ( V_133 & ~ ( V_155 - V_47 ) ) | ( ( V_86 << V_16 ) & ~ ( V_47 - 1 ) ) ;
if ( F_78 ( V_133 ) && ! V_186 )
V_133 = F_83 ( V_133 ) ;
V_51 = V_176 ;
F_62 () ;
while ( ! F_75 ( V_145 , V_112 ) )
F_76 () ;
if ( ( V_145 [ 0 ] & ~ V_112 ) != V_180 [ 0 ] || V_145 [ 1 ] != V_180 [ 1 ] ||
V_5 -> V_152 != V_180 [ 2 ] )
goto V_201;
V_180 [ 0 ] = ( V_180 [ 0 ] & ~ V_113 ) | V_114 ;
V_184 = & V_39 -> V_10 . V_184 [ V_74 - V_39 -> V_88 ] ;
F_84 ( V_184 ) ;
V_51 = V_176 ;
if ( F_85 ( V_37 -> V_1 , V_181 ) ) {
F_86 ( V_184 ) ;
goto V_201;
}
V_187 = * V_184 >> V_202 ;
V_133 &= V_187 | ~ ( V_55 | V_56 ) ;
if ( V_145 [ 0 ] & V_114 ) {
F_86 ( V_184 ) ;
V_145 [ 0 ] |= V_113 ;
F_87 ( V_1 , V_145 , V_146 ) ;
V_133 |= V_145 [ 1 ] & ( V_55 | V_56 ) ;
} else {
F_88 ( V_1 , V_5 , V_184 , V_146 , 0 ) ;
}
V_145 [ 1 ] = V_133 ;
F_89 () ;
V_145 [ 0 ] = V_180 [ 0 ] ;
asm volatile("ptesync" : : : "memory");
F_64 () ;
if ( V_6 && F_78 ( V_133 ) )
F_90 ( V_6 ) ;
V_198:
if ( V_6 ) {
F_49 ( V_78 [ 0 ] ) ;
}
return V_51 ;
V_201:
V_145 [ 0 ] &= ~ V_112 ;
F_64 () ;
goto V_198;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_203 * V_204 ;
struct V_38 * V_39 ;
int V_205 ;
V_205 = F_91 ( & V_1 -> V_206 ) ;
V_204 = V_1 -> V_207 ;
F_92 (memslot, slots) {
memset ( V_39 -> V_10 . V_184 , 0 ,
V_39 -> V_42 * sizeof( * V_39 -> V_10 . V_184 ) ) ;
}
F_93 ( & V_1 -> V_206 , V_205 ) ;
}
static int F_94 ( struct V_1 * V_1 ,
unsigned long V_75 ,
unsigned long V_208 ,
int (* F_95)( struct V_1 * V_1 ,
unsigned long * V_209 ,
unsigned long V_74 ) )
{
int V_51 ;
int V_210 = 0 ;
struct V_203 * V_204 ;
struct V_38 * V_39 ;
V_204 = V_203 ( V_1 ) ;
F_92 (memslot, slots) {
unsigned long V_211 , V_212 ;
T_5 V_74 , V_213 ;
V_211 = F_96 ( V_75 , V_39 -> V_101 ) ;
V_212 = F_97 ( V_208 , V_39 -> V_101 +
( V_39 -> V_42 << V_16 ) ) ;
if ( V_211 >= V_212 )
continue;
V_74 = F_98 ( V_211 , V_39 ) ;
V_213 = F_98 ( V_212 + V_99 - 1 , V_39 ) ;
for (; V_74 < V_213 ; ++ V_74 ) {
T_5 V_214 = V_74 - V_39 -> V_88 ;
V_51 = F_95 ( V_1 , & V_39 -> V_10 . V_184 [ V_214 ] , V_74 ) ;
V_210 |= V_51 ;
}
}
return V_210 ;
}
static int F_99 ( struct V_1 * V_1 , unsigned long V_183 ,
int (* F_95)( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_74 ) )
{
return F_94 ( V_1 , V_183 , V_183 + 1 , F_95 ) ;
}
static int F_100 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_74 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_215 , V_41 , V_216 ;
unsigned long * V_145 ;
unsigned long V_106 , V_47 , V_187 ;
for (; ; ) {
F_84 ( V_209 ) ;
if ( ! ( * V_209 & V_217 ) ) {
F_86 ( V_209 ) ;
break;
}
V_41 = * V_209 & V_218 ;
V_145 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
if ( ! F_75 ( V_145 , V_112 ) ) {
F_86 ( V_209 ) ;
while ( V_145 [ 0 ] & V_112 )
F_76 () ;
continue;
}
V_216 = V_5 [ V_41 ] . V_219 ;
if ( V_216 == V_41 ) {
* V_209 &= ~ ( V_217 | V_218 ) ;
} else {
V_215 = V_5 [ V_41 ] . V_220 ;
V_5 [ V_215 ] . V_219 = V_216 ;
V_5 [ V_216 ] . V_220 = V_215 ;
V_5 [ V_41 ] . V_219 = V_5 [ V_41 ] . V_220 = V_41 ;
* V_209 = ( * V_209 & ~ V_218 ) | V_216 ;
}
V_106 = V_5 [ V_41 ] . V_152 ;
V_47 = F_53 ( V_145 [ 0 ] , V_106 ) ;
if ( ( V_145 [ 0 ] & V_114 ) &&
F_101 ( V_106 , V_47 ) == V_74 ) {
if ( V_1 -> V_10 . V_109 )
V_145 [ 0 ] |= V_113 ;
F_87 ( V_1 , V_145 , V_41 ) ;
V_187 = V_145 [ 1 ] & ( V_55 | V_56 ) ;
* V_209 |= V_187 << V_202 ;
if ( V_187 & ~ V_5 [ V_41 ] . V_152 ) {
V_5 [ V_41 ] . V_152 = V_106 | V_187 ;
F_102 ( V_1 , & V_5 [ V_41 ] ) ;
}
}
F_86 ( V_209 ) ;
V_145 [ 0 ] &= ~ V_112 ;
}
return 0 ;
}
int F_103 ( struct V_1 * V_1 , unsigned long V_183 )
{
if ( V_1 -> V_10 . V_109 )
F_99 ( V_1 , V_183 , F_100 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_1 , unsigned long V_75 , unsigned long V_208 )
{
if ( V_1 -> V_10 . V_109 )
F_94 ( V_1 , V_75 , V_208 , F_100 ) ;
return 0 ;
}
void F_105 ( struct V_1 * V_1 ,
struct V_38 * V_39 )
{
unsigned long * V_209 ;
unsigned long V_74 ;
unsigned long V_221 ;
V_209 = V_39 -> V_10 . V_184 ;
V_74 = V_39 -> V_88 ;
for ( V_221 = V_39 -> V_42 ; V_221 ; -- V_221 ) {
if ( * V_209 & V_217 )
F_100 ( V_1 , V_209 , V_74 ) ;
++ V_209 ;
++ V_74 ;
}
}
static int F_106 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_74 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_222 , V_41 , V_216 ;
unsigned long * V_145 ;
int V_51 = 0 ;
V_223:
F_84 ( V_209 ) ;
if ( * V_209 & V_224 ) {
* V_209 &= ~ V_224 ;
V_51 = 1 ;
}
if ( ! ( * V_209 & V_217 ) ) {
F_86 ( V_209 ) ;
return V_51 ;
}
V_41 = V_222 = * V_209 & V_218 ;
do {
V_145 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_216 = V_5 [ V_41 ] . V_219 ;
if ( ! ( V_145 [ 1 ] & V_55 ) )
continue;
if ( ! F_75 ( V_145 , V_112 ) ) {
F_86 ( V_209 ) ;
while ( V_145 [ 0 ] & V_112 )
F_76 () ;
goto V_223;
}
if ( ( V_145 [ 0 ] & V_114 ) && ( V_145 [ 1 ] & V_55 ) ) {
F_107 ( V_1 , V_145 , V_41 ) ;
if ( ! ( V_5 [ V_41 ] . V_152 & V_55 ) ) {
V_5 [ V_41 ] . V_152 |= V_55 ;
F_102 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_51 = 1 ;
}
V_145 [ 0 ] &= ~ V_112 ;
} while ( ( V_41 = V_216 ) != V_222 );
F_86 ( V_209 ) ;
return V_51 ;
}
int F_108 ( struct V_1 * V_1 , unsigned long V_183 )
{
if ( ! V_1 -> V_10 . V_109 )
return 0 ;
return F_99 ( V_1 , V_183 , F_106 ) ;
}
static int F_109 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_74 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_222 , V_41 , V_216 ;
unsigned long * V_225 ;
int V_51 = 1 ;
if ( * V_209 & V_224 )
return 1 ;
F_84 ( V_209 ) ;
if ( * V_209 & V_224 )
goto V_32;
if ( * V_209 & V_217 ) {
V_41 = V_222 = * V_209 & V_218 ;
do {
V_225 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_216 = V_5 [ V_41 ] . V_219 ;
if ( V_225 [ 1 ] & V_55 )
goto V_32;
} while ( ( V_41 = V_216 ) != V_222 );
}
V_51 = 0 ;
V_32:
F_86 ( V_209 ) ;
return V_51 ;
}
int F_110 ( struct V_1 * V_1 , unsigned long V_183 )
{
if ( ! V_1 -> V_10 . V_109 )
return 0 ;
return F_99 ( V_1 , V_183 , F_109 ) ;
}
void F_111 ( struct V_1 * V_1 , unsigned long V_183 , T_4 V_197 )
{
if ( ! V_1 -> V_10 . V_109 )
return;
F_99 ( V_1 , V_183 , F_100 ) ;
}
static int F_112 ( struct V_1 * V_1 , unsigned long * V_209 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_222 , V_41 , V_216 ;
unsigned long * V_145 ;
int V_51 = 0 ;
V_223:
F_84 ( V_209 ) ;
if ( * V_209 & V_226 ) {
* V_209 &= ~ V_226 ;
V_51 = 1 ;
}
if ( ! ( * V_209 & V_217 ) ) {
F_86 ( V_209 ) ;
return V_51 ;
}
V_41 = V_222 = * V_209 & V_218 ;
do {
V_145 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_216 = V_5 [ V_41 ] . V_219 ;
if ( ! ( V_145 [ 1 ] & V_56 ) )
continue;
if ( ! F_75 ( V_145 , V_112 ) ) {
F_86 ( V_209 ) ;
while ( V_145 [ 0 ] & V_112 )
F_76 () ;
goto V_223;
}
if ( ( V_145 [ 0 ] & V_114 ) && ( V_145 [ 1 ] & V_56 ) ) {
V_145 [ 0 ] |= V_113 ;
F_87 ( V_1 , V_145 , V_41 ) ;
V_145 [ 1 ] &= ~ V_56 ;
F_89 () ;
V_145 [ 0 ] = ( V_145 [ 0 ] & ~ V_113 ) | V_114 ;
if ( ! ( V_5 [ V_41 ] . V_152 & V_56 ) ) {
V_5 [ V_41 ] . V_152 |= V_56 ;
F_102 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_51 = 1 ;
}
V_145 [ 0 ] &= ~ V_112 ;
} while ( ( V_41 = V_216 ) != V_222 );
F_86 ( V_209 ) ;
return V_51 ;
}
static void F_113 ( struct V_227 * V_228 ,
struct V_38 * V_39 ,
unsigned long * V_229 )
{
unsigned long V_74 ;
if ( ! V_228 -> V_230 || ! V_228 -> V_231 )
return;
V_74 = V_228 -> V_108 >> V_16 ;
if ( V_74 < V_39 -> V_88 ||
V_74 >= V_39 -> V_88 + V_39 -> V_42 )
return;
V_228 -> V_230 = false ;
if ( V_229 )
F_114 ( V_74 - V_39 -> V_88 , V_229 ) ;
}
long F_115 ( struct V_1 * V_1 , struct V_38 * V_39 ,
unsigned long * V_229 )
{
unsigned long V_41 ;
unsigned long * V_209 ;
struct V_36 * V_37 ;
F_62 () ;
V_209 = V_39 -> V_10 . V_184 ;
for ( V_41 = 0 ; V_41 < V_39 -> V_42 ; ++ V_41 ) {
if ( F_112 ( V_1 , V_209 ) && V_229 )
F_114 ( V_41 , V_229 ) ;
++ V_209 ;
}
F_116 (i, vcpu, kvm) {
F_51 ( & V_37 -> V_10 . V_232 ) ;
F_113 ( & V_37 -> V_10 . V_228 , V_39 , V_229 ) ;
F_113 ( & V_37 -> V_10 . V_233 , V_39 , V_229 ) ;
F_52 ( & V_37 -> V_10 . V_232 ) ;
}
F_64 () ;
return 0 ;
}
void * F_117 ( struct V_1 * V_1 , unsigned long V_108 ,
unsigned long * V_234 )
{
struct V_38 * V_39 ;
unsigned long V_74 = V_108 >> V_16 ;
struct V_6 * V_6 , * V_78 [ 1 ] ;
int V_42 ;
unsigned long V_183 , V_235 ;
unsigned long V_236 ;
unsigned long * V_80 ;
int V_205 ;
V_205 = F_91 ( & V_1 -> V_206 ) ;
V_39 = F_54 ( V_1 , V_74 ) ;
if ( ! V_39 || ( V_39 -> V_103 & V_116 ) )
goto V_27;
if ( ! V_1 -> V_10 . V_109 ) {
V_80 = V_39 -> V_10 . V_87 ;
if ( ! V_80 )
goto V_27;
V_80 += V_74 - V_39 -> V_88 ;
V_236 = * V_80 ;
if ( ! V_236 ) {
if ( F_36 ( V_1 , V_74 , V_39 ,
V_99 ) < 0 )
goto V_27;
V_236 = * V_80 ;
}
V_6 = F_118 ( V_236 >> V_16 ) ;
F_48 ( V_6 ) ;
} else {
V_183 = F_37 ( V_39 , V_74 ) ;
V_42 = F_38 ( V_183 , 1 , 1 , V_78 ) ;
if ( V_42 < 1 )
goto V_27;
V_6 = V_78 [ 0 ] ;
}
F_93 ( & V_1 -> V_206 , V_205 ) ;
V_235 = V_108 & ( V_99 - 1 ) ;
if ( V_234 )
* V_234 = V_99 - V_235 ;
return F_119 ( V_6 ) + V_235 ;
V_27:
F_93 ( & V_1 -> V_206 , V_205 ) ;
return NULL ;
}
void F_120 ( struct V_1 * V_1 , void * V_237 , unsigned long V_108 ,
bool V_230 )
{
struct V_6 * V_6 = F_23 ( V_237 ) ;
struct V_38 * V_39 ;
unsigned long V_74 ;
unsigned long * V_184 ;
int V_205 ;
F_49 ( V_6 ) ;
if ( ! V_230 || ! V_1 -> V_10 . V_109 )
return;
V_74 = V_108 >> V_16 ;
V_205 = F_91 ( & V_1 -> V_206 ) ;
V_39 = F_54 ( V_1 , V_74 ) ;
if ( V_39 ) {
V_184 = & V_39 -> V_10 . V_184 [ V_74 - V_39 -> V_88 ] ;
F_84 ( V_184 ) ;
* V_184 |= V_226 ;
F_86 ( V_184 ) ;
}
F_93 ( & V_1 -> V_206 , V_205 ) ;
}
static int F_121 ( struct V_4 * V_238 , unsigned long * V_239 )
{
unsigned long V_240 ;
if ( V_238 -> V_152 & V_241 )
return 1 ;
V_240 = ~ V_238 -> V_152 & ( V_55 | V_56 ) ;
if ( ( V_239 [ 0 ] & V_114 ) && ( V_239 [ 1 ] & V_240 ) )
return 1 ;
return 0 ;
}
static long F_122 ( unsigned long V_103 , unsigned long * V_239 ,
unsigned long * V_180 , struct V_4 * V_238 ,
int V_242 , int V_243 )
{
unsigned long V_132 , V_133 ;
unsigned long V_240 ;
int V_244 = 1 ;
int V_245 , V_230 ;
V_230 = F_121 ( V_238 , V_239 ) ;
if ( ! V_243 && ! V_230 )
return 0 ;
V_245 = 0 ;
if ( V_239 [ 0 ] & ( V_114 | V_113 ) ) {
V_245 = 1 ;
if ( ( V_103 & V_246 ) &&
! ( V_239 [ 0 ] & V_54 ) )
V_245 = 0 ;
}
if ( V_245 != V_242 )
return 0 ;
V_132 = V_133 = 0 ;
if ( V_245 || V_230 ) {
F_62 () ;
while ( ! F_75 ( V_239 , V_112 ) )
F_76 () ;
V_132 = V_239 [ 0 ] ;
V_245 = ! ! ( V_132 & V_114 ) ;
V_230 = ! ! ( V_238 -> V_152 & V_241 ) ;
V_240 = ~ V_238 -> V_152 & ( V_55 | V_56 ) ;
if ( V_245 && ( V_240 & V_239 [ 1 ] ) ) {
V_238 -> V_152 |= ( V_239 [ 1 ] & ( V_55 | V_56 ) ) |
V_241 ;
V_230 = 1 ;
}
if ( V_132 & V_113 ) {
V_132 &= ~ V_113 ;
V_132 |= V_114 ;
V_245 = 1 ;
}
if ( ( V_103 & V_246 ) && ! ( V_132 & V_54 ) )
V_245 = 0 ;
V_133 = V_238 -> V_152 ;
if ( V_245 == V_242 && V_230 ) {
V_133 &= ~ V_241 ;
V_238 -> V_152 = V_133 ;
}
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_239 [ 0 ] &= ~ V_112 ;
F_64 () ;
if ( ! ( V_245 == V_242 && ( V_243 || V_230 ) ) )
V_244 = 0 ;
}
V_180 [ 0 ] = V_132 ;
V_180 [ 1 ] = V_133 ;
return V_244 ;
}
static T_6 F_123 ( struct V_247 * V_247 , char T_7 * V_248 ,
T_8 V_249 , T_9 * V_250 )
{
struct V_251 * V_252 = V_247 -> V_253 ;
struct V_1 * V_1 = V_252 -> V_1 ;
struct V_254 V_255 ;
unsigned long * V_239 ;
struct V_4 * V_238 ;
unsigned long V_41 , V_256 , V_257 ;
unsigned long T_7 * V_258 ;
struct V_254 T_7 * V_259 ;
unsigned long V_103 ;
int V_243 ;
unsigned long V_180 [ 2 ] ;
if ( ! F_124 ( V_260 , V_248 , V_249 ) )
return - V_192 ;
V_243 = V_252 -> V_243 ;
V_103 = V_252 -> V_103 ;
V_41 = V_252 -> V_146 ;
V_239 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 * V_261 ) ) ;
V_238 = V_1 -> V_10 . V_24 + V_41 ;
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
while ( V_41 < V_1 -> V_10 . V_21 &&
! F_121 ( V_238 , V_239 ) ) {
++ V_41 ;
V_239 += 2 ;
++ V_238 ;
}
}
V_255 . V_146 = V_41 ;
while ( V_41 < V_1 -> V_10 . V_21 &&
V_255 . V_262 < 0xffff &&
V_256 + V_261 < V_249 &&
F_122 ( V_103 , V_239 , V_180 , V_238 , 1 , V_243 ) ) {
++ V_255 . V_262 ;
if ( F_125 ( V_180 [ 0 ] , V_258 ) ||
F_125 ( V_180 [ 1 ] , V_258 + 1 ) )
return - V_192 ;
V_256 += V_261 ;
V_258 += 2 ;
++ V_41 ;
V_239 += 2 ;
++ V_238 ;
}
while ( V_41 < V_1 -> V_10 . V_21 &&
V_255 . V_263 < 0xffff &&
F_122 ( V_103 , V_239 , V_180 , V_238 , 0 , V_243 ) ) {
++ V_255 . V_263 ;
++ V_41 ;
V_239 += 2 ;
++ V_238 ;
}
if ( V_255 . V_262 || V_255 . V_263 ) {
if ( F_126 ( V_259 , & V_255 , sizeof( V_255 ) ) )
return - V_192 ;
V_257 = V_256 ;
V_248 = ( char T_7 * ) V_258 ;
} else {
V_256 = V_257 ;
}
if ( V_41 >= V_1 -> V_10 . V_21 ) {
V_41 = 0 ;
V_252 -> V_243 = 0 ;
break;
}
}
V_252 -> V_146 = V_41 ;
return V_256 ;
}
static T_6 F_127 ( struct V_247 * V_247 , const char T_7 * V_248 ,
T_8 V_249 , T_9 * V_250 )
{
struct V_251 * V_252 = V_247 -> V_253 ;
struct V_1 * V_1 = V_252 -> V_1 ;
struct V_254 V_255 ;
unsigned long V_41 , V_216 ;
unsigned long V_132 , V_133 ;
unsigned long T_7 * V_258 ;
unsigned long * V_239 ;
unsigned long V_264 [ 2 ] ;
T_6 V_256 ;
long int V_27 , V_51 ;
int V_265 ;
if ( ! F_124 ( V_266 , V_248 , V_249 ) )
return - V_192 ;
F_14 ( & V_1 -> V_29 ) ;
V_265 = V_1 -> V_10 . V_30 ;
if ( V_265 ) {
V_1 -> V_10 . V_30 = 0 ;
F_15 () ;
if ( F_16 ( & V_1 -> V_10 . V_31 ) ) {
V_1 -> V_10 . V_30 = 1 ;
F_19 ( & V_1 -> V_29 ) ;
return - V_28 ;
}
}
V_27 = 0 ;
for ( V_256 = 0 ; V_256 + sizeof( V_255 ) <= V_249 ; ) {
V_27 = - V_192 ;
if ( F_128 ( & V_255 , V_248 , sizeof( V_255 ) ) )
break;
V_27 = 0 ;
if ( V_256 + V_255 . V_262 * V_261 > V_249 )
break;
V_256 += sizeof( V_255 ) ;
V_248 += sizeof( V_255 ) ;
V_27 = - V_64 ;
V_41 = V_255 . V_146 ;
if ( V_41 >= V_1 -> V_10 . V_21 ||
V_41 + V_255 . V_262 + V_255 . V_263 > V_1 -> V_10 . V_21 )
break;
V_239 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 * V_261 ) ) ;
V_258 = ( unsigned long T_7 * ) V_248 ;
for ( V_216 = 0 ; V_216 < V_255 . V_262 ; ++ V_216 ) {
V_27 = - V_192 ;
if ( F_129 ( V_132 , V_258 ) || F_129 ( V_133 , V_258 + 1 ) )
goto V_32;
V_27 = - V_64 ;
if ( ! ( V_132 & V_114 ) )
goto V_32;
V_258 += 2 ;
V_256 += V_261 ;
if ( V_239 [ 0 ] & ( V_114 | V_113 ) )
F_130 ( V_1 , 0 , V_41 , 0 , V_264 ) ;
V_27 = - V_267 ;
V_51 = F_27 ( V_1 , V_59 , V_41 , V_132 , V_133 ,
V_264 ) ;
if ( V_51 != V_60 ) {
F_8 ( L_5
L_6 , V_51 , V_41 , V_132 , V_133 ) ;
goto V_32;
}
if ( ! V_265 && F_131 ( V_132 ) ) {
unsigned long V_47 = F_53 ( V_132 , V_133 ) ;
unsigned long V_268 = F_132 ( V_47 ) ;
unsigned long V_269 ;
V_1 -> V_10 . V_150 = V_268 | V_129 |
( V_53 << V_270 ) ;
V_269 = V_268 << ( V_271 - 4 ) ;
F_133 ( V_1 , V_269 , V_272 ) ;
V_265 = 1 ;
}
++ V_41 ;
V_239 += 2 ;
}
for ( V_216 = 0 ; V_216 < V_255 . V_263 ; ++ V_216 ) {
if ( V_239 [ 0 ] & ( V_114 | V_113 ) )
F_130 ( V_1 , 0 , V_41 , 0 , V_264 ) ;
++ V_41 ;
V_239 += 2 ;
}
V_27 = 0 ;
}
V_32:
F_134 () ;
V_1 -> V_10 . V_30 = V_265 ;
F_19 ( & V_1 -> V_29 ) ;
if ( V_27 )
return V_27 ;
return V_256 ;
}
static int F_135 ( struct V_273 * V_273 , struct V_247 * V_274 )
{
struct V_251 * V_252 = V_274 -> V_253 ;
V_274 -> V_253 = NULL ;
if ( ! ( V_252 -> V_103 & V_275 ) )
F_136 ( & V_252 -> V_1 -> V_10 . V_276 ) ;
F_137 ( V_252 -> V_1 ) ;
F_138 ( V_252 ) ;
return 0 ;
}
int F_139 ( struct V_1 * V_1 , struct V_277 * V_278 )
{
int V_51 ;
struct V_251 * V_252 ;
int V_279 ;
if ( V_278 -> V_103 & ~ ( V_246 | V_275 ) )
return - V_64 ;
V_252 = F_140 ( sizeof( * V_252 ) , V_12 ) ;
if ( ! V_252 )
return - V_18 ;
F_141 ( V_1 ) ;
V_252 -> V_1 = V_1 ;
V_252 -> V_146 = V_278 -> V_280 ;
V_252 -> V_103 = V_278 -> V_103 ;
V_252 -> V_243 = 1 ;
V_279 = ( V_278 -> V_103 & V_275 ) ? V_281 : V_282 ;
V_51 = F_142 ( L_7 , & V_283 , V_252 , V_279 | V_284 ) ;
if ( V_51 < 0 ) {
F_137 ( V_1 ) ;
return V_51 ;
}
if ( V_279 == V_282 ) {
F_14 ( & V_1 -> V_285 ) ;
F_143 ( & V_1 -> V_10 . V_276 ) ;
F_144 ( & V_1 -> V_206 ) ;
F_19 ( & V_1 -> V_285 ) ;
}
return V_51 ;
}
void F_145 ( struct V_36 * V_37 )
{
struct V_286 * V_287 = & V_37 -> V_10 . V_287 ;
if ( F_29 ( V_65 ) )
V_37 -> V_10 . V_124 = 32 ;
else
V_37 -> V_10 . V_124 = 64 ;
V_287 -> V_288 = F_61 ;
V_287 -> V_289 = F_33 ;
V_37 -> V_10 . V_290 |= V_291 ;
}
