void F_1 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_4 , const char * V_5 ,
const char * V_6 , const char * V_7 , ... )
{
struct V_8 V_9 ;
T_1 args ;
if ( V_4 != V_10 && ! ( V_11 & V_4 ) )
return;
va_start ( args , V_7 ) ;
V_9 . V_12 = V_7 ;
V_9 . V_13 = & args ;
if ( V_2 )
F_2 ( V_3 , V_2 , V_14 , V_5 , V_6 ,
& V_9 ) ;
else
F_3 ( L_1 V_14 , V_3 , V_5 , V_6 , & V_9 ) ;
va_end ( args ) ;
}
void F_4 ( const char * V_3 , unsigned int V_4 ,
const char * V_7 , ... )
{
struct V_8 V_9 ;
T_1 args ;
if ( V_4 != V_10 && ! ( V_11 & V_4 ) )
return;
va_start ( args , V_7 ) ;
V_9 . V_12 = V_7 ;
V_9 . V_13 = & args ;
F_3 ( L_1 L_2 V_15 L_3 ,
V_3 , F_5 ( 0 ) ,
strcmp ( V_3 , V_16 ) == 0 ? L_4 : L_5 , & V_9 ) ;
va_end ( args ) ;
}
static struct V_17 * * F_6 ( struct V_18 * V_2 ,
unsigned int type )
{
switch ( type ) {
case V_19 :
return & V_2 -> V_20 ;
case V_21 :
return & V_2 -> V_22 ;
case V_23 :
return & V_2 -> V_24 ;
default:
return NULL ;
}
}
static int F_7 ( struct V_18 * V_2 , unsigned int type )
{
struct V_17 * V_25 ;
unsigned long V_26 ;
int V_27 ;
V_25 = F_8 ( sizeof( * V_25 ) , V_28 ) ;
if ( ! V_25 )
return - V_29 ;
V_25 -> type = type ;
V_25 -> V_2 = V_2 ;
F_9 ( V_28 ) ;
F_10 ( & V_30 , V_26 ) ;
V_27 = F_11 ( & V_31 ,
NULL ,
64 * type ,
64 * ( type + 1 ) ,
V_32 ) ;
F_12 ( & V_30 , V_26 ) ;
F_13 () ;
if ( V_27 < 0 )
goto V_33;
V_25 -> V_34 = V_27 ;
V_25 -> V_35 = F_14 ( V_25 ) ;
if ( F_15 ( V_25 -> V_35 ) ) {
V_27 = F_16 ( V_25 -> V_35 ) ;
goto V_36;
}
* F_6 ( V_2 , type ) = V_25 ;
return 0 ;
V_36:
F_10 ( & V_30 , V_26 ) ;
F_17 ( & V_31 , V_25 -> V_34 ) ;
F_12 ( & V_30 , V_26 ) ;
V_33:
F_18 ( V_25 ) ;
return V_27 ;
}
static void F_19 ( struct V_18 * V_2 , unsigned int type )
{
struct V_17 * * V_37 , * V_25 ;
unsigned long V_26 ;
V_37 = F_6 ( V_2 , type ) ;
V_25 = * V_37 ;
if ( ! V_25 )
return;
F_20 ( V_25 -> V_35 ) ;
F_10 ( & V_30 , V_26 ) ;
F_17 ( & V_31 , V_25 -> V_34 ) ;
F_12 ( & V_30 , V_26 ) ;
F_18 ( V_25 ) ;
* V_37 = NULL ;
}
static int F_21 ( struct V_18 * V_2 , unsigned int type )
{
struct V_17 * V_25 ;
unsigned long V_26 ;
int V_38 ;
F_22 ( L_6 ) ;
V_25 = * F_6 ( V_2 , type ) ;
if ( ! V_25 )
return 0 ;
V_38 = F_23 ( V_25 , V_25 -> V_34 , V_39 ) ;
if ( V_38 ) {
F_24 ( L_7 ) ;
goto V_40;
}
V_38 = F_25 ( V_25 -> V_35 ) ;
if ( V_38 )
goto V_40;
F_10 ( & V_30 , V_26 ) ;
F_26 ( & V_31 , V_25 , V_25 -> V_34 ) ;
F_12 ( & V_30 , V_26 ) ;
F_22 ( L_8 , V_25 -> V_34 ) ;
return 0 ;
V_40:
F_27 ( V_25 ) ;
return V_38 ;
}
static void F_28 ( struct V_18 * V_2 , unsigned int type )
{
struct V_17 * V_25 ;
unsigned long V_26 ;
V_25 = * F_6 ( V_2 , type ) ;
if ( ! V_25 || ! F_29 ( V_25 -> V_35 ) )
return;
F_10 ( & V_30 , V_26 ) ;
F_26 ( & V_31 , NULL , V_25 -> V_34 ) ;
F_12 ( & V_30 , V_26 ) ;
F_30 ( V_25 -> V_35 ) ;
F_31 ( V_25 -> V_35 , NULL ) ;
F_27 ( V_25 ) ;
}
struct V_17 * F_32 ( unsigned int V_41 )
{
struct V_17 * V_25 ;
unsigned long V_26 ;
F_10 ( & V_30 , V_26 ) ;
V_25 = F_33 ( & V_31 , V_41 ) ;
if ( V_25 )
F_34 ( V_25 -> V_2 ) ;
F_12 ( & V_30 , V_26 ) ;
if ( ! V_25 ) {
return F_35 ( - V_42 ) ;
} else if ( F_36 ( V_25 -> V_2 ) ) {
F_37 ( V_25 -> V_2 ) ;
return F_35 ( - V_42 ) ;
}
return V_25 ;
}
void F_38 ( struct V_17 * V_25 )
{
F_37 ( V_25 -> V_2 ) ;
}
void F_39 ( struct V_18 * V_2 )
{
F_22 ( L_6 ) ;
if ( ! V_2 ) {
F_24 ( L_9 ) ;
return;
}
F_40 ( V_2 ) ;
F_37 ( V_2 ) ;
}
void F_41 ( struct V_18 * V_2 )
{
if ( F_42 ( V_2 , V_43 ) )
F_43 ( V_2 ) ;
F_28 ( V_2 , V_19 ) ;
F_28 ( V_2 , V_21 ) ;
F_28 ( V_2 , V_23 ) ;
F_44 ( & V_44 ) ;
F_45 ( V_2 ) ;
if ( V_2 -> V_45 == 0 ) {
F_39 ( V_2 ) ;
}
F_46 ( & V_44 ) ;
}
static struct V_46 * F_47 ( struct V_47 * V_48 , int V_26 ,
const char * V_49 , void * V_50 )
{
return F_48 ( V_48 ,
L_10 ,
& V_51 ,
& V_52 ,
0x010203ff ) ;
}
static struct V_53 * F_49 ( void )
{
struct V_53 * V_53 ;
int V_27 ;
V_27 = F_50 ( & V_54 , & V_55 , & V_56 ) ;
if ( V_27 < 0 ) {
F_24 ( L_11 , V_27 ) ;
return F_35 ( V_27 ) ;
}
V_53 = F_51 ( V_55 -> V_57 ) ;
if ( F_15 ( V_53 ) )
F_52 ( & V_55 , & V_56 ) ;
return V_53 ;
}
static void F_53 ( struct V_53 * V_53 )
{
if ( V_53 ) {
F_54 ( V_53 ) ;
F_52 ( & V_55 , & V_56 ) ;
}
}
int F_55 ( struct V_18 * V_2 ,
struct V_58 * V_59 ,
struct V_1 * V_60 )
{
int V_38 ;
F_56 ( & V_2 -> V_61 ) ;
V_2 -> V_2 = V_60 ;
V_2 -> V_59 = V_59 ;
F_57 ( & V_2 -> V_62 ) ;
F_57 ( & V_2 -> V_63 ) ;
F_57 ( & V_2 -> V_64 ) ;
F_57 ( & V_2 -> V_65 ) ;
F_57 ( & V_2 -> V_66 ) ;
F_58 ( & V_2 -> V_67 ) ;
F_58 ( & V_2 -> V_68 ) ;
F_59 ( & V_2 -> V_69 ) ;
F_59 ( & V_2 -> V_70 ) ;
F_59 ( & V_2 -> V_71 ) ;
F_59 ( & V_2 -> V_72 ) ;
V_2 -> V_73 = F_49 () ;
if ( F_15 ( V_2 -> V_73 ) ) {
V_38 = F_16 ( V_2 -> V_73 ) ;
F_24 ( L_12 , V_38 ) ;
goto V_33;
}
if ( F_42 ( V_2 , V_74 ) ) {
V_38 = F_7 ( V_2 , V_21 ) ;
if ( V_38 )
goto V_75;
}
V_38 = F_7 ( V_2 , V_19 ) ;
if ( V_38 )
goto V_75;
V_38 = F_60 ( & V_2 -> V_76 , 12 ) ;
if ( V_38 )
goto V_75;
F_61 ( V_2 ) ;
if ( F_42 ( V_2 , V_77 ) ) {
V_38 = F_62 ( V_2 ) ;
if ( V_38 ) {
F_24 ( L_13 ) ;
goto V_78;
}
}
V_38 = F_63 ( V_2 , V_60 ? V_49 ( V_60 ) : V_59 -> V_79 ) ;
if ( V_38 )
goto V_80;
return 0 ;
V_80:
if ( F_42 ( V_2 , V_77 ) )
F_64 ( V_2 ) ;
V_78:
F_65 ( V_2 ) ;
F_66 ( & V_2 -> V_76 ) ;
V_75:
F_19 ( V_2 , V_19 ) ;
F_19 ( V_2 , V_21 ) ;
F_19 ( V_2 , V_23 ) ;
F_53 ( V_2 -> V_73 ) ;
V_33:
F_67 ( & V_2 -> V_72 ) ;
F_67 ( & V_2 -> V_71 ) ;
F_67 ( & V_2 -> V_70 ) ;
F_67 ( & V_2 -> V_69 ) ;
return V_38 ;
}
void F_68 ( struct V_18 * V_2 )
{
F_69 ( V_2 ) ;
if ( F_42 ( V_2 , V_77 ) )
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
F_66 ( & V_2 -> V_76 ) ;
F_53 ( V_2 -> V_73 ) ;
F_19 ( V_2 , V_19 ) ;
F_19 ( V_2 , V_21 ) ;
F_19 ( V_2 , V_23 ) ;
F_67 ( & V_2 -> V_72 ) ;
F_67 ( & V_2 -> V_71 ) ;
F_67 ( & V_2 -> V_70 ) ;
F_67 ( & V_2 -> V_69 ) ;
F_18 ( V_2 -> V_81 ) ;
}
struct V_18 * F_70 ( struct V_58 * V_59 ,
struct V_1 * V_60 )
{
struct V_18 * V_2 ;
int V_38 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_35 ( - V_29 ) ;
V_38 = F_55 ( V_2 , V_59 , V_60 ) ;
if ( V_38 ) {
F_18 ( V_2 ) ;
return F_35 ( V_38 ) ;
}
return V_2 ;
}
static void F_71 ( struct V_82 * V_61 )
{
struct V_18 * V_2 = F_72 ( V_61 , struct V_18 , V_61 ) ;
if ( V_2 -> V_59 -> V_83 ) {
V_2 -> V_59 -> V_83 ( V_2 ) ;
} else {
F_68 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
void F_34 ( struct V_18 * V_2 )
{
if ( V_2 )
F_73 ( & V_2 -> V_61 ) ;
}
void F_37 ( struct V_18 * V_2 )
{
if ( V_2 )
F_74 ( & V_2 -> V_61 , F_71 ) ;
}
static int F_75 ( struct V_18 * V_2 )
{
struct V_17 * V_25 ;
char * V_79 ;
int V_38 ;
if ( ! F_42 ( V_2 , V_43 ) )
return 0 ;
V_25 = * F_6 ( V_2 , V_19 ) ;
if ( ! V_25 )
return 0 ;
V_79 = F_76 ( V_28 , L_14 , V_25 -> V_34 + 64 ) ;
if ( ! V_79 )
return - V_29 ;
V_38 = F_77 ( V_25 -> V_35 -> V_84 . V_60 ,
& V_25 -> V_35 -> V_84 ,
V_79 ) ;
F_18 ( V_79 ) ;
return V_38 ;
}
static void F_78 ( struct V_18 * V_2 )
{
struct V_17 * V_25 ;
char * V_79 ;
if ( ! F_42 ( V_2 , V_43 ) )
return;
V_25 = * F_6 ( V_2 , V_19 ) ;
if ( ! V_25 )
return;
V_79 = F_76 ( V_28 , L_14 , V_25 -> V_34 ) ;
if ( ! V_79 )
return;
F_79 ( V_25 -> V_35 -> V_84 . V_60 , V_79 ) ;
F_18 ( V_79 ) ;
}
int F_80 ( struct V_18 * V_2 , unsigned long V_26 )
{
struct V_58 * V_59 = V_2 -> V_59 ;
int V_38 ;
F_44 ( & V_44 ) ;
V_38 = F_21 ( V_2 , V_23 ) ;
if ( V_38 )
goto V_75;
V_38 = F_21 ( V_2 , V_21 ) ;
if ( V_38 )
goto V_75;
V_38 = F_21 ( V_2 , V_19 ) ;
if ( V_38 )
goto V_75;
V_38 = F_75 ( V_2 ) ;
if ( V_38 )
goto V_75;
V_2 -> V_85 = true ;
if ( V_2 -> V_59 -> V_86 ) {
V_38 = V_2 -> V_59 -> V_86 ( V_2 , V_26 ) ;
if ( V_38 )
goto V_75;
}
if ( F_42 ( V_2 , V_43 ) )
F_81 ( V_2 ) ;
V_38 = 0 ;
F_82 ( L_15 ,
V_59 -> V_79 , V_59 -> V_87 , V_59 -> V_25 ,
V_59 -> V_88 , V_59 -> V_89 ,
V_2 -> V_2 ? V_49 ( V_2 -> V_2 ) : L_16 ,
V_2 -> V_20 -> V_34 ) ;
goto V_90;
V_75:
F_78 ( V_2 ) ;
F_28 ( V_2 , V_19 ) ;
F_28 ( V_2 , V_21 ) ;
F_28 ( V_2 , V_23 ) ;
V_90:
F_46 ( & V_44 ) ;
return V_38 ;
}
void F_40 ( struct V_18 * V_2 )
{
struct V_91 * V_92 , * V_93 ;
F_83 ( V_2 ) ;
V_2 -> V_85 = false ;
if ( F_42 ( V_2 , V_43 ) )
F_43 ( V_2 ) ;
if ( V_2 -> V_59 -> V_94 )
V_2 -> V_59 -> V_94 ( V_2 ) ;
if ( V_2 -> V_95 )
F_84 ( V_2 ) ;
F_85 (r_list, list_temp, &dev->maplist, head)
F_86 ( V_2 , V_92 -> V_96 ) ;
F_78 ( V_2 ) ;
F_28 ( V_2 , V_19 ) ;
F_28 ( V_2 , V_21 ) ;
F_28 ( V_2 , V_23 ) ;
}
int F_63 ( struct V_18 * V_2 , const char * V_79 )
{
F_18 ( V_2 -> V_81 ) ;
V_2 -> V_81 = F_87 ( V_79 , V_28 ) ;
return V_2 -> V_81 ? 0 : - V_29 ;
}
static int F_88 ( struct V_53 * V_53 , struct V_97 * V_98 )
{
const struct V_99 * V_100 ;
struct V_17 * V_25 ;
int V_101 ;
F_22 ( L_6 ) ;
F_44 ( & V_44 ) ;
V_25 = F_32 ( F_89 ( V_53 ) ) ;
if ( F_15 ( V_25 ) ) {
V_101 = F_16 ( V_25 ) ;
goto V_90;
}
V_100 = F_90 ( V_25 -> V_2 -> V_59 -> V_102 ) ;
if ( ! V_100 ) {
V_101 = - V_42 ;
goto V_103;
}
F_91 ( V_98 , V_100 ) ;
if ( V_98 -> V_104 -> V_105 )
V_101 = V_98 -> V_104 -> V_105 ( V_53 , V_98 ) ;
else
V_101 = 0 ;
V_103:
F_38 ( V_25 ) ;
V_90:
F_46 ( & V_44 ) ;
return V_101 ;
}
static void F_92 ( void )
{
F_93 ( V_106 , L_17 ) ;
F_94 ( V_39 ) ;
F_95 () ;
F_96 ( & V_31 ) ;
F_97 () ;
F_98 () ;
}
static int T_2 F_99 ( void )
{
int V_38 ;
F_100 () ;
F_101 () ;
F_102 ( & V_31 ) ;
V_38 = F_103 () ;
if ( V_38 < 0 ) {
F_24 ( L_18 , V_38 ) ;
goto error;
}
V_39 = F_104 ( L_19 , NULL ) ;
if ( ! V_39 ) {
V_38 = - V_29 ;
F_24 ( L_20 , V_38 ) ;
goto error;
}
V_38 = F_105 ( V_106 , L_17 , & V_107 ) ;
if ( V_38 < 0 )
goto error;
F_22 ( L_21 ) ;
return 0 ;
error:
F_92 () ;
return V_38 ;
}
