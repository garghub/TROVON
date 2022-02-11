static struct V_1 * F_1 ( enum V_2 V_3 )
{
switch ( F_2 () ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return NULL ;
case V_9 :
case V_10 :
case V_11 :
switch ( V_3 ) {
case V_12 :
return F_3 ( 0 ) ;
case V_13 :
return F_3 ( 1 ) ;
default:
return NULL ;
}
case V_14 :
switch ( V_3 ) {
case V_12 :
return F_3 ( 0 ) ;
case V_15 :
return F_3 ( 1 ) ;
default:
return NULL ;
}
default:
return NULL ;
}
}
static enum V_16 F_4 ( enum V_2 V_3 )
{
switch ( V_3 ) {
case V_12 :
return V_17 ;
case V_13 :
return V_18 ;
default:
F_5 ( 1 ) ;
return V_19 ;
}
}
static bool F_6 ( int V_20 , int V_21 , unsigned long V_22 ,
unsigned long V_23 , void * V_24 )
{
struct V_25 * V_26 = V_24 ;
if ( V_26 -> V_27 >= 1000000 ) {
if ( V_20 > 1 && V_20 % 2 != 0 )
return false ;
if ( V_21 > 1 && V_21 % 2 != 0 )
return false ;
}
V_26 -> V_28 . V_29 = V_20 ;
V_26 -> V_28 . V_30 = V_21 ;
V_26 -> V_28 . V_22 = V_22 ;
V_26 -> V_28 . V_23 = V_23 ;
return true ;
}
static bool F_7 ( int V_31 , unsigned long V_32 ,
void * V_24 )
{
struct V_25 * V_26 = V_24 ;
if ( V_31 > 1 && V_31 % 2 != 0 && V_26 -> V_27 >= 1000000 )
return false ;
V_26 -> V_33 . V_31 = V_31 ;
V_26 -> V_33 . V_34 = V_32 ;
return F_8 ( V_32 , V_26 -> V_27 , V_26 -> V_35 ,
F_6 , V_26 ) ;
}
static bool F_9 ( int V_36 , int V_37 , unsigned long V_38 ,
unsigned long V_39 ,
void * V_24 )
{
struct V_25 * V_26 = V_24 ;
V_26 -> V_33 . V_36 = V_36 ;
V_26 -> V_33 . V_37 = V_37 ;
V_26 -> V_33 . V_38 = V_38 ;
V_26 -> V_33 . V_40 = V_39 ;
return F_10 ( V_26 -> V_41 , V_39 , V_26 -> V_27 ,
F_7 , V_26 ) ;
}
static bool F_11 ( int V_42 , unsigned long V_43 , void * V_24 )
{
struct V_25 * V_26 = V_24 ;
V_26 -> V_44 . V_43 = V_43 ;
V_26 -> V_44 . V_45 = V_42 ;
return F_8 ( V_43 , V_26 -> V_27 , V_26 -> V_35 ,
F_6 , V_26 ) ;
}
static bool F_12 ( unsigned long V_23 , struct V_25 * V_26 )
{
unsigned long V_46 ;
unsigned long V_47 , V_48 ;
V_46 = F_13 ( V_49 . V_41 ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_41 = V_49 . V_41 ;
V_26 -> V_27 = V_23 - 1000 ;
V_26 -> V_35 = V_23 + 1000 ;
V_26 -> V_33 . V_46 = V_46 ;
V_47 = 0 ;
V_48 = 0 ;
return F_14 ( V_49 . V_41 , V_46 ,
V_47 , V_48 ,
F_9 , V_26 ) ;
}
static bool F_15 ( unsigned long V_23 , struct V_25 * V_26 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < 25 ; ++ V_50 ) {
bool V_51 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
if ( V_23 > 1000 * V_50 * V_50 * V_50 )
V_26 -> V_27 = F_16 ( V_23 - 1000 * V_50 * V_50 * V_50 , 0lu ) ;
else
V_26 -> V_27 = 0 ;
V_26 -> V_35 = V_23 + 1000 * V_50 * V_50 * V_50 ;
V_51 = F_17 ( V_26 -> V_27 , F_11 , V_26 ) ;
if ( V_51 )
return V_51 ;
}
return false ;
}
static int F_18 ( enum V_2 V_3 ,
unsigned long V_52 , unsigned long * V_43 , int * V_29 ,
int * V_30 )
{
struct V_25 V_26 ;
int V_53 ;
bool V_51 ;
V_51 = F_12 ( V_52 , & V_26 ) ;
if ( ! V_51 )
return - V_54 ;
V_53 = F_19 ( V_49 . V_41 , & V_26 . V_33 ) ;
if ( V_53 )
return V_53 ;
F_20 ( V_3 ,
F_4 ( V_3 ) ) ;
V_49 . V_55 . V_56 = V_26 . V_28 ;
* V_43 = V_26 . V_33 . V_34 ;
* V_29 = V_26 . V_28 . V_29 ;
* V_30 = V_26 . V_28 . V_30 ;
return 0 ;
}
static int F_21 ( unsigned long V_52 , unsigned long * V_43 ,
int * V_29 , int * V_30 )
{
struct V_25 V_26 ;
int V_53 ;
bool V_51 ;
V_51 = F_15 ( V_52 , & V_26 ) ;
if ( ! V_51 )
return - V_54 ;
V_53 = F_22 ( & V_26 . V_44 ) ;
if ( V_53 )
return V_53 ;
V_49 . V_55 . V_56 = V_26 . V_28 ;
* V_43 = V_26 . V_44 . V_43 ;
* V_29 = V_26 . V_28 . V_29 ;
* V_30 = V_26 . V_28 . V_30 ;
return 0 ;
}
static int F_23 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = & V_49 . V_61 ;
int V_29 = 0 , V_30 = 0 ;
unsigned long V_43 = 0 ;
unsigned long V_23 ;
int V_53 = 0 ;
if ( V_49 . V_41 )
V_53 = F_18 ( V_58 -> V_62 , V_60 -> V_63 * 1000 , & V_43 ,
& V_29 , & V_30 ) ;
else
V_53 = F_21 ( V_60 -> V_63 * 1000 , & V_43 ,
& V_29 , & V_30 ) ;
if ( V_53 )
return V_53 ;
V_23 = V_43 / V_29 / V_30 / 1000 ;
if ( V_23 != V_60 -> V_63 ) {
F_24 ( L_1
L_2 ,
V_60 -> V_63 , V_23 ) ;
V_60 -> V_63 = V_23 ;
}
F_25 ( V_58 , V_60 ) ;
return 0 ;
}
static void F_26 ( struct V_57 * V_58 )
{
V_49 . V_55 . V_64 = V_65 ;
V_49 . V_55 . V_66 = false ;
V_49 . V_55 . V_67 = false ;
V_49 . V_55 . V_68 = V_49 . V_69 ;
V_49 . V_55 . V_70 = 0 ;
F_27 ( V_58 , & V_49 . V_55 ) ;
}
int F_28 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = & V_49 . V_75 ;
int V_53 ;
F_29 ( & V_49 . V_76 ) ;
if ( F_30 ( V_77 ) && ! V_49 . V_78 ) {
F_31 ( L_3 ) ;
V_53 = - V_79 ;
goto V_80;
}
if ( V_74 == NULL || V_74 -> V_81 == NULL ) {
F_31 ( L_4 ) ;
V_53 = - V_79 ;
goto V_82;
}
V_53 = F_32 ( V_72 ) ;
if ( V_53 ) {
F_31 ( L_5 ) ;
goto V_83;
}
if ( F_30 ( V_77 ) ) {
V_53 = F_33 ( V_49 . V_78 ) ;
if ( V_53 )
goto V_84;
}
V_53 = F_34 () ;
if ( V_53 )
goto V_85;
V_53 = F_35 ( V_74 -> V_81 -> V_62 ) ;
if ( V_53 )
goto V_86;
if ( V_49 . V_41 ) {
V_53 = F_36 ( V_49 . V_41 ) ;
if ( V_53 )
goto V_87;
V_53 = F_37 ( V_49 . V_41 , 0 , 1 ) ;
if ( V_53 )
goto V_88;
}
V_53 = F_23 ( V_74 -> V_81 ) ;
if ( V_53 )
goto V_89;
F_26 ( V_74 -> V_81 ) ;
F_38 ( 2 ) ;
V_53 = F_39 ( V_74 -> V_81 ) ;
if ( V_53 )
goto V_90;
F_40 ( & V_49 . V_76 ) ;
return 0 ;
V_90:
V_89:
if ( V_49 . V_41 )
F_41 ( V_49 . V_41 , true ) ;
V_88:
if ( V_49 . V_41 )
F_42 ( V_49 . V_41 ) ;
V_87:
V_86:
F_43 () ;
V_85:
if ( F_30 ( V_77 ) )
F_44 ( V_49 . V_78 ) ;
V_84:
F_45 ( V_72 ) ;
V_83:
V_82:
V_80:
F_40 ( & V_49 . V_76 ) ;
return V_53 ;
}
void F_46 ( struct V_71 * V_72 )
{
struct V_57 * V_58 = V_49 . V_75 . V_81 ;
F_29 ( & V_49 . V_76 ) ;
F_47 ( V_58 ) ;
if ( V_49 . V_41 ) {
F_20 ( V_58 -> V_62 , V_19 ) ;
F_41 ( V_49 . V_41 , true ) ;
F_42 ( V_49 . V_41 ) ;
}
F_43 () ;
if ( F_30 ( V_77 ) )
F_44 ( V_49 . V_78 ) ;
F_45 ( V_72 ) ;
F_40 ( & V_49 . V_76 ) ;
}
void F_48 ( struct V_71 * V_72 ,
struct V_59 * V_61 )
{
F_49 ( L_6 ) ;
F_29 ( & V_49 . V_76 ) ;
V_49 . V_61 = * V_61 ;
F_40 ( & V_49 . V_76 ) ;
}
int F_50 ( struct V_71 * V_72 ,
struct V_59 * V_61 )
{
struct V_57 * V_58 = V_49 . V_75 . V_81 ;
int V_29 , V_30 ;
unsigned long V_43 ;
unsigned long V_23 ;
struct V_25 V_26 ;
bool V_51 ;
if ( V_58 && ! F_51 ( V_58 -> V_62 , V_61 ) )
return - V_54 ;
if ( V_61 -> V_63 == 0 )
return - V_54 ;
if ( V_49 . V_41 ) {
V_51 = F_12 ( V_61 -> V_63 * 1000 , & V_26 ) ;
if ( ! V_51 )
return - V_54 ;
V_43 = V_26 . V_33 . V_34 ;
} else {
V_51 = F_15 ( V_61 -> V_63 * 1000 , & V_26 ) ;
if ( ! V_51 )
return - V_54 ;
V_43 = V_26 . V_44 . V_43 ;
}
V_29 = V_26 . V_28 . V_29 ;
V_30 = V_26 . V_28 . V_30 ;
V_23 = V_43 / V_29 / V_30 / 1000 ;
V_61 -> V_63 = V_23 ;
return 0 ;
}
void F_52 ( struct V_71 * V_72 , int V_69 )
{
F_29 ( & V_49 . V_76 ) ;
V_49 . V_69 = V_69 ;
F_40 ( & V_49 . V_76 ) ;
}
static int F_53 ( struct V_1 * V_41 )
{
int V_53 ;
V_53 = F_36 ( V_41 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_37 ( V_41 , 0 , 1 ) ;
if ( V_53 ) {
F_42 ( V_41 ) ;
return V_53 ;
}
F_41 ( V_41 , true ) ;
F_42 ( V_41 ) ;
return 0 ;
}
static enum V_2 F_54 ( void )
{
switch ( F_2 () ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return V_12 ;
case V_9 :
case V_10 :
case V_11 :
return V_13 ;
case V_14 :
return V_15 ;
default:
F_24 ( L_7 ) ;
return V_12 ;
}
}
static int F_55 ( struct V_71 * V_72 )
{
struct V_1 * V_41 ;
F_49 ( L_8 ) ;
if ( F_30 ( V_77 ) &&
V_49 . V_78 == NULL ) {
struct V_91 * V_92 ;
V_92 = F_56 () ;
if ( F_57 ( V_92 ) ) {
F_31 ( L_9 ) ;
return F_58 ( V_92 ) ;
}
V_49 . V_78 = V_92 ;
}
V_41 = F_1 ( V_49 . V_75 . V_93 ) ;
if ( V_41 && F_53 ( V_41 ) ) {
V_41 = NULL ;
F_24 ( L_10 ) ;
}
if ( V_41 )
F_49 ( L_11 ) ;
V_49 . V_41 = V_41 ;
return 0 ;
}
static struct V_71 * F_59 ( struct V_1 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 . V_98 ;
const char * V_99 = F_60 () ;
struct V_71 * V_100 ;
int V_50 ;
V_100 = NULL ;
for ( V_50 = 0 ; V_50 < V_96 -> V_101 ; ++ V_50 ) {
struct V_71 * V_72 = V_96 -> V_102 [ V_50 ] ;
if ( V_72 -> type != V_103 )
continue;
if ( V_100 == NULL )
V_100 = V_72 ;
if ( V_99 != NULL &&
strcmp ( V_72 -> V_104 , V_99 ) == 0 ) {
V_100 = V_72 ;
break;
}
}
return V_100 ;
}
static int F_61 ( struct V_1 * V_105 )
{
struct V_71 * V_106 ;
struct V_71 * V_72 ;
int V_53 ;
V_106 = F_59 ( V_105 ) ;
if ( ! V_106 )
return 0 ;
V_72 = F_62 ( & V_105 -> V_97 ) ;
if ( ! V_72 )
return - V_107 ;
F_63 ( V_72 , V_106 ) ;
V_53 = F_55 ( V_72 ) ;
if ( V_53 ) {
F_31 ( L_12 , V_72 -> V_104 , V_53 ) ;
F_64 ( V_72 ) ;
return V_53 ;
}
V_53 = F_65 ( & V_49 . V_75 , V_72 ) ;
if ( V_53 ) {
F_31 ( L_13 ,
V_72 -> V_104 ) ;
F_64 ( V_72 ) ;
return V_53 ;
}
V_53 = F_66 ( V_72 ) ;
if ( V_53 ) {
F_31 ( L_14 , V_72 -> V_104 , V_53 ) ;
F_67 ( & V_49 . V_75 ) ;
F_64 ( V_72 ) ;
return V_53 ;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_94 )
{
struct V_73 * V_74 = & V_49 . V_75 ;
V_74 -> V_94 = V_94 ;
V_74 -> V_62 = V_108 ;
V_74 -> type = V_103 ;
V_74 -> V_104 = L_15 ;
V_74 -> V_93 = F_54 () ;
F_69 ( V_74 ) ;
}
static void T_1 F_70 ( struct V_1 * V_94 )
{
struct V_73 * V_74 = & V_49 . V_75 ;
F_71 ( V_74 ) ;
}
static int F_72 ( struct V_1 * V_94 )
{
int V_53 ;
F_73 ( & V_49 . V_76 ) ;
F_68 ( V_94 ) ;
V_53 = F_61 ( V_94 ) ;
if ( V_53 ) {
F_70 ( V_94 ) ;
return V_53 ;
}
return 0 ;
}
static int T_1 F_74 ( struct V_1 * V_94 )
{
F_75 ( & V_94 -> V_97 ) ;
F_70 ( V_94 ) ;
return 0 ;
}
int T_2 F_76 ( void )
{
return F_77 ( & V_109 ) ;
}
void T_1 F_78 ( void )
{
F_79 ( & V_109 ) ;
}
