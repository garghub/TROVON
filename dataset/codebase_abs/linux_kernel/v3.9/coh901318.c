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
static int F_50 ( struct V_1 * V_2 ,
struct V_37 * V_40 )
{
unsigned long V_42 ;
const struct V_37 * V_88 ;
int V_46 = V_2 -> V_39 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
if ( V_40 )
V_88 = V_40 ;
else
V_88 = F_15 ( V_2 ) ;
if ( V_46 < 32 ) {
F_22 ( 1 << V_46 , V_47 + V_89 ) ;
F_22 ( 1 << V_46 , V_47 + V_90 ) ;
} else {
F_22 ( 1 << ( V_46 - 32 ) , V_47 +
V_91 ) ;
F_22 ( 1 << ( V_46 - 32 ) , V_47 +
V_92 ) ;
}
F_23 ( V_2 , V_88 -> V_93 ) ;
F_21 ( V_2 , V_88 -> V_94 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
return 0 ;
}
static struct V_64 * F_51 ( struct V_1 * V_2 )
{
struct V_64 * V_72 ;
V_72 = F_41 ( V_2 ) ;
if ( V_72 != NULL ) {
F_39 ( V_72 ) ;
V_2 -> V_95 = 1 ;
F_37 ( V_2 , V_72 ) ;
F_23 ( V_2 , V_72 -> V_96 ) ;
F_21 ( V_2 , V_72 -> V_97 ) ;
F_26 ( V_2 , V_72 -> V_4 ) ;
F_24 ( V_2 ) ;
}
return V_72 ;
}
static void F_52 ( unsigned long V_98 )
{
struct V_1 * V_2 = (struct V_1 * ) V_98 ;
struct V_64 * V_99 ;
unsigned long V_42 ;
T_10 V_70 ;
void * V_71 ;
F_2 ( F_3 ( V_2 ) , L_8
L_9 , V_100 ,
V_2 -> V_39 , V_2 -> V_101 ) ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
V_99 = F_38 ( V_2 ) ;
if ( V_99 == NULL )
goto V_102;
V_70 = V_99 -> V_65 . V_70 ;
V_71 = V_99 -> V_65 . V_71 ;
F_53 ( & V_99 -> V_65 ) ;
F_54 ( & V_2 -> V_44 -> V_20 , & V_99 -> V_4 ) ;
F_39 ( V_99 ) ;
F_35 ( V_2 , V_99 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
if ( V_70 )
V_70 ( V_71 ) ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
V_2 -> V_101 -- ;
if ( V_2 -> V_101 ) {
F_55 ( F_3 ( V_2 ) , L_10
L_11 ) ;
if ( F_16 ( V_2 ) -> V_103 )
F_56 ( & V_2 -> V_104 ) ;
else
F_57 ( & V_2 -> V_104 ) ;
}
F_19 ( & V_2 -> V_45 , V_42 ) ;
return;
V_102:
F_19 ( & V_2 -> V_45 , V_42 ) ;
F_58 ( F_3 ( V_2 ) , L_12 , V_100 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_105 ) {
F_58 ( F_3 ( V_2 ) , L_13
L_14 ) ;
return;
}
F_60 ( & V_2 -> V_45 ) ;
F_27 ( F_29 ( & V_2 -> V_73 ) ) ;
V_2 -> V_101 ++ ;
if ( F_51 ( V_2 ) == NULL )
V_2 -> V_95 = 0 ;
F_61 ( & V_2 -> V_45 ) ;
if ( F_16 ( V_2 ) -> V_103 )
F_56 ( & V_2 -> V_104 ) ;
else
F_57 ( & V_2 -> V_104 ) ;
}
static T_11 F_62 ( int V_106 , void * V_107 )
{
T_7 V_108 ;
T_7 V_109 ;
int V_6 ;
int V_110 ;
struct V_111 * V_44 = V_107 ;
struct V_1 * V_2 ;
void T_8 * V_47 = V_44 -> V_47 ;
V_108 = F_25 ( V_47 + V_112 ) ;
V_109 = F_25 ( V_47 + V_113 ) ;
if ( F_63 ( V_108 == 0 && V_109 == 0 ) ) {
F_64 ( V_44 -> V_114 , L_15 ) ;
return V_115 ;
}
while ( V_108 ) {
V_6 = F_65 ( V_108 ) - 1 ;
V_110 = V_6 ;
V_2 = & V_44 -> V_116 [ V_110 ] ;
F_60 ( & V_2 -> V_45 ) ;
V_108 &= ~ ( 1 << V_6 ) ;
if ( F_66 ( V_6 , V_47 + V_117 ) ) {
F_67 ( F_3 ( V_2 ) ,
L_16 , V_110 ) ;
F_27 ( 1 ) ;
F_68 ( V_6 , V_47 + V_89 ) ;
} else {
if ( F_63 ( ! F_66 ( V_6 , V_47 +
V_118 ) ) ) {
F_64 ( F_3 ( V_2 ) ,
L_17 , V_110 ) ;
F_27 ( 1 ) ;
F_68 ( V_6 , V_47 + V_90 ) ;
} else {
if ( ! ( F_25 ( V_47 + V_55 +
V_56 * V_110 ) &
V_119 ) ) {
F_17 ( V_2 ) ;
}
F_68 ( V_6 , V_47 + V_90 ) ;
F_59 ( V_2 ) ;
}
}
F_61 ( & V_2 -> V_45 ) ;
}
while ( V_109 ) {
V_6 = F_65 ( V_109 ) - 1 ;
V_110 = V_6 + 32 ;
V_2 = & V_44 -> V_116 [ V_110 ] ;
F_60 ( & V_2 -> V_45 ) ;
V_109 &= ~ ( 1 << V_6 ) ;
if ( F_66 ( V_6 , V_47 + V_120 ) ) {
F_67 ( F_3 ( V_2 ) ,
L_16 , V_110 ) ;
F_27 ( 1 ) ;
F_68 ( V_6 , V_47 + V_91 ) ;
} else {
if ( F_63 ( ! F_66 ( V_6 , V_47 +
V_121 ) ) ) {
F_64 ( F_3 ( V_2 ) ,
L_17 , V_110 ) ;
F_68 ( V_6 , V_47 + V_92 ) ;
F_27 ( 1 ) ;
} else {
if ( ! ( F_25 ( V_47 + V_55 +
V_56 * V_110 ) &
V_119 ) ) {
F_17 ( V_2 ) ;
}
F_68 ( V_6 , V_47 + V_92 ) ;
F_59 ( V_2 ) ;
}
}
F_61 ( & V_2 -> V_45 ) ;
}
return V_115 ;
}
static int F_69 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
unsigned long V_42 ;
F_2 ( F_3 ( V_2 ) , L_18 ,
V_100 , V_2 -> V_39 ) ;
if ( V_36 -> V_122 > 1 )
return - V_123 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
F_50 ( V_2 , NULL ) ;
V_2 -> V_105 = 1 ;
F_70 ( V_36 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
return 1 ;
}
static void
F_71 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
int V_46 = V_2 -> V_39 ;
unsigned long V_42 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
F_22 ( 0x00000000U , V_2 -> V_44 -> V_47 + V_51 +
V_52 * V_46 ) ;
F_22 ( 0x00000000U , V_2 -> V_44 -> V_47 + V_48 +
V_49 * V_46 ) ;
V_2 -> V_105 = 0 ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
V_36 -> V_124 -> V_125 ( V_36 , V_126 , 0 ) ;
}
static T_12
F_72 ( struct V_127 * V_128 )
{
struct V_64 * V_72 = F_14 ( V_128 , struct V_64 ,
V_65 ) ;
struct V_1 * V_2 = F_13 ( V_128 -> V_36 ) ;
unsigned long V_42 ;
T_12 V_129 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
V_129 = F_73 ( V_128 ) ;
F_40 ( V_2 , V_72 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
return V_129 ;
}
static struct V_127 *
F_74 ( struct V_35 * V_36 , T_9 V_130 , T_9 V_131 ,
T_2 V_132 , unsigned long V_42 )
{
struct V_3 * V_4 ;
struct V_64 * V_72 ;
unsigned long V_133 ;
struct V_1 * V_2 = F_13 ( V_36 ) ;
int V_134 ;
T_7 V_135 = F_15 ( V_2 ) -> V_94 ;
int V_22 ;
F_18 ( & V_2 -> V_45 , V_133 ) ;
F_2 ( F_3 ( V_2 ) ,
L_19 ,
V_100 , V_2 -> V_39 , V_131 , V_130 , V_132 ) ;
if ( V_42 & V_136 )
V_135 |= V_137 ;
V_134 = V_132 >> V_138 ;
if ( ( V_134 << V_138 ) < V_132 )
V_134 ++ ;
V_4 = F_75 ( & V_2 -> V_44 -> V_20 , V_134 ) ;
if ( V_4 == NULL )
goto V_102;
V_22 = F_76 (
& V_2 -> V_44 -> V_20 , V_4 , V_131 , V_132 , V_130 ,
F_15 ( V_2 ) -> V_139 ,
V_135 ) ;
if ( V_22 )
goto V_102;
F_77 ( F_1 ( V_2 , V_4 ) ) ;
V_72 = F_28 ( V_2 ) ;
V_72 -> V_4 = V_4 ;
V_72 -> V_42 = V_42 ;
V_72 -> V_65 . V_140 = F_72 ;
F_19 ( & V_2 -> V_45 , V_133 ) ;
return & V_72 -> V_65 ;
V_102:
F_19 ( & V_2 -> V_45 , V_133 ) ;
return NULL ;
}
static struct V_127 *
F_78 ( struct V_35 * V_36 , struct V_141 * V_142 ,
unsigned int V_69 , enum V_143 V_144 ,
unsigned long V_42 , void * V_145 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
struct V_3 * V_4 ;
struct V_64 * V_72 ;
const struct V_37 * V_146 ;
struct V_141 * V_68 ;
int V_147 = 0 ;
int V_132 ;
int V_6 ;
T_7 V_148 = F_15 ( V_2 ) -> V_139 ;
T_7 V_149 = F_15 ( V_2 ) -> V_150 ;
T_7 V_135 = F_15 ( V_2 ) -> V_94 ;
T_7 V_93 ;
unsigned long V_133 ;
int V_22 ;
if ( ! V_142 )
goto V_29;
if ( F_79 ( V_142 ) == 0 )
goto V_29;
F_18 ( & V_2 -> V_45 , V_133 ) ;
F_2 ( F_3 ( V_2 ) , L_20 ,
V_100 , V_69 , V_144 ) ;
if ( V_42 & V_136 )
V_135 |= V_137 ;
V_146 = F_15 ( V_2 ) ;
V_93 = V_146 -> V_93 ;
V_148 |= V_2 -> V_149 ;
V_135 |= V_2 -> V_149 ;
V_149 |= V_2 -> V_149 ;
if ( V_144 == V_151 ) {
T_7 V_152 = V_153 |
V_154 ;
V_93 |= V_155 ;
V_148 |= V_152 ;
V_135 |= V_152 ;
V_149 |= V_152 ;
} else if ( V_144 == V_156 ) {
T_7 V_157 = V_158 |
V_159 ;
V_93 |= V_160 ;
V_148 |= V_157 ;
V_135 |= V_157 ;
V_149 |= V_157 ;
} else
goto V_161;
F_80 (sgl, sg, sg_len, i) {
unsigned int V_162 ;
V_132 = F_79 ( V_68 ) ;
if ( V_132 <= V_163 ) {
V_147 ++ ;
continue;
}
V_162 = V_132 >> V_138 ;
if ( ( V_162 << V_138 ) < V_132 )
V_162 ++ ;
V_147 += V_162 ;
}
F_81 ( L_21 , V_147 ) ;
V_4 = F_75 ( & V_2 -> V_44 -> V_20 , V_147 ) ;
if ( V_4 == NULL )
goto V_164;
V_22 = F_82 ( & V_2 -> V_44 -> V_20 , V_4 , V_142 , V_69 ,
V_2 -> V_165 ,
V_148 ,
V_149 ,
V_135 ,
V_144 , V_137 ) ;
if ( V_22 )
goto V_166;
F_77 ( F_1 ( V_2 , V_4 ) ) ;
V_72 = F_28 ( V_2 ) ;
V_72 -> V_96 = V_93 ;
V_72 -> V_97 = V_4 -> V_7 ;
V_72 -> V_167 = V_144 ;
V_72 -> V_42 = V_42 ;
V_72 -> V_65 . V_140 = F_72 ;
V_72 -> V_4 = V_4 ;
F_19 ( & V_2 -> V_45 , V_133 ) ;
return & V_72 -> V_65 ;
V_166:
V_164:
V_161:
F_19 ( & V_2 -> V_45 , V_133 ) ;
V_29:
return NULL ;
}
static enum V_168
F_83 ( struct V_35 * V_36 , T_12 V_129 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
enum V_168 V_22 ;
V_22 = F_84 ( V_36 , V_129 , V_170 ) ;
if ( V_22 == V_171 )
return V_22 ;
F_85 ( V_170 , F_43 ( V_36 ) ) ;
if ( V_22 == V_172 && V_2 -> V_85 )
V_22 = V_173 ;
return V_22 ;
}
static void
F_86 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
unsigned long V_42 ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
if ( ! V_2 -> V_95 )
F_51 ( V_2 ) ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
}
static void F_87 ( struct V_35 * V_36 ,
struct V_174 * V_93 )
{
struct V_1 * V_2 = F_13 ( V_36 ) ;
T_9 V_165 ;
enum V_175 V_176 ;
T_7 V_177 ;
T_7 V_149 = 0 ;
int V_6 = 0 ;
if ( V_93 -> V_144 == V_156 ) {
V_165 = V_93 -> V_8 ;
V_176 = V_93 -> V_178 ;
V_177 = V_93 -> V_179 ;
} else if ( V_93 -> V_144 == V_151 ) {
V_165 = V_93 -> V_9 ;
V_176 = V_93 -> V_180 ;
V_177 = V_93 -> V_181 ;
} else {
F_58 ( F_3 ( V_2 ) , L_22 ) ;
return;
}
F_55 ( F_3 ( V_2 ) , L_23 ,
V_176 ) ;
switch ( V_176 ) {
case V_182 :
V_149 |=
V_183 |
V_184 ;
while ( V_6 < F_88 ( V_185 ) ) {
if ( V_185 [ V_6 ] . V_186 <= V_177 )
break;
V_6 ++ ;
}
break;
case V_187 :
V_149 |=
V_188 |
V_189 ;
while ( V_6 < F_88 ( V_185 ) ) {
if ( V_185 [ V_6 ] . V_190 <= V_177 )
break;
V_6 ++ ;
}
break;
case V_191 :
V_149 |=
V_192 |
V_193 ;
while ( V_6 < F_88 ( V_185 ) ) {
if ( V_185 [ V_6 ] . V_194 <= V_177 )
break;
V_6 ++ ;
}
break;
default:
F_58 ( F_3 ( V_2 ) ,
L_24 ) ;
return;
}
V_149 |= V_185 [ V_6 ] . V_195 ;
F_55 ( F_3 ( V_2 ) ,
L_25 ,
V_185 [ V_6 ] . V_186 , V_176 , V_177 ) ;
V_2 -> V_165 = V_165 ;
V_2 -> V_149 = V_149 ;
}
static int
F_89 ( struct V_35 * V_36 , enum V_196 V_197 ,
unsigned long V_198 )
{
unsigned long V_42 ;
struct V_1 * V_2 = F_13 ( V_36 ) ;
struct V_64 * V_72 ;
void T_8 * V_47 = V_2 -> V_44 -> V_47 ;
if ( V_197 == V_199 ) {
struct V_174 * V_93 =
(struct V_174 * ) V_198 ;
F_87 ( V_36 , V_93 ) ;
return 0 ;
}
if ( V_197 == V_200 ) {
F_46 ( V_36 ) ;
return 0 ;
}
if ( V_197 == V_201 ) {
F_48 ( V_36 ) ;
return 0 ;
}
if ( V_197 != V_126 )
return - V_202 ;
F_46 ( V_36 ) ;
F_18 ( & V_2 -> V_45 , V_42 ) ;
if ( V_2 -> V_39 < 32 ) {
F_22 ( 1 << V_2 -> V_39 , V_47 + V_89 ) ;
F_22 ( 1 << V_2 -> V_39 , V_47 + V_90 ) ;
} else {
F_22 ( 1 << ( V_2 -> V_39 - 32 ) , V_47 +
V_91 ) ;
F_22 ( 1 << ( V_2 -> V_39 - 32 ) , V_47 +
V_92 ) ;
}
F_17 ( V_2 ) ;
while ( ( V_72 = F_38 ( V_2 ) ) ) {
F_54 ( & V_2 -> V_44 -> V_20 , & V_72 -> V_4 ) ;
F_39 ( V_72 ) ;
F_35 ( V_2 , V_72 ) ;
}
while ( ( V_72 = F_41 ( V_2 ) ) ) {
F_54 ( & V_2 -> V_44 -> V_20 , & V_72 -> V_4 ) ;
F_39 ( V_72 ) ;
F_35 ( V_2 , V_72 ) ;
}
V_2 -> V_101 = 0 ;
V_2 -> V_95 = 0 ;
F_19 ( & V_2 -> V_45 , V_42 ) ;
return 0 ;
}
void F_90 ( struct V_203 * V_204 , const int * V_205 ,
struct V_111 * V_44 )
{
int V_206 ;
int V_6 = 0 ;
struct V_1 * V_2 ;
F_31 ( & V_204 -> V_207 ) ;
for ( V_206 = 0 ; V_205 [ V_206 ] != - 1 ; V_206 += 2 ) {
for ( V_6 = V_205 [ V_206 ] ; V_6 <= V_205 [ V_206 + 1 ] ; V_6 ++ ) {
V_2 = & V_44 -> V_116 [ V_6 ] ;
V_2 -> V_44 = V_44 ;
V_2 -> V_36 . V_124 = V_204 ;
V_2 -> V_39 = V_6 ;
F_91 ( & V_2 -> V_45 ) ;
V_2 -> V_101 = 0 ;
V_2 -> V_95 = 0 ;
F_31 ( & V_2 -> free ) ;
F_31 ( & V_2 -> V_73 ) ;
F_31 ( & V_2 -> V_75 ) ;
F_92 ( & V_2 -> V_104 , F_52 ,
( unsigned long ) V_2 ) ;
F_36 ( & V_2 -> V_36 . V_208 ,
& V_204 -> V_207 ) ;
}
}
}
static int T_5 F_93 ( struct V_209 * V_210 )
{
int V_102 = 0 ;
struct V_111 * V_44 ;
int V_106 ;
struct V_211 * V_212 ;
V_212 = F_94 ( V_210 , V_213 , 0 ) ;
if ( ! V_212 )
return - V_214 ;
if ( F_95 ( & V_210 -> V_114 ,
V_212 -> V_215 ,
F_96 ( V_212 ) ,
V_210 -> V_114 . V_216 -> V_217 ) == NULL )
return - V_218 ;
V_44 = F_97 ( & V_210 -> V_114 ,
F_98 ( sizeof( struct V_111 ) , 4 ) +
V_28 *
sizeof( struct V_1 ) ,
V_26 ) ;
if ( ! V_44 )
return - V_218 ;
V_44 -> V_116 = ( ( void * ) V_44 ) + F_98 ( sizeof( struct V_111 ) , 4 ) ;
V_44 -> V_47 = F_99 ( & V_210 -> V_114 , V_212 -> V_215 , F_96 ( V_212 ) ) ;
if ( ! V_44 -> V_47 )
return - V_218 ;
V_44 -> V_114 = & V_210 -> V_114 ;
F_91 ( & V_44 -> V_18 . V_45 ) ;
V_44 -> V_18 . V_16 = 0 ;
F_100 ( V_17 , V_44 ) ;
V_106 = F_101 ( V_210 , 0 ) ;
if ( V_106 < 0 )
return V_106 ;
V_102 = F_102 ( & V_210 -> V_114 , V_106 , F_62 , V_219 ,
L_26 , V_44 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_103 ( & V_44 -> V_20 , & V_210 -> V_114 ,
sizeof( struct V_3 ) ,
32 ) ;
if ( V_102 )
return V_102 ;
F_90 ( & V_44 -> V_220 , V_221 ,
V_44 ) ;
F_104 ( V_44 -> V_220 . V_222 ) ;
F_105 ( V_223 , V_44 -> V_220 . V_222 ) ;
V_44 -> V_220 . V_224 = F_69 ;
V_44 -> V_220 . V_225 = F_71 ;
V_44 -> V_220 . V_226 = F_78 ;
V_44 -> V_220 . V_227 = F_83 ;
V_44 -> V_220 . V_228 = F_86 ;
V_44 -> V_220 . V_125 = F_89 ;
V_44 -> V_220 . V_114 = & V_210 -> V_114 ;
V_102 = F_106 ( & V_44 -> V_220 ) ;
if ( V_102 )
goto V_229;
F_90 ( & V_44 -> V_230 , V_231 ,
V_44 ) ;
F_104 ( V_44 -> V_230 . V_222 ) ;
F_105 ( V_232 , V_44 -> V_230 . V_222 ) ;
V_44 -> V_230 . V_224 = F_69 ;
V_44 -> V_230 . V_225 = F_71 ;
V_44 -> V_230 . V_233 = F_74 ;
V_44 -> V_230 . V_227 = F_83 ;
V_44 -> V_230 . V_228 = F_86 ;
V_44 -> V_230 . V_125 = F_89 ;
V_44 -> V_230 . V_114 = & V_210 -> V_114 ;
V_44 -> V_230 . V_234 = 2 ;
V_102 = F_106 ( & V_44 -> V_230 ) ;
if ( V_102 )
goto V_235;
F_107 ( V_210 , V_44 ) ;
F_108 ( & V_210 -> V_114 , L_27 ,
( T_7 ) V_44 -> V_47 ) ;
return V_102 ;
V_235:
F_109 ( & V_44 -> V_220 ) ;
V_229:
F_110 ( & V_44 -> V_20 ) ;
return V_102 ;
}
static int T_6 F_111 ( struct V_209 * V_210 )
{
struct V_111 * V_44 = F_112 ( V_210 ) ;
F_109 ( & V_44 -> V_230 ) ;
F_109 ( & V_44 -> V_220 ) ;
F_110 ( & V_44 -> V_20 ) ;
return 0 ;
}
int T_5 F_113 ( void )
{
return F_114 ( & V_236 , F_93 ) ;
}
void T_6 F_115 ( void )
{
F_116 ( & V_236 ) ;
}
