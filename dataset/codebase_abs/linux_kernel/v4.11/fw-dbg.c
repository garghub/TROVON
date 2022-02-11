static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
T_1 * V_5 = ( void * ) ( * V_4 ) -> V_6 ;
unsigned long V_7 ;
int V_8 ;
if ( ! F_2 ( V_2 -> V_9 , & V_7 ) )
return;
( * V_4 ) -> type = F_3 ( V_10 ) ;
( * V_4 ) -> V_11 = F_3 ( V_12 ) ;
for ( V_8 = 0 ; V_8 < V_12 ; V_8 ++ ) {
T_2 V_13 = V_14 ;
V_13 |= V_8 << V_15 ;
F_4 ( V_2 -> V_9 , V_16 , V_13 ) ;
* V_5 = ( T_1 ) F_5 ( V_2 -> V_9 , V_17 ) ;
V_5 ++ ;
}
* V_4 = F_6 ( * V_4 ) ;
F_7 ( V_2 -> V_9 , & V_7 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_18 * V_19 ;
T_2 * V_20 ;
T_2 V_21 ;
unsigned long V_7 ;
int V_8 , V_22 ;
if ( ! F_2 ( V_2 -> V_9 , & V_7 ) )
return;
for ( V_8 = 0 ; V_8 < F_9 ( V_2 -> V_23 . V_24 ) ; V_8 ++ ) {
T_2 V_25 = V_26 * V_8 ;
V_19 = ( void * ) ( * V_4 ) -> V_6 ;
V_20 = ( void * ) V_19 -> V_6 ;
V_21 = V_2 -> V_23 . V_24 [ V_8 ] ;
if ( V_21 == 0 )
continue;
( * V_4 ) -> type = F_3 ( V_27 ) ;
( * V_4 ) -> V_11 = F_3 ( V_21 + sizeof( * V_19 ) ) ;
V_19 -> V_28 = F_3 ( V_8 ) ;
V_19 -> V_29 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_30 +
V_25 ) ) ;
V_19 -> V_31 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_32 +
V_25 ) ) ;
V_19 -> V_33 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_34 +
V_25 ) ) ;
V_19 -> V_35 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_36 +
V_25 ) ) ;
V_19 -> V_37 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_38 +
V_25 ) ) ;
F_11 ( V_2 -> V_9 ,
V_38 + V_25 , 0x1 ) ;
F_11 ( V_2 -> V_9 ,
V_39 + V_25 , 0x1 ) ;
F_11 ( V_2 -> V_9 ,
V_40 + V_25 ,
0x0 ) ;
V_21 /= sizeof( T_2 ) ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
V_20 [ V_22 ] = F_10 ( V_2 -> V_9 ,
V_41 +
V_25 ) ;
* V_4 = F_6 ( * V_4 ) ;
}
for ( V_8 = 0 ; V_8 < F_9 ( V_2 -> V_23 . V_42 ) ; V_8 ++ ) {
F_11 ( V_2 -> V_9 , V_43 , V_8 ) ;
V_19 = ( void * ) ( * V_4 ) -> V_6 ;
V_20 = ( void * ) V_19 -> V_6 ;
V_21 = V_2 -> V_23 . V_42 [ V_8 ] ;
if ( V_21 == 0 )
continue;
( * V_4 ) -> type = F_3 ( V_44 ) ;
( * V_4 ) -> V_11 = F_3 ( V_21 + sizeof( * V_19 ) ) ;
V_19 -> V_28 = F_3 ( V_8 ) ;
V_19 -> V_29 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_45 ) ) ;
V_19 -> V_31 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_46 ) ) ;
V_19 -> V_33 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_47 ) ) ;
V_19 -> V_35 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_48 ) ) ;
V_19 -> V_37 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_49 ) ) ;
F_11 ( V_2 -> V_9 , V_50 ,
V_46 ) ;
F_10 ( V_2 -> V_9 , V_51 ) ;
V_21 /= sizeof( T_2 ) ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
V_20 [ V_22 ] = F_10 ( V_2 -> V_9 ,
V_51 ) ;
* V_4 = F_6 ( * V_4 ) ;
}
if ( F_12 ( & V_2 -> V_52 -> V_53 ,
V_54 ) ) {
for ( V_8 = 0 ;
V_8 < F_9 ( V_2 -> V_23 . V_55 ) ;
V_8 ++ ) {
V_19 = ( void * ) ( * V_4 ) -> V_6 ;
V_20 = ( void * ) V_19 -> V_6 ;
V_21 = V_2 -> V_23 . V_55 [ V_8 ] ;
if ( V_21 == 0 )
continue;
( * V_4 ) -> type =
F_3 ( V_56 ) ;
( * V_4 ) -> V_11 =
F_3 ( V_21 + sizeof( * V_19 ) ) ;
V_19 -> V_28 = F_3 ( V_8 ) ;
F_11 ( V_2 -> V_9 , V_57 , V_8 +
F_9 ( V_2 -> V_23 . V_42 ) ) ;
V_19 -> V_29 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_58 ) ) ;
V_19 -> V_31 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_59 ) ) ;
V_19 -> V_33 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_60 ) ) ;
V_19 -> V_35 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_61 ) ) ;
V_19 -> V_37 =
F_3 ( F_10 ( V_2 -> V_9 ,
V_62 ) ) ;
F_11 ( V_2 -> V_9 ,
V_63 ,
V_59 ) ;
F_10 ( V_2 -> V_9 ,
V_64 ) ;
V_21 /= sizeof( T_2 ) ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
V_20 [ V_22 ] =
F_10 ( V_2 -> V_9 ,
V_64 ) ;
* V_4 = F_6 ( * V_4 ) ;
}
}
F_7 ( V_2 -> V_9 , & V_7 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_65 == & V_66 )
return;
F_14 ( V_2 -> V_65 ) ;
V_2 -> V_65 = NULL ;
}
static void F_15 ( struct V_67 * V_9 , T_2 V_68 ,
T_2 V_69 , T_3 * V_6 )
{
T_2 V_8 ;
for ( V_8 = 0 ; V_8 < V_69 ; V_8 += 4 )
* V_6 ++ = F_3 ( F_5 ( V_9 , V_68 + V_8 ) ) ;
}
static bool F_16 ( struct V_67 * V_9 , T_2 V_68 ,
T_2 V_69 , T_3 * V_6 )
{
unsigned long V_7 ;
bool V_70 = false ;
if ( F_2 ( V_9 , & V_7 ) ) {
V_70 = true ;
F_15 ( V_9 , V_68 , V_69 , V_6 ) ;
F_7 ( V_9 , & V_7 ) ;
}
return V_70 ;
}
static void F_17 ( struct V_67 * V_9 ,
struct V_3 * * V_6 ,
const struct V_71 * V_72 ,
T_2 V_73 )
{
struct V_74 * V_75 ;
unsigned long V_7 ;
T_2 V_8 ;
if ( ! F_2 ( V_9 , & V_7 ) )
return;
for ( V_8 = 0 ; V_8 < V_73 ; V_8 ++ ) {
int V_76 = V_72 [ V_8 ] . V_77 -
V_72 [ V_8 ] . V_68 + 4 ;
( * V_6 ) -> type = F_3 ( V_78 ) ;
( * V_6 ) -> V_11 = F_3 ( sizeof( * V_75 ) +
V_76 ) ;
V_75 = ( void * ) ( * V_6 ) -> V_6 ;
V_75 -> V_79 = F_3 ( V_72 [ V_8 ] . V_68 ) ;
F_15 ( V_9 , V_72 [ V_8 ] . V_68 ,
V_72 [ V_8 ] . V_77 -
V_72 [ V_8 ] . V_68 + 4 ,
( void * ) V_75 -> V_6 ) ;
* V_6 = F_6 ( * V_6 ) ;
}
F_7 ( V_9 , & V_7 ) ;
}
static struct V_80 * F_18 ( int V_81 )
{
int V_82 , V_83 , V_8 ;
struct V_84 * V_85 ;
struct V_80 * V_86 ;
struct V_80 * V_87 ;
V_83 = F_19 ( V_81 , V_88 ) ;
V_87 = F_20 ( V_83 , sizeof( * V_87 ) , V_89 ) ;
if ( ! V_87 )
return NULL ;
F_21 ( V_87 , V_83 ) ;
V_86 = V_87 ;
F_22 (table, iter, sg_nents(table), i) {
V_85 = F_23 ( V_89 ) ;
if ( ! V_85 ) {
V_86 = V_87 ;
F_22 (table, iter, sg_nents(table), i) {
V_85 = F_24 ( V_86 ) ;
if ( V_85 )
F_25 ( V_85 ) ;
}
return NULL ;
}
V_82 = F_26 ( int , V_81 , V_88 ) ;
V_81 -= V_88 ;
F_27 ( V_86 , V_85 , V_82 , 0 ) ;
}
return V_87 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
struct V_3 * V_4 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_80 * V_100 ;
T_2 V_101 , V_102 ;
const struct V_103 * V_104 = V_2 -> V_52 -> V_105 ;
T_2 V_106 , V_107 = 0 , V_108 = 0 , V_109 = 0 ;
T_2 V_110 = V_2 -> V_52 -> V_111 ? 0 : V_2 -> V_112 -> V_110 ;
T_2 V_113 = V_2 -> V_52 -> V_111 ? 0 : V_2 -> V_112 -> V_114 ;
bool V_115 = false ;
int V_8 ;
if ( ! V_116 &&
! V_2 -> V_9 -> V_117 )
return;
F_29 ( & V_2 -> V_118 ) ;
if ( F_30 ( V_119 , & V_2 -> V_9 -> V_120 ) ) {
F_31 ( V_2 , L_1 ) ;
goto V_121;
}
if ( V_2 -> V_122 &&
V_2 -> V_122 -> V_123 & V_124 )
V_115 = true ;
V_99 = F_32 ( sizeof( * V_99 ) , V_89 ) ;
if ( ! V_99 )
goto V_121;
if ( ! V_2 -> V_112 -> V_125 || ! V_2 -> V_112 -> V_126 ) {
const struct V_127 * V_128 ;
V_128 = & V_2 -> V_52 -> V_128 [ V_2 -> V_129 ] ;
V_102 = V_128 -> V_130 [ V_131 ] . V_132 ;
V_101 = V_128 -> V_130 [ V_131 ] . V_11 ;
} else {
V_102 = V_2 -> V_112 -> V_125 ;
V_101 = V_2 -> V_112 -> V_126 ;
}
if ( F_30 ( V_133 , & V_2 -> V_9 -> V_120 ) ) {
struct V_134 * V_135 = & V_2 -> V_23 ;
V_107 = 0 ;
for ( V_8 = 0 ; V_8 < F_9 ( V_135 -> V_24 ) ; V_8 ++ ) {
if ( ! V_135 -> V_24 [ V_8 ] )
continue;
V_107 += V_135 -> V_24 [ V_8 ] +
sizeof( * V_4 ) +
sizeof( struct V_18 ) ;
}
for ( V_8 = 0 ; V_8 < V_135 -> V_136 ; V_8 ++ ) {
if ( ! V_135 -> V_42 [ V_8 ] )
continue;
V_107 += V_135 -> V_42 [ V_8 ] +
sizeof( * V_4 ) +
sizeof( struct V_18 ) ;
}
if ( F_12 ( & V_2 -> V_52 -> V_53 ,
V_54 ) ) {
for ( V_8 = 0 ;
V_8 < F_9 ( V_135 -> V_55 ) ;
V_8 ++ ) {
if ( ! V_135 -> V_55 [ V_8 ] )
continue;
V_107 +=
V_135 -> V_55 [ V_8 ] +
sizeof( * V_4 ) +
sizeof( struct V_18 ) ;
}
}
for ( V_8 = 0 ; V_8 < F_9 ( V_137 ) ; V_8 ++ ) {
int V_76 =
V_137 [ V_8 ] . V_77 -
V_137 [ V_8 ] . V_68 + 4 ;
V_108 += sizeof( * V_4 ) +
sizeof( struct V_74 ) +
V_76 ;
}
if ( V_2 -> V_112 -> V_138 ) {
for ( V_8 = 0 ; V_8 <
F_9 ( V_139 ) ; V_8 ++ ) {
int V_76 =
V_139 [ V_8 ] . V_77 -
V_139 [ V_8 ] . V_68 + 4 ;
V_108 += sizeof( * V_4 ) +
sizeof( struct V_74 ) +
V_76 ;
}
}
if ( V_2 -> V_112 -> V_140 == V_141 )
V_109 = sizeof( * V_4 ) + V_12 ;
}
V_106 = sizeof( * V_91 ) +
sizeof( * V_4 ) * 2 +
V_107 +
V_108 +
V_109 +
sizeof( * V_93 ) ;
if ( V_110 )
V_106 += sizeof( * V_4 ) + sizeof( * V_95 ) + V_110 ;
if ( V_113 )
V_106 += sizeof( * V_4 ) + sizeof( * V_95 ) + V_113 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_52 -> V_111 ; V_8 ++ ) {
V_106 += sizeof( * V_4 ) + sizeof( * V_95 ) +
F_33 ( V_104 [ V_8 ] . V_11 ) ;
}
if ( V_2 -> V_52 -> V_128 [ V_2 -> V_129 ] . V_142 &&
V_2 -> V_143 [ 0 ] . V_144 )
V_106 += V_2 -> V_145 *
( sizeof( * V_4 ) +
sizeof( struct V_146 ) +
V_147 ) ;
if ( V_115 ) {
V_106 = sizeof( * V_91 ) + sizeof( * V_4 ) +
sizeof( * V_93 ) ;
}
if ( V_2 -> V_112 -> V_140 == V_148 &&
F_34 ( V_2 -> V_9 -> V_149 ) == V_150 )
V_106 += sizeof( * V_4 ) + sizeof( * V_95 ) +
V_151 ;
if ( V_2 -> V_65 )
V_106 += sizeof( * V_4 ) + sizeof( * V_97 ) +
V_2 -> V_65 -> V_11 ;
if ( ! V_2 -> V_52 -> V_111 )
V_106 += V_101 + sizeof( * V_95 ) ;
V_91 = F_35 ( V_106 ) ;
if ( ! V_91 ) {
F_14 ( V_99 ) ;
goto V_121;
}
V_99 -> V_152 = V_91 ;
V_91 -> V_153 = F_3 ( V_154 ) ;
V_4 = ( void * ) V_91 -> V_6 ;
V_4 -> type = F_3 ( V_155 ) ;
V_4 -> V_11 = F_3 ( sizeof( * V_93 ) ) ;
V_93 = ( void * ) V_4 -> V_6 ;
V_93 -> V_140 =
V_2 -> V_112 -> V_140 == V_141 ?
F_3 ( V_156 ) :
F_3 ( V_157 ) ;
V_93 -> V_158 = F_3 ( F_34 ( V_2 -> V_9 -> V_149 ) ) ;
memcpy ( V_93 -> V_159 , V_2 -> V_52 -> V_160 ,
sizeof( V_93 -> V_159 ) ) ;
strncpy ( V_93 -> V_161 , V_2 -> V_112 -> V_162 ,
sizeof( V_93 -> V_161 ) ) ;
strncpy ( V_93 -> V_163 , V_2 -> V_164 -> V_165 -> V_162 ,
sizeof( V_93 -> V_163 ) ) ;
V_4 = F_6 ( V_4 ) ;
if ( F_30 ( V_133 , & V_2 -> V_9 -> V_120 ) ) {
F_8 ( V_2 , & V_4 ) ;
if ( V_109 )
F_1 ( V_2 , & V_4 ) ;
}
if ( V_2 -> V_65 ) {
V_4 -> type = F_3 ( V_166 ) ;
V_4 -> V_11 = F_3 ( sizeof( * V_97 ) +
V_2 -> V_65 -> V_11 ) ;
V_97 = ( void * ) V_4 -> V_6 ;
memcpy ( V_97 , & V_2 -> V_65 -> V_167 ,
sizeof( * V_97 ) + V_2 -> V_65 -> V_11 ) ;
V_4 = F_6 ( V_4 ) ;
}
if ( V_115 )
goto V_168;
if ( ! V_2 -> V_52 -> V_111 ) {
V_4 -> type = F_3 ( V_169 ) ;
V_4 -> V_11 = F_3 ( V_101 + sizeof( * V_95 ) ) ;
V_95 = ( void * ) V_4 -> V_6 ;
V_95 -> type = F_3 ( V_170 ) ;
V_95 -> V_132 = F_3 ( V_102 ) ;
F_36 ( V_2 -> V_9 , V_102 , V_95 -> V_6 ,
V_101 ) ;
V_4 = F_6 ( V_4 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_52 -> V_111 ; V_8 ++ ) {
T_2 V_11 = F_33 ( V_104 [ V_8 ] . V_11 ) ;
T_2 V_171 = F_33 ( V_104 [ V_8 ] . V_171 ) ;
bool V_70 ;
V_4 -> type = F_3 ( V_169 ) ;
V_4 -> V_11 = F_3 ( V_11 + sizeof( * V_95 ) ) ;
V_95 = ( void * ) V_4 -> V_6 ;
V_95 -> type = V_104 [ V_8 ] . V_172 ;
V_95 -> V_132 = F_3 ( V_171 ) ;
switch ( V_95 -> type & F_3 ( V_173 ) ) {
case F_3 ( V_174 ) :
F_36 ( V_2 -> V_9 , V_171 ,
V_95 -> V_6 ,
V_11 ) ;
V_70 = true ;
break;
case F_3 ( V_175 ) :
V_70 = F_16 ( V_2 -> V_9 , V_171 , V_11 ,
( void * ) V_95 -> V_6 ) ;
break;
default:
F_37 ( 1 ) ;
V_70 = false ;
}
if ( V_70 )
V_4 = F_6 ( V_4 ) ;
}
if ( V_110 ) {
V_4 -> type = F_3 ( V_169 ) ;
V_4 -> V_11 = F_3 ( V_110 + sizeof( * V_95 ) ) ;
V_95 = ( void * ) V_4 -> V_6 ;
V_95 -> type = F_3 ( V_176 ) ;
V_95 -> V_132 = F_3 ( V_2 -> V_112 -> V_177 ) ;
F_36 ( V_2 -> V_9 , V_2 -> V_112 -> V_177 ,
V_95 -> V_6 , V_110 ) ;
V_4 = F_6 ( V_4 ) ;
}
if ( V_113 ) {
V_4 -> type = F_3 ( V_169 ) ;
V_4 -> V_11 = F_3 ( V_113 + sizeof( * V_95 ) ) ;
V_95 = ( void * ) V_4 -> V_6 ;
V_95 -> type = F_3 ( V_170 ) ;
V_95 -> V_132 = F_3 ( V_2 -> V_112 -> V_178 ) ;
F_36 ( V_2 -> V_9 , V_2 -> V_112 -> V_178 ,
V_95 -> V_6 , V_113 ) ;
V_4 = F_6 ( V_4 ) ;
}
if ( V_2 -> V_112 -> V_140 == V_148 &&
F_34 ( V_2 -> V_9 -> V_149 ) == V_150 ) {
V_4 -> type = F_3 ( V_169 ) ;
V_4 -> V_11 = F_3 ( V_151 +
sizeof( * V_95 ) ) ;
V_95 = ( void * ) V_4 -> V_6 ;
V_95 -> type = F_3 ( V_170 ) ;
V_95 -> V_132 = F_3 ( V_179 ) ;
F_36 ( V_2 -> V_9 , V_179 ,
V_95 -> V_6 , V_151 ) ;
V_4 = F_6 ( V_4 ) ;
}
if ( V_2 -> V_52 -> V_128 [ V_2 -> V_129 ] . V_142 &&
V_2 -> V_143 [ 0 ] . V_144 ) {
for ( V_8 = 1 ; V_8 < V_2 -> V_145 + 1 ; V_8 ++ ) {
struct V_146 * V_180 ;
struct V_84 * V_181 =
V_2 -> V_143 [ V_8 ] . V_144 ;
T_4 V_182 = V_2 -> V_143 [ V_8 ] . V_183 ;
V_4 -> type = F_3 ( V_184 ) ;
V_4 -> V_11 = F_3 ( sizeof( * V_180 ) +
V_147 ) ;
V_180 = ( void * ) V_4 -> V_6 ;
V_180 -> V_185 = F_3 ( V_8 ) ;
F_38 ( V_2 -> V_9 -> V_164 , V_182 ,
V_147 ,
V_186 ) ;
memcpy ( V_180 -> V_6 , F_39 ( V_181 ) ,
V_147 ) ;
V_4 = F_6 ( V_4 ) ;
}
}
if ( V_108 ) {
F_17 ( V_2 -> V_9 , & V_4 ,
V_137 ,
F_9 ( V_137 ) ) ;
if ( V_2 -> V_112 -> V_138 )
F_17 ( V_2 -> V_9 , & V_4 ,
V_139 ,
F_9 ( V_139 ) ) ;
}
V_168:
V_99 -> V_187 = F_40 ( V_2 -> V_9 ,
V_2 -> V_122 ) ;
V_99 -> V_188 = V_106 ;
if ( V_99 -> V_187 )
V_106 += V_99 -> V_187 -> V_11 ;
V_91 -> V_106 = F_3 ( V_106 ) ;
V_100 = F_18 ( V_106 ) ;
if ( V_100 ) {
F_41 ( V_100 ,
F_42 ( V_100 ) ,
V_99 -> V_152 ,
V_99 -> V_188 , 0 ) ;
if ( V_99 -> V_187 )
F_41 ( V_100 ,
F_42 ( V_100 ) ,
V_99 -> V_187 -> V_6 ,
V_99 -> V_187 -> V_11 ,
V_99 -> V_188 ) ;
F_43 ( V_2 -> V_9 -> V_164 , V_100 , V_106 ,
V_89 ) ;
}
F_44 ( V_99 -> V_152 ) ;
F_44 ( V_99 -> V_187 ) ;
F_14 ( V_99 ) ;
V_121:
F_13 ( V_2 ) ;
V_2 -> V_122 = NULL ;
F_45 ( V_189 , & V_2 -> V_120 ) ;
}
int F_46 ( struct V_1 * V_2 ,
const struct V_190 * V_191 ,
const struct V_192 * V_193 )
{
unsigned int V_194 = 0 ;
if ( V_193 )
V_194 = F_47 ( F_33 ( V_193 -> V_195 ) ) ;
if ( F_48 ( V_189 , & V_2 -> V_120 ) )
return - V_196 ;
if ( F_37 ( V_2 -> V_65 ) )
F_13 ( V_2 ) ;
F_49 ( V_2 , L_2 ,
F_33 ( V_191 -> V_167 . type ) ) ;
V_2 -> V_65 = V_191 ;
V_2 -> V_122 = V_193 ;
F_50 ( V_197 , & V_2 -> V_198 , V_194 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , enum V_199 V_200 ,
const char * V_201 , T_5 V_11 ,
const struct V_192 * V_193 )
{
struct V_190 * V_191 ;
V_191 = F_32 ( sizeof( * V_191 ) + V_11 , V_202 ) ;
if ( ! V_191 )
return - V_203 ;
V_191 -> V_11 = V_11 ;
V_191 -> V_167 . type = F_3 ( V_200 ) ;
memcpy ( V_191 -> V_167 . V_6 , V_201 , V_11 ) ;
return F_46 ( V_2 , V_191 , V_193 ) ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_192 * V_193 ,
const char * V_204 , ... )
{
T_6 V_205 = F_53 ( V_193 -> V_205 ) ;
int V_206 , V_11 = 0 ;
char V_207 [ 64 ] ;
if ( ! V_205 )
return 0 ;
if ( V_204 ) {
T_7 V_208 ;
V_207 [ sizeof( V_207 ) - 1 ] = '\0' ;
va_start ( V_208 , V_204 ) ;
vsnprintf ( V_207 , sizeof( V_207 ) , V_204 , V_208 ) ;
va_end ( V_208 ) ;
if ( F_54 ( V_207 [ sizeof( V_207 ) - 1 ] ) )
V_207 [ sizeof( V_207 ) - 1 ] = '\0' ;
V_11 = strlen ( V_207 ) + 1 ;
}
V_206 = F_51 ( V_2 , F_33 ( V_193 -> V_209 ) , V_207 , V_11 ,
V_193 ) ;
if ( V_206 )
return V_206 ;
V_193 -> V_205 = F_55 ( V_205 - 1 ) ;
return 0 ;
}
static inline void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_112 -> V_140 == V_141 )
F_57 ( V_2 -> V_9 , V_210 , 0x100 ) ;
else
F_58 ( V_2 -> V_9 , V_211 , 1 ) ;
}
int F_59 ( struct V_1 * V_2 , T_1 V_212 )
{
T_1 * V_213 ;
int V_206 ;
int V_8 ;
if ( F_60 ( V_212 >= F_9 ( V_2 -> V_52 -> V_214 ) ,
L_3 , V_212 ) )
return - V_215 ;
if ( ( ! V_2 -> V_52 -> V_214 [ V_212 ] ||
! V_2 -> V_52 -> V_214 [ V_212 ] -> V_216 ) &&
V_212 == V_217 ) {
F_56 ( V_2 ) ;
return 0 ;
}
if ( ! V_2 -> V_52 -> V_214 [ V_212 ] )
return - V_215 ;
if ( V_2 -> V_218 != V_219 )
F_49 ( V_2 , L_4 ,
V_2 -> V_218 ) ;
V_213 = ( void * ) & V_2 -> V_52 -> V_214 [ V_212 ] -> V_220 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_52 -> V_214 [ V_212 ] -> V_216 ; V_8 ++ ) {
struct V_221 * V_222 = ( void * ) V_213 ;
V_206 = F_61 ( V_2 , V_222 -> V_209 , 0 ,
F_53 ( V_222 -> V_11 ) , V_222 -> V_6 ) ;
if ( V_206 )
return V_206 ;
V_213 += sizeof( * V_222 ) ;
V_213 += F_53 ( V_222 -> V_11 ) ;
}
V_2 -> V_218 = V_212 ;
return 0 ;
}
