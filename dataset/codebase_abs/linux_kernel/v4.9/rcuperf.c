static int F_1 ( void ) __acquires( T_1 )
{
F_2 () ;
return 0 ;
}
static void F_3 ( int V_1 ) __releases( T_1 )
{
F_4 () ;
}
static unsigned long T_2 F_5 ( void )
{
return 0 ;
}
static void F_6 ( void )
{
}
static int F_7 ( void ) __acquires( T_3 )
{
F_8 () ;
return 0 ;
}
static void F_9 ( int V_1 ) __releases( T_3 )
{
F_10 () ;
}
static int F_11 ( void ) __acquires( T_4 )
{
return F_12 ( T_4 ) ;
}
static void F_13 ( int V_1 ) __releases( T_4 )
{
F_14 ( T_4 , V_1 ) ;
}
static unsigned long F_15 ( void )
{
return F_16 ( T_4 ) ;
}
static void F_17 ( void )
{
F_18 ( T_4 ) ;
}
static void F_19 ( void )
{
F_20 ( T_4 ) ;
}
static int F_21 ( void )
{
F_22 () ;
return 0 ;
}
static void F_23 ( int V_1 )
{
F_24 () ;
}
static int F_25 ( void )
{
return 0 ;
}
static void F_26 ( int V_1 )
{
}
static bool T_2 F_27 ( void )
{
return V_2 == & V_3 ;
}
static bool T_2 F_27 ( void )
{
return false ;
}
static void F_28 ( void )
{
F_29 () ;
if ( F_30 ( & V_4 ) < V_5 )
return;
while ( ! F_31 () )
F_32 ( 1 ) ;
}
static int
F_33 ( void * V_6 )
{
unsigned long V_7 ;
int V_1 ;
long V_8 = ( long ) V_6 ;
F_34 ( L_1 ) ;
F_35 ( V_9 , F_36 ( V_8 % V_10 ) ) ;
F_37 ( V_9 , V_11 ) ;
F_38 ( & V_12 ) ;
do {
F_39 ( V_7 ) ;
V_1 = V_2 -> V_13 () ;
V_2 -> V_14 ( V_1 ) ;
F_40 ( V_7 ) ;
F_28 () ;
} while ( ! F_31 () );
F_41 ( L_2 ) ;
return 0 ;
}
static int
F_42 ( void * V_6 )
{
int V_15 = 0 ;
int V_16 ;
long V_8 = ( long ) V_6 ;
struct V_17 V_18 ;
bool V_19 = false , V_20 = false , V_21 = false ;
T_5 V_22 ;
T_5 * V_23 ;
T_5 * V_24 = V_25 [ V_8 ] ;
F_34 ( L_3 ) ;
F_43 ( ! V_24 ) ;
F_35 ( V_9 , F_36 ( V_8 % V_10 ) ) ;
V_18 . V_26 = 1 ;
F_44 ( V_9 , V_27 , & V_18 ) ;
if ( V_28 )
F_32 ( V_28 * V_29 ) ;
V_22 = F_45 () ;
if ( F_46 ( & V_30 ) >= V_5 ) {
V_31 = V_22 ;
if ( V_32 ) {
V_33 =
V_2 -> V_34 () / 2 ;
} else {
V_33 =
V_2 -> V_35 () ;
}
}
do {
V_23 = & V_24 [ V_15 ] ;
* V_23 = F_45 () ;
if ( V_32 ) {
V_36 = V_37 ;
V_2 -> V_38 () ;
} else {
V_36 = V_39 ;
V_2 -> V_40 () ;
}
V_36 = V_41 ;
V_22 = F_45 () ;
* V_23 = V_22 - * V_23 ;
V_16 = V_15 ;
if ( ! V_19 &&
F_30 ( & V_30 ) >= V_5 )
V_19 = true ;
if ( ! V_20 && V_15 >= V_42 ) {
V_20 = true ;
V_18 . V_26 = 0 ;
F_44 ( V_9 ,
V_43 , & V_18 ) ;
F_47 ( L_4 ,
V_44 , V_45 , V_8 , V_42 ) ;
if ( F_46 ( & V_4 ) >=
V_5 ) {
F_48 ( 10 ) ;
F_49 ( V_46 ) ;
F_50 ( L_5 ) ;
V_47 = V_22 ;
if ( V_32 ) {
V_48 =
V_2 -> V_34 () / 2 ;
} else {
V_48 =
V_2 -> V_35 () ;
}
if ( V_49 ) {
F_51 () ;
F_52 ( & V_50 ) ;
}
}
}
if ( V_20 && ! V_21 &&
F_30 ( & V_4 ) >= V_5 )
V_21 = true ;
if ( V_19 && ! V_21 && V_15 < V_51 - 1 )
V_15 ++ ;
F_28 () ;
} while ( ! F_31 () );
V_36 = V_52 ;
V_53 [ V_8 ] = V_16 ;
F_41 ( L_6 ) ;
return 0 ;
}
static inline void
F_53 ( struct V_54 * V_2 , const char * V_55 )
{
F_47 ( L_7 V_45
L_8 ,
V_44 , V_55 , V_56 , V_5 , V_57 , V_49 ) ;
}
static void
F_54 ( void )
{
int V_15 ;
int V_58 ;
int V_59 = 0 ;
T_5 * V_23 ;
T_5 * V_24 ;
if ( F_55 () )
return;
if ( V_60 ) {
for ( V_15 = 0 ; V_15 < V_56 ; V_15 ++ )
F_56 ( F_33 ,
V_60 [ V_15 ] ) ;
F_57 ( V_60 ) ;
}
if ( V_61 ) {
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ ) {
F_56 ( F_42 ,
V_61 [ V_15 ] ) ;
if ( ! V_53 )
continue;
V_58 = V_53 [ V_15 ] ;
F_47 ( L_9 ,
V_44 , V_45 , V_15 , V_58 ) ;
V_59 += V_58 ;
}
F_47 ( L_10 ,
V_44 , V_45 ,
V_31 , V_47 ,
V_47 -
V_31 ,
V_59 ,
V_48 -
V_33 ) ;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ ) {
if ( ! V_25 )
break;
if ( ! V_53 )
continue;
V_24 = V_25 [ V_15 ] ;
if ( ! V_24 )
continue;
for ( V_58 = 0 ; V_58 <= V_53 [ V_15 ] ; V_58 ++ ) {
V_23 = & V_24 [ V_58 ] ;
F_47 ( L_11 ,
V_44 , V_45 ,
V_15 , V_58 , * V_23 ) ;
if ( V_58 % 100 == 0 )
F_32 ( 1 ) ;
}
F_57 ( V_25 [ V_15 ] ) ;
}
F_57 ( V_61 ) ;
F_57 ( V_25 ) ;
F_57 ( V_53 ) ;
}
if ( V_2 -> V_62 != NULL )
V_2 -> V_62 () ;
F_58 () ;
}
static int F_59 ( int V_63 )
{
int V_64 ;
if ( V_63 >= 0 ) {
V_64 = V_63 ;
} else {
V_64 = F_60 () + 1 + V_63 ;
if ( V_64 <= 0 )
V_64 = 1 ;
}
return V_64 ;
}
static int
F_61 ( void * V_6 )
{
do {
F_62 ( V_50 ,
F_30 ( & V_4 ) >=
V_5 ) ;
} while ( F_30 ( & V_4 ) < V_5 );
F_51 () ;
F_54 () ;
F_63 () ;
return - V_65 ;
}
static int T_6
F_64 ( void )
{
long V_15 ;
int V_66 = 0 ;
static struct V_54 * V_67 [] = {
& V_68 , & V_69 , & V_70 , & V_71 ,
V_72
} ;
if ( ! F_65 ( V_44 , V_57 , & V_73 ) )
return - V_74 ;
for ( V_15 = 0 ; V_15 < F_66 ( V_67 ) ; V_15 ++ ) {
V_2 = V_67 [ V_15 ] ;
if ( strcmp ( V_44 , V_2 -> V_75 ) == 0 )
break;
}
if ( V_15 == F_66 ( V_67 ) ) {
F_47 ( L_12 ,
V_44 ) ;
F_47 ( L_13 ) ;
for ( V_15 = 0 ; V_15 < F_66 ( V_67 ) ; V_15 ++ )
F_47 ( L_14 , V_67 [ V_15 ] -> V_75 ) ;
F_47 ( L_15 ) ;
V_66 = - V_65 ;
goto V_76;
}
if ( V_2 -> V_77 )
V_2 -> V_77 () ;
V_5 = F_59 ( V_78 ) ;
V_56 = F_59 ( V_79 ) ;
F_67 ( & V_12 , 0 ) ;
F_67 ( & V_30 , 0 ) ;
F_67 ( & V_4 , 0 ) ;
F_53 ( V_2 , L_16 ) ;
if ( V_49 ) {
F_68 ( & V_50 ) ;
V_66 = F_69 ( F_61 , NULL ,
V_80 ) ;
if ( V_66 )
goto V_76;
F_32 ( 1 ) ;
}
V_60 = F_70 ( V_56 , sizeof( V_60 [ 0 ] ) ,
V_81 ) ;
if ( V_60 == NULL ) {
F_71 ( L_17 ) ;
V_66 = - V_82 ;
goto V_76;
}
for ( V_15 = 0 ; V_15 < V_56 ; V_15 ++ ) {
V_66 = F_69 ( F_33 , ( void * ) V_15 ,
V_60 [ V_15 ] ) ;
if ( V_66 )
goto V_76;
}
while ( F_30 ( & V_12 ) < V_56 )
F_32 ( 1 ) ;
V_61 = F_70 ( V_5 , sizeof( V_60 [ 0 ] ) ,
V_81 ) ;
V_25 = F_70 ( V_5 , sizeof( * V_25 ) ,
V_81 ) ;
V_53 =
F_70 ( V_5 , sizeof( * V_53 ) ,
V_81 ) ;
if ( ! V_61 || ! V_25 || ! V_53 ) {
F_71 ( L_17 ) ;
V_66 = - V_82 ;
goto V_76;
}
if ( F_72 () && ! F_73 () && ! V_32 ) {
F_71 ( L_18 ) ;
V_66 = - V_65 ;
goto V_76;
}
if ( F_73 () && V_32 ) {
F_71 ( L_19 ) ;
V_66 = - V_65 ;
goto V_76;
}
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ ) {
V_25 [ V_15 ] =
F_70 ( V_51 , sizeof( * V_25 [ V_15 ] ) ,
V_81 ) ;
if ( ! V_25 [ V_15 ] ) {
V_66 = - V_82 ;
goto V_76;
}
V_66 = F_69 ( F_42 , ( void * ) V_15 ,
V_61 [ V_15 ] ) ;
if ( V_66 )
goto V_76;
}
F_74 () ;
return 0 ;
V_76:
F_74 () ;
F_54 () ;
return V_66 ;
}
