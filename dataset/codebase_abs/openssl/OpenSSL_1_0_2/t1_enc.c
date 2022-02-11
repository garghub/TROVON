static int F_1 ( const T_1 * V_1 , const unsigned char * V_2 ,
int V_3 ,
const void * V_4 , int V_5 ,
const void * V_6 , int V_7 ,
const void * V_8 , int V_9 ,
const void * V_10 , int V_11 ,
const void * V_12 , int V_13 ,
unsigned char * V_14 , int V_15 )
{
int V_16 ;
T_2 V_17 ;
T_3 V_18 , V_19 , V_20 ;
T_4 * V_21 ;
unsigned char V_22 [ V_23 ] ;
T_2 V_24 ;
int V_25 = 0 ;
V_16 = F_2 ( V_1 ) ;
F_3 ( V_16 >= 0 ) ;
F_4 ( & V_18 ) ;
F_4 ( & V_19 ) ;
F_4 ( & V_20 ) ;
F_5 ( & V_20 , V_26 ) ;
V_21 = F_6 ( V_27 , NULL , V_2 , V_3 ) ;
if ( ! V_21 )
goto V_28;
if ( ! F_7 ( & V_20 , NULL , V_1 , NULL , V_21 ) )
goto V_28;
if ( ! F_8 ( & V_18 , & V_20 ) )
goto V_28;
if ( V_4 && ! F_9 ( & V_18 , V_4 , V_5 ) )
goto V_28;
if ( V_6 && ! F_9 ( & V_18 , V_6 , V_7 ) )
goto V_28;
if ( V_8 && ! F_9 ( & V_18 , V_8 , V_9 ) )
goto V_28;
if ( V_10 && ! F_9 ( & V_18 , V_10 , V_11 ) )
goto V_28;
if ( V_12 && ! F_9 ( & V_18 , V_12 , V_13 ) )
goto V_28;
if ( ! F_10 ( & V_18 , V_22 , & V_24 ) )
goto V_28;
for (; ; ) {
if ( ! F_8 ( & V_18 , & V_20 ) )
goto V_28;
if ( ! F_9 ( & V_18 , V_22 , V_24 ) )
goto V_28;
if ( V_15 > V_16 && ! F_8 ( & V_19 , & V_18 ) )
goto V_28;
if ( V_4 && ! F_9 ( & V_18 , V_4 , V_5 ) )
goto V_28;
if ( V_6 && ! F_9 ( & V_18 , V_6 , V_7 ) )
goto V_28;
if ( V_8 && ! F_9 ( & V_18 , V_8 , V_9 ) )
goto V_28;
if ( V_10 && ! F_9 ( & V_18 , V_10 , V_11 ) )
goto V_28;
if ( V_12 && ! F_9 ( & V_18 , V_12 , V_13 ) )
goto V_28;
if ( V_15 > V_16 ) {
if ( ! F_10 ( & V_18 , V_14 , & V_17 ) )
goto V_28;
V_14 += V_17 ;
V_15 -= V_17 ;
if ( ! F_10 ( & V_19 , V_22 , & V_24 ) )
goto V_28;
} else {
if ( ! F_10 ( & V_18 , V_22 , & V_24 ) )
goto V_28;
memcpy ( V_14 , V_22 , V_15 ) ;
break;
}
}
V_25 = 1 ;
V_28:
F_11 ( V_21 ) ;
F_12 ( & V_18 ) ;
F_12 ( & V_19 ) ;
F_12 ( & V_20 ) ;
F_13 ( V_22 , sizeof( V_22 ) ) ;
return V_25 ;
}
static int F_14 ( long V_29 ,
const void * V_4 , int V_5 ,
const void * V_6 , int V_7 ,
const void * V_8 , int V_9 ,
const void * V_10 , int V_11 ,
const void * V_12 , int V_13 ,
const unsigned char * V_2 , int V_30 ,
unsigned char * V_31 , unsigned char * V_32 , int V_15 )
{
int V_33 , V_34 , V_35 , V_36 ;
const unsigned char * V_37 ;
long V_38 ;
const T_1 * V_1 ;
int V_25 = 0 ;
V_36 = 0 ;
for ( V_35 = 0 ; F_15 ( V_35 , & V_38 , & V_1 ) ; V_35 ++ ) {
if ( ( V_38 << V_39 ) & V_29 )
V_36 ++ ;
}
V_33 = V_30 / V_36 ;
if ( V_36 == 1 )
V_30 = 0 ;
V_37 = V_2 ;
memset ( V_31 , 0 , V_15 ) ;
for ( V_35 = 0 ; F_15 ( V_35 , & V_38 , & V_1 ) ; V_35 ++ ) {
if ( ( V_38 << V_39 ) & V_29 ) {
if ( ! V_1 ) {
F_16 ( V_40 , V_41 ) ;
goto V_28;
}
if ( ! F_1 ( V_1 , V_37 , V_33 + ( V_30 & 1 ) ,
V_4 , V_5 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 , V_12 , V_13 ,
V_32 , V_15 ) )
goto V_28;
V_37 += V_33 ;
for ( V_34 = 0 ; V_34 < V_15 ; V_34 ++ ) {
V_31 [ V_34 ] ^= V_32 [ V_34 ] ;
}
}
}
V_25 = 1 ;
V_28:
return V_25 ;
}
static int F_17 ( T_5 * V_42 , unsigned char * V_43 ,
unsigned char * V_44 , int V_45 )
{
int V_25 ;
V_25 = F_14 ( F_18 ( V_42 ) ,
V_46 ,
V_47 , V_42 -> V_48 -> V_49 ,
V_50 , V_42 -> V_48 -> V_51 , V_50 ,
NULL , 0 , NULL , 0 , V_42 -> V_52 -> V_53 ,
V_42 -> V_52 -> V_54 , V_43 , V_44 , V_45 ) ;
#ifdef F_19
fprintf ( V_55 , L_1 ,
V_42 -> V_52 -> V_54 ) ;
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_42 -> V_52 -> V_54 ; V_34 ++ ) {
fprintf ( V_55 , L_2 , V_42 -> V_52 -> V_53 [ V_34 ] ) ;
}
fprintf ( V_55 , L_3 ) ;
}
#endif
return V_25 ;
}
int F_20 ( T_5 * V_42 , int V_56 )
{
static const unsigned char V_57 [] = L_4 ;
unsigned char * V_58 , * V_59 ;
unsigned char * V_60 ;
unsigned char V_61 [ V_62 ] ;
unsigned char V_63 [ V_62 ] ;
unsigned char V_64 [ V_65 * 2 ] ;
unsigned char V_66 [ V_65 * 2 ] ;
unsigned char * V_67 , * V_68 , * V_69 ;
int V_70 ;
T_6 * V_71 ;
const T_7 * V_72 ;
#ifndef F_21
const T_8 * V_73 ;
#endif
const T_1 * V_38 ;
int V_74 ;
int * V_75 ;
T_3 * V_76 ;
T_4 * V_21 ;
int V_77 , V_78 , V_34 , V_17 , V_79 , V_80 , V_81 ;
int V_82 = 0 ;
V_77 = F_22 ( V_42 -> V_48 -> V_44 . V_83 ) ;
V_72 = V_42 -> V_48 -> V_44 . V_84 ;
V_38 = V_42 -> V_48 -> V_44 . V_85 ;
V_74 = V_42 -> V_48 -> V_44 . V_86 ;
#ifndef F_21
V_73 = V_42 -> V_48 -> V_44 . V_87 ;
#endif
#ifdef F_19
fprintf ( V_55 , L_5 , V_56 ) ;
fprintf ( V_55 , L_6 ,
V_42 -> V_48 -> V_44 . V_83 -> V_88 ,
V_42 -> V_48 -> V_44 . V_83 -> V_89 , V_73 ) ;
fprintf ( V_55 , L_7 , V_72 ) ;
fprintf ( V_55 , L_8 ,
V_72 -> V_90 , V_72 -> V_91 , V_72 -> V_92 , V_72 -> V_93 ) ;
fprintf ( V_55 , L_9 ,
V_42 -> V_48 -> V_44 . V_94 ) ;
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_42 -> V_48 -> V_44 . V_94 ; V_34 ++ )
fprintf ( V_55 , L_10 , V_42 -> V_48 -> V_44 . V_95 [ V_34 ] ) ;
fprintf ( V_55 , L_3 ) ;
}
#endif
if ( V_56 & V_96 ) {
if ( V_42 -> V_48 -> V_44 . V_83 -> V_97 & V_98 )
V_42 -> V_99 |= V_100 ;
else
V_42 -> V_99 &= ~ V_100 ;
if ( V_42 -> V_101 != NULL )
V_82 = 1 ;
else if ( ( V_42 -> V_101 =
F_23 ( sizeof( T_6 ) ) ) == NULL )
goto V_28;
else
F_24 ( V_42 -> V_101 ) ;
V_71 = V_42 -> V_101 ;
V_76 = F_25 ( & V_42 -> V_102 , NULL ) ;
#ifndef F_21
if ( V_42 -> V_103 != NULL ) {
F_26 ( V_42 -> V_103 ) ;
V_42 -> V_103 = NULL ;
}
if ( V_73 != NULL ) {
V_42 -> V_103 = F_27 ( V_73 -> V_104 ) ;
if ( V_42 -> V_103 == NULL ) {
F_16 ( V_105 ,
V_106 ) ;
goto V_107;
}
if ( V_42 -> V_48 -> V_108 . V_73 == NULL )
V_42 -> V_48 -> V_108 . V_73 = ( unsigned char * )
F_23 ( V_109 ) ;
if ( V_42 -> V_48 -> V_108 . V_73 == NULL )
goto V_28;
}
#endif
if ( V_42 -> V_110 != V_111 )
memset ( & ( V_42 -> V_48 -> V_112 [ 0 ] ) , 0 , 8 ) ;
V_59 = & ( V_42 -> V_48 -> V_113 [ 0 ] ) ;
V_75 = & ( V_42 -> V_48 -> V_114 ) ;
} else {
if ( V_42 -> V_48 -> V_44 . V_83 -> V_97 & V_98 )
V_42 -> V_99 |= V_115 ;
else
V_42 -> V_99 &= ~ V_115 ;
if ( V_42 -> V_116 != NULL && ! F_28 ( V_42 ) )
V_82 = 1 ;
else if ( ( V_42 -> V_116 = F_29 () ) == NULL )
goto V_28;
V_71 = V_42 -> V_116 ;
if ( F_28 ( V_42 ) ) {
V_76 = F_30 () ;
if ( ! V_76 )
goto V_28;
V_42 -> V_117 = V_76 ;
} else
V_76 = F_25 ( & V_42 -> V_117 , NULL ) ;
#ifndef F_21
if ( V_42 -> V_118 != NULL ) {
F_26 ( V_42 -> V_118 ) ;
V_42 -> V_118 = NULL ;
}
if ( V_73 != NULL ) {
V_42 -> V_118 = F_27 ( V_73 -> V_104 ) ;
if ( V_42 -> V_118 == NULL ) {
F_16 ( V_105 ,
V_106 ) ;
goto V_107;
}
}
#endif
if ( V_42 -> V_110 != V_111 )
memset ( & ( V_42 -> V_48 -> V_119 [ 0 ] ) , 0 , 8 ) ;
V_59 = & ( V_42 -> V_48 -> V_120 [ 0 ] ) ;
V_75 = & ( V_42 -> V_48 -> V_121 ) ;
}
if ( V_82 )
F_31 ( V_71 ) ;
V_58 = V_42 -> V_48 -> V_44 . V_95 ;
V_34 = * V_75 = V_42 -> V_48 -> V_44 . V_122 ;
V_81 = F_32 ( V_72 ) ;
V_17 = V_77 ? ( V_81 < F_33 ( V_42 -> V_48 -> V_44 . V_83 ) ?
V_81 : F_33 ( V_42 -> V_48 -> V_44 . V_83 ) ) : V_81 ;
if ( F_34 ( V_72 ) == V_123 )
V_79 = V_124 ;
else
V_79 = F_35 ( V_72 ) ;
if ( ( V_56 == V_125 ) ||
( V_56 == V_126 ) ) {
V_67 = & ( V_58 [ 0 ] ) ;
V_78 = V_34 + V_34 ;
V_68 = & ( V_58 [ V_78 ] ) ;
V_78 += V_17 + V_17 ;
V_69 = & ( V_58 [ V_78 ] ) ;
V_78 += V_79 + V_79 ;
V_60 = ( unsigned char * ) V_127 ;
V_80 = V_128 ;
V_70 = 1 ;
} else {
V_78 = V_34 ;
V_67 = & ( V_58 [ V_78 ] ) ;
V_78 += V_34 + V_17 ;
V_68 = & ( V_58 [ V_78 ] ) ;
V_78 += V_17 + V_79 ;
V_69 = & ( V_58 [ V_78 ] ) ;
V_78 += V_79 ;
V_60 = ( unsigned char * ) V_129 ;
V_80 = V_130 ;
V_70 = 0 ;
}
if ( V_78 > V_42 -> V_48 -> V_44 . V_94 ) {
F_16 ( V_105 , V_131 ) ;
goto V_107;
}
memcpy ( V_59 , V_67 , V_34 ) ;
if ( ! ( F_36 ( V_72 ) & V_132 ) ) {
V_21 = F_6 ( V_74 , NULL ,
V_59 , * V_75 ) ;
F_7 ( V_76 , NULL , V_38 , NULL , V_21 ) ;
F_11 ( V_21 ) ;
}
#ifdef F_37
printf ( L_11 , V_56 ) ;
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_34 ; V_133 ++ )
printf ( L_12 , V_67 [ V_133 ] , ( ( V_133 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
#endif
if ( V_77 ) {
if ( ! F_14 ( F_18 ( V_42 ) ,
V_60 , V_80 ,
V_42 -> V_48 -> V_51 , V_50 ,
V_42 -> V_48 -> V_49 , V_50 ,
NULL , 0 , NULL , 0 ,
V_68 , V_17 , V_61 , V_63 , F_32 ( V_72 ) ) )
goto V_107;
V_68 = V_61 ;
if ( V_79 > 0 ) {
if ( ! F_14 ( F_18 ( V_42 ) ,
V_134 , V_135 ,
V_42 -> V_48 -> V_51 , V_50 ,
V_42 -> V_48 -> V_49 , V_50 ,
NULL , 0 , NULL , 0 , V_57 , 0 , V_64 , V_66 , V_79 * 2 ) )
goto V_107;
if ( V_70 )
V_69 = V_64 ;
else
V_69 = & ( V_64 [ V_79 ] ) ;
}
}
V_42 -> V_52 -> V_136 = 0 ;
#ifdef F_19
{
int V_34 ;
fprintf ( V_55 , L_13 ) ;
fprintf ( V_55 , L_14 ) ;
for ( V_34 = 0 ; V_34 < V_72 -> V_92 ; V_34 ++ )
fprintf ( V_55 , L_10 , V_68 [ V_34 ] ) ;
fprintf ( V_55 , L_3 ) ;
fprintf ( V_55 , L_15 ) ;
for ( V_34 = 0 ; V_34 < V_72 -> V_93 ; V_34 ++ )
fprintf ( V_55 , L_10 , V_69 [ V_34 ] ) ;
fprintf ( V_55 , L_3 ) ;
}
#endif
if ( F_34 ( V_72 ) == V_123 ) {
F_38 ( V_71 , V_72 , NULL , V_68 , NULL , ( V_56 & V_137 ) ) ;
F_39 ( V_71 , V_138 , V_79 , V_69 ) ;
} else
F_38 ( V_71 , V_72 , NULL , V_68 , V_69 , ( V_56 & V_137 ) ) ;
if ( ( F_36 ( V_72 ) & V_132 ) && * V_75 )
F_39 ( V_71 , V_139 ,
* V_75 , V_59 ) ;
#ifdef F_40
if ( V_42 -> V_140 ) {
int V_141 = V_56 & V_137 ? V_142 : 0 ;
if ( * V_75 )
V_42 -> V_140 ( 2 , V_42 -> V_110 , V_141 | V_143 ,
V_59 , * V_75 ,
V_42 , V_42 -> V_144 ) ;
if ( V_72 -> V_92 )
V_42 -> V_140 ( 2 , V_42 -> V_110 , V_141 | V_145 ,
V_68 , V_72 -> V_92 , V_42 , V_42 -> V_144 ) ;
if ( V_79 ) {
if ( F_34 ( V_72 ) == V_123 )
V_141 |= V_146 ;
else
V_141 |= V_147 ;
V_42 -> V_140 ( 2 , V_42 -> V_110 , V_141 , V_69 , V_79 , V_42 , V_42 -> V_144 ) ;
}
}
#endif
#ifdef F_37
printf ( L_16 , V_56 ) ;
{
int V_133 ;
for ( V_133 = 0 ; V_133 < F_32 ( V_72 ) ; V_133 ++ )
printf ( L_12 , V_68 [ V_133 ] , ( ( V_133 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_17 ) ;
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_79 ; V_133 ++ )
printf ( L_12 , V_69 [ V_133 ] , ( ( V_133 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_3 ) ;
#endif
F_13 ( V_61 , sizeof( V_61 ) ) ;
F_13 ( V_63 , sizeof( V_61 ) ) ;
F_13 ( V_64 , sizeof( V_64 ) ) ;
F_13 ( V_66 , sizeof( V_66 ) ) ;
return ( 1 ) ;
V_28:
F_16 ( V_105 , V_148 ) ;
V_107:
return ( 0 ) ;
}
int F_41 ( T_5 * V_42 )
{
unsigned char * V_149 , * V_150 = NULL ;
const T_7 * V_72 ;
const T_1 * V_151 ;
int V_45 ;
T_8 * V_73 ;
int V_74 = V_152 , V_75 = 0 ;
int V_25 = 0 ;
#ifdef F_19
fprintf ( V_55 , L_18 ) ;
#endif
if ( V_42 -> V_48 -> V_44 . V_94 != 0 )
return ( 1 ) ;
if ( ! F_42
( V_42 -> V_52 , & V_72 , & V_151 , & V_74 , & V_75 , & V_73 ) ) {
F_16 ( V_153 , V_154 ) ;
return ( 0 ) ;
}
V_42 -> V_48 -> V_44 . V_84 = V_72 ;
V_42 -> V_48 -> V_44 . V_85 = V_151 ;
V_42 -> V_48 -> V_44 . V_86 = V_74 ;
V_42 -> V_48 -> V_44 . V_122 = V_75 ;
V_45 =
F_32 ( V_72 ) + V_75 + F_35 ( V_72 ) ;
V_45 *= 2 ;
F_43 ( V_42 ) ;
if ( ( V_149 = ( unsigned char * ) F_23 ( V_45 ) ) == NULL ) {
F_16 ( V_153 , V_148 ) ;
goto V_28;
}
V_42 -> V_48 -> V_44 . V_94 = V_45 ;
V_42 -> V_48 -> V_44 . V_95 = V_149 ;
if ( ( V_150 = ( unsigned char * ) F_23 ( V_45 ) ) == NULL ) {
F_16 ( V_153 , V_148 ) ;
goto V_28;
}
#ifdef F_37
printf ( L_19 ) ;
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_50 ; V_133 ++ )
printf ( L_12 , V_42 -> V_48 -> V_51 [ V_133 ] ,
( ( V_133 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_20 ) ;
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_50 ; V_133 ++ )
printf ( L_12 , V_42 -> V_48 -> V_49 [ V_133 ] ,
( ( V_133 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_21 ) ;
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_42 -> V_52 -> V_54 ; V_133 ++ )
printf ( L_12 , V_42 -> V_52 -> V_53 [ V_133 ] ,
( ( V_133 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
#endif
if ( ! F_17 ( V_42 , V_149 , V_150 , V_45 ) )
goto V_28;
#ifdef F_37
printf ( L_22 ) ;
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_45 ; V_133 ++ )
printf ( L_12 , V_149 [ V_133 ] , ( ( V_133 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
#endif
if ( ! ( V_42 -> V_155 & V_156 )
&& V_42 -> V_104 -> V_110 <= V_157 ) {
V_42 -> V_48 -> V_158 = 1 ;
if ( V_42 -> V_52 -> V_159 != NULL ) {
if ( V_42 -> V_52 -> V_159 -> V_160 == V_161 )
V_42 -> V_48 -> V_158 = 0 ;
#ifndef F_44
if ( V_42 -> V_52 -> V_159 -> V_160 == V_162 )
V_42 -> V_48 -> V_158 = 0 ;
#endif
}
}
V_25 = 1 ;
V_28:
if ( V_150 ) {
F_13 ( V_150 , V_45 ) ;
F_45 ( V_150 ) ;
}
return ( V_25 ) ;
}
int F_46 ( T_5 * V_42 , int V_163 )
{
T_9 * V_164 ;
T_6 * V_165 ;
unsigned long V_166 ;
int V_167 , V_34 , V_17 , V_79 , V_168 = 0 , V_25 , V_169 = 0 ;
const T_7 * V_170 ;
if ( V_163 ) {
if ( F_47 ( V_42 -> V_117 ) ) {
int V_78 = F_48 ( V_42 -> V_117 ) ;
F_3 ( V_78 >= 0 ) ;
}
V_165 = V_42 -> V_116 ;
V_164 = & ( V_42 -> V_48 -> V_171 ) ;
if ( V_42 -> V_116 == NULL )
V_170 = NULL ;
else {
int V_172 ;
V_170 = F_49 ( V_42 -> V_116 ) ;
if ( F_50 ( V_42 )
&& F_34 ( V_170 ) == V_173 )
V_172 = F_35 ( V_170 ) ;
else
V_172 = 0 ;
if ( V_172 > 1 ) {
if ( V_164 -> V_174 != V_164 -> V_175 )
fprintf ( V_55 ,
L_23 ,
__FILE__ , __LINE__ ) ;
else if ( F_51 ( V_164 -> V_175 , V_172 ) <= 0 )
return - 1 ;
}
}
} else {
if ( F_47 ( V_42 -> V_102 ) ) {
int V_78 = F_48 ( V_42 -> V_102 ) ;
F_3 ( V_78 >= 0 ) ;
}
V_165 = V_42 -> V_101 ;
V_164 = & ( V_42 -> V_48 -> V_108 ) ;
if ( V_42 -> V_101 == NULL )
V_170 = NULL ;
else
V_170 = F_49 ( V_42 -> V_101 ) ;
}
#ifdef F_19
fprintf ( V_55 , L_24 , V_163 ) ;
#endif
if ( ( V_42 -> V_52 == NULL ) || ( V_165 == NULL ) || ( V_170 == NULL ) ) {
memmove ( V_164 -> V_174 , V_164 -> V_175 , V_164 -> V_176 ) ;
V_164 -> V_175 = V_164 -> V_174 ;
V_25 = 1 ;
} else {
V_166 = V_164 -> V_176 ;
V_167 = F_52 ( V_165 -> V_159 ) ;
if ( F_36 ( V_165 -> V_159 ) & V_132 ) {
unsigned char V_177 [ 13 ] , * V_178 ;
V_178 = V_163 ? V_42 -> V_48 -> V_119 : V_42 -> V_48 -> V_112 ;
if ( F_28 ( V_42 ) ) {
unsigned char V_179 [ 9 ] , * V_58 = V_179 ;
F_53 ( V_163 ? V_42 -> V_180 -> V_181 : V_42 -> V_180 -> V_182 , V_58 ) ;
memcpy ( V_58 , & V_178 [ 2 ] , 6 ) ;
memcpy ( V_177 , V_179 , 8 ) ;
} else {
memcpy ( V_177 , V_178 , 8 ) ;
for ( V_34 = 7 ; V_34 >= 0 ; V_34 -- ) {
++ V_178 [ V_34 ] ;
if ( V_178 [ V_34 ] != 0 )
break;
}
}
V_177 [ 8 ] = V_164 -> type ;
V_177 [ 9 ] = ( unsigned char ) ( V_42 -> V_110 >> 8 ) ;
V_177 [ 10 ] = ( unsigned char ) ( V_42 -> V_110 ) ;
V_177 [ 11 ] = V_164 -> V_176 >> 8 ;
V_177 [ 12 ] = V_164 -> V_176 & 0xff ;
V_168 = F_39 ( V_165 , V_183 , 13 , V_177 ) ;
if ( V_163 ) {
V_166 += V_168 ;
V_164 -> V_176 += V_168 ;
}
} else if ( ( V_167 != 1 ) && V_163 ) {
V_34 = V_167 - ( ( int ) V_166 % V_167 ) ;
V_17 = V_34 - 1 ;
if ( V_42 -> V_155 & V_184 ) {
if ( V_42 -> V_48 -> V_185 & V_186 )
V_17 ++ ;
}
for ( V_79 = ( int ) V_166 ; V_79 < ( int ) ( V_166 + V_34 ) ; V_79 ++ )
V_164 -> V_175 [ V_79 ] = V_17 ;
V_166 += V_34 ;
V_164 -> V_176 += V_34 ;
}
#ifdef F_19
{
unsigned long V_187 ;
fprintf ( V_55 ,
L_25 ,
V_165 , V_164 -> V_174 , V_164 -> V_175 , V_166 ) ;
fprintf ( V_55 ,
L_26 ,
V_165 -> V_188 , V_165 -> V_159 -> V_92 , V_189 ,
V_190 , V_165 -> V_159 -> V_93 ) ;
fprintf ( V_55 , L_27 ) ;
for ( V_34 = 0 ; V_34 < V_165 -> V_159 -> V_93 ; V_34 ++ )
fprintf ( V_55 , L_2 , V_165 -> V_69 [ V_34 ] ) ;
fprintf ( V_55 , L_3 ) ;
fprintf ( V_55 , L_28 ) ;
for ( V_187 = 0 ; V_187 < V_166 ; V_187 ++ )
fprintf ( V_55 , L_29 , V_164 -> V_175 [ V_187 ] ) ;
fprintf ( V_55 , L_3 ) ;
}
#endif
if ( ! V_163 ) {
if ( V_166 == 0 || V_166 % V_167 != 0 )
return 0 ;
}
V_34 = F_54 ( V_165 , V_164 -> V_174 , V_164 -> V_175 , V_166 ) ;
if ( ( F_36 ( V_165 -> V_159 ) & V_191 )
? ( V_34 < 0 )
: ( V_34 == 0 ) )
return - 1 ;
if ( F_34 ( V_170 ) == V_123 && ! V_163 ) {
V_164 -> V_174 += V_192 ;
V_164 -> V_175 += V_192 ;
V_164 -> V_176 -= V_192 ;
}
#ifdef F_19
{
unsigned long V_34 ;
fprintf ( V_55 , L_30 ) ;
for ( V_34 = 0 ; V_34 < V_166 ; V_34 ++ )
fprintf ( V_55 , L_29 , V_164 -> V_174 [ V_34 ] ) ;
fprintf ( V_55 , L_3 ) ;
}
#endif
V_25 = 1 ;
if ( F_47 ( V_42 -> V_102 ) != NULL )
V_169 = F_48 ( V_42 -> V_102 ) ;
if ( ( V_167 != 1 ) && ! V_163 )
V_25 = F_55 ( V_42 , V_164 , V_167 , V_169 ) ;
if ( V_168 && ! V_163 )
V_164 -> V_176 -= V_168 ;
}
return V_25 ;
}
int F_56 ( T_5 * V_42 , int V_193 , unsigned char * V_14 )
{
unsigned int V_25 ;
T_3 V_18 , * V_194 = NULL ;
int V_34 ;
if ( V_42 -> V_48 -> V_195 )
if ( ! F_57 ( V_42 ) )
return 0 ;
for ( V_34 = 0 ; V_34 < V_196 ; V_34 ++ ) {
if ( V_42 -> V_48 -> V_197 [ V_34 ]
&& F_58 ( V_42 -> V_48 -> V_197 [ V_34 ] ) == V_193 ) {
V_194 = V_42 -> V_48 -> V_197 [ V_34 ] ;
break;
}
}
if ( ! V_194 ) {
F_16 ( V_198 , V_199 ) ;
return 0 ;
}
F_4 ( & V_18 ) ;
F_8 ( & V_18 , V_194 ) ;
F_59 ( & V_18 , V_14 , & V_25 ) ;
F_12 ( & V_18 ) ;
return ( ( int ) V_25 ) ;
}
int F_60 ( T_5 * V_42 ,
const char * V_200 , int V_30 , unsigned char * V_14 )
{
unsigned int V_34 ;
T_3 V_18 ;
unsigned char V_177 [ 2 * V_23 ] ;
unsigned char * V_201 , V_202 [ 12 ] ;
int V_35 ;
long V_203 ;
int V_28 = 0 ;
const T_1 * V_1 ;
V_201 = V_177 ;
if ( V_42 -> V_48 -> V_195 )
if ( ! F_57 ( V_42 ) )
return 0 ;
F_4 ( & V_18 ) ;
for ( V_35 = 0 ; F_15 ( V_35 , & V_203 , & V_1 ) ; V_35 ++ ) {
if ( V_203 & F_18 ( V_42 ) ) {
int V_204 = F_2 ( V_1 ) ;
T_3 * V_205 = V_42 -> V_48 -> V_197 [ V_35 ] ;
if ( ! V_205 || V_204 < 0
|| V_204 > ( int ) ( sizeof V_177 - ( T_2 ) ( V_201 - V_177 ) ) ) {
V_28 = 1 ;
} else {
if ( ! F_8 ( & V_18 , V_205 ) ||
! F_59 ( & V_18 , V_201 , & V_34 ) ||
( V_34 != ( unsigned int ) V_204 ) )
V_28 = 1 ;
V_201 += V_204 ;
}
}
}
if ( ! F_14 ( F_18 ( V_42 ) ,
V_200 , V_30 , V_177 , ( int ) ( V_201 - V_177 ) , NULL , 0 , NULL , 0 , NULL , 0 ,
V_42 -> V_52 -> V_53 , V_42 -> V_52 -> V_54 ,
V_14 , V_202 , sizeof V_202 ) )
V_28 = 1 ;
F_12 ( & V_18 ) ;
if ( V_28 )
return 0 ;
else
return sizeof V_202 ;
}
int F_61 ( T_5 * V_206 , unsigned char * V_1 , int V_163 )
{
T_9 * V_164 ;
unsigned char * V_178 ;
T_3 * V_151 ;
T_2 V_207 , V_208 ;
int V_34 ;
T_3 V_209 , * V_76 ;
unsigned char V_210 [ 13 ] ;
int V_211 = ( V_163 ? ( V_206 -> V_99 & V_115 )
: ( V_206 -> V_99 & V_100 ) ) ;
int V_212 ;
if ( V_163 ) {
V_164 = & ( V_206 -> V_48 -> V_171 ) ;
V_178 = & ( V_206 -> V_48 -> V_119 [ 0 ] ) ;
V_151 = V_206 -> V_117 ;
} else {
V_164 = & ( V_206 -> V_48 -> V_108 ) ;
V_178 = & ( V_206 -> V_48 -> V_112 [ 0 ] ) ;
V_151 = V_206 -> V_102 ;
}
V_212 = F_48 ( V_151 ) ;
F_3 ( V_212 >= 0 ) ;
V_207 = V_212 ;
if ( V_211 ) {
V_76 = V_151 ;
} else {
if ( ! F_62 ( & V_209 , V_151 ) )
return - 1 ;
V_76 = & V_209 ;
}
if ( F_28 ( V_206 ) ) {
unsigned char V_179 [ 8 ] , * V_58 = V_179 ;
F_53 ( V_163 ? V_206 -> V_180 -> V_181 : V_206 -> V_180 -> V_182 , V_58 ) ;
memcpy ( V_58 , & V_178 [ 2 ] , 6 ) ;
memcpy ( V_210 , V_179 , 8 ) ;
} else
memcpy ( V_210 , V_178 , 8 ) ;
V_208 = V_164 -> V_176 + V_207 + ( ( unsigned int ) V_164 -> type >> 8 ) ;
V_164 -> type &= 0xff ;
V_210 [ 8 ] = V_164 -> type ;
V_210 [ 9 ] = ( unsigned char ) ( V_206 -> V_110 >> 8 ) ;
V_210 [ 10 ] = ( unsigned char ) ( V_206 -> V_110 ) ;
V_210 [ 11 ] = ( V_164 -> V_176 ) >> 8 ;
V_210 [ 12 ] = ( V_164 -> V_176 ) & 0xff ;
if ( ! V_163 &&
F_63 ( V_206 -> V_101 ) == V_173 &&
F_64 ( V_76 ) ) {
F_65 ( V_76 ,
V_1 , & V_207 ,
V_210 , V_164 -> V_175 ,
V_164 -> V_176 + V_207 , V_208 ,
V_206 -> V_48 -> V_113 ,
V_206 -> V_48 -> V_114 , 0 ) ;
} else {
F_9 ( V_76 , V_210 , sizeof( V_210 ) ) ;
F_9 ( V_76 , V_164 -> V_175 , V_164 -> V_176 ) ;
V_212 = F_10 ( V_76 , V_1 , & V_207 ) ;
F_3 ( V_212 > 0 ) ;
#ifdef F_66
if ( ! V_163 && F_67 () )
F_68 ( V_206 -> V_101 ,
V_76 , V_164 -> V_175 , V_164 -> V_176 , V_208 ) ;
#endif
}
if ( ! V_211 )
F_12 ( & V_209 ) ;
#ifdef F_37
fprintf ( V_55 , L_31 ) ;
{
int V_133 ;
for ( V_133 = 0 ; V_133 < 8 ; V_133 ++ )
fprintf ( V_55 , L_32 , V_178 [ V_133 ] ) ;
fprintf ( V_55 , L_3 ) ;
}
fprintf ( V_55 , L_33 ) ;
{
unsigned int V_133 ;
for ( V_133 = 0 ; V_133 < V_164 -> V_176 ; V_133 ++ )
fprintf ( V_55 , L_32 , V_164 -> V_174 [ V_133 ] ) ;
fprintf ( V_55 , L_3 ) ;
}
#endif
if ( ! F_28 ( V_206 ) ) {
for ( V_34 = 7 ; V_34 >= 0 ; V_34 -- ) {
++ V_178 [ V_34 ] ;
if ( V_178 [ V_34 ] != 0 )
break;
}
}
#ifdef F_37
{
unsigned int V_133 ;
for ( V_133 = 0 ; V_133 < V_207 ; V_133 ++ )
fprintf ( V_55 , L_32 , V_1 [ V_133 ] ) ;
fprintf ( V_55 , L_3 ) ;
}
#endif
return ( V_207 ) ;
}
int F_69 ( T_5 * V_42 , unsigned char * V_14 , unsigned char * V_58 ,
int V_33 )
{
unsigned char V_213 [ V_214 ] ;
const void * V_215 = NULL , * V_216 = NULL ;
int V_217 = 0 , V_218 = 0 ;
#ifdef F_19
fprintf ( V_55 , L_34 , V_42 , V_14 , V_58 ,
V_33 ) ;
#endif
#ifdef F_70
if ( V_42 -> V_48 -> V_219 != NULL
&& V_42 -> V_48 -> V_220 != NULL
&& V_42 -> V_48 -> V_221 > 0
&& V_42 -> V_48 -> V_221 ==
V_42 -> V_48 -> V_222 ) {
V_215 = V_42 -> V_48 -> V_219 ;
V_217 = V_42 -> V_48 -> V_222 ;
V_216 = V_42 -> V_48 -> V_220 ;
V_218 = V_42 -> V_48 -> V_221 ;
}
#endif
F_14 ( F_18 ( V_42 ) ,
V_223 , V_224 ,
V_42 -> V_48 -> V_51 , V_50 ,
V_215 , V_217 ,
V_42 -> V_48 -> V_49 , V_50 ,
V_216 , V_218 , V_58 , V_33 , V_42 -> V_52 -> V_53 , V_213 , sizeof V_213 ) ;
#ifdef F_71
fprintf ( V_55 , L_35 ) ;
F_72 ( V_55 , ( char * ) V_58 , V_33 ) ;
fprintf ( V_55 , L_36 ) ;
F_72 ( V_55 , ( char * ) V_42 -> V_48 -> V_51 , V_50 ) ;
fprintf ( V_55 , L_37 ) ;
F_72 ( V_55 , ( char * ) V_42 -> V_48 -> V_49 , V_50 ) ;
fprintf ( V_55 , L_38 ) ;
F_72 ( V_55 , ( char * ) V_42 -> V_52 -> V_53 ,
V_225 ) ;
#endif
#ifdef F_40
if ( V_42 -> V_140 ) {
V_42 -> V_140 ( 2 , V_42 -> V_110 , V_226 ,
V_58 , V_33 , V_42 , V_42 -> V_144 ) ;
V_42 -> V_140 ( 2 , V_42 -> V_110 , V_227 ,
V_42 -> V_48 -> V_51 , V_50 ,
V_42 , V_42 -> V_144 ) ;
V_42 -> V_140 ( 2 , V_42 -> V_110 , V_228 ,
V_42 -> V_48 -> V_49 , V_50 ,
V_42 , V_42 -> V_144 ) ;
V_42 -> V_140 ( 2 , V_42 -> V_110 , V_229 ,
V_42 -> V_52 -> V_53 ,
V_225 , V_42 , V_42 -> V_144 ) ;
}
#endif
#ifdef F_19
fprintf ( V_55 , L_39 ) ;
#endif
return ( V_225 ) ;
}
int F_73 ( T_5 * V_42 , unsigned char * V_14 , T_2 V_15 ,
const char * V_230 , T_2 V_231 ,
const unsigned char * V_232 ,
T_2 V_233 , int V_234 )
{
unsigned char * V_213 ;
unsigned char * V_235 = NULL ;
T_2 V_236 , V_237 ;
int V_238 ;
#ifdef F_19
fprintf ( V_55 , L_40 ,
V_42 , V_14 , V_15 , V_230 , V_231 , V_232 , V_233 ) ;
#endif
V_213 = F_23 ( V_15 ) ;
if ( V_213 == NULL )
goto V_107;
V_236 = V_231 + V_50 * 2 ;
if ( V_234 ) {
V_236 += 2 + V_233 ;
}
V_235 = F_23 ( V_236 ) ;
if ( V_235 == NULL )
goto V_107;
V_237 = 0 ;
memcpy ( V_235 + V_237 , ( unsigned char * ) V_230 , V_231 ) ;
V_237 += V_231 ;
memcpy ( V_235 + V_237 , V_42 -> V_48 -> V_51 , V_50 ) ;
V_237 += V_50 ;
memcpy ( V_235 + V_237 , V_42 -> V_48 -> V_49 , V_50 ) ;
V_237 += V_50 ;
if ( V_234 ) {
V_235 [ V_237 ] = ( V_233 >> 8 ) & 0xff ;
V_237 ++ ;
V_235 [ V_237 ] = V_233 & 0xff ;
V_237 ++ ;
if ( ( V_233 > 0 ) || ( V_232 != NULL ) ) {
memcpy ( V_235 + V_237 , V_232 , V_233 ) ;
}
}
if ( memcmp ( V_235 , V_239 ,
V_240 ) == 0 )
goto V_241;
if ( memcmp ( V_235 , V_242 ,
V_243 ) == 0 )
goto V_241;
if ( memcmp ( V_235 , V_223 ,
V_224 ) == 0 )
goto V_241;
if ( memcmp ( V_235 , V_46 ,
V_47 ) == 0 )
goto V_241;
V_238 = F_14 ( F_18 ( V_42 ) ,
V_235 , V_236 ,
NULL , 0 ,
NULL , 0 ,
NULL , 0 ,
NULL , 0 ,
V_42 -> V_52 -> V_53 , V_42 -> V_52 -> V_54 ,
V_14 , V_213 , V_15 ) ;
#ifdef F_19
fprintf ( V_55 , L_41 ) ;
#endif
goto V_25;
V_241:
F_16 ( V_244 ,
V_245 ) ;
V_238 = 0 ;
goto V_25;
V_107:
F_16 ( V_244 , V_148 ) ;
V_238 = 0 ;
V_25:
if ( V_213 != NULL )
F_45 ( V_213 ) ;
if ( V_235 != NULL )
F_45 ( V_235 ) ;
return ( V_238 ) ;
}
int F_74 ( int V_246 )
{
switch ( V_246 ) {
case V_247 :
return ( V_248 ) ;
case V_249 :
return ( V_250 ) ;
case V_251 :
return ( V_252 ) ;
case V_253 :
return ( V_254 ) ;
case V_255 :
return ( V_256 ) ;
case V_257 :
return ( V_258 ) ;
case V_259 :
return ( V_260 ) ;
case V_261 :
return ( - 1 ) ;
case V_262 :
return ( V_263 ) ;
case V_264 :
return ( V_265 ) ;
case V_266 :
return ( V_267 ) ;
case V_268 :
return ( V_269 ) ;
case V_270 :
return ( V_271 ) ;
case V_272 :
return ( V_273 ) ;
case V_274 :
return ( V_275 ) ;
case V_276 :
return ( V_277 ) ;
case V_278 :
return ( V_279 ) ;
case V_280 :
return ( V_281 ) ;
case V_282 :
return ( V_283 ) ;
case V_284 :
return ( V_285 ) ;
case V_286 :
return ( V_287 ) ;
case V_288 :
return ( V_289 ) ;
case V_290 :
return ( V_291 ) ;
case V_292 :
return ( V_293 ) ;
case V_294 :
return ( V_295 ) ;
case V_296 :
return ( V_297 ) ;
case V_298 :
return ( V_299 ) ;
case V_300 :
return ( V_301 ) ;
case V_302 :
return ( V_303 ) ;
case V_304 :
return ( V_305 ) ;
case V_306 :
return ( V_307 ) ;
#if 0
case DTLS1_AD_MISSING_HANDSHAKE_MESSAGE:
return (DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
default:
return ( - 1 ) ;
}
}
