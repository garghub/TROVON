static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static bool F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_6 + V_7 ) & V_8 )
return true ;
return false ;
}
static bool F_6 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_6 + V_7 ) & V_9 )
return true ;
return false ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_6 ( V_2 ) )
return 0 ;
F_8 ( V_12 , V_13 ) ;
}
F_9 ( V_2 -> V_14 , L_1 ) ;
return - V_15 ;
}
static bool F_10 ( struct V_16 * V_17 , unsigned int V_18 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
if ( V_17 -> V_20 != V_2 -> V_21 ) {
if ( ! F_5 ( V_2 ) )
return false ;
}
if ( V_17 -> V_20 == V_2 -> V_21 && V_18 > 0 )
return false ;
return true ;
}
static void T_2 * F_11 ( struct V_16 * V_17 , unsigned int V_18 ,
int V_22 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
int V_23 ;
if ( ! F_10 ( V_17 , V_18 ) )
return NULL ;
V_23 = ( V_17 -> V_20 << V_24 ) |
( V_18 << V_25 ) ;
return V_2 -> V_26 + V_23 + V_22 ;
}
static T_3 F_12 ( int V_27 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
T_1 V_29 ;
V_29 = F_1 ( V_2 , V_30 ) &
V_31 ;
if ( ! V_29 )
return V_32 ;
if ( V_29 & V_33 )
F_9 ( V_2 -> V_14 , L_2 ) ;
if ( V_29 & V_34 )
F_9 ( V_2 -> V_14 , L_3 ) ;
if ( V_29 & V_35 )
F_9 ( V_2 -> V_14 , L_4 ) ;
if ( V_29 & V_36 )
F_9 ( V_2 -> V_14 ,
L_5 ) ;
if ( V_29 & V_37 )
F_9 ( V_2 -> V_14 ,
L_6 ) ;
if ( V_29 & V_38 )
F_9 ( V_2 -> V_14 , L_7 ) ;
F_3 ( V_2 , V_29 , V_30 ) ;
return V_39 ;
}
static void F_13 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_14 ( V_41 ) ;
struct V_1 * V_2 ;
unsigned long V_44 ;
T_1 V_45 ;
T_1 V_46 ;
F_15 ( V_43 , V_41 ) ;
V_2 = F_16 ( V_41 ) ;
while ( ( V_44 = F_1 ( V_2 , V_47 ) &
V_48 ) != 0 ) {
F_17 (bit, &status, INTX_NUM) {
V_46 = F_18 ( V_2 -> V_49 ,
V_45 + 1 ) ;
if ( V_46 )
F_19 ( V_46 ) ;
}
}
F_20 ( V_43 , V_41 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_50 )
{
struct V_51 * V_52 ;
unsigned long V_44 ;
T_1 V_45 ;
T_1 V_46 ;
V_52 = & V_2 -> V_52 ;
while ( ( V_44 = F_1 ( V_2 , V_50 ) ) != 0 ) {
F_17 (bit, &status, 32 ) {
F_3 ( V_2 , 1 << V_45 , V_50 ) ;
V_46 = F_18 ( V_52 -> V_53 , V_45 ) ;
if ( V_46 )
F_19 ( V_46 ) ;
}
}
}
static void F_22 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_14 ( V_41 ) ;
struct V_1 * V_2 = F_16 ( V_41 ) ;
F_15 ( V_43 , V_41 ) ;
F_21 ( V_2 , V_54 ) ;
F_20 ( V_43 , V_41 ) ;
}
static void F_23 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_14 ( V_41 ) ;
struct V_1 * V_2 = F_16 ( V_41 ) ;
F_15 ( V_43 , V_41 ) ;
F_21 ( V_2 , V_55 ) ;
F_20 ( V_43 , V_41 ) ;
}
static int F_24 ( struct V_56 * V_57 , unsigned int V_27 ,
T_4 V_58 )
{
F_25 ( V_27 , & V_59 , V_60 ) ;
F_26 ( V_27 , V_57 -> V_61 ) ;
return 0 ;
}
static void F_27 ( struct V_62 * V_28 , struct V_63 * V_64 )
{
struct V_1 * V_2 = F_28 ( V_28 ) ;
T_5 V_65 = V_2 -> V_66 ;
V_64 -> V_67 = F_29 ( V_65 ) ;
V_64 -> V_68 = F_30 ( V_65 ) ;
V_64 -> V_28 = V_28 -> V_58 ;
}
static int F_31 ( struct V_62 * V_62 ,
const struct V_69 * V_70 , bool V_71 )
{
return - V_72 ;
}
static int F_32 ( struct V_56 * V_57 , unsigned int V_46 ,
unsigned int V_73 , void * args )
{
struct V_1 * V_2 = V_57 -> V_61 ;
struct V_51 * V_52 = & V_2 -> V_52 ;
int V_45 ;
int V_74 ;
F_33 ( & V_52 -> V_75 ) ;
V_45 = F_34 ( V_52 -> V_76 , V_77 , 0 ,
V_73 , 0 ) ;
if ( V_45 >= V_77 ) {
F_35 ( & V_52 -> V_75 ) ;
return - V_78 ;
}
F_36 ( V_52 -> V_76 , V_45 , V_73 ) ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
F_37 ( V_57 , V_46 + V_74 , V_45 + V_74 , & V_79 ,
V_57 -> V_61 , V_60 ,
NULL , NULL ) ;
}
F_35 ( & V_52 -> V_75 ) ;
return 0 ;
}
static void F_38 ( struct V_56 * V_57 , unsigned int V_46 ,
unsigned int V_73 )
{
struct V_62 * V_28 = F_39 ( V_57 , V_46 ) ;
struct V_1 * V_2 = F_28 ( V_28 ) ;
struct V_51 * V_52 = & V_2 -> V_52 ;
F_33 ( & V_52 -> V_75 ) ;
F_40 ( V_52 -> V_76 , V_28 -> V_58 , V_73 ) ;
F_35 ( & V_52 -> V_75 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = & V_2 -> V_52 ;
if ( V_52 -> V_80 )
F_42 ( V_52 -> V_80 , NULL , NULL ) ;
if ( V_52 -> V_81 )
F_42 ( V_52 -> V_81 , NULL , NULL ) ;
if ( V_52 -> V_82 )
F_43 ( V_52 -> V_82 ) ;
if ( V_52 -> V_53 )
F_43 ( V_52 -> V_53 ) ;
F_44 ( V_52 -> V_76 ) ;
V_52 -> V_76 = NULL ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_74 ;
T_1 V_27 ;
for ( V_74 = 0 ; V_74 < V_83 ; V_74 ++ ) {
V_27 = F_18 ( V_2 -> V_49 , V_74 + 1 ) ;
if ( V_27 > 0 )
F_46 ( V_27 ) ;
}
if ( V_2 -> V_49 )
F_43 ( V_2 -> V_49 ) ;
F_41 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
#ifdef F_48
struct V_84 * V_85 = F_49 ( V_2 -> V_14 -> V_86 ) ;
struct V_51 * V_52 = & V_2 -> V_52 ;
V_52 -> V_53 = F_50 ( NULL , V_77 ,
& V_87 , V_2 ) ;
if ( ! V_52 -> V_53 ) {
F_9 ( V_2 -> V_14 , L_8 ) ;
return - V_88 ;
}
V_52 -> V_82 = F_51 ( V_85 ,
& V_89 ,
V_52 -> V_53 ) ;
if ( ! V_52 -> V_82 ) {
F_9 ( V_2 -> V_14 , L_9 ) ;
F_43 ( V_52 -> V_53 ) ;
return - V_88 ;
}
#endif
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = V_2 -> V_14 -> V_86 ;
struct V_90 * V_92 ;
V_92 = F_53 ( V_91 , NULL ) ;
if ( ! V_92 ) {
F_9 ( V_2 -> V_14 , L_10 ) ;
return - V_72 ;
}
V_2 -> V_49 = F_50 ( V_92 ,
V_83 ,
& V_93 ,
V_2 ) ;
if ( ! V_2 -> V_49 ) {
F_9 ( V_2 -> V_14 , L_11 ) ;
return - V_88 ;
}
F_47 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_94 * V_95 = F_55 ( V_2 -> V_14 ) ;
struct V_51 * V_52 = & V_2 -> V_52 ;
unsigned long V_96 ;
int V_97 ;
int V_98 = F_56 ( V_77 ) * sizeof( long ) ;
F_57 ( & V_52 -> V_75 ) ;
V_52 -> V_76 = F_58 ( V_98 , V_99 ) ;
if ( ! V_52 -> V_76 )
return - V_88 ;
V_52 -> V_81 = F_59 ( V_95 , L_12 ) ;
if ( V_52 -> V_81 < 0 ) {
F_9 ( & V_95 -> V_14 , L_13 , V_52 -> V_81 ) ;
V_97 = - V_72 ;
goto V_100;
}
F_42 ( V_52 -> V_81 ,
F_22 , V_2 ) ;
V_52 -> V_80 = F_59 ( V_95 , L_14 ) ;
if ( V_52 -> V_80 < 0 ) {
F_9 ( & V_95 -> V_14 , L_13 , V_52 -> V_80 ) ;
V_97 = - V_72 ;
goto V_100;
}
F_42 ( V_52 -> V_80 ,
F_23 , V_2 ) ;
V_97 = F_1 ( V_2 , V_101 ) & V_102 ;
if ( ! V_97 ) {
F_9 ( V_2 -> V_14 , L_15 ) ;
V_97 = - V_103 ;
goto V_100;
}
F_3 ( V_2 , F_1 ( V_2 , V_104 ) |
V_105 , V_104 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_104 ) |
V_106 , V_104 ) ;
V_96 = V_2 -> V_66 ;
F_3 ( V_2 , F_29 ( V_96 ) , V_107 ) ;
F_3 ( V_2 , F_30 ( V_96 ) , V_108 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_109 , V_110 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_54 ) &
V_109 , V_54 ) ;
F_3 ( V_2 , V_109 , V_110 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_111 , V_112 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_55 ) &
V_111 , V_55 ) ;
F_3 ( V_2 , V_111 , V_112 ) ;
return 0 ;
V_100:
F_44 ( V_52 -> V_76 ) ;
V_52 -> V_76 = NULL ;
return V_97 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = F_55 ( V_2 -> V_14 ) ;
T_1 V_113 , V_114 , V_115 = 0 ;
int V_100 ;
V_113 = F_1 ( V_2 , V_116 ) & V_117 ;
if ( ! V_113 ) {
F_9 ( V_2 -> V_14 , L_16 ) ;
return V_113 ;
}
F_3 ( V_2 , F_29 ( V_2 -> V_118 ) ,
V_119 ) ;
F_3 ( V_2 , F_30 ( V_2 -> V_118 ) ,
V_120 ) ;
F_3 ( V_2 , ~ V_121 & V_122 ,
V_123 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_124 ) |
V_125 , V_124 ) ;
F_3 ( V_2 , V_126 , V_127 ) ;
F_3 ( V_2 , V_128 ,
V_129 ) ;
V_100 = F_7 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_114 = F_1 ( V_2 , V_130 ) & V_131 ;
if ( ! V_114 ) {
F_9 ( V_2 -> V_14 , L_17 ) ;
return V_114 ;
}
F_3 ( V_2 , F_1 ( V_2 , V_132 ) |
V_133 , V_132 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_132 ) |
( V_2 -> V_134 << V_135 ) ,
V_132 ) ;
F_3 ( V_2 , F_29 ( V_2 -> V_136 ) ,
V_137 ) ;
F_3 ( V_2 , F_30 ( V_2 -> V_136 ) ,
V_138 ) ;
V_114 = F_1 ( V_2 , V_132 ) ;
V_2 -> V_139 = ( V_114 & V_140 ) >> V_135 ;
V_114 = V_115 ;
V_114 |= ( V_115 + 1 ) << 8 ;
V_114 |= ( V_2 -> V_139 << V_135 ) ;
F_4 ( V_114 , ( V_2 -> V_26 + V_141 ) ) ;
if ( F_5 ( V_2 ) )
F_61 ( V_2 -> V_14 , L_18 ) ;
else
F_61 ( V_2 -> V_14 , L_19 ) ;
V_2 -> V_142 = F_59 ( V_95 , L_20 ) ;
if ( V_2 -> V_142 < 0 ) {
F_9 ( & V_95 -> V_14 , L_21 ,
V_2 -> V_142 ) ;
return - V_72 ;
}
V_100 = F_62 ( V_2 -> V_14 , V_2 -> V_142 ,
F_12 , V_143 ,
L_22 , V_2 ) ;
if ( V_100 ) {
F_9 ( V_2 -> V_14 , L_23 ,
V_2 -> V_142 ) ;
return V_100 ;
}
F_3 ( V_2 , ( T_1 ) ~ V_31 , V_144 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_30 ) &
V_31 , V_30 ) ;
F_3 ( V_2 , V_31 , V_144 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_48 , V_145 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_47 ) &
V_48 , V_47 ) ;
F_3 ( V_2 , V_48 , V_145 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_146 ) |
V_147 , V_146 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_90 * V_91 = V_2 -> V_14 -> V_86 ;
struct V_148 * V_149 ;
const char * type ;
type = F_64 ( V_91 , L_24 , NULL ) ;
if ( ! type || strcmp ( type , L_25 ) ) {
F_9 ( V_2 -> V_14 , L_26 , type ) ;
return - V_72 ;
}
V_149 = F_65 ( V_95 , V_150 , L_27 ) ;
V_2 -> V_4 = F_66 ( V_2 -> V_14 , V_149 ) ;
if ( F_67 ( V_2 -> V_4 ) )
return F_68 ( V_2 -> V_4 ) ;
V_2 -> V_118 = V_149 -> V_151 ;
V_149 = F_65 ( V_95 , V_150 , L_28 ) ;
V_2 -> V_6 = F_66 ( V_2 -> V_14 , V_149 ) ;
if ( F_67 ( V_2 -> V_6 ) )
return F_68 ( V_2 -> V_6 ) ;
V_2 -> V_66 = V_149 -> V_151 ;
V_149 = F_65 ( V_95 , V_150 , L_29 ) ;
V_2 -> V_26 = F_66 ( V_2 -> V_14 , V_149 ) ;
if ( F_67 ( V_2 -> V_26 ) )
return F_68 ( V_2 -> V_26 ) ;
V_2 -> V_136 = V_149 -> V_151 ;
V_2 -> V_152 = F_59 ( V_95 , L_30 ) ;
if ( V_2 -> V_152 < 0 ) {
F_9 ( & V_95 -> V_14 , L_31 ,
V_2 -> V_152 ) ;
return - V_72 ;
}
F_42 ( V_2 -> V_152 ,
F_13 , V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_94 * V_95 )
{
struct V_90 * V_91 = V_95 -> V_14 . V_86 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_16 * V_153 ;
int V_100 ;
T_6 V_154 = 0 ;
F_70 ( V_149 ) ;
V_2 = F_71 ( & V_95 -> V_14 , sizeof( * V_2 ) , V_99 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_14 = & V_95 -> V_14 ;
V_2 -> V_134 = V_155 ;
V_100 = F_63 ( V_2 , V_95 ) ;
if ( V_100 ) {
F_9 ( V_2 -> V_14 , L_32 ) ;
return V_100 ;
}
V_100 = F_60 ( V_2 ) ;
if ( V_100 ) {
F_9 ( V_2 -> V_14 , L_33 ) ;
return V_100 ;
}
V_100 = F_72 ( V_91 , 0 , 0xff , & V_149 , & V_154 ) ;
if ( V_100 ) {
F_9 ( V_2 -> V_14 , L_34 ) ;
return V_100 ;
}
V_100 = F_73 ( V_2 -> V_14 , & V_149 ) ;
if ( V_100 )
goto error;
V_100 = F_52 ( V_2 ) ;
if ( V_100 ) {
F_9 ( V_2 -> V_14 , L_35 ) ;
goto error;
}
V_17 = F_74 ( & V_95 -> V_14 , V_2 -> V_21 ,
& V_156 , V_2 , & V_149 ) ;
if ( ! V_17 ) {
V_100 = - V_88 ;
goto error;
}
if ( F_75 ( F_48 ) ) {
V_100 = F_54 ( V_2 , V_17 ) ;
if ( V_100 < 0 ) {
F_9 ( & V_95 -> V_14 ,
L_36 , V_100 ) ;
goto error;
}
}
F_76 ( V_17 ) ;
F_77 ( V_17 ) ;
F_78 (child, &bus->children, node)
F_79 ( V_153 ) ;
F_80 ( V_17 ) ;
F_81 ( V_95 , V_2 ) ;
return 0 ;
error:
F_82 ( & V_149 ) ;
return V_100 ;
}
static int F_83 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_84 ( V_95 ) ;
F_45 ( V_2 ) ;
F_81 ( V_95 , NULL ) ;
return 0 ;
}
