static int F_1 ( void )
{
int V_1 ;
F_2 ( L_1 ) ;
V_1 = F_3 ( & V_2 . V_3 -> V_4 ) ;
F_4 ( V_1 < 0 ) ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
static void F_5 ( void )
{
int V_1 ;
F_2 ( L_2 ) ;
V_1 = F_6 ( & V_2 . V_3 -> V_4 ) ;
F_4 ( V_1 < 0 && V_1 != - V_5 ) ;
}
static T_1 F_7 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
T_2 V_10 ;
V_10 = F_8 ( V_9 ) ;
F_9 ( V_9 , V_10 ) ;
if ( ( V_10 & V_11 ) &&
V_10 & V_12 ) {
F_10 ( V_9 , V_13 ) ;
F_9 ( V_9 , V_11 |
V_12 ) ;
F_10 ( V_9 , V_14 ) ;
} else if ( V_10 & V_11 ) {
F_10 ( V_9 , V_15 ) ;
} else if ( V_10 & V_12 ) {
F_10 ( V_9 , V_14 ) ;
}
return V_16 ;
}
static int F_11 ( void )
{
int V_1 ;
struct V_17 * V_18 ;
if ( V_2 . V_19 != NULL )
return 0 ;
V_18 = F_12 ( & V_2 . V_3 -> V_4 , L_3 ) ;
if ( F_13 ( V_18 ) ) {
if ( F_14 ( V_18 ) != - V_20 )
F_15 ( L_4 ) ;
return F_14 ( V_18 ) ;
}
if ( F_16 ( V_18 ) ) {
V_1 = F_17 ( V_18 , 1800000 , 1800000 ) ;
if ( V_1 ) {
F_18 ( V_18 ) ;
F_19 ( L_5 ) ;
return V_1 ;
}
}
V_2 . V_19 = V_18 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 )
{
int V_1 ;
V_1 = F_21 ( V_2 . V_19 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 () ;
if ( V_1 )
goto V_23;
F_22 ( V_24 ) ;
V_2 . V_25 = true ;
return 0 ;
V_23:
F_23 ( V_2 . V_19 ) ;
return V_1 ;
}
static void F_24 ( struct V_21 * V_22 )
{
V_2 . V_25 = false ;
F_5 () ;
F_23 ( V_2 . V_19 ) ;
}
static int F_25 ( struct V_21 * V_22 )
{
int V_1 ;
struct V_26 * V_27 ;
struct V_28 * V_29 = V_2 . V_30 . V_31 ;
unsigned long V_32 ;
struct V_8 * V_9 = & V_2 . V_9 ;
V_1 = F_20 ( V_22 ) ;
if ( V_1 )
return V_1 ;
F_26 ( V_9 , 0xffffffff ) ;
F_9 ( V_9 , 0xffffffff ) ;
V_27 = & V_2 . V_33 . V_34 ;
F_2 ( L_6 , V_27 -> V_35 , V_27 -> V_36 ) ;
V_32 = V_27 -> V_37 / 1000 ;
F_27 ( & V_2 . V_38 , F_28 ( V_2 . V_39 ) , V_32 ) ;
V_1 = F_29 ( & V_2 . V_38 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_2 ( L_7 ) ;
goto V_40;
}
V_1 = F_30 ( & V_2 . V_32 , & V_2 . V_33 ) ;
if ( V_1 ) {
F_2 ( L_8 ) ;
goto V_41;
}
V_1 = F_10 ( V_9 , V_14 ) ;
if ( V_1 )
goto V_42;
F_31 ( & V_2 . V_43 , & V_2 . V_9 , & V_2 . V_33 ) ;
F_32 ( 0 ) ;
F_33 ( V_29 , V_27 ) ;
V_1 = F_34 ( & V_2 . V_9 ) ;
if ( V_1 )
goto V_44;
V_1 = F_35 ( V_29 ) ;
if ( V_1 )
goto V_45;
F_36 ( V_9 ,
V_11 | V_12 ) ;
return 0 ;
V_45:
F_37 ( & V_2 . V_9 ) ;
V_44:
V_41:
F_10 ( & V_2 . V_9 , V_13 ) ;
V_42:
F_38 ( & V_2 . V_38 , & V_2 . V_9 ) ;
V_40:
F_24 ( V_22 ) ;
return - V_46 ;
}
static void F_39 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = V_2 . V_30 . V_31 ;
F_26 ( & V_2 . V_9 , 0xffffffff ) ;
F_40 ( V_29 ) ;
F_37 ( & V_2 . V_9 ) ;
F_10 ( & V_2 . V_9 , V_13 ) ;
F_38 ( & V_2 . V_38 , & V_2 . V_9 ) ;
F_24 ( V_22 ) ;
}
static int F_41 ( struct V_21 * V_22 ,
struct V_26 * V_34 )
{
struct V_21 * V_47 = & V_2 . V_30 ;
if ( ! F_42 ( V_47 -> V_48 , V_34 ) )
return - V_49 ;
return 0 ;
}
static void F_43 ( struct V_21 * V_22 ,
struct V_26 * V_34 )
{
struct V_50 V_51 ;
const struct V_52 * V_53 ;
F_44 ( & V_2 . V_54 ) ;
V_51 = F_45 ( V_34 ) ;
V_2 . V_33 . V_51 = V_51 ;
V_53 = F_46 ( V_51 . V_55 , V_51 . V_56 ) ;
if ( V_53 != NULL ) {
V_2 . V_33 = * V_53 ;
F_47 ( V_53 -> V_34 . V_37 ) ;
} else {
V_2 . V_33 . V_34 = * V_34 ;
V_2 . V_33 . V_51 . V_56 = 0 ;
V_2 . V_33 . V_51 . V_55 = V_57 ;
F_47 ( V_34 -> V_37 ) ;
}
F_2 ( L_9 , V_2 . V_33 . V_51 . V_55 == V_57 ?
L_10 : L_11 , V_2 . V_33 . V_51 . V_56 ) ;
F_48 ( & V_2 . V_54 ) ;
}
static void F_49 ( struct V_21 * V_22 ,
struct V_26 * V_34 )
{
const struct V_52 * V_33 ;
struct V_50 V_51 = V_2 . V_33 . V_51 ;
V_33 = F_46 ( V_51 . V_55 , V_51 . V_56 ) ;
if ( V_33 == NULL )
V_33 = F_50 () ;
memcpy ( V_34 , & V_33 -> V_34 , sizeof( V_33 -> V_34 ) ) ;
}
static void F_51 ( struct V_58 * V_59 )
{
F_44 ( & V_2 . V_54 ) ;
if ( F_1 () ) {
F_48 ( & V_2 . V_54 ) ;
return;
}
F_52 ( & V_2 . V_9 , V_59 ) ;
F_53 ( & V_2 . V_38 , V_59 ) ;
F_54 ( & V_2 . V_32 , V_59 ) ;
F_55 ( & V_2 . V_43 , V_59 ) ;
F_5 () ;
F_48 ( & V_2 . V_54 ) ;
}
static int F_56 ( T_3 * V_60 , int V_61 )
{
int V_1 ;
F_44 ( & V_2 . V_54 ) ;
V_1 = F_1 () ;
F_57 ( V_1 ) ;
V_1 = F_58 ( & V_2 . V_43 , V_60 , V_61 ) ;
F_5 () ;
F_48 ( & V_2 . V_54 ) ;
return V_1 ;
}
static int F_59 ( struct V_21 * V_22 )
{
struct V_21 * V_47 = & V_2 . V_30 ;
int V_1 = 0 ;
F_2 ( L_12 ) ;
F_44 ( & V_2 . V_54 ) ;
if ( V_47 == NULL || V_47 -> V_31 == NULL ) {
F_15 ( L_13 ) ;
V_1 = - V_62 ;
goto V_63;
}
V_1 = F_25 ( V_22 ) ;
if ( V_1 ) {
F_15 ( L_14 ) ;
goto V_63;
}
F_48 ( & V_2 . V_54 ) ;
return 0 ;
V_63:
F_48 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_60 ( struct V_21 * V_22 )
{
F_2 ( L_15 ) ;
F_44 ( & V_2 . V_54 ) ;
F_39 ( V_22 ) ;
F_48 ( & V_2 . V_54 ) ;
}
static int F_61 ( struct V_21 * V_22 )
{
int V_1 = 0 ;
F_2 ( L_16 ) ;
F_44 ( & V_2 . V_54 ) ;
V_1 = F_20 ( V_22 ) ;
if ( V_1 ) {
F_15 ( L_14 ) ;
goto V_63;
}
F_48 ( & V_2 . V_54 ) ;
return 0 ;
V_63:
F_48 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_62 ( struct V_21 * V_22 )
{
F_2 ( L_17 ) ;
F_44 ( & V_2 . V_54 ) ;
F_24 ( V_22 ) ;
F_48 ( & V_2 . V_54 ) ;
}
static int F_63 ( struct V_64 * V_3 )
{
struct V_65 * V_65 ;
V_65 = F_64 ( & V_3 -> V_4 , L_18 ) ;
if ( F_13 ( V_65 ) ) {
F_15 ( L_19 ) ;
return F_14 ( V_65 ) ;
}
V_2 . V_39 = V_65 ;
return 0 ;
}
static int F_65 ( struct V_21 * V_22 ,
struct V_21 * V_66 )
{
struct V_28 * V_29 ;
int V_1 ;
V_1 = F_11 () ;
if ( V_1 )
return V_1 ;
V_29 = F_66 ( V_22 -> V_48 ) ;
if ( ! V_29 )
return - V_62 ;
V_1 = F_67 ( V_29 , V_22 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_68 ( V_22 , V_66 ) ;
if ( V_1 ) {
F_15 ( L_20 ,
V_66 -> V_67 ) ;
F_69 ( V_29 , V_22 ) ;
return V_1 ;
}
return 0 ;
}
static void F_70 ( struct V_21 * V_22 ,
struct V_21 * V_66 )
{
F_4 ( V_66 != V_22 -> V_66 ) ;
if ( V_66 != V_22 -> V_66 )
return;
F_71 ( V_22 ) ;
if ( V_22 -> V_31 )
F_69 ( V_22 -> V_31 , V_22 ) ;
}
static int F_72 ( struct V_21 * V_22 ,
T_3 * V_68 , int V_61 )
{
bool V_69 ;
int V_1 ;
V_69 = V_2 . V_25 == false ;
if ( V_69 ) {
V_1 = F_61 ( V_22 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_56 ( V_68 , V_61 ) ;
if ( V_69 )
F_62 ( V_22 ) ;
return V_1 ;
}
static int F_73 ( struct V_21 * V_22 )
{
int V_1 ;
F_44 ( & V_2 . V_54 ) ;
if ( ! F_74 ( V_2 . V_33 . V_51 . V_55 ) ) {
V_1 = - V_70 ;
goto V_71;
}
V_1 = F_75 ( & V_2 . V_9 , true ) ;
if ( V_1 )
goto V_71;
F_48 ( & V_2 . V_54 ) ;
return 0 ;
V_71:
F_48 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_76 ( struct V_21 * V_22 )
{
F_75 ( & V_2 . V_9 , false ) ;
}
static int F_77 ( struct V_21 * V_22 )
{
return F_78 ( & V_2 . V_43 , & V_2 . V_9 ) ;
}
static void F_79 ( struct V_21 * V_22 )
{
F_80 ( & V_2 . V_43 , & V_2 . V_9 ) ;
}
static bool F_81 ( struct V_21 * V_22 )
{
bool V_1 ;
F_44 ( & V_2 . V_54 ) ;
V_1 = F_74 ( V_2 . V_33 . V_51 . V_55 ) ;
F_48 ( & V_2 . V_54 ) ;
return V_1 ;
}
static int F_82 ( struct V_21 * V_22 ,
struct V_72 * V_73 )
{
int V_1 ;
T_2 V_74 = V_2 . V_33 . V_34 . V_37 ;
F_44 ( & V_2 . V_54 ) ;
if ( ! F_74 ( V_2 . V_33 . V_51 . V_55 ) ) {
V_1 = - V_70 ;
goto V_71;
}
V_1 = F_83 ( & V_2 . V_43 , & V_2 . V_9 , V_73 , V_74 ) ;
if ( V_1 )
goto V_71;
F_48 ( & V_2 . V_54 ) ;
return 0 ;
V_71:
F_48 ( & V_2 . V_54 ) ;
return V_1 ;
}
static int F_73 ( struct V_21 * V_22 )
{
return - V_70 ;
}
static void F_76 ( struct V_21 * V_22 )
{
}
static int F_77 ( struct V_21 * V_22 )
{
return - V_70 ;
}
static void F_79 ( struct V_21 * V_22 )
{
}
static bool F_81 ( struct V_21 * V_22 )
{
return false ;
}
static int F_82 ( struct V_21 * V_22 ,
struct V_72 * V_73 )
{
return - V_70 ;
}
static void F_84 ( struct V_64 * V_3 )
{
struct V_21 * V_47 = & V_2 . V_30 ;
V_47 -> V_4 = & V_3 -> V_4 ;
V_47 -> V_75 = V_76 ;
V_47 -> V_77 = V_78 ;
V_47 -> V_67 = L_21 ;
V_47 -> V_48 = V_79 ;
V_47 -> V_80 . V_2 = & V_81 ;
V_47 -> V_82 = V_83 ;
F_85 ( V_47 ) ;
}
static void T_4 F_86 ( struct V_64 * V_3 )
{
struct V_21 * V_47 = & V_2 . V_30 ;
F_87 ( V_47 ) ;
}
static int F_88 ( struct V_64 * V_3 )
{
struct V_84 * V_85 = V_3 -> V_4 . V_86 ;
struct V_84 * V_87 ;
int V_1 ;
V_87 = F_89 ( V_85 ) ;
if ( ! V_87 )
return 0 ;
V_1 = F_90 ( V_3 , V_87 , & V_2 . V_32 ) ;
if ( V_1 )
goto V_71;
F_91 ( V_87 ) ;
return 0 ;
V_71:
F_91 ( V_87 ) ;
return V_1 ;
}
static int F_92 ( struct V_64 * V_3 )
{
int V_1 ;
int V_6 ;
V_2 . V_3 = V_3 ;
F_93 ( & V_2 . V_54 ) ;
if ( V_3 -> V_4 . V_86 ) {
V_1 = F_88 ( V_3 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_94 ( V_3 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_95 ( V_3 , & V_2 . V_38 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_96 ( V_3 , & V_2 . V_32 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_97 ( V_3 , & V_2 . V_43 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_63 ( V_3 ) ;
if ( V_1 ) {
F_15 ( L_22 ) ;
return V_1 ;
}
V_6 = F_98 ( V_3 , 0 ) ;
if ( V_6 < 0 ) {
F_15 ( L_23 ) ;
return - V_62 ;
}
V_1 = F_99 ( & V_3 -> V_4 , V_6 ,
NULL , F_7 ,
V_88 , L_24 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_15 ( L_25 ) ;
return V_1 ;
}
F_100 ( & V_3 -> V_4 ) ;
F_84 ( V_3 ) ;
F_101 ( L_26 , F_51 ) ;
return 0 ;
}
static int T_4 F_102 ( struct V_64 * V_3 )
{
F_86 ( V_3 ) ;
F_103 ( & V_3 -> V_4 ) ;
return 0 ;
}
static int F_104 ( struct V_89 * V_4 )
{
F_105 ( V_2 . V_39 ) ;
F_106 () ;
return 0 ;
}
static int F_107 ( struct V_89 * V_4 )
{
int V_1 ;
V_1 = F_108 () ;
if ( V_1 < 0 )
return V_1 ;
F_109 ( V_2 . V_39 ) ;
return 0 ;
}
int T_5 F_110 ( void )
{
return F_111 ( & V_90 ) ;
}
void T_4 F_112 ( void )
{
F_113 ( & V_90 ) ;
}
