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
V_28 [ V_29 ] =
F_8 ( V_30 ) ;
V_31 [ V_29 ] =
F_9 ( V_28 [ V_29 ] ) ;
F_10 ( V_31 [ V_29 ] >= 0 ) ;
V_28 [ V_32 ] =
F_8 ( V_33 ) ;
V_31 [ V_32 ] =
F_9 ( V_28 [ V_32 ] ) ;
F_10 ( V_31 [ V_32 ] >= 0 ) ;
V_28 [ V_34 ] =
F_8 ( V_35 ) ;
if ( V_28 [ V_34 ] )
{
V_31 [ V_34 ] =
F_9 ( V_28 [ V_34 ] ) ;
F_10 ( V_31 [ V_34 ] >= 0 ) ;
}
V_28 [ V_36 ] =
F_8 ( V_37 ) ;
V_38 [ V_36 ] = F_1 ( L_1 ) ;
if ( V_38 [ V_36 ] ) {
V_31 [ V_36 ] = 32 ;
}
}
static int F_11 ( const T_3 * const * V_39 ,
const T_3 * const * V_40 )
{
return ( ( * V_39 ) -> V_41 - ( * V_40 ) -> V_41 ) ;
}
static void F_12 ( void )
{
int V_42 = 0 ;
F_13 ( V_43 ) ;
if ( V_44 == NULL )
{
F_14 ( V_43 ) ;
F_15 ( V_43 ) ;
V_42 = 1 ;
if ( V_44 == NULL )
{
T_3 * V_45 = NULL ;
F_16 () ;
V_44 = F_17 ( F_11 ) ;
if ( V_44 != NULL )
{
V_45 = ( T_3 * ) F_18 ( sizeof( T_3 ) ) ;
if ( V_45 != NULL )
{
V_45 -> V_46 = F_19 () ;
if ( V_45 -> V_46
&& V_45 -> V_46 -> type == V_47 )
F_20 ( V_45 ) ;
else
{
V_45 -> V_41 = V_48 ;
V_45 -> V_49 = V_45 -> V_46 -> V_49 ;
F_21 ( V_44 , V_45 ) ;
}
}
}
F_22 () ;
}
}
if ( V_42 )
F_23 ( V_43 ) ;
else
F_14 ( V_43 ) ;
}
int F_24 ( const T_4 * V_50 , const T_5 * * V_51 ,
const T_6 * * V_52 , int * V_53 , int * V_54 , T_3 * * V_45 )
{
int V_55 ;
const T_7 * V_56 ;
V_56 = V_50 -> V_57 ;
if ( V_56 == NULL ) return ( 0 ) ;
if ( V_45 != NULL )
{
T_3 V_58 ;
#ifndef F_25
F_12 () ;
#endif
* V_45 = NULL ;
V_58 . V_41 = V_50 -> V_59 ;
if ( V_44 != NULL )
{
V_55 = F_26 ( V_44 , & V_58 ) ;
if ( V_55 >= 0 )
* V_45 = F_27 ( V_44 , V_55 ) ;
else
* V_45 = NULL ;
}
}
if ( ( V_51 == NULL ) || ( V_52 == NULL ) ) return ( 0 ) ;
switch ( V_56 -> V_60 )
{
case V_61 :
V_55 = V_6 ;
break;
case V_62 :
V_55 = V_8 ;
break;
case V_63 :
V_55 = V_10 ;
break;
case V_64 :
V_55 = V_12 ;
break;
case V_65 :
V_55 = V_14 ;
break;
case V_66 :
V_55 = V_67 ;
break;
case V_68 :
V_55 = V_16 ;
break;
case V_69 :
V_55 = V_18 ;
break;
case V_70 :
V_55 = V_20 ;
break;
case V_71 :
V_55 = V_22 ;
break;
case V_72 :
V_55 = V_24 ;
break;
case V_73 :
V_55 = V_26 ;
break;
default:
V_55 = - 1 ;
break;
}
if ( ( V_55 < 0 ) || ( V_55 > V_74 ) )
* V_51 = NULL ;
else
{
if ( V_55 == V_67 )
* V_51 = F_28 () ;
else
* V_51 = V_5 [ V_55 ] ;
}
switch ( V_56 -> V_75 )
{
case V_76 :
V_55 = V_29 ;
break;
case V_77 :
V_55 = V_32 ;
break;
case V_78 :
V_55 = V_34 ;
break;
case V_79 :
V_55 = V_36 ;
break;
default:
V_55 = - 1 ;
break;
}
if ( ( V_55 < 0 ) || ( V_55 > V_80 ) )
{
* V_52 = NULL ;
if ( V_53 != NULL ) * V_53 = V_47 ;
if ( V_54 != NULL ) * V_54 = 0 ;
}
else
{
* V_52 = V_28 [ V_55 ] ;
if ( V_53 != NULL ) * V_53 = V_38 [ V_55 ] ;
if ( V_54 != NULL ) * V_54 = V_31 [ V_55 ] ;
}
if ( ( * V_51 != NULL ) && ( * V_52 != NULL ) && ( ! V_53 || * V_53 != V_47 ) )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_29 ( int V_81 , long * V_82 , const T_6 * * V_52 )
{
if ( V_81 < 0 || V_81 >= V_80 )
{
return 0 ;
}
if ( V_83 [ V_81 ] == 0 ) return 0 ;
* V_82 = V_83 [ V_81 ] ;
* V_52 = V_28 [ V_81 ] ;
return 1 ;
}
static void F_30 ( T_8 * * V_84 , T_8 * V_85 ,
T_8 * * V_86 )
{
if ( V_85 == * V_86 ) return;
if ( V_85 == * V_84 )
* V_84 = V_85 -> V_87 ;
if ( V_85 -> V_88 != NULL )
V_85 -> V_88 -> V_87 = V_85 -> V_87 ;
if ( V_85 -> V_87 != NULL )
V_85 -> V_87 -> V_88 = V_85 -> V_88 ;
( * V_86 ) -> V_87 = V_85 ;
V_85 -> V_88 = * V_86 ;
V_85 -> V_87 = NULL ;
* V_86 = V_85 ;
}
static void F_31 ( T_8 * * V_84 , T_8 * V_85 ,
T_8 * * V_86 )
{
if ( V_85 == * V_84 ) return;
if ( V_85 == * V_86 )
* V_86 = V_85 -> V_88 ;
if ( V_85 -> V_87 != NULL )
V_85 -> V_87 -> V_88 = V_85 -> V_88 ;
if ( V_85 -> V_88 != NULL )
V_85 -> V_88 -> V_87 = V_85 -> V_87 ;
( * V_84 ) -> V_88 = V_85 ;
V_85 -> V_87 = * V_84 ;
V_85 -> V_88 = NULL ;
* V_84 = V_85 ;
}
static void F_32 ( unsigned long * V_89 , unsigned long * V_90 , unsigned long * V_51 , unsigned long * V_91 , unsigned long * V_92 )
{
* V_89 = 0 ;
* V_90 = 0 ;
* V_51 = 0 ;
* V_91 = 0 ;
* V_92 = 0 ;
#ifdef F_33
* V_89 |= V_93 ;
* V_90 |= V_94 ;
#endif
#ifdef F_34
* V_90 |= V_95 ;
#endif
* V_89 |= V_96 | V_97 ;
* V_90 |= V_98 ;
#ifdef F_35
* V_89 |= V_96 | V_97 | V_99 ;
* V_90 |= V_98 ;
#endif
#ifdef F_36
* V_89 |= V_100 ;
* V_90 |= V_101 ;
#endif
#ifdef F_37
* V_90 |= V_102 ;
#endif
#ifdef F_38
* V_89 |= V_103 | V_104 ;
* V_90 |= V_105 ;
#endif
#ifdef F_39
* V_89 |= V_106 ;
* V_90 |= V_107 ;
#endif
if ( ! F_1 ( L_2 ) ) {
* V_90 |= V_108 ;
}
if ( ! F_1 ( L_3 ) ) {
* V_90 |= V_109 ;
}
if ( ( * V_90 & ( V_108 | V_109 ) ) == ( V_108 | V_109 ) ) {
* V_89 |= V_110 ;
}
#ifdef F_40
* V_51 |= V_66 ;
#endif
* V_51 |= ( V_5 [ V_6 ] == NULL ) ? V_61 : 0 ;
* V_51 |= ( V_5 [ V_8 ] == NULL ) ? V_62 : 0 ;
* V_51 |= ( V_5 [ V_10 ] == NULL ) ? V_63 : 0 ;
* V_51 |= ( V_5 [ V_12 ] == NULL ) ? V_64 : 0 ;
* V_51 |= ( V_5 [ V_14 ] == NULL ) ? V_65 : 0 ;
* V_51 |= ( V_5 [ V_16 ] == NULL ) ? V_68 : 0 ;
* V_51 |= ( V_5 [ V_18 ] == NULL ) ? V_69 : 0 ;
* V_51 |= ( V_5 [ V_20 ] == NULL ) ? V_70 : 0 ;
* V_51 |= ( V_5 [ V_22 ] == NULL ) ? V_71 : 0 ;
* V_51 |= ( V_5 [ V_24 ] == NULL ) ? V_72 : 0 ;
* V_51 |= ( V_5 [ V_26 ] == NULL ) ? V_73 : 0 ;
* V_91 |= ( V_28 [ V_29 ] == NULL ) ? V_76 : 0 ;
* V_91 |= ( V_28 [ V_32 ] == NULL ) ? V_77 : 0 ;
* V_91 |= ( V_28 [ V_34 ] == NULL ) ? V_78 : 0 ;
* V_91 |= ( V_28 [ V_36 ] == NULL || V_38 [ V_36 ] == V_47 ) ? V_79 : 0 ;
}
static void F_41 ( const T_9 * V_111 ,
int V_112 ,
unsigned long V_113 , unsigned long V_114 ,
unsigned long V_115 , unsigned long V_116 ,
unsigned long V_117 ,
T_8 * V_118 ,
T_8 * * V_119 , T_8 * * V_120 )
{
int V_55 , V_121 ;
const T_7 * V_56 ;
V_121 = 0 ;
for ( V_55 = 0 ; V_55 < V_112 ; V_55 ++ )
{
V_56 = V_111 -> V_122 ( V_55 ) ;
if ( ( V_56 != NULL ) && V_56 -> V_123 &&
! ( V_56 -> V_124 & V_113 ) &&
! ( V_56 -> V_125 & V_114 ) &&
! ( V_56 -> V_60 & V_115 ) &&
! ( V_56 -> V_75 & V_116 ) &&
! ( V_56 -> V_126 & V_117 ) )
{
V_118 [ V_121 ] . V_57 = V_56 ;
V_118 [ V_121 ] . V_87 = NULL ;
V_118 [ V_121 ] . V_88 = NULL ;
V_118 [ V_121 ] . V_127 = 0 ;
V_121 ++ ;
#ifdef F_42
printf ( L_4 , V_55 , V_56 -> V_49 , V_56 -> V_41 , V_56 -> V_124 , V_56 -> V_125 ) ;
#endif
}
}
if ( V_121 > 0 )
{
V_118 [ 0 ] . V_88 = NULL ;
if ( V_121 > 1 )
{
V_118 [ 0 ] . V_87 = & V_118 [ 1 ] ;
for ( V_55 = 1 ; V_55 < V_121 - 1 ; V_55 ++ )
{
V_118 [ V_55 ] . V_88 = & V_118 [ V_55 - 1 ] ;
V_118 [ V_55 ] . V_87 = & V_118 [ V_55 + 1 ] ;
}
V_118 [ V_121 - 1 ] . V_88 = & V_118 [ V_121 - 2 ] ;
}
V_118 [ V_121 - 1 ] . V_87 = NULL ;
* V_119 = & V_118 [ 0 ] ;
* V_120 = & V_118 [ V_121 - 1 ] ;
}
}
static void F_43 ( const T_7 * * V_128 ,
int V_129 ,
unsigned long V_113 , unsigned long V_114 ,
unsigned long V_115 , unsigned long V_116 ,
unsigned long V_117 ,
T_8 * V_84 )
{
T_8 * V_130 ;
const T_7 * * V_131 ;
int V_55 ;
unsigned long V_132 = ~ V_113 ;
unsigned long V_133 = ~ V_114 ;
unsigned long V_134 = ~ V_115 ;
unsigned long V_135 = ~ V_116 ;
unsigned long V_136 = ~ V_117 ;
V_130 = V_84 ;
V_131 = V_128 ;
while ( V_130 != NULL )
{
* V_131 = V_130 -> V_57 ;
V_131 ++ ;
V_130 = V_130 -> V_87 ;
}
for ( V_55 = 0 ; V_55 < V_129 ; V_55 ++ )
{
unsigned long V_124 = V_137 [ V_55 ] . V_124 ;
unsigned long V_125 = V_137 [ V_55 ] . V_125 ;
unsigned long V_60 = V_137 [ V_55 ] . V_60 ;
unsigned long V_75 = V_137 [ V_55 ] . V_75 ;
unsigned long V_126 = V_137 [ V_55 ] . V_126 ;
if ( V_124 )
if ( ( V_124 & V_132 ) == 0 )
continue;
if ( V_125 )
if ( ( V_125 & V_133 ) == 0 )
continue;
if ( V_60 )
if ( ( V_60 & V_134 ) == 0 )
continue;
if ( V_75 )
if ( ( V_75 & V_135 ) == 0 )
continue;
if ( V_126 )
if ( ( V_126 & V_136 ) == 0 )
continue;
* V_131 = ( T_7 * ) ( V_137 + V_55 ) ;
V_131 ++ ;
}
* V_131 = NULL ;
}
static void F_44 ( unsigned long V_138 ,
unsigned long V_139 , unsigned long V_140 ,
unsigned long V_141 , unsigned long V_142 ,
unsigned long V_143 ,
unsigned long V_144 ,
int V_145 , int V_146 ,
T_8 * * V_119 , T_8 * * V_120 )
{
T_8 * V_84 , * V_86 , * V_85 , * V_147 , * V_148 ;
const T_7 * V_149 ;
int V_150 = 0 ;
#ifdef F_45
printf ( L_5 ,
V_145 , V_139 , V_140 , V_141 , V_142 , V_143 , V_144 , V_146 ) ;
#endif
if ( V_145 == V_151 )
V_150 = 1 ;
V_84 = * V_119 ;
V_86 = * V_120 ;
if ( V_150 )
{
V_85 = V_86 ;
V_148 = V_84 ;
}
else
{
V_85 = V_84 ;
V_148 = V_86 ;
}
V_147 = V_85 ;
for (; ; )
{
if ( ( V_85 == NULL ) || ( V_85 == V_148 ) ) break;
V_85 = V_147 ;
V_147 = V_150 ? V_85 -> V_88 : V_85 -> V_87 ;
V_149 = V_85 -> V_57 ;
if ( V_146 >= 0 )
{
if ( V_146 != V_149 -> V_146 )
continue;
}
else
{
#ifdef F_45
printf ( L_6 , V_149 -> V_49 , V_149 -> V_124 , V_149 -> V_125 , V_149 -> V_60 , V_149 -> V_75 , V_149 -> V_126 , V_149 -> V_144 ) ;
#endif
if ( V_139 && ! ( V_139 & V_149 -> V_124 ) )
continue;
if ( V_140 && ! ( V_140 & V_149 -> V_125 ) )
continue;
if ( V_141 && ! ( V_141 & V_149 -> V_60 ) )
continue;
if ( V_142 && ! ( V_142 & V_149 -> V_75 ) )
continue;
if ( V_143 && ! ( V_143 & V_149 -> V_126 ) )
continue;
if ( ( V_144 & V_152 ) && ! ( V_144 & V_152 & V_149 -> V_144 ) )
continue;
if ( ( V_144 & V_153 ) && ! ( V_144 & V_153 & V_149 -> V_144 ) )
continue;
}
#ifdef F_45
printf ( L_7 , V_145 ) ;
#endif
if ( V_145 == V_154 )
{
if ( ! V_85 -> V_127 )
{
F_30 ( & V_84 , V_85 , & V_86 ) ;
V_85 -> V_127 = 1 ;
}
}
else if ( V_145 == V_155 )
{
if ( V_85 -> V_127 )
{
F_30 ( & V_84 , V_85 , & V_86 ) ;
}
}
else if ( V_145 == V_151 )
{
if ( V_85 -> V_127 )
{
F_31 ( & V_84 , V_85 , & V_86 ) ;
V_85 -> V_127 = 0 ;
}
}
else if ( V_145 == V_156 )
{
if ( V_84 == V_85 )
V_84 = V_85 -> V_87 ;
else
V_85 -> V_88 -> V_87 = V_85 -> V_87 ;
if ( V_86 == V_85 )
V_86 = V_85 -> V_88 ;
V_85 -> V_127 = 0 ;
if ( V_85 -> V_87 != NULL )
V_85 -> V_87 -> V_88 = V_85 -> V_88 ;
if ( V_85 -> V_88 != NULL )
V_85 -> V_88 -> V_87 = V_85 -> V_87 ;
V_85 -> V_87 = NULL ;
V_85 -> V_88 = NULL ;
}
}
* V_119 = V_84 ;
* V_120 = V_86 ;
}
static int F_46 ( T_8 * * V_119 ,
T_8 * * V_120 )
{
int V_157 , V_55 , * V_158 ;
T_8 * V_85 ;
V_157 = 0 ;
V_85 = * V_119 ;
while ( V_85 != NULL )
{
if ( V_85 -> V_127 &&
( V_85 -> V_57 -> V_146 > V_157 ) )
V_157 = V_85 -> V_57 -> V_146 ;
V_85 = V_85 -> V_87 ;
}
V_158 = F_18 ( ( V_157 + 1 ) * sizeof( int ) ) ;
if ( ! V_158 )
{
F_47 ( V_159 , V_160 ) ;
return ( 0 ) ;
}
memset ( V_158 , 0 , ( V_157 + 1 ) * sizeof( int ) ) ;
V_85 = * V_119 ;
while ( V_85 != NULL )
{
if ( V_85 -> V_127 )
V_158 [ V_85 -> V_57 -> V_146 ] ++ ;
V_85 = V_85 -> V_87 ;
}
for ( V_55 = V_157 ; V_55 >= 0 ; V_55 -- )
if ( V_158 [ V_55 ] > 0 )
F_44 ( 0 , 0 , 0 , 0 , 0 , 0 , 0 , V_155 , V_55 , V_119 , V_120 ) ;
F_20 ( V_158 ) ;
return ( 1 ) ;
}
static int F_48 ( const char * V_161 ,
T_8 * * V_119 , T_8 * * V_120 ,
const T_7 * * V_128 )
{
unsigned long V_139 , V_140 , V_141 , V_142 , V_143 , V_144 ;
const char * V_162 , * V_163 , * V_164 ;
int V_165 , V_166 , V_167 , V_145 , V_168 , V_169 , V_170 ;
unsigned long V_138 = 0 ;
char V_171 ;
V_168 = 1 ;
V_162 = V_161 ;
for (; ; )
{
V_171 = * V_162 ;
if ( V_171 == '\0' )
break;
if ( V_171 == '-' )
{ V_145 = V_151 ; V_162 ++ ; }
else if ( V_171 == '+' )
{ V_145 = V_155 ; V_162 ++ ; }
else if ( V_171 == '!' )
{ V_145 = V_156 ; V_162 ++ ; }
else if ( V_171 == '@' )
{ V_145 = V_172 ; V_162 ++ ; }
else
{ V_145 = V_154 ; }
if ( F_49 ( V_171 ) )
{
V_162 ++ ;
continue;
}
V_139 = 0 ;
V_140 = 0 ;
V_141 = 0 ;
V_142 = 0 ;
V_143 = 0 ;
V_144 = 0 ;
V_163 = V_162 ;
for (; ; )
{
V_171 = * V_162 ;
V_164 = V_162 ;
V_170 = 0 ;
#ifndef F_50
while ( ( ( V_171 >= 'A' ) && ( V_171 <= 'Z' ) ) ||
( ( V_171 >= '0' ) && ( V_171 <= '9' ) ) ||
( ( V_171 >= 'a' ) && ( V_171 <= 'z' ) ) ||
( V_171 == '-' ) )
#else
while ( isalnum ( V_171 ) || ( V_171 == '-' ) )
#endif
{
V_171 = * ( ++ V_162 ) ;
V_170 ++ ;
}
if ( V_170 == 0 )
{
F_47 ( V_173 ,
V_174 ) ;
V_168 = V_167 = 0 ;
V_162 ++ ;
break;
}
if ( V_145 == V_172 )
{
V_167 = 0 ;
break;
}
if ( V_171 == '+' )
{
V_166 = 1 ;
V_162 ++ ;
}
else
V_166 = 0 ;
V_165 = V_167 = 0 ;
V_138 = 0 ;
while ( V_128 [ V_165 ] )
{
if ( ! strncmp ( V_164 , V_128 [ V_165 ] -> V_49 , V_170 ) &&
( V_128 [ V_165 ] -> V_49 [ V_170 ] == '\0' ) )
{
V_167 = 1 ;
break;
}
else
V_165 ++ ;
}
if ( ! V_167 )
break;
if ( V_128 [ V_165 ] -> V_124 )
{
if ( V_139 )
{
V_139 &= V_128 [ V_165 ] -> V_124 ;
if ( ! V_139 ) { V_167 = 0 ; break; }
}
else
V_139 = V_128 [ V_165 ] -> V_124 ;
}
if ( V_128 [ V_165 ] -> V_125 )
{
if ( V_140 )
{
V_140 &= V_128 [ V_165 ] -> V_125 ;
if ( ! V_140 ) { V_167 = 0 ; break; }
}
else
V_140 = V_128 [ V_165 ] -> V_125 ;
}
if ( V_128 [ V_165 ] -> V_60 )
{
if ( V_141 )
{
V_141 &= V_128 [ V_165 ] -> V_60 ;
if ( ! V_141 ) { V_167 = 0 ; break; }
}
else
V_141 = V_128 [ V_165 ] -> V_60 ;
}
if ( V_128 [ V_165 ] -> V_75 )
{
if ( V_142 )
{
V_142 &= V_128 [ V_165 ] -> V_75 ;
if ( ! V_142 ) { V_167 = 0 ; break; }
}
else
V_142 = V_128 [ V_165 ] -> V_75 ;
}
if ( V_128 [ V_165 ] -> V_144 & V_152 )
{
if ( V_144 & V_152 )
{
V_144 &= ( V_128 [ V_165 ] -> V_144 & V_152 ) | ~ V_152 ;
if ( ! ( V_144 & V_152 ) ) { V_167 = 0 ; break; }
}
else
V_144 |= V_128 [ V_165 ] -> V_144 & V_152 ;
}
if ( V_128 [ V_165 ] -> V_144 & V_153 )
{
if ( V_144 & V_153 )
{
V_144 &= ( V_128 [ V_165 ] -> V_144 & V_153 ) | ~ V_153 ;
if ( ! ( V_144 & V_153 ) ) { V_167 = 0 ; break; }
}
else
V_144 |= V_128 [ V_165 ] -> V_144 & V_153 ;
}
if ( V_128 [ V_165 ] -> V_123 )
{
V_138 = V_128 [ V_165 ] -> V_41 ;
}
else
{
if ( V_128 [ V_165 ] -> V_126 )
{
if ( V_143 )
{
V_143 &= V_128 [ V_165 ] -> V_126 ;
if ( ! V_143 ) { V_167 = 0 ; break; }
}
else
V_143 = V_128 [ V_165 ] -> V_126 ;
}
}
if ( ! V_166 ) break;
}
if ( V_145 == V_172 )
{
V_169 = 0 ;
if ( ( V_170 == 8 ) &&
! strncmp ( V_164 , L_8 , 8 ) )
V_169 = F_46 ( V_119 , V_120 ) ;
else
F_47 ( V_173 ,
V_174 ) ;
if ( V_169 == 0 )
V_168 = 0 ;
while ( ( * V_162 != '\0' ) && ! F_49 ( * V_162 ) )
V_162 ++ ;
}
else if ( V_167 )
{
F_44 ( V_138 ,
V_139 , V_140 , V_141 , V_142 , V_143 , V_144 ,
V_145 , - 1 , V_119 , V_120 ) ;
}
else
{
while ( ( * V_162 != '\0' ) && ! F_49 ( * V_162 ) )
V_162 ++ ;
}
if ( * V_162 == '\0' ) break;
}
return ( V_168 ) ;
}
char * F_51 ( const T_7 * V_56 )
{
if ( V_56 != NULL )
return ( V_56 -> V_49 ) ;
return ( L_9 ) ;
}
int F_52 ( const T_7 * V_56 , int * V_175 )
{
int V_176 = 0 ;
if ( V_56 != NULL )
{
if ( V_175 != NULL ) * V_175 = V_56 -> V_175 ;
V_176 = V_56 -> V_146 ;
}
return ( V_176 ) ;
}
void * F_53 ( void )
{
return NULL ;
}
int F_54 ( int V_41 , void * V_177 )
{
return 1 ;
}
const char * F_55 ( const void * V_45 )
{
return NULL ;
}
int F_54 ( int V_41 , T_10 * V_177 )
{
T_3 * V_45 ;
if ( V_177 == NULL || V_177 -> type == V_47 )
return 1 ;
if ( V_41 < 193 || V_41 > 255 )
{
F_47 ( V_178 , V_179 ) ;
return 0 ;
}
F_16 () ;
V_45 = ( T_3 * ) F_18 ( sizeof( T_3 ) ) ;
V_45 -> V_41 = V_41 ;
V_45 -> V_46 = V_177 ;
F_12 () ;
if ( V_44
&& F_26 ( V_44 , V_45 ) >= 0 )
{
F_20 ( V_45 ) ;
F_22 () ;
F_47 ( V_178 , V_180 ) ;
return ( 1 ) ;
}
else if ( ( V_44 == NULL )
|| ! F_21 ( V_44 , V_45 ) )
{
F_20 ( V_45 ) ;
F_22 () ;
F_47 ( V_178 , V_160 ) ;
return ( 1 ) ;
}
else
{
F_22 () ;
return ( 0 ) ;
}
}
const char * F_55 ( const T_10 * V_45 )
{
if ( V_45 )
return V_45 -> V_49 ;
return NULL ;
}
