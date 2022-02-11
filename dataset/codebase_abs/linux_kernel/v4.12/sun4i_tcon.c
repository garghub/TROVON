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
struct V_65 * V_66 = V_2 -> V_69 ;
unsigned int V_73 ;
F_45 ( V_2 -> V_3 , V_18 , & V_73 ) ;
if ( ! ( V_73 & ( F_46 ( 0 ) |
F_46 ( 1 ) ) ) )
return V_74 ;
F_47 ( & V_66 -> V_69 ) ;
F_39 ( V_72 , V_66 ) ;
F_3 ( V_2 -> V_3 , V_18 ,
F_46 ( 0 ) |
F_46 ( 1 ) ,
0 ) ;
return V_75 ;
}
static int F_48 ( struct V_76 * V_64 ,
struct V_1 * V_2 )
{
V_2 -> V_77 = F_49 ( V_64 , L_10 ) ;
if ( F_50 ( V_2 -> V_77 ) ) {
F_51 ( V_64 , L_11 ) ;
return F_52 ( V_2 -> V_77 ) ;
}
F_9 ( V_2 -> V_77 ) ;
V_2 -> V_78 = F_49 ( V_64 , L_12 ) ;
if ( F_50 ( V_2 -> V_78 ) ) {
F_51 ( V_64 , L_13 ) ;
return F_52 ( V_2 -> V_78 ) ;
}
if ( V_2 -> V_10 -> V_11 ) {
V_2 -> V_14 = F_49 ( V_64 , L_14 ) ;
if ( F_50 ( V_2 -> V_14 ) ) {
F_51 ( V_64 , L_15 ) ;
return F_52 ( V_2 -> V_14 ) ;
}
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_77 ) ;
}
static int F_54 ( struct V_76 * V_64 ,
struct V_1 * V_2 )
{
struct V_79 * V_80 = F_55 ( V_64 ) ;
int V_70 , V_81 ;
V_70 = F_56 ( V_80 , 0 ) ;
if ( V_70 < 0 ) {
F_51 ( V_64 , L_16 ) ;
return V_70 ;
}
V_81 = F_57 ( V_64 , V_70 , F_44 , 0 ,
F_58 ( V_64 ) , V_2 ) ;
if ( V_81 ) {
F_51 ( V_64 , L_17 ) ;
return V_81 ;
}
return 0 ;
}
static int F_59 ( struct V_76 * V_64 ,
struct V_1 * V_2 )
{
struct V_79 * V_80 = F_55 ( V_64 ) ;
struct V_82 * V_83 ;
void T_4 * V_3 ;
V_83 = F_60 ( V_80 , V_84 , 0 ) ;
V_3 = F_61 ( V_64 , V_83 ) ;
if ( F_50 ( V_3 ) )
return F_52 ( V_3 ) ;
V_2 -> V_3 = F_62 ( V_64 , V_3 ,
& V_85 ) ;
if ( F_50 ( V_2 -> V_3 ) ) {
F_51 ( V_64 , L_18 ) ;
return F_52 ( V_2 -> V_3 ) ;
}
F_16 ( V_2 -> V_3 , V_4 , 0 ) ;
F_16 ( V_2 -> V_3 , V_18 , 0 ) ;
F_16 ( V_2 -> V_3 , V_86 , 0 ) ;
F_16 ( V_2 -> V_3 , V_50 , ~ 0 ) ;
F_16 ( V_2 -> V_3 , V_87 , ~ 0 ) ;
return 0 ;
}
static int F_63 ( struct V_76 * V_64 , struct V_76 * V_88 ,
void * V_89 )
{
struct V_63 * V_72 = V_89 ;
struct V_90 * V_91 = V_72 -> V_92 ;
struct V_1 * V_2 ;
int V_81 ;
V_2 = F_64 ( V_64 , sizeof( * V_2 ) , V_93 ) ;
if ( ! V_2 )
return - V_94 ;
F_65 ( V_64 , V_2 ) ;
V_91 -> V_2 = V_2 ;
V_2 -> V_72 = V_72 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_10 = F_66 ( V_64 ) ;
V_2 -> V_95 = F_67 ( V_64 , L_19 ) ;
if ( F_50 ( V_2 -> V_95 ) ) {
F_51 ( V_64 , L_20 ) ;
return F_52 ( V_2 -> V_95 ) ;
}
if ( ! F_68 ( V_2 -> V_95 ) )
F_69 ( V_2 -> V_95 ) ;
V_81 = F_70 ( V_2 -> V_95 ) ;
if ( V_81 ) {
F_51 ( V_64 , L_21 ) ;
return V_81 ;
}
V_81 = F_48 ( V_64 , V_2 ) ;
if ( V_81 ) {
F_51 ( V_64 , L_22 ) ;
goto V_96;
}
V_81 = F_59 ( V_64 , V_2 ) ;
if ( V_81 ) {
F_51 ( V_64 , L_23 ) ;
goto V_97;
}
V_81 = F_71 ( V_64 , V_2 ) ;
if ( V_81 ) {
F_51 ( V_64 , L_24 ) ;
goto V_97;
}
V_81 = F_54 ( V_64 , V_2 ) ;
if ( V_81 ) {
F_51 ( V_64 , L_25 ) ;
goto V_98;
}
V_2 -> V_69 = F_72 ( V_72 , V_91 -> V_99 , V_2 ) ;
if ( F_50 ( V_2 -> V_69 ) ) {
F_51 ( V_64 , L_26 ) ;
V_81 = F_52 ( V_2 -> V_69 ) ;
goto V_97;
}
V_81 = F_73 ( V_72 , V_2 ) ;
if ( V_81 < 0 )
goto V_97;
return 0 ;
V_98:
F_74 ( V_2 ) ;
V_97:
F_53 ( V_2 ) ;
V_96:
F_69 ( V_2 -> V_95 ) ;
return V_81 ;
}
static void F_75 ( struct V_76 * V_64 , struct V_76 * V_88 ,
void * V_89 )
{
struct V_1 * V_2 = F_76 ( V_64 ) ;
F_74 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static int F_77 ( struct V_79 * V_80 )
{
struct V_100 * V_101 = V_80 -> V_64 . V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_81 ;
V_81 = F_78 ( V_101 , 1 , 0 , & V_106 , & V_104 ) ;
if ( V_81 == - V_107 )
return V_81 ;
return F_79 ( & V_80 -> V_64 , & V_108 ) ;
}
static int F_80 ( struct V_79 * V_80 )
{
F_81 ( & V_80 -> V_64 , & V_108 ) ;
return 0 ;
}
