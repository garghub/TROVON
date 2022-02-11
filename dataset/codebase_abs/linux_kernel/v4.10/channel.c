void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ( V_2 -> V_5 . V_6 ) &&
( ! V_2 -> V_7 ) ) {
F_2 ( V_2 -> V_5 . V_8 & 31 ,
( unsigned long * ) V_9 . V_10 +
( V_2 -> V_5 . V_8 >> 5 ) ) ;
V_4 = V_9 . V_11 [ 1 ] ;
F_2 ( V_2 -> V_12 ,
( unsigned long * ) & V_4 -> V_13
[ V_2 -> V_14 ] . V_15 ) ;
} else {
F_3 ( V_2 ) ;
}
}
int F_4 ( struct V_1 * V_16 , T_1 V_17 ,
T_1 V_18 , void * V_19 , T_1 V_20 ,
void (* F_5)( void * V_21 ) , void * V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 = NULL ;
unsigned long V_26 ;
int V_27 , V_28 = 0 ;
struct V_29 * V_29 ;
if ( V_17 % V_30 ||
V_18 % V_30 )
return - V_31 ;
F_6 ( & V_16 -> V_32 , V_26 ) ;
if ( V_16 -> V_33 == V_34 ) {
V_16 -> V_33 = V_35 ;
} else {
F_7 ( & V_16 -> V_32 , V_26 ) ;
return - V_31 ;
}
F_7 ( & V_16 -> V_32 , V_26 ) ;
V_16 -> V_36 = F_5 ;
V_16 -> V_37 = V_21 ;
V_29 = F_8 ( F_9 ( V_16 -> V_38 ) ,
V_39 | V_40 ,
F_10 ( V_17 +
V_18 ) ) ;
if ( ! V_29 )
V_29 = F_11 ( V_39 | V_40 ,
F_10 ( V_17 +
V_18 ) ) ;
if ( ! V_29 ) {
V_28 = - V_41 ;
goto V_42;
}
V_16 -> V_43 = F_12 ( V_29 ) ;
V_16 -> V_44 = ( V_17 +
V_18 ) >> V_45 ;
V_27 = F_13 ( & V_16 -> V_46 , V_29 ,
V_17 >> V_45 ) ;
if ( V_27 != 0 ) {
V_28 = V_27 ;
goto V_47;
}
V_27 = F_13 ( & V_16 -> V_48 ,
& V_29 [ V_17 >> V_45 ] ,
V_18 >> V_45 ) ;
if ( V_27 != 0 ) {
V_28 = V_27 ;
goto V_47;
}
V_16 -> V_49 = 0 ;
V_27 = F_14 ( V_16 ,
F_12 ( V_29 ) ,
V_17 +
V_18 ,
& V_16 -> V_49 ) ;
if ( V_27 != 0 ) {
V_28 = V_27 ;
goto V_47;
}
V_25 = F_15 ( sizeof( * V_25 ) +
sizeof( struct V_22 ) ,
V_39 ) ;
if ( ! V_25 ) {
V_28 = - V_41 ;
goto V_50;
}
F_16 ( & V_25 -> V_51 ) ;
V_23 = (struct V_22 * ) V_25 -> V_52 ;
V_23 -> V_53 . V_54 = V_55 ;
V_23 -> V_56 = V_16 -> V_5 . V_8 ;
V_23 -> V_8 = V_16 -> V_5 . V_8 ;
V_23 -> V_49 = V_16 -> V_49 ;
V_23 -> V_57 = V_17 >>
V_45 ;
V_23 -> V_58 = V_16 -> V_58 ;
if ( V_20 > V_59 ) {
V_28 = - V_31 ;
goto V_50;
}
if ( V_20 )
memcpy ( V_23 -> V_19 , V_19 , V_20 ) ;
F_6 ( & V_9 . V_60 , V_26 ) ;
F_17 ( & V_25 -> V_61 ,
& V_9 . V_62 ) ;
F_7 ( & V_9 . V_60 , V_26 ) ;
V_27 = F_18 ( V_23 ,
sizeof( struct V_22 ) ) ;
if ( V_27 != 0 ) {
V_28 = V_27 ;
goto V_63;
}
F_19 ( & V_25 -> V_51 ) ;
F_6 ( & V_9 . V_60 , V_26 ) ;
F_20 ( & V_25 -> V_61 ) ;
F_7 ( & V_9 . V_60 , V_26 ) ;
if ( V_25 -> V_64 . V_65 . V_66 ) {
V_28 = - V_67 ;
goto V_50;
}
V_16 -> V_33 = V_68 ;
F_21 ( V_25 ) ;
return 0 ;
V_63:
F_6 ( & V_9 . V_60 , V_26 ) ;
F_20 ( & V_25 -> V_61 ) ;
F_7 ( & V_9 . V_60 , V_26 ) ;
V_50:
F_22 ( V_16 , V_16 -> V_49 ) ;
F_21 ( V_25 ) ;
V_47:
F_23 ( & V_16 -> V_46 ) ;
F_23 ( & V_16 -> V_48 ) ;
F_24 ( V_29 ,
F_10 ( V_17 + V_18 ) ) ;
V_42:
V_16 -> V_33 = V_34 ;
return V_28 ;
}
int F_25 ( const T_2 * V_69 ,
const T_2 * V_70 )
{
struct V_71 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_53 . V_54 = V_73 ;
V_72 . V_74 = * V_69 ;
V_72 . V_75 = * V_70 ;
return F_18 ( & V_72 , sizeof( V_72 ) ) ;
}
static int F_26 ( void * V_76 , T_1 V_77 ,
struct V_24 * * V_78 )
{
int V_79 ;
int V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_24 * V_85 ;
struct V_24 * V_86 = NULL ;
T_1 V_87 ;
int V_88 , V_89 , V_90 , V_91 , V_92 ;
V_80 = V_77 >> V_45 ;
V_92 = V_93 -
sizeof( struct V_81 ) -
sizeof( struct V_94 ) ;
V_89 = V_92 / sizeof( V_95 ) ;
if ( V_80 > V_89 ) {
V_87 = sizeof( struct V_24 ) +
sizeof( struct V_81 ) +
sizeof( struct V_94 ) + V_89 * sizeof( V_95 ) ;
V_85 = F_27 ( V_87 , V_39 ) ;
if ( ! V_85 )
goto V_96;
F_28 ( & V_85 -> V_97 ) ;
V_85 -> V_87 = V_87 ;
V_82 = (struct V_81 * )
V_85 -> V_52 ;
V_82 -> V_98 = 1 ;
V_82 -> V_99 = sizeof( struct V_94 ) +
V_80 * sizeof( V_95 ) ;
V_82 -> V_100 [ 0 ] . V_101 = 0 ;
V_82 -> V_100 [ 0 ] . V_102 = V_77 ;
for ( V_79 = 0 ; V_79 < V_89 ; V_79 ++ )
V_82 -> V_100 [ 0 ] . V_103 [ V_79 ] = F_29 (
V_76 + V_30 * V_79 ) >> V_45 ;
* V_78 = V_85 ;
V_88 = V_89 ;
V_90 = V_80 - V_89 ;
V_92 = V_93 -
sizeof( struct V_83 ) ;
V_89 = V_92 / sizeof( V_95 ) ;
while ( V_90 ) {
if ( V_90 > V_89 )
V_91 = V_89 ;
else
V_91 = V_90 ;
V_87 = sizeof( struct V_24 ) +
sizeof( struct V_83 ) +
V_91 * sizeof( V_95 ) ;
V_86 = F_27 ( V_87 , V_39 ) ;
if ( ! V_86 ) {
struct V_24 * V_104 = NULL ;
struct V_24 * V_105 = NULL ;
F_30 (pos, tmp,
&msgheader->submsglist,
msglistentry) {
F_20 ( & V_104 -> V_61 ) ;
F_21 ( V_104 ) ;
}
goto V_96;
}
V_86 -> V_87 = V_87 ;
V_84 =
(struct V_83 * ) V_86 -> V_52 ;
for ( V_79 = 0 ; V_79 < V_91 ; V_79 ++ )
V_84 -> V_106 [ V_79 ] = F_29 (
V_76 + V_30 * ( V_88 + V_79 ) ) >>
V_45 ;
F_17 ( & V_86 -> V_61 ,
& V_85 -> V_97 ) ;
V_88 += V_91 ;
V_90 -= V_91 ;
}
} else {
V_87 = sizeof( struct V_24 ) +
sizeof( struct V_81 ) +
sizeof( struct V_94 ) + V_80 * sizeof( V_95 ) ;
V_85 = F_27 ( V_87 , V_39 ) ;
if ( V_85 == NULL )
goto V_96;
F_28 ( & V_85 -> V_97 ) ;
V_85 -> V_87 = V_87 ;
V_82 = (struct V_81 * )
V_85 -> V_52 ;
V_82 -> V_98 = 1 ;
V_82 -> V_99 = sizeof( struct V_94 ) +
V_80 * sizeof( V_95 ) ;
V_82 -> V_100 [ 0 ] . V_101 = 0 ;
V_82 -> V_100 [ 0 ] . V_102 = V_77 ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ )
V_82 -> V_100 [ 0 ] . V_103 [ V_79 ] = F_29 (
V_76 + V_30 * V_79 ) >> V_45 ;
* V_78 = V_85 ;
}
return 0 ;
V_96:
F_21 ( V_85 ) ;
F_21 ( V_86 ) ;
return - V_41 ;
}
int F_14 ( struct V_1 * V_2 , void * V_76 ,
T_1 V_77 , T_1 * V_107 )
{
struct V_81 * V_108 ;
struct V_83 * V_84 ;
struct V_24 * V_78 = NULL ;
struct V_24 * V_109 , * V_105 ;
struct V_110 * V_111 ;
T_1 V_112 ;
unsigned long V_26 ;
int V_27 = 0 ;
V_112 =
( F_31 ( & V_9 . V_112 ) - 1 ) ;
V_27 = F_26 ( V_76 , V_77 , & V_78 ) ;
if ( V_27 )
return V_27 ;
F_16 ( & V_78 -> V_51 ) ;
V_108 = (struct V_81 * ) V_78 -> V_52 ;
V_108 -> V_53 . V_54 = V_113 ;
V_108 -> V_8 = V_2 -> V_5 . V_8 ;
V_108 -> V_114 = V_112 ;
F_6 ( & V_9 . V_60 , V_26 ) ;
F_17 ( & V_78 -> V_61 ,
& V_9 . V_62 ) ;
F_7 ( & V_9 . V_60 , V_26 ) ;
V_27 = F_18 ( V_108 , V_78 -> V_87 -
sizeof( * V_78 ) ) ;
if ( V_27 != 0 )
goto V_115;
F_32 (curr, &msginfo->submsglist) {
V_109 = (struct V_24 * ) V_111 ;
V_84 =
(struct V_83 * ) V_109 -> V_52 ;
V_84 -> V_53 . V_54 =
V_116 ;
V_84 -> V_114 = V_112 ;
V_27 = F_18 ( V_84 ,
V_109 -> V_87 -
sizeof( * V_109 ) ) ;
if ( V_27 != 0 )
goto V_115;
}
F_19 ( & V_78 -> V_51 ) ;
* V_107 = V_108 -> V_114 ;
V_115:
F_6 ( & V_9 . V_60 , V_26 ) ;
F_20 ( & V_78 -> V_61 ) ;
F_7 ( & V_9 . V_60 , V_26 ) ;
F_30 (submsginfo, tmp, &msginfo->submsglist,
msglistentry) {
F_21 ( V_109 ) ;
}
F_21 ( V_78 ) ;
return V_27 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_107 )
{
struct V_117 * V_52 ;
struct V_24 * V_118 ;
unsigned long V_26 ;
int V_27 ;
V_118 = F_15 ( sizeof( * V_118 ) +
sizeof( struct V_117 ) , V_39 ) ;
if ( ! V_118 )
return - V_41 ;
F_16 ( & V_118 -> V_51 ) ;
V_52 = (struct V_117 * ) V_118 -> V_52 ;
V_52 -> V_53 . V_54 = V_119 ;
V_52 -> V_8 = V_2 -> V_5 . V_8 ;
V_52 -> V_114 = V_107 ;
F_6 ( & V_9 . V_60 , V_26 ) ;
F_17 ( & V_118 -> V_61 ,
& V_9 . V_62 ) ;
F_7 ( & V_9 . V_60 , V_26 ) ;
V_27 = F_18 ( V_52 ,
sizeof( struct V_117 ) ) ;
if ( V_27 )
goto V_120;
F_19 ( & V_118 -> V_51 ) ;
V_120:
F_6 ( & V_9 . V_60 , V_26 ) ;
F_20 ( & V_118 -> V_61 ) ;
F_7 ( & V_9 . V_60 , V_26 ) ;
F_21 ( V_118 ) ;
return V_27 ;
}
static void F_33 ( void * V_121 )
{
struct V_1 * V_2 = V_121 ;
V_2 -> V_36 = NULL ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_122 * V_52 ;
int V_27 ;
F_35 ( V_2 ) ;
if ( V_2 -> V_33 != V_68 ) {
V_27 = - V_31 ;
goto V_123;
}
V_2 -> V_33 = V_34 ;
V_2 -> V_124 = NULL ;
if ( V_2 -> V_38 != F_36 () ) {
F_37 () ;
F_38 ( V_2 -> V_38 , F_33 ,
V_2 , true ) ;
} else {
F_33 ( V_2 ) ;
F_37 () ;
}
V_52 = & V_2 -> V_125 . V_52 ;
V_52 -> V_53 . V_54 = V_126 ;
V_52 -> V_8 = V_2 -> V_5 . V_8 ;
V_27 = F_18 ( V_52 , sizeof( struct V_122 ) ) ;
if ( V_27 ) {
F_39 ( L_1 , V_27 ) ;
goto V_123;
}
if ( V_2 -> V_49 ) {
V_27 = F_22 ( V_2 ,
V_2 -> V_49 ) ;
if ( V_27 ) {
F_39 ( L_2 , V_27 ) ;
goto V_123;
}
}
F_23 ( & V_2 -> V_46 ) ;
F_23 ( & V_2 -> V_48 ) ;
F_40 ( ( unsigned long ) V_2 -> V_43 ,
F_10 ( V_2 -> V_44 * V_30 ) ) ;
V_123:
F_41 ( V_2 ) ;
return V_27 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_110 * V_127 , * V_105 ;
struct V_1 * V_128 ;
if ( V_2 -> V_129 != NULL ) {
return;
}
F_43 (cur, tmp, &channel->sc_list) {
V_128 = F_44 ( V_127 , struct V_1 , V_130 ) ;
if ( V_128 -> V_33 != V_68 )
continue;
F_34 ( V_128 ) ;
}
F_34 ( V_2 ) ;
}
int F_45 ( struct V_1 * V_2 , void * V_131 ,
T_1 V_132 , V_95 V_133 ,
enum V_134 type , T_1 V_26 , bool V_135 )
{
struct V_136 V_137 ;
T_1 V_138 = sizeof( struct V_136 ) + V_132 ;
T_1 V_139 = F_46 ( V_138 , sizeof( V_95 ) ) ;
struct V_140 V_141 [ 3 ] ;
V_95 V_142 = 0 ;
bool V_32 = V_2 -> V_143 ;
int V_144 = ( ( V_132 != 0 ) ? 3 : 1 ) ;
V_137 . type = type ;
V_137 . V_26 = V_26 ;
V_137 . V_145 = sizeof( struct V_136 ) >> 3 ;
V_137 . V_146 = ( V_147 ) ( V_139 >> 3 ) ;
V_137 . V_148 = V_133 ;
V_141 [ 0 ] . V_149 = & V_137 ;
V_141 [ 0 ] . V_150 = sizeof( struct V_136 ) ;
V_141 [ 1 ] . V_149 = V_131 ;
V_141 [ 1 ] . V_150 = V_132 ;
V_141 [ 2 ] . V_149 = & V_142 ;
V_141 [ 2 ] . V_150 = ( V_139 - V_138 ) ;
return F_47 ( V_2 , V_141 , V_144 ,
V_32 , V_135 ) ;
}
int F_48 ( struct V_1 * V_2 , void * V_131 ,
T_1 V_132 , V_95 V_133 ,
enum V_134 type , T_1 V_26 )
{
return F_45 ( V_2 , V_131 , V_132 , V_133 ,
type , V_26 , true ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_151 V_152 [] ,
T_1 V_80 , void * V_131 , T_1 V_132 ,
V_95 V_133 ,
T_1 V_26 ,
bool V_135 )
{
int V_79 ;
struct V_153 V_137 ;
T_1 V_154 ;
T_1 V_138 ;
T_1 V_139 ;
struct V_140 V_141 [ 3 ] ;
V_95 V_142 = 0 ;
bool V_32 = V_2 -> V_143 ;
if ( V_80 > V_155 )
return - V_31 ;
V_154 = sizeof( struct V_153 ) -
( ( V_155 - V_80 ) *
sizeof( struct V_151 ) ) ;
V_138 = V_154 + V_132 ;
V_139 = F_46 ( V_138 , sizeof( V_95 ) ) ;
V_137 . type = V_156 ;
V_137 . V_26 = V_26 ;
V_137 . V_157 = V_154 >> 3 ;
V_137 . V_158 = ( V_147 ) ( V_139 >> 3 ) ;
V_137 . V_159 = V_133 ;
V_137 . V_98 = V_80 ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
V_137 . V_100 [ V_79 ] . V_160 = V_152 [ V_79 ] . V_160 ;
V_137 . V_100 [ V_79 ] . V_161 = V_152 [ V_79 ] . V_161 ;
V_137 . V_100 [ V_79 ] . V_106 = V_152 [ V_79 ] . V_106 ;
}
V_141 [ 0 ] . V_149 = & V_137 ;
V_141 [ 0 ] . V_150 = V_154 ;
V_141 [ 1 ] . V_149 = V_131 ;
V_141 [ 1 ] . V_150 = V_132 ;
V_141 [ 2 ] . V_149 = & V_142 ;
V_141 [ 2 ] . V_150 = ( V_139 - V_138 ) ;
return F_47 ( V_2 , V_141 , 3 ,
V_32 , V_135 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_151 V_152 [] ,
T_1 V_80 , void * V_131 , T_1 V_132 ,
V_95 V_133 )
{
T_1 V_26 = V_162 ;
return F_49 ( V_2 , V_152 , V_80 ,
V_131 , V_132 , V_133 ,
V_26 , true ) ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_163 * V_137 ,
T_1 V_164 ,
void * V_131 , T_1 V_132 , V_95 V_133 )
{
T_1 V_138 ;
T_1 V_139 ;
struct V_140 V_141 [ 3 ] ;
V_95 V_142 = 0 ;
bool V_32 = V_2 -> V_143 ;
V_138 = V_164 + V_132 ;
V_139 = F_46 ( V_138 , sizeof( V_95 ) ) ;
V_137 -> type = V_156 ;
V_137 -> V_26 = V_162 ;
V_137 -> V_157 = V_164 >> 3 ;
V_137 -> V_158 = ( V_147 ) ( V_139 >> 3 ) ;
V_137 -> V_159 = V_133 ;
V_137 -> V_98 = 1 ;
V_141 [ 0 ] . V_149 = V_137 ;
V_141 [ 0 ] . V_150 = V_164 ;
V_141 [ 1 ] . V_149 = V_131 ;
V_141 [ 1 ] . V_150 = V_132 ;
V_141 [ 2 ] . V_149 = & V_142 ;
V_141 [ 2 ] . V_150 = ( V_139 - V_138 ) ;
return F_47 ( V_2 , V_141 , 3 ,
V_32 , true ) ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_165 * V_166 ,
void * V_131 , T_1 V_132 , V_95 V_133 )
{
struct V_167 V_137 ;
T_1 V_154 ;
T_1 V_138 ;
T_1 V_139 ;
struct V_140 V_141 [ 3 ] ;
V_95 V_142 = 0 ;
bool V_32 = V_2 -> V_143 ;
T_1 V_89 = F_53 ( V_166 -> V_161 ,
V_166 -> V_160 ) ;
if ( V_89 > V_168 )
return - V_31 ;
V_154 = sizeof( struct V_167 ) -
( ( V_168 - V_89 ) *
sizeof( V_95 ) ) ;
V_138 = V_154 + V_132 ;
V_139 = F_46 ( V_138 , sizeof( V_95 ) ) ;
V_137 . type = V_156 ;
V_137 . V_26 = V_162 ;
V_137 . V_157 = V_154 >> 3 ;
V_137 . V_158 = ( V_147 ) ( V_139 >> 3 ) ;
V_137 . V_159 = V_133 ;
V_137 . V_98 = 1 ;
V_137 . V_100 . V_160 = V_166 -> V_160 ;
V_137 . V_100 . V_161 = V_166 -> V_161 ;
memcpy ( V_137 . V_100 . V_103 , V_166 -> V_103 ,
V_89 * sizeof( V_95 ) ) ;
V_141 [ 0 ] . V_149 = & V_137 ;
V_141 [ 0 ] . V_150 = V_154 ;
V_141 [ 1 ] . V_149 = V_131 ;
V_141 [ 1 ] . V_150 = V_132 ;
V_141 [ 2 ] . V_149 = & V_142 ;
V_141 [ 2 ] . V_150 = ( V_139 - V_138 ) ;
return F_47 ( V_2 , V_141 , 3 ,
V_32 , true ) ;
}
static inline int
F_54 ( struct V_1 * V_2 , void * V_131 ,
T_1 V_132 , T_1 * V_169 , V_95 * V_133 ,
bool V_170 )
{
return F_55 ( V_2 , V_131 , V_132 ,
V_169 , V_133 , V_170 ) ;
}
int F_56 ( struct V_1 * V_2 , void * V_131 ,
T_1 V_132 , T_1 * V_169 ,
V_95 * V_133 )
{
return F_54 ( V_2 , V_131 , V_132 ,
V_169 , V_133 , false ) ;
}
int F_57 ( struct V_1 * V_2 , void * V_131 ,
T_1 V_132 , T_1 * V_169 ,
V_95 * V_133 )
{
return F_54 ( V_2 , V_131 , V_132 ,
V_169 , V_133 , true ) ;
}
