static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_5 . V_6 ) {
F_2 ( V_2 -> V_5 . V_7 & 31 ,
( unsigned long * ) V_8 . V_9 +
( V_2 -> V_5 . V_7 >> 5 ) ) ;
V_4 = V_8 . V_10 [ 1 ] ;
F_2 ( V_2 -> V_11 ,
( unsigned long * ) & V_4 -> V_12
[ V_2 -> V_13 ] . V_14 ) ;
} else {
F_3 ( V_2 ) ;
}
}
int F_4 ( struct V_1 * V_15 , T_1 V_16 ,
T_1 V_17 , void * V_18 , T_1 V_19 ,
void (* F_5)( void * V_20 ) , void * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 = NULL ;
void * V_25 , * V_26 ;
unsigned long V_27 ;
int V_28 , V_29 = 0 ;
unsigned long V_30 ;
struct V_31 * V_31 ;
F_6 ( & V_15 -> V_32 , V_27 ) ;
if ( V_15 -> V_33 == V_34 ) {
V_15 -> V_33 = V_35 ;
} else {
F_7 ( & V_15 -> V_32 , V_27 ) ;
return - V_36 ;
}
F_7 ( & V_15 -> V_32 , V_27 ) ;
V_15 -> V_37 = F_5 ;
V_15 -> V_38 = V_20 ;
V_31 = F_8 ( F_9 ( V_15 -> V_39 ) ,
V_40 | V_41 ,
F_10 ( V_16 +
V_17 ) ) ;
if ( ! V_31 )
V_26 = ( void * ) F_11 ( V_40 | V_41 ,
F_10 ( V_16 +
V_17 ) ) ;
else
V_26 = ( void * ) F_12 ( V_31 ) ;
if ( ! V_26 ) {
V_29 = - V_42 ;
goto V_43;
}
V_25 = ( void * ) ( ( unsigned long ) V_26 + V_16 ) ;
V_15 -> V_44 = V_26 ;
V_15 -> V_45 = ( V_16 +
V_17 ) >> V_46 ;
V_28 = F_13 (
& V_15 -> V_47 , V_26 , V_16 ) ;
if ( V_28 != 0 ) {
V_29 = V_28 ;
goto V_43;
}
V_28 = F_13 (
& V_15 -> V_48 , V_25 , V_17 ) ;
if ( V_28 != 0 ) {
V_29 = V_28 ;
goto V_43;
}
V_15 -> V_49 = 0 ;
V_28 = F_14 ( V_15 ,
V_15 -> V_47 . V_50 ,
V_16 +
V_17 ,
& V_15 -> V_49 ) ;
if ( V_28 != 0 ) {
V_29 = V_28 ;
goto V_43;
}
V_24 = F_15 ( sizeof( * V_24 ) +
sizeof( struct V_21 ) ,
V_40 ) ;
if ( ! V_24 ) {
V_29 = - V_42 ;
goto V_51;
}
F_16 ( & V_24 -> V_52 ) ;
V_22 = (struct V_21 * ) V_24 -> V_53 ;
V_22 -> V_54 . V_55 = V_56 ;
V_22 -> V_57 = V_15 -> V_5 . V_7 ;
V_22 -> V_7 = V_15 -> V_5 . V_7 ;
V_22 -> V_49 = V_15 -> V_49 ;
V_22 -> V_58 = V_16 >>
V_46 ;
V_22 -> V_59 = V_15 -> V_59 ;
if ( V_19 > V_60 ) {
V_29 = - V_36 ;
goto V_51;
}
if ( V_19 )
memcpy ( V_22 -> V_18 , V_18 , V_19 ) ;
F_6 ( & V_8 . V_61 , V_27 ) ;
F_17 ( & V_24 -> V_62 ,
& V_8 . V_63 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
V_28 = F_18 ( V_22 ,
sizeof( struct V_21 ) ) ;
if ( V_28 != 0 ) {
V_29 = V_28 ;
goto V_64;
}
V_30 = F_19 ( & V_24 -> V_52 , 5 * V_65 ) ;
if ( V_30 == 0 ) {
V_29 = - V_66 ;
goto V_64;
}
F_6 ( & V_8 . V_61 , V_27 ) ;
F_20 ( & V_24 -> V_62 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
if ( V_24 -> V_67 . V_68 . V_69 ) {
V_29 = - V_70 ;
goto V_51;
}
V_15 -> V_33 = V_71 ;
F_21 ( V_24 ) ;
return 0 ;
V_64:
F_6 ( & V_8 . V_61 , V_27 ) ;
F_20 ( & V_24 -> V_62 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
V_51:
F_22 ( V_15 , V_15 -> V_49 ) ;
V_43:
F_23 ( ( unsigned long ) V_26 ,
F_10 ( V_16 + V_17 ) ) ;
F_21 ( V_24 ) ;
V_15 -> V_33 = V_34 ;
return V_29 ;
}
int F_24 ( const T_2 * V_72 ,
const T_2 * V_73 )
{
struct V_74 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_54 . V_55 = V_76 ;
V_75 . V_77 = * V_72 ;
V_75 . V_78 = * V_73 ;
return F_18 ( & V_75 , sizeof( V_75 ) ) ;
}
static int F_25 ( void * V_79 , T_1 V_80 ,
struct V_23 * * V_81 ,
T_1 * V_82 )
{
int V_83 ;
int V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_23 * V_89 ;
struct V_23 * V_90 = NULL ;
T_1 V_91 ;
int V_92 , V_93 , V_94 , V_95 , V_96 ;
V_84 = V_80 >> V_46 ;
V_96 = V_97 -
sizeof( struct V_85 ) -
sizeof( struct V_98 ) ;
V_93 = V_96 / sizeof( V_99 ) ;
if ( V_84 > V_93 ) {
V_91 = sizeof( struct V_23 ) +
sizeof( struct V_85 ) +
sizeof( struct V_98 ) + V_93 * sizeof( V_99 ) ;
V_89 = F_26 ( V_91 , V_40 ) ;
if ( ! V_89 )
goto V_100;
F_27 ( & V_89 -> V_101 ) ;
V_89 -> V_91 = V_91 ;
V_86 = (struct V_85 * )
V_89 -> V_53 ;
V_86 -> V_102 = 1 ;
V_86 -> V_103 = sizeof( struct V_98 ) +
V_84 * sizeof( V_99 ) ;
V_86 -> V_104 [ 0 ] . V_105 = 0 ;
V_86 -> V_104 [ 0 ] . V_106 = V_80 ;
for ( V_83 = 0 ; V_83 < V_93 ; V_83 ++ )
V_86 -> V_104 [ 0 ] . V_107 [ V_83 ] = F_28 (
V_79 + V_108 * V_83 ) >> V_46 ;
* V_81 = V_89 ;
* V_82 = 1 ;
V_92 = V_93 ;
V_94 = V_84 - V_93 ;
V_96 = V_97 -
sizeof( struct V_87 ) ;
V_93 = V_96 / sizeof( V_99 ) ;
while ( V_94 ) {
if ( V_94 > V_93 )
V_95 = V_93 ;
else
V_95 = V_94 ;
V_91 = sizeof( struct V_23 ) +
sizeof( struct V_87 ) +
V_95 * sizeof( V_99 ) ;
V_90 = F_26 ( V_91 , V_40 ) ;
if ( ! V_90 ) {
struct V_23 * V_109 = NULL ;
struct V_23 * V_110 = NULL ;
F_29 (pos, tmp,
&msgheader->submsglist,
msglistentry) {
F_20 ( & V_109 -> V_62 ) ;
F_21 ( V_109 ) ;
}
goto V_100;
}
V_90 -> V_91 = V_91 ;
( * V_82 ) ++ ;
V_88 =
(struct V_87 * ) V_90 -> V_53 ;
for ( V_83 = 0 ; V_83 < V_95 ; V_83 ++ )
V_88 -> V_111 [ V_83 ] = F_28 (
V_79 + V_108 * ( V_92 + V_83 ) ) >>
V_46 ;
F_17 ( & V_90 -> V_62 ,
& V_89 -> V_101 ) ;
V_92 += V_95 ;
V_94 -= V_95 ;
}
} else {
V_91 = sizeof( struct V_23 ) +
sizeof( struct V_85 ) +
sizeof( struct V_98 ) + V_84 * sizeof( V_99 ) ;
V_89 = F_26 ( V_91 , V_40 ) ;
if ( V_89 == NULL )
goto V_100;
V_89 -> V_91 = V_91 ;
V_86 = (struct V_85 * )
V_89 -> V_53 ;
V_86 -> V_102 = 1 ;
V_86 -> V_103 = sizeof( struct V_98 ) +
V_84 * sizeof( V_99 ) ;
V_86 -> V_104 [ 0 ] . V_105 = 0 ;
V_86 -> V_104 [ 0 ] . V_106 = V_80 ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ )
V_86 -> V_104 [ 0 ] . V_107 [ V_83 ] = F_28 (
V_79 + V_108 * V_83 ) >> V_46 ;
* V_81 = V_89 ;
* V_82 = 1 ;
}
return 0 ;
V_100:
F_21 ( V_89 ) ;
F_21 ( V_90 ) ;
return - V_42 ;
}
int F_14 ( struct V_1 * V_2 , void * V_79 ,
T_1 V_80 , T_1 * V_112 )
{
struct V_85 * V_113 ;
struct V_87 * V_88 ;
struct V_23 * V_81 = NULL ;
struct V_23 * V_114 ;
T_1 V_115 ;
struct V_116 * V_117 ;
T_1 V_118 ;
unsigned long V_27 ;
int V_28 = 0 ;
V_118 =
( F_30 ( & V_8 . V_118 ) - 1 ) ;
V_28 = F_25 ( V_79 , V_80 , & V_81 , & V_115 ) ;
if ( V_28 )
return V_28 ;
F_16 ( & V_81 -> V_52 ) ;
V_113 = (struct V_85 * ) V_81 -> V_53 ;
V_113 -> V_54 . V_55 = V_119 ;
V_113 -> V_7 = V_2 -> V_5 . V_7 ;
V_113 -> V_120 = V_118 ;
F_6 ( & V_8 . V_61 , V_27 ) ;
F_17 ( & V_81 -> V_62 ,
& V_8 . V_63 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
V_28 = F_18 ( V_113 , V_81 -> V_91 -
sizeof( * V_81 ) ) ;
if ( V_28 != 0 )
goto V_121;
if ( V_115 > 1 ) {
F_31 (curr, &msginfo->submsglist) {
V_114 = (struct V_23 * ) V_117 ;
V_88 =
(struct V_87 * ) V_114 -> V_53 ;
V_88 -> V_54 . V_55 =
V_122 ;
V_88 -> V_120 = V_118 ;
V_28 = F_18 ( V_88 ,
V_114 -> V_91 -
sizeof( * V_114 ) ) ;
if ( V_28 != 0 )
goto V_121;
}
}
F_32 ( & V_81 -> V_52 ) ;
* V_112 = V_113 -> V_120 ;
V_121:
F_6 ( & V_8 . V_61 , V_27 ) ;
F_20 ( & V_81 -> V_62 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
F_21 ( V_81 ) ;
return V_28 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_112 )
{
struct V_123 * V_53 ;
struct V_23 * V_124 ;
unsigned long V_27 ;
int V_28 ;
V_124 = F_15 ( sizeof( * V_124 ) +
sizeof( struct V_123 ) , V_40 ) ;
if ( ! V_124 )
return - V_42 ;
F_16 ( & V_124 -> V_52 ) ;
V_53 = (struct V_123 * ) V_124 -> V_53 ;
V_53 -> V_54 . V_55 = V_125 ;
V_53 -> V_7 = V_2 -> V_5 . V_7 ;
V_53 -> V_120 = V_112 ;
F_6 ( & V_8 . V_61 , V_27 ) ;
F_17 ( & V_124 -> V_62 ,
& V_8 . V_63 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
V_28 = F_18 ( V_53 ,
sizeof( struct V_123 ) ) ;
if ( V_28 )
goto V_126;
F_32 ( & V_124 -> V_52 ) ;
V_126:
F_6 ( & V_8 . V_61 , V_27 ) ;
F_20 ( & V_124 -> V_62 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
F_21 ( V_124 ) ;
return V_28 ;
}
static void F_33 ( void * V_127 )
{
struct V_1 * V_2 = V_127 ;
V_2 -> V_37 = NULL ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_128 * V_53 ;
struct V_129 * V_130 ;
int V_28 ;
V_130 = V_131 . V_132 [ V_2 -> V_39 ] ;
F_35 ( V_130 ) ;
if ( V_2 -> V_33 != V_71 ) {
V_28 = - V_36 ;
goto V_26;
}
V_2 -> V_33 = V_34 ;
V_2 -> V_133 = NULL ;
if ( V_2 -> V_39 != F_36 () ) {
F_37 () ;
F_38 ( V_2 -> V_39 , F_33 ,
V_2 , true ) ;
} else {
F_33 ( V_2 ) ;
F_37 () ;
}
V_53 = & V_2 -> V_134 . V_53 ;
V_53 -> V_54 . V_55 = V_135 ;
V_53 -> V_7 = V_2 -> V_5 . V_7 ;
V_28 = F_18 ( V_53 , sizeof( struct V_128 ) ) ;
if ( V_28 ) {
F_39 ( L_1 , V_28 ) ;
goto V_26;
}
if ( V_2 -> V_49 ) {
V_28 = F_22 ( V_2 ,
V_2 -> V_49 ) ;
if ( V_28 ) {
F_39 ( L_2 , V_28 ) ;
goto V_26;
}
}
F_40 ( & V_2 -> V_47 ) ;
F_40 ( & V_2 -> V_48 ) ;
F_23 ( ( unsigned long ) V_2 -> V_44 ,
F_10 ( V_2 -> V_45 * V_108 ) ) ;
V_26:
F_41 ( V_130 ) ;
return V_28 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_116 * V_136 , * V_110 ;
struct V_1 * V_137 ;
if ( V_2 -> V_138 != NULL ) {
return;
}
F_43 (cur, tmp, &channel->sc_list) {
V_137 = F_44 ( V_136 , struct V_1 , V_139 ) ;
if ( V_137 -> V_33 != V_71 )
continue;
F_34 ( V_137 ) ;
}
F_34 ( V_2 ) ;
}
int F_45 ( struct V_1 * V_2 , void * V_140 ,
T_1 V_141 , V_99 V_142 ,
enum V_143 type , T_1 V_27 , bool V_144 )
{
struct V_145 V_146 ;
T_1 V_147 = sizeof( struct V_145 ) + V_141 ;
T_1 V_148 = F_46 ( V_147 , sizeof( V_99 ) ) ;
struct V_149 V_150 [ 3 ] ;
V_99 V_151 = 0 ;
int V_28 ;
bool signal = false ;
bool V_32 = V_2 -> V_152 ;
int V_153 = ( ( V_141 != 0 ) ? 3 : 1 ) ;
V_146 . type = type ;
V_146 . V_27 = V_27 ;
V_146 . V_154 = sizeof( struct V_145 ) >> 3 ;
V_146 . V_155 = ( V_156 ) ( V_148 >> 3 ) ;
V_146 . V_157 = V_142 ;
V_150 [ 0 ] . V_158 = & V_146 ;
V_150 [ 0 ] . V_159 = sizeof( struct V_145 ) ;
V_150 [ 1 ] . V_158 = V_140 ;
V_150 [ 1 ] . V_159 = V_141 ;
V_150 [ 2 ] . V_158 = & V_151 ;
V_150 [ 2 ] . V_159 = ( V_148 - V_147 ) ;
V_28 = F_47 ( & V_2 -> V_47 , V_150 , V_153 ,
& signal , V_32 ) ;
if ( V_2 -> V_160 )
signal = true ;
else
V_144 = true ;
if ( ( ( V_28 == 0 ) && V_144 && signal ) ||
( V_28 && ! F_48 ( V_2 ) ) )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_49 ( struct V_1 * V_2 , void * V_140 ,
T_1 V_141 , V_99 V_142 ,
enum V_143 type , T_1 V_27 )
{
return F_45 ( V_2 , V_140 , V_141 , V_142 ,
type , V_27 , true ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_161 V_162 [] ,
T_1 V_84 , void * V_140 , T_1 V_141 ,
V_99 V_142 ,
T_1 V_27 ,
bool V_144 )
{
int V_28 ;
int V_83 ;
struct V_163 V_146 ;
T_1 V_164 ;
T_1 V_147 ;
T_1 V_148 ;
struct V_149 V_150 [ 3 ] ;
V_99 V_151 = 0 ;
bool signal = false ;
bool V_32 = V_2 -> V_152 ;
if ( V_84 > V_165 )
return - V_36 ;
V_164 = sizeof( struct V_163 ) -
( ( V_165 - V_84 ) *
sizeof( struct V_161 ) ) ;
V_147 = V_164 + V_141 ;
V_148 = F_46 ( V_147 , sizeof( V_99 ) ) ;
V_146 . type = V_166 ;
V_146 . V_27 = V_27 ;
V_146 . V_167 = V_164 >> 3 ;
V_146 . V_168 = ( V_156 ) ( V_148 >> 3 ) ;
V_146 . V_169 = V_142 ;
V_146 . V_102 = V_84 ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
V_146 . V_104 [ V_83 ] . V_170 = V_162 [ V_83 ] . V_170 ;
V_146 . V_104 [ V_83 ] . V_171 = V_162 [ V_83 ] . V_171 ;
V_146 . V_104 [ V_83 ] . V_111 = V_162 [ V_83 ] . V_111 ;
}
V_150 [ 0 ] . V_158 = & V_146 ;
V_150 [ 0 ] . V_159 = V_164 ;
V_150 [ 1 ] . V_158 = V_140 ;
V_150 [ 1 ] . V_159 = V_141 ;
V_150 [ 2 ] . V_158 = & V_151 ;
V_150 [ 2 ] . V_159 = ( V_148 - V_147 ) ;
V_28 = F_47 ( & V_2 -> V_47 , V_150 , 3 ,
& signal , V_32 ) ;
if ( V_2 -> V_160 )
signal = true ;
else
V_144 = true ;
if ( ( ( V_28 == 0 ) && V_144 && signal ) || ( V_28 ) )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_161 V_162 [] ,
T_1 V_84 , void * V_140 , T_1 V_141 ,
V_99 V_142 )
{
T_1 V_27 = V_172 ;
return F_50 ( V_2 , V_162 , V_84 ,
V_140 , V_141 , V_142 ,
V_27 , true ) ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_173 * V_146 ,
T_1 V_174 ,
void * V_140 , T_1 V_141 , V_99 V_142 )
{
int V_28 ;
T_1 V_147 ;
T_1 V_148 ;
struct V_149 V_150 [ 3 ] ;
V_99 V_151 = 0 ;
bool signal = false ;
bool V_32 = V_2 -> V_152 ;
V_147 = V_174 + V_141 ;
V_148 = F_46 ( V_147 , sizeof( V_99 ) ) ;
V_146 -> type = V_166 ;
V_146 -> V_27 = V_172 ;
V_146 -> V_167 = V_174 >> 3 ;
V_146 -> V_168 = ( V_156 ) ( V_148 >> 3 ) ;
V_146 -> V_169 = V_142 ;
V_146 -> V_102 = 1 ;
V_150 [ 0 ] . V_158 = V_146 ;
V_150 [ 0 ] . V_159 = V_174 ;
V_150 [ 1 ] . V_158 = V_140 ;
V_150 [ 1 ] . V_159 = V_141 ;
V_150 [ 2 ] . V_158 = & V_151 ;
V_150 [ 2 ] . V_159 = ( V_148 - V_147 ) ;
V_28 = F_47 ( & V_2 -> V_47 , V_150 , 3 ,
& signal , V_32 ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_175 * V_176 ,
void * V_140 , T_1 V_141 , V_99 V_142 )
{
int V_28 ;
struct V_177 V_146 ;
T_1 V_164 ;
T_1 V_147 ;
T_1 V_148 ;
struct V_149 V_150 [ 3 ] ;
V_99 V_151 = 0 ;
bool signal = false ;
bool V_32 = V_2 -> V_152 ;
T_1 V_93 = F_54 ( V_176 -> V_171 ,
V_176 -> V_170 ) ;
if ( V_93 > V_178 )
return - V_36 ;
V_164 = sizeof( struct V_177 ) -
( ( V_178 - V_93 ) *
sizeof( V_99 ) ) ;
V_147 = V_164 + V_141 ;
V_148 = F_46 ( V_147 , sizeof( V_99 ) ) ;
V_146 . type = V_166 ;
V_146 . V_27 = V_172 ;
V_146 . V_167 = V_164 >> 3 ;
V_146 . V_168 = ( V_156 ) ( V_148 >> 3 ) ;
V_146 . V_169 = V_142 ;
V_146 . V_102 = 1 ;
V_146 . V_104 . V_170 = V_176 -> V_170 ;
V_146 . V_104 . V_171 = V_176 -> V_171 ;
memcpy ( V_146 . V_104 . V_107 , V_176 -> V_107 ,
V_93 * sizeof( V_99 ) ) ;
V_150 [ 0 ] . V_158 = & V_146 ;
V_150 [ 0 ] . V_159 = V_164 ;
V_150 [ 1 ] . V_158 = V_140 ;
V_150 [ 1 ] . V_159 = V_141 ;
V_150 [ 2 ] . V_158 = & V_151 ;
V_150 [ 2 ] . V_159 = ( V_148 - V_147 ) ;
V_28 = F_47 ( & V_2 -> V_47 , V_150 , 3 ,
& signal , V_32 ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
static inline int
F_55 ( struct V_1 * V_2 , void * V_140 ,
T_1 V_141 , T_1 * V_179 , V_99 * V_142 ,
bool V_180 )
{
int V_28 ;
bool signal = false ;
V_28 = F_56 ( & V_2 -> V_48 , V_140 , V_141 ,
V_179 , V_142 , & signal , V_180 ) ;
if ( signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_57 ( struct V_1 * V_2 , void * V_140 ,
T_1 V_141 , T_1 * V_179 ,
V_99 * V_142 )
{
return F_55 ( V_2 , V_140 , V_141 ,
V_179 , V_142 , false ) ;
}
int F_58 ( struct V_1 * V_2 , void * V_140 ,
T_1 V_141 , T_1 * V_179 ,
V_99 * V_142 )
{
return F_55 ( V_2 , V_140 , V_141 ,
V_179 , V_142 , true ) ;
}
