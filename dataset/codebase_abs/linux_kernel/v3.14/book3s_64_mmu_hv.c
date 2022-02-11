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
F_34 ( V_37 , V_37 -> V_10 . V_69 ) ;
}
static long F_35 ( struct V_1 * V_1 , unsigned long V_70 ,
struct V_38 * V_39 ,
unsigned long V_47 )
{
unsigned long V_71 ;
long V_72 , V_27 ;
struct V_6 * V_6 , * V_73 , * V_74 [ 1 ] ;
unsigned long V_75 , V_34 ;
unsigned long * V_76 ;
unsigned int V_77 , V_78 , V_79 ;
struct V_80 * V_81 ;
unsigned long V_82 , V_41 , V_42 ;
V_76 = V_39 -> V_10 . V_83 ;
if ( ! V_76 )
return - V_64 ;
if ( V_76 [ V_70 - V_39 -> V_84 ] )
return 0 ;
V_77 = 0 ;
V_78 = 0 ;
V_6 = NULL ;
V_34 = V_47 ;
V_27 = - V_64 ;
V_71 = F_36 ( V_39 , V_70 ) ;
V_72 = F_37 ( V_71 , 1 , 1 , V_74 ) ;
if ( V_72 != 1 ) {
F_38 ( & V_85 -> V_86 -> V_87 ) ;
V_81 = F_39 ( V_85 -> V_86 , V_71 ) ;
if ( ! V_81 || V_81 -> V_88 > V_71 ||
V_71 + V_47 > V_81 -> V_89 ||
! ( V_81 -> V_90 & V_91 ) )
goto V_92;
V_77 = F_40 ( F_41 ( V_81 -> V_93 ) ) ;
V_82 = V_81 -> V_94 + ( ( V_71 - V_81 -> V_88 ) >> V_16 ) ;
if ( V_47 > V_95 && ( V_82 & ( ( V_47 >> V_16 ) - 1 ) ) )
goto V_92;
F_42 ( & V_85 -> V_86 -> V_87 ) ;
} else {
V_6 = V_74 [ 0 ] ;
V_78 = V_96 ;
V_75 = V_95 ;
if ( F_43 ( V_6 ) ) {
V_73 = F_44 ( V_6 ) ;
V_75 <<= F_45 ( V_73 ) ;
if ( V_75 > V_47 && F_46 ( V_39 , V_75 ) &&
! ( V_39 -> V_97 & ( V_75 - 1 ) ) ) {
V_71 &= ~ ( V_75 - 1 ) ;
V_34 = V_75 ;
F_47 ( V_73 ) ;
F_48 ( V_6 ) ;
V_6 = V_73 ;
}
}
if ( V_75 < V_47 )
goto V_32;
V_82 = F_6 ( V_6 ) ;
}
V_42 = V_34 >> V_16 ;
V_79 = F_49 ( V_42 ) ;
V_76 += ( V_70 - V_39 -> V_84 ) & ~ ( V_42 - 1 ) ;
F_50 ( & V_1 -> V_10 . V_98 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; ++ V_41 ) {
if ( ! V_76 [ V_41 ] ) {
V_76 [ V_41 ] = ( ( V_82 + V_41 ) << V_16 ) +
V_78 + V_77 + V_79 ;
V_78 = 0 ;
}
}
F_51 ( & V_1 -> V_10 . V_98 ) ;
V_27 = 0 ;
V_32:
if ( V_78 )
F_48 ( V_6 ) ;
return V_27 ;
V_92:
F_42 ( & V_85 -> V_86 -> V_87 ) ;
return V_27 ;
}
long F_27 ( struct V_1 * V_1 , unsigned long V_99 ,
long V_100 , unsigned long V_101 ,
unsigned long V_102 , unsigned long * V_103 )
{
unsigned long V_47 , V_104 , V_70 ;
struct V_38 * V_39 ;
long V_51 ;
if ( V_1 -> V_10 . V_105 )
goto V_106;
V_47 = F_52 ( V_101 , V_102 ) ;
if ( ! V_47 )
return V_107 ;
V_101 &= ~ ( V_108 | V_109 | V_110 ) ;
V_104 = ( V_102 & V_111 ) & ~ ( V_47 - 1 ) ;
V_70 = V_104 >> V_16 ;
V_39 = F_53 ( V_1 , V_70 ) ;
if ( V_39 && ! ( V_39 -> V_99 & V_112 ) ) {
if ( ! F_46 ( V_39 , V_47 ) )
return V_107 ;
if ( F_35 ( V_1 , V_70 , V_39 , V_47 ) < 0 )
return V_107 ;
}
V_106:
F_54 () ;
V_51 = F_55 ( V_1 , V_99 , V_100 , V_101 , V_102 ,
V_85 -> V_86 -> V_113 , false , V_103 ) ;
F_56 () ;
if ( V_51 == V_114 ) {
F_8 ( L_4 ) ;
V_51 = V_115 ;
}
return V_51 ;
}
long F_57 ( struct V_36 * V_37 , unsigned long V_99 ,
long V_100 , unsigned long V_101 ,
unsigned long V_102 )
{
return F_27 ( V_37 -> V_1 , V_99 , V_100 ,
V_101 , V_102 , & V_37 -> V_10 . V_116 [ 4 ] ) ;
}
static struct V_117 * F_58 ( struct V_36 * V_37 ,
T_2 V_118 )
{
T_3 V_119 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_37 -> V_10 . V_120 ; V_41 ++ ) {
if ( ! ( V_37 -> V_10 . V_121 [ V_41 ] . V_122 & V_123 ) )
continue;
if ( V_37 -> V_10 . V_121 [ V_41 ] . V_124 & V_125 )
V_119 = V_126 ;
else
V_119 = V_127 ;
if ( ( ( V_37 -> V_10 . V_121 [ V_41 ] . V_122 ^ V_118 ) & V_119 ) == 0 )
return & V_37 -> V_10 . V_121 [ V_41 ] ;
}
return NULL ;
}
static unsigned long F_59 ( unsigned long V_128 , unsigned long V_129 ,
unsigned long V_130 )
{
unsigned long V_131 ;
V_131 = F_52 ( V_128 , V_129 ) - 1 ;
return ( V_129 & V_111 & ~ V_131 ) | ( V_130 & V_131 ) ;
}
static int F_60 ( struct V_36 * V_37 , T_2 V_118 ,
struct V_132 * V_133 , bool V_134 , bool V_135 )
{
struct V_1 * V_1 = V_37 -> V_1 ;
struct V_117 * V_136 ;
unsigned long V_137 ;
unsigned long V_138 , V_139 ;
unsigned long V_128 , V_140 ;
unsigned long * V_141 ;
int V_142 ;
int V_143 = V_37 -> V_10 . V_144 . V_145 & ( V_134 ? V_146 : V_147 ) ;
if ( V_143 ) {
V_136 = F_58 ( V_37 , V_118 ) ;
if ( ! V_136 )
return - V_64 ;
V_137 = V_136 -> V_124 ;
} else {
V_137 = V_37 -> V_1 -> V_10 . V_148 ;
}
F_61 () ;
V_142 = F_62 ( V_1 , V_118 , V_137 ,
V_110 | V_109 ) ;
if ( V_142 < 0 ) {
F_63 () ;
return - V_149 ;
}
V_141 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_142 << 4 ) ) ;
V_128 = V_141 [ 0 ] & ~ V_108 ;
V_140 = V_1 -> V_10 . V_24 [ V_142 ] . V_150 ;
asm volatile("lwsync" : : : "memory");
V_141 [ 0 ] = V_128 ;
F_63 () ;
V_133 -> V_118 = V_118 ;
V_133 -> V_151 = ( ( V_128 & V_152 ) << 4 ) | ( ( V_118 >> 12 ) & 0xfff ) ;
V_138 = V_140 & ( V_153 | V_154 ) ;
V_139 = ( V_37 -> V_10 . V_144 . V_145 & V_155 ) ? V_156 : V_157 ;
V_139 &= V_137 ;
V_133 -> V_158 = F_64 ( V_138 , V_139 ) ;
V_133 -> V_159 = F_65 ( V_138 , V_139 ) ;
V_133 -> V_160 = V_133 -> V_158 && ! ( V_140 & ( V_161 | V_162 ) ) ;
if ( V_134 && V_143 && F_29 ( V_65 ) ) {
int V_163 = F_66 ( V_140 , V_37 -> V_10 . V_164 ) ;
if ( V_163 & 1 )
V_133 -> V_158 = 0 ;
if ( V_163 & 2 )
V_133 -> V_159 = 0 ;
}
V_133 -> V_165 = F_59 ( V_128 , V_140 , V_118 ) ;
return 0 ;
}
static int F_67 ( unsigned int V_166 )
{
unsigned int V_119 ;
V_119 = 0x10000000 ;
if ( ( V_166 & 0xfc000000 ) == 0x7c000000 )
V_119 = 0x100 ;
return ( V_166 & V_119 ) != 0 ;
}
static int F_68 ( struct V_167 * V_168 , struct V_36 * V_37 ,
unsigned long V_104 , T_2 V_130 , int V_169 )
{
int V_51 ;
T_1 V_170 ;
unsigned long V_171 = F_69 ( V_37 ) ;
if ( V_37 -> V_10 . V_170 == V_172 ) {
V_51 = F_70 ( V_37 , & V_171 , sizeof( T_1 ) , & V_170 , false ) ;
if ( V_51 != V_173 || V_170 == V_172 )
return V_174 ;
V_37 -> V_10 . V_170 = V_170 ;
}
if ( F_67 ( F_71 ( V_37 ) ) != ! ! V_169 )
return V_174 ;
V_37 -> V_10 . V_175 = V_104 ;
V_37 -> V_10 . V_176 = V_130 ;
return F_72 ( V_168 , V_37 ) ;
}
int F_73 ( struct V_167 * V_168 , struct V_36 * V_37 ,
unsigned long V_130 , unsigned long V_177 )
{
struct V_1 * V_1 = V_37 -> V_1 ;
unsigned long * V_141 , V_178 [ 3 ] , V_129 ;
unsigned long V_179 , V_47 , V_180 ;
unsigned long V_104 , V_70 , V_181 , V_82 ;
struct V_38 * V_39 ;
unsigned long * V_182 ;
struct V_4 * V_5 ;
struct V_6 * V_6 , * V_74 [ 1 ] ;
long V_142 , V_51 , V_42 ;
unsigned long V_77 ;
unsigned int V_183 , V_184 ;
struct V_80 * V_81 ;
unsigned long V_185 ;
if ( V_130 != V_37 -> V_10 . V_186 )
return V_174 ;
V_142 = V_37 -> V_10 . V_187 ;
V_141 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_142 << 4 ) ) ;
V_5 = & V_1 -> V_10 . V_24 [ V_142 ] ;
F_61 () ;
while ( ! F_74 ( V_141 , V_108 ) )
F_75 () ;
V_178 [ 0 ] = V_141 [ 0 ] & ~ V_108 ;
V_178 [ 1 ] = V_141 [ 1 ] ;
V_178 [ 2 ] = V_129 = V_5 -> V_150 ;
asm volatile("lwsync" : : : "memory");
V_141 [ 0 ] = V_178 [ 0 ] ;
F_63 () ;
if ( V_178 [ 0 ] != V_37 -> V_10 . V_188 [ 0 ] ||
V_178 [ 1 ] != V_37 -> V_10 . V_188 [ 1 ] )
return V_174 ;
V_47 = F_52 ( V_178 [ 0 ] , V_129 ) ;
V_104 = ( V_129 & V_111 & ~ ( V_47 - 1 ) ) | ( V_130 & ( V_47 - 1 ) ) ;
V_70 = V_104 >> V_16 ;
V_39 = F_53 ( V_1 , V_70 ) ;
if ( ! V_39 || ( V_39 -> V_99 & V_112 ) )
return F_68 ( V_168 , V_37 , V_104 , V_130 ,
V_177 & V_189 ) ;
if ( ! V_1 -> V_10 . V_105 )
return - V_190 ;
V_179 = V_1 -> V_191 ;
F_76 () ;
V_77 = 0 ;
V_82 = 0 ;
V_6 = NULL ;
V_180 = V_95 ;
V_183 = ( V_177 & V_189 ) != 0 ;
V_184 = V_183 ;
V_181 = F_36 ( V_39 , V_70 ) ;
V_42 = F_37 ( V_181 , 1 , V_183 , V_74 ) ;
if ( V_42 < 1 ) {
F_38 ( & V_85 -> V_86 -> V_87 ) ;
V_81 = F_39 ( V_85 -> V_86 , V_181 ) ;
if ( V_81 && V_81 -> V_88 <= V_181 && V_181 + V_47 <= V_81 -> V_89 &&
( V_81 -> V_90 & V_91 ) ) {
V_82 = V_81 -> V_94 +
( ( V_181 - V_81 -> V_88 ) >> V_16 ) ;
V_180 = V_47 ;
V_77 = F_40 ( F_41 ( V_81 -> V_93 ) ) ;
V_184 = V_81 -> V_90 & V_192 ;
}
F_42 ( & V_85 -> V_86 -> V_87 ) ;
if ( ! V_82 )
return - V_190 ;
} else {
V_6 = V_74 [ 0 ] ;
V_82 = F_6 ( V_6 ) ;
if ( F_43 ( V_6 ) ) {
V_6 = F_44 ( V_6 ) ;
V_180 <<= F_45 ( V_6 ) ;
}
if ( ! V_183 && F_77 ( V_129 ) ) {
unsigned int V_193 ;
T_4 * V_194 , V_195 ;
F_54 () ;
V_194 = F_78 ( V_85 -> V_86 -> V_113 ,
V_181 , & V_193 ) ;
if ( V_194 ) {
V_195 = F_79 ( V_194 , 1 ,
V_193 ) ;
if ( F_80 ( V_195 ) )
V_184 = 1 ;
}
F_56 () ;
}
}
V_51 = - V_190 ;
if ( V_47 > V_180 )
goto V_196;
if ( ! F_81 ( V_129 , V_77 ) ) {
if ( V_77 )
return - V_190 ;
V_129 = ( V_129 & ~ ( V_197 | V_198 | V_162 ) ) | V_57 ;
}
if ( V_47 < V_95 )
V_47 = V_95 ;
V_129 = ( V_129 & ~ ( V_153 - V_47 ) ) | ( ( V_82 << V_16 ) & ~ ( V_47 - 1 ) ) ;
if ( F_77 ( V_129 ) && ! V_184 )
V_129 = F_82 ( V_129 ) ;
V_51 = V_174 ;
F_61 () ;
while ( ! F_74 ( V_141 , V_108 ) )
F_75 () ;
if ( ( V_141 [ 0 ] & ~ V_108 ) != V_178 [ 0 ] || V_141 [ 1 ] != V_178 [ 1 ] ||
V_5 -> V_150 != V_178 [ 2 ] )
goto V_199;
V_178 [ 0 ] = ( V_178 [ 0 ] & ~ V_109 ) | V_110 ;
V_182 = & V_39 -> V_10 . V_182 [ V_70 - V_39 -> V_84 ] ;
F_83 ( V_182 ) ;
V_51 = V_174 ;
if ( F_84 ( V_37 -> V_1 , V_179 ) ) {
F_85 ( V_182 ) ;
goto V_199;
}
V_185 = * V_182 >> V_200 ;
V_129 &= V_185 | ~ ( V_55 | V_56 ) ;
if ( V_141 [ 0 ] & V_110 ) {
F_85 ( V_182 ) ;
V_141 [ 0 ] |= V_109 ;
F_86 ( V_1 , V_141 , V_142 ) ;
V_129 |= V_141 [ 1 ] & ( V_55 | V_56 ) ;
} else {
F_87 ( V_1 , V_5 , V_182 , V_142 , 0 ) ;
}
V_141 [ 1 ] = V_129 ;
F_88 () ;
V_141 [ 0 ] = V_178 [ 0 ] ;
asm volatile("ptesync" : : : "memory");
F_63 () ;
if ( V_6 && F_77 ( V_129 ) )
F_89 ( V_6 ) ;
V_196:
if ( V_6 ) {
F_48 ( V_74 [ 0 ] ) ;
}
return V_51 ;
V_199:
V_141 [ 0 ] &= ~ V_108 ;
F_63 () ;
goto V_196;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_201 * V_202 ;
struct V_38 * V_39 ;
int V_203 ;
V_203 = F_90 ( & V_1 -> V_204 ) ;
V_202 = V_1 -> V_205 ;
F_91 (memslot, slots) {
memset ( V_39 -> V_10 . V_182 , 0 ,
V_39 -> V_42 * sizeof( * V_39 -> V_10 . V_182 ) ) ;
}
F_92 ( & V_1 -> V_204 , V_203 ) ;
}
static int F_93 ( struct V_1 * V_1 ,
unsigned long V_71 ,
unsigned long V_206 ,
int (* F_94)( struct V_1 * V_1 ,
unsigned long * V_207 ,
unsigned long V_70 ) )
{
int V_51 ;
int V_208 = 0 ;
struct V_201 * V_202 ;
struct V_38 * V_39 ;
V_202 = V_201 ( V_1 ) ;
F_91 (memslot, slots) {
unsigned long V_209 , V_210 ;
T_5 V_70 , V_211 ;
V_209 = F_95 ( V_71 , V_39 -> V_97 ) ;
V_210 = F_96 ( V_206 , V_39 -> V_97 +
( V_39 -> V_42 << V_16 ) ) ;
if ( V_209 >= V_210 )
continue;
V_70 = F_97 ( V_209 , V_39 ) ;
V_211 = F_97 ( V_210 + V_95 - 1 , V_39 ) ;
for (; V_70 < V_211 ; ++ V_70 ) {
T_5 V_212 = V_70 - V_39 -> V_84 ;
V_51 = F_94 ( V_1 , & V_39 -> V_10 . V_182 [ V_212 ] , V_70 ) ;
V_208 |= V_51 ;
}
}
return V_208 ;
}
static int F_98 ( struct V_1 * V_1 , unsigned long V_181 ,
int (* F_94)( struct V_1 * V_1 , unsigned long * V_207 ,
unsigned long V_70 ) )
{
return F_93 ( V_1 , V_181 , V_181 + 1 , F_94 ) ;
}
static int F_99 ( struct V_1 * V_1 , unsigned long * V_207 ,
unsigned long V_70 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_213 , V_41 , V_214 ;
unsigned long * V_141 ;
unsigned long V_102 , V_47 , V_185 ;
for (; ; ) {
F_83 ( V_207 ) ;
if ( ! ( * V_207 & V_215 ) ) {
F_85 ( V_207 ) ;
break;
}
V_41 = * V_207 & V_216 ;
V_141 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
if ( ! F_74 ( V_141 , V_108 ) ) {
F_85 ( V_207 ) ;
while ( V_141 [ 0 ] & V_108 )
F_75 () ;
continue;
}
V_214 = V_5 [ V_41 ] . V_217 ;
if ( V_214 == V_41 ) {
* V_207 &= ~ ( V_215 | V_216 ) ;
} else {
V_213 = V_5 [ V_41 ] . V_218 ;
V_5 [ V_213 ] . V_217 = V_214 ;
V_5 [ V_214 ] . V_218 = V_213 ;
V_5 [ V_41 ] . V_217 = V_5 [ V_41 ] . V_218 = V_41 ;
* V_207 = ( * V_207 & ~ V_216 ) | V_214 ;
}
V_102 = V_5 [ V_41 ] . V_150 ;
V_47 = F_52 ( V_141 [ 0 ] , V_102 ) ;
if ( ( V_141 [ 0 ] & V_110 ) &&
F_100 ( V_102 , V_47 ) == V_70 ) {
if ( V_1 -> V_10 . V_105 )
V_141 [ 0 ] |= V_109 ;
F_86 ( V_1 , V_141 , V_41 ) ;
V_185 = V_141 [ 1 ] & ( V_55 | V_56 ) ;
* V_207 |= V_185 << V_200 ;
if ( V_185 & ~ V_5 [ V_41 ] . V_150 ) {
V_5 [ V_41 ] . V_150 = V_102 | V_185 ;
F_101 ( V_1 , & V_5 [ V_41 ] ) ;
}
}
F_85 ( V_207 ) ;
V_141 [ 0 ] &= ~ V_108 ;
}
return 0 ;
}
int F_102 ( struct V_1 * V_1 , unsigned long V_181 )
{
if ( V_1 -> V_10 . V_105 )
F_98 ( V_1 , V_181 , F_99 ) ;
return 0 ;
}
int F_103 ( struct V_1 * V_1 , unsigned long V_71 , unsigned long V_206 )
{
if ( V_1 -> V_10 . V_105 )
F_93 ( V_1 , V_71 , V_206 , F_99 ) ;
return 0 ;
}
void F_104 ( struct V_1 * V_1 ,
struct V_38 * V_39 )
{
unsigned long * V_207 ;
unsigned long V_70 ;
unsigned long V_219 ;
V_207 = V_39 -> V_10 . V_182 ;
V_70 = V_39 -> V_84 ;
for ( V_219 = V_39 -> V_42 ; V_219 ; -- V_219 ) {
if ( * V_207 & V_215 )
F_99 ( V_1 , V_207 , V_70 ) ;
++ V_207 ;
++ V_70 ;
}
}
static int F_105 ( struct V_1 * V_1 , unsigned long * V_207 ,
unsigned long V_70 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_220 , V_41 , V_214 ;
unsigned long * V_141 ;
int V_51 = 0 ;
V_221:
F_83 ( V_207 ) ;
if ( * V_207 & V_222 ) {
* V_207 &= ~ V_222 ;
V_51 = 1 ;
}
if ( ! ( * V_207 & V_215 ) ) {
F_85 ( V_207 ) ;
return V_51 ;
}
V_41 = V_220 = * V_207 & V_216 ;
do {
V_141 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_214 = V_5 [ V_41 ] . V_217 ;
if ( ! ( V_141 [ 1 ] & V_55 ) )
continue;
if ( ! F_74 ( V_141 , V_108 ) ) {
F_85 ( V_207 ) ;
while ( V_141 [ 0 ] & V_108 )
F_75 () ;
goto V_221;
}
if ( ( V_141 [ 0 ] & V_110 ) && ( V_141 [ 1 ] & V_55 ) ) {
F_106 ( V_1 , V_141 , V_41 ) ;
if ( ! ( V_5 [ V_41 ] . V_150 & V_55 ) ) {
V_5 [ V_41 ] . V_150 |= V_55 ;
F_101 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_51 = 1 ;
}
V_141 [ 0 ] &= ~ V_108 ;
} while ( ( V_41 = V_214 ) != V_220 );
F_85 ( V_207 ) ;
return V_51 ;
}
int F_107 ( struct V_1 * V_1 , unsigned long V_181 )
{
if ( ! V_1 -> V_10 . V_105 )
return 0 ;
return F_98 ( V_1 , V_181 , F_105 ) ;
}
static int F_108 ( struct V_1 * V_1 , unsigned long * V_207 ,
unsigned long V_70 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_220 , V_41 , V_214 ;
unsigned long * V_223 ;
int V_51 = 1 ;
if ( * V_207 & V_222 )
return 1 ;
F_83 ( V_207 ) ;
if ( * V_207 & V_222 )
goto V_32;
if ( * V_207 & V_215 ) {
V_41 = V_220 = * V_207 & V_216 ;
do {
V_223 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_214 = V_5 [ V_41 ] . V_217 ;
if ( V_223 [ 1 ] & V_55 )
goto V_32;
} while ( ( V_41 = V_214 ) != V_220 );
}
V_51 = 0 ;
V_32:
F_85 ( V_207 ) ;
return V_51 ;
}
int F_109 ( struct V_1 * V_1 , unsigned long V_181 )
{
if ( ! V_1 -> V_10 . V_105 )
return 0 ;
return F_98 ( V_1 , V_181 , F_108 ) ;
}
void F_110 ( struct V_1 * V_1 , unsigned long V_181 , T_4 V_195 )
{
if ( ! V_1 -> V_10 . V_105 )
return;
F_98 ( V_1 , V_181 , F_99 ) ;
}
static int F_111 ( struct V_1 * V_1 , unsigned long * V_207 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_220 , V_41 , V_214 ;
unsigned long * V_141 ;
int V_51 = 0 ;
V_221:
F_83 ( V_207 ) ;
if ( * V_207 & V_224 ) {
* V_207 &= ~ V_224 ;
V_51 = 1 ;
}
if ( ! ( * V_207 & V_215 ) ) {
F_85 ( V_207 ) ;
return V_51 ;
}
V_41 = V_220 = * V_207 & V_216 ;
do {
V_141 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 << 4 ) ) ;
V_214 = V_5 [ V_41 ] . V_217 ;
if ( ! ( V_141 [ 1 ] & V_56 ) )
continue;
if ( ! F_74 ( V_141 , V_108 ) ) {
F_85 ( V_207 ) ;
while ( V_141 [ 0 ] & V_108 )
F_75 () ;
goto V_221;
}
if ( ( V_141 [ 0 ] & V_110 ) && ( V_141 [ 1 ] & V_56 ) ) {
V_141 [ 0 ] |= V_109 ;
F_86 ( V_1 , V_141 , V_41 ) ;
V_141 [ 1 ] &= ~ V_56 ;
F_88 () ;
V_141 [ 0 ] = ( V_141 [ 0 ] & ~ V_109 ) | V_110 ;
if ( ! ( V_5 [ V_41 ] . V_150 & V_56 ) ) {
V_5 [ V_41 ] . V_150 |= V_56 ;
F_101 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_51 = 1 ;
}
V_141 [ 0 ] &= ~ V_108 ;
} while ( ( V_41 = V_214 ) != V_220 );
F_85 ( V_207 ) ;
return V_51 ;
}
static void F_112 ( struct V_225 * V_226 ,
struct V_38 * V_39 ,
unsigned long * V_227 )
{
unsigned long V_70 ;
if ( ! V_226 -> V_228 || ! V_226 -> V_229 )
return;
V_70 = V_226 -> V_104 >> V_16 ;
if ( V_70 < V_39 -> V_84 ||
V_70 >= V_39 -> V_84 + V_39 -> V_42 )
return;
V_226 -> V_228 = false ;
if ( V_227 )
F_113 ( V_70 - V_39 -> V_84 , V_227 ) ;
}
long F_114 ( struct V_1 * V_1 , struct V_38 * V_39 ,
unsigned long * V_227 )
{
unsigned long V_41 ;
unsigned long * V_207 ;
struct V_36 * V_37 ;
F_61 () ;
V_207 = V_39 -> V_10 . V_182 ;
for ( V_41 = 0 ; V_41 < V_39 -> V_42 ; ++ V_41 ) {
if ( F_111 ( V_1 , V_207 ) && V_227 )
F_113 ( V_41 , V_227 ) ;
++ V_207 ;
}
F_115 (i, vcpu, kvm) {
F_50 ( & V_37 -> V_10 . V_230 ) ;
F_112 ( & V_37 -> V_10 . V_226 , V_39 , V_227 ) ;
F_112 ( & V_37 -> V_10 . V_231 , V_39 , V_227 ) ;
F_51 ( & V_37 -> V_10 . V_230 ) ;
}
F_63 () ;
return 0 ;
}
void * F_116 ( struct V_1 * V_1 , unsigned long V_104 ,
unsigned long * V_232 )
{
struct V_38 * V_39 ;
unsigned long V_70 = V_104 >> V_16 ;
struct V_6 * V_6 , * V_74 [ 1 ] ;
int V_42 ;
unsigned long V_181 , V_233 ;
unsigned long V_234 ;
unsigned long * V_76 ;
int V_203 ;
V_203 = F_90 ( & V_1 -> V_204 ) ;
V_39 = F_53 ( V_1 , V_70 ) ;
if ( ! V_39 || ( V_39 -> V_99 & V_112 ) )
goto V_27;
if ( ! V_1 -> V_10 . V_105 ) {
V_76 = V_39 -> V_10 . V_83 ;
if ( ! V_76 )
goto V_27;
V_76 += V_70 - V_39 -> V_84 ;
V_234 = * V_76 ;
if ( ! V_234 ) {
if ( F_35 ( V_1 , V_70 , V_39 ,
V_95 ) < 0 )
goto V_27;
V_234 = * V_76 ;
}
V_6 = F_117 ( V_234 >> V_16 ) ;
F_47 ( V_6 ) ;
} else {
V_181 = F_36 ( V_39 , V_70 ) ;
V_42 = F_37 ( V_181 , 1 , 1 , V_74 ) ;
if ( V_42 < 1 )
goto V_27;
V_6 = V_74 [ 0 ] ;
}
F_92 ( & V_1 -> V_204 , V_203 ) ;
V_233 = V_104 & ( V_95 - 1 ) ;
if ( V_232 )
* V_232 = V_95 - V_233 ;
return F_118 ( V_6 ) + V_233 ;
V_27:
F_92 ( & V_1 -> V_204 , V_203 ) ;
return NULL ;
}
void F_119 ( struct V_1 * V_1 , void * V_235 , unsigned long V_104 ,
bool V_228 )
{
struct V_6 * V_6 = F_23 ( V_235 ) ;
struct V_38 * V_39 ;
unsigned long V_70 ;
unsigned long * V_182 ;
int V_203 ;
F_48 ( V_6 ) ;
if ( ! V_228 || ! V_1 -> V_10 . V_105 )
return;
V_70 = V_104 >> V_16 ;
V_203 = F_90 ( & V_1 -> V_204 ) ;
V_39 = F_53 ( V_1 , V_70 ) ;
if ( V_39 ) {
V_182 = & V_39 -> V_10 . V_182 [ V_70 - V_39 -> V_84 ] ;
F_83 ( V_182 ) ;
* V_182 |= V_224 ;
F_85 ( V_182 ) ;
}
F_92 ( & V_1 -> V_204 , V_203 ) ;
}
static int F_120 ( struct V_4 * V_236 , unsigned long * V_237 )
{
unsigned long V_238 ;
if ( V_236 -> V_150 & V_239 )
return 1 ;
V_238 = ~ V_236 -> V_150 & ( V_55 | V_56 ) ;
if ( ( V_237 [ 0 ] & V_110 ) && ( V_237 [ 1 ] & V_238 ) )
return 1 ;
return 0 ;
}
static long F_121 ( unsigned long V_99 , unsigned long * V_237 ,
unsigned long * V_178 , struct V_4 * V_236 ,
int V_240 , int V_241 )
{
unsigned long V_128 , V_129 ;
unsigned long V_238 ;
int V_242 = 1 ;
int V_243 , V_228 ;
V_228 = F_120 ( V_236 , V_237 ) ;
if ( ! V_241 && ! V_228 )
return 0 ;
V_243 = 0 ;
if ( V_237 [ 0 ] & ( V_110 | V_109 ) ) {
V_243 = 1 ;
if ( ( V_99 & V_244 ) &&
! ( V_237 [ 0 ] & V_54 ) )
V_243 = 0 ;
}
if ( V_243 != V_240 )
return 0 ;
V_128 = V_129 = 0 ;
if ( V_243 || V_228 ) {
F_61 () ;
while ( ! F_74 ( V_237 , V_108 ) )
F_75 () ;
V_128 = V_237 [ 0 ] ;
V_243 = ! ! ( V_128 & V_110 ) ;
V_228 = ! ! ( V_236 -> V_150 & V_239 ) ;
V_238 = ~ V_236 -> V_150 & ( V_55 | V_56 ) ;
if ( V_243 && ( V_238 & V_237 [ 1 ] ) ) {
V_236 -> V_150 |= ( V_237 [ 1 ] & ( V_55 | V_56 ) ) |
V_239 ;
V_228 = 1 ;
}
if ( V_128 & V_109 ) {
V_128 &= ~ V_109 ;
V_128 |= V_110 ;
V_243 = 1 ;
}
if ( ( V_99 & V_244 ) && ! ( V_128 & V_54 ) )
V_243 = 0 ;
V_129 = V_236 -> V_150 ;
if ( V_243 == V_240 && V_228 ) {
V_129 &= ~ V_239 ;
V_236 -> V_150 = V_129 ;
}
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_237 [ 0 ] &= ~ V_108 ;
F_63 () ;
if ( ! ( V_243 == V_240 && ( V_241 || V_228 ) ) )
V_242 = 0 ;
}
V_178 [ 0 ] = V_128 ;
V_178 [ 1 ] = V_129 ;
return V_242 ;
}
static T_6 F_122 ( struct V_245 * V_245 , char T_7 * V_246 ,
T_8 V_247 , T_9 * V_248 )
{
struct V_249 * V_250 = V_245 -> V_251 ;
struct V_1 * V_1 = V_250 -> V_1 ;
struct V_252 V_253 ;
unsigned long * V_237 ;
struct V_4 * V_236 ;
unsigned long V_41 , V_254 , V_255 ;
unsigned long T_7 * V_256 ;
struct V_252 T_7 * V_257 ;
unsigned long V_99 ;
int V_241 ;
unsigned long V_178 [ 2 ] ;
if ( ! F_123 ( V_258 , V_246 , V_247 ) )
return - V_190 ;
V_241 = V_250 -> V_241 ;
V_99 = V_250 -> V_99 ;
V_41 = V_250 -> V_142 ;
V_237 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 * V_259 ) ) ;
V_236 = V_1 -> V_10 . V_24 + V_41 ;
V_256 = ( unsigned long T_7 * ) V_246 ;
V_254 = 0 ;
while ( V_254 + sizeof( V_253 ) + V_259 < V_247 ) {
V_257 = (struct V_252 T_7 * ) V_246 ;
V_253 . V_260 = 0 ;
V_253 . V_261 = 0 ;
V_255 = V_254 ;
V_254 += sizeof( V_253 ) ;
V_256 = ( unsigned long T_7 * ) ( V_246 + sizeof( V_253 ) ) ;
if ( ! V_241 ) {
while ( V_41 < V_1 -> V_10 . V_21 &&
! F_120 ( V_236 , V_237 ) ) {
++ V_41 ;
V_237 += 2 ;
++ V_236 ;
}
}
V_253 . V_142 = V_41 ;
while ( V_41 < V_1 -> V_10 . V_21 &&
V_253 . V_260 < 0xffff &&
V_254 + V_259 < V_247 &&
F_121 ( V_99 , V_237 , V_178 , V_236 , 1 , V_241 ) ) {
++ V_253 . V_260 ;
if ( F_124 ( V_178 [ 0 ] , V_256 ) ||
F_124 ( V_178 [ 1 ] , V_256 + 1 ) )
return - V_190 ;
V_254 += V_259 ;
V_256 += 2 ;
++ V_41 ;
V_237 += 2 ;
++ V_236 ;
}
while ( V_41 < V_1 -> V_10 . V_21 &&
V_253 . V_261 < 0xffff &&
F_121 ( V_99 , V_237 , V_178 , V_236 , 0 , V_241 ) ) {
++ V_253 . V_261 ;
++ V_41 ;
V_237 += 2 ;
++ V_236 ;
}
if ( V_253 . V_260 || V_253 . V_261 ) {
if ( F_125 ( V_257 , & V_253 , sizeof( V_253 ) ) )
return - V_190 ;
V_255 = V_254 ;
V_246 = ( char T_7 * ) V_256 ;
} else {
V_254 = V_255 ;
}
if ( V_41 >= V_1 -> V_10 . V_21 ) {
V_41 = 0 ;
V_250 -> V_241 = 0 ;
break;
}
}
V_250 -> V_142 = V_41 ;
return V_254 ;
}
static T_6 F_126 ( struct V_245 * V_245 , const char T_7 * V_246 ,
T_8 V_247 , T_9 * V_248 )
{
struct V_249 * V_250 = V_245 -> V_251 ;
struct V_1 * V_1 = V_250 -> V_1 ;
struct V_252 V_253 ;
unsigned long V_41 , V_214 ;
unsigned long V_128 , V_129 ;
unsigned long T_7 * V_256 ;
unsigned long * V_237 ;
unsigned long V_262 [ 2 ] ;
T_6 V_254 ;
long int V_27 , V_51 ;
int V_263 ;
if ( ! F_123 ( V_264 , V_246 , V_247 ) )
return - V_190 ;
F_14 ( & V_1 -> V_29 ) ;
V_263 = V_1 -> V_10 . V_30 ;
if ( V_263 ) {
V_1 -> V_10 . V_30 = 0 ;
F_15 () ;
if ( F_16 ( & V_1 -> V_10 . V_31 ) ) {
V_1 -> V_10 . V_30 = 1 ;
F_19 ( & V_1 -> V_29 ) ;
return - V_28 ;
}
}
V_27 = 0 ;
for ( V_254 = 0 ; V_254 + sizeof( V_253 ) <= V_247 ; ) {
V_27 = - V_190 ;
if ( F_127 ( & V_253 , V_246 , sizeof( V_253 ) ) )
break;
V_27 = 0 ;
if ( V_254 + V_253 . V_260 * V_259 > V_247 )
break;
V_254 += sizeof( V_253 ) ;
V_246 += sizeof( V_253 ) ;
V_27 = - V_64 ;
V_41 = V_253 . V_142 ;
if ( V_41 >= V_1 -> V_10 . V_21 ||
V_41 + V_253 . V_260 + V_253 . V_261 > V_1 -> V_10 . V_21 )
break;
V_237 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_41 * V_259 ) ) ;
V_256 = ( unsigned long T_7 * ) V_246 ;
for ( V_214 = 0 ; V_214 < V_253 . V_260 ; ++ V_214 ) {
V_27 = - V_190 ;
if ( F_128 ( V_128 , V_256 ) || F_128 ( V_129 , V_256 + 1 ) )
goto V_32;
V_27 = - V_64 ;
if ( ! ( V_128 & V_110 ) )
goto V_32;
V_256 += 2 ;
V_254 += V_259 ;
if ( V_237 [ 0 ] & ( V_110 | V_109 ) )
F_129 ( V_1 , 0 , V_41 , 0 , V_262 ) ;
V_27 = - V_265 ;
V_51 = F_27 ( V_1 , V_59 , V_41 , V_128 , V_129 ,
V_262 ) ;
if ( V_51 != V_60 ) {
F_8 ( L_5
L_6 , V_51 , V_41 , V_128 , V_129 ) ;
goto V_32;
}
if ( ! V_263 && F_130 ( V_128 ) ) {
unsigned long V_47 = F_52 ( V_128 , V_129 ) ;
unsigned long V_266 = F_131 ( V_47 ) ;
unsigned long V_267 ;
V_1 -> V_10 . V_148 = V_266 | V_125 |
( V_53 << V_268 ) ;
V_267 = V_266 << ( V_269 - 4 ) ;
F_132 ( V_1 , V_267 , V_270 ) ;
V_263 = 1 ;
}
++ V_41 ;
V_237 += 2 ;
}
for ( V_214 = 0 ; V_214 < V_253 . V_261 ; ++ V_214 ) {
if ( V_237 [ 0 ] & ( V_110 | V_109 ) )
F_129 ( V_1 , 0 , V_41 , 0 , V_262 ) ;
++ V_41 ;
V_237 += 2 ;
}
V_27 = 0 ;
}
V_32:
F_133 () ;
V_1 -> V_10 . V_30 = V_263 ;
F_19 ( & V_1 -> V_29 ) ;
if ( V_27 )
return V_27 ;
return V_254 ;
}
static int F_134 ( struct V_271 * V_271 , struct V_245 * V_272 )
{
struct V_249 * V_250 = V_272 -> V_251 ;
V_272 -> V_251 = NULL ;
if ( ! ( V_250 -> V_99 & V_273 ) )
F_135 ( & V_250 -> V_1 -> V_10 . V_274 ) ;
F_136 ( V_250 -> V_1 ) ;
F_137 ( V_250 ) ;
return 0 ;
}
int F_138 ( struct V_1 * V_1 , struct V_275 * V_276 )
{
int V_51 ;
struct V_249 * V_250 ;
int V_277 ;
if ( V_276 -> V_99 & ~ ( V_244 | V_273 ) )
return - V_64 ;
V_250 = F_139 ( sizeof( * V_250 ) , V_12 ) ;
if ( ! V_250 )
return - V_18 ;
F_140 ( V_1 ) ;
V_250 -> V_1 = V_1 ;
V_250 -> V_142 = V_276 -> V_278 ;
V_250 -> V_99 = V_276 -> V_99 ;
V_250 -> V_241 = 1 ;
V_277 = ( V_276 -> V_99 & V_273 ) ? V_279 : V_280 ;
V_51 = F_141 ( L_7 , & V_281 , V_250 , V_277 | V_282 ) ;
if ( V_51 < 0 ) {
F_136 ( V_1 ) ;
return V_51 ;
}
if ( V_277 == V_280 ) {
F_14 ( & V_1 -> V_283 ) ;
F_142 ( & V_1 -> V_10 . V_274 ) ;
F_143 ( & V_1 -> V_204 ) ;
F_19 ( & V_1 -> V_283 ) ;
}
return V_51 ;
}
void F_144 ( struct V_36 * V_37 )
{
struct V_284 * V_285 = & V_37 -> V_10 . V_285 ;
if ( F_29 ( V_65 ) )
V_37 -> V_10 . V_120 = 32 ;
else
V_37 -> V_10 . V_120 = 64 ;
V_285 -> V_286 = F_60 ;
V_285 -> V_287 = F_33 ;
V_37 -> V_10 . V_288 |= V_289 ;
}
