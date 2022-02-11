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
static void F_25 ( struct V_64 * V_29 )
{
struct V_48 * V_49 = F_26 ( V_29 -> V_28 ) ;
struct V_1 * V_2 ;
unsigned long V_65 ;
T_1 V_66 ;
T_1 V_5 ;
V_2 = F_27 ( V_49 ) ;
V_66 = 1 << ( V_29 -> V_67 - 1 ) ;
F_28 ( & V_2 -> V_68 , V_65 ) ;
V_5 = F_1 ( V_2 , V_69 ) ;
F_3 ( V_2 , ( V_5 & ( ~ V_66 ) ) , V_69 ) ;
F_29 ( & V_2 -> V_68 , V_65 ) ;
}
static void F_30 ( struct V_64 * V_29 )
{
struct V_48 * V_49 = F_26 ( V_29 -> V_28 ) ;
struct V_1 * V_2 ;
unsigned long V_65 ;
T_1 V_66 ;
T_1 V_5 ;
V_2 = F_27 ( V_49 ) ;
V_66 = 1 << ( V_29 -> V_67 - 1 ) ;
F_28 ( & V_2 -> V_68 , V_65 ) ;
V_5 = F_1 ( V_2 , V_69 ) ;
F_3 ( V_2 , ( V_5 | V_66 ) , V_69 ) ;
F_29 ( & V_2 -> V_68 , V_65 ) ;
}
static int F_31 ( struct V_70 * V_71 , unsigned int V_28 ,
T_4 V_67 )
{
F_32 ( V_28 , & V_72 , V_73 ) ;
F_33 ( V_28 , V_71 -> V_74 ) ;
F_34 ( V_28 , V_75 ) ;
return 0 ;
}
static void F_35 ( struct V_64 * V_29 , struct V_76 * V_77 )
{
struct V_1 * V_2 = F_36 ( V_29 ) ;
T_5 V_78 = V_2 -> V_79 ;
V_77 -> V_80 = F_37 ( V_78 ) ;
V_77 -> V_81 = F_38 ( V_78 ) ;
V_77 -> V_29 = V_29 -> V_67 ;
}
static int F_39 ( struct V_64 * V_64 ,
const struct V_82 * V_66 , bool V_83 )
{
return - V_84 ;
}
static int F_40 ( struct V_70 * V_71 , unsigned int V_54 ,
unsigned int V_85 , void * args )
{
struct V_1 * V_2 = V_71 -> V_74 ;
struct V_59 * V_60 = & V_2 -> V_60 ;
int V_53 ;
int V_86 ;
F_41 ( & V_60 -> V_87 ) ;
V_53 = F_42 ( V_60 -> V_88 , V_89 , 0 ,
V_85 , 0 ) ;
if ( V_53 >= V_89 ) {
F_43 ( & V_60 -> V_87 ) ;
return - V_90 ;
}
F_44 ( V_60 -> V_88 , V_53 , V_85 ) ;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ ) {
F_45 ( V_71 , V_54 + V_86 , V_53 + V_86 , & V_91 ,
V_71 -> V_74 , V_92 ,
NULL , NULL ) ;
}
F_43 ( & V_60 -> V_87 ) ;
return 0 ;
}
static void F_46 ( struct V_70 * V_71 , unsigned int V_54 ,
unsigned int V_85 )
{
struct V_64 * V_29 = F_47 ( V_71 , V_54 ) ;
struct V_1 * V_2 = F_36 ( V_29 ) ;
struct V_59 * V_60 = & V_2 -> V_60 ;
F_41 ( & V_60 -> V_87 ) ;
F_48 ( V_60 -> V_88 , V_29 -> V_67 , V_85 ) ;
F_43 ( & V_60 -> V_87 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
#ifdef F_50
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_93 * V_94 = F_51 ( V_11 -> V_95 ) ;
struct V_59 * V_60 = & V_2 -> V_60 ;
V_60 -> V_61 = F_52 ( NULL , V_89 ,
& V_96 , V_2 ) ;
if ( ! V_60 -> V_61 ) {
F_9 ( V_11 , L_15 ) ;
return - V_97 ;
}
V_60 -> V_98 = F_53 ( V_94 ,
& V_99 ,
V_60 -> V_61 ) ;
if ( ! V_60 -> V_98 ) {
F_9 ( V_11 , L_16 ) ;
F_54 ( V_60 -> V_61 ) ;
return - V_97 ;
}
#endif
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_100 * V_101 = V_11 -> V_95 ;
struct V_100 * V_102 ;
V_102 = F_56 ( V_101 , NULL ) ;
if ( ! V_102 ) {
F_9 ( V_11 , L_17 ) ;
return - V_84 ;
}
V_2 -> V_57 = F_52 ( V_102 ,
V_103 ,
& V_104 ,
V_2 ) ;
if ( ! V_2 -> V_57 ) {
F_9 ( V_11 , L_18 ) ;
return - V_97 ;
}
F_57 ( & V_2 -> V_68 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_105 * V_106 = F_59 ( V_11 ) ;
struct V_59 * V_60 = & V_2 -> V_60 ;
unsigned long V_107 ;
int V_108 ;
int V_109 = F_60 ( V_89 ) * sizeof( long ) ;
F_61 ( & V_60 -> V_87 ) ;
V_60 -> V_88 = F_62 ( V_109 , V_110 ) ;
if ( ! V_60 -> V_88 )
return - V_97 ;
V_60 -> V_111 = F_63 ( V_106 , L_19 ) ;
if ( V_60 -> V_111 < 0 ) {
F_9 ( V_11 , L_20 , V_60 -> V_111 ) ;
V_108 = - V_84 ;
goto V_112;
}
F_64 ( V_60 -> V_111 ,
F_23 , V_2 ) ;
V_60 -> V_113 = F_63 ( V_106 , L_21 ) ;
if ( V_60 -> V_113 < 0 ) {
F_9 ( V_11 , L_20 , V_60 -> V_113 ) ;
V_108 = - V_84 ;
goto V_112;
}
F_64 ( V_60 -> V_113 ,
F_24 , V_2 ) ;
V_108 = F_1 ( V_2 , V_114 ) & V_115 ;
if ( ! V_108 ) {
F_9 ( V_11 , L_22 ) ;
V_108 = - V_116 ;
goto V_112;
}
F_3 ( V_2 , F_1 ( V_2 , V_117 ) |
V_118 , V_117 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_117 ) |
V_119 , V_117 ) ;
V_107 = V_2 -> V_79 ;
F_3 ( V_2 , F_37 ( V_107 ) , V_120 ) ;
F_3 ( V_2 , F_38 ( V_107 ) , V_121 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_122 , V_123 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_62 ) &
V_122 , V_62 ) ;
F_3 ( V_2 , V_122 , V_123 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_124 , V_125 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_63 ) &
V_124 , V_63 ) ;
F_3 ( V_2 , V_124 , V_125 ) ;
return 0 ;
V_112:
F_65 ( V_60 -> V_88 ) ;
V_60 -> V_88 = NULL ;
return V_108 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_105 * V_106 = F_59 ( V_11 ) ;
T_1 V_126 , V_127 , V_128 = 0 ;
int V_112 ;
V_126 = F_1 ( V_2 , V_129 ) & V_130 ;
if ( ! V_126 ) {
F_9 ( V_11 , L_23 ) ;
return V_126 ;
}
F_3 ( V_2 , F_37 ( V_2 -> V_131 ) ,
V_132 ) ;
F_3 ( V_2 , F_38 ( V_2 -> V_131 ) ,
V_133 ) ;
F_3 ( V_2 , ~ V_134 & V_135 ,
V_136 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_137 ) |
V_138 , V_137 ) ;
F_3 ( V_2 , V_139 , V_140 ) ;
F_3 ( V_2 , V_141 ,
V_142 ) ;
V_112 = F_7 ( V_2 ) ;
if ( V_112 )
return V_112 ;
V_127 = F_1 ( V_2 , V_143 ) & V_144 ;
if ( ! V_127 ) {
F_9 ( V_11 , L_24 ) ;
return V_127 ;
}
F_3 ( V_2 , F_1 ( V_2 , V_145 ) |
V_146 , V_145 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_145 ) |
( V_2 -> V_147 << V_148 ) ,
V_145 ) ;
F_3 ( V_2 , F_37 ( V_2 -> V_149 ) ,
V_150 ) ;
F_3 ( V_2 , F_38 ( V_2 -> V_149 ) ,
V_151 ) ;
V_127 = F_1 ( V_2 , V_145 ) ;
V_2 -> V_152 = ( V_127 & V_153 ) >> V_148 ;
V_127 = V_128 ;
V_127 |= ( V_128 + 1 ) << 8 ;
V_127 |= ( V_2 -> V_152 << V_148 ) ;
F_4 ( V_127 , ( V_2 -> V_27 + V_154 ) ) ;
if ( F_5 ( V_2 ) )
F_13 ( V_11 , L_25 ) ;
else
F_13 ( V_11 , L_26 ) ;
V_2 -> V_155 = F_63 ( V_106 , L_27 ) ;
if ( V_2 -> V_155 < 0 ) {
F_9 ( V_11 , L_28 ,
V_2 -> V_155 ) ;
return - V_84 ;
}
V_112 = F_67 ( V_11 , V_2 -> V_155 ,
F_12 , V_156 ,
L_29 , V_2 ) ;
if ( V_112 ) {
F_9 ( V_11 , L_30 ,
V_2 -> V_155 ) ;
return V_112 ;
}
F_3 ( V_2 , ( T_1 ) ~ V_32 , V_157 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_31 ) &
V_32 , V_31 ) ;
F_3 ( V_2 , V_32 , V_157 ) ;
F_3 ( V_2 , ( T_1 ) ~ V_56 , V_69 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_55 ) &
V_56 , V_55 ) ;
F_3 ( V_2 , V_56 , V_69 ) ;
F_3 ( V_2 , F_1 ( V_2 , V_158 ) |
V_159 , V_158 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_100 * V_101 = V_11 -> V_95 ;
struct V_160 * V_161 ;
const char * type ;
type = F_69 ( V_101 , L_31 , NULL ) ;
if ( ! type || strcmp ( type , L_32 ) ) {
F_9 ( V_11 , L_33 , type ) ;
return - V_84 ;
}
V_161 = F_70 ( V_106 , V_162 , L_34 ) ;
V_2 -> V_4 = F_71 ( V_11 , V_161 ) ;
if ( F_72 ( V_2 -> V_4 ) )
return F_73 ( V_2 -> V_4 ) ;
V_2 -> V_131 = V_161 -> V_163 ;
V_161 = F_70 ( V_106 , V_162 , L_35 ) ;
V_2 -> V_6 = F_71 ( V_11 , V_161 ) ;
if ( F_72 ( V_2 -> V_6 ) )
return F_73 ( V_2 -> V_6 ) ;
V_2 -> V_79 = V_161 -> V_163 ;
V_161 = F_70 ( V_106 , V_162 , L_36 ) ;
V_2 -> V_27 = F_74 ( V_11 , V_161 ) ;
if ( F_72 ( V_2 -> V_27 ) )
return F_73 ( V_2 -> V_27 ) ;
V_2 -> V_149 = V_161 -> V_163 ;
V_2 -> V_164 = F_63 ( V_106 , L_37 ) ;
if ( V_2 -> V_164 < 0 ) {
F_9 ( V_11 , L_38 , V_2 -> V_164 ) ;
return - V_84 ;
}
F_64 ( V_2 -> V_164 ,
F_14 , V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_105 * V_106 )
{
struct V_10 * V_11 = & V_106 -> V_11 ;
struct V_100 * V_101 = V_11 -> V_95 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_17 * V_165 ;
struct V_166 * V_167 ;
int V_112 ;
T_6 V_168 = 0 ;
F_76 ( V_161 ) ;
V_167 = F_77 ( V_11 , sizeof( * V_2 ) ) ;
if ( ! V_167 )
return - V_169 ;
V_2 = F_78 ( V_167 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_147 = V_170 ;
V_112 = F_68 ( V_2 , V_106 ) ;
if ( V_112 ) {
F_9 ( V_11 , L_39 ) ;
return V_112 ;
}
V_112 = F_66 ( V_2 ) ;
if ( V_112 ) {
F_9 ( V_11 , L_40 ) ;
return V_112 ;
}
V_112 = F_79 ( V_101 , 0 , 0xff , & V_161 , & V_168 ) ;
if ( V_112 ) {
F_9 ( V_11 , L_41 ) ;
return V_112 ;
}
V_112 = F_80 ( V_11 , & V_161 ) ;
if ( V_112 )
goto error;
V_112 = F_55 ( V_2 ) ;
if ( V_112 ) {
F_9 ( V_11 , L_42 ) ;
goto error;
}
F_81 ( & V_161 , & V_167 -> V_171 ) ;
V_167 -> V_11 . V_172 = V_11 ;
V_167 -> V_20 = V_2 ;
V_167 -> V_173 = V_2 -> V_22 ;
V_167 -> V_174 = & V_175 ;
V_167 -> V_176 = V_177 ;
V_167 -> V_178 = V_179 ;
if ( F_82 ( F_50 ) ) {
V_112 = F_58 ( V_2 ) ;
if ( V_112 < 0 ) {
F_9 ( V_11 , L_43 , V_112 ) ;
goto error;
}
}
V_112 = F_83 ( V_167 ) ;
if ( V_112 )
goto error;
V_18 = V_167 -> V_18 ;
F_84 ( V_18 ) ;
F_85 (child, &bus->children, node)
F_86 ( V_165 ) ;
F_87 ( V_18 ) ;
return 0 ;
error:
F_88 ( & V_161 ) ;
return V_112 ;
}
