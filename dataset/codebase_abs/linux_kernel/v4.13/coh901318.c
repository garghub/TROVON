static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 = V_4 ;
int V_6 = 0 ;
while ( V_5 ) {
F_2 ( F_3 ( V_2 ) , L_1
L_2 ,
V_6 , V_5 , V_5 -> V_7 , & V_5 -> V_8 , & V_5 -> V_9 ,
& V_5 -> V_10 , V_5 -> V_11 ) ;
V_6 ++ ;
V_5 = V_5 -> V_11 ;
}
}
static T_1 F_4 ( struct V_12 * V_12 , char T_2 * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
T_5 V_16 = V_17 -> V_18 . V_16 ;
int V_19 = V_17 -> V_20 . V_21 ;
char * V_22 ;
char * V_23 ;
int V_24 ;
int V_6 ;
V_22 = F_5 ( 4 * 1024 , V_25 ) ;
if ( V_22 == NULL )
return - V_26 ;
V_23 = V_22 ;
V_23 += sprintf ( V_23 , L_3 ) ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
if ( V_16 & ( 1ULL << V_6 ) )
V_23 += sprintf ( V_23 , L_4 , V_6 ) ;
}
V_23 += sprintf ( V_23 , L_5 , V_19 ) ;
V_24 = F_6 ( V_13 , V_14 , V_15 , V_22 ,
V_23 - V_22 ) ;
F_7 ( V_22 ) ;
return V_24 ;
}
static int T_6 F_8 ( void )
{
V_28 = F_9 ( L_6 , NULL ) ;
( void ) F_10 ( L_7 ,
V_29 | V_30 ,
V_28 , NULL ,
& V_31 ) ;
return 0 ;
}
static void T_7 F_11 ( void )
{
F_12 ( V_28 ) ;
}
static inline struct V_1 * F_13 ( struct V_32 * V_33 )
{
return F_14 ( V_33 , struct V_1 , V_33 ) ;
}
static inline const struct V_34 *
F_15 ( struct V_1 * V_2 )
{
return & V_35 [ V_2 -> V_36 ] . V_37 ;
}
static inline const struct V_38 *
F_16 ( struct V_1 * V_2 )
{
return & V_35 [ V_2 -> V_36 ] ;
}
static void F_17 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_40 * V_18 = & V_2 -> V_41 -> V_18 ;
F_18 ( & V_18 -> V_42 , V_39 ) ;
V_18 -> V_16 &= ~ ( 1ULL << V_2 -> V_36 ) ;
F_19 ( & V_18 -> V_42 , V_39 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_40 * V_18 = & V_2 -> V_41 -> V_18 ;
F_18 ( & V_18 -> V_42 , V_39 ) ;
V_18 -> V_16 |= ( 1ULL << V_2 -> V_36 ) ;
F_19 ( & V_18 -> V_42 , V_39 ) ;
}
static inline int F_21 ( struct V_1 * V_2 , T_8 V_7 )
{
int V_43 = V_2 -> V_36 ;
void T_9 * V_44 = V_2 -> V_41 -> V_44 ;
F_22 ( V_7 ,
V_44 + V_45 +
V_46 * V_43 ) ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_2 , T_8 V_47 )
{
int V_43 = V_2 -> V_36 ;
void T_9 * V_44 = V_2 -> V_41 -> V_44 ;
F_22 ( V_47 ,
V_44 + V_48 +
V_49 * V_43 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_8 V_50 ;
int V_43 = V_2 -> V_36 ;
void T_9 * V_44 = V_2 -> V_41 -> V_44 ;
F_20 ( V_2 ) ;
V_50 = F_25 ( V_44 + V_48 +
V_49 * V_43 ) ;
V_50 |= V_51 ;
F_22 ( V_50 , V_44 + V_48 +
V_49 * V_43 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_43 = V_2 -> V_36 ;
void T_9 * V_44 = V_2 -> V_41 -> V_44 ;
F_27 ( F_25 ( V_44 + V_52 +
V_53 * V_43 ) &
V_54 ) ;
F_22 ( V_4 -> V_8 ,
V_44 + V_55 +
V_56 * V_43 ) ;
F_22 ( V_4 -> V_9 , V_44 +
V_57 +
V_58 * V_43 ) ;
F_22 ( V_4 -> V_10 , V_44 + V_59 +
V_60 * V_43 ) ;
F_22 ( V_4 -> V_7 , V_44 + V_45 +
V_46 * V_43 ) ;
return 0 ;
}
static struct V_61 *
F_28 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
if ( F_29 ( & V_2 -> free ) ) {
V_62 = F_30 ( sizeof( struct V_61 ) , V_63 ) ;
if ( V_62 == NULL )
goto V_64;
F_31 ( & V_62 -> V_65 ) ;
F_32 ( & V_62 -> V_62 , & V_2 -> V_33 ) ;
} else {
V_62 = F_33 ( & V_2 -> free ,
struct V_61 ,
V_65 ) ;
F_34 ( & V_62 -> V_65 ) ;
V_62 -> V_66 = NULL ;
V_62 -> V_67 = 0 ;
V_62 -> V_62 . V_68 = NULL ;
V_62 -> V_62 . V_69 = NULL ;
}
V_64:
return V_62 ;
}
static void
F_35 ( struct V_1 * V_2 , struct V_61 * V_70 )
{
F_36 ( & V_70 -> V_65 , & V_2 -> free ) ;
}
static void
F_37 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
F_36 ( & V_62 -> V_65 , & V_2 -> V_71 ) ;
}
static struct V_61 *
F_38 ( struct V_1 * V_2 )
{
return F_39 ( & V_2 -> V_71 , struct V_61 ,
V_65 ) ;
}
static void
F_40 ( struct V_61 * V_70 )
{
F_34 ( & V_70 -> V_65 ) ;
}
static void
F_41 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
F_36 ( & V_62 -> V_65 , & V_2 -> V_72 ) ;
}
static struct V_61 *
F_42 ( struct V_1 * V_2 )
{
return F_39 ( & V_2 -> V_72 , struct V_61 ,
V_65 ) ;
}
static inline T_8 F_43 ( struct V_3 * V_73 )
{
struct V_3 * V_4 = V_73 ;
T_8 V_74 = 0 ;
while ( V_4 ) {
V_74 += V_4 -> V_7 & V_75 ;
V_4 = V_4 -> V_11 ;
}
return V_74 ;
}
static T_8 F_44 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_61 * V_70 ;
struct V_76 * V_77 ;
unsigned long V_39 ;
T_8 V_78 = 0 ;
int V_6 = 0 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
F_45 (pos, &cohc->active) {
V_70 = F_46 ( V_77 , struct V_61 , V_65 ) ;
if ( V_6 == 0 ) {
struct V_3 * V_4 ;
T_10 V_79 ;
V_78 = F_25 ( V_2 -> V_41 -> V_44 +
V_45 +
V_46 * V_2 -> V_36 ) &
V_75 ;
V_79 = F_25 ( V_2 -> V_41 -> V_44 +
V_59 +
V_60 *
V_2 -> V_36 ) &
~ V_80 ;
if ( ! V_79 )
continue;
V_4 = V_70 -> V_4 ;
while ( V_4 && V_4 -> V_10 != V_79 )
V_4 = V_4 -> V_11 ;
if ( V_4 )
V_4 = V_4 -> V_11 ;
V_78 += F_43 ( V_4 ) ;
} else {
V_78 += F_43 ( V_70 -> V_4 ) ;
}
V_6 ++ ;
}
F_45 (pos, &cohc->queue) {
V_70 = F_46 ( V_77 , struct V_61 , V_65 ) ;
V_78 += F_43 ( V_70 -> V_4 ) ;
}
F_19 ( & V_2 -> V_42 , V_39 ) ;
return V_78 ;
}
static int F_47 ( struct V_32 * V_33 )
{
T_8 V_50 ;
unsigned long V_39 ;
struct V_1 * V_2 = F_13 ( V_33 ) ;
int V_43 = V_2 -> V_36 ;
void T_9 * V_44 = V_2 -> V_41 -> V_44 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
V_50 = F_25 ( V_44 + V_48 +
V_49 * V_43 ) ;
if ( ( V_50 & V_81 ) == 0 &&
( V_50 & V_51 ) )
V_2 -> V_82 = 1 ;
V_50 &= ~ V_51 ;
F_22 ( V_50 , V_44 + V_48 +
V_49 * V_43 ) ;
F_22 ( V_50 , V_44 + V_48 +
V_49 * V_43 ) ;
while ( F_25 ( V_44 + V_52 + V_53 *
V_43 ) & V_54 )
F_48 () ;
if ( ( F_25 ( V_44 + V_45 + V_46 *
V_43 ) & V_75 ) > 0 )
V_2 -> V_82 = 1 ;
F_17 ( V_2 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 0 ;
}
static int F_49 ( struct V_32 * V_33 )
{
T_8 V_50 ;
unsigned long V_39 ;
struct V_1 * V_2 = F_13 ( V_33 ) ;
int V_43 = V_2 -> V_36 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_82 ) {
V_50 = F_25 ( V_2 -> V_41 -> V_44 + V_48 +
V_49 * V_43 ) ;
V_50 |= V_51 ;
F_22 ( V_50 , V_2 -> V_41 -> V_44 + V_48 +
V_49 * V_43 ) ;
V_2 -> V_82 = 0 ;
}
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 0 ;
}
bool F_50 ( struct V_32 * V_33 , void * V_83 )
{
unsigned long V_84 = ( unsigned long ) V_83 ;
if ( V_84 == F_13 ( V_33 ) -> V_36 )
return true ;
return false ;
}
static bool F_51 ( struct V_32 * V_33 , void * V_85 )
{
struct V_86 * args = V_85 ;
if ( & args -> V_41 -> V_87 == V_33 -> V_88 &&
args -> V_84 == F_13 ( V_33 ) -> V_36 )
return true ;
return false ;
}
static struct V_32 * F_52 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
struct V_86 args = {
. V_41 = V_92 -> V_93 ,
. V_84 = V_90 -> args [ 0 ] ,
} ;
T_11 V_94 ;
F_53 ( V_94 ) ;
F_54 ( V_95 , V_94 ) ;
return F_55 ( V_94 , F_51 , & args ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_34 * V_37 )
{
unsigned long V_39 ;
const struct V_34 * V_96 ;
int V_43 = V_2 -> V_36 ;
void T_9 * V_44 = V_2 -> V_41 -> V_44 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
if ( V_37 )
V_96 = V_37 ;
else
V_96 = F_15 ( V_2 ) ;
if ( V_43 < 32 ) {
F_22 ( 1 << V_43 , V_44 + V_97 ) ;
F_22 ( 1 << V_43 , V_44 + V_98 ) ;
} else {
F_22 ( 1 << ( V_43 - 32 ) , V_44 +
V_99 ) ;
F_22 ( 1 << ( V_43 - 32 ) , V_44 +
V_100 ) ;
}
F_23 ( V_2 , V_96 -> V_101 ) ;
F_21 ( V_2 , V_96 -> V_102 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 0 ;
}
static struct V_61 * F_57 ( struct V_1 * V_2 )
{
struct V_61 * V_70 ;
V_70 = F_42 ( V_2 ) ;
if ( V_70 != NULL ) {
F_40 ( V_70 ) ;
V_2 -> V_103 = 1 ;
F_37 ( V_2 , V_70 ) ;
F_23 ( V_2 , V_70 -> V_104 ) ;
F_21 ( V_2 , V_70 -> V_105 ) ;
F_26 ( V_2 , V_70 -> V_4 ) ;
F_24 ( V_2 ) ;
}
return V_70 ;
}
static void F_58 ( unsigned long V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_85 ;
struct V_61 * V_106 ;
unsigned long V_39 ;
struct V_107 V_108 ;
F_2 ( F_3 ( V_2 ) , L_8
L_9 , V_109 ,
V_2 -> V_36 , V_2 -> V_110 ) ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
V_106 = F_38 ( V_2 ) ;
if ( V_106 == NULL )
goto V_111;
F_59 ( & V_106 -> V_62 , & V_108 ) ;
F_60 ( & V_106 -> V_62 ) ;
F_61 ( & V_2 -> V_41 -> V_20 , & V_106 -> V_4 ) ;
F_40 ( V_106 ) ;
F_35 ( V_2 , V_106 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
F_62 ( & V_108 , NULL ) ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
V_2 -> V_110 -- ;
if ( V_2 -> V_110 ) {
F_63 ( F_3 ( V_2 ) , L_10
L_11 ) ;
if ( F_16 ( V_2 ) -> V_112 )
F_64 ( & V_2 -> V_113 ) ;
else
F_65 ( & V_2 -> V_113 ) ;
}
F_19 ( & V_2 -> V_42 , V_39 ) ;
return;
V_111:
F_19 ( & V_2 -> V_42 , V_39 ) ;
F_66 ( F_3 ( V_2 ) , L_12 , V_109 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_114 ) {
F_66 ( F_3 ( V_2 ) , L_13
L_14 ) ;
return;
}
F_68 ( & V_2 -> V_42 ) ;
F_27 ( F_29 ( & V_2 -> V_71 ) ) ;
V_2 -> V_110 ++ ;
if ( F_57 ( V_2 ) == NULL )
V_2 -> V_103 = 0 ;
F_69 ( & V_2 -> V_42 ) ;
if ( F_16 ( V_2 ) -> V_112 )
F_64 ( & V_2 -> V_113 ) ;
else
F_65 ( & V_2 -> V_113 ) ;
}
static T_12 F_70 ( int V_115 , void * V_116 )
{
T_8 V_117 ;
T_8 V_118 ;
int V_6 ;
int V_119 ;
struct V_120 * V_41 = V_116 ;
struct V_1 * V_2 ;
void T_9 * V_44 = V_41 -> V_44 ;
V_117 = F_25 ( V_44 + V_121 ) ;
V_118 = F_25 ( V_44 + V_122 ) ;
if ( F_71 ( V_117 == 0 && V_118 == 0 ) ) {
F_72 ( V_41 -> V_123 , L_15 ) ;
return V_124 ;
}
while ( V_117 ) {
V_6 = F_73 ( V_117 ) - 1 ;
V_119 = V_6 ;
V_2 = & V_41 -> V_125 [ V_119 ] ;
F_68 ( & V_2 -> V_42 ) ;
V_117 &= ~ ( 1 << V_6 ) ;
if ( F_74 ( V_6 , V_44 + V_126 ) ) {
F_75 ( F_3 ( V_2 ) ,
L_16 , V_119 ) ;
F_27 ( 1 ) ;
F_76 ( V_6 , V_44 + V_97 ) ;
} else {
if ( F_71 ( ! F_74 ( V_6 , V_44 +
V_127 ) ) ) {
F_72 ( F_3 ( V_2 ) ,
L_17 , V_119 ) ;
F_27 ( 1 ) ;
F_76 ( V_6 , V_44 + V_98 ) ;
} else {
if ( ! ( F_25 ( V_44 + V_52 +
V_53 * V_119 ) &
V_128 ) ) {
F_17 ( V_2 ) ;
}
F_76 ( V_6 , V_44 + V_98 ) ;
F_67 ( V_2 ) ;
}
}
F_69 ( & V_2 -> V_42 ) ;
}
while ( V_118 ) {
V_6 = F_73 ( V_118 ) - 1 ;
V_119 = V_6 + 32 ;
V_2 = & V_41 -> V_125 [ V_119 ] ;
F_68 ( & V_2 -> V_42 ) ;
V_118 &= ~ ( 1 << V_6 ) ;
if ( F_74 ( V_6 , V_44 + V_129 ) ) {
F_75 ( F_3 ( V_2 ) ,
L_16 , V_119 ) ;
F_27 ( 1 ) ;
F_76 ( V_6 , V_44 + V_99 ) ;
} else {
if ( F_71 ( ! F_74 ( V_6 , V_44 +
V_130 ) ) ) {
F_72 ( F_3 ( V_2 ) ,
L_17 , V_119 ) ;
F_76 ( V_6 , V_44 + V_100 ) ;
F_27 ( 1 ) ;
} else {
if ( ! ( F_25 ( V_44 + V_52 +
V_53 * V_119 ) &
V_128 ) ) {
F_17 ( V_2 ) ;
}
F_76 ( V_6 , V_44 + V_100 ) ;
F_67 ( V_2 ) ;
}
}
F_69 ( & V_2 -> V_42 ) ;
}
return V_124 ;
}
static int F_77 ( struct V_32 * V_33 )
{
unsigned long V_39 ;
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_61 * V_70 ;
void T_9 * V_44 = V_2 -> V_41 -> V_44 ;
F_47 ( V_33 ) ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
if ( V_2 -> V_36 < 32 ) {
F_22 ( 1 << V_2 -> V_36 , V_44 + V_97 ) ;
F_22 ( 1 << V_2 -> V_36 , V_44 + V_98 ) ;
} else {
F_22 ( 1 << ( V_2 -> V_36 - 32 ) , V_44 +
V_99 ) ;
F_22 ( 1 << ( V_2 -> V_36 - 32 ) , V_44 +
V_100 ) ;
}
F_17 ( V_2 ) ;
while ( ( V_70 = F_38 ( V_2 ) ) ) {
F_61 ( & V_2 -> V_41 -> V_20 , & V_70 -> V_4 ) ;
F_40 ( V_70 ) ;
F_35 ( V_2 , V_70 ) ;
}
while ( ( V_70 = F_42 ( V_2 ) ) ) {
F_61 ( & V_2 -> V_41 -> V_20 , & V_70 -> V_4 ) ;
F_40 ( V_70 ) ;
F_35 ( V_2 , V_70 ) ;
}
V_2 -> V_110 = 0 ;
V_2 -> V_103 = 0 ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 0 ;
}
static int F_78 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
unsigned long V_39 ;
F_2 ( F_3 ( V_2 ) , L_18 ,
V_109 , V_2 -> V_36 ) ;
if ( V_33 -> V_131 > 1 )
return - V_132 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
F_56 ( V_2 , NULL ) ;
V_2 -> V_114 = 1 ;
F_79 ( V_33 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 1 ;
}
static void
F_80 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
int V_43 = V_2 -> V_36 ;
unsigned long V_39 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
F_22 ( 0x00000000U , V_2 -> V_41 -> V_44 + V_48 +
V_49 * V_43 ) ;
F_22 ( 0x00000000U , V_2 -> V_41 -> V_44 + V_45 +
V_46 * V_43 ) ;
V_2 -> V_114 = 0 ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
F_77 ( V_33 ) ;
}
static T_13
F_81 ( struct V_133 * V_134 )
{
struct V_61 * V_70 = F_14 ( V_134 , struct V_61 ,
V_62 ) ;
struct V_1 * V_2 = F_13 ( V_134 -> V_33 ) ;
unsigned long V_39 ;
T_13 V_135 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
V_135 = F_82 ( V_134 ) ;
F_41 ( V_2 , V_70 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return V_135 ;
}
static struct V_133 *
F_83 ( struct V_32 * V_33 , T_10 V_136 , T_10 V_137 ,
T_3 V_138 , unsigned long V_39 )
{
struct V_3 * V_4 ;
struct V_61 * V_70 ;
unsigned long V_139 ;
struct V_1 * V_2 = F_13 ( V_33 ) ;
int V_140 ;
T_8 V_141 = F_15 ( V_2 ) -> V_102 ;
int V_24 ;
F_18 ( & V_2 -> V_42 , V_139 ) ;
F_2 ( F_3 ( V_2 ) ,
L_19 ,
V_109 , V_2 -> V_36 , & V_137 , & V_136 , V_138 ) ;
if ( V_39 & V_142 )
V_141 |= V_143 ;
V_140 = V_138 >> V_144 ;
if ( ( V_140 << V_144 ) < V_138 )
V_140 ++ ;
V_4 = F_84 ( & V_2 -> V_41 -> V_20 , V_140 ) ;
if ( V_4 == NULL )
goto V_111;
V_24 = F_85 (
& V_2 -> V_41 -> V_20 , V_4 , V_137 , V_138 , V_136 ,
F_15 ( V_2 ) -> V_145 ,
V_141 ) ;
if ( V_24 )
goto V_111;
F_86 ( F_1 ( V_2 , V_4 ) ) ;
V_70 = F_28 ( V_2 ) ;
V_70 -> V_4 = V_4 ;
V_70 -> V_39 = V_39 ;
V_70 -> V_62 . V_146 = F_81 ;
F_19 ( & V_2 -> V_42 , V_139 ) ;
return & V_70 -> V_62 ;
V_111:
F_19 ( & V_2 -> V_42 , V_139 ) ;
return NULL ;
}
static struct V_133 *
F_87 ( struct V_32 * V_33 , struct V_147 * V_148 ,
unsigned int V_67 , enum V_149 V_150 ,
unsigned long V_39 , void * V_151 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_3 * V_4 ;
struct V_61 * V_70 ;
const struct V_34 * V_152 ;
struct V_147 * V_66 ;
int V_153 = 0 ;
int V_138 ;
int V_6 ;
T_8 V_154 = F_15 ( V_2 ) -> V_145 ;
T_8 V_155 = F_15 ( V_2 ) -> V_156 ;
T_8 V_141 = F_15 ( V_2 ) -> V_102 ;
T_8 V_101 ;
unsigned long V_139 ;
int V_24 ;
if ( ! V_148 )
goto V_64;
if ( F_88 ( V_148 ) == 0 )
goto V_64;
F_18 ( & V_2 -> V_42 , V_139 ) ;
F_2 ( F_3 ( V_2 ) , L_20 ,
V_109 , V_67 , V_150 ) ;
if ( V_39 & V_142 )
V_141 |= V_143 ;
V_152 = F_15 ( V_2 ) ;
V_101 = V_152 -> V_101 ;
V_154 |= V_2 -> V_155 ;
V_141 |= V_2 -> V_155 ;
V_155 |= V_2 -> V_155 ;
if ( V_150 == V_157 ) {
T_8 V_158 = V_159 |
V_160 ;
V_101 |= V_161 ;
V_154 |= V_158 ;
V_141 |= V_158 ;
V_155 |= V_158 ;
} else if ( V_150 == V_162 ) {
T_8 V_163 = V_164 |
V_165 ;
V_101 |= V_166 ;
V_154 |= V_163 ;
V_141 |= V_163 ;
V_155 |= V_163 ;
} else
goto V_167;
F_89 (sgl, sg, sg_len, i) {
unsigned int V_168 ;
V_138 = F_88 ( V_66 ) ;
if ( V_138 <= V_169 ) {
V_153 ++ ;
continue;
}
V_168 = V_138 >> V_144 ;
if ( ( V_168 << V_144 ) < V_138 )
V_168 ++ ;
V_153 += V_168 ;
}
F_90 ( L_21 , V_153 ) ;
V_4 = F_84 ( & V_2 -> V_41 -> V_20 , V_153 ) ;
if ( V_4 == NULL )
goto V_170;
V_24 = F_91 ( & V_2 -> V_41 -> V_20 , V_4 , V_148 , V_67 ,
V_2 -> V_171 ,
V_154 ,
V_155 ,
V_141 ,
V_150 , V_143 ) ;
if ( V_24 )
goto V_172;
F_86 ( F_1 ( V_2 , V_4 ) ) ;
V_70 = F_28 ( V_2 ) ;
V_70 -> V_104 = V_101 ;
V_70 -> V_105 = V_4 -> V_7 ;
V_70 -> V_173 = V_150 ;
V_70 -> V_39 = V_39 ;
V_70 -> V_62 . V_146 = F_81 ;
V_70 -> V_4 = V_4 ;
F_19 ( & V_2 -> V_42 , V_139 ) ;
return & V_70 -> V_62 ;
V_172:
V_170:
V_167:
F_19 ( & V_2 -> V_42 , V_139 ) ;
V_64:
return NULL ;
}
static enum V_174
F_92 ( struct V_32 * V_33 , T_13 V_135 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
enum V_174 V_24 ;
V_24 = F_93 ( V_33 , V_135 , V_176 ) ;
if ( V_24 == V_177 || ! V_176 )
return V_24 ;
F_94 ( V_176 , F_44 ( V_33 ) ) ;
if ( V_24 == V_178 && V_2 -> V_82 )
V_24 = V_179 ;
return V_24 ;
}
static void
F_95 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
unsigned long V_39 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
if ( ! V_2 -> V_103 )
F_57 ( V_2 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
}
static int F_96 ( struct V_32 * V_33 ,
struct V_180 * V_101 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
T_10 V_171 ;
enum V_181 V_182 ;
T_8 V_183 ;
T_8 V_155 = 0 ;
int V_6 = 0 ;
if ( V_101 -> V_150 == V_162 ) {
V_171 = V_101 -> V_8 ;
V_182 = V_101 -> V_184 ;
V_183 = V_101 -> V_185 ;
} else if ( V_101 -> V_150 == V_157 ) {
V_171 = V_101 -> V_9 ;
V_182 = V_101 -> V_186 ;
V_183 = V_101 -> V_187 ;
} else {
F_66 ( F_3 ( V_2 ) , L_22 ) ;
return - V_188 ;
}
F_63 ( F_3 ( V_2 ) , L_23 ,
V_182 ) ;
switch ( V_182 ) {
case V_189 :
V_155 |=
V_190 |
V_191 ;
while ( V_6 < F_97 ( V_192 ) ) {
if ( V_192 [ V_6 ] . V_193 <= V_183 )
break;
V_6 ++ ;
}
break;
case V_194 :
V_155 |=
V_195 |
V_196 ;
while ( V_6 < F_97 ( V_192 ) ) {
if ( V_192 [ V_6 ] . V_197 <= V_183 )
break;
V_6 ++ ;
}
break;
case V_198 :
V_155 |=
V_199 |
V_200 ;
while ( V_6 < F_97 ( V_192 ) ) {
if ( V_192 [ V_6 ] . V_201 <= V_183 )
break;
V_6 ++ ;
}
break;
default:
F_66 ( F_3 ( V_2 ) ,
L_24 ) ;
return - V_188 ;
}
V_155 |= V_192 [ V_6 ] . V_202 ;
F_63 ( F_3 ( V_2 ) ,
L_25 ,
V_192 [ V_6 ] . V_193 , V_182 , V_183 ) ;
V_2 -> V_171 = V_171 ;
V_2 -> V_155 = V_155 ;
return 0 ;
}
static void F_98 ( struct V_203 * V_204 , const int * V_205 ,
struct V_120 * V_41 )
{
int V_206 ;
int V_6 = 0 ;
struct V_1 * V_2 ;
F_31 ( & V_204 -> V_207 ) ;
for ( V_206 = 0 ; V_205 [ V_206 ] != - 1 ; V_206 += 2 ) {
for ( V_6 = V_205 [ V_206 ] ; V_6 <= V_205 [ V_206 + 1 ] ; V_6 ++ ) {
V_2 = & V_41 -> V_125 [ V_6 ] ;
V_2 -> V_41 = V_41 ;
V_2 -> V_33 . V_88 = V_204 ;
V_2 -> V_36 = V_6 ;
F_99 ( & V_2 -> V_42 ) ;
V_2 -> V_110 = 0 ;
V_2 -> V_103 = 0 ;
F_31 ( & V_2 -> free ) ;
F_31 ( & V_2 -> V_71 ) ;
F_31 ( & V_2 -> V_72 ) ;
F_100 ( & V_2 -> V_113 , F_58 ,
( unsigned long ) V_2 ) ;
F_36 ( & V_2 -> V_33 . V_208 ,
& V_204 -> V_207 ) ;
}
}
}
static int T_6 F_101 ( struct V_209 * V_210 )
{
int V_111 = 0 ;
struct V_120 * V_41 ;
int V_115 ;
struct V_211 * V_212 ;
V_212 = F_102 ( V_210 , V_213 , 0 ) ;
if ( ! V_212 )
return - V_214 ;
if ( F_103 ( & V_210 -> V_123 ,
V_212 -> V_215 ,
F_104 ( V_212 ) ,
V_210 -> V_123 . V_216 -> V_217 ) == NULL )
return - V_26 ;
V_41 = F_105 ( & V_210 -> V_123 ,
F_106 ( sizeof( struct V_120 ) , 4 ) +
V_27 *
sizeof( struct V_1 ) ,
V_25 ) ;
if ( ! V_41 )
return - V_26 ;
V_41 -> V_125 = ( ( void * ) V_41 ) + F_106 ( sizeof( struct V_120 ) , 4 ) ;
V_41 -> V_44 = F_107 ( & V_210 -> V_123 , V_212 -> V_215 , F_104 ( V_212 ) ) ;
if ( ! V_41 -> V_44 )
return - V_26 ;
V_41 -> V_123 = & V_210 -> V_123 ;
F_99 ( & V_41 -> V_18 . V_42 ) ;
V_41 -> V_18 . V_16 = 0 ;
F_108 ( V_17 , V_41 ) ;
V_115 = F_109 ( V_210 , 0 ) ;
if ( V_115 < 0 )
return V_115 ;
V_111 = F_110 ( & V_210 -> V_123 , V_115 , F_70 , 0 ,
L_26 , V_41 ) ;
if ( V_111 )
return V_111 ;
V_41 -> V_115 = V_115 ;
V_111 = F_111 ( & V_41 -> V_20 , & V_210 -> V_123 ,
sizeof( struct V_3 ) ,
32 ) ;
if ( V_111 )
return V_111 ;
F_98 ( & V_41 -> V_87 , V_218 ,
V_41 ) ;
F_53 ( V_41 -> V_87 . V_219 ) ;
F_54 ( V_95 , V_41 -> V_87 . V_219 ) ;
V_41 -> V_87 . V_220 = F_78 ;
V_41 -> V_87 . V_221 = F_80 ;
V_41 -> V_87 . V_222 = F_87 ;
V_41 -> V_87 . V_223 = F_92 ;
V_41 -> V_87 . V_224 = F_95 ;
V_41 -> V_87 . V_225 = F_96 ;
V_41 -> V_87 . V_226 = F_47 ;
V_41 -> V_87 . V_227 = F_49 ;
V_41 -> V_87 . V_228 = F_77 ;
V_41 -> V_87 . V_123 = & V_210 -> V_123 ;
V_111 = F_112 ( & V_41 -> V_87 ) ;
if ( V_111 )
goto V_229;
F_98 ( & V_41 -> V_230 , V_231 ,
V_41 ) ;
F_53 ( V_41 -> V_230 . V_219 ) ;
F_54 ( V_232 , V_41 -> V_230 . V_219 ) ;
V_41 -> V_230 . V_220 = F_78 ;
V_41 -> V_230 . V_221 = F_80 ;
V_41 -> V_230 . V_233 = F_83 ;
V_41 -> V_230 . V_223 = F_92 ;
V_41 -> V_230 . V_224 = F_95 ;
V_41 -> V_230 . V_225 = F_96 ;
V_41 -> V_230 . V_226 = F_47 ;
V_41 -> V_230 . V_227 = F_49 ;
V_41 -> V_230 . V_228 = F_77 ;
V_41 -> V_230 . V_123 = & V_210 -> V_123 ;
V_41 -> V_230 . V_234 = V_235 ;
V_111 = F_112 ( & V_41 -> V_230 ) ;
if ( V_111 )
goto V_236;
V_111 = F_113 ( V_210 -> V_123 . V_237 , F_52 ,
V_41 ) ;
if ( V_111 )
goto V_238;
F_114 ( V_210 , V_41 ) ;
F_115 ( & V_210 -> V_123 , L_27 ,
V_41 -> V_44 ) ;
return V_111 ;
V_238:
F_116 ( & V_41 -> V_230 ) ;
V_236:
F_116 ( & V_41 -> V_87 ) ;
V_229:
F_117 ( & V_41 -> V_20 ) ;
return V_111 ;
}
static void F_118 ( struct V_120 * V_41 , const int * V_205 )
{
int V_206 ;
int V_6 = 0 ;
struct V_1 * V_2 ;
for ( V_206 = 0 ; V_205 [ V_206 ] != - 1 ; V_206 += 2 ) {
for ( V_6 = V_205 [ V_206 ] ; V_6 <= V_205 [ V_206 + 1 ] ; V_6 ++ ) {
V_2 = & V_41 -> V_125 [ V_6 ] ;
F_119 ( & V_2 -> V_113 ) ;
}
}
}
static int F_120 ( struct V_209 * V_210 )
{
struct V_120 * V_41 = F_121 ( V_210 ) ;
F_122 ( & V_210 -> V_123 , V_41 -> V_115 , V_41 ) ;
F_118 ( V_41 , V_218 ) ;
F_118 ( V_41 , V_231 ) ;
F_123 ( V_210 -> V_123 . V_237 ) ;
F_116 ( & V_41 -> V_230 ) ;
F_116 ( & V_41 -> V_87 ) ;
F_117 ( & V_41 -> V_20 ) ;
return 0 ;
}
static int T_6 F_124 ( void )
{
return F_125 ( & V_239 , F_101 ) ;
}
static void T_7 F_126 ( void )
{
F_127 ( & V_239 ) ;
}
