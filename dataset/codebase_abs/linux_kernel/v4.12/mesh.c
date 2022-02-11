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
struct V_28 * V_29 ;
if ( ! ( V_17 -> V_30 == V_24 -> V_30 &&
memcmp ( V_17 -> V_31 , V_24 -> V_31 , V_24 -> V_30 ) == 0 &&
( V_17 -> V_32 == V_24 -> V_33 -> V_34 ) &&
( V_17 -> V_35 == V_24 -> V_33 -> V_36 ) &&
( V_17 -> V_37 == V_24 -> V_33 -> V_38 ) &&
( V_17 -> V_39 == V_24 -> V_33 -> V_40 ) &&
( V_17 -> V_41 == V_24 -> V_33 -> V_42 ) ) )
return false ;
V_29 = F_10 ( V_13 ) ;
if ( ! V_29 )
return false ;
F_11 ( V_13 , V_24 , V_29 -> V_43 ,
& V_25 ) ;
if ( V_13 -> V_44 . V_45 . V_25 != V_25 )
return false ;
F_12 ( & V_27 , V_13 -> V_44 . V_45 . V_46 . V_47 ,
V_48 ) ;
F_13 ( V_24 -> V_49 , & V_27 ) ;
F_14 ( V_24 -> V_50 , & V_27 ) ;
if ( ! F_15 ( & V_13 -> V_44 . V_45 . V_46 ,
& V_27 ) )
return false ;
return true ;
}
bool F_16 ( struct V_23 * V_24 )
{
return ( V_24 -> V_33 -> V_51 &
V_52 ) != 0 ;
}
T_1 F_17 ( struct V_12 * V_13 )
{
bool V_53 ;
T_1 V_54 = 0 ;
V_53 = F_18 ( V_13 ) ;
if ( V_53 != V_13 -> V_3 . V_18 . V_55 ) {
V_13 -> V_3 . V_18 . V_55 = V_53 ;
V_54 = V_56 ;
}
return V_54 ;
}
void F_19 ( struct V_57 * V_58 )
{
struct V_12 * V_13 = V_58 -> V_13 ;
T_1 V_54 = F_20 ( V_58 ) ;
if ( V_54 )
F_21 ( V_13 , V_54 ) ;
}
int F_22 ( struct V_12 * V_13 )
{
int V_59 ;
V_13 -> V_3 . V_18 . V_60 = F_23 ( sizeof( struct V_61 ) , V_62 ) ;
if ( ! V_13 -> V_3 . V_18 . V_60 )
return - V_63 ;
V_13 -> V_3 . V_18 . V_60 -> V_64 = V_65 - 1 ;
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ )
F_24 ( & V_13 -> V_3 . V_18 . V_60 -> V_66 [ V_59 ] ) ;
return 0 ;
}
void F_25 ( struct V_12 * V_13 )
{
struct V_61 * V_60 = V_13 -> V_3 . V_18 . V_60 ;
struct V_10 * V_67 ;
struct V_68 * V_69 ;
int V_59 ;
if ( ! V_13 -> V_3 . V_18 . V_60 )
return;
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
F_26 (p, n, &rmc->bucket[i], list) {
F_27 ( & V_67 -> V_70 ) ;
F_28 ( V_9 , V_67 ) ;
}
}
F_29 ( V_60 ) ;
V_13 -> V_3 . V_18 . V_60 = NULL ;
}
int F_30 ( struct V_12 * V_13 ,
const T_2 * V_71 , struct V_72 * V_73 )
{
struct V_61 * V_60 = V_13 -> V_3 . V_18 . V_60 ;
T_1 V_74 = 0 ;
int V_75 = 0 ;
T_2 V_76 ;
struct V_10 * V_67 ;
struct V_68 * V_69 ;
if ( ! V_60 )
return - 1 ;
memcpy ( & V_74 , & V_73 -> V_74 , sizeof( V_73 -> V_74 ) ) ;
V_76 = F_31 ( V_73 -> V_74 ) & V_60 -> V_64 ;
F_26 (p, n, &rmc->bucket[idx], list) {
++ V_75 ;
if ( F_32 ( V_77 , V_67 -> V_78 ) ||
V_75 == V_79 ) {
F_27 ( & V_67 -> V_70 ) ;
F_28 ( V_9 , V_67 ) ;
-- V_75 ;
} else if ( ( V_74 == V_67 -> V_74 ) && F_33 ( V_71 , V_67 -> V_71 ) )
return - 1 ;
}
V_67 = F_34 ( V_9 , V_80 ) ;
if ( ! V_67 )
return 0 ;
V_67 -> V_74 = V_74 ;
V_67 -> V_78 = V_77 + V_81 ;
memcpy ( V_67 -> V_71 , V_71 , V_82 ) ;
F_35 ( & V_67 -> V_70 , & V_60 -> V_66 [ V_76 ] ) ;
return 0 ;
}
int F_36 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_85 , V_86 ;
T_2 V_87 = sizeof( struct V_88 ) ;
if ( F_37 ( V_84 ) < 2 + V_87 )
return - V_63 ;
V_85 = F_38 ( V_84 , 2 + V_87 ) ;
* V_85 ++ = V_89 ;
* V_85 ++ = V_87 ;
V_17 -> V_90 = V_85 - V_84 -> V_11 ;
* V_85 ++ = V_17 -> V_32 ;
* V_85 ++ = V_17 -> V_35 ;
* V_85 ++ = V_17 -> V_37 ;
* V_85 ++ = V_17 -> V_39 ;
* V_85 ++ = V_17 -> V_41 ;
V_86 = F_39 ( & V_17 -> V_91 ) ;
V_86 = F_40 ( int , V_86 , V_92 ) ;
* V_85 ++ = V_86 << 1 ;
* V_85 = 0x00 ;
* V_85 |= V_17 -> V_93 . V_94 ?
V_95 : 0x00 ;
* V_85 |= V_17 -> V_55 ?
V_52 : 0x00 ;
* V_85 |= V_17 -> V_96 ?
V_97 : 0x00 ;
return 0 ;
}
int F_41 ( struct V_12 * V_13 , struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_85 ;
if ( F_37 ( V_84 ) < 2 + V_17 -> V_30 )
return - V_63 ;
V_85 = F_38 ( V_84 , 2 + V_17 -> V_30 ) ;
* V_85 ++ = V_98 ;
* V_85 ++ = V_17 -> V_30 ;
if ( V_17 -> V_30 )
memcpy ( V_85 , V_17 -> V_31 , V_17 -> V_30 ) ;
return 0 ;
}
static int F_42 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_85 ;
if ( V_17 -> V_99 == 0 &&
V_17 -> V_96 == 0 &&
V_17 -> V_100 == V_101 )
return 0 ;
if ( F_37 ( V_84 ) < 4 )
return - V_63 ;
V_85 = F_38 ( V_84 , 2 + 2 ) ;
* V_85 ++ = V_102 ;
* V_85 ++ = 2 ;
F_43 ( V_17 -> V_93 . V_103 , V_85 ) ;
return 0 ;
}
int F_44 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_104 , V_105 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_106 )
return 0 ;
V_104 = F_45 ( V_17 -> V_24 , V_17 -> V_106 , 0 ) ;
if ( V_104 < V_17 -> V_106 ) {
V_105 = V_17 -> V_106 - V_104 ;
V_11 = V_17 -> V_24 + V_104 ;
if ( F_37 ( V_84 ) < V_105 )
return - V_63 ;
memcpy ( F_38 ( V_84 , V_105 ) , V_11 , V_105 ) ;
}
return 0 ;
}
int F_46 ( struct V_12 * V_13 , struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_105 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_106 )
return 0 ;
V_11 = F_47 ( V_107 , V_17 -> V_24 , V_17 -> V_106 ) ;
if ( ! V_11 )
return 0 ;
V_105 = V_11 [ 1 ] + 2 ;
if ( F_37 ( V_84 ) < V_105 )
return - V_63 ;
memcpy ( F_38 ( V_84 , V_105 ) , V_11 , V_105 ) ;
return 0 ;
}
static int F_48 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_108 * V_109 ;
struct V_110 * V_47 ;
T_2 * V_85 ;
if ( F_37 ( V_84 ) < 3 )
return - V_63 ;
F_49 () ;
V_109 = F_50 ( V_13 -> V_44 . V_109 ) ;
if ( F_51 ( ! V_109 ) ) {
F_52 () ;
return - V_111 ;
}
V_47 = V_109 -> V_112 . V_47 ;
F_52 () ;
V_85 = F_38 ( V_84 , 2 + 1 ) ;
* V_85 ++ = V_113 ;
* V_85 ++ = 1 ;
* V_85 ++ = F_53 ( V_47 -> V_114 ) ;
return 0 ;
}
int F_54 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_28 * V_29 ;
T_2 * V_85 ;
V_29 = F_10 ( V_13 ) ;
if ( ! V_29 )
return - V_111 ;
if ( ! V_29 -> V_115 . V_116 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_118 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_119 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_120 )
return 0 ;
if ( F_37 ( V_84 ) < 2 + sizeof( struct V_121 ) )
return - V_63 ;
V_85 = F_38 ( V_84 , 2 + sizeof( struct V_121 ) ) ;
F_55 ( V_85 , & V_29 -> V_115 , V_29 -> V_115 . V_122 ) ;
return 0 ;
}
int F_56 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_108 * V_109 ;
struct V_110 * V_123 ;
struct V_28 * V_29 ;
struct V_124 * V_115 ;
T_2 * V_85 ;
F_49 () ;
V_109 = F_50 ( V_13 -> V_44 . V_109 ) ;
if ( F_51 ( ! V_109 ) ) {
F_52 () ;
return - V_111 ;
}
V_123 = V_109 -> V_112 . V_47 ;
F_52 () ;
V_29 = V_15 -> V_21 . V_125 -> V_126 [ V_123 -> V_43 ] ;
V_115 = & V_29 -> V_115 ;
if ( ! V_115 -> V_116 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_118 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_119 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_120 )
return 0 ;
if ( F_37 ( V_84 ) < 2 + sizeof( struct V_127 ) )
return - V_63 ;
V_85 = F_38 ( V_84 , 2 + sizeof( struct V_127 ) ) ;
F_57 ( V_85 , V_115 , & V_13 -> V_44 . V_45 . V_46 ,
V_13 -> V_44 . V_45 . V_128 ,
false ) ;
return 0 ;
}
int F_58 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_28 * V_29 ;
T_2 * V_85 ;
V_29 = F_10 ( V_13 ) ;
if ( ! V_29 )
return - V_111 ;
if ( ! V_29 -> V_129 . V_130 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_118 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_119 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_120 )
return 0 ;
if ( F_37 ( V_84 ) < 2 + sizeof( struct V_131 ) )
return - V_63 ;
V_85 = F_38 ( V_84 , 2 + sizeof( struct V_131 ) ) ;
F_59 ( V_85 , & V_29 -> V_129 , V_29 -> V_129 . V_122 ) ;
return 0 ;
}
int F_60 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_108 * V_109 ;
struct V_110 * V_123 ;
struct V_28 * V_29 ;
struct V_132 * V_129 ;
T_2 * V_85 ;
F_49 () ;
V_109 = F_50 ( V_13 -> V_44 . V_109 ) ;
if ( F_51 ( ! V_109 ) ) {
F_52 () ;
return - V_111 ;
}
V_123 = V_109 -> V_112 . V_47 ;
F_52 () ;
V_29 = V_15 -> V_21 . V_125 -> V_126 [ V_123 -> V_43 ] ;
V_129 = & V_29 -> V_129 ;
if ( ! V_129 -> V_130 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_118 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_119 ||
V_13 -> V_44 . V_45 . V_46 . V_117 == V_120 )
return 0 ;
if ( F_37 ( V_84 ) < 2 + sizeof( struct V_133 ) )
return - V_63 ;
V_85 = F_38 ( V_84 , 2 + sizeof( struct V_133 ) ) ;
F_61 ( V_85 , V_129 ,
& V_13 -> V_44 . V_45 . V_46 ) ;
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
F_7 ( V_134 , & V_17 -> V_20 ) ;
F_8 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_64 ( struct V_16 * V_17 )
{
if ( V_17 -> V_93 . V_135 > V_136 )
F_7 ( V_134 , & V_17 -> V_20 ) ;
else {
F_65 ( V_134 , & V_17 -> V_20 ) ;
F_66 ( & V_17 -> V_137 ) ;
}
}
int F_67 ( struct V_138 * V_139 , T_3 * V_140 ,
const T_2 * V_141 , const T_2 * V_142 )
{
if ( F_68 ( V_141 ) ) {
* V_140 |= F_69 ( V_143 ) ;
memcpy ( V_139 -> V_144 , V_141 , V_82 ) ;
memcpy ( V_139 -> V_145 , V_142 , V_82 ) ;
memcpy ( V_139 -> V_146 , V_142 , V_82 ) ;
return 24 ;
} else {
* V_140 |= F_69 ( V_143 | V_147 ) ;
F_70 ( V_139 -> V_144 ) ;
memcpy ( V_139 -> V_145 , V_142 , V_82 ) ;
memcpy ( V_139 -> V_146 , V_141 , V_82 ) ;
memcpy ( V_139 -> V_148 , V_142 , V_82 ) ;
return 30 ;
}
}
unsigned int F_71 ( struct V_12 * V_13 ,
struct V_72 * V_149 ,
const char * V_150 , const char * V_151 )
{
if ( F_51 ( ! V_150 && V_151 ) )
return 0 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_152 = V_13 -> V_3 . V_18 . V_93 . V_153 ;
F_72 ( F_73 ( V_13 -> V_3 . V_18 . V_154 ) , & V_149 -> V_74 ) ;
V_13 -> V_3 . V_18 . V_154 ++ ;
if ( V_150 && ! V_151 ) {
V_149 -> V_155 |= V_156 ;
memcpy ( V_149 -> V_157 , V_150 , V_82 ) ;
return 2 * V_82 ;
} else if ( V_150 && V_151 ) {
V_149 -> V_155 |= V_158 ;
memcpy ( V_149 -> V_157 , V_150 , V_82 ) ;
memcpy ( V_149 -> V_159 , V_151 , V_82 ) ;
return 3 * V_82 ;
}
return V_82 ;
}
static void F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_54 ;
if ( V_17 -> V_93 . V_160 > 0 )
F_75 ( V_13 , V_17 -> V_93 . V_160 * V_161 ) ;
F_76 ( V_13 ) ;
V_54 = F_17 ( V_13 ) ;
F_21 ( V_13 , V_54 ) ;
F_77 ( & V_17 -> V_162 ,
F_78 ( V_77 +
V_163 ) ) ;
}
static void F_79 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_164 ;
F_80 ( V_13 ) ;
if ( V_17 -> V_93 . V_135 == V_165 )
V_164 = V_17 -> V_93 . V_166 ;
else
V_164 = V_17 -> V_93 . V_167 ;
F_77 ( & V_17 -> V_137 ,
F_78 ( F_81 ( V_164 ) ) ) ;
}
static int
F_82 ( struct V_16 * V_17 )
{
struct V_168 * V_169 ;
int V_170 , V_171 ;
struct V_83 * V_84 ;
struct V_1 * V_2 ;
struct V_108 * V_109 ;
struct V_172 * V_173 ;
enum V_174 V_43 ;
T_2 * V_85 ;
struct V_12 * V_13 ;
int V_175 = F_83 ( struct V_1 , V_3 . V_176 ) +
sizeof( V_2 -> V_3 . V_176 ) ;
V_13 = F_84 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_49 () ;
V_109 = F_50 ( V_13 -> V_44 . V_109 ) ;
V_43 = V_109 -> V_112 . V_47 -> V_43 ;
F_52 () ;
V_170 = V_175 +
2 +
2 + sizeof( struct V_177 ) +
2 + sizeof( struct V_178 ) +
2 + 8 +
2 + 3 ;
V_171 = 2 + ( V_179 - 8 ) +
2 + sizeof( struct V_121 ) +
2 + sizeof( struct V_127 ) +
2 + V_17 -> V_30 +
2 + sizeof( struct V_88 ) +
2 + sizeof( T_3 ) +
2 + sizeof( struct V_131 ) +
2 + sizeof( struct V_133 ) +
V_17 -> V_106 ;
V_169 = F_85 ( sizeof( * V_169 ) + V_170 + V_171 , V_62 ) ;
V_84 = F_86 ( F_87 ( V_170 , V_171 ) ) ;
if ( ! V_169 || ! V_84 )
goto V_180;
V_169 -> V_181 = ( ( T_2 * ) V_169 ) + sizeof( * V_169 ) ;
V_2 = (struct V_1 * ) F_38 ( V_84 , V_175 ) ;
memset ( V_2 , 0 , V_175 ) ;
V_2 -> V_182 = F_69 ( V_183 |
V_184 ) ;
F_88 ( V_2 -> V_185 ) ;
memcpy ( V_2 -> V_71 , V_13 -> V_44 . V_186 , V_82 ) ;
memcpy ( V_2 -> V_187 , V_13 -> V_44 . V_186 , V_82 ) ;
F_89 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_176 . V_188 =
F_69 ( V_13 -> V_44 . V_45 . V_188 ) ;
V_2 -> V_3 . V_176 . V_189 |= F_69 (
V_13 -> V_3 . V_18 . V_190 ? V_191 : 0 ) ;
V_85 = F_38 ( V_84 , 2 ) ;
* V_85 ++ = V_192 ;
* V_85 ++ = 0x0 ;
F_49 () ;
V_173 = F_50 ( V_17 -> V_173 ) ;
if ( V_173 ) {
V_85 = F_38 ( V_84 , 13 ) ;
memset ( V_85 , 0 , 13 ) ;
* V_85 ++ = V_193 ;
* V_85 ++ = 3 ;
* V_85 ++ = 0x0 ;
* V_85 ++ = F_53 (
V_173 -> V_194 . V_46 . V_47 -> V_114 ) ;
V_169 -> V_195 = V_173 -> V_194 . V_196 ;
V_169 -> V_197 [ 0 ] = V_175 + 6 ;
* V_85 ++ = V_173 -> V_194 . V_196 ;
* V_85 ++ = V_198 ;
* V_85 ++ = 6 ;
if ( V_17 -> V_199 == V_200 ) {
* V_85 ++ = V_17 -> V_93 . V_153 ;
* V_85 |= V_201 ;
} else {
* V_85 ++ = V_17 -> V_202 ;
}
* V_85 ++ |= V_173 -> V_194 . V_203 ?
V_204 : 0x00 ;
F_43 ( V_205 , V_85 ) ;
V_85 += 2 ;
F_43 ( V_17 -> V_206 , V_85 ) ;
V_85 += 2 ;
}
F_52 () ;
if ( F_90 ( V_13 , V_84 , true , V_43 ) ||
F_48 ( V_13 , V_84 ) )
goto V_180;
V_169 -> V_170 = V_84 -> V_105 ;
memcpy ( V_169 -> V_181 , V_84 -> V_11 , V_169 -> V_170 ) ;
F_91 ( V_84 , 0 ) ;
V_169 -> V_207 = V_169 -> V_181 + V_169 -> V_170 ;
if ( F_92 ( V_13 , V_84 , true , V_43 ) ||
F_46 ( V_13 , V_84 ) ||
F_54 ( V_13 , V_84 ) ||
F_56 ( V_13 , V_84 ) ||
F_41 ( V_13 , V_84 ) ||
F_36 ( V_13 , V_84 ) ||
F_42 ( V_13 , V_84 ) ||
F_58 ( V_13 , V_84 ) ||
F_60 ( V_13 , V_84 ) ||
F_44 ( V_13 , V_84 ) )
goto V_180;
V_169 -> V_171 = V_84 -> V_105 ;
memcpy ( V_169 -> V_207 , V_84 -> V_11 , V_169 -> V_171 ) ;
V_169 -> V_208 = (struct V_88 * )
( V_169 -> V_207 + V_17 -> V_90 ) ;
F_93 ( V_84 ) ;
F_94 ( V_17 -> V_176 , V_169 ) ;
return 0 ;
V_180:
F_29 ( V_169 ) ;
F_93 ( V_84 ) ;
return - V_63 ;
}
static int
F_95 ( struct V_12 * V_13 )
{
struct V_168 * V_209 ;
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
T_1 V_54 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_214 = V_54 ;
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
T_1 V_54 = V_56 |
V_218 |
V_219 |
V_220 |
V_221 ;
V_15 -> V_222 ++ ;
F_101 ( & V_15 -> V_223 ) ;
F_102 ( V_15 ) ;
V_17 -> V_37 = 0 ;
V_17 -> V_224 = F_103 ( V_17 -> V_39 ) ;
V_17 -> V_225 = 0 ;
F_7 ( V_19 , & V_17 -> V_20 ) ;
F_64 ( V_17 ) ;
F_8 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_44 . V_45 . V_128 =
V_17 -> V_93 . V_226 ;
V_13 -> V_44 . V_45 . V_227 = true ;
V_54 |= F_104 ( V_13 ) ;
if ( F_82 ( V_17 ) ) {
F_105 ( V_13 ) ;
return - V_63 ;
}
F_106 ( V_15 , V_13 ) ;
F_107 ( V_13 , V_54 ) ;
F_108 ( V_13 -> V_228 ) ;
return 0 ;
}
void F_105 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_168 * V_169 ;
F_109 ( V_13 -> V_228 ) ;
F_110 ( V_13 ) ;
F_111 ( V_13 ) ;
V_17 -> V_30 = 0 ;
V_13 -> V_44 . V_45 . V_227 = false ;
F_65 ( V_229 , & V_13 -> V_230 ) ;
F_107 ( V_13 , V_218 ) ;
V_169 = F_96 ( V_17 -> V_176 ,
F_97 ( & V_13 -> V_211 . V_212 ) ) ;
F_112 ( V_17 -> V_176 , NULL ) ;
F_98 ( V_169 , V_213 ) ;
V_15 -> V_231 -= F_113 ( & V_17 -> V_232 . V_233 ) ;
F_114 ( & V_17 -> V_232 . V_233 ) ;
F_66 ( & V_13 -> V_3 . V_18 . V_162 ) ;
F_66 ( & V_13 -> V_3 . V_18 . V_137 ) ;
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
struct V_28 * V_29 ;
int V_240 ;
T_1 V_241 ;
F_117 ( V_13 ) ;
V_29 = F_10 ( V_13 ) ;
if ( ! V_29 )
return false ;
V_241 = V_242 ;
switch ( V_13 -> V_44 . V_45 . V_46 . V_117 ) {
case V_118 :
V_241 |= V_243 ;
case V_244 :
V_241 |= V_245 ;
break;
default:
break;
}
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_240 = F_118 ( V_13 , V_235 , V_29 -> V_43 ,
V_241 , V_13 -> V_44 . V_186 ,
& V_239 ) ;
if ( V_240 < 0 )
return false ;
if ( V_240 )
return false ;
V_237 . V_46 = V_239 . V_46 ;
V_237 . V_196 = V_239 . V_196 ;
if ( ! F_119 ( V_13 -> V_15 -> V_21 . V_125 , & V_237 . V_46 ,
V_246 ) ) {
F_120 ( V_13 ,
L_2 ,
V_13 -> V_44 . V_186 ,
V_237 . V_46 . V_47 -> V_114 ,
V_237 . V_46 . V_117 ,
V_237 . V_46 . V_247 ,
V_237 . V_46 . V_248 ) ;
return false ;
}
V_240 = F_121 ( V_13 -> V_15 -> V_21 . V_125 ,
& V_237 . V_46 ,
V_249 ) ;
if ( V_240 < 0 )
return false ;
if ( V_240 > 0 )
return false ;
V_237 . V_250 = V_240 ;
if ( F_122 ( & V_237 . V_46 ,
& V_13 -> V_44 . V_45 . V_46 ) ) {
F_123 ( V_13 ,
L_3 ) ;
return true ;
}
F_123 ( V_13 ,
L_4 ,
V_237 . V_46 . V_47 -> V_114 ) ;
V_237 . V_203 = V_239 . V_251 & V_204 ;
if ( V_176 ) {
V_17 -> V_202 = V_239 . V_152 - 1 ;
if ( V_17 -> V_206 >= V_239 . V_206 )
return false ;
V_17 -> V_206 = V_239 . V_206 ;
}
if ( V_17 -> V_202 >= V_17 -> V_93 . V_153 )
return false ;
V_17 -> V_199 = V_252 ;
if ( F_124 ( V_13 -> V_15 -> V_21 . V_125 , V_13 -> V_228 ,
& V_237 ) < 0 )
return false ;
return true ;
}
static void
F_125 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_105 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_83 * V_253 ;
struct V_168 * V_169 ;
struct V_1 * V_139 ;
struct V_23 V_235 ;
T_4 V_254 ;
T_2 * V_85 ;
V_85 = V_2 -> V_3 . V_255 . V_256 ;
V_254 = ( T_2 * ) V_85 - ( T_2 * ) V_2 ;
if ( V_254 > V_105 )
return;
F_126 ( V_85 , V_105 - V_254 , false , & V_235 ) ;
if ( ! V_235 . V_31 )
return;
if ( ( ! F_33 ( V_2 -> V_185 , V_13 -> V_44 . V_186 ) &&
! F_127 ( V_2 -> V_185 ) ) ||
V_235 . V_257 != 0 )
return;
if ( V_235 . V_30 != 0 &&
( V_235 . V_30 != V_17 -> V_30 ||
memcmp ( V_235 . V_31 , V_17 -> V_31 , V_17 -> V_30 ) ) )
return;
F_49 () ;
V_169 = F_50 ( V_17 -> V_176 ) ;
if ( ! V_169 )
goto V_258;
V_253 = F_86 ( V_15 -> V_259 +
V_169 -> V_170 + V_169 -> V_171 ) ;
if ( ! V_253 )
goto V_258;
F_128 ( V_253 , V_15 -> V_259 ) ;
memcpy ( F_38 ( V_253 , V_169 -> V_170 ) , V_169 -> V_181 , V_169 -> V_170 ) ;
memcpy ( F_38 ( V_253 , V_169 -> V_171 ) , V_169 -> V_207 , V_169 -> V_171 ) ;
V_139 = (struct V_1 * ) V_253 -> V_11 ;
V_139 -> V_182 = F_69 ( V_183 |
V_260 ) ;
memcpy ( V_139 -> V_185 , V_2 -> V_71 , V_82 ) ;
F_129 ( V_253 ) -> V_155 |= V_261 ;
F_130 ( V_13 , V_253 ) ;
V_258:
F_52 () ;
}
static void F_131 ( struct V_12 * V_13 ,
T_5 V_262 ,
struct V_1 * V_2 ,
T_4 V_105 ,
struct V_263 * V_264 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_235 ;
struct V_110 * V_123 ;
T_4 V_254 ;
int V_265 ;
enum V_174 V_43 = V_264 -> V_43 ;
if ( V_262 == V_260 &&
! F_33 ( V_2 -> V_185 , V_13 -> V_44 . V_186 ) )
return;
V_254 = ( T_2 * ) V_2 -> V_3 . V_266 . V_256 - ( T_2 * ) V_2 ;
if ( V_254 > V_105 )
return;
F_126 ( V_2 -> V_3 . V_266 . V_256 , V_105 - V_254 ,
false , & V_235 ) ;
if ( ( ! V_235 . V_31 || ! V_235 . V_33 ) ||
( V_235 . V_267 && V_13 -> V_3 . V_18 . V_190 == V_268 ) ||
( ! V_235 . V_267 && V_13 -> V_3 . V_18 . V_190 != V_268 ) )
return;
if ( V_235 . V_269 )
V_265 = F_132 ( V_235 . V_269 [ 0 ] , V_43 ) ;
else
V_265 = V_264 -> V_265 ;
V_123 = F_133 ( V_15 -> V_21 . V_125 , V_265 ) ;
if ( ! V_123 || V_123 -> V_155 & V_246 )
return;
if ( F_9 ( V_13 , & V_235 ) ) {
F_134 ( V_13 , L_5 ,
V_13 -> V_3 . V_18 . V_93 . V_270 , V_264 -> signal ) ;
if ( ! V_13 -> V_3 . V_18 . V_271 ||
V_13 -> V_3 . V_18 . V_93 . V_270 == 0 ||
V_13 -> V_3 . V_18 . V_93 . V_270 < V_264 -> signal )
F_135 ( V_13 , V_2 -> V_71 , & V_235 ) ;
}
if ( V_17 -> V_224 )
V_17 -> V_224 -> V_272 ( V_13 ,
V_262 , V_2 , & V_235 , V_264 ) ;
if ( V_17 -> V_199 != V_200 &&
! V_13 -> V_44 . V_273 )
F_116 ( V_13 , & V_235 , true ) ;
}
int F_136 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_172 * V_274 ;
int V_210 = 0 ;
int V_54 = 0 ;
V_17 -> V_199 = V_275 ;
V_17 -> V_202 = 0 ;
V_274 = F_50 ( V_17 -> V_173 ) ;
F_112 ( V_17 -> V_173 , NULL ) ;
if ( V_274 )
F_98 ( V_274 , V_213 ) ;
V_210 = F_95 ( V_13 ) ;
if ( V_210 )
return - V_111 ;
V_54 |= V_56 ;
F_123 ( V_13 , L_6 ,
V_13 -> V_44 . V_45 . V_46 . V_47 -> V_114 ) ;
return V_54 ;
}
int F_137 ( struct V_12 * V_13 ,
struct V_236 * V_276 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_172 * V_274 ;
int V_210 = 0 ;
V_274 = F_23 ( sizeof( * V_274 ) ,
V_80 ) ;
if ( ! V_274 )
return - V_63 ;
memcpy ( & V_274 -> V_194 , V_276 ,
sizeof( struct V_236 ) ) ;
F_94 ( V_17 -> V_173 , V_274 ) ;
V_210 = F_95 ( V_13 ) ;
if ( V_210 ) {
V_274 = F_50 ( V_17 -> V_173 ) ;
F_112 ( V_17 -> V_173 , NULL ) ;
F_98 ( V_274 , V_213 ) ;
return V_210 ;
}
return V_56 ;
}
static int F_138 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_105 )
{
struct V_1 * V_277 ;
struct V_83 * V_84 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_2 * V_85 = V_2 -> V_3 . V_4 . V_3 . V_278 . V_256 ;
T_4 V_279 ;
V_84 = F_86 ( V_15 -> V_259 + V_105 ) ;
if ( ! V_84 )
return - V_63 ;
F_128 ( V_84 , V_15 -> V_259 ) ;
V_277 = (struct V_1 * ) F_38 ( V_84 , V_105 ) ;
V_279 = ( V_105 < 42 ) ? 7 : 10 ;
* ( V_85 + V_279 ) -= 1 ;
* ( V_85 + V_279 + 1 ) &= ~ V_201 ;
memcpy ( V_277 , V_2 , V_105 ) ;
F_88 ( V_277 -> V_185 ) ;
memcpy ( V_277 -> V_71 , V_13 -> V_44 . V_186 , V_82 ) ;
memcpy ( V_277 -> V_187 , V_13 -> V_44 . V_186 , V_82 ) ;
F_130 ( V_13 , V_84 ) ;
return 0 ;
}
static void F_139 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_105 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_235 ;
T_5 V_206 ;
bool V_280 = true ;
T_4 V_254 ;
T_2 * V_85 ;
if ( V_2 -> V_3 . V_4 . V_3 . V_281 . V_6 !=
V_282 )
return;
V_85 = V_2 -> V_3 . V_4 . V_3 . V_278 . V_256 ;
V_254 = F_83 ( struct V_1 ,
V_3 . V_4 . V_3 . V_278 . V_256 ) ;
F_126 ( V_85 , V_105 - V_254 , false , & V_235 ) ;
V_17 -> V_202 = V_235 . V_283 -> V_284 ;
if ( ! -- V_17 -> V_202 )
V_280 = false ;
V_206 = F_140 ( V_235 . V_283 -> V_285 ) ;
if ( V_17 -> V_206 >= V_206 )
return;
V_17 -> V_206 = V_206 ;
if ( ! V_13 -> V_44 . V_273 &&
! F_116 ( V_13 , & V_235 , false ) ) {
F_123 ( V_13 , L_7 ) ;
return;
}
if ( V_280 ) {
if ( F_138 ( V_13 , V_2 , V_105 ) < 0 )
F_123 ( V_13 , L_8 ) ;
}
}
static void F_141 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_105 ,
struct V_263 * V_264 )
{
switch ( V_2 -> V_3 . V_4 . V_286 ) {
case V_287 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_288 . V_6 ) {
case V_289 :
case V_290 :
case V_291 :
F_142 ( V_13 , V_2 , V_105 , V_264 ) ;
break;
}
break;
case V_292 :
if ( F_1 ( V_2 ) )
F_143 ( V_13 , V_2 , V_105 ) ;
break;
case V_293 :
F_139 ( V_13 , V_2 , V_105 ) ;
break;
}
}
void F_144 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_263 * V_264 ;
struct V_1 * V_2 ;
T_5 V_262 ;
F_145 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_30 )
goto V_258;
V_264 = F_146 ( V_84 ) ;
V_2 = (struct V_1 * ) V_84 -> V_11 ;
V_262 = F_140 ( V_2 -> V_182 ) & V_294 ;
switch ( V_262 ) {
case V_260 :
case V_184 :
F_131 ( V_13 , V_262 , V_2 , V_84 -> V_105 ,
V_264 ) ;
break;
case V_295 :
F_125 ( V_13 , V_2 , V_84 -> V_105 ) ;
break;
case V_296 :
F_141 ( V_13 , V_2 , V_84 -> V_105 , V_264 ) ;
break;
}
V_258:
F_147 ( V_13 ) ;
}
static void F_148 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_215 , V_54 = 0 ;
F_99 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_65 ( V_215 , & V_17 -> V_216 ) ;
V_54 |= F_149 ( V_215 ) ;
}
if ( V_13 -> V_44 . V_45 . V_227 &&
( V_54 & ( V_56 |
V_219 |
V_220 |
V_221 ) ) )
if ( F_95 ( V_13 ) )
return;
F_107 ( V_13 , V_54 ) ;
}
void F_150 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_145 ( V_13 ) ;
if ( ! V_13 -> V_3 . V_18 . V_30 )
goto V_258;
if ( V_17 -> V_297 &&
F_32 ( V_77 ,
V_17 -> V_298 + F_151 ( V_17 -> V_93 . V_299 ) ) )
F_152 ( V_13 ) ;
if ( F_153 ( V_19 , & V_17 -> V_20 ) )
F_74 ( V_13 ) ;
if ( F_153 ( V_134 , & V_17 -> V_20 ) )
F_79 ( V_13 ) ;
if ( F_153 ( V_300 , & V_17 -> V_20 ) )
F_154 ( V_13 ) ;
if ( F_153 ( V_217 , & V_17 -> V_20 ) )
F_148 ( V_13 ) ;
V_258:
F_147 ( V_13 ) ;
}
void F_155 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_301 [ V_82 ] = {} ;
F_156 ( & V_17 -> V_162 ,
F_6 ,
( unsigned long ) V_13 ) ;
V_17 -> V_55 = true ;
F_157 ( & V_17 -> V_302 , 0 ) ;
F_22 ( V_13 ) ;
V_17 -> V_298 = V_77 ;
V_17 -> V_303 = V_77 ;
V_17 -> V_199 = V_275 ;
if ( ! V_8 )
F_2 () ;
F_158 ( V_13 ) ;
F_156 ( & V_17 -> V_234 ,
F_62 ,
( unsigned long ) V_13 ) ;
F_156 ( & V_17 -> V_137 ,
F_63 ,
( unsigned long ) V_13 ) ;
F_159 ( & V_17 -> V_304 . V_70 ) ;
F_160 ( & V_17 -> V_232 . V_233 ) ;
F_161 ( & V_17 -> V_305 ) ;
F_161 ( & V_17 -> V_306 ) ;
F_112 ( V_17 -> V_176 , NULL ) ;
V_13 -> V_44 . V_45 . V_187 = V_301 ;
}
void F_162 ( struct V_12 * V_13 )
{
F_25 ( V_13 ) ;
F_163 ( V_13 ) ;
}
