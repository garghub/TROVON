static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( F_3 ( V_2 -> V_4 ) , L_1 ) ;
if ( F_4 ( V_2 -> V_3 ) ) {
V_2 -> V_3 = NULL ;
} else {
V_2 -> V_4 -> V_5 = F_5 ( V_2 -> V_3 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> V_5 )
F_6 ( F_3 ( V_2 -> V_4 ) ,
L_2 ) ;
}
if ( V_2 -> V_3 == NULL ) {
if ( V_2 -> V_6 && V_2 -> V_6 -> V_5 )
V_2 -> V_4 -> V_5 = V_2 -> V_6 -> V_5 ;
else
V_2 -> V_4 -> V_5 = V_7 | V_8 ;
}
}
static inline void F_7 ( struct V_1 * V_2 ,
unsigned char V_9 ,
unsigned int V_10 )
{
if ( V_2 -> V_3 ) {
if ( V_9 == V_11 )
F_8 ( V_2 -> V_4 , V_2 -> V_3 , V_10 ) ;
else if ( V_9 == V_12 )
F_8 ( V_2 -> V_4 , V_2 -> V_3 , 0 ) ;
}
if ( V_2 -> V_6 && V_2 -> V_6 -> V_13 )
V_2 -> V_6 -> V_13 ( F_3 ( V_2 -> V_4 ) , V_10 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_14 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_15 ;
F_11 ( F_3 ( V_2 -> V_4 ) , L_3 ) ;
F_12 ( V_16 , V_2 -> V_17 + V_18 ) ;
F_12 ( V_16 | V_19 ,
V_2 -> V_17 + V_18 ) ;
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ )
F_12 ( V_19 , V_2 -> V_17 + V_18 ) ;
F_12 ( 0xff , V_2 -> V_17 + V_20 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
unsigned int V_23 = V_22 -> V_24 ;
unsigned int V_25 = V_22 -> V_25 ;
unsigned int V_26 = V_23 * V_25 ;
struct V_27 * V_28 ;
enum V_29 V_30 ;
int V_15 , V_31 ;
if ( V_22 -> V_32 & V_33 )
V_23 = 0xffff ;
V_2 -> V_22 = V_22 ;
V_22 -> V_34 = 0 ;
F_12 ( V_23 , V_2 -> V_17 + V_35 ) ;
F_12 ( V_25 , V_2 -> V_17 + V_36 ) ;
V_2 -> V_26 = V_26 ;
if ( ! F_9 ( V_2 ) )
return 0 ;
F_14 (data->sg, sg, data->sg_len, i) {
if ( V_28 -> V_37 & 3 || V_28 -> V_38 & 3 ) {
V_2 -> V_14 = 0 ;
return 0 ;
}
}
if ( V_22 -> V_32 & V_39 ) {
V_2 -> V_40 = V_41 ;
V_30 = V_42 ;
} else {
V_2 -> V_40 = V_43 ;
V_30 = V_44 ;
}
V_31 = F_15 ( V_2 -> V_45 -> V_46 -> V_47 , V_22 -> V_28 ,
V_22 -> V_48 , V_2 -> V_40 ) ;
if ( V_31 != V_22 -> V_48 )
return - V_49 ;
V_2 -> V_50 = F_16 ( V_2 -> V_45 ,
V_22 -> V_28 , V_22 -> V_48 , V_30 ,
V_51 | V_52 ) ;
if ( ! V_2 -> V_50 ) {
F_17 ( V_2 -> V_45 -> V_46 -> V_47 , V_22 -> V_28 , V_22 -> V_48 ,
V_2 -> V_40 ) ;
V_2 -> V_14 = 0 ;
return 0 ;
}
F_18 () ;
F_19 ( V_2 -> V_50 ) ;
F_20 ( V_2 -> V_45 ) ;
F_21 ( & V_2 -> V_53 , V_54 + F_22 ( V_55 ) ) ;
return 0 ;
}
static void F_23 ( void * V_22 )
{
struct V_1 * V_2 = V_22 ;
T_1 V_56 ;
F_24 ( & V_2 -> V_53 ) ;
V_56 = F_25 ( V_2 -> V_17 + V_57 ) ;
F_26 ( V_56 & ~ V_58 , V_2 -> V_17 + V_57 ) ;
F_11 ( F_3 ( V_2 -> V_4 ) , L_4 , V_59 , V_56 ) ;
if ( V_56 & V_60 )
F_26 ( V_60 , V_2 -> V_17 + V_57 ) ;
F_27 ( V_2 , V_56 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_61 * V_62 ,
unsigned int V_63 )
{
T_1 V_64 = V_2 -> V_65 ;
unsigned long V_32 ;
F_29 ( V_2 -> V_62 != NULL ) ;
V_2 -> V_62 = V_62 ;
switch ( F_30 ( V_62 ) ) {
case V_66 :
case V_67 :
V_63 |= V_68 ;
break;
case V_69 :
V_63 |= V_70 ;
break;
case V_71 :
V_63 |= V_72 ;
break;
case V_73 :
break;
default:
F_31 ( F_3 ( V_2 -> V_4 ) , L_5 ,
F_30 ( V_62 ) ) ;
V_62 -> error = - V_49 ;
return - V_49 ;
}
V_64 = V_74 ;
if ( F_9 ( V_2 ) ) {
if ( V_2 -> V_40 == V_41 ) {
V_2 -> V_50 -> V_75 = F_23 ;
V_2 -> V_50 -> V_76 = V_2 ;
} else {
V_64 |= V_77 ;
}
}
F_32 ( & V_2 -> V_78 , V_32 ) ;
if ( V_2 -> V_79 )
V_64 |= V_80 ;
F_26 ( V_64 , V_2 -> V_17 + V_81 ) ;
F_33 ( & V_2 -> V_78 , V_32 ) ;
F_12 ( V_62 -> V_82 , V_2 -> V_17 + V_83 ) ;
F_26 ( V_62 -> V_84 , V_2 -> V_17 + V_85 ) ;
F_12 ( V_63 , V_2 -> V_17 + V_86 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
T_1 V_64 = V_2 -> V_65 ;
unsigned long V_32 ;
F_32 ( & V_2 -> V_78 , V_32 ) ;
if ( V_2 -> V_79 )
V_64 |= V_80 ;
F_26 ( V_64 , V_2 -> V_17 + V_81 ) ;
F_33 ( & V_2 -> V_78 , V_32 ) ;
V_2 -> V_88 = NULL ;
V_2 -> V_62 = NULL ;
V_2 -> V_22 = NULL ;
F_35 ( V_2 -> V_4 , V_88 ) ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int V_56 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_89 ;
if ( F_9 ( V_2 ) )
F_17 ( V_2 -> V_45 -> V_46 -> V_47 , V_22 -> V_28 , V_22 -> V_48 ,
V_2 -> V_40 ) ;
if ( V_56 & V_90 ) {
F_11 ( F_3 ( V_2 -> V_4 ) , L_6 ,
V_56 ) ;
if ( V_56 & V_91 ) {
F_31 ( F_3 ( V_2 -> V_4 ) , L_7 , V_59 ) ;
V_22 -> error = - V_92 ;
} else if ( V_56 & V_93 ) {
T_1 V_94 = ( V_56 >> 9 ) & 0x3 ;
if ( V_94 == 2 ) {
F_31 ( F_3 ( V_2 -> V_4 ) ,
L_8 , V_59 ) ;
V_22 -> error = - V_95 ;
} else {
F_31 ( F_3 ( V_2 -> V_4 ) ,
L_7 , V_59 ) ;
V_22 -> error = - V_92 ;
}
} else if ( V_56 & V_96 ) {
F_31 ( F_3 ( V_2 -> V_4 ) ,
L_9 , V_59 ) ;
V_22 -> error = - V_95 ;
} else {
F_31 ( F_3 ( V_2 -> V_4 ) , L_10 , V_59 ) ;
V_22 -> error = - V_97 ;
}
} else {
V_22 -> V_34 = V_2 -> V_26 ;
}
V_89 = V_22 -> error ;
V_2 -> V_22 = NULL ;
return V_89 ;
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_56 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
int V_15 ;
T_1 V_98 , V_99 , V_100 ;
if ( ! V_62 )
return;
if ( V_56 & V_101 ) {
F_11 ( F_3 ( V_2 -> V_4 ) , L_11 ) ;
V_62 -> error = - V_95 ;
} else if ( V_56 & V_102 && V_62 -> V_32 & V_103 ) {
F_11 ( F_3 ( V_2 -> V_4 ) , L_12 ) ;
V_62 -> error = - V_92 ;
}
if ( V_62 -> V_32 & V_104 ) {
if ( V_62 -> V_32 & V_105 ) {
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_98 = F_38 ( V_2 -> V_17 + V_106 ) ;
V_99 = F_38 ( V_2 -> V_17 + V_106 ) ;
V_62 -> V_107 [ V_15 ] = V_98 << 16 | V_99 ;
}
} else {
V_98 = F_38 ( V_2 -> V_17 + V_106 ) ;
V_99 = F_38 ( V_2 -> V_17 + V_106 ) ;
V_100 = F_38 ( V_2 -> V_17 + V_106 ) ;
V_62 -> V_107 [ 0 ] = V_98 << 24 | V_99 << 8 | V_100 >> 8 ;
}
}
}
static int F_39 ( struct V_1 * V_2 , T_1 V_108 )
{
T_1 V_56 ;
unsigned long V_109 = V_54 + V_110 ;
do {
V_56 = F_25 ( V_2 -> V_17 + V_57 ) ;
if ( V_56 & V_90 )
return V_56 ;
if ( F_40 ( V_54 , V_109 ) ) {
F_10 ( V_2 ) ;
F_41 ( V_2 , V_2 -> clock ) ;
return V_96 ;
}
if ( V_56 & V_108 )
return 0 ;
F_42 () ;
} while ( 1 );
}
static int F_43 ( struct V_1 * V_2 , void * V_111 , int V_112 )
{
unsigned int V_56 ;
T_1 * V_113 = V_111 ;
while ( V_112 > 3 ) {
V_56 = F_39 ( V_2 ,
V_114 | V_60 ) ;
if ( V_56 )
return V_56 ;
* V_113 ++ = F_25 ( V_2 -> V_17 + V_115 ) ;
V_112 -= 4 ;
}
if ( V_112 ) {
T_2 * V_99 = ( T_2 * ) V_113 ;
T_1 V_116 ;
V_56 = F_39 ( V_2 ,
V_114 | V_60 ) ;
if ( V_56 )
return V_56 ;
V_116 = F_25 ( V_2 -> V_17 + V_115 ) ;
memcpy ( V_99 , & V_116 , V_112 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , void * V_111 , int V_112 )
{
unsigned int V_56 ;
T_1 * V_113 = V_111 ;
while ( V_112 > 3 ) {
V_56 = F_39 ( V_2 , V_117 ) ;
if ( V_56 )
return V_56 ;
F_26 ( * V_113 ++ , V_2 -> V_17 + V_115 ) ;
V_112 -= 4 ;
}
if ( V_112 ) {
T_2 * V_99 = ( T_2 * ) V_113 ;
T_1 V_116 ;
V_56 = F_39 ( V_2 , V_117 ) ;
if ( V_56 )
return V_56 ;
memcpy ( & V_116 , V_99 , V_112 ) ;
F_26 ( V_116 , V_2 -> V_17 + V_115 ) ;
}
V_56 = F_39 ( V_2 , V_117 ) ;
if ( V_56 )
return V_56 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_88 -> V_22 ;
struct V_27 * V_28 ;
int V_56 , V_15 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_26 = 0 ;
if ( V_22 -> V_32 & V_39 ) {
F_14 (data->sg, sg, data->sg_len, i) {
V_56 = F_43 ( V_2 , F_46 ( V_28 ) , V_28 -> V_38 ) ;
if ( V_56 )
return V_56 ;
V_2 -> V_26 += V_28 -> V_38 ;
}
} else {
F_14 (data->sg, sg, data->sg_len, i) {
V_56 = F_44 ( V_2 , F_46 ( V_28 ) , V_28 -> V_38 ) ;
if ( V_56 )
return V_56 ;
V_2 -> V_26 += V_28 -> V_38 ;
}
V_56 = F_39 ( V_2 , V_118 ) ;
if ( V_56 )
return V_56 ;
}
return 0 ;
}
static void F_47 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_48 ( V_120 , struct V_1 ,
V_121 ) ;
int V_122 = F_45 ( V_2 ) ;
F_26 ( V_60 | V_118 ,
V_2 -> V_17 + V_57 ) ;
F_36 ( V_2 , V_122 ) ;
if ( V_2 -> V_88 -> V_123 ) {
if ( F_28 ( V_2 , V_2 -> V_88 -> V_123 , 0 ) ) {
F_34 ( V_2 , V_2 -> V_88 ) ;
return;
}
} else {
F_34 ( V_2 , V_2 -> V_88 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_56 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_89 ;
if ( ! V_22 )
return;
V_89 = F_36 ( V_2 , V_56 ) ;
F_37 ( V_2 , V_56 ) ;
V_2 -> V_62 = NULL ;
if ( V_2 -> V_88 -> V_123 ) {
if ( F_28 ( V_2 , V_2 -> V_88 -> V_123 , 0 ) ) {
F_34 ( V_2 , V_2 -> V_88 ) ;
return;
}
} else {
F_34 ( V_2 , V_2 -> V_88 ) ;
}
}
static void F_49 ( struct V_1 * V_2 , unsigned int V_56 )
{
F_37 ( V_2 , V_56 ) ;
V_2 -> V_62 = NULL ;
if ( ! V_2 -> V_22 && V_2 -> V_88 ) {
F_34 ( V_2 , V_2 -> V_88 ) ;
return;
}
if ( ! F_9 ( V_2 ) && V_2 -> V_22 )
F_50 ( & V_2 -> V_121 ) ;
}
static T_3 F_51 ( int V_124 , void * V_125 )
{
struct V_1 * V_2 = V_125 ;
unsigned long V_32 ;
bool V_126 ;
T_1 V_56 ;
V_56 = F_25 ( V_2 -> V_17 + V_57 ) ;
F_26 ( V_56 & ~ ( V_127 | V_58 |
V_118 ) , V_2 -> V_17 + V_57 ) ;
F_11 ( F_3 ( V_2 -> V_4 ) , L_4 , V_59 , V_56 ) ;
F_32 ( & V_2 -> V_78 , V_32 ) ;
V_126 = ( V_56 & V_127 ) && V_2 -> V_79 ;
F_33 ( & V_2 -> V_78 , V_32 ) ;
if ( F_9 ( V_2 ) &&
( V_56 & ( V_60 | V_118 ) ) )
F_26 ( V_60 | V_118 ,
V_2 -> V_17 + V_57 ) ;
if ( V_126 ) {
F_26 ( V_127 , V_2 -> V_17 + V_57 ) ;
F_52 ( V_2 -> V_4 ) ;
}
if ( V_56 & V_128 )
F_49 ( V_2 , V_56 ) ;
if ( F_9 ( V_2 ) &&
( V_56 & ( V_58 | V_118 ) ) ) {
F_24 ( & V_2 -> V_53 ) ;
F_27 ( V_2 , V_56 ) ;
}
if ( V_2 -> V_65 &&
( V_56 & ( V_129 | V_130 ) ) )
F_53 ( V_2 -> V_4 , F_22 ( 200 ) ) ;
return V_131 ;
}
static void F_54 ( struct V_132 * V_4 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_55 ( V_4 ) ;
unsigned int V_63 = V_2 -> V_63 ;
int error ;
F_29 ( V_2 -> V_88 != NULL ) ;
V_2 -> V_88 = V_88 ;
V_2 -> V_63 &= ~ V_133 ;
if ( V_2 -> V_45 )
V_2 -> V_14 = 1 ;
if ( V_88 -> V_22 ) {
error = F_13 ( V_2 , V_88 -> V_22 ) ;
if ( error ) {
V_88 -> V_62 -> error = error ;
goto V_134;
}
V_63 |= V_135 ;
if ( V_88 -> V_22 -> V_32 & V_136 )
V_63 |= V_137 ;
}
error = F_28 ( V_2 , V_88 -> V_62 , V_63 ) ;
V_134:
if ( error )
F_34 ( V_2 , V_88 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_138 )
{
unsigned int V_139 ;
int V_140 = 0 ;
unsigned int V_141 = F_56 ( V_2 -> V_142 ) ;
while ( V_140 <= 0x800 ) {
for ( V_139 = 1 ; V_139 <= 0xF ; V_139 ++ ) {
int V_143 ;
V_143 = ( V_141 / ( V_139 + 1 ) ) ;
if ( V_140 )
V_143 /= ( V_140 * 2 ) ;
if ( V_143 <= V_138 )
break;
}
if ( V_139 < 0x10 )
break;
if ( V_140 == 0 )
V_140 = 1 ;
else
V_140 <<= 1 ;
}
F_12 ( ( V_140 << 4 ) | V_139 , V_2 -> V_17 + V_144 ) ;
F_11 ( F_3 ( V_2 -> V_4 ) , L_13 ,
V_140 , V_139 , V_141 , V_138 ) ;
}
static int F_57 ( struct V_132 * V_4 )
{
struct V_1 * V_2 = F_55 ( V_4 ) ;
struct V_145 * V_146 = & V_2 -> V_145 ;
V_146 -> V_147 = V_2 -> V_148 -> V_149 + V_115 ;
V_146 -> V_150 = V_2 -> V_148 -> V_149 + V_115 ;
V_146 -> V_151 = 4 ;
V_146 -> V_152 = 4 ;
V_146 -> V_153 = V_2 -> V_154 ;
V_146 -> V_155 = V_2 -> V_154 ;
V_146 -> V_156 = false ;
return F_58 ( V_2 -> V_45 , V_146 ) ;
}
static void F_59 ( struct V_132 * V_4 , struct V_157 * V_158 )
{
struct V_1 * V_2 = F_55 ( V_4 ) ;
int V_154 , V_159 ;
if ( V_158 -> V_160 == V_161 )
V_154 = 16 ;
else
V_154 = 4 ;
if ( F_9 ( V_2 ) && V_154 != V_2 -> V_154 ) {
V_2 -> V_154 = V_154 ;
V_159 = F_57 ( V_4 ) ;
if ( V_159 ) {
F_31 ( F_3 ( V_2 -> V_4 ) ,
L_14 ) ;
F_60 ( V_2 -> V_45 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_45 = NULL ;
}
}
if ( V_158 -> V_160 == V_161 )
V_2 -> V_63 |= V_162 ;
else
V_2 -> V_63 &= ~ V_162 ;
if ( V_2 -> V_9 != V_158 -> V_9 ) {
F_7 ( V_2 , V_158 -> V_9 , V_158 -> V_10 ) ;
V_2 -> V_9 = V_158 -> V_9 ;
if ( V_158 -> V_9 == V_163 )
V_2 -> V_63 |= V_133 ;
}
if ( V_158 -> clock ) {
F_41 ( V_2 , V_158 -> clock ) ;
F_12 ( V_19 , V_2 -> V_17 + V_18 ) ;
} else {
F_12 ( V_164 , V_2 -> V_17 + V_18 ) ;
}
V_2 -> clock = V_158 -> clock ;
}
static T_3 F_61 ( int V_124 , void * V_22 )
{
struct V_132 * V_4 = V_22 ;
F_11 ( F_3 ( V_4 ) , L_15 , V_59 ) ;
F_53 ( V_4 , F_22 ( 250 ) ) ;
return V_131 ;
}
static int F_62 ( struct V_132 * V_4 )
{
struct V_1 * V_2 = F_55 ( V_4 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> V_165 )
return ! ! V_2 -> V_6 -> V_165 ( F_3 ( V_4 ) ) ;
return - V_166 ;
}
static void F_63 ( struct V_132 * V_4 , int V_167 )
{
struct V_1 * V_2 = F_55 ( V_4 ) ;
unsigned long V_32 ;
T_1 V_64 ;
F_32 ( & V_2 -> V_78 , V_32 ) ;
V_2 -> V_79 = V_167 ;
V_64 = F_25 ( V_2 -> V_17 + V_81 ) ;
if ( V_167 )
V_64 |= V_80 ;
else
V_64 &= ~ V_80 ;
F_26 ( V_64 , V_2 -> V_17 + V_81 ) ;
F_33 ( & V_2 -> V_78 , V_32 ) ;
}
static void F_64 ( struct V_132 * V_2 , struct V_168 * V_169 )
{
if ( F_65 () && V_169 -> type == V_170 )
V_2 -> V_171 &= ~ V_172 ;
else
V_2 -> V_171 |= V_172 ;
}
static bool F_66 ( struct V_173 * V_174 , void * V_175 )
{
struct V_1 * V_2 = V_175 ;
if ( ! F_67 ( V_174 ) )
return false ;
V_174 -> V_176 = & V_2 -> V_177 ;
return true ;
}
static void F_68 ( unsigned long V_22 )
{
struct V_132 * V_4 = (struct V_132 * ) V_22 ;
struct V_1 * V_2 = F_55 ( V_4 ) ;
struct V_87 * V_88 = V_2 -> V_88 ;
unsigned int V_56 = F_25 ( V_2 -> V_17 + V_57 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_69 ( V_2 -> V_45 ) ;
F_31 ( F_3 ( V_2 -> V_4 ) ,
L_16 ,
V_59 , V_56 ) ;
} else {
F_31 ( F_3 ( V_2 -> V_4 ) ,
L_17 ,
V_59 , V_56 ) ;
F_10 ( V_2 ) ;
}
V_2 -> V_22 -> error = - V_95 ;
V_2 -> V_88 = NULL ;
V_2 -> V_62 = NULL ;
V_2 -> V_22 = NULL ;
F_35 ( V_2 -> V_4 , V_88 ) ;
}
static int F_70 ( struct V_178 * V_179 )
{
struct V_132 * V_4 ;
struct V_1 * V_2 = NULL ;
struct V_180 * V_181 , * V_182 ;
int V_159 = 0 , V_124 ;
T_4 V_108 ;
F_71 ( L_18 ) ;
V_181 = F_72 ( V_179 , V_183 , 0 ) ;
V_124 = F_73 ( V_179 , 0 ) ;
if ( ! V_181 || V_124 < 0 )
return - V_49 ;
V_182 = F_74 ( V_181 -> V_149 , F_75 ( V_181 ) , V_179 -> V_184 ) ;
if ( ! V_182 )
return - V_185 ;
V_4 = F_76 ( sizeof( struct V_1 ) , & V_179 -> V_47 ) ;
if ( ! V_4 ) {
V_159 = - V_186 ;
goto V_187;
}
V_4 -> V_188 = & V_189 ;
V_4 -> V_171 = V_172 | V_190 ;
V_4 -> V_191 = 64 ;
V_4 -> V_192 = 2048 ;
V_4 -> V_193 = 65535 ;
V_4 -> V_194 = V_4 -> V_192 * V_4 -> V_193 ;
V_4 -> V_195 = V_4 -> V_194 ;
V_2 = F_55 ( V_4 ) ;
V_2 -> V_17 = F_77 ( V_182 -> V_149 , F_75 ( V_182 ) ) ;
if ( ! V_2 -> V_17 ) {
V_159 = - V_186 ;
goto V_196;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_179 -> V_47 . V_197 ;
F_78 ( & V_2 -> V_78 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> V_198 )
V_2 -> V_65 =
V_199 | V_200 ;
else
V_2 -> V_65 = 0 ;
V_2 -> V_148 = V_182 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_201 = F_79 ( & V_179 -> V_47 , L_19 ) ;
if ( F_4 ( V_2 -> V_201 ) ) {
V_159 = F_80 ( V_2 -> V_201 ) ;
goto V_202;
}
V_2 -> V_142 = F_79 ( & V_179 -> V_47 , L_20 ) ;
if ( F_4 ( V_2 -> V_142 ) ) {
V_159 = F_80 ( V_2 -> V_142 ) ;
goto V_202;
}
F_81 ( V_2 -> V_142 ) ;
F_81 ( V_2 -> V_201 ) ;
F_10 ( V_2 ) ;
V_2 -> V_203 = F_38 ( V_2 -> V_17 + V_204 ) ;
if ( V_2 -> V_203 != 0x400 ) {
V_159 = - V_205 ;
F_31 ( F_3 ( V_2 -> V_4 ) , L_21 ,
V_2 -> V_203 ) ;
goto V_206;
}
V_4 -> V_207 = F_56 ( V_2 -> V_142 ) >> 16 ;
V_4 -> V_208 = F_56 ( V_2 -> V_142 ) >> 1 ;
F_12 ( 0x2db4 , V_2 -> V_17 + V_209 ) ;
F_26 ( V_2 -> V_65 , V_2 -> V_17 + V_81 ) ;
V_182 = F_72 ( V_179 , V_210 , 0 ) ;
if ( V_182 ) {
V_2 -> V_211 = V_182 -> V_149 ;
V_2 -> V_177 . V_212 = V_213 ;
V_2 -> V_177 . V_214 = V_215 ;
V_2 -> V_177 . V_216 = V_2 -> V_211 ;
F_82 ( V_108 ) ;
F_83 ( V_217 , V_108 ) ;
V_2 -> V_45 = F_84 ( V_108 , F_66 , V_2 ) ;
if ( V_2 -> V_45 )
V_4 -> V_195 = F_85 (
V_2 -> V_45 -> V_46 -> V_47 ) ;
}
if ( ! V_2 -> V_45 )
F_86 ( F_3 ( V_2 -> V_4 ) , L_22 ) ;
F_87 ( & V_2 -> V_121 , F_47 ) ;
V_159 = F_88 ( V_2 -> V_124 , F_51 , 0 , V_218 , V_2 ) ;
if ( V_159 )
goto V_219;
F_89 ( V_179 , V_4 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> V_220 ) {
V_159 = V_2 -> V_6 -> V_220 ( & V_179 -> V_47 , F_61 ,
V_2 -> V_4 ) ;
if ( V_159 )
goto V_221;
}
F_90 ( V_4 ) ;
F_91 ( & V_2 -> V_53 ) ;
V_2 -> V_53 . V_222 = & F_68 ;
V_2 -> V_53 . V_22 = ( unsigned long ) V_4 ;
return 0 ;
V_221:
F_92 ( V_2 -> V_124 , V_2 ) ;
V_219:
if ( V_2 -> V_45 )
F_60 ( V_2 -> V_45 ) ;
V_206:
F_93 ( V_2 -> V_142 ) ;
F_93 ( V_2 -> V_201 ) ;
V_202:
F_94 ( V_2 -> V_17 ) ;
V_196:
F_95 ( V_4 ) ;
V_187:
F_96 ( V_181 -> V_149 , F_75 ( V_181 ) ) ;
return V_159 ;
}
static int F_97 ( struct V_178 * V_179 )
{
struct V_132 * V_4 = F_98 ( V_179 ) ;
struct V_1 * V_2 = F_55 ( V_4 ) ;
F_89 ( V_179 , NULL ) ;
F_99 ( V_4 ) ;
if ( V_2 -> V_3 )
F_100 ( V_2 -> V_3 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> exit )
V_2 -> V_6 -> exit ( & V_179 -> V_47 , V_4 ) ;
F_92 ( V_2 -> V_124 , V_2 ) ;
F_94 ( V_2 -> V_17 ) ;
if ( V_2 -> V_45 )
F_60 ( V_2 -> V_45 ) ;
F_93 ( V_2 -> V_142 ) ;
F_93 ( V_2 -> V_201 ) ;
F_96 ( V_2 -> V_148 -> V_149 , F_75 ( V_2 -> V_148 ) ) ;
F_95 ( V_4 ) ;
return 0 ;
}
static int F_101 ( struct V_46 * V_47 )
{
struct V_132 * V_4 = F_102 ( V_47 ) ;
struct V_1 * V_2 = F_55 ( V_4 ) ;
int V_159 = 0 ;
if ( V_4 )
V_159 = F_103 ( V_4 ) ;
F_93 ( V_2 -> V_142 ) ;
F_93 ( V_2 -> V_201 ) ;
return V_159 ;
}
static int F_104 ( struct V_46 * V_47 )
{
struct V_132 * V_4 = F_102 ( V_47 ) ;
struct V_1 * V_2 = F_55 ( V_4 ) ;
int V_159 = 0 ;
F_81 ( V_2 -> V_142 ) ;
F_81 ( V_2 -> V_201 ) ;
if ( V_4 )
V_159 = F_105 ( V_4 ) ;
return V_159 ;
}
