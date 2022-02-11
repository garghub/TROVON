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
while ( ! V_3 && V_7 > V_9 && ! V_2 ) {
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
F_6 ( & V_1 -> V_10 . V_22 , 0 ) ;
V_5 = F_7 ( sizeof( struct V_4 ) * V_1 -> V_10 . V_20 ) ;
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
F_11 ( V_6 , 1 << ( V_7 - V_12 ) ) ;
else
F_12 ( V_3 , V_7 - V_12 ) ;
return - V_17 ;
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
if ( V_1 -> V_10 . V_18 ) {
V_7 = V_1 -> V_10 . V_19 ;
memset ( ( void * ) V_1 -> V_10 . V_18 , 0 , 1ul << V_7 ) ;
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
F_11 ( F_23 ( V_1 -> V_10 . V_18 ) ,
1 << ( V_1 -> V_10 . V_19 - V_12 ) ) ;
else
F_12 ( V_1 -> V_10 . V_18 ,
V_1 -> V_10 . V_19 - V_12 ) ;
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
V_42 = V_39 -> V_42 >> ( V_40 - V_12 ) ;
if ( V_42 > 1ul << ( 40 - V_40 ) )
V_42 = 1ul << ( 40 - V_40 ) ;
if ( V_42 > V_1 -> V_10 . V_21 + 1 )
V_42 = V_1 -> V_10 . V_21 + 1 ;
V_48 = V_52 | ( V_53 << ( 40 - 16 ) ) |
V_54 | F_24 ( V_47 ) ;
V_49 = F_25 ( V_47 ) |
V_55 | V_56 | V_57 | V_58 ;
for ( V_41 = 0 ; V_41 < V_42 ; ++ V_41 ) {
V_45 = V_41 << V_40 ;
V_46 = ( V_41 ^ ( V_53 ^ ( V_53 << 25 ) ) ) & V_1 -> V_10 . V_21 ;
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
V_61 = F_30 ( V_65 ) ;
V_62 = V_66 ;
F_31 ( V_62 + 1 ) ;
F_32 ( V_61 ) ;
F_32 ( V_62 ) ;
return 0 ;
}
static void F_33 ( struct V_36 * V_37 )
{
unsigned long V_67 = V_37 -> V_10 . V_68 ;
if ( F_34 ( V_37 -> V_10 . V_69 . V_67 ) )
V_67 |= V_70 ;
else
V_67 |= V_37 -> V_10 . V_69 . V_67 & V_71 ;
F_35 ( V_37 , V_67 ) ;
}
static long F_27 ( struct V_1 * V_1 , unsigned long V_72 ,
long V_73 , unsigned long V_74 ,
unsigned long V_75 , unsigned long * V_76 )
{
long V_51 ;
F_36 () ;
V_51 = F_37 ( V_1 , V_72 , V_73 , V_74 , V_75 ,
V_77 -> V_78 -> V_79 , false , V_76 ) ;
F_38 () ;
if ( V_51 == V_80 ) {
F_8 ( L_4 ) ;
V_51 = V_81 ;
}
return V_51 ;
}
static struct V_82 * F_39 ( struct V_36 * V_37 ,
T_2 V_83 )
{
T_3 V_84 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_37 -> V_10 . V_85 ; V_41 ++ ) {
if ( ! ( V_37 -> V_10 . V_86 [ V_41 ] . V_87 & V_88 ) )
continue;
if ( V_37 -> V_10 . V_86 [ V_41 ] . V_89 & V_90 )
V_84 = V_91 ;
else
V_84 = V_92 ;
if ( ( ( V_37 -> V_10 . V_86 [ V_41 ] . V_87 ^ V_83 ) & V_84 ) == 0 )
return & V_37 -> V_10 . V_86 [ V_41 ] ;
}
return NULL ;
}
static unsigned long F_40 ( unsigned long V_93 , unsigned long V_94 ,
unsigned long V_95 )
{
unsigned long V_96 ;
V_96 = F_41 ( V_93 , V_94 ) - 1 ;
return ( V_94 & V_97 & ~ V_96 ) | ( V_95 & V_96 ) ;
}
static int F_42 ( struct V_36 * V_37 , T_2 V_83 ,
struct V_98 * V_99 , bool V_100 , bool V_101 )
{
struct V_1 * V_1 = V_37 -> V_1 ;
struct V_82 * V_102 ;
unsigned long V_103 ;
unsigned long V_104 , V_105 ;
unsigned long V_93 , V_106 , V_107 ;
T_4 * V_108 ;
int V_109 ;
int V_110 = V_37 -> V_10 . V_69 . V_67 & ( V_100 ? V_111 : V_112 ) ;
if ( V_110 ) {
V_102 = F_39 ( V_37 , V_83 ) ;
if ( ! V_102 )
return - V_64 ;
V_103 = V_102 -> V_89 ;
} else {
V_103 = V_37 -> V_1 -> V_10 . V_113 ;
}
F_43 () ;
V_109 = F_44 ( V_1 , V_83 , V_103 ,
V_114 | V_115 ) ;
if ( V_109 < 0 ) {
F_45 () ;
return - V_116 ;
}
V_108 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_109 << 4 ) ) ;
V_93 = V_106 = F_46 ( V_108 [ 0 ] ) & ~ V_117 ;
if ( F_29 ( V_118 ) )
V_93 = F_47 ( V_93 , F_46 ( V_108 [ 1 ] ) ) ;
V_107 = V_1 -> V_10 . V_24 [ V_109 ] . V_119 ;
F_48 ( V_108 , V_106 ) ;
F_45 () ;
V_99 -> V_83 = V_83 ;
V_99 -> V_120 = ( ( V_93 & V_121 ) << 4 ) | ( ( V_83 >> 12 ) & 0xfff ) ;
V_104 = V_107 & ( V_122 | V_123 ) ;
V_105 = ( V_37 -> V_10 . V_69 . V_67 & V_124 ) ? V_125 : V_126 ;
V_105 &= V_103 ;
V_99 -> V_127 = F_49 ( V_104 , V_105 ) ;
V_99 -> V_128 = F_50 ( V_104 , V_105 ) ;
V_99 -> V_129 = V_99 -> V_127 && ! ( V_107 & ( V_130 | V_131 ) ) ;
if ( V_100 && V_110 ) {
int V_132 = F_51 ( V_107 , V_37 -> V_10 . V_133 ) ;
if ( V_132 & 1 )
V_99 -> V_127 = 0 ;
if ( V_132 & 2 )
V_99 -> V_128 = 0 ;
}
V_99 -> V_134 = F_40 ( V_93 , V_107 , V_83 ) ;
return 0 ;
}
static int F_52 ( unsigned int V_135 )
{
unsigned int V_84 ;
V_84 = 0x10000000 ;
if ( ( V_135 & 0xfc000000 ) == 0x7c000000 )
V_84 = 0x100 ;
return ( V_135 & V_84 ) != 0 ;
}
static int F_53 ( struct V_136 * V_137 , struct V_36 * V_37 ,
unsigned long V_138 , T_2 V_95 , int V_139 )
{
T_1 V_140 ;
if ( F_54 ( V_37 , V_141 , & V_140 ) !=
V_142 )
return V_143 ;
if ( F_52 ( V_140 ) != ! ! V_139 )
return V_143 ;
V_37 -> V_10 . V_144 = V_138 ;
V_37 -> V_10 . V_145 = V_95 ;
return F_55 ( V_137 , V_37 ) ;
}
int F_56 ( struct V_136 * V_137 , struct V_36 * V_37 ,
unsigned long V_95 , unsigned long V_146 )
{
struct V_1 * V_1 = V_37 -> V_1 ;
unsigned long V_147 [ 3 ] , V_94 ;
unsigned long V_148 , V_149 ;
T_4 * V_108 ;
unsigned long V_150 , V_47 , V_151 ;
unsigned long V_152 , V_153 ;
unsigned long V_138 , V_154 , V_155 , V_156 ;
struct V_38 * V_39 ;
unsigned long * V_157 ;
struct V_4 * V_5 ;
struct V_6 * V_6 , * V_158 [ 1 ] ;
long V_109 , V_51 , V_42 ;
bool V_159 ;
unsigned int V_160 , V_161 ;
struct V_162 * V_163 ;
unsigned long V_164 ;
long V_22 ;
if ( V_95 != V_37 -> V_10 . V_165 )
return V_143 ;
if ( V_37 -> V_10 . V_166 ) {
V_22 = F_57 ( & V_1 -> V_10 . V_22 ) ;
if ( V_22 == V_37 -> V_10 . V_166 -> V_22 ) {
V_94 = V_37 -> V_10 . V_166 -> V_167 ;
V_47 = F_41 ( V_37 -> V_10 . V_168 [ 0 ] , V_94 ) ;
V_152 = V_94 & V_97 & ~ ( V_47 - 1 ) ;
V_153 = V_152 >> V_12 ;
V_138 = V_152 | ( V_95 & ( V_47 - 1 ) ) ;
return F_53 ( V_137 , V_37 , V_138 , V_95 ,
V_146 & V_169 ) ;
}
}
V_109 = V_37 -> V_10 . V_170 ;
V_108 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_109 << 4 ) ) ;
V_5 = & V_1 -> V_10 . V_24 [ V_109 ] ;
F_43 () ;
while ( ! F_58 ( V_108 , V_117 ) )
F_59 () ;
V_147 [ 0 ] = F_46 ( V_108 [ 0 ] ) & ~ V_117 ;
V_147 [ 1 ] = F_46 ( V_108 [ 1 ] ) ;
V_147 [ 2 ] = V_94 = V_5 -> V_119 ;
F_48 ( V_108 , V_147 [ 0 ] ) ;
F_45 () ;
if ( F_29 ( V_118 ) ) {
V_147 [ 0 ] = F_47 ( V_147 [ 0 ] , V_147 [ 1 ] ) ;
V_147 [ 1 ] = F_60 ( V_147 [ 1 ] ) ;
}
if ( V_147 [ 0 ] != V_37 -> V_10 . V_168 [ 0 ] ||
V_147 [ 1 ] != V_37 -> V_10 . V_168 [ 1 ] )
return V_143 ;
V_47 = F_41 ( V_147 [ 0 ] , V_94 ) ;
V_152 = V_94 & V_97 & ~ ( V_47 - 1 ) ;
V_153 = V_152 >> V_12 ;
V_138 = V_152 | ( V_95 & ( V_47 - 1 ) ) ;
V_154 = V_138 >> V_12 ;
V_39 = F_61 ( V_1 , V_154 ) ;
F_62 ( V_37 , V_147 , V_39 , V_95 , V_146 ) ;
if ( ! V_39 || ( V_39 -> V_72 & V_171 ) )
return F_53 ( V_137 , V_37 , V_138 , V_95 ,
V_146 & V_169 ) ;
if ( V_153 < V_39 -> V_172 )
return - V_173 ;
V_150 = V_1 -> V_174 ;
F_63 () ;
V_51 = - V_173 ;
V_159 = false ;
V_156 = 0 ;
V_6 = NULL ;
V_151 = V_175 ;
V_160 = ( V_146 & V_169 ) != 0 ;
V_161 = V_160 ;
V_155 = F_64 ( V_39 , V_154 ) ;
V_42 = F_65 ( V_155 , 1 , V_160 , V_158 ) ;
if ( V_42 < 1 ) {
F_66 ( & V_77 -> V_78 -> V_176 ) ;
V_163 = F_67 ( V_77 -> V_78 , V_155 ) ;
if ( V_163 && V_163 -> V_177 <= V_155 && V_155 + V_47 <= V_163 -> V_178 &&
( V_163 -> V_179 & V_180 ) ) {
V_156 = V_163 -> V_181 +
( ( V_155 - V_163 -> V_177 ) >> V_12 ) ;
V_151 = V_47 ;
V_159 = F_68 ( F_69 ( ( F_70 ( V_163 -> V_182 ) ) ) ) ;
V_161 = V_163 -> V_179 & V_183 ;
}
F_71 ( & V_77 -> V_78 -> V_176 ) ;
if ( ! V_156 )
goto V_184;
} else {
V_6 = V_158 [ 0 ] ;
V_156 = F_4 ( V_6 ) ;
if ( F_72 ( V_6 ) ) {
V_6 = F_73 ( V_6 ) ;
V_151 <<= F_74 ( V_6 ) ;
}
if ( ! V_160 && F_75 ( V_94 ) ) {
T_5 * V_185 , V_186 ;
unsigned long V_72 ;
F_76 ( V_72 ) ;
V_185 = F_77 ( V_77 -> V_78 -> V_79 ,
V_155 , NULL , NULL ) ;
if ( V_185 ) {
V_186 = F_78 ( V_185 , 1 ) ;
if ( F_79 ( V_186 ) )
V_161 = 1 ;
}
F_80 ( V_72 ) ;
}
}
if ( V_47 > V_151 )
goto V_184;
if ( ! F_81 ( V_94 , V_159 ) ) {
if ( V_159 )
goto V_184;
V_94 = ( V_94 & ~ ( V_187 | V_188 | V_131 ) ) | V_57 ;
}
if ( V_47 < V_175 )
V_47 = V_175 ;
V_94 = ( V_94 & V_189 ) | ( V_94 & ~ ( V_122 - V_47 ) ) |
( ( V_156 << V_12 ) & ~ ( V_47 - 1 ) ) ;
if ( F_75 ( V_94 ) && ! V_161 )
V_94 = F_82 ( V_94 ) ;
V_51 = V_143 ;
F_43 () ;
while ( ! F_58 ( V_108 , V_117 ) )
F_59 () ;
V_148 = F_46 ( V_108 [ 0 ] ) ;
V_149 = F_46 ( V_108 [ 1 ] ) ;
if ( F_29 ( V_118 ) ) {
V_148 = F_47 ( V_148 , V_149 ) ;
V_149 = F_60 ( V_149 ) ;
}
if ( ( V_148 & ~ V_117 ) != V_147 [ 0 ] || V_149 != V_147 [ 1 ] ||
V_5 -> V_119 != V_147 [ 2 ] )
goto V_190;
V_147 [ 0 ] = ( V_147 [ 0 ] & ~ V_115 ) | V_114 ;
V_157 = & V_39 -> V_10 . V_157 [ V_153 - V_39 -> V_172 ] ;
F_83 ( V_157 ) ;
V_51 = V_143 ;
if ( F_84 ( V_37 -> V_1 , V_150 ) ) {
F_85 ( V_157 ) ;
goto V_190;
}
V_164 = * V_157 >> V_191 ;
V_94 &= V_164 | ~ ( V_55 | V_56 ) ;
if ( F_46 ( V_108 [ 0 ] ) & V_114 ) {
F_85 ( V_157 ) ;
V_108 [ 0 ] |= F_86 ( V_115 ) ;
F_87 ( V_1 , V_108 , V_109 ) ;
V_94 |= F_46 ( V_108 [ 1 ] ) & ( V_55 | V_56 ) ;
} else {
F_88 ( V_1 , V_5 , V_157 , V_109 , 0 ) ;
}
if ( F_29 ( V_118 ) ) {
V_94 = F_89 ( V_147 [ 0 ] , V_94 ) ;
V_147 [ 0 ] = F_90 ( V_147 [ 0 ] ) ;
}
V_108 [ 1 ] = F_86 ( V_94 ) ;
F_91 () ;
F_92 ( V_108 , V_147 [ 0 ] ) ;
asm volatile("ptesync" : : : "memory");
F_45 () ;
if ( V_6 && F_75 ( V_94 ) )
F_93 ( V_6 ) ;
V_184:
F_94 ( V_37 , V_147 , V_51 ) ;
if ( V_6 ) {
F_95 ( V_158 [ 0 ] ) ;
}
return V_51 ;
V_190:
F_92 ( V_108 , F_46 ( V_108 [ 0 ] ) ) ;
F_45 () ;
goto V_184;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_192 * V_193 ;
struct V_38 * V_39 ;
int V_194 ;
V_194 = F_96 ( & V_1 -> V_195 ) ;
V_193 = V_192 ( V_1 ) ;
F_97 (memslot, slots) {
memset ( V_39 -> V_10 . V_157 , 0 ,
V_39 -> V_42 * sizeof( * V_39 -> V_10 . V_157 ) ) ;
}
F_98 ( & V_1 -> V_195 , V_194 ) ;
}
static int F_99 ( struct V_1 * V_1 ,
unsigned long V_196 ,
unsigned long V_197 ,
int (* F_100)( struct V_1 * V_1 ,
unsigned long * V_198 ,
unsigned long V_154 ) )
{
int V_51 ;
int V_199 = 0 ;
struct V_192 * V_193 ;
struct V_38 * V_39 ;
V_193 = V_192 ( V_1 ) ;
F_97 (memslot, slots) {
unsigned long V_200 , V_201 ;
T_6 V_154 , V_202 ;
V_200 = F_101 ( V_196 , V_39 -> V_203 ) ;
V_201 = F_102 ( V_197 , V_39 -> V_203 +
( V_39 -> V_42 << V_12 ) ) ;
if ( V_200 >= V_201 )
continue;
V_154 = F_103 ( V_200 , V_39 ) ;
V_202 = F_103 ( V_201 + V_175 - 1 , V_39 ) ;
for (; V_154 < V_202 ; ++ V_154 ) {
T_6 V_204 = V_154 - V_39 -> V_172 ;
V_51 = F_100 ( V_1 , & V_39 -> V_10 . V_157 [ V_204 ] , V_154 ) ;
V_199 |= V_51 ;
}
}
return V_199 ;
}
static int F_104 ( struct V_1 * V_1 , unsigned long V_155 ,
int (* F_100)( struct V_1 * V_1 , unsigned long * V_198 ,
unsigned long V_154 ) )
{
return F_99 ( V_1 , V_155 , V_155 + 1 , F_100 ) ;
}
static int F_105 ( struct V_1 * V_1 , unsigned long * V_198 ,
unsigned long V_154 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_205 , V_41 , V_206 ;
T_4 * V_108 ;
unsigned long V_75 , V_47 , V_164 ;
for (; ; ) {
F_83 ( V_198 ) ;
if ( ! ( * V_198 & V_207 ) ) {
F_85 ( V_198 ) ;
break;
}
V_41 = * V_198 & V_208 ;
V_108 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_41 << 4 ) ) ;
if ( ! F_58 ( V_108 , V_117 ) ) {
F_85 ( V_198 ) ;
while ( F_46 ( V_108 [ 0 ] ) & V_117 )
F_59 () ;
continue;
}
V_206 = V_5 [ V_41 ] . V_209 ;
if ( V_206 == V_41 ) {
* V_198 &= ~ ( V_207 | V_208 ) ;
} else {
V_205 = V_5 [ V_41 ] . V_210 ;
V_5 [ V_205 ] . V_209 = V_206 ;
V_5 [ V_206 ] . V_210 = V_205 ;
V_5 [ V_41 ] . V_209 = V_5 [ V_41 ] . V_210 = V_41 ;
* V_198 = ( * V_198 & ~ V_208 ) | V_206 ;
}
V_75 = V_5 [ V_41 ] . V_119 ;
V_47 = F_41 ( F_46 ( V_108 [ 0 ] ) , V_75 ) ;
if ( ( F_46 ( V_108 [ 0 ] ) & V_114 ) &&
F_106 ( V_75 , V_47 ) == V_154 ) {
V_108 [ 0 ] |= F_86 ( V_115 ) ;
F_87 ( V_1 , V_108 , V_41 ) ;
V_108 [ 1 ] &= ~ F_86 ( V_189 | V_211 ) ;
V_164 = F_46 ( V_108 [ 1 ] ) & ( V_55 | V_56 ) ;
* V_198 |= V_164 << V_191 ;
if ( V_164 & V_56 )
F_107 ( V_198 , V_47 ) ;
if ( V_164 & ~ V_5 [ V_41 ] . V_119 ) {
V_5 [ V_41 ] . V_119 = V_75 | V_164 ;
F_108 ( V_1 , & V_5 [ V_41 ] ) ;
}
}
F_85 ( V_198 ) ;
F_92 ( V_108 , F_46 ( V_108 [ 0 ] ) ) ;
}
return 0 ;
}
int F_109 ( struct V_1 * V_1 , unsigned long V_155 )
{
F_104 ( V_1 , V_155 , F_105 ) ;
return 0 ;
}
int F_110 ( struct V_1 * V_1 , unsigned long V_196 , unsigned long V_197 )
{
F_99 ( V_1 , V_196 , V_197 , F_105 ) ;
return 0 ;
}
void F_111 ( struct V_1 * V_1 ,
struct V_38 * V_39 )
{
unsigned long * V_198 ;
unsigned long V_154 ;
unsigned long V_212 ;
V_198 = V_39 -> V_10 . V_157 ;
V_154 = V_39 -> V_172 ;
for ( V_212 = V_39 -> V_42 ; V_212 ; -- V_212 ) {
if ( * V_198 & V_207 )
F_105 ( V_1 , V_198 , V_154 ) ;
++ V_198 ;
++ V_154 ;
}
}
static int F_112 ( struct V_1 * V_1 , unsigned long * V_198 ,
unsigned long V_154 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_213 , V_41 , V_206 ;
T_4 * V_108 ;
int V_51 = 0 ;
V_214:
F_83 ( V_198 ) ;
if ( * V_198 & V_215 ) {
* V_198 &= ~ V_215 ;
V_51 = 1 ;
}
if ( ! ( * V_198 & V_207 ) ) {
F_85 ( V_198 ) ;
return V_51 ;
}
V_41 = V_213 = * V_198 & V_208 ;
do {
V_108 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_41 << 4 ) ) ;
V_206 = V_5 [ V_41 ] . V_209 ;
if ( ! ( F_46 ( V_108 [ 1 ] ) & V_55 ) )
continue;
if ( ! F_58 ( V_108 , V_117 ) ) {
F_85 ( V_198 ) ;
while ( F_46 ( V_108 [ 0 ] ) & V_117 )
F_59 () ;
goto V_214;
}
if ( ( F_46 ( V_108 [ 0 ] ) & V_114 ) &&
( F_46 ( V_108 [ 1 ] ) & V_55 ) ) {
F_113 ( V_1 , V_108 , V_41 ) ;
if ( ! ( V_5 [ V_41 ] . V_119 & V_55 ) ) {
V_5 [ V_41 ] . V_119 |= V_55 ;
F_108 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_51 = 1 ;
}
F_92 ( V_108 , F_46 ( V_108 [ 0 ] ) ) ;
} while ( ( V_41 = V_206 ) != V_213 );
F_85 ( V_198 ) ;
return V_51 ;
}
int F_114 ( struct V_1 * V_1 , unsigned long V_196 , unsigned long V_197 )
{
return F_99 ( V_1 , V_196 , V_197 , F_112 ) ;
}
static int F_115 ( struct V_1 * V_1 , unsigned long * V_198 ,
unsigned long V_154 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_213 , V_41 , V_206 ;
unsigned long * V_216 ;
int V_51 = 1 ;
if ( * V_198 & V_215 )
return 1 ;
F_83 ( V_198 ) ;
if ( * V_198 & V_215 )
goto V_32;
if ( * V_198 & V_207 ) {
V_41 = V_213 = * V_198 & V_208 ;
do {
V_216 = ( unsigned long * ) ( V_1 -> V_10 . V_18 + ( V_41 << 4 ) ) ;
V_206 = V_5 [ V_41 ] . V_209 ;
if ( F_46 ( V_216 [ 1 ] ) & V_55 )
goto V_32;
} while ( ( V_41 = V_206 ) != V_213 );
}
V_51 = 0 ;
V_32:
F_85 ( V_198 ) ;
return V_51 ;
}
int F_116 ( struct V_1 * V_1 , unsigned long V_155 )
{
return F_104 ( V_1 , V_155 , F_115 ) ;
}
void F_117 ( struct V_1 * V_1 , unsigned long V_155 , T_5 V_186 )
{
F_104 ( V_1 , V_155 , F_105 ) ;
}
static int V_31 ( struct V_1 * V_1 )
{
return F_16 ( & V_1 -> V_10 . V_31 ) != 0 ;
}
static int F_118 ( struct V_1 * V_1 , unsigned long * V_198 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_24 ;
unsigned long V_213 , V_41 , V_206 ;
unsigned long V_212 ;
unsigned long V_93 , V_94 ;
T_4 * V_108 ;
int V_217 = 0 ;
V_214:
F_83 ( V_198 ) ;
if ( * V_198 & V_218 ) {
long V_219 = ( * V_198 & V_220 )
>> V_221 ;
* V_198 &= ~ ( V_218 | V_220 ) ;
V_217 = 1 ;
if ( V_219 > V_12 )
V_217 = 1ul << ( V_219 - V_12 ) ;
}
if ( ! ( * V_198 & V_207 ) ) {
F_85 ( V_198 ) ;
return V_217 ;
}
V_41 = V_213 = * V_198 & V_208 ;
do {
unsigned long V_222 ;
V_108 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_41 << 4 ) ) ;
V_206 = V_5 [ V_41 ] . V_209 ;
V_222 = F_46 ( V_108 [ 1 ] ) ;
if ( ! ( V_222 & V_56 ) &&
( ! F_75 ( V_222 ) || V_31 ( V_1 ) ) )
continue;
if ( ! F_58 ( V_108 , V_117 ) ) {
F_85 ( V_198 ) ;
while ( V_108 [ 0 ] & F_86 ( V_117 ) )
F_59 () ;
goto V_214;
}
if ( ! ( V_108 [ 0 ] & F_86 ( V_114 ) ) ) {
F_92 ( V_108 , F_46 ( V_108 [ 0 ] ) ) ;
continue;
}
V_108 [ 0 ] |= F_86 ( V_115 ) ;
F_87 ( V_1 , V_108 , V_41 ) ;
V_93 = F_46 ( V_108 [ 0 ] ) ;
V_94 = F_46 ( V_108 [ 1 ] ) ;
if ( V_94 & V_56 ) {
V_108 [ 1 ] = F_86 ( V_94 & ~ V_56 ) ;
if ( ! ( V_5 [ V_41 ] . V_119 & V_56 ) ) {
V_5 [ V_41 ] . V_119 |= V_56 ;
F_108 ( V_1 , & V_5 [ V_41 ] ) ;
}
V_212 = F_41 ( V_93 , V_94 ) ;
V_212 = ( V_212 + V_175 - 1 ) >> V_12 ;
if ( V_212 > V_217 )
V_217 = V_212 ;
F_91 () ;
}
V_93 &= ~ V_115 ;
V_93 |= V_114 ;
F_92 ( V_108 , V_93 ) ;
} while ( ( V_41 = V_206 ) != V_213 );
F_85 ( V_198 ) ;
return V_217 ;
}
static void F_119 ( struct V_223 * V_224 ,
struct V_38 * V_39 ,
unsigned long * V_225 )
{
unsigned long V_154 ;
if ( ! V_224 -> V_226 || ! V_224 -> V_227 )
return;
V_154 = V_224 -> V_138 >> V_12 ;
if ( V_154 < V_39 -> V_172 ||
V_154 >= V_39 -> V_172 + V_39 -> V_42 )
return;
V_224 -> V_226 = false ;
if ( V_225 )
F_120 ( V_154 - V_39 -> V_172 , V_225 ) ;
}
long F_121 ( struct V_1 * V_1 , struct V_38 * V_39 ,
unsigned long * V_225 )
{
unsigned long V_41 , V_206 ;
unsigned long * V_198 ;
struct V_36 * V_37 ;
F_43 () ;
V_198 = V_39 -> V_10 . V_157 ;
for ( V_41 = 0 ; V_41 < V_39 -> V_42 ; ++ V_41 ) {
int V_42 = F_118 ( V_1 , V_198 ) ;
if ( V_42 && V_225 )
for ( V_206 = V_41 ; V_42 ; ++ V_206 , -- V_42 )
F_120 ( V_206 , V_225 ) ;
++ V_198 ;
}
F_122 (i, vcpu, kvm) {
F_123 ( & V_37 -> V_10 . V_228 ) ;
F_119 ( & V_37 -> V_10 . V_224 , V_39 , V_225 ) ;
F_119 ( & V_37 -> V_10 . V_229 , V_39 , V_225 ) ;
F_124 ( & V_37 -> V_10 . V_228 ) ;
}
F_45 () ;
return 0 ;
}
void * F_125 ( struct V_1 * V_1 , unsigned long V_138 ,
unsigned long * V_230 )
{
struct V_38 * V_39 ;
unsigned long V_154 = V_138 >> V_12 ;
struct V_6 * V_6 , * V_158 [ 1 ] ;
int V_42 ;
unsigned long V_155 , V_231 ;
int V_194 ;
V_194 = F_96 ( & V_1 -> V_195 ) ;
V_39 = F_61 ( V_1 , V_154 ) ;
if ( ! V_39 || ( V_39 -> V_72 & V_171 ) )
goto V_27;
V_155 = F_64 ( V_39 , V_154 ) ;
V_42 = F_65 ( V_155 , 1 , 1 , V_158 ) ;
if ( V_42 < 1 )
goto V_27;
V_6 = V_158 [ 0 ] ;
F_98 ( & V_1 -> V_195 , V_194 ) ;
V_231 = V_138 & ( V_175 - 1 ) ;
if ( V_230 )
* V_230 = V_175 - V_231 ;
return F_126 ( V_6 ) + V_231 ;
V_27:
F_98 ( & V_1 -> V_195 , V_194 ) ;
return NULL ;
}
void F_127 ( struct V_1 * V_1 , void * V_232 , unsigned long V_138 ,
bool V_226 )
{
struct V_6 * V_6 = F_23 ( V_232 ) ;
struct V_38 * V_39 ;
unsigned long V_154 ;
unsigned long * V_157 ;
int V_194 ;
F_95 ( V_6 ) ;
if ( ! V_226 )
return;
V_154 = V_138 >> V_12 ;
V_194 = F_96 ( & V_1 -> V_195 ) ;
V_39 = F_61 ( V_1 , V_154 ) ;
if ( V_39 ) {
V_157 = & V_39 -> V_10 . V_157 [ V_154 - V_39 -> V_172 ] ;
F_83 ( V_157 ) ;
* V_157 |= V_218 ;
F_85 ( V_157 ) ;
}
F_98 ( & V_1 -> V_195 , V_194 ) ;
}
static int F_128 ( struct V_4 * V_233 , T_4 * V_234 )
{
unsigned long V_235 ;
if ( V_233 -> V_119 & V_236 )
return 1 ;
V_235 = ~ V_233 -> V_119 & ( V_55 | V_56 ) ;
if ( ( F_46 ( V_234 [ 0 ] ) & V_114 ) &&
( F_46 ( V_234 [ 1 ] ) & V_235 ) )
return 1 ;
return 0 ;
}
static long F_129 ( unsigned long V_72 , T_4 * V_234 ,
unsigned long * V_147 , struct V_4 * V_233 ,
int V_237 , int V_238 )
{
unsigned long V_93 , V_94 , V_239 ;
unsigned long V_235 ;
int V_240 = 1 ;
int V_241 , V_226 ;
V_226 = F_128 ( V_233 , V_234 ) ;
if ( ! V_238 && ! V_226 )
return 0 ;
V_241 = 0 ;
if ( F_46 ( V_234 [ 0 ] ) & ( V_114 | V_115 ) ) {
V_241 = 1 ;
if ( ( V_72 & V_242 ) &&
! ( F_46 ( V_234 [ 0 ] ) & V_54 ) )
V_241 = 0 ;
}
if ( V_241 != V_237 )
return 0 ;
V_93 = V_94 = 0 ;
if ( V_241 || V_226 ) {
F_43 () ;
while ( ! F_58 ( V_234 , V_117 ) )
F_59 () ;
V_93 = F_46 ( V_234 [ 0 ] ) ;
V_239 = F_46 ( V_234 [ 1 ] ) ;
if ( F_29 ( V_118 ) ) {
V_93 = F_47 ( V_93 , V_239 ) ;
V_239 = F_60 ( V_239 ) ;
}
V_241 = ! ! ( V_93 & V_114 ) ;
V_226 = ! ! ( V_233 -> V_119 & V_236 ) ;
V_235 = ~ V_233 -> V_119 & ( V_55 | V_56 ) ;
if ( V_241 && ( V_235 & V_239 ) ) {
V_233 -> V_119 |= ( V_239 &
( V_55 | V_56 ) ) | V_236 ;
V_226 = 1 ;
}
if ( V_93 & V_115 ) {
V_93 &= ~ V_115 ;
V_93 |= V_114 ;
V_241 = 1 ;
}
if ( ( V_72 & V_242 ) && ! ( V_93 & V_54 ) )
V_241 = 0 ;
V_94 = V_233 -> V_119 ;
if ( V_241 == V_237 && V_226 ) {
V_94 &= ~ V_236 ;
V_233 -> V_119 = V_94 ;
}
F_48 ( V_234 , F_46 ( V_234 [ 0 ] ) ) ;
F_45 () ;
if ( ! ( V_241 == V_237 && ( V_238 || V_226 ) ) )
V_240 = 0 ;
}
V_147 [ 0 ] = F_86 ( V_93 ) ;
V_147 [ 1 ] = F_86 ( V_94 ) ;
return V_240 ;
}
static T_7 F_130 ( struct V_243 * V_243 , char T_8 * V_244 ,
T_9 V_245 , T_10 * V_246 )
{
struct V_247 * V_248 = V_243 -> V_249 ;
struct V_1 * V_1 = V_248 -> V_1 ;
struct V_250 V_251 ;
T_4 * V_234 ;
struct V_4 * V_233 ;
unsigned long V_41 , V_252 , V_253 ;
unsigned long T_8 * V_254 ;
struct V_250 T_8 * V_255 ;
unsigned long V_72 ;
int V_238 ;
unsigned long V_147 [ 2 ] ;
if ( ! F_131 ( V_256 , V_244 , V_245 ) )
return - V_173 ;
V_238 = V_248 -> V_238 ;
V_72 = V_248 -> V_72 ;
V_41 = V_248 -> V_109 ;
V_234 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_41 * V_257 ) ) ;
V_233 = V_1 -> V_10 . V_24 + V_41 ;
V_254 = ( unsigned long T_8 * ) V_244 ;
V_252 = 0 ;
while ( V_252 + sizeof( V_251 ) + V_257 < V_245 ) {
V_255 = (struct V_250 T_8 * ) V_244 ;
V_251 . V_258 = 0 ;
V_251 . V_259 = 0 ;
V_253 = V_252 ;
V_252 += sizeof( V_251 ) ;
V_254 = ( unsigned long T_8 * ) ( V_244 + sizeof( V_251 ) ) ;
if ( ! V_238 ) {
while ( V_41 < V_1 -> V_10 . V_20 &&
! F_128 ( V_233 , V_234 ) ) {
++ V_41 ;
V_234 += 2 ;
++ V_233 ;
}
}
V_251 . V_109 = V_41 ;
while ( V_41 < V_1 -> V_10 . V_20 &&
V_251 . V_258 < 0xffff &&
V_252 + V_257 < V_245 &&
F_129 ( V_72 , V_234 , V_147 , V_233 , 1 , V_238 ) ) {
++ V_251 . V_258 ;
if ( F_132 ( V_147 [ 0 ] , V_254 ) ||
F_132 ( V_147 [ 1 ] , V_254 + 1 ) )
return - V_173 ;
V_252 += V_257 ;
V_254 += 2 ;
++ V_41 ;
V_234 += 2 ;
++ V_233 ;
}
while ( V_41 < V_1 -> V_10 . V_20 &&
V_251 . V_259 < 0xffff &&
F_129 ( V_72 , V_234 , V_147 , V_233 , 0 , V_238 ) ) {
++ V_251 . V_259 ;
++ V_41 ;
V_234 += 2 ;
++ V_233 ;
}
if ( V_251 . V_258 || V_251 . V_259 ) {
if ( F_133 ( V_255 , & V_251 , sizeof( V_251 ) ) )
return - V_173 ;
V_253 = V_252 ;
V_244 = ( char T_8 * ) V_254 ;
} else {
V_252 = V_253 ;
}
if ( V_41 >= V_1 -> V_10 . V_20 ) {
V_41 = 0 ;
V_248 -> V_238 = 0 ;
break;
}
}
V_248 -> V_109 = V_41 ;
return V_252 ;
}
static T_7 F_134 ( struct V_243 * V_243 , const char T_8 * V_244 ,
T_9 V_245 , T_10 * V_246 )
{
struct V_247 * V_248 = V_243 -> V_249 ;
struct V_1 * V_1 = V_248 -> V_1 ;
struct V_250 V_251 ;
unsigned long V_41 , V_206 ;
unsigned long V_93 , V_94 ;
unsigned long T_8 * V_254 ;
T_4 * V_234 ;
unsigned long V_260 [ 2 ] ;
T_7 V_252 ;
long int V_27 , V_51 ;
int V_261 ;
if ( ! F_131 ( V_262 , V_244 , V_245 ) )
return - V_173 ;
F_14 ( & V_1 -> V_29 ) ;
V_261 = V_1 -> V_10 . V_30 ;
if ( V_261 ) {
V_1 -> V_10 . V_30 = 0 ;
F_15 () ;
if ( F_16 ( & V_1 -> V_10 . V_31 ) ) {
V_1 -> V_10 . V_30 = 1 ;
F_19 ( & V_1 -> V_29 ) ;
return - V_28 ;
}
}
V_27 = 0 ;
for ( V_252 = 0 ; V_252 + sizeof( V_251 ) <= V_245 ; ) {
V_27 = - V_173 ;
if ( F_135 ( & V_251 , V_244 , sizeof( V_251 ) ) )
break;
V_27 = 0 ;
if ( V_252 + V_251 . V_258 * V_257 > V_245 )
break;
V_252 += sizeof( V_251 ) ;
V_244 += sizeof( V_251 ) ;
V_27 = - V_64 ;
V_41 = V_251 . V_109 ;
if ( V_41 >= V_1 -> V_10 . V_20 ||
V_41 + V_251 . V_258 + V_251 . V_259 > V_1 -> V_10 . V_20 )
break;
V_234 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_41 * V_257 ) ) ;
V_254 = ( unsigned long T_8 * ) V_244 ;
for ( V_206 = 0 ; V_206 < V_251 . V_258 ; ++ V_206 ) {
T_4 V_263 ;
T_4 V_264 ;
V_27 = - V_173 ;
if ( F_136 ( V_263 , V_254 ) ||
F_136 ( V_264 , V_254 + 1 ) )
goto V_32;
V_93 = F_46 ( V_263 ) ;
V_94 = F_46 ( V_264 ) ;
V_27 = - V_64 ;
if ( ! ( V_93 & V_114 ) )
goto V_32;
V_254 += 2 ;
V_252 += V_257 ;
if ( F_46 ( V_234 [ 0 ] ) & ( V_114 | V_115 ) )
F_137 ( V_1 , 0 , V_41 , 0 , V_260 ) ;
V_27 = - V_265 ;
V_51 = F_27 ( V_1 , V_59 , V_41 , V_93 , V_94 ,
V_260 ) ;
if ( V_51 != V_60 ) {
F_8 ( L_5
L_6 , V_51 , V_41 , V_93 , V_94 ) ;
goto V_32;
}
if ( ! V_261 && F_138 ( V_93 ) ) {
unsigned long V_47 = F_139 ( V_93 , V_94 ) ;
unsigned long V_266 = F_140 ( V_47 ) ;
unsigned long V_267 ;
V_1 -> V_10 . V_113 = V_266 | V_90 |
( V_53 << V_268 ) ;
V_267 = V_266 << ( V_269 - 4 ) ;
F_141 ( V_1 , V_267 , V_270 ) ;
V_261 = 1 ;
}
++ V_41 ;
V_234 += 2 ;
}
for ( V_206 = 0 ; V_206 < V_251 . V_259 ; ++ V_206 ) {
if ( F_46 ( V_234 [ 0 ] ) & ( V_114 | V_115 ) )
F_137 ( V_1 , 0 , V_41 , 0 , V_260 ) ;
++ V_41 ;
V_234 += 2 ;
}
V_27 = 0 ;
}
V_32:
F_142 () ;
V_1 -> V_10 . V_30 = V_261 ;
F_19 ( & V_1 -> V_29 ) ;
if ( V_27 )
return V_27 ;
return V_252 ;
}
static int F_143 ( struct V_271 * V_271 , struct V_243 * V_272 )
{
struct V_247 * V_248 = V_272 -> V_249 ;
V_272 -> V_249 = NULL ;
if ( ! ( V_248 -> V_72 & V_273 ) )
F_144 ( & V_248 -> V_1 -> V_10 . V_274 ) ;
F_145 ( V_248 -> V_1 ) ;
F_146 ( V_248 ) ;
return 0 ;
}
int F_147 ( struct V_1 * V_1 , struct V_275 * V_276 )
{
int V_51 ;
struct V_247 * V_248 ;
int V_277 ;
if ( V_276 -> V_72 & ~ ( V_242 | V_273 ) )
return - V_64 ;
V_248 = F_148 ( sizeof( * V_248 ) , V_13 ) ;
if ( ! V_248 )
return - V_17 ;
F_149 ( V_1 ) ;
V_248 -> V_1 = V_1 ;
V_248 -> V_109 = V_276 -> V_278 ;
V_248 -> V_72 = V_276 -> V_72 ;
V_248 -> V_238 = 1 ;
V_277 = ( V_276 -> V_72 & V_273 ) ? V_279 : V_280 ;
V_51 = F_150 ( L_7 , & V_281 , V_248 , V_277 | V_282 ) ;
if ( V_51 < 0 ) {
F_145 ( V_1 ) ;
return V_51 ;
}
if ( V_277 == V_280 ) {
F_14 ( & V_1 -> V_283 ) ;
F_151 ( & V_1 -> V_10 . V_274 ) ;
F_152 ( & V_1 -> V_195 ) ;
F_19 ( & V_1 -> V_283 ) ;
}
return V_51 ;
}
static int F_153 ( struct V_271 * V_271 , struct V_243 * V_243 )
{
struct V_1 * V_1 = V_271 -> V_284 ;
struct V_285 * V_286 ;
V_286 = F_148 ( sizeof( * V_286 ) , V_13 ) ;
if ( ! V_286 )
return - V_17 ;
F_149 ( V_1 ) ;
V_286 -> V_1 = V_1 ;
F_154 ( & V_286 -> V_287 ) ;
V_243 -> V_249 = V_286 ;
return F_155 ( V_271 , V_243 ) ;
}
static int F_156 ( struct V_271 * V_271 , struct V_243 * V_243 )
{
struct V_285 * V_286 = V_243 -> V_249 ;
F_145 ( V_286 -> V_1 ) ;
F_146 ( V_286 ) ;
return 0 ;
}
static T_7 F_157 ( struct V_243 * V_243 , char T_8 * V_244 ,
T_9 V_288 , T_10 * V_246 )
{
struct V_285 * V_286 = V_243 -> V_249 ;
T_7 V_51 , V_94 ;
unsigned long V_41 , V_212 ;
unsigned long V_93 , V_239 , V_107 ;
struct V_1 * V_1 ;
T_4 * V_234 ;
V_51 = F_158 ( & V_286 -> V_287 ) ;
if ( V_51 )
return V_51 ;
if ( V_286 -> V_289 ) {
V_212 = V_286 -> V_289 ;
if ( V_212 > V_288 )
V_212 = V_288 ;
V_94 = F_159 ( V_244 , V_286 -> V_244 + V_286 -> V_290 , V_212 ) ;
V_212 -= V_94 ;
V_286 -> V_289 -= V_212 ;
V_286 -> V_290 += V_212 ;
V_244 += V_212 ;
V_288 -= V_212 ;
V_51 = V_212 ;
if ( V_94 ) {
if ( ! V_212 )
V_51 = - V_173 ;
goto V_32;
}
}
V_1 = V_286 -> V_1 ;
V_41 = V_286 -> V_291 ;
V_234 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_41 * V_257 ) ) ;
for (; V_288 != 0 && V_41 < V_1 -> V_10 . V_20 ; ++ V_41 , V_234 += 2 ) {
if ( ! ( F_46 ( V_234 [ 0 ] ) & ( V_114 | V_115 ) ) )
continue;
F_43 () ;
while ( ! F_58 ( V_234 , V_117 ) )
F_59 () ;
V_93 = F_46 ( V_234 [ 0 ] ) & ~ V_117 ;
V_239 = F_46 ( V_234 [ 1 ] ) ;
V_107 = V_1 -> V_10 . V_24 [ V_41 ] . V_119 ;
F_48 ( V_234 , V_93 ) ;
F_45 () ;
if ( ! ( V_93 & ( V_114 | V_115 ) ) )
continue;
V_212 = F_160 ( V_286 -> V_244 , sizeof( V_286 -> V_244 ) ,
L_8 ,
V_41 , V_93 , V_239 , V_107 ) ;
V_286 -> V_289 = V_212 ;
if ( V_212 > V_288 )
V_212 = V_288 ;
V_94 = F_159 ( V_244 , V_286 -> V_244 , V_212 ) ;
V_212 -= V_94 ;
V_286 -> V_289 -= V_212 ;
V_286 -> V_290 = V_212 ;
V_244 += V_212 ;
V_288 -= V_212 ;
V_51 += V_212 ;
if ( V_94 ) {
if ( ! V_51 )
V_51 = - V_173 ;
goto V_32;
}
}
V_286 -> V_291 = V_41 ;
V_32:
F_19 ( & V_286 -> V_287 ) ;
return V_51 ;
}
static T_7 F_161 ( struct V_243 * V_243 , const char T_8 * V_244 ,
T_9 V_288 , T_10 * V_246 )
{
return - V_292 ;
}
void F_162 ( struct V_1 * V_1 )
{
V_1 -> V_10 . V_293 = F_163 ( L_9 , 0400 ,
V_1 -> V_10 . V_294 , V_1 ,
& V_295 ) ;
}
void F_164 ( struct V_36 * V_37 )
{
struct V_296 * V_297 = & V_37 -> V_10 . V_297 ;
V_37 -> V_10 . V_85 = 32 ;
V_297 -> V_298 = F_42 ;
V_297 -> V_299 = F_33 ;
V_37 -> V_10 . V_300 |= V_301 ;
}
