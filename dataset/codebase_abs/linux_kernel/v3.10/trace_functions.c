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
static int
F_45 ( const char * V_31 , struct V_32 * V_33 ,
unsigned long V_6 , void * V_12 )
{
long V_29 = ( long ) V_12 ;
F_46 ( V_33 , L_1 , ( void * ) V_6 , V_31 ) ;
if ( V_29 == - 1 )
F_46 ( V_33 , L_2 ) ;
else
F_46 ( V_33 , L_3 , V_29 ) ;
return 0 ;
}
static int
F_47 ( struct V_32 * V_33 , unsigned long V_6 ,
struct V_34 * V_35 , void * V_12 )
{
return F_45 ( L_4 , V_33 , V_6 , V_12 ) ;
}
static int
F_48 ( struct V_32 * V_33 , unsigned long V_6 ,
struct V_34 * V_35 , void * V_12 )
{
return F_45 ( L_5 , V_33 , V_6 , V_12 ) ;
}
static int
F_49 ( struct V_32 * V_33 , unsigned long V_6 ,
struct V_34 * V_35 , void * V_12 )
{
return F_45 ( L_6 , V_33 , V_6 , V_12 ) ;
}
static int
F_50 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_38 ,
char * V_39 , char * V_40 , int V_41 )
{
void * V_29 = ( void * ) - 1 ;
char * V_42 ;
int V_43 ;
if ( ! V_41 )
return - V_28 ;
if ( V_38 [ 0 ] == '!' ) {
F_51 ( V_38 + 1 , V_35 ) ;
return 0 ;
}
if ( ! V_40 )
goto V_44;
V_42 = F_52 ( & V_40 , L_7 ) ;
if ( ! strlen ( V_42 ) )
goto V_44;
V_43 = F_53 ( V_42 , 0 , ( unsigned long * ) & V_29 ) ;
if ( V_43 )
return V_43 ;
V_44:
V_43 = F_54 ( V_38 , V_35 , V_29 ) ;
return V_43 < 0 ? V_43 : 0 ;
}
static int
F_55 ( struct V_36 * V_37 ,
char * V_38 , char * V_39 , char * V_40 , int V_41 )
{
struct V_34 * V_35 ;
if ( strcmp ( V_39 , L_4 ) == 0 )
V_35 = V_40 ? & V_45 : & V_46 ;
else
V_35 = V_40 ? & V_47 : & V_48 ;
return F_50 ( V_35 , V_37 , V_38 , V_39 ,
V_40 , V_41 ) ;
}
static int
F_56 ( struct V_36 * V_37 ,
char * V_38 , char * V_39 , char * V_40 , int V_41 )
{
struct V_34 * V_35 ;
V_35 = V_40 ? & V_49 : & V_50 ;
return F_50 ( V_35 , V_37 , V_38 , V_39 ,
V_40 , V_41 ) ;
}
static int T_2 F_57 ( void )
{
int V_43 ;
V_43 = F_58 ( & V_51 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_58 ( & V_52 ) ;
if ( V_43 )
F_59 ( & V_51 ) ;
V_43 = F_58 ( & V_53 ) ;
if ( V_43 ) {
F_59 ( & V_51 ) ;
F_59 ( & V_52 ) ;
}
return V_43 ;
}
static inline int F_57 ( void )
{
return 0 ;
}
static T_2 int F_60 ( void )
{
F_57 () ;
return F_61 ( & V_54 ) ;
}
