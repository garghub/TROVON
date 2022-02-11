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
static unsigned long F_9 ( void )
{
return F_6 () * ( V_7 / 5 ) ;
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
static void F_25 ( struct V_17 * V_18 , int V_19 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
V_18 -> V_24 . V_25 = 0 ;
if ( F_22 ( V_10 ) == true ) {
F_12 ( V_10 , false ) ;
return;
}
if ( F_21 () ) {
int V_6 = F_11 () ;
if ( F_22 ( V_26 ) == true )
return;
if ( V_2 )
F_26 ( L_4 , V_6 ) ;
else
F_27 ( 1 , L_4 , V_6 ) ;
F_12 ( V_26 , true ) ;
return;
}
F_12 ( V_26 , false ) ;
return;
}
static void F_28 ( void )
{
F_29 ( V_13 ) ;
}
static inline void F_28 ( void ) { return; }
static enum V_27 F_30 ( struct V_28 * V_28 )
{
unsigned long V_15 = F_22 ( V_8 ) ;
struct V_22 * V_23 = F_31 () ;
int V_29 ;
F_28 () ;
F_32 ( F_22 ( V_30 ) ) ;
F_33 ( V_28 , F_34 ( F_9 () ) ) ;
if ( V_15 == 0 ) {
if ( F_35 ( F_22 ( V_11 ) ) ) {
F_12 ( V_11 , false ) ;
F_36 () ;
}
F_10 () ;
return V_31 ;
}
V_29 = F_23 ( V_15 ) ;
if ( F_35 ( V_29 ) ) {
if ( F_22 ( V_32 ) == true )
return V_31 ;
F_37 ( V_33 L_5 ,
F_11 () , V_29 ,
V_34 -> V_35 , F_38 ( V_34 ) ) ;
F_39 () ;
F_40 ( V_34 ) ;
if ( V_23 )
F_41 ( V_23 ) ;
else
F_42 () ;
if ( V_4 )
F_26 ( L_6 ) ;
F_12 ( V_32 , true ) ;
} else
F_12 ( V_32 , false ) ;
return V_31 ;
}
static int F_43 ( void * V_36 )
{
static struct V_37 V_38 = { . V_39 = V_40 - 1 } ;
struct V_28 * V_28 = & F_20 ( V_41 ) ;
F_44 ( V_34 , V_42 , & V_38 ) ;
F_10 () ;
F_45 ( V_28 , F_34 ( F_9 () ) ,
V_43 ) ;
F_46 ( V_44 ) ;
while ( ! F_47 () ) {
F_10 () ;
F_48 () ;
if ( F_47 () )
break;
F_46 ( V_44 ) ;
}
F_49 ( V_45 ) ;
return 0 ;
}
static int F_50 ( int V_9 )
{
struct V_46 * V_47 ;
struct V_17 * V_18 = F_16 ( V_48 , V_9 ) ;
if ( V_18 && V_18 -> V_49 > V_50 )
goto V_51;
if ( V_18 != NULL )
goto V_52;
V_47 = & V_53 ;
V_47 -> V_54 = F_51 ( V_5 ) ;
V_18 = F_52 ( V_47 , V_9 , NULL , F_25 ) ;
if ( ! F_53 ( V_18 ) ) {
F_37 ( V_55 L_7 ) ;
goto V_56;
}
if ( F_54 ( V_18 ) == - V_57 )
F_37 ( V_55 L_8 , V_9 ) ;
else if ( F_54 ( V_18 ) == - V_58 )
F_37 ( V_59 L_9 , V_9 ) ;
else
F_37 ( V_33 L_10 , V_9 , F_54 ( V_18 ) ) ;
return F_54 ( V_18 ) ;
V_56:
F_16 ( V_48 , V_9 ) = V_18 ;
V_52:
F_55 ( F_16 ( V_48 , V_9 ) ) ;
V_51:
return 0 ;
}
static void F_56 ( int V_9 )
{
struct V_17 * V_18 = F_16 ( V_48 , V_9 ) ;
if ( V_18 ) {
F_57 ( V_18 ) ;
F_16 ( V_48 , V_9 ) = NULL ;
F_58 ( V_18 ) ;
}
return;
}
static int F_50 ( int V_9 ) { return 0 ; }
static void F_56 ( int V_9 ) { return; }
static void F_59 ( int V_9 )
{
struct V_28 * V_28 = & F_16 ( V_41 , V_9 ) ;
F_60 ( F_16 ( V_30 , V_9 ) ) ;
F_61 ( V_28 , V_60 , V_61 ) ;
V_28 -> V_62 = F_30 ;
}
static int F_62 ( int V_9 )
{
struct V_63 * V_64 = F_16 ( V_30 , V_9 ) ;
int V_65 = 0 ;
V_65 = F_50 ( V_9 ) ;
if ( ! V_64 ) {
V_64 = F_63 ( F_43 , ( void * ) ( unsigned long ) V_9 , L_11 , V_9 ) ;
if ( F_53 ( V_64 ) ) {
F_37 ( V_33 L_12 , V_9 ) ;
if ( ! V_65 ) {
V_65 = F_54 ( V_64 ) ;
F_56 ( V_9 ) ;
}
goto V_51;
}
F_64 ( V_64 , V_9 ) ;
F_16 ( V_8 , V_9 ) = 0 ;
F_16 ( V_30 , V_9 ) = V_64 ;
F_32 ( V_64 ) ;
}
V_51:
return V_65 ;
}
static void F_65 ( int V_9 )
{
struct V_63 * V_64 = F_16 ( V_30 , V_9 ) ;
struct V_28 * V_28 = & F_16 ( V_41 , V_9 ) ;
F_66 ( V_28 ) ;
F_56 ( V_9 ) ;
if ( V_64 ) {
F_16 ( V_30 , V_9 ) = NULL ;
F_67 ( V_64 ) ;
}
}
static void F_68 ( void )
{
int V_9 ;
V_3 = 0 ;
F_15 (cpu)
if ( ! F_62 ( V_9 ) )
V_3 = 1 ;
if ( ! V_3 )
F_37 ( V_33 L_13 ) ;
}
static void F_69 ( void )
{
int V_9 ;
F_15 (cpu)
F_65 ( V_9 ) ;
V_3 = 0 ;
}
int F_70 ( struct V_66 * V_67 , int V_68 ,
void T_2 * V_69 , T_3 * V_70 , T_4 * V_71 )
{
int V_72 ;
V_72 = F_71 ( V_67 , V_68 , V_69 , V_70 , V_71 ) ;
if ( V_72 || ! V_68 )
goto V_51;
if ( V_3 && V_5 )
F_68 () ;
else
F_69 () ;
V_51:
return V_72 ;
}
static int T_5
F_72 ( struct V_73 * V_74 , unsigned long V_75 , void * V_76 )
{
int V_77 = ( unsigned long ) V_76 ;
switch ( V_75 ) {
case V_78 :
case V_79 :
F_59 ( V_77 ) ;
break;
case V_80 :
case V_81 :
if ( V_3 )
F_62 ( V_77 ) ;
break;
#ifdef F_73
case V_82 :
case V_83 :
F_65 ( V_77 ) ;
break;
case V_84 :
case V_85 :
F_65 ( V_77 ) ;
break;
#endif
}
return V_86 ;
}
void T_1 F_74 ( void )
{
void * V_9 = ( void * ) ( long ) F_11 () ;
int V_65 ;
V_65 = F_72 ( & V_87 , V_78 , V_9 ) ;
F_60 ( F_75 ( V_65 ) ) ;
F_72 ( & V_87 , V_80 , V_9 ) ;
F_76 ( & V_87 ) ;
return;
}
