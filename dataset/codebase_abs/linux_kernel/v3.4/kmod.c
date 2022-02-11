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
V_34:
V_26 -> V_29 = V_29 ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 )
(* V_2 -> V_42 )( V_2 ) ;
F_2 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_26 )
{
struct V_43 * V_44 = F_32 ( & V_26 -> V_45 , NULL ) ;
if ( V_44 )
V_45 ( V_44 ) ;
else
F_30 ( V_26 ) ;
}
static int F_33 ( void * V_25 )
{
struct V_1 * V_26 = V_25 ;
T_3 V_46 ;
F_18 ( & V_30 -> V_31 -> V_32 ) ;
V_30 -> V_31 -> V_47 [ V_48 - 1 ] . V_49 . V_50 = V_51 ;
F_20 ( & V_30 -> V_31 -> V_32 ) ;
V_46 = F_34 ( F_17 , V_26 , V_48 ) ;
if ( V_46 < 0 ) {
V_26 -> V_29 = V_46 ;
} else {
int V_16 = - V_52 ;
F_35 ( V_46 , ( int V_53 * ) & V_16 , 0 , NULL ) ;
if ( V_16 )
V_26 -> V_29 = V_16 ;
}
F_31 ( V_26 ) ;
return 0 ;
}
static void F_36 ( struct V_54 * V_55 )
{
struct V_1 * V_26 =
F_37 ( V_55 , struct V_1 , V_55 ) ;
int V_5 = V_26 -> V_5 & ~ V_11 ;
T_3 V_46 ;
if ( V_5 == V_23 )
V_46 = F_34 ( F_33 , V_26 ,
V_56 | V_57 | V_48 ) ;
else
V_46 = F_34 ( F_17 , V_26 ,
V_58 | V_48 ) ;
switch ( V_5 ) {
case V_59 :
F_30 ( V_26 ) ;
break;
case V_23 :
if ( V_46 > 0 )
break;
case V_24 :
if ( V_46 < 0 )
V_26 -> V_29 = V_46 ;
F_31 ( V_26 ) ;
}
}
int F_38 ( void )
{
F_39 ( V_5 ) ;
int V_16 = 0 ;
F_40 ( & V_60 ) ;
for (; ; ) {
F_41 ( & V_61 , & V_5 ,
V_62 ) ;
if ( ! V_63 )
break;
if ( V_63 == V_64 )
V_16 = - V_65 ;
F_42 ( & V_60 ) ;
if ( V_16 )
break;
F_43 () ;
F_44 () ;
F_40 ( & V_60 ) ;
}
F_45 ( & V_61 , & V_5 ) ;
return V_16 ;
}
long F_46 ( long V_66 )
{
F_39 ( V_5 ) ;
if ( V_66 < 0 )
return - V_67 ;
F_40 ( & V_60 ) ;
for (; ; ) {
F_41 ( & V_61 , & V_5 ,
V_68 ) ;
if ( ! V_63 )
break;
F_42 ( & V_60 ) ;
V_66 = F_47 ( V_66 ) ;
if ( ! V_66 )
break;
F_40 ( & V_60 ) ;
}
F_45 ( & V_61 , & V_5 ) ;
return V_66 ;
}
void F_48 ( void )
{
F_42 ( & V_60 ) ;
}
void F_49 ( enum V_69 V_70 )
{
F_50 ( & V_60 ) ;
V_63 = V_70 ;
F_51 ( & V_61 ) ;
F_52 ( & V_60 ) ;
}
int F_53 ( enum V_69 V_70 )
{
long V_29 ;
if ( ! V_70 )
return - V_67 ;
F_50 ( & V_60 ) ;
V_63 = V_70 ;
F_52 ( & V_60 ) ;
V_29 = F_54 ( V_71 ,
F_13 ( & V_72 ) == 0 ,
V_73 ) ;
if ( V_29 )
return 0 ;
F_49 ( V_74 ) ;
return - V_65 ;
}
static void F_55 ( void )
{
F_12 ( & V_72 ) ;
F_56 () ;
}
static void F_57 ( void )
{
if ( F_58 ( & V_72 ) )
F_51 ( & V_71 ) ;
}
struct V_1 * F_59 ( char * V_41 , char * * V_3 ,
char * * V_6 , T_4 V_75 )
{
struct V_1 * V_26 ;
V_26 = F_60 ( sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_26 )
goto V_8;
F_61 ( & V_26 -> V_55 , F_36 ) ;
V_26 -> V_41 = V_41 ;
V_26 -> V_3 = V_3 ;
V_26 -> V_6 = V_6 ;
V_8:
return V_26 ;
}
void F_62 ( struct V_1 * V_2 ,
int (* V_40)( struct V_1 * V_2 , struct V_27 * V_28 ) ,
void (* V_42)( struct V_1 * V_2 ) ,
void * V_25 )
{
V_2 -> V_42 = V_42 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_25 = V_25 ;
}
int F_63 ( struct V_1 * V_26 , int V_5 )
{
F_64 ( V_76 ) ;
int V_29 = 0 ;
F_55 () ;
if ( V_26 -> V_41 [ 0 ] == '\0' )
goto V_8;
if ( ! V_77 || V_63 ) {
V_29 = - V_78 ;
goto V_8;
}
V_26 -> V_45 = & V_76 ;
V_26 -> V_5 = V_5 ;
F_65 ( V_77 , & V_26 -> V_55 ) ;
if ( V_5 == V_59 )
goto V_79;
if ( V_5 & V_11 ) {
V_29 = F_66 ( & V_76 ) ;
if ( ! V_29 )
goto V_80;
if ( F_32 ( & V_26 -> V_45 , NULL ) )
goto V_79;
}
F_67 ( & V_76 ) ;
V_80:
V_29 = V_26 -> V_29 ;
V_8:
F_30 ( V_26 ) ;
V_79:
F_57 () ;
return V_29 ;
}
static int F_68 ( struct V_81 * V_82 , int V_83 ,
void V_53 * V_84 , T_5 * V_85 , T_6 * V_86 )
{
struct V_81 V_87 ;
unsigned long V_88 [ V_89 ] ;
T_7 V_90 ;
int V_91 , V_92 ;
if ( V_83 && ( ! F_69 ( V_93 ) ||
! F_69 ( V_94 ) ) )
return - V_95 ;
F_24 ( & V_35 ) ;
for ( V_92 = 0 ; V_92 < V_89 ; V_92 ++ ) {
if ( V_82 -> V_25 == V_96 )
V_88 [ V_92 ] = V_37 . V_97 [ V_92 ] ;
else if ( V_82 -> V_25 == V_98 )
V_88 [ V_92 ] = V_39 . V_97 [ V_92 ] ;
else
F_70 () ;
}
F_26 ( & V_35 ) ;
V_87 = * V_82 ;
V_87 . V_25 = & V_88 ;
V_91 = F_71 ( & V_87 , V_83 , V_84 , V_85 , V_86 ) ;
if ( V_91 < 0 )
return V_91 ;
for ( V_92 = 0 ; V_92 < V_89 ; V_92 ++ )
V_90 . V_97 [ V_92 ] = V_88 [ V_92 ] ;
F_24 ( & V_35 ) ;
if ( V_83 ) {
if ( V_82 -> V_25 == V_96 )
V_37 = F_25 ( V_37 , V_90 ) ;
if ( V_82 -> V_25 == V_98 )
V_39 = F_25 ( V_39 , V_90 ) ;
}
F_26 ( & V_35 ) ;
return 0 ;
}
void T_8 F_72 ( void )
{
V_77 = F_73 ( L_7 ) ;
F_74 ( ! V_77 ) ;
}
