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
static int F_20 ( void * V_26 )
{
struct V_1 * V_27 = V_26 ;
struct V_28 * V_29 ;
int V_30 ;
F_21 ( & V_31 -> V_32 -> V_33 ) ;
F_22 ( V_31 , 1 ) ;
F_23 ( & V_31 -> V_32 -> V_33 ) ;
F_24 ( V_31 , V_34 ) ;
F_25 ( V_31 , 0 ) ;
V_30 = - V_13 ;
V_29 = F_26 ( V_31 ) ;
if ( ! V_29 )
goto V_35;
F_27 ( & V_36 ) ;
V_29 -> V_37 = F_28 ( V_38 , V_29 -> V_37 ) ;
V_29 -> V_39 = F_28 ( V_40 ,
V_29 -> V_39 ) ;
F_29 ( & V_36 ) ;
if ( V_27 -> V_41 ) {
V_30 = V_27 -> V_41 ( V_27 , V_29 ) ;
if ( V_30 ) {
F_30 ( V_29 ) ;
goto V_35;
}
}
F_31 ( V_29 ) ;
V_30 = F_32 ( F_33 ( V_27 -> V_42 ) ,
( const char V_43 * const V_43 * ) V_27 -> V_3 ,
( const char V_43 * const V_43 * ) V_27 -> V_6 ) ;
if ( ! V_30 )
return 0 ;
V_35:
V_27 -> V_30 = V_30 ;
F_34 ( 0 ) ;
}
static int F_35 ( void * V_26 )
{
V_44 = V_31 ;
return F_20 ( V_26 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_45 )
(* V_2 -> V_45 )( V_2 ) ;
F_2 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_27 )
{
struct V_46 * V_47 = F_38 ( & V_27 -> V_48 , NULL ) ;
if ( V_47 )
V_48 ( V_47 ) ;
else
F_36 ( V_27 ) ;
}
static int F_39 ( void * V_26 )
{
struct V_1 * V_27 = V_26 ;
T_3 V_49 ;
F_40 ( V_50 , V_51 ) ;
V_49 = F_41 ( F_20 , V_27 , V_50 ) ;
if ( V_49 < 0 ) {
V_27 -> V_30 = V_49 ;
} else {
int V_17 = - V_52 ;
F_42 ( V_49 , ( int V_43 * ) & V_17 , 0 , NULL ) ;
if ( V_17 )
V_27 -> V_30 = V_17 ;
}
F_37 ( V_27 ) ;
F_34 ( 0 ) ;
}
static void F_43 ( struct V_53 * V_54 )
{
struct V_1 * V_27 =
F_44 ( V_54 , struct V_1 , V_54 ) ;
int V_5 = V_27 -> V_5 & ~ V_12 ;
T_3 V_49 ;
if ( V_5 == V_24 )
V_49 = F_41 ( F_39 , V_27 ,
V_55 | V_56 | V_50 ) ;
else {
V_49 = F_41 ( F_35 , V_27 ,
V_57 | V_50 ) ;
V_44 = NULL ;
}
switch ( V_5 ) {
case V_58 :
F_36 ( V_27 ) ;
break;
case V_24 :
if ( V_49 > 0 )
break;
case V_25 :
if ( V_49 < 0 )
V_27 -> V_30 = V_49 ;
F_37 ( V_27 ) ;
}
}
int F_45 ( void )
{
F_46 ( V_5 ) ;
int V_17 = 0 ;
F_47 ( & V_59 ) ;
for (; ; ) {
F_48 ( & V_60 , & V_5 ,
V_61 ) ;
if ( ! V_62 )
break;
if ( V_62 == V_63 )
V_17 = - V_64 ;
F_49 ( & V_59 ) ;
if ( V_17 )
break;
F_50 () ;
F_51 () ;
F_47 ( & V_59 ) ;
}
F_52 ( & V_60 , & V_5 ) ;
return V_17 ;
}
long F_53 ( long V_65 )
{
F_46 ( V_5 ) ;
if ( V_65 < 0 )
return - V_66 ;
F_47 ( & V_59 ) ;
for (; ; ) {
F_48 ( & V_60 , & V_5 ,
V_67 ) ;
if ( ! V_62 )
break;
F_49 ( & V_59 ) ;
V_65 = F_54 ( V_65 ) ;
if ( ! V_65 )
break;
F_47 ( & V_59 ) ;
}
F_52 ( & V_60 , & V_5 ) ;
return V_65 ;
}
void F_55 ( void )
{
F_49 ( & V_59 ) ;
}
void F_56 ( enum V_68 V_69 )
{
F_57 ( & V_59 ) ;
V_62 = V_69 ;
F_58 ( & V_60 ) ;
F_59 ( & V_59 ) ;
}
int F_60 ( enum V_68 V_69 )
{
long V_30 ;
if ( ! V_69 )
return - V_66 ;
F_57 ( & V_59 ) ;
V_62 = V_69 ;
F_59 ( & V_59 ) ;
V_30 = F_61 ( V_70 ,
F_16 ( & V_71 ) == 0 ,
V_72 ) ;
if ( V_30 )
return 0 ;
F_56 ( V_73 ) ;
return - V_64 ;
}
static void F_62 ( void )
{
F_15 ( & V_71 ) ;
F_63 () ;
}
static void F_64 ( void )
{
if ( F_65 ( & V_71 ) )
F_58 ( & V_70 ) ;
}
struct V_1 * F_6 ( char * V_42 , char * * V_3 ,
char * * V_6 , T_4 V_74 ,
int (* V_41)( struct V_1 * V_2 , struct V_28 * V_29 ) ,
void (* V_45)( struct V_1 * V_2 ) ,
void * V_26 )
{
struct V_1 * V_27 ;
V_27 = F_66 ( sizeof( struct V_1 ) , V_74 ) ;
if ( ! V_27 )
goto V_8;
F_67 ( & V_27 -> V_54 , F_43 ) ;
V_27 -> V_42 = V_42 ;
V_27 -> V_3 = V_3 ;
V_27 -> V_6 = V_6 ;
V_27 -> V_45 = V_45 ;
V_27 -> V_41 = V_41 ;
V_27 -> V_26 = V_26 ;
V_8:
return V_27 ;
}
int F_7 ( struct V_1 * V_27 , int V_5 )
{
F_68 ( V_75 ) ;
int V_30 = 0 ;
if ( ! V_27 -> V_42 ) {
F_36 ( V_27 ) ;
return - V_66 ;
}
F_62 () ;
if ( ! V_76 || V_62 ) {
V_30 = - V_77 ;
goto V_8;
}
if ( V_5 != V_58 && V_31 == V_44 ) {
V_30 = - V_77 ;
goto V_8;
}
V_27 -> V_48 = & V_75 ;
V_27 -> V_5 = V_5 ;
F_69 ( V_76 , & V_27 -> V_54 ) ;
if ( V_5 == V_58 )
goto V_78;
if ( V_5 & V_12 ) {
V_30 = F_70 ( & V_75 ) ;
if ( ! V_30 )
goto V_79;
if ( F_38 ( & V_27 -> V_48 , NULL ) )
goto V_78;
}
F_71 ( & V_75 ) ;
V_79:
V_30 = V_27 -> V_30 ;
V_8:
F_36 ( V_27 ) ;
V_78:
F_64 () ;
return V_30 ;
}
int F_72 ( char * V_42 , char * * V_3 , char * * V_6 , int V_5 )
{
struct V_1 * V_2 ;
T_4 V_74 = ( V_5 == V_58 ) ? V_80 : V_7 ;
V_2 = F_6 ( V_42 , V_3 , V_6 , V_74 ,
NULL , NULL , NULL ) ;
if ( V_2 == NULL )
return - V_13 ;
return F_7 ( V_2 , V_5 ) ;
}
static int F_73 ( struct V_81 * V_82 , int V_83 ,
void V_43 * V_84 , T_5 * V_85 , T_6 * V_86 )
{
struct V_81 V_87 ;
unsigned long V_88 [ V_89 ] ;
T_7 V_90 ;
int V_91 , V_92 ;
if ( V_83 && ( ! F_74 ( V_93 ) ||
! F_74 ( V_94 ) ) )
return - V_95 ;
F_27 ( & V_36 ) ;
for ( V_92 = 0 ; V_92 < V_89 ; V_92 ++ ) {
if ( V_82 -> V_26 == V_96 )
V_88 [ V_92 ] = V_38 . V_97 [ V_92 ] ;
else if ( V_82 -> V_26 == V_98 )
V_88 [ V_92 ] = V_40 . V_97 [ V_92 ] ;
else
F_75 () ;
}
F_29 ( & V_36 ) ;
V_87 = * V_82 ;
V_87 . V_26 = & V_88 ;
V_91 = F_76 ( & V_87 , V_83 , V_84 , V_85 , V_86 ) ;
if ( V_91 < 0 )
return V_91 ;
for ( V_92 = 0 ; V_92 < V_89 ; V_92 ++ )
V_90 . V_97 [ V_92 ] = V_88 [ V_92 ] ;
F_27 ( & V_36 ) ;
if ( V_83 ) {
if ( V_82 -> V_26 == V_96 )
V_38 = F_28 ( V_38 , V_90 ) ;
if ( V_82 -> V_26 == V_98 )
V_40 = F_28 ( V_40 , V_90 ) ;
}
F_29 ( & V_36 ) ;
return 0 ;
}
void T_8 F_77 ( void )
{
V_76 = F_78 ( L_7 ) ;
F_79 ( ! V_76 ) ;
}
