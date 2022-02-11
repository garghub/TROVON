static int F_1 ( const T_1 * V_1 ,
T_2 V_2 , T_3 V_3 )
{
T_2 V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ , V_1 ++ ) {
if ( V_1 -> V_3 == V_3 )
return V_4 ;
}
return - 1 ;
}
static int F_2 ( const char * V_5 )
{
const T_4 * V_6 ;
int V_7 = 0 ;
V_6 = F_3 ( NULL , V_5 , - 1 ) ;
if ( V_6 && F_4 ( & V_7 , NULL , NULL , NULL , NULL ,
V_6 ) > 0 ) {
return V_7 ;
}
return 0 ;
}
static int F_2 ( const char * V_5 )
{
const T_4 * V_6 ;
T_5 * V_8 = NULL ;
int V_7 = 0 ;
V_6 = F_3 ( & V_8 , V_5 , - 1 ) ;
if ( V_6 ) {
if ( F_4 ( & V_7 , NULL , NULL , NULL , NULL ,
V_6 ) <= 0 )
V_7 = 0 ;
}
F_5 ( V_8 ) ;
return V_7 ;
}
void F_6 ( void )
{
T_2 V_4 ;
const T_1 * V_9 ;
V_10 = 0 ;
F_7 () ;
for ( V_4 = 0 , V_9 = V_11 ; V_4 < V_12 ; V_4 ++ , V_9 ++ ) {
if ( V_9 -> V_13 == V_14 ) {
V_15 [ V_4 ] = NULL ;
} else {
const T_6 * V_16 = F_8 ( V_9 -> V_13 ) ;
V_15 [ V_4 ] = V_16 ;
if ( V_16 == NULL )
V_10 |= V_9 -> V_3 ;
}
}
#ifdef F_9
V_10 |= V_17 ;
#endif
V_18 = 0 ;
for ( V_4 = 0 , V_9 = V_19 ; V_4 < V_20 ; V_4 ++ , V_9 ++ ) {
const T_7 * V_21 = F_10 ( V_9 -> V_13 ) ;
V_22 [ V_4 ] = V_21 ;
if ( V_21 == NULL ) {
V_18 |= V_9 -> V_3 ;
} else {
V_23 [ V_4 ] = F_11 ( V_21 ) ;
F_12 ( V_23 [ V_4 ] >= 0 ) ;
}
}
F_12 ( V_22 [ V_24 ] != NULL ) ;
F_12 ( V_22 [ V_25 ] != NULL ) ;
V_26 = 0 ;
V_27 = 0 ;
#ifdef F_13
V_26 |= V_28 | V_29 ;
V_27 |= V_30 ;
#endif
#ifdef F_14
V_27 |= V_31 ;
#endif
#ifdef F_15
V_26 |= V_32 | V_33 ;
#endif
#ifdef F_16
V_26 |= V_34 ;
V_27 |= V_35 ;
#endif
#ifdef F_17
V_26 |= V_36 ;
V_27 |= V_37 ;
#endif
#ifdef F_18
V_26 |= V_38 ;
#endif
V_39 [ V_40 ] = F_2 ( L_1 ) ;
if ( V_39 [ V_40 ] ) {
V_23 [ V_40 ] = 32 ;
} else {
V_18 |= V_41 ;
}
V_39 [ V_42 ] =
F_2 ( L_2 ) ;
if ( V_39 [ V_42 ] ) {
V_23 [ V_42 ] = 32 ;
} else {
V_18 |= V_43 ;
}
if ( ! F_2 ( L_3 ) )
V_27 |= V_44 | V_45 ;
if ( ! F_2 ( L_4 ) )
V_27 |= V_45 ;
if ( ! F_2 ( L_5 ) )
V_27 |= V_45 ;
if ( ( V_27 & ( V_44 | V_45 ) ) ==
( V_44 | V_45 ) )
V_26 |= V_46 ;
}
static int F_19 ( const T_8 * const * V_47 , const T_8 * const * V_48 )
{
return ( ( * V_47 ) -> V_49 - ( * V_48 ) -> V_49 ) ;
}
static int F_20 ( void )
{
return F_21 ( & V_50 , V_51 ) ;
}
int F_22 ( const T_9 * V_52 , const T_6 * * V_53 ,
const T_7 * * V_21 , int * V_54 ,
int * V_55 , T_8 * * V_56 , int V_57 )
{
int V_4 ;
const T_10 * V_58 ;
V_58 = V_52 -> V_16 ;
if ( V_58 == NULL )
return ( 0 ) ;
if ( V_56 != NULL ) {
T_8 V_59 ;
#ifndef F_23
if ( ! F_20 () ) {
}
#endif
* V_56 = NULL ;
V_59 . V_49 = V_52 -> V_60 ;
if ( V_61 != NULL ) {
V_4 = F_24 ( V_61 , & V_59 ) ;
if ( V_4 >= 0 )
* V_56 = F_25 ( V_61 , V_4 ) ;
else
* V_56 = NULL ;
}
if ( ( V_53 == NULL ) && ( V_21 == NULL ) )
return 1 ;
}
if ( ( V_53 == NULL ) || ( V_21 == NULL ) )
return 0 ;
V_4 = F_26 ( V_11 , V_58 -> V_62 ) ;
if ( V_4 == - 1 )
* V_53 = NULL ;
else {
if ( V_4 == V_63 )
* V_53 = F_27 () ;
else
* V_53 = V_15 [ V_4 ] ;
}
V_4 = F_26 ( V_19 , V_58 -> V_64 ) ;
if ( V_4 == - 1 ) {
* V_21 = NULL ;
if ( V_54 != NULL )
* V_54 = V_14 ;
if ( V_55 != NULL )
* V_55 = 0 ;
if ( V_58 -> V_64 == V_65 )
V_54 = NULL ;
} else {
* V_21 = V_22 [ V_4 ] ;
if ( V_54 != NULL )
* V_54 = V_39 [ V_4 ] ;
if ( V_55 != NULL )
* V_55 = V_23 [ V_4 ] ;
}
if ( ( * V_53 != NULL ) &&
( * V_21 != NULL || ( F_28 ( * V_53 ) & V_66 ) )
&& ( ! V_54 || * V_54 != V_14 ) ) {
const T_6 * V_67 ;
if ( V_57 )
return 1 ;
if ( V_52 -> V_68 >> 8 != V_69 ||
V_52 -> V_68 < V_70 )
return 1 ;
if ( F_29 () )
return 1 ;
if ( V_58 -> V_62 == V_71 &&
V_58 -> V_64 == V_72 &&
( V_67 = F_30 ( L_6 ) ) )
* V_53 = V_67 , * V_21 = NULL ;
else if ( V_58 -> V_62 == V_73 &&
V_58 -> V_64 == V_74 &&
( V_67 = F_30 ( L_7 ) ) )
* V_53 = V_67 , * V_21 = NULL ;
else if ( V_58 -> V_62 == V_75 &&
V_58 -> V_64 == V_74 &&
( V_67 = F_30 ( L_8 ) ) )
* V_53 = V_67 , * V_21 = NULL ;
else if ( V_58 -> V_62 == V_73 &&
V_58 -> V_64 == V_76 &&
( V_67 = F_30 ( L_9 ) ) )
* V_53 = V_67 , * V_21 = NULL ;
else if ( V_58 -> V_62 == V_75 &&
V_58 -> V_64 == V_76 &&
( V_67 = F_30 ( L_10 ) ) )
* V_53 = V_67 , * V_21 = NULL ;
return ( 1 ) ;
} else
return ( 0 ) ;
}
const T_7 * F_31 ( int V_77 )
{
V_77 &= V_78 ;
if ( V_77 < 0 || V_77 >= V_20 )
return NULL ;
return V_22 [ V_77 ] ;
}
const T_7 * F_32 ( T_11 * V_52 )
{
return F_31 ( F_33 ( V_52 ) ) ;
}
const T_7 * F_34 ( T_11 * V_52 )
{
return F_31 ( F_33 ( V_52 ) >> V_79 ) ;
}
static void F_35 ( T_12 * * V_80 , T_12 * V_81 ,
T_12 * * V_82 )
{
if ( V_81 == * V_82 )
return;
if ( V_81 == * V_80 )
* V_80 = V_81 -> V_83 ;
if ( V_81 -> V_84 != NULL )
V_81 -> V_84 -> V_83 = V_81 -> V_83 ;
if ( V_81 -> V_83 != NULL )
V_81 -> V_83 -> V_84 = V_81 -> V_84 ;
( * V_82 ) -> V_83 = V_81 ;
V_81 -> V_84 = * V_82 ;
V_81 -> V_83 = NULL ;
* V_82 = V_81 ;
}
static void F_36 ( T_12 * * V_80 , T_12 * V_81 ,
T_12 * * V_82 )
{
if ( V_81 == * V_80 )
return;
if ( V_81 == * V_82 )
* V_82 = V_81 -> V_84 ;
if ( V_81 -> V_83 != NULL )
V_81 -> V_83 -> V_84 = V_81 -> V_84 ;
if ( V_81 -> V_84 != NULL )
V_81 -> V_84 -> V_83 = V_81 -> V_83 ;
( * V_80 ) -> V_84 = V_81 ;
V_81 -> V_83 = * V_80 ;
V_81 -> V_84 = NULL ;
* V_80 = V_81 ;
}
static void F_37 ( const T_13 * V_85 ,
int V_86 ,
T_3 V_87 ,
T_3 V_88 ,
T_3 V_89 ,
T_3 V_90 ,
T_12 * V_91 ,
T_12 * * V_92 ,
T_12 * * V_93 )
{
int V_4 , V_94 ;
const T_10 * V_58 ;
V_94 = 0 ;
for ( V_4 = 0 ; V_4 < V_86 ; V_4 ++ ) {
V_58 = V_85 -> V_95 ( V_4 ) ;
if ( V_58 == NULL || ! V_58 -> V_96 )
continue;
if ( F_29 () && ( V_58 -> V_97 & V_98 ) )
continue;
if ( ( V_58 -> V_99 & V_87 ) ||
( V_58 -> V_100 & V_88 ) ||
( V_58 -> V_62 & V_89 ) ||
( V_58 -> V_64 & V_90 ) )
continue;
if ( ( ( V_85 -> V_101 -> V_102 & V_103 ) == 0 ) &&
V_58 -> V_104 == 0 )
continue;
if ( ( ( V_85 -> V_101 -> V_102 & V_103 ) != 0 ) &&
V_58 -> V_105 == 0 )
continue;
V_91 [ V_94 ] . V_16 = V_58 ;
V_91 [ V_94 ] . V_83 = NULL ;
V_91 [ V_94 ] . V_84 = NULL ;
V_91 [ V_94 ] . V_106 = 0 ;
V_94 ++ ;
}
if ( V_94 > 0 ) {
V_91 [ 0 ] . V_84 = NULL ;
if ( V_94 > 1 ) {
V_91 [ 0 ] . V_83 = & V_91 [ 1 ] ;
for ( V_4 = 1 ; V_4 < V_94 - 1 ; V_4 ++ ) {
V_91 [ V_4 ] . V_84 = & V_91 [ V_4 - 1 ] ;
V_91 [ V_4 ] . V_83 = & V_91 [ V_4 + 1 ] ;
}
V_91 [ V_94 - 1 ] . V_84 = & V_91 [ V_94 - 2 ] ;
}
V_91 [ V_94 - 1 ] . V_83 = NULL ;
* V_92 = & V_91 [ 0 ] ;
* V_93 = & V_91 [ V_94 - 1 ] ;
}
}
static void F_38 ( const T_10 * * V_107 ,
int V_108 ,
T_3 V_87 ,
T_3 V_88 ,
T_3 V_89 ,
T_3 V_90 ,
T_12 * V_80 )
{
T_12 * V_109 ;
const T_10 * * V_110 ;
int V_4 ;
T_3 V_111 = ~ V_87 ;
T_3 V_112 = ~ V_88 ;
T_3 V_113 = ~ V_89 ;
T_3 V_114 = ~ V_90 ;
V_109 = V_80 ;
V_110 = V_107 ;
while ( V_109 != NULL ) {
* V_110 = V_109 -> V_16 ;
V_110 ++ ;
V_109 = V_109 -> V_83 ;
}
for ( V_4 = 0 ; V_4 < V_108 ; V_4 ++ ) {
T_3 V_99 = V_115 [ V_4 ] . V_99 ;
T_3 V_100 = V_115 [ V_4 ] . V_100 ;
T_3 V_62 = V_115 [ V_4 ] . V_62 ;
T_3 V_64 = V_115 [ V_4 ] . V_64 ;
if ( V_99 )
if ( ( V_99 & V_111 ) == 0 )
continue;
if ( V_100 )
if ( ( V_100 & V_112 ) == 0 )
continue;
if ( V_62 )
if ( ( V_62 & V_113 ) == 0 )
continue;
if ( V_64 )
if ( ( V_64 & V_114 ) == 0 )
continue;
* V_110 = ( T_10 * ) ( V_115 + V_4 ) ;
V_110 ++ ;
}
* V_110 = NULL ;
}
static void F_39 ( T_3 V_116 , T_3 V_117 ,
T_3 V_118 , T_3 V_119 ,
T_3 V_120 , int V_104 ,
T_3 V_97 , int V_121 ,
T_14 V_122 , T_12 * * V_92 ,
T_12 * * V_93 )
{
T_12 * V_80 , * V_82 , * V_81 , * V_83 , * V_123 ;
const T_10 * V_124 ;
int V_125 = 0 ;
#ifdef F_40
fprintf ( V_126 ,
L_11 ,
V_121 , V_117 , V_118 , V_119 , V_120 , V_104 ,
V_97 , V_122 ) ;
#endif
if ( V_121 == V_127 || V_121 == V_128 )
V_125 = 1 ;
V_80 = * V_92 ;
V_82 = * V_93 ;
if ( V_125 ) {
V_83 = V_82 ;
V_123 = V_80 ;
} else {
V_83 = V_80 ;
V_123 = V_82 ;
}
V_81 = NULL ;
for (; ; ) {
if ( V_81 == V_123 )
break;
V_81 = V_83 ;
if ( V_81 == NULL )
break;
V_83 = V_125 ? V_81 -> V_84 : V_81 -> V_83 ;
V_124 = V_81 -> V_16 ;
if ( V_122 >= 0 ) {
if ( V_122 != V_124 -> V_122 )
continue;
} else {
#ifdef F_40
fprintf ( V_126 ,
L_12 ,
V_124 -> V_129 , V_124 -> V_99 , V_124 -> V_100 ,
V_124 -> V_62 , V_124 -> V_64 , V_124 -> V_104 ,
V_124 -> V_97 ) ;
#endif
if ( V_117 && ! ( V_117 & V_124 -> V_99 ) )
continue;
if ( V_118 && ! ( V_118 & V_124 -> V_100 ) )
continue;
if ( V_119 && ! ( V_119 & V_124 -> V_62 ) )
continue;
if ( V_120 && ! ( V_120 & V_124 -> V_64 ) )
continue;
if ( V_104 && ( V_104 != V_124 -> V_104 ) )
continue;
if ( ( V_97 & V_130 )
&& ! ( V_97 & V_130 & V_124 -> V_97 ) )
continue;
if ( ( V_97 & V_131 )
&& ! ( V_97 & V_131 & V_124 -> V_97 ) )
continue;
}
#ifdef F_40
fprintf ( V_126 , L_13 , V_121 ) ;
#endif
if ( V_121 == V_132 ) {
if ( ! V_81 -> V_106 ) {
F_35 ( & V_80 , V_81 , & V_82 ) ;
V_81 -> V_106 = 1 ;
}
}
else if ( V_121 == V_133 ) {
if ( V_81 -> V_106 ) {
F_35 ( & V_80 , V_81 , & V_82 ) ;
}
} else if ( V_121 == V_127 ) {
if ( V_81 -> V_106 ) {
F_36 ( & V_80 , V_81 , & V_82 ) ;
V_81 -> V_106 = 0 ;
}
} else if ( V_121 == V_128 ) {
if ( V_81 -> V_106 )
F_36 ( & V_80 , V_81 , & V_82 ) ;
} else if ( V_121 == V_134 ) {
if ( V_80 == V_81 )
V_80 = V_81 -> V_83 ;
else
V_81 -> V_84 -> V_83 = V_81 -> V_83 ;
if ( V_82 == V_81 )
V_82 = V_81 -> V_84 ;
V_81 -> V_106 = 0 ;
if ( V_81 -> V_83 != NULL )
V_81 -> V_83 -> V_84 = V_81 -> V_84 ;
if ( V_81 -> V_84 != NULL )
V_81 -> V_84 -> V_83 = V_81 -> V_83 ;
V_81 -> V_83 = NULL ;
V_81 -> V_84 = NULL ;
}
}
* V_92 = V_80 ;
* V_93 = V_82 ;
}
static int F_41 ( T_12 * * V_92 ,
T_12 * * V_93 )
{
T_14 V_135 ;
int V_4 , * V_136 ;
T_12 * V_81 ;
V_135 = 0 ;
V_81 = * V_92 ;
while ( V_81 != NULL ) {
if ( V_81 -> V_106 && ( V_81 -> V_16 -> V_122 > V_135 ) )
V_135 = V_81 -> V_16 -> V_122 ;
V_81 = V_81 -> V_83 ;
}
V_136 = F_42 ( sizeof( int ) * ( V_135 + 1 ) ) ;
if ( V_136 == NULL ) {
F_43 ( V_137 , V_138 ) ;
return ( 0 ) ;
}
V_81 = * V_92 ;
while ( V_81 != NULL ) {
if ( V_81 -> V_106 )
V_136 [ V_81 -> V_16 -> V_122 ] ++ ;
V_81 = V_81 -> V_83 ;
}
for ( V_4 = V_135 ; V_4 >= 0 ; V_4 -- )
if ( V_136 [ V_4 ] > 0 )
F_39 ( 0 , 0 , 0 , 0 , 0 , 0 , 0 , V_133 , V_4 , V_92 ,
V_93 ) ;
F_44 ( V_136 ) ;
return ( 1 ) ;
}
static int F_45 ( const char * V_139 ,
T_12 * * V_92 ,
T_12 * * V_93 ,
const T_10 * * V_107 , T_15 * V_58 )
{
T_3 V_117 , V_118 , V_119 , V_120 , V_97 ;
int V_104 ;
const char * V_140 , * V_141 ;
int V_142 , V_143 , V_144 , V_121 , V_145 , V_146 , V_147 ;
T_3 V_116 = 0 ;
char V_148 ;
V_145 = 1 ;
V_140 = V_139 ;
for (; ; ) {
V_148 = * V_140 ;
if ( V_148 == '\0' )
break;
if ( V_148 == '-' ) {
V_121 = V_127 ;
V_140 ++ ;
} else if ( V_148 == '+' ) {
V_121 = V_133 ;
V_140 ++ ;
} else if ( V_148 == '!' ) {
V_121 = V_134 ;
V_140 ++ ;
} else if ( V_148 == '@' ) {
V_121 = V_149 ;
V_140 ++ ;
} else {
V_121 = V_132 ;
}
if ( F_46 ( V_148 ) ) {
V_140 ++ ;
continue;
}
V_117 = 0 ;
V_118 = 0 ;
V_119 = 0 ;
V_120 = 0 ;
V_104 = 0 ;
V_97 = 0 ;
for (; ; ) {
V_148 = * V_140 ;
V_141 = V_140 ;
V_147 = 0 ;
#ifndef F_47
while ( ( ( V_148 >= 'A' ) && ( V_148 <= 'Z' ) ) ||
( ( V_148 >= '0' ) && ( V_148 <= '9' ) ) ||
( ( V_148 >= 'a' ) && ( V_148 <= 'z' ) ) ||
( V_148 == '-' ) || ( V_148 == '.' ) || ( V_148 == '=' ) )
#else
while ( isalnum ( V_148 ) || ( V_148 == '-' ) || ( V_148 == '.' ) || ( V_148 == '=' ) )
#endif
{
V_148 = * ( ++ V_140 ) ;
V_147 ++ ;
}
if ( V_147 == 0 ) {
F_43 ( V_150 , V_151 ) ;
V_145 = V_144 = 0 ;
V_140 ++ ;
break;
}
if ( V_121 == V_149 ) {
V_144 = 0 ;
break;
}
if ( V_148 == '+' ) {
V_143 = 1 ;
V_140 ++ ;
} else
V_143 = 0 ;
V_142 = V_144 = 0 ;
V_116 = 0 ;
while ( V_107 [ V_142 ] ) {
if ( strncmp ( V_141 , V_107 [ V_142 ] -> V_129 , V_147 ) == 0
&& ( V_107 [ V_142 ] -> V_129 [ V_147 ] == '\0' ) ) {
V_144 = 1 ;
break;
} else
V_142 ++ ;
}
if ( ! V_144 )
break;
if ( V_107 [ V_142 ] -> V_99 ) {
if ( V_117 ) {
V_117 &= V_107 [ V_142 ] -> V_99 ;
if ( ! V_117 ) {
V_144 = 0 ;
break;
}
} else
V_117 = V_107 [ V_142 ] -> V_99 ;
}
if ( V_107 [ V_142 ] -> V_100 ) {
if ( V_118 ) {
V_118 &= V_107 [ V_142 ] -> V_100 ;
if ( ! V_118 ) {
V_144 = 0 ;
break;
}
} else
V_118 = V_107 [ V_142 ] -> V_100 ;
}
if ( V_107 [ V_142 ] -> V_62 ) {
if ( V_119 ) {
V_119 &= V_107 [ V_142 ] -> V_62 ;
if ( ! V_119 ) {
V_144 = 0 ;
break;
}
} else
V_119 = V_107 [ V_142 ] -> V_62 ;
}
if ( V_107 [ V_142 ] -> V_64 ) {
if ( V_120 ) {
V_120 &= V_107 [ V_142 ] -> V_64 ;
if ( ! V_120 ) {
V_144 = 0 ;
break;
}
} else
V_120 = V_107 [ V_142 ] -> V_64 ;
}
if ( V_107 [ V_142 ] -> V_97 & V_130 ) {
if ( V_97 & V_130 ) {
V_97 &=
( V_107 [ V_142 ] -> V_97 & V_130 ) |
~ V_130 ;
if ( ! ( V_97 & V_130 ) ) {
V_144 = 0 ;
break;
}
} else
V_97 = V_107 [ V_142 ] -> V_97 & V_130 ;
}
if ( V_107 [ V_142 ] -> V_97 & V_131 ) {
if ( V_97 & V_131 ) {
V_97 &=
( V_107 [ V_142 ] -> V_97 & V_131 ) |
~ V_131 ;
if ( ! ( V_97 & V_131 ) ) {
V_144 = 0 ;
break;
}
} else
V_97 |=
V_107 [ V_142 ] -> V_97 & V_131 ;
}
if ( V_107 [ V_142 ] -> V_96 ) {
V_116 = V_107 [ V_142 ] -> V_49 ;
} else {
if ( V_107 [ V_142 ] -> V_104 ) {
if ( V_104 != 0 && V_104 != V_107 [ V_142 ] -> V_104 ) {
V_144 = 0 ;
break;
} else {
V_104 = V_107 [ V_142 ] -> V_104 ;
}
}
}
if ( ! V_143 )
break;
}
if ( V_121 == V_149 ) {
V_146 = 0 ;
if ( ( V_147 == 8 ) && strncmp ( V_141 , L_14 , 8 ) == 0 )
V_146 = F_41 ( V_92 , V_93 ) ;
else if ( V_147 == 10 && strncmp ( V_141 , L_15 , 9 ) == 0 ) {
int V_152 = V_141 [ 9 ] - '0' ;
if ( V_152 < 0 || V_152 > 5 ) {
F_43 ( V_150 ,
V_151 ) ;
} else {
V_58 -> V_153 = V_152 ;
V_146 = 1 ;
}
} else
F_43 ( V_150 , V_151 ) ;
if ( V_146 == 0 )
V_145 = 0 ;
while ( ( * V_140 != '\0' ) && ! F_46 ( * V_140 ) )
V_140 ++ ;
} else if ( V_144 ) {
F_39 ( V_116 ,
V_117 , V_118 , V_119 , V_120 ,
V_104 , V_97 , V_121 , - 1 , V_92 ,
V_93 ) ;
} else {
while ( ( * V_140 != '\0' ) && ! F_46 ( * V_140 ) )
V_140 ++ ;
}
if ( * V_140 == '\0' )
break;
}
return ( V_145 ) ;
}
static int F_48 ( const T_13 * V_154 , T_15 * V_58 ,
const char * * V_155 )
{
unsigned int V_156 = 0 , V_157 = 0 ;
if ( strncmp ( * V_155 , L_16 , 13 ) == 0 ) {
V_156 = V_158 ;
} else if ( strncmp ( * V_155 , L_17 , 11 ) == 0 ) {
V_157 = 1 ;
V_156 = V_159 ;
} else if ( strncmp ( * V_155 , L_18 , 9 ) == 0 ) {
V_156 = V_159 ;
} else if ( strncmp ( * V_155 , L_19 , 9 ) == 0 ) {
V_156 = V_160 ;
}
if ( V_156 ) {
V_58 -> V_161 &= ~ V_159 ;
V_58 -> V_161 |= V_156 ;
} else
V_156 = V_58 -> V_161 & V_159 ;
if ( ! V_156 )
return 1 ;
if ( ! ( V_154 -> V_101 -> V_102 & V_162 ) ) {
F_43 ( V_163 ,
V_164 ) ;
return 0 ;
}
# ifndef F_16
switch ( V_156 ) {
case V_159 :
if ( V_157 )
* V_155 = L_20 ;
else
* V_155 =
L_21 ;
break;
case V_158 :
* V_155 = L_22 ;
break;
case V_160 :
* V_155 = L_20 ;
break;
}
return 1 ;
# else
F_43 ( V_163 , V_165 ) ;
return 0 ;
# endif
}
char * F_49 ( const T_10 * V_58 )
{
if ( V_58 == NULL )
return L_23 ;
if ( V_58 -> V_104 == V_70 )
return L_24 ;
return F_50 ( V_58 -> V_104 ) ;
}
const char * F_51 ( const T_10 * V_58 )
{
if ( V_58 != NULL )
return ( V_58 -> V_129 ) ;
return ( L_23 ) ;
}
int F_52 ( const T_10 * V_58 , int * V_166 )
{
int V_167 = 0 ;
if ( V_58 != NULL ) {
if ( V_166 != NULL )
* V_166 = ( int ) V_58 -> V_166 ;
V_167 = ( int ) V_58 -> V_122 ;
}
return V_167 ;
}
T_3 F_53 ( const T_10 * V_58 )
{
return V_58 -> V_49 ;
}
int F_54 ( int V_49 , T_16 * V_168 )
{
return 1 ;
}
static void F_55 ( T_8 * V_168 )
{
F_44 ( V_168 ) ;
}
void F_56 ( void )
{
F_57 ( T_8 ) * V_169 = V_61 ;
V_61 = NULL ;
F_58 ( V_169 , F_55 ) ;
}
int F_54 ( int V_49 , T_16 * V_168 )
{
T_8 * V_56 ;
if ( V_168 == NULL || F_59 ( V_168 ) == V_14 )
return 1 ;
if ( V_49 < 193 || V_49 > 255 ) {
F_43 ( V_170 ,
V_171 ) ;
return 0 ;
}
F_60 ( V_172 ) ;
V_56 = F_61 ( sizeof( * V_56 ) ) ;
if ( V_56 == NULL ) {
F_60 ( V_173 ) ;
F_43 ( V_170 , V_138 ) ;
return ( 1 ) ;
}
V_56 -> V_49 = V_49 ;
V_56 -> V_174 = V_168 ;
F_20 () ;
if ( V_61 && F_24 ( V_61 , V_56 ) >= 0 ) {
F_44 ( V_56 ) ;
F_60 ( V_173 ) ;
F_43 ( V_170 ,
V_175 ) ;
return ( 1 ) ;
}
if ( V_61 == NULL || ! F_62 ( V_61 , V_56 ) ) {
F_44 ( V_56 ) ;
F_60 ( V_173 ) ;
F_43 ( V_170 , V_138 ) ;
return ( 1 ) ;
}
F_60 ( V_173 ) ;
return ( 0 ) ;
}
const char * F_63 ( const T_16 * V_56 )
{
#ifndef F_23
return V_56 ? F_64 ( V_56 ) : NULL ;
#else
return NULL ;
#endif
}
int F_65 ( const T_10 * V_58 )
{
T_3 V_176 ;
V_176 = V_58 -> V_100 ;
if ( V_176 & V_35 )
return V_177 ;
else if ( V_176 & V_31 )
return V_178 ;
else if ( V_176 & V_30 )
return V_179 ;
else if ( V_176 & V_45 )
return V_180 ;
else if ( V_176 & V_44 )
return V_181 ;
return - 1 ;
}
const T_10 * F_66 ( T_11 * V_182 , const unsigned char * V_183 )
{
const T_10 * V_58 = V_182 -> V_174 -> V_184 ( V_183 ) ;
if ( V_58 == NULL || V_58 -> V_96 == 0 )
return NULL ;
return V_58 ;
}
const T_10 * F_67 ( T_11 * V_182 , const unsigned char * V_183 )
{
return V_182 -> V_174 -> V_184 ( V_183 ) ;
}
int F_68 ( const T_10 * V_58 )
{
int V_4 ;
if ( V_58 == NULL )
return V_14 ;
V_4 = F_26 ( V_11 , V_58 -> V_62 ) ;
if ( V_4 == - 1 )
return V_14 ;
return V_11 [ V_4 ] . V_13 ;
}
int F_69 ( const T_10 * V_58 )
{
int V_4 = F_26 ( V_19 , V_58 -> V_64 ) ;
if ( V_4 == - 1 )
return V_14 ;
return V_19 [ V_4 ] . V_13 ;
}
int F_70 ( const T_10 * V_58 )
{
int V_4 = F_26 ( V_185 , V_58 -> V_99 ) ;
if ( V_4 == - 1 )
return V_14 ;
return V_185 [ V_4 ] . V_13 ;
}
int F_71 ( const T_10 * V_58 )
{
int V_4 = F_26 ( V_186 , V_58 -> V_100 ) ;
if ( V_4 == - 1 )
return V_14 ;
return V_186 [ V_4 ] . V_13 ;
}
int F_72 ( const T_10 * V_58 )
{
return ( V_58 -> V_64 & V_65 ) ? 1 : 0 ;
}
