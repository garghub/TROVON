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
static void F_21 ( void * V_26 , T_2 V_24 , void * V_22 )
{
unsigned long V_7 = ( unsigned long ) V_26 & ~ V_27 ;
struct V_1 * V_10 = V_22 ;
F_22 ( V_10 -> V_6 -> V_18 , F_23 ( V_26 ) , V_7 , V_24 ,
V_28 ) ;
}
static int F_24 ( struct V_1 * V_10 )
{
T_3 V_29 ;
V_10 -> V_30 . V_31 = V_32 ;
V_10 -> V_30 . V_33 = V_34 | V_35 | V_36 ,
V_10 -> V_30 . V_37 = 32 ;
V_10 -> V_30 . V_38 = 40 ;
V_10 -> V_30 . V_39 = & V_40 ;
V_10 -> V_41 = F_25 ( V_42 , & V_10 -> V_30 ,
V_10 ) ;
if ( ! V_10 -> V_41 )
return - V_43 ;
V_10 -> V_12 = 0 ;
V_29 = V_10 -> V_30 . V_44 . V_29 [ 0 ] ;
F_8 ( V_10 , V_45 , V_29 ) ;
F_8 ( V_10 , V_46 , V_29 >> 32 ) ;
F_8 ( V_10 , V_47 , V_48 |
V_49 | V_50 |
V_51 | V_52 ) ;
F_8 ( V_10 , V_53 , V_10 -> V_30 . V_44 . V_54 [ 0 ] ) ;
F_8 ( V_10 , V_55 ,
F_7 ( V_10 , V_55 ) &
~ ( V_56 | V_57 ) ) ;
F_8 ( V_10 , V_58 , F_7 ( V_10 , V_58 ) ) ;
F_8 ( V_10 , V_15 , V_59 | V_16 | V_60 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_10 )
{
F_8 ( V_10 , V_15 , V_16 ) ;
F_9 ( V_10 ) ;
}
static T_4 F_27 ( struct V_1 * V_10 )
{
const T_1 V_61 = V_62 | V_63 | V_64 | V_65 ;
struct V_5 * V_6 = V_10 -> V_6 ;
T_1 V_66 ;
T_1 V_23 ;
V_66 = F_7 ( V_10 , V_58 ) ;
if ( ! ( V_66 & V_61 ) )
return V_67 ;
V_23 = F_7 ( V_10 , V_68 ) ;
F_8 ( V_10 , V_58 , 0 ) ;
if ( V_66 & V_62 )
F_11 ( V_6 -> V_18 , L_2 ,
V_23 ) ;
if ( V_66 & V_63 )
F_11 ( V_6 -> V_18 , L_3 ,
V_23 ) ;
if ( ! ( V_66 & ( V_64 | V_65 ) ) )
return V_67 ;
if ( ! F_28 ( & V_10 -> V_4 , V_6 -> V_18 , V_23 , 0 ) )
return V_69 ;
F_11 ( V_6 -> V_18 ,
L_4 ,
V_66 , V_23 ) ;
return V_69 ;
}
static T_4 F_29 ( int V_70 , void * V_18 )
{
struct V_5 * V_6 = V_18 ;
struct V_2 * V_4 ;
struct V_1 * V_10 ;
if ( ! V_6 -> V_71 )
return V_67 ;
V_4 = V_6 -> V_71 -> V_10 ;
V_10 = F_1 ( V_4 ) ;
return F_27 ( V_10 ) ;
}
static struct V_2 * F_30 ( unsigned type )
{
struct V_1 * V_10 ;
if ( type != V_72 )
return NULL ;
V_10 = F_31 ( sizeof( * V_10 ) , V_73 ) ;
if ( ! V_10 )
return NULL ;
F_32 ( & V_10 -> V_74 ) ;
return & V_10 -> V_4 ;
}
static void F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_26 ( V_10 ) ;
F_34 ( V_10 -> V_41 ) ;
F_35 ( V_10 ) ;
}
static int F_36 ( struct V_2 * V_4 ,
struct V_75 * V_18 )
{
struct V_76 * V_77 = V_18 -> V_77 . V_78 ;
struct V_5 * V_6 = V_77 -> V_6 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_79 ;
unsigned int V_80 ;
int V_81 = 0 ;
if ( ! V_6 ) {
F_37 ( V_18 , L_5 ) ;
return - V_82 ;
}
F_38 ( & V_10 -> V_74 , V_79 ) ;
if ( ! V_10 -> V_6 ) {
V_10 -> V_6 = V_6 ;
V_81 = F_24 ( V_10 ) ;
} else if ( V_10 -> V_6 != V_6 ) {
F_37 ( V_18 , L_6 ,
F_39 ( V_6 -> V_18 ) , F_39 ( V_10 -> V_6 -> V_18 ) ) ;
V_81 = - V_43 ;
}
F_40 ( & V_10 -> V_74 , V_79 ) ;
if ( V_81 < 0 )
return V_81 ;
for ( V_80 = 0 ; V_80 < V_77 -> V_83 ; ++ V_80 )
F_14 ( V_10 , V_77 -> V_84 [ V_80 ] ) ;
return 0 ;
}
static void F_41 ( struct V_2 * V_4 ,
struct V_75 * V_18 )
{
struct V_76 * V_77 = V_18 -> V_77 . V_78 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < V_77 -> V_83 ; ++ V_80 )
F_18 ( V_10 , V_77 -> V_84 [ V_80 ] ) ;
}
static int F_42 ( struct V_2 * V_4 , unsigned long V_23 ,
T_3 V_85 , T_2 V_24 , int V_86 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( ! V_10 )
return - V_87 ;
return V_10 -> V_41 -> V_88 ( V_10 -> V_41 , V_23 , V_85 , V_24 , V_86 ) ;
}
static T_2 F_43 ( struct V_2 * V_4 , unsigned long V_23 ,
T_2 V_24 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_41 -> V_89 ( V_10 -> V_41 , V_23 , V_24 ) ;
}
static T_3 F_44 ( struct V_2 * V_4 ,
T_5 V_23 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_41 -> V_90 ( V_10 -> V_41 , V_23 ) ;
}
static int F_45 ( struct V_5 * V_6 , struct V_75 * V_18 ,
unsigned int * V_84 , unsigned int V_83 )
{
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < V_83 ; ++ V_80 ) {
struct V_91 args ;
int V_81 ;
V_81 = F_46 ( V_18 -> V_92 , L_7 ,
L_8 , V_80 , & args ) ;
if ( V_81 < 0 )
return V_81 ;
F_47 ( args . V_93 ) ;
if ( args . V_93 != V_6 -> V_18 -> V_92 || args . V_94 != 1 )
return - V_43 ;
V_84 [ V_80 ] = args . args [ 0 ] ;
}
return 0 ;
}
static int F_48 ( struct V_75 * V_18 )
{
struct V_76 * V_77 ;
struct V_5 * V_6 ;
struct V_95 * V_96 = NULL ;
unsigned int * V_84 ;
unsigned int V_80 ;
int V_83 ;
int V_81 = - V_87 ;
if ( V_18 -> V_77 . V_78 ) {
F_49 ( V_18 , L_9 ,
F_39 ( V_18 ) ) ;
return - V_43 ;
}
V_83 = F_50 ( V_18 -> V_92 , L_7 ,
L_8 ) ;
if ( V_83 < 0 )
return - V_87 ;
V_84 = F_51 ( V_83 , sizeof( * V_84 ) , V_73 ) ;
if ( ! V_84 )
return - V_97 ;
F_52 ( & V_98 ) ;
F_53 (mmu, &ipmmu_devices, list) {
V_81 = F_45 ( V_6 , V_18 , V_84 , V_83 ) ;
if ( ! V_81 ) {
break;
}
}
F_54 ( & V_98 ) ;
if ( V_81 < 0 )
return - V_87 ;
for ( V_80 = 0 ; V_80 < V_83 ; ++ V_80 ) {
if ( V_84 [ V_80 ] >= V_6 -> V_83 ) {
V_81 = - V_43 ;
goto error;
}
}
V_96 = F_55 () ;
if ( F_56 ( V_96 ) ) {
F_37 ( V_18 , L_10 ) ;
V_81 = F_57 ( V_96 ) ;
goto error;
}
V_81 = F_58 ( V_96 , V_18 ) ;
F_59 ( V_96 ) ;
if ( V_81 < 0 ) {
F_37 ( V_18 , L_11 ) ;
V_96 = NULL ;
goto error;
}
V_77 = F_31 ( sizeof( * V_77 ) , V_73 ) ;
if ( ! V_77 ) {
V_81 = - V_97 ;
goto error;
}
V_77 -> V_6 = V_6 ;
V_77 -> V_84 = V_84 ;
V_77 -> V_83 = V_83 ;
V_18 -> V_77 . V_78 = V_77 ;
if ( ! V_6 -> V_71 ) {
struct V_99 * V_71 ;
V_71 = F_60 ( & V_100 ,
V_34 , V_101 ) ;
if ( F_56 ( V_71 ) ) {
F_37 ( V_6 -> V_18 , L_12 ) ;
V_81 = F_57 ( V_71 ) ;
goto error;
}
V_6 -> V_71 = V_71 ;
}
V_81 = F_61 ( V_18 , V_6 -> V_71 ) ;
if ( V_81 < 0 ) {
F_37 ( V_18 , L_13 ) ;
goto error;
}
return 0 ;
error:
F_62 ( V_6 -> V_71 ) ;
F_35 ( V_18 -> V_77 . V_78 ) ;
F_35 ( V_84 ) ;
V_18 -> V_77 . V_78 = NULL ;
if ( ! F_63 ( V_96 ) )
F_64 ( V_18 ) ;
return V_81 ;
}
static void F_65 ( struct V_75 * V_18 )
{
struct V_76 * V_77 = V_18 -> V_77 . V_78 ;
F_66 ( V_18 ) ;
F_64 ( V_18 ) ;
F_35 ( V_77 -> V_84 ) ;
F_35 ( V_77 ) ;
V_18 -> V_77 . V_78 = NULL ;
}
static void F_67 ( struct V_5 * V_6 )
{
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < 4 ; ++ V_80 )
F_5 ( V_6 , V_80 * V_13 + V_15 , 0 ) ;
}
static int F_68 ( struct V_102 * V_103 )
{
struct V_5 * V_6 ;
struct V_104 * V_105 ;
int V_70 ;
int V_81 ;
if ( ! F_69 ( V_106 ) && ! V_103 -> V_18 . V_107 ) {
F_37 ( & V_103 -> V_18 , L_14 ) ;
return - V_43 ;
}
V_6 = F_70 ( & V_103 -> V_18 , sizeof( * V_6 ) , V_73 ) ;
if ( ! V_6 ) {
F_37 ( & V_103 -> V_18 , L_15 ) ;
return - V_97 ;
}
V_6 -> V_18 = & V_103 -> V_18 ;
V_6 -> V_83 = 32 ;
V_105 = F_71 ( V_103 , V_108 , 0 ) ;
V_6 -> V_8 = F_72 ( & V_103 -> V_18 , V_105 ) ;
if ( F_56 ( V_6 -> V_8 ) )
return F_57 ( V_6 -> V_8 ) ;
V_6 -> V_8 += V_109 ;
V_70 = F_73 ( V_103 , 0 ) ;
if ( V_70 < 0 ) {
F_37 ( & V_103 -> V_18 , L_16 ) ;
return V_70 ;
}
V_81 = F_74 ( & V_103 -> V_18 , V_70 , F_29 , 0 ,
F_39 ( & V_103 -> V_18 ) , V_6 ) ;
if ( V_81 < 0 ) {
F_37 ( & V_103 -> V_18 , L_17 , V_70 ) ;
return V_81 ;
}
F_67 ( V_6 ) ;
F_52 ( & V_98 ) ;
F_75 ( & V_6 -> V_110 , & V_111 ) ;
F_54 ( & V_98 ) ;
F_76 ( V_103 , V_6 ) ;
return 0 ;
}
static int F_77 ( struct V_102 * V_103 )
{
struct V_5 * V_6 = F_78 ( V_103 ) ;
F_52 ( & V_98 ) ;
F_79 ( & V_6 -> V_110 ) ;
F_54 ( & V_98 ) ;
F_62 ( V_6 -> V_71 ) ;
F_67 ( V_6 ) ;
return 0 ;
}
static int T_6 F_80 ( void )
{
int V_81 ;
V_81 = F_81 ( & V_112 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( ! F_82 ( & V_100 ) )
F_83 ( & V_100 , & V_113 ) ;
return 0 ;
}
static void T_7 F_84 ( void )
{
return F_85 ( & V_112 ) ;
}
