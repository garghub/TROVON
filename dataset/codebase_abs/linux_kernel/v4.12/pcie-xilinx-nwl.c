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
struct V_10 * V_11 = V_2 -> V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
if ( F_6 ( V_2 ) )
return 0 ;
F_8 ( V_14 , V_15 ) ;
}
F_9 ( V_11 , L_1 ) ;
return - V_16 ;
}
static bool F_10 ( struct V_17 * V_18 , unsigned int V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
if ( V_18 -> V_21 != V_2 -> V_22 ) {
if ( ! F_5 ( V_2 ) )
return false ;
}
if ( V_18 -> V_21 == V_2 -> V_22 && V_19 > 0 )
return false ;
return true ;
}
static void T_2 * F_11 ( struct V_17 * V_18 , unsigned int V_19 ,
int V_23 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
int V_24 ;
if ( ! F_10 ( V_18 , V_19 ) )
return NULL ;
V_24 = ( V_18 -> V_21 << V_25 ) |
( V_19 << V_26 ) ;
return V_2 -> V_27 + V_24 + V_23 ;
}
static T_3 F_12 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_30 ;
V_30 = F_1 ( V_2 , V_31 ) &
V_32 ;
if ( ! V_30 )
return V_33 ;
if ( V_30 & V_34 )
F_9 ( V_11 , L_2 ) ;
if ( V_30 & V_35 )
F_9 ( V_11 , L_3 ) ;
if ( V_30 & V_36 )
F_9 ( V_11 , L_4 ) ;
if ( V_30 & V_37 )
F_9 ( V_11 , L_5 ) ;
if ( V_30 & V_38 )
F_9 ( V_11 , L_6 ) ;
if ( V_30 & V_39 )
F_9 ( V_11 , L_7 ) ;
if ( V_30 & V_40 )
F_9 ( V_11 , L_8 ) ;
if ( V_30 & V_41 )
F_9 ( V_11 , L_9 ) ;
if ( V_30 & V_42 )
F_9 ( V_11 , L_10 ) ;
if ( V_30 & V_43 )
F_9 ( V_11 , L_11 ) ;
if ( V_30 & V_44 )
F_9 ( V_11 , L_12 ) ;
if ( V_30 & V_45 )
F_13 ( V_11 , L_13 ) ;
if ( V_30 & V_46 )
F_13 ( V_11 , L_14 ) ;
F_3 ( V_2 , V_30 , V_31 ) ;
return V_47 ;
}
static void F_14 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_15 ( V_49 ) ;
struct V_1 * V_2 ;
unsigned long V_52 ;
T_1 V_53 ;
T_1 V_54 ;
F_16 ( V_51 , V_49 ) ;
V_2 = F_17 ( V_49 ) ;
while ( ( V_52 = F_1 ( V_2 , V_55 ) &
V_56 ) != 0 ) {
F_18 (bit, &status, INTX_NUM) {
V_54 = F_19 ( V_2 -> V_57 ,
V_53 + 1 ) ;
if ( V_54 )
F_20 ( V_54 ) ;
}
}
F_21 ( V_51 , V_49 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_58 )
{
struct V_59 * V_60 ;
unsigned long V_52 ;
T_1 V_53 ;
T_1 V_54 ;
V_60 = & V_2 -> V_60 ;
while ( ( V_52 = F_1 ( V_2 , V_58 ) ) != 0 ) {
F_18 (bit, &status, 32 ) {
F_3 ( V_2 , 1 << V_53 , V_58 ) ;
V_54 = F_19 ( V_60 -> V_61 , V_53 ) ;
if ( V_54 )
F_20 ( V_54 ) ;
}
}
}
static void F_23 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_15 ( V_49 ) ;
struct V_1 * V_2 = F_17 ( V_49 ) ;
F_16 ( V_51 , V_49 ) ;
F_22 ( V_2 , V_62 ) ;
F_21 ( V_51 , V_49 ) ;
}
static void F_24 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_15 ( V_49 ) ;
struct V_1 * V_2 = F_17 ( V_49 ) ;
F_16 ( V_51 , V_49 ) ;
F_22 ( V_2 , V_63 ) ;
F_21 ( V_51 , V_49 ) ;
}
static int F_25 ( struct V_64 * V_65 , unsigned int V_28 ,
T_4 V_66 )
{
F_26 ( V_28 , & V_67 , V_68 ) ;
F_27 ( V_28 , V_65 -> V_69 ) ;
return 0 ;
}
static void F_28 ( struct V_70 * V_29 , struct V_71 * V_72 )
{
struct V_1 * V_2 = F_29 ( V_29 ) ;
T_5 V_73 = V_2 -> V_74 ;
V_72 -> V_75 = F_30 ( V_73 ) ;
V_72 -> V_76 = F_31 ( V_73 ) ;
V_72 -> V_29 = V_29 -> V_66 ;
}
static int F_32 ( struct V_70 * V_70 ,
const struct V_77 * V_78 , bool V_79 )
{
return - V_80 ;
}
static int F_33 ( struct V_64 * V_65 , unsigned int V_54 ,
unsigned int V_81 , void * args )
{
struct V_1 * V_2 = V_65 -> V_69 ;
struct V_59 * V_60 = & V_2 -> V_60 ;
int V_53 ;
int V_82 ;
F_34 ( & V_60 -> V_83 ) ;
V_53 = F_35 ( V_60 -> V_84 , V_85 , 0 ,
V_81 , 0 ) ;
if ( V_53 >= V_85 ) {
F_36 ( & V_60 -> V_83 ) ;
return - V_86 ;
}
F_37 ( V_60 -> V_84 , V_53 , V_81 ) ;
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ ) {
F_38 ( V_65 , V_54 + V_82 , V_53 + V_82 , & V_87 ,
V_65 -> V_69 , V_68 ,
NULL , NULL ) ;
}
F_36 ( & V_60 -> V_83 ) ;
return 0 ;
}
static void F_39 ( struct V_64 * V_65 , unsigned int V_54 ,
unsigned int V_81 )
{
struct V_70 * V_29 = F_40 ( V_65 , V_54 ) ;
struct V_1 * V_2 = F_29 ( V_29 ) ;
struct V_59 * V_60 = & V_2 -> V_60 ;
F_34 ( & V_60 -> V_83 ) ;
F_41 ( V_60 -> V_84 , V_29 -> V_66 , V_81 ) ;
F_36 ( & V_60 -> V_83 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
#ifdef F_43
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_88 * V_89 = F_44 ( V_11 -> V_90 ) ;
struct V_59 * V_60 = & V_2 -> V_60 ;
V_60 -> V_61 = F_45 ( NULL , V_85 ,
& V_91 , V_2 ) ;
if ( ! V_60 -> V_61 ) {
F_9 ( V_11 , L_15 ) ;
return - V_92 ;
}
V_60 -> V_93 = F_46 ( V_89 ,
& V_94 ,
V_60 -> V_61 ) ;
if ( ! V_60 -> V_93 ) {
F_9 ( V_11 , L_16 ) ;
F_47 ( V_60 -> V_61 ) ;
return - V_92 ;
}
#endif
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_95 * V_96 = V_11 -> V_90 ;
struct V_95 * V_97 ;
V_97 = F_49 ( V_96 , NULL ) ;
if ( ! V_97 ) {
F_9 ( V_11 , L_17 ) ;
return - V_80 ;
}
V_2 -> V_57 = F_45 ( V_97 ,
V_98 ,
& V_99 ,
V_2 ) ;
if ( ! V_2 -> V_57 ) {
F_9 ( V_11 , L_18 ) ;
return - V_92 ;
}
F_42 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_100 * V_101 = F_51 ( V_11 ) ;
struct V_59 * V_60 = & V_2 -> V_60 ;
unsigned long V_102 ;
int V_103 ;
int V_104 = F_52 ( V_85 ) * sizeof( long ) ;
F_53 ( & V_60 -> V_83 ) ;
V_60 -> V_84 = F_54 ( V_104 , V_105 ) ;
if ( ! V_60 -> V_84 )
return - V_92 ;
V_60 -> V_106 = F_55 ( V_101 , L_19 ) ;
if ( V_60 -> V_106 < 0 ) {
F_9 ( V_11 , L_20 , V_60 -> V_106 ) ;
V_103 = - V_80 ;
goto V_107;
}
F_56 ( V_60 -> V_106 ,
F_23 , V_2 ) ;
V_60 -> V_108 = F_55 ( V_101 , L_21 ) ;
if ( V_60 -> V_108 < 0 ) {
F_9 ( V_11 , L_20 , V_60 -> V_108 ) ;
V_103 = - V_80 ;
goto V_107;
}
F_56 ( V_60 -> V_108 ,
F_24 , V_2 ) ;
V_103 = F_1 ( V_2 , V_109 ) & V_110 ;
if ( ! V_103 ) {
F_9 ( V_11 , L_22 ) ;
V_103 = - V_111 ;
goto V_107;
}
F_3 ( V_2 , F_1 ( V_2 , V_112 ) |
V_113 , V_112 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_112 ) |
V_114 , V_112 ) ;
V_102 = V_2 -> V_74 ;
F_3 ( V_2 , F_30 ( V_102 ) , V_115 ) ;
F_3 ( V_2 , F_31 ( V_102 ) , V_116 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_117 , V_118 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_62 ) &
V_117 , V_62 ) ;
F_3 ( V_2 , V_117 , V_118 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_119 , V_120 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_63 ) &
V_119 , V_63 ) ;
F_3 ( V_2 , V_119 , V_120 ) ;
return 0 ;
V_107:
F_57 ( V_60 -> V_84 ) ;
V_60 -> V_84 = NULL ;
return V_103 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_100 * V_101 = F_51 ( V_11 ) ;
T_1 V_121 , V_122 , V_123 = 0 ;
int V_107 ;
V_121 = F_1 ( V_2 , V_124 ) & V_125 ;
if ( ! V_121 ) {
F_9 ( V_11 , L_23 ) ;
return V_121 ;
}
F_3 ( V_2 , F_30 ( V_2 -> V_126 ) ,
V_127 ) ;
F_3 ( V_2 , F_31 ( V_2 -> V_126 ) ,
V_128 ) ;
F_3 ( V_2 , ~ V_129 & V_130 ,
V_131 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_132 ) |
V_133 , V_132 ) ;
F_3 ( V_2 , V_134 , V_135 ) ;
F_3 ( V_2 , V_136 ,
V_137 ) ;
V_107 = F_7 ( V_2 ) ;
if ( V_107 )
return V_107 ;
V_122 = F_1 ( V_2 , V_138 ) & V_139 ;
if ( ! V_122 ) {
F_9 ( V_11 , L_24 ) ;
return V_122 ;
}
F_3 ( V_2 , F_1 ( V_2 , V_140 ) |
V_141 , V_140 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_140 ) |
( V_2 -> V_142 << V_143 ) ,
V_140 ) ;
F_3 ( V_2 , F_30 ( V_2 -> V_144 ) ,
V_145 ) ;
F_3 ( V_2 , F_31 ( V_2 -> V_144 ) ,
V_146 ) ;
V_122 = F_1 ( V_2 , V_140 ) ;
V_2 -> V_147 = ( V_122 & V_148 ) >> V_143 ;
V_122 = V_123 ;
V_122 |= ( V_123 + 1 ) << 8 ;
V_122 |= ( V_2 -> V_147 << V_143 ) ;
F_4 ( V_122 , ( V_2 -> V_27 + V_149 ) ) ;
if ( F_5 ( V_2 ) )
F_13 ( V_11 , L_25 ) ;
else
F_13 ( V_11 , L_26 ) ;
V_2 -> V_150 = F_55 ( V_101 , L_27 ) ;
if ( V_2 -> V_150 < 0 ) {
F_9 ( V_11 , L_28 ,
V_2 -> V_150 ) ;
return - V_80 ;
}
V_107 = F_59 ( V_11 , V_2 -> V_150 ,
F_12 , V_151 ,
L_29 , V_2 ) ;
if ( V_107 ) {
F_9 ( V_11 , L_30 ,
V_2 -> V_150 ) ;
return V_107 ;
}
F_3 ( V_2 , ( T_1 ) ~ V_32 , V_152 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_31 ) &
V_32 , V_31 ) ;
F_3 ( V_2 , V_32 , V_152 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_56 , V_153 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_55 ) &
V_56 , V_55 ) ;
F_3 ( V_2 , V_56 , V_153 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_154 ) |
V_155 , V_154 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_95 * V_96 = V_11 -> V_90 ;
struct V_156 * V_157 ;
const char * type ;
type = F_61 ( V_96 , L_31 , NULL ) ;
if ( ! type || strcmp ( type , L_32 ) ) {
F_9 ( V_11 , L_33 , type ) ;
return - V_80 ;
}
V_157 = F_62 ( V_101 , V_158 , L_34 ) ;
V_2 -> V_4 = F_63 ( V_11 , V_157 ) ;
if ( F_64 ( V_2 -> V_4 ) )
return F_65 ( V_2 -> V_4 ) ;
V_2 -> V_126 = V_157 -> V_159 ;
V_157 = F_62 ( V_101 , V_158 , L_35 ) ;
V_2 -> V_6 = F_63 ( V_11 , V_157 ) ;
if ( F_64 ( V_2 -> V_6 ) )
return F_65 ( V_2 -> V_6 ) ;
V_2 -> V_74 = V_157 -> V_159 ;
V_157 = F_62 ( V_101 , V_158 , L_36 ) ;
V_2 -> V_27 = F_66 ( V_11 , V_157 ) ;
if ( F_64 ( V_2 -> V_27 ) )
return F_65 ( V_2 -> V_27 ) ;
V_2 -> V_144 = V_157 -> V_159 ;
V_2 -> V_160 = F_55 ( V_101 , L_37 ) ;
if ( V_2 -> V_160 < 0 ) {
F_9 ( V_11 , L_38 , V_2 -> V_160 ) ;
return - V_80 ;
}
F_56 ( V_2 -> V_160 ,
F_14 , V_2 ) ;
return 0 ;
}
static int F_67 ( struct V_100 * V_101 )
{
struct V_10 * V_11 = & V_101 -> V_11 ;
struct V_95 * V_96 = V_11 -> V_90 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_17 * V_161 ;
int V_107 ;
T_6 V_162 = 0 ;
F_68 ( V_157 ) ;
V_2 = F_69 ( V_11 , sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 )
return - V_92 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_142 = V_163 ;
V_107 = F_60 ( V_2 , V_101 ) ;
if ( V_107 ) {
F_9 ( V_11 , L_39 ) ;
return V_107 ;
}
V_107 = F_58 ( V_2 ) ;
if ( V_107 ) {
F_9 ( V_11 , L_40 ) ;
return V_107 ;
}
V_107 = F_70 ( V_96 , 0 , 0xff , & V_157 , & V_162 ) ;
if ( V_107 ) {
F_9 ( V_11 , L_41 ) ;
return V_107 ;
}
V_107 = F_71 ( V_11 , & V_157 ) ;
if ( V_107 )
goto error;
V_107 = F_48 ( V_2 ) ;
if ( V_107 ) {
F_9 ( V_11 , L_42 ) ;
goto error;
}
V_18 = F_72 ( V_11 , V_2 -> V_22 ,
& V_164 , V_2 , & V_157 ) ;
if ( ! V_18 ) {
V_107 = - V_92 ;
goto error;
}
if ( F_73 ( F_43 ) ) {
V_107 = F_50 ( V_2 , V_18 ) ;
if ( V_107 < 0 ) {
F_9 ( V_11 , L_43 , V_107 ) ;
goto error;
}
}
F_74 ( V_18 ) ;
F_75 ( V_18 ) ;
F_76 (child, &bus->children, node)
F_77 ( V_161 ) ;
F_78 ( V_18 ) ;
return 0 ;
error:
F_79 ( & V_157 ) ;
return V_107 ;
}
