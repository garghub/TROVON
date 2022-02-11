static int F_1 ( struct V_1 * V_2 )
{
V_3 = V_2 ;
V_2 -> V_4 . V_5 = F_2 () ;
F_3 () ;
F_4 () ;
F_5 () ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 () ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_4 ) ;
}
static void
F_11 ( unsigned long V_6 , unsigned long V_7 ,
struct V_8 * V_9 , struct V_10 * V_10 )
{
struct V_1 * V_2 = V_3 ;
struct V_11 * V_12 ;
unsigned long V_13 ;
int V_14 ;
int V_5 ;
int V_15 ;
if ( F_12 ( ! V_16 ) )
return;
V_15 = F_13 () ;
F_14 () ;
V_14 = F_15 ( V_17 , V_18 ) ;
if ( V_14 < 0 )
goto V_19;
V_5 = F_16 () ;
V_12 = F_17 ( V_2 -> V_4 . V_12 , V_5 ) ;
if ( ! F_18 ( & V_12 -> V_20 ) ) {
F_19 ( V_13 ) ;
F_20 ( V_2 , V_6 , V_7 , V_13 , V_15 ) ;
}
F_21 ( V_14 ) ;
V_19:
F_22 () ;
}
static void
F_23 ( unsigned long V_6 , unsigned long V_7 ,
struct V_8 * V_9 , struct V_10 * V_10 )
{
struct V_1 * V_2 = V_3 ;
struct V_11 * V_12 ;
unsigned long V_13 ;
long V_20 ;
int V_5 ;
int V_15 ;
if ( F_12 ( ! V_16 ) )
return;
F_24 ( V_13 ) ;
V_5 = F_25 () ;
V_12 = F_17 ( V_2 -> V_4 . V_12 , V_5 ) ;
V_20 = F_26 ( & V_12 -> V_20 ) ;
if ( F_27 ( V_20 == 1 ) ) {
V_15 = F_13 () ;
F_20 ( V_2 , V_6 , V_7 , V_13 , V_15 ) ;
F_28 ( V_2 , V_13 , 5 , V_15 ) ;
}
F_29 ( & V_12 -> V_20 ) ;
F_30 ( V_13 ) ;
}
static void F_5 ( void )
{
V_16 = 0 ;
if ( V_21 . V_22 & V_23 )
F_31 ( & V_24 ) ;
else
F_31 ( & V_25 ) ;
V_16 = 1 ;
}
static void F_7 ( void )
{
V_16 = 0 ;
if ( V_21 . V_22 & V_23 )
F_32 ( & V_24 ) ;
else
F_32 ( & V_25 ) ;
}
static int F_33 ( T_1 V_26 , T_1 V_14 , int V_27 )
{
switch ( V_14 ) {
case V_23 :
if ( ! ! V_27 == ! ! ( V_21 . V_22 & V_23 ) )
break;
if ( V_27 ) {
F_32 ( & V_25 ) ;
F_31 ( & V_24 ) ;
} else {
F_32 ( & V_24 ) ;
F_31 ( & V_25 ) ;
}
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_34 ( void * * V_12 )
{
unsigned long * V_29 = ( long * ) V_12 ;
if ( ! * V_29 )
return 0 ;
if ( * V_29 != - 1 )
( * V_29 ) -- ;
return 1 ;
}
static void
F_35 ( unsigned long V_6 , unsigned long V_7 , void * * V_12 )
{
if ( F_36 () )
return;
if ( F_34 ( V_12 ) )
F_37 () ;
}
static void
F_38 ( unsigned long V_6 , unsigned long V_7 , void * * V_12 )
{
if ( ! F_36 () )
return;
if ( F_34 ( V_12 ) )
F_39 () ;
}
static void
F_40 ( unsigned long V_6 , unsigned long V_7 , void * * V_12 )
{
if ( F_36 () )
return;
F_37 () ;
}
static void
F_41 ( unsigned long V_6 , unsigned long V_7 , void * * V_12 )
{
if ( ! F_36 () )
return;
F_39 () ;
}
static void
F_42 ( unsigned long V_6 , unsigned long V_7 , void * * V_12 )
{
F_43 ( V_30 ) ;
}
static void
F_44 ( unsigned long V_6 , unsigned long V_7 , void * * V_12 )
{
if ( ! F_36 () )
return;
if ( F_34 ( V_12 ) )
F_43 ( V_30 ) ;
}
static void
F_45 ( unsigned long V_6 , unsigned long V_7 , void * * V_12 )
{
if ( F_34 ( V_12 ) )
F_46 ( V_31 ) ;
}
static void
F_47 ( unsigned long V_6 , unsigned long V_7 , void * * V_12 )
{
if ( F_34 ( V_12 ) )
F_46 ( V_32 ) ;
}
static int
F_48 ( const char * V_33 , struct V_34 * V_35 ,
unsigned long V_6 , void * V_12 )
{
long V_29 = ( long ) V_12 ;
F_49 ( V_35 , L_1 , ( void * ) V_6 , V_33 ) ;
if ( V_29 == - 1 )
F_49 ( V_35 , L_2 ) ;
else
F_49 ( V_35 , L_3 , V_29 ) ;
return 0 ;
}
static int
F_50 ( struct V_34 * V_35 , unsigned long V_6 ,
struct V_36 * V_37 , void * V_12 )
{
return F_48 ( L_4 , V_35 , V_6 , V_12 ) ;
}
static int
F_51 ( struct V_34 * V_35 , unsigned long V_6 ,
struct V_36 * V_37 , void * V_12 )
{
return F_48 ( L_5 , V_35 , V_6 , V_12 ) ;
}
static int
F_52 ( struct V_34 * V_35 , unsigned long V_6 ,
struct V_36 * V_37 , void * V_12 )
{
return F_48 ( L_6 , V_35 , V_6 , V_12 ) ;
}
static int
F_53 ( struct V_34 * V_35 , unsigned long V_6 ,
struct V_36 * V_37 , void * V_12 )
{
return F_48 ( L_7 , V_35 , V_6 , V_12 ) ;
}
static int
F_54 ( struct V_34 * V_35 , unsigned long V_6 ,
struct V_36 * V_37 , void * V_12 )
{
return F_48 ( L_8 , V_35 , V_6 , V_12 ) ;
}
static int
F_55 ( struct V_36 * V_37 ,
struct V_38 * V_39 , char * V_40 ,
char * V_41 , char * V_42 , int V_43 )
{
void * V_29 = ( void * ) - 1 ;
char * V_44 ;
int V_45 ;
if ( ! V_43 )
return - V_28 ;
if ( V_40 [ 0 ] == '!' ) {
F_56 ( V_40 + 1 , V_37 ) ;
return 0 ;
}
if ( ! V_42 )
goto V_46;
V_44 = F_57 ( & V_42 , L_9 ) ;
if ( ! strlen ( V_44 ) )
goto V_46;
V_45 = F_58 ( V_44 , 0 , ( unsigned long * ) & V_29 ) ;
if ( V_45 )
return V_45 ;
V_46:
V_45 = F_59 ( V_40 , V_37 , V_29 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
static int
F_60 ( struct V_38 * V_39 ,
char * V_40 , char * V_41 , char * V_42 , int V_43 )
{
struct V_36 * V_37 ;
if ( strcmp ( V_41 , L_4 ) == 0 )
V_37 = V_42 ? & V_47 : & V_48 ;
else
V_37 = V_42 ? & V_49 : & V_50 ;
return F_55 ( V_37 , V_39 , V_40 , V_41 ,
V_42 , V_43 ) ;
}
static int
F_61 ( struct V_38 * V_39 ,
char * V_40 , char * V_41 , char * V_42 , int V_43 )
{
struct V_36 * V_37 ;
V_37 = V_42 ? & V_51 : & V_52 ;
return F_55 ( V_37 , V_39 , V_40 , V_41 ,
V_42 , V_43 ) ;
}
static int
F_62 ( struct V_38 * V_39 ,
char * V_40 , char * V_41 , char * V_42 , int V_43 )
{
struct V_36 * V_37 ;
V_37 = & V_53 ;
return F_55 ( V_37 , V_39 , V_40 , V_41 ,
L_10 , V_43 ) ;
}
static int
F_63 ( struct V_38 * V_39 ,
char * V_40 , char * V_41 , char * V_42 , int V_43 )
{
struct V_36 * V_37 ;
V_37 = & V_54 ;
return F_55 ( V_37 , V_39 , V_40 , V_41 ,
L_10 , V_43 ) ;
}
static int T_2 F_64 ( void )
{
int V_45 ;
V_45 = F_65 ( & V_55 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_65 ( & V_56 ) ;
if ( V_45 )
goto V_57;
V_45 = F_65 ( & V_58 ) ;
if ( V_45 )
goto V_59;
V_45 = F_65 ( & V_60 ) ;
if ( V_45 )
goto V_61;
V_45 = F_65 ( & V_62 ) ;
if ( V_45 )
goto V_63;
return 0 ;
V_63:
F_66 ( & V_60 ) ;
V_61:
F_66 ( & V_58 ) ;
V_59:
F_66 ( & V_56 ) ;
V_57:
F_66 ( & V_55 ) ;
return V_45 ;
}
static inline int F_64 ( void )
{
return 0 ;
}
static T_2 int F_67 ( void )
{
F_64 () ;
return F_68 ( & V_64 ) ;
}
