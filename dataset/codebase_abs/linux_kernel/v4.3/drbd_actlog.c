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
void F_45 ( struct V_1 * V_2 )
{
bool V_86 = false ;
F_2 ( V_2 -> V_76 ,
V_2 -> V_77 -> V_87 == 0 ||
( V_86 = F_46 ( V_2 -> V_77 ) ) ) ;
if ( V_86 ) {
if ( V_2 -> V_77 -> V_87 ) {
bool V_88 ;
F_9 () ;
V_88 = F_10 ( V_2 -> V_51 -> V_20 ) -> V_89 ;
F_11 () ;
if ( V_88 )
F_47 ( V_2 ) ;
F_38 ( & V_2 -> V_74 ) ;
F_48 ( V_2 -> V_77 ) ;
F_40 ( & V_2 -> V_74 ) ;
}
F_49 ( V_2 -> V_77 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
}
void F_50 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
if ( F_44 ( V_2 , V_79 ) )
F_45 ( V_2 ) ;
}
int F_51 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_90 * V_91 = V_2 -> V_77 ;
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
unsigned V_92 ;
unsigned V_93 ;
unsigned V_63 ;
F_27 ( V_2 , V_80 <= V_82 ) ;
V_92 = 1 + V_82 - V_80 ;
V_93 = F_52 ( V_91 -> V_94 - V_91 -> V_95 ,
V_91 -> V_96 - V_91 -> V_87 ) ;
if ( V_93 < V_92 ) {
if ( ! V_91 -> V_87 )
F_53 ( V_97 , & V_2 -> V_77 -> V_25 ) ;
return - V_98 ;
}
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
struct V_64 * V_65 ;
V_65 = F_34 ( V_2 -> V_66 , V_63 / V_67 ) ;
if ( F_35 ( V_65 != NULL ) ) {
struct V_62 * V_68 = F_36 ( V_65 , struct V_62 , V_69 ) ;
if ( F_13 ( V_70 , & V_68 -> V_25 ) ) {
if ( ! F_39 ( V_75 , & V_68 -> V_25 ) )
return - V_99 ;
return - V_100 ;
}
}
}
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
struct V_64 * V_72 ;
V_72 = F_54 ( V_2 -> V_77 , V_63 ) ;
if ( ! V_72 )
F_55 ( V_2 , L_8 , V_63 ) ;
}
return 0 ;
}
void F_56 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
unsigned V_63 ;
struct V_64 * V_101 ;
unsigned long V_25 ;
F_27 ( V_2 , V_80 <= V_82 ) ;
F_57 ( & V_2 -> V_74 , V_25 ) ;
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
V_101 = F_34 ( V_2 -> V_77 , V_63 ) ;
if ( ! V_101 ) {
F_14 ( V_2 , L_9 , V_63 ) ;
continue;
}
F_58 ( V_2 -> V_77 , V_101 ) ;
}
F_59 ( & V_2 -> V_74 , V_25 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
static unsigned int F_60 ( unsigned int V_102 )
{
return V_102 >>
( ( V_103 + 3 ) -
( V_81 - V_104 ) ) ;
}
static T_1 F_61 ( struct V_1 * V_2 )
{
const unsigned int V_105 = V_2 -> V_51 -> V_106 . V_107 ;
const unsigned int V_108 = V_2 -> V_51 -> V_106 . V_109 ;
unsigned int V_110 = V_2 -> V_111 % ( V_2 -> V_51 -> V_106 . V_112 ) ;
V_110 = ( ( V_110 % V_105 ) * V_108 ) + V_110 / V_105 ;
V_110 *= 8 ;
return V_2 -> V_51 -> V_106 . V_113 + V_2 -> V_51 -> V_106 . V_114 + V_110 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_115 * V_116 ;
struct V_64 * V_117 ;
T_1 V_27 ;
int V_79 , V_118 ;
unsigned V_119 ;
unsigned V_120 = 0 ;
int V_31 = 0 ;
if ( ! F_62 ( V_2 ) ) {
F_14 ( V_2 , L_10 ,
F_63 ( V_2 -> V_8 . V_9 ) ) ;
return - V_44 ;
}
if ( V_2 -> V_8 . V_9 < V_121 ) {
F_14 ( V_2 ,
L_11 ,
F_63 ( V_2 -> V_8 . V_9 ) ) ;
F_64 ( V_2 ) ;
return - V_44 ;
}
V_116 = F_1 ( V_2 , V_59 ) ;
if ( ! V_116 ) {
F_14 ( V_2 , L_12 ) ;
F_64 ( V_2 ) ;
return - V_32 ;
}
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_122 = F_65 ( V_123 ) ;
V_116 -> V_124 = F_65 ( V_2 -> V_111 ) ;
V_79 = 0 ;
F_38 ( & V_2 -> V_74 ) ;
F_66 (e, &device->act_log->to_be_changed, list) {
if ( V_79 == V_125 ) {
V_79 ++ ;
break;
}
V_116 -> V_126 [ V_79 ] = F_67 ( V_117 -> V_127 ) ;
V_116 -> V_128 [ V_79 ] = F_65 ( V_117 -> V_129 ) ;
if ( V_117 -> V_85 != V_130 )
F_68 ( V_2 ,
F_60 ( V_117 -> V_85 ) ) ;
V_79 ++ ;
}
F_40 ( & V_2 -> V_74 ) ;
F_29 ( V_79 > V_125 ) ;
V_116 -> V_131 = F_67 ( V_79 ) ;
for ( ; V_79 < V_125 ; V_79 ++ ) {
V_116 -> V_126 [ V_79 ] = F_67 ( - 1 ) ;
V_116 -> V_128 [ V_79 ] = F_65 ( V_130 ) ;
}
V_116 -> V_132 = F_67 ( V_2 -> V_77 -> V_94 ) ;
V_116 -> V_133 = F_67 ( V_2 -> V_134 ) ;
V_118 = F_69 ( int , V_135 ,
V_2 -> V_77 -> V_94 - V_2 -> V_134 ) ;
for ( V_79 = 0 ; V_79 < V_118 ; V_79 ++ ) {
unsigned V_136 = V_2 -> V_134 + V_79 ;
V_119 = F_70 ( V_2 -> V_77 , V_136 ) -> V_85 ;
V_116 -> V_137 [ V_79 ] = F_65 ( V_119 ) ;
}
for (; V_79 < V_135 ; V_79 ++ )
V_116 -> V_137 [ V_79 ] = F_65 ( V_130 ) ;
V_2 -> V_134 += V_135 ;
if ( V_2 -> V_134 >= V_2 -> V_77 -> V_94 )
V_2 -> V_134 = 0 ;
V_27 = F_61 ( V_2 ) ;
V_120 = F_71 ( 0 , V_116 , 4096 ) ;
V_116 -> F_71 = F_65 ( V_120 ) ;
if ( F_72 ( V_2 ) )
V_31 = - V_44 ;
else {
bool V_88 ;
F_9 () ;
V_88 = F_10 ( V_2 -> V_51 -> V_20 ) -> V_89 ;
F_11 () ;
if ( V_88 ) {
if ( F_26 ( V_2 , V_2 -> V_51 , V_27 , V_33 ) ) {
V_31 = - V_44 ;
F_15 ( V_2 , 1 , V_138 ) ;
} else {
V_2 -> V_111 ++ ;
V_2 -> V_139 ++ ;
}
}
}
F_5 ( V_2 ) ;
F_64 ( V_2 ) ;
return V_31 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_64 * V_72 )
{
int V_140 ;
F_38 ( & V_2 -> V_74 ) ;
V_140 = ( V_72 -> V_141 == 0 ) ;
if ( F_74 ( V_140 ) )
F_75 ( V_2 -> V_77 , V_72 ) ;
F_40 ( & V_2 -> V_74 ) ;
return V_140 ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_64 * V_72 ;
int V_79 ;
F_27 ( V_2 , F_13 ( V_142 , & V_2 -> V_77 -> V_25 ) ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_77 -> V_94 ; V_79 ++ ) {
V_72 = F_70 ( V_2 -> V_77 , V_79 ) ;
if ( V_72 -> V_85 == V_130 )
continue;
F_2 ( V_2 -> V_76 , F_73 ( V_2 , V_72 ) ) ;
}
F_7 ( & V_2 -> V_76 ) ;
}
int F_77 ( struct V_1 * V_2 , void * V_116 )
{
struct V_115 * V_91 = V_116 ;
struct V_143 * V_106 = & V_2 -> V_51 -> V_106 ;
T_1 V_144 = V_106 -> V_113 + V_106 -> V_114 ;
int V_112 = V_106 -> V_107 * V_106 -> V_109 ;
int V_79 ;
memset ( V_91 , 0 , 4096 ) ;
V_91 -> V_122 = F_65 ( V_123 ) ;
V_91 -> V_145 = F_67 ( V_146 ) ;
V_91 -> F_71 = F_65 ( F_71 ( 0 , V_91 , 4096 ) ) ;
for ( V_79 = 0 ; V_79 < V_112 ; V_79 ++ ) {
int V_31 = F_26 ( V_2 , V_2 -> V_51 , V_144 + V_79 * 8 , V_33 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static bool F_78 ( struct V_1 * V_2 ,
unsigned int V_63 , int V_147 ,
enum V_148 V_149 )
{
struct V_64 * V_117 ;
F_27 ( V_2 , F_28 ( & V_2 -> V_83 ) ) ;
if ( V_149 == V_150 )
V_117 = F_34 ( V_2 -> V_66 , V_63 ) ;
else
V_117 = F_42 ( V_2 -> V_66 , V_63 ) ;
if ( V_117 ) {
struct V_62 * V_151 = F_36 ( V_117 , struct V_62 , V_69 ) ;
if ( V_151 -> V_69 . V_85 == V_63 ) {
if ( V_149 == V_152 )
V_151 -> V_153 -= V_147 ;
else if ( V_149 == V_150 )
V_151 -> V_153 += V_147 ;
else
V_151 -> V_154 += V_147 ;
if ( V_151 -> V_153 < V_151 -> V_154 ) {
F_79 ( V_2 , L_13
L_14 ,
V_151 -> V_69 . V_85 , V_151 -> V_153 ,
V_151 -> V_154 , V_147 ,
F_80 ( V_2 -> V_8 . V_155 ) ) ;
V_151 -> V_153 = F_81 ( V_2 , V_63 ) ;
}
} else {
int V_153 = F_81 ( V_2 , V_63 ) ;
if ( V_151 -> V_25 != 0 ) {
F_79 ( V_2 , L_15
L_16 ,
V_151 -> V_69 . V_85 , V_151 -> V_153 ,
V_151 -> V_25 , V_63 , V_153 ) ;
V_151 -> V_25 = 0 ;
}
if ( V_151 -> V_154 ) {
F_79 ( V_2 , L_17
L_18 ,
V_151 -> V_69 . V_85 , V_151 -> V_154 ) ;
}
V_151 -> V_153 = V_153 ;
V_151 -> V_154 = ( V_149 == V_156 ) ? V_147 : 0 ;
F_48 ( V_2 -> V_66 ) ;
}
if ( V_149 != V_150 )
F_58 ( V_2 -> V_66 , & V_151 -> V_69 ) ;
if ( V_151 -> V_153 <= V_151 -> V_154 ) {
V_151 -> V_154 = 0 ;
return true ;
}
} else if ( V_149 != V_150 ) {
F_14 ( V_2 , L_19 ,
V_2 -> V_157 ,
V_2 -> V_66 -> V_94 ,
V_2 -> V_66 -> V_25 ) ;
}
return false ;
}
void F_82 ( struct V_1 * V_2 , unsigned long V_158 )
{
unsigned long V_159 = V_13 ;
unsigned long V_82 = V_2 -> V_160 [ V_2 -> V_161 ] ;
int V_162 = ( V_2 -> V_161 + 1 ) % V_163 ;
if ( F_83 ( V_159 , V_82 + V_164 ) ) {
if ( V_2 -> V_165 [ V_2 -> V_161 ] != V_158 &&
V_2 -> V_8 . V_155 != V_166 &&
V_2 -> V_8 . V_155 != V_167 ) {
V_2 -> V_160 [ V_162 ] = V_159 ;
V_2 -> V_165 [ V_162 ] = V_158 ;
V_2 -> V_161 = V_162 ;
}
}
}
static bool F_84 ( struct V_1 * V_2 )
{
return F_85 ( V_13 , V_2 -> V_168 + 2 * V_22 ) ;
}
static void F_86 ( struct V_1 * V_2 , bool V_169 )
{
if ( V_169 )
F_87 ( V_170 , & V_2 -> V_25 ) ;
else if ( ! F_84 ( V_2 ) )
return;
F_88 ( V_2 , V_171 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
unsigned long V_172 , unsigned long V_173 ,
enum V_148 V_149 )
{
unsigned long V_25 ;
unsigned long V_147 = 0 ;
unsigned int V_174 = 0 ;
while ( V_172 <= V_173 ) {
unsigned long V_175 = F_52 ( V_173 , V_172 | V_176 ) ;
unsigned long V_177 ;
if ( V_149 == V_156 )
V_177 = F_90 ( V_2 , V_172 , V_175 ) ;
else if ( V_149 == V_152 )
V_177 = F_91 ( V_2 , V_172 , V_175 ) ;
else
V_177 = F_92 ( V_2 , V_172 , V_175 ) ;
if ( V_177 ) {
F_57 ( & V_2 -> V_74 , V_25 ) ;
V_174 += F_78 ( V_2 , F_93 ( V_172 ) , V_177 , V_149 ) ;
F_59 ( & V_2 -> V_74 , V_25 ) ;
V_147 += V_177 ;
}
V_172 = V_175 + 1 ;
}
if ( V_147 ) {
if ( V_149 == V_152 ) {
unsigned long V_158 = F_94 ( V_2 ) ;
bool V_178 = ( V_158 <= V_2 -> V_154 ) ;
F_82 ( V_2 , V_158 ) ;
if ( V_174 || V_178 )
F_86 ( V_2 , V_178 ) ;
} else if ( V_149 == V_156 )
V_2 -> V_154 += V_147 ;
F_7 ( & V_2 -> V_76 ) ;
}
return V_147 ;
}
int F_95 ( struct V_1 * V_2 , T_1 V_27 , int V_30 ,
enum V_148 V_149 )
{
unsigned long V_172 , V_173 , V_179 ;
unsigned long V_147 = 0 ;
T_1 V_180 , V_181 ;
if ( ( V_149 == V_150 ) && V_30 == 0 )
return 0 ;
if ( V_30 <= 0 || ! F_96 ( V_30 , 512 ) || V_30 > V_182 ) {
F_14 ( V_2 , L_20 ,
V_183 [ V_149 ] ,
( unsigned long long ) V_27 , V_30 ) ;
return 0 ;
}
if ( ! F_62 ( V_2 ) )
return 0 ;
V_181 = F_97 ( V_2 -> V_184 ) ;
V_180 = V_27 + ( V_30 >> 9 ) - 1 ;
if ( ! F_98 ( V_27 < V_181 ) )
goto V_45;
if ( ! F_98 ( V_180 < V_181 ) )
V_180 = V_181 - 1 ;
V_179 = F_99 ( V_181 - 1 ) ;
if ( V_149 == V_152 ) {
if ( F_35 ( V_180 < V_185 - 1 ) )
goto V_45;
if ( F_35 ( V_180 == ( V_181 - 1 ) ) )
V_173 = V_179 ;
else
V_173 = F_99 ( V_180 - ( V_185 - 1 ) ) ;
V_172 = F_99 ( V_27 + V_185 - 1 ) ;
} else {
V_172 = F_99 ( V_27 ) ;
V_173 = F_99 ( V_180 ) ;
}
V_147 = F_89 ( V_2 , V_172 , V_173 , V_149 ) ;
V_45:
F_64 ( V_2 ) ;
return V_147 ;
}
static
struct V_62 * F_100 ( struct V_1 * V_2 , unsigned int V_63 )
{
struct V_64 * V_117 ;
struct V_62 * V_68 ;
int V_186 = 0 ;
unsigned long V_187 ;
F_38 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_157 > V_2 -> V_66 -> V_94 / 2 ) {
F_40 ( & V_2 -> V_74 ) ;
return NULL ;
}
V_117 = F_42 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_117 ? F_36 ( V_117 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
if ( V_68 -> V_69 . V_85 != V_63 ) {
V_68 -> V_153 = F_81 ( V_2 , V_63 ) ;
V_68 -> V_154 = 0 ;
F_48 ( V_2 -> V_66 ) ;
V_186 = 1 ;
}
if ( V_68 -> V_69 . V_141 == 1 )
V_2 -> V_157 ++ ;
F_87 ( V_70 , & V_68 -> V_25 ) ;
}
V_187 = V_2 -> V_66 -> V_25 ;
F_40 ( & V_2 -> V_74 ) ;
if ( V_186 )
F_7 ( & V_2 -> V_76 ) ;
if ( ! V_68 ) {
if ( V_187 & V_188 )
F_79 ( V_2 , L_21
L_22 ) ;
F_29 ( V_187 & V_189 ) ;
}
return V_68 ;
}
static int F_101 ( struct V_1 * V_2 , unsigned int V_63 )
{
int V_140 ;
F_38 ( & V_2 -> V_74 ) ;
V_140 = F_102 ( V_2 -> V_77 , V_63 ) ;
F_40 ( & V_2 -> V_74 ) ;
return V_140 ;
}
int F_103 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_104 ( V_27 ) ;
struct V_62 * V_68 ;
int V_79 , V_190 ;
bool V_191 ;
V_192:
V_190 = F_105 ( V_2 -> V_76 ,
( V_68 = F_100 ( V_2 , V_63 ) ) ) ;
if ( V_190 )
return - V_193 ;
if ( F_13 ( V_194 , & V_68 -> V_25 ) )
return 0 ;
V_191 = F_106 ( V_2 ) ;
for ( V_79 = 0 ; V_79 < V_67 ; V_79 ++ ) {
V_190 = F_105 ( V_2 -> V_76 ,
! F_101 ( V_2 , V_63 * V_67 + V_79 ) ||
( V_191 && F_13 ( V_75 , & V_68 -> V_25 ) ) ) ;
if ( V_190 || ( V_191 && F_13 ( V_75 , & V_68 -> V_25 ) ) ) {
F_38 ( & V_2 -> V_74 ) ;
if ( F_58 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_157 -- ;
F_7 ( & V_2 -> V_76 ) ;
}
F_40 ( & V_2 -> V_74 ) ;
if ( V_190 )
return - V_193 ;
if ( F_107 ( V_22 / 10 ) )
return - V_193 ;
goto V_192;
}
}
F_87 ( V_194 , & V_68 -> V_25 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_104 ( V_27 ) ;
const unsigned int V_102 = V_63 * V_67 ;
struct V_64 * V_117 ;
struct V_62 * V_68 ;
int V_79 ;
bool V_195 = F_109 ( V_2 , V_27 , true ) ;
if ( V_195 && V_2 -> V_196 != V_63 )
return - V_197 ;
F_38 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_196 != V_130 && V_2 -> V_196 != V_63 ) {
V_117 = F_34 ( V_2 -> V_66 , V_2 -> V_196 ) ;
V_68 = V_117 ? F_36 ( V_117 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
F_27 ( V_2 , ! F_13 ( V_194 , & V_68 -> V_25 ) ) ;
F_27 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_110 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_196 = V_130 ;
if ( F_58 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_157 -- ;
}
F_7 ( & V_2 -> V_76 ) ;
} else {
F_32 ( V_2 , L_23 ) ;
}
}
V_117 = F_41 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_117 ? F_36 ( V_117 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
if ( F_13 ( V_194 , & V_68 -> V_25 ) )
goto V_198;
if ( ! F_39 ( V_70 , & V_68 -> V_25 ) ) {
V_2 -> V_157 ++ ;
} else {
V_68 -> V_69 . V_141 -- ;
F_27 ( V_2 , V_68 -> V_69 . V_141 > 0 ) ;
}
goto V_199;
} else {
if ( V_2 -> V_157 > V_2 -> V_66 -> V_94 - 3 )
goto V_200;
V_117 = F_42 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_117 ? F_36 ( V_117 , struct V_62 , V_69 ) : NULL ;
if ( ! V_68 ) {
const unsigned long V_187 = V_2 -> V_66 -> V_25 ;
if ( V_187 & V_188 )
F_79 ( V_2 , L_21
L_22 ) ;
F_29 ( V_187 & V_189 ) ;
goto V_200;
}
if ( V_68 -> V_69 . V_85 != V_63 ) {
V_68 -> V_153 = F_81 ( V_2 , V_63 ) ;
V_68 -> V_154 = 0 ;
F_48 ( V_2 -> V_66 ) ;
F_7 ( & V_2 -> V_76 ) ;
F_27 ( V_2 , F_13 ( V_194 , & V_68 -> V_25 ) == 0 ) ;
}
F_87 ( V_70 , & V_68 -> V_25 ) ;
F_27 ( V_2 , V_68 -> V_69 . V_141 == 1 ) ;
V_2 -> V_157 ++ ;
goto V_199;
}
V_199:
for ( V_79 = 0 ; V_79 < V_67 ; V_79 ++ ) {
if ( F_102 ( V_2 -> V_77 , V_102 + V_79 ) )
goto V_200;
}
F_87 ( V_194 , & V_68 -> V_25 ) ;
V_198:
V_2 -> V_196 = V_130 ;
F_40 ( & V_2 -> V_74 ) ;
return 0 ;
V_200:
if ( V_68 ) {
if ( V_195 ) {
F_27 ( V_2 , ! F_13 ( V_194 , & V_68 -> V_25 ) ) ;
F_27 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_110 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_196 = V_130 ;
if ( F_58 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_157 -- ;
}
F_7 ( & V_2 -> V_76 ) ;
} else
V_2 -> V_196 = V_63 ;
}
F_40 ( & V_2 -> V_74 ) ;
return - V_197 ;
}
void F_111 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_104 ( V_27 ) ;
struct V_64 * V_117 ;
struct V_62 * V_68 ;
unsigned long V_25 ;
F_57 ( & V_2 -> V_74 , V_25 ) ;
V_117 = F_34 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_117 ? F_36 ( V_117 , struct V_62 , V_69 ) : NULL ;
if ( ! V_68 ) {
F_59 ( & V_2 -> V_74 , V_25 ) ;
if ( F_112 ( & V_201 ) )
F_14 ( V_2 , L_24 ) ;
return;
}
if ( V_68 -> V_69 . V_141 == 0 ) {
F_59 ( & V_2 -> V_74 , V_25 ) ;
F_14 ( V_2 , L_25
L_26 ,
( unsigned long long ) V_27 , V_63 ) ;
return;
}
if ( F_58 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_157 -- ;
F_7 ( & V_2 -> V_76 ) ;
}
F_59 ( & V_2 -> V_74 , V_25 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_74 ) ;
if ( F_19 ( V_2 , V_10 ) ) {
F_114 ( V_2 -> V_66 ) ;
F_64 ( V_2 ) ;
}
V_2 -> V_157 = 0 ;
V_2 -> V_196 = V_130 ;
F_40 ( & V_2 -> V_74 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
struct V_64 * V_117 ;
struct V_62 * V_68 ;
int V_79 ;
F_38 ( & V_2 -> V_74 ) ;
if ( F_19 ( V_2 , V_10 ) ) {
for ( V_79 = 0 ; V_79 < V_2 -> V_66 -> V_94 ; V_79 ++ ) {
V_117 = F_70 ( V_2 -> V_66 , V_79 ) ;
V_68 = F_36 ( V_117 , struct V_62 , V_69 ) ;
if ( V_68 -> V_69 . V_85 == V_130 )
continue;
if ( V_68 -> V_69 . V_85 == V_2 -> V_196 ) {
F_55 ( V_2 , L_27
L_28 ,
V_2 -> V_196 ) ;
F_27 ( V_2 , ! F_13 ( V_194 , & V_68 -> V_25 ) ) ;
F_27 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_110 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_196 = V_130 ;
F_58 ( V_2 -> V_66 , & V_68 -> V_69 ) ;
}
if ( V_68 -> V_69 . V_141 != 0 ) {
F_55 ( V_2 , L_29
L_30 , V_68 -> V_69 . V_141 ) ;
F_64 ( V_2 ) ;
F_40 ( & V_2 -> V_74 ) ;
return - V_197 ;
}
F_27 ( V_2 , ! F_13 ( V_194 , & V_68 -> V_25 ) ) ;
F_27 ( V_2 , ! F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_75 ( V_2 -> V_66 , & V_68 -> V_69 ) ;
}
F_27 ( V_2 , V_2 -> V_66 -> V_95 == 0 ) ;
F_64 ( V_2 ) ;
}
F_40 ( & V_2 -> V_74 ) ;
F_7 ( & V_2 -> V_76 ) ;
return 0 ;
}
