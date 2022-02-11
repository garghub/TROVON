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
if ( V_14 == V_16 )
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
F_12 ( & V_17 , V_9 ) ;
V_3 = V_7 ;
V_1 = V_13 ;
V_7 = 0 ;
free = V_18 - V_2 ;
V_12 = V_10 = F_13 ( V_19 , V_20 ) ;
V_11 = 0 ;
while ( V_10 != V_2 ) {
unsigned V_21 = V_10 & ( V_18 - 1 ) ;
V_1 [ V_11 ] = V_22 [ V_21 ] ;
V_10 ++ ;
V_11 ++ ;
}
V_20 -= V_12 ;
V_19 -= V_12 ;
V_2 -= V_12 ;
F_14 ( & V_17 , V_9 ) ;
F_15 ( L_2 , V_3 ) ;
F_15 ( L_3 ,
free , ( free * 100 ) / V_18 ) ;
}
static int T_1 F_16 ( char * V_5 )
{
unsigned long V_23 ;
V_23 = V_24 ? V_24 : 1000000 ;
V_25 = ( unsigned long long ) V_23 / 1000 * V_26 ;
F_17 ( & V_5 , & V_27 ) ;
if ( V_27 > 10 * 1000 )
V_27 = 0 ;
F_18 ( L_4
L_5 ,
V_27 , V_24 , V_23 , V_26 , V_25 ) ;
return 1 ;
}
static void F_19 ( void )
{
unsigned long long V_28 ;
unsigned long V_29 ;
if ( V_27 == 0 || V_30 != V_31 )
return;
V_28 = ( unsigned long long ) V_25 * V_27 ;
V_29 = V_32 + F_20 ( V_27 ) ;
while ( V_28 ) {
V_28 -- ;
F_21 () ;
if ( F_22 ( V_32 , V_29 ) )
break;
F_23 () ;
}
}
static inline void F_19 ( void )
{
}
static int F_24 ( int type )
{
if ( V_33 )
return 1 ;
return type != V_34 && type != V_35 ;
}
static int F_25 ( int type , bool V_36 )
{
if ( V_36 && type != V_37 )
return 0 ;
if ( F_24 ( type ) ) {
if ( F_26 ( V_38 ) )
return 0 ;
if ( F_26 ( V_39 ) ) {
F_27 ( V_40 L_6
L_7
L_8 ,
V_41 -> V_42 , F_28 ( V_41 ) ) ;
return 0 ;
}
return - V_43 ;
}
return 0 ;
}
int F_29 ( int type , char T_2 * V_44 , int V_45 , bool V_36 )
{
unsigned V_46 , V_47 , V_48 , V_49 ;
int V_50 = 0 ;
char V_51 ;
int error ;
error = F_25 ( type , V_36 ) ;
if ( error )
goto V_52;
error = F_30 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_53 :
break;
case V_37 :
break;
case V_54 :
error = - V_55 ;
if ( ! V_44 || V_45 < 0 )
goto V_52;
error = 0 ;
if ( ! V_45 )
goto V_52;
if ( ! F_31 ( V_56 , V_44 , V_45 ) ) {
error = - V_57 ;
goto V_52;
}
error = F_32 ( V_58 ,
( V_20 - V_2 ) ) ;
if ( error )
goto V_52;
V_46 = 0 ;
F_33 ( & V_17 ) ;
while ( ! error && ( V_20 != V_2 ) && V_46 < V_45 ) {
V_51 = F_34 ( V_20 ) ;
V_20 ++ ;
F_35 ( & V_17 ) ;
error = F_36 ( V_51 , V_44 ) ;
V_44 ++ ;
V_46 ++ ;
F_37 () ;
F_33 ( & V_17 ) ;
}
F_35 ( & V_17 ) ;
if ( ! error )
error = V_46 ;
break;
case V_59 :
V_50 = 1 ;
case V_34 :
error = - V_55 ;
if ( ! V_44 || V_45 < 0 )
goto V_52;
error = 0 ;
if ( ! V_45 )
goto V_52;
if ( ! F_31 ( V_56 , V_44 , V_45 ) ) {
error = - V_57 ;
goto V_52;
}
V_49 = V_45 ;
if ( V_49 > V_3 )
V_49 = V_3 ;
F_33 ( & V_17 ) ;
if ( V_49 > V_4 )
V_49 = V_4 ;
if ( V_50 )
V_4 = 0 ;
V_48 = V_2 ;
for ( V_46 = 0 ; V_46 < V_49 && ! error ; V_46 ++ ) {
V_47 = V_48 - 1 - V_46 ;
if ( V_47 + V_3 < V_2 )
break;
V_51 = F_34 ( V_47 ) ;
F_35 ( & V_17 ) ;
error = F_36 ( V_51 , & V_44 [ V_49 - 1 - V_46 ] ) ;
F_37 () ;
F_33 ( & V_17 ) ;
}
F_35 ( & V_17 ) ;
if ( error )
break;
error = V_46 ;
if ( V_46 != V_49 ) {
int V_12 = V_49 - error ;
for ( V_46 = 0 ; V_46 < error ; V_46 ++ ) {
if ( F_38 ( V_51 , & V_44 [ V_46 + V_12 ] ) ||
F_36 ( V_51 , & V_44 [ V_46 ] ) ) {
error = - V_57 ;
break;
}
F_37 () ;
}
}
break;
case V_60 :
V_4 = 0 ;
break;
case V_61 :
if ( V_62 == - 1 )
V_62 = V_63 ;
V_63 = V_64 ;
break;
case V_65 :
if ( V_62 != - 1 ) {
V_63 = V_62 ;
V_62 = - 1 ;
}
break;
case V_66 :
error = - V_55 ;
if ( V_45 < 1 || V_45 > 8 )
goto V_52;
if ( V_45 < V_64 )
V_45 = V_64 ;
V_63 = V_45 ;
V_62 = - 1 ;
error = 0 ;
break;
case V_67 :
error = V_2 - V_20 ;
break;
case V_35 :
error = V_3 ;
break;
default:
error = - V_55 ;
break;
}
V_52:
return error ;
}
void F_39 ( char * V_68 [ 4 ] )
{
V_68 [ 0 ] = V_1 ;
V_68 [ 1 ] = V_1 + V_3 ;
V_68 [ 2 ] = V_1 + V_2 -
( V_4 < V_3 ? V_4 : V_3 ) ;
V_68 [ 3 ] = V_1 + V_2 ;
}
static void F_40 ( unsigned V_10 , unsigned V_69 )
{
struct V_70 * V_71 ;
F_41 (con) {
if ( V_72 && V_71 != V_72 )
continue;
if ( ( V_71 -> V_9 & V_73 ) && V_71 -> V_74 &&
( F_42 ( F_43 () ) ||
( V_71 -> V_9 & V_75 ) ) )
V_71 -> V_74 ( V_71 , & F_34 ( V_10 ) , V_69 - V_10 ) ;
}
}
static int T_1 F_44 ( char * V_5 )
{
V_76 = 1 ;
F_45 ( V_77 L_9 ) ;
return 0 ;
}
static void F_46 ( unsigned V_10 ,
unsigned V_69 , int V_78 )
{
if ( ( V_78 < V_63 || V_76 ) &&
V_79 && V_10 != V_69 ) {
if ( ( V_10 & V_80 ) > ( V_69 & V_80 ) ) {
F_40 ( V_10 & V_80 ,
V_3 ) ;
F_40 ( 0 , V_69 & V_80 ) ;
} else {
F_40 ( V_10 , V_69 ) ;
}
}
}
static T_3 F_47 ( const char * V_81 , unsigned int * V_82 , char * V_83 )
{
unsigned int V_84 = 0 ;
char V_85 = '\0' ;
T_3 V_45 ;
if ( V_81 [ 0 ] != '<' || ! V_81 [ 1 ] )
return 0 ;
if ( V_81 [ 2 ] == '>' ) {
switch ( V_81 [ 1 ] ) {
case '0' ... '7' :
V_84 = V_81 [ 1 ] - '0' ;
break;
case 'c' :
case 'd' :
V_85 = V_81 [ 1 ] ;
break;
default:
return 0 ;
}
V_45 = 3 ;
} else {
char * V_86 = NULL ;
if ( V_81 [ 1 ] < '0' && V_81 [ 1 ] > '9' )
return 0 ;
V_84 = ( F_48 ( & V_81 [ 1 ] , & V_86 , 10 ) & 7 ) ;
if ( V_86 == NULL || V_86 [ 0 ] != '>' )
return 0 ;
V_45 = ( V_86 + 1 ) - V_81 ;
}
if ( V_85 && ! V_83 )
return 0 ;
if ( V_83 ) {
* V_83 = V_85 ;
if ( V_85 )
return V_45 ;
}
if ( V_82 )
* V_82 = V_84 ;
return V_45 ;
}
static void F_49 ( unsigned V_10 , unsigned V_69 )
{
unsigned V_87 , V_88 ;
static int V_89 = - 1 ;
F_50 ( ( ( int ) ( V_10 - V_69 ) ) > 0 ) ;
V_87 = V_10 ;
V_88 = V_10 ;
while ( V_87 != V_69 ) {
if ( V_89 < 0 && ( ( V_69 - V_87 ) > 2 ) ) {
V_87 += F_47 ( & F_34 ( V_87 ) , & V_89 , NULL ) ;
V_88 = V_87 ;
}
while ( V_87 != V_69 ) {
char V_51 = F_34 ( V_87 ) ;
V_87 ++ ;
if ( V_51 == '\n' ) {
if ( V_89 < 0 ) {
V_89 = V_90 ;
}
F_46 ( V_88 , V_87 , V_89 ) ;
V_89 = - 1 ;
V_88 = V_87 ;
break;
}
}
}
F_46 ( V_88 , V_69 , V_89 ) ;
}
static void F_51 ( char V_51 )
{
F_34 ( V_2 ) = V_51 ;
V_2 ++ ;
if ( V_2 - V_20 > V_3 )
V_20 = V_2 - V_3 ;
if ( V_2 - V_19 > V_3 )
V_19 = V_2 - V_3 ;
if ( V_4 < V_3 )
V_4 ++ ;
}
static void F_52 ( void )
{
static unsigned long V_91 ;
if ( F_53 ( V_32 , V_91 ) &&
! F_22 ( V_32 , V_91 + 30 * V_26 ) )
return;
V_91 = V_32 ;
F_54 ( & V_17 ) ;
F_55 ( & V_92 , 1 ) ;
}
static int F_56 ( void )
{
struct V_70 * V_71 ;
F_41 (con)
if ( V_71 -> V_9 & V_75 )
return 1 ;
return 0 ;
}
T_4 int F_45 ( const char * V_93 , ... )
{
T_5 args ;
int V_94 ;
#ifdef F_57
if ( F_10 ( V_95 ) ) {
va_start ( args , V_93 ) ;
V_94 = F_58 ( V_93 , args ) ;
va_end ( args ) ;
return V_94 ;
}
#endif
va_start ( args , V_93 ) ;
V_94 = F_59 ( V_93 , args ) ;
va_end ( args ) ;
return V_94 ;
}
static inline int F_60 ( unsigned int V_96 )
{
return F_42 ( V_96 ) || F_56 () ;
}
static int F_61 ( unsigned int V_96 )
__releases( &logbuf_lock
static inline void F_62 ( void )
{
if ( F_10 ( V_97 ) ) {
int V_98 = V_97 ;
while ( V_98 -- ) {
F_63 ( 1 ) ;
F_23 () ;
}
}
}
T_4 int F_59 ( const char * V_93 , T_5 args )
{
int V_99 = 0 ;
int V_100 = V_90 ;
unsigned long V_9 ;
int V_101 ;
char * V_81 ;
T_3 V_102 ;
char V_83 ;
F_19 () ;
F_62 () ;
F_64 () ;
F_65 ( V_9 ) ;
V_101 = F_43 () ;
if ( F_10 ( V_103 == V_101 ) ) {
if ( ! V_104 ) {
V_105 = 1 ;
goto V_106;
}
F_52 () ;
}
F_66 () ;
F_67 ( & V_17 ) ;
V_103 = V_101 ;
if ( V_105 ) {
V_105 = 0 ;
strcpy ( V_107 , V_108 ) ;
V_99 = strlen ( V_108 ) ;
}
V_99 += F_68 ( V_107 + V_99 ,
sizeof( V_107 ) - V_99 , V_93 , args ) ;
V_81 = V_107 ;
V_102 = F_47 ( V_81 , & V_100 , & V_83 ) ;
if ( V_102 ) {
V_81 += V_102 ;
switch ( V_83 ) {
case 'c' :
V_102 = 0 ;
break;
case 'd' :
V_102 = 0 ;
default:
if ( ! V_109 ) {
F_51 ( '\n' ) ;
V_109 = 1 ;
}
}
}
for (; * V_81 ; V_81 ++ ) {
if ( V_109 ) {
V_109 = 0 ;
if ( V_102 ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < V_102 ; V_46 ++ )
F_51 ( V_107 [ V_46 ] ) ;
V_99 += V_102 ;
} else {
F_51 ( '<' ) ;
F_51 ( V_100 + '0' ) ;
F_51 ( '>' ) ;
V_99 += 3 ;
}
if ( V_110 ) {
char V_111 [ 50 ] , * V_112 ;
unsigned V_113 ;
unsigned long long V_114 ;
unsigned long V_115 ;
V_114 = F_69 ( V_103 ) ;
V_115 = F_70 ( V_114 , 1000000000 ) ;
V_113 = sprintf ( V_111 , L_10 ,
( unsigned long ) V_114 ,
V_115 / 1000 ) ;
for ( V_112 = V_111 ; V_112 < V_111 + V_113 ; V_112 ++ )
F_51 ( * V_112 ) ;
V_99 += V_113 ;
}
if ( ! * V_81 )
break;
}
F_51 ( * V_81 ) ;
if ( * V_81 == '\n' )
V_109 = 1 ;
}
if ( F_61 ( V_101 ) )
F_71 () ;
F_72 () ;
V_106:
F_73 ( V_9 ) ;
F_74 () ;
return V_99 ;
}
static void F_49 ( unsigned V_10 , unsigned V_69 )
{
}
static int F_75 ( char * V_116 , int V_117 , char * V_118 ,
char * V_119 )
{
struct V_120 * V_51 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_121 && V_120 [ V_46 ] . V_116 [ 0 ] ; V_46 ++ )
if ( strcmp ( V_120 [ V_46 ] . V_116 , V_116 ) == 0 &&
V_120 [ V_46 ] . V_122 == V_117 ) {
if ( ! V_119 )
V_123 = V_46 ;
return 0 ;
}
if ( V_46 == V_121 )
return - V_124 ;
if ( ! V_119 )
V_123 = V_46 ;
V_51 = & V_120 [ V_46 ] ;
F_76 ( V_51 -> V_116 , V_116 , sizeof( V_51 -> V_116 ) ) ;
V_51 -> V_118 = V_118 ;
#ifdef F_77
V_51 -> V_119 = V_119 ;
#endif
V_51 -> V_122 = V_117 ;
return 0 ;
}
static int T_1 F_78 ( char * V_5 )
{
char V_44 [ sizeof( V_120 [ 0 ] . V_116 ) + 4 ] ;
char * V_125 , * V_118 , * V_119 = NULL ;
int V_117 ;
#ifdef F_77
if ( ! memcmp ( V_5 , L_11 , 4 ) ) {
V_119 = L_12 ;
V_5 += 4 ;
} else if ( ! memcmp ( V_5 , L_13 , 4 ) ) {
V_119 = V_5 + 4 ;
V_5 = strchr ( V_119 , ',' ) ;
if ( ! V_5 ) {
F_45 ( V_126 L_14 ) ;
return 1 ;
}
* ( V_5 ++ ) = 0 ;
}
#endif
if ( V_5 [ 0 ] >= '0' && V_5 [ 0 ] <= '9' ) {
strcpy ( V_44 , L_15 ) ;
strncpy ( V_44 + 4 , V_5 , sizeof( V_44 ) - 5 ) ;
} else {
strncpy ( V_44 , V_5 , sizeof( V_44 ) - 1 ) ;
}
V_44 [ sizeof( V_44 ) - 1 ] = 0 ;
if ( ( V_118 = strchr ( V_5 , ',' ) ) != NULL )
* ( V_118 ++ ) = 0 ;
#ifdef F_79
if ( ! strcmp ( V_5 , L_16 ) )
strcpy ( V_44 , L_17 ) ;
if ( ! strcmp ( V_5 , L_18 ) )
strcpy ( V_44 , L_19 ) ;
#endif
for ( V_125 = V_44 ; * V_125 ; V_125 ++ )
if ( ( * V_125 >= '0' && * V_125 <= '9' ) || * V_125 == ',' )
break;
V_117 = F_48 ( V_125 , NULL , 10 ) ;
* V_125 = 0 ;
F_75 ( V_44 , V_117 , V_118 , V_119 ) ;
V_127 = 1 ;
return 1 ;
}
int F_80 ( char * V_116 , int V_117 , char * V_118 )
{
return F_75 ( V_116 , V_117 , V_118 , NULL ) ;
}
int F_81 ( char * V_116 , int V_117 , char * V_128 , int V_129 , char * V_118 )
{
struct V_120 * V_51 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_121 && V_120 [ V_46 ] . V_116 [ 0 ] ; V_46 ++ )
if ( strcmp ( V_120 [ V_46 ] . V_116 , V_116 ) == 0 &&
V_120 [ V_46 ] . V_122 == V_117 ) {
V_51 = & V_120 [ V_46 ] ;
F_76 ( V_51 -> V_116 , V_128 , sizeof( V_51 -> V_116 ) ) ;
V_51 -> V_116 [ sizeof( V_51 -> V_116 ) - 1 ] = 0 ;
V_51 -> V_118 = V_118 ;
V_51 -> V_122 = V_129 ;
return V_46 ;
}
return - 1 ;
}
static int T_1 F_82 ( char * V_5 )
{
V_130 = 0 ;
return 1 ;
}
void F_83 ( void )
{
if ( ! V_130 )
return;
F_45 ( L_20 ) ;
F_84 () ;
V_131 = 1 ;
F_85 ( & V_92 ) ;
}
void F_86 ( void )
{
if ( ! V_130 )
return;
F_87 ( & V_92 ) ;
V_131 = 0 ;
F_71 () ;
}
static int T_6 F_88 ( struct V_132 * V_133 ,
unsigned long V_134 , void * V_135 )
{
switch ( V_134 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
F_84 () ;
F_71 () ;
}
return V_141 ;
}
void F_84 ( void )
{
F_50 ( F_89 () ) ;
F_87 ( & V_92 ) ;
if ( V_131 )
return;
V_142 = 1 ;
V_143 = 1 ;
}
int F_90 ( void )
{
if ( F_91 ( & V_92 ) )
return 0 ;
if ( V_131 ) {
F_85 ( & V_92 ) ;
return 0 ;
}
V_142 = 1 ;
V_143 = 0 ;
return 1 ;
}
int F_92 ( void )
{
return V_142 ;
}
void F_93 ( void )
{
if ( F_94 ( V_144 ) ) {
F_95 ( V_144 , 0 ) ;
F_96 ( & V_58 ) ;
}
}
int F_97 ( int V_96 )
{
if ( F_98 ( V_96 ) )
F_93 () ;
return F_94 ( V_144 ) ;
}
void F_99 ( void )
{
if ( F_100 ( & V_58 ) )
F_101 ( V_144 , 1 ) ;
}
void F_71 ( void )
{
unsigned long V_9 ;
unsigned V_145 , V_146 ;
unsigned V_147 = 0 , V_148 = 0 ;
if ( V_131 ) {
F_85 ( & V_92 ) ;
return;
}
V_143 = 0 ;
V_149:
for ( ; ; ) {
F_12 ( & V_17 , V_9 ) ;
V_147 |= V_20 - V_2 ;
if ( V_19 == V_2 )
break;
V_145 = V_19 ;
V_146 = V_2 ;
V_19 = V_2 ;
F_102 ( & V_17 ) ;
F_103 () ;
F_49 ( V_145 , V_146 ) ;
F_104 () ;
F_105 ( V_9 ) ;
}
V_142 = 0 ;
if ( F_10 ( V_72 ) )
V_72 = NULL ;
F_102 ( & V_17 ) ;
F_85 ( & V_92 ) ;
F_67 ( & V_17 ) ;
if ( V_19 != V_2 )
V_148 = 1 ;
F_14 ( & V_17 , V_9 ) ;
if ( V_148 && F_90 () )
goto V_149;
if ( V_147 )
F_99 () ;
}
void T_7 F_106 ( void )
{
if ( V_143 )
F_37 () ;
}
void F_107 ( void )
{
struct V_70 * V_51 ;
if ( V_104 ) {
if ( F_91 ( & V_92 ) != 0 )
return;
} else
F_84 () ;
V_142 = 1 ;
V_143 = 0 ;
F_41 (c)
if ( ( V_51 -> V_9 & V_73 ) && V_51 -> V_150 )
V_51 -> V_150 () ;
F_71 () ;
}
struct V_151 * F_108 ( int * V_122 )
{
struct V_70 * V_51 ;
struct V_151 * V_152 = NULL ;
F_84 () ;
F_41 (c) {
if ( ! V_51 -> V_153 )
continue;
V_152 = V_51 -> V_153 ( V_51 , V_122 ) ;
if ( V_152 )
break;
}
F_71 () ;
return V_152 ;
}
void F_109 ( struct V_70 * V_70 )
{
F_84 () ;
V_70 -> V_9 &= ~ V_73 ;
F_71 () ;
}
void F_110 ( struct V_70 * V_70 )
{
F_84 () ;
V_70 -> V_9 |= V_73 ;
F_71 () ;
}
static int T_1 F_111 ( char * V_5 )
{
V_154 = 1 ;
F_45 ( V_77 L_21 ) ;
return 0 ;
}
void F_112 ( struct V_70 * V_155 )
{
int V_46 ;
unsigned long V_9 ;
struct V_70 * V_156 = NULL ;
if ( V_79 && V_155 -> V_9 & V_157 ) {
F_41 (bcon) {
if ( ! ( V_156 -> V_9 & V_157 ) ) {
F_45 ( V_77 L_22 ,
V_155 -> V_116 , V_155 -> V_122 ) ;
return;
}
}
}
if ( V_79 && V_79 -> V_9 & V_157 )
V_156 = V_79 ;
if ( V_158 < 0 || V_156 || ! V_79 )
V_158 = V_123 ;
if ( V_155 -> V_159 )
V_155 -> V_159 () ;
if ( V_158 < 0 ) {
if ( V_155 -> V_122 < 0 )
V_155 -> V_122 = 0 ;
if ( V_155 -> V_160 == NULL ||
V_155 -> V_160 ( V_155 , NULL ) == 0 ) {
V_155 -> V_9 |= V_73 ;
if ( V_155 -> V_153 ) {
V_155 -> V_9 |= V_161 ;
V_158 = 0 ;
}
}
}
for ( V_46 = 0 ; V_46 < V_121 && V_120 [ V_46 ] . V_116 [ 0 ] ;
V_46 ++ ) {
if ( strcmp ( V_120 [ V_46 ] . V_116 , V_155 -> V_116 ) != 0 )
continue;
if ( V_155 -> V_122 >= 0 &&
V_155 -> V_122 != V_120 [ V_46 ] . V_122 )
continue;
if ( V_155 -> V_122 < 0 )
V_155 -> V_122 = V_120 [ V_46 ] . V_122 ;
#ifdef F_77
if ( V_120 [ V_46 ] . V_119 ) {
V_155 -> V_9 |= V_162 ;
F_113 ( V_155 ,
V_120 [ V_46 ] . V_122 ,
V_120 [ V_46 ] . V_118 ,
V_120 [ V_46 ] . V_119 ) ;
return;
}
#endif
if ( V_155 -> V_160 &&
V_155 -> V_160 ( V_155 , V_120 [ V_46 ] . V_118 ) != 0 )
break;
V_155 -> V_9 |= V_73 ;
V_155 -> V_122 = V_120 [ V_46 ] . V_122 ;
if ( V_46 == V_123 ) {
V_155 -> V_9 |= V_161 ;
V_158 = V_123 ;
}
break;
}
if ( ! ( V_155 -> V_9 & V_73 ) )
return;
if ( V_156 && ( ( V_155 -> V_9 & ( V_161 | V_157 ) ) == V_161 ) )
V_155 -> V_9 &= ~ V_163 ;
F_84 () ;
if ( ( V_155 -> V_9 & V_161 ) || V_79 == NULL ) {
V_155 -> V_164 = V_79 ;
V_79 = V_155 ;
if ( V_155 -> V_164 )
V_155 -> V_164 -> V_9 &= ~ V_161 ;
} else {
V_155 -> V_164 = V_79 -> V_164 ;
V_79 -> V_164 = V_155 ;
}
if ( V_155 -> V_9 & V_163 ) {
F_12 ( & V_17 , V_9 ) ;
V_19 = V_20 ;
F_14 ( & V_17 , V_9 ) ;
V_72 = V_155 ;
}
F_71 () ;
F_114 () ;
if ( V_156 &&
( ( V_155 -> V_9 & ( V_161 | V_157 ) ) == V_161 ) &&
! V_154 ) {
F_45 ( V_77 L_23 ,
V_155 -> V_116 , V_155 -> V_122 ) ;
F_41 (bcon)
if ( V_156 -> V_9 & V_157 )
F_115 ( V_156 ) ;
} else {
F_45 ( V_77 L_24 ,
( V_155 -> V_9 & V_157 ) ? L_25 : L_12 ,
V_155 -> V_116 , V_155 -> V_122 ) ;
}
}
int F_115 ( struct V_70 * V_70 )
{
struct V_70 * V_165 , * V_166 ;
int V_167 = 1 ;
#ifdef F_77
if ( V_70 -> V_9 & V_162 )
return F_116 ( V_70 ) ;
#endif
F_84 () ;
if ( V_79 == V_70 ) {
V_79 = V_70 -> V_164 ;
V_167 = 0 ;
} else if ( V_79 ) {
for ( V_165 = V_79 -> V_164 , V_166 = V_79 ;
V_165 ; V_166 = V_165 , V_165 = V_166 -> V_164 ) {
if ( V_165 == V_70 ) {
V_166 -> V_164 = V_165 -> V_164 ;
V_167 = 0 ;
break;
}
}
}
if ( V_79 != NULL && V_70 -> V_9 & V_161 )
V_79 -> V_9 |= V_161 ;
F_71 () ;
F_114 () ;
return V_167 ;
}
static int T_1 F_117 ( void )
{
struct V_70 * V_71 ;
F_41 (con) {
if ( ! V_154 && V_71 -> V_9 & V_157 ) {
F_45 ( V_77 L_26 ,
V_71 -> V_116 , V_71 -> V_122 ) ;
F_115 ( V_71 ) ;
}
}
F_118 ( F_88 , 0 ) ;
return 0 ;
}
int F_119 ( const char * V_168 )
{
return F_120 ( & V_169 , V_168 ) ;
}
bool F_121 ( unsigned long * V_170 ,
unsigned int V_171 )
{
if ( * V_170 == 0
|| ! F_122 ( V_32 , * V_170 ,
* V_170
+ F_20 ( V_171 ) ) ) {
* V_170 = V_32 ;
return true ;
}
return false ;
}
int F_123 ( struct V_172 * V_173 )
{
unsigned long V_9 ;
int V_174 = - V_175 ;
if ( ! V_173 -> V_176 )
return - V_55 ;
F_12 ( & V_177 , V_9 ) ;
if ( ! V_173 -> V_178 ) {
V_173 -> V_178 = 1 ;
F_124 ( & V_173 -> V_179 , & V_180 ) ;
V_174 = 0 ;
}
F_14 ( & V_177 , V_9 ) ;
return V_174 ;
}
int F_125 ( struct V_172 * V_173 )
{
unsigned long V_9 ;
int V_174 = - V_55 ;
F_12 ( & V_177 , V_9 ) ;
if ( V_173 -> V_178 ) {
V_173 -> V_178 = 0 ;
F_126 ( & V_173 -> V_179 ) ;
V_174 = 0 ;
}
F_14 ( & V_177 , V_9 ) ;
F_127 () ;
return V_174 ;
}
void F_128 ( enum V_181 V_182 )
{
unsigned long V_69 ;
unsigned V_183 ;
struct V_172 * V_173 ;
const char * V_184 , * V_185 ;
unsigned long V_186 , V_187 ;
unsigned long V_9 ;
F_12 ( & V_17 , V_9 ) ;
V_69 = V_2 & V_80 ;
V_183 = V_4 ;
F_14 ( & V_17 , V_9 ) ;
if ( V_183 > V_69 ) {
V_184 = V_1 + V_3 - V_183 + V_69 ;
V_186 = V_183 - V_69 ;
V_185 = V_1 ;
V_187 = V_69 ;
} else {
V_184 = L_12 ;
V_186 = 0 ;
V_185 = V_1 + V_69 - V_183 ;
V_187 = V_183 ;
}
F_129 () ;
F_130 (dumper, &dump_list, list)
V_173 -> V_176 ( V_173 , V_182 , V_184 , V_186 , V_185 , V_187 ) ;
F_131 () ;
}
