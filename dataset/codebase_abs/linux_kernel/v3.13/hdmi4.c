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
if ( F_9 ( V_7 ) )
V_7 = F_8 ( & V_2 . V_3 -> V_4 , L_4 ) ;
if ( F_9 ( V_7 ) ) {
F_10 ( L_5 ) ;
return F_11 ( V_7 ) ;
}
V_2 . V_8 = V_7 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 )
{
int V_1 ;
V_1 = F_13 ( V_2 . V_8 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 () ;
if ( V_1 )
goto V_11;
F_14 ( V_12 ) ;
V_2 . V_13 = true ;
return 0 ;
V_11:
F_15 ( V_2 . V_8 ) ;
return V_1 ;
}
static void F_16 ( struct V_9 * V_10 )
{
V_2 . V_13 = false ;
F_5 () ;
F_15 ( V_2 . V_8 ) ;
}
static int F_17 ( struct V_9 * V_10 )
{
int V_1 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = V_2 . V_18 . V_19 ;
unsigned long V_20 ;
V_1 = F_12 ( V_10 ) ;
if ( V_1 )
return V_1 ;
F_18 ( V_17 ) ;
V_15 = & V_2 . V_21 . V_22 ;
F_2 ( L_6 , V_15 -> V_23 , V_15 -> V_24 ) ;
V_20 = V_15 -> V_25 ;
F_19 ( & V_2 . V_26 , F_20 ( V_2 . V_27 ) , V_20 ) ;
F_21 ( & V_2 . V_28 ) ;
V_1 = F_22 ( & V_2 . V_26 , & V_2 . V_28 ) ;
if ( V_1 ) {
F_2 ( L_7 ) ;
goto V_29;
}
V_1 = F_23 ( & V_2 . V_20 , & V_2 . V_28 , & V_2 . V_21 ) ;
if ( V_1 ) {
F_2 ( L_8 ) ;
goto V_30;
}
F_24 ( & V_2 . V_31 , & V_2 . V_28 , & V_2 . V_21 ) ;
F_25 ( 0 ) ;
F_26 ( V_17 , V_15 ) ;
V_1 = F_27 ( & V_2 . V_28 ) ;
if ( V_1 )
goto V_32;
V_1 = F_28 ( V_17 ) ;
if ( V_1 )
goto V_33;
return 0 ;
V_33:
F_21 ( & V_2 . V_28 ) ;
V_32:
F_29 ( & V_2 . V_20 , & V_2 . V_28 ) ;
V_30:
F_30 ( & V_2 . V_26 , & V_2 . V_28 ) ;
V_29:
F_16 ( V_10 ) ;
return - V_34 ;
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = V_2 . V_18 . V_19 ;
F_18 ( V_17 ) ;
F_21 ( & V_2 . V_28 ) ;
F_29 ( & V_2 . V_20 , & V_2 . V_28 ) ;
F_30 ( & V_2 . V_26 , & V_2 . V_28 ) ;
F_16 ( V_10 ) ;
}
static int F_32 ( struct V_9 * V_10 ,
struct V_14 * V_22 )
{
struct V_35 V_36 ;
V_36 = F_33 ( V_22 ) ;
if ( V_36 . V_37 == - 1 )
return - V_38 ;
return 0 ;
}
static void F_34 ( struct V_9 * V_10 ,
struct V_14 * V_22 )
{
struct V_35 V_36 ;
const struct V_39 * V_40 ;
F_35 ( & V_2 . V_41 ) ;
V_36 = F_33 ( V_22 ) ;
V_2 . V_21 . V_36 = V_36 ;
V_40 = F_36 ( V_36 . V_42 , V_36 . V_37 ) ;
if ( V_40 != NULL ) {
V_2 . V_21 = * V_40 ;
F_37 ( V_40 -> V_22 . V_25 * 1000 ) ;
}
F_38 ( & V_2 . V_41 ) ;
}
static void F_39 ( struct V_9 * V_10 ,
struct V_14 * V_22 )
{
const struct V_39 * V_21 ;
struct V_35 V_36 = V_2 . V_21 . V_36 ;
V_21 = F_36 ( V_36 . V_42 , V_36 . V_37 ) ;
if ( V_21 == NULL )
V_21 = F_40 () ;
memcpy ( V_22 , & V_21 -> V_22 , sizeof( V_21 -> V_22 ) ) ;
}
static void F_41 ( struct V_43 * V_44 )
{
F_35 ( & V_2 . V_41 ) ;
if ( F_1 () ) {
F_38 ( & V_2 . V_41 ) ;
return;
}
F_42 ( & V_2 . V_28 , V_44 ) ;
F_43 ( & V_2 . V_26 , V_44 ) ;
F_44 ( & V_2 . V_20 , V_44 ) ;
F_45 ( & V_2 . V_31 , V_44 ) ;
F_5 () ;
F_38 ( & V_2 . V_41 ) ;
}
static int F_46 ( T_1 * V_45 , int V_46 )
{
int V_1 ;
F_35 ( & V_2 . V_41 ) ;
V_1 = F_1 () ;
F_47 ( V_1 ) ;
V_1 = F_48 ( & V_2 . V_31 , V_45 , V_46 ) ;
F_5 () ;
F_38 ( & V_2 . V_41 ) ;
return V_1 ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_9 * V_47 = & V_2 . V_18 ;
int V_1 = 0 ;
F_2 ( L_9 ) ;
F_35 ( & V_2 . V_41 ) ;
if ( V_47 == NULL || V_47 -> V_19 == NULL ) {
F_10 ( L_10 ) ;
V_1 = - V_48 ;
goto V_49;
}
V_1 = F_17 ( V_10 ) ;
if ( V_1 ) {
F_10 ( L_11 ) ;
goto V_49;
}
F_38 ( & V_2 . V_41 ) ;
return 0 ;
V_49:
F_38 ( & V_2 . V_41 ) ;
return V_1 ;
}
static void F_50 ( struct V_9 * V_10 )
{
F_2 ( L_12 ) ;
F_35 ( & V_2 . V_41 ) ;
F_31 ( V_10 ) ;
F_38 ( & V_2 . V_41 ) ;
}
static int F_51 ( struct V_9 * V_10 )
{
int V_1 = 0 ;
F_2 ( L_13 ) ;
F_35 ( & V_2 . V_41 ) ;
V_1 = F_12 ( V_10 ) ;
if ( V_1 ) {
F_10 ( L_11 ) ;
goto V_49;
}
F_38 ( & V_2 . V_41 ) ;
return 0 ;
V_49:
F_38 ( & V_2 . V_41 ) ;
return V_1 ;
}
static void F_52 ( struct V_9 * V_10 )
{
F_2 ( L_14 ) ;
F_35 ( & V_2 . V_41 ) ;
F_16 ( V_10 ) ;
F_38 ( & V_2 . V_41 ) ;
}
static int F_53 ( struct V_50 * V_3 )
{
struct V_51 * V_51 ;
V_51 = F_54 ( & V_3 -> V_4 , L_15 ) ;
if ( F_9 ( V_51 ) ) {
F_10 ( L_16 ) ;
return F_11 ( V_51 ) ;
}
V_2 . V_27 = V_51 ;
return 0 ;
}
static int F_55 ( struct V_9 * V_10 ,
struct V_9 * V_52 )
{
struct V_16 * V_17 ;
int V_1 ;
V_1 = F_7 () ;
if ( V_1 )
return V_1 ;
V_17 = F_56 ( V_10 -> V_53 ) ;
if ( ! V_17 )
return - V_48 ;
V_1 = F_57 ( V_17 , V_10 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_58 ( V_10 , V_52 ) ;
if ( V_1 ) {
F_10 ( L_17 ,
V_52 -> V_54 ) ;
F_59 ( V_17 , V_10 ) ;
return V_1 ;
}
return 0 ;
}
static void F_60 ( struct V_9 * V_10 ,
struct V_9 * V_52 )
{
F_4 ( V_52 != V_10 -> V_52 ) ;
if ( V_52 != V_10 -> V_52 )
return;
F_61 ( V_10 ) ;
if ( V_10 -> V_19 )
F_59 ( V_10 -> V_19 , V_10 ) ;
}
static int F_62 ( struct V_9 * V_10 ,
T_1 * V_55 , int V_46 )
{
bool V_56 ;
int V_1 ;
V_56 = V_2 . V_13 == false ;
if ( V_56 ) {
V_1 = F_51 ( V_10 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_46 ( V_55 , V_46 ) ;
if ( V_56 )
F_52 ( V_10 ) ;
return V_1 ;
}
static int F_63 ( struct V_9 * V_10 )
{
int V_1 ;
F_35 ( & V_2 . V_41 ) ;
if ( ! F_64 ( V_2 . V_21 . V_36 . V_42 ) ) {
V_1 = - V_57 ;
goto V_58;
}
V_1 = F_65 ( & V_2 . V_28 , true ) ;
if ( V_1 )
goto V_58;
F_38 ( & V_2 . V_41 ) ;
return 0 ;
V_58:
F_38 ( & V_2 . V_41 ) ;
return V_1 ;
}
static void F_66 ( struct V_9 * V_10 )
{
F_65 ( & V_2 . V_28 , false ) ;
}
static int F_67 ( struct V_9 * V_10 )
{
return F_68 ( & V_2 . V_31 , & V_2 . V_28 ) ;
}
static void F_69 ( struct V_9 * V_10 )
{
F_70 ( & V_2 . V_31 , & V_2 . V_28 ) ;
}
static bool F_71 ( struct V_9 * V_10 )
{
bool V_1 ;
F_35 ( & V_2 . V_41 ) ;
V_1 = F_64 ( V_2 . V_21 . V_36 . V_42 ) ;
F_38 ( & V_2 . V_41 ) ;
return V_1 ;
}
static int F_72 ( struct V_9 * V_10 ,
struct V_59 * V_60 )
{
int V_1 ;
T_2 V_61 = V_2 . V_21 . V_22 . V_25 ;
F_35 ( & V_2 . V_41 ) ;
if ( ! F_64 ( V_2 . V_21 . V_36 . V_42 ) ) {
V_1 = - V_57 ;
goto V_58;
}
V_1 = F_73 ( & V_2 . V_31 , & V_2 . V_28 , V_60 , V_61 ) ;
if ( V_1 )
goto V_58;
F_38 ( & V_2 . V_41 ) ;
return 0 ;
V_58:
F_38 ( & V_2 . V_41 ) ;
return V_1 ;
}
static int F_63 ( struct V_9 * V_10 )
{
return - V_57 ;
}
static void F_66 ( struct V_9 * V_10 )
{
}
static int F_67 ( struct V_9 * V_10 )
{
return - V_57 ;
}
static void F_69 ( struct V_9 * V_10 )
{
}
static bool F_71 ( struct V_9 * V_10 )
{
return false ;
}
static int F_72 ( struct V_9 * V_10 ,
struct V_59 * V_60 )
{
return - V_57 ;
}
static void F_74 ( struct V_50 * V_3 )
{
struct V_9 * V_47 = & V_2 . V_18 ;
V_47 -> V_4 = & V_3 -> V_4 ;
V_47 -> V_62 = V_63 ;
V_47 -> V_64 = V_65 ;
V_47 -> V_54 = L_18 ;
V_47 -> V_53 = V_66 ;
V_47 -> V_67 . V_2 = & V_68 ;
V_47 -> V_69 = V_70 ;
F_75 ( V_47 ) ;
}
static void T_3 F_76 ( struct V_50 * V_3 )
{
struct V_9 * V_47 = & V_2 . V_18 ;
F_77 ( V_47 ) ;
}
static int F_78 ( struct V_50 * V_3 )
{
int V_1 ;
V_2 . V_3 = V_3 ;
F_79 ( & V_2 . V_41 ) ;
V_1 = F_80 ( V_3 , & V_2 . V_28 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_81 ( V_3 , & V_2 . V_26 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_82 ( V_3 , & V_2 . V_20 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_83 ( V_3 , & V_2 . V_31 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_53 ( V_3 ) ;
if ( V_1 ) {
F_10 ( L_19 ) ;
return V_1 ;
}
F_84 ( & V_3 -> V_4 ) ;
F_74 ( V_3 ) ;
F_85 ( L_20 , F_41 ) ;
return 0 ;
}
static int T_3 F_86 ( struct V_50 * V_3 )
{
F_76 ( V_3 ) ;
F_87 ( & V_3 -> V_4 ) ;
return 0 ;
}
static int F_88 ( struct V_71 * V_4 )
{
F_89 ( V_2 . V_27 ) ;
F_90 () ;
return 0 ;
}
static int F_91 ( struct V_71 * V_4 )
{
int V_1 ;
V_1 = F_92 () ;
if ( V_1 < 0 )
return V_1 ;
F_93 ( V_2 . V_27 ) ;
return 0 ;
}
int T_4 F_94 ( void )
{
return F_95 ( & V_72 ) ;
}
void T_3 F_96 ( void )
{
F_97 ( & V_72 ) ;
}
