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
struct V_122 * V_123 ;
int V_28 ;
V_123 = V_124 . V_125 [ V_2 -> V_39 ] ;
F_34 ( V_123 ) ;
if ( V_2 -> V_33 != V_71 ) {
V_28 = - V_36 ;
goto V_26;
}
V_2 -> V_33 = V_34 ;
V_2 -> V_126 = NULL ;
if ( V_2 -> V_39 != F_35 () ) {
F_36 () ;
F_37 ( V_2 -> V_39 , F_32 ,
V_2 , true ) ;
} else {
F_32 ( V_2 ) ;
F_36 () ;
}
V_53 = & V_2 -> V_127 . V_53 ;
V_53 -> V_54 . V_55 = V_128 ;
V_53 -> V_7 = V_2 -> V_5 . V_7 ;
V_28 = F_18 ( V_53 , sizeof( struct V_121 ) ) ;
if ( V_28 ) {
F_38 ( L_1 , V_28 ) ;
goto V_26;
}
if ( V_2 -> V_49 ) {
V_28 = F_22 ( V_2 ,
V_2 -> V_49 ) ;
if ( V_28 ) {
F_38 ( L_2 , V_28 ) ;
goto V_26;
}
}
F_39 ( & V_2 -> V_47 ) ;
F_39 ( & V_2 -> V_48 ) ;
F_23 ( ( unsigned long ) V_2 -> V_44 ,
F_10 ( V_2 -> V_45 * V_101 ) ) ;
V_26:
F_40 ( V_123 ) ;
return V_28 ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_109 * V_129 , * V_103 ;
struct V_1 * V_130 ;
if ( V_2 -> V_131 != NULL ) {
return;
}
F_42 (cur, tmp, &channel->sc_list) {
V_130 = F_43 ( V_129 , struct V_1 , V_132 ) ;
if ( V_130 -> V_33 != V_71 )
continue;
F_33 ( V_130 ) ;
}
F_33 ( V_2 ) ;
}
int F_44 ( struct V_1 * V_2 , void * V_133 ,
T_1 V_134 , V_92 V_135 ,
enum V_136 type , T_1 V_27 , bool V_137 )
{
struct V_138 V_139 ;
T_1 V_140 = sizeof( struct V_138 ) + V_134 ;
T_1 V_141 = F_45 ( V_140 , sizeof( V_92 ) ) ;
struct V_142 V_143 [ 3 ] ;
V_92 V_144 = 0 ;
int V_28 ;
bool signal = false ;
int V_145 = ( ( V_134 != 0 ) ? 3 : 1 ) ;
V_139 . type = type ;
V_139 . V_27 = V_27 ;
V_139 . V_146 = sizeof( struct V_138 ) >> 3 ;
V_139 . V_147 = ( V_148 ) ( V_141 >> 3 ) ;
V_139 . V_149 = V_135 ;
V_143 [ 0 ] . V_150 = & V_139 ;
V_143 [ 0 ] . V_151 = sizeof( struct V_138 ) ;
V_143 [ 1 ] . V_150 = V_133 ;
V_143 [ 1 ] . V_151 = V_134 ;
V_143 [ 2 ] . V_150 = & V_144 ;
V_143 [ 2 ] . V_151 = ( V_141 - V_140 ) ;
V_28 = F_46 ( & V_2 -> V_47 , V_143 , V_145 ,
& signal ) ;
if ( V_2 -> V_152 )
signal = true ;
else
V_137 = true ;
if ( ( ( V_28 == 0 ) && V_137 && signal ) || ( V_28 ) )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_47 ( struct V_1 * V_2 , void * V_133 ,
T_1 V_134 , V_92 V_135 ,
enum V_136 type , T_1 V_27 )
{
return F_44 ( V_2 , V_133 , V_134 , V_135 ,
type , V_27 , true ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_153 V_154 [] ,
T_1 V_77 , void * V_133 , T_1 V_134 ,
V_92 V_135 ,
T_1 V_27 ,
bool V_137 )
{
int V_28 ;
int V_76 ;
struct V_155 V_139 ;
T_1 V_156 ;
T_1 V_140 ;
T_1 V_141 ;
struct V_142 V_143 [ 3 ] ;
V_92 V_144 = 0 ;
bool signal = false ;
if ( V_77 > V_157 )
return - V_36 ;
V_156 = sizeof( struct V_155 ) -
( ( V_157 - V_77 ) *
sizeof( struct V_153 ) ) ;
V_140 = V_156 + V_134 ;
V_141 = F_45 ( V_140 , sizeof( V_92 ) ) ;
V_139 . type = V_158 ;
V_139 . V_27 = V_27 ;
V_139 . V_159 = V_156 >> 3 ;
V_139 . V_160 = ( V_148 ) ( V_141 >> 3 ) ;
V_139 . V_161 = V_135 ;
V_139 . V_95 = V_77 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
V_139 . V_97 [ V_76 ] . V_162 = V_154 [ V_76 ] . V_162 ;
V_139 . V_97 [ V_76 ] . V_163 = V_154 [ V_76 ] . V_163 ;
V_139 . V_97 [ V_76 ] . V_104 = V_154 [ V_76 ] . V_104 ;
}
V_143 [ 0 ] . V_150 = & V_139 ;
V_143 [ 0 ] . V_151 = V_156 ;
V_143 [ 1 ] . V_150 = V_133 ;
V_143 [ 1 ] . V_151 = V_134 ;
V_143 [ 2 ] . V_150 = & V_144 ;
V_143 [ 2 ] . V_151 = ( V_141 - V_140 ) ;
V_28 = F_46 ( & V_2 -> V_47 , V_143 , 3 , & signal ) ;
if ( V_2 -> V_152 )
signal = true ;
else
V_137 = true ;
if ( ( ( V_28 == 0 ) && V_137 && signal ) || ( V_28 ) )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_153 V_154 [] ,
T_1 V_77 , void * V_133 , T_1 V_134 ,
V_92 V_135 )
{
T_1 V_27 = V_164 ;
return F_48 ( V_2 , V_154 , V_77 ,
V_133 , V_134 , V_135 ,
V_27 , true ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_165 * V_139 ,
T_1 V_166 ,
void * V_133 , T_1 V_134 , V_92 V_135 )
{
int V_28 ;
T_1 V_140 ;
T_1 V_141 ;
struct V_142 V_143 [ 3 ] ;
V_92 V_144 = 0 ;
bool signal = false ;
V_140 = V_166 + V_134 ;
V_141 = F_45 ( V_140 , sizeof( V_92 ) ) ;
V_139 -> type = V_158 ;
V_139 -> V_27 = V_164 ;
V_139 -> V_159 = V_166 >> 3 ;
V_139 -> V_160 = ( V_148 ) ( V_141 >> 3 ) ;
V_139 -> V_161 = V_135 ;
V_139 -> V_95 = 1 ;
V_143 [ 0 ] . V_150 = V_139 ;
V_143 [ 0 ] . V_151 = V_166 ;
V_143 [ 1 ] . V_150 = V_133 ;
V_143 [ 1 ] . V_151 = V_134 ;
V_143 [ 2 ] . V_150 = & V_144 ;
V_143 [ 2 ] . V_151 = ( V_141 - V_140 ) ;
V_28 = F_46 ( & V_2 -> V_47 , V_143 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_167 * V_168 ,
void * V_133 , T_1 V_134 , V_92 V_135 )
{
int V_28 ;
struct V_169 V_139 ;
T_1 V_156 ;
T_1 V_140 ;
T_1 V_141 ;
struct V_142 V_143 [ 3 ] ;
V_92 V_144 = 0 ;
bool signal = false ;
T_1 V_86 = F_52 ( V_168 -> V_163 ,
V_168 -> V_162 ) ;
if ( V_86 > V_170 )
return - V_36 ;
V_156 = sizeof( struct V_169 ) -
( ( V_170 - V_86 ) *
sizeof( V_92 ) ) ;
V_140 = V_156 + V_134 ;
V_141 = F_45 ( V_140 , sizeof( V_92 ) ) ;
V_139 . type = V_158 ;
V_139 . V_27 = V_164 ;
V_139 . V_159 = V_156 >> 3 ;
V_139 . V_160 = ( V_148 ) ( V_141 >> 3 ) ;
V_139 . V_161 = V_135 ;
V_139 . V_95 = 1 ;
V_139 . V_97 . V_162 = V_168 -> V_162 ;
V_139 . V_97 . V_163 = V_168 -> V_163 ;
memcpy ( V_139 . V_97 . V_100 , V_168 -> V_100 ,
V_86 * sizeof( V_92 ) ) ;
V_143 [ 0 ] . V_150 = & V_139 ;
V_143 [ 0 ] . V_151 = V_156 ;
V_143 [ 1 ] . V_150 = V_133 ;
V_143 [ 1 ] . V_151 = V_134 ;
V_143 [ 2 ] . V_150 = & V_144 ;
V_143 [ 2 ] . V_151 = ( V_141 - V_140 ) ;
V_28 = F_46 ( & V_2 -> V_47 , V_143 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
static inline int
F_53 ( struct V_1 * V_2 , void * V_133 ,
T_1 V_134 , T_1 * V_171 , V_92 * V_135 ,
bool V_172 )
{
int V_28 ;
bool signal = false ;
V_28 = F_54 ( & V_2 -> V_48 , V_133 , V_134 ,
V_171 , V_135 , & signal , V_172 ) ;
if ( signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_55 ( struct V_1 * V_2 , void * V_133 ,
T_1 V_134 , T_1 * V_171 ,
V_92 * V_135 )
{
return F_53 ( V_2 , V_133 , V_134 ,
V_171 , V_135 , false ) ;
}
int F_56 ( struct V_1 * V_2 , void * V_133 ,
T_1 V_134 , T_1 * V_171 ,
V_92 * V_135 )
{
return F_53 ( V_2 , V_133 , V_134 ,
V_171 , V_135 , true ) ;
}
