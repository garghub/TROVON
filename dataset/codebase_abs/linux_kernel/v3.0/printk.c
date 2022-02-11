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
F_27 ( 1 , L_6
L_7 ) ;
return 0 ;
}
return - V_40 ;
}
return 0 ;
}
int F_28 ( int type , char T_2 * V_41 , int V_42 , bool V_36 )
{
unsigned V_43 , V_44 , V_45 , V_46 ;
int V_47 = 0 ;
char V_48 ;
int error ;
error = F_25 ( type , V_36 ) ;
if ( error )
goto V_49;
error = F_29 ( type ) ;
if ( error )
return error ;
switch ( type ) {
case V_50 :
break;
case V_37 :
break;
case V_51 :
error = - V_52 ;
if ( ! V_41 || V_42 < 0 )
goto V_49;
error = 0 ;
if ( ! V_42 )
goto V_49;
if ( ! F_30 ( V_53 , V_41 , V_42 ) ) {
error = - V_54 ;
goto V_49;
}
error = F_31 ( V_55 ,
( V_20 - V_2 ) ) ;
if ( error )
goto V_49;
V_43 = 0 ;
F_32 ( & V_17 ) ;
while ( ! error && ( V_20 != V_2 ) && V_43 < V_42 ) {
V_48 = F_33 ( V_20 ) ;
V_20 ++ ;
F_34 ( & V_17 ) ;
error = F_35 ( V_48 , V_41 ) ;
V_41 ++ ;
V_43 ++ ;
F_36 () ;
F_32 ( & V_17 ) ;
}
F_34 ( & V_17 ) ;
if ( ! error )
error = V_43 ;
break;
case V_56 :
V_47 = 1 ;
case V_34 :
error = - V_52 ;
if ( ! V_41 || V_42 < 0 )
goto V_49;
error = 0 ;
if ( ! V_42 )
goto V_49;
if ( ! F_30 ( V_53 , V_41 , V_42 ) ) {
error = - V_54 ;
goto V_49;
}
V_46 = V_42 ;
if ( V_46 > V_3 )
V_46 = V_3 ;
F_32 ( & V_17 ) ;
if ( V_46 > V_4 )
V_46 = V_4 ;
if ( V_47 )
V_4 = 0 ;
V_45 = V_2 ;
for ( V_43 = 0 ; V_43 < V_46 && ! error ; V_43 ++ ) {
V_44 = V_45 - 1 - V_43 ;
if ( V_44 + V_3 < V_2 )
break;
V_48 = F_33 ( V_44 ) ;
F_34 ( & V_17 ) ;
error = F_35 ( V_48 , & V_41 [ V_46 - 1 - V_43 ] ) ;
F_36 () ;
F_32 ( & V_17 ) ;
}
F_34 ( & V_17 ) ;
if ( error )
break;
error = V_43 ;
if ( V_43 != V_46 ) {
int V_12 = V_46 - error ;
for ( V_43 = 0 ; V_43 < error ; V_43 ++ ) {
if ( F_37 ( V_48 , & V_41 [ V_43 + V_12 ] ) ||
F_35 ( V_48 , & V_41 [ V_43 ] ) ) {
error = - V_54 ;
break;
}
F_36 () ;
}
}
break;
case V_57 :
V_4 = 0 ;
break;
case V_58 :
if ( V_59 == - 1 )
V_59 = V_60 ;
V_60 = V_61 ;
break;
case V_62 :
if ( V_59 != - 1 ) {
V_60 = V_59 ;
V_59 = - 1 ;
}
break;
case V_63 :
error = - V_52 ;
if ( V_42 < 1 || V_42 > 8 )
goto V_49;
if ( V_42 < V_61 )
V_42 = V_61 ;
V_60 = V_42 ;
V_59 = - 1 ;
error = 0 ;
break;
case V_64 :
error = V_2 - V_20 ;
break;
case V_35 :
error = V_3 ;
break;
default:
error = - V_52 ;
break;
}
V_49:
return error ;
}
void F_38 ( char * V_65 [ 4 ] )
{
V_65 [ 0 ] = V_1 ;
V_65 [ 1 ] = V_1 + V_3 ;
V_65 [ 2 ] = V_1 + V_2 -
( V_4 < V_3 ? V_4 : V_3 ) ;
V_65 [ 3 ] = V_1 + V_2 ;
}
static void F_39 ( unsigned V_10 , unsigned V_66 )
{
struct V_67 * V_68 ;
F_40 (con) {
if ( V_69 && V_68 != V_69 )
continue;
if ( ( V_68 -> V_9 & V_70 ) && V_68 -> V_71 &&
( F_41 ( F_42 () ) ||
( V_68 -> V_9 & V_72 ) ) )
V_68 -> V_71 ( V_68 , & F_33 ( V_10 ) , V_66 - V_10 ) ;
}
}
static int T_1 F_43 ( char * V_5 )
{
V_73 = 1 ;
F_44 ( V_74 L_8 ) ;
return 0 ;
}
static void F_45 ( unsigned V_10 ,
unsigned V_66 , int V_75 )
{
if ( ( V_75 < V_60 || V_73 ) &&
V_76 && V_10 != V_66 ) {
if ( ( V_10 & V_77 ) > ( V_66 & V_77 ) ) {
F_39 ( V_10 & V_77 ,
V_3 ) ;
F_39 ( 0 , V_66 & V_77 ) ;
} else {
F_39 ( V_10 , V_66 ) ;
}
}
}
static T_3 F_46 ( const char * V_78 , unsigned int * V_79 , char * V_80 )
{
unsigned int V_81 = 0 ;
char V_82 = '\0' ;
T_3 V_42 ;
if ( V_78 [ 0 ] != '<' || ! V_78 [ 1 ] )
return 0 ;
if ( V_78 [ 2 ] == '>' ) {
switch ( V_78 [ 1 ] ) {
case '0' ... '7' :
V_81 = V_78 [ 1 ] - '0' ;
break;
case 'c' :
case 'd' :
V_82 = V_78 [ 1 ] ;
break;
default:
return 0 ;
}
V_42 = 3 ;
} else {
char * V_83 = NULL ;
if ( V_78 [ 1 ] < '0' && V_78 [ 1 ] > '9' )
return 0 ;
V_81 = ( F_47 ( & V_78 [ 1 ] , & V_83 , 10 ) & 7 ) ;
if ( V_83 == NULL || V_83 [ 0 ] != '>' )
return 0 ;
V_42 = ( V_83 + 1 ) - V_78 ;
}
if ( V_82 && ! V_80 )
return 0 ;
if ( V_80 ) {
* V_80 = V_82 ;
if ( V_82 )
return V_42 ;
}
if ( V_79 )
* V_79 = V_81 ;
return V_42 ;
}
static void F_48 ( unsigned V_10 , unsigned V_66 )
{
unsigned V_84 , V_85 ;
static int V_86 = - 1 ;
F_49 ( ( ( int ) ( V_10 - V_66 ) ) > 0 ) ;
V_84 = V_10 ;
V_85 = V_10 ;
while ( V_84 != V_66 ) {
if ( V_86 < 0 && ( ( V_66 - V_84 ) > 2 ) ) {
V_84 += F_46 ( & F_33 ( V_84 ) , & V_86 , NULL ) ;
V_85 = V_84 ;
}
while ( V_84 != V_66 ) {
char V_48 = F_33 ( V_84 ) ;
V_84 ++ ;
if ( V_48 == '\n' ) {
if ( V_86 < 0 ) {
V_86 = V_87 ;
}
F_45 ( V_85 , V_84 , V_86 ) ;
V_86 = - 1 ;
V_85 = V_84 ;
break;
}
}
}
F_45 ( V_85 , V_66 , V_86 ) ;
}
static void F_50 ( char V_48 )
{
F_33 ( V_2 ) = V_48 ;
V_2 ++ ;
if ( V_2 - V_20 > V_3 )
V_20 = V_2 - V_3 ;
if ( V_2 - V_19 > V_3 )
V_19 = V_2 - V_3 ;
if ( V_4 < V_3 )
V_4 ++ ;
}
static void F_51 ( void )
{
static unsigned long V_88 ;
if ( F_52 ( V_32 , V_88 ) &&
! F_22 ( V_32 , V_88 + 30 * V_26 ) )
return;
V_88 = V_32 ;
F_53 ( & V_17 ) ;
F_54 ( & V_89 , 1 ) ;
}
static int F_55 ( void )
{
struct V_67 * V_68 ;
F_40 (con)
if ( V_68 -> V_9 & V_72 )
return 1 ;
return 0 ;
}
T_4 int F_44 ( const char * V_90 , ... )
{
T_5 args ;
int V_91 ;
#ifdef F_56
if ( F_10 ( V_92 ) ) {
va_start ( args , V_90 ) ;
V_91 = F_57 ( V_90 , args ) ;
va_end ( args ) ;
return V_91 ;
}
#endif
va_start ( args , V_90 ) ;
V_91 = F_58 ( V_90 , args ) ;
va_end ( args ) ;
return V_91 ;
}
static inline int F_59 ( unsigned int V_93 )
{
return F_41 ( V_93 ) || F_55 () ;
}
static int F_60 ( unsigned int V_93 )
__releases( &logbuf_lock
static inline void F_61 ( void )
{
if ( F_10 ( V_94 ) ) {
int V_95 = V_94 ;
while ( V_95 -- ) {
F_62 ( 1 ) ;
F_23 () ;
}
}
}
T_4 int F_58 ( const char * V_90 , T_5 args )
{
int V_96 = 0 ;
int V_97 = V_87 ;
unsigned long V_9 ;
int V_98 ;
char * V_78 ;
T_3 V_99 ;
char V_80 ;
F_19 () ;
F_61 () ;
F_63 () ;
F_64 ( V_9 ) ;
V_98 = F_42 () ;
if ( F_10 ( V_100 == V_98 ) ) {
if ( ! V_101 ) {
V_102 = 1 ;
goto V_103;
}
F_51 () ;
}
F_65 () ;
F_66 ( & V_17 ) ;
V_100 = V_98 ;
if ( V_102 ) {
V_102 = 0 ;
strcpy ( V_104 , V_105 ) ;
V_96 = strlen ( V_105 ) ;
}
V_96 += F_67 ( V_104 + V_96 ,
sizeof( V_104 ) - V_96 , V_90 , args ) ;
V_78 = V_104 ;
V_99 = F_46 ( V_78 , & V_97 , & V_80 ) ;
if ( V_99 ) {
V_78 += V_99 ;
switch ( V_80 ) {
case 'c' :
V_99 = 0 ;
break;
case 'd' :
V_99 = 0 ;
default:
if ( ! V_106 ) {
F_50 ( '\n' ) ;
V_106 = 1 ;
}
}
}
for (; * V_78 ; V_78 ++ ) {
if ( V_106 ) {
V_106 = 0 ;
if ( V_99 ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_99 ; V_43 ++ )
F_50 ( V_104 [ V_43 ] ) ;
V_96 += V_99 ;
} else {
F_50 ( '<' ) ;
F_50 ( V_97 + '0' ) ;
F_50 ( '>' ) ;
V_96 += 3 ;
}
if ( V_107 ) {
char V_108 [ 50 ] , * V_109 ;
unsigned V_110 ;
unsigned long long V_111 ;
unsigned long V_112 ;
V_111 = F_68 ( V_100 ) ;
V_112 = F_69 ( V_111 , 1000000000 ) ;
V_110 = sprintf ( V_108 , L_9 ,
( unsigned long ) V_111 ,
V_112 / 1000 ) ;
for ( V_109 = V_108 ; V_109 < V_108 + V_110 ; V_109 ++ )
F_50 ( * V_109 ) ;
V_96 += V_110 ;
}
if ( ! * V_78 )
break;
}
F_50 ( * V_78 ) ;
if ( * V_78 == '\n' )
V_106 = 1 ;
}
if ( F_60 ( V_98 ) )
F_70 () ;
F_71 () ;
V_103:
F_72 ( V_9 ) ;
F_73 () ;
return V_96 ;
}
static void F_48 ( unsigned V_10 , unsigned V_66 )
{
}
static int F_74 ( char * V_113 , int V_114 , char * V_115 ,
char * V_116 )
{
struct V_117 * V_48 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_118 && V_117 [ V_43 ] . V_113 [ 0 ] ; V_43 ++ )
if ( strcmp ( V_117 [ V_43 ] . V_113 , V_113 ) == 0 &&
V_117 [ V_43 ] . V_119 == V_114 ) {
if ( ! V_116 )
V_120 = V_43 ;
return 0 ;
}
if ( V_43 == V_118 )
return - V_121 ;
if ( ! V_116 )
V_120 = V_43 ;
V_48 = & V_117 [ V_43 ] ;
F_75 ( V_48 -> V_113 , V_113 , sizeof( V_48 -> V_113 ) ) ;
V_48 -> V_115 = V_115 ;
#ifdef F_76
V_48 -> V_116 = V_116 ;
#endif
V_48 -> V_119 = V_114 ;
return 0 ;
}
static int T_1 F_77 ( char * V_5 )
{
char V_41 [ sizeof( V_117 [ 0 ] . V_113 ) + 4 ] ;
char * V_122 , * V_115 , * V_116 = NULL ;
int V_114 ;
#ifdef F_76
if ( ! memcmp ( V_5 , L_10 , 4 ) ) {
V_116 = L_11 ;
V_5 += 4 ;
} else if ( ! memcmp ( V_5 , L_12 , 4 ) ) {
V_116 = V_5 + 4 ;
V_5 = strchr ( V_116 , ',' ) ;
if ( ! V_5 ) {
F_44 ( V_123 L_13 ) ;
return 1 ;
}
* ( V_5 ++ ) = 0 ;
}
#endif
if ( V_5 [ 0 ] >= '0' && V_5 [ 0 ] <= '9' ) {
strcpy ( V_41 , L_14 ) ;
strncpy ( V_41 + 4 , V_5 , sizeof( V_41 ) - 5 ) ;
} else {
strncpy ( V_41 , V_5 , sizeof( V_41 ) - 1 ) ;
}
V_41 [ sizeof( V_41 ) - 1 ] = 0 ;
if ( ( V_115 = strchr ( V_5 , ',' ) ) != NULL )
* ( V_115 ++ ) = 0 ;
#ifdef F_78
if ( ! strcmp ( V_5 , L_15 ) )
strcpy ( V_41 , L_16 ) ;
if ( ! strcmp ( V_5 , L_17 ) )
strcpy ( V_41 , L_18 ) ;
#endif
for ( V_122 = V_41 ; * V_122 ; V_122 ++ )
if ( ( * V_122 >= '0' && * V_122 <= '9' ) || * V_122 == ',' )
break;
V_114 = F_47 ( V_122 , NULL , 10 ) ;
* V_122 = 0 ;
F_74 ( V_41 , V_114 , V_115 , V_116 ) ;
V_124 = 1 ;
return 1 ;
}
int F_79 ( char * V_113 , int V_114 , char * V_115 )
{
return F_74 ( V_113 , V_114 , V_115 , NULL ) ;
}
int F_80 ( char * V_113 , int V_114 , char * V_125 , int V_126 , char * V_115 )
{
struct V_117 * V_48 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_118 && V_117 [ V_43 ] . V_113 [ 0 ] ; V_43 ++ )
if ( strcmp ( V_117 [ V_43 ] . V_113 , V_113 ) == 0 &&
V_117 [ V_43 ] . V_119 == V_114 ) {
V_48 = & V_117 [ V_43 ] ;
F_75 ( V_48 -> V_113 , V_125 , sizeof( V_48 -> V_113 ) ) ;
V_48 -> V_113 [ sizeof( V_48 -> V_113 ) - 1 ] = 0 ;
V_48 -> V_115 = V_115 ;
V_48 -> V_119 = V_126 ;
return V_43 ;
}
return - 1 ;
}
static int T_1 F_81 ( char * V_5 )
{
V_127 = 0 ;
return 1 ;
}
void F_82 ( void )
{
if ( ! V_127 )
return;
F_44 ( L_19 ) ;
F_83 () ;
V_128 = 1 ;
F_84 ( & V_89 ) ;
}
void F_85 ( void )
{
if ( ! V_127 )
return;
F_86 ( & V_89 ) ;
V_128 = 0 ;
F_70 () ;
}
static int T_6 F_87 ( struct V_129 * V_130 ,
unsigned long V_131 , void * V_132 )
{
switch ( V_131 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
F_83 () ;
F_70 () ;
}
return V_138 ;
}
void F_83 ( void )
{
F_49 ( F_88 () ) ;
F_86 ( & V_89 ) ;
if ( V_128 )
return;
V_139 = 1 ;
V_140 = 1 ;
}
int F_89 ( void )
{
if ( F_90 ( & V_89 ) )
return 0 ;
if ( V_128 ) {
F_84 ( & V_89 ) ;
return 0 ;
}
V_139 = 1 ;
V_140 = 0 ;
return 1 ;
}
int F_91 ( void )
{
return V_139 ;
}
void F_92 ( void )
{
if ( F_93 ( V_141 ) ) {
F_94 ( V_141 , 0 ) ;
F_95 ( & V_55 ) ;
}
}
int F_96 ( int V_93 )
{
if ( F_97 ( V_93 ) )
F_92 () ;
return F_93 ( V_141 ) ;
}
void F_98 ( void )
{
if ( F_99 ( & V_55 ) )
F_100 ( V_141 , 1 ) ;
}
void F_70 ( void )
{
unsigned long V_9 ;
unsigned V_142 , V_143 ;
unsigned V_144 = 0 ;
if ( V_128 ) {
F_84 ( & V_89 ) ;
return;
}
V_140 = 0 ;
for ( ; ; ) {
F_12 ( & V_17 , V_9 ) ;
V_144 |= V_20 - V_2 ;
if ( V_19 == V_2 )
break;
V_142 = V_19 ;
V_143 = V_2 ;
V_19 = V_2 ;
F_101 ( & V_17 ) ;
F_102 () ;
F_48 ( V_142 , V_143 ) ;
F_103 () ;
F_104 ( V_9 ) ;
}
V_139 = 0 ;
if ( F_10 ( V_69 ) )
V_69 = NULL ;
F_84 ( & V_89 ) ;
F_14 ( & V_17 , V_9 ) ;
if ( V_144 )
F_98 () ;
}
void T_7 F_105 ( void )
{
if ( V_140 )
F_36 () ;
}
void F_106 ( void )
{
struct V_67 * V_48 ;
if ( V_101 ) {
if ( F_90 ( & V_89 ) != 0 )
return;
} else
F_83 () ;
V_139 = 1 ;
V_140 = 0 ;
F_40 (c)
if ( ( V_48 -> V_9 & V_70 ) && V_48 -> V_145 )
V_48 -> V_145 () ;
F_70 () ;
}
struct V_146 * F_107 ( int * V_119 )
{
struct V_67 * V_48 ;
struct V_146 * V_147 = NULL ;
F_83 () ;
F_40 (c) {
if ( ! V_48 -> V_148 )
continue;
V_147 = V_48 -> V_148 ( V_48 , V_119 ) ;
if ( V_147 )
break;
}
F_70 () ;
return V_147 ;
}
void F_108 ( struct V_67 * V_67 )
{
F_83 () ;
V_67 -> V_9 &= ~ V_70 ;
F_70 () ;
}
void F_109 ( struct V_67 * V_67 )
{
F_83 () ;
V_67 -> V_9 |= V_70 ;
F_70 () ;
}
static int T_1 F_110 ( char * V_5 )
{
V_149 = 1 ;
F_44 ( V_74 L_20 ) ;
return 0 ;
}
void F_111 ( struct V_67 * V_150 )
{
int V_43 ;
unsigned long V_9 ;
struct V_67 * V_151 = NULL ;
if ( V_76 && V_150 -> V_9 & V_152 ) {
F_40 (bcon) {
if ( ! ( V_151 -> V_9 & V_152 ) ) {
F_44 ( V_74 L_21 ,
V_150 -> V_113 , V_150 -> V_119 ) ;
return;
}
}
}
if ( V_76 && V_76 -> V_9 & V_152 )
V_151 = V_76 ;
if ( V_153 < 0 || V_151 || ! V_76 )
V_153 = V_120 ;
if ( V_150 -> V_154 )
V_150 -> V_154 () ;
if ( V_153 < 0 ) {
if ( V_150 -> V_119 < 0 )
V_150 -> V_119 = 0 ;
if ( V_150 -> V_155 == NULL ||
V_150 -> V_155 ( V_150 , NULL ) == 0 ) {
V_150 -> V_9 |= V_70 ;
if ( V_150 -> V_148 ) {
V_150 -> V_9 |= V_156 ;
V_153 = 0 ;
}
}
}
for ( V_43 = 0 ; V_43 < V_118 && V_117 [ V_43 ] . V_113 [ 0 ] ;
V_43 ++ ) {
if ( strcmp ( V_117 [ V_43 ] . V_113 , V_150 -> V_113 ) != 0 )
continue;
if ( V_150 -> V_119 >= 0 &&
V_150 -> V_119 != V_117 [ V_43 ] . V_119 )
continue;
if ( V_150 -> V_119 < 0 )
V_150 -> V_119 = V_117 [ V_43 ] . V_119 ;
#ifdef F_76
if ( V_117 [ V_43 ] . V_116 ) {
V_150 -> V_9 |= V_157 ;
F_112 ( V_150 ,
V_117 [ V_43 ] . V_119 ,
V_117 [ V_43 ] . V_115 ,
V_117 [ V_43 ] . V_116 ) ;
return;
}
#endif
if ( V_150 -> V_155 &&
V_150 -> V_155 ( V_150 , V_117 [ V_43 ] . V_115 ) != 0 )
break;
V_150 -> V_9 |= V_70 ;
V_150 -> V_119 = V_117 [ V_43 ] . V_119 ;
if ( V_43 == V_120 ) {
V_150 -> V_9 |= V_156 ;
V_153 = V_120 ;
}
break;
}
if ( ! ( V_150 -> V_9 & V_70 ) )
return;
if ( V_151 && ( ( V_150 -> V_9 & ( V_156 | V_152 ) ) == V_156 ) )
V_150 -> V_9 &= ~ V_158 ;
F_83 () ;
if ( ( V_150 -> V_9 & V_156 ) || V_76 == NULL ) {
V_150 -> V_159 = V_76 ;
V_76 = V_150 ;
if ( V_150 -> V_159 )
V_150 -> V_159 -> V_9 &= ~ V_156 ;
} else {
V_150 -> V_159 = V_76 -> V_159 ;
V_76 -> V_159 = V_150 ;
}
if ( V_150 -> V_9 & V_158 ) {
F_12 ( & V_17 , V_9 ) ;
V_19 = V_20 ;
F_14 ( & V_17 , V_9 ) ;
V_69 = V_150 ;
}
F_70 () ;
F_113 () ;
if ( V_151 &&
( ( V_150 -> V_9 & ( V_156 | V_152 ) ) == V_156 ) &&
! V_149 ) {
F_44 ( V_74 L_22 ,
V_150 -> V_113 , V_150 -> V_119 ) ;
F_40 (bcon)
if ( V_151 -> V_9 & V_152 )
F_114 ( V_151 ) ;
} else {
F_44 ( V_74 L_23 ,
( V_150 -> V_9 & V_152 ) ? L_24 : L_11 ,
V_150 -> V_113 , V_150 -> V_119 ) ;
}
}
int F_114 ( struct V_67 * V_67 )
{
struct V_67 * V_160 , * V_161 ;
int V_162 = 1 ;
#ifdef F_76
if ( V_67 -> V_9 & V_157 )
return F_115 ( V_67 ) ;
#endif
F_83 () ;
if ( V_76 == V_67 ) {
V_76 = V_67 -> V_159 ;
V_162 = 0 ;
} else if ( V_76 ) {
for ( V_160 = V_76 -> V_159 , V_161 = V_76 ;
V_160 ; V_161 = V_160 , V_160 = V_161 -> V_159 ) {
if ( V_160 == V_67 ) {
V_161 -> V_159 = V_160 -> V_159 ;
V_162 = 0 ;
break;
}
}
}
if ( V_76 != NULL && V_67 -> V_9 & V_156 )
V_76 -> V_9 |= V_156 ;
F_70 () ;
F_113 () ;
return V_162 ;
}
static int T_1 F_116 ( void )
{
struct V_67 * V_68 ;
F_40 (con) {
if ( V_68 -> V_9 & V_152 ) {
F_44 ( V_74 L_25 ,
V_68 -> V_113 , V_68 -> V_119 ) ;
F_114 ( V_68 ) ;
}
}
F_117 ( F_87 , 0 ) ;
return 0 ;
}
int F_118 ( const char * V_163 )
{
return F_119 ( & V_164 , V_163 ) ;
}
bool F_120 ( unsigned long * V_165 ,
unsigned int V_166 )
{
if ( * V_165 == 0
|| ! F_121 ( V_32 , * V_165 ,
* V_165
+ F_20 ( V_166 ) ) ) {
* V_165 = V_32 ;
return true ;
}
return false ;
}
int F_122 ( struct V_167 * V_168 )
{
unsigned long V_9 ;
int V_169 = - V_170 ;
if ( ! V_168 -> V_171 )
return - V_52 ;
F_12 ( & V_172 , V_9 ) ;
if ( ! V_168 -> V_173 ) {
V_168 -> V_173 = 1 ;
F_123 ( & V_168 -> V_174 , & V_175 ) ;
V_169 = 0 ;
}
F_14 ( & V_172 , V_9 ) ;
return V_169 ;
}
int F_124 ( struct V_167 * V_168 )
{
unsigned long V_9 ;
int V_169 = - V_52 ;
F_12 ( & V_172 , V_9 ) ;
if ( V_168 -> V_173 ) {
V_168 -> V_173 = 0 ;
F_125 ( & V_168 -> V_174 ) ;
V_169 = 0 ;
}
F_14 ( & V_172 , V_9 ) ;
F_126 () ;
return V_169 ;
}
void F_127 ( enum V_176 V_177 )
{
unsigned long V_66 ;
unsigned V_178 ;
struct V_167 * V_168 ;
const char * V_179 , * V_180 ;
unsigned long V_181 , V_182 ;
unsigned long V_9 ;
F_12 ( & V_17 , V_9 ) ;
V_66 = V_2 & V_77 ;
V_178 = V_4 ;
F_14 ( & V_17 , V_9 ) ;
if ( V_178 > V_66 ) {
V_179 = V_1 + V_3 - V_178 + V_66 ;
V_181 = V_178 - V_66 ;
V_180 = V_1 ;
V_182 = V_66 ;
} else {
V_179 = L_11 ;
V_181 = 0 ;
V_180 = V_1 + V_66 - V_178 ;
V_182 = V_178 ;
}
F_128 () ;
F_129 (dumper, &dump_list, list)
V_168 -> V_171 ( V_168 , V_177 , V_179 , V_181 , V_180 , V_182 ) ;
F_130 () ;
}
