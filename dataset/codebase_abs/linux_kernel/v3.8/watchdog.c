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
static void F_9 ( void )
{
V_7 = F_6 () * ( ( V_8 ) V_9 / 5 ) ;
}
static void F_10 ( void )
{
int V_6 = F_11 () ;
F_12 ( V_10 , F_7 ( V_6 ) ) ;
}
void F_13 ( void )
{
F_12 ( V_10 , 0 ) ;
}
void F_14 ( void )
{
int V_11 ;
F_15 (cpu)
F_16 ( V_10 , V_11 ) = 0 ;
}
void F_17 ( void )
{
if ( V_3 ) {
unsigned V_11 ;
F_18 (cpu) {
if ( F_16 ( V_12 , V_11 ) != true )
F_16 ( V_12 , V_11 ) = true ;
}
}
F_13 () ;
}
void F_19 ( void )
{
F_20 ( V_13 ) = true ;
F_20 ( V_10 ) = 0 ;
}
static int F_21 ( void )
{
unsigned long V_14 = F_22 ( V_15 ) ;
if ( F_22 ( V_16 ) == V_14 )
return 1 ;
F_12 ( V_16 , V_14 ) ;
return 0 ;
}
static int F_23 ( unsigned long V_17 )
{
unsigned long V_18 = F_7 ( F_11 () ) ;
if ( F_24 ( V_18 , V_17 + F_6 () ) )
return V_18 - V_17 ;
return 0 ;
}
static void F_25 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
V_20 -> V_25 . V_26 = 0 ;
if ( F_22 ( V_12 ) == true ) {
F_12 ( V_12 , false ) ;
return;
}
if ( F_21 () ) {
int V_6 = F_11 () ;
if ( F_22 ( V_27 ) == true )
return;
if ( V_2 )
F_26 ( L_4 , V_6 ) ;
else
F_27 ( 1 , L_4 , V_6 ) ;
F_12 ( V_27 , true ) ;
return;
}
F_12 ( V_27 , false ) ;
return;
}
static void F_28 ( void )
{
F_29 ( V_15 ) ;
}
static enum V_28 F_30 ( struct V_29 * V_29 )
{
unsigned long V_17 = F_22 ( V_10 ) ;
struct V_23 * V_24 = F_31 () ;
int V_30 ;
F_28 () ;
F_32 ( F_22 ( V_31 ) ) ;
F_33 ( V_29 , F_34 ( V_7 ) ) ;
if ( V_17 == 0 ) {
if ( F_35 ( F_22 ( V_13 ) ) ) {
F_12 ( V_13 , false ) ;
F_36 () ;
}
F_37 () ;
F_10 () ;
return V_32 ;
}
V_30 = F_23 ( V_17 ) ;
if ( F_35 ( V_30 ) ) {
if ( F_37 () )
return V_32 ;
if ( F_22 ( V_33 ) == true )
return V_32 ;
F_38 ( V_34 L_5 ,
F_11 () , V_30 ,
V_35 -> V_36 , F_39 ( V_35 ) ) ;
F_40 () ;
F_41 ( V_35 ) ;
if ( V_24 )
F_42 ( V_24 ) ;
else
F_43 () ;
if ( V_4 )
F_26 ( L_6 ) ;
F_12 ( V_33 , true ) ;
} else
F_12 ( V_33 , false ) ;
return V_32 ;
}
static void F_44 ( unsigned int V_37 , unsigned int V_38 )
{
struct V_39 V_40 = { . V_41 = V_38 } ;
F_45 ( V_35 , V_37 , & V_40 ) ;
}
static void F_46 ( unsigned int V_11 )
{
struct V_29 * V_29 = & F_20 ( V_42 ) ;
F_47 ( V_29 , V_43 , V_44 ) ;
V_29 -> V_45 = F_30 ;
if ( ! V_3 ) {
F_48 ( V_35 ) ;
return;
}
F_49 ( V_11 ) ;
F_50 ( V_29 , F_34 ( V_7 ) ,
V_46 ) ;
F_44 ( V_47 , V_48 - 1 ) ;
F_10 () ;
}
static void F_51 ( unsigned int V_11 )
{
struct V_29 * V_29 = & F_20 ( V_42 ) ;
F_44 ( V_49 , 0 ) ;
F_52 ( V_29 ) ;
F_53 ( V_11 ) ;
}
static int F_54 ( unsigned int V_11 )
{
return F_22 ( V_15 ) !=
F_22 ( V_50 ) ;
}
static void F_55 ( unsigned int V_11 )
{
F_12 ( V_50 ,
F_22 ( V_15 ) ) ;
F_10 () ;
}
static int F_49 ( unsigned int V_11 )
{
struct V_51 * V_52 ;
struct V_19 * V_20 = F_16 ( V_53 , V_11 ) ;
if ( V_20 && V_20 -> V_54 > V_55 )
goto V_56;
if ( V_20 != NULL )
goto V_57;
V_52 = & V_58 ;
V_52 -> V_7 = F_56 ( V_5 ) ;
V_20 = F_57 ( V_52 , V_11 , NULL , F_25 , NULL ) ;
if ( V_11 == 0 && F_58 ( V_20 ) )
V_59 = F_59 ( V_20 ) ;
if ( ! F_58 ( V_20 ) ) {
if ( V_11 == 0 || V_59 )
F_60 ( L_7 ) ;
goto V_60;
}
if ( V_11 > 0 && ( F_59 ( V_20 ) == V_59 ) )
return F_59 ( V_20 ) ;
if ( F_59 ( V_20 ) == - V_61 )
F_60 ( L_8 , V_11 ) ;
else if ( F_59 ( V_20 ) == - V_62 )
F_61 ( L_9 ,
V_11 ) ;
else
F_62 ( L_10 ,
V_11 , F_59 ( V_20 ) ) ;
return F_59 ( V_20 ) ;
V_60:
F_16 ( V_53 , V_11 ) = V_20 ;
V_57:
F_63 ( F_16 ( V_53 , V_11 ) ) ;
V_56:
return 0 ;
}
static void F_53 ( unsigned int V_11 )
{
struct V_19 * V_20 = F_16 ( V_53 , V_11 ) ;
if ( V_20 ) {
F_64 ( V_20 ) ;
F_16 ( V_53 , V_11 ) = NULL ;
F_65 ( V_20 ) ;
}
return;
}
static int F_49 ( unsigned int V_11 ) { return 0 ; }
static void F_53 ( unsigned int V_11 ) { return; }
static void F_66 ( void )
{
unsigned int V_11 ;
if ( V_63 ) {
V_63 = 0 ;
F_15 (cpu)
F_67 ( F_16 ( V_31 , V_11 ) ) ;
}
}
static void F_68 ( void )
{
unsigned int V_11 ;
if ( ! V_63 ) {
V_63 = 1 ;
F_15 (cpu)
F_48 ( F_16 ( V_31 , V_11 ) ) ;
}
}
int F_69 ( struct V_64 * V_65 , int V_66 ,
void T_2 * V_67 , T_3 * V_68 , T_4 * V_69 )
{
int V_70 ;
if ( V_63 < 0 )
return - V_71 ;
V_70 = F_70 ( V_65 , V_66 , V_67 , V_68 , V_69 ) ;
if ( V_70 || ! V_66 )
return V_70 ;
F_9 () ;
if ( V_3 && V_5 )
F_66 () ;
else
F_68 () ;
return V_70 ;
}
void T_1 F_71 ( void )
{
F_9 () ;
if ( F_72 ( & V_72 ) ) {
F_62 ( L_11 ) ;
V_63 = - V_71 ;
}
}
