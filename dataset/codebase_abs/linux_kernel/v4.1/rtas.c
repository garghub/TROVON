static unsigned long F_1 ( void )
{
unsigned long V_1 ;
F_2 ( V_1 ) ;
F_3 () ;
F_4 ( & V_2 . V_3 , V_1 ) ;
return V_1 ;
}
static void F_5 ( unsigned long V_1 )
{
F_6 ( & V_2 . V_3 ) ;
F_7 ( V_1 ) ;
F_8 () ;
}
static void F_9 ( unsigned char V_4 )
{
struct V_5 * args = & V_2 . args ;
unsigned long V_6 ;
if ( ! V_2 . V_7 )
return;
V_6 = F_1 () ;
args -> V_8 = F_10 ( 10 ) ;
args -> V_9 = F_10 ( 1 ) ;
args -> V_10 = F_10 ( 1 ) ;
args -> V_11 = & ( args -> args [ 1 ] ) ;
args -> args [ 0 ] = F_10 ( V_4 ) ;
F_11 ( F_12 ( args ) ) ;
F_5 ( V_6 ) ;
}
static void F_13 ( char V_4 )
{
static int V_12 = 0 ;
static int V_13 = 16 ;
if ( V_4 == '\n' ) {
while ( V_13 -- > 0 )
F_9 ( ' ' ) ;
V_13 = 16 ;
F_14 ( 500 ) ;
V_12 = 1 ;
} else {
if ( V_12 ) {
F_9 ( '\r' ) ;
F_9 ( '\n' ) ;
}
V_12 = 0 ;
if ( V_13 -- ) {
F_9 ( V_4 ) ;
F_15 ( 10000 ) ;
}
}
}
void T_1 F_16 ( void )
{
V_14 = F_13 ;
}
static void F_17 ( char V_4 )
{
int V_15 ;
if ( ! V_2 . V_7 )
return;
if ( V_4 == '\n' )
F_17 ( '\r' ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ ) {
if ( F_18 ( V_16 , 1 , 1 , NULL , V_4 ) == 0 )
break;
F_15 ( 1000 ) ;
}
}
static int F_19 ( void )
{
int V_4 ;
if ( ! V_2 . V_7 )
return - 1 ;
if ( F_18 ( V_17 , 0 , 2 , & V_4 ) )
return - 1 ;
return V_4 ;
}
static int F_20 ( void )
{
int V_4 ;
while ( ( V_4 = F_19 () ) == - 1 )
;
return V_4 ;
}
void T_1 F_21 ( void )
{
V_14 = F_17 ;
V_18 = F_20 ;
V_19 = F_19 ;
}
void F_22 ( char * V_6 , unsigned short V_20 )
{
struct V_21 * V_22 ;
int V_13 ;
const T_2 * V_23 ;
char * V_24 ;
static int V_25 , V_26 ;
static int V_27 , V_28 , V_29 ;
static const int * V_30 ;
static F_23 ( V_31 ) ;
static int V_32 ;
static int V_12 = 0 ;
if ( ! V_2 . V_7 )
return;
if ( V_27 == 0 ) {
V_27 = 0x10 ;
if ( ( V_22 = F_24 ( L_1 ) ) ) {
if ( ( V_23 = F_25 ( V_22 ,
L_2 , NULL ) ) )
V_27 = F_26 ( * V_23 ) ;
if ( ( V_23 = F_25 ( V_22 ,
L_3 , NULL ) ) )
V_29 = F_26 ( * V_23 ) ;
if ( ( V_23 = F_25 ( V_22 ,
L_4 , NULL ) ) )
V_28 = F_26 ( * V_23 ) ;
V_30 = F_25 ( V_22 ,
L_5 , NULL ) ;
F_27 ( V_22 ) ;
}
V_25 = F_28 ( L_6 ) ;
V_26 = F_28 ( L_7 ) ;
}
if ( V_25 == V_33 ) {
if ( V_26 != V_33 )
F_18 ( V_26 , 3 , 1 , NULL , 6 , 0 , V_20 ) ;
return;
}
F_29 ( & V_31 ) ;
if ( V_12 ) {
F_18 ( V_25 , 1 , 1 , NULL , '\r' ) ;
F_18 ( V_25 , 1 , 1 , NULL , '\n' ) ;
V_12 = 0 ;
} else {
V_32 = 0 ;
if ( V_29 )
F_18 ( V_25 , 1 , 1 , NULL ,
( char ) V_29 ) ;
else
F_18 ( V_25 , 1 , 1 , NULL , '\r' ) ;
}
if ( V_30 )
V_13 = V_30 [ V_32 ] ;
else
V_13 = V_27 ;
V_24 = V_6 ;
while ( * V_24 ) {
if ( * V_24 == '\n' || * V_24 == '\r' ) {
if ( * V_24 == '\n' && ! V_24 [ 1 ] ) {
V_12 = 1 ;
V_32 ++ ;
if ( V_32 > V_28 - 1 )
V_32 = V_28 - 1 ;
F_30 ( & V_31 ) ;
return;
}
if ( * V_24 == '\n' ) {
F_18 ( V_25 , 1 , 1 , NULL , '\r' ) ;
F_18 ( V_25 , 1 , 1 , NULL , '\n' ) ;
} else {
F_18 ( V_25 , 1 , 1 , NULL , * V_24 ) ;
}
if ( V_30 )
V_13 = V_30 [ V_32 ] ;
else
V_13 = V_27 ;
} else {
V_13 -- ;
F_18 ( V_25 , 1 , 1 , NULL , * V_24 ) ;
}
V_24 ++ ;
if ( V_13 <= 0 )
while ( ( * V_24 != 0 ) && ( * V_24 != '\n' ) && ( * V_24 != '\r' ) )
V_24 ++ ;
}
F_30 ( & V_31 ) ;
}
int F_28 ( const char * V_34 )
{
const T_2 * V_35 ;
if ( V_2 . V_36 == NULL )
return V_33 ;
V_35 = F_25 ( V_2 . V_36 , V_34 , NULL ) ;
return V_35 ? F_26 ( * V_35 ) : V_33 ;
}
int F_31 ( const char * V_34 )
{
return F_28 ( V_34 ) != V_33 ;
}
int F_32 ( void )
{
static int V_37 ;
if ( V_37 )
return V_37 ;
V_37 = F_28 ( L_8 ) ;
if ( ( V_37 == V_33 ) ||
( V_37 > V_38 ) ) {
F_33 ( V_39 L_9 ,
V_37 ) ;
V_37 = V_38 ;
}
return V_37 ;
}
static char * F_34 ( char * V_40 )
{
struct V_5 V_41 , V_42 ;
T_3 V_43 ;
char * V_44 = NULL ;
if ( V_45 == - 1 )
return NULL ;
V_43 = F_32 () ;
V_41 . V_8 = F_10 ( V_45 ) ;
V_41 . V_9 = F_10 ( 2 ) ;
V_41 . V_10 = F_10 ( 1 ) ;
V_41 . args [ 0 ] = F_10 ( F_12 ( V_46 ) ) ;
V_41 . args [ 1 ] = F_10 ( V_43 ) ;
V_41 . args [ 2 ] = 0 ;
V_42 = V_2 . args ;
V_2 . args = V_41 ;
F_11 ( F_12 ( & V_2 . args ) ) ;
V_41 = V_2 . args ;
V_2 . args = V_42 ;
if ( F_35 ( V_41 . args [ 2 ] == 0 ) ) {
if ( V_40 ) {
V_44 = V_40 ;
} else {
V_44 = V_46 ;
if ( F_36 () )
V_44 = F_37 ( V_38 , V_47 ) ;
}
if ( V_44 )
memcpy ( V_44 , V_46 , V_38 ) ;
}
return V_44 ;
}
int F_18 ( int V_8 , int V_9 , int V_10 , int * V_48 , ... )
{
T_4 V_49 ;
int V_50 ;
unsigned long V_6 ;
struct V_5 * V_5 ;
char * V_51 = NULL ;
int V_52 ;
if ( ! V_2 . V_53 || V_8 == V_33 )
return - 1 ;
V_6 = F_1 () ;
V_5 = & V_2 . args ;
V_5 -> V_8 = F_10 ( V_8 ) ;
V_5 -> V_9 = F_10 ( V_9 ) ;
V_5 -> V_10 = F_10 ( V_10 ) ;
V_5 -> V_11 = & ( V_5 -> args [ V_9 ] ) ;
va_start ( V_49 , V_48 ) ;
for ( V_50 = 0 ; V_50 < V_9 ; ++ V_50 )
V_5 -> args [ V_50 ] = F_10 ( va_arg ( V_49 , V_54 ) ) ;
va_end ( V_49 ) ;
for ( V_50 = 0 ; V_50 < V_10 ; ++ V_50 )
V_5 -> V_11 [ V_50 ] = 0 ;
F_11 ( F_12 ( V_5 ) ) ;
if ( F_26 ( V_5 -> V_11 [ 0 ] ) == - 1 )
V_51 = F_34 ( NULL ) ;
if ( V_10 > 1 && V_48 != NULL )
for ( V_50 = 0 ; V_50 < V_10 - 1 ; ++ V_50 )
V_48 [ V_50 ] = F_26 ( V_5 -> V_11 [ V_50 + 1 ] ) ;
V_52 = ( V_10 > 0 ) ? F_26 ( V_5 -> V_11 [ 0 ] ) : 0 ;
F_5 ( V_6 ) ;
if ( V_51 ) {
F_38 ( V_51 , V_55 , 0 ) ;
if ( F_36 () )
F_39 ( V_51 ) ;
}
return V_52 ;
}
unsigned int F_40 ( int V_56 )
{
int V_57 ;
unsigned int V_58 = 0 ;
if ( V_56 == V_59 ) {
V_58 = 1 ;
} else if ( V_56 >= 9900 && V_56 <= 9905 ) {
V_57 = V_56 - 9900 ;
for ( V_58 = 1 ; V_57 > 0 ; V_57 -- )
V_58 *= 10 ;
}
return V_58 ;
}
unsigned int F_41 ( int V_56 )
{
unsigned int V_58 ;
F_42 () ;
V_58 = F_40 ( V_56 ) ;
if ( V_58 && F_43 () )
F_44 ( V_58 ) ;
return V_58 ;
}
static int F_45 ( int V_60 )
{
int V_61 ;
switch ( V_60 ) {
case - 1 :
V_61 = - V_62 ;
break;
case - 3 :
V_61 = - V_63 ;
break;
case - 9000 :
V_61 = - V_64 ;
break;
case - 9001 :
V_61 = - V_65 ;
break;
case - 9002 :
V_61 = - V_66 ;
break;
default:
F_33 ( V_67 L_10 ,
V_68 , V_60 ) ;
V_61 = - V_69 ;
break;
}
return V_61 ;
}
int F_46 ( int V_70 , int * V_71 )
{
int V_8 = F_28 ( L_11 ) ;
int V_61 ;
if ( V_8 == V_33 )
return - V_72 ;
while ( ( V_61 = F_18 ( V_8 , 1 , 2 , V_71 , V_70 ) ) == V_59 )
F_15 ( 1 ) ;
if ( V_61 < 0 )
return F_45 ( V_61 ) ;
return V_61 ;
}
int F_47 ( int V_70 , int V_71 , int * V_73 )
{
int V_8 = F_28 ( L_12 ) ;
int V_61 ;
if ( V_8 == V_33 )
return - V_72 ;
do {
V_61 = F_18 ( V_8 , 2 , 2 , V_73 , V_70 , V_71 ) ;
} while ( F_41 ( V_61 ) );
if ( V_61 < 0 )
return F_45 ( V_61 ) ;
return V_61 ;
}
int F_48 ( int V_74 , int V_75 , int * V_76 )
{
int V_8 = F_28 ( L_13 ) ;
int V_61 ;
if ( V_8 == V_33 )
return - V_72 ;
do {
V_61 = F_18 ( V_8 , 2 , 2 , V_76 , V_74 , V_75 ) ;
} while ( F_41 ( V_61 ) );
if ( V_61 < 0 )
return F_45 ( V_61 ) ;
return V_61 ;
}
bool F_49 ( int V_8 , int * V_77 )
{
int V_78 , V_79 , V_50 ;
const struct V_80 {
T_2 V_8 ;
T_2 V_77 ;
} * V_81 ;
V_81 = F_25 ( V_2 . V_36 , L_14 , & V_78 ) ;
if ( ! V_81 )
return false ;
V_79 = V_78 / sizeof( struct V_80 ) ;
for ( V_50 = 0 ; V_50 < V_79 ; V_50 ++ ) {
if ( F_50 ( V_81 [ V_50 ] . V_8 ) != V_8 )
continue;
if ( V_77 )
* V_77 = F_50 ( V_81 [ V_50 ] . V_77 ) ;
return true ;
}
return false ;
}
int F_51 ( int V_82 , int V_75 , int V_83 )
{
int V_8 = F_28 ( L_7 ) ;
int V_61 ;
if ( V_8 == V_33 )
return - V_72 ;
do {
V_61 = F_18 ( V_8 , 3 , 1 , NULL , V_82 , V_75 , V_83 ) ;
} while ( F_41 ( V_61 ) );
if ( V_61 < 0 )
return F_45 ( V_61 ) ;
return V_61 ;
}
int F_52 ( int V_82 , int V_75 , int V_83 )
{
int V_61 ;
int V_8 = F_28 ( L_7 ) ;
if ( V_8 == V_33 )
return - V_72 ;
V_61 = F_18 ( V_8 , 3 , 1 , NULL , V_82 , V_75 , V_83 ) ;
F_53 ( V_61 == - 2 || ( V_61 >= 9900 && V_61 <= 9905 ) ) ;
if ( V_61 < 0 )
return F_45 ( V_61 ) ;
return V_61 ;
}
void F_54 ( char * V_84 )
{
if ( V_85 )
V_85 ( V_86 ) ;
F_33 ( L_15 ,
F_18 ( F_28 ( L_16 ) , 0 , 1 , NULL ) ) ;
for (; ; ) ;
}
void F_55 ( void )
{
if ( V_85 )
V_85 ( V_87 ) ;
F_33 ( L_17 ,
F_18 ( F_28 ( L_18 ) , 2 , 1 , NULL , - 1 , - 1 ) ) ;
for (; ; ) ;
}
void F_56 ( void )
{
if ( V_85 )
V_85 ( V_88 ) ;
F_33 ( L_17 ,
F_18 ( F_28 ( L_18 ) , 2 , 1 , NULL , - 1 , - 1 ) ) ;
for (; ; ) ;
}
void F_57 ( char * V_89 )
{
int V_56 ;
if ( V_33 == F_28 ( L_19 ) ||
V_33 == F_28 ( L_20 ) )
return;
snprintf ( V_90 , 2048 , L_21 , V_89 ) ;
do {
V_56 = F_18 ( F_28 ( L_19 ) , 1 , 1 , NULL ,
F_12 ( V_90 ) ) ;
} while ( F_41 ( V_56 ) );
if ( V_56 != 0 )
F_33 ( V_91 L_22 , V_56 ) ;
}
static int F_58 ( struct V_92 * V_93 , int V_94 )
{
T_5 V_95 = V_96 ;
int V_61 = V_97 ;
int V_98 ;
F_59 ( V_99 ) ;
F_33 ( V_100 L_23 , F_60 () ) ;
while ( V_61 == V_97 && ! F_61 ( & V_93 -> V_101 ) &&
! F_61 ( & V_93 -> error ) )
V_61 = F_18 ( V_93 -> V_8 , 0 , 1 , NULL ) ;
if ( V_61 || F_61 ( & V_93 -> error ) ) {
F_33 ( V_100 L_24 , V_61 ) ;
F_59 ( V_95 ) ;
}
if ( F_61 ( & V_93 -> error ) )
V_61 = F_61 ( & V_93 -> error ) ;
F_62 ( & V_93 -> error , V_61 ) ;
F_63 () ;
if ( V_94 ) {
F_62 ( & V_93 -> V_101 , 1 ) ;
F_64 (cpu)
F_65 ( V_102 , F_66 ( V_98 ) ) ;
}
if ( F_67 ( & V_93 -> V_103 ) == 0 )
F_68 ( V_93 -> F_68 ) ;
return V_61 ;
}
int F_69 ( struct V_92 * V_93 )
{
F_70 ( & V_93 -> V_103 ) ;
return F_58 ( V_93 , 0 ) ;
}
static int F_71 ( struct V_92 * V_93 , int V_94 )
{
long V_61 = V_104 ;
unsigned long V_105 ;
int V_98 ;
F_70 ( & V_93 -> V_103 ) ;
V_105 = F_72 () ;
F_73 ( V_105 & ~ ( V_106 ) ) ;
while ( V_61 == V_104 && ! F_61 ( & V_93 -> V_101 ) && ! F_61 ( & V_93 -> error ) )
V_61 = F_65 ( V_107 ) ;
F_73 ( V_105 ) ;
if ( V_61 == V_104 ) {
goto V_108;
} else if ( V_61 == V_109 ) {
return F_58 ( V_93 , V_94 ) ;
} else {
F_33 ( V_67 L_25 ,
F_60 () , V_61 ) ;
F_62 ( & V_93 -> error , V_61 ) ;
}
if ( V_94 ) {
F_62 ( & V_93 -> V_101 , 1 ) ;
F_64 (cpu)
F_65 ( V_102 , F_66 ( V_98 ) ) ;
}
V_108:
if ( F_67 ( & V_93 -> V_103 ) == 0 )
F_68 ( V_93 -> F_68 ) ;
return V_61 ;
}
int F_74 ( struct V_92 * V_93 )
{
return F_71 ( V_93 , 0 ) ;
}
static void F_75 ( void * V_110 )
{
F_71 ( (struct V_92 * ) V_110 , 1 ) ;
}
static int F_76 ( enum V_111 V_76 ,
T_6 V_112 )
{
if ( ! F_77 ( V_112 ) ) {
F_78 ( V_112 ) ;
return - V_63 ;
} else
return 0 ;
}
static int F_76 ( enum V_111 V_76 ,
T_6 V_112 )
{
int V_98 ;
int V_113 = 0 ;
int V_52 = 0 ;
if ( F_77 ( V_112 ) )
return 0 ;
F_79 (cpu, cpus) {
switch ( V_76 ) {
case V_114 :
V_113 = F_80 ( V_98 ) ;
break;
case V_115 :
V_113 = F_81 ( V_98 ) ;
break;
}
if ( V_113 ) {
F_82 ( L_26 ,
V_68 ,
( ( V_76 == V_115 ) ? L_27 : L_28 ) ,
V_98 , V_113 ) ;
if ( ! V_52 )
V_52 = V_113 ;
if ( V_76 == V_115 ) {
F_83 ( V_112 , V_112 , V_98 ) ;
F_84 ( V_112 , V_112 , V_98 ) ;
break;
} else {
F_85 ( V_98 , V_112 ) ;
}
}
}
return V_52 ;
}
int F_86 ( T_6 V_112 )
{
int V_52 ;
V_52 = F_76 ( V_115 , V_112 ) ;
if ( V_52 ) {
T_6 V_116 ;
if ( ! F_87 ( & V_116 , V_117 ) )
return V_52 ;
F_88 ( V_116 , V_112 ) ;
F_89 ( V_116 ) ;
F_90 ( V_116 ) ;
}
return V_52 ;
}
int F_89 ( T_6 V_112 )
{
return F_76 ( V_114 , V_112 ) ;
}
int F_91 ( T_7 V_118 )
{
long V_76 ;
long V_61 ;
unsigned long V_119 [ V_120 ] ;
struct V_92 V_93 ;
F_92 ( V_101 ) ;
T_6 V_121 ;
int V_113 ;
if ( ! F_31 ( L_29 ) )
return - V_122 ;
V_61 = F_93 ( V_123 , V_119 , V_118 ) ;
V_76 = V_119 [ 0 ] ;
if ( V_61 ) {
F_33 ( V_67 L_30 , V_61 ) ;
return V_61 ;
} else if ( V_76 == V_124 ) {
return - V_125 ;
} else if ( V_76 != V_126 ) {
F_33 ( V_67 L_31 ,
V_76 ) ;
return - V_62 ;
}
if ( ! F_87 ( & V_121 , V_117 ) )
return - V_127 ;
F_62 ( & V_93 . V_103 , 0 ) ;
F_62 ( & V_93 . V_101 , 0 ) ;
F_62 ( & V_93 . error , 0 ) ;
V_93 . V_8 = F_28 ( L_29 ) ;
V_93 . F_68 = & V_101 ;
F_94 ( V_121 , V_128 , V_129 ) ;
V_113 = F_86 ( V_121 ) ;
if ( V_113 ) {
F_95 ( L_32 , V_68 ) ;
F_62 ( & V_93 . error , V_113 ) ;
goto V_108;
}
F_96 () ;
if ( F_97 ( F_75 , & V_93 , 0 ) )
F_62 ( & V_93 . error , - V_63 ) ;
F_98 ( & V_101 ) ;
if ( F_61 ( & V_93 . error ) != 0 )
F_33 ( V_67 L_33 ) ;
F_99 () ;
V_113 = F_89 ( V_121 ) ;
if ( V_113 )
F_100 ( L_34 ,
V_68 ) ;
V_108:
F_90 ( V_121 ) ;
return F_61 ( & V_93 . error ) ;
}
int F_91 ( T_7 V_118 )
{
return - V_122 ;
}
struct V_130 * F_101 ( struct V_131 * log ,
T_8 V_132 )
{
struct V_133 * V_134 =
(struct V_133 * ) log -> V_135 ;
struct V_130 * V_136 ;
unsigned char * V_23 , * V_137 ;
T_9 V_138 = F_102 ( log ) ;
T_10 V_139 = F_103 ( V_134 ) ;
T_9 V_140 = F_104 ( V_134 ) ;
if ( V_138 < sizeof( struct V_133 ) ||
V_139 != V_141 ||
V_140 != V_142 )
return NULL ;
V_137 = log -> V_135 + V_138 ;
V_23 = V_134 -> V_143 ;
while ( V_23 < V_137 ) {
V_136 = (struct V_130 * ) V_23 ;
if ( F_105 ( V_136 ) == V_132 )
return V_136 ;
V_23 += F_106 ( V_136 ) ;
}
return NULL ;
}
T_11 int F_107 ( struct V_5 T_12 * V_144 )
{
struct V_5 args ;
unsigned long V_1 ;
char * V_51 , * V_145 = NULL ;
int V_9 , V_10 , V_8 ;
if ( ! F_108 ( V_146 ) )
return - V_147 ;
if ( F_109 ( & args , V_144 , 3 * sizeof( T_3 ) ) != 0 )
return - V_64 ;
V_9 = F_26 ( args . V_9 ) ;
V_10 = F_26 ( args . V_10 ) ;
V_8 = F_26 ( args . V_8 ) ;
if ( V_9 > F_110 ( args . args )
|| V_10 > F_110 ( args . args )
|| V_9 + V_10 > F_110 ( args . args ) )
return - V_63 ;
if ( F_109 ( args . args , V_144 -> args ,
V_9 * sizeof( V_148 ) ) != 0 )
return - V_64 ;
if ( V_8 == V_33 )
return - V_63 ;
args . V_11 = & args . args [ V_9 ] ;
memset ( args . V_11 , 0 , V_10 * sizeof( V_148 ) ) ;
if ( V_8 == V_149 ) {
int V_61 = 0 ;
T_7 V_118 = ( ( T_7 ) F_26 ( args . args [ 0 ] ) << 32 )
| F_26 ( args . args [ 1 ] ) ;
V_61 = F_91 ( V_118 ) ;
if ( V_61 == - V_125 )
args . V_11 [ 0 ] = F_10 ( V_150 ) ;
else if ( V_61 == - V_62 )
args . V_11 [ 0 ] = F_10 ( - 1 ) ;
else if ( V_61 )
return V_61 ;
goto V_151;
}
V_51 = F_111 () ;
V_1 = F_1 () ;
V_2 . args = args ;
F_11 ( F_12 ( & V_2 . args ) ) ;
args = V_2 . args ;
if ( F_26 ( args . V_11 [ 0 ] ) == - 1 )
V_145 = F_34 ( V_51 ) ;
F_5 ( V_1 ) ;
if ( V_51 ) {
if ( V_145 )
F_38 ( V_145 , V_55 , 0 ) ;
F_39 ( V_51 ) ;
}
V_151:
if ( F_112 ( V_144 -> args + V_9 ,
args . args + V_9 ,
V_10 * sizeof( V_148 ) ) != 0 )
return - V_64 ;
return 0 ;
}
void T_1 F_113 ( void )
{
unsigned long V_152 = V_153 ;
V_2 . V_36 = F_114 ( NULL , L_35 ) ;
if ( V_2 . V_36 ) {
const T_2 * V_154 , * V_155 , * V_156 ;
V_154 = F_25 ( V_2 . V_36 , L_36 , NULL ) ;
V_156 = F_25 ( V_2 . V_36 , L_37 , NULL ) ;
if ( V_154 != NULL && V_156 != NULL ) {
V_2 . V_7 = F_50 ( * V_154 ) ;
V_2 . V_157 = F_50 ( * V_156 ) ;
V_155 = F_25 ( V_2 . V_36 ,
L_38 , NULL ) ;
if ( V_155 == NULL )
V_2 . V_53 = V_2 . V_7 ;
else
V_2 . V_53 = F_50 ( * V_155 ) ;
} else
V_2 . V_36 = NULL ;
}
if ( ! V_2 . V_36 )
return;
#ifdef F_115
if ( F_116 ( V_158 ) && F_117 ( V_159 ) ) {
V_152 = F_118 ( V_160 , V_153 ) ;
V_149 = F_28 ( L_29 ) ;
}
#endif
V_161 = F_119 ( V_162 , V_163 , V_152 ) ;
#ifdef F_120
V_45 = F_28 ( L_39 ) ;
#endif
}
int T_1 F_121 ( unsigned long V_164 ,
const char * V_165 , int V_166 , void * V_93 )
{
const T_3 * V_154 , * V_155 , * V_156 ;
if ( V_166 != 1 || strcmp ( V_165 , L_35 ) != 0 )
return 0 ;
V_154 = F_122 ( V_164 , L_36 , NULL ) ;
V_155 = F_122 ( V_164 , L_38 , NULL ) ;
V_156 = F_122 ( V_164 , L_37 , NULL ) ;
if ( V_154 && V_155 && V_156 ) {
V_2 . V_7 = * V_154 ;
V_2 . V_53 = * V_155 ;
V_2 . V_157 = * V_156 ;
}
#ifdef F_123
V_154 = F_122 ( V_164 , L_40 , NULL ) ;
if ( V_154 )
V_16 = * V_154 ;
V_154 = F_122 ( V_164 , L_41 , NULL ) ;
if ( V_154 )
V_17 = * V_154 ;
if ( V_16 != V_33 &&
V_17 != V_33 )
F_21 () ;
#endif
return 1 ;
}
void F_124 ( void )
{
unsigned long V_1 ;
F_2 ( V_1 ) ;
F_125 () ;
F_126 ( & V_167 ) ;
F_18 ( F_28 ( L_42 ) , 0 , 1 , NULL ) ;
V_168 = F_127 () ;
F_6 ( & V_167 ) ;
while ( V_168 )
F_128 () ;
F_18 ( F_28 ( L_43 ) , 0 , 1 , NULL ) ;
F_7 ( V_1 ) ;
}
void F_129 ( void )
{
while ( ! V_168 )
F_128 () ;
F_126 ( & V_167 ) ;
F_130 ( V_168 >> 32 , V_168 & 0xffffffff ) ;
V_168 = 0 ;
F_6 ( & V_167 ) ;
}
