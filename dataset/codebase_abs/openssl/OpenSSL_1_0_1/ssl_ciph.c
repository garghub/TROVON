static int F_1 ( const char * V_1 )
{
const T_1 * V_2 ;
int V_3 = 0 ;
V_2 = F_2 ( NULL , V_1 , - 1 ) ;
if ( V_2 )
{
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
if ( V_2 )
{
F_3 ( & V_3 , NULL , NULL , NULL , NULL , V_2 ) ;
}
if ( V_4 ) F_4 ( V_4 ) ;
return V_3 ;
}
void F_5 ( void )
{
V_5 [ V_6 ] =
F_6 ( V_7 ) ;
V_5 [ V_8 ] =
F_6 ( V_9 ) ;
V_5 [ V_10 ] =
F_6 ( V_11 ) ;
V_5 [ V_12 ] =
F_6 ( V_13 ) ;
#ifndef F_7
V_5 [ V_14 ] =
F_6 ( V_15 ) ;
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
V_5 [ V_26 ] =
F_6 ( V_27 ) ;
V_5 [ V_28 ] =
F_6 ( V_29 ) ;
V_5 [ V_30 ] =
F_6 ( V_31 ) ;
V_32 [ V_33 ] =
F_8 ( V_34 ) ;
V_35 [ V_33 ] =
F_9 ( V_32 [ V_33 ] ) ;
F_10 ( V_35 [ V_33 ] >= 0 ) ;
V_32 [ V_36 ] =
F_8 ( V_37 ) ;
V_35 [ V_36 ] =
F_9 ( V_32 [ V_36 ] ) ;
F_10 ( V_35 [ V_36 ] >= 0 ) ;
V_32 [ V_38 ] =
F_8 ( V_39 ) ;
if ( V_32 [ V_38 ] )
{
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
V_32 [ V_43 ] =
F_8 ( V_44 ) ;
V_35 [ V_43 ] =
F_9 ( V_32 [ V_43 ] ) ;
V_32 [ V_45 ] =
F_8 ( V_46 ) ;
V_35 [ V_45 ] =
F_9 ( V_32 [ V_45 ] ) ;
}
static int F_11 ( const T_3 * const * V_47 ,
const T_3 * const * V_48 )
{
return ( ( * V_47 ) -> V_49 - ( * V_48 ) -> V_49 ) ;
}
static void F_12 ( void )
{
int V_50 = 0 ;
F_13 ( V_51 ) ;
if ( V_52 == NULL )
{
F_14 ( V_51 ) ;
F_15 ( V_51 ) ;
V_50 = 1 ;
if ( V_52 == NULL )
{
T_3 * V_53 = NULL ;
F_16 () ;
V_52 = F_17 ( F_11 ) ;
if ( V_52 != NULL )
{
V_53 = ( T_3 * ) F_18 ( sizeof( T_3 ) ) ;
if ( V_53 != NULL )
{
V_53 -> V_54 = F_19 () ;
if ( V_53 -> V_54
&& V_53 -> V_54 -> type == V_55 )
F_20 ( V_53 ) ;
else
{
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
const T_6 * * V_60 , int * V_61 , int * V_62 , T_3 * * V_53 )
{
int V_63 ;
const T_7 * V_64 ;
V_64 = V_58 -> V_65 ;
if ( V_64 == NULL ) return ( 0 ) ;
if ( V_53 != NULL )
{
T_3 V_66 ;
#ifndef F_26
F_12 () ;
#endif
* V_53 = NULL ;
V_66 . V_49 = V_58 -> V_67 ;
if ( V_52 != NULL )
{
V_63 = F_27 ( V_52 , & V_66 ) ;
if ( V_63 >= 0 )
* V_53 = F_28 ( V_52 , V_63 ) ;
else
* V_53 = NULL ;
}
}
if ( ( V_59 == NULL ) || ( V_60 == NULL ) ) return ( 0 ) ;
switch ( V_64 -> V_68 )
{
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
if ( ( V_63 < 0 ) || ( V_63 > V_84 ) )
* V_59 = NULL ;
else
{
if ( V_63 == V_75 )
* V_59 = F_29 () ;
else
* V_59 = V_5 [ V_63 ] ;
}
switch ( V_64 -> V_85 )
{
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
if ( ( V_63 < 0 ) || ( V_63 > V_92 ) )
{
* V_60 = NULL ;
if ( V_61 != NULL ) * V_61 = V_55 ;
if ( V_62 != NULL ) * V_62 = 0 ;
if ( V_64 -> V_85 == V_93 )
V_61 = NULL ;
}
else
{
* V_60 = V_32 [ V_63 ] ;
if ( V_61 != NULL ) * V_61 = V_42 [ V_63 ] ;
if ( V_62 != NULL ) * V_62 = V_35 [ V_63 ] ;
}
if ( ( * V_59 != NULL ) &&
( * V_60 != NULL || ( F_30 ( * V_59 ) & V_94 ) ) &&
( ! V_61 || * V_61 != V_55 ) )
{
const T_5 * V_95 ;
if ( V_58 -> V_96 >= V_97 &&
V_64 -> V_68 == V_71 &&
V_64 -> V_85 == V_86 &&
( V_95 = F_6 ( L_2 ) ) )
* V_59 = V_95 , * V_60 = NULL ;
else if ( V_58 -> V_96 >= V_97 &&
V_64 -> V_68 == V_76 &&
V_64 -> V_85 == V_87 &&
( V_95 = F_6 ( L_3 ) ) )
* V_59 = V_95 , * V_60 = NULL ;
else if ( V_58 -> V_96 >= V_97 &&
V_64 -> V_68 == V_77 &&
V_64 -> V_85 == V_87 &&
( V_95 = F_6 ( L_4 ) ) )
* V_59 = V_95 , * V_60 = NULL ;
return ( 1 ) ;
}
else
return ( 0 ) ;
}
int F_31 ( int V_98 , long * V_99 , const T_6 * * V_60 )
{
if ( V_98 < 0 || V_98 >= V_92 )
{
return 0 ;
}
* V_99 = V_100 [ V_98 ] ;
if ( * V_99 )
* V_60 = V_32 [ V_98 ] ;
else
* V_60 = NULL ;
return 1 ;
}
static void F_32 ( T_8 * * V_101 , T_8 * V_102 ,
T_8 * * V_103 )
{
if ( V_102 == * V_103 ) return;
if ( V_102 == * V_101 )
* V_101 = V_102 -> V_104 ;
if ( V_102 -> V_105 != NULL )
V_102 -> V_105 -> V_104 = V_102 -> V_104 ;
if ( V_102 -> V_104 != NULL )
V_102 -> V_104 -> V_105 = V_102 -> V_105 ;
( * V_103 ) -> V_104 = V_102 ;
V_102 -> V_105 = * V_103 ;
V_102 -> V_104 = NULL ;
* V_103 = V_102 ;
}
static void F_33 ( T_8 * * V_101 , T_8 * V_102 ,
T_8 * * V_103 )
{
if ( V_102 == * V_101 ) return;
if ( V_102 == * V_103 )
* V_103 = V_102 -> V_105 ;
if ( V_102 -> V_104 != NULL )
V_102 -> V_104 -> V_105 = V_102 -> V_105 ;
if ( V_102 -> V_105 != NULL )
V_102 -> V_105 -> V_104 = V_102 -> V_104 ;
( * V_101 ) -> V_105 = V_102 ;
V_102 -> V_104 = * V_101 ;
V_102 -> V_105 = NULL ;
* V_101 = V_102 ;
}
static void F_34 ( unsigned long * V_106 , unsigned long * V_107 , unsigned long * V_59 , unsigned long * V_108 , unsigned long * V_109 )
{
* V_106 = 0 ;
* V_107 = 0 ;
* V_59 = 0 ;
* V_108 = 0 ;
* V_109 = 0 ;
#ifdef F_35
* V_106 |= V_110 ;
* V_107 |= V_111 ;
#endif
#ifdef F_36
* V_107 |= V_112 ;
#endif
* V_106 |= V_113 | V_114 ;
* V_107 |= V_115 ;
#ifdef F_37
* V_106 |= V_113 | V_114 | V_116 ;
* V_107 |= V_115 ;
#endif
#ifdef F_38
* V_106 |= V_117 ;
* V_107 |= V_118 ;
#endif
#ifdef F_39
* V_107 |= V_119 ;
#endif
#ifdef F_40
* V_106 |= V_120 | V_121 ;
* V_107 |= V_122 ;
#endif
#ifdef F_41
* V_106 |= V_123 ;
* V_107 |= V_124 ;
#endif
#ifdef F_42
* V_106 |= V_125 ;
#endif
if ( ! F_1 ( L_5 ) ) {
* V_107 |= V_126 ;
}
if ( ! F_1 ( L_6 ) ) {
* V_107 |= V_127 ;
}
if ( ( * V_107 & ( V_126 | V_127 ) ) == ( V_126 | V_127 ) ) {
* V_106 |= V_128 ;
}
#ifdef F_43
* V_59 |= V_74 ;
#endif
* V_59 |= ( V_5 [ V_6 ] == NULL ) ? V_69 : 0 ;
* V_59 |= ( V_5 [ V_8 ] == NULL ) ? V_70 : 0 ;
* V_59 |= ( V_5 [ V_10 ] == NULL ) ? V_71 : 0 ;
* V_59 |= ( V_5 [ V_12 ] == NULL ) ? V_72 : 0 ;
* V_59 |= ( V_5 [ V_14 ] == NULL ) ? V_73 : 0 ;
* V_59 |= ( V_5 [ V_16 ] == NULL ) ? V_76 : 0 ;
* V_59 |= ( V_5 [ V_18 ] == NULL ) ? V_77 : 0 ;
* V_59 |= ( V_5 [ V_28 ] == NULL ) ? V_82 : 0 ;
* V_59 |= ( V_5 [ V_30 ] == NULL ) ? V_83 : 0 ;
* V_59 |= ( V_5 [ V_20 ] == NULL ) ? V_78 : 0 ;
* V_59 |= ( V_5 [ V_22 ] == NULL ) ? V_79 : 0 ;
* V_59 |= ( V_5 [ V_24 ] == NULL ) ? V_80 : 0 ;
* V_59 |= ( V_5 [ V_26 ] == NULL ) ? V_81 : 0 ;
* V_108 |= ( V_32 [ V_33 ] == NULL ) ? V_86 : 0 ;
* V_108 |= ( V_32 [ V_36 ] == NULL ) ? V_87 : 0 ;
* V_108 |= ( V_32 [ V_43 ] == NULL ) ? V_88 : 0 ;
* V_108 |= ( V_32 [ V_45 ] == NULL ) ? V_89 : 0 ;
* V_108 |= ( V_32 [ V_38 ] == NULL ) ? V_90 : 0 ;
* V_108 |= ( V_32 [ V_40 ] == NULL || V_42 [ V_40 ] == V_55 ) ? V_91 : 0 ;
}
static void F_44 ( const T_9 * V_129 ,
int V_130 ,
unsigned long V_131 , unsigned long V_132 ,
unsigned long V_133 , unsigned long V_134 ,
unsigned long V_135 ,
T_8 * V_136 ,
T_8 * * V_137 , T_8 * * V_138 )
{
int V_63 , V_139 ;
const T_7 * V_64 ;
V_139 = 0 ;
for ( V_63 = 0 ; V_63 < V_130 ; V_63 ++ )
{
V_64 = V_129 -> V_140 ( V_63 ) ;
if ( ( V_64 != NULL ) && V_64 -> V_141 &&
#ifdef F_45
( ! F_46 () || ( V_64 -> V_142 & V_143 ) ) &&
#endif
! ( V_64 -> V_144 & V_131 ) &&
! ( V_64 -> V_145 & V_132 ) &&
! ( V_64 -> V_68 & V_133 ) &&
! ( V_64 -> V_85 & V_134 ) &&
! ( V_64 -> V_146 & V_135 ) )
{
V_136 [ V_139 ] . V_65 = V_64 ;
V_136 [ V_139 ] . V_104 = NULL ;
V_136 [ V_139 ] . V_105 = NULL ;
V_136 [ V_139 ] . V_147 = 0 ;
V_139 ++ ;
#ifdef F_47
printf ( L_7 , V_63 , V_64 -> V_57 , V_64 -> V_49 , V_64 -> V_144 , V_64 -> V_145 ) ;
#endif
}
}
if ( V_139 > 0 )
{
V_136 [ 0 ] . V_105 = NULL ;
if ( V_139 > 1 )
{
V_136 [ 0 ] . V_104 = & V_136 [ 1 ] ;
for ( V_63 = 1 ; V_63 < V_139 - 1 ; V_63 ++ )
{
V_136 [ V_63 ] . V_105 = & V_136 [ V_63 - 1 ] ;
V_136 [ V_63 ] . V_104 = & V_136 [ V_63 + 1 ] ;
}
V_136 [ V_139 - 1 ] . V_105 = & V_136 [ V_139 - 2 ] ;
}
V_136 [ V_139 - 1 ] . V_104 = NULL ;
* V_137 = & V_136 [ 0 ] ;
* V_138 = & V_136 [ V_139 - 1 ] ;
}
}
static void F_48 ( const T_7 * * V_148 ,
int V_149 ,
unsigned long V_131 , unsigned long V_132 ,
unsigned long V_133 , unsigned long V_134 ,
unsigned long V_135 ,
T_8 * V_101 )
{
T_8 * V_150 ;
const T_7 * * V_151 ;
int V_63 ;
unsigned long V_152 = ~ V_131 ;
unsigned long V_153 = ~ V_132 ;
unsigned long V_154 = ~ V_133 ;
unsigned long V_155 = ~ V_134 ;
unsigned long V_156 = ~ V_135 ;
V_150 = V_101 ;
V_151 = V_148 ;
while ( V_150 != NULL )
{
* V_151 = V_150 -> V_65 ;
V_151 ++ ;
V_150 = V_150 -> V_104 ;
}
for ( V_63 = 0 ; V_63 < V_149 ; V_63 ++ )
{
unsigned long V_144 = V_157 [ V_63 ] . V_144 ;
unsigned long V_145 = V_157 [ V_63 ] . V_145 ;
unsigned long V_68 = V_157 [ V_63 ] . V_68 ;
unsigned long V_85 = V_157 [ V_63 ] . V_85 ;
unsigned long V_146 = V_157 [ V_63 ] . V_146 ;
if ( V_144 )
if ( ( V_144 & V_152 ) == 0 )
continue;
if ( V_145 )
if ( ( V_145 & V_153 ) == 0 )
continue;
if ( V_68 )
if ( ( V_68 & V_154 ) == 0 )
continue;
if ( V_85 )
if ( ( V_85 & V_155 ) == 0 )
continue;
if ( V_146 )
if ( ( V_146 & V_156 ) == 0 )
continue;
* V_151 = ( T_7 * ) ( V_157 + V_63 ) ;
V_151 ++ ;
}
* V_151 = NULL ;
}
static void F_49 ( unsigned long V_158 ,
unsigned long V_159 , unsigned long V_160 ,
unsigned long V_161 , unsigned long V_162 ,
unsigned long V_163 ,
unsigned long V_142 ,
int V_164 , int V_165 ,
T_8 * * V_137 , T_8 * * V_138 )
{
T_8 * V_101 , * V_103 , * V_102 , * V_166 , * V_167 ;
const T_7 * V_168 ;
int V_169 = 0 ;
#ifdef F_50
printf ( L_8 ,
V_164 , V_159 , V_160 , V_161 , V_162 , V_163 , V_142 , V_165 ) ;
#endif
if ( V_164 == V_170 )
V_169 = 1 ;
V_101 = * V_137 ;
V_103 = * V_138 ;
if ( V_169 )
{
V_102 = V_103 ;
V_167 = V_101 ;
}
else
{
V_102 = V_101 ;
V_167 = V_103 ;
}
V_166 = V_102 ;
for (; ; )
{
if ( ( V_102 == NULL ) || ( V_102 == V_167 ) ) break;
V_102 = V_166 ;
V_166 = V_169 ? V_102 -> V_105 : V_102 -> V_104 ;
V_168 = V_102 -> V_65 ;
if ( V_165 >= 0 )
{
if ( V_165 != V_168 -> V_165 )
continue;
}
else
{
#ifdef F_50
printf ( L_9 , V_168 -> V_57 , V_168 -> V_144 , V_168 -> V_145 , V_168 -> V_68 , V_168 -> V_85 , V_168 -> V_146 , V_168 -> V_142 ) ;
#endif
if ( V_159 && ! ( V_159 & V_168 -> V_144 ) )
continue;
if ( V_160 && ! ( V_160 & V_168 -> V_145 ) )
continue;
if ( V_161 && ! ( V_161 & V_168 -> V_68 ) )
continue;
if ( V_162 && ! ( V_162 & V_168 -> V_85 ) )
continue;
if ( V_163 && ! ( V_163 & V_168 -> V_146 ) )
continue;
if ( ( V_142 & V_171 ) && ! ( V_142 & V_171 & V_168 -> V_142 ) )
continue;
if ( ( V_142 & V_172 ) && ! ( V_142 & V_172 & V_168 -> V_142 ) )
continue;
}
#ifdef F_50
printf ( L_10 , V_164 ) ;
#endif
if ( V_164 == V_173 )
{
if ( ! V_102 -> V_147 )
{
F_32 ( & V_101 , V_102 , & V_103 ) ;
V_102 -> V_147 = 1 ;
}
}
else if ( V_164 == V_174 )
{
if ( V_102 -> V_147 )
{
F_32 ( & V_101 , V_102 , & V_103 ) ;
}
}
else if ( V_164 == V_170 )
{
if ( V_102 -> V_147 )
{
F_33 ( & V_101 , V_102 , & V_103 ) ;
V_102 -> V_147 = 0 ;
}
}
else if ( V_164 == V_175 )
{
if ( V_101 == V_102 )
V_101 = V_102 -> V_104 ;
else
V_102 -> V_105 -> V_104 = V_102 -> V_104 ;
if ( V_103 == V_102 )
V_103 = V_102 -> V_105 ;
V_102 -> V_147 = 0 ;
if ( V_102 -> V_104 != NULL )
V_102 -> V_104 -> V_105 = V_102 -> V_105 ;
if ( V_102 -> V_105 != NULL )
V_102 -> V_105 -> V_104 = V_102 -> V_104 ;
V_102 -> V_104 = NULL ;
V_102 -> V_105 = NULL ;
}
}
* V_137 = V_101 ;
* V_138 = V_103 ;
}
static int F_51 ( T_8 * * V_137 ,
T_8 * * V_138 )
{
int V_176 , V_63 , * V_177 ;
T_8 * V_102 ;
V_176 = 0 ;
V_102 = * V_137 ;
while ( V_102 != NULL )
{
if ( V_102 -> V_147 &&
( V_102 -> V_65 -> V_165 > V_176 ) )
V_176 = V_102 -> V_65 -> V_165 ;
V_102 = V_102 -> V_104 ;
}
V_177 = F_18 ( ( V_176 + 1 ) * sizeof( int ) ) ;
if ( ! V_177 )
{
F_52 ( V_178 , V_179 ) ;
return ( 0 ) ;
}
memset ( V_177 , 0 , ( V_176 + 1 ) * sizeof( int ) ) ;
V_102 = * V_137 ;
while ( V_102 != NULL )
{
if ( V_102 -> V_147 )
V_177 [ V_102 -> V_65 -> V_165 ] ++ ;
V_102 = V_102 -> V_104 ;
}
for ( V_63 = V_176 ; V_63 >= 0 ; V_63 -- )
if ( V_177 [ V_63 ] > 0 )
F_49 ( 0 , 0 , 0 , 0 , 0 , 0 , 0 , V_174 , V_63 , V_137 , V_138 ) ;
F_20 ( V_177 ) ;
return ( 1 ) ;
}
static int F_53 ( const char * V_180 ,
T_8 * * V_137 , T_8 * * V_138 ,
const T_7 * * V_148 )
{
unsigned long V_159 , V_160 , V_161 , V_162 , V_163 , V_142 ;
const char * V_181 , * V_182 ;
int V_183 , V_184 , V_185 , V_164 , V_186 , V_187 , V_188 ;
unsigned long V_158 = 0 ;
char V_189 ;
V_186 = 1 ;
V_181 = V_180 ;
for (; ; )
{
V_189 = * V_181 ;
if ( V_189 == '\0' )
break;
if ( V_189 == '-' )
{ V_164 = V_170 ; V_181 ++ ; }
else if ( V_189 == '+' )
{ V_164 = V_174 ; V_181 ++ ; }
else if ( V_189 == '!' )
{ V_164 = V_175 ; V_181 ++ ; }
else if ( V_189 == '@' )
{ V_164 = V_190 ; V_181 ++ ; }
else
{ V_164 = V_173 ; }
if ( F_54 ( V_189 ) )
{
V_181 ++ ;
continue;
}
V_159 = 0 ;
V_160 = 0 ;
V_161 = 0 ;
V_162 = 0 ;
V_163 = 0 ;
V_142 = 0 ;
for (; ; )
{
V_189 = * V_181 ;
V_182 = V_181 ;
V_188 = 0 ;
#ifndef F_55
while ( ( ( V_189 >= 'A' ) && ( V_189 <= 'Z' ) ) ||
( ( V_189 >= '0' ) && ( V_189 <= '9' ) ) ||
( ( V_189 >= 'a' ) && ( V_189 <= 'z' ) ) ||
( V_189 == '-' ) )
#else
while ( isalnum ( V_189 ) || ( V_189 == '-' ) )
#endif
{
V_189 = * ( ++ V_181 ) ;
V_188 ++ ;
}
if ( V_188 == 0 )
{
F_52 ( V_191 ,
V_192 ) ;
V_186 = V_185 = 0 ;
V_181 ++ ;
break;
}
if ( V_164 == V_190 )
{
V_185 = 0 ;
break;
}
if ( V_189 == '+' )
{
V_184 = 1 ;
V_181 ++ ;
}
else
V_184 = 0 ;
V_183 = V_185 = 0 ;
V_158 = 0 ;
while ( V_148 [ V_183 ] )
{
if ( ! strncmp ( V_182 , V_148 [ V_183 ] -> V_57 , V_188 ) &&
( V_148 [ V_183 ] -> V_57 [ V_188 ] == '\0' ) )
{
V_185 = 1 ;
break;
}
else
V_183 ++ ;
}
if ( ! V_185 )
break;
if ( V_148 [ V_183 ] -> V_144 )
{
if ( V_159 )
{
V_159 &= V_148 [ V_183 ] -> V_144 ;
if ( ! V_159 ) { V_185 = 0 ; break; }
}
else
V_159 = V_148 [ V_183 ] -> V_144 ;
}
if ( V_148 [ V_183 ] -> V_145 )
{
if ( V_160 )
{
V_160 &= V_148 [ V_183 ] -> V_145 ;
if ( ! V_160 ) { V_185 = 0 ; break; }
}
else
V_160 = V_148 [ V_183 ] -> V_145 ;
}
if ( V_148 [ V_183 ] -> V_68 )
{
if ( V_161 )
{
V_161 &= V_148 [ V_183 ] -> V_68 ;
if ( ! V_161 ) { V_185 = 0 ; break; }
}
else
V_161 = V_148 [ V_183 ] -> V_68 ;
}
if ( V_148 [ V_183 ] -> V_85 )
{
if ( V_162 )
{
V_162 &= V_148 [ V_183 ] -> V_85 ;
if ( ! V_162 ) { V_185 = 0 ; break; }
}
else
V_162 = V_148 [ V_183 ] -> V_85 ;
}
if ( V_148 [ V_183 ] -> V_142 & V_171 )
{
if ( V_142 & V_171 )
{
V_142 &= ( V_148 [ V_183 ] -> V_142 & V_171 ) | ~ V_171 ;
if ( ! ( V_142 & V_171 ) ) { V_185 = 0 ; break; }
}
else
V_142 |= V_148 [ V_183 ] -> V_142 & V_171 ;
}
if ( V_148 [ V_183 ] -> V_142 & V_172 )
{
if ( V_142 & V_172 )
{
V_142 &= ( V_148 [ V_183 ] -> V_142 & V_172 ) | ~ V_172 ;
if ( ! ( V_142 & V_172 ) ) { V_185 = 0 ; break; }
}
else
V_142 |= V_148 [ V_183 ] -> V_142 & V_172 ;
}
if ( V_148 [ V_183 ] -> V_141 )
{
V_158 = V_148 [ V_183 ] -> V_49 ;
}
else
{
if ( V_148 [ V_183 ] -> V_146 )
{
if ( V_163 )
{
V_163 &= V_148 [ V_183 ] -> V_146 ;
if ( ! V_163 ) { V_185 = 0 ; break; }
}
else
V_163 = V_148 [ V_183 ] -> V_146 ;
}
}
if ( ! V_184 ) break;
}
if ( V_164 == V_190 )
{
V_187 = 0 ;
if ( ( V_188 == 8 ) &&
! strncmp ( V_182 , L_11 , 8 ) )
V_187 = F_51 ( V_137 , V_138 ) ;
else
F_52 ( V_191 ,
V_192 ) ;
if ( V_187 == 0 )
V_186 = 0 ;
while ( ( * V_181 != '\0' ) && ! F_54 ( * V_181 ) )
V_181 ++ ;
}
else if ( V_185 )
{
F_49 ( V_158 ,
V_159 , V_160 , V_161 , V_162 , V_163 , V_142 ,
V_164 , - 1 , V_137 , V_138 ) ;
}
else
{
while ( ( * V_181 != '\0' ) && ! F_54 ( * V_181 ) )
V_181 ++ ;
}
if ( * V_181 == '\0' ) break;
}
return ( V_186 ) ;
}
char * F_56 ( const T_7 * V_64 )
{
if ( V_64 != NULL )
return ( V_64 -> V_57 ) ;
return ( L_12 ) ;
}
int F_57 ( const T_7 * V_64 , int * V_193 )
{
int V_194 = 0 ;
if ( V_64 != NULL )
{
if ( V_193 != NULL ) * V_193 = V_64 -> V_193 ;
V_194 = V_64 -> V_165 ;
}
return ( V_194 ) ;
}
unsigned long F_58 ( const T_7 * V_64 )
{
return V_64 -> V_49 ;
}
void * F_59 ( void )
{
return NULL ;
}
int F_60 ( int V_49 , void * V_195 )
{
return 1 ;
}
const char * F_61 ( const void * V_53 )
{
return NULL ;
}
int F_60 ( int V_49 , T_10 * V_195 )
{
T_3 * V_53 ;
if ( V_195 == NULL || V_195 -> type == V_55 )
return 1 ;
if ( V_49 < 193 || V_49 > 255 )
{
F_52 ( V_196 , V_197 ) ;
return 0 ;
}
F_16 () ;
V_53 = ( T_3 * ) F_18 ( sizeof( T_3 ) ) ;
V_53 -> V_49 = V_49 ;
V_53 -> V_54 = V_195 ;
F_12 () ;
if ( V_52
&& F_27 ( V_52 , V_53 ) >= 0 )
{
F_20 ( V_53 ) ;
F_23 () ;
F_52 ( V_196 , V_198 ) ;
return ( 1 ) ;
}
else if ( ( V_52 == NULL )
|| ! F_21 ( V_52 , V_53 ) )
{
F_20 ( V_53 ) ;
F_23 () ;
F_52 ( V_196 , V_179 ) ;
return ( 1 ) ;
}
else
{
F_23 () ;
return ( 0 ) ;
}
}
const char * F_61 ( const T_10 * V_53 )
{
if ( V_53 )
return V_53 -> V_57 ;
return NULL ;
}
