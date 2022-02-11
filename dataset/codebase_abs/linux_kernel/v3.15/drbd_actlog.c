void * F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 -> V_4 ,
( V_3 = F_3 ( & V_2 -> V_5 , 0 , 1 ) ) == 0 ||
V_2 -> V_6 . V_7 <= V_8 ) ;
return V_3 ? NULL : F_4 ( V_2 -> V_9 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( & V_2 -> V_5 ) )
F_7 ( & V_2 -> V_4 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int * V_12 )
{
long V_13 ;
F_9 () ;
V_13 = F_10 ( V_11 -> V_14 ) -> V_15 ;
F_11 () ;
V_13 = V_13 * V_16 / 10 ;
if ( V_13 == 0 )
V_13 = V_17 ;
V_13 = F_12 ( V_2 -> V_4 ,
* V_12 || F_13 ( V_18 , & V_2 -> V_19 ) , V_13 ) ;
if ( V_13 == 0 ) {
F_14 ( V_2 , L_1 ) ;
F_15 ( V_2 , 1 , V_20 ) ;
}
}
static int F_16 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_21 * V_21 , T_1 V_22 ,
int V_23 , int V_24 )
{
struct V_25 * V_25 ;
int V_26 ;
V_2 -> V_27 . V_12 = 0 ;
V_2 -> V_27 . error = - V_28 ;
if ( ( V_23 & V_29 ) && ! F_13 ( V_30 , & V_2 -> V_19 ) )
V_23 |= V_31 | V_32 ;
V_23 |= V_33 ;
V_25 = F_17 ( V_34 ) ;
V_25 -> V_35 = V_11 -> V_36 ;
V_25 -> V_37 . V_38 = V_22 ;
V_26 = - V_39 ;
if ( F_18 ( V_25 , V_21 , V_24 , 0 ) != V_24 )
goto V_40;
V_25 -> V_41 = & V_2 -> V_27 ;
V_25 -> V_42 = V_43 ;
V_25 -> V_44 = V_23 ;
if ( ! ( V_23 & V_29 ) && V_2 -> V_6 . V_7 == V_45 && V_2 -> V_46 == NULL )
;
else if ( ! F_19 ( V_2 , V_47 ) ) {
F_14 ( V_2 , L_2 ) ;
V_26 = - V_28 ;
goto V_40;
}
F_20 ( V_25 ) ;
F_21 ( & V_2 -> V_5 ) ;
if ( F_22 ( V_2 , ( V_23 & V_29 ) ? V_48 : V_49 ) )
F_23 ( V_25 , - V_39 ) ;
else
F_24 ( V_23 , V_25 ) ;
F_8 ( V_2 , V_11 , & V_2 -> V_27 . V_12 ) ;
if ( F_25 ( V_25 , V_50 ) )
V_26 = V_2 -> V_27 . error ;
V_40:
F_26 ( V_25 ) ;
return V_26 ;
}
int F_27 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_1 V_22 , int V_23 )
{
int V_26 ;
struct V_21 * V_51 = V_2 -> V_9 ;
F_28 ( V_2 , F_29 ( & V_2 -> V_5 ) == 1 ) ;
F_30 ( ! V_11 -> V_36 ) ;
F_31 ( V_2 , L_3 ,
V_52 -> V_53 , V_52 -> V_54 , V_55 ,
( unsigned long long ) V_22 , ( V_23 & V_29 ) ? L_4 : L_5 ,
( void * ) V_56 ) ;
if ( V_22 < V_57 ( V_11 ) ||
V_22 + 7 > F_32 ( V_11 ) )
F_33 ( V_2 , L_6 ,
V_52 -> V_53 , V_52 -> V_54 , V_55 ,
( unsigned long long ) V_22 , ( V_23 & V_29 ) ? L_4 : L_5 ) ;
V_26 = F_16 ( V_2 , V_11 , V_51 , V_22 , V_23 , 4096 ) ;
if ( V_26 ) {
F_14 ( V_2 , L_7 ,
( unsigned long long ) V_22 , ( V_23 & V_29 ) ? L_4 : L_5 , V_26 ) ;
}
return V_26 ;
}
static struct V_58 * F_34 ( struct V_1 * V_2 , unsigned int V_59 )
{
struct V_60 * V_61 ;
V_61 = F_35 ( V_2 -> V_62 , V_59 / V_63 ) ;
if ( F_36 ( V_61 != NULL ) ) {
struct V_58 * V_64 = F_37 ( V_61 , struct V_58 , V_65 ) ;
if ( F_13 ( V_66 , & V_64 -> V_19 ) )
return V_64 ;
}
return NULL ;
}
static struct V_60 * F_38 ( struct V_1 * V_2 , unsigned int V_59 , bool V_67 )
{
struct V_60 * V_68 ;
struct V_58 * V_64 ;
int V_69 ;
F_39 ( & V_2 -> V_70 ) ;
V_64 = F_34 ( V_2 , V_59 ) ;
if ( V_64 ) {
V_69 = ! F_40 ( V_71 , & V_64 -> V_19 ) ;
F_41 ( & V_2 -> V_70 ) ;
if ( V_69 )
F_7 ( & V_2 -> V_72 ) ;
return NULL ;
}
if ( V_67 )
V_68 = F_42 ( V_2 -> V_73 , V_59 ) ;
else
V_68 = F_43 ( V_2 -> V_73 , V_59 ) ;
F_41 ( & V_2 -> V_70 ) ;
return V_68 ;
}
bool F_44 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
unsigned V_76 = V_75 -> V_22 >> ( V_77 - 9 ) ;
unsigned V_78 = V_75 -> V_24 == 0 ? V_76 : ( V_75 -> V_22 + ( V_75 -> V_24 >> 9 ) - 1 ) >> ( V_77 - 9 ) ;
F_28 ( V_2 , ( unsigned ) ( V_78 - V_76 ) <= 1 ) ;
F_28 ( V_2 , F_29 ( & V_2 -> V_79 ) > 0 ) ;
if ( V_76 != V_78 )
return false ;
return F_38 ( V_2 , V_76 , true ) ;
}
static
bool F_45 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
unsigned V_76 = V_75 -> V_22 >> ( V_77 - 9 ) ;
unsigned V_78 = V_75 -> V_24 == 0 ? V_76 : ( V_75 -> V_22 + ( V_75 -> V_24 >> 9 ) - 1 ) >> ( V_77 - 9 ) ;
unsigned V_59 ;
bool V_80 = false ;
F_28 ( V_2 , V_76 <= V_78 ) ;
F_28 ( V_2 , F_29 ( & V_2 -> V_79 ) > 0 ) ;
for ( V_59 = V_76 ; V_59 <= V_78 ; V_59 ++ ) {
struct V_60 * V_68 ;
F_2 ( V_2 -> V_72 ,
( V_68 = F_38 ( V_2 , V_59 , false ) ) != NULL ) ;
if ( V_68 -> V_81 != V_59 )
V_80 = true ;
}
return V_80 ;
}
void F_46 ( struct V_1 * V_2 , bool V_82 )
{
bool V_83 = false ;
F_30 ( V_82 && V_52 == F_47 ( V_2 ) -> V_84 -> V_85 . V_86 ) ;
F_2 ( V_2 -> V_72 ,
V_2 -> V_73 -> V_87 == 0 ||
( V_83 = F_48 ( V_2 -> V_73 ) ) ) ;
if ( V_83 ) {
if ( V_2 -> V_73 -> V_87 ) {
bool V_88 ;
F_9 () ;
V_88 = F_10 ( V_2 -> V_46 -> V_14 ) -> V_89 ;
F_11 () ;
if ( V_88 )
F_49 ( V_2 , V_82 ) ;
F_39 ( & V_2 -> V_70 ) ;
F_50 ( V_2 -> V_73 ) ;
F_41 ( & V_2 -> V_70 ) ;
}
F_51 ( V_2 -> V_73 ) ;
F_7 ( & V_2 -> V_72 ) ;
}
}
void F_52 ( struct V_1 * V_2 , struct V_74 * V_75 , bool V_82 )
{
F_30 ( V_82 && V_52 == F_47 ( V_2 ) -> V_84 -> V_85 . V_86 ) ;
if ( F_45 ( V_2 , V_75 ) )
F_46 ( V_2 , V_82 ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
struct V_90 * V_91 = V_2 -> V_73 ;
unsigned V_76 = V_75 -> V_22 >> ( V_77 - 9 ) ;
unsigned V_78 = V_75 -> V_24 == 0 ? V_76 : ( V_75 -> V_22 + ( V_75 -> V_24 >> 9 ) - 1 ) >> ( V_77 - 9 ) ;
unsigned V_92 ;
unsigned V_93 ;
unsigned V_59 ;
F_28 ( V_2 , V_76 <= V_78 ) ;
V_92 = 1 + V_78 - V_76 ;
V_93 = F_54 ( V_91 -> V_94 - V_91 -> V_95 ,
V_91 -> V_96 - V_91 -> V_87 ) ;
if ( V_93 < V_92 )
return - V_97 ;
for ( V_59 = V_76 ; V_59 <= V_78 ; V_59 ++ ) {
struct V_60 * V_61 ;
V_61 = F_35 ( V_2 -> V_62 , V_59 / V_63 ) ;
if ( F_36 ( V_61 != NULL ) ) {
struct V_58 * V_64 = F_37 ( V_61 , struct V_58 , V_65 ) ;
if ( F_13 ( V_66 , & V_64 -> V_19 ) ) {
if ( ! F_40 ( V_71 , & V_64 -> V_19 ) )
return - V_98 ;
return - V_97 ;
}
}
}
for ( V_59 = V_76 ; V_59 <= V_78 ; V_59 ++ ) {
struct V_60 * V_68 ;
V_68 = F_55 ( V_2 -> V_73 , V_59 ) ;
if ( ! V_68 )
F_56 ( V_2 , L_8 , V_59 ) ;
}
return 0 ;
}
void F_57 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
unsigned V_76 = V_75 -> V_22 >> ( V_77 - 9 ) ;
unsigned V_78 = V_75 -> V_24 == 0 ? V_76 : ( V_75 -> V_22 + ( V_75 -> V_24 >> 9 ) - 1 ) >> ( V_77 - 9 ) ;
unsigned V_59 ;
struct V_60 * V_99 ;
unsigned long V_19 ;
F_28 ( V_2 , V_76 <= V_78 ) ;
F_58 ( & V_2 -> V_70 , V_19 ) ;
for ( V_59 = V_76 ; V_59 <= V_78 ; V_59 ++ ) {
V_99 = F_35 ( V_2 -> V_73 , V_59 ) ;
if ( ! V_99 ) {
F_14 ( V_2 , L_9 , V_59 ) ;
continue;
}
F_59 ( V_2 -> V_73 , V_99 ) ;
}
F_60 ( & V_2 -> V_70 , V_19 ) ;
F_7 ( & V_2 -> V_72 ) ;
}
static unsigned int F_61 ( unsigned int V_100 )
{
return V_100 >>
( ( V_101 + 3 ) -
( V_77 - V_102 ) ) ;
}
static unsigned int F_62 ( unsigned int V_103 )
{
return V_103 >>
( ( V_101 + 3 ) -
( V_104 - V_102 ) ) ;
}
static T_1 F_63 ( struct V_1 * V_2 )
{
const unsigned int V_105 = V_2 -> V_46 -> V_106 . V_107 ;
const unsigned int V_108 = V_2 -> V_46 -> V_106 . V_109 ;
unsigned int V_110 = V_2 -> V_111 % ( V_2 -> V_46 -> V_106 . V_112 ) ;
V_110 = ( ( V_110 % V_105 ) * V_108 ) + V_110 / V_105 ;
V_110 *= 8 ;
return V_2 -> V_46 -> V_106 . V_113 + V_2 -> V_46 -> V_106 . V_114 + V_110 ;
}
static int
F_64 ( struct V_1 * V_2 )
{
struct V_115 * V_116 ;
struct V_60 * V_117 ;
T_1 V_22 ;
int V_75 , V_118 ;
unsigned V_119 ;
unsigned V_120 = 0 ;
int V_26 = 0 ;
if ( ! F_65 ( V_2 ) ) {
F_14 ( V_2 , L_10 ,
F_66 ( V_2 -> V_6 . V_7 ) ) ;
return - V_39 ;
}
if ( V_2 -> V_6 . V_7 < V_121 ) {
F_14 ( V_2 ,
L_11 ,
F_66 ( V_2 -> V_6 . V_7 ) ) ;
F_67 ( V_2 ) ;
return - V_39 ;
}
V_116 = F_1 ( V_2 ) ;
if ( ! V_116 ) {
F_14 ( V_2 , L_12 ) ;
F_67 ( V_2 ) ;
return - V_28 ;
}
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_122 = F_68 ( V_123 ) ;
V_116 -> V_124 = F_68 ( V_2 -> V_111 ) ;
V_75 = 0 ;
F_39 ( & V_2 -> V_70 ) ;
F_69 (e, &device->act_log->to_be_changed, list) {
if ( V_75 == V_125 ) {
V_75 ++ ;
break;
}
V_116 -> V_126 [ V_75 ] = F_70 ( V_117 -> V_127 ) ;
V_116 -> V_128 [ V_75 ] = F_68 ( V_117 -> V_129 ) ;
if ( V_117 -> V_81 != V_130 )
F_71 ( V_2 ,
F_61 ( V_117 -> V_81 ) ) ;
V_75 ++ ;
}
F_41 ( & V_2 -> V_70 ) ;
F_30 ( V_75 > V_125 ) ;
V_116 -> V_131 = F_70 ( V_75 ) ;
for ( ; V_75 < V_125 ; V_75 ++ ) {
V_116 -> V_126 [ V_75 ] = F_70 ( - 1 ) ;
V_116 -> V_128 [ V_75 ] = F_68 ( V_130 ) ;
}
V_116 -> V_132 = F_70 ( V_2 -> V_73 -> V_94 ) ;
V_116 -> V_133 = F_70 ( V_2 -> V_134 ) ;
V_118 = F_72 ( int , V_135 ,
V_2 -> V_73 -> V_94 - V_2 -> V_134 ) ;
for ( V_75 = 0 ; V_75 < V_118 ; V_75 ++ ) {
unsigned V_136 = V_2 -> V_134 + V_75 ;
V_119 = F_73 ( V_2 -> V_73 , V_136 ) -> V_81 ;
V_116 -> V_137 [ V_75 ] = F_68 ( V_119 ) ;
}
for (; V_75 < V_135 ; V_75 ++ )
V_116 -> V_137 [ V_75 ] = F_68 ( V_130 ) ;
V_2 -> V_134 += V_135 ;
if ( V_2 -> V_134 >= V_2 -> V_73 -> V_94 )
V_2 -> V_134 = 0 ;
V_22 = F_63 ( V_2 ) ;
V_120 = F_74 ( 0 , V_116 , 4096 ) ;
V_116 -> F_74 = F_68 ( V_120 ) ;
if ( F_75 ( V_2 ) )
V_26 = - V_39 ;
else {
bool V_88 ;
F_9 () ;
V_88 = F_10 ( V_2 -> V_46 -> V_14 ) -> V_89 ;
F_11 () ;
if ( V_88 ) {
if ( F_27 ( V_2 , V_2 -> V_46 , V_22 , V_29 ) ) {
V_26 = - V_39 ;
F_15 ( V_2 , 1 , V_138 ) ;
} else {
V_2 -> V_111 ++ ;
V_2 -> V_139 ++ ;
}
}
}
F_5 ( V_2 ) ;
F_67 ( V_2 ) ;
return V_26 ;
}
static int F_76 ( struct V_140 * V_141 , int V_142 )
{
struct V_143 * V_144 = F_77 ( V_141 , struct V_143 , V_141 ) ;
struct V_1 * V_2 = V_144 -> V_2 ;
int V_26 ;
V_26 = F_64 ( V_2 ) ;
V_144 -> V_26 = V_26 ;
F_78 ( & V_144 -> V_145 ) ;
return V_26 != - V_39 ? V_26 : 0 ;
}
static int F_49 ( struct V_1 * V_2 , bool V_82 )
{
if ( V_82 ) {
struct V_143 V_146 ;
F_79 ( & V_146 . V_145 ) ;
V_146 . V_141 . V_147 = F_76 ;
V_146 . V_2 = V_2 ;
F_80 ( & F_47 ( V_2 ) -> V_84 -> V_148 ,
& V_146 . V_141 ) ;
F_81 ( & V_146 . V_145 ) ;
return V_146 . V_26 ;
} else
return F_64 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_60 * V_68 )
{
int V_149 ;
F_39 ( & V_2 -> V_70 ) ;
V_149 = ( V_68 -> V_150 == 0 ) ;
if ( F_83 ( V_149 ) )
F_84 ( V_2 -> V_73 , V_68 ) ;
F_41 ( & V_2 -> V_70 ) ;
return V_149 ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_60 * V_68 ;
int V_75 ;
F_28 ( V_2 , F_13 ( V_151 , & V_2 -> V_73 -> V_19 ) ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_73 -> V_94 ; V_75 ++ ) {
V_68 = F_73 ( V_2 -> V_73 , V_75 ) ;
if ( V_68 -> V_81 == V_130 )
continue;
F_2 ( V_2 -> V_72 , F_82 ( V_2 , V_68 ) ) ;
}
F_7 ( & V_2 -> V_72 ) ;
}
int F_86 ( struct V_1 * V_2 , void * V_116 )
{
struct V_115 * V_91 = V_116 ;
struct V_152 * V_106 = & V_2 -> V_46 -> V_106 ;
T_1 V_153 = V_106 -> V_113 + V_106 -> V_114 ;
int V_112 = V_106 -> V_107 * V_106 -> V_109 ;
int V_75 ;
memset ( V_91 , 0 , 4096 ) ;
V_91 -> V_122 = F_68 ( V_123 ) ;
V_91 -> V_154 = F_70 ( V_155 ) ;
V_91 -> F_74 = F_68 ( F_74 ( 0 , V_91 , 4096 ) ) ;
for ( V_75 = 0 ; V_75 < V_112 ; V_75 ++ ) {
int V_26 = F_27 ( V_2 , V_2 -> V_46 , V_153 + V_75 * 8 , V_29 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_87 ( struct V_140 * V_141 , int V_142 )
{
struct V_156 * V_157 = F_77 ( V_141 , struct V_156 , V_141 ) ;
struct V_1 * V_2 = V_157 -> V_2 ;
struct V_158 V_159 = { . V_160 = V_161 , } ;
if ( ! F_65 ( V_2 ) ) {
if ( F_88 ( & V_162 ) )
F_89 ( V_2 , L_13 ) ;
F_90 ( V_157 ) ;
return 0 ;
}
F_91 ( V_2 , F_62 ( V_157 -> V_59 ) ) ;
F_67 ( V_2 ) ;
F_90 ( V_157 ) ;
if ( F_92 ( V_2 ) <= V_2 -> V_163 ) {
switch ( V_2 -> V_6 . V_164 ) {
case V_165 : case V_166 :
case V_167 : case V_168 :
F_93 ( V_2 ) ;
default:
break;
}
}
F_94 ( V_2 , & V_159 ) ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 , T_1 V_22 ,
int V_169 , int V_170 )
{
struct V_60 * V_117 ;
struct V_156 * V_157 ;
unsigned int V_59 ;
F_28 ( V_2 , F_29 ( & V_2 -> V_79 ) ) ;
V_59 = F_96 ( V_22 ) ;
V_117 = F_43 ( V_2 -> V_62 , V_59 ) ;
if ( V_117 ) {
struct V_58 * V_171 = F_37 ( V_117 , struct V_58 , V_65 ) ;
if ( V_171 -> V_65 . V_81 == V_59 ) {
if ( V_170 )
V_171 -> V_172 -= V_169 ;
else
V_171 -> V_163 += V_169 ;
if ( V_171 -> V_172 < V_171 -> V_163 ) {
F_89 ( V_2 , L_14
L_15 ,
( unsigned long long ) V_22 ,
V_171 -> V_65 . V_81 , V_171 -> V_172 ,
V_171 -> V_163 , V_169 ,
F_97 ( V_2 -> V_6 . V_164 ) ) ;
V_171 -> V_172 = F_98 ( V_2 , V_59 ) ;
}
} else {
int V_172 = F_98 ( V_2 , V_59 ) ;
if ( V_171 -> V_19 != 0 ) {
F_89 ( V_2 , L_16
L_17 ,
V_171 -> V_65 . V_81 , V_171 -> V_172 ,
V_171 -> V_19 , V_59 , V_172 ) ;
V_171 -> V_19 = 0 ;
}
if ( V_171 -> V_163 ) {
F_89 ( V_2 , L_18
L_19 ,
V_171 -> V_65 . V_81 , V_171 -> V_163 ) ;
}
V_171 -> V_172 = V_172 ;
V_171 -> V_163 = V_170 ? 0 : V_169 ;
F_50 ( V_2 -> V_62 ) ;
}
F_59 ( V_2 -> V_62 , & V_171 -> V_65 ) ;
if ( V_171 -> V_172 == V_171 -> V_163 ) {
V_171 -> V_163 = 0 ;
V_157 = F_99 ( sizeof( * V_157 ) , V_173 ) ;
if ( V_157 ) {
V_157 -> V_59 = V_171 -> V_65 . V_81 ;
V_157 -> V_141 . V_147 = F_87 ;
V_157 -> V_2 = V_2 ;
F_80 ( & F_47 ( V_2 ) -> V_84 -> V_148 ,
& V_157 -> V_141 ) ;
} else {
F_89 ( V_2 , L_20 ) ;
}
}
} else {
F_14 ( V_2 , L_21 ,
V_2 -> V_174 ,
V_2 -> V_62 -> V_94 ,
V_2 -> V_62 -> V_19 ) ;
}
}
void F_100 ( struct V_1 * V_2 , unsigned long V_175 )
{
unsigned long V_176 = V_177 ;
unsigned long V_78 = V_2 -> V_178 [ V_2 -> V_179 ] ;
int V_180 = ( V_2 -> V_179 + 1 ) % V_181 ;
if ( F_101 ( V_176 , V_78 + V_182 ) ) {
if ( V_2 -> V_183 [ V_2 -> V_179 ] != V_175 &&
V_2 -> V_6 . V_164 != V_168 &&
V_2 -> V_6 . V_164 != V_167 ) {
V_2 -> V_178 [ V_180 ] = V_176 ;
V_2 -> V_183 [ V_180 ] = V_175 ;
V_2 -> V_179 = V_180 ;
}
}
}
void F_102 ( struct V_1 * V_2 , T_1 V_22 , int V_24 ,
const char * V_184 , const unsigned int line )
{
unsigned long V_185 , V_186 , V_187 ;
unsigned long V_169 = 0 ;
T_1 V_188 , V_189 ;
int F_7 = 0 ;
unsigned long V_19 ;
if ( V_24 <= 0 || ! F_103 ( V_24 , 512 ) || V_24 > V_190 ) {
F_14 ( V_2 , L_22 ,
( unsigned long long ) V_22 , V_24 ) ;
return;
}
if ( ! F_65 ( V_2 ) )
return;
V_189 = F_104 ( V_2 -> V_191 ) ;
V_188 = V_22 + ( V_24 >> 9 ) - 1 ;
if ( ! F_105 ( V_22 < V_189 ) )
goto V_40;
if ( ! F_105 ( V_188 < V_189 ) )
V_188 = V_189 - 1 ;
V_187 = F_106 ( V_189 - 1 ) ;
if ( F_36 ( V_188 < V_192 - 1 ) )
goto V_40;
if ( F_36 ( V_188 == ( V_189 - 1 ) ) )
V_186 = V_187 ;
else
V_186 = F_106 ( V_188 - ( V_192 - 1 ) ) ;
V_185 = F_106 ( V_22 + V_192 - 1 ) ;
if ( V_185 > V_186 )
goto V_40;
V_169 = F_107 ( V_2 , V_185 , V_186 ) ;
if ( V_169 ) {
F_100 ( V_2 , F_92 ( V_2 ) ) ;
F_58 ( & V_2 -> V_70 , V_19 ) ;
F_95 ( V_2 , V_22 , V_169 , true ) ;
F_60 ( & V_2 -> V_70 , V_19 ) ;
F_7 = 1 ;
}
V_40:
F_67 ( V_2 ) ;
if ( F_7 )
F_7 ( & V_2 -> V_72 ) ;
}
int F_108 ( struct V_1 * V_2 , T_1 V_22 , int V_24 ,
const char * V_184 , const unsigned int line )
{
unsigned long V_185 , V_186 , V_19 ;
T_1 V_188 , V_189 ;
unsigned int V_59 , V_169 = 0 ;
struct V_60 * V_117 ;
if ( V_24 == 0 )
return 0 ;
if ( V_24 < 0 || ! F_103 ( V_24, 512 ) || V_24 > V_190 ) {
F_14 ( V_2 , L_23 ,
( unsigned long long ) V_22 , V_24 ) ;
return 0 ;
}
if ( ! F_65 ( V_2 ) )
return 0 ;
V_189 = F_104 ( V_2 -> V_191 ) ;
V_188 = V_22 + ( V_24 >> 9 ) - 1 ;
if ( ! F_105 ( V_22 < V_189 ) )
goto V_40;
if ( ! F_105 ( V_188 < V_189 ) )
V_188 = V_189 - 1 ;
V_185 = F_106 ( V_22 ) ;
V_186 = F_106 ( V_188 ) ;
F_58 ( & V_2 -> V_70 , V_19 ) ;
V_169 = F_109 ( V_2 , V_185 , V_186 ) ;
V_59 = F_96 ( V_22 ) ;
V_117 = F_35 ( V_2 -> V_62 , V_59 ) ;
if ( V_117 )
F_37 ( V_117 , struct V_58 , V_65 ) -> V_172 += V_169 ;
F_60 ( & V_2 -> V_70 , V_19 ) ;
V_40:
F_67 ( V_2 ) ;
return V_169 ;
}
static
struct V_58 * F_110 ( struct V_1 * V_2 , unsigned int V_59 )
{
struct V_60 * V_117 ;
struct V_58 * V_64 ;
int V_193 = 0 ;
unsigned long V_194 ;
F_39 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_174 > V_2 -> V_62 -> V_94 / 2 ) {
F_41 ( & V_2 -> V_70 ) ;
return NULL ;
}
V_117 = F_43 ( V_2 -> V_62 , V_59 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( V_64 ) {
if ( V_64 -> V_65 . V_81 != V_59 ) {
V_64 -> V_172 = F_98 ( V_2 , V_59 ) ;
V_64 -> V_163 = 0 ;
F_50 ( V_2 -> V_62 ) ;
V_193 = 1 ;
}
if ( V_64 -> V_65 . V_150 == 1 )
V_2 -> V_174 ++ ;
F_111 ( V_66 , & V_64 -> V_19 ) ;
}
V_194 = V_2 -> V_62 -> V_19 ;
F_41 ( & V_2 -> V_70 ) ;
if ( V_193 )
F_7 ( & V_2 -> V_72 ) ;
if ( ! V_64 ) {
if ( V_194 & V_195 )
F_89 ( V_2 , L_24
L_25 ) ;
F_30 ( V_194 & V_196 ) ;
}
return V_64 ;
}
static int F_112 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_149 ;
F_39 ( & V_2 -> V_70 ) ;
V_149 = F_113 ( V_2 -> V_73 , V_59 ) ;
F_41 ( & V_2 -> V_70 ) ;
return V_149 ;
}
int F_114 ( struct V_1 * V_2 , T_1 V_22 )
{
unsigned int V_59 = F_96 ( V_22 ) ;
struct V_58 * V_64 ;
int V_75 , V_197 ;
int V_198 = 200 ;
V_199:
V_197 = F_115 ( V_2 -> V_72 ,
( V_64 = F_110 ( V_2 , V_59 ) ) ) ;
if ( V_197 )
return - V_200 ;
if ( F_13 ( V_201 , & V_64 -> V_19 ) )
return 0 ;
for ( V_75 = 0 ; V_75 < V_63 ; V_75 ++ ) {
V_197 = F_115 ( V_2 -> V_72 ,
! F_112 ( V_2 , V_59 * V_63 + V_75 ) ||
F_13 ( V_71 , & V_64 -> V_19 ) ) ;
if ( V_197 || ( F_13 ( V_71 , & V_64 -> V_19 ) && V_198 ) ) {
F_39 ( & V_2 -> V_70 ) ;
if ( F_59 ( V_2 -> V_62 , & V_64 -> V_65 ) == 0 ) {
V_64 -> V_19 = 0 ;
V_2 -> V_174 -- ;
F_7 ( & V_2 -> V_72 ) ;
}
F_41 ( & V_2 -> V_70 ) ;
if ( V_197 )
return - V_200 ;
if ( F_116 ( V_16 / 10 ) )
return - V_200 ;
if ( V_198 && -- V_198 == 0 )
F_89 ( V_2 , L_26
L_27 ) ;
goto V_199;
}
}
F_111 ( V_201 , & V_64 -> V_19 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 , T_1 V_22 )
{
unsigned int V_59 = F_96 ( V_22 ) ;
const unsigned int V_100 = V_59 * V_63 ;
struct V_60 * V_117 ;
struct V_58 * V_64 ;
int V_75 ;
F_39 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_202 != V_130 && V_2 -> V_202 != V_59 ) {
V_117 = F_35 ( V_2 -> V_62 , V_2 -> V_202 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( V_64 ) {
F_28 ( V_2 , ! F_13 ( V_201 , & V_64 -> V_19 ) ) ;
F_28 ( V_2 , F_13 ( V_66 , & V_64 -> V_19 ) ) ;
F_118 ( V_66 , & V_64 -> V_19 ) ;
V_2 -> V_202 = V_130 ;
if ( F_59 ( V_2 -> V_62 , & V_64 -> V_65 ) == 0 )
V_2 -> V_174 -- ;
F_7 ( & V_2 -> V_72 ) ;
} else {
F_33 ( V_2 , L_28 ) ;
}
}
V_117 = F_42 ( V_2 -> V_62 , V_59 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( V_64 ) {
if ( F_13 ( V_201 , & V_64 -> V_19 ) )
goto V_203;
if ( ! F_40 ( V_66 , & V_64 -> V_19 ) ) {
V_2 -> V_174 ++ ;
} else {
V_64 -> V_65 . V_150 -- ;
F_28 ( V_2 , V_64 -> V_65 . V_150 > 0 ) ;
}
goto V_204;
} else {
if ( V_2 -> V_174 > V_2 -> V_62 -> V_94 - 3 )
goto V_205;
V_117 = F_43 ( V_2 -> V_62 , V_59 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( ! V_64 ) {
const unsigned long V_194 = V_2 -> V_62 -> V_19 ;
if ( V_194 & V_195 )
F_89 ( V_2 , L_24
L_25 ) ;
F_30 ( V_194 & V_196 ) ;
goto V_205;
}
if ( V_64 -> V_65 . V_81 != V_59 ) {
V_64 -> V_172 = F_98 ( V_2 , V_59 ) ;
V_64 -> V_163 = 0 ;
F_50 ( V_2 -> V_62 ) ;
F_7 ( & V_2 -> V_72 ) ;
F_28 ( V_2 , F_13 ( V_201 , & V_64 -> V_19 ) == 0 ) ;
}
F_111 ( V_66 , & V_64 -> V_19 ) ;
F_28 ( V_2 , V_64 -> V_65 . V_150 == 1 ) ;
V_2 -> V_174 ++ ;
goto V_204;
}
V_204:
for ( V_75 = 0 ; V_75 < V_63 ; V_75 ++ ) {
if ( F_113 ( V_2 -> V_73 , V_100 + V_75 ) )
goto V_205;
}
F_111 ( V_201 , & V_64 -> V_19 ) ;
V_203:
V_2 -> V_202 = V_130 ;
F_41 ( & V_2 -> V_70 ) ;
return 0 ;
V_205:
if ( V_64 )
V_2 -> V_202 = V_59 ;
F_41 ( & V_2 -> V_70 ) ;
return - V_206 ;
}
void F_119 ( struct V_1 * V_2 , T_1 V_22 )
{
unsigned int V_59 = F_96 ( V_22 ) ;
struct V_60 * V_117 ;
struct V_58 * V_64 ;
unsigned long V_19 ;
F_58 ( & V_2 -> V_70 , V_19 ) ;
V_117 = F_35 ( V_2 -> V_62 , V_59 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( ! V_64 ) {
F_60 ( & V_2 -> V_70 , V_19 ) ;
if ( F_88 ( & V_162 ) )
F_14 ( V_2 , L_29 ) ;
return;
}
if ( V_64 -> V_65 . V_150 == 0 ) {
F_60 ( & V_2 -> V_70 , V_19 ) ;
F_14 ( V_2 , L_30
L_31 ,
( unsigned long long ) V_22 , V_59 ) ;
return;
}
if ( F_59 ( V_2 -> V_62 , & V_64 -> V_65 ) == 0 ) {
V_64 -> V_19 = 0 ;
V_2 -> V_174 -- ;
F_7 ( & V_2 -> V_72 ) ;
}
F_60 ( & V_2 -> V_70 , V_19 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_70 ) ;
if ( F_19 ( V_2 , V_8 ) ) {
F_121 ( V_2 -> V_62 ) ;
F_67 ( V_2 ) ;
}
V_2 -> V_174 = 0 ;
V_2 -> V_202 = V_130 ;
F_41 ( & V_2 -> V_70 ) ;
F_7 ( & V_2 -> V_72 ) ;
}
int F_122 ( struct V_1 * V_2 )
{
struct V_60 * V_117 ;
struct V_58 * V_64 ;
int V_75 ;
F_39 ( & V_2 -> V_70 ) ;
if ( F_19 ( V_2 , V_8 ) ) {
for ( V_75 = 0 ; V_75 < V_2 -> V_62 -> V_94 ; V_75 ++ ) {
V_117 = F_73 ( V_2 -> V_62 , V_75 ) ;
V_64 = F_37 ( V_117 , struct V_58 , V_65 ) ;
if ( V_64 -> V_65 . V_81 == V_130 )
continue;
if ( V_64 -> V_65 . V_81 == V_2 -> V_202 ) {
F_56 ( V_2 , L_32
L_33 ,
V_2 -> V_202 ) ;
F_28 ( V_2 , ! F_13 ( V_201 , & V_64 -> V_19 ) ) ;
F_28 ( V_2 , F_13 ( V_66 , & V_64 -> V_19 ) ) ;
F_118 ( V_66 , & V_64 -> V_19 ) ;
V_2 -> V_202 = V_130 ;
F_59 ( V_2 -> V_62 , & V_64 -> V_65 ) ;
}
if ( V_64 -> V_65 . V_150 != 0 ) {
F_56 ( V_2 , L_34
L_35 , V_64 -> V_65 . V_150 ) ;
F_67 ( V_2 ) ;
F_41 ( & V_2 -> V_70 ) ;
return - V_206 ;
}
F_28 ( V_2 , ! F_13 ( V_201 , & V_64 -> V_19 ) ) ;
F_28 ( V_2 , ! F_13 ( V_66 , & V_64 -> V_19 ) ) ;
F_84 ( V_2 -> V_62 , & V_64 -> V_65 ) ;
}
F_28 ( V_2 , V_2 -> V_62 -> V_95 == 0 ) ;
F_67 ( V_2 ) ;
}
F_41 ( & V_2 -> V_70 ) ;
F_7 ( & V_2 -> V_72 ) ;
return 0 ;
}
void F_123 ( struct V_1 * V_2 , T_1 V_22 , int V_24 )
{
unsigned long V_185 , V_186 , V_187 ;
unsigned long V_169 ;
T_1 V_188 , V_189 ;
int F_7 = 0 ;
if ( V_24 <= 0 || ! F_103 ( V_24 , 512 ) || V_24 > V_190 ) {
F_14 ( V_2 , L_36 ,
( unsigned long long ) V_22 , V_24 ) ;
return;
}
V_189 = F_104 ( V_2 -> V_191 ) ;
V_188 = V_22 + ( V_24 >> 9 ) - 1 ;
if ( ! F_105 ( V_22 < V_189 ) )
return;
if ( ! F_105 ( V_188 < V_189 ) )
V_188 = V_189 - 1 ;
V_187 = F_106 ( V_189 - 1 ) ;
if ( F_36 ( V_188 < V_192 - 1 ) )
return;
if ( F_36 ( V_188 == ( V_189 - 1 ) ) )
V_186 = V_187 ;
else
V_186 = F_106 ( V_188 - ( V_192 - 1 ) ) ;
V_185 = F_106 ( V_22 + V_192 - 1 ) ;
if ( V_185 > V_186 )
return;
F_39 ( & V_2 -> V_70 ) ;
V_169 = F_124 ( V_2 , V_185 , V_186 ) ;
if ( V_169 ) {
V_2 -> V_163 += V_169 ;
if ( F_65 ( V_2 ) ) {
F_95 ( V_2 , V_22 , V_169 , false ) ;
F_67 ( V_2 ) ;
}
F_7 = 1 ;
}
F_41 ( & V_2 -> V_70 ) ;
if ( F_7 )
F_7 ( & V_2 -> V_72 ) ;
}
