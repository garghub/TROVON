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
F_18 ( V_29 , V_17 -> V_40 ) ;
V_29 -> V_41 . V_42 = V_27 ;
V_31 = - V_43 ;
if ( F_19 ( V_29 , V_2 -> V_6 . V_15 , V_30 , 0 ) != V_30 )
goto V_44;
V_29 -> V_45 = V_2 ;
V_29 -> V_46 = V_47 ;
F_20 ( V_29 , V_28 , V_32 ) ;
if ( V_28 != V_34 && V_2 -> V_8 . V_9 == V_48 && V_2 -> V_49 == NULL )
;
else if ( ! F_21 ( V_2 , V_50 ) ) {
F_14 ( V_2 , L_2 ) ;
V_31 = - V_33 ;
goto V_44;
}
F_22 ( V_29 ) ;
F_23 ( & V_2 -> V_6 . V_7 ) ;
V_2 -> V_6 . V_14 = V_13 ;
if ( F_24 ( V_2 , ( V_28 == V_34 ) ? V_51 : V_52 ) )
F_25 ( V_29 ) ;
else
F_26 ( V_29 ) ;
F_8 ( V_2 , V_17 , & V_2 -> V_6 . V_18 ) ;
if ( ! V_29 -> V_53 )
V_31 = V_2 -> V_6 . error ;
V_44:
F_27 ( V_29 ) ;
return V_31 ;
}
int F_28 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_1 V_27 , int V_28 )
{
int V_31 ;
F_29 ( V_2 , F_30 ( & V_2 -> V_6 . V_7 ) == 1 ) ;
F_31 ( ! V_17 -> V_40 ) ;
F_32 ( V_2 , L_3 ,
V_54 -> V_55 , V_54 -> V_56 , V_57 ,
( unsigned long long ) V_27 , ( V_28 == V_34 ) ? L_4 : L_5 ,
( void * ) V_58 ) ;
if ( V_27 < V_59 ( V_17 ) ||
V_27 + 7 > F_33 ( V_17 ) )
F_34 ( V_2 , L_6 ,
V_54 -> V_55 , V_54 -> V_56 , V_57 ,
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
static struct V_60 * F_35 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_62 * V_63 ;
V_63 = F_36 ( V_2 -> V_64 , V_61 / V_65 ) ;
if ( F_37 ( V_63 != NULL ) ) {
struct V_60 * V_66 = F_38 ( V_63 , struct V_60 , V_67 ) ;
if ( F_13 ( V_68 , & V_66 -> V_25 ) )
return V_66 ;
}
return NULL ;
}
static struct V_62 * F_39 ( struct V_1 * V_2 , unsigned int V_61 , bool V_69 )
{
struct V_62 * V_70 ;
struct V_60 * V_66 ;
int V_71 ;
F_40 ( & V_2 -> V_72 ) ;
V_66 = F_35 ( V_2 , V_61 ) ;
if ( V_66 ) {
V_71 = ! F_41 ( V_73 , & V_66 -> V_25 ) ;
F_42 ( & V_2 -> V_72 ) ;
if ( V_71 )
F_7 ( & V_2 -> V_74 ) ;
return NULL ;
}
if ( V_69 )
V_70 = F_43 ( V_2 -> V_75 , V_61 ) ;
else
V_70 = F_44 ( V_2 -> V_75 , V_61 ) ;
F_42 ( & V_2 -> V_72 ) ;
return V_70 ;
}
bool F_45 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
unsigned V_78 = V_77 -> V_27 >> ( V_79 - 9 ) ;
unsigned V_80 = V_77 -> V_30 == 0 ? V_78 : ( V_77 -> V_27 + ( V_77 -> V_30 >> 9 ) - 1 ) >> ( V_79 - 9 ) ;
F_29 ( V_2 , V_78 <= V_80 ) ;
F_29 ( V_2 , F_30 ( & V_2 -> V_81 ) > 0 ) ;
if ( V_78 != V_80 )
return false ;
return F_39 ( V_2 , V_78 , true ) ;
}
bool F_46 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
unsigned V_78 = V_77 -> V_27 >> ( V_79 - 9 ) ;
unsigned V_80 = V_77 -> V_30 == 0 ? V_78 : ( V_77 -> V_27 + ( V_77 -> V_30 >> 9 ) - 1 ) >> ( V_79 - 9 ) ;
unsigned V_61 ;
bool V_82 = false ;
F_29 ( V_2 , V_78 <= V_80 ) ;
F_29 ( V_2 , F_30 ( & V_2 -> V_81 ) > 0 ) ;
for ( V_61 = V_78 ; V_61 <= V_80 ; V_61 ++ ) {
struct V_62 * V_70 ;
F_2 ( V_2 -> V_74 ,
( V_70 = F_39 ( V_2 , V_61 , false ) ) != NULL ) ;
if ( V_70 -> V_83 != V_61 )
V_82 = true ;
}
return V_82 ;
}
static unsigned int F_47 ( unsigned int V_84 )
{
return V_84 >>
( ( V_85 + 3 ) -
( V_79 - V_86 ) ) ;
}
static T_1 F_48 ( struct V_1 * V_2 )
{
const unsigned int V_87 = V_2 -> V_49 -> V_88 . V_89 ;
const unsigned int V_90 = V_2 -> V_49 -> V_88 . V_91 ;
unsigned int V_92 = V_2 -> V_93 % ( V_2 -> V_49 -> V_88 . V_94 ) ;
V_92 = ( ( V_92 % V_87 ) * V_90 ) + V_92 / V_87 ;
V_92 *= 8 ;
return V_2 -> V_49 -> V_88 . V_95 + V_2 -> V_49 -> V_88 . V_96 + V_92 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_62 * V_99 ;
T_1 V_27 ;
int V_77 , V_100 ;
unsigned V_101 ;
unsigned V_102 = 0 ;
int V_31 = 0 ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_103 = F_50 ( V_104 ) ;
V_98 -> V_105 = F_50 ( V_2 -> V_93 ) ;
V_77 = 0 ;
F_51 ( V_2 ) ;
F_40 ( & V_2 -> V_72 ) ;
F_52 (e, &device->act_log->to_be_changed, list) {
if ( V_77 == V_106 ) {
V_77 ++ ;
break;
}
V_98 -> V_107 [ V_77 ] = F_53 ( V_99 -> V_108 ) ;
V_98 -> V_109 [ V_77 ] = F_50 ( V_99 -> V_110 ) ;
if ( V_99 -> V_83 != V_111 )
F_54 ( V_2 ,
F_47 ( V_99 -> V_83 ) ) ;
V_77 ++ ;
}
F_42 ( & V_2 -> V_72 ) ;
F_31 ( V_77 > V_106 ) ;
V_98 -> V_112 = F_53 ( V_77 ) ;
for ( ; V_77 < V_106 ; V_77 ++ ) {
V_98 -> V_107 [ V_77 ] = F_53 ( - 1 ) ;
V_98 -> V_109 [ V_77 ] = F_50 ( V_111 ) ;
}
V_98 -> V_113 = F_53 ( V_2 -> V_75 -> V_114 ) ;
V_98 -> V_115 = F_53 ( V_2 -> V_116 ) ;
V_100 = F_55 ( int , V_117 ,
V_2 -> V_75 -> V_114 - V_2 -> V_116 ) ;
for ( V_77 = 0 ; V_77 < V_100 ; V_77 ++ ) {
unsigned V_118 = V_2 -> V_116 + V_77 ;
V_101 = F_56 ( V_2 -> V_75 , V_118 ) -> V_83 ;
V_98 -> V_119 [ V_77 ] = F_50 ( V_101 ) ;
}
for (; V_77 < V_117 ; V_77 ++ )
V_98 -> V_119 [ V_77 ] = F_50 ( V_111 ) ;
V_2 -> V_116 += V_117 ;
if ( V_2 -> V_116 >= V_2 -> V_75 -> V_114 )
V_2 -> V_116 = 0 ;
V_27 = F_48 ( V_2 ) ;
V_102 = F_57 ( 0 , V_98 , 4096 ) ;
V_98 -> F_57 = F_50 ( V_102 ) ;
if ( F_58 ( V_2 ) )
V_31 = - V_43 ;
else {
bool V_120 ;
F_9 () ;
V_120 = F_10 ( V_2 -> V_49 -> V_20 ) -> V_121 ;
F_11 () ;
if ( V_120 ) {
if ( F_28 ( V_2 , V_2 -> V_49 , V_27 , V_122 ) ) {
V_31 = - V_43 ;
F_15 ( V_2 , 1 , V_123 ) ;
} else {
V_2 -> V_93 ++ ;
V_2 -> V_124 ++ ;
}
}
}
return V_31 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
int V_31 ;
if ( ! F_60 ( V_2 ) ) {
F_14 ( V_2 , L_8 ,
F_61 ( V_2 -> V_8 . V_9 ) ) ;
return - V_43 ;
}
if ( V_2 -> V_8 . V_9 < V_125 ) {
F_14 ( V_2 ,
L_9 ,
F_61 ( V_2 -> V_8 . V_9 ) ) ;
F_62 ( V_2 ) ;
return - V_43 ;
}
V_98 = F_1 ( V_2 , V_57 ) ;
if ( ! V_98 ) {
F_14 ( V_2 , L_10 ) ;
F_62 ( V_2 ) ;
return - V_33 ;
}
V_31 = F_49 ( V_2 , V_98 ) ;
F_5 ( V_2 ) ;
F_62 ( V_2 ) ;
return V_31 ;
}
void F_63 ( struct V_1 * V_2 )
{
bool V_126 = false ;
F_2 ( V_2 -> V_74 ,
V_2 -> V_75 -> V_127 == 0 ||
( V_126 = F_64 ( V_2 -> V_75 ) ) ) ;
if ( V_126 ) {
if ( V_2 -> V_75 -> V_127 ) {
bool V_120 ;
F_9 () ;
V_120 = F_10 ( V_2 -> V_49 -> V_20 ) -> V_121 ;
F_11 () ;
if ( V_120 )
F_59 ( V_2 ) ;
F_40 ( & V_2 -> V_72 ) ;
F_65 ( V_2 -> V_75 ) ;
F_42 ( & V_2 -> V_72 ) ;
}
F_66 ( V_2 -> V_75 ) ;
F_7 ( & V_2 -> V_74 ) ;
}
}
void F_67 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
if ( F_46 ( V_2 , V_77 ) )
F_63 ( V_2 ) ;
}
int F_68 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_128 * V_129 = V_2 -> V_75 ;
unsigned V_78 = V_77 -> V_27 >> ( V_79 - 9 ) ;
unsigned V_80 = V_77 -> V_30 == 0 ? V_78 : ( V_77 -> V_27 + ( V_77 -> V_30 >> 9 ) - 1 ) >> ( V_79 - 9 ) ;
unsigned V_130 ;
unsigned V_131 ;
unsigned V_61 ;
F_29 ( V_2 , V_78 <= V_80 ) ;
V_130 = 1 + V_80 - V_78 ;
V_131 = F_69 ( V_129 -> V_114 - V_129 -> V_132 ,
V_129 -> V_133 - V_129 -> V_127 ) ;
if ( V_131 < V_130 ) {
if ( ! V_129 -> V_127 )
F_70 ( V_134 , & V_2 -> V_75 -> V_25 ) ;
return - V_135 ;
}
for ( V_61 = V_78 ; V_61 <= V_80 ; V_61 ++ ) {
struct V_62 * V_63 ;
V_63 = F_36 ( V_2 -> V_64 , V_61 / V_65 ) ;
if ( F_37 ( V_63 != NULL ) ) {
struct V_60 * V_66 = F_38 ( V_63 , struct V_60 , V_67 ) ;
if ( F_13 ( V_68 , & V_66 -> V_25 ) ) {
if ( ! F_41 ( V_73 , & V_66 -> V_25 ) )
return - V_136 ;
return - V_137 ;
}
}
}
for ( V_61 = V_78 ; V_61 <= V_80 ; V_61 ++ ) {
struct V_62 * V_70 ;
V_70 = F_71 ( V_2 -> V_75 , V_61 ) ;
if ( ! V_70 )
F_72 ( V_2 , L_11 , V_61 ) ;
}
return 0 ;
}
void F_73 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
unsigned V_78 = V_77 -> V_27 >> ( V_79 - 9 ) ;
unsigned V_80 = V_77 -> V_30 == 0 ? V_78 : ( V_77 -> V_27 + ( V_77 -> V_30 >> 9 ) - 1 ) >> ( V_79 - 9 ) ;
unsigned V_61 ;
struct V_62 * V_138 ;
unsigned long V_25 ;
F_29 ( V_2 , V_78 <= V_80 ) ;
F_74 ( & V_2 -> V_72 , V_25 ) ;
for ( V_61 = V_78 ; V_61 <= V_80 ; V_61 ++ ) {
V_138 = F_36 ( V_2 -> V_75 , V_61 ) ;
if ( ! V_138 ) {
F_14 ( V_2 , L_12 , V_61 ) ;
continue;
}
F_75 ( V_2 -> V_75 , V_138 ) ;
}
F_76 ( & V_2 -> V_72 , V_25 ) ;
F_7 ( & V_2 -> V_74 ) ;
}
static int F_77 ( struct V_1 * V_2 , struct V_62 * V_70 )
{
int V_139 ;
F_40 ( & V_2 -> V_72 ) ;
V_139 = ( V_70 -> V_140 == 0 ) ;
if ( F_78 ( V_139 ) )
F_79 ( V_2 -> V_75 , V_70 ) ;
F_42 ( & V_2 -> V_72 ) ;
return V_139 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_62 * V_70 ;
int V_77 ;
F_29 ( V_2 , F_13 ( V_141 , & V_2 -> V_75 -> V_25 ) ) ;
for ( V_77 = 0 ; V_77 < V_2 -> V_75 -> V_114 ; V_77 ++ ) {
V_70 = F_56 ( V_2 -> V_75 , V_77 ) ;
if ( V_70 -> V_83 == V_111 )
continue;
F_2 ( V_2 -> V_74 , F_77 ( V_2 , V_70 ) ) ;
}
F_7 ( & V_2 -> V_74 ) ;
}
int F_81 ( struct V_1 * V_2 , void * V_98 )
{
struct V_97 * V_129 = V_98 ;
struct V_142 * V_88 = & V_2 -> V_49 -> V_88 ;
int V_94 = V_88 -> V_89 * V_88 -> V_91 ;
int V_77 ;
F_49 ( V_2 , V_129 ) ;
F_40 ( & V_2 -> V_72 ) ;
F_65 ( V_2 -> V_75 ) ;
F_42 ( & V_2 -> V_72 ) ;
for ( V_77 = 1 ; V_77 < V_94 ; V_77 ++ ) {
int V_31 = F_49 ( V_2 , V_129 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static bool F_82 ( struct V_1 * V_2 ,
unsigned int V_61 , int V_143 ,
enum V_144 V_145 )
{
struct V_62 * V_99 ;
F_29 ( V_2 , F_30 ( & V_2 -> V_81 ) ) ;
if ( V_145 == V_146 )
V_99 = F_36 ( V_2 -> V_64 , V_61 ) ;
else
V_99 = F_44 ( V_2 -> V_64 , V_61 ) ;
if ( V_99 ) {
struct V_60 * V_147 = F_38 ( V_99 , struct V_60 , V_67 ) ;
if ( V_147 -> V_67 . V_83 == V_61 ) {
if ( V_145 == V_148 )
V_147 -> V_149 -= V_143 ;
else if ( V_145 == V_146 )
V_147 -> V_149 += V_143 ;
else
V_147 -> V_150 += V_143 ;
if ( V_147 -> V_149 < V_147 -> V_150 ) {
F_83 ( V_2 , L_13
L_14 ,
V_147 -> V_67 . V_83 , V_147 -> V_149 ,
V_147 -> V_150 , V_143 ,
F_84 ( V_2 -> V_8 . V_151 ) ) ;
V_147 -> V_149 = F_85 ( V_2 , V_61 ) ;
}
} else {
int V_149 = F_85 ( V_2 , V_61 ) ;
if ( V_147 -> V_25 != 0 ) {
F_83 ( V_2 , L_15
L_16 ,
V_147 -> V_67 . V_83 , V_147 -> V_149 ,
V_147 -> V_25 , V_61 , V_149 ) ;
V_147 -> V_25 = 0 ;
}
if ( V_147 -> V_150 ) {
F_83 ( V_2 , L_17
L_18 ,
V_147 -> V_67 . V_83 , V_147 -> V_150 ) ;
}
V_147 -> V_149 = V_149 ;
V_147 -> V_150 = ( V_145 == V_152 ) ? V_143 : 0 ;
F_65 ( V_2 -> V_64 ) ;
}
if ( V_145 != V_146 )
F_75 ( V_2 -> V_64 , & V_147 -> V_67 ) ;
if ( V_147 -> V_149 <= V_147 -> V_150 ) {
V_147 -> V_150 = 0 ;
return true ;
}
} else if ( V_145 != V_146 ) {
F_14 ( V_2 , L_19 ,
V_2 -> V_153 ,
V_2 -> V_64 -> V_114 ,
V_2 -> V_64 -> V_25 ) ;
}
return false ;
}
void F_86 ( struct V_1 * V_2 , unsigned long V_154 )
{
unsigned long V_155 = V_13 ;
unsigned long V_80 = V_2 -> V_156 [ V_2 -> V_157 ] ;
int V_158 = ( V_2 -> V_157 + 1 ) % V_159 ;
if ( F_87 ( V_155 , V_80 + V_160 ) ) {
if ( V_2 -> V_161 [ V_2 -> V_157 ] != V_154 &&
V_2 -> V_8 . V_151 != V_162 &&
V_2 -> V_8 . V_151 != V_163 ) {
V_2 -> V_156 [ V_158 ] = V_155 ;
V_2 -> V_161 [ V_158 ] = V_154 ;
V_2 -> V_157 = V_158 ;
}
}
}
static bool F_88 ( struct V_1 * V_2 )
{
return F_89 ( V_13 , V_2 -> V_164 + 2 * V_22 ) ;
}
static void F_90 ( struct V_1 * V_2 , bool V_165 )
{
if ( V_165 ) {
struct V_166 * V_167 = F_91 ( V_2 ) -> V_167 ;
if ( V_167 -> V_168 <= 95 ||
F_92 ( V_2 -> V_8 . V_151 ) )
F_93 ( V_169 , & V_2 -> V_25 ) ;
} else if ( ! F_88 ( V_2 ) )
return;
F_94 ( V_2 , V_170 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
unsigned long V_171 , unsigned long V_172 ,
enum V_144 V_145 )
{
unsigned long V_25 ;
unsigned long V_143 = 0 ;
unsigned int V_173 = 0 ;
while ( V_171 <= V_172 ) {
unsigned long V_174 = F_69 ( V_172 , V_171 | V_175 ) ;
unsigned long V_176 ;
if ( V_145 == V_152 )
V_176 = F_96 ( V_2 , V_171 , V_174 ) ;
else if ( V_145 == V_148 )
V_176 = F_97 ( V_2 , V_171 , V_174 ) ;
else
V_176 = F_98 ( V_2 , V_171 , V_174 ) ;
if ( V_176 ) {
F_74 ( & V_2 -> V_72 , V_25 ) ;
V_173 += F_82 ( V_2 , F_99 ( V_171 ) , V_176 , V_145 ) ;
F_76 ( & V_2 -> V_72 , V_25 ) ;
V_143 += V_176 ;
}
V_171 = V_174 + 1 ;
}
if ( V_143 ) {
if ( V_145 == V_148 ) {
unsigned long V_154 = F_100 ( V_2 ) ;
bool V_177 = ( V_154 <= V_2 -> V_150 ) ;
F_86 ( V_2 , V_154 ) ;
if ( V_173 || V_177 )
F_90 ( V_2 , V_177 ) ;
} else if ( V_145 == V_152 )
V_2 -> V_150 += V_143 ;
F_7 ( & V_2 -> V_74 ) ;
}
return V_143 ;
}
static bool F_101 ( int V_30 )
{
return V_30 > 0
&& V_30 <= V_178
&& F_102 ( V_30 , 512 ) ;
}
int F_103 ( struct V_1 * V_2 , T_1 V_27 , int V_30 ,
enum V_144 V_145 )
{
unsigned long V_171 , V_172 , V_179 ;
unsigned long V_143 = 0 ;
T_1 V_180 , V_181 ;
if ( ( V_145 == V_146 ) && V_30 == 0 )
return 0 ;
if ( ! F_101 ( V_30 ) ) {
F_14 ( V_2 , L_20 ,
V_182 [ V_145 ] ,
( unsigned long long ) V_27 , V_30 ) ;
return 0 ;
}
if ( ! F_60 ( V_2 ) )
return 0 ;
V_181 = F_104 ( V_2 -> V_183 ) ;
V_180 = V_27 + ( V_30 >> 9 ) - 1 ;
if ( ! F_105 ( V_27 < V_181 ) )
goto V_44;
if ( ! F_105 ( V_180 < V_181 ) )
V_180 = V_181 - 1 ;
V_179 = F_106 ( V_181 - 1 ) ;
if ( V_145 == V_148 ) {
if ( F_37 ( V_180 < V_184 - 1 ) )
goto V_44;
if ( F_37 ( V_180 == ( V_181 - 1 ) ) )
V_172 = V_179 ;
else
V_172 = F_106 ( V_180 - ( V_184 - 1 ) ) ;
V_171 = F_106 ( V_27 + V_184 - 1 ) ;
} else {
V_171 = F_106 ( V_27 ) ;
V_172 = F_106 ( V_180 ) ;
}
V_143 = F_95 ( V_2 , V_171 , V_172 , V_145 ) ;
V_44:
F_62 ( V_2 ) ;
return V_143 ;
}
static
struct V_60 * F_107 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_62 * V_99 ;
struct V_60 * V_66 ;
int V_185 = 0 ;
unsigned long V_186 ;
F_40 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_153 > V_2 -> V_64 -> V_114 / 2 ) {
F_42 ( & V_2 -> V_72 ) ;
return NULL ;
}
V_99 = F_44 ( V_2 -> V_64 , V_61 ) ;
V_66 = V_99 ? F_38 ( V_99 , struct V_60 , V_67 ) : NULL ;
if ( V_66 ) {
if ( V_66 -> V_67 . V_83 != V_61 ) {
V_66 -> V_149 = F_85 ( V_2 , V_61 ) ;
V_66 -> V_150 = 0 ;
F_65 ( V_2 -> V_64 ) ;
V_185 = 1 ;
}
if ( V_66 -> V_67 . V_140 == 1 )
V_2 -> V_153 ++ ;
F_93 ( V_68 , & V_66 -> V_25 ) ;
}
V_186 = V_2 -> V_64 -> V_25 ;
F_42 ( & V_2 -> V_72 ) ;
if ( V_185 )
F_7 ( & V_2 -> V_74 ) ;
if ( ! V_66 ) {
if ( V_186 & V_187 )
F_83 ( V_2 , L_21
L_22 ) ;
F_31 ( V_186 & V_188 ) ;
}
return V_66 ;
}
static int F_108 ( struct V_1 * V_2 , unsigned int V_61 )
{
int V_139 ;
F_40 ( & V_2 -> V_72 ) ;
V_139 = F_109 ( V_2 -> V_75 , V_61 ) ;
F_42 ( & V_2 -> V_72 ) ;
return V_139 ;
}
int F_110 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_61 = F_111 ( V_27 ) ;
struct V_60 * V_66 ;
int V_77 , V_189 ;
bool V_190 ;
V_191:
V_189 = F_112 ( V_2 -> V_74 ,
( V_66 = F_107 ( V_2 , V_61 ) ) ) ;
if ( V_189 )
return - V_192 ;
if ( F_13 ( V_193 , & V_66 -> V_25 ) )
return 0 ;
V_190 = F_113 ( V_2 ) ;
for ( V_77 = 0 ; V_77 < V_65 ; V_77 ++ ) {
V_189 = F_112 ( V_2 -> V_74 ,
! F_108 ( V_2 , V_61 * V_65 + V_77 ) ||
( V_190 && F_13 ( V_73 , & V_66 -> V_25 ) ) ) ;
if ( V_189 || ( V_190 && F_13 ( V_73 , & V_66 -> V_25 ) ) ) {
F_40 ( & V_2 -> V_72 ) ;
if ( F_75 ( V_2 -> V_64 , & V_66 -> V_67 ) == 0 ) {
V_66 -> V_25 = 0 ;
V_2 -> V_153 -- ;
F_7 ( & V_2 -> V_74 ) ;
}
F_42 ( & V_2 -> V_72 ) ;
if ( V_189 )
return - V_192 ;
if ( F_114 ( V_22 / 10 ) )
return - V_192 ;
goto V_191;
}
}
F_93 ( V_193 , & V_66 -> V_25 ) ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_61 = F_111 ( V_27 ) ;
const unsigned int V_84 = V_61 * V_65 ;
struct V_62 * V_99 ;
struct V_60 * V_66 ;
int V_77 ;
bool V_194 = F_116 ( V_2 , V_27 , true ) ;
if ( V_194 && V_2 -> V_195 != V_61 )
return - V_196 ;
F_40 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_195 != V_111 && V_2 -> V_195 != V_61 ) {
V_99 = F_36 ( V_2 -> V_64 , V_2 -> V_195 ) ;
V_66 = V_99 ? F_38 ( V_99 , struct V_60 , V_67 ) : NULL ;
if ( V_66 ) {
F_29 ( V_2 , ! F_13 ( V_193 , & V_66 -> V_25 ) ) ;
F_29 ( V_2 , F_13 ( V_68 , & V_66 -> V_25 ) ) ;
F_117 ( V_68 , & V_66 -> V_25 ) ;
V_2 -> V_195 = V_111 ;
if ( F_75 ( V_2 -> V_64 , & V_66 -> V_67 ) == 0 ) {
V_66 -> V_25 = 0 ;
V_2 -> V_153 -- ;
}
F_7 ( & V_2 -> V_74 ) ;
} else {
F_34 ( V_2 , L_23 ) ;
}
}
V_99 = F_43 ( V_2 -> V_64 , V_61 ) ;
V_66 = V_99 ? F_38 ( V_99 , struct V_60 , V_67 ) : NULL ;
if ( V_66 ) {
if ( F_13 ( V_193 , & V_66 -> V_25 ) )
goto V_197;
if ( ! F_41 ( V_68 , & V_66 -> V_25 ) ) {
V_2 -> V_153 ++ ;
} else {
V_66 -> V_67 . V_140 -- ;
F_29 ( V_2 , V_66 -> V_67 . V_140 > 0 ) ;
}
goto V_198;
} else {
if ( V_2 -> V_153 > V_2 -> V_64 -> V_114 - 3 )
goto V_199;
V_99 = F_44 ( V_2 -> V_64 , V_61 ) ;
V_66 = V_99 ? F_38 ( V_99 , struct V_60 , V_67 ) : NULL ;
if ( ! V_66 ) {
const unsigned long V_186 = V_2 -> V_64 -> V_25 ;
if ( V_186 & V_187 )
F_83 ( V_2 , L_21
L_22 ) ;
F_31 ( V_186 & V_188 ) ;
goto V_199;
}
if ( V_66 -> V_67 . V_83 != V_61 ) {
V_66 -> V_149 = F_85 ( V_2 , V_61 ) ;
V_66 -> V_150 = 0 ;
F_65 ( V_2 -> V_64 ) ;
F_7 ( & V_2 -> V_74 ) ;
F_29 ( V_2 , F_13 ( V_193 , & V_66 -> V_25 ) == 0 ) ;
}
F_93 ( V_68 , & V_66 -> V_25 ) ;
F_29 ( V_2 , V_66 -> V_67 . V_140 == 1 ) ;
V_2 -> V_153 ++ ;
goto V_198;
}
V_198:
for ( V_77 = 0 ; V_77 < V_65 ; V_77 ++ ) {
if ( F_109 ( V_2 -> V_75 , V_84 + V_77 ) )
goto V_199;
}
F_93 ( V_193 , & V_66 -> V_25 ) ;
V_197:
V_2 -> V_195 = V_111 ;
F_42 ( & V_2 -> V_72 ) ;
return 0 ;
V_199:
if ( V_66 ) {
if ( V_194 ) {
F_29 ( V_2 , ! F_13 ( V_193 , & V_66 -> V_25 ) ) ;
F_29 ( V_2 , F_13 ( V_68 , & V_66 -> V_25 ) ) ;
F_117 ( V_68 , & V_66 -> V_25 ) ;
V_2 -> V_195 = V_111 ;
if ( F_75 ( V_2 -> V_64 , & V_66 -> V_67 ) == 0 ) {
V_66 -> V_25 = 0 ;
V_2 -> V_153 -- ;
}
F_7 ( & V_2 -> V_74 ) ;
} else
V_2 -> V_195 = V_61 ;
}
F_42 ( & V_2 -> V_72 ) ;
return - V_196 ;
}
void F_118 ( struct V_1 * V_2 , T_1 V_27 )
{
unsigned int V_61 = F_111 ( V_27 ) ;
struct V_62 * V_99 ;
struct V_60 * V_66 ;
unsigned long V_25 ;
F_74 ( & V_2 -> V_72 , V_25 ) ;
V_99 = F_36 ( V_2 -> V_64 , V_61 ) ;
V_66 = V_99 ? F_38 ( V_99 , struct V_60 , V_67 ) : NULL ;
if ( ! V_66 ) {
F_76 ( & V_2 -> V_72 , V_25 ) ;
if ( F_119 ( & V_200 ) )
F_14 ( V_2 , L_24 ) ;
return;
}
if ( V_66 -> V_67 . V_140 == 0 ) {
F_76 ( & V_2 -> V_72 , V_25 ) ;
F_14 ( V_2 , L_25
L_26 ,
( unsigned long long ) V_27 , V_61 ) ;
return;
}
if ( F_75 ( V_2 -> V_64 , & V_66 -> V_67 ) == 0 ) {
V_66 -> V_25 = 0 ;
V_2 -> V_153 -- ;
F_7 ( & V_2 -> V_74 ) ;
}
F_76 ( & V_2 -> V_72 , V_25 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_72 ) ;
if ( F_21 ( V_2 , V_10 ) ) {
F_121 ( V_2 -> V_64 ) ;
F_62 ( V_2 ) ;
}
V_2 -> V_153 = 0 ;
V_2 -> V_195 = V_111 ;
F_42 ( & V_2 -> V_72 ) ;
F_7 ( & V_2 -> V_74 ) ;
}
int F_122 ( struct V_1 * V_2 )
{
struct V_62 * V_99 ;
struct V_60 * V_66 ;
int V_77 ;
F_40 ( & V_2 -> V_72 ) ;
if ( F_21 ( V_2 , V_10 ) ) {
for ( V_77 = 0 ; V_77 < V_2 -> V_64 -> V_114 ; V_77 ++ ) {
V_99 = F_56 ( V_2 -> V_64 , V_77 ) ;
V_66 = F_38 ( V_99 , struct V_60 , V_67 ) ;
if ( V_66 -> V_67 . V_83 == V_111 )
continue;
if ( V_66 -> V_67 . V_83 == V_2 -> V_195 ) {
F_72 ( V_2 , L_27
L_28 ,
V_2 -> V_195 ) ;
F_29 ( V_2 , ! F_13 ( V_193 , & V_66 -> V_25 ) ) ;
F_29 ( V_2 , F_13 ( V_68 , & V_66 -> V_25 ) ) ;
F_117 ( V_68 , & V_66 -> V_25 ) ;
V_2 -> V_195 = V_111 ;
F_75 ( V_2 -> V_64 , & V_66 -> V_67 ) ;
}
if ( V_66 -> V_67 . V_140 != 0 ) {
F_72 ( V_2 , L_29
L_30 , V_66 -> V_67 . V_140 ) ;
F_62 ( V_2 ) ;
F_42 ( & V_2 -> V_72 ) ;
return - V_196 ;
}
F_29 ( V_2 , ! F_13 ( V_193 , & V_66 -> V_25 ) ) ;
F_29 ( V_2 , ! F_13 ( V_68 , & V_66 -> V_25 ) ) ;
F_79 ( V_2 -> V_64 , & V_66 -> V_67 ) ;
}
F_29 ( V_2 , V_2 -> V_64 -> V_132 == 0 ) ;
F_62 ( V_2 ) ;
}
F_42 ( & V_2 -> V_72 ) ;
F_7 ( & V_2 -> V_74 ) ;
return 0 ;
}
