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
if ( V_15 -> V_21 ) {
F_9 ( V_22 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
bool F_11 ( struct V_12 * V_13 ,
struct V_26 * V_27 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_28 = 0 ;
struct V_29 V_30 ;
if ( ! ( V_17 -> V_31 == V_27 -> V_31 &&
memcmp ( V_17 -> V_32 , V_27 -> V_32 , V_27 -> V_31 ) == 0 &&
( V_17 -> V_33 == V_27 -> V_34 -> V_35 ) &&
( V_17 -> V_36 == V_27 -> V_34 -> V_37 ) &&
( V_17 -> V_38 == V_27 -> V_34 -> V_39 ) &&
( V_17 -> V_40 == V_27 -> V_34 -> V_41 ) &&
( V_17 -> V_42 == V_27 -> V_34 -> V_43 ) ) )
return false ;
F_12 ( V_15 , V_27 , F_13 ( V_13 ) ,
& V_28 ) ;
if ( V_13 -> V_44 . V_45 . V_28 != V_28 )
return false ;
F_14 ( V_13 -> V_44 . V_45 . V_46 . V_47 ,
V_27 -> V_48 , & V_30 ) ;
if ( ! F_15 ( & V_13 -> V_44 . V_45 . V_46 ,
& V_30 ) )
return false ;
return true ;
}
bool F_16 ( struct V_26 * V_27 )
{
return ( V_27 -> V_34 -> V_49 &
V_50 ) != 0 ;
}
T_1 F_17 ( struct V_12 * V_13 )
{
bool V_51 ;
T_1 V_52 = 0 ;
V_51 = F_18 ( V_13 ) ;
if ( V_51 != V_13 -> V_3 . V_18 . V_53 ) {
V_13 -> V_3 . V_18 . V_53 = V_51 ;
V_52 = V_54 ;
}
return V_52 ;
}
void F_19 ( struct V_55 * V_56 )
{
struct V_12 * V_13 = V_56 -> V_13 ;
T_1 V_52 ;
V_52 = F_17 ( V_13 ) ;
if ( V_13 -> V_3 . V_18 . V_57 == V_58 ) {
V_52 |= F_20 ( V_56 ) ;
F_21 ( & V_56 -> V_59 ) ;
}
if ( V_52 )
F_22 ( V_13 , V_52 ) ;
}
int F_23 ( struct V_12 * V_13 )
{
int V_60 ;
V_13 -> V_3 . V_18 . V_61 = F_24 ( sizeof( struct V_62 ) , V_63 ) ;
if ( ! V_13 -> V_3 . V_18 . V_61 )
return - V_64 ;
V_13 -> V_3 . V_18 . V_61 -> V_65 = V_66 - 1 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ )
F_25 ( & V_13 -> V_3 . V_18 . V_61 -> V_67 [ V_60 ] ) ;
return 0 ;
}
void F_26 ( struct V_12 * V_13 )
{
struct V_62 * V_61 = V_13 -> V_3 . V_18 . V_61 ;
struct V_10 * V_68 , * V_69 ;
int V_60 ;
if ( ! V_13 -> V_3 . V_18 . V_61 )
return;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
F_27 (p, n, &rmc->bucket[i], list) {
F_28 ( & V_68 -> V_70 ) ;
F_29 ( V_9 , V_68 ) ;
}
}
F_30 ( V_61 ) ;
V_13 -> V_3 . V_18 . V_61 = NULL ;
}
int F_31 ( struct V_12 * V_13 ,
const T_2 * V_71 , struct V_72 * V_73 )
{
struct V_62 * V_61 = V_13 -> V_3 . V_18 . V_61 ;
T_1 V_74 = 0 ;
int V_75 = 0 ;
T_2 V_76 ;
struct V_10 * V_68 , * V_69 ;
memcpy ( & V_74 , & V_73 -> V_74 , sizeof( V_73 -> V_74 ) ) ;
V_76 = F_32 ( V_73 -> V_74 ) & V_61 -> V_65 ;
F_27 (p, n, &rmc->bucket[idx], list) {
++ V_75 ;
if ( F_33 ( V_77 , V_68 -> V_78 ) ||
V_75 == V_79 ) {
F_28 ( & V_68 -> V_70 ) ;
F_29 ( V_9 , V_68 ) ;
-- V_75 ;
} else if ( ( V_74 == V_68 -> V_74 ) && F_34 ( V_71 , V_68 -> V_71 ) )
return - 1 ;
}
V_68 = F_35 ( V_9 , V_80 ) ;
if ( ! V_68 )
return 0 ;
V_68 -> V_74 = V_74 ;
V_68 -> V_78 = V_77 + V_81 ;
memcpy ( V_68 -> V_71 , V_71 , V_82 ) ;
F_36 ( & V_68 -> V_70 , & V_61 -> V_67 [ V_76 ] ) ;
return 0 ;
}
int F_37 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_85 , V_86 ;
T_2 V_87 = sizeof( struct V_88 ) ;
if ( F_38 ( V_84 ) < 2 + V_87 )
return - V_64 ;
V_85 = F_39 ( V_84 , 2 + V_87 ) ;
* V_85 ++ = V_89 ;
* V_85 ++ = V_87 ;
* V_85 ++ = V_17 -> V_33 ;
* V_85 ++ = V_17 -> V_36 ;
* V_85 ++ = V_17 -> V_38 ;
* V_85 ++ = V_17 -> V_40 ;
* V_85 ++ = V_17 -> V_42 ;
V_86 = F_40 ( & V_17 -> V_90 ) ;
V_86 = ( V_86 > 15 ) ? 15 : V_86 ;
* V_85 ++ = V_86 << 1 ;
* V_85 = V_91 ;
* V_85 |= V_17 -> V_53 ?
V_50 : 0x00 ;
* V_85 |= V_17 -> V_92 ?
V_93 : 0x00 ;
* V_85 ++ |= V_17 -> V_94 ?
V_95 : 0x00 ;
* V_85 ++ = 0x00 ;
return 0 ;
}
int F_41 ( struct V_12 * V_13 , struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_85 ;
if ( F_38 ( V_84 ) < 2 + V_17 -> V_31 )
return - V_64 ;
V_85 = F_39 ( V_84 , 2 + V_17 -> V_31 ) ;
* V_85 ++ = V_96 ;
* V_85 ++ = V_17 -> V_31 ;
if ( V_17 -> V_31 )
memcpy ( V_85 , V_17 -> V_32 , V_17 -> V_31 ) ;
return 0 ;
}
static int F_42 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_85 ;
if ( V_17 -> V_97 == 0 &&
V_17 -> V_92 == 0 &&
V_17 -> V_98 == V_99 )
return 0 ;
if ( F_38 ( V_84 ) < 4 )
return - V_64 ;
V_85 = F_39 ( V_84 , 2 + 2 ) ;
* V_85 ++ = V_100 ;
* V_85 ++ = 2 ;
F_43 ( V_17 -> V_101 . V_102 , V_85 ) ;
return 0 ;
}
int F_44 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_103 , V_104 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_105 )
return 0 ;
V_103 = F_45 ( V_17 -> V_27 , V_17 -> V_105 , 0 ) ;
if ( V_103 ) {
V_104 = V_17 -> V_105 - V_103 ;
V_11 = V_17 -> V_27 + V_103 ;
if ( F_38 ( V_84 ) < V_104 )
return - V_64 ;
memcpy ( F_39 ( V_84 , V_104 ) , V_11 , V_104 ) ;
}
return 0 ;
}
int F_46 ( struct V_12 * V_13 , struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_104 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_105 )
return 0 ;
V_11 = V_17 -> V_27 ;
while ( V_11 < V_17 -> V_27 + V_17 -> V_105 ) {
if ( * V_11 == V_106 ) {
V_104 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_104 ) {
if ( F_38 ( V_84 ) < V_104 )
return - V_64 ;
memcpy ( F_39 ( V_84 , V_104 ) , V_11 , V_104 ) ;
}
return 0 ;
}
static int F_47 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_107 * V_108 ;
struct V_109 * V_47 ;
T_2 * V_85 ;
if ( F_38 ( V_84 ) < 3 )
return - V_64 ;
F_48 () ;
V_108 = F_49 ( V_13 -> V_44 . V_108 ) ;
if ( F_50 ( ! V_108 ) ) {
F_51 () ;
return - V_110 ;
}
V_47 = V_108 -> V_111 . V_47 ;
F_51 () ;
V_85 = F_39 ( V_84 , 2 + 1 ) ;
* V_85 ++ = V_112 ;
* V_85 ++ = 1 ;
* V_85 ++ = F_52 ( V_47 -> V_113 ) ;
return 0 ;
}
int F_53 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_114 V_115 = F_13 ( V_13 ) ;
struct V_116 * V_117 ;
T_2 * V_85 ;
V_117 = V_15 -> V_24 . V_118 -> V_119 [ V_115 ] ;
if ( ! V_117 -> V_120 . V_121 ||
V_13 -> V_44 . V_45 . V_46 . V_122 == V_123 )
return 0 ;
if ( F_38 ( V_84 ) < 2 + sizeof( struct V_124 ) )
return - V_64 ;
V_85 = F_39 ( V_84 , 2 + sizeof( struct V_124 ) ) ;
F_54 ( V_85 , & V_117 -> V_120 , V_117 -> V_120 . V_125 ) ;
return 0 ;
}
int F_55 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_107 * V_108 ;
struct V_109 * V_126 ;
enum V_127 V_128 =
F_56 ( & V_13 -> V_44 . V_45 . V_46 ) ;
struct V_116 * V_117 ;
struct V_129 * V_120 ;
T_2 * V_85 ;
F_48 () ;
V_108 = F_49 ( V_13 -> V_44 . V_108 ) ;
if ( F_50 ( ! V_108 ) ) {
F_51 () ;
return - V_110 ;
}
V_126 = V_108 -> V_111 . V_47 ;
F_51 () ;
V_117 = V_15 -> V_24 . V_118 -> V_119 [ V_126 -> V_115 ] ;
V_120 = & V_117 -> V_120 ;
if ( ! V_120 -> V_121 || V_128 == V_130 )
return 0 ;
if ( F_38 ( V_84 ) < 2 + sizeof( struct V_131 ) )
return - V_64 ;
V_85 = F_39 ( V_84 , 2 + sizeof( struct V_131 ) ) ;
F_57 ( V_85 , V_120 , & V_13 -> V_44 . V_45 . V_46 ,
V_13 -> V_44 . V_45 . V_132 ) ;
return 0 ;
}
static void F_58 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( V_15 -> V_21 ) {
F_9 ( V_133 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
static void F_59 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_9 ( V_134 , & V_17 -> V_20 ) ;
if ( V_15 -> V_21 ) {
F_9 ( V_135 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
void F_60 ( struct V_16 * V_17 )
{
if ( V_17 -> V_101 . V_136 > V_137 )
F_9 ( V_134 , & V_17 -> V_20 ) ;
else {
F_61 ( V_134 , & V_17 -> V_20 ) ;
F_21 ( & V_17 -> V_138 ) ;
}
}
int F_62 ( struct V_139 * V_140 , T_3 * V_141 ,
const T_2 * V_142 , const T_2 * V_143 )
{
if ( F_63 ( V_142 ) ) {
* V_141 |= F_64 ( V_144 ) ;
memcpy ( V_140 -> V_145 , V_142 , V_82 ) ;
memcpy ( V_140 -> V_146 , V_143 , V_82 ) ;
memcpy ( V_140 -> V_147 , V_143 , V_82 ) ;
return 24 ;
} else {
* V_141 |= F_64 ( V_144 | V_148 ) ;
memset ( V_140 -> V_145 , 0 , V_82 ) ;
memcpy ( V_140 -> V_146 , V_143 , V_82 ) ;
memcpy ( V_140 -> V_147 , V_142 , V_82 ) ;
memcpy ( V_140 -> V_149 , V_143 , V_82 ) ;
return 30 ;
}
}
int F_65 ( struct V_12 * V_13 ,
struct V_72 * V_150 ,
const char * V_151 , const char * V_152 )
{
if ( F_50 ( ! V_151 && V_152 ) )
return 0 ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_153 = V_13 -> V_3 . V_18 . V_101 . V_154 ;
F_66 ( F_67 ( V_13 -> V_3 . V_18 . V_155 ) , & V_150 -> V_74 ) ;
V_13 -> V_3 . V_18 . V_155 ++ ;
if ( V_151 && ! V_152 ) {
V_150 -> V_156 |= V_157 ;
memcpy ( V_150 -> V_158 , V_151 , V_82 ) ;
return 2 * V_82 ;
} else if ( V_151 && V_152 ) {
V_150 -> V_156 |= V_159 ;
memcpy ( V_150 -> V_158 , V_151 , V_82 ) ;
memcpy ( V_150 -> V_160 , V_152 , V_82 ) ;
return 3 * V_82 ;
}
return V_82 ;
}
static void F_68 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_52 ;
F_69 ( V_13 , V_161 ) ;
F_70 ( V_13 ) ;
V_52 = F_17 ( V_13 ) ;
F_22 ( V_13 , V_52 ) ;
F_71 ( & V_17 -> V_162 ,
F_72 ( V_77 +
V_163 ) ) ;
}
static void F_73 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_164 ;
F_74 ( V_13 ) ;
if ( V_17 -> V_101 . V_136 == V_165 )
V_164 = V_17 -> V_101 . V_166 ;
else
V_164 = V_17 -> V_101 . V_167 ;
F_71 ( & V_17 -> V_138 ,
F_72 ( F_75 ( V_164 ) ) ) ;
}
void F_76 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_21 ( & V_17 -> V_162 ) )
F_9 ( V_22 , & V_17 -> V_23 ) ;
if ( F_21 ( & V_17 -> V_168 ) )
F_9 ( V_133 , & V_17 -> V_23 ) ;
if ( F_21 ( & V_17 -> V_138 ) )
F_9 ( V_135 , & V_17 -> V_23 ) ;
}
void F_77 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_78 ( V_22 , & V_17 -> V_23 ) )
F_79 ( & V_17 -> V_162 ) ;
if ( F_78 ( V_133 , & V_17 -> V_23 ) )
F_79 ( & V_17 -> V_168 ) ;
if ( F_78 ( V_135 , & V_17 -> V_23 ) )
F_79 ( & V_17 -> V_138 ) ;
F_60 ( V_17 ) ;
}
static int
F_80 ( struct V_16 * V_17 )
{
struct V_169 * V_170 ;
int V_171 , V_172 ;
struct V_83 * V_84 ;
struct V_1 * V_2 ;
struct V_107 * V_108 ;
enum V_114 V_115 ;
T_2 * V_85 ;
struct V_12 * V_13 ;
int V_173 = F_81 ( struct V_1 , V_3 . V_174 ) +
sizeof( V_2 -> V_3 . V_174 ) ;
V_13 = F_82 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_48 () ;
V_108 = F_49 ( V_13 -> V_44 . V_108 ) ;
V_115 = V_108 -> V_111 . V_47 -> V_115 ;
F_51 () ;
V_171 = V_173 +
2 +
2 + 8 +
2 + 3 ;
V_172 = 2 + ( V_175 - 8 ) +
2 + sizeof( struct V_124 ) +
2 + sizeof( struct V_131 ) +
2 + V_17 -> V_31 +
2 + sizeof( struct V_88 ) +
2 + sizeof( T_3 ) +
V_17 -> V_105 ;
V_170 = F_83 ( sizeof( * V_170 ) + V_171 + V_172 , V_63 ) ;
V_84 = F_84 ( F_85 ( V_171 , V_172 ) ) ;
if ( ! V_170 || ! V_84 )
goto V_176;
V_170 -> V_177 = ( ( T_2 * ) V_170 ) + sizeof( * V_170 ) ;
V_2 = (struct V_1 * ) F_39 ( V_84 , V_173 ) ;
memset ( V_2 , 0 , V_173 ) ;
V_2 -> V_178 = F_64 ( V_179 |
V_180 ) ;
F_86 ( V_2 -> V_181 ) ;
memcpy ( V_2 -> V_71 , V_13 -> V_44 . V_182 , V_82 ) ;
memcpy ( V_2 -> V_183 , V_13 -> V_44 . V_182 , V_82 ) ;
F_87 ( V_13 , NULL , ( void * ) V_2 ) ;
V_2 -> V_3 . V_174 . V_184 =
F_64 ( V_13 -> V_44 . V_45 . V_184 ) ;
V_2 -> V_3 . V_174 . V_185 |= F_64 (
V_13 -> V_3 . V_18 . V_57 ? V_186 : 0 ) ;
V_85 = F_39 ( V_84 , 2 ) ;
* V_85 ++ = V_187 ;
* V_85 ++ = 0x0 ;
if ( F_88 ( V_13 , V_84 , true , V_115 ) ||
F_47 ( V_13 , V_84 ) )
goto V_176;
V_170 -> V_171 = V_84 -> V_104 ;
memcpy ( V_170 -> V_177 , V_84 -> V_11 , V_170 -> V_171 ) ;
F_89 ( V_84 , 0 ) ;
V_170 -> V_188 = V_170 -> V_177 + V_170 -> V_171 ;
if ( F_90 ( V_13 , V_84 , true , V_115 ) ||
F_46 ( V_13 , V_84 ) ||
F_53 ( V_13 , V_84 ) ||
F_55 ( V_13 , V_84 ) ||
F_41 ( V_13 , V_84 ) ||
F_37 ( V_13 , V_84 ) ||
F_42 ( V_13 , V_84 ) ||
F_44 ( V_13 , V_84 ) )
goto V_176;
V_170 -> V_172 = V_84 -> V_104 ;
memcpy ( V_170 -> V_188 , V_84 -> V_11 , V_170 -> V_172 ) ;
F_91 ( V_84 ) ;
F_92 ( V_17 -> V_174 , V_170 ) ;
return 0 ;
V_176:
F_30 ( V_170 ) ;
F_91 ( V_84 ) ;
return - V_64 ;
}
static int
F_93 ( struct V_16 * V_17 )
{
struct V_12 * V_13 ;
struct V_169 * V_189 ;
int V_190 ;
V_13 = F_82 ( V_17 , struct V_12 , V_3 . V_18 ) ;
F_94 ( & V_17 -> V_191 ) ;
V_189 = F_95 ( V_17 -> V_174 ,
F_96 ( & V_17 -> V_191 ) ) ;
V_190 = F_80 ( V_17 ) ;
if ( V_190 )
goto V_192;
if ( V_189 )
F_97 ( V_189 , V_193 ) ;
V_192:
F_98 ( & V_17 -> V_191 ) ;
return V_190 ;
}
void F_22 ( struct V_12 * V_13 ,
T_1 V_52 )
{
if ( V_13 -> V_44 . V_45 . V_194 &&
( V_52 & ( V_54 |
V_195 |
V_196 |
V_197 ) ) )
if ( F_93 ( & V_13 -> V_3 . V_18 ) )
return;
F_99 ( V_13 , V_52 ) ;
}
int F_100 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_52 = V_54 |
V_198 |
V_195 |
V_196 |
V_197 ;
enum V_114 V_115 = F_13 ( V_13 ) ;
V_15 -> V_199 ++ ;
F_101 ( & V_15 -> V_200 ) ;
F_102 ( V_15 ) ;
V_17 -> V_38 = 0 ;
V_17 -> V_42 = 0 ;
V_17 -> V_201 = F_103 ( V_17 -> V_40 ) ;
V_17 -> V_94 = false ;
V_17 -> V_202 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_60 ( V_17 ) ;
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_13 -> V_44 . V_45 . V_132 =
V_17 -> V_101 . V_203 ;
V_13 -> V_44 . V_45 . V_194 = true ;
V_13 -> V_44 . V_45 . V_28 =
F_104 ( V_15 , V_115 ) ;
V_52 |= F_105 ( V_13 ) ;
if ( F_80 ( V_17 ) ) {
F_106 ( V_13 ) ;
return - V_64 ;
}
F_99 ( V_13 , V_52 ) ;
F_107 ( V_13 -> V_204 ) ;
return 0 ;
}
void F_106 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_169 * V_170 ;
F_108 ( V_13 -> V_204 ) ;
V_17 -> V_31 = 0 ;
V_13 -> V_44 . V_45 . V_194 = false ;
F_61 ( V_205 , & V_13 -> V_206 ) ;
F_99 ( V_13 , V_198 ) ;
F_94 ( & V_17 -> V_191 ) ;
V_170 = F_95 ( V_17 -> V_174 ,
F_96 ( & V_17 -> V_191 ) ) ;
F_92 ( V_17 -> V_174 , NULL ) ;
F_97 ( V_170 , V_193 ) ;
F_98 ( & V_17 -> V_191 ) ;
F_109 ( V_13 ) ;
F_110 ( V_13 ) ;
V_15 -> V_207 -= F_111 ( & V_17 -> V_208 . V_209 ) ;
F_112 ( & V_17 -> V_208 . V_209 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_162 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_138 ) ;
F_21 ( & V_13 -> V_3 . V_18 . V_168 ) ;
F_113 ( & V_13 -> V_25 ) ;
V_15 -> V_199 -- ;
F_114 ( & V_15 -> V_200 ) ;
F_102 ( V_15 ) ;
V_13 -> V_3 . V_18 . V_23 = 0 ;
}
static void
F_115 ( struct V_12 * V_13 ,
struct V_1 * V_2 , T_4 V_104 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_83 * V_210 ;
struct V_169 * V_170 ;
struct V_1 * V_140 ;
struct V_26 V_211 ;
T_4 V_212 ;
T_2 * V_85 , * V_213 ;
V_213 = ( ( T_2 * ) V_2 ) + V_104 ;
V_85 = V_2 -> V_3 . V_214 . V_215 ;
V_212 = ( T_2 * ) V_85 - ( T_2 * ) V_2 ;
if ( V_212 > V_104 )
return;
F_116 ( V_85 , V_104 - V_212 , & V_211 ) ;
if ( ( ! F_34 ( V_2 -> V_181 , V_13 -> V_44 . V_182 ) &&
! F_117 ( V_2 -> V_181 ) ) ||
V_211 . V_216 != 0 )
return;
if ( V_211 . V_31 != 0 &&
( V_211 . V_31 != V_17 -> V_31 ||
memcmp ( V_211 . V_32 , V_17 -> V_32 , V_17 -> V_31 ) ) )
return;
F_48 () ;
V_170 = F_49 ( V_17 -> V_174 ) ;
if ( ! V_170 )
goto V_192;
V_210 = F_84 ( V_15 -> V_217 +
V_170 -> V_171 + V_170 -> V_172 ) ;
if ( ! V_210 )
goto V_192;
F_118 ( V_210 , V_15 -> V_217 ) ;
memcpy ( F_39 ( V_210 , V_170 -> V_171 ) , V_170 -> V_177 , V_170 -> V_171 ) ;
memcpy ( F_39 ( V_210 , V_170 -> V_172 ) , V_170 -> V_188 , V_170 -> V_172 ) ;
V_140 = (struct V_1 * ) V_210 -> V_11 ;
V_140 -> V_178 = F_64 ( V_179 |
V_218 ) ;
memcpy ( V_140 -> V_181 , V_2 -> V_71 , V_82 ) ;
F_119 ( V_210 ) -> V_156 |= V_219 ;
F_120 ( V_13 , V_210 ) ;
V_192:
F_51 () ;
}
static void F_121 ( struct V_12 * V_13 ,
T_5 V_220 ,
struct V_1 * V_2 ,
T_4 V_104 ,
struct V_221 * V_222 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_26 V_211 ;
struct V_109 * V_126 ;
T_4 V_212 ;
int V_223 ;
enum V_114 V_115 = V_222 -> V_115 ;
if ( V_220 == V_218 &&
! F_34 ( V_2 -> V_181 , V_13 -> V_44 . V_182 ) )
return;
V_212 = ( T_2 * ) V_2 -> V_3 . V_224 . V_215 - ( T_2 * ) V_2 ;
if ( V_212 > V_104 )
return;
F_116 ( V_2 -> V_3 . V_224 . V_215 , V_104 - V_212 ,
& V_211 ) ;
if ( ( ! V_211 . V_32 || ! V_211 . V_34 ) ||
( V_211 . V_225 && V_13 -> V_3 . V_18 . V_57 == V_58 ) ||
( ! V_211 . V_225 && V_13 -> V_3 . V_18 . V_57 != V_58 ) )
return;
if ( V_211 . V_226 && V_211 . V_227 == 1 )
V_223 = F_122 ( V_211 . V_226 [ 0 ] , V_115 ) ;
else
V_223 = V_222 -> V_223 ;
V_126 = F_123 ( V_15 -> V_24 . V_118 , V_223 ) ;
if ( ! V_126 || V_126 -> V_156 & V_228 )
return;
if ( F_11 ( V_13 , & V_211 ) )
F_124 ( V_13 , V_2 -> V_71 , & V_211 ) ;
if ( V_17 -> V_201 )
V_17 -> V_201 -> V_229 ( V_13 ,
V_220 , V_2 , & V_211 , V_222 ) ;
}
static void F_125 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_4 V_104 ,
struct V_221 * V_222 )
{
switch ( V_2 -> V_3 . V_4 . V_230 ) {
case V_231 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_232 . V_6 ) {
case V_233 :
case V_234 :
case V_235 :
F_126 ( V_13 , V_2 , V_104 , V_222 ) ;
break;
}
break;
case V_236 :
if ( F_1 ( V_2 ) )
F_127 ( V_13 , V_2 , V_104 ) ;
break;
}
}
void F_128 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_221 * V_222 ;
struct V_1 * V_2 ;
T_5 V_220 ;
V_222 = F_129 ( V_84 ) ;
V_2 = (struct V_1 * ) V_84 -> V_11 ;
V_220 = F_130 ( V_2 -> V_178 ) & V_237 ;
switch ( V_220 ) {
case V_218 :
case V_180 :
F_121 ( V_13 , V_220 , V_2 , V_84 -> V_104 ,
V_222 ) ;
break;
case V_238 :
F_115 ( V_13 , V_2 , V_84 -> V_104 ) ;
break;
case V_239 :
F_125 ( V_13 , V_2 , V_84 -> V_104 , V_222 ) ;
break;
}
}
void F_131 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( V_17 -> V_240 &&
F_33 ( V_77 ,
V_17 -> V_241 + F_132 ( V_17 -> V_101 . V_242 ) ) )
F_133 ( V_13 ) ;
if ( F_78 ( V_243 , & V_17 -> V_20 ) )
F_134 () ;
if ( F_78 ( V_244 , & V_17 -> V_20 ) )
F_135 () ;
if ( F_78 ( V_19 , & V_17 -> V_20 ) )
F_68 ( V_13 ) ;
if ( F_78 ( V_134 , & V_17 -> V_20 ) )
F_73 ( V_13 ) ;
if ( F_78 ( V_245 , & V_17 -> V_20 ) )
F_136 ( V_13 ) ;
}
void F_137 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_48 () ;
F_138 (sdata, &local->interfaces, list)
if ( F_139 ( & V_13 -> V_44 ) &&
F_140 ( V_13 ) )
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
F_51 () ;
}
void F_141 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
static T_2 V_246 [ V_82 ] = {} ;
F_142 ( & V_17 -> V_162 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_53 = true ;
V_17 -> V_247 = 0 ;
V_17 -> V_248 = 0 ;
V_17 -> V_249 = 0 ;
F_143 ( & V_17 -> V_250 , 0 ) ;
F_23 ( V_13 ) ;
V_17 -> V_241 = V_77 ;
V_17 -> V_251 = V_77 ;
if ( ! V_8 )
F_2 () ;
F_142 ( & V_17 -> V_168 ,
F_58 ,
( unsigned long ) V_13 ) ;
F_142 ( & V_17 -> V_138 ,
F_59 ,
( unsigned long ) V_13 ) ;
F_25 ( & V_17 -> V_252 . V_70 ) ;
F_144 ( & V_17 -> V_208 . V_209 ) ;
F_145 ( & V_17 -> V_253 ) ;
F_145 ( & V_17 -> V_254 ) ;
F_146 ( V_17 -> V_174 , NULL ) ;
F_147 ( & V_17 -> V_191 ) ;
V_13 -> V_44 . V_45 . V_183 = V_246 ;
}
