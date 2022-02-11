static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_4 ( & V_6 -> V_7 ) ;
}
static struct V_8 * F_5 ( enum V_9 V_10 )
{
switch ( F_6 () ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
return NULL ;
case V_17 :
case V_18 :
case V_19 :
switch ( V_10 ) {
case V_20 :
return F_7 ( L_1 ) ;
case V_21 :
return F_7 ( L_2 ) ;
default:
return NULL ;
}
case V_22 :
switch ( V_10 ) {
case V_20 :
return F_7 ( L_1 ) ;
case V_23 :
return F_7 ( L_2 ) ;
default:
return NULL ;
}
default:
return NULL ;
}
}
static enum V_24 F_8 ( enum V_9 V_10 )
{
switch ( V_10 ) {
case V_20 :
return V_25 ;
case V_21 :
return V_26 ;
case V_23 :
return V_26 ;
default:
F_9 ( 1 ) ;
return V_27 ;
}
}
static bool F_10 ( int V_28 , int V_29 , unsigned long V_30 ,
unsigned long V_31 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
if ( V_34 -> V_35 >= 100000000 ) {
if ( V_28 > 1 && V_28 % 2 != 0 )
return false ;
if ( V_29 > 1 && V_29 % 2 != 0 )
return false ;
}
V_34 -> V_36 . V_37 = V_28 ;
V_34 -> V_36 . V_38 = V_29 ;
V_34 -> V_36 . V_30 = V_30 ;
V_34 -> V_36 . V_31 = V_31 ;
return true ;
}
static bool F_11 ( int V_39 , unsigned long V_40 ,
void * V_32 )
{
struct V_33 * V_34 = V_32 ;
if ( V_39 > 1 && V_39 % 2 != 0 && V_34 -> V_35 >= 100000000 )
return false ;
V_34 -> V_41 . V_42 [ V_43 ] = V_39 ;
V_34 -> V_41 . V_44 [ V_43 ] = V_40 ;
return F_12 ( V_40 , V_34 -> V_35 , V_34 -> V_45 ,
F_10 , V_34 ) ;
}
static bool F_13 ( int V_46 , int V_47 , unsigned long V_48 ,
unsigned long V_49 ,
void * V_32 )
{
struct V_33 * V_34 = V_32 ;
V_34 -> V_41 . V_46 = V_46 ;
V_34 -> V_41 . V_47 = V_47 ;
V_34 -> V_41 . V_48 = V_48 ;
V_34 -> V_41 . V_49 = V_49 ;
return F_14 ( V_34 -> V_50 , V_49 ,
V_34 -> V_35 , F_15 ( V_51 ) ,
F_11 , V_34 ) ;
}
static bool F_16 ( unsigned long V_52 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
V_34 -> V_52 = V_52 ;
return F_12 ( V_52 , V_34 -> V_35 , V_34 -> V_45 ,
F_10 , V_34 ) ;
}
static bool F_17 ( struct V_1 * V_53 , unsigned long V_31 ,
struct V_33 * V_34 )
{
unsigned long V_54 ;
unsigned long V_55 , V_56 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_50 = V_53 -> V_50 ;
V_34 -> V_35 = V_31 - 1000 ;
V_34 -> V_45 = V_31 + 1000 ;
V_55 = 0 ;
V_56 = 0 ;
V_54 = F_18 ( V_34 -> V_50 -> V_54 ) ;
return F_19 ( V_34 -> V_50 , V_54 ,
V_55 , V_56 ,
F_13 , V_34 ) ;
}
static bool F_20 ( unsigned long V_31 , struct V_33 * V_34 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < 25 ; ++ V_57 ) {
bool V_58 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
if ( V_31 > 1000 * V_57 * V_57 * V_57 )
V_34 -> V_35 = F_21 ( V_31 - 1000 * V_57 * V_57 * V_57 , 0lu ) ;
else
V_34 -> V_35 = 0 ;
V_34 -> V_45 = V_31 + 1000 * V_57 * V_57 * V_57 ;
V_58 = F_22 ( V_31 , V_34 -> V_35 , F_16 , V_34 ) ;
if ( V_58 )
return V_58 ;
}
return false ;
}
static int F_23 ( struct V_1 * V_53 , enum V_9 V_10 ,
unsigned long V_59 , unsigned long * V_52 , int * V_37 ,
int * V_38 )
{
struct V_33 V_34 ;
int V_60 ;
bool V_58 ;
V_58 = F_17 ( V_53 , V_59 , & V_34 ) ;
if ( ! V_58 )
return - V_61 ;
V_60 = F_24 ( V_53 -> V_50 , & V_34 . V_41 ) ;
if ( V_60 )
return V_60 ;
F_25 ( V_10 ,
F_8 ( V_10 ) ) ;
V_53 -> V_62 . V_63 = V_34 . V_36 ;
* V_52 = V_34 . V_41 . V_44 [ V_43 ] ;
* V_37 = V_34 . V_36 . V_37 ;
* V_38 = V_34 . V_36 . V_38 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_53 , unsigned long V_59 ,
unsigned long * V_52 , int * V_37 , int * V_38 )
{
struct V_33 V_34 ;
int V_60 ;
bool V_58 ;
V_58 = F_20 ( V_59 , & V_34 ) ;
if ( ! V_58 )
return - V_61 ;
V_60 = F_27 ( V_34 . V_52 ) ;
if ( V_60 )
return V_60 ;
V_53 -> V_62 . V_63 = V_34 . V_36 ;
* V_52 = V_34 . V_52 ;
* V_37 = V_34 . V_36 . V_37 ;
* V_38 = V_34 . V_36 . V_38 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_53 )
{
struct V_2 * V_64 = & V_53 -> V_4 ;
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_68 * V_69 = & V_53 -> V_70 ;
int V_37 = 0 , V_38 = 0 ;
unsigned long V_52 = 0 ;
unsigned long V_31 ;
int V_60 = 0 ;
if ( V_53 -> V_50 )
V_60 = F_23 ( V_53 , V_66 -> V_71 , V_69 -> V_72 , & V_52 ,
& V_37 , & V_38 ) ;
else
V_60 = F_26 ( V_53 , V_69 -> V_72 , & V_52 ,
& V_37 , & V_38 ) ;
if ( V_60 )
return V_60 ;
V_31 = V_52 / V_37 / V_38 ;
if ( V_31 != V_69 -> V_72 ) {
F_29 ( L_3 ,
V_69 -> V_72 , V_31 ) ;
V_69 -> V_72 = V_31 ;
}
F_30 ( V_66 , V_69 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_53 )
{
struct V_2 * V_64 = & V_53 -> V_4 ;
struct V_65 * V_66 = V_64 -> V_67 ;
V_53 -> V_62 . V_73 = V_74 ;
V_53 -> V_62 . V_75 = false ;
V_53 -> V_62 . V_76 = false ;
V_53 -> V_62 . V_77 = V_53 -> V_78 ;
V_53 -> V_62 . V_79 = 0 ;
F_32 ( V_66 , & V_53 -> V_62 ) ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_2 * V_64 = & V_53 -> V_4 ;
int V_60 ;
F_34 ( & V_53 -> V_80 ) ;
if ( F_35 ( V_81 ) && ! V_53 -> V_82 ) {
F_36 ( L_4 ) ;
V_60 = - V_83 ;
goto V_84;
}
if ( V_64 == NULL || V_64 -> V_67 == NULL ) {
F_36 ( L_5 ) ;
V_60 = - V_83 ;
goto V_85;
}
if ( F_35 ( V_81 ) ) {
V_60 = F_37 ( V_53 -> V_82 ) ;
if ( V_60 )
goto V_86;
}
V_60 = F_38 () ;
if ( V_60 )
goto V_87;
V_60 = F_39 ( V_64 -> V_88 , V_64 -> V_67 -> V_71 ) ;
if ( V_60 )
goto V_89;
if ( V_53 -> V_50 ) {
V_60 = F_40 ( V_53 -> V_50 ) ;
if ( V_60 )
goto V_90;
}
V_60 = F_28 ( V_53 ) ;
if ( V_60 )
goto V_91;
F_31 ( V_53 ) ;
F_41 ( 2 ) ;
V_60 = F_42 ( V_64 -> V_67 ) ;
if ( V_60 )
goto V_92;
F_43 ( & V_53 -> V_80 ) ;
return 0 ;
V_92:
V_91:
if ( V_53 -> V_50 )
F_44 ( V_53 -> V_50 ) ;
V_90:
V_89:
F_45 () ;
V_87:
if ( F_35 ( V_81 ) )
F_46 ( V_53 -> V_82 ) ;
V_86:
V_85:
V_84:
F_43 ( & V_53 -> V_80 ) ;
return V_60 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_65 * V_66 = V_53 -> V_4 . V_67 ;
F_34 ( & V_53 -> V_80 ) ;
F_48 ( V_66 ) ;
if ( V_53 -> V_50 ) {
F_25 ( V_66 -> V_71 , V_27 ) ;
F_44 ( V_53 -> V_50 ) ;
}
F_45 () ;
if ( F_35 ( V_81 ) )
F_46 ( V_53 -> V_82 ) ;
F_43 ( & V_53 -> V_80 ) ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_68 * V_70 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
F_50 ( L_6 ) ;
F_34 ( & V_53 -> V_80 ) ;
V_53 -> V_70 = * V_70 ;
F_43 ( & V_53 -> V_80 ) ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_68 * V_70 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
F_34 ( & V_53 -> V_80 ) ;
* V_70 = V_53 -> V_70 ;
F_43 ( & V_53 -> V_80 ) ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_68 * V_70 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_65 * V_66 = V_53 -> V_4 . V_67 ;
int V_37 , V_38 ;
unsigned long V_52 ;
unsigned long V_31 ;
struct V_33 V_34 ;
bool V_58 ;
if ( V_66 && ! F_53 ( V_66 -> V_71 , V_70 ) )
return - V_61 ;
if ( V_70 -> V_72 == 0 )
return - V_61 ;
if ( V_53 -> V_50 ) {
V_58 = F_17 ( V_53 , V_70 -> V_72 , & V_34 ) ;
if ( ! V_58 )
return - V_61 ;
V_52 = V_34 . V_41 . V_44 [ V_43 ] ;
} else {
V_58 = F_20 ( V_70 -> V_72 , & V_34 ) ;
if ( ! V_58 )
return - V_61 ;
V_52 = V_34 . V_52 ;
}
V_37 = V_34 . V_36 . V_37 ;
V_38 = V_34 . V_36 . V_38 ;
V_31 = V_52 / V_37 / V_38 ;
V_70 -> V_72 = V_31 ;
return 0 ;
}
static void F_54 ( struct V_2 * V_3 , int V_78 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
F_34 ( & V_53 -> V_80 ) ;
V_53 -> V_78 = V_78 ;
F_43 ( & V_53 -> V_80 ) ;
}
static int F_55 ( struct V_8 * V_50 )
{
int V_60 ;
V_60 = F_40 ( V_50 ) ;
if ( V_60 )
return V_60 ;
F_44 ( V_50 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_53 )
{
struct V_93 * V_94 ;
if ( ! F_35 ( V_81 ) )
return 0 ;
if ( V_53 -> V_82 )
return 0 ;
V_94 = F_57 ( & V_53 -> V_6 -> V_7 , L_7 ) ;
if ( F_58 ( V_94 ) ) {
if ( F_59 ( V_94 ) != - V_95 )
F_36 ( L_8 ) ;
return F_59 ( V_94 ) ;
}
V_53 -> V_82 = V_94 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_53 )
{
struct V_8 * V_50 ;
if ( V_53 -> V_50 )
return;
V_50 = F_5 ( V_53 -> V_4 . V_96 ) ;
if ( ! V_50 )
return;
if ( F_55 ( V_50 ) ) {
F_29 ( L_9 ) ;
return;
}
V_53 -> V_50 = V_50 ;
}
static enum V_9 F_61 ( int V_88 )
{
switch ( F_6 () ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
return V_20 ;
case V_17 :
case V_18 :
case V_19 :
return V_21 ;
case V_22 :
return V_23 ;
default:
F_29 ( L_10 ) ;
return V_20 ;
}
}
static int F_62 ( struct V_2 * V_3 ,
struct V_2 * V_97 )
{
struct V_1 * V_53 = F_1 ( V_3 ) ;
struct V_65 * V_66 ;
int V_60 ;
V_60 = F_56 ( V_53 ) ;
if ( V_60 )
return V_60 ;
F_60 ( V_53 ) ;
V_66 = F_63 ( V_3 -> V_96 ) ;
if ( ! V_66 )
return - V_83 ;
V_60 = F_64 ( V_66 , V_3 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_65 ( V_3 , V_97 ) ;
if ( V_60 ) {
F_36 ( L_11 ,
V_97 -> V_98 ) ;
F_66 ( V_66 , V_3 ) ;
return V_60 ;
}
return 0 ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_2 * V_97 )
{
F_9 ( V_97 != V_3 -> V_97 ) ;
if ( V_97 != V_3 -> V_97 )
return;
F_68 ( V_3 ) ;
if ( V_3 -> V_67 )
F_66 ( V_3 -> V_67 , V_3 ) ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_53 = F_3 ( V_6 ) ;
struct V_2 * V_64 = & V_53 -> V_4 ;
V_64 -> V_7 = & V_6 -> V_7 ;
V_64 -> V_71 = V_99 ;
V_64 -> V_100 = V_101 ;
V_64 -> V_98 = L_12 ;
V_64 -> V_96 = F_61 ( 0 ) ;
V_64 -> V_102 . V_53 = & V_103 ;
V_64 -> V_104 = V_105 ;
F_70 ( V_64 ) ;
}
static void T_1 F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_53 = F_3 ( V_6 ) ;
struct V_2 * V_64 = & V_53 -> V_4 ;
F_72 ( V_64 ) ;
}
static void F_73 ( struct V_5 * V_6 ,
struct V_106 * V_107 )
{
struct V_1 * V_53 = V_107 -> V_32 ;
struct V_2 * V_64 = & V_53 -> V_4 ;
int V_60 ;
T_2 V_88 ;
V_60 = F_74 ( V_107 , L_13 , & V_88 ) ;
if ( V_60 )
V_88 = 0 ;
switch ( V_88 ) {
case 2 :
V_64 -> V_98 = L_14 ;
break;
case 1 :
V_64 -> V_98 = L_15 ;
break;
case 0 :
default:
V_64 -> V_98 = L_12 ;
break;
}
V_64 -> V_7 = & V_6 -> V_7 ;
V_64 -> V_71 = V_99 ;
V_64 -> V_100 = V_101 ;
V_64 -> V_96 = F_61 ( V_88 ) ;
V_64 -> V_88 = V_88 ;
V_64 -> V_102 . V_53 = & V_103 ;
V_64 -> V_104 = V_105 ;
F_70 ( V_64 ) ;
}
static void T_1 F_75 ( struct V_106 * V_107 )
{
struct V_1 * V_53 = V_107 -> V_32 ;
struct V_2 * V_64 = & V_53 -> V_4 ;
F_72 ( V_64 ) ;
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_1 * V_53 ;
V_53 = F_77 ( & V_6 -> V_7 , sizeof( * V_53 ) , V_108 ) ;
if ( ! V_53 )
return - V_109 ;
V_53 -> V_6 = V_6 ;
F_78 ( & V_6 -> V_7 , V_53 ) ;
F_79 ( & V_53 -> V_80 ) ;
F_69 ( V_6 ) ;
return 0 ;
}
static int T_1 F_80 ( struct V_5 * V_6 )
{
F_71 ( V_6 ) ;
return 0 ;
}
int T_3 F_81 ( void )
{
return F_82 ( & V_110 ) ;
}
void T_1 F_83 ( void )
{
F_84 ( & V_110 ) ;
}
int T_3 F_85 ( struct V_5 * V_6 , struct V_106 * V_107 )
{
struct V_1 * V_53 ;
struct V_106 * V_111 ;
T_2 V_112 ;
int V_60 ;
V_53 = F_77 ( & V_6 -> V_7 , sizeof( * V_53 ) , V_108 ) ;
if ( ! V_53 )
return - V_109 ;
V_111 = F_86 ( V_107 , NULL ) ;
if ( ! V_111 )
return 0 ;
V_60 = F_74 ( V_111 , L_16 , & V_112 ) ;
if ( V_60 ) {
F_36 ( L_17 ) ;
goto V_113;
}
V_53 -> V_78 = V_112 ;
F_87 ( V_111 ) ;
V_53 -> V_6 = V_6 ;
V_107 -> V_32 = V_53 ;
F_79 ( & V_53 -> V_80 ) ;
F_73 ( V_6 , V_107 ) ;
V_53 -> V_114 = true ;
return 0 ;
V_113:
F_87 ( V_111 ) ;
return V_60 ;
}
void T_1 F_88 ( struct V_106 * V_107 )
{
struct V_1 * V_53 = V_107 -> V_32 ;
if ( ! V_53 -> V_114 )
return;
F_75 ( V_107 ) ;
}
