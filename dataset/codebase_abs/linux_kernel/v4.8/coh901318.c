static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 = V_4 ;
int V_6 = 0 ;
while ( V_5 ) {
F_2 ( F_3 ( V_2 ) , L_1
L_2 ,
V_6 , V_5 , V_5 -> V_7 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , V_5 -> V_11 ) ;
V_6 ++ ;
V_5 = V_5 -> V_11 ;
}
}
static int F_4 ( struct V_12 * V_12 , char T_1 * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
T_4 V_16 = V_17 -> V_18 . V_16 ;
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
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
if ( V_16 & ( 1 << V_6 ) )
V_23 += sprintf ( V_23 , L_4 , V_6 ) ;
V_23 += sprintf ( V_23 , L_5 , V_19 ) ;
V_24 = F_6 ( V_13 , V_14 , V_15 , V_22 ,
V_23 - V_22 ) ;
F_7 ( V_22 ) ;
return V_24 ;
}
static int T_5 F_8 ( void )
{
V_28 = F_9 ( L_6 , NULL ) ;
( void ) F_10 ( L_7 ,
V_29 | V_30 ,
V_28 , NULL ,
& V_31 ) ;
return 0 ;
}
static void T_6 F_11 ( void )
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
static inline int F_21 ( struct V_1 * V_2 , T_7 V_7 )
{
int V_43 = V_2 -> V_36 ;
void T_8 * V_44 = V_2 -> V_41 -> V_44 ;
F_22 ( V_7 ,
V_44 + V_45 +
V_46 * V_43 ) ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_2 , T_7 V_47 )
{
int V_43 = V_2 -> V_36 ;
void T_8 * V_44 = V_2 -> V_41 -> V_44 ;
F_22 ( V_47 ,
V_44 + V_48 +
V_49 * V_43 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_7 V_50 ;
int V_43 = V_2 -> V_36 ;
void T_8 * V_44 = V_2 -> V_41 -> V_44 ;
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
void T_8 * V_44 = V_2 -> V_41 -> V_44 ;
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
struct V_61 * V_72 ;
if ( F_29 ( & V_2 -> V_71 ) )
return NULL ;
V_72 = F_33 ( & V_2 -> V_71 ,
struct V_61 ,
V_65 ) ;
return V_72 ;
}
static void
F_39 ( struct V_61 * V_70 )
{
F_34 ( & V_70 -> V_65 ) ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
F_36 ( & V_62 -> V_65 , & V_2 -> V_73 ) ;
}
static struct V_61 *
F_41 ( struct V_1 * V_2 )
{
struct V_61 * V_72 ;
if ( F_29 ( & V_2 -> V_73 ) )
return NULL ;
V_72 = F_33 ( & V_2 -> V_73 ,
struct V_61 ,
V_65 ) ;
return V_72 ;
}
static inline T_7 F_42 ( struct V_3 * V_74 )
{
struct V_3 * V_4 = V_74 ;
T_7 V_75 = 0 ;
while ( V_4 ) {
V_75 += V_4 -> V_7 & V_76 ;
V_4 = V_4 -> V_11 ;
}
return V_75 ;
}
static T_7 F_43 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_61 * V_70 ;
struct V_77 * V_78 ;
unsigned long V_39 ;
T_7 V_79 = 0 ;
int V_6 = 0 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
F_44 (pos, &cohc->active) {
V_70 = F_45 ( V_78 , struct V_61 , V_65 ) ;
if ( V_6 == 0 ) {
struct V_3 * V_4 ;
T_9 V_80 ;
V_79 = F_25 ( V_2 -> V_41 -> V_44 +
V_45 +
V_46 * V_2 -> V_36 ) &
V_76 ;
V_80 = F_25 ( V_2 -> V_41 -> V_44 +
V_59 +
V_60 *
V_2 -> V_36 ) &
~ V_81 ;
if ( ! V_80 )
continue;
V_4 = V_70 -> V_4 ;
while ( V_4 && V_4 -> V_10 != V_80 )
V_4 = V_4 -> V_11 ;
if ( V_4 )
V_4 = V_4 -> V_11 ;
V_79 += F_42 ( V_4 ) ;
} else {
V_79 += F_42 ( V_70 -> V_4 ) ;
}
V_6 ++ ;
}
F_44 (pos, &cohc->queue) {
V_70 = F_45 ( V_78 , struct V_61 , V_65 ) ;
V_79 += F_42 ( V_70 -> V_4 ) ;
}
F_19 ( & V_2 -> V_42 , V_39 ) ;
return V_79 ;
}
static int F_46 ( struct V_32 * V_33 )
{
T_7 V_50 ;
unsigned long V_39 ;
struct V_1 * V_2 = F_13 ( V_33 ) ;
int V_43 = V_2 -> V_36 ;
void T_8 * V_44 = V_2 -> V_41 -> V_44 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
V_50 = F_25 ( V_44 + V_48 +
V_49 * V_43 ) ;
if ( ( V_50 & V_82 ) == 0 &&
( V_50 & V_51 ) )
V_2 -> V_83 = 1 ;
V_50 &= ~ V_51 ;
F_22 ( V_50 , V_44 + V_48 +
V_49 * V_43 ) ;
F_22 ( V_50 , V_44 + V_48 +
V_49 * V_43 ) ;
while ( F_25 ( V_44 + V_52 + V_53 *
V_43 ) & V_54 )
F_47 () ;
if ( ( F_25 ( V_44 + V_45 + V_46 *
V_43 ) & V_76 ) > 0 )
V_2 -> V_83 = 1 ;
F_17 ( V_2 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 0 ;
}
static int F_48 ( struct V_32 * V_33 )
{
T_7 V_50 ;
unsigned long V_39 ;
struct V_1 * V_2 = F_13 ( V_33 ) ;
int V_43 = V_2 -> V_36 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_83 ) {
V_50 = F_25 ( V_2 -> V_41 -> V_44 + V_48 +
V_49 * V_43 ) ;
V_50 |= V_51 ;
F_22 ( V_50 , V_2 -> V_41 -> V_44 + V_48 +
V_49 * V_43 ) ;
V_2 -> V_83 = 0 ;
}
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 0 ;
}
bool F_49 ( struct V_32 * V_33 , void * V_84 )
{
unsigned int V_85 = ( unsigned int ) V_84 ;
if ( V_85 == F_13 ( V_33 ) -> V_36 )
return true ;
return false ;
}
static bool F_50 ( struct V_32 * V_33 , void * V_86 )
{
struct V_87 * args = V_86 ;
if ( & args -> V_41 -> V_88 == V_33 -> V_89 &&
args -> V_85 == F_13 ( V_33 ) -> V_36 )
return true ;
return false ;
}
static struct V_32 * F_51 ( struct V_90 * V_91 ,
struct V_92 * V_93 )
{
struct V_87 args = {
. V_41 = V_93 -> V_94 ,
. V_85 = V_91 -> args [ 0 ] ,
} ;
T_10 V_95 ;
F_52 ( V_95 ) ;
F_53 ( V_96 , V_95 ) ;
return F_54 ( V_95 , F_50 , & args ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_34 * V_37 )
{
unsigned long V_39 ;
const struct V_34 * V_97 ;
int V_43 = V_2 -> V_36 ;
void T_8 * V_44 = V_2 -> V_41 -> V_44 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
if ( V_37 )
V_97 = V_37 ;
else
V_97 = F_15 ( V_2 ) ;
if ( V_43 < 32 ) {
F_22 ( 1 << V_43 , V_44 + V_98 ) ;
F_22 ( 1 << V_43 , V_44 + V_99 ) ;
} else {
F_22 ( 1 << ( V_43 - 32 ) , V_44 +
V_100 ) ;
F_22 ( 1 << ( V_43 - 32 ) , V_44 +
V_101 ) ;
}
F_23 ( V_2 , V_97 -> V_102 ) ;
F_21 ( V_2 , V_97 -> V_103 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 0 ;
}
static struct V_61 * F_56 ( struct V_1 * V_2 )
{
struct V_61 * V_70 ;
V_70 = F_41 ( V_2 ) ;
if ( V_70 != NULL ) {
F_39 ( V_70 ) ;
V_2 -> V_104 = 1 ;
F_37 ( V_2 , V_70 ) ;
F_23 ( V_2 , V_70 -> V_105 ) ;
F_21 ( V_2 , V_70 -> V_106 ) ;
F_26 ( V_2 , V_70 -> V_4 ) ;
F_24 ( V_2 ) ;
}
return V_70 ;
}
static void F_57 ( unsigned long V_86 )
{
struct V_1 * V_2 = (struct V_1 * ) V_86 ;
struct V_61 * V_107 ;
unsigned long V_39 ;
T_11 V_68 ;
void * V_69 ;
F_2 ( F_3 ( V_2 ) , L_8
L_9 , V_108 ,
V_2 -> V_36 , V_2 -> V_109 ) ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
V_107 = F_38 ( V_2 ) ;
if ( V_107 == NULL )
goto V_110;
V_68 = V_107 -> V_62 . V_68 ;
V_69 = V_107 -> V_62 . V_69 ;
F_58 ( & V_107 -> V_62 ) ;
F_59 ( & V_2 -> V_41 -> V_20 , & V_107 -> V_4 ) ;
F_39 ( V_107 ) ;
F_35 ( V_2 , V_107 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
if ( V_68 )
V_68 ( V_69 ) ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
V_2 -> V_109 -- ;
if ( V_2 -> V_109 ) {
F_60 ( F_3 ( V_2 ) , L_10
L_11 ) ;
if ( F_16 ( V_2 ) -> V_111 )
F_61 ( & V_2 -> V_112 ) ;
else
F_62 ( & V_2 -> V_112 ) ;
}
F_19 ( & V_2 -> V_42 , V_39 ) ;
return;
V_110:
F_19 ( & V_2 -> V_42 , V_39 ) ;
F_63 ( F_3 ( V_2 ) , L_12 , V_108 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_113 ) {
F_63 ( F_3 ( V_2 ) , L_13
L_14 ) ;
return;
}
F_65 ( & V_2 -> V_42 ) ;
F_27 ( F_29 ( & V_2 -> V_71 ) ) ;
V_2 -> V_109 ++ ;
if ( F_56 ( V_2 ) == NULL )
V_2 -> V_104 = 0 ;
F_66 ( & V_2 -> V_42 ) ;
if ( F_16 ( V_2 ) -> V_111 )
F_61 ( & V_2 -> V_112 ) ;
else
F_62 ( & V_2 -> V_112 ) ;
}
static T_12 F_67 ( int V_114 , void * V_115 )
{
T_7 V_116 ;
T_7 V_117 ;
int V_6 ;
int V_118 ;
struct V_119 * V_41 = V_115 ;
struct V_1 * V_2 ;
void T_8 * V_44 = V_41 -> V_44 ;
V_116 = F_25 ( V_44 + V_120 ) ;
V_117 = F_25 ( V_44 + V_121 ) ;
if ( F_68 ( V_116 == 0 && V_117 == 0 ) ) {
F_69 ( V_41 -> V_122 , L_15 ) ;
return V_123 ;
}
while ( V_116 ) {
V_6 = F_70 ( V_116 ) - 1 ;
V_118 = V_6 ;
V_2 = & V_41 -> V_124 [ V_118 ] ;
F_65 ( & V_2 -> V_42 ) ;
V_116 &= ~ ( 1 << V_6 ) ;
if ( F_71 ( V_6 , V_44 + V_125 ) ) {
F_72 ( F_3 ( V_2 ) ,
L_16 , V_118 ) ;
F_27 ( 1 ) ;
F_73 ( V_6 , V_44 + V_98 ) ;
} else {
if ( F_68 ( ! F_71 ( V_6 , V_44 +
V_126 ) ) ) {
F_69 ( F_3 ( V_2 ) ,
L_17 , V_118 ) ;
F_27 ( 1 ) ;
F_73 ( V_6 , V_44 + V_99 ) ;
} else {
if ( ! ( F_25 ( V_44 + V_52 +
V_53 * V_118 ) &
V_127 ) ) {
F_17 ( V_2 ) ;
}
F_73 ( V_6 , V_44 + V_99 ) ;
F_64 ( V_2 ) ;
}
}
F_66 ( & V_2 -> V_42 ) ;
}
while ( V_117 ) {
V_6 = F_70 ( V_117 ) - 1 ;
V_118 = V_6 + 32 ;
V_2 = & V_41 -> V_124 [ V_118 ] ;
F_65 ( & V_2 -> V_42 ) ;
V_117 &= ~ ( 1 << V_6 ) ;
if ( F_71 ( V_6 , V_44 + V_128 ) ) {
F_72 ( F_3 ( V_2 ) ,
L_16 , V_118 ) ;
F_27 ( 1 ) ;
F_73 ( V_6 , V_44 + V_100 ) ;
} else {
if ( F_68 ( ! F_71 ( V_6 , V_44 +
V_129 ) ) ) {
F_69 ( F_3 ( V_2 ) ,
L_17 , V_118 ) ;
F_73 ( V_6 , V_44 + V_101 ) ;
F_27 ( 1 ) ;
} else {
if ( ! ( F_25 ( V_44 + V_52 +
V_53 * V_118 ) &
V_127 ) ) {
F_17 ( V_2 ) ;
}
F_73 ( V_6 , V_44 + V_101 ) ;
F_64 ( V_2 ) ;
}
}
F_66 ( & V_2 -> V_42 ) ;
}
return V_123 ;
}
static int F_74 ( struct V_32 * V_33 )
{
unsigned long V_39 ;
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_61 * V_70 ;
void T_8 * V_44 = V_2 -> V_41 -> V_44 ;
F_46 ( V_33 ) ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
if ( V_2 -> V_36 < 32 ) {
F_22 ( 1 << V_2 -> V_36 , V_44 + V_98 ) ;
F_22 ( 1 << V_2 -> V_36 , V_44 + V_99 ) ;
} else {
F_22 ( 1 << ( V_2 -> V_36 - 32 ) , V_44 +
V_100 ) ;
F_22 ( 1 << ( V_2 -> V_36 - 32 ) , V_44 +
V_101 ) ;
}
F_17 ( V_2 ) ;
while ( ( V_70 = F_38 ( V_2 ) ) ) {
F_59 ( & V_2 -> V_41 -> V_20 , & V_70 -> V_4 ) ;
F_39 ( V_70 ) ;
F_35 ( V_2 , V_70 ) ;
}
while ( ( V_70 = F_41 ( V_2 ) ) ) {
F_59 ( & V_2 -> V_41 -> V_20 , & V_70 -> V_4 ) ;
F_39 ( V_70 ) ;
F_35 ( V_2 , V_70 ) ;
}
V_2 -> V_109 = 0 ;
V_2 -> V_104 = 0 ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 0 ;
}
static int F_75 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
unsigned long V_39 ;
F_2 ( F_3 ( V_2 ) , L_18 ,
V_108 , V_2 -> V_36 ) ;
if ( V_33 -> V_130 > 1 )
return - V_131 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
F_55 ( V_2 , NULL ) ;
V_2 -> V_113 = 1 ;
F_76 ( V_33 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return 1 ;
}
static void
F_77 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
int V_43 = V_2 -> V_36 ;
unsigned long V_39 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
F_22 ( 0x00000000U , V_2 -> V_41 -> V_44 + V_48 +
V_49 * V_43 ) ;
F_22 ( 0x00000000U , V_2 -> V_41 -> V_44 + V_45 +
V_46 * V_43 ) ;
V_2 -> V_113 = 0 ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
F_74 ( V_33 ) ;
}
static T_13
F_78 ( struct V_132 * V_133 )
{
struct V_61 * V_70 = F_14 ( V_133 , struct V_61 ,
V_62 ) ;
struct V_1 * V_2 = F_13 ( V_133 -> V_33 ) ;
unsigned long V_39 ;
T_13 V_134 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
V_134 = F_79 ( V_133 ) ;
F_40 ( V_2 , V_70 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
return V_134 ;
}
static struct V_132 *
F_80 ( struct V_32 * V_33 , T_9 V_135 , T_9 V_136 ,
T_2 V_137 , unsigned long V_39 )
{
struct V_3 * V_4 ;
struct V_61 * V_70 ;
unsigned long V_138 ;
struct V_1 * V_2 = F_13 ( V_33 ) ;
int V_139 ;
T_7 V_140 = F_15 ( V_2 ) -> V_103 ;
int V_24 ;
F_18 ( & V_2 -> V_42 , V_138 ) ;
F_2 ( F_3 ( V_2 ) ,
L_19 ,
V_108 , V_2 -> V_36 , V_136 , V_135 , V_137 ) ;
if ( V_39 & V_141 )
V_140 |= V_142 ;
V_139 = V_137 >> V_143 ;
if ( ( V_139 << V_143 ) < V_137 )
V_139 ++ ;
V_4 = F_81 ( & V_2 -> V_41 -> V_20 , V_139 ) ;
if ( V_4 == NULL )
goto V_110;
V_24 = F_82 (
& V_2 -> V_41 -> V_20 , V_4 , V_136 , V_137 , V_135 ,
F_15 ( V_2 ) -> V_144 ,
V_140 ) ;
if ( V_24 )
goto V_110;
F_83 ( F_1 ( V_2 , V_4 ) ) ;
V_70 = F_28 ( V_2 ) ;
V_70 -> V_4 = V_4 ;
V_70 -> V_39 = V_39 ;
V_70 -> V_62 . V_145 = F_78 ;
F_19 ( & V_2 -> V_42 , V_138 ) ;
return & V_70 -> V_62 ;
V_110:
F_19 ( & V_2 -> V_42 , V_138 ) ;
return NULL ;
}
static struct V_132 *
F_84 ( struct V_32 * V_33 , struct V_146 * V_147 ,
unsigned int V_67 , enum V_148 V_149 ,
unsigned long V_39 , void * V_150 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_3 * V_4 ;
struct V_61 * V_70 ;
const struct V_34 * V_151 ;
struct V_146 * V_66 ;
int V_152 = 0 ;
int V_137 ;
int V_6 ;
T_7 V_153 = F_15 ( V_2 ) -> V_144 ;
T_7 V_154 = F_15 ( V_2 ) -> V_155 ;
T_7 V_140 = F_15 ( V_2 ) -> V_103 ;
T_7 V_102 ;
unsigned long V_138 ;
int V_24 ;
if ( ! V_147 )
goto V_64;
if ( F_85 ( V_147 ) == 0 )
goto V_64;
F_18 ( & V_2 -> V_42 , V_138 ) ;
F_2 ( F_3 ( V_2 ) , L_20 ,
V_108 , V_67 , V_149 ) ;
if ( V_39 & V_141 )
V_140 |= V_142 ;
V_151 = F_15 ( V_2 ) ;
V_102 = V_151 -> V_102 ;
V_153 |= V_2 -> V_154 ;
V_140 |= V_2 -> V_154 ;
V_154 |= V_2 -> V_154 ;
if ( V_149 == V_156 ) {
T_7 V_157 = V_158 |
V_159 ;
V_102 |= V_160 ;
V_153 |= V_157 ;
V_140 |= V_157 ;
V_154 |= V_157 ;
} else if ( V_149 == V_161 ) {
T_7 V_162 = V_163 |
V_164 ;
V_102 |= V_165 ;
V_153 |= V_162 ;
V_140 |= V_162 ;
V_154 |= V_162 ;
} else
goto V_166;
F_86 (sgl, sg, sg_len, i) {
unsigned int V_167 ;
V_137 = F_85 ( V_66 ) ;
if ( V_137 <= V_168 ) {
V_152 ++ ;
continue;
}
V_167 = V_137 >> V_143 ;
if ( ( V_167 << V_143 ) < V_137 )
V_167 ++ ;
V_152 += V_167 ;
}
F_87 ( L_21 , V_152 ) ;
V_4 = F_81 ( & V_2 -> V_41 -> V_20 , V_152 ) ;
if ( V_4 == NULL )
goto V_169;
V_24 = F_88 ( & V_2 -> V_41 -> V_20 , V_4 , V_147 , V_67 ,
V_2 -> V_170 ,
V_153 ,
V_154 ,
V_140 ,
V_149 , V_142 ) ;
if ( V_24 )
goto V_171;
F_83 ( F_1 ( V_2 , V_4 ) ) ;
V_70 = F_28 ( V_2 ) ;
V_70 -> V_105 = V_102 ;
V_70 -> V_106 = V_4 -> V_7 ;
V_70 -> V_172 = V_149 ;
V_70 -> V_39 = V_39 ;
V_70 -> V_62 . V_145 = F_78 ;
V_70 -> V_4 = V_4 ;
F_19 ( & V_2 -> V_42 , V_138 ) ;
return & V_70 -> V_62 ;
V_171:
V_169:
V_166:
F_19 ( & V_2 -> V_42 , V_138 ) ;
V_64:
return NULL ;
}
static enum V_173
F_89 ( struct V_32 * V_33 , T_13 V_134 ,
struct V_174 * V_175 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
enum V_173 V_24 ;
V_24 = F_90 ( V_33 , V_134 , V_175 ) ;
if ( V_24 == V_176 || ! V_175 )
return V_24 ;
F_91 ( V_175 , F_43 ( V_33 ) ) ;
if ( V_24 == V_177 && V_2 -> V_83 )
V_24 = V_178 ;
return V_24 ;
}
static void
F_92 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
unsigned long V_39 ;
F_18 ( & V_2 -> V_42 , V_39 ) ;
if ( ! V_2 -> V_104 )
F_56 ( V_2 ) ;
F_19 ( & V_2 -> V_42 , V_39 ) ;
}
static int F_93 ( struct V_32 * V_33 ,
struct V_179 * V_102 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
T_9 V_170 ;
enum V_180 V_181 ;
T_7 V_182 ;
T_7 V_154 = 0 ;
int V_6 = 0 ;
if ( V_102 -> V_149 == V_161 ) {
V_170 = V_102 -> V_8 ;
V_181 = V_102 -> V_183 ;
V_182 = V_102 -> V_184 ;
} else if ( V_102 -> V_149 == V_156 ) {
V_170 = V_102 -> V_9 ;
V_181 = V_102 -> V_185 ;
V_182 = V_102 -> V_186 ;
} else {
F_63 ( F_3 ( V_2 ) , L_22 ) ;
return - V_187 ;
}
F_60 ( F_3 ( V_2 ) , L_23 ,
V_181 ) ;
switch ( V_181 ) {
case V_188 :
V_154 |=
V_189 |
V_190 ;
while ( V_6 < F_94 ( V_191 ) ) {
if ( V_191 [ V_6 ] . V_192 <= V_182 )
break;
V_6 ++ ;
}
break;
case V_193 :
V_154 |=
V_194 |
V_195 ;
while ( V_6 < F_94 ( V_191 ) ) {
if ( V_191 [ V_6 ] . V_196 <= V_182 )
break;
V_6 ++ ;
}
break;
case V_197 :
V_154 |=
V_198 |
V_199 ;
while ( V_6 < F_94 ( V_191 ) ) {
if ( V_191 [ V_6 ] . V_200 <= V_182 )
break;
V_6 ++ ;
}
break;
default:
F_63 ( F_3 ( V_2 ) ,
L_24 ) ;
return - V_187 ;
}
V_154 |= V_191 [ V_6 ] . V_201 ;
F_60 ( F_3 ( V_2 ) ,
L_25 ,
V_191 [ V_6 ] . V_192 , V_181 , V_182 ) ;
V_2 -> V_170 = V_170 ;
V_2 -> V_154 = V_154 ;
return 0 ;
}
static void F_95 ( struct V_202 * V_203 , const int * V_204 ,
struct V_119 * V_41 )
{
int V_205 ;
int V_6 = 0 ;
struct V_1 * V_2 ;
F_31 ( & V_203 -> V_206 ) ;
for ( V_205 = 0 ; V_204 [ V_205 ] != - 1 ; V_205 += 2 ) {
for ( V_6 = V_204 [ V_205 ] ; V_6 <= V_204 [ V_205 + 1 ] ; V_6 ++ ) {
V_2 = & V_41 -> V_124 [ V_6 ] ;
V_2 -> V_41 = V_41 ;
V_2 -> V_33 . V_89 = V_203 ;
V_2 -> V_36 = V_6 ;
F_96 ( & V_2 -> V_42 ) ;
V_2 -> V_109 = 0 ;
V_2 -> V_104 = 0 ;
F_31 ( & V_2 -> free ) ;
F_31 ( & V_2 -> V_71 ) ;
F_31 ( & V_2 -> V_73 ) ;
F_97 ( & V_2 -> V_112 , F_57 ,
( unsigned long ) V_2 ) ;
F_36 ( & V_2 -> V_33 . V_207 ,
& V_203 -> V_206 ) ;
}
}
}
static int T_5 F_98 ( struct V_208 * V_209 )
{
int V_110 = 0 ;
struct V_119 * V_41 ;
int V_114 ;
struct V_210 * V_211 ;
V_211 = F_99 ( V_209 , V_212 , 0 ) ;
if ( ! V_211 )
return - V_213 ;
if ( F_100 ( & V_209 -> V_122 ,
V_211 -> V_214 ,
F_101 ( V_211 ) ,
V_209 -> V_122 . V_215 -> V_216 ) == NULL )
return - V_26 ;
V_41 = F_102 ( & V_209 -> V_122 ,
F_103 ( sizeof( struct V_119 ) , 4 ) +
V_27 *
sizeof( struct V_1 ) ,
V_25 ) ;
if ( ! V_41 )
return - V_26 ;
V_41 -> V_124 = ( ( void * ) V_41 ) + F_103 ( sizeof( struct V_119 ) , 4 ) ;
V_41 -> V_44 = F_104 ( & V_209 -> V_122 , V_211 -> V_214 , F_101 ( V_211 ) ) ;
if ( ! V_41 -> V_44 )
return - V_26 ;
V_41 -> V_122 = & V_209 -> V_122 ;
F_96 ( & V_41 -> V_18 . V_42 ) ;
V_41 -> V_18 . V_16 = 0 ;
F_105 ( V_17 , V_41 ) ;
V_114 = F_106 ( V_209 , 0 ) ;
if ( V_114 < 0 )
return V_114 ;
V_110 = F_107 ( & V_209 -> V_122 , V_114 , F_67 , 0 ,
L_26 , V_41 ) ;
if ( V_110 )
return V_110 ;
V_41 -> V_114 = V_114 ;
V_110 = F_108 ( & V_41 -> V_20 , & V_209 -> V_122 ,
sizeof( struct V_3 ) ,
32 ) ;
if ( V_110 )
return V_110 ;
F_95 ( & V_41 -> V_88 , V_217 ,
V_41 ) ;
F_52 ( V_41 -> V_88 . V_218 ) ;
F_53 ( V_96 , V_41 -> V_88 . V_218 ) ;
V_41 -> V_88 . V_219 = F_75 ;
V_41 -> V_88 . V_220 = F_77 ;
V_41 -> V_88 . V_221 = F_84 ;
V_41 -> V_88 . V_222 = F_89 ;
V_41 -> V_88 . V_223 = F_92 ;
V_41 -> V_88 . V_224 = F_93 ;
V_41 -> V_88 . V_225 = F_46 ;
V_41 -> V_88 . V_226 = F_48 ;
V_41 -> V_88 . V_227 = F_74 ;
V_41 -> V_88 . V_122 = & V_209 -> V_122 ;
V_110 = F_109 ( & V_41 -> V_88 ) ;
if ( V_110 )
goto V_228;
F_95 ( & V_41 -> V_229 , V_230 ,
V_41 ) ;
F_52 ( V_41 -> V_229 . V_218 ) ;
F_53 ( V_231 , V_41 -> V_229 . V_218 ) ;
V_41 -> V_229 . V_219 = F_75 ;
V_41 -> V_229 . V_220 = F_77 ;
V_41 -> V_229 . V_232 = F_80 ;
V_41 -> V_229 . V_222 = F_89 ;
V_41 -> V_229 . V_223 = F_92 ;
V_41 -> V_229 . V_224 = F_93 ;
V_41 -> V_229 . V_225 = F_46 ;
V_41 -> V_229 . V_226 = F_48 ;
V_41 -> V_229 . V_227 = F_74 ;
V_41 -> V_229 . V_122 = & V_209 -> V_122 ;
V_41 -> V_229 . V_233 = V_234 ;
V_110 = F_109 ( & V_41 -> V_229 ) ;
if ( V_110 )
goto V_235;
V_110 = F_110 ( V_209 -> V_122 . V_236 , F_51 ,
V_41 ) ;
if ( V_110 )
goto V_237;
F_111 ( V_209 , V_41 ) ;
F_112 ( & V_209 -> V_122 , L_27 ,
( T_7 ) V_41 -> V_44 ) ;
return V_110 ;
V_237:
F_113 ( & V_41 -> V_229 ) ;
V_235:
F_113 ( & V_41 -> V_88 ) ;
V_228:
F_114 ( & V_41 -> V_20 ) ;
return V_110 ;
}
static void F_115 ( struct V_119 * V_41 , const int * V_204 )
{
int V_205 ;
int V_6 = 0 ;
struct V_1 * V_2 ;
for ( V_205 = 0 ; V_204 [ V_205 ] != - 1 ; V_205 += 2 ) {
for ( V_6 = V_204 [ V_205 ] ; V_6 <= V_204 [ V_205 + 1 ] ; V_6 ++ ) {
V_2 = & V_41 -> V_124 [ V_6 ] ;
F_116 ( & V_2 -> V_112 ) ;
}
}
}
static int F_117 ( struct V_208 * V_209 )
{
struct V_119 * V_41 = F_118 ( V_209 ) ;
F_119 ( & V_209 -> V_122 , V_41 -> V_114 , V_41 ) ;
F_115 ( V_41 , V_217 ) ;
F_115 ( V_41 , V_230 ) ;
F_120 ( V_209 -> V_122 . V_236 ) ;
F_113 ( & V_41 -> V_229 ) ;
F_113 ( & V_41 -> V_88 ) ;
F_114 ( & V_41 -> V_20 ) ;
return 0 ;
}
static int T_5 F_121 ( void )
{
return F_122 ( & V_238 , F_98 ) ;
}
static void T_6 F_123 ( void )
{
F_124 ( & V_238 ) ;
}
