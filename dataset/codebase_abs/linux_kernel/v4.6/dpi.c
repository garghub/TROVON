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
case V_24 :
switch ( V_10 ) {
case V_20 :
case V_21 :
return F_7 ( L_3 ) ;
case V_23 :
return F_7 ( L_4 ) ;
default:
return NULL ;
}
default:
return NULL ;
}
}
static enum V_25 F_8 ( enum V_9 V_10 )
{
switch ( V_10 ) {
case V_20 :
return V_26 ;
case V_21 :
return V_27 ;
case V_23 :
return V_27 ;
default:
F_9 ( 1 ) ;
return V_28 ;
}
}
static bool F_10 ( int V_29 , int V_30 , unsigned long V_31 ,
unsigned long V_32 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
if ( V_35 -> V_36 >= 100000000 ) {
if ( V_29 > 1 && V_29 % 2 != 0 )
return false ;
if ( V_30 > 1 && V_30 % 2 != 0 )
return false ;
}
V_35 -> V_37 . V_38 = V_29 ;
V_35 -> V_37 . V_39 = V_30 ;
V_35 -> V_37 . V_31 = V_31 ;
V_35 -> V_37 . V_32 = V_32 ;
return true ;
}
static bool F_11 ( int V_40 , unsigned long V_41 ,
void * V_33 )
{
struct V_34 * V_35 = V_33 ;
if ( V_40 > 1 && V_40 % 2 != 0 && V_35 -> V_36 >= 100000000 )
return false ;
V_35 -> V_42 . V_43 [ V_44 ] = V_40 ;
V_35 -> V_42 . V_45 [ V_44 ] = V_41 ;
return F_12 ( V_41 , V_35 -> V_36 , V_35 -> V_46 ,
F_10 , V_35 ) ;
}
static bool F_13 ( int V_47 , int V_48 , unsigned long V_49 ,
unsigned long V_50 ,
void * V_33 )
{
struct V_34 * V_35 = V_33 ;
V_35 -> V_42 . V_47 = V_47 ;
V_35 -> V_42 . V_48 = V_48 ;
V_35 -> V_42 . V_49 = V_49 ;
V_35 -> V_42 . V_50 = V_50 ;
return F_14 ( V_35 -> V_51 , V_50 ,
V_35 -> V_36 , F_15 ( V_52 ) ,
F_11 , V_35 ) ;
}
static bool F_16 ( unsigned long V_53 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
V_35 -> V_53 = V_53 ;
return F_12 ( V_53 , V_35 -> V_36 , V_35 -> V_46 ,
F_10 , V_35 ) ;
}
static bool F_17 ( struct V_1 * V_54 , unsigned long V_32 ,
struct V_34 * V_35 )
{
unsigned long V_55 ;
unsigned long V_56 , V_57 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_51 = V_54 -> V_51 ;
V_35 -> V_36 = V_32 - 1000 ;
V_35 -> V_46 = V_32 + 1000 ;
V_56 = 0 ;
V_57 = 0 ;
V_55 = F_18 ( V_35 -> V_51 -> V_55 ) ;
return F_19 ( V_35 -> V_51 , V_55 ,
V_56 , V_57 ,
F_13 , V_35 ) ;
}
static bool F_20 ( unsigned long V_32 , struct V_34 * V_35 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < 25 ; ++ V_58 ) {
bool V_59 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
if ( V_32 > 1000 * V_58 * V_58 * V_58 )
V_35 -> V_36 = F_21 ( V_32 - 1000 * V_58 * V_58 * V_58 , 0lu ) ;
else
V_35 -> V_36 = 0 ;
V_35 -> V_46 = V_32 + 1000 * V_58 * V_58 * V_58 ;
V_59 = F_22 ( V_32 , V_35 -> V_36 , F_16 , V_35 ) ;
if ( V_59 )
return V_59 ;
}
return false ;
}
static int F_23 ( struct V_1 * V_54 , enum V_9 V_10 ,
unsigned long V_60 , unsigned long * V_53 , int * V_38 ,
int * V_39 )
{
struct V_34 V_35 ;
int V_61 ;
bool V_59 ;
V_59 = F_17 ( V_54 , V_60 , & V_35 ) ;
if ( ! V_59 )
return - V_62 ;
V_61 = F_24 ( V_54 -> V_51 , & V_35 . V_42 ) ;
if ( V_61 )
return V_61 ;
F_25 ( V_10 ,
F_8 ( V_10 ) ) ;
V_54 -> V_63 . V_64 = V_35 . V_37 ;
* V_53 = V_35 . V_42 . V_45 [ V_44 ] ;
* V_38 = V_35 . V_37 . V_38 ;
* V_39 = V_35 . V_37 . V_39 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_54 , unsigned long V_60 ,
unsigned long * V_53 , int * V_38 , int * V_39 )
{
struct V_34 V_35 ;
int V_61 ;
bool V_59 ;
V_59 = F_20 ( V_60 , & V_35 ) ;
if ( ! V_59 )
return - V_62 ;
V_61 = F_27 ( V_35 . V_53 ) ;
if ( V_61 )
return V_61 ;
V_54 -> V_63 . V_64 = V_35 . V_37 ;
* V_53 = V_35 . V_53 ;
* V_38 = V_35 . V_37 . V_38 ;
* V_39 = V_35 . V_37 . V_39 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_54 )
{
struct V_2 * V_65 = & V_54 -> V_4 ;
enum V_9 V_10 = V_65 -> V_66 ;
struct V_67 * V_68 = & V_54 -> V_69 ;
int V_38 = 0 , V_39 = 0 ;
unsigned long V_53 = 0 ;
unsigned long V_32 ;
int V_61 = 0 ;
if ( V_54 -> V_51 )
V_61 = F_23 ( V_54 , V_10 , V_68 -> V_70 , & V_53 ,
& V_38 , & V_39 ) ;
else
V_61 = F_26 ( V_54 , V_68 -> V_70 , & V_53 ,
& V_38 , & V_39 ) ;
if ( V_61 )
return V_61 ;
V_32 = V_53 / V_38 / V_39 ;
if ( V_32 != V_68 -> V_70 ) {
F_29 ( L_5 ,
V_68 -> V_70 , V_32 ) ;
V_68 -> V_70 = V_32 ;
}
F_30 ( V_10 , V_68 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_54 )
{
struct V_2 * V_65 = & V_54 -> V_4 ;
enum V_9 V_10 = V_65 -> V_66 ;
V_54 -> V_63 . V_71 = V_72 ;
V_54 -> V_63 . V_73 = false ;
V_54 -> V_63 . V_74 = false ;
V_54 -> V_63 . V_75 = V_54 -> V_76 ;
V_54 -> V_63 . V_77 = 0 ;
F_32 ( V_10 , & V_54 -> V_63 ) ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
struct V_2 * V_65 = & V_54 -> V_4 ;
enum V_9 V_10 = V_65 -> V_66 ;
int V_61 ;
F_34 ( & V_54 -> V_78 ) ;
if ( F_35 ( V_79 ) && ! V_54 -> V_80 ) {
F_36 ( L_6 ) ;
V_61 = - V_81 ;
goto V_82;
}
if ( ! V_65 -> V_83 ) {
F_36 ( L_7 ) ;
V_61 = - V_81 ;
goto V_84;
}
if ( F_35 ( V_79 ) ) {
V_61 = F_37 ( V_54 -> V_80 ) ;
if ( V_61 )
goto V_85;
}
V_61 = F_38 () ;
if ( V_61 )
goto V_86;
V_61 = F_39 ( V_65 -> V_87 , V_10 ) ;
if ( V_61 )
goto V_88;
if ( V_54 -> V_51 ) {
V_61 = F_40 ( V_54 -> V_51 ) ;
if ( V_61 )
goto V_89;
}
V_61 = F_28 ( V_54 ) ;
if ( V_61 )
goto V_90;
F_31 ( V_54 ) ;
F_41 ( 2 ) ;
V_61 = F_42 ( V_10 ) ;
if ( V_61 )
goto V_91;
F_43 ( & V_54 -> V_78 ) ;
return 0 ;
V_91:
V_90:
if ( V_54 -> V_51 )
F_44 ( V_54 -> V_51 ) ;
V_89:
V_88:
F_45 () ;
V_86:
if ( F_35 ( V_79 ) )
F_46 ( V_54 -> V_80 ) ;
V_85:
V_84:
V_82:
F_43 ( & V_54 -> V_78 ) ;
return V_61 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_54 -> V_4 . V_66 ;
F_34 ( & V_54 -> V_78 ) ;
F_48 ( V_10 ) ;
if ( V_54 -> V_51 ) {
F_25 ( V_10 , V_28 ) ;
F_44 ( V_54 -> V_51 ) ;
}
F_45 () ;
if ( F_35 ( V_79 ) )
F_46 ( V_54 -> V_80 ) ;
F_43 ( & V_54 -> V_78 ) ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_67 * V_69 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
F_50 ( L_8 ) ;
F_34 ( & V_54 -> V_78 ) ;
V_54 -> V_69 = * V_69 ;
F_43 ( & V_54 -> V_78 ) ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_67 * V_69 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
F_34 ( & V_54 -> V_78 ) ;
* V_69 = V_54 -> V_69 ;
F_43 ( & V_54 -> V_78 ) ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_67 * V_69 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_54 -> V_4 . V_66 ;
int V_38 , V_39 ;
unsigned long V_53 ;
unsigned long V_32 ;
struct V_34 V_35 ;
bool V_59 ;
if ( V_69 -> V_92 % 8 != 0 )
return - V_62 ;
if ( ! F_53 ( V_10 , V_69 ) )
return - V_62 ;
if ( V_69 -> V_70 == 0 )
return - V_62 ;
if ( V_54 -> V_51 ) {
V_59 = F_17 ( V_54 , V_69 -> V_70 , & V_35 ) ;
if ( ! V_59 )
return - V_62 ;
V_53 = V_35 . V_42 . V_45 [ V_44 ] ;
} else {
V_59 = F_20 ( V_69 -> V_70 , & V_35 ) ;
if ( ! V_59 )
return - V_62 ;
V_53 = V_35 . V_53 ;
}
V_38 = V_35 . V_37 . V_38 ;
V_39 = V_35 . V_37 . V_39 ;
V_32 = V_53 / V_38 / V_39 ;
V_69 -> V_70 = V_32 ;
return 0 ;
}
static void F_54 ( struct V_2 * V_3 , int V_76 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
F_34 ( & V_54 -> V_78 ) ;
V_54 -> V_76 = V_76 ;
F_43 ( & V_54 -> V_78 ) ;
}
static int F_55 ( struct V_8 * V_51 )
{
int V_61 ;
V_61 = F_40 ( V_51 ) ;
if ( V_61 )
return V_61 ;
F_44 ( V_51 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_54 )
{
struct V_93 * V_94 ;
if ( ! F_35 ( V_79 ) )
return 0 ;
if ( V_54 -> V_80 )
return 0 ;
V_94 = F_57 ( & V_54 -> V_6 -> V_7 , L_9 ) ;
if ( F_58 ( V_94 ) ) {
if ( F_59 ( V_94 ) != - V_95 )
F_36 ( L_10 ) ;
return F_59 ( V_94 ) ;
}
V_54 -> V_80 = V_94 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_54 )
{
struct V_8 * V_51 ;
if ( V_54 -> V_51 )
return;
V_51 = F_5 ( V_54 -> V_4 . V_66 ) ;
if ( ! V_51 )
return;
if ( F_6 () == V_24 )
F_61 ( V_51 -> V_96 , V_54 -> V_4 . V_66 ) ;
if ( F_55 ( V_51 ) ) {
F_29 ( L_11 ) ;
return;
}
V_54 -> V_51 = V_51 ;
}
static enum V_9 F_62 ( int V_87 )
{
switch ( F_6 () ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
return V_20 ;
case V_24 :
switch ( V_87 ) {
case 2 :
return V_23 ;
case 1 :
return V_21 ;
case 0 :
default:
return V_20 ;
}
case V_17 :
case V_18 :
case V_19 :
return V_21 ;
case V_22 :
return V_23 ;
default:
F_29 ( L_12 ) ;
return V_20 ;
}
}
static int F_63 ( struct V_2 * V_3 ,
struct V_2 * V_97 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_54 -> V_4 . V_66 ;
int V_61 ;
V_61 = F_56 ( V_54 ) ;
if ( V_61 )
return V_61 ;
F_60 ( V_54 ) ;
V_61 = F_64 ( V_10 , V_3 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_65 ( V_3 , V_97 ) ;
if ( V_61 ) {
F_36 ( L_13 ,
V_97 -> V_98 ) ;
F_66 ( V_10 , V_3 ) ;
return V_61 ;
}
return 0 ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_2 * V_97 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_54 -> V_4 . V_66 ;
F_9 ( V_97 != V_3 -> V_97 ) ;
if ( V_97 != V_3 -> V_97 )
return;
F_68 ( V_3 ) ;
F_66 ( V_10 , V_3 ) ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_54 = F_3 ( V_6 ) ;
struct V_2 * V_65 = & V_54 -> V_4 ;
V_65 -> V_7 = & V_6 -> V_7 ;
V_65 -> V_96 = V_99 ;
V_65 -> V_100 = V_101 ;
V_65 -> V_98 = L_14 ;
V_65 -> V_66 = F_62 ( 0 ) ;
V_65 -> V_102 . V_54 = & V_103 ;
V_65 -> V_104 = V_105 ;
F_70 ( V_65 ) ;
}
static void F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_54 = F_3 ( V_6 ) ;
struct V_2 * V_65 = & V_54 -> V_4 ;
F_72 ( V_65 ) ;
}
static void F_73 ( struct V_5 * V_6 ,
struct V_106 * V_107 )
{
struct V_1 * V_54 = V_107 -> V_33 ;
struct V_2 * V_65 = & V_54 -> V_4 ;
int V_61 ;
T_1 V_87 ;
V_61 = F_74 ( V_107 , L_15 , & V_87 ) ;
if ( V_61 )
V_87 = 0 ;
switch ( V_87 ) {
case 2 :
V_65 -> V_98 = L_16 ;
break;
case 1 :
V_65 -> V_98 = L_17 ;
break;
case 0 :
default:
V_65 -> V_98 = L_14 ;
break;
}
V_65 -> V_7 = & V_6 -> V_7 ;
V_65 -> V_96 = V_99 ;
V_65 -> V_100 = V_101 ;
V_65 -> V_66 = F_62 ( V_87 ) ;
V_65 -> V_87 = V_87 ;
V_65 -> V_102 . V_54 = & V_103 ;
V_65 -> V_104 = V_105 ;
F_70 ( V_65 ) ;
}
static void F_75 ( struct V_106 * V_107 )
{
struct V_1 * V_54 = V_107 -> V_33 ;
struct V_2 * V_65 = & V_54 -> V_4 ;
F_72 ( V_65 ) ;
}
static int F_76 ( struct V_108 * V_7 , struct V_108 * V_109 , void * V_33 )
{
struct V_5 * V_6 = F_77 ( V_7 ) ;
struct V_1 * V_54 ;
V_54 = F_78 ( & V_6 -> V_7 , sizeof( * V_54 ) , V_110 ) ;
if ( ! V_54 )
return - V_111 ;
V_54 -> V_6 = V_6 ;
F_79 ( & V_6 -> V_7 , V_54 ) ;
F_80 ( & V_54 -> V_78 ) ;
F_69 ( V_6 ) ;
return 0 ;
}
static void F_81 ( struct V_108 * V_7 , struct V_108 * V_109 , void * V_33 )
{
struct V_5 * V_6 = F_77 ( V_7 ) ;
F_71 ( V_6 ) ;
}
static int F_82 ( struct V_5 * V_6 )
{
return F_83 ( & V_6 -> V_7 , & V_112 ) ;
}
static int F_84 ( struct V_5 * V_6 )
{
F_85 ( & V_6 -> V_7 , & V_112 ) ;
return 0 ;
}
int T_2 F_86 ( void )
{
return F_87 ( & V_113 ) ;
}
void F_88 ( void )
{
F_89 ( & V_113 ) ;
}
int F_90 ( struct V_5 * V_6 , struct V_106 * V_107 )
{
struct V_1 * V_54 ;
struct V_106 * V_114 ;
T_1 V_115 ;
int V_61 ;
V_54 = F_78 ( & V_6 -> V_7 , sizeof( * V_54 ) , V_110 ) ;
if ( ! V_54 )
return - V_111 ;
V_114 = F_91 ( V_107 , NULL ) ;
if ( ! V_114 )
return 0 ;
V_61 = F_74 ( V_114 , L_18 , & V_115 ) ;
if ( V_61 ) {
F_36 ( L_19 ) ;
goto V_116;
}
V_54 -> V_76 = V_115 ;
F_92 ( V_114 ) ;
V_54 -> V_6 = V_6 ;
V_107 -> V_33 = V_54 ;
F_80 ( & V_54 -> V_78 ) ;
F_73 ( V_6 , V_107 ) ;
V_54 -> V_117 = true ;
return 0 ;
V_116:
F_92 ( V_114 ) ;
return V_61 ;
}
void F_93 ( struct V_106 * V_107 )
{
struct V_1 * V_54 = V_107 -> V_33 ;
if ( ! V_54 -> V_117 )
return;
F_75 ( V_107 ) ;
}
