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
V_32 |= V_38 ;
V_29 = F_17 ( V_39 ) ;
V_29 -> V_40 = V_17 -> V_41 ;
V_29 -> V_42 . V_43 = V_27 ;
V_31 = - V_44 ;
if ( F_18 ( V_29 , V_2 -> V_6 . V_15 , V_30 , 0 ) != V_30 )
goto V_45;
V_29 -> V_46 = V_2 ;
V_29 -> V_47 = V_48 ;
F_19 ( V_29 , V_28 , V_32 ) ;
if ( V_28 != V_34 && V_2 -> V_8 . V_9 == V_49 && V_2 -> V_50 == NULL )
;
else if ( ! F_20 ( V_2 , V_51 ) ) {
F_14 ( V_2 , L_2 ) ;
V_31 = - V_33 ;
goto V_45;
}
F_21 ( V_29 ) ;
F_22 ( & V_2 -> V_6 . V_7 ) ;
V_2 -> V_6 . V_14 = V_13 ;
if ( F_23 ( V_2 , ( V_28 == V_34 ) ? V_52 : V_53 ) )
F_24 ( V_29 ) ;
else
F_25 ( V_29 ) ;
F_8 ( V_2 , V_17 , & V_2 -> V_6 . V_18 ) ;
if ( ! V_29 -> V_54 )
V_31 = V_2 -> V_6 . error ;
V_45:
F_26 ( V_29 ) ;
return V_31 ;
}
int F_27 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_1 V_27 , int V_28 )
{
int V_31 ;
F_28 ( V_2 , F_29 ( & V_2 -> V_6 . V_7 ) == 1 ) ;
F_30 ( ! V_17 -> V_41 ) ;
F_31 ( V_2 , L_3 ,
V_55 -> V_56 , V_55 -> V_57 , V_58 ,
( unsigned long long ) V_27 , ( V_28 == V_34 ) ? L_4 : L_5 ,
( void * ) V_59 ) ;
if ( V_27 < V_60 ( V_17 ) ||
V_27 + 7 > F_32 ( V_17 ) )
F_33 ( V_2 , L_6 ,
V_55 -> V_56 , V_55 -> V_57 , V_58 ,
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
static struct V_61 * F_34 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_63 * V_64 ;
V_64 = F_35 ( V_2 -> V_65 , V_62 / V_66 ) ;
if ( F_36 ( V_64 != NULL ) ) {
struct V_61 * V_67 = F_37 ( V_64 , struct V_61 , V_68 ) ;
if ( F_13 ( V_69 , & V_67 -> V_25 ) )
return V_67 ;
}
return NULL ;
}
static struct V_63 * F_38 ( struct V_1 * V_2 , unsigned int V_62 , bool V_70 )
{
struct V_63 * V_71 ;
struct V_61 * V_67 ;
int V_72 ;
F_39 ( & V_2 -> V_73 ) ;
V_67 = F_34 ( V_2 , V_62 ) ;
if ( V_67 ) {
V_72 = ! F_40 ( V_74 , & V_67 -> V_25 ) ;
F_41 ( & V_2 -> V_73 ) ;
if ( V_72 )
F_7 ( & V_2 -> V_75 ) ;
return NULL ;
}
if ( V_70 )
V_71 = F_42 ( V_2 -> V_76 , V_62 ) ;
else
V_71 = F_43 ( V_2 -> V_76 , V_62 ) ;
F_41 ( & V_2 -> V_73 ) ;
return V_71 ;
}
bool F_44 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
unsigned V_79 = V_78 -> V_27 >> ( V_80 - 9 ) ;
unsigned V_81 = V_78 -> V_30 == 0 ? V_79 : ( V_78 -> V_27 + ( V_78 -> V_30 >> 9 ) - 1 ) >> ( V_80 - 9 ) ;
F_28 ( V_2 , V_79 <= V_81 ) ;
F_28 ( V_2 , F_29 ( & V_2 -> V_82 ) > 0 ) ;
if ( V_79 != V_81 )
return false ;
return F_38 ( V_2 , V_79 , true ) ;
}
bool F_45 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
unsigned V_79 = V_78 -> V_27 >> ( V_80 - 9 ) ;
unsigned V_81 = V_78 -> V_30 == 0 ? V_79 : ( V_78 -> V_27 + ( V_78 -> V_30 >> 9 ) - 1 ) >> ( V_80 - 9 ) ;
unsigned V_62 ;
bool V_83 = false ;
F_28 ( V_2 , V_79 <= V_81 ) ;
F_28 ( V_2 , F_29 ( & V_2 -> V_82 ) > 0 ) ;
for ( V_62 = V_79 ; V_62 <= V_81 ; V_62 ++ ) {
struct V_63 * V_71 ;
F_2 ( V_2 -> V_75 ,
( V_71 = F_38 ( V_2 , V_62 , false ) ) != NULL ) ;
if ( V_71 -> V_84 != V_62 )
V_83 = true ;
}
return V_83 ;
}
static unsigned int F_46 ( unsigned int V_85 )
{
return V_85 >>
( ( V_86 + 3 ) -
( V_80 - V_87 ) ) ;
}
static T_1 F_47 ( struct V_1 * V_2 )
{
const unsigned int V_88 = V_2 -> V_50 -> V_89 . V_90 ;
const unsigned int V_91 = V_2 -> V_50 -> V_89 . V_92 ;
unsigned int V_93 = V_2 -> V_94 % ( V_2 -> V_50 -> V_89 . V_95 ) ;
V_93 = ( ( V_93 % V_88 ) * V_91 ) + V_93 / V_88 ;
V_93 *= 8 ;
return V_2 -> V_50 -> V_89 . V_96 + V_2 -> V_50 -> V_89 . V_97 + V_93 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
struct V_63 * V_100 ;
T_1 V_27 ;
int V_78 , V_101 ;
unsigned V_102 ;
unsigned V_103 = 0 ;
int V_31 = 0 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> V_104 = F_49 ( V_105 ) ;
V_99 -> V_106 = F_49 ( V_2 -> V_94 ) ;
V_78 = 0 ;
F_50 ( V_2 ) ;
F_39 ( & V_2 -> V_73 ) ;
F_51 (e, &device->act_log->to_be_changed, list) {
if ( V_78 == V_107 ) {
V_78 ++ ;
break;
}
V_99 -> V_108 [ V_78 ] = F_52 ( V_100 -> V_109 ) ;
V_99 -> V_110 [ V_78 ] = F_49 ( V_100 -> V_111 ) ;
if ( V_100 -> V_84 != V_112 )
F_53 ( V_2 ,
F_46 ( V_100 -> V_84 ) ) ;
V_78 ++ ;
}
F_41 ( & V_2 -> V_73 ) ;
F_30 ( V_78 > V_107 ) ;
V_99 -> V_113 = F_52 ( V_78 ) ;
for ( ; V_78 < V_107 ; V_78 ++ ) {
V_99 -> V_108 [ V_78 ] = F_52 ( - 1 ) ;
V_99 -> V_110 [ V_78 ] = F_49 ( V_112 ) ;
}
V_99 -> V_114 = F_52 ( V_2 -> V_76 -> V_115 ) ;
V_99 -> V_116 = F_52 ( V_2 -> V_117 ) ;
V_101 = F_54 ( int , V_118 ,
V_2 -> V_76 -> V_115 - V_2 -> V_117 ) ;
for ( V_78 = 0 ; V_78 < V_101 ; V_78 ++ ) {
unsigned V_119 = V_2 -> V_117 + V_78 ;
V_102 = F_55 ( V_2 -> V_76 , V_119 ) -> V_84 ;
V_99 -> V_120 [ V_78 ] = F_49 ( V_102 ) ;
}
for (; V_78 < V_118 ; V_78 ++ )
V_99 -> V_120 [ V_78 ] = F_49 ( V_112 ) ;
V_2 -> V_117 += V_118 ;
if ( V_2 -> V_117 >= V_2 -> V_76 -> V_115 )
V_2 -> V_117 = 0 ;
V_27 = F_47 ( V_2 ) ;
V_103 = F_56 ( 0 , V_99 , 4096 ) ;
V_99 -> F_56 = F_49 ( V_103 ) ;
if ( F_57 ( V_2 ) )
V_31 = - V_44 ;
else {
bool V_121 ;
F_9 () ;
V_121 = F_10 ( V_2 -> V_50 -> V_20 ) -> V_122 ;
F_11 () ;
if ( V_121 ) {
if ( F_27 ( V_2 , V_2 -> V_50 , V_27 , V_123 ) ) {
V_31 = - V_44 ;
F_15 ( V_2 , 1 , V_124 ) ;
} else {
V_2 -> V_94 ++ ;
V_2 -> V_125 ++ ;
}
}
}
return V_31 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
int V_31 ;
if ( ! F_59 ( V_2 ) ) {
F_14 ( V_2 , L_8 ,
F_60 ( V_2 -> V_8 . V_9 ) ) ;
return - V_44 ;
}
if ( V_2 -> V_8 . V_9 < V_126 ) {
F_14 ( V_2 ,
L_9 ,
F_60 ( V_2 -> V_8 . V_9 ) ) ;
F_61 ( V_2 ) ;
return - V_44 ;
}
V_99 = F_1 ( V_2 , V_58 ) ;
if ( ! V_99 ) {
F_14 ( V_2 , L_10 ) ;
F_61 ( V_2 ) ;
return - V_33 ;
}
V_31 = F_48 ( V_2 , V_99 ) ;
F_5 ( V_2 ) ;
F_61 ( V_2 ) ;
return V_31 ;
}
void F_62 ( struct V_1 * V_2 )
{
bool V_127 = false ;
F_2 ( V_2 -> V_75 ,
V_2 -> V_76 -> V_128 == 0 ||
( V_127 = F_63 ( V_2 -> V_76 ) ) ) ;
if ( V_127 ) {
if ( V_2 -> V_76 -> V_128 ) {
bool V_121 ;
F_9 () ;
V_121 = F_10 ( V_2 -> V_50 -> V_20 ) -> V_122 ;
F_11 () ;
if ( V_121 )
F_58 ( V_2 ) ;
F_39 ( & V_2 -> V_73 ) ;
F_64 ( V_2 -> V_76 ) ;
F_41 ( & V_2 -> V_73 ) ;
}
F_65 ( V_2 -> V_76 ) ;
F_7 ( & V_2 -> V_75 ) ;
}
}
void F_66 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
if ( F_45 ( V_2 , V_78 ) )
F_62 ( V_2 ) ;
}
int F_67 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_129 * V_130 = V_2 -> V_76 ;
unsigned V_79 = V_78 -> V_27 >> ( V_80 - 9 ) ;
unsigned V_81 = V_78 -> V_30 == 0 ? V_79 : ( V_78 -> V_27 + ( V_78 -> V_30 >> 9 ) - 1 ) >> ( V_80 - 9 ) ;
unsigned V_131 ;
unsigned V_132 ;
unsigned V_62 ;
F_28 ( V_2 , V_79 <= V_81 ) ;
V_131 = 1 + V_81 - V_79 ;
V_132 = F_68 ( V_130 -> V_115 - V_130 -> V_133 ,
V_130 -> V_134 - V_130 -> V_128 ) ;
if ( V_132 < V_131 ) {
if ( ! V_130 -> V_128 )
F_69 ( V_135 , & V_2 -> V_76 -> V_25 ) ;
return - V_136 ;
}
for ( V_62 = V_79 ; V_62 <= V_81 ; V_62 ++ ) {
struct V_63 * V_64 ;
V_64 = F_35 ( V_2 -> V_65 , V_62 / V_66 ) ;
if ( F_36 ( V_64 != NULL ) ) {
struct V_61 * V_67 = F_37 ( V_64 , struct V_61 , V_68 ) ;
if ( F_13 ( V_69 , & V_67 -> V_25 ) ) {
if ( ! F_40 ( V_74 , & V_67 -> V_25 ) )
return - V_137 ;
return - V_138 ;
}
}
}
for ( V_62 = V_79 ; V_62 <= V_81 ; V_62 ++ ) {
struct V_63 * V_71 ;
V_71 = F_70 ( V_2 -> V_76 , V_62 ) ;
if ( ! V_71 )
F_71 ( V_2 , L_11 , V_62 ) ;
}
return 0 ;
}
void F_72 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
unsigned V_79 = V_78 -> V_27 >> ( V_80 - 9 ) ;
unsigned V_81 = V_78 -> V_30 == 0 ? V_79 : ( V_78 -> V_27 + ( V_78 -> V_30 >> 9 ) - 1 ) >> ( V_80 - 9 ) ;
unsigned V_62 ;
struct V_63 * V_139 ;
unsigned long V_25 ;
F_28 ( V_2 , V_79 <= V_81 ) ;
F_73 ( & V_2 -> V_73 , V_25 ) ;
for ( V_62 = V_79 ; V_62 <= V_81 ; V_62 ++ ) {
V_139 = F_35 ( V_2 -> V_76 , V_62 ) ;
if ( ! V_139 ) {
F_14 ( V_2 , L_12 , V_62 ) ;
continue;
}
F_74 ( V_2 -> V_76 , V_139 ) ;
}
F_75 ( & V_2 -> V_73 , V_25 ) ;
F_7 ( & V_2 -> V_75 ) ;
}
static int F_76 ( struct V_1 * V_2 , struct V_63 * V_71 )
{
int V_140 ;
F_39 ( & V_2 -> V_73 ) ;
V_140 = ( V_71 -> V_141 == 0 ) ;
if ( F_77 ( V_140 ) )
F_78 ( V_2 -> V_76 , V_71 ) ;
F_41 ( & V_2 -> V_73 ) ;
return V_140 ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_63 * V_71 ;
int V_78 ;
F_28 ( V_2 , F_13 ( V_142 , & V_2 -> V_76 -> V_25 ) ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_76 -> V_115 ; V_78 ++ ) {
V_71 = F_55 ( V_2 -> V_76 , V_78 ) ;
if ( V_71 -> V_84 == V_112 )
continue;
F_2 ( V_2 -> V_75 , F_76 ( V_2 , V_71 ) ) ;
}
F_7 ( & V_2 -> V_75 ) ;
}
int F_80 ( struct V_1 * V_2 , void * V_99 )
{
struct V_98 * V_130 = V_99 ;
struct V_143 * V_89 = & V_2 -> V_50 -> V_89 ;
int V_95 = V_89 -> V_90 * V_89 -> V_92 ;
int V_78 ;
F_48 ( V_2 , V_130 ) ;
F_39 ( & V_2 -> V_73 ) ;
F_64 ( V_2 -> V_76 ) ;
F_41 ( & V_2 -> V_73 ) ;
for ( V_78 = 1 ; V_78 < V_95 ; V_78 ++ ) {
int V_31 = F_48 ( V_2 , V_130 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static bool F_81 ( struct V_1 * V_2 ,
unsigned int V_62 , int V_144 ,
enum V_145 V_146 )
{
struct V_63 * V_100 ;
F_28 ( V_2 , F_29 ( & V_2 -> V_82 ) ) ;
if ( V_146 == V_147 )
V_100 = F_35 ( V_2 -> V_65 , V_62 ) ;
else
V_100 = F_43 ( V_2 -> V_65 , V_62 ) ;
if ( V_100 ) {
struct V_61 * V_148 = F_37 ( V_100 , struct V_61 , V_68 ) ;
if ( V_148 -> V_68 . V_84 == V_62 ) {
if ( V_146 == V_149 )
V_148 -> V_150 -= V_144 ;
else if ( V_146 == V_147 )
V_148 -> V_150 += V_144 ;
else
V_148 -> V_151 += V_144 ;
if ( V_148 -> V_150 < V_148 -> V_151 ) {
F_82 ( V_2 , L_13
L_14 ,
V_148 -> V_68 . V_84 , V_148 -> V_150 ,
V_148 -> V_151 , V_144 ,
F_83 ( V_2 -> V_8 . V_152 ) ) ;
V_148 -> V_150 = F_84 ( V_2 , V_62 ) ;
}
} else {
int V_150 = F_84 ( V_2 , V_62 ) ;
if ( V_148 -> V_25 != 0 ) {
F_82 ( V_2 , L_15
L_16 ,
V_148 -> V_68 . V_84 , V_148 -> V_150 ,
V_148 -> V_25 , V_62 , V_150 ) ;
V_148 -> V_25 = 0 ;
}
if ( V_148 -> V_151 ) {
F_82 ( V_2 , L_17
L_18 ,
V_148 -> V_68 . V_84 , V_148 -> V_151 ) ;
}
V_148 -> V_150 = V_150 ;
V_148 -> V_151 = ( V_146 == V_153 ) ? V_144 : 0 ;
F_64 ( V_2 -> V_65 ) ;
}
if ( V_146 != V_147 )
F_74 ( V_2 -> V_65 , & V_148 -> V_68 ) ;
if ( V_148 -> V_150 <= V_148 -> V_151 ) {
V_148 -> V_151 = 0 ;
return true ;
}
} else if ( V_146 != V_147 ) {
F_14 ( V_2 , L_19 ,
V_2 -> V_154 ,
V_2 -> V_65 -> V_115 ,
V_2 -> V_65 -> V_25 ) ;
}
return false ;
}
void F_85 ( struct V_1 * V_2 , unsigned long V_155 )
{
unsigned long V_156 = V_13 ;
unsigned long V_81 = V_2 -> V_157 [ V_2 -> V_158 ] ;
int V_159 = ( V_2 -> V_158 + 1 ) % V_160 ;
if ( F_86 ( V_156 , V_81 + V_161 ) ) {
if ( V_2 -> V_162 [ V_2 -> V_158 ] != V_155 &&
V_2 -> V_8 . V_152 != V_163 &&
V_2 -> V_8 . V_152 != V_164 ) {
V_2 -> V_157 [ V_159 ] = V_156 ;
V_2 -> V_162 [ V_159 ] = V_155 ;
V_2 -> V_158 = V_159 ;
}
}
}
static bool F_87 ( struct V_1 * V_2 )
{
return F_88 ( V_13 , V_2 -> V_165 + 2 * V_22 ) ;
}
static void F_89 ( struct V_1 * V_2 , bool V_166 )
{
if ( V_166 ) {
struct V_167 * V_168 = F_90 ( V_2 ) -> V_168 ;
if ( V_168 -> V_169 <= 95 ||
F_91 ( V_2 -> V_8 . V_152 ) )
F_92 ( V_170 , & V_2 -> V_25 ) ;
} else if ( ! F_87 ( V_2 ) )
return;
F_93 ( V_2 , V_171 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
unsigned long V_172 , unsigned long V_173 ,
enum V_145 V_146 )
{
unsigned long V_25 ;
unsigned long V_144 = 0 ;
unsigned int V_174 = 0 ;
while ( V_172 <= V_173 ) {
unsigned long V_175 = F_68 ( V_173 , V_172 | V_176 ) ;
unsigned long V_177 ;
if ( V_146 == V_153 )
V_177 = F_95 ( V_2 , V_172 , V_175 ) ;
else if ( V_146 == V_149 )
V_177 = F_96 ( V_2 , V_172 , V_175 ) ;
else
V_177 = F_97 ( V_2 , V_172 , V_175 ) ;
if ( V_177 ) {
F_73 ( & V_2 -> V_73 , V_25 ) ;
V_174 += F_81 ( V_2 , F_98 ( V_172 ) , V_177 , V_146 ) ;
F_75 ( & V_2 -> V_73 , V_25 ) ;
V_144 += V_177 ;
}
V_172 = V_175 + 1 ;
}
if ( V_144 ) {
if ( V_146 == V_149 ) {
unsigned long V_155 = F_99 ( V_2 ) ;
bool V_178 = ( V_155 <= V_2 -> V_151 ) ;
F_85 ( V_2 , V_155 ) ;
if ( V_174 || V_178 )
F_89 ( V_2 , V_178 ) ;
} else if ( V_146 == V_153 )
V_2 -> V_151 += V_144 ;
F_7 ( & V_2 -> V_75 ) ;
}
return V_144 ;
}
static bool F_100 ( int V_30 )
{
return V_30 > 0
&& V_30 <= V_179
&& F_101 ( V_30 , 512 ) ;
}
int F_102 ( struct V_1 * V_2 , T_1 V_27 , int V_30 ,
enum V_145 V_146 )
{
unsigned long V_172 , V_173 , V_180 ;
unsigned long V_144 = 0 ;
T_1 V_181 , V_182 ;
if ( ( V_146 == V_147 ) && V_30 == 0 )
return 0 ;
if ( ! F_100 ( V_30 ) ) {
F_14 ( V_2 , L_20 ,
V_183 [ V_146 ] ,
( unsigned long long ) V_27 , V_30 ) ;
return 0 ;
}
if ( ! F_59 ( V_2 ) )
return 0 ;
V_182 = F_103 ( V_2 -> V_184 ) ;
V_181 = V_27 + ( V_30 >> 9 ) - 1 ;
if ( ! F_104 ( V_27 < V_182 ) )
goto V_45;
if ( ! F_104 ( V_181 < V_182 ) )
V_181 = V_182 - 1 ;
V_180 = F_105 ( V_182 - 1 ) ;
if ( V_146 == V_149 ) {
if ( F_36 ( V_181 < V_185 - 1 ) )
goto V_45;
if ( F_36 ( V_181 == ( V_182 - 1 ) ) )
V_173 = V_180 ;
else
V_173 = F_105 ( V_181 - ( V_185 - 1 ) ) ;
V_172 = F_105 ( V_27 + V_185 - 1 ) ;
} else {
V_172 = F_105 ( V_27 ) ;
V_173 = F_105 ( V_181 ) ;
}
V_144 = F_94 ( V_2 , V_172 , V_173 , V_146 ) ;
V_45:
F_61 ( V_2 ) ;
return V_144 ;
}
static
struct V_61 * F_106 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_63 * V_100 ;
struct V_61 * V_67 ;
int V_186 = 0 ;
unsigned long V_187 ;
F_39 ( & V_2 -> V_73 ) ;
if ( V_2 -> V_154 > V_2 -> V_65 -> V_115 / 2 ) {
F_41 ( & V_2 -> V_73 ) ;
return NULL ;
}
V_100 = F_43 ( V_2 -> V_65 , V_62 ) ;
V_67 = V_100 ? F_37 ( V_100 , struct V_61 , V_68 ) : NULL ;
if ( V_67 ) {
if ( V_67 -> V_68 . V_84 != V_62 ) {
V_67 -> V_150 = F_84 ( V_2 , V_62 ) ;
V_67 -> V_151 = 0 ;
F_64 ( V_2 -> V_65 ) ;
V_186 = 1 ;
}
if ( V_67 -> V_68 . V_141 == 1 )
V_2 -> V_154 ++ ;
F_92 ( V_69 , & V_67 -> V_25 ) ;
}
V_187 = V_2 -> V_65 -> V_25 ;
F_41 ( & V_2 -> V_73 ) ;
if ( V_186 )
F_7 ( & V_2 -> V_75 ) ;
if ( ! V_67 ) {
if ( V_187 & V_188 )
F_82 ( V_2 , L_21
L_22 ) ;
F_30 ( V_187 & V_189 ) ;
}
return V_67 ;
}
static int F_107 ( struct V_1 * V_2 , unsigned int V_62 )
{
int V_140 ;
F_39 ( & V_2 -> V_73 ) ;
V_140 = F_108 ( V_2 -> V_76 , V_62 ) ;
F_41 ( & V_2 -> V_73 ) ;
return V_140 ;
}
int F_109 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_62 = F_110 ( V_27 ) ;
struct V_61 * V_67 ;
int V_78 , V_190 ;
bool V_191 ;
V_192:
V_190 = F_111 ( V_2 -> V_75 ,
( V_67 = F_106 ( V_2 , V_62 ) ) ) ;
if ( V_190 )
return - V_193 ;
if ( F_13 ( V_194 , & V_67 -> V_25 ) )
return 0 ;
V_191 = F_112 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_66 ; V_78 ++ ) {
V_190 = F_111 ( V_2 -> V_75 ,
! F_107 ( V_2 , V_62 * V_66 + V_78 ) ||
( V_191 && F_13 ( V_74 , & V_67 -> V_25 ) ) ) ;
if ( V_190 || ( V_191 && F_13 ( V_74 , & V_67 -> V_25 ) ) ) {
F_39 ( & V_2 -> V_73 ) ;
if ( F_74 ( V_2 -> V_65 , & V_67 -> V_68 ) == 0 ) {
V_67 -> V_25 = 0 ;
V_2 -> V_154 -- ;
F_7 ( & V_2 -> V_75 ) ;
}
F_41 ( & V_2 -> V_73 ) ;
if ( V_190 )
return - V_193 ;
if ( F_113 ( V_22 / 10 ) )
return - V_193 ;
goto V_192;
}
}
F_92 ( V_194 , & V_67 -> V_25 ) ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_62 = F_110 ( V_27 ) ;
const unsigned int V_85 = V_62 * V_66 ;
struct V_63 * V_100 ;
struct V_61 * V_67 ;
int V_78 ;
bool V_195 = F_115 ( V_2 , V_27 , true ) ;
if ( V_195 && V_2 -> V_196 != V_62 )
return - V_197 ;
F_39 ( & V_2 -> V_73 ) ;
if ( V_2 -> V_196 != V_112 && V_2 -> V_196 != V_62 ) {
V_100 = F_35 ( V_2 -> V_65 , V_2 -> V_196 ) ;
V_67 = V_100 ? F_37 ( V_100 , struct V_61 , V_68 ) : NULL ;
if ( V_67 ) {
F_28 ( V_2 , ! F_13 ( V_194 , & V_67 -> V_25 ) ) ;
F_28 ( V_2 , F_13 ( V_69 , & V_67 -> V_25 ) ) ;
F_116 ( V_69 , & V_67 -> V_25 ) ;
V_2 -> V_196 = V_112 ;
if ( F_74 ( V_2 -> V_65 , & V_67 -> V_68 ) == 0 ) {
V_67 -> V_25 = 0 ;
V_2 -> V_154 -- ;
}
F_7 ( & V_2 -> V_75 ) ;
} else {
F_33 ( V_2 , L_23 ) ;
}
}
V_100 = F_42 ( V_2 -> V_65 , V_62 ) ;
V_67 = V_100 ? F_37 ( V_100 , struct V_61 , V_68 ) : NULL ;
if ( V_67 ) {
if ( F_13 ( V_194 , & V_67 -> V_25 ) )
goto V_198;
if ( ! F_40 ( V_69 , & V_67 -> V_25 ) ) {
V_2 -> V_154 ++ ;
} else {
V_67 -> V_68 . V_141 -- ;
F_28 ( V_2 , V_67 -> V_68 . V_141 > 0 ) ;
}
goto V_199;
} else {
if ( V_2 -> V_154 > V_2 -> V_65 -> V_115 - 3 )
goto V_200;
V_100 = F_43 ( V_2 -> V_65 , V_62 ) ;
V_67 = V_100 ? F_37 ( V_100 , struct V_61 , V_68 ) : NULL ;
if ( ! V_67 ) {
const unsigned long V_187 = V_2 -> V_65 -> V_25 ;
if ( V_187 & V_188 )
F_82 ( V_2 , L_21
L_22 ) ;
F_30 ( V_187 & V_189 ) ;
goto V_200;
}
if ( V_67 -> V_68 . V_84 != V_62 ) {
V_67 -> V_150 = F_84 ( V_2 , V_62 ) ;
V_67 -> V_151 = 0 ;
F_64 ( V_2 -> V_65 ) ;
F_7 ( & V_2 -> V_75 ) ;
F_28 ( V_2 , F_13 ( V_194 , & V_67 -> V_25 ) == 0 ) ;
}
F_92 ( V_69 , & V_67 -> V_25 ) ;
F_28 ( V_2 , V_67 -> V_68 . V_141 == 1 ) ;
V_2 -> V_154 ++ ;
goto V_199;
}
V_199:
for ( V_78 = 0 ; V_78 < V_66 ; V_78 ++ ) {
if ( F_108 ( V_2 -> V_76 , V_85 + V_78 ) )
goto V_200;
}
F_92 ( V_194 , & V_67 -> V_25 ) ;
V_198:
V_2 -> V_196 = V_112 ;
F_41 ( & V_2 -> V_73 ) ;
return 0 ;
V_200:
if ( V_67 ) {
if ( V_195 ) {
F_28 ( V_2 , ! F_13 ( V_194 , & V_67 -> V_25 ) ) ;
F_28 ( V_2 , F_13 ( V_69 , & V_67 -> V_25 ) ) ;
F_116 ( V_69 , & V_67 -> V_25 ) ;
V_2 -> V_196 = V_112 ;
if ( F_74 ( V_2 -> V_65 , & V_67 -> V_68 ) == 0 ) {
V_67 -> V_25 = 0 ;
V_2 -> V_154 -- ;
}
F_7 ( & V_2 -> V_75 ) ;
} else
V_2 -> V_196 = V_62 ;
}
F_41 ( & V_2 -> V_73 ) ;
return - V_197 ;
}
void F_117 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_62 = F_110 ( V_27 ) ;
struct V_63 * V_100 ;
struct V_61 * V_67 ;
unsigned long V_25 ;
F_73 ( & V_2 -> V_73 , V_25 ) ;
V_100 = F_35 ( V_2 -> V_65 , V_62 ) ;
V_67 = V_100 ? F_37 ( V_100 , struct V_61 , V_68 ) : NULL ;
if ( ! V_67 ) {
F_75 ( & V_2 -> V_73 , V_25 ) ;
if ( F_118 ( & V_201 ) )
F_14 ( V_2 , L_24 ) ;
return;
}
if ( V_67 -> V_68 . V_141 == 0 ) {
F_75 ( & V_2 -> V_73 , V_25 ) ;
F_14 ( V_2 , L_25
L_26 ,
( unsigned long long ) V_27 , V_62 ) ;
return;
}
if ( F_74 ( V_2 -> V_65 , & V_67 -> V_68 ) == 0 ) {
V_67 -> V_25 = 0 ;
V_2 -> V_154 -- ;
F_7 ( & V_2 -> V_75 ) ;
}
F_75 ( & V_2 -> V_73 , V_25 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_73 ) ;
if ( F_20 ( V_2 , V_10 ) ) {
F_120 ( V_2 -> V_65 ) ;
F_61 ( V_2 ) ;
}
V_2 -> V_154 = 0 ;
V_2 -> V_196 = V_112 ;
F_41 ( & V_2 -> V_73 ) ;
F_7 ( & V_2 -> V_75 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_63 * V_100 ;
struct V_61 * V_67 ;
int V_78 ;
F_39 ( & V_2 -> V_73 ) ;
if ( F_20 ( V_2 , V_10 ) ) {
for ( V_78 = 0 ; V_78 < V_2 -> V_65 -> V_115 ; V_78 ++ ) {
V_100 = F_55 ( V_2 -> V_65 , V_78 ) ;
V_67 = F_37 ( V_100 , struct V_61 , V_68 ) ;
if ( V_67 -> V_68 . V_84 == V_112 )
continue;
if ( V_67 -> V_68 . V_84 == V_2 -> V_196 ) {
F_71 ( V_2 , L_27
L_28 ,
V_2 -> V_196 ) ;
F_28 ( V_2 , ! F_13 ( V_194 , & V_67 -> V_25 ) ) ;
F_28 ( V_2 , F_13 ( V_69 , & V_67 -> V_25 ) ) ;
F_116 ( V_69 , & V_67 -> V_25 ) ;
V_2 -> V_196 = V_112 ;
F_74 ( V_2 -> V_65 , & V_67 -> V_68 ) ;
}
if ( V_67 -> V_68 . V_141 != 0 ) {
F_71 ( V_2 , L_29
L_30 , V_67 -> V_68 . V_141 ) ;
F_61 ( V_2 ) ;
F_41 ( & V_2 -> V_73 ) ;
return - V_197 ;
}
F_28 ( V_2 , ! F_13 ( V_194 , & V_67 -> V_25 ) ) ;
F_28 ( V_2 , ! F_13 ( V_69 , & V_67 -> V_25 ) ) ;
F_78 ( V_2 -> V_65 , & V_67 -> V_68 ) ;
}
F_28 ( V_2 , V_2 -> V_65 -> V_133 == 0 ) ;
F_61 ( V_2 ) ;
}
F_41 ( & V_2 -> V_73 ) ;
F_7 ( & V_2 -> V_75 ) ;
return 0 ;
}
