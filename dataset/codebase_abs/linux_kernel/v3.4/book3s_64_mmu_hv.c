long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
unsigned long V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 () ;
if ( V_7 ) {
V_2 = ( V_8 ) V_7 -> V_9 ;
V_1 -> V_10 . V_11 = V_7 ;
} else {
V_2 = F_3 ( V_12 | V_13 | V_14 |
V_15 , V_16 - V_17 ) ;
}
if ( ! V_2 ) {
F_4 ( L_1 ) ;
return - V_18 ;
}
V_1 -> V_10 . V_19 = V_2 ;
V_5 = F_5 ( sizeof( struct V_4 ) * V_20 ) ;
if ( ! V_5 ) {
F_4 ( L_2 ) ;
goto V_21;
}
V_1 -> V_10 . V_22 = V_5 ;
do {
V_3 = F_6 ( V_23 , V_24 ) ;
if ( V_3 >= V_24 ) {
F_4 ( L_3 ) ;
goto V_25;
}
} while ( F_7 ( V_3 , V_23 ) );
V_1 -> V_10 . V_26 = F_8 ( V_2 ) | ( V_16 - 18 ) ;
V_1 -> V_10 . V_3 = V_3 ;
F_9 ( L_4 , V_2 , V_3 ) ;
return 0 ;
V_25:
F_10 ( V_5 ) ;
V_21:
F_11 ( V_2 , V_16 - V_17 ) ;
return - V_18 ;
}
void F_12 ( struct V_1 * V_1 )
{
F_13 ( V_1 -> V_10 . V_3 , V_23 ) ;
F_10 ( V_1 -> V_10 . V_22 ) ;
if ( V_1 -> V_10 . V_11 )
F_14 ( V_1 -> V_10 . V_11 ) ;
else
F_11 ( V_1 -> V_10 . V_19 , V_16 - V_17 ) ;
}
static inline unsigned long F_15 ( unsigned long V_27 )
{
return ( V_27 > 0x1000 ) ? V_28 : 0 ;
}
static inline unsigned long F_16 ( unsigned long V_27 )
{
return ( V_27 == 0x10000 ) ? 0x1000 : 0 ;
}
void F_17 ( struct V_29 * V_30 , struct V_31 * V_32 ,
unsigned long V_33 )
{
unsigned long V_34 ;
unsigned long V_35 ;
unsigned long V_36 , V_37 ;
unsigned long V_38 , V_39 ;
unsigned long V_40 ;
unsigned long V_41 , V_42 ;
long V_43 ;
V_40 = 1ul << V_33 ;
V_35 = V_32 -> V_35 >> ( V_33 - V_17 ) ;
if ( V_35 > 1ul << ( 40 - V_33 ) )
V_35 = 1ul << ( 40 - V_33 ) ;
if ( V_35 > V_44 )
V_35 = V_44 ;
V_41 = V_45 | ( V_46 << ( 40 - 16 ) ) |
V_47 | F_15 ( V_40 ) ;
V_42 = F_16 ( V_40 ) |
V_48 | V_49 | V_50 | V_51 ;
for ( V_34 = 0 ; V_34 < V_35 ; ++ V_34 ) {
V_38 = V_34 << V_33 ;
V_39 = ( V_34 ^ ( V_46 ^ ( V_46 << 25 ) ) ) & V_52 ;
V_39 = ( V_39 << 3 ) + 7 ;
V_36 = V_41 | ( ( V_38 >> 16 ) & ~ 0x7fUL ) ;
V_37 = V_42 | V_38 ;
V_43 = F_18 ( V_30 , V_53 , V_39 , V_36 , V_37 ) ;
if ( V_43 != V_54 ) {
F_4 ( L_5 ,
V_38 , V_43 ) ;
break;
}
}
}
int F_19 ( void )
{
unsigned long V_55 , V_56 ;
if ( ! F_20 ( V_57 ) )
return - V_58 ;
memset ( V_23 , 0 , sizeof( V_23 ) ) ;
if ( F_20 ( V_59 ) ) {
V_55 = F_21 ( V_60 ) ;
V_56 = V_61 ;
} else {
V_55 = 0 ;
V_56 = V_62 ;
}
F_22 ( V_55 , V_23 ) ;
F_22 ( V_56 , V_23 ) ;
return 0 ;
}
void F_23 ( struct V_29 * V_30 )
{
}
static void F_24 ( struct V_29 * V_30 )
{
F_25 ( V_30 , V_63 | V_64 ) ;
}
static long F_26 ( struct V_1 * V_1 , unsigned long V_65 ,
struct V_31 * V_32 ,
unsigned long V_40 )
{
unsigned long V_66 ;
long V_67 , V_68 ;
struct V_69 * V_69 , * V_70 , * V_71 [ 1 ] ;
unsigned long V_72 , V_27 ;
unsigned long * V_73 ;
unsigned int V_74 , V_75 , V_76 ;
struct V_77 * V_78 ;
unsigned long V_79 , V_34 , V_35 ;
V_73 = V_1 -> V_10 . V_80 [ V_32 -> V_81 ] ;
if ( ! V_73 )
return - V_58 ;
if ( V_73 [ V_65 - V_32 -> V_82 ] )
return 0 ;
V_74 = 0 ;
V_75 = 0 ;
V_69 = NULL ;
V_27 = V_40 ;
V_68 = - V_58 ;
V_66 = F_27 ( V_32 , V_65 ) ;
V_67 = F_28 ( V_66 , 1 , 1 , V_71 ) ;
if ( V_67 != 1 ) {
F_29 ( & V_83 -> V_84 -> V_85 ) ;
V_78 = F_30 ( V_83 -> V_84 , V_66 ) ;
if ( ! V_78 || V_78 -> V_86 > V_66 ||
V_66 + V_40 > V_78 -> V_87 ||
! ( V_78 -> V_88 & V_89 ) )
goto V_90;
V_74 = F_31 ( F_32 ( V_78 -> V_91 ) ) ;
V_79 = V_78 -> V_92 + ( ( V_66 - V_78 -> V_86 ) >> V_17 ) ;
if ( V_40 > V_93 && ( V_79 & ( ( V_40 >> V_17 ) - 1 ) ) )
goto V_90;
F_33 ( & V_83 -> V_84 -> V_85 ) ;
} else {
V_69 = V_71 [ 0 ] ;
V_75 = V_94 ;
V_72 = V_93 ;
if ( F_34 ( V_69 ) ) {
V_70 = F_35 ( V_69 ) ;
V_72 <<= F_36 ( V_70 ) ;
if ( V_72 > V_40 && F_37 ( V_32 , V_72 ) &&
! ( V_32 -> V_95 & ( V_72 - 1 ) ) ) {
V_66 &= ~ ( V_72 - 1 ) ;
V_27 = V_72 ;
F_38 ( V_70 ) ;
F_39 ( V_69 ) ;
V_69 = V_70 ;
}
}
if ( V_72 < V_40 )
goto V_96;
V_79 = F_40 ( V_69 ) ;
}
V_35 = V_27 >> V_17 ;
V_76 = F_41 ( V_35 ) ;
V_73 += ( V_65 - V_32 -> V_82 ) & ~ ( V_35 - 1 ) ;
F_42 ( & V_1 -> V_10 . V_97 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; ++ V_34 ) {
if ( ! V_73 [ V_34 ] ) {
V_73 [ V_34 ] = ( ( V_79 + V_34 ) << V_17 ) +
V_75 + V_74 + V_76 ;
V_75 = 0 ;
}
}
F_43 ( & V_1 -> V_10 . V_97 ) ;
V_68 = 0 ;
V_96:
if ( V_75 )
F_39 ( V_69 ) ;
return V_68 ;
V_90:
F_33 ( & V_83 -> V_84 -> V_85 ) ;
return V_68 ;
}
long F_18 ( struct V_29 * V_30 , unsigned long V_98 ,
long V_99 , unsigned long V_100 , unsigned long V_101 )
{
struct V_1 * V_1 = V_30 -> V_1 ;
unsigned long V_40 , V_102 , V_65 ;
struct V_31 * V_32 ;
long V_43 ;
if ( V_1 -> V_10 . V_103 )
goto V_104;
V_40 = F_44 ( V_100 , V_101 ) ;
if ( ! V_40 )
return V_105 ;
V_100 &= ~ ( V_106 | V_107 | V_108 ) ;
V_102 = ( V_101 & V_109 ) & ~ ( V_40 - 1 ) ;
V_65 = V_102 >> V_17 ;
V_32 = F_45 ( V_1 , V_65 ) ;
if ( V_32 && ! ( V_32 -> V_98 & V_110 ) ) {
if ( ! F_37 ( V_32 , V_40 ) )
return V_105 ;
if ( F_26 ( V_1 , V_65 , V_32 , V_40 ) < 0 )
return V_105 ;
}
V_104:
F_46 () ;
V_30 -> V_10 . V_111 = V_83 -> V_84 -> V_112 ;
V_43 = F_47 ( V_30 , V_98 , V_99 , V_100 , V_101 ) ;
F_48 () ;
if ( V_43 == V_113 ) {
F_4 ( L_6 ) ;
V_43 = V_114 ;
}
return V_43 ;
}
static struct V_115 * F_49 ( struct V_29 * V_30 ,
T_1 V_116 )
{
T_2 V_117 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_30 -> V_10 . V_118 ; V_34 ++ ) {
if ( ! ( V_30 -> V_10 . V_119 [ V_34 ] . V_120 & V_121 ) )
continue;
if ( V_30 -> V_10 . V_119 [ V_34 ] . V_122 & V_123 )
V_117 = V_124 ;
else
V_117 = V_125 ;
if ( ( ( V_30 -> V_10 . V_119 [ V_34 ] . V_120 ^ V_116 ) & V_117 ) == 0 )
return & V_30 -> V_10 . V_119 [ V_34 ] ;
}
return NULL ;
}
static unsigned long F_50 ( unsigned long V_126 , unsigned long V_127 ,
unsigned long V_128 )
{
unsigned long V_129 ;
V_129 = F_44 ( V_126 , V_127 ) - 1 ;
return ( V_127 & V_109 & ~ V_129 ) | ( V_128 & V_129 ) ;
}
static int F_51 ( struct V_29 * V_30 , T_1 V_116 ,
struct V_130 * V_131 , bool V_132 )
{
struct V_1 * V_1 = V_30 -> V_1 ;
struct V_115 * V_133 ;
unsigned long V_134 ;
unsigned long V_135 , V_136 ;
unsigned long V_126 , V_137 ;
unsigned long * V_138 ;
int V_139 ;
int V_140 = V_30 -> V_10 . V_141 . V_142 & ( V_132 ? V_143 : V_144 ) ;
if ( V_140 ) {
V_133 = F_49 ( V_30 , V_116 ) ;
if ( ! V_133 )
return - V_58 ;
V_134 = V_133 -> V_122 ;
} else {
V_134 = V_30 -> V_1 -> V_10 . V_145 ;
}
V_139 = F_52 ( V_1 , V_116 , V_134 ,
V_108 | V_107 ) ;
if ( V_139 < 0 )
return - V_146 ;
V_138 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_139 << 4 ) ) ;
V_126 = V_138 [ 0 ] & ~ V_106 ;
V_137 = V_1 -> V_10 . V_22 [ V_139 ] . V_147 ;
asm volatile("lwsync" : : : "memory");
V_138 [ 0 ] = V_126 ;
V_131 -> V_116 = V_116 ;
V_131 -> V_148 = ( ( V_126 & V_149 ) << 4 ) | ( ( V_116 >> 12 ) & 0xfff ) ;
V_135 = V_137 & ( V_150 | V_151 ) ;
V_136 = ( V_30 -> V_10 . V_141 . V_142 & V_152 ) ? V_153 : V_154 ;
V_136 &= V_134 ;
V_131 -> V_155 = F_53 ( V_135 , V_136 ) ;
V_131 -> V_156 = F_54 ( V_135 , V_136 ) ;
V_131 -> V_157 = V_131 -> V_155 && ! ( V_137 & ( V_158 | V_159 ) ) ;
if ( V_132 && V_140 && F_20 ( V_59 ) ) {
int V_160 = F_55 ( V_137 , V_30 -> V_10 . V_161 ) ;
if ( V_160 & 1 )
V_131 -> V_155 = 0 ;
if ( V_160 & 2 )
V_131 -> V_156 = 0 ;
}
V_131 -> V_162 = F_50 ( V_126 , V_137 , V_116 ) ;
return 0 ;
}
static int F_56 ( unsigned int V_163 )
{
unsigned int V_117 ;
V_117 = 0x10000000 ;
if ( ( V_163 & 0xfc000000 ) == 0x7c000000 )
V_117 = 0x100 ;
return ( V_163 & V_117 ) != 0 ;
}
static int F_57 ( struct V_164 * V_165 , struct V_29 * V_30 ,
unsigned long V_102 , int V_166 )
{
int V_43 ;
T_3 V_167 ;
unsigned long V_168 = F_58 ( V_30 ) ;
if ( V_30 -> V_10 . V_167 == V_169 ) {
V_43 = F_59 ( V_30 , & V_168 , sizeof( T_3 ) , & V_167 , false ) ;
if ( V_43 != V_170 || V_167 == V_169 )
return V_171 ;
V_30 -> V_10 . V_167 = V_167 ;
}
if ( F_56 ( V_30 -> V_10 . V_167 ) != ! ! V_166 )
return V_171 ;
V_30 -> V_10 . V_172 = V_102 ;
return F_60 ( V_165 , V_30 ) ;
}
int F_61 ( struct V_164 * V_165 , struct V_29 * V_30 ,
unsigned long V_128 , unsigned long V_173 )
{
struct V_1 * V_1 = V_30 -> V_1 ;
unsigned long * V_138 , V_174 [ 3 ] , V_127 ;
unsigned long V_175 , V_40 , V_176 ;
unsigned long V_65 , V_177 , V_79 ;
struct V_31 * V_32 ;
unsigned long * V_178 ;
struct V_4 * V_5 ;
struct V_69 * V_69 , * V_71 [ 1 ] ;
long V_139 , V_43 , V_35 ;
unsigned long V_74 ;
unsigned int V_179 , V_180 ;
struct V_77 * V_78 ;
unsigned long V_181 ;
if ( V_128 != V_30 -> V_10 . V_182 )
return V_171 ;
V_139 = V_30 -> V_10 . V_183 ;
V_138 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_139 << 4 ) ) ;
V_5 = & V_1 -> V_10 . V_22 [ V_139 ] ;
F_62 () ;
while ( ! F_63 ( V_138 , V_106 ) )
F_64 () ;
V_174 [ 0 ] = V_138 [ 0 ] & ~ V_106 ;
V_174 [ 1 ] = V_138 [ 1 ] ;
V_174 [ 2 ] = V_127 = V_5 -> V_147 ;
asm volatile("lwsync" : : : "memory");
V_138 [ 0 ] = V_174 [ 0 ] ;
F_65 () ;
if ( V_174 [ 0 ] != V_30 -> V_10 . V_184 [ 0 ] ||
V_174 [ 1 ] != V_30 -> V_10 . V_184 [ 1 ] )
return V_171 ;
V_40 = F_44 ( V_174 [ 0 ] , V_127 ) ;
V_65 = F_66 ( V_127 , V_40 ) ;
V_32 = F_45 ( V_1 , V_65 ) ;
if ( ! V_32 || ( V_32 -> V_98 & V_110 ) ) {
unsigned long V_102 = ( V_65 << V_17 ) | ( V_128 & ( V_40 - 1 ) ) ;
return F_57 ( V_165 , V_30 , V_102 ,
V_173 & V_185 ) ;
}
if ( ! V_1 -> V_10 . V_103 )
return - V_186 ;
V_175 = V_1 -> V_187 ;
F_67 () ;
V_74 = 0 ;
V_79 = 0 ;
V_69 = NULL ;
V_176 = V_93 ;
V_179 = ( V_173 & V_185 ) != 0 ;
V_180 = V_179 ;
V_177 = F_27 ( V_32 , V_65 ) ;
V_35 = F_28 ( V_177 , 1 , V_179 , V_71 ) ;
if ( V_35 < 1 ) {
F_29 ( & V_83 -> V_84 -> V_85 ) ;
V_78 = F_30 ( V_83 -> V_84 , V_177 ) ;
if ( V_78 && V_78 -> V_86 <= V_177 && V_177 + V_40 <= V_78 -> V_87 &&
( V_78 -> V_88 & V_89 ) ) {
V_79 = V_78 -> V_92 +
( ( V_177 - V_78 -> V_86 ) >> V_17 ) ;
V_176 = V_40 ;
V_74 = F_31 ( F_32 ( V_78 -> V_91 ) ) ;
V_180 = V_78 -> V_88 & V_188 ;
}
F_33 ( & V_83 -> V_84 -> V_85 ) ;
if ( ! V_79 )
return - V_186 ;
} else {
V_69 = V_71 [ 0 ] ;
if ( F_34 ( V_69 ) ) {
V_69 = F_35 ( V_69 ) ;
V_176 <<= F_36 ( V_69 ) ;
}
if ( ! V_179 && F_68 ( V_127 ) ) {
T_4 * V_189 , V_190 ;
F_46 () ;
V_189 = F_69 ( V_83 -> V_84 -> V_112 ,
V_177 , NULL ) ;
if ( V_189 && F_70 ( * V_189 ) ) {
V_190 = F_71 ( V_189 , 1 ) ;
if ( F_72 ( V_190 ) )
V_180 = 1 ;
}
F_48 () ;
}
V_79 = F_40 ( V_69 ) ;
}
V_43 = - V_186 ;
if ( V_40 > V_176 )
goto V_191;
if ( ! F_73 ( V_127 , V_74 ) ) {
if ( V_74 )
return - V_186 ;
V_127 = ( V_127 & ~ ( V_192 | V_193 | V_159 ) ) | V_50 ;
}
V_127 = ( V_127 & ~ ( V_150 - V_176 ) ) | ( V_79 << V_17 ) ;
if ( F_68 ( V_127 ) && ! V_180 )
V_127 = F_74 ( V_127 ) ;
V_43 = V_171 ;
F_62 () ;
while ( ! F_63 ( V_138 , V_106 ) )
F_64 () ;
if ( ( V_138 [ 0 ] & ~ V_106 ) != V_174 [ 0 ] || V_138 [ 1 ] != V_174 [ 1 ] ||
V_5 -> V_147 != V_174 [ 2 ] )
goto V_194;
V_174 [ 0 ] = ( V_174 [ 0 ] & ~ V_107 ) | V_108 ;
V_178 = & V_32 -> V_178 [ V_65 - V_32 -> V_82 ] ;
F_75 ( V_178 ) ;
V_43 = V_171 ;
if ( F_76 ( V_30 , V_175 ) ) {
F_77 ( V_178 ) ;
goto V_194;
}
V_181 = * V_178 >> V_195 ;
V_127 &= V_181 | ~ ( V_48 | V_49 ) ;
if ( V_138 [ 0 ] & V_108 ) {
F_77 ( V_178 ) ;
V_138 [ 0 ] |= V_107 ;
F_78 ( V_1 , V_138 , V_139 ) ;
V_127 |= V_138 [ 1 ] & ( V_48 | V_49 ) ;
} else {
F_79 ( V_1 , V_5 , V_178 , V_139 , 0 ) ;
}
V_138 [ 1 ] = V_127 ;
F_80 () ;
V_138 [ 0 ] = V_174 [ 0 ] ;
asm volatile("ptesync" : : : "memory");
F_65 () ;
if ( V_69 && F_68 ( V_127 ) )
F_81 ( V_69 ) ;
V_191:
if ( V_69 ) {
F_39 ( V_71 [ 0 ] ) ;
}
return V_43 ;
V_194:
V_138 [ 0 ] &= ~ V_106 ;
F_65 () ;
goto V_191;
}
static int F_82 ( struct V_1 * V_1 , unsigned long V_177 ,
int (* F_83)( struct V_1 * V_1 , unsigned long * V_196 ,
unsigned long V_65 ) )
{
int V_43 ;
int V_197 = 0 ;
struct V_198 * V_199 ;
struct V_31 * V_32 ;
V_199 = V_198 ( V_1 ) ;
F_84 (memslot, slots) {
unsigned long V_66 = V_32 -> V_95 ;
unsigned long V_200 ;
V_200 = V_66 + ( V_32 -> V_35 << V_17 ) ;
if ( V_177 >= V_66 && V_177 < V_200 ) {
T_5 V_201 = ( V_177 - V_66 ) >> V_17 ;
V_43 = F_83 ( V_1 , & V_32 -> V_178 [ V_201 ] ,
V_32 -> V_82 + V_201 ) ;
V_197 |= V_43 ;
}
}
return V_197 ;
}
static int F_85 ( struct V_1 * V_1 , unsigned long * V_196 ,
unsigned long V_65 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_22 ;
unsigned long V_202 , V_34 , V_203 ;
unsigned long * V_138 ;
unsigned long V_101 , V_40 , V_181 ;
for (; ; ) {
F_75 ( V_196 ) ;
if ( ! ( * V_196 & V_204 ) ) {
F_77 ( V_196 ) ;
break;
}
V_34 = * V_196 & V_205 ;
V_138 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_34 << 4 ) ) ;
if ( ! F_63 ( V_138 , V_106 ) ) {
F_77 ( V_196 ) ;
while ( V_138 [ 0 ] & V_106 )
F_64 () ;
continue;
}
V_203 = V_5 [ V_34 ] . V_206 ;
if ( V_203 == V_34 ) {
* V_196 &= ~ ( V_204 | V_205 ) ;
} else {
V_202 = V_5 [ V_34 ] . V_207 ;
V_5 [ V_202 ] . V_206 = V_203 ;
V_5 [ V_203 ] . V_207 = V_202 ;
V_5 [ V_34 ] . V_206 = V_5 [ V_34 ] . V_207 = V_34 ;
* V_196 = ( * V_196 & ~ V_205 ) | V_203 ;
}
V_101 = V_5 [ V_34 ] . V_147 ;
V_40 = F_44 ( V_138 [ 0 ] , V_101 ) ;
if ( ( V_138 [ 0 ] & V_108 ) &&
F_66 ( V_101 , V_40 ) == V_65 ) {
V_138 [ 0 ] |= V_107 ;
F_78 ( V_1 , V_138 , V_34 ) ;
V_181 = V_138 [ 1 ] & ( V_48 | V_49 ) ;
* V_196 |= V_181 << V_195 ;
V_5 [ V_34 ] . V_147 = V_101 | V_181 ;
}
F_77 ( V_196 ) ;
V_138 [ 0 ] &= ~ V_106 ;
}
return 0 ;
}
int F_86 ( struct V_1 * V_1 , unsigned long V_177 )
{
if ( V_1 -> V_10 . V_103 )
F_82 ( V_1 , V_177 , F_85 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_1 , unsigned long * V_196 ,
unsigned long V_65 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_22 ;
unsigned long V_208 , V_34 , V_203 ;
unsigned long * V_138 ;
int V_43 = 0 ;
V_209:
F_75 ( V_196 ) ;
if ( * V_196 & V_210 ) {
* V_196 &= ~ V_210 ;
V_43 = 1 ;
}
if ( ! ( * V_196 & V_204 ) ) {
F_77 ( V_196 ) ;
return V_43 ;
}
V_34 = V_208 = * V_196 & V_205 ;
do {
V_138 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_34 << 4 ) ) ;
V_203 = V_5 [ V_34 ] . V_206 ;
if ( ! ( V_138 [ 1 ] & V_48 ) )
continue;
if ( ! F_63 ( V_138 , V_106 ) ) {
F_77 ( V_196 ) ;
while ( V_138 [ 0 ] & V_106 )
F_64 () ;
goto V_209;
}
if ( ( V_138 [ 0 ] & V_108 ) && ( V_138 [ 1 ] & V_48 ) ) {
F_88 ( V_1 , V_138 , V_34 ) ;
V_5 [ V_34 ] . V_147 |= V_48 ;
V_43 = 1 ;
}
V_138 [ 0 ] &= ~ V_106 ;
} while ( ( V_34 = V_203 ) != V_208 );
F_77 ( V_196 ) ;
return V_43 ;
}
int F_89 ( struct V_1 * V_1 , unsigned long V_177 )
{
if ( ! V_1 -> V_10 . V_103 )
return 0 ;
return F_82 ( V_1 , V_177 , F_87 ) ;
}
static int F_90 ( struct V_1 * V_1 , unsigned long * V_196 ,
unsigned long V_65 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_22 ;
unsigned long V_208 , V_34 , V_203 ;
unsigned long * V_211 ;
int V_43 = 1 ;
if ( * V_196 & V_210 )
return 1 ;
F_75 ( V_196 ) ;
if ( * V_196 & V_210 )
goto V_96;
if ( * V_196 & V_204 ) {
V_34 = V_208 = * V_196 & V_205 ;
do {
V_211 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_34 << 4 ) ) ;
V_203 = V_5 [ V_34 ] . V_206 ;
if ( V_211 [ 1 ] & V_48 )
goto V_96;
} while ( ( V_34 = V_203 ) != V_208 );
}
V_43 = 0 ;
V_96:
F_77 ( V_196 ) ;
return V_43 ;
}
int F_91 ( struct V_1 * V_1 , unsigned long V_177 )
{
if ( ! V_1 -> V_10 . V_103 )
return 0 ;
return F_82 ( V_1 , V_177 , F_90 ) ;
}
void F_92 ( struct V_1 * V_1 , unsigned long V_177 , T_4 V_190 )
{
if ( ! V_1 -> V_10 . V_103 )
return;
F_82 ( V_1 , V_177 , F_85 ) ;
}
static int F_93 ( struct V_1 * V_1 , unsigned long * V_196 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_22 ;
unsigned long V_208 , V_34 , V_203 ;
unsigned long * V_138 ;
int V_43 = 0 ;
V_209:
F_75 ( V_196 ) ;
if ( * V_196 & V_212 ) {
* V_196 &= ~ V_212 ;
V_43 = 1 ;
}
if ( ! ( * V_196 & V_204 ) ) {
F_77 ( V_196 ) ;
return V_43 ;
}
V_34 = V_208 = * V_196 & V_205 ;
do {
V_138 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_34 << 4 ) ) ;
V_203 = V_5 [ V_34 ] . V_206 ;
if ( ! ( V_138 [ 1 ] & V_49 ) )
continue;
if ( ! F_63 ( V_138 , V_106 ) ) {
F_77 ( V_196 ) ;
while ( V_138 [ 0 ] & V_106 )
F_64 () ;
goto V_209;
}
if ( ( V_138 [ 0 ] & V_108 ) && ( V_138 [ 1 ] & V_49 ) ) {
V_138 [ 0 ] |= V_107 ;
F_78 ( V_1 , V_138 , V_34 ) ;
V_138 [ 1 ] &= ~ V_49 ;
F_80 () ;
V_138 [ 0 ] = ( V_138 [ 0 ] & ~ V_107 ) | V_108 ;
V_5 [ V_34 ] . V_147 |= V_49 ;
V_43 = 1 ;
}
V_138 [ 0 ] &= ~ V_106 ;
} while ( ( V_34 = V_203 ) != V_208 );
F_77 ( V_196 ) ;
return V_43 ;
}
long F_94 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
unsigned long V_34 ;
unsigned long * V_196 , * V_213 ;
F_62 () ;
V_196 = V_32 -> V_178 ;
V_213 = V_32 -> V_214 ;
for ( V_34 = 0 ; V_34 < V_32 -> V_35 ; ++ V_34 ) {
if ( F_93 ( V_1 , V_196 ) )
F_95 ( V_34 , V_213 ) ;
++ V_196 ;
}
F_65 () ;
return 0 ;
}
void * F_96 ( struct V_1 * V_1 , unsigned long V_102 ,
unsigned long * V_215 )
{
struct V_31 * V_32 ;
unsigned long V_65 = V_102 >> V_17 ;
struct V_69 * V_69 , * V_71 [ 1 ] ;
int V_35 ;
unsigned long V_177 , V_40 , V_216 ;
unsigned long V_217 ;
unsigned long * V_73 ;
V_32 = F_45 ( V_1 , V_65 ) ;
if ( ! V_32 || ( V_32 -> V_98 & V_110 ) )
return NULL ;
if ( ! V_1 -> V_10 . V_103 ) {
V_73 = V_1 -> V_10 . V_80 [ V_32 -> V_81 ] ;
if ( ! V_73 )
return NULL ;
V_73 += V_65 - V_32 -> V_82 ;
V_217 = * V_73 ;
if ( ! V_217 ) {
if ( F_26 ( V_1 , V_65 , V_32 ,
V_93 ) < 0 )
return NULL ;
V_217 = * V_73 ;
}
V_69 = F_97 ( V_217 >> V_17 ) ;
F_38 ( V_69 ) ;
} else {
V_177 = F_27 ( V_32 , V_65 ) ;
V_35 = F_28 ( V_177 , 1 , 1 , V_71 ) ;
if ( V_35 < 1 )
return NULL ;
V_69 = V_71 [ 0 ] ;
}
V_40 = V_93 ;
if ( F_34 ( V_69 ) ) {
V_69 = F_35 ( V_69 ) ;
V_40 <<= F_36 ( V_69 ) ;
}
V_216 = V_102 & ( V_40 - 1 ) ;
if ( V_215 )
* V_215 = V_40 - V_216 ;
return F_98 ( V_69 ) + V_216 ;
}
void F_99 ( struct V_1 * V_1 , void * V_218 )
{
struct V_69 * V_69 = F_100 ( V_218 ) ;
F_39 ( V_69 ) ;
}
void F_101 ( struct V_29 * V_30 )
{
struct V_219 * V_220 = & V_30 -> V_10 . V_220 ;
if ( F_20 ( V_59 ) )
V_30 -> V_10 . V_118 = 32 ;
else
V_30 -> V_10 . V_118 = 64 ;
V_220 -> V_221 = F_51 ;
V_220 -> V_222 = F_24 ;
V_30 -> V_10 . V_223 |= V_224 ;
}
