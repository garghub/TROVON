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
struct V_3 * * V_4 ,
int V_18 , T_2 V_19 , int V_20 )
{
struct V_21 * V_22 ;
T_2 * V_23 ;
T_2 V_24 ;
int V_8 ;
V_22 = ( void * ) ( * V_4 ) -> V_6 ;
V_23 = ( void * ) V_22 -> V_6 ;
V_24 = V_18 ;
if ( V_24 == 0 )
return;
( * V_4 ) -> type = F_3 ( V_25 ) ;
( * V_4 ) -> V_11 = F_3 ( V_24 + sizeof( * V_22 ) ) ;
V_22 -> V_20 = F_3 ( V_20 ) ;
V_22 -> V_26 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_27 + V_19 ) ) ;
V_22 -> V_28 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_29 + V_19 ) ) ;
V_22 -> V_30 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_31 + V_19 ) ) ;
V_22 -> V_32 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_33 + V_19 ) ) ;
V_22 -> V_34 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_35 + V_19 ) ) ;
F_10 ( V_2 -> V_9 , V_35 + V_19 , 0x1 ) ;
F_10 ( V_2 -> V_9 , V_36 + V_19 , 0x1 ) ;
F_10 ( V_2 -> V_9 ,
V_37 + V_19 , 0x0 ) ;
V_24 /= sizeof( T_2 ) ;
for ( V_8 = 0 ; V_8 < V_24 ; V_8 ++ )
V_23 [ V_8 ] = F_9 ( V_2 -> V_9 ,
V_38 +
V_19 ) ;
* V_4 = F_6 ( * V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int V_18 , T_2 V_19 , int V_20 )
{
struct V_21 * V_22 ;
T_2 * V_23 ;
T_2 V_24 ;
int V_8 ;
V_22 = ( void * ) ( * V_4 ) -> V_6 ;
V_23 = ( void * ) V_22 -> V_6 ;
V_24 = V_18 ;
if ( V_24 == 0 )
return;
( * V_4 ) -> type = F_3 ( V_39 ) ;
( * V_4 ) -> V_11 = F_3 ( V_24 + sizeof( * V_22 ) ) ;
V_22 -> V_20 = F_3 ( V_20 ) ;
V_22 -> V_26 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_40 + V_19 ) ) ;
V_22 -> V_28 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_41 + V_19 ) ) ;
V_22 -> V_30 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_42 + V_19 ) ) ;
V_22 -> V_32 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_43 + V_19 ) ) ;
V_22 -> V_34 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_44 + V_19 ) ) ;
F_10 ( V_2 -> V_9 , V_45 + V_19 ,
V_41 + V_19 ) ;
F_9 ( V_2 -> V_9 , V_46 + V_19 ) ;
V_24 /= sizeof( T_2 ) ;
for ( V_8 = 0 ; V_8 < V_24 ; V_8 ++ )
V_23 [ V_8 ] = F_9 ( V_2 -> V_9 ,
V_46 +
V_19 ) ;
* V_4 = F_6 ( * V_4 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_21 * V_22 ;
struct V_47 * V_48 = & V_2 -> V_49 ;
T_2 * V_23 ;
T_2 V_24 ;
unsigned long V_7 ;
int V_8 , V_50 ;
if ( ! F_2 ( V_2 -> V_9 , & V_7 ) )
return;
F_8 ( V_2 , V_4 , V_48 -> V_51 [ 0 ] . V_52 , 0 , 0 ) ;
F_8 ( V_2 , V_4 , V_48 -> V_53 ,
V_54 , 1 ) ;
if ( V_2 -> V_49 . V_55 > 1 )
F_8 ( V_2 , V_4 , V_48 -> V_51 [ 1 ] . V_52 ,
V_56 , 2 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_49 . V_57 ; V_8 ++ ) {
F_10 ( V_2 -> V_9 , V_58 , V_8 ) ;
F_11 ( V_2 , V_4 , V_48 -> V_51 [ 0 ] . V_59 [ V_8 ] ,
0 , V_8 ) ;
}
if ( V_2 -> V_49 . V_55 > 1 ) {
for ( V_8 = 0 ; V_8 < V_2 -> V_49 . V_57 ; V_8 ++ ) {
F_10 ( V_2 -> V_9 ,
V_58 + V_56 ,
V_8 ) ;
F_11 ( V_2 , V_4 ,
V_48 -> V_51 [ 1 ] . V_59 [ V_8 ] ,
V_56 ,
V_8 + V_48 -> V_57 ) ;
}
}
if ( F_13 ( & V_2 -> V_60 -> V_61 ,
V_62 ) ) {
for ( V_8 = 0 ;
V_8 < F_14 ( V_2 -> V_49 . V_63 ) ;
V_8 ++ ) {
V_22 = ( void * ) ( * V_4 ) -> V_6 ;
V_23 = ( void * ) V_22 -> V_6 ;
V_24 = V_2 -> V_49 . V_63 [ V_8 ] ;
if ( V_24 == 0 )
continue;
( * V_4 ) -> type =
F_3 ( V_64 ) ;
( * V_4 ) -> V_11 =
F_3 ( V_24 + sizeof( * V_22 ) ) ;
V_22 -> V_20 = F_3 ( V_8 ) ;
F_10 ( V_2 -> V_9 , V_65 , V_8 +
V_2 -> V_49 . V_57 ) ;
V_22 -> V_26 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_66 ) ) ;
V_22 -> V_28 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_67 ) ) ;
V_22 -> V_30 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_68 ) ) ;
V_22 -> V_32 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_69 ) ) ;
V_22 -> V_34 =
F_3 ( F_9 ( V_2 -> V_9 ,
V_70 ) ) ;
F_10 ( V_2 -> V_9 ,
V_71 ,
V_67 ) ;
F_9 ( V_2 -> V_9 ,
V_72 ) ;
V_24 /= sizeof( T_2 ) ;
for ( V_50 = 0 ; V_50 < V_24 ; V_50 ++ )
V_23 [ V_50 ] =
F_9 ( V_2 -> V_9 ,
V_72 ) ;
* V_4 = F_6 ( * V_4 ) ;
}
}
F_7 ( V_2 -> V_9 , & V_7 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_73 != & V_74 )
F_16 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
}
static void F_17 ( struct V_75 * V_9 , T_2 V_76 ,
T_2 V_77 , T_3 * V_6 )
{
T_2 V_8 ;
for ( V_8 = 0 ; V_8 < V_77 ; V_8 += 4 )
* V_6 ++ = F_3 ( F_5 ( V_9 , V_76 + V_8 ) ) ;
}
static bool F_18 ( struct V_75 * V_9 , T_2 V_76 ,
T_2 V_77 , T_3 * V_6 )
{
unsigned long V_7 ;
bool V_78 = false ;
if ( F_2 ( V_9 , & V_7 ) ) {
V_78 = true ;
F_17 ( V_9 , V_76 , V_77 , V_6 ) ;
F_7 ( V_9 , & V_7 ) ;
}
return V_78 ;
}
static void F_19 ( struct V_75 * V_9 ,
struct V_3 * * V_6 ,
const struct V_79 * V_80 ,
T_2 V_81 )
{
struct V_82 * V_83 ;
unsigned long V_7 ;
T_2 V_8 ;
if ( ! F_2 ( V_9 , & V_7 ) )
return;
for ( V_8 = 0 ; V_8 < V_81 ; V_8 ++ ) {
int V_84 = V_80 [ V_8 ] . V_85 -
V_80 [ V_8 ] . V_76 + 4 ;
( * V_6 ) -> type = F_3 ( V_86 ) ;
( * V_6 ) -> V_11 = F_3 ( sizeof( * V_83 ) +
V_84 ) ;
V_83 = ( void * ) ( * V_6 ) -> V_6 ;
V_83 -> V_87 = F_3 ( V_80 [ V_8 ] . V_76 ) ;
F_17 ( V_9 , V_80 [ V_8 ] . V_76 ,
V_80 [ V_8 ] . V_85 -
V_80 [ V_8 ] . V_76 + 4 ,
( void * ) V_83 -> V_6 ) ;
* V_6 = F_6 ( * V_6 ) ;
}
F_7 ( V_9 , & V_7 ) ;
}
static struct V_88 * F_20 ( int V_18 )
{
int V_89 , V_90 , V_8 ;
struct V_91 * V_92 ;
struct V_88 * V_93 ;
struct V_88 * V_94 ;
V_90 = F_21 ( V_18 , V_95 ) ;
V_94 = F_22 ( V_90 , sizeof( * V_94 ) , V_96 ) ;
if ( ! V_94 )
return NULL ;
F_23 ( V_94 , V_90 ) ;
V_93 = V_94 ;
F_24 (table, iter, sg_nents(table), i) {
V_92 = F_25 ( V_96 ) ;
if ( ! V_92 ) {
V_93 = V_94 ;
F_24 (table, iter, sg_nents(table), i) {
V_92 = F_26 ( V_93 ) ;
if ( V_92 )
F_27 ( V_92 ) ;
}
return NULL ;
}
V_89 = F_28 ( int , V_18 , V_95 ) ;
V_18 -= V_95 ;
F_29 ( V_93 , V_92 , V_89 , 0 ) ;
}
return V_94 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
struct V_3 * V_4 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_88 * V_107 ;
T_2 V_108 , V_109 ;
const struct V_110 * V_111 = V_2 -> V_60 -> V_112 ;
T_2 V_113 , V_114 = 0 , V_115 = 0 , V_116 = 0 ;
T_2 V_117 = V_2 -> V_60 -> V_118 ? 0 : V_2 -> V_48 -> V_117 ;
T_2 V_119 = V_2 -> V_60 -> V_118 ? 0 : V_2 -> V_48 -> V_120 ;
bool V_121 = false ;
int V_8 ;
if ( ! V_122 &&
! V_2 -> V_9 -> V_123 )
return;
F_31 ( & V_2 -> V_124 ) ;
if ( F_32 ( V_125 , & V_2 -> V_9 -> V_126 ) ) {
F_33 ( V_2 , L_1 ) ;
goto V_127;
}
if ( V_2 -> V_128 &&
V_2 -> V_128 -> V_129 & V_130 )
V_121 = true ;
V_106 = F_34 ( sizeof( * V_106 ) , V_96 ) ;
if ( ! V_106 )
goto V_127;
if ( ! V_2 -> V_48 -> V_131 || ! V_2 -> V_48 -> V_132 ) {
const struct V_133 * V_134 ;
V_134 = & V_2 -> V_60 -> V_134 [ V_2 -> V_135 ] ;
V_109 = V_134 -> V_136 [ V_137 ] . V_19 ;
V_108 = V_134 -> V_136 [ V_137 ] . V_11 ;
} else {
V_109 = V_2 -> V_48 -> V_131 ;
V_108 = V_2 -> V_48 -> V_132 ;
}
if ( F_32 ( V_138 , & V_2 -> V_9 -> V_126 ) ) {
struct V_47 * V_139 = & V_2 -> V_49 ;
V_114 = 0 ;
if ( V_139 -> V_53 ) {
V_114 += V_139 -> V_53 +
sizeof( * V_4 ) +
sizeof( struct V_21 ) ;
}
for ( V_8 = 0 ; V_8 < V_139 -> V_55 ; V_8 ++ ) {
if ( ! V_139 -> V_51 [ V_8 ] . V_52 )
continue;
V_114 += V_139 -> V_51 [ V_8 ] . V_52 +
sizeof( * V_4 ) +
sizeof( struct V_21 ) ;
}
for ( V_8 = 0 ; V_8 < V_139 -> V_55 ; V_8 ++ ) {
int V_50 ;
for ( V_50 = 0 ; V_50 < V_139 -> V_57 ; V_50 ++ ) {
if ( ! V_139 -> V_51 [ V_8 ] . V_59 [ V_50 ] )
continue;
V_114 +=
V_139 -> V_51 [ V_8 ] . V_59 [ V_50 ] +
sizeof( * V_4 ) +
sizeof( struct V_21 ) ;
}
}
if ( F_13 ( & V_2 -> V_60 -> V_61 ,
V_62 ) ) {
for ( V_8 = 0 ;
V_8 < F_14 ( V_139 -> V_63 ) ;
V_8 ++ ) {
if ( ! V_139 -> V_63 [ V_8 ] )
continue;
V_114 +=
V_139 -> V_63 [ V_8 ] +
sizeof( * V_4 ) +
sizeof( struct V_21 ) ;
}
}
if ( ! V_2 -> V_9 -> V_48 -> V_140 ) {
for ( V_8 = 0 ; V_8 < F_14 ( V_141 ) ;
V_8 ++ ) {
int V_84 =
V_141 [ V_8 ] . V_85 -
V_141 [ V_8 ] . V_76 + 4 ;
V_115 += sizeof( * V_4 ) +
sizeof( struct V_82 ) +
V_84 ;
}
}
if ( ! V_2 -> V_9 -> V_48 -> V_140 && V_2 -> V_48 -> V_142 ) {
for ( V_8 = 0 ; V_8 <
F_14 ( V_143 ) ; V_8 ++ ) {
int V_84 =
V_143 [ V_8 ] . V_85 -
V_143 [ V_8 ] . V_76 + 4 ;
V_115 += sizeof( * V_4 ) +
sizeof( struct V_82 ) +
V_84 ;
}
}
if ( V_2 -> V_48 -> V_144 == V_145 )
V_116 = sizeof( * V_4 ) + V_12 ;
}
V_113 = sizeof( * V_98 ) +
sizeof( * V_4 ) * 2 +
V_114 +
V_115 +
V_116 +
sizeof( * V_100 ) ;
if ( V_117 )
V_113 += sizeof( * V_4 ) + sizeof( * V_102 ) + V_117 ;
if ( V_119 )
V_113 += sizeof( * V_4 ) + sizeof( * V_102 ) + V_119 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_60 -> V_118 ; V_8 ++ ) {
V_113 += sizeof( * V_4 ) + sizeof( * V_102 ) +
F_35 ( V_111 [ V_8 ] . V_11 ) ;
}
if ( ! V_2 -> V_9 -> V_48 -> V_140 &&
V_2 -> V_60 -> V_134 [ V_2 -> V_135 ] . V_146 &&
V_2 -> V_147 [ 0 ] . V_148 )
V_113 += V_2 -> V_149 *
( sizeof( * V_4 ) +
sizeof( struct V_150 ) +
V_151 ) ;
if ( V_121 ) {
V_113 = sizeof( * V_98 ) + sizeof( * V_4 ) +
sizeof( * V_100 ) ;
}
if ( V_2 -> V_73 )
V_113 += sizeof( * V_4 ) + sizeof( * V_104 ) +
V_2 -> V_73 -> V_11 ;
if ( ! V_2 -> V_60 -> V_118 )
V_113 += V_108 + sizeof( * V_102 ) ;
V_98 = F_36 ( V_113 ) ;
if ( ! V_98 ) {
F_16 ( V_106 ) ;
goto V_127;
}
V_106 -> V_152 = V_98 ;
V_98 -> V_153 = F_3 ( V_154 ) ;
V_4 = ( void * ) V_98 -> V_6 ;
V_4 -> type = F_3 ( V_155 ) ;
V_4 -> V_11 = F_3 ( sizeof( * V_100 ) ) ;
V_100 = ( void * ) V_4 -> V_6 ;
V_100 -> V_144 =
V_2 -> V_48 -> V_144 == V_145 ?
F_3 ( V_156 ) :
F_3 ( V_157 ) ;
V_100 -> V_158 = F_3 ( F_37 ( V_2 -> V_9 -> V_159 ) ) ;
memcpy ( V_100 -> V_160 , V_2 -> V_60 -> V_161 ,
sizeof( V_100 -> V_160 ) ) ;
strncpy ( V_100 -> V_162 , V_2 -> V_48 -> V_163 ,
sizeof( V_100 -> V_162 ) ) ;
strncpy ( V_100 -> V_164 , V_2 -> V_165 -> V_166 -> V_163 ,
sizeof( V_100 -> V_164 ) ) ;
V_4 = F_6 ( V_4 ) ;
if ( F_32 ( V_138 , & V_2 -> V_9 -> V_126 ) ) {
F_12 ( V_2 , & V_4 ) ;
if ( V_116 )
F_1 ( V_2 , & V_4 ) ;
}
if ( V_2 -> V_73 ) {
V_4 -> type = F_3 ( V_167 ) ;
V_4 -> V_11 = F_3 ( sizeof( * V_104 ) +
V_2 -> V_73 -> V_11 ) ;
V_104 = ( void * ) V_4 -> V_6 ;
memcpy ( V_104 , & V_2 -> V_73 -> V_168 ,
sizeof( * V_104 ) + V_2 -> V_73 -> V_11 ) ;
V_4 = F_6 ( V_4 ) ;
}
if ( V_121 )
goto V_169;
if ( ! V_2 -> V_60 -> V_118 ) {
V_4 -> type = F_3 ( V_170 ) ;
V_4 -> V_11 = F_3 ( V_108 + sizeof( * V_102 ) ) ;
V_102 = ( void * ) V_4 -> V_6 ;
V_102 -> type = F_3 ( V_171 ) ;
V_102 -> V_19 = F_3 ( V_109 ) ;
F_38 ( V_2 -> V_9 , V_109 , V_102 -> V_6 ,
V_108 ) ;
V_4 = F_6 ( V_4 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_60 -> V_118 ; V_8 ++ ) {
T_2 V_11 = F_35 ( V_111 [ V_8 ] . V_11 ) ;
T_2 V_172 = F_35 ( V_111 [ V_8 ] . V_172 ) ;
bool V_78 ;
V_4 -> type = F_3 ( V_170 ) ;
V_4 -> V_11 = F_3 ( V_11 + sizeof( * V_102 ) ) ;
V_102 = ( void * ) V_4 -> V_6 ;
V_102 -> type = V_111 [ V_8 ] . V_173 ;
V_102 -> V_19 = F_3 ( V_172 ) ;
switch ( V_102 -> type & F_3 ( V_174 ) ) {
case F_3 ( V_175 ) :
F_38 ( V_2 -> V_9 , V_172 ,
V_102 -> V_6 ,
V_11 ) ;
V_78 = true ;
break;
case F_3 ( V_176 ) :
V_78 = F_18 ( V_2 -> V_9 , V_172 , V_11 ,
( void * ) V_102 -> V_6 ) ;
break;
default:
F_39 ( 1 ) ;
V_78 = false ;
}
if ( V_78 )
V_4 = F_6 ( V_4 ) ;
}
if ( V_117 ) {
V_4 -> type = F_3 ( V_170 ) ;
V_4 -> V_11 = F_3 ( V_117 + sizeof( * V_102 ) ) ;
V_102 = ( void * ) V_4 -> V_6 ;
V_102 -> type = F_3 ( V_177 ) ;
V_102 -> V_19 = F_3 ( V_2 -> V_48 -> V_178 ) ;
F_38 ( V_2 -> V_9 , V_2 -> V_48 -> V_178 ,
V_102 -> V_6 , V_117 ) ;
V_4 = F_6 ( V_4 ) ;
}
if ( V_119 ) {
V_4 -> type = F_3 ( V_170 ) ;
V_4 -> V_11 = F_3 ( V_119 + sizeof( * V_102 ) ) ;
V_102 = ( void * ) V_4 -> V_6 ;
V_102 -> type = F_3 ( V_171 ) ;
V_102 -> V_19 = F_3 ( V_2 -> V_48 -> V_179 ) ;
F_38 ( V_2 -> V_9 , V_2 -> V_48 -> V_179 ,
V_102 -> V_6 , V_119 ) ;
V_4 = F_6 ( V_4 ) ;
}
if ( ! V_2 -> V_9 -> V_48 -> V_140 &&
V_2 -> V_60 -> V_134 [ V_2 -> V_135 ] . V_146 &&
V_2 -> V_147 [ 0 ] . V_148 ) {
for ( V_8 = 1 ; V_8 < V_2 -> V_149 + 1 ; V_8 ++ ) {
struct V_150 * V_180 ;
struct V_91 * V_181 =
V_2 -> V_147 [ V_8 ] . V_148 ;
T_4 V_182 = V_2 -> V_147 [ V_8 ] . V_183 ;
V_4 -> type = F_3 ( V_184 ) ;
V_4 -> V_11 = F_3 ( sizeof( * V_180 ) +
V_151 ) ;
V_180 = ( void * ) V_4 -> V_6 ;
V_180 -> V_185 = F_3 ( V_8 ) ;
F_40 ( V_2 -> V_9 -> V_165 , V_182 ,
V_151 ,
V_186 ) ;
memcpy ( V_180 -> V_6 , F_41 ( V_181 ) ,
V_151 ) ;
V_4 = F_6 ( V_4 ) ;
}
}
if ( V_115 ) {
F_19 ( V_2 -> V_9 , & V_4 ,
V_141 ,
F_14 ( V_141 ) ) ;
if ( V_2 -> V_48 -> V_142 )
F_19 ( V_2 -> V_9 , & V_4 ,
V_143 ,
F_14 ( V_143 ) ) ;
}
V_169:
V_106 -> V_187 = F_42 ( V_2 -> V_9 ,
V_2 -> V_128 ) ;
V_106 -> V_188 = V_113 ;
if ( V_106 -> V_187 )
V_113 += V_106 -> V_187 -> V_11 ;
V_98 -> V_113 = F_3 ( V_113 ) ;
V_107 = F_20 ( V_113 ) ;
if ( V_107 ) {
F_43 ( V_107 ,
F_44 ( V_107 ) ,
V_106 -> V_152 ,
V_106 -> V_188 , 0 ) ;
if ( V_106 -> V_187 )
F_43 ( V_107 ,
F_44 ( V_107 ) ,
V_106 -> V_187 -> V_6 ,
V_106 -> V_187 -> V_11 ,
V_106 -> V_188 ) ;
F_45 ( V_2 -> V_9 -> V_165 , V_107 , V_113 ,
V_96 ) ;
}
F_46 ( V_106 -> V_152 ) ;
F_46 ( V_106 -> V_187 ) ;
F_16 ( V_106 ) ;
V_127:
F_15 ( V_2 ) ;
V_2 -> V_128 = NULL ;
F_47 ( V_189 , & V_2 -> V_126 ) ;
}
int F_48 ( struct V_1 * V_2 ,
const struct V_190 * V_191 ,
const struct V_192 * V_193 )
{
unsigned int V_194 = 0 ;
if ( V_193 )
V_194 = F_49 ( F_35 ( V_193 -> V_195 ) ) ;
if ( F_50 ( V_2 -> V_9 -> V_196 == V_197 ,
L_2 ) )
return - V_198 ;
if ( F_51 ( V_189 , & V_2 -> V_126 ) )
return - V_199 ;
if ( F_39 ( V_2 -> V_73 ) )
F_15 ( V_2 ) ;
F_52 ( V_2 , L_3 ,
F_35 ( V_191 -> V_168 . type ) ) ;
V_2 -> V_73 = V_191 ;
V_2 -> V_128 = V_193 ;
F_53 ( & V_2 -> V_200 , V_194 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , enum V_201 V_202 ,
const char * V_203 , T_5 V_11 ,
const struct V_192 * V_193 )
{
struct V_190 * V_191 ;
V_191 = F_34 ( sizeof( * V_191 ) + V_11 , V_204 ) ;
if ( ! V_191 )
return - V_205 ;
V_191 -> V_11 = V_11 ;
V_191 -> V_168 . type = F_3 ( V_202 ) ;
memcpy ( V_191 -> V_168 . V_6 , V_203 , V_11 ) ;
return F_48 ( V_2 , V_191 , V_193 ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_192 * V_193 ,
const char * V_206 , ... )
{
T_6 V_207 = F_56 ( V_193 -> V_207 ) ;
int V_208 , V_11 = 0 ;
char V_209 [ 64 ] ;
if ( ! V_207 )
return 0 ;
if ( V_206 ) {
T_7 V_210 ;
V_209 [ sizeof( V_209 ) - 1 ] = '\0' ;
va_start ( V_210 , V_206 ) ;
vsnprintf ( V_209 , sizeof( V_209 ) , V_206 , V_210 ) ;
va_end ( V_210 ) ;
if ( F_57 ( V_209 [ sizeof( V_209 ) - 1 ] ) )
V_209 [ sizeof( V_209 ) - 1 ] = '\0' ;
V_11 = strlen ( V_209 ) + 1 ;
}
V_208 = F_54 ( V_2 , F_35 ( V_193 -> V_211 ) , V_209 , V_11 ,
V_193 ) ;
if ( V_208 )
return V_208 ;
V_193 -> V_207 = F_58 ( V_207 - 1 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 , T_1 V_212 )
{
T_1 * V_213 ;
int V_208 ;
int V_8 ;
if ( F_60 ( V_212 >= F_14 ( V_2 -> V_60 -> V_214 ) ,
L_4 , V_212 ) )
return - V_215 ;
if ( ( ! V_2 -> V_60 -> V_214 [ V_212 ] ||
! V_2 -> V_60 -> V_214 [ V_212 ] -> V_216 ) &&
V_212 == V_217 )
return 0 ;
if ( ! V_2 -> V_60 -> V_214 [ V_212 ] )
return - V_215 ;
if ( V_2 -> V_218 != V_219 )
F_52 ( V_2 , L_5 ,
V_2 -> V_218 ) ;
V_213 = ( void * ) & V_2 -> V_60 -> V_214 [ V_212 ] -> V_220 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_60 -> V_214 [ V_212 ] -> V_216 ; V_8 ++ ) {
struct V_221 * V_222 = ( void * ) V_213 ;
V_208 = F_61 ( V_2 , V_222 -> V_211 , 0 ,
F_56 ( V_222 -> V_11 ) , V_222 -> V_6 ) ;
if ( V_208 )
return V_208 ;
V_213 += sizeof( * V_222 ) ;
V_213 += F_56 ( V_222 -> V_11 ) ;
}
V_2 -> V_218 = V_212 ;
return 0 ;
}
