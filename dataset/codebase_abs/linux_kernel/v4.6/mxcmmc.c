static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_6 )
{
if ( F_4 ( V_7 ) )
return F_5 ( V_2 -> V_8 + V_6 ) ;
else
return F_6 ( V_2 -> V_8 + V_6 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_9 , int V_6 )
{
if ( F_4 ( V_7 ) )
F_8 ( V_9 , V_2 -> V_8 + V_6 ) ;
else
F_9 ( V_9 , V_2 -> V_8 + V_6 ) ;
}
static inline T_2 F_10 ( struct V_1 * V_2 , int V_6 )
{
if ( F_4 ( V_7 ) )
return F_5 ( V_2 -> V_8 + V_6 ) ;
else
return F_11 ( V_2 -> V_8 + V_6 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , T_2 V_9 , int V_6 )
{
if ( F_4 ( V_7 ) )
F_8 ( V_9 , V_2 -> V_8 + V_6 ) ;
else
F_13 ( V_9 , V_2 -> V_8 + V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_10 )
{
if ( ! F_15 ( V_2 -> V_11 -> V_12 . V_13 ) ) {
if ( V_2 -> V_14 == V_15 )
F_16 ( V_2 -> V_11 ,
V_2 -> V_11 -> V_12 . V_13 , V_10 ) ;
else if ( V_2 -> V_14 == V_16 )
F_16 ( V_2 -> V_11 ,
V_2 -> V_11 -> V_12 . V_13 , 0 ) ;
}
if ( V_2 -> V_17 && V_2 -> V_17 -> V_18 )
V_2 -> V_17 -> V_18 ( F_17 ( V_2 -> V_11 ) , V_10 ) ;
}
static inline int F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_19 ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_20 ;
F_20 ( F_17 ( V_2 -> V_11 ) , L_1 ) ;
F_12 ( V_2 , V_21 , V_22 ) ;
F_12 ( V_2 , V_21 | V_23 ,
V_22 ) ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
F_12 ( V_2 , V_23 , V_22 ) ;
F_12 ( V_2 , 0xff , V_24 ) ;
}
static inline void F_21 ( T_1 * V_25 , int V_26 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < ( ( V_26 + 3 ) / 4 ) ; V_20 ++ ) {
* V_25 = F_22 ( * V_25 ) ;
V_25 ++ ;
}
}
static void F_23 ( struct V_27 * V_28 )
{
struct V_29 * V_30 ;
int V_20 ;
F_24 (data->sg, sg, data->sg_len, i)
F_21 ( F_25 ( V_30 ) , V_30 -> V_31 ) ;
}
static inline void F_23 ( struct V_27 * V_28 ) {}
static int F_26 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
unsigned int V_32 = V_28 -> V_33 ;
unsigned int V_34 = V_28 -> V_34 ;
unsigned int V_35 = V_32 * V_34 ;
struct V_29 * V_30 ;
enum V_36 V_37 ;
int V_20 , V_38 ;
V_2 -> V_28 = V_28 ;
V_28 -> V_39 = 0 ;
F_12 ( V_2 , V_32 , V_40 ) ;
F_12 ( V_2 , V_34 , V_41 ) ;
V_2 -> V_35 = V_35 ;
if ( ! F_18 ( V_2 ) )
return 0 ;
F_24 (data->sg, sg, data->sg_len, i) {
if ( V_30 -> V_42 & 3 || V_30 -> V_31 & 3 || V_30 -> V_31 < 512 ) {
V_2 -> V_19 = 0 ;
return 0 ;
}
}
if ( V_28 -> V_43 & V_44 ) {
V_2 -> V_45 = V_46 ;
V_37 = V_47 ;
} else {
V_2 -> V_45 = V_48 ;
V_37 = V_49 ;
F_23 ( V_28 ) ;
}
V_38 = F_27 ( V_2 -> V_50 -> V_51 -> V_52 , V_28 -> V_30 ,
V_28 -> V_53 , V_2 -> V_45 ) ;
if ( V_38 != V_28 -> V_53 )
return - V_54 ;
V_2 -> V_55 = F_28 ( V_2 -> V_50 ,
V_28 -> V_30 , V_28 -> V_53 , V_37 ,
V_56 | V_57 ) ;
if ( ! V_2 -> V_55 ) {
F_29 ( V_2 -> V_50 -> V_51 -> V_52 , V_28 -> V_30 , V_28 -> V_53 ,
V_2 -> V_45 ) ;
V_2 -> V_19 = 0 ;
return 0 ;
}
F_30 () ;
F_31 ( V_2 -> V_55 ) ;
F_32 ( V_2 -> V_50 ) ;
F_33 ( & V_2 -> V_58 , V_59 + F_34 ( V_60 ) ) ;
return 0 ;
}
static void F_35 ( void * V_28 )
{
struct V_1 * V_2 = V_28 ;
T_1 V_61 ;
F_36 ( & V_2 -> V_58 ) ;
V_61 = F_3 ( V_2 , V_62 ) ;
F_20 ( F_17 ( V_2 -> V_11 ) , L_2 , V_63 , V_61 ) ;
F_37 ( V_2 , V_61 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_64 * V_65 ,
unsigned int V_66 )
{
T_1 V_67 = V_2 -> V_68 ;
unsigned long V_43 ;
F_39 ( V_2 -> V_65 != NULL ) ;
V_2 -> V_65 = V_65 ;
switch ( F_40 ( V_65 ) ) {
case V_69 :
case V_70 :
V_66 |= V_71 ;
break;
case V_72 :
V_66 |= V_73 ;
break;
case V_74 :
V_66 |= V_75 ;
break;
case V_76 :
break;
default:
F_41 ( F_17 ( V_2 -> V_11 ) , L_3 ,
F_40 ( V_65 ) ) ;
V_65 -> error = - V_54 ;
return - V_54 ;
}
V_67 = V_77 ;
if ( F_18 ( V_2 ) ) {
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_55 -> V_78 = F_35 ;
V_2 -> V_55 -> V_79 = V_2 ;
} else {
V_67 |= V_80 ;
}
}
F_42 ( & V_2 -> V_81 , V_43 ) ;
if ( V_2 -> V_82 )
V_67 |= V_83 ;
F_7 ( V_2 , V_67 , V_84 ) ;
F_43 ( & V_2 -> V_81 , V_43 ) ;
F_12 ( V_2 , V_65 -> V_85 , V_86 ) ;
F_7 ( V_2 , V_65 -> V_87 , V_88 ) ;
F_12 ( V_2 , V_66 , V_89 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
T_1 V_67 = V_2 -> V_68 ;
unsigned long V_43 ;
F_42 ( & V_2 -> V_81 , V_43 ) ;
if ( V_2 -> V_82 )
V_67 |= V_83 ;
F_7 ( V_2 , V_67 , V_84 ) ;
F_43 ( & V_2 -> V_81 , V_43 ) ;
V_2 -> V_91 = NULL ;
V_2 -> V_65 = NULL ;
V_2 -> V_28 = NULL ;
F_45 ( V_2 -> V_11 , V_91 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
int V_92 ;
if ( F_18 ( V_2 ) ) {
F_29 ( V_2 -> V_50 -> V_51 -> V_52 , V_28 -> V_30 , V_28 -> V_53 ,
V_2 -> V_45 ) ;
F_23 ( V_28 ) ;
}
if ( V_61 & V_93 ) {
F_20 ( F_17 ( V_2 -> V_11 ) , L_4 ,
V_61 ) ;
if ( V_61 & V_94 ) {
F_41 ( F_17 ( V_2 -> V_11 ) , L_5 , V_63 ) ;
V_28 -> error = - V_95 ;
} else if ( V_61 & V_96 ) {
T_1 V_97 = ( V_61 >> 9 ) & 0x3 ;
if ( V_97 == 2 ) {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_6 , V_63 ) ;
V_28 -> error = - V_98 ;
} else {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_5 , V_63 ) ;
V_28 -> error = - V_95 ;
}
} else if ( V_61 & V_99 ) {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_7 , V_63 ) ;
V_28 -> error = - V_98 ;
} else {
F_41 ( F_17 ( V_2 -> V_11 ) , L_8 , V_63 ) ;
V_28 -> error = - V_100 ;
}
} else {
V_28 -> V_39 = V_2 -> V_35 ;
}
V_92 = V_28 -> error ;
V_2 -> V_28 = NULL ;
return V_92 ;
}
static void F_47 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
int V_20 ;
T_1 V_101 , V_102 , V_103 ;
if ( ! V_65 )
return;
if ( V_61 & V_104 ) {
F_20 ( F_17 ( V_2 -> V_11 ) , L_9 ) ;
V_65 -> error = - V_98 ;
} else if ( V_61 & V_105 && V_65 -> V_43 & V_106 ) {
F_20 ( F_17 ( V_2 -> V_11 ) , L_10 ) ;
V_65 -> error = - V_95 ;
}
if ( V_65 -> V_43 & V_107 ) {
if ( V_65 -> V_43 & V_108 ) {
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
V_101 = F_10 ( V_2 , V_109 ) ;
V_102 = F_10 ( V_2 , V_109 ) ;
V_65 -> V_110 [ V_20 ] = V_101 << 16 | V_102 ;
}
} else {
V_101 = F_10 ( V_2 , V_109 ) ;
V_102 = F_10 ( V_2 , V_109 ) ;
V_103 = F_10 ( V_2 , V_109 ) ;
V_65 -> V_110 [ 0 ] = V_101 << 24 | V_102 << 8 | V_103 >> 8 ;
}
}
}
static int F_48 ( struct V_1 * V_2 , T_1 V_111 )
{
T_1 V_61 ;
unsigned long V_112 = V_59 + V_113 ;
do {
V_61 = F_3 ( V_2 , V_62 ) ;
if ( V_61 & V_93 )
return V_61 ;
if ( F_49 ( V_59 , V_112 ) ) {
F_19 ( V_2 ) ;
F_50 ( V_2 , V_2 -> clock ) ;
return V_99 ;
}
if ( V_61 & V_111 )
return 0 ;
F_51 () ;
} while ( 1 );
}
static int F_52 ( struct V_1 * V_2 , void * V_114 , int V_115 )
{
unsigned int V_61 ;
T_1 * V_25 = V_114 ;
while ( V_115 > 3 ) {
V_61 = F_48 ( V_2 ,
V_116 | V_117 ) ;
if ( V_61 )
return V_61 ;
* V_25 ++ = F_53 ( F_3 ( V_2 , V_118 ) ) ;
V_115 -= 4 ;
}
if ( V_115 ) {
T_3 * V_102 = ( T_3 * ) V_25 ;
T_1 V_119 ;
V_61 = F_48 ( V_2 ,
V_116 | V_117 ) ;
if ( V_61 )
return V_61 ;
V_119 = F_53 ( F_3 ( V_2 , V_118 ) ) ;
memcpy ( V_102 , & V_119 , V_115 ) ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , void * V_114 , int V_115 )
{
unsigned int V_61 ;
T_1 * V_25 = V_114 ;
while ( V_115 > 3 ) {
V_61 = F_48 ( V_2 , V_120 ) ;
if ( V_61 )
return V_61 ;
F_7 ( V_2 , F_53 ( * V_25 ++ ) , V_118 ) ;
V_115 -= 4 ;
}
if ( V_115 ) {
T_3 * V_102 = ( T_3 * ) V_25 ;
T_1 V_119 ;
V_61 = F_48 ( V_2 , V_120 ) ;
if ( V_61 )
return V_61 ;
memcpy ( & V_119 , V_102 , V_115 ) ;
F_7 ( V_2 , F_53 ( V_119 ) , V_118 ) ;
}
return F_48 ( V_2 , V_120 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_91 -> V_28 ;
struct V_29 * V_30 ;
int V_61 , V_20 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_35 = 0 ;
if ( V_28 -> V_43 & V_44 ) {
F_24 (data->sg, sg, data->sg_len, i) {
V_61 = F_52 ( V_2 , F_25 ( V_30 ) , V_30 -> V_31 ) ;
if ( V_61 )
return V_61 ;
V_2 -> V_35 += V_30 -> V_31 ;
}
} else {
F_24 (data->sg, sg, data->sg_len, i) {
V_61 = F_54 ( V_2 , F_25 ( V_30 ) , V_30 -> V_31 ) ;
if ( V_61 )
return V_61 ;
V_2 -> V_35 += V_30 -> V_31 ;
}
V_61 = F_48 ( V_2 , V_121 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static void F_56 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_57 ( V_123 , struct V_1 ,
V_124 ) ;
int V_125 = F_55 ( V_2 ) ;
F_7 ( V_2 , V_117 | V_121 ,
V_62 ) ;
F_46 ( V_2 , V_125 ) ;
if ( V_2 -> V_91 -> V_126 ) {
if ( F_38 ( V_2 , V_2 -> V_91 -> V_126 , 0 ) ) {
F_44 ( V_2 , V_2 -> V_91 ) ;
return;
}
} else {
F_44 ( V_2 , V_2 -> V_91 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_90 * V_91 ;
int V_92 ;
unsigned long V_43 ;
F_42 ( & V_2 -> V_81 , V_43 ) ;
if ( ! V_2 -> V_28 ) {
F_43 ( & V_2 -> V_81 , V_43 ) ;
return;
}
if ( ! V_2 -> V_91 ) {
F_43 ( & V_2 -> V_81 , V_43 ) ;
return;
}
V_91 = V_2 -> V_91 ;
if ( ! V_91 -> V_126 )
V_2 -> V_91 = NULL ;
V_92 = F_46 ( V_2 , V_61 ) ;
F_43 ( & V_2 -> V_81 , V_43 ) ;
F_47 ( V_2 , V_61 ) ;
V_2 -> V_65 = NULL ;
if ( V_91 -> V_126 ) {
if ( F_38 ( V_2 , V_91 -> V_126 , 0 ) ) {
F_44 ( V_2 , V_91 ) ;
return;
}
} else {
F_44 ( V_2 , V_91 ) ;
}
}
static void F_58 ( struct V_1 * V_2 , unsigned int V_61 )
{
F_47 ( V_2 , V_61 ) ;
V_2 -> V_65 = NULL ;
if ( ! V_2 -> V_28 && V_2 -> V_91 ) {
F_44 ( V_2 , V_2 -> V_91 ) ;
return;
}
if ( ! F_18 ( V_2 ) && V_2 -> V_28 )
F_59 ( & V_2 -> V_124 ) ;
}
static T_4 F_60 ( int V_127 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
unsigned long V_43 ;
bool V_129 ;
T_1 V_61 ;
V_61 = F_3 ( V_2 , V_62 ) ;
F_7 ( V_2 ,
V_61 & ~ ( V_130 | V_131 |
V_121 ) ,
V_62 ) ;
F_20 ( F_17 ( V_2 -> V_11 ) , L_2 , V_63 , V_61 ) ;
F_42 ( & V_2 -> V_81 , V_43 ) ;
V_129 = ( V_61 & V_130 ) && V_2 -> V_82 ;
F_43 ( & V_2 -> V_81 , V_43 ) ;
if ( F_18 ( V_2 ) && ( V_61 & ( V_121 ) ) )
F_7 ( V_2 , V_121 , V_62 ) ;
if ( V_129 ) {
F_7 ( V_2 , V_130 , V_62 ) ;
F_61 ( V_2 -> V_11 ) ;
}
if ( V_61 & V_132 )
F_58 ( V_2 , V_61 ) ;
if ( F_18 ( V_2 ) && ( V_61 & V_121 ) ) {
F_36 ( & V_2 -> V_58 ) ;
F_37 ( V_2 , V_61 ) ;
}
if ( V_2 -> V_68 &&
( V_61 & ( V_133 | V_134 ) ) )
F_62 ( V_2 -> V_11 , F_34 ( 200 ) ) ;
return V_135 ;
}
static void F_63 ( struct V_136 * V_11 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
unsigned int V_66 = V_2 -> V_66 ;
int error ;
F_39 ( V_2 -> V_91 != NULL ) ;
V_2 -> V_91 = V_91 ;
V_2 -> V_66 &= ~ V_137 ;
if ( V_2 -> V_50 )
V_2 -> V_19 = 1 ;
if ( V_91 -> V_28 ) {
error = F_26 ( V_2 , V_91 -> V_28 ) ;
if ( error ) {
V_91 -> V_65 -> error = error ;
goto V_138;
}
V_66 |= V_139 ;
if ( V_91 -> V_28 -> V_43 & V_140 )
V_66 |= V_141 ;
}
error = F_38 ( V_2 , V_91 -> V_65 , V_66 ) ;
V_138:
if ( error )
F_44 ( V_2 , V_91 ) ;
}
static void F_50 ( struct V_1 * V_2 , unsigned int V_142 )
{
unsigned int V_143 ;
int V_144 = 0 ;
unsigned int V_145 = F_65 ( V_2 -> V_146 ) ;
while ( V_144 <= 0x800 ) {
for ( V_143 = 1 ; V_143 <= 0xF ; V_143 ++ ) {
int V_147 ;
V_147 = ( V_145 / ( V_143 + 1 ) ) ;
if ( V_144 )
V_147 /= ( V_144 * 2 ) ;
if ( V_147 <= V_142 )
break;
}
if ( V_143 < 0x10 )
break;
if ( V_144 == 0 )
V_144 = 1 ;
else
V_144 <<= 1 ;
}
F_12 ( V_2 , ( V_144 << 4 ) | V_143 , V_148 ) ;
F_20 ( F_17 ( V_2 -> V_11 ) , L_11 ,
V_144 , V_143 , V_145 , V_142 ) ;
}
static int F_66 ( struct V_136 * V_11 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
struct V_149 * V_150 = & V_2 -> V_149 ;
V_150 -> V_151 = V_2 -> V_152 + V_118 ;
V_150 -> V_153 = V_2 -> V_152 + V_118 ;
V_150 -> V_154 = 4 ;
V_150 -> V_155 = 4 ;
V_150 -> V_156 = V_2 -> V_157 ;
V_150 -> V_158 = V_2 -> V_157 ;
V_150 -> V_159 = false ;
return F_67 ( V_2 -> V_50 , V_150 ) ;
}
static void F_68 ( struct V_136 * V_11 , struct V_160 * V_161 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
int V_157 , V_162 ;
if ( V_161 -> V_163 == V_164 )
V_157 = 16 ;
else
V_157 = 4 ;
if ( F_18 ( V_2 ) && V_157 != V_2 -> V_157 ) {
V_2 -> V_157 = V_157 ;
V_162 = F_66 ( V_11 ) ;
if ( V_162 ) {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_12 ) ;
F_69 ( V_2 -> V_50 ) ;
V_2 -> V_19 = 0 ;
V_2 -> V_50 = NULL ;
}
}
if ( V_161 -> V_163 == V_164 )
V_2 -> V_66 |= V_165 ;
else
V_2 -> V_66 &= ~ V_165 ;
if ( V_2 -> V_14 != V_161 -> V_14 ) {
V_2 -> V_14 = V_161 -> V_14 ;
F_14 ( V_2 , V_161 -> V_10 ) ;
if ( V_161 -> V_14 == V_166 )
V_2 -> V_66 |= V_137 ;
}
if ( V_161 -> clock ) {
F_50 ( V_2 , V_161 -> clock ) ;
F_12 ( V_2 , V_23 , V_22 ) ;
} else {
F_12 ( V_2 , V_167 , V_22 ) ;
}
V_2 -> clock = V_161 -> clock ;
}
static T_4 F_70 ( int V_127 , void * V_28 )
{
struct V_136 * V_11 = V_28 ;
F_20 ( F_17 ( V_11 ) , L_13 , V_63 ) ;
F_62 ( V_11 , F_34 ( 250 ) ) ;
return V_135 ;
}
static int F_71 ( struct V_136 * V_11 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
if ( V_2 -> V_17 && V_2 -> V_17 -> V_168 )
return ! ! V_2 -> V_17 -> V_168 ( F_17 ( V_11 ) ) ;
return F_72 ( V_11 ) ;
}
static void F_73 ( struct V_136 * V_11 , int V_169 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
unsigned long V_43 ;
T_1 V_67 ;
F_42 ( & V_2 -> V_81 , V_43 ) ;
V_2 -> V_82 = V_169 ;
V_67 = F_3 ( V_2 , V_84 ) ;
if ( V_169 )
V_67 |= V_83 ;
else
V_67 &= ~ V_83 ;
F_7 ( V_2 , V_67 , V_84 ) ;
F_43 ( & V_2 -> V_81 , V_43 ) ;
}
static void F_74 ( struct V_136 * V_2 , struct V_170 * V_171 )
{
struct V_1 * V_172 = F_64 ( V_2 ) ;
if ( F_1 ( V_172 ) && V_171 -> type == V_173 )
V_2 -> V_174 &= ~ V_175 ;
else
V_2 -> V_174 |= V_175 ;
}
static bool F_75 ( struct V_176 * V_177 , void * V_178 )
{
struct V_1 * V_2 = V_178 ;
if ( ! F_76 ( V_177 ) )
return false ;
V_177 -> V_179 = & V_2 -> V_180 ;
return true ;
}
static void F_77 ( unsigned long V_28 )
{
struct V_136 * V_11 = (struct V_136 * ) V_28 ;
struct V_1 * V_2 = F_64 ( V_11 ) ;
struct V_90 * V_91 = V_2 -> V_91 ;
unsigned int V_61 = F_3 ( V_2 , V_62 ) ;
if ( V_2 -> V_45 == V_46 ) {
F_78 ( V_2 -> V_50 ) ;
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_14 ,
V_63 , V_61 ) ;
} else {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_15 ,
V_63 , V_61 ) ;
F_19 ( V_2 ) ;
}
if ( V_2 -> V_28 )
V_2 -> V_28 -> error = - V_98 ;
V_2 -> V_91 = NULL ;
V_2 -> V_65 = NULL ;
V_2 -> V_28 = NULL ;
F_45 ( V_2 -> V_11 , V_91 ) ;
}
static int F_79 ( struct V_181 * V_182 )
{
struct V_136 * V_11 ;
struct V_1 * V_2 ;
struct V_183 * V_184 ;
int V_162 = 0 , V_127 ;
bool V_185 = false ;
T_5 V_111 ;
const struct V_186 * V_187 ;
struct V_188 * V_17 = V_182 -> V_52 . V_189 ;
F_80 ( L_16 ) ;
V_187 = F_81 ( V_190 , & V_182 -> V_52 ) ;
V_184 = F_82 ( V_182 , V_191 , 0 ) ;
V_127 = F_83 ( V_182 , 0 ) ;
if ( V_127 < 0 )
return - V_54 ;
V_11 = F_84 ( sizeof( * V_2 ) , & V_182 -> V_52 ) ;
if ( ! V_11 )
return - V_192 ;
V_2 = F_64 ( V_11 ) ;
V_2 -> V_8 = F_85 ( & V_182 -> V_52 , V_184 ) ;
if ( F_15 ( V_2 -> V_8 ) ) {
V_162 = F_86 ( V_2 -> V_8 ) ;
goto V_193;
}
V_2 -> V_152 = V_184 -> V_194 ;
V_162 = F_87 ( V_11 ) ;
if ( V_162 )
goto V_193;
V_11 -> V_195 = & V_196 ;
if ( V_17 )
V_11 -> V_174 = V_175 | V_197 ;
else
V_11 -> V_174 |= V_197 ;
V_11 -> V_198 = 2048 ;
V_11 -> V_199 = 65535 ;
V_11 -> V_200 = V_11 -> V_198 * V_11 -> V_199 ;
V_11 -> V_201 = V_11 -> V_200 ;
if ( V_187 ) {
const struct V_202 * V_203 = V_187 -> V_28 ;
V_2 -> V_3 = V_203 -> V_204 ;
} else {
V_2 -> V_3 = V_182 -> V_203 -> V_204 ;
}
if ( ! F_2 ( V_2 ) )
V_11 -> V_205 = 64 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_17 = V_17 ;
F_88 ( & V_2 -> V_81 ) ;
if ( V_17 )
V_185 = V_17 -> V_185 ;
else if ( ! ( V_11 -> V_174 & V_206 )
&& ! F_89 ( V_182 -> V_52 . V_207 , L_17 ) )
V_185 = true ;
V_162 = F_90 ( V_11 ) ;
if ( V_162 == - V_208 )
goto V_193;
if ( ! V_11 -> V_209 ) {
if ( V_17 && V_17 -> V_209 )
V_11 -> V_209 = V_17 -> V_209 ;
else
V_11 -> V_209 = V_210 | V_211 ;
}
if ( V_185 )
V_2 -> V_68 =
V_212 | V_213 ;
else
V_2 -> V_68 = 0 ;
V_2 -> V_214 = F_91 ( & V_182 -> V_52 , L_18 ) ;
if ( F_15 ( V_2 -> V_214 ) ) {
V_162 = F_86 ( V_2 -> V_214 ) ;
goto V_193;
}
V_2 -> V_146 = F_91 ( & V_182 -> V_52 , L_19 ) ;
if ( F_15 ( V_2 -> V_146 ) ) {
V_162 = F_86 ( V_2 -> V_146 ) ;
goto V_193;
}
F_92 ( V_2 -> V_146 ) ;
F_92 ( V_2 -> V_214 ) ;
F_19 ( V_2 ) ;
V_2 -> V_215 = F_10 ( V_2 , V_216 ) ;
if ( V_2 -> V_215 != 0x400 ) {
V_162 = - V_217 ;
F_41 ( F_17 ( V_2 -> V_11 ) , L_20 ,
V_2 -> V_215 ) ;
goto V_218;
}
V_11 -> V_219 = F_65 ( V_2 -> V_146 ) >> 16 ;
V_11 -> V_220 = F_65 ( V_2 -> V_146 ) >> 1 ;
F_12 ( V_2 , 0x2db4 , V_221 ) ;
F_7 ( V_2 , V_2 -> V_68 , V_84 ) ;
if ( ! V_2 -> V_17 ) {
V_2 -> V_50 = F_93 ( & V_182 -> V_52 , L_21 ) ;
} else {
V_184 = F_82 ( V_182 , V_222 , 0 ) ;
if ( V_184 ) {
V_2 -> V_223 = V_184 -> V_194 ;
V_2 -> V_180 . V_224 = V_225 ;
V_2 -> V_180 . V_226 = V_227 ;
V_2 -> V_180 . V_228 = V_2 -> V_223 ;
F_94 ( V_111 ) ;
F_95 ( V_229 , V_111 ) ;
V_2 -> V_50 = F_96 ( V_111 , F_75 , V_2 ) ;
}
}
if ( V_2 -> V_50 )
V_11 -> V_201 = F_97 (
V_2 -> V_50 -> V_51 -> V_52 ) ;
else
F_98 ( F_17 ( V_2 -> V_11 ) , L_22 ) ;
F_99 ( & V_2 -> V_124 , F_56 ) ;
V_162 = F_100 ( & V_182 -> V_52 , V_127 , F_60 , 0 ,
F_101 ( & V_182 -> V_52 ) , V_2 ) ;
if ( V_162 )
goto V_230;
F_102 ( V_182 , V_11 ) ;
if ( V_2 -> V_17 && V_2 -> V_17 -> V_231 ) {
V_162 = V_2 -> V_17 -> V_231 ( & V_182 -> V_52 , F_70 ,
V_2 -> V_11 ) ;
if ( V_162 )
goto V_230;
}
F_103 ( & V_2 -> V_58 ) ;
V_2 -> V_58 . V_232 = & F_77 ;
V_2 -> V_58 . V_28 = ( unsigned long ) V_11 ;
F_104 ( V_11 ) ;
return 0 ;
V_230:
if ( V_2 -> V_50 )
F_69 ( V_2 -> V_50 ) ;
V_218:
F_105 ( V_2 -> V_146 ) ;
F_105 ( V_2 -> V_214 ) ;
V_193:
F_106 ( V_11 ) ;
return V_162 ;
}
static int F_107 ( struct V_181 * V_182 )
{
struct V_136 * V_11 = F_108 ( V_182 ) ;
struct V_1 * V_2 = F_64 ( V_11 ) ;
F_109 ( V_11 ) ;
if ( V_2 -> V_17 && V_2 -> V_17 -> exit )
V_2 -> V_17 -> exit ( & V_182 -> V_52 , V_11 ) ;
if ( V_2 -> V_50 )
F_69 ( V_2 -> V_50 ) ;
F_105 ( V_2 -> V_146 ) ;
F_105 ( V_2 -> V_214 ) ;
F_106 ( V_11 ) ;
return 0 ;
}
static int T_6 F_110 ( struct V_51 * V_52 )
{
struct V_136 * V_11 = F_111 ( V_52 ) ;
struct V_1 * V_2 = F_64 ( V_11 ) ;
F_105 ( V_2 -> V_146 ) ;
F_105 ( V_2 -> V_214 ) ;
return 0 ;
}
static int T_6 F_112 ( struct V_51 * V_52 )
{
struct V_136 * V_11 = F_111 ( V_52 ) ;
struct V_1 * V_2 = F_64 ( V_11 ) ;
F_92 ( V_2 -> V_146 ) ;
F_92 ( V_2 -> V_214 ) ;
return 0 ;
}
