long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
long V_3 ;
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
V_3 = F_6 () ;
if ( V_3 < 0 )
goto V_23;
V_1 -> V_10 . V_24 = F_7 ( V_2 ) | ( V_16 - 18 ) ;
V_1 -> V_10 . V_3 = V_3 ;
F_8 ( L_3 , V_2 , V_3 ) ;
return 0 ;
V_23:
F_9 ( V_5 ) ;
V_21:
F_10 ( V_2 , V_16 - V_17 ) ;
return - V_18 ;
}
void F_11 ( struct V_1 * V_1 )
{
F_12 ( V_1 -> V_10 . V_3 ) ;
F_9 ( V_1 -> V_10 . V_22 ) ;
if ( V_1 -> V_10 . V_11 )
F_13 ( V_1 -> V_10 . V_11 ) ;
else
F_10 ( V_1 -> V_10 . V_19 , V_16 - V_17 ) ;
}
static inline unsigned long F_14 ( unsigned long V_25 )
{
return ( V_25 > 0x1000 ) ? V_26 : 0 ;
}
static inline unsigned long F_15 ( unsigned long V_25 )
{
return ( V_25 == 0x10000 ) ? 0x1000 : 0 ;
}
void F_16 ( struct V_27 * V_28 , struct V_29 * V_30 ,
unsigned long V_31 )
{
unsigned long V_32 ;
unsigned long V_33 ;
unsigned long V_34 , V_35 ;
unsigned long V_36 , V_37 ;
unsigned long V_38 ;
unsigned long V_39 , V_40 ;
long V_41 ;
V_38 = 1ul << V_31 ;
V_33 = V_30 -> V_33 >> ( V_31 - V_17 ) ;
if ( V_33 > 1ul << ( 40 - V_31 ) )
V_33 = 1ul << ( 40 - V_31 ) ;
if ( V_33 > V_42 )
V_33 = V_42 ;
V_39 = V_43 | ( V_44 << ( 40 - 16 ) ) |
V_45 | F_14 ( V_38 ) ;
V_40 = F_15 ( V_38 ) |
V_46 | V_47 | V_48 | V_49 ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
V_36 = V_32 << V_31 ;
V_37 = ( V_32 ^ ( V_44 ^ ( V_44 << 25 ) ) ) & V_50 ;
V_37 = ( V_37 << 3 ) + 7 ;
V_34 = V_39 | ( ( V_36 >> 16 ) & ~ 0x7fUL ) ;
V_35 = V_40 | V_36 ;
V_41 = F_17 ( V_28 , V_51 , V_37 , V_34 , V_35 ) ;
if ( V_41 != V_52 ) {
F_4 ( L_4 ,
V_36 , V_41 ) ;
break;
}
}
}
int F_18 ( void )
{
unsigned long V_53 , V_54 ;
if ( ! F_19 ( V_55 ) )
return - V_56 ;
if ( F_19 ( V_57 ) ) {
V_53 = F_20 ( V_58 ) ;
V_54 = V_59 ;
} else {
V_53 = 0 ;
V_54 = V_60 ;
}
F_21 ( V_54 + 1 ) ;
F_22 ( V_53 ) ;
F_22 ( V_54 ) ;
return 0 ;
}
void F_23 ( struct V_27 * V_28 )
{
}
static void F_24 ( struct V_27 * V_28 )
{
F_25 ( V_28 , V_61 | V_62 ) ;
}
static long F_26 ( struct V_1 * V_1 , unsigned long V_63 ,
struct V_29 * V_30 ,
unsigned long V_38 )
{
unsigned long V_64 ;
long V_65 , V_66 ;
struct V_67 * V_67 , * V_68 , * V_69 [ 1 ] ;
unsigned long V_70 , V_25 ;
unsigned long * V_71 ;
unsigned int V_72 , V_73 , V_74 ;
struct V_75 * V_76 ;
unsigned long V_77 , V_32 , V_33 ;
V_71 = V_1 -> V_10 . V_78 [ V_30 -> V_79 ] ;
if ( ! V_71 )
return - V_56 ;
if ( V_71 [ V_63 - V_30 -> V_80 ] )
return 0 ;
V_72 = 0 ;
V_73 = 0 ;
V_67 = NULL ;
V_25 = V_38 ;
V_66 = - V_56 ;
V_64 = F_27 ( V_30 , V_63 ) ;
V_65 = F_28 ( V_64 , 1 , 1 , V_69 ) ;
if ( V_65 != 1 ) {
F_29 ( & V_81 -> V_82 -> V_83 ) ;
V_76 = F_30 ( V_81 -> V_82 , V_64 ) ;
if ( ! V_76 || V_76 -> V_84 > V_64 ||
V_64 + V_38 > V_76 -> V_85 ||
! ( V_76 -> V_86 & V_87 ) )
goto V_88;
V_72 = F_31 ( F_32 ( V_76 -> V_89 ) ) ;
V_77 = V_76 -> V_90 + ( ( V_64 - V_76 -> V_84 ) >> V_17 ) ;
if ( V_38 > V_91 && ( V_77 & ( ( V_38 >> V_17 ) - 1 ) ) )
goto V_88;
F_33 ( & V_81 -> V_82 -> V_83 ) ;
} else {
V_67 = V_69 [ 0 ] ;
V_73 = V_92 ;
V_70 = V_91 ;
if ( F_34 ( V_67 ) ) {
V_68 = F_35 ( V_67 ) ;
V_70 <<= F_36 ( V_68 ) ;
if ( V_70 > V_38 && F_37 ( V_30 , V_70 ) &&
! ( V_30 -> V_93 & ( V_70 - 1 ) ) ) {
V_64 &= ~ ( V_70 - 1 ) ;
V_25 = V_70 ;
F_38 ( V_68 ) ;
F_39 ( V_67 ) ;
V_67 = V_68 ;
}
}
if ( V_70 < V_38 )
goto V_94;
V_77 = F_40 ( V_67 ) ;
}
V_33 = V_25 >> V_17 ;
V_74 = F_41 ( V_33 ) ;
V_71 += ( V_63 - V_30 -> V_80 ) & ~ ( V_33 - 1 ) ;
F_42 ( & V_1 -> V_10 . V_95 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
if ( ! V_71 [ V_32 ] ) {
V_71 [ V_32 ] = ( ( V_77 + V_32 ) << V_17 ) +
V_73 + V_72 + V_74 ;
V_73 = 0 ;
}
}
F_43 ( & V_1 -> V_10 . V_95 ) ;
V_66 = 0 ;
V_94:
if ( V_73 )
F_39 ( V_67 ) ;
return V_66 ;
V_88:
F_33 ( & V_81 -> V_82 -> V_83 ) ;
return V_66 ;
}
long F_17 ( struct V_27 * V_28 , unsigned long V_96 ,
long V_97 , unsigned long V_98 , unsigned long V_99 )
{
struct V_1 * V_1 = V_28 -> V_1 ;
unsigned long V_38 , V_100 , V_63 ;
struct V_29 * V_30 ;
long V_41 ;
if ( V_1 -> V_10 . V_101 )
goto V_102;
V_38 = F_44 ( V_98 , V_99 ) ;
if ( ! V_38 )
return V_103 ;
V_98 &= ~ ( V_104 | V_105 | V_106 ) ;
V_100 = ( V_99 & V_107 ) & ~ ( V_38 - 1 ) ;
V_63 = V_100 >> V_17 ;
V_30 = F_45 ( V_1 , V_63 ) ;
if ( V_30 && ! ( V_30 -> V_96 & V_108 ) ) {
if ( ! F_37 ( V_30 , V_38 ) )
return V_103 ;
if ( F_26 ( V_1 , V_63 , V_30 , V_38 ) < 0 )
return V_103 ;
}
V_102:
F_46 () ;
V_28 -> V_10 . V_109 = V_81 -> V_82 -> V_110 ;
V_41 = F_47 ( V_28 , V_96 , V_97 , V_98 , V_99 ) ;
F_48 () ;
if ( V_41 == V_111 ) {
F_4 ( L_5 ) ;
V_41 = V_112 ;
}
return V_41 ;
}
static struct V_113 * F_49 ( struct V_27 * V_28 ,
T_1 V_114 )
{
T_2 V_115 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_28 -> V_10 . V_116 ; V_32 ++ ) {
if ( ! ( V_28 -> V_10 . V_117 [ V_32 ] . V_118 & V_119 ) )
continue;
if ( V_28 -> V_10 . V_117 [ V_32 ] . V_120 & V_121 )
V_115 = V_122 ;
else
V_115 = V_123 ;
if ( ( ( V_28 -> V_10 . V_117 [ V_32 ] . V_118 ^ V_114 ) & V_115 ) == 0 )
return & V_28 -> V_10 . V_117 [ V_32 ] ;
}
return NULL ;
}
static unsigned long F_50 ( unsigned long V_124 , unsigned long V_125 ,
unsigned long V_126 )
{
unsigned long V_127 ;
V_127 = F_44 ( V_124 , V_125 ) - 1 ;
return ( V_125 & V_107 & ~ V_127 ) | ( V_126 & V_127 ) ;
}
static int F_51 ( struct V_27 * V_28 , T_1 V_114 ,
struct V_128 * V_129 , bool V_130 )
{
struct V_1 * V_1 = V_28 -> V_1 ;
struct V_113 * V_131 ;
unsigned long V_132 ;
unsigned long V_133 , V_134 ;
unsigned long V_124 , V_135 ;
unsigned long * V_136 ;
int V_137 ;
int V_138 = V_28 -> V_10 . V_139 . V_140 & ( V_130 ? V_141 : V_142 ) ;
if ( V_138 ) {
V_131 = F_49 ( V_28 , V_114 ) ;
if ( ! V_131 )
return - V_56 ;
V_132 = V_131 -> V_120 ;
} else {
V_132 = V_28 -> V_1 -> V_10 . V_143 ;
}
V_137 = F_52 ( V_1 , V_114 , V_132 ,
V_106 | V_105 ) ;
if ( V_137 < 0 )
return - V_144 ;
V_136 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_137 << 4 ) ) ;
V_124 = V_136 [ 0 ] & ~ V_104 ;
V_135 = V_1 -> V_10 . V_22 [ V_137 ] . V_145 ;
asm volatile("lwsync" : : : "memory");
V_136 [ 0 ] = V_124 ;
V_129 -> V_114 = V_114 ;
V_129 -> V_146 = ( ( V_124 & V_147 ) << 4 ) | ( ( V_114 >> 12 ) & 0xfff ) ;
V_133 = V_135 & ( V_148 | V_149 ) ;
V_134 = ( V_28 -> V_10 . V_139 . V_140 & V_150 ) ? V_151 : V_152 ;
V_134 &= V_132 ;
V_129 -> V_153 = F_53 ( V_133 , V_134 ) ;
V_129 -> V_154 = F_54 ( V_133 , V_134 ) ;
V_129 -> V_155 = V_129 -> V_153 && ! ( V_135 & ( V_156 | V_157 ) ) ;
if ( V_130 && V_138 && F_19 ( V_57 ) ) {
int V_158 = F_55 ( V_135 , V_28 -> V_10 . V_159 ) ;
if ( V_158 & 1 )
V_129 -> V_153 = 0 ;
if ( V_158 & 2 )
V_129 -> V_154 = 0 ;
}
V_129 -> V_160 = F_50 ( V_124 , V_135 , V_114 ) ;
return 0 ;
}
static int F_56 ( unsigned int V_161 )
{
unsigned int V_115 ;
V_115 = 0x10000000 ;
if ( ( V_161 & 0xfc000000 ) == 0x7c000000 )
V_115 = 0x100 ;
return ( V_161 & V_115 ) != 0 ;
}
static int F_57 ( struct V_162 * V_163 , struct V_27 * V_28 ,
unsigned long V_100 , T_1 V_126 , int V_164 )
{
int V_41 ;
T_3 V_165 ;
unsigned long V_166 = F_58 ( V_28 ) ;
if ( V_28 -> V_10 . V_165 == V_167 ) {
V_41 = F_59 ( V_28 , & V_166 , sizeof( T_3 ) , & V_165 , false ) ;
if ( V_41 != V_168 || V_165 == V_167 )
return V_169 ;
V_28 -> V_10 . V_165 = V_165 ;
}
if ( F_56 ( V_28 -> V_10 . V_165 ) != ! ! V_164 )
return V_169 ;
V_28 -> V_10 . V_170 = V_100 ;
V_28 -> V_10 . V_171 = V_126 ;
return F_60 ( V_163 , V_28 ) ;
}
int F_61 ( struct V_162 * V_163 , struct V_27 * V_28 ,
unsigned long V_126 , unsigned long V_172 )
{
struct V_1 * V_1 = V_28 -> V_1 ;
unsigned long * V_136 , V_173 [ 3 ] , V_125 ;
unsigned long V_174 , V_38 , V_175 ;
unsigned long V_63 , V_176 , V_77 ;
struct V_29 * V_30 ;
unsigned long * V_177 ;
struct V_4 * V_5 ;
struct V_67 * V_67 , * V_69 [ 1 ] ;
long V_137 , V_41 , V_33 ;
unsigned long V_72 ;
unsigned int V_178 , V_179 ;
struct V_75 * V_76 ;
unsigned long V_180 ;
if ( V_126 != V_28 -> V_10 . V_181 )
return V_169 ;
V_137 = V_28 -> V_10 . V_182 ;
V_136 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_137 << 4 ) ) ;
V_5 = & V_1 -> V_10 . V_22 [ V_137 ] ;
F_62 () ;
while ( ! F_63 ( V_136 , V_104 ) )
F_64 () ;
V_173 [ 0 ] = V_136 [ 0 ] & ~ V_104 ;
V_173 [ 1 ] = V_136 [ 1 ] ;
V_173 [ 2 ] = V_125 = V_5 -> V_145 ;
asm volatile("lwsync" : : : "memory");
V_136 [ 0 ] = V_173 [ 0 ] ;
F_65 () ;
if ( V_173 [ 0 ] != V_28 -> V_10 . V_183 [ 0 ] ||
V_173 [ 1 ] != V_28 -> V_10 . V_183 [ 1 ] )
return V_169 ;
V_38 = F_44 ( V_173 [ 0 ] , V_125 ) ;
V_63 = F_66 ( V_125 , V_38 ) ;
V_30 = F_45 ( V_1 , V_63 ) ;
if ( ! V_30 || ( V_30 -> V_96 & V_108 ) ) {
unsigned long V_100 = ( V_63 << V_17 ) | ( V_126 & ( V_38 - 1 ) ) ;
return F_57 ( V_163 , V_28 , V_100 , V_126 ,
V_172 & V_184 ) ;
}
if ( ! V_1 -> V_10 . V_101 )
return - V_185 ;
V_174 = V_1 -> V_186 ;
F_67 () ;
V_72 = 0 ;
V_77 = 0 ;
V_67 = NULL ;
V_175 = V_91 ;
V_178 = ( V_172 & V_184 ) != 0 ;
V_179 = V_178 ;
V_176 = F_27 ( V_30 , V_63 ) ;
V_33 = F_28 ( V_176 , 1 , V_178 , V_69 ) ;
if ( V_33 < 1 ) {
F_29 ( & V_81 -> V_82 -> V_83 ) ;
V_76 = F_30 ( V_81 -> V_82 , V_176 ) ;
if ( V_76 && V_76 -> V_84 <= V_176 && V_176 + V_38 <= V_76 -> V_85 &&
( V_76 -> V_86 & V_87 ) ) {
V_77 = V_76 -> V_90 +
( ( V_176 - V_76 -> V_84 ) >> V_17 ) ;
V_175 = V_38 ;
V_72 = F_31 ( F_32 ( V_76 -> V_89 ) ) ;
V_179 = V_76 -> V_86 & V_187 ;
}
F_33 ( & V_81 -> V_82 -> V_83 ) ;
if ( ! V_77 )
return - V_185 ;
} else {
V_67 = V_69 [ 0 ] ;
if ( F_34 ( V_67 ) ) {
V_67 = F_35 ( V_67 ) ;
V_175 <<= F_36 ( V_67 ) ;
}
if ( ! V_178 && F_68 ( V_125 ) ) {
T_4 * V_188 , V_189 ;
F_46 () ;
V_188 = F_69 ( V_81 -> V_82 -> V_110 ,
V_176 , NULL ) ;
if ( V_188 && F_70 ( * V_188 ) ) {
V_189 = F_71 ( V_188 , 1 ) ;
if ( F_72 ( V_189 ) )
V_179 = 1 ;
}
F_48 () ;
}
V_77 = F_40 ( V_67 ) ;
}
V_41 = - V_185 ;
if ( V_38 > V_175 )
goto V_190;
if ( ! F_73 ( V_125 , V_72 ) ) {
if ( V_72 )
return - V_185 ;
V_125 = ( V_125 & ~ ( V_191 | V_192 | V_157 ) ) | V_48 ;
}
V_125 = ( V_125 & ~ ( V_148 - V_175 ) ) | ( V_77 << V_17 ) ;
if ( F_68 ( V_125 ) && ! V_179 )
V_125 = F_74 ( V_125 ) ;
V_41 = V_169 ;
F_62 () ;
while ( ! F_63 ( V_136 , V_104 ) )
F_64 () ;
if ( ( V_136 [ 0 ] & ~ V_104 ) != V_173 [ 0 ] || V_136 [ 1 ] != V_173 [ 1 ] ||
V_5 -> V_145 != V_173 [ 2 ] )
goto V_193;
V_173 [ 0 ] = ( V_173 [ 0 ] & ~ V_105 ) | V_106 ;
V_177 = & V_30 -> V_177 [ V_63 - V_30 -> V_80 ] ;
F_75 ( V_177 ) ;
V_41 = V_169 ;
if ( F_76 ( V_28 , V_174 ) ) {
F_77 ( V_177 ) ;
goto V_193;
}
V_180 = * V_177 >> V_194 ;
V_125 &= V_180 | ~ ( V_46 | V_47 ) ;
if ( V_136 [ 0 ] & V_106 ) {
F_77 ( V_177 ) ;
V_136 [ 0 ] |= V_105 ;
F_78 ( V_1 , V_136 , V_137 ) ;
V_125 |= V_136 [ 1 ] & ( V_46 | V_47 ) ;
} else {
F_79 ( V_1 , V_5 , V_177 , V_137 , 0 ) ;
}
V_136 [ 1 ] = V_125 ;
F_80 () ;
V_136 [ 0 ] = V_173 [ 0 ] ;
asm volatile("ptesync" : : : "memory");
F_65 () ;
if ( V_67 && F_68 ( V_125 ) )
F_81 ( V_67 ) ;
V_190:
if ( V_67 ) {
F_39 ( V_69 [ 0 ] ) ;
}
return V_41 ;
V_193:
V_136 [ 0 ] &= ~ V_104 ;
F_65 () ;
goto V_190;
}
static int F_82 ( struct V_1 * V_1 , unsigned long V_176 ,
int (* F_83)( struct V_1 * V_1 , unsigned long * V_195 ,
unsigned long V_63 ) )
{
int V_41 ;
int V_196 = 0 ;
struct V_197 * V_198 ;
struct V_29 * V_30 ;
V_198 = V_197 ( V_1 ) ;
F_84 (memslot, slots) {
unsigned long V_64 = V_30 -> V_93 ;
unsigned long V_199 ;
V_199 = V_64 + ( V_30 -> V_33 << V_17 ) ;
if ( V_176 >= V_64 && V_176 < V_199 ) {
T_5 V_200 = ( V_176 - V_64 ) >> V_17 ;
V_41 = F_83 ( V_1 , & V_30 -> V_177 [ V_200 ] ,
V_30 -> V_80 + V_200 ) ;
V_196 |= V_41 ;
}
}
return V_196 ;
}
static int F_85 ( struct V_1 * V_1 , unsigned long * V_195 ,
unsigned long V_63 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_22 ;
unsigned long V_201 , V_32 , V_202 ;
unsigned long * V_136 ;
unsigned long V_99 , V_38 , V_180 ;
for (; ; ) {
F_75 ( V_195 ) ;
if ( ! ( * V_195 & V_203 ) ) {
F_77 ( V_195 ) ;
break;
}
V_32 = * V_195 & V_204 ;
V_136 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_32 << 4 ) ) ;
if ( ! F_63 ( V_136 , V_104 ) ) {
F_77 ( V_195 ) ;
while ( V_136 [ 0 ] & V_104 )
F_64 () ;
continue;
}
V_202 = V_5 [ V_32 ] . V_205 ;
if ( V_202 == V_32 ) {
* V_195 &= ~ ( V_203 | V_204 ) ;
} else {
V_201 = V_5 [ V_32 ] . V_206 ;
V_5 [ V_201 ] . V_205 = V_202 ;
V_5 [ V_202 ] . V_206 = V_201 ;
V_5 [ V_32 ] . V_205 = V_5 [ V_32 ] . V_206 = V_32 ;
* V_195 = ( * V_195 & ~ V_204 ) | V_202 ;
}
V_99 = V_5 [ V_32 ] . V_145 ;
V_38 = F_44 ( V_136 [ 0 ] , V_99 ) ;
if ( ( V_136 [ 0 ] & V_106 ) &&
F_66 ( V_99 , V_38 ) == V_63 ) {
V_136 [ 0 ] |= V_105 ;
F_78 ( V_1 , V_136 , V_32 ) ;
V_180 = V_136 [ 1 ] & ( V_46 | V_47 ) ;
* V_195 |= V_180 << V_194 ;
V_5 [ V_32 ] . V_145 = V_99 | V_180 ;
}
F_77 ( V_195 ) ;
V_136 [ 0 ] &= ~ V_104 ;
}
return 0 ;
}
int F_86 ( struct V_1 * V_1 , unsigned long V_176 )
{
if ( V_1 -> V_10 . V_101 )
F_82 ( V_1 , V_176 , F_85 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_1 , unsigned long * V_195 ,
unsigned long V_63 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_22 ;
unsigned long V_207 , V_32 , V_202 ;
unsigned long * V_136 ;
int V_41 = 0 ;
V_208:
F_75 ( V_195 ) ;
if ( * V_195 & V_209 ) {
* V_195 &= ~ V_209 ;
V_41 = 1 ;
}
if ( ! ( * V_195 & V_203 ) ) {
F_77 ( V_195 ) ;
return V_41 ;
}
V_32 = V_207 = * V_195 & V_204 ;
do {
V_136 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_32 << 4 ) ) ;
V_202 = V_5 [ V_32 ] . V_205 ;
if ( ! ( V_136 [ 1 ] & V_46 ) )
continue;
if ( ! F_63 ( V_136 , V_104 ) ) {
F_77 ( V_195 ) ;
while ( V_136 [ 0 ] & V_104 )
F_64 () ;
goto V_208;
}
if ( ( V_136 [ 0 ] & V_106 ) && ( V_136 [ 1 ] & V_46 ) ) {
F_88 ( V_1 , V_136 , V_32 ) ;
V_5 [ V_32 ] . V_145 |= V_46 ;
V_41 = 1 ;
}
V_136 [ 0 ] &= ~ V_104 ;
} while ( ( V_32 = V_202 ) != V_207 );
F_77 ( V_195 ) ;
return V_41 ;
}
int F_89 ( struct V_1 * V_1 , unsigned long V_176 )
{
if ( ! V_1 -> V_10 . V_101 )
return 0 ;
return F_82 ( V_1 , V_176 , F_87 ) ;
}
static int F_90 ( struct V_1 * V_1 , unsigned long * V_195 ,
unsigned long V_63 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_22 ;
unsigned long V_207 , V_32 , V_202 ;
unsigned long * V_210 ;
int V_41 = 1 ;
if ( * V_195 & V_209 )
return 1 ;
F_75 ( V_195 ) ;
if ( * V_195 & V_209 )
goto V_94;
if ( * V_195 & V_203 ) {
V_32 = V_207 = * V_195 & V_204 ;
do {
V_210 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_32 << 4 ) ) ;
V_202 = V_5 [ V_32 ] . V_205 ;
if ( V_210 [ 1 ] & V_46 )
goto V_94;
} while ( ( V_32 = V_202 ) != V_207 );
}
V_41 = 0 ;
V_94:
F_77 ( V_195 ) ;
return V_41 ;
}
int F_91 ( struct V_1 * V_1 , unsigned long V_176 )
{
if ( ! V_1 -> V_10 . V_101 )
return 0 ;
return F_82 ( V_1 , V_176 , F_90 ) ;
}
void F_92 ( struct V_1 * V_1 , unsigned long V_176 , T_4 V_189 )
{
if ( ! V_1 -> V_10 . V_101 )
return;
F_82 ( V_1 , V_176 , F_85 ) ;
}
static int F_93 ( struct V_1 * V_1 , unsigned long * V_195 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_22 ;
unsigned long V_207 , V_32 , V_202 ;
unsigned long * V_136 ;
int V_41 = 0 ;
V_208:
F_75 ( V_195 ) ;
if ( * V_195 & V_211 ) {
* V_195 &= ~ V_211 ;
V_41 = 1 ;
}
if ( ! ( * V_195 & V_203 ) ) {
F_77 ( V_195 ) ;
return V_41 ;
}
V_32 = V_207 = * V_195 & V_204 ;
do {
V_136 = ( unsigned long * ) ( V_1 -> V_10 . V_19 + ( V_32 << 4 ) ) ;
V_202 = V_5 [ V_32 ] . V_205 ;
if ( ! ( V_136 [ 1 ] & V_47 ) )
continue;
if ( ! F_63 ( V_136 , V_104 ) ) {
F_77 ( V_195 ) ;
while ( V_136 [ 0 ] & V_104 )
F_64 () ;
goto V_208;
}
if ( ( V_136 [ 0 ] & V_106 ) && ( V_136 [ 1 ] & V_47 ) ) {
V_136 [ 0 ] |= V_105 ;
F_78 ( V_1 , V_136 , V_32 ) ;
V_136 [ 1 ] &= ~ V_47 ;
F_80 () ;
V_136 [ 0 ] = ( V_136 [ 0 ] & ~ V_105 ) | V_106 ;
V_5 [ V_32 ] . V_145 |= V_47 ;
V_41 = 1 ;
}
V_136 [ 0 ] &= ~ V_104 ;
} while ( ( V_32 = V_202 ) != V_207 );
F_77 ( V_195 ) ;
return V_41 ;
}
long F_94 ( struct V_1 * V_1 , struct V_29 * V_30 )
{
unsigned long V_32 ;
unsigned long * V_195 , * V_212 ;
F_62 () ;
V_195 = V_30 -> V_177 ;
V_212 = V_30 -> V_213 ;
for ( V_32 = 0 ; V_32 < V_30 -> V_33 ; ++ V_32 ) {
if ( F_93 ( V_1 , V_195 ) )
F_95 ( V_32 , V_212 ) ;
++ V_195 ;
}
F_65 () ;
return 0 ;
}
void * F_96 ( struct V_1 * V_1 , unsigned long V_100 ,
unsigned long * V_214 )
{
struct V_29 * V_30 ;
unsigned long V_63 = V_100 >> V_17 ;
struct V_67 * V_67 , * V_69 [ 1 ] ;
int V_33 ;
unsigned long V_176 , V_38 , V_215 ;
unsigned long V_216 ;
unsigned long * V_71 ;
V_30 = F_45 ( V_1 , V_63 ) ;
if ( ! V_30 || ( V_30 -> V_96 & V_108 ) )
return NULL ;
if ( ! V_1 -> V_10 . V_101 ) {
V_71 = V_1 -> V_10 . V_78 [ V_30 -> V_79 ] ;
if ( ! V_71 )
return NULL ;
V_71 += V_63 - V_30 -> V_80 ;
V_216 = * V_71 ;
if ( ! V_216 ) {
if ( F_26 ( V_1 , V_63 , V_30 ,
V_91 ) < 0 )
return NULL ;
V_216 = * V_71 ;
}
V_67 = F_97 ( V_216 >> V_17 ) ;
F_38 ( V_67 ) ;
} else {
V_176 = F_27 ( V_30 , V_63 ) ;
V_33 = F_28 ( V_176 , 1 , 1 , V_69 ) ;
if ( V_33 < 1 )
return NULL ;
V_67 = V_69 [ 0 ] ;
}
V_38 = V_91 ;
if ( F_34 ( V_67 ) ) {
V_67 = F_35 ( V_67 ) ;
V_38 <<= F_36 ( V_67 ) ;
}
V_215 = V_100 & ( V_38 - 1 ) ;
if ( V_214 )
* V_214 = V_38 - V_215 ;
return F_98 ( V_67 ) + V_215 ;
}
void F_99 ( struct V_1 * V_1 , void * V_217 )
{
struct V_67 * V_67 = F_100 ( V_217 ) ;
F_39 ( V_67 ) ;
}
void F_101 ( struct V_27 * V_28 )
{
struct V_218 * V_219 = & V_28 -> V_10 . V_219 ;
if ( F_19 ( V_57 ) )
V_28 -> V_10 . V_116 = 32 ;
else
V_28 -> V_10 . V_116 = 64 ;
V_219 -> V_220 = F_51 ;
V_219 -> V_221 = F_24 ;
V_28 -> V_10 . V_222 |= V_223 ;
}
