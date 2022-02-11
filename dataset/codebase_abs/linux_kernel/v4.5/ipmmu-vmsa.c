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
static void F_20 ( unsigned long V_23 , T_2 V_24 ,
T_2 V_25 , bool V_26 , void * V_22 )
{
}
static int F_21 ( struct V_1 * V_10 )
{
T_3 V_27 ;
V_10 -> V_28 . V_29 = V_30 ;
V_10 -> V_28 . V_31 = V_32 | V_33 | V_34 ,
V_10 -> V_28 . V_35 = 32 ;
V_10 -> V_28 . V_36 = 40 ;
V_10 -> V_28 . V_37 = & V_38 ;
V_10 -> V_28 . V_39 = V_10 -> V_6 -> V_18 ;
V_10 -> V_40 = F_22 ( V_41 , & V_10 -> V_28 ,
V_10 ) ;
if ( ! V_10 -> V_40 )
return - V_42 ;
V_10 -> V_12 = 0 ;
V_27 = V_10 -> V_28 . V_43 . V_27 [ 0 ] ;
F_8 ( V_10 , V_44 , V_27 ) ;
F_8 ( V_10 , V_45 , V_27 >> 32 ) ;
F_8 ( V_10 , V_46 , V_47 |
V_48 | V_49 |
V_50 | V_51 ) ;
F_8 ( V_10 , V_52 , V_10 -> V_28 . V_43 . V_53 [ 0 ] ) ;
F_8 ( V_10 , V_54 ,
F_7 ( V_10 , V_54 ) &
~ ( V_55 | V_56 ) ) ;
F_8 ( V_10 , V_57 , F_7 ( V_10 , V_57 ) ) ;
F_8 ( V_10 , V_15 , V_58 | V_16 | V_59 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_10 )
{
F_8 ( V_10 , V_15 , V_16 ) ;
F_9 ( V_10 ) ;
}
static T_4 F_24 ( struct V_1 * V_10 )
{
const T_1 V_60 = V_61 | V_62 | V_63 | V_64 ;
struct V_5 * V_6 = V_10 -> V_6 ;
T_1 V_65 ;
T_1 V_23 ;
V_65 = F_7 ( V_10 , V_57 ) ;
if ( ! ( V_65 & V_60 ) )
return V_66 ;
V_23 = F_7 ( V_10 , V_67 ) ;
F_8 ( V_10 , V_57 , 0 ) ;
if ( V_65 & V_61 )
F_11 ( V_6 -> V_18 , L_2 ,
V_23 ) ;
if ( V_65 & V_62 )
F_11 ( V_6 -> V_18 , L_3 ,
V_23 ) ;
if ( ! ( V_65 & ( V_63 | V_64 ) ) )
return V_66 ;
if ( ! F_25 ( & V_10 -> V_4 , V_6 -> V_18 , V_23 , 0 ) )
return V_68 ;
F_11 ( V_6 -> V_18 ,
L_4 ,
V_65 , V_23 ) ;
return V_68 ;
}
static T_4 F_26 ( int V_69 , void * V_18 )
{
struct V_5 * V_6 = V_18 ;
struct V_2 * V_4 ;
struct V_1 * V_10 ;
if ( ! V_6 -> V_70 )
return V_66 ;
V_4 = V_6 -> V_70 -> V_10 ;
V_10 = F_1 ( V_4 ) ;
return F_24 ( V_10 ) ;
}
static struct V_2 * F_27 ( unsigned type )
{
struct V_1 * V_10 ;
if ( type != V_71 )
return NULL ;
V_10 = F_28 ( sizeof( * V_10 ) , V_72 ) ;
if ( ! V_10 )
return NULL ;
F_29 ( & V_10 -> V_73 ) ;
return & V_10 -> V_4 ;
}
static void F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_23 ( V_10 ) ;
F_31 ( V_10 -> V_40 ) ;
F_32 ( V_10 ) ;
}
static int F_33 ( struct V_2 * V_4 ,
struct V_74 * V_18 )
{
struct V_75 * V_76 = V_18 -> V_76 . V_77 ;
struct V_5 * V_6 = V_76 -> V_6 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_78 ;
unsigned int V_79 ;
int V_80 = 0 ;
if ( ! V_6 ) {
F_34 ( V_18 , L_5 ) ;
return - V_81 ;
}
F_35 ( & V_10 -> V_73 , V_78 ) ;
if ( ! V_10 -> V_6 ) {
V_10 -> V_6 = V_6 ;
V_80 = F_21 ( V_10 ) ;
} else if ( V_10 -> V_6 != V_6 ) {
F_34 ( V_18 , L_6 ,
F_36 ( V_6 -> V_18 ) , F_36 ( V_10 -> V_6 -> V_18 ) ) ;
V_80 = - V_42 ;
}
F_37 ( & V_10 -> V_73 , V_78 ) ;
if ( V_80 < 0 )
return V_80 ;
for ( V_79 = 0 ; V_79 < V_76 -> V_82 ; ++ V_79 )
F_14 ( V_10 , V_76 -> V_83 [ V_79 ] ) ;
return 0 ;
}
static void F_38 ( struct V_2 * V_4 ,
struct V_74 * V_18 )
{
struct V_75 * V_76 = V_18 -> V_76 . V_77 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_79 ;
for ( V_79 = 0 ; V_79 < V_76 -> V_82 ; ++ V_79 )
F_18 ( V_10 , V_76 -> V_83 [ V_79 ] ) ;
}
static int F_39 ( struct V_2 * V_4 , unsigned long V_23 ,
T_5 V_84 , T_2 V_24 , int V_85 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( ! V_10 )
return - V_86 ;
return V_10 -> V_40 -> V_87 ( V_10 -> V_40 , V_23 , V_84 , V_24 , V_85 ) ;
}
static T_2 F_40 ( struct V_2 * V_4 , unsigned long V_23 ,
T_2 V_24 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_40 -> V_88 ( V_10 -> V_40 , V_23 , V_24 ) ;
}
static T_5 F_41 ( struct V_2 * V_4 ,
T_6 V_23 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_40 -> V_89 ( V_10 -> V_40 , V_23 ) ;
}
static int F_42 ( struct V_5 * V_6 , struct V_74 * V_18 ,
unsigned int * V_83 , unsigned int V_82 )
{
unsigned int V_79 ;
for ( V_79 = 0 ; V_79 < V_82 ; ++ V_79 ) {
struct V_90 args ;
int V_80 ;
V_80 = F_43 ( V_18 -> V_91 , L_7 ,
L_8 , V_79 , & args ) ;
if ( V_80 < 0 )
return V_80 ;
F_44 ( args . V_92 ) ;
if ( args . V_92 != V_6 -> V_18 -> V_91 || args . V_93 != 1 )
return - V_42 ;
V_83 [ V_79 ] = args . args [ 0 ] ;
}
return 0 ;
}
static int F_45 ( struct V_74 * V_18 )
{
struct V_75 * V_76 ;
struct V_5 * V_6 ;
struct V_94 * V_95 = NULL ;
unsigned int * V_83 ;
unsigned int V_79 ;
int V_82 ;
int V_80 = - V_86 ;
if ( V_18 -> V_76 . V_77 ) {
F_46 ( V_18 , L_9 ,
F_36 ( V_18 ) ) ;
return - V_42 ;
}
V_82 = F_47 ( V_18 -> V_91 , L_7 ,
L_8 ) ;
if ( V_82 < 0 )
return - V_86 ;
V_83 = F_48 ( V_82 , sizeof( * V_83 ) , V_72 ) ;
if ( ! V_83 )
return - V_96 ;
F_49 ( & V_97 ) ;
F_50 (mmu, &ipmmu_devices, list) {
V_80 = F_42 ( V_6 , V_18 , V_83 , V_82 ) ;
if ( ! V_80 ) {
break;
}
}
F_51 ( & V_97 ) ;
if ( V_80 < 0 )
return - V_86 ;
for ( V_79 = 0 ; V_79 < V_82 ; ++ V_79 ) {
if ( V_83 [ V_79 ] >= V_6 -> V_82 ) {
V_80 = - V_42 ;
goto error;
}
}
V_95 = F_52 () ;
if ( F_53 ( V_95 ) ) {
F_34 ( V_18 , L_10 ) ;
V_80 = F_54 ( V_95 ) ;
goto error;
}
V_80 = F_55 ( V_95 , V_18 ) ;
F_56 ( V_95 ) ;
if ( V_80 < 0 ) {
F_34 ( V_18 , L_11 ) ;
V_95 = NULL ;
goto error;
}
V_76 = F_28 ( sizeof( * V_76 ) , V_72 ) ;
if ( ! V_76 ) {
V_80 = - V_96 ;
goto error;
}
V_76 -> V_6 = V_6 ;
V_76 -> V_83 = V_83 ;
V_76 -> V_82 = V_82 ;
V_18 -> V_76 . V_77 = V_76 ;
if ( ! V_6 -> V_70 ) {
struct V_98 * V_70 ;
V_70 = F_57 ( & V_99 ,
V_32 , V_100 ) ;
if ( F_53 ( V_70 ) ) {
F_34 ( V_6 -> V_18 , L_12 ) ;
V_80 = F_54 ( V_70 ) ;
goto error;
}
V_6 -> V_70 = V_70 ;
}
V_80 = F_58 ( V_18 , V_6 -> V_70 ) ;
if ( V_80 < 0 ) {
F_34 ( V_18 , L_13 ) ;
goto error;
}
return 0 ;
error:
F_59 ( V_6 -> V_70 ) ;
F_32 ( V_18 -> V_76 . V_77 ) ;
F_32 ( V_83 ) ;
V_18 -> V_76 . V_77 = NULL ;
if ( ! F_60 ( V_95 ) )
F_61 ( V_18 ) ;
return V_80 ;
}
static void F_62 ( struct V_74 * V_18 )
{
struct V_75 * V_76 = V_18 -> V_76 . V_77 ;
F_63 ( V_18 ) ;
F_61 ( V_18 ) ;
F_32 ( V_76 -> V_83 ) ;
F_32 ( V_76 ) ;
V_18 -> V_76 . V_77 = NULL ;
}
static void F_64 ( struct V_5 * V_6 )
{
unsigned int V_79 ;
for ( V_79 = 0 ; V_79 < 4 ; ++ V_79 )
F_5 ( V_6 , V_79 * V_13 + V_15 , 0 ) ;
}
static int F_65 ( struct V_101 * V_102 )
{
struct V_5 * V_6 ;
struct V_103 * V_104 ;
int V_69 ;
int V_80 ;
if ( ! F_66 ( V_105 ) && ! V_102 -> V_18 . V_106 ) {
F_34 ( & V_102 -> V_18 , L_14 ) ;
return - V_42 ;
}
V_6 = F_67 ( & V_102 -> V_18 , sizeof( * V_6 ) , V_72 ) ;
if ( ! V_6 ) {
F_34 ( & V_102 -> V_18 , L_15 ) ;
return - V_96 ;
}
V_6 -> V_18 = & V_102 -> V_18 ;
V_6 -> V_82 = 32 ;
V_104 = F_68 ( V_102 , V_107 , 0 ) ;
V_6 -> V_8 = F_69 ( & V_102 -> V_18 , V_104 ) ;
if ( F_53 ( V_6 -> V_8 ) )
return F_54 ( V_6 -> V_8 ) ;
V_6 -> V_8 += V_108 ;
V_69 = F_70 ( V_102 , 0 ) ;
if ( V_69 < 0 ) {
F_34 ( & V_102 -> V_18 , L_16 ) ;
return V_69 ;
}
V_80 = F_71 ( & V_102 -> V_18 , V_69 , F_26 , 0 ,
F_36 ( & V_102 -> V_18 ) , V_6 ) ;
if ( V_80 < 0 ) {
F_34 ( & V_102 -> V_18 , L_17 , V_69 ) ;
return V_80 ;
}
F_64 ( V_6 ) ;
F_49 ( & V_97 ) ;
F_72 ( & V_6 -> V_109 , & V_110 ) ;
F_51 ( & V_97 ) ;
F_73 ( V_102 , V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_101 * V_102 )
{
struct V_5 * V_6 = F_75 ( V_102 ) ;
F_49 ( & V_97 ) ;
F_76 ( & V_6 -> V_109 ) ;
F_51 ( & V_97 ) ;
F_59 ( V_6 -> V_70 ) ;
F_64 ( V_6 ) ;
return 0 ;
}
static int T_7 F_77 ( void )
{
int V_80 ;
V_80 = F_78 ( & V_111 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( ! F_79 ( & V_99 ) )
F_80 ( & V_99 , & V_112 ) ;
return 0 ;
}
static void T_8 F_81 ( void )
{
return F_82 ( & V_111 ) ;
}
