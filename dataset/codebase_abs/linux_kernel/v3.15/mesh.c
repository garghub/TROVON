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
if ( V_17 -> V_197 == V_198 ) {
* V_81 ++ = V_17 -> V_89 . V_153 ;
* V_81 |= V_199 ;
} else {
* V_81 ++ = V_17 -> V_200 ;
}
* V_81 ++ |= V_173 -> V_193 . V_201 ?
V_202 : 0x00 ;
F_44 ( V_203 , V_81 ) ;
V_81 += 2 ;
F_44 ( V_17 -> V_204 , V_81 ) ;
V_81 += 2 ;
}
F_52 () ;
if ( F_85 ( V_13 , V_80 , true , V_114 ) ||
F_48 ( V_13 , V_80 ) )
goto V_179;
V_169 -> V_170 = V_80 -> V_103 ;
memcpy ( V_169 -> V_180 , V_80 -> V_11 , V_169 -> V_170 ) ;
F_86 ( V_80 , 0 ) ;
V_169 -> V_205 = V_169 -> V_180 + V_169 -> V_170 ;
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
memcpy ( V_169 -> V_205 , V_80 -> V_11 , V_169 -> V_171 ) ;
V_169 -> V_206 = (struct V_84 * )
( V_169 -> V_205 + V_17 -> V_86 ) ;
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
struct V_168 * V_207 ;
int V_208 ;
V_207 = F_91 ( V_13 -> V_3 . V_18 . V_175 ,
F_92 ( & V_13 -> V_209 . V_210 ) ) ;
V_208 = F_77 ( & V_13 -> V_3 . V_18 ) ;
if ( V_208 )
return V_208 ;
if ( V_207 )
F_93 ( V_207 , V_211 ) ;
return 0 ;
}
void F_22 ( struct V_12 * V_13 ,
T_1 V_49 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_212 = V_49 ;
T_1 V_213 ;
if ( ! V_212 )
return;
F_94 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_9 ( V_213 , & V_17 -> V_214 ) ;
F_9 ( V_215 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_95 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_49 = V_51 |
V_216 |
V_217 |
V_218 |
V_219 ;
V_15 -> V_220 ++ ;
F_96 ( & V_15 -> V_221 ) ;
F_97 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_222 = F_98 ( V_17 -> V_37 ) ;
V_17 -> V_94 = false ;
V_17 -> V_223 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_61 ( V_17 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_133 =
V_17 -> V_89 . V_224 ;
V_13 -> V_41 . V_42 . V_225 = true ;
V_49 |= F_99 ( V_13 ) ;
if ( F_77 ( V_17 ) ) {
F_100 ( V_13 ) ;
return - V_60 ;
}
F_101 ( V_15 , V_13 ) ;
F_102 ( V_13 , V_49 ) ;
F_103 ( V_13 -> V_226 ) ;
return 0 ;
}
void F_100 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_168 * V_169 ;
F_104 ( V_13 -> V_226 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_225 = false ;
F_62 ( V_227 , & V_13 -> V_228 ) ;
F_102 ( V_13 , V_216 ) ;
V_169 = F_91 ( V_17 -> V_175 ,
F_92 ( & V_13 -> V_209 . V_210 ) ) ;
F_89 ( V_17 -> V_175 , NULL ) ;
F_93 ( V_169 , V_211 ) ;
F_105 ( V_13 ) ;
F_106 ( V_13 ) ;
V_15 -> V_229 -= F_107 ( & V_17 -> V_230 . V_231 ) ;
F_108 ( & V_17 -> V_230 . V_231 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_162 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_137 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_232 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_214 = 0 ;
V_15 -> V_220 -- ;
F_109 ( & V_15 -> V_221 ) ;
F_97 ( V_15 ) ;
}
static bool
F_110 ( struct V_12 * V_13 ,
struct V_23 * V_233 , bool V_175 )
{
struct V_234 V_235 ;
struct V_236 V_237 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
enum V_113 V_114 = F_13 ( V_13 ) ;
int V_238 ;
T_1 V_239 ;
F_111 ( V_13 ) ;
V_239 = V_240 ;
switch ( V_13 -> V_41 . V_42 . V_43 . V_121 ) {
case V_122 :
V_239 |= V_241 ;
case V_242 :
V_239 |= V_243 ;
break;
default:
break;
}
memset ( & V_235 , 0 , sizeof( V_235 ) ) ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_238 = F_112 ( V_13 , V_233 , V_175 , V_114 ,
V_239 , V_13 -> V_41 . V_185 ,
& V_237 ) ;
if ( V_238 < 0 )
return false ;
if ( V_238 )
return false ;
V_235 . V_43 = V_237 . V_43 ;
V_235 . V_195 = V_237 . V_195 ;
if ( ! F_113 ( V_13 -> V_15 -> V_21 . V_117 , & V_235 . V_43 ,
V_244 ) ) {
F_114 ( V_13 ,
L_2 ,
V_13 -> V_41 . V_185 ,
V_235 . V_43 . V_44 -> V_112 ,
V_235 . V_43 . V_121 ,
V_235 . V_43 . V_245 ,
V_235 . V_43 . V_246 ) ;
return false ;
}
V_238 = F_115 ( V_13 -> V_15 -> V_21 . V_117 ,
& V_235 . V_43 ) ;
if ( V_238 < 0 )
return false ;
if ( V_238 ) {
V_235 . V_247 = true ;
return false ;
}
if ( F_116 ( & V_235 . V_43 ,
& V_13 -> V_41 . V_42 . V_43 ) ) {
F_117 ( V_13 ,
L_3 ) ;
return true ;
}
F_117 ( V_13 ,
L_4 ,
V_235 . V_43 . V_44 -> V_112 ) ;
V_235 . V_201 = V_237 . V_248 & V_202 ;
if ( V_175 ) {
V_17 -> V_200 = V_237 . V_152 - 1 ;
if ( V_17 -> V_204 >= V_237 . V_204 )
return false ;
V_17 -> V_204 = V_237 . V_204 ;
}
if ( V_17 -> V_200 >= V_17 -> V_89 . V_153 )
return false ;
V_17 -> V_197 = V_249 ;
if ( F_118 ( V_13 -> V_15 -> V_21 . V_117 , V_13 -> V_226 ,
& V_235 ) < 0 )
return false ;
return true ;
}
static void
F_119 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_103 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_79 * V_250 ;
struct V_168 * V_169 ;
struct V_1 * V_139 ;
struct V_23 V_233 ;
T_4 V_251 ;
T_2 * V_81 ;
V_81 = V_2 -> V_3 . V_252 . V_253 ;
V_251 = ( T_2 * ) V_81 - ( T_2 * ) V_2 ;
if ( V_251 > V_103 )
return;
F_120 ( V_81 , V_103 - V_251 , false , & V_233 ) ;
if ( ! V_233 . V_29 )
return;
if ( ( ! F_34 ( V_2 -> V_184 , V_13 -> V_41 . V_185 ) &&
! F_121 ( V_2 -> V_184 ) ) ||
V_233 . V_254 != 0 )
return;
if ( V_233 . V_28 != 0 &&
( V_233 . V_28 != V_17 -> V_28 ||
memcmp ( V_233 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_49 () ;
V_169 = F_50 ( V_17 -> V_175 ) ;
if ( ! V_169 )
goto V_255;
V_250 = F_81 ( V_15 -> V_256 +
V_169 -> V_170 + V_169 -> V_171 ) ;
if ( ! V_250 )
goto V_255;
F_122 ( V_250 , V_15 -> V_256 ) ;
memcpy ( F_39 ( V_250 , V_169 -> V_170 ) , V_169 -> V_180 , V_169 -> V_170 ) ;
memcpy ( F_39 ( V_250 , V_169 -> V_171 ) , V_169 -> V_205 , V_169 -> V_171 ) ;
V_139 = (struct V_1 * ) V_250 -> V_11 ;
V_139 -> V_181 = F_65 ( V_182 |
V_257 ) ;
memcpy ( V_139 -> V_184 , V_2 -> V_67 , V_78 ) ;
F_123 ( V_250 ) -> V_155 |= V_258 ;
F_124 ( V_13 , V_250 ) ;
V_255:
F_52 () ;
}
static void F_125 ( struct V_12 * V_13 ,
T_5 V_259 ,
struct V_1 * V_2 ,
T_4 V_103 ,
struct V_260 * V_261 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_233 ;
struct V_108 * V_127 ;
T_4 V_251 ;
int V_262 ;
enum V_113 V_114 = V_261 -> V_114 ;
if ( V_259 == V_257 &&
! F_34 ( V_2 -> V_184 , V_13 -> V_41 . V_185 ) )
return;
V_251 = ( T_2 * ) V_2 -> V_3 . V_263 . V_253 - ( T_2 * ) V_2 ;
if ( V_251 > V_103 )
return;
F_120 ( V_2 -> V_3 . V_263 . V_253 , V_103 - V_251 ,
false , & V_233 ) ;
if ( ( ! V_233 . V_29 || ! V_233 . V_31 ) ||
( V_233 . V_264 && V_13 -> V_3 . V_18 . V_189 == V_265 ) ||
( ! V_233 . V_264 && V_13 -> V_3 . V_18 . V_189 != V_265 ) )
return;
if ( V_233 . V_266 )
V_262 = F_126 ( V_233 . V_266 [ 0 ] , V_114 ) ;
else
V_262 = V_261 -> V_262 ;
V_127 = F_127 ( V_15 -> V_21 . V_117 , V_262 ) ;
if ( ! V_127 || V_127 -> V_155 & V_244 )
return;
if ( F_11 ( V_13 , & V_233 ) )
F_128 ( V_13 , V_2 -> V_67 , & V_233 ) ;
if ( V_17 -> V_222 )
V_17 -> V_222 -> V_267 ( V_13 ,
V_259 , V_2 , & V_233 , V_261 ) ;
if ( V_17 -> V_197 != V_198 &&
! V_13 -> V_41 . V_268 )
F_110 ( V_13 , & V_233 , true ) ;
}
int F_129 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_172 * V_269 ;
int V_208 = 0 ;
int V_49 = 0 ;
V_17 -> V_197 = V_270 ;
V_17 -> V_200 = 0 ;
V_269 = F_50 ( V_17 -> V_173 ) ;
F_89 ( V_17 -> V_173 , NULL ) ;
if ( V_269 )
F_93 ( V_269 , V_211 ) ;
V_208 = F_90 ( V_13 ) ;
if ( V_208 )
return - V_109 ;
V_49 |= V_51 ;
F_117 ( V_13 , L_5 ,
V_13 -> V_41 . V_42 . V_43 . V_44 -> V_112 ) ;
return V_49 ;
}
int F_130 ( struct V_12 * V_13 ,
struct V_234 * V_271 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_172 * V_269 ;
int V_208 = 0 ;
V_269 = F_24 ( sizeof( * V_269 ) ,
V_76 ) ;
if ( ! V_269 )
return - V_60 ;
memcpy ( & V_269 -> V_193 , V_271 ,
sizeof( struct V_234 ) ) ;
F_89 ( V_17 -> V_173 , V_269 ) ;
V_208 = F_90 ( V_13 ) ;
if ( V_208 ) {
V_269 = F_50 ( V_17 -> V_173 ) ;
F_89 ( V_17 -> V_173 , NULL ) ;
F_93 ( V_269 , V_211 ) ;
return V_208 ;
}
return V_51 ;
}
static int F_131 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_103 )
{
struct V_1 * V_272 ;
struct V_79 * V_80 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_2 * V_81 = V_2 -> V_3 . V_4 . V_3 . V_273 . V_253 ;
T_4 V_274 ;
V_80 = F_81 ( V_15 -> V_256 + V_103 ) ;
if ( ! V_80 )
return - V_60 ;
F_122 ( V_80 , V_15 -> V_256 ) ;
V_272 = (struct V_1 * ) F_39 ( V_80 , V_103 ) ;
V_274 = ( V_103 < 42 ) ? 7 : 10 ;
* ( V_81 + V_274 ) -= 1 ;
* ( V_81 + V_274 + 1 ) &= ~ V_199 ;
memcpy ( V_272 , V_2 , V_103 ) ;
F_83 ( V_272 -> V_184 ) ;
memcpy ( V_272 -> V_67 , V_13 -> V_41 . V_185 , V_78 ) ;
memcpy ( V_272 -> V_186 , V_13 -> V_41 . V_185 , V_78 ) ;
F_124 ( V_13 , V_80 ) ;
return 0 ;
}
static void F_132 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_103 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_233 ;
T_5 V_204 ;
bool V_275 = true ;
T_4 V_251 ;
T_2 * V_81 ;
if ( V_2 -> V_3 . V_4 . V_3 . V_276 . V_6 !=
V_277 )
return;
V_81 = V_2 -> V_3 . V_4 . V_3 . V_273 . V_253 ;
V_251 = F_78 ( struct V_1 ,
V_3 . V_4 . V_3 . V_273 . V_253 ) ;
F_120 ( V_81 , V_103 - V_251 , false , & V_233 ) ;
V_17 -> V_200 = V_233 . V_278 -> V_279 ;
if ( ! -- V_17 -> V_200 )
V_275 = false ;
V_204 = F_133 ( V_233 . V_278 -> V_280 ) ;
if ( V_17 -> V_204 >= V_204 )
return;
V_17 -> V_204 = V_204 ;
if ( ! V_13 -> V_41 . V_268 &&
! F_110 ( V_13 , & V_233 , false ) ) {
F_117 ( V_13 , L_6 ) ;
return;
}
if ( V_275 ) {
if ( F_131 ( V_13 , V_2 , V_103 ) < 0 )
F_117 ( V_13 , L_7 ) ;
}
}
static void F_134 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_103 ,
struct V_260 * V_261 )
{
switch ( V_2 -> V_3 . V_4 . V_281 ) {
case V_282 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_283 . V_6 ) {
case V_284 :
case V_285 :
case V_286 :
F_135 ( V_13 , V_2 , V_103 , V_261 ) ;
break;
}
break;
case V_287 :
if ( F_1 ( V_2 ) )
F_136 ( V_13 , V_2 , V_103 ) ;
break;
case V_288 :
F_132 ( V_13 , V_2 , V_103 ) ;
break;
}
}
void F_137 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_260 * V_261 ;
struct V_1 * V_2 ;
T_5 V_259 ;
F_138 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_255;
V_261 = F_139 ( V_80 ) ;
V_2 = (struct V_1 * ) V_80 -> V_11 ;
V_259 = F_133 ( V_2 -> V_181 ) & V_289 ;
switch ( V_259 ) {
case V_257 :
case V_183 :
F_125 ( V_13 , V_259 , V_2 , V_80 -> V_103 ,
V_261 ) ;
break;
case V_290 :
F_119 ( V_13 , V_2 , V_80 -> V_103 ) ;
break;
case V_291 :
F_134 ( V_13 , V_2 , V_80 -> V_103 , V_261 ) ;
break;
}
V_255:
F_140 ( V_13 ) ;
}
static void F_141 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_213 , V_49 = 0 ;
F_94 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_62 ( V_213 , & V_17 -> V_214 ) ;
V_49 |= F_142 ( V_213 ) ;
}
if ( V_13 -> V_41 . V_42 . V_225 &&
( V_49 & ( V_51 |
V_217 |
V_218 |
V_219 ) ) )
if ( F_90 ( V_13 ) )
return;
F_102 ( V_13 , V_49 ) ;
}
void F_143 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_138 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_255;
if ( V_17 -> V_292 &&
F_33 ( V_73 ,
V_17 -> V_293 + F_144 ( V_17 -> V_89 . V_294 ) ) )
F_145 ( V_13 ) ;
if ( F_146 ( V_295 , & V_17 -> V_20 ) )
F_147 () ;
if ( F_146 ( V_296 , & V_17 -> V_20 ) )
F_148 () ;
if ( F_146 ( V_19 , & V_17 -> V_20 ) )
F_69 ( V_13 ) ;
if ( F_146 ( V_134 , & V_17 -> V_20 ) )
F_74 ( V_13 ) ;
if ( F_146 ( V_297 , & V_17 -> V_20 ) )
F_149 ( V_13 ) ;
if ( F_146 ( V_215 , & V_17 -> V_20 ) )
F_141 ( V_13 ) ;
V_255:
F_140 ( V_13 ) ;
}
void F_150 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_49 () ;
F_151 (sdata, &local->interfaces, list)
if ( F_152 ( & V_13 -> V_41 ) &&
F_153 ( V_13 ) )
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
F_52 () ;
}
void F_154 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_298 [ V_78 ] = {} ;
F_155 ( & V_17 -> V_162 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_50 = true ;
F_156 ( & V_17 -> V_299 , 0 ) ;
F_23 ( V_13 ) ;
V_17 -> V_293 = V_73 ;
V_17 -> V_300 = V_73 ;
V_17 -> V_197 = V_270 ;
if ( ! V_8 )
F_2 () ;
F_155 ( & V_17 -> V_232 ,
F_59 ,
( unsigned long ) V_13 ) ;
F_155 ( & V_17 -> V_137 ,
F_60 ,
( unsigned long ) V_13 ) ;
F_25 ( & V_17 -> V_301 . V_66 ) ;
F_157 ( & V_17 -> V_230 . V_231 ) ;
F_158 ( & V_17 -> V_302 ) ;
F_158 ( & V_17 -> V_303 ) ;
F_159 ( V_17 -> V_175 , NULL ) ;
V_13 -> V_41 . V_42 . V_186 = V_298 ;
}
