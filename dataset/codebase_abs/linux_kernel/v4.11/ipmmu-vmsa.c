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
V_10 -> V_4 . V_39 . V_40 = F_22 ( 32 ) ;
V_10 -> V_4 . V_39 . V_41 = true ;
V_10 -> V_28 . V_42 = V_10 -> V_6 -> V_18 ;
V_10 -> V_43 = F_23 ( V_44 , & V_10 -> V_28 ,
V_10 ) ;
if ( ! V_10 -> V_43 )
return - V_45 ;
V_10 -> V_12 = 0 ;
V_27 = V_10 -> V_28 . V_46 . V_27 [ 0 ] ;
F_8 ( V_10 , V_47 , V_27 ) ;
F_8 ( V_10 , V_48 , V_27 >> 32 ) ;
F_8 ( V_10 , V_49 , V_50 |
V_51 | V_52 |
V_53 | V_54 ) ;
F_8 ( V_10 , V_55 , V_10 -> V_28 . V_46 . V_56 [ 0 ] ) ;
F_8 ( V_10 , V_57 ,
F_7 ( V_10 , V_57 ) &
~ ( V_58 | V_59 ) ) ;
F_8 ( V_10 , V_60 , F_7 ( V_10 , V_60 ) ) ;
F_8 ( V_10 , V_15 , V_61 | V_16 | V_62 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_10 )
{
F_8 ( V_10 , V_15 , V_16 ) ;
F_9 ( V_10 ) ;
}
static T_4 F_25 ( struct V_1 * V_10 )
{
const T_1 V_63 = V_64 | V_65 | V_66 | V_67 ;
struct V_5 * V_6 = V_10 -> V_6 ;
T_1 V_68 ;
T_1 V_23 ;
V_68 = F_7 ( V_10 , V_60 ) ;
if ( ! ( V_68 & V_63 ) )
return V_69 ;
V_23 = F_7 ( V_10 , V_70 ) ;
F_8 ( V_10 , V_60 , 0 ) ;
if ( V_68 & V_64 )
F_11 ( V_6 -> V_18 , L_2 ,
V_23 ) ;
if ( V_68 & V_65 )
F_11 ( V_6 -> V_18 , L_3 ,
V_23 ) ;
if ( ! ( V_68 & ( V_66 | V_67 ) ) )
return V_69 ;
if ( ! F_26 ( & V_10 -> V_4 , V_6 -> V_18 , V_23 , 0 ) )
return V_71 ;
F_11 ( V_6 -> V_18 ,
L_4 ,
V_68 , V_23 ) ;
return V_71 ;
}
static T_4 F_27 ( int V_72 , void * V_18 )
{
struct V_5 * V_6 = V_18 ;
struct V_2 * V_4 ;
struct V_1 * V_10 ;
if ( ! V_6 -> V_73 )
return V_69 ;
V_4 = V_6 -> V_73 -> V_10 ;
V_10 = F_1 ( V_4 ) ;
return F_25 ( V_10 ) ;
}
static struct V_2 * F_28 ( unsigned type )
{
struct V_1 * V_10 ;
if ( type != V_74 )
return NULL ;
V_10 = F_29 ( sizeof( * V_10 ) , V_75 ) ;
if ( ! V_10 )
return NULL ;
F_30 ( & V_10 -> V_76 ) ;
return & V_10 -> V_4 ;
}
static void F_31 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_24 ( V_10 ) ;
F_32 ( V_10 -> V_43 ) ;
F_33 ( V_10 ) ;
}
static int F_34 ( struct V_2 * V_4 ,
struct V_77 * V_18 )
{
struct V_78 * V_79 = V_18 -> V_79 . V_80 ;
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_81 ;
unsigned int V_82 ;
int V_83 = 0 ;
if ( ! V_6 ) {
F_35 ( V_18 , L_5 ) ;
return - V_84 ;
}
F_36 ( & V_10 -> V_76 , V_81 ) ;
if ( ! V_10 -> V_6 ) {
V_10 -> V_6 = V_6 ;
V_83 = F_21 ( V_10 ) ;
} else if ( V_10 -> V_6 != V_6 ) {
F_35 ( V_18 , L_6 ,
F_37 ( V_6 -> V_18 ) , F_37 ( V_10 -> V_6 -> V_18 ) ) ;
V_83 = - V_45 ;
}
F_38 ( & V_10 -> V_76 , V_81 ) ;
if ( V_83 < 0 )
return V_83 ;
for ( V_82 = 0 ; V_82 < V_79 -> V_85 ; ++ V_82 )
F_14 ( V_10 , V_79 -> V_86 [ V_82 ] ) ;
return 0 ;
}
static void F_39 ( struct V_2 * V_4 ,
struct V_77 * V_18 )
{
struct V_78 * V_79 = V_18 -> V_79 . V_80 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < V_79 -> V_85 ; ++ V_82 )
F_18 ( V_10 , V_79 -> V_86 [ V_82 ] ) ;
}
static int F_40 ( struct V_2 * V_4 , unsigned long V_23 ,
T_5 V_87 , T_2 V_24 , int V_88 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( ! V_10 )
return - V_89 ;
return V_10 -> V_43 -> V_90 ( V_10 -> V_43 , V_23 , V_87 , V_24 , V_88 ) ;
}
static T_2 F_41 ( struct V_2 * V_4 , unsigned long V_23 ,
T_2 V_24 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_43 -> V_91 ( V_10 -> V_43 , V_23 , V_24 ) ;
}
static T_5 F_42 ( struct V_2 * V_4 ,
T_6 V_23 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_43 -> V_92 ( V_10 -> V_43 , V_23 ) ;
}
static int F_43 ( struct V_5 * V_6 , struct V_77 * V_18 ,
unsigned int * V_86 , unsigned int V_85 )
{
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < V_85 ; ++ V_82 ) {
struct V_93 args ;
int V_83 ;
V_83 = F_44 ( V_18 -> V_94 , L_7 ,
L_8 , V_82 , & args ) ;
if ( V_83 < 0 )
return V_83 ;
F_45 ( args . V_95 ) ;
if ( args . V_95 != V_6 -> V_18 -> V_94 || args . V_96 != 1 )
return - V_45 ;
V_86 [ V_82 ] = args . args [ 0 ] ;
}
return 0 ;
}
static int F_46 ( struct V_77 * V_18 )
{
struct V_78 * V_79 ;
struct V_5 * V_6 ;
struct V_97 * V_98 = NULL ;
unsigned int * V_86 ;
unsigned int V_82 ;
int V_85 ;
int V_83 = - V_89 ;
if ( V_18 -> V_79 . V_80 ) {
F_47 ( V_18 , L_9 ,
F_37 ( V_18 ) ) ;
return - V_45 ;
}
V_85 = F_48 ( V_18 -> V_94 , L_7 ,
L_8 ) ;
if ( V_85 < 0 )
return - V_89 ;
V_86 = F_49 ( V_85 , sizeof( * V_86 ) , V_75 ) ;
if ( ! V_86 )
return - V_99 ;
F_50 ( & V_100 ) ;
F_51 (mmu, &ipmmu_devices, list) {
V_83 = F_43 ( V_6 , V_18 , V_86 , V_85 ) ;
if ( ! V_83 ) {
break;
}
}
F_52 ( & V_100 ) ;
if ( V_83 < 0 )
goto error;
for ( V_82 = 0 ; V_82 < V_85 ; ++ V_82 ) {
if ( V_86 [ V_82 ] >= V_6 -> V_85 ) {
V_83 = - V_45 ;
goto error;
}
}
V_98 = F_53 () ;
if ( F_54 ( V_98 ) ) {
F_35 ( V_18 , L_10 ) ;
V_83 = F_55 ( V_98 ) ;
goto error;
}
V_83 = F_56 ( V_98 , V_18 ) ;
F_57 ( V_98 ) ;
if ( V_83 < 0 ) {
F_35 ( V_18 , L_11 ) ;
V_98 = NULL ;
goto error;
}
V_79 = F_29 ( sizeof( * V_79 ) , V_75 ) ;
if ( ! V_79 ) {
V_83 = - V_99 ;
goto error;
}
V_79 -> V_6 = V_6 ;
V_79 -> V_86 = V_86 ;
V_79 -> V_85 = V_85 ;
V_18 -> V_79 . V_80 = V_79 ;
if ( ! V_6 -> V_73 ) {
struct V_101 * V_73 ;
V_73 = F_58 ( & V_102 ,
V_32 , V_103 ) ;
if ( F_54 ( V_73 ) ) {
F_35 ( V_6 -> V_18 , L_12 ) ;
V_83 = F_55 ( V_73 ) ;
goto error;
}
V_6 -> V_73 = V_73 ;
}
V_83 = F_59 ( V_18 , V_6 -> V_73 ) ;
if ( V_83 < 0 ) {
F_35 ( V_18 , L_13 ) ;
goto error;
}
return 0 ;
error:
F_60 ( V_6 -> V_73 ) ;
F_33 ( V_18 -> V_79 . V_80 ) ;
F_33 ( V_86 ) ;
V_18 -> V_79 . V_80 = NULL ;
if ( ! F_61 ( V_98 ) )
F_62 ( V_18 ) ;
return V_83 ;
}
static void F_63 ( struct V_77 * V_18 )
{
struct V_78 * V_79 = V_18 -> V_79 . V_80 ;
F_64 ( V_18 ) ;
F_62 ( V_18 ) ;
F_33 ( V_79 -> V_86 ) ;
F_33 ( V_79 ) ;
V_18 -> V_79 . V_80 = NULL ;
}
static void F_65 ( struct V_5 * V_6 )
{
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < 4 ; ++ V_82 )
F_5 ( V_6 , V_82 * V_13 + V_15 , 0 ) ;
}
static int F_66 ( struct V_104 * V_105 )
{
struct V_5 * V_6 ;
struct V_106 * V_107 ;
int V_72 ;
int V_83 ;
if ( ! F_67 ( V_108 ) && ! V_105 -> V_18 . V_109 ) {
F_35 ( & V_105 -> V_18 , L_14 ) ;
return - V_45 ;
}
V_6 = F_68 ( & V_105 -> V_18 , sizeof( * V_6 ) , V_75 ) ;
if ( ! V_6 ) {
F_35 ( & V_105 -> V_18 , L_15 ) ;
return - V_99 ;
}
V_6 -> V_18 = & V_105 -> V_18 ;
V_6 -> V_85 = 32 ;
V_107 = F_69 ( V_105 , V_110 , 0 ) ;
V_6 -> V_8 = F_70 ( & V_105 -> V_18 , V_107 ) ;
if ( F_54 ( V_6 -> V_8 ) )
return F_55 ( V_6 -> V_8 ) ;
V_6 -> V_8 += V_111 ;
V_72 = F_71 ( V_105 , 0 ) ;
if ( V_72 < 0 ) {
F_35 ( & V_105 -> V_18 , L_16 ) ;
return V_72 ;
}
V_83 = F_72 ( & V_105 -> V_18 , V_72 , F_27 , 0 ,
F_37 ( & V_105 -> V_18 ) , V_6 ) ;
if ( V_83 < 0 ) {
F_35 ( & V_105 -> V_18 , L_17 , V_72 ) ;
return V_83 ;
}
F_65 ( V_6 ) ;
F_50 ( & V_100 ) ;
F_73 ( & V_6 -> V_112 , & V_113 ) ;
F_52 ( & V_100 ) ;
F_74 ( V_105 , V_6 ) ;
return 0 ;
}
static int F_75 ( struct V_104 * V_105 )
{
struct V_5 * V_6 = F_76 ( V_105 ) ;
F_50 ( & V_100 ) ;
F_77 ( & V_6 -> V_112 ) ;
F_52 ( & V_100 ) ;
F_60 ( V_6 -> V_73 ) ;
F_65 ( V_6 ) ;
return 0 ;
}
static int T_7 F_78 ( void )
{
int V_83 ;
V_83 = F_79 ( & V_114 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( ! F_80 ( & V_102 ) )
F_81 ( & V_102 , & V_115 ) ;
return 0 ;
}
static void T_8 F_82 ( void )
{
return F_83 ( & V_114 ) ;
}
