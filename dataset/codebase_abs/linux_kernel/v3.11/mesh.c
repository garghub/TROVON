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
struct V_14 * V_15 = V_13 -> V_15 ;
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
F_12 ( V_15 , V_24 , F_13 ( V_13 ) ,
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
* V_81 = V_88 ;
* V_81 |= V_17 -> V_50 ?
V_47 : 0x00 ;
* V_81 |= V_17 -> V_89 ?
V_90 : 0x00 ;
* V_81 ++ |= V_17 -> V_91 ?
V_92 : 0x00 ;
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
* V_81 ++ = V_93 ;
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
if ( V_17 -> V_94 == 0 &&
V_17 -> V_89 == 0 &&
V_17 -> V_95 == V_96 )
return 0 ;
if ( F_38 ( V_80 ) < 4 )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + 2 ) ;
* V_81 ++ = V_97 ;
* V_81 ++ = 2 ;
F_44 ( V_17 -> V_98 . V_99 , V_81 ) ;
return 0 ;
}
int F_45 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_100 , V_101 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_102 )
return 0 ;
V_100 = F_46 ( V_17 -> V_24 , V_17 -> V_102 , 0 ) ;
if ( V_100 ) {
V_101 = V_17 -> V_102 - V_100 ;
V_11 = V_17 -> V_24 + V_100 ;
if ( F_38 ( V_80 ) < V_101 )
return - V_60 ;
memcpy ( F_39 ( V_80 , V_101 ) , V_11 , V_101 ) ;
}
return 0 ;
}
int F_47 ( struct V_12 * V_13 , struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_101 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_102 )
return 0 ;
V_11 = V_17 -> V_24 ;
while ( V_11 < V_17 -> V_24 + V_17 -> V_102 ) {
if ( * V_11 == V_103 ) {
V_101 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_101 ) {
if ( F_38 ( V_80 ) < V_101 )
return - V_60 ;
memcpy ( F_39 ( V_80 , V_101 ) , V_11 , V_101 ) ;
}
return 0 ;
}
static int F_48 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_104 * V_105 ;
struct V_106 * V_44 ;
T_2 * V_81 ;
if ( F_38 ( V_80 ) < 3 )
return - V_60 ;
F_49 () ;
V_105 = F_50 ( V_13 -> V_41 . V_105 ) ;
if ( F_51 ( ! V_105 ) ) {
F_52 () ;
return - V_107 ;
}
V_44 = V_105 -> V_108 . V_44 ;
F_52 () ;
V_81 = F_39 ( V_80 , 2 + 1 ) ;
* V_81 ++ = V_109 ;
* V_81 ++ = 1 ;
* V_81 ++ = F_53 ( V_44 -> V_110 ) ;
return 0 ;
}
int F_54 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_111 V_112 = F_13 ( V_13 ) ;
struct V_113 * V_114 ;
T_2 * V_81 ;
V_114 = V_15 -> V_21 . V_115 -> V_116 [ V_112 ] ;
if ( ! V_114 -> V_117 . V_118 ||
V_13 -> V_41 . V_42 . V_43 . V_119 == V_120 ||
V_13 -> V_41 . V_42 . V_43 . V_119 == V_121 ||
V_13 -> V_41 . V_42 . V_43 . V_119 == V_122 )
return 0 ;
if ( F_38 ( V_80 ) < 2 + sizeof( struct V_123 ) )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + sizeof( struct V_123 ) ) ;
F_55 ( V_81 , & V_114 -> V_117 , V_114 -> V_117 . V_124 ) ;
return 0 ;
}
int F_56 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_104 * V_105 ;
struct V_106 * V_125 ;
enum V_126 V_127 =
F_57 ( & V_13 -> V_41 . V_42 . V_43 ) ;
struct V_113 * V_114 ;
struct V_128 * V_117 ;
T_2 * V_81 ;
F_49 () ;
V_105 = F_50 ( V_13 -> V_41 . V_105 ) ;
if ( F_51 ( ! V_105 ) ) {
F_52 () ;
return - V_107 ;
}
V_125 = V_105 -> V_108 . V_44 ;
F_52 () ;
V_114 = V_15 -> V_21 . V_115 -> V_116 [ V_125 -> V_112 ] ;
V_117 = & V_114 -> V_117 ;
if ( ! V_117 -> V_118 || V_127 == V_129 )
return 0 ;
if ( F_38 ( V_80 ) < 2 + sizeof( struct V_130 ) )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + sizeof( struct V_130 ) ) ;
F_58 ( V_81 , V_117 , & V_13 -> V_41 . V_42 . V_43 ,
V_13 -> V_41 . V_42 . V_131 ) ;
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
F_9 ( V_132 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_61 ( struct V_16 * V_17 )
{
if ( V_17 -> V_98 . V_133 > V_134 )
F_9 ( V_132 , & V_17 -> V_20 ) ;
else {
F_62 ( V_132 , & V_17 -> V_20 ) ;
F_21 ( & V_17 -> V_135 ) ;
}
}
int F_63 ( struct V_136 * V_137 , T_3 * V_138 ,
const T_2 * V_139 , const T_2 * V_140 )
{
if ( F_64 ( V_139 ) ) {
* V_138 |= F_65 ( V_141 ) ;
memcpy ( V_137 -> V_142 , V_139 , V_78 ) ;
memcpy ( V_137 -> V_143 , V_140 , V_78 ) ;
memcpy ( V_137 -> V_144 , V_140 , V_78 ) ;
return 24 ;
} else {
* V_138 |= F_65 ( V_141 | V_145 ) ;
memset ( V_137 -> V_142 , 0 , V_78 ) ;
memcpy ( V_137 -> V_143 , V_140 , V_78 ) ;
memcpy ( V_137 -> V_144 , V_139 , V_78 ) ;
memcpy ( V_137 -> V_146 , V_140 , V_78 ) ;
return 30 ;
}
}
int F_66 ( struct V_12 * V_13 ,
struct V_68 * V_147 ,
const char * V_148 , const char * V_149 )
{
if ( F_51 ( ! V_148 && V_149 ) )
return 0 ;
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
V_147 -> V_150 = V_13 -> V_3 . V_18 . V_98 . V_151 ;
F_67 ( F_68 ( V_13 -> V_3 . V_18 . V_152 ) , & V_147 -> V_70 ) ;
V_13 -> V_3 . V_18 . V_152 ++ ;
if ( V_148 && ! V_149 ) {
V_147 -> V_153 |= V_154 ;
memcpy ( V_147 -> V_155 , V_148 , V_78 ) ;
return 2 * V_78 ;
} else if ( V_148 && V_149 ) {
V_147 -> V_153 |= V_156 ;
memcpy ( V_147 -> V_155 , V_148 , V_78 ) ;
memcpy ( V_147 -> V_157 , V_149 , V_78 ) ;
return 3 * V_78 ;
}
return V_78 ;
}
static void F_69 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_49 ;
F_70 ( V_13 , V_17 -> V_98 . V_158 * V_159 ) ;
F_71 ( V_13 ) ;
V_49 = F_17 ( V_13 ) ;
F_22 ( V_13 , V_49 ) ;
F_72 ( & V_17 -> V_160 ,
F_73 ( V_73 +
V_161 ) ) ;
}
static void F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_162 ;
F_75 ( V_13 ) ;
if ( V_17 -> V_98 . V_133 == V_163 )
V_162 = V_17 -> V_98 . V_164 ;
else
V_162 = V_17 -> V_98 . V_165 ;
F_72 ( & V_17 -> V_135 ,
F_73 ( F_76 ( V_162 ) ) ) ;
}
static int
F_77 ( struct V_16 * V_17 )
{
struct V_166 * V_167 ;
int V_168 , V_169 ;
struct V_79 * V_80 ;
struct V_1 * V_2 ;
struct V_104 * V_105 ;
enum V_111 V_112 ;
T_2 * V_81 ;
struct V_12 * V_13 ;
int V_170 = F_78 ( struct V_1 , V_3 . V_171 ) +
sizeof( V_2 -> V_3 . V_171 ) ;
V_13 = F_79 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_49 () ;
V_105 = F_50 ( V_13 -> V_41 . V_105 ) ;
V_112 = V_105 -> V_108 . V_44 -> V_112 ;
F_52 () ;
V_168 = V_170 +
2 +
2 + 8 +
2 + 3 ;
V_169 = 2 + ( V_172 - 8 ) +
2 + sizeof( struct V_123 ) +
2 + sizeof( struct V_130 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_84 ) +
2 + sizeof( T_3 ) +
V_17 -> V_102 ;
V_167 = F_80 ( sizeof( * V_167 ) + V_168 + V_169 , V_59 ) ;
V_80 = F_81 ( F_82 ( V_168 , V_169 ) ) ;
if ( ! V_167 || ! V_80 )
goto V_173;
V_167 -> V_174 = ( ( T_2 * ) V_167 ) + sizeof( * V_167 ) ;
V_2 = (struct V_1 * ) F_39 ( V_80 , V_170 ) ;
memset ( V_2 , 0 , V_170 ) ;
V_2 -> V_175 = F_65 ( V_176 |
V_177 ) ;
F_83 ( V_2 -> V_178 ) ;
memcpy ( V_2 -> V_67 , V_13 -> V_41 . V_179 , V_78 ) ;
memcpy ( V_2 -> V_180 , V_13 -> V_41 . V_179 , V_78 ) ;
F_84 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_171 . V_181 =
F_65 ( V_13 -> V_41 . V_42 . V_181 ) ;
V_2 -> V_3 . V_171 . V_182 |= F_65 (
V_13 -> V_3 . V_18 . V_183 ? V_184 : 0 ) ;
V_81 = F_39 ( V_80 , 2 ) ;
* V_81 ++ = V_185 ;
* V_81 ++ = 0x0 ;
if ( F_85 ( V_13 , V_80 , true , V_112 ) ||
F_48 ( V_13 , V_80 ) )
goto V_173;
V_167 -> V_168 = V_80 -> V_101 ;
memcpy ( V_167 -> V_174 , V_80 -> V_11 , V_167 -> V_168 ) ;
F_86 ( V_80 , 0 ) ;
V_167 -> V_186 = V_167 -> V_174 + V_167 -> V_168 ;
if ( F_87 ( V_13 , V_80 , true , V_112 ) ||
F_47 ( V_13 , V_80 ) ||
F_54 ( V_13 , V_80 ) ||
F_56 ( V_13 , V_80 ) ||
F_42 ( V_13 , V_80 ) ||
F_37 ( V_13 , V_80 ) ||
F_43 ( V_13 , V_80 ) ||
F_45 ( V_13 , V_80 ) )
goto V_173;
V_167 -> V_169 = V_80 -> V_101 ;
memcpy ( V_167 -> V_186 , V_80 -> V_11 , V_167 -> V_169 ) ;
F_88 ( V_80 ) ;
F_89 ( V_17 -> V_171 , V_167 ) ;
return 0 ;
V_173:
F_30 ( V_167 ) ;
F_88 ( V_80 ) ;
return - V_60 ;
}
static int
F_90 ( struct V_12 * V_13 )
{
struct V_166 * V_187 ;
int V_188 ;
V_187 = F_91 ( V_13 -> V_3 . V_18 . V_171 ,
F_92 ( & V_13 -> V_189 . V_190 ) ) ;
V_188 = F_77 ( & V_13 -> V_3 . V_18 ) ;
if ( V_188 )
return V_188 ;
if ( V_187 )
F_93 ( V_187 , V_191 ) ;
return 0 ;
}
void F_22 ( struct V_12 * V_13 ,
T_1 V_49 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
unsigned long V_192 = V_49 ;
T_1 V_193 ;
if ( ! V_192 )
return;
F_94 (bit, &bits, sizeof(changed) * BITS_PER_BYTE)
F_9 ( V_193 , & V_17 -> V_194 ) ;
F_9 ( V_195 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
int F_95 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_49 = V_51 |
V_196 |
V_197 |
V_198 |
V_199 ;
V_15 -> V_200 ++ ;
F_96 ( & V_15 -> V_201 ) ;
F_97 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_202 = F_98 ( V_17 -> V_37 ) ;
V_17 -> V_91 = false ;
V_17 -> V_203 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_61 ( V_17 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_131 =
V_17 -> V_98 . V_204 ;
V_13 -> V_41 . V_42 . V_205 = true ;
V_49 |= F_99 ( V_13 ) ;
if ( F_77 ( V_17 ) ) {
F_100 ( V_13 ) ;
return - V_60 ;
}
F_101 ( V_13 , V_49 ) ;
F_102 ( V_13 -> V_206 ) ;
return 0 ;
}
void F_100 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_166 * V_167 ;
F_103 ( V_13 -> V_206 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_205 = false ;
F_62 ( V_207 , & V_13 -> V_208 ) ;
F_101 ( V_13 , V_196 ) ;
V_167 = F_91 ( V_17 -> V_171 ,
F_92 ( & V_13 -> V_189 . V_190 ) ) ;
F_89 ( V_17 -> V_171 , NULL ) ;
F_93 ( V_167 , V_191 ) ;
F_104 ( V_13 ) ;
F_105 ( V_13 ) ;
V_15 -> V_209 -= F_106 ( & V_17 -> V_210 . V_211 ) ;
F_107 ( & V_17 -> V_210 . V_211 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_160 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_135 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_212 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_194 = 0 ;
V_15 -> V_200 -- ;
F_108 ( & V_15 -> V_201 ) ;
F_97 ( V_15 ) ;
}
static void
F_109 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_101 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_79 * V_213 ;
struct V_166 * V_167 ;
struct V_1 * V_137 ;
struct V_23 V_214 ;
T_4 V_215 ;
T_2 * V_81 ;
V_81 = V_2 -> V_3 . V_216 . V_217 ;
V_215 = ( T_2 * ) V_81 - ( T_2 * ) V_2 ;
if ( V_215 > V_101 )
return;
F_110 ( V_81 , V_101 - V_215 , false , & V_214 ) ;
if ( ( ! F_34 ( V_2 -> V_178 , V_13 -> V_41 . V_179 ) &&
! F_111 ( V_2 -> V_178 ) ) ||
V_214 . V_218 != 0 )
return;
if ( V_214 . V_28 != 0 &&
( V_214 . V_28 != V_17 -> V_28 ||
memcmp ( V_214 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_49 () ;
V_167 = F_50 ( V_17 -> V_171 ) ;
if ( ! V_167 )
goto V_219;
V_213 = F_81 ( V_15 -> V_220 +
V_167 -> V_168 + V_167 -> V_169 ) ;
if ( ! V_213 )
goto V_219;
F_112 ( V_213 , V_15 -> V_220 ) ;
memcpy ( F_39 ( V_213 , V_167 -> V_168 ) , V_167 -> V_174 , V_167 -> V_168 ) ;
memcpy ( F_39 ( V_213 , V_167 -> V_169 ) , V_167 -> V_186 , V_167 -> V_169 ) ;
V_137 = (struct V_1 * ) V_213 -> V_11 ;
V_137 -> V_175 = F_65 ( V_176 |
V_221 ) ;
memcpy ( V_137 -> V_178 , V_2 -> V_67 , V_78 ) ;
F_113 ( V_213 ) -> V_153 |= V_222 ;
F_114 ( V_13 , V_213 ) ;
V_219:
F_52 () ;
}
static void F_115 ( struct V_12 * V_13 ,
T_5 V_223 ,
struct V_1 * V_2 ,
T_4 V_101 ,
struct V_224 * V_225 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_214 ;
struct V_106 * V_125 ;
T_4 V_215 ;
int V_226 ;
enum V_111 V_112 = V_225 -> V_112 ;
if ( V_223 == V_221 &&
! F_34 ( V_2 -> V_178 , V_13 -> V_41 . V_179 ) )
return;
V_215 = ( T_2 * ) V_2 -> V_3 . V_227 . V_217 - ( T_2 * ) V_2 ;
if ( V_215 > V_101 )
return;
F_110 ( V_2 -> V_3 . V_227 . V_217 , V_101 - V_215 ,
false , & V_214 ) ;
if ( ( ! V_214 . V_29 || ! V_214 . V_31 ) ||
( V_214 . V_228 && V_13 -> V_3 . V_18 . V_183 == V_229 ) ||
( ! V_214 . V_228 && V_13 -> V_3 . V_18 . V_183 != V_229 ) )
return;
if ( V_214 . V_230 )
V_226 = F_116 ( V_214 . V_230 [ 0 ] , V_112 ) ;
else
V_226 = V_225 -> V_226 ;
V_125 = F_117 ( V_15 -> V_21 . V_115 , V_226 ) ;
if ( ! V_125 || V_125 -> V_153 & V_231 )
return;
if ( F_11 ( V_13 , & V_214 ) )
F_118 ( V_13 , V_2 -> V_67 , & V_214 ) ;
if ( V_17 -> V_202 )
V_17 -> V_202 -> V_232 ( V_13 ,
V_223 , V_2 , & V_214 , V_225 ) ;
}
static void F_119 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_101 ,
struct V_224 * V_225 )
{
switch ( V_2 -> V_3 . V_4 . V_233 ) {
case V_234 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_235 . V_6 ) {
case V_236 :
case V_237 :
case V_238 :
F_120 ( V_13 , V_2 , V_101 , V_225 ) ;
break;
}
break;
case V_239 :
if ( F_1 ( V_2 ) )
F_121 ( V_13 , V_2 , V_101 ) ;
break;
}
}
void F_122 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_224 * V_225 ;
struct V_1 * V_2 ;
T_5 V_223 ;
F_123 ( V_13 ) ;
if ( ! V_13 -> V_189 . V_28 )
goto V_219;
V_225 = F_124 ( V_80 ) ;
V_2 = (struct V_1 * ) V_80 -> V_11 ;
V_223 = F_125 ( V_2 -> V_175 ) & V_240 ;
switch ( V_223 ) {
case V_221 :
case V_177 :
F_115 ( V_13 , V_223 , V_2 , V_80 -> V_101 ,
V_225 ) ;
break;
case V_241 :
F_109 ( V_13 , V_2 , V_80 -> V_101 ) ;
break;
case V_242 :
F_119 ( V_13 , V_2 , V_80 -> V_101 , V_225 ) ;
break;
}
V_219:
F_126 ( V_13 ) ;
}
static void F_127 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_193 , V_49 = 0 ;
F_94 (bit, &ifmsh->mbss_changed,
sizeof(changed) * BITS_PER_BYTE) {
F_62 ( V_193 , & V_17 -> V_194 ) ;
V_49 |= F_128 ( V_193 ) ;
}
if ( V_13 -> V_41 . V_42 . V_205 &&
( V_49 & ( V_51 |
V_197 |
V_198 |
V_199 ) ) )
if ( F_90 ( V_13 ) )
return;
F_101 ( V_13 , V_49 ) ;
}
void F_129 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_123 ( V_13 ) ;
if ( ! V_13 -> V_189 . V_28 )
goto V_219;
if ( V_17 -> V_243 &&
F_33 ( V_73 ,
V_17 -> V_244 + F_130 ( V_17 -> V_98 . V_245 ) ) )
F_131 ( V_13 ) ;
if ( F_132 ( V_246 , & V_17 -> V_20 ) )
F_133 () ;
if ( F_132 ( V_247 , & V_17 -> V_20 ) )
F_134 () ;
if ( F_132 ( V_19 , & V_17 -> V_20 ) )
F_69 ( V_13 ) ;
if ( F_132 ( V_132 , & V_17 -> V_20 ) )
F_74 ( V_13 ) ;
if ( F_132 ( V_248 , & V_17 -> V_20 ) )
F_135 ( V_13 ) ;
if ( F_132 ( V_195 , & V_17 -> V_20 ) )
F_127 ( V_13 ) ;
V_219:
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
static T_2 V_249 [ V_78 ] = {} ;
F_141 ( & V_17 -> V_160 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_50 = true ;
V_17 -> V_250 = 0 ;
V_17 -> V_251 = 0 ;
V_17 -> V_252 = 0 ;
F_142 ( & V_17 -> V_253 , 0 ) ;
F_23 ( V_13 ) ;
V_17 -> V_244 = V_73 ;
V_17 -> V_254 = V_73 ;
if ( ! V_8 )
F_2 () ;
F_141 ( & V_17 -> V_212 ,
F_59 ,
( unsigned long ) V_13 ) ;
F_141 ( & V_17 -> V_135 ,
F_60 ,
( unsigned long ) V_13 ) ;
F_25 ( & V_17 -> V_255 . V_66 ) ;
F_143 ( & V_17 -> V_210 . V_211 ) ;
F_144 ( & V_17 -> V_256 ) ;
F_144 ( & V_17 -> V_257 ) ;
F_145 ( V_17 -> V_171 , NULL ) ;
V_13 -> V_41 . V_42 . V_180 = V_249 ;
}
