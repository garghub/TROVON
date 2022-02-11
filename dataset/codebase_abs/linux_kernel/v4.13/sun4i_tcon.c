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
F_2 ( L_3 , V_6 ) ;
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
F_2 ( L_4 , V_6 ) ;
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
F_2 ( L_5 , V_15 ? L_6 : L_7 ) ;
V_16 = F_11 ( 0 ) |
F_11 ( 1 ) ;
if ( V_15 )
V_17 = V_16 ;
F_3 ( V_2 -> V_3 , V_18 , V_16 , V_17 ) ;
}
void F_12 ( struct V_1 * V_2 , int V_6 ,
struct V_19 * V_20 )
{
T_1 V_17 ;
if ( ! V_2 -> V_10 -> V_21 )
return;
if ( V_6 != 1 )
return;
if ( V_20 -> V_22 == V_23 )
V_17 = 1 ;
else
V_17 = 0 ;
F_13 ( V_2 -> V_3 , V_24 , V_17 ) ;
}
static int F_14 ( struct V_25 * V_26 ,
int V_6 )
{
int V_27 = V_26 -> V_28 - V_26 -> V_29 ;
if ( V_26 -> V_30 & V_31 )
V_27 /= 2 ;
if ( V_6 == 1 )
V_27 -= 2 ;
V_27 = F_15 ( V_27 , 30 ) ;
F_2 ( L_8 , V_6 , V_27 ) ;
return V_27 ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
unsigned int V_32 , V_33 , V_34 ;
T_2 V_35 ;
T_1 V_17 = 0 ;
F_17 ( V_2 -> V_9 , V_26 -> V_36 * 1000 ) ;
V_35 = F_14 ( V_26 , 0 ) ;
F_3 ( V_2 -> V_3 , V_7 ,
V_37 ,
F_18 ( V_35 ) ) ;
F_13 ( V_2 -> V_3 , V_38 ,
F_19 ( V_26 -> V_39 ) |
F_20 ( V_26 -> V_40 ) ) ;
V_32 = V_26 -> V_41 - V_26 -> V_42 ;
F_2 ( L_9 ,
V_26 -> V_41 , V_32 ) ;
F_13 ( V_2 -> V_3 , V_43 ,
F_21 ( V_26 -> V_41 ) |
F_22 ( V_32 ) ) ;
V_32 = V_26 -> V_44 - V_26 -> V_45 ;
F_2 ( L_10 ,
V_26 -> V_44 , V_32 ) ;
F_13 ( V_2 -> V_3 , V_46 ,
F_23 ( V_26 -> V_44 * 2 ) |
F_24 ( V_32 ) ) ;
V_33 = V_26 -> V_47 - V_26 -> V_42 ;
V_34 = V_26 -> V_48 - V_26 -> V_45 ;
F_2 ( L_11 , V_33 , V_34 ) ;
F_13 ( V_2 -> V_3 , V_49 ,
F_25 ( V_34 ) |
F_26 ( V_33 ) ) ;
if ( ! ( V_26 -> V_30 & V_50 ) )
V_17 |= V_51 ;
if ( ! ( V_26 -> V_30 & V_52 ) )
V_17 |= V_53 ;
F_3 ( V_2 -> V_3 , V_54 ,
V_51 | V_53 ,
V_17 ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_55 ,
V_56 ) ;
F_13 ( V_2 -> V_3 , V_57 , 0 ) ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
unsigned int V_32 , V_33 , V_34 , V_28 ;
T_2 V_35 ;
T_1 V_17 ;
F_7 ( ! V_2 -> V_10 -> V_11 ) ;
F_17 ( V_2 -> V_14 , V_26 -> V_36 * 1000 ) ;
V_35 = F_14 ( V_26 , 1 ) ;
F_3 ( V_2 -> V_3 , V_12 ,
V_58 ,
F_28 ( V_35 ) ) ;
if ( V_26 -> V_30 & V_31 )
V_17 = V_59 ;
else
V_17 = 0 ;
F_3 ( V_2 -> V_3 , V_12 ,
V_59 ,
V_17 ) ;
F_13 ( V_2 -> V_3 , V_60 ,
F_29 ( V_26 -> V_39 ) |
F_30 ( V_26 -> V_40 ) ) ;
F_13 ( V_2 -> V_3 , V_61 ,
F_31 ( V_26 -> V_39 ) |
F_32 ( V_26 -> V_40 ) ) ;
F_13 ( V_2 -> V_3 , V_62 ,
F_33 ( V_26 -> V_39 ) |
F_34 ( V_26 -> V_40 ) ) ;
V_32 = V_26 -> V_41 - V_26 -> V_42 ;
F_2 ( L_9 ,
V_26 -> V_63 , V_32 ) ;
F_13 ( V_2 -> V_3 , V_64 ,
F_35 ( V_26 -> V_41 ) |
F_36 ( V_32 ) ) ;
V_32 = V_26 -> V_44 - V_26 -> V_45 ;
F_2 ( L_10 ,
V_26 -> V_44 , V_32 ) ;
V_28 = V_26 -> V_28 ;
if ( ! ( V_26 -> V_30 & V_31 ) )
V_28 = V_28 * 2 ;
F_13 ( V_2 -> V_3 , V_65 ,
F_37 ( V_28 ) |
F_38 ( V_32 ) ) ;
V_33 = V_26 -> V_47 - V_26 -> V_42 ;
V_34 = V_26 -> V_48 - V_26 -> V_45 ;
F_2 ( L_11 , V_33 , V_34 ) ;
F_13 ( V_2 -> V_3 , V_66 ,
F_39 ( V_34 ) |
F_40 ( V_33 ) ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_55 ,
V_67 ) ;
}
static void F_41 ( struct V_68 * V_69 ,
struct V_70 * V_71 )
{
unsigned long V_30 ;
F_42 ( & V_69 -> V_72 , V_30 ) ;
if ( V_71 -> V_73 ) {
F_43 ( & V_71 -> V_74 , V_71 -> V_73 ) ;
F_44 ( & V_71 -> V_74 ) ;
V_71 -> V_73 = NULL ;
}
F_45 ( & V_69 -> V_72 , V_30 ) ;
}
static T_3 F_46 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
struct V_68 * V_77 = V_2 -> V_77 ;
struct V_70 * V_71 = V_2 -> V_74 ;
unsigned int V_78 ;
F_47 ( V_2 -> V_3 , V_18 , & V_78 ) ;
if ( ! ( V_78 & ( F_48 ( 0 ) |
F_48 ( 1 ) ) ) )
return V_79 ;
F_49 ( & V_71 -> V_74 ) ;
F_41 ( V_77 , V_71 ) ;
F_3 ( V_2 -> V_3 , V_18 ,
F_48 ( 0 ) |
F_48 ( 1 ) ,
0 ) ;
return V_80 ;
}
static int F_50 ( struct V_81 * V_69 ,
struct V_1 * V_2 )
{
V_2 -> V_82 = F_51 ( V_69 , L_12 ) ;
if ( F_52 ( V_2 -> V_82 ) ) {
F_53 ( V_69 , L_13 ) ;
return F_54 ( V_2 -> V_82 ) ;
}
F_9 ( V_2 -> V_82 ) ;
V_2 -> V_83 = F_51 ( V_69 , L_14 ) ;
if ( F_52 ( V_2 -> V_83 ) ) {
F_53 ( V_69 , L_15 ) ;
return F_54 ( V_2 -> V_83 ) ;
}
if ( V_2 -> V_10 -> V_11 ) {
V_2 -> V_14 = F_51 ( V_69 , L_16 ) ;
if ( F_52 ( V_2 -> V_14 ) ) {
F_53 ( V_69 , L_17 ) ;
return F_54 ( V_2 -> V_14 ) ;
}
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_82 ) ;
}
static int F_56 ( struct V_81 * V_69 ,
struct V_1 * V_2 )
{
struct V_84 * V_85 = F_57 ( V_69 ) ;
int V_75 , V_86 ;
V_75 = F_58 ( V_85 , 0 ) ;
if ( V_75 < 0 ) {
F_53 ( V_69 , L_18 ) ;
return V_75 ;
}
V_86 = F_59 ( V_69 , V_75 , F_46 , 0 ,
F_60 ( V_69 ) , V_2 ) ;
if ( V_86 ) {
F_53 ( V_69 , L_19 ) ;
return V_86 ;
}
return 0 ;
}
static int F_61 ( struct V_81 * V_69 ,
struct V_1 * V_2 )
{
struct V_84 * V_85 = F_57 ( V_69 ) ;
struct V_87 * V_88 ;
void T_4 * V_3 ;
V_88 = F_62 ( V_85 , V_89 , 0 ) ;
V_3 = F_63 ( V_69 , V_88 ) ;
if ( F_52 ( V_3 ) )
return F_54 ( V_3 ) ;
V_2 -> V_3 = F_64 ( V_69 , V_3 ,
& V_90 ) ;
if ( F_52 ( V_2 -> V_3 ) ) {
F_53 ( V_69 , L_20 ) ;
return F_54 ( V_2 -> V_3 ) ;
}
F_13 ( V_2 -> V_3 , V_4 , 0 ) ;
F_13 ( V_2 -> V_3 , V_18 , 0 ) ;
F_13 ( V_2 -> V_3 , V_91 , 0 ) ;
F_13 ( V_2 -> V_3 , V_57 , ~ 0 ) ;
F_13 ( V_2 -> V_3 , V_92 , ~ 0 ) ;
return 0 ;
}
static struct V_93 * F_65 ( struct V_94 * V_95 ,
struct V_96 * V_97 )
{
struct V_96 * V_98 , * V_99 , * V_100 ;
struct V_93 * V_101 ;
V_98 = F_66 ( V_97 , 0 ) ;
if ( ! V_98 )
return F_67 ( - V_102 ) ;
F_68 (port, ep) {
V_100 = F_69 ( V_99 ) ;
if ( ! V_100 )
continue;
F_70 (engine, &drv->engine_list, list) {
if ( V_100 == V_101 -> V_97 ) {
F_71 ( V_100 ) ;
F_71 ( V_98 ) ;
return V_101 ;
}
}
V_101 = F_65 ( V_95 , V_100 ) ;
if ( ! F_52 ( V_101 ) ) {
F_71 ( V_100 ) ;
F_71 ( V_98 ) ;
return V_101 ;
}
}
return F_67 ( - V_102 ) ;
}
static int F_72 ( struct V_81 * V_69 , struct V_81 * V_103 ,
void * V_104 )
{
struct V_68 * V_77 = V_104 ;
struct V_94 * V_95 = V_77 -> V_105 ;
struct V_93 * V_101 ;
struct V_1 * V_2 ;
int V_86 ;
V_101 = F_65 ( V_95 , V_69 -> V_106 ) ;
if ( F_52 ( V_101 ) ) {
F_53 ( V_69 , L_21 ) ;
return - V_107 ;
}
V_2 = F_73 ( V_69 , sizeof( * V_2 ) , V_108 ) ;
if ( ! V_2 )
return - V_109 ;
F_74 ( V_69 , V_2 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_69 = V_69 ;
V_2 -> V_110 = V_101 -> V_110 ;
V_2 -> V_10 = F_75 ( V_69 ) ;
V_2 -> V_111 = F_76 ( V_69 , L_22 ) ;
if ( F_52 ( V_2 -> V_111 ) ) {
F_53 ( V_69 , L_23 ) ;
return F_54 ( V_2 -> V_111 ) ;
}
if ( ! F_77 ( V_2 -> V_111 ) )
F_78 ( V_2 -> V_111 ) ;
V_86 = F_79 ( V_2 -> V_111 ) ;
if ( V_86 ) {
F_53 ( V_69 , L_24 ) ;
return V_86 ;
}
V_86 = F_50 ( V_69 , V_2 ) ;
if ( V_86 ) {
F_53 ( V_69 , L_25 ) ;
goto V_112;
}
V_86 = F_61 ( V_69 , V_2 ) ;
if ( V_86 ) {
F_53 ( V_69 , L_26 ) ;
goto V_113;
}
V_86 = F_80 ( V_69 , V_2 ) ;
if ( V_86 ) {
F_53 ( V_69 , L_27 ) ;
goto V_113;
}
V_86 = F_56 ( V_69 , V_2 ) ;
if ( V_86 ) {
F_53 ( V_69 , L_28 ) ;
goto V_114;
}
V_2 -> V_74 = F_81 ( V_77 , V_101 , V_2 ) ;
if ( F_52 ( V_2 -> V_74 ) ) {
F_53 ( V_69 , L_29 ) ;
V_86 = F_54 ( V_2 -> V_74 ) ;
goto V_113;
}
V_86 = F_82 ( V_77 , V_2 ) ;
if ( V_86 < 0 )
goto V_113;
F_83 ( & V_2 -> V_115 , & V_95 -> V_116 ) ;
return 0 ;
V_114:
F_84 ( V_2 ) ;
V_113:
F_55 ( V_2 ) ;
V_112:
F_78 ( V_2 -> V_111 ) ;
return V_86 ;
}
static void F_85 ( struct V_81 * V_69 , struct V_81 * V_103 ,
void * V_104 )
{
struct V_1 * V_2 = F_86 ( V_69 ) ;
F_87 ( & V_2 -> V_115 ) ;
F_84 ( V_2 ) ;
F_55 ( V_2 ) ;
}
static int F_88 ( struct V_84 * V_85 )
{
struct V_96 * V_97 = V_85 -> V_69 . V_106 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
int V_86 ;
V_86 = F_89 ( V_97 , 1 , 0 , & V_120 , & V_118 ) ;
if ( V_86 == - V_107 )
return V_86 ;
return F_90 ( & V_85 -> V_69 , & V_121 ) ;
}
static int F_91 ( struct V_84 * V_85 )
{
F_92 ( & V_85 -> V_69 , & V_121 ) ;
return 0 ;
}
