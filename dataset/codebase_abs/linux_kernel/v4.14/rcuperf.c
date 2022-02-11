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
static void F_17 ( struct V_2 * V_3 , T_5 V_4 )
{
F_18 ( T_4 , V_3 , V_4 ) ;
}
static void F_19 ( void )
{
F_20 ( T_4 ) ;
}
static void F_21 ( void )
{
F_22 ( T_4 ) ;
}
static void F_23 ( void )
{
F_24 ( T_4 ) ;
}
static void F_25 ( void )
{
T_4 = & V_5 ;
F_26 ( T_4 ) ;
}
static void F_27 ( void )
{
F_28 ( T_4 ) ;
}
static int F_29 ( void )
{
F_30 () ;
return 0 ;
}
static void F_31 ( int V_1 )
{
F_32 () ;
}
static int F_33 ( void )
{
return 0 ;
}
static void F_34 ( int V_1 )
{
}
static bool T_2 F_35 ( void )
{
return V_6 == & V_7 ;
}
static void F_36 ( void )
{
F_37 () ;
if ( F_38 ( & V_8 ) < V_9 )
return;
while ( ! F_39 () )
F_40 ( 1 ) ;
}
static int
F_41 ( void * V_10 )
{
unsigned long V_11 ;
int V_1 ;
long V_12 = ( long ) V_10 ;
F_42 ( L_1 ) ;
F_43 ( V_13 , F_44 ( V_12 % V_14 ) ) ;
F_45 ( V_13 , V_15 ) ;
F_46 ( & V_16 ) ;
do {
F_47 ( V_11 ) ;
V_1 = V_6 -> V_17 () ;
V_6 -> V_18 ( V_1 ) ;
F_48 ( V_11 ) ;
F_36 () ;
} while ( ! F_39 () );
F_49 ( L_2 ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_19 )
{
F_51 ( F_52 ( & V_20 ) ) ;
F_53 ( V_19 ) ;
}
static int
F_54 ( void * V_10 )
{
int V_21 = 0 ;
int V_22 ;
long V_12 = ( long ) V_10 ;
struct V_2 * V_19 = NULL ;
struct V_23 V_24 ;
bool V_25 = false , V_26 = false , V_27 = false ;
T_6 V_28 ;
T_6 * V_29 ;
T_6 * V_30 = V_31 [ V_12 ] ;
F_42 ( L_3 ) ;
F_55 ( ! V_30 ) ;
F_43 ( V_13 , F_44 ( V_12 % V_14 ) ) ;
V_24 . V_32 = 1 ;
F_56 ( V_13 , V_33 , & V_24 ) ;
if ( V_34 )
F_40 ( V_34 * V_35 ) ;
V_28 = F_57 () ;
if ( F_58 ( & V_36 ) >= V_9 ) {
V_37 = V_28 ;
if ( V_38 ) {
V_39 =
V_6 -> V_40 () / 2 ;
} else {
V_39 =
V_6 -> V_41 () ;
}
}
do {
if ( V_42 )
F_59 ( V_42 ) ;
V_29 = & V_30 [ V_21 ] ;
* V_29 = F_57 () ;
if ( V_43 ) {
V_44:
if ( ! V_19 )
V_19 = F_60 ( sizeof( * V_19 ) , V_45 ) ;
if ( V_19 && F_38 ( F_52 ( & V_20 ) ) < V_46 ) {
V_47 = V_48 ;
F_46 ( F_52 ( & V_20 ) ) ;
V_6 -> V_49 ( V_19 , F_50 ) ;
V_19 = NULL ;
} else if ( ! F_61 () ) {
V_47 = V_50 ;
V_6 -> V_51 () ;
goto V_44;
} else {
F_53 ( V_19 ) ;
}
} else if ( V_38 ) {
V_47 = V_52 ;
V_6 -> V_53 () ;
} else {
V_47 = V_54 ;
V_6 -> V_55 () ;
}
V_47 = V_56 ;
V_28 = F_57 () ;
* V_29 = V_28 - * V_29 ;
V_22 = V_21 ;
if ( ! V_25 &&
F_38 ( & V_36 ) >= V_9 )
V_25 = true ;
if ( ! V_26 && V_21 >= V_57 ) {
V_26 = true ;
V_24 . V_32 = 0 ;
F_56 ( V_13 ,
V_58 , & V_24 ) ;
F_62 ( L_4 ,
V_59 , V_60 , V_12 , V_57 ) ;
if ( F_58 ( & V_8 ) >=
V_9 ) {
F_63 ( 10 ) ;
F_64 ( V_61 ) ;
F_65 ( L_5 ) ;
V_62 = V_28 ;
if ( V_38 ) {
V_63 =
V_6 -> V_40 () / 2 ;
} else {
V_63 =
V_6 -> V_41 () ;
}
if ( V_64 ) {
F_66 () ;
F_67 ( & V_65 ) ;
}
}
}
if ( V_26 && ! V_27 &&
F_38 ( & V_8 ) >= V_9 )
V_27 = true ;
if ( V_25 && ! V_27 && V_21 < V_66 - 1 )
V_21 ++ ;
F_36 () ;
} while ( ! F_39 () );
if ( V_43 ) {
V_47 = V_50 ;
V_6 -> V_51 () ;
}
V_47 = V_67 ;
V_68 [ V_12 ] = V_22 ;
F_49 ( L_6 ) ;
return 0 ;
}
static inline void
F_68 ( struct V_69 * V_6 , const char * V_70 )
{
F_62 ( L_7 V_60
L_8 ,
V_59 , V_70 , V_71 , V_9 , V_72 , V_64 ) ;
}
static void
F_69 ( void )
{
int V_21 ;
int V_73 ;
int V_74 = 0 ;
T_6 * V_29 ;
T_6 * V_30 ;
if ( F_70 () && ! F_71 () && ! V_38 )
F_72 ( L_9 ) ;
if ( F_71 () && V_38 )
F_72 ( L_10 ) ;
if ( V_38 && V_43 )
F_72 ( L_11 ) ;
if ( F_73 () )
return;
if ( V_75 ) {
for ( V_21 = 0 ; V_21 < V_71 ; V_21 ++ )
F_74 ( F_41 ,
V_75 [ V_21 ] ) ;
F_53 ( V_75 ) ;
}
if ( V_76 ) {
for ( V_21 = 0 ; V_21 < V_9 ; V_21 ++ ) {
F_74 ( F_54 ,
V_76 [ V_21 ] ) ;
if ( ! V_68 )
continue;
V_73 = V_68 [ V_21 ] ;
F_62 ( L_12 ,
V_59 , V_60 , V_21 , V_73 ) ;
V_74 += V_73 ;
}
F_62 ( L_13 ,
V_59 , V_60 ,
V_37 , V_62 ,
V_62 -
V_37 ,
V_74 ,
V_63 -
V_39 ) ;
for ( V_21 = 0 ; V_21 < V_9 ; V_21 ++ ) {
if ( ! V_31 )
break;
if ( ! V_68 )
continue;
V_30 = V_31 [ V_21 ] ;
if ( ! V_30 )
continue;
for ( V_73 = 0 ; V_73 <= V_68 [ V_21 ] ; V_73 ++ ) {
V_29 = & V_30 [ V_73 ] ;
F_62 ( L_14 ,
V_59 , V_60 ,
V_21 , V_73 , * V_29 ) ;
if ( V_73 % 100 == 0 )
F_40 ( 1 ) ;
}
F_53 ( V_31 [ V_21 ] ) ;
}
F_53 ( V_76 ) ;
F_53 ( V_31 ) ;
F_53 ( V_68 ) ;
}
if ( V_6 -> V_77 != NULL )
V_6 -> V_77 () ;
F_75 () ;
}
static int F_76 ( int V_78 )
{
int V_79 ;
if ( V_78 >= 0 ) {
V_79 = V_78 ;
} else {
V_79 = F_77 () + 1 + V_78 ;
if ( V_79 <= 0 )
V_79 = 1 ;
}
return V_79 ;
}
static int
F_78 ( void * V_10 )
{
do {
F_79 ( V_65 ,
F_38 ( & V_8 ) >=
V_9 ) ;
} while ( F_38 ( & V_8 ) < V_9 );
F_66 () ;
F_69 () ;
F_80 () ;
return - V_80 ;
}
static int T_7
F_81 ( void )
{
long V_21 ;
int V_81 = 0 ;
static struct V_69 * V_82 [] = {
& V_83 , & V_84 , & V_85 , & V_86 , & V_87 ,
& V_7 ,
} ;
if ( ! F_82 ( V_59 , V_72 , & V_88 ) )
return - V_89 ;
for ( V_21 = 0 ; V_21 < F_83 ( V_82 ) ; V_21 ++ ) {
V_6 = V_82 [ V_21 ] ;
if ( strcmp ( V_59 , V_6 -> V_90 ) == 0 )
break;
}
if ( V_21 == F_83 ( V_82 ) ) {
F_62 ( L_15 ,
V_59 ) ;
F_62 ( L_16 ) ;
for ( V_21 = 0 ; V_21 < F_83 ( V_82 ) ; V_21 ++ )
F_62 ( L_17 , V_82 [ V_21 ] -> V_90 ) ;
F_62 ( L_18 ) ;
V_81 = - V_80 ;
goto V_91;
}
if ( V_6 -> V_92 )
V_6 -> V_92 () ;
V_9 = F_76 ( V_93 ) ;
V_71 = F_76 ( V_94 ) ;
F_84 ( & V_16 , 0 ) ;
F_84 ( & V_36 , 0 ) ;
F_84 ( & V_8 , 0 ) ;
F_68 ( V_6 , L_19 ) ;
if ( V_64 ) {
F_85 ( & V_65 ) ;
V_81 = F_86 ( F_78 , NULL ,
V_95 ) ;
if ( V_81 )
goto V_91;
F_40 ( 1 ) ;
}
V_75 = F_87 ( V_71 , sizeof( V_75 [ 0 ] ) ,
V_45 ) ;
if ( V_75 == NULL ) {
F_72 ( L_20 ) ;
V_81 = - V_96 ;
goto V_91;
}
for ( V_21 = 0 ; V_21 < V_71 ; V_21 ++ ) {
V_81 = F_86 ( F_41 , ( void * ) V_21 ,
V_75 [ V_21 ] ) ;
if ( V_81 )
goto V_91;
}
while ( F_38 ( & V_16 ) < V_71 )
F_40 ( 1 ) ;
V_76 = F_87 ( V_9 , sizeof( V_75 [ 0 ] ) ,
V_45 ) ;
V_31 = F_87 ( V_9 , sizeof( * V_31 ) ,
V_45 ) ;
V_68 =
F_87 ( V_9 , sizeof( * V_68 ) ,
V_45 ) ;
if ( ! V_76 || ! V_31 || ! V_68 ) {
F_72 ( L_20 ) ;
V_81 = - V_96 ;
goto V_91;
}
for ( V_21 = 0 ; V_21 < V_9 ; V_21 ++ ) {
V_31 [ V_21 ] =
F_87 ( V_66 , sizeof( * V_31 [ V_21 ] ) ,
V_45 ) ;
if ( ! V_31 [ V_21 ] ) {
V_81 = - V_96 ;
goto V_91;
}
V_81 = F_86 ( F_54 , ( void * ) V_21 ,
V_76 [ V_21 ] ) ;
if ( V_81 )
goto V_91;
}
F_88 () ;
return 0 ;
V_91:
F_88 () ;
F_69 () ;
return V_81 ;
}
