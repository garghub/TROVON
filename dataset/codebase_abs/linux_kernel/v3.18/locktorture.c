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
const unsigned long V_9 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_9 ) ) )
F_4 ( V_9 ) ;
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
const unsigned long V_9 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_10 * 2000 * V_9 ) ) )
F_4 ( V_9 ) ;
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
F_31 ( & T_2 , V_4 . V_8 -> V_7 ) ;
}
static int F_35 ( void ) __acquires( T_3 )
{
F_36 ( & T_3 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
const unsigned long V_9 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_9 ) ) )
F_4 ( V_9 * 5 ) ;
else
F_4 ( V_9 / 5 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_5 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_38 ( void ) __releases( T_3 )
{
F_39 ( & T_3 ) ;
}
static int F_40 ( void ) __acquires( T_4 )
{
F_41 ( & T_4 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
const unsigned long V_9 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_9 ) ) )
F_4 ( V_9 * 10 ) ;
else
F_4 ( V_9 / 10 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_5 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_43 ( void ) __releases( T_4 )
{
F_44 ( & T_4 ) ;
}
static int F_45 ( void ) __acquires( T_4 )
{
F_46 ( & T_4 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
const unsigned long V_9 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 . V_5 * 2000 * V_9 ) ) )
F_4 ( V_9 * 2 ) ;
else
F_4 ( V_9 / 2 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 . V_10 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_48 ( void ) __releases( T_4 )
{
F_49 ( & T_4 ) ;
}
static int F_50 ( void * V_11 )
{
struct V_12 * V_13 = V_11 ;
static F_51 ( rand ) ;
F_52 ( L_1 ) ;
F_53 ( V_14 , V_15 ) ;
do {
if ( ( F_3 ( & rand ) & 0xfffff ) == 0 )
F_54 ( 1 ) ;
V_4 . V_8 -> V_16 () ;
if ( F_55 ( V_17 ) )
V_13 -> V_18 ++ ;
V_17 = 1 ;
if ( F_55 ( V_19 ) )
V_13 -> V_18 ++ ;
V_13 -> V_20 ++ ;
V_4 . V_8 -> V_21 ( & rand ) ;
V_17 = 0 ;
V_4 . V_8 -> V_22 () ;
F_56 ( L_2 ) ;
} while ( ! F_57 () );
F_58 ( L_2 ) ;
return 0 ;
}
static int F_59 ( void * V_11 )
{
struct V_12 * V_23 = V_11 ;
static F_51 ( rand ) ;
F_52 ( L_3 ) ;
F_53 ( V_14 , V_15 ) ;
do {
if ( ( F_3 ( & rand ) & 0xfffff ) == 0 )
F_54 ( 1 ) ;
V_4 . V_8 -> V_24 () ;
V_19 = 1 ;
if ( F_55 ( V_17 ) )
V_23 -> V_18 ++ ;
V_23 -> V_20 ++ ;
V_4 . V_8 -> V_25 ( & rand ) ;
V_19 = 0 ;
V_4 . V_8 -> V_26 () ;
F_56 ( L_4 ) ;
} while ( ! F_57 () );
F_58 ( L_4 ) ;
return 0 ;
}
static void F_60 ( char * V_27 ,
struct V_12 * V_28 , bool V_29 )
{
bool V_30 = 0 ;
int V_31 , V_32 ;
long V_33 = 0 ;
long V_34 = V_28 [ 0 ] . V_20 ;
long long V_35 = 0 ;
V_32 = V_29 ? V_4 . V_5 : V_4 . V_10 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
if ( V_28 [ V_31 ] . V_18 )
V_30 = true ;
V_35 += V_28 [ V_31 ] . V_20 ;
if ( V_33 < V_28 [ V_31 ] . V_18 )
V_33 = V_28 [ V_31 ] . V_18 ;
if ( V_34 > V_28 [ V_31 ] . V_18 )
V_34 = V_28 [ V_31 ] . V_18 ;
}
V_27 += sprintf ( V_27 ,
L_5 ,
V_29 ? L_6 : L_7 ,
V_35 , V_33 , V_34 , V_33 / 2 > V_34 ? L_8 : L_9 ,
V_30 , V_30 ? L_10 : L_9 ) ;
if ( V_30 )
F_61 ( & V_4 . V_36 ) ;
}
static void F_62 ( void )
{
int V_37 = V_4 . V_5 * 200 + 8192 ;
char * V_38 ;
if ( V_4 . V_8 -> V_24 )
V_37 += V_4 . V_10 * 200 + 8192 ;
V_38 = F_63 ( V_37 , V_39 ) ;
if ( ! V_38 ) {
F_64 ( L_11 ,
V_37 ) ;
return;
}
F_60 ( V_38 , V_4 . V_40 , true ) ;
F_65 ( L_12 , V_38 ) ;
F_66 ( V_38 ) ;
if ( V_4 . V_8 -> V_24 ) {
V_38 = F_63 ( V_37 , V_39 ) ;
if ( ! V_38 ) {
F_64 ( L_11 ,
V_37 ) ;
return;
}
F_60 ( V_38 , V_4 . V_41 , false ) ;
F_65 ( L_12 , V_38 ) ;
F_66 ( V_38 ) ;
}
}
static int F_67 ( void * V_11 )
{
F_52 ( L_13 ) ;
do {
F_68 ( V_42 * V_43 ) ;
F_62 () ;
F_69 ( L_14 ) ;
} while ( ! F_57 () );
F_58 ( L_14 ) ;
return 0 ;
}
static inline void
F_70 ( struct V_44 * V_8 ,
const char * V_45 )
{
F_65 ( L_12 V_46
L_15 ,
V_47 , V_45 , V_4 . V_48 ? L_16 : L_9 ,
V_4 . V_5 , V_4 . V_10 , V_42 ,
V_49 , V_50 , V_51 , V_52 ,
V_53 , V_54 ) ;
}
static void F_71 ( void )
{
int V_31 ;
if ( F_72 () )
return;
if ( V_55 ) {
for ( V_31 = 0 ; V_31 < V_4 . V_5 ; V_31 ++ )
F_73 ( F_50 ,
V_55 [ V_31 ] ) ;
F_66 ( V_55 ) ;
V_55 = NULL ;
}
if ( V_56 ) {
for ( V_31 = 0 ; V_31 < V_4 . V_10 ; V_31 ++ )
F_73 ( F_59 ,
V_56 [ V_31 ] ) ;
F_66 ( V_56 ) ;
V_56 = NULL ;
}
F_73 ( F_67 , V_57 ) ;
F_62 () ;
if ( F_74 ( & V_4 . V_36 ) )
F_70 ( V_4 . V_8 ,
L_17 ) ;
else if ( F_75 () )
F_70 ( V_4 . V_8 ,
L_18 ) ;
else
F_70 ( V_4 . V_8 ,
L_19 ) ;
F_76 () ;
}
static int T_5 F_77 ( void )
{
int V_31 , V_58 ;
int V_59 = 0 ;
static struct V_44 * V_60 [] = {
& V_61 ,
& V_62 , & V_63 ,
& V_64 , & V_65 ,
& V_66 ,
& V_67 ,
} ;
if ( ! F_78 ( V_47 , V_49 , & V_68 ) )
return - V_69 ;
for ( V_31 = 0 ; V_31 < F_79 ( V_60 ) ; V_31 ++ ) {
V_4 . V_8 = V_60 [ V_31 ] ;
if ( strcmp ( V_47 , V_4 . V_8 -> V_70 ) == 0 )
break;
}
if ( V_31 == F_79 ( V_60 ) ) {
F_65 ( L_20 ,
V_47 ) ;
F_65 ( L_21 ) ;
for ( V_31 = 0 ; V_31 < F_79 ( V_60 ) ; V_31 ++ )
F_65 ( L_22 , V_60 [ V_31 ] -> V_70 ) ;
F_65 ( L_23 ) ;
F_80 () ;
return - V_71 ;
}
if ( V_4 . V_8 -> V_72 )
V_4 . V_8 -> V_72 () ;
if ( V_73 >= 0 )
V_4 . V_5 = V_73 ;
else
V_4 . V_5 = 2 * F_81 () ;
#ifdef F_82
if ( strncmp ( V_47 , L_24 , 5 ) == 0 )
V_4 . V_48 = true ;
#endif
#ifdef F_83
if ( ( strncmp ( V_47 , L_25 , 4 ) == 0 ) ||
( strncmp ( V_47 , L_26 , 7 ) == 0 ) )
V_4 . V_48 = true ;
#endif
V_17 = 0 ;
V_4 . V_40 = F_63 ( sizeof( * V_4 . V_40 ) * V_4 . V_5 , V_39 ) ;
if ( V_4 . V_40 == NULL ) {
F_52 ( L_27 ) ;
V_59 = - V_74 ;
goto V_75;
}
for ( V_31 = 0 ; V_31 < V_4 . V_5 ; V_31 ++ ) {
V_4 . V_40 [ V_31 ] . V_18 = 0 ;
V_4 . V_40 [ V_31 ] . V_20 = 0 ;
}
if ( V_4 . V_8 -> V_24 ) {
if ( V_76 >= 0 )
V_4 . V_10 = V_76 ;
else {
if ( V_73 < 0 )
V_4 . V_5 = F_81 () ;
V_4 . V_10 = V_4 . V_5 ;
}
V_19 = 0 ;
V_4 . V_41 = F_63 ( sizeof( * V_4 . V_41 ) * V_4 . V_10 , V_39 ) ;
if ( V_4 . V_41 == NULL ) {
F_52 ( L_28 ) ;
V_59 = - V_74 ;
F_66 ( V_4 . V_40 ) ;
goto V_75;
}
for ( V_31 = 0 ; V_31 < V_4 . V_10 ; V_31 ++ ) {
V_4 . V_41 [ V_31 ] . V_18 = 0 ;
V_4 . V_41 [ V_31 ] . V_20 = 0 ;
}
}
F_70 ( V_4 . V_8 , L_29 ) ;
if ( V_53 > 0 ) {
V_59 = F_84 ( V_54 * V_43 ,
V_53 * V_43 ) ;
if ( V_59 )
goto V_75;
}
if ( V_50 > 0 ) {
V_59 = F_85 ( V_50 ) ;
if ( V_59 )
goto V_75;
}
if ( V_52 > 0 ) {
V_59 = F_86 ( V_52 ,
F_71 ) ;
if ( V_59 )
goto V_75;
}
if ( V_51 > 0 ) {
V_59 = F_87 ( V_51 ) ;
if ( V_59 )
goto V_75;
}
V_55 = F_88 ( V_4 . V_5 * sizeof( V_55 [ 0 ] ) ,
V_39 ) ;
if ( V_55 == NULL ) {
F_89 ( L_30 ) ;
V_59 = - V_74 ;
goto V_75;
}
if ( V_4 . V_8 -> V_24 ) {
V_56 = F_88 ( V_4 . V_10 * sizeof( V_56 [ 0 ] ) ,
V_39 ) ;
if ( V_56 == NULL ) {
F_89 ( L_31 ) ;
V_59 = - V_74 ;
goto V_75;
}
}
for ( V_31 = 0 , V_58 = 0 ; V_31 < V_4 . V_5 ||
V_58 < V_4 . V_10 ; V_31 ++ , V_58 ++ ) {
if ( V_31 >= V_4 . V_5 )
goto V_77;
V_59 = F_90 ( F_50 , & V_4 . V_40 [ V_31 ] ,
V_55 [ V_31 ] ) ;
if ( V_59 )
goto V_75;
V_77:
if ( V_4 . V_8 -> V_24 == NULL || ( V_58 >= V_4 . V_10 ) )
continue;
V_59 = F_90 ( F_59 , & V_4 . V_41 [ V_58 ] ,
V_56 [ V_58 ] ) ;
if ( V_59 )
goto V_75;
}
if ( V_42 > 0 ) {
V_59 = F_90 ( F_67 , NULL ,
V_57 ) ;
if ( V_59 )
goto V_75;
}
F_80 () ;
return 0 ;
V_75:
F_80 () ;
F_71 () ;
return V_59 ;
}
