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
if ( F_10 ( & V_13 -> V_19 , V_20 ) ) {
F_11 ( V_13 ) ;
return NULL ;
}
F_12 ( & V_13 -> V_21 ) ;
V_13 -> V_12 = V_12 ;
return V_13 ;
}
struct V_10 * F_13 ( struct V_10 * V_13 )
{
F_14 ( & V_13 -> V_15 ) ;
return V_13 ;
}
static void F_15 ( struct V_22 * V_22 )
{
struct V_10 * V_13 = F_16 ( V_22 , struct V_10 , V_15 ) ;
struct V_23 * V_24 = V_13 -> V_12 -> V_24 ;
struct V_25 * V_26 , * V_27 ;
F_17 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_29 -> V_30 )
V_24 -> V_29 -> V_30 ( V_24 , V_13 ) ;
F_18 (r_list, list_temp, &dev->maplist, head) {
if ( V_26 -> V_13 == V_13 ) {
F_19 ( V_24 , V_26 -> V_31 ) ;
V_26 = NULL ;
}
}
if ( V_13 -> V_32 ) {
F_11 ( V_13 -> V_32 ) ;
V_13 -> V_32 = NULL ;
V_13 -> V_33 = 0 ;
}
F_20 ( & V_13 -> V_19 ) ;
F_21 ( & V_24 -> V_28 ) ;
F_11 ( V_13 ) ;
}
void F_22 ( struct V_10 * * V_13 )
{
F_23 ( & ( * V_13 ) -> V_15 , F_15 ) ;
* V_13 = NULL ;
}
int F_24 ( struct V_23 * V_24 , void * V_34 ,
struct V_35 * V_36 )
{
int V_37 = 0 ;
F_17 ( & V_24 -> V_38 ) ;
if ( V_36 -> V_39 )
goto V_40;
if ( V_36 -> V_12 -> V_13 ) {
V_37 = - V_41 ;
goto V_40;
}
if ( ! V_36 -> V_13 ) {
V_37 = - V_41 ;
goto V_40;
}
V_36 -> V_12 -> V_13 = F_13 ( V_36 -> V_13 ) ;
V_36 -> V_39 = 1 ;
if ( V_24 -> V_29 -> V_42 ) {
V_37 = V_24 -> V_29 -> V_42 ( V_24 , V_36 , false ) ;
if ( F_25 ( V_37 != 0 ) ) {
V_36 -> V_39 = 0 ;
F_22 ( & V_36 -> V_12 -> V_13 ) ;
}
}
V_40:
F_21 ( & V_24 -> V_38 ) ;
return V_37 ;
}
int F_26 ( struct V_23 * V_24 , void * V_34 ,
struct V_35 * V_36 )
{
int V_37 = - V_41 ;
F_17 ( & V_24 -> V_38 ) ;
if ( ! V_36 -> V_39 )
goto V_40;
if ( ! V_36 -> V_12 -> V_13 )
goto V_40;
V_37 = 0 ;
if ( V_24 -> V_29 -> V_43 )
V_24 -> V_29 -> V_43 ( V_24 , V_36 , false ) ;
F_22 ( & V_36 -> V_12 -> V_13 ) ;
V_36 -> V_39 = 0 ;
V_40:
F_21 ( & V_24 -> V_38 ) ;
return V_37 ;
}
static struct V_11 * * F_27 ( struct V_23 * V_24 ,
unsigned int type )
{
switch ( type ) {
case V_44 :
return & V_24 -> V_45 ;
case V_46 :
return & V_24 -> V_47 ;
case V_48 :
return & V_24 -> V_49 ;
default:
return NULL ;
}
}
static int F_28 ( struct V_23 * V_24 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_50 ;
int V_51 ;
V_12 = F_6 ( sizeof( * V_12 ) , V_14 ) ;
if ( ! V_12 )
return - V_52 ;
V_12 -> type = type ;
V_12 -> V_24 = V_24 ;
F_29 ( V_14 ) ;
F_30 ( & V_53 , V_50 ) ;
V_51 = F_31 ( & V_54 ,
NULL ,
64 * type ,
64 * ( type + 1 ) ,
V_55 ) ;
F_32 ( & V_53 , V_50 ) ;
F_33 () ;
if ( V_51 < 0 )
goto V_56;
V_12 -> V_57 = V_51 ;
V_12 -> V_58 = F_34 ( V_12 ) ;
if ( F_35 ( V_12 -> V_58 ) ) {
V_51 = F_36 ( V_12 -> V_58 ) ;
goto V_59;
}
* F_27 ( V_24 , type ) = V_12 ;
return 0 ;
V_59:
F_30 ( & V_53 , V_50 ) ;
F_37 ( & V_54 , V_12 -> V_57 ) ;
F_32 ( & V_53 , V_50 ) ;
V_56:
F_11 ( V_12 ) ;
return V_51 ;
}
static void F_38 ( struct V_23 * V_24 , unsigned int type )
{
struct V_11 * * V_60 , * V_12 ;
unsigned long V_50 ;
V_60 = F_27 ( V_24 , type ) ;
V_12 = * V_60 ;
if ( ! V_12 )
return;
F_39 ( & V_12 -> V_61 ) ;
F_40 ( V_12 -> V_58 ) ;
F_30 ( & V_53 , V_50 ) ;
F_37 ( & V_54 , V_12 -> V_57 ) ;
F_32 ( & V_53 , V_50 ) ;
F_11 ( V_12 ) ;
* V_60 = NULL ;
}
static int F_41 ( struct V_23 * V_24 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_50 ;
int V_37 ;
F_42 ( L_4 ) ;
V_12 = * F_27 ( V_24 , type ) ;
if ( ! V_12 )
return 0 ;
V_37 = F_43 ( V_12 , V_12 -> V_57 , V_62 ) ;
if ( V_37 ) {
F_44 ( L_5 ) ;
return V_37 ;
}
V_37 = F_45 ( V_12 -> V_58 ) ;
if ( V_37 )
goto V_63;
F_30 ( & V_53 , V_50 ) ;
F_46 ( & V_54 , V_12 , V_12 -> V_57 ) ;
F_32 ( & V_53 , V_50 ) ;
F_42 ( L_6 , V_12 -> V_57 ) ;
return 0 ;
V_63:
F_47 ( V_12 ) ;
return V_37 ;
}
static void F_48 ( struct V_23 * V_24 , unsigned int type )
{
struct V_11 * V_12 ;
unsigned long V_50 ;
V_12 = * F_27 ( V_24 , type ) ;
if ( ! V_12 || ! F_49 ( V_12 -> V_58 ) )
return;
F_30 ( & V_53 , V_50 ) ;
F_46 ( & V_54 , NULL , V_12 -> V_57 ) ;
F_32 ( & V_53 , V_50 ) ;
F_50 ( V_12 -> V_58 ) ;
F_51 ( V_12 -> V_58 , NULL ) ;
F_47 ( V_12 ) ;
}
struct V_11 * F_52 ( unsigned int V_64 )
{
struct V_11 * V_12 ;
unsigned long V_50 ;
F_30 ( & V_53 , V_50 ) ;
V_12 = F_53 ( & V_54 , V_64 ) ;
if ( V_12 )
F_54 ( V_12 -> V_24 ) ;
F_32 ( & V_53 , V_50 ) ;
if ( ! V_12 ) {
return F_55 ( - V_65 ) ;
} else if ( F_56 ( V_12 -> V_24 ) ) {
F_57 ( V_12 -> V_24 ) ;
return F_55 ( - V_65 ) ;
}
return V_12 ;
}
void F_58 ( struct V_11 * V_12 )
{
F_57 ( V_12 -> V_24 ) ;
}
void F_59 ( struct V_23 * V_24 )
{
F_42 ( L_4 ) ;
if ( ! V_24 ) {
F_44 ( L_7 ) ;
return;
}
F_60 ( V_24 ) ;
F_57 ( V_24 ) ;
}
void F_61 ( struct V_23 * V_24 )
{
F_48 ( V_24 , V_44 ) ;
F_48 ( V_24 , V_46 ) ;
F_48 ( V_24 , V_48 ) ;
F_17 ( & V_66 ) ;
F_62 ( V_24 ) ;
if ( V_24 -> V_67 == 0 ) {
F_59 ( V_24 ) ;
}
F_21 ( & V_66 ) ;
}
static struct V_68 * F_63 ( struct V_69 * V_70 , int V_50 ,
const char * V_71 , void * V_34 )
{
return F_64 ( V_70 ,
L_8 ,
& V_72 ,
& V_73 ,
0x010203ff ) ;
}
static struct V_74 * F_65 ( void )
{
struct V_74 * V_74 ;
int V_51 ;
V_51 = F_66 ( & V_75 , & V_76 , & V_77 ) ;
if ( V_51 < 0 ) {
F_44 ( L_9 , V_51 ) ;
return F_55 ( V_51 ) ;
}
V_74 = F_67 ( V_76 -> V_78 ) ;
if ( F_35 ( V_74 ) )
F_68 ( & V_76 , & V_77 ) ;
return V_74 ;
}
static void F_69 ( struct V_74 * V_74 )
{
if ( V_74 ) {
F_70 ( V_74 ) ;
F_68 ( & V_76 , & V_77 ) ;
}
}
struct V_23 * F_71 ( struct V_79 * V_29 ,
struct V_80 * V_81 )
{
struct V_23 * V_24 ;
int V_37 ;
V_24 = F_6 ( sizeof( * V_24 ) , V_14 ) ;
if ( ! V_24 )
return NULL ;
F_7 ( & V_24 -> V_82 ) ;
V_24 -> V_24 = V_81 ;
V_24 -> V_29 = V_29 ;
F_12 ( & V_24 -> V_83 ) ;
F_12 ( & V_24 -> V_84 ) ;
F_12 ( & V_24 -> V_85 ) ;
F_12 ( & V_24 -> V_86 ) ;
F_12 ( & V_24 -> V_87 ) ;
F_8 ( & V_24 -> V_88 ) ;
F_8 ( & V_24 -> V_89 ) ;
F_72 ( & V_24 -> V_28 ) ;
F_72 ( & V_24 -> V_90 ) ;
F_72 ( & V_24 -> V_38 ) ;
V_24 -> V_91 = F_65 () ;
if ( F_35 ( V_24 -> V_91 ) ) {
V_37 = F_36 ( V_24 -> V_91 ) ;
F_44 ( L_10 , V_37 ) ;
goto V_56;
}
if ( F_73 ( V_24 , V_92 ) ) {
V_37 = F_28 ( V_24 , V_48 ) ;
if ( V_37 )
goto V_93;
}
if ( F_73 ( V_24 , V_94 ) ) {
V_37 = F_28 ( V_24 , V_46 ) ;
if ( V_37 )
goto V_93;
}
V_37 = F_28 ( V_24 , V_44 ) ;
if ( V_37 )
goto V_93;
if ( F_10 ( & V_24 -> V_95 , 12 ) )
goto V_93;
V_37 = F_74 ( V_24 ) ;
if ( V_37 ) {
F_44 ( L_11 ) ;
goto V_96;
}
if ( F_73 ( V_24 , V_97 ) ) {
V_37 = F_75 ( V_24 ) ;
if ( V_37 ) {
F_44 ( L_12 ) ;
goto V_98;
}
}
return V_24 ;
V_98:
F_76 ( V_24 ) ;
V_96:
F_20 ( & V_24 -> V_95 ) ;
V_93:
F_38 ( V_24 , V_44 ) ;
F_38 ( V_24 , V_46 ) ;
F_38 ( V_24 , V_48 ) ;
F_69 ( V_24 -> V_91 ) ;
V_56:
F_77 ( & V_24 -> V_38 ) ;
F_11 ( V_24 ) ;
return NULL ;
}
static void F_78 ( struct V_22 * V_82 )
{
struct V_23 * V_24 = F_16 ( V_82 , struct V_23 , V_82 ) ;
if ( F_73 ( V_24 , V_97 ) )
F_79 ( V_24 ) ;
F_76 ( V_24 ) ;
F_20 ( & V_24 -> V_95 ) ;
F_69 ( V_24 -> V_91 ) ;
F_38 ( V_24 , V_44 ) ;
F_38 ( V_24 , V_46 ) ;
F_38 ( V_24 , V_48 ) ;
F_77 ( & V_24 -> V_38 ) ;
F_11 ( V_24 -> V_32 ) ;
F_11 ( V_24 ) ;
}
void F_54 ( struct V_23 * V_24 )
{
if ( V_24 )
F_14 ( & V_24 -> V_82 ) ;
}
void F_57 ( struct V_23 * V_24 )
{
if ( V_24 )
F_23 ( & V_24 -> V_82 , F_78 ) ;
}
int F_80 ( struct V_23 * V_24 , unsigned long V_50 )
{
int V_37 ;
F_17 ( & V_66 ) ;
V_37 = F_41 ( V_24 , V_48 ) ;
if ( V_37 )
goto V_93;
V_37 = F_41 ( V_24 , V_46 ) ;
if ( V_37 )
goto V_93;
V_37 = F_41 ( V_24 , V_44 ) ;
if ( V_37 )
goto V_93;
if ( V_24 -> V_29 -> V_99 ) {
V_37 = V_24 -> V_29 -> V_99 ( V_24 , V_50 ) ;
if ( V_37 )
goto V_93;
}
if ( F_73 ( V_24 , V_92 ) ) {
V_37 = F_81 ( V_24 ,
& V_24 -> V_45 -> V_61 ) ;
if ( V_37 )
goto V_100;
}
V_37 = 0 ;
goto V_40;
V_100:
if ( V_24 -> V_29 -> V_101 )
V_24 -> V_29 -> V_101 ( V_24 ) ;
V_93:
F_48 ( V_24 , V_44 ) ;
F_48 ( V_24 , V_46 ) ;
F_48 ( V_24 , V_48 ) ;
V_40:
F_21 ( & V_66 ) ;
return V_37 ;
}
void F_60 ( struct V_23 * V_24 )
{
struct V_25 * V_26 , * V_27 ;
F_82 ( V_24 ) ;
if ( V_24 -> V_29 -> V_101 )
V_24 -> V_29 -> V_101 ( V_24 ) ;
if ( V_24 -> V_102 )
F_83 ( V_24 ) ;
F_84 ( V_24 ) ;
F_18 (r_list, list_temp, &dev->maplist, head)
F_85 ( V_24 , V_26 -> V_31 ) ;
F_48 ( V_24 , V_44 ) ;
F_48 ( V_24 , V_46 ) ;
F_48 ( V_24 , V_48 ) ;
}
int F_86 ( struct V_23 * V_24 , const char * V_4 , ... )
{
T_1 V_103 ;
F_11 ( V_24 -> V_32 ) ;
va_start ( V_103 , V_4 ) ;
V_24 -> V_32 = F_87 ( V_14 , V_4 , V_103 ) ;
va_end ( V_103 ) ;
return V_24 -> V_32 ? 0 : - V_52 ;
}
static int F_88 ( struct V_74 * V_74 , struct V_104 * V_105 )
{
const struct V_106 * V_107 ;
struct V_11 * V_12 ;
int V_108 ;
F_42 ( L_4 ) ;
F_17 ( & V_66 ) ;
V_12 = F_52 ( F_89 ( V_74 ) ) ;
if ( F_35 ( V_12 ) ) {
V_108 = F_36 ( V_12 ) ;
goto V_40;
}
V_107 = F_90 ( V_12 -> V_24 -> V_29 -> V_109 ) ;
if ( ! V_107 ) {
V_108 = - V_65 ;
goto V_110;
}
F_91 ( V_105 , V_107 ) ;
if ( V_105 -> V_111 -> V_112 )
V_108 = V_105 -> V_111 -> V_112 ( V_74 , V_105 ) ;
else
V_108 = 0 ;
V_110:
F_58 ( V_12 ) ;
V_40:
F_21 ( & V_66 ) ;
return V_108 ;
}
static int T_2 F_92 ( void )
{
int V_37 = - V_52 ;
F_93 () ;
F_94 () ;
F_95 ( & V_54 ) ;
if ( F_96 ( V_113 , L_13 , & V_114 ) )
goto V_115;
V_116 = F_97 ( V_117 , L_13 ) ;
if ( F_35 ( V_116 ) ) {
F_2 ( V_6 L_14 ) ;
V_37 = F_36 ( V_116 ) ;
goto V_118;
}
V_62 = F_98 ( L_15 , NULL ) ;
if ( ! V_62 ) {
F_44 ( L_16 ) ;
V_37 = - 1 ;
goto V_119;
}
F_99 ( L_17 ,
V_120 , V_121 , V_122 , V_123 , V_124 ) ;
return 0 ;
V_119:
F_100 () ;
V_118:
F_101 ( V_113 , L_13 ) ;
F_102 ( & V_54 ) ;
V_115:
return V_37 ;
}
static void T_3 F_103 ( void )
{
F_104 ( V_62 ) ;
F_100 () ;
F_101 ( V_113 , L_13 ) ;
F_105 () ;
F_102 ( & V_54 ) ;
}
