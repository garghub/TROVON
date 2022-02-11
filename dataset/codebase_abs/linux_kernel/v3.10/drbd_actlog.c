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
V_26 -> V_38 = V_23 ;
V_27 = - V_39 ;
if ( F_18 ( V_26 , V_22 , V_25 , 0 ) != V_25 )
goto V_40;
V_26 -> V_41 = & V_2 -> V_28 ;
V_26 -> V_42 = V_43 ;
V_26 -> V_44 = V_24 ;
if ( ! ( V_24 & V_30 ) && V_2 -> V_6 . V_7 == V_45 && V_2 -> V_46 == NULL )
;
else if ( ! F_19 ( V_2 , V_47 ) ) {
F_14 ( V_20 , L_2 ) ;
V_27 = - V_29 ;
goto V_40;
}
F_20 ( V_26 ) ;
F_21 ( & V_2 -> V_5 ) ;
if ( F_22 ( V_2 , ( V_24 & V_30 ) ? V_48 : V_49 ) )
F_23 ( V_26 , - V_39 ) ;
else
F_24 ( V_24 , V_26 ) ;
F_8 ( V_2 , V_11 , & V_2 -> V_28 . V_12 ) ;
if ( F_25 ( V_26 , V_50 ) )
V_27 = V_2 -> V_28 . error ;
V_40:
F_26 ( V_26 ) ;
return V_27 ;
}
int F_27 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_1 V_23 , int V_24 )
{
int V_27 ;
struct V_22 * V_51 = V_2 -> V_9 ;
F_28 ( F_29 ( & V_2 -> V_5 ) == 1 ) ;
F_30 ( ! V_11 -> V_37 ) ;
F_31 ( V_20 , L_3 ,
V_52 -> V_53 , V_52 -> V_54 , V_55 ,
( unsigned long long ) V_23 , ( V_24 & V_30 ) ? L_4 : L_5 ,
( void * ) V_56 ) ;
if ( V_23 < V_57 ( V_11 ) ||
V_23 + 7 > F_32 ( V_11 ) )
F_33 ( V_20 , L_6 ,
V_52 -> V_53 , V_52 -> V_54 , V_55 ,
( unsigned long long ) V_23 , ( V_24 & V_30 ) ? L_4 : L_5 ) ;
V_27 = F_16 ( V_2 , V_11 , V_51 , V_23 , V_24 , 4096 ) ;
if ( V_27 ) {
F_14 ( V_20 , L_7 ,
( unsigned long long ) V_23 , ( V_24 & V_30 ) ? L_4 : L_5 , V_27 ) ;
}
return V_27 ;
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
unsigned V_76 = V_75 -> V_23 >> ( V_77 - 9 ) ;
unsigned V_78 = V_75 -> V_25 == 0 ? V_76 : ( V_75 -> V_23 + ( V_75 -> V_25 >> 9 ) - 1 ) >> ( V_77 - 9 ) ;
F_28 ( ( unsigned ) ( V_78 - V_76 ) <= 1 ) ;
F_28 ( F_29 ( & V_2 -> V_79 ) > 0 ) ;
if ( V_76 != V_78 )
return false ;
return F_38 ( V_2 , V_76 , true ) ;
}
bool F_45 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
unsigned V_76 = V_75 -> V_23 >> ( V_77 - 9 ) ;
unsigned V_78 = V_75 -> V_25 == 0 ? V_76 : ( V_75 -> V_23 + ( V_75 -> V_25 >> 9 ) - 1 ) >> ( V_77 - 9 ) ;
unsigned V_59 ;
bool V_80 = false ;
F_28 ( V_76 <= V_78 ) ;
F_28 ( F_29 ( & V_2 -> V_79 ) > 0 ) ;
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
F_30 ( V_82 && V_52 == V_2 -> V_84 -> V_85 . V_86 ) ;
F_2 ( V_2 -> V_72 ,
V_2 -> V_73 -> V_87 == 0 ||
( V_83 = F_47 ( V_2 -> V_73 ) ) ) ;
if ( V_83 ) {
if ( V_2 -> V_73 -> V_87 ) {
bool V_88 ;
F_9 () ;
V_88 = F_10 ( V_2 -> V_46 -> V_14 ) -> V_89 ;
F_11 () ;
if ( V_88 )
F_48 ( V_2 , V_82 ) ;
F_39 ( & V_2 -> V_70 ) ;
F_49 ( V_2 -> V_73 ) ;
F_41 ( & V_2 -> V_70 ) ;
}
F_50 ( V_2 -> V_73 ) ;
F_7 ( & V_2 -> V_72 ) ;
}
}
void F_51 ( struct V_1 * V_2 , struct V_74 * V_75 , bool V_82 )
{
F_30 ( V_82 && V_52 == V_2 -> V_84 -> V_85 . V_86 ) ;
if ( F_45 ( V_2 , V_75 ) )
F_46 ( V_2 , V_82 ) ;
}
int F_52 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
struct V_90 * V_91 = V_2 -> V_73 ;
unsigned V_76 = V_75 -> V_23 >> ( V_77 - 9 ) ;
unsigned V_78 = V_75 -> V_25 == 0 ? V_76 : ( V_75 -> V_23 + ( V_75 -> V_25 >> 9 ) - 1 ) >> ( V_77 - 9 ) ;
unsigned V_92 ;
unsigned V_93 ;
unsigned V_59 ;
F_28 ( V_76 <= V_78 ) ;
V_92 = 1 + V_78 - V_76 ;
V_93 = F_53 ( V_91 -> V_94 - V_91 -> V_95 ,
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
V_68 = F_54 ( V_2 -> V_73 , V_59 ) ;
if ( ! V_68 )
F_55 ( V_20 , L_8 , V_59 ) ;
}
return 0 ;
}
void F_56 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
unsigned V_76 = V_75 -> V_23 >> ( V_77 - 9 ) ;
unsigned V_78 = V_75 -> V_25 == 0 ? V_76 : ( V_75 -> V_23 + ( V_75 -> V_25 >> 9 ) - 1 ) >> ( V_77 - 9 ) ;
unsigned V_59 ;
struct V_60 * V_99 ;
unsigned long V_19 ;
F_28 ( V_76 <= V_78 ) ;
F_57 ( & V_2 -> V_70 , V_19 ) ;
for ( V_59 = V_76 ; V_59 <= V_78 ; V_59 ++ ) {
V_99 = F_35 ( V_2 -> V_73 , V_59 ) ;
if ( ! V_99 ) {
F_14 ( V_20 , L_9 , V_59 ) ;
continue;
}
F_58 ( V_2 -> V_73 , V_99 ) ;
}
F_59 ( & V_2 -> V_70 , V_19 ) ;
F_7 ( & V_2 -> V_72 ) ;
}
static unsigned int F_60 ( unsigned int V_100 )
{
return V_100 >>
( ( V_101 + 3 ) -
( V_77 - V_102 ) ) ;
}
static unsigned int F_61 ( unsigned int V_103 )
{
return V_103 >>
( ( V_101 + 3 ) -
( V_104 - V_102 ) ) ;
}
static T_1 F_62 ( struct V_1 * V_2 )
{
const unsigned int V_105 = V_2 -> V_46 -> V_106 . V_107 ;
const unsigned int V_108 = V_2 -> V_46 -> V_106 . V_109 ;
unsigned int V_110 = V_2 -> V_111 % ( V_2 -> V_46 -> V_106 . V_112 ) ;
V_110 = ( ( V_110 % V_105 ) * V_108 ) + V_110 / V_105 ;
V_110 *= 8 ;
return V_2 -> V_46 -> V_106 . V_113 + V_2 -> V_46 -> V_106 . V_114 + V_110 ;
}
static int
F_63 ( struct V_1 * V_2 )
{
struct V_115 * V_116 ;
struct V_60 * V_117 ;
T_1 V_23 ;
int V_75 , V_118 ;
unsigned V_119 ;
unsigned V_120 = 0 ;
int V_27 = 0 ;
if ( ! F_64 ( V_2 ) ) {
F_14 ( V_20 , L_10 ,
F_65 ( V_2 -> V_6 . V_7 ) ) ;
return - V_39 ;
}
if ( V_2 -> V_6 . V_7 < V_121 ) {
F_14 ( V_20 ,
L_11 ,
F_65 ( V_2 -> V_6 . V_7 ) ) ;
F_66 ( V_2 ) ;
return - V_39 ;
}
V_116 = F_1 ( V_2 ) ;
if ( ! V_116 ) {
F_14 ( V_20 , L_12 ) ;
F_66 ( V_2 ) ;
return - V_29 ;
}
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_122 = F_67 ( V_123 ) ;
V_116 -> V_124 = F_67 ( V_2 -> V_111 ) ;
V_75 = 0 ;
F_39 ( & V_2 -> V_70 ) ;
F_68 (e, &mdev->act_log->to_be_changed, list) {
if ( V_75 == V_125 ) {
V_75 ++ ;
break;
}
V_116 -> V_126 [ V_75 ] = F_69 ( V_117 -> V_127 ) ;
V_116 -> V_128 [ V_75 ] = F_67 ( V_117 -> V_129 ) ;
if ( V_117 -> V_81 != V_130 )
F_70 ( V_2 ,
F_60 ( V_117 -> V_81 ) ) ;
V_75 ++ ;
}
F_41 ( & V_2 -> V_70 ) ;
F_30 ( V_75 > V_125 ) ;
V_116 -> V_131 = F_69 ( V_75 ) ;
for ( ; V_75 < V_125 ; V_75 ++ ) {
V_116 -> V_126 [ V_75 ] = F_69 ( - 1 ) ;
V_116 -> V_128 [ V_75 ] = F_67 ( V_130 ) ;
}
V_116 -> V_132 = F_69 ( V_2 -> V_73 -> V_94 ) ;
V_116 -> V_133 = F_69 ( V_2 -> V_134 ) ;
V_118 = F_71 ( int , V_135 ,
V_2 -> V_73 -> V_94 - V_2 -> V_134 ) ;
for ( V_75 = 0 ; V_75 < V_118 ; V_75 ++ ) {
unsigned V_136 = V_2 -> V_134 + V_75 ;
V_119 = F_72 ( V_2 -> V_73 , V_136 ) -> V_81 ;
V_116 -> V_137 [ V_75 ] = F_67 ( V_119 ) ;
}
for (; V_75 < V_135 ; V_75 ++ )
V_116 -> V_137 [ V_75 ] = F_67 ( V_130 ) ;
V_2 -> V_134 += V_135 ;
if ( V_2 -> V_134 >= V_2 -> V_73 -> V_94 )
V_2 -> V_134 = 0 ;
V_23 = F_62 ( V_2 ) ;
V_120 = F_73 ( 0 , V_116 , 4096 ) ;
V_116 -> F_73 = F_67 ( V_120 ) ;
if ( F_74 ( V_2 ) )
V_27 = - V_39 ;
else {
bool V_88 ;
F_9 () ;
V_88 = F_10 ( V_2 -> V_46 -> V_14 ) -> V_89 ;
F_11 () ;
if ( V_88 ) {
if ( F_27 ( V_2 , V_2 -> V_46 , V_23 , V_30 ) ) {
V_27 = - V_39 ;
F_15 ( V_2 , 1 , V_138 ) ;
} else {
V_2 -> V_111 ++ ;
V_2 -> V_139 ++ ;
}
}
}
F_5 ( V_2 ) ;
F_66 ( V_2 ) ;
return V_27 ;
}
static int F_75 ( struct V_140 * V_141 , int V_142 )
{
struct V_143 * V_144 = F_76 ( V_141 , struct V_143 , V_141 ) ;
struct V_1 * V_2 = V_141 -> V_2 ;
int V_27 ;
V_27 = F_63 ( V_2 ) ;
V_144 -> V_27 = V_27 ;
F_77 ( & V_144 -> V_145 ) ;
return V_27 != - V_39 ? V_27 : 0 ;
}
static int F_48 ( struct V_1 * V_2 , bool V_82 )
{
if ( V_82 ) {
struct V_143 V_146 ;
F_78 ( & V_146 . V_145 ) ;
V_146 . V_141 . V_147 = F_75 ;
V_146 . V_141 . V_2 = V_2 ;
F_79 ( & V_2 -> V_84 -> V_148 , & V_146 . V_141 ) ;
F_80 ( & V_146 . V_145 ) ;
return V_146 . V_27 ;
} else
return F_63 ( V_2 ) ;
}
static int F_81 ( struct V_1 * V_2 , struct V_60 * V_68 )
{
int V_149 ;
F_39 ( & V_2 -> V_70 ) ;
V_149 = ( V_68 -> V_150 == 0 ) ;
if ( F_82 ( V_149 ) )
F_83 ( V_2 -> V_73 , V_68 ) ;
F_41 ( & V_2 -> V_70 ) ;
return V_149 ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_60 * V_68 ;
int V_75 ;
F_28 ( F_13 ( V_151 , & V_2 -> V_73 -> V_19 ) ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_73 -> V_94 ; V_75 ++ ) {
V_68 = F_72 ( V_2 -> V_73 , V_75 ) ;
if ( V_68 -> V_81 == V_130 )
continue;
F_2 ( V_2 -> V_72 , F_81 ( V_2 , V_68 ) ) ;
}
F_7 ( & V_2 -> V_72 ) ;
}
static int F_85 ( struct V_140 * V_141 , int V_142 )
{
struct V_152 * V_153 = F_76 ( V_141 , struct V_152 , V_141 ) ;
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_154 V_155 = { . V_156 = V_157 , } ;
if ( ! F_64 ( V_2 ) ) {
if ( F_86 ( & V_158 ) )
F_87 ( V_20 , L_13 ) ;
F_88 ( V_153 ) ;
return 0 ;
}
F_89 ( V_2 , F_61 ( V_153 -> V_59 ) ) ;
F_66 ( V_2 ) ;
F_88 ( V_153 ) ;
if ( F_90 ( V_2 ) <= V_2 -> V_159 ) {
switch ( V_2 -> V_6 . V_160 ) {
case V_161 : case V_162 :
case V_163 : case V_164 :
F_91 ( V_2 ) ;
default:
break;
}
}
F_92 ( V_2 , & V_155 ) ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 , T_1 V_23 ,
int V_165 , int V_166 )
{
struct V_60 * V_117 ;
struct V_152 * V_153 ;
unsigned int V_59 ;
F_28 ( F_29 ( & V_2 -> V_79 ) ) ;
V_59 = F_94 ( V_23 ) ;
V_117 = F_43 ( V_2 -> V_62 , V_59 ) ;
if ( V_117 ) {
struct V_58 * V_167 = F_37 ( V_117 , struct V_58 , V_65 ) ;
if ( V_167 -> V_65 . V_81 == V_59 ) {
if ( V_166 )
V_167 -> V_168 -= V_165 ;
else
V_167 -> V_159 += V_165 ;
if ( V_167 -> V_168 < V_167 -> V_159 ) {
F_87 ( V_20 , L_14
L_15 ,
( unsigned long long ) V_23 ,
V_167 -> V_65 . V_81 , V_167 -> V_168 ,
V_167 -> V_159 , V_165 ,
F_95 ( V_2 -> V_6 . V_160 ) ) ;
V_167 -> V_168 = F_96 ( V_2 , V_59 ) ;
}
} else {
int V_168 = F_96 ( V_2 , V_59 ) ;
if ( V_167 -> V_19 != 0 ) {
F_87 ( V_20 , L_16
L_17 ,
V_167 -> V_65 . V_81 , V_167 -> V_168 ,
V_167 -> V_19 , V_59 , V_168 ) ;
V_167 -> V_19 = 0 ;
}
if ( V_167 -> V_159 ) {
F_87 ( V_20 , L_18
L_19 ,
V_167 -> V_65 . V_81 , V_167 -> V_159 ) ;
}
V_167 -> V_168 = V_168 ;
V_167 -> V_159 = V_166 ? 0 : V_165 ;
F_49 ( V_2 -> V_62 ) ;
}
F_58 ( V_2 -> V_62 , & V_167 -> V_65 ) ;
if ( V_167 -> V_168 == V_167 -> V_159 ) {
V_167 -> V_159 = 0 ;
V_153 = F_97 ( sizeof( * V_153 ) , V_169 ) ;
if ( V_153 ) {
V_153 -> V_59 = V_167 -> V_65 . V_81 ;
V_153 -> V_141 . V_147 = F_85 ;
V_153 -> V_141 . V_2 = V_2 ;
F_79 ( & V_2 -> V_84 -> V_148 , & V_153 -> V_141 ) ;
} else {
F_87 ( V_20 , L_20 ) ;
}
}
} else {
F_14 ( V_20 , L_21 ,
V_2 -> V_170 ,
V_2 -> V_62 -> V_94 ,
V_2 -> V_62 -> V_19 ) ;
}
}
void F_98 ( struct V_1 * V_2 , unsigned long V_171 )
{
unsigned long V_172 = V_173 ;
unsigned long V_78 = V_2 -> V_174 [ V_2 -> V_175 ] ;
int V_176 = ( V_2 -> V_175 + 1 ) % V_177 ;
if ( F_99 ( V_172 , V_78 + V_178 ) ) {
if ( V_2 -> V_179 [ V_2 -> V_175 ] != V_171 &&
V_2 -> V_6 . V_160 != V_164 &&
V_2 -> V_6 . V_160 != V_163 ) {
V_2 -> V_174 [ V_176 ] = V_172 ;
V_2 -> V_179 [ V_176 ] = V_171 ;
V_2 -> V_175 = V_176 ;
}
}
}
void F_100 ( struct V_1 * V_2 , T_1 V_23 , int V_25 ,
const char * V_180 , const unsigned int line )
{
unsigned long V_181 , V_182 , V_183 ;
unsigned long V_165 = 0 ;
T_1 V_184 , V_185 ;
int F_7 = 0 ;
unsigned long V_19 ;
if ( V_25 <= 0 || ! F_101 ( V_25 , 512 ) || V_25 > V_186 ) {
F_14 ( V_20 , L_22 ,
( unsigned long long ) V_23 , V_25 ) ;
return;
}
if ( ! F_64 ( V_2 ) )
return;
V_185 = F_102 ( V_2 -> V_187 ) ;
V_184 = V_23 + ( V_25 >> 9 ) - 1 ;
if ( ! F_103 ( V_23 < V_185 ) )
goto V_40;
if ( ! F_103 ( V_184 < V_185 ) )
V_184 = V_185 - 1 ;
V_183 = F_104 ( V_185 - 1 ) ;
if ( F_36 ( V_184 < V_188 - 1 ) )
goto V_40;
if ( F_36 ( V_184 == ( V_185 - 1 ) ) )
V_182 = V_183 ;
else
V_182 = F_104 ( V_184 - ( V_188 - 1 ) ) ;
V_181 = F_104 ( V_23 + V_188 - 1 ) ;
if ( V_181 > V_182 )
goto V_40;
V_165 = F_105 ( V_2 , V_181 , V_182 ) ;
if ( V_165 ) {
F_98 ( V_2 , F_90 ( V_2 ) ) ;
F_57 ( & V_2 -> V_70 , V_19 ) ;
F_93 ( V_2 , V_23 , V_165 , true ) ;
F_59 ( & V_2 -> V_70 , V_19 ) ;
F_7 = 1 ;
}
V_40:
F_66 ( V_2 ) ;
if ( F_7 )
F_7 ( & V_2 -> V_72 ) ;
}
int F_106 ( struct V_1 * V_2 , T_1 V_23 , int V_25 ,
const char * V_180 , const unsigned int line )
{
unsigned long V_181 , V_182 , V_19 ;
T_1 V_184 , V_185 ;
unsigned int V_59 , V_165 = 0 ;
struct V_60 * V_117 ;
if ( V_25 == 0 )
return 0 ;
if ( V_25 < 0 || ! F_101 ( V_25, 512 ) || V_25 > V_186 ) {
F_14 ( V_20 , L_23 ,
( unsigned long long ) V_23 , V_25 ) ;
return 0 ;
}
if ( ! F_64 ( V_2 ) )
return 0 ;
V_185 = F_102 ( V_2 -> V_187 ) ;
V_184 = V_23 + ( V_25 >> 9 ) - 1 ;
if ( ! F_103 ( V_23 < V_185 ) )
goto V_40;
if ( ! F_103 ( V_184 < V_185 ) )
V_184 = V_185 - 1 ;
V_181 = F_104 ( V_23 ) ;
V_182 = F_104 ( V_184 ) ;
F_57 ( & V_2 -> V_70 , V_19 ) ;
V_165 = F_107 ( V_2 , V_181 , V_182 ) ;
V_59 = F_94 ( V_23 ) ;
V_117 = F_35 ( V_2 -> V_62 , V_59 ) ;
if ( V_117 )
F_37 ( V_117 , struct V_58 , V_65 ) -> V_168 += V_165 ;
F_59 ( & V_2 -> V_70 , V_19 ) ;
V_40:
F_66 ( V_2 ) ;
return V_165 ;
}
static
struct V_58 * F_108 ( struct V_1 * V_2 , unsigned int V_59 )
{
struct V_60 * V_117 ;
struct V_58 * V_64 ;
int V_189 = 0 ;
unsigned long V_190 ;
F_39 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_170 > V_2 -> V_62 -> V_94 / 2 ) {
F_41 ( & V_2 -> V_70 ) ;
return NULL ;
}
V_117 = F_43 ( V_2 -> V_62 , V_59 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( V_64 ) {
if ( V_64 -> V_65 . V_81 != V_59 ) {
V_64 -> V_168 = F_96 ( V_2 , V_59 ) ;
V_64 -> V_159 = 0 ;
F_49 ( V_2 -> V_62 ) ;
V_189 = 1 ;
}
if ( V_64 -> V_65 . V_150 == 1 )
V_2 -> V_170 ++ ;
F_109 ( V_66 , & V_64 -> V_19 ) ;
}
V_190 = V_2 -> V_62 -> V_19 ;
F_41 ( & V_2 -> V_70 ) ;
if ( V_189 )
F_7 ( & V_2 -> V_72 ) ;
if ( ! V_64 ) {
if ( V_190 & V_191 )
F_87 ( V_20 , L_24
L_25 ) ;
F_30 ( V_190 & V_192 ) ;
}
return V_64 ;
}
static int F_110 ( struct V_1 * V_2 , unsigned int V_59 )
{
int V_149 ;
F_39 ( & V_2 -> V_70 ) ;
V_149 = F_111 ( V_2 -> V_73 , V_59 ) ;
F_41 ( & V_2 -> V_70 ) ;
return V_149 ;
}
int F_112 ( struct V_1 * V_2 , T_1 V_23 )
{
unsigned int V_59 = F_94 ( V_23 ) ;
struct V_58 * V_64 ;
int V_75 , V_193 ;
int V_194 = 200 ;
V_195:
V_193 = F_113 ( V_2 -> V_72 ,
( V_64 = F_108 ( V_2 , V_59 ) ) ) ;
if ( V_193 )
return - V_196 ;
if ( F_13 ( V_197 , & V_64 -> V_19 ) )
return 0 ;
for ( V_75 = 0 ; V_75 < V_63 ; V_75 ++ ) {
V_193 = F_113 ( V_2 -> V_72 ,
! F_110 ( V_2 , V_59 * V_63 + V_75 ) ||
F_13 ( V_71 , & V_64 -> V_19 ) ) ;
if ( V_193 || ( F_13 ( V_71 , & V_64 -> V_19 ) && V_194 ) ) {
F_39 ( & V_2 -> V_70 ) ;
if ( F_58 ( V_2 -> V_62 , & V_64 -> V_65 ) == 0 ) {
V_64 -> V_19 = 0 ;
V_2 -> V_170 -- ;
F_7 ( & V_2 -> V_72 ) ;
}
F_41 ( & V_2 -> V_70 ) ;
if ( V_193 )
return - V_196 ;
if ( F_114 ( V_16 / 10 ) )
return - V_196 ;
if ( V_194 && -- V_194 == 0 )
F_87 ( V_20 , L_26
L_27 ) ;
goto V_195;
}
}
F_109 ( V_197 , & V_64 -> V_19 ) ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 , T_1 V_23 )
{
unsigned int V_59 = F_94 ( V_23 ) ;
const unsigned int V_100 = V_59 * V_63 ;
struct V_60 * V_117 ;
struct V_58 * V_64 ;
int V_75 ;
F_39 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_198 != V_130 && V_2 -> V_198 != V_59 ) {
V_117 = F_35 ( V_2 -> V_62 , V_2 -> V_198 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( V_64 ) {
F_28 ( ! F_13 ( V_197 , & V_64 -> V_19 ) ) ;
F_28 ( F_13 ( V_66 , & V_64 -> V_19 ) ) ;
F_116 ( V_66 , & V_64 -> V_19 ) ;
V_2 -> V_198 = V_130 ;
if ( F_58 ( V_2 -> V_62 , & V_64 -> V_65 ) == 0 )
V_2 -> V_170 -- ;
F_7 ( & V_2 -> V_72 ) ;
} else {
F_33 ( V_20 , L_28 ) ;
}
}
V_117 = F_42 ( V_2 -> V_62 , V_59 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( V_64 ) {
if ( F_13 ( V_197 , & V_64 -> V_19 ) )
goto V_199;
if ( ! F_40 ( V_66 , & V_64 -> V_19 ) ) {
V_2 -> V_170 ++ ;
} else {
V_64 -> V_65 . V_150 -- ;
F_28 ( V_64 -> V_65 . V_150 > 0 ) ;
}
goto V_200;
} else {
if ( V_2 -> V_170 > V_2 -> V_62 -> V_94 - 3 )
goto V_201;
V_117 = F_43 ( V_2 -> V_62 , V_59 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( ! V_64 ) {
const unsigned long V_190 = V_2 -> V_62 -> V_19 ;
if ( V_190 & V_191 )
F_87 ( V_20 , L_24
L_25 ) ;
F_30 ( V_190 & V_192 ) ;
goto V_201;
}
if ( V_64 -> V_65 . V_81 != V_59 ) {
V_64 -> V_168 = F_96 ( V_2 , V_59 ) ;
V_64 -> V_159 = 0 ;
F_49 ( V_2 -> V_62 ) ;
F_7 ( & V_2 -> V_72 ) ;
F_28 ( F_13 ( V_197 , & V_64 -> V_19 ) == 0 ) ;
}
F_109 ( V_66 , & V_64 -> V_19 ) ;
F_28 ( V_64 -> V_65 . V_150 == 1 ) ;
V_2 -> V_170 ++ ;
goto V_200;
}
V_200:
for ( V_75 = 0 ; V_75 < V_63 ; V_75 ++ ) {
if ( F_111 ( V_2 -> V_73 , V_100 + V_75 ) )
goto V_201;
}
F_109 ( V_197 , & V_64 -> V_19 ) ;
V_199:
V_2 -> V_198 = V_130 ;
F_41 ( & V_2 -> V_70 ) ;
return 0 ;
V_201:
if ( V_64 )
V_2 -> V_198 = V_59 ;
F_41 ( & V_2 -> V_70 ) ;
return - V_202 ;
}
void F_117 ( struct V_1 * V_2 , T_1 V_23 )
{
unsigned int V_59 = F_94 ( V_23 ) ;
struct V_60 * V_117 ;
struct V_58 * V_64 ;
unsigned long V_19 ;
F_57 ( & V_2 -> V_70 , V_19 ) ;
V_117 = F_35 ( V_2 -> V_62 , V_59 ) ;
V_64 = V_117 ? F_37 ( V_117 , struct V_58 , V_65 ) : NULL ;
if ( ! V_64 ) {
F_59 ( & V_2 -> V_70 , V_19 ) ;
if ( F_86 ( & V_158 ) )
F_14 ( V_20 , L_29 ) ;
return;
}
if ( V_64 -> V_65 . V_150 == 0 ) {
F_59 ( & V_2 -> V_70 , V_19 ) ;
F_14 ( V_20 , L_30
L_31 ,
( unsigned long long ) V_23 , V_59 ) ;
return;
}
if ( F_58 ( V_2 -> V_62 , & V_64 -> V_65 ) == 0 ) {
V_64 -> V_19 = 0 ;
V_2 -> V_170 -- ;
F_7 ( & V_2 -> V_72 ) ;
}
F_59 ( & V_2 -> V_70 , V_19 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_70 ) ;
if ( F_19 ( V_2 , V_8 ) ) {
F_119 ( V_2 -> V_62 ) ;
F_66 ( V_2 ) ;
}
V_2 -> V_170 = 0 ;
V_2 -> V_198 = V_130 ;
F_41 ( & V_2 -> V_70 ) ;
F_7 ( & V_2 -> V_72 ) ;
}
int F_120 ( struct V_1 * V_2 )
{
struct V_60 * V_117 ;
struct V_58 * V_64 ;
int V_75 ;
F_39 ( & V_2 -> V_70 ) ;
if ( F_19 ( V_2 , V_8 ) ) {
for ( V_75 = 0 ; V_75 < V_2 -> V_62 -> V_94 ; V_75 ++ ) {
V_117 = F_72 ( V_2 -> V_62 , V_75 ) ;
V_64 = F_37 ( V_117 , struct V_58 , V_65 ) ;
if ( V_64 -> V_65 . V_81 == V_130 )
continue;
if ( V_64 -> V_65 . V_81 == V_2 -> V_198 ) {
F_55 ( V_20 , L_32
L_33 ,
V_2 -> V_198 ) ;
F_28 ( ! F_13 ( V_197 , & V_64 -> V_19 ) ) ;
F_28 ( F_13 ( V_66 , & V_64 -> V_19 ) ) ;
F_116 ( V_66 , & V_64 -> V_19 ) ;
V_2 -> V_198 = V_130 ;
F_58 ( V_2 -> V_62 , & V_64 -> V_65 ) ;
}
if ( V_64 -> V_65 . V_150 != 0 ) {
F_55 ( V_20 , L_34
L_35 , V_64 -> V_65 . V_150 ) ;
F_66 ( V_2 ) ;
F_41 ( & V_2 -> V_70 ) ;
return - V_202 ;
}
F_28 ( ! F_13 ( V_197 , & V_64 -> V_19 ) ) ;
F_28 ( ! F_13 ( V_66 , & V_64 -> V_19 ) ) ;
F_83 ( V_2 -> V_62 , & V_64 -> V_65 ) ;
}
F_28 ( V_2 -> V_62 -> V_95 == 0 ) ;
F_66 ( V_2 ) ;
}
F_41 ( & V_2 -> V_70 ) ;
F_7 ( & V_2 -> V_72 ) ;
return 0 ;
}
void F_121 ( struct V_1 * V_2 , T_1 V_23 , int V_25 )
{
unsigned long V_181 , V_182 , V_183 ;
unsigned long V_165 ;
T_1 V_184 , V_185 ;
int F_7 = 0 ;
if ( V_25 <= 0 || ! F_101 ( V_25 , 512 ) || V_25 > V_186 ) {
F_14 ( V_20 , L_36 ,
( unsigned long long ) V_23 , V_25 ) ;
return;
}
V_185 = F_102 ( V_2 -> V_187 ) ;
V_184 = V_23 + ( V_25 >> 9 ) - 1 ;
if ( ! F_103 ( V_23 < V_185 ) )
return;
if ( ! F_103 ( V_184 < V_185 ) )
V_184 = V_185 - 1 ;
V_183 = F_104 ( V_185 - 1 ) ;
if ( F_36 ( V_184 < V_188 - 1 ) )
return;
if ( F_36 ( V_184 == ( V_185 - 1 ) ) )
V_182 = V_183 ;
else
V_182 = F_104 ( V_184 - ( V_188 - 1 ) ) ;
V_181 = F_104 ( V_23 + V_188 - 1 ) ;
if ( V_181 > V_182 )
return;
F_39 ( & V_2 -> V_70 ) ;
V_165 = F_122 ( V_2 , V_181 , V_182 ) ;
if ( V_165 ) {
V_2 -> V_159 += V_165 ;
if ( F_64 ( V_2 ) ) {
F_93 ( V_2 , V_23 , V_165 , false ) ;
F_66 ( V_2 ) ;
}
F_7 = 1 ;
}
F_41 ( & V_2 -> V_70 ) ;
if ( F_7 )
F_7 ( & V_2 -> V_72 ) ;
}
