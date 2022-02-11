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
static int F_42 ( void ) __acquires( T_4 )
{
F_43 ( & T_4 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_11 V_12 ;
const unsigned int V_13 = 50000 ;
if ( ! F_45 ( V_14 ) ) {
if ( V_2 && ! ( F_3 ( V_2 ) %
( V_4 . V_5 * V_13 ) ) ) {
V_10 = V_15 ;
V_12 . V_16 = V_17 - 1 ;
} else
return;
} else {
if ( ! V_2 || ! ( F_3 ( V_2 ) %
( V_4 . V_5 * V_13 * 2 ) ) ) {
V_10 = V_18 ;
V_12 . V_16 = 0 ;
} else
return;
}
F_46 ( V_14 , V_10 , & V_12 ) ;
}
static void F_47 ( struct V_1 * V_2 )
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
static void F_48 ( void ) __releases( T_4 )
{
F_49 ( & T_4 ) ;
}
static int F_50 ( void ) __acquires( T_5 )
{
F_51 ( & T_5 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
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
static void F_53 ( void ) __releases( T_5 )
{
F_54 ( & T_5 ) ;
}
static int F_55 ( void ) __acquires( T_5 )
{
F_56 ( & T_5 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
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
static void F_58 ( void ) __releases( T_5 )
{
F_59 ( & T_5 ) ;
}
void F_60 ( void )
{
F_61 ( F_62 ( & V_19 ) ) ;
}
static int F_63 ( void ) __acquires( V_19 )
{
F_64 ( & V_19 ) ;
return 0 ;
}
static void F_65 ( void ) __releases( V_19 )
{
F_66 ( & V_19 ) ;
}
static int F_67 ( void ) __acquires( V_19 )
{
F_68 ( & V_19 ) ;
return 0 ;
}
static void F_69 ( void ) __releases( V_19 )
{
F_70 ( & V_19 ) ;
}
static int F_71 ( void * V_20 )
{
struct V_21 * V_22 = V_20 ;
static F_72 ( rand ) ;
F_73 ( L_1 ) ;
F_74 ( V_14 , V_23 ) ;
do {
if ( ( F_3 ( & rand ) & 0xfffff ) == 0 )
F_75 ( 1 ) ;
V_4 . V_8 -> V_24 ( & rand ) ;
V_4 . V_8 -> V_25 () ;
if ( F_76 ( V_26 ) )
V_22 -> V_27 ++ ;
V_26 = 1 ;
if ( F_76 ( V_28 ) )
V_22 -> V_27 ++ ;
V_22 -> V_29 ++ ;
V_4 . V_8 -> V_30 ( & rand ) ;
V_26 = 0 ;
V_4 . V_8 -> V_31 () ;
F_77 ( L_2 ) ;
} while ( ! F_78 () );
V_4 . V_8 -> V_24 ( NULL ) ;
F_79 ( L_2 ) ;
return 0 ;
}
static int F_80 ( void * V_20 )
{
struct V_21 * V_32 = V_20 ;
static F_72 ( rand ) ;
F_73 ( L_3 ) ;
F_74 ( V_14 , V_23 ) ;
do {
if ( ( F_3 ( & rand ) & 0xfffff ) == 0 )
F_75 ( 1 ) ;
V_4 . V_8 -> V_33 () ;
V_28 = 1 ;
if ( F_76 ( V_26 ) )
V_32 -> V_27 ++ ;
V_32 -> V_29 ++ ;
V_4 . V_8 -> V_34 ( & rand ) ;
V_28 = 0 ;
V_4 . V_8 -> V_35 () ;
F_77 ( L_4 ) ;
} while ( ! F_78 () );
F_79 ( L_4 ) ;
return 0 ;
}
static void F_81 ( char * V_36 ,
struct V_21 * V_37 , bool V_38 )
{
bool V_39 = 0 ;
int V_40 , V_41 ;
long V_42 = 0 ;
long V_43 = V_37 [ 0 ] . V_29 ;
long long V_44 = 0 ;
V_41 = V_38 ? V_4 . V_5 : V_4 . V_9 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
if ( V_37 [ V_40 ] . V_27 )
V_39 = true ;
V_44 += V_37 [ V_40 ] . V_29 ;
if ( V_42 < V_37 [ V_40 ] . V_27 )
V_42 = V_37 [ V_40 ] . V_27 ;
if ( V_43 > V_37 [ V_40 ] . V_27 )
V_43 = V_37 [ V_40 ] . V_27 ;
}
V_36 += sprintf ( V_36 ,
L_5 ,
V_38 ? L_6 : L_7 ,
V_44 , V_42 , V_43 , V_42 / 2 > V_43 ? L_8 : L_9 ,
V_39 , V_39 ? L_10 : L_9 ) ;
if ( V_39 )
F_82 ( & V_4 . V_45 ) ;
}
static void F_83 ( void )
{
int V_46 = V_4 . V_5 * 200 + 8192 ;
char * V_47 ;
if ( V_4 . V_8 -> V_33 )
V_46 += V_4 . V_9 * 200 + 8192 ;
V_47 = F_84 ( V_46 , V_48 ) ;
if ( ! V_47 ) {
F_85 ( L_11 ,
V_46 ) ;
return;
}
F_81 ( V_47 , V_4 . V_49 , true ) ;
F_86 ( L_12 , V_47 ) ;
F_87 ( V_47 ) ;
if ( V_4 . V_8 -> V_33 ) {
V_47 = F_84 ( V_46 , V_48 ) ;
if ( ! V_47 ) {
F_85 ( L_11 ,
V_46 ) ;
return;
}
F_81 ( V_47 , V_4 . V_50 , false ) ;
F_86 ( L_12 , V_47 ) ;
F_87 ( V_47 ) ;
}
}
static int F_88 ( void * V_20 )
{
F_73 ( L_13 ) ;
do {
F_89 ( V_51 * V_52 ) ;
F_83 () ;
F_90 ( L_14 ) ;
} while ( ! F_78 () );
F_79 ( L_14 ) ;
return 0 ;
}
static inline void
F_91 ( struct V_53 * V_8 ,
const char * V_54 )
{
F_86 ( L_12 V_55
L_15 ,
V_56 , V_54 , V_4 . V_57 ? L_16 : L_9 ,
V_4 . V_5 , V_4 . V_9 , V_51 ,
V_58 , V_59 , V_60 , V_61 ,
V_62 , V_63 ) ;
}
static void F_92 ( void )
{
int V_40 ;
if ( F_93 () )
return;
if ( ! V_4 . V_49 )
goto V_64;
if ( V_65 ) {
for ( V_40 = 0 ; V_40 < V_4 . V_5 ; V_40 ++ )
F_94 ( F_71 ,
V_65 [ V_40 ] ) ;
F_87 ( V_65 ) ;
V_65 = NULL ;
}
if ( V_66 ) {
for ( V_40 = 0 ; V_40 < V_4 . V_9 ; V_40 ++ )
F_94 ( F_80 ,
V_66 [ V_40 ] ) ;
F_87 ( V_66 ) ;
V_66 = NULL ;
}
F_94 ( F_88 , V_67 ) ;
F_83 () ;
if ( F_95 ( & V_4 . V_45 ) )
F_91 ( V_4 . V_8 ,
L_17 ) ;
else if ( F_96 () )
F_91 ( V_4 . V_8 ,
L_18 ) ;
else
F_91 ( V_4 . V_8 ,
L_19 ) ;
V_64:
F_97 () ;
}
static int T_6 F_98 ( void )
{
int V_40 , V_68 ;
int V_69 = 0 ;
static struct V_53 * V_70 [] = {
& V_71 ,
& V_72 , & V_73 ,
& V_74 , & V_75 ,
& V_76 ,
#ifdef F_99
& V_77 ,
#endif
& V_78 ,
& V_79 ,
} ;
if ( ! F_100 ( V_56 , V_58 , & V_80 ) )
return - V_81 ;
for ( V_40 = 0 ; V_40 < F_101 ( V_70 ) ; V_40 ++ ) {
V_4 . V_8 = V_70 [ V_40 ] ;
if ( strcmp ( V_56 , V_4 . V_8 -> V_82 ) == 0 )
break;
}
if ( V_40 == F_101 ( V_70 ) ) {
F_86 ( L_20 ,
V_56 ) ;
F_86 ( L_21 ) ;
for ( V_40 = 0 ; V_40 < F_101 ( V_70 ) ; V_40 ++ )
F_86 ( L_22 , V_70 [ V_40 ] -> V_82 ) ;
F_86 ( L_23 ) ;
V_69 = - V_83 ;
goto V_84;
}
if ( V_4 . V_8 -> V_85 )
V_4 . V_8 -> V_85 () ;
if ( V_86 >= 0 )
V_4 . V_5 = V_86 ;
else
V_4 . V_5 = 2 * F_102 () ;
#ifdef F_103
if ( strncmp ( V_56 , L_24 , 5 ) == 0 )
V_4 . V_57 = true ;
#endif
#ifdef F_104
if ( strncmp ( V_56 , L_25 , 7 ) == 0 )
V_4 . V_57 = true ;
#endif
#ifdef F_105
if ( ( strncmp ( V_56 , L_26 , 4 ) == 0 ) ||
( strncmp ( V_56 , L_27 , 7 ) == 0 ) )
V_4 . V_57 = true ;
#endif
V_26 = 0 ;
V_4 . V_49 = F_84 ( sizeof( * V_4 . V_49 ) * V_4 . V_5 , V_48 ) ;
if ( V_4 . V_49 == NULL ) {
F_73 ( L_28 ) ;
V_69 = - V_87 ;
goto V_84;
}
for ( V_40 = 0 ; V_40 < V_4 . V_5 ; V_40 ++ ) {
V_4 . V_49 [ V_40 ] . V_27 = 0 ;
V_4 . V_49 [ V_40 ] . V_29 = 0 ;
}
if ( V_4 . V_8 -> V_33 ) {
if ( V_88 >= 0 )
V_4 . V_9 = V_88 ;
else {
if ( V_86 < 0 )
V_4 . V_5 = F_102 () ;
V_4 . V_9 = V_4 . V_5 ;
}
V_28 = 0 ;
V_4 . V_50 = F_84 ( sizeof( * V_4 . V_50 ) * V_4 . V_9 , V_48 ) ;
if ( V_4 . V_50 == NULL ) {
F_73 ( L_29 ) ;
V_69 = - V_87 ;
F_87 ( V_4 . V_49 ) ;
V_4 . V_49 = NULL ;
goto V_84;
}
for ( V_40 = 0 ; V_40 < V_4 . V_9 ; V_40 ++ ) {
V_4 . V_50 [ V_40 ] . V_27 = 0 ;
V_4 . V_50 [ V_40 ] . V_29 = 0 ;
}
}
F_91 ( V_4 . V_8 , L_30 ) ;
if ( V_62 > 0 ) {
V_69 = F_106 ( V_63 * V_52 ,
V_62 * V_52 ) ;
if ( V_69 )
goto V_84;
}
if ( V_59 > 0 ) {
V_69 = F_107 ( V_59 ) ;
if ( V_69 )
goto V_84;
}
if ( V_61 > 0 ) {
V_69 = F_108 ( V_61 ,
F_92 ) ;
if ( V_69 )
goto V_84;
}
if ( V_60 > 0 ) {
V_69 = F_109 ( V_60 ) ;
if ( V_69 )
goto V_84;
}
V_65 = F_110 ( V_4 . V_5 * sizeof( V_65 [ 0 ] ) ,
V_48 ) ;
if ( V_65 == NULL ) {
F_111 ( L_31 ) ;
V_69 = - V_87 ;
goto V_84;
}
if ( V_4 . V_8 -> V_33 ) {
V_66 = F_110 ( V_4 . V_9 * sizeof( V_66 [ 0 ] ) ,
V_48 ) ;
if ( V_66 == NULL ) {
F_111 ( L_32 ) ;
V_69 = - V_87 ;
goto V_84;
}
}
for ( V_40 = 0 , V_68 = 0 ; V_40 < V_4 . V_5 ||
V_68 < V_4 . V_9 ; V_40 ++ , V_68 ++ ) {
if ( V_40 >= V_4 . V_5 )
goto V_89;
V_69 = F_112 ( F_71 , & V_4 . V_49 [ V_40 ] ,
V_65 [ V_40 ] ) ;
if ( V_69 )
goto V_84;
V_89:
if ( V_4 . V_8 -> V_33 == NULL || ( V_68 >= V_4 . V_9 ) )
continue;
V_69 = F_112 ( F_80 , & V_4 . V_50 [ V_68 ] ,
V_66 [ V_68 ] ) ;
if ( V_69 )
goto V_84;
}
if ( V_51 > 0 ) {
V_69 = F_112 ( F_88 , NULL ,
V_67 ) ;
if ( V_69 )
goto V_84;
}
F_113 () ;
return 0 ;
V_84:
F_113 () ;
F_92 () ;
return V_69 ;
}
