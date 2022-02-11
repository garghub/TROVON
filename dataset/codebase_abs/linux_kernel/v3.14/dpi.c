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
if ( V_26 -> V_27 >= 100000000 ) {
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
if ( V_31 > 1 && V_31 % 2 != 0 && V_26 -> V_27 >= 100000000 )
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
static bool F_11 ( unsigned long V_42 , void * V_24 )
{
struct V_25 * V_26 = V_24 ;
V_26 -> V_42 = V_42 ;
return F_8 ( V_42 , V_26 -> V_27 , V_26 -> V_35 ,
F_6 , V_26 ) ;
}
static bool F_12 ( unsigned long V_23 , struct V_25 * V_26 )
{
unsigned long V_43 ;
unsigned long V_44 , V_45 ;
V_43 = F_13 ( V_46 . V_41 ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_41 = V_46 . V_41 ;
V_26 -> V_27 = V_23 - 1000 ;
V_26 -> V_35 = V_23 + 1000 ;
V_26 -> V_33 . V_43 = V_43 ;
V_44 = 0 ;
V_45 = 0 ;
return F_14 ( V_46 . V_41 , V_43 ,
V_44 , V_45 ,
F_9 , V_26 ) ;
}
static bool F_15 ( unsigned long V_23 , struct V_25 * V_26 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < 25 ; ++ V_47 ) {
bool V_48 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
if ( V_23 > 1000 * V_47 * V_47 * V_47 )
V_26 -> V_27 = F_16 ( V_23 - 1000 * V_47 * V_47 * V_47 , 0lu ) ;
else
V_26 -> V_27 = 0 ;
V_26 -> V_35 = V_23 + 1000 * V_47 * V_47 * V_47 ;
V_48 = F_17 ( V_23 , V_26 -> V_27 , F_11 , V_26 ) ;
if ( V_48 )
return V_48 ;
}
return false ;
}
static int F_18 ( enum V_2 V_3 ,
unsigned long V_49 , unsigned long * V_42 , int * V_29 ,
int * V_30 )
{
struct V_25 V_26 ;
int V_50 ;
bool V_48 ;
V_48 = F_12 ( V_49 , & V_26 ) ;
if ( ! V_48 )
return - V_51 ;
V_50 = F_19 ( V_46 . V_41 , & V_26 . V_33 ) ;
if ( V_50 )
return V_50 ;
F_20 ( V_3 ,
F_4 ( V_3 ) ) ;
V_46 . V_52 . V_53 = V_26 . V_28 ;
* V_42 = V_26 . V_33 . V_34 ;
* V_29 = V_26 . V_28 . V_29 ;
* V_30 = V_26 . V_28 . V_30 ;
return 0 ;
}
static int F_21 ( unsigned long V_49 , unsigned long * V_42 ,
int * V_29 , int * V_30 )
{
struct V_25 V_26 ;
int V_50 ;
bool V_48 ;
V_48 = F_15 ( V_49 , & V_26 ) ;
if ( ! V_48 )
return - V_51 ;
V_50 = F_22 ( V_26 . V_42 ) ;
if ( V_50 )
return V_50 ;
V_46 . V_52 . V_53 = V_26 . V_28 ;
* V_42 = V_26 . V_42 ;
* V_29 = V_26 . V_28 . V_29 ;
* V_30 = V_26 . V_28 . V_30 ;
return 0 ;
}
static int F_23 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = & V_46 . V_58 ;
int V_29 = 0 , V_30 = 0 ;
unsigned long V_42 = 0 ;
unsigned long V_23 ;
int V_50 = 0 ;
if ( V_46 . V_41 )
V_50 = F_18 ( V_55 -> V_59 , V_57 -> V_60 * 1000 , & V_42 ,
& V_29 , & V_30 ) ;
else
V_50 = F_21 ( V_57 -> V_60 * 1000 , & V_42 ,
& V_29 , & V_30 ) ;
if ( V_50 )
return V_50 ;
V_23 = V_42 / V_29 / V_30 / 1000 ;
if ( V_23 != V_57 -> V_60 ) {
F_24 ( L_1
L_2 ,
V_57 -> V_60 , V_23 ) ;
V_57 -> V_60 = V_23 ;
}
F_25 ( V_55 , V_57 ) ;
return 0 ;
}
static void F_26 ( struct V_54 * V_55 )
{
V_46 . V_52 . V_61 = V_62 ;
V_46 . V_52 . V_63 = false ;
V_46 . V_52 . V_64 = false ;
V_46 . V_52 . V_65 = V_46 . V_66 ;
V_46 . V_52 . V_67 = 0 ;
F_27 ( V_55 , & V_46 . V_52 ) ;
}
static int F_28 ( struct V_68 * V_69 )
{
struct V_68 * V_70 = & V_46 . V_71 ;
int V_50 ;
F_29 ( & V_46 . V_72 ) ;
if ( F_30 ( V_73 ) && ! V_46 . V_74 ) {
F_31 ( L_3 ) ;
V_50 = - V_75 ;
goto V_76;
}
if ( V_70 == NULL || V_70 -> V_77 == NULL ) {
F_31 ( L_4 ) ;
V_50 = - V_75 ;
goto V_78;
}
if ( F_30 ( V_73 ) ) {
V_50 = F_32 ( V_46 . V_74 ) ;
if ( V_50 )
goto V_79;
}
V_50 = F_33 () ;
if ( V_50 )
goto V_80;
V_50 = F_34 ( V_70 -> V_77 -> V_59 ) ;
if ( V_50 )
goto V_81;
if ( V_46 . V_41 ) {
V_50 = F_35 ( V_46 . V_41 ) ;
if ( V_50 )
goto V_82;
V_50 = F_36 ( V_46 . V_41 , 0 , 1 ) ;
if ( V_50 )
goto V_83;
}
V_50 = F_23 ( V_70 -> V_77 ) ;
if ( V_50 )
goto V_84;
F_26 ( V_70 -> V_77 ) ;
F_37 ( 2 ) ;
V_50 = F_38 ( V_70 -> V_77 ) ;
if ( V_50 )
goto V_85;
F_39 ( & V_46 . V_72 ) ;
return 0 ;
V_85:
V_84:
if ( V_46 . V_41 )
F_40 ( V_46 . V_41 , true ) ;
V_83:
if ( V_46 . V_41 )
F_41 ( V_46 . V_41 ) ;
V_82:
V_81:
F_42 () ;
V_80:
if ( F_30 ( V_73 ) )
F_43 ( V_46 . V_74 ) ;
V_79:
V_78:
V_76:
F_39 ( & V_46 . V_72 ) ;
return V_50 ;
}
static void F_44 ( struct V_68 * V_69 )
{
struct V_54 * V_55 = V_46 . V_71 . V_77 ;
F_29 ( & V_46 . V_72 ) ;
F_45 ( V_55 ) ;
if ( V_46 . V_41 ) {
F_20 ( V_55 -> V_59 , V_19 ) ;
F_40 ( V_46 . V_41 , true ) ;
F_41 ( V_46 . V_41 ) ;
}
F_42 () ;
if ( F_30 ( V_73 ) )
F_43 ( V_46 . V_74 ) ;
F_39 ( & V_46 . V_72 ) ;
}
static void F_46 ( struct V_68 * V_69 ,
struct V_56 * V_58 )
{
F_47 ( L_5 ) ;
F_29 ( & V_46 . V_72 ) ;
V_46 . V_58 = * V_58 ;
F_39 ( & V_46 . V_72 ) ;
}
static void F_48 ( struct V_68 * V_69 ,
struct V_56 * V_58 )
{
F_29 ( & V_46 . V_72 ) ;
* V_58 = V_46 . V_58 ;
F_39 ( & V_46 . V_72 ) ;
}
static int F_49 ( struct V_68 * V_69 ,
struct V_56 * V_58 )
{
struct V_54 * V_55 = V_46 . V_71 . V_77 ;
int V_29 , V_30 ;
unsigned long V_42 ;
unsigned long V_23 ;
struct V_25 V_26 ;
bool V_48 ;
if ( V_55 && ! F_50 ( V_55 -> V_59 , V_58 ) )
return - V_51 ;
if ( V_58 -> V_60 == 0 )
return - V_51 ;
if ( V_46 . V_41 ) {
V_48 = F_12 ( V_58 -> V_60 * 1000 , & V_26 ) ;
if ( ! V_48 )
return - V_51 ;
V_42 = V_26 . V_33 . V_34 ;
} else {
V_48 = F_15 ( V_58 -> V_60 * 1000 , & V_26 ) ;
if ( ! V_48 )
return - V_51 ;
V_42 = V_26 . V_42 ;
}
V_29 = V_26 . V_28 . V_29 ;
V_30 = V_26 . V_28 . V_30 ;
V_23 = V_42 / V_29 / V_30 / 1000 ;
V_58 -> V_60 = V_23 ;
return 0 ;
}
static void F_51 ( struct V_68 * V_69 , int V_66 )
{
F_29 ( & V_46 . V_72 ) ;
V_46 . V_66 = V_66 ;
F_39 ( & V_46 . V_72 ) ;
}
static int F_52 ( struct V_1 * V_41 )
{
int V_50 ;
V_50 = F_35 ( V_41 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_36 ( V_41 , 0 , 1 ) ;
if ( V_50 ) {
F_41 ( V_41 ) ;
return V_50 ;
}
F_40 ( V_41 , true ) ;
F_41 ( V_41 ) ;
return 0 ;
}
static int F_53 ( void )
{
struct V_86 * V_87 ;
if ( ! F_30 ( V_73 ) )
return 0 ;
if ( V_46 . V_74 )
return 0 ;
V_87 = F_54 ( & V_46 . V_88 -> V_89 , L_6 ) ;
if ( F_55 ( V_87 ) ) {
if ( F_56 ( V_87 ) != - V_90 )
F_31 ( L_7 ) ;
return F_56 ( V_87 ) ;
}
V_46 . V_74 = V_87 ;
return 0 ;
}
static void F_57 ( void )
{
struct V_1 * V_41 ;
if ( V_46 . V_41 )
return;
V_41 = F_1 ( V_46 . V_71 . V_91 ) ;
if ( ! V_41 )
return;
if ( F_52 ( V_41 ) ) {
F_24 ( L_8 ) ;
return;
}
V_46 . V_41 = V_41 ;
}
static enum V_2 F_58 ( void )
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
F_24 ( L_9 ) ;
return V_12 ;
}
}
static int F_59 ( struct V_68 * V_69 ,
struct V_68 * V_92 )
{
struct V_54 * V_55 ;
int V_50 ;
V_50 = F_53 () ;
if ( V_50 )
return V_50 ;
F_57 () ;
V_55 = F_60 ( V_69 -> V_91 ) ;
if ( ! V_55 )
return - V_75 ;
V_50 = F_61 ( V_55 , V_69 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_62 ( V_69 , V_92 ) ;
if ( V_50 ) {
F_31 ( L_10 ,
V_92 -> V_93 ) ;
F_63 ( V_55 , V_69 ) ;
return V_50 ;
}
return 0 ;
}
static void F_64 ( struct V_68 * V_69 ,
struct V_68 * V_92 )
{
F_5 ( V_92 != V_69 -> V_92 ) ;
if ( V_92 != V_69 -> V_92 )
return;
F_65 ( V_69 ) ;
if ( V_69 -> V_77 )
F_63 ( V_69 -> V_77 , V_69 ) ;
}
static void F_66 ( struct V_1 * V_88 )
{
struct V_68 * V_70 = & V_46 . V_71 ;
V_70 -> V_89 = & V_88 -> V_89 ;
V_70 -> V_59 = V_94 ;
V_70 -> V_95 = V_96 ;
V_70 -> V_93 = L_11 ;
V_70 -> V_91 = F_58 () ;
V_70 -> V_97 . V_46 = & V_98 ;
V_70 -> V_99 = V_100 ;
F_67 ( V_70 ) ;
}
static void T_1 F_68 ( struct V_1 * V_88 )
{
struct V_68 * V_70 = & V_46 . V_71 ;
F_69 ( V_70 ) ;
}
static int F_70 ( struct V_1 * V_88 )
{
V_46 . V_88 = V_88 ;
F_71 ( & V_46 . V_72 ) ;
F_66 ( V_88 ) ;
return 0 ;
}
static int T_1 F_72 ( struct V_1 * V_88 )
{
F_68 ( V_88 ) ;
return 0 ;
}
int T_2 F_73 ( void )
{
return F_74 ( & V_101 ) ;
}
void T_1 F_75 ( void )
{
F_76 ( & V_101 ) ;
}
