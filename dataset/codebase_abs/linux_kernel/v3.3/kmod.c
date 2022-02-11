int F_1 ( bool V_1 , const char * V_2 , ... )
{
T_1 args ;
char V_3 [ V_4 ] ;
unsigned int V_5 ;
int V_6 ;
char * V_7 [] = { V_8 , L_1 , L_2 , V_3 , NULL } ;
static char * V_9 [] = { L_3 ,
L_4 ,
L_5 ,
NULL } ;
static T_2 V_10 = F_2 ( 0 ) ;
#define F_3 50
static int V_11 ;
va_start ( args , V_2 ) ;
V_6 = vsnprintf ( V_3 , V_4 , V_2 , args ) ;
va_end ( args ) ;
if ( V_6 >= V_4 )
return - V_12 ;
V_6 = F_4 ( V_3 ) ;
if ( V_6 )
return V_6 ;
V_5 = F_5 ( V_13 / 2 , F_3 ) ;
F_6 ( & V_10 ) ;
if ( F_7 ( & V_10 ) > V_5 ) {
if ( V_11 < 5 ) {
F_8 ( V_14
L_6 ,
V_3 ) ;
V_11 ++ ;
}
F_9 ( & V_10 ) ;
return - V_15 ;
}
F_10 ( V_3 , V_1 , V_16 ) ;
V_6 = F_11 ( V_8 , V_7 , V_9 ,
V_1 ? V_17 : V_18 ,
NULL , NULL , NULL ) ;
F_9 ( & V_10 ) ;
return V_6 ;
}
static int F_12 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_23 ;
int V_24 ;
F_13 ( & V_25 -> V_26 -> V_27 ) ;
F_14 ( V_25 , 1 ) ;
F_15 ( & V_25 -> V_26 -> V_27 ) ;
F_16 ( V_25 , V_28 ) ;
F_17 ( V_25 , 0 ) ;
V_24 = - V_15 ;
V_23 = F_18 ( V_25 ) ;
if ( ! V_23 )
goto V_29;
F_19 ( & V_30 ) ;
V_23 -> V_31 = F_20 ( V_32 , V_23 -> V_31 ) ;
V_23 -> V_33 = F_20 ( V_34 ,
V_23 -> V_33 ) ;
F_21 ( & V_30 ) ;
if ( V_21 -> V_35 ) {
V_24 = V_21 -> V_35 ( V_21 , V_23 ) ;
if ( V_24 ) {
F_22 ( V_23 ) ;
goto V_29;
}
}
F_23 ( V_23 ) ;
V_24 = F_24 ( V_21 -> V_36 ,
( const char * const * ) V_21 -> V_7 ,
( const char * const * ) V_21 -> V_9 ) ;
V_29:
V_21 -> V_24 = V_24 ;
F_25 ( 0 ) ;
}
void F_26 ( struct V_20 * V_37 )
{
if ( V_37 -> V_38 )
(* V_37 -> V_38 )( V_37 ) ;
F_27 ( V_37 ) ;
}
static int F_28 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
T_3 V_39 ;
F_13 ( & V_25 -> V_26 -> V_27 ) ;
V_25 -> V_26 -> V_40 [ V_41 - 1 ] . V_42 . V_43 = V_44 ;
F_15 ( & V_25 -> V_26 -> V_27 ) ;
V_39 = F_29 ( F_12 , V_21 , V_41 ) ;
if ( V_39 < 0 ) {
V_21 -> V_24 = V_39 ;
} else {
int V_6 = - V_45 ;
F_30 ( V_39 , ( int V_46 * ) & V_6 , 0 , NULL ) ;
if ( V_6 )
V_21 -> V_24 = V_6 ;
}
F_31 ( V_21 -> F_31 ) ;
return 0 ;
}
static void F_32 ( struct V_47 * V_48 )
{
struct V_20 * V_21 =
F_33 ( V_48 , struct V_20 , V_48 ) ;
enum V_49 V_1 = V_21 -> V_1 ;
T_3 V_39 ;
if ( V_1 == V_17 )
V_39 = F_29 ( F_28 , V_21 ,
V_50 | V_51 | V_41 ) ;
else
V_39 = F_29 ( F_12 , V_21 ,
V_52 | V_41 ) ;
switch ( V_1 ) {
case V_53 :
F_26 ( V_21 ) ;
break;
case V_17 :
if ( V_39 > 0 )
break;
case V_18 :
if ( V_39 < 0 )
V_21 -> V_24 = V_39 ;
F_31 ( V_21 -> F_31 ) ;
}
}
void F_34 ( void )
{
F_35 ( & V_54 ) ;
}
void F_36 ( void )
{
F_37 ( & V_54 ) ;
}
int F_38 ( void )
{
long V_24 ;
F_39 ( & V_54 ) ;
V_55 = 1 ;
F_40 ( & V_54 ) ;
V_24 = F_41 ( V_56 ,
F_7 ( & V_57 ) == 0 ,
V_58 ) ;
if ( V_24 )
return 0 ;
F_39 ( & V_54 ) ;
V_55 = 0 ;
F_40 ( & V_54 ) ;
return - V_59 ;
}
void F_42 ( void )
{
F_39 ( & V_54 ) ;
V_55 = 0 ;
F_40 ( & V_54 ) ;
}
bool F_43 ( void )
{
return V_55 ;
}
static void F_44 ( void )
{
F_6 ( & V_57 ) ;
F_45 () ;
}
static void F_46 ( void )
{
if ( F_47 ( & V_57 ) )
F_48 ( & V_56 ) ;
}
struct V_20 * F_49 ( char * V_36 , char * * V_7 ,
char * * V_9 , T_4 V_60 )
{
struct V_20 * V_21 ;
V_21 = F_50 ( sizeof( struct V_20 ) , V_60 ) ;
if ( ! V_21 )
goto V_61;
F_51 ( & V_21 -> V_48 , F_32 ) ;
V_21 -> V_36 = V_36 ;
V_21 -> V_7 = V_7 ;
V_21 -> V_9 = V_9 ;
V_61:
return V_21 ;
}
void F_52 ( struct V_20 * V_37 ,
int (* V_35)( struct V_20 * V_37 , struct V_22 * V_23 ) ,
void (* V_38)( struct V_20 * V_37 ) ,
void * V_19 )
{
V_37 -> V_38 = V_38 ;
V_37 -> V_35 = V_35 ;
V_37 -> V_19 = V_19 ;
}
int F_53 ( struct V_20 * V_21 ,
enum V_49 V_1 )
{
F_54 ( V_62 ) ;
int V_24 = 0 ;
F_44 () ;
if ( V_21 -> V_36 [ 0 ] == '\0' )
goto V_61;
if ( ! V_63 || V_55 ) {
V_24 = - V_64 ;
goto V_61;
}
V_21 -> F_31 = & V_62 ;
V_21 -> V_1 = V_1 ;
F_55 ( V_63 , & V_21 -> V_48 ) ;
if ( V_1 == V_53 )
goto V_65;
F_56 ( & V_62 ) ;
V_24 = V_21 -> V_24 ;
V_61:
F_26 ( V_21 ) ;
V_65:
F_46 () ;
return V_24 ;
}
static int F_57 ( struct V_66 * V_67 , int V_68 ,
void V_46 * V_69 , T_5 * V_70 , T_6 * V_71 )
{
struct V_66 V_72 ;
unsigned long V_73 [ V_74 ] ;
T_7 V_75 ;
int V_76 , V_77 ;
if ( V_68 && ( ! F_58 ( V_78 ) ||
! F_58 ( V_79 ) ) )
return - V_80 ;
F_19 ( & V_30 ) ;
for ( V_77 = 0 ; V_77 < V_74 ; V_77 ++ ) {
if ( V_67 -> V_19 == V_81 )
V_73 [ V_77 ] = V_32 . V_82 [ V_77 ] ;
else if ( V_67 -> V_19 == V_83 )
V_73 [ V_77 ] = V_34 . V_82 [ V_77 ] ;
else
F_59 () ;
}
F_21 ( & V_30 ) ;
V_72 = * V_67 ;
V_72 . V_19 = & V_73 ;
V_76 = F_60 ( & V_72 , V_68 , V_69 , V_70 , V_71 ) ;
if ( V_76 < 0 )
return V_76 ;
for ( V_77 = 0 ; V_77 < V_74 ; V_77 ++ )
V_75 . V_82 [ V_77 ] = V_73 [ V_77 ] ;
F_19 ( & V_30 ) ;
if ( V_68 ) {
if ( V_67 -> V_19 == V_81 )
V_32 = F_20 ( V_32 , V_75 ) ;
if ( V_67 -> V_19 == V_83 )
V_34 = F_20 ( V_34 , V_75 ) ;
}
F_21 ( & V_30 ) ;
return 0 ;
}
void T_8 F_61 ( void )
{
V_63 = F_62 ( L_7 ) ;
F_63 ( ! V_63 ) ;
}
