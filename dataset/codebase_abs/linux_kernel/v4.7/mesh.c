bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 . V_3 . V_5 . V_6 ==
V_7 ) ;
}
void F_2 ( void )
{
V_8 = 1 ;
V_9 = F_3 ( L_1 , sizeof( struct V_10 ) ,
0 , 0 , NULL ) ;
}
void F_4 ( void )
{
if ( ! V_8 )
return;
F_5 ( V_9 ) ;
}
static void F_6 ( unsigned long V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 ;
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_7 ( V_19 , & V_17 -> V_20 ) ;
F_8 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
}
bool F_9 ( struct V_12 * V_13 ,
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
F_10 ( V_13 , V_24 , F_11 ( V_13 ) ,
& V_25 ) ;
if ( V_13 -> V_41 . V_42 . V_25 != V_25 )
return false ;
F_12 ( & V_27 , V_13 -> V_41 . V_42 . V_43 . V_44 ,
V_45 ) ;
F_13 ( V_24 -> V_46 , & V_27 ) ;
F_14 ( V_24 -> V_47 , & V_27 ) ;
if ( ! F_15 ( & V_13 -> V_41 . V_42 . V_43 ,
& V_27 ) )
return false ;
return true ;
}
bool F_16 ( struct V_23 * V_24 )
{
return ( V_24 -> V_31 -> V_48 &
V_49 ) != 0 ;
}
T_1 F_17 ( struct V_12 * V_13 )
{
bool V_50 ;
T_1 V_51 = 0 ;
V_50 = F_18 ( V_13 ) ;
if ( V_50 != V_13 -> V_3 . V_18 . V_52 ) {
V_13 -> V_3 . V_18 . V_52 = V_50 ;
V_51 = V_53 ;
}
return V_51 ;
}
void F_19 ( struct V_54 * V_55 )
{
struct V_12 * V_13 = V_55 -> V_13 ;
T_1 V_51 = 0 ;
if ( V_13 -> V_3 . V_18 . V_56 &&
V_55 -> V_18 -> V_57 == V_58 )
V_51 |= F_20 ( V_13 ) ;
V_51 |= F_17 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_56 ) {
V_51 |= F_21 ( V_55 ) ;
F_22 ( & V_55 -> V_18 -> V_59 ) ;
}
F_23 ( V_55 ) ;
F_24 () ;
if ( V_51 )
F_25 ( V_13 , V_51 ) ;
}
int F_26 ( struct V_12 * V_13 )
{
int V_60 ;
V_13 -> V_3 . V_18 . V_61 = F_27 ( sizeof( struct V_62 ) , V_63 ) ;
if ( ! V_13 -> V_3 . V_18 . V_61 )
return - V_64 ;
V_13 -> V_3 . V_18 . V_61 -> V_65 = V_66 - 1 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ )
F_28 ( & V_13 -> V_3 . V_18 . V_61 -> V_67 [ V_60 ] ) ;
return 0 ;
}
void F_29 ( struct V_12 * V_13 )
{
struct V_62 * V_61 = V_13 -> V_3 . V_18 . V_61 ;
struct V_10 * V_68 ;
struct V_69 * V_70 ;
int V_60 ;
if ( ! V_13 -> V_3 . V_18 . V_61 )
return;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
F_30 (p, n, &rmc->bucket[i], list) {
F_31 ( & V_68 -> V_71 ) ;
F_32 ( V_9 , V_68 ) ;
}
}
F_33 ( V_61 ) ;
V_13 -> V_3 . V_18 . V_61 = NULL ;
}
int F_34 ( struct V_12 * V_13 ,
const T_2 * V_72 , struct V_73 * V_74 )
{
struct V_62 * V_61 = V_13 -> V_3 . V_18 . V_61 ;
T_1 V_75 = 0 ;
int V_76 = 0 ;
T_2 V_77 ;
struct V_10 * V_68 ;
struct V_69 * V_70 ;
if ( ! V_61 )
return - 1 ;
memcpy ( & V_75 , & V_74 -> V_75 , sizeof( V_74 -> V_75 ) ) ;
V_77 = F_35 ( V_74 -> V_75 ) & V_61 -> V_65 ;
F_30 (p, n, &rmc->bucket[idx], list) {
++ V_76 ;
if ( F_36 ( V_78 , V_68 -> V_79 ) ||
V_76 == V_80 ) {
F_31 ( & V_68 -> V_71 ) ;
F_32 ( V_9 , V_68 ) ;
-- V_76 ;
} else if ( ( V_75 == V_68 -> V_75 ) && F_37 ( V_72 , V_68 -> V_72 ) )
return - 1 ;
}
V_68 = F_38 ( V_9 , V_81 ) ;
if ( ! V_68 )
return 0 ;
V_68 -> V_75 = V_75 ;
V_68 -> V_79 = V_78 + V_82 ;
memcpy ( V_68 -> V_72 , V_72 , V_83 ) ;
F_39 ( & V_68 -> V_71 , & V_61 -> V_67 [ V_77 ] ) ;
return 0 ;
}
int F_40 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_86 , V_87 ;
T_2 V_88 = sizeof( struct V_89 ) ;
if ( F_41 ( V_85 ) < 2 + V_88 )
return - V_64 ;
V_86 = F_42 ( V_85 , 2 + V_88 ) ;
* V_86 ++ = V_90 ;
* V_86 ++ = V_88 ;
V_17 -> V_91 = V_86 - V_85 -> V_11 ;
* V_86 ++ = V_17 -> V_30 ;
* V_86 ++ = V_17 -> V_33 ;
* V_86 ++ = V_17 -> V_35 ;
* V_86 ++ = V_17 -> V_37 ;
* V_86 ++ = V_17 -> V_39 ;
V_87 = F_43 ( & V_17 -> V_92 ) ;
V_87 = F_44 ( int , V_87 , V_93 ) ;
* V_86 ++ = V_87 << 1 ;
* V_86 = 0x00 ;
* V_86 |= V_17 -> V_94 . V_95 ?
V_96 : 0x00 ;
* V_86 |= V_17 -> V_52 ?
V_49 : 0x00 ;
* V_86 |= V_17 -> V_97 ?
V_98 : 0x00 ;
* V_86 ++ |= V_17 -> V_99 ?
V_100 : 0x00 ;
* V_86 ++ = 0x00 ;
return 0 ;
}
int F_45 ( struct V_12 * V_13 , struct V_84 * V_85 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_86 ;
if ( F_41 ( V_85 ) < 2 + V_17 -> V_28 )
return - V_64 ;
V_86 = F_42 ( V_85 , 2 + V_17 -> V_28 ) ;
* V_86 ++ = V_101 ;
* V_86 ++ = V_17 -> V_28 ;
if ( V_17 -> V_28 )
memcpy ( V_86 , V_17 -> V_29 , V_17 -> V_28 ) ;
return 0 ;
}
static int F_46 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_86 ;
if ( V_17 -> V_102 == 0 &&
V_17 -> V_97 == 0 &&
V_17 -> V_103 == V_104 )
return 0 ;
if ( F_41 ( V_85 ) < 4 )
return - V_64 ;
V_86 = F_42 ( V_85 , 2 + 2 ) ;
* V_86 ++ = V_105 ;
* V_86 ++ = 2 ;
F_47 ( V_17 -> V_94 . V_106 , V_86 ) ;
return 0 ;
}
int F_48 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_107 , V_108 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_109 )
return 0 ;
V_107 = F_49 ( V_17 -> V_24 , V_17 -> V_109 , 0 ) ;
if ( V_107 ) {
V_108 = V_17 -> V_109 - V_107 ;
V_11 = V_17 -> V_24 + V_107 ;
if ( F_41 ( V_85 ) < V_108 )
return - V_64 ;
memcpy ( F_42 ( V_85 , V_108 ) , V_11 , V_108 ) ;
}
return 0 ;
}
int F_50 ( struct V_12 * V_13 , struct V_84 * V_85 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_108 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_109 )
return 0 ;
V_11 = F_51 ( V_110 , V_17 -> V_24 , V_17 -> V_109 ) ;
if ( ! V_11 )
return 0 ;
V_108 = V_11 [ 1 ] + 2 ;
if ( F_41 ( V_85 ) < V_108 )
return - V_64 ;
memcpy ( F_42 ( V_85 , V_108 ) , V_11 , V_108 ) ;
return 0 ;
}
static int F_52 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_111 * V_112 ;
struct V_113 * V_44 ;
T_2 * V_86 ;
if ( F_41 ( V_85 ) < 3 )
return - V_64 ;
F_53 () ;
V_112 = F_54 ( V_13 -> V_41 . V_112 ) ;
if ( F_55 ( ! V_112 ) ) {
F_56 () ;
return - V_114 ;
}
V_44 = V_112 -> V_115 . V_44 ;
F_56 () ;
V_86 = F_42 ( V_85 , 2 + 1 ) ;
* V_86 ++ = V_116 ;
* V_86 ++ = 1 ;
* V_86 ++ = F_57 ( V_44 -> V_117 ) ;
return 0 ;
}
int F_58 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_118 V_119 = F_11 ( V_13 ) ;
struct V_120 * V_121 ;
T_2 * V_86 ;
V_121 = V_15 -> V_21 . V_122 -> V_123 [ V_119 ] ;
if ( ! V_121 -> V_124 . V_125 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_127 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_128 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_129 )
return 0 ;
if ( F_41 ( V_85 ) < 2 + sizeof( struct V_130 ) )
return - V_64 ;
V_86 = F_42 ( V_85 , 2 + sizeof( struct V_130 ) ) ;
F_59 ( V_86 , & V_121 -> V_124 , V_121 -> V_124 . V_131 ) ;
return 0 ;
}
int F_60 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_111 * V_112 ;
struct V_113 * V_132 ;
struct V_120 * V_121 ;
struct V_133 * V_124 ;
T_2 * V_86 ;
F_53 () ;
V_112 = F_54 ( V_13 -> V_41 . V_112 ) ;
if ( F_55 ( ! V_112 ) ) {
F_56 () ;
return - V_114 ;
}
V_132 = V_112 -> V_115 . V_44 ;
F_56 () ;
V_121 = V_15 -> V_21 . V_122 -> V_123 [ V_132 -> V_119 ] ;
V_124 = & V_121 -> V_124 ;
if ( ! V_124 -> V_125 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_127 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_128 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_129 )
return 0 ;
if ( F_41 ( V_85 ) < 2 + sizeof( struct V_134 ) )
return - V_64 ;
V_86 = F_42 ( V_85 , 2 + sizeof( struct V_134 ) ) ;
F_61 ( V_86 , V_124 , & V_13 -> V_41 . V_42 . V_43 ,
V_13 -> V_41 . V_42 . V_135 ,
false ) ;
return 0 ;
}
int F_62 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_118 V_119 = F_11 ( V_13 ) ;
struct V_120 * V_121 ;
T_2 * V_86 ;
V_121 = V_15 -> V_21 . V_122 -> V_123 [ V_119 ] ;
if ( ! V_121 -> V_136 . V_137 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_127 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_128 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_129 )
return 0 ;
if ( F_41 ( V_85 ) < 2 + sizeof( struct V_138 ) )
return - V_64 ;
V_86 = F_42 ( V_85 , 2 + sizeof( struct V_138 ) ) ;
F_63 ( V_86 , & V_121 -> V_136 , V_121 -> V_136 . V_131 ) ;
return 0 ;
}
int F_64 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_111 * V_112 ;
struct V_113 * V_132 ;
struct V_120 * V_121 ;
struct V_139 * V_136 ;
T_2 * V_86 ;
F_53 () ;
V_112 = F_54 ( V_13 -> V_41 . V_112 ) ;
if ( F_55 ( ! V_112 ) ) {
F_56 () ;
return - V_114 ;
}
V_132 = V_112 -> V_115 . V_44 ;
F_56 () ;
V_121 = V_15 -> V_21 . V_122 -> V_123 [ V_132 -> V_119 ] ;
V_136 = & V_121 -> V_136 ;
if ( ! V_136 -> V_137 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_127 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_128 ||
V_13 -> V_41 . V_42 . V_43 . V_126 == V_129 )
return 0 ;
if ( F_41 ( V_85 ) < 2 + sizeof( struct V_140 ) )
return - V_64 ;
V_86 = F_42 ( V_85 , 2 + sizeof( struct V_140 ) ) ;
F_65 ( V_86 , V_136 ,
& V_13 -> V_41 . V_42 . V_43 ) ;
return 0 ;
}
static void F_66 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
F_8 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
static void F_67 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_7 ( V_141 , & V_17 -> V_20 ) ;
F_8 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_68 ( struct V_16 * V_17 )
{
if ( V_17 -> V_94 . V_142 > V_143 )
F_7 ( V_141 , & V_17 -> V_20 ) ;
else {
F_69 ( V_141 , & V_17 -> V_20 ) ;
F_22 ( & V_17 -> V_144 ) ;
}
}
int F_70 ( struct V_145 * V_146 , T_3 * V_147 ,
const T_2 * V_148 , const T_2 * V_149 )
{
if ( F_71 ( V_148 ) ) {
* V_147 |= F_72 ( V_150 ) ;
memcpy ( V_146 -> V_151 , V_148 , V_83 ) ;
memcpy ( V_146 -> V_152 , V_149 , V_83 ) ;
memcpy ( V_146 -> V_153 , V_149 , V_83 ) ;
return 24 ;
} else {
* V_147 |= F_72 ( V_150 | V_154 ) ;
F_73 ( V_146 -> V_151 ) ;
memcpy ( V_146 -> V_152 , V_149 , V_83 ) ;
memcpy ( V_146 -> V_153 , V_148 , V_83 ) ;
memcpy ( V_146 -> V_155 , V_149 , V_83 ) ;
return 30 ;
}
}
unsigned int F_74 ( struct V_12 * V_13 ,
struct V_73 * V_156 ,
const char * V_157 , const char * V_158 )
{
if ( F_55 ( ! V_157 && V_158 ) )
return 0 ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
V_156 -> V_159 = V_13 -> V_3 . V_18 . V_94 . V_160 ;
F_75 ( F_76 ( V_13 -> V_3 . V_18 . V_161 ) , & V_156 -> V_75 ) ;
V_13 -> V_3 . V_18 . V_161 ++ ;
if ( V_157 && ! V_158 ) {
V_156 -> V_162 |= V_163 ;
memcpy ( V_156 -> V_164 , V_157 , V_83 ) ;
return 2 * V_83 ;
} else if ( V_157 && V_158 ) {
V_156 -> V_162 |= V_165 ;
memcpy ( V_156 -> V_164 , V_157 , V_83 ) ;
memcpy ( V_156 -> V_166 , V_158 , V_83 ) ;
return 3 * V_83 ;
}
return V_83 ;
}
static void F_77 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_51 ;
if ( V_17 -> V_94 . V_167 > 0 )
F_78 ( V_13 , V_17 -> V_94 . V_167 * V_168 ) ;
F_79 ( V_13 ) ;
V_51 = F_17 ( V_13 ) ;
F_25 ( V_13 , V_51 ) ;
F_80 ( & V_17 -> V_169 ,
F_81 ( V_78 +
V_170 ) ) ;
}
static void F_82 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_171 ;
F_83 ( V_13 ) ;
if ( V_17 -> V_94 . V_142 == V_172 )
V_171 = V_17 -> V_94 . V_173 ;
else
V_171 = V_17 -> V_94 . V_174 ;
F_80 ( & V_17 -> V_144 ,
F_81 ( F_84 ( V_171 ) ) ) ;
}
static int
F_85 ( struct V_16 * V_17 )
{
struct V_175 * V_176 ;
int V_177 , V_178 ;
struct V_84 * V_85 ;
struct V_1 * V_2 ;
struct V_111 * V_112 ;
struct V_179 * V_180 ;
enum V_118 V_119 ;
T_2 * V_86 ;
struct V_12 * V_13 ;
int V_181 = F_86 ( struct V_1 , V_3 . V_182 ) +
sizeof( V_2 -> V_3 . V_182 ) ;
V_13 = F_87 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_53 () ;
V_112 = F_54 ( V_13 -> V_41 . V_112 ) ;
V_119 = V_112 -> V_115 . V_44 -> V_119 ;
F_56 () ;
V_177 = V_181 +
2 +
2 + sizeof( struct V_183 ) +
2 + sizeof( struct V_184 ) +
2 + 8 +
2 + 3 ;
V_178 = 2 + ( V_185 - 8 ) +
2 + sizeof( struct V_130 ) +
2 + sizeof( struct V_134 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_89 ) +
2 + sizeof( T_3 ) +
2 + sizeof( struct V_138 ) +
2 + sizeof( struct V_140 ) +
V_17 -> V_109 ;
V_176 = F_88 ( sizeof( * V_176 ) + V_177 + V_178 , V_63 ) ;
V_85 = F_89 ( F_90 ( V_177 , V_178 ) ) ;
if ( ! V_176 || ! V_85 )
goto V_186;
V_176 -> V_187 = ( ( T_2 * ) V_176 ) + sizeof( * V_176 ) ;
V_2 = (struct V_1 * ) F_42 ( V_85 , V_181 ) ;
memset ( V_2 , 0 , V_181 ) ;
V_2 -> V_188 = F_72 ( V_189 |
V_190 ) ;
F_91 ( V_2 -> V_191 ) ;
memcpy ( V_2 -> V_72 , V_13 -> V_41 . V_192 , V_83 ) ;
memcpy ( V_2 -> V_193 , V_13 -> V_41 . V_192 , V_83 ) ;
F_92 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_182 . V_194 =
F_72 ( V_13 -> V_41 . V_42 . V_194 ) ;
V_2 -> V_3 . V_182 . V_195 |= F_72 (
V_13 -> V_3 . V_18 . V_196 ? V_197 : 0 ) ;
V_86 = F_42 ( V_85 , 2 ) ;
* V_86 ++ = V_198 ;
* V_86 ++ = 0x0 ;
F_53 () ;
V_180 = F_54 ( V_17 -> V_180 ) ;
if ( V_180 ) {
V_86 = F_42 ( V_85 , 13 ) ;
memset ( V_86 , 0 , 13 ) ;
* V_86 ++ = V_199 ;
* V_86 ++ = 3 ;
* V_86 ++ = 0x0 ;
* V_86 ++ = F_57 (
V_180 -> V_200 . V_43 . V_44 -> V_117 ) ;
V_176 -> V_201 = V_180 -> V_200 . V_202 ;
V_176 -> V_203 [ 0 ] = V_181 + 6 ;
* V_86 ++ = V_180 -> V_200 . V_202 ;
* V_86 ++ = V_204 ;
* V_86 ++ = 6 ;
if ( V_17 -> V_205 == V_206 ) {
* V_86 ++ = V_17 -> V_94 . V_160 ;
* V_86 |= V_207 ;
} else {
* V_86 ++ = V_17 -> V_208 ;
}
* V_86 ++ |= V_180 -> V_200 . V_209 ?
V_210 : 0x00 ;
F_47 ( V_211 , V_86 ) ;
V_86 += 2 ;
F_47 ( V_17 -> V_212 , V_86 ) ;
V_86 += 2 ;
}
F_56 () ;
if ( F_93 ( V_13 , V_85 , true , V_119 ) ||
F_52 ( V_13 , V_85 ) )
goto V_186;
V_176 -> V_177 = V_85 -> V_108 ;
memcpy ( V_176 -> V_187 , V_85 -> V_11 , V_176 -> V_177 ) ;
F_94 ( V_85 , 0 ) ;
V_176 -> V_213 = V_176 -> V_187 + V_176 -> V_177 ;
if ( F_95 ( V_13 , V_85 , true , V_119 ) ||
F_50 ( V_13 , V_85 ) ||
F_58 ( V_13 , V_85 ) ||
F_60 ( V_13 , V_85 ) ||
F_45 ( V_13 , V_85 ) ||
F_40 ( V_13 , V_85 ) ||
F_46 ( V_13 , V_85 ) ||
F_62 ( V_13 , V_85 ) ||
F_64 ( V_13 , V_85 ) ||
F_48 ( V_13 , V_85 ) )
goto V_186;
V_176 -> V_178 = V_85 -> V_108 ;
memcpy ( V_176 -> V_213 , V_85 -> V_11 , V_176 -> V_178 ) ;
V_176 -> V_214 = (struct V_89 * )
( V_176 -> V_213 + V_17 -> V_91 ) ;
F_96 ( V_85 ) ;
F_97 ( V_17 -> V_182 , V_176 ) ;
return 0 ;
V_186:
F_33 ( V_176 ) ;
F_96 ( V_85 ) ;
return - V_64 ;
}
static int
F_98 ( struct V_12 * V_13 )
{
struct V_175 * V_215 ;
int V_216 ;
V_215 = F_99 ( V_13 -> V_3 . V_18 . V_182 ,
F_100 ( & V_13 -> V_217 . V_218 ) ) ;
V_216 = F_85 ( & V_13 -> V_3 . V_18 ) ;
if ( V_216 )
return V_216 ;
if ( V_215 )
F_101 ( V_215 , V_219 ) ;
return 0 ;
}
void F_25 ( struct V_12 * V_13 ,
T_1 V_51 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_220 = V_51 ;
T_1 V_221 ;
if ( ! V_220 )
return;
F_102 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_7 ( V_221 , & V_17 -> V_222 ) ;
F_7 ( V_223 , & V_17 -> V_20 ) ;
F_8 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_103 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_51 = V_53 |
V_224 |
V_225 |
V_226 |
V_227 ;
V_15 -> V_228 ++ ;
F_104 ( & V_15 -> V_229 ) ;
F_105 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_230 = F_106 ( V_17 -> V_37 ) ;
V_17 -> V_99 = false ;
V_17 -> V_231 = 0 ;
F_7 ( V_19 , & V_17 -> V_20 ) ;
F_68 ( V_17 ) ;
F_8 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_135 =
V_17 -> V_94 . V_232 ;
V_13 -> V_41 . V_42 . V_233 = true ;
V_51 |= F_107 ( V_13 ) ;
if ( F_85 ( V_17 ) ) {
F_108 ( V_13 ) ;
return - V_64 ;
}
F_109 ( V_15 , V_13 ) ;
F_110 ( V_13 , V_51 ) ;
F_111 ( V_13 -> V_234 ) ;
return 0 ;
}
void F_108 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_175 * V_176 ;
F_112 ( V_13 -> V_234 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_233 = false ;
F_69 ( V_235 , & V_13 -> V_236 ) ;
F_110 ( V_13 , V_224 ) ;
V_176 = F_99 ( V_17 -> V_182 ,
F_100 ( & V_13 -> V_217 . V_218 ) ) ;
F_113 ( V_17 -> V_182 , NULL ) ;
F_101 ( V_176 , V_219 ) ;
F_114 ( V_13 ) ;
F_115 ( V_13 ) ;
V_15 -> V_237 -= F_116 ( & V_17 -> V_238 . V_239 ) ;
F_117 ( & V_17 -> V_238 . V_239 ) ;
F_22 ( & V_13 -> V_3 . V_18 . V_169 ) ;
F_22 ( & V_13 -> V_3 . V_18 . V_144 ) ;
F_22 ( & V_13 -> V_3 . V_18 . V_240 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_222 = 0 ;
V_15 -> V_228 -- ;
F_118 ( & V_15 -> V_229 ) ;
F_105 ( V_15 ) ;
}
static bool
F_119 ( struct V_12 * V_13 ,
struct V_23 * V_241 , bool V_182 )
{
struct V_242 V_243 ;
struct V_244 V_245 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
enum V_118 V_119 = F_11 ( V_13 ) ;
int V_246 ;
T_1 V_247 ;
F_120 ( V_13 ) ;
V_247 = V_248 ;
switch ( V_13 -> V_41 . V_42 . V_43 . V_126 ) {
case V_127 :
V_247 |= V_249 ;
case V_250 :
V_247 |= V_251 ;
break;
default:
break;
}
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
memset ( & V_245 , 0 , sizeof( V_245 ) ) ;
V_246 = F_121 ( V_13 , V_241 , V_119 ,
V_247 , V_13 -> V_41 . V_192 ,
& V_245 ) ;
if ( V_246 < 0 )
return false ;
if ( V_246 )
return false ;
V_243 . V_43 = V_245 . V_43 ;
V_243 . V_202 = V_245 . V_202 ;
if ( ! F_122 ( V_13 -> V_15 -> V_21 . V_122 , & V_243 . V_43 ,
V_252 ) ) {
F_123 ( V_13 ,
L_2 ,
V_13 -> V_41 . V_192 ,
V_243 . V_43 . V_44 -> V_117 ,
V_243 . V_43 . V_126 ,
V_243 . V_43 . V_253 ,
V_243 . V_43 . V_254 ) ;
return false ;
}
V_246 = F_124 ( V_13 -> V_15 -> V_21 . V_122 ,
& V_243 . V_43 ,
V_255 ) ;
if ( V_246 < 0 )
return false ;
if ( V_246 > 0 )
return false ;
V_243 . V_256 = V_246 ;
if ( F_125 ( & V_243 . V_43 ,
& V_13 -> V_41 . V_42 . V_43 ) ) {
F_126 ( V_13 ,
L_3 ) ;
return true ;
}
F_126 ( V_13 ,
L_4 ,
V_243 . V_43 . V_44 -> V_117 ) ;
V_243 . V_209 = V_245 . V_257 & V_210 ;
if ( V_182 ) {
V_17 -> V_208 = V_245 . V_159 - 1 ;
if ( V_17 -> V_212 >= V_245 . V_212 )
return false ;
V_17 -> V_212 = V_245 . V_212 ;
}
if ( V_17 -> V_208 >= V_17 -> V_94 . V_160 )
return false ;
V_17 -> V_205 = V_258 ;
if ( F_127 ( V_13 -> V_15 -> V_21 . V_122 , V_13 -> V_234 ,
& V_243 ) < 0 )
return false ;
return true ;
}
static void
F_128 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_108 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_84 * V_259 ;
struct V_175 * V_176 ;
struct V_1 * V_146 ;
struct V_23 V_241 ;
T_4 V_260 ;
T_2 * V_86 ;
V_86 = V_2 -> V_3 . V_261 . V_262 ;
V_260 = ( T_2 * ) V_86 - ( T_2 * ) V_2 ;
if ( V_260 > V_108 )
return;
F_129 ( V_86 , V_108 - V_260 , false , & V_241 ) ;
if ( ! V_241 . V_29 )
return;
if ( ( ! F_37 ( V_2 -> V_191 , V_13 -> V_41 . V_192 ) &&
! F_130 ( V_2 -> V_191 ) ) ||
V_241 . V_263 != 0 )
return;
if ( V_241 . V_28 != 0 &&
( V_241 . V_28 != V_17 -> V_28 ||
memcmp ( V_241 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_53 () ;
V_176 = F_54 ( V_17 -> V_182 ) ;
if ( ! V_176 )
goto V_264;
V_259 = F_89 ( V_15 -> V_265 +
V_176 -> V_177 + V_176 -> V_178 ) ;
if ( ! V_259 )
goto V_264;
F_131 ( V_259 , V_15 -> V_265 ) ;
memcpy ( F_42 ( V_259 , V_176 -> V_177 ) , V_176 -> V_187 , V_176 -> V_177 ) ;
memcpy ( F_42 ( V_259 , V_176 -> V_178 ) , V_176 -> V_213 , V_176 -> V_178 ) ;
V_146 = (struct V_1 * ) V_259 -> V_11 ;
V_146 -> V_188 = F_72 ( V_189 |
V_266 ) ;
memcpy ( V_146 -> V_191 , V_2 -> V_72 , V_83 ) ;
F_132 ( V_259 ) -> V_162 |= V_267 ;
F_133 ( V_13 , V_259 ) ;
V_264:
F_56 () ;
}
static void F_134 ( struct V_12 * V_13 ,
T_5 V_268 ,
struct V_1 * V_2 ,
T_4 V_108 ,
struct V_269 * V_270 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_241 ;
struct V_113 * V_132 ;
T_4 V_260 ;
int V_271 ;
enum V_118 V_119 = V_270 -> V_119 ;
if ( V_268 == V_266 &&
! F_37 ( V_2 -> V_191 , V_13 -> V_41 . V_192 ) )
return;
V_260 = ( T_2 * ) V_2 -> V_3 . V_272 . V_262 - ( T_2 * ) V_2 ;
if ( V_260 > V_108 )
return;
F_129 ( V_2 -> V_3 . V_272 . V_262 , V_108 - V_260 ,
false , & V_241 ) ;
if ( ( ! V_241 . V_29 || ! V_241 . V_31 ) ||
( V_241 . V_273 && V_13 -> V_3 . V_18 . V_196 == V_274 ) ||
( ! V_241 . V_273 && V_13 -> V_3 . V_18 . V_196 != V_274 ) )
return;
if ( V_241 . V_275 )
V_271 = F_135 ( V_241 . V_275 [ 0 ] , V_119 ) ;
else
V_271 = V_270 -> V_271 ;
V_132 = F_136 ( V_15 -> V_21 . V_122 , V_271 ) ;
if ( ! V_132 || V_132 -> V_162 & V_252 )
return;
if ( F_9 ( V_13 , & V_241 ) )
F_137 ( V_13 , V_2 -> V_72 , & V_241 ) ;
if ( V_17 -> V_230 )
V_17 -> V_230 -> V_276 ( V_13 ,
V_268 , V_2 , & V_241 , V_270 ) ;
if ( V_17 -> V_205 != V_206 &&
! V_13 -> V_41 . V_277 )
F_119 ( V_13 , & V_241 , true ) ;
}
int F_138 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_179 * V_278 ;
int V_216 = 0 ;
int V_51 = 0 ;
V_17 -> V_205 = V_279 ;
V_17 -> V_208 = 0 ;
V_278 = F_54 ( V_17 -> V_180 ) ;
F_113 ( V_17 -> V_180 , NULL ) ;
if ( V_278 )
F_101 ( V_278 , V_219 ) ;
V_216 = F_98 ( V_13 ) ;
if ( V_216 )
return - V_114 ;
V_51 |= V_53 ;
F_126 ( V_13 , L_5 ,
V_13 -> V_41 . V_42 . V_43 . V_44 -> V_117 ) ;
return V_51 ;
}
int F_139 ( struct V_12 * V_13 ,
struct V_242 * V_280 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_179 * V_278 ;
int V_216 = 0 ;
V_278 = F_27 ( sizeof( * V_278 ) ,
V_81 ) ;
if ( ! V_278 )
return - V_64 ;
memcpy ( & V_278 -> V_200 , V_280 ,
sizeof( struct V_242 ) ) ;
F_97 ( V_17 -> V_180 , V_278 ) ;
V_216 = F_98 ( V_13 ) ;
if ( V_216 ) {
V_278 = F_54 ( V_17 -> V_180 ) ;
F_113 ( V_17 -> V_180 , NULL ) ;
F_101 ( V_278 , V_219 ) ;
return V_216 ;
}
return V_53 ;
}
static int F_140 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_108 )
{
struct V_1 * V_281 ;
struct V_84 * V_85 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_2 * V_86 = V_2 -> V_3 . V_4 . V_3 . V_282 . V_262 ;
T_4 V_283 ;
V_85 = F_89 ( V_15 -> V_265 + V_108 ) ;
if ( ! V_85 )
return - V_64 ;
F_131 ( V_85 , V_15 -> V_265 ) ;
V_281 = (struct V_1 * ) F_42 ( V_85 , V_108 ) ;
V_283 = ( V_108 < 42 ) ? 7 : 10 ;
* ( V_86 + V_283 ) -= 1 ;
* ( V_86 + V_283 + 1 ) &= ~ V_207 ;
memcpy ( V_281 , V_2 , V_108 ) ;
F_91 ( V_281 -> V_191 ) ;
memcpy ( V_281 -> V_72 , V_13 -> V_41 . V_192 , V_83 ) ;
memcpy ( V_281 -> V_193 , V_13 -> V_41 . V_192 , V_83 ) ;
F_133 ( V_13 , V_85 ) ;
return 0 ;
}
static void F_141 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_108 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_241 ;
T_5 V_212 ;
bool V_284 = true ;
T_4 V_260 ;
T_2 * V_86 ;
if ( V_2 -> V_3 . V_4 . V_3 . V_285 . V_6 !=
V_286 )
return;
V_86 = V_2 -> V_3 . V_4 . V_3 . V_282 . V_262 ;
V_260 = F_86 ( struct V_1 ,
V_3 . V_4 . V_3 . V_282 . V_262 ) ;
F_129 ( V_86 , V_108 - V_260 , false , & V_241 ) ;
V_17 -> V_208 = V_241 . V_287 -> V_288 ;
if ( ! -- V_17 -> V_208 )
V_284 = false ;
V_212 = F_142 ( V_241 . V_287 -> V_289 ) ;
if ( V_17 -> V_212 >= V_212 )
return;
V_17 -> V_212 = V_212 ;
if ( ! V_13 -> V_41 . V_277 &&
! F_119 ( V_13 , & V_241 , false ) ) {
F_126 ( V_13 , L_6 ) ;
return;
}
if ( V_284 ) {
if ( F_140 ( V_13 , V_2 , V_108 ) < 0 )
F_126 ( V_13 , L_7 ) ;
}
}
static void F_143 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_108 ,
struct V_269 * V_270 )
{
switch ( V_2 -> V_3 . V_4 . V_290 ) {
case V_291 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_292 . V_6 ) {
case V_293 :
case V_294 :
case V_295 :
F_144 ( V_13 , V_2 , V_108 , V_270 ) ;
break;
}
break;
case V_296 :
if ( F_1 ( V_2 ) )
F_145 ( V_13 , V_2 , V_108 ) ;
break;
case V_297 :
F_141 ( V_13 , V_2 , V_108 ) ;
break;
}
}
void F_146 ( struct V_12 * V_13 ,
struct V_84 * V_85 )
{
struct V_269 * V_270 ;
struct V_1 * V_2 ;
T_5 V_268 ;
F_147 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_264;
V_270 = F_148 ( V_85 ) ;
V_2 = (struct V_1 * ) V_85 -> V_11 ;
V_268 = F_142 ( V_2 -> V_188 ) & V_298 ;
switch ( V_268 ) {
case V_266 :
case V_190 :
F_134 ( V_13 , V_268 , V_2 , V_85 -> V_108 ,
V_270 ) ;
break;
case V_299 :
F_128 ( V_13 , V_2 , V_85 -> V_108 ) ;
break;
case V_300 :
F_143 ( V_13 , V_2 , V_85 -> V_108 , V_270 ) ;
break;
}
V_264:
F_149 ( V_13 ) ;
}
static void F_150 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_221 , V_51 = 0 ;
F_102 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_69 ( V_221 , & V_17 -> V_222 ) ;
V_51 |= F_151 ( V_221 ) ;
}
if ( V_13 -> V_41 . V_42 . V_233 &&
( V_51 & ( V_53 |
V_225 |
V_226 |
V_227 ) ) )
if ( F_98 ( V_13 ) )
return;
F_110 ( V_13 , V_51 ) ;
}
void F_152 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_147 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_264;
if ( V_17 -> V_301 &&
F_36 ( V_78 ,
V_17 -> V_302 + F_153 ( V_17 -> V_94 . V_303 ) ) )
F_154 ( V_13 ) ;
if ( F_155 ( V_19 , & V_17 -> V_20 ) )
F_77 ( V_13 ) ;
if ( F_155 ( V_141 , & V_17 -> V_20 ) )
F_82 ( V_13 ) ;
if ( F_155 ( V_304 , & V_17 -> V_20 ) )
F_156 ( V_13 ) ;
if ( F_155 ( V_223 , & V_17 -> V_20 ) )
F_150 ( V_13 ) ;
V_264:
F_149 ( V_13 ) ;
}
void F_157 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_305 [ V_83 ] = {} ;
F_158 ( & V_17 -> V_169 ,
F_6 ,
( unsigned long ) V_13 ) ;
V_17 -> V_52 = true ;
F_159 ( & V_17 -> V_306 , 0 ) ;
F_26 ( V_13 ) ;
V_17 -> V_302 = V_78 ;
V_17 -> V_307 = V_78 ;
V_17 -> V_205 = V_279 ;
if ( ! V_8 )
F_2 () ;
F_160 ( V_13 ) ;
F_158 ( & V_17 -> V_240 ,
F_66 ,
( unsigned long ) V_13 ) ;
F_158 ( & V_17 -> V_144 ,
F_67 ,
( unsigned long ) V_13 ) ;
F_161 ( & V_17 -> V_308 . V_71 ) ;
F_162 ( & V_17 -> V_238 . V_239 ) ;
F_163 ( & V_17 -> V_309 ) ;
F_163 ( & V_17 -> V_310 ) ;
F_113 ( V_17 -> V_182 , NULL ) ;
V_13 -> V_41 . V_42 . V_193 = V_305 ;
}
void F_164 ( struct V_12 * V_13 )
{
F_29 ( V_13 ) ;
F_165 ( V_13 ) ;
}
