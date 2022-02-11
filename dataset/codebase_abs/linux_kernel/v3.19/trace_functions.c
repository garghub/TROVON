static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_7 = V_8 ;
V_4 -> V_9 = V_10 ;
V_2 -> V_4 = V_4 ;
V_4 -> V_11 = V_2 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_14 ;
if ( V_2 -> V_9 & V_15 )
return 0 ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_4 ( V_2 -> V_4 , V_13 ) ;
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
if ( V_2 -> V_9 & V_15 &&
V_16 . V_17 & V_18 )
V_7 = V_19 ;
else
V_7 = V_8 ;
F_9 ( V_2 , V_7 ) ;
V_2 -> V_20 . V_21 = F_10 () ;
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
F_19 ( & V_2 -> V_20 ) ;
}
static void
V_8 ( unsigned long V_22 , unsigned long V_23 ,
struct V_3 * V_24 , struct V_25 * V_25 )
{
struct V_1 * V_2 = V_24 -> V_11 ;
struct V_26 * V_27 ;
unsigned long V_9 ;
int V_28 ;
int V_21 ;
int V_29 ;
if ( F_20 ( ! V_2 -> V_30 ) )
return;
V_29 = F_21 () ;
F_22 () ;
V_28 = F_23 ( V_31 , V_32 ) ;
if ( V_28 < 0 )
goto V_33;
V_21 = F_24 () ;
V_27 = F_25 ( V_2 -> V_20 . V_27 , V_21 ) ;
if ( ! F_26 ( & V_27 -> V_34 ) ) {
F_27 ( V_9 ) ;
F_28 ( V_2 , V_22 , V_23 , V_9 , V_29 ) ;
}
F_29 ( V_28 ) ;
V_33:
F_30 () ;
}
static void
V_19 ( unsigned long V_22 , unsigned long V_23 ,
struct V_3 * V_24 , struct V_25 * V_25 )
{
struct V_1 * V_2 = V_24 -> V_11 ;
struct V_26 * V_27 ;
unsigned long V_9 ;
long V_34 ;
int V_21 ;
int V_29 ;
if ( F_20 ( ! V_2 -> V_30 ) )
return;
F_31 ( V_9 ) ;
V_21 = F_32 () ;
V_27 = F_25 ( V_2 -> V_20 . V_27 , V_21 ) ;
V_34 = F_33 ( & V_27 -> V_34 ) ;
if ( F_34 ( V_34 == 1 ) ) {
V_29 = F_21 () ;
F_28 ( V_2 , V_22 , V_23 , V_9 , V_29 ) ;
F_35 ( V_2 , V_9 , 5 , V_29 ) ;
}
F_36 ( & V_27 -> V_34 ) ;
F_37 ( V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_30 = 0 ;
F_38 ( V_2 -> V_4 ) ;
V_2 -> V_30 = 1 ;
}
static void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_30 = 0 ;
F_39 ( V_2 -> V_4 ) ;
}
static int
F_40 ( struct V_1 * V_2 , T_2 V_35 , T_2 V_28 , int V_36 )
{
switch ( V_28 ) {
case V_18 :
if ( ! ! V_36 == ! ! ( V_16 . V_17 & V_18 ) )
break;
F_39 ( V_2 -> V_4 ) ;
if ( V_36 ) {
V_2 -> V_4 -> V_7 = V_19 ;
F_38 ( V_2 -> V_4 ) ;
} else {
V_2 -> V_4 -> V_7 = V_8 ;
F_38 ( V_2 -> V_4 ) ;
}
break;
default:
return - V_37 ;
}
return 0 ;
}
static void F_41 ( void * * V_27 , bool V_38 )
{
long * V_39 = ( long * ) V_27 ;
long V_40 = * V_39 ;
if ( ! V_40 )
return;
F_42 () ;
if ( V_38 == ! ! F_43 () )
return;
if ( V_38 )
F_44 () ;
else
F_45 () ;
if ( V_40 == - 1 )
return;
F_46 () ;
* V_39 = V_40 - 1 ;
}
static void
F_47 ( unsigned long V_22 , unsigned long V_23 , void * * V_27 )
{
F_41 ( V_27 , 1 ) ;
}
static void
F_48 ( unsigned long V_22 , unsigned long V_23 , void * * V_27 )
{
F_41 ( V_27 , 0 ) ;
}
static void
F_49 ( unsigned long V_22 , unsigned long V_23 , void * * V_27 )
{
if ( F_43 () )
return;
F_44 () ;
}
static void
F_50 ( unsigned long V_22 , unsigned long V_23 , void * * V_27 )
{
if ( ! F_43 () )
return;
F_45 () ;
}
static void
F_51 ( unsigned long V_22 , unsigned long V_23 , void * * V_27 )
{
F_52 ( V_41 ) ;
}
static void
F_53 ( unsigned long V_22 , unsigned long V_23 , void * * V_27 )
{
long * V_39 = ( long * ) V_27 ;
long V_40 ;
long V_42 ;
do {
if ( ! F_43 () )
return;
V_40 = * V_39 ;
if ( ! V_40 )
return;
if ( V_40 == - 1 ) {
F_52 ( V_41 ) ;
return;
}
V_42 = V_40 - 1 ;
V_42 = F_54 ( V_39 , V_40 , V_42 ) ;
if ( V_42 == V_40 )
F_52 ( V_41 ) ;
} while ( V_42 != V_40 );
}
static int F_55 ( void * * V_27 )
{
unsigned long * V_39 = ( long * ) V_27 ;
if ( ! * V_39 )
return 0 ;
if ( * V_39 != - 1 )
( * V_39 ) -- ;
return 1 ;
}
static void
F_56 ( unsigned long V_22 , unsigned long V_23 , void * * V_27 )
{
if ( F_55 ( V_27 ) )
F_57 ( V_43 ) ;
}
static void
F_58 ( unsigned long V_22 , unsigned long V_23 , void * * V_27 )
{
if ( F_55 ( V_27 ) )
F_57 ( V_44 ) ;
}
static int
F_59 ( const char * V_45 , struct V_46 * V_47 ,
unsigned long V_22 , void * V_27 )
{
long V_39 = ( long ) V_27 ;
F_60 ( V_47 , L_1 , ( void * ) V_22 , V_45 ) ;
if ( V_39 == - 1 )
F_61 ( V_47 , L_2 ) ;
else
F_60 ( V_47 , L_3 , V_39 ) ;
return 0 ;
}
static int
F_62 ( struct V_46 * V_47 , unsigned long V_22 ,
struct V_48 * V_4 , void * V_27 )
{
return F_59 ( L_4 , V_47 , V_22 , V_27 ) ;
}
static int
F_63 ( struct V_46 * V_47 , unsigned long V_22 ,
struct V_48 * V_4 , void * V_27 )
{
return F_59 ( L_5 , V_47 , V_22 , V_27 ) ;
}
static int
F_64 ( struct V_46 * V_47 , unsigned long V_22 ,
struct V_48 * V_4 , void * V_27 )
{
return F_59 ( L_6 , V_47 , V_22 , V_27 ) ;
}
static int
F_65 ( struct V_46 * V_47 , unsigned long V_22 ,
struct V_48 * V_4 , void * V_27 )
{
return F_59 ( L_7 , V_47 , V_22 , V_27 ) ;
}
static int
F_66 ( struct V_46 * V_47 , unsigned long V_22 ,
struct V_48 * V_4 , void * V_27 )
{
return F_59 ( L_8 , V_47 , V_22 , V_27 ) ;
}
static int
F_67 ( struct V_48 * V_4 ,
struct V_49 * V_50 , char * V_51 ,
char * V_52 , char * V_53 , int V_54 )
{
void * V_39 = ( void * ) - 1 ;
char * V_55 ;
int V_14 ;
if ( ! V_54 )
return - V_37 ;
if ( V_51 [ 0 ] == '!' ) {
F_68 ( V_51 + 1 , V_4 ) ;
return 0 ;
}
if ( ! V_53 )
goto V_56;
V_55 = F_69 ( & V_53 , L_9 ) ;
if ( ! strlen ( V_55 ) )
goto V_56;
V_14 = F_70 ( V_55 , 0 , ( unsigned long * ) & V_39 ) ;
if ( V_14 )
return V_14 ;
V_56:
V_14 = F_71 ( V_51 , V_4 , V_39 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int
F_72 ( struct V_49 * V_50 ,
char * V_51 , char * V_52 , char * V_53 , int V_54 )
{
struct V_48 * V_4 ;
if ( strcmp ( V_52 , L_4 ) == 0 )
V_4 = V_53 ? & V_57 : & V_58 ;
else
V_4 = V_53 ? & V_59 : & V_60 ;
return F_67 ( V_4 , V_50 , V_51 , V_52 ,
V_53 , V_54 ) ;
}
static int
F_73 ( struct V_49 * V_50 ,
char * V_51 , char * V_52 , char * V_53 , int V_54 )
{
struct V_48 * V_4 ;
V_4 = V_53 ? & V_61 : & V_62 ;
return F_67 ( V_4 , V_50 , V_51 , V_52 ,
V_53 , V_54 ) ;
}
static int
F_74 ( struct V_49 * V_50 ,
char * V_51 , char * V_52 , char * V_53 , int V_54 )
{
struct V_48 * V_4 ;
V_4 = & V_63 ;
return F_67 ( V_4 , V_50 , V_51 , V_52 ,
L_10 , V_54 ) ;
}
static int
F_75 ( struct V_49 * V_50 ,
char * V_51 , char * V_52 , char * V_53 , int V_54 )
{
struct V_48 * V_4 ;
V_4 = & V_64 ;
return F_67 ( V_4 , V_50 , V_51 , V_52 ,
L_10 , V_54 ) ;
}
static int T_3 F_76 ( void )
{
int V_14 ;
V_14 = F_77 ( & V_65 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_77 ( & V_66 ) ;
if ( V_14 )
goto V_67;
V_14 = F_77 ( & V_68 ) ;
if ( V_14 )
goto V_69;
V_14 = F_77 ( & V_70 ) ;
if ( V_14 )
goto V_71;
V_14 = F_77 ( & V_72 ) ;
if ( V_14 )
goto V_73;
return 0 ;
V_73:
F_78 ( & V_70 ) ;
V_71:
F_78 ( & V_68 ) ;
V_69:
F_78 ( & V_66 ) ;
V_67:
F_78 ( & V_65 ) ;
return V_14 ;
}
static inline int F_76 ( void )
{
return 0 ;
}
static T_3 int F_79 ( void )
{
F_76 () ;
return F_80 ( & V_74 ) ;
}
