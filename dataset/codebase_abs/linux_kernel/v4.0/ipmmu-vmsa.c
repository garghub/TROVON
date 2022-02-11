static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
return F_1 ( V_7 -> V_2 , V_7 -> V_9 * V_10 + V_8 ) ;
}
static void F_6 ( struct V_6 * V_7 , unsigned int V_8 ,
T_1 V_5 )
{
F_3 ( V_7 -> V_2 , V_7 -> V_9 * V_10 + V_8 , V_5 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
unsigned int V_11 = 0 ;
while ( F_5 ( V_7 , V_12 ) & V_13 ) {
F_8 () ;
if ( ++ V_11 == V_14 ) {
F_9 ( V_7 -> V_2 -> V_15 ,
L_1 ) ;
return;
}
F_10 ( 1 ) ;
}
}
static void F_11 ( struct V_6 * V_7 )
{
T_1 V_8 ;
V_8 = F_5 ( V_7 , V_12 ) ;
V_8 |= V_13 ;
F_6 ( V_7 , V_12 , V_8 ) ;
F_7 ( V_7 ) ;
}
static void F_12 ( struct V_6 * V_7 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , F_13 ( V_16 ) , 0 ) ;
F_3 ( V_2 , F_14 ( V_16 ) ,
F_15 ( V_7 -> V_9 ) | V_17 |
V_18 ) ;
}
static void F_16 ( struct V_6 * V_7 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , F_14 ( V_16 ) , 0 ) ;
}
static void F_17 ( void * V_19 )
{
struct V_6 * V_7 = V_19 ;
F_11 ( V_7 ) ;
}
static void F_18 ( unsigned long V_20 , T_2 V_21 , bool V_22 ,
void * V_19 )
{
}
static void F_19 ( void * V_23 , T_2 V_21 , void * V_19 )
{
unsigned long V_3 = ( unsigned long ) V_23 & ~ V_24 ;
struct V_6 * V_7 = V_19 ;
F_20 ( V_7 -> V_2 -> V_15 , F_21 ( V_23 ) , V_3 , V_21 ,
V_25 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
T_3 V_26 ;
V_7 -> V_27 . V_28 = V_29 ;
V_7 -> V_27 . V_30 = V_31 | V_32 | V_33 ,
V_7 -> V_27 . V_34 = 32 ;
V_7 -> V_27 . V_35 = 40 ;
V_7 -> V_27 . V_36 = & V_37 ;
V_7 -> V_38 = F_23 ( V_39 , & V_7 -> V_27 ,
V_7 ) ;
if ( ! V_7 -> V_38 )
return - V_40 ;
V_7 -> V_9 = 0 ;
V_26 = V_7 -> V_27 . V_41 . V_26 [ 0 ] ;
F_6 ( V_7 , V_42 , V_26 ) ;
F_6 ( V_7 , V_43 , V_26 >> 32 ) ;
F_6 ( V_7 , V_44 , V_45 |
V_46 | V_47 |
V_48 | V_49 ) ;
F_6 ( V_7 , V_50 , V_7 -> V_27 . V_41 . V_51 [ 0 ] ) ;
F_6 ( V_7 , V_52 ,
F_5 ( V_7 , V_52 ) &
~ ( V_53 | V_54 ) ) ;
F_6 ( V_7 , V_55 , F_5 ( V_7 , V_55 ) ) ;
F_6 ( V_7 , V_12 , V_56 | V_13 | V_57 ) ;
return 0 ;
}
static void F_24 ( struct V_6 * V_7 )
{
F_6 ( V_7 , V_12 , V_13 ) ;
F_7 ( V_7 ) ;
}
static T_4 F_25 ( struct V_6 * V_7 )
{
const T_1 V_58 = V_59 | V_60 | V_61 | V_62 ;
struct V_1 * V_2 = V_7 -> V_2 ;
T_1 V_63 ;
T_1 V_20 ;
V_63 = F_5 ( V_7 , V_55 ) ;
if ( ! ( V_63 & V_58 ) )
return V_64 ;
V_20 = F_5 ( V_7 , V_65 ) ;
F_6 ( V_7 , V_55 , 0 ) ;
if ( V_63 & V_59 )
F_9 ( V_2 -> V_15 , L_2 ,
V_20 ) ;
if ( V_63 & V_60 )
F_9 ( V_2 -> V_15 , L_3 ,
V_20 ) ;
if ( ! ( V_63 & ( V_61 | V_62 ) ) )
return V_64 ;
if ( ! F_26 ( V_7 -> V_66 , V_2 -> V_15 , V_20 , 0 ) )
return V_67 ;
F_9 ( V_2 -> V_15 ,
L_4 ,
V_63 , V_20 ) ;
return V_67 ;
}
static T_4 F_27 ( int V_68 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
struct V_69 * V_66 ;
struct V_6 * V_7 ;
if ( ! V_2 -> V_70 )
return V_64 ;
V_66 = V_2 -> V_70 -> V_7 ;
V_7 = V_66 -> V_71 ;
return F_25 ( V_7 ) ;
}
static int F_28 ( struct V_69 * V_66 )
{
struct V_6 * V_7 ;
V_7 = F_29 ( sizeof( * V_7 ) , V_72 ) ;
if ( ! V_7 )
return - V_73 ;
F_30 ( & V_7 -> V_74 ) ;
V_66 -> V_71 = V_7 ;
V_7 -> V_66 = V_66 ;
return 0 ;
}
static void F_31 ( struct V_69 * V_66 )
{
struct V_6 * V_7 = V_66 -> V_71 ;
F_24 ( V_7 ) ;
F_32 ( V_7 -> V_38 ) ;
F_33 ( V_7 ) ;
}
static int F_34 ( struct V_69 * V_66 ,
struct V_75 * V_15 )
{
struct V_76 * V_77 = V_15 -> V_77 . V_78 ;
struct V_1 * V_2 = V_77 -> V_2 ;
struct V_6 * V_7 = V_66 -> V_71 ;
unsigned long V_79 ;
unsigned int V_80 ;
int V_81 = 0 ;
if ( ! V_2 ) {
F_35 ( V_15 , L_5 ) ;
return - V_82 ;
}
F_36 ( & V_7 -> V_74 , V_79 ) ;
if ( ! V_7 -> V_2 ) {
V_7 -> V_2 = V_2 ;
V_81 = F_22 ( V_7 ) ;
} else if ( V_7 -> V_2 != V_2 ) {
F_35 ( V_15 , L_6 ,
F_37 ( V_2 -> V_15 ) , F_37 ( V_7 -> V_2 -> V_15 ) ) ;
V_81 = - V_40 ;
}
F_38 ( & V_7 -> V_74 , V_79 ) ;
if ( V_81 < 0 )
return V_81 ;
for ( V_80 = 0 ; V_80 < V_77 -> V_83 ; ++ V_80 )
F_12 ( V_7 , V_77 -> V_84 [ V_80 ] ) ;
return 0 ;
}
static void F_39 ( struct V_69 * V_66 ,
struct V_75 * V_15 )
{
struct V_76 * V_77 = V_15 -> V_77 . V_78 ;
struct V_6 * V_7 = V_66 -> V_71 ;
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < V_77 -> V_83 ; ++ V_80 )
F_16 ( V_7 , V_77 -> V_84 [ V_80 ] ) ;
}
static int F_40 ( struct V_69 * V_66 , unsigned long V_20 ,
T_3 V_85 , T_2 V_21 , int V_86 )
{
struct V_6 * V_7 = V_66 -> V_71 ;
if ( ! V_7 )
return - V_87 ;
return V_7 -> V_38 -> V_88 ( V_7 -> V_38 , V_20 , V_85 , V_21 , V_86 ) ;
}
static T_2 F_41 ( struct V_69 * V_66 , unsigned long V_20 ,
T_2 V_21 )
{
struct V_6 * V_7 = V_66 -> V_71 ;
return V_7 -> V_38 -> V_89 ( V_7 -> V_38 , V_20 , V_21 ) ;
}
static T_3 F_42 ( struct V_69 * V_66 ,
T_5 V_20 )
{
struct V_6 * V_7 = V_66 -> V_71 ;
return V_7 -> V_38 -> V_90 ( V_7 -> V_38 , V_20 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_75 * V_15 ,
unsigned int * V_84 , unsigned int V_83 )
{
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < V_83 ; ++ V_80 ) {
struct V_91 args ;
int V_81 ;
V_81 = F_44 ( V_15 -> V_92 , L_7 ,
L_8 , V_80 , & args ) ;
if ( V_81 < 0 )
return V_81 ;
F_45 ( args . V_93 ) ;
if ( args . V_93 != V_2 -> V_15 -> V_92 || args . V_94 != 1 )
return - V_40 ;
V_84 [ V_80 ] = args . args [ 0 ] ;
}
return 0 ;
}
static int F_46 ( struct V_75 * V_15 )
{
struct V_76 * V_77 ;
struct V_1 * V_2 ;
struct V_95 * V_96 = NULL ;
unsigned int * V_84 ;
unsigned int V_80 ;
int V_83 ;
int V_81 = - V_87 ;
if ( V_15 -> V_77 . V_78 ) {
F_47 ( V_15 , L_9 ,
F_37 ( V_15 ) ) ;
return - V_40 ;
}
V_83 = F_48 ( V_15 -> V_92 , L_7 ,
L_8 ) ;
if ( V_83 < 0 )
return - V_87 ;
V_84 = F_49 ( V_83 , sizeof( * V_84 ) , V_72 ) ;
if ( ! V_84 )
return - V_73 ;
F_50 ( & V_97 ) ;
F_51 (mmu, &ipmmu_devices, list) {
V_81 = F_43 ( V_2 , V_15 , V_84 , V_83 ) ;
if ( ! V_81 ) {
break;
}
}
F_52 ( & V_97 ) ;
if ( V_81 < 0 )
return - V_87 ;
for ( V_80 = 0 ; V_80 < V_83 ; ++ V_80 ) {
if ( V_84 [ V_80 ] >= V_2 -> V_83 ) {
V_81 = - V_40 ;
goto error;
}
}
V_96 = F_53 () ;
if ( F_54 ( V_96 ) ) {
F_35 ( V_15 , L_10 ) ;
V_81 = F_55 ( V_96 ) ;
goto error;
}
V_81 = F_56 ( V_96 , V_15 ) ;
F_57 ( V_96 ) ;
if ( V_81 < 0 ) {
F_35 ( V_15 , L_11 ) ;
V_96 = NULL ;
goto error;
}
V_77 = F_29 ( sizeof( * V_77 ) , V_72 ) ;
if ( ! V_77 ) {
V_81 = - V_73 ;
goto error;
}
V_77 -> V_2 = V_2 ;
V_77 -> V_84 = V_84 ;
V_77 -> V_83 = V_83 ;
V_15 -> V_77 . V_78 = V_77 ;
if ( ! V_2 -> V_70 ) {
struct V_98 * V_70 ;
V_70 = F_58 ( & V_99 ,
V_31 , V_100 ) ;
if ( F_54 ( V_70 ) ) {
F_35 ( V_2 -> V_15 , L_12 ) ;
V_81 = F_55 ( V_70 ) ;
goto error;
}
V_2 -> V_70 = V_70 ;
}
V_81 = F_59 ( V_15 , V_2 -> V_70 ) ;
if ( V_81 < 0 ) {
F_35 ( V_15 , L_13 ) ;
goto error;
}
return 0 ;
error:
F_60 ( V_2 -> V_70 ) ;
F_33 ( V_15 -> V_77 . V_78 ) ;
F_33 ( V_84 ) ;
V_15 -> V_77 . V_78 = NULL ;
if ( ! F_61 ( V_96 ) )
F_62 ( V_15 ) ;
return V_81 ;
}
static void F_63 ( struct V_75 * V_15 )
{
struct V_76 * V_77 = V_15 -> V_77 . V_78 ;
F_64 ( V_15 ) ;
F_62 ( V_15 ) ;
F_33 ( V_77 -> V_84 ) ;
F_33 ( V_77 ) ;
V_15 -> V_77 . V_78 = NULL ;
}
static void F_65 ( struct V_1 * V_2 )
{
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < 4 ; ++ V_80 )
F_3 ( V_2 , V_80 * V_10 + V_12 , 0 ) ;
}
static int F_66 ( struct V_101 * V_102 )
{
struct V_1 * V_2 ;
struct V_103 * V_104 ;
int V_68 ;
int V_81 ;
if ( ! F_67 ( V_105 ) && ! V_102 -> V_15 . V_106 ) {
F_35 ( & V_102 -> V_15 , L_14 ) ;
return - V_40 ;
}
V_2 = F_68 ( & V_102 -> V_15 , sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 ) {
F_35 ( & V_102 -> V_15 , L_15 ) ;
return - V_73 ;
}
V_2 -> V_15 = & V_102 -> V_15 ;
V_2 -> V_83 = 32 ;
V_104 = F_69 ( V_102 , V_107 , 0 ) ;
V_2 -> V_4 = F_70 ( & V_102 -> V_15 , V_104 ) ;
if ( F_54 ( V_2 -> V_4 ) )
return F_55 ( V_2 -> V_4 ) ;
V_2 -> V_4 += V_108 ;
V_68 = F_71 ( V_102 , 0 ) ;
if ( V_68 < 0 ) {
F_35 ( & V_102 -> V_15 , L_16 ) ;
return V_68 ;
}
V_81 = F_72 ( & V_102 -> V_15 , V_68 , F_27 , 0 ,
F_37 ( & V_102 -> V_15 ) , V_2 ) ;
if ( V_81 < 0 ) {
F_35 ( & V_102 -> V_15 , L_17 , V_68 ) ;
return V_81 ;
}
F_65 ( V_2 ) ;
F_50 ( & V_97 ) ;
F_73 ( & V_2 -> V_109 , & V_110 ) ;
F_52 ( & V_97 ) ;
F_74 ( V_102 , V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_76 ( V_102 ) ;
F_50 ( & V_97 ) ;
F_77 ( & V_2 -> V_109 ) ;
F_52 ( & V_97 ) ;
F_60 ( V_2 -> V_70 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
static int T_6 F_78 ( void )
{
int V_81 ;
V_81 = F_79 ( & V_111 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( ! F_80 ( & V_99 ) )
F_81 ( & V_99 , & V_112 ) ;
return 0 ;
}
static void T_7 F_82 ( void )
{
return F_83 ( & V_111 ) ;
}
