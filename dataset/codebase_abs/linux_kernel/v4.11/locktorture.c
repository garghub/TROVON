static int F_1 ( void )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_5 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_7 ( void )
{
}
static void F_8 ( struct V_1 * V_2 )
{
}
static int F_9 ( void ) __acquires( T_1 )
{
F_10 ( & T_1 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
const unsigned long V_6 = 2 ;
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2 * V_6 ) ) )
F_12 ( V_6 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_5 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_13 ( void ) __releases( T_1 )
{
F_14 ( & T_1 ) ;
}
static int F_15 ( void )
__acquires( T_1 )
{
unsigned long V_7 ;
F_16 ( & T_1 , V_7 ) ;
V_4 . V_8 -> V_7 = V_7 ;
return 0 ;
}
static void F_17 ( void )
__releases( T_1 )
{
F_18 ( & T_1 , V_4 . V_8 -> V_7 ) ;
}
static int F_19 ( void ) __acquires( T_2 )
{
F_20 ( & T_2 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
const unsigned long V_6 = 2 ;
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
else
F_12 ( V_6 ) ;
}
static void F_22 ( void ) __releases( T_2 )
{
F_23 ( & T_2 ) ;
}
static int F_24 ( void ) __acquires( T_2 )
{
F_25 ( & T_2 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
const unsigned long V_6 = 10 ;
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_9 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
else
F_12 ( V_6 ) ;
}
static void F_27 ( void ) __releases( T_2 )
{
F_28 ( & T_2 ) ;
}
static int F_29 ( void ) __acquires( T_2 )
{
unsigned long V_7 ;
F_30 ( & T_2 , V_7 ) ;
V_4 . V_8 -> V_7 = V_7 ;
return 0 ;
}
static void F_31 ( void )
__releases( T_2 )
{
F_32 ( & T_2 , V_4 . V_8 -> V_7 ) ;
}
static int F_33 ( void ) __acquires( T_2 )
{
unsigned long V_7 ;
F_34 ( & T_2 , V_7 ) ;
V_4 . V_8 -> V_7 = V_7 ;
return 0 ;
}
static void F_35 ( void )
__releases( T_2 )
{
F_36 ( & T_2 , V_4 . V_8 -> V_7 ) ;
}
static int F_37 ( void ) __acquires( T_3 )
{
F_38 ( & T_3 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 * 5 ) ;
else
F_4 ( V_3 / 5 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_5 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_40 ( void ) __releases( T_3 )
{
F_41 ( & T_3 ) ;
}
static int F_42 ( void )
__acquires( T_4 )
__acquires( T_5 )
__acquires( T_6 )
{
F_43 ( V_10 ) ;
struct V_11 {
struct V_12 V_13 ;
struct V_14 * V_15 ;
} V_16 [ 3 ] , * V_17 , * V_18 ;
struct V_19 V_20 ;
V_16 [ 0 ] . V_15 = & T_4 ;
F_44 ( & V_16 [ 0 ] . V_13 , & V_10 ) ;
V_16 [ 1 ] . V_15 = & T_5 ;
F_44 ( & V_16 [ 1 ] . V_13 , & V_10 ) ;
V_16 [ 2 ] . V_15 = & T_6 ;
F_44 ( & V_16 [ 2 ] . V_13 , & V_10 ) ;
F_45 ( & V_20 , & V_21 ) ;
F_46 (ll, &list, link) {
int V_22 ;
V_22 = F_47 ( V_17 -> V_15 , & V_20 ) ;
if ( ! V_22 )
continue;
V_18 = V_17 ;
F_48 (ln, &list, link)
F_49 ( V_18 -> V_15 ) ;
if ( V_22 != - V_23 )
return V_22 ;
F_50 ( V_17 -> V_15 , & V_20 ) ;
F_51 ( & V_17 -> V_13 , & V_10 ) ;
}
F_52 ( & V_20 ) ;
return 0 ;
}
static void F_53 ( void )
__releases( T_4 )
__releases( T_5 )
__releases( T_6 )
{
F_49 ( & T_4 ) ;
F_49 ( & T_5 ) ;
F_49 ( & T_6 ) ;
}
static int F_54 ( void ) __acquires( T_7 )
{
F_55 ( & T_7 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_25 V_26 ;
const unsigned int V_27 = 50000 ;
if ( ! F_57 ( V_28 ) ) {
if ( V_2 && ! ( F_3 ( V_2 ) %
( V_4 . V_5 * V_27 ) ) ) {
V_24 = V_29 ;
V_26 . V_30 = V_31 - 1 ;
} else
return;
} else {
if ( ! V_2 || ! ( F_3 ( V_2 ) %
( V_4 . V_5 * V_27 * 2 ) ) ) {
V_24 = V_32 ;
V_26 . V_30 = 0 ;
} else
return;
}
F_58 ( V_28 , V_24 , & V_26 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
const unsigned long V_6 = 2 ;
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2 * V_6 ) ) )
F_12 ( V_6 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_5 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_60 ( void ) __releases( T_7 )
{
F_61 ( & T_7 ) ;
}
static int F_62 ( void ) __acquires( T_8 )
{
F_63 ( & T_8 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 * 10 ) ;
else
F_4 ( V_3 / 10 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_5 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_65 ( void ) __releases( T_8 )
{
F_66 ( & T_8 ) ;
}
static int F_67 ( void ) __acquires( T_8 )
{
F_68 ( & T_8 ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 * 2 ) ;
else
F_4 ( V_3 / 2 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_9 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_70 ( void ) __releases( T_8 )
{
F_71 ( & T_8 ) ;
}
void F_72 ( void )
{
F_73 ( F_74 ( & V_33 ) ) ;
}
static int F_75 ( void ) __acquires( V_33 )
{
F_76 ( & V_33 ) ;
return 0 ;
}
static void F_77 ( void ) __releases( V_33 )
{
F_78 ( & V_33 ) ;
}
static int F_79 ( void ) __acquires( V_33 )
{
F_80 ( & V_33 ) ;
return 0 ;
}
static void F_81 ( void ) __releases( V_33 )
{
F_82 ( & V_33 ) ;
}
static int F_83 ( void * V_34 )
{
struct V_35 * V_36 = V_34 ;
static F_84 ( rand ) ;
F_85 ( L_1 ) ;
F_86 ( V_28 , V_37 ) ;
do {
if ( ( F_3 ( & rand ) & 0xfffff ) == 0 )
F_87 ( 1 ) ;
V_4 . V_8 -> V_38 ( & rand ) ;
V_4 . V_8 -> V_39 () ;
if ( F_88 ( V_40 ) )
V_36 -> V_41 ++ ;
V_40 = 1 ;
if ( F_88 ( V_42 ) )
V_36 -> V_41 ++ ;
V_36 -> V_43 ++ ;
V_4 . V_8 -> V_44 ( & rand ) ;
V_40 = 0 ;
V_4 . V_8 -> V_45 () ;
F_89 ( L_2 ) ;
} while ( ! F_90 () );
V_4 . V_8 -> V_38 ( NULL ) ;
F_91 ( L_2 ) ;
return 0 ;
}
static int F_92 ( void * V_34 )
{
struct V_35 * V_46 = V_34 ;
static F_84 ( rand ) ;
F_85 ( L_3 ) ;
F_86 ( V_28 , V_37 ) ;
do {
if ( ( F_3 ( & rand ) & 0xfffff ) == 0 )
F_87 ( 1 ) ;
V_4 . V_8 -> V_47 () ;
V_42 = 1 ;
if ( F_88 ( V_40 ) )
V_46 -> V_41 ++ ;
V_46 -> V_43 ++ ;
V_4 . V_8 -> V_48 ( & rand ) ;
V_42 = 0 ;
V_4 . V_8 -> V_49 () ;
F_89 ( L_4 ) ;
} while ( ! F_90 () );
F_91 ( L_4 ) ;
return 0 ;
}
static void F_93 ( char * V_50 ,
struct V_35 * V_51 , bool V_52 )
{
bool V_53 = 0 ;
int V_54 , V_55 ;
long V_56 = 0 ;
long V_57 = V_51 [ 0 ] . V_43 ;
long long V_58 = 0 ;
V_55 = V_52 ? V_4 . V_5 : V_4 . V_9 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
if ( V_51 [ V_54 ] . V_41 )
V_53 = true ;
V_58 += V_51 [ V_54 ] . V_43 ;
if ( V_56 < V_51 [ V_54 ] . V_41 )
V_56 = V_51 [ V_54 ] . V_41 ;
if ( V_57 > V_51 [ V_54 ] . V_41 )
V_57 = V_51 [ V_54 ] . V_41 ;
}
V_50 += sprintf ( V_50 ,
L_5 ,
V_52 ? L_6 : L_7 ,
V_58 , V_56 , V_57 , V_56 / 2 > V_57 ? L_8 : L_9 ,
V_53 , V_53 ? L_10 : L_9 ) ;
if ( V_53 )
F_94 ( & V_4 . V_59 ) ;
}
static void F_95 ( void )
{
int V_60 = V_4 . V_5 * 200 + 8192 ;
char * V_61 ;
if ( V_4 . V_8 -> V_47 )
V_60 += V_4 . V_9 * 200 + 8192 ;
V_61 = F_96 ( V_60 , V_62 ) ;
if ( ! V_61 ) {
F_97 ( L_11 ,
V_60 ) ;
return;
}
F_93 ( V_61 , V_4 . V_63 , true ) ;
F_98 ( L_12 , V_61 ) ;
F_99 ( V_61 ) ;
if ( V_4 . V_8 -> V_47 ) {
V_61 = F_96 ( V_60 , V_62 ) ;
if ( ! V_61 ) {
F_97 ( L_11 ,
V_60 ) ;
return;
}
F_93 ( V_61 , V_4 . V_64 , false ) ;
F_98 ( L_12 , V_61 ) ;
F_99 ( V_61 ) ;
}
}
static int F_100 ( void * V_34 )
{
F_85 ( L_13 ) ;
do {
F_101 ( V_65 * V_66 ) ;
F_95 () ;
F_102 ( L_14 ) ;
} while ( ! F_90 () );
F_91 ( L_14 ) ;
return 0 ;
}
static inline void
F_103 ( struct V_67 * V_8 ,
const char * V_68 )
{
F_98 ( L_12 V_69
L_15 ,
V_70 , V_68 , V_4 . V_71 ? L_16 : L_9 ,
V_4 . V_5 , V_4 . V_9 , V_65 ,
V_72 , V_73 , V_74 , V_75 ,
V_76 , V_77 ) ;
}
static void F_104 ( void )
{
int V_54 ;
if ( F_105 () )
return;
if ( ! V_4 . V_63 )
goto V_78;
if ( V_79 ) {
for ( V_54 = 0 ; V_54 < V_4 . V_5 ; V_54 ++ )
F_106 ( F_83 ,
V_79 [ V_54 ] ) ;
F_99 ( V_79 ) ;
V_79 = NULL ;
}
if ( V_80 ) {
for ( V_54 = 0 ; V_54 < V_4 . V_9 ; V_54 ++ )
F_106 ( F_92 ,
V_80 [ V_54 ] ) ;
F_99 ( V_80 ) ;
V_80 = NULL ;
}
F_106 ( F_100 , V_81 ) ;
F_95 () ;
if ( F_107 ( & V_4 . V_59 ) )
F_103 ( V_4 . V_8 ,
L_17 ) ;
else if ( F_108 () )
F_103 ( V_4 . V_8 ,
L_18 ) ;
else
F_103 ( V_4 . V_8 ,
L_19 ) ;
F_99 ( V_4 . V_63 ) ;
F_99 ( V_4 . V_64 ) ;
V_78:
F_109 () ;
}
static int T_9 F_110 ( void )
{
int V_54 , V_82 ;
int V_83 = 0 ;
static struct V_67 * V_84 [] = {
& V_85 ,
& V_86 , & V_87 ,
& V_88 , & V_89 ,
& V_90 ,
& V_91 ,
#ifdef F_111
& V_92 ,
#endif
& V_93 ,
& V_94 ,
} ;
if ( ! F_112 ( V_70 , V_72 , & V_95 ) )
return - V_96 ;
for ( V_54 = 0 ; V_54 < F_113 ( V_84 ) ; V_54 ++ ) {
V_4 . V_8 = V_84 [ V_54 ] ;
if ( strcmp ( V_70 , V_4 . V_8 -> V_97 ) == 0 )
break;
}
if ( V_54 == F_113 ( V_84 ) ) {
F_98 ( L_20 ,
V_70 ) ;
F_98 ( L_21 ) ;
for ( V_54 = 0 ; V_54 < F_113 ( V_84 ) ; V_54 ++ )
F_98 ( L_22 , V_84 [ V_54 ] -> V_97 ) ;
F_98 ( L_23 ) ;
V_83 = - V_98 ;
goto V_99;
}
if ( V_4 . V_8 -> V_100 )
V_4 . V_8 -> V_100 () ;
if ( V_101 >= 0 )
V_4 . V_5 = V_101 ;
else
V_4 . V_5 = 2 * F_114 () ;
#ifdef F_115
if ( strncmp ( V_70 , L_24 , 5 ) == 0 )
V_4 . V_71 = true ;
#endif
#ifdef F_116
if ( strncmp ( V_70 , L_25 , 7 ) == 0 )
V_4 . V_71 = true ;
#endif
#ifdef F_117
if ( ( strncmp ( V_70 , L_26 , 4 ) == 0 ) ||
( strncmp ( V_70 , L_27 , 7 ) == 0 ) )
V_4 . V_71 = true ;
#endif
V_40 = 0 ;
V_4 . V_63 = F_96 ( sizeof( * V_4 . V_63 ) * V_4 . V_5 , V_62 ) ;
if ( V_4 . V_63 == NULL ) {
F_85 ( L_28 ) ;
V_83 = - V_102 ;
goto V_99;
}
for ( V_54 = 0 ; V_54 < V_4 . V_5 ; V_54 ++ ) {
V_4 . V_63 [ V_54 ] . V_41 = 0 ;
V_4 . V_63 [ V_54 ] . V_43 = 0 ;
}
if ( V_4 . V_8 -> V_47 ) {
if ( V_103 >= 0 )
V_4 . V_9 = V_103 ;
else {
if ( V_101 < 0 )
V_4 . V_5 = F_114 () ;
V_4 . V_9 = V_4 . V_5 ;
}
V_42 = 0 ;
V_4 . V_64 = F_96 ( sizeof( * V_4 . V_64 ) * V_4 . V_9 , V_62 ) ;
if ( V_4 . V_64 == NULL ) {
F_85 ( L_29 ) ;
V_83 = - V_102 ;
F_99 ( V_4 . V_63 ) ;
V_4 . V_63 = NULL ;
goto V_99;
}
for ( V_54 = 0 ; V_54 < V_4 . V_9 ; V_54 ++ ) {
V_4 . V_64 [ V_54 ] . V_41 = 0 ;
V_4 . V_64 [ V_54 ] . V_43 = 0 ;
}
}
F_103 ( V_4 . V_8 , L_30 ) ;
if ( V_76 > 0 ) {
V_83 = F_118 ( V_77 * V_66 ,
V_76 * V_66 ) ;
if ( V_83 )
goto V_99;
}
if ( V_73 > 0 ) {
V_83 = F_119 ( V_73 ) ;
if ( V_83 )
goto V_99;
}
if ( V_75 > 0 ) {
V_83 = F_120 ( V_75 ,
F_104 ) ;
if ( V_83 )
goto V_99;
}
if ( V_74 > 0 ) {
V_83 = F_121 ( V_74 ) ;
if ( V_83 )
goto V_99;
}
V_79 = F_122 ( V_4 . V_5 * sizeof( V_79 [ 0 ] ) ,
V_62 ) ;
if ( V_79 == NULL ) {
F_123 ( L_31 ) ;
V_83 = - V_102 ;
goto V_99;
}
if ( V_4 . V_8 -> V_47 ) {
V_80 = F_122 ( V_4 . V_9 * sizeof( V_80 [ 0 ] ) ,
V_62 ) ;
if ( V_80 == NULL ) {
F_123 ( L_32 ) ;
F_99 ( V_79 ) ;
V_79 = NULL ;
V_83 = - V_102 ;
goto V_99;
}
}
for ( V_54 = 0 , V_82 = 0 ; V_54 < V_4 . V_5 ||
V_82 < V_4 . V_9 ; V_54 ++ , V_82 ++ ) {
if ( V_54 >= V_4 . V_5 )
goto V_104;
V_83 = F_124 ( F_83 , & V_4 . V_63 [ V_54 ] ,
V_79 [ V_54 ] ) ;
if ( V_83 )
goto V_99;
V_104:
if ( V_4 . V_8 -> V_47 == NULL || ( V_82 >= V_4 . V_9 ) )
continue;
V_83 = F_124 ( F_92 , & V_4 . V_64 [ V_82 ] ,
V_80 [ V_82 ] ) ;
if ( V_83 )
goto V_99;
}
if ( V_65 > 0 ) {
V_83 = F_124 ( F_100 , NULL ,
V_81 ) ;
if ( V_83 )
goto V_99;
}
F_125 () ;
return 0 ;
V_99:
F_125 () ;
F_104 () ;
return V_83 ;
}
