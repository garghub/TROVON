static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_1 T_2 * V_11 = & V_10 -> V_11 ;
unsigned long V_12 ;
if ( V_7 -> V_13 == F_3 ( V_11 ) )
return;
F_4 ( V_12 ) ;
F_5 ( V_11 , V_7 -> V_13 & ~ V_14 ) ;
if ( V_4 -> V_12 & V_15 ) {
if ( V_4 -> V_12 & V_16 ) {
F_6 ( V_17 , V_4 -> V_18 ,
V_19 , 0 ) ;
} else {
F_7 ( V_20 , V_21 ) ;
if ( V_4 -> V_12 & V_22 ) {
F_8 ( & V_4 -> V_23 -> V_24 ,
F_9 ( & V_4 -> V_23 -> V_25 ) ) ;
F_8 ( & V_4 -> V_23 -> V_26 ,
F_9 ( & V_4 -> V_23 -> V_27 ) ) ;
}
}
}
F_5 ( V_11 , V_7 -> V_13 ) ;
F_10 ( V_12 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
struct V_29 * V_30 ;
bool V_31 = V_2 -> V_11 & V_32 ;
struct V_6 * V_7 = V_2 -> V_8 ;
V_30 = V_2 -> V_33 . V_34 -> V_34 -> V_35 ;
if ( V_28 == V_36 ) {
if ( V_30 -> V_37 )
V_30 -> V_37 ( V_2 , ! V_31 ) ;
}
if ( V_28 == V_38 ) {
V_3 -> V_39 = V_7 -> V_39 ;
V_3 -> V_40 = V_7 -> V_40 ;
V_3 -> V_41 = V_7 -> V_41 ;
V_3 -> V_42 = V_7 -> V_42 ;
F_1 ( V_2 ) ;
if ( V_30 -> V_37 )
V_30 -> V_37 ( V_2 , V_31 ) ;
}
}
static int F_12 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_3 * V_3 ,
int V_43 )
{
V_7 -> V_39 = 0 ;
V_7 -> V_40 = 0 ;
if ( V_43 <= 8 ) {
V_7 -> V_41 = V_44 ;
V_7 -> V_42 = V_45 ;
if ( V_3 -> V_12 & V_46 ) {
V_7 -> V_39 = 16 ;
V_7 -> V_40 = 24 ;
}
} else if ( V_43 <= 16 ) {
V_7 -> V_41 = V_47 ;
V_7 -> V_42 = V_48 ;
if ( V_3 -> V_12 & V_46 ) {
V_7 -> V_39 = 16 ;
V_7 -> V_40 = 16 ;
}
} else if ( V_43 <= 32 ) {
V_7 -> V_41 = V_49 ;
V_7 -> V_42 = V_50 ;
} else
return - V_51 ;
if ( V_3 -> V_12 & V_46 &&
V_2 -> V_11 & V_52 ) {
V_7 -> V_40 = 0 ;
if ( V_43 <= 8 )
V_7 -> V_39 = 8 ;
else
V_7 -> V_39 = 0 ;
}
V_3 -> V_39 = V_7 -> V_39 ;
V_3 -> V_40 = V_7 -> V_40 ;
V_3 -> V_41 = V_7 -> V_41 ;
V_3 -> V_42 = V_7 -> V_42 ;
return V_43 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
int V_43 )
{
if ( V_2 -> V_11 & V_52 &&
V_43 > 8 )
return - V_51 ;
if ( V_43 > 8 )
return 8 ;
return V_43 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_3 ;
int V_43 = 0 ;
T_3 V_55 ;
T_4 V_56 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_54 ) {
V_43 = V_54 -> V_43 ;
V_56 = V_54 -> V_57 ;
}
if ( ! V_43 )
V_43 = V_2 -> V_43 ;
if ( ( V_43 < 4 )
|| ( ( V_43 > 16 ) && ( V_43 != 32 ) ) )
return - V_51 ;
if ( ! V_56 )
V_56 = V_2 -> V_58 ;
if ( ! ( V_3 -> V_12 & V_15 ) )
V_43 = F_12 ( V_7 , V_2 ,
V_3 ,
V_43 ) ;
else if ( V_3 -> V_12 & V_16 )
V_43 = F_13 ( V_7 , V_2 ,
V_43 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_43 == 32 )
V_43 = 0 ;
else
V_43 = V_43 - 1 ;
V_7 -> V_13 &= ~ ( F_15 ( 0xF ) | V_59
| F_16 ( 0xF ) ) ;
V_7 -> V_13 |= F_15 ( V_43 ) ;
if ( ( V_3 -> V_60 / V_56 ) > 64 ) {
V_7 -> V_13 |= V_59 ;
V_55 = ( V_3 -> V_60 - 1 ) / ( V_56 * 64 ) + 1 ;
F_17 ( V_55 > 16 , L_1
L_2 , F_18 ( & V_2 -> V_33 ) ,
V_56 , V_3 -> V_60 / 1024 ) ;
if ( V_55 > 16 )
V_55 = 16 ;
} else {
V_55 = ( V_3 -> V_60 - 1 ) / ( V_56 * 4 ) + 1 ;
}
if ( V_55 )
V_55 -- ;
V_7 -> V_13 |= F_16 ( V_55 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_61 T_2 * V_62 = V_4 -> V_62 ;
struct V_61 T_2 * V_63 = V_4 -> V_63 ;
unsigned int V_64 = F_20 ( V_4 -> V_65 , V_66 ) ;
unsigned int V_67 ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_67 = V_4 -> V_68 -> V_69 - V_4 -> V_65 ;
if ( V_4 -> V_70 == V_4 -> V_71 )
F_21 ( & V_63 -> V_72 , V_4 -> V_70 ) ;
else
F_21 ( & V_63 -> V_72 , V_4 -> V_70 + V_67 ) ;
F_8 ( & V_63 -> V_73 , 0 ) ;
F_8 ( & V_63 -> V_74 , V_75 | V_76 | V_77 ) ;
if ( V_4 -> V_78 == V_4 -> V_79 )
F_21 ( & V_62 -> V_72 , V_4 -> V_78 ) ;
else
F_21 ( & V_62 -> V_72 , V_4 -> V_78 + V_67 ) ;
F_8 ( & V_62 -> V_73 , V_64 ) ;
F_8 ( & V_62 -> V_74 , V_80 | V_76 | V_77 |
V_81 ) ;
F_5 ( & V_10 -> V_82 , V_83 ) ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_53 * V_54 , bool V_84 )
{
struct V_85 * V_33 = V_4 -> V_33 ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_84 ) {
V_4 -> V_86 = 0 ;
V_4 -> V_87 = 0 ;
} else {
V_4 -> V_86 = 1 ;
V_4 -> V_87 = 1 ;
}
if ( ! V_54 -> V_88 ) {
V_4 -> V_78 = V_4 -> V_79 ;
V_4 -> V_86 = 0 ;
}
if ( ! V_54 -> V_89 ) {
V_4 -> V_70 = V_4 -> V_71 ;
V_4 -> V_87 = 0 ;
}
if ( V_4 -> V_86 ) {
void * V_90 = ( void * ) V_4 -> V_91 ;
V_4 -> V_78 = F_23 ( V_33 , V_90 , V_54 -> V_69 ,
V_92 ) ;
if ( F_24 ( V_33 , V_4 -> V_78 ) ) {
F_25 ( V_33 , L_3 ) ;
return - V_93 ;
}
} else if ( V_54 -> V_88 ) {
V_4 -> V_78 = V_54 -> V_78 ;
}
if ( V_4 -> V_87 ) {
V_4 -> V_70 = F_23 ( V_33 , V_4 -> V_94 , V_54 -> V_69 ,
V_95 ) ;
if ( F_24 ( V_33 , V_4 -> V_70 ) ) {
F_25 ( V_33 , L_4 ) ;
goto V_96;
}
} else if ( V_54 -> V_89 ) {
V_4 -> V_70 = V_54 -> V_70 ;
}
F_5 ( & V_10 -> V_97 , V_98 ) ;
V_4 -> V_68 = V_54 ;
V_4 -> V_65 = V_54 -> V_69 ;
F_19 ( V_4 ) ;
return 0 ;
V_96:
if ( V_4 -> V_86 )
F_26 ( V_33 , V_4 -> V_78 , V_54 -> V_69 , V_92 ) ;
return - V_93 ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_85 * V_33 = V_4 -> V_33 ;
struct V_53 * V_54 = V_4 -> V_68 ;
if ( V_4 -> V_86 )
F_26 ( V_33 , V_4 -> V_78 , V_54 -> V_69 , V_92 ) ;
if ( V_4 -> V_87 )
F_26 ( V_33 , V_4 -> V_70 , V_54 -> V_69 , V_95 ) ;
V_4 -> V_68 = NULL ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_53 * V_54 , unsigned int V_69 )
{
T_4 V_99 ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_4 -> V_65 = V_69 ;
F_5 ( & V_10 -> V_97 , V_100 ) ;
V_99 = V_4 -> V_42 ( V_4 ) ;
F_5 ( & V_10 -> V_101 , V_99 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_53 * V_54 ,
bool V_84 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
struct V_9 * V_10 ;
unsigned int V_69 = V_54 -> V_69 ;
T_3 V_43 ;
int V_102 ;
V_10 = V_3 -> V_10 ;
V_43 = V_2 -> V_43 ;
if ( V_54 -> V_43 )
V_43 = V_54 -> V_43 ;
if ( V_43 > 8 ) {
if ( V_69 & 1 )
return - V_51 ;
V_69 /= 2 ;
}
if ( V_43 > 16 ) {
if ( V_69 & 1 )
return - V_51 ;
V_69 /= 2 ;
}
V_3 -> V_91 = V_54 -> V_88 ;
V_3 -> V_94 = V_54 -> V_89 ;
F_30 ( V_3 -> V_103 ) ;
if ( V_3 -> V_12 & V_15 )
V_102 = F_22 ( V_3 , V_54 , V_84 ) ;
else
V_102 = F_28 ( V_3 , V_54 , V_69 ) ;
if ( V_102 )
return V_102 ;
F_31 ( & V_3 -> V_103 ) ;
F_5 ( & V_10 -> V_97 , 0 ) ;
if ( V_3 -> V_12 & V_15 )
F_27 ( V_3 ) ;
return V_3 -> V_65 ;
}
static void F_32 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_53 * V_54 ;
unsigned int V_106 ;
const int V_107 = 50 ;
int V_108 ;
V_106 = 1 ;
V_108 = 0 ;
F_33 (t, &m->transfers, transfer_list) {
if ( V_54 -> V_43 || V_54 -> V_57 ) {
V_108 = - V_51 ;
if ( V_106 )
V_108 = F_14 ( V_2 , V_54 ) ;
if ( V_108 < 0 )
break;
}
if ( V_106 ) {
F_11 ( V_2 , V_38 ) ;
F_34 ( V_107 ) ;
}
V_106 = V_54 -> V_106 ;
if ( V_54 -> V_69 )
V_108 = F_29 ( V_2 , V_54 , V_105 -> V_84 ) ;
if ( V_108 ) {
V_108 = - V_109 ;
break;
}
V_105 -> V_110 += V_54 -> V_69 ;
if ( V_54 -> V_111 )
F_35 ( V_54 -> V_111 ) ;
if ( V_106 ) {
F_34 ( V_107 ) ;
F_11 ( V_2 , V_36 ) ;
F_34 ( V_107 ) ;
}
}
V_105 -> V_108 = V_108 ;
V_105 -> V_112 ( V_105 -> V_113 ) ;
if ( V_108 || ! V_106 ) {
F_34 ( V_107 ) ;
F_11 ( V_2 , V_36 ) ;
}
F_14 ( V_2 , NULL ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_9 * V_10 ;
int V_114 ;
T_4 V_13 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_2 -> V_58 )
return - V_51 ;
if ( ! V_7 ) {
V_7 = F_37 ( sizeof *V_7 , V_115 ) ;
if ( ! V_7 )
return - V_93 ;
V_2 -> V_8 = V_7 ;
}
V_3 = F_2 ( V_2 -> V_5 ) ;
V_10 = V_3 -> V_10 ;
V_13 = V_7 -> V_13 ;
V_7 -> V_13 = F_3 ( & V_10 -> V_11 ) ;
V_7 -> V_13 &= ~ ( V_116 | V_117
| V_118 | V_119 ) ;
if ( V_2 -> V_11 & V_120 )
V_7 -> V_13 |= V_116 ;
if ( V_2 -> V_11 & V_121 )
V_7 -> V_13 |= V_117 ;
if ( ! ( V_2 -> V_11 & V_52 ) )
V_7 -> V_13 |= V_118 ;
if ( V_2 -> V_11 & V_122 )
V_7 -> V_13 |= V_119 ;
V_114 = F_14 ( V_2 , NULL ) ;
if ( V_114 < 0 ) {
V_7 -> V_13 = V_13 ;
return V_114 ;
}
return 0 ;
}
static void F_38 ( struct V_3 * V_4 , T_4 V_123 )
{
T_5 V_69 ;
struct V_9 * V_10 = V_4 -> V_10 ;
F_39 ( V_4 -> V_33 , L_5 , V_124 ,
F_9 ( & V_4 -> V_63 -> V_73 ) , V_4 -> V_65 ) ;
V_69 = F_9 ( & V_4 -> V_63 -> V_73 ) ;
if ( V_69 > V_4 -> V_65 ) {
F_40 ( 1 ) ;
V_69 = V_4 -> V_65 ;
}
F_5 ( & V_10 -> V_125 , V_123 ) ;
V_4 -> V_65 -= V_69 ;
if ( V_4 -> V_65 )
F_19 ( V_4 ) ;
else
V_112 ( & V_4 -> V_103 ) ;
}
static void F_41 ( struct V_3 * V_4 , T_4 V_123 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_123 & V_126 ) {
T_4 V_127 = F_3 ( & V_10 -> V_128 ) ;
if ( V_4 -> V_94 )
V_4 -> V_41 ( V_127 , V_4 ) ;
}
if ( ( V_123 & V_129 ) == 0 )
while ( ( ( V_123 =
F_3 ( & V_10 -> V_125 ) ) &
V_129 ) == 0 )
F_42 () ;
F_5 ( & V_10 -> V_125 , V_123 ) ;
V_4 -> V_65 -= 1 ;
if ( V_4 -> V_65 ) {
T_4 V_99 = V_4 -> V_42 ( V_4 ) ;
F_5 ( & V_10 -> V_101 , V_99 ) ;
} else {
V_112 ( & V_4 -> V_103 ) ;
}
}
static T_6 F_43 ( T_7 V_130 , void * V_131 )
{
struct V_3 * V_4 = V_131 ;
T_6 V_102 = V_132 ;
T_4 V_123 ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_123 = F_3 ( & V_10 -> V_125 ) ;
if ( V_123 )
V_102 = V_133 ;
F_39 ( V_4 -> V_33 , L_6 , V_124 , V_123 ) ;
if ( V_4 -> V_12 & V_15 )
F_38 ( V_4 , V_123 ) ;
else
F_41 ( V_4 , V_123 ) ;
return V_102 ;
}
static void * F_44 ( void )
{
F_45 ( & V_134 ) ;
if ( ! V_135 )
V_135 = F_46 ( V_66 , V_115 ) ;
if ( V_135 )
V_136 ++ ;
F_47 ( & V_134 ) ;
return V_135 ;
}
static void F_48 ( void )
{
F_45 ( & V_134 ) ;
switch ( V_136 ) {
case 0 :
F_40 ( 1 ) ;
break;
case 1 :
F_49 ( V_135 ) ;
V_135 = NULL ;
default:
V_136 -- ;
break;
}
F_47 ( & V_134 ) ;
}
static unsigned long F_50 ( struct V_3 * V_4 )
{
struct V_85 * V_33 = V_4 -> V_33 ;
struct V_137 * V_138 = V_33 -> V_139 ;
const T_4 * V_140 ;
int V_141 ;
void T_2 * V_142 ;
unsigned long V_143 = - V_93 ;
V_140 = F_51 ( V_138 , L_7 , & V_141 ) ;
if ( V_4 -> V_12 & V_16 && V_140 && V_141 == sizeof( * V_140 ) * 4 )
return F_52 ( V_140 [ 2 ] , V_144 ) ;
if ( V_4 -> V_12 & V_16 ) {
V_143 = F_53 ( V_144 , 64 ) ;
F_6 ( V_145 , V_4 -> V_18 ,
V_19 , V_143 ) ;
return V_143 ;
}
V_142 = F_54 ( V_138 , 1 ) ;
if ( V_142 == NULL )
return - V_51 ;
if ( V_4 -> V_12 & V_146 ) {
V_143 = F_53 ( V_144 , 64 ) ;
F_8 ( V_142 , V_143 ) ;
} else {
struct V_147 T_2 * V_23 = V_142 ;
T_5 V_148 = F_9 ( & V_23 -> V_148 ) ;
if ( V_148 )
V_143 = V_148 ;
else {
V_143 = F_53 ( V_144 , 64 ) ;
F_8 ( V_142 , V_143 ) ;
}
}
F_55 ( V_142 ) ;
return V_143 ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_85 * V_33 = V_4 -> V_33 ;
struct V_137 * V_138 = V_33 -> V_139 ;
const T_4 * V_140 ;
int V_141 ;
unsigned long V_143 ;
unsigned long V_149 ;
if ( ! ( V_4 -> V_12 & V_15 ) )
return 0 ;
if ( ! F_44 () )
return - V_93 ;
if ( V_4 -> V_12 & V_16 ) {
V_140 = F_51 ( V_138 , L_8 , & V_141 ) ;
if ( V_140 && V_141 == sizeof( * V_140 ) )
V_4 -> V_18 = * V_140 ;
switch ( V_4 -> V_18 ) {
default:
F_57 ( V_33 , L_9 ) ;
case 0 :
V_4 -> V_18 = V_150 ;
break;
case 1 :
V_4 -> V_18 = V_151 ;
break;
}
}
V_143 = F_50 ( V_4 ) ;
if ( F_58 ( V_143 ) ) {
F_25 ( V_33 , L_10 ) ;
goto V_152;
}
V_149 = F_53 ( sizeof( * V_4 -> V_62 ) +
sizeof( * V_4 -> V_63 ) , 8 ) ;
if ( F_58 ( V_149 ) ) {
F_25 ( V_33 , L_11 ) ;
goto V_153;
}
V_4 -> V_79 = F_23 ( V_33 , V_154 , V_155 ,
V_92 ) ;
if ( F_24 ( V_33 , V_4 -> V_79 ) ) {
F_25 ( V_33 , L_12 ) ;
goto V_156;
}
V_4 -> V_71 = F_23 ( V_33 , V_135 , V_66 ,
V_95 ) ;
if ( F_24 ( V_33 , V_4 -> V_71 ) ) {
F_25 ( V_33 , L_13 ) ;
goto V_157;
}
V_4 -> V_23 = F_59 ( V_143 ) ;
V_4 -> V_62 = F_59 ( V_149 ) ;
V_4 -> V_63 = F_59 ( V_149 + sizeof( * V_4 -> V_62 ) ) ;
F_8 ( & V_4 -> V_23 -> V_27 , F_60 ( V_4 -> V_62 ) ) ;
F_8 ( & V_4 -> V_23 -> V_25 , F_60 ( V_4 -> V_63 ) ) ;
F_61 ( & V_4 -> V_23 -> V_158 , V_159 | V_160 ) ;
F_61 ( & V_4 -> V_23 -> V_161 , V_159 | V_160 ) ;
F_8 ( & V_4 -> V_23 -> V_162 , V_66 ) ;
F_21 ( & V_4 -> V_23 -> V_163 , 0 ) ;
F_21 ( & V_4 -> V_23 -> V_164 , 0 ) ;
F_8 ( & V_4 -> V_23 -> V_24 , 0 ) ;
F_8 ( & V_4 -> V_23 -> V_165 , 0 ) ;
F_21 ( & V_4 -> V_23 -> V_166 , 0 ) ;
F_21 ( & V_4 -> V_23 -> V_167 , 0 ) ;
F_21 ( & V_4 -> V_23 -> V_168 , 0 ) ;
F_8 ( & V_4 -> V_23 -> V_26 , 0 ) ;
F_8 ( & V_4 -> V_23 -> V_169 , 0 ) ;
F_21 ( & V_4 -> V_23 -> V_170 , 0 ) ;
return 0 ;
V_157:
F_26 ( V_33 , V_4 -> V_79 , V_155 , V_92 ) ;
V_156:
F_62 ( V_149 ) ;
V_153:
F_62 ( V_143 ) ;
V_152:
F_48 () ;
return - V_93 ;
}
static void F_63 ( struct V_3 * V_4 )
{
struct V_85 * V_33 = V_4 -> V_33 ;
if ( ! ( V_4 -> V_12 & V_15 ) )
return;
F_26 ( V_33 , V_4 -> V_71 , V_66 , V_95 ) ;
F_26 ( V_33 , V_4 -> V_79 , V_155 , V_92 ) ;
F_62 ( F_60 ( V_4 -> V_62 ) ) ;
F_62 ( F_60 ( V_4 -> V_23 ) ) ;
F_48 () ;
}
static void F_64 ( struct V_3 * V_4 )
{
F_55 ( V_4 -> V_10 ) ;
F_63 ( V_4 ) ;
}
static struct V_171 * F_65 ( struct V_85 * V_33 ,
struct V_172 * V_173 , unsigned int V_130 )
{
struct V_29 * V_30 = V_33 -> V_35 ;
struct V_171 * V_5 ;
struct V_3 * V_3 ;
struct V_9 * V_10 ;
T_4 V_174 ;
int V_102 = 0 ;
V_5 = F_66 ( V_33 , sizeof( struct V_3 ) ) ;
if ( V_5 == NULL ) {
V_102 = - V_93 ;
goto V_175;
}
F_67 ( V_33 , V_5 ) ;
V_102 = F_68 ( V_33 , V_173 , V_130 ) ;
if ( V_102 )
goto V_176;
V_5 -> V_177 = F_36 ;
V_3 = F_2 ( V_5 ) ;
V_3 -> V_178 = F_32 ;
V_3 -> V_179 = F_64 ;
V_102 = F_56 ( V_3 ) ;
if ( V_102 )
goto V_180;
if ( V_3 -> V_12 & V_46 ) {
V_3 -> V_39 = 16 ;
V_3 -> V_40 = 24 ;
}
V_3 -> V_10 = F_69 ( V_173 -> V_181 , F_70 ( V_173 ) ) ;
if ( V_3 -> V_10 == NULL ) {
V_102 = - V_93 ;
goto V_182;
}
V_102 = F_71 ( V_3 -> V_130 , F_43 ,
0 , L_14 , V_3 ) ;
if ( V_102 != 0 )
goto V_183;
V_10 = V_3 -> V_10 ;
F_5 ( & V_10 -> V_11 , 0 ) ;
F_5 ( & V_10 -> V_97 , 0 ) ;
F_5 ( & V_10 -> V_82 , 0 ) ;
F_5 ( & V_10 -> V_125 , 0xffffffff ) ;
V_174 = V_30 -> V_184 | V_185 | V_14 ;
if ( V_3 -> V_12 & V_46 )
V_174 |= V_186 ;
F_5 ( & V_10 -> V_11 , V_174 ) ;
V_102 = F_72 ( V_5 ) ;
if ( V_102 < 0 )
goto V_187;
F_73 ( V_33 , L_15 , V_10 ,
V_3 -> V_130 , F_74 ( V_3 -> V_12 ) ) ;
return V_5 ;
V_187:
V_183 ( V_3 -> V_130 , V_3 ) ;
V_183:
F_55 ( V_3 -> V_10 ) ;
V_182:
F_63 ( V_3 ) ;
V_180:
V_176:
F_75 ( V_5 ) ;
V_175:
return F_76 ( V_102 ) ;
}
static void F_77 ( struct V_1 * V_2 , bool V_188 )
{
struct V_85 * V_33 = V_2 -> V_33 . V_34 -> V_34 ;
struct V_189 * V_190 = F_78 ( V_33 -> V_35 ) ;
T_5 V_7 = V_2 -> V_191 ;
int V_192 = V_190 -> V_193 [ V_7 ] ;
bool V_194 = V_190 -> V_195 [ V_7 ] ;
F_79 ( V_192 , V_188 ^ V_194 ) ;
}
static int F_80 ( struct V_85 * V_33 )
{
struct V_137 * V_138 = V_33 -> V_139 ;
struct V_29 * V_30 = V_33 -> V_35 ;
struct V_189 * V_190 = F_78 ( V_30 ) ;
unsigned int V_196 ;
int V_197 = 0 ;
int V_102 ;
V_196 = F_81 ( V_138 ) ;
if ( ! V_196 ) {
V_30 -> V_198 = 1 ;
return 0 ;
}
V_190 -> V_193 = F_46 ( V_196 * sizeof( * V_190 -> V_193 ) , V_115 ) ;
if ( ! V_190 -> V_193 )
return - V_93 ;
memset ( V_190 -> V_193 , - 1 , V_196 * sizeof( * V_190 -> V_193 ) ) ;
V_190 -> V_195 = F_37 ( V_196 * sizeof( * V_190 -> V_195 ) ,
V_115 ) ;
if ( ! V_190 -> V_195 ) {
V_102 = - V_93 ;
goto V_199;
}
for (; V_197 < V_196 ; V_197 ++ ) {
int V_192 ;
enum V_200 V_12 ;
V_192 = F_82 ( V_138 , V_197 , & V_12 ) ;
if ( ! F_83 ( V_192 ) ) {
F_25 ( V_33 , L_16 , V_197 , V_192 ) ;
V_102 = V_192 ;
goto V_201;
}
V_102 = F_84 ( V_192 , F_18 ( V_33 ) ) ;
if ( V_102 ) {
F_25 ( V_33 , L_17 , V_197 , V_102 ) ;
goto V_201;
}
V_190 -> V_193 [ V_197 ] = V_192 ;
V_190 -> V_195 [ V_197 ] = V_12 & V_202 ;
V_102 = F_85 ( V_190 -> V_193 [ V_197 ] ,
V_190 -> V_195 [ V_197 ] ) ;
if ( V_102 ) {
F_25 ( V_33 , L_18
L_19 , V_197 , V_102 ) ;
goto V_201;
}
}
V_30 -> V_198 = V_196 ;
V_30 -> V_37 = F_77 ;
return 0 ;
V_201:
while ( V_197 >= 0 ) {
if ( F_83 ( V_190 -> V_193 [ V_197 ] ) )
F_86 ( V_190 -> V_193 [ V_197 ] ) ;
V_197 -- ;
}
F_49 ( V_190 -> V_195 ) ;
V_190 -> V_195 = NULL ;
V_199:
F_49 ( V_190 -> V_193 ) ;
V_190 -> V_193 = NULL ;
return V_102 ;
}
static int F_87 ( struct V_85 * V_33 )
{
struct V_29 * V_30 = V_33 -> V_35 ;
struct V_189 * V_190 = F_78 ( V_30 ) ;
int V_197 ;
if ( ! V_190 -> V_193 )
return 0 ;
for ( V_197 = 0 ; V_197 < V_30 -> V_198 ; V_197 ++ ) {
if ( F_83 ( V_190 -> V_193 [ V_197 ] ) )
F_86 ( V_190 -> V_193 [ V_197 ] ) ;
}
F_49 ( V_190 -> V_193 ) ;
F_49 ( V_190 -> V_195 ) ;
return 0 ;
}
static int F_88 ( struct V_203 * V_204 )
{
struct V_85 * V_33 = & V_204 -> V_33 ;
struct V_137 * V_138 = V_204 -> V_33 . V_139 ;
struct V_171 * V_5 ;
struct V_172 V_173 ;
struct V_172 V_130 ;
int V_102 = - V_93 ;
V_102 = F_89 ( V_204 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_80 ( V_33 ) ;
if ( V_102 )
goto V_175;
V_102 = F_90 ( V_138 , 0 , & V_173 ) ;
if ( V_102 )
goto V_175;
V_102 = F_91 ( V_138 , 0 , & V_130 ) ;
if ( ! V_102 ) {
V_102 = - V_51 ;
goto V_175;
}
V_5 = F_65 ( V_33 , & V_173 , V_130 . V_181 ) ;
if ( F_92 ( V_5 ) ) {
V_102 = F_93 ( V_5 ) ;
goto V_175;
}
return 0 ;
V_175:
F_87 ( V_33 ) ;
return V_102 ;
}
static int F_94 ( struct V_203 * V_204 )
{
int V_102 ;
V_102 = F_95 ( & V_204 -> V_33 ) ;
if ( V_102 )
return V_102 ;
F_87 ( & V_204 -> V_33 ) ;
return 0 ;
}
static int F_96 ( struct V_203 * V_205 )
{
struct V_172 * V_173 ;
int V_130 ;
struct V_171 * V_5 ;
if ( ! V_205 -> V_33 . V_35 )
return - V_51 ;
V_173 = F_97 ( V_205 , V_206 , 0 ) ;
if ( ! V_173 )
return - V_51 ;
V_130 = F_98 ( V_205 , 0 ) ;
if ( V_130 <= 0 )
return - V_51 ;
V_5 = F_65 ( & V_205 -> V_33 , V_173 , V_130 ) ;
if ( F_92 ( V_5 ) )
return F_93 ( V_5 ) ;
return 0 ;
}
static int F_99 ( struct V_203 * V_205 )
{
return F_95 ( & V_205 -> V_33 ) ;
}
static void T_8 F_100 ( void )
{
V_207 = F_101 ( & V_208 ) ;
}
static void T_9 F_102 ( void )
{
if ( V_207 )
return;
F_103 ( & V_208 ) ;
}
static void T_8 F_100 ( void ) {}
static void T_9 F_102 ( void ) {}
static int T_8 F_104 ( void )
{
F_100 () ;
return F_101 ( & V_209 ) ;
}
static void T_9 F_105 ( void )
{
F_103 ( & V_209 ) ;
F_102 () ;
}
