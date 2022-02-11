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
int V_6 ;
int V_22 = 0 ;
char * V_23 ;
char * V_24 ;
int V_25 ;
V_23 = F_5 ( 4 * 1024 , V_26 ) ;
if ( V_23 == NULL )
goto V_27;
V_24 = V_23 ;
V_24 += sprintf ( V_24 , L_3 ) ;
for ( V_6 = 0 ; V_6 < V_28 ; V_6 ++ )
if ( V_16 & ( 1 << V_6 ) )
V_24 += sprintf ( V_24 , L_4 , V_6 ) ;
V_24 += sprintf ( V_24 , L_5 , V_19 ) ;
V_25 = V_24 - V_23 ;
if ( * V_15 > V_25 )
goto V_29;
if ( V_14 > V_25 - * V_15 )
V_14 = V_25 - * V_15 ;
if ( F_6 ( V_13 , V_23 + * V_15 , V_14 ) )
V_22 = - V_30 ;
V_22 = V_14 ;
* V_15 += V_14 ;
V_29:
F_7 ( V_23 ) ;
return V_22 ;
V_27:
return 0 ;
}
static int T_5 F_8 ( void )
{
V_31 = F_9 ( L_6 , NULL ) ;
( void ) F_10 ( L_7 ,
V_32 | V_33 ,
V_31 , NULL ,
& V_34 ) ;
return 0 ;
}
static void T_6 F_11 ( void )
{
F_12 ( V_31 ) ;
}
static inline struct V_1 * F_13 ( struct V_35 * V_36 )
{
return F_14 ( V_36 , struct V_1 , V_36 ) ;
}
static inline const struct V_37 *
F_15 ( struct V_1 * V_2 )
{
return & V_38 [ V_2 -> V_39 ] . V_40 ;
}
static inline const struct V_41 *
F_16 ( struct V_1 * V_2 )
{
return & V_38 [ V_2 -> V_39 ] ;
}
static void F_17 ( struct V_1 * V_2 )
{
unsigned long V_42 ;
struct V_43 * V_18 = & V_2 -> V_44 -> V_18 ;
F_18 ( & V_18 -> V_45 , V_42 ) ;
V_18 -> V_16 &= ~ ( 1ULL << V_2 -> V_39 ) ;
F_19 ( & V_18 -> V_45 , V_42 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_42 ;
struct V_43 * V_18 = & V_2 -> V_44 -> V_18 ;
F_18 ( & V_18 -> V_45 , V_42 ) ;
V_18 -> V_16 |= ( 1ULL << V_2 -> V_39 ) ;
F_19 ( & V_18 -> V_45 , V_42 ) ;
}
static inline int F_21 ( struct V_1 * V_2 , T_7 V_7 )
{
int V_46 = V_2 -> V_39 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
F_22 ( V_7 ,
V_47 + V_48 +
V_49 * V_46 ) ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_2 , T_7 V_50 )
{
int V_46 = V_2 -> V_39 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
F_22 ( V_50 ,
V_47 + V_51 +
V_52 * V_46 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_7 V_53 ;
int V_46 = V_2 -> V_39 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
F_20 ( V_2 ) ;
V_53 = F_25 ( V_47 + V_51 +
V_52 * V_46 ) ;
V_53 |= V_54 ;
F_22 ( V_53 , V_47 + V_51 +
V_52 * V_46 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_46 = V_2 -> V_39 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
F_27 ( F_25 ( V_47 + V_55 +
V_56 * V_46 ) &
V_57 ) ;
F_22 ( V_4 -> V_8 ,
V_47 + V_58 +
V_59 * V_46 ) ;
F_22 ( V_4 -> V_9 , V_47 +
V_60 +
V_61 * V_46 ) ;
F_22 ( V_4 -> V_10 , V_47 + V_62 +
V_63 * V_46 ) ;
F_22 ( V_4 -> V_7 , V_47 + V_48 +
V_49 * V_46 ) ;
return 0 ;
}
static struct V_64 *
F_28 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
if ( F_29 ( & V_2 -> free ) ) {
V_65 = F_30 ( sizeof( struct V_64 ) , V_66 ) ;
if ( V_65 == NULL )
goto V_29;
F_31 ( & V_65 -> V_67 ) ;
F_32 ( & V_65 -> V_65 , & V_2 -> V_36 ) ;
} else {
V_65 = F_33 ( & V_2 -> free ,
struct V_64 ,
V_67 ) ;
F_34 ( & V_65 -> V_67 ) ;
V_65 -> V_68 = NULL ;
V_65 -> V_69 = 0 ;
V_65 -> V_65 . V_70 = NULL ;
V_65 -> V_65 . V_71 = NULL ;
}
V_29:
return V_65 ;
}
static void
F_35 ( struct V_1 * V_2 , struct V_64 * V_72 )
{
F_36 ( & V_72 -> V_67 , & V_2 -> free ) ;
}
static void
F_37 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
F_36 ( & V_65 -> V_67 , & V_2 -> V_73 ) ;
}
static struct V_64 *
F_38 ( struct V_1 * V_2 )
{
struct V_64 * V_74 ;
if ( F_29 ( & V_2 -> V_73 ) )
return NULL ;
V_74 = F_33 ( & V_2 -> V_73 ,
struct V_64 ,
V_67 ) ;
return V_74 ;
}
static void
F_39 ( struct V_64 * V_72 )
{
F_34 ( & V_72 -> V_67 ) ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
F_36 ( & V_65 -> V_67 , & V_2 -> V_75 ) ;
}
static struct V_64 *
F_41 ( struct V_1 * V_2 )
{
struct V_64 * V_74 ;
if ( F_29 ( & V_2 -> V_75 ) )
return NULL ;
V_74 = F_33 ( & V_2 -> V_75 ,
struct V_64 ,
V_67 ) ;
return V_74 ;
}
static inline T_7 F_42 ( struct V_3 * V_76 )
{
struct V_3 * V_4 = V_76 ;
T_7 V_77 = 0 ;
while ( V_4 ) {
V_77 += V_4 -> V_7 & V_78 ;
V_4 = V_4 -> V_11 ;
}
return V_77 ;
}
static T_7 F_43 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
struct V_64 * V_72 ;
struct V_79 * V_80 ;
unsigned long V_42 ;
T_7 V_81 = 0 ;
int V_6 = 0 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
F_44 (pos, &cohc->active) {
V_72 = F_45 ( V_80 , struct V_64 , V_67 ) ;
if ( V_6 == 0 ) {
struct V_3 * V_4 ;
T_9 V_82 ;
V_81 = F_25 ( V_2 -> V_44 -> V_47 +
V_48 +
V_49 * V_2 -> V_39 ) &
V_78 ;
V_82 = F_25 ( V_2 -> V_44 -> V_47 +
V_62 +
V_63 *
V_2 -> V_39 ) &
~ V_83 ;
if ( ! V_82 )
continue;
V_4 = V_72 -> V_4 ;
while ( V_4 && V_4 -> V_10 != V_82 )
V_4 = V_4 -> V_11 ;
if ( V_4 )
V_4 = V_4 -> V_11 ;
V_81 += F_42 ( V_4 ) ;
} else {
V_81 += F_42 ( V_72 -> V_4 ) ;
}
V_6 ++ ;
}
F_44 (pos, &cohc->queue) {
V_72 = F_45 ( V_80 , struct V_64 , V_67 ) ;
V_81 += F_42 ( V_72 -> V_4 ) ;
}
F_19 ( & V_2 -> V_45 , V_42 ) ;
return V_81 ;
}
static void F_46 ( struct V_35 * V_36 )
{
T_7 V_53 ;
unsigned long V_42 ;
struct V_1 * V_2 = F_13 ( V_36 ) ;
int V_46 = V_2 -> V_39 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
V_53 = F_25 ( V_47 + V_51 +
V_52 * V_46 ) ;
if ( ( V_53 & V_84 ) == 0 &&
( V_53 & V_54 ) )
V_2 -> V_85 = 1 ;
V_53 &= ~ V_54 ;
F_22 ( V_53 , V_47 + V_51 +
V_52 * V_46 ) ;
F_22 ( V_53 , V_47 + V_51 +
V_52 * V_46 ) ;
while ( F_25 ( V_47 + V_55 + V_56 *
V_46 ) & V_57 )
F_47 () ;
if ( ( F_25 ( V_47 + V_48 + V_49 *
V_46 ) & V_78 ) > 0 )
V_2 -> V_85 = 1 ;
F_17 ( V_2 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
}
static void F_48 ( struct V_35 * V_36 )
{
T_7 V_53 ;
unsigned long V_42 ;
struct V_1 * V_2 = F_13 ( V_36 ) ;
int V_46 = V_2 -> V_39 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_85 ) {
V_53 = F_25 ( V_2 -> V_44 -> V_47 + V_51 +
V_52 * V_46 ) ;
V_53 |= V_54 ;
F_22 ( V_53 , V_2 -> V_44 -> V_47 + V_51 +
V_52 * V_46 ) ;
V_2 -> V_85 = 0 ;
}
F_19 ( & V_2 -> V_45 , V_42 ) ;
}
bool F_49 ( struct V_35 * V_36 , void * V_86 )
{
unsigned int V_87 = ( unsigned int ) V_86 ;
if ( V_87 == F_13 ( V_36 ) -> V_39 )
return true ;
return false ;
}
static bool F_50 ( struct V_35 * V_36 , void * V_88 )
{
struct V_89 * args = V_88 ;
if ( & args -> V_44 -> V_90 == V_36 -> V_91 &&
args -> V_87 == F_13 ( V_36 ) -> V_39 )
return true ;
return false ;
}
static struct V_35 * F_51 ( struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_89 args = {
. V_44 = V_95 -> V_96 ,
. V_87 = V_93 -> args [ 0 ] ,
} ;
T_10 V_97 ;
F_52 ( V_97 ) ;
F_53 ( V_98 , V_97 ) ;
return F_54 ( V_97 , F_50 , & args ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_37 * V_40 )
{
unsigned long V_42 ;
const struct V_37 * V_99 ;
int V_46 = V_2 -> V_39 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
if ( V_40 )
V_99 = V_40 ;
else
V_99 = F_15 ( V_2 ) ;
if ( V_46 < 32 ) {
F_22 ( 1 << V_46 , V_47 + V_100 ) ;
F_22 ( 1 << V_46 , V_47 + V_101 ) ;
} else {
F_22 ( 1 << ( V_46 - 32 ) , V_47 +
V_102 ) ;
F_22 ( 1 << ( V_46 - 32 ) , V_47 +
V_103 ) ;
}
F_23 ( V_2 , V_99 -> V_104 ) ;
F_21 ( V_2 , V_99 -> V_105 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
return 0 ;
}
static struct V_64 * F_56 ( struct V_1 * V_2 )
{
struct V_64 * V_72 ;
V_72 = F_41 ( V_2 ) ;
if ( V_72 != NULL ) {
F_39 ( V_72 ) ;
V_2 -> V_106 = 1 ;
F_37 ( V_2 , V_72 ) ;
F_23 ( V_2 , V_72 -> V_107 ) ;
F_21 ( V_2 , V_72 -> V_108 ) ;
F_26 ( V_2 , V_72 -> V_4 ) ;
F_24 ( V_2 ) ;
}
return V_72 ;
}
static void F_57 ( unsigned long V_88 )
{
struct V_1 * V_2 = (struct V_1 * ) V_88 ;
struct V_64 * V_109 ;
unsigned long V_42 ;
T_11 V_70 ;
void * V_71 ;
F_2 ( F_3 ( V_2 ) , L_8
L_9 , V_110 ,
V_2 -> V_39 , V_2 -> V_111 ) ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
V_109 = F_38 ( V_2 ) ;
if ( V_109 == NULL )
goto V_112;
V_70 = V_109 -> V_65 . V_70 ;
V_71 = V_109 -> V_65 . V_71 ;
F_58 ( & V_109 -> V_65 ) ;
F_59 ( & V_2 -> V_44 -> V_20 , & V_109 -> V_4 ) ;
F_39 ( V_109 ) ;
F_35 ( V_2 , V_109 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
if ( V_70 )
V_70 ( V_71 ) ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
V_2 -> V_111 -- ;
if ( V_2 -> V_111 ) {
F_60 ( F_3 ( V_2 ) , L_10
L_11 ) ;
if ( F_16 ( V_2 ) -> V_113 )
F_61 ( & V_2 -> V_114 ) ;
else
F_62 ( & V_2 -> V_114 ) ;
}
F_19 ( & V_2 -> V_45 , V_42 ) ;
return;
V_112:
F_19 ( & V_2 -> V_45 , V_42 ) ;
F_63 ( F_3 ( V_2 ) , L_12 , V_110 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_115 ) {
F_63 ( F_3 ( V_2 ) , L_13
L_14 ) ;
return;
}
F_65 ( & V_2 -> V_45 ) ;
F_27 ( F_29 ( & V_2 -> V_73 ) ) ;
V_2 -> V_111 ++ ;
if ( F_56 ( V_2 ) == NULL )
V_2 -> V_106 = 0 ;
F_66 ( & V_2 -> V_45 ) ;
if ( F_16 ( V_2 ) -> V_113 )
F_61 ( & V_2 -> V_114 ) ;
else
F_62 ( & V_2 -> V_114 ) ;
}
static T_12 F_67 ( int V_116 , void * V_117 )
{
T_7 V_118 ;
T_7 V_119 ;
int V_6 ;
int V_120 ;
struct V_121 * V_44 = V_117 ;
struct V_1 * V_2 ;
void T_8 * V_47 = V_44 -> V_47 ;
V_118 = F_25 ( V_47 + V_122 ) ;
V_119 = F_25 ( V_47 + V_123 ) ;
if ( F_68 ( V_118 == 0 && V_119 == 0 ) ) {
F_69 ( V_44 -> V_124 , L_15 ) ;
return V_125 ;
}
while ( V_118 ) {
V_6 = F_70 ( V_118 ) - 1 ;
V_120 = V_6 ;
V_2 = & V_44 -> V_126 [ V_120 ] ;
F_65 ( & V_2 -> V_45 ) ;
V_118 &= ~ ( 1 << V_6 ) ;
if ( F_71 ( V_6 , V_47 + V_127 ) ) {
F_72 ( F_3 ( V_2 ) ,
L_16 , V_120 ) ;
F_27 ( 1 ) ;
F_73 ( V_6 , V_47 + V_100 ) ;
} else {
if ( F_68 ( ! F_71 ( V_6 , V_47 +
V_128 ) ) ) {
F_69 ( F_3 ( V_2 ) ,
L_17 , V_120 ) ;
F_27 ( 1 ) ;
F_73 ( V_6 , V_47 + V_101 ) ;
} else {
if ( ! ( F_25 ( V_47 + V_55 +
V_56 * V_120 ) &
V_129 ) ) {
F_17 ( V_2 ) ;
}
F_73 ( V_6 , V_47 + V_101 ) ;
F_64 ( V_2 ) ;
}
}
F_66 ( & V_2 -> V_45 ) ;
}
while ( V_119 ) {
V_6 = F_70 ( V_119 ) - 1 ;
V_120 = V_6 + 32 ;
V_2 = & V_44 -> V_126 [ V_120 ] ;
F_65 ( & V_2 -> V_45 ) ;
V_119 &= ~ ( 1 << V_6 ) ;
if ( F_71 ( V_6 , V_47 + V_130 ) ) {
F_72 ( F_3 ( V_2 ) ,
L_16 , V_120 ) ;
F_27 ( 1 ) ;
F_73 ( V_6 , V_47 + V_102 ) ;
} else {
if ( F_68 ( ! F_71 ( V_6 , V_47 +
V_131 ) ) ) {
F_69 ( F_3 ( V_2 ) ,
L_17 , V_120 ) ;
F_73 ( V_6 , V_47 + V_103 ) ;
F_27 ( 1 ) ;
} else {
if ( ! ( F_25 ( V_47 + V_55 +
V_56 * V_120 ) &
V_129 ) ) {
F_17 ( V_2 ) ;
}
F_73 ( V_6 , V_47 + V_103 ) ;
F_64 ( V_2 ) ;
}
}
F_66 ( & V_2 -> V_45 ) ;
}
return V_125 ;
}
static int F_74 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
unsigned long V_42 ;
F_2 ( F_3 ( V_2 ) , L_18 ,
V_110 , V_2 -> V_39 ) ;
if ( V_36 -> V_132 > 1 )
return - V_133 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
F_55 ( V_2 , NULL ) ;
V_2 -> V_115 = 1 ;
F_75 ( V_36 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
return 1 ;
}
static void
F_76 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
int V_46 = V_2 -> V_39 ;
unsigned long V_42 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
F_22 ( 0x00000000U , V_2 -> V_44 -> V_47 + V_51 +
V_52 * V_46 ) ;
F_22 ( 0x00000000U , V_2 -> V_44 -> V_47 + V_48 +
V_49 * V_46 ) ;
V_2 -> V_115 = 0 ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
V_36 -> V_91 -> V_134 ( V_36 , V_135 , 0 ) ;
}
static T_13
F_77 ( struct V_136 * V_137 )
{
struct V_64 * V_72 = F_14 ( V_137 , struct V_64 ,
V_65 ) ;
struct V_1 * V_2 = F_13 ( V_137 -> V_36 ) ;
unsigned long V_42 ;
T_13 V_138 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
V_138 = F_78 ( V_137 ) ;
F_40 ( V_2 , V_72 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
return V_138 ;
}
static struct V_136 *
F_79 ( struct V_35 * V_36 , T_9 V_139 , T_9 V_140 ,
T_2 V_141 , unsigned long V_42 )
{
struct V_3 * V_4 ;
struct V_64 * V_72 ;
unsigned long V_142 ;
struct V_1 * V_2 = F_13 ( V_36 ) ;
int V_143 ;
T_7 V_144 = F_15 ( V_2 ) -> V_105 ;
int V_22 ;
F_18 ( & V_2 -> V_45 , V_142 ) ;
F_2 ( F_3 ( V_2 ) ,
L_19 ,
V_110 , V_2 -> V_39 , V_140 , V_139 , V_141 ) ;
if ( V_42 & V_145 )
V_144 |= V_146 ;
V_143 = V_141 >> V_147 ;
if ( ( V_143 << V_147 ) < V_141 )
V_143 ++ ;
V_4 = F_80 ( & V_2 -> V_44 -> V_20 , V_143 ) ;
if ( V_4 == NULL )
goto V_112;
V_22 = F_81 (
& V_2 -> V_44 -> V_20 , V_4 , V_140 , V_141 , V_139 ,
F_15 ( V_2 ) -> V_148 ,
V_144 ) ;
if ( V_22 )
goto V_112;
F_82 ( F_1 ( V_2 , V_4 ) ) ;
V_72 = F_28 ( V_2 ) ;
V_72 -> V_4 = V_4 ;
V_72 -> V_42 = V_42 ;
V_72 -> V_65 . V_149 = F_77 ;
F_19 ( & V_2 -> V_45 , V_142 ) ;
return & V_72 -> V_65 ;
V_112:
F_19 ( & V_2 -> V_45 , V_142 ) ;
return NULL ;
}
static struct V_136 *
F_83 ( struct V_35 * V_36 , struct V_150 * V_151 ,
unsigned int V_69 , enum V_152 V_153 ,
unsigned long V_42 , void * V_154 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
struct V_3 * V_4 ;
struct V_64 * V_72 ;
const struct V_37 * V_155 ;
struct V_150 * V_68 ;
int V_156 = 0 ;
int V_141 ;
int V_6 ;
T_7 V_157 = F_15 ( V_2 ) -> V_148 ;
T_7 V_158 = F_15 ( V_2 ) -> V_159 ;
T_7 V_144 = F_15 ( V_2 ) -> V_105 ;
T_7 V_104 ;
unsigned long V_142 ;
int V_22 ;
if ( ! V_151 )
goto V_29;
if ( F_84 ( V_151 ) == 0 )
goto V_29;
F_18 ( & V_2 -> V_45 , V_142 ) ;
F_2 ( F_3 ( V_2 ) , L_20 ,
V_110 , V_69 , V_153 ) ;
if ( V_42 & V_145 )
V_144 |= V_146 ;
V_155 = F_15 ( V_2 ) ;
V_104 = V_155 -> V_104 ;
V_157 |= V_2 -> V_158 ;
V_144 |= V_2 -> V_158 ;
V_158 |= V_2 -> V_158 ;
if ( V_153 == V_160 ) {
T_7 V_161 = V_162 |
V_163 ;
V_104 |= V_164 ;
V_157 |= V_161 ;
V_144 |= V_161 ;
V_158 |= V_161 ;
} else if ( V_153 == V_165 ) {
T_7 V_166 = V_167 |
V_168 ;
V_104 |= V_169 ;
V_157 |= V_166 ;
V_144 |= V_166 ;
V_158 |= V_166 ;
} else
goto V_170;
F_85 (sgl, sg, sg_len, i) {
unsigned int V_171 ;
V_141 = F_84 ( V_68 ) ;
if ( V_141 <= V_172 ) {
V_156 ++ ;
continue;
}
V_171 = V_141 >> V_147 ;
if ( ( V_171 << V_147 ) < V_141 )
V_171 ++ ;
V_156 += V_171 ;
}
F_86 ( L_21 , V_156 ) ;
V_4 = F_80 ( & V_2 -> V_44 -> V_20 , V_156 ) ;
if ( V_4 == NULL )
goto V_173;
V_22 = F_87 ( & V_2 -> V_44 -> V_20 , V_4 , V_151 , V_69 ,
V_2 -> V_174 ,
V_157 ,
V_158 ,
V_144 ,
V_153 , V_146 ) ;
if ( V_22 )
goto V_175;
F_82 ( F_1 ( V_2 , V_4 ) ) ;
V_72 = F_28 ( V_2 ) ;
V_72 -> V_107 = V_104 ;
V_72 -> V_108 = V_4 -> V_7 ;
V_72 -> V_176 = V_153 ;
V_72 -> V_42 = V_42 ;
V_72 -> V_65 . V_149 = F_77 ;
V_72 -> V_4 = V_4 ;
F_19 ( & V_2 -> V_45 , V_142 ) ;
return & V_72 -> V_65 ;
V_175:
V_173:
V_170:
F_19 ( & V_2 -> V_45 , V_142 ) ;
V_29:
return NULL ;
}
static enum V_177
F_88 ( struct V_35 * V_36 , T_13 V_138 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
enum V_177 V_22 ;
V_22 = F_89 ( V_36 , V_138 , V_179 ) ;
if ( V_22 == V_180 )
return V_22 ;
F_90 ( V_179 , F_43 ( V_36 ) ) ;
if ( V_22 == V_181 && V_2 -> V_85 )
V_22 = V_182 ;
return V_22 ;
}
static void
F_91 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
unsigned long V_42 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
if ( ! V_2 -> V_106 )
F_56 ( V_2 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
}
static void F_92 ( struct V_35 * V_36 ,
struct V_183 * V_104 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
T_9 V_174 ;
enum V_184 V_185 ;
T_7 V_186 ;
T_7 V_158 = 0 ;
int V_6 = 0 ;
if ( V_104 -> V_153 == V_165 ) {
V_174 = V_104 -> V_8 ;
V_185 = V_104 -> V_187 ;
V_186 = V_104 -> V_188 ;
} else if ( V_104 -> V_153 == V_160 ) {
V_174 = V_104 -> V_9 ;
V_185 = V_104 -> V_189 ;
V_186 = V_104 -> V_190 ;
} else {
F_63 ( F_3 ( V_2 ) , L_22 ) ;
return;
}
F_60 ( F_3 ( V_2 ) , L_23 ,
V_185 ) ;
switch ( V_185 ) {
case V_191 :
V_158 |=
V_192 |
V_193 ;
while ( V_6 < F_93 ( V_194 ) ) {
if ( V_194 [ V_6 ] . V_195 <= V_186 )
break;
V_6 ++ ;
}
break;
case V_196 :
V_158 |=
V_197 |
V_198 ;
while ( V_6 < F_93 ( V_194 ) ) {
if ( V_194 [ V_6 ] . V_199 <= V_186 )
break;
V_6 ++ ;
}
break;
case V_200 :
V_158 |=
V_201 |
V_202 ;
while ( V_6 < F_93 ( V_194 ) ) {
if ( V_194 [ V_6 ] . V_203 <= V_186 )
break;
V_6 ++ ;
}
break;
default:
F_63 ( F_3 ( V_2 ) ,
L_24 ) ;
return;
}
V_158 |= V_194 [ V_6 ] . V_204 ;
F_60 ( F_3 ( V_2 ) ,
L_25 ,
V_194 [ V_6 ] . V_195 , V_185 , V_186 ) ;
V_2 -> V_174 = V_174 ;
V_2 -> V_158 = V_158 ;
}
static int
F_94 ( struct V_35 * V_36 , enum V_205 V_206 ,
unsigned long V_207 )
{
unsigned long V_42 ;
struct V_1 * V_2 = F_13 ( V_36 ) ;
struct V_64 * V_72 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
if ( V_206 == V_208 ) {
struct V_183 * V_104 =
(struct V_183 * ) V_207 ;
F_92 ( V_36 , V_104 ) ;
return 0 ;
}
if ( V_206 == V_209 ) {
F_46 ( V_36 ) ;
return 0 ;
}
if ( V_206 == V_210 ) {
F_48 ( V_36 ) ;
return 0 ;
}
if ( V_206 != V_135 )
return - V_211 ;
F_46 ( V_36 ) ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
if ( V_2 -> V_39 < 32 ) {
F_22 ( 1 << V_2 -> V_39 , V_47 + V_100 ) ;
F_22 ( 1 << V_2 -> V_39 , V_47 + V_101 ) ;
} else {
F_22 ( 1 << ( V_2 -> V_39 - 32 ) , V_47 +
V_102 ) ;
F_22 ( 1 << ( V_2 -> V_39 - 32 ) , V_47 +
V_103 ) ;
}
F_17 ( V_2 ) ;
while ( ( V_72 = F_38 ( V_2 ) ) ) {
F_59 ( & V_2 -> V_44 -> V_20 , & V_72 -> V_4 ) ;
F_39 ( V_72 ) ;
F_35 ( V_2 , V_72 ) ;
}
while ( ( V_72 = F_41 ( V_2 ) ) ) {
F_59 ( & V_2 -> V_44 -> V_20 , & V_72 -> V_4 ) ;
F_39 ( V_72 ) ;
F_35 ( V_2 , V_72 ) ;
}
V_2 -> V_111 = 0 ;
V_2 -> V_106 = 0 ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
return 0 ;
}
void F_95 ( struct V_212 * V_213 , const int * V_214 ,
struct V_121 * V_44 )
{
int V_215 ;
int V_6 = 0 ;
struct V_1 * V_2 ;
F_31 ( & V_213 -> V_216 ) ;
for ( V_215 = 0 ; V_214 [ V_215 ] != - 1 ; V_215 += 2 ) {
for ( V_6 = V_214 [ V_215 ] ; V_6 <= V_214 [ V_215 + 1 ] ; V_6 ++ ) {
V_2 = & V_44 -> V_126 [ V_6 ] ;
V_2 -> V_44 = V_44 ;
V_2 -> V_36 . V_91 = V_213 ;
V_2 -> V_39 = V_6 ;
F_96 ( & V_2 -> V_45 ) ;
V_2 -> V_111 = 0 ;
V_2 -> V_106 = 0 ;
F_31 ( & V_2 -> free ) ;
F_31 ( & V_2 -> V_73 ) ;
F_31 ( & V_2 -> V_75 ) ;
F_97 ( & V_2 -> V_114 , F_57 ,
( unsigned long ) V_2 ) ;
F_36 ( & V_2 -> V_36 . V_217 ,
& V_213 -> V_216 ) ;
}
}
}
static int T_5 F_98 ( struct V_218 * V_219 )
{
int V_112 = 0 ;
struct V_121 * V_44 ;
int V_116 ;
struct V_220 * V_221 ;
V_221 = F_99 ( V_219 , V_222 , 0 ) ;
if ( ! V_221 )
return - V_223 ;
if ( F_100 ( & V_219 -> V_124 ,
V_221 -> V_224 ,
F_101 ( V_221 ) ,
V_219 -> V_124 . V_225 -> V_226 ) == NULL )
return - V_227 ;
V_44 = F_102 ( & V_219 -> V_124 ,
F_103 ( sizeof( struct V_121 ) , 4 ) +
V_28 *
sizeof( struct V_1 ) ,
V_26 ) ;
if ( ! V_44 )
return - V_227 ;
V_44 -> V_126 = ( ( void * ) V_44 ) + F_103 ( sizeof( struct V_121 ) , 4 ) ;
V_44 -> V_47 = F_104 ( & V_219 -> V_124 , V_221 -> V_224 , F_101 ( V_221 ) ) ;
if ( ! V_44 -> V_47 )
return - V_227 ;
V_44 -> V_124 = & V_219 -> V_124 ;
F_96 ( & V_44 -> V_18 . V_45 ) ;
V_44 -> V_18 . V_16 = 0 ;
F_105 ( V_17 , V_44 ) ;
V_116 = F_106 ( V_219 , 0 ) ;
if ( V_116 < 0 )
return V_116 ;
V_112 = F_107 ( & V_219 -> V_124 , V_116 , F_67 , V_228 ,
L_26 , V_44 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_108 ( & V_44 -> V_20 , & V_219 -> V_124 ,
sizeof( struct V_3 ) ,
32 ) ;
if ( V_112 )
return V_112 ;
F_95 ( & V_44 -> V_90 , V_229 ,
V_44 ) ;
F_52 ( V_44 -> V_90 . V_230 ) ;
F_53 ( V_98 , V_44 -> V_90 . V_230 ) ;
V_44 -> V_90 . V_231 = F_74 ;
V_44 -> V_90 . V_232 = F_76 ;
V_44 -> V_90 . V_233 = F_83 ;
V_44 -> V_90 . V_234 = F_88 ;
V_44 -> V_90 . V_235 = F_91 ;
V_44 -> V_90 . V_134 = F_94 ;
V_44 -> V_90 . V_124 = & V_219 -> V_124 ;
V_112 = F_109 ( & V_44 -> V_90 ) ;
if ( V_112 )
goto V_236;
F_95 ( & V_44 -> V_237 , V_238 ,
V_44 ) ;
F_52 ( V_44 -> V_237 . V_230 ) ;
F_53 ( V_239 , V_44 -> V_237 . V_230 ) ;
V_44 -> V_237 . V_231 = F_74 ;
V_44 -> V_237 . V_232 = F_76 ;
V_44 -> V_237 . V_240 = F_79 ;
V_44 -> V_237 . V_234 = F_88 ;
V_44 -> V_237 . V_235 = F_91 ;
V_44 -> V_237 . V_134 = F_94 ;
V_44 -> V_237 . V_124 = & V_219 -> V_124 ;
V_44 -> V_237 . V_241 = 2 ;
V_112 = F_109 ( & V_44 -> V_237 ) ;
if ( V_112 )
goto V_242;
V_112 = F_110 ( V_219 -> V_124 . V_243 , F_51 ,
V_44 ) ;
if ( V_112 )
goto V_244;
F_111 ( V_219 , V_44 ) ;
F_112 ( & V_219 -> V_124 , L_27 ,
( T_7 ) V_44 -> V_47 ) ;
return V_112 ;
V_244:
F_113 ( & V_44 -> V_237 ) ;
V_242:
F_113 ( & V_44 -> V_90 ) ;
V_236:
F_114 ( & V_44 -> V_20 ) ;
return V_112 ;
}
static int F_115 ( struct V_218 * V_219 )
{
struct V_121 * V_44 = F_116 ( V_219 ) ;
F_117 ( V_219 -> V_124 . V_243 ) ;
F_113 ( & V_44 -> V_237 ) ;
F_113 ( & V_44 -> V_90 ) ;
F_114 ( & V_44 -> V_20 ) ;
return 0 ;
}
int T_5 F_118 ( void )
{
return F_119 ( & V_245 , F_98 ) ;
}
void T_6 F_120 ( void )
{
F_121 ( & V_245 ) ;
}
