static inline unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_11 = 0 , V_12 ;
T_1 V_13 , V_14 , V_15 ;
if ( V_7 -> V_8 -> V_16 ) {
F_7 ( V_2 -> V_17 , L_1 ) ;
return - V_18 ;
}
if ( ! V_2 -> V_19 ) {
F_8 ( V_2 -> V_17 , L_2 ) ;
return - V_20 ;
}
V_14 = F_9 ( V_2 -> V_21 ) ;
V_11 = F_10 ( V_14 , V_2 -> V_19 ) - 1 ;
if ( V_11 < 0 ) {
F_7 ( V_2 -> V_17 , L_3 ) ;
return - V_20 ;
}
if ( V_11 > V_22 ) {
F_7 ( V_2 -> V_17 , L_4 ,
V_22 , V_22 + 1 ) ;
return - V_20 ;
}
F_7 ( V_2 -> V_17 , L_5 ,
V_2 -> V_19 , V_11 ) ;
V_12 = F_11 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_6 ) ;
return V_12 ;
}
V_13 = F_1 ( V_2 , V_23 ) ;
V_13 &= ~ V_24 ;
F_3 ( V_2 , V_13 , V_23 ) ;
V_15 = V_24 | V_11 ;
F_3 ( V_2 , V_15 , V_23 ) ;
V_10 -> V_25 = V_15 ;
F_12 ( V_2 -> V_17 ) ;
V_12 = F_13 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_7 ) ;
return V_12 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_3 ( V_2 , V_10 -> V_25 , V_23 ) ;
}
static inline T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_26 ;
unsigned long V_27 = V_28 + V_29 ;
V_26 = F_1 ( V_2 , V_30 ) ;
while ( ( V_26 & V_31 ) && F_16 ( V_27 , V_28 ) ) {
F_17 () ;
V_26 = F_1 ( V_2 , V_30 ) ;
}
F_18 ( V_26 & V_31 , L_8 ) ;
return V_26 & V_31 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
T_1 V_26 ;
unsigned long V_27 = V_28 + V_29 ;
do {
V_26 = F_1 ( V_2 , V_30 ) ;
if ( V_26 & V_32 )
return 0 ;
F_17 () ;
} while ( F_16 ( V_27 , V_28 ) );
V_26 = F_1 ( V_2 , V_30 ) ;
if ( V_26 & V_32 )
return 0 ;
return - V_33 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 )
{
int V_37 , V_38 ;
unsigned int V_39 ;
const T_2 * V_40 ;
T_1 V_41 ;
V_40 = V_35 -> V_42 ;
V_39 = V_2 -> V_39 | V_43 ;
V_37 = V_35 -> V_44 >> 3 ;
V_38 = V_37 ;
while ( V_36 ) {
if ( F_15 ( V_2 ) )
return - V_18 ;
switch ( V_37 ) {
case 1 :
F_7 ( V_2 -> V_17 , L_9 ,
V_39 , V_2 -> V_45 , * V_40 ) ;
if ( V_36 >= V_46 ) {
T_1 * V_47 = ( T_1 * ) V_40 ;
V_41 = F_21 ( * V_47 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_48 ) ;
V_41 = F_21 ( * V_47 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_49 ) ;
V_41 = F_21 ( * V_47 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_50 ) ;
V_41 = F_21 ( * V_47 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_51 ) ;
V_38 = V_46 ;
V_39 |= F_22 ( V_52 ) ;
} else {
F_23 ( * V_40 , V_2 -> V_4 + V_51 ) ;
V_39 = V_2 -> V_39 | V_43 ;
V_38 = V_37 ;
V_39 |= F_22 ( V_37 ) ;
}
break;
case 2 :
F_7 ( V_2 -> V_17 , L_10 ,
V_39 , V_2 -> V_45 , * V_40 ) ;
F_24 ( * ( ( V_53 * ) V_40 ) , V_2 -> V_4 + V_51 ) ;
break;
case 4 :
F_7 ( V_2 -> V_17 , L_11 ,
V_39 , V_2 -> V_45 , * V_40 ) ;
F_4 ( * ( ( T_1 * ) V_40 ) , V_2 -> V_4 + V_51 ) ;
break;
}
F_3 ( V_2 , V_39 , V_54 ) ;
if ( F_19 ( V_2 ) ) {
F_8 ( V_2 -> V_17 , L_12 ) ;
return - V_33 ;
}
V_40 += V_38 ;
V_36 -= V_38 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 )
{
int V_37 ;
unsigned int V_39 ;
T_2 * V_55 ;
V_55 = V_35 -> V_56 ;
V_39 = V_2 -> V_39 ;
switch ( V_35 -> V_57 ) {
case V_58 :
V_39 |= V_59 ;
break;
case V_60 :
V_39 |= V_61 ;
break;
default:
V_39 |= V_62 ;
break;
}
V_37 = V_35 -> V_44 >> 3 ;
while ( V_36 ) {
F_7 ( V_2 -> V_17 , L_13 , V_39 , V_2 -> V_45 ) ;
if ( F_15 ( V_2 ) )
return - V_18 ;
F_3 ( V_2 , V_39 , V_54 ) ;
if ( F_19 ( V_2 ) ) {
F_8 ( V_2 -> V_17 , L_14 ) ;
return - V_33 ;
}
switch ( V_37 ) {
case 1 :
* V_55 = F_26 ( V_2 -> V_4 + V_51 ) ;
break;
case 2 :
* ( ( V_53 * ) V_55 ) = F_27 ( V_2 -> V_4 + V_51 ) ;
break;
case 4 :
* ( ( T_1 * ) V_55 ) = F_2 ( V_2 -> V_4 + V_51 ) ;
break;
}
V_55 += V_37 ;
V_36 -= V_37 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 )
{
int V_12 ;
if ( V_35 -> V_42 ) {
V_12 = F_20 ( V_2 , V_35 , V_36 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_15 ) ;
return V_12 ;
}
}
if ( V_35 -> V_56 ) {
V_12 = F_25 ( V_2 , V_35 , V_36 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_16 ) ;
return V_12 ;
}
}
return 0 ;
}
static void F_29 ( void * V_63 )
{
struct V_1 * V_2 = V_63 ;
F_30 ( & V_2 -> V_64 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_3 V_65 ,
T_3 V_66 , T_4 V_67 )
{
struct V_68 * V_69 = V_2 -> V_70 ;
struct V_71 * V_72 = V_69 -> V_73 ;
T_5 V_74 ;
enum V_75 V_76 = V_77 | V_78 ;
struct V_79 * V_80 ;
int V_12 ;
V_80 = V_72 -> V_81 ( V_69 , V_65 , V_66 ,
V_67 , V_76 ) ;
if ( ! V_80 ) {
F_8 ( V_2 -> V_17 , L_17 ) ;
return - V_82 ;
}
V_80 -> V_83 = F_29 ;
V_80 -> V_84 = V_2 ;
V_74 = V_80 -> V_85 ( V_80 ) ;
F_32 ( & V_2 -> V_64 ) ;
V_12 = F_33 ( V_74 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_17 , L_18 , V_74 ) ;
return - V_82 ;
}
F_34 ( V_69 ) ;
V_12 = F_35 ( & V_2 -> V_64 ,
F_36 ( V_67 ) ) ;
if ( V_12 <= 0 ) {
F_37 ( V_69 ) ;
F_8 ( V_2 -> V_17 , L_19 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_86 V_87 ,
T_6 V_88 )
{
struct V_89 * V_90 ;
T_3 V_66 = V_2 -> V_91 + V_88 ;
T_3 V_65 ;
int V_92 , V_67 , V_12 ;
F_39 (rx_sg.sgl, sg, rx_sg.nents, i) {
V_65 = F_40 ( V_90 ) ;
V_67 = F_41 ( V_90 ) ;
V_12 = F_31 ( V_2 , V_65 , V_66 , V_67 ) ;
if ( V_12 )
return V_12 ;
V_66 += V_67 ;
}
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
F_3 ( V_2 , V_93 , V_94 ) ;
if ( V_2 -> V_95 ) {
F_43 ( V_2 -> V_95 , V_2 -> V_96 ,
F_44 ( V_7 -> V_97 ) ,
V_98 ) ;
}
V_2 -> V_99 = true ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
F_3 ( V_2 , 0 , V_94 ) ;
if ( V_2 -> V_95 )
F_43 ( V_2 -> V_95 , V_2 -> V_96 ,
0 , V_98 ) ;
V_2 -> V_99 = false ;
}
static void F_46 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
T_1 V_102 = V_101 -> V_103 ;
switch ( V_101 -> V_104 ) {
case V_60 :
V_102 |= V_105 ;
break;
case V_58 :
V_102 |= V_106 ;
break;
default:
V_102 |= V_107 ;
break;
}
V_102 |= ( ( V_101 -> V_108 - 1 ) << V_109 |
V_101 -> V_110 << V_111 ) ;
F_3 ( V_2 , V_102 ,
F_47 ( V_7 -> V_97 ) ) ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
int V_12 = 0 ;
F_49 ( & V_2 -> V_112 ) ;
if ( ! V_2 -> V_99 )
F_42 ( V_7 ) ;
F_46 ( V_7 , V_101 ) ;
if ( V_2 -> V_70 ) {
if ( V_101 -> V_113 ) {
V_12 = F_38 ( V_2 , V_101 -> V_87 , V_101 -> V_88 ) ;
if ( V_12 )
goto V_114;
} else {
F_8 ( V_2 -> V_17 , L_20 ) ;
V_12 = - V_82 ;
goto V_114;
}
} else {
F_50 ( V_101 -> V_115 , V_2 -> V_116 + V_101 -> V_88 , V_101 -> V_67 ) ;
}
V_101 -> V_117 = V_101 -> V_67 ;
V_114:
F_51 ( & V_2 -> V_112 ) ;
return V_12 ;
}
static int F_52 ( struct V_118 * V_8 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_6 * V_7 = V_120 -> V_7 ;
struct V_34 * V_35 ;
int V_121 = 0 , V_12 ;
unsigned int V_122 , V_123 ;
int V_37 ;
V_2 -> V_45 = 0 ;
if ( V_7 -> V_124 & V_125 )
V_2 -> V_45 |= F_53 ( V_7 -> V_97 ) ;
if ( V_7 -> V_124 & V_126 )
V_2 -> V_45 |= F_54 ( V_7 -> V_97 ) ;
if ( V_7 -> V_124 & V_127 )
V_2 -> V_45 |= F_55 ( V_7 -> V_97 ) ;
V_122 = 0 ;
F_56 (t, &m->transfers, transfer_list)
V_122 += V_35 -> V_67 / ( V_35 -> V_44 >> 3 ) ;
V_122 = F_57 (unsigned int, frame_len_words, QSPI_FRAME) ;
V_2 -> V_39 = 0 ;
V_2 -> V_39 |= F_58 ( V_7 -> V_97 ) ;
V_2 -> V_39 |= F_59 ( V_122 ) ;
F_3 ( V_2 , V_2 -> V_45 , V_128 ) ;
F_49 ( & V_2 -> V_112 ) ;
if ( V_2 -> V_99 )
F_45 ( V_7 ) ;
F_56 (t, &m->transfers, transfer_list) {
V_2 -> V_39 = ( ( V_2 -> V_39 & ~ V_129 ) |
F_22 ( V_35 -> V_44 ) ) ;
V_37 = V_35 -> V_44 >> 3 ;
V_123 = F_60 ( V_35 -> V_67 / V_37 , V_122 ) ;
V_12 = F_28 ( V_2 , V_35 , V_123 * V_37 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_21 ) ;
F_51 ( & V_2 -> V_112 ) ;
return - V_20 ;
}
V_120 -> V_130 += V_123 * V_37 ;
V_122 -= V_123 ;
if ( V_122 == 0 )
break;
}
F_51 ( & V_2 -> V_112 ) ;
F_3 ( V_2 , V_2 -> V_39 | V_131 , V_54 ) ;
V_120 -> V_121 = V_121 ;
F_61 ( V_8 ) ;
return V_121 ;
}
static int F_62 ( struct V_73 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_63 ( V_17 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_132 * V_133 )
{
struct V_1 * V_2 ;
struct V_118 * V_8 ;
struct V_134 * V_135 , * V_136 ;
struct V_137 * V_138 = V_133 -> V_17 . V_139 ;
T_1 V_140 ;
int V_12 = 0 , V_141 , V_142 ;
T_7 V_143 ;
V_8 = F_65 ( & V_133 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_144 ;
V_8 -> V_145 = V_126 | V_125 | V_146 | V_147 ;
V_8 -> V_76 = V_148 ;
V_8 -> V_149 = F_5 ;
V_8 -> V_150 = true ;
V_8 -> V_151 = F_52 ;
V_8 -> V_17 . V_139 = V_133 -> V_17 . V_139 ;
V_8 -> V_152 = F_66 ( 32 ) | F_66 ( 16 ) |
F_66 ( 8 ) ;
V_8 -> V_153 = F_48 ;
if ( ! F_67 ( V_138 , L_22 , & V_141 ) )
V_8 -> V_154 = V_141 ;
V_2 = F_6 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = & V_133 -> V_17 ;
F_68 ( V_133 , V_2 ) ;
V_135 = F_69 ( V_133 , V_155 , L_23 ) ;
if ( V_135 == NULL ) {
V_135 = F_70 ( V_133 , V_155 , 0 ) ;
if ( V_135 == NULL ) {
F_8 ( & V_133 -> V_17 , L_24 ) ;
V_12 = - V_156 ;
goto V_157;
}
}
V_136 = F_69 ( V_133 ,
V_155 , L_25 ) ;
if ( V_136 == NULL ) {
V_136 = F_70 ( V_133 , V_155 , 1 ) ;
if ( V_136 == NULL ) {
F_8 ( & V_133 -> V_17 ,
L_26 ) ;
}
}
V_142 = F_71 ( V_133 , 0 ) ;
if ( V_142 < 0 ) {
F_8 ( & V_133 -> V_17 , L_27 ) ;
V_12 = V_142 ;
goto V_157;
}
F_72 ( & V_2 -> V_112 ) ;
V_2 -> V_4 = F_73 ( & V_133 -> V_17 , V_135 ) ;
if ( F_74 ( V_2 -> V_4 ) ) {
V_12 = F_75 ( V_2 -> V_4 ) ;
goto V_157;
}
if ( F_76 ( V_138 , L_28 ) ) {
V_2 -> V_95 =
F_77 ( V_138 ,
L_28 ) ;
if ( F_74 ( V_2 -> V_95 ) ) {
V_12 = F_75 ( V_2 -> V_95 ) ;
goto V_157;
}
V_12 = F_78 ( V_138 ,
L_28 ,
1 , & V_2 -> V_96 ) ;
if ( V_12 ) {
F_8 ( & V_133 -> V_17 ,
L_29 ) ;
goto V_157;
}
}
V_2 -> V_21 = F_79 ( & V_133 -> V_17 , L_30 ) ;
if ( F_74 ( V_2 -> V_21 ) ) {
V_12 = F_75 ( V_2 -> V_21 ) ;
F_8 ( & V_133 -> V_17 , L_31 , V_12 ) ;
}
F_80 ( & V_133 -> V_17 ) ;
F_81 ( & V_133 -> V_17 , V_158 ) ;
F_82 ( & V_133 -> V_17 ) ;
if ( ! F_67 ( V_138 , L_32 , & V_140 ) )
V_2 -> V_19 = V_140 ;
F_83 ( V_143 ) ;
F_84 ( V_159 , V_143 ) ;
V_2 -> V_70 = F_85 ( & V_143 ) ;
if ( F_74 ( V_2 -> V_70 ) ) {
F_8 ( V_2 -> V_17 ,
L_33 ) ;
V_2 -> V_70 = NULL ;
V_12 = 0 ;
goto V_160;
}
V_8 -> V_161 = V_2 -> V_70 ;
F_86 ( & V_2 -> V_64 ) ;
if ( V_136 )
V_2 -> V_91 = ( T_3 ) V_136 -> V_162 ;
V_160:
if ( ! V_2 -> V_70 && V_136 ) {
V_2 -> V_116 = F_73 ( & V_133 -> V_17 , V_136 ) ;
if ( F_74 ( V_2 -> V_116 ) ) {
F_87 ( & V_133 -> V_17 ,
L_34 ,
F_75 ( V_2 -> V_116 ) ) ;
V_2 -> V_116 = NULL ;
V_8 -> V_153 = NULL ;
}
}
V_2 -> V_99 = false ;
V_12 = F_88 ( & V_133 -> V_17 , V_8 ) ;
if ( ! V_12 )
return 0 ;
F_89 ( & V_133 -> V_17 ) ;
V_157:
F_90 ( V_8 ) ;
return V_12 ;
}
static int F_91 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_92 ( V_133 ) ;
int V_163 ;
V_163 = F_93 ( V_2 -> V_8 ) ;
if ( V_163 )
return V_163 ;
F_94 ( & V_133 -> V_17 ) ;
F_89 ( & V_133 -> V_17 ) ;
if ( V_2 -> V_70 )
F_95 ( V_2 -> V_70 ) ;
return 0 ;
}
