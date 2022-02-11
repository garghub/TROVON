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
* V_81 ++ = V_17 -> V_30 ;
* V_81 ++ = V_17 -> V_33 ;
* V_81 ++ = V_17 -> V_35 ;
* V_81 ++ = V_17 -> V_37 ;
* V_81 ++ = V_17 -> V_39 ;
V_82 = F_40 ( & V_17 -> V_86 ) ;
V_82 = F_41 ( int , V_82 , V_87 ) ;
* V_81 ++ = V_82 << 1 ;
* V_81 = 0x00 ;
* V_81 |= V_17 -> V_88 . V_89 ?
V_90 : 0x00 ;
* V_81 |= V_17 -> V_50 ?
V_47 : 0x00 ;
* V_81 |= V_17 -> V_91 ?
V_92 : 0x00 ;
* V_81 ++ |= V_17 -> V_93 ?
V_94 : 0x00 ;
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
* V_81 ++ = V_95 ;
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
if ( V_17 -> V_96 == 0 &&
V_17 -> V_91 == 0 &&
V_17 -> V_97 == V_98 )
return 0 ;
if ( F_38 ( V_80 ) < 4 )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + 2 ) ;
* V_81 ++ = V_99 ;
* V_81 ++ = 2 ;
F_44 ( V_17 -> V_88 . V_100 , V_81 ) ;
return 0 ;
}
int F_45 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_101 , V_102 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_103 )
return 0 ;
V_101 = F_46 ( V_17 -> V_24 , V_17 -> V_103 , 0 ) ;
if ( V_101 ) {
V_102 = V_17 -> V_103 - V_101 ;
V_11 = V_17 -> V_24 + V_101 ;
if ( F_38 ( V_80 ) < V_102 )
return - V_60 ;
memcpy ( F_39 ( V_80 , V_102 ) , V_11 , V_102 ) ;
}
return 0 ;
}
int F_47 ( struct V_12 * V_13 , struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_102 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_103 )
return 0 ;
V_11 = V_17 -> V_24 ;
while ( V_11 < V_17 -> V_24 + V_17 -> V_103 ) {
if ( * V_11 == V_104 ) {
V_102 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_102 ) {
if ( F_38 ( V_80 ) < V_102 )
return - V_60 ;
memcpy ( F_39 ( V_80 , V_102 ) , V_11 , V_102 ) ;
}
return 0 ;
}
static int F_48 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_105 * V_106 ;
struct V_107 * V_44 ;
T_2 * V_81 ;
if ( F_38 ( V_80 ) < 3 )
return - V_60 ;
F_49 () ;
V_106 = F_50 ( V_13 -> V_41 . V_106 ) ;
if ( F_51 ( ! V_106 ) ) {
F_52 () ;
return - V_108 ;
}
V_44 = V_106 -> V_109 . V_44 ;
F_52 () ;
V_81 = F_39 ( V_80 , 2 + 1 ) ;
* V_81 ++ = V_110 ;
* V_81 ++ = 1 ;
* V_81 ++ = F_53 ( V_44 -> V_111 ) ;
return 0 ;
}
int F_54 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_112 V_113 = F_13 ( V_13 ) ;
struct V_114 * V_115 ;
T_2 * V_81 ;
V_115 = V_15 -> V_21 . V_116 -> V_117 [ V_113 ] ;
if ( ! V_115 -> V_118 . V_119 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_121 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_122 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_123 )
return 0 ;
if ( F_38 ( V_80 ) < 2 + sizeof( struct V_124 ) )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + sizeof( struct V_124 ) ) ;
F_55 ( V_81 , & V_115 -> V_118 , V_115 -> V_118 . V_125 ) ;
return 0 ;
}
int F_56 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_105 * V_106 ;
struct V_107 * V_126 ;
enum V_127 V_128 =
F_57 ( & V_13 -> V_41 . V_42 . V_43 ) ;
struct V_114 * V_115 ;
struct V_129 * V_118 ;
T_2 * V_81 ;
F_49 () ;
V_106 = F_50 ( V_13 -> V_41 . V_106 ) ;
if ( F_51 ( ! V_106 ) ) {
F_52 () ;
return - V_108 ;
}
V_126 = V_106 -> V_109 . V_44 ;
F_52 () ;
V_115 = V_15 -> V_21 . V_116 -> V_117 [ V_126 -> V_113 ] ;
V_118 = & V_115 -> V_118 ;
if ( ! V_118 -> V_119 || V_128 == V_130 )
return 0 ;
if ( F_38 ( V_80 ) < 2 + sizeof( struct V_131 ) )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + sizeof( struct V_131 ) ) ;
F_58 ( V_81 , V_118 , & V_13 -> V_41 . V_42 . V_43 ,
V_13 -> V_41 . V_42 . V_132 ) ;
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
F_9 ( V_133 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_61 ( struct V_16 * V_17 )
{
if ( V_17 -> V_88 . V_134 > V_135 )
F_9 ( V_133 , & V_17 -> V_20 ) ;
else {
F_62 ( V_133 , & V_17 -> V_20 ) ;
F_21 ( & V_17 -> V_136 ) ;
}
}
int F_63 ( struct V_137 * V_138 , T_3 * V_139 ,
const T_2 * V_140 , const T_2 * V_141 )
{
if ( F_64 ( V_140 ) ) {
* V_139 |= F_65 ( V_142 ) ;
memcpy ( V_138 -> V_143 , V_140 , V_78 ) ;
memcpy ( V_138 -> V_144 , V_141 , V_78 ) ;
memcpy ( V_138 -> V_145 , V_141 , V_78 ) ;
return 24 ;
} else {
* V_139 |= F_65 ( V_142 | V_146 ) ;
memset ( V_138 -> V_143 , 0 , V_78 ) ;
memcpy ( V_138 -> V_144 , V_141 , V_78 ) ;
memcpy ( V_138 -> V_145 , V_140 , V_78 ) ;
memcpy ( V_138 -> V_147 , V_141 , V_78 ) ;
return 30 ;
}
}
int F_66 ( struct V_12 * V_13 ,
struct V_68 * V_148 ,
const char * V_149 , const char * V_150 )
{
if ( F_51 ( ! V_149 && V_150 ) )
return 0 ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
V_148 -> V_151 = V_13 -> V_3 . V_18 . V_88 . V_152 ;
F_67 ( F_68 ( V_13 -> V_3 . V_18 . V_153 ) , & V_148 -> V_70 ) ;
V_13 -> V_3 . V_18 . V_153 ++ ;
if ( V_149 && ! V_150 ) {
V_148 -> V_154 |= V_155 ;
memcpy ( V_148 -> V_156 , V_149 , V_78 ) ;
return 2 * V_78 ;
} else if ( V_149 && V_150 ) {
V_148 -> V_154 |= V_157 ;
memcpy ( V_148 -> V_156 , V_149 , V_78 ) ;
memcpy ( V_148 -> V_158 , V_150 , V_78 ) ;
return 3 * V_78 ;
}
return V_78 ;
}
static void F_69 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_49 ;
F_70 ( V_13 , V_17 -> V_88 . V_159 * V_160 ) ;
F_71 ( V_13 ) ;
V_49 = F_17 ( V_13 ) ;
F_22 ( V_13 , V_49 ) ;
F_72 ( & V_17 -> V_161 ,
F_73 ( V_73 +
V_162 ) ) ;
}
static void F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_163 ;
F_75 ( V_13 ) ;
if ( V_17 -> V_88 . V_134 == V_164 )
V_163 = V_17 -> V_88 . V_165 ;
else
V_163 = V_17 -> V_88 . V_166 ;
F_72 ( & V_17 -> V_136 ,
F_73 ( F_76 ( V_163 ) ) ) ;
}
static int
F_77 ( struct V_16 * V_17 )
{
struct V_167 * V_168 ;
int V_169 , V_170 ;
struct V_79 * V_80 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
struct V_171 * V_172 ;
enum V_112 V_113 ;
T_2 * V_81 ;
struct V_12 * V_13 ;
int V_173 = F_78 ( struct V_1 , V_3 . V_174 ) +
sizeof( V_2 -> V_3 . V_174 ) ;
V_13 = F_79 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_49 () ;
V_106 = F_50 ( V_13 -> V_41 . V_106 ) ;
V_113 = V_106 -> V_109 . V_44 -> V_113 ;
F_52 () ;
V_169 = V_173 +
2 +
2 + sizeof( struct V_175 ) +
2 + sizeof( struct V_176 ) +
2 + 8 +
2 + 3 ;
V_170 = 2 + ( V_177 - 8 ) +
2 + sizeof( struct V_124 ) +
2 + sizeof( struct V_131 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_84 ) +
2 + sizeof( T_3 ) +
V_17 -> V_103 ;
V_168 = F_80 ( sizeof( * V_168 ) + V_169 + V_170 , V_59 ) ;
V_80 = F_81 ( F_82 ( V_169 , V_170 ) ) ;
if ( ! V_168 || ! V_80 )
goto V_178;
V_168 -> V_179 = ( ( T_2 * ) V_168 ) + sizeof( * V_168 ) ;
V_2 = (struct V_1 * ) F_39 ( V_80 , V_173 ) ;
memset ( V_2 , 0 , V_173 ) ;
V_2 -> V_180 = F_65 ( V_181 |
V_182 ) ;
F_83 ( V_2 -> V_183 ) ;
memcpy ( V_2 -> V_67 , V_13 -> V_41 . V_184 , V_78 ) ;
memcpy ( V_2 -> V_185 , V_13 -> V_41 . V_184 , V_78 ) ;
F_84 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_174 . V_186 =
F_65 ( V_13 -> V_41 . V_42 . V_186 ) ;
V_2 -> V_3 . V_174 . V_187 |= F_65 (
V_13 -> V_3 . V_18 . V_188 ? V_189 : 0 ) ;
V_81 = F_39 ( V_80 , 2 ) ;
* V_81 ++ = V_190 ;
* V_81 ++ = 0x0 ;
F_49 () ;
V_172 = F_50 ( V_17 -> V_172 ) ;
if ( V_172 ) {
T_3 V_191 ;
V_81 = F_39 ( V_80 , 13 ) ;
memset ( V_81 , 0 , 13 ) ;
* V_81 ++ = V_192 ;
* V_81 ++ = 3 ;
* V_81 ++ = 0x0 ;
* V_81 ++ = F_53 (
V_172 -> V_193 . V_43 . V_44 -> V_111 ) ;
V_13 -> V_194 = V_173 + 6 ;
* V_81 ++ = V_172 -> V_193 . V_195 ;
* V_81 ++ = V_196 ;
* V_81 ++ = 6 ;
if ( V_17 -> V_197 ) {
* V_81 ++ = V_17 -> V_88 . V_152 ;
* V_81 |= V_198 ;
} else {
* V_81 ++ = V_17 -> V_199 ;
}
* V_81 ++ |= V_172 -> V_193 . V_200 ?
V_201 : 0x00 ;
F_44 ( V_202 , V_81 ) ;
V_81 += 2 ;
V_191 = F_65 ( V_17 -> V_191 ) ;
memcpy ( V_81 , & V_191 , 2 ) ;
V_81 += 2 ;
}
F_52 () ;
if ( F_85 ( V_13 , V_80 , true , V_113 ) ||
F_48 ( V_13 , V_80 ) )
goto V_178;
V_168 -> V_169 = V_80 -> V_102 ;
memcpy ( V_168 -> V_179 , V_80 -> V_11 , V_168 -> V_169 ) ;
F_86 ( V_80 , 0 ) ;
V_168 -> V_203 = V_168 -> V_179 + V_168 -> V_169 ;
if ( F_87 ( V_13 , V_80 , true , V_113 ) ||
F_47 ( V_13 , V_80 ) ||
F_54 ( V_13 , V_80 ) ||
F_56 ( V_13 , V_80 ) ||
F_42 ( V_13 , V_80 ) ||
F_37 ( V_13 , V_80 ) ||
F_43 ( V_13 , V_80 ) ||
F_45 ( V_13 , V_80 ) )
goto V_178;
V_168 -> V_170 = V_80 -> V_102 ;
memcpy ( V_168 -> V_203 , V_80 -> V_11 , V_168 -> V_170 ) ;
F_88 ( V_80 ) ;
F_89 ( V_17 -> V_174 , V_168 ) ;
return 0 ;
V_178:
F_30 ( V_168 ) ;
F_88 ( V_80 ) ;
return - V_60 ;
}
static int
F_90 ( struct V_12 * V_13 )
{
struct V_167 * V_204 ;
int V_205 ;
V_204 = F_91 ( V_13 -> V_3 . V_18 . V_174 ,
F_92 ( & V_13 -> V_206 . V_207 ) ) ;
V_205 = F_77 ( & V_13 -> V_3 . V_18 ) ;
if ( V_205 )
return V_205 ;
if ( V_204 )
F_93 ( V_204 , V_208 ) ;
return 0 ;
}
void F_22 ( struct V_12 * V_13 ,
T_1 V_49 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_209 = V_49 ;
T_1 V_210 ;
if ( ! V_209 )
return;
F_94 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_9 ( V_210 , & V_17 -> V_211 ) ;
F_9 ( V_212 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_95 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_49 = V_51 |
V_213 |
V_214 |
V_215 |
V_216 ;
V_15 -> V_217 ++ ;
F_96 ( & V_15 -> V_218 ) ;
F_97 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_219 = F_98 ( V_17 -> V_37 ) ;
V_17 -> V_93 = false ;
V_17 -> V_220 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_61 ( V_17 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_132 =
V_17 -> V_88 . V_221 ;
V_13 -> V_41 . V_42 . V_222 = true ;
V_49 |= F_99 ( V_13 ) ;
if ( F_77 ( V_17 ) ) {
F_100 ( V_13 ) ;
return - V_60 ;
}
F_101 ( V_13 , V_49 ) ;
F_102 ( V_13 -> V_223 ) ;
return 0 ;
}
void F_100 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_167 * V_168 ;
F_103 ( V_13 -> V_223 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_222 = false ;
F_62 ( V_224 , & V_13 -> V_225 ) ;
F_101 ( V_13 , V_213 ) ;
V_168 = F_91 ( V_17 -> V_174 ,
F_92 ( & V_13 -> V_206 . V_207 ) ) ;
F_89 ( V_17 -> V_174 , NULL ) ;
F_93 ( V_168 , V_208 ) ;
F_104 ( V_13 ) ;
F_105 ( V_13 ) ;
V_15 -> V_226 -= F_106 ( & V_17 -> V_227 . V_228 ) ;
F_107 ( & V_17 -> V_227 . V_228 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_161 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_136 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_229 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_211 = 0 ;
V_15 -> V_217 -- ;
F_108 ( & V_15 -> V_218 ) ;
F_97 ( V_15 ) ;
}
static bool
F_109 ( struct V_12 * V_13 ,
struct V_23 * V_230 , bool V_174 )
{
struct V_231 V_232 ;
struct V_233 V_234 ;
struct V_105 * V_106 ;
struct V_235 * V_236 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
enum V_112 V_113 = F_13 ( V_13 ) ;
int V_237 , V_238 ;
T_1 V_239 ;
if ( V_13 -> V_41 . V_240 )
return true ;
if ( ! V_17 -> V_29 )
return false ;
V_239 = V_241 ;
switch ( V_13 -> V_41 . V_42 . V_43 . V_120 ) {
case V_121 :
V_239 |= V_242 ;
case V_243 :
V_239 |= V_244 ;
break;
default:
break;
}
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_237 = F_110 ( V_13 , V_230 , V_174 , V_113 ,
V_239 , V_13 -> V_41 . V_184 ,
& V_234 ) ;
if ( V_237 < 0 )
return false ;
if ( V_237 )
return false ;
V_232 . V_43 = V_234 . V_43 ;
V_232 . V_195 = V_234 . V_195 ;
if ( V_13 -> V_41 . V_42 . V_43 . V_44 -> V_113 !=
V_232 . V_43 . V_44 -> V_113 )
return false ;
if ( ! F_111 ( V_13 -> V_15 -> V_21 . V_116 , & V_232 . V_43 ,
V_245 ) ) {
F_112 ( V_13 ,
L_2 ,
V_13 -> V_41 . V_184 ,
V_232 . V_43 . V_44 -> V_111 ,
V_232 . V_43 . V_120 ,
V_232 . V_43 . V_246 ,
V_232 . V_43 . V_247 ) ;
return false ;
}
V_237 = F_113 ( V_13 -> V_15 -> V_21 . V_116 ,
& V_232 . V_43 ) ;
if ( V_237 < 0 )
return false ;
if ( V_237 ) {
V_232 . V_248 = true ;
return false ;
}
F_49 () ;
V_106 = F_50 ( V_13 -> V_41 . V_106 ) ;
if ( ! V_106 )
goto V_249;
V_236 = F_79 ( V_106 , struct V_235 , V_250 ) ;
if ( V_236 -> V_251 > 1 )
goto V_249;
V_238 = 0 ;
F_114 (chanctx, &sdata->local->chanctx_list, list)
V_238 ++ ;
if ( V_238 > 1 )
goto V_249;
F_52 () ;
F_115 ( V_13 ,
L_3 ,
V_232 . V_43 . V_44 -> V_111 ) ;
V_232 . V_200 = V_234 . V_252 & V_201 ;
if ( V_174 ) {
V_17 -> V_199 = V_234 . V_151 - 1 ;
if ( V_17 -> V_191 >= V_234 . V_191 )
return false ;
V_17 -> V_191 = V_234 . V_191 ;
}
if ( V_17 -> V_199 < V_17 -> V_88 . V_152 ) {
if ( F_116 ( V_13 , & V_232 , false ) < 0 )
return false ;
} else {
return false ;
}
V_13 -> V_253 = V_232 . V_248 ;
if ( V_232 . V_200 )
F_117 ( & V_13 -> V_15 -> V_21 ,
V_254 ,
V_255 ) ;
V_13 -> V_15 -> V_256 = V_232 . V_43 ;
V_13 -> V_41 . V_240 = true ;
F_101 ( V_13 , V_237 ) ;
F_118 ( V_13 , & V_232 . V_43 ) ;
return true ;
V_249:
F_52 () ;
return false ;
}
static void
F_119 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_102 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_79 * V_257 ;
struct V_167 * V_168 ;
struct V_1 * V_138 ;
struct V_23 V_230 ;
T_4 V_258 ;
T_2 * V_81 ;
V_81 = V_2 -> V_3 . V_259 . V_260 ;
V_258 = ( T_2 * ) V_81 - ( T_2 * ) V_2 ;
if ( V_258 > V_102 )
return;
F_120 ( V_81 , V_102 - V_258 , false , & V_230 ) ;
if ( ! V_230 . V_29 )
return;
if ( ( ! F_34 ( V_2 -> V_183 , V_13 -> V_41 . V_184 ) &&
! F_121 ( V_2 -> V_183 ) ) ||
V_230 . V_261 != 0 )
return;
if ( V_230 . V_28 != 0 &&
( V_230 . V_28 != V_17 -> V_28 ||
memcmp ( V_230 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_49 () ;
V_168 = F_50 ( V_17 -> V_174 ) ;
if ( ! V_168 )
goto V_262;
V_257 = F_81 ( V_15 -> V_263 +
V_168 -> V_169 + V_168 -> V_170 ) ;
if ( ! V_257 )
goto V_262;
F_122 ( V_257 , V_15 -> V_263 ) ;
memcpy ( F_39 ( V_257 , V_168 -> V_169 ) , V_168 -> V_179 , V_168 -> V_169 ) ;
memcpy ( F_39 ( V_257 , V_168 -> V_170 ) , V_168 -> V_203 , V_168 -> V_170 ) ;
V_138 = (struct V_1 * ) V_257 -> V_11 ;
V_138 -> V_180 = F_65 ( V_181 |
V_264 ) ;
memcpy ( V_138 -> V_183 , V_2 -> V_67 , V_78 ) ;
F_123 ( V_257 ) -> V_154 |= V_265 ;
F_124 ( V_13 , V_257 ) ;
V_262:
F_52 () ;
}
static void F_125 ( struct V_12 * V_13 ,
T_5 V_266 ,
struct V_1 * V_2 ,
T_4 V_102 ,
struct V_267 * V_268 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_230 ;
struct V_107 * V_126 ;
T_4 V_258 ;
int V_269 ;
enum V_112 V_113 = V_268 -> V_113 ;
if ( V_266 == V_264 &&
! F_34 ( V_2 -> V_183 , V_13 -> V_41 . V_184 ) )
return;
V_258 = ( T_2 * ) V_2 -> V_3 . V_270 . V_260 - ( T_2 * ) V_2 ;
if ( V_258 > V_102 )
return;
F_120 ( V_2 -> V_3 . V_270 . V_260 , V_102 - V_258 ,
false , & V_230 ) ;
if ( ( ! V_230 . V_29 || ! V_230 . V_31 ) ||
( V_230 . V_271 && V_13 -> V_3 . V_18 . V_188 == V_272 ) ||
( ! V_230 . V_271 && V_13 -> V_3 . V_18 . V_188 != V_272 ) )
return;
if ( V_230 . V_273 )
V_269 = F_126 ( V_230 . V_273 [ 0 ] , V_113 ) ;
else
V_269 = V_268 -> V_269 ;
V_126 = F_127 ( V_15 -> V_21 . V_116 , V_269 ) ;
if ( ! V_126 || V_126 -> V_154 & V_245 )
return;
if ( F_11 ( V_13 , & V_230 ) )
F_128 ( V_13 , V_2 -> V_67 , & V_230 ) ;
if ( V_17 -> V_219 )
V_17 -> V_219 -> V_274 ( V_13 ,
V_266 , V_2 , & V_230 , V_268 ) ;
if ( ! V_17 -> V_197 )
F_109 ( V_13 , & V_230 , true ) ;
}
int F_129 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_171 * V_275 ;
int V_205 = 0 ;
V_17 -> V_197 = false ;
V_17 -> V_199 = 0 ;
V_275 = F_50 ( V_17 -> V_172 ) ;
F_89 ( V_17 -> V_172 , NULL ) ;
F_93 ( V_275 , V_208 ) ;
V_205 = F_90 ( V_13 ) ;
if ( V_205 )
return - V_108 ;
F_101 ( V_13 , V_51 ) ;
F_115 ( V_13 , L_4 ,
V_13 -> V_41 . V_42 . V_43 . V_44 -> V_111 ) ;
return 0 ;
}
int F_116 ( struct V_12 * V_13 ,
struct V_231 * V_276 ,
bool V_277 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_171 * V_275 ;
int V_205 = 0 ;
V_275 = F_24 ( sizeof( * V_275 ) ,
V_76 ) ;
if ( ! V_275 )
return - V_60 ;
memcpy ( & V_275 -> V_193 , V_276 ,
sizeof( struct V_231 ) ) ;
F_89 ( V_17 -> V_172 , V_275 ) ;
V_205 = F_90 ( V_13 ) ;
if ( V_205 ) {
V_275 = F_50 ( V_17 -> V_172 ) ;
F_89 ( V_17 -> V_172 , NULL ) ;
F_93 ( V_275 , V_208 ) ;
return V_205 ;
}
F_101 ( V_13 , V_51 ) ;
if ( V_277 )
F_130 ( V_13 , V_276 ) ;
return 0 ;
}
static int F_131 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_102 )
{
struct V_1 * V_278 ;
struct V_79 * V_80 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_2 * V_81 = V_2 -> V_3 . V_4 . V_3 . V_279 . V_260 ;
T_4 V_280 ;
V_80 = F_81 ( V_15 -> V_263 + V_102 ) ;
if ( ! V_80 )
return - V_60 ;
F_122 ( V_80 , V_15 -> V_263 ) ;
V_278 = (struct V_1 * ) F_39 ( V_80 , V_102 ) ;
V_280 = ( V_102 < 42 ) ? 7 : 10 ;
* ( V_81 + V_280 ) -= 1 ;
* ( V_81 + V_280 + 1 ) &= ~ V_198 ;
memcpy ( V_278 , V_2 , V_102 ) ;
F_83 ( V_278 -> V_183 ) ;
memcpy ( V_278 -> V_67 , V_13 -> V_41 . V_184 , V_78 ) ;
memcpy ( V_278 -> V_185 , V_13 -> V_41 . V_184 , V_78 ) ;
F_124 ( V_13 , V_80 ) ;
return 0 ;
}
static void F_132 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_102 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_230 ;
T_5 V_191 ;
bool V_281 = true ;
T_4 V_258 ;
T_2 * V_81 ;
if ( V_2 -> V_3 . V_4 . V_3 . V_282 . V_6 !=
V_283 )
return;
V_81 = V_2 -> V_3 . V_4 . V_3 . V_279 . V_260 ;
V_258 = F_78 ( struct V_1 ,
V_3 . V_4 . V_3 . V_279 . V_260 ) ;
F_120 ( V_81 , V_102 - V_258 , false , & V_230 ) ;
V_17 -> V_199 = V_230 . V_284 -> V_285 ;
if ( ! -- V_17 -> V_199 )
V_281 = false ;
V_191 = F_133 ( V_230 . V_284 -> V_286 ) ;
if ( V_17 -> V_191 >= V_191 )
return;
V_17 -> V_191 = V_191 ;
if ( ! F_109 ( V_13 , & V_230 , false ) ) {
F_115 ( V_13 , L_5 ) ;
return;
}
if ( V_281 ) {
if ( F_131 ( V_13 , V_2 , V_102 ) < 0 )
F_115 ( V_13 , L_6 ) ;
}
}
static void F_134 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_102 ,
struct V_267 * V_268 )
{
switch ( V_2 -> V_3 . V_4 . V_287 ) {
case V_288 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_289 . V_6 ) {
case V_290 :
case V_291 :
case V_292 :
F_135 ( V_13 , V_2 , V_102 , V_268 ) ;
break;
}
break;
case V_293 :
if ( F_1 ( V_2 ) )
F_136 ( V_13 , V_2 , V_102 ) ;
break;
case V_294 :
F_132 ( V_13 , V_2 , V_102 ) ;
break;
}
}
void F_137 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_267 * V_268 ;
struct V_1 * V_2 ;
T_5 V_266 ;
F_138 ( V_13 ) ;
if ( ! V_13 -> V_206 . V_28 )
goto V_262;
V_268 = F_139 ( V_80 ) ;
V_2 = (struct V_1 * ) V_80 -> V_11 ;
V_266 = F_133 ( V_2 -> V_180 ) & V_295 ;
switch ( V_266 ) {
case V_264 :
case V_182 :
F_125 ( V_13 , V_266 , V_2 , V_80 -> V_102 ,
V_268 ) ;
break;
case V_296 :
F_119 ( V_13 , V_2 , V_80 -> V_102 ) ;
break;
case V_297 :
F_134 ( V_13 , V_2 , V_80 -> V_102 , V_268 ) ;
break;
}
V_262:
F_140 ( V_13 ) ;
}
static void F_141 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_210 , V_49 = 0 ;
F_94 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_62 ( V_210 , & V_17 -> V_211 ) ;
V_49 |= F_142 ( V_210 ) ;
}
if ( V_13 -> V_41 . V_42 . V_222 &&
( V_49 & ( V_51 |
V_214 |
V_215 |
V_216 ) ) )
if ( F_90 ( V_13 ) )
return;
F_101 ( V_13 , V_49 ) ;
}
void F_143 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_138 ( V_13 ) ;
if ( ! V_13 -> V_206 . V_28 )
goto V_262;
if ( V_17 -> V_298 &&
F_33 ( V_73 ,
V_17 -> V_299 + F_144 ( V_17 -> V_88 . V_300 ) ) )
F_145 ( V_13 ) ;
if ( F_146 ( V_301 , & V_17 -> V_20 ) )
F_147 () ;
if ( F_146 ( V_302 , & V_17 -> V_20 ) )
F_148 () ;
if ( F_146 ( V_19 , & V_17 -> V_20 ) )
F_69 ( V_13 ) ;
if ( F_146 ( V_133 , & V_17 -> V_20 ) )
F_74 ( V_13 ) ;
if ( F_146 ( V_303 , & V_17 -> V_20 ) )
F_149 ( V_13 ) ;
if ( F_146 ( V_212 , & V_17 -> V_20 ) )
F_141 ( V_13 ) ;
V_262:
F_140 ( V_13 ) ;
}
void F_150 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_49 () ;
F_114 (sdata, &local->interfaces, list)
if ( F_151 ( & V_13 -> V_41 ) &&
F_152 ( V_13 ) )
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
F_52 () ;
}
void F_153 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_304 [ V_78 ] = {} ;
F_154 ( & V_17 -> V_161 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_50 = true ;
F_155 ( & V_17 -> V_305 , 0 ) ;
F_23 ( V_13 ) ;
V_17 -> V_299 = V_73 ;
V_17 -> V_306 = V_73 ;
V_17 -> V_197 = false ;
if ( ! V_8 )
F_2 () ;
F_154 ( & V_17 -> V_229 ,
F_59 ,
( unsigned long ) V_13 ) ;
F_154 ( & V_17 -> V_136 ,
F_60 ,
( unsigned long ) V_13 ) ;
F_25 ( & V_17 -> V_307 . V_66 ) ;
F_156 ( & V_17 -> V_227 . V_228 ) ;
F_157 ( & V_17 -> V_308 ) ;
F_157 ( & V_17 -> V_309 ) ;
F_158 ( V_17 -> V_174 , NULL ) ;
V_13 -> V_41 . V_42 . V_185 = V_304 ;
}
