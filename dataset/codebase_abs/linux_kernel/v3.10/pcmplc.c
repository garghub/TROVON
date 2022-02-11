static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_7 = FALSE ;
F_2 ( V_2 , & V_6 -> V_8 , V_3 ,
F_3 ( V_9 + V_6 -> V_10 , V_4 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
if ( V_6 -> V_8 . V_11 )
F_5 ( V_2 , & V_6 -> V_8 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
int V_12 ;
int V_10 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
for ( V_10 = 0 , V_6 = V_2 -> V_15 ; V_10 < V_16 ; V_10 ++ , V_6 ++ ) {
V_14 = V_6 -> V_14 ;
V_14 -> V_17 = F_7 ( V_18 ) ;
V_6 -> V_10 = V_10 ;
switch ( V_2 -> V_19 . V_20 ) {
#ifdef F_8
case V_21 :
V_14 -> V_22 = ( V_10 == V_23 ) ? V_24 : V_25 ;
break ;
case V_26 :
V_14 -> V_22 = ( V_10 == V_27 ) ? V_28 :
( V_10 == V_29 ) ? V_30 : V_25 ;
break ;
case V_31 :
V_14 -> V_22 = V_25 ;
break;
#else
case V_21 :
V_14 -> V_22 = ( V_10 == V_23 ) ? V_24 : V_32 ;
V_14 -> V_33 = ( V_10 == V_23 ) ? TRUE :
FALSE ;
#ifndef F_9
V_2 -> V_15 [ V_27 ] . V_14 -> V_17 = V_18 ;
#else
V_2 -> V_15 [ V_29 ] . V_14 -> V_17 = V_18 ;
#endif
break ;
case V_26 :
V_14 -> V_22 = ( V_10 == V_29 ) ? V_30 : V_28 ;
break ;
#endif
}
V_6 -> V_34 = 0 ;
switch ( V_6 -> V_35 [ V_36 ] ) {
case 'P' :
V_14 -> V_37 = V_38 ;
break ;
case 'L' :
V_14 -> V_37 = V_39 ;
break ;
case 'D' :
V_14 -> V_37 = V_40 ;
break ;
case 'S' :
V_14 -> V_37 = V_40 ;
V_6 -> V_34 = TRUE ;
break ;
case 'U' :
V_14 -> V_37 = V_40 ;
V_6 -> V_34 = TRUE ;
break ;
case '1' :
V_14 -> V_37 = V_41 ;
break ;
case '2' :
V_14 -> V_37 = V_42 ;
break ;
case '3' :
V_14 -> V_37 = V_42 ;
break ;
case '4' :
V_14 -> V_37 = V_41 ;
break ;
case 'H' :
V_14 -> V_37 = V_43 ;
break ;
case 'I' :
V_14 -> V_37 = V_40 ;
break ;
case 'G' :
V_14 -> V_37 = V_40 ;
break ;
default:
V_14 -> V_37 = V_43 ;
break ;
}
switch ( V_14 -> V_22 ) {
case V_28 :
V_14 -> V_44 |= V_45 ;
V_14 -> V_46 [ 1 ] = V_47 ;
V_14 -> V_46 [ 2 ] =
V_47 |
V_48 |
V_49 ;
V_14 -> V_46 [ 3 ] =
V_47 |
V_48 |
V_49 |
V_50 ;
break ;
case V_30 :
V_14 -> V_44 |= V_45 ;
V_14 -> V_46 [ 1 ] = V_47 ;
V_14 -> V_46 [ 2 ] =
V_47 |
V_51 ;
V_14 -> V_46 [ 3 ] =
V_47 |
V_51 |
V_52 |
V_50 ;
break ;
case V_24 :
V_14 -> V_44 |= V_45 ;
V_14 -> V_46 [ 1 ] = V_47 ;
V_14 -> V_46 [ 2 ] =
V_47 |
V_48 |
V_51 ;
V_14 -> V_46 [ 3 ] =
V_47 |
V_48 |
V_51 ;
break ;
case V_25 :
V_14 -> V_46 [ 1 ] = V_47 ;
V_14 -> V_46 [ 2 ] =
V_47 |
V_53 |
V_54 ;
V_14 -> V_46 [ 3 ] = 0 ;
break ;
}
V_6 -> V_55 = FALSE ;
V_14 -> V_56 = V_14 -> V_17 ;
V_14 -> V_57 = 0 ;
V_14 -> V_58 = 0 ;
V_14 -> V_59 = V_60 ;
V_14 -> V_61 = V_32 ;
V_6 -> V_62 = 0 ;
V_6 -> V_63 = 0 ;
V_6 -> V_64 = 0 ;
V_6 -> V_65 = 0 ;
if ( V_10 >= V_66 )
V_6 -> V_67 = '0' + V_10 - V_66 ;
else
V_6 -> V_67 = 'A' + V_10 ;
V_6 -> V_68 = FALSE ;
memset ( ( char * ) & V_6 -> V_69 , 0 , sizeof( struct V_70 ) ) ;
F_10 ( V_6 ) ;
memset ( ( char * ) & V_6 -> V_71 , 0 , sizeof( struct V_72 ) ) ;
V_6 -> V_71 . V_73 = V_74 ;
for ( V_12 = 0 ; V_12 < V_75 ; V_12 ++ ) {
V_6 -> V_76 [ V_12 ] = 0 ;
}
}
F_11 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_16 ; V_77 ++ )
F_14 ( V_2 , V_77 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_77 )
{
int V_12 ;
#ifndef F_15
int V_78 ;
#endif
F_16 ( F_17 ( V_77 , V_79 ) , 0 ) ;
F_16 ( F_17 ( V_77 , V_79 ) , V_80 ) ;
F_16 ( F_17 ( V_77 , V_81 ) , 0 ) ;
#ifndef F_15
V_78 = F_18 ( F_17 ( V_77 , V_82 ) ) & V_83 ;
if ( V_78 != V_84 )
#endif
{
if ( V_2 -> V_15 [ V_77 ] . V_34 ) {
F_16 ( F_17 ( V_77 , V_85 ) , V_86 ) ;
#ifdef F_15
F_16 ( F_17 ( V_77 , V_87 ) , V_88 ) ;
F_16 ( F_17 ( V_77 , V_89 ) , V_90 ) ;
#endif
}
else {
F_16 ( F_17 ( V_77 , V_85 ) , V_91 ) ;
#ifdef F_15
F_16 ( F_17 ( V_77 , V_87 ) , V_92 ) ;
F_16 ( F_17 ( V_77 , V_89 ) , V_93 ) ;
#endif
}
}
for ( V_12 = 0 ; V_94 [ V_12 ] . V_95 ; V_12 ++ )
F_16 ( F_17 ( V_77 , V_94 [ V_12 ] . V_95 ) , V_94 [ V_12 ] . V_96 ) ;
( void ) F_18 ( F_17 ( V_77 , V_97 ) ) ;
F_19 ( V_2 , V_77 ) ;
F_16 ( F_17 ( V_77 , V_98 ) , V_99 ) ;
#ifndef F_8
if ( ( V_2 -> V_19 . V_20 == V_21 ) && ( V_77 == V_23 ) ) {
F_16 ( F_17 ( V_77 , V_79 ) , V_100 ) ;
}
#endif
}
static void F_20 ( struct V_1 * V_2 , int V_77 , int V_101 )
{
T_2 V_102 ;
int V_103 ;
F_13 ( V_2 ) ;
V_102 = ( T_2 ) ( F_17 ( V_77 , V_79 ) ) ;
V_103 = F_18 ( V_102 ) & ~ ( V_104 | V_105 ) ;
F_16 ( V_102 , V_103 ) ;
F_16 ( V_102 , V_103 | V_101 ) ;
}
int F_21 ( struct V_1 * V_2 , int V_6 )
{
int V_101 ;
#ifdef F_8
if ( ! F_22 ( V_2 , V_6 ) )
return V_106 ;
#endif
V_101 = F_18 ( F_17 ( V_6 , V_82 ) ) & V_107 ;
switch( V_101 ) {
case V_108 :
V_101 = V_106 ;
break ;
case V_109 :
V_101 = V_110 ;
break ;
case V_111 :
V_101 = V_112 ;
break ;
case V_113 :
case V_114 :
V_101 = V_115 ;
break ;
case V_116 :
V_101 = V_117 ;
break ;
default :
V_101 = V_118 ;
}
return V_101 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_5 * V_6 , int V_119 )
{
int V_10 = V_6 -> V_10 ;
int V_120 ;
int V_12 ;
F_13 ( V_2 ) ;
for ( V_12 = V_119 - 1 , V_120 = 0 ; V_12 >= 0 ; V_12 -- ) {
V_120 = ( V_120 << 1 ) | V_6 -> V_121 [ V_6 -> V_122 + V_12 ] ;
}
if ( F_18 ( F_17 ( V_10 , V_123 ) ) & V_124 ) {
#if 0
printf("PL_PCM_SIGNAL is set\n") ;
#endif
return 1 ;
}
F_16 ( F_17 ( V_10 , V_125 ) , V_119 - 1 ) ;
F_16 ( F_17 ( V_10 , V_126 ) , V_120 ) ;
#ifdef F_24
#if 1
#ifdef F_25
if ( V_2 -> V_127 . V_128 & 0x80 )
#else
if ( V_127 . V_128 & 0x80 )
#endif
printf ( L_1 , V_6 -> V_122 , V_6 -> V_122 + V_119 - 1 ) ;
#endif
#endif
return 0 ;
}
void F_26 ( struct V_1 * V_2 , int V_129 )
{
if ( V_2 -> V_19 . V_20 != V_26 )
return ;
if ( V_129 == V_130 ) {
F_27 ( F_17 ( V_27 , V_79 ) , V_131 , V_131 ) ;
F_27 ( F_17 ( V_27 , V_81 ) , V_132 , V_132 ) ;
}
else {
F_28 ( F_17 ( V_27 , V_79 ) , V_131 ) ;
F_28 ( F_17 ( V_27 , V_81 ) , V_132 ) ;
}
F_28 ( F_17 ( V_29 , V_79 ) , V_131 ) ;
F_28 ( F_17 ( V_29 , V_81 ) , V_132 ) ;
}
void F_29 ( struct V_1 * V_2 , const int V_10 , int V_4 )
{
int V_101 ;
int V_133 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
#ifndef F_8
if ( ( V_10 != V_23 ) && ( V_2 -> V_19 . V_20 == V_21 ) )
return ;
#endif
V_6 = & V_2 -> V_15 [ V_10 ] ;
V_14 = V_6 -> V_14 ;
V_133 = V_14 -> V_17 ;
do {
F_30 ( L_2 ,
V_6 -> V_67 ,
( V_14 -> V_17 & V_134 ) ? L_3 : L_4 ) ;
F_30 ( L_5 ,
V_135 [ V_14 -> V_17 & ~ V_134 ] ,
V_136 [ V_4 ] ) ;
V_101 = V_14 -> V_17 ;
F_31 ( V_2 , V_6 , V_4 ) ;
V_4 = 0 ;
} while ( V_101 != V_14 -> V_17 ) ;
if ( V_101 == V_137 )
V_14 -> V_56 = V_138 ;
else
V_14 -> V_56 = V_101 ;
#ifndef F_32
if ( V_14 -> V_17 != V_133 &&
( ( V_133 == V_139 ) || ( V_14 -> V_17 == V_139 ) ) ) {
F_33 ( V_2 , V_140 ,
( int ) ( V_141 + V_6 -> V_10 ) , 0 ) ;
}
#endif
#ifdef F_34
if ( V_14 -> V_17 != V_133 ) {
F_35 ( L_6 , V_133 , V_14 -> V_17 ) ;
if ( V_14 -> V_17 == V_18 ) {
F_36 ( V_2 , 1 , ( int ) V_14 -> V_142 ) ;
} else if ( V_133 == V_18 ) {
F_36 ( V_2 , 2 , ( int ) V_14 -> V_142 ) ;
} else if ( V_14 -> V_17 != V_143 &&
V_133 == V_139 ) {
F_36 ( V_2 , 3 , ( int ) V_14 -> V_142 ) ;
} else if ( V_14 -> V_17 == V_139 ) {
F_36 ( V_2 , 4 , ( int ) V_14 -> V_142 ) ;
}
}
#endif
F_37 ( V_2 , V_10 , V_101 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_5 * V_6 , int V_144 )
{
int V_12 ;
int V_10 = V_6 -> V_10 ;
struct V_72 * V_71 ;
struct V_13 * V_14 ;
#ifndef F_15
T_3 V_145 ;
#endif
V_71 = & V_6 -> V_71 ;
V_14 = V_6 -> V_14 ;
switch ( V_144 ) {
case V_146 :
if ( V_14 -> V_17 != V_147 ) {
F_38 ( V_18 ) ;
F_39 ( V_2 , ( T_1 ) V_148 , ( T_1 )
V_149 , ( T_1 ) V_150 ,
F_40 ( V_2 ) ) ;
}
return ;
case V_151 :
if ( V_14 -> V_17 != V_147 )
F_38 ( V_152 ) ;
return ;
case V_153 :
F_38 ( V_147 ) ;
F_39 ( V_2 , ( T_1 ) V_148 , ( T_1 )
V_149 , ( T_1 ) V_154 ,
F_40 ( V_2 ) ) ;
return ;
case V_155 :
F_4 ( V_2 , V_6 ) ;
F_28 ( F_17 ( V_10 , V_79 ) , V_156 ) ;
return ;
}
switch( V_14 -> V_17 ) {
case F_7 ( V_18 ) :
F_4 ( V_2 , V_6 ) ;
F_16 ( F_17 ( V_10 , V_81 ) , 0 ) ;
F_28 ( F_17 ( V_10 , V_79 ) , V_157 ) ;
F_28 ( F_17 ( V_10 , V_79 ) , V_156 ) ;
F_41 ( V_2 , V_10 ) ;
V_6 -> V_158 = FALSE ;
V_6 -> V_159 = FALSE ;
F_42 ( V_2 , V_160 , V_161 + V_10 ) ;
F_20 ( V_2 , V_10 , V_80 ) ;
V_14 -> V_162 = V_163 ;
F_43 () ;
break ;
case V_18 :
if ( V_144 == V_164 ) {
F_38 ( V_147 ) ;
break ;
}
break ;
case F_7 ( V_152 ) :
F_4 ( V_2 , V_6 ) ;
F_43 () ;
F_20 ( V_2 , V_10 , 0 ) ;
F_28 ( F_17 ( V_10 , V_79 ) , V_157 ) ;
F_28 ( F_17 ( V_10 , V_79 ) , V_156 ) ;
F_41 ( V_2 , V_10 ) ;
#if 0
if (inpw(PLC(np,PL_STATUS_B)) & PL_PCM_SIGNAL) {
plc_go_state(smc,np,PL_PCM_STOP) ;
}
#endif
F_20 ( V_2 , V_10 , V_80 ) ;
if ( V_14 -> V_165 == V_166 )
V_14 -> V_162 = V_167 ;
V_6 -> V_158 = FALSE ;
V_6 -> V_159 = FALSE ;
F_42 ( V_2 , V_160 , V_161 + V_10 ) ;
V_6 -> V_62 = FALSE ;
V_6 -> V_168 = V_169 ;
V_6 -> V_122 = 0 ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ )
F_44 ( V_2 , V_12 , V_6 ) ;
F_16 ( F_17 ( V_10 , V_98 ) , V_99 ) ;
( void ) F_18 ( F_17 ( V_10 , V_97 ) ) ;
#ifndef F_15
V_145 = F_18 ( F_17 ( V_10 , V_82 ) ) & V_83 ;
if ( V_145 != V_170 )
#endif
{
if ( F_23 ( V_2 , V_6 , 3 ) ) {
return ;
}
}
F_20 ( V_2 , V_10 , V_171 ) ;
#ifdef F_15
if ( ! ( F_18 ( F_17 ( V_10 , V_123 ) ) & V_124 ) )
#else
if ( ( ( F_18 ( F_17 ( V_10 , V_82 ) ) & V_83 ) !=
V_84 ) &&
! ( F_18 ( F_17 ( V_10 , V_123 ) ) & V_124 ) )
#endif
{
( void ) F_23 ( V_2 , V_6 , 3 ) ;
}
F_38 ( V_137 ) ;
V_71 -> V_73 = V_172 ;
V_71 -> V_173 = 3 ;
V_71 -> V_174 = 0 ;
break ;
case V_152 :
break ;
case F_7 ( V_143 ) :
F_20 ( V_2 , V_10 , V_175 ) ;
F_43 () ;
break ;
case V_143 :
break ;
case V_138 :
case V_176 :
break ;
case F_7 ( V_137 ) :
F_43 () ;
case V_137 :
if ( ( V_144 != V_177 ) && ( V_144 != V_155 ) )
break ;
switch ( V_71 -> V_73 ) {
case V_172 :
for ( V_12 = 0 ; V_12 <= 2 ; V_12 ++ )
F_45 ( V_2 , V_12 , V_6 ) ;
F_44 ( V_2 , 3 , V_6 ) ;
V_71 -> V_73 = V_178 ;
V_71 -> V_173 = 1 ;
V_71 -> V_174 = 3 ;
V_6 -> V_122 = 3 ;
if ( F_23 ( V_2 , V_6 , 1 ) ) {
return ;
}
break ;
case V_178 :
F_45 ( V_2 , 3 , V_6 ) ;
for ( V_12 = 4 ; V_12 <= 6 ; V_12 ++ )
F_44 ( V_2 , V_12 , V_6 ) ;
V_71 -> V_73 = V_179 ;
V_71 -> V_173 = 3 ;
V_71 -> V_174 = 4 ;
V_6 -> V_122 = 4 ;
if ( F_23 ( V_2 , V_6 , 3 ) ) {
return ;
}
break ;
case V_179 :
for ( V_12 = 3 ; V_12 <= 6 ; V_12 ++ )
F_45 ( V_2 , V_12 , V_6 ) ;
V_71 -> V_73 = V_180 ;
V_71 -> V_173 = 0 ;
V_71 -> V_174 = 7 ;
V_6 -> V_122 = 7 ;
F_46 ( V_2 , V_10 , ( int ) V_2 -> V_19 . V_181 ) ;
V_12 = F_18 ( F_17 ( V_10 , V_79 ) ) & ~ V_182 ;
F_16 ( F_17 ( V_10 , V_79 ) , V_12 ) ;
F_16 ( F_17 ( V_10 , V_79 ) , V_12 | V_183 ) ;
break ;
case V_180 :
F_44 ( V_2 , 7 , V_6 ) ;
V_71 -> V_73 = V_184 ;
V_71 -> V_173 = 1 ;
V_71 -> V_174 = 7 ;
V_6 -> V_122 = 7 ;
if ( F_23 ( V_2 , V_6 , 1 ) ) {
return ;
}
break ;
case V_184 :
F_45 ( V_2 , 7 , V_6 ) ;
if ( V_6 -> V_121 [ 7 ] || V_6 -> V_185 [ 7 ] ) {
F_20 ( V_2 , V_10 , V_80 ) ;
F_38 ( V_152 ) ;
break ;
}
for ( V_12 = 8 ; V_12 <= 9 ; V_12 ++ )
F_44 ( V_2 , V_12 , V_6 ) ;
V_71 -> V_73 = V_186 ;
V_71 -> V_173 = 2 ;
V_71 -> V_174 = 8 ;
V_6 -> V_122 = 8 ;
if ( F_23 ( V_2 , V_6 , 2 ) ) {
return ;
}
break ;
case V_186 :
for ( V_12 = 8 ; V_12 <= 9 ; V_12 ++ )
F_45 ( V_2 , V_12 , V_6 ) ;
V_71 -> V_73 = V_187 ;
F_38 ( V_188 ) ;
break ;
}
break ;
case F_7 ( V_188 ) :
if ( V_2 -> V_19 . V_20 == V_26 && V_10 == V_29 &&
( V_2 -> V_15 [ V_27 ] . V_168 == V_189 ||
V_2 -> V_15 [ V_29 ] . V_168 == V_189 ) ) {
F_27 ( F_17 ( V_10 , V_81 ) ,
V_132 , V_132 ) ;
F_27 ( F_17 ( V_10 , V_79 ) ,
V_131 , V_131 ) ;
}
F_27 ( F_17 ( V_10 , V_79 ) , V_157 , V_157 ) ;
F_27 ( F_17 ( V_10 , V_79 ) , V_157 , V_157 ) ;
F_43 () ;
V_144 = 0 ;
case V_188 :
switch ( V_71 -> V_73 ) {
case V_187 :
if ( ! V_6 -> V_159 ) {
V_6 -> V_159 = TRUE ;
F_42 ( V_2 , V_160 , V_161 + V_10 ) ;
}
if ( V_144 == V_190 )
F_38 ( V_139 ) ;
if ( V_144 == V_191 ) {
F_38 ( V_143 ) ;
break ;
}
break ;
}
break ;
case V_192 :
break ;
case F_7 ( V_139 ) :
F_46 ( V_2 , ( int ) V_6 -> V_10 , V_193 ) ;
V_6 -> V_194 = FALSE ;
V_14 -> V_162 = V_195 ;
F_16 ( F_17 ( V_10 , V_98 ) , V_196 ) ;
F_43 () ;
break ;
case V_139 :
if ( V_144 == V_191 ) {
F_38 ( V_143 ) ;
break ;
}
break ;
case F_7 ( V_147 ) :
F_4 ( V_2 , V_6 ) ;
F_28 ( F_17 ( V_10 , V_79 ) , V_157 ) ;
F_28 ( F_17 ( V_10 , V_79 ) , V_156 ) ;
F_28 ( F_17 ( V_10 , V_98 ) , V_197 ) ;
F_41 ( V_2 , V_10 ) ;
V_6 -> V_158 = FALSE ;
V_6 -> V_159 = FALSE ;
F_42 ( V_2 , V_160 , V_161 + V_10 ) ;
F_20 ( V_2 , V_10 , V_80 ) ;
V_14 -> V_162 = V_163 ;
F_27 ( F_17 ( V_10 , V_79 ) , V_105 , V_105 ) ;
F_47 ( V_2 , V_10 , ( int ) F_48 ( V_14 -> V_198 ) ) ;
F_16 ( F_17 ( V_10 , V_81 ) , V_199 ) ;
F_43 () ;
break ;
case V_147 :
F_49 ( 1 , L_7 , V_6 -> V_67 , 0 ) ;
if ( V_144 == V_200 ) {
F_38 ( V_18 ) ;
break ;
}
break ;
default:
F_50 ( V_2 , V_201 , V_202 ) ;
break ;
}
}
static void F_47 ( struct V_1 * V_2 , int V_6 , int V_203 )
{
int V_204 ;
F_13 ( V_2 ) ;
V_204 = ( F_18 ( F_17 ( V_6 , V_79 ) ) & ~ V_205 ) |
V_80 | V_105 ;
switch( V_203 ) {
case V_106 :
V_204 |= V_206 ;
break ;
case V_110 :
V_204 |= V_207 ;
break ;
case V_112 :
V_204 |= V_208 ;
break ;
default :
case V_115 :
V_204 |= V_209 ;
break ;
case V_117 :
V_204 |= V_210 ;
break ;
}
F_16 ( F_17 ( V_6 , V_79 ) , V_204 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_70 * V_69 = & V_6 -> V_69 ;
V_6 -> V_14 -> V_211 = 15 ;
V_69 -> V_212 = 15 * 100 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_213 ;
T_1 V_214 ;
struct V_70 * V_69 = & V_6 -> V_69 ;
struct V_13 * V_14 ;
int V_215 ;
V_14 = V_6 -> V_14 ;
if ( ! V_69 -> V_216 )
return ;
V_214 = F_18 ( F_17 ( ( ( int ) V_6 -> V_10 ) , V_217 ) ) ;
V_69 -> V_218 += V_214 ;
V_14 -> V_219 += V_214 ;
V_214 = V_69 -> V_218 ;
if ( ! V_214 ) V_213 = 15 ;
else if ( V_214 <= 9 ) V_213 = 9 ;
else if ( V_214 <= 99 ) V_213 = 8 ;
else if ( V_214 <= 999 ) V_213 = 7 ;
else if ( V_214 <= 9999 ) V_213 = 6 ;
else if ( V_214 <= 99999 ) V_213 = 5 ;
else if ( V_214 <= 999999 ) V_213 = 4 ;
else if ( V_214 <= 9999999 ) V_213 = 3 ;
else if ( V_214 <= 99999999 ) V_213 = 2 ;
else if ( V_214 <= 999999999 ) V_213 = 1 ;
else V_213 = 0 ;
V_213 *= 100 ;
V_69 -> V_212 = V_69 -> V_212 * 7 + V_213 * 3 ;
V_69 -> V_212 /= 10 ;
V_14 -> V_211 = V_69 -> V_212 / 100 ;
if ( V_14 -> V_211 < 4 ) {
V_14 -> V_211 = 4 ;
}
if ( V_69 -> V_218 ) {
F_49 ( 1 , L_8 , V_6 -> V_10 == V_29 ? 'B' : 'A' , 0 ) ;
F_49 ( 1 , L_9 , V_69 -> V_218 , 0 ) ;
F_49 ( 1 , L_10 , V_14 -> V_219 , 0 ) ;
F_49 ( 1 , L_11 , V_213 / 100 , 0 ) ;
F_49 ( 1 , L_12 , V_69 -> V_212 , 0 ) ;
F_49 ( 1 , L_13 ,
V_14 -> V_211 , 0 ) ;
}
V_69 -> V_218 = 0L ;
#ifndef F_32
V_215 = ( V_14 -> V_211 <= V_14 -> V_220 ) ?
TRUE : FALSE ;
#ifdef F_52
F_53 ( V_2 , V_6 , V_215 ) ;
#endif
if ( V_215 != V_14 -> V_221 ) {
F_33 ( V_2 , V_222 ,
( int ) ( V_141 + V_6 -> V_10 ) , V_215 ) ;
}
#endif
if ( V_14 -> V_211 <= V_14 -> V_223 ) {
V_6 -> V_55 = TRUE ;
V_14 -> V_224 ++ ;
V_69 -> V_212 += 2 * 100 ;
#ifdef F_8
F_49 ( 1 , L_14 ,
V_6 -> V_10 , V_14 -> V_223 ) ;
#endif
#ifdef F_52
F_54 ( V_2 , V_6 -> V_10 ) ;
#else
F_42 ( V_2 , ( int ) ( V_9 + V_6 -> V_10 ) , V_151 ) ;
#endif
}
}
void F_55 ( struct V_1 * V_2 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_16 ; V_10 ++ )
F_51 ( V_2 , & V_2 -> V_15 [ V_10 ] ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_70 * V_69 = & V_6 -> V_69 ;
struct V_13 * V_14 ;
int V_214 ;
V_14 = V_6 -> V_14 ;
V_6 -> V_55 = FALSE ;
V_214 = F_18 ( F_17 ( ( ( int ) V_6 -> V_10 ) , V_217 ) ) ;
V_69 -> V_218 += V_214 ;
V_14 -> V_219 += V_214 ;
if ( V_69 -> V_218 ) {
switch( V_6 -> V_225 ) {
case V_226 :
if ( V_69 -> V_218 >= V_2 -> V_19 . V_181 )
V_6 -> V_55 = TRUE ;
break ;
case V_227 :
if ( V_69 -> V_218 >= V_2 -> V_19 . V_228 )
V_6 -> V_55 = TRUE ;
break ;
case V_229 :
if ( V_69 -> V_218 >= V_2 -> V_19 . V_230 )
V_6 -> V_55 = TRUE ;
break ;
case V_231 :
if ( V_69 -> V_218 >= V_2 -> V_19 . V_232 )
V_6 -> V_55 = TRUE ;
break ;
}
F_49 ( 1 , L_15 , V_69 -> V_218 , 0 ) ;
}
if ( V_6 -> V_55 ) {
V_14 -> V_57 ++ ;
V_14 -> V_224 ++ ;
}
else
V_14 -> V_57 = 0 ;
}
static void F_46 ( struct V_1 * V_2 , int V_10 , int V_233 )
{
struct V_70 * V_69 = & V_2 -> V_15 [ V_10 ] . V_69 ;
V_69 -> V_216 = 1 ;
V_69 -> V_218 = 0L ;
F_16 ( F_17 ( V_10 , V_234 ) , V_233 ) ;
( void ) F_18 ( F_17 ( V_10 , V_217 ) ) ;
F_27 ( F_17 ( V_10 , V_98 ) , V_197 , V_197 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_10 )
{
struct V_70 * V_69 = & V_2 -> V_15 [ V_10 ] . V_69 ;
V_69 -> V_216 = 0 ;
F_28 ( F_17 ( V_10 , V_98 ) , V_197 ) ;
}
void F_57 ( struct V_1 * V_2 , int V_6 , int V_235 )
{
F_13 ( V_2 ) ;
V_6 = V_6 ; V_235 = V_235 ;
}
static void F_45 ( struct V_1 * V_2 , int V_236 , struct V_5 * V_6 )
{
struct V_13 * V_14 ;
V_14 = V_6 -> V_14 ;
F_49 ( 1 , L_16 , V_236 , V_6 -> V_185 [ V_236 ] ) ;
V_236 ++ ;
switch( V_236 ) {
case 0 :
case 1 :
case 2 :
break ;
case 3 :
if ( V_6 -> V_185 [ 1 ] == 0 && V_6 -> V_185 [ 2 ] == 0 )
V_14 -> V_61 = V_28 ;
else if ( V_6 -> V_185 [ 1 ] == 0 && V_6 -> V_185 [ 2 ] == 1 )
V_14 -> V_61 = V_30 ;
else if ( V_6 -> V_185 [ 1 ] == 1 && V_6 -> V_185 [ 2 ] == 0 )
V_14 -> V_61 = V_24 ;
else if ( V_6 -> V_185 [ 1 ] == 1 && V_6 -> V_185 [ 2 ] == 1 )
V_14 -> V_61 = V_25 ;
break ;
case 4 :
if ( V_14 -> V_22 == V_25 &&
V_14 -> V_61 == V_25 ) {
F_49 ( 1 , L_17 ,
V_6 -> V_67 , 0 ) ;
V_14 -> V_165 = V_237 ;
F_58 ( V_2 , V_238 ) ;
}
else if ( V_6 -> V_121 [ 3 ] || V_6 -> V_185 [ 3 ] ) {
V_14 -> V_165 = V_166 ;
if ( V_14 -> V_22 == V_25 ||
V_14 -> V_61 == V_25 )
V_6 -> V_168 = V_189 ;
else
V_6 -> V_168 = V_239 ;
F_59 ( V_2 ) ;
if ( V_6 -> V_68 ) {
V_14 -> V_165 = V_240 ;
}
}
else {
V_14 -> V_165 = V_241 ;
F_58 ( V_2 , V_238 ) ;
F_49 ( 1 , L_18 ,
V_6 -> V_67 , 0 ) ;
}
V_6 -> V_242 = ( ( V_14 -> V_22 != V_24 ) &&
( V_14 -> V_22 != V_25 ) &&
( V_14 -> V_61 ==
V_14 -> V_22 ) ) ;
if ( V_6 -> V_242 ) {
F_49 ( 1 , L_19 ,
V_6 -> V_67 , 0 ) ;
}
break ;
case 5 :
break ;
case 6 :
if ( V_6 -> V_121 [ 4 ] || V_6 -> V_185 [ 4 ] ) {
if ( ( V_6 -> V_121 [ 4 ] && V_6 -> V_121 [ 5 ] ) ||
( V_6 -> V_185 [ 4 ] && V_6 -> V_185 [ 5 ] ) )
V_6 -> V_225 = V_231 ;
else
V_6 -> V_225 = V_229 ;
}
else if ( V_6 -> V_121 [ 5 ] || V_6 -> V_185 [ 5 ] )
V_6 -> V_225 = V_227 ;
else
V_6 -> V_225 = V_226 ;
switch ( V_6 -> V_225 ) {
case V_226 :
F_16 ( F_17 ( ( int ) V_6 -> V_10 , V_243 ) , V_244 ) ;
V_6 -> V_76 [ 7 ] = V_2 -> V_19 . V_245 ;
break ;
case V_227 :
F_16 ( F_17 ( ( int ) V_6 -> V_10 , V_243 ) , V_246 ) ;
V_6 -> V_76 [ 7 ] = V_2 -> V_19 . V_247 ;
break ;
case V_229 :
F_27 ( F_17 ( ( int ) V_6 -> V_10 , V_79 ) , V_156 , V_156 ) ;
V_6 -> V_76 [ 7 ] = V_2 -> V_19 . V_248 ;
break ;
case V_231 :
F_27 ( F_17 ( ( int ) V_6 -> V_10 , V_79 ) , V_156 , V_156 ) ;
V_6 -> V_76 [ 7 ] = V_2 -> V_19 . V_249 ;
break ;
}
if ( V_6 -> V_76 [ 7 ] > V_2 -> V_19 . V_247 ) {
F_1 ( V_2 , V_6 -> V_76 [ 7 ] , V_155 , V_6 ) ;
}
F_49 ( 1 , L_20 , V_6 -> V_76 [ 7 ] , 0 ) ;
V_6 -> V_76 [ 9 ] = V_2 -> V_19 . V_250 ;
break ;
case 7 :
if ( V_6 -> V_121 [ 6 ] ) {
V_6 -> V_158 = TRUE ;
}
V_6 -> V_65 = TRUE ;
break ;
case 8 :
if ( V_6 -> V_121 [ 7 ] || V_6 -> V_185 [ 7 ] ) {
F_49 ( 1 , L_21 ,
V_6 -> V_67 , V_6 -> V_121 [ 7 ] ? L_22 : L_23 ) ;
F_42 ( V_2 , ( int ) ( V_9 + V_6 -> V_10 ) , V_151 ) ;
}
break ;
case 9 :
if ( V_6 -> V_121 [ 8 ] || V_6 -> V_185 [ 8 ] ) {
if ( V_6 -> V_121 [ 8 ] )
V_6 -> V_158 = TRUE ;
V_6 -> V_65 = TRUE ;
}
break ;
case 10 :
if ( V_6 -> V_185 [ 9 ] ) {
;
V_14 -> V_251 . V_252 = TRUE ;
}
else {
;
V_14 -> V_251 . V_252 = FALSE ;
}
break ;
}
}
static void F_44 ( struct V_1 * V_2 , const int V_236 , struct V_5 * V_6 )
{
int V_10 = V_6 -> V_10 ;
struct V_13 * V_14 ;
V_14 = V_6 -> V_14 ;
switch( V_236 ) {
case 0 :
V_6 -> V_121 [ 0 ] = 0 ;
break ;
case 1 :
if ( V_14 -> V_22 == V_24 || V_14 -> V_22 == V_25 )
V_6 -> V_121 [ 1 ] = 1 ;
else
V_6 -> V_121 [ 1 ] = 0 ;
break ;
case 2 :
if ( V_14 -> V_22 == V_30 || V_14 -> V_22 == V_25 )
V_6 -> V_121 [ 2 ] = 1 ;
else
V_6 -> V_121 [ 2 ] = 0 ;
break ;
case 3 :
{
int type , V_253 ;
int V_254 ;
type = V_14 -> V_22 ;
V_253 = V_14 -> V_61 ;
V_254 = V_2 -> V_14 . V_255 ;
V_6 -> V_121 [ 3 ] = 1 ;
switch ( type ) {
case V_28 :
if (
( ( V_254 & V_256 ) && V_253 == V_28 ) ||
( ( V_254 & V_257 ) && V_253 == V_30 ) ||
( ( V_254 & V_258 ) && V_253 == V_24 ) ||
( ( V_254 & V_259 ) && V_253 == V_25 ) )
V_6 -> V_121 [ 3 ] = 0 ;
break ;
case V_30 :
if (
( ( V_254 & V_260 ) && V_253 == V_28 ) ||
( ( V_254 & V_261 ) && V_253 == V_30 ) ||
( ( V_254 & V_262 ) && V_253 == V_24 ) ||
( ( V_254 & V_263 ) && V_253 == V_25 ) )
V_6 -> V_121 [ 3 ] = 0 ;
break ;
case V_24 :
if (
( ( V_254 & V_264 ) && V_253 == V_28 ) ||
( ( V_254 & V_265 ) && V_253 == V_30 ) ||
( ( V_254 & V_266 ) && V_253 == V_24 ) ||
( ( V_254 & V_267 ) && V_253 == V_25 ) )
V_6 -> V_121 [ 3 ] = 0 ;
break ;
case V_25 :
if ( V_253 == V_25 ||
( ( V_254 & V_268 ) && V_253 == V_28 ) ||
( ( V_254 & V_269 ) && V_253 == V_30 ) ||
( ( V_254 & V_270 ) && V_253 == V_24 ) ||
( ( V_254 & V_271 ) && V_253 == V_25 ) )
V_6 -> V_121 [ 3 ] = 0 ;
break ;
}
#ifndef F_32
if ( ( type == V_28 && V_253 == V_28 ) ||
( type == V_28 && V_253 == V_24 ) ||
( type == V_30 && V_253 == V_30 ) ||
( type == V_30 && V_253 == V_24 ) ||
( type == V_24 && V_253 == V_28 ) ||
( type == V_24 && V_253 == V_30 ) ) {
F_33 ( V_2 , V_272 ,
( int ) ( V_141 + V_6 -> V_10 ) , 0 ) ;
}
#endif
}
break ;
case 4 :
if ( V_14 -> V_165 == V_166 ) {
if ( V_6 -> V_55 ) {
V_6 -> V_121 [ 4 ] = 1 ;
V_6 -> V_121 [ 5 ] = 0 ;
}
else {
V_6 -> V_121 [ 4 ] = 0 ;
if ( V_14 -> V_57 > 0 )
V_6 -> V_121 [ 5 ] = 1 ;
else
V_6 -> V_121 [ 5 ] = 0 ;
if ( V_6 -> V_68 )
V_6 -> V_121 [ 5 ] = 1 ;
}
V_14 -> V_162 = V_167 ;
}
else {
V_14 -> V_162 = V_273 ;
V_6 -> V_121 [ 4 ] = 1 ;
V_6 -> V_121 [ 5 ] = 1 ;
}
break ;
case 5 :
break ;
case 6 :
V_6 -> V_121 [ 6 ] = 0 ;
break ;
case 7 :
V_6 -> V_158 = FALSE ;
F_56 ( V_2 , V_6 ) ;
if ( V_6 -> V_55 ) {
F_49 ( 1 , L_24 ,
V_6 -> V_67 , 0 ) ;
V_6 -> V_121 [ 7 ] = 1 ;
}
else
V_6 -> V_121 [ 7 ] = 0 ;
break ;
case 8 :
V_6 -> V_121 [ 8 ] = 0 ;
break ;
case 9 :
V_6 -> V_158 = 0 ;
if ( ( V_14 -> V_165 != V_166 ) ||
( ( V_2 -> V_19 . V_20 == V_26 ) && ( V_6 -> V_68 ) ) ) {
F_42 ( V_2 , V_9 + V_10 , V_151 ) ;
break ;
}
V_6 -> V_121 [ 9 ] = FALSE ;
switch ( V_2 -> V_19 . V_20 ) {
case V_26 :
if ( V_6 -> V_168 == V_189 ) {
if ( ( V_10 == V_29 ) || ( ( V_10 == V_27 ) &&
( V_2 -> V_15 [ V_29 ] . V_14 -> V_162 !=
V_195 ) ) )
V_6 -> V_121 [ 9 ] = TRUE ;
}
else {
if ( V_10 == V_29 )
V_6 -> V_121 [ 9 ] = TRUE ;
}
break ;
case V_21 :
if ( V_10 == V_23 )
V_6 -> V_121 [ 9 ] = TRUE ;
break ;
#ifdef F_8
case V_31 :
if ( V_10 == V_29 )
V_6 -> V_121 [ 9 ] = TRUE ;
break ;
#endif
}
V_14 -> V_251 . V_274 = V_6 -> V_121 [ 9 ] ;
break ;
}
F_49 ( 1 , L_25 , V_236 , V_6 -> V_121 [ V_236 ] ) ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_275 = 0 ;
if ( V_2 -> V_19 . V_20 != V_26 )
return 0 ;
if ( V_2 -> V_15 [ V_27 ] . V_242 && ( V_2 -> V_15 [ V_27 ] . V_14 -> V_17 == V_139 ) )
V_275 |= 1 ;
if ( V_2 -> V_15 [ V_29 ] . V_242 && ( V_2 -> V_15 [ V_29 ] . V_14 -> V_17 == V_139 ) )
V_275 |= 2 ;
return V_275 ;
}
void F_61 ( struct V_1 * V_2 , int V_10 , int * type , int * V_101 ,
int * V_276 , int * V_277 )
{
struct V_5 * V_6 = & V_2 -> V_15 [ V_10 ] ;
struct V_13 * V_14 ;
V_14 = V_6 -> V_14 ;
* V_277 = 0 ;
* type = V_14 -> V_22 ;
* V_101 = V_14 -> V_162 ;
* V_276 = V_14 -> V_61 ;
switch( V_14 -> V_17 ) {
case V_139 :
* V_277 = V_14 -> V_251 . V_252 ;
break ;
}
}
int F_62 ( struct V_1 * V_2 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_16 ; V_120 ++ ) {
if ( V_2 -> V_15 [ V_120 ] . V_14 -> V_17 == V_139 &&
V_2 -> V_15 [ V_120 ] . V_14 -> V_61 == V_25 )
return 0 ;
}
return 1 ;
}
void F_63 ( struct V_1 * V_2 , int V_10 , unsigned int V_144 )
{
struct V_5 * V_6 = & V_2 -> V_15 [ V_10 ] ;
struct V_72 * V_71 = & V_6 -> V_71 ;
int V_120 ;
#ifdef F_9
int V_278 ;
#endif
int V_12 ;
if ( V_10 >= V_2 -> V_19 . V_279 ) {
V_71 -> V_280 ++ ;
return ;
}
if ( V_144 & V_281 ) {
if ( ! V_71 -> V_282 && V_6 -> V_14 -> V_17 == V_139 ) {
V_6 -> V_14 -> V_283 ++ ;
}
V_71 -> V_284 ++ ;
if ( V_71 -> V_282 <= 1000 ) {
V_71 -> V_282 ++ ;
}
#ifdef F_9
if ( V_71 -> V_282 == 1000 &&
( ( F_18 ( F_17 ( V_10 , V_82 ) ) & V_83 ) ==
V_170 ) ) {
V_278 = ( V_99 & ~ V_281 ) ;
F_16 ( F_17 ( V_10 , V_98 ) , V_278 ) ;
F_42 ( V_2 , V_285 , V_286 ) ;
F_64 ( V_2 , V_287 , V_288 ) ;
F_65 ( V_2 ) ;
}
#endif
} else {
V_71 -> V_282 = 0 ;
}
if ( V_144 & V_289 ) {
V_71 -> V_290 ++ ;
}
if ( V_144 & V_291 ) {
V_71 -> V_292 ++ ;
}
if ( V_144 & V_293 ) {
V_71 -> V_294 ++ ;
}
if ( V_144 & V_197 ) {
int V_295 ;
V_295 = F_18 ( F_17 ( V_10 , V_234 ) ) ;
V_12 = F_18 ( F_17 ( V_10 , V_217 ) ) ;
if ( V_12 < V_295 ) {
V_12 += 256 ;
}
if ( V_6 -> V_69 . V_216 ) {
V_6 -> V_69 . V_218 += V_12 ;
V_6 -> V_14 -> V_219 += V_12 ;
}
}
if ( V_144 & V_296 ) {
if ( V_71 -> V_73 == V_180 ) {
;
}
V_71 -> V_297 ++ ;
}
if ( V_144 & V_298 ) {
switch ( F_18 ( F_17 ( V_10 , V_79 ) ) & V_299 ) {
case V_300 : V_6 -> V_301 = V_115 ; break ;
case V_302 : V_6 -> V_301 = V_112 ; break ;
case V_303 : V_6 -> V_301 = V_110 ; break ;
case V_304 : V_6 -> V_301 = V_106 ; break ;
}
}
if ( V_144 & V_305 ) {
int V_306 ;
V_306 = F_18 ( F_17 ( V_10 , V_123 ) ) & V_307 ;
switch ( V_306 ) {
case V_308 : V_71 -> V_309 ++ ; break ;
case V_310 : V_71 -> V_311 ++ ; break ;
case V_312 : V_71 -> V_313 ++ ; break ;
case V_314 : V_71 -> V_315 ++ ; break ;
case V_316 : V_71 -> V_317 ++ ; break ;
case V_318 : V_71 -> V_319 ++ ; break ;
}
F_49 ( 1 , L_26 , V_10 , V_2 -> V_320 . V_321 ) ;
if ( V_2 -> V_320 . V_321 == FALSE ) {
F_49 ( 1 , L_27 , V_10 , V_306 ) ;
F_42 ( V_2 , V_9 + V_10 , V_151 ) ;
}
else {
F_49 ( 1 , L_28 , V_10 , V_306 ) ;
}
return ;
}
if ( V_144 & V_322 ) {
F_42 ( V_2 , V_9 + V_10 , V_177 ) ;
V_120 = F_18 ( F_17 ( V_10 , V_323 ) ) ;
for ( V_12 = 0 ; V_12 < V_71 -> V_173 ; V_12 ++ ) {
V_6 -> V_185 [ V_71 -> V_174 + V_12 ] = V_120 & 1 ;
V_120 >>= 1 ;
}
}
else if ( V_144 & V_324 ) {
F_42 ( V_2 , V_9 + V_10 , V_190 ) ;
}
if ( V_144 & V_325 ) {
if ( ! V_6 -> V_194 ) {
F_49 ( 1 , L_29 ,
V_10 , V_2 -> V_14 . V_326 ) ;
V_6 -> V_194 = TRUE ;
V_2 -> V_320 . V_327 |= F_66 ( F_67 ( V_10 ) ) ;
F_42 ( V_2 , V_285 , V_328 ) ;
}
}
if ( ( V_144 & V_329 ) && ( V_6 -> V_14 -> V_17 == V_143 ) ) {
if ( V_2 -> V_320 . V_330 == V_331 ) {
F_49 ( 1 , L_30 , F_68 ( V_2 , V_10 ) ,
V_6 -> V_14 -> V_17 ) ;
V_2 -> V_320 . V_330 = V_332 ;
F_42 ( V_2 , V_285 , V_333 ) ;
}
}
if ( V_144 & V_334 ) {
if ( V_6 -> V_14 -> V_17 == V_139 ) {
if ( ! V_6 -> V_194 ) {
F_49 ( 1 , L_31 , V_6 -> V_67 , L_32 ) ;
F_42 ( V_2 , V_9 + V_10 , V_151 ) ;
return ;
}
}
}
#if 0
if (cmd & PL_NP_ERR) {
plc->np_err++ ;
}
if (cmd & PL_PARITY_ERR) {
plc->parity_err++ ;
}
if (cmd & PL_LSDO) {
;
}
#endif
}
void F_69 ( struct V_1 * V_2 , struct V_335 * V_101 )
{
struct V_5 * V_6 ;
struct V_336 * V_337 ;
int V_12 ;
int V_338 ;
short V_339 ;
short V_340 ;
struct V_13 * V_14 ;
for ( V_12 = 0 , V_6 = V_2 -> V_15 , V_337 = V_101 -> V_336 ; V_12 < V_16 ;
V_12 ++ , V_6 ++ , V_337 ++ ) {
V_14 = V_6 -> V_14 ;
V_337 -> V_341 = ( V_342 ) V_14 -> V_22 ;
V_337 -> V_336 = ( V_342 ) V_14 -> V_17 ;
V_337 -> V_343 = V_6 -> V_168 ;
V_337 -> V_344 = ( V_342 ) V_14 -> V_61 ;
V_337 -> V_345 = V_14 -> V_58 ;
V_337 -> V_346 = V_6 -> V_62 ;
V_337 -> V_347 = ( V_342 ) V_14 -> V_57 ;
V_337 -> V_348 = F_70 ( F_21 ( V_2 , V_12 ) ) ;
for ( V_338 = 0 , V_339 = V_340 = 0 ; V_338 < V_75 ; V_338 ++ ) {
V_339 <<= 1 ;
V_340 <<= 1 ;
if ( V_6 -> V_185 [ V_75 - 1 - V_338 ] )
V_339 |= 1 ;
if ( V_6 -> V_121 [ V_75 - 1 - V_338 ] )
V_340 |= 1 ;
}
V_337 -> V_349 = V_339 ;
V_337 -> V_350 = V_340 ;
}
}
int F_71 ( struct V_1 * V_2 , int V_10 )
{
int V_337 ;
F_13 ( V_2 ) ;
switch ( F_18 ( F_17 ( V_10 , V_123 ) ) & V_351 ) {
case V_352 : V_337 = V_146 ; break ;
case V_353 : V_337 = V_151 ; break ;
case V_354 : V_337 = V_191 ; break ;
case V_355 : V_337 = V_177 ; break ;
case V_356 : V_337 = V_177 ; break ;
case V_357 : V_337 = V_177 ; break ;
case V_358 : V_337 = V_190 ; break ;
case V_359 : V_337 = V_190 ; break ;
case V_360 : V_337 = V_200 ; break ;
case V_361 : V_337 = V_164 ; break ;
default : V_337 = V_153 ; break ;
}
return V_337 ;
}
char * F_72 ( struct V_1 * V_2 , int V_10 )
{
char * V_203 = L_4 ;
F_13 ( V_2 ) ;
switch ( F_18 ( F_17 ( V_10 , V_82 ) ) & V_107 ) {
case V_362 : V_203 = L_33 ; break ;
case V_116 : V_203 = L_34 ; break ;
case V_363 : V_203 = L_35 ; break ;
case V_113 : V_203 = L_36 ; break ;
case V_108 : V_203 = L_37 ; break ;
case V_109 : V_203 = L_38 ; break ;
case V_111 : V_203 = L_39 ; break ;
case V_114 : V_203 = L_40 ; break ;
#ifdef F_73
default: V_203 = L_41 ; break ;
#endif
}
return V_203 ;
}
char * F_68 ( struct V_1 * V_2 , int V_10 )
{
char * V_337 ;
F_13 ( V_2 ) ;
switch ( F_18 ( F_17 ( V_10 , V_123 ) ) & V_351 ) {
case V_352 : V_337 = L_42 ; break ;
case V_353 : V_337 = L_43 ; break ;
case V_354 : V_337 = L_44 ; break ;
case V_355 : V_337 = L_45 ; break ;
case V_356 : V_337 = L_46 ; break ;
case V_357 : V_337 = L_47 ; break ;
case V_358 : V_337 = L_48 ; break ;
case V_359 : V_337 = L_49 ; break ;
case V_360 : V_337 = L_34 ; break ;
case V_361 : V_337 = L_50 ; break ;
default : V_337 = L_51 ; break ;
}
return V_337 ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_72 * V_71 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_16 ; V_10 ++ ) {
V_71 = & V_2 -> V_15 [ V_10 ] . V_71 ;
printf ( L_52 , V_10 ) ;
printf ( L_53 ,
V_71 -> V_280 , V_71 -> V_309 ) ;
printf ( L_54 ,
V_71 -> V_364 , V_71 -> V_311 , F_72 ( V_2 , V_10 ) ) ;
printf ( L_55 ,
V_71 -> V_284 , V_71 -> V_313 ) ;
printf ( L_56 ,
V_71 -> V_290 , V_71 -> V_315 , F_68 ( V_2 , V_10 ) ) ;
printf ( L_57 ,
V_71 -> V_292 , V_71 -> V_317 ) ;
printf ( L_58 ,
V_71 -> V_294 , V_71 -> V_319 ) ;
printf ( L_59 , V_71 -> V_365 ) ;
printf ( L_60 , V_71 -> V_297 ) ;
printf ( L_61 , V_2 -> V_15 [ V_10 ] . V_69 . V_218 ) ;
}
}
void F_75 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
char * F_76 () ;
printf ( L_62 ) ;
printf ( L_63 ) ;
for ( V_12 = 0 , V_6 = V_2 -> V_15 ; V_12 < V_16 ; V_12 ++ , V_6 ++ ) {
if ( ! F_22 ( V_2 , V_12 ) )
continue ;
V_14 = V_6 -> V_14 ;
printf ( L_64 ,
F_76 ( V_2 , F_67 ( V_12 ) ) ,
V_14 -> V_219 ,
V_14 -> V_211 ) ;
}
}
