long F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
unsigned long V_3 = 0 ;
struct V_4 * V_5 ;
struct V_6 * V_6 = NULL ;
long V_7 = V_8 ;
if ( V_2 ) {
V_7 = * V_2 ;
if ( V_7 < V_9 )
V_7 = V_9 ;
}
V_1 -> V_10 . V_11 = 0 ;
F_2 ( V_7 < V_12 ) ;
V_6 = F_3 ( 1 << ( V_7 - V_13 ) ) ;
if ( V_6 ) {
V_3 = ( unsigned long ) F_4 ( F_5 ( V_6 ) ) ;
V_1 -> V_10 . V_11 = 1 ;
}
while ( ! V_3 && V_7 > V_9 ) {
V_3 = F_6 ( V_14 | V_15 | V_16 |
V_17 , V_7 - V_13 ) ;
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
F_11 ( V_6 , 1 << ( V_7 - V_13 ) ) ;
else
F_12 ( V_3 , V_7 - V_13 ) ;
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
1 << ( V_1 -> V_10 . V_20 - V_13 ) ) ;
else
F_12 ( V_1 -> V_10 . V_19 ,
V_1 -> V_10 . V_20 - V_13 ) ;
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
V_42 = V_39 -> V_42 >> ( V_40 - V_13 ) ;
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
V_86 = V_85 -> V_98 + ( ( V_75 - V_85 -> V_92 ) >> V_13 ) ;
if ( V_47 > V_99 && ( V_86 & ( ( V_47 >> V_13 ) - 1 ) ) )
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
V_86 = F_5 ( V_6 ) ;
}
V_42 = V_34 >> V_13 ;
V_83 = F_50 ( V_42 ) ;
V_80 += ( V_74 - V_39 -> V_88 ) & ~ ( V_42 - 1 ) ;
F_51 ( & V_1 -> V_10 . V_102 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; ++ V_41 ) {
if ( ! V_80 [ V_41 ] ) {
V_80 [ V_41 ] = ( ( V_86 + V_41 ) << V_13 ) +
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
V_74 = V_108 >> V_13 ;
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
unsigned long V_183 , V_184 ;
unsigned long V_108 , V_74 , V_185 , V_86 ;
struct V_38 * V_39 ;
unsigned long * V_186 ;
struct V_4 * V_5 ;
struct V_6 * V_6 , * V_78 [ 1 ] ;
long V_146 , V_51 , V_42 ;
unsigned long V_81 ;
unsigned int V_187 , V_188 ;
struct V_84 * V_85 ;
unsigned long V_189 ;
if ( V_134 != V_37 -> V_10 . V_190 )
return V_176 ;
V_146 = V_37 -> V_10 . V_191 ;
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
if ( V_180 [ 0 ] != V_37 -> V_10 . V_192 [ 0 ] ||
V_180 [ 1 ] != V_37 -> V_10 . V_192 [ 1 ] )
return V_176 ;
V_47 = F_53 ( V_180 [ 0 ] , V_133 ) ;
V_183 = V_133 & V_115 & ~ ( V_47 - 1 ) ;
V_184 = V_183 >> V_13 ;
V_108 = V_183 | ( V_134 & ( V_47 - 1 ) ) ;
V_74 = V_108 >> V_13 ;
V_39 = F_54 ( V_1 , V_74 ) ;
if ( ! V_39 || ( V_39 -> V_103 & V_116 ) )
return F_69 ( V_170 , V_37 , V_108 , V_134 ,
V_179 & V_193 ) ;
if ( ! V_1 -> V_10 . V_109 )
return - V_194 ;
if ( V_184 < V_39 -> V_88 )
return - V_194 ;
V_181 = V_1 -> V_195 ;
F_77 () ;
V_81 = 0 ;
V_86 = 0 ;
V_6 = NULL ;
V_182 = V_99 ;
V_187 = ( V_179 & V_193 ) != 0 ;
V_188 = V_187 ;
V_185 = F_37 ( V_39 , V_74 ) ;
V_42 = F_38 ( V_185 , 1 , V_187 , V_78 ) ;
if ( V_42 < 1 ) {
F_39 ( & V_89 -> V_90 -> V_91 ) ;
V_85 = F_40 ( V_89 -> V_90 , V_185 ) ;
if ( V_85 && V_85 -> V_92 <= V_185 && V_185 + V_47 <= V_85 -> V_93 &&
( V_85 -> V_94 & V_95 ) ) {
V_86 = V_85 -> V_98 +
( ( V_185 - V_85 -> V_92 ) >> V_13 ) ;
V_182 = V_47 ;
V_81 = F_41 ( F_42 ( V_85 -> V_97 ) ) ;
V_188 = V_85 -> V_94 & V_196 ;
}
F_43 ( & V_89 -> V_90 -> V_91 ) ;
if ( ! V_86 )
return - V_194 ;
} else {
V_6 = V_78 [ 0 ] ;
V_86 = F_5 ( V_6 ) ;
if ( F_44 ( V_6 ) ) {
V_6 = F_45 ( V_6 ) ;
V_182 <<= F_46 ( V_6 ) ;
}
if ( ! V_187 && F_78 ( V_133 ) ) {
unsigned int V_197 ;
T_4 * V_198 , V_199 ;
F_55 () ;
V_198 = F_79 ( V_89 -> V_90 -> V_117 ,
V_185 , & V_197 ) ;
if ( V_198 ) {
V_199 = F_80 ( V_198 , 1 ,
V_197 ) ;
if ( F_81 ( V_199 ) )
V_188 = 1 ;
}
F_57 () ;
}
}
V_51 = - V_194 ;
if ( V_47 > V_182 )
goto V_200;
if ( ! F_82 ( V_133 , V_81 ) ) {
if ( V_81 )
return - V_194 ;
V_133 = ( V_133 & ~ ( V_201 | V_202 | V_164 ) ) | V_57 ;
}
if ( V_47 < V_99 )
V_47 = V_99 ;
V_133 = ( V_133 & ~ ( V_155 - V_47 ) ) | ( ( V_86 << V_13 ) & ~ ( V_47 - 1 ) ) ;
if ( F_78 ( V_133 ) && ! V_188 )
V_133 = F_83 ( V_133 ) ;
V_51 = V_176 ;
F_62 () ;
while ( ! F_75 ( V_145 , V_112 ) )
F_76 () ;
if ( ( V_145 [ 0 ] & ~ V_112 ) != V_180 [ 0 ] || V_145 [ 1 ] != V_180 [ 1 ] ||
V_5 -> V_152 != V_180 [ 2 ] )
goto V_203;
V_180 [ 0 ] = ( V_180 [ 0 ] & ~ V_113 ) | V_114 ;
V_186 = & V_39 -> V_10 . V_186 [ V_184 - V_39 -> V_88 ] ;
F_84 ( V_186 ) ;
V_51 = V_176 ;
if ( F_85 ( V_37 -> V_1 , V_181 ) ) {
F_86 ( V_186 ) ;
goto V_203;
}
V_189 = * V_186 >> V_204 ;
V_133 &= V_189 | ~ ( V_55 | V_56 ) ;
if ( V_145 [ 0 ] & V_114 ) {
F_86 ( V_186 ) ;
V_145 [ 0 ] |= V_113 ;
F_87 ( V_1 , V_145 , V_146 ) ;
V_133 |= V_145 [ 1 ] & ( V_55 | V_56 ) ;
} else {
F_88 ( V_1 , V_5 , V_186 , V_146 , 0 ) ;
}
V_145 [ 1 ] = V_133 ;
F_89 () ;
V_145 [ 0 ] = V_180 [ 0 ] ;
asm volatile("ptesync" : : : "memory");
F_64 () ;
if ( V_6 && F_78 ( V_133 ) )
F_90 ( V_6 ) ;
V_200:
if ( V_6 ) {
F_49 ( V_78 [ 0 ] ) ;
}
return V_51 ;
V_203:
V_145 [ 0 ] &= ~ V_112 ;
F_64 () ;
goto V_200;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_205 * V_206 ;
struct V_38 * V_39 ;
int V_207 ;
V_207 = F_91 ( & V_1 -> V_208 ) ;
V_206 = V_1 -> V_209 ;
F_92 (memslot, slots) {
memset ( V_39 -> V_10 . V_186 , 0 ,
V_39 -> V_42 * sizeof( * V_39 -> V_10 . V_186 ) ) ;
}
F_93 ( & V_1 -> V_208 , V_207 ) ;
}
static int F_94 ( struct V_1 * V_1 ,
unsigned long V_75 ,
unsigned long V_210 ,
int (* F_95)( struct V_1 * V_1 ,
unsigned long * V_211 ,
unsigned long V_74 ) )
{
int V_51 ;
int V_212 = 0 ;
struct V_205 * V_206 ;
struct V_38 * V_39 ;
V_206 = V_205 ( V_1 ) ;
F_92 (memslot, slots) {
unsigned long V_213 , V_214 ;
T_5 V_74 , V_215 ;
V_213 = F_96 ( V_75 , V_39 -> V_101 ) ;
V_214 = F_97 ( V_210 , V_39 -> V_101 +
( V_39 -> V_42 << V_13 ) ) ;
if ( V_213 >= V_214 )
continue;
V_74 = F_98 ( V_213 , V_39 ) ;
V_215 = F_98 ( V_214 + V_99 - 1 , V_39 ) ;
for (; V_74 < V_215 ; ++ V_74 ) {
T_5 V_216 = V_74 - V_39 -> V_88 ;
V_51 = F_95 ( V_1 , & V_39 -> V_10 . V_186 [ V_216 ] , V_74 ) ;
V_212 |= V_51 ;
}
}
return V_212 ;
}
static int F_99 ( struct V_1 * V_1 , unsigned long V_185 ,
int (* F_95)( struct V_1 * V_1 , unsigned long * V_211 ,
unsigned long V_74 ) )
{
return F_94 ( V_1 , V_185 , V_185 + 1 , F_95 ) ;
}
static int F_100 ( struct V_1 * V_1 , unsigned long * V_211 ,
unsigned long V_74 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_217 , V_41 , V_218 ;
unsigned long * V_145 ;
unsigned long V_106 , V_47 , V_189 ;
for (; ; ) {
F_84 ( V_211 ) ;
if ( ! ( * V_211 & V_219 ) ) {
F_86 ( V_211 ) ;
break;
}
V_41 = * V_211 & V_220 ;
V_145 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
if ( ! F_75 ( V_145 , V_112 ) ) {
F_86 ( V_211 ) ;
while ( V_145 [ 0 ] & V_112 )
F_76 () ;
continue;
}
V_218 = V_5 [ V_41 ] . V_221 ;
if ( V_218 == V_41 ) {
* V_211 &= ~ ( V_219 | V_220 ) ;
} else {
V_217 = V_5 [ V_41 ] . V_222 ;
V_5 [ V_217 ] . V_221 = V_218 ;
V_5 [ V_218 ] . V_222 = V_217 ;
V_5 [ V_41 ] . V_221 = V_5 [ V_41 ] . V_222 = V_41 ;
* V_211 = ( * V_211 & ~ V_220 ) | V_218 ;
}
V_106 = V_5 [ V_41 ] . V_152 ;
V_47 = F_53 ( V_145 [ 0 ] , V_106 ) ;
if ( ( V_145 [ 0 ] & V_114 ) &&
F_101 ( V_106 , V_47 ) == V_74 ) {
if ( V_1 -> V_10 . V_109 )
V_145 [ 0 ] |= V_113 ;
F_87 ( V_1 , V_145 , V_41 ) ;
V_189 = V_145 [ 1 ] & ( V_55 | V_56 ) ;
* V_211 |= V_189 << V_204 ;
if ( V_189 & ~ V_5 [ V_41 ] . V_152 ) {
V_5 [ V_41 ] . V_152 = V_106 | V_189 ;
F_102 ( V_1 , & V_5 [ V_41 ] ) ;
}
}
F_86 ( V_211 ) ;
V_145 [ 0 ] &= ~ V_112 ;
}
return 0 ;
}
int F_103 ( struct V_1 * V_1 , unsigned long V_185 )
{
if ( V_1 -> V_10 . V_109 )
F_99 ( V_1 , V_185 , F_100 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_1 , unsigned long V_75 , unsigned long V_210 )
{
if ( V_1 -> V_10 . V_109 )
F_94 ( V_1 , V_75 , V_210 , F_100 ) ;
return 0 ;
}
void F_105 ( struct V_1 * V_1 ,
struct V_38 * V_39 )
{
unsigned long * V_211 ;
unsigned long V_74 ;
unsigned long V_223 ;
V_211 = V_39 -> V_10 . V_186 ;
V_74 = V_39 -> V_88 ;
for ( V_223 = V_39 -> V_42 ; V_223 ; -- V_223 ) {
if ( * V_211 & V_219 )
F_100 ( V_1 , V_211 , V_74 ) ;
++ V_211 ;
++ V_74 ;
}
}
static int F_106 ( struct V_1 * V_1 , unsigned long * V_211 ,
unsigned long V_74 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_224 , V_41 , V_218 ;
unsigned long * V_145 ;
int V_51 = 0 ;
V_225:
F_84 ( V_211 ) ;
if ( * V_211 & V_226 ) {
* V_211 &= ~ V_226 ;
V_51 = 1 ;
}
if ( ! ( * V_211 & V_219 ) ) {
F_86 ( V_211 ) ;
return V_51 ;
}
V_41 = V_224 = * V_211 & V_220 ;
do {
V_145 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_218 = V_5 [ V_41 ] . V_221 ;
if ( ! ( V_145 [ 1 ] & V_55 ) )
continue;
if ( ! F_75 ( V_145 , V_112 ) ) {
F_86 ( V_211 ) ;
while ( V_145 [ 0 ] & V_112 )
F_76 () ;
goto V_225;
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
} while ( ( V_41 = V_218 ) != V_224 );
F_86 ( V_211 ) ;
return V_51 ;
}
int F_108 ( struct V_1 * V_1 , unsigned long V_185 )
{
if ( ! V_1 -> V_10 . V_109 )
return 0 ;
return F_99 ( V_1 , V_185 , F_106 ) ;
}
static int F_109 ( struct V_1 * V_1 , unsigned long * V_211 ,
unsigned long V_74 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_224 , V_41 , V_218 ;
unsigned long * V_227 ;
int V_51 = 1 ;
if ( * V_211 & V_226 )
return 1 ;
F_84 ( V_211 ) ;
if ( * V_211 & V_226 )
goto V_32;
if ( * V_211 & V_219 ) {
V_41 = V_224 = * V_211 & V_220 ;
do {
V_227 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_218 = V_5 [ V_41 ] . V_221 ;
if ( V_227 [ 1 ] & V_55 )
goto V_32;
} while ( ( V_41 = V_218 ) != V_224 );
}
V_51 = 0 ;
V_32:
F_86 ( V_211 ) ;
return V_51 ;
}
int F_110 ( struct V_1 * V_1 , unsigned long V_185 )
{
if ( ! V_1 -> V_10 . V_109 )
return 0 ;
return F_99 ( V_1 , V_185 , F_109 ) ;
}
void F_111 ( struct V_1 * V_1 , unsigned long V_185 , T_4 V_199 )
{
if ( ! V_1 -> V_10 . V_109 )
return;
F_99 ( V_1 , V_185 , F_100 ) ;
}
static int V_31 ( struct V_1 * V_1 )
{
return F_16 ( & V_1 -> V_10 . V_31 ) != 0 ;
}
static int F_112 ( struct V_1 * V_1 , unsigned long * V_211 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_224 , V_41 , V_218 ;
unsigned long V_223 ;
unsigned long V_132 , V_133 ;
unsigned long * V_145 ;
int V_228 = 0 ;
V_225:
F_84 ( V_211 ) ;
if ( * V_211 & V_229 ) {
* V_211 &= ~ V_229 ;
V_228 = 1 ;
}
if ( ! ( * V_211 & V_219 ) ) {
F_86 ( V_211 ) ;
return V_228 ;
}
V_41 = V_224 = * V_211 & V_220 ;
do {
V_145 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_218 = V_5 [ V_41 ] . V_221 ;
if ( ! ( V_145 [ 1 ] & V_56 ) &&
( ! F_78 ( V_145 [ 1 ] ) || V_31 ( V_1 ) ) )
continue;
if ( ! F_75 ( V_145 , V_112 ) ) {
F_86 ( V_211 ) ;
while ( V_145 [ 0 ] & V_112 )
F_76 () ;
goto V_225;
}
if ( ! ( V_145 [ 0 ] & V_114 ) )
continue;
V_145 [ 0 ] |= V_113 ;
F_87 ( V_1 , V_145 , V_41 ) ;
V_132 = V_145 [ 0 ] ;
V_133 = V_145 [ 1 ] ;
if ( V_133 & V_56 ) {
V_145 [ 1 ] = V_133 & ~ V_56 ;
if ( ! ( V_5 [ V_41 ] . V_152 & V_56 ) ) {
V_5 [ V_41 ] . V_152 |= V_56 ;
F_102 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_223 = F_53 ( V_132 , V_133 ) ;
V_223 = ( V_223 + V_99 - 1 ) >> V_13 ;
if ( V_223 > V_228 )
V_228 = V_223 ;
F_89 () ;
}
V_132 &= ~ ( V_113 | V_112 ) ;
V_132 |= V_114 ;
V_145 [ 0 ] = V_132 ;
} while ( ( V_41 = V_218 ) != V_224 );
F_86 ( V_211 ) ;
return V_228 ;
}
static void F_113 ( struct V_230 * V_231 ,
struct V_38 * V_39 ,
unsigned long * V_232 )
{
unsigned long V_74 ;
if ( ! V_231 -> V_233 || ! V_231 -> V_234 )
return;
V_74 = V_231 -> V_108 >> V_13 ;
if ( V_74 < V_39 -> V_88 ||
V_74 >= V_39 -> V_88 + V_39 -> V_42 )
return;
V_231 -> V_233 = false ;
if ( V_232 )
F_114 ( V_74 - V_39 -> V_88 , V_232 ) ;
}
long F_115 ( struct V_1 * V_1 , struct V_38 * V_39 ,
unsigned long * V_232 )
{
unsigned long V_41 , V_218 ;
unsigned long * V_211 ;
struct V_36 * V_37 ;
F_62 () ;
V_211 = V_39 -> V_10 . V_186 ;
for ( V_41 = 0 ; V_41 < V_39 -> V_42 ; ++ V_41 ) {
int V_42 = F_112 ( V_1 , V_211 ) ;
if ( V_42 && V_232 )
for ( V_218 = V_41 ; V_42 ; ++ V_218 , -- V_42 )
F_114 ( V_218 , V_232 ) ;
++ V_211 ;
}
F_116 (i, vcpu, kvm) {
F_51 ( & V_37 -> V_10 . V_235 ) ;
F_113 ( & V_37 -> V_10 . V_231 , V_39 , V_232 ) ;
F_113 ( & V_37 -> V_10 . V_236 , V_39 , V_232 ) ;
F_52 ( & V_37 -> V_10 . V_235 ) ;
}
F_64 () ;
return 0 ;
}
void * F_117 ( struct V_1 * V_1 , unsigned long V_108 ,
unsigned long * V_237 )
{
struct V_38 * V_39 ;
unsigned long V_74 = V_108 >> V_13 ;
struct V_6 * V_6 , * V_78 [ 1 ] ;
int V_42 ;
unsigned long V_185 , V_238 ;
unsigned long V_239 ;
unsigned long * V_80 ;
int V_207 ;
V_207 = F_91 ( & V_1 -> V_208 ) ;
V_39 = F_54 ( V_1 , V_74 ) ;
if ( ! V_39 || ( V_39 -> V_103 & V_116 ) )
goto V_27;
if ( ! V_1 -> V_10 . V_109 ) {
V_80 = V_39 -> V_10 . V_87 ;
if ( ! V_80 )
goto V_27;
V_80 += V_74 - V_39 -> V_88 ;
V_239 = * V_80 ;
if ( ! V_239 ) {
if ( F_36 ( V_1 , V_74 , V_39 ,
V_99 ) < 0 )
goto V_27;
V_239 = * V_80 ;
}
V_6 = F_118 ( V_239 >> V_13 ) ;
F_48 ( V_6 ) ;
} else {
V_185 = F_37 ( V_39 , V_74 ) ;
V_42 = F_38 ( V_185 , 1 , 1 , V_78 ) ;
if ( V_42 < 1 )
goto V_27;
V_6 = V_78 [ 0 ] ;
}
F_93 ( & V_1 -> V_208 , V_207 ) ;
V_238 = V_108 & ( V_99 - 1 ) ;
if ( V_237 )
* V_237 = V_99 - V_238 ;
return F_119 ( V_6 ) + V_238 ;
V_27:
F_93 ( & V_1 -> V_208 , V_207 ) ;
return NULL ;
}
void F_120 ( struct V_1 * V_1 , void * V_240 , unsigned long V_108 ,
bool V_233 )
{
struct V_6 * V_6 = F_23 ( V_240 ) ;
struct V_38 * V_39 ;
unsigned long V_74 ;
unsigned long * V_186 ;
int V_207 ;
F_49 ( V_6 ) ;
if ( ! V_233 || ! V_1 -> V_10 . V_109 )
return;
V_74 = V_108 >> V_13 ;
V_207 = F_91 ( & V_1 -> V_208 ) ;
V_39 = F_54 ( V_1 , V_74 ) ;
if ( V_39 ) {
V_186 = & V_39 -> V_10 . V_186 [ V_74 - V_39 -> V_88 ] ;
F_84 ( V_186 ) ;
* V_186 |= V_229 ;
F_86 ( V_186 ) ;
}
F_93 ( & V_1 -> V_208 , V_207 ) ;
}
static int F_121 ( struct V_4 * V_241 , unsigned long * V_242 )
{
unsigned long V_243 ;
if ( V_241 -> V_152 & V_244 )
return 1 ;
V_243 = ~ V_241 -> V_152 & ( V_55 | V_56 ) ;
if ( ( V_242 [ 0 ] & V_114 ) && ( V_242 [ 1 ] & V_243 ) )
return 1 ;
return 0 ;
}
static long F_122 ( unsigned long V_103 , unsigned long * V_242 ,
unsigned long * V_180 , struct V_4 * V_241 ,
int V_245 , int V_246 )
{
unsigned long V_132 , V_133 ;
unsigned long V_243 ;
int V_247 = 1 ;
int V_248 , V_233 ;
V_233 = F_121 ( V_241 , V_242 ) ;
if ( ! V_246 && ! V_233 )
return 0 ;
V_248 = 0 ;
if ( V_242 [ 0 ] & ( V_114 | V_113 ) ) {
V_248 = 1 ;
if ( ( V_103 & V_249 ) &&
! ( V_242 [ 0 ] & V_54 ) )
V_248 = 0 ;
}
if ( V_248 != V_245 )
return 0 ;
V_132 = V_133 = 0 ;
if ( V_248 || V_233 ) {
F_62 () ;
while ( ! F_75 ( V_242 , V_112 ) )
F_76 () ;
V_132 = V_242 [ 0 ] ;
V_248 = ! ! ( V_132 & V_114 ) ;
V_233 = ! ! ( V_241 -> V_152 & V_244 ) ;
V_243 = ~ V_241 -> V_152 & ( V_55 | V_56 ) ;
if ( V_248 && ( V_243 & V_242 [ 1 ] ) ) {
V_241 -> V_152 |= ( V_242 [ 1 ] & ( V_55 | V_56 ) ) |
V_244 ;
V_233 = 1 ;
}
if ( V_132 & V_113 ) {
V_132 &= ~ V_113 ;
V_132 |= V_114 ;
V_248 = 1 ;
}
if ( ( V_103 & V_249 ) && ! ( V_132 & V_54 ) )
V_248 = 0 ;
V_133 = V_241 -> V_152 ;
if ( V_248 == V_245 && V_233 ) {
V_133 &= ~ V_244 ;
V_241 -> V_152 = V_133 ;
}
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_242 [ 0 ] &= ~ V_112 ;
F_64 () ;
if ( ! ( V_248 == V_245 && ( V_246 || V_233 ) ) )
V_247 = 0 ;
}
V_180 [ 0 ] = V_132 ;
V_180 [ 1 ] = V_133 ;
return V_247 ;
}
static T_6 F_123 ( struct V_250 * V_250 , char T_7 * V_251 ,
T_8 V_252 , T_9 * V_253 )
{
struct V_254 * V_255 = V_250 -> V_256 ;
struct V_1 * V_1 = V_255 -> V_1 ;
struct V_257 V_258 ;
unsigned long * V_242 ;
struct V_4 * V_241 ;
unsigned long V_41 , V_259 , V_260 ;
unsigned long T_7 * V_261 ;
struct V_257 T_7 * V_262 ;
unsigned long V_103 ;
int V_246 ;
unsigned long V_180 [ 2 ] ;
if ( ! F_124 ( V_263 , V_251 , V_252 ) )
return - V_194 ;
V_246 = V_255 -> V_246 ;
V_103 = V_255 -> V_103 ;
V_41 = V_255 -> V_146 ;
V_242 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 * V_264 ) ) ;
V_241 = V_1 -> V_10 . V_24 + V_41 ;
V_261 = ( unsigned long T_7 * ) V_251 ;
V_259 = 0 ;
while ( V_259 + sizeof( V_258 ) + V_264 < V_252 ) {
V_262 = (struct V_257 T_7 * ) V_251 ;
V_258 . V_265 = 0 ;
V_258 . V_266 = 0 ;
V_260 = V_259 ;
V_259 += sizeof( V_258 ) ;
V_261 = ( unsigned long T_7 * ) ( V_251 + sizeof( V_258 ) ) ;
if ( ! V_246 ) {
while ( V_41 < V_1 -> V_10 . V_21 &&
! F_121 ( V_241 , V_242 ) ) {
++ V_41 ;
V_242 += 2 ;
++ V_241 ;
}
}
V_258 . V_146 = V_41 ;
while ( V_41 < V_1 -> V_10 . V_21 &&
V_258 . V_265 < 0xffff &&
V_259 + V_264 < V_252 &&
F_122 ( V_103 , V_242 , V_180 , V_241 , 1 , V_246 ) ) {
++ V_258 . V_265 ;
if ( F_125 ( V_180 [ 0 ] , V_261 ) ||
F_125 ( V_180 [ 1 ] , V_261 + 1 ) )
return - V_194 ;
V_259 += V_264 ;
V_261 += 2 ;
++ V_41 ;
V_242 += 2 ;
++ V_241 ;
}
while ( V_41 < V_1 -> V_10 . V_21 &&
V_258 . V_266 < 0xffff &&
F_122 ( V_103 , V_242 , V_180 , V_241 , 0 , V_246 ) ) {
++ V_258 . V_266 ;
++ V_41 ;
V_242 += 2 ;
++ V_241 ;
}
if ( V_258 . V_265 || V_258 . V_266 ) {
if ( F_126 ( V_262 , & V_258 , sizeof( V_258 ) ) )
return - V_194 ;
V_260 = V_259 ;
V_251 = ( char T_7 * ) V_261 ;
} else {
V_259 = V_260 ;
}
if ( V_41 >= V_1 -> V_10 . V_21 ) {
V_41 = 0 ;
V_255 -> V_246 = 0 ;
break;
}
}
V_255 -> V_146 = V_41 ;
return V_259 ;
}
static T_6 F_127 ( struct V_250 * V_250 , const char T_7 * V_251 ,
T_8 V_252 , T_9 * V_253 )
{
struct V_254 * V_255 = V_250 -> V_256 ;
struct V_1 * V_1 = V_255 -> V_1 ;
struct V_257 V_258 ;
unsigned long V_41 , V_218 ;
unsigned long V_132 , V_133 ;
unsigned long T_7 * V_261 ;
unsigned long * V_242 ;
unsigned long V_267 [ 2 ] ;
T_6 V_259 ;
long int V_27 , V_51 ;
int V_268 ;
if ( ! F_124 ( V_269 , V_251 , V_252 ) )
return - V_194 ;
F_14 ( & V_1 -> V_29 ) ;
V_268 = V_1 -> V_10 . V_30 ;
if ( V_268 ) {
V_1 -> V_10 . V_30 = 0 ;
F_15 () ;
if ( F_16 ( & V_1 -> V_10 . V_31 ) ) {
V_1 -> V_10 . V_30 = 1 ;
F_19 ( & V_1 -> V_29 ) ;
return - V_28 ;
}
}
V_27 = 0 ;
for ( V_259 = 0 ; V_259 + sizeof( V_258 ) <= V_252 ; ) {
V_27 = - V_194 ;
if ( F_128 ( & V_258 , V_251 , sizeof( V_258 ) ) )
break;
V_27 = 0 ;
if ( V_259 + V_258 . V_265 * V_264 > V_252 )
break;
V_259 += sizeof( V_258 ) ;
V_251 += sizeof( V_258 ) ;
V_27 = - V_64 ;
V_41 = V_258 . V_146 ;
if ( V_41 >= V_1 -> V_10 . V_21 ||
V_41 + V_258 . V_265 + V_258 . V_266 > V_1 -> V_10 . V_21 )
break;
V_242 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 * V_264 ) ) ;
V_261 = ( unsigned long T_7 * ) V_251 ;
for ( V_218 = 0 ; V_218 < V_258 . V_265 ; ++ V_218 ) {
V_27 = - V_194 ;
if ( F_129 ( V_132 , V_261 ) || F_129 ( V_133 , V_261 + 1 ) )
goto V_32;
V_27 = - V_64 ;
if ( ! ( V_132 & V_114 ) )
goto V_32;
V_261 += 2 ;
V_259 += V_264 ;
if ( V_242 [ 0 ] & ( V_114 | V_113 ) )
F_130 ( V_1 , 0 , V_41 , 0 , V_267 ) ;
V_27 = - V_270 ;
V_51 = F_27 ( V_1 , V_59 , V_41 , V_132 , V_133 ,
V_267 ) ;
if ( V_51 != V_60 ) {
F_8 ( L_5
L_6 , V_51 , V_41 , V_132 , V_133 ) ;
goto V_32;
}
if ( ! V_268 && F_131 ( V_132 ) ) {
unsigned long V_47 = F_132 ( V_132 , V_133 ) ;
unsigned long V_271 = F_133 ( V_47 ) ;
unsigned long V_272 ;
V_1 -> V_10 . V_150 = V_271 | V_129 |
( V_53 << V_273 ) ;
V_272 = V_271 << ( V_274 - 4 ) ;
F_134 ( V_1 , V_272 , V_275 ) ;
V_268 = 1 ;
}
++ V_41 ;
V_242 += 2 ;
}
for ( V_218 = 0 ; V_218 < V_258 . V_266 ; ++ V_218 ) {
if ( V_242 [ 0 ] & ( V_114 | V_113 ) )
F_130 ( V_1 , 0 , V_41 , 0 , V_267 ) ;
++ V_41 ;
V_242 += 2 ;
}
V_27 = 0 ;
}
V_32:
F_135 () ;
V_1 -> V_10 . V_30 = V_268 ;
F_19 ( & V_1 -> V_29 ) ;
if ( V_27 )
return V_27 ;
return V_259 ;
}
static int F_136 ( struct V_276 * V_276 , struct V_250 * V_277 )
{
struct V_254 * V_255 = V_277 -> V_256 ;
V_277 -> V_256 = NULL ;
if ( ! ( V_255 -> V_103 & V_278 ) )
F_137 ( & V_255 -> V_1 -> V_10 . V_279 ) ;
F_138 ( V_255 -> V_1 ) ;
F_139 ( V_255 ) ;
return 0 ;
}
int F_140 ( struct V_1 * V_1 , struct V_280 * V_281 )
{
int V_51 ;
struct V_254 * V_255 ;
int V_282 ;
if ( V_281 -> V_103 & ~ ( V_249 | V_278 ) )
return - V_64 ;
V_255 = F_141 ( sizeof( * V_255 ) , V_14 ) ;
if ( ! V_255 )
return - V_18 ;
F_142 ( V_1 ) ;
V_255 -> V_1 = V_1 ;
V_255 -> V_146 = V_281 -> V_283 ;
V_255 -> V_103 = V_281 -> V_103 ;
V_255 -> V_246 = 1 ;
V_282 = ( V_281 -> V_103 & V_278 ) ? V_284 : V_285 ;
V_51 = F_143 ( L_7 , & V_286 , V_255 , V_282 | V_287 ) ;
if ( V_51 < 0 ) {
F_138 ( V_1 ) ;
return V_51 ;
}
if ( V_282 == V_285 ) {
F_14 ( & V_1 -> V_288 ) ;
F_144 ( & V_1 -> V_10 . V_279 ) ;
F_145 ( & V_1 -> V_208 ) ;
F_19 ( & V_1 -> V_288 ) ;
}
return V_51 ;
}
void F_146 ( struct V_36 * V_37 )
{
struct V_289 * V_290 = & V_37 -> V_10 . V_290 ;
if ( F_29 ( V_65 ) )
V_37 -> V_10 . V_124 = 32 ;
else
V_37 -> V_10 . V_124 = 64 ;
V_290 -> V_291 = F_61 ;
V_290 -> V_292 = F_33 ;
V_37 -> V_10 . V_293 |= V_294 ;
}
