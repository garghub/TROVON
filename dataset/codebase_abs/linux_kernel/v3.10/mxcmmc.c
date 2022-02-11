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
static inline void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_10 = F_15 ( F_16 ( V_2 -> V_11 ) , L_1 ) ;
if ( F_17 ( V_2 -> V_10 ) ) {
V_2 -> V_10 = NULL ;
} else {
V_2 -> V_11 -> V_12 = F_18 ( V_2 -> V_10 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_12 )
F_19 ( F_16 ( V_2 -> V_11 ) ,
L_2 ) ;
}
if ( V_2 -> V_10 == NULL ) {
if ( V_2 -> V_13 && V_2 -> V_13 -> V_12 )
V_2 -> V_11 -> V_12 = V_2 -> V_13 -> V_12 ;
else
V_2 -> V_11 -> V_12 = V_14 | V_15 ;
}
}
static inline void F_20 ( struct V_1 * V_2 ,
unsigned char V_16 ,
unsigned int V_17 )
{
if ( V_2 -> V_10 ) {
if ( V_16 == V_18 )
F_21 ( V_2 -> V_11 , V_2 -> V_10 , V_17 ) ;
else if ( V_16 == V_19 )
F_21 ( V_2 -> V_11 , V_2 -> V_10 , 0 ) ;
}
if ( V_2 -> V_13 && V_2 -> V_13 -> V_20 )
V_2 -> V_13 -> V_20 ( F_16 ( V_2 -> V_11 ) , V_17 ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_21 ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_22 ;
F_24 ( F_16 ( V_2 -> V_11 ) , L_3 ) ;
F_12 ( V_2 , V_23 , V_24 ) ;
F_12 ( V_2 , V_23 | V_25 ,
V_24 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_12 ( V_2 , V_25 , V_24 ) ;
F_12 ( V_2 , 0xff , V_26 ) ;
}
static inline void F_25 ( T_1 * V_27 , int V_28 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < ( ( V_28 + 3 ) / 4 ) ; V_22 ++ ) {
F_26 ( V_27 , * V_27 ) ;
V_27 ++ ;
}
}
static void F_27 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
int V_22 ;
F_28 (data->sg, sg, data->sg_len, i)
F_25 ( F_29 ( V_32 ) , V_32 -> V_33 ) ;
}
static inline void F_27 ( struct V_29 * V_30 ) {}
static int F_30 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
unsigned int V_34 = V_30 -> V_35 ;
unsigned int V_36 = V_30 -> V_36 ;
unsigned int V_37 = V_34 * V_36 ;
struct V_31 * V_32 ;
enum V_38 V_39 ;
int V_22 , V_40 ;
if ( V_30 -> V_41 & V_42 )
V_34 = 0xffff ;
V_2 -> V_30 = V_30 ;
V_30 -> V_43 = 0 ;
F_12 ( V_2 , V_34 , V_44 ) ;
F_12 ( V_2 , V_36 , V_45 ) ;
V_2 -> V_37 = V_37 ;
if ( ! F_22 ( V_2 ) )
return 0 ;
F_28 (data->sg, sg, data->sg_len, i) {
if ( V_32 -> V_46 & 3 || V_32 -> V_33 & 3 || V_32 -> V_33 < 512 ) {
V_2 -> V_21 = 0 ;
return 0 ;
}
}
if ( V_30 -> V_41 & V_47 ) {
V_2 -> V_48 = V_49 ;
V_39 = V_50 ;
} else {
V_2 -> V_48 = V_51 ;
V_39 = V_52 ;
F_27 ( V_30 ) ;
}
V_40 = F_31 ( V_2 -> V_53 -> V_54 -> V_55 , V_30 -> V_32 ,
V_30 -> V_56 , V_2 -> V_48 ) ;
if ( V_40 != V_30 -> V_56 )
return - V_57 ;
V_2 -> V_58 = F_32 ( V_2 -> V_53 ,
V_30 -> V_32 , V_30 -> V_56 , V_39 ,
V_59 | V_60 ) ;
if ( ! V_2 -> V_58 ) {
F_33 ( V_2 -> V_53 -> V_54 -> V_55 , V_30 -> V_32 , V_30 -> V_56 ,
V_2 -> V_48 ) ;
V_2 -> V_21 = 0 ;
return 0 ;
}
F_34 () ;
F_35 ( V_2 -> V_58 ) ;
F_36 ( V_2 -> V_53 ) ;
F_37 ( & V_2 -> V_61 , V_62 + F_38 ( V_63 ) ) ;
return 0 ;
}
static void F_39 ( void * V_30 )
{
struct V_1 * V_2 = V_30 ;
T_1 V_64 ;
F_40 ( & V_2 -> V_61 ) ;
V_64 = F_3 ( V_2 , V_65 ) ;
F_7 ( V_2 , V_64 & ~ V_66 , V_65 ) ;
F_24 ( F_16 ( V_2 -> V_11 ) , L_4 , V_67 , V_64 ) ;
if ( V_64 & V_68 )
F_7 ( V_2 , V_68 , V_65 ) ;
F_41 ( V_2 , V_64 ) ;
}
static int F_42 ( struct V_1 * V_2 , struct V_69 * V_70 ,
unsigned int V_71 )
{
T_1 V_72 = V_2 -> V_73 ;
unsigned long V_41 ;
F_43 ( V_2 -> V_70 != NULL ) ;
V_2 -> V_70 = V_70 ;
switch ( F_44 ( V_70 ) ) {
case V_74 :
case V_75 :
V_71 |= V_76 ;
break;
case V_77 :
V_71 |= V_78 ;
break;
case V_79 :
V_71 |= V_80 ;
break;
case V_81 :
break;
default:
F_45 ( F_16 ( V_2 -> V_11 ) , L_5 ,
F_44 ( V_70 ) ) ;
V_70 -> error = - V_57 ;
return - V_57 ;
}
V_72 = V_82 ;
if ( F_22 ( V_2 ) ) {
if ( V_2 -> V_48 == V_49 ) {
V_2 -> V_58 -> V_83 = F_39 ;
V_2 -> V_58 -> V_84 = V_2 ;
} else {
V_72 |= V_85 ;
}
}
F_46 ( & V_2 -> V_86 , V_41 ) ;
if ( V_2 -> V_87 )
V_72 |= V_88 ;
F_7 ( V_2 , V_72 , V_89 ) ;
F_47 ( & V_2 -> V_86 , V_41 ) ;
F_12 ( V_2 , V_70 -> V_90 , V_91 ) ;
F_7 ( V_2 , V_70 -> V_92 , V_93 ) ;
F_12 ( V_2 , V_71 , V_94 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
T_1 V_72 = V_2 -> V_73 ;
unsigned long V_41 ;
F_46 ( & V_2 -> V_86 , V_41 ) ;
if ( V_2 -> V_87 )
V_72 |= V_88 ;
F_7 ( V_2 , V_72 , V_89 ) ;
F_47 ( & V_2 -> V_86 , V_41 ) ;
V_2 -> V_96 = NULL ;
V_2 -> V_70 = NULL ;
V_2 -> V_30 = NULL ;
F_49 ( V_2 -> V_11 , V_96 ) ;
}
static int F_50 ( struct V_1 * V_2 , unsigned int V_64 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_97 ;
if ( F_22 ( V_2 ) ) {
F_33 ( V_2 -> V_53 -> V_54 -> V_55 , V_30 -> V_32 , V_30 -> V_56 ,
V_2 -> V_48 ) ;
F_27 ( V_30 ) ;
}
if ( V_64 & V_98 ) {
F_24 ( F_16 ( V_2 -> V_11 ) , L_6 ,
V_64 ) ;
if ( V_64 & V_99 ) {
F_45 ( F_16 ( V_2 -> V_11 ) , L_7 , V_67 ) ;
V_30 -> error = - V_100 ;
} else if ( V_64 & V_101 ) {
T_1 V_102 = ( V_64 >> 9 ) & 0x3 ;
if ( V_102 == 2 ) {
F_45 ( F_16 ( V_2 -> V_11 ) ,
L_8 , V_67 ) ;
V_30 -> error = - V_103 ;
} else {
F_45 ( F_16 ( V_2 -> V_11 ) ,
L_7 , V_67 ) ;
V_30 -> error = - V_100 ;
}
} else if ( V_64 & V_104 ) {
F_45 ( F_16 ( V_2 -> V_11 ) ,
L_9 , V_67 ) ;
V_30 -> error = - V_103 ;
} else {
F_45 ( F_16 ( V_2 -> V_11 ) , L_10 , V_67 ) ;
V_30 -> error = - V_105 ;
}
} else {
V_30 -> V_43 = V_2 -> V_37 ;
}
V_97 = V_30 -> error ;
V_2 -> V_30 = NULL ;
return V_97 ;
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_64 )
{
struct V_69 * V_70 = V_2 -> V_70 ;
int V_22 ;
T_1 V_106 , V_107 , V_108 ;
if ( ! V_70 )
return;
if ( V_64 & V_109 ) {
F_24 ( F_16 ( V_2 -> V_11 ) , L_11 ) ;
V_70 -> error = - V_103 ;
} else if ( V_64 & V_110 && V_70 -> V_41 & V_111 ) {
F_24 ( F_16 ( V_2 -> V_11 ) , L_12 ) ;
V_70 -> error = - V_100 ;
}
if ( V_70 -> V_41 & V_112 ) {
if ( V_70 -> V_41 & V_113 ) {
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
V_106 = F_10 ( V_2 , V_114 ) ;
V_107 = F_10 ( V_2 , V_114 ) ;
V_70 -> V_115 [ V_22 ] = V_106 << 16 | V_107 ;
}
} else {
V_106 = F_10 ( V_2 , V_114 ) ;
V_107 = F_10 ( V_2 , V_114 ) ;
V_108 = F_10 ( V_2 , V_114 ) ;
V_70 -> V_115 [ 0 ] = V_106 << 24 | V_107 << 8 | V_108 >> 8 ;
}
}
}
static int F_52 ( struct V_1 * V_2 , T_1 V_116 )
{
T_1 V_64 ;
unsigned long V_117 = V_62 + V_118 ;
do {
V_64 = F_3 ( V_2 , V_65 ) ;
if ( V_64 & V_98 )
return V_64 ;
if ( F_53 ( V_62 , V_117 ) ) {
F_23 ( V_2 ) ;
F_54 ( V_2 , V_2 -> clock ) ;
return V_104 ;
}
if ( V_64 & V_116 )
return 0 ;
F_55 () ;
} while ( 1 );
}
static int F_56 ( struct V_1 * V_2 , void * V_119 , int V_120 )
{
unsigned int V_64 ;
T_1 * V_27 = V_119 ;
while ( V_120 > 3 ) {
V_64 = F_52 ( V_2 ,
V_121 | V_68 ) ;
if ( V_64 )
return V_64 ;
* V_27 ++ = F_57 ( F_3 ( V_2 , V_122 ) ) ;
V_120 -= 4 ;
}
if ( V_120 ) {
T_3 * V_107 = ( T_3 * ) V_27 ;
T_1 V_123 ;
V_64 = F_52 ( V_2 ,
V_121 | V_68 ) ;
if ( V_64 )
return V_64 ;
V_123 = F_57 ( F_3 ( V_2 , V_122 ) ) ;
memcpy ( V_107 , & V_123 , V_120 ) ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , void * V_119 , int V_120 )
{
unsigned int V_64 ;
T_1 * V_27 = V_119 ;
while ( V_120 > 3 ) {
V_64 = F_52 ( V_2 , V_124 ) ;
if ( V_64 )
return V_64 ;
F_7 ( V_2 , F_57 ( * V_27 ++ ) , V_122 ) ;
V_120 -= 4 ;
}
if ( V_120 ) {
T_3 * V_107 = ( T_3 * ) V_27 ;
T_1 V_123 ;
V_64 = F_52 ( V_2 , V_124 ) ;
if ( V_64 )
return V_64 ;
memcpy ( & V_123 , V_107 , V_120 ) ;
F_7 ( V_2 , F_57 ( V_123 ) , V_122 ) ;
}
V_64 = F_52 ( V_2 , V_124 ) ;
if ( V_64 )
return V_64 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_96 -> V_30 ;
struct V_31 * V_32 ;
int V_64 , V_22 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_37 = 0 ;
if ( V_30 -> V_41 & V_47 ) {
F_28 (data->sg, sg, data->sg_len, i) {
V_64 = F_56 ( V_2 , F_29 ( V_32 ) , V_32 -> V_33 ) ;
if ( V_64 )
return V_64 ;
V_2 -> V_37 += V_32 -> V_33 ;
}
} else {
F_28 (data->sg, sg, data->sg_len, i) {
V_64 = F_58 ( V_2 , F_29 ( V_32 ) , V_32 -> V_33 ) ;
if ( V_64 )
return V_64 ;
V_2 -> V_37 += V_32 -> V_33 ;
}
V_64 = F_52 ( V_2 , V_125 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
static void F_60 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_61 ( V_127 , struct V_1 ,
V_128 ) ;
int V_129 = F_59 ( V_2 ) ;
F_7 ( V_2 , V_68 | V_125 ,
V_65 ) ;
F_50 ( V_2 , V_129 ) ;
if ( V_2 -> V_96 -> V_130 ) {
if ( F_42 ( V_2 , V_2 -> V_96 -> V_130 , 0 ) ) {
F_48 ( V_2 , V_2 -> V_96 ) ;
return;
}
} else {
F_48 ( V_2 , V_2 -> V_96 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_64 )
{
struct V_95 * V_96 ;
int V_97 ;
unsigned long V_41 ;
F_46 ( & V_2 -> V_86 , V_41 ) ;
if ( ! V_2 -> V_30 ) {
F_47 ( & V_2 -> V_86 , V_41 ) ;
return;
}
if ( ! V_2 -> V_96 ) {
F_47 ( & V_2 -> V_86 , V_41 ) ;
return;
}
V_96 = V_2 -> V_96 ;
if ( ! V_96 -> V_130 )
V_2 -> V_96 = NULL ;
V_97 = F_50 ( V_2 , V_64 ) ;
F_47 ( & V_2 -> V_86 , V_41 ) ;
F_51 ( V_2 , V_64 ) ;
V_2 -> V_70 = NULL ;
if ( V_96 -> V_130 ) {
if ( F_42 ( V_2 , V_96 -> V_130 , 0 ) ) {
F_48 ( V_2 , V_96 ) ;
return;
}
} else {
F_48 ( V_2 , V_96 ) ;
}
}
static void F_62 ( struct V_1 * V_2 , unsigned int V_64 )
{
F_51 ( V_2 , V_64 ) ;
V_2 -> V_70 = NULL ;
if ( ! V_2 -> V_30 && V_2 -> V_96 ) {
F_48 ( V_2 , V_2 -> V_96 ) ;
return;
}
if ( ! F_22 ( V_2 ) && V_2 -> V_30 )
F_63 ( & V_2 -> V_128 ) ;
}
static T_4 F_64 ( int V_131 , void * V_132 )
{
struct V_1 * V_2 = V_132 ;
unsigned long V_41 ;
bool V_133 ;
T_1 V_64 ;
V_64 = F_3 ( V_2 , V_65 ) ;
F_7 ( V_2 ,
V_64 & ~ ( V_134 | V_66 |
V_125 ) ,
V_65 ) ;
F_24 ( F_16 ( V_2 -> V_11 ) , L_4 , V_67 , V_64 ) ;
F_46 ( & V_2 -> V_86 , V_41 ) ;
V_133 = ( V_64 & V_134 ) && V_2 -> V_87 ;
F_47 ( & V_2 -> V_86 , V_41 ) ;
if ( F_22 ( V_2 ) &&
( V_64 & ( V_68 | V_125 ) ) )
F_7 ( V_2 , V_68 | V_125 ,
V_65 ) ;
if ( V_133 ) {
F_7 ( V_2 , V_134 , V_65 ) ;
F_65 ( V_2 -> V_11 ) ;
}
if ( V_64 & V_135 )
F_62 ( V_2 , V_64 ) ;
if ( F_22 ( V_2 ) &&
( V_64 & ( V_66 | V_125 ) ) ) {
F_40 ( & V_2 -> V_61 ) ;
F_41 ( V_2 , V_64 ) ;
}
if ( V_2 -> V_73 &&
( V_64 & ( V_136 | V_137 ) ) )
F_66 ( V_2 -> V_11 , F_38 ( 200 ) ) ;
return V_138 ;
}
static void F_67 ( struct V_139 * V_11 , struct V_95 * V_96 )
{
struct V_1 * V_2 = F_68 ( V_11 ) ;
unsigned int V_71 = V_2 -> V_71 ;
int error ;
F_43 ( V_2 -> V_96 != NULL ) ;
V_2 -> V_96 = V_96 ;
V_2 -> V_71 &= ~ V_140 ;
if ( V_2 -> V_53 )
V_2 -> V_21 = 1 ;
if ( V_96 -> V_30 ) {
error = F_30 ( V_2 , V_96 -> V_30 ) ;
if ( error ) {
V_96 -> V_70 -> error = error ;
goto V_141;
}
V_71 |= V_142 ;
if ( V_96 -> V_30 -> V_41 & V_143 )
V_71 |= V_144 ;
}
error = F_42 ( V_2 , V_96 -> V_70 , V_71 ) ;
V_141:
if ( error )
F_48 ( V_2 , V_96 ) ;
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_145 )
{
unsigned int V_146 ;
int V_147 = 0 ;
unsigned int V_148 = F_69 ( V_2 -> V_149 ) ;
while ( V_147 <= 0x800 ) {
for ( V_146 = 1 ; V_146 <= 0xF ; V_146 ++ ) {
int V_150 ;
V_150 = ( V_148 / ( V_146 + 1 ) ) ;
if ( V_147 )
V_150 /= ( V_147 * 2 ) ;
if ( V_150 <= V_145 )
break;
}
if ( V_146 < 0x10 )
break;
if ( V_147 == 0 )
V_147 = 1 ;
else
V_147 <<= 1 ;
}
F_12 ( V_2 , ( V_147 << 4 ) | V_146 , V_151 ) ;
F_24 ( F_16 ( V_2 -> V_11 ) , L_13 ,
V_147 , V_146 , V_148 , V_145 ) ;
}
static int F_70 ( struct V_139 * V_11 )
{
struct V_1 * V_2 = F_68 ( V_11 ) ;
struct V_152 * V_153 = & V_2 -> V_152 ;
V_153 -> V_154 = V_2 -> V_155 -> V_156 + V_122 ;
V_153 -> V_157 = V_2 -> V_155 -> V_156 + V_122 ;
V_153 -> V_158 = 4 ;
V_153 -> V_159 = 4 ;
V_153 -> V_160 = V_2 -> V_161 ;
V_153 -> V_162 = V_2 -> V_161 ;
V_153 -> V_163 = false ;
return F_71 ( V_2 -> V_53 , V_153 ) ;
}
static void F_72 ( struct V_139 * V_11 , struct V_164 * V_165 )
{
struct V_1 * V_2 = F_68 ( V_11 ) ;
int V_161 , V_166 ;
if ( V_165 -> V_167 == V_168 )
V_161 = 16 ;
else
V_161 = 4 ;
if ( F_22 ( V_2 ) && V_161 != V_2 -> V_161 ) {
V_2 -> V_161 = V_161 ;
V_166 = F_70 ( V_11 ) ;
if ( V_166 ) {
F_45 ( F_16 ( V_2 -> V_11 ) ,
L_14 ) ;
F_73 ( V_2 -> V_53 ) ;
V_2 -> V_21 = 0 ;
V_2 -> V_53 = NULL ;
}
}
if ( V_165 -> V_167 == V_168 )
V_2 -> V_71 |= V_169 ;
else
V_2 -> V_71 &= ~ V_169 ;
if ( V_2 -> V_16 != V_165 -> V_16 ) {
F_20 ( V_2 , V_165 -> V_16 , V_165 -> V_17 ) ;
V_2 -> V_16 = V_165 -> V_16 ;
if ( V_165 -> V_16 == V_170 )
V_2 -> V_71 |= V_140 ;
}
if ( V_165 -> clock ) {
F_54 ( V_2 , V_165 -> clock ) ;
F_12 ( V_2 , V_25 , V_24 ) ;
} else {
F_12 ( V_2 , V_171 , V_24 ) ;
}
V_2 -> clock = V_165 -> clock ;
}
static T_4 F_74 ( int V_131 , void * V_30 )
{
struct V_139 * V_11 = V_30 ;
F_24 ( F_16 ( V_11 ) , L_15 , V_67 ) ;
F_66 ( V_11 , F_38 ( 250 ) ) ;
return V_138 ;
}
static int F_75 ( struct V_139 * V_11 )
{
struct V_1 * V_2 = F_68 ( V_11 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_172 )
return ! ! V_2 -> V_13 -> V_172 ( F_16 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
static void F_77 ( struct V_139 * V_11 , int V_173 )
{
struct V_1 * V_2 = F_68 ( V_11 ) ;
unsigned long V_41 ;
T_1 V_72 ;
F_46 ( & V_2 -> V_86 , V_41 ) ;
V_2 -> V_87 = V_173 ;
V_72 = F_3 ( V_2 , V_89 ) ;
if ( V_173 )
V_72 |= V_88 ;
else
V_72 &= ~ V_88 ;
F_7 ( V_2 , V_72 , V_89 ) ;
F_47 ( & V_2 -> V_86 , V_41 ) ;
}
static void F_78 ( struct V_139 * V_2 , struct V_174 * V_175 )
{
struct V_1 * V_176 = F_68 ( V_2 ) ;
if ( F_1 ( V_176 ) && V_175 -> type == V_177 )
V_2 -> V_178 &= ~ V_179 ;
else
V_2 -> V_178 |= V_179 ;
}
static bool F_79 ( struct V_180 * V_181 , void * V_182 )
{
struct V_1 * V_2 = V_182 ;
if ( ! F_80 ( V_181 ) )
return false ;
V_181 -> V_183 = & V_2 -> V_184 ;
return true ;
}
static void F_81 ( unsigned long V_30 )
{
struct V_139 * V_11 = (struct V_139 * ) V_30 ;
struct V_1 * V_2 = F_68 ( V_11 ) ;
struct V_95 * V_96 = V_2 -> V_96 ;
unsigned int V_64 = F_3 ( V_2 , V_65 ) ;
if ( V_2 -> V_48 == V_49 ) {
F_82 ( V_2 -> V_53 ) ;
F_45 ( F_16 ( V_2 -> V_11 ) ,
L_16 ,
V_67 , V_64 ) ;
} else {
F_45 ( F_16 ( V_2 -> V_11 ) ,
L_17 ,
V_67 , V_64 ) ;
F_23 ( V_2 ) ;
}
if ( V_2 -> V_30 )
V_2 -> V_30 -> error = - V_103 ;
V_2 -> V_96 = NULL ;
V_2 -> V_70 = NULL ;
V_2 -> V_30 = NULL ;
F_49 ( V_2 -> V_11 , V_96 ) ;
}
static int F_83 ( struct V_185 * V_186 )
{
struct V_139 * V_11 ;
struct V_1 * V_2 = NULL ;
struct V_187 * V_188 , * V_189 ;
int V_166 = 0 , V_131 ;
bool V_190 = false ;
T_5 V_116 ;
const struct V_191 * V_192 ;
struct V_193 * V_13 = V_186 -> V_55 . V_194 ;
F_84 ( L_18 ) ;
V_192 = F_85 ( V_195 , & V_186 -> V_55 ) ;
V_188 = F_86 ( V_186 , V_196 , 0 ) ;
V_131 = F_87 ( V_186 , 0 ) ;
if ( ! V_188 || V_131 < 0 )
return - V_57 ;
V_189 = F_88 ( V_188 -> V_156 , F_89 ( V_188 ) , V_186 -> V_197 ) ;
if ( ! V_189 )
return - V_198 ;
V_11 = F_90 ( sizeof( struct V_1 ) , & V_186 -> V_55 ) ;
if ( ! V_11 ) {
V_166 = - V_199 ;
goto V_200;
}
F_91 ( V_11 ) ;
V_11 -> V_201 = & V_202 ;
if ( V_13 )
V_11 -> V_178 = V_179 | V_203 ;
else
V_11 -> V_178 |= V_203 ;
V_11 -> V_204 = 2048 ;
V_11 -> V_205 = 65535 ;
V_11 -> V_206 = V_11 -> V_204 * V_11 -> V_205 ;
V_11 -> V_207 = V_11 -> V_206 ;
V_2 = F_68 ( V_11 ) ;
V_2 -> V_8 = F_92 ( V_189 -> V_156 , F_89 ( V_189 ) ) ;
if ( ! V_2 -> V_8 ) {
V_166 = - V_199 ;
goto V_208;
}
if ( V_192 ) {
const struct V_209 * V_210 = V_192 -> V_30 ;
V_2 -> V_3 = V_210 -> V_211 ;
} else {
V_2 -> V_3 = V_186 -> V_210 -> V_211 ;
}
if ( ! F_2 ( V_2 ) )
V_11 -> V_212 = 64 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_13 = V_13 ;
F_93 ( & V_2 -> V_86 ) ;
if ( V_13 )
V_190 = V_13 -> V_190 ;
else if ( ! ( V_11 -> V_178 & V_213 )
&& ! F_94 ( V_186 -> V_55 . V_214 , L_19 ) )
V_190 = true ;
F_14 ( V_2 ) ;
if ( V_190 )
V_2 -> V_73 =
V_215 | V_216 ;
else
V_2 -> V_73 = 0 ;
V_2 -> V_155 = V_189 ;
V_2 -> V_131 = V_131 ;
V_2 -> V_217 = F_95 ( & V_186 -> V_55 , L_20 ) ;
if ( F_17 ( V_2 -> V_217 ) ) {
V_166 = F_96 ( V_2 -> V_217 ) ;
goto V_218;
}
V_2 -> V_149 = F_95 ( & V_186 -> V_55 , L_21 ) ;
if ( F_17 ( V_2 -> V_149 ) ) {
V_166 = F_96 ( V_2 -> V_149 ) ;
goto V_218;
}
F_97 ( V_2 -> V_149 ) ;
F_97 ( V_2 -> V_217 ) ;
F_23 ( V_2 ) ;
V_2 -> V_219 = F_10 ( V_2 , V_220 ) ;
if ( V_2 -> V_219 != 0x400 ) {
V_166 = - V_221 ;
F_45 ( F_16 ( V_2 -> V_11 ) , L_22 ,
V_2 -> V_219 ) ;
goto V_222;
}
V_11 -> V_223 = F_69 ( V_2 -> V_149 ) >> 16 ;
V_11 -> V_224 = F_69 ( V_2 -> V_149 ) >> 1 ;
F_12 ( V_2 , 0x2db4 , V_225 ) ;
F_7 ( V_2 , V_2 -> V_73 , V_89 ) ;
if ( ! V_2 -> V_13 ) {
V_2 -> V_53 = F_98 ( & V_186 -> V_55 , L_23 ) ;
} else {
V_189 = F_86 ( V_186 , V_226 , 0 ) ;
if ( V_189 ) {
V_2 -> V_227 = V_189 -> V_156 ;
V_2 -> V_184 . V_228 = V_229 ;
V_2 -> V_184 . V_230 = V_231 ;
V_2 -> V_184 . V_232 = V_2 -> V_227 ;
F_99 ( V_116 ) ;
F_100 ( V_233 , V_116 ) ;
V_2 -> V_53 = F_101 ( V_116 , F_79 , V_2 ) ;
}
}
if ( V_2 -> V_53 )
V_11 -> V_207 = F_102 (
V_2 -> V_53 -> V_54 -> V_55 ) ;
else
F_103 ( F_16 ( V_2 -> V_11 ) , L_24 ) ;
F_104 ( & V_2 -> V_128 , F_60 ) ;
V_166 = F_105 ( V_2 -> V_131 , F_64 , 0 , V_234 , V_2 ) ;
if ( V_166 )
goto V_235;
F_106 ( V_186 , V_11 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_236 ) {
V_166 = V_2 -> V_13 -> V_236 ( & V_186 -> V_55 , F_74 ,
V_2 -> V_11 ) ;
if ( V_166 )
goto V_237;
}
F_107 ( & V_2 -> V_61 ) ;
V_2 -> V_61 . V_238 = & F_81 ;
V_2 -> V_61 . V_30 = ( unsigned long ) V_11 ;
F_108 ( V_11 ) ;
return 0 ;
V_237:
F_109 ( V_2 -> V_131 , V_2 ) ;
V_235:
if ( V_2 -> V_53 )
F_73 ( V_2 -> V_53 ) ;
V_222:
F_110 ( V_2 -> V_149 ) ;
F_110 ( V_2 -> V_217 ) ;
V_218:
F_111 ( V_2 -> V_8 ) ;
V_208:
F_112 ( V_11 ) ;
V_200:
F_113 ( V_188 -> V_156 , F_89 ( V_188 ) ) ;
return V_166 ;
}
static int F_114 ( struct V_185 * V_186 )
{
struct V_139 * V_11 = F_115 ( V_186 ) ;
struct V_1 * V_2 = F_68 ( V_11 ) ;
F_106 ( V_186 , NULL ) ;
F_116 ( V_11 ) ;
if ( V_2 -> V_10 )
F_117 ( V_2 -> V_10 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> exit )
V_2 -> V_13 -> exit ( & V_186 -> V_55 , V_11 ) ;
F_109 ( V_2 -> V_131 , V_2 ) ;
F_111 ( V_2 -> V_8 ) ;
if ( V_2 -> V_53 )
F_73 ( V_2 -> V_53 ) ;
F_110 ( V_2 -> V_149 ) ;
F_110 ( V_2 -> V_217 ) ;
F_113 ( V_2 -> V_155 -> V_156 , F_89 ( V_2 -> V_155 ) ) ;
F_112 ( V_11 ) ;
return 0 ;
}
static int F_118 ( struct V_54 * V_55 )
{
struct V_139 * V_11 = F_119 ( V_55 ) ;
struct V_1 * V_2 = F_68 ( V_11 ) ;
int V_166 = 0 ;
if ( V_11 )
V_166 = F_120 ( V_11 ) ;
F_110 ( V_2 -> V_149 ) ;
F_110 ( V_2 -> V_217 ) ;
return V_166 ;
}
static int F_121 ( struct V_54 * V_55 )
{
struct V_139 * V_11 = F_119 ( V_55 ) ;
struct V_1 * V_2 = F_68 ( V_11 ) ;
int V_166 = 0 ;
F_97 ( V_2 -> V_149 ) ;
F_97 ( V_2 -> V_217 ) ;
if ( V_11 )
V_166 = F_122 ( V_11 ) ;
return V_166 ;
}
