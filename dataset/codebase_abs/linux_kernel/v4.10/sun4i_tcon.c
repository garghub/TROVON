void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_5 , 0 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_2 ( L_2 ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_5 ,
V_5 ) ;
}
void F_5 ( struct V_1 * V_2 , int V_6 )
{
if ( V_6 == 0 ) {
F_3 ( V_2 -> V_3 , V_7 ,
V_8 , 0 ) ;
F_6 ( V_2 -> V_9 ) ;
return;
}
F_7 ( ! V_2 -> V_10 -> V_11 ) ;
F_3 ( V_2 -> V_3 , V_12 ,
V_13 , 0 ) ;
F_6 ( V_2 -> V_14 ) ;
}
void F_8 ( struct V_1 * V_2 , int V_6 )
{
if ( V_6 == 0 ) {
F_3 ( V_2 -> V_3 , V_7 ,
V_8 ,
V_8 ) ;
F_9 ( V_2 -> V_9 ) ;
return;
}
F_7 ( ! V_2 -> V_10 -> V_11 ) ;
F_3 ( V_2 -> V_3 , V_12 ,
V_13 ,
V_13 ) ;
F_9 ( V_2 -> V_14 ) ;
}
void F_10 ( struct V_1 * V_2 , bool V_15 )
{
T_1 V_16 , V_17 = 0 ;
F_2 ( L_3 , V_15 ? L_4 : L_5 ) ;
V_16 = F_11 ( 0 ) |
F_11 ( 1 ) ;
if ( V_15 )
V_17 = V_16 ;
F_3 ( V_2 -> V_3 , V_18 , V_16 , V_17 ) ;
}
static int F_12 ( struct V_19 * V_20 ,
int V_6 )
{
int V_21 = V_20 -> V_22 - V_20 -> V_23 ;
if ( V_20 -> V_24 & V_25 )
V_21 /= 2 ;
if ( V_6 == 1 )
V_21 -= 2 ;
V_21 = F_13 ( V_21 , 30 ) ;
F_2 ( L_6 , V_6 , V_21 ) ;
return V_21 ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
unsigned int V_26 , V_27 , V_28 ;
T_2 V_29 ;
T_1 V_17 = 0 ;
V_29 = F_12 ( V_20 , 0 ) ;
F_3 ( V_2 -> V_3 , V_7 ,
V_30 ,
F_15 ( V_29 ) ) ;
F_16 ( V_2 -> V_3 , V_31 ,
F_17 ( V_20 -> V_32 ) |
F_18 ( V_20 -> V_33 ) ) ;
V_26 = V_20 -> V_34 - V_20 -> V_35 ;
F_2 ( L_7 ,
V_20 -> V_34 , V_26 ) ;
F_16 ( V_2 -> V_3 , V_36 ,
F_19 ( V_20 -> V_34 ) |
F_20 ( V_26 ) ) ;
V_26 = V_20 -> V_37 - V_20 -> V_38 ;
F_2 ( L_8 ,
V_20 -> V_37 , V_26 ) ;
F_16 ( V_2 -> V_3 , V_39 ,
F_21 ( V_20 -> V_37 ) |
F_22 ( V_26 ) ) ;
V_27 = V_20 -> V_40 - V_20 -> V_35 ;
V_28 = V_20 -> V_41 - V_20 -> V_38 ;
F_2 ( L_9 , V_27 , V_28 ) ;
F_16 ( V_2 -> V_3 , V_42 ,
F_23 ( V_28 ) |
F_24 ( V_27 ) ) ;
if ( ! ( V_20 -> V_24 & V_43 ) )
V_17 |= V_44 ;
if ( ! ( V_20 -> V_24 & V_45 ) )
V_17 |= V_46 ;
F_3 ( V_2 -> V_3 , V_47 ,
V_44 | V_46 ,
V_17 ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_48 ,
V_49 ) ;
F_16 ( V_2 -> V_3 , V_50 , 0 ) ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
unsigned int V_26 , V_27 , V_28 ;
T_2 V_29 ;
T_1 V_17 ;
F_7 ( ! V_2 -> V_10 -> V_11 ) ;
V_29 = F_12 ( V_20 , 1 ) ;
F_3 ( V_2 -> V_3 , V_12 ,
V_51 ,
F_26 ( V_29 ) ) ;
if ( V_20 -> V_24 & V_25 )
V_17 = V_52 ;
else
V_17 = 0 ;
F_3 ( V_2 -> V_3 , V_12 ,
V_52 ,
V_17 ) ;
F_16 ( V_2 -> V_3 , V_53 ,
F_27 ( V_20 -> V_32 ) |
F_28 ( V_20 -> V_33 ) ) ;
F_16 ( V_2 -> V_3 , V_54 ,
F_29 ( V_20 -> V_32 ) |
F_30 ( V_20 -> V_33 ) ) ;
F_16 ( V_2 -> V_3 , V_55 ,
F_31 ( V_20 -> V_32 ) |
F_32 ( V_20 -> V_33 ) ) ;
V_26 = V_20 -> V_34 - V_20 -> V_40 ;
F_2 ( L_7 ,
V_20 -> V_56 , V_26 ) ;
F_16 ( V_2 -> V_3 , V_57 ,
F_33 ( V_20 -> V_34 ) |
F_34 ( V_26 ) ) ;
V_26 = V_20 -> V_37 - V_20 -> V_41 ;
F_2 ( L_8 ,
V_20 -> V_22 , V_26 ) ;
F_16 ( V_2 -> V_3 , V_58 ,
F_35 ( V_20 -> V_22 ) |
F_36 ( V_26 ) ) ;
V_27 = V_20 -> V_40 - V_20 -> V_35 ;
V_28 = V_20 -> V_41 - V_20 -> V_38 ;
F_2 ( L_9 , V_27 , V_28 ) ;
F_16 ( V_2 -> V_3 , V_59 ,
F_37 ( V_28 ) |
F_38 ( V_27 ) ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_48 ,
V_60 ) ;
if ( V_2 -> V_10 -> V_61 )
F_16 ( V_2 -> V_3 , V_62 , 1 ) ;
}
static void F_39 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
unsigned long V_24 ;
F_40 ( & V_64 -> V_67 , V_24 ) ;
if ( V_66 -> V_68 ) {
F_41 ( & V_66 -> V_69 , V_66 -> V_68 ) ;
F_42 ( & V_66 -> V_69 ) ;
V_66 -> V_68 = NULL ;
}
F_43 ( & V_64 -> V_67 , V_24 ) ;
}
static T_3 F_44 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
struct V_63 * V_72 = V_2 -> V_72 ;
struct V_73 * V_74 = V_72 -> V_75 ;
struct V_65 * V_66 = V_74 -> V_69 ;
unsigned int V_76 ;
F_45 ( V_2 -> V_3 , V_18 , & V_76 ) ;
if ( ! ( V_76 & ( F_46 ( 0 ) |
F_46 ( 1 ) ) ) )
return V_77 ;
F_47 ( & V_66 -> V_69 ) ;
F_39 ( V_72 , V_66 ) ;
F_3 ( V_2 -> V_3 , V_18 ,
F_46 ( 0 ) |
F_46 ( 1 ) ,
0 ) ;
return V_78 ;
}
static int F_48 ( struct V_79 * V_64 ,
struct V_1 * V_2 )
{
V_2 -> V_80 = F_49 ( V_64 , L_10 ) ;
if ( F_50 ( V_2 -> V_80 ) ) {
F_51 ( V_64 , L_11 ) ;
return F_52 ( V_2 -> V_80 ) ;
}
F_9 ( V_2 -> V_80 ) ;
V_2 -> V_81 = F_49 ( V_64 , L_12 ) ;
if ( F_50 ( V_2 -> V_81 ) ) {
F_51 ( V_64 , L_13 ) ;
return F_52 ( V_2 -> V_81 ) ;
}
if ( V_2 -> V_10 -> V_11 ) {
V_2 -> V_14 = F_49 ( V_64 , L_14 ) ;
if ( F_50 ( V_2 -> V_14 ) ) {
F_51 ( V_64 , L_15 ) ;
return F_52 ( V_2 -> V_14 ) ;
}
}
return F_53 ( V_64 , V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 ) ;
F_6 ( V_2 -> V_80 ) ;
}
static int F_56 ( struct V_79 * V_64 ,
struct V_1 * V_2 )
{
struct V_82 * V_83 = F_57 ( V_64 ) ;
int V_70 , V_84 ;
V_70 = F_58 ( V_83 , 0 ) ;
if ( V_70 < 0 ) {
F_51 ( V_64 , L_16 ) ;
return V_70 ;
}
V_84 = F_59 ( V_64 , V_70 , F_44 , 0 ,
F_60 ( V_64 ) , V_2 ) ;
if ( V_84 ) {
F_51 ( V_64 , L_17 ) ;
return V_84 ;
}
return 0 ;
}
static int F_61 ( struct V_79 * V_64 ,
struct V_1 * V_2 )
{
struct V_82 * V_83 = F_57 ( V_64 ) ;
struct V_85 * V_86 ;
void T_4 * V_3 ;
V_86 = F_62 ( V_83 , V_87 , 0 ) ;
V_3 = F_63 ( V_64 , V_86 ) ;
if ( F_50 ( V_3 ) )
return F_52 ( V_3 ) ;
V_2 -> V_3 = F_64 ( V_64 , V_3 ,
& V_88 ) ;
if ( F_50 ( V_2 -> V_3 ) ) {
F_51 ( V_64 , L_18 ) ;
return F_52 ( V_2 -> V_3 ) ;
}
F_16 ( V_2 -> V_3 , V_4 , 0 ) ;
F_16 ( V_2 -> V_3 , V_18 , 0 ) ;
F_16 ( V_2 -> V_3 , V_89 , 0 ) ;
F_16 ( V_2 -> V_3 , V_50 , ~ 0 ) ;
F_16 ( V_2 -> V_3 , V_90 , ~ 0 ) ;
return 0 ;
}
struct V_91 * F_65 ( struct V_92 * V_93 )
{
struct V_92 * V_94 , * V_95 , * V_96 ;
struct V_92 * V_97 = NULL ;
V_94 = F_66 ( V_93 , 1 ) ;
F_67 (port, child) {
T_1 V_98 ;
F_68 ( V_96 , L_19 , & V_98 ) ;
if ( V_98 == 0 )
V_97 = V_96 ;
}
if ( ! V_97 ) {
F_2 ( L_20 ) ;
return F_69 ( - V_99 ) ;
}
V_95 = F_70 ( V_97 ) ;
if ( ! V_95 ) {
F_2 ( L_21 ) ;
return F_69 ( - V_100 ) ;
}
return F_71 ( V_95 ) ? : F_69 ( - V_101 ) ;
}
struct V_102 * F_72 ( struct V_92 * V_93 )
{
struct V_92 * V_94 , * V_95 , * V_96 ;
struct V_92 * V_97 = NULL ;
V_94 = F_66 ( V_93 , 1 ) ;
F_67 (port, child) {
T_1 V_98 ;
F_68 ( V_96 , L_19 , & V_98 ) ;
if ( V_98 == 0 )
V_97 = V_96 ;
}
if ( ! V_97 ) {
F_2 ( L_22 ) ;
return F_69 ( - V_99 ) ;
}
V_95 = F_70 ( V_97 ) ;
if ( ! V_95 ) {
F_2 ( L_23 ) ;
return F_69 ( - V_100 ) ;
}
return F_73 ( V_95 ) ? : F_69 ( - V_101 ) ;
}
static int F_74 ( struct V_79 * V_64 , struct V_79 * V_103 ,
void * V_104 )
{
struct V_63 * V_72 = V_104 ;
struct V_73 * V_74 = V_72 -> V_75 ;
struct V_1 * V_2 ;
int V_84 ;
V_2 = F_75 ( V_64 , sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 )
return - V_106 ;
F_76 ( V_64 , V_2 ) ;
V_74 -> V_2 = V_2 ;
V_2 -> V_72 = V_72 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_10 = F_77 ( V_64 ) ;
V_2 -> V_107 = F_78 ( V_64 , L_24 ) ;
if ( F_50 ( V_2 -> V_107 ) ) {
F_51 ( V_64 , L_25 ) ;
return F_52 ( V_2 -> V_107 ) ;
}
if ( ! F_79 ( V_2 -> V_107 ) )
F_80 ( V_2 -> V_107 ) ;
V_84 = F_81 ( V_2 -> V_107 ) ;
if ( V_84 ) {
F_51 ( V_64 , L_26 ) ;
return V_84 ;
}
V_84 = F_61 ( V_64 , V_2 ) ;
if ( V_84 ) {
F_51 ( V_64 , L_27 ) ;
goto V_108;
}
V_84 = F_48 ( V_64 , V_2 ) ;
if ( V_84 ) {
F_51 ( V_64 , L_28 ) ;
goto V_108;
}
V_84 = F_56 ( V_64 , V_2 ) ;
if ( V_84 ) {
F_51 ( V_64 , L_29 ) ;
goto V_109;
}
V_84 = F_82 ( V_72 ) ;
if ( V_84 < 0 )
goto V_109;
return 0 ;
V_109:
F_54 ( V_2 ) ;
V_108:
F_80 ( V_2 -> V_107 ) ;
return V_84 ;
}
static void F_83 ( struct V_79 * V_64 , struct V_79 * V_103 ,
void * V_104 )
{
struct V_1 * V_2 = F_84 ( V_64 ) ;
F_54 ( V_2 ) ;
}
static int F_85 ( struct V_82 * V_83 )
{
struct V_92 * V_93 = V_83 -> V_64 . V_110 ;
struct V_102 * V_111 ;
struct V_91 * V_112 ;
V_112 = F_65 ( V_93 ) ;
V_111 = F_72 ( V_93 ) ;
if ( ( F_52 ( V_112 ) == - V_101 ) &&
( F_52 ( V_111 ) == - V_101 ) ) {
F_2 ( L_30 ) ;
return - V_101 ;
}
return F_86 ( & V_83 -> V_64 , & V_113 ) ;
}
static int F_87 ( struct V_82 * V_83 )
{
F_88 ( & V_83 -> V_64 , & V_113 ) ;
return 0 ;
}
