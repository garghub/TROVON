void F_1 ( const char * V_1 , ... )
{
struct V_2 V_3 ;
T_1 args ;
va_start ( args , V_1 ) ;
V_3 . V_4 = V_1 ;
V_3 . V_5 = & args ;
F_2 ( V_6 L_1 V_7 L_2 ,
F_3 ( 0 ) , & V_3 ) ;
va_end ( args ) ;
}
void F_4 ( const char * V_8 , const char * V_1 , ... )
{
struct V_2 V_3 ;
T_1 args ;
va_start ( args , V_1 ) ;
V_3 . V_4 = V_1 ;
V_3 . V_5 = & args ;
F_2 ( V_9 L_1 V_7 L_3 , V_8 , & V_3 ) ;
va_end ( args ) ;
}
static struct V_10 * * F_5 ( struct V_11 * V_12 ,
unsigned int type )
{
switch ( type ) {
case V_13 :
return & V_12 -> V_14 ;
case V_15 :
return & V_12 -> V_16 ;
case V_17 :
return & V_12 -> V_18 ;
default:
return NULL ;
}
}
static int F_6 ( struct V_11 * V_12 , unsigned int type )
{
struct V_10 * V_19 ;
unsigned long V_20 ;
int V_21 ;
V_19 = F_7 ( sizeof( * V_19 ) , V_22 ) ;
if ( ! V_19 )
return - V_23 ;
V_19 -> type = type ;
V_19 -> V_12 = V_12 ;
F_8 ( V_22 ) ;
F_9 ( & V_24 , V_20 ) ;
V_21 = F_10 ( & V_25 ,
NULL ,
64 * type ,
64 * ( type + 1 ) ,
V_26 ) ;
F_11 ( & V_24 , V_20 ) ;
F_12 () ;
if ( V_21 < 0 )
goto V_27;
V_19 -> V_28 = V_21 ;
V_19 -> V_29 = F_13 ( V_19 ) ;
if ( F_14 ( V_19 -> V_29 ) ) {
V_21 = F_15 ( V_19 -> V_29 ) ;
goto V_30;
}
* F_5 ( V_12 , type ) = V_19 ;
return 0 ;
V_30:
F_9 ( & V_24 , V_20 ) ;
F_16 ( & V_25 , V_19 -> V_28 ) ;
F_11 ( & V_24 , V_20 ) ;
V_27:
F_17 ( V_19 ) ;
return V_21 ;
}
static void F_18 ( struct V_11 * V_12 , unsigned int type )
{
struct V_10 * * V_31 , * V_19 ;
unsigned long V_20 ;
V_31 = F_5 ( V_12 , type ) ;
V_19 = * V_31 ;
if ( ! V_19 )
return;
F_19 ( V_19 -> V_29 ) ;
F_9 ( & V_24 , V_20 ) ;
F_16 ( & V_25 , V_19 -> V_28 ) ;
F_11 ( & V_24 , V_20 ) ;
F_17 ( V_19 ) ;
* V_31 = NULL ;
}
static int F_20 ( struct V_11 * V_12 , unsigned int type )
{
struct V_10 * V_19 ;
unsigned long V_20 ;
int V_32 ;
F_21 ( L_4 ) ;
V_19 = * F_5 ( V_12 , type ) ;
if ( ! V_19 )
return 0 ;
V_32 = F_22 ( V_19 , V_19 -> V_28 , V_33 ) ;
if ( V_32 ) {
F_23 ( L_5 ) ;
return V_32 ;
}
V_32 = F_24 ( V_19 -> V_29 ) ;
if ( V_32 )
goto V_34;
F_9 ( & V_24 , V_20 ) ;
F_25 ( & V_25 , V_19 , V_19 -> V_28 ) ;
F_11 ( & V_24 , V_20 ) ;
F_21 ( L_6 , V_19 -> V_28 ) ;
return 0 ;
V_34:
F_26 ( V_19 ) ;
return V_32 ;
}
static void F_27 ( struct V_11 * V_12 , unsigned int type )
{
struct V_10 * V_19 ;
unsigned long V_20 ;
V_19 = * F_5 ( V_12 , type ) ;
if ( ! V_19 || ! F_28 ( V_19 -> V_29 ) )
return;
F_9 ( & V_24 , V_20 ) ;
F_25 ( & V_25 , NULL , V_19 -> V_28 ) ;
F_11 ( & V_24 , V_20 ) ;
F_29 ( V_19 -> V_29 ) ;
F_30 ( V_19 -> V_29 , NULL ) ;
F_26 ( V_19 ) ;
}
struct V_10 * F_31 ( unsigned int V_35 )
{
struct V_10 * V_19 ;
unsigned long V_20 ;
F_9 ( & V_24 , V_20 ) ;
V_19 = F_32 ( & V_25 , V_35 ) ;
if ( V_19 )
F_33 ( V_19 -> V_12 ) ;
F_11 ( & V_24 , V_20 ) ;
if ( ! V_19 ) {
return F_34 ( - V_36 ) ;
} else if ( F_35 ( V_19 -> V_12 ) ) {
F_36 ( V_19 -> V_12 ) ;
return F_34 ( - V_36 ) ;
}
return V_19 ;
}
void F_37 ( struct V_10 * V_19 )
{
F_36 ( V_19 -> V_12 ) ;
}
static int F_38 ( struct V_11 * V_12 , const char * V_37 )
{
F_17 ( V_12 -> V_38 ) ;
V_12 -> V_38 = F_39 ( V_37 , V_22 ) ;
return V_12 -> V_38 ? 0 : - V_23 ;
}
void F_40 ( struct V_11 * V_12 )
{
F_21 ( L_4 ) ;
if ( ! V_12 ) {
F_23 ( L_7 ) ;
return;
}
F_41 ( V_12 ) ;
F_36 ( V_12 ) ;
}
void F_42 ( struct V_11 * V_12 )
{
F_41 ( V_12 ) ;
F_43 ( & V_39 ) ;
F_44 ( V_12 ) ;
if ( V_12 -> V_40 == 0 ) {
F_40 ( V_12 ) ;
}
F_45 ( & V_39 ) ;
}
static struct V_41 * F_46 ( struct V_42 * V_43 , int V_20 ,
const char * V_44 , void * V_45 )
{
return F_47 ( V_43 ,
L_8 ,
& V_46 ,
& V_47 ,
0x010203ff ) ;
}
static struct V_48 * F_48 ( void )
{
struct V_48 * V_48 ;
int V_21 ;
V_21 = F_49 ( & V_49 , & V_50 , & V_51 ) ;
if ( V_21 < 0 ) {
F_23 ( L_9 , V_21 ) ;
return F_34 ( V_21 ) ;
}
V_48 = F_50 ( V_50 -> V_52 ) ;
if ( F_14 ( V_48 ) )
F_51 ( & V_50 , & V_51 ) ;
return V_48 ;
}
static void F_52 ( struct V_48 * V_48 )
{
if ( V_48 ) {
F_53 ( V_48 ) ;
F_51 ( & V_50 , & V_51 ) ;
}
}
int F_54 ( struct V_11 * V_12 ,
struct V_53 * V_54 ,
struct V_55 * V_56 )
{
int V_32 ;
F_55 ( & V_12 -> V_57 ) ;
V_12 -> V_12 = V_56 ;
V_12 -> V_54 = V_54 ;
F_56 ( & V_12 -> V_58 ) ;
F_56 ( & V_12 -> V_59 ) ;
F_56 ( & V_12 -> V_60 ) ;
F_56 ( & V_12 -> V_61 ) ;
F_56 ( & V_12 -> V_62 ) ;
F_57 ( & V_12 -> V_63 ) ;
F_57 ( & V_12 -> V_64 ) ;
F_58 ( & V_12 -> V_65 ) ;
F_58 ( & V_12 -> V_66 ) ;
F_58 ( & V_12 -> V_67 ) ;
F_58 ( & V_12 -> V_68 ) ;
V_12 -> V_69 = F_48 () ;
if ( F_14 ( V_12 -> V_69 ) ) {
V_32 = F_15 ( V_12 -> V_69 ) ;
F_23 ( L_10 , V_32 ) ;
goto V_27;
}
if ( F_59 ( V_12 , V_70 ) ) {
V_32 = F_6 ( V_12 , V_17 ) ;
if ( V_32 )
goto V_71;
}
if ( F_59 ( V_12 , V_72 ) ) {
V_32 = F_6 ( V_12 , V_15 ) ;
if ( V_32 )
goto V_71;
}
V_32 = F_6 ( V_12 , V_13 ) ;
if ( V_32 )
goto V_71;
V_32 = F_60 ( & V_12 -> V_73 , 12 ) ;
if ( V_32 )
goto V_71;
F_61 ( V_12 ) ;
if ( F_59 ( V_12 , V_74 ) ) {
V_32 = F_62 ( V_12 ) ;
if ( V_32 ) {
F_23 ( L_11 ) ;
goto V_75;
}
}
V_32 = F_38 ( V_12 , V_56 ? V_44 ( V_56 ) : V_54 -> V_37 ) ;
if ( V_32 )
goto V_76;
return 0 ;
V_76:
if ( F_59 ( V_12 , V_74 ) )
F_63 ( V_12 ) ;
V_75:
F_64 ( V_12 ) ;
F_65 ( & V_12 -> V_73 ) ;
V_71:
F_18 ( V_12 , V_13 ) ;
F_18 ( V_12 , V_15 ) ;
F_18 ( V_12 , V_17 ) ;
F_52 ( V_12 -> V_69 ) ;
V_27:
F_66 ( & V_12 -> V_68 ) ;
return V_32 ;
}
struct V_11 * F_67 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_11 * V_12 ;
int V_32 ;
V_12 = F_7 ( sizeof( * V_12 ) , V_22 ) ;
if ( ! V_12 )
return NULL ;
V_32 = F_54 ( V_12 , V_54 , V_56 ) ;
if ( V_32 ) {
F_17 ( V_12 ) ;
return NULL ;
}
return V_12 ;
}
static void F_68 ( struct V_77 * V_57 )
{
struct V_11 * V_12 = F_69 ( V_57 , struct V_11 , V_57 ) ;
if ( F_59 ( V_12 , V_74 ) )
F_63 ( V_12 ) ;
F_64 ( V_12 ) ;
F_65 ( & V_12 -> V_73 ) ;
F_52 ( V_12 -> V_69 ) ;
F_18 ( V_12 , V_13 ) ;
F_18 ( V_12 , V_15 ) ;
F_18 ( V_12 , V_17 ) ;
F_66 ( & V_12 -> V_68 ) ;
F_17 ( V_12 -> V_38 ) ;
F_17 ( V_12 ) ;
}
void F_33 ( struct V_11 * V_12 )
{
if ( V_12 )
F_70 ( & V_12 -> V_57 ) ;
}
void F_36 ( struct V_11 * V_12 )
{
if ( V_12 )
F_71 ( & V_12 -> V_57 , F_68 ) ;
}
int F_72 ( struct V_11 * V_12 , unsigned long V_20 )
{
int V_32 ;
F_43 ( & V_39 ) ;
V_32 = F_20 ( V_12 , V_17 ) ;
if ( V_32 )
goto V_71;
V_32 = F_20 ( V_12 , V_15 ) ;
if ( V_32 )
goto V_71;
V_32 = F_20 ( V_12 , V_13 ) ;
if ( V_32 )
goto V_71;
if ( V_12 -> V_54 -> V_78 ) {
V_32 = V_12 -> V_54 -> V_78 ( V_12 , V_20 ) ;
if ( V_32 )
goto V_71;
}
if ( F_59 ( V_12 , V_70 ) )
F_73 ( V_12 ) ;
V_32 = 0 ;
goto V_79;
V_71:
F_27 ( V_12 , V_13 ) ;
F_27 ( V_12 , V_15 ) ;
F_27 ( V_12 , V_17 ) ;
V_79:
F_45 ( & V_39 ) ;
return V_32 ;
}
void F_41 ( struct V_11 * V_12 )
{
struct V_80 * V_81 , * V_82 ;
F_74 ( V_12 ) ;
if ( F_59 ( V_12 , V_70 ) )
F_75 ( V_12 ) ;
if ( V_12 -> V_54 -> V_83 )
V_12 -> V_54 -> V_83 ( V_12 ) ;
if ( V_12 -> V_84 )
F_76 ( V_12 ) ;
F_77 ( V_12 ) ;
F_78 (r_list, list_temp, &dev->maplist, head)
F_79 ( V_12 , V_81 -> V_85 ) ;
F_27 ( V_12 , V_13 ) ;
F_27 ( V_12 , V_15 ) ;
F_27 ( V_12 , V_17 ) ;
}
static int F_80 ( struct V_48 * V_48 , struct V_86 * V_87 )
{
const struct V_88 * V_89 ;
struct V_10 * V_19 ;
int V_90 ;
F_21 ( L_4 ) ;
F_43 ( & V_39 ) ;
V_19 = F_31 ( F_81 ( V_48 ) ) ;
if ( F_14 ( V_19 ) ) {
V_90 = F_15 ( V_19 ) ;
goto V_79;
}
V_89 = F_82 ( V_19 -> V_12 -> V_54 -> V_91 ) ;
if ( ! V_89 ) {
V_90 = - V_36 ;
goto V_92;
}
F_83 ( V_87 , V_89 ) ;
if ( V_87 -> V_93 -> V_94 )
V_90 = V_87 -> V_93 -> V_94 ( V_48 , V_87 ) ;
else
V_90 = 0 ;
V_92:
F_37 ( V_19 ) ;
V_79:
F_45 ( & V_39 ) ;
return V_90 ;
}
static int T_2 F_84 ( void )
{
int V_32 = - V_23 ;
F_85 () ;
F_86 () ;
F_87 ( & V_25 ) ;
if ( F_88 ( V_95 , L_12 , & V_96 ) )
goto V_97;
V_32 = F_89 () ;
if ( V_32 < 0 ) {
F_2 ( V_6 L_13 ) ;
goto V_98;
}
V_33 = F_90 ( L_14 , NULL ) ;
if ( ! V_33 ) {
F_23 ( L_15 ) ;
V_32 = - 1 ;
goto V_99;
}
F_91 ( L_16 ,
V_100 , V_101 , V_102 , V_103 , V_104 ) ;
return 0 ;
V_99:
F_92 () ;
V_98:
F_93 ( V_95 , L_12 ) ;
F_94 ( & V_25 ) ;
V_97:
return V_32 ;
}
static void T_3 F_95 ( void )
{
F_96 ( V_33 ) ;
F_92 () ;
F_93 ( V_95 , L_12 ) ;
F_97 () ;
F_94 ( & V_25 ) ;
}
