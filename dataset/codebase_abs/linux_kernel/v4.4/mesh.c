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
F_15 ( V_13 -> V_41 . V_42 . V_43 . V_44 ,
V_24 -> V_46 , & V_27 ) ;
if ( ! F_16 ( & V_13 -> V_41 . V_42 . V_43 ,
& V_27 ) )
return false ;
return true ;
}
bool F_17 ( struct V_23 * V_24 )
{
return ( V_24 -> V_31 -> V_47 &
V_48 ) != 0 ;
}
T_1 F_18 ( struct V_12 * V_13 )
{
bool V_49 ;
T_1 V_50 = 0 ;
V_49 = F_19 ( V_13 ) ;
if ( V_49 != V_13 -> V_3 . V_18 . V_51 ) {
V_13 -> V_3 . V_18 . V_51 = V_49 ;
V_50 = V_52 ;
}
return V_50 ;
}
void F_20 ( struct V_53 * V_54 )
{
struct V_12 * V_13 = V_54 -> V_13 ;
T_1 V_50 ;
V_50 = F_18 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_55 ) {
V_50 |= F_21 ( V_54 ) ;
F_22 ( & V_54 -> V_18 -> V_56 ) ;
}
if ( V_50 )
F_23 ( V_13 , V_50 ) ;
}
int F_24 ( struct V_12 * V_13 )
{
int V_57 ;
V_13 -> V_3 . V_18 . V_58 = F_25 ( sizeof( struct V_59 ) , V_60 ) ;
if ( ! V_13 -> V_3 . V_18 . V_58 )
return - V_61 ;
V_13 -> V_3 . V_18 . V_58 -> V_62 = V_63 - 1 ;
for ( V_57 = 0 ; V_57 < V_63 ; V_57 ++ )
F_26 ( & V_13 -> V_3 . V_18 . V_58 -> V_64 [ V_57 ] ) ;
return 0 ;
}
void F_27 ( struct V_12 * V_13 )
{
struct V_59 * V_58 = V_13 -> V_3 . V_18 . V_58 ;
struct V_10 * V_65 , * V_66 ;
int V_57 ;
if ( ! V_13 -> V_3 . V_18 . V_58 )
return;
for ( V_57 = 0 ; V_57 < V_63 ; V_57 ++ ) {
F_28 (p, n, &rmc->bucket[i], list) {
F_29 ( & V_65 -> V_67 ) ;
F_30 ( V_9 , V_65 ) ;
}
}
F_31 ( V_58 ) ;
V_13 -> V_3 . V_18 . V_58 = NULL ;
}
int F_32 ( struct V_12 * V_13 ,
const T_2 * V_68 , struct V_69 * V_70 )
{
struct V_59 * V_58 = V_13 -> V_3 . V_18 . V_58 ;
T_1 V_71 = 0 ;
int V_72 = 0 ;
T_2 V_73 ;
struct V_10 * V_65 , * V_66 ;
memcpy ( & V_71 , & V_70 -> V_71 , sizeof( V_70 -> V_71 ) ) ;
V_73 = F_33 ( V_70 -> V_71 ) & V_58 -> V_62 ;
F_28 (p, n, &rmc->bucket[idx], list) {
++ V_72 ;
if ( F_34 ( V_74 , V_65 -> V_75 ) ||
V_72 == V_76 ) {
F_29 ( & V_65 -> V_67 ) ;
F_30 ( V_9 , V_65 ) ;
-- V_72 ;
} else if ( ( V_71 == V_65 -> V_71 ) && F_35 ( V_68 , V_65 -> V_68 ) )
return - 1 ;
}
V_65 = F_36 ( V_9 , V_77 ) ;
if ( ! V_65 )
return 0 ;
V_65 -> V_71 = V_71 ;
V_65 -> V_75 = V_74 + V_78 ;
memcpy ( V_65 -> V_68 , V_68 , V_79 ) ;
F_37 ( & V_65 -> V_67 , & V_58 -> V_64 [ V_73 ] ) ;
return 0 ;
}
int F_38 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_82 , V_83 ;
T_2 V_84 = sizeof( struct V_85 ) ;
if ( F_39 ( V_81 ) < 2 + V_84 )
return - V_61 ;
V_82 = F_40 ( V_81 , 2 + V_84 ) ;
* V_82 ++ = V_86 ;
* V_82 ++ = V_84 ;
V_17 -> V_87 = V_82 - V_81 -> V_11 ;
* V_82 ++ = V_17 -> V_30 ;
* V_82 ++ = V_17 -> V_33 ;
* V_82 ++ = V_17 -> V_35 ;
* V_82 ++ = V_17 -> V_37 ;
* V_82 ++ = V_17 -> V_39 ;
V_83 = F_41 ( & V_17 -> V_88 ) ;
V_83 = F_42 ( int , V_83 , V_89 ) ;
* V_82 ++ = V_83 << 1 ;
* V_82 = 0x00 ;
* V_82 |= V_17 -> V_90 . V_91 ?
V_92 : 0x00 ;
* V_82 |= V_17 -> V_51 ?
V_48 : 0x00 ;
* V_82 |= V_17 -> V_93 ?
V_94 : 0x00 ;
* V_82 ++ |= V_17 -> V_95 ?
V_96 : 0x00 ;
* V_82 ++ = 0x00 ;
return 0 ;
}
int F_43 ( struct V_12 * V_13 , struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_82 ;
if ( F_39 ( V_81 ) < 2 + V_17 -> V_28 )
return - V_61 ;
V_82 = F_40 ( V_81 , 2 + V_17 -> V_28 ) ;
* V_82 ++ = V_97 ;
* V_82 ++ = V_17 -> V_28 ;
if ( V_17 -> V_28 )
memcpy ( V_82 , V_17 -> V_29 , V_17 -> V_28 ) ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_82 ;
if ( V_17 -> V_98 == 0 &&
V_17 -> V_93 == 0 &&
V_17 -> V_99 == V_100 )
return 0 ;
if ( F_39 ( V_81 ) < 4 )
return - V_61 ;
V_82 = F_40 ( V_81 , 2 + 2 ) ;
* V_82 ++ = V_101 ;
* V_82 ++ = 2 ;
F_45 ( V_17 -> V_90 . V_102 , V_82 ) ;
return 0 ;
}
int F_46 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_103 , V_104 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_105 )
return 0 ;
V_103 = F_47 ( V_17 -> V_24 , V_17 -> V_105 , 0 ) ;
if ( V_103 ) {
V_104 = V_17 -> V_105 - V_103 ;
V_11 = V_17 -> V_24 + V_103 ;
if ( F_39 ( V_81 ) < V_104 )
return - V_61 ;
memcpy ( F_40 ( V_81 , V_104 ) , V_11 , V_104 ) ;
}
return 0 ;
}
int F_48 ( struct V_12 * V_13 , struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_104 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_105 )
return 0 ;
V_11 = F_49 ( V_106 , V_17 -> V_24 , V_17 -> V_105 ) ;
if ( ! V_11 )
return 0 ;
V_104 = V_11 [ 1 ] + 2 ;
if ( F_39 ( V_81 ) < V_104 )
return - V_61 ;
memcpy ( F_40 ( V_81 , V_104 ) , V_11 , V_104 ) ;
return 0 ;
}
static int F_50 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_107 * V_108 ;
struct V_109 * V_44 ;
T_2 * V_82 ;
if ( F_39 ( V_81 ) < 3 )
return - V_61 ;
F_51 () ;
V_108 = F_52 ( V_13 -> V_41 . V_108 ) ;
if ( F_53 ( ! V_108 ) ) {
F_54 () ;
return - V_110 ;
}
V_44 = V_108 -> V_111 . V_44 ;
F_54 () ;
V_82 = F_40 ( V_81 , 2 + 1 ) ;
* V_82 ++ = V_112 ;
* V_82 ++ = 1 ;
* V_82 ++ = F_55 ( V_44 -> V_113 ) ;
return 0 ;
}
int F_56 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_114 V_115 = F_13 ( V_13 ) ;
struct V_116 * V_117 ;
T_2 * V_82 ;
V_117 = V_15 -> V_21 . V_118 -> V_119 [ V_115 ] ;
if ( ! V_117 -> V_120 . V_121 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_123 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_124 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_125 )
return 0 ;
if ( F_39 ( V_81 ) < 2 + sizeof( struct V_126 ) )
return - V_61 ;
V_82 = F_40 ( V_81 , 2 + sizeof( struct V_126 ) ) ;
F_57 ( V_82 , & V_117 -> V_120 , V_117 -> V_120 . V_127 ) ;
return 0 ;
}
int F_58 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_107 * V_108 ;
struct V_109 * V_128 ;
struct V_116 * V_117 ;
struct V_129 * V_120 ;
T_2 * V_82 ;
F_51 () ;
V_108 = F_52 ( V_13 -> V_41 . V_108 ) ;
if ( F_53 ( ! V_108 ) ) {
F_54 () ;
return - V_110 ;
}
V_128 = V_108 -> V_111 . V_44 ;
F_54 () ;
V_117 = V_15 -> V_21 . V_118 -> V_119 [ V_128 -> V_115 ] ;
V_120 = & V_117 -> V_120 ;
if ( ! V_120 -> V_121 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_123 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_124 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_125 )
return 0 ;
if ( F_39 ( V_81 ) < 2 + sizeof( struct V_130 ) )
return - V_61 ;
V_82 = F_40 ( V_81 , 2 + sizeof( struct V_130 ) ) ;
F_59 ( V_82 , V_120 , & V_13 -> V_41 . V_42 . V_43 ,
V_13 -> V_41 . V_42 . V_131 ,
false ) ;
return 0 ;
}
int F_60 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_114 V_115 = F_13 ( V_13 ) ;
struct V_116 * V_117 ;
T_2 * V_82 ;
V_117 = V_15 -> V_21 . V_118 -> V_119 [ V_115 ] ;
if ( ! V_117 -> V_132 . V_133 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_123 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_124 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_125 )
return 0 ;
if ( F_39 ( V_81 ) < 2 + sizeof( struct V_134 ) )
return - V_61 ;
V_82 = F_40 ( V_81 , 2 + sizeof( struct V_134 ) ) ;
F_61 ( V_82 , & V_117 -> V_132 , V_117 -> V_132 . V_127 ) ;
return 0 ;
}
int F_62 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_107 * V_108 ;
struct V_109 * V_128 ;
struct V_116 * V_117 ;
struct V_135 * V_132 ;
T_2 * V_82 ;
F_51 () ;
V_108 = F_52 ( V_13 -> V_41 . V_108 ) ;
if ( F_53 ( ! V_108 ) ) {
F_54 () ;
return - V_110 ;
}
V_128 = V_108 -> V_111 . V_44 ;
F_54 () ;
V_117 = V_15 -> V_21 . V_118 -> V_119 [ V_128 -> V_115 ] ;
V_132 = & V_117 -> V_132 ;
if ( ! V_132 -> V_133 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_123 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_124 ||
V_13 -> V_41 . V_42 . V_43 . V_122 == V_125 )
return 0 ;
if ( F_39 ( V_81 ) < 2 + sizeof( struct V_136 ) )
return - V_61 ;
V_82 = F_40 ( V_81 , 2 + sizeof( struct V_136 ) ) ;
F_63 ( V_82 , V_132 ,
& V_13 -> V_41 . V_42 . V_43 ) ;
return 0 ;
}
static void F_64 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
static void F_65 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_9 ( V_137 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_66 ( struct V_16 * V_17 )
{
if ( V_17 -> V_90 . V_138 > V_139 )
F_9 ( V_137 , & V_17 -> V_20 ) ;
else {
F_67 ( V_137 , & V_17 -> V_20 ) ;
F_22 ( & V_17 -> V_140 ) ;
}
}
int F_68 ( struct V_141 * V_142 , T_3 * V_143 ,
const T_2 * V_144 , const T_2 * V_145 )
{
if ( F_69 ( V_144 ) ) {
* V_143 |= F_70 ( V_146 ) ;
memcpy ( V_142 -> V_147 , V_144 , V_79 ) ;
memcpy ( V_142 -> V_148 , V_145 , V_79 ) ;
memcpy ( V_142 -> V_149 , V_145 , V_79 ) ;
return 24 ;
} else {
* V_143 |= F_70 ( V_146 | V_150 ) ;
F_71 ( V_142 -> V_147 ) ;
memcpy ( V_142 -> V_148 , V_145 , V_79 ) ;
memcpy ( V_142 -> V_149 , V_144 , V_79 ) ;
memcpy ( V_142 -> V_151 , V_145 , V_79 ) ;
return 30 ;
}
}
unsigned int F_72 ( struct V_12 * V_13 ,
struct V_69 * V_152 ,
const char * V_153 , const char * V_154 )
{
if ( F_53 ( ! V_153 && V_154 ) )
return 0 ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
V_152 -> V_155 = V_13 -> V_3 . V_18 . V_90 . V_156 ;
F_73 ( F_74 ( V_13 -> V_3 . V_18 . V_157 ) , & V_152 -> V_71 ) ;
V_13 -> V_3 . V_18 . V_157 ++ ;
if ( V_153 && ! V_154 ) {
V_152 -> V_158 |= V_159 ;
memcpy ( V_152 -> V_160 , V_153 , V_79 ) ;
return 2 * V_79 ;
} else if ( V_153 && V_154 ) {
V_152 -> V_158 |= V_161 ;
memcpy ( V_152 -> V_160 , V_153 , V_79 ) ;
memcpy ( V_152 -> V_162 , V_154 , V_79 ) ;
return 3 * V_79 ;
}
return V_79 ;
}
static void F_75 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_50 ;
if ( V_17 -> V_90 . V_163 > 0 )
F_76 ( V_13 , V_17 -> V_90 . V_163 * V_164 ) ;
F_77 ( V_13 ) ;
V_50 = F_18 ( V_13 ) ;
F_23 ( V_13 , V_50 ) ;
F_78 ( & V_17 -> V_165 ,
F_79 ( V_74 +
V_166 ) ) ;
}
static void F_80 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_167 ;
F_81 ( V_13 ) ;
if ( V_17 -> V_90 . V_138 == V_168 )
V_167 = V_17 -> V_90 . V_169 ;
else
V_167 = V_17 -> V_90 . V_170 ;
F_78 ( & V_17 -> V_140 ,
F_79 ( F_82 ( V_167 ) ) ) ;
}
static int
F_83 ( struct V_16 * V_17 )
{
struct V_171 * V_172 ;
int V_173 , V_174 ;
struct V_80 * V_81 ;
struct V_1 * V_2 ;
struct V_107 * V_108 ;
struct V_175 * V_176 ;
enum V_114 V_115 ;
T_2 * V_82 ;
struct V_12 * V_13 ;
int V_177 = F_84 ( struct V_1 , V_3 . V_178 ) +
sizeof( V_2 -> V_3 . V_178 ) ;
V_13 = F_85 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_51 () ;
V_108 = F_52 ( V_13 -> V_41 . V_108 ) ;
V_115 = V_108 -> V_111 . V_44 -> V_115 ;
F_54 () ;
V_173 = V_177 +
2 +
2 + sizeof( struct V_179 ) +
2 + sizeof( struct V_180 ) +
2 + 8 +
2 + 3 ;
V_174 = 2 + ( V_181 - 8 ) +
2 + sizeof( struct V_126 ) +
2 + sizeof( struct V_130 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_85 ) +
2 + sizeof( T_3 ) +
2 + sizeof( struct V_134 ) +
2 + sizeof( struct V_136 ) +
V_17 -> V_105 ;
V_172 = F_86 ( sizeof( * V_172 ) + V_173 + V_174 , V_60 ) ;
V_81 = F_87 ( F_88 ( V_173 , V_174 ) ) ;
if ( ! V_172 || ! V_81 )
goto V_182;
V_172 -> V_183 = ( ( T_2 * ) V_172 ) + sizeof( * V_172 ) ;
V_2 = (struct V_1 * ) F_40 ( V_81 , V_177 ) ;
memset ( V_2 , 0 , V_177 ) ;
V_2 -> V_184 = F_70 ( V_185 |
V_186 ) ;
F_89 ( V_2 -> V_187 ) ;
memcpy ( V_2 -> V_68 , V_13 -> V_41 . V_188 , V_79 ) ;
memcpy ( V_2 -> V_189 , V_13 -> V_41 . V_188 , V_79 ) ;
F_90 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_178 . V_190 =
F_70 ( V_13 -> V_41 . V_42 . V_190 ) ;
V_2 -> V_3 . V_178 . V_191 |= F_70 (
V_13 -> V_3 . V_18 . V_192 ? V_193 : 0 ) ;
V_82 = F_40 ( V_81 , 2 ) ;
* V_82 ++ = V_194 ;
* V_82 ++ = 0x0 ;
F_51 () ;
V_176 = F_52 ( V_17 -> V_176 ) ;
if ( V_176 ) {
V_82 = F_40 ( V_81 , 13 ) ;
memset ( V_82 , 0 , 13 ) ;
* V_82 ++ = V_195 ;
* V_82 ++ = 3 ;
* V_82 ++ = 0x0 ;
* V_82 ++ = F_55 (
V_176 -> V_196 . V_43 . V_44 -> V_113 ) ;
V_172 -> V_197 = V_176 -> V_196 . V_198 ;
V_172 -> V_199 [ 0 ] = V_177 + 6 ;
* V_82 ++ = V_176 -> V_196 . V_198 ;
* V_82 ++ = V_200 ;
* V_82 ++ = 6 ;
if ( V_17 -> V_201 == V_202 ) {
* V_82 ++ = V_17 -> V_90 . V_156 ;
* V_82 |= V_203 ;
} else {
* V_82 ++ = V_17 -> V_204 ;
}
* V_82 ++ |= V_176 -> V_196 . V_205 ?
V_206 : 0x00 ;
F_45 ( V_207 , V_82 ) ;
V_82 += 2 ;
F_45 ( V_17 -> V_208 , V_82 ) ;
V_82 += 2 ;
}
F_54 () ;
if ( F_91 ( V_13 , V_81 , true , V_115 ) ||
F_50 ( V_13 , V_81 ) )
goto V_182;
V_172 -> V_173 = V_81 -> V_104 ;
memcpy ( V_172 -> V_183 , V_81 -> V_11 , V_172 -> V_173 ) ;
F_92 ( V_81 , 0 ) ;
V_172 -> V_209 = V_172 -> V_183 + V_172 -> V_173 ;
if ( F_93 ( V_13 , V_81 , true , V_115 ) ||
F_48 ( V_13 , V_81 ) ||
F_56 ( V_13 , V_81 ) ||
F_58 ( V_13 , V_81 ) ||
F_43 ( V_13 , V_81 ) ||
F_38 ( V_13 , V_81 ) ||
F_44 ( V_13 , V_81 ) ||
F_60 ( V_13 , V_81 ) ||
F_62 ( V_13 , V_81 ) ||
F_46 ( V_13 , V_81 ) )
goto V_182;
V_172 -> V_174 = V_81 -> V_104 ;
memcpy ( V_172 -> V_209 , V_81 -> V_11 , V_172 -> V_174 ) ;
V_172 -> V_210 = (struct V_85 * )
( V_172 -> V_209 + V_17 -> V_87 ) ;
F_94 ( V_81 ) ;
F_95 ( V_17 -> V_178 , V_172 ) ;
return 0 ;
V_182:
F_31 ( V_172 ) ;
F_94 ( V_81 ) ;
return - V_61 ;
}
static int
F_96 ( struct V_12 * V_13 )
{
struct V_171 * V_211 ;
int V_212 ;
V_211 = F_97 ( V_13 -> V_3 . V_18 . V_178 ,
F_98 ( & V_13 -> V_213 . V_214 ) ) ;
V_212 = F_83 ( & V_13 -> V_3 . V_18 ) ;
if ( V_212 )
return V_212 ;
if ( V_211 )
F_99 ( V_211 , V_215 ) ;
return 0 ;
}
void F_23 ( struct V_12 * V_13 ,
T_1 V_50 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_216 = V_50 ;
T_1 V_217 ;
if ( ! V_216 )
return;
F_100 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_9 ( V_217 , & V_17 -> V_218 ) ;
F_9 ( V_219 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_101 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_50 = V_52 |
V_220 |
V_221 |
V_222 |
V_223 ;
V_15 -> V_224 ++ ;
F_102 ( & V_15 -> V_225 ) ;
F_103 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_226 = F_104 ( V_17 -> V_37 ) ;
V_17 -> V_95 = false ;
V_17 -> V_227 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_66 ( V_17 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_131 =
V_17 -> V_90 . V_228 ;
V_13 -> V_41 . V_42 . V_229 = true ;
V_50 |= F_105 ( V_13 ) ;
if ( F_83 ( V_17 ) ) {
F_106 ( V_13 ) ;
return - V_61 ;
}
F_107 ( V_15 , V_13 ) ;
F_108 ( V_13 , V_50 ) ;
F_109 ( V_13 -> V_230 ) ;
return 0 ;
}
void F_106 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_171 * V_172 ;
F_110 ( V_13 -> V_230 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_229 = false ;
F_67 ( V_231 , & V_13 -> V_232 ) ;
F_108 ( V_13 , V_220 ) ;
V_172 = F_97 ( V_17 -> V_178 ,
F_98 ( & V_13 -> V_213 . V_214 ) ) ;
F_111 ( V_17 -> V_178 , NULL ) ;
F_99 ( V_172 , V_215 ) ;
F_112 ( V_13 ) ;
F_113 ( V_13 ) ;
V_15 -> V_233 -= F_114 ( & V_17 -> V_234 . V_235 ) ;
F_115 ( & V_17 -> V_234 . V_235 ) ;
F_22 ( & V_13 -> V_3 . V_18 . V_165 ) ;
F_22 ( & V_13 -> V_3 . V_18 . V_140 ) ;
F_22 ( & V_13 -> V_3 . V_18 . V_236 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_218 = 0 ;
V_15 -> V_224 -- ;
F_116 ( & V_15 -> V_225 ) ;
F_103 ( V_15 ) ;
}
static bool
F_117 ( struct V_12 * V_13 ,
struct V_23 * V_237 , bool V_178 )
{
struct V_238 V_239 ;
struct V_240 V_241 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
enum V_114 V_115 = F_13 ( V_13 ) ;
int V_242 ;
T_1 V_243 ;
F_118 ( V_13 ) ;
V_243 = V_244 ;
switch ( V_13 -> V_41 . V_42 . V_43 . V_122 ) {
case V_123 :
V_243 |= V_245 ;
case V_246 :
V_243 |= V_247 ;
break;
default:
break;
}
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_242 = F_119 ( V_13 , V_237 , V_115 ,
V_243 , V_13 -> V_41 . V_188 ,
& V_241 ) ;
if ( V_242 < 0 )
return false ;
if ( V_242 )
return false ;
V_239 . V_43 = V_241 . V_43 ;
V_239 . V_198 = V_241 . V_198 ;
if ( ! F_120 ( V_13 -> V_15 -> V_21 . V_118 , & V_239 . V_43 ,
V_248 ) ) {
F_121 ( V_13 ,
L_2 ,
V_13 -> V_41 . V_188 ,
V_239 . V_43 . V_44 -> V_113 ,
V_239 . V_43 . V_122 ,
V_239 . V_43 . V_249 ,
V_239 . V_43 . V_250 ) ;
return false ;
}
V_242 = F_122 ( V_13 -> V_15 -> V_21 . V_118 ,
& V_239 . V_43 ,
V_251 ) ;
if ( V_242 < 0 )
return false ;
if ( V_242 > 0 )
return false ;
V_239 . V_252 = V_242 ;
if ( F_123 ( & V_239 . V_43 ,
& V_13 -> V_41 . V_42 . V_43 ) ) {
F_124 ( V_13 ,
L_3 ) ;
return true ;
}
F_124 ( V_13 ,
L_4 ,
V_239 . V_43 . V_44 -> V_113 ) ;
V_239 . V_205 = V_241 . V_253 & V_206 ;
if ( V_178 ) {
V_17 -> V_204 = V_241 . V_155 - 1 ;
if ( V_17 -> V_208 >= V_241 . V_208 )
return false ;
V_17 -> V_208 = V_241 . V_208 ;
}
if ( V_17 -> V_204 >= V_17 -> V_90 . V_156 )
return false ;
V_17 -> V_201 = V_254 ;
if ( F_125 ( V_13 -> V_15 -> V_21 . V_118 , V_13 -> V_230 ,
& V_239 ) < 0 )
return false ;
return true ;
}
static void
F_126 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_104 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_80 * V_255 ;
struct V_171 * V_172 ;
struct V_1 * V_142 ;
struct V_23 V_237 ;
T_4 V_256 ;
T_2 * V_82 ;
V_82 = V_2 -> V_3 . V_257 . V_258 ;
V_256 = ( T_2 * ) V_82 - ( T_2 * ) V_2 ;
if ( V_256 > V_104 )
return;
F_127 ( V_82 , V_104 - V_256 , false , & V_237 ) ;
if ( ! V_237 . V_29 )
return;
if ( ( ! F_35 ( V_2 -> V_187 , V_13 -> V_41 . V_188 ) &&
! F_128 ( V_2 -> V_187 ) ) ||
V_237 . V_259 != 0 )
return;
if ( V_237 . V_28 != 0 &&
( V_237 . V_28 != V_17 -> V_28 ||
memcmp ( V_237 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_51 () ;
V_172 = F_52 ( V_17 -> V_178 ) ;
if ( ! V_172 )
goto V_260;
V_255 = F_87 ( V_15 -> V_261 +
V_172 -> V_173 + V_172 -> V_174 ) ;
if ( ! V_255 )
goto V_260;
F_129 ( V_255 , V_15 -> V_261 ) ;
memcpy ( F_40 ( V_255 , V_172 -> V_173 ) , V_172 -> V_183 , V_172 -> V_173 ) ;
memcpy ( F_40 ( V_255 , V_172 -> V_174 ) , V_172 -> V_209 , V_172 -> V_174 ) ;
V_142 = (struct V_1 * ) V_255 -> V_11 ;
V_142 -> V_184 = F_70 ( V_185 |
V_262 ) ;
memcpy ( V_142 -> V_187 , V_2 -> V_68 , V_79 ) ;
F_130 ( V_255 ) -> V_158 |= V_263 ;
F_131 ( V_13 , V_255 ) ;
V_260:
F_54 () ;
}
static void F_132 ( struct V_12 * V_13 ,
T_5 V_264 ,
struct V_1 * V_2 ,
T_4 V_104 ,
struct V_265 * V_266 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_237 ;
struct V_109 * V_128 ;
T_4 V_256 ;
int V_267 ;
enum V_114 V_115 = V_266 -> V_115 ;
if ( V_264 == V_262 &&
! F_35 ( V_2 -> V_187 , V_13 -> V_41 . V_188 ) )
return;
V_256 = ( T_2 * ) V_2 -> V_3 . V_268 . V_258 - ( T_2 * ) V_2 ;
if ( V_256 > V_104 )
return;
F_127 ( V_2 -> V_3 . V_268 . V_258 , V_104 - V_256 ,
false , & V_237 ) ;
if ( ( ! V_237 . V_29 || ! V_237 . V_31 ) ||
( V_237 . V_269 && V_13 -> V_3 . V_18 . V_192 == V_270 ) ||
( ! V_237 . V_269 && V_13 -> V_3 . V_18 . V_192 != V_270 ) )
return;
if ( V_237 . V_271 )
V_267 = F_133 ( V_237 . V_271 [ 0 ] , V_115 ) ;
else
V_267 = V_266 -> V_267 ;
V_128 = F_134 ( V_15 -> V_21 . V_118 , V_267 ) ;
if ( ! V_128 || V_128 -> V_158 & V_248 )
return;
if ( F_11 ( V_13 , & V_237 ) )
F_135 ( V_13 , V_2 -> V_68 , & V_237 ) ;
if ( V_17 -> V_226 )
V_17 -> V_226 -> V_272 ( V_13 ,
V_264 , V_2 , & V_237 , V_266 ) ;
if ( V_17 -> V_201 != V_202 &&
! V_13 -> V_41 . V_273 )
F_117 ( V_13 , & V_237 , true ) ;
}
int F_136 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_175 * V_274 ;
int V_212 = 0 ;
int V_50 = 0 ;
V_17 -> V_201 = V_275 ;
V_17 -> V_204 = 0 ;
V_274 = F_52 ( V_17 -> V_176 ) ;
F_111 ( V_17 -> V_176 , NULL ) ;
if ( V_274 )
F_99 ( V_274 , V_215 ) ;
V_212 = F_96 ( V_13 ) ;
if ( V_212 )
return - V_110 ;
V_50 |= V_52 ;
F_124 ( V_13 , L_5 ,
V_13 -> V_41 . V_42 . V_43 . V_44 -> V_113 ) ;
return V_50 ;
}
int F_137 ( struct V_12 * V_13 ,
struct V_238 * V_276 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_175 * V_274 ;
int V_212 = 0 ;
V_274 = F_25 ( sizeof( * V_274 ) ,
V_77 ) ;
if ( ! V_274 )
return - V_61 ;
memcpy ( & V_274 -> V_196 , V_276 ,
sizeof( struct V_238 ) ) ;
F_95 ( V_17 -> V_176 , V_274 ) ;
V_212 = F_96 ( V_13 ) ;
if ( V_212 ) {
V_274 = F_52 ( V_17 -> V_176 ) ;
F_111 ( V_17 -> V_176 , NULL ) ;
F_99 ( V_274 , V_215 ) ;
return V_212 ;
}
return V_52 ;
}
static int F_138 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_104 )
{
struct V_1 * V_277 ;
struct V_80 * V_81 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_2 * V_82 = V_2 -> V_3 . V_4 . V_3 . V_278 . V_258 ;
T_4 V_279 ;
V_81 = F_87 ( V_15 -> V_261 + V_104 ) ;
if ( ! V_81 )
return - V_61 ;
F_129 ( V_81 , V_15 -> V_261 ) ;
V_277 = (struct V_1 * ) F_40 ( V_81 , V_104 ) ;
V_279 = ( V_104 < 42 ) ? 7 : 10 ;
* ( V_82 + V_279 ) -= 1 ;
* ( V_82 + V_279 + 1 ) &= ~ V_203 ;
memcpy ( V_277 , V_2 , V_104 ) ;
F_89 ( V_277 -> V_187 ) ;
memcpy ( V_277 -> V_68 , V_13 -> V_41 . V_188 , V_79 ) ;
memcpy ( V_277 -> V_189 , V_13 -> V_41 . V_188 , V_79 ) ;
F_131 ( V_13 , V_81 ) ;
return 0 ;
}
static void F_139 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_104 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_237 ;
T_5 V_208 ;
bool V_280 = true ;
T_4 V_256 ;
T_2 * V_82 ;
if ( V_2 -> V_3 . V_4 . V_3 . V_281 . V_6 !=
V_282 )
return;
V_82 = V_2 -> V_3 . V_4 . V_3 . V_278 . V_258 ;
V_256 = F_84 ( struct V_1 ,
V_3 . V_4 . V_3 . V_278 . V_258 ) ;
F_127 ( V_82 , V_104 - V_256 , false , & V_237 ) ;
V_17 -> V_204 = V_237 . V_283 -> V_284 ;
if ( ! -- V_17 -> V_204 )
V_280 = false ;
V_208 = F_140 ( V_237 . V_283 -> V_285 ) ;
if ( V_17 -> V_208 >= V_208 )
return;
V_17 -> V_208 = V_208 ;
if ( ! V_13 -> V_41 . V_273 &&
! F_117 ( V_13 , & V_237 , false ) ) {
F_124 ( V_13 , L_6 ) ;
return;
}
if ( V_280 ) {
if ( F_138 ( V_13 , V_2 , V_104 ) < 0 )
F_124 ( V_13 , L_7 ) ;
}
}
static void F_141 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_104 ,
struct V_265 * V_266 )
{
switch ( V_2 -> V_3 . V_4 . V_286 ) {
case V_287 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_288 . V_6 ) {
case V_289 :
case V_290 :
case V_291 :
F_142 ( V_13 , V_2 , V_104 , V_266 ) ;
break;
}
break;
case V_292 :
if ( F_1 ( V_2 ) )
F_143 ( V_13 , V_2 , V_104 ) ;
break;
case V_293 :
F_139 ( V_13 , V_2 , V_104 ) ;
break;
}
}
void F_144 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_265 * V_266 ;
struct V_1 * V_2 ;
T_5 V_264 ;
F_145 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_260;
V_266 = F_146 ( V_81 ) ;
V_2 = (struct V_1 * ) V_81 -> V_11 ;
V_264 = F_140 ( V_2 -> V_184 ) & V_294 ;
switch ( V_264 ) {
case V_262 :
case V_186 :
F_132 ( V_13 , V_264 , V_2 , V_81 -> V_104 ,
V_266 ) ;
break;
case V_295 :
F_126 ( V_13 , V_2 , V_81 -> V_104 ) ;
break;
case V_296 :
F_141 ( V_13 , V_2 , V_81 -> V_104 , V_266 ) ;
break;
}
V_260:
F_147 ( V_13 ) ;
}
static void F_148 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_217 , V_50 = 0 ;
F_100 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_67 ( V_217 , & V_17 -> V_218 ) ;
V_50 |= F_149 ( V_217 ) ;
}
if ( V_13 -> V_41 . V_42 . V_229 &&
( V_50 & ( V_52 |
V_221 |
V_222 |
V_223 ) ) )
if ( F_96 ( V_13 ) )
return;
F_108 ( V_13 , V_50 ) ;
}
void F_150 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_145 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_260;
if ( V_17 -> V_297 &&
F_34 ( V_74 ,
V_17 -> V_298 + F_151 ( V_17 -> V_90 . V_299 ) ) )
F_152 ( V_13 ) ;
if ( F_153 ( V_300 , & V_17 -> V_20 ) )
F_154 () ;
if ( F_153 ( V_301 , & V_17 -> V_20 ) )
F_155 () ;
if ( F_153 ( V_19 , & V_17 -> V_20 ) )
F_75 ( V_13 ) ;
if ( F_153 ( V_137 , & V_17 -> V_20 ) )
F_80 ( V_13 ) ;
if ( F_153 ( V_302 , & V_17 -> V_20 ) )
F_156 ( V_13 ) ;
if ( F_153 ( V_219 , & V_17 -> V_20 ) )
F_148 ( V_13 ) ;
V_260:
F_147 ( V_13 ) ;
}
void F_157 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_51 () ;
F_158 (sdata, &local->interfaces, list)
if ( F_159 ( & V_13 -> V_41 ) &&
F_160 ( V_13 ) )
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
F_54 () ;
}
void F_161 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_303 [ V_79 ] = {} ;
F_162 ( & V_17 -> V_165 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_51 = true ;
F_163 ( & V_17 -> V_304 , 0 ) ;
F_24 ( V_13 ) ;
V_17 -> V_298 = V_74 ;
V_17 -> V_305 = V_74 ;
V_17 -> V_201 = V_275 ;
if ( ! V_8 )
F_2 () ;
F_162 ( & V_17 -> V_236 ,
F_64 ,
( unsigned long ) V_13 ) ;
F_162 ( & V_17 -> V_140 ,
F_65 ,
( unsigned long ) V_13 ) ;
F_26 ( & V_17 -> V_306 . V_67 ) ;
F_164 ( & V_17 -> V_234 . V_235 ) ;
F_165 ( & V_17 -> V_307 ) ;
F_165 ( & V_17 -> V_308 ) ;
F_111 ( V_17 -> V_178 , NULL ) ;
V_13 -> V_41 . V_42 . V_189 = V_303 ;
}
