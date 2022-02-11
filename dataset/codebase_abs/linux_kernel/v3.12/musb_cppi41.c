static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
if ( V_2 -> V_5 )
return;
if ( ! F_2 ( V_2 -> V_6 -> V_7 ) )
return;
V_3 = F_3 ( V_2 -> V_8 -> V_9 , V_10 ) ;
V_4 = V_3 & V_11 ? 1 : 0 ;
V_2 -> V_12 = V_4 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
if ( V_2 -> V_5 )
return;
if ( ! F_2 ( V_2 -> V_6 -> V_7 ) )
return;
V_3 = F_3 ( V_2 -> V_8 -> V_9 , V_10 ) ;
V_4 = V_3 & V_11 ? 1 : 0 ;
if ( ! V_4 && V_4 == V_2 -> V_12 ) {
V_3 |= V_11 | V_13 ;
F_5 ( V_2 -> V_8 -> V_9 , V_10 , V_3 ) ;
F_6 ( V_2 -> V_6 -> V_7 -> V_6 ,
L_1 ) ;
}
V_2 -> V_12 = V_4 ;
}
static void F_7 ( void * V_14 )
{
struct V_15 * V_16 = V_14 ;
struct V_1 * V_2 = V_16 -> V_14 ;
struct V_17 * V_8 = V_2 -> V_8 ;
struct V_7 * V_7 = V_8 -> V_7 ;
unsigned long V_18 ;
struct V_19 V_20 ;
T_3 V_21 ;
F_8 ( & V_7 -> V_22 , V_18 ) ;
F_9 ( V_2 -> V_23 , V_2 -> V_24 ,
& V_20 ) ;
V_21 = V_2 -> V_25 - V_20 . V_26 ;
V_2 -> V_21 += V_21 ;
F_6 ( V_7 -> V_6 , L_2 ,
V_8 -> V_27 , V_2 -> V_21 ,
V_2 -> V_28 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_21 == V_2 -> V_28 ||
V_21 < V_2 -> V_29 ) {
V_2 -> V_16 . V_30 =
V_2 -> V_21 ;
V_2 -> V_16 . V_31 = V_32 ;
F_10 ( V_7 , V_8 -> V_27 , V_2 -> V_5 ) ;
} else {
struct V_33 * V_23 = V_2 -> V_23 ;
struct V_34 * V_35 ;
enum V_36 V_37 ;
T_1 V_3 ;
T_3 V_38 ;
void T_4 * V_39 = V_2 -> V_8 -> V_9 ;
V_2 -> V_40 += V_2 -> V_29 ;
V_38 = V_2 -> V_28 ;
V_38 -= V_2 -> V_21 ;
V_38 = F_11 ( V_38 , V_2 -> V_29 ) ;
V_2 -> V_25 = V_38 ;
V_37 = V_2 -> V_5 ? V_41
: V_42 ;
V_35 = F_12 ( V_23 ,
V_2 -> V_40 ,
V_38 ,
V_37 ,
V_43 | V_44 ) ;
if ( F_13 ( ! V_35 ) ) {
F_14 ( & V_7 -> V_22 , V_18 ) ;
return;
}
V_35 -> V_45 = F_7 ;
V_35 -> V_46 = V_16 ;
V_2 -> V_24 = V_35 -> V_47 ( V_35 ) ;
F_15 ( V_23 ) ;
if ( ! V_2 -> V_5 ) {
V_3 = F_3 ( V_39 , V_10 ) ;
V_3 |= V_48 ;
F_5 ( V_39 , V_10 , V_3 ) ;
}
}
F_14 ( & V_7 -> V_22 , V_18 ) ;
}
static T_3 F_16 ( unsigned V_49 , unsigned V_50 , T_3 V_51 )
{
unsigned V_52 ;
V_52 = ( V_49 - 1 ) * 2 ;
V_51 &= ~ ( 3 << V_52 ) ;
V_51 |= V_50 << V_52 ;
return V_51 ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned V_50 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
T_3 V_54 ;
T_3 V_55 ;
T_3 V_56 ;
if ( V_2 -> V_5 )
V_56 = V_6 -> V_57 ;
else
V_56 = V_6 -> V_58 ;
V_54 = V_2 -> V_59 ;
V_55 = F_16 ( V_54 , V_50 , V_56 ) ;
if ( V_55 == V_56 )
return;
if ( V_2 -> V_5 ) {
V_6 -> V_57 = V_55 ;
F_18 ( V_6 -> V_7 -> V_60 , V_61 ,
V_55 ) ;
} else {
V_6 -> V_58 = V_55 ;
F_18 ( V_6 -> V_7 -> V_60 , V_62 ,
V_55 ) ;
}
}
static void F_19 ( struct V_1 * V_2 ,
unsigned V_50 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
T_3 V_54 ;
T_3 V_55 ;
T_3 V_56 ;
V_56 = V_6 -> V_63 ;
V_54 = V_2 -> V_59 ;
V_55 = F_16 ( V_54 , V_50 , V_56 ) ;
if ( V_55 == V_56 )
return;
V_6 -> V_63 = V_55 ;
F_18 ( V_6 -> V_7 -> V_60 , V_64 , V_55 ) ;
}
static bool F_20 ( struct V_15 * V_16 ,
T_1 V_29 , T_2 V_50 ,
T_5 V_65 , T_3 V_66 )
{
struct V_1 * V_2 = V_16 -> V_14 ;
struct V_33 * V_23 = V_2 -> V_23 ;
struct V_34 * V_35 ;
enum V_36 V_37 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_7 ;
unsigned V_67 = 0 ;
F_6 ( V_7 -> V_6 ,
L_3 ,
V_2 -> V_59 , F_21 ( V_2 -> V_59 ) ,
V_29 , V_50 , ( unsigned long long ) V_65 ,
V_66 , V_2 -> V_5 ) ;
V_2 -> V_40 = V_65 ;
V_2 -> V_28 = V_66 ;
V_2 -> V_21 = 0 ;
V_2 -> V_29 = V_29 ;
if ( V_2 -> V_5 )
V_67 = 1 ;
if ( V_67 ) {
if ( V_66 > V_29 ) {
F_18 ( V_7 -> V_60 ,
F_21 ( V_2 -> V_59 ) , V_66 ) ;
F_17 ( V_2 ,
V_68 ) ;
F_19 ( V_2 ,
V_69 ) ;
} else {
F_18 ( V_7 -> V_60 ,
F_21 ( V_2 -> V_59 ) , 0 ) ;
F_17 ( V_2 ,
V_70 ) ;
F_19 ( V_2 ,
V_71 ) ;
}
} else {
F_17 ( V_2 , V_70 ) ;
F_19 ( V_2 , V_71 ) ;
V_66 = F_22 ( T_3 , V_29 , V_66 ) ;
}
V_2 -> V_25 = V_66 ;
V_37 = V_2 -> V_5 ? V_41 : V_42 ;
V_35 = F_12 ( V_23 , V_65 , V_66 , V_37 ,
V_43 | V_44 ) ;
if ( ! V_35 )
return false ;
V_35 -> V_45 = F_7 ;
V_35 -> V_46 = V_16 ;
V_2 -> V_24 = V_35 -> V_47 ( V_35 ) ;
F_1 ( V_2 ) ;
F_15 ( V_23 ) ;
return true ;
}
static struct V_15 * F_23 ( struct V_72 * V_73 ,
struct V_17 * V_8 , T_2 V_5 )
{
struct V_53 * V_6 = F_24 ( V_73 ,
struct V_53 , V_6 ) ;
struct V_1 * V_2 = NULL ;
T_2 V_74 = V_8 -> V_27 - 1 ;
if ( V_74 >= V_75 )
return NULL ;
if ( V_5 )
V_2 = & V_6 -> V_76 [ V_74 ] ;
else
V_2 = & V_6 -> V_77 [ V_74 ] ;
if ( ! V_2 -> V_23 )
return NULL ;
if ( V_2 -> V_78 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_78 = 1 ;
return & V_2 -> V_16 ;
}
static void F_25 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_14 ;
if ( V_2 -> V_78 ) {
V_2 -> V_78 = 0 ;
V_16 -> V_31 = V_32 ;
V_16 -> V_30 = 0 ;
}
}
static int F_26 ( struct V_15 * V_16 ,
T_1 V_29 , T_2 V_50 ,
T_5 V_65 , T_3 V_66 )
{
int V_79 ;
F_27 ( V_16 -> V_31 == V_80 ||
V_16 -> V_31 == V_81 ) ;
V_16 -> V_31 = V_81 ;
V_16 -> V_30 = 0 ;
V_79 = F_20 ( V_16 , V_29 , V_50 , V_65 , V_66 ) ;
if ( ! V_79 )
V_16 -> V_31 = V_32 ;
return V_79 ;
}
static int F_28 ( struct V_15 * V_16 , T_1 V_82 ,
void * V_83 , T_3 V_84 )
{
struct V_1 * V_2 = V_16 -> V_14 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
if ( F_2 ( V_7 ) ) {
F_13 ( 1 ) ;
return 1 ;
}
if ( V_2 -> V_5 )
return 1 ;
return 0 ;
}
static int F_29 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_14 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
void T_4 * V_39 = V_2 -> V_8 -> V_9 ;
int V_85 ;
int V_79 ;
unsigned V_5 ;
T_1 V_3 ;
V_5 = V_2 -> V_5 ;
F_6 ( V_7 -> V_6 , L_4 ,
V_2 -> V_59 , V_5 ) ;
if ( V_2 -> V_16 . V_31 == V_32 )
return 0 ;
if ( V_5 ) {
V_3 = F_3 ( V_39 , V_86 ) ;
V_3 &= ~ V_87 ;
F_5 ( V_39 , V_86 , V_3 ) ;
} else {
V_3 = F_3 ( V_39 , V_10 ) ;
V_3 &= ~ ( V_48 | V_88 ) ;
F_5 ( V_39 , V_10 , V_3 ) ;
V_3 = F_3 ( V_39 , V_10 ) ;
if ( V_3 & V_89 ) {
V_3 |= V_90 ;
F_5 ( V_39 , V_10 , V_3 ) ;
F_5 ( V_39 , V_10 , V_3 ) ;
}
}
V_85 = 1 << V_2 -> V_59 ;
if ( V_5 )
V_85 <<= 16 ;
do {
F_18 ( V_7 -> V_60 , V_91 , V_85 ) ;
V_79 = F_30 ( V_2 -> V_23 ) ;
} while ( V_79 == - V_92 );
F_18 ( V_7 -> V_60 , V_91 , V_85 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_39 , V_86 ) ;
if ( V_3 & V_93 ) {
V_3 |= V_94 ;
F_5 ( V_39 , V_86 , V_3 ) ;
}
}
V_2 -> V_16 . V_31 = V_32 ;
return 0 ;
}
static void F_31 ( struct V_53 * V_95 )
{
struct V_33 * V_23 ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_75 ; V_96 ++ ) {
V_23 = V_95 -> V_76 [ V_96 ] . V_23 ;
if ( V_23 )
F_32 ( V_23 ) ;
V_23 = V_95 -> V_77 [ V_96 ] . V_23 ;
if ( V_23 )
F_32 ( V_23 ) ;
}
}
static void F_33 ( struct V_53 * V_6 )
{
F_31 ( V_6 ) ;
}
static int F_34 ( struct V_53 * V_6 )
{
struct V_7 * V_7 = V_6 -> V_7 ;
struct V_97 * V_98 = V_7 -> V_6 ;
struct V_99 * V_100 = V_98 -> V_101 ;
struct V_1 * V_2 ;
int V_102 ;
int V_96 ;
int V_79 ;
V_102 = F_35 ( V_100 , L_5 ) ;
if ( V_102 < 0 )
return V_102 ;
for ( V_96 = 0 ; V_96 < V_102 ; V_96 ++ ) {
struct V_33 * V_23 ;
struct V_15 * V_103 ;
const char * V_104 ;
unsigned V_5 ;
unsigned int V_54 ;
V_79 = F_36 ( V_100 , L_5 , V_96 , & V_104 ) ;
if ( V_79 )
goto V_105;
if ( ! strncmp ( V_104 , L_6 , 2 ) )
V_5 = 1 ;
else if ( ! strncmp ( V_104 , L_7 , 2 ) )
V_5 = 0 ;
else {
F_37 ( V_98 , L_8 , V_104 ) ;
goto V_105;
}
V_79 = F_38 ( V_104 + 2 , 0 , & V_54 ) ;
if ( V_79 )
goto V_105;
if ( V_54 > V_75 || ! V_54 )
goto V_105;
if ( V_5 )
V_2 = & V_6 -> V_76 [ V_54 - 1 ] ;
else
V_2 = & V_6 -> V_77 [ V_54 - 1 ] ;
V_2 -> V_6 = V_6 ;
V_2 -> V_59 = V_54 ;
V_2 -> V_5 = V_5 ;
V_103 = & V_2 -> V_16 ;
V_103 -> V_14 = V_2 ;
V_103 -> V_31 = V_32 ;
V_103 -> V_106 = V_107 ;
V_23 = F_39 ( V_98 , V_104 ) ;
if ( ! V_23 ) {
F_37 ( V_98 , L_9 , V_104 ) ;
goto V_105;
}
V_2 -> V_23 = V_23 ;
}
return 0 ;
V_105:
F_31 ( V_6 ) ;
return - V_108 ;
}
void F_40 ( struct V_72 * V_73 )
{
struct V_53 * V_6 = F_24 ( V_73 ,
struct V_53 , V_6 ) ;
F_33 ( V_6 ) ;
F_41 ( V_6 ) ;
}
struct V_72 * F_42 ( struct V_7 * V_7 ,
void T_4 * V_109 )
{
struct V_53 * V_6 ;
int V_79 ;
if ( ! V_7 -> V_6 -> V_101 ) {
F_37 ( V_7 -> V_6 , L_10 ) ;
return NULL ;
}
V_6 = F_43 ( sizeof( * V_6 ) , V_110 ) ;
if ( ! V_6 )
goto V_111;
V_6 -> V_7 = V_7 ;
V_6 -> V_6 . V_112 = F_23 ;
V_6 -> V_6 . V_113 = F_25 ;
V_6 -> V_6 . V_114 = F_26 ;
V_6 -> V_6 . V_115 = F_29 ;
V_6 -> V_6 . V_116 = F_28 ;
V_79 = F_34 ( V_6 ) ;
if ( V_79 )
goto V_117;
return & V_6 -> V_6 ;
V_117:
F_41 ( V_6 ) ;
V_111:
return NULL ;
}
