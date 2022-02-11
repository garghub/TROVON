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
F_14 ( V_20 , L_1 ) ;
F_15 ( V_2 , 1 , V_21 ) ;
}
}
static int F_16 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_22 * V_22 , T_1 V_23 ,
int V_24 , int V_25 )
{
struct V_26 * V_26 ;
int V_27 ;
V_2 -> V_28 . V_12 = 0 ;
V_2 -> V_28 . error = - V_29 ;
if ( ( V_24 & V_30 ) && ! F_13 ( V_31 , & V_2 -> V_19 ) )
V_24 |= V_32 | V_33 ;
V_24 |= V_34 ;
V_26 = F_17 ( V_35 ) ;
V_26 -> V_36 = V_11 -> V_37 ;
V_26 -> V_38 . V_39 = V_23 ;
V_27 = - V_40 ;
if ( F_18 ( V_26 , V_22 , V_25 , 0 ) != V_25 )
goto V_41;
V_26 -> V_42 = & V_2 -> V_28 ;
V_26 -> V_43 = V_44 ;
V_26 -> V_45 = V_24 ;
if ( ! ( V_24 & V_30 ) && V_2 -> V_6 . V_7 == V_46 && V_2 -> V_47 == NULL )
;
else if ( ! F_19 ( V_2 , V_48 ) ) {
F_14 ( V_20 , L_2 ) ;
V_27 = - V_29 ;
goto V_41;
}
F_20 ( V_26 ) ;
F_21 ( & V_2 -> V_5 ) ;
if ( F_22 ( V_2 , ( V_24 & V_30 ) ? V_49 : V_50 ) )
F_23 ( V_26 , - V_40 ) ;
else
F_24 ( V_24 , V_26 ) ;
F_8 ( V_2 , V_11 , & V_2 -> V_28 . V_12 ) ;
if ( F_25 ( V_26 , V_51 ) )
V_27 = V_2 -> V_28 . error ;
V_41:
F_26 ( V_26 ) ;
return V_27 ;
}
int F_27 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_1 V_23 , int V_24 )
{
int V_27 ;
struct V_22 * V_52 = V_2 -> V_9 ;
F_28 ( F_29 ( & V_2 -> V_5 ) == 1 ) ;
F_30 ( ! V_11 -> V_37 ) ;
F_31 ( V_20 , L_3 ,
V_53 -> V_54 , V_53 -> V_55 , V_56 ,
( unsigned long long ) V_23 , ( V_24 & V_30 ) ? L_4 : L_5 ,
( void * ) V_57 ) ;
if ( V_23 < V_58 ( V_11 ) ||
V_23 + 7 > F_32 ( V_11 ) )
F_33 ( V_20 , L_6 ,
V_53 -> V_54 , V_53 -> V_55 , V_56 ,
( unsigned long long ) V_23 , ( V_24 & V_30 ) ? L_4 : L_5 ) ;
V_27 = F_16 ( V_2 , V_11 , V_52 , V_23 , V_24 , 4096 ) ;
if ( V_27 ) {
F_14 ( V_20 , L_7 ,
( unsigned long long ) V_23 , ( V_24 & V_30 ) ? L_4 : L_5 , V_27 ) ;
}
return V_27 ;
}
static struct V_59 * F_34 ( struct V_1 * V_2 , unsigned int V_60 )
{
struct V_61 * V_62 ;
V_62 = F_35 ( V_2 -> V_63 , V_60 / V_64 ) ;
if ( F_36 ( V_62 != NULL ) ) {
struct V_59 * V_65 = F_37 ( V_62 , struct V_59 , V_66 ) ;
if ( F_13 ( V_67 , & V_65 -> V_19 ) )
return V_65 ;
}
return NULL ;
}
static struct V_61 * F_38 ( struct V_1 * V_2 , unsigned int V_60 , bool V_68 )
{
struct V_61 * V_69 ;
struct V_59 * V_65 ;
int V_70 ;
F_39 ( & V_2 -> V_71 ) ;
V_65 = F_34 ( V_2 , V_60 ) ;
if ( V_65 ) {
V_70 = ! F_40 ( V_72 , & V_65 -> V_19 ) ;
F_41 ( & V_2 -> V_71 ) ;
if ( V_70 )
F_7 ( & V_2 -> V_73 ) ;
return NULL ;
}
if ( V_68 )
V_69 = F_42 ( V_2 -> V_74 , V_60 ) ;
else
V_69 = F_43 ( V_2 -> V_74 , V_60 ) ;
F_41 ( & V_2 -> V_71 ) ;
return V_69 ;
}
bool F_44 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
unsigned V_77 = V_76 -> V_23 >> ( V_78 - 9 ) ;
unsigned V_79 = V_76 -> V_25 == 0 ? V_77 : ( V_76 -> V_23 + ( V_76 -> V_25 >> 9 ) - 1 ) >> ( V_78 - 9 ) ;
F_28 ( ( unsigned ) ( V_79 - V_77 ) <= 1 ) ;
F_28 ( F_29 ( & V_2 -> V_80 ) > 0 ) ;
if ( V_77 != V_79 )
return false ;
return F_38 ( V_2 , V_77 , true ) ;
}
bool F_45 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
unsigned V_77 = V_76 -> V_23 >> ( V_78 - 9 ) ;
unsigned V_79 = V_76 -> V_25 == 0 ? V_77 : ( V_76 -> V_23 + ( V_76 -> V_25 >> 9 ) - 1 ) >> ( V_78 - 9 ) ;
unsigned V_60 ;
bool V_81 = false ;
F_28 ( V_77 <= V_79 ) ;
F_28 ( F_29 ( & V_2 -> V_80 ) > 0 ) ;
for ( V_60 = V_77 ; V_60 <= V_79 ; V_60 ++ ) {
struct V_61 * V_69 ;
F_2 ( V_2 -> V_73 ,
( V_69 = F_38 ( V_2 , V_60 , false ) ) != NULL ) ;
if ( V_69 -> V_82 != V_60 )
V_81 = true ;
}
return V_81 ;
}
void F_46 ( struct V_1 * V_2 , bool V_83 )
{
bool V_84 = false ;
F_30 ( V_83 && V_53 == V_2 -> V_85 -> V_86 . V_87 ) ;
F_2 ( V_2 -> V_73 ,
V_2 -> V_74 -> V_88 == 0 ||
( V_84 = F_47 ( V_2 -> V_74 ) ) ) ;
if ( V_84 ) {
if ( V_2 -> V_74 -> V_88 ) {
bool V_89 ;
F_9 () ;
V_89 = F_10 ( V_2 -> V_47 -> V_14 ) -> V_90 ;
F_11 () ;
if ( V_89 )
F_48 ( V_2 , V_83 ) ;
F_39 ( & V_2 -> V_71 ) ;
F_49 ( V_2 -> V_74 ) ;
F_41 ( & V_2 -> V_71 ) ;
}
F_50 ( V_2 -> V_74 ) ;
F_7 ( & V_2 -> V_73 ) ;
}
}
void F_51 ( struct V_1 * V_2 , struct V_75 * V_76 , bool V_83 )
{
F_30 ( V_83 && V_53 == V_2 -> V_85 -> V_86 . V_87 ) ;
if ( F_45 ( V_2 , V_76 ) )
F_46 ( V_2 , V_83 ) ;
}
int F_52 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
struct V_91 * V_92 = V_2 -> V_74 ;
unsigned V_77 = V_76 -> V_23 >> ( V_78 - 9 ) ;
unsigned V_79 = V_76 -> V_25 == 0 ? V_77 : ( V_76 -> V_23 + ( V_76 -> V_25 >> 9 ) - 1 ) >> ( V_78 - 9 ) ;
unsigned V_93 ;
unsigned V_94 ;
unsigned V_60 ;
F_28 ( V_77 <= V_79 ) ;
V_93 = 1 + V_79 - V_77 ;
V_94 = F_53 ( V_92 -> V_95 - V_92 -> V_96 ,
V_92 -> V_97 - V_92 -> V_88 ) ;
if ( V_94 < V_93 )
return - V_98 ;
for ( V_60 = V_77 ; V_60 <= V_79 ; V_60 ++ ) {
struct V_61 * V_62 ;
V_62 = F_35 ( V_2 -> V_63 , V_60 / V_64 ) ;
if ( F_36 ( V_62 != NULL ) ) {
struct V_59 * V_65 = F_37 ( V_62 , struct V_59 , V_66 ) ;
if ( F_13 ( V_67 , & V_65 -> V_19 ) ) {
if ( ! F_40 ( V_72 , & V_65 -> V_19 ) )
return - V_99 ;
return - V_98 ;
}
}
}
for ( V_60 = V_77 ; V_60 <= V_79 ; V_60 ++ ) {
struct V_61 * V_69 ;
V_69 = F_54 ( V_2 -> V_74 , V_60 ) ;
if ( ! V_69 )
F_55 ( V_20 , L_8 , V_60 ) ;
}
return 0 ;
}
void F_56 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
unsigned V_77 = V_76 -> V_23 >> ( V_78 - 9 ) ;
unsigned V_79 = V_76 -> V_25 == 0 ? V_77 : ( V_76 -> V_23 + ( V_76 -> V_25 >> 9 ) - 1 ) >> ( V_78 - 9 ) ;
unsigned V_60 ;
struct V_61 * V_100 ;
unsigned long V_19 ;
F_28 ( V_77 <= V_79 ) ;
F_57 ( & V_2 -> V_71 , V_19 ) ;
for ( V_60 = V_77 ; V_60 <= V_79 ; V_60 ++ ) {
V_100 = F_35 ( V_2 -> V_74 , V_60 ) ;
if ( ! V_100 ) {
F_14 ( V_20 , L_9 , V_60 ) ;
continue;
}
F_58 ( V_2 -> V_74 , V_100 ) ;
}
F_59 ( & V_2 -> V_71 , V_19 ) ;
F_7 ( & V_2 -> V_73 ) ;
}
static unsigned int F_60 ( unsigned int V_101 )
{
return V_101 >>
( ( V_102 + 3 ) -
( V_78 - V_103 ) ) ;
}
static unsigned int F_61 ( unsigned int V_104 )
{
return V_104 >>
( ( V_102 + 3 ) -
( V_105 - V_103 ) ) ;
}
static T_1 F_62 ( struct V_1 * V_2 )
{
const unsigned int V_106 = V_2 -> V_47 -> V_107 . V_108 ;
const unsigned int V_109 = V_2 -> V_47 -> V_107 . V_110 ;
unsigned int V_111 = V_2 -> V_112 % ( V_2 -> V_47 -> V_107 . V_113 ) ;
V_111 = ( ( V_111 % V_106 ) * V_109 ) + V_111 / V_106 ;
V_111 *= 8 ;
return V_2 -> V_47 -> V_107 . V_114 + V_2 -> V_47 -> V_107 . V_115 + V_111 ;
}
static int
F_63 ( struct V_1 * V_2 )
{
struct V_116 * V_117 ;
struct V_61 * V_118 ;
T_1 V_23 ;
int V_76 , V_119 ;
unsigned V_120 ;
unsigned V_121 = 0 ;
int V_27 = 0 ;
if ( ! F_64 ( V_2 ) ) {
F_14 ( V_20 , L_10 ,
F_65 ( V_2 -> V_6 . V_7 ) ) ;
return - V_40 ;
}
if ( V_2 -> V_6 . V_7 < V_122 ) {
F_14 ( V_20 ,
L_11 ,
F_65 ( V_2 -> V_6 . V_7 ) ) ;
F_66 ( V_2 ) ;
return - V_40 ;
}
V_117 = F_1 ( V_2 ) ;
if ( ! V_117 ) {
F_14 ( V_20 , L_12 ) ;
F_66 ( V_2 ) ;
return - V_29 ;
}
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
V_117 -> V_123 = F_67 ( V_124 ) ;
V_117 -> V_125 = F_67 ( V_2 -> V_112 ) ;
V_76 = 0 ;
F_39 ( & V_2 -> V_71 ) ;
F_68 (e, &mdev->act_log->to_be_changed, list) {
if ( V_76 == V_126 ) {
V_76 ++ ;
break;
}
V_117 -> V_127 [ V_76 ] = F_69 ( V_118 -> V_128 ) ;
V_117 -> V_129 [ V_76 ] = F_67 ( V_118 -> V_130 ) ;
if ( V_118 -> V_82 != V_131 )
F_70 ( V_2 ,
F_60 ( V_118 -> V_82 ) ) ;
V_76 ++ ;
}
F_41 ( & V_2 -> V_71 ) ;
F_30 ( V_76 > V_126 ) ;
V_117 -> V_132 = F_69 ( V_76 ) ;
for ( ; V_76 < V_126 ; V_76 ++ ) {
V_117 -> V_127 [ V_76 ] = F_69 ( - 1 ) ;
V_117 -> V_129 [ V_76 ] = F_67 ( V_131 ) ;
}
V_117 -> V_133 = F_69 ( V_2 -> V_74 -> V_95 ) ;
V_117 -> V_134 = F_69 ( V_2 -> V_135 ) ;
V_119 = F_71 ( int , V_136 ,
V_2 -> V_74 -> V_95 - V_2 -> V_135 ) ;
for ( V_76 = 0 ; V_76 < V_119 ; V_76 ++ ) {
unsigned V_137 = V_2 -> V_135 + V_76 ;
V_120 = F_72 ( V_2 -> V_74 , V_137 ) -> V_82 ;
V_117 -> V_138 [ V_76 ] = F_67 ( V_120 ) ;
}
for (; V_76 < V_136 ; V_76 ++ )
V_117 -> V_138 [ V_76 ] = F_67 ( V_131 ) ;
V_2 -> V_135 += V_136 ;
if ( V_2 -> V_135 >= V_2 -> V_74 -> V_95 )
V_2 -> V_135 = 0 ;
V_23 = F_62 ( V_2 ) ;
V_121 = F_73 ( 0 , V_117 , 4096 ) ;
V_117 -> F_73 = F_67 ( V_121 ) ;
if ( F_74 ( V_2 ) )
V_27 = - V_40 ;
else {
bool V_89 ;
F_9 () ;
V_89 = F_10 ( V_2 -> V_47 -> V_14 ) -> V_90 ;
F_11 () ;
if ( V_89 ) {
if ( F_27 ( V_2 , V_2 -> V_47 , V_23 , V_30 ) ) {
V_27 = - V_40 ;
F_15 ( V_2 , 1 , V_139 ) ;
} else {
V_2 -> V_112 ++ ;
V_2 -> V_140 ++ ;
}
}
}
F_5 ( V_2 ) ;
F_66 ( V_2 ) ;
return V_27 ;
}
static int F_75 ( struct V_141 * V_142 , int V_143 )
{
struct V_144 * V_145 = F_76 ( V_142 , struct V_144 , V_142 ) ;
struct V_1 * V_2 = V_142 -> V_2 ;
int V_27 ;
V_27 = F_63 ( V_2 ) ;
V_145 -> V_27 = V_27 ;
F_77 ( & V_145 -> V_146 ) ;
return V_27 != - V_40 ? V_27 : 0 ;
}
static int F_48 ( struct V_1 * V_2 , bool V_83 )
{
if ( V_83 ) {
struct V_144 V_147 ;
F_78 ( & V_147 . V_146 ) ;
V_147 . V_142 . V_148 = F_75 ;
V_147 . V_142 . V_2 = V_2 ;
F_79 ( & V_2 -> V_85 -> V_149 , & V_147 . V_142 ) ;
F_80 ( & V_147 . V_146 ) ;
return V_147 . V_27 ;
} else
return F_63 ( V_2 ) ;
}
static int F_81 ( struct V_1 * V_2 , struct V_61 * V_69 )
{
int V_150 ;
F_39 ( & V_2 -> V_71 ) ;
V_150 = ( V_69 -> V_151 == 0 ) ;
if ( F_82 ( V_150 ) )
F_83 ( V_2 -> V_74 , V_69 ) ;
F_41 ( & V_2 -> V_71 ) ;
return V_150 ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_61 * V_69 ;
int V_76 ;
F_28 ( F_13 ( V_152 , & V_2 -> V_74 -> V_19 ) ) ;
for ( V_76 = 0 ; V_76 < V_2 -> V_74 -> V_95 ; V_76 ++ ) {
V_69 = F_72 ( V_2 -> V_74 , V_76 ) ;
if ( V_69 -> V_82 == V_131 )
continue;
F_2 ( V_2 -> V_73 , F_81 ( V_2 , V_69 ) ) ;
}
F_7 ( & V_2 -> V_73 ) ;
}
int F_85 ( struct V_1 * V_2 , void * V_117 )
{
struct V_116 * V_92 = V_117 ;
struct V_153 * V_107 = & V_2 -> V_47 -> V_107 ;
T_1 V_154 = V_107 -> V_114 + V_107 -> V_115 ;
int V_113 = V_107 -> V_108 * V_107 -> V_110 ;
int V_76 ;
memset ( V_92 , 0 , 4096 ) ;
V_92 -> V_123 = F_67 ( V_124 ) ;
V_92 -> V_155 = F_69 ( V_156 ) ;
V_92 -> F_73 = F_67 ( F_73 ( 0 , V_92 , 4096 ) ) ;
for ( V_76 = 0 ; V_76 < V_113 ; V_76 ++ ) {
int V_27 = F_27 ( V_2 , V_2 -> V_47 , V_154 + V_76 * 8 , V_30 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_86 ( struct V_141 * V_142 , int V_143 )
{
struct V_157 * V_158 = F_76 ( V_142 , struct V_157 , V_142 ) ;
struct V_1 * V_2 = V_142 -> V_2 ;
struct V_159 V_160 = { . V_161 = V_162 , } ;
if ( ! F_64 ( V_2 ) ) {
if ( F_87 ( & V_163 ) )
F_88 ( V_20 , L_13 ) ;
F_89 ( V_158 ) ;
return 0 ;
}
F_90 ( V_2 , F_61 ( V_158 -> V_60 ) ) ;
F_66 ( V_2 ) ;
F_89 ( V_158 ) ;
if ( F_91 ( V_2 ) <= V_2 -> V_164 ) {
switch ( V_2 -> V_6 . V_165 ) {
case V_166 : case V_167 :
case V_168 : case V_169 :
F_92 ( V_2 ) ;
default:
break;
}
}
F_93 ( V_2 , & V_160 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 , T_1 V_23 ,
int V_170 , int V_171 )
{
struct V_61 * V_118 ;
struct V_157 * V_158 ;
unsigned int V_60 ;
F_28 ( F_29 ( & V_2 -> V_80 ) ) ;
V_60 = F_95 ( V_23 ) ;
V_118 = F_43 ( V_2 -> V_63 , V_60 ) ;
if ( V_118 ) {
struct V_59 * V_172 = F_37 ( V_118 , struct V_59 , V_66 ) ;
if ( V_172 -> V_66 . V_82 == V_60 ) {
if ( V_171 )
V_172 -> V_173 -= V_170 ;
else
V_172 -> V_164 += V_170 ;
if ( V_172 -> V_173 < V_172 -> V_164 ) {
F_88 ( V_20 , L_14
L_15 ,
( unsigned long long ) V_23 ,
V_172 -> V_66 . V_82 , V_172 -> V_173 ,
V_172 -> V_164 , V_170 ,
F_96 ( V_2 -> V_6 . V_165 ) ) ;
V_172 -> V_173 = F_97 ( V_2 , V_60 ) ;
}
} else {
int V_173 = F_97 ( V_2 , V_60 ) ;
if ( V_172 -> V_19 != 0 ) {
F_88 ( V_20 , L_16
L_17 ,
V_172 -> V_66 . V_82 , V_172 -> V_173 ,
V_172 -> V_19 , V_60 , V_173 ) ;
V_172 -> V_19 = 0 ;
}
if ( V_172 -> V_164 ) {
F_88 ( V_20 , L_18
L_19 ,
V_172 -> V_66 . V_82 , V_172 -> V_164 ) ;
}
V_172 -> V_173 = V_173 ;
V_172 -> V_164 = V_171 ? 0 : V_170 ;
F_49 ( V_2 -> V_63 ) ;
}
F_58 ( V_2 -> V_63 , & V_172 -> V_66 ) ;
if ( V_172 -> V_173 == V_172 -> V_164 ) {
V_172 -> V_164 = 0 ;
V_158 = F_98 ( sizeof( * V_158 ) , V_174 ) ;
if ( V_158 ) {
V_158 -> V_60 = V_172 -> V_66 . V_82 ;
V_158 -> V_142 . V_148 = F_86 ;
V_158 -> V_142 . V_2 = V_2 ;
F_79 ( & V_2 -> V_85 -> V_149 , & V_158 -> V_142 ) ;
} else {
F_88 ( V_20 , L_20 ) ;
}
}
} else {
F_14 ( V_20 , L_21 ,
V_2 -> V_175 ,
V_2 -> V_63 -> V_95 ,
V_2 -> V_63 -> V_19 ) ;
}
}
void F_99 ( struct V_1 * V_2 , unsigned long V_176 )
{
unsigned long V_177 = V_178 ;
unsigned long V_79 = V_2 -> V_179 [ V_2 -> V_180 ] ;
int V_181 = ( V_2 -> V_180 + 1 ) % V_182 ;
if ( F_100 ( V_177 , V_79 + V_183 ) ) {
if ( V_2 -> V_184 [ V_2 -> V_180 ] != V_176 &&
V_2 -> V_6 . V_165 != V_169 &&
V_2 -> V_6 . V_165 != V_168 ) {
V_2 -> V_179 [ V_181 ] = V_177 ;
V_2 -> V_184 [ V_181 ] = V_176 ;
V_2 -> V_180 = V_181 ;
}
}
}
void F_101 ( struct V_1 * V_2 , T_1 V_23 , int V_25 ,
const char * V_185 , const unsigned int line )
{
unsigned long V_186 , V_187 , V_188 ;
unsigned long V_170 = 0 ;
T_1 V_189 , V_190 ;
int F_7 = 0 ;
unsigned long V_19 ;
if ( V_25 <= 0 || ! F_102 ( V_25 , 512 ) || V_25 > V_191 ) {
F_14 ( V_20 , L_22 ,
( unsigned long long ) V_23 , V_25 ) ;
return;
}
if ( ! F_64 ( V_2 ) )
return;
V_190 = F_103 ( V_2 -> V_192 ) ;
V_189 = V_23 + ( V_25 >> 9 ) - 1 ;
if ( ! F_104 ( V_23 < V_190 ) )
goto V_41;
if ( ! F_104 ( V_189 < V_190 ) )
V_189 = V_190 - 1 ;
V_188 = F_105 ( V_190 - 1 ) ;
if ( F_36 ( V_189 < V_193 - 1 ) )
goto V_41;
if ( F_36 ( V_189 == ( V_190 - 1 ) ) )
V_187 = V_188 ;
else
V_187 = F_105 ( V_189 - ( V_193 - 1 ) ) ;
V_186 = F_105 ( V_23 + V_193 - 1 ) ;
if ( V_186 > V_187 )
goto V_41;
V_170 = F_106 ( V_2 , V_186 , V_187 ) ;
if ( V_170 ) {
F_99 ( V_2 , F_91 ( V_2 ) ) ;
F_57 ( & V_2 -> V_71 , V_19 ) ;
F_94 ( V_2 , V_23 , V_170 , true ) ;
F_59 ( & V_2 -> V_71 , V_19 ) ;
F_7 = 1 ;
}
V_41:
F_66 ( V_2 ) ;
if ( F_7 )
F_7 ( & V_2 -> V_73 ) ;
}
int F_107 ( struct V_1 * V_2 , T_1 V_23 , int V_25 ,
const char * V_185 , const unsigned int line )
{
unsigned long V_186 , V_187 , V_19 ;
T_1 V_189 , V_190 ;
unsigned int V_60 , V_170 = 0 ;
struct V_61 * V_118 ;
if ( V_25 == 0 )
return 0 ;
if ( V_25 < 0 || ! F_102 ( V_25, 512 ) || V_25 > V_191 ) {
F_14 ( V_20 , L_23 ,
( unsigned long long ) V_23 , V_25 ) ;
return 0 ;
}
if ( ! F_64 ( V_2 ) )
return 0 ;
V_190 = F_103 ( V_2 -> V_192 ) ;
V_189 = V_23 + ( V_25 >> 9 ) - 1 ;
if ( ! F_104 ( V_23 < V_190 ) )
goto V_41;
if ( ! F_104 ( V_189 < V_190 ) )
V_189 = V_190 - 1 ;
V_186 = F_105 ( V_23 ) ;
V_187 = F_105 ( V_189 ) ;
F_57 ( & V_2 -> V_71 , V_19 ) ;
V_170 = F_108 ( V_2 , V_186 , V_187 ) ;
V_60 = F_95 ( V_23 ) ;
V_118 = F_35 ( V_2 -> V_63 , V_60 ) ;
if ( V_118 )
F_37 ( V_118 , struct V_59 , V_66 ) -> V_173 += V_170 ;
F_59 ( & V_2 -> V_71 , V_19 ) ;
V_41:
F_66 ( V_2 ) ;
return V_170 ;
}
static
struct V_59 * F_109 ( struct V_1 * V_2 , unsigned int V_60 )
{
struct V_61 * V_118 ;
struct V_59 * V_65 ;
int V_194 = 0 ;
unsigned long V_195 ;
F_39 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_175 > V_2 -> V_63 -> V_95 / 2 ) {
F_41 ( & V_2 -> V_71 ) ;
return NULL ;
}
V_118 = F_43 ( V_2 -> V_63 , V_60 ) ;
V_65 = V_118 ? F_37 ( V_118 , struct V_59 , V_66 ) : NULL ;
if ( V_65 ) {
if ( V_65 -> V_66 . V_82 != V_60 ) {
V_65 -> V_173 = F_97 ( V_2 , V_60 ) ;
V_65 -> V_164 = 0 ;
F_49 ( V_2 -> V_63 ) ;
V_194 = 1 ;
}
if ( V_65 -> V_66 . V_151 == 1 )
V_2 -> V_175 ++ ;
F_110 ( V_67 , & V_65 -> V_19 ) ;
}
V_195 = V_2 -> V_63 -> V_19 ;
F_41 ( & V_2 -> V_71 ) ;
if ( V_194 )
F_7 ( & V_2 -> V_73 ) ;
if ( ! V_65 ) {
if ( V_195 & V_196 )
F_88 ( V_20 , L_24
L_25 ) ;
F_30 ( V_195 & V_197 ) ;
}
return V_65 ;
}
static int F_111 ( struct V_1 * V_2 , unsigned int V_60 )
{
int V_150 ;
F_39 ( & V_2 -> V_71 ) ;
V_150 = F_112 ( V_2 -> V_74 , V_60 ) ;
F_41 ( & V_2 -> V_71 ) ;
return V_150 ;
}
int F_113 ( struct V_1 * V_2 , T_1 V_23 )
{
unsigned int V_60 = F_95 ( V_23 ) ;
struct V_59 * V_65 ;
int V_76 , V_198 ;
int V_199 = 200 ;
V_200:
V_198 = F_114 ( V_2 -> V_73 ,
( V_65 = F_109 ( V_2 , V_60 ) ) ) ;
if ( V_198 )
return - V_201 ;
if ( F_13 ( V_202 , & V_65 -> V_19 ) )
return 0 ;
for ( V_76 = 0 ; V_76 < V_64 ; V_76 ++ ) {
V_198 = F_114 ( V_2 -> V_73 ,
! F_111 ( V_2 , V_60 * V_64 + V_76 ) ||
F_13 ( V_72 , & V_65 -> V_19 ) ) ;
if ( V_198 || ( F_13 ( V_72 , & V_65 -> V_19 ) && V_199 ) ) {
F_39 ( & V_2 -> V_71 ) ;
if ( F_58 ( V_2 -> V_63 , & V_65 -> V_66 ) == 0 ) {
V_65 -> V_19 = 0 ;
V_2 -> V_175 -- ;
F_7 ( & V_2 -> V_73 ) ;
}
F_41 ( & V_2 -> V_71 ) ;
if ( V_198 )
return - V_201 ;
if ( F_115 ( V_16 / 10 ) )
return - V_201 ;
if ( V_199 && -- V_199 == 0 )
F_88 ( V_20 , L_26
L_27 ) ;
goto V_200;
}
}
F_110 ( V_202 , & V_65 -> V_19 ) ;
return 0 ;
}
int F_116 ( struct V_1 * V_2 , T_1 V_23 )
{
unsigned int V_60 = F_95 ( V_23 ) ;
const unsigned int V_101 = V_60 * V_64 ;
struct V_61 * V_118 ;
struct V_59 * V_65 ;
int V_76 ;
F_39 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_203 != V_131 && V_2 -> V_203 != V_60 ) {
V_118 = F_35 ( V_2 -> V_63 , V_2 -> V_203 ) ;
V_65 = V_118 ? F_37 ( V_118 , struct V_59 , V_66 ) : NULL ;
if ( V_65 ) {
F_28 ( ! F_13 ( V_202 , & V_65 -> V_19 ) ) ;
F_28 ( F_13 ( V_67 , & V_65 -> V_19 ) ) ;
F_117 ( V_67 , & V_65 -> V_19 ) ;
V_2 -> V_203 = V_131 ;
if ( F_58 ( V_2 -> V_63 , & V_65 -> V_66 ) == 0 )
V_2 -> V_175 -- ;
F_7 ( & V_2 -> V_73 ) ;
} else {
F_33 ( V_20 , L_28 ) ;
}
}
V_118 = F_42 ( V_2 -> V_63 , V_60 ) ;
V_65 = V_118 ? F_37 ( V_118 , struct V_59 , V_66 ) : NULL ;
if ( V_65 ) {
if ( F_13 ( V_202 , & V_65 -> V_19 ) )
goto V_204;
if ( ! F_40 ( V_67 , & V_65 -> V_19 ) ) {
V_2 -> V_175 ++ ;
} else {
V_65 -> V_66 . V_151 -- ;
F_28 ( V_65 -> V_66 . V_151 > 0 ) ;
}
goto V_205;
} else {
if ( V_2 -> V_175 > V_2 -> V_63 -> V_95 - 3 )
goto V_206;
V_118 = F_43 ( V_2 -> V_63 , V_60 ) ;
V_65 = V_118 ? F_37 ( V_118 , struct V_59 , V_66 ) : NULL ;
if ( ! V_65 ) {
const unsigned long V_195 = V_2 -> V_63 -> V_19 ;
if ( V_195 & V_196 )
F_88 ( V_20 , L_24
L_25 ) ;
F_30 ( V_195 & V_197 ) ;
goto V_206;
}
if ( V_65 -> V_66 . V_82 != V_60 ) {
V_65 -> V_173 = F_97 ( V_2 , V_60 ) ;
V_65 -> V_164 = 0 ;
F_49 ( V_2 -> V_63 ) ;
F_7 ( & V_2 -> V_73 ) ;
F_28 ( F_13 ( V_202 , & V_65 -> V_19 ) == 0 ) ;
}
F_110 ( V_67 , & V_65 -> V_19 ) ;
F_28 ( V_65 -> V_66 . V_151 == 1 ) ;
V_2 -> V_175 ++ ;
goto V_205;
}
V_205:
for ( V_76 = 0 ; V_76 < V_64 ; V_76 ++ ) {
if ( F_112 ( V_2 -> V_74 , V_101 + V_76 ) )
goto V_206;
}
F_110 ( V_202 , & V_65 -> V_19 ) ;
V_204:
V_2 -> V_203 = V_131 ;
F_41 ( & V_2 -> V_71 ) ;
return 0 ;
V_206:
if ( V_65 )
V_2 -> V_203 = V_60 ;
F_41 ( & V_2 -> V_71 ) ;
return - V_207 ;
}
void F_118 ( struct V_1 * V_2 , T_1 V_23 )
{
unsigned int V_60 = F_95 ( V_23 ) ;
struct V_61 * V_118 ;
struct V_59 * V_65 ;
unsigned long V_19 ;
F_57 ( & V_2 -> V_71 , V_19 ) ;
V_118 = F_35 ( V_2 -> V_63 , V_60 ) ;
V_65 = V_118 ? F_37 ( V_118 , struct V_59 , V_66 ) : NULL ;
if ( ! V_65 ) {
F_59 ( & V_2 -> V_71 , V_19 ) ;
if ( F_87 ( & V_163 ) )
F_14 ( V_20 , L_29 ) ;
return;
}
if ( V_65 -> V_66 . V_151 == 0 ) {
F_59 ( & V_2 -> V_71 , V_19 ) ;
F_14 ( V_20 , L_30
L_31 ,
( unsigned long long ) V_23 , V_60 ) ;
return;
}
if ( F_58 ( V_2 -> V_63 , & V_65 -> V_66 ) == 0 ) {
V_65 -> V_19 = 0 ;
V_2 -> V_175 -- ;
F_7 ( & V_2 -> V_73 ) ;
}
F_59 ( & V_2 -> V_71 , V_19 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_71 ) ;
if ( F_19 ( V_2 , V_8 ) ) {
F_120 ( V_2 -> V_63 ) ;
F_66 ( V_2 ) ;
}
V_2 -> V_175 = 0 ;
V_2 -> V_203 = V_131 ;
F_41 ( & V_2 -> V_71 ) ;
F_7 ( & V_2 -> V_73 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_61 * V_118 ;
struct V_59 * V_65 ;
int V_76 ;
F_39 ( & V_2 -> V_71 ) ;
if ( F_19 ( V_2 , V_8 ) ) {
for ( V_76 = 0 ; V_76 < V_2 -> V_63 -> V_95 ; V_76 ++ ) {
V_118 = F_72 ( V_2 -> V_63 , V_76 ) ;
V_65 = F_37 ( V_118 , struct V_59 , V_66 ) ;
if ( V_65 -> V_66 . V_82 == V_131 )
continue;
if ( V_65 -> V_66 . V_82 == V_2 -> V_203 ) {
F_55 ( V_20 , L_32
L_33 ,
V_2 -> V_203 ) ;
F_28 ( ! F_13 ( V_202 , & V_65 -> V_19 ) ) ;
F_28 ( F_13 ( V_67 , & V_65 -> V_19 ) ) ;
F_117 ( V_67 , & V_65 -> V_19 ) ;
V_2 -> V_203 = V_131 ;
F_58 ( V_2 -> V_63 , & V_65 -> V_66 ) ;
}
if ( V_65 -> V_66 . V_151 != 0 ) {
F_55 ( V_20 , L_34
L_35 , V_65 -> V_66 . V_151 ) ;
F_66 ( V_2 ) ;
F_41 ( & V_2 -> V_71 ) ;
return - V_207 ;
}
F_28 ( ! F_13 ( V_202 , & V_65 -> V_19 ) ) ;
F_28 ( ! F_13 ( V_67 , & V_65 -> V_19 ) ) ;
F_83 ( V_2 -> V_63 , & V_65 -> V_66 ) ;
}
F_28 ( V_2 -> V_63 -> V_96 == 0 ) ;
F_66 ( V_2 ) ;
}
F_41 ( & V_2 -> V_71 ) ;
F_7 ( & V_2 -> V_73 ) ;
return 0 ;
}
void F_122 ( struct V_1 * V_2 , T_1 V_23 , int V_25 )
{
unsigned long V_186 , V_187 , V_188 ;
unsigned long V_170 ;
T_1 V_189 , V_190 ;
int F_7 = 0 ;
if ( V_25 <= 0 || ! F_102 ( V_25 , 512 ) || V_25 > V_191 ) {
F_14 ( V_20 , L_36 ,
( unsigned long long ) V_23 , V_25 ) ;
return;
}
V_190 = F_103 ( V_2 -> V_192 ) ;
V_189 = V_23 + ( V_25 >> 9 ) - 1 ;
if ( ! F_104 ( V_23 < V_190 ) )
return;
if ( ! F_104 ( V_189 < V_190 ) )
V_189 = V_190 - 1 ;
V_188 = F_105 ( V_190 - 1 ) ;
if ( F_36 ( V_189 < V_193 - 1 ) )
return;
if ( F_36 ( V_189 == ( V_190 - 1 ) ) )
V_187 = V_188 ;
else
V_187 = F_105 ( V_189 - ( V_193 - 1 ) ) ;
V_186 = F_105 ( V_23 + V_193 - 1 ) ;
if ( V_186 > V_187 )
return;
F_39 ( & V_2 -> V_71 ) ;
V_170 = F_123 ( V_2 , V_186 , V_187 ) ;
if ( V_170 ) {
V_2 -> V_164 += V_170 ;
if ( F_64 ( V_2 ) ) {
F_94 ( V_2 , V_23 , V_170 , false ) ;
F_66 ( V_2 ) ;
}
F_7 = 1 ;
}
F_41 ( & V_2 -> V_71 ) ;
if ( F_7 )
F_7 ( & V_2 -> V_73 ) ;
}
