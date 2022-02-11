static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 [ 3 ] ) ;
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( char * V_4 , int V_5 )
{
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
return F_6 ( V_10 , V_3 , V_6 ,
V_5 | V_11 , NULL , F_1 , NULL ) ;
V_9:
F_2 ( V_3 ) ;
V_8:
return - V_12 ;
}
int F_7 ( bool V_5 , const char * V_13 , ... )
{
T_1 args ;
char V_4 [ V_14 ] ;
unsigned int V_15 ;
int V_16 ;
static T_2 V_17 = F_8 ( 0 ) ;
#define F_9 50
static int V_18 ;
va_start ( args , V_13 ) ;
V_16 = vsnprintf ( V_4 , V_14 , V_13 , args ) ;
va_end ( args ) ;
if ( V_16 >= V_14 )
return - V_19 ;
V_16 = F_10 ( V_4 ) ;
if ( V_16 )
return V_16 ;
V_15 = F_11 ( V_20 / 2 , F_9 ) ;
F_12 ( & V_17 ) ;
if ( F_13 ( & V_17 ) > V_15 ) {
if ( V_18 < 5 ) {
F_14 ( V_21
L_6 ,
V_4 ) ;
V_18 ++ ;
}
F_15 ( & V_17 ) ;
return - V_12 ;
}
F_16 ( V_4 , V_5 , V_22 ) ;
V_16 = F_3 ( V_4 , V_5 ? V_23 : V_24 ) ;
F_15 ( & V_17 ) ;
return V_16 ;
}
static int F_17 ( void * V_25 )
{
struct V_1 * V_26 = V_25 ;
struct V_27 * V_28 ;
int V_29 ;
F_18 ( & V_30 -> V_31 -> V_32 ) ;
F_19 ( V_30 , 1 ) ;
F_20 ( & V_30 -> V_31 -> V_32 ) ;
F_21 ( V_30 , V_33 ) ;
F_22 ( V_30 , 0 ) ;
V_29 = - V_12 ;
V_28 = F_23 ( V_30 ) ;
if ( ! V_28 )
goto V_34;
F_24 ( & V_35 ) ;
V_28 -> V_36 = F_25 ( V_37 , V_28 -> V_36 ) ;
V_28 -> V_38 = F_25 ( V_39 ,
V_28 -> V_38 ) ;
F_26 ( & V_35 ) ;
if ( V_26 -> V_40 ) {
V_29 = V_26 -> V_40 ( V_26 , V_28 ) ;
if ( V_29 ) {
F_27 ( V_28 ) ;
goto V_34;
}
}
F_28 ( V_28 ) ;
V_29 = F_29 ( V_26 -> V_41 ,
( const char * const * ) V_26 -> V_3 ,
( const char * const * ) V_26 -> V_6 ) ;
if ( ! V_29 )
return 0 ;
V_34:
V_26 -> V_29 = V_29 ;
F_30 ( 0 ) ;
}
static int F_31 ( void * V_25 )
{
V_42 = V_30 ;
return F_17 ( V_25 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_43 )
(* V_2 -> V_43 )( V_2 ) ;
F_2 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_26 )
{
struct V_44 * V_45 = F_34 ( & V_26 -> V_46 , NULL ) ;
if ( V_45 )
V_46 ( V_45 ) ;
else
F_32 ( V_26 ) ;
}
static int F_35 ( void * V_25 )
{
struct V_1 * V_26 = V_25 ;
T_3 V_47 ;
F_18 ( & V_30 -> V_31 -> V_32 ) ;
V_30 -> V_31 -> V_48 [ V_49 - 1 ] . V_50 . V_51 = V_52 ;
F_20 ( & V_30 -> V_31 -> V_32 ) ;
V_47 = F_36 ( F_17 , V_26 , V_49 ) ;
if ( V_47 < 0 ) {
V_26 -> V_29 = V_47 ;
} else {
int V_16 = - V_53 ;
F_37 ( V_47 , ( int V_54 * ) & V_16 , 0 , NULL ) ;
if ( V_16 )
V_26 -> V_29 = V_16 ;
}
F_33 ( V_26 ) ;
F_30 ( 0 ) ;
}
static void F_38 ( struct V_55 * V_56 )
{
struct V_1 * V_26 =
F_39 ( V_56 , struct V_1 , V_56 ) ;
int V_5 = V_26 -> V_5 & ~ V_11 ;
T_3 V_47 ;
if ( V_5 == V_23 )
V_47 = F_36 ( F_35 , V_26 ,
V_57 | V_58 | V_49 ) ;
else {
V_47 = F_36 ( F_31 , V_26 ,
V_59 | V_49 ) ;
V_42 = NULL ;
}
switch ( V_5 ) {
case V_60 :
F_32 ( V_26 ) ;
break;
case V_23 :
if ( V_47 > 0 )
break;
case V_24 :
if ( V_47 < 0 )
V_26 -> V_29 = V_47 ;
F_33 ( V_26 ) ;
}
}
int F_40 ( void )
{
F_41 ( V_5 ) ;
int V_16 = 0 ;
F_42 ( & V_61 ) ;
for (; ; ) {
F_43 ( & V_62 , & V_5 ,
V_63 ) ;
if ( ! V_64 )
break;
if ( V_64 == V_65 )
V_16 = - V_66 ;
F_44 ( & V_61 ) ;
if ( V_16 )
break;
F_45 () ;
F_46 () ;
F_42 ( & V_61 ) ;
}
F_47 ( & V_62 , & V_5 ) ;
return V_16 ;
}
long F_48 ( long V_67 )
{
F_41 ( V_5 ) ;
if ( V_67 < 0 )
return - V_68 ;
F_42 ( & V_61 ) ;
for (; ; ) {
F_43 ( & V_62 , & V_5 ,
V_69 ) ;
if ( ! V_64 )
break;
F_44 ( & V_61 ) ;
V_67 = F_49 ( V_67 ) ;
if ( ! V_67 )
break;
F_42 ( & V_61 ) ;
}
F_47 ( & V_62 , & V_5 ) ;
return V_67 ;
}
void F_50 ( void )
{
F_44 ( & V_61 ) ;
}
void F_51 ( enum V_70 V_71 )
{
F_52 ( & V_61 ) ;
V_64 = V_71 ;
F_53 ( & V_62 ) ;
F_54 ( & V_61 ) ;
}
int F_55 ( enum V_70 V_71 )
{
long V_29 ;
if ( ! V_71 )
return - V_68 ;
F_52 ( & V_61 ) ;
V_64 = V_71 ;
F_54 ( & V_61 ) ;
V_29 = F_56 ( V_72 ,
F_13 ( & V_73 ) == 0 ,
V_74 ) ;
if ( V_29 )
return 0 ;
F_51 ( V_75 ) ;
return - V_66 ;
}
static void F_57 ( void )
{
F_12 ( & V_73 ) ;
F_58 () ;
}
static void F_59 ( void )
{
if ( F_60 ( & V_73 ) )
F_53 ( & V_72 ) ;
}
static
struct V_1 * F_61 ( char * V_41 , char * * V_3 ,
char * * V_6 , T_4 V_76 )
{
struct V_1 * V_26 ;
V_26 = F_62 ( sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_26 )
goto V_8;
F_63 ( & V_26 -> V_56 , F_38 ) ;
V_26 -> V_41 = V_41 ;
V_26 -> V_3 = V_3 ;
V_26 -> V_6 = V_6 ;
V_8:
return V_26 ;
}
static
void F_64 ( struct V_1 * V_2 ,
int (* V_40)( struct V_1 * V_2 , struct V_27 * V_28 ) ,
void (* V_43)( struct V_1 * V_2 ) ,
void * V_25 )
{
V_2 -> V_43 = V_43 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_25 = V_25 ;
}
static
int F_65 ( struct V_1 * V_26 , int V_5 )
{
F_66 ( V_77 ) ;
int V_29 = 0 ;
F_57 () ;
if ( V_26 -> V_41 [ 0 ] == '\0' )
goto V_8;
if ( ! V_78 || V_64 ) {
V_29 = - V_79 ;
goto V_8;
}
if ( V_5 != V_60 && V_30 == V_42 ) {
V_29 = - V_79 ;
goto V_8;
}
V_26 -> V_46 = & V_77 ;
V_26 -> V_5 = V_5 ;
F_67 ( V_78 , & V_26 -> V_56 ) ;
if ( V_5 == V_60 )
goto V_80;
if ( V_5 & V_11 ) {
V_29 = F_68 ( & V_77 ) ;
if ( ! V_29 )
goto V_81;
if ( F_34 ( & V_26 -> V_46 , NULL ) )
goto V_80;
}
F_69 ( & V_77 ) ;
V_81:
V_29 = V_26 -> V_29 ;
V_8:
F_32 ( V_26 ) ;
V_80:
F_59 () ;
return V_29 ;
}
int F_6 (
char * V_41 , char * * V_3 , char * * V_6 , int V_5 ,
int (* V_40)( struct V_1 * V_2 , struct V_27 * V_28 ) ,
void (* V_43)( struct V_1 * ) , void * V_25 )
{
struct V_1 * V_2 ;
T_4 V_76 = ( V_5 == V_60 ) ? V_82 : V_7 ;
V_2 = F_61 ( V_41 , V_3 , V_6 , V_76 ) ;
if ( V_2 == NULL )
return - V_12 ;
F_64 ( V_2 , V_40 , V_43 , V_25 ) ;
return F_65 ( V_2 , V_5 ) ;
}
static int F_70 ( struct V_83 * V_84 , int V_85 ,
void V_54 * V_86 , T_5 * V_87 , T_6 * V_88 )
{
struct V_83 V_89 ;
unsigned long V_90 [ V_91 ] ;
T_7 V_92 ;
int V_93 , V_94 ;
if ( V_85 && ( ! F_71 ( V_95 ) ||
! F_71 ( V_96 ) ) )
return - V_97 ;
F_24 ( & V_35 ) ;
for ( V_94 = 0 ; V_94 < V_91 ; V_94 ++ ) {
if ( V_84 -> V_25 == V_98 )
V_90 [ V_94 ] = V_37 . V_99 [ V_94 ] ;
else if ( V_84 -> V_25 == V_100 )
V_90 [ V_94 ] = V_39 . V_99 [ V_94 ] ;
else
F_72 () ;
}
F_26 ( & V_35 ) ;
V_89 = * V_84 ;
V_89 . V_25 = & V_90 ;
V_93 = F_73 ( & V_89 , V_85 , V_86 , V_87 , V_88 ) ;
if ( V_93 < 0 )
return V_93 ;
for ( V_94 = 0 ; V_94 < V_91 ; V_94 ++ )
V_92 . V_99 [ V_94 ] = V_90 [ V_94 ] ;
F_24 ( & V_35 ) ;
if ( V_85 ) {
if ( V_84 -> V_25 == V_98 )
V_37 = F_25 ( V_37 , V_92 ) ;
if ( V_84 -> V_25 == V_100 )
V_39 = F_25 ( V_39 , V_92 ) ;
}
F_26 ( & V_35 ) ;
return 0 ;
}
void T_8 F_74 ( void )
{
V_78 = F_75 ( L_7 ) ;
F_76 ( ! V_78 ) ;
}
