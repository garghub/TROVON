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
unsigned int V_16 ;
int V_17 ;
static T_2 V_18 = F_9 ( 0 ) ;
#define F_10 50
static int V_19 ;
F_11 ( V_5 && F_12 () ) ;
if ( ! V_10 [ 0 ] )
return 0 ;
va_start ( args , V_14 ) ;
V_17 = vsnprintf ( V_4 , V_15 , V_14 , args ) ;
va_end ( args ) ;
if ( V_17 >= V_15 )
return - V_20 ;
V_17 = F_13 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_16 = F_14 ( V_21 / 2 , F_10 ) ;
F_15 ( & V_18 ) ;
if ( F_16 ( & V_18 ) > V_16 ) {
if ( V_19 < 5 ) {
F_17 ( V_22
L_6 ,
V_4 ) ;
V_19 ++ ;
}
F_18 ( & V_18 ) ;
return - V_13 ;
}
F_19 ( V_4 , V_5 , V_23 ) ;
V_17 = F_3 ( V_4 , V_5 ? V_24 : V_25 ) ;
F_18 ( & V_18 ) ;
return V_17 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 )
(* V_2 -> V_26 )( V_2 ) ;
F_2 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_27 )
{
struct V_28 * V_29 = F_22 ( & V_27 -> V_30 , NULL ) ;
if ( V_29 )
V_30 ( V_29 ) ;
else
F_20 ( V_27 ) ;
}
static int F_23 ( void * V_31 )
{
struct V_1 * V_27 = V_31 ;
struct V_32 * V_33 ;
int V_34 ;
F_24 ( & V_35 -> V_36 -> V_37 ) ;
F_25 ( V_35 , 1 ) ;
F_26 ( & V_35 -> V_36 -> V_37 ) ;
F_27 ( V_35 , 0 ) ;
V_34 = - V_13 ;
V_33 = F_28 ( V_35 ) ;
if ( ! V_33 )
goto V_8;
F_29 ( & V_38 ) ;
V_33 -> V_39 = F_30 ( V_40 , V_33 -> V_39 ) ;
V_33 -> V_41 = F_30 ( V_42 ,
V_33 -> V_41 ) ;
F_31 ( & V_38 ) ;
if ( V_27 -> V_43 ) {
V_34 = V_27 -> V_43 ( V_27 , V_33 ) ;
if ( V_34 ) {
F_32 ( V_33 ) ;
goto V_8;
}
}
F_33 ( V_33 ) ;
V_34 = F_34 ( F_35 ( V_27 -> V_44 ) ,
( const char V_45 * const V_45 * ) V_27 -> V_3 ,
( const char V_45 * const V_45 * ) V_27 -> V_6 ) ;
V_8:
V_27 -> V_34 = V_34 ;
if ( ! ( V_27 -> V_5 & V_24 ) )
F_21 ( V_27 ) ;
if ( ! V_34 )
return 0 ;
F_36 ( 0 ) ;
}
static void F_37 ( struct V_1 * V_27 )
{
T_3 V_46 ;
F_38 ( V_47 , V_48 ) ;
V_46 = F_39 ( F_23 , V_27 , V_47 ) ;
if ( V_46 < 0 ) {
V_27 -> V_34 = V_46 ;
} else {
int V_17 = - V_49 ;
F_40 ( V_46 , ( int V_45 * ) & V_17 , 0 , NULL ) ;
if ( V_17 )
V_27 -> V_34 = V_17 ;
}
F_38 ( V_47 , V_50 ) ;
F_21 ( V_27 ) ;
}
static void F_41 ( struct V_51 * V_52 )
{
struct V_1 * V_27 =
F_42 ( V_52 , struct V_1 , V_52 ) ;
if ( V_27 -> V_5 & V_24 ) {
F_37 ( V_27 ) ;
} else {
T_3 V_46 ;
V_46 = F_39 ( F_23 , V_27 ,
V_53 | V_47 ) ;
if ( V_46 < 0 ) {
V_27 -> V_34 = V_46 ;
F_21 ( V_27 ) ;
}
}
}
int F_43 ( void )
{
F_44 ( V_5 ) ;
int V_17 = 0 ;
F_45 ( & V_54 ) ;
for (; ; ) {
F_46 ( & V_55 , & V_5 ,
V_56 ) ;
if ( ! V_57 )
break;
if ( V_57 == V_58 )
V_17 = - V_59 ;
F_47 ( & V_54 ) ;
if ( V_17 )
break;
F_48 () ;
F_49 () ;
F_45 ( & V_54 ) ;
}
F_50 ( & V_55 , & V_5 ) ;
return V_17 ;
}
long F_51 ( long V_60 )
{
F_44 ( V_5 ) ;
if ( V_60 < 0 )
return - V_61 ;
F_45 ( & V_54 ) ;
for (; ; ) {
F_46 ( & V_55 , & V_5 ,
V_62 ) ;
if ( ! V_57 )
break;
F_47 ( & V_54 ) ;
V_60 = F_52 ( V_60 ) ;
if ( ! V_60 )
break;
F_45 ( & V_54 ) ;
}
F_50 ( & V_55 , & V_5 ) ;
return V_60 ;
}
void F_53 ( void )
{
F_47 ( & V_54 ) ;
}
void F_54 ( enum V_63 V_64 )
{
F_55 ( & V_54 ) ;
V_57 = V_64 ;
F_56 ( & V_55 ) ;
F_57 ( & V_54 ) ;
}
int F_58 ( enum V_63 V_64 )
{
long V_34 ;
if ( ! V_64 )
return - V_61 ;
F_55 ( & V_54 ) ;
V_57 = V_64 ;
F_57 ( & V_54 ) ;
V_34 = F_59 ( V_65 ,
F_16 ( & V_66 ) == 0 ,
V_67 ) ;
if ( V_34 )
return 0 ;
F_54 ( V_68 ) ;
return - V_59 ;
}
static void F_60 ( void )
{
F_15 ( & V_66 ) ;
F_61 () ;
}
static void F_62 ( void )
{
if ( F_63 ( & V_66 ) )
F_56 ( & V_65 ) ;
}
struct V_1 * F_6 ( const char * V_44 , char * * V_3 ,
char * * V_6 , T_4 V_69 ,
int (* V_43)( struct V_1 * V_2 , struct V_32 * V_33 ) ,
void (* V_26)( struct V_1 * V_2 ) ,
void * V_31 )
{
struct V_1 * V_27 ;
V_27 = F_64 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_27 )
goto V_8;
F_65 ( & V_27 -> V_52 , F_41 ) ;
#ifdef F_66
V_27 -> V_44 = V_70 ;
#else
V_27 -> V_44 = V_44 ;
#endif
V_27 -> V_3 = V_3 ;
V_27 -> V_6 = V_6 ;
V_27 -> V_26 = V_26 ;
V_27 -> V_43 = V_43 ;
V_27 -> V_31 = V_31 ;
V_8:
return V_27 ;
}
int F_7 ( struct V_1 * V_27 , int V_5 )
{
F_67 ( V_71 ) ;
int V_34 = 0 ;
if ( ! V_27 -> V_44 ) {
F_20 ( V_27 ) ;
return - V_61 ;
}
F_60 () ;
if ( V_57 ) {
V_34 = - V_72 ;
goto V_8;
}
if ( strlen ( V_27 -> V_44 ) == 0 )
goto V_8;
V_27 -> V_30 = ( V_5 == V_73 ) ? NULL : & V_71 ;
V_27 -> V_5 = V_5 ;
F_68 ( V_74 , & V_27 -> V_52 ) ;
if ( V_5 == V_73 )
goto V_75;
if ( V_5 & V_12 ) {
V_34 = F_69 ( & V_71 ) ;
if ( ! V_34 )
goto V_76;
if ( F_22 ( & V_27 -> V_30 , NULL ) )
goto V_75;
}
F_70 ( & V_71 ) ;
V_76:
V_34 = V_27 -> V_34 ;
V_8:
F_20 ( V_27 ) ;
V_75:
F_62 () ;
return V_34 ;
}
int F_71 ( const char * V_44 , char * * V_3 , char * * V_6 , int V_5 )
{
struct V_1 * V_2 ;
T_4 V_69 = ( V_5 == V_73 ) ? V_77 : V_7 ;
V_2 = F_6 ( V_44 , V_3 , V_6 , V_69 ,
NULL , NULL , NULL ) ;
if ( V_2 == NULL )
return - V_13 ;
return F_7 ( V_2 , V_5 ) ;
}
static int F_72 ( struct V_78 * V_79 , int V_80 ,
void V_45 * V_81 , T_5 * V_82 , T_6 * V_83 )
{
struct V_78 V_84 ;
unsigned long V_85 [ V_86 ] ;
T_7 V_87 ;
int V_88 , V_89 ;
if ( V_80 && ( ! F_73 ( V_90 ) ||
! F_73 ( V_91 ) ) )
return - V_92 ;
F_29 ( & V_38 ) ;
for ( V_89 = 0 ; V_89 < V_86 ; V_89 ++ ) {
if ( V_79 -> V_31 == V_93 )
V_85 [ V_89 ] = V_40 . V_94 [ V_89 ] ;
else if ( V_79 -> V_31 == V_95 )
V_85 [ V_89 ] = V_42 . V_94 [ V_89 ] ;
else
F_74 () ;
}
F_31 ( & V_38 ) ;
V_84 = * V_79 ;
V_84 . V_31 = & V_85 ;
V_88 = F_75 ( & V_84 , V_80 , V_81 , V_82 , V_83 ) ;
if ( V_88 < 0 )
return V_88 ;
for ( V_89 = 0 ; V_89 < V_86 ; V_89 ++ )
V_87 . V_94 [ V_89 ] = V_85 [ V_89 ] ;
F_29 ( & V_38 ) ;
if ( V_80 ) {
if ( V_79 -> V_31 == V_93 )
V_40 = F_30 ( V_40 , V_87 ) ;
if ( V_79 -> V_31 == V_95 )
V_42 = F_30 ( V_42 , V_87 ) ;
}
F_31 ( & V_38 ) ;
return 0 ;
}
