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
static unsigned long F_7 ( int V_6 )
{
return F_8 ( V_6 ) >> 30LL ;
}
static T_2 F_9 ( void )
{
return F_6 () * ( ( T_2 ) V_7 / 5 ) ;
}
static void F_10 ( void )
{
int V_6 = F_11 () ;
F_12 ( V_8 , F_7 ( V_6 ) ) ;
}
void F_13 ( void )
{
F_12 ( V_8 , 0 ) ;
}
void F_14 ( void )
{
int V_9 ;
F_15 (cpu)
F_16 ( V_8 , V_9 ) = 0 ;
}
void F_17 ( void )
{
if ( V_3 ) {
unsigned V_9 ;
F_18 (cpu) {
if ( F_16 ( V_10 , V_9 ) != true )
F_16 ( V_10 , V_9 ) = true ;
}
}
F_13 () ;
}
void F_19 ( void )
{
F_20 ( V_11 ) = true ;
F_20 ( V_8 ) = 0 ;
}
static int F_21 ( void )
{
unsigned long V_12 = F_22 ( V_13 ) ;
if ( F_22 ( V_14 ) == V_12 )
return 1 ;
F_12 ( V_14 , V_12 ) ;
return 0 ;
}
static int F_23 ( unsigned long V_15 )
{
unsigned long V_16 = F_7 ( F_11 () ) ;
if ( F_24 ( V_16 , V_15 + F_6 () ) )
return V_16 - V_15 ;
return 0 ;
}
static void F_25 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
V_18 -> V_23 . V_24 = 0 ;
if ( F_22 ( V_10 ) == true ) {
F_12 ( V_10 , false ) ;
return;
}
if ( F_21 () ) {
int V_6 = F_11 () ;
if ( F_22 ( V_25 ) == true )
return;
if ( V_2 )
F_26 ( L_4 , V_6 ) ;
else
F_27 ( 1 , L_4 , V_6 ) ;
F_12 ( V_25 , true ) ;
return;
}
F_12 ( V_25 , false ) ;
return;
}
static void F_28 ( void )
{
F_29 ( V_13 ) ;
}
static enum V_26 F_30 ( struct V_27 * V_27 )
{
unsigned long V_15 = F_22 ( V_8 ) ;
struct V_21 * V_22 = F_31 () ;
int V_28 ;
F_28 () ;
F_32 ( F_22 ( V_29 ) ) ;
F_33 ( V_27 , F_34 ( F_9 () ) ) ;
if ( V_15 == 0 ) {
if ( F_35 ( F_22 ( V_11 ) ) ) {
F_12 ( V_11 , false ) ;
F_36 () ;
}
F_37 () ;
F_10 () ;
return V_30 ;
}
V_28 = F_23 ( V_15 ) ;
if ( F_35 ( V_28 ) ) {
if ( F_37 () )
return V_30 ;
if ( F_22 ( V_31 ) == true )
return V_30 ;
F_38 ( V_32 L_5 ,
F_11 () , V_28 ,
V_33 -> V_34 , F_39 ( V_33 ) ) ;
F_40 () ;
F_41 ( V_33 ) ;
if ( V_22 )
F_42 ( V_22 ) ;
else
F_43 () ;
if ( V_4 )
F_26 ( L_6 ) ;
F_12 ( V_31 , true ) ;
} else
F_12 ( V_31 , false ) ;
return V_30 ;
}
static void F_44 ( unsigned int V_35 , unsigned int V_36 )
{
struct V_37 V_38 = { . V_39 = V_36 } ;
F_45 ( V_33 , V_35 , & V_38 ) ;
}
static void F_46 ( unsigned int V_9 )
{
struct V_27 * V_27 = & F_20 ( V_40 ) ;
if ( ! V_3 ) {
F_47 ( V_33 ) ;
return;
}
F_48 ( V_9 ) ;
F_49 ( V_27 , V_41 , V_42 ) ;
V_27 -> V_43 = F_30 ;
F_50 ( V_27 , F_34 ( F_9 () ) ,
V_44 ) ;
F_44 ( V_45 , V_46 - 1 ) ;
F_10 () ;
}
static void F_51 ( unsigned int V_9 )
{
struct V_27 * V_27 = & F_20 ( V_40 ) ;
if ( ! V_3 )
return;
F_44 ( V_47 , 0 ) ;
F_52 ( V_27 ) ;
F_53 ( V_9 ) ;
}
static int F_54 ( unsigned int V_9 )
{
return F_22 ( V_13 ) !=
F_22 ( V_48 ) ;
}
static void F_55 ( unsigned int V_9 )
{
F_12 ( V_48 ,
F_22 ( V_13 ) ) ;
F_10 () ;
}
static int F_48 ( unsigned int V_9 )
{
struct V_49 * V_50 ;
struct V_17 * V_18 = F_16 ( V_51 , V_9 ) ;
if ( V_18 && V_18 -> V_52 > V_53 )
goto V_54;
if ( V_18 != NULL )
goto V_55;
V_50 = & V_56 ;
V_50 -> V_57 = F_56 ( V_5 ) ;
V_18 = F_57 ( V_50 , V_9 , NULL , F_25 , NULL ) ;
if ( V_9 == 0 && F_58 ( V_18 ) )
V_58 = F_59 ( V_18 ) ;
if ( ! F_58 ( V_18 ) ) {
if ( V_9 == 0 || V_58 )
F_60 ( L_7 ) ;
goto V_59;
}
if ( V_9 > 0 && ( F_59 ( V_18 ) == V_58 ) )
return F_59 ( V_18 ) ;
if ( F_59 ( V_18 ) == - V_60 )
F_60 ( L_8 , V_9 ) ;
else if ( F_59 ( V_18 ) == - V_61 )
F_61 ( L_9 ,
V_9 ) ;
else
F_62 ( L_10 ,
V_9 , F_59 ( V_18 ) ) ;
return F_59 ( V_18 ) ;
V_59:
F_16 ( V_51 , V_9 ) = V_18 ;
V_55:
F_63 ( F_16 ( V_51 , V_9 ) ) ;
V_54:
return 0 ;
}
static void F_53 ( unsigned int V_9 )
{
struct V_17 * V_18 = F_16 ( V_51 , V_9 ) ;
if ( V_18 ) {
F_64 ( V_18 ) ;
F_16 ( V_51 , V_9 ) = NULL ;
F_65 ( V_18 ) ;
}
return;
}
static int F_48 ( unsigned int V_9 ) { return 0 ; }
static void F_53 ( unsigned int V_9 ) { return; }
static void F_66 ( void )
{
unsigned int V_9 ;
if ( V_62 ) {
V_62 = 0 ;
F_15 (cpu)
F_67 ( F_16 ( V_29 , V_9 ) ) ;
}
}
static void F_68 ( void )
{
unsigned int V_9 ;
if ( ! V_62 ) {
V_62 = 1 ;
F_15 (cpu)
F_47 ( F_16 ( V_29 , V_9 ) ) ;
}
}
int F_69 ( struct V_63 * V_64 , int V_65 ,
void T_3 * V_66 , T_4 * V_67 , T_5 * V_68 )
{
int V_69 ;
if ( V_62 < 0 )
return - V_70 ;
V_69 = F_70 ( V_64 , V_65 , V_66 , V_67 , V_68 ) ;
if ( V_69 || ! V_65 )
return V_69 ;
if ( V_3 && V_5 )
F_66 () ;
else
F_68 () ;
return V_69 ;
}
void T_1 F_71 ( void )
{
if ( F_72 ( & V_71 ) ) {
F_62 ( L_11 ) ;
V_62 = - V_70 ;
}
}
