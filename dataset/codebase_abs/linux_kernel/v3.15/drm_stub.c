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
F_9 ( & V_15 -> V_21 , V_22 ) ;
F_10 ( & V_15 -> V_23 ) ;
V_15 -> V_14 = V_14 ;
return V_15 ;
}
struct V_12 * F_11 ( struct V_12 * V_15 )
{
F_12 ( & V_15 -> V_17 ) ;
return V_15 ;
}
static void F_13 ( struct V_24 * V_24 )
{
struct V_12 * V_15 = F_14 ( V_24 , struct V_12 , V_17 ) ;
struct V_25 * V_26 , * V_27 ;
struct V_28 * V_29 = V_15 -> V_14 -> V_29 ;
struct V_30 * V_31 , * V_32 ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_34 -> V_35 )
V_29 -> V_34 -> V_35 ( V_29 , V_15 ) ;
F_16 (r_list, list_temp, &dev->maplist, head) {
if ( V_31 -> V_15 == V_15 ) {
F_17 ( V_29 , V_31 -> V_36 ) ;
V_31 = NULL ;
}
}
if ( V_15 -> V_37 ) {
F_18 ( V_15 -> V_37 ) ;
V_15 -> V_37 = NULL ;
V_15 -> V_38 = 0 ;
}
F_18 ( V_29 -> V_39 ) ;
V_29 -> V_39 = NULL ;
F_16 (pt, next, &master->magicfree, head) {
F_19 ( & V_26 -> V_40 ) ;
F_20 ( & V_15 -> V_21 , & V_26 -> V_41 ) ;
F_18 ( V_26 ) ;
}
F_21 ( & V_15 -> V_21 ) ;
F_22 ( & V_29 -> V_33 ) ;
F_18 ( V_15 ) ;
}
void F_23 ( struct V_12 * * V_15 )
{
F_24 ( & ( * V_15 ) -> V_17 , F_13 ) ;
* V_15 = NULL ;
}
int F_25 ( struct V_28 * V_29 , void * V_42 ,
struct V_43 * V_44 )
{
int V_45 = 0 ;
F_15 ( & V_29 -> V_46 ) ;
if ( V_44 -> V_47 )
goto V_48;
if ( V_44 -> V_14 -> V_15 ) {
V_45 = - V_49 ;
goto V_48;
}
if ( ! V_44 -> V_15 ) {
V_45 = - V_49 ;
goto V_48;
}
V_44 -> V_14 -> V_15 = F_11 ( V_44 -> V_15 ) ;
V_44 -> V_47 = 1 ;
if ( V_29 -> V_34 -> V_50 ) {
V_45 = V_29 -> V_34 -> V_50 ( V_29 , V_44 , false ) ;
if ( F_26 ( V_45 != 0 ) ) {
V_44 -> V_47 = 0 ;
F_23 ( & V_44 -> V_14 -> V_15 ) ;
}
}
V_48:
F_22 ( & V_29 -> V_46 ) ;
return V_45 ;
}
int F_27 ( struct V_28 * V_29 , void * V_42 ,
struct V_43 * V_44 )
{
int V_45 = - V_49 ;
F_15 ( & V_29 -> V_46 ) ;
if ( ! V_44 -> V_47 )
goto V_48;
if ( ! V_44 -> V_14 -> V_15 )
goto V_48;
V_45 = 0 ;
if ( V_29 -> V_34 -> V_51 )
V_29 -> V_34 -> V_51 ( V_29 , V_44 , false ) ;
F_23 ( & V_44 -> V_14 -> V_15 ) ;
V_44 -> V_47 = 0 ;
V_48:
F_22 ( & V_29 -> V_46 ) ;
return V_45 ;
}
static struct V_13 * * F_28 ( struct V_28 * V_29 ,
unsigned int type )
{
switch ( type ) {
case V_52 :
return & V_29 -> V_53 ;
case V_54 :
return & V_29 -> V_55 ;
case V_56 :
return & V_29 -> V_57 ;
default:
return NULL ;
}
}
static int F_29 ( struct V_28 * V_29 , unsigned int type )
{
struct V_13 * V_14 ;
V_14 = F_5 ( sizeof( * V_14 ) , V_16 ) ;
if ( ! V_14 )
return - V_58 ;
V_14 -> type = type ;
V_14 -> V_29 = V_29 ;
* F_28 ( V_29 , type ) = V_14 ;
return 0 ;
}
static void F_30 ( struct V_28 * V_29 , unsigned int type )
{
struct V_13 * * V_59 ;
V_59 = F_28 ( V_29 , type ) ;
if ( * V_59 ) {
F_18 ( * V_59 ) ;
* V_59 = NULL ;
}
}
static int F_31 ( struct V_28 * V_29 , unsigned int type )
{
struct V_13 * V_60 ;
unsigned long V_61 ;
int V_45 ;
int V_62 ;
F_32 ( L_4 ) ;
V_60 = * F_28 ( V_29 , type ) ;
if ( ! V_60 )
return 0 ;
F_33 ( V_16 ) ;
F_34 ( & V_63 , V_61 ) ;
V_62 = F_35 ( & V_64 ,
NULL ,
64 * type ,
64 * ( type + 1 ) ,
V_65 ) ;
F_36 ( & V_63 , V_61 ) ;
F_37 () ;
if ( V_62 < 0 )
return V_62 ;
V_60 -> V_66 = V_62 ;
V_45 = F_38 ( V_60 , V_62 , V_67 ) ;
if ( V_45 ) {
F_39 ( L_5 ) ;
goto V_68;
}
V_45 = F_40 ( V_60 ) ;
if ( V_45 ) {
F_39 ( L_6 ) ;
goto V_69;
}
F_34 ( & V_63 , V_61 ) ;
F_41 ( & V_64 , V_60 , V_60 -> V_66 ) ;
F_36 ( & V_63 , V_61 ) ;
F_32 ( L_7 , V_62 ) ;
return 0 ;
V_69:
F_42 ( V_60 ) ;
V_68:
F_34 ( & V_63 , V_61 ) ;
F_43 ( & V_64 , V_62 ) ;
F_36 ( & V_63 , V_61 ) ;
V_60 -> V_66 = 0 ;
return V_45 ;
}
static void F_44 ( struct V_28 * V_29 , unsigned int type )
{
struct V_13 * V_14 ;
unsigned long V_61 ;
V_14 = * F_28 ( V_29 , type ) ;
if ( ! V_14 || ! V_14 -> V_70 )
return;
F_34 ( & V_63 , V_61 ) ;
F_43 ( & V_64 , V_14 -> V_66 ) ;
F_36 ( & V_63 , V_61 ) ;
V_14 -> V_66 = 0 ;
F_42 ( V_14 ) ;
F_45 ( V_14 ) ;
}
struct V_13 * F_46 ( unsigned int V_62 )
{
struct V_13 * V_14 ;
unsigned long V_61 ;
F_34 ( & V_63 , V_61 ) ;
V_14 = F_47 ( & V_64 , V_62 ) ;
if ( V_14 )
F_48 ( V_14 -> V_29 ) ;
F_36 ( & V_63 , V_61 ) ;
if ( ! V_14 ) {
return F_49 ( - V_71 ) ;
} else if ( F_50 ( V_14 -> V_29 ) ) {
F_51 ( V_14 -> V_29 ) ;
return F_49 ( - V_71 ) ;
}
return V_14 ;
}
void F_52 ( struct V_13 * V_14 )
{
F_51 ( V_14 -> V_29 ) ;
}
void F_53 ( struct V_28 * V_29 )
{
F_32 ( L_4 ) ;
if ( ! V_29 ) {
F_39 ( L_8 ) ;
return;
}
F_54 ( V_29 ) ;
F_51 ( V_29 ) ;
}
void F_55 ( struct V_28 * V_29 )
{
F_44 ( V_29 , V_52 ) ;
F_44 ( V_29 , V_54 ) ;
F_44 ( V_29 , V_56 ) ;
F_15 ( & V_72 ) ;
F_56 ( V_29 ) ;
if ( V_29 -> V_73 == 0 ) {
F_53 ( V_29 ) ;
}
F_22 ( & V_72 ) ;
}
static struct V_74 * F_57 ( struct V_75 * V_76 , int V_61 ,
const char * V_77 , void * V_42 )
{
return F_58 ( V_76 ,
L_9 ,
& V_78 ,
& V_79 ,
0x010203ff ) ;
}
static struct V_80 * F_59 ( void )
{
struct V_80 * V_80 ;
int V_5 ;
V_5 = F_60 ( & V_81 , & V_82 , & V_83 ) ;
if ( V_5 < 0 ) {
F_39 ( L_10 , V_5 ) ;
return F_49 ( V_5 ) ;
}
V_80 = F_61 ( V_82 -> V_84 ) ;
if ( F_62 ( V_80 ) )
F_63 ( & V_82 , & V_83 ) ;
return V_80 ;
}
static void F_64 ( struct V_80 * V_80 )
{
if ( V_80 ) {
F_65 ( V_80 ) ;
F_63 ( & V_82 , & V_83 ) ;
}
}
struct V_28 * F_66 ( struct V_85 * V_34 ,
struct V_86 * V_87 )
{
struct V_28 * V_29 ;
int V_45 ;
V_29 = F_5 ( sizeof( * V_29 ) , V_16 ) ;
if ( ! V_29 )
return NULL ;
F_6 ( & V_29 -> V_88 ) ;
V_29 -> V_29 = V_87 ;
V_29 -> V_34 = V_34 ;
F_10 ( & V_29 -> V_89 ) ;
F_10 ( & V_29 -> V_90 ) ;
F_10 ( & V_29 -> V_91 ) ;
F_10 ( & V_29 -> V_92 ) ;
F_10 ( & V_29 -> V_93 ) ;
F_7 ( & V_29 -> V_94 ) ;
F_7 ( & V_29 -> V_95 ) ;
F_67 ( & V_29 -> V_33 ) ;
F_67 ( & V_29 -> V_96 ) ;
F_67 ( & V_29 -> V_46 ) ;
V_29 -> V_97 = F_59 () ;
if ( F_62 ( V_29 -> V_97 ) ) {
V_45 = F_68 ( V_29 -> V_97 ) ;
F_39 ( L_11 , V_45 ) ;
goto V_98;
}
if ( F_69 ( V_29 , V_99 ) ) {
V_45 = F_29 ( V_29 , V_56 ) ;
if ( V_45 )
goto V_100;
}
if ( F_69 ( V_29 , V_101 ) && V_102 ) {
V_45 = F_29 ( V_29 , V_54 ) ;
if ( V_45 )
goto V_100;
}
V_45 = F_29 ( V_29 , V_52 ) ;
if ( V_45 )
goto V_100;
if ( F_9 ( & V_29 -> V_103 , 12 ) )
goto V_100;
V_45 = F_70 ( V_29 ) ;
if ( V_45 ) {
F_39 ( L_12 ) ;
goto V_104;
}
if ( V_34 -> V_105 & V_106 ) {
V_45 = F_71 ( V_29 ) ;
if ( V_45 ) {
F_39 ( L_13 ) ;
goto V_107;
}
}
return V_29 ;
V_107:
F_72 ( V_29 ) ;
V_104:
F_21 ( & V_29 -> V_103 ) ;
V_100:
F_30 ( V_29 , V_52 ) ;
F_30 ( V_29 , V_54 ) ;
F_30 ( V_29 , V_56 ) ;
F_64 ( V_29 -> V_97 ) ;
V_98:
F_73 ( & V_29 -> V_46 ) ;
F_18 ( V_29 ) ;
return NULL ;
}
static void F_74 ( struct V_24 * V_88 )
{
struct V_28 * V_29 = F_14 ( V_88 , struct V_28 , V_88 ) ;
if ( V_29 -> V_34 -> V_105 & V_106 )
F_75 ( V_29 ) ;
F_72 ( V_29 ) ;
F_21 ( & V_29 -> V_103 ) ;
F_64 ( V_29 -> V_97 ) ;
F_30 ( V_29 , V_52 ) ;
F_30 ( V_29 , V_54 ) ;
F_30 ( V_29 , V_56 ) ;
F_18 ( V_29 -> V_39 ) ;
F_73 ( & V_29 -> V_46 ) ;
F_18 ( V_29 ) ;
}
void F_48 ( struct V_28 * V_29 )
{
if ( V_29 )
F_12 ( & V_29 -> V_88 ) ;
}
void F_51 ( struct V_28 * V_29 )
{
if ( V_29 )
F_24 ( & V_29 -> V_88 , F_74 ) ;
}
int F_76 ( struct V_28 * V_29 , unsigned long V_61 )
{
int V_45 ;
F_15 ( & V_72 ) ;
V_45 = F_31 ( V_29 , V_56 ) ;
if ( V_45 )
goto V_100;
V_45 = F_31 ( V_29 , V_54 ) ;
if ( V_45 )
goto V_100;
V_45 = F_31 ( V_29 , V_52 ) ;
if ( V_45 )
goto V_100;
if ( V_29 -> V_34 -> V_108 ) {
V_45 = V_29 -> V_34 -> V_108 ( V_29 , V_61 ) ;
if ( V_45 )
goto V_100;
}
if ( F_69 ( V_29 , V_99 ) ) {
V_45 = F_77 ( V_29 ,
& V_29 -> V_53 -> V_109 ) ;
if ( V_45 )
goto V_110;
}
V_45 = 0 ;
goto V_48;
V_110:
if ( V_29 -> V_34 -> V_111 )
V_29 -> V_34 -> V_111 ( V_29 ) ;
V_100:
F_44 ( V_29 , V_52 ) ;
F_44 ( V_29 , V_54 ) ;
F_44 ( V_29 , V_56 ) ;
V_48:
F_22 ( & V_72 ) ;
return V_45 ;
}
void F_54 ( struct V_28 * V_29 )
{
struct V_30 * V_31 , * V_32 ;
F_78 ( V_29 ) ;
if ( V_29 -> V_34 -> V_111 )
V_29 -> V_34 -> V_111 ( V_29 ) ;
if ( V_29 -> V_112 )
F_79 ( V_29 ) ;
F_80 ( V_29 ) ;
F_16 (r_list, list_temp, &dev->maplist, head)
F_81 ( V_29 , V_31 -> V_36 ) ;
F_44 ( V_29 , V_52 ) ;
F_44 ( V_29 , V_54 ) ;
F_44 ( V_29 , V_56 ) ;
}
