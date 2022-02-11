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
static int F_8 ( void ) __acquires( T_1 )
{
F_9 ( & T_1 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
const unsigned long V_6 = 2 ;
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2 * V_6 ) ) )
F_11 ( V_6 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_5 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_12 ( void ) __releases( T_1 )
{
F_13 ( & T_1 ) ;
}
static int F_14 ( void )
__acquires( T_1 )
{
unsigned long V_7 ;
F_15 ( & T_1 , V_7 ) ;
V_4 . V_8 -> V_7 = V_7 ;
return 0 ;
}
static void F_16 ( void )
__releases( T_1 )
{
F_17 ( & T_1 , V_4 . V_8 -> V_7 ) ;
}
static int F_18 ( void ) __acquires( T_2 )
{
F_19 ( & T_2 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
const unsigned long V_6 = 2 ;
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
else
F_11 ( V_6 ) ;
}
static void F_21 ( void ) __releases( T_2 )
{
F_22 ( & T_2 ) ;
}
static int F_23 ( void ) __acquires( T_2 )
{
F_24 ( & T_2 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
const unsigned long V_6 = 10 ;
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_9 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
else
F_11 ( V_6 ) ;
}
static void F_26 ( void ) __releases( T_2 )
{
F_27 ( & T_2 ) ;
}
static int F_28 ( void ) __acquires( T_2 )
{
unsigned long V_7 ;
F_29 ( & T_2 , V_7 ) ;
V_4 . V_8 -> V_7 = V_7 ;
return 0 ;
}
static void F_30 ( void )
__releases( T_2 )
{
F_31 ( & T_2 , V_4 . V_8 -> V_7 ) ;
}
static int F_32 ( void ) __acquires( T_2 )
{
unsigned long V_7 ;
F_33 ( & T_2 , V_7 ) ;
V_4 . V_8 -> V_7 = V_7 ;
return 0 ;
}
static void F_34 ( void )
__releases( T_2 )
{
F_35 ( & T_2 , V_4 . V_8 -> V_7 ) ;
}
static int F_36 ( void ) __acquires( T_3 )
{
F_37 ( & T_3 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
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
static void F_39 ( void ) __releases( T_3 )
{
F_40 ( & T_3 ) ;
}
static int F_41 ( void ) __acquires( T_4 )
{
F_42 ( & T_4 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
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
static void F_44 ( void ) __releases( T_4 )
{
F_45 ( & T_4 ) ;
}
static int F_46 ( void ) __acquires( T_4 )
{
F_47 ( & T_4 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
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
static void F_49 ( void ) __releases( T_4 )
{
F_50 ( & T_4 ) ;
}
static int F_51 ( void * V_10 )
{
struct V_11 * V_12 = V_10 ;
static F_52 ( rand ) ;
F_53 ( L_1 ) ;
F_54 ( V_13 , V_14 ) ;
do {
if ( ( F_3 ( & rand ) & 0xfffff ) == 0 )
F_55 ( 1 ) ;
V_4 . V_8 -> V_15 () ;
if ( F_56 ( V_16 ) )
V_12 -> V_17 ++ ;
V_16 = 1 ;
if ( F_56 ( V_18 ) )
V_12 -> V_17 ++ ;
V_12 -> V_19 ++ ;
V_4 . V_8 -> V_20 ( & rand ) ;
V_16 = 0 ;
V_4 . V_8 -> V_21 () ;
F_57 ( L_2 ) ;
} while ( ! F_58 () );
F_59 ( L_2 ) ;
return 0 ;
}
static int F_60 ( void * V_10 )
{
struct V_11 * V_22 = V_10 ;
static F_52 ( rand ) ;
F_53 ( L_3 ) ;
F_54 ( V_13 , V_14 ) ;
do {
if ( ( F_3 ( & rand ) & 0xfffff ) == 0 )
F_55 ( 1 ) ;
V_4 . V_8 -> V_23 () ;
V_18 = 1 ;
if ( F_56 ( V_16 ) )
V_22 -> V_17 ++ ;
V_22 -> V_19 ++ ;
V_4 . V_8 -> V_24 ( & rand ) ;
V_18 = 0 ;
V_4 . V_8 -> V_25 () ;
F_57 ( L_4 ) ;
} while ( ! F_58 () );
F_59 ( L_4 ) ;
return 0 ;
}
static void F_61 ( char * V_26 ,
struct V_11 * V_27 , bool V_28 )
{
bool V_29 = 0 ;
int V_30 , V_31 ;
long V_32 = 0 ;
long V_33 = V_27 [ 0 ] . V_19 ;
long long V_34 = 0 ;
V_31 = V_28 ? V_4 . V_5 : V_4 . V_9 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
if ( V_27 [ V_30 ] . V_17 )
V_29 = true ;
V_34 += V_27 [ V_30 ] . V_19 ;
if ( V_32 < V_27 [ V_30 ] . V_17 )
V_32 = V_27 [ V_30 ] . V_17 ;
if ( V_33 > V_27 [ V_30 ] . V_17 )
V_33 = V_27 [ V_30 ] . V_17 ;
}
V_26 += sprintf ( V_26 ,
L_5 ,
V_28 ? L_6 : L_7 ,
V_34 , V_32 , V_33 , V_32 / 2 > V_33 ? L_8 : L_9 ,
V_29 , V_29 ? L_10 : L_9 ) ;
if ( V_29 )
F_62 ( & V_4 . V_35 ) ;
}
static void F_63 ( void )
{
int V_36 = V_4 . V_5 * 200 + 8192 ;
char * V_37 ;
if ( V_4 . V_8 -> V_23 )
V_36 += V_4 . V_9 * 200 + 8192 ;
V_37 = F_64 ( V_36 , V_38 ) ;
if ( ! V_37 ) {
F_65 ( L_11 ,
V_36 ) ;
return;
}
F_61 ( V_37 , V_4 . V_39 , true ) ;
F_66 ( L_12 , V_37 ) ;
F_67 ( V_37 ) ;
if ( V_4 . V_8 -> V_23 ) {
V_37 = F_64 ( V_36 , V_38 ) ;
if ( ! V_37 ) {
F_65 ( L_11 ,
V_36 ) ;
return;
}
F_61 ( V_37 , V_4 . V_40 , false ) ;
F_66 ( L_12 , V_37 ) ;
F_67 ( V_37 ) ;
}
}
static int F_68 ( void * V_10 )
{
F_53 ( L_13 ) ;
do {
F_69 ( V_41 * V_42 ) ;
F_63 () ;
F_70 ( L_14 ) ;
} while ( ! F_58 () );
F_59 ( L_14 ) ;
return 0 ;
}
static inline void
F_71 ( struct V_43 * V_8 ,
const char * V_44 )
{
F_66 ( L_12 V_45
L_15 ,
V_46 , V_44 , V_4 . V_47 ? L_16 : L_9 ,
V_4 . V_5 , V_4 . V_9 , V_41 ,
V_48 , V_49 , V_50 , V_51 ,
V_52 , V_53 ) ;
}
static void F_72 ( void )
{
int V_30 ;
if ( F_73 () )
return;
if ( V_54 ) {
for ( V_30 = 0 ; V_30 < V_4 . V_5 ; V_30 ++ )
F_74 ( F_51 ,
V_54 [ V_30 ] ) ;
F_67 ( V_54 ) ;
V_54 = NULL ;
}
if ( V_55 ) {
for ( V_30 = 0 ; V_30 < V_4 . V_9 ; V_30 ++ )
F_74 ( F_60 ,
V_55 [ V_30 ] ) ;
F_67 ( V_55 ) ;
V_55 = NULL ;
}
F_74 ( F_68 , V_56 ) ;
F_63 () ;
if ( F_75 ( & V_4 . V_35 ) )
F_71 ( V_4 . V_8 ,
L_17 ) ;
else if ( F_76 () )
F_71 ( V_4 . V_8 ,
L_18 ) ;
else
F_71 ( V_4 . V_8 ,
L_19 ) ;
F_77 () ;
}
static int T_5 F_78 ( void )
{
int V_30 , V_57 ;
int V_58 = 0 ;
static struct V_43 * V_59 [] = {
& V_60 ,
& V_61 , & V_62 ,
& V_63 , & V_64 ,
& V_65 ,
& V_66 ,
} ;
if ( ! F_79 ( V_46 , V_48 , & V_67 ) )
return - V_68 ;
for ( V_30 = 0 ; V_30 < F_80 ( V_59 ) ; V_30 ++ ) {
V_4 . V_8 = V_59 [ V_30 ] ;
if ( strcmp ( V_46 , V_4 . V_8 -> V_69 ) == 0 )
break;
}
if ( V_30 == F_80 ( V_59 ) ) {
F_66 ( L_20 ,
V_46 ) ;
F_66 ( L_21 ) ;
for ( V_30 = 0 ; V_30 < F_80 ( V_59 ) ; V_30 ++ )
F_66 ( L_22 , V_59 [ V_30 ] -> V_69 ) ;
F_66 ( L_23 ) ;
F_81 () ;
return - V_70 ;
}
if ( V_4 . V_8 -> V_71 )
V_4 . V_8 -> V_71 () ;
if ( V_72 >= 0 )
V_4 . V_5 = V_72 ;
else
V_4 . V_5 = 2 * F_82 () ;
#ifdef F_83
if ( strncmp ( V_46 , L_24 , 5 ) == 0 )
V_4 . V_47 = true ;
#endif
#ifdef F_84
if ( ( strncmp ( V_46 , L_25 , 4 ) == 0 ) ||
( strncmp ( V_46 , L_26 , 7 ) == 0 ) )
V_4 . V_47 = true ;
#endif
V_16 = 0 ;
V_4 . V_39 = F_64 ( sizeof( * V_4 . V_39 ) * V_4 . V_5 , V_38 ) ;
if ( V_4 . V_39 == NULL ) {
F_53 ( L_27 ) ;
V_58 = - V_73 ;
goto V_74;
}
for ( V_30 = 0 ; V_30 < V_4 . V_5 ; V_30 ++ ) {
V_4 . V_39 [ V_30 ] . V_17 = 0 ;
V_4 . V_39 [ V_30 ] . V_19 = 0 ;
}
if ( V_4 . V_8 -> V_23 ) {
if ( V_75 >= 0 )
V_4 . V_9 = V_75 ;
else {
if ( V_72 < 0 )
V_4 . V_5 = F_82 () ;
V_4 . V_9 = V_4 . V_5 ;
}
V_18 = 0 ;
V_4 . V_40 = F_64 ( sizeof( * V_4 . V_40 ) * V_4 . V_9 , V_38 ) ;
if ( V_4 . V_40 == NULL ) {
F_53 ( L_28 ) ;
V_58 = - V_73 ;
F_67 ( V_4 . V_39 ) ;
goto V_74;
}
for ( V_30 = 0 ; V_30 < V_4 . V_9 ; V_30 ++ ) {
V_4 . V_40 [ V_30 ] . V_17 = 0 ;
V_4 . V_40 [ V_30 ] . V_19 = 0 ;
}
}
F_71 ( V_4 . V_8 , L_29 ) ;
if ( V_52 > 0 ) {
V_58 = F_85 ( V_53 * V_42 ,
V_52 * V_42 ) ;
if ( V_58 )
goto V_74;
}
if ( V_49 > 0 ) {
V_58 = F_86 ( V_49 ) ;
if ( V_58 )
goto V_74;
}
if ( V_51 > 0 ) {
V_58 = F_87 ( V_51 ,
F_72 ) ;
if ( V_58 )
goto V_74;
}
if ( V_50 > 0 ) {
V_58 = F_88 ( V_50 ) ;
if ( V_58 )
goto V_74;
}
V_54 = F_89 ( V_4 . V_5 * sizeof( V_54 [ 0 ] ) ,
V_38 ) ;
if ( V_54 == NULL ) {
F_90 ( L_30 ) ;
V_58 = - V_73 ;
goto V_74;
}
if ( V_4 . V_8 -> V_23 ) {
V_55 = F_89 ( V_4 . V_9 * sizeof( V_55 [ 0 ] ) ,
V_38 ) ;
if ( V_55 == NULL ) {
F_90 ( L_31 ) ;
V_58 = - V_73 ;
goto V_74;
}
}
for ( V_30 = 0 , V_57 = 0 ; V_30 < V_4 . V_5 ||
V_57 < V_4 . V_9 ; V_30 ++ , V_57 ++ ) {
if ( V_30 >= V_4 . V_5 )
goto V_76;
V_58 = F_91 ( F_51 , & V_4 . V_39 [ V_30 ] ,
V_54 [ V_30 ] ) ;
if ( V_58 )
goto V_74;
V_76:
if ( V_4 . V_8 -> V_23 == NULL || ( V_57 >= V_4 . V_9 ) )
continue;
V_58 = F_91 ( F_60 , & V_4 . V_40 [ V_57 ] ,
V_55 [ V_57 ] ) ;
if ( V_58 )
goto V_74;
}
if ( V_41 > 0 ) {
V_58 = F_91 ( F_68 , NULL ,
V_56 ) ;
if ( V_58 )
goto V_74;
}
F_81 () ;
return 0 ;
V_74:
F_81 () ;
F_72 () ;
return V_58 ;
}
