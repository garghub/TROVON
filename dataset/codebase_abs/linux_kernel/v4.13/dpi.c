static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static enum V_5 F_3 ( enum V_6 V_7 )
{
switch ( V_7 ) {
case V_8 :
{
if ( F_4 ( V_9 ) )
return V_9 ;
break;
}
case V_10 :
{
if ( F_4 ( V_11 ) )
return V_11 ;
if ( F_4 ( V_12 ) )
return V_12 ;
break;
}
case V_13 :
{
if ( F_4 ( V_14 ) )
return V_14 ;
if ( F_4 ( V_11 ) )
return V_11 ;
break;
}
default:
break;
}
return V_15 ;
}
static enum V_5 F_5 ( enum V_6 V_7 )
{
switch ( F_6 () ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return V_15 ;
case V_22 :
case V_23 :
case V_24 :
switch ( V_7 ) {
case V_8 :
return V_9 ;
case V_10 :
return V_14 ;
default:
return V_15 ;
}
case V_25 :
switch ( V_7 ) {
case V_8 :
return V_9 ;
case V_13 :
return V_14 ;
case V_10 :
default:
return V_15 ;
}
case V_26 :
return F_3 ( V_7 ) ;
default:
return V_15 ;
}
}
static bool F_7 ( int V_27 , int V_28 , unsigned long V_29 ,
unsigned long V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
if ( V_33 -> V_34 >= 100000000 ) {
if ( V_27 > 1 && V_27 % 2 != 0 )
return false ;
if ( V_28 > 1 && V_28 % 2 != 0 )
return false ;
}
V_33 -> V_35 . V_36 = V_27 ;
V_33 -> V_35 . V_37 = V_28 ;
V_33 -> V_35 . V_29 = V_29 ;
V_33 -> V_35 . V_30 = V_30 ;
return true ;
}
static bool F_8 ( int V_38 , unsigned long V_39 ,
void * V_31 )
{
struct V_32 * V_33 = V_31 ;
V_33 -> V_40 . V_41 [ V_33 -> V_42 ] = V_38 ;
V_33 -> V_40 . V_43 [ V_33 -> V_42 ] = V_39 ;
return F_9 ( V_39 , V_33 -> V_34 , V_33 -> V_44 ,
F_7 , V_33 ) ;
}
static bool F_10 ( int V_45 , int V_46 , unsigned long V_47 ,
unsigned long V_48 ,
void * V_31 )
{
struct V_32 * V_33 = V_31 ;
V_33 -> V_40 . V_45 = V_45 ;
V_33 -> V_40 . V_46 = V_46 ;
V_33 -> V_40 . V_47 = V_47 ;
V_33 -> V_40 . V_48 = V_48 ;
return F_11 ( V_33 -> V_49 , V_48 ,
V_33 -> V_34 , F_12 ( V_50 ) ,
F_8 , V_33 ) ;
}
static bool F_13 ( unsigned long V_51 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
V_33 -> V_51 = V_51 ;
return F_9 ( V_51 , V_33 -> V_34 , V_33 -> V_44 ,
F_7 , V_33 ) ;
}
static bool F_14 ( struct V_1 * V_52 , unsigned long V_30 ,
struct V_32 * V_33 )
{
unsigned long V_53 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_49 = V_52 -> V_49 ;
V_33 -> V_42 = F_15 ( V_52 -> V_54 ) ;
V_53 = F_16 ( V_52 -> V_49 -> V_53 ) ;
if ( V_52 -> V_49 -> V_55 -> type == V_56 ) {
unsigned long V_57 , V_58 ;
V_33 -> V_34 = V_30 - 1000 ;
V_33 -> V_44 = V_30 + 1000 ;
V_57 = 0 ;
V_58 = 0 ;
return F_17 ( V_33 -> V_49 , V_53 ,
V_57 , V_58 ,
F_10 , V_33 ) ;
} else {
F_18 ( V_52 -> V_49 , V_53 , V_30 , & V_33 -> V_40 ) ;
V_33 -> V_35 . V_36 = 1 ;
V_33 -> V_35 . V_37 = 1 ;
V_33 -> V_35 . V_29 = V_33 -> V_40 . V_43 [ 0 ] ;
V_33 -> V_35 . V_30 = V_33 -> V_35 . V_29 ;
return true ;
}
}
static bool F_19 ( unsigned long V_30 , struct V_32 * V_33 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < 25 ; ++ V_59 ) {
bool V_60 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
if ( V_30 > 1000 * V_59 * V_59 * V_59 )
V_33 -> V_34 = F_20 ( V_30 - 1000 * V_59 * V_59 * V_59 , 0lu ) ;
else
V_33 -> V_34 = 0 ;
V_33 -> V_44 = V_30 + 1000 * V_59 * V_59 * V_59 ;
V_60 = F_21 ( V_30 , V_33 -> V_34 , F_13 , V_33 ) ;
if ( V_60 )
return V_60 ;
}
return false ;
}
static int F_22 ( struct V_1 * V_52 , enum V_6 V_7 ,
unsigned long V_61 , unsigned long * V_51 , int * V_36 ,
int * V_37 )
{
struct V_32 V_33 ;
int V_62 ;
bool V_60 ;
V_60 = F_14 ( V_52 , V_61 , & V_33 ) ;
if ( ! V_60 )
return - V_63 ;
V_62 = F_23 ( V_52 -> V_49 , & V_33 . V_40 ) ;
if ( V_62 )
return V_62 ;
F_24 ( V_7 , V_52 -> V_54 ) ;
V_52 -> V_64 . V_65 = V_33 . V_35 ;
* V_51 = V_33 . V_40 . V_43 [ V_33 . V_42 ] ;
* V_36 = V_33 . V_35 . V_36 ;
* V_37 = V_33 . V_35 . V_37 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_52 , unsigned long V_61 ,
unsigned long * V_51 , int * V_36 , int * V_37 )
{
struct V_32 V_33 ;
int V_62 ;
bool V_60 ;
V_60 = F_19 ( V_61 , & V_33 ) ;
if ( ! V_60 )
return - V_63 ;
V_62 = F_26 ( V_33 . V_51 ) ;
if ( V_62 )
return V_62 ;
V_52 -> V_64 . V_65 = V_33 . V_35 ;
* V_51 = V_33 . V_51 ;
* V_36 = V_33 . V_35 . V_36 ;
* V_37 = V_33 . V_35 . V_37 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_52 )
{
struct V_2 * V_66 = & V_52 -> V_4 ;
enum V_6 V_7 = V_66 -> V_67 ;
struct V_68 * V_69 = & V_52 -> V_69 ;
int V_36 = 0 , V_37 = 0 ;
unsigned long V_51 = 0 ;
unsigned long V_30 ;
int V_62 = 0 ;
if ( V_52 -> V_49 )
V_62 = F_22 ( V_52 , V_7 , V_69 -> V_70 , & V_51 ,
& V_36 , & V_37 ) ;
else
V_62 = F_25 ( V_52 , V_69 -> V_70 , & V_51 ,
& V_36 , & V_37 ) ;
if ( V_62 )
return V_62 ;
V_30 = V_51 / V_36 / V_37 ;
if ( V_30 != V_69 -> V_70 ) {
F_28 ( L_1 ,
V_69 -> V_70 , V_30 ) ;
V_69 -> V_70 = V_30 ;
}
F_29 ( V_7 , V_69 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_52 )
{
struct V_2 * V_66 = & V_52 -> V_4 ;
enum V_6 V_7 = V_66 -> V_67 ;
V_52 -> V_64 . V_71 = V_72 ;
V_52 -> V_64 . V_73 = false ;
V_52 -> V_64 . V_74 = false ;
V_52 -> V_64 . V_75 = V_52 -> V_76 ;
V_52 -> V_64 . V_77 = 0 ;
F_31 ( V_7 , & V_52 -> V_64 ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_52 = F_1 ( V_3 ) ;
struct V_2 * V_66 = & V_52 -> V_4 ;
enum V_6 V_7 = V_66 -> V_67 ;
int V_62 ;
F_33 ( & V_52 -> V_78 ) ;
if ( F_34 ( V_79 ) && ! V_52 -> V_80 ) {
F_35 ( L_2 ) ;
V_62 = - V_81 ;
goto V_82;
}
if ( ! V_66 -> V_83 ) {
F_35 ( L_3 ) ;
V_62 = - V_81 ;
goto V_84;
}
if ( F_34 ( V_79 ) ) {
V_62 = F_36 ( V_52 -> V_80 ) ;
if ( V_62 )
goto V_85;
}
V_62 = F_37 () ;
if ( V_62 )
goto V_86;
V_62 = F_38 ( V_66 -> V_87 , V_7 ) ;
if ( V_62 )
goto V_88;
if ( V_52 -> V_49 ) {
V_62 = F_39 ( V_52 -> V_49 ) ;
if ( V_62 )
goto V_89;
}
V_62 = F_27 ( V_52 ) ;
if ( V_62 )
goto V_90;
F_30 ( V_52 ) ;
F_40 ( 2 ) ;
V_62 = F_41 ( V_7 ) ;
if ( V_62 )
goto V_91;
F_42 ( & V_52 -> V_78 ) ;
return 0 ;
V_91:
V_90:
if ( V_52 -> V_49 )
F_43 ( V_52 -> V_49 ) ;
V_89:
V_88:
F_44 () ;
V_86:
if ( F_34 ( V_79 ) )
F_45 ( V_52 -> V_80 ) ;
V_85:
V_84:
V_82:
F_42 ( & V_52 -> V_78 ) ;
return V_62 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_52 = F_1 ( V_3 ) ;
enum V_6 V_7 = V_52 -> V_4 . V_67 ;
F_33 ( & V_52 -> V_78 ) ;
F_47 ( V_7 ) ;
if ( V_52 -> V_49 ) {
F_24 ( V_7 , V_15 ) ;
F_43 ( V_52 -> V_49 ) ;
}
F_44 () ;
if ( F_34 ( V_79 ) )
F_45 ( V_52 -> V_80 ) ;
F_42 ( & V_52 -> V_78 ) ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_1 * V_52 = F_1 ( V_3 ) ;
F_49 ( L_4 ) ;
F_33 ( & V_52 -> V_78 ) ;
V_52 -> V_69 = * V_69 ;
F_42 ( & V_52 -> V_78 ) ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_1 * V_52 = F_1 ( V_3 ) ;
F_33 ( & V_52 -> V_78 ) ;
* V_69 = V_52 -> V_69 ;
F_42 ( & V_52 -> V_78 ) ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_1 * V_52 = F_1 ( V_3 ) ;
enum V_6 V_7 = V_52 -> V_4 . V_67 ;
int V_36 , V_37 ;
unsigned long V_51 ;
unsigned long V_30 ;
struct V_32 V_33 ;
bool V_60 ;
if ( V_69 -> V_92 % 8 != 0 )
return - V_63 ;
if ( ! F_52 ( V_7 , V_69 ) )
return - V_63 ;
if ( V_69 -> V_70 == 0 )
return - V_63 ;
if ( V_52 -> V_49 ) {
V_60 = F_14 ( V_52 , V_69 -> V_70 , & V_33 ) ;
if ( ! V_60 )
return - V_63 ;
V_51 = V_33 . V_40 . V_43 [ V_33 . V_42 ] ;
} else {
V_60 = F_19 ( V_69 -> V_70 , & V_33 ) ;
if ( ! V_60 )
return - V_63 ;
V_51 = V_33 . V_51 ;
}
V_36 = V_33 . V_35 . V_36 ;
V_37 = V_33 . V_35 . V_37 ;
V_30 = V_51 / V_36 / V_37 ;
V_69 -> V_70 = V_30 ;
return 0 ;
}
static int F_53 ( struct V_93 * V_49 )
{
int V_62 ;
V_62 = F_39 ( V_49 ) ;
if ( V_62 )
return V_62 ;
F_43 ( V_49 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_52 )
{
struct V_94 * V_95 ;
if ( ! F_34 ( V_79 ) )
return 0 ;
if ( V_52 -> V_80 )
return 0 ;
V_95 = F_55 ( & V_52 -> V_96 -> V_97 , L_5 ) ;
if ( F_56 ( V_95 ) ) {
if ( F_57 ( V_95 ) != - V_98 )
F_35 ( L_6 ) ;
return F_57 ( V_95 ) ;
}
V_52 -> V_80 = V_95 ;
return 0 ;
}
static void F_58 ( struct V_1 * V_52 )
{
struct V_93 * V_49 ;
if ( V_52 -> V_49 )
return;
V_52 -> V_54 = F_5 ( V_52 -> V_4 . V_67 ) ;
V_49 = F_4 ( V_52 -> V_54 ) ;
if ( ! V_49 )
return;
if ( F_53 ( V_49 ) ) {
F_28 ( L_7 ) ;
return;
}
V_52 -> V_49 = V_49 ;
}
static enum V_6 F_59 ( int V_87 )
{
switch ( F_6 () ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return V_8 ;
case V_26 :
switch ( V_87 ) {
case 2 :
return V_13 ;
case 1 :
return V_10 ;
case 0 :
default:
return V_8 ;
}
case V_22 :
case V_23 :
case V_24 :
return V_10 ;
case V_25 :
return V_13 ;
default:
F_28 ( L_8 ) ;
return V_8 ;
}
}
static int F_60 ( struct V_2 * V_3 ,
struct V_2 * V_99 )
{
struct V_1 * V_52 = F_1 ( V_3 ) ;
enum V_6 V_7 = V_52 -> V_4 . V_67 ;
int V_62 ;
V_62 = F_54 ( V_52 ) ;
if ( V_62 )
return V_62 ;
F_58 ( V_52 ) ;
V_62 = F_61 ( V_7 , V_3 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_62 ( V_3 , V_99 ) ;
if ( V_62 ) {
F_35 ( L_9 ,
V_99 -> V_100 ) ;
F_63 ( V_7 , V_3 ) ;
return V_62 ;
}
return 0 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_2 * V_99 )
{
struct V_1 * V_52 = F_1 ( V_3 ) ;
enum V_6 V_7 = V_52 -> V_4 . V_67 ;
F_65 ( V_99 != V_3 -> V_99 ) ;
if ( V_99 != V_3 -> V_99 )
return;
F_66 ( V_3 ) ;
F_63 ( V_7 , V_3 ) ;
}
static void F_67 ( struct V_101 * V_96 ,
struct V_102 * V_103 )
{
struct V_1 * V_52 = V_103 -> V_31 ;
struct V_2 * V_66 = & V_52 -> V_4 ;
int V_62 ;
T_1 V_87 ;
V_62 = F_68 ( V_103 , L_10 , & V_87 ) ;
if ( V_62 )
V_87 = 0 ;
switch ( V_87 ) {
case 2 :
V_66 -> V_100 = L_11 ;
break;
case 1 :
V_66 -> V_100 = L_12 ;
break;
case 0 :
default:
V_66 -> V_100 = L_13 ;
break;
}
V_66 -> V_97 = & V_96 -> V_97 ;
V_66 -> V_104 = V_105 ;
V_66 -> V_106 = V_107 ;
V_66 -> V_67 = F_59 ( V_87 ) ;
V_66 -> V_87 = V_87 ;
V_66 -> V_108 . V_52 = & V_109 ;
V_66 -> V_110 = V_111 ;
F_69 ( V_66 ) ;
}
static void F_70 ( struct V_102 * V_103 )
{
struct V_1 * V_52 = V_103 -> V_31 ;
struct V_2 * V_66 = & V_52 -> V_4 ;
F_71 ( V_66 ) ;
}
int F_72 ( struct V_101 * V_96 , struct V_102 * V_103 )
{
struct V_1 * V_52 ;
struct V_102 * V_112 ;
T_1 V_113 ;
int V_62 ;
V_52 = F_73 ( & V_96 -> V_97 , sizeof( * V_52 ) , V_114 ) ;
if ( ! V_52 )
return - V_115 ;
V_112 = F_74 ( V_103 , NULL ) ;
if ( ! V_112 )
return 0 ;
V_62 = F_68 ( V_112 , L_14 , & V_113 ) ;
if ( V_62 ) {
F_35 ( L_15 ) ;
goto V_116;
}
V_52 -> V_76 = V_113 ;
F_75 ( V_112 ) ;
V_52 -> V_96 = V_96 ;
V_103 -> V_31 = V_52 ;
F_76 ( & V_52 -> V_78 ) ;
F_67 ( V_96 , V_103 ) ;
V_52 -> V_117 = true ;
return 0 ;
V_116:
F_75 ( V_112 ) ;
return V_62 ;
}
void F_77 ( struct V_102 * V_103 )
{
struct V_1 * V_52 = V_103 -> V_31 ;
if ( ! V_52 -> V_117 )
return;
F_70 ( V_103 ) ;
}
