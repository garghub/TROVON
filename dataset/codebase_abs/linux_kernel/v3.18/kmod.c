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
int V_5 = V_27 -> V_5 & ~ V_12 ;
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
if ( V_5 != V_24 )
F_21 ( V_27 ) ;
if ( ! V_34 )
return 0 ;
F_37 ( 0 ) ;
}
static int F_38 ( void * V_31 )
{
V_47 = V_35 ;
return F_23 ( V_31 ) ;
}
static int F_39 ( void * V_31 )
{
struct V_1 * V_27 = V_31 ;
T_3 V_48 ;
F_40 ( V_49 , V_50 ) ;
V_48 = F_41 ( F_23 , V_27 , V_49 ) ;
if ( V_48 < 0 ) {
V_27 -> V_34 = V_48 ;
} else {
int V_17 = - V_51 ;
F_42 ( V_48 , ( int V_46 * ) & V_17 , 0 , NULL ) ;
if ( V_17 )
V_27 -> V_34 = V_17 ;
}
F_21 ( V_27 ) ;
F_37 ( 0 ) ;
}
static void F_43 ( struct V_52 * V_53 )
{
struct V_1 * V_27 =
F_44 ( V_53 , struct V_1 , V_53 ) ;
int V_5 = V_27 -> V_5 & ~ V_12 ;
T_3 V_48 ;
if ( V_5 == V_24 )
V_48 = F_41 ( F_39 , V_27 ,
V_54 | V_55 | V_49 ) ;
else {
V_48 = F_41 ( F_38 , V_27 ,
V_56 | V_49 ) ;
V_47 = NULL ;
}
if ( V_48 < 0 ) {
V_27 -> V_34 = V_48 ;
F_21 ( V_27 ) ;
}
}
int F_45 ( void )
{
F_46 ( V_5 ) ;
int V_17 = 0 ;
F_47 ( & V_57 ) ;
for (; ; ) {
F_48 ( & V_58 , & V_5 ,
V_59 ) ;
if ( ! V_60 )
break;
if ( V_60 == V_61 )
V_17 = - V_62 ;
F_49 ( & V_57 ) ;
if ( V_17 )
break;
F_50 () ;
F_51 () ;
F_47 ( & V_57 ) ;
}
F_52 ( & V_58 , & V_5 ) ;
return V_17 ;
}
long F_53 ( long V_63 )
{
F_46 ( V_5 ) ;
if ( V_63 < 0 )
return - V_64 ;
F_47 ( & V_57 ) ;
for (; ; ) {
F_48 ( & V_58 , & V_5 ,
V_65 ) ;
if ( ! V_60 )
break;
F_49 ( & V_57 ) ;
V_63 = F_54 ( V_63 ) ;
if ( ! V_63 )
break;
F_47 ( & V_57 ) ;
}
F_52 ( & V_58 , & V_5 ) ;
return V_63 ;
}
void F_55 ( void )
{
F_49 ( & V_57 ) ;
}
void F_56 ( enum V_66 V_67 )
{
F_57 ( & V_57 ) ;
V_60 = V_67 ;
F_58 ( & V_58 ) ;
F_59 ( & V_57 ) ;
}
int F_60 ( enum V_66 V_67 )
{
long V_34 ;
if ( ! V_67 )
return - V_64 ;
F_57 ( & V_57 ) ;
V_60 = V_67 ;
F_59 ( & V_57 ) ;
V_34 = F_61 ( V_68 ,
F_16 ( & V_69 ) == 0 ,
V_70 ) ;
if ( V_34 )
return 0 ;
F_56 ( V_71 ) ;
return - V_62 ;
}
static void F_62 ( void )
{
F_15 ( & V_69 ) ;
F_63 () ;
}
static void F_64 ( void )
{
if ( F_65 ( & V_69 ) )
F_58 ( & V_68 ) ;
}
struct V_1 * F_6 ( char * V_45 , char * * V_3 ,
char * * V_6 , T_4 V_72 ,
int (* V_44)( struct V_1 * V_2 , struct V_32 * V_33 ) ,
void (* V_26)( struct V_1 * V_2 ) ,
void * V_31 )
{
struct V_1 * V_27 ;
V_27 = F_66 ( sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_27 )
goto V_8;
F_67 ( & V_27 -> V_53 , F_43 ) ;
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
F_68 ( V_73 ) ;
int V_34 = 0 ;
if ( ! V_27 -> V_45 ) {
F_20 ( V_27 ) ;
return - V_64 ;
}
F_62 () ;
if ( ! V_74 || V_60 ) {
V_34 = - V_75 ;
goto V_8;
}
if ( V_5 != V_76 && V_35 == V_47 ) {
V_34 = - V_75 ;
goto V_8;
}
V_27 -> V_30 = ( V_5 == V_76 ) ? NULL : & V_73 ;
V_27 -> V_5 = V_5 ;
F_69 ( V_74 , & V_27 -> V_53 ) ;
if ( V_5 == V_76 )
goto V_77;
if ( V_5 & V_12 ) {
V_34 = F_70 ( & V_73 ) ;
if ( ! V_34 )
goto V_78;
if ( F_22 ( & V_27 -> V_30 , NULL ) )
goto V_77;
}
F_71 ( & V_73 ) ;
V_78:
V_34 = V_27 -> V_34 ;
V_8:
F_20 ( V_27 ) ;
V_77:
F_64 () ;
return V_34 ;
}
int F_72 ( char * V_45 , char * * V_3 , char * * V_6 , int V_5 )
{
struct V_1 * V_2 ;
T_4 V_72 = ( V_5 == V_76 ) ? V_79 : V_7 ;
V_2 = F_6 ( V_45 , V_3 , V_6 , V_72 ,
NULL , NULL , NULL ) ;
if ( V_2 == NULL )
return - V_13 ;
return F_7 ( V_2 , V_5 ) ;
}
static int F_73 ( struct V_80 * V_81 , int V_82 ,
void V_46 * V_83 , T_5 * V_84 , T_6 * V_85 )
{
struct V_80 V_86 ;
unsigned long V_87 [ V_88 ] ;
T_7 V_89 ;
int V_90 , V_91 ;
if ( V_82 && ( ! F_74 ( V_92 ) ||
! F_74 ( V_93 ) ) )
return - V_94 ;
F_30 ( & V_39 ) ;
for ( V_91 = 0 ; V_91 < V_88 ; V_91 ++ ) {
if ( V_81 -> V_31 == V_95 )
V_87 [ V_91 ] = V_41 . V_96 [ V_91 ] ;
else if ( V_81 -> V_31 == V_97 )
V_87 [ V_91 ] = V_43 . V_96 [ V_91 ] ;
else
F_75 () ;
}
F_32 ( & V_39 ) ;
V_86 = * V_81 ;
V_86 . V_31 = & V_87 ;
V_90 = F_76 ( & V_86 , V_82 , V_83 , V_84 , V_85 ) ;
if ( V_90 < 0 )
return V_90 ;
for ( V_91 = 0 ; V_91 < V_88 ; V_91 ++ )
V_89 . V_96 [ V_91 ] = V_87 [ V_91 ] ;
F_30 ( & V_39 ) ;
if ( V_82 ) {
if ( V_81 -> V_31 == V_95 )
V_41 = F_31 ( V_41 , V_89 ) ;
if ( V_81 -> V_31 == V_97 )
V_43 = F_31 ( V_43 , V_89 ) ;
}
F_32 ( & V_39 ) ;
return 0 ;
}
void T_8 F_77 ( void )
{
V_74 = F_78 ( L_7 ) ;
F_79 ( ! V_74 ) ;
}
