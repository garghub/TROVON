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
int V_31 , V_32 = 0 ;
V_2 -> V_6 . V_18 = 0 ;
V_2 -> V_6 . error = - V_33 ;
if ( ( V_28 == V_34 ) && ! F_13 ( V_35 , & V_2 -> V_25 ) )
V_32 |= V_36 | V_37 ;
V_32 |= V_38 | V_39 ;
V_29 = F_17 ( V_40 ) ;
V_29 -> V_41 = V_17 -> V_42 ;
V_29 -> V_43 . V_44 = V_27 ;
V_31 = - V_45 ;
if ( F_18 ( V_29 , V_2 -> V_6 . V_15 , V_30 , 0 ) != V_30 )
goto V_46;
V_29 -> V_47 = V_2 ;
V_29 -> V_48 = V_49 ;
F_19 ( V_29 , V_28 , V_32 ) ;
if ( V_28 != V_34 && V_2 -> V_8 . V_9 == V_50 && V_2 -> V_51 == NULL )
;
else if ( ! F_20 ( V_2 , V_52 ) ) {
F_14 ( V_2 , L_2 ) ;
V_31 = - V_33 ;
goto V_46;
}
F_21 ( V_29 ) ;
F_22 ( & V_2 -> V_6 . V_7 ) ;
V_2 -> V_6 . V_14 = V_13 ;
if ( F_23 ( V_2 , ( V_28 == V_34 ) ? V_53 : V_54 ) )
F_24 ( V_29 ) ;
else
F_25 ( V_29 ) ;
F_8 ( V_2 , V_17 , & V_2 -> V_6 . V_18 ) ;
if ( ! V_29 -> V_55 )
V_31 = V_2 -> V_6 . error ;
V_46:
F_26 ( V_29 ) ;
return V_31 ;
}
int F_27 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_1 V_27 , int V_28 )
{
int V_31 ;
F_28 ( V_2 , F_29 ( & V_2 -> V_6 . V_7 ) == 1 ) ;
F_30 ( ! V_17 -> V_42 ) ;
F_31 ( V_2 , L_3 ,
V_56 -> V_57 , V_56 -> V_58 , V_59 ,
( unsigned long long ) V_27 , ( V_28 == V_34 ) ? L_4 : L_5 ,
( void * ) V_60 ) ;
if ( V_27 < V_61 ( V_17 ) ||
V_27 + 7 > F_32 ( V_17 ) )
F_33 ( V_2 , L_6 ,
V_56 -> V_57 , V_56 -> V_58 , V_59 ,
( unsigned long long ) V_27 ,
( V_28 == V_34 ) ? L_4 : L_5 ) ;
V_31 = F_16 ( V_2 , V_17 , V_27 , V_28 ) ;
if ( V_31 ) {
F_14 ( V_2 , L_7 ,
( unsigned long long ) V_27 ,
( V_28 == V_34 ) ? L_4 : L_5 , V_31 ) ;
}
return V_31 ;
}
static struct V_62 * F_34 ( struct V_1 * V_2 , unsigned int V_63 )
{
struct V_64 * V_65 ;
V_65 = F_35 ( V_2 -> V_66 , V_63 / V_67 ) ;
if ( F_36 ( V_65 != NULL ) ) {
struct V_62 * V_68 = F_37 ( V_65 , struct V_62 , V_69 ) ;
if ( F_13 ( V_70 , & V_68 -> V_25 ) )
return V_68 ;
}
return NULL ;
}
static struct V_64 * F_38 ( struct V_1 * V_2 , unsigned int V_63 , bool V_71 )
{
struct V_64 * V_72 ;
struct V_62 * V_68 ;
int V_73 ;
F_39 ( & V_2 -> V_74 ) ;
V_68 = F_34 ( V_2 , V_63 ) ;
if ( V_68 ) {
V_73 = ! F_40 ( V_75 , & V_68 -> V_25 ) ;
F_41 ( & V_2 -> V_74 ) ;
if ( V_73 )
F_7 ( & V_2 -> V_76 ) ;
return NULL ;
}
if ( V_71 )
V_72 = F_42 ( V_2 -> V_77 , V_63 ) ;
else
V_72 = F_43 ( V_2 -> V_77 , V_63 ) ;
F_41 ( & V_2 -> V_74 ) ;
return V_72 ;
}
bool F_44 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
F_28 ( V_2 , V_80 <= V_82 ) ;
F_28 ( V_2 , F_29 ( & V_2 -> V_83 ) > 0 ) ;
if ( V_80 != V_82 )
return false ;
return F_38 ( V_2 , V_80 , true ) ;
}
bool F_45 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
unsigned V_63 ;
bool V_84 = false ;
F_28 ( V_2 , V_80 <= V_82 ) ;
F_28 ( V_2 , F_29 ( & V_2 -> V_83 ) > 0 ) ;
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
struct V_64 * V_72 ;
F_2 ( V_2 -> V_76 ,
( V_72 = F_38 ( V_2 , V_63 , false ) ) != NULL ) ;
if ( V_72 -> V_85 != V_63 )
V_84 = true ;
}
return V_84 ;
}
static unsigned int F_46 ( unsigned int V_86 )
{
return V_86 >>
( ( V_87 + 3 ) -
( V_81 - V_88 ) ) ;
}
static T_1 F_47 ( struct V_1 * V_2 )
{
const unsigned int V_89 = V_2 -> V_51 -> V_90 . V_91 ;
const unsigned int V_92 = V_2 -> V_51 -> V_90 . V_93 ;
unsigned int V_94 = V_2 -> V_95 % ( V_2 -> V_51 -> V_90 . V_96 ) ;
V_94 = ( ( V_94 % V_89 ) * V_92 ) + V_94 / V_89 ;
V_94 *= 8 ;
return V_2 -> V_51 -> V_90 . V_97 + V_2 -> V_51 -> V_90 . V_98 + V_94 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
struct V_64 * V_101 ;
T_1 V_27 ;
int V_79 , V_102 ;
unsigned V_103 ;
unsigned V_104 = 0 ;
int V_31 = 0 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_105 = F_49 ( V_106 ) ;
V_100 -> V_107 = F_49 ( V_2 -> V_95 ) ;
V_79 = 0 ;
F_50 ( V_2 ) ;
F_39 ( & V_2 -> V_74 ) ;
F_51 (e, &device->act_log->to_be_changed, list) {
if ( V_79 == V_108 ) {
V_79 ++ ;
break;
}
V_100 -> V_109 [ V_79 ] = F_52 ( V_101 -> V_110 ) ;
V_100 -> V_111 [ V_79 ] = F_49 ( V_101 -> V_112 ) ;
if ( V_101 -> V_85 != V_113 )
F_53 ( V_2 ,
F_46 ( V_101 -> V_85 ) ) ;
V_79 ++ ;
}
F_41 ( & V_2 -> V_74 ) ;
F_30 ( V_79 > V_108 ) ;
V_100 -> V_114 = F_52 ( V_79 ) ;
for ( ; V_79 < V_108 ; V_79 ++ ) {
V_100 -> V_109 [ V_79 ] = F_52 ( - 1 ) ;
V_100 -> V_111 [ V_79 ] = F_49 ( V_113 ) ;
}
V_100 -> V_115 = F_52 ( V_2 -> V_77 -> V_116 ) ;
V_100 -> V_117 = F_52 ( V_2 -> V_118 ) ;
V_102 = F_54 ( int , V_119 ,
V_2 -> V_77 -> V_116 - V_2 -> V_118 ) ;
for ( V_79 = 0 ; V_79 < V_102 ; V_79 ++ ) {
unsigned V_120 = V_2 -> V_118 + V_79 ;
V_103 = F_55 ( V_2 -> V_77 , V_120 ) -> V_85 ;
V_100 -> V_121 [ V_79 ] = F_49 ( V_103 ) ;
}
for (; V_79 < V_119 ; V_79 ++ )
V_100 -> V_121 [ V_79 ] = F_49 ( V_113 ) ;
V_2 -> V_118 += V_119 ;
if ( V_2 -> V_118 >= V_2 -> V_77 -> V_116 )
V_2 -> V_118 = 0 ;
V_27 = F_47 ( V_2 ) ;
V_104 = F_56 ( 0 , V_100 , 4096 ) ;
V_100 -> F_56 = F_49 ( V_104 ) ;
if ( F_57 ( V_2 ) )
V_31 = - V_45 ;
else {
bool V_122 ;
F_9 () ;
V_122 = F_10 ( V_2 -> V_51 -> V_20 ) -> V_123 ;
F_11 () ;
if ( V_122 ) {
if ( F_27 ( V_2 , V_2 -> V_51 , V_27 , V_124 ) ) {
V_31 = - V_45 ;
F_15 ( V_2 , 1 , V_125 ) ;
} else {
V_2 -> V_95 ++ ;
V_2 -> V_126 ++ ;
}
}
}
return V_31 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_99 * V_100 ;
int V_31 ;
if ( ! F_59 ( V_2 ) ) {
F_14 ( V_2 , L_8 ,
F_60 ( V_2 -> V_8 . V_9 ) ) ;
return - V_45 ;
}
if ( V_2 -> V_8 . V_9 < V_127 ) {
F_14 ( V_2 ,
L_9 ,
F_60 ( V_2 -> V_8 . V_9 ) ) ;
F_61 ( V_2 ) ;
return - V_45 ;
}
V_100 = F_1 ( V_2 , V_59 ) ;
if ( ! V_100 ) {
F_14 ( V_2 , L_10 ) ;
F_61 ( V_2 ) ;
return - V_33 ;
}
V_31 = F_48 ( V_2 , V_100 ) ;
F_5 ( V_2 ) ;
F_61 ( V_2 ) ;
return V_31 ;
}
void F_62 ( struct V_1 * V_2 )
{
bool V_128 = false ;
F_2 ( V_2 -> V_76 ,
V_2 -> V_77 -> V_129 == 0 ||
( V_128 = F_63 ( V_2 -> V_77 ) ) ) ;
if ( V_128 ) {
if ( V_2 -> V_77 -> V_129 ) {
bool V_122 ;
F_9 () ;
V_122 = F_10 ( V_2 -> V_51 -> V_20 ) -> V_123 ;
F_11 () ;
if ( V_122 )
F_58 ( V_2 ) ;
F_39 ( & V_2 -> V_74 ) ;
F_64 ( V_2 -> V_77 ) ;
F_41 ( & V_2 -> V_74 ) ;
}
F_65 ( V_2 -> V_77 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
}
void F_66 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
if ( F_45 ( V_2 , V_79 ) )
F_62 ( V_2 ) ;
}
int F_67 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_130 * V_131 = V_2 -> V_77 ;
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
unsigned V_132 ;
unsigned V_133 ;
unsigned V_63 ;
F_28 ( V_2 , V_80 <= V_82 ) ;
V_132 = 1 + V_82 - V_80 ;
V_133 = F_68 ( V_131 -> V_116 - V_131 -> V_134 ,
V_131 -> V_135 - V_131 -> V_129 ) ;
if ( V_133 < V_132 ) {
if ( ! V_131 -> V_129 )
F_69 ( V_136 , & V_2 -> V_77 -> V_25 ) ;
return - V_137 ;
}
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
struct V_64 * V_65 ;
V_65 = F_35 ( V_2 -> V_66 , V_63 / V_67 ) ;
if ( F_36 ( V_65 != NULL ) ) {
struct V_62 * V_68 = F_37 ( V_65 , struct V_62 , V_69 ) ;
if ( F_13 ( V_70 , & V_68 -> V_25 ) ) {
if ( ! F_40 ( V_75 , & V_68 -> V_25 ) )
return - V_138 ;
return - V_139 ;
}
}
}
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
struct V_64 * V_72 ;
V_72 = F_70 ( V_2 -> V_77 , V_63 ) ;
if ( ! V_72 )
F_71 ( V_2 , L_11 , V_63 ) ;
}
return 0 ;
}
void F_72 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
unsigned V_80 = V_79 -> V_27 >> ( V_81 - 9 ) ;
unsigned V_82 = V_79 -> V_30 == 0 ? V_80 : ( V_79 -> V_27 + ( V_79 -> V_30 >> 9 ) - 1 ) >> ( V_81 - 9 ) ;
unsigned V_63 ;
struct V_64 * V_140 ;
unsigned long V_25 ;
F_28 ( V_2 , V_80 <= V_82 ) ;
F_73 ( & V_2 -> V_74 , V_25 ) ;
for ( V_63 = V_80 ; V_63 <= V_82 ; V_63 ++ ) {
V_140 = F_35 ( V_2 -> V_77 , V_63 ) ;
if ( ! V_140 ) {
F_14 ( V_2 , L_12 , V_63 ) ;
continue;
}
F_74 ( V_2 -> V_77 , V_140 ) ;
}
F_75 ( & V_2 -> V_74 , V_25 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
static int F_76 ( struct V_1 * V_2 , struct V_64 * V_72 )
{
int V_141 ;
F_39 ( & V_2 -> V_74 ) ;
V_141 = ( V_72 -> V_142 == 0 ) ;
if ( F_77 ( V_141 ) )
F_78 ( V_2 -> V_77 , V_72 ) ;
F_41 ( & V_2 -> V_74 ) ;
return V_141 ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_64 * V_72 ;
int V_79 ;
F_28 ( V_2 , F_13 ( V_143 , & V_2 -> V_77 -> V_25 ) ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_77 -> V_116 ; V_79 ++ ) {
V_72 = F_55 ( V_2 -> V_77 , V_79 ) ;
if ( V_72 -> V_85 == V_113 )
continue;
F_2 ( V_2 -> V_76 , F_76 ( V_2 , V_72 ) ) ;
}
F_7 ( & V_2 -> V_76 ) ;
}
int F_80 ( struct V_1 * V_2 , void * V_100 )
{
struct V_99 * V_131 = V_100 ;
struct V_144 * V_90 = & V_2 -> V_51 -> V_90 ;
int V_96 = V_90 -> V_91 * V_90 -> V_93 ;
int V_79 ;
F_48 ( V_2 , V_131 ) ;
F_39 ( & V_2 -> V_74 ) ;
F_64 ( V_2 -> V_77 ) ;
F_41 ( & V_2 -> V_74 ) ;
for ( V_79 = 1 ; V_79 < V_96 ; V_79 ++ ) {
int V_31 = F_48 ( V_2 , V_131 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static bool F_81 ( struct V_1 * V_2 ,
unsigned int V_63 , int V_145 ,
enum V_146 V_147 )
{
struct V_64 * V_101 ;
F_28 ( V_2 , F_29 ( & V_2 -> V_83 ) ) ;
if ( V_147 == V_148 )
V_101 = F_35 ( V_2 -> V_66 , V_63 ) ;
else
V_101 = F_43 ( V_2 -> V_66 , V_63 ) ;
if ( V_101 ) {
struct V_62 * V_149 = F_37 ( V_101 , struct V_62 , V_69 ) ;
if ( V_149 -> V_69 . V_85 == V_63 ) {
if ( V_147 == V_150 )
V_149 -> V_151 -= V_145 ;
else if ( V_147 == V_148 )
V_149 -> V_151 += V_145 ;
else
V_149 -> V_152 += V_145 ;
if ( V_149 -> V_151 < V_149 -> V_152 ) {
F_82 ( V_2 , L_13
L_14 ,
V_149 -> V_69 . V_85 , V_149 -> V_151 ,
V_149 -> V_152 , V_145 ,
F_83 ( V_2 -> V_8 . V_153 ) ) ;
V_149 -> V_151 = F_84 ( V_2 , V_63 ) ;
}
} else {
int V_151 = F_84 ( V_2 , V_63 ) ;
if ( V_149 -> V_25 != 0 ) {
F_82 ( V_2 , L_15
L_16 ,
V_149 -> V_69 . V_85 , V_149 -> V_151 ,
V_149 -> V_25 , V_63 , V_151 ) ;
V_149 -> V_25 = 0 ;
}
if ( V_149 -> V_152 ) {
F_82 ( V_2 , L_17
L_18 ,
V_149 -> V_69 . V_85 , V_149 -> V_152 ) ;
}
V_149 -> V_151 = V_151 ;
V_149 -> V_152 = ( V_147 == V_154 ) ? V_145 : 0 ;
F_64 ( V_2 -> V_66 ) ;
}
if ( V_147 != V_148 )
F_74 ( V_2 -> V_66 , & V_149 -> V_69 ) ;
if ( V_149 -> V_151 <= V_149 -> V_152 ) {
V_149 -> V_152 = 0 ;
return true ;
}
} else if ( V_147 != V_148 ) {
F_14 ( V_2 , L_19 ,
V_2 -> V_155 ,
V_2 -> V_66 -> V_116 ,
V_2 -> V_66 -> V_25 ) ;
}
return false ;
}
void F_85 ( struct V_1 * V_2 , unsigned long V_156 )
{
unsigned long V_157 = V_13 ;
unsigned long V_82 = V_2 -> V_158 [ V_2 -> V_159 ] ;
int V_160 = ( V_2 -> V_159 + 1 ) % V_161 ;
if ( F_86 ( V_157 , V_82 + V_162 ) ) {
if ( V_2 -> V_163 [ V_2 -> V_159 ] != V_156 &&
V_2 -> V_8 . V_153 != V_164 &&
V_2 -> V_8 . V_153 != V_165 ) {
V_2 -> V_158 [ V_160 ] = V_157 ;
V_2 -> V_163 [ V_160 ] = V_156 ;
V_2 -> V_159 = V_160 ;
}
}
}
static bool F_87 ( struct V_1 * V_2 )
{
return F_88 ( V_13 , V_2 -> V_166 + 2 * V_22 ) ;
}
static void F_89 ( struct V_1 * V_2 , bool V_167 )
{
if ( V_167 ) {
struct V_168 * V_169 = F_90 ( V_2 ) -> V_169 ;
if ( V_169 -> V_170 <= 95 ||
F_91 ( V_2 -> V_8 . V_153 ) )
F_92 ( V_171 , & V_2 -> V_25 ) ;
} else if ( ! F_87 ( V_2 ) )
return;
F_93 ( V_2 , V_172 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
unsigned long V_173 , unsigned long V_174 ,
enum V_146 V_147 )
{
unsigned long V_25 ;
unsigned long V_145 = 0 ;
unsigned int V_175 = 0 ;
while ( V_173 <= V_174 ) {
unsigned long V_176 = F_68 ( V_174 , V_173 | V_177 ) ;
unsigned long V_178 ;
if ( V_147 == V_154 )
V_178 = F_95 ( V_2 , V_173 , V_176 ) ;
else if ( V_147 == V_150 )
V_178 = F_96 ( V_2 , V_173 , V_176 ) ;
else
V_178 = F_97 ( V_2 , V_173 , V_176 ) ;
if ( V_178 ) {
F_73 ( & V_2 -> V_74 , V_25 ) ;
V_175 += F_81 ( V_2 , F_98 ( V_173 ) , V_178 , V_147 ) ;
F_75 ( & V_2 -> V_74 , V_25 ) ;
V_145 += V_178 ;
}
V_173 = V_176 + 1 ;
}
if ( V_145 ) {
if ( V_147 == V_150 ) {
unsigned long V_156 = F_99 ( V_2 ) ;
bool V_179 = ( V_156 <= V_2 -> V_152 ) ;
F_85 ( V_2 , V_156 ) ;
if ( V_175 || V_179 )
F_89 ( V_2 , V_179 ) ;
} else if ( V_147 == V_154 )
V_2 -> V_152 += V_145 ;
F_7 ( & V_2 -> V_76 ) ;
}
return V_145 ;
}
static bool F_100 ( int V_30 )
{
return V_30 > 0
&& V_30 <= V_180
&& F_101 ( V_30 , 512 ) ;
}
int F_102 ( struct V_1 * V_2 , T_1 V_27 , int V_30 ,
enum V_146 V_147 )
{
unsigned long V_173 , V_174 , V_181 ;
unsigned long V_145 = 0 ;
T_1 V_182 , V_183 ;
if ( ( V_147 == V_148 ) && V_30 == 0 )
return 0 ;
if ( ! F_100 ( V_30 ) ) {
F_14 ( V_2 , L_20 ,
V_184 [ V_147 ] ,
( unsigned long long ) V_27 , V_30 ) ;
return 0 ;
}
if ( ! F_59 ( V_2 ) )
return 0 ;
V_183 = F_103 ( V_2 -> V_185 ) ;
V_182 = V_27 + ( V_30 >> 9 ) - 1 ;
if ( ! F_104 ( V_27 < V_183 ) )
goto V_46;
if ( ! F_104 ( V_182 < V_183 ) )
V_182 = V_183 - 1 ;
V_181 = F_105 ( V_183 - 1 ) ;
if ( V_147 == V_150 ) {
if ( F_36 ( V_182 < V_186 - 1 ) )
goto V_46;
if ( F_36 ( V_182 == ( V_183 - 1 ) ) )
V_174 = V_181 ;
else
V_174 = F_105 ( V_182 - ( V_186 - 1 ) ) ;
V_173 = F_105 ( V_27 + V_186 - 1 ) ;
} else {
V_173 = F_105 ( V_27 ) ;
V_174 = F_105 ( V_182 ) ;
}
V_145 = F_94 ( V_2 , V_173 , V_174 , V_147 ) ;
V_46:
F_61 ( V_2 ) ;
return V_145 ;
}
static
struct V_62 * F_106 ( struct V_1 * V_2 , unsigned int V_63 )
{
struct V_64 * V_101 ;
struct V_62 * V_68 ;
int V_187 = 0 ;
unsigned long V_188 ;
F_39 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_155 > V_2 -> V_66 -> V_116 / 2 ) {
F_41 ( & V_2 -> V_74 ) ;
return NULL ;
}
V_101 = F_43 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_101 ? F_37 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
if ( V_68 -> V_69 . V_85 != V_63 ) {
V_68 -> V_151 = F_84 ( V_2 , V_63 ) ;
V_68 -> V_152 = 0 ;
F_64 ( V_2 -> V_66 ) ;
V_187 = 1 ;
}
if ( V_68 -> V_69 . V_142 == 1 )
V_2 -> V_155 ++ ;
F_92 ( V_70 , & V_68 -> V_25 ) ;
}
V_188 = V_2 -> V_66 -> V_25 ;
F_41 ( & V_2 -> V_74 ) ;
if ( V_187 )
F_7 ( & V_2 -> V_76 ) ;
if ( ! V_68 ) {
if ( V_188 & V_189 )
F_82 ( V_2 , L_21
L_22 ) ;
F_30 ( V_188 & V_190 ) ;
}
return V_68 ;
}
static int F_107 ( struct V_1 * V_2 , unsigned int V_63 )
{
int V_141 ;
F_39 ( & V_2 -> V_74 ) ;
V_141 = F_108 ( V_2 -> V_77 , V_63 ) ;
F_41 ( & V_2 -> V_74 ) ;
return V_141 ;
}
int F_109 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_110 ( V_27 ) ;
struct V_62 * V_68 ;
int V_79 , V_191 ;
bool V_192 ;
V_193:
V_191 = F_111 ( V_2 -> V_76 ,
( V_68 = F_106 ( V_2 , V_63 ) ) ) ;
if ( V_191 )
return - V_194 ;
if ( F_13 ( V_195 , & V_68 -> V_25 ) )
return 0 ;
V_192 = F_112 ( V_2 ) ;
for ( V_79 = 0 ; V_79 < V_67 ; V_79 ++ ) {
V_191 = F_111 ( V_2 -> V_76 ,
! F_107 ( V_2 , V_63 * V_67 + V_79 ) ||
( V_192 && F_13 ( V_75 , & V_68 -> V_25 ) ) ) ;
if ( V_191 || ( V_192 && F_13 ( V_75 , & V_68 -> V_25 ) ) ) {
F_39 ( & V_2 -> V_74 ) ;
if ( F_74 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_155 -- ;
F_7 ( & V_2 -> V_76 ) ;
}
F_41 ( & V_2 -> V_74 ) ;
if ( V_191 )
return - V_194 ;
if ( F_113 ( V_22 / 10 ) )
return - V_194 ;
goto V_193;
}
}
F_92 ( V_195 , & V_68 -> V_25 ) ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_110 ( V_27 ) ;
const unsigned int V_86 = V_63 * V_67 ;
struct V_64 * V_101 ;
struct V_62 * V_68 ;
int V_79 ;
bool V_196 = F_115 ( V_2 , V_27 , true ) ;
if ( V_196 && V_2 -> V_197 != V_63 )
return - V_198 ;
F_39 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_197 != V_113 && V_2 -> V_197 != V_63 ) {
V_101 = F_35 ( V_2 -> V_66 , V_2 -> V_197 ) ;
V_68 = V_101 ? F_37 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
F_28 ( V_2 , ! F_13 ( V_195 , & V_68 -> V_25 ) ) ;
F_28 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_116 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_197 = V_113 ;
if ( F_74 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_155 -- ;
}
F_7 ( & V_2 -> V_76 ) ;
} else {
F_33 ( V_2 , L_23 ) ;
}
}
V_101 = F_42 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_101 ? F_37 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( V_68 ) {
if ( F_13 ( V_195 , & V_68 -> V_25 ) )
goto V_199;
if ( ! F_40 ( V_70 , & V_68 -> V_25 ) ) {
V_2 -> V_155 ++ ;
} else {
V_68 -> V_69 . V_142 -- ;
F_28 ( V_2 , V_68 -> V_69 . V_142 > 0 ) ;
}
goto V_200;
} else {
if ( V_2 -> V_155 > V_2 -> V_66 -> V_116 - 3 )
goto V_201;
V_101 = F_43 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_101 ? F_37 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( ! V_68 ) {
const unsigned long V_188 = V_2 -> V_66 -> V_25 ;
if ( V_188 & V_189 )
F_82 ( V_2 , L_21
L_22 ) ;
F_30 ( V_188 & V_190 ) ;
goto V_201;
}
if ( V_68 -> V_69 . V_85 != V_63 ) {
V_68 -> V_151 = F_84 ( V_2 , V_63 ) ;
V_68 -> V_152 = 0 ;
F_64 ( V_2 -> V_66 ) ;
F_7 ( & V_2 -> V_76 ) ;
F_28 ( V_2 , F_13 ( V_195 , & V_68 -> V_25 ) == 0 ) ;
}
F_92 ( V_70 , & V_68 -> V_25 ) ;
F_28 ( V_2 , V_68 -> V_69 . V_142 == 1 ) ;
V_2 -> V_155 ++ ;
goto V_200;
}
V_200:
for ( V_79 = 0 ; V_79 < V_67 ; V_79 ++ ) {
if ( F_108 ( V_2 -> V_77 , V_86 + V_79 ) )
goto V_201;
}
F_92 ( V_195 , & V_68 -> V_25 ) ;
V_199:
V_2 -> V_197 = V_113 ;
F_41 ( & V_2 -> V_74 ) ;
return 0 ;
V_201:
if ( V_68 ) {
if ( V_196 ) {
F_28 ( V_2 , ! F_13 ( V_195 , & V_68 -> V_25 ) ) ;
F_28 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_116 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_197 = V_113 ;
if ( F_74 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_155 -- ;
}
F_7 ( & V_2 -> V_76 ) ;
} else
V_2 -> V_197 = V_63 ;
}
F_41 ( & V_2 -> V_74 ) ;
return - V_198 ;
}
void F_117 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_63 = F_110 ( V_27 ) ;
struct V_64 * V_101 ;
struct V_62 * V_68 ;
unsigned long V_25 ;
F_73 ( & V_2 -> V_74 , V_25 ) ;
V_101 = F_35 ( V_2 -> V_66 , V_63 ) ;
V_68 = V_101 ? F_37 ( V_101 , struct V_62 , V_69 ) : NULL ;
if ( ! V_68 ) {
F_75 ( & V_2 -> V_74 , V_25 ) ;
if ( F_118 ( & V_202 ) )
F_14 ( V_2 , L_24 ) ;
return;
}
if ( V_68 -> V_69 . V_142 == 0 ) {
F_75 ( & V_2 -> V_74 , V_25 ) ;
F_14 ( V_2 , L_25
L_26 ,
( unsigned long long ) V_27 , V_63 ) ;
return;
}
if ( F_74 ( V_2 -> V_66 , & V_68 -> V_69 ) == 0 ) {
V_68 -> V_25 = 0 ;
V_2 -> V_155 -- ;
F_7 ( & V_2 -> V_76 ) ;
}
F_75 ( & V_2 -> V_74 , V_25 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_74 ) ;
if ( F_20 ( V_2 , V_10 ) ) {
F_120 ( V_2 -> V_66 ) ;
F_61 ( V_2 ) ;
}
V_2 -> V_155 = 0 ;
V_2 -> V_197 = V_113 ;
F_41 ( & V_2 -> V_74 ) ;
F_7 ( & V_2 -> V_76 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_64 * V_101 ;
struct V_62 * V_68 ;
int V_79 ;
F_39 ( & V_2 -> V_74 ) ;
if ( F_20 ( V_2 , V_10 ) ) {
for ( V_79 = 0 ; V_79 < V_2 -> V_66 -> V_116 ; V_79 ++ ) {
V_101 = F_55 ( V_2 -> V_66 , V_79 ) ;
V_68 = F_37 ( V_101 , struct V_62 , V_69 ) ;
if ( V_68 -> V_69 . V_85 == V_113 )
continue;
if ( V_68 -> V_69 . V_85 == V_2 -> V_197 ) {
F_71 ( V_2 , L_27
L_28 ,
V_2 -> V_197 ) ;
F_28 ( V_2 , ! F_13 ( V_195 , & V_68 -> V_25 ) ) ;
F_28 ( V_2 , F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_116 ( V_70 , & V_68 -> V_25 ) ;
V_2 -> V_197 = V_113 ;
F_74 ( V_2 -> V_66 , & V_68 -> V_69 ) ;
}
if ( V_68 -> V_69 . V_142 != 0 ) {
F_71 ( V_2 , L_29
L_30 , V_68 -> V_69 . V_142 ) ;
F_61 ( V_2 ) ;
F_41 ( & V_2 -> V_74 ) ;
return - V_198 ;
}
F_28 ( V_2 , ! F_13 ( V_195 , & V_68 -> V_25 ) ) ;
F_28 ( V_2 , ! F_13 ( V_70 , & V_68 -> V_25 ) ) ;
F_78 ( V_2 -> V_66 , & V_68 -> V_69 ) ;
}
F_28 ( V_2 , V_2 -> V_66 -> V_134 == 0 ) ;
F_61 ( V_2 ) ;
}
F_41 ( & V_2 -> V_74 ) ;
F_7 ( & V_2 -> V_76 ) ;
return 0 ;
}
