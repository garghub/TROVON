static T_1 F_1 ( void * V_1 )
{
struct V_2 * V_2 ;
T_1 V_3 = 0 ;
V_2 = F_2 ( V_1 ) ;
if ( V_2 )
V_3 = F_3 ( V_2 ) << V_4 ;
return V_3 ;
}
static int F_4 ( struct V_5 * V_6 , void T_2 * V_7 ,
T_3 V_8 )
{
struct V_9 * V_10 = F_5 ( V_6 ) ;
int V_11 = 0 ;
struct V_12 * V_13 = NULL ;
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_17 ;
unsigned V_18 ;
int V_19 , V_20 ;
T_3 V_21 ;
V_18 = V_10 -> V_18 ;
if ( ! V_18 ) {
V_19 = 0 ;
V_20 = 0 ;
V_18 = 1 ;
} else {
V_19 = 1 ;
V_20 = ! F_6 ( V_6 ) ;
}
V_21 = sizeof( * V_13 ) ;
if ( ! V_19 )
V_21 -= 7 * sizeof( T_1 ) ;
if ( V_8 < V_21 ) {
V_11 = - V_22 ;
goto V_23;
}
V_13 = F_7 ( sizeof( * V_13 ) , V_24 ) ;
if ( V_13 == NULL ) {
V_11 = - V_25 ;
goto V_23;
}
V_11 = V_15 -> V_26 ( V_10 , V_13 ) ;
if ( V_11 < 0 )
goto V_23;
V_13 -> V_27 = V_15 -> V_28 ;
V_13 -> V_29 = V_15 -> V_30 ;
V_13 -> V_31 = V_10 -> V_32 ;
V_13 -> V_33 = V_15 -> V_34 ;
V_13 -> V_35 =
V_10 -> V_36 * V_10 -> V_37 ;
V_13 -> V_38 = V_10 -> V_39 ;
V_13 -> V_40 = V_13 -> V_35 /
V_10 -> V_36 ;
V_13 -> V_41 = V_15 -> V_42 / V_18 ;
if ( V_20 )
V_13 -> V_41 += V_15 -> V_42 % V_18 ;
V_13 -> V_43 = V_15 -> V_44 ;
V_13 -> V_45 = V_15 -> V_46 ;
V_13 -> V_47 = V_17 -> V_48 ;
V_13 -> V_49 = V_50 ;
V_13 -> V_51 = ( T_1 ) V_10 -> V_52 ;
V_13 -> V_53 = ( T_1 ) V_10 -> V_54 ;
V_13 -> V_55 = V_15 -> V_56 ;
V_13 -> V_57 = ( T_1 ) V_10 -> V_58 ;
V_13 -> V_59 = ( T_1 ) V_15 -> V_60 ;
V_13 -> V_61 = ( T_1 ) V_13 -> V_59 +
( char * ) V_17 -> V_62 -
( char * ) V_15 -> V_63 ;
V_13 -> V_64 = ( T_1 ) V_15 -> V_65 + V_15 -> V_66 * V_10 -> V_67 ;
if ( ! V_19 ) {
V_13 -> V_68 = V_10 -> V_69 ;
V_13 -> V_70 = ( T_1 ) V_10 -> V_71 ;
V_13 -> V_72 = F_1 ( V_10 -> V_73 ) ;
} else if ( V_20 ) {
V_13 -> V_68 = ( V_10 -> V_69 / V_18 ) +
( V_10 -> V_69 % V_18 ) ;
V_13 -> V_70 = ( T_1 ) V_10 -> V_71 +
V_15 -> V_74 *
( V_10 -> V_69 - V_13 -> V_68 ) ;
} else {
unsigned V_75 = F_6 ( V_6 ) - 1 ;
V_13 -> V_68 = V_10 -> V_69 / V_18 ;
V_13 -> V_70 = ( T_1 ) V_10 -> V_71 +
V_15 -> V_74 * V_13 -> V_68 * V_75 ;
}
if ( V_19 ) {
V_13 -> V_72 =
F_1 ( & V_10 -> V_73 [ F_6 ( V_6 ) ] ) ;
V_13 -> V_76 = F_1 ( V_10 -> V_77 ) ;
V_13 -> V_78 =
F_1 ( V_10 -> V_79 ) ;
V_13 -> V_80 =
F_1 ( V_10 -> V_81 ) ;
}
V_13 -> V_82 = ( V_13 -> V_70 - V_15 -> V_83 ) /
V_15 -> V_74 ;
V_13 -> V_84 = V_15 -> V_74 ;
V_13 -> V_85 = V_86 ;
V_13 -> V_87 = V_15 -> V_88 - 2 * sizeof( V_89 ) ;
V_13 -> V_90 = V_17 -> V_91 ;
V_13 -> V_92 = V_10 -> V_67 ;
V_13 -> V_93 = F_6 ( V_6 ) ;
V_13 -> V_94 = V_95 ;
V_13 -> V_94 |= 1U << 31 ;
V_13 -> V_96 = V_15 -> V_97 ;
if ( V_20 )
V_13 -> V_98 |= V_99 ;
V_21 = ( V_8 < sizeof( * V_13 ) ) ? V_8 : sizeof( * V_13 ) ;
if ( F_8 ( V_7 , V_13 , V_21 ) )
V_11 = - V_100 ;
V_23:
F_9 ( V_13 ) ;
return V_11 ;
}
static int F_10 ( struct V_9 * V_10 , struct V_5 * V_6 ,
const struct V_101 * V_102 )
{
int V_11 = 0 , V_103 ;
V_89 V_104 , V_105 , V_106 , V_107 , V_108 , V_109 ;
T_4 * V_110 ;
struct V_14 * V_15 = V_10 -> V_15 ;
T_1 V_111 ;
unsigned long V_112 ;
T_1 T_5 * V_113 ;
unsigned long V_114 [ 8 ] ;
struct V_2 * * V_115 = NULL ;
unsigned V_116 = F_6 ( V_6 ) ;
if ( ! V_15 -> V_117 ) {
V_11 = - V_25 ;
goto V_118;
}
V_106 = V_102 -> V_108 ;
if ( ! V_106 ) {
V_11 = - V_100 ;
goto V_118;
}
V_105 = V_10 -> V_67 * V_15 -> V_42 ;
if ( ! V_10 -> V_18 ) {
V_108 = V_15 -> V_42 ;
V_104 = V_10 -> V_119 ;
V_109 = 0 ;
} else if ( ! V_116 ) {
V_108 = ( V_15 -> V_42 / V_10 -> V_18 ) +
( V_15 -> V_42 % V_10 -> V_18 ) ;
V_109 = V_15 -> V_42 - V_108 ;
V_105 += V_109 ;
V_104 = F_11 ( V_6 ) ;
} else {
V_108 = V_15 -> V_42 / V_10 -> V_18 ;
V_109 = V_108 * ( V_116 - 1 ) ;
V_105 += V_109 ;
V_104 = F_11 ( V_6 ) ;
}
if ( V_106 > V_108 ) {
F_12 ( V_15 -> V_120 , L_1
L_2 , V_106 , V_108 ) ;
V_106 = V_108 ;
}
V_115 = (struct V_2 * * ) V_10 -> V_121 ;
V_110 = ( T_4 * ) & V_115 [ V_15 -> V_42 ] ;
V_115 += V_109 ;
V_110 += V_109 ;
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
V_103 = V_108 ;
V_113 = ( T_1 T_5 * ) ( ( ( char T_5 * ) V_15 -> V_122 ) +
V_15 -> V_123 +
V_105 * sizeof( * V_113 ) ) ;
V_112 = V_102 -> V_124 ;
if ( ! F_13 ( V_125 , ( void T_2 * ) V_112 ,
V_106 * V_50 ) ) {
V_11 = - V_100 ;
goto V_118;
}
V_11 = F_14 ( V_112 , V_106 , V_115 ) ;
if ( V_11 ) {
F_12 ( V_15 -> V_120 ,
L_3
L_4 , ( void * ) V_112 , V_106 , - V_11 ) ;
goto V_118;
}
for ( V_107 = 0 ; V_107 < V_106 ; V_107 ++ , V_112 += V_50 ) {
for (; V_103 -- ; V_104 ++ ) {
if ( V_104 == V_108 )
V_104 = 0 ;
if ( ! V_15 -> V_117 [ V_105 + V_104 ] )
break;
}
if ( V_103 < 0 ) {
V_107 -- ;
V_11 = - V_25 ;
break;
}
V_110 [ V_107 ] = V_104 + V_109 ;
V_15 -> V_117 [ V_105 + V_104 ] = V_115 [ V_107 ] ;
V_15 -> V_126 [ V_105 + V_104 ] =
F_15 ( V_15 -> V_120 , V_115 [ V_107 ] , 0 , V_50 ,
V_127 ) ;
F_16 ( V_104 , V_114 ) ;
V_111 = V_15 -> V_126 [ V_105 + V_104 ] ;
V_15 -> V_128 ( V_15 , & V_113 [ V_104 ] ,
V_129 , V_111 ) ;
V_104 ++ ;
}
if ( V_11 ) {
V_89 V_130 ;
V_131:
V_130 = sizeof( V_114 ) * V_132 ;
if ( V_130 > V_108 )
V_130 = V_108 ;
V_104 = F_17 ( ( const unsigned long * ) V_114 , V_130 ) ;
for (; V_104 < V_130 ; V_104 ++ ) {
if ( ! F_18 ( V_104 , V_114 ) )
continue;
if ( V_15 -> V_117 [ V_105 + V_104 ] ) {
T_6 V_133 ;
V_133 = V_15 -> V_126 [ V_105 + V_104 ] ;
V_15 -> V_126 [ V_105 + V_104 ] = V_15 -> V_134 ;
V_15 -> V_128 ( V_15 , & V_113 [ V_104 ] ,
V_129 ,
V_15 -> V_134 ) ;
F_19 ( V_15 -> V_120 , V_133 , V_50 ,
V_127 ) ;
V_15 -> V_117 [ V_105 + V_104 ] = NULL ;
}
}
F_20 ( V_115 , V_106 ) ;
} else {
if ( F_8 ( ( void T_2 * )
( unsigned long ) V_102 -> V_110 ,
V_110 , V_106 * sizeof( * V_110 ) ) ) {
V_11 = - V_100 ;
goto V_131;
}
if ( F_8 ( ( void T_2 * ) ( unsigned long ) V_102 -> V_114 ,
V_114 , sizeof V_114 ) ) {
V_11 = - V_100 ;
goto V_131;
}
if ( V_104 == V_108 )
V_104 = 0 ;
if ( ! V_10 -> V_18 )
V_10 -> V_119 = V_104 ;
else
F_11 ( V_6 ) = V_104 ;
}
V_118:
return V_11 ;
}
static int F_21 ( struct V_9 * V_10 , unsigned V_116 ,
const struct V_101 * V_102 )
{
int V_11 = 0 ;
V_89 V_104 , V_105 , V_106 , V_130 , V_108 ;
struct V_14 * V_15 = V_10 -> V_15 ;
T_1 T_5 * V_113 ;
unsigned long V_114 [ 8 ] ;
if ( ! V_15 -> V_117 ) {
V_11 = - V_25 ;
goto V_118;
}
if ( F_22 ( V_114 , ( void T_2 * ) ( unsigned long ) V_102 -> V_114 ,
sizeof V_114 ) ) {
V_11 = - V_100 ;
goto V_118;
}
V_105 = V_10 -> V_67 * V_15 -> V_42 ;
if ( ! V_10 -> V_18 )
V_108 = V_15 -> V_42 ;
else if ( ! V_116 ) {
V_108 = ( V_15 -> V_42 / V_10 -> V_18 ) +
( V_15 -> V_42 % V_10 -> V_18 ) ;
V_105 += V_15 -> V_42 - V_108 ;
} else {
V_108 = V_15 -> V_42 / V_10 -> V_18 ;
V_105 += V_108 * ( V_116 - 1 ) ;
}
V_113 = ( T_1 T_5 * ) ( ( char T_5 * ) ( V_15 -> V_122 ) +
V_15 -> V_123 +
V_105 * sizeof( * V_113 ) ) ;
V_130 = sizeof( V_114 ) * V_132 ;
if ( V_130 > V_108 )
V_130 = V_108 ;
V_104 = F_17 ( V_114 , V_130 ) ;
for ( V_106 = 0 ; V_104 < V_130 ; V_104 ++ ) {
if ( ! F_18 ( V_104 , V_114 ) )
continue;
V_106 ++ ;
if ( V_15 -> V_117 [ V_105 + V_104 ] ) {
struct V_2 * V_1 ;
T_6 V_133 ;
V_1 = V_15 -> V_117 [ V_105 + V_104 ] ;
V_15 -> V_117 [ V_105 + V_104 ] = NULL ;
V_133 = V_15 -> V_126 [ V_105 + V_104 ] ;
V_15 -> V_126 [ V_105 + V_104 ] = V_15 -> V_134 ;
V_15 -> V_128 ( V_15 , & V_113 [ V_104 ] ,
V_129 , V_15 -> V_134 ) ;
F_19 ( V_15 -> V_120 , V_133 , V_50 ,
V_127 ) ;
F_20 ( & V_1 , 1 ) ;
}
}
V_118:
return V_11 ;
}
static int F_23 ( struct V_9 * V_10 , T_4 V_135 )
{
struct V_16 * V_17 = V_10 -> V_17 ;
int V_107 , V_136 = 0 , V_137 = - 1 ;
T_4 V_138 = V_135 & 0x7FFF ;
int V_11 ;
if ( V_138 == ( V_139 & 0x7FFF ) ) {
V_11 = 0 ;
goto V_23;
}
if ( ! V_138 ) {
V_11 = - V_22 ;
goto V_23;
}
V_135 |= 0x8000 ;
for ( V_107 = 0 ; V_107 < F_24 ( V_10 -> V_140 ) ; V_107 ++ ) {
if ( ! V_10 -> V_140 [ V_107 ] && V_137 == - 1 )
V_137 = V_107 ;
if ( V_10 -> V_140 [ V_107 ] == V_135 ) {
V_11 = - V_141 ;
goto V_23;
}
}
if ( V_137 == - 1 ) {
V_11 = - V_142 ;
goto V_23;
}
for ( V_136 = V_107 = 0 ; V_107 < F_24 ( V_17 -> V_140 ) ; V_107 ++ ) {
if ( ! V_17 -> V_140 [ V_107 ] ) {
V_136 ++ ;
continue;
}
if ( V_17 -> V_140 [ V_107 ] == V_135 ) {
T_7 * V_143 = & V_17 -> V_144 [ V_107 ] ;
if ( F_25 ( V_143 ) > 1 ) {
V_10 -> V_140 [ V_137 ] = V_135 ;
V_11 = 0 ;
goto V_23;
} else {
F_26 ( V_143 ) ;
V_136 ++ ;
}
}
if ( ( V_17 -> V_140 [ V_107 ] & 0x7FFF ) == V_138 ) {
V_11 = - V_141 ;
goto V_23;
}
}
if ( ! V_136 ) {
V_11 = - V_142 ;
goto V_23;
}
for ( V_136 = V_107 = 0 ; V_107 < F_24 ( V_17 -> V_140 ) ; V_107 ++ ) {
if ( ! V_17 -> V_140 [ V_107 ] &&
F_25 ( & V_17 -> V_144 [ V_107 ] ) == 1 ) {
V_10 -> V_140 [ V_137 ] = V_135 ;
V_17 -> V_140 [ V_107 ] = V_135 ;
( void ) V_17 -> V_15 -> V_145 ( V_17 , V_146 , 0 ) ;
V_11 = 0 ;
goto V_23;
}
}
V_11 = - V_142 ;
V_23:
return V_11 ;
}
static int F_27 ( struct V_9 * V_10 , unsigned V_116 ,
int V_147 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
unsigned int V_148 ;
if ( V_116 )
goto V_23;
if ( V_147 ) {
if ( V_10 -> V_149 )
F_28 ( V_10 ) ;
V_148 = V_150 ;
} else
V_148 = V_151 ;
V_15 -> V_152 ( V_10 -> V_17 , V_148 , V_10 -> V_67 ) ;
V_23:
return 0 ;
}
static void F_29 ( struct V_9 * V_10 ,
struct V_14 * V_15 )
{
int V_107 , V_153 , V_154 = 0 ;
T_1 V_155 ;
struct V_16 * V_17 = V_10 -> V_17 ;
V_155 = ( T_1 ) V_17 -> V_140 [ 0 ] |
( ( T_1 ) V_17 -> V_140 [ 1 ] << 16 ) |
( ( T_1 ) V_17 -> V_140 [ 2 ] << 32 ) |
( ( T_1 ) V_17 -> V_140 [ 3 ] << 48 ) ;
for ( V_107 = 0 ; V_107 < F_24 ( V_10 -> V_140 ) ; V_107 ++ ) {
if ( ! V_10 -> V_140 [ V_107 ] )
continue;
for ( V_153 = 0 ; V_153 < F_24 ( V_17 -> V_140 ) ; V_153 ++ ) {
if ( ( V_17 -> V_140 [ V_153 ] & 0x7fff ) !=
( V_10 -> V_140 [ V_107 ] & 0x7fff ) )
continue;
if ( F_30 ( & V_17 -> V_144 [ V_153 ] ) ) {
V_17 -> V_140 [ V_153 ] = 0 ;
V_154 ++ ;
}
break;
}
V_10 -> V_140 [ V_107 ] = 0 ;
}
if ( V_154 )
( void ) V_17 -> V_15 -> V_145 ( V_17 , V_146 , 0 ) ;
}
static int F_31 ( struct V_156 * V_157 , struct V_9 * V_10 ,
unsigned V_158 , void * V_159 , V_89 V_160 , char * V_161 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
unsigned long V_162 ;
int V_11 ;
if ( ( V_157 -> V_163 - V_157 -> V_164 ) > V_158 ) {
F_12 ( V_15 -> V_120 ,
L_5 , V_161 ,
V_157 -> V_163 - V_157 -> V_164 , V_158 ) ;
V_11 = - V_100 ;
goto V_23;
}
if ( ! V_160 ) {
if ( V_157 -> V_165 & V_166 ) {
F_12 ( V_15 -> V_120 ,
L_6 , V_161 ) ;
V_11 = - V_167 ;
goto V_23;
}
V_157 -> V_165 &= ~ V_168 ;
}
V_162 = F_32 ( V_159 ) >> V_4 ;
V_11 = F_33 ( V_157 , V_157 -> V_164 , V_162 ,
V_158 , V_157 -> V_169 ) ;
if ( V_11 )
F_12 ( V_15 -> V_120 , L_7
L_8 , V_161 , V_10 -> V_67 ,
V_162 , V_158 , V_11 ) ;
V_23:
return V_11 ;
}
static int F_34 ( struct V_156 * V_157 , struct V_14 * V_15 ,
T_1 V_170 )
{
unsigned long V_133 ;
unsigned long V_21 ;
int V_11 ;
V_21 = V_15 -> V_171 & V_172 ? 2 * V_50 : V_50 ;
if ( ( V_157 -> V_163 - V_157 -> V_164 ) > V_21 ) {
F_12 ( V_15 -> V_120 , L_9
L_10 , V_157 -> V_163 - V_157 -> V_164 ) ;
V_11 = - V_100 ;
} else {
V_133 = V_15 -> V_111 + V_170 ;
V_157 -> V_169 = F_35 ( V_157 -> V_169 ) ;
V_157 -> V_165 |= V_173 | V_174 ;
V_11 = F_36 ( V_157 , V_157 -> V_164 ,
V_133 >> V_4 ,
V_157 -> V_163 - V_157 -> V_164 ,
V_157 -> V_169 ) ;
}
return V_11 ;
}
static int F_37 ( struct V_156 * V_157 ,
struct V_14 * V_15 ,
struct V_9 * V_10 ,
unsigned V_71 , unsigned V_69 )
{
unsigned long V_133 ;
int V_11 ;
if ( ( V_157 -> V_163 - V_157 -> V_164 ) > ( V_69 * V_15 -> V_74 ) ) {
F_12 ( V_15 -> V_120 , L_11
L_12 ,
V_157 -> V_163 - V_157 -> V_164 ) ;
V_11 = - V_22 ;
goto V_23;
}
V_133 = V_15 -> V_111 + V_71 ;
#if F_38 ( V_175 )
F_39 ( V_157 -> V_169 ) |= V_176 ;
F_39 ( V_157 -> V_169 ) |= V_177 ;
F_39 ( V_157 -> V_169 ) &= ~ V_178 ;
#endif
V_157 -> V_165 &= ~ V_179 ;
V_157 -> V_165 |= V_173 | V_174 ;
if ( V_180 )
V_157 -> V_169 = F_40 ( V_157 -> V_169 ) ;
V_11 = F_36 ( V_157 , V_157 -> V_164 , V_133 >> V_4 ,
V_157 -> V_163 - V_157 -> V_164 ,
V_157 -> V_169 ) ;
V_23:
return V_11 ;
}
static int F_41 ( struct V_156 * V_157 ,
struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
unsigned long V_181 , V_182 ;
T_3 V_183 , V_107 ;
unsigned long V_162 ;
int V_11 ;
V_182 = V_10 -> V_37 ;
V_183 = V_10 -> V_36 * V_182 ;
if ( ( V_157 -> V_163 - V_157 -> V_164 ) > V_183 ) {
F_12 ( V_15 -> V_120 , L_13
L_14 ,
V_157 -> V_163 - V_157 -> V_164 ,
( unsigned long ) V_183 ) ;
V_11 = - V_22 ;
goto V_23;
}
if ( V_157 -> V_165 & V_166 ) {
F_12 ( V_15 -> V_120 , L_15
L_16 , V_157 -> V_165 ) ;
V_11 = - V_167 ;
goto V_23;
}
V_157 -> V_165 &= ~ V_168 ;
V_181 = V_157 -> V_164 ;
for ( V_107 = 0 ; V_107 < V_10 -> V_36 ; V_107 ++ , V_181 += V_182 ) {
V_162 = F_32 ( V_10 -> V_184 [ V_107 ] ) >> V_4 ;
V_11 = F_33 ( V_157 , V_181 , V_162 , V_182 ,
V_157 -> V_169 ) ;
if ( V_11 < 0 )
goto V_23;
}
V_11 = 0 ;
V_23:
return V_11 ;
}
static int F_42 ( struct V_156 * V_157 , struct V_185 * V_186 )
{
struct V_2 * V_2 ;
V_2 = F_2 ( ( void * ) ( V_186 -> V_187 << V_4 ) ) ;
if ( ! V_2 )
return V_188 ;
F_43 ( V_2 ) ;
V_186 -> V_2 = V_2 ;
return 0 ;
}
static int F_44 ( struct V_156 * V_157 , T_1 V_189 ,
struct V_9 * V_10 , unsigned V_116 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
unsigned V_18 ;
unsigned long V_158 ;
void * V_190 ;
T_3 V_182 ;
int V_11 = 0 ;
V_18 = V_10 -> V_18 ;
V_182 = V_10 -> V_36 * V_10 -> V_37 ;
if ( V_189 == F_1 ( V_10 -> V_77 ) ) {
V_190 = V_10 -> V_77 ;
V_182 = V_50 * V_18 ;
} else if ( V_189 == F_1 ( V_10 -> V_81 ) ) {
V_190 = V_10 -> V_81 ;
V_182 = V_10 -> V_191 * V_18 ;
} else if ( V_189 == F_1 ( V_10 -> V_79 ) ) {
V_190 = V_10 -> V_79 ;
V_182 *= V_18 ;
} else if ( V_189 == F_1 ( V_10 -> V_77 +
V_50 * V_116 ) ) {
V_190 = V_10 -> V_77 + V_50 * V_116 ;
V_182 = V_50 ;
} else if ( V_189 == F_1 ( V_10 -> V_81 +
V_10 -> V_191 * V_116 ) ) {
V_190 = V_10 -> V_81 +
V_10 -> V_191 * V_116 ;
V_182 = V_10 -> V_191 ;
} else if ( V_189 == F_1 ( & V_10 -> V_73 [ V_116 ] ) ) {
V_190 = V_10 -> V_73 ;
V_182 = V_50 ;
} else if ( V_189 == F_1 ( V_10 -> V_79 +
V_182 * V_116 ) ) {
V_190 = V_10 -> V_79 + V_182 * V_116 ;
if ( V_157 -> V_165 & V_166 ) {
F_12 ( V_15 -> V_120 ,
L_15
L_16 , V_157 -> V_165 ) ;
V_11 = - V_167 ;
goto V_23;
}
V_157 -> V_165 &= ~ V_168 ;
} else
goto V_23;
V_158 = V_157 -> V_163 - V_157 -> V_164 ;
if ( V_158 > V_182 ) {
V_11 = - V_22 ;
goto V_23;
}
V_157 -> V_192 = ( unsigned long ) V_190 >> V_4 ;
V_157 -> V_193 = & V_194 ;
V_157 -> V_165 |= V_195 | V_174 ;
V_11 = 1 ;
V_23:
return V_11 ;
}
static int F_45 ( struct V_5 * V_6 , struct V_156 * V_157 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
T_1 V_189 , V_170 ;
unsigned V_71 , V_69 ;
int V_11 , V_196 = 1 ;
V_10 = F_5 ( V_6 ) ;
if ( ! V_10 || ! ( V_157 -> V_165 & V_197 ) ) {
V_11 = - V_22 ;
goto V_23;
}
V_15 = V_10 -> V_15 ;
V_189 = V_157 -> V_192 << V_4 ;
if ( ! V_189 ) {
V_11 = - V_22 ;
goto V_23;
}
V_11 = F_44 ( V_157 , V_189 , V_10 , F_6 ( V_6 ) ) ;
if ( V_11 ) {
if ( V_11 > 0 )
V_11 = 0 ;
goto V_23;
}
V_170 = V_15 -> V_65 + V_15 -> V_66 * V_10 -> V_67 ;
if ( ! V_10 -> V_18 ) {
V_69 = V_10 -> V_69 ;
V_71 = V_10 -> V_71 ;
} else if ( ! F_6 ( V_6 ) ) {
V_69 = ( V_10 -> V_69 / V_10 -> V_18 ) +
( V_10 -> V_69 % V_10 -> V_18 ) ;
V_71 = V_10 -> V_71 +
V_15 -> V_74 * ( V_10 -> V_69 - V_69 ) ;
} else {
unsigned V_75 = F_6 ( V_6 ) - 1 ;
V_69 = V_10 -> V_69 / V_10 -> V_18 ;
V_71 = V_10 -> V_71 + V_15 -> V_74 * V_69 * V_75 ;
}
if ( V_189 == V_170 )
V_11 = F_34 ( V_157 , V_15 , V_170 ) ;
else if ( V_189 == V_71 )
V_11 = F_37 ( V_157 , V_15 , V_10 , V_71 , V_69 ) ;
else if ( V_189 == V_15 -> V_60 )
V_11 = F_31 ( V_157 , V_10 , V_50 ,
( void * ) V_15 -> V_63 , 0 ,
L_17 ) ;
else if ( V_189 == V_10 -> V_58 )
V_11 = F_41 ( V_157 , V_10 ) ;
else if ( V_189 == ( T_1 ) V_10 -> V_52 )
V_11 = F_31 ( V_157 , V_10 , V_10 -> V_191 ,
V_10 -> V_198 , 1 , L_18 ) ;
else if ( V_189 == ( T_1 ) V_10 -> V_54 )
V_11 = F_31 ( V_157 , V_10 , V_50 ,
V_10 -> V_149 , 0 ,
L_19 ) ;
else
V_196 = 0 ;
if ( ! V_196 )
V_11 = - V_22 ;
V_157 -> V_199 = NULL ;
if ( V_11 < 0 )
F_12 ( V_15 -> V_120 ,
L_20 ,
- V_11 , ( unsigned long long ) V_189 ,
V_157 -> V_163 - V_157 -> V_164 ) ;
V_23:
return V_11 ;
}
static unsigned int F_46 ( struct V_9 * V_10 ,
struct V_5 * V_6 ,
struct V_200 * V_201 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
unsigned V_202 ;
F_47 ( V_6 , & V_10 -> V_203 , V_201 ) ;
F_48 ( & V_15 -> V_204 ) ;
if ( V_10 -> V_205 != V_10 -> V_206 ) {
V_202 = V_207 | V_208 ;
V_10 -> V_206 = V_10 -> V_205 ;
} else {
V_202 = 0 ;
F_49 ( V_209 , & V_10 -> V_210 ) ;
}
F_50 ( & V_15 -> V_204 ) ;
return V_202 ;
}
static unsigned int F_51 ( struct V_9 * V_10 ,
struct V_5 * V_6 ,
struct V_200 * V_201 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
unsigned V_202 ;
F_47 ( V_6 , & V_10 -> V_203 , V_201 ) ;
F_48 ( & V_15 -> V_204 ) ;
if ( V_15 -> V_211 ( V_10 ) ) {
F_49 ( V_212 , & V_10 -> V_210 ) ;
V_15 -> V_152 ( V_10 -> V_17 , V_213 , V_10 -> V_67 ) ;
V_202 = 0 ;
} else
V_202 = V_207 | V_208 ;
F_50 ( & V_15 -> V_204 ) ;
return V_202 ;
}
static unsigned int F_52 ( struct V_5 * V_6 , struct V_200 * V_201 )
{
struct V_9 * V_10 ;
unsigned V_202 ;
V_10 = F_5 ( V_6 ) ;
if ( ! V_10 )
V_202 = V_214 ;
else if ( V_10 -> V_215 == V_216 )
V_202 = F_46 ( V_10 , V_6 , V_201 ) ;
else if ( V_10 -> V_215 == V_217 )
V_202 = F_51 ( V_10 , V_6 , V_201 ) ;
else
V_202 = V_214 ;
return V_202 ;
}
static int F_53 ( int V_218 , int V_219 )
{
if ( V_220 != V_218 ) {
return 0 ;
}
if ( V_220 == 1 ) {
switch ( V_221 ) {
case 0 :
case 1 :
case 2 :
return 0 ;
case 3 :
return V_219 == 3 ;
default:
return V_219 >= 4 ;
}
}
return 0 ;
}
static int F_54 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
const struct V_222 * V_223 )
{
int V_11 = 0 ;
unsigned V_224 ;
T_3 V_182 ;
if ( V_223 -> V_225 <= 0 )
goto V_23;
V_224 = V_223 -> V_225 ;
if ( ! F_53 ( V_223 -> V_226 >> 16 ,
V_223 -> V_226 & 0xffff ) ) {
F_12 ( V_15 -> V_120 ,
L_21
L_22
L_23
L_24 ,
( int ) ( V_223 -> V_226 >> 16 ) ,
( int ) ( V_223 -> V_226 & 0xffff ) ,
V_220 , V_221 ) ;
goto V_23;
}
if ( V_224 > V_227 ) {
V_11 = - V_22 ;
goto V_23;
}
V_10 -> V_77 = F_55 ( V_50 * V_224 ) ;
if ( ! V_10 -> V_77 ) {
V_11 = - V_25 ;
goto V_23;
}
V_182 = F_56 ( V_15 -> V_28 * V_15 -> V_30 *
sizeof( V_89 ) , V_50 ) * V_224 ;
V_10 -> V_81 = F_55 ( V_182 ) ;
if ( ! V_10 -> V_81 ) {
V_11 = - V_25 ;
goto V_228;
}
V_10 -> V_79 = F_55 ( V_10 -> V_36 *
V_10 -> V_37 *
V_224 ) ;
if ( ! V_10 -> V_79 ) {
V_11 = - V_25 ;
goto V_229;
}
V_10 -> V_18 = V_223 -> V_225 ;
V_10 -> V_230 = V_223 -> V_231 ;
V_10 -> V_232 = 1 ;
V_10 -> V_233 = 1 ;
F_49 ( V_234 , & V_10 -> V_210 ) ;
goto V_23;
V_229:
F_57 ( V_10 -> V_81 ) ;
V_228:
F_57 ( V_10 -> V_77 ) ;
V_10 -> V_77 = NULL ;
V_23:
return V_11 ;
}
static int F_58 ( struct V_16 * V_17 , int V_67 ,
struct V_5 * V_6 , const struct V_222 * V_223 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
struct V_9 * V_10 ;
void * V_235 = NULL ;
int V_11 ;
V_10 = F_59 ( V_17 , V_67 ) ;
if ( V_10 )
V_235 = F_60 ( V_15 -> V_42 * sizeof( T_4 ) +
V_15 -> V_42 * sizeof( struct V_2 * * ) ,
V_24 ) ;
if ( ! V_10 || ! V_235 ) {
F_61 ( V_15 , L_25
L_26 ) ;
V_11 = - V_25 ;
goto V_236;
}
V_10 -> V_237 = V_223 -> V_226 ;
V_11 = F_54 ( V_15 , V_10 , V_223 ) ;
if ( V_11 )
goto V_236;
V_10 -> V_121 = V_235 ;
V_10 -> V_238 = V_239 -> V_238 ;
F_62 ( & V_15 -> V_10 [ V_67 ] -> V_203 ) ;
F_63 ( V_10 -> V_240 , V_239 -> V_240 , sizeof( V_10 -> V_240 ) ) ;
F_5 ( V_6 ) = V_10 ;
V_241 . V_242 ++ ;
V_15 -> V_243 -- ;
V_11 = 0 ;
goto V_23;
V_236:
V_15 -> V_10 [ V_67 ] = NULL ;
F_9 ( V_10 ) ;
F_9 ( V_235 ) ;
V_23:
return V_11 ;
}
static inline int F_64 ( struct V_16 * V_17 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
return V_15 && ( V_15 -> V_171 & V_244 ) && V_15 -> V_122 && V_17 -> V_245 &&
( V_17 -> V_246 & V_247 ) ;
}
static int F_65 ( struct V_5 * V_6 , struct V_14 * V_15 , V_89 V_48 ,
const struct V_222 * V_223 )
{
struct V_16 * V_17 = NULL ;
int V_11 , V_67 ;
if ( V_48 ) {
if ( ! F_64 ( V_15 -> V_248 + V_48 - 1 ) ) {
V_11 = - V_249 ;
goto V_118;
} else
V_17 = V_15 -> V_248 + V_48 - 1 ;
}
for ( V_67 = V_15 -> V_250 ; V_67 < V_15 -> V_44 && V_15 -> V_10 [ V_67 ] ;
V_67 ++ )
;
if ( V_67 == V_15 -> V_44 ) {
V_11 = - V_142 ;
goto V_118;
}
if ( ! V_17 ) {
V_89 V_137 = V_67 % V_15 -> V_251 ;
if ( F_64 ( V_15 -> V_248 + V_137 ) )
V_17 = V_15 -> V_248 + V_137 ;
else {
for ( V_137 = 0 ; V_137 < V_15 -> V_251 && ! V_17 ;
V_137 ++ )
if ( F_64 ( V_15 -> V_248 + V_137 ) )
V_17 = V_15 -> V_248 + V_137 ;
}
}
V_11 = V_17 ? F_58 ( V_17 , V_67 , V_6 , V_223 ) : - V_249 ;
V_118:
return V_11 ;
}
static int F_66 ( int V_46 , struct V_5 * V_6 ,
const struct V_222 * V_223 )
{
struct V_14 * V_15 = F_67 ( V_46 ) ;
int V_11 ;
if ( ! V_15 || ( V_223 -> V_252 && V_223 -> V_252 > V_15 -> V_251 ) )
V_11 = - V_253 ;
else
V_11 = F_65 ( V_6 , V_15 , V_223 -> V_252 , V_223 ) ;
return V_11 ;
}
static int F_68 ( struct V_5 * V_6 , const struct V_222 * V_223 ,
unsigned V_254 )
{
struct V_14 * V_255 = NULL ;
int V_11 = 0 , V_256 , V_257 , V_258 , V_259 , V_260 = 0 , V_107 ;
V_89 V_48 = V_223 -> V_252 , V_67 ;
V_256 = F_69 ( & V_257 , & V_258 ) ;
if ( ! V_257 ) {
V_11 = - V_261 ;
goto V_118;
}
if ( V_258 == 0 ) {
V_11 = - V_249 ;
goto V_118;
}
if ( V_254 == V_262 ) {
unsigned V_263 = ~ 0U ;
for ( V_259 = 0 ; V_259 < V_256 ; V_259 ++ ) {
struct V_14 * V_15 = F_67 ( V_259 ) ;
unsigned V_264 = 0 , V_265 = 0 , V_266 = 0 ;
if ( ! V_15 )
continue;
if ( V_48 && V_48 <= V_15 -> V_251 &&
F_64 ( V_15 -> V_248 + V_48 - 1 ) )
V_266 = 1 ;
else
for ( V_107 = 0 ; V_107 < V_15 -> V_251 ; V_107 ++ )
if ( F_64 ( V_15 -> V_248 + V_107 ) )
V_266 ++ ;
if ( ! V_266 )
continue;
for ( V_67 = V_15 -> V_250 ; V_67 < V_15 -> V_44 ;
V_67 ++ )
if ( V_15 -> V_10 [ V_67 ] )
V_264 ++ ;
else
V_265 ++ ;
if ( V_266 && V_265 && V_264 < V_263 ) {
V_255 = V_15 ;
V_263 = V_264 ;
}
}
if ( V_255 ) {
V_11 = F_65 ( V_6 , V_255 , V_48 , V_223 ) ;
goto V_118;
}
} else {
for ( V_259 = 0 ; V_259 < V_256 ; V_259 ++ ) {
struct V_14 * V_15 = F_67 ( V_259 ) ;
if ( V_15 ) {
V_11 = F_65 ( V_6 , V_15 , V_48 , V_223 ) ;
if ( ! V_11 )
goto V_118;
if ( V_11 == - V_142 )
V_260 ++ ;
}
}
}
V_11 = V_260 ? - V_142 : - V_249 ;
V_118:
return V_11 ;
}
static int F_70 ( struct V_5 * V_6 ,
const struct V_222 * V_223 )
{
int V_256 , V_259 , V_107 ;
int V_11 = 0 ;
V_256 = F_69 ( NULL , NULL ) ;
for ( V_259 = 0 ; V_259 < V_256 ; V_259 ++ ) {
struct V_14 * V_15 = F_67 ( V_259 ) ;
if ( ! ( V_15 && ( V_15 -> V_171 & V_244 ) && V_15 -> V_122 ) )
continue;
for ( V_107 = V_15 -> V_250 ; V_107 < V_15 -> V_44 ; V_107 ++ ) {
struct V_9 * V_10 = V_15 -> V_10 [ V_107 ] ;
if ( ! V_10 || ! V_10 -> V_106 )
continue;
if ( V_10 -> V_230 != V_223 -> V_231 )
continue;
if ( V_10 -> V_18 != V_223 -> V_225 ||
V_10 -> V_237 != V_223 -> V_226 ||
V_10 -> V_106 >= V_10 -> V_18 ) {
V_11 = - V_22 ;
goto V_118;
}
F_5 ( V_6 ) = V_10 ;
F_6 ( V_6 ) = V_10 -> V_106 ++ ;
V_10 -> V_267 [ F_6 ( V_6 ) ] = V_239 -> V_238 ;
F_11 ( V_6 ) = 0 ;
V_10 -> V_232 |= 1 << F_6 ( V_6 ) ;
V_11 = 1 ;
goto V_118;
}
}
V_118:
return V_11 ;
}
static int F_71 ( struct V_268 * V_269 , struct V_5 * V_6 )
{
V_6 -> V_270 = F_7 ( sizeof( struct V_271 ) , V_24 ) ;
if ( V_6 -> V_270 )
( (struct V_271 * ) V_6 -> V_270 ) -> V_272 = - 1 ;
return V_6 -> V_270 ? 0 : - V_25 ;
}
static int F_72 ( struct V_5 * V_6 , const struct V_222 * V_223 )
{
int V_11 ;
int V_273 ;
unsigned V_274 , V_275 , V_254 = V_262 ;
if ( F_5 ( V_6 ) ) {
V_11 = - V_22 ;
goto V_118;
}
V_274 = V_223 -> V_226 >> 16 ;
if ( V_274 != V_220 ) {
V_11 = - V_253 ;
goto V_118;
}
V_275 = V_223 -> V_226 & 0xffff ;
if ( V_275 >= 11 && V_223 -> V_276 < V_277 )
V_254 = V_223 -> V_276 ;
F_73 ( & V_278 ) ;
if ( F_53 ( V_274 , V_275 ) &&
V_223 -> V_225 ) {
V_11 = F_70 ( V_6 , V_223 ) ;
if ( V_11 ) {
if ( V_11 > 0 )
V_11 = 0 ;
goto V_279;
}
}
V_273 = F_74 ( V_6 -> V_280 -> V_281 ) - V_282 ;
if ( V_273 )
V_11 = F_66 ( V_273 - 1 , V_6 , V_223 ) ;
else
V_11 = F_68 ( V_6 , V_223 , V_254 ) ;
V_279:
if ( ! V_11 ) {
struct V_271 * V_283 = V_6 -> V_270 ;
const struct V_9 * V_10 = V_283 -> V_10 ;
const struct V_14 * V_15 = V_10 -> V_15 ;
unsigned int V_284 ;
if ( V_15 -> V_171 & V_285 ) {
V_283 -> V_286 = F_75 ( & V_15 -> V_120 -> V_287 ,
V_15 -> V_46 ,
V_10 -> V_67 ,
V_283 -> V_116 ) ;
if ( ! V_283 -> V_286 )
V_11 = - V_25 ;
}
V_284 = F_76 ( F_77 ( V_239 ) ) ;
if ( ! V_11 && V_284 >= V_288 ) {
int V_289 ;
V_289 = F_78 ( V_290 ,
V_288 ) ;
if ( V_289 != V_288 ) {
F_16 ( V_289 , V_290 ) ;
V_283 -> V_272 = V_289 ;
}
} else if ( V_284 == 1 &&
F_18 ( F_79 ( F_77 ( V_239 ) ) ,
V_290 ) )
F_12 ( V_15 -> V_120 , L_27
L_28 ,
V_239 -> V_240 , V_239 -> V_238 ,
F_79 ( F_77 ( V_239 ) ) ) ;
}
F_80 ( & V_278 ) ;
V_118:
return V_11 ;
}
static int F_81 ( struct V_5 * V_6 ,
const struct V_222 * V_223 )
{
int V_11 ;
struct V_9 * V_10 = F_5 ( V_6 ) ;
struct V_14 * V_15 ;
unsigned V_291 ;
if ( F_6 ( V_6 ) ) {
V_11 = F_82 ( V_10 -> V_203 ,
! F_18 ( V_234 , & V_10 -> V_210 ) ) ;
goto V_23;
}
V_15 = V_10 -> V_15 ;
V_291 = V_10 -> V_67 - V_15 -> V_250 ;
if ( V_291 < V_15 -> V_292 ) {
V_10 -> V_69 = V_15 -> V_293 + 1 ;
V_10 -> V_294 = V_10 -> V_69 * V_291 ;
} else {
V_10 -> V_69 = V_15 -> V_293 ;
V_10 -> V_294 = V_10 -> V_69 * V_291 +
V_15 -> V_292 ;
}
if ( ( V_10 -> V_294 + V_10 -> V_69 ) > V_15 -> V_295 ) {
if ( V_10 -> V_294 >= V_15 -> V_295 ) {
F_61 ( V_15 ,
L_29 ,
V_15 -> V_46 , V_10 -> V_67 ) ;
V_11 = - V_296 ;
goto V_23;
}
V_10 -> V_69 = V_15 -> V_295 - V_10 -> V_294 ;
F_61 ( V_15 , L_30 ,
V_10 -> V_67 , V_10 -> V_69 ) ;
}
V_10 -> V_71 = V_15 -> V_83 + V_10 -> V_294 * V_15 -> V_74 ;
F_83 ( V_15 , V_10 -> V_294 , V_10 -> V_69 ,
V_297 , V_10 ) ;
V_15 -> V_298 ( V_15 -> V_248 , V_299 ) ;
V_11 = F_84 ( V_15 , V_10 ) ;
if ( ! V_11 )
V_11 = F_85 ( V_10 ) ;
if ( V_11 )
goto V_300;
V_10 -> V_119 = 0 ;
V_10 -> V_205 = 0 ;
V_10 -> V_206 = 0 ;
if ( V_10 -> V_149 )
F_28 ( V_10 ) ;
V_15 -> V_152 ( V_10 -> V_17 , V_150 | V_301 ,
V_10 -> V_67 ) ;
if ( V_10 -> V_18 ) {
F_86 ( V_234 , & V_10 -> V_210 ) ;
F_87 ( & V_10 -> V_203 ) ;
}
return 0 ;
V_300:
F_83 ( V_15 , V_10 -> V_294 , V_10 -> V_69 ,
V_302 , V_10 ) ;
V_23:
return V_11 ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
int V_303 = V_10 -> V_67 * V_15 -> V_42 ;
int V_107 , V_106 = 0 , V_304 = V_303 + V_15 -> V_42 ;
for ( V_107 = V_303 ; V_107 < V_304 ; V_107 ++ ) {
struct V_2 * V_1 = V_15 -> V_117 [ V_107 ] ;
T_6 V_133 ;
if ( ! V_1 )
continue;
V_133 = V_15 -> V_126 [ V_107 ] ;
V_15 -> V_126 [ V_107 ] = V_15 -> V_134 ;
V_15 -> V_117 [ V_107 ] = NULL ;
F_19 ( V_15 -> V_120 , V_133 , V_50 ,
V_127 ) ;
F_20 ( & V_1 , 1 ) ;
V_106 ++ ;
}
}
static int F_89 ( struct V_268 * V_269 , struct V_5 * V_6 )
{
int V_11 = 0 ;
struct V_271 * V_283 ;
struct V_9 * V_10 ;
struct V_14 * V_15 ;
unsigned long V_171 ;
unsigned V_67 ;
T_8 V_238 ;
F_73 ( & V_278 ) ;
V_283 = V_6 -> V_270 ;
V_6 -> V_270 = NULL ;
V_10 = V_283 -> V_10 ;
if ( ! V_10 ) {
F_80 ( & V_278 ) ;
goto V_23;
}
V_15 = V_10 -> V_15 ;
F_90 () ;
if ( V_283 -> V_286 ) {
F_91 ( V_10 -> V_17 , V_283 -> V_286 ) ;
F_92 ( V_283 -> V_286 ) ;
}
if ( V_283 -> V_272 != - 1 )
F_93 ( V_283 -> V_272 , V_290 ) ;
if ( -- V_10 -> V_106 ) {
V_10 -> V_232 &= ~ ( 1 << V_283 -> V_116 ) ;
V_10 -> V_267 [ V_283 -> V_116 ] = 0 ;
F_80 ( & V_278 ) ;
goto V_23;
}
F_94 ( & V_15 -> V_204 , V_171 ) ;
V_67 = V_10 -> V_67 ;
V_15 -> V_10 [ V_67 ] = NULL ;
V_238 = V_10 -> V_238 ;
V_10 -> V_238 = 0 ;
F_95 ( & V_15 -> V_204 , V_171 ) ;
if ( V_10 -> V_305 || V_10 -> V_306 ||
V_10 -> V_307 || V_10 -> V_308 ) {
V_10 -> V_305 = 0 ;
V_10 -> V_306 = 0 ;
V_10 -> V_307 = 0 ;
V_10 -> V_308 = 0 ;
}
if ( V_10 -> V_210 )
V_10 -> V_210 = 0 ;
if ( V_15 -> V_122 ) {
V_15 -> V_152 ( V_10 -> V_17 , V_151 |
V_309 , V_67 ) ;
F_29 ( V_10 , V_15 ) ;
F_96 ( V_15 , V_10 -> V_294 , V_10 -> V_69 ) ;
F_83 ( V_15 , V_10 -> V_294 ,
V_10 -> V_69 , V_302 , NULL ) ;
V_15 -> V_310 ( V_15 , V_10 ) ;
if ( V_15 -> V_117 )
F_88 ( V_10 ) ;
V_241 . V_242 -- ;
V_15 -> V_243 ++ ;
}
F_80 ( & V_278 ) ;
F_97 ( V_15 , V_10 ) ;
V_23:
F_9 ( V_283 ) ;
return V_11 ;
}
static int F_98 ( struct V_5 * V_6 , struct F_98 T_2 * V_223 )
{
struct F_98 V_311 ;
int V_11 ;
T_3 V_21 ;
struct V_9 * V_10 = F_5 ( V_6 ) ;
struct V_271 * V_283 ;
V_283 = V_6 -> V_270 ;
V_311 . V_312 = F_99 () ;
V_311 . V_46 = V_10 -> V_15 -> V_46 ;
V_311 . V_48 = V_10 -> V_17 -> V_48 ;
V_311 . V_67 = V_10 -> V_67 ;
V_311 . V_116 = F_6 ( V_6 ) ;
V_311 . V_313 = V_10 -> V_15 -> V_44 - V_10 -> V_15 -> V_250 ;
V_311 . V_224 = V_10 -> V_18 ;
V_311 . V_314 = V_283 -> V_272 ;
V_21 = sizeof( V_311 ) ;
if ( F_8 ( V_223 , & V_311 , V_21 ) ) {
V_11 = - V_100 ;
goto V_23;
}
V_11 = 0 ;
V_23:
return V_11 ;
}
static int F_100 ( struct V_315 * V_286 ,
V_89 T_2 * V_316 )
{
const V_89 V_317 = F_101 ( V_286 ) ;
if ( F_102 ( V_317 , V_316 ) )
return - V_100 ;
return 0 ;
}
static int F_103 ( struct V_16 * V_17 ,
struct V_315 * V_286 ,
V_89 T_2 * V_318 )
{
V_89 V_317 ;
int V_319 ;
if ( ! V_286 )
return - V_22 ;
V_319 = F_104 ( V_17 , V_286 ) ;
if ( V_319 < 0 )
return V_319 ;
V_317 = F_105 ( V_286 ) ;
if ( F_102 ( V_317 , V_318 ) )
return - V_100 ;
return 0 ;
}
static int F_106 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
if ( ! F_64 ( V_10 -> V_17 ) ) {
int V_107 ;
if ( V_10 -> V_73 ) {
F_49 ( V_320 ,
& V_10 -> V_73 [ 0 ] ) ;
for ( V_107 = 1 ; V_107 < V_10 -> V_18 ; V_107 ++ )
F_49 ( V_320 ,
& V_10 -> V_73 [ V_107 ] ) ;
}
for ( V_107 = 0 ; ! F_64 ( V_10 -> V_17 ) && V_107 < 300 ; V_107 ++ )
F_107 ( 100 ) ;
V_11 = - V_249 ;
}
return V_11 ;
}
int F_108 ( struct V_16 * V_17 , const int V_321 )
{
struct V_9 * V_10 ;
unsigned V_67 ;
int V_11 = 0 ;
unsigned long V_171 ;
F_94 ( & V_17 -> V_15 -> V_204 , V_171 ) ;
for ( V_67 = V_17 -> V_15 -> V_250 ; V_67 < V_17 -> V_15 -> V_44 ;
V_67 ++ ) {
V_10 = V_17 -> V_15 -> V_10 [ V_67 ] ;
if ( ! V_10 )
continue;
if ( V_10 -> V_73 ) {
int V_107 ;
F_49 ( V_321 , & V_10 -> V_73 [ 0 ] ) ;
for ( V_107 = 1 ; V_107 < V_10 -> V_18 ; V_107 ++ )
F_49 ( V_321 , & V_10 -> V_73 [ V_107 ] ) ;
}
V_11 = 1 ;
break;
}
F_95 ( & V_17 -> V_15 -> V_204 , V_171 ) ;
return V_11 ;
}
static int F_109 ( struct V_9 * V_10 , int V_116 ,
unsigned long V_322 )
{
int V_11 = 0 , V_107 ;
for ( V_107 = 0 ; V_107 <= V_323 ; V_107 ++ ) {
if ( ! F_18 ( V_107 , & V_322 ) )
continue;
if ( V_107 == V_320 ) {
( void ) F_110 ( V_10 ) ;
V_11 = F_106 ( V_10 ) ;
} else
F_86 ( V_107 , & V_10 -> V_73 [ V_116 ] ) ;
}
return V_11 ;
}
static T_9 F_111 ( struct V_5 * V_6 , const char T_2 * V_324 ,
T_3 V_325 , T_10 * V_326 )
{
const struct V_327 T_2 * V_328 ;
struct V_9 * V_10 ;
const void T_2 * V_329 ;
T_3 V_330 , V_331 = 0 ;
struct V_327 V_332 ;
T_9 V_11 = 0 ;
void * V_333 ;
if ( V_325 < sizeof( V_332 . type ) ) {
V_11 = - V_22 ;
goto V_23;
}
V_328 = ( const struct V_327 T_2 * ) V_324 ;
if ( F_22 ( & V_332 . type , & V_328 -> type , sizeof( V_332 . type ) ) ) {
V_11 = - V_100 ;
goto V_23;
}
V_330 = sizeof( V_332 . type ) ;
switch ( V_332 . type ) {
case V_334 :
case V_335 :
V_331 = sizeof( V_332 . V_332 . V_336 ) ;
V_333 = & V_332 . V_332 . V_336 ;
V_329 = & V_328 -> V_332 . V_336 ;
break;
case V_337 :
V_331 = sizeof( V_332 . V_332 . V_338 ) ;
V_333 = & V_332 . V_332 . V_338 ;
V_329 = & V_328 -> V_332 . V_338 ;
break;
case V_339 :
V_331 = sizeof( V_332 . V_332 . V_340 ) ;
V_333 = & V_332 . V_332 . V_340 ;
V_329 = & V_328 -> V_332 . V_340 ;
break;
case V_341 :
case V_342 :
V_331 = sizeof( V_332 . V_332 . V_343 ) ;
V_333 = & V_332 . V_332 . V_343 ;
V_329 = & V_328 -> V_332 . V_343 ;
break;
case V_344 :
V_331 = sizeof( V_332 . V_332 . V_345 ) ;
V_333 = & V_332 . V_332 . V_345 ;
V_329 = & V_328 -> V_332 . V_345 ;
break;
case V_346 :
case V_347 :
V_331 = 0 ;
V_329 = NULL ;
V_333 = NULL ;
break;
case V_348 :
V_331 = sizeof( V_332 . V_332 . V_215 ) ;
V_333 = & V_332 . V_332 . V_215 ;
V_329 = & V_328 -> V_332 . V_215 ;
break;
case V_349 :
V_331 = sizeof( V_332 . V_332 . V_350 ) ;
V_333 = & V_332 . V_332 . V_350 ;
V_329 = & V_328 -> V_332 . V_350 ;
break;
case V_351 :
V_331 = sizeof( V_332 . V_332 . V_352 ) ;
V_333 = & V_332 . V_332 . V_352 ;
V_329 = & V_328 -> V_332 . V_352 ;
break;
case V_353 :
V_331 = sizeof( V_332 . V_332 . V_354 ) ;
V_333 = & V_332 . V_332 . V_354 ;
V_329 = & V_328 -> V_332 . V_354 ;
break;
case V_355 :
V_331 = sizeof( V_332 . V_332 . V_356 ) ;
V_333 = & V_332 . V_332 . V_356 ;
V_329 = & V_328 -> V_332 . V_356 ;
break;
default:
V_11 = - V_22 ;
goto V_23;
}
if ( V_331 ) {
if ( ( V_325 - V_330 ) < V_331 ) {
V_11 = - V_22 ;
goto V_23;
}
if ( F_22 ( V_333 , V_329 , V_331 ) ) {
V_11 = - V_100 ;
goto V_23;
}
V_330 += V_331 ;
}
V_10 = F_5 ( V_6 ) ;
if ( ! V_10 && V_332 . type != V_334 ) {
V_11 = - V_22 ;
goto V_23;
}
switch ( V_332 . type ) {
case V_334 :
V_11 = F_72 ( V_6 , & V_332 . V_332 . V_336 ) ;
if ( V_11 )
goto V_23;
break;
case V_335 :
V_11 = F_81 ( V_6 , & V_332 . V_332 . V_336 ) ;
if ( V_11 )
goto V_23;
V_11 = F_4 ( V_6 , ( void T_2 * ) ( unsigned long )
V_332 . V_332 . V_336 . V_357 ,
V_332 . V_332 . V_336 . V_358 ) ;
break;
case V_337 :
V_11 = F_27 ( V_10 , F_6 ( V_6 ) , V_332 . V_332 . V_338 ) ;
break;
case V_339 :
V_11 = F_98 ( V_6 , (struct F_98 T_2 * )
( unsigned long ) V_332 . V_332 . V_340 ) ;
break;
case V_341 :
V_11 = F_10 ( V_10 , V_6 , & V_332 . V_332 . V_343 ) ;
break;
case V_342 :
V_11 = F_21 ( V_10 , F_6 ( V_6 ) , & V_332 . V_332 . V_343 ) ;
break;
case V_344 :
V_11 = F_23 ( V_10 , V_332 . V_332 . V_345 ) ;
break;
case V_346 :
( void ) F_110 ( V_10 ) ;
V_11 = F_106 ( V_10 ) ;
break;
case V_347 :
F_112 ( V_10 -> V_15 ) ;
break;
case V_348 :
V_10 -> V_215 = V_332 . V_332 . V_215 ;
break;
case V_349 :
V_10 -> V_15 -> V_359 ( V_10 -> V_15 , V_332 . V_332 . V_350 ) ;
break;
case V_351 :
V_11 = F_100 ( F_113 ( V_6 ) ,
( V_89 T_2 * ) ( unsigned long )
V_332 . V_332 . V_352 ) ;
break;
case V_353 :
V_11 = F_103 ( V_10 -> V_17 ,
F_113 ( V_6 ) ,
( V_89 T_2 * ) ( unsigned long )
V_332 . V_332 . V_354 ) ;
break;
case V_355 :
V_11 = F_109 ( V_10 , F_6 ( V_6 ) ,
V_332 . V_332 . V_356 ) ;
break;
}
if ( V_11 >= 0 )
V_11 = V_330 ;
V_23:
return V_11 ;
}
static T_9 F_114 ( struct V_360 * V_361 , const struct V_362 * V_363 ,
unsigned long V_364 , T_10 V_326 )
{
struct V_271 * V_6 = V_361 -> V_365 -> V_270 ;
struct V_9 * V_10 = F_5 ( V_361 -> V_365 ) ;
struct V_315 * V_286 = V_6 -> V_286 ;
if ( ! V_364 || ! V_286 )
return - V_22 ;
return F_115 ( V_10 , V_286 , V_363 , V_364 ) ;
}
int F_116 ( int V_366 , const char * V_367 ,
const struct V_368 * V_369 ,
struct V_370 * * V_371 , struct V_372 * * V_373 )
{
const T_11 V_287 = F_117 ( F_118 ( V_374 ) , V_366 ) ;
struct V_370 * V_370 ;
struct V_372 * V_372 = NULL ;
int V_11 ;
V_370 = F_119 () ;
if ( ! V_370 ) {
F_120 (KERN_ERR QIB_DRV_NAME
L_31 ,
minor, name) ;
V_11 = - V_25 ;
goto V_118;
}
V_370 -> V_375 = V_376 ;
V_370 -> V_377 = V_369 ;
F_121 ( & V_370 -> V_378 , V_367 ) ;
V_11 = F_122 ( V_370 , V_287 , 1 ) ;
if ( V_11 < 0 ) {
F_120 (KERN_ERR QIB_DRV_NAME
L_32 ,
minor, name, -ret) ;
goto V_379;
}
V_372 = F_123 ( V_380 , NULL , V_287 , NULL , V_367 ) ;
if ( ! F_124 ( V_372 ) )
goto V_118;
V_11 = F_125 ( V_372 ) ;
V_372 = NULL ;
F_120 (KERN_ERR QIB_DRV_NAME L_33
L_34 ,
minor, name, -ret) ;
V_379:
F_126 ( V_370 ) ;
V_370 = NULL ;
V_118:
* V_371 = V_370 ;
* V_373 = V_372 ;
return V_11 ;
}
void F_127 ( struct V_370 * * V_371 , struct V_372 * * V_373 )
{
struct V_372 * V_372 = * V_373 ;
if ( V_372 ) {
F_128 ( V_372 ) ;
* V_373 = NULL ;
}
if ( * V_371 ) {
F_126 ( * V_371 ) ;
* V_371 = NULL ;
}
}
int T_12 F_129 ( void )
{
int V_11 ;
V_11 = F_130 ( & V_374 , 0 , V_381 , V_382 ) ;
if ( V_11 < 0 ) {
F_120 (KERN_ERR QIB_DRV_NAME L_35
L_36 , -ret) ;
goto V_118;
}
V_380 = F_131 ( V_376 , L_37 ) ;
if ( F_124 ( V_380 ) ) {
V_11 = F_125 ( V_380 ) ;
F_120 (KERN_ERR QIB_DRV_NAME L_33
L_38 , -ret) ;
F_132 ( V_374 , V_381 ) ;
}
V_118:
return V_11 ;
}
void F_133 ( void )
{
if ( V_380 ) {
F_134 ( V_380 ) ;
V_380 = NULL ;
}
F_132 ( V_374 , V_381 ) ;
}
static void F_135 ( struct V_14 * V_15 )
{
if ( F_136 ( & V_383 ) == 0 )
F_127 ( & V_384 , & V_385 ) ;
F_127 ( & V_15 -> V_386 , & V_15 -> V_387 ) ;
}
static int F_137 ( struct V_14 * V_15 )
{
char V_367 [ 10 ] ;
int V_11 ;
if ( F_25 ( & V_383 ) == 1 ) {
V_11 = F_116 ( 0 , L_37 , & V_388 ,
& V_384 , & V_385 ) ;
if ( V_11 )
goto V_118;
}
snprintf ( V_367 , sizeof( V_367 ) , L_39 , V_15 -> V_46 ) ;
V_11 = F_116 ( V_15 -> V_46 + 1 , V_367 , & V_388 ,
& V_15 -> V_386 , & V_15 -> V_387 ) ;
if ( V_11 )
F_135 ( V_15 ) ;
V_118:
return V_11 ;
}
int F_138 ( struct V_14 * V_15 )
{
int V_389 , V_11 ;
V_389 = F_137 ( V_15 ) ;
V_11 = F_139 ( V_15 ) ;
if ( V_389 && ! V_11 )
V_11 = V_389 ;
return V_11 ;
}
void F_140 ( struct V_14 * V_15 )
{
F_135 ( V_15 ) ;
F_141 ( V_15 ) ;
}
