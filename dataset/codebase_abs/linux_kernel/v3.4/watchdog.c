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
static inline void F_28 ( void ) { return; }
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
F_10 () ;
return V_30 ;
}
V_28 = F_23 ( V_15 ) ;
if ( F_35 ( V_28 ) ) {
if ( F_22 ( V_31 ) == true )
return V_30 ;
F_37 ( V_32 L_5 ,
F_11 () , V_28 ,
V_33 -> V_34 , F_38 ( V_33 ) ) ;
F_39 () ;
F_40 ( V_33 ) ;
if ( V_22 )
F_41 ( V_22 ) ;
else
F_42 () ;
if ( V_4 )
F_26 ( L_6 ) ;
F_12 ( V_31 , true ) ;
} else
F_12 ( V_31 , false ) ;
return V_30 ;
}
static int F_43 ( void * V_35 )
{
struct V_36 V_37 = { . V_38 = 0 } ;
struct V_27 * V_27 = & F_20 ( V_39 ) ;
F_10 () ;
F_44 ( V_27 , F_34 ( F_9 () ) ,
V_40 ) ;
F_45 ( V_41 ) ;
while ( ! F_46 () ) {
F_10 () ;
F_47 () ;
if ( F_46 () )
break;
F_45 ( V_41 ) ;
}
F_48 ( V_42 ) ;
F_49 ( V_33 , V_43 , & V_37 ) ;
return 0 ;
}
static int F_50 ( int V_9 )
{
struct V_44 * V_45 ;
struct V_17 * V_18 = F_16 ( V_46 , V_9 ) ;
if ( V_18 && V_18 -> V_47 > V_48 )
goto V_49;
if ( V_18 != NULL )
goto V_50;
V_45 = & V_51 ;
V_45 -> V_52 = F_51 ( V_5 ) ;
V_18 = F_52 ( V_45 , V_9 , NULL , F_25 , NULL ) ;
if ( ! F_53 ( V_18 ) ) {
F_54 ( L_7 ) ;
goto V_53;
}
if ( F_55 ( V_18 ) == - V_54 )
F_54 ( L_8 , V_9 ) ;
else if ( F_55 ( V_18 ) == - V_55 )
F_56 ( L_9 ,
V_9 ) ;
else
F_57 ( L_10 ,
V_9 , F_55 ( V_18 ) ) ;
return F_55 ( V_18 ) ;
V_53:
F_16 ( V_46 , V_9 ) = V_18 ;
V_50:
F_58 ( F_16 ( V_46 , V_9 ) ) ;
V_49:
return 0 ;
}
static void F_59 ( int V_9 )
{
struct V_17 * V_18 = F_16 ( V_46 , V_9 ) ;
if ( V_18 ) {
F_60 ( V_18 ) ;
F_16 ( V_46 , V_9 ) = NULL ;
F_61 ( V_18 ) ;
}
return;
}
static int F_50 ( int V_9 ) { return 0 ; }
static void F_59 ( int V_9 ) { return; }
static void F_62 ( int V_9 )
{
struct V_27 * V_27 = & F_16 ( V_39 , V_9 ) ;
F_63 ( F_16 ( V_29 , V_9 ) ) ;
F_64 ( V_27 , V_56 , V_57 ) ;
V_27 -> V_58 = F_30 ;
}
static int F_65 ( int V_9 )
{
struct V_59 * V_60 = F_16 ( V_29 , V_9 ) ;
int V_61 = 0 ;
V_61 = F_50 ( V_9 ) ;
if ( ! V_60 ) {
struct V_36 V_37 = { . V_38 = V_62 - 1 } ;
V_60 = F_66 ( F_43 , NULL , F_67 ( V_9 ) , L_11 , V_9 ) ;
if ( F_53 ( V_60 ) ) {
F_57 ( L_12 , V_9 ) ;
if ( ! V_61 ) {
V_61 = F_55 ( V_60 ) ;
F_59 ( V_9 ) ;
}
goto V_49;
}
F_49 ( V_60 , V_63 , & V_37 ) ;
F_68 ( V_60 , V_9 ) ;
F_16 ( V_8 , V_9 ) = 0 ;
F_16 ( V_29 , V_9 ) = V_60 ;
F_32 ( V_60 ) ;
}
V_49:
return V_61 ;
}
static void F_69 ( int V_9 )
{
struct V_59 * V_60 = F_16 ( V_29 , V_9 ) ;
struct V_27 * V_27 = & F_16 ( V_39 , V_9 ) ;
F_70 ( V_27 ) ;
F_59 ( V_9 ) ;
if ( V_60 ) {
F_16 ( V_29 , V_9 ) = NULL ;
F_71 ( V_60 ) ;
}
}
static void F_72 ( void )
{
int V_9 ;
V_3 = 0 ;
F_15 (cpu)
if ( ! F_65 ( V_9 ) )
V_3 = 1 ;
if ( ! V_3 )
F_57 ( L_13 ) ;
}
static void F_73 ( void )
{
int V_9 ;
F_15 (cpu)
F_69 ( V_9 ) ;
V_3 = 0 ;
}
int F_74 ( struct V_64 * V_65 , int V_66 ,
void T_2 * V_67 , T_3 * V_68 , T_4 * V_69 )
{
int V_70 ;
V_70 = F_75 ( V_65 , V_66 , V_67 , V_68 , V_69 ) ;
if ( V_70 || ! V_66 )
goto V_49;
if ( V_3 && V_5 )
F_72 () ;
else
F_73 () ;
V_49:
return V_70 ;
}
static int T_5
F_76 ( struct V_71 * V_72 , unsigned long V_73 , void * V_74 )
{
int V_75 = ( unsigned long ) V_74 ;
switch ( V_73 ) {
case V_76 :
case V_77 :
F_62 ( V_75 ) ;
break;
case V_78 :
case V_79 :
if ( V_3 )
F_65 ( V_75 ) ;
break;
#ifdef F_77
case V_80 :
case V_81 :
F_69 ( V_75 ) ;
break;
case V_82 :
case V_83 :
F_69 ( V_75 ) ;
break;
#endif
}
return V_84 ;
}
void T_1 F_78 ( void )
{
void * V_9 = ( void * ) ( long ) F_11 () ;
int V_61 ;
V_61 = F_76 ( & V_85 , V_76 , V_9 ) ;
F_63 ( F_79 ( V_61 ) ) ;
F_76 ( & V_85 , V_78 , V_9 ) ;
F_80 ( & V_85 ) ;
return;
}
