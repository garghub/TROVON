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
if ( V_47 )
V_44 = F_36 ( V_38 , V_48 ) ;
}
if ( V_44 )
memcpy ( V_44 , V_46 , V_38 ) ;
}
return V_44 ;
}
int F_18 ( int V_8 , int V_9 , int V_10 , int * V_49 , ... )
{
T_4 V_50 ;
int V_51 ;
unsigned long V_6 ;
struct V_5 * V_5 ;
char * V_52 = NULL ;
int V_53 ;
if ( ! V_2 . V_54 || V_8 == V_33 )
return - 1 ;
V_6 = F_1 () ;
V_5 = & V_2 . args ;
V_5 -> V_8 = F_10 ( V_8 ) ;
V_5 -> V_9 = F_10 ( V_9 ) ;
V_5 -> V_10 = F_10 ( V_10 ) ;
V_5 -> V_11 = & ( V_5 -> args [ V_9 ] ) ;
va_start ( V_50 , V_49 ) ;
for ( V_51 = 0 ; V_51 < V_9 ; ++ V_51 )
V_5 -> args [ V_51 ] = F_10 ( va_arg ( V_50 , V_55 ) ) ;
va_end ( V_50 ) ;
for ( V_51 = 0 ; V_51 < V_10 ; ++ V_51 )
V_5 -> V_11 [ V_51 ] = 0 ;
F_11 ( F_12 ( V_5 ) ) ;
if ( F_26 ( V_5 -> V_11 [ 0 ] ) == - 1 )
V_52 = F_34 ( NULL ) ;
if ( V_10 > 1 && V_49 != NULL )
for ( V_51 = 0 ; V_51 < V_10 - 1 ; ++ V_51 )
V_49 [ V_51 ] = F_26 ( V_5 -> V_11 [ V_51 + 1 ] ) ;
V_53 = ( V_10 > 0 ) ? F_26 ( V_5 -> V_11 [ 0 ] ) : 0 ;
F_5 ( V_6 ) ;
if ( V_52 ) {
F_37 ( V_52 , V_56 , 0 ) ;
if ( V_47 )
F_38 ( V_52 ) ;
}
return V_53 ;
}
unsigned int F_39 ( int V_57 )
{
int V_58 ;
unsigned int V_59 = 0 ;
if ( V_57 == V_60 ) {
V_59 = 1 ;
} else if ( V_57 >= 9900 && V_57 <= 9905 ) {
V_58 = V_57 - 9900 ;
for ( V_59 = 1 ; V_58 > 0 ; V_58 -- )
V_59 *= 10 ;
}
return V_59 ;
}
unsigned int F_40 ( int V_57 )
{
unsigned int V_59 ;
F_41 () ;
V_59 = F_39 ( V_57 ) ;
if ( V_59 && F_42 () )
F_43 ( V_59 ) ;
return V_59 ;
}
static int F_44 ( int V_61 )
{
int V_62 ;
switch ( V_61 ) {
case - 1 :
V_62 = - V_63 ;
break;
case - 3 :
V_62 = - V_64 ;
break;
case - 9000 :
V_62 = - V_65 ;
break;
case - 9001 :
V_62 = - V_66 ;
break;
case - 9002 :
V_62 = - V_67 ;
break;
default:
F_33 ( V_68 L_10 ,
V_69 , V_61 ) ;
V_62 = - V_70 ;
break;
}
return V_62 ;
}
int F_45 ( int V_71 , int * V_72 )
{
int V_8 = F_28 ( L_11 ) ;
int V_62 ;
if ( V_8 == V_33 )
return - V_73 ;
while ( ( V_62 = F_18 ( V_8 , 1 , 2 , V_72 , V_71 ) ) == V_60 )
F_15 ( 1 ) ;
if ( V_62 < 0 )
return F_44 ( V_62 ) ;
return V_62 ;
}
int F_46 ( int V_71 , int V_72 , int * V_74 )
{
int V_8 = F_28 ( L_12 ) ;
int V_62 ;
if ( V_8 == V_33 )
return - V_73 ;
do {
V_62 = F_18 ( V_8 , 2 , 2 , V_74 , V_71 , V_72 ) ;
} while ( F_40 ( V_62 ) );
if ( V_62 < 0 )
return F_44 ( V_62 ) ;
return V_62 ;
}
int F_47 ( int V_75 , int V_76 , int * V_77 )
{
int V_8 = F_28 ( L_13 ) ;
int V_62 ;
if ( V_8 == V_33 )
return - V_73 ;
do {
V_62 = F_18 ( V_8 , 2 , 2 , V_77 , V_75 , V_76 ) ;
} while ( F_40 ( V_62 ) );
if ( V_62 < 0 )
return F_44 ( V_62 ) ;
return V_62 ;
}
bool F_48 ( int V_8 , int * V_78 )
{
int V_79 , V_80 , V_51 ;
const struct V_81 {
T_2 V_8 ;
T_2 V_78 ;
} * V_82 ;
V_82 = F_25 ( V_2 . V_36 , L_14 , & V_79 ) ;
if ( ! V_82 )
return false ;
V_80 = V_79 / sizeof( struct V_81 ) ;
for ( V_51 = 0 ; V_51 < V_80 ; V_51 ++ ) {
if ( F_49 ( V_82 [ V_51 ] . V_8 ) != V_8 )
continue;
if ( V_78 )
* V_78 = F_49 ( V_82 [ V_51 ] . V_78 ) ;
return true ;
}
return false ;
}
int F_50 ( int V_83 , int V_76 , int V_84 )
{
int V_8 = F_28 ( L_7 ) ;
int V_62 ;
if ( V_8 == V_33 )
return - V_73 ;
do {
V_62 = F_18 ( V_8 , 3 , 1 , NULL , V_83 , V_76 , V_84 ) ;
} while ( F_40 ( V_62 ) );
if ( V_62 < 0 )
return F_44 ( V_62 ) ;
return V_62 ;
}
int F_51 ( int V_83 , int V_76 , int V_84 )
{
int V_62 ;
int V_8 = F_28 ( L_7 ) ;
if ( V_8 == V_33 )
return - V_73 ;
V_62 = F_18 ( V_8 , 3 , 1 , NULL , V_83 , V_76 , V_84 ) ;
F_52 ( V_62 == - 2 || ( V_62 >= 9900 && V_62 <= 9905 ) ) ;
if ( V_62 < 0 )
return F_44 ( V_62 ) ;
return V_62 ;
}
void F_53 ( char * V_85 )
{
if ( V_86 )
V_86 ( V_87 ) ;
F_33 ( L_15 ,
F_18 ( F_28 ( L_16 ) , 0 , 1 , NULL ) ) ;
for (; ; ) ;
}
void F_54 ( void )
{
if ( V_86 )
V_86 ( V_88 ) ;
F_33 ( L_17 ,
F_18 ( F_28 ( L_18 ) , 2 , 1 , NULL , - 1 , - 1 ) ) ;
for (; ; ) ;
}
void F_55 ( void )
{
if ( V_86 )
V_86 ( V_89 ) ;
F_33 ( L_17 ,
F_18 ( F_28 ( L_18 ) , 2 , 1 , NULL , - 1 , - 1 ) ) ;
for (; ; ) ;
}
void F_56 ( char * V_90 )
{
int V_57 ;
if ( V_33 == F_28 ( L_19 ) ||
V_33 == F_28 ( L_20 ) )
return;
snprintf ( V_91 , 2048 , L_21 , V_90 ) ;
do {
V_57 = F_18 ( F_28 ( L_19 ) , 1 , 1 , NULL ,
F_12 ( V_91 ) ) ;
} while ( F_40 ( V_57 ) );
if ( V_57 != 0 )
F_33 ( V_92 L_22 , V_57 ) ;
}
static int F_57 ( struct V_93 * V_94 , int V_95 )
{
T_5 V_96 = V_97 ;
int V_62 = V_98 ;
int V_99 ;
F_58 ( V_100 ) ;
F_33 ( V_101 L_23 , F_59 () ) ;
while ( V_62 == V_98 && ! F_60 ( & V_94 -> V_102 ) &&
! F_60 ( & V_94 -> error ) )
V_62 = F_18 ( V_94 -> V_8 , 0 , 1 , NULL ) ;
if ( V_62 || F_60 ( & V_94 -> error ) ) {
F_33 ( V_101 L_24 , V_62 ) ;
F_58 ( V_96 ) ;
}
if ( F_60 ( & V_94 -> error ) )
V_62 = F_60 ( & V_94 -> error ) ;
F_61 ( & V_94 -> error , V_62 ) ;
F_62 () ;
if ( V_95 ) {
F_61 ( & V_94 -> V_102 , 1 ) ;
F_63 (cpu)
F_64 ( V_103 , F_65 ( V_99 ) ) ;
}
if ( F_66 ( & V_94 -> V_104 ) == 0 )
F_67 ( V_94 -> F_67 ) ;
return V_62 ;
}
int F_68 ( struct V_93 * V_94 )
{
F_69 ( & V_94 -> V_104 ) ;
return F_57 ( V_94 , 0 ) ;
}
static int F_70 ( struct V_93 * V_94 , int V_95 )
{
long V_62 = V_105 ;
unsigned long V_106 ;
int V_99 ;
F_69 ( & V_94 -> V_104 ) ;
V_106 = F_71 () ;
F_72 ( V_106 & ~ ( V_107 ) ) ;
while ( V_62 == V_105 && ! F_60 ( & V_94 -> V_102 ) && ! F_60 ( & V_94 -> error ) )
V_62 = F_64 ( V_108 ) ;
F_72 ( V_106 ) ;
if ( V_62 == V_105 ) {
goto V_109;
} else if ( V_62 == V_110 ) {
return F_57 ( V_94 , V_95 ) ;
} else {
F_33 ( V_68 L_25 ,
F_59 () , V_62 ) ;
F_61 ( & V_94 -> error , V_62 ) ;
}
if ( V_95 ) {
F_61 ( & V_94 -> V_102 , 1 ) ;
F_63 (cpu)
F_64 ( V_103 , F_65 ( V_99 ) ) ;
}
V_109:
if ( F_66 ( & V_94 -> V_104 ) == 0 )
F_67 ( V_94 -> F_67 ) ;
return V_62 ;
}
int F_73 ( struct V_93 * V_94 )
{
return F_70 ( V_94 , 0 ) ;
}
static void F_74 ( void * V_111 )
{
F_70 ( (struct V_93 * ) V_111 , 1 ) ;
}
static int F_75 ( enum V_112 V_77 ,
T_6 V_113 )
{
if ( ! F_76 ( V_113 ) ) {
F_77 ( V_113 ) ;
return - V_64 ;
} else
return 0 ;
}
static int F_75 ( enum V_112 V_77 ,
T_6 V_113 )
{
int V_99 ;
int V_114 = 0 ;
int V_53 = 0 ;
if ( F_76 ( V_113 ) )
return 0 ;
F_78 (cpu, cpus) {
switch ( V_77 ) {
case V_115 :
V_114 = F_79 ( V_99 ) ;
break;
case V_116 :
V_114 = F_80 ( V_99 ) ;
break;
}
if ( V_114 ) {
F_81 ( L_26 ,
V_69 ,
( ( V_77 == V_116 ) ? L_27 : L_28 ) ,
V_99 , V_114 ) ;
if ( ! V_53 )
V_53 = V_114 ;
if ( V_77 == V_116 ) {
F_82 ( V_113 , V_113 , V_99 ) ;
F_83 ( V_113 , V_113 , V_99 ) ;
break;
} else {
F_84 ( V_99 , V_113 ) ;
}
}
}
return V_53 ;
}
int F_85 ( T_6 V_113 )
{
int V_53 ;
V_53 = F_75 ( V_116 , V_113 ) ;
if ( V_53 ) {
T_6 V_117 ;
if ( ! F_86 ( & V_117 , V_118 ) )
return V_53 ;
F_87 ( V_117 , V_113 ) ;
F_88 ( V_117 ) ;
F_89 ( V_117 ) ;
}
return V_53 ;
}
int F_88 ( T_6 V_113 )
{
return F_75 ( V_115 , V_113 ) ;
}
int F_90 ( T_7 V_119 , int * V_120 )
{
long V_77 ;
long V_62 ;
unsigned long V_121 [ V_122 ] ;
struct V_93 V_94 ;
F_91 ( V_102 ) ;
T_6 V_123 ;
int V_114 ;
if ( ! F_31 ( L_29 ) )
return - V_124 ;
V_62 = F_92 ( V_125 , V_121 , V_119 ) ;
V_77 = V_121 [ 0 ] ;
if ( V_62 ) {
F_33 ( V_68 L_30 , V_62 ) ;
return V_62 ;
} else if ( V_77 == V_126 ) {
* V_120 = V_127 ;
return 0 ;
} else if ( V_77 != V_128 ) {
F_33 ( V_68 L_31 ,
V_77 ) ;
* V_120 = - 1 ;
return 0 ;
}
if ( ! F_86 ( & V_123 , V_118 ) )
return - V_129 ;
F_61 ( & V_94 . V_104 , 0 ) ;
F_61 ( & V_94 . V_102 , 0 ) ;
F_61 ( & V_94 . error , 0 ) ;
V_94 . V_8 = F_28 ( L_29 ) ;
V_94 . F_67 = & V_102 ;
F_93 ( V_123 , V_130 , V_131 ) ;
V_114 = F_85 ( V_123 ) ;
if ( V_114 ) {
F_94 ( L_32 , V_69 ) ;
F_61 ( & V_94 . error , V_114 ) ;
goto V_109;
}
F_95 () ;
if ( F_96 ( F_74 , & V_94 , 0 ) )
F_61 ( & V_94 . error , - V_64 ) ;
F_97 ( & V_102 ) ;
if ( F_60 ( & V_94 . error ) != 0 )
F_33 ( V_68 L_33 ) ;
F_98 () ;
V_114 = F_88 ( V_123 ) ;
if ( V_114 )
F_99 ( L_34 ,
V_69 ) ;
V_109:
F_89 ( V_123 ) ;
return F_60 ( & V_94 . error ) ;
}
int F_90 ( T_7 V_119 , int * V_120 )
{
return - V_124 ;
}
struct V_132 * F_100 ( struct V_133 * log ,
T_8 V_134 )
{
struct V_135 * V_136 =
(struct V_135 * ) log -> V_137 ;
struct V_132 * V_138 ;
unsigned char * V_23 , * V_139 ;
T_9 V_140 = F_101 ( log ) ;
T_10 V_141 = F_102 ( V_136 ) ;
T_9 V_142 = F_103 ( V_136 ) ;
if ( V_140 < sizeof( struct V_135 ) ||
V_141 != V_143 ||
V_142 != V_144 )
return NULL ;
V_139 = log -> V_137 + V_140 ;
V_23 = V_136 -> V_145 ;
while ( V_23 < V_139 ) {
V_138 = (struct V_132 * ) V_23 ;
if ( F_104 ( V_138 ) == V_134 )
return V_138 ;
V_23 += F_105 ( V_138 ) ;
}
return NULL ;
}
T_11 int F_106 ( struct V_5 T_12 * V_146 )
{
struct V_5 args ;
unsigned long V_1 ;
char * V_52 , * V_147 = NULL ;
int V_9 , V_10 , V_8 ;
int V_62 ;
if ( ! F_107 ( V_148 ) )
return - V_149 ;
if ( F_108 ( & args , V_146 , 3 * sizeof( T_3 ) ) != 0 )
return - V_65 ;
V_9 = F_26 ( args . V_9 ) ;
V_10 = F_26 ( args . V_10 ) ;
V_8 = F_26 ( args . V_8 ) ;
if ( V_9 > F_109 ( args . args )
|| V_10 > F_109 ( args . args )
|| V_9 + V_10 > F_109 ( args . args ) )
return - V_64 ;
if ( F_108 ( args . args , V_146 -> args ,
V_9 * sizeof( V_150 ) ) != 0 )
return - V_65 ;
if ( V_8 == V_33 )
return - V_64 ;
args . V_11 = & args . args [ V_9 ] ;
memset ( args . V_11 , 0 , V_10 * sizeof( V_150 ) ) ;
if ( V_8 == V_151 ) {
int V_152 = 0 ;
T_7 V_119 = ( ( T_7 ) F_26 ( args . args [ 0 ] ) << 32 )
| F_26 ( args . args [ 1 ] ) ;
V_62 = F_90 ( V_119 , & V_152 ) ;
args . V_11 [ 0 ] = F_10 ( V_152 ) ;
if ( V_62 )
return V_62 ;
goto V_153;
}
V_52 = F_110 () ;
V_1 = F_1 () ;
V_2 . args = args ;
F_11 ( F_12 ( & V_2 . args ) ) ;
args = V_2 . args ;
if ( F_26 ( args . V_11 [ 0 ] ) == - 1 )
V_147 = F_34 ( V_52 ) ;
F_5 ( V_1 ) ;
if ( V_52 ) {
if ( V_147 )
F_37 ( V_147 , V_56 , 0 ) ;
F_38 ( V_52 ) ;
}
V_153:
if ( F_111 ( V_146 -> args + V_9 ,
args . args + V_9 ,
V_10 * sizeof( V_150 ) ) != 0 )
return - V_65 ;
return 0 ;
}
void T_1 F_112 ( void )
{
unsigned long V_154 = V_155 ;
V_2 . V_36 = F_113 ( NULL , L_35 ) ;
if ( V_2 . V_36 ) {
const T_2 * V_156 , * V_157 , * V_158 ;
V_156 = F_25 ( V_2 . V_36 , L_36 , NULL ) ;
V_158 = F_25 ( V_2 . V_36 , L_37 , NULL ) ;
if ( V_156 != NULL && V_158 != NULL ) {
V_2 . V_7 = F_49 ( * V_156 ) ;
V_2 . V_159 = F_49 ( * V_158 ) ;
V_157 = F_25 ( V_2 . V_36 ,
L_38 , NULL ) ;
if ( V_157 == NULL )
V_2 . V_54 = V_2 . V_7 ;
else
V_2 . V_54 = F_49 ( * V_157 ) ;
} else
V_2 . V_36 = NULL ;
}
if ( ! V_2 . V_36 )
return;
#ifdef F_114
if ( F_115 ( V_160 ) && F_116 ( V_161 ) ) {
V_154 = F_117 ( V_162 , V_155 ) ;
V_151 = F_28 ( L_29 ) ;
}
#endif
V_163 = F_118 ( V_164 , V_165 , V_154 ) ;
#ifdef F_119
V_45 = F_28 ( L_39 ) ;
#endif
}
int T_1 F_120 ( unsigned long V_166 ,
const char * V_167 , int V_168 , void * V_94 )
{
const T_3 * V_156 , * V_157 , * V_158 ;
if ( V_168 != 1 || strcmp ( V_167 , L_35 ) != 0 )
return 0 ;
V_156 = F_121 ( V_166 , L_36 , NULL ) ;
V_157 = F_121 ( V_166 , L_38 , NULL ) ;
V_158 = F_121 ( V_166 , L_37 , NULL ) ;
if ( V_156 && V_157 && V_158 ) {
V_2 . V_7 = * V_156 ;
V_2 . V_54 = * V_157 ;
V_2 . V_159 = * V_158 ;
}
#ifdef F_122
V_156 = F_121 ( V_166 , L_40 , NULL ) ;
if ( V_156 )
V_16 = * V_156 ;
V_156 = F_121 ( V_166 , L_41 , NULL ) ;
if ( V_156 )
V_17 = * V_156 ;
if ( V_16 != V_33 &&
V_17 != V_33 )
F_21 () ;
#endif
return 1 ;
}
void F_123 ( void )
{
unsigned long V_1 ;
F_2 ( V_1 ) ;
F_124 () ;
F_125 ( & V_169 ) ;
F_18 ( F_28 ( L_42 ) , 0 , 1 , NULL ) ;
V_170 = F_126 () ;
F_6 ( & V_169 ) ;
while ( V_170 )
F_127 () ;
F_18 ( F_28 ( L_43 ) , 0 , 1 , NULL ) ;
F_7 ( V_1 ) ;
}
void F_128 ( void )
{
while ( ! V_170 )
F_127 () ;
F_125 ( & V_169 ) ;
F_129 ( V_170 >> 32 , V_170 & 0xffffffff ) ;
V_170 = 0 ;
F_6 ( & V_169 ) ;
}
