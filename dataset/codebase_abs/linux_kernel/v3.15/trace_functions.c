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
struct V_3 * V_4 ;
if ( V_2 -> V_9 & V_15 ) {
if ( ! V_16 . V_11 ) {
V_16 . V_11 = V_2 ;
V_17 . V_11 = V_2 ;
}
if ( V_18 . V_19 & V_20 )
V_4 = & V_17 ;
else
V_4 = & V_16 ;
V_2 -> V_4 = V_4 ;
} else if ( ! V_2 -> V_4 ) {
return - V_6 ;
}
V_2 -> V_21 . V_22 = F_9 () ;
F_10 () ;
F_11 () ;
F_12 ( V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_15 () ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_21 ) ;
}
static void
V_8 ( unsigned long V_23 , unsigned long V_24 ,
struct V_3 * V_25 , struct V_26 * V_26 )
{
struct V_1 * V_2 = V_25 -> V_11 ;
struct V_27 * V_28 ;
unsigned long V_9 ;
int V_29 ;
int V_22 ;
int V_30 ;
if ( F_18 ( ! V_2 -> V_31 ) )
return;
V_30 = F_19 () ;
F_20 () ;
V_29 = F_21 ( V_32 , V_33 ) ;
if ( V_29 < 0 )
goto V_34;
V_22 = F_22 () ;
V_28 = F_23 ( V_2 -> V_21 . V_28 , V_22 ) ;
if ( ! F_24 ( & V_28 -> V_35 ) ) {
F_25 ( V_9 ) ;
F_26 ( V_2 , V_23 , V_24 , V_9 , V_30 ) ;
}
F_27 ( V_29 ) ;
V_34:
F_28 () ;
}
static void
F_29 ( unsigned long V_23 , unsigned long V_24 ,
struct V_3 * V_25 , struct V_26 * V_26 )
{
struct V_1 * V_2 = V_25 -> V_11 ;
struct V_27 * V_28 ;
unsigned long V_9 ;
long V_35 ;
int V_22 ;
int V_30 ;
if ( F_18 ( ! V_2 -> V_31 ) )
return;
F_30 ( V_9 ) ;
V_22 = F_31 () ;
V_28 = F_23 ( V_2 -> V_21 . V_28 , V_22 ) ;
V_35 = F_32 ( & V_28 -> V_35 ) ;
if ( F_33 ( V_35 == 1 ) ) {
V_30 = F_19 () ;
F_26 ( V_2 , V_23 , V_24 , V_9 , V_30 ) ;
F_34 ( V_2 , V_9 , 5 , V_30 ) ;
}
F_35 ( & V_28 -> V_35 ) ;
F_36 ( V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_31 = 0 ;
F_37 ( V_2 -> V_4 ) ;
V_2 -> V_31 = 1 ;
}
static void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_31 = 0 ;
F_38 ( V_2 -> V_4 ) ;
}
static int
F_39 ( struct V_1 * V_2 , T_1 V_36 , T_1 V_29 , int V_37 )
{
switch ( V_29 ) {
case V_20 :
if ( ! ! V_37 == ! ! ( V_18 . V_19 & V_20 ) )
break;
F_38 ( V_2 -> V_4 ) ;
if ( V_37 ) {
V_2 -> V_4 = & V_17 ;
F_37 ( V_2 -> V_4 ) ;
} else {
V_2 -> V_4 = & V_16 ;
F_37 ( V_2 -> V_4 ) ;
}
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_40 ( void * * V_28 )
{
unsigned long * V_39 = ( long * ) V_28 ;
if ( ! * V_39 )
return 0 ;
if ( * V_39 != - 1 )
( * V_39 ) -- ;
return 1 ;
}
static void
F_41 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( F_42 () )
return;
if ( F_40 ( V_28 ) )
F_43 () ;
}
static void
F_44 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( ! F_42 () )
return;
if ( F_40 ( V_28 ) )
F_45 () ;
}
static void
F_46 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( F_42 () )
return;
F_43 () ;
}
static void
F_47 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( ! F_42 () )
return;
F_45 () ;
}
static void
F_48 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
F_49 ( V_40 ) ;
}
static void
F_50 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( ! F_42 () )
return;
if ( F_40 ( V_28 ) )
F_49 ( V_40 ) ;
}
static void
F_51 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( F_40 ( V_28 ) )
F_52 ( V_41 ) ;
}
static void
F_53 ( unsigned long V_23 , unsigned long V_24 , void * * V_28 )
{
if ( F_40 ( V_28 ) )
F_52 ( V_42 ) ;
}
static int
F_54 ( const char * V_43 , struct V_44 * V_45 ,
unsigned long V_23 , void * V_28 )
{
long V_39 = ( long ) V_28 ;
F_55 ( V_45 , L_1 , ( void * ) V_23 , V_43 ) ;
if ( V_39 == - 1 )
F_55 ( V_45 , L_2 ) ;
else
F_55 ( V_45 , L_3 , V_39 ) ;
return 0 ;
}
static int
F_56 ( struct V_44 * V_45 , unsigned long V_23 ,
struct V_46 * V_4 , void * V_28 )
{
return F_54 ( L_4 , V_45 , V_23 , V_28 ) ;
}
static int
F_57 ( struct V_44 * V_45 , unsigned long V_23 ,
struct V_46 * V_4 , void * V_28 )
{
return F_54 ( L_5 , V_45 , V_23 , V_28 ) ;
}
static int
F_58 ( struct V_44 * V_45 , unsigned long V_23 ,
struct V_46 * V_4 , void * V_28 )
{
return F_54 ( L_6 , V_45 , V_23 , V_28 ) ;
}
static int
F_59 ( struct V_44 * V_45 , unsigned long V_23 ,
struct V_46 * V_4 , void * V_28 )
{
return F_54 ( L_7 , V_45 , V_23 , V_28 ) ;
}
static int
F_60 ( struct V_44 * V_45 , unsigned long V_23 ,
struct V_46 * V_4 , void * V_28 )
{
return F_54 ( L_8 , V_45 , V_23 , V_28 ) ;
}
static int
F_61 ( struct V_46 * V_4 ,
struct V_47 * V_48 , char * V_49 ,
char * V_50 , char * V_51 , int V_52 )
{
void * V_39 = ( void * ) - 1 ;
char * V_53 ;
int V_14 ;
if ( ! V_52 )
return - V_38 ;
if ( V_49 [ 0 ] == '!' ) {
F_62 ( V_49 + 1 , V_4 ) ;
return 0 ;
}
if ( ! V_51 )
goto V_54;
V_53 = F_63 ( & V_51 , L_9 ) ;
if ( ! strlen ( V_53 ) )
goto V_54;
V_14 = F_64 ( V_53 , 0 , ( unsigned long * ) & V_39 ) ;
if ( V_14 )
return V_14 ;
V_54:
V_14 = F_65 ( V_49 , V_4 , V_39 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int
F_66 ( struct V_47 * V_48 ,
char * V_49 , char * V_50 , char * V_51 , int V_52 )
{
struct V_46 * V_4 ;
if ( strcmp ( V_50 , L_4 ) == 0 )
V_4 = V_51 ? & V_55 : & V_56 ;
else
V_4 = V_51 ? & V_57 : & V_58 ;
return F_61 ( V_4 , V_48 , V_49 , V_50 ,
V_51 , V_52 ) ;
}
static int
F_67 ( struct V_47 * V_48 ,
char * V_49 , char * V_50 , char * V_51 , int V_52 )
{
struct V_46 * V_4 ;
V_4 = V_51 ? & V_59 : & V_60 ;
return F_61 ( V_4 , V_48 , V_49 , V_50 ,
V_51 , V_52 ) ;
}
static int
F_68 ( struct V_47 * V_48 ,
char * V_49 , char * V_50 , char * V_51 , int V_52 )
{
struct V_46 * V_4 ;
V_4 = & V_61 ;
return F_61 ( V_4 , V_48 , V_49 , V_50 ,
L_10 , V_52 ) ;
}
static int
F_69 ( struct V_47 * V_48 ,
char * V_49 , char * V_50 , char * V_51 , int V_52 )
{
struct V_46 * V_4 ;
V_4 = & V_62 ;
return F_61 ( V_4 , V_48 , V_49 , V_50 ,
L_10 , V_52 ) ;
}
static int T_2 F_70 ( void )
{
int V_14 ;
V_14 = F_71 ( & V_63 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_71 ( & V_64 ) ;
if ( V_14 )
goto V_65;
V_14 = F_71 ( & V_66 ) ;
if ( V_14 )
goto V_67;
V_14 = F_71 ( & V_68 ) ;
if ( V_14 )
goto V_69;
V_14 = F_71 ( & V_70 ) ;
if ( V_14 )
goto V_71;
return 0 ;
V_71:
F_72 ( & V_68 ) ;
V_69:
F_72 ( & V_66 ) ;
V_67:
F_72 ( & V_64 ) ;
V_65:
F_72 ( & V_63 ) ;
return V_14 ;
}
static inline int F_70 ( void )
{
return 0 ;
}
static T_2 int F_73 ( void )
{
F_70 () ;
return F_74 ( & V_72 ) ;
}
