static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_7 = V_8 ;
V_4 -> V_9 = V_10 | V_11 ;
V_2 -> V_4 = V_4 ;
V_4 -> V_12 = V_2 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_15 ;
if ( V_2 -> V_9 & V_16 )
return 0 ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_4 ( V_2 -> V_4 , V_14 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_4 ) ;
F_7 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( ! V_2 -> V_4 )
return - V_6 ;
if ( V_2 -> V_9 & V_16 &&
V_17 . V_18 & V_19 )
V_7 = V_20 ;
else
V_7 = V_8 ;
F_9 ( V_2 , V_7 ) ;
V_2 -> V_21 . V_22 = F_10 () ;
F_11 () ;
F_12 () ;
F_13 ( V_2 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_16 () ;
F_17 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_21 ) ;
}
static void
V_8 ( unsigned long V_23 , unsigned long V_24 ,
struct V_3 * V_25 , struct V_26 * V_26 )
{
struct V_1 * V_2 = V_25 -> V_12 ;
struct V_27 * V_28 ;
unsigned long V_9 ;
int V_29 ;
int V_22 ;
int V_30 ;
if ( F_20 ( ! V_2 -> V_31 ) )
return;
V_30 = F_21 () ;
F_22 () ;
V_29 = F_23 ( V_32 , V_33 ) ;
if ( V_29 < 0 )
goto V_34;
V_22 = F_24 () ;
V_28 = F_25 ( V_2 -> V_21 . V_28 , V_22 ) ;
if ( ! F_26 ( & V_28 -> V_35 ) ) {
F_27 ( V_9 ) ;
F_28 ( V_2 , V_23 , V_24 , V_9 , V_30 ) ;
}
F_29 ( V_29 ) ;
V_34:
F_30 () ;
}
static void
V_20 ( unsigned long V_23 , unsigned long V_24 ,
struct V_3 * V_25 , struct V_26 * V_26 )
{
struct V_1 * V_2 = V_25 -> V_12 ;
struct V_27 * V_28 ;
unsigned long V_9 ;
long V_35 ;
int V_22 ;
int V_30 ;
if ( F_20 ( ! V_2 -> V_31 ) )
return;
F_31 ( V_9 ) ;
V_22 = F_32 () ;
V_28 = F_25 ( V_2 -> V_21 . V_28 , V_22 ) ;
V_35 = F_33 ( & V_28 -> V_35 ) ;
if ( F_34 ( V_35 == 1 ) ) {
V_30 = F_21 () ;
F_28 ( V_2 , V_23 , V_24 , V_9 , V_30 ) ;
F_35 ( V_2 , V_9 , 5 , V_30 ) ;
}
F_36 ( & V_28 -> V_35 ) ;
F_37 ( V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_31 = 0 ;
F_38 ( V_2 -> V_4 ) ;
V_2 -> V_31 = 1 ;
}
static void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_31 = 0 ;
F_39 ( V_2 -> V_4 ) ;
}
static int
F_40 ( struct V_1 * V_2 , T_2 V_36 , T_2 V_29 , int V_37 )
{
switch ( V_29 ) {
case V_19 :
if ( ! ! V_37 == ! ! ( V_17 . V_18 & V_19 ) )
break;
if ( V_2 -> V_38 != & V_39 )
break;
F_39 ( V_2 -> V_4 ) ;
if ( V_37 ) {
V_2 -> V_4 -> V_7 = V_20 ;
F_38 ( V_2 -> V_4 ) ;
} else {
V_2 -> V_4 -> V_7 = V_8 ;
F_38 ( V_2 -> V_4 ) ;
}
break;
default:
return - V_40 ;
}
return 0 ;
}
static void F_41 ( void * * V_28 , bool V_41 )
{
long * V_42 = ( long * ) V_28 ;
long V_43 = * V_42 ;
if ( ! V_43 )
return;
F_42 () ;
if ( V_41 == ! ! F_43 () )
return;
if ( V_41 )
F_44 () ;
else
F_45 () ;
if ( V_43 == - 1 )
return;
F_46 () ;
* V_42 = V_43 - 1 ;
}
static void
F_47 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
F_41 ( V_28 , 1 ) ;
}
static void
F_48 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
F_41 ( V_28 , 0 ) ;
}
static void
F_49 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( F_43 () )
return;
F_44 () ;
}
static void
F_50 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( ! F_43 () )
return;
F_45 () ;
}
static void
F_51 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
F_52 ( V_44 ) ;
}
static void
F_53 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
long * V_42 = ( long * ) V_28 ;
long V_43 ;
long V_45 ;
do {
if ( ! F_43 () )
return;
V_43 = * V_42 ;
if ( ! V_43 )
return;
if ( V_43 == - 1 ) {
F_52 ( V_44 ) ;
return;
}
V_45 = V_43 - 1 ;
V_45 = F_54 ( V_42 , V_43 , V_45 ) ;
if ( V_45 == V_43 )
F_52 ( V_44 ) ;
} while ( V_45 != V_43 );
}
static int F_55 ( void * * V_28 )
{
unsigned long * V_42 = ( long * ) V_28 ;
if ( ! * V_42 )
return 0 ;
if ( * V_42 != - 1 )
( * V_42 ) -- ;
return 1 ;
}
static void
F_56 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( F_55 ( V_28 ) )
F_57 ( V_46 ) ;
}
static void
F_58 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( F_55 ( V_28 ) )
F_57 ( V_47 ) ;
}
static int
F_59 ( const char * V_48 , struct V_49 * V_50 ,
unsigned long V_23 , void * V_28 )
{
long V_42 = ( long ) V_28 ;
F_60 ( V_50 , L_1 , ( void * ) V_23 , V_48 ) ;
if ( V_42 == - 1 )
F_61 ( V_50 , L_2 ) ;
else
F_60 ( V_50 , L_3 , V_42 ) ;
return 0 ;
}
static int
F_62 ( struct V_49 * V_50 , unsigned long V_23 ,
struct V_51 * V_4 , void * V_28 )
{
return F_59 ( L_4 , V_50 , V_23 , V_28 ) ;
}
static int
F_63 ( struct V_49 * V_50 , unsigned long V_23 ,
struct V_51 * V_4 , void * V_28 )
{
return F_59 ( L_5 , V_50 , V_23 , V_28 ) ;
}
static int
F_64 ( struct V_49 * V_50 , unsigned long V_23 ,
struct V_51 * V_4 , void * V_28 )
{
return F_59 ( L_6 , V_50 , V_23 , V_28 ) ;
}
static int
F_65 ( struct V_49 * V_50 , unsigned long V_23 ,
struct V_51 * V_4 , void * V_28 )
{
return F_59 ( L_7 , V_50 , V_23 , V_28 ) ;
}
static int
F_66 ( struct V_49 * V_50 , unsigned long V_23 ,
struct V_51 * V_4 , void * V_28 )
{
return F_59 ( L_8 , V_50 , V_23 , V_28 ) ;
}
static int
F_67 ( struct V_51 * V_4 ,
struct V_52 * V_53 , char * V_54 ,
char * V_55 , char * V_56 , int V_57 )
{
void * V_42 = ( void * ) - 1 ;
char * V_58 ;
int V_15 ;
if ( ! V_57 )
return - V_40 ;
if ( V_54 [ 0 ] == '!' ) {
F_68 ( V_54 + 1 , V_4 ) ;
return 0 ;
}
if ( ! V_56 )
goto V_59;
V_58 = F_69 ( & V_56 , L_9 ) ;
if ( ! strlen ( V_58 ) )
goto V_59;
V_15 = F_70 ( V_58 , 0 , ( unsigned long * ) & V_42 ) ;
if ( V_15 )
return V_15 ;
V_59:
V_15 = F_71 ( V_54 , V_4 , V_42 ) ;
return V_15 < 0 ? V_15 : 0 ;
}
static int
F_72 ( struct V_52 * V_53 ,
char * V_54 , char * V_55 , char * V_56 , int V_57 )
{
struct V_51 * V_4 ;
if ( strcmp ( V_55 , L_4 ) == 0 )
V_4 = V_56 ? & V_60 : & V_61 ;
else
V_4 = V_56 ? & V_62 : & V_63 ;
return F_67 ( V_4 , V_53 , V_54 , V_55 ,
V_56 , V_57 ) ;
}
static int
F_73 ( struct V_52 * V_53 ,
char * V_54 , char * V_55 , char * V_56 , int V_57 )
{
struct V_51 * V_4 ;
V_4 = V_56 ? & V_64 : & V_65 ;
return F_67 ( V_4 , V_53 , V_54 , V_55 ,
V_56 , V_57 ) ;
}
static int
F_74 ( struct V_52 * V_53 ,
char * V_54 , char * V_55 , char * V_56 , int V_57 )
{
struct V_51 * V_4 ;
V_4 = & V_66 ;
return F_67 ( V_4 , V_53 , V_54 , V_55 ,
L_10 , V_57 ) ;
}
static int
F_75 ( struct V_52 * V_53 ,
char * V_54 , char * V_55 , char * V_56 , int V_57 )
{
struct V_51 * V_4 ;
V_4 = & V_67 ;
return F_67 ( V_4 , V_53 , V_54 , V_55 ,
L_10 , V_57 ) ;
}
static int T_3 F_76 ( void )
{
int V_15 ;
V_15 = F_77 ( & V_68 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_77 ( & V_69 ) ;
if ( V_15 )
goto V_70;
V_15 = F_77 ( & V_71 ) ;
if ( V_15 )
goto V_72;
V_15 = F_77 ( & V_73 ) ;
if ( V_15 )
goto V_74;
V_15 = F_77 ( & V_75 ) ;
if ( V_15 )
goto V_76;
return 0 ;
V_76:
F_78 ( & V_73 ) ;
V_74:
F_78 ( & V_71 ) ;
V_72:
F_78 ( & V_69 ) ;
V_70:
F_78 ( & V_68 ) ;
return V_15 ;
}
static inline int F_76 ( void )
{
return 0 ;
}
static T_3 int F_79 ( void )
{
F_76 () ;
return F_80 ( & V_39 ) ;
}
