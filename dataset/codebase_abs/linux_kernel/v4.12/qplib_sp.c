int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
T_1 V_13 = 0 ;
T_2 V_14 ;
T_3 * V_15 ;
int V_16 , V_17 = 0 ;
F_2 ( V_6 , V_18 , V_13 ) ;
V_10 = F_3 ( V_2 , sizeof( * V_12 ) ) ;
if ( ! V_10 ) {
F_4 ( & V_2 -> V_19 -> V_20 ,
L_1 ) ;
return - V_21 ;
}
V_12 = V_10 -> V_12 ;
V_6 . V_22 = sizeof( * V_12 ) / V_23 ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 , ( void * ) & V_8 ,
( void * ) V_10 , 0 ) ;
if ( V_17 )
goto V_24;
V_4 -> V_25 = F_6 ( V_12 -> V_25 ) ;
V_4 -> V_26 =
V_12 -> V_26 > V_27 ?
V_27 : V_12 -> V_26 ;
V_4 -> V_28 =
V_12 -> V_28 > V_27 ?
V_27 : V_12 -> V_28 ;
V_4 -> V_29 = F_7 ( V_12 -> V_30 ) ;
V_4 -> V_29 -= V_31 ;
V_4 -> V_32 = V_12 -> V_33 ;
V_4 -> V_34 = F_6 ( V_12 -> V_34 ) ;
V_4 -> V_35 = F_6 ( V_12 -> V_36 ) ;
V_4 -> V_37 = V_4 -> V_32 ;
V_4 -> V_38 = F_6 ( V_12 -> V_38 ) ;
V_4 -> V_39 = F_6 ( V_12 -> V_39 ) ;
V_4 -> V_40 = F_8 ( V_12 -> V_40 ) ;
V_4 -> V_41 = 64 * 1024 ;
V_4 -> V_42 = F_6 ( V_12 -> V_43 ) ;
V_4 -> V_44 = F_6 ( V_12 -> V_44 ) ;
V_4 -> V_45 = F_6 ( V_12 -> V_45 ) ;
V_4 -> V_46 = V_12 -> V_46 ;
V_4 -> V_47 = F_7 ( V_12 -> V_47 ) ;
V_4 -> V_48 = F_6 ( V_12 -> V_49 ) - 1 ;
V_4 -> V_50 = V_12 -> V_51 ;
V_4 -> V_52 = F_6 ( V_12 -> V_53 ) ;
V_4 -> V_54 = F_6 ( V_12 -> V_54 ) ;
V_4 -> V_55 = ( V_12 -> V_56 + 1 ) * V_57 ;
V_4 -> V_58 = F_6 ( V_12 -> V_59 ) ;
F_9 ( V_4 -> V_60 , L_2 , sizeof( V_4 -> V_60 ) ) ;
for ( V_16 = 0 ; V_16 < V_61 / 4 ; V_16 ++ ) {
V_14 = F_6 ( V_12 -> V_62 [ V_16 ] ) ;
V_15 = ( T_3 * ) & V_14 ;
V_4 -> V_62 [ V_16 * 4 ] = * V_15 ;
V_4 -> V_62 [ V_16 * 4 + 1 ] = * ( ++ V_15 ) ;
V_4 -> V_62 [ V_16 * 4 + 2 ] = * ( ++ V_15 ) ;
V_4 -> V_62 [ V_16 * 4 + 3 ] = * ( ++ V_15 ) ;
}
V_24:
F_10 ( V_2 , V_10 ) ;
return V_17 ;
}
int F_11 ( struct V_63 * V_64 ,
struct V_65 * V_66 , int V_67 ,
struct V_68 * V_69 )
{
if ( V_67 > V_66 -> V_70 ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_3 ,
V_67 , V_66 -> V_70 ) ;
return - V_71 ;
}
memcpy ( V_69 , & V_66 -> V_72 [ V_67 ] , sizeof( * V_69 ) ) ;
return 0 ;
}
int F_12 ( struct V_65 * V_66 ,
struct V_68 * V_69 , bool V_73 )
{
struct V_63 * V_64 = F_13 ( V_66 ,
struct V_63 ,
V_66 ) ;
struct V_1 * V_2 = V_64 -> V_2 ;
int V_67 ;
if ( ! V_66 ) {
F_4 ( & V_64 -> V_19 -> V_20 , L_4 ) ;
return - V_71 ;
}
if ( ! V_66 -> V_74 ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_5 ) ;
return - V_21 ;
}
for ( V_67 = 0 ; V_67 < V_66 -> V_70 ; V_67 ++ ) {
if ( ! memcmp ( & V_66 -> V_72 [ V_67 ] , V_69 , sizeof( * V_69 ) ) )
break;
}
if ( V_67 == V_66 -> V_70 ) {
F_14 ( & V_64 -> V_19 -> V_20 , L_6 ) ;
return 0 ;
}
if ( V_73 ) {
struct V_75 V_6 ;
struct V_76 V_8 ;
T_1 V_13 = 0 ;
int V_17 ;
F_2 ( V_6 , V_77 , V_13 ) ;
if ( V_66 -> V_78 [ V_67 ] == 0xFFFF ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_7 ) ;
return - V_71 ;
}
V_6 . V_79 = F_15 ( V_66 -> V_78 [ V_67 ] ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 ,
( void * ) & V_8 , NULL , 0 ) ;
if ( V_17 )
return V_17 ;
}
memcpy ( & V_66 -> V_72 [ V_67 ] , & V_80 ,
sizeof( V_80 ) ) ;
V_66 -> V_74 -- ;
F_16 ( & V_64 -> V_19 -> V_20 ,
L_8 ,
V_67 , V_66 -> V_78 [ V_67 ] , V_66 -> V_74 ) ;
V_66 -> V_78 [ V_67 ] = ( T_1 ) - 1 ;
return 0 ;
}
int F_17 ( struct V_65 * V_66 ,
struct V_68 * V_69 , T_3 * V_81 , T_1 V_82 ,
bool V_73 , T_2 * V_67 )
{
struct V_63 * V_64 = F_13 ( V_66 ,
struct V_63 ,
V_66 ) ;
struct V_1 * V_2 = V_64 -> V_2 ;
int V_16 , V_83 ;
if ( ! V_66 ) {
F_4 ( & V_64 -> V_19 -> V_20 , L_4 ) ;
return - V_71 ;
}
if ( V_66 -> V_74 == V_66 -> V_70 ) {
F_4 ( & V_64 -> V_19 -> V_20 , L_9 ) ;
return - V_21 ;
}
V_83 = V_66 -> V_70 ;
for ( V_16 = 0 ; V_16 < V_66 -> V_70 ; V_16 ++ ) {
if ( ! memcmp ( & V_66 -> V_72 [ V_16 ] , V_69 , sizeof( * V_69 ) ) ) {
F_16 ( & V_64 -> V_19 -> V_20 ,
L_10 ,
V_16 ) ;
* V_67 = V_16 ;
return - V_84 ;
} else if ( ! memcmp ( & V_66 -> V_72 [ V_16 ] , & V_80 ,
sizeof( V_80 ) ) &&
V_83 == V_66 -> V_70 ) {
V_83 = V_16 ;
}
}
if ( V_83 == V_66 -> V_70 ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_11 ) ;
return - V_21 ;
}
if ( V_73 ) {
struct V_85 V_6 ;
struct V_86 V_8 ;
T_1 V_13 = 0 ;
T_2 V_87 [ 4 ] ;
T_1 V_88 [ 3 ] ;
int V_17 ;
F_2 ( V_6 , V_89 , V_13 ) ;
memcpy ( V_87 , V_69 -> V_90 , sizeof( struct V_68 ) ) ;
V_6 . V_69 [ 0 ] = F_18 ( V_87 [ 3 ] ) ;
V_6 . V_69 [ 1 ] = F_18 ( V_87 [ 2 ] ) ;
V_6 . V_69 [ 2 ] = F_18 ( V_87 [ 1 ] ) ;
V_6 . V_69 [ 3 ] = F_18 ( V_87 [ 0 ] ) ;
if ( V_82 != 0xFFFF )
V_6 . V_91 = F_15 ( ( V_82 &
V_92 ) |
V_93 |
V_94 ) ;
memcpy ( V_88 , V_81 , 6 ) ;
V_6 . V_95 [ 0 ] = F_19 ( V_88 [ 0 ] ) ;
V_6 . V_95 [ 1 ] = F_19 ( V_88 [ 1 ] ) ;
V_6 . V_95 [ 2 ] = F_19 ( V_88 [ 2 ] ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 ,
( void * ) & V_8 , NULL , 0 ) ;
if ( V_17 )
return V_17 ;
V_66 -> V_78 [ V_83 ] = F_6 ( V_8 . V_96 ) ;
}
memcpy ( & V_66 -> V_72 [ V_83 ] , V_69 , sizeof( * V_69 ) ) ;
V_66 -> V_74 ++ ;
F_16 ( & V_64 -> V_19 -> V_20 ,
L_12 ,
V_83 , V_66 -> V_78 [ V_83 ] , V_66 -> V_74 ) ;
* V_67 = V_83 ;
return 0 ;
}
int F_20 ( struct V_63 * V_64 ,
struct V_97 * V_98 , T_1 V_67 ,
T_1 * V_99 )
{
if ( V_67 == 0xFFFF ) {
* V_99 = 0xFFFF ;
return 0 ;
}
if ( V_67 > V_98 -> V_70 ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_13 ,
V_67 , V_98 -> V_70 ) ;
return - V_71 ;
}
memcpy ( V_99 , & V_98 -> V_72 [ V_67 ] , sizeof( * V_99 ) ) ;
return 0 ;
}
int F_21 ( struct V_63 * V_64 ,
struct V_97 * V_98 , T_1 * V_99 ,
bool V_73 )
{
int V_16 , V_17 = 0 ;
if ( ! V_98 ) {
F_4 ( & V_64 -> V_19 -> V_20 , L_14 ) ;
return - V_71 ;
}
if ( ! V_98 -> V_74 ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_15 ) ;
return - V_21 ;
}
for ( V_16 = 0 ; V_16 < V_98 -> V_70 ; V_16 ++ ) {
if ( ! memcmp ( & V_98 -> V_72 [ V_16 ] , V_99 , sizeof( * V_99 ) ) )
break;
}
if ( V_16 == V_98 -> V_70 ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_16 ,
* V_99 ) ;
return - V_21 ;
}
memset ( & V_98 -> V_72 [ V_16 ] , 0 , sizeof( * V_99 ) ) ;
V_98 -> V_74 -- ;
return V_17 ;
}
int F_22 ( struct V_63 * V_64 ,
struct V_97 * V_98 , T_1 * V_99 ,
bool V_73 )
{
int V_16 , V_83 , V_17 = 0 ;
if ( ! V_98 ) {
F_4 ( & V_64 -> V_19 -> V_20 , L_14 ) ;
return - V_71 ;
}
if ( V_98 -> V_74 == V_98 -> V_70 ) {
F_4 ( & V_64 -> V_19 -> V_20 , L_17 ) ;
return - V_21 ;
}
V_83 = V_98 -> V_70 ;
for ( V_16 = 0 ; V_16 < V_98 -> V_70 ; V_16 ++ ) {
if ( ! memcmp ( & V_98 -> V_72 [ V_16 ] , V_99 , sizeof( * V_99 ) ) )
return - V_84 ;
else if ( ! V_98 -> V_72 [ V_16 ] && V_83 == V_98 -> V_70 )
V_83 = V_16 ;
}
if ( V_83 == V_98 -> V_70 ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_18 ) ;
return - V_21 ;
}
memcpy ( & V_98 -> V_72 [ V_83 ] , V_99 , sizeof( * V_99 ) ) ;
V_98 -> V_74 ++ ;
return V_17 ;
}
int F_23 ( struct V_63 * V_64 , struct V_100 * V_101 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_102 V_6 ;
struct V_103 V_8 ;
T_1 V_13 = 0 ;
T_2 V_87 [ 4 ] ;
T_1 V_88 [ 3 ] ;
int V_17 ;
F_2 ( V_6 , V_104 , V_13 ) ;
memcpy ( V_87 , V_101 -> V_105 . V_90 , sizeof( struct V_68 ) ) ;
V_6 . V_105 [ 0 ] = F_24 ( V_87 [ 0 ] ) ;
V_6 . V_105 [ 1 ] = F_24 ( V_87 [ 1 ] ) ;
V_6 . V_105 [ 2 ] = F_24 ( V_87 [ 2 ] ) ;
V_6 . V_105 [ 3 ] = F_24 ( V_87 [ 3 ] ) ;
V_6 . type = V_101 -> V_106 ;
V_6 . V_107 = V_101 -> V_107 ;
V_6 . V_108 = F_15 ( V_64 -> V_66 . V_78 [ V_101 -> V_108 ] ) ;
V_6 . V_109 = F_24 ( ( V_101 -> V_110 &
V_111 ) |
V_112 ) ;
V_6 . V_113 = F_24 ( V_101 -> V_114 -> V_115 ) ;
V_6 . V_116 = V_101 -> V_116 ;
memcpy ( V_88 , V_101 -> V_117 , 6 ) ;
V_6 . V_118 [ 0 ] = F_15 ( V_88 [ 0 ] ) ;
V_6 . V_118 [ 1 ] = F_15 ( V_88 [ 1 ] ) ;
V_6 . V_118 [ 2 ] = F_15 ( V_88 [ 2 ] ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 , ( void * ) & V_8 ,
NULL , 1 ) ;
if ( V_17 )
return V_17 ;
V_101 -> V_115 = F_6 ( V_8 . V_96 ) ;
return 0 ;
}
int F_25 ( struct V_63 * V_64 , struct V_100 * V_101 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_119 V_6 ;
struct V_120 V_8 ;
T_1 V_13 = 0 ;
int V_17 ;
F_2 ( V_6 , V_121 , V_13 ) ;
V_6 . V_122 = F_24 ( V_101 -> V_115 ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 , ( void * ) & V_8 ,
NULL , 1 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
int F_26 ( struct V_63 * V_64 , struct V_123 * V_124 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_125 V_6 ;
struct V_126 V_8 ;
T_1 V_13 = 0 ;
int V_17 ;
if ( V_124 -> V_127 == 0xFFFFFFFF ) {
F_27 ( & V_64 -> V_19 -> V_20 ,
L_19 ) ;
return 0 ;
}
F_2 ( V_6 , V_128 , V_13 ) ;
V_6 . V_129 = V_124 -> type ;
if ( ( V_124 -> type == V_130 ) ||
( V_124 -> type == V_131 ) ||
( V_124 -> type == V_132 ) )
V_6 . V_133 = F_24 ( V_124 -> V_134 ) ;
else
V_6 . V_133 = F_24 ( V_124 -> V_127 ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 , ( void * ) & V_8 ,
NULL , 0 ) ;
if ( V_17 )
return V_17 ;
if ( V_124 -> V_135 . V_136 )
F_28 ( V_64 -> V_19 , & V_124 -> V_135 ) ;
return 0 ;
}
int F_29 ( struct V_63 * V_64 , struct V_123 * V_124 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_137 V_6 ;
struct V_138 V_8 ;
T_1 V_13 = 0 ;
unsigned long V_139 ;
int V_17 ;
F_2 ( V_6 , V_140 , V_13 ) ;
V_6 . V_113 = F_24 ( V_124 -> V_114 -> V_115 ) ;
V_6 . V_129 = V_124 -> type ;
if ( ( V_124 -> type == V_141 &&
V_124 -> V_142 & V_143 ) ||
V_124 -> type == V_131 ||
V_124 -> type == V_132 )
V_6 . V_144 = V_145 ;
V_139 = ( unsigned long ) V_124 ;
V_6 . V_146 = F_30 ( V_139 ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 ,
( void * ) & V_8 , NULL , 0 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_124 -> type == V_130 ) ||
( V_124 -> type == V_131 ) ||
( V_124 -> type == V_132 ) )
V_124 -> V_134 = F_6 ( V_8 . V_96 ) ;
else
V_124 -> V_127 = F_6 ( V_8 . V_96 ) ;
return 0 ;
}
int F_31 ( struct V_63 * V_64 , struct V_123 * V_124 ,
bool V_147 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_148 V_6 ;
struct V_149 V_8 ;
T_1 V_13 = 0 ;
int V_17 ;
F_2 ( V_6 , V_150 , V_13 ) ;
V_6 . V_127 = F_24 ( V_124 -> V_127 ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 ,
( void * ) & V_8 , NULL , V_147 ) ;
if ( V_17 )
return V_17 ;
if ( V_124 -> V_135 . V_136 ) {
V_124 -> V_151 = 0 ;
V_124 -> V_152 = 0 ;
F_28 ( V_64 -> V_19 , & V_124 -> V_135 ) ;
}
return 0 ;
}
int F_32 ( struct V_63 * V_64 , struct V_123 * V_153 ,
T_4 * V_154 , int V_155 , bool V_147 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_156 V_6 ;
struct V_157 V_8 ;
T_1 V_13 = 0 , V_158 ;
int V_159 , V_160 , V_16 , V_17 ;
T_5 * * V_161 ;
T_2 V_162 ;
if ( V_155 ) {
V_159 = F_33 ( V_155 ) ;
V_160 = V_159 >> V_163 ;
if ( ! V_160 )
V_160 ++ ;
if ( V_160 > V_164 ) {
F_4 ( & V_64 -> V_19 -> V_20 , L_20 ) ;
F_4 ( & V_64 -> V_19 -> V_20 ,
L_21 ,
V_160 , V_164 ) ;
return - V_21 ;
}
if ( V_153 -> V_135 . V_136 )
F_28 ( V_64 -> V_19 , & V_153 -> V_135 ) ;
V_153 -> V_135 . V_136 = V_160 ;
V_17 = F_34 ( V_64 -> V_19 , & V_153 -> V_135 , NULL , 0 ,
& V_153 -> V_135 . V_136 ,
V_57 , 0 , V_57 ,
V_165 ) ;
if ( V_17 ) {
F_4 ( & V_64 -> V_19 -> V_20 ,
L_22 ) ;
return - V_21 ;
}
V_161 = ( T_5 * * ) V_153 -> V_135 . V_161 ;
for ( V_16 = 0 ; V_16 < V_155 ; V_16 ++ )
V_161 [ F_35 ( V_16 ) ] [ F_36 ( V_16 ) ] =
( V_154 [ V_16 ] & V_166 ) | V_167 ;
}
F_2 ( V_6 , V_168 , V_13 ) ;
if ( V_153 -> V_135 . V_158 == V_169 ) {
V_158 = 0 ;
V_6 . V_170 = 0 ;
V_162 = V_57 ;
} else {
V_158 = V_153 -> V_135 . V_158 + 1 ;
V_6 . V_170 = F_30 ( V_153 -> V_135 . V_170 [ V_171 ] . V_172 [ 0 ] ) ;
V_162 = V_153 -> V_135 . V_170 [ V_171 ] . V_162 ;
}
V_6 . V_173 = ( V_158 << V_174 ) |
( ( F_37 ( V_162 ) <<
V_175 ) &
V_176 ) ;
V_6 . V_144 = ( V_153 -> V_142 & 0xFFFF ) ;
V_6 . V_151 = F_30 ( V_153 -> V_151 ) ;
V_6 . V_133 = F_24 ( V_153 -> V_127 ) ;
V_6 . V_177 = F_30 ( V_153 -> V_152 ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 ,
( void * ) & V_8 , NULL , V_147 ) ;
if ( V_17 )
goto V_178;
return 0 ;
V_178:
if ( V_153 -> V_135 . V_136 )
F_28 ( V_64 -> V_19 , & V_153 -> V_135 ) ;
return V_17 ;
}
int F_38 ( struct V_63 * V_64 ,
struct V_179 * V_180 ,
int V_181 )
{
int V_159 , V_160 , V_17 ;
V_159 = F_33 ( V_181 ) ;
V_160 = V_159 >> V_163 ;
if ( ! V_160 )
V_160 ++ ;
if ( V_160 > V_164 )
return - V_21 ;
V_180 -> V_135 . V_136 = V_160 ;
V_17 = F_34 ( V_64 -> V_19 , & V_180 -> V_135 , NULL , 0 ,
& V_180 -> V_135 . V_136 , V_57 , 0 ,
V_57 , V_165 ) ;
if ( ! V_17 )
V_180 -> V_181 = V_159 ;
return V_17 ;
}
int F_39 ( struct V_63 * V_64 ,
struct V_179 * V_180 )
{
F_28 ( V_64 -> V_19 , & V_180 -> V_135 ) ;
return 0 ;
}
int F_40 ( struct V_63 * V_64 , T_1 * V_182 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_183 V_6 ;
struct V_184 V_8 ;
T_1 V_13 = 0 ;
int V_17 = 0 ;
F_2 ( V_6 , V_185 , V_13 ) ;
V_6 . V_186 = F_15 ( V_182 [ 0 ] ) ;
V_6 . V_187 = F_15 ( V_182 [ 1 ] ) ;
V_17 = F_5 ( V_2 , ( void * ) & V_6 ,
( void * ) & V_8 , NULL , 0 ) ;
return 0 ;
}
