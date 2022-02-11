static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_5 = F_3 ( F_4 ( V_2 -> V_6 ) , L_1 ) ;
if ( F_5 ( V_2 -> V_5 ) ) {
V_2 -> V_5 = NULL ;
} else {
V_2 -> V_6 -> V_7 = F_6 ( V_2 -> V_5 ) ;
if ( V_2 -> V_8 && V_2 -> V_8 -> V_7 )
F_7 ( F_4 ( V_2 -> V_6 ) ,
L_2 ) ;
}
if ( V_2 -> V_5 == NULL ) {
if ( V_2 -> V_8 && V_2 -> V_8 -> V_7 )
V_2 -> V_6 -> V_7 = V_2 -> V_8 -> V_7 ;
else
V_2 -> V_6 -> V_7 = V_9 | V_10 ;
}
}
static inline void F_8 ( struct V_1 * V_2 ,
unsigned char V_11 ,
unsigned int V_12 )
{
if ( V_2 -> V_5 ) {
if ( V_11 == V_13 )
F_9 ( V_2 -> V_6 , V_2 -> V_5 , V_12 ) ;
else if ( V_11 == V_14 )
F_9 ( V_2 -> V_6 , V_2 -> V_5 , 0 ) ;
}
if ( V_2 -> V_8 && V_2 -> V_8 -> V_15 )
V_2 -> V_8 -> V_15 ( F_4 ( V_2 -> V_6 ) , V_12 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_17 ;
F_12 ( F_4 ( V_2 -> V_6 ) , L_3 ) ;
F_13 ( V_18 , V_2 -> V_19 + V_20 ) ;
F_13 ( V_18 | V_21 ,
V_2 -> V_19 + V_20 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_13 ( V_21 , V_2 -> V_19 + V_20 ) ;
F_13 ( 0xff , V_2 -> V_19 + V_22 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
unsigned int V_25 = V_24 -> V_26 ;
unsigned int V_27 = V_24 -> V_27 ;
unsigned int V_28 = V_25 * V_27 ;
struct V_29 * V_30 ;
enum V_31 V_32 ;
int V_17 , V_33 ;
if ( V_24 -> V_34 & V_35 )
V_25 = 0xffff ;
V_2 -> V_24 = V_24 ;
V_24 -> V_36 = 0 ;
F_13 ( V_25 , V_2 -> V_19 + V_37 ) ;
F_13 ( V_27 , V_2 -> V_19 + V_38 ) ;
V_2 -> V_28 = V_28 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
F_15 (data->sg, sg, data->sg_len, i) {
if ( V_30 -> V_39 & 3 || V_30 -> V_40 & 3 || V_30 -> V_40 < 512 ) {
V_2 -> V_16 = 0 ;
return 0 ;
}
}
if ( V_24 -> V_34 & V_41 ) {
V_2 -> V_42 = V_43 ;
V_32 = V_44 ;
} else {
V_2 -> V_42 = V_45 ;
V_32 = V_46 ;
}
V_33 = F_16 ( V_2 -> V_47 -> V_48 -> V_49 , V_24 -> V_30 ,
V_24 -> V_50 , V_2 -> V_42 ) ;
if ( V_33 != V_24 -> V_50 )
return - V_51 ;
V_2 -> V_52 = F_17 ( V_2 -> V_47 ,
V_24 -> V_30 , V_24 -> V_50 , V_32 ,
V_53 | V_54 ) ;
if ( ! V_2 -> V_52 ) {
F_18 ( V_2 -> V_47 -> V_48 -> V_49 , V_24 -> V_30 , V_24 -> V_50 ,
V_2 -> V_42 ) ;
V_2 -> V_16 = 0 ;
return 0 ;
}
F_19 () ;
F_20 ( V_2 -> V_52 ) ;
F_21 ( V_2 -> V_47 ) ;
F_22 ( & V_2 -> V_55 , V_56 + F_23 ( V_57 ) ) ;
return 0 ;
}
static void F_24 ( void * V_24 )
{
struct V_1 * V_2 = V_24 ;
T_1 V_58 ;
F_25 ( & V_2 -> V_55 ) ;
V_58 = F_26 ( V_2 -> V_19 + V_59 ) ;
F_27 ( V_58 & ~ V_60 , V_2 -> V_19 + V_59 ) ;
F_12 ( F_4 ( V_2 -> V_6 ) , L_4 , V_61 , V_58 ) ;
if ( V_58 & V_62 )
F_27 ( V_62 , V_2 -> V_19 + V_59 ) ;
F_28 ( V_2 , V_58 ) ;
}
static int F_29 ( struct V_1 * V_2 , struct V_63 * V_64 ,
unsigned int V_65 )
{
T_1 V_66 = V_2 -> V_67 ;
unsigned long V_34 ;
F_30 ( V_2 -> V_64 != NULL ) ;
V_2 -> V_64 = V_64 ;
switch ( F_31 ( V_64 ) ) {
case V_68 :
case V_69 :
V_65 |= V_70 ;
break;
case V_71 :
V_65 |= V_72 ;
break;
case V_73 :
V_65 |= V_74 ;
break;
case V_75 :
break;
default:
F_32 ( F_4 ( V_2 -> V_6 ) , L_5 ,
F_31 ( V_64 ) ) ;
V_64 -> error = - V_51 ;
return - V_51 ;
}
V_66 = V_76 ;
if ( F_10 ( V_2 ) ) {
if ( V_2 -> V_42 == V_43 ) {
V_2 -> V_52 -> V_77 = F_24 ;
V_2 -> V_52 -> V_78 = V_2 ;
} else {
V_66 |= V_79 ;
}
}
F_33 ( & V_2 -> V_80 , V_34 ) ;
if ( V_2 -> V_81 )
V_66 |= V_82 ;
F_27 ( V_66 , V_2 -> V_19 + V_83 ) ;
F_34 ( & V_2 -> V_80 , V_34 ) ;
F_13 ( V_64 -> V_84 , V_2 -> V_19 + V_85 ) ;
F_27 ( V_64 -> V_86 , V_2 -> V_19 + V_87 ) ;
F_13 ( V_65 , V_2 -> V_19 + V_88 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
T_1 V_66 = V_2 -> V_67 ;
unsigned long V_34 ;
F_33 ( & V_2 -> V_80 , V_34 ) ;
if ( V_2 -> V_81 )
V_66 |= V_82 ;
F_27 ( V_66 , V_2 -> V_19 + V_83 ) ;
F_34 ( & V_2 -> V_80 , V_34 ) ;
V_2 -> V_90 = NULL ;
V_2 -> V_64 = NULL ;
V_2 -> V_24 = NULL ;
F_36 ( V_2 -> V_6 , V_90 ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_58 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
int V_91 ;
if ( F_10 ( V_2 ) )
F_18 ( V_2 -> V_47 -> V_48 -> V_49 , V_24 -> V_30 , V_24 -> V_50 ,
V_2 -> V_42 ) ;
if ( V_58 & V_92 ) {
F_12 ( F_4 ( V_2 -> V_6 ) , L_6 ,
V_58 ) ;
if ( V_58 & V_93 ) {
F_32 ( F_4 ( V_2 -> V_6 ) , L_7 , V_61 ) ;
V_24 -> error = - V_94 ;
} else if ( V_58 & V_95 ) {
T_1 V_96 = ( V_58 >> 9 ) & 0x3 ;
if ( V_96 == 2 ) {
F_32 ( F_4 ( V_2 -> V_6 ) ,
L_8 , V_61 ) ;
V_24 -> error = - V_97 ;
} else {
F_32 ( F_4 ( V_2 -> V_6 ) ,
L_7 , V_61 ) ;
V_24 -> error = - V_94 ;
}
} else if ( V_58 & V_98 ) {
F_32 ( F_4 ( V_2 -> V_6 ) ,
L_9 , V_61 ) ;
V_24 -> error = - V_97 ;
} else {
F_32 ( F_4 ( V_2 -> V_6 ) , L_10 , V_61 ) ;
V_24 -> error = - V_99 ;
}
} else {
V_24 -> V_36 = V_2 -> V_28 ;
}
V_91 = V_24 -> error ;
V_2 -> V_24 = NULL ;
return V_91 ;
}
static void F_38 ( struct V_1 * V_2 , unsigned int V_58 )
{
struct V_63 * V_64 = V_2 -> V_64 ;
int V_17 ;
T_1 V_100 , V_101 , V_102 ;
if ( ! V_64 )
return;
if ( V_58 & V_103 ) {
F_12 ( F_4 ( V_2 -> V_6 ) , L_11 ) ;
V_64 -> error = - V_97 ;
} else if ( V_58 & V_104 && V_64 -> V_34 & V_105 ) {
F_12 ( F_4 ( V_2 -> V_6 ) , L_12 ) ;
V_64 -> error = - V_94 ;
}
if ( V_64 -> V_34 & V_106 ) {
if ( V_64 -> V_34 & V_107 ) {
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
V_100 = F_39 ( V_2 -> V_19 + V_108 ) ;
V_101 = F_39 ( V_2 -> V_19 + V_108 ) ;
V_64 -> V_109 [ V_17 ] = V_100 << 16 | V_101 ;
}
} else {
V_100 = F_39 ( V_2 -> V_19 + V_108 ) ;
V_101 = F_39 ( V_2 -> V_19 + V_108 ) ;
V_102 = F_39 ( V_2 -> V_19 + V_108 ) ;
V_64 -> V_109 [ 0 ] = V_100 << 24 | V_101 << 8 | V_102 >> 8 ;
}
}
}
static int F_40 ( struct V_1 * V_2 , T_1 V_110 )
{
T_1 V_58 ;
unsigned long V_111 = V_56 + V_112 ;
do {
V_58 = F_26 ( V_2 -> V_19 + V_59 ) ;
if ( V_58 & V_92 )
return V_58 ;
if ( F_41 ( V_56 , V_111 ) ) {
F_11 ( V_2 ) ;
F_42 ( V_2 , V_2 -> clock ) ;
return V_98 ;
}
if ( V_58 & V_110 )
return 0 ;
F_43 () ;
} while ( 1 );
}
static int F_44 ( struct V_1 * V_2 , void * V_113 , int V_114 )
{
unsigned int V_58 ;
T_1 * V_115 = V_113 ;
while ( V_114 > 3 ) {
V_58 = F_40 ( V_2 ,
V_116 | V_62 ) ;
if ( V_58 )
return V_58 ;
* V_115 ++ = F_26 ( V_2 -> V_19 + V_117 ) ;
V_114 -= 4 ;
}
if ( V_114 ) {
T_2 * V_101 = ( T_2 * ) V_115 ;
T_1 V_118 ;
V_58 = F_40 ( V_2 ,
V_116 | V_62 ) ;
if ( V_58 )
return V_58 ;
V_118 = F_26 ( V_2 -> V_19 + V_117 ) ;
memcpy ( V_101 , & V_118 , V_114 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , void * V_113 , int V_114 )
{
unsigned int V_58 ;
T_1 * V_115 = V_113 ;
while ( V_114 > 3 ) {
V_58 = F_40 ( V_2 , V_119 ) ;
if ( V_58 )
return V_58 ;
F_27 ( * V_115 ++ , V_2 -> V_19 + V_117 ) ;
V_114 -= 4 ;
}
if ( V_114 ) {
T_2 * V_101 = ( T_2 * ) V_115 ;
T_1 V_118 ;
V_58 = F_40 ( V_2 , V_119 ) ;
if ( V_58 )
return V_58 ;
memcpy ( & V_118 , V_101 , V_114 ) ;
F_27 ( V_118 , V_2 -> V_19 + V_117 ) ;
}
V_58 = F_40 ( V_2 , V_119 ) ;
if ( V_58 )
return V_58 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_90 -> V_24 ;
struct V_29 * V_30 ;
int V_58 , V_17 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_28 = 0 ;
if ( V_24 -> V_34 & V_41 ) {
F_15 (data->sg, sg, data->sg_len, i) {
V_58 = F_44 ( V_2 , F_47 ( V_30 ) , V_30 -> V_40 ) ;
if ( V_58 )
return V_58 ;
V_2 -> V_28 += V_30 -> V_40 ;
}
} else {
F_15 (data->sg, sg, data->sg_len, i) {
V_58 = F_45 ( V_2 , F_47 ( V_30 ) , V_30 -> V_40 ) ;
if ( V_58 )
return V_58 ;
V_2 -> V_28 += V_30 -> V_40 ;
}
V_58 = F_40 ( V_2 , V_120 ) ;
if ( V_58 )
return V_58 ;
}
return 0 ;
}
static void F_48 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_49 ( V_122 , struct V_1 ,
V_123 ) ;
int V_124 = F_46 ( V_2 ) ;
F_27 ( V_62 | V_120 ,
V_2 -> V_19 + V_59 ) ;
F_37 ( V_2 , V_124 ) ;
if ( V_2 -> V_90 -> V_125 ) {
if ( F_29 ( V_2 , V_2 -> V_90 -> V_125 , 0 ) ) {
F_35 ( V_2 , V_2 -> V_90 ) ;
return;
}
} else {
F_35 ( V_2 , V_2 -> V_90 ) ;
}
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_58 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
int V_91 ;
if ( ! V_24 )
return;
V_91 = F_37 ( V_2 , V_58 ) ;
F_38 ( V_2 , V_58 ) ;
V_2 -> V_64 = NULL ;
if ( V_2 -> V_90 -> V_125 ) {
if ( F_29 ( V_2 , V_2 -> V_90 -> V_125 , 0 ) ) {
F_35 ( V_2 , V_2 -> V_90 ) ;
return;
}
} else {
F_35 ( V_2 , V_2 -> V_90 ) ;
}
}
static void F_50 ( struct V_1 * V_2 , unsigned int V_58 )
{
F_38 ( V_2 , V_58 ) ;
V_2 -> V_64 = NULL ;
if ( ! V_2 -> V_24 && V_2 -> V_90 ) {
F_35 ( V_2 , V_2 -> V_90 ) ;
return;
}
if ( ! F_10 ( V_2 ) && V_2 -> V_24 )
F_51 ( & V_2 -> V_123 ) ;
}
static T_3 F_52 ( int V_126 , void * V_127 )
{
struct V_1 * V_2 = V_127 ;
unsigned long V_34 ;
bool V_128 ;
T_1 V_58 ;
V_58 = F_26 ( V_2 -> V_19 + V_59 ) ;
F_27 ( V_58 & ~ ( V_129 | V_60 |
V_120 ) , V_2 -> V_19 + V_59 ) ;
F_12 ( F_4 ( V_2 -> V_6 ) , L_4 , V_61 , V_58 ) ;
F_33 ( & V_2 -> V_80 , V_34 ) ;
V_128 = ( V_58 & V_129 ) && V_2 -> V_81 ;
F_34 ( & V_2 -> V_80 , V_34 ) ;
if ( F_10 ( V_2 ) &&
( V_58 & ( V_62 | V_120 ) ) )
F_27 ( V_62 | V_120 ,
V_2 -> V_19 + V_59 ) ;
if ( V_128 ) {
F_27 ( V_129 , V_2 -> V_19 + V_59 ) ;
F_53 ( V_2 -> V_6 ) ;
}
if ( V_58 & V_130 )
F_50 ( V_2 , V_58 ) ;
if ( F_10 ( V_2 ) &&
( V_58 & ( V_60 | V_120 ) ) ) {
F_25 ( & V_2 -> V_55 ) ;
F_28 ( V_2 , V_58 ) ;
}
if ( V_2 -> V_67 &&
( V_58 & ( V_131 | V_132 ) ) )
F_54 ( V_2 -> V_6 , F_23 ( 200 ) ) ;
return V_133 ;
}
static void F_55 ( struct V_134 * V_6 , struct V_89 * V_90 )
{
struct V_1 * V_2 = F_56 ( V_6 ) ;
unsigned int V_65 = V_2 -> V_65 ;
int error ;
F_30 ( V_2 -> V_90 != NULL ) ;
V_2 -> V_90 = V_90 ;
V_2 -> V_65 &= ~ V_135 ;
if ( V_2 -> V_47 )
V_2 -> V_16 = 1 ;
if ( V_90 -> V_24 ) {
error = F_14 ( V_2 , V_90 -> V_24 ) ;
if ( error ) {
V_90 -> V_64 -> error = error ;
goto V_136;
}
V_65 |= V_137 ;
if ( V_90 -> V_24 -> V_34 & V_138 )
V_65 |= V_139 ;
}
error = F_29 ( V_2 , V_90 -> V_64 , V_65 ) ;
V_136:
if ( error )
F_35 ( V_2 , V_90 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_140 )
{
unsigned int V_141 ;
int V_142 = 0 ;
unsigned int V_143 = F_57 ( V_2 -> V_144 ) ;
while ( V_142 <= 0x800 ) {
for ( V_141 = 1 ; V_141 <= 0xF ; V_141 ++ ) {
int V_145 ;
V_145 = ( V_143 / ( V_141 + 1 ) ) ;
if ( V_142 )
V_145 /= ( V_142 * 2 ) ;
if ( V_145 <= V_140 )
break;
}
if ( V_141 < 0x10 )
break;
if ( V_142 == 0 )
V_142 = 1 ;
else
V_142 <<= 1 ;
}
F_13 ( ( V_142 << 4 ) | V_141 , V_2 -> V_19 + V_146 ) ;
F_12 ( F_4 ( V_2 -> V_6 ) , L_13 ,
V_142 , V_141 , V_143 , V_140 ) ;
}
static int F_58 ( struct V_134 * V_6 )
{
struct V_1 * V_2 = F_56 ( V_6 ) ;
struct V_147 * V_148 = & V_2 -> V_147 ;
V_148 -> V_149 = V_2 -> V_150 -> V_151 + V_117 ;
V_148 -> V_152 = V_2 -> V_150 -> V_151 + V_117 ;
V_148 -> V_153 = 4 ;
V_148 -> V_154 = 4 ;
V_148 -> V_155 = V_2 -> V_156 ;
V_148 -> V_157 = V_2 -> V_156 ;
V_148 -> V_158 = false ;
return F_59 ( V_2 -> V_47 , V_148 ) ;
}
static void F_60 ( struct V_134 * V_6 , struct V_159 * V_160 )
{
struct V_1 * V_2 = F_56 ( V_6 ) ;
int V_156 , V_161 ;
if ( V_160 -> V_162 == V_163 )
V_156 = 16 ;
else
V_156 = 4 ;
if ( F_10 ( V_2 ) && V_156 != V_2 -> V_156 ) {
V_2 -> V_156 = V_156 ;
V_161 = F_58 ( V_6 ) ;
if ( V_161 ) {
F_32 ( F_4 ( V_2 -> V_6 ) ,
L_14 ) ;
F_61 ( V_2 -> V_47 ) ;
V_2 -> V_16 = 0 ;
V_2 -> V_47 = NULL ;
}
}
if ( V_160 -> V_162 == V_163 )
V_2 -> V_65 |= V_164 ;
else
V_2 -> V_65 &= ~ V_164 ;
if ( V_2 -> V_11 != V_160 -> V_11 ) {
F_8 ( V_2 , V_160 -> V_11 , V_160 -> V_12 ) ;
V_2 -> V_11 = V_160 -> V_11 ;
if ( V_160 -> V_11 == V_165 )
V_2 -> V_65 |= V_135 ;
}
if ( V_160 -> clock ) {
F_42 ( V_2 , V_160 -> clock ) ;
F_13 ( V_21 , V_2 -> V_19 + V_20 ) ;
} else {
F_13 ( V_166 , V_2 -> V_19 + V_20 ) ;
}
V_2 -> clock = V_160 -> clock ;
}
static T_3 F_62 ( int V_126 , void * V_24 )
{
struct V_134 * V_6 = V_24 ;
F_12 ( F_4 ( V_6 ) , L_15 , V_61 ) ;
F_54 ( V_6 , F_23 ( 250 ) ) ;
return V_133 ;
}
static int F_63 ( struct V_134 * V_6 )
{
struct V_1 * V_2 = F_56 ( V_6 ) ;
if ( V_2 -> V_8 && V_2 -> V_8 -> V_167 )
return ! ! V_2 -> V_8 -> V_167 ( F_4 ( V_6 ) ) ;
return - V_168 ;
}
static void F_64 ( struct V_134 * V_6 , int V_169 )
{
struct V_1 * V_2 = F_56 ( V_6 ) ;
unsigned long V_34 ;
T_1 V_66 ;
F_33 ( & V_2 -> V_80 , V_34 ) ;
V_2 -> V_81 = V_169 ;
V_66 = F_26 ( V_2 -> V_19 + V_83 ) ;
if ( V_169 )
V_66 |= V_82 ;
else
V_66 &= ~ V_82 ;
F_27 ( V_66 , V_2 -> V_19 + V_83 ) ;
F_34 ( & V_2 -> V_80 , V_34 ) ;
}
static void F_65 ( struct V_134 * V_2 , struct V_170 * V_171 )
{
struct V_1 * V_172 = F_56 ( V_2 ) ;
if ( F_1 ( V_172 ) && V_171 -> type == V_173 )
V_2 -> V_174 &= ~ V_175 ;
else
V_2 -> V_174 |= V_175 ;
}
static bool F_66 ( struct V_176 * V_177 , void * V_178 )
{
struct V_1 * V_2 = V_178 ;
if ( ! F_67 ( V_177 ) )
return false ;
V_177 -> V_179 = & V_2 -> V_180 ;
return true ;
}
static void F_68 ( unsigned long V_24 )
{
struct V_134 * V_6 = (struct V_134 * ) V_24 ;
struct V_1 * V_2 = F_56 ( V_6 ) ;
struct V_89 * V_90 = V_2 -> V_90 ;
unsigned int V_58 = F_26 ( V_2 -> V_19 + V_59 ) ;
if ( V_2 -> V_42 == V_43 ) {
F_69 ( V_2 -> V_47 ) ;
F_32 ( F_4 ( V_2 -> V_6 ) ,
L_16 ,
V_61 , V_58 ) ;
} else {
F_32 ( F_4 ( V_2 -> V_6 ) ,
L_17 ,
V_61 , V_58 ) ;
F_11 ( V_2 ) ;
}
V_2 -> V_24 -> error = - V_97 ;
V_2 -> V_90 = NULL ;
V_2 -> V_64 = NULL ;
V_2 -> V_24 = NULL ;
F_36 ( V_2 -> V_6 , V_90 ) ;
}
static int F_70 ( struct V_181 * V_182 )
{
struct V_134 * V_6 ;
struct V_1 * V_2 = NULL ;
struct V_183 * V_184 , * V_185 ;
int V_161 = 0 , V_126 ;
T_4 V_110 ;
F_71 ( L_18 ) ;
V_184 = F_72 ( V_182 , V_186 , 0 ) ;
V_126 = F_73 ( V_182 , 0 ) ;
if ( ! V_184 || V_126 < 0 )
return - V_51 ;
V_185 = F_74 ( V_184 -> V_151 , F_75 ( V_184 ) , V_182 -> V_187 ) ;
if ( ! V_185 )
return - V_188 ;
V_6 = F_76 ( sizeof( struct V_1 ) , & V_182 -> V_49 ) ;
if ( ! V_6 ) {
V_161 = - V_189 ;
goto V_190;
}
V_6 -> V_191 = & V_192 ;
V_6 -> V_174 = V_175 | V_193 ;
V_6 -> V_194 = 64 ;
V_6 -> V_195 = 2048 ;
V_6 -> V_196 = 65535 ;
V_6 -> V_197 = V_6 -> V_195 * V_6 -> V_196 ;
V_6 -> V_198 = V_6 -> V_197 ;
V_2 = F_56 ( V_6 ) ;
V_2 -> V_19 = F_77 ( V_185 -> V_151 , F_75 ( V_185 ) ) ;
if ( ! V_2 -> V_19 ) {
V_161 = - V_189 ;
goto V_199;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = V_182 -> V_49 . V_200 ;
V_2 -> V_3 = V_182 -> V_201 -> V_202 ;
F_78 ( & V_2 -> V_80 ) ;
F_2 ( V_2 ) ;
if ( V_2 -> V_8 && V_2 -> V_8 -> V_203 )
V_2 -> V_67 =
V_204 | V_205 ;
else
V_2 -> V_67 = 0 ;
V_2 -> V_150 = V_185 ;
V_2 -> V_126 = V_126 ;
V_2 -> V_206 = F_79 ( & V_182 -> V_49 , L_19 ) ;
if ( F_5 ( V_2 -> V_206 ) ) {
V_161 = F_80 ( V_2 -> V_206 ) ;
goto V_207;
}
V_2 -> V_144 = F_79 ( & V_182 -> V_49 , L_20 ) ;
if ( F_5 ( V_2 -> V_144 ) ) {
V_161 = F_80 ( V_2 -> V_144 ) ;
goto V_207;
}
F_81 ( V_2 -> V_144 ) ;
F_81 ( V_2 -> V_206 ) ;
F_11 ( V_2 ) ;
V_2 -> V_208 = F_39 ( V_2 -> V_19 + V_209 ) ;
if ( V_2 -> V_208 != 0x400 ) {
V_161 = - V_210 ;
F_32 ( F_4 ( V_2 -> V_6 ) , L_21 ,
V_2 -> V_208 ) ;
goto V_211;
}
V_6 -> V_212 = F_57 ( V_2 -> V_144 ) >> 16 ;
V_6 -> V_213 = F_57 ( V_2 -> V_144 ) >> 1 ;
F_13 ( 0x2db4 , V_2 -> V_19 + V_214 ) ;
F_27 ( V_2 -> V_67 , V_2 -> V_19 + V_83 ) ;
V_185 = F_72 ( V_182 , V_215 , 0 ) ;
if ( V_185 ) {
V_2 -> V_216 = V_185 -> V_151 ;
V_2 -> V_180 . V_217 = V_218 ;
V_2 -> V_180 . V_219 = V_220 ;
V_2 -> V_180 . V_221 = V_2 -> V_216 ;
F_82 ( V_110 ) ;
F_83 ( V_222 , V_110 ) ;
V_2 -> V_47 = F_84 ( V_110 , F_66 , V_2 ) ;
if ( V_2 -> V_47 )
V_6 -> V_198 = F_85 (
V_2 -> V_47 -> V_48 -> V_49 ) ;
}
if ( ! V_2 -> V_47 )
F_86 ( F_4 ( V_2 -> V_6 ) , L_22 ) ;
F_87 ( & V_2 -> V_123 , F_48 ) ;
V_161 = F_88 ( V_2 -> V_126 , F_52 , 0 , V_223 , V_2 ) ;
if ( V_161 )
goto V_224;
F_89 ( V_182 , V_6 ) ;
if ( V_2 -> V_8 && V_2 -> V_8 -> V_225 ) {
V_161 = V_2 -> V_8 -> V_225 ( & V_182 -> V_49 , F_62 ,
V_2 -> V_6 ) ;
if ( V_161 )
goto V_226;
}
F_90 ( V_6 ) ;
F_91 ( & V_2 -> V_55 ) ;
V_2 -> V_55 . V_227 = & F_68 ;
V_2 -> V_55 . V_24 = ( unsigned long ) V_6 ;
return 0 ;
V_226:
F_92 ( V_2 -> V_126 , V_2 ) ;
V_224:
if ( V_2 -> V_47 )
F_61 ( V_2 -> V_47 ) ;
V_211:
F_93 ( V_2 -> V_144 ) ;
F_93 ( V_2 -> V_206 ) ;
V_207:
F_94 ( V_2 -> V_19 ) ;
V_199:
F_95 ( V_6 ) ;
V_190:
F_96 ( V_184 -> V_151 , F_75 ( V_184 ) ) ;
return V_161 ;
}
static int F_97 ( struct V_181 * V_182 )
{
struct V_134 * V_6 = F_98 ( V_182 ) ;
struct V_1 * V_2 = F_56 ( V_6 ) ;
F_89 ( V_182 , NULL ) ;
F_99 ( V_6 ) ;
if ( V_2 -> V_5 )
F_100 ( V_2 -> V_5 ) ;
if ( V_2 -> V_8 && V_2 -> V_8 -> exit )
V_2 -> V_8 -> exit ( & V_182 -> V_49 , V_6 ) ;
F_92 ( V_2 -> V_126 , V_2 ) ;
F_94 ( V_2 -> V_19 ) ;
if ( V_2 -> V_47 )
F_61 ( V_2 -> V_47 ) ;
F_93 ( V_2 -> V_144 ) ;
F_93 ( V_2 -> V_206 ) ;
F_96 ( V_2 -> V_150 -> V_151 , F_75 ( V_2 -> V_150 ) ) ;
F_95 ( V_6 ) ;
return 0 ;
}
static int F_101 ( struct V_48 * V_49 )
{
struct V_134 * V_6 = F_102 ( V_49 ) ;
struct V_1 * V_2 = F_56 ( V_6 ) ;
int V_161 = 0 ;
if ( V_6 )
V_161 = F_103 ( V_6 ) ;
F_93 ( V_2 -> V_144 ) ;
F_93 ( V_2 -> V_206 ) ;
return V_161 ;
}
static int F_104 ( struct V_48 * V_49 )
{
struct V_134 * V_6 = F_102 ( V_49 ) ;
struct V_1 * V_2 = F_56 ( V_6 ) ;
int V_161 = 0 ;
F_81 ( V_2 -> V_144 ) ;
F_81 ( V_2 -> V_206 ) ;
if ( V_6 )
V_161 = F_105 ( V_6 ) ;
return V_161 ;
}
