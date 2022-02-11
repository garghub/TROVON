static struct V_1 * F_1 ( enum V_2 V_3 )
{
switch ( F_2 () ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return NULL ;
case V_10 :
case V_11 :
case V_12 :
switch ( V_3 ) {
case V_13 :
return F_3 ( 0 ) ;
case V_14 :
return F_3 ( 1 ) ;
default:
return NULL ;
}
case V_15 :
switch ( V_3 ) {
case V_13 :
return F_3 ( 0 ) ;
case V_16 :
return F_3 ( 1 ) ;
default:
return NULL ;
}
default:
return NULL ;
}
}
static enum V_17 F_4 ( enum V_2 V_3 )
{
switch ( V_3 ) {
case V_13 :
return V_18 ;
case V_14 :
return V_19 ;
case V_16 :
return V_19 ;
default:
F_5 ( 1 ) ;
return V_20 ;
}
}
static bool F_6 ( int V_21 , int V_22 , unsigned long V_23 ,
unsigned long V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
if ( V_27 -> V_28 >= 100000000 ) {
if ( V_21 > 1 && V_21 % 2 != 0 )
return false ;
if ( V_22 > 1 && V_22 % 2 != 0 )
return false ;
}
V_27 -> V_29 . V_30 = V_21 ;
V_27 -> V_29 . V_31 = V_22 ;
V_27 -> V_29 . V_23 = V_23 ;
V_27 -> V_29 . V_24 = V_24 ;
return true ;
}
static bool F_7 ( int V_32 , unsigned long V_33 ,
void * V_25 )
{
struct V_26 * V_27 = V_25 ;
if ( V_32 > 1 && V_32 % 2 != 0 && V_27 -> V_28 >= 100000000 )
return false ;
V_27 -> V_34 . V_32 = V_32 ;
V_27 -> V_34 . V_35 = V_33 ;
return F_8 ( V_33 , V_27 -> V_28 , V_27 -> V_36 ,
F_6 , V_27 ) ;
}
static bool F_9 ( int V_37 , int V_38 , unsigned long V_39 ,
unsigned long V_40 ,
void * V_25 )
{
struct V_26 * V_27 = V_25 ;
V_27 -> V_34 . V_37 = V_37 ;
V_27 -> V_34 . V_38 = V_38 ;
V_27 -> V_34 . V_39 = V_39 ;
V_27 -> V_34 . V_41 = V_40 ;
return F_10 ( V_27 -> V_42 , V_40 , V_27 -> V_28 ,
F_7 , V_27 ) ;
}
static bool F_11 ( unsigned long V_43 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
V_27 -> V_43 = V_43 ;
return F_8 ( V_43 , V_27 -> V_28 , V_27 -> V_36 ,
F_6 , V_27 ) ;
}
static bool F_12 ( unsigned long V_24 , struct V_26 * V_27 )
{
unsigned long V_44 ;
unsigned long V_45 , V_46 ;
V_44 = F_13 ( V_47 . V_42 ) ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_42 = V_47 . V_42 ;
V_27 -> V_28 = V_24 - 1000 ;
V_27 -> V_36 = V_24 + 1000 ;
V_27 -> V_34 . V_44 = V_44 ;
V_45 = 0 ;
V_46 = 0 ;
return F_14 ( V_47 . V_42 , V_44 ,
V_45 , V_46 ,
F_9 , V_27 ) ;
}
static bool F_15 ( unsigned long V_24 , struct V_26 * V_27 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < 25 ; ++ V_48 ) {
bool V_49 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
if ( V_24 > 1000 * V_48 * V_48 * V_48 )
V_27 -> V_28 = F_16 ( V_24 - 1000 * V_48 * V_48 * V_48 , 0lu ) ;
else
V_27 -> V_28 = 0 ;
V_27 -> V_36 = V_24 + 1000 * V_48 * V_48 * V_48 ;
V_49 = F_17 ( V_24 , V_27 -> V_28 , F_11 , V_27 ) ;
if ( V_49 )
return V_49 ;
}
return false ;
}
static int F_18 ( enum V_2 V_3 ,
unsigned long V_50 , unsigned long * V_43 , int * V_30 ,
int * V_31 )
{
struct V_26 V_27 ;
int V_51 ;
bool V_49 ;
V_49 = F_12 ( V_50 , & V_27 ) ;
if ( ! V_49 )
return - V_52 ;
V_51 = F_19 ( V_47 . V_42 , & V_27 . V_34 ) ;
if ( V_51 )
return V_51 ;
F_20 ( V_3 ,
F_4 ( V_3 ) ) ;
V_47 . V_53 . V_54 = V_27 . V_29 ;
* V_43 = V_27 . V_34 . V_35 ;
* V_30 = V_27 . V_29 . V_30 ;
* V_31 = V_27 . V_29 . V_31 ;
return 0 ;
}
static int F_21 ( unsigned long V_50 , unsigned long * V_43 ,
int * V_30 , int * V_31 )
{
struct V_26 V_27 ;
int V_51 ;
bool V_49 ;
V_49 = F_15 ( V_50 , & V_27 ) ;
if ( ! V_49 )
return - V_52 ;
V_51 = F_22 ( V_27 . V_43 ) ;
if ( V_51 )
return V_51 ;
V_47 . V_53 . V_54 = V_27 . V_29 ;
* V_43 = V_27 . V_43 ;
* V_30 = V_27 . V_29 . V_30 ;
* V_31 = V_27 . V_29 . V_31 ;
return 0 ;
}
static int F_23 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = & V_47 . V_59 ;
int V_30 = 0 , V_31 = 0 ;
unsigned long V_43 = 0 ;
unsigned long V_24 ;
int V_51 = 0 ;
if ( V_47 . V_42 )
V_51 = F_18 ( V_56 -> V_60 , V_58 -> V_61 , & V_43 ,
& V_30 , & V_31 ) ;
else
V_51 = F_21 ( V_58 -> V_61 , & V_43 ,
& V_30 , & V_31 ) ;
if ( V_51 )
return V_51 ;
V_24 = V_43 / V_30 / V_31 ;
if ( V_24 != V_58 -> V_61 ) {
F_24 ( L_1 ,
V_58 -> V_61 , V_24 ) ;
V_58 -> V_61 = V_24 ;
}
F_25 ( V_56 , V_58 ) ;
return 0 ;
}
static void F_26 ( struct V_55 * V_56 )
{
V_47 . V_53 . V_62 = V_63 ;
V_47 . V_53 . V_64 = false ;
V_47 . V_53 . V_65 = false ;
V_47 . V_53 . V_66 = V_47 . V_67 ;
V_47 . V_53 . V_68 = 0 ;
F_27 ( V_56 , & V_47 . V_53 ) ;
}
static int F_28 ( struct V_69 * V_70 )
{
struct V_69 * V_71 = & V_47 . V_72 ;
int V_51 ;
F_29 ( & V_47 . V_73 ) ;
if ( F_30 ( V_74 ) && ! V_47 . V_75 ) {
F_31 ( L_2 ) ;
V_51 = - V_76 ;
goto V_77;
}
if ( V_71 == NULL || V_71 -> V_78 == NULL ) {
F_31 ( L_3 ) ;
V_51 = - V_76 ;
goto V_79;
}
if ( F_30 ( V_74 ) ) {
V_51 = F_32 ( V_47 . V_75 ) ;
if ( V_51 )
goto V_80;
}
V_51 = F_33 () ;
if ( V_51 )
goto V_81;
V_51 = F_34 ( V_71 -> V_78 -> V_60 ) ;
if ( V_51 )
goto V_82;
if ( V_47 . V_42 ) {
V_51 = F_35 ( V_47 . V_42 ) ;
if ( V_51 )
goto V_83;
V_51 = F_36 ( V_47 . V_42 , 0 , 1 ) ;
if ( V_51 )
goto V_84;
}
V_51 = F_23 ( V_71 -> V_78 ) ;
if ( V_51 )
goto V_85;
F_26 ( V_71 -> V_78 ) ;
F_37 ( 2 ) ;
V_51 = F_38 ( V_71 -> V_78 ) ;
if ( V_51 )
goto V_86;
F_39 ( & V_47 . V_73 ) ;
return 0 ;
V_86:
V_85:
if ( V_47 . V_42 )
F_40 ( V_47 . V_42 , true ) ;
V_84:
if ( V_47 . V_42 )
F_41 ( V_47 . V_42 ) ;
V_83:
V_82:
F_42 () ;
V_81:
if ( F_30 ( V_74 ) )
F_43 ( V_47 . V_75 ) ;
V_80:
V_79:
V_77:
F_39 ( & V_47 . V_73 ) ;
return V_51 ;
}
static void F_44 ( struct V_69 * V_70 )
{
struct V_55 * V_56 = V_47 . V_72 . V_78 ;
F_29 ( & V_47 . V_73 ) ;
F_45 ( V_56 ) ;
if ( V_47 . V_42 ) {
F_20 ( V_56 -> V_60 , V_20 ) ;
F_40 ( V_47 . V_42 , true ) ;
F_41 ( V_47 . V_42 ) ;
}
F_42 () ;
if ( F_30 ( V_74 ) )
F_43 ( V_47 . V_75 ) ;
F_39 ( & V_47 . V_73 ) ;
}
static void F_46 ( struct V_69 * V_70 ,
struct V_57 * V_59 )
{
F_47 ( L_4 ) ;
F_29 ( & V_47 . V_73 ) ;
V_47 . V_59 = * V_59 ;
F_39 ( & V_47 . V_73 ) ;
}
static void F_48 ( struct V_69 * V_70 ,
struct V_57 * V_59 )
{
F_29 ( & V_47 . V_73 ) ;
* V_59 = V_47 . V_59 ;
F_39 ( & V_47 . V_73 ) ;
}
static int F_49 ( struct V_69 * V_70 ,
struct V_57 * V_59 )
{
struct V_55 * V_56 = V_47 . V_72 . V_78 ;
int V_30 , V_31 ;
unsigned long V_43 ;
unsigned long V_24 ;
struct V_26 V_27 ;
bool V_49 ;
if ( V_56 && ! F_50 ( V_56 -> V_60 , V_59 ) )
return - V_52 ;
if ( V_59 -> V_61 == 0 )
return - V_52 ;
if ( V_47 . V_42 ) {
V_49 = F_12 ( V_59 -> V_61 , & V_27 ) ;
if ( ! V_49 )
return - V_52 ;
V_43 = V_27 . V_34 . V_35 ;
} else {
V_49 = F_15 ( V_59 -> V_61 , & V_27 ) ;
if ( ! V_49 )
return - V_52 ;
V_43 = V_27 . V_43 ;
}
V_30 = V_27 . V_29 . V_30 ;
V_31 = V_27 . V_29 . V_31 ;
V_24 = V_43 / V_30 / V_31 ;
V_59 -> V_61 = V_24 ;
return 0 ;
}
static void F_51 ( struct V_69 * V_70 , int V_67 )
{
F_29 ( & V_47 . V_73 ) ;
V_47 . V_67 = V_67 ;
F_39 ( & V_47 . V_73 ) ;
}
static int F_52 ( struct V_1 * V_42 )
{
int V_51 ;
V_51 = F_35 ( V_42 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_36 ( V_42 , 0 , 1 ) ;
if ( V_51 ) {
F_41 ( V_42 ) ;
return V_51 ;
}
F_40 ( V_42 , true ) ;
F_41 ( V_42 ) ;
return 0 ;
}
static int F_53 ( void )
{
struct V_87 * V_88 ;
if ( ! F_30 ( V_74 ) )
return 0 ;
if ( V_47 . V_75 )
return 0 ;
V_88 = F_54 ( & V_47 . V_89 -> V_90 , L_5 ) ;
if ( F_55 ( V_88 ) ) {
if ( F_56 ( V_88 ) != - V_91 )
F_31 ( L_6 ) ;
return F_56 ( V_88 ) ;
}
V_47 . V_75 = V_88 ;
return 0 ;
}
static void F_57 ( void )
{
struct V_1 * V_42 ;
if ( V_47 . V_42 )
return;
V_42 = F_1 ( V_47 . V_72 . V_92 ) ;
if ( ! V_42 )
return;
if ( F_52 ( V_42 ) ) {
F_24 ( L_7 ) ;
return;
}
V_47 . V_42 = V_42 ;
}
static enum V_2 F_58 ( void )
{
switch ( F_2 () ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return V_13 ;
case V_10 :
case V_11 :
case V_12 :
return V_14 ;
case V_15 :
return V_16 ;
default:
F_24 ( L_8 ) ;
return V_13 ;
}
}
static int F_59 ( struct V_69 * V_70 ,
struct V_69 * V_93 )
{
struct V_55 * V_56 ;
int V_51 ;
V_51 = F_53 () ;
if ( V_51 )
return V_51 ;
F_57 () ;
V_56 = F_60 ( V_70 -> V_92 ) ;
if ( ! V_56 )
return - V_76 ;
V_51 = F_61 ( V_56 , V_70 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_62 ( V_70 , V_93 ) ;
if ( V_51 ) {
F_31 ( L_9 ,
V_93 -> V_94 ) ;
F_63 ( V_56 , V_70 ) ;
return V_51 ;
}
return 0 ;
}
static void F_64 ( struct V_69 * V_70 ,
struct V_69 * V_93 )
{
F_5 ( V_93 != V_70 -> V_93 ) ;
if ( V_93 != V_70 -> V_93 )
return;
F_65 ( V_70 ) ;
if ( V_70 -> V_78 )
F_63 ( V_70 -> V_78 , V_70 ) ;
}
static void F_66 ( struct V_1 * V_89 )
{
struct V_69 * V_71 = & V_47 . V_72 ;
V_71 -> V_90 = & V_89 -> V_90 ;
V_71 -> V_60 = V_95 ;
V_71 -> V_96 = V_97 ;
V_71 -> V_94 = L_10 ;
V_71 -> V_92 = F_58 () ;
V_71 -> V_98 . V_47 = & V_99 ;
V_71 -> V_100 = V_101 ;
F_67 ( V_71 ) ;
}
static void T_1 F_68 ( struct V_1 * V_89 )
{
struct V_69 * V_71 = & V_47 . V_72 ;
F_69 ( V_71 ) ;
}
static int F_70 ( struct V_1 * V_89 )
{
V_47 . V_89 = V_89 ;
F_71 ( & V_47 . V_73 ) ;
F_66 ( V_89 ) ;
return 0 ;
}
static int T_1 F_72 ( struct V_1 * V_89 )
{
F_68 ( V_89 ) ;
return 0 ;
}
int T_2 F_73 ( void )
{
return F_74 ( & V_102 ) ;
}
void T_1 F_75 ( void )
{
F_76 ( & V_102 ) ;
}
int T_2 F_77 ( struct V_1 * V_89 , struct V_103 * V_104 )
{
struct V_103 * V_105 ;
T_3 V_106 ;
int V_51 ;
V_105 = F_78 ( V_104 , NULL ) ;
if ( ! V_105 )
return 0 ;
V_51 = F_79 ( V_105 , L_11 , & V_106 ) ;
if ( V_51 ) {
F_31 ( L_12 ) ;
goto V_107;
}
V_47 . V_67 = V_106 ;
F_80 ( V_105 ) ;
V_47 . V_89 = V_89 ;
F_71 ( & V_47 . V_73 ) ;
F_66 ( V_89 ) ;
V_47 . V_108 = true ;
return 0 ;
V_107:
F_80 ( V_105 ) ;
return V_51 ;
}
void T_1 F_81 ( void )
{
if ( ! V_47 . V_108 )
return;
F_68 ( V_47 . V_89 ) ;
}
