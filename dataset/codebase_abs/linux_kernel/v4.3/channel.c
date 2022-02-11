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
static int F_24 ( void * V_72 , T_1 V_73 ,
struct V_23 * * V_74 ,
T_1 * V_75 )
{
int V_76 ;
int V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_23 * V_82 ;
struct V_23 * V_83 = NULL ;
T_1 V_84 ;
int V_85 , V_86 , V_87 , V_88 , V_89 ;
V_77 = V_73 >> V_46 ;
V_89 = V_90 -
sizeof( struct V_78 ) -
sizeof( struct V_91 ) ;
V_86 = V_89 / sizeof( V_92 ) ;
if ( V_77 > V_86 ) {
V_84 = sizeof( struct V_23 ) +
sizeof( struct V_78 ) +
sizeof( struct V_91 ) + V_86 * sizeof( V_92 ) ;
V_82 = F_25 ( V_84 , V_40 ) ;
if ( ! V_82 )
goto V_93;
F_26 ( & V_82 -> V_94 ) ;
V_82 -> V_84 = V_84 ;
V_79 = (struct V_78 * )
V_82 -> V_53 ;
V_79 -> V_95 = 1 ;
V_79 -> V_96 = sizeof( struct V_91 ) +
V_77 * sizeof( V_92 ) ;
V_79 -> V_97 [ 0 ] . V_98 = 0 ;
V_79 -> V_97 [ 0 ] . V_99 = V_73 ;
for ( V_76 = 0 ; V_76 < V_86 ; V_76 ++ )
V_79 -> V_97 [ 0 ] . V_100 [ V_76 ] = F_27 (
V_72 + V_101 * V_76 ) >> V_46 ;
* V_74 = V_82 ;
* V_75 = 1 ;
V_85 = V_86 ;
V_87 = V_77 - V_86 ;
V_89 = V_90 -
sizeof( struct V_80 ) ;
V_86 = V_89 / sizeof( V_92 ) ;
while ( V_87 ) {
if ( V_87 > V_86 )
V_88 = V_86 ;
else
V_88 = V_87 ;
V_84 = sizeof( struct V_23 ) +
sizeof( struct V_80 ) +
V_88 * sizeof( V_92 ) ;
V_83 = F_25 ( V_84 , V_40 ) ;
if ( ! V_83 ) {
struct V_23 * V_102 = NULL ;
struct V_23 * V_103 = NULL ;
F_28 (pos, tmp,
&msgheader->submsglist,
msglistentry) {
F_20 ( & V_102 -> V_62 ) ;
F_21 ( V_102 ) ;
}
goto V_93;
}
V_83 -> V_84 = V_84 ;
( * V_75 ) ++ ;
V_81 =
(struct V_80 * ) V_83 -> V_53 ;
for ( V_76 = 0 ; V_76 < V_88 ; V_76 ++ )
V_81 -> V_104 [ V_76 ] = F_27 (
V_72 + V_101 * ( V_85 + V_76 ) ) >>
V_46 ;
F_17 ( & V_83 -> V_62 ,
& V_82 -> V_94 ) ;
V_85 += V_88 ;
V_87 -= V_88 ;
}
} else {
V_84 = sizeof( struct V_23 ) +
sizeof( struct V_78 ) +
sizeof( struct V_91 ) + V_77 * sizeof( V_92 ) ;
V_82 = F_25 ( V_84 , V_40 ) ;
if ( V_82 == NULL )
goto V_93;
V_82 -> V_84 = V_84 ;
V_79 = (struct V_78 * )
V_82 -> V_53 ;
V_79 -> V_95 = 1 ;
V_79 -> V_96 = sizeof( struct V_91 ) +
V_77 * sizeof( V_92 ) ;
V_79 -> V_97 [ 0 ] . V_98 = 0 ;
V_79 -> V_97 [ 0 ] . V_99 = V_73 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ )
V_79 -> V_97 [ 0 ] . V_100 [ V_76 ] = F_27 (
V_72 + V_101 * V_76 ) >> V_46 ;
* V_74 = V_82 ;
* V_75 = 1 ;
}
return 0 ;
V_93:
F_21 ( V_82 ) ;
F_21 ( V_83 ) ;
return - V_42 ;
}
int F_14 ( struct V_1 * V_2 , void * V_72 ,
T_1 V_73 , T_1 * V_105 )
{
struct V_78 * V_106 ;
struct V_80 * V_81 ;
struct V_23 * V_74 = NULL ;
struct V_23 * V_107 ;
T_1 V_108 ;
struct V_109 * V_110 ;
T_1 V_111 ;
unsigned long V_27 ;
int V_28 = 0 ;
V_111 =
( F_29 ( & V_8 . V_111 ) - 1 ) ;
V_28 = F_24 ( V_72 , V_73 , & V_74 , & V_108 ) ;
if ( V_28 )
return V_28 ;
F_16 ( & V_74 -> V_52 ) ;
V_106 = (struct V_78 * ) V_74 -> V_53 ;
V_106 -> V_54 . V_55 = V_112 ;
V_106 -> V_7 = V_2 -> V_5 . V_7 ;
V_106 -> V_113 = V_111 ;
F_6 ( & V_8 . V_61 , V_27 ) ;
F_17 ( & V_74 -> V_62 ,
& V_8 . V_63 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
V_28 = F_18 ( V_106 , V_74 -> V_84 -
sizeof( * V_74 ) ) ;
if ( V_28 != 0 )
goto V_114;
if ( V_108 > 1 ) {
F_30 (curr, &msginfo->submsglist) {
V_107 = (struct V_23 * ) V_110 ;
V_81 =
(struct V_80 * ) V_107 -> V_53 ;
V_81 -> V_54 . V_55 =
V_115 ;
V_81 -> V_113 = V_111 ;
V_28 = F_18 ( V_81 ,
V_107 -> V_84 -
sizeof( * V_107 ) ) ;
if ( V_28 != 0 )
goto V_114;
}
}
F_31 ( & V_74 -> V_52 ) ;
* V_105 = V_106 -> V_113 ;
V_114:
F_6 ( & V_8 . V_61 , V_27 ) ;
F_20 ( & V_74 -> V_62 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
F_21 ( V_74 ) ;
return V_28 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_105 )
{
struct V_116 * V_53 ;
struct V_23 * V_117 ;
unsigned long V_27 ;
int V_28 ;
V_117 = F_15 ( sizeof( * V_117 ) +
sizeof( struct V_116 ) , V_40 ) ;
if ( ! V_117 )
return - V_42 ;
F_16 ( & V_117 -> V_52 ) ;
V_53 = (struct V_116 * ) V_117 -> V_53 ;
V_53 -> V_54 . V_55 = V_118 ;
V_53 -> V_7 = V_2 -> V_5 . V_7 ;
V_53 -> V_113 = V_105 ;
F_6 ( & V_8 . V_61 , V_27 ) ;
F_17 ( & V_117 -> V_62 ,
& V_8 . V_63 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
V_28 = F_18 ( V_53 ,
sizeof( struct V_116 ) ) ;
if ( V_28 )
goto V_119;
F_31 ( & V_117 -> V_52 ) ;
V_119:
F_6 ( & V_8 . V_61 , V_27 ) ;
F_20 ( & V_117 -> V_62 ) ;
F_7 ( & V_8 . V_61 , V_27 ) ;
F_21 ( V_117 ) ;
return V_28 ;
}
static void F_32 ( void * V_120 )
{
struct V_1 * V_2 = V_120 ;
V_2 -> V_37 = NULL ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_121 * V_53 ;
int V_28 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_122 = NULL ;
if ( V_2 -> V_39 != F_34 () ) {
F_35 () ;
F_36 ( V_2 -> V_39 , F_32 ,
V_2 , true ) ;
} else {
F_32 ( V_2 ) ;
F_35 () ;
}
V_53 = & V_2 -> V_123 . V_53 ;
V_53 -> V_54 . V_55 = V_124 ;
V_53 -> V_7 = V_2 -> V_5 . V_7 ;
V_28 = F_18 ( V_53 , sizeof( struct V_121 ) ) ;
if ( V_28 ) {
F_37 ( L_1 , V_28 ) ;
return V_28 ;
}
if ( V_2 -> V_49 ) {
V_28 = F_22 ( V_2 ,
V_2 -> V_49 ) ;
if ( V_28 ) {
F_37 ( L_2 , V_28 ) ;
return V_28 ;
}
}
F_38 ( & V_2 -> V_47 ) ;
F_38 ( & V_2 -> V_48 ) ;
F_23 ( ( unsigned long ) V_2 -> V_44 ,
F_10 ( V_2 -> V_45 * V_101 ) ) ;
if ( V_2 -> V_125 )
F_39 ( V_2 ,
V_2 -> V_5 . V_7 ) ;
return V_28 ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_109 * V_126 , * V_103 ;
struct V_1 * V_127 ;
if ( V_2 -> V_128 != NULL ) {
return;
}
F_41 (cur, tmp, &channel->sc_list) {
V_127 = F_42 ( V_126 , struct V_1 , V_129 ) ;
if ( V_127 -> V_33 != V_71 )
continue;
F_33 ( V_127 ) ;
}
F_33 ( V_2 ) ;
}
int F_43 ( struct V_1 * V_2 , void * V_130 ,
T_1 V_131 , V_92 V_132 ,
enum V_133 type , T_1 V_27 , bool V_134 )
{
struct V_135 V_136 ;
T_1 V_137 = sizeof( struct V_135 ) + V_131 ;
T_1 V_138 = F_44 ( V_137 , sizeof( V_92 ) ) ;
struct V_139 V_140 [ 3 ] ;
V_92 V_141 = 0 ;
int V_28 ;
bool signal = false ;
int V_142 = ( ( V_131 != 0 ) ? 3 : 1 ) ;
V_136 . type = type ;
V_136 . V_27 = V_27 ;
V_136 . V_143 = sizeof( struct V_135 ) >> 3 ;
V_136 . V_144 = ( V_145 ) ( V_138 >> 3 ) ;
V_136 . V_146 = V_132 ;
V_140 [ 0 ] . V_147 = & V_136 ;
V_140 [ 0 ] . V_148 = sizeof( struct V_135 ) ;
V_140 [ 1 ] . V_147 = V_130 ;
V_140 [ 1 ] . V_148 = V_131 ;
V_140 [ 2 ] . V_147 = & V_141 ;
V_140 [ 2 ] . V_148 = ( V_138 - V_137 ) ;
V_28 = F_45 ( & V_2 -> V_47 , V_140 , V_142 ,
& signal ) ;
if ( ( ( V_28 == 0 ) && V_134 && signal ) || ( V_28 ) )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_46 ( struct V_1 * V_2 , void * V_130 ,
T_1 V_131 , V_92 V_132 ,
enum V_133 type , T_1 V_27 )
{
return F_43 ( V_2 , V_130 , V_131 , V_132 ,
type , V_27 , true ) ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_149 V_150 [] ,
T_1 V_77 , void * V_130 , T_1 V_131 ,
V_92 V_132 ,
T_1 V_27 ,
bool V_134 )
{
int V_28 ;
int V_76 ;
struct V_151 V_136 ;
T_1 V_152 ;
T_1 V_137 ;
T_1 V_138 ;
struct V_139 V_140 [ 3 ] ;
V_92 V_141 = 0 ;
bool signal = false ;
if ( V_77 > V_153 )
return - V_36 ;
V_152 = sizeof( struct V_151 ) -
( ( V_153 - V_77 ) *
sizeof( struct V_149 ) ) ;
V_137 = V_152 + V_131 ;
V_138 = F_44 ( V_137 , sizeof( V_92 ) ) ;
V_136 . type = V_154 ;
V_136 . V_27 = V_27 ;
V_136 . V_155 = V_152 >> 3 ;
V_136 . V_156 = ( V_145 ) ( V_138 >> 3 ) ;
V_136 . V_157 = V_132 ;
V_136 . V_95 = V_77 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
V_136 . V_97 [ V_76 ] . V_158 = V_150 [ V_76 ] . V_158 ;
V_136 . V_97 [ V_76 ] . V_159 = V_150 [ V_76 ] . V_159 ;
V_136 . V_97 [ V_76 ] . V_104 = V_150 [ V_76 ] . V_104 ;
}
V_140 [ 0 ] . V_147 = & V_136 ;
V_140 [ 0 ] . V_148 = V_152 ;
V_140 [ 1 ] . V_147 = V_130 ;
V_140 [ 1 ] . V_148 = V_131 ;
V_140 [ 2 ] . V_147 = & V_141 ;
V_140 [ 2 ] . V_148 = ( V_138 - V_137 ) ;
V_28 = F_45 ( & V_2 -> V_47 , V_140 , 3 , & signal ) ;
if ( ( ( V_28 == 0 ) && V_134 && signal ) || ( V_28 ) )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_149 V_150 [] ,
T_1 V_77 , void * V_130 , T_1 V_131 ,
V_92 V_132 )
{
T_1 V_27 = V_160 ;
return F_47 ( V_2 , V_150 , V_77 ,
V_130 , V_131 , V_132 ,
V_27 , true ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_161 * V_136 ,
T_1 V_162 ,
void * V_130 , T_1 V_131 , V_92 V_132 )
{
int V_28 ;
T_1 V_137 ;
T_1 V_138 ;
struct V_139 V_140 [ 3 ] ;
V_92 V_141 = 0 ;
bool signal = false ;
V_137 = V_162 + V_131 ;
V_138 = F_44 ( V_137 , sizeof( V_92 ) ) ;
V_136 -> type = V_154 ;
V_136 -> V_27 = V_160 ;
V_136 -> V_155 = V_162 >> 3 ;
V_136 -> V_156 = ( V_145 ) ( V_138 >> 3 ) ;
V_136 -> V_157 = V_132 ;
V_136 -> V_95 = 1 ;
V_140 [ 0 ] . V_147 = V_136 ;
V_140 [ 0 ] . V_148 = V_162 ;
V_140 [ 1 ] . V_147 = V_130 ;
V_140 [ 1 ] . V_148 = V_131 ;
V_140 [ 2 ] . V_147 = & V_141 ;
V_140 [ 2 ] . V_148 = ( V_138 - V_137 ) ;
V_28 = F_45 ( & V_2 -> V_47 , V_140 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_163 * V_164 ,
void * V_130 , T_1 V_131 , V_92 V_132 )
{
int V_28 ;
struct V_165 V_136 ;
T_1 V_152 ;
T_1 V_137 ;
T_1 V_138 ;
struct V_139 V_140 [ 3 ] ;
V_92 V_141 = 0 ;
bool signal = false ;
T_1 V_86 = F_51 ( V_164 -> V_159 ,
V_164 -> V_158 ) ;
if ( V_86 > V_166 )
return - V_36 ;
V_152 = sizeof( struct V_165 ) -
( ( V_166 - V_86 ) *
sizeof( V_92 ) ) ;
V_137 = V_152 + V_131 ;
V_138 = F_44 ( V_137 , sizeof( V_92 ) ) ;
V_136 . type = V_154 ;
V_136 . V_27 = V_160 ;
V_136 . V_155 = V_152 >> 3 ;
V_136 . V_156 = ( V_145 ) ( V_138 >> 3 ) ;
V_136 . V_157 = V_132 ;
V_136 . V_95 = 1 ;
V_136 . V_97 . V_158 = V_164 -> V_158 ;
V_136 . V_97 . V_159 = V_164 -> V_159 ;
memcpy ( V_136 . V_97 . V_100 , V_164 -> V_100 ,
V_86 * sizeof( V_92 ) ) ;
V_140 [ 0 ] . V_147 = & V_136 ;
V_140 [ 0 ] . V_148 = V_152 ;
V_140 [ 1 ] . V_147 = V_130 ;
V_140 [ 1 ] . V_148 = V_131 ;
V_140 [ 2 ] . V_147 = & V_141 ;
V_140 [ 2 ] . V_148 = ( V_138 - V_137 ) ;
V_28 = F_45 ( & V_2 -> V_47 , V_140 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_52 ( struct V_1 * V_2 , void * V_130 ,
T_1 V_131 , T_1 * V_167 , V_92 * V_132 )
{
struct V_135 V_136 ;
T_1 V_137 ;
T_1 V_168 ;
int V_28 ;
bool signal = false ;
* V_167 = 0 ;
* V_132 = 0 ;
V_28 = F_53 ( & V_2 -> V_48 , & V_136 ,
sizeof( struct V_135 ) ) ;
if ( V_28 != 0 )
return 0 ;
V_137 = V_136 . V_144 << 3 ;
V_168 = V_137 - ( V_136 . V_143 << 3 ) ;
* V_167 = V_168 ;
if ( V_168 > V_131 ) {
F_37 ( L_3 ,
V_131 , V_168 ) ;
return - V_169 ;
}
* V_132 = V_136 . V_146 ;
V_28 = F_54 ( & V_2 -> V_48 , V_130 , V_168 ,
( V_136 . V_143 << 3 ) , & signal ) ;
if ( signal )
F_1 ( V_2 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , void * V_130 ,
T_1 V_131 , T_1 * V_167 ,
V_92 * V_132 )
{
struct V_135 V_136 ;
T_1 V_137 ;
int V_28 ;
bool signal = false ;
* V_167 = 0 ;
* V_132 = 0 ;
V_28 = F_53 ( & V_2 -> V_48 , & V_136 ,
sizeof( struct V_135 ) ) ;
if ( V_28 != 0 )
return 0 ;
V_137 = V_136 . V_144 << 3 ;
* V_167 = V_137 ;
if ( V_137 > V_131 )
return - V_170 ;
* V_132 = V_136 . V_146 ;
V_28 = F_54 ( & V_2 -> V_48 , V_130 , V_137 , 0 ,
& signal ) ;
if ( signal )
F_1 ( V_2 ) ;
return V_28 ;
}
