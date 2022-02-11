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
enum V_112 V_113 ;
T_2 * V_81 ;
struct V_12 * V_13 ;
int V_171 = F_78 ( struct V_1 , V_3 . V_172 ) +
sizeof( V_2 -> V_3 . V_172 ) ;
V_13 = F_79 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_49 () ;
V_106 = F_50 ( V_13 -> V_41 . V_106 ) ;
V_113 = V_106 -> V_109 . V_44 -> V_113 ;
F_52 () ;
V_169 = V_171 +
2 +
2 + 8 +
2 + 3 ;
V_170 = 2 + ( V_173 - 8 ) +
2 + sizeof( struct V_124 ) +
2 + sizeof( struct V_131 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_84 ) +
2 + sizeof( T_3 ) +
V_17 -> V_103 ;
V_168 = F_80 ( sizeof( * V_168 ) + V_169 + V_170 , V_59 ) ;
V_80 = F_81 ( F_82 ( V_169 , V_170 ) ) ;
if ( ! V_168 || ! V_80 )
goto V_174;
V_168 -> V_175 = ( ( T_2 * ) V_168 ) + sizeof( * V_168 ) ;
V_2 = (struct V_1 * ) F_39 ( V_80 , V_171 ) ;
memset ( V_2 , 0 , V_171 ) ;
V_2 -> V_176 = F_65 ( V_177 |
V_178 ) ;
F_83 ( V_2 -> V_179 ) ;
memcpy ( V_2 -> V_67 , V_13 -> V_41 . V_180 , V_78 ) ;
memcpy ( V_2 -> V_181 , V_13 -> V_41 . V_180 , V_78 ) ;
F_84 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_172 . V_182 =
F_65 ( V_13 -> V_41 . V_42 . V_182 ) ;
V_2 -> V_3 . V_172 . V_183 |= F_65 (
V_13 -> V_3 . V_18 . V_184 ? V_185 : 0 ) ;
V_81 = F_39 ( V_80 , 2 ) ;
* V_81 ++ = V_186 ;
* V_81 ++ = 0x0 ;
if ( F_85 ( V_13 , V_80 , true , V_113 ) ||
F_48 ( V_13 , V_80 ) )
goto V_174;
V_168 -> V_169 = V_80 -> V_102 ;
memcpy ( V_168 -> V_175 , V_80 -> V_11 , V_168 -> V_169 ) ;
F_86 ( V_80 , 0 ) ;
V_168 -> V_187 = V_168 -> V_175 + V_168 -> V_169 ;
if ( F_87 ( V_13 , V_80 , true , V_113 ) ||
F_47 ( V_13 , V_80 ) ||
F_54 ( V_13 , V_80 ) ||
F_56 ( V_13 , V_80 ) ||
F_42 ( V_13 , V_80 ) ||
F_37 ( V_13 , V_80 ) ||
F_43 ( V_13 , V_80 ) ||
F_45 ( V_13 , V_80 ) )
goto V_174;
V_168 -> V_170 = V_80 -> V_102 ;
memcpy ( V_168 -> V_187 , V_80 -> V_11 , V_168 -> V_170 ) ;
F_88 ( V_80 ) ;
F_89 ( V_17 -> V_172 , V_168 ) ;
return 0 ;
V_174:
F_30 ( V_168 ) ;
F_88 ( V_80 ) ;
return - V_60 ;
}
static int
F_90 ( struct V_12 * V_13 )
{
struct V_167 * V_188 ;
int V_189 ;
V_188 = F_91 ( V_13 -> V_3 . V_18 . V_172 ,
F_92 ( & V_13 -> V_190 . V_191 ) ) ;
V_189 = F_77 ( & V_13 -> V_3 . V_18 ) ;
if ( V_189 )
return V_189 ;
if ( V_188 )
F_93 ( V_188 , V_192 ) ;
return 0 ;
}
void F_22 ( struct V_12 * V_13 ,
T_1 V_49 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_193 = V_49 ;
T_1 V_194 ;
if ( ! V_193 )
return;
F_94 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_9 ( V_194 , & V_17 -> V_195 ) ;
F_9 ( V_196 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_95 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_49 = V_51 |
V_197 |
V_198 |
V_199 |
V_200 ;
V_15 -> V_201 ++ ;
F_96 ( & V_15 -> V_202 ) ;
F_97 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_203 = F_98 ( V_17 -> V_37 ) ;
V_17 -> V_93 = false ;
V_17 -> V_204 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_61 ( V_17 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_132 =
V_17 -> V_88 . V_205 ;
V_13 -> V_41 . V_42 . V_206 = true ;
V_49 |= F_99 ( V_13 ) ;
if ( F_77 ( V_17 ) ) {
F_100 ( V_13 ) ;
return - V_60 ;
}
F_101 ( V_13 , V_49 ) ;
F_102 ( V_13 -> V_207 ) ;
return 0 ;
}
void F_100 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_167 * V_168 ;
F_103 ( V_13 -> V_207 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_206 = false ;
F_62 ( V_208 , & V_13 -> V_209 ) ;
F_101 ( V_13 , V_197 ) ;
V_168 = F_91 ( V_17 -> V_172 ,
F_92 ( & V_13 -> V_190 . V_191 ) ) ;
F_89 ( V_17 -> V_172 , NULL ) ;
F_93 ( V_168 , V_192 ) ;
F_104 ( V_13 ) ;
F_105 ( V_13 ) ;
V_15 -> V_210 -= F_106 ( & V_17 -> V_211 . V_212 ) ;
F_107 ( & V_17 -> V_211 . V_212 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_161 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_136 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_213 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_195 = 0 ;
V_15 -> V_201 -- ;
F_108 ( & V_15 -> V_202 ) ;
F_97 ( V_15 ) ;
}
static void
F_109 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_102 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_79 * V_214 ;
struct V_167 * V_168 ;
struct V_1 * V_138 ;
struct V_23 V_215 ;
T_4 V_216 ;
T_2 * V_81 ;
V_81 = V_2 -> V_3 . V_217 . V_218 ;
V_216 = ( T_2 * ) V_81 - ( T_2 * ) V_2 ;
if ( V_216 > V_102 )
return;
F_110 ( V_81 , V_102 - V_216 , false , & V_215 ) ;
if ( ! V_215 . V_29 )
return;
if ( ( ! F_34 ( V_2 -> V_179 , V_13 -> V_41 . V_180 ) &&
! F_111 ( V_2 -> V_179 ) ) ||
V_215 . V_219 != 0 )
return;
if ( V_215 . V_28 != 0 &&
( V_215 . V_28 != V_17 -> V_28 ||
memcmp ( V_215 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_49 () ;
V_168 = F_50 ( V_17 -> V_172 ) ;
if ( ! V_168 )
goto V_220;
V_214 = F_81 ( V_15 -> V_221 +
V_168 -> V_169 + V_168 -> V_170 ) ;
if ( ! V_214 )
goto V_220;
F_112 ( V_214 , V_15 -> V_221 ) ;
memcpy ( F_39 ( V_214 , V_168 -> V_169 ) , V_168 -> V_175 , V_168 -> V_169 ) ;
memcpy ( F_39 ( V_214 , V_168 -> V_170 ) , V_168 -> V_187 , V_168 -> V_170 ) ;
V_138 = (struct V_1 * ) V_214 -> V_11 ;
V_138 -> V_176 = F_65 ( V_177 |
V_222 ) ;
memcpy ( V_138 -> V_179 , V_2 -> V_67 , V_78 ) ;
F_113 ( V_214 ) -> V_154 |= V_223 ;
F_114 ( V_13 , V_214 ) ;
V_220:
F_52 () ;
}
static void F_115 ( struct V_12 * V_13 ,
T_5 V_224 ,
struct V_1 * V_2 ,
T_4 V_102 ,
struct V_225 * V_226 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_215 ;
struct V_107 * V_126 ;
T_4 V_216 ;
int V_227 ;
enum V_112 V_113 = V_226 -> V_113 ;
if ( V_224 == V_222 &&
! F_34 ( V_2 -> V_179 , V_13 -> V_41 . V_180 ) )
return;
V_216 = ( T_2 * ) V_2 -> V_3 . V_228 . V_218 - ( T_2 * ) V_2 ;
if ( V_216 > V_102 )
return;
F_110 ( V_2 -> V_3 . V_228 . V_218 , V_102 - V_216 ,
false , & V_215 ) ;
if ( ( ! V_215 . V_29 || ! V_215 . V_31 ) ||
( V_215 . V_229 && V_13 -> V_3 . V_18 . V_184 == V_230 ) ||
( ! V_215 . V_229 && V_13 -> V_3 . V_18 . V_184 != V_230 ) )
return;
if ( V_215 . V_231 )
V_227 = F_116 ( V_215 . V_231 [ 0 ] , V_113 ) ;
else
V_227 = V_226 -> V_227 ;
V_126 = F_117 ( V_15 -> V_21 . V_116 , V_227 ) ;
if ( ! V_126 || V_126 -> V_154 & V_232 )
return;
if ( F_11 ( V_13 , & V_215 ) )
F_118 ( V_13 , V_2 -> V_67 , & V_215 ) ;
if ( V_17 -> V_203 )
V_17 -> V_203 -> V_233 ( V_13 ,
V_224 , V_2 , & V_215 , V_226 ) ;
}
static void F_119 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_102 ,
struct V_225 * V_226 )
{
switch ( V_2 -> V_3 . V_4 . V_234 ) {
case V_235 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_236 . V_6 ) {
case V_237 :
case V_238 :
case V_239 :
F_120 ( V_13 , V_2 , V_102 , V_226 ) ;
break;
}
break;
case V_240 :
if ( F_1 ( V_2 ) )
F_121 ( V_13 , V_2 , V_102 ) ;
break;
}
}
void F_122 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_225 * V_226 ;
struct V_1 * V_2 ;
T_5 V_224 ;
F_123 ( V_13 ) ;
if ( ! V_13 -> V_190 . V_28 )
goto V_220;
V_226 = F_124 ( V_80 ) ;
V_2 = (struct V_1 * ) V_80 -> V_11 ;
V_224 = F_125 ( V_2 -> V_176 ) & V_241 ;
switch ( V_224 ) {
case V_222 :
case V_178 :
F_115 ( V_13 , V_224 , V_2 , V_80 -> V_102 ,
V_226 ) ;
break;
case V_242 :
F_109 ( V_13 , V_2 , V_80 -> V_102 ) ;
break;
case V_243 :
F_119 ( V_13 , V_2 , V_80 -> V_102 , V_226 ) ;
break;
}
V_220:
F_126 ( V_13 ) ;
}
static void F_127 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_194 , V_49 = 0 ;
F_94 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_62 ( V_194 , & V_17 -> V_195 ) ;
V_49 |= F_128 ( V_194 ) ;
}
if ( V_13 -> V_41 . V_42 . V_206 &&
( V_49 & ( V_51 |
V_198 |
V_199 |
V_200 ) ) )
if ( F_90 ( V_13 ) )
return;
F_101 ( V_13 , V_49 ) ;
}
void F_129 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_123 ( V_13 ) ;
if ( ! V_13 -> V_190 . V_28 )
goto V_220;
if ( V_17 -> V_244 &&
F_33 ( V_73 ,
V_17 -> V_245 + F_130 ( V_17 -> V_88 . V_246 ) ) )
F_131 ( V_13 ) ;
if ( F_132 ( V_247 , & V_17 -> V_20 ) )
F_133 () ;
if ( F_132 ( V_248 , & V_17 -> V_20 ) )
F_134 () ;
if ( F_132 ( V_19 , & V_17 -> V_20 ) )
F_69 ( V_13 ) ;
if ( F_132 ( V_133 , & V_17 -> V_20 ) )
F_74 ( V_13 ) ;
if ( F_132 ( V_249 , & V_17 -> V_20 ) )
F_135 ( V_13 ) ;
if ( F_132 ( V_196 , & V_17 -> V_20 ) )
F_127 ( V_13 ) ;
V_220:
F_126 ( V_13 ) ;
}
void F_136 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_49 () ;
F_137 (sdata, &local->interfaces, list)
if ( F_138 ( & V_13 -> V_41 ) &&
F_139 ( V_13 ) )
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
F_52 () ;
}
void F_140 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_250 [ V_78 ] = {} ;
F_141 ( & V_17 -> V_161 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_50 = true ;
V_17 -> V_251 = 0 ;
V_17 -> V_252 = 0 ;
V_17 -> V_253 = 0 ;
F_142 ( & V_17 -> V_254 , 0 ) ;
F_23 ( V_13 ) ;
V_17 -> V_245 = V_73 ;
V_17 -> V_255 = V_73 ;
if ( ! V_8 )
F_2 () ;
F_141 ( & V_17 -> V_213 ,
F_59 ,
( unsigned long ) V_13 ) ;
F_141 ( & V_17 -> V_136 ,
F_60 ,
( unsigned long ) V_13 ) ;
F_25 ( & V_17 -> V_256 . V_66 ) ;
F_143 ( & V_17 -> V_211 . V_212 ) ;
F_144 ( & V_17 -> V_257 ) ;
F_144 ( & V_17 -> V_258 ) ;
F_145 ( V_17 -> V_172 , NULL ) ;
V_13 -> V_41 . V_42 . V_181 = V_250 ;
}
