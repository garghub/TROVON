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
F_27 ( V_35 , V_38 ) ;
F_28 ( V_35 , 0 ) ;
V_34 = - V_13 ;
V_33 = F_29 ( V_35 ) ;
if ( ! V_33 )
goto V_8;
F_30 ( & V_39 ) ;
V_33 -> V_40 = F_31 ( V_41 , V_33 -> V_40 ) ;
V_33 -> V_42 = F_31 ( V_43 ,
V_33 -> V_42 ) ;
F_32 ( & V_39 ) ;
if ( V_27 -> V_44 ) {
V_34 = V_27 -> V_44 ( V_27 , V_33 ) ;
if ( V_34 ) {
F_33 ( V_33 ) ;
goto V_8;
}
}
F_34 ( V_33 ) ;
V_34 = F_35 ( F_36 ( V_27 -> V_45 ) ,
( const char V_46 * const V_46 * ) V_27 -> V_3 ,
( const char V_46 * const V_46 * ) V_27 -> V_6 ) ;
V_8:
V_27 -> V_34 = V_34 ;
if ( ! ( V_27 -> V_5 & V_24 ) )
F_21 ( V_27 ) ;
if ( ! V_34 )
return 0 ;
F_37 ( 0 ) ;
}
static int F_38 ( void * V_31 )
{
struct V_1 * V_27 = V_31 ;
T_3 V_47 ;
F_39 ( V_48 , V_49 ) ;
V_47 = F_40 ( F_23 , V_27 , V_48 ) ;
if ( V_47 < 0 ) {
V_27 -> V_34 = V_47 ;
} else {
int V_17 = - V_50 ;
F_41 ( V_47 , ( int V_46 * ) & V_17 , 0 , NULL ) ;
if ( V_17 )
V_27 -> V_34 = V_17 ;
}
F_21 ( V_27 ) ;
F_37 ( 0 ) ;
}
static void F_42 ( struct V_51 * V_52 )
{
struct V_1 * V_27 =
F_43 ( V_52 , struct V_1 , V_52 ) ;
T_3 V_47 ;
if ( V_27 -> V_5 & V_24 )
V_47 = F_40 ( F_38 , V_27 ,
V_53 | V_54 | V_48 ) ;
else
V_47 = F_40 ( F_23 , V_27 ,
V_48 ) ;
if ( V_47 < 0 ) {
V_27 -> V_34 = V_47 ;
F_21 ( V_27 ) ;
}
}
int F_44 ( void )
{
F_45 ( V_5 ) ;
int V_17 = 0 ;
F_46 ( & V_55 ) ;
for (; ; ) {
F_47 ( & V_56 , & V_5 ,
V_57 ) ;
if ( ! V_58 )
break;
if ( V_58 == V_59 )
V_17 = - V_60 ;
F_48 ( & V_55 ) ;
if ( V_17 )
break;
F_49 () ;
F_50 () ;
F_46 ( & V_55 ) ;
}
F_51 ( & V_56 , & V_5 ) ;
return V_17 ;
}
long F_52 ( long V_61 )
{
F_45 ( V_5 ) ;
if ( V_61 < 0 )
return - V_62 ;
F_46 ( & V_55 ) ;
for (; ; ) {
F_47 ( & V_56 , & V_5 ,
V_63 ) ;
if ( ! V_58 )
break;
F_48 ( & V_55 ) ;
V_61 = F_53 ( V_61 ) ;
if ( ! V_61 )
break;
F_46 ( & V_55 ) ;
}
F_51 ( & V_56 , & V_5 ) ;
return V_61 ;
}
void F_54 ( void )
{
F_48 ( & V_55 ) ;
}
void F_55 ( enum V_64 V_65 )
{
F_56 ( & V_55 ) ;
V_58 = V_65 ;
F_57 ( & V_56 ) ;
F_58 ( & V_55 ) ;
}
int F_59 ( enum V_64 V_65 )
{
long V_34 ;
if ( ! V_65 )
return - V_62 ;
F_56 ( & V_55 ) ;
V_58 = V_65 ;
F_58 ( & V_55 ) ;
V_34 = F_60 ( V_66 ,
F_16 ( & V_67 ) == 0 ,
V_68 ) ;
if ( V_34 )
return 0 ;
F_55 ( V_69 ) ;
return - V_60 ;
}
static void F_61 ( void )
{
F_15 ( & V_67 ) ;
F_62 () ;
}
static void F_63 ( void )
{
if ( F_64 ( & V_67 ) )
F_57 ( & V_66 ) ;
}
struct V_1 * F_6 ( char * V_45 , char * * V_3 ,
char * * V_6 , T_4 V_70 ,
int (* V_44)( struct V_1 * V_2 , struct V_32 * V_33 ) ,
void (* V_26)( struct V_1 * V_2 ) ,
void * V_31 )
{
struct V_1 * V_27 ;
V_27 = F_65 ( sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_27 )
goto V_8;
F_66 ( & V_27 -> V_52 , F_42 ) ;
V_27 -> V_45 = V_45 ;
V_27 -> V_3 = V_3 ;
V_27 -> V_6 = V_6 ;
V_27 -> V_26 = V_26 ;
V_27 -> V_44 = V_44 ;
V_27 -> V_31 = V_31 ;
V_8:
return V_27 ;
}
int F_7 ( struct V_1 * V_27 , int V_5 )
{
F_67 ( V_71 ) ;
int V_34 = 0 ;
if ( ! V_27 -> V_45 ) {
F_20 ( V_27 ) ;
return - V_62 ;
}
F_61 () ;
if ( ! V_72 || V_58 ) {
V_34 = - V_73 ;
goto V_8;
}
V_27 -> V_30 = ( V_5 == V_74 ) ? NULL : & V_71 ;
V_27 -> V_5 = V_5 ;
F_68 ( V_72 , & V_27 -> V_52 ) ;
if ( V_5 == V_74 )
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
F_63 () ;
return V_34 ;
}
int F_71 ( char * V_45 , char * * V_3 , char * * V_6 , int V_5 )
{
struct V_1 * V_2 ;
T_4 V_70 = ( V_5 == V_74 ) ? V_77 : V_7 ;
V_2 = F_6 ( V_45 , V_3 , V_6 , V_70 ,
NULL , NULL , NULL ) ;
if ( V_2 == NULL )
return - V_13 ;
return F_7 ( V_2 , V_5 ) ;
}
static int F_72 ( struct V_78 * V_79 , int V_80 ,
void V_46 * V_81 , T_5 * V_82 , T_6 * V_83 )
{
struct V_78 V_84 ;
unsigned long V_85 [ V_86 ] ;
T_7 V_87 ;
int V_88 , V_89 ;
if ( V_80 && ( ! F_73 ( V_90 ) ||
! F_73 ( V_91 ) ) )
return - V_92 ;
F_30 ( & V_39 ) ;
for ( V_89 = 0 ; V_89 < V_86 ; V_89 ++ ) {
if ( V_79 -> V_31 == V_93 )
V_85 [ V_89 ] = V_41 . V_94 [ V_89 ] ;
else if ( V_79 -> V_31 == V_95 )
V_85 [ V_89 ] = V_43 . V_94 [ V_89 ] ;
else
F_74 () ;
}
F_32 ( & V_39 ) ;
V_84 = * V_79 ;
V_84 . V_31 = & V_85 ;
V_88 = F_75 ( & V_84 , V_80 , V_81 , V_82 , V_83 ) ;
if ( V_88 < 0 )
return V_88 ;
for ( V_89 = 0 ; V_89 < V_86 ; V_89 ++ )
V_87 . V_94 [ V_89 ] = V_85 [ V_89 ] ;
F_30 ( & V_39 ) ;
if ( V_80 ) {
if ( V_79 -> V_31 == V_93 )
V_41 = F_31 ( V_41 , V_87 ) ;
if ( V_79 -> V_31 == V_95 )
V_43 = F_31 ( V_43 , V_87 ) ;
}
F_32 ( & V_39 ) ;
return 0 ;
}
void T_8 F_76 ( void )
{
V_72 = F_77 ( L_7 ) ;
F_78 ( ! V_72 ) ;
}
