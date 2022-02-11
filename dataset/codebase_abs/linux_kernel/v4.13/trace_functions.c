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
static void F_41 ( struct V_41 * V_4 ,
unsigned long V_23 ,
struct V_1 * V_2 , bool V_42 ,
void * V_28 )
{
struct V_43 * V_44 = V_28 ;
long * V_45 ;
long V_46 ;
V_45 = ( long * ) F_42 ( V_44 , V_23 ) ;
V_46 = * V_45 ;
if ( V_46 <= 0 )
return;
F_43 () ;
if ( V_42 == ! ! F_44 ( V_2 ) )
return;
if ( V_42 )
F_45 ( V_2 ) ;
else
F_46 ( V_2 ) ;
F_47 () ;
* V_45 = V_46 - 1 ;
}
static void
F_48 ( unsigned long V_23 , unsigned long V_24 ,
struct V_1 * V_2 , struct V_41 * V_4 ,
void * V_28 )
{
F_41 ( V_4 , V_23 , V_2 , 1 , V_28 ) ;
}
static void
F_49 ( unsigned long V_23 , unsigned long V_24 ,
struct V_1 * V_2 , struct V_41 * V_4 ,
void * V_28 )
{
F_41 ( V_4 , V_23 , V_2 , 0 , V_28 ) ;
}
static void
F_50 ( unsigned long V_23 , unsigned long V_24 ,
struct V_1 * V_2 , struct V_41 * V_4 ,
void * V_28 )
{
if ( F_44 ( V_2 ) )
return;
F_45 ( V_2 ) ;
}
static void
F_51 ( unsigned long V_23 , unsigned long V_24 ,
struct V_1 * V_2 , struct V_41 * V_4 ,
void * V_28 )
{
if ( ! F_44 ( V_2 ) )
return;
F_46 ( V_2 ) ;
}
static T_3 void F_52 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_30 ;
F_27 ( V_9 ) ;
V_30 = F_21 () ;
F_35 ( V_2 , V_9 , V_47 , V_30 ) ;
}
static void
F_53 ( unsigned long V_23 , unsigned long V_24 ,
struct V_1 * V_2 , struct V_41 * V_4 ,
void * V_28 )
{
F_52 ( V_2 ) ;
}
static void
F_54 ( unsigned long V_23 , unsigned long V_24 ,
struct V_1 * V_2 , struct V_41 * V_4 ,
void * V_28 )
{
struct V_43 * V_44 = V_28 ;
long * V_45 ;
long V_46 ;
long V_48 ;
if ( ! F_55 () )
return;
if ( ! V_44 ) {
F_52 ( V_2 ) ;
return;
}
V_45 = ( long * ) F_42 ( V_44 , V_23 ) ;
do {
V_46 = * V_45 ;
if ( ! V_46 )
return;
V_48 = V_46 - 1 ;
V_48 = F_56 ( V_45 , V_46 , V_48 ) ;
if ( V_48 == V_46 )
F_52 ( V_2 ) ;
if ( ! F_55 () )
return;
} while ( V_48 != V_46 );
}
static int F_57 ( struct V_41 * V_4 , unsigned long V_23 ,
void * V_28 )
{
struct V_43 * V_44 = V_28 ;
long * V_45 = NULL ;
if ( V_44 )
V_45 = ( long * ) F_42 ( V_44 , V_23 ) ;
if ( V_45 ) {
if ( * V_45 <= 0 )
return 0 ;
( * V_45 ) -- ;
}
return 1 ;
}
static void
F_58 ( unsigned long V_23 , unsigned long V_24 ,
struct V_1 * V_2 , struct V_41 * V_4 ,
void * V_28 )
{
if ( F_57 ( V_4 , V_23 , V_28 ) )
F_59 ( V_49 ) ;
}
static void
F_60 ( unsigned long V_23 , unsigned long V_24 ,
struct V_1 * V_2 , struct V_41 * V_4 ,
void * V_28 )
{
if ( F_57 ( V_4 , V_23 , V_28 ) )
F_59 ( V_50 ) ;
}
static int
F_61 ( const char * V_51 , struct V_52 * V_53 ,
unsigned long V_23 , struct V_41 * V_4 ,
void * V_28 )
{
struct V_43 * V_44 = V_28 ;
long * V_45 = NULL ;
F_62 ( V_53 , L_1 , ( void * ) V_23 , V_51 ) ;
if ( V_44 )
V_45 = ( long * ) F_42 ( V_44 , V_23 ) ;
if ( V_45 )
F_62 ( V_53 , L_2 , * V_45 ) ;
else
F_63 ( V_53 , L_3 ) ;
return 0 ;
}
static int
F_64 ( struct V_52 * V_53 , unsigned long V_23 ,
struct V_41 * V_4 ,
void * V_28 )
{
return F_61 ( L_4 , V_53 , V_23 , V_4 , V_28 ) ;
}
static int
F_65 ( struct V_52 * V_53 , unsigned long V_23 ,
struct V_41 * V_4 , void * V_28 )
{
return F_61 ( L_5 , V_53 , V_23 , V_4 , V_28 ) ;
}
static int
F_66 ( struct V_52 * V_53 , unsigned long V_23 ,
struct V_41 * V_4 , void * V_28 )
{
return F_61 ( L_6 , V_53 , V_23 , V_4 , V_28 ) ;
}
static int
F_67 ( struct V_52 * V_53 , unsigned long V_23 ,
struct V_41 * V_4 , void * V_28 )
{
return F_61 ( L_7 , V_53 , V_23 , V_4 , V_28 ) ;
}
static int
F_68 ( struct V_52 * V_53 , unsigned long V_23 ,
struct V_41 * V_4 , void * V_28 )
{
return F_61 ( L_8 , V_53 , V_23 , V_4 , V_28 ) ;
}
static int
F_69 ( struct V_41 * V_4 , struct V_1 * V_2 ,
unsigned long V_23 , void * V_54 , void * * V_28 )
{
struct V_43 * V_44 = * V_28 ;
if ( ! V_44 ) {
V_44 = F_70 () ;
if ( ! V_44 )
return - V_6 ;
* V_28 = V_44 ;
}
return F_71 ( V_44 , V_23 , V_54 ) ;
}
static void
F_72 ( struct V_41 * V_4 , struct V_1 * V_2 ,
unsigned long V_23 , void * V_28 )
{
struct V_43 * V_44 = V_28 ;
if ( ! V_23 ) {
F_73 ( V_44 , NULL ) ;
return;
}
F_74 ( V_44 , V_23 ) ;
}
static int
F_75 ( struct V_1 * V_2 ,
struct V_41 * V_4 ,
struct V_55 * V_56 , char * V_57 ,
char * V_58 , char * V_59 , int V_60 )
{
void * V_45 = ( void * ) - 1 ;
char * V_61 ;
int V_15 ;
if ( ! V_60 )
return - V_40 ;
if ( V_57 [ 0 ] == '!' )
return F_76 ( V_57 + 1 , V_2 , V_4 ) ;
if ( ! V_59 )
goto V_62;
V_61 = F_77 ( & V_59 , L_9 ) ;
if ( ! strlen ( V_61 ) )
goto V_62;
V_15 = F_78 ( V_61 , 0 , ( unsigned long * ) & V_45 ) ;
if ( V_15 )
return V_15 ;
V_62:
V_15 = F_79 ( V_57 , V_2 , V_4 , V_45 ) ;
return V_15 < 0 ? V_15 : 0 ;
}
static int
F_80 ( struct V_1 * V_2 , struct V_55 * V_56 ,
char * V_57 , char * V_58 , char * V_59 , int V_60 )
{
struct V_41 * V_4 ;
if ( ! V_2 )
return - V_63 ;
if ( strcmp ( V_58 , L_4 ) == 0 )
V_4 = V_59 ? & V_64 : & V_65 ;
else
V_4 = V_59 ? & V_66 : & V_67 ;
return F_75 ( V_2 , V_4 , V_56 , V_57 , V_58 ,
V_59 , V_60 ) ;
}
static int
F_81 ( struct V_1 * V_2 , struct V_55 * V_56 ,
char * V_57 , char * V_58 , char * V_59 , int V_60 )
{
struct V_41 * V_4 ;
if ( ! V_2 )
return - V_63 ;
V_4 = V_59 ? & V_68 : & V_69 ;
return F_75 ( V_2 , V_4 , V_56 , V_57 , V_58 ,
V_59 , V_60 ) ;
}
static int
F_82 ( struct V_1 * V_2 , struct V_55 * V_56 ,
char * V_57 , char * V_58 , char * V_59 , int V_60 )
{
struct V_41 * V_4 ;
if ( ! V_2 )
return - V_63 ;
V_4 = & V_70 ;
return F_75 ( V_2 , V_4 , V_56 , V_57 , V_58 ,
L_10 , V_60 ) ;
}
static int
F_83 ( struct V_1 * V_2 , struct V_55 * V_56 ,
char * V_57 , char * V_58 , char * V_59 , int V_60 )
{
struct V_41 * V_4 ;
if ( ! V_2 )
return - V_63 ;
V_4 = & V_71 ;
return F_75 ( V_2 , V_4 , V_56 , V_57 , V_58 ,
L_10 , V_60 ) ;
}
static int T_4 F_84 ( void )
{
int V_15 ;
V_15 = F_85 ( & V_72 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_85 ( & V_73 ) ;
if ( V_15 )
goto V_74;
V_15 = F_85 ( & V_75 ) ;
if ( V_15 )
goto V_76;
V_15 = F_85 ( & V_77 ) ;
if ( V_15 )
goto V_78;
V_15 = F_85 ( & V_79 ) ;
if ( V_15 )
goto V_80;
return 0 ;
V_80:
F_86 ( & V_77 ) ;
V_78:
F_86 ( & V_75 ) ;
V_76:
F_86 ( & V_73 ) ;
V_74:
F_86 ( & V_72 ) ;
return V_15 ;
}
static inline int F_84 ( void )
{
return 0 ;
}
T_4 int F_87 ( void )
{
F_84 () ;
return F_88 ( & V_39 ) ;
}
