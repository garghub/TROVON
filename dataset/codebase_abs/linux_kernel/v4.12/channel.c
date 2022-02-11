void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_5 . V_6 && ! V_2 -> V_7 ) {
F_2 ( V_2 -> V_5 . V_8 ) ;
V_4 = V_9 . V_10 [ 1 ] ;
F_3 ( V_2 -> V_11 ,
( unsigned long * ) & V_4 -> V_12
[ V_2 -> V_13 ] . V_14 ) ;
} else {
F_4 ( V_2 ) ;
}
}
int F_5 ( struct V_1 * V_15 , T_1 V_16 ,
T_1 V_17 , void * V_18 , T_1 V_19 ,
void (* F_6)( void * V_20 ) , void * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 = NULL ;
unsigned long V_25 ;
int V_26 , V_27 = 0 ;
struct V_28 * V_28 ;
if ( V_16 % V_29 ||
V_17 % V_29 )
return - V_30 ;
F_7 ( & V_15 -> V_31 , V_25 ) ;
if ( V_15 -> V_32 == V_33 ) {
V_15 -> V_32 = V_34 ;
} else {
F_8 ( & V_15 -> V_31 , V_25 ) ;
return - V_30 ;
}
F_8 ( & V_15 -> V_31 , V_25 ) ;
V_15 -> V_35 = F_6 ;
V_15 -> V_36 = V_20 ;
V_28 = F_9 ( F_10 ( V_15 -> V_37 ) ,
V_38 | V_39 ,
F_11 ( V_16 +
V_17 ) ) ;
if ( ! V_28 )
V_28 = F_12 ( V_38 | V_39 ,
F_11 ( V_16 +
V_17 ) ) ;
if ( ! V_28 ) {
V_27 = - V_40 ;
goto V_41;
}
V_15 -> V_42 = F_13 ( V_28 ) ;
V_15 -> V_43 = ( V_16 +
V_17 ) >> V_44 ;
V_26 = F_14 ( & V_15 -> V_45 , V_28 ,
V_16 >> V_44 ) ;
if ( V_26 != 0 ) {
V_27 = V_26 ;
goto V_46;
}
V_26 = F_14 ( & V_15 -> V_47 ,
& V_28 [ V_16 >> V_44 ] ,
V_17 >> V_44 ) ;
if ( V_26 != 0 ) {
V_27 = V_26 ;
goto V_46;
}
V_15 -> V_48 = 0 ;
V_26 = F_15 ( V_15 ,
F_13 ( V_28 ) ,
V_16 +
V_17 ,
& V_15 -> V_48 ) ;
if ( V_26 != 0 ) {
V_27 = V_26 ;
goto V_46;
}
V_24 = F_16 ( sizeof( * V_24 ) +
sizeof( struct V_21 ) ,
V_38 ) ;
if ( ! V_24 ) {
V_27 = - V_40 ;
goto V_49;
}
F_17 ( & V_24 -> V_50 ) ;
V_24 -> V_51 = V_15 ;
V_22 = (struct V_21 * ) V_24 -> V_52 ;
V_22 -> V_53 . V_54 = V_55 ;
V_22 -> V_56 = V_15 -> V_5 . V_8 ;
V_22 -> V_8 = V_15 -> V_5 . V_8 ;
V_22 -> V_48 = V_15 -> V_48 ;
V_22 -> V_57 = V_16 >>
V_44 ;
V_22 -> V_58 = V_15 -> V_58 ;
if ( V_19 > V_59 ) {
V_27 = - V_30 ;
goto V_49;
}
if ( V_19 )
memcpy ( V_22 -> V_18 , V_18 , V_19 ) ;
F_7 ( & V_9 . V_60 , V_25 ) ;
F_18 ( & V_24 -> V_61 ,
& V_9 . V_62 ) ;
F_8 ( & V_9 . V_60 , V_25 ) ;
V_26 = F_19 ( V_22 ,
sizeof( struct V_21 ) , true ) ;
if ( V_26 != 0 ) {
V_27 = V_26 ;
goto V_63;
}
F_20 ( & V_24 -> V_50 ) ;
F_7 ( & V_9 . V_60 , V_25 ) ;
F_21 ( & V_24 -> V_61 ) ;
F_8 ( & V_9 . V_60 , V_25 ) ;
if ( V_15 -> V_64 ) {
V_27 = - V_65 ;
goto V_49;
}
if ( V_24 -> V_66 . V_67 . V_68 ) {
V_27 = - V_69 ;
goto V_49;
}
V_15 -> V_32 = V_70 ;
F_22 ( V_24 ) ;
return 0 ;
V_63:
F_7 ( & V_9 . V_60 , V_25 ) ;
F_21 ( & V_24 -> V_61 ) ;
F_8 ( & V_9 . V_60 , V_25 ) ;
V_49:
F_23 ( V_15 , V_15 -> V_48 ) ;
F_22 ( V_24 ) ;
V_46:
F_24 ( & V_15 -> V_45 ) ;
F_24 ( & V_15 -> V_47 ) ;
F_25 ( V_28 ,
F_11 ( V_16 + V_17 ) ) ;
V_41:
V_15 -> V_32 = V_33 ;
return V_27 ;
}
int F_26 ( const T_2 * V_71 ,
const T_2 * V_72 )
{
struct V_73 V_74 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_53 . V_54 = V_75 ;
V_74 . V_76 = * V_71 ;
V_74 . V_77 = * V_72 ;
return F_19 ( & V_74 , sizeof( V_74 ) , true ) ;
}
static int F_27 ( void * V_78 , T_1 V_79 ,
struct V_23 * * V_80 )
{
int V_81 ;
int V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_23 * V_87 ;
struct V_23 * V_88 = NULL ;
T_1 V_89 ;
int V_90 , V_91 , V_92 , V_93 , V_94 ;
V_82 = V_79 >> V_44 ;
V_94 = V_95 -
sizeof( struct V_83 ) -
sizeof( struct V_96 ) ;
V_91 = V_94 / sizeof( V_97 ) ;
if ( V_82 > V_91 ) {
V_89 = sizeof( struct V_23 ) +
sizeof( struct V_83 ) +
sizeof( struct V_96 ) + V_91 * sizeof( V_97 ) ;
V_87 = F_28 ( V_89 , V_38 ) ;
if ( ! V_87 )
goto V_98;
F_29 ( & V_87 -> V_99 ) ;
V_87 -> V_89 = V_89 ;
V_84 = (struct V_83 * )
V_87 -> V_52 ;
V_84 -> V_100 = 1 ;
V_84 -> V_101 = sizeof( struct V_96 ) +
V_82 * sizeof( V_97 ) ;
V_84 -> V_102 [ 0 ] . V_103 = 0 ;
V_84 -> V_102 [ 0 ] . V_104 = V_79 ;
for ( V_81 = 0 ; V_81 < V_91 ; V_81 ++ )
V_84 -> V_102 [ 0 ] . V_105 [ V_81 ] = F_30 (
V_78 + V_29 * V_81 ) >> V_44 ;
* V_80 = V_87 ;
V_90 = V_91 ;
V_92 = V_82 - V_91 ;
V_94 = V_95 -
sizeof( struct V_85 ) ;
V_91 = V_94 / sizeof( V_97 ) ;
while ( V_92 ) {
if ( V_92 > V_91 )
V_93 = V_91 ;
else
V_93 = V_92 ;
V_89 = sizeof( struct V_23 ) +
sizeof( struct V_85 ) +
V_93 * sizeof( V_97 ) ;
V_88 = F_28 ( V_89 , V_38 ) ;
if ( ! V_88 ) {
struct V_23 * V_106 = NULL ;
struct V_23 * V_107 = NULL ;
F_31 (pos, tmp,
&msgheader->submsglist,
msglistentry) {
F_21 ( & V_106 -> V_61 ) ;
F_22 ( V_106 ) ;
}
goto V_98;
}
V_88 -> V_89 = V_89 ;
V_86 =
(struct V_85 * ) V_88 -> V_52 ;
for ( V_81 = 0 ; V_81 < V_93 ; V_81 ++ )
V_86 -> V_108 [ V_81 ] = F_30 (
V_78 + V_29 * ( V_90 + V_81 ) ) >>
V_44 ;
F_18 ( & V_88 -> V_61 ,
& V_87 -> V_99 ) ;
V_90 += V_93 ;
V_92 -= V_93 ;
}
} else {
V_89 = sizeof( struct V_23 ) +
sizeof( struct V_83 ) +
sizeof( struct V_96 ) + V_82 * sizeof( V_97 ) ;
V_87 = F_28 ( V_89 , V_38 ) ;
if ( V_87 == NULL )
goto V_98;
F_29 ( & V_87 -> V_99 ) ;
V_87 -> V_89 = V_89 ;
V_84 = (struct V_83 * )
V_87 -> V_52 ;
V_84 -> V_100 = 1 ;
V_84 -> V_101 = sizeof( struct V_96 ) +
V_82 * sizeof( V_97 ) ;
V_84 -> V_102 [ 0 ] . V_103 = 0 ;
V_84 -> V_102 [ 0 ] . V_104 = V_79 ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ )
V_84 -> V_102 [ 0 ] . V_105 [ V_81 ] = F_30 (
V_78 + V_29 * V_81 ) >> V_44 ;
* V_80 = V_87 ;
}
return 0 ;
V_98:
F_22 ( V_87 ) ;
F_22 ( V_88 ) ;
return - V_40 ;
}
int F_15 ( struct V_1 * V_2 , void * V_78 ,
T_1 V_79 , T_1 * V_109 )
{
struct V_83 * V_110 ;
struct V_85 * V_86 ;
struct V_23 * V_80 = NULL ;
struct V_23 * V_111 , * V_107 ;
struct V_112 * V_113 ;
T_1 V_114 ;
unsigned long V_25 ;
int V_26 = 0 ;
V_114 =
( F_32 ( & V_9 . V_114 ) - 1 ) ;
V_26 = F_27 ( V_78 , V_79 , & V_80 ) ;
if ( V_26 )
return V_26 ;
F_17 ( & V_80 -> V_50 ) ;
V_80 -> V_51 = V_2 ;
V_110 = (struct V_83 * ) V_80 -> V_52 ;
V_110 -> V_53 . V_54 = V_115 ;
V_110 -> V_8 = V_2 -> V_5 . V_8 ;
V_110 -> V_116 = V_114 ;
F_7 ( & V_9 . V_60 , V_25 ) ;
F_18 ( & V_80 -> V_61 ,
& V_9 . V_62 ) ;
F_8 ( & V_9 . V_60 , V_25 ) ;
V_26 = F_19 ( V_110 , V_80 -> V_89 -
sizeof( * V_80 ) , true ) ;
if ( V_26 != 0 )
goto V_117;
F_33 (curr, &msginfo->submsglist) {
V_111 = (struct V_23 * ) V_113 ;
V_86 =
(struct V_85 * ) V_111 -> V_52 ;
V_86 -> V_53 . V_54 =
V_118 ;
V_86 -> V_116 = V_114 ;
V_26 = F_19 ( V_86 ,
V_111 -> V_89 - sizeof( * V_111 ) ,
true ) ;
if ( V_26 != 0 )
goto V_117;
}
F_20 ( & V_80 -> V_50 ) ;
if ( V_2 -> V_64 ) {
V_26 = - V_65 ;
goto V_117;
}
* V_109 = V_110 -> V_116 ;
V_117:
F_7 ( & V_9 . V_60 , V_25 ) ;
F_21 ( & V_80 -> V_61 ) ;
F_8 ( & V_9 . V_60 , V_25 ) ;
F_31 (submsginfo, tmp, &msginfo->submsglist,
msglistentry) {
F_22 ( V_111 ) ;
}
F_22 ( V_80 ) ;
return V_26 ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_109 )
{
struct V_119 * V_52 ;
struct V_23 * V_120 ;
unsigned long V_25 ;
int V_26 ;
V_120 = F_16 ( sizeof( * V_120 ) +
sizeof( struct V_119 ) , V_38 ) ;
if ( ! V_120 )
return - V_40 ;
F_17 ( & V_120 -> V_50 ) ;
V_120 -> V_51 = V_2 ;
V_52 = (struct V_119 * ) V_120 -> V_52 ;
V_52 -> V_53 . V_54 = V_121 ;
V_52 -> V_8 = V_2 -> V_5 . V_8 ;
V_52 -> V_116 = V_109 ;
F_7 ( & V_9 . V_60 , V_25 ) ;
F_18 ( & V_120 -> V_61 ,
& V_9 . V_62 ) ;
F_8 ( & V_9 . V_60 , V_25 ) ;
V_26 = F_19 ( V_52 , sizeof( struct V_119 ) ,
true ) ;
if ( V_26 )
goto V_122;
F_20 ( & V_120 -> V_50 ) ;
V_122:
if ( V_2 -> V_64 )
V_26 = 0 ;
F_7 ( & V_9 . V_60 , V_25 ) ;
F_21 ( & V_120 -> V_61 ) ;
F_8 ( & V_9 . V_60 , V_25 ) ;
F_22 ( V_120 ) ;
return V_26 ;
}
static void F_34 ( void * V_123 )
{
struct V_1 * V_2 = V_123 ;
V_2 -> V_35 = NULL ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_124 * V_52 ;
int V_26 ;
F_36 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_32 != V_70 ) {
V_26 = - V_30 ;
goto V_126;
}
V_2 -> V_32 = V_33 ;
V_2 -> V_127 = NULL ;
if ( V_2 -> V_37 != F_37 () ) {
F_38 () ;
F_39 ( V_2 -> V_37 , F_34 ,
V_2 , true ) ;
} else {
F_34 ( V_2 ) ;
F_38 () ;
}
V_52 = & V_2 -> V_128 . V_52 ;
V_52 -> V_53 . V_54 = V_129 ;
V_52 -> V_8 = V_2 -> V_5 . V_8 ;
V_26 = F_19 ( V_52 , sizeof( struct V_124 ) ,
true ) ;
if ( V_26 ) {
F_40 ( L_1 , V_26 ) ;
goto V_126;
}
if ( V_2 -> V_48 ) {
V_26 = F_23 ( V_2 ,
V_2 -> V_48 ) ;
if ( V_26 ) {
F_40 ( L_2 , V_26 ) ;
goto V_126;
}
}
F_24 ( & V_2 -> V_45 ) ;
F_24 ( & V_2 -> V_47 ) ;
F_41 ( ( unsigned long ) V_2 -> V_42 ,
F_11 ( V_2 -> V_43 * V_29 ) ) ;
V_126:
return V_26 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_112 * V_130 , * V_107 ;
struct V_1 * V_131 ;
if ( V_2 -> V_132 != NULL ) {
return;
}
F_43 (cur, tmp, &channel->sc_list) {
V_131 = F_44 ( V_130 , struct V_1 , V_133 ) ;
if ( V_131 -> V_32 != V_70 )
continue;
F_35 ( V_131 ) ;
}
F_35 ( V_2 ) ;
}
int F_45 ( struct V_1 * V_2 , void * V_134 ,
T_1 V_135 , V_97 V_136 ,
enum V_137 type , T_1 V_25 )
{
struct V_138 V_139 ;
T_1 V_140 = sizeof( struct V_138 ) + V_135 ;
T_1 V_141 = F_46 ( V_140 , sizeof( V_97 ) ) ;
struct V_142 V_143 [ 3 ] ;
V_97 V_144 = 0 ;
int V_145 = ( ( V_135 != 0 ) ? 3 : 1 ) ;
V_139 . type = type ;
V_139 . V_25 = V_25 ;
V_139 . V_146 = sizeof( struct V_138 ) >> 3 ;
V_139 . V_147 = ( V_148 ) ( V_141 >> 3 ) ;
V_139 . V_149 = V_136 ;
V_143 [ 0 ] . V_150 = & V_139 ;
V_143 [ 0 ] . V_151 = sizeof( struct V_138 ) ;
V_143 [ 1 ] . V_150 = V_134 ;
V_143 [ 1 ] . V_151 = V_135 ;
V_143 [ 2 ] . V_150 = & V_144 ;
V_143 [ 2 ] . V_151 = ( V_141 - V_140 ) ;
return F_47 ( V_2 , V_143 , V_145 ) ;
}
int F_48 ( struct V_1 * V_2 , void * V_134 ,
T_1 V_135 , V_97 V_136 ,
enum V_137 type , T_1 V_25 )
{
return F_45 ( V_2 , V_134 , V_135 , V_136 ,
type , V_25 ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_152 V_153 [] ,
T_1 V_82 , void * V_134 , T_1 V_135 ,
V_97 V_136 , T_1 V_25 )
{
int V_81 ;
struct V_154 V_139 ;
T_1 V_155 ;
T_1 V_140 ;
T_1 V_141 ;
struct V_142 V_143 [ 3 ] ;
V_97 V_144 = 0 ;
if ( V_82 > V_156 )
return - V_30 ;
V_155 = sizeof( struct V_154 ) -
( ( V_156 - V_82 ) *
sizeof( struct V_152 ) ) ;
V_140 = V_155 + V_135 ;
V_141 = F_46 ( V_140 , sizeof( V_97 ) ) ;
V_139 . type = V_157 ;
V_139 . V_25 = V_25 ;
V_139 . V_158 = V_155 >> 3 ;
V_139 . V_159 = ( V_148 ) ( V_141 >> 3 ) ;
V_139 . V_160 = V_136 ;
V_139 . V_100 = V_82 ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
V_139 . V_102 [ V_81 ] . V_161 = V_153 [ V_81 ] . V_161 ;
V_139 . V_102 [ V_81 ] . V_162 = V_153 [ V_81 ] . V_162 ;
V_139 . V_102 [ V_81 ] . V_108 = V_153 [ V_81 ] . V_108 ;
}
V_143 [ 0 ] . V_150 = & V_139 ;
V_143 [ 0 ] . V_151 = V_155 ;
V_143 [ 1 ] . V_150 = V_134 ;
V_143 [ 1 ] . V_151 = V_135 ;
V_143 [ 2 ] . V_150 = & V_144 ;
V_143 [ 2 ] . V_151 = ( V_141 - V_140 ) ;
return F_47 ( V_2 , V_143 , 3 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_152 V_153 [] ,
T_1 V_82 , void * V_134 , T_1 V_135 ,
V_97 V_136 )
{
T_1 V_25 = V_163 ;
return F_49 ( V_2 , V_153 , V_82 ,
V_134 , V_135 ,
V_136 , V_25 ) ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_164 * V_139 ,
T_1 V_165 ,
void * V_134 , T_1 V_135 , V_97 V_136 )
{
T_1 V_140 ;
T_1 V_141 ;
struct V_142 V_143 [ 3 ] ;
V_97 V_144 = 0 ;
V_140 = V_165 + V_135 ;
V_141 = F_46 ( V_140 , sizeof( V_97 ) ) ;
V_139 -> type = V_157 ;
V_139 -> V_25 = V_163 ;
V_139 -> V_158 = V_165 >> 3 ;
V_139 -> V_159 = ( V_148 ) ( V_141 >> 3 ) ;
V_139 -> V_160 = V_136 ;
V_139 -> V_100 = 1 ;
V_143 [ 0 ] . V_150 = V_139 ;
V_143 [ 0 ] . V_151 = V_165 ;
V_143 [ 1 ] . V_150 = V_134 ;
V_143 [ 1 ] . V_151 = V_135 ;
V_143 [ 2 ] . V_150 = & V_144 ;
V_143 [ 2 ] . V_151 = ( V_141 - V_140 ) ;
return F_47 ( V_2 , V_143 , 3 ) ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_166 * V_167 ,
void * V_134 , T_1 V_135 , V_97 V_136 )
{
struct V_168 V_139 ;
T_1 V_155 ;
T_1 V_140 ;
T_1 V_141 ;
struct V_142 V_143 [ 3 ] ;
V_97 V_144 = 0 ;
T_1 V_91 = F_53 ( V_167 -> V_162 ,
V_167 -> V_161 ) ;
if ( V_91 > V_169 )
return - V_30 ;
V_155 = sizeof( struct V_168 ) -
( ( V_169 - V_91 ) *
sizeof( V_97 ) ) ;
V_140 = V_155 + V_135 ;
V_141 = F_46 ( V_140 , sizeof( V_97 ) ) ;
V_139 . type = V_157 ;
V_139 . V_25 = V_163 ;
V_139 . V_158 = V_155 >> 3 ;
V_139 . V_159 = ( V_148 ) ( V_141 >> 3 ) ;
V_139 . V_160 = V_136 ;
V_139 . V_100 = 1 ;
V_139 . V_102 . V_161 = V_167 -> V_161 ;
V_139 . V_102 . V_162 = V_167 -> V_162 ;
memcpy ( V_139 . V_102 . V_105 , V_167 -> V_105 ,
V_91 * sizeof( V_97 ) ) ;
V_143 [ 0 ] . V_150 = & V_139 ;
V_143 [ 0 ] . V_151 = V_155 ;
V_143 [ 1 ] . V_150 = V_134 ;
V_143 [ 1 ] . V_151 = V_135 ;
V_143 [ 2 ] . V_150 = & V_144 ;
V_143 [ 2 ] . V_151 = ( V_141 - V_140 ) ;
return F_47 ( V_2 , V_143 , 3 ) ;
}
static inline int
F_54 ( struct V_1 * V_2 , void * V_134 ,
T_1 V_135 , T_1 * V_170 , V_97 * V_136 ,
bool V_171 )
{
return F_55 ( V_2 , V_134 , V_135 ,
V_170 , V_136 , V_171 ) ;
}
int F_56 ( struct V_1 * V_2 , void * V_134 ,
T_1 V_135 , T_1 * V_170 ,
V_97 * V_136 )
{
return F_54 ( V_2 , V_134 , V_135 ,
V_170 , V_136 , false ) ;
}
int F_57 ( struct V_1 * V_2 , void * V_134 ,
T_1 V_135 , T_1 * V_170 ,
V_97 * V_136 )
{
return F_54 ( V_2 , V_134 , V_135 ,
V_170 , V_136 , true ) ;
}
