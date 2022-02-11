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
switch ( F_6 () ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
return V_17 ;
case V_18 :
case V_19 :
case V_20 :
switch ( V_10 ) {
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
default:
return V_17 ;
}
case V_25 :
switch ( V_10 ) {
case V_21 :
return V_22 ;
case V_26 :
return V_24 ;
case V_23 :
default:
return V_17 ;
}
case V_27 :
switch ( V_10 ) {
case V_21 :
return V_22 ;
case V_23 :
return V_28 ;
case V_26 :
return V_24 ;
default:
return V_17 ;
}
default:
return V_17 ;
}
}
static bool F_7 ( int V_29 , int V_30 , unsigned long V_31 ,
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
static bool F_8 ( int V_40 , unsigned long V_41 ,
void * V_33 )
{
struct V_34 * V_35 = V_33 ;
if ( V_40 > 1 && V_40 % 2 != 0 && V_35 -> V_36 >= 100000000 )
return false ;
V_35 -> V_42 . V_43 [ V_35 -> V_44 ] = V_40 ;
V_35 -> V_42 . V_45 [ V_35 -> V_44 ] = V_41 ;
return F_9 ( V_41 , V_35 -> V_36 , V_35 -> V_46 ,
F_7 , V_35 ) ;
}
static bool F_10 ( int V_47 , int V_48 , unsigned long V_49 ,
unsigned long V_50 ,
void * V_33 )
{
struct V_34 * V_35 = V_33 ;
V_35 -> V_42 . V_47 = V_47 ;
V_35 -> V_42 . V_48 = V_48 ;
V_35 -> V_42 . V_49 = V_49 ;
V_35 -> V_42 . V_50 = V_50 ;
return F_11 ( V_35 -> V_51 , V_50 ,
V_35 -> V_36 , F_12 ( V_52 ) ,
F_8 , V_35 ) ;
}
static bool F_13 ( unsigned long V_53 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
V_35 -> V_53 = V_53 ;
return F_9 ( V_53 , V_35 -> V_36 , V_35 -> V_46 ,
F_7 , V_35 ) ;
}
static bool F_14 ( struct V_1 * V_54 , unsigned long V_32 ,
struct V_34 * V_35 )
{
unsigned long V_55 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_51 = V_54 -> V_51 ;
V_35 -> V_44 = F_15 ( V_54 -> V_56 ) ;
V_55 = F_16 ( V_54 -> V_51 -> V_55 ) ;
if ( V_54 -> V_51 -> V_57 -> type == V_58 ) {
unsigned long V_59 , V_60 ;
V_35 -> V_36 = V_32 - 1000 ;
V_35 -> V_46 = V_32 + 1000 ;
V_59 = 0 ;
V_60 = 0 ;
return F_17 ( V_35 -> V_51 , V_55 ,
V_59 , V_60 ,
F_10 , V_35 ) ;
} else {
F_18 ( V_54 -> V_51 , V_55 , V_32 , & V_35 -> V_42 ) ;
V_35 -> V_37 . V_38 = 1 ;
V_35 -> V_37 . V_39 = 1 ;
V_35 -> V_37 . V_31 = V_35 -> V_42 . V_45 [ 0 ] ;
V_35 -> V_37 . V_32 = V_35 -> V_37 . V_31 ;
return true ;
}
}
static bool F_19 ( unsigned long V_32 , struct V_34 * V_35 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < 25 ; ++ V_61 ) {
bool V_62 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
if ( V_32 > 1000 * V_61 * V_61 * V_61 )
V_35 -> V_36 = F_20 ( V_32 - 1000 * V_61 * V_61 * V_61 , 0lu ) ;
else
V_35 -> V_36 = 0 ;
V_35 -> V_46 = V_32 + 1000 * V_61 * V_61 * V_61 ;
V_62 = F_21 ( V_32 , V_35 -> V_36 , F_13 , V_35 ) ;
if ( V_62 )
return V_62 ;
}
return false ;
}
static int F_22 ( struct V_1 * V_54 , enum V_9 V_10 ,
unsigned long V_63 , unsigned long * V_53 , int * V_38 ,
int * V_39 )
{
struct V_34 V_35 ;
int V_64 ;
bool V_62 ;
V_62 = F_14 ( V_54 , V_63 , & V_35 ) ;
if ( ! V_62 )
return - V_65 ;
V_64 = F_23 ( V_54 -> V_51 , & V_35 . V_42 ) ;
if ( V_64 )
return V_64 ;
F_24 ( V_10 , V_54 -> V_56 ) ;
V_54 -> V_66 . V_67 = V_35 . V_37 ;
* V_53 = V_35 . V_42 . V_45 [ V_35 . V_44 ] ;
* V_38 = V_35 . V_37 . V_38 ;
* V_39 = V_35 . V_37 . V_39 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_54 , unsigned long V_63 ,
unsigned long * V_53 , int * V_38 , int * V_39 )
{
struct V_34 V_35 ;
int V_64 ;
bool V_62 ;
V_62 = F_19 ( V_63 , & V_35 ) ;
if ( ! V_62 )
return - V_65 ;
V_64 = F_26 ( V_35 . V_53 ) ;
if ( V_64 )
return V_64 ;
V_54 -> V_66 . V_67 = V_35 . V_37 ;
* V_53 = V_35 . V_53 ;
* V_38 = V_35 . V_37 . V_38 ;
* V_39 = V_35 . V_37 . V_39 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_54 )
{
struct V_2 * V_68 = & V_54 -> V_4 ;
enum V_9 V_10 = V_68 -> V_69 ;
struct V_70 * V_71 = & V_54 -> V_72 ;
int V_38 = 0 , V_39 = 0 ;
unsigned long V_53 = 0 ;
unsigned long V_32 ;
int V_64 = 0 ;
if ( V_54 -> V_51 )
V_64 = F_22 ( V_54 , V_10 , V_71 -> V_73 , & V_53 ,
& V_38 , & V_39 ) ;
else
V_64 = F_25 ( V_54 , V_71 -> V_73 , & V_53 ,
& V_38 , & V_39 ) ;
if ( V_64 )
return V_64 ;
V_32 = V_53 / V_38 / V_39 ;
if ( V_32 != V_71 -> V_73 ) {
F_28 ( L_1 ,
V_71 -> V_73 , V_32 ) ;
V_71 -> V_73 = V_32 ;
}
F_29 ( V_10 , V_71 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_54 )
{
struct V_2 * V_68 = & V_54 -> V_4 ;
enum V_9 V_10 = V_68 -> V_69 ;
V_54 -> V_66 . V_74 = V_75 ;
V_54 -> V_66 . V_76 = false ;
V_54 -> V_66 . V_77 = false ;
V_54 -> V_66 . V_78 = V_54 -> V_79 ;
V_54 -> V_66 . V_80 = 0 ;
F_31 ( V_10 , & V_54 -> V_66 ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
struct V_2 * V_68 = & V_54 -> V_4 ;
enum V_9 V_10 = V_68 -> V_69 ;
int V_64 ;
F_33 ( & V_54 -> V_81 ) ;
if ( F_34 ( V_82 ) && ! V_54 -> V_83 ) {
F_35 ( L_2 ) ;
V_64 = - V_84 ;
goto V_85;
}
if ( ! V_68 -> V_86 ) {
F_35 ( L_3 ) ;
V_64 = - V_84 ;
goto V_87;
}
if ( F_34 ( V_82 ) ) {
V_64 = F_36 ( V_54 -> V_83 ) ;
if ( V_64 )
goto V_88;
}
V_64 = F_37 () ;
if ( V_64 )
goto V_89;
V_64 = F_38 ( V_68 -> V_90 , V_10 ) ;
if ( V_64 )
goto V_91;
if ( V_54 -> V_51 ) {
V_64 = F_39 ( V_54 -> V_51 ) ;
if ( V_64 )
goto V_92;
}
V_64 = F_27 ( V_54 ) ;
if ( V_64 )
goto V_93;
F_30 ( V_54 ) ;
F_40 ( 2 ) ;
V_64 = F_41 ( V_10 ) ;
if ( V_64 )
goto V_94;
F_42 ( & V_54 -> V_81 ) ;
return 0 ;
V_94:
V_93:
if ( V_54 -> V_51 )
F_43 ( V_54 -> V_51 ) ;
V_92:
V_91:
F_44 () ;
V_89:
if ( F_34 ( V_82 ) )
F_45 ( V_54 -> V_83 ) ;
V_88:
V_87:
V_85:
F_42 ( & V_54 -> V_81 ) ;
return V_64 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_54 -> V_4 . V_69 ;
F_33 ( & V_54 -> V_81 ) ;
F_47 ( V_10 ) ;
if ( V_54 -> V_51 ) {
F_24 ( V_10 , V_17 ) ;
F_43 ( V_54 -> V_51 ) ;
}
F_44 () ;
if ( F_34 ( V_82 ) )
F_45 ( V_54 -> V_83 ) ;
F_42 ( & V_54 -> V_81 ) ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_70 * V_72 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
F_49 ( L_4 ) ;
F_33 ( & V_54 -> V_81 ) ;
V_54 -> V_72 = * V_72 ;
F_42 ( & V_54 -> V_81 ) ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_70 * V_72 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
F_33 ( & V_54 -> V_81 ) ;
* V_72 = V_54 -> V_72 ;
F_42 ( & V_54 -> V_81 ) ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_70 * V_72 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_54 -> V_4 . V_69 ;
int V_38 , V_39 ;
unsigned long V_53 ;
unsigned long V_32 ;
struct V_34 V_35 ;
bool V_62 ;
if ( V_72 -> V_95 % 8 != 0 )
return - V_65 ;
if ( ! F_52 ( V_10 , V_72 ) )
return - V_65 ;
if ( V_72 -> V_73 == 0 )
return - V_65 ;
if ( V_54 -> V_51 ) {
V_62 = F_14 ( V_54 , V_72 -> V_73 , & V_35 ) ;
if ( ! V_62 )
return - V_65 ;
V_53 = V_35 . V_42 . V_45 [ V_35 . V_44 ] ;
} else {
V_62 = F_19 ( V_72 -> V_73 , & V_35 ) ;
if ( ! V_62 )
return - V_65 ;
V_53 = V_35 . V_53 ;
}
V_38 = V_35 . V_37 . V_38 ;
V_39 = V_35 . V_37 . V_39 ;
V_32 = V_53 / V_38 / V_39 ;
V_72 -> V_73 = V_32 ;
return 0 ;
}
static void F_53 ( struct V_2 * V_3 , int V_79 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
F_33 ( & V_54 -> V_81 ) ;
V_54 -> V_79 = V_79 ;
F_42 ( & V_54 -> V_81 ) ;
}
static int F_54 ( struct V_96 * V_51 )
{
int V_64 ;
V_64 = F_39 ( V_51 ) ;
if ( V_64 )
return V_64 ;
F_43 ( V_51 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_54 )
{
struct V_97 * V_98 ;
if ( ! F_34 ( V_82 ) )
return 0 ;
if ( V_54 -> V_83 )
return 0 ;
V_98 = F_56 ( & V_54 -> V_6 -> V_7 , L_5 ) ;
if ( F_57 ( V_98 ) ) {
if ( F_58 ( V_98 ) != - V_99 )
F_35 ( L_6 ) ;
return F_58 ( V_98 ) ;
}
V_54 -> V_83 = V_98 ;
return 0 ;
}
static void F_59 ( struct V_1 * V_54 )
{
struct V_96 * V_51 ;
if ( V_54 -> V_51 )
return;
V_54 -> V_56 = F_5 ( V_54 -> V_4 . V_69 ) ;
V_51 = F_60 ( V_54 -> V_56 ) ;
if ( ! V_51 )
return;
if ( F_54 ( V_51 ) ) {
F_28 ( L_7 ) ;
return;
}
V_54 -> V_51 = V_51 ;
}
static enum V_9 F_61 ( int V_90 )
{
switch ( F_6 () ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
return V_21 ;
case V_27 :
switch ( V_90 ) {
case 2 :
return V_26 ;
case 1 :
return V_23 ;
case 0 :
default:
return V_21 ;
}
case V_18 :
case V_19 :
case V_20 :
return V_23 ;
case V_25 :
return V_26 ;
default:
F_28 ( L_8 ) ;
return V_21 ;
}
}
static int F_62 ( struct V_2 * V_3 ,
struct V_2 * V_100 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_54 -> V_4 . V_69 ;
int V_64 ;
V_64 = F_55 ( V_54 ) ;
if ( V_64 )
return V_64 ;
F_59 ( V_54 ) ;
V_64 = F_63 ( V_10 , V_3 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_64 ( V_3 , V_100 ) ;
if ( V_64 ) {
F_35 ( L_9 ,
V_100 -> V_101 ) ;
F_65 ( V_10 , V_3 ) ;
return V_64 ;
}
return 0 ;
}
static void F_66 ( struct V_2 * V_3 ,
struct V_2 * V_100 )
{
struct V_1 * V_54 = F_1 ( V_3 ) ;
enum V_9 V_10 = V_54 -> V_4 . V_69 ;
F_67 ( V_100 != V_3 -> V_100 ) ;
if ( V_100 != V_3 -> V_100 )
return;
F_68 ( V_3 ) ;
F_65 ( V_10 , V_3 ) ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_54 = F_3 ( V_6 ) ;
struct V_2 * V_68 = & V_54 -> V_4 ;
V_68 -> V_7 = & V_6 -> V_7 ;
V_68 -> V_102 = V_103 ;
V_68 -> V_104 = V_105 ;
V_68 -> V_101 = L_10 ;
V_68 -> V_69 = F_61 ( 0 ) ;
V_68 -> V_106 . V_54 = & V_107 ;
V_68 -> V_108 = V_109 ;
F_70 ( V_68 ) ;
}
static void F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_54 = F_3 ( V_6 ) ;
struct V_2 * V_68 = & V_54 -> V_4 ;
F_72 ( V_68 ) ;
}
static void F_73 ( struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_1 * V_54 = V_111 -> V_33 ;
struct V_2 * V_68 = & V_54 -> V_4 ;
int V_64 ;
T_1 V_90 ;
V_64 = F_74 ( V_111 , L_11 , & V_90 ) ;
if ( V_64 )
V_90 = 0 ;
switch ( V_90 ) {
case 2 :
V_68 -> V_101 = L_12 ;
break;
case 1 :
V_68 -> V_101 = L_13 ;
break;
case 0 :
default:
V_68 -> V_101 = L_10 ;
break;
}
V_68 -> V_7 = & V_6 -> V_7 ;
V_68 -> V_102 = V_103 ;
V_68 -> V_104 = V_105 ;
V_68 -> V_69 = F_61 ( V_90 ) ;
V_68 -> V_90 = V_90 ;
V_68 -> V_106 . V_54 = & V_107 ;
V_68 -> V_108 = V_109 ;
F_70 ( V_68 ) ;
}
static void F_75 ( struct V_110 * V_111 )
{
struct V_1 * V_54 = V_111 -> V_33 ;
struct V_2 * V_68 = & V_54 -> V_4 ;
F_72 ( V_68 ) ;
}
static int F_76 ( struct V_112 * V_7 , struct V_112 * V_113 , void * V_33 )
{
struct V_5 * V_6 = F_77 ( V_7 ) ;
struct V_1 * V_54 ;
V_54 = F_78 ( & V_6 -> V_7 , sizeof( * V_54 ) , V_114 ) ;
if ( ! V_54 )
return - V_115 ;
V_54 -> V_6 = V_6 ;
F_79 ( & V_6 -> V_7 , V_54 ) ;
F_80 ( & V_54 -> V_81 ) ;
F_69 ( V_6 ) ;
return 0 ;
}
static void F_81 ( struct V_112 * V_7 , struct V_112 * V_113 , void * V_33 )
{
struct V_5 * V_6 = F_77 ( V_7 ) ;
F_71 ( V_6 ) ;
}
static int F_82 ( struct V_5 * V_6 )
{
return F_83 ( & V_6 -> V_7 , & V_116 ) ;
}
static int F_84 ( struct V_5 * V_6 )
{
F_85 ( & V_6 -> V_7 , & V_116 ) ;
return 0 ;
}
int T_2 F_86 ( void )
{
return F_87 ( & V_117 ) ;
}
void F_88 ( void )
{
F_89 ( & V_117 ) ;
}
int F_90 ( struct V_5 * V_6 , struct V_110 * V_111 )
{
struct V_1 * V_54 ;
struct V_110 * V_118 ;
T_1 V_119 ;
int V_64 ;
V_54 = F_78 ( & V_6 -> V_7 , sizeof( * V_54 ) , V_114 ) ;
if ( ! V_54 )
return - V_115 ;
V_118 = F_91 ( V_111 , NULL ) ;
if ( ! V_118 )
return 0 ;
V_64 = F_74 ( V_118 , L_14 , & V_119 ) ;
if ( V_64 ) {
F_35 ( L_15 ) ;
goto V_120;
}
V_54 -> V_79 = V_119 ;
F_92 ( V_118 ) ;
V_54 -> V_6 = V_6 ;
V_111 -> V_33 = V_54 ;
F_80 ( & V_54 -> V_81 ) ;
F_73 ( V_6 , V_111 ) ;
V_54 -> V_121 = true ;
return 0 ;
V_120:
F_92 ( V_118 ) ;
return V_64 ;
}
void F_93 ( struct V_110 * V_111 )
{
struct V_1 * V_54 = V_111 -> V_33 ;
if ( ! V_54 -> V_121 )
return;
F_75 ( V_111 ) ;
}
