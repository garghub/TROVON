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
T_5 V_71 ;
enum V_72 V_73 = V_74 | V_75 ;
struct V_76 * V_77 ;
int V_12 ;
V_77 = F_32 ( V_69 , V_65 , V_66 , V_67 , V_73 ) ;
if ( ! V_77 ) {
F_8 ( V_2 -> V_17 , L_17 ) ;
return - V_78 ;
}
V_77 -> V_79 = F_29 ;
V_77 -> V_80 = V_2 ;
V_71 = V_77 -> V_81 ( V_77 ) ;
F_33 ( & V_2 -> V_64 ) ;
V_12 = F_34 ( V_71 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_17 , L_18 , V_71 ) ;
return - V_78 ;
}
F_35 ( V_69 ) ;
V_12 = F_36 ( & V_2 -> V_64 ,
F_37 ( V_67 ) ) ;
if ( V_12 <= 0 ) {
F_38 ( V_69 ) ;
F_8 ( V_2 -> V_17 , L_19 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
T_4 V_84 = V_83 -> V_67 ;
void * V_85 = V_83 -> V_86 ;
T_3 V_66 = V_2 -> V_87 + V_83 -> V_88 ;
int V_12 = 0 ;
while ( V_84 != 0 ) {
T_4 V_38 = F_40 ( T_4 , V_89 ,
V_84 ) ;
V_12 = F_31 ( V_2 , V_2 -> V_90 ,
V_66 , V_38 ) ;
if ( V_12 != 0 )
return V_12 ;
memcpy ( V_85 , V_2 -> V_91 , V_38 ) ;
V_84 -= V_38 ;
V_66 += V_38 ;
V_85 += V_38 ;
}
return V_12 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_92 V_93 ,
T_6 V_88 )
{
struct V_94 * V_95 ;
T_3 V_66 = V_2 -> V_87 + V_88 ;
T_3 V_65 ;
int V_96 , V_67 , V_12 ;
F_42 (rx_sg.sgl, sg, rx_sg.nents, i) {
V_65 = F_43 ( V_95 ) ;
V_67 = F_44 ( V_95 ) ;
V_12 = F_31 ( V_2 , V_65 , V_66 , V_67 ) ;
if ( V_12 )
return V_12 ;
V_66 += V_67 ;
}
return 0 ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
F_3 ( V_2 , V_97 , V_98 ) ;
if ( V_2 -> V_99 ) {
F_46 ( V_2 -> V_99 , V_2 -> V_100 ,
F_47 ( V_7 -> V_101 ) ,
V_102 ) ;
}
V_2 -> V_103 = true ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
F_3 ( V_2 , 0 , V_98 ) ;
if ( V_2 -> V_99 )
F_46 ( V_2 -> V_99 , V_2 -> V_100 ,
0 , V_102 ) ;
V_2 -> V_103 = false ;
}
static void F_49 ( struct V_6 * V_7 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
T_1 V_104 = V_83 -> V_105 ;
switch ( V_83 -> V_106 ) {
case V_60 :
V_104 |= V_107 ;
break;
case V_58 :
V_104 |= V_108 ;
break;
default:
V_104 |= V_109 ;
break;
}
V_104 |= ( ( V_83 -> V_110 - 1 ) << V_111 |
V_83 -> V_112 << V_113 ) ;
F_3 ( V_2 , V_104 ,
F_50 ( V_7 -> V_101 ) ) ;
}
static bool F_51 ( struct V_6 * V_7 ,
struct V_82 * V_83 )
{
return F_52 ( V_83 -> V_86 ) ;
}
static int F_53 ( struct V_6 * V_7 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
int V_12 = 0 ;
F_54 ( & V_2 -> V_114 ) ;
if ( ! V_2 -> V_103 )
F_45 ( V_7 ) ;
F_49 ( V_7 , V_83 ) ;
if ( V_2 -> V_70 ) {
if ( V_83 -> V_115 )
V_12 = F_41 ( V_2 , V_83 -> V_93 , V_83 -> V_88 ) ;
else
V_12 = F_39 ( V_2 , V_83 ) ;
if ( V_12 )
goto V_116;
} else {
F_55 ( V_83 -> V_86 , V_2 -> V_117 + V_83 -> V_88 , V_83 -> V_67 ) ;
}
V_83 -> V_118 = V_83 -> V_67 ;
V_116:
F_56 ( & V_2 -> V_114 ) ;
return V_12 ;
}
static int F_57 ( struct V_119 * V_8 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_6 * V_7 = V_121 -> V_7 ;
struct V_34 * V_35 ;
int V_122 = 0 , V_12 ;
unsigned int V_123 , V_124 ;
int V_37 ;
V_2 -> V_45 = 0 ;
if ( V_7 -> V_125 & V_126 )
V_2 -> V_45 |= F_58 ( V_7 -> V_101 ) ;
if ( V_7 -> V_125 & V_127 )
V_2 -> V_45 |= F_59 ( V_7 -> V_101 ) ;
if ( V_7 -> V_125 & V_128 )
V_2 -> V_45 |= F_60 ( V_7 -> V_101 ) ;
V_123 = 0 ;
F_61 (t, &m->transfers, transfer_list)
V_123 += V_35 -> V_67 / ( V_35 -> V_44 >> 3 ) ;
V_123 = F_40 (unsigned int, frame_len_words, QSPI_FRAME) ;
V_2 -> V_39 = 0 ;
V_2 -> V_39 |= F_62 ( V_7 -> V_101 ) ;
V_2 -> V_39 |= F_63 ( V_123 ) ;
F_3 ( V_2 , V_2 -> V_45 , V_129 ) ;
F_54 ( & V_2 -> V_114 ) ;
if ( V_2 -> V_103 )
F_48 ( V_7 ) ;
F_61 (t, &m->transfers, transfer_list) {
V_2 -> V_39 = ( ( V_2 -> V_39 & ~ V_130 ) |
F_22 ( V_35 -> V_44 ) ) ;
V_37 = V_35 -> V_44 >> 3 ;
V_124 = F_64 ( V_35 -> V_67 / V_37 , V_123 ) ;
V_12 = F_28 ( V_2 , V_35 , V_124 * V_37 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_20 ) ;
F_56 ( & V_2 -> V_114 ) ;
return - V_20 ;
}
V_121 -> V_131 += V_124 * V_37 ;
V_123 -= V_124 ;
if ( V_123 == 0 )
break;
}
F_56 ( & V_2 -> V_114 ) ;
F_3 ( V_2 , V_2 -> V_39 | V_132 , V_54 ) ;
V_121 -> V_122 = V_122 ;
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_66 ( struct V_133 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_67 ( V_17 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_68 ( struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_119 * V_8 ;
struct V_136 * V_137 , * V_138 ;
struct V_139 * V_140 = V_135 -> V_17 . V_141 ;
T_1 V_142 ;
int V_12 = 0 , V_143 , V_144 ;
T_7 V_145 ;
V_8 = F_69 ( & V_135 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_146 ;
V_8 -> V_147 = V_127 | V_126 | V_148 | V_149 ;
V_8 -> V_73 = V_150 ;
V_8 -> V_151 = F_5 ;
V_8 -> V_152 = true ;
V_8 -> V_153 = F_57 ;
V_8 -> V_17 . V_141 = V_135 -> V_17 . V_141 ;
V_8 -> V_154 = F_70 ( 32 ) | F_70 ( 16 ) |
F_70 ( 8 ) ;
V_8 -> V_155 = F_53 ;
if ( ! F_71 ( V_140 , L_21 , & V_143 ) )
V_8 -> V_156 = V_143 ;
V_2 = F_6 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = & V_135 -> V_17 ;
F_72 ( V_135 , V_2 ) ;
V_137 = F_73 ( V_135 , V_157 , L_22 ) ;
if ( V_137 == NULL ) {
V_137 = F_74 ( V_135 , V_157 , 0 ) ;
if ( V_137 == NULL ) {
F_8 ( & V_135 -> V_17 , L_23 ) ;
V_12 = - V_158 ;
goto V_159;
}
}
V_138 = F_73 ( V_135 ,
V_157 , L_24 ) ;
if ( V_138 == NULL ) {
V_138 = F_74 ( V_135 , V_157 , 1 ) ;
if ( V_138 == NULL ) {
F_8 ( & V_135 -> V_17 ,
L_25 ) ;
}
}
V_144 = F_75 ( V_135 , 0 ) ;
if ( V_144 < 0 ) {
F_8 ( & V_135 -> V_17 , L_26 ) ;
V_12 = V_144 ;
goto V_159;
}
F_76 ( & V_2 -> V_114 ) ;
V_2 -> V_4 = F_77 ( & V_135 -> V_17 , V_137 ) ;
if ( F_78 ( V_2 -> V_4 ) ) {
V_12 = F_79 ( V_2 -> V_4 ) ;
goto V_159;
}
if ( F_80 ( V_140 , L_27 ) ) {
V_2 -> V_99 =
F_81 ( V_140 ,
L_27 ) ;
if ( F_78 ( V_2 -> V_99 ) ) {
V_12 = F_79 ( V_2 -> V_99 ) ;
goto V_159;
}
V_12 = F_82 ( V_140 ,
L_27 ,
1 , & V_2 -> V_100 ) ;
if ( V_12 ) {
F_8 ( & V_135 -> V_17 ,
L_28 ) ;
goto V_159;
}
}
V_2 -> V_21 = F_83 ( & V_135 -> V_17 , L_29 ) ;
if ( F_78 ( V_2 -> V_21 ) ) {
V_12 = F_79 ( V_2 -> V_21 ) ;
F_8 ( & V_135 -> V_17 , L_30 , V_12 ) ;
}
F_84 ( & V_135 -> V_17 ) ;
F_85 ( & V_135 -> V_17 , V_160 ) ;
F_86 ( & V_135 -> V_17 ) ;
if ( ! F_71 ( V_140 , L_31 , & V_142 ) )
V_2 -> V_19 = V_142 ;
F_87 ( V_145 ) ;
F_88 ( V_161 , V_145 ) ;
V_2 -> V_70 = F_89 ( & V_145 ) ;
if ( F_78 ( V_2 -> V_70 ) ) {
F_8 ( V_2 -> V_17 ,
L_32 ) ;
V_2 -> V_70 = NULL ;
V_12 = 0 ;
goto V_162;
}
V_2 -> V_91 = F_90 ( V_2 -> V_17 ,
V_89 ,
& V_2 -> V_90 ,
V_163 | V_164 ) ;
if ( ! V_2 -> V_91 ) {
F_8 ( V_2 -> V_17 ,
L_33 ) ;
F_91 ( V_2 -> V_70 ) ;
goto V_162;
}
V_8 -> V_165 = F_51 ;
V_8 -> V_166 = V_2 -> V_70 ;
F_92 ( & V_2 -> V_64 ) ;
if ( V_138 )
V_2 -> V_87 = ( T_3 ) V_138 -> V_167 ;
V_162:
if ( ! V_2 -> V_70 && V_138 ) {
V_2 -> V_117 = F_77 ( & V_135 -> V_17 , V_138 ) ;
if ( F_78 ( V_2 -> V_117 ) ) {
F_93 ( & V_135 -> V_17 ,
L_34 ,
F_79 ( V_2 -> V_117 ) ) ;
V_2 -> V_117 = NULL ;
V_8 -> V_155 = NULL ;
}
}
V_2 -> V_103 = false ;
V_12 = F_94 ( & V_135 -> V_17 , V_8 ) ;
if ( ! V_12 )
return 0 ;
F_95 ( & V_135 -> V_17 ) ;
V_159:
F_96 ( V_8 ) ;
return V_12 ;
}
static int F_97 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_98 ( V_135 ) ;
int V_168 ;
V_168 = F_99 ( V_2 -> V_8 ) ;
if ( V_168 )
return V_168 ;
F_100 ( & V_135 -> V_17 ) ;
F_95 ( & V_135 -> V_17 ) ;
if ( V_2 -> V_91 )
F_101 ( V_2 -> V_17 , V_89 ,
V_2 -> V_91 ,
V_2 -> V_90 ) ;
if ( V_2 -> V_70 )
F_91 ( V_2 -> V_70 ) ;
return 0 ;
}
