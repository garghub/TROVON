static void F_1 ( const char * V_1 , int line , char * type , char * V_2 , ... )
{
T_1 args ;
char V_3 [ V_4 ] ;
va_start ( args , V_2 ) ;
vsnprintf ( V_3 , sizeof( V_3 ) , V_2 , args ) ;
va_end ( args ) ;
#ifndef F_2
F_3 ( L_1 , type , V_3 ) ;
#else
F_3 ( L_2 , type , V_1 , line , V_3 ) ;
#endif
}
static void F_4 ( const char * V_1 , int line , int V_5 , char * V_2 , ... )
{
T_1 args ;
char V_3 [ V_4 ] ;
va_start ( args , V_2 ) ;
vsnprintf ( V_3 , sizeof( V_3 ) , V_2 , args ) ;
va_end ( args ) ;
if ( V_5 & V_6 ) {
F_3 ( L_3 , V_5 , V_1 , line , V_3 ) ;
}
}
static void F_5 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
int V_13 = V_9 -> V_14 ;
int V_15 = FALSE ;
if ( V_16 == 0 ) {
}
V_9 -> V_17 [ V_13 ] = F_6 ( V_15 , V_8 -> V_10 -> V_18 ) ; V_13 ++ ;
V_9 -> V_14 = V_13 ;
}
static void F_7 ( struct V_7 * V_8 ,
unsigned char V_19 ,
unsigned char V_20 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
int V_13 = V_9 -> V_14 ;
V_9 -> V_17 [ V_13 ] = V_21 ; V_13 ++ ;
V_9 -> V_17 [ V_13 ] = V_22 ; V_13 ++ ;
V_9 -> V_17 [ V_13 ] = V_23 ; V_13 ++ ;
V_9 -> V_17 [ V_13 ] = V_19 ; V_13 ++ ;
V_9 -> V_17 [ V_13 ] = V_20 ; V_13 ++ ;
V_9 -> V_14 = V_13 ;
}
static void F_8 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
int V_13 = V_9 -> V_14 ;
if ( V_13 != 0 ) {
F_9 ( V_24 ,
L_4 ) ;
return;
}
V_9 -> V_17 [ V_13 ] = V_25 ; V_13 ++ ;
V_9 -> V_14 = V_13 ;
}
static void F_10 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
int V_13 = V_9 -> V_14 ;
V_9 -> V_17 [ V_13 ] = V_26 ; V_13 ++ ;
V_9 -> V_14 = V_13 ;
}
static int F_11 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
unsigned int V_29 = V_8 -> V_10 -> V_11 -> V_30 ;
unsigned char V_31 = F_12 ( V_8 ) ;
T_3 * V_32 = V_9 -> V_33 ;
unsigned char V_34 ;
int V_35 , V_36 ;
unsigned int V_37 ;
T_4 V_38 ;
F_13 ( V_39 , L_5 ) ;
V_34 = F_14 ( V_27 , V_40 ) ;
if ( V_34 != V_41 ) {
F_9 ( V_24 , L_6 ) ;
F_15 ( V_34 & V_42 ) ;
V_8 -> V_43 = V_44 << 16 ;
return FALSE ;
}
if ( V_9 -> V_14 == 0 ) {
F_9 ( V_45 , L_7 ) ;
V_8 -> V_43 = V_46 << 16 ;
return FALSE ;
} else if ( V_9 -> V_14 > 0 && V_9 -> V_14 <= 3 ) {
V_37 = 0 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_14 ; V_35 ++ ) {
V_37 >>= 8 ;
V_37 |= ( ( unsigned int ) ( V_9 -> V_17 [ V_35 ] ) << 24 ) ;
}
V_37 |= V_47 ;
V_37 |= ( unsigned int ) V_9 -> V_14 ;
} else {
V_37 = 0 ;
}
memset ( V_32 , 0 , sizeof( T_3 ) ) ;
for ( V_35 = 0 ; V_35 < V_8 -> V_48 ; V_35 ++ ) {
V_32 -> V_49 [ 4 * V_35 ] = V_8 -> V_50 [ V_35 ] ;
}
V_32 -> V_37 = F_16 ( V_37 ) ;
V_32 -> V_51 = V_9 -> V_52 -> V_51 ;
V_32 -> V_53 = V_9 -> V_52 -> V_53 ;
V_32 -> V_54 = F_17 ( V_29 ) | F_17 ( V_31 ) ;
V_32 -> V_55 = V_9 -> V_52 -> V_55 ;
V_32 -> V_56 = F_18 ( V_57 |
V_58 |
V_59 |
V_60 |
V_61 ) ;
V_38 = 0 ;
switch ( V_9 -> V_62 ) {
case V_63 :
V_38 |= V_64 ;
break;
case V_65 :
V_38 |= V_66 ;
break;
case V_67 :
V_38 |= V_68 ;
break;
default:
F_9 ( V_45 , L_8 ) ;
break;
}
V_38 |= ( V_69 | V_70 ) ;
V_32 -> V_71 = F_18 ( V_38 ) ;
V_32 -> V_72 = F_16 ( V_9 -> V_73 -> V_74 ) ;
F_19 ( V_27 , V_75 , V_9 -> V_76 ) ;
F_20 ( V_27 , V_77 , V_57 |
V_78 ) ;
V_36 = F_21 ( V_8 , V_27 ) ;
return V_36 ;
}
static int F_22 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
unsigned int V_29 = V_8 -> V_10 -> V_11 -> V_30 ;
unsigned char V_31 = F_12 ( V_8 ) ;
unsigned char V_34 ;
int V_79 ;
unsigned short V_80 = 0 ;
unsigned int V_37 = 0 ;
unsigned short V_81 ;
int V_35 ;
F_13 ( V_39 , L_5 ) ;
F_20 ( V_27 , V_82 , V_83 ) ;
V_34 = F_14 ( V_27 , V_40 ) ;
if( ( ( V_34 & V_84 ) == 1 ) || ( V_34 & V_85 ) == 1 ) {
F_9 ( V_24 , L_6 ) ;
V_8 -> V_43 = V_44 << 16 ;
V_79 = 1 ;
goto V_86;
}
V_81 = F_23 ( V_27 , V_87 ) ;
F_20 ( V_27 , V_77 , V_57 ) ;
for ( V_35 = 0 ; V_35 < V_8 -> V_48 ; V_35 ++ ) {
F_24 ( V_27 , V_88 , V_8 -> V_50 [ V_35 ] ) ;
}
F_13 ( V_89 , L_9 , V_8 -> V_50 [ 0 ] ) ;
F_24 ( V_27 , V_90 , F_17 ( V_29 ) | F_17 ( V_31 ) ) ;
if ( V_9 -> V_14 == 0 ) {
F_9 ( V_45 , L_7 ) ;
V_8 -> V_43 = V_46 << 16 ;
V_79 = 1 ;
goto V_86;
} else if ( V_9 -> V_14 > 0 && V_9 -> V_14 <= 3 ) {
V_37 = 0 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_14 ; V_35 ++ ) {
V_37 >>= 8 ;
V_37 |= ( ( unsigned int ) ( V_9 -> V_17 [ V_35 ] ) << 24 ) ;
}
V_37 |= V_47 ;
V_37 |= ( unsigned int ) V_9 -> V_14 ;
F_19 ( V_27 , V_91 , V_37 ) ;
} else {
F_19 ( V_27 , V_91 , 0 ) ;
}
F_20 ( V_27 , V_92 , V_93 ) ;
F_24 ( V_27 , V_94 , V_9 -> V_52 -> V_55 ) ;
F_24 ( V_27 , V_95 , V_96 ) ;
F_24 ( V_27 , V_97 , V_9 -> V_52 -> V_51 ) ;
F_24 ( V_27 , V_98 , V_9 -> V_52 -> V_53 ) ;
F_13 ( V_39 ,
L_10 ,
F_14 ( V_27 , V_97 ) , F_14 ( V_27 , V_98 ) ,
F_25 ( V_27 , V_75 ) , F_14 ( V_27 , V_90 ) ) ;
F_13 ( V_39 , L_11 ,
V_9 -> V_14 , V_37 ) ;
F_19 ( V_27 , V_75 , V_9 -> V_73 -> V_74 ) ;
V_80 = 0 ;
V_80 |= ( V_69 | V_70 ) ;
if ( V_9 -> V_62 & V_63 ) {
if ( F_26 ( V_8 ) > 0 ) {
V_80 |= V_64 ;
}
} else if ( V_9 -> V_62 & V_65 ) {
V_80 |= V_66 ;
} else if ( V_9 -> V_62 & V_67 ) {
V_80 |= V_68 ;
}
F_20 ( V_27 , V_99 , V_80 ) ;
V_80 = ( V_57 |
V_58 |
V_59 |
V_60 |
V_61 ) ;
F_20 ( V_27 , V_77 , V_80 ) ;
V_79 = F_21 ( V_8 , V_27 ) ;
V_86:
F_20 ( V_27 , V_82 , 0 ) ;
return V_79 ;
}
static int F_21 ( struct V_7 * V_8 , unsigned int V_27 )
{
unsigned char V_100 ;
int V_79 = TRUE ;
int time = 0 ;
do {
V_100 = F_14 ( V_27 , V_101 ) ;
time ++ ;
} while ( ( V_100 & ( V_102 | V_103 ) ) == 0 &&
( time <= V_104 ) );
F_13 ( V_39 ,
L_12 , V_100 , time ) ;
if ( V_100 & V_102 ) {
V_8 -> V_43 = V_105 << 16 ;
F_27 ( V_27 , V_106 , V_107 ) ;
} else if ( V_100 & V_103 ) {
V_8 -> V_43 = V_44 << 16 ;
V_79 = FALSE ;
} else {
F_13 ( V_39 , L_13 ) ;
V_8 -> V_43 = V_108 << 16 ;
V_79 = FALSE ;
}
F_24 ( V_27 , V_95 , V_96 ) ;
return V_79 ;
}
static int F_28 ( struct V_7 * V_8 , unsigned char V_109 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_29 = V_8 -> V_10 -> V_11 -> V_30 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
unsigned char V_110 , V_111 ;
F_13 ( V_112 , L_14 ) ;
V_110 = F_14 ( V_27 , V_113 ) ;
V_110 &= ( ~ F_17 ( V_29 ) ) ;
V_111 = 0 ;
while ( V_110 ) {
if ( V_110 & 1 ) {
break;
}
V_110 >>= 1 ;
V_111 ++ ;
}
if ( V_111 >= F_29 ( V_9 -> V_114 ) || V_109 >= F_29 ( V_9 -> V_114 [ 0 ] ) ) {
F_9 ( V_24 , L_15 ) ;
return FALSE ;
} else if( V_9 -> V_114 [ V_111 ] [ V_109 ] . V_8 == NULL ) {
F_9 ( V_24 , L_16 ) ;
return FALSE ;
}
V_9 -> V_115 = V_111 ;
V_9 -> V_116 = V_109 ;
V_9 -> V_52 = & ( V_9 -> V_31 [ V_111 ] ) ;
V_9 -> V_73 = & ( V_9 -> V_114 [ V_111 ] [ V_109 ] ) ;
F_19 ( V_27 , V_117 , V_118 ) ;
return TRUE ;
}
static int F_30 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
struct V_119 * V_120 ;
T_5 * V_121 = V_9 -> V_73 -> V_122 -> V_121 ;
int V_123 , V_35 ;
T_6 V_124 ;
if ( V_121 == NULL ) {
F_13 ( V_125 , L_17 ) ;
return FALSE ;
}
V_123 = F_31 ( V_8 ) ;
if ( ! V_123 )
return TRUE ;
else if ( V_123 < 0 )
return FALSE ;
else {
F_32 (SCpnt, sg, num, i) {
V_121 [ V_35 ] . V_126 = F_16 ( F_33 ( V_120 ) ) ;
V_121 [ V_35 ] . V_127 = F_16 ( F_34 ( V_120 ) ) ;
if ( F_35 ( V_121 [ V_35 ] . V_127 ) > 0x10000 ) {
F_9 ( V_45 ,
L_18 , F_35 ( V_121 [ V_35 ] . V_127 ) ) ;
return FALSE ;
}
F_13 ( V_125 ,
L_19 ,
V_35 ,
F_35 ( V_121 [ V_35 ] . V_126 ) ,
F_35 ( V_121 [ V_35 ] . V_127 ) ) ;
}
V_124 = F_35 ( V_121 [ V_123 - 1 ] . V_127 ) ;
V_121 [ V_123 - 1 ] . V_127 = F_16 ( V_124 | V_128 ) ;
}
return TRUE ;
}
static int F_36 ( struct V_7 * V_8 , void (* F_37)( struct V_7 * ) )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
T_7 * V_31 ;
T_8 * V_73 ;
int V_36 ;
F_13 ( V_129 ,
L_20
L_21 ,
V_8 -> V_10 -> V_130 , V_8 -> V_10 -> V_18 , V_8 -> V_50 [ 0 ] , V_8 -> V_48 ,
F_38 ( V_8 ) , F_39 ( V_8 ) , F_26 ( V_8 ) ) ;
if ( V_9 -> V_131 != NULL ) {
F_9 ( V_45 , L_22 ) ;
V_9 -> V_131 = NULL ;
V_8 -> V_43 = V_108 << 16 ;
F_37 ( V_8 ) ;
return 0 ;
}
if ( F_12 ( V_8 ) == V_8 -> V_10 -> V_11 -> V_30 ) {
F_13 ( V_129 , L_23 ) ;
V_8 -> V_43 = V_132 << 16 ;
F_37 ( V_8 ) ;
return 0 ;
}
if ( V_8 -> V_10 -> V_18 >= V_133 ) {
F_13 ( V_129 , L_24 ) ;
V_8 -> V_43 = V_132 << 16 ;
F_37 ( V_8 ) ;
return 0 ;
}
F_40 ( V_8 ) ;
V_8 -> V_134 = F_37 ;
V_9 -> V_131 = V_8 ;
V_8 -> V_135 . V_136 = V_137 ;
V_8 -> V_135 . V_138 = 0 ;
F_41 ( V_8 , F_26 ( V_8 ) ) ;
V_8 -> V_135 . V_139 = ( char * ) F_39 ( V_8 ) ;
V_8 -> V_135 . V_140 = F_26 ( V_8 ) ;
V_8 -> V_135 . V_141 = NULL ;
V_8 -> V_135 . V_142 = 0 ;
V_9 -> V_14 = 0 ;
V_9 -> V_143 = 0 ;
V_73 = & ( V_9 -> V_114 [ V_8 -> V_10 -> V_130 ] [ V_8 -> V_10 -> V_18 ] ) ;
V_73 -> V_8 = V_8 ;
V_73 -> V_144 = 0 ;
V_73 -> V_145 = FALSE ;
V_9 -> V_73 = V_73 ;
V_9 -> V_115 = V_8 -> V_10 -> V_130 ;
V_9 -> V_116 = V_8 -> V_10 -> V_18 ;
V_36 = F_30 ( V_8 ) ;
if ( V_36 == FALSE ) {
F_9 ( V_45 , L_25 ) ;
V_8 -> V_43 = V_46 << 16 ;
F_42 ( V_8 ) ;
return 0 ;
}
F_5 ( V_8 ) ;
V_31 = & V_9 -> V_31 [ F_12 ( V_8 ) ] ;
V_9 -> V_52 = V_31 ;
if ( ! ( V_31 -> V_146 & ( V_147 | V_148 | V_149 ) ) ) {
unsigned char V_19 , V_20 ;
if ( V_150 != V_151 ) {
F_43 ( V_9 , V_31 , & V_19 , & V_20 ) ;
F_7 ( V_8 , V_19 , V_20 ) ;
V_31 -> V_146 |= V_148 ;
} else {
F_44 ( V_9 , V_31 ) ;
V_31 -> V_146 |= V_147 ;
}
F_13 ( V_129 ,
L_26 ,
V_31 -> V_152 , V_19 , V_20 ) ;
} else if ( V_31 -> V_146 & V_148 ) {
F_44 ( V_9 , V_31 ) ;
V_31 -> V_146 &= ~ V_148 ;
V_31 -> V_146 |= V_147 ;
F_13 ( V_129 ,
L_27 ) ;
} else if ( V_31 -> V_146 & V_149 ) {
F_44 ( V_9 , V_31 ) ;
V_31 -> V_146 &= ~ V_149 ;
V_31 -> V_146 |= V_147 ;
F_13 ( V_129 ,
L_28 ) ;
}
F_13 ( V_153 ,
L_29 ,
V_8 -> V_10 -> V_130 , V_31 -> V_146 , V_31 -> V_51 ,
V_31 -> V_53 ) ;
if ( V_154 == 0 ) {
V_36 = F_11 ( V_8 ) ;
} else {
V_36 = F_22 ( V_8 ) ;
}
if ( V_36 != TRUE ) {
F_13 ( V_129 , L_30 ) ;
F_42 ( V_8 ) ;
}
return 0 ;
}
T_9 F_45 ( int V_155 , void * V_156 )
{
T_2 * V_9 = V_156 ;
unsigned int V_27 = V_9 -> V_157 ;
struct V_7 * V_8 = V_9 -> V_131 ;
unsigned short V_158 , V_159 , V_160 ;
unsigned char V_161 , V_162 ;
unsigned long V_163 ;
int V_36 ;
int V_164 = 0 ;
struct V_165 * V_11 = V_9 -> V_166 ;
F_46 ( V_11 -> V_167 , V_163 ) ;
V_159 = F_23 ( V_27 , V_168 ) ;
F_13 ( V_169 ,
L_31 , V_155 , V_159 ) ;
if ( ( V_159 & V_170 ) == 0 ) {
F_13 ( V_169 , L_32 , V_159 ) ;
goto V_171;
}
V_164 = 1 ;
F_20 ( V_27 , V_82 , V_83 ) ;
V_161 = F_14 ( V_27 , V_40 ) ;
V_162 = V_161 & V_42 ;
V_160 = F_23 ( V_27 , V_172 ) ;
if ( ( V_159 == 0xffff ) && ( V_160 == 0xffff ) ) {
F_9 ( V_173 , L_33 ) ;
if ( V_9 -> V_131 != NULL ) {
F_9 ( V_173 , L_34 ) ;
V_8 -> V_43 = V_132 << 16 ;
F_42 ( V_8 ) ;
}
goto V_86;
}
if ( V_159 & V_174 ) {
F_13 ( V_169 , L_35 ) ;
F_20 ( V_27 , V_175 , V_176 ) ;
goto V_86;
}
if ( V_159 & V_177 ) {
F_9 ( V_173 , L_36 ) ;
F_47 ( V_9 ) ;
if ( V_8 != NULL ) {
V_8 -> V_43 = V_178 << 16 ;
F_42 ( V_8 ) ;
}
goto V_86;
}
if ( V_8 == NULL ) {
F_9 ( V_24 , L_37 ) ;
F_9 ( V_24 , L_38 , V_159 , V_160 ) ;
goto V_86;
}
if( V_159 & V_179 ) {
V_158 = F_23 ( V_27 , V_87 ) ;
F_20 ( V_27 , V_87 , 0 ) ;
if ( V_158 & V_180 ) {
F_13 ( V_169 ,
L_39 ) ;
V_8 -> V_43 = V_181 << 16 ;
F_42 ( V_8 ) ;
goto V_86;
}
if ( V_158 & V_182 ) {
if ( ! ( V_158 & V_183 ) &&
( V_9 -> V_14 <= 3 ) ) {
V_9 -> V_14 = 0 ;
} ;
F_13 ( V_169 , L_40 ) ;
}
if ( ( V_158 & V_184 ) &&
( F_48 ( V_8 ) > 0 ) &&
( ( F_23 ( V_27 , V_185 ) & V_186 ) != 0 ) ) {
F_3 ( L_41 ) ;
}
if ( V_158 & ( V_184 | V_187 ) ) {
F_13 ( V_169 ,
L_42 ) ;
F_13 ( V_169 , L_43 ,
F_25 ( V_27 , V_188 ) ) ;
F_13 ( V_169 , L_44 ,
F_25 ( V_27 , V_75 ) ) ;
F_13 ( V_169 , L_45 ,
F_25 ( V_27 , V_189 ) ) ;
F_13 ( V_169 , L_46 ,
F_25 ( V_27 , V_190 ) ) ;
F_41 ( V_8 , 0 ) ;
}
if ( V_158 & V_183 ) {
F_49 ( V_8 , V_159 , V_158 ) ;
}
if ( V_158 & V_191 ) {
F_50 ( V_8 ) ;
}
if ( V_158 & V_192 ) {
V_36 = F_51 ( V_8 , V_158 ) ;
if ( V_36 == TRUE ) {
goto V_86;
}
}
if ( V_158 & V_193 ) {
V_8 -> V_43 = ( int ) F_14 ( V_27 , V_194 ) ;
}
if ( V_158 & V_195 ) {
F_9 ( V_24 ,
L_47 ) ;
F_52 ( V_9 ) ;
F_53 ( V_9 , V_196 ) ;
F_54 ( V_9 ) ;
}
if ( V_158 & V_197 ) {
F_13 ( V_169 , L_48 ) ;
}
if ( V_158 & V_198 ) {
}
F_55 ( V_158 ) ;
}
if ( V_159 & V_199 ) {
F_13 ( V_169 , L_49 ) ;
switch( V_162 ) {
case V_200 :
F_13 ( V_169 , L_50 ) ;
break;
case V_201 :
F_13 ( V_169 , L_51 ) ;
break;
case V_202 :
F_13 ( V_169 , L_52 ) ;
V_8 -> V_135 . V_136 = F_14 ( V_27 , V_194 ) ;
break;
default:
F_13 ( V_169 , L_53 ) ;
F_13 ( V_169 , L_38 , V_159 , V_160 ) ;
F_15 ( V_162 ) ;
break;
}
goto V_86;
}
if ( V_159 & V_203 ) {
F_13 ( V_169 , L_54 ) ;
switch( V_162 ) {
case V_204 :
F_13 ( V_169 , L_55 ) ;
F_49 ( V_8 , V_159 , 0 ) ;
break;
default:
F_9 ( V_24 , L_56 ) ;
F_9 ( V_24 , L_57 ,
V_159 , V_160 ) ;
F_15 ( V_162 ) ;
break;
}
goto V_86;
}
if ( V_159 & V_205 ) {
F_13 ( V_169 , L_58 ) ;
}
if ( V_159 & V_206 ) {
F_9 ( V_45 , L_59 ) ;
}
#if 0
nsp32_dbg(NSP32_DEBUG_INTR,
"irq_stat=0x%x trans_stat=0x%x", irq_stat, trans_stat);
show_busphase(busphase);
#endif
V_86:
F_20 ( V_27 , V_82 , 0 ) ;
V_171:
F_56 ( V_11 -> V_167 , V_163 ) ;
F_13 ( V_169 , L_60 ) ;
return F_57 ( V_164 ) ;
}
static int F_58 ( struct V_207 * V_208 , struct V_165 * V_11 )
{
unsigned long V_163 ;
T_2 * V_9 ;
int V_209 ;
unsigned int V_27 ;
unsigned char V_210 ;
int V_130 , V_211 ;
long V_212 ;
V_209 = V_11 -> V_213 ;
V_9 = ( T_2 * ) V_11 -> V_12 ;
V_27 = V_11 -> V_28 ;
SPRINTF ( L_61 ) ;
SPRINTF ( L_62 , V_214 ) ;
SPRINTF ( L_63 , V_209 ) ;
SPRINTF ( L_64 , V_11 -> V_155 ) ;
SPRINTF ( L_65 , V_11 -> V_28 , V_11 -> V_28 + V_11 -> V_215 - 1 ) ;
SPRINTF ( L_66 , V_11 -> V_27 , V_11 -> V_27 + V_9 -> V_216 - 1 ) ;
SPRINTF ( L_67 , V_11 -> V_217 ) ;
SPRINTF ( L_68 , ( F_23 ( V_27 , V_218 ) >> 8 ) & 0xff ) ;
V_210 = F_59 ( V_27 , V_219 ) ;
V_212 = V_9 -> V_220 -> V_221 ;
#ifdef F_60
SPRINTF ( L_69 , ( V_210 & V_222 ) ? L_70 : L_71 ) ;
#endif
SPRINTF ( L_72 , ( V_210 & ( V_223 | V_224 ) ) , V_225 [ V_212 ] ) ;
F_46 ( & ( V_9 -> V_226 ) , V_163 ) ;
SPRINTF ( L_73 , V_9 -> V_131 ) ;
F_56 ( & ( V_9 -> V_226 ) , V_163 ) ;
SPRINTF ( L_74 ) ;
for ( V_130 = 0 ; V_130 < F_29 ( V_9 -> V_31 ) ; V_130 ++ ) {
SPRINTF ( L_75 , V_130 ) ;
if ( V_130 == V_11 -> V_30 ) {
SPRINTF ( L_76 ) ;
continue;
}
if ( V_9 -> V_31 [ V_130 ] . V_146 == V_147 ) {
if ( V_9 -> V_31 [ V_130 ] . V_19 == 0 &&
V_9 -> V_31 [ V_130 ] . V_20 == V_227 ) {
SPRINTF ( L_77 ) ;
} else {
SPRINTF ( L_78 ) ;
}
} else {
SPRINTF ( L_79 ) ;
}
if ( V_9 -> V_31 [ V_130 ] . V_19 != 0 ) {
V_211 = 1000000 / ( V_9 -> V_31 [ V_130 ] . V_19 * 4 ) ;
SPRINTF ( L_80 ,
V_211 / 1000 ,
V_211 % 1000 ,
V_9 -> V_31 [ V_130 ] . V_20
) ;
}
SPRINTF ( L_81 ) ;
}
return 0 ;
}
static void F_42 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
F_61 ( V_8 ) ;
F_20 ( V_27 , V_99 , 0 ) ;
F_19 ( V_27 , V_188 , 0 ) ;
(* V_8 -> V_134 )( V_8 ) ;
V_9 -> V_73 -> V_8 = NULL ;
V_9 -> V_73 = NULL ;
V_9 -> V_52 = NULL ;
V_9 -> V_131 = NULL ;
}
static int F_51 ( struct V_7 * V_8 , unsigned short V_81 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
F_13 ( V_228 , L_82 , V_81 ) ;
F_55 ( V_81 ) ;
F_19 ( V_27 , V_188 , 0 ) ;
F_20 ( V_27 , V_99 , 0 ) ;
if ( V_81 & V_229 ) {
F_13 ( V_228 , L_83 ) ;
if ( ! ( V_81 & V_230 ) &&
( ( V_81 & V_184 ) || ( V_81 & V_187 ) ) ) {
unsigned int V_231 , V_232 ;
V_231 = F_25 ( V_27 , V_189 ) ;
V_232 = F_25 ( V_27 , V_190 ) ;
if ( V_232 > 0 ) {
if ( V_231 != V_232 ) {
V_9 -> V_73 -> V_145 = FALSE ;
} else {
V_9 -> V_73 -> V_145 = TRUE ;
}
F_62 ( V_8 , V_232 ) ;
}
}
} else {
}
if ( V_81 & V_233 ) {
}
if ( V_9 -> V_52 -> V_146 & V_148 ) {
F_44 ( V_9 , V_9 -> V_52 ) ;
V_9 -> V_52 -> V_146 &= ~ V_148 ;
V_9 -> V_52 -> V_146 |= V_147 ;
} else if ( V_9 -> V_52 -> V_146 & V_149 ) {
if ( V_81 & ( V_230 | V_234 ) ) {
} else {
F_44 ( V_9 , V_9 -> V_52 ) ;
}
V_9 -> V_52 -> V_146 &= ~ V_149 ;
V_9 -> V_52 -> V_146 |= V_147 ;
}
if ( V_81 & V_230 ) {
F_13 ( V_228 , L_84 ) ;
V_8 -> V_135 . V_136 = F_14 ( V_27 , V_194 ) ;
V_8 -> V_135 . V_138 = 0 ;
F_13 ( V_228 ,
L_85 ,
V_8 -> V_135 . V_136 , F_48 ( V_8 ) ) ;
V_8 -> V_43 = ( V_105 << 16 ) |
( V_8 -> V_135 . V_138 << 8 ) |
( V_8 -> V_135 . V_136 << 0 ) ;
F_42 ( V_8 ) ;
return TRUE ;
} else if ( V_81 & V_234 ) {
V_8 -> V_135 . V_136 = F_14 ( V_27 , V_194 ) ;
V_8 -> V_135 . V_138 = 4 ;
F_13 ( V_228 , L_86 ) ;
return TRUE ;
} else {
F_9 ( V_24 , L_87 ) ;
V_8 -> V_43 = V_46 << 16 ;
F_42 ( V_8 ) ;
return TRUE ;
}
return FALSE ;
}
static void F_62 ( struct V_7 * V_8 , unsigned int V_232 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
int V_235 = V_9 -> V_236 ;
int V_237 ;
int V_238 = V_9 -> V_73 -> V_238 ;
T_5 * V_121 = V_9 -> V_73 -> V_122 -> V_121 ;
unsigned int V_239 , V_240 ;
T_6 V_127 , V_126 ;
F_13 ( V_125 , L_88 , F_48 ( V_8 ) ) ;
V_232 -= F_35 ( V_121 [ V_235 ] . V_126 ) & 3 ;
V_240 = 0 ;
for ( V_237 = V_235 ; V_237 < V_238 ; V_237 ++ ) {
V_240 += ( F_35 ( V_121 [ V_237 ] . V_127 ) & ~ V_128 ) ;
if ( V_240 > V_232 ) {
break;
}
}
if ( V_237 == V_238 ) {
goto V_241;
}
if ( V_240 == V_232 ) {
}
V_239 = V_240 - V_232 ;
V_127 = F_35 ( V_121 [ V_237 ] . V_127 ) ;
V_126 = F_35 ( V_121 [ V_237 ] . V_126 ) ;
V_126 += ( V_127 - V_239 ) ;
V_121 [ V_237 ] . V_126 = F_16 ( V_126 ) ;
V_121 [ V_237 ] . V_127 = F_16 ( V_239 ) ;
V_9 -> V_236 = V_237 ;
return;
V_241:
if ( F_48 ( V_8 ) < V_240 ) {
F_9 ( V_45 , L_89 ) ;
}
F_41 ( V_8 , F_48 ( V_8 ) - V_240 ) ;
F_13 ( V_125 , L_90 , F_48 ( V_8 ) ) ;
return;
}
static void F_50 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
long V_242 ;
int V_35 ;
F_13 ( V_243 ,
L_91 , V_9 -> V_14 ) ;
if ( V_9 -> V_14 == 0 ) {
F_8 ( V_8 ) ;
}
V_242 = V_9 -> V_73 -> V_74 +
( V_9 -> V_73 -> V_236 * sizeof( T_5 ) ) ;
for ( V_35 = 0 ; V_35 < V_9 -> V_14 ; V_35 ++ ) {
F_13 ( V_243 ,
L_92 , V_35 , V_9 -> V_17 [ V_35 ] ) ;
F_53 ( V_9 , ASSERT ) ;
if ( V_35 == ( V_9 -> V_14 - 1 ) ) {
F_20 ( V_27 , V_77 ,
( V_57 |
V_244 |
V_245 |
V_59 |
V_60 ) ) ;
}
F_24 ( V_27 , V_246 , V_9 -> V_17 [ V_35 ] ) ;
F_63 ( V_9 , V_196 ) ;
F_13 ( V_243 , L_93 ,
F_14 ( V_27 , V_40 ) ) ;
} ;
V_9 -> V_14 = 0 ;
F_13 ( V_243 , L_60 ) ;
}
static void F_64 ( struct V_7 * V_8 , unsigned short V_80 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_9 -> V_157 ;
unsigned short V_247 = 0 ;
F_13 ( V_248 , L_14 ) ;
if ( V_9 -> V_52 == NULL || V_9 -> V_73 == NULL ) {
F_9 ( V_45 , L_94 ) ;
}
F_24 ( V_27 , V_97 , V_9 -> V_52 -> V_51 ) ;
F_24 ( V_27 , V_98 , V_9 -> V_52 -> V_53 ) ;
F_24 ( V_27 , V_94 , V_9 -> V_52 -> V_55 ) ;
F_19 ( V_27 , V_75 , V_9 -> V_73 -> V_74 ) ;
V_247 = 0 ;
V_247 |= ( V_69 | V_70 ) ;
if ( V_9 -> V_62 & V_63 ) {
if ( F_26 ( V_8 ) > 0 ) {
V_247 |= V_64 ;
}
} else if ( V_9 -> V_62 & V_65 ) {
V_247 |= V_66 ;
} else if ( V_9 -> V_62 & V_67 ) {
V_247 |= V_68 ;
}
F_20 ( V_27 , V_99 , V_247 ) ;
V_80 |= ( V_57 |
V_244 |
V_245 ) ;
F_20 ( V_27 , V_77 , V_80 ) ;
F_13 ( V_248 , L_60 ) ;
}
static void F_49 ( struct V_7 * V_8 ,
unsigned long V_249 ,
unsigned short V_81 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
unsigned char V_250 ;
unsigned char V_251 ;
unsigned char V_109 ;
unsigned short V_80 = 0 ;
int V_252 = TRUE ;
long V_242 ;
int V_36 ;
V_250 = F_14 ( V_27 , V_253 ) ;
V_9 -> V_254 [ ( unsigned char ) V_9 -> V_143 ] = V_250 ;
V_251 = V_9 -> V_254 [ 0 ] ;
F_13 ( V_255 ,
L_95 ,
V_9 -> V_143 , V_250 , V_251 ) ;
F_52 ( V_9 ) ;
if ( V_251 & 0x80 ) {
if ( ! ( V_249 & V_256 ) ) {
goto V_257;
}
V_109 = V_251 & 0x1f ;
V_36 = F_28 ( V_8 , V_109 ) ;
if ( V_36 == TRUE ) {
goto V_258;
} else {
goto V_257;
}
}
switch ( V_251 ) {
case V_259 :
case V_260 :
F_9 ( V_24 ,
L_96 , V_250 ) ;
break;
case V_261 :
if ( ( V_81 & V_184 ) || ( V_81 & V_187 ) ) {
unsigned int V_232 ;
V_232 = F_25 ( V_27 , V_190 ) ;
if ( ( V_81 & V_229 ) && ( V_232 > 0 ) ) {
F_62 ( V_8 , V_232 ) ;
} else {
}
}
V_9 -> V_73 -> V_145 = FALSE ;
F_19 ( V_27 , V_117 , V_118 ) ;
V_242 = V_9 -> V_73 -> V_74 +
( V_9 -> V_73 -> V_236 * sizeof( T_5 ) ) ;
F_19 ( V_27 , V_75 , V_242 ) ;
break;
case V_262 :
F_9 ( V_24 ,
L_97 ) ;
break;
case V_26 :
if ( V_9 -> V_52 -> V_146 &
( V_148 | V_149 ) ) {
F_44 ( V_9 , V_9 -> V_52 ) ;
V_9 -> V_52 -> V_146 &= ~ V_148 ;
V_9 -> V_52 -> V_146 |= V_147 ;
}
break;
case V_263 :
case V_264 :
F_9 ( V_24 ,
L_98 , V_251 ) ;
break;
case V_265 :
goto V_257;
case V_266 :
case 0x23 :
if ( V_9 -> V_143 >= 1 ) {
goto V_257;
}
V_252 = FALSE ;
break;
case V_21 :
if ( V_9 -> V_143 < 1 ) {
V_252 = FALSE ;
break;
}
if ( ( V_9 -> V_254 [ 1 ] + 1 ) > V_9 -> V_143 ) {
V_252 = FALSE ;
break;
}
switch ( V_9 -> V_254 [ 2 ] ) {
case V_267 :
goto V_257;
break;
case V_23 :
if ( V_9 -> V_143 != V_22 + 1 ) {
goto V_257;
break;
}
F_65 ( V_8 ) ;
break;
case V_268 :
goto V_257;
break;
case V_269 :
goto V_257;
break;
default:
goto V_257;
}
break;
default:
goto V_257;
}
V_258:
if ( V_252 == TRUE ) {
V_9 -> V_143 = 0 ;
if ( V_9 -> V_14 > 0 ) {
F_19 ( V_27 , V_91 , 0 ) ;
V_80 |= V_61 ;
}
V_80 |= ( V_59 | V_60 ) ;
if ( V_9 -> V_73 -> V_145 == TRUE ) {
V_80 |= V_270 ;
}
V_9 -> V_73 -> V_145 = FALSE ;
} else {
V_9 -> V_143 ++ ;
}
F_64 ( V_8 , V_80 ) ;
F_53 ( V_9 , V_196 ) ;
F_54 ( V_9 ) ;
F_13 ( V_255 , L_60 ) ;
return;
V_257:
F_9 ( V_24 ,
L_99
L_100 ,
V_250 , V_9 -> V_143 , V_251 ) ;
F_10 ( V_8 ) ;
V_9 -> V_143 = 0 ;
goto V_258;
}
static void F_65 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
T_7 * V_31 = V_9 -> V_52 ;
T_10 * V_271 ;
unsigned char V_272 = V_9 -> V_254 [ 3 ] ;
unsigned char V_273 = V_9 -> V_254 [ 4 ] ;
int V_274 ;
int V_275 ;
F_13 ( V_255 , L_14 ) ;
V_271 = V_9 -> V_271 ;
V_275 = V_9 -> V_275 ;
if ( V_31 -> V_146 & V_148 ) {
F_13 ( V_255 , L_101 ) ;
V_31 -> V_146 &= ~ V_148 ;
V_31 -> V_146 |= V_147 ;
if ( V_273 > V_276 ) {
goto V_257;
}
if ( V_273 == V_227 ) {
goto V_277;
}
if ( V_272 < V_9 -> V_271 [ 0 ] . V_278 ) {
goto V_257;
}
V_274 = F_66 ( V_9 , V_31 , V_272 ) ;
if ( V_274 < 0 ) {
goto V_257;
}
F_67 ( V_9 , V_31 , V_274 , V_273 ) ;
} else {
F_13 ( V_255 , L_102 ) ;
V_31 -> V_146 |= V_148 ;
if ( V_273 > V_276 ) {
V_273 = V_276 ;
}
if ( V_272 < V_9 -> V_271 [ 0 ] . V_278 ) {
V_272 = V_9 -> V_271 [ 0 ] . V_278 ;
}
V_274 = F_66 ( V_9 , V_31 , V_272 ) ;
if ( V_273 == V_227 || V_274 < 0 ) {
F_44 ( V_9 , V_31 ) ;
F_7 ( V_8 , 0 , V_227 ) ;
} else {
F_67 ( V_9 , V_31 , V_274 , V_273 ) ;
F_7 ( V_8 , V_272 , V_273 ) ;
}
}
V_31 -> V_19 = V_272 ;
F_13 ( V_255 , L_60 ) ;
return;
V_257:
F_10 ( V_8 ) ;
V_277:
F_44 ( V_9 , V_31 ) ;
V_31 -> V_19 = 0 ;
F_13 ( V_255 , L_103 ) ;
return;
}
static int F_66 ( T_2 * V_9 ,
T_7 * V_31 ,
unsigned char V_19 )
{
int V_35 ;
if ( V_31 -> V_152 >= V_9 -> V_275 ) {
F_9 ( V_45 , L_104 ) ;
V_31 -> V_152 = 0 ;
}
for ( V_35 = V_31 -> V_152 ; V_35 < V_9 -> V_275 ; V_35 ++ ) {
if ( V_19 >= V_9 -> V_271 [ V_35 ] . V_279 &&
V_19 <= V_9 -> V_271 [ V_35 ] . V_280 ) {
break;
}
}
if ( V_35 == V_9 -> V_275 ) {
V_35 = - 1 ;
}
return V_35 ;
}
static void F_44 ( T_2 * V_9 , T_7 * V_31 )
{
unsigned char V_19 = V_9 -> V_271 [ V_31 -> V_152 ] . V_278 ;
V_31 -> V_20 = V_227 ;
V_31 -> V_19 = 0 ;
V_31 -> V_51 = F_68 ( V_19 , V_227 ) ;
V_31 -> V_53 = 0 ;
V_31 -> V_55 = 0 ;
F_13 ( V_281 , L_105 ) ;
}
static void F_43 ( T_2 * V_9 ,
T_7 * V_31 ,
unsigned char * V_19 ,
unsigned char * V_20 )
{
unsigned char V_278 , V_53 ;
V_278 = V_9 -> V_271 [ V_31 -> V_152 ] . V_278 ;
* V_19 = V_9 -> V_271 [ V_31 -> V_152 ] . V_279 ;
V_53 = V_9 -> V_271 [ V_31 -> V_152 ] . V_53 ;
* V_20 = V_276 ;
V_31 -> V_51 = F_68 ( V_278 , * V_20 ) ;
V_31 -> V_53 = V_53 ;
V_31 -> V_20 = * V_20 ;
V_31 -> V_55 = 0 ;
}
static void F_67 ( T_2 * V_9 ,
T_7 * V_31 ,
int V_274 ,
unsigned char V_20 )
{
unsigned char V_19 , V_53 , V_282 ;
V_19 = V_9 -> V_271 [ V_274 ] . V_278 ;
V_53 = V_9 -> V_271 [ V_274 ] . V_53 ;
V_20 = V_20 ;
V_282 = V_9 -> V_271 [ V_274 ] . V_282 ;
V_31 -> V_51 = F_68 ( V_19 , V_20 ) ;
V_31 -> V_53 = V_53 ;
V_31 -> V_20 = V_20 ;
V_31 -> V_55 = V_282 | V_283 ;
F_13 ( V_281 , L_106 ) ;
}
static void F_53 ( T_2 * V_9 , int V_284 )
{
unsigned int V_27 = V_9 -> V_157 ;
int V_285 = 0 ;
unsigned char V_286 , V_287 ;
if ( ! ( ( V_284 == ASSERT ) || ( V_284 == V_196 ) ) ) {
F_9 ( V_45 , L_107 ) ;
}
V_287 = ( V_284 == ASSERT ? V_288 : 0 ) ;
do {
V_286 = F_14 ( V_27 , V_40 ) ;
if ( ( V_286 & V_288 ) == V_287 ) {
F_13 ( V_289 ,
L_108 , V_285 ) ;
return;
}
F_69 ( 1 ) ;
V_285 ++ ;
} while ( V_285 < V_290 );
F_9 ( V_24 , L_109 , V_287 ) ;
}
static void F_63 ( T_2 * V_9 , int V_284 )
{
unsigned int V_27 = V_9 -> V_157 ;
int V_285 = 0 ;
unsigned char V_286 , V_291 ;
if ( ! ( ( V_284 == ASSERT ) || ( V_284 == V_196 ) ) ) {
F_9 ( V_45 , L_107 ) ;
}
V_291 = ( V_284 == ASSERT ? V_292 : 0 ) ;
do {
V_286 = F_14 ( V_27 , V_40 ) ;
if ( ( V_286 & V_292 ) == V_291 ) {
F_13 ( V_289 ,
L_108 , V_285 ) ;
return;
}
F_69 ( 1 ) ;
V_285 ++ ;
} while ( V_285 < V_290 );
F_9 ( V_24 , L_110 , V_291 ) ;
}
static void F_52 ( T_2 * V_9 )
{
unsigned int V_27 = V_9 -> V_157 ;
unsigned char V_293 ;
V_293 = F_14 ( V_27 , V_294 ) ;
V_293 |= ( V_295 | V_296 | V_297 ) ;
F_24 ( V_27 , V_294 , V_293 ) ;
}
static void F_54 ( T_2 * V_9 )
{
unsigned int V_27 = V_9 -> V_157 ;
unsigned char V_293 ;
V_293 = F_14 ( V_27 , V_294 ) ;
V_293 &= ~ V_295 ;
F_24 ( V_27 , V_294 , V_293 ) ;
}
static int F_70 ( struct V_298 * V_299 )
{
struct V_165 * V_11 ;
struct V_300 * V_301 ;
T_2 * V_9 ;
int V_36 ;
int V_35 , V_302 ;
F_13 ( V_303 , L_14 ) ;
V_11 = F_71 ( & V_304 , sizeof( T_2 ) ) ;
if ( V_11 == NULL ) {
F_9 ( V_45 , L_111 ) ;
goto V_305;
}
V_9 = ( T_2 * ) V_11 -> V_12 ;
memcpy ( V_9 , & V_306 , sizeof( T_2 ) ) ;
V_11 -> V_155 = V_9 -> V_307 ;
V_11 -> V_28 = V_9 -> V_157 ;
V_11 -> V_308 = V_9 -> V_157 ;
V_11 -> V_215 = V_9 -> V_309 ;
V_11 -> V_27 = ( unsigned long ) V_9 -> V_310 ;
V_9 -> V_166 = V_11 ;
F_72 ( & ( V_9 -> V_226 ) ) ;
V_9 -> V_73 = NULL ;
V_9 -> V_52 = NULL ;
V_9 -> V_62 = V_63 ;
V_9 -> clock = V_311 ;
switch ( V_9 -> clock ) {
case V_311 :
V_9 -> V_271 = V_312 ;
V_9 -> V_275 = F_29 ( V_312 ) ;
break;
case V_313 :
V_9 -> V_271 = V_314 ;
V_9 -> V_275 = F_29 ( V_314 ) ;
break;
case V_315 :
V_9 -> V_271 = V_316 ;
V_9 -> V_275 = F_29 ( V_316 ) ;
break;
default:
F_9 ( V_24 ,
L_112 ) ;
V_9 -> clock = V_311 ;
V_9 -> V_271 = V_312 ;
V_9 -> V_275 = F_29 ( V_312 ) ;
}
if ( F_73 ( V_299 , F_74 ( 32 ) ) != 0 ) {
F_9 ( V_45 , L_113 ) ;
goto V_317;
}
V_9 -> V_33 = F_75 ( V_299 , sizeof( T_3 ) , & ( V_9 -> V_76 ) ) ;
if ( V_9 -> V_33 == NULL ) {
F_9 ( V_45 , L_114 ) ;
goto V_317;
}
V_9 -> V_318 = F_75 ( V_299 , V_319 ,
& ( V_9 -> V_320 ) ) ;
if ( V_9 -> V_318 == NULL ) {
F_9 ( V_45 , L_114 ) ;
goto V_321;
}
for ( V_35 = 0 ; V_35 < F_29 ( V_9 -> V_114 ) ; V_35 ++ ) {
for ( V_302 = 0 ; V_302 < F_29 ( V_9 -> V_114 [ 0 ] ) ; V_302 ++ ) {
int V_20 = V_35 * F_29 ( V_9 -> V_114 [ 0 ] ) + V_302 ;
T_8 V_322 = {
. V_8 = NULL ,
. V_144 = 0 ,
. V_145 = FALSE ,
. V_238 = 0 ,
. V_236 = 0 ,
. V_122 = & ( V_9 -> V_318 [ V_20 ] ) ,
. V_74 = V_9 -> V_320 + ( V_20 * sizeof( V_323 ) ) ,
} ;
V_9 -> V_114 [ V_35 ] [ V_302 ] = V_322 ;
}
}
for ( V_35 = 0 ; V_35 < F_29 ( V_9 -> V_31 ) ; V_35 ++ ) {
T_7 * V_31 = & ( V_9 -> V_31 [ V_35 ] ) ;
V_31 -> V_152 = 0 ;
V_31 -> V_146 = 0 ;
F_44 ( V_9 , V_31 ) ;
}
V_36 = F_76 ( V_9 ) ;
if ( V_36 == FALSE ) {
V_9 -> V_324 = 3 ;
}
F_77 ( V_9 ) ;
snprintf ( V_9 -> V_325 , sizeof( V_9 -> V_325 ) ,
L_115 ,
V_11 -> V_155 , V_11 -> V_28 , V_11 -> V_215 ) ;
F_47 ( V_9 ) ;
V_36 = F_78 ( V_11 -> V_155 , F_45 , V_326 , L_116 , V_9 ) ;
if ( V_36 < 0 ) {
F_9 ( V_45 , L_117
L_118 , V_11 -> V_155 ) ;
goto V_327;
}
V_301 = F_79 ( V_11 -> V_28 , V_11 -> V_215 , L_116 ) ;
if ( V_301 == NULL ) {
F_9 ( V_45 ,
L_119 ,
V_9 -> V_157 , V_9 -> V_309 ) ;
goto V_328;
}
V_36 = F_80 ( V_11 , & V_299 -> V_329 ) ;
if ( V_36 ) {
F_9 ( V_45 , L_120 ) ;
goto V_330;
}
F_81 ( V_11 ) ;
F_82 ( V_299 , V_11 ) ;
return 0 ;
V_330:
F_83 ( V_11 -> V_28 , V_11 -> V_215 ) ;
V_328:
V_328 ( V_11 -> V_155 , V_9 ) ;
V_327:
F_84 ( V_299 , V_319 ,
V_9 -> V_318 , V_9 -> V_320 ) ;
V_321:
F_84 ( V_299 , sizeof( T_3 ) ,
V_9 -> V_33 , V_9 -> V_76 ) ;
V_317:
F_85 ( V_11 ) ;
V_305:
return 1 ;
}
static int F_86 ( struct V_165 * V_11 )
{
T_2 * V_9 = ( T_2 * ) V_11 -> V_12 ;
if ( V_9 -> V_33 ) {
F_84 ( V_9 -> V_331 , sizeof( T_3 ) ,
V_9 -> V_33 , V_9 -> V_76 ) ;
}
if ( V_9 -> V_318 ) {
F_84 ( V_9 -> V_331 , V_319 ,
V_9 -> V_318 , V_9 -> V_320 ) ;
}
if ( V_11 -> V_155 ) {
V_328 ( V_11 -> V_155 , V_9 ) ;
}
if ( V_11 -> V_28 && V_11 -> V_215 ) {
F_83 ( V_11 -> V_28 , V_11 -> V_215 ) ;
}
if ( V_9 -> V_310 ) {
F_87 ( V_9 -> V_310 ) ;
}
return 0 ;
}
static const char * F_88 ( struct V_165 * V_332 )
{
T_2 * V_9 = ( T_2 * ) V_332 -> V_12 ;
return V_9 -> V_325 ;
}
static int F_89 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
F_9 ( V_24 , L_121 ) ;
if ( V_9 -> V_73 -> V_8 == NULL ) {
F_13 ( V_333 , L_122 ) ;
return V_334 ;
}
if ( V_9 -> V_52 -> V_146 & ( V_148 | V_149 ) ) {
V_9 -> V_52 -> V_146 = 0 ;
F_44 ( V_9 , V_9 -> V_52 ) ;
}
F_20 ( V_27 , V_99 , 0 ) ;
F_20 ( V_27 , V_188 , 0 ) ;
V_8 -> V_43 = V_335 << 16 ;
F_42 ( V_8 ) ;
F_13 ( V_333 , L_123 ) ;
return V_336 ;
}
static int F_90 ( struct V_7 * V_8 )
{
T_2 * V_9 = ( T_2 * ) V_8 -> V_10 -> V_11 -> V_12 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
F_91 ( V_8 -> V_10 -> V_11 -> V_167 ) ;
F_9 ( V_173 , L_124 ) ;
F_13 ( V_333 , L_125 , V_8 ) ;
F_20 ( V_27 , V_82 , V_83 ) ;
F_47 ( V_9 ) ;
F_20 ( V_27 , V_82 , 0 ) ;
F_92 ( V_8 -> V_10 -> V_11 -> V_167 ) ;
return V_336 ;
}
static void F_47 ( T_2 * V_9 )
{
unsigned int V_27 = V_9 -> V_157 ;
unsigned short V_337 ;
int V_35 ;
F_13 ( V_333 , L_5 ) ;
F_20 ( V_27 , V_99 , 0 ) ;
F_19 ( V_27 , V_188 , 0 ) ;
F_19 ( V_27 , V_117 , V_118 ) ;
for ( V_35 = 0 ; V_35 < F_29 ( V_9 -> V_31 ) ; V_35 ++ ) {
T_7 * V_31 = & V_9 -> V_31 [ V_35 ] ;
V_31 -> V_146 = 0 ;
F_44 ( V_9 , V_31 ) ;
}
F_24 ( V_27 , V_294 , V_338 ) ;
F_93 ( V_339 / 1000 ) ;
F_24 ( V_27 , V_294 , 0 ) ;
for( V_35 = 0 ; V_35 < 5 ; V_35 ++ ) {
V_337 = F_23 ( V_27 , V_168 ) ;
F_13 ( V_333 , L_126 , V_337 ) ;
}
V_9 -> V_131 = NULL ;
}
static int F_94 ( struct V_7 * V_8 )
{
struct V_165 * V_11 = V_8 -> V_10 -> V_11 ;
unsigned int V_27 = V_8 -> V_10 -> V_11 -> V_28 ;
T_2 * V_9 = ( T_2 * ) V_11 -> V_12 ;
F_9 ( V_173 , L_127 ) ;
F_13 ( V_333 , L_125 , V_8 ) ;
F_91 ( V_8 -> V_10 -> V_11 -> V_167 ) ;
F_77 ( V_9 ) ;
F_20 ( V_27 , V_82 , V_83 ) ;
F_47 ( V_9 ) ;
F_20 ( V_27 , V_82 , 0 ) ;
F_92 ( V_8 -> V_10 -> V_11 -> V_167 ) ;
return V_336 ;
}
static int F_76 ( T_2 * V_9 )
{
int V_340 = V_9 -> V_220 -> V_340 ;
int V_10 = V_9 -> V_220 -> V_10 ;
int V_36 , V_341 , V_35 ;
V_36 = F_95 ( V_9 , 0x7e ) ;
if ( V_36 != 0x55 ) {
F_9 ( V_173 , L_128 , V_36 ) ;
return FALSE ;
}
V_36 = F_95 ( V_9 , 0x7f ) ;
if ( V_36 != 0xaa ) {
F_9 ( V_173 , L_129 , V_36 ) ;
return FALSE ;
}
if ( V_340 == V_342 &&
V_10 == V_343 ) {
V_36 = F_96 ( V_9 ) ;
} else if ( V_340 == V_342 &&
V_10 == V_344 ) {
V_36 = F_97 ( V_9 ) ;
} else if ( V_340 == V_342 &&
V_10 == V_345 ) {
V_36 = F_97 ( V_9 ) ;
} else {
F_9 ( V_24 , L_130 ) ;
V_36 = FALSE ;
}
for ( V_35 = 0 ; V_35 <= 0x1f ; V_35 ++ ) {
V_341 = F_95 ( V_9 , V_35 ) ;
F_13 ( V_346 ,
L_131 , V_35 , V_341 ) ;
}
return V_36 ;
}
static int F_97 ( T_2 * V_9 )
{
int V_36 , V_35 ;
int V_347 ;
T_7 * V_31 ;
int V_274 ;
V_9 -> V_324 = F_95 ( V_9 , 0x12 ) ;
V_36 = F_95 ( V_9 , 0x07 ) ;
switch ( V_36 ) {
case 0 :
V_347 = TRUE ;
break;
case 1 :
V_347 = FALSE ;
break;
default:
F_9 ( V_24 ,
L_132 ) ;
V_347 = TRUE ;
}
if ( V_150 == V_348 ) {
V_347 = TRUE ;
}
for ( V_35 = 0 ; V_35 < V_349 ; V_35 ++ ) {
V_31 = & V_9 -> V_31 [ V_35 ] ;
if ( V_347 == TRUE ) {
V_31 -> V_152 = 0 ;
} else {
V_36 = F_95 ( V_9 , V_35 ) ;
V_274 = F_66 ( V_9 , V_31 , V_36 ) ;
if ( V_274 < 0 ) {
V_274 = 0 ;
}
V_31 -> V_152 = V_274 ;
}
}
return TRUE ;
}
static int F_96 ( T_2 * V_9 )
{
int V_36 , V_35 ;
T_7 * V_31 ;
int V_274 , V_341 ;
V_9 -> V_324 = F_95 ( V_9 , 0x11 ) ;
for ( V_35 = 0 ; V_35 < V_349 ; V_35 ++ ) {
V_31 = & V_9 -> V_31 [ V_35 ] ;
V_36 = F_95 ( V_9 , V_35 ) ;
switch ( V_36 ) {
case 0 :
V_341 = 0x0c ;
break;
case 1 :
V_341 = 0x19 ;
break;
case 2 :
V_341 = 0x32 ;
break;
case 3 :
V_341 = 0x00 ;
break;
default:
V_341 = 0x0c ;
break;
}
V_274 = F_66 ( V_9 , V_31 , V_341 ) ;
if ( V_274 < 0 || V_150 == V_348 ) {
V_274 = 0 ;
}
V_31 -> V_152 = V_274 ;
}
return TRUE ;
}
static int F_95 ( T_2 * V_9 , int V_350 )
{
int V_35 , V_341 ;
F_98 ( V_9 ) ;
F_99 ( V_9 , 1 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 1 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 0 ) ;
for ( V_35 = 7 ; V_35 >= 0 ; V_35 -- ) {
F_99 ( V_9 , ( ( V_350 >> V_35 ) & 1 ) ) ;
}
F_99 ( V_9 , 0 ) ;
F_98 ( V_9 ) ;
F_99 ( V_9 , 1 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 1 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 0 ) ;
F_99 ( V_9 , 1 ) ;
F_99 ( V_9 , 0 ) ;
V_341 = 0 ;
for ( V_35 = 7 ; V_35 >= 0 ; V_35 -- ) {
V_341 += ( F_100 ( V_9 ) << V_35 ) ;
}
F_99 ( V_9 , 1 ) ;
F_101 ( V_9 ) ;
return V_341 ;
}
static void F_102 ( T_2 * V_9 , int V_351 , int V_341 )
{
int V_27 = V_9 -> V_157 ;
int V_322 ;
V_322 = F_59 ( V_27 , V_352 ) ;
if ( V_341 == 0 ) {
V_322 &= ~ V_351 ;
} else {
V_322 |= V_351 ;
}
F_27 ( V_27 , V_352 , V_322 ) ;
F_69 ( 10 ) ;
}
static int F_103 ( T_2 * V_9 , int V_351 )
{
int V_27 = V_9 -> V_157 ;
int V_322 , V_36 ;
if ( V_351 != V_353 ) {
F_9 ( V_45 , L_133 ) ;
return 0 ;
}
V_322 = F_59 ( V_27 , V_352 ) & V_351 ;
if ( V_322 == 0 ) {
V_36 = 0 ;
} else {
V_36 = 1 ;
}
F_69 ( 10 ) ;
return V_36 ;
}
static void F_98 ( T_2 * V_9 )
{
F_102 ( V_9 , V_354 , 1 ) ;
F_102 ( V_9 , V_353 , 1 ) ;
F_102 ( V_9 , V_355 , 1 ) ;
F_102 ( V_9 , V_353 , 0 ) ;
F_102 ( V_9 , V_354 , 0 ) ;
}
static void F_101 ( T_2 * V_9 )
{
F_102 ( V_9 , V_354 , 1 ) ;
F_102 ( V_9 , V_353 , 0 ) ;
F_102 ( V_9 , V_355 , 1 ) ;
F_102 ( V_9 , V_353 , 1 ) ;
F_102 ( V_9 , V_354 , 0 ) ;
}
static void F_99 ( T_2 * V_9 , int V_341 )
{
F_102 ( V_9 , V_353 , V_341 ) ;
F_102 ( V_9 , V_354 , 1 ) ;
F_102 ( V_9 , V_354 , 0 ) ;
}
static int F_100 ( T_2 * V_9 )
{
int V_341 ;
F_102 ( V_9 , V_355 , 0 ) ;
F_102 ( V_9 , V_354 , 1 ) ;
V_341 = F_103 ( V_9 , V_353 ) ;
F_102 ( V_9 , V_354 , 0 ) ;
F_102 ( V_9 , V_355 , 1 ) ;
return V_341 ;
}
static int F_104 ( struct V_298 * V_299 , T_11 V_284 )
{
struct V_165 * V_11 = F_105 ( V_299 ) ;
F_9 ( V_173 , L_134 , V_299 , V_284 , F_106 ( V_299 ) , V_11 ) ;
F_107 ( V_299 ) ;
F_108 ( V_299 ) ;
F_109 ( V_299 , F_110 ( V_299 , V_284 ) ) ;
return 0 ;
}
static int F_111 ( struct V_298 * V_299 )
{
struct V_165 * V_11 = F_105 ( V_299 ) ;
T_2 * V_9 = ( T_2 * ) V_11 -> V_12 ;
unsigned short V_356 ;
F_9 ( V_173 , L_135 , V_299 , F_106 ( V_299 ) , V_11 ) ;
F_109 ( V_299 , V_357 ) ;
F_112 ( V_299 , V_357 , 0 ) ;
F_113 ( V_299 ) ;
V_356 = F_23 ( V_9 -> V_157 , V_218 ) ;
F_9 ( V_173 , L_136 , V_9 -> V_157 , V_356 ) ;
if ( V_356 == 0xffff ) {
F_9 ( V_173 , L_137 ) ;
return 0 ;
}
F_77 ( V_9 ) ;
F_47 ( V_9 ) ;
F_9 ( V_173 , L_138 ) ;
return 0 ;
}
static int F_114 ( struct V_298 * V_299 , const struct V_358 * V_130 )
{
int V_36 ;
T_2 * V_9 = & V_306 ;
F_13 ( V_303 , L_14 ) ;
V_36 = F_115 ( V_299 ) ;
if ( V_36 ) {
F_9 ( V_45 , L_139 ) ;
return V_36 ;
}
V_9 -> V_331 = V_299 ;
V_9 -> V_220 = V_130 ;
V_9 -> V_307 = V_299 -> V_155 ;
V_9 -> V_157 = F_116 ( V_299 , 0 ) ;
V_9 -> V_309 = F_117 ( V_299 , 0 ) ;
V_9 -> V_310 = F_118 ( V_299 , 1 ) ;
V_9 -> V_216 = F_117 ( V_299 , 1 ) ;
F_119 ( V_299 ) ;
V_36 = F_70 ( V_299 ) ;
F_9 ( V_173 , L_140 ,
V_299 -> V_155 ,
V_9 -> V_310 , V_9 -> V_216 ,
F_106 ( V_299 ) ,
V_225 [ V_130 -> V_221 ] ) ;
F_13 ( V_303 , L_141 , V_36 ) ;
return V_36 ;
}
static void F_120 ( struct V_298 * V_299 )
{
struct V_165 * V_11 = F_105 ( V_299 ) ;
F_13 ( V_303 , L_14 ) ;
F_121 ( V_11 ) ;
F_86 ( V_11 ) ;
F_85 ( V_11 ) ;
}
static int T_12 F_122 ( void ) {
F_9 ( V_173 , L_142 ) ;
return F_123 ( & V_359 ) ;
}
static void T_13 F_124 ( void ) {
F_9 ( V_173 , L_143 ) ;
F_125 ( & V_359 ) ;
}
