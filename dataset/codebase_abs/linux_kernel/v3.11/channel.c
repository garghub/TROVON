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
F_3 ( V_2 ) ;
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
F_8 ( & V_41 -> V_57 , V_53 ) ;
if ( V_41 -> V_21 == V_58 ) {
V_41 -> V_21 = V_59 ;
} else {
F_9 ( & V_41 -> V_57 , V_53 ) ;
return - V_60 ;
}
F_9 ( & V_41 -> V_57 , V_53 ) ;
V_41 -> V_61 = F_7 ;
V_41 -> V_62 = V_46 ;
V_52 = ( void * ) F_10 ( V_63 | V_64 ,
F_11 ( V_42 + V_43 ) ) ;
if ( ! V_52 )
return - V_65 ;
V_51 = ( void * ) ( ( unsigned long ) V_52 + V_42 ) ;
V_41 -> V_66 = V_52 ;
V_41 -> V_67 = ( V_42 +
V_43 ) >> V_68 ;
V_54 = F_12 (
& V_41 -> V_40 , V_52 , V_42 ) ;
if ( V_54 != 0 ) {
V_56 = V_54 ;
goto V_69;
}
V_54 = F_12 (
& V_41 -> V_39 , V_51 , V_43 ) ;
if ( V_54 != 0 ) {
V_56 = V_54 ;
goto V_69;
}
V_41 -> V_70 = 0 ;
V_54 = F_13 ( V_41 ,
V_41 -> V_40 . V_71 ,
V_42 +
V_43 ,
& V_41 -> V_70 ) ;
if ( V_54 != 0 ) {
V_56 = V_54 ;
goto V_69;
}
V_50 = F_14 ( sizeof( * V_50 ) +
sizeof( struct V_47 ) ,
V_63 ) ;
if ( ! V_50 ) {
V_56 = - V_65 ;
goto V_69;
}
F_15 ( & V_50 -> V_72 ) ;
V_48 = (struct V_47 * ) V_50 -> V_73 ;
V_48 -> V_74 . V_75 = V_76 ;
V_48 -> V_77 = V_41 -> V_5 . V_7 ;
V_48 -> V_7 = V_41 -> V_5 . V_7 ;
V_48 -> V_70 = V_41 -> V_70 ;
V_48 -> V_78 = V_42 >>
V_68 ;
V_48 -> V_79 = V_41 -> V_79 ;
if ( V_45 > V_80 ) {
V_56 = - V_60 ;
goto V_69;
}
if ( V_45 )
memcpy ( V_48 -> V_44 , V_44 , V_45 ) ;
F_8 ( & V_8 . V_81 , V_53 ) ;
F_16 ( & V_50 -> V_82 ,
& V_8 . V_83 ) ;
F_9 ( & V_8 . V_81 , V_53 ) ;
V_54 = F_17 ( V_48 ,
sizeof( struct V_47 ) ) ;
if ( V_54 != 0 )
goto V_84;
V_55 = F_18 ( & V_50 -> V_72 , 5 * V_85 ) ;
if ( V_55 == 0 ) {
V_56 = - V_86 ;
goto V_84;
}
if ( V_50 -> V_87 . V_88 . V_89 )
V_56 = V_50 -> V_87 . V_88 . V_89 ;
F_8 ( & V_8 . V_81 , V_53 ) ;
F_19 ( & V_50 -> V_82 ) ;
F_9 ( & V_8 . V_81 , V_53 ) ;
if ( V_56 == 0 )
V_41 -> V_21 = V_90 ;
F_20 ( V_50 ) ;
return V_56 ;
V_84:
F_8 ( & V_8 . V_81 , V_53 ) ;
F_19 ( & V_50 -> V_82 ) ;
F_9 ( & V_8 . V_81 , V_53 ) ;
V_69:
F_21 ( ( unsigned long ) V_52 ,
F_11 ( V_42 + V_43 ) ) ;
F_20 ( V_50 ) ;
return V_56 ;
}
static int F_22 ( void * V_91 , T_2 V_92 ,
struct V_49 * * V_93 ,
T_2 * V_94 )
{
int V_95 ;
int V_96 ;
unsigned long long V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_49 * V_102 ;
struct V_49 * V_103 = NULL ;
T_2 V_104 ;
int V_105 , V_106 , V_107 , V_108 , V_109 ;
V_96 = V_92 >> V_68 ;
V_97 = F_23 ( V_91 ) >> V_68 ;
V_109 = V_110 -
sizeof( struct V_98 ) -
sizeof( struct V_111 ) ;
V_106 = V_109 / sizeof( V_112 ) ;
if ( V_96 > V_106 ) {
V_104 = sizeof( struct V_49 ) +
sizeof( struct V_98 ) +
sizeof( struct V_111 ) + V_106 * sizeof( V_112 ) ;
V_102 = F_24 ( V_104 , V_63 ) ;
if ( ! V_102 )
goto V_113;
F_25 ( & V_102 -> V_114 ) ;
V_102 -> V_104 = V_104 ;
V_99 = (struct V_98 * )
V_102 -> V_73 ;
V_99 -> V_115 = 1 ;
V_99 -> V_116 = sizeof( struct V_111 ) +
V_96 * sizeof( V_112 ) ;
V_99 -> V_117 [ 0 ] . V_118 = 0 ;
V_99 -> V_117 [ 0 ] . V_119 = V_92 ;
for ( V_95 = 0 ; V_95 < V_106 ; V_95 ++ )
V_99 -> V_117 [ 0 ] . V_120 [ V_95 ] = V_97 + V_95 ;
* V_93 = V_102 ;
* V_94 = 1 ;
V_105 = V_106 ;
V_107 = V_96 - V_106 ;
V_109 = V_110 -
sizeof( struct V_100 ) ;
V_106 = V_109 / sizeof( V_112 ) ;
while ( V_107 ) {
if ( V_107 > V_106 )
V_108 = V_106 ;
else
V_108 = V_107 ;
V_104 = sizeof( struct V_49 ) +
sizeof( struct V_100 ) +
V_108 * sizeof( V_112 ) ;
V_103 = F_24 ( V_104 , V_63 ) ;
if ( ! V_103 ) {
struct V_49 * V_121 = NULL ;
struct V_49 * V_122 = NULL ;
F_26 (pos, tmp,
&msgheader->submsglist,
msglistentry) {
F_19 ( & V_121 -> V_82 ) ;
F_20 ( V_121 ) ;
}
goto V_113;
}
V_103 -> V_104 = V_104 ;
( * V_94 ) ++ ;
V_101 =
(struct V_100 * ) V_103 -> V_73 ;
for ( V_95 = 0 ; V_95 < V_108 ; V_95 ++ )
V_101 -> V_97 [ V_95 ] = V_97 + V_105 + V_95 ;
F_16 ( & V_103 -> V_82 ,
& V_102 -> V_114 ) ;
V_105 += V_108 ;
V_107 -= V_108 ;
}
} else {
V_104 = sizeof( struct V_49 ) +
sizeof( struct V_98 ) +
sizeof( struct V_111 ) + V_96 * sizeof( V_112 ) ;
V_102 = F_24 ( V_104 , V_63 ) ;
if ( V_102 == NULL )
goto V_113;
V_102 -> V_104 = V_104 ;
V_99 = (struct V_98 * )
V_102 -> V_73 ;
V_99 -> V_115 = 1 ;
V_99 -> V_116 = sizeof( struct V_111 ) +
V_96 * sizeof( V_112 ) ;
V_99 -> V_117 [ 0 ] . V_118 = 0 ;
V_99 -> V_117 [ 0 ] . V_119 = V_92 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ )
V_99 -> V_117 [ 0 ] . V_120 [ V_95 ] = V_97 + V_95 ;
* V_93 = V_102 ;
* V_94 = 1 ;
}
return 0 ;
V_113:
F_20 ( V_102 ) ;
F_20 ( V_103 ) ;
return - V_65 ;
}
int F_13 ( struct V_1 * V_2 , void * V_91 ,
T_2 V_92 , T_2 * V_123 )
{
struct V_98 * V_124 ;
struct V_100 * V_101 ;
struct V_49 * V_93 = NULL ;
struct V_49 * V_125 ;
T_2 V_126 ;
struct V_127 * V_128 ;
T_2 V_129 ;
unsigned long V_53 ;
int V_54 = 0 ;
int V_55 ;
V_129 = F_27 ( & V_8 . V_129 ) ;
F_28 ( & V_8 . V_129 ) ;
V_54 = F_22 ( V_91 , V_92 , & V_93 , & V_126 ) ;
if ( V_54 )
return V_54 ;
F_15 ( & V_93 -> V_72 ) ;
V_124 = (struct V_98 * ) V_93 -> V_73 ;
V_124 -> V_74 . V_75 = V_130 ;
V_124 -> V_7 = V_2 -> V_5 . V_7 ;
V_124 -> V_131 = V_129 ;
F_8 ( & V_8 . V_81 , V_53 ) ;
F_16 ( & V_93 -> V_82 ,
& V_8 . V_83 ) ;
F_9 ( & V_8 . V_81 , V_53 ) ;
V_54 = F_17 ( V_124 , V_93 -> V_104 -
sizeof( * V_93 ) ) ;
if ( V_54 != 0 )
goto V_132;
if ( V_126 > 1 ) {
F_29 (curr, &msginfo->submsglist) {
V_125 = (struct V_49 * ) V_128 ;
V_101 =
(struct V_100 * ) V_125 -> V_73 ;
V_101 -> V_74 . V_75 =
V_133 ;
V_101 -> V_131 = V_129 ;
V_54 = F_17 ( V_101 ,
V_125 -> V_104 -
sizeof( * V_125 ) ) ;
if ( V_54 != 0 )
goto V_132;
}
}
V_55 = F_18 ( & V_93 -> V_72 , 5 * V_85 ) ;
F_30 ( V_55 == 0 ) ;
* V_123 = V_124 -> V_131 ;
V_132:
F_8 ( & V_8 . V_81 , V_53 ) ;
F_19 ( & V_93 -> V_82 ) ;
F_9 ( & V_8 . V_81 , V_53 ) ;
F_20 ( V_93 ) ;
return V_54 ;
}
int F_31 ( struct V_1 * V_2 , T_2 V_123 )
{
struct V_134 * V_73 ;
struct V_49 * V_135 ;
unsigned long V_53 ;
int V_54 , V_55 ;
V_135 = F_14 ( sizeof( * V_135 ) +
sizeof( struct V_134 ) , V_63 ) ;
if ( ! V_135 )
return - V_65 ;
F_15 ( & V_135 -> V_72 ) ;
V_73 = (struct V_134 * ) V_135 -> V_73 ;
V_73 -> V_74 . V_75 = V_136 ;
V_73 -> V_7 = V_2 -> V_5 . V_7 ;
V_73 -> V_131 = V_123 ;
F_8 ( & V_8 . V_81 , V_53 ) ;
F_16 ( & V_135 -> V_82 ,
& V_8 . V_83 ) ;
F_9 ( & V_8 . V_81 , V_53 ) ;
V_54 = F_17 ( V_73 ,
sizeof( struct V_134 ) ) ;
F_30 ( V_54 != 0 ) ;
V_55 = F_18 ( & V_135 -> V_72 , 5 * V_85 ) ;
F_30 ( V_55 == 0 ) ;
F_8 ( & V_8 . V_81 , V_53 ) ;
F_19 ( & V_135 -> V_82 ) ;
F_9 ( & V_8 . V_81 , V_53 ) ;
F_20 ( V_135 ) ;
return V_54 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_137 * V_73 ;
int V_54 ;
unsigned long V_53 ;
V_2 -> V_21 = V_58 ;
V_2 -> V_138 = NULL ;
F_8 ( & V_2 -> V_139 , V_53 ) ;
V_2 -> V_61 = NULL ;
F_9 ( & V_2 -> V_139 , V_53 ) ;
V_73 = & V_2 -> V_140 . V_73 ;
V_73 -> V_74 . V_75 = V_141 ;
V_73 -> V_7 = V_2 -> V_5 . V_7 ;
V_54 = F_17 ( V_73 , sizeof( struct V_137 ) ) ;
F_30 ( V_54 != 0 ) ;
if ( V_2 -> V_70 )
F_31 ( V_2 ,
V_2 -> V_70 ) ;
F_33 ( & V_2 -> V_40 ) ;
F_33 ( & V_2 -> V_39 ) ;
F_21 ( ( unsigned long ) V_2 -> V_66 ,
F_11 ( V_2 -> V_67 * V_142 ) ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_127 * V_143 , * V_122 ;
struct V_1 * V_144 ;
if ( V_2 -> V_145 != NULL ) {
return;
}
F_35 (cur, tmp, &channel->sc_list) {
V_144 = F_36 ( V_143 , struct V_1 , V_146 ) ;
if ( V_144 -> V_21 != V_90 )
continue;
F_32 ( V_144 ) ;
}
F_32 ( V_2 ) ;
}
int F_37 ( struct V_1 * V_2 , const void * V_147 ,
T_2 V_148 , V_112 V_149 ,
enum V_150 type , T_2 V_53 )
{
struct V_151 V_152 ;
T_2 V_153 = sizeof( struct V_151 ) + V_148 ;
T_2 V_154 = F_38 ( V_153 , sizeof( V_112 ) ) ;
struct V_155 V_156 [ 3 ] ;
V_112 V_157 = 0 ;
int V_54 ;
bool signal = false ;
V_152 . type = type ;
V_152 . V_53 = V_53 ;
V_152 . V_158 = sizeof( struct V_151 ) >> 3 ;
V_152 . V_159 = ( V_160 ) ( V_154 >> 3 ) ;
V_152 . V_161 = V_149 ;
F_39 ( V_156 , 3 ) ;
F_40 ( & V_156 [ 0 ] , & V_152 , sizeof( struct V_151 ) ) ;
F_40 ( & V_156 [ 1 ] , V_147 , V_148 ) ;
F_40 ( & V_156 [ 2 ] , & V_157 ,
V_154 - V_153 ) ;
V_54 = F_41 ( & V_2 -> V_40 , V_156 , 3 , & signal ) ;
if ( V_54 == 0 && signal )
F_1 ( V_2 ) ;
return V_54 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_162 V_163 [] ,
T_2 V_96 , void * V_147 , T_2 V_148 ,
V_112 V_149 )
{
int V_54 ;
int V_95 ;
struct V_164 V_152 ;
T_2 V_165 ;
T_2 V_153 ;
T_2 V_154 ;
struct V_155 V_156 [ 3 ] ;
V_112 V_157 = 0 ;
bool signal = false ;
if ( V_96 > V_166 )
return - V_60 ;
V_165 = sizeof( struct V_164 ) -
( ( V_166 - V_96 ) *
sizeof( struct V_162 ) ) ;
V_153 = V_165 + V_148 ;
V_154 = F_38 ( V_153 , sizeof( V_112 ) ) ;
V_152 . type = V_167 ;
V_152 . V_53 = V_168 ;
V_152 . V_169 = V_165 >> 3 ;
V_152 . V_170 = ( V_160 ) ( V_154 >> 3 ) ;
V_152 . V_171 = V_149 ;
V_152 . V_115 = V_96 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
V_152 . V_117 [ V_95 ] . V_172 = V_163 [ V_95 ] . V_172 ;
V_152 . V_117 [ V_95 ] . V_173 = V_163 [ V_95 ] . V_173 ;
V_152 . V_117 [ V_95 ] . V_97 = V_163 [ V_95 ] . V_97 ;
}
F_39 ( V_156 , 3 ) ;
F_40 ( & V_156 [ 0 ] , & V_152 , V_165 ) ;
F_40 ( & V_156 [ 1 ] , V_147 , V_148 ) ;
F_40 ( & V_156 [ 2 ] , & V_157 ,
V_154 - V_153 ) ;
V_54 = F_41 ( & V_2 -> V_40 , V_156 , 3 , & signal ) ;
if ( V_54 == 0 && signal )
F_1 ( V_2 ) ;
return V_54 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_174 * V_175 ,
void * V_147 , T_2 V_148 , V_112 V_149 )
{
int V_54 ;
struct V_176 V_152 ;
T_2 V_165 ;
T_2 V_153 ;
T_2 V_154 ;
struct V_155 V_156 [ 3 ] ;
V_112 V_157 = 0 ;
bool signal = false ;
T_2 V_106 = F_44 ( V_175 -> V_173 ,
V_175 -> V_172 ) ;
if ( ( V_106 < 0 ) || ( V_106 > V_177 ) )
return - V_60 ;
V_165 = sizeof( struct V_176 ) -
( ( V_177 - V_106 ) *
sizeof( V_112 ) ) ;
V_153 = V_165 + V_148 ;
V_154 = F_38 ( V_153 , sizeof( V_112 ) ) ;
V_152 . type = V_167 ;
V_152 . V_53 = V_168 ;
V_152 . V_169 = V_165 >> 3 ;
V_152 . V_170 = ( V_160 ) ( V_154 >> 3 ) ;
V_152 . V_171 = V_149 ;
V_152 . V_115 = 1 ;
V_152 . V_117 . V_172 = V_175 -> V_172 ;
V_152 . V_117 . V_173 = V_175 -> V_173 ;
memcpy ( V_152 . V_117 . V_120 , V_175 -> V_120 ,
V_106 * sizeof( V_112 ) ) ;
F_39 ( V_156 , 3 ) ;
F_40 ( & V_156 [ 0 ] , & V_152 , V_165 ) ;
F_40 ( & V_156 [ 1 ] , V_147 , V_148 ) ;
F_40 ( & V_156 [ 2 ] , & V_157 ,
V_154 - V_153 ) ;
V_54 = F_41 ( & V_2 -> V_40 , V_156 , 3 , & signal ) ;
if ( V_54 == 0 && signal )
F_1 ( V_2 ) ;
return V_54 ;
}
int F_45 ( struct V_1 * V_2 , void * V_147 ,
T_2 V_148 , T_2 * V_178 , V_112 * V_149 )
{
struct V_151 V_152 ;
T_2 V_153 ;
T_2 V_179 ;
int V_54 ;
bool signal = false ;
* V_178 = 0 ;
* V_149 = 0 ;
V_54 = F_46 ( & V_2 -> V_39 , & V_152 ,
sizeof( struct V_151 ) ) ;
if ( V_54 != 0 )
return 0 ;
V_153 = V_152 . V_159 << 3 ;
V_179 = V_153 - ( V_152 . V_158 << 3 ) ;
* V_178 = V_179 ;
if ( V_179 > V_148 ) {
F_47 ( L_1 ,
V_148 , V_179 ) ;
return - V_180 ;
}
* V_149 = V_152 . V_161 ;
V_54 = F_48 ( & V_2 -> V_39 , V_147 , V_179 ,
( V_152 . V_158 << 3 ) , & signal ) ;
if ( signal )
F_1 ( V_2 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , void * V_147 ,
T_2 V_148 , T_2 * V_178 ,
V_112 * V_149 )
{
struct V_151 V_152 ;
T_2 V_153 ;
int V_54 ;
bool signal = false ;
* V_178 = 0 ;
* V_149 = 0 ;
V_54 = F_46 ( & V_2 -> V_39 , & V_152 ,
sizeof( struct V_151 ) ) ;
if ( V_54 != 0 )
return 0 ;
V_153 = V_152 . V_159 << 3 ;
* V_178 = V_153 ;
if ( V_153 > V_148 ) {
F_47 ( L_2
L_3 ,
V_153 , V_148 ) ;
return - V_181 ;
}
* V_149 = V_152 . V_161 ;
V_54 = F_48 ( & V_2 -> V_39 , V_147 , V_153 , 0 ,
& signal ) ;
if ( signal )
F_1 ( V_2 ) ;
return 0 ;
}
