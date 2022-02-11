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
static int F_7 ( void )
{
struct V_6 * V_7 ;
if ( V_2 . V_8 != NULL )
return 0 ;
V_7 = F_8 ( & V_2 . V_3 -> V_4 , L_3 ) ;
if ( F_9 ( V_7 ) ) {
if ( F_10 ( V_7 ) != - V_9 )
F_11 ( L_4 ) ;
return F_10 ( V_7 ) ;
}
V_2 . V_8 = V_7 ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 )
{
int V_1 ;
V_1 = F_13 ( V_2 . V_8 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 () ;
if ( V_1 )
goto V_12;
F_14 ( V_13 ) ;
V_2 . V_14 = true ;
return 0 ;
V_12:
F_15 ( V_2 . V_8 ) ;
return V_1 ;
}
static void F_16 ( struct V_10 * V_11 )
{
V_2 . V_14 = false ;
F_5 () ;
F_15 ( V_2 . V_8 ) ;
}
static int F_17 ( struct V_10 * V_11 )
{
int V_1 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_2 . V_19 . V_20 ;
unsigned long V_21 ;
V_1 = F_12 ( V_11 ) ;
if ( V_1 )
return V_1 ;
V_16 = & V_2 . V_22 . V_23 ;
F_2 ( L_5 , V_16 -> V_24 , V_16 -> V_25 ) ;
V_21 = V_16 -> V_26 / 1000 ;
F_18 ( & V_2 . V_27 , F_19 ( V_2 . V_28 ) , V_21 ) ;
V_1 = F_20 ( & V_2 . V_27 , & V_2 . V_29 ) ;
if ( V_1 ) {
F_2 ( L_6 ) ;
goto V_30;
}
V_1 = F_21 ( & V_2 . V_21 , & V_2 . V_29 , & V_2 . V_22 ) ;
if ( V_1 ) {
F_2 ( L_7 ) ;
goto V_31;
}
F_22 ( & V_2 . V_32 , & V_2 . V_29 , & V_2 . V_22 ) ;
F_23 ( 0 ) ;
F_24 ( V_18 , V_16 ) ;
V_1 = F_25 ( & V_2 . V_29 ) ;
if ( V_1 )
goto V_33;
V_1 = F_26 ( V_18 ) ;
if ( V_1 )
goto V_34;
return 0 ;
V_34:
F_27 ( & V_2 . V_29 ) ;
V_33:
F_28 ( & V_2 . V_21 , & V_2 . V_29 ) ;
V_31:
F_29 ( & V_2 . V_27 , & V_2 . V_29 ) ;
V_30:
F_16 ( V_11 ) ;
return - V_35 ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_17 * V_18 = V_2 . V_19 . V_20 ;
F_31 ( V_18 ) ;
F_27 ( & V_2 . V_29 ) ;
F_28 ( & V_2 . V_21 , & V_2 . V_29 ) ;
F_29 ( & V_2 . V_27 , & V_2 . V_29 ) ;
F_16 ( V_11 ) ;
}
static int F_32 ( struct V_10 * V_11 ,
struct V_15 * V_23 )
{
struct V_10 * V_36 = & V_2 . V_19 ;
if ( ! F_33 ( V_36 -> V_37 , V_23 ) )
return - V_38 ;
return 0 ;
}
static void F_34 ( struct V_10 * V_11 ,
struct V_15 * V_23 )
{
struct V_39 V_40 ;
const struct V_41 * V_42 ;
F_35 ( & V_2 . V_43 ) ;
V_40 = F_36 ( V_23 ) ;
V_2 . V_22 . V_40 = V_40 ;
V_42 = F_37 ( V_40 . V_44 , V_40 . V_45 ) ;
if ( V_42 != NULL ) {
V_2 . V_22 = * V_42 ;
F_38 ( V_42 -> V_23 . V_26 ) ;
} else {
V_2 . V_22 . V_23 = * V_23 ;
V_2 . V_22 . V_40 . V_45 = 0 ;
V_2 . V_22 . V_40 . V_44 = V_46 ;
F_38 ( V_23 -> V_26 ) ;
}
F_2 ( L_8 , V_2 . V_22 . V_40 . V_44 == V_46 ?
L_9 : L_10 , V_2 . V_22 . V_40 . V_45 ) ;
F_39 ( & V_2 . V_43 ) ;
}
static void F_40 ( struct V_10 * V_11 ,
struct V_15 * V_23 )
{
const struct V_41 * V_22 ;
struct V_39 V_40 = V_2 . V_22 . V_40 ;
V_22 = F_37 ( V_40 . V_44 , V_40 . V_45 ) ;
if ( V_22 == NULL )
V_22 = F_41 () ;
memcpy ( V_23 , & V_22 -> V_23 , sizeof( V_22 -> V_23 ) ) ;
}
static void F_42 ( struct V_47 * V_48 )
{
F_35 ( & V_2 . V_43 ) ;
if ( F_1 () ) {
F_39 ( & V_2 . V_43 ) ;
return;
}
F_43 ( & V_2 . V_29 , V_48 ) ;
F_44 ( & V_2 . V_27 , V_48 ) ;
F_45 ( & V_2 . V_21 , V_48 ) ;
F_46 ( & V_2 . V_32 , V_48 ) ;
F_5 () ;
F_39 ( & V_2 . V_43 ) ;
}
static int F_47 ( T_1 * V_49 , int V_50 )
{
int V_1 ;
F_35 ( & V_2 . V_43 ) ;
V_1 = F_1 () ;
F_48 ( V_1 ) ;
V_1 = F_49 ( & V_2 . V_32 , V_49 , V_50 ) ;
F_5 () ;
F_39 ( & V_2 . V_43 ) ;
return V_1 ;
}
static int F_50 ( struct V_10 * V_11 )
{
struct V_10 * V_36 = & V_2 . V_19 ;
int V_1 = 0 ;
F_2 ( L_11 ) ;
F_35 ( & V_2 . V_43 ) ;
if ( V_36 == NULL || V_36 -> V_20 == NULL ) {
F_11 ( L_12 ) ;
V_1 = - V_51 ;
goto V_52;
}
V_1 = F_17 ( V_11 ) ;
if ( V_1 ) {
F_11 ( L_13 ) ;
goto V_52;
}
F_39 ( & V_2 . V_43 ) ;
return 0 ;
V_52:
F_39 ( & V_2 . V_43 ) ;
return V_1 ;
}
static void F_51 ( struct V_10 * V_11 )
{
F_2 ( L_14 ) ;
F_35 ( & V_2 . V_43 ) ;
F_30 ( V_11 ) ;
F_39 ( & V_2 . V_43 ) ;
}
static int F_52 ( struct V_10 * V_11 )
{
int V_1 = 0 ;
F_2 ( L_15 ) ;
F_35 ( & V_2 . V_43 ) ;
V_1 = F_12 ( V_11 ) ;
if ( V_1 ) {
F_11 ( L_13 ) ;
goto V_52;
}
F_39 ( & V_2 . V_43 ) ;
return 0 ;
V_52:
F_39 ( & V_2 . V_43 ) ;
return V_1 ;
}
static void F_53 ( struct V_10 * V_11 )
{
F_2 ( L_16 ) ;
F_35 ( & V_2 . V_43 ) ;
F_16 ( V_11 ) ;
F_39 ( & V_2 . V_43 ) ;
}
static int F_54 ( struct V_53 * V_3 )
{
struct V_54 * V_54 ;
V_54 = F_55 ( & V_3 -> V_4 , L_17 ) ;
if ( F_9 ( V_54 ) ) {
F_11 ( L_18 ) ;
return F_10 ( V_54 ) ;
}
V_2 . V_28 = V_54 ;
return 0 ;
}
static int F_56 ( struct V_10 * V_11 ,
struct V_10 * V_55 )
{
struct V_17 * V_18 ;
int V_1 ;
V_1 = F_7 () ;
if ( V_1 )
return V_1 ;
V_18 = F_57 ( V_11 -> V_37 ) ;
if ( ! V_18 )
return - V_51 ;
V_1 = F_58 ( V_18 , V_11 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_59 ( V_11 , V_55 ) ;
if ( V_1 ) {
F_11 ( L_19 ,
V_55 -> V_56 ) ;
F_60 ( V_18 , V_11 ) ;
return V_1 ;
}
return 0 ;
}
static void F_61 ( struct V_10 * V_11 ,
struct V_10 * V_55 )
{
F_4 ( V_55 != V_11 -> V_55 ) ;
if ( V_55 != V_11 -> V_55 )
return;
F_62 ( V_11 ) ;
if ( V_11 -> V_20 )
F_60 ( V_11 -> V_20 , V_11 ) ;
}
static int F_63 ( struct V_10 * V_11 ,
T_1 * V_57 , int V_50 )
{
bool V_58 ;
int V_1 ;
V_58 = V_2 . V_14 == false ;
if ( V_58 ) {
V_1 = F_52 ( V_11 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_47 ( V_57 , V_50 ) ;
if ( V_58 )
F_53 ( V_11 ) ;
return V_1 ;
}
static int F_64 ( struct V_10 * V_11 )
{
int V_1 ;
F_35 ( & V_2 . V_43 ) ;
if ( ! F_65 ( V_2 . V_22 . V_40 . V_44 ) ) {
V_1 = - V_59 ;
goto V_60;
}
V_1 = F_66 ( & V_2 . V_29 , true ) ;
if ( V_1 )
goto V_60;
F_39 ( & V_2 . V_43 ) ;
return 0 ;
V_60:
F_39 ( & V_2 . V_43 ) ;
return V_1 ;
}
static void F_67 ( struct V_10 * V_11 )
{
F_66 ( & V_2 . V_29 , false ) ;
}
static int F_68 ( struct V_10 * V_11 )
{
return F_69 ( & V_2 . V_32 , & V_2 . V_29 ) ;
}
static void F_70 ( struct V_10 * V_11 )
{
F_71 ( & V_2 . V_32 , & V_2 . V_29 ) ;
}
static bool F_72 ( struct V_10 * V_11 )
{
bool V_1 ;
F_35 ( & V_2 . V_43 ) ;
V_1 = F_65 ( V_2 . V_22 . V_40 . V_44 ) ;
F_39 ( & V_2 . V_43 ) ;
return V_1 ;
}
static int F_73 ( struct V_10 * V_11 ,
struct V_61 * V_62 )
{
int V_1 ;
T_2 V_63 = V_2 . V_22 . V_23 . V_26 ;
F_35 ( & V_2 . V_43 ) ;
if ( ! F_65 ( V_2 . V_22 . V_40 . V_44 ) ) {
V_1 = - V_59 ;
goto V_60;
}
V_1 = F_74 ( & V_2 . V_32 , & V_2 . V_29 , V_62 , V_63 ) ;
if ( V_1 )
goto V_60;
F_39 ( & V_2 . V_43 ) ;
return 0 ;
V_60:
F_39 ( & V_2 . V_43 ) ;
return V_1 ;
}
static int F_64 ( struct V_10 * V_11 )
{
return - V_59 ;
}
static void F_67 ( struct V_10 * V_11 )
{
}
static int F_68 ( struct V_10 * V_11 )
{
return - V_59 ;
}
static void F_70 ( struct V_10 * V_11 )
{
}
static bool F_72 ( struct V_10 * V_11 )
{
return false ;
}
static int F_73 ( struct V_10 * V_11 ,
struct V_61 * V_62 )
{
return - V_59 ;
}
static void F_75 ( struct V_53 * V_3 )
{
struct V_10 * V_36 = & V_2 . V_19 ;
V_36 -> V_4 = & V_3 -> V_4 ;
V_36 -> V_64 = V_65 ;
V_36 -> V_66 = V_67 ;
V_36 -> V_56 = L_20 ;
V_36 -> V_37 = V_68 ;
V_36 -> V_69 . V_2 = & V_70 ;
V_36 -> V_71 = V_72 ;
F_76 ( V_36 ) ;
}
static void T_3 F_77 ( struct V_53 * V_3 )
{
struct V_10 * V_36 = & V_2 . V_19 ;
F_78 ( V_36 ) ;
}
static int F_79 ( struct V_53 * V_3 )
{
int V_1 ;
V_2 . V_3 = V_3 ;
F_80 ( & V_2 . V_43 ) ;
V_1 = F_81 ( V_3 , & V_2 . V_29 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_82 ( V_3 , & V_2 . V_27 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_83 ( V_3 , & V_2 . V_21 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_84 ( V_3 , & V_2 . V_32 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_54 ( V_3 ) ;
if ( V_1 ) {
F_11 ( L_21 ) ;
return V_1 ;
}
F_85 ( & V_3 -> V_4 ) ;
F_75 ( V_3 ) ;
F_86 ( L_22 , F_42 ) ;
return 0 ;
}
static int T_3 F_87 ( struct V_53 * V_3 )
{
F_77 ( V_3 ) ;
F_88 ( & V_3 -> V_4 ) ;
return 0 ;
}
static int F_89 ( struct V_73 * V_4 )
{
F_90 ( V_2 . V_28 ) ;
F_91 () ;
return 0 ;
}
static int F_92 ( struct V_73 * V_4 )
{
int V_1 ;
V_1 = F_93 () ;
if ( V_1 < 0 )
return V_1 ;
F_94 ( V_2 . V_28 ) ;
return 0 ;
}
int T_4 F_95 ( void )
{
return F_96 ( & V_74 ) ;
}
void T_3 F_97 ( void )
{
F_98 ( & V_74 ) ;
}
