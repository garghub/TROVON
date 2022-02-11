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
V_6 = F_2 ( 1ul << ( V_7 - V_12 ) ) ;
if ( V_6 ) {
V_3 = ( unsigned long ) F_3 ( F_4 ( V_6 ) ) ;
memset ( ( void * ) V_3 , 0 , ( 1ul << V_7 ) ) ;
V_1 -> V_10 . V_11 = 1 ;
}
while ( ! V_3 && V_7 > V_9 ) {
V_3 = F_5 ( V_13 | V_14 | V_15 |
V_16 , V_7 - V_12 ) ;
if ( ! V_3 )
-- V_7 ;
}
if ( ! V_3 )
return - V_17 ;
V_1 -> V_10 . V_18 = V_3 ;
V_1 -> V_10 . V_19 = V_7 ;
V_1 -> V_10 . V_20 = 1ul << ( V_7 - 4 ) ;
V_1 -> V_10 . V_21 = ( 1ul << ( V_7 - 7 ) ) - 1 ;
V_5 = F_6 ( sizeof( struct V_4 ) * V_1 -> V_10 . V_20 ) ;
if ( ! V_5 ) {
F_7 ( L_1 ) ;
goto V_22;
}
V_1 -> V_10 . V_23 = V_5 ;
V_1 -> V_10 . V_24 = F_8 ( V_3 ) | ( V_7 - 18 ) ;
F_9 ( L_2 ,
V_3 , V_7 , V_1 -> V_10 . V_25 ) ;
if ( V_2 )
* V_2 = V_7 ;
return 0 ;
V_22:
if ( V_1 -> V_10 . V_11 )
F_10 ( V_6 , 1 << ( V_7 - V_12 ) ) ;
else
F_11 ( V_3 , V_7 - V_12 ) ;
return - V_17 ;
}
long F_12 ( struct V_1 * V_1 , T_1 * V_2 )
{
long V_26 = - V_27 ;
long V_7 ;
F_13 ( & V_1 -> V_28 ) ;
if ( V_1 -> V_10 . V_29 ) {
V_1 -> V_10 . V_29 = 0 ;
F_14 () ;
if ( F_15 ( & V_1 -> V_10 . V_30 ) ) {
V_1 -> V_10 . V_29 = 1 ;
goto V_31;
}
}
if ( V_1 -> V_10 . V_18 ) {
V_7 = V_1 -> V_10 . V_19 ;
memset ( ( void * ) V_1 -> V_10 . V_18 , 0 , 1ul << V_7 ) ;
F_16 ( V_1 ) ;
F_17 ( & V_1 -> V_10 . V_32 ) ;
* V_2 = V_7 ;
V_26 = 0 ;
} else {
V_26 = F_1 ( V_1 , V_2 ) ;
V_7 = * V_2 ;
}
V_31:
F_18 ( & V_1 -> V_28 ) ;
return V_26 ;
}
void F_19 ( struct V_1 * V_1 )
{
F_20 ( V_1 -> V_10 . V_25 ) ;
F_21 ( V_1 -> V_10 . V_23 ) ;
if ( V_1 -> V_10 . V_11 )
F_10 ( F_22 ( V_1 -> V_10 . V_18 ) ,
1 << ( V_1 -> V_10 . V_19 - V_12 ) ) ;
else
F_11 ( V_1 -> V_10 . V_18 ,
V_1 -> V_10 . V_19 - V_12 ) ;
}
static inline unsigned long F_23 ( unsigned long V_33 )
{
return ( V_33 > 0x1000 ) ? V_34 : 0 ;
}
static inline unsigned long F_24 ( unsigned long V_33 )
{
return ( V_33 == 0x10000 ) ? 0x1000 : 0 ;
}
void F_25 ( struct V_35 * V_36 , struct V_37 * V_38 ,
unsigned long V_39 )
{
unsigned long V_40 ;
unsigned long V_41 ;
unsigned long V_42 , V_43 ;
unsigned long V_44 , V_45 ;
unsigned long V_46 ;
unsigned long V_47 , V_48 ;
unsigned long V_49 ;
long V_50 ;
struct V_1 * V_1 = V_36 -> V_1 ;
V_46 = 1ul << V_39 ;
V_41 = V_38 -> V_41 >> ( V_39 - V_12 ) ;
if ( V_41 > 1ul << ( 40 - V_39 ) )
V_41 = 1ul << ( 40 - V_39 ) ;
if ( V_41 > V_1 -> V_10 . V_21 + 1 )
V_41 = V_1 -> V_10 . V_21 + 1 ;
V_47 = V_51 | ( V_52 << ( 40 - 16 ) ) |
V_53 | F_23 ( V_46 ) ;
V_48 = F_24 ( V_46 ) |
V_54 | V_55 | V_56 | V_57 ;
for ( V_40 = 0 ; V_40 < V_41 ; ++ V_40 ) {
V_44 = V_40 << V_39 ;
V_45 = ( V_40 ^ ( V_52 ^ ( V_52 << 25 ) ) ) & V_1 -> V_10 . V_21 ;
V_45 = ( V_45 << 3 ) + 7 ;
V_42 = V_47 | ( ( V_44 >> 16 ) & ~ 0x7fUL ) ;
V_43 = V_48 | V_44 ;
V_50 = F_26 ( V_1 , V_58 , V_45 , V_42 , V_43 ,
& V_49 ) ;
if ( V_50 != V_59 ) {
F_7 ( L_3 ,
V_44 , V_50 ) ;
break;
}
}
}
int F_27 ( void )
{
unsigned long V_60 , V_61 ;
if ( ! F_28 ( V_62 ) )
return - V_63 ;
if ( F_28 ( V_64 ) ) {
V_60 = F_29 ( V_65 ) ;
V_61 = V_66 ;
} else {
V_60 = 0 ;
V_61 = V_67 ;
}
F_30 ( V_61 + 1 ) ;
F_31 ( V_60 ) ;
F_31 ( V_61 ) ;
return 0 ;
}
static void F_32 ( struct V_35 * V_36 )
{
unsigned long V_68 = V_36 -> V_10 . V_69 ;
if ( F_33 ( V_36 -> V_10 . V_70 . V_68 ) )
V_68 |= V_71 ;
else
V_68 |= V_36 -> V_10 . V_70 . V_68 & V_72 ;
F_34 ( V_36 , V_68 ) ;
}
static long F_35 ( struct V_1 * V_1 , unsigned long V_73 ,
struct V_37 * V_38 ,
unsigned long V_46 )
{
unsigned long V_74 ;
long V_75 , V_26 ;
struct V_6 * V_6 , * V_76 , * V_77 [ 1 ] ;
unsigned long V_78 , V_33 ;
unsigned long * V_79 ;
unsigned int V_80 , V_81 , V_82 ;
struct V_83 * V_84 ;
unsigned long V_85 , V_40 , V_41 ;
V_79 = V_38 -> V_10 . V_86 ;
if ( ! V_79 )
return - V_63 ;
if ( V_79 [ V_73 - V_38 -> V_87 ] )
return 0 ;
V_80 = 0 ;
V_81 = 0 ;
V_6 = NULL ;
V_33 = V_46 ;
V_26 = - V_63 ;
V_74 = F_36 ( V_38 , V_73 ) ;
V_75 = F_37 ( V_74 , 1 , 1 , V_77 ) ;
if ( V_75 != 1 ) {
F_38 ( & V_88 -> V_89 -> V_90 ) ;
V_84 = F_39 ( V_88 -> V_89 , V_74 ) ;
if ( ! V_84 || V_84 -> V_91 > V_74 ||
V_74 + V_46 > V_84 -> V_92 ||
! ( V_84 -> V_93 & V_94 ) )
goto V_95;
V_80 = F_40 ( F_41 ( V_84 -> V_96 ) ) ;
V_85 = V_84 -> V_97 + ( ( V_74 - V_84 -> V_91 ) >> V_12 ) ;
if ( V_46 > V_98 && ( V_85 & ( ( V_46 >> V_12 ) - 1 ) ) )
goto V_95;
F_42 ( & V_88 -> V_89 -> V_90 ) ;
} else {
V_6 = V_77 [ 0 ] ;
V_81 = V_99 ;
V_78 = V_98 ;
if ( F_43 ( V_6 ) ) {
V_76 = F_44 ( V_6 ) ;
V_78 <<= F_45 ( V_76 ) ;
if ( V_78 > V_46 && F_46 ( V_38 , V_78 ) &&
! ( V_38 -> V_100 & ( V_78 - 1 ) ) ) {
V_74 &= ~ ( V_78 - 1 ) ;
V_33 = V_78 ;
F_47 ( V_76 ) ;
F_48 ( V_6 ) ;
V_6 = V_76 ;
}
}
if ( V_78 < V_46 )
goto V_31;
V_85 = F_4 ( V_6 ) ;
}
V_41 = V_33 >> V_12 ;
V_82 = F_49 ( V_41 ) ;
V_79 += ( V_73 - V_38 -> V_87 ) & ~ ( V_41 - 1 ) ;
F_50 ( & V_1 -> V_10 . V_101 ) ;
for ( V_40 = 0 ; V_40 < V_41 ; ++ V_40 ) {
if ( ! V_79 [ V_40 ] ) {
V_79 [ V_40 ] = ( ( V_85 + V_40 ) << V_12 ) +
V_81 + V_80 + V_82 ;
V_81 = 0 ;
}
}
F_51 ( & V_1 -> V_10 . V_101 ) ;
V_26 = 0 ;
V_31:
if ( V_81 )
F_48 ( V_6 ) ;
return V_26 ;
V_95:
F_42 ( & V_88 -> V_89 -> V_90 ) ;
return V_26 ;
}
long F_26 ( struct V_1 * V_1 , unsigned long V_102 ,
long V_103 , unsigned long V_104 ,
unsigned long V_105 , unsigned long * V_106 )
{
unsigned long V_46 , V_107 , V_73 ;
struct V_37 * V_38 ;
long V_50 ;
if ( V_1 -> V_10 . V_108 )
goto V_109;
V_46 = F_52 ( V_104 , V_105 ) ;
if ( ! V_46 )
return V_110 ;
V_104 &= ~ ( V_111 | V_112 | V_113 ) ;
V_107 = ( V_105 & V_114 ) & ~ ( V_46 - 1 ) ;
V_73 = V_107 >> V_12 ;
V_38 = F_53 ( V_1 , V_73 ) ;
if ( V_38 && ! ( V_38 -> V_102 & V_115 ) ) {
if ( ! F_46 ( V_38 , V_46 ) )
return V_110 ;
if ( F_35 ( V_1 , V_73 , V_38 , V_46 ) < 0 )
return V_110 ;
}
V_109:
F_54 () ;
V_50 = F_55 ( V_1 , V_102 , V_103 , V_104 , V_105 ,
V_88 -> V_89 -> V_116 , false , V_106 ) ;
F_56 () ;
if ( V_50 == V_117 ) {
F_7 ( L_4 ) ;
V_50 = V_118 ;
}
return V_50 ;
}
long F_57 ( struct V_35 * V_36 , unsigned long V_102 ,
long V_103 , unsigned long V_104 ,
unsigned long V_105 )
{
return F_26 ( V_36 -> V_1 , V_102 , V_103 ,
V_104 , V_105 , & V_36 -> V_10 . V_119 [ 4 ] ) ;
}
static struct V_120 * F_58 ( struct V_35 * V_36 ,
T_2 V_121 )
{
T_3 V_122 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_36 -> V_10 . V_123 ; V_40 ++ ) {
if ( ! ( V_36 -> V_10 . V_124 [ V_40 ] . V_125 & V_126 ) )
continue;
if ( V_36 -> V_10 . V_124 [ V_40 ] . V_127 & V_128 )
V_122 = V_129 ;
else
V_122 = V_130 ;
if ( ( ( V_36 -> V_10 . V_124 [ V_40 ] . V_125 ^ V_121 ) & V_122 ) == 0 )
return & V_36 -> V_10 . V_124 [ V_40 ] ;
}
return NULL ;
}
static unsigned long F_59 ( unsigned long V_131 , unsigned long V_132 ,
unsigned long V_133 )
{
unsigned long V_134 ;
V_134 = F_52 ( V_131 , V_132 ) - 1 ;
return ( V_132 & V_114 & ~ V_134 ) | ( V_133 & V_134 ) ;
}
static int F_60 ( struct V_35 * V_36 , T_2 V_121 ,
struct V_135 * V_136 , bool V_137 , bool V_138 )
{
struct V_1 * V_1 = V_36 -> V_1 ;
struct V_120 * V_139 ;
unsigned long V_140 ;
unsigned long V_141 , V_142 ;
unsigned long V_131 , V_143 ;
T_4 * V_144 ;
int V_145 ;
int V_146 = V_36 -> V_10 . V_70 . V_68 & ( V_137 ? V_147 : V_148 ) ;
if ( V_146 ) {
V_139 = F_58 ( V_36 , V_121 ) ;
if ( ! V_139 )
return - V_63 ;
V_140 = V_139 -> V_127 ;
} else {
V_140 = V_36 -> V_1 -> V_10 . V_149 ;
}
F_61 () ;
V_145 = F_62 ( V_1 , V_121 , V_140 ,
V_113 | V_112 ) ;
if ( V_145 < 0 ) {
F_63 () ;
return - V_150 ;
}
V_144 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_145 << 4 ) ) ;
V_131 = F_64 ( V_144 [ 0 ] ) & ~ V_111 ;
V_143 = V_1 -> V_10 . V_23 [ V_145 ] . V_151 ;
asm volatile("lwsync" : : : "memory");
V_144 [ 0 ] = F_65 ( V_131 ) ;
F_63 () ;
V_136 -> V_121 = V_121 ;
V_136 -> V_152 = ( ( V_131 & V_153 ) << 4 ) | ( ( V_121 >> 12 ) & 0xfff ) ;
V_141 = V_143 & ( V_154 | V_155 ) ;
V_142 = ( V_36 -> V_10 . V_70 . V_68 & V_156 ) ? V_157 : V_158 ;
V_142 &= V_140 ;
V_136 -> V_159 = F_66 ( V_141 , V_142 ) ;
V_136 -> V_160 = F_67 ( V_141 , V_142 ) ;
V_136 -> V_161 = V_136 -> V_159 && ! ( V_143 & ( V_162 | V_163 ) ) ;
if ( V_137 && V_146 && F_28 ( V_64 ) ) {
int V_164 = F_68 ( V_143 , V_36 -> V_10 . V_165 ) ;
if ( V_164 & 1 )
V_136 -> V_159 = 0 ;
if ( V_164 & 2 )
V_136 -> V_160 = 0 ;
}
V_136 -> V_166 = F_59 ( V_131 , V_143 , V_121 ) ;
return 0 ;
}
static int F_69 ( unsigned int V_167 )
{
unsigned int V_122 ;
V_122 = 0x10000000 ;
if ( ( V_167 & 0xfc000000 ) == 0x7c000000 )
V_122 = 0x100 ;
return ( V_167 & V_122 ) != 0 ;
}
static int F_70 ( struct V_168 * V_169 , struct V_35 * V_36 ,
unsigned long V_107 , T_2 V_133 , int V_170 )
{
T_1 V_171 ;
if ( F_71 ( V_36 , V_172 , & V_171 ) !=
V_173 )
return V_174 ;
if ( F_69 ( V_171 ) != ! ! V_170 )
return V_174 ;
V_36 -> V_10 . V_175 = V_107 ;
V_36 -> V_10 . V_176 = V_133 ;
return F_72 ( V_169 , V_36 ) ;
}
int F_73 ( struct V_168 * V_169 , struct V_35 * V_36 ,
unsigned long V_133 , unsigned long V_177 )
{
struct V_1 * V_1 = V_36 -> V_1 ;
unsigned long V_178 [ 3 ] , V_132 ;
T_4 * V_144 ;
unsigned long V_179 , V_46 , V_180 ;
unsigned long V_181 , V_182 ;
unsigned long V_107 , V_73 , V_183 , V_85 ;
struct V_37 * V_38 ;
unsigned long * V_184 ;
struct V_4 * V_5 ;
struct V_6 * V_6 , * V_77 [ 1 ] ;
long V_145 , V_50 , V_41 ;
unsigned long V_80 ;
unsigned int V_185 , V_186 ;
struct V_83 * V_84 ;
unsigned long V_187 ;
if ( V_133 != V_36 -> V_10 . V_188 )
return V_174 ;
V_145 = V_36 -> V_10 . V_189 ;
V_144 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_145 << 4 ) ) ;
V_5 = & V_1 -> V_10 . V_23 [ V_145 ] ;
F_61 () ;
while ( ! F_74 ( V_144 , V_111 ) )
F_75 () ;
V_178 [ 0 ] = F_64 ( V_144 [ 0 ] ) & ~ V_111 ;
V_178 [ 1 ] = F_64 ( V_144 [ 1 ] ) ;
V_178 [ 2 ] = V_132 = V_5 -> V_151 ;
asm volatile("lwsync" : : : "memory");
V_144 [ 0 ] = F_65 ( V_178 [ 0 ] ) ;
F_63 () ;
if ( V_178 [ 0 ] != V_36 -> V_10 . V_190 [ 0 ] ||
V_178 [ 1 ] != V_36 -> V_10 . V_190 [ 1 ] )
return V_174 ;
V_46 = F_52 ( V_178 [ 0 ] , V_132 ) ;
V_181 = V_132 & V_114 & ~ ( V_46 - 1 ) ;
V_182 = V_181 >> V_12 ;
V_107 = V_181 | ( V_133 & ( V_46 - 1 ) ) ;
V_73 = V_107 >> V_12 ;
V_38 = F_53 ( V_1 , V_73 ) ;
if ( ! V_38 || ( V_38 -> V_102 & V_115 ) )
return F_70 ( V_169 , V_36 , V_107 , V_133 ,
V_177 & V_191 ) ;
if ( ! V_1 -> V_10 . V_108 )
return - V_192 ;
if ( V_182 < V_38 -> V_87 )
return - V_192 ;
V_179 = V_1 -> V_193 ;
F_76 () ;
V_80 = 0 ;
V_85 = 0 ;
V_6 = NULL ;
V_180 = V_98 ;
V_185 = ( V_177 & V_191 ) != 0 ;
V_186 = V_185 ;
V_183 = F_36 ( V_38 , V_73 ) ;
V_41 = F_37 ( V_183 , 1 , V_185 , V_77 ) ;
if ( V_41 < 1 ) {
F_38 ( & V_88 -> V_89 -> V_90 ) ;
V_84 = F_39 ( V_88 -> V_89 , V_183 ) ;
if ( V_84 && V_84 -> V_91 <= V_183 && V_183 + V_46 <= V_84 -> V_92 &&
( V_84 -> V_93 & V_94 ) ) {
V_85 = V_84 -> V_97 +
( ( V_183 - V_84 -> V_91 ) >> V_12 ) ;
V_180 = V_46 ;
V_80 = F_40 ( F_41 ( V_84 -> V_96 ) ) ;
V_186 = V_84 -> V_93 & V_194 ;
}
F_42 ( & V_88 -> V_89 -> V_90 ) ;
if ( ! V_85 )
return - V_192 ;
} else {
V_6 = V_77 [ 0 ] ;
V_85 = F_4 ( V_6 ) ;
if ( F_43 ( V_6 ) ) {
V_6 = F_44 ( V_6 ) ;
V_180 <<= F_45 ( V_6 ) ;
}
if ( ! V_185 && F_77 ( V_132 ) ) {
unsigned int V_195 ;
T_5 * V_196 , V_197 ;
F_54 () ;
V_196 = F_78 ( V_88 -> V_89 -> V_116 ,
V_183 , & V_195 ) ;
if ( V_196 ) {
V_197 = F_79 ( V_196 , 1 ,
V_195 ) ;
if ( F_80 ( V_197 ) )
V_186 = 1 ;
}
F_56 () ;
}
}
V_50 = - V_192 ;
if ( V_46 > V_180 )
goto V_198;
if ( ! F_81 ( V_132 , V_80 ) ) {
if ( V_80 )
return - V_192 ;
V_132 = ( V_132 & ~ ( V_199 | V_200 | V_163 ) ) | V_56 ;
}
if ( V_46 < V_98 )
V_46 = V_98 ;
V_132 = ( V_132 & ~ ( V_154 - V_46 ) ) | ( ( V_85 << V_12 ) & ~ ( V_46 - 1 ) ) ;
if ( F_77 ( V_132 ) && ! V_186 )
V_132 = F_82 ( V_132 ) ;
V_50 = V_174 ;
F_61 () ;
while ( ! F_74 ( V_144 , V_111 ) )
F_75 () ;
if ( ( F_64 ( V_144 [ 0 ] ) & ~ V_111 ) != V_178 [ 0 ] ||
F_64 ( V_144 [ 1 ] ) != V_178 [ 1 ] ||
V_5 -> V_151 != V_178 [ 2 ] )
goto V_201;
V_178 [ 0 ] = ( V_178 [ 0 ] & ~ V_112 ) | V_113 ;
V_184 = & V_38 -> V_10 . V_184 [ V_182 - V_38 -> V_87 ] ;
F_83 ( V_184 ) ;
V_50 = V_174 ;
if ( F_84 ( V_36 -> V_1 , V_179 ) ) {
F_85 ( V_184 ) ;
goto V_201;
}
V_187 = * V_184 >> V_202 ;
V_132 &= V_187 | ~ ( V_54 | V_55 ) ;
if ( F_64 ( V_144 [ 0 ] ) & V_113 ) {
F_85 ( V_184 ) ;
V_144 [ 0 ] |= F_65 ( V_112 ) ;
F_86 ( V_1 , V_144 , V_145 ) ;
V_132 |= F_64 ( V_144 [ 1 ] ) & ( V_54 | V_55 ) ;
} else {
F_87 ( V_1 , V_5 , V_184 , V_145 , 0 ) ;
}
V_144 [ 1 ] = F_65 ( V_132 ) ;
F_88 () ;
V_144 [ 0 ] = F_65 ( V_178 [ 0 ] ) ;
asm volatile("ptesync" : : : "memory");
F_63 () ;
if ( V_6 && F_77 ( V_132 ) )
F_89 ( V_6 ) ;
V_198:
if ( V_6 ) {
F_48 ( V_77 [ 0 ] ) ;
}
return V_50 ;
V_201:
V_144 [ 0 ] &= ~ F_65 ( V_111 ) ;
F_63 () ;
goto V_198;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_203 * V_204 ;
struct V_37 * V_38 ;
int V_205 ;
V_205 = F_90 ( & V_1 -> V_206 ) ;
V_204 = V_1 -> V_207 ;
F_91 (memslot, slots) {
memset ( V_38 -> V_10 . V_184 , 0 ,
V_38 -> V_41 * sizeof( * V_38 -> V_10 . V_184 ) ) ;
}
F_92 ( & V_1 -> V_206 , V_205 ) ;
}
static int F_93 ( struct V_1 * V_1 ,
unsigned long V_74 ,
unsigned long V_208 ,
int (* F_94)( struct V_1 * V_1 ,
unsigned long * V_209 ,
unsigned long V_73 ) )
{
int V_50 ;
int V_210 = 0 ;
struct V_203 * V_204 ;
struct V_37 * V_38 ;
V_204 = V_203 ( V_1 ) ;
F_91 (memslot, slots) {
unsigned long V_211 , V_212 ;
T_6 V_73 , V_213 ;
V_211 = F_95 ( V_74 , V_38 -> V_100 ) ;
V_212 = F_96 ( V_208 , V_38 -> V_100 +
( V_38 -> V_41 << V_12 ) ) ;
if ( V_211 >= V_212 )
continue;
V_73 = F_97 ( V_211 , V_38 ) ;
V_213 = F_97 ( V_212 + V_98 - 1 , V_38 ) ;
for (; V_73 < V_213 ; ++ V_73 ) {
T_6 V_214 = V_73 - V_38 -> V_87 ;
V_50 = F_94 ( V_1 , & V_38 -> V_10 . V_184 [ V_214 ] , V_73 ) ;
V_210 |= V_50 ;
}
}
return V_210 ;
}
static int F_98 ( struct V_1 * V_1 , unsigned long V_183 ,
int (* F_94)( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_73 ) )
{
return F_93 ( V_1 , V_183 , V_183 + 1 , F_94 ) ;
}
static int F_99 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_73 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_23 ;
unsigned long V_215 , V_40 , V_216 ;
T_4 * V_144 ;
unsigned long V_105 , V_46 , V_187 ;
for (; ; ) {
F_83 ( V_209 ) ;
if ( ! ( * V_209 & V_217 ) ) {
F_85 ( V_209 ) ;
break;
}
V_40 = * V_209 & V_218 ;
V_144 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 << 4 ) ) ;
if ( ! F_74 ( V_144 , V_111 ) ) {
F_85 ( V_209 ) ;
while ( F_64 ( V_144 [ 0 ] ) & V_111 )
F_75 () ;
continue;
}
V_216 = V_5 [ V_40 ] . V_219 ;
if ( V_216 == V_40 ) {
* V_209 &= ~ ( V_217 | V_218 ) ;
} else {
V_215 = V_5 [ V_40 ] . V_220 ;
V_5 [ V_215 ] . V_219 = V_216 ;
V_5 [ V_216 ] . V_220 = V_215 ;
V_5 [ V_40 ] . V_219 = V_5 [ V_40 ] . V_220 = V_40 ;
* V_209 = ( * V_209 & ~ V_218 ) | V_216 ;
}
V_105 = V_5 [ V_40 ] . V_151 ;
V_46 = F_52 ( F_64 ( V_144 [ 0 ] ) , V_105 ) ;
if ( ( F_64 ( V_144 [ 0 ] ) & V_113 ) &&
F_100 ( V_105 , V_46 ) == V_73 ) {
if ( V_1 -> V_10 . V_108 )
V_144 [ 0 ] |= F_65 ( V_112 ) ;
F_86 ( V_1 , V_144 , V_40 ) ;
V_187 = F_64 ( V_144 [ 1 ] ) & ( V_54 | V_55 ) ;
* V_209 |= V_187 << V_202 ;
if ( V_187 & ~ V_5 [ V_40 ] . V_151 ) {
V_5 [ V_40 ] . V_151 = V_105 | V_187 ;
F_101 ( V_1 , & V_5 [ V_40 ] ) ;
}
}
F_85 ( V_209 ) ;
V_144 [ 0 ] &= ~ F_65 ( V_111 ) ;
}
return 0 ;
}
int F_102 ( struct V_1 * V_1 , unsigned long V_183 )
{
if ( V_1 -> V_10 . V_108 )
F_98 ( V_1 , V_183 , F_99 ) ;
return 0 ;
}
int F_103 ( struct V_1 * V_1 , unsigned long V_74 , unsigned long V_208 )
{
if ( V_1 -> V_10 . V_108 )
F_93 ( V_1 , V_74 , V_208 , F_99 ) ;
return 0 ;
}
void F_104 ( struct V_1 * V_1 ,
struct V_37 * V_38 )
{
unsigned long * V_209 ;
unsigned long V_73 ;
unsigned long V_221 ;
V_209 = V_38 -> V_10 . V_184 ;
V_73 = V_38 -> V_87 ;
for ( V_221 = V_38 -> V_41 ; V_221 ; -- V_221 ) {
if ( * V_209 & V_217 )
F_99 ( V_1 , V_209 , V_73 ) ;
++ V_209 ;
++ V_73 ;
}
}
static int F_105 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_73 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_23 ;
unsigned long V_222 , V_40 , V_216 ;
T_4 * V_144 ;
int V_50 = 0 ;
V_223:
F_83 ( V_209 ) ;
if ( * V_209 & V_224 ) {
* V_209 &= ~ V_224 ;
V_50 = 1 ;
}
if ( ! ( * V_209 & V_217 ) ) {
F_85 ( V_209 ) ;
return V_50 ;
}
V_40 = V_222 = * V_209 & V_218 ;
do {
V_144 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 << 4 ) ) ;
V_216 = V_5 [ V_40 ] . V_219 ;
if ( ! ( F_64 ( V_144 [ 1 ] ) & V_54 ) )
continue;
if ( ! F_74 ( V_144 , V_111 ) ) {
F_85 ( V_209 ) ;
while ( F_64 ( V_144 [ 0 ] ) & V_111 )
F_75 () ;
goto V_223;
}
if ( ( F_64 ( V_144 [ 0 ] ) & V_113 ) &&
( F_64 ( V_144 [ 1 ] ) & V_54 ) ) {
F_106 ( V_1 , V_144 , V_40 ) ;
if ( ! ( V_5 [ V_40 ] . V_151 & V_54 ) ) {
V_5 [ V_40 ] . V_151 |= V_54 ;
F_101 ( V_1 , & V_5 [ V_40 ] ) ;
}
V_50 = 1 ;
}
V_144 [ 0 ] &= ~ F_65 ( V_111 ) ;
} while ( ( V_40 = V_216 ) != V_222 );
F_85 ( V_209 ) ;
return V_50 ;
}
int F_107 ( struct V_1 * V_1 , unsigned long V_74 , unsigned long V_208 )
{
if ( ! V_1 -> V_10 . V_108 )
return 0 ;
return F_93 ( V_1 , V_74 , V_208 , F_105 ) ;
}
static int F_108 ( struct V_1 * V_1 , unsigned long * V_209 ,
unsigned long V_73 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_23 ;
unsigned long V_222 , V_40 , V_216 ;
unsigned long * V_225 ;
int V_50 = 1 ;
if ( * V_209 & V_224 )
return 1 ;
F_83 ( V_209 ) ;
if ( * V_209 & V_224 )
goto V_31;
if ( * V_209 & V_217 ) {
V_40 = V_222 = * V_209 & V_218 ;
do {
V_225 = ( unsigned long * ) ( V_1 -> V_10 . V_18 + ( V_40 << 4 ) ) ;
V_216 = V_5 [ V_40 ] . V_219 ;
if ( F_64 ( V_225 [ 1 ] ) & V_54 )
goto V_31;
} while ( ( V_40 = V_216 ) != V_222 );
}
V_50 = 0 ;
V_31:
F_85 ( V_209 ) ;
return V_50 ;
}
int F_109 ( struct V_1 * V_1 , unsigned long V_183 )
{
if ( ! V_1 -> V_10 . V_108 )
return 0 ;
return F_98 ( V_1 , V_183 , F_108 ) ;
}
void F_110 ( struct V_1 * V_1 , unsigned long V_183 , T_5 V_197 )
{
if ( ! V_1 -> V_10 . V_108 )
return;
F_98 ( V_1 , V_183 , F_99 ) ;
}
static int V_30 ( struct V_1 * V_1 )
{
return F_15 ( & V_1 -> V_10 . V_30 ) != 0 ;
}
static int F_111 ( struct V_1 * V_1 , unsigned long * V_209 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_23 ;
unsigned long V_222 , V_40 , V_216 ;
unsigned long V_221 ;
unsigned long V_131 , V_132 ;
T_4 * V_144 ;
int V_226 = 0 ;
V_223:
F_83 ( V_209 ) ;
if ( * V_209 & V_227 ) {
* V_209 &= ~ V_227 ;
V_226 = 1 ;
}
if ( ! ( * V_209 & V_217 ) ) {
F_85 ( V_209 ) ;
return V_226 ;
}
V_40 = V_222 = * V_209 & V_218 ;
do {
unsigned long V_228 ;
V_144 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 << 4 ) ) ;
V_216 = V_5 [ V_40 ] . V_219 ;
V_228 = F_64 ( V_144 [ 1 ] ) ;
if ( ! ( V_228 & V_55 ) &&
( ! F_77 ( V_228 ) || V_30 ( V_1 ) ) )
continue;
if ( ! F_74 ( V_144 , V_111 ) ) {
F_85 ( V_209 ) ;
while ( V_144 [ 0 ] & F_65 ( V_111 ) )
F_75 () ;
goto V_223;
}
if ( ! ( V_144 [ 0 ] & F_65 ( V_113 ) ) )
continue;
V_144 [ 0 ] |= F_65 ( V_112 ) ;
F_86 ( V_1 , V_144 , V_40 ) ;
V_131 = F_64 ( V_144 [ 0 ] ) ;
V_132 = F_64 ( V_144 [ 1 ] ) ;
if ( V_132 & V_55 ) {
V_144 [ 1 ] = F_65 ( V_132 & ~ V_55 ) ;
if ( ! ( V_5 [ V_40 ] . V_151 & V_55 ) ) {
V_5 [ V_40 ] . V_151 |= V_55 ;
F_101 ( V_1 , & V_5 [ V_40 ] ) ;
}
V_221 = F_52 ( V_131 , V_132 ) ;
V_221 = ( V_221 + V_98 - 1 ) >> V_12 ;
if ( V_221 > V_226 )
V_226 = V_221 ;
F_88 () ;
}
V_131 &= ~ ( V_112 | V_111 ) ;
V_131 |= V_113 ;
V_144 [ 0 ] = F_65 ( V_131 ) ;
} while ( ( V_40 = V_216 ) != V_222 );
F_85 ( V_209 ) ;
return V_226 ;
}
static void F_112 ( struct V_229 * V_230 ,
struct V_37 * V_38 ,
unsigned long * V_231 )
{
unsigned long V_73 ;
if ( ! V_230 -> V_232 || ! V_230 -> V_233 )
return;
V_73 = V_230 -> V_107 >> V_12 ;
if ( V_73 < V_38 -> V_87 ||
V_73 >= V_38 -> V_87 + V_38 -> V_41 )
return;
V_230 -> V_232 = false ;
if ( V_231 )
F_113 ( V_73 - V_38 -> V_87 , V_231 ) ;
}
long F_114 ( struct V_1 * V_1 , struct V_37 * V_38 ,
unsigned long * V_231 )
{
unsigned long V_40 , V_216 ;
unsigned long * V_209 ;
struct V_35 * V_36 ;
F_61 () ;
V_209 = V_38 -> V_10 . V_184 ;
for ( V_40 = 0 ; V_40 < V_38 -> V_41 ; ++ V_40 ) {
int V_41 = F_111 ( V_1 , V_209 ) ;
if ( V_41 && V_231 )
for ( V_216 = V_40 ; V_41 ; ++ V_216 , -- V_41 )
F_113 ( V_216 , V_231 ) ;
++ V_209 ;
}
F_115 (i, vcpu, kvm) {
F_50 ( & V_36 -> V_10 . V_234 ) ;
F_112 ( & V_36 -> V_10 . V_230 , V_38 , V_231 ) ;
F_112 ( & V_36 -> V_10 . V_235 , V_38 , V_231 ) ;
F_51 ( & V_36 -> V_10 . V_234 ) ;
}
F_63 () ;
return 0 ;
}
void * F_116 ( struct V_1 * V_1 , unsigned long V_107 ,
unsigned long * V_236 )
{
struct V_37 * V_38 ;
unsigned long V_73 = V_107 >> V_12 ;
struct V_6 * V_6 , * V_77 [ 1 ] ;
int V_41 ;
unsigned long V_183 , V_237 ;
unsigned long V_238 ;
unsigned long * V_79 ;
int V_205 ;
V_205 = F_90 ( & V_1 -> V_206 ) ;
V_38 = F_53 ( V_1 , V_73 ) ;
if ( ! V_38 || ( V_38 -> V_102 & V_115 ) )
goto V_26;
if ( ! V_1 -> V_10 . V_108 ) {
V_79 = V_38 -> V_10 . V_86 ;
if ( ! V_79 )
goto V_26;
V_79 += V_73 - V_38 -> V_87 ;
V_238 = * V_79 ;
if ( ! V_238 ) {
if ( F_35 ( V_1 , V_73 , V_38 ,
V_98 ) < 0 )
goto V_26;
V_238 = * V_79 ;
}
V_6 = F_117 ( V_238 >> V_12 ) ;
F_47 ( V_6 ) ;
} else {
V_183 = F_36 ( V_38 , V_73 ) ;
V_41 = F_37 ( V_183 , 1 , 1 , V_77 ) ;
if ( V_41 < 1 )
goto V_26;
V_6 = V_77 [ 0 ] ;
}
F_92 ( & V_1 -> V_206 , V_205 ) ;
V_237 = V_107 & ( V_98 - 1 ) ;
if ( V_236 )
* V_236 = V_98 - V_237 ;
return F_118 ( V_6 ) + V_237 ;
V_26:
F_92 ( & V_1 -> V_206 , V_205 ) ;
return NULL ;
}
void F_119 ( struct V_1 * V_1 , void * V_239 , unsigned long V_107 ,
bool V_232 )
{
struct V_6 * V_6 = F_22 ( V_239 ) ;
struct V_37 * V_38 ;
unsigned long V_73 ;
unsigned long * V_184 ;
int V_205 ;
F_48 ( V_6 ) ;
if ( ! V_232 || ! V_1 -> V_10 . V_108 )
return;
V_73 = V_107 >> V_12 ;
V_205 = F_90 ( & V_1 -> V_206 ) ;
V_38 = F_53 ( V_1 , V_73 ) ;
if ( V_38 ) {
V_184 = & V_38 -> V_10 . V_184 [ V_73 - V_38 -> V_87 ] ;
F_83 ( V_184 ) ;
* V_184 |= V_227 ;
F_85 ( V_184 ) ;
}
F_92 ( & V_1 -> V_206 , V_205 ) ;
}
static int F_120 ( struct V_4 * V_240 , T_4 * V_241 )
{
unsigned long V_242 ;
if ( V_240 -> V_151 & V_243 )
return 1 ;
V_242 = ~ V_240 -> V_151 & ( V_54 | V_55 ) ;
if ( ( F_64 ( V_241 [ 0 ] ) & V_113 ) &&
( F_64 ( V_241 [ 1 ] ) & V_242 ) )
return 1 ;
return 0 ;
}
static long F_121 ( unsigned long V_102 , T_4 * V_241 ,
unsigned long * V_178 , struct V_4 * V_240 ,
int V_244 , int V_245 )
{
unsigned long V_131 , V_132 ;
unsigned long V_242 ;
int V_246 = 1 ;
int V_247 , V_232 ;
V_232 = F_120 ( V_240 , V_241 ) ;
if ( ! V_245 && ! V_232 )
return 0 ;
V_247 = 0 ;
if ( F_64 ( V_241 [ 0 ] ) & ( V_113 | V_112 ) ) {
V_247 = 1 ;
if ( ( V_102 & V_248 ) &&
! ( F_64 ( V_241 [ 0 ] ) & V_53 ) )
V_247 = 0 ;
}
if ( V_247 != V_244 )
return 0 ;
V_131 = V_132 = 0 ;
if ( V_247 || V_232 ) {
F_61 () ;
while ( ! F_74 ( V_241 , V_111 ) )
F_75 () ;
V_131 = F_64 ( V_241 [ 0 ] ) ;
V_247 = ! ! ( V_131 & V_113 ) ;
V_232 = ! ! ( V_240 -> V_151 & V_243 ) ;
V_242 = ~ V_240 -> V_151 & ( V_54 | V_55 ) ;
if ( V_247 && ( V_242 & F_64 ( V_241 [ 1 ] ) ) ) {
V_240 -> V_151 |= ( F_64 ( V_241 [ 1 ] ) &
( V_54 | V_55 ) ) | V_243 ;
V_232 = 1 ;
}
if ( V_131 & V_112 ) {
V_131 &= ~ V_112 ;
V_131 |= V_113 ;
V_247 = 1 ;
}
if ( ( V_102 & V_248 ) && ! ( V_131 & V_53 ) )
V_247 = 0 ;
V_132 = V_240 -> V_151 ;
if ( V_247 == V_244 && V_232 ) {
V_132 &= ~ V_243 ;
V_240 -> V_151 = V_132 ;
}
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_241 [ 0 ] &= ~ F_65 ( V_111 ) ;
F_63 () ;
if ( ! ( V_247 == V_244 && ( V_245 || V_232 ) ) )
V_246 = 0 ;
}
V_178 [ 0 ] = F_65 ( V_131 ) ;
V_178 [ 1 ] = F_65 ( V_132 ) ;
return V_246 ;
}
static T_7 F_122 ( struct V_249 * V_249 , char T_8 * V_250 ,
T_9 V_251 , T_10 * V_252 )
{
struct V_253 * V_254 = V_249 -> V_255 ;
struct V_1 * V_1 = V_254 -> V_1 ;
struct V_256 V_257 ;
T_4 * V_241 ;
struct V_4 * V_240 ;
unsigned long V_40 , V_258 , V_259 ;
unsigned long T_8 * V_260 ;
struct V_256 T_8 * V_261 ;
unsigned long V_102 ;
int V_245 ;
unsigned long V_178 [ 2 ] ;
if ( ! F_123 ( V_262 , V_250 , V_251 ) )
return - V_192 ;
V_245 = V_254 -> V_245 ;
V_102 = V_254 -> V_102 ;
V_40 = V_254 -> V_145 ;
V_241 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 * V_263 ) ) ;
V_240 = V_1 -> V_10 . V_23 + V_40 ;
V_260 = ( unsigned long T_8 * ) V_250 ;
V_258 = 0 ;
while ( V_258 + sizeof( V_257 ) + V_263 < V_251 ) {
V_261 = (struct V_256 T_8 * ) V_250 ;
V_257 . V_264 = 0 ;
V_257 . V_265 = 0 ;
V_259 = V_258 ;
V_258 += sizeof( V_257 ) ;
V_260 = ( unsigned long T_8 * ) ( V_250 + sizeof( V_257 ) ) ;
if ( ! V_245 ) {
while ( V_40 < V_1 -> V_10 . V_20 &&
! F_120 ( V_240 , V_241 ) ) {
++ V_40 ;
V_241 += 2 ;
++ V_240 ;
}
}
V_257 . V_145 = V_40 ;
while ( V_40 < V_1 -> V_10 . V_20 &&
V_257 . V_264 < 0xffff &&
V_258 + V_263 < V_251 &&
F_121 ( V_102 , V_241 , V_178 , V_240 , 1 , V_245 ) ) {
++ V_257 . V_264 ;
if ( F_124 ( V_178 [ 0 ] , V_260 ) ||
F_124 ( V_178 [ 1 ] , V_260 + 1 ) )
return - V_192 ;
V_258 += V_263 ;
V_260 += 2 ;
++ V_40 ;
V_241 += 2 ;
++ V_240 ;
}
while ( V_40 < V_1 -> V_10 . V_20 &&
V_257 . V_265 < 0xffff &&
F_121 ( V_102 , V_241 , V_178 , V_240 , 0 , V_245 ) ) {
++ V_257 . V_265 ;
++ V_40 ;
V_241 += 2 ;
++ V_240 ;
}
if ( V_257 . V_264 || V_257 . V_265 ) {
if ( F_125 ( V_261 , & V_257 , sizeof( V_257 ) ) )
return - V_192 ;
V_259 = V_258 ;
V_250 = ( char T_8 * ) V_260 ;
} else {
V_258 = V_259 ;
}
if ( V_40 >= V_1 -> V_10 . V_20 ) {
V_40 = 0 ;
V_254 -> V_245 = 0 ;
break;
}
}
V_254 -> V_145 = V_40 ;
return V_258 ;
}
static T_7 F_126 ( struct V_249 * V_249 , const char T_8 * V_250 ,
T_9 V_251 , T_10 * V_252 )
{
struct V_253 * V_254 = V_249 -> V_255 ;
struct V_1 * V_1 = V_254 -> V_1 ;
struct V_256 V_257 ;
unsigned long V_40 , V_216 ;
unsigned long V_131 , V_132 ;
unsigned long T_8 * V_260 ;
T_4 * V_241 ;
unsigned long V_266 [ 2 ] ;
T_7 V_258 ;
long int V_26 , V_50 ;
int V_267 ;
if ( ! F_123 ( V_268 , V_250 , V_251 ) )
return - V_192 ;
F_13 ( & V_1 -> V_28 ) ;
V_267 = V_1 -> V_10 . V_29 ;
if ( V_267 ) {
V_1 -> V_10 . V_29 = 0 ;
F_14 () ;
if ( F_15 ( & V_1 -> V_10 . V_30 ) ) {
V_1 -> V_10 . V_29 = 1 ;
F_18 ( & V_1 -> V_28 ) ;
return - V_27 ;
}
}
V_26 = 0 ;
for ( V_258 = 0 ; V_258 + sizeof( V_257 ) <= V_251 ; ) {
V_26 = - V_192 ;
if ( F_127 ( & V_257 , V_250 , sizeof( V_257 ) ) )
break;
V_26 = 0 ;
if ( V_258 + V_257 . V_264 * V_263 > V_251 )
break;
V_258 += sizeof( V_257 ) ;
V_250 += sizeof( V_257 ) ;
V_26 = - V_63 ;
V_40 = V_257 . V_145 ;
if ( V_40 >= V_1 -> V_10 . V_20 ||
V_40 + V_257 . V_264 + V_257 . V_265 > V_1 -> V_10 . V_20 )
break;
V_241 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 * V_263 ) ) ;
V_260 = ( unsigned long T_8 * ) V_250 ;
for ( V_216 = 0 ; V_216 < V_257 . V_264 ; ++ V_216 ) {
V_26 = - V_192 ;
if ( F_128 ( V_131 , V_260 ) || F_128 ( V_132 , V_260 + 1 ) )
goto V_31;
V_26 = - V_63 ;
if ( ! ( V_131 & V_113 ) )
goto V_31;
V_260 += 2 ;
V_258 += V_263 ;
if ( F_64 ( V_241 [ 0 ] ) & ( V_113 | V_112 ) )
F_129 ( V_1 , 0 , V_40 , 0 , V_266 ) ;
V_26 = - V_269 ;
V_50 = F_26 ( V_1 , V_58 , V_40 , V_131 , V_132 ,
V_266 ) ;
if ( V_50 != V_59 ) {
F_7 ( L_5
L_6 , V_50 , V_40 , V_131 , V_132 ) ;
goto V_31;
}
if ( ! V_267 && F_130 ( V_131 ) ) {
unsigned long V_46 = F_131 ( V_131 , V_132 ) ;
unsigned long V_270 = F_132 ( V_46 ) ;
unsigned long V_271 ;
V_1 -> V_10 . V_149 = V_270 | V_128 |
( V_52 << V_272 ) ;
V_271 = V_270 << ( V_273 - 4 ) ;
F_133 ( V_1 , V_271 , V_274 ) ;
V_267 = 1 ;
}
++ V_40 ;
V_241 += 2 ;
}
for ( V_216 = 0 ; V_216 < V_257 . V_265 ; ++ V_216 ) {
if ( F_64 ( V_241 [ 0 ] ) & ( V_113 | V_112 ) )
F_129 ( V_1 , 0 , V_40 , 0 , V_266 ) ;
++ V_40 ;
V_241 += 2 ;
}
V_26 = 0 ;
}
V_31:
F_134 () ;
V_1 -> V_10 . V_29 = V_267 ;
F_18 ( & V_1 -> V_28 ) ;
if ( V_26 )
return V_26 ;
return V_258 ;
}
static int F_135 ( struct V_275 * V_275 , struct V_249 * V_276 )
{
struct V_253 * V_254 = V_276 -> V_255 ;
V_276 -> V_255 = NULL ;
if ( ! ( V_254 -> V_102 & V_277 ) )
F_136 ( & V_254 -> V_1 -> V_10 . V_278 ) ;
F_137 ( V_254 -> V_1 ) ;
F_138 ( V_254 ) ;
return 0 ;
}
int F_139 ( struct V_1 * V_1 , struct V_279 * V_280 )
{
int V_50 ;
struct V_253 * V_254 ;
int V_281 ;
if ( V_280 -> V_102 & ~ ( V_248 | V_277 ) )
return - V_63 ;
V_254 = F_140 ( sizeof( * V_254 ) , V_13 ) ;
if ( ! V_254 )
return - V_17 ;
F_141 ( V_1 ) ;
V_254 -> V_1 = V_1 ;
V_254 -> V_145 = V_280 -> V_282 ;
V_254 -> V_102 = V_280 -> V_102 ;
V_254 -> V_245 = 1 ;
V_281 = ( V_280 -> V_102 & V_277 ) ? V_283 : V_284 ;
V_50 = F_142 ( L_7 , & V_285 , V_254 , V_281 | V_286 ) ;
if ( V_50 < 0 ) {
F_137 ( V_1 ) ;
return V_50 ;
}
if ( V_281 == V_284 ) {
F_13 ( & V_1 -> V_287 ) ;
F_143 ( & V_1 -> V_10 . V_278 ) ;
F_144 ( & V_1 -> V_206 ) ;
F_18 ( & V_1 -> V_287 ) ;
}
return V_50 ;
}
void F_145 ( struct V_35 * V_36 )
{
struct V_288 * V_289 = & V_36 -> V_10 . V_289 ;
if ( F_28 ( V_64 ) )
V_36 -> V_10 . V_123 = 32 ;
else
V_36 -> V_10 . V_123 = 64 ;
V_289 -> V_290 = F_60 ;
V_289 -> V_291 = F_32 ;
V_36 -> V_10 . V_292 |= V_293 ;
}
