static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_5 . V_6 ) {
F_2 ( V_2 -> V_5 . V_7 & 31 ,
( unsigned long * ) V_8 . V_9 +
( V_2 -> V_5 . V_7 >> 5 ) ) ;
V_4 = V_8 . V_10 ;
V_4 ++ ;
F_2 ( V_2 -> V_11 ,
( unsigned long * ) & V_4 -> V_12
[ V_2 -> V_13 ] . V_14 ) ;
} else {
F_3 ( V_2 -> V_5 . V_7 ) ;
}
}
void F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 ;
T_1 V_17 = ( T_1 ) V_2 -> V_5 . V_18 / 32 ;
T_1 V_19 = ( T_1 ) V_2 -> V_5 . V_18 % 32 ;
V_16 -> V_20 = V_2 -> V_5 . V_7 ;
V_16 -> V_21 = V_2 -> V_21 ;
memcpy ( & V_16 -> V_22 ,
& V_2 -> V_5 . V_23 . V_24 , sizeof( V_25 ) ) ;
memcpy ( & V_16 -> V_26 ,
& V_2 -> V_5 . V_23 . V_27 ,
sizeof( V_25 ) ) ;
V_4 = (struct V_3 * ) V_8 . V_10 ;
V_16 -> V_18 = V_2 -> V_5 . V_18 ;
V_16 -> V_28 =
V_4 -> V_12 [ V_17 ] . V_14 ;
V_16 -> V_29 =
V_4 -> V_30 [ V_17 ] [ V_19 ] ;
V_16 -> V_31 =
V_4 -> V_32 [ V_17 ]
[ V_19 ] . V_33 . V_34 . V_35 ;
V_4 ++ ;
V_16 -> V_36 =
V_4 -> V_12 [ V_17 ] . V_14 ;
V_16 -> V_37 =
V_4 -> V_30 [ V_17 ] [ V_19 ] ;
V_16 -> V_38 =
V_4 -> V_32 [ V_17 ]
[ V_19 ] . V_33 . V_34 . V_35 ;
F_5 ( & V_2 -> V_39 , & V_16 -> V_39 ) ;
F_5 ( & V_2 -> V_40 , & V_16 -> V_40 ) ;
}
int F_6 ( struct V_1 * V_41 , T_2 V_42 ,
T_2 V_43 , void * V_44 , T_2 V_45 ,
void (* F_7)( void * V_46 ) , void * V_46 )
{
struct V_47 * V_48 ;
struct V_49 * V_50 = NULL ;
void * V_51 , * V_52 ;
unsigned long V_53 ;
int V_54 , V_55 , V_56 = 0 ;
V_41 -> V_57 = F_7 ;
V_41 -> V_58 = V_46 ;
V_52 = ( void * ) F_8 ( V_59 | V_60 ,
F_9 ( V_42 + V_43 ) ) ;
if ( ! V_52 )
return - V_61 ;
V_51 = ( void * ) ( ( unsigned long ) V_52 + V_42 ) ;
V_41 -> V_62 = V_52 ;
V_41 -> V_63 = ( V_42 +
V_43 ) >> V_64 ;
V_54 = F_10 (
& V_41 -> V_40 , V_52 , V_42 ) ;
if ( V_54 != 0 ) {
V_56 = V_54 ;
goto V_65;
}
V_54 = F_10 (
& V_41 -> V_39 , V_51 , V_43 ) ;
if ( V_54 != 0 ) {
V_56 = V_54 ;
goto V_65;
}
V_41 -> V_66 = 0 ;
V_54 = F_11 ( V_41 ,
V_41 -> V_40 . V_67 ,
V_42 +
V_43 ,
& V_41 -> V_66 ) ;
if ( V_54 != 0 ) {
V_56 = V_54 ;
goto V_65;
}
V_50 = F_12 ( sizeof( * V_50 ) +
sizeof( struct V_47 ) ,
V_59 ) ;
if ( ! V_50 ) {
V_56 = - V_61 ;
goto V_65;
}
F_13 ( & V_50 -> V_68 ) ;
V_48 = (struct V_47 * ) V_50 -> V_69 ;
V_48 -> V_70 . V_71 = V_72 ;
V_48 -> V_73 = V_41 -> V_5 . V_7 ;
V_48 -> V_7 = V_41 -> V_5 . V_7 ;
V_48 -> V_66 = V_41 -> V_66 ;
V_48 -> V_74 = V_42 >>
V_64 ;
V_48 -> V_75 = 0 ;
if ( V_45 > V_76 ) {
V_56 = - V_77 ;
goto V_65;
}
if ( V_45 )
memcpy ( V_48 -> V_44 , V_44 , V_45 ) ;
F_14 ( & V_8 . V_78 , V_53 ) ;
F_15 ( & V_50 -> V_79 ,
& V_8 . V_80 ) ;
F_16 ( & V_8 . V_78 , V_53 ) ;
V_54 = F_17 ( V_48 ,
sizeof( struct V_47 ) ) ;
if ( V_54 != 0 )
goto V_81;
V_55 = F_18 ( & V_50 -> V_68 , 5 * V_82 ) ;
if ( V_55 == 0 ) {
V_56 = - V_83 ;
goto V_81;
}
if ( V_50 -> V_84 . V_85 . V_86 )
V_56 = V_50 -> V_84 . V_85 . V_86 ;
F_14 ( & V_8 . V_78 , V_53 ) ;
F_19 ( & V_50 -> V_79 ) ;
F_16 ( & V_8 . V_78 , V_53 ) ;
F_20 ( V_50 ) ;
return V_56 ;
V_81:
F_14 ( & V_8 . V_78 , V_53 ) ;
F_19 ( & V_50 -> V_79 ) ;
F_16 ( & V_8 . V_78 , V_53 ) ;
V_65:
F_21 ( ( unsigned long ) V_52 ,
F_9 ( V_42 + V_43 ) ) ;
F_20 ( V_50 ) ;
return V_56 ;
}
static int F_22 ( void * V_87 , T_2 V_88 ,
struct V_49 * * V_89 ,
T_2 * V_90 )
{
int V_91 ;
int V_92 ;
unsigned long long V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_49 * V_98 ;
struct V_49 * V_99 = NULL ;
T_2 V_100 ;
int V_101 , V_102 , V_103 , V_104 , V_105 ;
V_92 = V_88 >> V_64 ;
V_93 = F_23 ( V_87 ) >> V_64 ;
V_105 = V_106 -
sizeof( struct V_94 ) -
sizeof( struct V_107 ) ;
V_102 = V_105 / sizeof( V_108 ) ;
if ( V_92 > V_102 ) {
V_100 = sizeof( struct V_49 ) +
sizeof( struct V_94 ) +
sizeof( struct V_107 ) + V_102 * sizeof( V_108 ) ;
V_98 = F_24 ( V_100 , V_59 ) ;
if ( ! V_98 )
goto V_109;
F_25 ( & V_98 -> V_110 ) ;
V_98 -> V_100 = V_100 ;
V_95 = (struct V_94 * )
V_98 -> V_69 ;
V_95 -> V_111 = 1 ;
V_95 -> V_112 = sizeof( struct V_107 ) +
V_92 * sizeof( V_108 ) ;
V_95 -> V_113 [ 0 ] . V_114 = 0 ;
V_95 -> V_113 [ 0 ] . V_115 = V_88 ;
for ( V_91 = 0 ; V_91 < V_102 ; V_91 ++ )
V_95 -> V_113 [ 0 ] . V_116 [ V_91 ] = V_93 + V_91 ;
* V_89 = V_98 ;
* V_90 = 1 ;
V_101 = V_102 ;
V_103 = V_92 - V_102 ;
V_105 = V_106 -
sizeof( struct V_96 ) ;
V_102 = V_105 / sizeof( V_108 ) ;
while ( V_103 ) {
if ( V_103 > V_102 )
V_104 = V_102 ;
else
V_104 = V_103 ;
V_100 = sizeof( struct V_49 ) +
sizeof( struct V_96 ) +
V_104 * sizeof( V_108 ) ;
V_99 = F_24 ( V_100 , V_59 ) ;
if ( ! V_99 ) {
struct V_49 * V_117 = NULL ;
struct V_49 * V_118 = NULL ;
F_26 (pos, tmp,
&msgheader->submsglist,
msglistentry) {
F_19 ( & V_117 -> V_79 ) ;
F_20 ( V_117 ) ;
}
goto V_109;
}
V_99 -> V_100 = V_100 ;
( * V_90 ) ++ ;
V_97 =
(struct V_96 * ) V_99 -> V_69 ;
for ( V_91 = 0 ; V_91 < V_104 ; V_91 ++ )
V_97 -> V_93 [ V_91 ] = V_93 + V_101 + V_91 ;
F_15 ( & V_99 -> V_79 ,
& V_98 -> V_110 ) ;
V_101 += V_104 ;
V_103 -= V_104 ;
}
} else {
V_100 = sizeof( struct V_49 ) +
sizeof( struct V_94 ) +
sizeof( struct V_107 ) + V_92 * sizeof( V_108 ) ;
V_98 = F_24 ( V_100 , V_59 ) ;
if ( V_98 == NULL )
goto V_109;
V_98 -> V_100 = V_100 ;
V_95 = (struct V_94 * )
V_98 -> V_69 ;
V_95 -> V_111 = 1 ;
V_95 -> V_112 = sizeof( struct V_107 ) +
V_92 * sizeof( V_108 ) ;
V_95 -> V_113 [ 0 ] . V_114 = 0 ;
V_95 -> V_113 [ 0 ] . V_115 = V_88 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ )
V_95 -> V_113 [ 0 ] . V_116 [ V_91 ] = V_93 + V_91 ;
* V_89 = V_98 ;
* V_90 = 1 ;
}
return 0 ;
V_109:
F_20 ( V_98 ) ;
F_20 ( V_99 ) ;
return - V_61 ;
}
int F_11 ( struct V_1 * V_2 , void * V_87 ,
T_2 V_88 , T_2 * V_119 )
{
struct V_94 * V_120 ;
struct V_96 * V_97 ;
struct V_49 * V_89 = NULL ;
struct V_49 * V_121 ;
T_2 V_122 ;
struct V_123 * V_124 ;
T_2 V_125 ;
unsigned long V_53 ;
int V_54 = 0 ;
int V_55 ;
V_125 = F_27 ( & V_8 . V_125 ) ;
F_28 ( & V_8 . V_125 ) ;
V_54 = F_22 ( V_87 , V_88 , & V_89 , & V_122 ) ;
if ( V_54 )
return V_54 ;
F_13 ( & V_89 -> V_68 ) ;
V_120 = (struct V_94 * ) V_89 -> V_69 ;
V_120 -> V_70 . V_71 = V_126 ;
V_120 -> V_7 = V_2 -> V_5 . V_7 ;
V_120 -> V_127 = V_125 ;
F_14 ( & V_8 . V_78 , V_53 ) ;
F_15 ( & V_89 -> V_79 ,
& V_8 . V_80 ) ;
F_16 ( & V_8 . V_78 , V_53 ) ;
V_54 = F_17 ( V_120 , V_89 -> V_100 -
sizeof( * V_89 ) ) ;
if ( V_54 != 0 )
goto V_128;
if ( V_122 > 1 ) {
F_29 (curr, &msginfo->submsglist) {
V_121 = (struct V_49 * ) V_124 ;
V_97 =
(struct V_96 * ) V_121 -> V_69 ;
V_97 -> V_70 . V_71 =
V_129 ;
V_97 -> V_127 = V_125 ;
V_54 = F_17 ( V_97 ,
V_121 -> V_100 -
sizeof( * V_121 ) ) ;
if ( V_54 != 0 )
goto V_128;
}
}
V_55 = F_18 ( & V_89 -> V_68 , 5 * V_82 ) ;
F_30 ( V_55 == 0 ) ;
* V_119 = V_120 -> V_127 ;
V_128:
F_14 ( & V_8 . V_78 , V_53 ) ;
F_19 ( & V_89 -> V_79 ) ;
F_16 ( & V_8 . V_78 , V_53 ) ;
F_20 ( V_89 ) ;
return V_54 ;
}
int F_31 ( struct V_1 * V_2 , T_2 V_119 )
{
struct V_130 * V_69 ;
struct V_49 * V_131 ;
unsigned long V_53 ;
int V_54 , V_55 ;
V_131 = F_12 ( sizeof( * V_131 ) +
sizeof( struct V_130 ) , V_59 ) ;
if ( ! V_131 )
return - V_61 ;
F_13 ( & V_131 -> V_68 ) ;
V_69 = (struct V_130 * ) V_131 -> V_69 ;
V_69 -> V_70 . V_71 = V_132 ;
V_69 -> V_7 = V_2 -> V_5 . V_7 ;
V_69 -> V_127 = V_119 ;
F_14 ( & V_8 . V_78 , V_53 ) ;
F_15 ( & V_131 -> V_79 ,
& V_8 . V_80 ) ;
F_16 ( & V_8 . V_78 , V_53 ) ;
V_54 = F_17 ( V_69 ,
sizeof( struct V_130 ) ) ;
F_30 ( V_54 != 0 ) ;
V_55 = F_18 ( & V_131 -> V_68 , 5 * V_82 ) ;
F_30 ( V_55 == 0 ) ;
F_14 ( & V_8 . V_78 , V_53 ) ;
F_19 ( & V_131 -> V_79 ) ;
F_16 ( & V_8 . V_78 , V_53 ) ;
F_20 ( V_131 ) ;
return V_54 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_133 * V_69 ;
int V_54 ;
unsigned long V_53 ;
F_14 ( & V_2 -> V_134 , V_53 ) ;
V_2 -> V_57 = NULL ;
F_16 ( & V_2 -> V_134 , V_53 ) ;
V_69 = & V_2 -> V_135 . V_69 ;
V_69 -> V_70 . V_71 = V_136 ;
V_69 -> V_7 = V_2 -> V_5 . V_7 ;
V_54 = F_17 ( V_69 , sizeof( struct V_133 ) ) ;
F_30 ( V_54 != 0 ) ;
if ( V_2 -> V_66 )
F_31 ( V_2 ,
V_2 -> V_66 ) ;
F_33 ( & V_2 -> V_40 ) ;
F_33 ( & V_2 -> V_39 ) ;
F_21 ( ( unsigned long ) V_2 -> V_62 ,
F_9 ( V_2 -> V_63 * V_137 ) ) ;
}
int F_34 ( struct V_1 * V_2 , const void * V_138 ,
T_2 V_139 , V_108 V_140 ,
enum V_141 type , T_2 V_53 )
{
struct V_142 V_143 ;
T_2 V_144 = sizeof( struct V_142 ) + V_139 ;
T_2 V_145 = F_35 ( V_144 , sizeof( V_108 ) ) ;
struct V_146 V_147 [ 3 ] ;
V_108 V_148 = 0 ;
int V_54 ;
V_143 . type = type ;
V_143 . V_53 = V_53 ;
V_143 . V_149 = sizeof( struct V_142 ) >> 3 ;
V_143 . V_150 = ( V_151 ) ( V_145 >> 3 ) ;
V_143 . V_152 = V_140 ;
F_36 ( V_147 , 3 ) ;
F_37 ( & V_147 [ 0 ] , & V_143 , sizeof( struct V_142 ) ) ;
F_37 ( & V_147 [ 1 ] , V_138 , V_139 ) ;
F_37 ( & V_147 [ 2 ] , & V_148 ,
V_145 - V_144 ) ;
V_54 = F_38 ( & V_2 -> V_40 , V_147 , 3 ) ;
if ( V_54 == 0 && ! F_39 ( & V_2 -> V_40 ) )
F_1 ( V_2 ) ;
return V_54 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_153 V_154 [] ,
T_2 V_92 , void * V_138 , T_2 V_139 ,
V_108 V_140 )
{
int V_54 ;
int V_91 ;
struct V_155 V_143 ;
T_2 V_156 ;
T_2 V_144 ;
T_2 V_145 ;
struct V_146 V_147 [ 3 ] ;
V_108 V_148 = 0 ;
if ( V_92 > V_157 )
return - V_77 ;
V_156 = sizeof( struct V_155 ) -
( ( V_157 - V_92 ) *
sizeof( struct V_153 ) ) ;
V_144 = V_156 + V_139 ;
V_145 = F_35 ( V_144 , sizeof( V_108 ) ) ;
V_143 . type = V_158 ;
V_143 . V_53 = V_159 ;
V_143 . V_160 = V_156 >> 3 ;
V_143 . V_161 = ( V_151 ) ( V_145 >> 3 ) ;
V_143 . V_162 = V_140 ;
V_143 . V_111 = V_92 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
V_143 . V_113 [ V_91 ] . V_163 = V_154 [ V_91 ] . V_163 ;
V_143 . V_113 [ V_91 ] . V_164 = V_154 [ V_91 ] . V_164 ;
V_143 . V_113 [ V_91 ] . V_93 = V_154 [ V_91 ] . V_93 ;
}
F_36 ( V_147 , 3 ) ;
F_37 ( & V_147 [ 0 ] , & V_143 , V_156 ) ;
F_37 ( & V_147 [ 1 ] , V_138 , V_139 ) ;
F_37 ( & V_147 [ 2 ] , & V_148 ,
V_145 - V_144 ) ;
V_54 = F_38 ( & V_2 -> V_40 , V_147 , 3 ) ;
if ( V_54 == 0 && ! F_39 ( & V_2 -> V_40 ) )
F_1 ( V_2 ) ;
return V_54 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_165 * V_166 ,
void * V_138 , T_2 V_139 , V_108 V_140 )
{
int V_54 ;
struct V_167 V_143 ;
T_2 V_156 ;
T_2 V_144 ;
T_2 V_145 ;
struct V_146 V_147 [ 3 ] ;
V_108 V_148 = 0 ;
T_2 V_102 = F_42 ( V_166 -> V_164 ,
V_166 -> V_163 ) ;
if ( ( V_102 < 0 ) || ( V_102 > V_168 ) )
return - V_77 ;
V_156 = sizeof( struct V_167 ) -
( ( V_168 - V_102 ) *
sizeof( V_108 ) ) ;
V_144 = V_156 + V_139 ;
V_145 = F_35 ( V_144 , sizeof( V_108 ) ) ;
V_143 . type = V_158 ;
V_143 . V_53 = V_159 ;
V_143 . V_160 = V_156 >> 3 ;
V_143 . V_161 = ( V_151 ) ( V_145 >> 3 ) ;
V_143 . V_162 = V_140 ;
V_143 . V_111 = 1 ;
V_143 . V_113 . V_163 = V_166 -> V_163 ;
V_143 . V_113 . V_164 = V_166 -> V_164 ;
memcpy ( V_143 . V_113 . V_116 , V_166 -> V_116 ,
V_102 * sizeof( V_108 ) ) ;
F_36 ( V_147 , 3 ) ;
F_37 ( & V_147 [ 0 ] , & V_143 , V_156 ) ;
F_37 ( & V_147 [ 1 ] , V_138 , V_139 ) ;
F_37 ( & V_147 [ 2 ] , & V_148 ,
V_145 - V_144 ) ;
V_54 = F_38 ( & V_2 -> V_40 , V_147 , 3 ) ;
if ( V_54 == 0 && ! F_39 ( & V_2 -> V_40 ) )
F_1 ( V_2 ) ;
return V_54 ;
}
int F_43 ( struct V_1 * V_2 , void * V_138 ,
T_2 V_139 , T_2 * V_169 , V_108 * V_140 )
{
struct V_142 V_143 ;
T_2 V_144 ;
T_2 V_170 ;
int V_54 ;
* V_169 = 0 ;
* V_140 = 0 ;
V_54 = F_44 ( & V_2 -> V_39 , & V_143 ,
sizeof( struct V_142 ) ) ;
if ( V_54 != 0 )
return 0 ;
V_144 = V_143 . V_150 << 3 ;
V_170 = V_144 - ( V_143 . V_149 << 3 ) ;
* V_169 = V_170 ;
if ( V_170 > V_139 ) {
F_45 ( L_1 ,
V_139 , V_170 ) ;
return - V_171 ;
}
* V_140 = V_143 . V_152 ;
V_54 = F_46 ( & V_2 -> V_39 , V_138 , V_170 ,
( V_143 . V_149 << 3 ) ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , void * V_138 ,
T_2 V_139 , T_2 * V_169 ,
V_108 * V_140 )
{
struct V_142 V_143 ;
T_2 V_144 ;
T_2 V_170 ;
int V_54 ;
* V_169 = 0 ;
* V_140 = 0 ;
V_54 = F_44 ( & V_2 -> V_39 , & V_143 ,
sizeof( struct V_142 ) ) ;
if ( V_54 != 0 )
return 0 ;
V_144 = V_143 . V_150 << 3 ;
V_170 = V_144 - ( V_143 . V_149 << 3 ) ;
* V_169 = V_144 ;
if ( V_144 > V_139 ) {
F_45 ( L_2
L_3 ,
V_144 , V_139 ) ;
return - V_172 ;
}
* V_140 = V_143 . V_152 ;
V_54 = F_46 ( & V_2 -> V_39 , V_138 , V_144 , 0 ) ;
return 0 ;
}
