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
static enum V_5 F_5 ( struct V_1 * V_16 )
{
enum V_6 V_7 = V_16 -> V_4 . V_17 ;
switch ( V_16 -> V_18 ) {
case V_19 :
case V_20 :
return V_15 ;
case V_21 :
switch ( V_7 ) {
case V_8 :
return V_9 ;
case V_10 :
return V_14 ;
default:
return V_15 ;
}
case V_22 :
switch ( V_7 ) {
case V_8 :
return V_9 ;
case V_13 :
return V_14 ;
case V_10 :
default:
return V_15 ;
}
case V_23 :
return F_3 ( V_7 ) ;
default:
return V_15 ;
}
}
static bool F_6 ( int V_24 , int V_25 , unsigned long V_26 ,
unsigned long V_27 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
if ( V_30 -> V_31 >= 100000000 ) {
if ( V_24 > 1 && V_24 % 2 != 0 )
return false ;
if ( V_25 > 1 && V_25 % 2 != 0 )
return false ;
}
V_30 -> V_32 . V_33 = V_24 ;
V_30 -> V_32 . V_34 = V_25 ;
V_30 -> V_32 . V_26 = V_26 ;
V_30 -> V_32 . V_27 = V_27 ;
return true ;
}
static bool F_7 ( int V_35 , unsigned long V_36 ,
void * V_28 )
{
struct V_29 * V_30 = V_28 ;
V_30 -> V_37 . V_38 [ V_30 -> V_39 ] = V_35 ;
V_30 -> V_37 . V_40 [ V_30 -> V_39 ] = V_36 ;
return F_8 ( V_36 , V_30 -> V_31 , V_30 -> V_41 ,
F_6 , V_30 ) ;
}
static bool F_9 ( int V_42 , int V_43 , unsigned long V_44 ,
unsigned long V_45 ,
void * V_28 )
{
struct V_29 * V_30 = V_28 ;
V_30 -> V_37 . V_42 = V_42 ;
V_30 -> V_37 . V_43 = V_43 ;
V_30 -> V_37 . V_44 = V_44 ;
V_30 -> V_37 . V_45 = V_45 ;
return F_10 ( V_30 -> V_46 , V_45 ,
V_30 -> V_31 , F_11 () ,
F_7 , V_30 ) ;
}
static bool F_12 ( unsigned long V_47 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
V_30 -> V_47 = V_47 ;
return F_8 ( V_47 , V_30 -> V_31 , V_30 -> V_41 ,
F_6 , V_30 ) ;
}
static bool F_13 ( struct V_1 * V_16 , unsigned long V_27 ,
struct V_29 * V_30 )
{
unsigned long V_48 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_46 = V_16 -> V_46 ;
V_30 -> V_39 = F_14 ( V_16 -> V_49 ) ;
V_48 = F_15 ( V_16 -> V_46 -> V_48 ) ;
if ( V_16 -> V_46 -> V_50 -> type == V_51 ) {
unsigned long V_52 , V_53 ;
V_30 -> V_31 = V_27 - 1000 ;
V_30 -> V_41 = V_27 + 1000 ;
V_52 = 0 ;
V_53 = 0 ;
return F_16 ( V_30 -> V_46 , V_48 ,
V_52 , V_53 ,
F_9 , V_30 ) ;
} else {
F_17 ( V_16 -> V_46 , V_48 , V_27 , & V_30 -> V_37 ) ;
V_30 -> V_32 . V_33 = 1 ;
V_30 -> V_32 . V_34 = 1 ;
V_30 -> V_32 . V_26 = V_30 -> V_37 . V_40 [ 0 ] ;
V_30 -> V_32 . V_27 = V_30 -> V_32 . V_26 ;
return true ;
}
}
static bool F_18 ( unsigned long V_27 , struct V_29 * V_30 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < 25 ; ++ V_54 ) {
bool V_55 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( V_27 > 1000 * V_54 * V_54 * V_54 )
V_30 -> V_31 = F_19 ( V_27 - 1000 * V_54 * V_54 * V_54 , 0lu ) ;
else
V_30 -> V_31 = 0 ;
V_30 -> V_41 = V_27 + 1000 * V_54 * V_54 * V_54 ;
V_55 = F_20 ( V_27 , V_30 -> V_31 , F_12 , V_30 ) ;
if ( V_55 )
return V_55 ;
}
return false ;
}
static int F_21 ( struct V_1 * V_16 , enum V_6 V_7 ,
unsigned long V_56 , unsigned long * V_47 , int * V_33 ,
int * V_34 )
{
struct V_29 V_30 ;
int V_57 ;
bool V_55 ;
V_55 = F_13 ( V_16 , V_56 , & V_30 ) ;
if ( ! V_55 )
return - V_58 ;
V_57 = F_22 ( V_16 -> V_46 , & V_30 . V_37 ) ;
if ( V_57 )
return V_57 ;
F_23 ( V_7 , V_16 -> V_49 ) ;
V_16 -> V_59 . V_60 = V_30 . V_32 ;
* V_47 = V_30 . V_37 . V_40 [ V_30 . V_39 ] ;
* V_33 = V_30 . V_32 . V_33 ;
* V_34 = V_30 . V_32 . V_34 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_16 , unsigned long V_56 ,
unsigned long * V_47 , int * V_33 , int * V_34 )
{
struct V_29 V_30 ;
int V_57 ;
bool V_55 ;
V_55 = F_18 ( V_56 , & V_30 ) ;
if ( ! V_55 )
return - V_58 ;
V_57 = F_25 ( V_30 . V_47 ) ;
if ( V_57 )
return V_57 ;
V_16 -> V_59 . V_60 = V_30 . V_32 ;
* V_47 = V_30 . V_47 ;
* V_33 = V_30 . V_32 . V_33 ;
* V_34 = V_30 . V_32 . V_34 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_16 )
{
struct V_2 * V_61 = & V_16 -> V_4 ;
enum V_6 V_7 = V_61 -> V_17 ;
struct V_62 * V_63 = & V_16 -> V_63 ;
int V_33 = 0 , V_34 = 0 ;
unsigned long V_47 = 0 ;
unsigned long V_27 ;
int V_57 = 0 ;
if ( V_16 -> V_46 )
V_57 = F_21 ( V_16 , V_7 , V_63 -> V_64 , & V_47 ,
& V_33 , & V_34 ) ;
else
V_57 = F_24 ( V_16 , V_63 -> V_64 , & V_47 ,
& V_33 , & V_34 ) ;
if ( V_57 )
return V_57 ;
V_27 = V_47 / V_33 / V_34 ;
if ( V_27 != V_63 -> V_64 ) {
F_27 ( L_1 ,
V_63 -> V_64 , V_27 ) ;
V_63 -> V_64 = V_27 ;
}
F_28 ( V_7 , V_63 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_16 )
{
struct V_2 * V_61 = & V_16 -> V_4 ;
enum V_6 V_7 = V_61 -> V_17 ;
V_16 -> V_59 . V_65 = V_66 ;
V_16 -> V_59 . V_67 = false ;
V_16 -> V_59 . V_68 = false ;
V_16 -> V_59 . V_69 = V_16 -> V_70 ;
V_16 -> V_59 . V_71 = 0 ;
F_30 ( V_7 , & V_16 -> V_59 ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_2 * V_61 = & V_16 -> V_4 ;
enum V_6 V_7 = V_61 -> V_17 ;
int V_57 ;
F_32 ( & V_16 -> V_72 ) ;
if ( ! V_61 -> V_73 ) {
F_33 ( L_2 ) ;
V_57 = - V_74 ;
goto V_75;
}
if ( V_16 -> V_76 ) {
V_57 = F_34 ( V_16 -> V_76 ) ;
if ( V_57 )
goto V_77;
}
V_57 = F_35 () ;
if ( V_57 )
goto V_78;
V_57 = F_36 ( V_61 -> V_79 , V_7 ) ;
if ( V_57 )
goto V_80;
if ( V_16 -> V_46 ) {
V_57 = F_37 ( V_16 -> V_46 ) ;
if ( V_57 )
goto V_81;
}
V_57 = F_26 ( V_16 ) ;
if ( V_57 )
goto V_82;
F_29 ( V_16 ) ;
F_38 ( 2 ) ;
V_57 = F_39 ( V_7 ) ;
if ( V_57 )
goto V_83;
F_40 ( & V_16 -> V_72 ) ;
return 0 ;
V_83:
V_82:
if ( V_16 -> V_46 )
F_41 ( V_16 -> V_46 ) ;
V_81:
V_80:
F_42 () ;
V_78:
if ( V_16 -> V_76 )
F_43 ( V_16 -> V_76 ) ;
V_77:
V_75:
F_40 ( & V_16 -> V_72 ) ;
return V_57 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
enum V_6 V_7 = V_16 -> V_4 . V_17 ;
F_32 ( & V_16 -> V_72 ) ;
F_45 ( V_7 ) ;
if ( V_16 -> V_46 ) {
F_23 ( V_7 , V_15 ) ;
F_41 ( V_16 -> V_46 ) ;
}
F_42 () ;
if ( V_16 -> V_76 )
F_43 ( V_16 -> V_76 ) ;
F_40 ( & V_16 -> V_72 ) ;
}
static void F_46 ( struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_47 ( L_3 ) ;
F_32 ( & V_16 -> V_72 ) ;
V_16 -> V_63 = * V_63 ;
F_40 ( & V_16 -> V_72 ) ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_32 ( & V_16 -> V_72 ) ;
* V_63 = V_16 -> V_63 ;
F_40 ( & V_16 -> V_72 ) ;
}
static int F_49 ( struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
enum V_6 V_7 = V_16 -> V_4 . V_17 ;
int V_33 , V_34 ;
unsigned long V_47 ;
unsigned long V_27 ;
struct V_29 V_30 ;
bool V_55 ;
if ( V_63 -> V_84 % 8 != 0 )
return - V_58 ;
if ( ! F_50 ( V_7 , V_63 ) )
return - V_58 ;
if ( V_63 -> V_64 == 0 )
return - V_58 ;
if ( V_16 -> V_46 ) {
V_55 = F_13 ( V_16 , V_63 -> V_64 , & V_30 ) ;
if ( ! V_55 )
return - V_58 ;
V_47 = V_30 . V_37 . V_40 [ V_30 . V_39 ] ;
} else {
V_55 = F_18 ( V_63 -> V_64 , & V_30 ) ;
if ( ! V_55 )
return - V_58 ;
V_47 = V_30 . V_47 ;
}
V_33 = V_30 . V_32 . V_33 ;
V_34 = V_30 . V_32 . V_34 ;
V_27 = V_47 / V_33 / V_34 ;
V_63 -> V_64 = V_27 ;
return 0 ;
}
static int F_51 ( struct V_85 * V_46 )
{
int V_57 ;
V_57 = F_37 ( V_46 ) ;
if ( V_57 )
return V_57 ;
F_41 ( V_46 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_16 )
{
struct V_86 * V_87 ;
if ( ! F_53 ( V_88 ) )
return 0 ;
if ( V_16 -> V_76 )
return 0 ;
V_87 = F_54 ( & V_16 -> V_89 -> V_90 , L_4 ) ;
if ( F_55 ( V_87 ) ) {
if ( F_56 ( V_87 ) != - V_91 )
F_33 ( L_5 ) ;
return F_56 ( V_87 ) ;
}
V_16 -> V_76 = V_87 ;
return 0 ;
}
static void F_57 ( struct V_1 * V_16 )
{
struct V_85 * V_46 ;
if ( V_16 -> V_46 )
return;
V_16 -> V_49 = F_5 ( V_16 ) ;
V_46 = F_4 ( V_16 -> V_49 ) ;
if ( ! V_46 )
return;
if ( F_51 ( V_46 ) ) {
F_27 ( L_6 ) ;
return;
}
V_16 -> V_46 = V_46 ;
}
static enum V_6 F_58 ( struct V_1 * V_16 , int V_79 )
{
switch ( V_16 -> V_18 ) {
case V_19 :
case V_20 :
return V_8 ;
case V_23 :
switch ( V_79 ) {
case 2 :
return V_13 ;
case 1 :
return V_10 ;
case 0 :
default:
return V_8 ;
}
case V_21 :
return V_10 ;
case V_22 :
return V_13 ;
default:
F_27 ( L_7 ) ;
return V_8 ;
}
}
static int F_59 ( struct V_2 * V_3 ,
struct V_2 * V_92 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
enum V_6 V_7 = V_16 -> V_4 . V_17 ;
int V_57 ;
V_57 = F_52 ( V_16 ) ;
if ( V_57 )
return V_57 ;
F_57 ( V_16 ) ;
V_57 = F_60 ( V_7 , V_3 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_61 ( V_3 , V_92 ) ;
if ( V_57 ) {
F_33 ( L_8 ,
V_92 -> V_93 ) ;
F_62 ( V_7 , V_3 ) ;
return V_57 ;
}
return 0 ;
}
static void F_63 ( struct V_2 * V_3 ,
struct V_2 * V_92 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
enum V_6 V_7 = V_16 -> V_4 . V_17 ;
F_64 ( V_92 != V_3 -> V_92 ) ;
if ( V_92 != V_3 -> V_92 )
return;
F_65 ( V_3 ) ;
F_62 ( V_7 , V_3 ) ;
}
static void F_66 ( struct V_1 * V_16 , struct V_94 * V_95 )
{
struct V_2 * V_61 = & V_16 -> V_4 ;
int V_57 ;
T_1 V_79 ;
V_57 = F_67 ( V_95 , L_9 , & V_79 ) ;
if ( V_57 )
V_79 = 0 ;
switch ( V_79 ) {
case 2 :
V_61 -> V_93 = L_10 ;
break;
case 1 :
V_61 -> V_93 = L_11 ;
break;
case 0 :
default:
V_61 -> V_93 = L_12 ;
break;
}
V_61 -> V_90 = & V_16 -> V_89 -> V_90 ;
V_61 -> V_96 = V_97 ;
V_61 -> V_98 = V_99 ;
V_61 -> V_17 = F_58 ( V_16 , V_79 ) ;
V_61 -> V_79 = V_79 ;
V_61 -> V_100 . V_16 = & V_101 ;
V_61 -> V_102 = V_103 ;
F_68 ( V_61 ) ;
}
static void F_69 ( struct V_94 * V_95 )
{
struct V_1 * V_16 = V_95 -> V_28 ;
struct V_2 * V_61 = & V_16 -> V_4 ;
F_70 ( V_61 ) ;
}
int F_71 ( struct V_104 * V_89 , struct V_94 * V_95 ,
enum V_18 V_18 )
{
struct V_1 * V_16 ;
struct V_94 * V_105 ;
T_1 V_106 ;
int V_57 ;
V_16 = F_72 ( & V_89 -> V_90 , sizeof( * V_16 ) , V_107 ) ;
if ( ! V_16 )
return - V_108 ;
V_105 = F_73 ( V_95 , NULL ) ;
if ( ! V_105 )
return 0 ;
V_57 = F_67 ( V_105 , L_13 , & V_106 ) ;
if ( V_57 ) {
F_33 ( L_14 ) ;
goto V_109;
}
V_16 -> V_70 = V_106 ;
F_74 ( V_105 ) ;
V_16 -> V_89 = V_89 ;
V_16 -> V_18 = V_18 ;
V_95 -> V_28 = V_16 ;
F_75 ( & V_16 -> V_72 ) ;
F_66 ( V_16 , V_95 ) ;
V_16 -> V_110 = true ;
return 0 ;
V_109:
F_74 ( V_105 ) ;
return V_57 ;
}
void F_76 ( struct V_94 * V_95 )
{
struct V_1 * V_16 = V_95 -> V_28 ;
if ( ! V_16 -> V_110 )
return;
F_69 ( V_95 ) ;
}
