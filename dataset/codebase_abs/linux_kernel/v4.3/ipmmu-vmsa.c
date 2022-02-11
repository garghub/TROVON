static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_5 * V_6 , unsigned int V_7 )
{
return F_4 ( V_6 -> V_8 + V_7 ) ;
}
static void F_5 ( struct V_5 * V_6 , unsigned int V_7 ,
T_1 V_9 )
{
F_6 ( V_9 , V_6 -> V_8 + V_7 ) ;
}
static T_1 F_7 ( struct V_1 * V_10 , unsigned int V_11 )
{
return F_3 ( V_10 -> V_6 , V_10 -> V_12 * V_13 + V_11 ) ;
}
static void F_8 ( struct V_1 * V_10 , unsigned int V_11 ,
T_1 V_9 )
{
F_5 ( V_10 -> V_6 , V_10 -> V_12 * V_13 + V_11 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_10 )
{
unsigned int V_14 = 0 ;
while ( F_7 ( V_10 , V_15 ) & V_16 ) {
F_10 () ;
if ( ++ V_14 == V_17 ) {
F_11 ( V_10 -> V_6 -> V_18 ,
L_1 ) ;
return;
}
F_12 ( 1 ) ;
}
}
static void F_13 ( struct V_1 * V_10 )
{
T_1 V_11 ;
V_11 = F_7 ( V_10 , V_15 ) ;
V_11 |= V_16 ;
F_8 ( V_10 , V_15 , V_11 ) ;
F_9 ( V_10 ) ;
}
static void F_14 ( struct V_1 * V_10 ,
unsigned int V_19 )
{
struct V_5 * V_6 = V_10 -> V_6 ;
F_5 ( V_6 , F_15 ( V_19 ) , 0 ) ;
F_5 ( V_6 , F_16 ( V_19 ) ,
F_17 ( V_10 -> V_12 ) | V_20 |
V_21 ) ;
}
static void F_18 ( struct V_1 * V_10 ,
unsigned int V_19 )
{
struct V_5 * V_6 = V_10 -> V_6 ;
F_5 ( V_6 , F_16 ( V_19 ) , 0 ) ;
}
static void F_19 ( void * V_22 )
{
struct V_1 * V_10 = V_22 ;
F_13 ( V_10 ) ;
}
static void F_20 ( unsigned long V_23 , T_2 V_24 , bool V_25 ,
void * V_22 )
{
}
static int F_21 ( struct V_1 * V_10 )
{
T_3 V_26 ;
V_10 -> V_27 . V_28 = V_29 ;
V_10 -> V_27 . V_30 = V_31 | V_32 | V_33 ,
V_10 -> V_27 . V_34 = 32 ;
V_10 -> V_27 . V_35 = 40 ;
V_10 -> V_27 . V_36 = & V_37 ;
V_10 -> V_27 . V_38 = V_10 -> V_6 -> V_18 ;
V_10 -> V_39 = F_22 ( V_40 , & V_10 -> V_27 ,
V_10 ) ;
if ( ! V_10 -> V_39 )
return - V_41 ;
V_10 -> V_12 = 0 ;
V_26 = V_10 -> V_27 . V_42 . V_26 [ 0 ] ;
F_8 ( V_10 , V_43 , V_26 ) ;
F_8 ( V_10 , V_44 , V_26 >> 32 ) ;
F_8 ( V_10 , V_45 , V_46 |
V_47 | V_48 |
V_49 | V_50 ) ;
F_8 ( V_10 , V_51 , V_10 -> V_27 . V_42 . V_52 [ 0 ] ) ;
F_8 ( V_10 , V_53 ,
F_7 ( V_10 , V_53 ) &
~ ( V_54 | V_55 ) ) ;
F_8 ( V_10 , V_56 , F_7 ( V_10 , V_56 ) ) ;
F_8 ( V_10 , V_15 , V_57 | V_16 | V_58 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_10 )
{
F_8 ( V_10 , V_15 , V_16 ) ;
F_9 ( V_10 ) ;
}
static T_4 F_24 ( struct V_1 * V_10 )
{
const T_1 V_59 = V_60 | V_61 | V_62 | V_63 ;
struct V_5 * V_6 = V_10 -> V_6 ;
T_1 V_64 ;
T_1 V_23 ;
V_64 = F_7 ( V_10 , V_56 ) ;
if ( ! ( V_64 & V_59 ) )
return V_65 ;
V_23 = F_7 ( V_10 , V_66 ) ;
F_8 ( V_10 , V_56 , 0 ) ;
if ( V_64 & V_60 )
F_11 ( V_6 -> V_18 , L_2 ,
V_23 ) ;
if ( V_64 & V_61 )
F_11 ( V_6 -> V_18 , L_3 ,
V_23 ) ;
if ( ! ( V_64 & ( V_62 | V_63 ) ) )
return V_65 ;
if ( ! F_25 ( & V_10 -> V_4 , V_6 -> V_18 , V_23 , 0 ) )
return V_67 ;
F_11 ( V_6 -> V_18 ,
L_4 ,
V_64 , V_23 ) ;
return V_67 ;
}
static T_4 F_26 ( int V_68 , void * V_18 )
{
struct V_5 * V_6 = V_18 ;
struct V_2 * V_4 ;
struct V_1 * V_10 ;
if ( ! V_6 -> V_69 )
return V_65 ;
V_4 = V_6 -> V_69 -> V_10 ;
V_10 = F_1 ( V_4 ) ;
return F_24 ( V_10 ) ;
}
static struct V_2 * F_27 ( unsigned type )
{
struct V_1 * V_10 ;
if ( type != V_70 )
return NULL ;
V_10 = F_28 ( sizeof( * V_10 ) , V_71 ) ;
if ( ! V_10 )
return NULL ;
F_29 ( & V_10 -> V_72 ) ;
return & V_10 -> V_4 ;
}
static void F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_23 ( V_10 ) ;
F_31 ( V_10 -> V_39 ) ;
F_32 ( V_10 ) ;
}
static int F_33 ( struct V_2 * V_4 ,
struct V_73 * V_18 )
{
struct V_74 * V_75 = V_18 -> V_75 . V_76 ;
struct V_5 * V_6 = V_75 -> V_6 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_77 ;
unsigned int V_78 ;
int V_79 = 0 ;
if ( ! V_6 ) {
F_34 ( V_18 , L_5 ) ;
return - V_80 ;
}
F_35 ( & V_10 -> V_72 , V_77 ) ;
if ( ! V_10 -> V_6 ) {
V_10 -> V_6 = V_6 ;
V_79 = F_21 ( V_10 ) ;
} else if ( V_10 -> V_6 != V_6 ) {
F_34 ( V_18 , L_6 ,
F_36 ( V_6 -> V_18 ) , F_36 ( V_10 -> V_6 -> V_18 ) ) ;
V_79 = - V_41 ;
}
F_37 ( & V_10 -> V_72 , V_77 ) ;
if ( V_79 < 0 )
return V_79 ;
for ( V_78 = 0 ; V_78 < V_75 -> V_81 ; ++ V_78 )
F_14 ( V_10 , V_75 -> V_82 [ V_78 ] ) ;
return 0 ;
}
static void F_38 ( struct V_2 * V_4 ,
struct V_73 * V_18 )
{
struct V_74 * V_75 = V_18 -> V_75 . V_76 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_78 ;
for ( V_78 = 0 ; V_78 < V_75 -> V_81 ; ++ V_78 )
F_18 ( V_10 , V_75 -> V_82 [ V_78 ] ) ;
}
static int F_39 ( struct V_2 * V_4 , unsigned long V_23 ,
T_3 V_83 , T_2 V_24 , int V_84 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( ! V_10 )
return - V_85 ;
return V_10 -> V_39 -> V_86 ( V_10 -> V_39 , V_23 , V_83 , V_24 , V_84 ) ;
}
static T_2 F_40 ( struct V_2 * V_4 , unsigned long V_23 ,
T_2 V_24 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_39 -> V_87 ( V_10 -> V_39 , V_23 , V_24 ) ;
}
static T_3 F_41 ( struct V_2 * V_4 ,
T_5 V_23 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_39 -> V_88 ( V_10 -> V_39 , V_23 ) ;
}
static int F_42 ( struct V_5 * V_6 , struct V_73 * V_18 ,
unsigned int * V_82 , unsigned int V_81 )
{
unsigned int V_78 ;
for ( V_78 = 0 ; V_78 < V_81 ; ++ V_78 ) {
struct V_89 args ;
int V_79 ;
V_79 = F_43 ( V_18 -> V_90 , L_7 ,
L_8 , V_78 , & args ) ;
if ( V_79 < 0 )
return V_79 ;
F_44 ( args . V_91 ) ;
if ( args . V_91 != V_6 -> V_18 -> V_90 || args . V_92 != 1 )
return - V_41 ;
V_82 [ V_78 ] = args . args [ 0 ] ;
}
return 0 ;
}
static int F_45 ( struct V_73 * V_18 )
{
struct V_74 * V_75 ;
struct V_5 * V_6 ;
struct V_93 * V_94 = NULL ;
unsigned int * V_82 ;
unsigned int V_78 ;
int V_81 ;
int V_79 = - V_85 ;
if ( V_18 -> V_75 . V_76 ) {
F_46 ( V_18 , L_9 ,
F_36 ( V_18 ) ) ;
return - V_41 ;
}
V_81 = F_47 ( V_18 -> V_90 , L_7 ,
L_8 ) ;
if ( V_81 < 0 )
return - V_85 ;
V_82 = F_48 ( V_81 , sizeof( * V_82 ) , V_71 ) ;
if ( ! V_82 )
return - V_95 ;
F_49 ( & V_96 ) ;
F_50 (mmu, &ipmmu_devices, list) {
V_79 = F_42 ( V_6 , V_18 , V_82 , V_81 ) ;
if ( ! V_79 ) {
break;
}
}
F_51 ( & V_96 ) ;
if ( V_79 < 0 )
return - V_85 ;
for ( V_78 = 0 ; V_78 < V_81 ; ++ V_78 ) {
if ( V_82 [ V_78 ] >= V_6 -> V_81 ) {
V_79 = - V_41 ;
goto error;
}
}
V_94 = F_52 () ;
if ( F_53 ( V_94 ) ) {
F_34 ( V_18 , L_10 ) ;
V_79 = F_54 ( V_94 ) ;
goto error;
}
V_79 = F_55 ( V_94 , V_18 ) ;
F_56 ( V_94 ) ;
if ( V_79 < 0 ) {
F_34 ( V_18 , L_11 ) ;
V_94 = NULL ;
goto error;
}
V_75 = F_28 ( sizeof( * V_75 ) , V_71 ) ;
if ( ! V_75 ) {
V_79 = - V_95 ;
goto error;
}
V_75 -> V_6 = V_6 ;
V_75 -> V_82 = V_82 ;
V_75 -> V_81 = V_81 ;
V_18 -> V_75 . V_76 = V_75 ;
if ( ! V_6 -> V_69 ) {
struct V_97 * V_69 ;
V_69 = F_57 ( & V_98 ,
V_31 , V_99 ) ;
if ( F_53 ( V_69 ) ) {
F_34 ( V_6 -> V_18 , L_12 ) ;
V_79 = F_54 ( V_69 ) ;
goto error;
}
V_6 -> V_69 = V_69 ;
}
V_79 = F_58 ( V_18 , V_6 -> V_69 ) ;
if ( V_79 < 0 ) {
F_34 ( V_18 , L_13 ) ;
goto error;
}
return 0 ;
error:
F_59 ( V_6 -> V_69 ) ;
F_32 ( V_18 -> V_75 . V_76 ) ;
F_32 ( V_82 ) ;
V_18 -> V_75 . V_76 = NULL ;
if ( ! F_60 ( V_94 ) )
F_61 ( V_18 ) ;
return V_79 ;
}
static void F_62 ( struct V_73 * V_18 )
{
struct V_74 * V_75 = V_18 -> V_75 . V_76 ;
F_63 ( V_18 ) ;
F_61 ( V_18 ) ;
F_32 ( V_75 -> V_82 ) ;
F_32 ( V_75 ) ;
V_18 -> V_75 . V_76 = NULL ;
}
static void F_64 ( struct V_5 * V_6 )
{
unsigned int V_78 ;
for ( V_78 = 0 ; V_78 < 4 ; ++ V_78 )
F_5 ( V_6 , V_78 * V_13 + V_15 , 0 ) ;
}
static int F_65 ( struct V_100 * V_101 )
{
struct V_5 * V_6 ;
struct V_102 * V_103 ;
int V_68 ;
int V_79 ;
if ( ! F_66 ( V_104 ) && ! V_101 -> V_18 . V_105 ) {
F_34 ( & V_101 -> V_18 , L_14 ) ;
return - V_41 ;
}
V_6 = F_67 ( & V_101 -> V_18 , sizeof( * V_6 ) , V_71 ) ;
if ( ! V_6 ) {
F_34 ( & V_101 -> V_18 , L_15 ) ;
return - V_95 ;
}
V_6 -> V_18 = & V_101 -> V_18 ;
V_6 -> V_81 = 32 ;
V_103 = F_68 ( V_101 , V_106 , 0 ) ;
V_6 -> V_8 = F_69 ( & V_101 -> V_18 , V_103 ) ;
if ( F_53 ( V_6 -> V_8 ) )
return F_54 ( V_6 -> V_8 ) ;
V_6 -> V_8 += V_107 ;
V_68 = F_70 ( V_101 , 0 ) ;
if ( V_68 < 0 ) {
F_34 ( & V_101 -> V_18 , L_16 ) ;
return V_68 ;
}
V_79 = F_71 ( & V_101 -> V_18 , V_68 , F_26 , 0 ,
F_36 ( & V_101 -> V_18 ) , V_6 ) ;
if ( V_79 < 0 ) {
F_34 ( & V_101 -> V_18 , L_17 , V_68 ) ;
return V_79 ;
}
F_64 ( V_6 ) ;
F_49 ( & V_96 ) ;
F_72 ( & V_6 -> V_108 , & V_109 ) ;
F_51 ( & V_96 ) ;
F_73 ( V_101 , V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_100 * V_101 )
{
struct V_5 * V_6 = F_75 ( V_101 ) ;
F_49 ( & V_96 ) ;
F_76 ( & V_6 -> V_108 ) ;
F_51 ( & V_96 ) ;
F_59 ( V_6 -> V_69 ) ;
F_64 ( V_6 ) ;
return 0 ;
}
static int T_6 F_77 ( void )
{
int V_79 ;
V_79 = F_78 ( & V_110 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( ! F_79 ( & V_98 ) )
F_80 ( & V_98 , & V_111 ) ;
return 0 ;
}
static void T_7 F_81 ( void )
{
return F_82 ( & V_110 ) ;
}
