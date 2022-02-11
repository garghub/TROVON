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
T_1 V_51 = F_20 ( V_55 ) ;
if ( V_51 )
F_21 ( V_13 , V_51 ) ;
}
int F_22 ( struct V_12 * V_13 )
{
int V_56 ;
V_13 -> V_3 . V_18 . V_57 = F_23 ( sizeof( struct V_58 ) , V_59 ) ;
if ( ! V_13 -> V_3 . V_18 . V_57 )
return - V_60 ;
V_13 -> V_3 . V_18 . V_57 -> V_61 = V_62 - 1 ;
for ( V_56 = 0 ; V_56 < V_62 ; V_56 ++ )
F_24 ( & V_13 -> V_3 . V_18 . V_57 -> V_63 [ V_56 ] ) ;
return 0 ;
}
void F_25 ( struct V_12 * V_13 )
{
struct V_58 * V_57 = V_13 -> V_3 . V_18 . V_57 ;
struct V_10 * V_64 ;
struct V_65 * V_66 ;
int V_56 ;
if ( ! V_13 -> V_3 . V_18 . V_57 )
return;
for ( V_56 = 0 ; V_56 < V_62 ; V_56 ++ ) {
F_26 (p, n, &rmc->bucket[i], list) {
F_27 ( & V_64 -> V_67 ) ;
F_28 ( V_9 , V_64 ) ;
}
}
F_29 ( V_57 ) ;
V_13 -> V_3 . V_18 . V_57 = NULL ;
}
int F_30 ( struct V_12 * V_13 ,
const T_2 * V_68 , struct V_69 * V_70 )
{
struct V_58 * V_57 = V_13 -> V_3 . V_18 . V_57 ;
T_1 V_71 = 0 ;
int V_72 = 0 ;
T_2 V_73 ;
struct V_10 * V_64 ;
struct V_65 * V_66 ;
if ( ! V_57 )
return - 1 ;
memcpy ( & V_71 , & V_70 -> V_71 , sizeof( V_70 -> V_71 ) ) ;
V_73 = F_31 ( V_70 -> V_71 ) & V_57 -> V_61 ;
F_26 (p, n, &rmc->bucket[idx], list) {
++ V_72 ;
if ( F_32 ( V_74 , V_64 -> V_75 ) ||
V_72 == V_76 ) {
F_27 ( & V_64 -> V_67 ) ;
F_28 ( V_9 , V_64 ) ;
-- V_72 ;
} else if ( ( V_71 == V_64 -> V_71 ) && F_33 ( V_68 , V_64 -> V_68 ) )
return - 1 ;
}
V_64 = F_34 ( V_9 , V_77 ) ;
if ( ! V_64 )
return 0 ;
V_64 -> V_71 = V_71 ;
V_64 -> V_75 = V_74 + V_78 ;
memcpy ( V_64 -> V_68 , V_68 , V_79 ) ;
F_35 ( & V_64 -> V_67 , & V_57 -> V_63 [ V_73 ] ) ;
return 0 ;
}
int F_36 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_82 , V_83 ;
T_2 V_84 = sizeof( struct V_85 ) ;
if ( F_37 ( V_81 ) < 2 + V_84 )
return - V_60 ;
V_82 = F_38 ( V_81 , 2 + V_84 ) ;
* V_82 ++ = V_86 ;
* V_82 ++ = V_84 ;
V_17 -> V_87 = V_82 - V_81 -> V_11 ;
* V_82 ++ = V_17 -> V_30 ;
* V_82 ++ = V_17 -> V_33 ;
* V_82 ++ = V_17 -> V_35 ;
* V_82 ++ = V_17 -> V_37 ;
* V_82 ++ = V_17 -> V_39 ;
V_83 = F_39 ( & V_17 -> V_88 ) ;
V_83 = F_40 ( int , V_83 , V_89 ) ;
* V_82 ++ = V_83 << 1 ;
* V_82 = 0x00 ;
* V_82 |= V_17 -> V_90 . V_91 ?
V_92 : 0x00 ;
* V_82 |= V_17 -> V_52 ?
V_49 : 0x00 ;
* V_82 |= V_17 -> V_93 ?
V_94 : 0x00 ;
return 0 ;
}
int F_41 ( struct V_12 * V_13 , struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_82 ;
if ( F_37 ( V_81 ) < 2 + V_17 -> V_28 )
return - V_60 ;
V_82 = F_38 ( V_81 , 2 + V_17 -> V_28 ) ;
* V_82 ++ = V_95 ;
* V_82 ++ = V_17 -> V_28 ;
if ( V_17 -> V_28 )
memcpy ( V_82 , V_17 -> V_29 , V_17 -> V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_82 ;
if ( V_17 -> V_96 == 0 &&
V_17 -> V_93 == 0 &&
V_17 -> V_97 == V_98 )
return 0 ;
if ( F_37 ( V_81 ) < 4 )
return - V_60 ;
V_82 = F_38 ( V_81 , 2 + 2 ) ;
* V_82 ++ = V_99 ;
* V_82 ++ = 2 ;
F_43 ( V_17 -> V_90 . V_100 , V_82 ) ;
return 0 ;
}
int F_44 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_101 , V_102 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_103 )
return 0 ;
V_101 = F_45 ( V_17 -> V_24 , V_17 -> V_103 , 0 ) ;
if ( V_101 < V_17 -> V_103 ) {
V_102 = V_17 -> V_103 - V_101 ;
V_11 = V_17 -> V_24 + V_101 ;
if ( F_37 ( V_81 ) < V_102 )
return - V_60 ;
memcpy ( F_38 ( V_81 , V_102 ) , V_11 , V_102 ) ;
}
return 0 ;
}
int F_46 ( struct V_12 * V_13 , struct V_80 * V_81 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_102 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_103 )
return 0 ;
V_11 = F_47 ( V_104 , V_17 -> V_24 , V_17 -> V_103 ) ;
if ( ! V_11 )
return 0 ;
V_102 = V_11 [ 1 ] + 2 ;
if ( F_37 ( V_81 ) < V_102 )
return - V_60 ;
memcpy ( F_38 ( V_81 , V_102 ) , V_11 , V_102 ) ;
return 0 ;
}
static int F_48 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_105 * V_106 ;
struct V_107 * V_44 ;
T_2 * V_82 ;
if ( F_37 ( V_81 ) < 3 )
return - V_60 ;
F_49 () ;
V_106 = F_50 ( V_13 -> V_41 . V_106 ) ;
if ( F_51 ( ! V_106 ) ) {
F_52 () ;
return - V_108 ;
}
V_44 = V_106 -> V_109 . V_44 ;
F_52 () ;
V_82 = F_38 ( V_81 , 2 + 1 ) ;
* V_82 ++ = V_110 ;
* V_82 ++ = 1 ;
* V_82 ++ = F_53 ( V_44 -> V_111 ) ;
return 0 ;
}
int F_54 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_112 V_113 = F_11 ( V_13 ) ;
struct V_114 * V_115 ;
T_2 * V_82 ;
V_115 = V_15 -> V_21 . V_116 -> V_117 [ V_113 ] ;
if ( ! V_115 -> V_118 . V_119 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_121 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_122 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_123 )
return 0 ;
if ( F_37 ( V_81 ) < 2 + sizeof( struct V_124 ) )
return - V_60 ;
V_82 = F_38 ( V_81 , 2 + sizeof( struct V_124 ) ) ;
F_55 ( V_82 , & V_115 -> V_118 , V_115 -> V_118 . V_125 ) ;
return 0 ;
}
int F_56 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_105 * V_106 ;
struct V_107 * V_126 ;
struct V_114 * V_115 ;
struct V_127 * V_118 ;
T_2 * V_82 ;
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
if ( ! V_118 -> V_119 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_121 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_122 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_123 )
return 0 ;
if ( F_37 ( V_81 ) < 2 + sizeof( struct V_128 ) )
return - V_60 ;
V_82 = F_38 ( V_81 , 2 + sizeof( struct V_128 ) ) ;
F_57 ( V_82 , V_118 , & V_13 -> V_41 . V_42 . V_43 ,
V_13 -> V_41 . V_42 . V_129 ,
false ) ;
return 0 ;
}
int F_58 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_112 V_113 = F_11 ( V_13 ) ;
struct V_114 * V_115 ;
T_2 * V_82 ;
V_115 = V_15 -> V_21 . V_116 -> V_117 [ V_113 ] ;
if ( ! V_115 -> V_130 . V_131 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_121 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_122 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_123 )
return 0 ;
if ( F_37 ( V_81 ) < 2 + sizeof( struct V_132 ) )
return - V_60 ;
V_82 = F_38 ( V_81 , 2 + sizeof( struct V_132 ) ) ;
F_59 ( V_82 , & V_115 -> V_130 , V_115 -> V_130 . V_125 ) ;
return 0 ;
}
int F_60 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_105 * V_106 ;
struct V_107 * V_126 ;
struct V_114 * V_115 ;
struct V_133 * V_130 ;
T_2 * V_82 ;
F_49 () ;
V_106 = F_50 ( V_13 -> V_41 . V_106 ) ;
if ( F_51 ( ! V_106 ) ) {
F_52 () ;
return - V_108 ;
}
V_126 = V_106 -> V_109 . V_44 ;
F_52 () ;
V_115 = V_15 -> V_21 . V_116 -> V_117 [ V_126 -> V_113 ] ;
V_130 = & V_115 -> V_130 ;
if ( ! V_130 -> V_131 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_121 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_122 ||
V_13 -> V_41 . V_42 . V_43 . V_120 == V_123 )
return 0 ;
if ( F_37 ( V_81 ) < 2 + sizeof( struct V_134 ) )
return - V_60 ;
V_82 = F_38 ( V_81 , 2 + sizeof( struct V_134 ) ) ;
F_61 ( V_82 , V_130 ,
& V_13 -> V_41 . V_42 . V_43 ) ;
return 0 ;
}
static void F_62 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
F_8 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
static void F_63 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_7 ( V_135 , & V_17 -> V_20 ) ;
F_8 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_64 ( struct V_16 * V_17 )
{
if ( V_17 -> V_90 . V_136 > V_137 )
F_7 ( V_135 , & V_17 -> V_20 ) ;
else {
F_65 ( V_135 , & V_17 -> V_20 ) ;
F_66 ( & V_17 -> V_138 ) ;
}
}
int F_67 ( struct V_139 * V_140 , T_3 * V_141 ,
const T_2 * V_142 , const T_2 * V_143 )
{
if ( F_68 ( V_142 ) ) {
* V_141 |= F_69 ( V_144 ) ;
memcpy ( V_140 -> V_145 , V_142 , V_79 ) ;
memcpy ( V_140 -> V_146 , V_143 , V_79 ) ;
memcpy ( V_140 -> V_147 , V_143 , V_79 ) ;
return 24 ;
} else {
* V_141 |= F_69 ( V_144 | V_148 ) ;
F_70 ( V_140 -> V_145 ) ;
memcpy ( V_140 -> V_146 , V_143 , V_79 ) ;
memcpy ( V_140 -> V_147 , V_142 , V_79 ) ;
memcpy ( V_140 -> V_149 , V_143 , V_79 ) ;
return 30 ;
}
}
unsigned int F_71 ( struct V_12 * V_13 ,
struct V_69 * V_150 ,
const char * V_151 , const char * V_152 )
{
if ( F_51 ( ! V_151 && V_152 ) )
return 0 ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_153 = V_13 -> V_3 . V_18 . V_90 . V_154 ;
F_72 ( F_73 ( V_13 -> V_3 . V_18 . V_155 ) , & V_150 -> V_71 ) ;
V_13 -> V_3 . V_18 . V_155 ++ ;
if ( V_151 && ! V_152 ) {
V_150 -> V_156 |= V_157 ;
memcpy ( V_150 -> V_158 , V_151 , V_79 ) ;
return 2 * V_79 ;
} else if ( V_151 && V_152 ) {
V_150 -> V_156 |= V_159 ;
memcpy ( V_150 -> V_158 , V_151 , V_79 ) ;
memcpy ( V_150 -> V_160 , V_152 , V_79 ) ;
return 3 * V_79 ;
}
return V_79 ;
}
static void F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_51 ;
if ( V_17 -> V_90 . V_161 > 0 )
F_75 ( V_13 , V_17 -> V_90 . V_161 * V_162 ) ;
F_76 ( V_13 ) ;
V_51 = F_17 ( V_13 ) ;
F_21 ( V_13 , V_51 ) ;
F_77 ( & V_17 -> V_163 ,
F_78 ( V_74 +
V_164 ) ) ;
}
static void F_79 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_165 ;
F_80 ( V_13 ) ;
if ( V_17 -> V_90 . V_136 == V_166 )
V_165 = V_17 -> V_90 . V_167 ;
else
V_165 = V_17 -> V_90 . V_168 ;
F_77 ( & V_17 -> V_138 ,
F_78 ( F_81 ( V_165 ) ) ) ;
}
static int
F_82 ( struct V_16 * V_17 )
{
struct V_169 * V_170 ;
int V_171 , V_172 ;
struct V_80 * V_81 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
struct V_173 * V_174 ;
enum V_112 V_113 ;
T_2 * V_82 ;
struct V_12 * V_13 ;
int V_175 = F_83 ( struct V_1 , V_3 . V_176 ) +
sizeof( V_2 -> V_3 . V_176 ) ;
V_13 = F_84 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_49 () ;
V_106 = F_50 ( V_13 -> V_41 . V_106 ) ;
V_113 = V_106 -> V_109 . V_44 -> V_113 ;
F_52 () ;
V_171 = V_175 +
2 +
2 + sizeof( struct V_177 ) +
2 + sizeof( struct V_178 ) +
2 + 8 +
2 + 3 ;
V_172 = 2 + ( V_179 - 8 ) +
2 + sizeof( struct V_124 ) +
2 + sizeof( struct V_128 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_85 ) +
2 + sizeof( T_3 ) +
2 + sizeof( struct V_132 ) +
2 + sizeof( struct V_134 ) +
V_17 -> V_103 ;
V_170 = F_85 ( sizeof( * V_170 ) + V_171 + V_172 , V_59 ) ;
V_81 = F_86 ( F_87 ( V_171 , V_172 ) ) ;
if ( ! V_170 || ! V_81 )
goto V_180;
V_170 -> V_181 = ( ( T_2 * ) V_170 ) + sizeof( * V_170 ) ;
V_2 = (struct V_1 * ) F_38 ( V_81 , V_175 ) ;
memset ( V_2 , 0 , V_175 ) ;
V_2 -> V_182 = F_69 ( V_183 |
V_184 ) ;
F_88 ( V_2 -> V_185 ) ;
memcpy ( V_2 -> V_68 , V_13 -> V_41 . V_186 , V_79 ) ;
memcpy ( V_2 -> V_187 , V_13 -> V_41 . V_186 , V_79 ) ;
F_89 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_176 . V_188 =
F_69 ( V_13 -> V_41 . V_42 . V_188 ) ;
V_2 -> V_3 . V_176 . V_189 |= F_69 (
V_13 -> V_3 . V_18 . V_190 ? V_191 : 0 ) ;
V_82 = F_38 ( V_81 , 2 ) ;
* V_82 ++ = V_192 ;
* V_82 ++ = 0x0 ;
F_49 () ;
V_174 = F_50 ( V_17 -> V_174 ) ;
if ( V_174 ) {
V_82 = F_38 ( V_81 , 13 ) ;
memset ( V_82 , 0 , 13 ) ;
* V_82 ++ = V_193 ;
* V_82 ++ = 3 ;
* V_82 ++ = 0x0 ;
* V_82 ++ = F_53 (
V_174 -> V_194 . V_43 . V_44 -> V_111 ) ;
V_170 -> V_195 = V_174 -> V_194 . V_196 ;
V_170 -> V_197 [ 0 ] = V_175 + 6 ;
* V_82 ++ = V_174 -> V_194 . V_196 ;
* V_82 ++ = V_198 ;
* V_82 ++ = 6 ;
if ( V_17 -> V_199 == V_200 ) {
* V_82 ++ = V_17 -> V_90 . V_154 ;
* V_82 |= V_201 ;
} else {
* V_82 ++ = V_17 -> V_202 ;
}
* V_82 ++ |= V_174 -> V_194 . V_203 ?
V_204 : 0x00 ;
F_43 ( V_205 , V_82 ) ;
V_82 += 2 ;
F_43 ( V_17 -> V_206 , V_82 ) ;
V_82 += 2 ;
}
F_52 () ;
if ( F_90 ( V_13 , V_81 , true , V_113 ) ||
F_48 ( V_13 , V_81 ) )
goto V_180;
V_170 -> V_171 = V_81 -> V_102 ;
memcpy ( V_170 -> V_181 , V_81 -> V_11 , V_170 -> V_171 ) ;
F_91 ( V_81 , 0 ) ;
V_170 -> V_207 = V_170 -> V_181 + V_170 -> V_171 ;
if ( F_92 ( V_13 , V_81 , true , V_113 ) ||
F_46 ( V_13 , V_81 ) ||
F_54 ( V_13 , V_81 ) ||
F_56 ( V_13 , V_81 ) ||
F_41 ( V_13 , V_81 ) ||
F_36 ( V_13 , V_81 ) ||
F_42 ( V_13 , V_81 ) ||
F_58 ( V_13 , V_81 ) ||
F_60 ( V_13 , V_81 ) ||
F_44 ( V_13 , V_81 ) )
goto V_180;
V_170 -> V_172 = V_81 -> V_102 ;
memcpy ( V_170 -> V_207 , V_81 -> V_11 , V_170 -> V_172 ) ;
V_170 -> V_208 = (struct V_85 * )
( V_170 -> V_207 + V_17 -> V_87 ) ;
F_93 ( V_81 ) ;
F_94 ( V_17 -> V_176 , V_170 ) ;
return 0 ;
V_180:
F_29 ( V_170 ) ;
F_93 ( V_81 ) ;
return - V_60 ;
}
static int
F_95 ( struct V_12 * V_13 )
{
struct V_169 * V_209 ;
int V_210 ;
V_209 = F_96 ( V_13 -> V_3 . V_18 . V_176 ,
F_97 ( & V_13 -> V_211 . V_212 ) ) ;
V_210 = F_82 ( & V_13 -> V_3 . V_18 ) ;
if ( V_210 )
return V_210 ;
if ( V_209 )
F_98 ( V_209 , V_213 ) ;
return 0 ;
}
void F_21 ( struct V_12 * V_13 ,
T_1 V_51 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_214 = V_51 ;
T_1 V_215 ;
if ( ! V_214 )
return;
F_99 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_7 ( V_215 , & V_17 -> V_216 ) ;
F_7 ( V_217 , & V_17 -> V_20 ) ;
F_8 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_100 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_51 = V_53 |
V_218 |
V_219 |
V_220 |
V_221 ;
V_15 -> V_222 ++ ;
F_101 ( & V_15 -> V_223 ) ;
F_102 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_224 = F_103 ( V_17 -> V_37 ) ;
V_17 -> V_225 = 0 ;
F_7 ( V_19 , & V_17 -> V_20 ) ;
F_64 ( V_17 ) ;
F_8 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_129 =
V_17 -> V_90 . V_226 ;
V_13 -> V_41 . V_42 . V_227 = true ;
V_51 |= F_104 ( V_13 ) ;
if ( F_82 ( V_17 ) ) {
F_105 ( V_13 ) ;
return - V_60 ;
}
F_106 ( V_15 , V_13 ) ;
F_107 ( V_13 , V_51 ) ;
F_108 ( V_13 -> V_228 ) ;
return 0 ;
}
void F_105 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_169 * V_170 ;
F_109 ( V_13 -> V_228 ) ;
F_110 ( V_13 ) ;
F_111 ( V_13 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_227 = false ;
F_65 ( V_229 , & V_13 -> V_230 ) ;
F_107 ( V_13 , V_218 ) ;
V_170 = F_96 ( V_17 -> V_176 ,
F_97 ( & V_13 -> V_211 . V_212 ) ) ;
F_112 ( V_17 -> V_176 , NULL ) ;
F_98 ( V_170 , V_213 ) ;
V_15 -> V_231 -= F_113 ( & V_17 -> V_232 . V_233 ) ;
F_114 ( & V_17 -> V_232 . V_233 ) ;
F_66 ( & V_13 -> V_3 . V_18 . V_163 ) ;
F_66 ( & V_13 -> V_3 . V_18 . V_138 ) ;
F_66 ( & V_13 -> V_3 . V_18 . V_234 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_216 = 0 ;
V_15 -> V_222 -- ;
F_115 ( & V_15 -> V_223 ) ;
F_102 ( V_15 ) ;
}
static bool
F_116 ( struct V_12 * V_13 ,
struct V_23 * V_235 , bool V_176 )
{
struct V_236 V_237 ;
struct V_238 V_239 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
enum V_112 V_113 = F_11 ( V_13 ) ;
int V_240 ;
T_1 V_241 ;
F_117 ( V_13 ) ;
V_241 = V_242 ;
switch ( V_13 -> V_41 . V_42 . V_43 . V_120 ) {
case V_121 :
V_241 |= V_243 ;
case V_244 :
V_241 |= V_245 ;
break;
default:
break;
}
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_240 = F_118 ( V_13 , V_235 , V_113 ,
V_241 , V_13 -> V_41 . V_186 ,
& V_239 ) ;
if ( V_240 < 0 )
return false ;
if ( V_240 )
return false ;
V_237 . V_43 = V_239 . V_43 ;
V_237 . V_196 = V_239 . V_196 ;
if ( ! F_119 ( V_13 -> V_15 -> V_21 . V_116 , & V_237 . V_43 ,
V_246 ) ) {
F_120 ( V_13 ,
L_2 ,
V_13 -> V_41 . V_186 ,
V_237 . V_43 . V_44 -> V_111 ,
V_237 . V_43 . V_120 ,
V_237 . V_43 . V_247 ,
V_237 . V_43 . V_248 ) ;
return false ;
}
V_240 = F_121 ( V_13 -> V_15 -> V_21 . V_116 ,
& V_237 . V_43 ,
V_249 ) ;
if ( V_240 < 0 )
return false ;
if ( V_240 > 0 )
return false ;
V_237 . V_250 = V_240 ;
if ( F_122 ( & V_237 . V_43 ,
& V_13 -> V_41 . V_42 . V_43 ) ) {
F_123 ( V_13 ,
L_3 ) ;
return true ;
}
F_123 ( V_13 ,
L_4 ,
V_237 . V_43 . V_44 -> V_111 ) ;
V_237 . V_203 = V_239 . V_251 & V_204 ;
if ( V_176 ) {
V_17 -> V_202 = V_239 . V_153 - 1 ;
if ( V_17 -> V_206 >= V_239 . V_206 )
return false ;
V_17 -> V_206 = V_239 . V_206 ;
}
if ( V_17 -> V_202 >= V_17 -> V_90 . V_154 )
return false ;
V_17 -> V_199 = V_252 ;
if ( F_124 ( V_13 -> V_15 -> V_21 . V_116 , V_13 -> V_228 ,
& V_237 ) < 0 )
return false ;
return true ;
}
static void
F_125 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_102 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_80 * V_253 ;
struct V_169 * V_170 ;
struct V_1 * V_140 ;
struct V_23 V_235 ;
T_4 V_254 ;
T_2 * V_82 ;
V_82 = V_2 -> V_3 . V_255 . V_256 ;
V_254 = ( T_2 * ) V_82 - ( T_2 * ) V_2 ;
if ( V_254 > V_102 )
return;
F_126 ( V_82 , V_102 - V_254 , false , & V_235 ) ;
if ( ! V_235 . V_29 )
return;
if ( ( ! F_33 ( V_2 -> V_185 , V_13 -> V_41 . V_186 ) &&
! F_127 ( V_2 -> V_185 ) ) ||
V_235 . V_257 != 0 )
return;
if ( V_235 . V_28 != 0 &&
( V_235 . V_28 != V_17 -> V_28 ||
memcmp ( V_235 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_49 () ;
V_170 = F_50 ( V_17 -> V_176 ) ;
if ( ! V_170 )
goto V_258;
V_253 = F_86 ( V_15 -> V_259 +
V_170 -> V_171 + V_170 -> V_172 ) ;
if ( ! V_253 )
goto V_258;
F_128 ( V_253 , V_15 -> V_259 ) ;
memcpy ( F_38 ( V_253 , V_170 -> V_171 ) , V_170 -> V_181 , V_170 -> V_171 ) ;
memcpy ( F_38 ( V_253 , V_170 -> V_172 ) , V_170 -> V_207 , V_170 -> V_172 ) ;
V_140 = (struct V_1 * ) V_253 -> V_11 ;
V_140 -> V_182 = F_69 ( V_183 |
V_260 ) ;
memcpy ( V_140 -> V_185 , V_2 -> V_68 , V_79 ) ;
F_129 ( V_253 ) -> V_156 |= V_261 ;
F_130 ( V_13 , V_253 ) ;
V_258:
F_52 () ;
}
static void F_131 ( struct V_12 * V_13 ,
T_5 V_262 ,
struct V_1 * V_2 ,
T_4 V_102 ,
struct V_263 * V_264 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_235 ;
struct V_107 * V_126 ;
T_4 V_254 ;
int V_265 ;
enum V_112 V_113 = V_264 -> V_113 ;
if ( V_262 == V_260 &&
! F_33 ( V_2 -> V_185 , V_13 -> V_41 . V_186 ) )
return;
V_254 = ( T_2 * ) V_2 -> V_3 . V_266 . V_256 - ( T_2 * ) V_2 ;
if ( V_254 > V_102 )
return;
F_126 ( V_2 -> V_3 . V_266 . V_256 , V_102 - V_254 ,
false , & V_235 ) ;
if ( ( ! V_235 . V_29 || ! V_235 . V_31 ) ||
( V_235 . V_267 && V_13 -> V_3 . V_18 . V_190 == V_268 ) ||
( ! V_235 . V_267 && V_13 -> V_3 . V_18 . V_190 != V_268 ) )
return;
if ( V_235 . V_269 )
V_265 = F_132 ( V_235 . V_269 [ 0 ] , V_113 ) ;
else
V_265 = V_264 -> V_265 ;
V_126 = F_133 ( V_15 -> V_21 . V_116 , V_265 ) ;
if ( ! V_126 || V_126 -> V_156 & V_246 )
return;
if ( F_9 ( V_13 , & V_235 ) )
F_134 ( V_13 , V_2 -> V_68 , & V_235 ) ;
if ( V_17 -> V_224 )
V_17 -> V_224 -> V_270 ( V_13 ,
V_262 , V_2 , & V_235 , V_264 ) ;
if ( V_17 -> V_199 != V_200 &&
! V_13 -> V_41 . V_271 )
F_116 ( V_13 , & V_235 , true ) ;
}
int F_135 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_173 * V_272 ;
int V_210 = 0 ;
int V_51 = 0 ;
V_17 -> V_199 = V_273 ;
V_17 -> V_202 = 0 ;
V_272 = F_50 ( V_17 -> V_174 ) ;
F_112 ( V_17 -> V_174 , NULL ) ;
if ( V_272 )
F_98 ( V_272 , V_213 ) ;
V_210 = F_95 ( V_13 ) ;
if ( V_210 )
return - V_108 ;
V_51 |= V_53 ;
F_123 ( V_13 , L_5 ,
V_13 -> V_41 . V_42 . V_43 . V_44 -> V_111 ) ;
return V_51 ;
}
int F_136 ( struct V_12 * V_13 ,
struct V_236 * V_274 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_173 * V_272 ;
int V_210 = 0 ;
V_272 = F_23 ( sizeof( * V_272 ) ,
V_77 ) ;
if ( ! V_272 )
return - V_60 ;
memcpy ( & V_272 -> V_194 , V_274 ,
sizeof( struct V_236 ) ) ;
F_94 ( V_17 -> V_174 , V_272 ) ;
V_210 = F_95 ( V_13 ) ;
if ( V_210 ) {
V_272 = F_50 ( V_17 -> V_174 ) ;
F_112 ( V_17 -> V_174 , NULL ) ;
F_98 ( V_272 , V_213 ) ;
return V_210 ;
}
return V_53 ;
}
static int F_137 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_102 )
{
struct V_1 * V_275 ;
struct V_80 * V_81 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_2 * V_82 = V_2 -> V_3 . V_4 . V_3 . V_276 . V_256 ;
T_4 V_277 ;
V_81 = F_86 ( V_15 -> V_259 + V_102 ) ;
if ( ! V_81 )
return - V_60 ;
F_128 ( V_81 , V_15 -> V_259 ) ;
V_275 = (struct V_1 * ) F_38 ( V_81 , V_102 ) ;
V_277 = ( V_102 < 42 ) ? 7 : 10 ;
* ( V_82 + V_277 ) -= 1 ;
* ( V_82 + V_277 + 1 ) &= ~ V_201 ;
memcpy ( V_275 , V_2 , V_102 ) ;
F_88 ( V_275 -> V_185 ) ;
memcpy ( V_275 -> V_68 , V_13 -> V_41 . V_186 , V_79 ) ;
memcpy ( V_275 -> V_187 , V_13 -> V_41 . V_186 , V_79 ) ;
F_130 ( V_13 , V_81 ) ;
return 0 ;
}
static void F_138 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_102 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_235 ;
T_5 V_206 ;
bool V_278 = true ;
T_4 V_254 ;
T_2 * V_82 ;
if ( V_2 -> V_3 . V_4 . V_3 . V_279 . V_6 !=
V_280 )
return;
V_82 = V_2 -> V_3 . V_4 . V_3 . V_276 . V_256 ;
V_254 = F_83 ( struct V_1 ,
V_3 . V_4 . V_3 . V_276 . V_256 ) ;
F_126 ( V_82 , V_102 - V_254 , false , & V_235 ) ;
V_17 -> V_202 = V_235 . V_281 -> V_282 ;
if ( ! -- V_17 -> V_202 )
V_278 = false ;
V_206 = F_139 ( V_235 . V_281 -> V_283 ) ;
if ( V_17 -> V_206 >= V_206 )
return;
V_17 -> V_206 = V_206 ;
if ( ! V_13 -> V_41 . V_271 &&
! F_116 ( V_13 , & V_235 , false ) ) {
F_123 ( V_13 , L_6 ) ;
return;
}
if ( V_278 ) {
if ( F_137 ( V_13 , V_2 , V_102 ) < 0 )
F_123 ( V_13 , L_7 ) ;
}
}
static void F_140 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_102 ,
struct V_263 * V_264 )
{
switch ( V_2 -> V_3 . V_4 . V_284 ) {
case V_285 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_286 . V_6 ) {
case V_287 :
case V_288 :
case V_289 :
F_141 ( V_13 , V_2 , V_102 , V_264 ) ;
break;
}
break;
case V_290 :
if ( F_1 ( V_2 ) )
F_142 ( V_13 , V_2 , V_102 ) ;
break;
case V_291 :
F_138 ( V_13 , V_2 , V_102 ) ;
break;
}
}
void F_143 ( struct V_12 * V_13 ,
struct V_80 * V_81 )
{
struct V_263 * V_264 ;
struct V_1 * V_2 ;
T_5 V_262 ;
F_144 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_258;
V_264 = F_145 ( V_81 ) ;
V_2 = (struct V_1 * ) V_81 -> V_11 ;
V_262 = F_139 ( V_2 -> V_182 ) & V_292 ;
switch ( V_262 ) {
case V_260 :
case V_184 :
F_131 ( V_13 , V_262 , V_2 , V_81 -> V_102 ,
V_264 ) ;
break;
case V_293 :
F_125 ( V_13 , V_2 , V_81 -> V_102 ) ;
break;
case V_294 :
F_140 ( V_13 , V_2 , V_81 -> V_102 , V_264 ) ;
break;
}
V_258:
F_146 ( V_13 ) ;
}
static void F_147 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_215 , V_51 = 0 ;
F_99 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_65 ( V_215 , & V_17 -> V_216 ) ;
V_51 |= F_148 ( V_215 ) ;
}
if ( V_13 -> V_41 . V_42 . V_227 &&
( V_51 & ( V_53 |
V_219 |
V_220 |
V_221 ) ) )
if ( F_95 ( V_13 ) )
return;
F_107 ( V_13 , V_51 ) ;
}
void F_149 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_144 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_28 )
goto V_258;
if ( V_17 -> V_295 &&
F_32 ( V_74 ,
V_17 -> V_296 + F_150 ( V_17 -> V_90 . V_297 ) ) )
F_151 ( V_13 ) ;
if ( F_152 ( V_19 , & V_17 -> V_20 ) )
F_74 ( V_13 ) ;
if ( F_152 ( V_135 , & V_17 -> V_20 ) )
F_79 ( V_13 ) ;
if ( F_152 ( V_298 , & V_17 -> V_20 ) )
F_153 ( V_13 ) ;
if ( F_152 ( V_217 , & V_17 -> V_20 ) )
F_147 ( V_13 ) ;
V_258:
F_146 ( V_13 ) ;
}
void F_154 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_299 [ V_79 ] = {} ;
F_155 ( & V_17 -> V_163 ,
F_6 ,
( unsigned long ) V_13 ) ;
V_17 -> V_52 = true ;
F_156 ( & V_17 -> V_300 , 0 ) ;
F_22 ( V_13 ) ;
V_17 -> V_296 = V_74 ;
V_17 -> V_301 = V_74 ;
V_17 -> V_199 = V_273 ;
if ( ! V_8 )
F_2 () ;
F_157 ( V_13 ) ;
F_155 ( & V_17 -> V_234 ,
F_62 ,
( unsigned long ) V_13 ) ;
F_155 ( & V_17 -> V_138 ,
F_63 ,
( unsigned long ) V_13 ) ;
F_158 ( & V_17 -> V_302 . V_67 ) ;
F_159 ( & V_17 -> V_232 . V_233 ) ;
F_160 ( & V_17 -> V_303 ) ;
F_160 ( & V_17 -> V_304 ) ;
F_112 ( V_17 -> V_176 , NULL ) ;
V_13 -> V_41 . V_42 . V_187 = V_299 ;
}
void F_161 ( struct V_12 * V_13 )
{
F_25 ( V_13 ) ;
F_162 ( V_13 ) ;
}
