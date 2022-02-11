int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 = 0 ;
int V_5 = 0 ;
struct V_6 * V_6 = NULL ;
struct V_7 * V_8 ;
unsigned long V_9 ;
if ( ( V_3 < V_10 ) || ( V_3 > V_11 ) )
return - V_12 ;
V_6 = F_2 ( 1ul << ( V_3 - V_13 ) ) ;
if ( V_6 ) {
V_4 = ( unsigned long ) F_3 ( F_4 ( V_6 ) ) ;
memset ( ( void * ) V_4 , 0 , ( 1ul << V_3 ) ) ;
V_5 = 1 ;
}
if ( ! V_4 )
V_4 = F_5 ( V_14 | V_15 | V_16
| V_17 , V_3 - V_13 ) ;
if ( ! V_4 )
return - V_18 ;
V_9 = 1ul << ( V_3 - 4 ) ;
V_8 = F_6 ( sizeof( struct V_7 ) * V_9 ) ;
if ( ! V_8 ) {
F_7 ( L_1 ) ;
if ( V_5 )
F_8 ( V_6 , 1 << ( V_3 - V_13 ) ) ;
else
F_9 ( V_4 , V_3 - V_13 ) ;
return - V_18 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_19 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = V_8 ;
return 0 ;
}
void F_10 ( struct V_20 * V_20 , struct V_1 * V_2 )
{
F_11 ( & V_20 -> V_21 . V_22 , 0 ) ;
V_20 -> V_21 . V_4 = * V_2 ;
V_20 -> V_21 . V_23 = F_12 ( V_2 -> V_19 ) | ( V_2 -> V_3 - 18 ) ;
F_13 ( L_2 ,
V_2 -> V_19 , ( long ) V_2 -> V_3 , V_20 -> V_21 . V_24 ) ;
}
long F_14 ( struct V_20 * V_20 , int V_3 )
{
long V_25 = - V_26 ;
struct V_1 V_2 ;
if ( F_15 ( V_20 ) )
return - V_12 ;
F_16 ( & V_20 -> V_27 ) ;
if ( V_20 -> V_21 . V_28 ) {
V_20 -> V_21 . V_28 = 0 ;
F_17 () ;
if ( F_18 ( & V_20 -> V_21 . V_29 ) ) {
V_20 -> V_21 . V_28 = 1 ;
goto V_30;
}
}
if ( V_20 -> V_21 . V_4 . V_3 == V_3 ) {
memset ( ( void * ) V_20 -> V_21 . V_4 . V_19 , 0 , 1ul << V_3 ) ;
F_19 ( V_20 ) ;
F_20 ( & V_20 -> V_21 . V_31 ) ;
V_25 = 0 ;
goto V_30;
}
if ( V_20 -> V_21 . V_4 . V_19 )
F_21 ( & V_20 -> V_21 . V_4 ) ;
V_25 = F_1 ( & V_2 , V_3 ) ;
if ( V_25 < 0 )
goto V_30;
F_10 ( V_20 , & V_2 ) ;
V_30:
F_22 ( & V_20 -> V_27 ) ;
return V_25 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_8 ) ;
if ( V_2 -> V_5 )
F_8 ( F_24 ( V_2 -> V_19 ) ,
1 << ( V_2 -> V_3 - V_13 ) ) ;
else if ( V_2 -> V_19 )
F_9 ( V_2 -> V_19 , V_2 -> V_3 - V_13 ) ;
V_2 -> V_19 = 0 ;
V_2 -> V_3 = 0 ;
}
static inline unsigned long F_25 ( unsigned long V_32 )
{
return ( V_32 > 0x1000 ) ? V_33 : 0 ;
}
static inline unsigned long F_26 ( unsigned long V_32 )
{
return ( V_32 == 0x10000 ) ? 0x1000 : 0 ;
}
void F_27 ( struct V_34 * V_35 , struct V_36 * V_37 ,
unsigned long V_38 )
{
unsigned long V_39 ;
unsigned long V_40 ;
unsigned long V_41 , V_42 ;
unsigned long V_43 , V_44 ;
unsigned long V_45 ;
unsigned long V_46 , V_47 ;
unsigned long V_48 ;
long V_49 ;
struct V_20 * V_20 = V_35 -> V_20 ;
V_45 = 1ul << V_38 ;
V_40 = V_37 -> V_40 >> ( V_38 - V_13 ) ;
if ( V_40 > 1ul << ( 40 - V_38 ) )
V_40 = 1ul << ( 40 - V_38 ) ;
if ( V_40 > F_28 ( & V_20 -> V_21 . V_4 ) + 1 )
V_40 = F_28 ( & V_20 -> V_21 . V_4 ) + 1 ;
V_46 = V_50 | ( V_51 << ( 40 - 16 ) ) |
V_52 | F_25 ( V_45 ) ;
V_47 = F_26 ( V_45 ) |
V_53 | V_54 | V_55 | V_56 ;
for ( V_39 = 0 ; V_39 < V_40 ; ++ V_39 ) {
V_43 = V_39 << V_38 ;
V_44 = ( V_39 ^ ( V_51 ^ ( V_51 << 25 ) ) )
& F_28 ( & V_20 -> V_21 . V_4 ) ;
V_44 = ( V_44 << 3 ) + 7 ;
V_41 = V_46 | ( ( V_43 >> 16 ) & ~ 0x7fUL ) ;
V_42 = V_47 | V_43 ;
V_49 = F_29 ( V_20 , V_57 , V_44 , V_41 , V_42 ,
& V_48 ) ;
if ( V_49 != V_58 ) {
F_7 ( L_3 ,
V_43 , V_49 ) ;
break;
}
}
}
int F_30 ( void )
{
unsigned long V_59 , V_60 ;
if ( ! F_31 ( V_61 ) )
return - V_12 ;
V_59 = F_32 ( V_62 ) ;
V_60 = V_63 ;
F_33 ( V_60 + 1 ) ;
F_34 ( V_59 ) ;
F_34 ( V_60 ) ;
return 0 ;
}
static void F_35 ( struct V_34 * V_35 )
{
unsigned long V_64 = V_35 -> V_21 . V_65 ;
if ( F_36 ( V_35 -> V_21 . V_66 . V_64 ) )
V_64 |= V_67 ;
else
V_64 |= V_35 -> V_21 . V_66 . V_64 & V_68 ;
F_37 ( V_35 , V_64 ) ;
}
static long F_29 ( struct V_20 * V_20 , unsigned long V_69 ,
long V_70 , unsigned long V_71 ,
unsigned long V_72 , unsigned long * V_73 )
{
long V_49 ;
F_38 () ;
V_49 = F_39 ( V_20 , V_69 , V_70 , V_71 , V_72 ,
V_74 -> V_75 -> V_76 , false , V_73 ) ;
F_40 () ;
if ( V_49 == V_77 ) {
F_7 ( L_4 ) ;
V_49 = V_78 ;
}
return V_49 ;
}
static struct V_79 * F_41 ( struct V_34 * V_35 ,
T_2 V_80 )
{
T_3 V_81 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_35 -> V_21 . V_82 ; V_39 ++ ) {
if ( ! ( V_35 -> V_21 . V_83 [ V_39 ] . V_84 & V_85 ) )
continue;
if ( V_35 -> V_21 . V_83 [ V_39 ] . V_86 & V_87 )
V_81 = V_88 ;
else
V_81 = V_89 ;
if ( ( ( V_35 -> V_21 . V_83 [ V_39 ] . V_84 ^ V_80 ) & V_81 ) == 0 )
return & V_35 -> V_21 . V_83 [ V_39 ] ;
}
return NULL ;
}
static unsigned long F_42 ( unsigned long V_90 , unsigned long V_91 ,
unsigned long V_92 )
{
unsigned long V_93 ;
V_93 = F_43 ( V_90 , V_91 ) - 1 ;
return ( V_91 & V_94 & ~ V_93 ) | ( V_92 & V_93 ) ;
}
static int F_44 ( struct V_34 * V_35 , T_2 V_80 ,
struct V_95 * V_96 , bool V_97 , bool V_98 )
{
struct V_20 * V_20 = V_35 -> V_20 ;
struct V_79 * V_99 ;
unsigned long V_100 ;
unsigned long V_101 , V_102 ;
unsigned long V_90 , V_103 , V_104 ;
T_4 * V_105 ;
int V_106 ;
int V_107 = V_35 -> V_21 . V_66 . V_64 & ( V_97 ? V_108 : V_109 ) ;
if ( V_107 ) {
V_99 = F_41 ( V_35 , V_80 ) ;
if ( ! V_99 )
return - V_12 ;
V_100 = V_99 -> V_86 ;
} else {
V_100 = V_35 -> V_20 -> V_21 . V_110 ;
}
F_45 () ;
V_106 = F_46 ( V_20 , V_80 , V_100 ,
V_111 | V_112 ) ;
if ( V_106 < 0 ) {
F_47 () ;
return - V_113 ;
}
V_105 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_106 << 4 ) ) ;
V_90 = V_103 = F_48 ( V_105 [ 0 ] ) & ~ V_114 ;
if ( F_31 ( V_115 ) )
V_90 = F_49 ( V_90 , F_48 ( V_105 [ 1 ] ) ) ;
V_104 = V_20 -> V_21 . V_4 . V_8 [ V_106 ] . V_116 ;
F_50 ( V_105 , V_103 ) ;
F_47 () ;
V_96 -> V_80 = V_80 ;
V_96 -> V_117 = ( ( V_90 & V_118 ) << 4 ) | ( ( V_80 >> 12 ) & 0xfff ) ;
V_101 = V_104 & ( V_119 | V_120 ) ;
V_102 = ( V_35 -> V_21 . V_66 . V_64 & V_121 ) ? V_122 : V_123 ;
V_102 &= V_100 ;
V_96 -> V_124 = F_51 ( V_101 , V_102 ) ;
V_96 -> V_125 = F_52 ( V_101 , V_102 ) ;
V_96 -> V_126 = V_96 -> V_124 && ! ( V_104 & ( V_127 | V_128 ) ) ;
if ( V_97 && V_107 ) {
int V_129 = F_53 ( V_104 , V_35 -> V_21 . V_130 ) ;
if ( V_129 & 1 )
V_96 -> V_124 = 0 ;
if ( V_129 & 2 )
V_96 -> V_125 = 0 ;
}
V_96 -> V_131 = F_42 ( V_90 , V_104 , V_80 ) ;
return 0 ;
}
static int F_54 ( unsigned int V_132 )
{
unsigned int V_81 ;
V_81 = 0x10000000 ;
if ( ( V_132 & 0xfc000000 ) == 0x7c000000 )
V_81 = 0x100 ;
return ( V_132 & V_81 ) != 0 ;
}
int F_55 ( struct V_133 * V_134 , struct V_34 * V_35 ,
unsigned long V_135 , T_2 V_92 , int V_136 )
{
T_1 V_137 ;
if ( F_56 ( V_35 , V_138 , & V_137 ) !=
V_139 )
return V_140 ;
if ( F_54 ( V_137 ) != ! ! V_136 )
return V_140 ;
V_35 -> V_21 . V_141 = V_135 ;
V_35 -> V_21 . V_142 = V_92 ;
return F_57 ( V_134 , V_35 ) ;
}
int F_58 ( struct V_133 * V_134 , struct V_34 * V_35 ,
unsigned long V_92 , unsigned long V_143 )
{
struct V_20 * V_20 = V_35 -> V_20 ;
unsigned long V_144 [ 3 ] , V_91 ;
unsigned long V_145 , V_146 ;
T_4 * V_105 ;
unsigned long V_147 , V_45 , V_148 ;
unsigned long V_149 , V_150 ;
unsigned long V_135 , V_151 , V_152 , V_153 ;
struct V_36 * V_37 ;
unsigned long * V_154 ;
struct V_7 * V_8 ;
struct V_6 * V_6 , * V_155 [ 1 ] ;
long V_106 , V_49 , V_40 ;
bool V_156 ;
unsigned int V_157 , V_158 ;
struct V_159 * V_160 ;
unsigned long V_161 ;
long V_22 ;
if ( F_15 ( V_20 ) )
return F_59 ( V_134 , V_35 , V_92 , V_143 ) ;
if ( V_92 != V_35 -> V_21 . V_162 )
return V_140 ;
if ( V_35 -> V_21 . V_163 ) {
V_22 = F_60 ( & V_20 -> V_21 . V_22 ) ;
if ( V_22 == V_35 -> V_21 . V_163 -> V_22 ) {
V_91 = V_35 -> V_21 . V_163 -> V_164 ;
V_45 = F_43 ( V_35 -> V_21 . V_165 [ 0 ] , V_91 ) ;
V_149 = V_91 & V_94 & ~ ( V_45 - 1 ) ;
V_150 = V_149 >> V_13 ;
V_135 = V_149 | ( V_92 & ( V_45 - 1 ) ) ;
return F_55 ( V_134 , V_35 , V_135 , V_92 ,
V_143 & V_166 ) ;
}
}
V_106 = V_35 -> V_21 . V_167 ;
V_105 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_106 << 4 ) ) ;
V_8 = & V_20 -> V_21 . V_4 . V_8 [ V_106 ] ;
F_45 () ;
while ( ! F_61 ( V_105 , V_114 ) )
F_62 () ;
V_144 [ 0 ] = F_48 ( V_105 [ 0 ] ) & ~ V_114 ;
V_144 [ 1 ] = F_48 ( V_105 [ 1 ] ) ;
V_144 [ 2 ] = V_91 = V_8 -> V_116 ;
F_50 ( V_105 , V_144 [ 0 ] ) ;
F_47 () ;
if ( F_31 ( V_115 ) ) {
V_144 [ 0 ] = F_49 ( V_144 [ 0 ] , V_144 [ 1 ] ) ;
V_144 [ 1 ] = F_63 ( V_144 [ 1 ] ) ;
}
if ( V_144 [ 0 ] != V_35 -> V_21 . V_165 [ 0 ] ||
V_144 [ 1 ] != V_35 -> V_21 . V_165 [ 1 ] )
return V_140 ;
V_45 = F_43 ( V_144 [ 0 ] , V_91 ) ;
V_149 = V_91 & V_94 & ~ ( V_45 - 1 ) ;
V_150 = V_149 >> V_13 ;
V_135 = V_149 | ( V_92 & ( V_45 - 1 ) ) ;
V_151 = V_135 >> V_13 ;
V_37 = F_64 ( V_20 , V_151 ) ;
F_65 ( V_35 , V_144 , V_37 , V_92 , V_143 ) ;
if ( ! V_37 || ( V_37 -> V_69 & V_168 ) )
return F_55 ( V_134 , V_35 , V_135 , V_92 ,
V_143 & V_166 ) ;
if ( V_150 < V_37 -> V_169 )
return - V_170 ;
V_147 = V_20 -> V_171 ;
F_66 () ;
V_49 = - V_170 ;
V_156 = false ;
V_153 = 0 ;
V_6 = NULL ;
V_148 = V_172 ;
V_157 = ( V_143 & V_166 ) != 0 ;
V_158 = V_157 ;
V_152 = F_67 ( V_37 , V_151 ) ;
V_40 = F_68 ( V_152 , 1 , V_157 , V_155 ) ;
if ( V_40 < 1 ) {
F_69 ( & V_74 -> V_75 -> V_173 ) ;
V_160 = F_70 ( V_74 -> V_75 , V_152 ) ;
if ( V_160 && V_160 -> V_174 <= V_152 && V_152 + V_45 <= V_160 -> V_175 &&
( V_160 -> V_176 & V_177 ) ) {
V_153 = V_160 -> V_178 +
( ( V_152 - V_160 -> V_174 ) >> V_13 ) ;
V_148 = V_45 ;
V_156 = F_71 ( F_72 ( ( F_73 ( V_160 -> V_179 ) ) ) ) ;
V_158 = V_160 -> V_176 & V_180 ;
}
F_74 ( & V_74 -> V_75 -> V_173 ) ;
if ( ! V_153 )
goto V_181;
} else {
V_6 = V_155 [ 0 ] ;
V_153 = F_4 ( V_6 ) ;
if ( F_75 ( V_6 ) ) {
V_6 = F_76 ( V_6 ) ;
V_148 <<= F_77 ( V_6 ) ;
}
if ( ! V_157 && F_78 ( V_91 ) ) {
T_5 * V_182 , V_183 ;
unsigned long V_69 ;
F_79 ( V_69 ) ;
V_182 = F_80 ( V_74 -> V_75 -> V_76 ,
V_152 , NULL , NULL ) ;
if ( V_182 ) {
V_183 = F_81 ( V_182 , 1 ) ;
if ( F_82 ( V_183 ) )
V_158 = 1 ;
}
F_83 ( V_69 ) ;
}
}
if ( V_45 > V_148 )
goto V_181;
if ( ! F_84 ( V_91 , V_156 ) ) {
if ( V_156 )
goto V_181;
V_91 = ( V_91 & ~ ( V_184 | V_185 | V_128 ) ) | V_55 ;
}
if ( V_45 < V_172 )
V_45 = V_172 ;
V_91 = ( V_91 & V_186 ) | ( V_91 & ~ ( V_119 - V_45 ) ) |
( ( V_153 << V_13 ) & ~ ( V_45 - 1 ) ) ;
if ( F_78 ( V_91 ) && ! V_158 )
V_91 = F_85 ( V_91 ) ;
V_49 = V_140 ;
F_45 () ;
while ( ! F_61 ( V_105 , V_114 ) )
F_62 () ;
V_145 = F_48 ( V_105 [ 0 ] ) ;
V_146 = F_48 ( V_105 [ 1 ] ) ;
if ( F_31 ( V_115 ) ) {
V_145 = F_49 ( V_145 , V_146 ) ;
V_146 = F_63 ( V_146 ) ;
}
if ( ( V_145 & ~ V_114 ) != V_144 [ 0 ] || V_146 != V_144 [ 1 ] ||
V_8 -> V_116 != V_144 [ 2 ] )
goto V_187;
V_144 [ 0 ] = ( V_144 [ 0 ] & ~ V_112 ) | V_111 ;
V_154 = & V_37 -> V_21 . V_154 [ V_150 - V_37 -> V_169 ] ;
F_86 ( V_154 ) ;
V_49 = V_140 ;
if ( F_87 ( V_35 -> V_20 , V_147 ) ) {
F_88 ( V_154 ) ;
goto V_187;
}
V_161 = * V_154 >> V_188 ;
V_91 &= V_161 | ~ ( V_53 | V_54 ) ;
if ( F_48 ( V_105 [ 0 ] ) & V_111 ) {
F_88 ( V_154 ) ;
V_105 [ 0 ] |= F_89 ( V_112 ) ;
F_90 ( V_20 , V_105 , V_106 ) ;
V_91 |= F_48 ( V_105 [ 1 ] ) & ( V_53 | V_54 ) ;
} else {
F_91 ( V_20 , V_8 , V_154 , V_106 , 0 ) ;
}
if ( F_31 ( V_115 ) ) {
V_91 = F_92 ( V_144 [ 0 ] , V_91 ) ;
V_144 [ 0 ] = F_93 ( V_144 [ 0 ] ) ;
}
V_105 [ 1 ] = F_89 ( V_91 ) ;
F_94 () ;
F_95 ( V_105 , V_144 [ 0 ] ) ;
asm volatile("ptesync" : : : "memory");
F_47 () ;
if ( V_6 && F_78 ( V_91 ) )
F_96 ( V_6 ) ;
V_181:
F_97 ( V_35 , V_144 , V_49 ) ;
if ( V_6 ) {
F_98 ( V_155 [ 0 ] ) ;
}
return V_49 ;
V_187:
F_95 ( V_105 , F_48 ( V_105 [ 0 ] ) ) ;
F_47 () ;
goto V_181;
}
static void F_19 ( struct V_20 * V_20 )
{
struct V_189 * V_190 ;
struct V_36 * V_37 ;
int V_191 ;
V_191 = F_99 ( & V_20 -> V_192 ) ;
V_190 = V_189 ( V_20 ) ;
F_100 (memslot, slots) {
memset ( V_37 -> V_21 . V_154 , 0 ,
V_37 -> V_40 * sizeof( * V_37 -> V_21 . V_154 ) ) ;
}
F_101 ( & V_20 -> V_192 , V_191 ) ;
}
static int F_102 ( struct V_20 * V_20 ,
unsigned long V_193 ,
unsigned long V_194 ,
T_6 V_195 )
{
int V_49 ;
int V_196 = 0 ;
struct V_189 * V_190 ;
struct V_36 * V_37 ;
V_190 = V_189 ( V_20 ) ;
F_100 (memslot, slots) {
unsigned long V_197 , V_198 ;
T_7 V_151 , V_199 ;
V_197 = F_103 ( V_193 , V_37 -> V_200 ) ;
V_198 = F_104 ( V_194 , V_37 -> V_200 +
( V_37 -> V_40 << V_13 ) ) ;
if ( V_197 >= V_198 )
continue;
V_151 = F_105 ( V_197 , V_37 ) ;
V_199 = F_105 ( V_198 + V_172 - 1 , V_37 ) ;
for (; V_151 < V_199 ; ++ V_151 ) {
V_49 = V_195 ( V_20 , V_37 , V_151 ) ;
V_196 |= V_49 ;
}
}
return V_196 ;
}
static int F_106 ( struct V_20 * V_20 , unsigned long V_152 ,
T_6 V_195 )
{
return F_102 ( V_20 , V_152 , V_152 + 1 , V_195 ) ;
}
static void F_107 ( struct V_20 * V_20 , unsigned long V_39 ,
unsigned long * V_201 , unsigned long V_151 )
{
T_4 * V_105 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_39 << 4 ) ) ;
struct V_7 * V_8 = V_20 -> V_21 . V_4 . V_8 ;
unsigned long V_202 , V_203 ;
unsigned long V_72 , V_45 , V_161 ;
V_202 = V_8 [ V_39 ] . V_204 ;
if ( V_202 == V_39 ) {
* V_201 &= ~ ( V_205 | V_206 ) ;
} else {
V_203 = V_8 [ V_39 ] . V_207 ;
V_8 [ V_203 ] . V_204 = V_202 ;
V_8 [ V_202 ] . V_207 = V_203 ;
V_8 [ V_39 ] . V_204 = V_8 [ V_39 ] . V_207 = V_39 ;
* V_201 = ( * V_201 & ~ V_206 ) | V_202 ;
}
V_72 = V_8 [ V_39 ] . V_116 ;
V_45 = F_43 ( F_48 ( V_105 [ 0 ] ) , V_72 ) ;
if ( ( F_48 ( V_105 [ 0 ] ) & V_111 ) &&
F_108 ( V_72 , V_45 ) == V_151 ) {
V_105 [ 0 ] |= F_89 ( V_112 ) ;
F_90 ( V_20 , V_105 , V_39 ) ;
V_105 [ 1 ] &= ~ F_89 ( V_186 | V_208 ) ;
V_161 = F_48 ( V_105 [ 1 ] ) & ( V_53 | V_54 ) ;
* V_201 |= V_161 << V_188 ;
if ( V_161 & V_54 )
F_109 ( V_201 , V_45 ) ;
if ( V_161 & ~ V_8 [ V_39 ] . V_116 ) {
V_8 [ V_39 ] . V_116 = V_72 | V_161 ;
F_110 ( V_20 , & V_8 [ V_39 ] ) ;
}
}
}
static int F_111 ( struct V_20 * V_20 , struct V_36 * V_37 ,
unsigned long V_151 )
{
unsigned long V_39 ;
T_4 * V_105 ;
unsigned long * V_201 ;
V_201 = & V_37 -> V_21 . V_154 [ V_151 - V_37 -> V_169 ] ;
for (; ; ) {
F_86 ( V_201 ) ;
if ( ! ( * V_201 & V_205 ) ) {
F_88 ( V_201 ) ;
break;
}
V_39 = * V_201 & V_206 ;
V_105 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_39 << 4 ) ) ;
if ( ! F_61 ( V_105 , V_114 ) ) {
F_88 ( V_201 ) ;
while ( F_48 ( V_105 [ 0 ] ) & V_114 )
F_62 () ;
continue;
}
F_107 ( V_20 , V_39 , V_201 , V_151 ) ;
F_88 ( V_201 ) ;
F_95 ( V_105 , F_48 ( V_105 [ 0 ] ) ) ;
}
return 0 ;
}
int F_112 ( struct V_20 * V_20 , unsigned long V_152 )
{
T_6 V_195 ;
V_195 = F_15 ( V_20 ) ? V_209 : F_111 ;
F_106 ( V_20 , V_152 , V_195 ) ;
return 0 ;
}
int F_113 ( struct V_20 * V_20 , unsigned long V_193 , unsigned long V_194 )
{
T_6 V_195 ;
V_195 = F_15 ( V_20 ) ? V_209 : F_111 ;
F_102 ( V_20 , V_193 , V_194 , V_195 ) ;
return 0 ;
}
void F_114 ( struct V_20 * V_20 ,
struct V_36 * V_37 )
{
unsigned long V_151 ;
unsigned long V_210 ;
unsigned long * V_201 ;
V_151 = V_37 -> V_169 ;
V_201 = V_37 -> V_21 . V_154 ;
for ( V_210 = V_37 -> V_40 ; V_210 ; -- V_210 , ++ V_151 ) {
if ( F_15 ( V_20 ) ) {
V_209 ( V_20 , V_37 , V_151 ) ;
continue;
}
if ( * V_201 & V_205 )
F_111 ( V_20 , V_37 , V_151 ) ;
++ V_201 ;
}
}
static int F_115 ( struct V_20 * V_20 , struct V_36 * V_37 ,
unsigned long V_151 )
{
struct V_7 * V_8 = V_20 -> V_21 . V_4 . V_8 ;
unsigned long V_211 , V_39 , V_202 ;
T_4 * V_105 ;
int V_49 = 0 ;
unsigned long * V_201 ;
V_201 = & V_37 -> V_21 . V_154 [ V_151 - V_37 -> V_169 ] ;
V_212:
F_86 ( V_201 ) ;
if ( * V_201 & V_213 ) {
* V_201 &= ~ V_213 ;
V_49 = 1 ;
}
if ( ! ( * V_201 & V_205 ) ) {
F_88 ( V_201 ) ;
return V_49 ;
}
V_39 = V_211 = * V_201 & V_206 ;
do {
V_105 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_39 << 4 ) ) ;
V_202 = V_8 [ V_39 ] . V_204 ;
if ( ! ( F_48 ( V_105 [ 1 ] ) & V_53 ) )
continue;
if ( ! F_61 ( V_105 , V_114 ) ) {
F_88 ( V_201 ) ;
while ( F_48 ( V_105 [ 0 ] ) & V_114 )
F_62 () ;
goto V_212;
}
if ( ( F_48 ( V_105 [ 0 ] ) & V_111 ) &&
( F_48 ( V_105 [ 1 ] ) & V_53 ) ) {
F_116 ( V_20 , V_105 , V_39 ) ;
if ( ! ( V_8 [ V_39 ] . V_116 & V_53 ) ) {
V_8 [ V_39 ] . V_116 |= V_53 ;
F_110 ( V_20 , & V_8 [ V_39 ] ) ;
}
V_49 = 1 ;
}
F_95 ( V_105 , F_48 ( V_105 [ 0 ] ) ) ;
} while ( ( V_39 = V_202 ) != V_211 );
F_88 ( V_201 ) ;
return V_49 ;
}
int F_117 ( struct V_20 * V_20 , unsigned long V_193 , unsigned long V_194 )
{
T_6 V_195 ;
V_195 = F_15 ( V_20 ) ? V_214 : F_115 ;
return F_102 ( V_20 , V_193 , V_194 , V_195 ) ;
}
static int F_118 ( struct V_20 * V_20 , struct V_36 * V_37 ,
unsigned long V_151 )
{
struct V_7 * V_8 = V_20 -> V_21 . V_4 . V_8 ;
unsigned long V_211 , V_39 , V_202 ;
unsigned long * V_215 ;
int V_49 = 1 ;
unsigned long * V_201 ;
V_201 = & V_37 -> V_21 . V_154 [ V_151 - V_37 -> V_169 ] ;
if ( * V_201 & V_213 )
return 1 ;
F_86 ( V_201 ) ;
if ( * V_201 & V_213 )
goto V_30;
if ( * V_201 & V_205 ) {
V_39 = V_211 = * V_201 & V_206 ;
do {
V_215 = ( unsigned long * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_39 << 4 ) ) ;
V_202 = V_8 [ V_39 ] . V_204 ;
if ( F_48 ( V_215 [ 1 ] ) & V_53 )
goto V_30;
} while ( ( V_39 = V_202 ) != V_211 );
}
V_49 = 0 ;
V_30:
F_88 ( V_201 ) ;
return V_49 ;
}
int F_119 ( struct V_20 * V_20 , unsigned long V_152 )
{
T_6 V_195 ;
V_195 = F_15 ( V_20 ) ? V_216 : F_118 ;
return F_106 ( V_20 , V_152 , V_195 ) ;
}
void F_120 ( struct V_20 * V_20 , unsigned long V_152 , T_5 V_183 )
{
T_6 V_195 ;
V_195 = F_15 ( V_20 ) ? V_209 : F_111 ;
F_106 ( V_20 , V_152 , V_195 ) ;
}
static int V_29 ( struct V_20 * V_20 )
{
return F_18 ( & V_20 -> V_21 . V_29 ) != 0 ;
}
static int F_121 ( struct V_20 * V_20 , unsigned long * V_201 )
{
struct V_7 * V_8 = V_20 -> V_21 . V_4 . V_8 ;
unsigned long V_211 , V_39 , V_202 ;
unsigned long V_210 ;
unsigned long V_90 , V_91 ;
T_4 * V_105 ;
int V_217 = 0 ;
V_212:
F_86 ( V_201 ) ;
if ( * V_201 & V_218 ) {
long V_219 = ( * V_201 & V_220 )
>> V_221 ;
* V_201 &= ~ ( V_218 | V_220 ) ;
V_217 = 1 ;
if ( V_219 > V_13 )
V_217 = 1ul << ( V_219 - V_13 ) ;
}
if ( ! ( * V_201 & V_205 ) ) {
F_88 ( V_201 ) ;
return V_217 ;
}
V_39 = V_211 = * V_201 & V_206 ;
do {
unsigned long V_222 ;
V_105 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_39 << 4 ) ) ;
V_202 = V_8 [ V_39 ] . V_204 ;
V_222 = F_48 ( V_105 [ 1 ] ) ;
if ( ! ( V_222 & V_54 ) &&
( ! F_78 ( V_222 ) || V_29 ( V_20 ) ) )
continue;
if ( ! F_61 ( V_105 , V_114 ) ) {
F_88 ( V_201 ) ;
while ( V_105 [ 0 ] & F_89 ( V_114 ) )
F_62 () ;
goto V_212;
}
if ( ! ( V_105 [ 0 ] & F_89 ( V_111 ) ) ) {
F_95 ( V_105 , F_48 ( V_105 [ 0 ] ) ) ;
continue;
}
V_105 [ 0 ] |= F_89 ( V_112 ) ;
F_90 ( V_20 , V_105 , V_39 ) ;
V_90 = F_48 ( V_105 [ 0 ] ) ;
V_91 = F_48 ( V_105 [ 1 ] ) ;
if ( V_91 & V_54 ) {
V_105 [ 1 ] = F_89 ( V_91 & ~ V_54 ) ;
if ( ! ( V_8 [ V_39 ] . V_116 & V_54 ) ) {
V_8 [ V_39 ] . V_116 |= V_54 ;
F_110 ( V_20 , & V_8 [ V_39 ] ) ;
}
V_210 = F_43 ( V_90 , V_91 ) ;
V_210 = ( V_210 + V_172 - 1 ) >> V_13 ;
if ( V_210 > V_217 )
V_217 = V_210 ;
F_94 () ;
}
V_90 &= ~ V_112 ;
V_90 |= V_111 ;
F_95 ( V_105 , V_90 ) ;
} while ( ( V_39 = V_202 ) != V_211 );
F_88 ( V_201 ) ;
return V_217 ;
}
void F_122 ( struct V_223 * V_224 ,
struct V_36 * V_37 ,
unsigned long * V_225 )
{
unsigned long V_151 ;
if ( ! V_224 -> V_226 || ! V_224 -> V_227 )
return;
V_151 = V_224 -> V_135 >> V_13 ;
if ( V_151 < V_37 -> V_169 ||
V_151 >= V_37 -> V_169 + V_37 -> V_40 )
return;
V_224 -> V_226 = false ;
if ( V_225 )
F_123 ( V_151 - V_37 -> V_169 , V_225 ) ;
}
long F_124 ( struct V_20 * V_20 ,
struct V_36 * V_37 , unsigned long * V_225 )
{
unsigned long V_39 , V_202 ;
unsigned long * V_201 ;
F_45 () ;
V_201 = V_37 -> V_21 . V_154 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; ++ V_39 ) {
int V_40 = F_121 ( V_20 , V_201 ) ;
if ( V_40 && V_225 )
for ( V_202 = V_39 ; V_40 ; ++ V_202 , -- V_40 )
F_123 ( V_202 , V_225 ) ;
++ V_201 ;
}
F_47 () ;
return 0 ;
}
void * F_125 ( struct V_20 * V_20 , unsigned long V_135 ,
unsigned long * V_228 )
{
struct V_36 * V_37 ;
unsigned long V_151 = V_135 >> V_13 ;
struct V_6 * V_6 , * V_155 [ 1 ] ;
int V_40 ;
unsigned long V_152 , V_229 ;
int V_191 ;
V_191 = F_99 ( & V_20 -> V_192 ) ;
V_37 = F_64 ( V_20 , V_151 ) ;
if ( ! V_37 || ( V_37 -> V_69 & V_168 ) )
goto V_25;
V_152 = F_67 ( V_37 , V_151 ) ;
V_40 = F_68 ( V_152 , 1 , 1 , V_155 ) ;
if ( V_40 < 1 )
goto V_25;
V_6 = V_155 [ 0 ] ;
F_101 ( & V_20 -> V_192 , V_191 ) ;
V_229 = V_135 & ( V_172 - 1 ) ;
if ( V_228 )
* V_228 = V_172 - V_229 ;
return F_126 ( V_6 ) + V_229 ;
V_25:
F_101 ( & V_20 -> V_192 , V_191 ) ;
return NULL ;
}
void F_127 ( struct V_20 * V_20 , void * V_230 , unsigned long V_135 ,
bool V_226 )
{
struct V_6 * V_6 = F_24 ( V_230 ) ;
struct V_36 * V_37 ;
unsigned long V_151 ;
unsigned long * V_154 ;
int V_191 ;
F_98 ( V_6 ) ;
if ( ! V_226 )
return;
V_151 = V_135 >> V_13 ;
V_191 = F_99 ( & V_20 -> V_192 ) ;
V_37 = F_64 ( V_20 , V_151 ) ;
if ( V_37 ) {
if ( ! F_15 ( V_20 ) ) {
V_154 = & V_37 -> V_21 . V_154 [ V_151 - V_37 -> V_169 ] ;
F_86 ( V_154 ) ;
* V_154 |= V_218 ;
F_88 ( V_154 ) ;
} else if ( V_37 -> V_231 ) {
F_128 ( V_20 , V_151 ) ;
}
}
F_101 ( & V_20 -> V_192 , V_191 ) ;
}
static int F_129 ( struct V_232 * V_233 )
{
int V_234 ;
V_234 = F_1 ( & V_233 -> V_4 , V_233 -> V_3 ) ;
if ( V_234 < 0 )
return V_234 ;
F_130 ( V_233 , L_5 ,
V_233 -> V_4 . V_19 ) ;
return 0 ;
}
static unsigned long F_131 ( struct V_232 * V_233 ,
unsigned long V_235 )
{
struct V_20 * V_20 = V_233 -> V_20 ;
struct V_1 * V_236 = & V_20 -> V_21 . V_4 ;
struct V_1 * V_237 = & V_233 -> V_4 ;
unsigned long V_238 = ( 1ULL << ( V_236 -> V_3 - 7 ) ) - 1 ;
unsigned long V_239 = ( 1ULL << ( V_237 -> V_3 - 7 ) ) - 1 ;
T_4 * V_105 , * V_240 ;
unsigned long V_241 , V_164 , V_116 ;
int V_49 ;
struct V_7 * V_8 ;
unsigned long V_242 , V_45 , V_243 , V_244 , V_44 ;
unsigned long V_245 , V_246 , V_247 ;
V_105 = ( T_4 * ) ( V_236 -> V_19 + ( V_235 << 4 ) ) ;
V_241 = F_48 ( V_105 [ 0 ] ) ;
if ( ! ( V_241 & V_111 ) && ! ( V_241 & V_112 ) )
return 0 ;
while ( ! F_61 ( V_105 , V_114 ) )
F_62 () ;
V_241 = F_48 ( V_105 [ 0 ] ) ;
V_49 = 0 ;
if ( ! ( V_241 & V_111 ) && ! ( V_241 & V_112 ) )
goto V_30;
V_8 = & V_236 -> V_8 [ V_235 ] ;
V_116 = V_8 -> V_116 ;
V_49 = - V_248 ;
V_242 = F_43 ( V_241 , V_116 ) ;
if ( ! V_242 )
goto V_30;
if ( V_241 & V_111 ) {
unsigned long V_151 = F_108 ( V_116 , V_242 ) ;
int V_191 = F_99 ( & V_20 -> V_192 ) ;
struct V_36 * V_37 =
F_132 ( V_189 ( V_20 ) , V_151 ) ;
if ( V_37 ) {
unsigned long * V_201 ;
V_201 = & V_37 -> V_21 . V_154 [ V_151 - V_37 -> V_169 ] ;
F_86 ( V_201 ) ;
F_107 ( V_20 , V_235 , V_201 , V_151 ) ;
F_88 ( V_201 ) ;
}
F_101 ( & V_20 -> V_192 , V_191 ) ;
}
V_241 = F_48 ( V_105 [ 0 ] ) ;
F_133 ( V_241 & V_111 ) ;
F_133 ( ! ( V_241 & V_112 ) ) ;
V_49 = 0 ;
if ( ! ( V_241 & V_52 ) )
goto V_30;
V_164 = F_48 ( V_105 [ 1 ] ) ;
V_45 = F_134 ( V_241 , V_164 ) ;
V_243 = F_135 ( V_241 ) & ~ ( ( V_45 - 1 ) >> 23 ) ;
V_244 = V_235 / V_249 ;
if ( V_241 & V_250 )
V_244 = ~ V_244 ;
if ( ! ( V_241 & V_50 ) ) {
unsigned long V_229 , V_251 ;
V_229 = ( V_243 & 0x1f ) << 23 ;
V_251 = V_243 >> 5 ;
if ( V_45 < ( 1ULL << 23 ) )
V_229 |= ( ( V_251 ^ V_244 ) & V_238 ) * V_45 ;
V_44 = V_251 ^ ( V_229 / V_45 ) ;
} else {
unsigned long V_229 , V_251 ;
V_229 = ( V_243 & 0x1ffff ) << 23 ;
V_251 = V_243 >> 17 ;
if ( V_45 < ( 1ULL << 23 ) )
V_229 |= ( ( V_251 ^ ( V_251 << 25 ) ^ V_244 ) & V_238 ) * V_45 ;
V_44 = V_251 ^ ( V_251 << 25 ) ^ ( V_229 / V_45 ) ;
}
V_246 = V_44 & V_239 ;
if ( V_241 & V_250 ) {
F_133 ( ~ V_244 != ( V_44 & V_238 ) ) ;
V_246 = ~ V_246 ;
} else {
F_133 ( V_244 != ( V_44 & V_238 ) ) ;
}
V_245 = V_246 * V_249 + ( V_235 % V_249 ) ;
V_240 = ( T_4 * ) ( V_237 -> V_19 + ( V_245 << 4 ) ) ;
V_247 = F_48 ( V_240 [ 0 ] ) ;
if ( V_247 & ( V_111 | V_112 ) ) {
F_133 ( V_237 -> V_3 >= V_236 -> V_3 ) ;
if ( V_247 & V_52 ) {
if ( V_241 & V_52 )
V_49 = - V_252 ;
goto V_30;
}
}
V_240 [ 1 ] = F_89 ( V_164 ) ;
V_237 -> V_8 [ V_245 ] . V_116 = V_116 ;
V_240 [ 0 ] = F_89 ( V_241 ) ;
F_50 ( V_240 , V_241 ) ;
V_30:
F_50 ( V_105 , V_241 ) ;
return V_49 ;
}
static int F_136 ( struct V_232 * V_233 )
{
struct V_20 * V_20 = V_233 -> V_20 ;
unsigned long V_39 ;
int V_234 ;
if ( F_31 ( V_115 ) )
return - V_248 ;
for ( V_39 = 0 ; V_39 < F_137 ( & V_20 -> V_21 . V_4 ) ; V_39 ++ ) {
V_234 = F_131 ( V_233 , V_39 ) ;
if ( V_234 != 0 )
return V_234 ;
}
return 0 ;
}
static void F_138 ( struct V_232 * V_233 )
{
struct V_20 * V_20 = V_233 -> V_20 ;
struct V_1 V_253 ;
F_130 ( V_233 , L_6 ) ;
F_139 ( & V_20 -> V_254 ) ;
asm volatile("ptesync" : : : "memory");
V_253 = V_20 -> V_21 . V_4 ;
F_10 ( V_20 , & V_233 -> V_4 ) ;
V_233 -> V_4 = V_253 ;
F_140 ( & V_20 -> V_254 ) ;
F_141 ( & V_20 -> V_192 ) ;
F_130 ( V_233 , L_7 ) ;
}
static void F_142 ( struct V_20 * V_20 , struct V_232 * V_233 )
{
F_133 ( V_20 -> V_21 . V_255 != V_233 ) ;
if ( ! V_233 )
return;
if ( V_233 -> V_4 . V_19 )
F_21 ( & V_233 -> V_4 ) ;
V_20 -> V_21 . V_255 = NULL ;
F_143 ( V_233 ) ;
}
static void F_144 ( struct V_256 * V_257 )
{
struct V_232 * V_233 = F_145 ( V_257 ,
struct V_232 ,
V_257 ) ;
struct V_20 * V_20 = V_233 -> V_20 ;
int V_25 ;
F_130 ( V_233 , L_8 ,
V_233 -> V_3 ) ;
V_25 = F_129 ( V_233 ) ;
F_16 ( & V_20 -> V_27 ) ;
V_233 -> error = V_25 ;
V_233 -> V_258 = true ;
F_22 ( & V_20 -> V_27 ) ;
}
long F_146 ( struct V_20 * V_20 ,
struct V_259 * V_260 )
{
unsigned long V_69 = V_260 -> V_69 ;
unsigned long V_261 = V_260 -> V_261 ;
struct V_232 * V_233 ;
int V_49 ;
if ( V_69 != 0 )
return - V_12 ;
if ( V_261 && ( ( V_261 < 18 ) || ( V_261 > 46 ) ) )
return - V_12 ;
F_16 ( & V_20 -> V_27 ) ;
V_233 = V_20 -> V_21 . V_255 ;
if ( V_233 ) {
if ( V_233 -> V_3 == V_261 ) {
if ( V_233 -> V_258 ) {
V_49 = V_233 -> error ;
if ( V_49 != 0 )
F_142 ( V_20 , V_233 ) ;
} else {
V_49 = 100 ;
}
goto V_30;
}
F_142 ( V_20 , V_233 ) ;
}
V_49 = 0 ;
if ( ! V_261 )
goto V_30;
V_233 = F_147 ( sizeof( * V_233 ) , V_14 ) ;
if ( ! V_233 ) {
V_49 = - V_18 ;
goto V_30;
}
V_233 -> V_3 = V_261 ;
V_233 -> V_20 = V_20 ;
F_148 ( & V_233 -> V_257 , F_144 ) ;
V_20 -> V_21 . V_255 = V_233 ;
F_149 ( & V_233 -> V_257 ) ;
V_49 = 100 ;
V_30:
F_22 ( & V_20 -> V_27 ) ;
return V_49 ;
}
static void F_150 ( void * V_262 )
{
}
long F_151 ( struct V_20 * V_20 ,
struct V_259 * V_260 )
{
unsigned long V_69 = V_260 -> V_69 ;
unsigned long V_261 = V_260 -> V_261 ;
struct V_232 * V_233 ;
long V_49 ;
if ( V_69 != 0 )
return - V_12 ;
if ( V_261 && ( ( V_261 < 18 ) || ( V_261 > 46 ) ) )
return - V_12 ;
F_16 ( & V_20 -> V_27 ) ;
V_233 = V_20 -> V_21 . V_255 ;
V_49 = - V_248 ;
if ( F_152 ( ! V_20 -> V_21 . V_28 ) )
goto V_263;
V_20 -> V_21 . V_28 = 0 ;
F_17 () ;
F_153 ( F_150 , NULL , 1 ) ;
V_49 = - V_264 ;
if ( ! V_233 || ( V_233 -> V_3 != V_261 ) )
goto V_30;
V_49 = - V_26 ;
if ( ! V_233 -> V_258 )
goto V_30;
V_49 = V_233 -> error ;
if ( V_49 != 0 )
goto V_30;
V_49 = F_136 ( V_233 ) ;
if ( V_49 != 0 )
goto V_30;
F_138 ( V_233 ) ;
V_30:
V_20 -> V_21 . V_28 = 1 ;
F_17 () ;
V_263:
F_142 ( V_20 , V_233 ) ;
F_22 ( & V_20 -> V_27 ) ;
return V_49 ;
}
static int F_154 ( struct V_7 * V_265 , T_4 * V_266 )
{
unsigned long V_267 ;
if ( V_265 -> V_116 & V_268 )
return 1 ;
V_267 = ~ V_265 -> V_116 & ( V_53 | V_54 ) ;
if ( ( F_48 ( V_266 [ 0 ] ) & V_111 ) &&
( F_48 ( V_266 [ 1 ] ) & V_267 ) )
return 1 ;
return 0 ;
}
static long F_155 ( unsigned long V_69 , T_4 * V_266 ,
unsigned long * V_144 , struct V_7 * V_265 ,
int V_269 , int V_270 )
{
unsigned long V_90 , V_91 , V_271 ;
unsigned long V_267 ;
int V_272 = 1 ;
int V_273 , V_226 ;
V_226 = F_154 ( V_265 , V_266 ) ;
if ( ! V_270 && ! V_226 )
return 0 ;
V_273 = 0 ;
if ( F_48 ( V_266 [ 0 ] ) & ( V_111 | V_112 ) ) {
V_273 = 1 ;
if ( ( V_69 & V_274 ) &&
! ( F_48 ( V_266 [ 0 ] ) & V_52 ) )
V_273 = 0 ;
}
if ( V_273 != V_269 )
return 0 ;
V_90 = V_91 = 0 ;
if ( V_273 || V_226 ) {
F_45 () ;
while ( ! F_61 ( V_266 , V_114 ) )
F_62 () ;
V_90 = F_48 ( V_266 [ 0 ] ) ;
V_271 = F_48 ( V_266 [ 1 ] ) ;
if ( F_31 ( V_115 ) ) {
V_90 = F_49 ( V_90 , V_271 ) ;
V_271 = F_63 ( V_271 ) ;
}
V_273 = ! ! ( V_90 & V_111 ) ;
V_226 = ! ! ( V_265 -> V_116 & V_268 ) ;
V_267 = ~ V_265 -> V_116 & ( V_53 | V_54 ) ;
if ( V_273 && ( V_267 & V_271 ) ) {
V_265 -> V_116 |= ( V_271 &
( V_53 | V_54 ) ) | V_268 ;
V_226 = 1 ;
}
if ( V_90 & V_112 ) {
V_90 &= ~ V_112 ;
V_90 |= V_111 ;
V_273 = 1 ;
}
if ( ( V_69 & V_274 ) && ! ( V_90 & V_52 ) )
V_273 = 0 ;
V_91 = V_265 -> V_116 ;
if ( V_273 == V_269 && V_226 ) {
V_91 &= ~ V_268 ;
V_265 -> V_116 = V_91 ;
}
F_50 ( V_266 , F_48 ( V_266 [ 0 ] ) ) ;
F_47 () ;
if ( ! ( V_273 == V_269 && ( V_270 || V_226 ) ) )
V_272 = 0 ;
}
V_144 [ 0 ] = F_89 ( V_90 ) ;
V_144 [ 1 ] = F_89 ( V_91 ) ;
return V_272 ;
}
static T_8 F_156 ( struct V_275 * V_275 , char T_9 * V_276 ,
T_10 V_277 , T_11 * V_278 )
{
struct V_279 * V_280 = V_275 -> V_281 ;
struct V_20 * V_20 = V_280 -> V_20 ;
struct V_282 V_283 ;
T_4 * V_266 ;
struct V_7 * V_265 ;
unsigned long V_39 , V_284 , V_285 ;
unsigned long T_9 * V_286 ;
struct V_282 T_9 * V_287 ;
unsigned long V_69 ;
int V_270 ;
unsigned long V_144 [ 2 ] ;
if ( ! F_157 ( V_288 , V_276 , V_277 ) )
return - V_170 ;
V_270 = V_280 -> V_270 ;
V_69 = V_280 -> V_69 ;
V_39 = V_280 -> V_106 ;
V_266 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_39 * V_289 ) ) ;
V_265 = V_20 -> V_21 . V_4 . V_8 + V_39 ;
V_286 = ( unsigned long T_9 * ) V_276 ;
V_284 = 0 ;
while ( V_284 + sizeof( V_283 ) + V_289 < V_277 ) {
V_287 = (struct V_282 T_9 * ) V_276 ;
V_283 . V_290 = 0 ;
V_283 . V_291 = 0 ;
V_285 = V_284 ;
V_284 += sizeof( V_283 ) ;
V_286 = ( unsigned long T_9 * ) ( V_276 + sizeof( V_283 ) ) ;
if ( ! V_270 ) {
while ( V_39 < F_137 ( & V_20 -> V_21 . V_4 ) &&
! F_154 ( V_265 , V_266 ) ) {
++ V_39 ;
V_266 += 2 ;
++ V_265 ;
}
}
V_283 . V_106 = V_39 ;
while ( V_39 < F_137 ( & V_20 -> V_21 . V_4 ) &&
V_283 . V_290 < 0xffff &&
V_284 + V_289 < V_277 &&
F_155 ( V_69 , V_266 , V_144 , V_265 , 1 , V_270 ) ) {
++ V_283 . V_290 ;
if ( F_158 ( V_144 [ 0 ] , V_286 ) ||
F_158 ( V_144 [ 1 ] , V_286 + 1 ) )
return - V_170 ;
V_284 += V_289 ;
V_286 += 2 ;
++ V_39 ;
V_266 += 2 ;
++ V_265 ;
}
while ( V_39 < F_137 ( & V_20 -> V_21 . V_4 ) &&
V_283 . V_291 < 0xffff &&
F_155 ( V_69 , V_266 , V_144 , V_265 , 0 , V_270 ) ) {
++ V_283 . V_291 ;
++ V_39 ;
V_266 += 2 ;
++ V_265 ;
}
if ( V_283 . V_290 || V_283 . V_291 ) {
if ( F_159 ( V_287 , & V_283 , sizeof( V_283 ) ) )
return - V_170 ;
V_285 = V_284 ;
V_276 = ( char T_9 * ) V_286 ;
} else {
V_284 = V_285 ;
}
if ( V_39 >= F_137 ( & V_20 -> V_21 . V_4 ) ) {
V_39 = 0 ;
V_280 -> V_270 = 0 ;
break;
}
}
V_280 -> V_106 = V_39 ;
return V_284 ;
}
static T_8 F_160 ( struct V_275 * V_275 , const char T_9 * V_276 ,
T_10 V_277 , T_11 * V_278 )
{
struct V_279 * V_280 = V_275 -> V_281 ;
struct V_20 * V_20 = V_280 -> V_20 ;
struct V_282 V_283 ;
unsigned long V_39 , V_202 ;
unsigned long V_90 , V_91 ;
unsigned long T_9 * V_286 ;
T_4 * V_266 ;
unsigned long V_292 [ 2 ] ;
T_8 V_284 ;
long int V_25 , V_49 ;
int V_293 ;
if ( ! F_157 ( V_294 , V_276 , V_277 ) )
return - V_170 ;
F_16 ( & V_20 -> V_27 ) ;
V_293 = V_20 -> V_21 . V_28 ;
if ( V_293 ) {
V_20 -> V_21 . V_28 = 0 ;
F_17 () ;
if ( F_18 ( & V_20 -> V_21 . V_29 ) ) {
V_20 -> V_21 . V_28 = 1 ;
F_22 ( & V_20 -> V_27 ) ;
return - V_26 ;
}
}
V_25 = 0 ;
for ( V_284 = 0 ; V_284 + sizeof( V_283 ) <= V_277 ; ) {
V_25 = - V_170 ;
if ( F_161 ( & V_283 , V_276 , sizeof( V_283 ) ) )
break;
V_25 = 0 ;
if ( V_284 + V_283 . V_290 * V_289 > V_277 )
break;
V_284 += sizeof( V_283 ) ;
V_276 += sizeof( V_283 ) ;
V_25 = - V_12 ;
V_39 = V_283 . V_106 ;
if ( V_39 >= F_137 ( & V_20 -> V_21 . V_4 ) ||
V_39 + V_283 . V_290 + V_283 . V_291 > F_137 ( & V_20 -> V_21 . V_4 ) )
break;
V_266 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_39 * V_289 ) ) ;
V_286 = ( unsigned long T_9 * ) V_276 ;
for ( V_202 = 0 ; V_202 < V_283 . V_290 ; ++ V_202 ) {
T_4 V_295 ;
T_4 V_296 ;
V_25 = - V_170 ;
if ( F_162 ( V_295 , V_286 ) ||
F_162 ( V_296 , V_286 + 1 ) )
goto V_30;
V_90 = F_48 ( V_295 ) ;
V_91 = F_48 ( V_296 ) ;
V_25 = - V_12 ;
if ( ! ( V_90 & V_111 ) )
goto V_30;
V_286 += 2 ;
V_284 += V_289 ;
if ( F_48 ( V_266 [ 0 ] ) & ( V_111 | V_112 ) )
F_163 ( V_20 , 0 , V_39 , 0 , V_292 ) ;
V_25 = - V_248 ;
V_49 = F_29 ( V_20 , V_57 , V_39 , V_90 , V_91 ,
V_292 ) ;
if ( V_49 != V_58 ) {
F_7 ( L_9
L_10 , V_49 , V_39 , V_90 , V_91 ) ;
goto V_30;
}
if ( ! V_293 && F_164 ( V_90 ) ) {
unsigned long V_45 = F_134 ( V_90 , V_91 ) ;
unsigned long V_297 = F_165 ( V_45 ) ;
unsigned long V_298 ;
V_20 -> V_21 . V_110 = V_297 | V_87 |
( V_51 << V_299 ) ;
V_298 = V_297 << ( V_300 - 4 ) ;
F_166 ( V_20 , V_298 , V_301 ) ;
V_293 = 1 ;
}
++ V_39 ;
V_266 += 2 ;
}
for ( V_202 = 0 ; V_202 < V_283 . V_291 ; ++ V_202 ) {
if ( F_48 ( V_266 [ 0 ] ) & ( V_111 | V_112 ) )
F_163 ( V_20 , 0 , V_39 , 0 , V_292 ) ;
++ V_39 ;
V_266 += 2 ;
}
V_25 = 0 ;
}
V_30:
F_167 () ;
V_20 -> V_21 . V_28 = V_293 ;
F_22 ( & V_20 -> V_27 ) ;
if ( V_25 )
return V_25 ;
return V_284 ;
}
static int F_168 ( struct V_302 * V_302 , struct V_275 * V_303 )
{
struct V_279 * V_280 = V_303 -> V_281 ;
V_303 -> V_281 = NULL ;
if ( ! ( V_280 -> V_69 & V_304 ) )
F_169 ( & V_280 -> V_20 -> V_21 . V_305 ) ;
F_170 ( V_280 -> V_20 ) ;
F_143 ( V_280 ) ;
return 0 ;
}
int F_171 ( struct V_20 * V_20 , struct V_306 * V_307 )
{
int V_49 ;
struct V_279 * V_280 ;
int V_308 ;
if ( V_307 -> V_69 & ~ ( V_274 | V_304 ) )
return - V_12 ;
V_280 = F_147 ( sizeof( * V_280 ) , V_14 ) ;
if ( ! V_280 )
return - V_18 ;
F_172 ( V_20 ) ;
V_280 -> V_20 = V_20 ;
V_280 -> V_106 = V_307 -> V_309 ;
V_280 -> V_69 = V_307 -> V_69 ;
V_280 -> V_270 = 1 ;
V_308 = ( V_307 -> V_69 & V_304 ) ? V_310 : V_311 ;
V_49 = F_173 ( L_11 , & V_312 , V_280 , V_308 | V_313 ) ;
if ( V_49 < 0 ) {
F_170 ( V_20 ) ;
return V_49 ;
}
if ( V_308 == V_311 ) {
F_16 ( & V_20 -> V_314 ) ;
F_174 ( & V_20 -> V_21 . V_305 ) ;
F_141 ( & V_20 -> V_192 ) ;
F_22 ( & V_20 -> V_314 ) ;
}
return V_49 ;
}
static int F_175 ( struct V_302 * V_302 , struct V_275 * V_275 )
{
struct V_20 * V_20 = V_302 -> V_315 ;
struct V_316 * V_317 ;
V_317 = F_147 ( sizeof( * V_317 ) , V_14 ) ;
if ( ! V_317 )
return - V_18 ;
F_172 ( V_20 ) ;
V_317 -> V_20 = V_20 ;
F_176 ( & V_317 -> V_318 ) ;
V_275 -> V_281 = V_317 ;
return F_177 ( V_302 , V_275 ) ;
}
static int F_178 ( struct V_302 * V_302 , struct V_275 * V_275 )
{
struct V_316 * V_317 = V_275 -> V_281 ;
F_170 ( V_317 -> V_20 ) ;
F_143 ( V_317 ) ;
return 0 ;
}
static T_8 F_179 ( struct V_275 * V_275 , char T_9 * V_276 ,
T_10 V_319 , T_11 * V_278 )
{
struct V_316 * V_317 = V_275 -> V_281 ;
T_8 V_49 , V_91 ;
unsigned long V_39 , V_210 ;
unsigned long V_90 , V_271 , V_104 ;
struct V_20 * V_20 ;
T_4 * V_266 ;
V_49 = F_180 ( & V_317 -> V_318 ) ;
if ( V_49 )
return V_49 ;
if ( V_317 -> V_320 ) {
V_210 = V_317 -> V_320 ;
if ( V_210 > V_319 )
V_210 = V_319 ;
V_91 = F_181 ( V_276 , V_317 -> V_276 + V_317 -> V_321 , V_210 ) ;
V_210 -= V_91 ;
V_317 -> V_320 -= V_210 ;
V_317 -> V_321 += V_210 ;
V_276 += V_210 ;
V_319 -= V_210 ;
V_49 = V_210 ;
if ( V_91 ) {
if ( ! V_210 )
V_49 = - V_170 ;
goto V_30;
}
}
V_20 = V_317 -> V_20 ;
V_39 = V_317 -> V_322 ;
V_266 = ( T_4 * ) ( V_20 -> V_21 . V_4 . V_19 + ( V_39 * V_289 ) ) ;
for (; V_319 != 0 && V_39 < F_137 ( & V_20 -> V_21 . V_4 ) ;
++ V_39 , V_266 += 2 ) {
if ( ! ( F_48 ( V_266 [ 0 ] ) & ( V_111 | V_112 ) ) )
continue;
F_45 () ;
while ( ! F_61 ( V_266 , V_114 ) )
F_62 () ;
V_90 = F_48 ( V_266 [ 0 ] ) & ~ V_114 ;
V_271 = F_48 ( V_266 [ 1 ] ) ;
V_104 = V_20 -> V_21 . V_4 . V_8 [ V_39 ] . V_116 ;
F_50 ( V_266 , V_90 ) ;
F_47 () ;
if ( ! ( V_90 & ( V_111 | V_112 ) ) )
continue;
V_210 = F_182 ( V_317 -> V_276 , sizeof( V_317 -> V_276 ) ,
L_12 ,
V_39 , V_90 , V_271 , V_104 ) ;
V_317 -> V_320 = V_210 ;
if ( V_210 > V_319 )
V_210 = V_319 ;
V_91 = F_181 ( V_276 , V_317 -> V_276 , V_210 ) ;
V_210 -= V_91 ;
V_317 -> V_320 -= V_210 ;
V_317 -> V_321 = V_210 ;
V_276 += V_210 ;
V_319 -= V_210 ;
V_49 += V_210 ;
if ( V_91 ) {
if ( ! V_49 )
V_49 = - V_170 ;
goto V_30;
}
}
V_317 -> V_322 = V_39 ;
V_30:
F_22 ( & V_317 -> V_318 ) ;
return V_49 ;
}
static T_8 F_183 ( struct V_275 * V_275 , const char T_9 * V_276 ,
T_10 V_319 , T_11 * V_278 )
{
return - V_323 ;
}
void F_184 ( struct V_20 * V_20 )
{
V_20 -> V_21 . V_324 = F_185 ( L_13 , 0400 ,
V_20 -> V_21 . V_325 , V_20 ,
& V_326 ) ;
}
void F_186 ( struct V_34 * V_35 )
{
struct V_327 * V_328 = & V_35 -> V_21 . V_328 ;
V_35 -> V_21 . V_82 = 32 ;
if ( F_15 ( V_35 -> V_20 ) )
V_328 -> V_329 = V_330 ;
else
V_328 -> V_329 = F_44 ;
V_328 -> V_331 = F_35 ;
V_35 -> V_21 . V_332 |= V_333 ;
}
