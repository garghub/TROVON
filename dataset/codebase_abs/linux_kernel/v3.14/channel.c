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
int V_28 , V_29 , V_30 = 0 ;
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
if ( ! V_26 )
return - V_40 ;
V_25 = ( void * ) ( ( unsigned long ) V_26 + V_16 ) ;
V_15 -> V_41 = V_26 ;
V_15 -> V_42 = ( V_16 +
V_17 ) >> V_43 ;
V_28 = F_10 (
& V_15 -> V_44 , V_26 , V_16 ) ;
if ( V_28 != 0 ) {
V_30 = V_28 ;
goto V_45;
}
V_28 = F_10 (
& V_15 -> V_46 , V_25 , V_17 ) ;
if ( V_28 != 0 ) {
V_30 = V_28 ;
goto V_45;
}
V_15 -> V_47 = 0 ;
V_28 = F_11 ( V_15 ,
V_15 -> V_44 . V_48 ,
V_16 +
V_17 ,
& V_15 -> V_47 ) ;
if ( V_28 != 0 ) {
V_30 = V_28 ;
goto V_45;
}
V_24 = F_12 ( sizeof( * V_24 ) +
sizeof( struct V_21 ) ,
V_38 ) ;
if ( ! V_24 ) {
V_30 = - V_40 ;
goto V_45;
}
F_13 ( & V_24 -> V_49 ) ;
V_22 = (struct V_21 * ) V_24 -> V_50 ;
V_22 -> V_51 . V_52 = V_53 ;
V_22 -> V_54 = V_15 -> V_5 . V_7 ;
V_22 -> V_7 = V_15 -> V_5 . V_7 ;
V_22 -> V_47 = V_15 -> V_47 ;
V_22 -> V_55 = V_16 >>
V_43 ;
V_22 -> V_56 = V_15 -> V_56 ;
if ( V_19 > V_57 ) {
V_30 = - V_35 ;
goto V_45;
}
if ( V_19 )
memcpy ( V_22 -> V_18 , V_18 , V_19 ) ;
F_6 ( & V_8 . V_58 , V_27 ) ;
F_14 ( & V_24 -> V_59 ,
& V_8 . V_60 ) ;
F_7 ( & V_8 . V_58 , V_27 ) ;
V_28 = F_15 ( V_22 ,
sizeof( struct V_21 ) ) ;
if ( V_28 != 0 )
goto V_61;
V_29 = F_16 ( & V_24 -> V_49 , 5 * V_62 ) ;
if ( V_29 == 0 ) {
V_30 = - V_63 ;
goto V_61;
}
if ( V_24 -> V_64 . V_65 . V_66 )
V_30 = V_24 -> V_64 . V_65 . V_66 ;
F_6 ( & V_8 . V_58 , V_27 ) ;
F_17 ( & V_24 -> V_59 ) ;
F_7 ( & V_8 . V_58 , V_27 ) ;
if ( V_30 == 0 )
V_15 -> V_32 = V_67 ;
F_18 ( V_24 ) ;
return V_30 ;
V_61:
F_6 ( & V_8 . V_58 , V_27 ) ;
F_17 ( & V_24 -> V_59 ) ;
F_7 ( & V_8 . V_58 , V_27 ) ;
V_45:
F_19 ( ( unsigned long ) V_26 ,
F_9 ( V_16 + V_17 ) ) ;
F_18 ( V_24 ) ;
return V_30 ;
}
static int F_20 ( void * V_68 , T_1 V_69 ,
struct V_23 * * V_70 ,
T_1 * V_71 )
{
int V_72 ;
int V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_23 * V_78 ;
struct V_23 * V_79 = NULL ;
T_1 V_80 ;
int V_81 , V_82 , V_83 , V_84 , V_85 ;
V_73 = V_69 >> V_43 ;
V_85 = V_86 -
sizeof( struct V_74 ) -
sizeof( struct V_87 ) ;
V_82 = V_85 / sizeof( V_88 ) ;
if ( V_73 > V_82 ) {
V_80 = sizeof( struct V_23 ) +
sizeof( struct V_74 ) +
sizeof( struct V_87 ) + V_82 * sizeof( V_88 ) ;
V_78 = F_21 ( V_80 , V_38 ) ;
if ( ! V_78 )
goto V_89;
F_22 ( & V_78 -> V_90 ) ;
V_78 -> V_80 = V_80 ;
V_75 = (struct V_74 * )
V_78 -> V_50 ;
V_75 -> V_91 = 1 ;
V_75 -> V_92 = sizeof( struct V_87 ) +
V_73 * sizeof( V_88 ) ;
V_75 -> V_93 [ 0 ] . V_94 = 0 ;
V_75 -> V_93 [ 0 ] . V_95 = V_69 ;
for ( V_72 = 0 ; V_72 < V_82 ; V_72 ++ )
V_75 -> V_93 [ 0 ] . V_96 [ V_72 ] = F_23 (
V_68 + V_97 * V_72 ) >> V_43 ;
* V_70 = V_78 ;
* V_71 = 1 ;
V_81 = V_82 ;
V_83 = V_73 - V_82 ;
V_85 = V_86 -
sizeof( struct V_76 ) ;
V_82 = V_85 / sizeof( V_88 ) ;
while ( V_83 ) {
if ( V_83 > V_82 )
V_84 = V_82 ;
else
V_84 = V_83 ;
V_80 = sizeof( struct V_23 ) +
sizeof( struct V_76 ) +
V_84 * sizeof( V_88 ) ;
V_79 = F_21 ( V_80 , V_38 ) ;
if ( ! V_79 ) {
struct V_23 * V_98 = NULL ;
struct V_23 * V_99 = NULL ;
F_24 (pos, tmp,
&msgheader->submsglist,
msglistentry) {
F_17 ( & V_98 -> V_59 ) ;
F_18 ( V_98 ) ;
}
goto V_89;
}
V_79 -> V_80 = V_80 ;
( * V_71 ) ++ ;
V_77 =
(struct V_76 * ) V_79 -> V_50 ;
for ( V_72 = 0 ; V_72 < V_84 ; V_72 ++ )
V_77 -> V_100 [ V_72 ] = F_23 (
V_68 + V_97 * ( V_81 + V_72 ) ) >>
V_43 ;
F_14 ( & V_79 -> V_59 ,
& V_78 -> V_90 ) ;
V_81 += V_84 ;
V_83 -= V_84 ;
}
} else {
V_80 = sizeof( struct V_23 ) +
sizeof( struct V_74 ) +
sizeof( struct V_87 ) + V_73 * sizeof( V_88 ) ;
V_78 = F_21 ( V_80 , V_38 ) ;
if ( V_78 == NULL )
goto V_89;
V_78 -> V_80 = V_80 ;
V_75 = (struct V_74 * )
V_78 -> V_50 ;
V_75 -> V_91 = 1 ;
V_75 -> V_92 = sizeof( struct V_87 ) +
V_73 * sizeof( V_88 ) ;
V_75 -> V_93 [ 0 ] . V_94 = 0 ;
V_75 -> V_93 [ 0 ] . V_95 = V_69 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ )
V_75 -> V_93 [ 0 ] . V_96 [ V_72 ] = F_23 (
V_68 + V_97 * V_72 ) >> V_43 ;
* V_70 = V_78 ;
* V_71 = 1 ;
}
return 0 ;
V_89:
F_18 ( V_78 ) ;
F_18 ( V_79 ) ;
return - V_40 ;
}
int F_11 ( struct V_1 * V_2 , void * V_68 ,
T_1 V_69 , T_1 * V_101 )
{
struct V_74 * V_102 ;
struct V_76 * V_77 ;
struct V_23 * V_70 = NULL ;
struct V_23 * V_103 ;
T_1 V_104 ;
struct V_105 * V_106 ;
T_1 V_107 ;
unsigned long V_27 ;
int V_28 = 0 ;
int V_29 ;
V_107 = F_25 ( & V_8 . V_107 ) ;
F_26 ( & V_8 . V_107 ) ;
V_28 = F_20 ( V_68 , V_69 , & V_70 , & V_104 ) ;
if ( V_28 )
return V_28 ;
F_13 ( & V_70 -> V_49 ) ;
V_102 = (struct V_74 * ) V_70 -> V_50 ;
V_102 -> V_51 . V_52 = V_108 ;
V_102 -> V_7 = V_2 -> V_5 . V_7 ;
V_102 -> V_109 = V_107 ;
F_6 ( & V_8 . V_58 , V_27 ) ;
F_14 ( & V_70 -> V_59 ,
& V_8 . V_60 ) ;
F_7 ( & V_8 . V_58 , V_27 ) ;
V_28 = F_15 ( V_102 , V_70 -> V_80 -
sizeof( * V_70 ) ) ;
if ( V_28 != 0 )
goto V_110;
if ( V_104 > 1 ) {
F_27 (curr, &msginfo->submsglist) {
V_103 = (struct V_23 * ) V_106 ;
V_77 =
(struct V_76 * ) V_103 -> V_50 ;
V_77 -> V_51 . V_52 =
V_111 ;
V_77 -> V_109 = V_107 ;
V_28 = F_15 ( V_77 ,
V_103 -> V_80 -
sizeof( * V_103 ) ) ;
if ( V_28 != 0 )
goto V_110;
}
}
V_29 = F_16 ( & V_70 -> V_49 , 5 * V_62 ) ;
F_28 ( V_29 == 0 ) ;
* V_101 = V_102 -> V_109 ;
V_110:
F_6 ( & V_8 . V_58 , V_27 ) ;
F_17 ( & V_70 -> V_59 ) ;
F_7 ( & V_8 . V_58 , V_27 ) ;
F_18 ( V_70 ) ;
return V_28 ;
}
int F_29 ( struct V_1 * V_2 , T_1 V_101 )
{
struct V_112 * V_50 ;
struct V_23 * V_113 ;
unsigned long V_27 ;
int V_28 , V_29 ;
V_113 = F_12 ( sizeof( * V_113 ) +
sizeof( struct V_112 ) , V_38 ) ;
if ( ! V_113 )
return - V_40 ;
F_13 ( & V_113 -> V_49 ) ;
V_50 = (struct V_112 * ) V_113 -> V_50 ;
V_50 -> V_51 . V_52 = V_114 ;
V_50 -> V_7 = V_2 -> V_5 . V_7 ;
V_50 -> V_109 = V_101 ;
F_6 ( & V_8 . V_58 , V_27 ) ;
F_14 ( & V_113 -> V_59 ,
& V_8 . V_60 ) ;
F_7 ( & V_8 . V_58 , V_27 ) ;
V_28 = F_15 ( V_50 ,
sizeof( struct V_112 ) ) ;
F_28 ( V_28 != 0 ) ;
V_29 = F_16 ( & V_113 -> V_49 , 5 * V_62 ) ;
F_28 ( V_29 == 0 ) ;
F_6 ( & V_8 . V_58 , V_27 ) ;
F_17 ( & V_113 -> V_59 ) ;
F_7 ( & V_8 . V_58 , V_27 ) ;
F_18 ( V_113 ) ;
return V_28 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_115 * V_50 ;
int V_28 ;
unsigned long V_27 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_116 = NULL ;
F_6 ( & V_2 -> V_117 , V_27 ) ;
V_2 -> V_36 = NULL ;
F_7 ( & V_2 -> V_117 , V_27 ) ;
V_50 = & V_2 -> V_118 . V_50 ;
V_50 -> V_51 . V_52 = V_119 ;
V_50 -> V_7 = V_2 -> V_5 . V_7 ;
V_28 = F_15 ( V_50 , sizeof( struct V_115 ) ) ;
F_28 ( V_28 != 0 ) ;
if ( V_2 -> V_47 )
F_29 ( V_2 ,
V_2 -> V_47 ) ;
F_31 ( & V_2 -> V_44 ) ;
F_31 ( & V_2 -> V_46 ) ;
F_19 ( ( unsigned long ) V_2 -> V_41 ,
F_9 ( V_2 -> V_42 * V_97 ) ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_105 * V_120 , * V_99 ;
struct V_1 * V_121 ;
if ( V_2 -> V_122 != NULL ) {
return;
}
F_33 (cur, tmp, &channel->sc_list) {
V_121 = F_34 ( V_120 , struct V_1 , V_123 ) ;
if ( V_121 -> V_32 != V_67 )
continue;
F_30 ( V_121 ) ;
}
F_30 ( V_2 ) ;
}
int F_35 ( struct V_1 * V_2 , const void * V_124 ,
T_1 V_125 , V_88 V_126 ,
enum V_127 type , T_1 V_27 )
{
struct V_128 V_129 ;
T_1 V_130 = sizeof( struct V_128 ) + V_125 ;
T_1 V_131 = F_36 ( V_130 , sizeof( V_88 ) ) ;
struct V_132 V_133 [ 3 ] ;
V_88 V_134 = 0 ;
int V_28 ;
bool signal = false ;
V_129 . type = type ;
V_129 . V_27 = V_27 ;
V_129 . V_135 = sizeof( struct V_128 ) >> 3 ;
V_129 . V_136 = ( V_137 ) ( V_131 >> 3 ) ;
V_129 . V_138 = V_126 ;
F_37 ( V_133 , 3 ) ;
F_38 ( & V_133 [ 0 ] , & V_129 , sizeof( struct V_128 ) ) ;
F_38 ( & V_133 [ 1 ] , V_124 , V_125 ) ;
F_38 ( & V_133 [ 2 ] , & V_134 ,
V_131 - V_130 ) ;
V_28 = F_39 ( & V_2 -> V_44 , V_133 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_139 V_140 [] ,
T_1 V_73 , void * V_124 , T_1 V_125 ,
V_88 V_126 )
{
int V_28 ;
int V_72 ;
struct V_141 V_129 ;
T_1 V_142 ;
T_1 V_130 ;
T_1 V_131 ;
struct V_132 V_133 [ 3 ] ;
V_88 V_134 = 0 ;
bool signal = false ;
if ( V_73 > V_143 )
return - V_35 ;
V_142 = sizeof( struct V_141 ) -
( ( V_143 - V_73 ) *
sizeof( struct V_139 ) ) ;
V_130 = V_142 + V_125 ;
V_131 = F_36 ( V_130 , sizeof( V_88 ) ) ;
V_129 . type = V_144 ;
V_129 . V_27 = V_145 ;
V_129 . V_146 = V_142 >> 3 ;
V_129 . V_147 = ( V_137 ) ( V_131 >> 3 ) ;
V_129 . V_148 = V_126 ;
V_129 . V_91 = V_73 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
V_129 . V_93 [ V_72 ] . V_149 = V_140 [ V_72 ] . V_149 ;
V_129 . V_93 [ V_72 ] . V_150 = V_140 [ V_72 ] . V_150 ;
V_129 . V_93 [ V_72 ] . V_100 = V_140 [ V_72 ] . V_100 ;
}
F_37 ( V_133 , 3 ) ;
F_38 ( & V_133 [ 0 ] , & V_129 , V_142 ) ;
F_38 ( & V_133 [ 1 ] , V_124 , V_125 ) ;
F_38 ( & V_133 [ 2 ] , & V_134 ,
V_131 - V_130 ) ;
V_28 = F_39 ( & V_2 -> V_44 , V_133 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_151 * V_152 ,
void * V_124 , T_1 V_125 , V_88 V_126 )
{
int V_28 ;
struct V_153 V_129 ;
T_1 V_142 ;
T_1 V_130 ;
T_1 V_131 ;
struct V_132 V_133 [ 3 ] ;
V_88 V_134 = 0 ;
bool signal = false ;
T_1 V_82 = F_42 ( V_152 -> V_150 ,
V_152 -> V_149 ) ;
if ( ( V_82 < 0 ) || ( V_82 > V_154 ) )
return - V_35 ;
V_142 = sizeof( struct V_153 ) -
( ( V_154 - V_82 ) *
sizeof( V_88 ) ) ;
V_130 = V_142 + V_125 ;
V_131 = F_36 ( V_130 , sizeof( V_88 ) ) ;
V_129 . type = V_144 ;
V_129 . V_27 = V_145 ;
V_129 . V_146 = V_142 >> 3 ;
V_129 . V_147 = ( V_137 ) ( V_131 >> 3 ) ;
V_129 . V_148 = V_126 ;
V_129 . V_91 = 1 ;
V_129 . V_93 . V_149 = V_152 -> V_149 ;
V_129 . V_93 . V_150 = V_152 -> V_150 ;
memcpy ( V_129 . V_93 . V_96 , V_152 -> V_96 ,
V_82 * sizeof( V_88 ) ) ;
F_37 ( V_133 , 3 ) ;
F_38 ( & V_133 [ 0 ] , & V_129 , V_142 ) ;
F_38 ( & V_133 [ 1 ] , V_124 , V_125 ) ;
F_38 ( & V_133 [ 2 ] , & V_134 ,
V_131 - V_130 ) ;
V_28 = F_39 ( & V_2 -> V_44 , V_133 , 3 , & signal ) ;
if ( V_28 == 0 && signal )
F_1 ( V_2 ) ;
return V_28 ;
}
int F_43 ( struct V_1 * V_2 , void * V_124 ,
T_1 V_125 , T_1 * V_155 , V_88 * V_126 )
{
struct V_128 V_129 ;
T_1 V_130 ;
T_1 V_156 ;
int V_28 ;
bool signal = false ;
* V_155 = 0 ;
* V_126 = 0 ;
V_28 = F_44 ( & V_2 -> V_46 , & V_129 ,
sizeof( struct V_128 ) ) ;
if ( V_28 != 0 )
return 0 ;
V_130 = V_129 . V_136 << 3 ;
V_156 = V_130 - ( V_129 . V_135 << 3 ) ;
* V_155 = V_156 ;
if ( V_156 > V_125 ) {
F_45 ( L_1 ,
V_125 , V_156 ) ;
return - V_157 ;
}
* V_126 = V_129 . V_138 ;
V_28 = F_46 ( & V_2 -> V_46 , V_124 , V_156 ,
( V_129 . V_135 << 3 ) , & signal ) ;
if ( signal )
F_1 ( V_2 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , void * V_124 ,
T_1 V_125 , T_1 * V_155 ,
V_88 * V_126 )
{
struct V_128 V_129 ;
T_1 V_130 ;
int V_28 ;
bool signal = false ;
* V_155 = 0 ;
* V_126 = 0 ;
V_28 = F_44 ( & V_2 -> V_46 , & V_129 ,
sizeof( struct V_128 ) ) ;
if ( V_28 != 0 )
return 0 ;
V_130 = V_129 . V_136 << 3 ;
* V_155 = V_130 ;
if ( V_130 > V_125 ) {
F_45 ( L_2
L_3 ,
V_130 , V_125 ) ;
return - V_158 ;
}
* V_126 = V_129 . V_138 ;
V_28 = F_46 ( & V_2 -> V_46 , V_124 , V_130 , 0 ,
& signal ) ;
if ( signal )
F_1 ( V_2 ) ;
return V_28 ;
}
