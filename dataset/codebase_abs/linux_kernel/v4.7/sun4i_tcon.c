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
} else if ( V_6 == 1 ) {
F_3 ( V_2 -> V_3 , V_10 ,
V_11 , 0 ) ;
F_6 ( V_2 -> V_12 ) ;
}
}
void F_7 ( struct V_1 * V_2 , int V_6 )
{
if ( V_6 == 0 ) {
F_3 ( V_2 -> V_3 , V_7 ,
V_8 ,
V_8 ) ;
F_8 ( V_2 -> V_9 ) ;
} else if ( V_6 == 1 ) {
F_3 ( V_2 -> V_3 , V_10 ,
V_11 ,
V_11 ) ;
F_8 ( V_2 -> V_12 ) ;
}
}
void F_9 ( struct V_1 * V_2 , bool V_13 )
{
T_1 V_14 , V_15 = 0 ;
F_2 ( L_3 , V_13 ? L_4 : L_5 ) ;
V_14 = F_10 ( 0 ) |
F_10 ( 1 ) ;
if ( V_13 )
V_15 = V_14 ;
F_3 ( V_2 -> V_3 , V_16 , V_14 , V_15 ) ;
}
static int F_11 ( struct V_17 * V_18 ,
int V_6 )
{
int V_19 = V_18 -> V_20 - V_18 -> V_21 ;
if ( V_18 -> V_22 & V_23 )
V_19 /= 2 ;
if ( V_6 == 1 )
V_19 -= 2 ;
V_19 = F_12 ( V_19 , 30 ) ;
F_2 ( L_6 , V_6 , V_19 ) ;
return V_19 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
unsigned int V_24 , V_25 , V_26 ;
T_2 V_27 ;
T_1 V_15 = 0 ;
V_27 = F_11 ( V_18 , 0 ) ;
F_3 ( V_2 -> V_3 , V_7 ,
V_28 ,
F_14 ( V_27 ) ) ;
F_15 ( V_2 -> V_3 , V_29 ,
F_16 ( V_18 -> V_30 ) |
F_17 ( V_18 -> V_31 ) ) ;
V_24 = V_18 -> V_32 - V_18 -> V_33 ;
F_2 ( L_7 ,
V_18 -> V_32 , V_24 ) ;
F_15 ( V_2 -> V_3 , V_34 ,
F_18 ( V_18 -> V_32 ) |
F_19 ( V_24 ) ) ;
V_24 = V_18 -> V_35 - V_18 -> V_36 ;
F_2 ( L_8 ,
V_18 -> V_35 , V_24 ) ;
F_15 ( V_2 -> V_3 , V_37 ,
F_20 ( V_18 -> V_35 ) |
F_21 ( V_24 ) ) ;
V_25 = V_18 -> V_38 - V_18 -> V_33 ;
V_26 = V_18 -> V_39 - V_18 -> V_36 ;
F_2 ( L_9 , V_25 , V_26 ) ;
F_15 ( V_2 -> V_3 , V_40 ,
F_22 ( V_26 ) |
F_23 ( V_25 ) ) ;
if ( ! ( V_18 -> V_22 & V_41 ) )
V_15 |= V_42 ;
if ( ! ( V_18 -> V_22 & V_43 ) )
V_15 |= V_44 ;
F_3 ( V_2 -> V_3 , V_45 ,
V_42 | V_44 ,
V_15 ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_46 ,
V_47 ) ;
F_15 ( V_2 -> V_3 , V_48 , 0 ) ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
unsigned int V_24 , V_25 , V_26 ;
T_2 V_27 ;
T_1 V_15 ;
V_27 = F_11 ( V_18 , 1 ) ;
F_3 ( V_2 -> V_3 , V_10 ,
V_49 ,
F_25 ( V_27 ) ) ;
if ( V_18 -> V_22 & V_23 )
V_15 = V_50 ;
else
V_15 = 0 ;
F_3 ( V_2 -> V_3 , V_10 ,
V_50 ,
V_15 ) ;
F_15 ( V_2 -> V_3 , V_51 ,
F_26 ( V_18 -> V_30 ) |
F_27 ( V_18 -> V_31 ) ) ;
F_15 ( V_2 -> V_3 , V_52 ,
F_28 ( V_18 -> V_30 ) |
F_29 ( V_18 -> V_31 ) ) ;
F_15 ( V_2 -> V_3 , V_53 ,
F_30 ( V_18 -> V_30 ) |
F_31 ( V_18 -> V_31 ) ) ;
V_24 = V_18 -> V_32 - V_18 -> V_38 ;
F_2 ( L_7 ,
V_18 -> V_54 , V_24 ) ;
F_15 ( V_2 -> V_3 , V_55 ,
F_32 ( V_18 -> V_32 ) |
F_33 ( V_24 ) ) ;
V_24 = V_18 -> V_35 - V_18 -> V_39 ;
F_2 ( L_8 ,
V_18 -> V_20 , V_24 ) ;
F_15 ( V_2 -> V_3 , V_56 ,
F_34 ( V_18 -> V_20 ) |
F_35 ( V_24 ) ) ;
V_25 = V_18 -> V_38 - V_18 -> V_33 ;
V_26 = V_18 -> V_39 - V_18 -> V_36 ;
F_2 ( L_9 , V_25 , V_26 ) ;
F_15 ( V_2 -> V_3 , V_57 ,
F_36 ( V_26 ) |
F_37 ( V_25 ) ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_46 ,
V_58 ) ;
if ( V_2 -> V_59 )
F_15 ( V_2 -> V_3 , V_60 , 1 ) ;
}
static void F_38 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
unsigned long V_22 ;
F_39 ( & V_62 -> V_65 , V_22 ) ;
if ( V_64 -> V_66 ) {
F_40 ( & V_64 -> V_67 , V_64 -> V_66 ) ;
F_41 ( & V_64 -> V_67 ) ;
V_64 -> V_66 = NULL ;
}
F_42 ( & V_62 -> V_65 , V_22 ) ;
}
static T_3 F_43 ( int V_68 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
struct V_61 * V_70 = V_2 -> V_70 ;
struct V_71 * V_72 = V_70 -> V_73 ;
struct V_63 * V_64 = V_72 -> V_67 ;
unsigned int V_74 ;
F_44 ( V_2 -> V_3 , V_16 , & V_74 ) ;
if ( ! ( V_74 & ( F_45 ( 0 ) |
F_45 ( 1 ) ) ) )
return V_75 ;
F_46 ( & V_64 -> V_67 ) ;
F_38 ( V_70 , V_64 ) ;
F_3 ( V_2 -> V_3 , V_16 ,
F_45 ( 0 ) |
F_45 ( 1 ) ,
0 ) ;
return V_76 ;
}
static int F_47 ( struct V_77 * V_62 ,
struct V_1 * V_2 )
{
V_2 -> V_78 = F_48 ( V_62 , L_10 ) ;
if ( F_49 ( V_2 -> V_78 ) ) {
F_50 ( V_62 , L_11 ) ;
return F_51 ( V_2 -> V_78 ) ;
}
F_8 ( V_2 -> V_78 ) ;
V_2 -> V_79 = F_48 ( V_62 , L_12 ) ;
if ( F_49 ( V_2 -> V_79 ) ) {
F_50 ( V_62 , L_13 ) ;
return F_51 ( V_2 -> V_79 ) ;
}
V_2 -> V_12 = F_48 ( V_62 , L_14 ) ;
if ( F_49 ( V_2 -> V_12 ) ) {
F_50 ( V_62 , L_15 ) ;
return F_51 ( V_2 -> V_12 ) ;
}
return F_52 ( V_62 , V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
F_6 ( V_2 -> V_78 ) ;
}
static int F_55 ( struct V_77 * V_62 ,
struct V_1 * V_2 )
{
struct V_80 * V_81 = F_56 ( V_62 ) ;
int V_68 , V_82 ;
V_68 = F_57 ( V_81 , 0 ) ;
if ( V_68 < 0 ) {
F_50 ( V_62 , L_16 ) ;
return V_68 ;
}
V_82 = F_58 ( V_62 , V_68 , F_43 , 0 ,
F_59 ( V_62 ) , V_2 ) ;
if ( V_82 ) {
F_50 ( V_62 , L_17 ) ;
return V_82 ;
}
return 0 ;
}
static int F_60 ( struct V_77 * V_62 ,
struct V_1 * V_2 )
{
struct V_80 * V_81 = F_56 ( V_62 ) ;
struct V_83 * V_84 ;
void T_4 * V_3 ;
V_84 = F_61 ( V_81 , V_85 , 0 ) ;
V_3 = F_62 ( V_62 , V_84 ) ;
if ( F_49 ( V_3 ) ) {
F_50 ( V_62 , L_18 ) ;
return F_51 ( V_3 ) ;
}
V_2 -> V_3 = F_63 ( V_62 , V_3 ,
& V_86 ) ;
if ( F_49 ( V_2 -> V_3 ) ) {
F_50 ( V_62 , L_19 ) ;
return F_51 ( V_2 -> V_3 ) ;
}
F_15 ( V_2 -> V_3 , V_4 , 0 ) ;
F_15 ( V_2 -> V_3 , V_16 , 0 ) ;
F_15 ( V_2 -> V_3 , V_87 , 0 ) ;
F_15 ( V_2 -> V_3 , V_48 , ~ 0 ) ;
F_15 ( V_2 -> V_3 , V_88 , ~ 0 ) ;
return 0 ;
}
static struct V_89 * F_64 ( struct V_90 * V_91 )
{
struct V_90 * V_92 , * V_93 , * V_94 ;
struct V_90 * V_95 = NULL ;
V_92 = F_65 ( V_91 , 1 ) ;
F_66 (port, child) {
T_1 V_96 ;
F_67 ( V_94 , L_20 , & V_96 ) ;
if ( V_96 == 0 )
V_95 = V_94 ;
}
if ( ! V_95 ) {
F_2 ( L_21 ) ;
return F_68 ( - V_97 ) ;
}
V_93 = F_69 ( V_95 ) ;
if ( ! V_93 ) {
F_2 ( L_22 ) ;
return F_68 ( - V_98 ) ;
}
return F_70 ( V_93 ) ? : F_68 ( - V_99 ) ;
}
static int F_71 ( struct V_77 * V_62 , struct V_77 * V_100 ,
void * V_101 )
{
struct V_61 * V_70 = V_101 ;
struct V_71 * V_72 = V_70 -> V_73 ;
struct V_1 * V_2 ;
int V_82 ;
V_2 = F_72 ( V_62 , sizeof( * V_2 ) , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
F_73 ( V_62 , V_2 ) ;
V_72 -> V_2 = V_2 ;
V_2 -> V_70 = V_70 ;
if ( F_74 ( V_62 -> V_104 , L_23 ) )
V_2 -> V_59 = true ;
V_2 -> V_105 = F_75 ( V_62 , L_24 ) ;
if ( F_49 ( V_2 -> V_105 ) ) {
F_50 ( V_62 , L_25 ) ;
return F_51 ( V_2 -> V_105 ) ;
}
if ( ! F_76 ( V_2 -> V_105 ) )
F_77 ( V_2 -> V_105 ) ;
V_82 = F_78 ( V_2 -> V_105 ) ;
if ( V_82 ) {
F_50 ( V_62 , L_26 ) ;
return V_82 ;
}
V_82 = F_60 ( V_62 , V_2 ) ;
if ( V_82 ) {
F_50 ( V_62 , L_27 ) ;
goto V_106;
}
V_82 = F_47 ( V_62 , V_2 ) ;
if ( V_82 ) {
F_50 ( V_62 , L_28 ) ;
goto V_106;
}
V_82 = F_55 ( V_62 , V_2 ) ;
if ( V_82 ) {
F_50 ( V_62 , L_29 ) ;
goto V_107;
}
V_2 -> V_108 = F_64 ( V_62 -> V_104 ) ;
if ( F_49 ( V_2 -> V_108 ) ) {
F_79 ( V_62 , L_30 ) ;
return 0 ;
}
V_82 = F_80 ( V_70 ) ;
if ( V_82 < 0 )
goto V_107;
return 0 ;
V_107:
F_53 ( V_2 ) ;
V_106:
F_77 ( V_2 -> V_105 ) ;
return V_82 ;
}
static void F_81 ( struct V_77 * V_62 , struct V_77 * V_100 ,
void * V_101 )
{
struct V_1 * V_2 = F_82 ( V_62 ) ;
F_53 ( V_2 ) ;
}
static int F_83 ( struct V_80 * V_81 )
{
struct V_90 * V_91 = V_81 -> V_62 . V_104 ;
struct V_89 * V_108 ;
V_108 = F_64 ( V_91 ) ;
if ( F_51 ( V_108 ) == - V_99 ) {
F_2 ( L_31 ) ;
return - V_99 ;
}
return F_84 ( & V_81 -> V_62 , & V_109 ) ;
}
static int F_85 ( struct V_80 * V_81 )
{
F_86 ( & V_81 -> V_62 , & V_109 ) ;
return 0 ;
}
