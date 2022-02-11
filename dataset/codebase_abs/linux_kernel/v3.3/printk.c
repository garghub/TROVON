void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
}
static int T_1 F_3 ( char * V_5 )
{
unsigned V_6 = F_4 ( V_5 , & V_5 ) ;
if ( V_6 )
V_6 = F_5 ( V_6 ) ;
if ( V_6 > V_3 )
V_7 = V_6 ;
return 0 ;
}
void T_1 F_6 ( int V_8 )
{
unsigned long V_9 ;
unsigned V_10 , V_11 , V_12 ;
char * V_13 ;
int free ;
if ( ! V_7 )
return;
if ( V_8 ) {
unsigned long V_14 ;
V_14 = F_7 ( V_7 , V_15 ) ;
if ( ! V_14 )
return;
V_13 = F_8 ( V_14 ) ;
} else {
V_13 = F_9 ( V_7 ) ;
}
if ( F_10 ( ! V_13 ) ) {
F_11 ( L_1 ,
V_7 ) ;
return;
}
F_12 ( & V_16 , V_9 ) ;
V_3 = V_7 ;
V_1 = V_13 ;
V_7 = 0 ;
free = V_17 - V_2 ;
V_12 = V_10 = F_13 ( V_18 , V_19 ) ;
V_11 = 0 ;
while ( V_10 != V_2 ) {
unsigned V_20 = V_10 & ( V_17 - 1 ) ;
V_1 [ V_11 ] = V_21 [ V_20 ] ;
V_10 ++ ;
V_11 ++ ;
}
V_19 -= V_12 ;
V_18 -= V_12 ;
V_2 -= V_12 ;
F_14 ( & V_16 , V_9 ) ;
F_15 ( L_2 , V_3 ) ;
F_15 ( L_3 ,
free , ( free * 100 ) / V_17 ) ;
}
static int T_1 F_16 ( char * V_5 )
{
unsigned long V_22 ;
V_22 = V_23 ? V_23 : 1000000 ;
V_24 = ( unsigned long long ) V_22 / 1000 * V_25 ;
F_17 ( & V_5 , & V_26 ) ;
if ( V_26 > 10 * 1000 )
V_26 = 0 ;
F_18 ( L_4
L_5 ,
V_26 , V_23 , V_22 , V_25 , V_24 ) ;
return 1 ;
}
static void F_19 ( void )
{
unsigned long long V_27 ;
unsigned long V_28 ;
if ( V_26 == 0 || V_29 != V_30 )
return;
V_27 = ( unsigned long long ) V_24 * V_26 ;
V_28 = V_31 + F_20 ( V_26 ) ;
while ( V_27 ) {
V_27 -- ;
F_21 () ;
if ( F_22 ( V_31 , V_28 ) )
break;
F_23 () ;
}
}
static inline void F_19 ( void )
{
}
static int F_24 ( int type )
{
if ( V_32 )
return 1 ;
return type != V_33 && type != V_34 ;
}
static int F_25 ( int type , bool V_35 )
{
if ( V_35 && type != V_36 )
return 0 ;
if ( F_24 ( type ) ) {
if ( F_26 ( V_37 ) )
return 0 ;
if ( F_26 ( V_38 ) ) {
F_27 ( V_39 L_6
L_7
L_8 ,
V_40 -> V_41 , F_28 ( V_40 ) ) ;
return 0 ;
}
return - V_42 ;
}
return 0 ;
}
int F_29 ( int type , char T_2 * V_43 , int V_44 , bool V_35 )
{
unsigned V_45 , V_46 , V_47 , V_48 ;
int V_49 = 0 ;
char V_50 ;
int error ;
error = F_25 ( type , V_35 ) ;
if ( error )
goto V_51;
error = F_30 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_52 :
break;
case V_36 :
break;
case V_53 :
error = - V_54 ;
if ( ! V_43 || V_44 < 0 )
goto V_51;
error = 0 ;
if ( ! V_44 )
goto V_51;
if ( ! F_31 ( V_55 , V_43 , V_44 ) ) {
error = - V_56 ;
goto V_51;
}
error = F_32 ( V_57 ,
( V_19 - V_2 ) ) ;
if ( error )
goto V_51;
V_45 = 0 ;
F_33 ( & V_16 ) ;
while ( ! error && ( V_19 != V_2 ) && V_45 < V_44 ) {
V_50 = F_34 ( V_19 ) ;
V_19 ++ ;
F_35 ( & V_16 ) ;
error = F_36 ( V_50 , V_43 ) ;
V_43 ++ ;
V_45 ++ ;
F_37 () ;
F_33 ( & V_16 ) ;
}
F_35 ( & V_16 ) ;
if ( ! error )
error = V_45 ;
break;
case V_58 :
V_49 = 1 ;
case V_33 :
error = - V_54 ;
if ( ! V_43 || V_44 < 0 )
goto V_51;
error = 0 ;
if ( ! V_44 )
goto V_51;
if ( ! F_31 ( V_55 , V_43 , V_44 ) ) {
error = - V_56 ;
goto V_51;
}
V_48 = V_44 ;
if ( V_48 > V_3 )
V_48 = V_3 ;
F_33 ( & V_16 ) ;
if ( V_48 > V_4 )
V_48 = V_4 ;
if ( V_49 )
V_4 = 0 ;
V_47 = V_2 ;
for ( V_45 = 0 ; V_45 < V_48 && ! error ; V_45 ++ ) {
V_46 = V_47 - 1 - V_45 ;
if ( V_46 + V_3 < V_2 )
break;
V_50 = F_34 ( V_46 ) ;
F_35 ( & V_16 ) ;
error = F_36 ( V_50 , & V_43 [ V_48 - 1 - V_45 ] ) ;
F_37 () ;
F_33 ( & V_16 ) ;
}
F_35 ( & V_16 ) ;
if ( error )
break;
error = V_45 ;
if ( V_45 != V_48 ) {
int V_12 = V_48 - error ;
for ( V_45 = 0 ; V_45 < error ; V_45 ++ ) {
if ( F_38 ( V_50 , & V_43 [ V_45 + V_12 ] ) ||
F_36 ( V_50 , & V_43 [ V_45 ] ) ) {
error = - V_56 ;
break;
}
F_37 () ;
}
}
break;
case V_59 :
V_4 = 0 ;
break;
case V_60 :
if ( V_61 == - 1 )
V_61 = V_62 ;
V_62 = V_63 ;
break;
case V_64 :
if ( V_61 != - 1 ) {
V_62 = V_61 ;
V_61 = - 1 ;
}
break;
case V_65 :
error = - V_54 ;
if ( V_44 < 1 || V_44 > 8 )
goto V_51;
if ( V_44 < V_63 )
V_44 = V_63 ;
V_62 = V_44 ;
V_61 = - 1 ;
error = 0 ;
break;
case V_66 :
error = V_2 - V_19 ;
break;
case V_34 :
error = V_3 ;
break;
default:
error = - V_54 ;
break;
}
V_51:
return error ;
}
void F_39 ( char * V_67 [ 4 ] )
{
V_67 [ 0 ] = V_1 ;
V_67 [ 1 ] = V_1 + V_3 ;
V_67 [ 2 ] = V_1 + V_2 -
( V_4 < V_3 ? V_4 : V_3 ) ;
V_67 [ 3 ] = V_1 + V_2 ;
}
static void F_40 ( unsigned V_10 , unsigned V_68 )
{
struct V_69 * V_70 ;
F_41 (con) {
if ( V_71 && V_70 != V_71 )
continue;
if ( ( V_70 -> V_9 & V_72 ) && V_70 -> V_73 &&
( F_42 ( F_43 () ) ||
( V_70 -> V_9 & V_74 ) ) )
V_70 -> V_73 ( V_70 , & F_34 ( V_10 ) , V_68 - V_10 ) ;
}
}
static int T_1 F_44 ( char * V_5 )
{
V_75 = 1 ;
F_45 ( V_76 L_9 ) ;
return 0 ;
}
static void F_46 ( unsigned V_10 ,
unsigned V_68 , int V_77 )
{
if ( ( V_77 < V_62 || V_75 ) &&
V_78 && V_10 != V_68 ) {
if ( ( V_10 & V_79 ) > ( V_68 & V_79 ) ) {
F_40 ( V_10 & V_79 ,
V_3 ) ;
F_40 ( 0 , V_68 & V_79 ) ;
} else {
F_40 ( V_10 , V_68 ) ;
}
}
}
static T_3 F_47 ( const char * V_80 , unsigned int * V_81 , char * V_82 )
{
unsigned int V_83 = 0 ;
char V_84 = '\0' ;
T_3 V_44 ;
if ( V_80 [ 0 ] != '<' || ! V_80 [ 1 ] )
return 0 ;
if ( V_80 [ 2 ] == '>' ) {
switch ( V_80 [ 1 ] ) {
case '0' ... '7' :
V_83 = V_80 [ 1 ] - '0' ;
break;
case 'c' :
case 'd' :
V_84 = V_80 [ 1 ] ;
break;
default:
return 0 ;
}
V_44 = 3 ;
} else {
char * V_85 = NULL ;
V_83 = ( F_48 ( & V_80 [ 1 ] , & V_85 , 10 ) & 7 ) ;
if ( V_85 == NULL || V_85 [ 0 ] != '>' )
return 0 ;
V_44 = ( V_85 + 1 ) - V_80 ;
}
if ( V_84 && ! V_82 )
return 0 ;
if ( V_82 ) {
* V_82 = V_84 ;
if ( V_84 )
return V_44 ;
}
if ( V_81 )
* V_81 = V_83 ;
return V_44 ;
}
static void F_49 ( unsigned V_10 , unsigned V_68 )
{
unsigned V_86 , V_87 ;
static int V_88 = - 1 ;
F_50 ( ( ( int ) ( V_10 - V_68 ) ) > 0 ) ;
V_86 = V_10 ;
V_87 = V_10 ;
while ( V_86 != V_68 ) {
if ( V_88 < 0 && ( ( V_68 - V_86 ) > 2 ) ) {
V_86 += F_47 ( & F_34 ( V_86 ) , & V_88 , NULL ) ;
V_87 = V_86 ;
}
while ( V_86 != V_68 ) {
char V_50 = F_34 ( V_86 ) ;
V_86 ++ ;
if ( V_50 == '\n' ) {
if ( V_88 < 0 ) {
V_88 = V_89 ;
}
F_46 ( V_87 , V_86 , V_88 ) ;
V_88 = - 1 ;
V_87 = V_86 ;
break;
}
}
}
F_46 ( V_87 , V_68 , V_88 ) ;
}
static void F_51 ( char V_50 )
{
F_34 ( V_2 ) = V_50 ;
V_2 ++ ;
if ( V_2 - V_19 > V_3 )
V_19 = V_2 - V_3 ;
if ( V_2 - V_18 > V_3 )
V_18 = V_2 - V_3 ;
if ( V_4 < V_3 )
V_4 ++ ;
}
static void F_52 ( void )
{
static unsigned long V_90 ;
if ( F_53 ( V_31 , V_90 ) &&
! F_22 ( V_31 , V_90 + 30 * V_25 ) )
return;
V_90 = V_31 ;
F_54 () ;
F_55 ( & V_16 ) ;
F_56 ( & V_91 , 1 ) ;
}
static int F_57 ( void )
{
struct V_69 * V_70 ;
F_41 (con)
if ( V_70 -> V_9 & V_74 )
return 1 ;
return 0 ;
}
T_4 int F_45 ( const char * V_92 , ... )
{
T_5 args ;
int V_93 ;
#ifdef F_58
if ( F_10 ( V_94 ) ) {
va_start ( args , V_92 ) ;
V_93 = F_59 ( V_92 , args ) ;
va_end ( args ) ;
return V_93 ;
}
#endif
va_start ( args , V_92 ) ;
V_93 = F_60 ( V_92 , args ) ;
va_end ( args ) ;
return V_93 ;
}
static inline int F_61 ( unsigned int V_95 )
{
return F_42 ( V_95 ) || F_57 () ;
}
static int F_62 ( unsigned int V_95 )
__releases( &logbuf_lock
static inline void F_63 ( void )
{
if ( F_10 ( V_96 ) ) {
int V_97 = V_96 ;
while ( V_97 -- ) {
F_64 ( 1 ) ;
F_23 () ;
}
}
}
T_4 int F_60 ( const char * V_92 , T_5 args )
{
int V_98 = 0 ;
int V_99 = V_89 ;
unsigned long V_9 ;
int V_100 ;
char * V_80 ;
T_3 V_101 ;
char V_82 ;
F_19 () ;
F_63 () ;
F_65 ( V_9 ) ;
V_100 = F_43 () ;
if ( F_10 ( V_102 == V_100 ) ) {
if ( ! V_103 && ! F_66 ( V_40 ) ) {
V_104 = 1 ;
goto V_105;
}
F_52 () ;
}
F_67 () ;
F_68 ( & V_16 ) ;
V_102 = V_100 ;
if ( V_104 ) {
V_104 = 0 ;
strcpy ( V_106 , V_107 ) ;
V_98 = strlen ( V_107 ) ;
}
V_98 += F_69 ( V_106 + V_98 ,
sizeof( V_106 ) - V_98 , V_92 , args ) ;
V_80 = V_106 ;
V_101 = F_47 ( V_80 , & V_99 , & V_82 ) ;
if ( V_101 ) {
V_80 += V_101 ;
switch ( V_82 ) {
case 'c' :
V_101 = 0 ;
break;
case 'd' :
V_101 = 0 ;
default:
if ( ! V_108 ) {
F_51 ( '\n' ) ;
V_108 = 1 ;
}
}
}
for (; * V_80 ; V_80 ++ ) {
if ( V_108 ) {
V_108 = 0 ;
if ( V_101 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_101 ; V_45 ++ )
F_51 ( V_106 [ V_45 ] ) ;
V_98 += V_101 ;
} else {
F_51 ( '<' ) ;
F_51 ( V_99 + '0' ) ;
F_51 ( '>' ) ;
V_98 += 3 ;
}
if ( V_109 ) {
char V_110 [ 50 ] , * V_111 ;
unsigned V_112 ;
unsigned long long V_113 ;
unsigned long V_114 ;
V_113 = F_70 ( V_102 ) ;
V_114 = F_71 ( V_113 , 1000000000 ) ;
V_112 = sprintf ( V_110 , L_10 ,
( unsigned long ) V_113 ,
V_114 / 1000 ) ;
for ( V_111 = V_110 ; V_111 < V_110 + V_112 ; V_111 ++ )
F_51 ( * V_111 ) ;
V_98 += V_112 ;
}
if ( ! * V_80 )
break;
}
F_51 ( * V_80 ) ;
if ( * V_80 == '\n' )
V_108 = 1 ;
}
if ( F_62 ( V_100 ) )
F_72 () ;
F_73 () ;
V_105:
F_74 ( V_9 ) ;
return V_98 ;
}
static void F_49 ( unsigned V_10 , unsigned V_68 )
{
}
static int F_75 ( char * V_115 , int V_116 , char * V_117 ,
char * V_118 )
{
struct V_119 * V_50 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_120 && V_119 [ V_45 ] . V_115 [ 0 ] ; V_45 ++ )
if ( strcmp ( V_119 [ V_45 ] . V_115 , V_115 ) == 0 &&
V_119 [ V_45 ] . V_121 == V_116 ) {
if ( ! V_118 )
V_122 = V_45 ;
return 0 ;
}
if ( V_45 == V_120 )
return - V_123 ;
if ( ! V_118 )
V_122 = V_45 ;
V_50 = & V_119 [ V_45 ] ;
F_76 ( V_50 -> V_115 , V_115 , sizeof( V_50 -> V_115 ) ) ;
V_50 -> V_117 = V_117 ;
#ifdef F_77
V_50 -> V_118 = V_118 ;
#endif
V_50 -> V_121 = V_116 ;
return 0 ;
}
static int T_1 F_78 ( char * V_5 )
{
char V_43 [ sizeof( V_119 [ 0 ] . V_115 ) + 4 ] ;
char * V_124 , * V_117 , * V_118 = NULL ;
int V_116 ;
#ifdef F_77
if ( ! memcmp ( V_5 , L_11 , 4 ) ) {
V_118 = L_12 ;
V_5 += 4 ;
} else if ( ! memcmp ( V_5 , L_13 , 4 ) ) {
V_118 = V_5 + 4 ;
V_5 = strchr ( V_118 , ',' ) ;
if ( ! V_5 ) {
F_45 ( V_125 L_14 ) ;
return 1 ;
}
* ( V_5 ++ ) = 0 ;
}
#endif
if ( V_5 [ 0 ] >= '0' && V_5 [ 0 ] <= '9' ) {
strcpy ( V_43 , L_15 ) ;
strncpy ( V_43 + 4 , V_5 , sizeof( V_43 ) - 5 ) ;
} else {
strncpy ( V_43 , V_5 , sizeof( V_43 ) - 1 ) ;
}
V_43 [ sizeof( V_43 ) - 1 ] = 0 ;
if ( ( V_117 = strchr ( V_5 , ',' ) ) != NULL )
* ( V_117 ++ ) = 0 ;
#ifdef F_79
if ( ! strcmp ( V_5 , L_16 ) )
strcpy ( V_43 , L_17 ) ;
if ( ! strcmp ( V_5 , L_18 ) )
strcpy ( V_43 , L_19 ) ;
#endif
for ( V_124 = V_43 ; * V_124 ; V_124 ++ )
if ( ( * V_124 >= '0' && * V_124 <= '9' ) || * V_124 == ',' )
break;
V_116 = F_48 ( V_124 , NULL , 10 ) ;
* V_124 = 0 ;
F_75 ( V_43 , V_116 , V_117 , V_118 ) ;
V_126 = 1 ;
return 1 ;
}
int F_80 ( char * V_115 , int V_116 , char * V_117 )
{
return F_75 ( V_115 , V_116 , V_117 , NULL ) ;
}
int F_81 ( char * V_115 , int V_116 , char * V_127 , int V_128 , char * V_117 )
{
struct V_119 * V_50 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_120 && V_119 [ V_45 ] . V_115 [ 0 ] ; V_45 ++ )
if ( strcmp ( V_119 [ V_45 ] . V_115 , V_115 ) == 0 &&
V_119 [ V_45 ] . V_121 == V_116 ) {
V_50 = & V_119 [ V_45 ] ;
F_76 ( V_50 -> V_115 , V_127 , sizeof( V_50 -> V_115 ) ) ;
V_50 -> V_115 [ sizeof( V_50 -> V_115 ) - 1 ] = 0 ;
V_50 -> V_117 = V_117 ;
V_50 -> V_121 = V_128 ;
return V_45 ;
}
return - 1 ;
}
static int T_1 F_82 ( char * V_5 )
{
V_129 = 0 ;
return 1 ;
}
void F_83 ( void )
{
if ( ! V_129 )
return;
F_45 ( L_20 ) ;
F_84 () ;
V_130 = 1 ;
F_85 ( & V_91 ) ;
}
void F_86 ( void )
{
if ( ! V_129 )
return;
F_87 ( & V_91 ) ;
V_130 = 0 ;
F_72 () ;
}
static int T_6 F_88 ( struct V_131 * V_132 ,
unsigned long V_133 , void * V_134 )
{
switch ( V_133 ) {
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
F_84 () ;
F_72 () ;
}
return V_140 ;
}
void F_84 ( void )
{
F_50 ( F_89 () ) ;
F_87 ( & V_91 ) ;
if ( V_130 )
return;
V_141 = 1 ;
V_142 = 1 ;
}
int F_90 ( void )
{
if ( F_91 ( & V_91 ) )
return 0 ;
if ( V_130 ) {
F_85 ( & V_91 ) ;
return 0 ;
}
V_141 = 1 ;
V_142 = 0 ;
return 1 ;
}
int F_92 ( void )
{
return V_141 ;
}
void F_93 ( void )
{
if ( F_94 ( V_143 ) ) {
F_95 ( V_143 , 0 ) ;
F_96 ( & V_57 ) ;
}
}
int F_97 ( int V_95 )
{
if ( F_98 ( V_95 ) )
F_93 () ;
return F_94 ( V_143 ) ;
}
void F_99 ( void )
{
if ( F_100 ( & V_57 ) )
F_101 ( V_143 , 1 ) ;
}
void F_72 ( void )
{
unsigned long V_9 ;
unsigned V_144 , V_145 ;
unsigned V_146 = 0 , V_147 = 0 ;
if ( V_130 ) {
F_85 ( & V_91 ) ;
return;
}
V_142 = 0 ;
V_148:
for ( ; ; ) {
F_12 ( & V_16 , V_9 ) ;
V_146 |= V_19 - V_2 ;
if ( V_18 == V_2 )
break;
V_144 = V_18 ;
V_145 = V_2 ;
V_18 = V_2 ;
F_102 ( & V_16 ) ;
F_103 () ;
F_49 ( V_144 , V_145 ) ;
F_104 () ;
F_74 ( V_9 ) ;
}
V_141 = 0 ;
if ( F_10 ( V_71 ) )
V_71 = NULL ;
F_102 ( & V_16 ) ;
F_85 ( & V_91 ) ;
F_68 ( & V_16 ) ;
if ( V_18 != V_2 )
V_147 = 1 ;
F_14 ( & V_16 , V_9 ) ;
if ( V_147 && F_90 () )
goto V_148;
if ( V_146 )
F_99 () ;
}
void T_7 F_105 ( void )
{
if ( V_142 )
F_37 () ;
}
void F_106 ( void )
{
struct V_69 * V_50 ;
if ( V_103 ) {
if ( F_91 ( & V_91 ) != 0 )
return;
} else
F_84 () ;
V_141 = 1 ;
V_142 = 0 ;
F_41 (c)
if ( ( V_50 -> V_9 & V_72 ) && V_50 -> V_149 )
V_50 -> V_149 () ;
F_72 () ;
}
struct V_150 * F_107 ( int * V_121 )
{
struct V_69 * V_50 ;
struct V_150 * V_151 = NULL ;
F_84 () ;
F_41 (c) {
if ( ! V_50 -> V_152 )
continue;
V_151 = V_50 -> V_152 ( V_50 , V_121 ) ;
if ( V_151 )
break;
}
F_72 () ;
return V_151 ;
}
void F_108 ( struct V_69 * V_69 )
{
F_84 () ;
V_69 -> V_9 &= ~ V_72 ;
F_72 () ;
}
void F_109 ( struct V_69 * V_69 )
{
F_84 () ;
V_69 -> V_9 |= V_72 ;
F_72 () ;
}
static int T_1 F_110 ( char * V_5 )
{
V_153 = 1 ;
F_45 ( V_76 L_21 ) ;
return 0 ;
}
void F_111 ( struct V_69 * V_154 )
{
int V_45 ;
unsigned long V_9 ;
struct V_69 * V_155 = NULL ;
if ( V_78 && V_154 -> V_9 & V_156 ) {
F_41 (bcon) {
if ( ! ( V_155 -> V_9 & V_156 ) ) {
F_45 ( V_76 L_22 ,
V_154 -> V_115 , V_154 -> V_121 ) ;
return;
}
}
}
if ( V_78 && V_78 -> V_9 & V_156 )
V_155 = V_78 ;
if ( V_157 < 0 || V_155 || ! V_78 )
V_157 = V_122 ;
if ( V_154 -> V_158 )
V_154 -> V_158 () ;
if ( V_157 < 0 ) {
if ( V_154 -> V_121 < 0 )
V_154 -> V_121 = 0 ;
if ( V_154 -> V_159 == NULL ||
V_154 -> V_159 ( V_154 , NULL ) == 0 ) {
V_154 -> V_9 |= V_72 ;
if ( V_154 -> V_152 ) {
V_154 -> V_9 |= V_160 ;
V_157 = 0 ;
}
}
}
for ( V_45 = 0 ; V_45 < V_120 && V_119 [ V_45 ] . V_115 [ 0 ] ;
V_45 ++ ) {
if ( strcmp ( V_119 [ V_45 ] . V_115 , V_154 -> V_115 ) != 0 )
continue;
if ( V_154 -> V_121 >= 0 &&
V_154 -> V_121 != V_119 [ V_45 ] . V_121 )
continue;
if ( V_154 -> V_121 < 0 )
V_154 -> V_121 = V_119 [ V_45 ] . V_121 ;
#ifdef F_77
if ( V_119 [ V_45 ] . V_118 ) {
V_154 -> V_9 |= V_161 ;
F_112 ( V_154 ,
V_119 [ V_45 ] . V_121 ,
V_119 [ V_45 ] . V_117 ,
V_119 [ V_45 ] . V_118 ) ;
return;
}
#endif
if ( V_154 -> V_159 &&
V_154 -> V_159 ( V_154 , V_119 [ V_45 ] . V_117 ) != 0 )
break;
V_154 -> V_9 |= V_72 ;
V_154 -> V_121 = V_119 [ V_45 ] . V_121 ;
if ( V_45 == V_122 ) {
V_154 -> V_9 |= V_160 ;
V_157 = V_122 ;
}
break;
}
if ( ! ( V_154 -> V_9 & V_72 ) )
return;
if ( V_155 && ( ( V_154 -> V_9 & ( V_160 | V_156 ) ) == V_160 ) )
V_154 -> V_9 &= ~ V_162 ;
F_84 () ;
if ( ( V_154 -> V_9 & V_160 ) || V_78 == NULL ) {
V_154 -> V_163 = V_78 ;
V_78 = V_154 ;
if ( V_154 -> V_163 )
V_154 -> V_163 -> V_9 &= ~ V_160 ;
} else {
V_154 -> V_163 = V_78 -> V_163 ;
V_78 -> V_163 = V_154 ;
}
if ( V_154 -> V_9 & V_162 ) {
F_12 ( & V_16 , V_9 ) ;
V_18 = V_19 ;
F_14 ( & V_16 , V_9 ) ;
V_71 = V_154 ;
}
F_72 () ;
F_113 () ;
if ( V_155 &&
( ( V_154 -> V_9 & ( V_160 | V_156 ) ) == V_160 ) &&
! V_153 ) {
F_45 ( V_76 L_23 ,
V_154 -> V_115 , V_154 -> V_121 ) ;
F_41 (bcon)
if ( V_155 -> V_9 & V_156 )
F_114 ( V_155 ) ;
} else {
F_45 ( V_76 L_24 ,
( V_154 -> V_9 & V_156 ) ? L_25 : L_12 ,
V_154 -> V_115 , V_154 -> V_121 ) ;
}
}
int F_114 ( struct V_69 * V_69 )
{
struct V_69 * V_164 , * V_165 ;
int V_166 = 1 ;
#ifdef F_77
if ( V_69 -> V_9 & V_161 )
return F_115 ( V_69 ) ;
#endif
F_84 () ;
if ( V_78 == V_69 ) {
V_78 = V_69 -> V_163 ;
V_166 = 0 ;
} else if ( V_78 ) {
for ( V_164 = V_78 -> V_163 , V_165 = V_78 ;
V_164 ; V_165 = V_164 , V_164 = V_165 -> V_163 ) {
if ( V_164 == V_69 ) {
V_165 -> V_163 = V_164 -> V_163 ;
V_166 = 0 ;
break;
}
}
}
if ( V_78 != NULL && V_69 -> V_9 & V_160 )
V_78 -> V_9 |= V_160 ;
F_72 () ;
F_113 () ;
return V_166 ;
}
static int T_1 F_116 ( void )
{
struct V_69 * V_70 ;
F_41 (con) {
if ( ! V_153 && V_70 -> V_9 & V_156 ) {
F_45 ( V_76 L_26 ,
V_70 -> V_115 , V_70 -> V_121 ) ;
F_114 ( V_70 ) ;
}
}
F_117 ( F_88 , 0 ) ;
return 0 ;
}
int F_118 ( const char * V_167 )
{
return F_119 ( & V_168 , V_167 ) ;
}
bool F_120 ( unsigned long * V_169 ,
unsigned int V_170 )
{
if ( * V_169 == 0
|| ! F_121 ( V_31 , * V_169 ,
* V_169
+ F_20 ( V_170 ) ) ) {
* V_169 = V_31 ;
return true ;
}
return false ;
}
int F_122 ( struct V_171 * V_172 )
{
unsigned long V_9 ;
int V_173 = - V_174 ;
if ( ! V_172 -> V_175 )
return - V_54 ;
F_123 ( & V_176 , V_9 ) ;
if ( ! V_172 -> V_177 ) {
V_172 -> V_177 = 1 ;
F_124 ( & V_172 -> V_178 , & V_179 ) ;
V_173 = 0 ;
}
F_125 ( & V_176 , V_9 ) ;
return V_173 ;
}
int F_126 ( struct V_171 * V_172 )
{
unsigned long V_9 ;
int V_173 = - V_54 ;
F_123 ( & V_176 , V_9 ) ;
if ( V_172 -> V_177 ) {
V_172 -> V_177 = 0 ;
F_127 ( & V_172 -> V_178 ) ;
V_173 = 0 ;
}
F_125 ( & V_176 , V_9 ) ;
F_128 () ;
return V_173 ;
}
void F_129 ( enum V_180 V_181 )
{
unsigned long V_68 ;
unsigned V_182 ;
struct V_171 * V_172 ;
const char * V_183 , * V_184 ;
unsigned long V_185 , V_186 ;
unsigned long V_9 ;
if ( ( V_181 > V_187 ) && ! V_188 )
return;
F_12 ( & V_16 , V_9 ) ;
V_68 = V_2 & V_79 ;
V_182 = V_4 ;
F_14 ( & V_16 , V_9 ) ;
if ( V_182 > V_68 ) {
V_183 = V_1 + V_3 - V_182 + V_68 ;
V_185 = V_182 - V_68 ;
V_184 = V_1 ;
V_186 = V_68 ;
} else {
V_183 = L_12 ;
V_185 = 0 ;
V_184 = V_1 + V_68 - V_182 ;
V_186 = V_182 ;
}
F_130 () ;
F_131 (dumper, &dump_list, list)
V_172 -> V_175 ( V_172 , V_181 , V_183 , V_185 , V_184 , V_186 ) ;
F_132 () ;
}
