bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 . V_3 . V_5 . V_6 ==
V_7 ) ;
}
void F_2 ( void )
{
F_3 () ;
V_8 = 1 ;
V_9 = F_4 ( L_1 , sizeof( struct V_10 ) ,
0 , 0 , NULL ) ;
}
void F_5 ( void )
{
if ( ! V_8 )
return;
F_6 () ;
F_7 ( V_9 ) ;
}
static void F_8 ( unsigned long V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 ;
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
}
bool F_11 ( struct V_12 * V_13 ,
struct V_23 * V_24 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_25 = 0 ;
struct V_26 V_27 ;
if ( ! ( V_17 -> V_28 == V_24 -> V_28 &&
memcmp ( V_17 -> V_29 , V_24 -> V_29 , V_24 -> V_28 ) == 0 &&
( V_17 -> V_30 == V_24 -> V_31 -> V_32 ) &&
( V_17 -> V_33 == V_24 -> V_31 -> V_34 ) &&
( V_17 -> V_35 == V_24 -> V_31 -> V_36 ) &&
( V_17 -> V_37 == V_24 -> V_31 -> V_38 ) &&
( V_17 -> V_39 == V_24 -> V_31 -> V_40 ) ) )
return false ;
F_12 ( V_13 , V_24 , F_13 ( V_13 ) ,
& V_25 ) ;
if ( V_13 -> V_41 . V_42 . V_25 != V_25 )
return false ;
F_14 ( V_13 -> V_41 . V_42 . V_43 . V_44 ,
V_24 -> V_45 , & V_27 ) ;
if ( ! F_15 ( & V_13 -> V_41 . V_42 . V_43 ,
& V_27 ) )
return false ;
return true ;
}
bool F_16 ( struct V_23 * V_24 )
{
return ( V_24 -> V_31 -> V_46 &
V_47 ) != 0 ;
}
T_1 F_17 ( struct V_12 * V_13 )
{
bool V_48 ;
T_1 V_49 = 0 ;
V_48 = F_18 ( V_13 ) ;
if ( V_48 != V_13 -> V_3 . V_18 . V_50 ) {
V_13 -> V_3 . V_18 . V_50 = V_48 ;
V_49 = V_51 ;
}
return V_49 ;
}
void F_19 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
T_1 V_49 ;
V_49 = F_17 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_54 ) {
V_49 |= F_20 ( V_53 ) ;
F_21 ( & V_53 -> V_55 ) ;
}
if ( V_49 )
F_22 ( V_13 , V_49 ) ;
}
int F_23 ( struct V_12 * V_13 )
{
int V_56 ;
V_13 -> V_3 . V_18 . V_57 = F_24 ( sizeof( struct V_58 ) , V_59 ) ;
if ( ! V_13 -> V_3 . V_18 . V_57 )
return - V_60 ;
V_13 -> V_3 . V_18 . V_57 -> V_61 = V_62 - 1 ;
for ( V_56 = 0 ; V_56 < V_62 ; V_56 ++ )
F_25 ( & V_13 -> V_3 . V_18 . V_57 -> V_63 [ V_56 ] ) ;
return 0 ;
}
void F_26 ( struct V_12 * V_13 )
{
struct V_58 * V_57 = V_13 -> V_3 . V_18 . V_57 ;
struct V_10 * V_64 , * V_65 ;
int V_56 ;
if ( ! V_13 -> V_3 . V_18 . V_57 )
return;
for ( V_56 = 0 ; V_56 < V_62 ; V_56 ++ ) {
F_27 (p, n, &rmc->bucket[i], list) {
F_28 ( & V_64 -> V_66 ) ;
F_29 ( V_9 , V_64 ) ;
}
}
F_30 ( V_57 ) ;
V_13 -> V_3 . V_18 . V_57 = NULL ;
}
int F_31 ( struct V_12 * V_13 ,
const T_2 * V_67 , struct V_68 * V_69 )
{
struct V_58 * V_57 = V_13 -> V_3 . V_18 . V_57 ;
T_1 V_70 = 0 ;
int V_71 = 0 ;
T_2 V_72 ;
struct V_10 * V_64 , * V_65 ;
memcpy ( & V_70 , & V_69 -> V_70 , sizeof( V_69 -> V_70 ) ) ;
V_72 = F_32 ( V_69 -> V_70 ) & V_57 -> V_61 ;
F_27 (p, n, &rmc->bucket[idx], list) {
++ V_71 ;
if ( F_33 ( V_73 , V_64 -> V_74 ) ||
V_71 == V_75 ) {
F_28 ( & V_64 -> V_66 ) ;
F_29 ( V_9 , V_64 ) ;
-- V_71 ;
} else if ( ( V_70 == V_64 -> V_70 ) && F_34 ( V_67 , V_64 -> V_67 ) )
return - 1 ;
}
V_64 = F_35 ( V_9 , V_76 ) ;
if ( ! V_64 )
return 0 ;
V_64 -> V_70 = V_70 ;
V_64 -> V_74 = V_73 + V_77 ;
memcpy ( V_64 -> V_67 , V_67 , V_78 ) ;
F_36 ( & V_64 -> V_66 , & V_57 -> V_63 [ V_72 ] ) ;
return 0 ;
}
int F_37 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_81 , V_82 ;
T_2 V_83 = sizeof( struct V_84 ) ;
if ( F_38 ( V_80 ) < 2 + V_83 )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + V_83 ) ;
* V_81 ++ = V_85 ;
* V_81 ++ = V_83 ;
V_17 -> V_86 = V_81 - V_80 -> V_11 ;
* V_81 ++ = V_17 -> V_30 ;
* V_81 ++ = V_17 -> V_33 ;
* V_81 ++ = V_17 -> V_35 ;
* V_81 ++ = V_17 -> V_37 ;
* V_81 ++ = V_17 -> V_39 ;
V_82 = F_40 ( & V_17 -> V_87 ) ;
V_82 = F_41 ( int , V_82 , V_88 ) ;
* V_81 ++ = V_82 << 1 ;
* V_81 = 0x00 ;
* V_81 |= V_17 -> V_89 . V_90 ?
V_91 : 0x00 ;
* V_81 |= V_17 -> V_50 ?
V_47 : 0x00 ;
* V_81 |= V_17 -> V_92 ?
V_93 : 0x00 ;
* V_81 ++ |= V_17 -> V_94 ?
V_95 : 0x00 ;
* V_81 ++ = 0x00 ;
return 0 ;
}
int F_42 ( struct V_12 * V_13 , struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_81 ;
if ( F_38 ( V_80 ) < 2 + V_17 -> V_28 )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + V_17 -> V_28 ) ;
* V_81 ++ = V_96 ;
* V_81 ++ = V_17 -> V_28 ;
if ( V_17 -> V_28 )
memcpy ( V_81 , V_17 -> V_29 , V_17 -> V_28 ) ;
return 0 ;
}
static int F_43 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_81 ;
if ( V_17 -> V_97 == 0 &&
V_17 -> V_92 == 0 &&
V_17 -> V_98 == V_99 )
return 0 ;
if ( F_38 ( V_80 ) < 4 )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + 2 ) ;
* V_81 ++ = V_100 ;
* V_81 ++ = 2 ;
F_44 ( V_17 -> V_89 . V_101 , V_81 ) ;
return 0 ;
}
int F_45 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_102 , V_103 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_104 )
return 0 ;
V_102 = F_46 ( V_17 -> V_24 , V_17 -> V_104 , 0 ) ;
if ( V_102 ) {
V_103 = V_17 -> V_104 - V_102 ;
V_11 = V_17 -> V_24 + V_102 ;
if ( F_38 ( V_80 ) < V_103 )
return - V_60 ;
memcpy ( F_39 ( V_80 , V_103 ) , V_11 , V_103 ) ;
}
return 0 ;
}
int F_47 ( struct V_12 * V_13 , struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_103 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_104 )
return 0 ;
V_11 = V_17 -> V_24 ;
while ( V_11 < V_17 -> V_24 + V_17 -> V_104 ) {
if ( * V_11 == V_105 ) {
V_103 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_103 ) {
if ( F_38 ( V_80 ) < V_103 )
return - V_60 ;
memcpy ( F_39 ( V_80 , V_103 ) , V_11 , V_103 ) ;
}
return 0 ;
}
static int F_48 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_106 * V_107 ;
struct V_108 * V_44 ;
T_2 * V_81 ;
if ( F_38 ( V_80 ) < 3 )
return - V_60 ;
F_49 () ;
V_107 = F_50 ( V_13 -> V_41 . V_107 ) ;
if ( F_51 ( ! V_107 ) ) {
F_52 () ;
return - V_109 ;
}
V_44 = V_107 -> V_110 . V_44 ;
F_52 () ;
V_81 = F_39 ( V_80 , 2 + 1 ) ;
* V_81 ++ = V_111 ;
* V_81 ++ = 1 ;
* V_81 ++ = F_53 ( V_44 -> V_112 ) ;
return 0 ;
}
int F_54 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_113 V_114 = F_13 ( V_13 ) ;
struct V_115 * V_116 ;
T_2 * V_81 ;
V_116 = V_15 -> V_21 . V_117 -> V_118 [ V_114 ] ;
if ( ! V_116 -> V_119 . V_120 ||
V_13 -> V_41 . V_42 . V_43 . V_121 == V_122 ||
V_13 -> V_41 . V_42 . V_43 . V_121 == V_123 ||
V_13 -> V_41 . V_42 . V_43 . V_121 == V_124 )
return 0 ;
if ( F_38 ( V_80 ) < 2 + sizeof( struct V_125 ) )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + sizeof( struct V_125 ) ) ;
F_55 ( V_81 , & V_116 -> V_119 , V_116 -> V_119 . V_126 ) ;
return 0 ;
}
int F_56 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_106 * V_107 ;
struct V_108 * V_127 ;
enum V_128 V_129 =
F_57 ( & V_13 -> V_41 . V_42 . V_43 ) ;
struct V_115 * V_116 ;
struct V_130 * V_119 ;
T_2 * V_81 ;
F_49 () ;
V_107 = F_50 ( V_13 -> V_41 . V_107 ) ;
if ( F_51 ( ! V_107 ) ) {
F_52 () ;
return - V_109 ;
}
V_127 = V_107 -> V_110 . V_44 ;
F_52 () ;
V_116 = V_15 -> V_21 . V_117 -> V_118 [ V_127 -> V_114 ] ;
V_119 = & V_116 -> V_119 ;
if ( ! V_119 -> V_120 || V_129 == V_131 )
return 0 ;
if ( F_38 ( V_80 ) < 2 + sizeof( struct V_132 ) )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + sizeof( struct V_132 ) ) ;
F_58 ( V_81 , V_119 , & V_13 -> V_41 . V_42 . V_43 ,
V_13 -> V_41 . V_42 . V_133 ) ;
return 0 ;
}
static void F_59 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
static void F_60 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_9 ( V_134 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_61 ( struct V_16 * V_17 )
{
if ( V_17 -> V_89 . V_135 > V_136 )
F_9 ( V_134 , & V_17 -> V_20 ) ;
else {
F_62 ( V_134 , & V_17 -> V_20 ) ;
F_21 ( & V_17 -> V_137 ) ;
}
}
int F_63 ( struct V_138 * V_139 , T_3 * V_140 ,
const T_2 * V_141 , const T_2 * V_142 )
{
if ( F_64 ( V_141 ) ) {
* V_140 |= F_65 ( V_143 ) ;
memcpy ( V_139 -> V_144 , V_141 , V_78 ) ;
memcpy ( V_139 -> V_145 , V_142 , V_78 ) ;
memcpy ( V_139 -> V_146 , V_142 , V_78 ) ;
return 24 ;
} else {
* V_140 |= F_65 ( V_143 | V_147 ) ;
memset ( V_139 -> V_144 , 0 , V_78 ) ;
memcpy ( V_139 -> V_145 , V_142 , V_78 ) ;
memcpy ( V_139 -> V_146 , V_141 , V_78 ) ;
memcpy ( V_139 -> V_148 , V_142 , V_78 ) ;
return 30 ;
}
}
int F_66 ( struct V_12 * V_13 ,
struct V_68 * V_149 ,
const char * V_150 , const char * V_151 )
{
if ( F_51 ( ! V_150 && V_151 ) )
return 0 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_152 = V_13 -> V_3 . V_18 . V_89 . V_153 ;
F_67 ( F_68 ( V_13 -> V_3 . V_18 . V_154 ) , & V_149 -> V_70 ) ;
V_13 -> V_3 . V_18 . V_154 ++ ;
if ( V_150 && ! V_151 ) {
V_149 -> V_155 |= V_156 ;
memcpy ( V_149 -> V_157 , V_150 , V_78 ) ;
return 2 * V_78 ;
} else if ( V_150 && V_151 ) {
V_149 -> V_155 |= V_158 ;
memcpy ( V_149 -> V_157 , V_150 , V_78 ) ;
memcpy ( V_149 -> V_159 , V_151 , V_78 ) ;
return 3 * V_78 ;
}
return V_78 ;
}
static void F_69 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_49 ;
F_70 ( V_13 , V_17 -> V_89 . V_160 * V_161 ) ;
F_71 ( V_13 ) ;
V_49 = F_17 ( V_13 ) ;
F_22 ( V_13 , V_49 ) ;
F_72 ( & V_17 -> V_162 ,
F_73 ( V_73 +
V_163 ) ) ;
}
static void F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_164 ;
F_75 ( V_13 ) ;
if ( V_17 -> V_89 . V_135 == V_165 )
V_164 = V_17 -> V_89 . V_166 ;
else
V_164 = V_17 -> V_89 . V_167 ;
F_72 ( & V_17 -> V_137 ,
F_73 ( F_76 ( V_164 ) ) ) ;
}
static int
F_77 ( struct V_16 * V_17 )
{
struct V_168 * V_169 ;
int V_170 , V_171 ;
struct V_79 * V_80 ;
struct V_1 * V_2 ;
struct V_106 * V_107 ;
struct V_172 * V_173 ;
enum V_113 V_114 ;
T_2 * V_81 ;
struct V_12 * V_13 ;
int V_174 = F_78 ( struct V_1 , V_3 . V_175 ) +
sizeof( V_2 -> V_3 . V_175 ) ;
V_13 = F_79 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_49 () ;
V_107 = F_50 ( V_13 -> V_41 . V_107 ) ;
V_114 = V_107 -> V_110 . V_44 -> V_114 ;
F_52 () ;
V_170 = V_174 +
2 +
2 + sizeof( struct V_176 ) +
2 + sizeof( struct V_177 ) +
2 + 8 +
2 + 3 ;
V_171 = 2 + ( V_178 - 8 ) +
2 + sizeof( struct V_125 ) +
2 + sizeof( struct V_132 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_84 ) +
2 + sizeof( T_3 ) +
V_17 -> V_104 ;
V_169 = F_80 ( sizeof( * V_169 ) + V_170 + V_171 , V_59 ) ;
V_80 = F_81 ( F_82 ( V_170 , V_171 ) ) ;
if ( ! V_169 || ! V_80 )
goto V_179;
V_169 -> V_180 = ( ( T_2 * ) V_169 ) + sizeof( * V_169 ) ;
V_2 = (struct V_1 * ) F_39 ( V_80 , V_174 ) ;
memset ( V_2 , 0 , V_174 ) ;
V_2 -> V_181 = F_65 ( V_182 |
V_183 ) ;
F_83 ( V_2 -> V_184 ) ;
memcpy ( V_2 -> V_67 , V_13 -> V_41 . V_185 , V_78 ) ;
memcpy ( V_2 -> V_186 , V_13 -> V_41 . V_185 , V_78 ) ;
F_84 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_175 . V_187 =
F_65 ( V_13 -> V_41 . V_42 . V_187 ) ;
V_2 -> V_3 . V_175 . V_188 |= F_65 (
V_13 -> V_3 . V_18 . V_189 ? V_190 : 0 ) ;
V_81 = F_39 ( V_80 , 2 ) ;
* V_81 ++ = V_191 ;
* V_81 ++ = 0x0 ;
F_49 () ;
V_173 = F_50 ( V_17 -> V_173 ) ;
if ( V_173 ) {
V_81 = F_39 ( V_80 , 13 ) ;
memset ( V_81 , 0 , 13 ) ;
* V_81 ++ = V_192 ;
* V_81 ++ = 3 ;
* V_81 ++ = 0x0 ;
* V_81 ++ = F_53 (
V_173 -> V_193 . V_43 . V_44 -> V_112 ) ;
V_13 -> V_194 = V_174 + 6 ;
* V_81 ++ = V_173 -> V_193 . V_195 ;
* V_81 ++ = V_196 ;
* V_81 ++ = 6 ;
if ( V_17 -> V_197 ) {
* V_81 ++ = V_17 -> V_89 . V_153 ;
* V_81 |= V_198 ;
} else {
* V_81 ++ = V_17 -> V_199 ;
}
* V_81 ++ |= V_173 -> V_193 . V_200 ?
V_201 : 0x00 ;
F_44 ( V_202 , V_81 ) ;
V_81 += 2 ;
F_44 ( V_17 -> V_203 , V_81 ) ;
V_81 += 2 ;
}
F_52 () ;
if ( F_85 ( V_13 , V_80 , true , V_114 ) ||
F_48 ( V_13 , V_80 ) )
goto V_179;
V_169 -> V_170 = V_80 -> V_103 ;
memcpy ( V_169 -> V_180 , V_80 -> V_11 , V_169 -> V_170 ) ;
F_86 ( V_80 , 0 ) ;
V_169 -> V_204 = V_169 -> V_180 + V_169 -> V_170 ;
if ( F_87 ( V_13 , V_80 , true , V_114 ) ||
F_47 ( V_13 , V_80 ) ||
F_54 ( V_13 , V_80 ) ||
F_56 ( V_13 , V_80 ) ||
F_42 ( V_13 , V_80 ) ||
F_37 ( V_13 , V_80 ) ||
F_43 ( V_13 , V_80 ) ||
F_45 ( V_13 , V_80 ) )
goto V_179;
V_169 -> V_171 = V_80 -> V_103 ;
memcpy ( V_169 -> V_204 , V_80 -> V_11 , V_169 -> V_171 ) ;
V_169 -> V_205 = (struct V_84 * )
( V_169 -> V_204 + V_17 -> V_86 ) ;
F_88 ( V_80 ) ;
F_89 ( V_17 -> V_175 , V_169 ) ;
return 0 ;
V_179:
F_30 ( V_169 ) ;
F_88 ( V_80 ) ;
return - V_60 ;
}
static int
F_90 ( struct V_12 * V_13 )
{
struct V_168 * V_206 ;
int V_207 ;
V_206 = F_91 ( V_13 -> V_3 . V_18 . V_175 ,
F_92 ( & V_13 -> V_208 . V_209 ) ) ;
V_207 = F_77 ( & V_13 -> V_3 . V_18 ) ;
if ( V_207 )
return V_207 ;
if ( V_206 )
F_93 ( V_206 , V_210 ) ;
return 0 ;
}
void F_22 ( struct V_12 * V_13 ,
T_1 V_49 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_211 = V_49 ;
T_1 V_212 ;
if ( ! V_211 )
return;
F_94 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_9 ( V_212 , & V_17 -> V_213 ) ;
F_9 ( V_214 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_95 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_49 = V_51 |
V_215 |
V_216 |
V_217 |
V_218 ;
V_15 -> V_219 ++ ;
F_96 ( & V_15 -> V_220 ) ;
F_97 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_221 = F_98 ( V_17 -> V_37 ) ;
V_17 -> V_94 = false ;
V_17 -> V_222 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_61 ( V_17 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_133 =
V_17 -> V_89 . V_223 ;
V_13 -> V_41 . V_42 . V_224 = true ;
V_49 |= F_99 ( V_13 ) ;
if ( F_77 ( V_17 ) ) {
F_100 ( V_13 ) ;
return - V_60 ;
}
F_101 ( V_15 , V_13 ) ;
F_102 ( V_13 , V_49 ) ;
F_103 ( V_13 -> V_225 ) ;
return 0 ;
}
void F_100 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_168 * V_169 ;
F_104 ( V_13 -> V_225 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_224 = false ;
F_62 ( V_226 , & V_13 -> V_227 ) ;
F_102 ( V_13 , V_215 ) ;
V_169 = F_91 ( V_17 -> V_175 ,
F_92 ( & V_13 -> V_208 . V_209 ) ) ;
F_89 ( V_17 -> V_175 , NULL ) ;
F_93 ( V_169 , V_210 ) ;
F_105 ( V_13 ) ;
F_106 ( V_13 ) ;
V_15 -> V_228 -= F_107 ( & V_17 -> V_229 . V_230 ) ;
F_108 ( & V_17 -> V_229 . V_230 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_162 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_137 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_231 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_213 = 0 ;
V_15 -> V_219 -- ;
F_109 ( & V_15 -> V_220 ) ;
F_97 ( V_15 ) ;
}
static bool
F_110 ( struct V_12 * V_13 ,
struct V_23 * V_232 , bool V_175 )
{
struct V_233 V_234 ;
struct V_235 V_236 ;
struct V_106 * V_107 ;
struct V_237 * V_238 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
enum V_113 V_114 = F_13 ( V_13 ) ;
int V_239 , V_240 ;
T_1 V_241 ;
if ( V_13 -> V_41 . V_242 )
return true ;
if ( ! V_17 -> V_29 )
return false ;
V_241 = V_243 ;
switch ( V_13 -> V_41 . V_42 . V_43 . V_121 ) {
case V_122 :
V_241 |= V_244 ;
case V_245 :
V_241 |= V_246 ;
break;
default:
break;
}
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
V_239 = F_111 ( V_13 , V_232 , V_175 , V_114 ,
V_241 , V_13 -> V_41 . V_185 ,
& V_236 ) ;
if ( V_239 < 0 )
return false ;
if ( V_239 )
return false ;
V_234 . V_43 = V_236 . V_43 ;
V_234 . V_195 = V_236 . V_195 ;
if ( V_13 -> V_41 . V_42 . V_43 . V_44 -> V_114 !=
V_234 . V_43 . V_44 -> V_114 )
return false ;
if ( ! F_112 ( V_13 -> V_15 -> V_21 . V_117 , & V_234 . V_43 ,
V_247 ) ) {
F_113 ( V_13 ,
L_2 ,
V_13 -> V_41 . V_185 ,
V_234 . V_43 . V_44 -> V_112 ,
V_234 . V_43 . V_121 ,
V_234 . V_43 . V_248 ,
V_234 . V_43 . V_249 ) ;
return false ;
}
V_239 = F_114 ( V_13 -> V_15 -> V_21 . V_117 ,
& V_234 . V_43 ) ;
if ( V_239 < 0 )
return false ;
if ( V_239 ) {
V_234 . V_250 = true ;
return false ;
}
F_49 () ;
V_107 = F_50 ( V_13 -> V_41 . V_107 ) ;
if ( ! V_107 )
goto V_251;
V_238 = F_79 ( V_107 , struct V_237 , V_252 ) ;
if ( V_238 -> V_253 > 1 )
goto V_251;
V_240 = 0 ;
F_115 (chanctx, &sdata->local->chanctx_list, list)
V_240 ++ ;
if ( V_240 > 1 )
goto V_251;
F_52 () ;
F_116 ( V_13 ,
L_3 ,
V_234 . V_43 . V_44 -> V_112 ) ;
V_234 . V_200 = V_236 . V_254 & V_201 ;
if ( V_175 ) {
V_17 -> V_199 = V_236 . V_152 - 1 ;
if ( V_17 -> V_203 >= V_236 . V_203 )
return false ;
V_17 -> V_203 = V_236 . V_203 ;
}
if ( V_17 -> V_199 < V_17 -> V_89 . V_153 ) {
if ( F_117 ( V_13 , & V_234 , false ) < 0 )
return false ;
} else {
return false ;
}
V_13 -> V_255 = V_234 . V_250 ;
if ( V_234 . V_200 )
F_118 ( & V_13 -> V_15 -> V_21 ,
V_256 ,
V_257 ) ;
V_13 -> V_258 = V_234 . V_43 ;
V_13 -> V_41 . V_242 = true ;
F_102 ( V_13 , V_239 ) ;
F_119 ( V_13 , & V_234 . V_43 ) ;
return true ;
V_251:
F_52 () ;
return false ;
}
static void
F_120 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_103 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_79 * V_259 ;
struct V_168 * V_169 ;
struct V_1 * V_139 ;
struct V_23 V_232 ;
T_4 V_260 ;
T_2 * V_81 ;
V_81 = V_2 -> V_3 . V_261 . V_262 ;
V_260 = ( T_2 * ) V_81 - ( T_2 * ) V_2 ;
if ( V_260 > V_103 )
return;
F_121 ( V_81 , V_103 - V_260 , false , & V_232 ) ;
if ( ! V_232 . V_29 )
return;
if ( ( ! F_34 ( V_2 -> V_184 , V_13 -> V_41 . V_185 ) &&
! F_122 ( V_2 -> V_184 ) ) ||
V_232 . V_263 != 0 )
return;
if ( V_232 . V_28 != 0 &&
( V_232 . V_28 != V_17 -> V_28 ||
memcmp ( V_232 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_49 () ;
V_169 = F_50 ( V_17 -> V_175 ) ;
if ( ! V_169 )
goto V_264;
V_259 = F_81 ( V_15 -> V_265 +
V_169 -> V_170 + V_169 -> V_171 ) ;
if ( ! V_259 )
goto V_264;
F_123 ( V_259 , V_15 -> V_265 ) ;
memcpy ( F_39 ( V_259 , V_169 -> V_170 ) , V_169 -> V_180 , V_169 -> V_170 ) ;
memcpy ( F_39 ( V_259 , V_169 -> V_171 ) , V_169 -> V_204 , V_169 -> V_171 ) ;
V_139 = (struct V_1 * ) V_259 -> V_11 ;
V_139 -> V_181 = F_65 ( V_182 |
V_266 ) ;
memcpy ( V_139 -> V_184 , V_2 -> V_67 , V_78 ) ;
F_124 ( V_259 ) -> V_155 |= V_267 ;
F_125 ( V_13 , V_259 ) ;
V_264:
F_52 () ;
}
static void F_126 ( struct V_12 * V_13 ,
T_5 V_268 ,
struct V_1 * V_2 ,
T_4 V_103 ,
struct V_269 * V_270 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_232 ;
struct V_108 * V_127 ;
T_4 V_260 ;
int V_271 ;
enum V_113 V_114 = V_270 -> V_114 ;
if ( V_268 == V_266 &&
! F_34 ( V_2 -> V_184 , V_13 -> V_41 . V_185 ) )
return;
V_260 = ( T_2 * ) V_2 -> V_3 . V_272 . V_262 - ( T_2 * ) V_2 ;
if ( V_260 > V_103 )
return;
F_121 ( V_2 -> V_3 . V_272 . V_262 , V_103 - V_260 ,
false , & V_232 ) ;
if ( ( ! V_232 . V_29 || ! V_232 . V_31 ) ||
( V_232 . V_273 && V_13 -> V_3 . V_18 . V_189 == V_274 ) ||
( ! V_232 . V_273 && V_13 -> V_3 . V_18 . V_189 != V_274 ) )
return;
if ( V_232 . V_275 )
V_271 = F_127 ( V_232 . V_275 [ 0 ] , V_114 ) ;
else
V_271 = V_270 -> V_271 ;
V_127 = F_128 ( V_15 -> V_21 . V_117 , V_271 ) ;
if ( ! V_127 || V_127 -> V_155 & V_247 )
return;
if ( F_11 ( V_13 , & V_232 ) )
F_129 ( V_13 , V_2 -> V_67 , & V_232 ) ;
if ( V_17 -> V_221 )
V_17 -> V_221 -> V_276 ( V_13 ,
V_268 , V_2 , & V_232 , V_270 ) ;
if ( ! V_17 -> V_197 )
F_110 ( V_13 , & V_232 , true ) ;
}
int F_130 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_172 * V_277 ;
int V_207 = 0 ;
V_17 -> V_197 = false ;
V_17 -> V_199 = 0 ;
V_277 = F_50 ( V_17 -> V_173 ) ;
F_89 ( V_17 -> V_173 , NULL ) ;
F_93 ( V_277 , V_210 ) ;
V_207 = F_90 ( V_13 ) ;
if ( V_207 )
return - V_109 ;
F_102 ( V_13 , V_51 ) ;
F_116 ( V_13 , L_4 ,
V_13 -> V_41 . V_42 . V_43 . V_44 -> V_112 ) ;
return 0 ;
}
int F_117 ( struct V_12 * V_13 ,
struct V_233 * V_278 ,
bool V_279 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_172 * V_277 ;
int V_207 = 0 ;
V_277 = F_24 ( sizeof( * V_277 ) ,
V_76 ) ;
if ( ! V_277 )
return - V_60 ;
memcpy ( & V_277 -> V_193 , V_278 ,
sizeof( struct V_233 ) ) ;
F_89 ( V_17 -> V_173 , V_277 ) ;
V_207 = F_90 ( V_13 ) ;
if ( V_207 ) {
V_277 = F_50 ( V_17 -> V_173 ) ;
F_89 ( V_17 -> V_173 , NULL ) ;
F_93 ( V_277 , V_210 ) ;
return V_207 ;
}
F_102 ( V_13 , V_51 ) ;
if ( V_279 )
F_131 ( V_13 , V_278 ) ;
return 0 ;
}
static int F_132 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_103 )
{
struct V_1 * V_280 ;
struct V_79 * V_80 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_2 * V_81 = V_2 -> V_3 . V_4 . V_3 . V_281 . V_262 ;
T_4 V_282 ;
V_80 = F_81 ( V_15 -> V_265 + V_103 ) ;
if ( ! V_80 )
return - V_60 ;
F_123 ( V_80 , V_15 -> V_265 ) ;
V_280 = (struct V_1 * ) F_39 ( V_80 , V_103 ) ;
V_282 = ( V_103 < 42 ) ? 7 : 10 ;
* ( V_81 + V_282 ) -= 1 ;
* ( V_81 + V_282 + 1 ) &= ~ V_198 ;
memcpy ( V_280 , V_2 , V_103 ) ;
F_83 ( V_280 -> V_184 ) ;
memcpy ( V_280 -> V_67 , V_13 -> V_41 . V_185 , V_78 ) ;
memcpy ( V_280 -> V_186 , V_13 -> V_41 . V_185 , V_78 ) ;
F_125 ( V_13 , V_80 ) ;
return 0 ;
}
static void F_133 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_103 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_232 ;
T_5 V_203 ;
bool V_283 = true ;
T_4 V_260 ;
T_2 * V_81 ;
if ( V_2 -> V_3 . V_4 . V_3 . V_284 . V_6 !=
V_285 )
return;
V_81 = V_2 -> V_3 . V_4 . V_3 . V_281 . V_262 ;
V_260 = F_78 ( struct V_1 ,
V_3 . V_4 . V_3 . V_281 . V_262 ) ;
F_121 ( V_81 , V_103 - V_260 , false , & V_232 ) ;
V_17 -> V_199 = V_232 . V_286 -> V_287 ;
if ( ! -- V_17 -> V_199 )
V_283 = false ;
V_203 = F_134 ( V_232 . V_286 -> V_288 ) ;
if ( V_17 -> V_203 >= V_203 )
return;
V_17 -> V_203 = V_203 ;
if ( ! F_110 ( V_13 , & V_232 , false ) ) {
F_116 ( V_13 , L_5 ) ;
return;
}
if ( V_283 ) {
if ( F_132 ( V_13 , V_2 , V_103 ) < 0 )
F_116 ( V_13 , L_6 ) ;
}
}
static void F_135 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_103 ,
struct V_269 * V_270 )
{
switch ( V_2 -> V_3 . V_4 . V_289 ) {
case V_290 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_291 . V_6 ) {
case V_292 :
case V_293 :
case V_294 :
F_136 ( V_13 , V_2 , V_103 , V_270 ) ;
break;
}
break;
case V_295 :
if ( F_1 ( V_2 ) )
F_137 ( V_13 , V_2 , V_103 ) ;
break;
case V_296 :
F_133 ( V_13 , V_2 , V_103 ) ;
break;
}
}
void F_138 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_269 * V_270 ;
struct V_1 * V_2 ;
T_5 V_268 ;
F_139 ( V_13 ) ;
if ( ! V_13 -> V_208 . V_28 )
goto V_264;
V_270 = F_140 ( V_80 ) ;
V_2 = (struct V_1 * ) V_80 -> V_11 ;
V_268 = F_134 ( V_2 -> V_181 ) & V_297 ;
switch ( V_268 ) {
case V_266 :
case V_183 :
F_126 ( V_13 , V_268 , V_2 , V_80 -> V_103 ,
V_270 ) ;
break;
case V_298 :
F_120 ( V_13 , V_2 , V_80 -> V_103 ) ;
break;
case V_299 :
F_135 ( V_13 , V_2 , V_80 -> V_103 , V_270 ) ;
break;
}
V_264:
F_141 ( V_13 ) ;
}
static void F_142 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_212 , V_49 = 0 ;
F_94 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_62 ( V_212 , & V_17 -> V_213 ) ;
V_49 |= F_143 ( V_212 ) ;
}
if ( V_13 -> V_41 . V_42 . V_224 &&
( V_49 & ( V_51 |
V_216 |
V_217 |
V_218 ) ) )
if ( F_90 ( V_13 ) )
return;
F_102 ( V_13 , V_49 ) ;
}
void F_144 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_139 ( V_13 ) ;
if ( ! V_13 -> V_208 . V_28 )
goto V_264;
if ( V_17 -> V_300 &&
F_33 ( V_73 ,
V_17 -> V_301 + F_145 ( V_17 -> V_89 . V_302 ) ) )
F_146 ( V_13 ) ;
if ( F_147 ( V_303 , & V_17 -> V_20 ) )
F_148 () ;
if ( F_147 ( V_304 , & V_17 -> V_20 ) )
F_149 () ;
if ( F_147 ( V_19 , & V_17 -> V_20 ) )
F_69 ( V_13 ) ;
if ( F_147 ( V_134 , & V_17 -> V_20 ) )
F_74 ( V_13 ) ;
if ( F_147 ( V_305 , & V_17 -> V_20 ) )
F_150 ( V_13 ) ;
if ( F_147 ( V_214 , & V_17 -> V_20 ) )
F_142 ( V_13 ) ;
V_264:
F_141 ( V_13 ) ;
}
void F_151 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_49 () ;
F_115 (sdata, &local->interfaces, list)
if ( F_152 ( & V_13 -> V_41 ) &&
F_153 ( V_13 ) )
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
F_52 () ;
}
void F_154 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_306 [ V_78 ] = {} ;
F_155 ( & V_17 -> V_162 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_50 = true ;
F_156 ( & V_17 -> V_307 , 0 ) ;
F_23 ( V_13 ) ;
V_17 -> V_301 = V_73 ;
V_17 -> V_308 = V_73 ;
V_17 -> V_197 = false ;
if ( ! V_8 )
F_2 () ;
F_155 ( & V_17 -> V_231 ,
F_59 ,
( unsigned long ) V_13 ) ;
F_155 ( & V_17 -> V_137 ,
F_60 ,
( unsigned long ) V_13 ) ;
F_25 ( & V_17 -> V_309 . V_66 ) ;
F_157 ( & V_17 -> V_229 . V_230 ) ;
F_158 ( & V_17 -> V_310 ) ;
F_158 ( & V_17 -> V_311 ) ;
F_159 ( V_17 -> V_175 , NULL ) ;
V_13 -> V_41 . V_42 . V_186 = V_306 ;
}
