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
V_82 = ( V_82 > 15 ) ? 15 : V_82 ;
* V_81 ++ = V_82 << 1 ;
* V_81 = V_87 ;
* V_81 |= V_17 -> V_50 ?
V_47 : 0x00 ;
* V_81 |= V_17 -> V_88 ?
V_89 : 0x00 ;
* V_81 ++ |= V_17 -> V_90 ?
V_91 : 0x00 ;
* V_81 ++ = 0x00 ;
return 0 ;
}
int F_41 ( struct V_12 * V_13 , struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_81 ;
if ( F_38 ( V_80 ) < 2 + V_17 -> V_28 )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + V_17 -> V_28 ) ;
* V_81 ++ = V_92 ;
* V_81 ++ = V_17 -> V_28 ;
if ( V_17 -> V_28 )
memcpy ( V_81 , V_17 -> V_29 , V_17 -> V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_81 ;
if ( V_17 -> V_93 == 0 &&
V_17 -> V_88 == 0 &&
V_17 -> V_94 == V_95 )
return 0 ;
if ( F_38 ( V_80 ) < 4 )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + 2 ) ;
* V_81 ++ = V_96 ;
* V_81 ++ = 2 ;
F_43 ( V_17 -> V_97 . V_98 , V_81 ) ;
return 0 ;
}
int F_44 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_99 , V_100 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_101 )
return 0 ;
V_99 = F_45 ( V_17 -> V_24 , V_17 -> V_101 , 0 ) ;
if ( V_99 ) {
V_100 = V_17 -> V_101 - V_99 ;
V_11 = V_17 -> V_24 + V_99 ;
if ( F_38 ( V_80 ) < V_100 )
return - V_60 ;
memcpy ( F_39 ( V_80 , V_100 ) , V_11 , V_100 ) ;
}
return 0 ;
}
int F_46 ( struct V_12 * V_13 , struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_100 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_24 || ! V_17 -> V_101 )
return 0 ;
V_11 = V_17 -> V_24 ;
while ( V_11 < V_17 -> V_24 + V_17 -> V_101 ) {
if ( * V_11 == V_102 ) {
V_100 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_100 ) {
if ( F_38 ( V_80 ) < V_100 )
return - V_60 ;
memcpy ( F_39 ( V_80 , V_100 ) , V_11 , V_100 ) ;
}
return 0 ;
}
static int F_47 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_103 * V_104 ;
struct V_105 * V_44 ;
T_2 * V_81 ;
if ( F_38 ( V_80 ) < 3 )
return - V_60 ;
F_48 () ;
V_104 = F_49 ( V_13 -> V_41 . V_104 ) ;
if ( F_50 ( ! V_104 ) ) {
F_51 () ;
return - V_106 ;
}
V_44 = V_104 -> V_107 . V_44 ;
F_51 () ;
V_81 = F_39 ( V_80 , 2 + 1 ) ;
* V_81 ++ = V_108 ;
* V_81 ++ = 1 ;
* V_81 ++ = F_52 ( V_44 -> V_109 ) ;
return 0 ;
}
int F_53 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_110 V_111 = F_13 ( V_13 ) ;
struct V_112 * V_113 ;
T_2 * V_81 ;
V_113 = V_15 -> V_21 . V_114 -> V_115 [ V_111 ] ;
if ( ! V_113 -> V_116 . V_117 ||
V_13 -> V_41 . V_42 . V_43 . V_118 == V_119 )
return 0 ;
if ( F_38 ( V_80 ) < 2 + sizeof( struct V_120 ) )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + sizeof( struct V_120 ) ) ;
F_54 ( V_81 , & V_113 -> V_116 , V_113 -> V_116 . V_121 ) ;
return 0 ;
}
int F_55 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_103 * V_104 ;
struct V_105 * V_122 ;
enum V_123 V_124 =
F_56 ( & V_13 -> V_41 . V_42 . V_43 ) ;
struct V_112 * V_113 ;
struct V_125 * V_116 ;
T_2 * V_81 ;
F_48 () ;
V_104 = F_49 ( V_13 -> V_41 . V_104 ) ;
if ( F_50 ( ! V_104 ) ) {
F_51 () ;
return - V_106 ;
}
V_122 = V_104 -> V_107 . V_44 ;
F_51 () ;
V_113 = V_15 -> V_21 . V_114 -> V_115 [ V_122 -> V_111 ] ;
V_116 = & V_113 -> V_116 ;
if ( ! V_116 -> V_117 || V_124 == V_126 )
return 0 ;
if ( F_38 ( V_80 ) < 2 + sizeof( struct V_127 ) )
return - V_60 ;
V_81 = F_39 ( V_80 , 2 + sizeof( struct V_127 ) ) ;
F_57 ( V_81 , V_116 , & V_13 -> V_41 . V_42 . V_43 ,
V_13 -> V_41 . V_42 . V_128 ) ;
return 0 ;
}
static void F_58 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
static void F_59 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_9 ( V_129 , & V_17 -> V_20 ) ;
F_10 ( & V_13 -> V_15 -> V_21 , & V_13 -> V_22 ) ;
}
void F_60 ( struct V_16 * V_17 )
{
if ( V_17 -> V_97 . V_130 > V_131 )
F_9 ( V_129 , & V_17 -> V_20 ) ;
else {
F_61 ( V_129 , & V_17 -> V_20 ) ;
F_21 ( & V_17 -> V_132 ) ;
}
}
int F_62 ( struct V_133 * V_134 , T_3 * V_135 ,
const T_2 * V_136 , const T_2 * V_137 )
{
if ( F_63 ( V_136 ) ) {
* V_135 |= F_64 ( V_138 ) ;
memcpy ( V_134 -> V_139 , V_136 , V_78 ) ;
memcpy ( V_134 -> V_140 , V_137 , V_78 ) ;
memcpy ( V_134 -> V_141 , V_137 , V_78 ) ;
return 24 ;
} else {
* V_135 |= F_64 ( V_138 | V_142 ) ;
memset ( V_134 -> V_139 , 0 , V_78 ) ;
memcpy ( V_134 -> V_140 , V_137 , V_78 ) ;
memcpy ( V_134 -> V_141 , V_136 , V_78 ) ;
memcpy ( V_134 -> V_143 , V_137 , V_78 ) ;
return 30 ;
}
}
int F_65 ( struct V_12 * V_13 ,
struct V_68 * V_144 ,
const char * V_145 , const char * V_146 )
{
if ( F_50 ( ! V_145 && V_146 ) )
return 0 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> V_147 = V_13 -> V_3 . V_18 . V_97 . V_148 ;
F_66 ( F_67 ( V_13 -> V_3 . V_18 . V_149 ) , & V_144 -> V_70 ) ;
V_13 -> V_3 . V_18 . V_149 ++ ;
if ( V_145 && ! V_146 ) {
V_144 -> V_150 |= V_151 ;
memcpy ( V_144 -> V_152 , V_145 , V_78 ) ;
return 2 * V_78 ;
} else if ( V_145 && V_146 ) {
V_144 -> V_150 |= V_153 ;
memcpy ( V_144 -> V_152 , V_145 , V_78 ) ;
memcpy ( V_144 -> V_154 , V_146 , V_78 ) ;
return 3 * V_78 ;
}
return V_78 ;
}
static void F_68 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_49 ;
F_69 ( V_13 , V_155 ) ;
F_70 ( V_13 ) ;
V_49 = F_17 ( V_13 ) ;
F_22 ( V_13 , V_49 ) ;
F_71 ( & V_17 -> V_156 ,
F_72 ( V_73 +
V_157 ) ) ;
}
static void F_73 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_158 ;
F_74 ( V_13 ) ;
if ( V_17 -> V_97 . V_130 == V_159 )
V_158 = V_17 -> V_97 . V_160 ;
else
V_158 = V_17 -> V_97 . V_161 ;
F_71 ( & V_17 -> V_132 ,
F_72 ( F_75 ( V_158 ) ) ) ;
}
static int
F_76 ( struct V_16 * V_17 )
{
struct V_162 * V_163 ;
int V_164 , V_165 ;
struct V_79 * V_80 ;
struct V_1 * V_2 ;
struct V_103 * V_104 ;
enum V_110 V_111 ;
T_2 * V_81 ;
struct V_12 * V_13 ;
int V_166 = F_77 ( struct V_1 , V_3 . V_167 ) +
sizeof( V_2 -> V_3 . V_167 ) ;
V_13 = F_78 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_48 () ;
V_104 = F_49 ( V_13 -> V_41 . V_104 ) ;
V_111 = V_104 -> V_107 . V_44 -> V_111 ;
F_51 () ;
V_164 = V_166 +
2 +
2 + 8 +
2 + 3 ;
V_165 = 2 + ( V_168 - 8 ) +
2 + sizeof( struct V_120 ) +
2 + sizeof( struct V_127 ) +
2 + V_17 -> V_28 +
2 + sizeof( struct V_84 ) +
2 + sizeof( T_3 ) +
V_17 -> V_101 ;
V_163 = F_79 ( sizeof( * V_163 ) + V_164 + V_165 , V_59 ) ;
V_80 = F_80 ( F_81 ( V_164 , V_165 ) ) ;
if ( ! V_163 || ! V_80 )
goto V_169;
V_163 -> V_170 = ( ( T_2 * ) V_163 ) + sizeof( * V_163 ) ;
V_2 = (struct V_1 * ) F_39 ( V_80 , V_166 ) ;
memset ( V_2 , 0 , V_166 ) ;
V_2 -> V_171 = F_64 ( V_172 |
V_173 ) ;
F_82 ( V_2 -> V_174 ) ;
memcpy ( V_2 -> V_67 , V_13 -> V_41 . V_175 , V_78 ) ;
memcpy ( V_2 -> V_176 , V_13 -> V_41 . V_175 , V_78 ) ;
F_83 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_167 . V_177 =
F_64 ( V_13 -> V_41 . V_42 . V_177 ) ;
V_2 -> V_3 . V_167 . V_178 |= F_64 (
V_13 -> V_3 . V_18 . V_179 ? V_180 : 0 ) ;
V_81 = F_39 ( V_80 , 2 ) ;
* V_81 ++ = V_181 ;
* V_81 ++ = 0x0 ;
if ( F_84 ( V_13 , V_80 , true , V_111 ) ||
F_47 ( V_13 , V_80 ) )
goto V_169;
V_163 -> V_164 = V_80 -> V_100 ;
memcpy ( V_163 -> V_170 , V_80 -> V_11 , V_163 -> V_164 ) ;
F_85 ( V_80 , 0 ) ;
V_163 -> V_182 = V_163 -> V_170 + V_163 -> V_164 ;
if ( F_86 ( V_13 , V_80 , true , V_111 ) ||
F_46 ( V_13 , V_80 ) ||
F_53 ( V_13 , V_80 ) ||
F_55 ( V_13 , V_80 ) ||
F_41 ( V_13 , V_80 ) ||
F_37 ( V_13 , V_80 ) ||
F_42 ( V_13 , V_80 ) ||
F_44 ( V_13 , V_80 ) )
goto V_169;
V_163 -> V_165 = V_80 -> V_100 ;
memcpy ( V_163 -> V_182 , V_80 -> V_11 , V_163 -> V_165 ) ;
F_87 ( V_80 ) ;
F_88 ( V_17 -> V_167 , V_163 ) ;
return 0 ;
V_169:
F_30 ( V_163 ) ;
F_87 ( V_80 ) ;
return - V_60 ;
}
static int
F_89 ( struct V_16 * V_17 )
{
struct V_162 * V_183 ;
int V_184 ;
F_90 ( & V_17 -> V_185 ) ;
V_183 = F_91 ( V_17 -> V_167 ,
F_92 ( & V_17 -> V_185 ) ) ;
V_184 = F_76 ( V_17 ) ;
if ( V_184 )
goto V_186;
if ( V_183 )
F_93 ( V_183 , V_187 ) ;
V_186:
F_94 ( & V_17 -> V_185 ) ;
return V_184 ;
}
void F_22 ( struct V_12 * V_13 ,
T_1 V_49 )
{
if ( V_13 -> V_41 . V_42 . V_188 &&
( V_49 & ( V_51 |
V_189 |
V_190 |
V_191 ) ) )
if ( F_89 ( & V_13 -> V_3 . V_18 ) )
return;
F_95 ( V_13 , V_49 ) ;
}
int F_96 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_49 = V_51 |
V_192 |
V_189 |
V_190 |
V_191 ;
enum V_110 V_111 = F_13 ( V_13 ) ;
V_15 -> V_193 ++ ;
F_97 ( & V_15 -> V_194 ) ;
F_98 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_39 = 0 ;
V_17 -> V_195 = F_99 ( V_17 -> V_37 ) ;
V_17 -> V_90 = false ;
V_17 -> V_196 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_60 ( V_17 ) ;
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
V_13 -> V_41 . V_42 . V_128 =
V_17 -> V_97 . V_197 ;
V_13 -> V_41 . V_42 . V_188 = true ;
V_13 -> V_41 . V_42 . V_25 =
F_100 ( V_15 , V_111 ) ;
V_49 |= F_101 ( V_13 ) ;
if ( F_76 ( V_17 ) ) {
F_102 ( V_13 ) ;
return - V_60 ;
}
F_95 ( V_13 , V_49 ) ;
F_103 ( V_13 -> V_198 ) ;
return 0 ;
}
void F_102 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_162 * V_163 ;
F_104 ( V_13 -> V_198 ) ;
V_17 -> V_28 = 0 ;
V_13 -> V_41 . V_42 . V_188 = false ;
F_61 ( V_199 , & V_13 -> V_200 ) ;
F_95 ( V_13 , V_192 ) ;
F_90 ( & V_17 -> V_185 ) ;
V_163 = F_91 ( V_17 -> V_167 ,
F_92 ( & V_17 -> V_185 ) ) ;
F_88 ( V_17 -> V_167 , NULL ) ;
F_93 ( V_163 , V_187 ) ;
F_94 ( & V_17 -> V_185 ) ;
F_105 ( V_13 ) ;
F_106 ( V_13 ) ;
V_15 -> V_201 -= F_107 ( & V_17 -> V_202 . V_203 ) ;
F_108 ( & V_17 -> V_202 . V_203 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_156 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_132 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_204 ) ;
F_109 ( & V_13 -> V_22 ) ;
V_15 -> V_193 -- ;
F_110 ( & V_15 -> V_194 ) ;
F_98 ( V_15 ) ;
}
static void
F_111 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_100 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_79 * V_205 ;
struct V_162 * V_163 ;
struct V_1 * V_134 ;
struct V_23 V_206 ;
T_4 V_207 ;
T_2 * V_81 ;
V_81 = V_2 -> V_3 . V_208 . V_209 ;
V_207 = ( T_2 * ) V_81 - ( T_2 * ) V_2 ;
if ( V_207 > V_100 )
return;
F_112 ( V_81 , V_100 - V_207 , false , & V_206 ) ;
if ( ( ! F_34 ( V_2 -> V_174 , V_13 -> V_41 . V_175 ) &&
! F_113 ( V_2 -> V_174 ) ) ||
V_206 . V_210 != 0 )
return;
if ( V_206 . V_28 != 0 &&
( V_206 . V_28 != V_17 -> V_28 ||
memcmp ( V_206 . V_29 , V_17 -> V_29 , V_17 -> V_28 ) ) )
return;
F_48 () ;
V_163 = F_49 ( V_17 -> V_167 ) ;
if ( ! V_163 )
goto V_186;
V_205 = F_80 ( V_15 -> V_211 +
V_163 -> V_164 + V_163 -> V_165 ) ;
if ( ! V_205 )
goto V_186;
F_114 ( V_205 , V_15 -> V_211 ) ;
memcpy ( F_39 ( V_205 , V_163 -> V_164 ) , V_163 -> V_170 , V_163 -> V_164 ) ;
memcpy ( F_39 ( V_205 , V_163 -> V_165 ) , V_163 -> V_182 , V_163 -> V_165 ) ;
V_134 = (struct V_1 * ) V_205 -> V_11 ;
V_134 -> V_171 = F_64 ( V_172 |
V_212 ) ;
memcpy ( V_134 -> V_174 , V_2 -> V_67 , V_78 ) ;
F_115 ( V_205 ) -> V_150 |= V_213 ;
F_116 ( V_13 , V_205 ) ;
V_186:
F_51 () ;
}
static void F_117 ( struct V_12 * V_13 ,
T_5 V_214 ,
struct V_1 * V_2 ,
T_4 V_100 ,
struct V_215 * V_216 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_23 V_206 ;
struct V_105 * V_122 ;
T_4 V_207 ;
int V_217 ;
enum V_110 V_111 = V_216 -> V_111 ;
if ( V_214 == V_212 &&
! F_34 ( V_2 -> V_174 , V_13 -> V_41 . V_175 ) )
return;
V_207 = ( T_2 * ) V_2 -> V_3 . V_218 . V_209 - ( T_2 * ) V_2 ;
if ( V_207 > V_100 )
return;
F_112 ( V_2 -> V_3 . V_218 . V_209 , V_100 - V_207 ,
false , & V_206 ) ;
if ( ( ! V_206 . V_29 || ! V_206 . V_31 ) ||
( V_206 . V_219 && V_13 -> V_3 . V_18 . V_179 == V_220 ) ||
( ! V_206 . V_219 && V_13 -> V_3 . V_18 . V_179 != V_220 ) )
return;
if ( V_206 . V_221 )
V_217 = F_118 ( V_206 . V_221 [ 0 ] , V_111 ) ;
else
V_217 = V_216 -> V_217 ;
V_122 = F_119 ( V_15 -> V_21 . V_114 , V_217 ) ;
if ( ! V_122 || V_122 -> V_150 & V_222 )
return;
if ( F_11 ( V_13 , & V_206 ) )
F_120 ( V_13 , V_2 -> V_67 , & V_206 ) ;
if ( V_17 -> V_195 )
V_17 -> V_195 -> V_223 ( V_13 ,
V_214 , V_2 , & V_206 , V_216 ) ;
}
static void F_121 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_100 ,
struct V_215 * V_216 )
{
switch ( V_2 -> V_3 . V_4 . V_224 ) {
case V_225 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_226 . V_6 ) {
case V_227 :
case V_228 :
case V_229 :
F_122 ( V_13 , V_2 , V_100 , V_216 ) ;
break;
}
break;
case V_230 :
if ( F_1 ( V_2 ) )
F_123 ( V_13 , V_2 , V_100 ) ;
break;
}
}
void F_124 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_215 * V_216 ;
struct V_1 * V_2 ;
T_5 V_214 ;
V_216 = F_125 ( V_80 ) ;
V_2 = (struct V_1 * ) V_80 -> V_11 ;
V_214 = F_126 ( V_2 -> V_171 ) & V_231 ;
switch ( V_214 ) {
case V_212 :
case V_173 :
F_117 ( V_13 , V_214 , V_2 , V_80 -> V_100 ,
V_216 ) ;
break;
case V_232 :
F_111 ( V_13 , V_2 , V_80 -> V_100 ) ;
break;
case V_233 :
F_121 ( V_13 , V_2 , V_80 -> V_100 , V_216 ) ;
break;
}
}
void F_127 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( V_17 -> V_234 &&
F_33 ( V_73 ,
V_17 -> V_235 + F_128 ( V_17 -> V_97 . V_236 ) ) )
F_129 ( V_13 ) ;
if ( F_130 ( V_237 , & V_17 -> V_20 ) )
F_131 () ;
if ( F_130 ( V_238 , & V_17 -> V_20 ) )
F_132 () ;
if ( F_130 ( V_19 , & V_17 -> V_20 ) )
F_68 ( V_13 ) ;
if ( F_130 ( V_129 , & V_17 -> V_20 ) )
F_73 ( V_13 ) ;
if ( F_130 ( V_239 , & V_17 -> V_20 ) )
F_133 ( V_13 ) ;
}
void F_134 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_48 () ;
F_135 (sdata, &local->interfaces, list)
if ( F_136 ( & V_13 -> V_41 ) &&
F_137 ( V_13 ) )
F_10 ( & V_15 -> V_21 , & V_13 -> V_22 ) ;
F_51 () ;
}
void F_138 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_240 [ V_78 ] = {} ;
F_139 ( & V_17 -> V_156 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_50 = true ;
V_17 -> V_241 = 0 ;
V_17 -> V_242 = 0 ;
V_17 -> V_243 = 0 ;
F_140 ( & V_17 -> V_244 , 0 ) ;
F_23 ( V_13 ) ;
V_17 -> V_235 = V_73 ;
V_17 -> V_245 = V_73 ;
if ( ! V_8 )
F_2 () ;
F_139 ( & V_17 -> V_204 ,
F_58 ,
( unsigned long ) V_13 ) ;
F_139 ( & V_17 -> V_132 ,
F_59 ,
( unsigned long ) V_13 ) ;
F_25 ( & V_17 -> V_246 . V_66 ) ;
F_141 ( & V_17 -> V_202 . V_203 ) ;
F_142 ( & V_17 -> V_247 ) ;
F_142 ( & V_17 -> V_248 ) ;
F_143 ( V_17 -> V_167 , NULL ) ;
F_144 ( & V_17 -> V_185 ) ;
V_13 -> V_41 . V_42 . V_176 = V_240 ;
}
