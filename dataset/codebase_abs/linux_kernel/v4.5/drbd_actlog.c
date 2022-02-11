void * F_1 ( struct V_1 * V_2 , const char * V_3 )
{
int V_4 ;
F_2 ( V_2 -> V_5 ,
( V_4 = F_3 ( & V_2 -> V_6 . V_7 , 0 , 1 ) ) == 0 ||
V_2 -> V_8 . V_9 <= V_10 ) ;
if ( V_4 )
return NULL ;
V_2 -> V_6 . V_11 = V_3 ;
V_2 -> V_6 . V_12 = V_13 ;
V_2 -> V_6 . V_14 = V_2 -> V_6 . V_12 - 1 ;
return F_4 ( V_2 -> V_6 . V_15 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( & V_2 -> V_6 . V_7 ) )
F_7 ( & V_2 -> V_5 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_16 * V_17 ,
unsigned int * V_18 )
{
long V_19 ;
F_9 () ;
V_19 = F_10 ( V_17 -> V_20 ) -> V_21 ;
F_11 () ;
V_19 = V_19 * V_22 / 10 ;
if ( V_19 == 0 )
V_19 = V_23 ;
V_19 = F_12 ( V_2 -> V_5 ,
* V_18 || F_13 ( V_24 , & V_2 -> V_25 ) , V_19 ) ;
if ( V_19 == 0 ) {
F_14 ( V_2 , L_1 ) ;
F_15 ( V_2 , 1 , V_26 ) ;
}
}
static int F_16 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
T_1 V_27 , int V_28 )
{
struct V_29 * V_29 ;
const int V_30 = 4096 ;
int V_31 ;
V_2 -> V_6 . V_18 = 0 ;
V_2 -> V_6 . error = - V_32 ;
if ( ( V_28 & V_33 ) && ! F_13 ( V_34 , & V_2 -> V_25 ) )
V_28 |= V_35 | V_36 ;
V_28 |= V_37 | V_38 ;
V_29 = F_17 ( V_39 ) ;
V_29 -> V_40 = V_17 -> V_41 ;
V_29 -> V_42 . V_43 = V_27 ;
V_31 = - V_44 ;
if ( F_18 ( V_29 , V_2 -> V_6 . V_15 , V_30 , 0 ) != V_30 )
goto V_45;
V_29 -> V_46 = V_2 ;
V_29 -> V_47 = V_48 ;
V_29 -> V_49 = V_28 ;
if ( ! ( V_28 & V_33 ) && V_2 -> V_8 . V_9 == V_50 && V_2 -> V_51 == NULL )
;
else if ( ! F_19 ( V_2 , V_52 ) ) {
F_14 ( V_2 , L_2 ) ;
V_31 = - V_32 ;
goto V_45;
}
F_20 ( V_29 ) ;
F_21 ( & V_2 -> V_6 . V_7 ) ;
V_2 -> V_6 . V_14 = V_13 ;
if ( F_22 ( V_2 , ( V_28 & V_33 ) ? V_53 : V_54 ) )
F_23 ( V_29 ) ;
else
F_24 ( V_28 , V_29 ) ;
F_8 ( V_2 , V_17 , & V_2 -> V_6 . V_18 ) ;
if ( ! V_29 -> V_55 )
V_31 = V_2 -> V_6 . error ;
V_45:
F_25 ( V_29 ) ;
return V_31 ;
}
int F_26 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_1 V_27 , int V_28 )
{
int V_31 ;
F_27 ( V_2 , F_28 ( & V_2 -> V_6 . V_7 ) == 1 ) ;
F_29 ( ! V_17 -> V_41 ) ;
F_30 ( V_2 , L_3 ,
V_56 -> V_57 , V_56 -> V_58 , V_59 ,
( unsigned long long ) V_27 , ( V_28 & V_33 ) ? L_4 : L_5 ,
( void * ) V_60 ) ;
if ( V_27 < V_61 ( V_17 ) ||
V_27 + 7 > F_31 ( V_17 ) )
F_32 ( V_2 , L_6 ,
V_56 -> V_57 , V_56 -> V_58 , V_59 ,
( unsigned long long ) V_27 , ( V_28 & V_33 ) ? L_4 : L_5 ) ;
V_31 = F_16 ( V_2 , V_17 , V_27 , V_28 ) ;
if ( V_31 ) {
F_14 ( V_2 , L_7 ,
( unsigned long long ) V_27 , ( V_28 & V_33 ) ? L_4 : L_5 , V_31 ) ;
}
return V_31 ;
}
static struct V_62 * F_33 ( struct V_1 * V_2 , unsigned int V_63 )
{
struct V_64 * V_65 ;
V_65 = F_34 ( V_2 -> V_66 , V_63 / V_67 ) ;
if ( F_35 ( V_65 != NULL ) ) {
struct V_62 * V_68 = F_36 ( V_65 , struct V_62 , V_69 ) ;
if ( F_13 ( V_70 , & V_68 -> V_25 ) )
return V_68 ;
}
return NULL ;
}
static struct V_64 * F_37 ( struct V_1 * V_2 , unsigned int V_63 , bool V_71 )
{
struct V_64 * V_72 ;
struct V_62 * V_68 ;
int V_73 ;
F_38 ( & V_2 -> V_74 ) ;
V_68 = F_33 ( V_2 , V_63 ) ;
if ( V_68 ) {
V_73 = ! F_39 ( V_75 , & V_68 -> V_25 ) ;
F_40 ( & V_2 -> V_74 ) ;
if ( V_73 )
F_7 ( & V_2 -> V_76 ) ;
return NULL ;
}
if ( V_71 )
V_72 = F_41 ( V_2 -> V_77 , V_63 ) ;
else
V_72 = F_42 ( V_2 -> V_77 , V_63 ) ;
F_40 ( & V_2 -> V_74 ) ;
return V_72 ;
}
bool F_43 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
F_27 ( V_2 , ( unsigned ) ( V_82 - V_80 ) <= 1 ) ;
F_27 ( V_2 , F_28 ( & V_2 -> V_83 ) > 0 ) ;
if ( V_80 != V_82 )
return false ;
return F_37 ( V_2 , V_80 , true ) ;
}
bool F_44 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
unsigned V_63 ;
bool V_84 = false ;
F_27 ( V_2 , V_80 <= V_82 ) ;
F_27 ( V_2 , F_28 ( & V_2 -> V_83 ) > 0 ) ;
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
struct V_64 * V_72 ;
F_2 ( V_2 -> V_76 ,
( V_72 = F_37 ( V_2 , V_63 , false ) ) != NULL ) ;
if ( V_72 -> V_85 != V_63 )
V_84 = true ;
}
return V_84 ;
}
static unsigned int F_45 ( unsigned int V_86 )
{
return V_86 >>
( ( V_87 + 3 ) -
( V_81 - V_88 ) ) ;
}
static T_1 F_46 ( struct V_1 * V_2 )
{
const unsigned int V_89 = V_2 -> V_51 -> V_90 . V_91 ;
const unsigned int V_92 = V_2 -> V_51 -> V_90 . V_93 ;
unsigned int V_94 = V_2 -> V_95 % ( V_2 -> V_51 -> V_90 . V_96 ) ;
V_94 = ( ( V_94 % V_89 ) * V_92 ) + V_94 / V_89 ;
V_94 *= 8 ;
return V_2 -> V_51 -> V_90 . V_97 + V_2 -> V_51 -> V_90 . V_98 + V_94 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
struct V_64 * V_101 ;
T_1 V_27 ;
int V_79 , V_102 ;
unsigned V_103 ;
unsigned V_104 = 0 ;
int V_31 = 0 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_105 = F_48 ( V_106 ) ;
V_100 -> V_107 = F_48 ( V_2 -> V_95 ) ;
V_79 = 0 ;
F_38 ( & V_2 -> V_74 ) ;
F_49 (e, &device->act_log->to_be_changed, list) {
if ( V_79 == V_108 ) {
V_79 ++ ;
break;
}
V_100 -> V_109 [ V_79 ] = F_50 ( V_101 -> V_110 ) ;
V_100 -> V_111 [ V_79 ] = F_48 ( V_101 -> V_112 ) ;
if ( V_101 -> V_85 != V_113 )
F_51 ( V_2 ,
F_45 ( V_101 -> V_85 ) ) ;
V_79 ++ ;
}
F_40 ( & V_2 -> V_74 ) ;
F_29 ( V_79 > V_108 ) ;
V_100 -> V_114 = F_50 ( V_79 ) ;
for ( ; V_79 < V_108 ; V_79 ++ ) {
V_100 -> V_109 [ V_79 ] = F_50 ( - 1 ) ;
V_100 -> V_111 [ V_79 ] = F_48 ( V_113 ) ;
}
V_100 -> V_115 = F_50 ( V_2 -> V_77 -> V_116 ) ;
V_100 -> V_117 = F_50 ( V_2 -> V_118 ) ;
V_102 = F_52 ( int , V_119 ,
V_2 -> V_77 -> V_116 - V_2 -> V_118 ) ;
for ( V_79 = 0 ; V_79 < V_102 ; V_79 ++ ) {
unsigned V_120 = V_2 -> V_118 + V_79 ;
V_103 = F_53 ( V_2 -> V_77 , V_120 ) -> V_85 ;
V_100 -> V_121 [ V_79 ] = F_48 ( V_103 ) ;
}
for (; V_79 < V_119 ; V_79 ++ )
V_100 -> V_121 [ V_79 ] = F_48 ( V_113 ) ;
V_2 -> V_118 += V_119 ;
if ( V_2 -> V_118 >= V_2 -> V_77 -> V_116 )
V_2 -> V_118 = 0 ;
V_27 = F_46 ( V_2 ) ;
V_104 = F_54 ( 0 , V_100 , 4096 ) ;
V_100 -> F_54 = F_48 ( V_104 ) ;
if ( F_55 ( V_2 ) )
V_31 = - V_44 ;
else {
bool V_122 ;
F_9 () ;
V_122 = F_10 ( V_2 -> V_51 -> V_20 ) -> V_123 ;
F_11 () ;
if ( V_122 ) {
if ( F_26 ( V_2 , V_2 -> V_51 , V_27 , V_33 ) ) {
V_31 = - V_44 ;
F_15 ( V_2 , 1 , V_124 ) ;
} else {
V_2 -> V_95 ++ ;
V_2 -> V_125 ++ ;
}
}
}
return V_31 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_99 * V_100 ;
int V_31 ;
if ( ! F_57 ( V_2 ) ) {
F_14 ( V_2 , L_8 ,
F_58 ( V_2 -> V_8 . V_9 ) ) ;
return - V_44 ;
}
if ( V_2 -> V_8 . V_9 < V_126 ) {
F_14 ( V_2 ,
L_9 ,
F_58 ( V_2 -> V_8 . V_9 ) ) ;
F_59 ( V_2 ) ;
return - V_44 ;
}
V_100 = F_1 ( V_2 , V_59 ) ;
if ( ! V_100 ) {
F_14 ( V_2 , L_10 ) ;
F_59 ( V_2 ) ;
return - V_32 ;
}
V_31 = F_47 ( V_2 , V_100 ) ;
F_5 ( V_2 ) ;
F_59 ( V_2 ) ;
return V_31 ;
}
void F_60 ( struct V_1 * V_2 )
{
bool V_127 = false ;
F_2 ( V_2 -> V_76 ,
V_2 -> V_77 -> V_128 == 0 ||
( V_127 = F_61 ( V_2 -> V_77 ) ) ) ;
if ( V_127 ) {
if ( V_2 -> V_77 -> V_128 ) {
bool V_122 ;
F_9 () ;
V_122 = F_10 ( V_2 -> V_51 -> V_20 ) -> V_123 ;
F_11 () ;
if ( V_122 )
F_56 ( V_2 ) ;
F_38 ( & V_2 -> V_74 ) ;
F_62 ( V_2 -> V_77 ) ;
F_40 ( & V_2 -> V_74 ) ;
}
F_63 ( V_2 -> V_77 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
}
void F_64 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
if ( F_44 ( V_2 , V_79 ) )
F_60 ( V_2 ) ;
}
int F_65 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_129 * V_130 = V_2 -> V_77 ;
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
unsigned V_131 ;
unsigned V_132 ;
unsigned V_63 ;
F_27 ( V_2 , V_80 <= V_82 ) ;
V_131 = 1 + V_82 - V_80 ;
V_132 = F_66 ( V_130 -> V_116 - V_130 -> V_133 ,
V_130 -> V_134 - V_130 -> V_128 ) ;
if ( V_132 < V_131 ) {
if ( ! V_130 -> V_128 )
F_67 ( V_135 , & V_2 -> V_77 -> V_25 ) ;
return - V_136 ;
}
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
struct V_64 * V_65 ;
V_65 = F_34 ( V_2 -> V_66 , V_63 / V_67 ) ;
if ( F_35 ( V_65 != NULL ) ) {
struct V_62 * V_68 = F_36 ( V_65 , struct V_62 , V_69 ) ;
if ( F_13 ( V_70 , & V_68 -> V_25 ) ) {
if ( ! F_39 ( V_75 , & V_68 -> V_25 ) )
return - V_137 ;
return - V_138 ;
}
}
}
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
struct V_64 * V_72 ;
V_72 = F_68 ( V_2 -> V_77 , V_63 ) ;
if ( ! V_72 )
F_69 ( V_2 , L_11 , V_63 ) ;
}
return 0 ;
}
void F_70 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
unsigned V_63 ;
struct V_64 * V_139 ;
unsigned long V_25 ;
F_27 ( V_2 , V_80 <= V_82 ) ;
F_71 ( & V_2 -> V_74 , V_25 ) ;
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
V_139 = F_34 ( V_2 -> V_77 , V_63 ) ;
if ( ! V_139 ) {
F_14 ( V_2 , L_12 , V_63 ) ;
continue;
}
F_72 ( V_2 -> V_77 , V_139 ) ;
}
F_73 ( & V_2 -> V_74 , V_25 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_64 * V_72 )
{
int V_140 ;
F_38 ( & V_2 -> V_74 ) ;
V_140 = ( V_72 -> V_141 == 0 ) ;
if ( F_75 ( V_140 ) )
F_76 ( V_2 -> V_77 , V_72 ) ;
F_40 ( & V_2 -> V_74 ) ;
return V_140 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_64 * V_72 ;
int V_79 ;
F_27 ( V_2 , F_13 ( V_142 , & V_2 -> V_77 -> V_25 ) ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_77 -> V_116 ; V_79 ++ ) {
V_72 = F_53 ( V_2 -> V_77 , V_79 ) ;
if ( V_72 -> V_85 == V_113 )
continue;
F_2 ( V_2 -> V_76 , F_74 ( V_2 , V_72 ) ) ;
}
F_7 ( & V_2 -> V_76 ) ;
}
int F_78 ( struct V_1 * V_2 , void * V_100 )
{
struct V_99 * V_130 = V_100 ;
struct V_143 * V_90 = & V_2 -> V_51 -> V_90 ;
int V_96 = V_90 -> V_91 * V_90 -> V_93 ;
int V_79 ;
F_47 ( V_2 , V_130 ) ;
F_38 ( & V_2 -> V_74 ) ;
F_62 ( V_2 -> V_77 ) ;
F_40 ( & V_2 -> V_74 ) ;
for ( V_79 = 1 ; V_79 < V_96 ; V_79 ++ ) {
int V_31 = F_47 ( V_2 , V_130 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static bool F_79 ( struct V_1 * V_2 ,
unsigned int V_63 , int V_144 ,
enum V_145 V_146 )
{
struct V_64 * V_101 ;
F_27 ( V_2 , F_28 ( & V_2 -> V_83 ) ) ;
if ( V_146 == V_147 )
V_101 = F_34 ( V_2 -> V_66 , V_63 ) ;
else
V_101 = F_42 ( V_2 -> V_66 , V_63 ) ;
if ( V_101 ) {
struct V_62 * V_148 = F_36 ( V_101 , struct V_62 , V_69 ) ;
if ( V_148 -> V_69 . V_85 == V_63 ) {
if ( V_146 == V_149 )
V_148 -> V_150 -= V_144 ;
else if ( V_146 == V_147 )
V_148 -> V_150 += V_144 ;
else
V_148 -> V_151 += V_144 ;
if ( V_148 -> V_150 < V_148 -> V_151 ) {
F_80 ( V_2 , L_13
L_14 ,
V_148 -> V_69 . V_85 , V_148 -> V_150 ,
V_148 -> V_151 , V_144 ,
F_81 ( V_2 -> V_8 . V_152 ) ) ;
V_148 -> V_150 = F_82 ( V_2 , V_63 ) ;
}
} else {
int V_150 = F_82 ( V_2 , V_63 ) ;
if ( V_148 -> V_25 != 0 ) {
F_80 ( V_2 , L_15
L_16 ,
V_148 -> V_69 . V_85 , V_148 -> V_150 ,
V_148 -> V_25 , V_63 , V_150 ) ;
V_148 -> V_25 = 0 ;
}
if ( V_148 -> V_151 ) {
F_80 ( V_2 , L_17
L_18 ,
V_148 -> V_69 . V_85 , V_148 -> V_151 ) ;
}
V_148 -> V_150 = V_150 ;
V_148 -> V_151 = ( V_146 == V_153 ) ? V_144 : 0 ;
F_62 ( V_2 -> V_66 ) ;
}
if ( V_146 != V_147 )
F_72 ( V_2 -> V_66 , & V_148 -> V_69 ) ;
if ( V_148 -> V_150 <= V_148 -> V_151 ) {
V_148 -> V_151 = 0 ;
return true ;
}
} else if ( V_146 != V_147 ) {
F_14 ( V_2 , L_19 ,
V_2 -> V_154 ,
V_2 -> V_66 -> V_116 ,
V_2 -> V_66 -> V_25 ) ;
}
return false ;
}
void F_83 ( struct V_1 * V_2 , unsigned long V_155 )
{
unsigned long V_156 = V_13 ;
unsigned long V_82 = V_2 -> V_157 [ V_2 -> V_158 ] ;
int V_159 = ( V_2 -> V_158 + 1 ) % V_160 ;
if ( F_84 ( V_156 , V_82 + V_161 ) ) {
if ( V_2 -> V_162 [ V_2 -> V_158 ] != V_155 &&
V_2 -> V_8 . V_152 != V_163 &&
V_2 -> V_8 . V_152 != V_164 ) {
V_2 -> V_157 [ V_159 ] = V_156 ;
V_2 -> V_162 [ V_159 ] = V_155 ;
V_2 -> V_158 = V_159 ;
}
}
}
static bool F_85 ( struct V_1 * V_2 )
{
return F_86 ( V_13 , V_2 -> V_165 + 2 * V_22 ) ;
}
static void F_87 ( struct V_1 * V_2 , bool V_166 )
{
if ( V_166 )
F_88 ( V_167 , & V_2 -> V_25 ) ;
else if ( ! F_85 ( V_2 ) )
return;
F_89 ( V_2 , V_168 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
unsigned long V_169 , unsigned long V_170 ,
enum V_145 V_146 )
{
unsigned long V_25 ;
unsigned long V_144 = 0 ;
unsigned int V_171 = 0 ;
while ( V_169 <= V_170 ) {
unsigned long V_172 = F_66 ( V_170 , V_169 | V_173 ) ;
unsigned long V_174 ;
if ( V_146 == V_153 )
V_174 = F_91 ( V_2 , V_169 , V_172 ) ;
else if ( V_146 == V_149 )
V_174 = F_92 ( V_2 , V_169 , V_172 ) ;
else
V_174 = F_93 ( V_2 , V_169 , V_172 ) ;
if ( V_174 ) {
F_71 ( & V_2 -> V_74 , V_25 ) ;
V_171 += F_79 ( V_2 , F_94 ( V_169 ) , V_174 , V_146 ) ;
F_73 ( & V_2 -> V_74 , V_25 ) ;
V_144 += V_174 ;
}
V_169 = V_172 + 1 ;
}
if ( V_144 ) {
if ( V_146 == V_149 ) {
unsigned long V_155 = F_95 ( V_2 ) ;
bool V_175 = ( V_155 <= V_2 -> V_151 ) ;
F_83 ( V_2 , V_155 ) ;
if ( V_171 || V_175 )
F_87 ( V_2 , V_175 ) ;
} else if ( V_146 == V_153 )
V_2 -> V_151 += V_144 ;
F_7 ( & V_2 -> V_76 ) ;
}
return V_144 ;
}
int F_96 ( struct V_1 * V_2 , T_1 V_27 , int V_30 ,
enum V_145 V_146 )
{
unsigned long V_169 , V_170 , V_176 ;
unsigned long V_144 = 0 ;
T_1 V_177 , V_178 ;
if ( ( V_146 == V_147 ) && V_30 == 0 )
return 0 ;
if ( V_30 <= 0 || ! F_97 ( V_30 , 512 ) || V_30 > V_179 ) {
F_14 ( V_2 , L_20 ,
V_180 [ V_146 ] ,
( unsigned long long ) V_27 , V_30 ) ;
return 0 ;
}
if ( ! F_57 ( V_2 ) )
return 0 ;
V_178 = F_98 ( V_2 -> V_181 ) ;
V_177 = V_27 + ( V_30 >> 9 ) - 1 ;
if ( ! F_99 ( V_27 < V_178 ) )
goto V_45;
if ( ! F_99 ( V_177 < V_178 ) )
V_177 = V_178 - 1 ;
V_176 = F_100 ( V_178 - 1 ) ;
if ( V_146 == V_149 ) {
if ( F_35 ( V_177 < V_182 - 1 ) )
goto V_45;
if ( F_35 ( V_177 == ( V_178 - 1 ) ) )
V_170 = V_176 ;
else
V_170 = F_100 ( V_177 - ( V_182 - 1 ) ) ;
V_169 = F_100 ( V_27 + V_182 - 1 ) ;
} else {
V_169 = F_100 ( V_27 ) ;
V_170 = F_100 ( V_177 ) ;
}
V_144 = F_90 ( V_2 , V_169 , V_170 , V_146 ) ;
V_45:
F_59 ( V_2 ) ;
return V_144 ;
}
static
struct V_62 * F_101 ( struct V_1 * V_2 , unsigned int V_63 )
{
struct V_64 * V_101 ;
struct V_62 * V_68 ;
int V_183 = 0 ;
unsigned long V_184 ;
F_38 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_154 > V_2 -> V_66 -> V_116 / 2 ) {
F_40 ( & V_2 -> V_74 ) ;
return NULL ;
}
V_101 = F_42 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_101 ? F_36 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
if ( V_68 -> V_69 . V_85 != V_63 ) {
V_68 -> V_150 = F_82 ( V_2 , V_63 ) ;
V_68 -> V_151 = 0 ;
F_62 ( V_2 -> V_66 ) ;
V_183 = 1 ;
}
if ( V_68 -> V_69 . V_141 == 1 )
V_2 -> V_154 ++ ;
F_88 ( V_70 , & V_68 -> V_25 ) ;
}
V_184 = V_2 -> V_66 -> V_25 ;
F_40 ( & V_2 -> V_74 ) ;
if ( V_183 )
F_7 ( & V_2 -> V_76 ) ;
if ( ! V_68 ) {
if ( V_184 & V_185 )
F_80 ( V_2 , L_21
L_22 ) ;
F_29 ( V_184 & V_186 ) ;
}
return V_68 ;
}
static int F_102 ( struct V_1 * V_2 , unsigned int V_63 )
{
int V_140 ;
F_38 ( & V_2 -> V_74 ) ;
V_140 = F_103 ( V_2 -> V_77 , V_63 ) ;
F_40 ( & V_2 -> V_74 ) ;
return V_140 ;
}
int F_104 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_105 ( V_27 ) ;
struct V_62 * V_68 ;
int V_79 , V_187 ;
bool V_188 ;
V_189:
V_187 = F_106 ( V_2 -> V_76 ,
( V_68 = F_101 ( V_2 , V_63 ) ) ) ;
if ( V_187 )
return - V_190 ;
if ( F_13 ( V_191 , & V_68 -> V_25 ) )
return 0 ;
V_188 = F_107 ( V_2 ) ;
for ( V_79 = 0 ; V_79 < V_67 ; V_79 ++ ) {
V_187 = F_106 ( V_2 -> V_76 ,
! F_102 ( V_2 , V_63 * V_67 + V_79 ) ||
( V_188 && F_13 ( V_75 , & V_68 -> V_25 ) ) ) ;
if ( V_187 || ( V_188 && F_13 ( V_75 , & V_68 -> V_25 ) ) ) {
F_38 ( & V_2 -> V_74 ) ;
if ( F_72 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_154 -- ;
F_7 ( & V_2 -> V_76 ) ;
}
F_40 ( & V_2 -> V_74 ) ;
if ( V_187 )
return - V_190 ;
if ( F_108 ( V_22 / 10 ) )
return - V_190 ;
goto V_189;
}
}
F_88 ( V_191 , & V_68 -> V_25 ) ;
return 0 ;
}
int F_109 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_105 ( V_27 ) ;
const unsigned int V_86 = V_63 * V_67 ;
struct V_64 * V_101 ;
struct V_62 * V_68 ;
int V_79 ;
bool V_192 = F_110 ( V_2 , V_27 , true ) ;
if ( V_192 && V_2 -> V_193 != V_63 )
return - V_194 ;
F_38 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_193 != V_113 && V_2 -> V_193 != V_63 ) {
V_101 = F_34 ( V_2 -> V_66 , V_2 -> V_193 ) ;
V_68 = V_101 ? F_36 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
F_27 ( V_2 , ! F_13 ( V_191 , & V_68 -> V_25 ) ) ;
F_27 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_111 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_193 = V_113 ;
if ( F_72 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_154 -- ;
}
F_7 ( & V_2 -> V_76 ) ;
} else {
F_32 ( V_2 , L_23 ) ;
}
}
V_101 = F_41 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_101 ? F_36 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
if ( F_13 ( V_191 , & V_68 -> V_25 ) )
goto V_195;
if ( ! F_39 ( V_70 , & V_68 -> V_25 ) ) {
V_2 -> V_154 ++ ;
} else {
V_68 -> V_69 . V_141 -- ;
F_27 ( V_2 , V_68 -> V_69 . V_141 > 0 ) ;
}
goto V_196;
} else {
if ( V_2 -> V_154 > V_2 -> V_66 -> V_116 - 3 )
goto V_197;
V_101 = F_42 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_101 ? F_36 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( ! V_68 ) {
const unsigned long V_184 = V_2 -> V_66 -> V_25 ;
if ( V_184 & V_185 )
F_80 ( V_2 , L_21
L_22 ) ;
F_29 ( V_184 & V_186 ) ;
goto V_197;
}
if ( V_68 -> V_69 . V_85 != V_63 ) {
V_68 -> V_150 = F_82 ( V_2 , V_63 ) ;
V_68 -> V_151 = 0 ;
F_62 ( V_2 -> V_66 ) ;
F_7 ( & V_2 -> V_76 ) ;
F_27 ( V_2 , F_13 ( V_191 , & V_68 -> V_25 ) == 0 ) ;
}
F_88 ( V_70 , & V_68 -> V_25 ) ;
F_27 ( V_2 , V_68 -> V_69 . V_141 == 1 ) ;
V_2 -> V_154 ++ ;
goto V_196;
}
V_196:
for ( V_79 = 0 ; V_79 < V_67 ; V_79 ++ ) {
if ( F_103 ( V_2 -> V_77 , V_86 + V_79 ) )
goto V_197;
}
F_88 ( V_191 , & V_68 -> V_25 ) ;
V_195:
V_2 -> V_193 = V_113 ;
F_40 ( & V_2 -> V_74 ) ;
return 0 ;
V_197:
if ( V_68 ) {
if ( V_192 ) {
F_27 ( V_2 , ! F_13 ( V_191 , & V_68 -> V_25 ) ) ;
F_27 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_111 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_193 = V_113 ;
if ( F_72 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_154 -- ;
}
F_7 ( & V_2 -> V_76 ) ;
} else
V_2 -> V_193 = V_63 ;
}
F_40 ( & V_2 -> V_74 ) ;
return - V_194 ;
}
void F_112 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_105 ( V_27 ) ;
struct V_64 * V_101 ;
struct V_62 * V_68 ;
unsigned long V_25 ;
F_71 ( & V_2 -> V_74 , V_25 ) ;
V_101 = F_34 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_101 ? F_36 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( ! V_68 ) {
F_73 ( & V_2 -> V_74 , V_25 ) ;
if ( F_113 ( & V_198 ) )
F_14 ( V_2 , L_24 ) ;
return;
}
if ( V_68 -> V_69 . V_141 == 0 ) {
F_73 ( & V_2 -> V_74 , V_25 ) ;
F_14 ( V_2 , L_25
L_26 ,
( unsigned long long ) V_27 , V_63 ) ;
return;
}
if ( F_72 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_154 -- ;
F_7 ( & V_2 -> V_76 ) ;
}
F_73 ( & V_2 -> V_74 , V_25 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_74 ) ;
if ( F_19 ( V_2 , V_10 ) ) {
F_115 ( V_2 -> V_66 ) ;
F_59 ( V_2 ) ;
}
V_2 -> V_154 = 0 ;
V_2 -> V_193 = V_113 ;
F_40 ( & V_2 -> V_74 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
int F_116 ( struct V_1 * V_2 )
{
struct V_64 * V_101 ;
struct V_62 * V_68 ;
int V_79 ;
F_38 ( & V_2 -> V_74 ) ;
if ( F_19 ( V_2 , V_10 ) ) {
for ( V_79 = 0 ; V_79 < V_2 -> V_66 -> V_116 ; V_79 ++ ) {
V_101 = F_53 ( V_2 -> V_66 , V_79 ) ;
V_68 = F_36 ( V_101 , struct V_62 , V_69 ) ;
if ( V_68 -> V_69 . V_85 == V_113 )
continue;
if ( V_68 -> V_69 . V_85 == V_2 -> V_193 ) {
F_69 ( V_2 , L_27
L_28 ,
V_2 -> V_193 ) ;
F_27 ( V_2 , ! F_13 ( V_191 , & V_68 -> V_25 ) ) ;
F_27 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_111 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_193 = V_113 ;
F_72 ( V_2 -> V_66 , & V_68 -> V_69 ) ;
}
if ( V_68 -> V_69 . V_141 != 0 ) {
F_69 ( V_2 , L_29
L_30 , V_68 -> V_69 . V_141 ) ;
F_59 ( V_2 ) ;
F_40 ( & V_2 -> V_74 ) ;
return - V_194 ;
}
F_27 ( V_2 , ! F_13 ( V_191 , & V_68 -> V_25 ) ) ;
F_27 ( V_2 , ! F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_76 ( V_2 -> V_66 , & V_68 -> V_69 ) ;
}
F_27 ( V_2 , V_2 -> V_66 -> V_133 == 0 ) ;
F_59 ( V_2 ) ;
}
F_40 ( & V_2 -> V_74 ) ;
F_7 ( & V_2 -> V_76 ) ;
return 0 ;
}
