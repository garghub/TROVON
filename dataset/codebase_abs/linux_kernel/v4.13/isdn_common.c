static inline void
F_1 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_2 -> V_3 ) ;
V_1 -> V_4 ++ ;
}
void
F_3 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_7 -> V_1 [ V_5 ] )
continue;
F_1 ( V_7 -> V_1 [ V_5 ] ) ;
}
}
static inline void
F_4 ( T_1 * V_1 )
{
if ( V_1 -> V_4 > 0 ) {
V_1 -> V_4 -- ;
F_5 ( V_1 -> V_2 -> V_3 ) ;
}
}
void
F_6 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_7 -> V_1 [ V_5 ] )
continue;
F_4 ( V_7 -> V_1 [ V_5 ] ) ;
}
}
void
F_7 ( char * V_8 , T_2 * V_9 , int V_10 , int V_11 )
{
int V_12 ;
F_8 ( V_13 L_1 , V_8 , V_10 ) ;
for ( V_12 = 0 ; ( V_12 < V_11 ) && ( V_10 ) ; V_10 -- , V_12 ++ )
F_8 ( L_2 , * V_9 ++ ) ;
F_8 ( L_3 ) ;
}
static int
F_9 ( char * V_8 , char * V_9 )
{
while ( F_10 ( V_8 , V_9 ) ) {
if ( * ++ V_8 == '\0' )
return ( 2 ) ;
}
return ( 0 ) ;
}
static int
F_10 ( char * V_8 , char * V_9 )
{
register int V_14 ;
register int V_15 ;
register int V_16 ;
register int V_17 = 1 ;
if ( ! ( * V_8 ) && ! ( * V_9 ) )
return ( 1 ) ;
for (; * V_9 ; V_8 ++ , V_9 ++ )
switch ( * V_9 ) {
case '\\' :
V_9 ++ ;
default:
if ( * V_8 != * V_9 )
return ( * V_8 == '\0' ) ? 2 : 1 ;
continue;
case '?' :
if ( * V_8 == '\0' )
return ( 2 ) ;
continue;
case '*' :
V_17 = 0 ;
return ( * ++ V_9 ? F_9 ( V_8 , V_9 ) : 0 ) ;
case '[' :
if ( ( V_16 = ( V_9 [ 1 ] == '^' ) ) )
V_9 ++ ;
for ( V_14 = 0 , V_15 = 0 ; * ++ V_9 && ( * V_9 != ']' ) ; V_14 = * V_9 )
if ( * V_9 == '-' ? * V_8 <= * ++ V_9 && * V_8 >= V_14 : * V_8 == * V_9 )
V_15 = 1 ;
if ( V_15 == V_16 )
return ( 1 ) ;
continue;
}
return ( * V_8 == '\0' ) ? 0 : V_17 ;
}
int F_11 ( const char * V_18 , const char * V_19 )
{
char V_20 [ V_21 ] ;
char V_22 [ V_21 ] ;
char * V_9 ;
for ( V_9 = V_20 ; * V_18 && * V_18 != ':' ; )
* V_9 ++ = * V_18 ++ ;
* V_9 = '\0' ;
for ( V_9 = V_22 ; * V_19 && * V_19 != ':' ; )
* V_9 ++ = * V_19 ++ ;
* V_9 = '\0' ;
return F_10 ( V_20 , V_22 ) ;
}
int
F_12 ( int V_23 , int V_24 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
if ( V_7 -> V_26 [ V_5 ] == V_24 && V_7 -> V_27 [ V_5 ] == V_23 )
return V_5 ;
return - 1 ;
}
static void
F_13 ( T_3 V_28 )
{
int V_29 = V_7 -> V_30 ;
if ( V_29 & V_31 ) {
if ( V_29 & V_32 )
F_14 () ;
if ( V_29 & V_33 )
F_15 () ;
if ( V_29 & V_34 )
F_16 () ;
}
if ( V_29 & V_35 ) {
if ( ++ V_36 >= V_37 ) {
V_36 = 0 ;
if ( V_29 & V_38 )
F_17 () ;
}
if ( ++ V_39 >= V_40 ) {
V_39 = 0 ;
if ( V_29 & V_41 )
F_18 () ;
if ( ++ V_42 >= V_43 ) {
V_42 = 0 ;
if ( V_29 & V_44 )
F_19 () ;
}
if ( V_29 & V_45 )
F_20 () ;
}
}
if ( V_29 )
F_21 ( & V_7 -> V_46 , V_47 + V_48 ) ;
}
void
F_22 ( int V_29 , int V_49 )
{
unsigned long V_50 ;
int V_51 ;
F_23 ( & V_7 -> V_52 , V_50 ) ;
if ( ( V_29 & V_35 ) && ( ! ( V_7 -> V_30 & V_35 ) ) ) {
V_36 = 0 ;
V_39 = 0 ;
}
V_51 = V_7 -> V_30 ;
if ( V_49 )
V_7 -> V_30 |= V_29 ;
else
V_7 -> V_30 &= ~ V_29 ;
if ( V_7 -> V_30 && ! V_51 )
F_21 ( & V_7 -> V_46 , V_47 + V_48 ) ;
F_24 ( & V_7 -> V_52 , V_50 ) ;
}
static void
F_25 ( int V_23 , int V_53 , struct V_54 * V_55 )
{
int V_5 ;
if ( ( V_5 = F_12 ( V_23 , V_53 ) ) == - 1 ) {
F_26 ( V_55 ) ;
return;
}
V_7 -> V_56 [ V_5 ] += V_55 -> V_10 ;
if ( F_27 ( V_5 , V_55 ) )
return;
if ( V_7 -> V_57 [ V_5 ] ) {
F_28 ( & V_7 -> V_58 [ V_5 ] ) ;
V_55 = F_29 ( V_7 -> V_57 [ V_5 ] , V_55 ) ;
F_30 ( & V_7 -> V_58 [ V_5 ] ) ;
if ( ! V_55 )
return;
}
if ( V_55 -> V_10 ) {
if ( F_31 ( V_5 , V_23 , V_53 , V_55 ) )
return;
F_32 ( & V_7 -> V_1 [ V_23 ] -> V_59 [ V_53 ] ) ;
} else
F_26 ( V_55 ) ;
}
int
F_33 ( T_4 * V_60 )
{
if ( V_60 -> V_61 == - 1 ) {
F_8 ( V_62 L_4 , V_60 -> V_63 ) ;
return ( 1 ) ;
}
if ( ! V_7 -> V_1 [ V_60 -> V_61 ] ) {
F_8 ( V_62 L_5 ,
V_60 -> V_63 , V_60 -> V_61 ) ;
return ( 1 ) ;
}
if ( ! V_7 -> V_1 [ V_60 -> V_61 ] -> V_2 ) {
F_8 ( V_62 L_6 ,
V_60 -> V_63 , V_60 -> V_61 ) ;
return ( 1 ) ;
}
if ( V_60 -> V_63 == V_64 ) {
int V_65 = F_12 ( V_60 -> V_61 , V_60 -> V_66 & 255 ) ;
unsigned long V_67 = ( V_60 -> V_66 >> 8 ) & 255 ;
unsigned long V_68 = ( V_7 -> V_1 [ V_60 -> V_61 ] -> V_2 -> V_68
>> V_69 ) &
V_70 ;
unsigned long V_71 = ( 1 << V_67 ) ;
switch ( V_67 ) {
case V_72 :
case V_73 :
case V_74 :
if ( ! ( V_68 & V_71 ) ) {
V_7 -> V_75 [ V_65 ] = V_67 ;
V_60 -> V_66 = ( V_60 -> V_66 & 255 ) |
( V_76 << 8 ) ;
} else
V_7 -> V_75 [ V_65 ] = 0 ;
}
}
return V_7 -> V_1 [ V_60 -> V_61 ] -> V_2 -> V_63 ( V_60 ) ;
}
void
F_34 ( int V_23 , int V_24 )
{
T_4 V_60 ;
if ( V_23 < 0 )
return;
V_60 . V_61 = V_23 ;
V_60 . V_66 = V_24 ;
V_60 . V_63 = V_77 ;
V_60 . V_78 . V_79 [ 0 ] = '\0' ;
F_33 ( & V_60 ) ;
}
static int
F_35 ( T_5 * V_80 )
{
switch ( V_80 -> V_81 ) {
case V_82 :
return ( F_36 ( V_80 ) ) ;
default:
return ( - 1 ) ;
}
}
static int
F_37 ( T_4 * V_83 )
{
int V_23 ;
T_6 V_50 ;
int V_5 ;
int V_84 ;
int V_85 = 0 ;
T_4 V_60 ;
T_7 * V_9 ;
V_23 = V_83 -> V_61 ;
V_5 = F_12 ( V_23 , V_83 -> V_66 ) ;
switch ( V_83 -> V_63 ) {
case V_86 :
if ( V_5 < 0 )
return - 1 ;
if ( V_7 -> V_87 & V_88 )
return 0 ;
if ( F_38 ( V_5 , V_83 ) )
return 0 ;
if ( F_39 ( V_5 , V_83 ) )
return 0 ;
if ( F_40 ( V_5 , V_83 ) )
return 0 ;
F_32 ( & V_7 -> V_1 [ V_23 ] -> V_89 [ V_83 -> V_66 ] ) ;
break;
case V_90 :
V_7 -> V_1 [ V_23 ] -> V_91 += V_83 -> V_66 ;
F_32 ( & V_7 -> V_1 [ V_23 ] -> V_92 ) ;
break;
case V_93 :
V_7 -> V_1 [ V_23 ] -> V_50 |= V_94 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
if ( V_7 -> V_27 [ V_5 ] == V_23 )
F_34 ( V_23 , V_7 -> V_26 [ V_5 ] ) ;
F_41 () ;
break;
case V_95 :
V_7 -> V_1 [ V_23 ] -> V_50 &= ~ V_94 ;
break;
case V_96 :
if ( V_5 < 0 )
return - 1 ;
#ifdef F_42
F_8 ( V_13 L_7 , V_23 , V_83 -> V_66 , V_83 -> V_78 . V_79 ) ;
#endif
if ( V_7 -> V_87 & V_88 ) {
V_60 . V_61 = V_23 ;
V_60 . V_66 = V_83 -> V_66 ;
V_60 . V_63 = V_97 ;
F_33 ( & V_60 ) ;
return 0 ;
}
V_84 = ( ( V_83 -> V_63 == V_98 ) ? 0 : F_43 ( V_23 , V_83 -> V_66 , V_5 , & V_83 -> V_78 . V_99 ) ) ;
switch ( V_84 ) {
case 0 :
if ( V_83 -> V_63 == V_96 )
if ( ( V_85 = F_44 ( V_23 , V_83 -> V_66 , & V_83 -> V_78 . V_99 ) ) ) return ( V_85 ) ;
#ifdef F_45
if ( V_100 )
if ( ( V_85 = V_100 -> V_101 ( V_83 ) ) )
return ( V_85 ) ;
#endif
if ( ( ! V_85 ) && ( V_7 -> V_1 [ V_23 ] -> V_50 & V_102 ) ) {
V_60 . V_61 = V_23 ;
V_60 . V_66 = V_83 -> V_66 ;
V_60 . V_63 = V_97 ;
F_33 ( & V_60 ) ;
V_85 = 2 ;
}
break;
case 1 :
F_17 () ;
V_60 . V_61 = V_23 ;
V_60 . V_66 = V_83 -> V_66 ;
V_60 . V_63 = V_103 ;
for ( V_9 = V_7 -> V_104 ; V_9 ; V_9 = V_9 -> V_105 )
if ( V_9 -> V_106 -> V_107 == V_60 . V_66 )
{
strcpy ( V_60 . V_78 . V_99 . V_108 , V_9 -> V_106 -> V_109 ) ;
F_33 ( & V_60 ) ;
V_85 = 1 ;
break;
}
break;
case 2 :
case 3 :
V_85 = 2 ;
F_8 ( V_110 L_8 ) ;
V_60 . V_61 = V_23 ;
V_60 . V_66 = V_83 -> V_66 ;
V_60 . V_63 = V_97 ;
F_33 ( & V_60 ) ;
if ( V_84 == 3 )
break;
case 4 :
F_17 () ;
break;
case 5 :
V_85 = 3 ;
break;
}
#ifdef F_42
F_8 ( V_13 L_9 , V_85 ) ;
#endif
return V_85 ;
break;
case V_111 :
if ( V_5 < 0 )
return - 1 ;
#ifdef F_42
F_8 ( V_13 L_10 , V_83 -> V_66 , V_83 -> V_78 . V_79 ) ;
#endif
if ( V_7 -> V_87 & V_88 )
return 0 ;
if ( strcmp ( V_83 -> V_78 . V_79 , L_11 ) )
F_38 ( V_5 , V_83 ) ;
F_40 ( V_5 , V_83 ) ;
break;
case V_112 :
#ifdef F_42
F_8 ( V_13 L_12 , V_83 -> V_66 , V_83 -> V_78 . V_79 ) ;
#endif
F_8 ( V_110 L_13 ,
V_7 -> V_113 [ V_23 ] , V_83 -> V_66 , V_83 -> V_78 . V_79 ) ;
F_40 ( V_5 , V_83 ) ;
#ifdef F_45
if ( V_100 )
V_100 -> V_101 ( V_83 ) ;
#endif
break;
case V_114 :
#ifdef F_42
F_8 ( V_13 L_14 , V_83 -> V_66 , V_83 -> V_78 . V_115 ) ;
#endif
F_40 ( V_5 , V_83 ) ;
#ifdef F_45
if ( V_100 )
V_100 -> V_101 ( V_83 ) ;
#endif
break;
case V_116 :
if ( V_5 < 0 )
return - 1 ;
#ifdef F_42
F_8 ( V_13 L_15 , V_83 -> V_66 ) ;
#endif
if ( V_7 -> V_87 & V_88 )
return 0 ;
if ( F_38 ( V_5 , V_83 ) )
break;
F_39 ( V_5 , V_83 ) ;
if ( F_40 ( V_5 , V_83 ) ) {
V_60 . V_61 = V_23 ;
V_60 . V_66 = V_83 -> V_66 ;
V_60 . V_63 = V_117 ;
F_33 ( & V_60 ) ;
break;
}
break;
case V_118 :
if ( V_5 < 0 )
return - 1 ;
#ifdef F_42
F_8 ( V_13 L_16 , V_83 -> V_66 ) ;
#endif
if ( V_7 -> V_87 & V_88 )
return 0 ;
V_7 -> V_1 [ V_23 ] -> V_119 &= ~ ( 1 << ( V_83 -> V_66 ) ) ;
F_46 () ;
if ( F_38 ( V_5 , V_83 ) )
break;
F_39 ( V_5 , V_83 ) ;
if ( F_40 ( V_5 , V_83 ) )
break;
#ifdef F_45
if ( V_100 )
V_100 -> V_101 ( V_83 ) ;
#endif
break;
break;
case V_120 :
if ( V_5 < 0 )
return - 1 ;
#ifdef F_42
F_8 ( V_13 L_17 , V_83 -> V_66 ) ;
#endif
if ( V_7 -> V_87 & V_88 )
return 0 ;
V_7 -> V_1 [ V_23 ] -> V_119 |= ( 1 << ( V_83 -> V_66 ) ) ;
F_46 () ;
if ( F_38 ( V_5 , V_83 ) )
break;
F_39 ( V_5 , V_83 ) ;
if ( F_40 ( V_5 , V_83 ) )
break;
break;
case V_121 :
if ( V_5 < 0 )
return - 1 ;
#ifdef F_42
F_8 ( V_13 L_18 , V_83 -> V_66 ) ;
#endif
if ( V_7 -> V_87 & V_88 )
return 0 ;
V_7 -> V_1 [ V_23 ] -> V_119 &= ~ ( 1 << ( V_83 -> V_66 ) ) ;
F_46 () ;
#ifdef F_47
if ( F_38 ( V_5 , V_83 ) )
break;
#endif
F_39 ( V_5 , V_83 ) ;
if ( F_40 ( V_5 , V_83 ) )
break;
break;
case V_122 :
if ( V_5 < 0 )
return - 1 ;
#ifdef F_42
F_8 ( V_13 L_19 , V_83 -> V_66 ) ;
#endif
if ( V_7 -> V_87 & V_88 )
return 0 ;
if ( F_38 ( V_5 , V_83 ) )
break;
if ( F_40 ( V_5 , V_83 ) )
break;
break;
case V_123 :
F_23 ( & V_7 -> V_124 , V_50 ) ;
if ( F_48 ( V_7 -> V_1 [ V_23 ] , V_23 , V_83 -> V_66 , 1 ) ) {
F_24 ( & V_7 -> V_124 , V_50 ) ;
return - 1 ;
}
F_24 ( & V_7 -> V_124 , V_50 ) ;
F_46 () ;
break;
case V_125 :
F_23 ( & V_7 -> V_124 , V_50 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
if ( ( V_7 -> V_27 [ V_5 ] == V_23 ) &&
( V_7 -> V_26 [ V_5 ] == V_83 -> V_66 ) ) {
if ( V_83 -> V_78 . V_79 [ 0 ] )
V_7 -> V_126 [ V_5 ] &= ~ V_127 ;
else
if ( F_49 ( V_7 -> V_126 [ V_5 ] ) ) {
V_7 -> V_126 [ V_5 ] |= V_127 ;
}
else
V_85 = - 1 ;
break;
}
F_24 ( & V_7 -> V_124 , V_50 ) ;
F_46 () ;
break;
case V_128 :
while ( V_7 -> V_1 [ V_23 ] -> V_4 > 0 ) {
F_4 ( V_7 -> V_1 [ V_23 ] ) ;
}
F_23 ( & V_7 -> V_124 , V_50 ) ;
F_40 ( V_5 , V_83 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
if ( V_7 -> V_27 [ V_5 ] == V_23 ) {
V_7 -> V_27 [ V_5 ] = - 1 ;
V_7 -> V_26 [ V_5 ] = - 1 ;
V_7 -> V_126 [ V_5 ] &= ~ V_127 ;
}
V_7 -> V_129 -- ;
V_7 -> V_130 -= V_7 -> V_1 [ V_23 ] -> V_130 ;
F_50 ( V_7 -> V_1 [ V_23 ] -> V_131 ) ;
F_50 ( V_7 -> V_1 [ V_23 ] -> V_132 ) ;
for ( V_5 = 0 ; V_5 < V_7 -> V_1 [ V_23 ] -> V_130 ; V_5 ++ )
F_51 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_5 ] ) ;
F_50 ( V_7 -> V_1 [ V_23 ] -> V_133 ) ;
F_50 ( V_7 -> V_1 [ V_23 ] -> V_59 ) ;
F_50 ( V_7 -> V_1 [ V_23 ] ) ;
V_7 -> V_1 [ V_23 ] = NULL ;
V_7 -> V_113 [ V_23 ] [ 0 ] = '\0' ;
F_46 () ;
F_41 () ;
F_24 ( & V_7 -> V_124 , V_50 ) ;
return 0 ;
case V_134 :
break;
case V_135 :
return ( F_35 ( & V_83 -> V_78 . V_136 ) ) ;
#ifdef F_52
case V_137 :
F_40 ( V_5 , V_83 ) ;
break;
#endif
#ifdef F_53
case V_138 :
F_40 ( V_5 , V_83 ) ;
break;
#endif
#ifdef F_45
case V_139 :
case V_140 :
if ( V_100 )
return ( V_100 -> V_101 ( V_83 ) ) ;
#endif
default:
return - 1 ;
}
return 0 ;
}
int
F_54 ( char * * V_9 )
{
int V_141 = - 1 ;
while ( * V_9 [ 0 ] >= '0' && * V_9 [ 0 ] <= '9' )
V_141 = ( ( V_141 < 0 ) ? 0 : ( V_141 * 10 ) ) + ( int ) ( ( * V_9 [ 0 ] ++ ) - '0' ) ;
return V_141 ;
}
int
F_55 ( int V_23 , int V_53 , T_2 * V_142 , T_2 * V_143 , int V_10 , T_8 * V_144 )
{
int V_145 ;
int V_146 ;
int V_147 ;
int V_148 ;
struct V_54 * V_55 ;
T_2 * V_149 ;
if ( ! V_7 -> V_1 [ V_23 ] )
return 0 ;
if ( F_56 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_53 ] ) ) {
if ( V_144 )
F_57 ( * V_144 ,
! F_56 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_53 ] ) ) ;
else
return 0 ;
}
if ( V_10 > V_7 -> V_1 [ V_23 ] -> V_132 [ V_53 ] )
V_10 = V_7 -> V_1 [ V_23 ] -> V_132 [ V_53 ] ;
V_149 = V_142 ;
V_145 = 0 ;
while ( V_10 ) {
if ( ! ( V_55 = F_58 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_53 ] ) ) )
break;
#ifdef F_53
if ( F_59 ( V_55 ) )
break;
F_59 ( V_55 ) = 1 ;
if ( ( F_60 ( V_55 ) ) || ( V_7 -> V_1 [ V_23 ] -> V_150 & ( 1 << V_53 ) ) ) {
char * V_9 = V_55 -> V_151 ;
unsigned long V_152 = ( 1 << V_53 ) ;
V_148 = 0 ;
V_146 = V_147 = 0 ;
while ( ( V_146 < V_55 -> V_10 ) && ( V_10 > 0 ) ) {
V_10 -- ;
if ( V_7 -> V_1 [ V_23 ] -> V_150 & V_152 ) {
* V_149 ++ = V_153 ;
V_7 -> V_1 [ V_23 ] -> V_150 &= ~ V_152 ;
} else {
* V_149 ++ = * V_9 ;
if ( * V_9 == V_153 ) {
V_7 -> V_1 [ V_23 ] -> V_150 |= V_152 ;
( F_60 ( V_55 ) ) -- ;
}
V_9 ++ ;
V_146 ++ ;
}
V_147 ++ ;
}
if ( V_146 >= V_55 -> V_10 )
V_148 = 1 ;
} else {
#endif
V_148 = 1 ;
if ( ( V_146 = V_55 -> V_10 ) > V_10 ) {
V_146 = V_10 ;
V_148 = 0 ;
}
V_147 = V_146 ;
F_61 ( V_55 , V_149 , V_147 ) ;
V_149 += V_147 ;
V_10 -= V_147 ;
#ifdef F_53
}
#endif
V_145 += V_147 ;
if ( V_143 ) {
memset ( V_143 , 0 , V_147 ) ;
V_143 += V_147 ;
}
if ( V_148 ) {
if ( V_143 )
* ( V_143 - 1 ) = 0xff ;
#ifdef F_53
F_59 ( V_55 ) = 0 ;
#endif
V_55 = F_62 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_53 ] ) ;
F_26 ( V_55 ) ;
} else {
F_63 ( V_55 , V_146 ) ;
#ifdef F_53
F_59 ( V_55 ) = 0 ;
#endif
}
V_7 -> V_1 [ V_23 ] -> V_132 [ V_53 ] -= V_147 ;
}
return V_145 ;
}
int
F_64 ( int V_23 , int V_53 , struct V_154 * V_155 , int V_156 )
{
int V_145 ;
int V_146 ;
int V_147 ;
int V_148 ;
struct V_54 * V_55 ;
char V_14 = 0 ;
int V_10 ;
if ( ! V_7 -> V_1 [ V_23 ] )
return 0 ;
if ( F_56 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_53 ] ) )
return 0 ;
V_10 = F_65 ( V_155 , V_7 -> V_1 [ V_23 ] -> V_132 [ V_53 ] ) ;
if ( V_10 == 0 )
return V_10 ;
V_145 = 0 ;
while ( V_10 ) {
if ( ! ( V_55 = F_58 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_53 ] ) ) )
break;
#ifdef F_53
if ( F_59 ( V_55 ) )
break;
F_59 ( V_55 ) = 1 ;
if ( ( F_60 ( V_55 ) ) || ( V_7 -> V_1 [ V_23 ] -> V_150 & ( 1 << V_53 ) ) ) {
char * V_9 = V_55 -> V_151 ;
unsigned long V_152 = ( 1 << V_53 ) ;
V_148 = 0 ;
V_146 = V_147 = 0 ;
while ( ( V_146 < V_55 -> V_10 ) && ( V_10 > 0 ) ) {
if ( V_147 )
F_66 ( V_155 , V_14 , V_157 ) ;
V_10 -- ;
if ( V_7 -> V_1 [ V_23 ] -> V_150 & V_152 ) {
V_14 = V_153 ;
V_7 -> V_1 [ V_23 ] -> V_150 &= ~ V_152 ;
} else {
V_14 = * V_9 ;
if ( V_14 == V_153 ) {
V_7 -> V_1 [ V_23 ] -> V_150 |= V_152 ;
( F_60 ( V_55 ) ) -- ;
}
V_9 ++ ;
V_146 ++ ;
}
V_147 ++ ;
}
if ( V_146 >= V_55 -> V_10 )
V_148 = 1 ;
} else {
#endif
V_148 = 1 ;
if ( ( V_146 = V_55 -> V_10 ) > V_10 ) {
V_146 = V_10 ;
V_148 = 0 ;
}
V_147 = V_146 ;
if ( V_147 > 1 )
F_67 ( V_155 , V_55 -> V_151 , V_147 - 1 ) ;
V_14 = V_55 -> V_151 [ V_147 - 1 ] ;
V_10 -= V_147 ;
#ifdef F_53
}
#endif
V_145 += V_147 ;
if ( V_148 ) {
if ( V_156 )
F_66 ( V_155 , V_14 , 0xFF ) ;
else
F_66 ( V_155 , V_14 , V_157 ) ;
#ifdef F_53
F_59 ( V_55 ) = 0 ;
#endif
V_55 = F_62 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_53 ] ) ;
F_26 ( V_55 ) ;
} else {
F_66 ( V_155 , V_14 , V_157 ) ;
F_63 ( V_55 , V_146 ) ;
#ifdef F_53
F_59 ( V_55 ) = 0 ;
#endif
}
V_7 -> V_1 [ V_23 ] -> V_132 [ V_53 ] -= V_147 ;
}
return V_145 ;
}
static inline int
F_68 ( int V_158 )
{
return ( V_7 -> V_27 [ V_158 ] ) ;
}
static inline int
F_69 ( int V_158 )
{
return ( V_7 -> V_26 [ V_158 ] ) ;
}
static char *
F_70 ( void )
{
static char V_159 [ 2048 ] ;
char * V_9 ;
int V_5 ;
sprintf ( V_159 , L_20 ) ;
V_9 = V_159 + strlen ( V_159 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
sprintf ( V_9 , L_21 , ( V_7 -> V_27 [ V_5 ] < 0 ) ? L_22 : V_7 -> V_113 [ V_7 -> V_27 [ V_5 ] ] ) ;
V_9 = V_159 + strlen ( V_159 ) ;
}
sprintf ( V_9 , L_23 ) ;
V_9 = V_159 + strlen ( V_159 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
sprintf ( V_9 , L_24 , V_7 -> V_26 [ V_5 ] ) ;
V_9 = V_159 + strlen ( V_159 ) ;
}
sprintf ( V_9 , L_25 ) ;
V_9 = V_159 + strlen ( V_159 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
sprintf ( V_9 , L_24 , V_7 -> V_27 [ V_5 ] ) ;
V_9 = V_159 + strlen ( V_159 ) ;
}
sprintf ( V_9 , L_26 ) ;
V_9 = V_159 + strlen ( V_159 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
sprintf ( V_9 , L_24 , V_7 -> V_126 [ V_5 ] ) ;
V_9 = V_159 + strlen ( V_159 ) ;
}
sprintf ( V_9 , L_27 ) ;
V_9 = V_159 + strlen ( V_159 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_7 -> V_1 [ V_5 ] ) {
sprintf ( V_9 , L_28 , V_7 -> V_1 [ V_5 ] -> V_119 ) ;
V_9 = V_159 + strlen ( V_159 ) ;
} else {
sprintf ( V_9 , L_29 ) ;
V_9 = V_159 + strlen ( V_159 ) ;
}
}
sprintf ( V_9 , L_30 ) ;
V_9 = V_159 + strlen ( V_159 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
sprintf ( V_9 , L_21 , V_7 -> V_79 [ V_5 ] ) ;
V_9 = V_159 + strlen ( V_159 ) ;
}
sprintf ( V_9 , L_3 ) ;
return V_159 ;
}
void
F_46 ( void )
{
T_9 * V_9 = V_7 -> V_160 ;
while ( V_9 ) {
* ( V_9 -> V_161 ) = 1 ;
V_9 = ( T_9 * ) V_9 -> V_105 ;
}
F_32 ( & ( V_7 -> V_162 ) ) ;
}
static T_10
F_71 ( struct V_163 * V_163 , char T_11 * V_142 , T_12 V_145 , T_13 * V_164 )
{
T_14 V_158 = F_72 ( F_73 ( V_163 ) ) ;
int V_10 = 0 ;
int V_165 ;
int V_166 ;
int V_85 ;
char * V_9 ;
F_74 ( & V_167 ) ;
if ( V_158 == V_168 ) {
if ( ! V_163 -> V_169 ) {
if ( V_163 -> V_170 & V_171 ) {
V_85 = - V_172 ;
goto V_173;
}
F_57 ( V_7 -> V_162 ,
V_163 -> V_169 ) ;
}
V_9 = F_70 () ;
V_163 -> V_169 = NULL ;
if ( ( V_10 = strlen ( V_9 ) ) <= V_145 ) {
if ( F_75 ( V_142 , V_9 , V_10 ) ) {
V_85 = - V_174 ;
goto V_173;
}
* V_164 += V_10 ;
V_85 = V_10 ;
goto V_173;
}
V_85 = 0 ;
goto V_173;
}
if ( ! V_7 -> V_129 ) {
V_85 = - V_175 ;
goto V_173;
}
if ( V_158 <= V_176 ) {
F_8 ( V_62 L_31 , V_158 ) ;
V_165 = F_68 ( V_158 ) ;
if ( V_165 < 0 ) {
V_85 = - V_175 ;
goto V_173;
}
if ( ! ( V_7 -> V_1 [ V_165 ] -> V_50 & V_94 ) ) {
V_85 = - V_175 ;
goto V_173;
}
V_166 = F_69 ( V_158 ) ;
if ( ! ( V_9 = F_76 ( V_145 , V_177 ) ) ) {
V_85 = - V_178 ;
goto V_173;
}
V_10 = F_55 ( V_165 , V_166 , V_9 , NULL , V_145 ,
& V_7 -> V_1 [ V_165 ] -> V_59 [ V_166 ] ) ;
* V_164 += V_10 ;
if ( F_75 ( V_142 , V_9 , V_10 ) )
V_10 = - V_174 ;
F_50 ( V_9 ) ;
V_85 = V_10 ;
goto V_173;
}
if ( V_158 <= V_179 ) {
V_165 = F_68 ( V_158 - V_180 ) ;
if ( V_165 < 0 ) {
V_85 = - V_175 ;
goto V_173;
}
if ( ! V_7 -> V_1 [ V_165 ] -> V_91 ) {
if ( V_163 -> V_170 & V_171 ) {
V_85 = - V_172 ;
goto V_173;
}
F_57 ( V_7 -> V_1 [ V_165 ] -> V_92 ,
V_7 -> V_1 [ V_165 ] -> V_91 ) ;
}
if ( V_7 -> V_1 [ V_165 ] -> V_2 -> V_181 ) {
if ( V_145 > V_7 -> V_1 [ V_165 ] -> V_91 )
V_145 = V_7 -> V_1 [ V_165 ] -> V_91 ;
V_10 = V_7 -> V_1 [ V_165 ] -> V_2 -> V_181 ( V_142 , V_145 ,
V_165 , F_69 ( V_158 - V_180 ) ) ;
if ( V_10 < 0 ) {
V_85 = V_10 ;
goto V_173;
}
} else {
V_10 = 0 ;
}
if ( V_10 )
V_7 -> V_1 [ V_165 ] -> V_91 -= V_10 ;
else
V_7 -> V_1 [ V_165 ] -> V_91 = 0 ;
* V_164 += V_10 ;
V_85 = V_10 ;
goto V_173;
}
#ifdef F_77
if ( V_158 <= V_182 ) {
V_85 = F_78 ( V_158 - V_183 , V_163 , V_142 , V_145 ) ;
goto V_173;
}
#endif
V_85 = - V_175 ;
V_173:
F_79 ( & V_167 ) ;
return V_85 ;
}
static T_10
F_80 ( struct V_163 * V_163 , const char T_11 * V_142 , T_12 V_145 , T_13 * V_164 )
{
T_14 V_158 = F_72 ( F_73 ( V_163 ) ) ;
int V_165 ;
int V_166 ;
int V_85 ;
if ( V_158 == V_168 )
return - V_184 ;
if ( ! V_7 -> V_129 )
return - V_175 ;
F_74 ( & V_167 ) ;
if ( V_158 <= V_176 ) {
F_8 ( V_62 L_32 , V_158 ) ;
V_165 = F_68 ( V_158 ) ;
if ( V_165 < 0 ) {
V_85 = - V_175 ;
goto V_173;
}
if ( ! ( V_7 -> V_1 [ V_165 ] -> V_50 & V_94 ) ) {
V_85 = - V_175 ;
goto V_173;
}
V_166 = F_69 ( V_158 ) ;
F_57 ( V_7 -> V_1 [ V_165 ] -> V_89 [ V_166 ] ,
( V_85 = F_81 ( V_165 , V_166 , V_142 , V_145 ) ) ) ;
goto V_173;
}
if ( V_158 <= V_179 ) {
V_165 = F_68 ( V_158 - V_180 ) ;
if ( V_165 < 0 ) {
V_85 = - V_175 ;
goto V_173;
}
if ( V_7 -> V_1 [ V_165 ] -> V_2 -> V_185 )
V_85 = V_7 -> V_1 [ V_165 ] -> V_2 ->
V_185 ( V_142 , V_145 , V_165 ,
F_69 ( V_158 - V_180 ) ) ;
else
V_85 = V_145 ;
goto V_173;
}
#ifdef F_77
if ( V_158 <= V_182 ) {
V_85 = F_82 ( V_158 - V_183 , V_163 , V_142 , V_145 ) ;
goto V_173;
}
#endif
V_85 = - V_175 ;
V_173:
F_79 ( & V_167 ) ;
return V_85 ;
}
static unsigned int
F_83 ( struct V_163 * V_163 , T_15 * V_186 )
{
unsigned int V_187 = 0 ;
unsigned int V_158 = F_72 ( F_73 ( V_163 ) ) ;
int V_165 = F_68 ( V_158 - V_180 ) ;
F_74 ( & V_167 ) ;
if ( V_158 == V_168 ) {
F_84 ( V_163 , & ( V_7 -> V_162 ) , V_186 ) ;
if ( V_163 -> V_169 ) {
V_187 |= V_188 | V_189 ;
}
goto V_173;
}
if ( V_158 >= V_180 && V_158 <= V_179 ) {
if ( V_165 < 0 ) {
V_187 = V_190 ;
goto V_173;
}
F_84 ( V_163 , & ( V_7 -> V_1 [ V_165 ] -> V_92 ) , V_186 ) ;
V_187 = V_191 | V_192 ;
if ( V_7 -> V_1 [ V_165 ] -> V_91 ) {
V_187 |= V_188 | V_189 ;
}
goto V_173;
}
#ifdef F_77
if ( V_158 <= V_182 ) {
V_187 = F_85 ( V_163 , V_186 ) ;
goto V_173;
}
#endif
V_187 = V_193 ;
V_173:
F_79 ( & V_167 ) ;
return V_187 ;
}
static int
F_86 ( struct V_163 * V_163 , T_14 V_60 , T_3 V_66 )
{
T_14 V_158 = F_72 ( F_73 ( V_163 ) ) ;
T_4 V_83 ;
int V_165 ;
int V_194 ;
int V_5 ;
char T_11 * V_9 ;
char * V_8 ;
union T_16 {
char V_195 [ 10 ] ;
char V_196 [ 22 ] ;
T_17 V_197 ;
T_18 V_198 ;
T_19 V_199 ;
} T_16 ;
void T_11 * V_200 = ( void T_11 * ) V_66 ;
#define V_195 iocpar.name
#define V_196 iocpar.bname
#define V_197 iocpar.iocts
#define V_198 iocpar.phone
#define V_199 iocpar.cfg
if ( V_158 == V_168 ) {
switch ( V_60 ) {
case V_201 :
return ( V_202 +
( V_203 << 8 ) +
( V_204 << 16 ) ) ;
case V_205 :
if ( V_66 ) {
T_3 T_11 * V_9 = V_200 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
F_87 ( V_7 -> V_56 [ V_5 ] , V_9 ++ ) ;
F_87 ( V_7 -> V_206 [ V_5 ] , V_9 ++ ) ;
}
return 0 ;
} else
return - V_207 ;
break;
case V_208 :
if ( V_66 ) {
if ( F_88 ( & V_198 , V_200 , sizeof( V_198 ) ) )
return - V_174 ;
return F_89 ( & V_198 , V_200 ) ;
} else
return - V_207 ;
default:
return - V_207 ;
}
}
if ( ! V_7 -> V_129 )
return - V_175 ;
if ( V_158 <= V_176 ) {
V_165 = F_68 ( V_158 ) ;
if ( V_165 < 0 )
return - V_175 ;
if ( ! ( V_7 -> V_1 [ V_165 ] -> V_50 & V_94 ) )
return - V_175 ;
return 0 ;
}
if ( V_158 <= V_179 ) {
switch ( V_60 ) {
case V_209 :
F_8 ( V_110 L_33 ) ;
return ( - V_207 ) ;
case V_210 :
F_8 ( V_110 L_34 ) ;
return - V_175 ;
case V_211 :
if ( V_66 ) {
if ( F_88 ( V_195 , V_200 , sizeof( V_195 ) ) )
return - V_174 ;
V_8 = V_195 ;
} else {
V_8 = NULL ;
}
V_194 = F_90 ( & V_7 -> V_212 ) ;
if ( V_194 ) return V_194 ;
if ( ( V_8 = F_91 ( V_8 , NULL ) ) ) {
if ( F_75 ( V_200 , V_8 , strlen ( V_8 ) + 1 ) ) {
V_194 = - V_174 ;
} else {
V_194 = 0 ;
}
} else
V_194 = - V_175 ;
F_79 ( & V_7 -> V_212 ) ;
return V_194 ;
case V_213 :
if ( V_66 ) {
if ( F_88 ( V_196 , V_200 , sizeof( V_196 ) - 1 ) )
return - V_174 ;
V_196 [ sizeof( V_196 ) - 1 ] = 0 ;
} else
return - V_207 ;
V_194 = F_90 ( & V_7 -> V_212 ) ;
if ( V_194 ) return V_194 ;
if ( ( V_8 = F_92 ( V_196 ) ) ) {
if ( F_75 ( V_200 , V_8 , strlen ( V_8 ) + 1 ) ) {
V_194 = - V_174 ;
} else {
V_194 = 0 ;
}
} else
V_194 = - V_175 ;
F_79 ( & V_7 -> V_212 ) ;
return V_194 ;
case V_214 :
if ( V_66 ) {
if ( F_88 ( V_195 , V_200 , sizeof( V_195 ) ) )
return - V_174 ;
V_194 = F_90 ( & V_7 -> V_212 ) ;
if ( V_194 ) return V_194 ;
V_194 = F_93 ( V_195 ) ;
F_79 ( & V_7 -> V_212 ) ;
return V_194 ;
} else
return - V_207 ;
case V_215 :
if ( V_66 ) {
if ( F_88 ( & V_199 , V_200 , sizeof( V_199 ) ) )
return - V_174 ;
return F_94 ( & V_199 ) ;
} else
return - V_207 ;
case V_216 :
if ( V_66 ) {
if ( F_88 ( & V_199 , V_200 , sizeof( V_199 ) ) )
return - V_174 ;
if ( ! ( V_194 = F_95 ( & V_199 ) ) ) {
if ( F_75 ( V_200 , & V_199 , sizeof( V_199 ) ) )
return - V_174 ;
}
return V_194 ;
} else
return - V_207 ;
case V_217 :
if ( V_66 ) {
if ( F_88 ( & V_198 , V_200 , sizeof( V_198 ) ) )
return - V_174 ;
V_194 = F_90 ( & V_7 -> V_212 ) ;
if ( V_194 ) return V_194 ;
V_194 = F_96 ( & V_198 ) ;
F_79 ( & V_7 -> V_212 ) ;
return V_194 ;
} else
return - V_207 ;
case V_218 :
if ( V_66 ) {
if ( F_88 ( & V_198 , V_200 , sizeof( V_198 ) ) )
return - V_174 ;
V_194 = F_90 ( & V_7 -> V_212 ) ;
if ( V_194 ) return V_194 ;
V_194 = F_97 ( & V_198 , V_200 ) ;
F_79 ( & V_7 -> V_212 ) ;
return V_194 ;
} else
return - V_207 ;
case V_219 :
if ( V_66 ) {
if ( F_88 ( & V_198 , V_200 , sizeof( V_198 ) ) )
return - V_174 ;
V_194 = F_90 ( & V_7 -> V_212 ) ;
if ( V_194 ) return V_194 ;
V_194 = F_98 ( & V_198 ) ;
F_79 ( & V_7 -> V_212 ) ;
return V_194 ;
} else
return - V_207 ;
case V_220 :
if ( V_66 ) {
if ( F_88 ( V_195 , V_200 , sizeof( V_195 ) ) )
return - V_174 ;
return F_99 ( V_195 ) ;
} else
return - V_207 ;
#ifdef F_77
case V_221 :
if ( ! V_66 )
return - V_207 ;
if ( F_88 ( V_195 , V_200 , sizeof( V_195 ) ) )
return - V_174 ;
return F_100 ( V_195 ) ;
case V_222 :
if ( ! V_66 )
return - V_207 ;
if ( F_88 ( V_195 , V_200 , sizeof( V_195 ) ) )
return - V_174 ;
return F_101 ( V_195 ) ;
#endif
case V_223 :
if ( ! V_66 )
return - V_207 ;
if ( F_88 ( V_195 , V_200 , sizeof( V_195 ) ) )
return - V_174 ;
return F_102 ( V_195 ) ;
break;
case V_224 :
V_7 -> V_225 = V_66 ;
F_8 ( V_110 L_35 , V_7 -> V_225 ) ;
return 0 ;
case V_226 :
if ( V_66 )
V_7 -> V_87 |= V_88 ;
else
V_7 -> V_87 &= ~ V_88 ;
F_8 ( V_110 L_36 ,
( V_7 -> V_87 & V_88 ) ? L_37 : L_38 ) ;
return 0 ;
case V_227 :
V_165 = - 1 ;
if ( V_66 ) {
int V_5 ;
char * V_9 ;
if ( F_88 ( & V_197 , V_200 ,
sizeof( T_17 ) ) )
return - V_174 ;
V_197 . V_113 [ sizeof( V_197 . V_113 ) - 1 ] = 0 ;
if ( strlen ( V_197 . V_113 ) ) {
if ( ( V_9 = strchr ( V_197 . V_113 , ',' ) ) )
* V_9 = 0 ;
V_165 = - 1 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( ! ( strcmp ( V_7 -> V_113 [ V_5 ] , V_197 . V_113 ) ) ) {
V_165 = V_5 ;
break;
}
}
}
if ( V_165 == - 1 )
return - V_175 ;
if ( V_197 . V_66 )
V_7 -> V_1 [ V_165 ] -> V_50 |= V_102 ;
else
V_7 -> V_1 [ V_165 ] -> V_50 &= ~ V_102 ;
return 0 ;
case V_228 :
V_7 -> V_229 = V_230 ;
return 0 ;
break;
case V_231 :
if ( V_66 ) {
char T_11 * V_9 = V_200 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
if ( F_75 ( V_9 , V_7 -> V_232 . V_233 [ V_5 ] . V_234 . V_235 ,
V_236 ) )
return - V_174 ;
V_9 += V_236 ;
if ( F_75 ( V_9 , V_7 -> V_232 . V_233 [ V_5 ] . V_234 . V_237 , V_21 ) )
return - V_174 ;
V_9 += V_21 ;
if ( F_75 ( V_9 , V_7 -> V_232 . V_233 [ V_5 ] . V_234 . V_238 , V_239 ) )
return - V_174 ;
V_9 += V_239 ;
}
return ( V_236 + V_21 + V_239 ) * V_25 ;
} else
return - V_207 ;
break;
case V_240 :
if ( V_66 ) {
char T_11 * V_9 = V_200 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
if ( F_88 ( V_7 -> V_232 . V_233 [ V_5 ] . V_234 . V_235 , V_9 ,
V_236 ) )
return - V_174 ;
V_9 += V_236 ;
if ( F_88 ( V_7 -> V_232 . V_233 [ V_5 ] . V_234 . V_238 , V_9 , V_239 ) )
return - V_174 ;
V_9 += V_239 ;
if ( F_88 ( V_7 -> V_232 . V_233 [ V_5 ] . V_234 . V_237 , V_9 , V_21 ) )
return - V_174 ;
V_9 += V_21 ;
}
return 0 ;
} else
return - V_207 ;
break;
case V_241 :
case V_242 :
if ( V_66 ) {
if ( F_88 ( & V_197 , V_200 ,
sizeof( T_17 ) ) )
return - V_174 ;
V_197 . V_113 [ sizeof( V_197 . V_113 ) - 1 ] = 0 ;
if ( strlen ( V_197 . V_113 ) ) {
V_165 = - 1 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( ! ( strcmp ( V_7 -> V_113 [ V_5 ] , V_197 . V_113 ) ) ) {
V_165 = V_5 ;
break;
}
} else
V_165 = 0 ;
if ( V_165 == - 1 )
return - V_175 ;
if ( V_60 == V_241 ) {
int V_243 = 1 ;
V_9 = ( char T_11 * ) V_197 . V_66 ;
V_5 = 0 ;
while ( V_243 ) {
int V_244 = 0 ;
while ( 1 ) {
F_103 ( V_196 [ V_244 ] , V_9 ++ ) ;
switch ( V_196 [ V_244 ] ) {
case '\0' :
V_243 = 0 ;
case ',' :
V_196 [ V_244 ] = '\0' ;
strcpy ( V_7 -> V_1 [ V_165 ] -> V_245 [ V_5 ] , V_196 ) ;
V_244 = V_21 ;
break;
default:
V_244 ++ ;
}
if ( V_244 >= V_21 )
break;
}
if ( ++ V_5 > 9 )
break;
}
} else {
V_9 = ( char T_11 * ) V_197 . V_66 ;
for ( V_5 = 0 ; V_5 < 10 ; V_5 ++ ) {
snprintf ( V_196 , sizeof( V_196 ) , L_39 ,
strlen ( V_7 -> V_1 [ V_165 ] -> V_245 [ V_5 ] ) ?
V_7 -> V_1 [ V_165 ] -> V_245 [ V_5 ] : L_40 ,
( V_5 < 9 ) ? L_41 : L_42 ) ;
if ( F_75 ( V_9 , V_196 , strlen ( V_196 ) + 1 ) )
return - V_174 ;
V_9 += strlen ( V_196 ) ;
}
}
return 0 ;
} else
return - V_207 ;
case V_246 :
if ( V_66 ) {
if ( F_75 ( V_200 , & V_7 , sizeof( T_3 ) ) )
return - V_174 ;
return 0 ;
} else
return - V_207 ;
break;
default:
if ( ( V_60 & V_247 ) == V_247 )
V_60 = ( ( V_60 >> V_248 ) & V_249 ) & V_250 ;
else
return - V_207 ;
if ( V_66 ) {
int V_5 ;
char * V_9 ;
if ( F_88 ( & V_197 , V_200 , sizeof( T_17 ) ) )
return - V_174 ;
V_197 . V_113 [ sizeof( V_197 . V_113 ) - 1 ] = 0 ;
if ( strlen ( V_197 . V_113 ) ) {
if ( ( V_9 = strchr ( V_197 . V_113 , ',' ) ) )
* V_9 = 0 ;
V_165 = - 1 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( ! ( strcmp ( V_7 -> V_113 [ V_5 ] , V_197 . V_113 ) ) ) {
V_165 = V_5 ;
break;
}
} else
V_165 = 0 ;
if ( V_165 == - 1 )
return - V_175 ;
V_83 . V_61 = V_165 ;
V_83 . V_63 = V_251 ;
V_83 . V_66 = V_60 ;
memcpy ( V_83 . V_78 . V_79 , & V_197 . V_66 , sizeof( T_3 ) ) ;
V_194 = F_33 ( & V_83 ) ;
memcpy ( & V_197 . V_66 , V_83 . V_78 . V_79 , sizeof( T_3 ) ) ;
if ( F_75 ( V_200 , & V_197 , sizeof( T_17 ) ) )
return - V_174 ;
return V_194 ;
} else
return - V_207 ;
}
}
#ifdef F_77
if ( V_158 <= V_182 )
return ( F_104 ( V_158 - V_183 , V_163 , V_60 , V_66 ) ) ;
#endif
return - V_175 ;
#undef V_195
#undef V_196
#undef V_197
#undef V_198
#undef V_199
}
static long
F_105 ( struct V_163 * V_163 , unsigned int V_60 , unsigned long V_66 )
{
int V_194 ;
F_74 ( & V_167 ) ;
V_194 = F_86 ( V_163 , V_60 , V_66 ) ;
F_79 ( & V_167 ) ;
return V_194 ;
}
static int
F_106 ( struct V_252 * V_253 , struct V_163 * V_254 )
{
T_14 V_158 = F_72 ( V_253 ) ;
int V_165 ;
int V_166 ;
int V_85 = - V_175 ;
F_74 ( & V_167 ) ;
if ( V_158 == V_168 ) {
T_9 * V_9 ;
if ( ( V_9 = F_76 ( sizeof( T_9 ) , V_177 ) ) ) {
V_9 -> V_105 = ( char * ) V_7 -> V_160 ;
V_9 -> V_161 = ( char * ) & ( V_254 -> V_169 ) ;
V_7 -> V_160 = V_9 ;
V_254 -> V_169 = ( char * ) 1 ;
V_85 = 0 ;
goto V_173;
} else {
V_85 = - V_178 ;
goto V_173;
}
}
if ( ! V_7 -> V_130 )
goto V_173;
if ( V_158 <= V_176 ) {
F_8 ( V_62 L_43 , V_158 ) ;
V_165 = F_68 ( V_158 ) ;
if ( V_165 < 0 )
goto V_173;
V_166 = F_69 ( V_158 ) ;
if ( ! ( V_7 -> V_1 [ V_165 ] -> V_50 & V_94 ) )
goto V_173;
if ( ! ( V_7 -> V_1 [ V_165 ] -> V_119 & ( 1 << V_166 ) ) )
goto V_173;
F_3 () ;
V_85 = 0 ;
goto V_173;
}
if ( V_158 <= V_179 ) {
V_165 = F_68 ( V_158 - V_180 ) ;
if ( V_165 < 0 )
goto V_173;
F_3 () ;
V_85 = 0 ;
goto V_173;
}
#ifdef F_77
if ( V_158 <= V_182 ) {
V_85 = F_107 ( V_158 - V_183 , V_254 ) ;
if ( V_85 == 0 )
F_3 () ;
goto V_173;
}
#endif
V_173:
F_108 ( V_253 , V_254 ) ;
F_79 ( & V_167 ) ;
return V_85 ;
}
static int
F_109 ( struct V_252 * V_253 , struct V_163 * V_254 )
{
T_14 V_158 = F_72 ( V_253 ) ;
F_74 ( & V_167 ) ;
if ( V_158 == V_168 ) {
T_9 * V_9 = V_7 -> V_160 ;
T_9 * V_255 = NULL ;
while ( V_9 ) {
if ( V_9 -> V_161 == ( char * ) & ( V_254 -> V_169 ) ) {
if ( V_255 )
V_255 -> V_105 = V_9 -> V_105 ;
else
V_7 -> V_160 = ( T_9 * ) ( V_9 -> V_105 ) ;
F_50 ( V_9 ) ;
goto V_173;
}
V_255 = V_9 ;
V_9 = ( T_9 * ) ( V_9 -> V_105 ) ;
}
F_8 ( V_62 L_44 ) ;
goto V_173;
}
F_6 () ;
if ( V_158 <= V_176 )
goto V_173;
if ( V_158 <= V_179 ) {
if ( V_7 -> V_229 == V_230 )
V_7 -> V_229 = NULL ;
goto V_173;
}
#ifdef F_77
if ( V_158 <= V_182 )
F_110 ( V_158 - V_183 , V_254 ) ;
#endif
V_173:
F_79 ( & V_167 ) ;
return 0 ;
}
char *
F_111 ( char * V_109 , int V_23 )
{
T_1 * V_256 = V_7 -> V_1 [ V_23 ] ;
int V_5 ;
if ( strlen ( V_109 ) == 1 ) {
V_5 = V_109 [ 0 ] - '0' ;
if ( ( V_5 >= 0 ) && ( V_5 <= 9 ) )
if ( strlen ( V_256 -> V_245 [ V_5 ] ) )
return ( V_256 -> V_245 [ V_5 ] ) ;
}
return ( V_109 ) ;
}
int
F_112 ( int V_126 , int V_257 , int V_258 , int V_259
, int V_260 , char * V_109 )
{
int V_5 ;
T_3 V_68 ;
T_3 V_261 ;
V_68 = ( ( 1 << V_257 ) | ( 0x10000 << V_258 ) ) ;
V_261 = ( ( ( 1 << V_257 ) | ( 0x10000 << V_258 ) ) &
~ ( V_262 | V_263 | V_264 ) ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
if ( F_49 ( V_7 -> V_126 [ V_5 ] ) &&
( V_7 -> V_27 [ V_5 ] != - 1 ) ) {
int V_265 = V_7 -> V_27 [ V_5 ] ;
if ( ( V_7 -> V_126 [ V_5 ] & V_266 ) &&
( ( V_259 != V_265 ) || ( V_260 != V_7 -> V_26 [ V_5 ] ) ) )
continue;
if ( ! strcmp ( F_111 ( V_109 , V_265 ) , L_22 ) )
continue;
if ( V_7 -> V_126 [ V_5 ] & V_127 )
continue;
if ( V_7 -> V_1 [ V_265 ] -> V_50 & V_94 ) {
if ( ( ( V_7 -> V_1 [ V_265 ] -> V_2 -> V_68 & V_68 ) == V_68 ) ||
( ( ( V_7 -> V_1 [ V_265 ] -> V_2 -> V_68 & V_261 ) == V_261 ) &&
( V_7 -> V_1 [ V_265 ] -> V_2 -> V_68 & V_267 ) ) ) {
if ( ( V_259 < 0 ) || ( V_260 < 0 ) ) {
V_7 -> V_126 [ V_5 ] &= V_266 ;
V_7 -> V_126 [ V_5 ] |= V_126 ;
F_46 () ;
return V_5 ;
} else {
if ( ( V_259 == V_265 ) && ( V_260 == V_7 -> V_26 [ V_5 ] ) ) {
V_7 -> V_126 [ V_5 ] &= V_266 ;
V_7 -> V_126 [ V_5 ] |= V_126 ;
F_46 () ;
return V_5 ;
}
}
}
}
}
return - 1 ;
}
void
F_113 ( int V_23 , int V_24 , int V_126 )
{
int V_5 ;
if ( ( V_23 < 0 ) || ( V_24 < 0 ) ) {
F_8 ( V_62 L_45 ,
V_268 , V_23 , V_24 ) ;
return;
}
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
if ( ( ( ! V_126 ) || ( ( V_7 -> V_126 [ V_5 ] & V_269 ) == V_126 ) ) &&
( V_7 -> V_27 [ V_5 ] == V_23 ) &&
( V_7 -> V_26 [ V_5 ] == V_24 ) ) {
V_7 -> V_126 [ V_5 ] &= ( V_270 | V_266 ) ;
strcpy ( V_7 -> V_79 [ V_5 ] , L_46 ) ;
V_7 -> V_56 [ V_5 ] = 0 ;
V_7 -> V_206 [ V_5 ] = 0 ;
V_7 -> V_75 [ V_5 ] = 0 ;
F_114 ( & ( V_7 -> V_58 [ V_5 ] ) , 0 ) ;
F_115 ( V_7 -> V_57 [ V_5 ] ) ;
V_7 -> V_57 [ V_5 ] = NULL ;
F_46 () ;
if ( V_7 -> V_1 [ V_23 ] )
F_51 ( & V_7 -> V_1 [ V_23 ] -> V_133 [ V_24 ] ) ;
}
}
void
F_116 ( int V_23 , int V_24 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
if ( ( V_7 -> V_27 [ V_5 ] == V_23 ) &&
( V_7 -> V_26 [ V_5 ] == V_24 ) ) {
V_7 -> V_126 [ V_5 ] &= ~ V_266 ;
F_46 () ;
return;
}
}
static int
F_81 ( int V_165 , int V_271 , const T_2 T_11 * V_142 , int V_10 )
{
int V_194 ;
int V_272 = V_7 -> V_1 [ V_165 ] -> V_2 -> V_273 ;
struct V_54 * V_55 = F_117 ( V_272 + V_10 , V_274 ) ;
if ( ! V_55 )
return - V_178 ;
F_118 ( V_55 , V_272 ) ;
if ( F_88 ( F_119 ( V_55 , V_10 ) , V_142 , V_10 ) ) {
F_26 ( V_55 ) ;
return - V_174 ;
}
V_194 = V_7 -> V_1 [ V_165 ] -> V_2 -> V_275 ( V_165 , V_271 , 1 , V_55 ) ;
if ( V_194 <= 0 )
F_26 ( V_55 ) ;
if ( V_194 > 0 )
V_7 -> V_206 [ F_12 ( V_165 , V_271 ) ] += V_194 ;
return V_194 ;
}
int
F_120 ( int V_165 , int V_271 , int V_276 , struct V_54 * V_55 )
{
int V_194 ;
struct V_54 * V_277 = NULL ;
int V_278 = V_55 -> V_10 ;
int V_65 = F_12 ( V_165 , V_271 ) ;
if ( V_7 -> V_57 [ V_65 ] ) {
F_28 ( & V_7 -> V_58 [ V_65 ] ) ;
V_277 = F_121 ( V_7 -> V_57 [ V_65 ] , V_55 ) ;
F_30 ( & V_7 -> V_58 [ V_65 ] ) ;
if ( ! V_277 )
return 0 ;
V_278 = * ( ( int * ) V_277 -> V_151 ) ;
F_63 ( V_277 , sizeof( int ) ) ;
if ( ! V_277 -> V_10 ) {
F_26 ( V_277 ) ;
return V_278 ;
}
V_276 = 1 ;
V_194 = V_7 -> V_1 [ V_165 ] -> V_2 -> V_275 ( V_165 , V_271 , V_276 , V_277 ) ;
} else {
int V_272 = V_7 -> V_1 [ V_165 ] -> V_2 -> V_273 ;
if ( F_122 ( V_55 ) < V_272 ) {
struct V_54 * V_279 ;
V_279 = F_123 ( V_55 , V_272 ) ;
F_8 ( V_13 L_47 , V_279 ? L_48 : L_49 ) ;
if ( ! V_279 ) return - V_178 ;
V_194 = V_7 -> V_1 [ V_165 ] -> V_2 -> V_275 ( V_165 , V_271 , V_276 , V_279 ) ;
if ( V_194 > 0 ) {
F_26 ( V_55 ) ;
} else {
F_26 ( V_279 ) ;
}
} else {
V_194 = V_7 -> V_1 [ V_165 ] -> V_2 -> V_275 ( V_165 , V_271 , V_276 , V_55 ) ;
}
}
if ( V_194 > 0 ) {
V_7 -> V_206 [ V_65 ] += V_194 ;
if ( V_7 -> V_57 [ V_65 ] ) {
F_28 ( & V_7 -> V_58 [ V_65 ] ) ;
V_7 -> V_57 [ V_65 ] -> V_280 ++ ;
F_30 ( & V_7 -> V_58 [ V_65 ] ) ;
V_194 = V_278 ;
if ( V_194 == V_55 -> V_10 )
F_26 ( V_55 ) ;
}
} else
if ( V_7 -> V_57 [ V_65 ] )
F_26 ( V_277 ) ;
return V_194 ;
}
static int
F_48 ( T_1 * V_265 , int V_165 , int V_281 , int V_282 )
{
int V_244 , V_283 , V_284 ;
F_124 ( & V_265 -> V_92 ) ;
if ( V_265 -> V_50 & V_94 )
return - 1 ;
if ( V_281 < 1 ) return 0 ;
V_284 = ( V_282 ) ? V_265 -> V_130 + V_281 : V_281 ;
if ( V_7 -> V_130 + V_281 > V_25 ) {
F_8 ( V_62 L_50 ,
V_25 ) ;
return - 1 ;
}
if ( ( V_282 ) && ( V_265 -> V_131 ) )
F_50 ( V_265 -> V_131 ) ;
if ( ! ( V_265 -> V_131 = F_125 ( sizeof( int ) * V_284 , V_274 ) ) ) {
F_8 ( V_62 L_51 ) ;
return - 1 ;
}
if ( ( V_282 ) && ( V_265 -> V_132 ) )
F_50 ( V_265 -> V_132 ) ;
if ( ! ( V_265 -> V_132 = F_125 ( sizeof( int ) * V_284 , V_274 ) ) ) {
F_8 ( V_62 L_52 ) ;
if ( ! V_282 )
F_50 ( V_265 -> V_131 ) ;
return - 1 ;
}
if ( ( V_282 ) && ( V_265 -> V_133 ) ) {
for ( V_244 = 0 ; V_244 < V_265 -> V_130 ; V_244 ++ )
F_51 ( & V_265 -> V_133 [ V_244 ] ) ;
F_50 ( V_265 -> V_133 ) ;
}
if ( ! ( V_265 -> V_133 = F_76 ( sizeof( struct V_285 ) * V_284 , V_274 ) ) ) {
F_8 ( V_62 L_53 ) ;
if ( ! V_282 ) {
F_50 ( V_265 -> V_132 ) ;
F_50 ( V_265 -> V_131 ) ;
}
return - 1 ;
}
for ( V_244 = 0 ; V_244 < V_284 ; V_244 ++ ) {
F_126 ( & V_265 -> V_133 [ V_244 ] ) ;
}
if ( ( V_282 ) && ( V_265 -> V_59 ) )
F_50 ( V_265 -> V_59 ) ;
V_265 -> V_59 = F_76 ( sizeof( T_8 ) * 2 * V_284 , V_274 ) ;
if ( ! V_265 -> V_59 ) {
F_8 ( V_62 L_54 ) ;
if ( ! V_282 ) {
F_50 ( V_265 -> V_133 ) ;
F_50 ( V_265 -> V_132 ) ;
F_50 ( V_265 -> V_131 ) ;
}
return - 1 ;
}
V_265 -> V_89 = V_265 -> V_59 + V_284 ;
for ( V_244 = 0 ; V_244 < V_284 ; V_244 ++ ) {
F_124 ( & V_265 -> V_59 [ V_244 ] ) ;
F_124 ( & V_265 -> V_89 [ V_244 ] ) ;
}
V_7 -> V_130 += V_281 ;
for ( V_244 = V_265 -> V_130 ; V_244 < V_284 ; V_244 ++ )
for ( V_283 = 0 ; V_283 < V_25 ; V_283 ++ )
if ( V_7 -> V_26 [ V_283 ] < 0 ) {
V_7 -> V_26 [ V_283 ] = V_244 ;
V_7 -> V_27 [ V_283 ] = V_165 ;
break;
}
V_265 -> V_130 = V_284 ;
return 0 ;
}
static void
F_41 ( void )
{
int V_165 ;
V_7 -> V_286 = 0 ;
for ( V_165 = 0 ; V_165 < V_6 ; V_165 ++ ) {
if ( ! V_7 -> V_1 [ V_165 ] )
continue;
if ( V_7 -> V_1 [ V_165 ] -> V_2 )
V_7 -> V_286 |= V_7 -> V_1 [ V_165 ] -> V_2 -> V_68 ;
}
}
static char * F_127 ( int V_23 )
{
if ( ( V_23 < 0 ) || ( V_23 >= V_6 ) )
return ( NULL ) ;
return ( V_7 -> V_113 [ V_23 ] ) ;
}
static int F_128 ( char * V_287 )
{ int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
{ if ( ! strcmp ( V_7 -> V_113 [ V_5 ] , V_287 ) )
return ( V_5 ) ;
}
return ( - 1 ) ;
}
int F_129 ( T_20 * V_288 )
{
if ( V_288 -> V_289 != V_290 )
return ( V_291 ) ;
switch ( V_288 -> V_60 )
{
case V_292 :
if ( V_100 != V_288 )
return ( V_293 ) ;
V_100 = NULL ;
return ( V_294 ) ;
case V_295 :
if ( V_100 )
return ( V_296 ) ;
V_288 -> V_297 = F_33 ;
V_288 -> V_298 = F_127 ;
V_288 -> V_299 = F_128 ;
V_100 = V_288 ;
return ( V_294 ) ;
default:
return ( V_300 ) ;
}
}
int
F_130 ( T_21 * V_5 )
{
T_1 * V_265 ;
int V_244 ;
T_3 V_50 ;
int V_165 ;
if ( V_7 -> V_129 >= V_6 ) {
F_8 ( V_62 L_55 ,
V_6 ) ;
return 0 ;
}
if ( ! V_5 -> V_275 ) {
F_8 ( V_62 L_56 ) ;
return 0 ;
}
if ( ! ( V_265 = F_125 ( sizeof( T_1 ) , V_177 ) ) ) {
F_8 ( V_62 L_57 ) ;
return 0 ;
}
V_265 -> V_301 = V_5 -> V_301 ;
V_265 -> V_302 = 0 ;
V_265 -> V_91 = 0 ;
V_265 -> V_50 = V_303 ;
V_265 -> V_119 = 0 ;
V_265 -> V_2 = V_5 ;
V_265 -> V_130 = 0 ;
F_23 ( & V_7 -> V_124 , V_50 ) ;
for ( V_165 = 0 ; V_165 < V_6 ; V_165 ++ )
if ( ! V_7 -> V_1 [ V_165 ] )
break;
if ( F_48 ( V_265 , V_165 , V_5 -> V_130 , 0 ) ) {
F_24 ( & V_7 -> V_124 , V_50 ) ;
F_50 ( V_265 ) ;
return 0 ;
}
V_5 -> V_130 = V_165 ;
V_5 -> V_304 = F_25 ;
V_5 -> V_305 = F_37 ;
if ( ! strlen ( V_5 -> V_287 ) )
sprintf ( V_5 -> V_287 , L_58 , V_165 ) ;
for ( V_244 = 0 ; V_244 < V_165 ; V_244 ++ )
if ( ! strcmp ( V_5 -> V_287 , V_7 -> V_113 [ V_244 ] ) )
sprintf ( V_5 -> V_287 , L_58 , V_165 ) ;
V_7 -> V_1 [ V_165 ] = V_265 ;
strcpy ( V_7 -> V_113 [ V_165 ] , V_5 -> V_287 ) ;
F_46 () ;
V_7 -> V_129 ++ ;
F_41 () ;
F_24 ( & V_7 -> V_124 , V_50 ) ;
return 1 ;
}
static char *
F_131 ( const char * V_306 )
{
char * V_307 ;
char * V_9 ;
if ( ( V_9 = strchr ( V_306 , ':' ) ) ) {
V_307 = V_9 + 2 ;
V_9 = strchr ( V_307 , '$' ) ;
* -- V_9 = 0 ;
} else
V_307 = L_46 ;
return V_307 ;
}
static int T_22 F_132 ( void )
{
int V_5 ;
char V_308 [ 50 ] ;
V_7 = F_133 ( sizeof( V_309 ) ) ;
if ( ! V_7 ) {
F_8 ( V_62 L_59 ) ;
return - V_310 ;
}
F_134 ( & V_7 -> V_46 ) ;
V_7 -> V_46 . V_311 = F_13 ;
F_135 ( & V_7 -> V_124 ) ;
F_135 ( & V_7 -> V_52 ) ;
#ifdef F_136
V_7 -> V_3 = V_312 ;
#endif
F_137 ( & V_7 -> V_212 ) ;
F_124 ( & V_7 -> V_162 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
V_7 -> V_27 [ V_5 ] = - 1 ;
V_7 -> V_26 [ V_5 ] = - 1 ;
V_7 -> V_313 [ V_5 ] = - 1 ;
strcpy ( V_7 -> V_79 [ V_5 ] , L_46 ) ;
}
if ( F_138 ( V_314 , L_60 , & V_315 ) ) {
F_8 ( V_62 L_61 ) ;
F_139 ( V_7 ) ;
return - V_310 ;
}
if ( ( F_140 () ) < 0 ) {
F_8 ( V_62 L_62 ) ;
F_139 ( V_7 ) ;
F_141 ( V_314 , L_60 ) ;
return - V_310 ;
}
#ifdef F_77
if ( F_142 () < 0 ) {
F_8 ( V_62 L_63 ) ;
F_143 () ;
F_141 ( V_314 , L_60 ) ;
F_139 ( V_7 ) ;
return - V_310 ;
}
#endif
strcpy ( V_308 , V_316 ) ;
F_8 ( V_317 L_64 , F_131 ( V_308 ) ) ;
strcpy ( V_308 , V_318 ) ;
F_8 ( L_65 , F_131 ( V_308 ) ) ;
strcpy ( V_308 , V_319 ) ;
F_8 ( L_65 , F_131 ( V_308 ) ) ;
strcpy ( V_308 , V_320 ) ;
F_8 ( L_65 , F_131 ( V_308 ) ) ;
strcpy ( V_308 , V_321 ) ;
F_8 ( L_66 , F_131 ( V_308 ) ) ;
#ifdef F_136
F_8 ( L_67 ) ;
#else
F_8 ( L_3 ) ;
#endif
F_46 () ;
return 0 ;
}
static void T_23 F_144 ( void )
{
#ifdef F_77
F_145 () ;
#endif
if ( F_146 () < 0 ) {
F_8 ( V_62 L_68 ) ;
return;
}
F_143 () ;
F_141 ( V_314 , L_60 ) ;
F_147 ( & V_7 -> V_46 ) ;
F_139 ( V_7 ) ;
F_8 ( V_317 L_69 ) ;
}
