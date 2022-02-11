static int T_1 F_1 ( char * V_1 )
{
if ( ! strncmp ( V_1 , L_1 , 5 ) )
V_2 = 1 ;
else if ( ! strncmp ( V_1 , L_2 , 7 ) )
V_2 = 0 ;
else if ( ! strncmp ( V_1 , L_3 , 1 ) )
V_3 = 0 ;
return 1 ;
}
static int T_1 F_2 ( char * V_1 )
{
V_4 = F_3 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_4 ( char * V_1 )
{
V_3 = 0 ;
return 1 ;
}
static int T_1 F_5 ( char * V_1 )
{
V_3 = 0 ;
return 1 ;
}
static int T_1 F_6 ( char * V_1 )
{
V_5 =
! ! F_7 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static int F_8 ( void )
{
return V_6 * 2 ;
}
static unsigned long F_9 ( void )
{
return F_10 () >> 30LL ;
}
static void F_11 ( void )
{
V_7 = F_8 () * ( ( V_8 ) V_9 / 5 ) ;
}
static void F_12 ( void )
{
F_13 ( V_10 , F_9 () ) ;
}
void F_14 ( void )
{
F_15 ( V_10 , 0 ) ;
}
void F_16 ( void )
{
int V_11 ;
F_17 (cpu)
F_18 ( V_10 , V_11 ) = 0 ;
}
void F_19 ( void )
{
F_20 ( V_12 ) = true ;
F_14 () ;
}
void F_21 ( void )
{
F_20 ( V_13 ) = true ;
F_20 ( V_10 ) = 0 ;
}
static int F_22 ( void )
{
unsigned long V_14 = F_23 ( V_15 ) ;
if ( F_23 ( V_16 ) == V_14 )
return 1 ;
F_13 ( V_16 , V_14 ) ;
return 0 ;
}
static int F_24 ( unsigned long V_17 )
{
unsigned long V_18 = F_9 () ;
if ( F_25 ( V_18 , V_17 + F_8 () ) )
return V_18 - V_17 ;
return 0 ;
}
static void F_26 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
V_20 -> V_25 . V_26 = 0 ;
if ( F_23 ( V_12 ) == true ) {
F_13 ( V_12 , false ) ;
return;
}
if ( F_22 () ) {
int V_27 = F_27 () ;
if ( F_23 ( V_28 ) == true )
return;
if ( V_2 )
F_28 ( L_4 ,
V_27 ) ;
else
F_29 ( 1 , L_4 ,
V_27 ) ;
F_13 ( V_28 , true ) ;
return;
}
F_13 ( V_28 , false ) ;
return;
}
static void F_30 ( void )
{
F_31 ( V_15 ) ;
}
static enum V_29 F_32 ( struct V_30 * V_30 )
{
unsigned long V_17 = F_23 ( V_10 ) ;
struct V_23 * V_24 = F_33 () ;
int V_31 ;
int V_32 = V_5 ;
F_30 () ;
F_34 ( F_23 ( V_33 ) ) ;
F_35 ( V_30 , F_36 ( V_7 ) ) ;
if ( V_17 == 0 ) {
if ( F_37 ( F_23 ( V_13 ) ) ) {
F_13 ( V_13 , false ) ;
F_38 () ;
}
F_39 () ;
F_12 () ;
return V_34 ;
}
V_31 = F_24 ( V_17 ) ;
if ( F_37 ( V_31 ) ) {
if ( F_39 () )
return V_34 ;
if ( F_23 ( V_35 ) == true )
return V_34 ;
if ( V_32 ) {
if ( F_40 ( 0 , & V_36 ) ) {
F_13 ( V_35 , true ) ;
return V_34 ;
}
}
F_41 ( L_5 ,
F_27 () , V_31 ,
V_37 -> V_38 , F_42 ( V_37 ) ) ;
F_43 () ;
F_44 ( V_37 ) ;
if ( V_24 )
F_45 ( V_24 ) ;
else
F_46 () ;
if ( V_32 ) {
F_47 () ;
F_48 ( 0 , & V_36 ) ;
F_49 () ;
}
F_50 ( V_39 , V_40 ) ;
if ( V_4 )
F_28 ( L_6 ) ;
F_13 ( V_35 , true ) ;
} else
F_13 ( V_35 , false ) ;
return V_34 ;
}
static void F_51 ( unsigned int V_41 , unsigned int V_42 )
{
struct V_43 V_44 = { . V_45 = V_42 } ;
F_52 ( V_37 , V_41 , & V_44 ) ;
}
static void F_53 ( unsigned int V_11 )
{
struct V_30 * V_30 = & F_20 ( V_46 ) ;
F_54 ( V_30 , V_47 , V_48 ) ;
V_30 -> V_49 = F_32 ;
F_55 ( V_11 ) ;
F_56 ( V_30 , F_36 ( V_7 ) ,
V_50 ) ;
F_51 ( V_51 , V_52 - 1 ) ;
F_12 () ;
}
static void F_57 ( unsigned int V_11 )
{
struct V_30 * V_30 = & F_20 ( V_46 ) ;
F_51 ( V_53 , 0 ) ;
F_58 ( V_30 ) ;
F_59 ( V_11 ) ;
}
static void F_60 ( unsigned int V_11 , bool V_54 )
{
F_57 ( V_11 ) ;
}
static int F_61 ( unsigned int V_11 )
{
return F_23 ( V_15 ) !=
F_23 ( V_55 ) ;
}
static void F_62 ( unsigned int V_11 )
{
F_13 ( V_55 ,
F_23 ( V_15 ) ) ;
F_12 () ;
}
static int F_55 ( unsigned int V_11 )
{
struct V_56 * V_57 ;
struct V_19 * V_20 = F_18 ( V_58 , V_11 ) ;
if ( V_20 && V_20 -> V_59 > V_60 )
goto V_61;
if ( V_20 != NULL )
goto V_62;
V_57 = & V_63 ;
V_57 -> V_7 = F_63 ( V_6 ) ;
V_20 = F_64 ( V_57 , V_11 , NULL , F_26 , NULL ) ;
if ( V_11 == 0 && F_65 ( V_20 ) )
V_64 = F_66 ( V_20 ) ;
if ( ! F_65 ( V_20 ) ) {
if ( V_11 == 0 || V_64 )
F_67 ( L_7 ) ;
goto V_65;
}
if ( V_11 > 0 && ( F_66 ( V_20 ) == V_64 ) )
return F_66 ( V_20 ) ;
if ( F_66 ( V_20 ) == - V_66 )
F_67 ( L_8 , V_11 ) ;
else if ( F_66 ( V_20 ) == - V_67 )
F_68 ( L_9 ,
V_11 ) ;
else
F_69 ( L_10 ,
V_11 , F_66 ( V_20 ) ) ;
return F_66 ( V_20 ) ;
V_65:
F_18 ( V_58 , V_11 ) = V_20 ;
V_62:
F_70 ( F_18 ( V_58 , V_11 ) ) ;
V_61:
return 0 ;
}
static void F_59 ( unsigned int V_11 )
{
struct V_19 * V_20 = F_18 ( V_58 , V_11 ) ;
if ( V_20 ) {
F_71 ( V_20 ) ;
F_18 ( V_58 , V_11 ) = NULL ;
F_72 ( V_20 ) ;
}
return;
}
static int F_55 ( unsigned int V_11 ) { return 0 ; }
static void F_59 ( unsigned int V_11 ) { return; }
static void F_73 ( void * V_68 )
{
struct V_30 * V_30 = & F_20 ( V_46 ) ;
int V_69 ;
V_69 = F_74 ( V_30 ) ;
if ( V_69 == 1 )
F_56 ( V_30 , F_36 ( V_7 ) ,
V_50 ) ;
}
static void F_75 ( int V_11 )
{
F_59 ( V_11 ) ;
F_76 ( V_11 , F_73 , NULL , 1 ) ;
F_55 ( V_11 ) ;
}
static void F_77 ( void )
{
int V_11 ;
F_78 () ;
F_17 (cpu)
F_75 ( V_11 ) ;
F_79 () ;
}
static int F_80 ( bool V_70 )
{
int V_71 = 0 ;
if ( ! V_72 ) {
V_71 = F_81 ( & V_73 ) ;
if ( V_71 )
F_69 ( L_11 ) ;
else
V_72 = 1 ;
} else if ( V_70 ) {
F_77 () ;
}
return V_71 ;
}
static void F_82 ( void )
{
if ( V_72 ) {
V_72 = 0 ;
F_83 ( & V_73 ) ;
}
}
int F_84 ( struct V_74 * V_75 , int V_76 ,
void T_2 * V_77 , T_3 * V_78 , T_4 * V_79 )
{
int V_71 , V_80 , V_81 ;
static F_85 ( V_82 ) ;
F_86 ( & V_82 ) ;
V_80 = F_87 ( V_6 ) ;
V_81 = F_87 ( V_3 ) ;
V_71 = F_88 ( V_75 , V_76 , V_77 , V_78 , V_79 ) ;
if ( V_71 || ! V_76 )
goto V_61;
F_11 () ;
if ( V_3 && V_6 )
V_71 = F_80 ( V_80 != V_6 ) ;
else
F_82 () ;
if ( V_71 ) {
V_6 = V_80 ;
V_3 = V_81 ;
}
V_61:
F_89 ( & V_82 ) ;
return V_71 ;
}
void T_1 F_90 ( void )
{
F_11 () ;
if ( V_3 )
F_80 ( false ) ;
}
