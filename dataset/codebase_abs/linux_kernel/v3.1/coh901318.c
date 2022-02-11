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
static int F_4 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
V_13 -> V_14 = V_12 -> V_15 ;
return 0 ;
}
static int F_5 ( struct V_13 * V_13 , char T_1 * V_16 ,
T_2 V_17 , T_3 * V_18 )
{
T_4 V_19 = V_20 -> V_21 . V_19 ;
int V_22 = V_20 -> V_23 . V_24 ;
int V_6 ;
int V_25 = 0 ;
char * V_26 ;
char * V_27 ;
int V_28 ;
V_26 = F_6 ( 4 * 1024 , V_29 ) ;
if ( V_26 == NULL )
goto V_30;
V_27 = V_26 ;
V_27 += sprintf ( V_27 , L_3 ) ;
for ( V_6 = 0 ; V_6 < V_20 -> V_31 -> V_32 ; V_6 ++ )
if ( V_19 & ( 1 << V_6 ) )
V_27 += sprintf ( V_27 , L_4 , V_6 ) ;
V_27 += sprintf ( V_27 , L_5 , V_22 ) ;
V_28 = V_27 - V_26 ;
if ( * V_18 > V_28 )
goto V_33;
if ( V_17 > V_28 - * V_18 )
V_17 = V_28 - * V_18 ;
if ( F_7 ( V_16 , V_26 + * V_18 , V_17 ) )
V_25 = - V_34 ;
V_25 = V_17 ;
* V_18 += V_17 ;
V_33:
F_8 ( V_26 ) ;
return V_25 ;
V_30:
return 0 ;
}
static int T_5 F_9 ( void )
{
V_35 = F_10 ( L_6 , NULL ) ;
( void ) F_11 ( L_7 ,
V_36 | V_37 ,
V_35 , NULL ,
& V_38 ) ;
return 0 ;
}
static void T_6 F_12 ( void )
{
F_13 ( V_35 ) ;
}
static inline struct V_1 * F_14 ( struct V_39 * V_40 )
{
return F_15 ( V_40 , struct V_1 , V_40 ) ;
}
static inline T_7
F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 )
return V_2 -> V_41 ;
return V_2 -> V_42 -> V_31 -> V_43 [ V_2 -> V_44 ] . V_45 ;
}
static inline const struct V_46 *
F_17 ( struct V_1 * V_2 )
{
return & V_2 -> V_42 -> V_31 -> V_43 [ V_2 -> V_44 ] . V_47 ;
}
static inline const struct V_48 *
F_18 ( struct V_1 * V_2 )
{
return & V_2 -> V_42 -> V_31 -> V_43 [ V_2 -> V_44 ] ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned long V_49 ;
struct V_50 * V_21 = & V_2 -> V_42 -> V_21 ;
F_20 ( & V_21 -> V_51 , V_49 ) ;
V_21 -> V_19 &= ~ ( 1ULL << V_2 -> V_44 ) ;
if ( ! V_21 -> V_19 ) {
V_2 -> V_42 -> V_31 -> V_52 ( V_2 -> V_42 -> V_53 ,
false ) ;
}
F_21 ( & V_21 -> V_51 , V_49 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned long V_49 ;
struct V_50 * V_21 = & V_2 -> V_42 -> V_21 ;
F_20 ( & V_21 -> V_51 , V_49 ) ;
if ( ! V_21 -> V_19 ) {
V_2 -> V_42 -> V_31 -> V_52 ( V_2 -> V_42 -> V_53 ,
true ) ;
}
V_21 -> V_19 |= ( 1ULL << V_2 -> V_44 ) ;
F_21 ( & V_21 -> V_51 , V_49 ) ;
}
static inline int F_23 ( struct V_1 * V_2 , T_8 V_7 )
{
int V_54 = V_2 -> V_44 ;
void T_9 * V_55 = V_2 -> V_42 -> V_55 ;
F_24 ( V_7 ,
V_55 + V_56 +
V_57 * V_54 ) ;
return 0 ;
}
static inline int F_25 ( struct V_1 * V_2 , T_8 V_58 )
{
int V_54 = V_2 -> V_44 ;
void T_9 * V_55 = V_2 -> V_42 -> V_55 ;
F_24 ( V_58 ,
V_55 + V_59 +
V_60 * V_54 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_8 V_61 ;
int V_54 = V_2 -> V_44 ;
void T_9 * V_55 = V_2 -> V_42 -> V_55 ;
F_22 ( V_2 ) ;
V_61 = F_27 ( V_55 + V_59 +
V_60 * V_54 ) ;
V_61 |= V_62 ;
F_24 ( V_61 , V_55 + V_59 +
V_60 * V_54 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_54 = V_2 -> V_44 ;
void T_9 * V_55 = V_2 -> V_42 -> V_55 ;
F_29 ( F_27 ( V_55 + V_63 +
V_64 * V_54 ) &
V_65 ) ;
F_24 ( V_4 -> V_8 ,
V_55 + V_66 +
V_67 * V_54 ) ;
F_24 ( V_4 -> V_9 , V_55 +
V_68 +
V_69 * V_54 ) ;
F_24 ( V_4 -> V_10 , V_55 + V_70 +
V_71 * V_54 ) ;
F_24 ( V_4 -> V_7 , V_55 + V_56 +
V_57 * V_54 ) ;
return 0 ;
}
static T_10
F_30 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
T_10 V_74 = V_2 -> V_40 . V_74 ;
if ( ++ V_74 < 0 )
V_74 = 1 ;
V_2 -> V_40 . V_74 = V_74 ;
V_73 -> V_75 . V_74 = V_74 ;
return V_74 ;
}
static struct V_72 *
F_31 ( struct V_1 * V_2 )
{
struct V_72 * V_75 ;
if ( F_32 ( & V_2 -> free ) ) {
V_75 = F_33 ( sizeof( struct V_72 ) , V_76 ) ;
if ( V_75 == NULL )
goto V_33;
F_34 ( & V_75 -> V_77 ) ;
F_35 ( & V_75 -> V_75 , & V_2 -> V_40 ) ;
} else {
V_75 = F_36 ( & V_2 -> free ,
struct V_72 ,
V_77 ) ;
F_37 ( & V_75 -> V_77 ) ;
V_75 -> V_78 = NULL ;
V_75 -> V_79 = 0 ;
V_75 -> V_75 . V_80 = NULL ;
V_75 -> V_75 . V_81 = NULL ;
}
V_33:
return V_75 ;
}
static void
F_38 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
F_39 ( & V_73 -> V_77 , & V_2 -> free ) ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_72 * V_75 )
{
F_39 ( & V_75 -> V_77 , & V_2 -> V_82 ) ;
}
static struct V_72 *
F_41 ( struct V_1 * V_2 )
{
struct V_72 * V_83 ;
if ( F_32 ( & V_2 -> V_82 ) )
return NULL ;
V_83 = F_36 ( & V_2 -> V_82 ,
struct V_72 ,
V_77 ) ;
return V_83 ;
}
static void
F_42 ( struct V_72 * V_73 )
{
F_37 ( & V_73 -> V_77 ) ;
}
static void
F_43 ( struct V_1 * V_2 , struct V_72 * V_75 )
{
F_39 ( & V_75 -> V_77 , & V_2 -> V_84 ) ;
}
static struct V_72 *
F_44 ( struct V_1 * V_2 )
{
struct V_72 * V_83 ;
if ( F_32 ( & V_2 -> V_84 ) )
return NULL ;
V_83 = F_36 ( & V_2 -> V_84 ,
struct V_72 ,
V_77 ) ;
return V_83 ;
}
static inline T_8 F_45 ( struct V_3 * V_85 )
{
struct V_3 * V_4 = V_85 ;
T_8 V_86 = 0 ;
while ( V_4 ) {
V_86 += V_4 -> V_7 & V_87 ;
V_4 = V_4 -> V_11 ;
}
return V_86 ;
}
static T_8 F_46 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_14 ( V_40 ) ;
struct V_72 * V_73 ;
struct V_88 * V_89 ;
unsigned long V_49 ;
T_8 V_90 = 0 ;
int V_6 = 0 ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
F_47 (pos, &cohc->active) {
V_73 = F_48 ( V_89 , struct V_72 , V_77 ) ;
if ( V_6 == 0 ) {
struct V_3 * V_4 ;
T_7 V_91 ;
V_90 = F_27 ( V_2 -> V_42 -> V_55 +
V_56 +
V_57 * V_2 -> V_44 ) &
V_87 ;
V_91 = F_27 ( V_2 -> V_42 -> V_55 +
V_70 +
V_71 *
V_2 -> V_44 ) &
~ V_92 ;
if ( ! V_91 )
continue;
V_4 = V_73 -> V_4 ;
while ( V_4 && V_4 -> V_10 != V_91 )
V_4 = V_4 -> V_11 ;
if ( V_4 )
V_4 = V_4 -> V_11 ;
V_90 += F_45 ( V_4 ) ;
} else {
V_90 += F_45 ( V_73 -> V_4 ) ;
}
V_6 ++ ;
}
F_47 (pos, &cohc->queue) {
V_73 = F_48 ( V_89 , struct V_72 , V_77 ) ;
V_90 += F_45 ( V_73 -> V_4 ) ;
}
F_21 ( & V_2 -> V_51 , V_49 ) ;
return V_90 ;
}
static void F_49 ( struct V_39 * V_40 )
{
T_8 V_61 ;
unsigned long V_49 ;
struct V_1 * V_2 = F_14 ( V_40 ) ;
int V_54 = V_2 -> V_44 ;
void T_9 * V_55 = V_2 -> V_42 -> V_55 ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
V_61 = F_27 ( V_55 + V_59 +
V_60 * V_54 ) ;
if ( ( V_61 & V_93 ) == 0 &&
( V_61 & V_62 ) )
V_2 -> V_94 = 1 ;
V_61 &= ~ V_62 ;
F_24 ( V_61 , V_55 + V_59 +
V_60 * V_54 ) ;
F_24 ( V_61 , V_55 + V_59 +
V_60 * V_54 ) ;
while ( F_27 ( V_55 + V_63 + V_64 *
V_54 ) & V_65 )
F_50 () ;
if ( ( F_27 ( V_55 + V_56 + V_57 *
V_54 ) & V_87 ) > 0 )
V_2 -> V_94 = 1 ;
F_19 ( V_2 ) ;
F_21 ( & V_2 -> V_51 , V_49 ) ;
}
static void F_51 ( struct V_39 * V_40 )
{
T_8 V_61 ;
unsigned long V_49 ;
struct V_1 * V_2 = F_14 ( V_40 ) ;
int V_54 = V_2 -> V_44 ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_94 ) {
V_61 = F_27 ( V_2 -> V_42 -> V_55 + V_59 +
V_60 * V_54 ) ;
V_61 |= V_62 ;
F_24 ( V_61 , V_2 -> V_42 -> V_55 + V_59 +
V_60 * V_54 ) ;
V_2 -> V_94 = 0 ;
}
F_21 ( & V_2 -> V_51 , V_49 ) ;
}
bool F_52 ( struct V_39 * V_40 , void * V_95 )
{
unsigned int V_96 = ( unsigned int ) V_95 ;
if ( V_96 == F_14 ( V_40 ) -> V_44 )
return true ;
return false ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
unsigned long V_49 ;
const struct V_46 * V_97 ;
int V_54 = V_2 -> V_44 ;
void T_9 * V_55 = V_2 -> V_42 -> V_55 ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
if ( V_47 )
V_97 = V_47 ;
else
V_97 = & V_2 -> V_42 -> V_31 -> V_43 [ V_54 ] . V_47 ;
if ( V_54 < 32 ) {
F_24 ( 1 << V_54 , V_55 + V_98 ) ;
F_24 ( 1 << V_54 , V_55 + V_99 ) ;
} else {
F_24 ( 1 << ( V_54 - 32 ) , V_55 +
V_100 ) ;
F_24 ( 1 << ( V_54 - 32 ) , V_55 +
V_101 ) ;
}
F_25 ( V_2 , V_97 -> V_102 ) ;
F_23 ( V_2 , V_97 -> V_103 ) ;
F_21 ( & V_2 -> V_51 , V_49 ) ;
return 0 ;
}
static struct V_72 * F_54 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
V_73 = F_44 ( V_2 ) ;
if ( V_73 != NULL ) {
F_42 ( V_73 ) ;
V_2 -> V_104 = 1 ;
F_40 ( V_2 , V_73 ) ;
F_25 ( V_2 , V_73 -> V_105 ) ;
F_23 ( V_2 , V_73 -> V_106 ) ;
F_28 ( V_2 , V_73 -> V_4 ) ;
F_26 ( V_2 ) ;
}
return V_73 ;
}
static void F_55 ( unsigned long V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_107 ;
struct V_72 * V_108 ;
unsigned long V_49 ;
T_11 V_80 ;
void * V_81 ;
F_2 ( F_3 ( V_2 ) , L_8
L_9 , V_109 ,
V_2 -> V_44 , V_2 -> V_110 ) ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
V_108 = F_41 ( V_2 ) ;
if ( V_108 == NULL )
goto V_111;
V_80 = V_108 -> V_75 . V_80 ;
V_81 = V_108 -> V_75 . V_81 ;
V_2 -> V_112 = V_108 -> V_75 . V_74 ;
F_56 ( & V_2 -> V_42 -> V_23 , & V_108 -> V_4 ) ;
F_42 ( V_108 ) ;
F_38 ( V_2 , V_108 ) ;
F_21 ( & V_2 -> V_51 , V_49 ) ;
if ( V_80 )
V_80 ( V_81 ) ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
V_2 -> V_110 -- ;
if ( V_2 -> V_110 ) {
F_57 ( F_3 ( V_2 ) , L_10
L_11 ) ;
if ( F_18 ( V_2 ) -> V_113 )
F_58 ( & V_2 -> V_114 ) ;
else
F_59 ( & V_2 -> V_114 ) ;
}
F_21 ( & V_2 -> V_51 , V_49 ) ;
return;
V_111:
F_21 ( & V_2 -> V_51 , V_49 ) ;
F_60 ( F_3 ( V_2 ) , L_12 , V_109 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_115 ) {
F_60 ( F_3 ( V_2 ) , L_13
L_14 ) ;
return;
}
F_62 ( & V_2 -> V_51 ) ;
F_29 ( F_32 ( & V_2 -> V_82 ) ) ;
V_2 -> V_110 ++ ;
if ( F_54 ( V_2 ) == NULL )
V_2 -> V_104 = 0 ;
F_63 ( & V_2 -> V_51 ) ;
if ( F_18 ( V_2 ) -> V_113 )
F_58 ( & V_2 -> V_114 ) ;
else
F_59 ( & V_2 -> V_114 ) ;
}
static T_12 F_64 ( int V_116 , void * V_117 )
{
T_8 V_118 ;
T_8 V_119 ;
int V_6 ;
int V_120 ;
struct V_121 * V_42 = V_117 ;
struct V_1 * V_2 ;
void T_9 * V_55 = V_42 -> V_55 ;
V_118 = F_27 ( V_55 + V_122 ) ;
V_119 = F_27 ( V_55 + V_123 ) ;
if ( F_65 ( V_118 == 0 && V_119 == 0 ) ) {
F_66 ( V_42 -> V_53 , L_15 ) ;
return V_124 ;
}
while ( V_118 ) {
V_6 = F_67 ( V_118 ) - 1 ;
V_120 = V_6 ;
V_2 = & V_42 -> V_125 [ V_120 ] ;
F_62 ( & V_2 -> V_51 ) ;
V_118 &= ~ ( 1 << V_6 ) ;
if ( F_68 ( V_6 , V_55 + V_126 ) ) {
F_69 ( F_3 ( V_2 ) ,
L_16 , V_120 ) ;
F_29 ( 1 ) ;
F_70 ( V_6 , V_55 + V_98 ) ;
} else {
if ( F_65 ( ! F_68 ( V_6 , V_55 +
V_127 ) ) ) {
F_66 ( F_3 ( V_2 ) ,
L_17 , V_120 ) ;
F_29 ( 1 ) ;
F_70 ( V_6 , V_55 + V_99 ) ;
} else {
if ( ! ( F_27 ( V_55 + V_63 +
V_64 * V_120 ) &
V_128 ) ) {
F_19 ( V_2 ) ;
}
F_70 ( V_6 , V_55 + V_99 ) ;
F_61 ( V_2 ) ;
}
}
F_63 ( & V_2 -> V_51 ) ;
}
while ( V_119 ) {
V_6 = F_67 ( V_119 ) - 1 ;
V_120 = V_6 + 32 ;
V_2 = & V_42 -> V_125 [ V_120 ] ;
F_62 ( & V_2 -> V_51 ) ;
V_119 &= ~ ( 1 << V_6 ) ;
if ( F_68 ( V_6 , V_55 + V_129 ) ) {
F_69 ( F_3 ( V_2 ) ,
L_16 , V_120 ) ;
F_29 ( 1 ) ;
F_70 ( V_6 , V_55 + V_100 ) ;
} else {
if ( F_65 ( ! F_68 ( V_6 , V_55 +
V_130 ) ) ) {
F_66 ( F_3 ( V_2 ) ,
L_17 , V_120 ) ;
F_70 ( V_6 , V_55 + V_101 ) ;
F_29 ( 1 ) ;
} else {
if ( ! ( F_27 ( V_55 + V_63 +
V_64 * V_120 ) &
V_128 ) ) {
F_19 ( V_2 ) ;
}
F_70 ( V_6 , V_55 + V_101 ) ;
F_61 ( V_2 ) ;
}
}
F_63 ( & V_2 -> V_51 ) ;
}
return V_124 ;
}
static int F_71 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_14 ( V_40 ) ;
unsigned long V_49 ;
F_2 ( F_3 ( V_2 ) , L_18 ,
V_109 , V_2 -> V_44 ) ;
if ( V_40 -> V_131 > 1 )
return - V_132 ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
F_53 ( V_2 , NULL ) ;
V_2 -> V_115 = 1 ;
V_2 -> V_112 = V_40 -> V_74 = 1 ;
F_21 ( & V_2 -> V_51 , V_49 ) ;
return 1 ;
}
static void
F_72 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_14 ( V_40 ) ;
int V_54 = V_2 -> V_44 ;
unsigned long V_49 ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
F_24 ( 0x00000000U , V_2 -> V_42 -> V_55 + V_59 +
V_60 * V_54 ) ;
F_24 ( 0x00000000U , V_2 -> V_42 -> V_55 + V_56 +
V_57 * V_54 ) ;
V_2 -> V_115 = 0 ;
F_21 ( & V_2 -> V_51 , V_49 ) ;
V_40 -> V_133 -> V_134 ( V_40 , V_135 , 0 ) ;
}
static T_10
F_73 ( struct V_136 * V_137 )
{
struct V_72 * V_73 = F_15 ( V_137 , struct V_72 ,
V_75 ) ;
struct V_1 * V_2 = F_14 ( V_137 -> V_40 ) ;
unsigned long V_49 ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
V_137 -> V_74 = F_30 ( V_2 , V_73 ) ;
F_43 ( V_2 , V_73 ) ;
F_21 ( & V_2 -> V_51 , V_49 ) ;
return V_137 -> V_74 ;
}
static struct V_136 *
F_74 ( struct V_39 * V_40 , T_7 V_138 , T_7 V_139 ,
T_2 V_140 , unsigned long V_49 )
{
struct V_3 * V_4 ;
struct V_72 * V_73 ;
unsigned long V_141 ;
struct V_1 * V_2 = F_14 ( V_40 ) ;
int V_142 ;
T_8 V_143 = F_17 ( V_2 ) -> V_103 ;
int V_25 ;
F_20 ( & V_2 -> V_51 , V_141 ) ;
F_2 ( F_3 ( V_2 ) ,
L_19 ,
V_109 , V_2 -> V_44 , V_139 , V_138 , V_140 ) ;
if ( V_49 & V_144 )
V_143 |= V_145 ;
V_142 = V_140 >> V_146 ;
if ( ( V_142 << V_146 ) < V_140 )
V_142 ++ ;
V_4 = F_75 ( & V_2 -> V_42 -> V_23 , V_142 ) ;
if ( V_4 == NULL )
goto V_111;
V_25 = F_76 (
& V_2 -> V_42 -> V_23 , V_4 , V_139 , V_140 , V_138 ,
F_17 ( V_2 ) -> V_147 ,
V_143 ) ;
if ( V_25 )
goto V_111;
F_77 ( F_1 ( V_2 , V_4 ) ) ;
V_73 = F_31 ( V_2 ) ;
V_73 -> V_4 = V_4 ;
V_73 -> V_49 = V_49 ;
V_73 -> V_75 . V_148 = F_73 ;
F_21 ( & V_2 -> V_51 , V_141 ) ;
return & V_73 -> V_75 ;
V_111:
F_21 ( & V_2 -> V_51 , V_141 ) ;
return NULL ;
}
static struct V_136 *
F_78 ( struct V_39 * V_40 , struct V_149 * V_150 ,
unsigned int V_79 , enum V_151 V_152 ,
unsigned long V_49 )
{
struct V_1 * V_2 = F_14 ( V_40 ) ;
struct V_3 * V_4 ;
struct V_72 * V_73 ;
const struct V_46 * V_153 ;
struct V_149 * V_78 ;
int V_154 = 0 ;
int V_140 ;
int V_6 ;
T_8 V_155 = F_17 ( V_2 ) -> V_147 ;
T_8 V_156 = F_17 ( V_2 ) -> V_157 ;
T_8 V_143 = F_17 ( V_2 ) -> V_103 ;
T_8 V_102 ;
unsigned long V_141 ;
int V_25 ;
if ( ! V_150 )
goto V_33;
if ( V_150 -> V_158 == 0 )
goto V_33;
F_20 ( & V_2 -> V_51 , V_141 ) ;
F_2 ( F_3 ( V_2 ) , L_20 ,
V_109 , V_79 , V_152 ) ;
if ( V_49 & V_144 )
V_143 |= V_145 ;
V_153 = F_17 ( V_2 ) ;
V_102 = V_153 -> V_102 ;
V_155 |= V_2 -> V_159 ;
V_143 |= V_2 -> V_159 ;
V_156 |= V_2 -> V_159 ;
if ( V_152 == V_160 ) {
T_8 V_161 = V_162 |
V_163 ;
V_102 |= V_164 ;
V_155 |= V_161 ;
V_143 |= V_161 ;
V_156 |= V_161 ;
} else if ( V_152 == V_165 ) {
T_8 V_166 = V_167 |
V_168 ;
V_102 |= V_169 ;
V_155 |= V_166 ;
V_143 |= V_166 ;
V_156 |= V_166 ;
} else
goto V_170;
F_79 (sgl, sg, sg_len, i) {
unsigned int V_171 ;
V_140 = F_80 ( V_78 ) ;
if ( V_140 <= V_172 ) {
V_154 ++ ;
continue;
}
V_171 = V_140 >> V_146 ;
if ( ( V_171 << V_146 ) < V_140 )
V_171 ++ ;
V_154 += V_171 ;
}
F_81 ( L_21 , V_154 ) ;
V_4 = F_75 ( & V_2 -> V_42 -> V_23 , V_154 ) ;
if ( V_4 == NULL )
goto V_173;
V_25 = F_82 ( & V_2 -> V_42 -> V_23 , V_4 , V_150 , V_79 ,
F_16 ( V_2 ) ,
V_155 ,
V_156 ,
V_143 ,
V_152 , V_145 ) ;
if ( V_25 )
goto V_174;
F_77 ( F_1 ( V_2 , V_4 ) ) ;
V_73 = F_31 ( V_2 ) ;
V_73 -> V_105 = V_102 ;
V_73 -> V_106 = V_4 -> V_7 ;
V_73 -> V_175 = V_152 ;
V_73 -> V_49 = V_49 ;
V_73 -> V_75 . V_148 = F_73 ;
V_73 -> V_4 = V_4 ;
F_21 ( & V_2 -> V_51 , V_141 ) ;
return & V_73 -> V_75 ;
V_174:
V_173:
V_170:
F_21 ( & V_2 -> V_51 , V_141 ) ;
V_33:
return NULL ;
}
static enum V_176
F_83 ( struct V_39 * V_40 , T_10 V_74 ,
struct V_177 * V_178 )
{
struct V_1 * V_2 = F_14 ( V_40 ) ;
T_10 V_179 ;
T_10 V_180 ;
int V_25 ;
V_180 = V_2 -> V_112 ;
V_179 = V_40 -> V_74 ;
V_25 = F_84 ( V_74 , V_180 , V_179 ) ;
F_85 ( V_178 , V_180 , V_179 ,
F_46 ( V_40 ) ) ;
if ( V_25 == V_181 && V_2 -> V_94 )
V_25 = V_182 ;
return V_25 ;
}
static void
F_86 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_14 ( V_40 ) ;
unsigned long V_49 ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
if ( ! V_2 -> V_104 )
F_54 ( V_2 ) ;
F_21 ( & V_2 -> V_51 , V_49 ) ;
}
static void F_87 ( struct V_39 * V_40 ,
struct V_183 * V_102 )
{
struct V_1 * V_2 = F_14 ( V_40 ) ;
T_7 V_184 ;
enum V_185 V_186 ;
T_8 V_187 ;
T_8 V_159 = 0 ;
int V_6 = 0 ;
if ( V_102 -> V_152 == V_165 ) {
V_184 = V_102 -> V_8 ;
V_186 = V_102 -> V_188 ;
V_187 = V_102 -> V_189 ;
} else if ( V_102 -> V_152 == V_160 ) {
V_184 = V_102 -> V_9 ;
V_186 = V_102 -> V_190 ;
V_187 = V_102 -> V_191 ;
} else {
F_60 ( F_3 ( V_2 ) , L_22 ) ;
return;
}
F_57 ( F_3 ( V_2 ) , L_23 ,
V_186 ) ;
switch ( V_186 ) {
case V_192 :
V_159 |=
V_193 |
V_194 ;
while ( V_6 < F_88 ( V_195 ) ) {
if ( V_195 [ V_6 ] . V_196 <= V_187 )
break;
V_6 ++ ;
}
break;
case V_197 :
V_159 |=
V_198 |
V_199 ;
while ( V_6 < F_88 ( V_195 ) ) {
if ( V_195 [ V_6 ] . V_200 <= V_187 )
break;
V_6 ++ ;
}
break;
case V_201 :
V_159 |=
V_202 |
V_203 ;
while ( V_6 < F_88 ( V_195 ) ) {
if ( V_195 [ V_6 ] . V_204 <= V_187 )
break;
V_6 ++ ;
}
break;
default:
F_60 ( F_3 ( V_2 ) ,
L_24 ) ;
return;
}
V_159 |= V_195 [ V_6 ] . V_205 ;
F_57 ( F_3 ( V_2 ) ,
L_25 ,
V_195 [ V_6 ] . V_196 , V_186 , V_187 ) ;
V_2 -> V_41 = V_184 ;
V_2 -> V_159 = V_159 ;
}
static int
F_89 ( struct V_39 * V_40 , enum V_206 V_207 ,
unsigned long V_208 )
{
unsigned long V_49 ;
struct V_1 * V_2 = F_14 ( V_40 ) ;
struct V_72 * V_73 ;
void T_9 * V_55 = V_2 -> V_42 -> V_55 ;
if ( V_207 == V_209 ) {
struct V_183 * V_102 =
(struct V_183 * ) V_208 ;
F_87 ( V_40 , V_102 ) ;
return 0 ;
}
if ( V_207 == V_210 ) {
F_49 ( V_40 ) ;
return 0 ;
}
if ( V_207 == V_211 ) {
F_51 ( V_40 ) ;
return 0 ;
}
if ( V_207 != V_135 )
return - V_212 ;
F_49 ( V_40 ) ;
F_20 ( & V_2 -> V_51 , V_49 ) ;
if ( V_2 -> V_44 < 32 ) {
F_24 ( 1 << V_2 -> V_44 , V_55 + V_98 ) ;
F_24 ( 1 << V_2 -> V_44 , V_55 + V_99 ) ;
} else {
F_24 ( 1 << ( V_2 -> V_44 - 32 ) , V_55 +
V_100 ) ;
F_24 ( 1 << ( V_2 -> V_44 - 32 ) , V_55 +
V_101 ) ;
}
F_19 ( V_2 ) ;
while ( ( V_73 = F_41 ( V_2 ) ) ) {
F_56 ( & V_2 -> V_42 -> V_23 , & V_73 -> V_4 ) ;
F_42 ( V_73 ) ;
F_38 ( V_2 , V_73 ) ;
}
while ( ( V_73 = F_44 ( V_2 ) ) ) {
F_56 ( & V_2 -> V_42 -> V_23 , & V_73 -> V_4 ) ;
F_42 ( V_73 ) ;
F_38 ( V_2 , V_73 ) ;
}
V_2 -> V_110 = 0 ;
V_2 -> V_104 = 0 ;
F_21 ( & V_2 -> V_51 , V_49 ) ;
return 0 ;
}
void F_90 ( struct V_213 * V_214 , const int * V_215 ,
struct V_121 * V_42 )
{
int V_216 ;
int V_6 = 0 ;
struct V_1 * V_2 ;
F_34 ( & V_214 -> V_217 ) ;
for ( V_216 = 0 ; V_215 [ V_216 ] != - 1 ; V_216 += 2 ) {
for ( V_6 = V_215 [ V_216 ] ; V_6 <= V_215 [ V_216 + 1 ] ; V_6 ++ ) {
V_2 = & V_42 -> V_125 [ V_6 ] ;
V_2 -> V_42 = V_42 ;
V_2 -> V_40 . V_133 = V_214 ;
V_2 -> V_44 = V_6 ;
F_91 ( & V_2 -> V_51 ) ;
V_2 -> V_110 = 0 ;
V_2 -> V_104 = 0 ;
F_34 ( & V_2 -> free ) ;
F_34 ( & V_2 -> V_82 ) ;
F_34 ( & V_2 -> V_84 ) ;
F_92 ( & V_2 -> V_114 , F_55 ,
( unsigned long ) V_2 ) ;
F_39 ( & V_2 -> V_40 . V_218 ,
& V_214 -> V_217 ) ;
}
}
}
static int T_5 F_93 ( struct V_219 * V_220 )
{
int V_111 = 0 ;
struct V_221 * V_222 ;
struct V_121 * V_42 ;
int V_116 ;
struct V_223 * V_224 ;
V_224 = F_94 ( V_220 , V_225 , 0 ) ;
if ( ! V_224 )
goto V_226;
if ( F_95 ( V_224 -> V_227 ,
F_96 ( V_224 ) ,
V_220 -> V_53 . V_228 -> V_229 ) == NULL ) {
V_111 = - V_132 ;
goto V_230;
}
V_222 = V_220 -> V_53 . V_231 ;
if ( ! V_222 )
goto V_232;
V_42 = F_6 ( F_97 ( sizeof( struct V_121 ) , 4 ) +
V_222 -> V_32 *
sizeof( struct V_1 ) ,
V_29 ) ;
if ( ! V_42 )
goto V_233;
V_42 -> V_125 = ( ( void * ) V_42 ) + F_97 ( sizeof( struct V_121 ) , 4 ) ;
V_42 -> V_55 = F_98 ( V_224 -> V_227 , F_96 ( V_224 ) ) ;
if ( ! V_42 -> V_55 ) {
V_111 = - V_234 ;
goto V_235;
}
V_42 -> V_53 = & V_220 -> V_53 ;
V_42 -> V_31 = V_222 ;
F_91 ( & V_42 -> V_21 . V_51 ) ;
V_42 -> V_21 . V_19 = 0 ;
F_99 ( V_20 , V_42 ) ;
F_100 ( V_220 , V_42 ) ;
V_116 = F_101 ( V_220 , 0 ) ;
if ( V_116 < 0 )
goto V_236;
V_111 = F_102 ( V_116 , F_64 , V_237 ,
L_26 , V_42 ) ;
if ( V_111 ) {
F_69 ( & V_220 -> V_53 ,
L_27 ) ;
goto V_238;
}
V_111 = F_103 ( & V_42 -> V_23 , & V_220 -> V_53 ,
sizeof( struct V_3 ) ,
32 ) ;
if ( V_111 )
goto V_239;
F_90 ( & V_42 -> V_240 , V_42 -> V_31 -> V_241 ,
V_42 ) ;
F_104 ( V_42 -> V_240 . V_242 ) ;
F_105 ( V_243 , V_42 -> V_240 . V_242 ) ;
V_42 -> V_240 . V_244 = F_71 ;
V_42 -> V_240 . V_245 = F_72 ;
V_42 -> V_240 . V_246 = F_78 ;
V_42 -> V_240 . V_247 = F_83 ;
V_42 -> V_240 . V_248 = F_86 ;
V_42 -> V_240 . V_134 = F_89 ;
V_42 -> V_240 . V_53 = & V_220 -> V_53 ;
V_111 = F_106 ( & V_42 -> V_240 ) ;
if ( V_111 )
goto V_249;
F_90 ( & V_42 -> V_250 , V_42 -> V_31 -> V_251 ,
V_42 ) ;
F_104 ( V_42 -> V_250 . V_242 ) ;
F_105 ( V_252 , V_42 -> V_250 . V_242 ) ;
V_42 -> V_250 . V_244 = F_71 ;
V_42 -> V_250 . V_245 = F_72 ;
V_42 -> V_250 . V_253 = F_74 ;
V_42 -> V_250 . V_247 = F_83 ;
V_42 -> V_250 . V_248 = F_86 ;
V_42 -> V_250 . V_134 = F_89 ;
V_42 -> V_250 . V_53 = & V_220 -> V_53 ;
V_42 -> V_250 . V_254 = 2 ;
V_111 = F_106 ( & V_42 -> V_250 ) ;
if ( V_111 )
goto V_255;
F_107 ( & V_220 -> V_53 , L_28 ,
( T_8 ) V_42 -> V_55 ) ;
return V_111 ;
V_255:
F_108 ( & V_42 -> V_240 ) ;
V_249:
F_109 ( & V_42 -> V_23 ) ;
V_239:
F_110 ( F_101 ( V_220 , 0 ) , V_42 ) ;
V_238:
V_236:
F_111 ( V_42 -> V_55 ) ;
V_235:
F_8 ( V_42 ) ;
V_233:
V_232:
F_112 ( V_220 -> V_223 -> V_227 ,
F_96 ( V_220 -> V_223 ) ) ;
V_230:
V_226:
return V_111 ;
}
static int T_6 F_113 ( struct V_219 * V_220 )
{
struct V_121 * V_42 = F_114 ( V_220 ) ;
F_108 ( & V_42 -> V_250 ) ;
F_108 ( & V_42 -> V_240 ) ;
F_109 ( & V_42 -> V_23 ) ;
F_110 ( F_101 ( V_220 , 0 ) , V_42 ) ;
F_111 ( V_42 -> V_55 ) ;
F_8 ( V_42 ) ;
F_112 ( V_220 -> V_223 -> V_227 ,
F_96 ( V_220 -> V_223 ) ) ;
return 0 ;
}
int T_5 F_115 ( void )
{
return F_116 ( & V_256 , F_93 ) ;
}
void T_6 F_117 ( void )
{
F_118 ( & V_256 ) ;
}
