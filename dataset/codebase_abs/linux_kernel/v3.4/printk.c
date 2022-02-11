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
F_47 ( & F_34 ( 0 ) , V_10 , V_68 , V_3 ) ;
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
static T_3 F_48 ( const char * V_80 , unsigned int * V_81 , char * V_82 )
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
V_83 = ( F_49 ( & V_80 [ 1 ] , & V_85 , 10 ) & 7 ) ;
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
static void F_50 ( unsigned V_10 , unsigned V_68 )
{
unsigned V_86 , V_87 ;
static int V_88 = - 1 ;
F_51 ( ( ( int ) ( V_10 - V_68 ) ) > 0 ) ;
V_86 = V_10 ;
V_87 = V_10 ;
while ( V_86 != V_68 ) {
if ( V_88 < 0 && ( ( V_68 - V_86 ) > 2 ) ) {
V_86 += F_48 ( & F_34 ( V_86 ) , & V_88 , NULL ) ;
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
static void F_52 ( char V_50 )
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
static void F_53 ( void )
{
static unsigned long V_90 ;
if ( F_54 ( V_31 , V_90 ) &&
! F_22 ( V_31 , V_90 + 30 * V_25 ) )
return;
V_90 = V_31 ;
F_55 () ;
F_56 ( & V_16 ) ;
F_57 ( & V_91 , 1 ) ;
}
static int F_58 ( void )
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
#ifdef F_59
if ( F_10 ( V_94 ) ) {
va_start ( args , V_92 ) ;
V_93 = F_60 ( V_92 , args ) ;
va_end ( args ) ;
return V_93 ;
}
#endif
va_start ( args , V_92 ) ;
V_93 = F_61 ( V_92 , args ) ;
va_end ( args ) ;
return V_93 ;
}
static inline int F_62 ( unsigned int V_95 )
{
return F_42 ( V_95 ) || F_58 () ;
}
static int F_63 ( unsigned int V_95 )
__releases( &logbuf_lock
static inline void F_64 ( void )
{
if ( F_10 ( V_96 ) ) {
int V_97 = V_96 ;
while ( V_97 -- ) {
F_65 ( 1 ) ;
F_23 () ;
}
}
}
T_4 int F_61 ( const char * V_92 , T_5 args )
{
int V_98 = 0 ;
int V_99 = V_89 ;
unsigned long V_9 ;
int V_100 ;
char * V_80 ;
T_3 V_101 ;
char V_82 ;
F_19 () ;
F_64 () ;
F_66 ( V_9 ) ;
V_100 = F_43 () ;
if ( F_10 ( V_102 == V_100 ) ) {
if ( ! V_103 && ! F_67 ( V_40 ) ) {
V_104 = 1 ;
goto V_105;
}
F_53 () ;
}
F_68 () ;
F_69 ( & V_16 ) ;
V_102 = V_100 ;
if ( V_104 ) {
V_104 = 0 ;
strcpy ( V_106 , V_107 ) ;
V_98 = strlen ( V_107 ) ;
}
V_98 += F_70 ( V_106 + V_98 ,
sizeof( V_106 ) - V_98 , V_92 , args ) ;
V_80 = V_106 ;
V_101 = F_48 ( V_80 , & V_99 , & V_82 ) ;
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
F_52 ( '\n' ) ;
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
F_52 ( V_106 [ V_45 ] ) ;
V_98 += V_101 ;
} else {
F_52 ( '<' ) ;
F_52 ( V_99 + '0' ) ;
F_52 ( '>' ) ;
V_98 += 3 ;
}
if ( V_109 ) {
char V_110 [ 50 ] , * V_111 ;
unsigned V_112 ;
unsigned long long V_113 ;
unsigned long V_114 ;
V_113 = F_71 ( V_102 ) ;
V_114 = F_72 ( V_113 , 1000000000 ) ;
V_112 = sprintf ( V_110 , L_10 ,
( unsigned long ) V_113 ,
V_114 / 1000 ) ;
for ( V_111 = V_110 ; V_111 < V_110 + V_112 ; V_111 ++ )
F_52 ( * V_111 ) ;
V_98 += V_112 ;
}
if ( ! * V_80 )
break;
}
F_52 ( * V_80 ) ;
if ( * V_80 == '\n' )
V_108 = 1 ;
}
if ( F_63 ( V_100 ) )
F_73 () ;
F_74 () ;
V_105:
F_75 ( V_9 ) ;
return V_98 ;
}
static void F_50 ( unsigned V_10 , unsigned V_68 )
{
}
static int F_76 ( char * V_115 , int V_116 , char * V_117 ,
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
F_77 ( V_50 -> V_115 , V_115 , sizeof( V_50 -> V_115 ) ) ;
V_50 -> V_117 = V_117 ;
#ifdef F_78
V_50 -> V_118 = V_118 ;
#endif
V_50 -> V_121 = V_116 ;
return 0 ;
}
static int T_1 F_79 ( char * V_5 )
{
char V_43 [ sizeof( V_119 [ 0 ] . V_115 ) + 4 ] ;
char * V_124 , * V_117 , * V_118 = NULL ;
int V_116 ;
#ifdef F_78
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
#ifdef F_80
if ( ! strcmp ( V_5 , L_16 ) )
strcpy ( V_43 , L_17 ) ;
if ( ! strcmp ( V_5 , L_18 ) )
strcpy ( V_43 , L_19 ) ;
#endif
for ( V_124 = V_43 ; * V_124 ; V_124 ++ )
if ( ( * V_124 >= '0' && * V_124 <= '9' ) || * V_124 == ',' )
break;
V_116 = F_49 ( V_124 , NULL , 10 ) ;
* V_124 = 0 ;
F_76 ( V_43 , V_116 , V_117 , V_118 ) ;
V_126 = 1 ;
return 1 ;
}
int F_81 ( char * V_115 , int V_116 , char * V_117 )
{
return F_76 ( V_115 , V_116 , V_117 , NULL ) ;
}
int F_82 ( char * V_115 , int V_116 , char * V_127 , int V_128 , char * V_117 )
{
struct V_119 * V_50 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_120 && V_119 [ V_45 ] . V_115 [ 0 ] ; V_45 ++ )
if ( strcmp ( V_119 [ V_45 ] . V_115 , V_115 ) == 0 &&
V_119 [ V_45 ] . V_121 == V_116 ) {
V_50 = & V_119 [ V_45 ] ;
F_77 ( V_50 -> V_115 , V_127 , sizeof( V_50 -> V_115 ) ) ;
V_50 -> V_115 [ sizeof( V_50 -> V_115 ) - 1 ] = 0 ;
V_50 -> V_117 = V_117 ;
V_50 -> V_121 = V_128 ;
return V_45 ;
}
return - 1 ;
}
static int T_1 F_83 ( char * V_5 )
{
V_129 = 0 ;
return 1 ;
}
void F_84 ( void )
{
if ( ! V_129 )
return;
F_45 ( L_20 ) ;
F_85 () ;
V_130 = 1 ;
F_86 ( & V_91 ) ;
}
void F_87 ( void )
{
if ( ! V_129 )
return;
F_88 ( & V_91 ) ;
V_130 = 0 ;
F_73 () ;
}
static int T_6 F_89 ( struct V_131 * V_132 ,
unsigned long V_133 , void * V_134 )
{
switch ( V_133 ) {
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
F_85 () ;
F_73 () ;
}
return V_140 ;
}
void F_85 ( void )
{
F_51 ( F_90 () ) ;
F_88 ( & V_91 ) ;
if ( V_130 )
return;
V_141 = 1 ;
V_142 = 1 ;
}
int F_91 ( void )
{
if ( F_92 ( & V_91 ) )
return 0 ;
if ( V_130 ) {
F_86 ( & V_91 ) ;
return 0 ;
}
V_141 = 1 ;
V_142 = 0 ;
return 1 ;
}
int F_93 ( void )
{
return V_141 ;
}
void F_94 ( void )
{
if ( F_95 ( V_143 ) ) {
int V_144 = F_96 ( V_143 , 0 ) ;
if ( V_144 & V_145 ) {
char * V_43 = F_97 ( V_146 ) ;
F_45 ( V_39 L_21 , V_43 ) ;
}
if ( V_144 & V_147 )
F_98 ( & V_57 ) ;
}
}
int F_99 ( int V_95 )
{
if ( F_100 ( V_95 ) )
F_94 () ;
return F_95 ( V_143 ) ;
}
void F_101 ( void )
{
if ( F_102 ( & V_57 ) )
F_103 ( V_143 , V_147 ) ;
}
void F_73 ( void )
{
unsigned long V_9 ;
unsigned V_148 , V_149 ;
unsigned V_150 = 0 , V_151 = 0 ;
if ( V_130 ) {
F_86 ( & V_91 ) ;
return;
}
V_142 = 0 ;
V_152:
for ( ; ; ) {
F_12 ( & V_16 , V_9 ) ;
V_150 |= V_19 - V_2 ;
if ( V_18 == V_2 )
break;
V_148 = V_18 ;
V_149 = V_2 ;
V_18 = V_2 ;
F_104 ( & V_16 ) ;
F_105 () ;
F_50 ( V_148 , V_149 ) ;
F_106 () ;
F_75 ( V_9 ) ;
}
V_141 = 0 ;
if ( F_10 ( V_71 ) )
V_71 = NULL ;
F_104 ( & V_16 ) ;
F_86 ( & V_91 ) ;
F_69 ( & V_16 ) ;
if ( V_18 != V_2 )
V_151 = 1 ;
F_14 ( & V_16 , V_9 ) ;
if ( V_151 && F_91 () )
goto V_152;
if ( V_150 )
F_101 () ;
}
void T_7 F_107 ( void )
{
if ( V_142 )
F_37 () ;
}
void F_108 ( void )
{
struct V_69 * V_50 ;
if ( V_103 ) {
if ( F_92 ( & V_91 ) != 0 )
return;
} else
F_85 () ;
V_141 = 1 ;
V_142 = 0 ;
F_41 (c)
if ( ( V_50 -> V_9 & V_72 ) && V_50 -> V_153 )
V_50 -> V_153 () ;
F_73 () ;
}
struct V_154 * F_109 ( int * V_121 )
{
struct V_69 * V_50 ;
struct V_154 * V_155 = NULL ;
F_85 () ;
F_41 (c) {
if ( ! V_50 -> V_156 )
continue;
V_155 = V_50 -> V_156 ( V_50 , V_121 ) ;
if ( V_155 )
break;
}
F_73 () ;
return V_155 ;
}
void F_110 ( struct V_69 * V_69 )
{
F_85 () ;
V_69 -> V_9 &= ~ V_72 ;
F_73 () ;
}
void F_111 ( struct V_69 * V_69 )
{
F_85 () ;
V_69 -> V_9 |= V_72 ;
F_73 () ;
}
static int T_1 F_112 ( char * V_5 )
{
V_157 = 1 ;
F_45 ( V_76 L_22 ) ;
return 0 ;
}
void F_113 ( struct V_69 * V_158 )
{
int V_45 ;
unsigned long V_9 ;
struct V_69 * V_159 = NULL ;
if ( V_78 && V_158 -> V_9 & V_160 ) {
F_41 (bcon) {
if ( ! ( V_159 -> V_9 & V_160 ) ) {
F_45 ( V_76 L_23 ,
V_158 -> V_115 , V_158 -> V_121 ) ;
return;
}
}
}
if ( V_78 && V_78 -> V_9 & V_160 )
V_159 = V_78 ;
if ( V_161 < 0 || V_159 || ! V_78 )
V_161 = V_122 ;
if ( V_158 -> V_162 )
V_158 -> V_162 () ;
if ( V_161 < 0 ) {
if ( V_158 -> V_121 < 0 )
V_158 -> V_121 = 0 ;
if ( V_158 -> V_163 == NULL ||
V_158 -> V_163 ( V_158 , NULL ) == 0 ) {
V_158 -> V_9 |= V_72 ;
if ( V_158 -> V_156 ) {
V_158 -> V_9 |= V_164 ;
V_161 = 0 ;
}
}
}
for ( V_45 = 0 ; V_45 < V_120 && V_119 [ V_45 ] . V_115 [ 0 ] ;
V_45 ++ ) {
if ( strcmp ( V_119 [ V_45 ] . V_115 , V_158 -> V_115 ) != 0 )
continue;
if ( V_158 -> V_121 >= 0 &&
V_158 -> V_121 != V_119 [ V_45 ] . V_121 )
continue;
if ( V_158 -> V_121 < 0 )
V_158 -> V_121 = V_119 [ V_45 ] . V_121 ;
#ifdef F_78
if ( V_119 [ V_45 ] . V_118 ) {
V_158 -> V_9 |= V_165 ;
F_114 ( V_158 ,
V_119 [ V_45 ] . V_121 ,
V_119 [ V_45 ] . V_117 ,
V_119 [ V_45 ] . V_118 ) ;
return;
}
#endif
if ( V_158 -> V_163 &&
V_158 -> V_163 ( V_158 , V_119 [ V_45 ] . V_117 ) != 0 )
break;
V_158 -> V_9 |= V_72 ;
V_158 -> V_121 = V_119 [ V_45 ] . V_121 ;
if ( V_45 == V_122 ) {
V_158 -> V_9 |= V_164 ;
V_161 = V_122 ;
}
break;
}
if ( ! ( V_158 -> V_9 & V_72 ) )
return;
if ( V_159 && ( ( V_158 -> V_9 & ( V_164 | V_160 ) ) == V_164 ) )
V_158 -> V_9 &= ~ V_166 ;
F_85 () ;
if ( ( V_158 -> V_9 & V_164 ) || V_78 == NULL ) {
V_158 -> V_167 = V_78 ;
V_78 = V_158 ;
if ( V_158 -> V_167 )
V_158 -> V_167 -> V_9 &= ~ V_164 ;
} else {
V_158 -> V_167 = V_78 -> V_167 ;
V_78 -> V_167 = V_158 ;
}
if ( V_158 -> V_9 & V_166 ) {
F_12 ( & V_16 , V_9 ) ;
V_18 = V_19 ;
F_14 ( & V_16 , V_9 ) ;
V_71 = V_158 ;
}
F_73 () ;
F_115 () ;
if ( V_159 &&
( ( V_158 -> V_9 & ( V_164 | V_160 ) ) == V_164 ) &&
! V_157 ) {
F_45 ( V_76 L_24 ,
V_158 -> V_115 , V_158 -> V_121 ) ;
F_41 (bcon)
if ( V_159 -> V_9 & V_160 )
F_116 ( V_159 ) ;
} else {
F_45 ( V_76 L_25 ,
( V_158 -> V_9 & V_160 ) ? L_26 : L_12 ,
V_158 -> V_115 , V_158 -> V_121 ) ;
}
}
int F_116 ( struct V_69 * V_69 )
{
struct V_69 * V_168 , * V_169 ;
int V_170 = 1 ;
#ifdef F_78
if ( V_69 -> V_9 & V_165 )
return F_117 ( V_69 ) ;
#endif
F_85 () ;
if ( V_78 == V_69 ) {
V_78 = V_69 -> V_167 ;
V_170 = 0 ;
} else if ( V_78 ) {
for ( V_168 = V_78 -> V_167 , V_169 = V_78 ;
V_168 ; V_169 = V_168 , V_168 = V_169 -> V_167 ) {
if ( V_168 == V_69 ) {
V_169 -> V_167 = V_168 -> V_167 ;
V_170 = 0 ;
break;
}
}
}
if ( V_78 != NULL && V_69 -> V_9 & V_164 )
V_78 -> V_9 |= V_164 ;
F_73 () ;
F_115 () ;
return V_170 ;
}
static int T_1 F_118 ( void )
{
struct V_69 * V_70 ;
F_41 (con) {
if ( ! V_157 && V_70 -> V_9 & V_160 ) {
F_45 ( V_76 L_27 ,
V_70 -> V_115 , V_70 -> V_121 ) ;
F_116 ( V_70 ) ;
}
}
F_119 ( F_89 , 0 ) ;
return 0 ;
}
int F_120 ( const char * V_92 , ... )
{
unsigned long V_9 ;
T_5 args ;
char * V_43 ;
int V_93 ;
F_66 ( V_9 ) ;
V_43 = F_97 ( V_146 ) ;
va_start ( args , V_92 ) ;
V_93 = vsnprintf ( V_43 , V_171 , V_92 , args ) ;
va_end ( args ) ;
F_121 ( V_143 , V_145 ) ;
F_75 ( V_9 ) ;
return V_93 ;
}
int F_122 ( const char * V_172 )
{
return F_123 ( & V_173 , V_172 ) ;
}
bool F_124 ( unsigned long * V_174 ,
unsigned int V_175 )
{
if ( * V_174 == 0
|| ! F_125 ( V_31 , * V_174 ,
* V_174
+ F_20 ( V_175 ) ) ) {
* V_174 = V_31 ;
return true ;
}
return false ;
}
int F_126 ( struct V_176 * V_177 )
{
unsigned long V_9 ;
int V_178 = - V_179 ;
if ( ! V_177 -> V_180 )
return - V_54 ;
F_127 ( & V_181 , V_9 ) ;
if ( ! V_177 -> V_182 ) {
V_177 -> V_182 = 1 ;
F_128 ( & V_177 -> V_183 , & V_184 ) ;
V_178 = 0 ;
}
F_129 ( & V_181 , V_9 ) ;
return V_178 ;
}
int F_130 ( struct V_176 * V_177 )
{
unsigned long V_9 ;
int V_178 = - V_54 ;
F_127 ( & V_181 , V_9 ) ;
if ( V_177 -> V_182 ) {
V_177 -> V_182 = 0 ;
F_131 ( & V_177 -> V_183 ) ;
V_178 = 0 ;
}
F_129 ( & V_181 , V_9 ) ;
F_132 () ;
return V_178 ;
}
void F_133 ( enum V_185 V_186 )
{
unsigned long V_68 ;
unsigned V_187 ;
struct V_176 * V_177 ;
const char * V_188 , * V_189 ;
unsigned long V_190 , V_191 ;
unsigned long V_9 ;
if ( ( V_186 > V_192 ) && ! V_193 )
return;
F_12 ( & V_16 , V_9 ) ;
V_68 = V_2 & V_79 ;
V_187 = V_4 ;
F_14 ( & V_16 , V_9 ) ;
if ( V_187 > V_68 ) {
V_188 = V_1 + V_3 - V_187 + V_68 ;
V_190 = V_187 - V_68 ;
V_189 = V_1 ;
V_191 = V_68 ;
} else {
V_188 = L_12 ;
V_190 = 0 ;
V_189 = V_1 + V_68 - V_187 ;
V_191 = V_187 ;
}
F_134 () ;
F_135 (dumper, &dump_list, list)
V_177 -> V_180 ( V_177 , V_186 , V_188 , V_190 , V_189 , V_191 ) ;
F_136 () ;
}
