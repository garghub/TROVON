void F_1 ( const char * V_1 , const char * V_2 , ... )
{
struct V_3 V_4 ;
T_1 args ;
va_start ( args , V_2 ) ;
V_4 . V_5 = V_2 ;
V_4 . V_6 = & args ;
F_2 ( V_7 L_1 V_8 L_2 , V_1 , & V_4 ) ;
va_end ( args ) ;
}
void F_3 ( const char * V_9 , const char * V_2 , ... )
{
struct V_3 V_4 ;
T_1 args ;
va_start ( args , V_2 ) ;
V_4 . V_5 = V_2 ;
V_4 . V_6 = & args ;
F_2 ( V_10 L_1 V_8 L_3 , V_9 , & V_4 ) ;
va_end ( args ) ;
}
struct V_11 * F_4 ( struct V_12 * V_13 )
{
struct V_11 * V_14 ;
V_14 = F_5 ( sizeof( * V_14 ) , V_15 ) ;
if ( ! V_14 )
return NULL ;
F_6 ( & V_14 -> V_16 ) ;
F_7 ( & V_14 -> V_17 . V_18 ) ;
F_8 ( & V_14 -> V_17 . V_19 ) ;
if ( F_9 ( & V_14 -> V_20 , V_21 ) ) {
F_10 ( V_14 ) ;
return NULL ;
}
F_11 ( & V_14 -> V_22 ) ;
V_14 -> V_13 = V_13 ;
return V_14 ;
}
struct V_11 * F_12 ( struct V_11 * V_14 )
{
F_13 ( & V_14 -> V_16 ) ;
return V_14 ;
}
static void F_14 ( struct V_23 * V_23 )
{
struct V_11 * V_14 = F_15 ( V_23 , struct V_11 , V_16 ) ;
struct V_24 * V_25 = V_14 -> V_13 -> V_25 ;
struct V_26 * V_27 , * V_28 ;
F_16 ( & V_25 -> V_29 ) ;
if ( V_25 -> V_30 -> V_31 )
V_25 -> V_30 -> V_31 ( V_25 , V_14 ) ;
F_17 (r_list, list_temp, &dev->maplist, head) {
if ( V_27 -> V_14 == V_14 ) {
F_18 ( V_25 , V_27 -> V_32 ) ;
V_27 = NULL ;
}
}
if ( V_14 -> V_33 ) {
F_10 ( V_14 -> V_33 ) ;
V_14 -> V_33 = NULL ;
V_14 -> V_34 = 0 ;
}
F_19 ( & V_14 -> V_20 ) ;
F_20 ( & V_25 -> V_29 ) ;
F_10 ( V_14 ) ;
}
void F_21 ( struct V_11 * * V_14 )
{
F_22 ( & ( * V_14 ) -> V_16 , F_14 ) ;
* V_14 = NULL ;
}
int F_23 ( struct V_24 * V_25 , void * V_35 ,
struct V_36 * V_37 )
{
int V_38 = 0 ;
F_16 ( & V_25 -> V_39 ) ;
if ( V_37 -> V_40 )
goto V_41;
if ( V_37 -> V_13 -> V_14 ) {
V_38 = - V_42 ;
goto V_41;
}
if ( ! V_37 -> V_14 ) {
V_38 = - V_42 ;
goto V_41;
}
V_37 -> V_13 -> V_14 = F_12 ( V_37 -> V_14 ) ;
V_37 -> V_40 = 1 ;
if ( V_25 -> V_30 -> V_43 ) {
V_38 = V_25 -> V_30 -> V_43 ( V_25 , V_37 , false ) ;
if ( F_24 ( V_38 != 0 ) ) {
V_37 -> V_40 = 0 ;
F_21 ( & V_37 -> V_13 -> V_14 ) ;
}
}
V_41:
F_20 ( & V_25 -> V_39 ) ;
return V_38 ;
}
int F_25 ( struct V_24 * V_25 , void * V_35 ,
struct V_36 * V_37 )
{
int V_38 = - V_42 ;
F_16 ( & V_25 -> V_39 ) ;
if ( ! V_37 -> V_40 )
goto V_41;
if ( ! V_37 -> V_13 -> V_14 )
goto V_41;
V_38 = 0 ;
if ( V_25 -> V_30 -> V_44 )
V_25 -> V_30 -> V_44 ( V_25 , V_37 , false ) ;
F_21 ( & V_37 -> V_13 -> V_14 ) ;
V_37 -> V_40 = 0 ;
V_41:
F_20 ( & V_25 -> V_39 ) ;
return V_38 ;
}
static struct V_12 * * F_26 ( struct V_24 * V_25 ,
unsigned int type )
{
switch ( type ) {
case V_45 :
return & V_25 -> V_46 ;
case V_47 :
return & V_25 -> V_48 ;
case V_49 :
return & V_25 -> V_50 ;
default:
return NULL ;
}
}
static int F_27 ( struct V_24 * V_25 , unsigned int type )
{
struct V_12 * V_13 ;
unsigned long V_51 ;
int V_52 ;
V_13 = F_5 ( sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 )
return - V_53 ;
V_13 -> type = type ;
V_13 -> V_25 = V_25 ;
F_28 ( V_15 ) ;
F_29 ( & V_54 , V_51 ) ;
V_52 = F_30 ( & V_55 ,
NULL ,
64 * type ,
64 * ( type + 1 ) ,
V_56 ) ;
F_31 ( & V_54 , V_51 ) ;
F_32 () ;
if ( V_52 < 0 )
goto V_57;
V_13 -> V_58 = V_52 ;
V_13 -> V_59 = F_33 ( V_13 ) ;
if ( F_34 ( V_13 -> V_59 ) ) {
V_52 = F_35 ( V_13 -> V_59 ) ;
goto V_60;
}
* F_26 ( V_25 , type ) = V_13 ;
return 0 ;
V_60:
F_29 ( & V_54 , V_51 ) ;
F_36 ( & V_55 , V_13 -> V_58 ) ;
F_31 ( & V_54 , V_51 ) ;
V_57:
F_10 ( V_13 ) ;
return V_52 ;
}
static void F_37 ( struct V_24 * V_25 , unsigned int type )
{
struct V_12 * * V_61 , * V_13 ;
unsigned long V_51 ;
V_61 = F_26 ( V_25 , type ) ;
V_13 = * V_61 ;
if ( ! V_13 )
return;
F_38 ( & V_13 -> V_62 ) ;
F_39 ( V_13 -> V_59 ) ;
F_29 ( & V_54 , V_51 ) ;
F_36 ( & V_55 , V_13 -> V_58 ) ;
F_31 ( & V_54 , V_51 ) ;
F_10 ( V_13 ) ;
* V_61 = NULL ;
}
static int F_40 ( struct V_24 * V_25 , unsigned int type )
{
struct V_12 * V_13 ;
unsigned long V_51 ;
int V_38 ;
F_41 ( L_4 ) ;
V_13 = * F_26 ( V_25 , type ) ;
if ( ! V_13 )
return 0 ;
V_38 = F_42 ( V_13 , V_13 -> V_58 , V_63 ) ;
if ( V_38 ) {
F_43 ( L_5 ) ;
return V_38 ;
}
V_38 = F_44 ( V_13 -> V_59 ) ;
if ( V_38 )
goto V_64;
F_29 ( & V_54 , V_51 ) ;
F_45 ( & V_55 , V_13 , V_13 -> V_58 ) ;
F_31 ( & V_54 , V_51 ) ;
F_41 ( L_6 , V_13 -> V_58 ) ;
return 0 ;
V_64:
F_46 ( V_13 ) ;
return V_38 ;
}
static void F_47 ( struct V_24 * V_25 , unsigned int type )
{
struct V_12 * V_13 ;
unsigned long V_51 ;
V_13 = * F_26 ( V_25 , type ) ;
if ( ! V_13 || ! F_48 ( V_13 -> V_59 ) )
return;
F_29 ( & V_54 , V_51 ) ;
F_45 ( & V_55 , NULL , V_13 -> V_58 ) ;
F_31 ( & V_54 , V_51 ) ;
F_49 ( V_13 -> V_59 ) ;
F_50 ( V_13 -> V_59 , NULL ) ;
F_46 ( V_13 ) ;
}
struct V_12 * F_51 ( unsigned int V_65 )
{
struct V_12 * V_13 ;
unsigned long V_51 ;
F_29 ( & V_54 , V_51 ) ;
V_13 = F_52 ( & V_55 , V_65 ) ;
if ( V_13 )
F_53 ( V_13 -> V_25 ) ;
F_31 ( & V_54 , V_51 ) ;
if ( ! V_13 ) {
return F_54 ( - V_66 ) ;
} else if ( F_55 ( V_13 -> V_25 ) ) {
F_56 ( V_13 -> V_25 ) ;
return F_54 ( - V_66 ) ;
}
return V_13 ;
}
void F_57 ( struct V_12 * V_13 )
{
F_56 ( V_13 -> V_25 ) ;
}
void F_58 ( struct V_24 * V_25 )
{
F_41 ( L_4 ) ;
if ( ! V_25 ) {
F_43 ( L_7 ) ;
return;
}
F_59 ( V_25 ) ;
F_56 ( V_25 ) ;
}
void F_60 ( struct V_24 * V_25 )
{
F_47 ( V_25 , V_45 ) ;
F_47 ( V_25 , V_47 ) ;
F_47 ( V_25 , V_49 ) ;
F_16 ( & V_67 ) ;
F_61 ( V_25 ) ;
if ( V_25 -> V_68 == 0 ) {
F_58 ( V_25 ) ;
}
F_20 ( & V_67 ) ;
}
static struct V_69 * F_62 ( struct V_70 * V_71 , int V_51 ,
const char * V_72 , void * V_35 )
{
return F_63 ( V_71 ,
L_8 ,
& V_73 ,
& V_74 ,
0x010203ff ) ;
}
static struct V_75 * F_64 ( void )
{
struct V_75 * V_75 ;
int V_52 ;
V_52 = F_65 ( & V_76 , & V_77 , & V_78 ) ;
if ( V_52 < 0 ) {
F_43 ( L_9 , V_52 ) ;
return F_54 ( V_52 ) ;
}
V_75 = F_66 ( V_77 -> V_79 ) ;
if ( F_34 ( V_75 ) )
F_67 ( & V_77 , & V_78 ) ;
return V_75 ;
}
static void F_68 ( struct V_75 * V_75 )
{
if ( V_75 ) {
F_69 ( V_75 ) ;
F_67 ( & V_77 , & V_78 ) ;
}
}
struct V_24 * F_70 ( struct V_80 * V_30 ,
struct V_81 * V_82 )
{
struct V_24 * V_25 ;
int V_38 ;
V_25 = F_5 ( sizeof( * V_25 ) , V_15 ) ;
if ( ! V_25 )
return NULL ;
F_6 ( & V_25 -> V_83 ) ;
V_25 -> V_25 = V_82 ;
V_25 -> V_30 = V_30 ;
F_11 ( & V_25 -> V_84 ) ;
F_11 ( & V_25 -> V_85 ) ;
F_11 ( & V_25 -> V_86 ) ;
F_11 ( & V_25 -> V_87 ) ;
F_11 ( & V_25 -> V_88 ) ;
F_7 ( & V_25 -> V_89 ) ;
F_7 ( & V_25 -> V_90 ) ;
F_71 ( & V_25 -> V_29 ) ;
F_71 ( & V_25 -> V_91 ) ;
F_71 ( & V_25 -> V_39 ) ;
V_25 -> V_92 = F_64 () ;
if ( F_34 ( V_25 -> V_92 ) ) {
V_38 = F_35 ( V_25 -> V_92 ) ;
F_43 ( L_10 , V_38 ) ;
goto V_57;
}
if ( F_72 ( V_25 , V_93 ) ) {
V_38 = F_27 ( V_25 , V_49 ) ;
if ( V_38 )
goto V_94;
}
if ( F_72 ( V_25 , V_95 ) ) {
V_38 = F_27 ( V_25 , V_47 ) ;
if ( V_38 )
goto V_94;
}
V_38 = F_27 ( V_25 , V_45 ) ;
if ( V_38 )
goto V_94;
if ( F_9 ( & V_25 -> V_96 , 12 ) )
goto V_94;
V_38 = F_73 ( V_25 ) ;
if ( V_38 ) {
F_43 ( L_11 ) ;
goto V_97;
}
if ( F_72 ( V_25 , V_98 ) ) {
V_38 = F_74 ( V_25 ) ;
if ( V_38 ) {
F_43 ( L_12 ) ;
goto V_99;
}
}
return V_25 ;
V_99:
F_75 ( V_25 ) ;
V_97:
F_19 ( & V_25 -> V_96 ) ;
V_94:
F_37 ( V_25 , V_45 ) ;
F_37 ( V_25 , V_47 ) ;
F_37 ( V_25 , V_49 ) ;
F_68 ( V_25 -> V_92 ) ;
V_57:
F_76 ( & V_25 -> V_39 ) ;
F_10 ( V_25 ) ;
return NULL ;
}
static void F_77 ( struct V_23 * V_83 )
{
struct V_24 * V_25 = F_15 ( V_83 , struct V_24 , V_83 ) ;
if ( F_72 ( V_25 , V_98 ) )
F_78 ( V_25 ) ;
F_75 ( V_25 ) ;
F_19 ( & V_25 -> V_96 ) ;
F_68 ( V_25 -> V_92 ) ;
F_37 ( V_25 , V_45 ) ;
F_37 ( V_25 , V_47 ) ;
F_37 ( V_25 , V_49 ) ;
F_76 ( & V_25 -> V_39 ) ;
F_10 ( V_25 -> V_33 ) ;
F_10 ( V_25 ) ;
}
void F_53 ( struct V_24 * V_25 )
{
if ( V_25 )
F_13 ( & V_25 -> V_83 ) ;
}
void F_56 ( struct V_24 * V_25 )
{
if ( V_25 )
F_22 ( & V_25 -> V_83 , F_77 ) ;
}
int F_79 ( struct V_24 * V_25 , unsigned long V_51 )
{
int V_38 ;
F_16 ( & V_67 ) ;
V_38 = F_40 ( V_25 , V_49 ) ;
if ( V_38 )
goto V_94;
V_38 = F_40 ( V_25 , V_47 ) ;
if ( V_38 )
goto V_94;
V_38 = F_40 ( V_25 , V_45 ) ;
if ( V_38 )
goto V_94;
if ( V_25 -> V_30 -> V_100 ) {
V_38 = V_25 -> V_30 -> V_100 ( V_25 , V_51 ) ;
if ( V_38 )
goto V_94;
}
if ( F_72 ( V_25 , V_93 ) ) {
V_38 = F_80 ( V_25 ,
& V_25 -> V_46 -> V_62 ) ;
if ( V_38 )
goto V_101;
}
V_38 = 0 ;
goto V_41;
V_101:
if ( V_25 -> V_30 -> V_102 )
V_25 -> V_30 -> V_102 ( V_25 ) ;
V_94:
F_47 ( V_25 , V_45 ) ;
F_47 ( V_25 , V_47 ) ;
F_47 ( V_25 , V_49 ) ;
V_41:
F_20 ( & V_67 ) ;
return V_38 ;
}
void F_59 ( struct V_24 * V_25 )
{
struct V_26 * V_27 , * V_28 ;
F_81 ( V_25 ) ;
if ( V_25 -> V_30 -> V_102 )
V_25 -> V_30 -> V_102 ( V_25 ) ;
if ( V_25 -> V_103 )
F_82 ( V_25 ) ;
F_83 ( V_25 ) ;
F_17 (r_list, list_temp, &dev->maplist, head)
F_84 ( V_25 , V_27 -> V_32 ) ;
F_47 ( V_25 , V_45 ) ;
F_47 ( V_25 , V_47 ) ;
F_47 ( V_25 , V_49 ) ;
}
int F_85 ( struct V_24 * V_25 , const char * V_5 , ... )
{
T_1 V_104 ;
F_10 ( V_25 -> V_33 ) ;
va_start ( V_104 , V_5 ) ;
V_25 -> V_33 = F_86 ( V_15 , V_5 , V_104 ) ;
va_end ( V_104 ) ;
return V_25 -> V_33 ? 0 : - V_53 ;
}
static int F_87 ( struct V_75 * V_75 , struct V_105 * V_106 )
{
const struct V_107 * V_108 ;
struct V_12 * V_13 ;
int V_109 ;
F_41 ( L_4 ) ;
F_16 ( & V_67 ) ;
V_13 = F_51 ( F_88 ( V_75 ) ) ;
if ( F_34 ( V_13 ) ) {
V_109 = F_35 ( V_13 ) ;
goto V_41;
}
V_108 = F_89 ( V_13 -> V_25 -> V_30 -> V_110 ) ;
if ( ! V_108 ) {
V_109 = - V_66 ;
goto V_111;
}
F_90 ( V_106 , V_108 ) ;
if ( V_106 -> V_112 -> V_113 )
V_109 = V_106 -> V_112 -> V_113 ( V_75 , V_106 ) ;
else
V_109 = 0 ;
V_111:
F_57 ( V_13 ) ;
V_41:
F_20 ( & V_67 ) ;
return V_109 ;
}
static int T_2 F_91 ( void )
{
int V_38 = - V_53 ;
F_92 () ;
F_93 () ;
F_94 ( & V_55 ) ;
if ( F_95 ( V_114 , L_13 , & V_115 ) )
goto V_116;
V_117 = F_96 ( V_118 , L_13 ) ;
if ( F_34 ( V_117 ) ) {
F_2 ( V_7 L_14 ) ;
V_38 = F_35 ( V_117 ) ;
goto V_119;
}
V_63 = F_97 ( L_15 , NULL ) ;
if ( ! V_63 ) {
F_43 ( L_16 ) ;
V_38 = - 1 ;
goto V_120;
}
F_98 ( L_17 ,
V_121 , V_122 , V_123 , V_124 , V_125 ) ;
return 0 ;
V_120:
F_99 () ;
V_119:
F_100 ( V_114 , L_13 ) ;
F_101 ( & V_55 ) ;
V_116:
return V_38 ;
}
static void T_3 F_102 ( void )
{
F_103 ( V_63 ) ;
F_99 () ;
F_100 ( V_114 , L_13 ) ;
F_104 () ;
F_101 ( & V_55 ) ;
}
