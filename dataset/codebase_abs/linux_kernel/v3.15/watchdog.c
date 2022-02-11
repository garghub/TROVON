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
static int F_6 ( void )
{
return V_5 * 2 ;
}
static unsigned long F_7 ( void )
{
return F_8 () >> 30LL ;
}
static void F_9 ( void )
{
V_6 = F_6 () * ( ( V_7 ) V_8 / 5 ) ;
}
static void F_10 ( void )
{
F_11 ( V_9 , F_7 () ) ;
}
void F_12 ( void )
{
F_13 ( V_9 , 0 ) ;
}
void F_14 ( void )
{
int V_10 ;
F_15 (cpu)
F_16 ( V_9 , V_10 ) = 0 ;
}
void F_17 ( void )
{
F_18 ( V_11 ) = true ;
F_12 () ;
}
void F_19 ( void )
{
F_18 ( V_12 ) = true ;
F_18 ( V_9 ) = 0 ;
}
static int F_20 ( void )
{
unsigned long V_13 = F_21 ( V_14 ) ;
if ( F_21 ( V_15 ) == V_13 )
return 1 ;
F_11 ( V_15 , V_13 ) ;
return 0 ;
}
static int F_22 ( unsigned long V_16 )
{
unsigned long V_17 = F_7 () ;
if ( F_23 ( V_17 , V_16 + F_6 () ) )
return V_17 - V_16 ;
return 0 ;
}
static void F_24 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
V_19 -> V_24 . V_25 = 0 ;
if ( F_21 ( V_11 ) == true ) {
F_11 ( V_11 , false ) ;
return;
}
if ( F_20 () ) {
int V_26 = F_25 () ;
if ( F_21 ( V_27 ) == true )
return;
if ( V_2 )
F_26 ( L_4 , V_26 ) ;
else
F_27 ( 1 , L_4 , V_26 ) ;
F_11 ( V_27 , true ) ;
return;
}
F_11 ( V_27 , false ) ;
return;
}
static void F_28 ( void )
{
F_29 ( V_14 ) ;
}
static enum V_28 F_30 ( struct V_29 * V_29 )
{
unsigned long V_16 = F_21 ( V_9 ) ;
struct V_22 * V_23 = F_31 () ;
int V_30 ;
F_28 () ;
F_32 ( F_21 ( V_31 ) ) ;
F_33 ( V_29 , F_34 ( V_6 ) ) ;
if ( V_16 == 0 ) {
if ( F_35 ( F_21 ( V_12 ) ) ) {
F_11 ( V_12 , false ) ;
F_36 () ;
}
F_37 () ;
F_10 () ;
return V_32 ;
}
V_30 = F_22 ( V_16 ) ;
if ( F_35 ( V_30 ) ) {
if ( F_37 () )
return V_32 ;
if ( F_21 ( V_33 ) == true )
return V_32 ;
F_38 ( V_34 L_5 ,
F_25 () , V_30 ,
V_35 -> V_36 , F_39 ( V_35 ) ) ;
F_40 () ;
F_41 ( V_35 ) ;
if ( V_23 )
F_42 ( V_23 ) ;
else
F_43 () ;
if ( V_4 )
F_26 ( L_6 ) ;
F_11 ( V_33 , true ) ;
} else
F_11 ( V_33 , false ) ;
return V_32 ;
}
static void F_44 ( unsigned int V_37 , unsigned int V_38 )
{
struct V_39 V_40 = { . V_41 = V_38 } ;
F_45 ( V_35 , V_37 , & V_40 ) ;
}
static void F_46 ( unsigned int V_10 )
{
struct V_29 * V_29 = & F_18 ( V_42 ) ;
F_47 ( V_29 , V_43 , V_44 ) ;
V_29 -> V_45 = F_30 ;
F_48 ( V_10 ) ;
F_49 ( V_29 , F_34 ( V_6 ) ,
V_46 ) ;
F_44 ( V_47 , V_48 - 1 ) ;
F_10 () ;
}
static void F_50 ( unsigned int V_10 )
{
struct V_29 * V_29 = & F_18 ( V_42 ) ;
F_44 ( V_49 , 0 ) ;
F_51 ( V_29 ) ;
F_52 ( V_10 ) ;
}
static void F_53 ( unsigned int V_10 , bool V_50 )
{
F_50 ( V_10 ) ;
}
static int F_54 ( unsigned int V_10 )
{
return F_21 ( V_14 ) !=
F_21 ( V_51 ) ;
}
static void F_55 ( unsigned int V_10 )
{
F_11 ( V_51 ,
F_21 ( V_14 ) ) ;
F_10 () ;
}
static int F_48 ( unsigned int V_10 )
{
struct V_52 * V_53 ;
struct V_18 * V_19 = F_16 ( V_54 , V_10 ) ;
if ( V_19 && V_19 -> V_55 > V_56 )
goto V_57;
if ( V_19 != NULL )
goto V_58;
V_53 = & V_59 ;
V_53 -> V_6 = F_56 ( V_5 ) ;
V_19 = F_57 ( V_53 , V_10 , NULL , F_24 , NULL ) ;
if ( V_10 == 0 && F_58 ( V_19 ) )
V_60 = F_59 ( V_19 ) ;
if ( ! F_58 ( V_19 ) ) {
if ( V_10 == 0 || V_60 )
F_60 ( L_7 ) ;
goto V_61;
}
if ( V_10 > 0 && ( F_59 ( V_19 ) == V_60 ) )
return F_59 ( V_19 ) ;
if ( F_59 ( V_19 ) == - V_62 )
F_60 ( L_8 , V_10 ) ;
else if ( F_59 ( V_19 ) == - V_63 )
F_61 ( L_9 ,
V_10 ) ;
else
F_62 ( L_10 ,
V_10 , F_59 ( V_19 ) ) ;
return F_59 ( V_19 ) ;
V_61:
F_16 ( V_54 , V_10 ) = V_19 ;
V_58:
F_63 ( F_16 ( V_54 , V_10 ) ) ;
V_57:
return 0 ;
}
static void F_52 ( unsigned int V_10 )
{
struct V_18 * V_19 = F_16 ( V_54 , V_10 ) ;
if ( V_19 ) {
F_64 ( V_19 ) ;
F_16 ( V_54 , V_10 ) = NULL ;
F_65 ( V_19 ) ;
}
return;
}
static int F_48 ( unsigned int V_10 ) { return 0 ; }
static void F_52 ( unsigned int V_10 ) { return; }
static void F_66 ( void * V_64 )
{
struct V_29 * V_29 = & F_18 ( V_42 ) ;
int V_65 ;
V_65 = F_67 ( V_29 ) ;
if ( V_65 == 1 )
F_49 ( V_29 , F_34 ( V_6 ) ,
V_46 ) ;
}
static void F_68 ( int V_10 )
{
F_52 ( V_10 ) ;
F_69 ( V_10 , F_66 , NULL , 1 ) ;
F_48 ( V_10 ) ;
}
static void F_70 ( void )
{
int V_10 ;
F_71 () ;
F_72 () ;
F_15 (cpu)
F_68 ( V_10 ) ;
F_73 () ;
F_74 () ;
}
static int F_75 ( bool V_66 )
{
int V_67 = 0 ;
if ( ! V_68 ) {
V_67 = F_76 ( & V_69 ) ;
if ( V_67 )
F_62 ( L_11 ) ;
else
V_68 = 1 ;
} else if ( V_66 ) {
F_70 () ;
}
return V_67 ;
}
static void F_77 ( void )
{
if ( V_68 ) {
V_68 = 0 ;
F_78 ( & V_69 ) ;
}
}
int F_79 ( struct V_70 * V_71 , int V_72 ,
void T_2 * V_73 , T_3 * V_74 , T_4 * V_75 )
{
int V_67 , V_76 , V_77 ;
static F_80 ( V_78 ) ;
F_81 ( & V_78 ) ;
V_76 = F_82 ( V_5 ) ;
V_77 = F_82 ( V_3 ) ;
V_67 = F_83 ( V_71 , V_72 , V_73 , V_74 , V_75 ) ;
if ( V_67 || ! V_72 )
goto V_57;
F_9 () ;
if ( V_3 && V_5 )
V_67 = F_75 ( V_76 != V_5 ) ;
else
F_77 () ;
if ( V_67 ) {
V_5 = V_76 ;
V_3 = V_77 ;
}
V_57:
F_84 ( & V_78 ) ;
return V_67 ;
}
void T_1 F_85 ( void )
{
F_9 () ;
if ( V_3 )
F_75 ( false ) ;
}
