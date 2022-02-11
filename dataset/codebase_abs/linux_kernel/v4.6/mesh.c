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
F_14 ( & V_27 , V_13 -> V_41 . V_42 . V_43 . V_44 ,
V_45 ) ;
F_15 ( V_24 -> V_46 , & V_27 ) ;
F_16 ( V_24 -> V_47 , & V_27 ) ;
if ( ! F_17 ( & V_13 -> V_41 . V_42 . V_43 ,
& V_27 ) )
return false ;
return true ;
}
bool F_18 ( struct V_23 * V_24 )
{
return ( V_24 -> V_31 -> V_48 &
V_49 ) != 0 ;
}
T_1 F_19 ( struct V_12 * V_13 )
{
bool V_50 ;
T_1 V_51 = 0 ;
V_50 = F_20 ( V_13 ) ;
if ( V_50 != V_13 -> V_3 . V_18 . V_52 ) {
V_13 -> V_3 . V_18 . V_52 = V_50 ;
V_51 = V_53 ;
}
return V_51 ;
}
void F_21 ( struct V_54 * V_55 )
{
struct V_12 * V_13 = V_55 -> V_13 ;
T_1 V_51 ;
V_51 = F_19 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_56 ) {
V_51 |= F_22 ( V_55 ) ;
F_23 ( & V_55 -> V_18 -> V_57 ) ;
}
if ( V_51 )
F_24 ( V_13 , V_51 ) ;
}
int F_25 ( struct V_12 * V_13 )
{
int V_58 ;
V_13 -> V_3 . V_18 . V_59 = F_26 ( sizeof( struct V_60 ) , V_61 ) ;
if ( ! V_13 -> V_3 . V_18 . V_59 )
return - V_62 ;
V_13 -> V_3 . V_18 . V_59 -> V_63 = V_64 - 1 ;
for ( V_58 = 0 ; V_58 < V_64 ; V_58 ++ )
F_27 ( & V_13 -> V_3 . V_18 . V_59 -> V_65 [ V_58 ] ) ;
return 0 ;
}
void F_28 ( struct V_12 * V_13 )
{
struct V_60 * V_59 = V_13 -> V_3 . V_18 . V_59 ;
struct V_10 * V_66 , * V_67 ;
int V_58 ;
if ( ! V_13 -> V_3 . V_18 . V_59 )
return;
for ( V_58 = 0 ; V_58 < V_64 ; V_58 ++ ) {
F_29 (p, n, &rmc->bucket[i], list) {
F_30 ( & V_66 -> V_68 ) ;
F_31 ( V_9 , V_66 ) ;
}
}
F_32 ( V_59 ) ;
V_13 -> V_3 . V_18 . V_59 = NULL ;
}
int F_33 ( struct V_12 * V_13 ,
const T_2 * V_69 , struct V_70 * V_71 )
{
struct V_60 * V_59 = V_13 -> V_3 . V_18 . V_59 ;
T_1 V_72 = 0 ;
int V_73 = 0 ;
T_2 V_74 ;
struct V_10 * V_66 , * V_67 ;
memcpy ( & V_72 , & V_71 -> V_72 , sizeof( V_71 -> V_72 ) ) ;
V_74 = F_34 ( V_71 -> V_72 ) & V_59 -> V_63 ;
F_29 (p, n, &rmc->bucket[idx], list) {
++ V_73 ;
if ( F_35 ( V_75 , V_66 -> V_76 ) ||
V_73 == V_77 ) {
F_30 ( & V_66 -> V_68 ) ;
F_31 ( V_9 , V_66 ) ;
-- V_73 ;
} else if ( ( V_72 == V_66 -> V_72 ) && F_36 ( V_69 , V_66 -> V_69 ) )
return - 1 ;
}
V_66 = F_37 ( V_9 , V_78 ) ;
if ( ! V_66 )
return 0 ;
V_66 -> V_72 = V_72 ;
V_66 -> V_76 = V_75 + V_79 ;
memcpy ( V_66 -> V_69 , V_69 , V_80 ) ;
F_38 ( & V_66 -> V_68 , & V_59 -> V_65 [ V_74 ] ) ;
return 0 ;
}
int F_39 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_83 , V_84 ;
T_2 V_85 = sizeof( struct V_86 ) ;
if ( F_40 ( V_82 ) < 2 + V_85 )
return - V_62 ;
V_83 = F_41 ( V_82 , 2 + V_85 ) ;
* V_83 ++ = V_87 ;
* V_83 ++ = V_85 ;
V_17 -> V_88 = V_83 - V_82 -> V_11 ;
* V_83 ++ = V_17 -> V_30 ;
* V_83 ++ = V_17 -> V_33 ;
* V_83 ++ = V_17 -> V_35 ;
* V_83 ++ = V_17 -> V_37 ;
* V_83 ++ = V_17 -> V_39 ;
V_84 = F_42 ( & V_17 -> V_89 ) ;
V_84 = F_43 ( int , V_84 , V_90 ) ;
* V_83 ++ = V_84 << 1 ;
* V_83 = 0x00 ;
* V_83 |= V_17 -> V_91 . V_92 ?
V_93 : 0x00 ;
* V_83 |= V_17 -> V_52 ?
V_49 : 0x00 ;
* V_83 |= V_17 -> V_94 ?
V_95 : 0x00 ;
* V_83 ++ |= V_17 -> V_96 ?
V_97 : 0x00 ;
* V_83 ++ = 0x00 ;
return 0 ;
}
int F_44 ( struct V_12 * V_13 , struct V_81 * V_82 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_83 ;
if ( F_40 ( V_82 ) < 2 + V_17 -> V_28 )
return - V_62 ;
V_83 = F_41 ( V_82 , 2 + V_17 -> V_28 ) ;
* V_83 ++ = V_98 ;
* V_83 ++ = V_17 -> V_28 ;
if ( V_17 -> V_28 )
memcpy ( V_83 , V_17 -> V_29 , V_17 -> V_28 ) ;
return 0 ;
}
static int F_45 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_83 ;
if ( V_17 -> V_99 == 0 &&
V_17 -> V_94 == 0 &&
V_17 -> V_100 == V_101 )
return 0 ;
if ( F_40 ( V_82 ) < 4 )
return - V_62 ;
V_83 = F_41 ( V_82 , 2 + 2 ) ;
* V_83 ++ = V_102 ;
* V_83 ++ = 2 ;
F_46 ( V_17 -> V_91 . V_103 , V_83 ) ;
return 0 ;
}
int F_47 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_104 , V_105 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_106 )
return 0 ;
V_104 = F_48 ( V_17 -> V_24 , V_17 -> V_106 , 0 ) ;
if ( V_104 ) {
V_105 = V_17 -> V_106 - V_104 ;
V_11 = V_17 -> V_24 + V_104 ;
if ( F_40 ( V_82 ) < V_105 )
return - V_62 ;
memcpy ( F_41 ( V_82 , V_105 ) , V_11 , V_105 ) ;
}
return 0 ;
}
int F_49 ( struct V_12 * V_13 , struct V_81 * V_82 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_105 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_106 )
return 0 ;
V_11 = F_50 ( V_107 , V_17 -> V_24 , V_17 -> V_106 ) ;
if ( ! V_11 )
return 0 ;
V_105 = V_11 [ 1 ] + 2 ;
if ( F_40 ( V_82 ) < V_105 )
return - V_62 ;
memcpy ( F_41 ( V_82 , V_105 ) , V_11 , V_105 ) ;
return 0 ;
}
static int F_51 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_108 * V_109 ;
struct V_110 * V_44 ;
T_2 * V_83 ;
if ( F_40 ( V_82 ) < 3 )
return - V_62 ;
F_52 () ;
V_109 = F_53 ( V_13 -> V_41 . V_109 ) ;
if ( F_54 ( ! V_109 ) ) {
F_55 () ;
return - V_111 ;
}
V_44 = V_109 -> V_112 . V_44 ;
F_55 () ;
V_83 = F_41 ( V_82 , 2 + 1 ) ;
* V_83 ++ = V_113 ;
* V_83 ++ = 1 ;
* V_83 ++ = F_56 ( V_44 -> V_114 ) ;
return 0 ;
}
int F_57 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_115 V_116 = F_13 ( V_13 ) ;
struct V_117 * V_118 ;
T_2 * V_83 ;
V_118 = V_15 -> V_21 . V_119 -> V_120 [ V_116 ] ;
if ( ! V_118 -> V_121 . V_122 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_124 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_125 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_126 )
return 0 ;
if ( F_40 ( V_82 ) < 2 + sizeof( struct V_127 ) )
return - V_62 ;
V_83 = F_41 ( V_82 , 2 + sizeof( struct V_127 ) ) ;
F_58 ( V_83 , & V_118 -> V_121 , V_118 -> V_121 . V_128 ) ;
return 0 ;
}
int F_59 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_108 * V_109 ;
struct V_110 * V_129 ;
struct V_117 * V_118 ;
struct V_130 * V_121 ;
T_2 * V_83 ;
F_52 () ;
V_109 = F_53 ( V_13 -> V_41 . V_109 ) ;
if ( F_54 ( ! V_109 ) ) {
F_55 () ;
return - V_111 ;
}
V_129 = V_109 -> V_112 . V_44 ;
F_55 () ;
V_118 = V_15 -> V_21 . V_119 -> V_120 [ V_129 -> V_116 ] ;
V_121 = & V_118 -> V_121 ;
if ( ! V_121 -> V_122 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_124 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_125 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_126 )
return 0 ;
if ( F_40 ( V_82 ) < 2 + sizeof( struct V_131 ) )
return - V_62 ;
V_83 = F_41 ( V_82 , 2 + sizeof( struct V_131 ) ) ;
F_60 ( V_83 , V_121 , & V_13 -> V_41 . V_42 . V_43 ,
V_13 -> V_41 . V_42 . V_132 ,
false ) ;
return 0 ;
}
int F_61 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_115 V_116 = F_13 ( V_13 ) ;
struct V_117 * V_118 ;
T_2 * V_83 ;
V_118 = V_15 -> V_21 . V_119 -> V_120 [ V_116 ] ;
if ( ! V_118 -> V_133 . V_134 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_124 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_125 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_126 )
return 0 ;
if ( F_40 ( V_82 ) < 2 + sizeof( struct V_135 ) )
return - V_62 ;
V_83 = F_41 ( V_82 , 2 + sizeof( struct V_135 ) ) ;
F_62 ( V_83 , & V_118 -> V_133 , V_118 -> V_133 . V_128 ) ;
return 0 ;
}
int F_63 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_108 * V_109 ;
struct V_110 * V_129 ;
struct V_117 * V_118 ;
struct V_136 * V_133 ;
T_2 * V_83 ;
F_52 () ;
V_109 = F_53 ( V_13 -> V_41 . V_109 ) ;
if ( F_54 ( ! V_109 ) ) {
F_55 () ;
return - V_111 ;
}
V_129 = V_109 -> V_112 . V_44 ;
F_55 () ;
V_118 = V_15 -> V_21 . V_119 -> V_120 [ V_129 -> V_116 ] ;
V_133 = & V_118 -> V_133 ;
if ( ! V_133 -> V_134 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_124 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_125 ||
V_13 -> V_41 . V_42 . V_43 . V_123 == V_126 )
return 0 ;
if ( F_40 ( V_82 ) < 2 + sizeof( struct V_137 ) )
return - V_62 ;
V_83 = F_41 ( V_82 , 2 + sizeof( struct V_137 ) ) ;
F_64 ( V_83 , V_133 ,
& V_13 -> V_41 . V_42 . V_43 ) ;
return 0 ;
}
static void F_65 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
static void F_66 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_9 ( V_138 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_67 ( struct V_16 * V_17 )
{
if ( V_17 -> V_91 . V_139 > V_140 )
F_9 ( V_138 , & V_17 -> V_20 ) ;
else {
F_68 ( V_138 , & V_17 -> V_20 ) ;
F_23 ( & V_17 -> V_141 ) ;
}
}
int F_69 ( struct V_142 * V_143 , T_3 * V_144 ,
const T_2 * V_145 , const T_2 * V_146 )
{
if ( F_70 ( V_145 ) ) {
* V_144 |= F_71 ( V_147 ) ;
memcpy ( V_143 -> V_148 , V_145 , V_80 ) ;
memcpy ( V_143 -> V_149 , V_146 , V_80 ) ;
memcpy ( V_143 -> V_150 , V_146 , V_80 ) ;
return 24 ;
} else {
* V_144 |= F_71 ( V_147 | V_151 ) ;
F_72 ( V_143 -> V_148 ) ;
memcpy ( V_143 -> V_149 , V_146 , V_80 ) ;
memcpy ( V_143 -> V_150 , V_145 , V_80 ) ;
memcpy ( V_143 -> V_152 , V_146 , V_80 ) ;
return 30 ;
}
}
unsigned int F_73 ( struct V_12 * V_13 ,
struct V_70 * V_153 ,
const char * V_154 , const char * V_155 )
{
if ( F_54 ( ! V_154 && V_155 ) )
return 0 ;
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
V_153 -> V_156 = V_13 -> V_3 . V_18 . V_91 . V_157 ;
F_74 ( F_75 ( V_13 -> V_3 . V_18 . V_158 ) , & V_153 -> V_72 ) ;
V_13 -> V_3 . V_18 . V_158 ++ ;
if ( V_154 && ! V_155 ) {
V_153 -> V_159 |= V_160 ;
memcpy ( V_153 -> V_161 , V_154 , V_80 ) ;
return 2 * V_80 ;
} else if ( V_154 && V_155 ) {
V_153 -> V_159 |= V_162 ;
memcpy ( V_153 -> V_161 , V_154 , V_80 ) ;
memcpy ( V_153 -> V_163 , V_155 , V_80 ) ;
return 3 * V_80 ;
}
return V_80 ;
}
static void F_76 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_51 ;
if ( V_17 -> V_91 . V_164 > 0 )
F_77 ( V_13 , V_17 -> V_91 . V_164 * V_165 ) ;
F_78 ( V_13 ) ;
V_51 = F_19 ( V_13 ) ;
F_24 ( V_13 , V_51 ) ;
F_79 ( & V_17 -> V_166 ,
F_80 ( V_75 +
V_167 ) ) ;
}
static void F_81 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_168 ;
F_82 ( V_13 ) ;
if ( V_17 -> V_91 . V_139 == V_169 )
V_168 = V_17 -> V_91 . V_170 ;
else
V_168 = V_17 -> V_91 . V_171 ;
F_79 ( & V_17 -> V_141 ,
F_80 ( F_83 ( V_168 ) ) ) ;
}
static int
F_84 ( struct V_16 * V_17 )
{
struct V_172 * V_173 ;
int V_174 , V_175 ;
struct V_81 * V_82 ;
struct V_1 * V_2 ;
struct V_108 * V_109 ;
struct V_176 * V_177 ;
enum V_115 V_116 ;
T_2 * V_83 ;
struct V_12 * V_13 ;
int V_178 = F_85 ( struct V_1 , V_3 . V_179 ) +
sizeof( V_2 -> V_3 . V_179 ) ;
V_13 = F_86 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_52 () ;
V_109 = F_53 ( V_13 -> V_41 . V_109 ) ;
V_116 = V_109 -> V_112 . V_44 -> V_116 ;
F_55 () ;
V_174 = V_178 +
2 +
2 + sizeof( struct V_180 ) +
2 + sizeof( struct V_181 ) +
2 + 8 +
2 + 3 ;
V_175 = 2 + ( V_182 - 8 ) +
2 + sizeof( struct V_127 ) +
2 + sizeof( struct V_131 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_86 ) +
2 + sizeof( T_3 ) +
2 + sizeof( struct V_135 ) +
2 + sizeof( struct V_137 ) +
V_17 -> V_106 ;
V_173 = F_87 ( sizeof( * V_173 ) + V_174 + V_175 , V_61 ) ;
V_82 = F_88 ( F_89 ( V_174 , V_175 ) ) ;
if ( ! V_173 || ! V_82 )
goto V_183;
V_173 -> V_184 = ( ( T_2 * ) V_173 ) + sizeof( * V_173 ) ;
V_2 = (struct V_1 * ) F_41 ( V_82 , V_178 ) ;
memset ( V_2 , 0 , V_178 ) ;
V_2 -> V_185 = F_71 ( V_186 |
V_187 ) ;
F_90 ( V_2 -> V_188 ) ;
memcpy ( V_2 -> V_69 , V_13 -> V_41 . V_189 , V_80 ) ;
memcpy ( V_2 -> V_190 , V_13 -> V_41 . V_189 , V_80 ) ;
F_91 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_179 . V_191 =
F_71 ( V_13 -> V_41 . V_42 . V_191 ) ;
V_2 -> V_3 . V_179 . V_192 |= F_71 (
V_13 -> V_3 . V_18 . V_193 ? V_194 : 0 ) ;
V_83 = F_41 ( V_82 , 2 ) ;
* V_83 ++ = V_195 ;
* V_83 ++ = 0x0 ;
F_52 () ;
V_177 = F_53 ( V_17 -> V_177 ) ;
if ( V_177 ) {
V_83 = F_41 ( V_82 , 13 ) ;
memset ( V_83 , 0 , 13 ) ;
* V_83 ++ = V_196 ;
* V_83 ++ = 3 ;
* V_83 ++ = 0x0 ;
* V_83 ++ = F_56 (
V_177 -> V_197 . V_43 . V_44 -> V_114 ) ;
V_173 -> V_198 = V_177 -> V_197 . V_199 ;
V_173 -> V_200 [ 0 ] = V_178 + 6 ;
* V_83 ++ = V_177 -> V_197 . V_199 ;
* V_83 ++ = V_201 ;
* V_83 ++ = 6 ;
if ( V_17 -> V_202 == V_203 ) {
* V_83 ++ = V_17 -> V_91 . V_157 ;
* V_83 |= V_204 ;
} else {
* V_83 ++ = V_17 -> V_205 ;
}
* V_83 ++ |= V_177 -> V_197 . V_206 ?
V_207 : 0x00 ;
F_46 ( V_208 , V_83 ) ;
V_83 += 2 ;
F_46 ( V_17 -> V_209 , V_83 ) ;
V_83 += 2 ;
}
F_55 () ;
if ( F_92 ( V_13 , V_82 , true , V_116 ) ||
F_51 ( V_13 , V_82 ) )
goto V_183;
V_173 -> V_174 = V_82 -> V_105 ;
memcpy ( V_173 -> V_184 , V_82 -> V_11 , V_173 -> V_174 ) ;
F_93 ( V_82 , 0 ) ;
V_173 -> V_210 = V_173 -> V_184 + V_173 -> V_174 ;
if ( F_94 ( V_13 , V_82 , true , V_116 ) ||
F_49 ( V_13 , V_82 ) ||
F_57 ( V_13 , V_82 ) ||
F_59 ( V_13 , V_82 ) ||
F_44 ( V_13 , V_82 ) ||
F_39 ( V_13 , V_82 ) ||
F_45 ( V_13 , V_82 ) ||
F_61 ( V_13 , V_82 ) ||
F_63 ( V_13 , V_82 ) ||
F_47 ( V_13 , V_82 ) )
goto V_183;
V_173 -> V_175 = V_82 -> V_105 ;
memcpy ( V_173 -> V_210 , V_82 -> V_11 , V_173 -> V_175 ) ;
V_173 -> V_211 = (struct V_86 * )
( V_173 -> V_210 + V_17 -> V_88 ) ;
F_95 ( V_82 ) ;
F_96 ( V_17 -> V_179 , V_173 ) ;
return 0 ;
V_183:
F_32 ( V_173 ) ;
F_95 ( V_82 ) ;
return - V_62 ;
}
static int
F_97 ( struct V_12 * V_13 )
{
struct V_172 * V_212 ;
int V_213 ;
V_212 = F_98 ( V_13 -> V_3 . V_18 . V_179 ,
F_99 ( & V_13 -> V_214 . V_215 ) ) ;
V_213 = F_84 ( & V_13 -> V_3 . V_18 ) ;
if ( V_213 )
return V_213 ;
if ( V_212 )
F_100 ( V_212 , V_216 ) ;
return 0 ;
}
void F_24 ( struct V_12 * V_13 ,
T_1 V_51 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_217 = V_51 ;
T_1 V_218 ;
if ( ! V_217 )
return;
F_101 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_9 ( V_218 , & V_17 -> V_219 ) ;
F_9 ( V_220 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_102 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_51 = V_53 |
V_221 |
V_222 |
V_223 |
V_224 ;
V_15 -> V_225 ++ ;
F_103 ( & V_15 -> V_226 ) ;
F_104 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_227 = F_105 ( V_17 -> V_37 ) ;
V_17 -> V_96 = false ;
V_17 -> V_228 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_67 ( V_17 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_132 =
V_17 -> V_91 . V_229 ;
V_13 -> V_41 . V_42 . V_230 = true ;
V_51 |= F_106 ( V_13 ) ;
if ( F_84 ( V_17 ) ) {
F_107 ( V_13 ) ;
return - V_62 ;
}
F_108 ( V_15 , V_13 ) ;
F_109 ( V_13 , V_51 ) ;
F_110 ( V_13 -> V_231 ) ;
return 0 ;
}
void F_107 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_172 * V_173 ;
F_111 ( V_13 -> V_231 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_230 = false ;
F_68 ( V_232 , & V_13 -> V_233 ) ;
F_109 ( V_13 , V_221 ) ;
V_173 = F_98 ( V_17 -> V_179 ,
F_99 ( & V_13 -> V_214 . V_215 ) ) ;
F_112 ( V_17 -> V_179 , NULL ) ;
F_100 ( V_173 , V_216 ) ;
F_113 ( V_13 ) ;
F_114 ( V_13 ) ;
V_15 -> V_234 -= F_115 ( & V_17 -> V_235 . V_236 ) ;
F_116 ( & V_17 -> V_235 . V_236 ) ;
F_23 ( & V_13 -> V_3 . V_18 . V_166 ) ;
F_23 ( & V_13 -> V_3 . V_18 . V_141 ) ;
F_23 ( & V_13 -> V_3 . V_18 . V_237 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_219 = 0 ;
V_15 -> V_225 -- ;
F_117 ( & V_15 -> V_226 ) ;
F_104 ( V_15 ) ;
}
static bool
F_118 ( struct V_12 * V_13 ,
struct V_23 * V_238 , bool V_179 )
{
struct V_239 V_240 ;
struct V_241 V_242 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
enum V_115 V_116 = F_13 ( V_13 ) ;
int V_243 ;
T_1 V_244 ;
F_119 ( V_13 ) ;
V_244 = V_245 ;
switch ( V_13 -> V_41 . V_42 . V_43 . V_123 ) {
case V_124 :
V_244 |= V_246 ;
case V_247 :
V_244 |= V_248 ;
break;
default:
break;
}
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
V_243 = F_120 ( V_13 , V_238 , V_116 ,
V_244 , V_13 -> V_41 . V_189 ,
& V_242 ) ;
if ( V_243 < 0 )
return false ;
if ( V_243 )
return false ;
V_240 . V_43 = V_242 . V_43 ;
V_240 . V_199 = V_242 . V_199 ;
if ( ! F_121 ( V_13 -> V_15 -> V_21 . V_119 , & V_240 . V_43 ,
V_249 ) ) {
F_122 ( V_13 ,
L_2 ,
V_13 -> V_41 . V_189 ,
V_240 . V_43 . V_44 -> V_114 ,
V_240 . V_43 . V_123 ,
V_240 . V_43 . V_250 ,
V_240 . V_43 . V_251 ) ;
return false ;
}
V_243 = F_123 ( V_13 -> V_15 -> V_21 . V_119 ,
& V_240 . V_43 ,
V_252 ) ;
if ( V_243 < 0 )
return false ;
if ( V_243 > 0 )
return false ;
V_240 . V_253 = V_243 ;
if ( F_124 ( & V_240 . V_43 ,
& V_13 -> V_41 . V_42 . V_43 ) ) {
F_125 ( V_13 ,
L_3 ) ;
return true ;
}
F_125 ( V_13 ,
L_4 ,
V_240 . V_43 . V_44 -> V_114 ) ;
V_240 . V_206 = V_242 . V_254 & V_207 ;
if ( V_179 ) {
V_17 -> V_205 = V_242 . V_156 - 1 ;
if ( V_17 -> V_209 >= V_242 . V_209 )
return false ;
V_17 -> V_209 = V_242 . V_209 ;
}
if ( V_17 -> V_205 >= V_17 -> V_91 . V_157 )
return false ;
V_17 -> V_202 = V_255 ;
if ( F_126 ( V_13 -> V_15 -> V_21 . V_119 , V_13 -> V_231 ,
& V_240 ) < 0 )
return false ;
return true ;
}
static void
F_127 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_105 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_81 * V_256 ;
struct V_172 * V_173 ;
struct V_1 * V_143 ;
struct V_23 V_238 ;
T_4 V_257 ;
T_2 * V_83 ;
V_83 = V_2 -> V_3 . V_258 . V_259 ;
V_257 = ( T_2 * ) V_83 - ( T_2 * ) V_2 ;
if ( V_257 > V_105 )
return;
F_128 ( V_83 , V_105 - V_257 , false , & V_238 ) ;
if ( ! V_238 . V_29 )
return;
if ( ( ! F_36 ( V_2 -> V_188 , V_13 -> V_41 . V_189 ) &&
! F_129 ( V_2 -> V_188 ) ) ||
V_238 . V_260 != 0 )
return;
if ( V_238 . V_28 != 0 &&
( V_238 . V_28 != V_17 -> V_28 ||
memcmp ( V_238 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_52 () ;
V_173 = F_53 ( V_17 -> V_179 ) ;
if ( ! V_173 )
goto V_261;
V_256 = F_88 ( V_15 -> V_262 +
V_173 -> V_174 + V_173 -> V_175 ) ;
if ( ! V_256 )
goto V_261;
F_130 ( V_256 , V_15 -> V_262 ) ;
memcpy ( F_41 ( V_256 , V_173 -> V_174 ) , V_173 -> V_184 , V_173 -> V_174 ) ;
memcpy ( F_41 ( V_256 , V_173 -> V_175 ) , V_173 -> V_210 , V_173 -> V_175 ) ;
V_143 = (struct V_1 * ) V_256 -> V_11 ;
V_143 -> V_185 = F_71 ( V_186 |
V_263 ) ;
memcpy ( V_143 -> V_188 , V_2 -> V_69 , V_80 ) ;
F_131 ( V_256 ) -> V_159 |= V_264 ;
F_132 ( V_13 , V_256 ) ;
V_261:
F_55 () ;
}
static void F_133 ( struct V_12 * V_13 ,
T_5 V_265 ,
struct V_1 * V_2 ,
T_4 V_105 ,
struct V_266 * V_267 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_238 ;
struct V_110 * V_129 ;
T_4 V_257 ;
int V_268 ;
enum V_115 V_116 = V_267 -> V_116 ;
if ( V_265 == V_263 &&
! F_36 ( V_2 -> V_188 , V_13 -> V_41 . V_189 ) )
return;
V_257 = ( T_2 * ) V_2 -> V_3 . V_269 . V_259 - ( T_2 * ) V_2 ;
if ( V_257 > V_105 )
return;
F_128 ( V_2 -> V_3 . V_269 . V_259 , V_105 - V_257 ,
false , & V_238 ) ;
if ( ( ! V_238 . V_29 || ! V_238 . V_31 ) ||
( V_238 . V_270 && V_13 -> V_3 . V_18 . V_193 == V_271 ) ||
( ! V_238 . V_270 && V_13 -> V_3 . V_18 . V_193 != V_271 ) )
return;
if ( V_238 . V_272 )
V_268 = F_134 ( V_238 . V_272 [ 0 ] , V_116 ) ;
else
V_268 = V_267 -> V_268 ;
V_129 = F_135 ( V_15 -> V_21 . V_119 , V_268 ) ;
if ( ! V_129 || V_129 -> V_159 & V_249 )
return;
if ( F_11 ( V_13 , & V_238 ) )
F_136 ( V_13 , V_2 -> V_69 , & V_238 ) ;
if ( V_17 -> V_227 )
V_17 -> V_227 -> V_273 ( V_13 ,
V_265 , V_2 , & V_238 , V_267 ) ;
if ( V_17 -> V_202 != V_203 &&
! V_13 -> V_41 . V_274 )
F_118 ( V_13 , & V_238 , true ) ;
}
int F_137 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_176 * V_275 ;
int V_213 = 0 ;
int V_51 = 0 ;
V_17 -> V_202 = V_276 ;
V_17 -> V_205 = 0 ;
V_275 = F_53 ( V_17 -> V_177 ) ;
F_112 ( V_17 -> V_177 , NULL ) ;
if ( V_275 )
F_100 ( V_275 , V_216 ) ;
V_213 = F_97 ( V_13 ) ;
if ( V_213 )
return - V_111 ;
V_51 |= V_53 ;
F_125 ( V_13 , L_5 ,
V_13 -> V_41 . V_42 . V_43 . V_44 -> V_114 ) ;
return V_51 ;
}
int F_138 ( struct V_12 * V_13 ,
struct V_239 * V_277 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_176 * V_275 ;
int V_213 = 0 ;
V_275 = F_26 ( sizeof( * V_275 ) ,
V_78 ) ;
if ( ! V_275 )
return - V_62 ;
memcpy ( & V_275 -> V_197 , V_277 ,
sizeof( struct V_239 ) ) ;
F_96 ( V_17 -> V_177 , V_275 ) ;
V_213 = F_97 ( V_13 ) ;
if ( V_213 ) {
V_275 = F_53 ( V_17 -> V_177 ) ;
F_112 ( V_17 -> V_177 , NULL ) ;
F_100 ( V_275 , V_216 ) ;
return V_213 ;
}
return V_53 ;
}
static int F_139 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_105 )
{
struct V_1 * V_278 ;
struct V_81 * V_82 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_2 * V_83 = V_2 -> V_3 . V_4 . V_3 . V_279 . V_259 ;
T_4 V_280 ;
V_82 = F_88 ( V_15 -> V_262 + V_105 ) ;
if ( ! V_82 )
return - V_62 ;
F_130 ( V_82 , V_15 -> V_262 ) ;
V_278 = (struct V_1 * ) F_41 ( V_82 , V_105 ) ;
V_280 = ( V_105 < 42 ) ? 7 : 10 ;
* ( V_83 + V_280 ) -= 1 ;
* ( V_83 + V_280 + 1 ) &= ~ V_204 ;
memcpy ( V_278 , V_2 , V_105 ) ;
F_90 ( V_278 -> V_188 ) ;
memcpy ( V_278 -> V_69 , V_13 -> V_41 . V_189 , V_80 ) ;
memcpy ( V_278 -> V_190 , V_13 -> V_41 . V_189 , V_80 ) ;
F_132 ( V_13 , V_82 ) ;
return 0 ;
}
static void F_140 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_105 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_238 ;
T_5 V_209 ;
bool V_281 = true ;
T_4 V_257 ;
T_2 * V_83 ;
if ( V_2 -> V_3 . V_4 . V_3 . V_282 . V_6 !=
V_283 )
return;
V_83 = V_2 -> V_3 . V_4 . V_3 . V_279 . V_259 ;
V_257 = F_85 ( struct V_1 ,
V_3 . V_4 . V_3 . V_279 . V_259 ) ;
F_128 ( V_83 , V_105 - V_257 , false , & V_238 ) ;
V_17 -> V_205 = V_238 . V_284 -> V_285 ;
if ( ! -- V_17 -> V_205 )
V_281 = false ;
V_209 = F_141 ( V_238 . V_284 -> V_286 ) ;
if ( V_17 -> V_209 >= V_209 )
return;
V_17 -> V_209 = V_209 ;
if ( ! V_13 -> V_41 . V_274 &&
! F_118 ( V_13 , & V_238 , false ) ) {
F_125 ( V_13 , L_6 ) ;
return;
}
if ( V_281 ) {
if ( F_139 ( V_13 , V_2 , V_105 ) < 0 )
F_125 ( V_13 , L_7 ) ;
}
}
static void F_142 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_105 ,
struct V_266 * V_267 )
{
switch ( V_2 -> V_3 . V_4 . V_287 ) {
case V_288 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_289 . V_6 ) {
case V_290 :
case V_291 :
case V_292 :
F_143 ( V_13 , V_2 , V_105 , V_267 ) ;
break;
}
break;
case V_293 :
if ( F_1 ( V_2 ) )
F_144 ( V_13 , V_2 , V_105 ) ;
break;
case V_294 :
F_140 ( V_13 , V_2 , V_105 ) ;
break;
}
}
void F_145 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_266 * V_267 ;
struct V_1 * V_2 ;
T_5 V_265 ;
F_146 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_261;
V_267 = F_147 ( V_82 ) ;
V_2 = (struct V_1 * ) V_82 -> V_11 ;
V_265 = F_141 ( V_2 -> V_185 ) & V_295 ;
switch ( V_265 ) {
case V_263 :
case V_187 :
F_133 ( V_13 , V_265 , V_2 , V_82 -> V_105 ,
V_267 ) ;
break;
case V_296 :
F_127 ( V_13 , V_2 , V_82 -> V_105 ) ;
break;
case V_297 :
F_142 ( V_13 , V_2 , V_82 -> V_105 , V_267 ) ;
break;
}
V_261:
F_148 ( V_13 ) ;
}
static void F_149 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_218 , V_51 = 0 ;
F_101 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_68 ( V_218 , & V_17 -> V_219 ) ;
V_51 |= F_150 ( V_218 ) ;
}
if ( V_13 -> V_41 . V_42 . V_230 &&
( V_51 & ( V_53 |
V_222 |
V_223 |
V_224 ) ) )
if ( F_97 ( V_13 ) )
return;
F_109 ( V_13 , V_51 ) ;
}
void F_151 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_146 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_261;
if ( V_17 -> V_298 &&
F_35 ( V_75 ,
V_17 -> V_299 + F_152 ( V_17 -> V_91 . V_300 ) ) )
F_153 ( V_13 ) ;
if ( F_154 ( V_301 , & V_17 -> V_20 ) )
F_155 () ;
if ( F_154 ( V_302 , & V_17 -> V_20 ) )
F_156 () ;
if ( F_154 ( V_19 , & V_17 -> V_20 ) )
F_76 ( V_13 ) ;
if ( F_154 ( V_138 , & V_17 -> V_20 ) )
F_81 ( V_13 ) ;
if ( F_154 ( V_303 , & V_17 -> V_20 ) )
F_157 ( V_13 ) ;
if ( F_154 ( V_220 , & V_17 -> V_20 ) )
F_149 ( V_13 ) ;
V_261:
F_148 ( V_13 ) ;
}
void F_158 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_304 [ V_80 ] = {} ;
F_159 ( & V_17 -> V_166 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_52 = true ;
F_160 ( & V_17 -> V_305 , 0 ) ;
F_25 ( V_13 ) ;
V_17 -> V_299 = V_75 ;
V_17 -> V_306 = V_75 ;
V_17 -> V_202 = V_276 ;
if ( ! V_8 )
F_2 () ;
F_159 ( & V_17 -> V_237 ,
F_65 ,
( unsigned long ) V_13 ) ;
F_159 ( & V_17 -> V_141 ,
F_66 ,
( unsigned long ) V_13 ) ;
F_27 ( & V_17 -> V_307 . V_68 ) ;
F_161 ( & V_17 -> V_235 . V_236 ) ;
F_162 ( & V_17 -> V_308 ) ;
F_162 ( & V_17 -> V_309 ) ;
F_112 ( V_17 -> V_179 , NULL ) ;
V_13 -> V_41 . V_42 . V_190 = V_304 ;
}
