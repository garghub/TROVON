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
F_6 ( & V_15 -> V_31 , V_27 ) ;
if ( V_15 -> V_32 == V_33 ) {
V_15 -> V_32 = V_34 ;
} else {
F_7 ( & V_15 -> V_31 , V_27 ) ;
return - V_35 ;
}
F_7 ( & V_15 -> V_31 , V_27 ) ;
V_15 -> V_36 = F_5 ;
V_15 -> V_37 = V_20 ;
V_26 = ( void * ) F_8 ( V_38 | V_39 ,
F_9 ( V_16 + V_17 ) ) ;
if ( ! V_26 ) {
V_29 = - V_40 ;
goto V_41;
}
V_25 = ( void * ) ( ( unsigned long ) V_26 + V_16 ) ;
V_15 -> V_42 = V_26 ;
V_15 -> V_43 = ( V_16 +
V_17 ) >> V_44 ;
V_28 = F_10 (
& V_15 -> V_45 , V_26 , V_16 ) ;
if ( V_28 != 0 ) {
V_29 = V_28 ;
goto V_41;
}
V_28 = F_10 (
& V_15 -> V_46 , V_25 , V_17 ) ;
if ( V_28 != 0 ) {
V_29 = V_28 ;
goto V_41;
}
V_15 -> V_47 = 0 ;
V_28 = F_11 ( V_15 ,
V_15 -> V_45 . V_48 ,
V_16 +
V_17 ,
& V_15 -> V_47 ) ;
if ( V_28 != 0 ) {
V_29 = V_28 ;
goto V_41;
}
V_24 = F_12 ( sizeof( * V_24 ) +
sizeof( struct V_21 ) ,
V_38 ) ;
if ( ! V_24 ) {
V_29 = - V_40 ;
goto V_49;
}
F_13 ( & V_24 -> V_50 ) ;
V_22 = (struct V_21 * ) V_24 -> V_51 ;
V_22 -> V_52 . V_53 = V_54 ;
V_22 -> V_55 = V_15 -> V_5 . V_7 ;
V_22 -> V_7 = V_15 -> V_5 . V_7 ;
V_22 -> V_47 = V_15 -> V_47 ;
V_22 -> V_56 = V_16 >>
V_44 ;
V_22 -> V_57 = V_15 -> V_57 ;
if ( V_19 > V_58 ) {
V_29 = - V_35 ;
goto V_49;
}
if ( V_19 )
memcpy ( V_22 -> V_18 , V_18 , V_19 ) ;
F_6 ( & V_8 . V_59 , V_27 ) ;
F_14 ( & V_24 -> V_60 ,
& V_8 . V_61 ) ;
F_7 ( & V_8 . V_59 , V_27 ) ;
V_28 = F_15 ( V_22 ,
sizeof( struct V_21 ) ) ;
if ( V_28 != 0 ) {
V_29 = V_28 ;
goto V_62;
}
V_30 = F_16 ( & V_24 -> V_50 , 5 * V_63 ) ;
if ( V_30 == 0 ) {
V_29 = - V_64 ;
goto V_62;
}
if ( V_24 -> V_65 . V_66 . V_67 )
V_29 = V_24 -> V_65 . V_66 . V_67 ;
F_6 ( & V_8 . V_59 , V_27 ) ;
F_17 ( & V_24 -> V_60 ) ;
F_7 ( & V_8 . V_59 , V_27 ) ;
if ( V_29 == 0 )
V_15 -> V_32 = V_68 ;
F_18 ( V_24 ) ;
return V_29 ;
V_62:
F_6 ( & V_8 . V_59 , V_27 ) ;
F_17 ( & V_24 -> V_60 ) ;
F_7 ( & V_8 . V_59 , V_27 ) ;
V_49:
F_19 ( V_15 , V_15 -> V_47 ) ;
V_41:
F_20 ( ( unsigned long ) V_26 ,
F_9 ( V_16 + V_17 ) ) ;
F_18 ( V_24 ) ;
V_15 -> V_32 = V_33 ;
return V_29 ;
}
static int F_21 ( void * V_69 , T_1 V_70 ,
struct V_23 * * V_71 ,
T_1 * V_72 )
{
int V_73 ;
int V_74 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_23 * V_79 ;
struct V_23 * V_80 = NULL ;
T_1 V_81 ;
int V_82 , V_83 , V_84 , V_85 , V_86 ;
V_74 = V_70 >> V_44 ;
V_86 = V_87 -
sizeof( struct V_75 ) -
sizeof( struct V_88 ) ;
V_83 = V_86 / sizeof( V_89 ) ;
if ( V_74 > V_83 ) {
V_81 = sizeof( struct V_23 ) +
sizeof( struct V_75 ) +
sizeof( struct V_88 ) + V_83 * sizeof( V_89 ) ;
V_79 = F_22 ( V_81 , V_38 ) ;
if ( ! V_79 )
goto V_90;
F_23 ( & V_79 -> V_91 ) ;
V_79 -> V_81 = V_81 ;
V_76 = (struct V_75 * )
V_79 -> V_51 ;
V_76 -> V_92 = 1 ;
V_76 -> V_93 = sizeof( struct V_88 ) +
V_74 * sizeof( V_89 ) ;
V_76 -> V_94 [ 0 ] . V_95 = 0 ;
V_76 -> V_94 [ 0 ] . V_96 = V_70 ;
for ( V_73 = 0 ; V_73 < V_83 ; V_73 ++ )
V_76 -> V_94 [ 0 ] . V_97 [ V_73 ] = F_24 (
V_69 + V_98 * V_73 ) >> V_44 ;
* V_71 = V_79 ;
* V_72 = 1 ;
V_82 = V_83 ;
V_84 = V_74 - V_83 ;
V_86 = V_87 -
sizeof( struct V_77 ) ;
V_83 = V_86 / sizeof( V_89 ) ;
while ( V_84 ) {
if ( V_84 > V_83 )
V_85 = V_83 ;
else
V_85 = V_84 ;
V_81 = sizeof( struct V_23 ) +
sizeof( struct V_77 ) +
V_85 * sizeof( V_89 ) ;
V_80 = F_22 ( V_81 , V_38 ) ;
if ( ! V_80 ) {
struct V_23 * V_99 = NULL ;
struct V_23 * V_100 = NULL ;
F_25 (pos, tmp,
&msgheader->submsglist,
msglistentry) {
F_17 ( & V_99 -> V_60 ) ;
F_18 ( V_99 ) ;
}
goto V_90;
}
V_80 -> V_81 = V_81 ;
( * V_72 ) ++ ;
V_78 =
(struct V_77 * ) V_80 -> V_51 ;
for ( V_73 = 0 ; V_73 < V_85 ; V_73 ++ )
V_78 -> V_101 [ V_73 ] = F_24 (
V_69 + V_98 * ( V_82 + V_73 ) ) >>
V_44 ;
F_14 ( & V_80 -> V_60 ,
& V_79 -> V_91 ) ;
V_82 += V_85 ;
V_84 -= V_85 ;
}
} else {
V_81 = sizeof( struct V_23 ) +
sizeof( struct V_75 ) +
sizeof( struct V_88 ) + V_74 * sizeof( V_89 ) ;
V_79 = F_22 ( V_81 , V_38 ) ;
if ( V_79 == NULL )
goto V_90;
V_79 -> V_81 = V_81 ;
V_76 = (struct V_75 * )
V_79 -> V_51 ;
V_76 -> V_92 = 1 ;
V_76 -> V_93 = sizeof( struct V_88 ) +
V_74 * sizeof( V_89 ) ;
V_76 -> V_94 [ 0 ] . V_95 = 0 ;
V_76 -> V_94 [ 0 ] . V_96 = V_70 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
V_76 -> V_94 [ 0 ] . V_97 [ V_73 ] = F_24 (
V_69 + V_98 * V_73 ) >> V_44 ;
* V_71 = V_79 ;
* V_72 = 1 ;
}
return 0 ;
V_90:
F_18 ( V_79 ) ;
F_18 ( V_80 ) ;
return - V_40 ;
}
int F_11 ( struct V_1 * V_2 , void * V_69 ,
T_1 V_70 , T_1 * V_102 )
{
struct V_75 * V_103 ;
struct V_77 * V_78 ;
struct V_23 * V_71 = NULL ;
struct V_23 * V_104 ;
T_1 V_105 ;
struct V_106 * V_107 ;
T_1 V_108 ;
unsigned long V_27 ;
int V_28 = 0 ;
V_108 =
( F_26 ( & V_8 . V_108 ) - 1 ) ;
V_28 = F_21 ( V_69 , V_70 , & V_71 , & V_105 ) ;
if ( V_28 )
return V_28 ;
F_13 ( & V_71 -> V_50 ) ;
V_103 = (struct V_75 * ) V_71 -> V_51 ;
V_103 -> V_52 . V_53 = V_109 ;
V_103 -> V_7 = V_2 -> V_5 . V_7 ;
V_103 -> V_110 = V_108 ;
F_6 ( & V_8 . V_59 , V_27 ) ;
F_14 ( & V_71 -> V_60 ,
& V_8 . V_61 ) ;
F_7 ( & V_8 . V_59 , V_27 ) ;
V_28 = F_15 ( V_103 , V_71 -> V_81 -
sizeof( * V_71 ) ) ;
if ( V_28 != 0 )
goto V_111;
if ( V_105 > 1 ) {
F_27 (curr, &msginfo->submsglist) {
V_104 = (struct V_23 * ) V_107 ;
V_78 =
(struct V_77 * ) V_104 -> V_51 ;
V_78 -> V_52 . V_53 =
V_112 ;
V_78 -> V_110 = V_108 ;
V_28 = F_15 ( V_78 ,
V_104 -> V_81 -
sizeof( * V_104 ) ) ;
if ( V_28 != 0 )
goto V_111;
}
}
F_28 ( & V_71 -> V_50 ) ;
* V_102 = V_103 -> V_110 ;
V_111:
F_6 ( & V_8 . V_59 , V_27 ) ;
F_17 ( & V_71 -> V_60 ) ;
F_7 ( & V_8 . V_59 , V_27 ) ;
F_18 ( V_71 ) ;
return V_28 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_102 )
{
struct V_113 * V_51 ;
struct V_23 * V_114 ;
unsigned long V_27 ;
int V_28 ;
V_114 = F_12 ( sizeof( * V_114 ) +
sizeof( struct V_113 ) , V_38 ) ;
if ( ! V_114 )
return - V_40 ;
F_13 ( & V_114 -> V_50 ) ;
V_51 = (struct V_113 * ) V_114 -> V_51 ;
V_51 -> V_52 . V_53 = V_115 ;
V_51 -> V_7 = V_2 -> V_5 . V_7 ;
V_51 -> V_110 = V_102 ;
F_6 ( & V_8 . V_59 , V_27 ) ;
F_14 ( & V_114 -> V_60 ,
& V_8 . V_61 ) ;
F_7 ( & V_8 . V_59 , V_27 ) ;
V_28 = F_15 ( V_51 ,
sizeof( struct V_113 ) ) ;
if ( V_28 )
goto V_116;
F_28 ( & V_114 -> V_50 ) ;
V_116:
F_6 ( & V_8 . V_59 , V_27 ) ;
F_17 ( & V_114 -> V_60 ) ;
F_7 ( & V_8 . V_59 , V_27 ) ;
F_18 ( V_114 ) ;
return V_28 ;
}
static void F_29 ( void * V_117 )
{
struct V_1 * V_2 = V_117 ;
V_2 -> V_36 = NULL ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_118 * V_51 ;
int V_28 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_119 = NULL ;
if ( V_2 -> V_120 != F_31 () ) {
F_32 () ;
F_33 ( V_2 -> V_120 , F_29 ,
V_2 , true ) ;
} else {
F_29 ( V_2 ) ;
F_32 () ;
}
V_51 = & V_2 -> V_121 . V_51 ;
V_51 -> V_52 . V_53 = V_122 ;
V_51 -> V_7 = V_2 -> V_5 . V_7 ;
V_28 = F_15 ( V_51 , sizeof( struct V_118 ) ) ;
if ( V_28 ) {
F_34 ( L_1 , V_28 ) ;
return V_28 ;
}
if ( V_2 -> V_47 ) {
V_28 = F_19 ( V_2 ,
V_2 -> V_47 ) ;
if ( V_28 ) {
F_34 ( L_2 , V_28 ) ;
return V_28 ;
}
}
F_35 ( & V_2 -> V_45 ) ;
F_35 ( & V_2 -> V_46 ) ;
F_20 ( ( unsigned long ) V_2 -> V_42 ,
F_9 ( V_2 -> V_43 * V_98 ) ) ;
if ( V_2 -> V_123 )
F_36 ( V_2 ,
V_2 -> V_5 . V_7 ) ;
return V_28 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_106 * V_124 , * V_100 ;
struct V_1 * V_125 ;
if ( V_2 -> V_126 != NULL ) {
return;
}
F_38 (cur, tmp, &channel->sc_list) {
V_125 = F_39 ( V_124 , struct V_1 , V_127 ) ;
if ( V_125 -> V_32 != V_68 )
continue;
F_30 ( V_125 ) ;
}
F_30 ( V_2 ) ;
}
int F_40 ( struct V_1 * V_2 , void * V_128 ,
T_1 V_129 , V_89 V_130 ,
enum V_131 type , T_1 V_27 , bool V_132 )
{
struct V_133 V_134 ;
T_1 V_135 = sizeof( struct V_133 ) + V_129 ;
T_1 V_136 = F_41 ( V_135 , sizeof( V_89 ) ) ;
struct V_137 V_138 [ 3 ] ;
V_89 V_139 = 0 ;
int V_28 ;
bool signal = false ;
V_134 . type = type ;
V_134 . V_27 = V_27 ;
V_134 . V_140 = sizeof( struct V_133 ) >> 3 ;
V_134 . V_141 = ( V_142 ) ( V_136 >> 3 ) ;
V_134 . V_143 = V_130 ;
V_138 [ 0 ] . V_144 = & V_134 ;
V_138 [ 0 ] . V_145 = sizeof( struct V_133 ) ;
V_138 [ 1 ] . V_144 = V_128 ;
V_138 [ 1 ] . V_145 = V_129 ;
V_138 [ 2 ] . V_144 = & V_139 ;
V_138 [ 2 ] . V_145 = ( V_136 - V_135 ) ;
V_28 = F_42 ( & V_2 -> V_45 , V_138 , 3 , & signal ) ;
if ( ( ( V_28 == 0 ) && V_132 && signal ) || ( V_28 ) )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_43 ( struct V_1 * V_2 , void * V_128 ,
T_1 V_129 , V_89 V_130 ,
enum V_131 type , T_1 V_27 )
{
return F_40 ( V_2 , V_128 , V_129 , V_130 ,
type , V_27 , true ) ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_146 V_147 [] ,
T_1 V_74 , void * V_128 , T_1 V_129 ,
V_89 V_130 ,
T_1 V_27 ,
bool V_132 )
{
int V_28 ;
int V_73 ;
struct V_148 V_134 ;
T_1 V_149 ;
T_1 V_135 ;
T_1 V_136 ;
struct V_137 V_138 [ 3 ] ;
V_89 V_139 = 0 ;
bool signal = false ;
if ( V_74 > V_150 )
return - V_35 ;
V_149 = sizeof( struct V_148 ) -
( ( V_150 - V_74 ) *
sizeof( struct V_146 ) ) ;
V_135 = V_149 + V_129 ;
V_136 = F_41 ( V_135 , sizeof( V_89 ) ) ;
V_134 . type = V_151 ;
V_134 . V_27 = V_27 ;
V_134 . V_152 = V_149 >> 3 ;
V_134 . V_153 = ( V_142 ) ( V_136 >> 3 ) ;
V_134 . V_154 = V_130 ;
V_134 . V_92 = V_74 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
V_134 . V_94 [ V_73 ] . V_155 = V_147 [ V_73 ] . V_155 ;
V_134 . V_94 [ V_73 ] . V_156 = V_147 [ V_73 ] . V_156 ;
V_134 . V_94 [ V_73 ] . V_101 = V_147 [ V_73 ] . V_101 ;
}
V_138 [ 0 ] . V_144 = & V_134 ;
V_138 [ 0 ] . V_145 = V_149 ;
V_138 [ 1 ] . V_144 = V_128 ;
V_138 [ 1 ] . V_145 = V_129 ;
V_138 [ 2 ] . V_144 = & V_139 ;
V_138 [ 2 ] . V_145 = ( V_136 - V_135 ) ;
V_28 = F_42 ( & V_2 -> V_45 , V_138 , 3 , & signal ) ;
if ( ( ( V_28 == 0 ) && V_132 && signal ) || ( V_28 ) )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_146 V_147 [] ,
T_1 V_74 , void * V_128 , T_1 V_129 ,
V_89 V_130 )
{
T_1 V_27 = V_157 ;
return F_44 ( V_2 , V_147 , V_74 ,
V_128 , V_129 , V_130 ,
V_27 , true ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_158 * V_134 ,
T_1 V_159 ,
void * V_128 , T_1 V_129 , V_89 V_130 )
{
int V_28 ;
T_1 V_135 ;
T_1 V_136 ;
struct V_137 V_138 [ 3 ] ;
V_89 V_139 = 0 ;
bool signal = false ;
V_135 = V_159 + V_129 ;
V_136 = F_41 ( V_135 , sizeof( V_89 ) ) ;
V_134 -> type = V_151 ;
V_134 -> V_27 = V_157 ;
V_134 -> V_152 = V_159 >> 3 ;
V_134 -> V_153 = ( V_142 ) ( V_136 >> 3 ) ;
V_134 -> V_154 = V_130 ;
V_134 -> V_92 = 1 ;
V_138 [ 0 ] . V_144 = V_134 ;
V_138 [ 0 ] . V_145 = V_159 ;
V_138 [ 1 ] . V_144 = V_128 ;
V_138 [ 1 ] . V_145 = V_129 ;
V_138 [ 2 ] . V_144 = & V_139 ;
V_138 [ 2 ] . V_145 = ( V_136 - V_135 ) ;
V_28 = F_42 ( & V_2 -> V_45 , V_138 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_160 * V_161 ,
void * V_128 , T_1 V_129 , V_89 V_130 )
{
int V_28 ;
struct V_162 V_134 ;
T_1 V_149 ;
T_1 V_135 ;
T_1 V_136 ;
struct V_137 V_138 [ 3 ] ;
V_89 V_139 = 0 ;
bool signal = false ;
T_1 V_83 = F_48 ( V_161 -> V_156 ,
V_161 -> V_155 ) ;
if ( V_83 > V_163 )
return - V_35 ;
V_149 = sizeof( struct V_162 ) -
( ( V_163 - V_83 ) *
sizeof( V_89 ) ) ;
V_135 = V_149 + V_129 ;
V_136 = F_41 ( V_135 , sizeof( V_89 ) ) ;
V_134 . type = V_151 ;
V_134 . V_27 = V_157 ;
V_134 . V_152 = V_149 >> 3 ;
V_134 . V_153 = ( V_142 ) ( V_136 >> 3 ) ;
V_134 . V_154 = V_130 ;
V_134 . V_92 = 1 ;
V_134 . V_94 . V_155 = V_161 -> V_155 ;
V_134 . V_94 . V_156 = V_161 -> V_156 ;
memcpy ( V_134 . V_94 . V_97 , V_161 -> V_97 ,
V_83 * sizeof( V_89 ) ) ;
V_138 [ 0 ] . V_144 = & V_134 ;
V_138 [ 0 ] . V_145 = V_149 ;
V_138 [ 1 ] . V_144 = V_128 ;
V_138 [ 1 ] . V_145 = V_129 ;
V_138 [ 2 ] . V_144 = & V_139 ;
V_138 [ 2 ] . V_145 = ( V_136 - V_135 ) ;
V_28 = F_42 ( & V_2 -> V_45 , V_138 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_49 ( struct V_1 * V_2 , void * V_128 ,
T_1 V_129 , T_1 * V_164 , V_89 * V_130 )
{
struct V_133 V_134 ;
T_1 V_135 ;
T_1 V_165 ;
int V_28 ;
bool signal = false ;
* V_164 = 0 ;
* V_130 = 0 ;
V_28 = F_50 ( & V_2 -> V_46 , & V_134 ,
sizeof( struct V_133 ) ) ;
if ( V_28 != 0 )
return 0 ;
V_135 = V_134 . V_141 << 3 ;
V_165 = V_135 - ( V_134 . V_140 << 3 ) ;
* V_164 = V_165 ;
if ( V_165 > V_129 ) {
F_34 ( L_3 ,
V_129 , V_165 ) ;
return - V_166 ;
}
* V_130 = V_134 . V_143 ;
V_28 = F_51 ( & V_2 -> V_46 , V_128 , V_165 ,
( V_134 . V_140 << 3 ) , & signal ) ;
if ( signal )
F_1 ( V_2 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , void * V_128 ,
T_1 V_129 , T_1 * V_164 ,
V_89 * V_130 )
{
struct V_133 V_134 ;
T_1 V_135 ;
int V_28 ;
bool signal = false ;
* V_164 = 0 ;
* V_130 = 0 ;
V_28 = F_50 ( & V_2 -> V_46 , & V_134 ,
sizeof( struct V_133 ) ) ;
if ( V_28 != 0 )
return 0 ;
V_135 = V_134 . V_141 << 3 ;
* V_164 = V_135 ;
if ( V_135 > V_129 )
return - V_167 ;
* V_130 = V_134 . V_143 ;
V_28 = F_51 ( & V_2 -> V_46 , V_128 , V_135 , 0 ,
& signal ) ;
if ( signal )
F_1 ( V_2 ) ;
return V_28 ;
}
