static int F_1 ( const char * V_1 )
{
const T_1 * V_2 ;
int V_3 = 0 ;
V_2 = F_2 ( NULL , V_1 , - 1 ) ;
if ( V_2 ) {
F_3 ( & V_3 , NULL , NULL , NULL , NULL , V_2 ) ;
}
return V_3 ;
}
static int F_1 ( const char * V_1 )
{
const T_1 * V_2 ;
T_2 * V_4 = NULL ;
int V_3 = 0 ;
V_2 = F_2 ( & V_4 , V_1 , - 1 ) ;
if ( V_2 ) {
F_3 ( & V_3 , NULL , NULL , NULL , NULL , V_2 ) ;
}
if ( V_4 )
F_4 ( V_4 ) ;
return V_3 ;
}
void F_5 ( void )
{
V_5 [ V_6 ] = F_6 ( V_7 ) ;
V_5 [ V_8 ] =
F_6 ( V_9 ) ;
V_5 [ V_10 ] = F_6 ( V_11 ) ;
V_5 [ V_12 ] = F_6 ( V_13 ) ;
#ifndef F_7
V_5 [ V_14 ] = F_6 ( V_15 ) ;
#else
V_5 [ V_14 ] = NULL ;
#endif
V_5 [ V_16 ] =
F_6 ( V_17 ) ;
V_5 [ V_18 ] =
F_6 ( V_19 ) ;
V_5 [ V_20 ] =
F_6 ( V_21 ) ;
V_5 [ V_22 ] =
F_6 ( V_23 ) ;
V_5 [ V_24 ] =
F_6 ( V_25 ) ;
V_5 [ V_26 ] = F_6 ( V_27 ) ;
V_5 [ V_28 ] =
F_6 ( V_29 ) ;
V_5 [ V_30 ] =
F_6 ( V_31 ) ;
V_32 [ V_33 ] = F_8 ( V_34 ) ;
V_35 [ V_33 ] =
F_9 ( V_32 [ V_33 ] ) ;
F_10 ( V_35 [ V_33 ] >= 0 ) ;
V_32 [ V_36 ] = F_8 ( V_37 ) ;
V_35 [ V_36 ] =
F_9 ( V_32 [ V_36 ] ) ;
F_10 ( V_35 [ V_36 ] >= 0 ) ;
V_32 [ V_38 ] =
F_8 ( V_39 ) ;
if ( V_32 [ V_38 ] ) {
V_35 [ V_38 ] =
F_9 ( V_32 [ V_38 ] ) ;
F_10 ( V_35 [ V_38 ] >= 0 ) ;
}
V_32 [ V_40 ] =
F_8 ( V_41 ) ;
V_42 [ V_40 ] = F_1 ( L_1 ) ;
if ( V_42 [ V_40 ] ) {
V_35 [ V_40 ] = 32 ;
}
V_32 [ V_43 ] = F_8 ( V_44 ) ;
V_35 [ V_43 ] =
F_9 ( V_32 [ V_43 ] ) ;
V_32 [ V_45 ] = F_8 ( V_46 ) ;
V_35 [ V_45 ] =
F_9 ( V_32 [ V_45 ] ) ;
}
static int F_11 ( const T_3 * const * V_47 , const T_3 * const * V_48 )
{
return ( ( * V_47 ) -> V_49 - ( * V_48 ) -> V_49 ) ;
}
static void F_12 ( void )
{
int V_50 = 0 ;
F_13 ( V_51 ) ;
if ( V_52 == NULL ) {
F_14 ( V_51 ) ;
F_15 ( V_51 ) ;
V_50 = 1 ;
if ( V_52 == NULL ) {
T_3 * V_53 = NULL ;
F_16 () ;
V_52 = F_17 ( F_11 ) ;
if ( V_52 != NULL ) {
V_53 = ( T_3 * ) F_18 ( sizeof( T_3 ) ) ;
if ( V_53 != NULL ) {
V_53 -> V_54 = F_19 () ;
if ( V_53 -> V_54 && V_53 -> V_54 -> type == V_55 )
F_20 ( V_53 ) ;
else {
V_53 -> V_49 = V_56 ;
V_53 -> V_57 = V_53 -> V_54 -> V_57 ;
F_21 ( V_52 , V_53 ) ;
}
}
F_22 ( V_52 ) ;
}
F_23 () ;
}
}
if ( V_50 )
F_24 ( V_51 ) ;
else
F_14 ( V_51 ) ;
}
int F_25 ( const T_4 * V_58 , const T_5 * * V_59 ,
const T_6 * * V_60 , int * V_61 ,
int * V_62 , T_3 * * V_53 )
{
int V_63 ;
const T_7 * V_64 ;
V_64 = V_58 -> V_65 ;
if ( V_64 == NULL )
return ( 0 ) ;
if ( V_53 != NULL ) {
T_3 V_66 ;
#ifndef F_26
F_12 () ;
#endif
* V_53 = NULL ;
V_66 . V_49 = V_58 -> V_67 ;
if ( V_52 != NULL ) {
V_63 = F_27 ( V_52 , & V_66 ) ;
if ( V_63 >= 0 )
* V_53 = F_28 ( V_52 , V_63 ) ;
else
* V_53 = NULL ;
}
}
if ( ( V_59 == NULL ) || ( V_60 == NULL ) )
return ( 0 ) ;
switch ( V_64 -> V_68 ) {
case V_69 :
V_63 = V_6 ;
break;
case V_70 :
V_63 = V_8 ;
break;
case V_71 :
V_63 = V_10 ;
break;
case V_72 :
V_63 = V_12 ;
break;
case V_73 :
V_63 = V_14 ;
break;
case V_74 :
V_63 = V_75 ;
break;
case V_76 :
V_63 = V_16 ;
break;
case V_77 :
V_63 = V_18 ;
break;
case V_78 :
V_63 = V_20 ;
break;
case V_79 :
V_63 = V_22 ;
break;
case V_80 :
V_63 = V_24 ;
break;
case V_81 :
V_63 = V_26 ;
break;
case V_82 :
V_63 = V_28 ;
break;
case V_83 :
V_63 = V_30 ;
break;
default:
V_63 = - 1 ;
break;
}
if ( ( V_63 < 0 ) || ( V_63 >= V_84 ) )
* V_59 = NULL ;
else {
if ( V_63 == V_75 )
* V_59 = F_29 () ;
else
* V_59 = V_5 [ V_63 ] ;
}
switch ( V_64 -> V_85 ) {
case V_86 :
V_63 = V_33 ;
break;
case V_87 :
V_63 = V_36 ;
break;
case V_88 :
V_63 = V_43 ;
break;
case V_89 :
V_63 = V_45 ;
break;
case V_90 :
V_63 = V_38 ;
break;
case V_91 :
V_63 = V_40 ;
break;
default:
V_63 = - 1 ;
break;
}
if ( ( V_63 < 0 ) || ( V_63 >= V_92 ) ) {
* V_60 = NULL ;
if ( V_61 != NULL )
* V_61 = V_55 ;
if ( V_62 != NULL )
* V_62 = 0 ;
if ( V_64 -> V_85 == V_93 )
V_61 = NULL ;
} else {
* V_60 = V_32 [ V_63 ] ;
if ( V_61 != NULL )
* V_61 = V_42 [ V_63 ] ;
if ( V_62 != NULL )
* V_62 = V_35 [ V_63 ] ;
}
if ( ( * V_59 != NULL ) &&
( * V_60 != NULL || ( F_30 ( * V_59 ) & V_94 ) )
&& ( ! V_61 || * V_61 != V_55 ) ) {
const T_5 * V_95 ;
if ( V_58 -> V_96 >> 8 != V_97 ||
V_58 -> V_96 < V_98 )
return 1 ;
#ifdef F_31
if ( F_32 () )
return 1 ;
#endif
if ( V_64 -> V_68 == V_71 &&
V_64 -> V_85 == V_86 &&
( V_95 = F_6 ( L_2 ) ) )
* V_59 = V_95 , * V_60 = NULL ;
else if ( V_64 -> V_68 == V_76 &&
V_64 -> V_85 == V_87 &&
( V_95 = F_6 ( L_3 ) ) )
* V_59 = V_95 , * V_60 = NULL ;
else if ( V_64 -> V_68 == V_77 &&
V_64 -> V_85 == V_87 &&
( V_95 = F_6 ( L_4 ) ) )
* V_59 = V_95 , * V_60 = NULL ;
else if ( V_64 -> V_68 == V_76 &&
V_64 -> V_85 == V_88 &&
( V_95 = F_6 ( L_5 ) ) )
* V_59 = V_95 , * V_60 = NULL ;
else if ( V_64 -> V_68 == V_77 &&
V_64 -> V_85 == V_88 &&
( V_95 = F_6 ( L_6 ) ) )
* V_59 = V_95 , * V_60 = NULL ;
return ( 1 ) ;
} else
return ( 0 ) ;
}
int F_33 ( int V_99 , long * V_100 , const T_6 * * V_60 )
{
if ( V_99 < 0 || V_99 >= V_92 ) {
return 0 ;
}
* V_100 = V_101 [ V_99 ] ;
if ( * V_100 )
* V_60 = V_32 [ V_99 ] ;
else
* V_60 = NULL ;
return 1 ;
}
static void F_34 ( T_8 * * V_102 , T_8 * V_103 ,
T_8 * * V_104 )
{
if ( V_103 == * V_104 )
return;
if ( V_103 == * V_102 )
* V_102 = V_103 -> V_105 ;
if ( V_103 -> V_106 != NULL )
V_103 -> V_106 -> V_105 = V_103 -> V_105 ;
if ( V_103 -> V_105 != NULL )
V_103 -> V_105 -> V_106 = V_103 -> V_106 ;
( * V_104 ) -> V_105 = V_103 ;
V_103 -> V_106 = * V_104 ;
V_103 -> V_105 = NULL ;
* V_104 = V_103 ;
}
static void F_35 ( T_8 * * V_102 , T_8 * V_103 ,
T_8 * * V_104 )
{
if ( V_103 == * V_102 )
return;
if ( V_103 == * V_104 )
* V_104 = V_103 -> V_106 ;
if ( V_103 -> V_105 != NULL )
V_103 -> V_105 -> V_106 = V_103 -> V_106 ;
if ( V_103 -> V_106 != NULL )
V_103 -> V_106 -> V_105 = V_103 -> V_105 ;
( * V_102 ) -> V_106 = V_103 ;
V_103 -> V_105 = * V_102 ;
V_103 -> V_106 = NULL ;
* V_102 = V_103 ;
}
static void F_36 ( unsigned long * V_107 , unsigned long * V_108 ,
unsigned long * V_59 , unsigned long * V_109 ,
unsigned long * V_110 )
{
* V_107 = 0 ;
* V_108 = 0 ;
* V_59 = 0 ;
* V_109 = 0 ;
* V_110 = 0 ;
#ifdef F_37
* V_107 |= V_111 ;
* V_108 |= V_112 ;
#endif
#ifdef F_38
* V_108 |= V_113 ;
#endif
#ifdef F_39
* V_107 |= V_114 | V_115 | V_116 ;
* V_108 |= V_117 ;
#endif
#ifdef F_40
* V_107 |= V_118 ;
* V_108 |= V_119 ;
#endif
#ifdef F_41
* V_108 |= V_120 ;
#endif
#ifdef F_42
* V_107 |= V_121 | V_122 ;
* V_108 |= V_123 ;
#endif
#ifdef F_43
* V_107 |= V_124 ;
* V_108 |= V_125 ;
#endif
#ifdef F_44
* V_107 |= V_126 ;
#endif
if ( ! F_1 ( L_7 ) ) {
* V_108 |= V_127 ;
}
if ( ! F_1 ( L_8 ) ) {
* V_108 |= V_128 ;
}
if ( ( * V_108 & ( V_127 | V_128 ) ) == ( V_127 | V_128 ) ) {
* V_107 |= V_129 ;
}
#ifdef F_45
* V_59 |= V_74 ;
#endif
* V_59 |= ( V_5 [ V_6 ] == NULL ) ? V_69 : 0 ;
* V_59 |= ( V_5 [ V_8 ] == NULL ) ? V_70 : 0 ;
* V_59 |= ( V_5 [ V_10 ] == NULL ) ? V_71 : 0 ;
* V_59 |= ( V_5 [ V_12 ] == NULL ) ? V_72 : 0 ;
* V_59 |= ( V_5 [ V_14 ] == NULL ) ? V_73 : 0 ;
* V_59 |= ( V_5 [ V_16 ] == NULL ) ? V_76 : 0 ;
* V_59 |= ( V_5 [ V_18 ] == NULL ) ? V_77 : 0 ;
* V_59 |=
( V_5 [ V_28 ] ==
NULL ) ? V_82 : 0 ;
* V_59 |=
( V_5 [ V_30 ] ==
NULL ) ? V_83 : 0 ;
* V_59 |=
( V_5 [ V_20 ] ==
NULL ) ? V_78 : 0 ;
* V_59 |=
( V_5 [ V_22 ] ==
NULL ) ? V_79 : 0 ;
* V_59 |=
( V_5 [ V_24 ] ==
NULL ) ? V_80 : 0 ;
* V_59 |= ( V_5 [ V_26 ] == NULL ) ? V_81 : 0 ;
* V_109 |= ( V_32 [ V_33 ] == NULL ) ? V_86 : 0 ;
* V_109 |= ( V_32 [ V_36 ] == NULL ) ? V_87 : 0 ;
* V_109 |= ( V_32 [ V_43 ] == NULL ) ? V_88 : 0 ;
* V_109 |= ( V_32 [ V_45 ] == NULL ) ? V_89 : 0 ;
* V_109 |= ( V_32 [ V_38 ] == NULL ) ? V_90 : 0 ;
* V_109 |= ( V_32 [ V_40 ] == NULL
|| V_42 [ V_40 ] ==
V_55 ) ? V_91 : 0 ;
}
static void F_46 ( const T_9 * V_130 ,
int V_131 ,
unsigned long V_132 ,
unsigned long V_133 ,
unsigned long V_134 ,
unsigned long V_135 ,
unsigned long V_136 ,
T_8 * V_137 ,
T_8 * * V_138 ,
T_8 * * V_139 )
{
int V_63 , V_140 ;
const T_7 * V_64 ;
V_140 = 0 ;
for ( V_63 = 0 ; V_63 < V_131 ; V_63 ++ ) {
V_64 = V_130 -> V_141 ( V_63 ) ;
if ( ( V_64 != NULL ) && V_64 -> V_142 &&
#ifdef F_31
( ! F_32 () || ( V_64 -> V_143 & V_144 ) ) &&
#endif
! ( V_64 -> V_145 & V_132 ) &&
! ( V_64 -> V_146 & V_133 ) &&
! ( V_64 -> V_68 & V_134 ) &&
! ( V_64 -> V_85 & V_135 ) &&
! ( V_64 -> V_147 & V_136 ) ) {
V_137 [ V_140 ] . V_65 = V_64 ;
V_137 [ V_140 ] . V_105 = NULL ;
V_137 [ V_140 ] . V_106 = NULL ;
V_137 [ V_140 ] . V_148 = 0 ;
V_140 ++ ;
#ifdef F_47
fprintf ( V_149 , L_9 , V_63 , V_64 -> V_57 , V_64 -> V_49 ,
V_64 -> V_145 , V_64 -> V_146 ) ;
#endif
}
}
if ( V_140 > 0 ) {
V_137 [ 0 ] . V_106 = NULL ;
if ( V_140 > 1 ) {
V_137 [ 0 ] . V_105 = & V_137 [ 1 ] ;
for ( V_63 = 1 ; V_63 < V_140 - 1 ; V_63 ++ ) {
V_137 [ V_63 ] . V_106 = & V_137 [ V_63 - 1 ] ;
V_137 [ V_63 ] . V_105 = & V_137 [ V_63 + 1 ] ;
}
V_137 [ V_140 - 1 ] . V_106 = & V_137 [ V_140 - 2 ] ;
}
V_137 [ V_140 - 1 ] . V_105 = NULL ;
* V_138 = & V_137 [ 0 ] ;
* V_139 = & V_137 [ V_140 - 1 ] ;
}
}
static void F_48 ( const T_7 * * V_150 ,
int V_151 ,
unsigned long V_132 ,
unsigned long V_133 ,
unsigned long V_134 ,
unsigned long V_135 ,
unsigned long V_136 ,
T_8 * V_102 )
{
T_8 * V_152 ;
const T_7 * * V_153 ;
int V_63 ;
unsigned long V_154 = ~ V_132 ;
unsigned long V_155 = ~ V_133 ;
unsigned long V_156 = ~ V_134 ;
unsigned long V_157 = ~ V_135 ;
unsigned long V_158 = ~ V_136 ;
V_152 = V_102 ;
V_153 = V_150 ;
while ( V_152 != NULL ) {
* V_153 = V_152 -> V_65 ;
V_153 ++ ;
V_152 = V_152 -> V_105 ;
}
for ( V_63 = 0 ; V_63 < V_151 ; V_63 ++ ) {
unsigned long V_145 = V_159 [ V_63 ] . V_145 ;
unsigned long V_146 = V_159 [ V_63 ] . V_146 ;
unsigned long V_68 = V_159 [ V_63 ] . V_68 ;
unsigned long V_85 = V_159 [ V_63 ] . V_85 ;
unsigned long V_147 = V_159 [ V_63 ] . V_147 ;
if ( V_145 )
if ( ( V_145 & V_154 ) == 0 )
continue;
if ( V_146 )
if ( ( V_146 & V_155 ) == 0 )
continue;
if ( V_68 )
if ( ( V_68 & V_156 ) == 0 )
continue;
if ( V_85 )
if ( ( V_85 & V_157 ) == 0 )
continue;
if ( V_147 )
if ( ( V_147 & V_158 ) == 0 )
continue;
* V_153 = ( T_7 * ) ( V_159 + V_63 ) ;
V_153 ++ ;
}
* V_153 = NULL ;
}
static void F_49 ( unsigned long V_160 ,
unsigned long V_161 ,
unsigned long V_162 ,
unsigned long V_163 ,
unsigned long V_164 ,
unsigned long V_165 ,
unsigned long V_143 , int V_166 ,
int V_167 , T_8 * * V_138 ,
T_8 * * V_139 )
{
T_8 * V_102 , * V_104 , * V_103 , * V_105 , * V_168 ;
const T_7 * V_169 ;
int V_170 = 0 ;
#ifdef F_50
fprintf ( V_149 ,
L_10 ,
V_166 , V_161 , V_162 , V_163 , V_164 , V_165 ,
V_143 , V_167 ) ;
#endif
if ( V_166 == V_171 )
V_170 = 1 ;
V_102 = * V_138 ;
V_104 = * V_139 ;
if ( V_170 ) {
V_105 = V_104 ;
V_168 = V_102 ;
} else {
V_105 = V_102 ;
V_168 = V_104 ;
}
V_103 = NULL ;
for (; ; ) {
if ( V_103 == V_168 )
break;
V_103 = V_105 ;
if ( V_103 == NULL )
break;
V_105 = V_170 ? V_103 -> V_106 : V_103 -> V_105 ;
V_169 = V_103 -> V_65 ;
if ( V_167 >= 0 ) {
if ( V_167 != V_169 -> V_167 )
continue;
} else {
#ifdef F_50
fprintf ( V_149 ,
L_11 ,
V_169 -> V_57 , V_169 -> V_145 , V_169 -> V_146 ,
V_169 -> V_68 , V_169 -> V_85 , V_169 -> V_147 ,
V_169 -> V_143 ) ;
#endif
#ifdef F_51
if ( V_160 && V_160 != V_169 -> V_49 )
continue;
#endif
if ( V_161 && ! ( V_161 & V_169 -> V_145 ) )
continue;
if ( V_162 && ! ( V_162 & V_169 -> V_146 ) )
continue;
if ( V_163 && ! ( V_163 & V_169 -> V_68 ) )
continue;
if ( V_164 && ! ( V_164 & V_169 -> V_85 ) )
continue;
if ( V_165 && ! ( V_165 & V_169 -> V_147 ) )
continue;
if ( ( V_143 & V_172 )
&& ! ( V_143 & V_172 & V_169 -> V_143 ) )
continue;
if ( ( V_143 & V_173 )
&& ! ( V_143 & V_173 & V_169 -> V_143 ) )
continue;
}
#ifdef F_50
fprintf ( V_149 , L_12 , V_166 ) ;
#endif
if ( V_166 == V_174 ) {
if ( ! V_103 -> V_148 ) {
F_34 ( & V_102 , V_103 , & V_104 ) ;
V_103 -> V_148 = 1 ;
}
}
else if ( V_166 == V_175 ) {
if ( V_103 -> V_148 ) {
F_34 ( & V_102 , V_103 , & V_104 ) ;
}
} else if ( V_166 == V_171 ) {
if ( V_103 -> V_148 ) {
F_35 ( & V_102 , V_103 , & V_104 ) ;
V_103 -> V_148 = 0 ;
}
} else if ( V_166 == V_176 ) {
if ( V_102 == V_103 )
V_102 = V_103 -> V_105 ;
else
V_103 -> V_106 -> V_105 = V_103 -> V_105 ;
if ( V_104 == V_103 )
V_104 = V_103 -> V_106 ;
V_103 -> V_148 = 0 ;
if ( V_103 -> V_105 != NULL )
V_103 -> V_105 -> V_106 = V_103 -> V_106 ;
if ( V_103 -> V_106 != NULL )
V_103 -> V_106 -> V_105 = V_103 -> V_105 ;
V_103 -> V_105 = NULL ;
V_103 -> V_106 = NULL ;
}
}
* V_138 = V_102 ;
* V_139 = V_104 ;
}
static int F_52 ( T_8 * * V_138 ,
T_8 * * V_139 )
{
int V_177 , V_63 , * V_178 ;
T_8 * V_103 ;
V_177 = 0 ;
V_103 = * V_138 ;
while ( V_103 != NULL ) {
if ( V_103 -> V_148 && ( V_103 -> V_65 -> V_167 > V_177 ) )
V_177 = V_103 -> V_65 -> V_167 ;
V_103 = V_103 -> V_105 ;
}
V_178 = F_18 ( ( V_177 + 1 ) * sizeof( int ) ) ;
if ( ! V_178 ) {
F_53 ( V_179 , V_180 ) ;
return ( 0 ) ;
}
memset ( V_178 , 0 , ( V_177 + 1 ) * sizeof( int ) ) ;
V_103 = * V_138 ;
while ( V_103 != NULL ) {
if ( V_103 -> V_148 )
V_178 [ V_103 -> V_65 -> V_167 ] ++ ;
V_103 = V_103 -> V_105 ;
}
for ( V_63 = V_177 ; V_63 >= 0 ; V_63 -- )
if ( V_178 [ V_63 ] > 0 )
F_49 ( 0 , 0 , 0 , 0 , 0 , 0 , 0 , V_175 , V_63 , V_138 ,
V_139 ) ;
F_20 ( V_178 ) ;
return ( 1 ) ;
}
static int F_54 ( const char * V_181 ,
T_8 * * V_138 ,
T_8 * * V_139 ,
const T_7 * * V_150 )
{
unsigned long V_161 , V_162 , V_163 , V_164 , V_165 ,
V_143 ;
const char * V_182 , * V_183 ;
int V_184 , V_185 , V_186 , V_166 , V_187 , V_188 , V_189 ;
unsigned long V_160 = 0 ;
char V_190 ;
V_187 = 1 ;
V_182 = V_181 ;
for (; ; ) {
V_190 = * V_182 ;
if ( V_190 == '\0' )
break;
if ( V_190 == '-' ) {
V_166 = V_171 ;
V_182 ++ ;
} else if ( V_190 == '+' ) {
V_166 = V_175 ;
V_182 ++ ;
} else if ( V_190 == '!' ) {
V_166 = V_176 ;
V_182 ++ ;
} else if ( V_190 == '@' ) {
V_166 = V_191 ;
V_182 ++ ;
} else {
V_166 = V_174 ;
}
if ( F_55 ( V_190 ) ) {
V_182 ++ ;
continue;
}
V_161 = 0 ;
V_162 = 0 ;
V_163 = 0 ;
V_164 = 0 ;
V_165 = 0 ;
V_143 = 0 ;
for (; ; ) {
V_190 = * V_182 ;
V_183 = V_182 ;
V_189 = 0 ;
#ifndef F_56
while ( ( ( V_190 >= 'A' ) && ( V_190 <= 'Z' ) ) ||
( ( V_190 >= '0' ) && ( V_190 <= '9' ) ) ||
( ( V_190 >= 'a' ) && ( V_190 <= 'z' ) ) || ( V_190 == '-' ) || ( V_190 == '.' ) )
#else
while ( isalnum ( V_190 ) || ( V_190 == '-' ) || ( V_190 == '.' ) )
#endif
{
V_190 = * ( ++ V_182 ) ;
V_189 ++ ;
}
if ( V_189 == 0 ) {
F_53 ( V_192 ,
V_193 ) ;
V_187 = V_186 = 0 ;
V_182 ++ ;
break;
}
if ( V_166 == V_191 ) {
V_186 = 0 ;
break;
}
if ( V_190 == '+' ) {
V_185 = 1 ;
V_182 ++ ;
} else
V_185 = 0 ;
V_184 = V_186 = 0 ;
V_160 = 0 ;
while ( V_150 [ V_184 ] ) {
if ( ! strncmp ( V_183 , V_150 [ V_184 ] -> V_57 , V_189 ) &&
( V_150 [ V_184 ] -> V_57 [ V_189 ] == '\0' ) ) {
V_186 = 1 ;
break;
} else
V_184 ++ ;
}
if ( ! V_186 )
break;
if ( V_150 [ V_184 ] -> V_145 ) {
if ( V_161 ) {
V_161 &= V_150 [ V_184 ] -> V_145 ;
if ( ! V_161 ) {
V_186 = 0 ;
break;
}
} else
V_161 = V_150 [ V_184 ] -> V_145 ;
}
if ( V_150 [ V_184 ] -> V_146 ) {
if ( V_162 ) {
V_162 &= V_150 [ V_184 ] -> V_146 ;
if ( ! V_162 ) {
V_186 = 0 ;
break;
}
} else
V_162 = V_150 [ V_184 ] -> V_146 ;
}
if ( V_150 [ V_184 ] -> V_68 ) {
if ( V_163 ) {
V_163 &= V_150 [ V_184 ] -> V_68 ;
if ( ! V_163 ) {
V_186 = 0 ;
break;
}
} else
V_163 = V_150 [ V_184 ] -> V_68 ;
}
if ( V_150 [ V_184 ] -> V_85 ) {
if ( V_164 ) {
V_164 &= V_150 [ V_184 ] -> V_85 ;
if ( ! V_164 ) {
V_186 = 0 ;
break;
}
} else
V_164 = V_150 [ V_184 ] -> V_85 ;
}
if ( V_150 [ V_184 ] -> V_143 & V_172 ) {
if ( V_143 & V_172 ) {
V_143 &=
( V_150 [ V_184 ] -> V_143 & V_172 ) |
~ V_172 ;
if ( ! ( V_143 & V_172 ) ) {
V_186 = 0 ;
break;
}
} else
V_143 |= V_150 [ V_184 ] -> V_143 & V_172 ;
}
if ( V_150 [ V_184 ] -> V_143 & V_173 ) {
if ( V_143 & V_173 ) {
V_143 &=
( V_150 [ V_184 ] -> V_143 & V_173 ) |
~ V_173 ;
if ( ! ( V_143 & V_173 ) ) {
V_186 = 0 ;
break;
}
} else
V_143 |=
V_150 [ V_184 ] -> V_143 & V_173 ;
}
if ( V_150 [ V_184 ] -> V_142 ) {
V_160 = V_150 [ V_184 ] -> V_49 ;
} else {
if ( V_150 [ V_184 ] -> V_147 ) {
if ( V_165 ) {
V_165 &= V_150 [ V_184 ] -> V_147 ;
if ( ! V_165 ) {
V_186 = 0 ;
break;
}
} else
V_165 = V_150 [ V_184 ] -> V_147 ;
}
}
if ( ! V_185 )
break;
}
if ( V_166 == V_191 ) {
V_188 = 0 ;
if ( ( V_189 == 8 ) && ! strncmp ( V_183 , L_13 , 8 ) )
V_188 = F_52 ( V_138 , V_139 ) ;
else
F_53 ( V_192 ,
V_193 ) ;
if ( V_188 == 0 )
V_187 = 0 ;
while ( ( * V_182 != '\0' ) && ! F_55 ( * V_182 ) )
V_182 ++ ;
} else if ( V_186 ) {
F_49 ( V_160 ,
V_161 , V_162 , V_163 , V_164 ,
V_165 , V_143 , V_166 , - 1 , V_138 ,
V_139 ) ;
} else {
while ( ( * V_182 != '\0' ) && ! F_55 ( * V_182 ) )
V_182 ++ ;
}
if ( * V_182 == '\0' )
break;
}
return ( V_187 ) ;
}
static int F_57 ( const T_9 * V_194 , T_10 * V_64 ,
const char * * V_195 )
{
unsigned int V_196 = 0 , V_197 = 0 ;
if ( ! strcmp ( * V_195 , L_14 ) )
V_196 = V_198 ;
else if ( ! strcmp ( * V_195 , L_15 ) )
V_196 = V_199 ;
else if ( ! strcmp ( * V_195 , L_16 ) ) {
V_197 = 1 ;
V_196 = V_198 ;
} else if ( ! strcmp ( * V_195 , L_17 ) )
V_196 = V_200 ;
if ( V_196 ) {
V_64 -> V_201 &= ~ V_198 ;
V_64 -> V_201 |= V_196 ;
} else
V_196 = V_64 -> V_201 & V_198 ;
if ( ! V_196 )
return 1 ;
if ( ! ( V_194 -> V_202 -> V_203 & V_204 ) ) {
if ( V_194 -> V_202 -> V_203 & V_205 )
F_53 ( V_206 ,
V_207 ) ;
else
F_53 ( V_206 ,
V_208 ) ;
return 0 ;
}
# ifndef F_42
switch ( V_196 ) {
case V_198 :
if ( V_197 )
* V_195 = L_18 ;
else
* V_195 =
L_19 ;
break;
case V_199 :
* V_195 = L_20 ;
break;
case V_200 :
* V_195 = L_18 ;
break;
}
V_64 -> V_209 = 1 ;
return 1 ;
# else
F_53 ( V_206 ,
V_210 ) ;
return 0 ;
# endif
}
char * F_58 ( const T_7 * V_64 )
{
if ( V_64 != NULL )
return ( V_64 -> V_57 ) ;
return ( L_21 ) ;
}
int F_59 ( const T_7 * V_64 , int * V_211 )
{
int V_212 = 0 ;
if ( V_64 != NULL ) {
if ( V_211 != NULL )
* V_211 = V_64 -> V_211 ;
V_212 = V_64 -> V_167 ;
}
return ( V_212 ) ;
}
unsigned long F_60 ( const T_7 * V_64 )
{
return V_64 -> V_49 ;
}
void * F_61 ( void )
{
return NULL ;
}
int F_62 ( int V_49 , void * V_213 )
{
return 1 ;
}
const char * F_63 ( const void * V_53 )
{
return NULL ;
}
static void F_64 ( T_3 * V_213 )
{
F_20 ( V_213 ) ;
}
void F_65 ( void )
{
F_66 ( T_3 ) * V_214 = V_52 ;
V_52 = NULL ;
F_67 ( V_214 , F_64 ) ;
}
int F_62 ( int V_49 , T_11 * V_213 )
{
T_3 * V_53 ;
if ( V_213 == NULL || V_213 -> type == V_55 )
return 1 ;
if ( V_49 < 193 || V_49 > 255 ) {
F_53 ( V_215 ,
V_216 ) ;
return 0 ;
}
F_16 () ;
V_53 = ( T_3 * ) F_18 ( sizeof( T_3 ) ) ;
V_53 -> V_49 = V_49 ;
V_53 -> V_54 = V_213 ;
F_12 () ;
if ( V_52 && F_27 ( V_52 , V_53 ) >= 0 ) {
F_20 ( V_53 ) ;
F_23 () ;
F_53 ( V_215 ,
V_217 ) ;
return ( 1 ) ;
} else if ( ( V_52 == NULL )
|| ! F_21 ( V_52 , V_53 ) ) {
F_20 ( V_53 ) ;
F_23 () ;
F_53 ( V_215 , V_180 ) ;
return ( 1 ) ;
} else {
F_23 () ;
return ( 0 ) ;
}
}
const char * F_63 ( const T_11 * V_53 )
{
if ( V_53 )
return V_53 -> V_57 ;
return NULL ;
}
int F_68 ( const T_7 * V_64 )
{
unsigned long V_218 , V_219 ;
V_218 = V_64 -> V_145 ;
V_219 = V_64 -> V_146 ;
if ( V_218 & ( V_122 | V_121 ) ) {
return V_220 ;
} else if ( V_219 & V_120 )
return V_220 ;
else if ( V_218 & V_114 )
return V_221 ;
else if ( V_218 & V_115 )
return V_222 ;
else if ( V_219 & V_113 )
return V_223 ;
else if ( V_219 & V_112 )
return V_224 ;
else if ( V_219 & V_119 )
return - 1 ;
else if ( V_219 & V_127 )
return V_225 ;
else if ( V_219 & V_128 )
return V_226 ;
return - 1 ;
}
const T_7 * F_69 ( T_12 * V_110 , const unsigned char * V_227 )
{
const T_7 * V_64 ;
V_64 = V_110 -> V_54 -> V_228 ( V_227 ) ;
if ( V_64 == NULL || V_64 -> V_142 == 0 )
return NULL ;
return V_64 ;
}
const T_7 * F_70 ( T_12 * V_110 , const unsigned char * V_227 )
{
return V_110 -> V_54 -> V_228 ( V_227 ) ;
}
