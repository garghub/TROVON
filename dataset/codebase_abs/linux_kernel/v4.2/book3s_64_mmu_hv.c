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
V_60 = F_29 ( V_64 ) ;
V_61 = V_65 ;
F_30 ( V_61 + 1 ) ;
F_31 ( V_60 ) ;
F_31 ( V_61 ) ;
return 0 ;
}
static void F_32 ( struct V_35 * V_36 )
{
unsigned long V_66 = V_36 -> V_10 . V_67 ;
if ( F_33 ( V_36 -> V_10 . V_68 . V_66 ) )
V_66 |= V_69 ;
else
V_66 |= V_36 -> V_10 . V_68 . V_66 & V_70 ;
F_34 ( V_36 , V_66 ) ;
}
long F_26 ( struct V_1 * V_1 , unsigned long V_71 ,
long V_72 , unsigned long V_73 ,
unsigned long V_74 , unsigned long * V_75 )
{
long V_50 ;
F_35 () ;
V_50 = F_36 ( V_1 , V_71 , V_72 , V_73 , V_74 ,
V_76 -> V_77 -> V_78 , false , V_75 ) ;
F_37 () ;
if ( V_50 == V_79 ) {
F_7 ( L_4 ) ;
V_50 = V_80 ;
}
return V_50 ;
}
static struct V_81 * F_38 ( struct V_35 * V_36 ,
T_2 V_82 )
{
T_3 V_83 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_36 -> V_10 . V_84 ; V_40 ++ ) {
if ( ! ( V_36 -> V_10 . V_85 [ V_40 ] . V_86 & V_87 ) )
continue;
if ( V_36 -> V_10 . V_85 [ V_40 ] . V_88 & V_89 )
V_83 = V_90 ;
else
V_83 = V_91 ;
if ( ( ( V_36 -> V_10 . V_85 [ V_40 ] . V_86 ^ V_82 ) & V_83 ) == 0 )
return & V_36 -> V_10 . V_85 [ V_40 ] ;
}
return NULL ;
}
static unsigned long F_39 ( unsigned long V_92 , unsigned long V_93 ,
unsigned long V_94 )
{
unsigned long V_95 ;
V_95 = F_40 ( V_92 , V_93 ) - 1 ;
return ( V_93 & V_96 & ~ V_95 ) | ( V_94 & V_95 ) ;
}
static int F_41 ( struct V_35 * V_36 , T_2 V_82 ,
struct V_97 * V_98 , bool V_99 , bool V_100 )
{
struct V_1 * V_1 = V_36 -> V_1 ;
struct V_81 * V_101 ;
unsigned long V_102 ;
unsigned long V_103 , V_104 ;
unsigned long V_92 , V_105 ;
T_4 * V_106 ;
int V_107 ;
int V_108 = V_36 -> V_10 . V_68 . V_66 & ( V_99 ? V_109 : V_110 ) ;
if ( V_108 ) {
V_101 = F_38 ( V_36 , V_82 ) ;
if ( ! V_101 )
return - V_63 ;
V_102 = V_101 -> V_88 ;
} else {
V_102 = V_36 -> V_1 -> V_10 . V_111 ;
}
F_42 () ;
V_107 = F_43 ( V_1 , V_82 , V_102 ,
V_112 | V_113 ) ;
if ( V_107 < 0 ) {
F_44 () ;
return - V_114 ;
}
V_106 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_107 << 4 ) ) ;
V_92 = F_45 ( V_106 [ 0 ] ) & ~ V_115 ;
V_105 = V_1 -> V_10 . V_23 [ V_107 ] . V_116 ;
F_46 ( V_106 , V_92 ) ;
F_44 () ;
V_98 -> V_82 = V_82 ;
V_98 -> V_117 = ( ( V_92 & V_118 ) << 4 ) | ( ( V_82 >> 12 ) & 0xfff ) ;
V_103 = V_105 & ( V_119 | V_120 ) ;
V_104 = ( V_36 -> V_10 . V_68 . V_66 & V_121 ) ? V_122 : V_123 ;
V_104 &= V_102 ;
V_98 -> V_124 = F_47 ( V_103 , V_104 ) ;
V_98 -> V_125 = F_48 ( V_103 , V_104 ) ;
V_98 -> V_126 = V_98 -> V_124 && ! ( V_105 & ( V_127 | V_128 ) ) ;
if ( V_99 && V_108 ) {
int V_129 = F_49 ( V_105 , V_36 -> V_10 . V_130 ) ;
if ( V_129 & 1 )
V_98 -> V_124 = 0 ;
if ( V_129 & 2 )
V_98 -> V_125 = 0 ;
}
V_98 -> V_131 = F_39 ( V_92 , V_105 , V_82 ) ;
return 0 ;
}
static int F_50 ( unsigned int V_132 )
{
unsigned int V_83 ;
V_83 = 0x10000000 ;
if ( ( V_132 & 0xfc000000 ) == 0x7c000000 )
V_83 = 0x100 ;
return ( V_132 & V_83 ) != 0 ;
}
static int F_51 ( struct V_133 * V_134 , struct V_35 * V_36 ,
unsigned long V_135 , T_2 V_94 , int V_136 )
{
T_1 V_137 ;
if ( F_52 ( V_36 , V_138 , & V_137 ) !=
V_139 )
return V_140 ;
if ( F_50 ( V_137 ) != ! ! V_136 )
return V_140 ;
V_36 -> V_10 . V_141 = V_135 ;
V_36 -> V_10 . V_142 = V_94 ;
return F_53 ( V_134 , V_36 ) ;
}
int F_54 ( struct V_133 * V_134 , struct V_35 * V_36 ,
unsigned long V_94 , unsigned long V_143 )
{
struct V_1 * V_1 = V_36 -> V_1 ;
unsigned long V_144 [ 3 ] , V_93 ;
T_4 * V_106 ;
unsigned long V_145 , V_46 , V_146 ;
unsigned long V_147 , V_148 ;
unsigned long V_135 , V_149 , V_150 , V_151 ;
struct V_37 * V_38 ;
unsigned long * V_152 ;
struct V_4 * V_5 ;
struct V_6 * V_6 , * V_153 [ 1 ] ;
long V_107 , V_50 , V_41 ;
unsigned long V_154 ;
unsigned int V_155 , V_156 ;
struct V_157 * V_158 ;
unsigned long V_159 ;
if ( V_94 != V_36 -> V_10 . V_160 )
return V_140 ;
V_107 = V_36 -> V_10 . V_161 ;
V_106 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_107 << 4 ) ) ;
V_5 = & V_1 -> V_10 . V_23 [ V_107 ] ;
F_42 () ;
while ( ! F_55 ( V_106 , V_115 ) )
F_56 () ;
V_144 [ 0 ] = F_45 ( V_106 [ 0 ] ) & ~ V_115 ;
V_144 [ 1 ] = F_45 ( V_106 [ 1 ] ) ;
V_144 [ 2 ] = V_93 = V_5 -> V_116 ;
F_46 ( V_106 , V_144 [ 0 ] ) ;
F_44 () ;
if ( V_144 [ 0 ] != V_36 -> V_10 . V_162 [ 0 ] ||
V_144 [ 1 ] != V_36 -> V_10 . V_162 [ 1 ] )
return V_140 ;
V_46 = F_40 ( V_144 [ 0 ] , V_93 ) ;
V_147 = V_93 & V_96 & ~ ( V_46 - 1 ) ;
V_148 = V_147 >> V_12 ;
V_135 = V_147 | ( V_94 & ( V_46 - 1 ) ) ;
V_149 = V_135 >> V_12 ;
V_38 = F_57 ( V_1 , V_149 ) ;
F_58 ( V_36 , V_144 , V_38 , V_94 , V_143 ) ;
if ( ! V_38 || ( V_38 -> V_71 & V_163 ) )
return F_51 ( V_134 , V_36 , V_135 , V_94 ,
V_143 & V_164 ) ;
if ( V_148 < V_38 -> V_165 )
return - V_166 ;
V_145 = V_1 -> V_167 ;
F_59 () ;
V_50 = - V_166 ;
V_154 = 0 ;
V_151 = 0 ;
V_6 = NULL ;
V_146 = V_168 ;
V_155 = ( V_143 & V_164 ) != 0 ;
V_156 = V_155 ;
V_150 = F_60 ( V_38 , V_149 ) ;
V_41 = F_61 ( V_150 , 1 , V_155 , V_153 ) ;
if ( V_41 < 1 ) {
F_62 ( & V_76 -> V_77 -> V_169 ) ;
V_158 = F_63 ( V_76 -> V_77 , V_150 ) ;
if ( V_158 && V_158 -> V_170 <= V_150 && V_150 + V_46 <= V_158 -> V_171 &&
( V_158 -> V_172 & V_173 ) ) {
V_151 = V_158 -> V_174 +
( ( V_150 - V_158 -> V_170 ) >> V_12 ) ;
V_146 = V_46 ;
V_154 = F_64 ( F_65 ( V_158 -> V_175 ) ) ;
V_156 = V_158 -> V_172 & V_176 ;
}
F_66 ( & V_76 -> V_77 -> V_169 ) ;
if ( ! V_151 )
goto V_177;
} else {
V_6 = V_153 [ 0 ] ;
V_151 = F_4 ( V_6 ) ;
if ( F_67 ( V_6 ) ) {
V_6 = F_68 ( V_6 ) ;
V_146 <<= F_69 ( V_6 ) ;
}
if ( ! V_155 && F_70 ( V_93 ) ) {
T_5 * V_178 , V_179 ;
unsigned long V_71 ;
F_71 ( V_71 ) ;
V_178 = F_72 ( V_76 -> V_77 -> V_78 ,
V_150 , NULL ) ;
if ( V_178 ) {
V_179 = F_73 ( V_178 , 1 ) ;
if ( F_74 ( V_179 ) )
V_156 = 1 ;
}
F_75 ( V_71 ) ;
}
}
if ( V_46 > V_146 )
goto V_177;
if ( ! F_76 ( V_93 , V_154 ) ) {
if ( V_154 )
goto V_177;
V_93 = ( V_93 & ~ ( V_180 | V_181 | V_128 ) ) | V_56 ;
}
if ( V_46 < V_168 )
V_46 = V_168 ;
V_93 = ( V_93 & ~ ( V_119 - V_46 ) ) | ( ( V_151 << V_12 ) & ~ ( V_46 - 1 ) ) ;
if ( F_70 ( V_93 ) && ! V_156 )
V_93 = F_77 ( V_93 ) ;
V_50 = V_140 ;
F_42 () ;
while ( ! F_55 ( V_106 , V_115 ) )
F_56 () ;
if ( ( F_45 ( V_106 [ 0 ] ) & ~ V_115 ) != V_144 [ 0 ] ||
F_45 ( V_106 [ 1 ] ) != V_144 [ 1 ] ||
V_5 -> V_116 != V_144 [ 2 ] )
goto V_182;
V_144 [ 0 ] = ( V_144 [ 0 ] & ~ V_113 ) | V_112 ;
V_152 = & V_38 -> V_10 . V_152 [ V_148 - V_38 -> V_165 ] ;
F_78 ( V_152 ) ;
V_50 = V_140 ;
if ( F_79 ( V_36 -> V_1 , V_145 ) ) {
F_80 ( V_152 ) ;
goto V_182;
}
V_159 = * V_152 >> V_183 ;
V_93 &= V_159 | ~ ( V_54 | V_55 ) ;
if ( F_45 ( V_106 [ 0 ] ) & V_112 ) {
F_80 ( V_152 ) ;
V_106 [ 0 ] |= F_81 ( V_113 ) ;
F_82 ( V_1 , V_106 , V_107 ) ;
V_93 |= F_45 ( V_106 [ 1 ] ) & ( V_54 | V_55 ) ;
} else {
F_83 ( V_1 , V_5 , V_152 , V_107 , 0 ) ;
}
V_106 [ 1 ] = F_81 ( V_93 ) ;
F_84 () ;
F_85 ( V_106 , V_144 [ 0 ] ) ;
asm volatile("ptesync" : : : "memory");
F_44 () ;
if ( V_6 && F_70 ( V_93 ) )
F_86 ( V_6 ) ;
V_177:
F_87 ( V_36 , V_144 , V_50 ) ;
if ( V_6 ) {
F_88 ( V_153 [ 0 ] ) ;
}
return V_50 ;
V_182:
F_85 ( V_106 , F_45 ( V_106 [ 0 ] ) ) ;
F_44 () ;
goto V_177;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_184 * V_185 ;
struct V_37 * V_38 ;
int V_186 ;
V_186 = F_89 ( & V_1 -> V_187 ) ;
V_185 = V_184 ( V_1 ) ;
F_90 (memslot, slots) {
memset ( V_38 -> V_10 . V_152 , 0 ,
V_38 -> V_41 * sizeof( * V_38 -> V_10 . V_152 ) ) ;
}
F_91 ( & V_1 -> V_187 , V_186 ) ;
}
static int F_92 ( struct V_1 * V_1 ,
unsigned long V_188 ,
unsigned long V_189 ,
int (* F_93)( struct V_1 * V_1 ,
unsigned long * V_190 ,
unsigned long V_149 ) )
{
int V_50 ;
int V_191 = 0 ;
struct V_184 * V_185 ;
struct V_37 * V_38 ;
V_185 = V_184 ( V_1 ) ;
F_90 (memslot, slots) {
unsigned long V_192 , V_193 ;
T_6 V_149 , V_194 ;
V_192 = F_94 ( V_188 , V_38 -> V_195 ) ;
V_193 = F_95 ( V_189 , V_38 -> V_195 +
( V_38 -> V_41 << V_12 ) ) ;
if ( V_192 >= V_193 )
continue;
V_149 = F_96 ( V_192 , V_38 ) ;
V_194 = F_96 ( V_193 + V_168 - 1 , V_38 ) ;
for (; V_149 < V_194 ; ++ V_149 ) {
T_6 V_196 = V_149 - V_38 -> V_165 ;
V_50 = F_93 ( V_1 , & V_38 -> V_10 . V_152 [ V_196 ] , V_149 ) ;
V_191 |= V_50 ;
}
}
return V_191 ;
}
static int F_97 ( struct V_1 * V_1 , unsigned long V_150 ,
int (* F_93)( struct V_1 * V_1 , unsigned long * V_190 ,
unsigned long V_149 ) )
{
return F_92 ( V_1 , V_150 , V_150 + 1 , F_93 ) ;
}
static int F_98 ( struct V_1 * V_1 , unsigned long * V_190 ,
unsigned long V_149 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_23 ;
unsigned long V_197 , V_40 , V_198 ;
T_4 * V_106 ;
unsigned long V_74 , V_46 , V_159 ;
for (; ; ) {
F_78 ( V_190 ) ;
if ( ! ( * V_190 & V_199 ) ) {
F_80 ( V_190 ) ;
break;
}
V_40 = * V_190 & V_200 ;
V_106 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 << 4 ) ) ;
if ( ! F_55 ( V_106 , V_115 ) ) {
F_80 ( V_190 ) ;
while ( F_45 ( V_106 [ 0 ] ) & V_115 )
F_56 () ;
continue;
}
V_198 = V_5 [ V_40 ] . V_201 ;
if ( V_198 == V_40 ) {
* V_190 &= ~ ( V_199 | V_200 ) ;
} else {
V_197 = V_5 [ V_40 ] . V_202 ;
V_5 [ V_197 ] . V_201 = V_198 ;
V_5 [ V_198 ] . V_202 = V_197 ;
V_5 [ V_40 ] . V_201 = V_5 [ V_40 ] . V_202 = V_40 ;
* V_190 = ( * V_190 & ~ V_200 ) | V_198 ;
}
V_74 = V_5 [ V_40 ] . V_116 ;
V_46 = F_40 ( F_45 ( V_106 [ 0 ] ) , V_74 ) ;
if ( ( F_45 ( V_106 [ 0 ] ) & V_112 ) &&
F_99 ( V_74 , V_46 ) == V_149 ) {
V_106 [ 0 ] |= F_81 ( V_113 ) ;
F_82 ( V_1 , V_106 , V_40 ) ;
V_159 = F_45 ( V_106 [ 1 ] ) & ( V_54 | V_55 ) ;
* V_190 |= V_159 << V_183 ;
if ( V_159 & ~ V_5 [ V_40 ] . V_116 ) {
V_5 [ V_40 ] . V_116 = V_74 | V_159 ;
F_100 ( V_1 , & V_5 [ V_40 ] ) ;
}
}
F_80 ( V_190 ) ;
F_85 ( V_106 , F_45 ( V_106 [ 0 ] ) ) ;
}
return 0 ;
}
int F_101 ( struct V_1 * V_1 , unsigned long V_150 )
{
F_97 ( V_1 , V_150 , F_98 ) ;
return 0 ;
}
int F_102 ( struct V_1 * V_1 , unsigned long V_188 , unsigned long V_189 )
{
F_92 ( V_1 , V_188 , V_189 , F_98 ) ;
return 0 ;
}
void F_103 ( struct V_1 * V_1 ,
struct V_37 * V_38 )
{
unsigned long * V_190 ;
unsigned long V_149 ;
unsigned long V_203 ;
V_190 = V_38 -> V_10 . V_152 ;
V_149 = V_38 -> V_165 ;
for ( V_203 = V_38 -> V_41 ; V_203 ; -- V_203 ) {
if ( * V_190 & V_199 )
F_98 ( V_1 , V_190 , V_149 ) ;
++ V_190 ;
++ V_149 ;
}
}
static int F_104 ( struct V_1 * V_1 , unsigned long * V_190 ,
unsigned long V_149 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_23 ;
unsigned long V_204 , V_40 , V_198 ;
T_4 * V_106 ;
int V_50 = 0 ;
V_205:
F_78 ( V_190 ) ;
if ( * V_190 & V_206 ) {
* V_190 &= ~ V_206 ;
V_50 = 1 ;
}
if ( ! ( * V_190 & V_199 ) ) {
F_80 ( V_190 ) ;
return V_50 ;
}
V_40 = V_204 = * V_190 & V_200 ;
do {
V_106 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 << 4 ) ) ;
V_198 = V_5 [ V_40 ] . V_201 ;
if ( ! ( F_45 ( V_106 [ 1 ] ) & V_54 ) )
continue;
if ( ! F_55 ( V_106 , V_115 ) ) {
F_80 ( V_190 ) ;
while ( F_45 ( V_106 [ 0 ] ) & V_115 )
F_56 () ;
goto V_205;
}
if ( ( F_45 ( V_106 [ 0 ] ) & V_112 ) &&
( F_45 ( V_106 [ 1 ] ) & V_54 ) ) {
F_105 ( V_1 , V_106 , V_40 ) ;
if ( ! ( V_5 [ V_40 ] . V_116 & V_54 ) ) {
V_5 [ V_40 ] . V_116 |= V_54 ;
F_100 ( V_1 , & V_5 [ V_40 ] ) ;
}
V_50 = 1 ;
}
F_85 ( V_106 , F_45 ( V_106 [ 0 ] ) ) ;
} while ( ( V_40 = V_198 ) != V_204 );
F_80 ( V_190 ) ;
return V_50 ;
}
int F_106 ( struct V_1 * V_1 , unsigned long V_188 , unsigned long V_189 )
{
return F_92 ( V_1 , V_188 , V_189 , F_104 ) ;
}
static int F_107 ( struct V_1 * V_1 , unsigned long * V_190 ,
unsigned long V_149 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_23 ;
unsigned long V_204 , V_40 , V_198 ;
unsigned long * V_207 ;
int V_50 = 1 ;
if ( * V_190 & V_206 )
return 1 ;
F_78 ( V_190 ) ;
if ( * V_190 & V_206 )
goto V_31;
if ( * V_190 & V_199 ) {
V_40 = V_204 = * V_190 & V_200 ;
do {
V_207 = ( unsigned long * ) ( V_1 -> V_10 . V_18 + ( V_40 << 4 ) ) ;
V_198 = V_5 [ V_40 ] . V_201 ;
if ( F_45 ( V_207 [ 1 ] ) & V_54 )
goto V_31;
} while ( ( V_40 = V_198 ) != V_204 );
}
V_50 = 0 ;
V_31:
F_80 ( V_190 ) ;
return V_50 ;
}
int F_108 ( struct V_1 * V_1 , unsigned long V_150 )
{
return F_97 ( V_1 , V_150 , F_107 ) ;
}
void F_109 ( struct V_1 * V_1 , unsigned long V_150 , T_5 V_179 )
{
F_97 ( V_1 , V_150 , F_98 ) ;
}
static int V_30 ( struct V_1 * V_1 )
{
return F_15 ( & V_1 -> V_10 . V_30 ) != 0 ;
}
static int F_110 ( struct V_1 * V_1 , unsigned long * V_190 )
{
struct V_4 * V_5 = V_1 -> V_10 . V_23 ;
unsigned long V_204 , V_40 , V_198 ;
unsigned long V_203 ;
unsigned long V_92 , V_93 ;
T_4 * V_106 ;
int V_208 = 0 ;
V_205:
F_78 ( V_190 ) ;
if ( * V_190 & V_209 ) {
* V_190 &= ~ V_209 ;
V_208 = 1 ;
}
if ( ! ( * V_190 & V_199 ) ) {
F_80 ( V_190 ) ;
return V_208 ;
}
V_40 = V_204 = * V_190 & V_200 ;
do {
unsigned long V_210 ;
V_106 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 << 4 ) ) ;
V_198 = V_5 [ V_40 ] . V_201 ;
V_210 = F_45 ( V_106 [ 1 ] ) ;
if ( ! ( V_210 & V_55 ) &&
( ! F_70 ( V_210 ) || V_30 ( V_1 ) ) )
continue;
if ( ! F_55 ( V_106 , V_115 ) ) {
F_80 ( V_190 ) ;
while ( V_106 [ 0 ] & F_81 ( V_115 ) )
F_56 () ;
goto V_205;
}
if ( ! ( V_106 [ 0 ] & F_81 ( V_112 ) ) ) {
F_85 ( V_106 , F_45 ( V_106 [ 0 ] ) ) ;
continue;
}
V_106 [ 0 ] |= F_81 ( V_113 ) ;
F_82 ( V_1 , V_106 , V_40 ) ;
V_92 = F_45 ( V_106 [ 0 ] ) ;
V_93 = F_45 ( V_106 [ 1 ] ) ;
if ( V_93 & V_55 ) {
V_106 [ 1 ] = F_81 ( V_93 & ~ V_55 ) ;
if ( ! ( V_5 [ V_40 ] . V_116 & V_55 ) ) {
V_5 [ V_40 ] . V_116 |= V_55 ;
F_100 ( V_1 , & V_5 [ V_40 ] ) ;
}
V_203 = F_40 ( V_92 , V_93 ) ;
V_203 = ( V_203 + V_168 - 1 ) >> V_12 ;
if ( V_203 > V_208 )
V_208 = V_203 ;
F_84 () ;
}
V_92 &= ~ V_113 ;
V_92 |= V_112 ;
F_85 ( V_106 , V_92 ) ;
} while ( ( V_40 = V_198 ) != V_204 );
F_80 ( V_190 ) ;
return V_208 ;
}
static void F_111 ( struct V_211 * V_212 ,
struct V_37 * V_38 ,
unsigned long * V_213 )
{
unsigned long V_149 ;
if ( ! V_212 -> V_214 || ! V_212 -> V_215 )
return;
V_149 = V_212 -> V_135 >> V_12 ;
if ( V_149 < V_38 -> V_165 ||
V_149 >= V_38 -> V_165 + V_38 -> V_41 )
return;
V_212 -> V_214 = false ;
if ( V_213 )
F_112 ( V_149 - V_38 -> V_165 , V_213 ) ;
}
long F_113 ( struct V_1 * V_1 , struct V_37 * V_38 ,
unsigned long * V_213 )
{
unsigned long V_40 , V_198 ;
unsigned long * V_190 ;
struct V_35 * V_36 ;
F_42 () ;
V_190 = V_38 -> V_10 . V_152 ;
for ( V_40 = 0 ; V_40 < V_38 -> V_41 ; ++ V_40 ) {
int V_41 = F_110 ( V_1 , V_190 ) ;
if ( V_41 && V_213 )
for ( V_198 = V_40 ; V_41 ; ++ V_198 , -- V_41 )
F_112 ( V_198 , V_213 ) ;
++ V_190 ;
}
F_114 (i, vcpu, kvm) {
F_115 ( & V_36 -> V_10 . V_216 ) ;
F_111 ( & V_36 -> V_10 . V_212 , V_38 , V_213 ) ;
F_111 ( & V_36 -> V_10 . V_217 , V_38 , V_213 ) ;
F_116 ( & V_36 -> V_10 . V_216 ) ;
}
F_44 () ;
return 0 ;
}
void * F_117 ( struct V_1 * V_1 , unsigned long V_135 ,
unsigned long * V_218 )
{
struct V_37 * V_38 ;
unsigned long V_149 = V_135 >> V_12 ;
struct V_6 * V_6 , * V_153 [ 1 ] ;
int V_41 ;
unsigned long V_150 , V_219 ;
int V_186 ;
V_186 = F_89 ( & V_1 -> V_187 ) ;
V_38 = F_57 ( V_1 , V_149 ) ;
if ( ! V_38 || ( V_38 -> V_71 & V_163 ) )
goto V_26;
V_150 = F_60 ( V_38 , V_149 ) ;
V_41 = F_61 ( V_150 , 1 , 1 , V_153 ) ;
if ( V_41 < 1 )
goto V_26;
V_6 = V_153 [ 0 ] ;
F_91 ( & V_1 -> V_187 , V_186 ) ;
V_219 = V_135 & ( V_168 - 1 ) ;
if ( V_218 )
* V_218 = V_168 - V_219 ;
return F_118 ( V_6 ) + V_219 ;
V_26:
F_91 ( & V_1 -> V_187 , V_186 ) ;
return NULL ;
}
void F_119 ( struct V_1 * V_1 , void * V_220 , unsigned long V_135 ,
bool V_214 )
{
struct V_6 * V_6 = F_22 ( V_220 ) ;
struct V_37 * V_38 ;
unsigned long V_149 ;
unsigned long * V_152 ;
int V_186 ;
F_88 ( V_6 ) ;
if ( ! V_214 )
return;
V_149 = V_135 >> V_12 ;
V_186 = F_89 ( & V_1 -> V_187 ) ;
V_38 = F_57 ( V_1 , V_149 ) ;
if ( V_38 ) {
V_152 = & V_38 -> V_10 . V_152 [ V_149 - V_38 -> V_165 ] ;
F_78 ( V_152 ) ;
* V_152 |= V_209 ;
F_80 ( V_152 ) ;
}
F_91 ( & V_1 -> V_187 , V_186 ) ;
}
static int F_120 ( struct V_4 * V_221 , T_4 * V_222 )
{
unsigned long V_223 ;
if ( V_221 -> V_116 & V_224 )
return 1 ;
V_223 = ~ V_221 -> V_116 & ( V_54 | V_55 ) ;
if ( ( F_45 ( V_222 [ 0 ] ) & V_112 ) &&
( F_45 ( V_222 [ 1 ] ) & V_223 ) )
return 1 ;
return 0 ;
}
static long F_121 ( unsigned long V_71 , T_4 * V_222 ,
unsigned long * V_144 , struct V_4 * V_221 ,
int V_225 , int V_226 )
{
unsigned long V_92 , V_93 ;
unsigned long V_223 ;
int V_227 = 1 ;
int V_228 , V_214 ;
V_214 = F_120 ( V_221 , V_222 ) ;
if ( ! V_226 && ! V_214 )
return 0 ;
V_228 = 0 ;
if ( F_45 ( V_222 [ 0 ] ) & ( V_112 | V_113 ) ) {
V_228 = 1 ;
if ( ( V_71 & V_229 ) &&
! ( F_45 ( V_222 [ 0 ] ) & V_53 ) )
V_228 = 0 ;
}
if ( V_228 != V_225 )
return 0 ;
V_92 = V_93 = 0 ;
if ( V_228 || V_214 ) {
F_42 () ;
while ( ! F_55 ( V_222 , V_115 ) )
F_56 () ;
V_92 = F_45 ( V_222 [ 0 ] ) ;
V_228 = ! ! ( V_92 & V_112 ) ;
V_214 = ! ! ( V_221 -> V_116 & V_224 ) ;
V_223 = ~ V_221 -> V_116 & ( V_54 | V_55 ) ;
if ( V_228 && ( V_223 & F_45 ( V_222 [ 1 ] ) ) ) {
V_221 -> V_116 |= ( F_45 ( V_222 [ 1 ] ) &
( V_54 | V_55 ) ) | V_224 ;
V_214 = 1 ;
}
if ( V_92 & V_113 ) {
V_92 &= ~ V_113 ;
V_92 |= V_112 ;
V_228 = 1 ;
}
if ( ( V_71 & V_229 ) && ! ( V_92 & V_53 ) )
V_228 = 0 ;
V_93 = V_221 -> V_116 ;
if ( V_228 == V_225 && V_214 ) {
V_93 &= ~ V_224 ;
V_221 -> V_116 = V_93 ;
}
F_46 ( V_222 , F_45 ( V_222 [ 0 ] ) ) ;
F_44 () ;
if ( ! ( V_228 == V_225 && ( V_226 || V_214 ) ) )
V_227 = 0 ;
}
V_144 [ 0 ] = F_81 ( V_92 ) ;
V_144 [ 1 ] = F_81 ( V_93 ) ;
return V_227 ;
}
static T_7 F_122 ( struct V_230 * V_230 , char T_8 * V_231 ,
T_9 V_232 , T_10 * V_233 )
{
struct V_234 * V_235 = V_230 -> V_236 ;
struct V_1 * V_1 = V_235 -> V_1 ;
struct V_237 V_238 ;
T_4 * V_222 ;
struct V_4 * V_221 ;
unsigned long V_40 , V_239 , V_240 ;
unsigned long T_8 * V_241 ;
struct V_237 T_8 * V_242 ;
unsigned long V_71 ;
int V_226 ;
unsigned long V_144 [ 2 ] ;
if ( ! F_123 ( V_243 , V_231 , V_232 ) )
return - V_166 ;
V_226 = V_235 -> V_226 ;
V_71 = V_235 -> V_71 ;
V_40 = V_235 -> V_107 ;
V_222 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 * V_244 ) ) ;
V_221 = V_1 -> V_10 . V_23 + V_40 ;
V_241 = ( unsigned long T_8 * ) V_231 ;
V_239 = 0 ;
while ( V_239 + sizeof( V_238 ) + V_244 < V_232 ) {
V_242 = (struct V_237 T_8 * ) V_231 ;
V_238 . V_245 = 0 ;
V_238 . V_246 = 0 ;
V_240 = V_239 ;
V_239 += sizeof( V_238 ) ;
V_241 = ( unsigned long T_8 * ) ( V_231 + sizeof( V_238 ) ) ;
if ( ! V_226 ) {
while ( V_40 < V_1 -> V_10 . V_20 &&
! F_120 ( V_221 , V_222 ) ) {
++ V_40 ;
V_222 += 2 ;
++ V_221 ;
}
}
V_238 . V_107 = V_40 ;
while ( V_40 < V_1 -> V_10 . V_20 &&
V_238 . V_245 < 0xffff &&
V_239 + V_244 < V_232 &&
F_121 ( V_71 , V_222 , V_144 , V_221 , 1 , V_226 ) ) {
++ V_238 . V_245 ;
if ( F_124 ( V_144 [ 0 ] , V_241 ) ||
F_124 ( V_144 [ 1 ] , V_241 + 1 ) )
return - V_166 ;
V_239 += V_244 ;
V_241 += 2 ;
++ V_40 ;
V_222 += 2 ;
++ V_221 ;
}
while ( V_40 < V_1 -> V_10 . V_20 &&
V_238 . V_246 < 0xffff &&
F_121 ( V_71 , V_222 , V_144 , V_221 , 0 , V_226 ) ) {
++ V_238 . V_246 ;
++ V_40 ;
V_222 += 2 ;
++ V_221 ;
}
if ( V_238 . V_245 || V_238 . V_246 ) {
if ( F_125 ( V_242 , & V_238 , sizeof( V_238 ) ) )
return - V_166 ;
V_240 = V_239 ;
V_231 = ( char T_8 * ) V_241 ;
} else {
V_239 = V_240 ;
}
if ( V_40 >= V_1 -> V_10 . V_20 ) {
V_40 = 0 ;
V_235 -> V_226 = 0 ;
break;
}
}
V_235 -> V_107 = V_40 ;
return V_239 ;
}
static T_7 F_126 ( struct V_230 * V_230 , const char T_8 * V_231 ,
T_9 V_232 , T_10 * V_233 )
{
struct V_234 * V_235 = V_230 -> V_236 ;
struct V_1 * V_1 = V_235 -> V_1 ;
struct V_237 V_238 ;
unsigned long V_40 , V_198 ;
unsigned long V_92 , V_93 ;
unsigned long T_8 * V_241 ;
T_4 * V_222 ;
unsigned long V_247 [ 2 ] ;
T_7 V_239 ;
long int V_26 , V_50 ;
int V_248 ;
if ( ! F_123 ( V_249 , V_231 , V_232 ) )
return - V_166 ;
F_13 ( & V_1 -> V_28 ) ;
V_248 = V_1 -> V_10 . V_29 ;
if ( V_248 ) {
V_1 -> V_10 . V_29 = 0 ;
F_14 () ;
if ( F_15 ( & V_1 -> V_10 . V_30 ) ) {
V_1 -> V_10 . V_29 = 1 ;
F_18 ( & V_1 -> V_28 ) ;
return - V_27 ;
}
}
V_26 = 0 ;
for ( V_239 = 0 ; V_239 + sizeof( V_238 ) <= V_232 ; ) {
V_26 = - V_166 ;
if ( F_127 ( & V_238 , V_231 , sizeof( V_238 ) ) )
break;
V_26 = 0 ;
if ( V_239 + V_238 . V_245 * V_244 > V_232 )
break;
V_239 += sizeof( V_238 ) ;
V_231 += sizeof( V_238 ) ;
V_26 = - V_63 ;
V_40 = V_238 . V_107 ;
if ( V_40 >= V_1 -> V_10 . V_20 ||
V_40 + V_238 . V_245 + V_238 . V_246 > V_1 -> V_10 . V_20 )
break;
V_222 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 * V_244 ) ) ;
V_241 = ( unsigned long T_8 * ) V_231 ;
for ( V_198 = 0 ; V_198 < V_238 . V_245 ; ++ V_198 ) {
T_4 V_250 ;
T_4 V_251 ;
V_26 = - V_166 ;
if ( F_128 ( V_250 , V_241 ) ||
F_128 ( V_251 , V_241 + 1 ) )
goto V_31;
V_92 = F_45 ( V_250 ) ;
V_93 = F_45 ( V_251 ) ;
V_26 = - V_63 ;
if ( ! ( V_92 & V_112 ) )
goto V_31;
V_241 += 2 ;
V_239 += V_244 ;
if ( F_45 ( V_222 [ 0 ] ) & ( V_112 | V_113 ) )
F_129 ( V_1 , 0 , V_40 , 0 , V_247 ) ;
V_26 = - V_252 ;
V_50 = F_26 ( V_1 , V_58 , V_40 , V_92 , V_93 ,
V_247 ) ;
if ( V_50 != V_59 ) {
F_7 ( L_5
L_6 , V_50 , V_40 , V_92 , V_93 ) ;
goto V_31;
}
if ( ! V_248 && F_130 ( V_92 ) ) {
unsigned long V_46 = F_131 ( V_92 , V_93 ) ;
unsigned long V_253 = F_132 ( V_46 ) ;
unsigned long V_254 ;
V_1 -> V_10 . V_111 = V_253 | V_89 |
( V_52 << V_255 ) ;
V_254 = V_253 << ( V_256 - 4 ) ;
F_133 ( V_1 , V_254 , V_257 ) ;
V_248 = 1 ;
}
++ V_40 ;
V_222 += 2 ;
}
for ( V_198 = 0 ; V_198 < V_238 . V_246 ; ++ V_198 ) {
if ( F_45 ( V_222 [ 0 ] ) & ( V_112 | V_113 ) )
F_129 ( V_1 , 0 , V_40 , 0 , V_247 ) ;
++ V_40 ;
V_222 += 2 ;
}
V_26 = 0 ;
}
V_31:
F_134 () ;
V_1 -> V_10 . V_29 = V_248 ;
F_18 ( & V_1 -> V_28 ) ;
if ( V_26 )
return V_26 ;
return V_239 ;
}
static int F_135 ( struct V_258 * V_258 , struct V_230 * V_259 )
{
struct V_234 * V_235 = V_259 -> V_236 ;
V_259 -> V_236 = NULL ;
if ( ! ( V_235 -> V_71 & V_260 ) )
F_136 ( & V_235 -> V_1 -> V_10 . V_261 ) ;
F_137 ( V_235 -> V_1 ) ;
F_138 ( V_235 ) ;
return 0 ;
}
int F_139 ( struct V_1 * V_1 , struct V_262 * V_263 )
{
int V_50 ;
struct V_234 * V_235 ;
int V_264 ;
if ( V_263 -> V_71 & ~ ( V_229 | V_260 ) )
return - V_63 ;
V_235 = F_140 ( sizeof( * V_235 ) , V_13 ) ;
if ( ! V_235 )
return - V_17 ;
F_141 ( V_1 ) ;
V_235 -> V_1 = V_1 ;
V_235 -> V_107 = V_263 -> V_265 ;
V_235 -> V_71 = V_263 -> V_71 ;
V_235 -> V_226 = 1 ;
V_264 = ( V_263 -> V_71 & V_260 ) ? V_266 : V_267 ;
V_50 = F_142 ( L_7 , & V_268 , V_235 , V_264 | V_269 ) ;
if ( V_50 < 0 ) {
F_137 ( V_1 ) ;
return V_50 ;
}
if ( V_264 == V_267 ) {
F_13 ( & V_1 -> V_270 ) ;
F_143 ( & V_1 -> V_10 . V_261 ) ;
F_144 ( & V_1 -> V_187 ) ;
F_18 ( & V_1 -> V_270 ) ;
}
return V_50 ;
}
static int F_145 ( struct V_258 * V_258 , struct V_230 * V_230 )
{
struct V_1 * V_1 = V_258 -> V_271 ;
struct V_272 * V_273 ;
V_273 = F_140 ( sizeof( * V_273 ) , V_13 ) ;
if ( ! V_273 )
return - V_17 ;
F_141 ( V_1 ) ;
V_273 -> V_1 = V_1 ;
F_146 ( & V_273 -> V_274 ) ;
V_230 -> V_236 = V_273 ;
return F_147 ( V_258 , V_230 ) ;
}
static int F_148 ( struct V_258 * V_258 , struct V_230 * V_230 )
{
struct V_272 * V_273 = V_230 -> V_236 ;
F_137 ( V_273 -> V_1 ) ;
F_138 ( V_273 ) ;
return 0 ;
}
static T_7 F_149 ( struct V_230 * V_230 , char T_8 * V_231 ,
T_9 V_275 , T_10 * V_233 )
{
struct V_272 * V_273 = V_230 -> V_236 ;
T_7 V_50 , V_93 ;
unsigned long V_40 , V_203 ;
unsigned long V_92 , V_276 , V_105 ;
struct V_1 * V_1 ;
T_4 * V_222 ;
V_50 = F_150 ( & V_273 -> V_274 ) ;
if ( V_50 )
return V_50 ;
if ( V_273 -> V_277 ) {
V_203 = V_273 -> V_277 ;
if ( V_203 > V_275 )
V_203 = V_275 ;
V_93 = F_151 ( V_231 , V_273 -> V_231 + V_273 -> V_278 , V_203 ) ;
V_203 -= V_93 ;
V_273 -> V_277 -= V_203 ;
V_273 -> V_278 += V_203 ;
V_231 += V_203 ;
V_275 -= V_203 ;
V_50 = V_203 ;
if ( V_93 ) {
if ( ! V_203 )
V_50 = - V_166 ;
goto V_31;
}
}
V_1 = V_273 -> V_1 ;
V_40 = V_273 -> V_279 ;
V_222 = ( T_4 * ) ( V_1 -> V_10 . V_18 + ( V_40 * V_244 ) ) ;
for (; V_275 != 0 && V_40 < V_1 -> V_10 . V_20 ; ++ V_40 , V_222 += 2 ) {
if ( ! ( F_45 ( V_222 [ 0 ] ) & ( V_112 | V_113 ) ) )
continue;
F_42 () ;
while ( ! F_55 ( V_222 , V_115 ) )
F_56 () ;
V_92 = F_45 ( V_222 [ 0 ] ) & ~ V_115 ;
V_276 = F_45 ( V_222 [ 1 ] ) ;
V_105 = V_1 -> V_10 . V_23 [ V_40 ] . V_116 ;
F_46 ( V_222 , V_92 ) ;
F_44 () ;
if ( ! ( V_92 & ( V_112 | V_113 ) ) )
continue;
V_203 = F_152 ( V_273 -> V_231 , sizeof( V_273 -> V_231 ) ,
L_8 ,
V_40 , V_92 , V_276 , V_105 ) ;
V_273 -> V_277 = V_203 ;
if ( V_203 > V_275 )
V_203 = V_275 ;
V_93 = F_151 ( V_231 , V_273 -> V_231 , V_203 ) ;
V_203 -= V_93 ;
V_273 -> V_277 -= V_203 ;
V_273 -> V_278 = V_203 ;
V_231 += V_203 ;
V_275 -= V_203 ;
V_50 += V_203 ;
if ( V_93 ) {
if ( ! V_50 )
V_50 = - V_166 ;
goto V_31;
}
}
V_273 -> V_279 = V_40 ;
V_31:
F_18 ( & V_273 -> V_274 ) ;
return V_50 ;
}
T_7 F_153 ( struct V_230 * V_230 , const char T_8 * V_231 ,
T_9 V_275 , T_10 * V_233 )
{
return - V_280 ;
}
void F_154 ( struct V_1 * V_1 )
{
V_1 -> V_10 . V_281 = F_155 ( L_9 , 0400 ,
V_1 -> V_10 . V_282 , V_1 ,
& V_283 ) ;
}
void F_156 ( struct V_35 * V_36 )
{
struct V_284 * V_285 = & V_36 -> V_10 . V_285 ;
V_36 -> V_10 . V_84 = 32 ;
V_285 -> V_286 = F_41 ;
V_285 -> V_287 = F_32 ;
V_36 -> V_10 . V_288 |= V_289 ;
}
