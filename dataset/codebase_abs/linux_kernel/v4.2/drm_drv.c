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
struct V_10 * F_5 ( struct V_11 * V_12 )
{
struct V_10 * V_13 ;
V_13 = F_6 ( sizeof( * V_13 ) , V_14 ) ;
if ( ! V_13 )
return NULL ;
F_7 ( & V_13 -> V_15 ) ;
F_8 ( & V_13 -> V_16 . V_17 ) ;
F_9 ( & V_13 -> V_16 . V_18 ) ;
F_10 ( & V_13 -> V_19 ) ;
V_13 -> V_12 = V_12 ;
return V_13 ;
}
struct V_10 * F_11 ( struct V_10 * V_13 )
{
F_12 ( & V_13 -> V_15 ) ;
return V_13 ;
}
static void F_13 ( struct V_20 * V_20 )
{
struct V_10 * V_13 = F_14 ( V_20 , struct V_10 , V_15 ) ;
struct V_21 * V_22 = V_13 -> V_12 -> V_22 ;
struct V_23 * V_24 , * V_25 ;
F_15 ( & V_22 -> V_26 ) ;
if ( V_22 -> V_27 -> V_28 )
V_22 -> V_27 -> V_28 ( V_22 , V_13 ) ;
F_16 (r_list, list_temp, &dev->maplist, head) {
if ( V_24 -> V_13 == V_13 ) {
F_17 ( V_22 , V_24 -> V_29 ) ;
V_24 = NULL ;
}
}
F_18 ( & V_22 -> V_26 ) ;
F_19 ( & V_13 -> V_19 ) ;
F_20 ( V_13 -> V_30 ) ;
F_20 ( V_13 ) ;
}
void F_21 ( struct V_10 * * V_13 )
{
F_22 ( & ( * V_13 ) -> V_15 , F_13 ) ;
* V_13 = NULL ;
}
int F_23 ( struct V_21 * V_22 , void * V_31 ,
struct V_32 * V_33 )
{
int V_34 = 0 ;
F_15 ( & V_22 -> V_35 ) ;
if ( V_33 -> V_36 )
goto V_37;
if ( V_33 -> V_12 -> V_13 ) {
V_34 = - V_38 ;
goto V_37;
}
if ( ! V_33 -> V_13 ) {
V_34 = - V_38 ;
goto V_37;
}
V_33 -> V_12 -> V_13 = F_11 ( V_33 -> V_13 ) ;
V_33 -> V_36 = 1 ;
if ( V_22 -> V_27 -> V_39 ) {
V_34 = V_22 -> V_27 -> V_39 ( V_22 , V_33 , false ) ;
if ( F_24 ( V_34 != 0 ) ) {
V_33 -> V_36 = 0 ;
F_21 ( & V_33 -> V_12 -> V_13 ) ;
}
}
V_37:
F_18 ( & V_22 -> V_35 ) ;
return V_34 ;
}
int F_25 ( struct V_21 * V_22 , void * V_31 ,
struct V_32 * V_33 )
{
int V_34 = - V_38 ;
F_15 ( & V_22 -> V_35 ) ;
if ( ! V_33 -> V_36 )
goto V_37;
if ( ! V_33 -> V_12 -> V_13 )
goto V_37;
V_34 = 0 ;
if ( V_22 -> V_27 -> V_40 )
V_22 -> V_27 -> V_40 ( V_22 , V_33 , false ) ;
F_21 ( & V_33 -> V_12 -> V_13 ) ;
V_33 -> V_36 = 0 ;
V_37:
F_18 ( & V_22 -> V_35 ) ;
return V_34 ;
}
static struct V_11 * * F_26 ( struct V_21 * V_22 ,
unsigned int type )
{
switch ( type ) {
case V_41 :
return & V_22 -> V_42 ;
case V_43 :
return & V_22 -> V_44 ;
case V_45 :
return & V_22 -> V_46 ;
default:
return NULL ;
}
}
static int F_27 ( struct V_21 * V_22 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_47 ;
int V_48 ;
V_12 = F_6 ( sizeof( * V_12 ) , V_14 ) ;
if ( ! V_12 )
return - V_49 ;
V_12 -> type = type ;
V_12 -> V_22 = V_22 ;
F_28 ( V_14 ) ;
F_29 ( & V_50 , V_47 ) ;
V_48 = F_30 ( & V_51 ,
NULL ,
64 * type ,
64 * ( type + 1 ) ,
V_52 ) ;
F_31 ( & V_50 , V_47 ) ;
F_32 () ;
if ( V_48 < 0 )
goto V_53;
V_12 -> V_54 = V_48 ;
V_12 -> V_55 = F_33 ( V_12 ) ;
if ( F_34 ( V_12 -> V_55 ) ) {
V_48 = F_35 ( V_12 -> V_55 ) ;
goto V_56;
}
* F_26 ( V_22 , type ) = V_12 ;
return 0 ;
V_56:
F_29 ( & V_50 , V_47 ) ;
F_36 ( & V_51 , V_12 -> V_54 ) ;
F_31 ( & V_50 , V_47 ) ;
V_53:
F_20 ( V_12 ) ;
return V_48 ;
}
static void F_37 ( struct V_21 * V_22 , unsigned int type )
{
struct V_11 * * V_57 , * V_12 ;
unsigned long V_47 ;
V_57 = F_26 ( V_22 , type ) ;
V_12 = * V_57 ;
if ( ! V_12 )
return;
F_38 ( & V_12 -> V_58 ) ;
F_39 ( V_12 -> V_55 ) ;
F_29 ( & V_50 , V_47 ) ;
F_36 ( & V_51 , V_12 -> V_54 ) ;
F_31 ( & V_50 , V_47 ) ;
F_20 ( V_12 ) ;
* V_57 = NULL ;
}
static int F_40 ( struct V_21 * V_22 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_47 ;
int V_34 ;
F_41 ( L_4 ) ;
V_12 = * F_26 ( V_22 , type ) ;
if ( ! V_12 )
return 0 ;
V_34 = F_42 ( V_12 , V_12 -> V_54 , V_59 ) ;
if ( V_34 ) {
F_43 ( L_5 ) ;
return V_34 ;
}
V_34 = F_44 ( V_12 -> V_55 ) ;
if ( V_34 )
goto V_60;
F_29 ( & V_50 , V_47 ) ;
F_45 ( & V_51 , V_12 , V_12 -> V_54 ) ;
F_31 ( & V_50 , V_47 ) ;
F_41 ( L_6 , V_12 -> V_54 ) ;
return 0 ;
V_60:
F_46 ( V_12 ) ;
return V_34 ;
}
static void F_47 ( struct V_21 * V_22 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_47 ;
V_12 = * F_26 ( V_22 , type ) ;
if ( ! V_12 || ! F_48 ( V_12 -> V_55 ) )
return;
F_29 ( & V_50 , V_47 ) ;
F_45 ( & V_51 , NULL , V_12 -> V_54 ) ;
F_31 ( & V_50 , V_47 ) ;
F_49 ( V_12 -> V_55 ) ;
F_50 ( V_12 -> V_55 , NULL ) ;
F_46 ( V_12 ) ;
}
struct V_11 * F_51 ( unsigned int V_61 )
{
struct V_11 * V_12 ;
unsigned long V_47 ;
F_29 ( & V_50 , V_47 ) ;
V_12 = F_52 ( & V_51 , V_61 ) ;
if ( V_12 )
F_53 ( V_12 -> V_22 ) ;
F_31 ( & V_50 , V_47 ) ;
if ( ! V_12 ) {
return F_54 ( - V_62 ) ;
} else if ( F_55 ( V_12 -> V_22 ) ) {
F_56 ( V_12 -> V_22 ) ;
return F_54 ( - V_62 ) ;
}
return V_12 ;
}
void F_57 ( struct V_11 * V_12 )
{
F_56 ( V_12 -> V_22 ) ;
}
void F_58 ( struct V_21 * V_22 )
{
F_41 ( L_4 ) ;
if ( ! V_22 ) {
F_43 ( L_7 ) ;
return;
}
F_59 ( V_22 ) ;
F_56 ( V_22 ) ;
}
void F_60 ( struct V_21 * V_22 )
{
F_47 ( V_22 , V_41 ) ;
F_47 ( V_22 , V_43 ) ;
F_47 ( V_22 , V_45 ) ;
F_15 ( & V_63 ) ;
F_61 ( V_22 ) ;
if ( V_22 -> V_64 == 0 ) {
F_58 ( V_22 ) ;
}
F_18 ( & V_63 ) ;
}
static struct V_65 * F_62 ( struct V_66 * V_67 , int V_47 ,
const char * V_68 , void * V_31 )
{
return F_63 ( V_67 ,
L_8 ,
& V_69 ,
& V_70 ,
0x010203ff ) ;
}
static struct V_71 * F_64 ( void )
{
struct V_71 * V_71 ;
int V_48 ;
V_48 = F_65 ( & V_72 , & V_73 , & V_74 ) ;
if ( V_48 < 0 ) {
F_43 ( L_9 , V_48 ) ;
return F_54 ( V_48 ) ;
}
V_71 = F_66 ( V_73 -> V_75 ) ;
if ( F_34 ( V_71 ) )
F_67 ( & V_73 , & V_74 ) ;
return V_71 ;
}
static void F_68 ( struct V_71 * V_71 )
{
if ( V_71 ) {
F_69 ( V_71 ) ;
F_67 ( & V_73 , & V_74 ) ;
}
}
struct V_21 * F_70 ( struct V_76 * V_27 ,
struct V_77 * V_78 )
{
struct V_21 * V_22 ;
int V_34 ;
V_22 = F_6 ( sizeof( * V_22 ) , V_14 ) ;
if ( ! V_22 )
return NULL ;
F_7 ( & V_22 -> V_79 ) ;
V_22 -> V_22 = V_78 ;
V_22 -> V_27 = V_27 ;
F_71 ( & V_22 -> V_80 ) ;
F_71 ( & V_22 -> V_81 ) ;
F_71 ( & V_22 -> V_82 ) ;
F_71 ( & V_22 -> V_83 ) ;
F_71 ( & V_22 -> V_84 ) ;
F_8 ( & V_22 -> V_85 ) ;
F_8 ( & V_22 -> V_86 ) ;
F_72 ( & V_22 -> V_26 ) ;
F_72 ( & V_22 -> V_87 ) ;
F_72 ( & V_22 -> V_35 ) ;
V_22 -> V_88 = F_64 () ;
if ( F_34 ( V_22 -> V_88 ) ) {
V_34 = F_35 ( V_22 -> V_88 ) ;
F_43 ( L_10 , V_34 ) ;
goto V_53;
}
if ( F_73 ( V_22 , V_89 ) ) {
V_34 = F_27 ( V_22 , V_45 ) ;
if ( V_34 )
goto V_90;
}
if ( F_73 ( V_22 , V_91 ) ) {
V_34 = F_27 ( V_22 , V_43 ) ;
if ( V_34 )
goto V_90;
}
V_34 = F_27 ( V_22 , V_41 ) ;
if ( V_34 )
goto V_90;
if ( F_74 ( & V_22 -> V_92 , 12 ) )
goto V_90;
V_34 = F_75 ( V_22 ) ;
if ( V_34 ) {
F_43 ( L_11 ) ;
goto V_93;
}
if ( F_73 ( V_22 , V_94 ) ) {
V_34 = F_76 ( V_22 ) ;
if ( V_34 ) {
F_43 ( L_12 ) ;
goto V_95;
}
}
return V_22 ;
V_95:
F_77 ( V_22 ) ;
V_93:
F_78 ( & V_22 -> V_92 ) ;
V_90:
F_37 ( V_22 , V_41 ) ;
F_37 ( V_22 , V_43 ) ;
F_37 ( V_22 , V_45 ) ;
F_68 ( V_22 -> V_88 ) ;
V_53:
F_79 ( & V_22 -> V_35 ) ;
F_20 ( V_22 ) ;
return NULL ;
}
static void F_80 ( struct V_20 * V_79 )
{
struct V_21 * V_22 = F_14 ( V_79 , struct V_21 , V_79 ) ;
if ( F_73 ( V_22 , V_94 ) )
F_81 ( V_22 ) ;
F_77 ( V_22 ) ;
F_78 ( & V_22 -> V_92 ) ;
F_68 ( V_22 -> V_88 ) ;
F_37 ( V_22 , V_41 ) ;
F_37 ( V_22 , V_43 ) ;
F_37 ( V_22 , V_45 ) ;
F_79 ( & V_22 -> V_35 ) ;
F_20 ( V_22 -> V_30 ) ;
F_20 ( V_22 ) ;
}
void F_53 ( struct V_21 * V_22 )
{
if ( V_22 )
F_12 ( & V_22 -> V_79 ) ;
}
void F_56 ( struct V_21 * V_22 )
{
if ( V_22 )
F_22 ( & V_22 -> V_79 , F_80 ) ;
}
int F_82 ( struct V_21 * V_22 , unsigned long V_47 )
{
int V_34 ;
F_15 ( & V_63 ) ;
V_34 = F_40 ( V_22 , V_45 ) ;
if ( V_34 )
goto V_90;
V_34 = F_40 ( V_22 , V_43 ) ;
if ( V_34 )
goto V_90;
V_34 = F_40 ( V_22 , V_41 ) ;
if ( V_34 )
goto V_90;
if ( V_22 -> V_27 -> V_96 ) {
V_34 = V_22 -> V_27 -> V_96 ( V_22 , V_47 ) ;
if ( V_34 )
goto V_90;
}
if ( F_73 ( V_22 , V_89 ) ) {
V_34 = F_83 ( V_22 ,
& V_22 -> V_42 -> V_58 ) ;
if ( V_34 )
goto V_97;
}
V_34 = 0 ;
goto V_37;
V_97:
if ( V_22 -> V_27 -> V_98 )
V_22 -> V_27 -> V_98 ( V_22 ) ;
V_90:
F_47 ( V_22 , V_41 ) ;
F_47 ( V_22 , V_43 ) ;
F_47 ( V_22 , V_45 ) ;
V_37:
F_18 ( & V_63 ) ;
return V_34 ;
}
void F_59 ( struct V_21 * V_22 )
{
struct V_23 * V_24 , * V_25 ;
F_84 ( V_22 ) ;
if ( V_22 -> V_27 -> V_98 )
V_22 -> V_27 -> V_98 ( V_22 ) ;
if ( V_22 -> V_99 )
F_85 ( V_22 ) ;
F_86 ( V_22 ) ;
F_16 (r_list, list_temp, &dev->maplist, head)
F_87 ( V_22 , V_24 -> V_29 ) ;
F_47 ( V_22 , V_41 ) ;
F_47 ( V_22 , V_43 ) ;
F_47 ( V_22 , V_45 ) ;
}
int F_88 ( struct V_21 * V_22 , const char * V_4 , ... )
{
T_1 V_100 ;
F_20 ( V_22 -> V_30 ) ;
va_start ( V_100 , V_4 ) ;
V_22 -> V_30 = F_89 ( V_14 , V_4 , V_100 ) ;
va_end ( V_100 ) ;
return V_22 -> V_30 ? 0 : - V_49 ;
}
static int F_90 ( struct V_71 * V_71 , struct V_101 * V_102 )
{
const struct V_103 * V_104 ;
struct V_11 * V_12 ;
int V_105 ;
F_41 ( L_4 ) ;
F_15 ( & V_63 ) ;
V_12 = F_51 ( F_91 ( V_71 ) ) ;
if ( F_34 ( V_12 ) ) {
V_105 = F_35 ( V_12 ) ;
goto V_37;
}
V_104 = F_92 ( V_12 -> V_22 -> V_27 -> V_106 ) ;
if ( ! V_104 ) {
V_105 = - V_62 ;
goto V_107;
}
F_93 ( V_102 , V_104 ) ;
if ( V_102 -> V_108 -> V_109 )
V_105 = V_102 -> V_108 -> V_109 ( V_71 , V_102 ) ;
else
V_105 = 0 ;
V_107:
F_57 ( V_12 ) ;
V_37:
F_18 ( & V_63 ) ;
return V_105 ;
}
static int T_2 F_94 ( void )
{
int V_34 = - V_49 ;
F_95 () ;
F_96 () ;
F_10 ( & V_51 ) ;
if ( F_97 ( V_110 , L_13 , & V_111 ) )
goto V_112;
V_113 = F_98 ( V_114 , L_13 ) ;
if ( F_34 ( V_113 ) ) {
F_2 ( V_6 L_14 ) ;
V_34 = F_35 ( V_113 ) ;
goto V_115;
}
V_59 = F_99 ( L_15 , NULL ) ;
if ( ! V_59 ) {
F_43 ( L_16 ) ;
V_34 = - 1 ;
goto V_116;
}
F_100 ( L_17 ,
V_117 , V_118 , V_119 , V_120 , V_121 ) ;
return 0 ;
V_116:
F_101 () ;
V_115:
F_102 ( V_110 , L_13 ) ;
F_19 ( & V_51 ) ;
V_112:
return V_34 ;
}
static void T_3 F_103 ( void )
{
F_104 ( V_59 ) ;
F_101 () ;
F_102 ( V_110 , L_13 ) ;
F_105 () ;
F_19 ( & V_51 ) ;
}
