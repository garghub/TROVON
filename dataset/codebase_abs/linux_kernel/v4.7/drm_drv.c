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
if ( V_22 -> V_23 -> V_24 )
V_22 -> V_23 -> V_24 ( V_22 , V_13 ) ;
F_15 ( V_22 , V_13 ) ;
F_16 ( & V_13 -> V_19 ) ;
F_17 ( V_13 -> V_25 ) ;
F_17 ( V_13 ) ;
}
void F_18 ( struct V_10 * * V_13 )
{
F_19 ( & ( * V_13 ) -> V_15 , F_13 ) ;
* V_13 = NULL ;
}
int F_20 ( struct V_21 * V_22 , void * V_26 ,
struct V_27 * V_28 )
{
int V_29 = 0 ;
F_21 ( & V_22 -> V_30 ) ;
if ( V_28 -> V_31 )
goto V_32;
if ( V_28 -> V_12 -> V_13 ) {
V_29 = - V_33 ;
goto V_32;
}
if ( ! V_28 -> V_13 ) {
V_29 = - V_33 ;
goto V_32;
}
if ( ! V_28 -> V_34 ) {
V_29 = F_22 ( V_22 , V_28 ) ;
goto V_32;
}
V_28 -> V_12 -> V_13 = F_11 ( V_28 -> V_13 ) ;
V_28 -> V_31 = 1 ;
if ( V_22 -> V_23 -> V_35 ) {
V_29 = V_22 -> V_23 -> V_35 ( V_22 , V_28 , false ) ;
if ( F_23 ( V_29 != 0 ) ) {
V_28 -> V_31 = 0 ;
F_18 ( & V_28 -> V_12 -> V_13 ) ;
}
}
V_32:
F_24 ( & V_22 -> V_30 ) ;
return V_29 ;
}
int F_25 ( struct V_21 * V_22 , void * V_26 ,
struct V_27 * V_28 )
{
int V_29 = - V_33 ;
F_21 ( & V_22 -> V_30 ) ;
if ( ! V_28 -> V_31 )
goto V_32;
if ( ! V_28 -> V_12 -> V_13 )
goto V_32;
V_29 = 0 ;
if ( V_22 -> V_23 -> V_36 )
V_22 -> V_23 -> V_36 ( V_22 , V_28 , false ) ;
F_18 ( & V_28 -> V_12 -> V_13 ) ;
V_28 -> V_31 = 0 ;
V_32:
F_24 ( & V_22 -> V_30 ) ;
return V_29 ;
}
static struct V_11 * * F_26 ( struct V_21 * V_22 ,
unsigned int type )
{
switch ( type ) {
case V_37 :
return & V_22 -> V_38 ;
case V_39 :
return & V_22 -> V_40 ;
case V_41 :
return & V_22 -> V_42 ;
default:
return NULL ;
}
}
static int F_27 ( struct V_21 * V_22 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_43 ;
int V_44 ;
V_12 = F_6 ( sizeof( * V_12 ) , V_14 ) ;
if ( ! V_12 )
return - V_45 ;
V_12 -> type = type ;
V_12 -> V_22 = V_22 ;
F_28 ( V_14 ) ;
F_29 ( & V_46 , V_43 ) ;
V_44 = F_30 ( & V_47 ,
NULL ,
64 * type ,
64 * ( type + 1 ) ,
V_48 ) ;
F_31 ( & V_46 , V_43 ) ;
F_32 () ;
if ( V_44 < 0 )
goto V_49;
V_12 -> V_50 = V_44 ;
V_12 -> V_51 = F_33 ( V_12 ) ;
if ( F_34 ( V_12 -> V_51 ) ) {
V_44 = F_35 ( V_12 -> V_51 ) ;
goto V_52;
}
* F_26 ( V_22 , type ) = V_12 ;
return 0 ;
V_52:
F_29 ( & V_46 , V_43 ) ;
F_36 ( & V_47 , V_12 -> V_50 ) ;
F_31 ( & V_46 , V_43 ) ;
V_49:
F_17 ( V_12 ) ;
return V_44 ;
}
static void F_37 ( struct V_21 * V_22 , unsigned int type )
{
struct V_11 * * V_53 , * V_12 ;
unsigned long V_43 ;
V_53 = F_26 ( V_22 , type ) ;
V_12 = * V_53 ;
if ( ! V_12 )
return;
F_38 ( V_12 -> V_51 ) ;
F_29 ( & V_46 , V_43 ) ;
F_36 ( & V_47 , V_12 -> V_50 ) ;
F_31 ( & V_46 , V_43 ) ;
F_17 ( V_12 ) ;
* V_53 = NULL ;
}
static int F_39 ( struct V_21 * V_22 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_43 ;
int V_29 ;
F_40 ( L_4 ) ;
V_12 = * F_26 ( V_22 , type ) ;
if ( ! V_12 )
return 0 ;
V_29 = F_41 ( V_12 , V_12 -> V_50 , V_54 ) ;
if ( V_29 ) {
F_42 ( L_5 ) ;
return V_29 ;
}
V_29 = F_43 ( V_12 -> V_51 ) ;
if ( V_29 )
goto V_55;
F_29 ( & V_46 , V_43 ) ;
F_44 ( & V_47 , V_12 , V_12 -> V_50 ) ;
F_31 ( & V_46 , V_43 ) ;
F_40 ( L_6 , V_12 -> V_50 ) ;
return 0 ;
V_55:
F_45 ( V_12 ) ;
return V_29 ;
}
static void F_46 ( struct V_21 * V_22 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_43 ;
V_12 = * F_26 ( V_22 , type ) ;
if ( ! V_12 || ! F_47 ( V_12 -> V_51 ) )
return;
F_29 ( & V_46 , V_43 ) ;
F_44 ( & V_47 , NULL , V_12 -> V_50 ) ;
F_31 ( & V_46 , V_43 ) ;
F_48 ( V_12 -> V_51 ) ;
F_49 ( V_12 -> V_51 , NULL ) ;
F_45 ( V_12 ) ;
}
struct V_11 * F_50 ( unsigned int V_56 )
{
struct V_11 * V_12 ;
unsigned long V_43 ;
F_29 ( & V_46 , V_43 ) ;
V_12 = F_51 ( & V_47 , V_56 ) ;
if ( V_12 )
F_52 ( V_12 -> V_22 ) ;
F_31 ( & V_46 , V_43 ) ;
if ( ! V_12 ) {
return F_53 ( - V_57 ) ;
} else if ( F_54 ( V_12 -> V_22 ) ) {
F_55 ( V_12 -> V_22 ) ;
return F_53 ( - V_57 ) ;
}
return V_12 ;
}
void F_56 ( struct V_11 * V_12 )
{
F_55 ( V_12 -> V_22 ) ;
}
void F_57 ( struct V_21 * V_22 )
{
F_40 ( L_4 ) ;
if ( ! V_22 ) {
F_42 ( L_7 ) ;
return;
}
F_58 ( V_22 ) ;
F_55 ( V_22 ) ;
}
void F_59 ( struct V_21 * V_22 )
{
F_46 ( V_22 , V_37 ) ;
F_46 ( V_22 , V_39 ) ;
F_46 ( V_22 , V_41 ) ;
F_21 ( & V_58 ) ;
F_60 ( V_22 ) ;
if ( V_22 -> V_59 == 0 ) {
F_57 ( V_22 ) ;
}
F_24 ( & V_58 ) ;
}
static struct V_60 * F_61 ( struct V_61 * V_62 , int V_43 ,
const char * V_63 , void * V_26 )
{
return F_62 ( V_62 ,
L_8 ,
& V_64 ,
& V_65 ,
0x010203ff ) ;
}
static struct V_66 * F_63 ( void )
{
struct V_66 * V_66 ;
int V_44 ;
V_44 = F_64 ( & V_67 , & V_68 , & V_69 ) ;
if ( V_44 < 0 ) {
F_42 ( L_9 , V_44 ) ;
return F_53 ( V_44 ) ;
}
V_66 = F_65 ( V_68 -> V_70 ) ;
if ( F_34 ( V_66 ) )
F_66 ( & V_68 , & V_69 ) ;
return V_66 ;
}
static void F_67 ( struct V_66 * V_66 )
{
if ( V_66 ) {
F_68 ( V_66 ) ;
F_66 ( & V_68 , & V_69 ) ;
}
}
struct V_21 * F_69 ( struct V_71 * V_23 ,
struct V_72 * V_73 )
{
struct V_21 * V_22 ;
int V_29 ;
V_22 = F_6 ( sizeof( * V_22 ) , V_14 ) ;
if ( ! V_22 )
return NULL ;
F_7 ( & V_22 -> V_74 ) ;
V_22 -> V_22 = V_73 ;
V_22 -> V_23 = V_23 ;
F_70 ( & V_22 -> V_75 ) ;
F_70 ( & V_22 -> V_76 ) ;
F_70 ( & V_22 -> V_77 ) ;
F_70 ( & V_22 -> V_78 ) ;
F_70 ( & V_22 -> V_79 ) ;
F_8 ( & V_22 -> V_80 ) ;
F_8 ( & V_22 -> V_81 ) ;
F_71 ( & V_22 -> V_82 ) ;
F_71 ( & V_22 -> V_83 ) ;
F_71 ( & V_22 -> V_84 ) ;
F_71 ( & V_22 -> V_30 ) ;
V_22 -> V_85 = F_63 () ;
if ( F_34 ( V_22 -> V_85 ) ) {
V_29 = F_35 ( V_22 -> V_85 ) ;
F_42 ( L_10 , V_29 ) ;
goto V_49;
}
if ( F_72 ( V_22 , V_86 ) ) {
V_29 = F_27 ( V_22 , V_41 ) ;
if ( V_29 )
goto V_87;
F_73 ( V_23 -> V_88 || V_23 -> V_89 ) ;
}
if ( F_72 ( V_22 , V_90 ) ) {
V_29 = F_27 ( V_22 , V_39 ) ;
if ( V_29 )
goto V_87;
}
V_29 = F_27 ( V_22 , V_37 ) ;
if ( V_29 )
goto V_87;
if ( F_74 ( & V_22 -> V_91 , 12 ) )
goto V_87;
F_75 ( V_22 ) ;
if ( F_72 ( V_22 , V_92 ) ) {
V_29 = F_76 ( V_22 ) ;
if ( V_29 ) {
F_42 ( L_11 ) ;
goto V_93;
}
}
if ( V_73 ) {
V_29 = F_77 ( V_22 , V_63 ( V_73 ) ) ;
if ( V_29 )
goto V_94;
}
return V_22 ;
V_94:
if ( F_72 ( V_22 , V_92 ) )
F_78 ( V_22 ) ;
V_93:
F_79 ( V_22 ) ;
F_80 ( & V_22 -> V_91 ) ;
V_87:
F_37 ( V_22 , V_37 ) ;
F_37 ( V_22 , V_39 ) ;
F_37 ( V_22 , V_41 ) ;
F_67 ( V_22 -> V_85 ) ;
V_49:
F_81 ( & V_22 -> V_30 ) ;
F_17 ( V_22 ) ;
return NULL ;
}
static void F_82 ( struct V_20 * V_74 )
{
struct V_21 * V_22 = F_14 ( V_74 , struct V_21 , V_74 ) ;
if ( F_72 ( V_22 , V_92 ) )
F_78 ( V_22 ) ;
F_79 ( V_22 ) ;
F_80 ( & V_22 -> V_91 ) ;
F_67 ( V_22 -> V_85 ) ;
F_37 ( V_22 , V_37 ) ;
F_37 ( V_22 , V_39 ) ;
F_37 ( V_22 , V_41 ) ;
F_81 ( & V_22 -> V_30 ) ;
F_17 ( V_22 -> V_25 ) ;
F_17 ( V_22 ) ;
}
void F_52 ( struct V_21 * V_22 )
{
if ( V_22 )
F_12 ( & V_22 -> V_74 ) ;
}
void F_55 ( struct V_21 * V_22 )
{
if ( V_22 )
F_19 ( & V_22 -> V_74 , F_82 ) ;
}
int F_83 ( struct V_21 * V_22 , unsigned long V_43 )
{
int V_29 ;
F_21 ( & V_58 ) ;
V_29 = F_39 ( V_22 , V_41 ) ;
if ( V_29 )
goto V_87;
V_29 = F_39 ( V_22 , V_39 ) ;
if ( V_29 )
goto V_87;
V_29 = F_39 ( V_22 , V_37 ) ;
if ( V_29 )
goto V_87;
if ( V_22 -> V_23 -> V_95 ) {
V_29 = V_22 -> V_23 -> V_95 ( V_22 , V_43 ) ;
if ( V_29 )
goto V_87;
}
V_29 = 0 ;
goto V_32;
V_87:
F_46 ( V_22 , V_37 ) ;
F_46 ( V_22 , V_39 ) ;
F_46 ( V_22 , V_41 ) ;
V_32:
F_24 ( & V_58 ) ;
return V_29 ;
}
void F_58 ( struct V_21 * V_22 )
{
struct V_96 * V_97 , * V_98 ;
F_84 ( V_22 ) ;
if ( V_22 -> V_23 -> V_99 )
V_22 -> V_23 -> V_99 ( V_22 ) ;
if ( V_22 -> V_100 )
F_85 ( V_22 ) ;
F_86 ( V_22 ) ;
F_87 (r_list, list_temp, &dev->maplist, head)
F_88 ( V_22 , V_97 -> V_101 ) ;
F_46 ( V_22 , V_37 ) ;
F_46 ( V_22 , V_39 ) ;
F_46 ( V_22 , V_41 ) ;
}
int F_77 ( struct V_21 * V_22 , const char * V_102 )
{
F_17 ( V_22 -> V_25 ) ;
V_22 -> V_25 = F_89 ( V_102 , V_14 ) ;
return V_22 -> V_25 ? 0 : - V_45 ;
}
static int F_90 ( struct V_66 * V_66 , struct V_103 * V_104 )
{
const struct V_105 * V_106 ;
struct V_11 * V_12 ;
int V_107 ;
F_40 ( L_4 ) ;
F_21 ( & V_58 ) ;
V_12 = F_50 ( F_91 ( V_66 ) ) ;
if ( F_34 ( V_12 ) ) {
V_107 = F_35 ( V_12 ) ;
goto V_32;
}
V_106 = F_92 ( V_12 -> V_22 -> V_23 -> V_108 ) ;
if ( ! V_106 ) {
V_107 = - V_57 ;
goto V_109;
}
F_93 ( V_104 , V_106 ) ;
if ( V_104 -> V_110 -> V_111 )
V_107 = V_104 -> V_110 -> V_111 ( V_66 , V_104 ) ;
else
V_107 = 0 ;
V_109:
F_56 ( V_12 ) ;
V_32:
F_24 ( & V_58 ) ;
return V_107 ;
}
static int T_2 F_94 ( void )
{
int V_29 = - V_45 ;
F_95 () ;
F_96 () ;
F_10 ( & V_47 ) ;
if ( F_97 ( V_112 , L_12 , & V_113 ) )
goto V_114;
V_29 = F_98 () ;
if ( V_29 < 0 ) {
F_2 ( V_6 L_13 ) ;
goto V_115;
}
V_54 = F_99 ( L_14 , NULL ) ;
if ( ! V_54 ) {
F_42 ( L_15 ) ;
V_29 = - 1 ;
goto V_116;
}
F_100 ( L_16 ,
V_117 , V_118 , V_119 , V_120 , V_121 ) ;
return 0 ;
V_116:
F_101 () ;
V_115:
F_102 ( V_112 , L_12 ) ;
F_16 ( & V_47 ) ;
V_114:
return V_29 ;
}
static void T_3 F_103 ( void )
{
F_104 ( V_54 ) ;
F_101 () ;
F_102 ( V_112 , L_12 ) ;
F_105 () ;
F_16 ( & V_47 ) ;
}
