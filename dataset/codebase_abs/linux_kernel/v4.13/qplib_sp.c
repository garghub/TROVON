static bool F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = F_2 ( V_2 -> V_5 , V_6 ,
& V_4 ) ;
if ( V_3 )
return false ;
return ! ! ( V_4 & V_7 ) ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 V_11 ;
struct V_12 V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_1 V_18 = 0 ;
T_2 V_19 ;
T_3 * V_20 ;
int V_21 , V_3 = 0 ;
F_4 ( V_11 , V_22 , V_18 ) ;
V_15 = F_5 ( V_2 , sizeof( * V_17 ) ) ;
if ( ! V_15 ) {
F_6 ( & V_2 -> V_5 -> V_23 ,
L_1 ) ;
return - V_24 ;
}
V_17 = V_15 -> V_17 ;
V_11 . V_25 = sizeof( * V_17 ) / V_26 ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 , ( void * ) & V_13 ,
( void * ) V_15 , 0 ) ;
if ( V_3 )
goto V_27;
V_9 -> V_28 = F_8 ( V_17 -> V_28 ) ;
V_9 -> V_28 += 1 ;
V_9 -> V_29 =
V_17 -> V_29 > V_30 ?
V_30 : V_17 -> V_29 ;
V_9 -> V_31 =
V_17 -> V_31 > V_30 ?
V_30 : V_17 -> V_31 ;
V_9 -> V_32 = F_9 ( V_17 -> V_33 ) ;
V_9 -> V_32 -= V_34 ;
V_9 -> V_35 = V_17 -> V_36 ;
V_9 -> V_37 = F_8 ( V_17 -> V_37 ) ;
V_9 -> V_38 = F_8 ( V_17 -> V_39 ) ;
V_9 -> V_40 = V_9 -> V_35 ;
V_9 -> V_41 = F_8 ( V_17 -> V_41 ) ;
V_9 -> V_42 = F_8 ( V_17 -> V_42 ) ;
V_9 -> V_43 = F_10 ( V_17 -> V_43 ) ;
V_9 -> V_44 = 64 * 1024 ;
V_9 -> V_45 = F_8 ( V_17 -> V_46 ) ;
V_9 -> V_47 = F_8 ( V_17 -> V_47 ) ;
V_9 -> V_48 = F_8 ( V_17 -> V_48 ) ;
V_9 -> V_49 = V_17 -> V_49 ;
V_9 -> V_50 = F_9 ( V_17 -> V_50 ) ;
V_9 -> V_51 = F_8 ( V_17 -> V_52 ) - 1 ;
V_9 -> V_53 = V_17 -> V_54 ;
V_9 -> V_55 = F_8 ( V_17 -> V_56 ) ;
V_9 -> V_57 = F_8 ( V_17 -> V_57 ) ;
V_9 -> V_58 = ( V_17 -> V_59 + 1 ) * V_60 ;
V_9 -> V_61 = F_8 ( V_17 -> V_62 ) ;
F_11 ( V_9 -> V_63 , L_2 , sizeof( V_9 -> V_63 ) ) ;
for ( V_21 = 0 ; V_21 < V_64 / 4 ; V_21 ++ ) {
V_19 = F_8 ( V_17 -> V_65 [ V_21 ] ) ;
V_20 = ( T_3 * ) & V_19 ;
V_9 -> V_65 [ V_21 * 4 ] = * V_20 ;
V_9 -> V_65 [ V_21 * 4 + 1 ] = * ( ++ V_20 ) ;
V_9 -> V_65 [ V_21 * 4 + 2 ] = * ( ++ V_20 ) ;
V_9 -> V_65 [ V_21 * 4 + 3 ] = * ( ++ V_20 ) ;
}
V_9 -> V_66 = F_1 ( V_2 ) ;
V_27:
F_12 ( V_2 , V_15 ) ;
return V_3 ;
}
int F_13 ( struct V_67 * V_68 ,
struct V_69 * V_70 , int V_71 ,
struct V_72 * V_73 )
{
if ( V_71 > V_70 -> V_74 ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_3 ,
V_71 , V_70 -> V_74 ) ;
return - V_75 ;
}
memcpy ( V_73 , & V_70 -> V_76 [ V_71 ] , sizeof( * V_73 ) ) ;
return 0 ;
}
int F_14 ( struct V_69 * V_70 ,
struct V_72 * V_73 , bool V_77 )
{
struct V_67 * V_68 = F_15 ( V_70 ,
struct V_67 ,
V_70 ) ;
struct V_1 * V_2 = V_68 -> V_2 ;
int V_71 ;
if ( ! V_70 ) {
F_6 ( & V_68 -> V_5 -> V_23 , L_4 ) ;
return - V_75 ;
}
if ( ! V_70 -> V_78 ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_5 ) ;
return - V_24 ;
}
for ( V_71 = 0 ; V_71 < V_70 -> V_74 ; V_71 ++ ) {
if ( ! memcmp ( & V_70 -> V_76 [ V_71 ] , V_73 , sizeof( * V_73 ) ) )
break;
}
if ( V_71 == V_70 -> V_74 ) {
F_16 ( & V_68 -> V_5 -> V_23 , L_6 ) ;
return 0 ;
}
if ( V_77 ) {
struct V_79 V_11 ;
struct V_80 V_13 ;
T_1 V_18 = 0 ;
int V_3 ;
F_4 ( V_11 , V_81 , V_18 ) ;
if ( V_70 -> V_82 [ V_71 ] == 0xFFFF ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_7 ) ;
return - V_75 ;
}
V_11 . V_83 = F_17 ( V_70 -> V_82 [ V_71 ] ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 ,
( void * ) & V_13 , NULL , 0 ) ;
if ( V_3 )
return V_3 ;
}
memcpy ( & V_70 -> V_76 [ V_71 ] , & V_84 ,
sizeof( V_84 ) ) ;
V_70 -> V_78 -- ;
F_18 ( & V_68 -> V_5 -> V_23 ,
L_8 ,
V_71 , V_70 -> V_82 [ V_71 ] , V_70 -> V_78 ) ;
V_70 -> V_82 [ V_71 ] = ( T_1 ) - 1 ;
return 0 ;
}
int F_19 ( struct V_69 * V_70 ,
struct V_72 * V_73 , T_3 * V_85 , T_1 V_86 ,
bool V_77 , T_2 * V_71 )
{
struct V_67 * V_68 = F_15 ( V_70 ,
struct V_67 ,
V_70 ) ;
struct V_1 * V_2 = V_68 -> V_2 ;
int V_21 , V_87 ;
if ( ! V_70 ) {
F_6 ( & V_68 -> V_5 -> V_23 , L_4 ) ;
return - V_75 ;
}
if ( V_70 -> V_78 == V_70 -> V_74 ) {
F_6 ( & V_68 -> V_5 -> V_23 , L_9 ) ;
return - V_24 ;
}
V_87 = V_70 -> V_74 ;
for ( V_21 = 0 ; V_21 < V_70 -> V_74 ; V_21 ++ ) {
if ( ! memcmp ( & V_70 -> V_76 [ V_21 ] , V_73 , sizeof( * V_73 ) ) ) {
F_18 ( & V_68 -> V_5 -> V_23 ,
L_10 ,
V_21 ) ;
* V_71 = V_21 ;
return - V_88 ;
} else if ( ! memcmp ( & V_70 -> V_76 [ V_21 ] , & V_84 ,
sizeof( V_84 ) ) &&
V_87 == V_70 -> V_74 ) {
V_87 = V_21 ;
}
}
if ( V_87 == V_70 -> V_74 ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_11 ) ;
return - V_24 ;
}
if ( V_77 ) {
struct V_89 V_11 ;
struct V_90 V_13 ;
T_1 V_18 = 0 ;
T_2 V_91 [ 4 ] ;
T_1 V_92 [ 3 ] ;
int V_3 ;
F_4 ( V_11 , V_93 , V_18 ) ;
memcpy ( V_91 , V_73 -> V_94 , sizeof( struct V_72 ) ) ;
V_11 . V_73 [ 0 ] = F_20 ( V_91 [ 3 ] ) ;
V_11 . V_73 [ 1 ] = F_20 ( V_91 [ 2 ] ) ;
V_11 . V_73 [ 2 ] = F_20 ( V_91 [ 1 ] ) ;
V_11 . V_73 [ 3 ] = F_20 ( V_91 [ 0 ] ) ;
if ( V_86 != 0xFFFF )
V_11 . V_95 = F_17 ( ( V_86 &
V_96 ) |
V_97 |
V_98 ) ;
memcpy ( V_92 , V_85 , 6 ) ;
V_11 . V_99 [ 0 ] = F_21 ( V_92 [ 0 ] ) ;
V_11 . V_99 [ 1 ] = F_21 ( V_92 [ 1 ] ) ;
V_11 . V_99 [ 2 ] = F_21 ( V_92 [ 2 ] ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 ,
( void * ) & V_13 , NULL , 0 ) ;
if ( V_3 )
return V_3 ;
V_70 -> V_82 [ V_87 ] = F_8 ( V_13 . V_100 ) ;
}
memcpy ( & V_70 -> V_76 [ V_87 ] , V_73 , sizeof( * V_73 ) ) ;
V_70 -> V_78 ++ ;
F_18 ( & V_68 -> V_5 -> V_23 ,
L_12 ,
V_87 , V_70 -> V_82 [ V_87 ] , V_70 -> V_78 ) ;
* V_71 = V_87 ;
return 0 ;
}
int F_22 ( struct V_67 * V_68 ,
struct V_101 * V_102 , T_1 V_71 ,
T_1 * V_103 )
{
if ( V_71 == 0xFFFF ) {
* V_103 = 0xFFFF ;
return 0 ;
}
if ( V_71 > V_102 -> V_74 ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_13 ,
V_71 , V_102 -> V_74 ) ;
return - V_75 ;
}
memcpy ( V_103 , & V_102 -> V_76 [ V_71 ] , sizeof( * V_103 ) ) ;
return 0 ;
}
int F_23 ( struct V_67 * V_68 ,
struct V_101 * V_102 , T_1 * V_103 ,
bool V_77 )
{
int V_21 , V_3 = 0 ;
if ( ! V_102 ) {
F_6 ( & V_68 -> V_5 -> V_23 , L_14 ) ;
return - V_75 ;
}
if ( ! V_102 -> V_78 ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_15 ) ;
return - V_24 ;
}
for ( V_21 = 0 ; V_21 < V_102 -> V_74 ; V_21 ++ ) {
if ( ! memcmp ( & V_102 -> V_76 [ V_21 ] , V_103 , sizeof( * V_103 ) ) )
break;
}
if ( V_21 == V_102 -> V_74 ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_16 ,
* V_103 ) ;
return - V_24 ;
}
memset ( & V_102 -> V_76 [ V_21 ] , 0 , sizeof( * V_103 ) ) ;
V_102 -> V_78 -- ;
return V_3 ;
}
int F_24 ( struct V_67 * V_68 ,
struct V_101 * V_102 , T_1 * V_103 ,
bool V_77 )
{
int V_21 , V_87 , V_3 = 0 ;
if ( ! V_102 ) {
F_6 ( & V_68 -> V_5 -> V_23 , L_14 ) ;
return - V_75 ;
}
if ( V_102 -> V_78 == V_102 -> V_74 ) {
F_6 ( & V_68 -> V_5 -> V_23 , L_17 ) ;
return - V_24 ;
}
V_87 = V_102 -> V_74 ;
for ( V_21 = 0 ; V_21 < V_102 -> V_74 ; V_21 ++ ) {
if ( ! memcmp ( & V_102 -> V_76 [ V_21 ] , V_103 , sizeof( * V_103 ) ) )
return - V_88 ;
else if ( ! V_102 -> V_76 [ V_21 ] && V_87 == V_102 -> V_74 )
V_87 = V_21 ;
}
if ( V_87 == V_102 -> V_74 ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_18 ) ;
return - V_24 ;
}
memcpy ( & V_102 -> V_76 [ V_87 ] , V_103 , sizeof( * V_103 ) ) ;
V_102 -> V_78 ++ ;
return V_3 ;
}
int F_25 ( struct V_67 * V_68 , struct V_104 * V_105 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_106 V_11 ;
struct V_107 V_13 ;
T_1 V_18 = 0 ;
T_2 V_91 [ 4 ] ;
T_1 V_92 [ 3 ] ;
int V_3 ;
F_4 ( V_11 , V_108 , V_18 ) ;
memcpy ( V_91 , V_105 -> V_109 . V_94 , sizeof( struct V_72 ) ) ;
V_11 . V_109 [ 0 ] = F_26 ( V_91 [ 0 ] ) ;
V_11 . V_109 [ 1 ] = F_26 ( V_91 [ 1 ] ) ;
V_11 . V_109 [ 2 ] = F_26 ( V_91 [ 2 ] ) ;
V_11 . V_109 [ 3 ] = F_26 ( V_91 [ 3 ] ) ;
V_11 . type = V_105 -> V_110 ;
V_11 . V_111 = V_105 -> V_111 ;
V_11 . V_112 = F_17 ( V_68 -> V_70 . V_82 [ V_105 -> V_112 ] ) ;
V_11 . V_113 = F_26 ( ( V_105 -> V_114 &
V_115 ) |
V_116 ) ;
V_11 . V_117 = F_26 ( V_105 -> V_118 -> V_119 ) ;
V_11 . V_120 = V_105 -> V_120 ;
memcpy ( V_92 , V_105 -> V_121 , 6 ) ;
V_11 . V_122 [ 0 ] = F_17 ( V_92 [ 0 ] ) ;
V_11 . V_122 [ 1 ] = F_17 ( V_92 [ 1 ] ) ;
V_11 . V_122 [ 2 ] = F_17 ( V_92 [ 2 ] ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 , ( void * ) & V_13 ,
NULL , 1 ) ;
if ( V_3 )
return V_3 ;
V_105 -> V_119 = F_8 ( V_13 . V_100 ) ;
return 0 ;
}
int F_27 ( struct V_67 * V_68 , struct V_104 * V_105 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_123 V_11 ;
struct V_124 V_13 ;
T_1 V_18 = 0 ;
int V_3 ;
F_4 ( V_11 , V_125 , V_18 ) ;
V_11 . V_126 = F_26 ( V_105 -> V_119 ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 , ( void * ) & V_13 ,
NULL , 1 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
int F_28 ( struct V_67 * V_68 , struct V_127 * V_128 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_129 V_11 ;
struct V_130 V_13 ;
T_1 V_18 = 0 ;
int V_3 ;
if ( V_128 -> V_131 == 0xFFFFFFFF ) {
F_29 ( & V_68 -> V_5 -> V_23 ,
L_19 ) ;
return 0 ;
}
F_4 ( V_11 , V_132 , V_18 ) ;
V_11 . V_133 = V_128 -> type ;
if ( ( V_128 -> type == V_134 ) ||
( V_128 -> type == V_135 ) ||
( V_128 -> type == V_136 ) )
V_11 . V_137 = F_26 ( V_128 -> V_138 ) ;
else
V_11 . V_137 = F_26 ( V_128 -> V_131 ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 , ( void * ) & V_13 ,
NULL , 0 ) ;
if ( V_3 )
return V_3 ;
if ( V_128 -> V_139 . V_140 )
F_30 ( V_68 -> V_5 , & V_128 -> V_139 ) ;
return 0 ;
}
int F_31 ( struct V_67 * V_68 , struct V_127 * V_128 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_141 V_11 ;
struct V_142 V_13 ;
T_1 V_18 = 0 ;
unsigned long V_143 ;
int V_3 ;
F_4 ( V_11 , V_144 , V_18 ) ;
V_11 . V_117 = F_26 ( V_128 -> V_118 -> V_119 ) ;
V_11 . V_133 = V_128 -> type ;
if ( ( V_128 -> type == V_145 &&
V_128 -> V_146 & V_147 ) ||
V_128 -> type == V_135 ||
V_128 -> type == V_136 )
V_11 . V_148 = V_149 ;
V_143 = ( unsigned long ) V_128 ;
V_11 . V_150 = F_32 ( V_143 ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 ,
( void * ) & V_13 , NULL , 0 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_128 -> type == V_134 ) ||
( V_128 -> type == V_135 ) ||
( V_128 -> type == V_136 ) )
V_128 -> V_138 = F_8 ( V_13 . V_100 ) ;
else
V_128 -> V_131 = F_8 ( V_13 . V_100 ) ;
return 0 ;
}
int F_33 ( struct V_67 * V_68 , struct V_127 * V_128 ,
bool V_151 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_152 V_11 ;
struct V_153 V_13 ;
T_1 V_18 = 0 ;
int V_3 ;
F_4 ( V_11 , V_154 , V_18 ) ;
V_11 . V_131 = F_26 ( V_128 -> V_131 ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 ,
( void * ) & V_13 , NULL , V_151 ) ;
if ( V_3 )
return V_3 ;
if ( V_128 -> V_139 . V_140 ) {
V_128 -> V_155 = 0 ;
V_128 -> V_156 = 0 ;
F_30 ( V_68 -> V_5 , & V_128 -> V_139 ) ;
}
return 0 ;
}
int F_34 ( struct V_67 * V_68 , struct V_127 * V_157 ,
T_4 * V_158 , int V_159 , bool V_151 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_160 V_11 ;
struct V_161 V_13 ;
T_1 V_18 = 0 , V_162 ;
int V_163 , V_164 , V_21 , V_3 ;
T_5 * * V_165 ;
T_2 V_166 ;
if ( V_159 ) {
V_163 = F_35 ( V_159 ) ;
V_164 = V_163 >> V_167 ;
if ( ! V_164 )
V_164 ++ ;
if ( V_164 > V_168 ) {
F_6 ( & V_68 -> V_5 -> V_23 , L_20 ) ;
F_6 ( & V_68 -> V_5 -> V_23 ,
L_21 ,
V_164 , V_168 ) ;
return - V_24 ;
}
if ( V_157 -> V_139 . V_140 )
F_30 ( V_68 -> V_5 , & V_157 -> V_139 ) ;
V_157 -> V_139 . V_140 = V_164 ;
V_3 = F_36 ( V_68 -> V_5 , & V_157 -> V_139 , NULL , 0 ,
& V_157 -> V_139 . V_140 ,
V_60 , 0 , V_60 ,
V_169 ) ;
if ( V_3 ) {
F_6 ( & V_68 -> V_5 -> V_23 ,
L_22 ) ;
return - V_24 ;
}
V_165 = ( T_5 * * ) V_157 -> V_139 . V_165 ;
for ( V_21 = 0 ; V_21 < V_159 ; V_21 ++ )
V_165 [ F_37 ( V_21 ) ] [ F_38 ( V_21 ) ] =
( V_158 [ V_21 ] & V_170 ) | V_171 ;
}
F_4 ( V_11 , V_172 , V_18 ) ;
if ( V_157 -> V_139 . V_162 == V_173 ) {
V_162 = 0 ;
V_11 . V_174 = 0 ;
V_166 = V_60 ;
} else {
V_162 = V_157 -> V_139 . V_162 + 1 ;
V_11 . V_174 = F_32 ( V_157 -> V_139 . V_174 [ V_175 ] . V_176 [ 0 ] ) ;
V_166 = V_157 -> V_139 . V_174 [ V_175 ] . V_166 ;
}
V_11 . V_177 = ( V_162 << V_178 ) |
( ( F_39 ( V_166 ) <<
V_179 ) &
V_180 ) ;
V_11 . V_148 = ( V_157 -> V_146 & 0xFFFF ) ;
V_11 . V_155 = F_32 ( V_157 -> V_155 ) ;
V_11 . V_137 = F_26 ( V_157 -> V_131 ) ;
V_11 . V_181 = F_32 ( V_157 -> V_156 ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 ,
( void * ) & V_13 , NULL , V_151 ) ;
if ( V_3 )
goto V_182;
return 0 ;
V_182:
if ( V_157 -> V_139 . V_140 )
F_30 ( V_68 -> V_5 , & V_157 -> V_139 ) ;
return V_3 ;
}
int F_40 ( struct V_67 * V_68 ,
struct V_183 * V_184 ,
int V_185 )
{
int V_163 , V_164 , V_3 ;
V_163 = F_35 ( V_185 ) ;
V_164 = V_163 >> V_167 ;
if ( ! V_164 )
V_164 ++ ;
if ( V_164 > V_168 )
return - V_24 ;
V_184 -> V_139 . V_140 = V_164 ;
V_3 = F_36 ( V_68 -> V_5 , & V_184 -> V_139 , NULL , 0 ,
& V_184 -> V_139 . V_140 , V_60 , 0 ,
V_60 , V_169 ) ;
if ( ! V_3 )
V_184 -> V_185 = V_163 ;
return V_3 ;
}
int F_41 ( struct V_67 * V_68 ,
struct V_183 * V_184 )
{
F_30 ( V_68 -> V_5 , & V_184 -> V_139 ) ;
return 0 ;
}
int F_42 ( struct V_67 * V_68 , T_1 * V_186 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_187 V_11 ;
struct V_188 V_13 ;
T_1 V_18 = 0 ;
int V_3 = 0 ;
F_4 ( V_11 , V_189 , V_18 ) ;
V_11 . V_190 = F_17 ( V_186 [ 0 ] ) ;
V_11 . V_191 = F_17 ( V_186 [ 1 ] ) ;
V_3 = F_7 ( V_2 , ( void * ) & V_11 ,
( void * ) & V_13 , NULL , 0 ) ;
return 0 ;
}
