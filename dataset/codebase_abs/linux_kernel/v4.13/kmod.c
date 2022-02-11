static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 [ 3 ] ) ;
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( char * V_4 , int V_5 )
{
struct V_1 * V_2 ;
static char * V_6 [] = {
L_1 ,
L_2 ,
L_3 ,
NULL
} ;
char * * V_3 = F_4 ( sizeof( char * [ 5 ] ) , V_7 ) ;
if ( ! V_3 )
goto V_8;
V_4 = F_5 ( V_4 , V_7 ) ;
if ( ! V_4 )
goto V_9;
V_3 [ 0 ] = V_10 ;
V_3 [ 1 ] = L_4 ;
V_3 [ 2 ] = L_5 ;
V_3 [ 3 ] = V_4 ;
V_3 [ 4 ] = NULL ;
V_2 = F_6 ( V_10 , V_3 , V_6 , V_7 ,
NULL , F_1 , NULL ) ;
if ( ! V_2 )
goto V_11;
return F_7 ( V_2 , V_5 | V_12 ) ;
V_11:
F_2 ( V_4 ) ;
V_9:
F_2 ( V_3 ) ;
V_8:
return - V_13 ;
}
int F_8 ( bool V_5 , const char * V_14 , ... )
{
T_1 args ;
char V_4 [ V_15 ] ;
int V_16 ;
F_9 ( V_5 && F_10 () ) ;
if ( ! V_10 [ 0 ] )
return 0 ;
va_start ( args , V_14 ) ;
V_16 = vsnprintf ( V_4 , V_15 , V_14 , args ) ;
va_end ( args ) ;
if ( V_16 >= V_15 )
return - V_17 ;
V_16 = F_11 ( V_4 ) ;
if ( V_16 )
return V_16 ;
if ( F_12 ( & V_18 ) < 0 ) {
F_13 ( L_6 ,
F_14 ( & V_18 ) ,
V_19 , V_4 ) ;
V_16 = F_15 ( V_20 ,
F_12 ( & V_18 ) >= 0 ,
V_21 * V_22 ) ;
if ( ! V_16 ) {
F_13 ( L_7 ,
V_4 , V_19 , V_21 ) ;
return - V_23 ;
} else if ( V_16 == - V_24 ) {
F_13 ( L_8 , V_4 ) ;
return V_16 ;
}
}
F_16 ( V_4 , V_5 , V_25 ) ;
V_16 = F_3 ( V_4 , V_5 ? V_26 : V_27 ) ;
F_17 ( & V_18 ) ;
F_18 ( & V_20 ) ;
return V_16 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 )
(* V_2 -> V_28 )( V_2 ) ;
F_2 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_29 )
{
struct V_30 * V_31 = F_21 ( & V_29 -> V_32 , NULL ) ;
if ( V_31 )
V_32 ( V_31 ) ;
else
F_19 ( V_29 ) ;
}
static int F_22 ( void * V_33 )
{
struct V_1 * V_29 = V_33 ;
struct V_34 * V_35 ;
int V_36 ;
F_23 ( & V_37 -> V_38 -> V_39 ) ;
F_24 ( V_37 , 1 ) ;
F_25 ( & V_37 -> V_38 -> V_39 ) ;
F_26 ( V_37 , 0 ) ;
V_36 = - V_13 ;
V_35 = F_27 ( V_37 ) ;
if ( ! V_35 )
goto V_8;
F_28 ( & V_40 ) ;
V_35 -> V_41 = F_29 ( V_42 , V_35 -> V_41 ) ;
V_35 -> V_43 = F_29 ( V_44 ,
V_35 -> V_43 ) ;
F_30 ( & V_40 ) ;
if ( V_29 -> V_45 ) {
V_36 = V_29 -> V_45 ( V_29 , V_35 ) ;
if ( V_36 ) {
F_31 ( V_35 ) ;
goto V_8;
}
}
F_32 ( V_35 ) ;
V_36 = F_33 ( F_34 ( V_29 -> V_46 ) ,
( const char V_47 * const V_47 * ) V_29 -> V_3 ,
( const char V_47 * const V_47 * ) V_29 -> V_6 ) ;
V_8:
V_29 -> V_36 = V_36 ;
if ( ! ( V_29 -> V_5 & V_26 ) )
F_20 ( V_29 ) ;
if ( ! V_36 )
return 0 ;
F_35 ( 0 ) ;
}
static void F_36 ( struct V_1 * V_29 )
{
T_2 V_48 ;
F_37 ( V_49 , V_50 ) ;
V_48 = F_38 ( F_22 , V_29 , V_49 ) ;
if ( V_48 < 0 ) {
V_29 -> V_36 = V_48 ;
} else {
int V_16 = - V_51 ;
F_39 ( V_48 , ( int V_47 * ) & V_16 , 0 , NULL ) ;
if ( V_16 )
V_29 -> V_36 = V_16 ;
}
F_37 ( V_49 , V_52 ) ;
F_20 ( V_29 ) ;
}
static void F_40 ( struct V_53 * V_54 )
{
struct V_1 * V_29 =
F_41 ( V_54 , struct V_1 , V_54 ) ;
if ( V_29 -> V_5 & V_26 ) {
F_36 ( V_29 ) ;
} else {
T_2 V_48 ;
V_48 = F_38 ( F_22 , V_29 ,
V_55 | V_49 ) ;
if ( V_48 < 0 ) {
V_29 -> V_36 = V_48 ;
F_20 ( V_29 ) ;
}
}
}
int F_42 ( void )
{
F_43 ( V_5 ) ;
int V_16 = 0 ;
F_44 ( & V_56 ) ;
for (; ; ) {
F_45 ( & V_57 , & V_5 ,
V_58 ) ;
if ( ! V_59 )
break;
if ( V_59 == V_60 )
V_16 = - V_61 ;
F_46 ( & V_56 ) ;
if ( V_16 )
break;
F_47 () ;
F_48 () ;
F_44 ( & V_56 ) ;
}
F_49 ( & V_57 , & V_5 ) ;
return V_16 ;
}
long F_50 ( long V_62 )
{
F_43 ( V_5 ) ;
if ( V_62 < 0 )
return - V_63 ;
F_44 ( & V_56 ) ;
for (; ; ) {
F_45 ( & V_57 , & V_5 ,
V_64 ) ;
if ( ! V_59 )
break;
F_46 ( & V_56 ) ;
V_62 = F_51 ( V_62 ) ;
if ( ! V_62 )
break;
F_44 ( & V_56 ) ;
}
F_49 ( & V_57 , & V_5 ) ;
return V_62 ;
}
void F_52 ( void )
{
F_46 ( & V_56 ) ;
}
void F_53 ( enum V_65 V_66 )
{
F_54 ( & V_56 ) ;
V_59 = V_66 ;
F_18 ( & V_57 ) ;
F_55 ( & V_56 ) ;
}
int F_56 ( enum V_65 V_66 )
{
long V_36 ;
if ( ! V_66 )
return - V_63 ;
F_54 ( & V_56 ) ;
V_59 = V_66 ;
F_55 ( & V_56 ) ;
V_36 = F_57 ( V_67 ,
F_14 ( & V_68 ) == 0 ,
V_69 ) ;
if ( V_36 )
return 0 ;
F_53 ( V_70 ) ;
return - V_61 ;
}
static void F_58 ( void )
{
F_17 ( & V_68 ) ;
F_59 () ;
}
static void F_60 ( void )
{
if ( F_61 ( & V_68 ) )
F_18 ( & V_67 ) ;
}
struct V_1 * F_6 ( const char * V_46 , char * * V_3 ,
char * * V_6 , T_3 V_71 ,
int (* V_45)( struct V_1 * V_2 , struct V_34 * V_35 ) ,
void (* V_28)( struct V_1 * V_2 ) ,
void * V_33 )
{
struct V_1 * V_29 ;
V_29 = F_62 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_29 )
goto V_8;
F_63 ( & V_29 -> V_54 , F_40 ) ;
#ifdef F_64
V_29 -> V_46 = V_72 ;
#else
V_29 -> V_46 = V_46 ;
#endif
V_29 -> V_3 = V_3 ;
V_29 -> V_6 = V_6 ;
V_29 -> V_28 = V_28 ;
V_29 -> V_45 = V_45 ;
V_29 -> V_33 = V_33 ;
V_8:
return V_29 ;
}
int F_7 ( struct V_1 * V_29 , int V_5 )
{
F_65 ( V_73 ) ;
int V_36 = 0 ;
if ( ! V_29 -> V_46 ) {
F_19 ( V_29 ) ;
return - V_63 ;
}
F_58 () ;
if ( V_59 ) {
V_36 = - V_74 ;
goto V_8;
}
if ( strlen ( V_29 -> V_46 ) == 0 )
goto V_8;
V_29 -> V_32 = ( V_5 == V_75 ) ? NULL : & V_73 ;
V_29 -> V_5 = V_5 ;
F_66 ( V_76 , & V_29 -> V_54 ) ;
if ( V_5 == V_75 )
goto V_77;
if ( V_5 & V_12 ) {
V_36 = F_67 ( & V_73 ) ;
if ( ! V_36 )
goto V_78;
if ( F_21 ( & V_29 -> V_32 , NULL ) )
goto V_77;
}
F_68 ( & V_73 ) ;
V_78:
V_36 = V_29 -> V_36 ;
V_8:
F_19 ( V_29 ) ;
V_77:
F_60 () ;
return V_36 ;
}
int F_69 ( const char * V_46 , char * * V_3 , char * * V_6 , int V_5 )
{
struct V_1 * V_2 ;
T_3 V_71 = ( V_5 == V_75 ) ? V_79 : V_7 ;
V_2 = F_6 ( V_46 , V_3 , V_6 , V_71 ,
NULL , NULL , NULL ) ;
if ( V_2 == NULL )
return - V_13 ;
return F_7 ( V_2 , V_5 ) ;
}
static int F_70 ( struct V_80 * V_81 , int V_82 ,
void V_47 * V_83 , T_4 * V_84 , T_5 * V_85 )
{
struct V_80 V_86 ;
unsigned long V_87 [ V_88 ] ;
T_6 V_89 ;
int V_90 , V_91 ;
if ( V_82 && ( ! F_71 ( V_92 ) ||
! F_71 ( V_93 ) ) )
return - V_94 ;
F_28 ( & V_40 ) ;
for ( V_91 = 0 ; V_91 < V_88 ; V_91 ++ ) {
if ( V_81 -> V_33 == V_95 )
V_87 [ V_91 ] = V_42 . V_96 [ V_91 ] ;
else if ( V_81 -> V_33 == V_97 )
V_87 [ V_91 ] = V_44 . V_96 [ V_91 ] ;
else
F_72 () ;
}
F_30 ( & V_40 ) ;
V_86 = * V_81 ;
V_86 . V_33 = & V_87 ;
V_90 = F_73 ( & V_86 , V_82 , V_83 , V_84 , V_85 ) ;
if ( V_90 < 0 )
return V_90 ;
for ( V_91 = 0 ; V_91 < V_88 ; V_91 ++ )
V_89 . V_96 [ V_91 ] = V_87 [ V_91 ] ;
F_28 ( & V_40 ) ;
if ( V_82 ) {
if ( V_81 -> V_33 == V_95 )
V_42 = F_29 ( V_42 , V_89 ) ;
if ( V_81 -> V_33 == V_97 )
V_44 = F_29 ( V_44 , V_89 ) ;
}
F_30 ( & V_40 ) ;
return 0 ;
}
