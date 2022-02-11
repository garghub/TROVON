void F_1 ( bool V_1 )
{
V_2 = V_1 ;
}
bool F_2 ( void )
{
return V_2 ;
}
static int T_1 F_3 ( char * V_3 )
{
if ( ! strncmp ( V_3 , L_1 , 5 ) )
V_4 = 1 ;
else if ( ! strncmp ( V_3 , L_2 , 7 ) )
V_4 = 0 ;
else if ( ! strncmp ( V_3 , L_3 , 1 ) )
V_5 = 0 ;
else if ( ! strncmp ( V_3 , L_4 , 1 ) || ! strncmp ( V_3 , L_5 , 1 ) ) {
V_5 = 1 ;
F_1 ( true ) ;
}
return 1 ;
}
static int T_1 F_4 ( char * V_3 )
{
V_6 = F_5 ( V_3 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_6 ( char * V_3 )
{
V_5 = 0 ;
return 1 ;
}
static int T_1 F_7 ( char * V_3 )
{
V_5 = 0 ;
return 1 ;
}
static int T_1 F_8 ( char * V_3 )
{
V_7 =
! ! F_9 ( V_3 , NULL , 0 ) ;
return 1 ;
}
static int F_10 ( void )
{
return V_8 * 2 ;
}
static unsigned long F_11 ( void )
{
return F_12 () >> 30LL ;
}
static void F_13 ( void )
{
V_9 = F_10 () * ( ( V_10 ) V_11 / 5 ) ;
}
static void F_14 ( void )
{
F_15 ( V_12 , F_11 () ) ;
}
void F_16 ( void )
{
F_17 ( V_12 , 0 ) ;
}
void F_18 ( void )
{
int V_13 ;
F_19 (cpu)
F_20 ( V_12 , V_13 ) = 0 ;
}
void F_21 ( void )
{
F_17 ( V_14 , true ) ;
F_16 () ;
}
void F_22 ( void )
{
F_15 ( V_15 , true ) ;
F_15 ( V_12 , 0 ) ;
}
static int F_23 ( void )
{
unsigned long V_16 = F_24 ( V_17 ) ;
if ( F_24 ( V_18 ) == V_16 )
return 1 ;
F_15 ( V_18 , V_16 ) ;
return 0 ;
}
static int F_25 ( unsigned long V_19 )
{
unsigned long V_20 = F_11 () ;
if ( F_26 ( V_20 , V_19 + F_10 () ) )
return V_20 - V_19 ;
return 0 ;
}
static void F_27 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_25 * V_26 )
{
V_22 -> V_27 . V_28 = 0 ;
if ( F_24 ( V_14 ) == true ) {
F_15 ( V_14 , false ) ;
return;
}
if ( F_23 () ) {
int V_29 = F_28 () ;
if ( F_24 ( V_30 ) == true )
return;
if ( V_4 )
F_29 ( L_6 ,
V_29 ) ;
else
F_30 ( 1 , L_6 ,
V_29 ) ;
F_15 ( V_30 , true ) ;
return;
}
F_15 ( V_30 , false ) ;
return;
}
static void F_31 ( void )
{
F_32 ( V_17 ) ;
}
static enum V_31 F_33 ( struct V_32 * V_32 )
{
unsigned long V_19 = F_24 ( V_12 ) ;
struct V_25 * V_26 = F_34 () ;
int V_33 ;
int V_34 = V_7 ;
F_31 () ;
F_35 ( F_24 ( V_35 ) ) ;
F_36 ( V_32 , F_37 ( V_9 ) ) ;
if ( V_19 == 0 ) {
if ( F_38 ( F_24 ( V_15 ) ) ) {
F_15 ( V_15 , false ) ;
F_39 () ;
}
F_40 () ;
F_14 () ;
return V_36 ;
}
V_33 = F_25 ( V_19 ) ;
if ( F_38 ( V_33 ) ) {
if ( F_40 () )
return V_36 ;
if ( F_24 ( V_37 ) == true ) {
if ( F_24 ( V_38 ) !=
V_39 ) {
F_15 ( V_37 , false ) ;
F_14 () ;
}
return V_36 ;
}
if ( V_34 ) {
if ( F_41 ( 0 , & V_40 ) ) {
F_15 ( V_37 , true ) ;
return V_36 ;
}
}
F_42 ( L_7 ,
F_28 () , V_33 ,
V_39 -> V_41 , F_43 ( V_39 ) ) ;
F_15 ( V_38 , V_39 ) ;
F_44 () ;
F_45 ( V_39 ) ;
if ( V_26 )
F_46 ( V_26 ) ;
else
F_47 () ;
if ( V_34 ) {
F_48 () ;
F_49 ( 0 , & V_40 ) ;
F_50 () ;
}
F_51 ( V_42 , V_43 ) ;
if ( V_6 )
F_29 ( L_8 ) ;
F_15 ( V_37 , true ) ;
} else
F_15 ( V_37 , false ) ;
return V_36 ;
}
static void F_52 ( unsigned int V_44 , unsigned int V_45 )
{
struct V_46 V_47 = { . V_48 = V_45 } ;
F_53 ( V_39 , V_44 , & V_47 ) ;
}
static void F_54 ( unsigned int V_13 )
{
struct V_32 * V_32 = F_55 ( & V_49 ) ;
F_56 ( V_32 , V_50 , V_51 ) ;
V_32 -> V_52 = F_33 ;
F_57 ( V_13 ) ;
F_58 ( V_32 , F_37 ( V_9 ) ,
V_53 ) ;
F_52 ( V_54 , V_55 - 1 ) ;
F_14 () ;
}
static void F_59 ( unsigned int V_13 )
{
struct V_32 * V_32 = F_55 ( & V_49 ) ;
F_52 ( V_56 , 0 ) ;
F_60 ( V_32 ) ;
F_61 ( V_13 ) ;
}
static void F_62 ( unsigned int V_13 , bool V_57 )
{
F_59 ( V_13 ) ;
}
static int F_63 ( unsigned int V_13 )
{
return F_24 ( V_17 ) !=
F_24 ( V_58 ) ;
}
static void F_64 ( unsigned int V_13 )
{
F_15 ( V_58 ,
F_24 ( V_17 ) ) ;
F_14 () ;
}
static int F_57 ( unsigned int V_13 )
{
struct V_59 * V_60 ;
struct V_21 * V_22 = F_20 ( V_61 , V_13 ) ;
if ( ! F_2 () ) {
V_22 = F_65 ( - V_62 ) ;
goto V_63;
}
if ( V_22 && V_22 -> V_64 > V_65 )
goto V_66;
if ( V_22 != NULL )
goto V_67;
V_60 = & V_68 ;
V_60 -> V_9 = F_66 ( V_8 ) ;
V_22 = F_67 ( V_60 , V_13 , NULL , F_27 , NULL ) ;
V_63:
if ( V_13 == 0 && F_68 ( V_22 ) )
V_69 = F_69 ( V_22 ) ;
if ( ! F_68 ( V_22 ) ) {
if ( V_13 == 0 || V_69 )
F_70 ( L_9 ) ;
goto V_70;
}
if ( V_13 > 0 && ( F_69 ( V_22 ) == V_69 ) )
return F_69 ( V_22 ) ;
if ( F_69 ( V_22 ) == - V_71 )
F_70 ( L_10 , V_13 ) ;
else if ( F_69 ( V_22 ) == - V_62 )
F_71 ( L_11 ,
V_13 ) ;
else
F_72 ( L_12 ,
V_13 , F_69 ( V_22 ) ) ;
return F_69 ( V_22 ) ;
V_70:
F_20 ( V_61 , V_13 ) = V_22 ;
V_67:
F_73 ( F_20 ( V_61 , V_13 ) ) ;
V_66:
return 0 ;
}
static void F_61 ( unsigned int V_13 )
{
struct V_21 * V_22 = F_20 ( V_61 , V_13 ) ;
if ( V_22 ) {
F_74 ( V_22 ) ;
F_20 ( V_61 , V_13 ) = NULL ;
F_75 ( V_22 ) ;
}
if ( V_13 == 0 ) {
V_69 = 0 ;
}
}
static int F_57 ( unsigned int V_13 ) { return 0 ; }
static void F_61 ( unsigned int V_13 ) { return; }
static void F_76 ( void * V_72 )
{
struct V_32 * V_32 = F_55 ( & V_49 ) ;
int V_73 ;
V_73 = F_77 ( V_32 ) ;
if ( V_73 == 1 )
F_58 ( V_32 , F_37 ( V_9 ) ,
V_53 ) ;
}
static void F_78 ( int V_13 )
{
F_61 ( V_13 ) ;
F_79 ( V_13 , F_76 , NULL , 1 ) ;
F_57 ( V_13 ) ;
}
static void F_80 ( void )
{
int V_13 ;
F_81 () ;
F_19 (cpu)
F_78 ( V_13 ) ;
F_82 () ;
}
static int F_83 ( bool V_74 )
{
int V_75 = 0 ;
if ( ! V_76 ) {
V_75 = F_84 ( & V_77 ) ;
if ( V_75 )
F_72 ( L_13 ) ;
else
V_76 = 1 ;
} else if ( V_74 ) {
F_80 () ;
}
return V_75 ;
}
static void F_85 ( void )
{
if ( V_76 ) {
V_76 = 0 ;
F_86 ( & V_77 ) ;
}
}
int F_87 ( struct V_78 * V_79 , int V_80 ,
void T_2 * V_81 , T_3 * V_82 , T_4 * V_83 )
{
int V_75 , V_84 , V_85 ;
bool V_86 ;
static F_88 ( V_87 ) ;
F_89 ( & V_87 ) ;
V_84 = F_90 ( V_8 ) ;
V_85 = F_90 ( V_5 ) ;
V_86 = F_2 () ;
V_75 = F_91 ( V_79 , V_80 , V_81 , V_82 , V_83 ) ;
if ( V_75 || ! V_80 )
goto V_66;
F_13 () ;
if ( V_5 && V_8 ) {
if ( V_5 != V_85 )
F_1 ( true ) ;
V_75 = F_83 ( V_84 != V_8 ) ;
} else
F_85 () ;
if ( V_75 ) {
V_8 = V_84 ;
V_5 = V_85 ;
F_1 ( V_86 ) ;
}
V_66:
F_92 ( & V_87 ) ;
return V_75 ;
}
void T_1 F_93 ( void )
{
F_13 () ;
if ( V_5 )
F_83 ( false ) ;
}
