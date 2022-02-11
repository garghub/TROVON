static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_4 ( & V_6 -> V_7 ) ;
}
static enum V_8 F_5 ( enum V_9 V_10 )
{
switch ( V_10 ) {
case V_11 :
{
if ( F_6 ( V_12 ) )
return V_12 ;
break;
}
case V_13 :
{
if ( F_6 ( V_14 ) )
return V_14 ;
if ( F_6 ( V_15 ) )
return V_15 ;
break;
}
case V_16 :
{
if ( F_6 ( V_17 ) )
return V_17 ;
if ( F_6 ( V_14 ) )
return V_14 ;
break;
}
default:
break;
}
return V_18 ;
}
static enum V_8 F_7 ( enum V_9 V_10 )
{
switch ( F_8 () ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
return V_18 ;
case V_25 :
case V_26 :
case V_27 :
switch ( V_10 ) {
case V_11 :
return V_12 ;
case V_13 :
return V_17 ;
default:
return V_18 ;
}
case V_28 :
switch ( V_10 ) {
case V_11 :
return V_12 ;
case V_16 :
return V_17 ;
case V_13 :
default:
return V_18 ;
}
case V_29 :
return F_5 ( V_10 ) ;
default:
return V_18 ;
}
}
static bool F_9 ( int V_30 , int V_31 , unsigned long V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
if ( V_36 -> V_37 >= 100000000 ) {
if ( V_30 > 1 && V_30 % 2 != 0 )
return false ;
if ( V_31 > 1 && V_31 % 2 != 0 )
return false ;
}
V_36 -> V_38 . V_39 = V_30 ;
V_36 -> V_38 . V_40 = V_31 ;
V_36 -> V_38 . V_32 = V_32 ;
V_36 -> V_38 . V_33 = V_33 ;
return true ;
}
static bool F_10 ( int V_41 , unsigned long V_42 ,
void * V_34 )
{
struct V_35 * V_36 = V_34 ;
V_36 -> V_43 . V_44 [ V_36 -> V_45 ] = V_41 ;
V_36 -> V_43 . V_46 [ V_36 -> V_45 ] = V_42 ;
return F_11 ( V_42 , V_36 -> V_37 , V_36 -> V_47 ,
F_9 , V_36 ) ;
}
static bool F_12 ( int V_48 , int V_49 , unsigned long V_50 ,
unsigned long V_51 ,
void * V_34 )
{
struct V_35 * V_36 = V_34 ;
V_36 -> V_43 . V_48 = V_48 ;
V_36 -> V_43 . V_49 = V_49 ;
V_36 -> V_43 . V_50 = V_50 ;
V_36 -> V_43 . V_51 = V_51 ;
return F_13 ( V_36 -> V_52 , V_51 ,
V_36 -> V_37 , F_14 ( V_53 ) ,
F_10 , V_36 ) ;
}
static bool F_15 ( unsigned long V_54 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
V_36 -> V_54 = V_54 ;
return F_11 ( V_54 , V_36 -> V_37 , V_36 -> V_47 ,
F_9 , V_36 ) ;
}
static bool F_16 ( struct V_1 * V_55 , unsigned long V_33 ,
struct V_35 * V_36 )
{
unsigned long V_56 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_52 = V_55 -> V_52 ;
V_36 -> V_45 = F_17 ( V_55 -> V_57 ) ;
V_56 = F_18 ( V_55 -> V_52 -> V_56 ) ;
if ( V_55 -> V_52 -> V_58 -> type == V_59 ) {
unsigned long V_60 , V_61 ;
V_36 -> V_37 = V_33 - 1000 ;
V_36 -> V_47 = V_33 + 1000 ;
V_60 = 0 ;
V_61 = 0 ;
return F_19 ( V_36 -> V_52 , V_56 ,
V_60 , V_61 ,
F_12 , V_36 ) ;
} else {
F_20 ( V_55 -> V_52 , V_56 , V_33 , & V_36 -> V_43 ) ;
V_36 -> V_38 . V_39 = 1 ;
V_36 -> V_38 . V_40 = 1 ;
V_36 -> V_38 . V_32 = V_36 -> V_43 . V_46 [ 0 ] ;
V_36 -> V_38 . V_33 = V_36 -> V_38 . V_32 ;
return true ;
}
}
static bool F_21 ( unsigned long V_33 , struct V_35 * V_36 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < 25 ; ++ V_62 ) {
bool V_63 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
if ( V_33 > 1000 * V_62 * V_62 * V_62 )
V_36 -> V_37 = F_22 ( V_33 - 1000 * V_62 * V_62 * V_62 , 0lu ) ;
else
V_36 -> V_37 = 0 ;
V_36 -> V_47 = V_33 + 1000 * V_62 * V_62 * V_62 ;
V_63 = F_23 ( V_33 , V_36 -> V_37 , F_15 , V_36 ) ;
if ( V_63 )
return V_63 ;
}
return false ;
}
static int F_24 ( struct V_1 * V_55 , enum V_9 V_10 ,
unsigned long V_64 , unsigned long * V_54 , int * V_39 ,
int * V_40 )
{
struct V_35 V_36 ;
int V_65 ;
bool V_63 ;
V_63 = F_16 ( V_55 , V_64 , & V_36 ) ;
if ( ! V_63 )
return - V_66 ;
V_65 = F_25 ( V_55 -> V_52 , & V_36 . V_43 ) ;
if ( V_65 )
return V_65 ;
F_26 ( V_10 , V_55 -> V_57 ) ;
V_55 -> V_67 . V_68 = V_36 . V_38 ;
* V_54 = V_36 . V_43 . V_46 [ V_36 . V_45 ] ;
* V_39 = V_36 . V_38 . V_39 ;
* V_40 = V_36 . V_38 . V_40 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_55 , unsigned long V_64 ,
unsigned long * V_54 , int * V_39 , int * V_40 )
{
struct V_35 V_36 ;
int V_65 ;
bool V_63 ;
V_63 = F_21 ( V_64 , & V_36 ) ;
if ( ! V_63 )
return - V_66 ;
V_65 = F_28 ( V_36 . V_54 ) ;
if ( V_65 )
return V_65 ;
V_55 -> V_67 . V_68 = V_36 . V_38 ;
* V_54 = V_36 . V_54 ;
* V_39 = V_36 . V_38 . V_39 ;
* V_40 = V_36 . V_38 . V_40 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_55 )
{
struct V_2 * V_69 = & V_55 -> V_4 ;
enum V_9 V_10 = V_69 -> V_70 ;
struct V_71 * V_72 = & V_55 -> V_72 ;
int V_39 = 0 , V_40 = 0 ;
unsigned long V_54 = 0 ;
unsigned long V_33 ;
int V_65 = 0 ;
if ( V_55 -> V_52 )
V_65 = F_24 ( V_55 , V_10 , V_72 -> V_73 , & V_54 ,
& V_39 , & V_40 ) ;
else
V_65 = F_27 ( V_55 , V_72 -> V_73 , & V_54 ,
& V_39 , & V_40 ) ;
if ( V_65 )
return V_65 ;
V_33 = V_54 / V_39 / V_40 ;
if ( V_33 != V_72 -> V_73 ) {
F_30 ( L_1 ,
V_72 -> V_73 , V_33 ) ;
V_72 -> V_73 = V_33 ;
}
F_31 ( V_10 , V_72 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_55 )
{
struct V_2 * V_69 = & V_55 -> V_4 ;
enum V_9 V_10 = V_69 -> V_70 ;
V_55 -> V_67 . V_74 = V_75 ;
V_55 -> V_67 . V_76 = false ;
V_55 -> V_67 . V_77 = false ;
V_55 -> V_67 . V_78 = V_55 -> V_79 ;
V_55 -> V_67 . V_80 = 0 ;
F_33 ( V_10 , & V_55 -> V_67 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_55 = F_1 ( V_3 ) ;
struct V_2 * V_69 = & V_55 -> V_4 ;
enum V_9 V_10 = V_69 -> V_70 ;
int V_65 ;
F_35 ( & V_55 -> V_81 ) ;
if ( F_36 ( V_82 ) && ! V_55 -> V_83 ) {
F_37 ( L_2 ) ;
V_65 = - V_84 ;
goto V_85;
}
if ( ! V_69 -> V_86 ) {
F_37 ( L_3 ) ;
V_65 = - V_84 ;
goto V_87;
}
if ( F_36 ( V_82 ) ) {
V_65 = F_38 ( V_55 -> V_83 ) ;
if ( V_65 )
goto V_88;
}
V_65 = F_39 () ;
if ( V_65 )
goto V_89;
V_65 = F_40 ( V_69 -> V_90 , V_10 ) ;
if ( V_65 )
goto V_91;
if ( V_55 -> V_52 ) {
V_65 = F_41 ( V_55 -> V_52 ) ;
if ( V_65 )
goto V_92;
}
V_65 = F_29 ( V_55 ) ;
if ( V_65 )
goto V_93;
F_32 ( V_55 ) ;
F_42 ( 2 ) ;
V_65 = F_43 ( V_10 ) ;
if ( V_65 )
goto V_94;
F_44 ( & V_55 -> V_81 ) ;
return 0 ;
V_94:
V_93:
if ( V_55 -> V_52 )
F_45 ( V_55 -> V_52 ) ;
V_92:
V_91:
F_46 () ;
V_89:
if ( F_36 ( V_82 ) )
F_47 ( V_55 -> V_83 ) ;
V_88:
V_87:
V_85:
F_44 ( & V_55 -> V_81 ) ;
return V_65 ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_55 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_55 -> V_4 . V_70 ;
F_35 ( & V_55 -> V_81 ) ;
F_49 ( V_10 ) ;
if ( V_55 -> V_52 ) {
F_26 ( V_10 , V_18 ) ;
F_45 ( V_55 -> V_52 ) ;
}
F_46 () ;
if ( F_36 ( V_82 ) )
F_47 ( V_55 -> V_83 ) ;
F_44 ( & V_55 -> V_81 ) ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_1 * V_55 = F_1 ( V_3 ) ;
F_51 ( L_4 ) ;
F_35 ( & V_55 -> V_81 ) ;
V_55 -> V_72 = * V_72 ;
F_44 ( & V_55 -> V_81 ) ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_1 * V_55 = F_1 ( V_3 ) ;
F_35 ( & V_55 -> V_81 ) ;
* V_72 = V_55 -> V_72 ;
F_44 ( & V_55 -> V_81 ) ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_1 * V_55 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_55 -> V_4 . V_70 ;
int V_39 , V_40 ;
unsigned long V_54 ;
unsigned long V_33 ;
struct V_35 V_36 ;
bool V_63 ;
if ( V_72 -> V_95 % 8 != 0 )
return - V_66 ;
if ( ! F_54 ( V_10 , V_72 ) )
return - V_66 ;
if ( V_72 -> V_73 == 0 )
return - V_66 ;
if ( V_55 -> V_52 ) {
V_63 = F_16 ( V_55 , V_72 -> V_73 , & V_36 ) ;
if ( ! V_63 )
return - V_66 ;
V_54 = V_36 . V_43 . V_46 [ V_36 . V_45 ] ;
} else {
V_63 = F_21 ( V_72 -> V_73 , & V_36 ) ;
if ( ! V_63 )
return - V_66 ;
V_54 = V_36 . V_54 ;
}
V_39 = V_36 . V_38 . V_39 ;
V_40 = V_36 . V_38 . V_40 ;
V_33 = V_54 / V_39 / V_40 ;
V_72 -> V_73 = V_33 ;
return 0 ;
}
static void F_55 ( struct V_2 * V_3 , int V_79 )
{
struct V_1 * V_55 = F_1 ( V_3 ) ;
F_35 ( & V_55 -> V_81 ) ;
V_55 -> V_79 = V_79 ;
F_44 ( & V_55 -> V_81 ) ;
}
static int F_56 ( struct V_96 * V_52 )
{
int V_65 ;
V_65 = F_41 ( V_52 ) ;
if ( V_65 )
return V_65 ;
F_45 ( V_52 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_55 )
{
struct V_97 * V_98 ;
if ( ! F_36 ( V_82 ) )
return 0 ;
if ( V_55 -> V_83 )
return 0 ;
V_98 = F_58 ( & V_55 -> V_6 -> V_7 , L_5 ) ;
if ( F_59 ( V_98 ) ) {
if ( F_60 ( V_98 ) != - V_99 )
F_37 ( L_6 ) ;
return F_60 ( V_98 ) ;
}
V_55 -> V_83 = V_98 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_55 )
{
struct V_96 * V_52 ;
if ( V_55 -> V_52 )
return;
V_55 -> V_57 = F_7 ( V_55 -> V_4 . V_70 ) ;
V_52 = F_6 ( V_55 -> V_57 ) ;
if ( ! V_52 )
return;
if ( F_56 ( V_52 ) ) {
F_30 ( L_7 ) ;
return;
}
V_55 -> V_52 = V_52 ;
}
static enum V_9 F_62 ( int V_90 )
{
switch ( F_8 () ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
return V_11 ;
case V_29 :
switch ( V_90 ) {
case 2 :
return V_16 ;
case 1 :
return V_13 ;
case 0 :
default:
return V_11 ;
}
case V_25 :
case V_26 :
case V_27 :
return V_13 ;
case V_28 :
return V_16 ;
default:
F_30 ( L_8 ) ;
return V_11 ;
}
}
static int F_63 ( struct V_2 * V_3 ,
struct V_2 * V_100 )
{
struct V_1 * V_55 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_55 -> V_4 . V_70 ;
int V_65 ;
V_65 = F_57 ( V_55 ) ;
if ( V_65 )
return V_65 ;
F_61 ( V_55 ) ;
V_65 = F_64 ( V_10 , V_3 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_65 ( V_3 , V_100 ) ;
if ( V_65 ) {
F_37 ( L_9 ,
V_100 -> V_101 ) ;
F_66 ( V_10 , V_3 ) ;
return V_65 ;
}
return 0 ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_2 * V_100 )
{
struct V_1 * V_55 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_55 -> V_4 . V_70 ;
F_68 ( V_100 != V_3 -> V_100 ) ;
if ( V_100 != V_3 -> V_100 )
return;
F_69 ( V_3 ) ;
F_66 ( V_10 , V_3 ) ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_1 * V_55 = F_3 ( V_6 ) ;
struct V_2 * V_69 = & V_55 -> V_4 ;
V_69 -> V_7 = & V_6 -> V_7 ;
V_69 -> V_102 = V_103 ;
V_69 -> V_104 = V_105 ;
V_69 -> V_101 = L_10 ;
V_69 -> V_70 = F_62 ( 0 ) ;
V_69 -> V_106 . V_55 = & V_107 ;
V_69 -> V_108 = V_109 ;
F_71 ( V_69 ) ;
}
static void F_72 ( struct V_5 * V_6 )
{
struct V_1 * V_55 = F_3 ( V_6 ) ;
struct V_2 * V_69 = & V_55 -> V_4 ;
F_73 ( V_69 ) ;
}
static void F_74 ( struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_1 * V_55 = V_111 -> V_34 ;
struct V_2 * V_69 = & V_55 -> V_4 ;
int V_65 ;
T_1 V_90 ;
V_65 = F_75 ( V_111 , L_11 , & V_90 ) ;
if ( V_65 )
V_90 = 0 ;
switch ( V_90 ) {
case 2 :
V_69 -> V_101 = L_12 ;
break;
case 1 :
V_69 -> V_101 = L_13 ;
break;
case 0 :
default:
V_69 -> V_101 = L_10 ;
break;
}
V_69 -> V_7 = & V_6 -> V_7 ;
V_69 -> V_102 = V_103 ;
V_69 -> V_104 = V_105 ;
V_69 -> V_70 = F_62 ( V_90 ) ;
V_69 -> V_90 = V_90 ;
V_69 -> V_106 . V_55 = & V_107 ;
V_69 -> V_108 = V_109 ;
F_71 ( V_69 ) ;
}
static void F_76 ( struct V_110 * V_111 )
{
struct V_1 * V_55 = V_111 -> V_34 ;
struct V_2 * V_69 = & V_55 -> V_4 ;
F_73 ( V_69 ) ;
}
static int F_77 ( struct V_112 * V_7 , struct V_112 * V_113 , void * V_34 )
{
struct V_5 * V_6 = F_78 ( V_7 ) ;
struct V_1 * V_55 ;
V_55 = F_79 ( & V_6 -> V_7 , sizeof( * V_55 ) , V_114 ) ;
if ( ! V_55 )
return - V_115 ;
V_55 -> V_6 = V_6 ;
F_80 ( & V_6 -> V_7 , V_55 ) ;
F_81 ( & V_55 -> V_81 ) ;
F_70 ( V_6 ) ;
return 0 ;
}
static void F_82 ( struct V_112 * V_7 , struct V_112 * V_113 , void * V_34 )
{
struct V_5 * V_6 = F_78 ( V_7 ) ;
F_72 ( V_6 ) ;
}
static int F_83 ( struct V_5 * V_6 )
{
return F_84 ( & V_6 -> V_7 , & V_116 ) ;
}
static int F_85 ( struct V_5 * V_6 )
{
F_86 ( & V_6 -> V_7 , & V_116 ) ;
return 0 ;
}
int T_2 F_87 ( void )
{
return F_88 ( & V_117 ) ;
}
void F_89 ( void )
{
F_90 ( & V_117 ) ;
}
int F_91 ( struct V_5 * V_6 , struct V_110 * V_111 )
{
struct V_1 * V_55 ;
struct V_110 * V_118 ;
T_1 V_119 ;
int V_65 ;
V_55 = F_79 ( & V_6 -> V_7 , sizeof( * V_55 ) , V_114 ) ;
if ( ! V_55 )
return - V_115 ;
V_118 = F_92 ( V_111 , NULL ) ;
if ( ! V_118 )
return 0 ;
V_65 = F_75 ( V_118 , L_14 , & V_119 ) ;
if ( V_65 ) {
F_37 ( L_15 ) ;
goto V_120;
}
V_55 -> V_79 = V_119 ;
F_93 ( V_118 ) ;
V_55 -> V_6 = V_6 ;
V_111 -> V_34 = V_55 ;
F_81 ( & V_55 -> V_81 ) ;
F_74 ( V_6 , V_111 ) ;
V_55 -> V_121 = true ;
return 0 ;
V_120:
F_93 ( V_118 ) ;
return V_65 ;
}
void F_94 ( struct V_110 * V_111 )
{
struct V_1 * V_55 = V_111 -> V_34 ;
if ( ! V_55 -> V_121 )
return;
F_76 ( V_111 ) ;
}
