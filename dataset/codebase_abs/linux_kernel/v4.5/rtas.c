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
unsigned long V_5 ;
if ( ! V_2 . V_6 )
return;
V_5 = F_1 () ;
F_10 ( & V_2 . args , 10 , 1 , 1 , NULL , V_4 ) ;
F_5 ( V_5 ) ;
}
static void F_11 ( char V_4 )
{
static int V_7 = 0 ;
static int V_8 = 16 ;
if ( V_4 == '\n' ) {
while ( V_8 -- > 0 )
F_9 ( ' ' ) ;
V_8 = 16 ;
F_12 ( 500 ) ;
V_7 = 1 ;
} else {
if ( V_7 ) {
F_9 ( '\r' ) ;
F_9 ( '\n' ) ;
}
V_7 = 0 ;
if ( V_8 -- ) {
F_9 ( V_4 ) ;
F_13 ( 10000 ) ;
}
}
}
void T_1 F_14 ( void )
{
V_9 = F_11 ;
}
static void F_15 ( char V_4 )
{
int V_10 ;
if ( ! V_2 . V_6 )
return;
if ( V_4 == '\n' )
F_15 ( '\r' ) ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ ) {
if ( F_16 ( V_11 , 1 , 1 , NULL , V_4 ) == 0 )
break;
F_13 ( 1000 ) ;
}
}
static int F_17 ( void )
{
int V_4 ;
if ( ! V_2 . V_6 )
return - 1 ;
if ( F_16 ( V_12 , 0 , 2 , & V_4 ) )
return - 1 ;
return V_4 ;
}
static int F_18 ( void )
{
int V_4 ;
while ( ( V_4 = F_17 () ) == - 1 )
;
return V_4 ;
}
void T_1 F_19 ( void )
{
V_9 = F_15 ;
V_13 = F_18 ;
V_14 = F_17 ;
}
void F_20 ( char * V_5 , unsigned short V_15 )
{
struct V_16 * V_17 ;
int V_8 ;
const T_2 * V_18 ;
char * V_19 ;
static int V_20 , V_21 ;
static int V_22 , V_23 , V_24 ;
static const int * V_25 ;
static F_21 ( V_26 ) ;
static int V_27 ;
static int V_7 = 0 ;
if ( ! V_2 . V_6 )
return;
if ( V_22 == 0 ) {
V_22 = 0x10 ;
if ( ( V_17 = F_22 ( L_1 ) ) ) {
if ( ( V_18 = F_23 ( V_17 ,
L_2 , NULL ) ) )
V_22 = F_24 ( * V_18 ) ;
if ( ( V_18 = F_23 ( V_17 ,
L_3 , NULL ) ) )
V_24 = F_24 ( * V_18 ) ;
if ( ( V_18 = F_23 ( V_17 ,
L_4 , NULL ) ) )
V_23 = F_24 ( * V_18 ) ;
V_25 = F_23 ( V_17 ,
L_5 , NULL ) ;
F_25 ( V_17 ) ;
}
V_20 = F_26 ( L_6 ) ;
V_21 = F_26 ( L_7 ) ;
}
if ( V_20 == V_28 ) {
if ( V_21 != V_28 )
F_16 ( V_21 , 3 , 1 , NULL , 6 , 0 , V_15 ) ;
return;
}
F_27 ( & V_26 ) ;
if ( V_7 ) {
F_16 ( V_20 , 1 , 1 , NULL , '\r' ) ;
F_16 ( V_20 , 1 , 1 , NULL , '\n' ) ;
V_7 = 0 ;
} else {
V_27 = 0 ;
if ( V_24 )
F_16 ( V_20 , 1 , 1 , NULL ,
( char ) V_24 ) ;
else
F_16 ( V_20 , 1 , 1 , NULL , '\r' ) ;
}
if ( V_25 )
V_8 = V_25 [ V_27 ] ;
else
V_8 = V_22 ;
V_19 = V_5 ;
while ( * V_19 ) {
if ( * V_19 == '\n' || * V_19 == '\r' ) {
if ( * V_19 == '\n' && ! V_19 [ 1 ] ) {
V_7 = 1 ;
V_27 ++ ;
if ( V_27 > V_23 - 1 )
V_27 = V_23 - 1 ;
F_28 ( & V_26 ) ;
return;
}
if ( * V_19 == '\n' ) {
F_16 ( V_20 , 1 , 1 , NULL , '\r' ) ;
F_16 ( V_20 , 1 , 1 , NULL , '\n' ) ;
} else {
F_16 ( V_20 , 1 , 1 , NULL , * V_19 ) ;
}
if ( V_25 )
V_8 = V_25 [ V_27 ] ;
else
V_8 = V_22 ;
} else {
V_8 -- ;
F_16 ( V_20 , 1 , 1 , NULL , * V_19 ) ;
}
V_19 ++ ;
if ( V_8 <= 0 )
while ( ( * V_19 != 0 ) && ( * V_19 != '\n' ) && ( * V_19 != '\r' ) )
V_19 ++ ;
}
F_28 ( & V_26 ) ;
}
int F_26 ( const char * V_29 )
{
const T_2 * V_30 ;
if ( V_2 . V_31 == NULL )
return V_28 ;
V_30 = F_23 ( V_2 . V_31 , V_29 , NULL ) ;
return V_30 ? F_24 ( * V_30 ) : V_28 ;
}
int F_29 ( const char * V_29 )
{
return F_26 ( V_29 ) != V_28 ;
}
int F_30 ( void )
{
static int V_32 ;
if ( V_32 )
return V_32 ;
V_32 = F_26 ( L_8 ) ;
if ( ( V_32 == V_28 ) ||
( V_32 > V_33 ) ) {
F_31 ( V_34 L_9 ,
V_32 ) ;
V_32 = V_33 ;
}
return V_32 ;
}
static char * F_32 ( char * V_35 )
{
struct V_36 V_37 , V_38 ;
T_3 V_39 ;
char * V_40 = NULL ;
if ( V_41 == - 1 )
return NULL ;
V_39 = F_30 () ;
V_37 . V_42 = F_33 ( V_41 ) ;
V_37 . V_43 = F_33 ( 2 ) ;
V_37 . V_44 = F_33 ( 1 ) ;
V_37 . args [ 0 ] = F_33 ( F_34 ( V_45 ) ) ;
V_37 . args [ 1 ] = F_33 ( V_39 ) ;
V_37 . args [ 2 ] = 0 ;
V_38 = V_2 . args ;
V_2 . args = V_37 ;
F_35 ( F_34 ( & V_2 . args ) ) ;
V_37 = V_2 . args ;
V_2 . args = V_38 ;
if ( F_36 ( V_37 . args [ 2 ] == 0 ) ) {
if ( V_35 ) {
V_40 = V_35 ;
} else {
V_40 = V_45 ;
if ( F_37 () )
V_40 = F_38 ( V_33 , V_46 ) ;
}
if ( V_40 )
memcpy ( V_40 , V_45 , V_33 ) ;
}
return V_40 ;
}
static void
F_39 ( struct V_36 * args , int V_42 , int V_43 , int V_44 ,
T_4 V_47 )
{
int V_48 ;
args -> V_42 = F_33 ( V_42 ) ;
args -> V_43 = F_33 ( V_43 ) ;
args -> V_44 = F_33 ( V_44 ) ;
args -> V_49 = & ( args -> args [ V_43 ] ) ;
for ( V_48 = 0 ; V_48 < V_43 ; ++ V_48 )
args -> args [ V_48 ] = F_33 ( va_arg ( V_47 , V_50 ) ) ;
for ( V_48 = 0 ; V_48 < V_44 ; ++ V_48 )
args -> V_49 [ V_48 ] = 0 ;
F_35 ( F_34 ( args ) ) ;
}
void F_10 ( struct V_36 * args , int V_42 , int V_43 , int V_44 , ... )
{
T_4 V_47 ;
va_start ( V_47 , V_44 ) ;
F_39 ( args , V_42 , V_43 , V_44 , V_47 ) ;
va_end ( V_47 ) ;
}
int F_16 ( int V_42 , int V_43 , int V_44 , int * V_51 , ... )
{
T_4 V_47 ;
int V_48 ;
unsigned long V_5 ;
struct V_36 * V_36 ;
char * V_52 = NULL ;
int V_53 ;
if ( ! V_2 . V_54 || V_42 == V_28 )
return - 1 ;
V_5 = F_1 () ;
V_36 = & V_2 . args ;
va_start ( V_47 , V_51 ) ;
F_39 ( V_36 , V_42 , V_43 , V_44 , V_47 ) ;
va_end ( V_47 ) ;
if ( F_24 ( V_36 -> V_49 [ 0 ] ) == - 1 )
V_52 = F_32 ( NULL ) ;
if ( V_44 > 1 && V_51 != NULL )
for ( V_48 = 0 ; V_48 < V_44 - 1 ; ++ V_48 )
V_51 [ V_48 ] = F_24 ( V_36 -> V_49 [ V_48 + 1 ] ) ;
V_53 = ( V_44 > 0 ) ? F_24 ( V_36 -> V_49 [ 0 ] ) : 0 ;
F_5 ( V_5 ) ;
if ( V_52 ) {
F_40 ( V_52 , V_55 , 0 ) ;
if ( F_37 () )
F_41 ( V_52 ) ;
}
return V_53 ;
}
unsigned int F_42 ( int V_56 )
{
int V_57 ;
unsigned int V_58 = 0 ;
if ( V_56 == V_59 ) {
V_58 = 1 ;
} else if ( V_56 >= V_60 &&
V_56 <= V_61 ) {
V_57 = V_56 - V_60 ;
for ( V_58 = 1 ; V_57 > 0 ; V_57 -- )
V_58 *= 10 ;
}
return V_58 ;
}
unsigned int F_43 ( int V_56 )
{
unsigned int V_58 ;
F_44 () ;
V_58 = F_42 ( V_56 ) ;
if ( V_58 && F_45 () )
F_46 ( V_58 ) ;
return V_58 ;
}
static int F_47 ( int V_62 )
{
int V_63 ;
switch ( V_62 ) {
case - 1 :
V_63 = - V_64 ;
break;
case - 3 :
V_63 = - V_65 ;
break;
case - 9000 :
V_63 = - V_66 ;
break;
case - 9001 :
V_63 = - V_67 ;
break;
case - 9002 :
V_63 = - V_68 ;
break;
default:
F_31 ( V_69 L_10 ,
V_70 , V_62 ) ;
V_63 = - V_71 ;
break;
}
return V_63 ;
}
int F_48 ( int V_72 , int * V_73 )
{
int V_42 = F_26 ( L_11 ) ;
int V_63 ;
if ( V_42 == V_28 )
return - V_74 ;
while ( ( V_63 = F_16 ( V_42 , 1 , 2 , V_73 , V_72 ) ) == V_59 )
F_13 ( 1 ) ;
if ( V_63 < 0 )
return F_47 ( V_63 ) ;
return V_63 ;
}
int F_49 ( int V_72 , int V_73 , int * V_75 )
{
int V_42 = F_26 ( L_12 ) ;
int V_63 ;
if ( V_42 == V_28 )
return - V_74 ;
do {
V_63 = F_16 ( V_42 , 2 , 2 , V_75 , V_72 , V_73 ) ;
} while ( F_43 ( V_63 ) );
if ( V_63 < 0 )
return F_47 ( V_63 ) ;
return V_63 ;
}
int F_50 ( int V_76 , int V_77 , int * V_78 )
{
int V_42 = F_26 ( L_13 ) ;
int V_63 ;
if ( V_42 == V_28 )
return - V_74 ;
do {
V_63 = F_16 ( V_42 , 2 , 2 , V_78 , V_76 , V_77 ) ;
} while ( F_43 ( V_63 ) );
if ( V_63 < 0 )
return F_47 ( V_63 ) ;
return V_63 ;
}
int F_51 ( int V_76 , int V_77 , int * V_78 )
{
int V_42 = F_26 ( L_13 ) ;
int V_63 ;
if ( V_42 == V_28 )
return - V_74 ;
V_63 = F_16 ( V_42 , 2 , 2 , V_78 , V_76 , V_77 ) ;
F_52 ( V_63 == V_59 || ( V_63 >= V_60 &&
V_63 <= V_61 ) ) ;
if ( V_63 < 0 )
return F_47 ( V_63 ) ;
return V_63 ;
}
bool F_53 ( int V_42 , int * V_79 )
{
int V_80 , V_81 , V_48 ;
const struct V_82 {
T_2 V_42 ;
T_2 V_79 ;
} * V_83 ;
V_83 = F_23 ( V_2 . V_31 , L_14 , & V_80 ) ;
if ( ! V_83 )
return false ;
V_81 = V_80 / sizeof( struct V_82 ) ;
for ( V_48 = 0 ; V_48 < V_81 ; V_48 ++ ) {
if ( F_54 ( V_83 [ V_48 ] . V_42 ) != V_42 )
continue;
if ( V_79 )
* V_79 = F_54 ( V_83 [ V_48 ] . V_79 ) ;
return true ;
}
return false ;
}
int F_55 ( int V_84 , int V_77 , int V_85 )
{
int V_42 = F_26 ( L_7 ) ;
int V_63 ;
if ( V_42 == V_28 )
return - V_74 ;
do {
V_63 = F_16 ( V_42 , 3 , 1 , NULL , V_84 , V_77 , V_85 ) ;
} while ( F_43 ( V_63 ) );
if ( V_63 < 0 )
return F_47 ( V_63 ) ;
return V_63 ;
}
int F_56 ( int V_84 , int V_77 , int V_85 )
{
int V_63 ;
int V_42 = F_26 ( L_7 ) ;
if ( V_42 == V_28 )
return - V_74 ;
V_63 = F_16 ( V_42 , 3 , 1 , NULL , V_84 , V_77 , V_85 ) ;
F_52 ( V_63 == V_59 || ( V_63 >= V_60 &&
V_63 <= V_61 ) ) ;
if ( V_63 < 0 )
return F_47 ( V_63 ) ;
return V_63 ;
}
void F_57 ( char * V_86 )
{
if ( V_87 )
V_87 ( V_88 ) ;
F_31 ( L_15 ,
F_16 ( F_26 ( L_16 ) , 0 , 1 , NULL ) ) ;
for (; ; ) ;
}
void F_58 ( void )
{
if ( V_87 )
V_87 ( V_89 ) ;
F_31 ( L_17 ,
F_16 ( F_26 ( L_18 ) , 2 , 1 , NULL , - 1 , - 1 ) ) ;
for (; ; ) ;
}
void F_59 ( void )
{
if ( V_87 )
V_87 ( V_90 ) ;
F_31 ( L_17 ,
F_16 ( F_26 ( L_18 ) , 2 , 1 , NULL , - 1 , - 1 ) ) ;
for (; ; ) ;
}
void F_60 ( char * V_91 )
{
int V_56 ;
if ( V_28 == F_26 ( L_19 ) ||
V_28 == F_26 ( L_20 ) )
return;
snprintf ( V_92 , 2048 , L_21 , V_91 ) ;
do {
V_56 = F_16 ( F_26 ( L_19 ) , 1 , 1 , NULL ,
F_34 ( V_92 ) ) ;
} while ( F_43 ( V_56 ) );
if ( V_56 != 0 )
F_31 ( V_93 L_22 , V_56 ) ;
}
static int F_61 ( struct V_94 * V_95 , int V_96 )
{
T_5 V_97 = V_98 ;
int V_63 = V_99 ;
int V_100 ;
F_62 ( V_101 ) ;
F_31 ( V_102 L_23 , F_63 () ) ;
while ( V_63 == V_99 && ! F_64 ( & V_95 -> V_103 ) &&
! F_64 ( & V_95 -> error ) )
V_63 = F_16 ( V_95 -> V_42 , 0 , 1 , NULL ) ;
if ( V_63 || F_64 ( & V_95 -> error ) ) {
F_31 ( V_102 L_24 , V_63 ) ;
F_62 ( V_97 ) ;
}
if ( F_64 ( & V_95 -> error ) )
V_63 = F_64 ( & V_95 -> error ) ;
F_65 ( & V_95 -> error , V_63 ) ;
F_66 () ;
if ( V_96 ) {
F_65 ( & V_95 -> V_103 , 1 ) ;
F_67 (cpu)
F_68 ( V_104 , F_69 ( V_100 ) ) ;
}
if ( F_70 ( & V_95 -> V_105 ) == 0 )
F_71 ( V_95 -> F_71 ) ;
return V_63 ;
}
int F_72 ( struct V_94 * V_95 )
{
F_73 ( & V_95 -> V_105 ) ;
return F_61 ( V_95 , 0 ) ;
}
static int F_74 ( struct V_94 * V_95 , int V_96 )
{
long V_63 = V_106 ;
unsigned long V_107 ;
int V_100 ;
F_73 ( & V_95 -> V_105 ) ;
V_107 = F_75 () ;
F_76 ( V_107 & ~ ( V_108 ) ) ;
while ( V_63 == V_106 && ! F_64 ( & V_95 -> V_103 ) && ! F_64 ( & V_95 -> error ) )
V_63 = F_68 ( V_109 ) ;
F_76 ( V_107 ) ;
if ( V_63 == V_106 ) {
goto V_110;
} else if ( V_63 == V_111 ) {
return F_61 ( V_95 , V_96 ) ;
} else {
F_31 ( V_69 L_25 ,
F_63 () , V_63 ) ;
F_65 ( & V_95 -> error , V_63 ) ;
}
if ( V_96 ) {
F_65 ( & V_95 -> V_103 , 1 ) ;
F_67 (cpu)
F_68 ( V_104 , F_69 ( V_100 ) ) ;
}
V_110:
if ( F_70 ( & V_95 -> V_105 ) == 0 )
F_71 ( V_95 -> F_71 ) ;
return V_63 ;
}
int F_77 ( struct V_94 * V_95 )
{
return F_74 ( V_95 , 0 ) ;
}
static void F_78 ( void * V_112 )
{
F_74 ( (struct V_94 * ) V_112 , 1 ) ;
}
static int F_79 ( enum V_113 V_78 ,
T_6 V_114 )
{
if ( ! F_80 ( V_114 ) ) {
F_81 ( V_114 ) ;
return - V_65 ;
} else
return 0 ;
}
static int F_79 ( enum V_113 V_78 ,
T_6 V_114 )
{
int V_100 ;
int V_115 = 0 ;
int V_53 = 0 ;
if ( F_80 ( V_114 ) )
return 0 ;
F_82 (cpu, cpus) {
switch ( V_78 ) {
case V_116 :
V_115 = F_83 ( V_100 ) ;
break;
case V_117 :
V_115 = F_84 ( V_100 ) ;
break;
}
if ( V_115 ) {
F_85 ( L_26 ,
V_70 ,
( ( V_78 == V_117 ) ? L_27 : L_28 ) ,
V_100 , V_115 ) ;
if ( ! V_53 )
V_53 = V_115 ;
if ( V_78 == V_117 ) {
F_86 ( V_114 , V_114 , V_100 ) ;
F_87 ( V_114 , V_114 , V_100 ) ;
break;
} else {
F_88 ( V_100 , V_114 ) ;
}
}
}
return V_53 ;
}
int F_89 ( T_6 V_114 )
{
int V_53 ;
V_53 = F_79 ( V_117 , V_114 ) ;
if ( V_53 ) {
T_6 V_118 ;
if ( ! F_90 ( & V_118 , V_119 ) )
return V_53 ;
F_91 ( V_118 , V_114 ) ;
F_92 ( V_118 ) ;
F_93 ( V_118 ) ;
}
return V_53 ;
}
int F_92 ( T_6 V_114 )
{
return F_79 ( V_116 , V_114 ) ;
}
int F_94 ( T_7 V_120 )
{
long V_78 ;
long V_63 ;
unsigned long V_121 [ V_122 ] ;
struct V_94 V_95 ;
F_95 ( V_103 ) ;
T_6 V_123 ;
int V_115 ;
if ( ! F_29 ( L_29 ) )
return - V_124 ;
V_63 = F_96 ( V_125 , V_121 , V_120 ) ;
V_78 = V_121 [ 0 ] ;
if ( V_63 ) {
F_31 ( V_69 L_30 , V_63 ) ;
return V_63 ;
} else if ( V_78 == V_126 ) {
return - V_127 ;
} else if ( V_78 != V_128 ) {
F_31 ( V_69 L_31 ,
V_78 ) ;
return - V_64 ;
}
if ( ! F_90 ( & V_123 , V_119 ) )
return - V_129 ;
F_65 ( & V_95 . V_105 , 0 ) ;
F_65 ( & V_95 . V_103 , 0 ) ;
F_65 ( & V_95 . error , 0 ) ;
V_95 . V_42 = F_26 ( L_29 ) ;
V_95 . F_71 = & V_103 ;
F_97 ( V_123 , V_130 , V_131 ) ;
V_115 = F_89 ( V_123 ) ;
if ( V_115 ) {
F_98 ( L_32 , V_70 ) ;
F_65 ( & V_95 . error , V_115 ) ;
goto V_110;
}
F_99 () ;
if ( F_100 ( F_78 , & V_95 , 0 ) )
F_65 ( & V_95 . error , - V_65 ) ;
F_101 ( & V_103 ) ;
if ( F_64 ( & V_95 . error ) != 0 )
F_31 ( V_69 L_33 ) ;
F_102 () ;
V_115 = F_92 ( V_123 ) ;
if ( V_115 )
F_103 ( L_34 ,
V_70 ) ;
V_110:
F_93 ( V_123 ) ;
return F_64 ( & V_95 . error ) ;
}
int F_94 ( T_7 V_120 )
{
return - V_124 ;
}
struct V_132 * F_104 ( struct V_133 * log ,
T_8 V_134 )
{
struct V_135 * V_136 =
(struct V_135 * ) log -> V_137 ;
struct V_132 * V_138 ;
unsigned char * V_18 , * V_139 ;
T_9 V_140 = F_105 ( log ) ;
T_10 V_141 = F_106 ( V_136 ) ;
T_9 V_142 = F_107 ( V_136 ) ;
if ( V_140 < sizeof( struct V_135 ) ||
V_141 != V_143 ||
V_142 != V_144 )
return NULL ;
V_139 = log -> V_137 + V_140 ;
V_18 = V_136 -> V_145 ;
while ( V_18 < V_139 ) {
V_138 = (struct V_132 * ) V_18 ;
if ( F_108 ( V_138 ) == V_134 )
return V_138 ;
V_18 += F_109 ( V_138 ) ;
}
return NULL ;
}
T_11 int F_110 ( struct V_36 T_12 * V_146 )
{
struct V_36 args ;
unsigned long V_1 ;
char * V_52 , * V_147 = NULL ;
int V_43 , V_44 , V_42 ;
if ( ! F_111 ( V_148 ) )
return - V_149 ;
if ( ! V_2 . V_54 )
return - V_65 ;
if ( F_112 ( & args , V_146 , 3 * sizeof( T_3 ) ) != 0 )
return - V_66 ;
V_43 = F_24 ( args . V_43 ) ;
V_44 = F_24 ( args . V_44 ) ;
V_42 = F_24 ( args . V_42 ) ;
if ( V_43 > F_113 ( args . args )
|| V_44 > F_113 ( args . args )
|| V_43 + V_44 > F_113 ( args . args ) )
return - V_65 ;
if ( F_112 ( args . args , V_146 -> args ,
V_43 * sizeof( V_150 ) ) != 0 )
return - V_66 ;
if ( V_42 == V_28 )
return - V_65 ;
args . V_49 = & args . args [ V_43 ] ;
memset ( args . V_49 , 0 , V_44 * sizeof( V_150 ) ) ;
if ( V_42 == V_151 ) {
int V_63 = 0 ;
T_7 V_120 = ( ( T_7 ) F_24 ( args . args [ 0 ] ) << 32 )
| F_24 ( args . args [ 1 ] ) ;
V_63 = F_94 ( V_120 ) ;
if ( V_63 == - V_127 )
args . V_49 [ 0 ] = F_33 ( V_152 ) ;
else if ( V_63 == - V_64 )
args . V_49 [ 0 ] = F_33 ( - 1 ) ;
else if ( V_63 )
return V_63 ;
goto V_153;
}
V_52 = F_114 () ;
V_1 = F_1 () ;
V_2 . args = args ;
F_35 ( F_34 ( & V_2 . args ) ) ;
args = V_2 . args ;
if ( F_24 ( args . V_49 [ 0 ] ) == - 1 )
V_147 = F_32 ( V_52 ) ;
F_5 ( V_1 ) ;
if ( V_52 ) {
if ( V_147 )
F_40 ( V_147 , V_55 , 0 ) ;
F_41 ( V_52 ) ;
}
V_153:
if ( F_115 ( V_146 -> args + V_43 ,
args . args + V_43 ,
V_44 * sizeof( V_150 ) ) != 0 )
return - V_66 ;
return 0 ;
}
void T_1 F_116 ( void )
{
unsigned long V_154 = V_155 ;
V_2 . V_31 = F_117 ( NULL , L_35 ) ;
if ( V_2 . V_31 ) {
const T_2 * V_156 , * V_157 , * V_158 ;
V_156 = F_23 ( V_2 . V_31 , L_36 , NULL ) ;
V_158 = F_23 ( V_2 . V_31 , L_37 , NULL ) ;
if ( V_156 != NULL && V_158 != NULL ) {
V_2 . V_6 = F_54 ( * V_156 ) ;
V_2 . V_159 = F_54 ( * V_158 ) ;
V_157 = F_23 ( V_2 . V_31 ,
L_38 , NULL ) ;
if ( V_157 == NULL )
V_2 . V_54 = V_2 . V_6 ;
else
V_2 . V_54 = F_54 ( * V_157 ) ;
} else
V_2 . V_31 = NULL ;
}
if ( ! V_2 . V_31 )
return;
#ifdef F_118
if ( F_119 ( V_160 ) && F_120 ( V_161 ) ) {
V_154 = F_121 ( V_162 , V_155 ) ;
V_151 = F_26 ( L_29 ) ;
}
#endif
V_163 = F_122 ( V_164 , V_165 , V_154 ) ;
#ifdef F_123
V_41 = F_26 ( L_39 ) ;
#endif
}
int T_1 F_124 ( unsigned long V_166 ,
const char * V_167 , int V_168 , void * V_95 )
{
const T_3 * V_156 , * V_157 , * V_158 ;
if ( V_168 != 1 || strcmp ( V_167 , L_35 ) != 0 )
return 0 ;
V_156 = F_125 ( V_166 , L_36 , NULL ) ;
V_157 = F_125 ( V_166 , L_38 , NULL ) ;
V_158 = F_125 ( V_166 , L_37 , NULL ) ;
if ( V_156 && V_157 && V_158 ) {
V_2 . V_6 = * V_156 ;
V_2 . V_54 = * V_157 ;
V_2 . V_159 = * V_158 ;
}
#ifdef F_126
V_156 = F_125 ( V_166 , L_40 , NULL ) ;
if ( V_156 )
V_11 = * V_156 ;
V_156 = F_125 ( V_166 , L_41 , NULL ) ;
if ( V_156 )
V_12 = * V_156 ;
if ( V_11 != V_28 &&
V_12 != V_28 )
F_19 () ;
#endif
return 1 ;
}
void F_127 ( void )
{
unsigned long V_1 ;
F_2 ( V_1 ) ;
F_128 () ;
F_129 ( & V_169 ) ;
F_16 ( F_26 ( L_42 ) , 0 , 1 , NULL ) ;
V_170 = F_130 () ;
F_6 ( & V_169 ) ;
while ( V_170 )
F_131 () ;
F_16 ( F_26 ( L_43 ) , 0 , 1 , NULL ) ;
F_7 ( V_1 ) ;
}
void F_132 ( void )
{
while ( ! V_170 )
F_131 () ;
F_129 ( & V_169 ) ;
F_133 ( V_170 >> 32 , V_170 & 0xffffffff ) ;
V_170 = 0 ;
F_6 ( & V_169 ) ;
}
