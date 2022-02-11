int F_1 ( const char * V_1 , const char * V_2 , ... )
{
struct V_3 V_4 ;
T_1 args ;
int V_5 ;
va_start ( args , V_2 ) ;
V_4 . V_6 = V_2 ;
V_4 . V_7 = & args ;
V_5 = F_2 ( V_8 L_1 V_9 L_2 , V_1 , & V_4 ) ;
va_end ( args ) ;
return V_5 ;
}
void F_3 ( const char * V_10 , const char * V_2 , ... )
{
struct V_3 V_4 ;
T_1 args ;
va_start ( args , V_2 ) ;
V_4 . V_6 = V_2 ;
V_4 . V_7 = & args ;
F_2 ( V_11 L_1 V_9 L_3 , V_10 , & V_4 ) ;
va_end ( args ) ;
}
struct V_12 * F_4 ( struct V_13 * V_14 )
{
struct V_12 * V_15 ;
V_15 = F_5 ( sizeof( * V_15 ) , V_16 ) ;
if ( ! V_15 )
return NULL ;
F_6 ( & V_15 -> V_17 ) ;
F_7 ( & V_15 -> V_18 . V_19 ) ;
F_8 ( & V_15 -> V_18 . V_20 ) ;
if ( F_9 ( & V_15 -> V_21 , V_22 ) ) {
F_10 ( V_15 ) ;
return NULL ;
}
F_11 ( & V_15 -> V_23 ) ;
V_15 -> V_14 = V_14 ;
return V_15 ;
}
struct V_12 * F_12 ( struct V_12 * V_15 )
{
F_13 ( & V_15 -> V_17 ) ;
return V_15 ;
}
static void F_14 ( struct V_24 * V_24 )
{
struct V_12 * V_15 = F_15 ( V_24 , struct V_12 , V_17 ) ;
struct V_25 * V_26 , * V_27 ;
struct V_28 * V_29 = V_15 -> V_14 -> V_29 ;
struct V_30 * V_31 , * V_32 ;
F_16 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_34 -> V_35 )
V_29 -> V_34 -> V_35 ( V_29 , V_15 ) ;
F_17 (r_list, list_temp, &dev->maplist, head) {
if ( V_31 -> V_15 == V_15 ) {
F_18 ( V_29 , V_31 -> V_36 ) ;
V_31 = NULL ;
}
}
if ( V_15 -> V_37 ) {
F_10 ( V_15 -> V_37 ) ;
V_15 -> V_37 = NULL ;
V_15 -> V_38 = 0 ;
}
F_17 (pt, next, &master->magicfree, head) {
F_19 ( & V_26 -> V_39 ) ;
F_20 ( & V_15 -> V_21 , & V_26 -> V_40 ) ;
F_10 ( V_26 ) ;
}
F_21 ( & V_15 -> V_21 ) ;
F_22 ( & V_29 -> V_33 ) ;
F_10 ( V_15 ) ;
}
void F_23 ( struct V_12 * * V_15 )
{
F_24 ( & ( * V_15 ) -> V_17 , F_14 ) ;
* V_15 = NULL ;
}
int F_25 ( struct V_28 * V_29 , void * V_41 ,
struct V_42 * V_43 )
{
int V_44 = 0 ;
F_16 ( & V_29 -> V_45 ) ;
if ( V_43 -> V_46 )
goto V_47;
if ( V_43 -> V_14 -> V_15 ) {
V_44 = - V_48 ;
goto V_47;
}
if ( ! V_43 -> V_15 ) {
V_44 = - V_48 ;
goto V_47;
}
V_43 -> V_14 -> V_15 = F_12 ( V_43 -> V_15 ) ;
V_43 -> V_46 = 1 ;
if ( V_29 -> V_34 -> V_49 ) {
V_44 = V_29 -> V_34 -> V_49 ( V_29 , V_43 , false ) ;
if ( F_26 ( V_44 != 0 ) ) {
V_43 -> V_46 = 0 ;
F_23 ( & V_43 -> V_14 -> V_15 ) ;
}
}
V_47:
F_22 ( & V_29 -> V_45 ) ;
return V_44 ;
}
int F_27 ( struct V_28 * V_29 , void * V_41 ,
struct V_42 * V_43 )
{
int V_44 = - V_48 ;
F_16 ( & V_29 -> V_45 ) ;
if ( ! V_43 -> V_46 )
goto V_47;
if ( ! V_43 -> V_14 -> V_15 )
goto V_47;
V_44 = 0 ;
if ( V_29 -> V_34 -> V_50 )
V_29 -> V_34 -> V_50 ( V_29 , V_43 , false ) ;
F_23 ( & V_43 -> V_14 -> V_15 ) ;
V_43 -> V_46 = 0 ;
V_47:
F_22 ( & V_29 -> V_45 ) ;
return V_44 ;
}
static struct V_13 * * F_28 ( struct V_28 * V_29 ,
unsigned int type )
{
switch ( type ) {
case V_51 :
return & V_29 -> V_52 ;
case V_53 :
return & V_29 -> V_54 ;
case V_55 :
return & V_29 -> V_56 ;
default:
return NULL ;
}
}
static int F_29 ( struct V_28 * V_29 , unsigned int type )
{
struct V_13 * V_14 ;
unsigned long V_57 ;
int V_5 ;
V_14 = F_5 ( sizeof( * V_14 ) , V_16 ) ;
if ( ! V_14 )
return - V_58 ;
V_14 -> type = type ;
V_14 -> V_29 = V_29 ;
F_30 ( V_16 ) ;
F_31 ( & V_59 , V_57 ) ;
V_5 = F_32 ( & V_60 ,
NULL ,
64 * type ,
64 * ( type + 1 ) ,
V_61 ) ;
F_33 ( & V_59 , V_57 ) ;
F_34 () ;
if ( V_5 < 0 )
goto V_62;
V_14 -> V_63 = V_5 ;
V_14 -> V_64 = F_35 ( V_14 ) ;
if ( F_36 ( V_14 -> V_64 ) ) {
V_5 = F_37 ( V_14 -> V_64 ) ;
goto V_65;
}
* F_28 ( V_29 , type ) = V_14 ;
return 0 ;
V_65:
F_31 ( & V_59 , V_57 ) ;
F_38 ( & V_60 , V_14 -> V_63 ) ;
F_33 ( & V_59 , V_57 ) ;
V_62:
F_10 ( V_14 ) ;
return V_5 ;
}
static void F_39 ( struct V_28 * V_29 , unsigned int type )
{
struct V_13 * * V_66 , * V_14 ;
unsigned long V_57 ;
V_66 = F_28 ( V_29 , type ) ;
V_14 = * V_66 ;
if ( ! V_14 )
return;
F_40 ( & V_14 -> V_67 ) ;
F_41 ( V_14 -> V_64 ) ;
F_31 ( & V_59 , V_57 ) ;
F_38 ( & V_60 , V_14 -> V_63 ) ;
F_33 ( & V_59 , V_57 ) ;
F_10 ( V_14 ) ;
* V_66 = NULL ;
}
static int F_42 ( struct V_28 * V_29 , unsigned int type )
{
struct V_13 * V_14 ;
unsigned long V_57 ;
int V_44 ;
F_43 ( L_4 ) ;
V_14 = * F_28 ( V_29 , type ) ;
if ( ! V_14 )
return 0 ;
V_44 = F_44 ( V_14 , V_14 -> V_63 , V_68 ) ;
if ( V_44 ) {
F_45 ( L_5 ) ;
return V_44 ;
}
V_44 = F_46 ( V_14 -> V_64 ) ;
if ( V_44 )
goto V_69;
F_31 ( & V_59 , V_57 ) ;
F_47 ( & V_60 , V_14 , V_14 -> V_63 ) ;
F_33 ( & V_59 , V_57 ) ;
F_43 ( L_6 , V_14 -> V_63 ) ;
return 0 ;
V_69:
F_48 ( V_14 ) ;
return V_44 ;
}
static void F_49 ( struct V_28 * V_29 , unsigned int type )
{
struct V_13 * V_14 ;
unsigned long V_57 ;
V_14 = * F_28 ( V_29 , type ) ;
if ( ! V_14 || ! F_50 ( V_14 -> V_64 ) )
return;
F_31 ( & V_59 , V_57 ) ;
F_47 ( & V_60 , NULL , V_14 -> V_63 ) ;
F_33 ( & V_59 , V_57 ) ;
F_51 ( V_14 -> V_64 ) ;
F_52 ( V_14 -> V_64 , NULL ) ;
F_48 ( V_14 ) ;
}
struct V_13 * F_53 ( unsigned int V_70 )
{
struct V_13 * V_14 ;
unsigned long V_57 ;
F_31 ( & V_59 , V_57 ) ;
V_14 = F_54 ( & V_60 , V_70 ) ;
if ( V_14 )
F_55 ( V_14 -> V_29 ) ;
F_33 ( & V_59 , V_57 ) ;
if ( ! V_14 ) {
return F_56 ( - V_71 ) ;
} else if ( F_57 ( V_14 -> V_29 ) ) {
F_58 ( V_14 -> V_29 ) ;
return F_56 ( - V_71 ) ;
}
return V_14 ;
}
void F_59 ( struct V_13 * V_14 )
{
F_58 ( V_14 -> V_29 ) ;
}
void F_60 ( struct V_28 * V_29 )
{
F_43 ( L_4 ) ;
if ( ! V_29 ) {
F_45 ( L_7 ) ;
return;
}
F_61 ( V_29 ) ;
F_58 ( V_29 ) ;
}
void F_62 ( struct V_28 * V_29 )
{
F_49 ( V_29 , V_51 ) ;
F_49 ( V_29 , V_53 ) ;
F_49 ( V_29 , V_55 ) ;
F_16 ( & V_72 ) ;
F_63 ( V_29 ) ;
if ( V_29 -> V_73 == 0 ) {
F_60 ( V_29 ) ;
}
F_22 ( & V_72 ) ;
}
static struct V_74 * F_64 ( struct V_75 * V_76 , int V_57 ,
const char * V_77 , void * V_41 )
{
return F_65 ( V_76 ,
L_8 ,
& V_78 ,
& V_79 ,
0x010203ff ) ;
}
static struct V_80 * F_66 ( void )
{
struct V_80 * V_80 ;
int V_5 ;
V_5 = F_67 ( & V_81 , & V_82 , & V_83 ) ;
if ( V_5 < 0 ) {
F_45 ( L_9 , V_5 ) ;
return F_56 ( V_5 ) ;
}
V_80 = F_68 ( V_82 -> V_84 ) ;
if ( F_36 ( V_80 ) )
F_69 ( & V_82 , & V_83 ) ;
return V_80 ;
}
static void F_70 ( struct V_80 * V_80 )
{
if ( V_80 ) {
F_71 ( V_80 ) ;
F_69 ( & V_82 , & V_83 ) ;
}
}
struct V_28 * F_72 ( struct V_85 * V_34 ,
struct V_86 * V_87 )
{
struct V_28 * V_29 ;
int V_44 ;
V_29 = F_5 ( sizeof( * V_29 ) , V_16 ) ;
if ( ! V_29 )
return NULL ;
F_6 ( & V_29 -> V_88 ) ;
V_29 -> V_29 = V_87 ;
V_29 -> V_34 = V_34 ;
F_11 ( & V_29 -> V_89 ) ;
F_11 ( & V_29 -> V_90 ) ;
F_11 ( & V_29 -> V_91 ) ;
F_11 ( & V_29 -> V_92 ) ;
F_11 ( & V_29 -> V_93 ) ;
F_7 ( & V_29 -> V_94 ) ;
F_7 ( & V_29 -> V_95 ) ;
F_73 ( & V_29 -> V_33 ) ;
F_73 ( & V_29 -> V_96 ) ;
F_73 ( & V_29 -> V_45 ) ;
V_29 -> V_97 = F_66 () ;
if ( F_36 ( V_29 -> V_97 ) ) {
V_44 = F_37 ( V_29 -> V_97 ) ;
F_45 ( L_10 , V_44 ) ;
goto V_62;
}
if ( F_74 ( V_29 , V_98 ) ) {
V_44 = F_29 ( V_29 , V_55 ) ;
if ( V_44 )
goto V_99;
}
if ( F_74 ( V_29 , V_100 ) ) {
V_44 = F_29 ( V_29 , V_53 ) ;
if ( V_44 )
goto V_99;
}
V_44 = F_29 ( V_29 , V_51 ) ;
if ( V_44 )
goto V_99;
if ( F_9 ( & V_29 -> V_101 , 12 ) )
goto V_99;
V_44 = F_75 ( V_29 ) ;
if ( V_44 ) {
F_45 ( L_11 ) ;
goto V_102;
}
if ( V_34 -> V_103 & V_104 ) {
V_44 = F_76 ( V_29 ) ;
if ( V_44 ) {
F_45 ( L_12 ) ;
goto V_105;
}
}
return V_29 ;
V_105:
F_77 ( V_29 ) ;
V_102:
F_21 ( & V_29 -> V_101 ) ;
V_99:
F_39 ( V_29 , V_51 ) ;
F_39 ( V_29 , V_53 ) ;
F_39 ( V_29 , V_55 ) ;
F_70 ( V_29 -> V_97 ) ;
V_62:
F_78 ( & V_29 -> V_45 ) ;
F_10 ( V_29 ) ;
return NULL ;
}
static void F_79 ( struct V_24 * V_88 )
{
struct V_28 * V_29 = F_15 ( V_88 , struct V_28 , V_88 ) ;
if ( V_29 -> V_34 -> V_103 & V_104 )
F_80 ( V_29 ) ;
F_77 ( V_29 ) ;
F_21 ( & V_29 -> V_101 ) ;
F_70 ( V_29 -> V_97 ) ;
F_39 ( V_29 , V_51 ) ;
F_39 ( V_29 , V_53 ) ;
F_39 ( V_29 , V_55 ) ;
F_78 ( & V_29 -> V_45 ) ;
F_10 ( V_29 -> V_37 ) ;
F_10 ( V_29 ) ;
}
void F_55 ( struct V_28 * V_29 )
{
if ( V_29 )
F_13 ( & V_29 -> V_88 ) ;
}
void F_58 ( struct V_28 * V_29 )
{
if ( V_29 )
F_24 ( & V_29 -> V_88 , F_79 ) ;
}
int F_81 ( struct V_28 * V_29 , unsigned long V_57 )
{
int V_44 ;
F_16 ( & V_72 ) ;
V_44 = F_42 ( V_29 , V_55 ) ;
if ( V_44 )
goto V_99;
V_44 = F_42 ( V_29 , V_53 ) ;
if ( V_44 )
goto V_99;
V_44 = F_42 ( V_29 , V_51 ) ;
if ( V_44 )
goto V_99;
if ( V_29 -> V_34 -> V_106 ) {
V_44 = V_29 -> V_34 -> V_106 ( V_29 , V_57 ) ;
if ( V_44 )
goto V_99;
}
if ( F_74 ( V_29 , V_98 ) ) {
V_44 = F_82 ( V_29 ,
& V_29 -> V_52 -> V_67 ) ;
if ( V_44 )
goto V_107;
}
V_44 = 0 ;
goto V_47;
V_107:
if ( V_29 -> V_34 -> V_108 )
V_29 -> V_34 -> V_108 ( V_29 ) ;
V_99:
F_49 ( V_29 , V_51 ) ;
F_49 ( V_29 , V_53 ) ;
F_49 ( V_29 , V_55 ) ;
V_47:
F_22 ( & V_72 ) ;
return V_44 ;
}
void F_61 ( struct V_28 * V_29 )
{
struct V_30 * V_31 , * V_32 ;
F_83 ( V_29 ) ;
if ( V_29 -> V_34 -> V_108 )
V_29 -> V_34 -> V_108 ( V_29 ) ;
if ( V_29 -> V_109 )
F_84 ( V_29 ) ;
F_85 ( V_29 ) ;
F_17 (r_list, list_temp, &dev->maplist, head)
F_86 ( V_29 , V_31 -> V_36 ) ;
F_49 ( V_29 , V_51 ) ;
F_49 ( V_29 , V_53 ) ;
F_49 ( V_29 , V_55 ) ;
}
int F_87 ( struct V_28 * V_29 , const char * V_6 , ... )
{
T_1 V_110 ;
F_10 ( V_29 -> V_37 ) ;
va_start ( V_110 , V_6 ) ;
V_29 -> V_37 = F_88 ( V_16 , V_6 , V_110 ) ;
va_end ( V_110 ) ;
return V_29 -> V_37 ? 0 : - V_58 ;
}
static int F_89 ( struct V_80 * V_80 , struct V_111 * V_112 )
{
const struct V_113 * V_114 ;
struct V_13 * V_14 ;
int V_115 ;
F_43 ( L_4 ) ;
F_16 ( & V_72 ) ;
V_14 = F_53 ( F_90 ( V_80 ) ) ;
if ( F_36 ( V_14 ) ) {
V_115 = F_37 ( V_14 ) ;
goto V_47;
}
V_114 = F_91 ( V_14 -> V_29 -> V_34 -> V_116 ) ;
if ( ! V_114 ) {
V_115 = - V_71 ;
goto V_117;
}
F_92 ( V_112 , V_114 ) ;
if ( V_112 -> V_118 -> V_119 )
V_115 = V_112 -> V_118 -> V_119 ( V_80 , V_112 ) ;
else
V_115 = 0 ;
V_117:
F_59 ( V_14 ) ;
V_47:
F_22 ( & V_72 ) ;
return V_115 ;
}
static int T_2 F_93 ( void )
{
int V_44 = - V_58 ;
F_94 () ;
F_95 () ;
F_96 ( & V_60 ) ;
if ( F_97 ( V_120 , L_13 , & V_121 ) )
goto V_122;
V_123 = F_98 ( V_124 , L_13 ) ;
if ( F_36 ( V_123 ) ) {
F_2 ( V_8 L_14 ) ;
V_44 = F_37 ( V_123 ) ;
goto V_125;
}
V_68 = F_99 ( L_15 , NULL ) ;
if ( ! V_68 ) {
F_45 ( L_16 ) ;
V_44 = - 1 ;
goto V_126;
}
F_100 ( L_17 ,
V_127 , V_128 , V_129 , V_130 , V_131 ) ;
return 0 ;
V_126:
F_101 () ;
V_125:
F_102 ( V_120 , L_13 ) ;
F_103 ( & V_60 ) ;
V_122:
return V_44 ;
}
static void T_3 F_104 ( void )
{
F_105 ( V_68 ) ;
F_101 () ;
F_102 ( V_120 , L_13 ) ;
F_106 () ;
F_103 ( & V_60 ) ;
}
