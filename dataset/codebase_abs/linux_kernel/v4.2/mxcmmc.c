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
if ( V_28 -> V_39 & V_40 )
V_32 = 0xffff ;
V_2 -> V_28 = V_28 ;
V_28 -> V_41 = 0 ;
F_12 ( V_2 , V_32 , V_42 ) ;
F_12 ( V_2 , V_34 , V_43 ) ;
V_2 -> V_35 = V_35 ;
if ( ! F_18 ( V_2 ) )
return 0 ;
F_24 (data->sg, sg, data->sg_len, i) {
if ( V_30 -> V_44 & 3 || V_30 -> V_31 & 3 || V_30 -> V_31 < 512 ) {
V_2 -> V_19 = 0 ;
return 0 ;
}
}
if ( V_28 -> V_39 & V_45 ) {
V_2 -> V_46 = V_47 ;
V_37 = V_48 ;
} else {
V_2 -> V_46 = V_49 ;
V_37 = V_50 ;
F_23 ( V_28 ) ;
}
V_38 = F_27 ( V_2 -> V_51 -> V_52 -> V_53 , V_28 -> V_30 ,
V_28 -> V_54 , V_2 -> V_46 ) ;
if ( V_38 != V_28 -> V_54 )
return - V_55 ;
V_2 -> V_56 = F_28 ( V_2 -> V_51 ,
V_28 -> V_30 , V_28 -> V_54 , V_37 ,
V_57 | V_58 ) ;
if ( ! V_2 -> V_56 ) {
F_29 ( V_2 -> V_51 -> V_52 -> V_53 , V_28 -> V_30 , V_28 -> V_54 ,
V_2 -> V_46 ) ;
V_2 -> V_19 = 0 ;
return 0 ;
}
F_30 () ;
F_31 ( V_2 -> V_56 ) ;
F_32 ( V_2 -> V_51 ) ;
F_33 ( & V_2 -> V_59 , V_60 + F_34 ( V_61 ) ) ;
return 0 ;
}
static void F_35 ( void * V_28 )
{
struct V_1 * V_2 = V_28 ;
T_1 V_62 ;
F_36 ( & V_2 -> V_59 ) ;
V_62 = F_3 ( V_2 , V_63 ) ;
F_20 ( F_17 ( V_2 -> V_11 ) , L_2 , V_64 , V_62 ) ;
F_37 ( V_2 , V_62 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_65 * V_66 ,
unsigned int V_67 )
{
T_1 V_68 = V_2 -> V_69 ;
unsigned long V_39 ;
F_39 ( V_2 -> V_66 != NULL ) ;
V_2 -> V_66 = V_66 ;
switch ( F_40 ( V_66 ) ) {
case V_70 :
case V_71 :
V_67 |= V_72 ;
break;
case V_73 :
V_67 |= V_74 ;
break;
case V_75 :
V_67 |= V_76 ;
break;
case V_77 :
break;
default:
F_41 ( F_17 ( V_2 -> V_11 ) , L_3 ,
F_40 ( V_66 ) ) ;
V_66 -> error = - V_55 ;
return - V_55 ;
}
V_68 = V_78 ;
if ( F_18 ( V_2 ) ) {
if ( V_2 -> V_46 == V_47 ) {
V_2 -> V_56 -> V_79 = F_35 ;
V_2 -> V_56 -> V_80 = V_2 ;
} else {
V_68 |= V_81 ;
}
}
F_42 ( & V_2 -> V_82 , V_39 ) ;
if ( V_2 -> V_83 )
V_68 |= V_84 ;
F_7 ( V_2 , V_68 , V_85 ) ;
F_43 ( & V_2 -> V_82 , V_39 ) ;
F_12 ( V_2 , V_66 -> V_86 , V_87 ) ;
F_7 ( V_2 , V_66 -> V_88 , V_89 ) ;
F_12 ( V_2 , V_67 , V_90 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
T_1 V_68 = V_2 -> V_69 ;
unsigned long V_39 ;
F_42 ( & V_2 -> V_82 , V_39 ) ;
if ( V_2 -> V_83 )
V_68 |= V_84 ;
F_7 ( V_2 , V_68 , V_85 ) ;
F_43 ( & V_2 -> V_82 , V_39 ) ;
V_2 -> V_92 = NULL ;
V_2 -> V_66 = NULL ;
V_2 -> V_28 = NULL ;
F_45 ( V_2 -> V_11 , V_92 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
int V_93 ;
if ( F_18 ( V_2 ) ) {
F_29 ( V_2 -> V_51 -> V_52 -> V_53 , V_28 -> V_30 , V_28 -> V_54 ,
V_2 -> V_46 ) ;
F_23 ( V_28 ) ;
}
if ( V_62 & V_94 ) {
F_20 ( F_17 ( V_2 -> V_11 ) , L_4 ,
V_62 ) ;
if ( V_62 & V_95 ) {
F_41 ( F_17 ( V_2 -> V_11 ) , L_5 , V_64 ) ;
V_28 -> error = - V_96 ;
} else if ( V_62 & V_97 ) {
T_1 V_98 = ( V_62 >> 9 ) & 0x3 ;
if ( V_98 == 2 ) {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_6 , V_64 ) ;
V_28 -> error = - V_99 ;
} else {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_5 , V_64 ) ;
V_28 -> error = - V_96 ;
}
} else if ( V_62 & V_100 ) {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_7 , V_64 ) ;
V_28 -> error = - V_99 ;
} else {
F_41 ( F_17 ( V_2 -> V_11 ) , L_8 , V_64 ) ;
V_28 -> error = - V_101 ;
}
} else {
V_28 -> V_41 = V_2 -> V_35 ;
}
V_93 = V_28 -> error ;
V_2 -> V_28 = NULL ;
return V_93 ;
}
static void F_47 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_65 * V_66 = V_2 -> V_66 ;
int V_20 ;
T_1 V_102 , V_103 , V_104 ;
if ( ! V_66 )
return;
if ( V_62 & V_105 ) {
F_20 ( F_17 ( V_2 -> V_11 ) , L_9 ) ;
V_66 -> error = - V_99 ;
} else if ( V_62 & V_106 && V_66 -> V_39 & V_107 ) {
F_20 ( F_17 ( V_2 -> V_11 ) , L_10 ) ;
V_66 -> error = - V_96 ;
}
if ( V_66 -> V_39 & V_108 ) {
if ( V_66 -> V_39 & V_109 ) {
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
V_102 = F_10 ( V_2 , V_110 ) ;
V_103 = F_10 ( V_2 , V_110 ) ;
V_66 -> V_111 [ V_20 ] = V_102 << 16 | V_103 ;
}
} else {
V_102 = F_10 ( V_2 , V_110 ) ;
V_103 = F_10 ( V_2 , V_110 ) ;
V_104 = F_10 ( V_2 , V_110 ) ;
V_66 -> V_111 [ 0 ] = V_102 << 24 | V_103 << 8 | V_104 >> 8 ;
}
}
}
static int F_48 ( struct V_1 * V_2 , T_1 V_112 )
{
T_1 V_62 ;
unsigned long V_113 = V_60 + V_114 ;
do {
V_62 = F_3 ( V_2 , V_63 ) ;
if ( V_62 & V_94 )
return V_62 ;
if ( F_49 ( V_60 , V_113 ) ) {
F_19 ( V_2 ) ;
F_50 ( V_2 , V_2 -> clock ) ;
return V_100 ;
}
if ( V_62 & V_112 )
return 0 ;
F_51 () ;
} while ( 1 );
}
static int F_52 ( struct V_1 * V_2 , void * V_115 , int V_116 )
{
unsigned int V_62 ;
T_1 * V_25 = V_115 ;
while ( V_116 > 3 ) {
V_62 = F_48 ( V_2 ,
V_117 | V_118 ) ;
if ( V_62 )
return V_62 ;
* V_25 ++ = F_53 ( F_3 ( V_2 , V_119 ) ) ;
V_116 -= 4 ;
}
if ( V_116 ) {
T_3 * V_103 = ( T_3 * ) V_25 ;
T_1 V_120 ;
V_62 = F_48 ( V_2 ,
V_117 | V_118 ) ;
if ( V_62 )
return V_62 ;
V_120 = F_53 ( F_3 ( V_2 , V_119 ) ) ;
memcpy ( V_103 , & V_120 , V_116 ) ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , void * V_115 , int V_116 )
{
unsigned int V_62 ;
T_1 * V_25 = V_115 ;
while ( V_116 > 3 ) {
V_62 = F_48 ( V_2 , V_121 ) ;
if ( V_62 )
return V_62 ;
F_7 ( V_2 , F_53 ( * V_25 ++ ) , V_119 ) ;
V_116 -= 4 ;
}
if ( V_116 ) {
T_3 * V_103 = ( T_3 * ) V_25 ;
T_1 V_120 ;
V_62 = F_48 ( V_2 , V_121 ) ;
if ( V_62 )
return V_62 ;
memcpy ( & V_120 , V_103 , V_116 ) ;
F_7 ( V_2 , F_53 ( V_120 ) , V_119 ) ;
}
return F_48 ( V_2 , V_121 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_92 -> V_28 ;
struct V_29 * V_30 ;
int V_62 , V_20 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_35 = 0 ;
if ( V_28 -> V_39 & V_45 ) {
F_24 (data->sg, sg, data->sg_len, i) {
V_62 = F_52 ( V_2 , F_25 ( V_30 ) , V_30 -> V_31 ) ;
if ( V_62 )
return V_62 ;
V_2 -> V_35 += V_30 -> V_31 ;
}
} else {
F_24 (data->sg, sg, data->sg_len, i) {
V_62 = F_54 ( V_2 , F_25 ( V_30 ) , V_30 -> V_31 ) ;
if ( V_62 )
return V_62 ;
V_2 -> V_35 += V_30 -> V_31 ;
}
V_62 = F_48 ( V_2 , V_122 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static void F_56 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_57 ( V_124 , struct V_1 ,
V_125 ) ;
int V_126 = F_55 ( V_2 ) ;
F_7 ( V_2 , V_118 | V_122 ,
V_63 ) ;
F_46 ( V_2 , V_126 ) ;
if ( V_2 -> V_92 -> V_127 ) {
if ( F_38 ( V_2 , V_2 -> V_92 -> V_127 , 0 ) ) {
F_44 ( V_2 , V_2 -> V_92 ) ;
return;
}
} else {
F_44 ( V_2 , V_2 -> V_92 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_91 * V_92 ;
int V_93 ;
unsigned long V_39 ;
F_42 ( & V_2 -> V_82 , V_39 ) ;
if ( ! V_2 -> V_28 ) {
F_43 ( & V_2 -> V_82 , V_39 ) ;
return;
}
if ( ! V_2 -> V_92 ) {
F_43 ( & V_2 -> V_82 , V_39 ) ;
return;
}
V_92 = V_2 -> V_92 ;
if ( ! V_92 -> V_127 )
V_2 -> V_92 = NULL ;
V_93 = F_46 ( V_2 , V_62 ) ;
F_43 ( & V_2 -> V_82 , V_39 ) ;
F_47 ( V_2 , V_62 ) ;
V_2 -> V_66 = NULL ;
if ( V_92 -> V_127 ) {
if ( F_38 ( V_2 , V_92 -> V_127 , 0 ) ) {
F_44 ( V_2 , V_92 ) ;
return;
}
} else {
F_44 ( V_2 , V_92 ) ;
}
}
static void F_58 ( struct V_1 * V_2 , unsigned int V_62 )
{
F_47 ( V_2 , V_62 ) ;
V_2 -> V_66 = NULL ;
if ( ! V_2 -> V_28 && V_2 -> V_92 ) {
F_44 ( V_2 , V_2 -> V_92 ) ;
return;
}
if ( ! F_18 ( V_2 ) && V_2 -> V_28 )
F_59 ( & V_2 -> V_125 ) ;
}
static T_4 F_60 ( int V_128 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
unsigned long V_39 ;
bool V_130 ;
T_1 V_62 ;
V_62 = F_3 ( V_2 , V_63 ) ;
F_7 ( V_2 ,
V_62 & ~ ( V_131 | V_132 |
V_122 ) ,
V_63 ) ;
F_20 ( F_17 ( V_2 -> V_11 ) , L_2 , V_64 , V_62 ) ;
F_42 ( & V_2 -> V_82 , V_39 ) ;
V_130 = ( V_62 & V_131 ) && V_2 -> V_83 ;
F_43 ( & V_2 -> V_82 , V_39 ) ;
if ( F_18 ( V_2 ) && ( V_62 & ( V_122 ) ) )
F_7 ( V_2 , V_122 , V_63 ) ;
if ( V_130 ) {
F_7 ( V_2 , V_131 , V_63 ) ;
F_61 ( V_2 -> V_11 ) ;
}
if ( V_62 & V_133 )
F_58 ( V_2 , V_62 ) ;
if ( F_18 ( V_2 ) && ( V_62 & V_122 ) ) {
F_36 ( & V_2 -> V_59 ) ;
F_37 ( V_2 , V_62 ) ;
}
if ( V_2 -> V_69 &&
( V_62 & ( V_134 | V_135 ) ) )
F_62 ( V_2 -> V_11 , F_34 ( 200 ) ) ;
return V_136 ;
}
static void F_63 ( struct V_137 * V_11 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
unsigned int V_67 = V_2 -> V_67 ;
int error ;
F_39 ( V_2 -> V_92 != NULL ) ;
V_2 -> V_92 = V_92 ;
V_2 -> V_67 &= ~ V_138 ;
if ( V_2 -> V_51 )
V_2 -> V_19 = 1 ;
if ( V_92 -> V_28 ) {
error = F_26 ( V_2 , V_92 -> V_28 ) ;
if ( error ) {
V_92 -> V_66 -> error = error ;
goto V_139;
}
V_67 |= V_140 ;
if ( V_92 -> V_28 -> V_39 & V_141 )
V_67 |= V_142 ;
}
error = F_38 ( V_2 , V_92 -> V_66 , V_67 ) ;
V_139:
if ( error )
F_44 ( V_2 , V_92 ) ;
}
static void F_50 ( struct V_1 * V_2 , unsigned int V_143 )
{
unsigned int V_144 ;
int V_145 = 0 ;
unsigned int V_146 = F_65 ( V_2 -> V_147 ) ;
while ( V_145 <= 0x800 ) {
for ( V_144 = 1 ; V_144 <= 0xF ; V_144 ++ ) {
int V_148 ;
V_148 = ( V_146 / ( V_144 + 1 ) ) ;
if ( V_145 )
V_148 /= ( V_145 * 2 ) ;
if ( V_148 <= V_143 )
break;
}
if ( V_144 < 0x10 )
break;
if ( V_145 == 0 )
V_145 = 1 ;
else
V_145 <<= 1 ;
}
F_12 ( V_2 , ( V_145 << 4 ) | V_144 , V_149 ) ;
F_20 ( F_17 ( V_2 -> V_11 ) , L_11 ,
V_145 , V_144 , V_146 , V_143 ) ;
}
static int F_66 ( struct V_137 * V_11 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
struct V_150 * V_151 = & V_2 -> V_150 ;
V_151 -> V_152 = V_2 -> V_153 + V_119 ;
V_151 -> V_154 = V_2 -> V_153 + V_119 ;
V_151 -> V_155 = 4 ;
V_151 -> V_156 = 4 ;
V_151 -> V_157 = V_2 -> V_158 ;
V_151 -> V_159 = V_2 -> V_158 ;
V_151 -> V_160 = false ;
return F_67 ( V_2 -> V_51 , V_151 ) ;
}
static void F_68 ( struct V_137 * V_11 , struct V_161 * V_162 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
int V_158 , V_163 ;
if ( V_162 -> V_164 == V_165 )
V_158 = 16 ;
else
V_158 = 4 ;
if ( F_18 ( V_2 ) && V_158 != V_2 -> V_158 ) {
V_2 -> V_158 = V_158 ;
V_163 = F_66 ( V_11 ) ;
if ( V_163 ) {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_12 ) ;
F_69 ( V_2 -> V_51 ) ;
V_2 -> V_19 = 0 ;
V_2 -> V_51 = NULL ;
}
}
if ( V_162 -> V_164 == V_165 )
V_2 -> V_67 |= V_166 ;
else
V_2 -> V_67 &= ~ V_166 ;
if ( V_2 -> V_14 != V_162 -> V_14 ) {
V_2 -> V_14 = V_162 -> V_14 ;
F_14 ( V_2 , V_162 -> V_10 ) ;
if ( V_162 -> V_14 == V_167 )
V_2 -> V_67 |= V_138 ;
}
if ( V_162 -> clock ) {
F_50 ( V_2 , V_162 -> clock ) ;
F_12 ( V_2 , V_23 , V_22 ) ;
} else {
F_12 ( V_2 , V_168 , V_22 ) ;
}
V_2 -> clock = V_162 -> clock ;
}
static T_4 F_70 ( int V_128 , void * V_28 )
{
struct V_137 * V_11 = V_28 ;
F_20 ( F_17 ( V_11 ) , L_13 , V_64 ) ;
F_62 ( V_11 , F_34 ( 250 ) ) ;
return V_136 ;
}
static int F_71 ( struct V_137 * V_11 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
if ( V_2 -> V_17 && V_2 -> V_17 -> V_169 )
return ! ! V_2 -> V_17 -> V_169 ( F_17 ( V_11 ) ) ;
return F_72 ( V_11 ) ;
}
static void F_73 ( struct V_137 * V_11 , int V_170 )
{
struct V_1 * V_2 = F_64 ( V_11 ) ;
unsigned long V_39 ;
T_1 V_68 ;
F_42 ( & V_2 -> V_82 , V_39 ) ;
V_2 -> V_83 = V_170 ;
V_68 = F_3 ( V_2 , V_85 ) ;
if ( V_170 )
V_68 |= V_84 ;
else
V_68 &= ~ V_84 ;
F_7 ( V_2 , V_68 , V_85 ) ;
F_43 ( & V_2 -> V_82 , V_39 ) ;
}
static void F_74 ( struct V_137 * V_2 , struct V_171 * V_172 )
{
struct V_1 * V_173 = F_64 ( V_2 ) ;
if ( F_1 ( V_173 ) && V_172 -> type == V_174 )
V_2 -> V_175 &= ~ V_176 ;
else
V_2 -> V_175 |= V_176 ;
}
static bool F_75 ( struct V_177 * V_178 , void * V_179 )
{
struct V_1 * V_2 = V_179 ;
if ( ! F_76 ( V_178 ) )
return false ;
V_178 -> V_180 = & V_2 -> V_181 ;
return true ;
}
static void F_77 ( unsigned long V_28 )
{
struct V_137 * V_11 = (struct V_137 * ) V_28 ;
struct V_1 * V_2 = F_64 ( V_11 ) ;
struct V_91 * V_92 = V_2 -> V_92 ;
unsigned int V_62 = F_3 ( V_2 , V_63 ) ;
if ( V_2 -> V_46 == V_47 ) {
F_78 ( V_2 -> V_51 ) ;
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_14 ,
V_64 , V_62 ) ;
} else {
F_41 ( F_17 ( V_2 -> V_11 ) ,
L_15 ,
V_64 , V_62 ) ;
F_19 ( V_2 ) ;
}
if ( V_2 -> V_28 )
V_2 -> V_28 -> error = - V_99 ;
V_2 -> V_92 = NULL ;
V_2 -> V_66 = NULL ;
V_2 -> V_28 = NULL ;
F_45 ( V_2 -> V_11 , V_92 ) ;
}
static int F_79 ( struct V_182 * V_183 )
{
struct V_137 * V_11 ;
struct V_1 * V_2 ;
struct V_184 * V_185 ;
int V_163 = 0 , V_128 ;
bool V_186 = false ;
T_5 V_112 ;
const struct V_187 * V_188 ;
struct V_189 * V_17 = V_183 -> V_53 . V_190 ;
F_80 ( L_16 ) ;
V_188 = F_81 ( V_191 , & V_183 -> V_53 ) ;
V_185 = F_82 ( V_183 , V_192 , 0 ) ;
V_128 = F_83 ( V_183 , 0 ) ;
if ( V_128 < 0 )
return - V_55 ;
V_11 = F_84 ( sizeof( * V_2 ) , & V_183 -> V_53 ) ;
if ( ! V_11 )
return - V_193 ;
V_2 = F_64 ( V_11 ) ;
V_2 -> V_8 = F_85 ( & V_183 -> V_53 , V_185 ) ;
if ( F_15 ( V_2 -> V_8 ) ) {
V_163 = F_86 ( V_2 -> V_8 ) ;
goto V_194;
}
V_2 -> V_153 = V_185 -> V_195 ;
V_163 = F_87 ( V_11 ) ;
if ( V_163 )
goto V_194;
V_11 -> V_196 = & V_197 ;
if ( V_17 )
V_11 -> V_175 = V_176 | V_198 ;
else
V_11 -> V_175 |= V_198 ;
V_11 -> V_199 = 2048 ;
V_11 -> V_200 = 65535 ;
V_11 -> V_201 = V_11 -> V_199 * V_11 -> V_200 ;
V_11 -> V_202 = V_11 -> V_201 ;
if ( V_188 ) {
const struct V_203 * V_204 = V_188 -> V_28 ;
V_2 -> V_3 = V_204 -> V_205 ;
} else {
V_2 -> V_3 = V_183 -> V_204 -> V_205 ;
}
if ( ! F_2 ( V_2 ) )
V_11 -> V_206 = 64 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_17 = V_17 ;
F_88 ( & V_2 -> V_82 ) ;
if ( V_17 )
V_186 = V_17 -> V_186 ;
else if ( ! ( V_11 -> V_175 & V_207 )
&& ! F_89 ( V_183 -> V_53 . V_208 , L_17 ) )
V_186 = true ;
V_163 = F_90 ( V_11 ) ;
if ( V_163 == - V_209 )
goto V_194;
if ( ! V_11 -> V_210 ) {
if ( V_17 && V_17 -> V_210 )
V_11 -> V_210 = V_17 -> V_210 ;
else
V_11 -> V_210 = V_211 | V_212 ;
}
if ( V_186 )
V_2 -> V_69 =
V_213 | V_214 ;
else
V_2 -> V_69 = 0 ;
V_2 -> V_215 = F_91 ( & V_183 -> V_53 , L_18 ) ;
if ( F_15 ( V_2 -> V_215 ) ) {
V_163 = F_86 ( V_2 -> V_215 ) ;
goto V_194;
}
V_2 -> V_147 = F_91 ( & V_183 -> V_53 , L_19 ) ;
if ( F_15 ( V_2 -> V_147 ) ) {
V_163 = F_86 ( V_2 -> V_147 ) ;
goto V_194;
}
F_92 ( V_2 -> V_147 ) ;
F_92 ( V_2 -> V_215 ) ;
F_19 ( V_2 ) ;
V_2 -> V_216 = F_10 ( V_2 , V_217 ) ;
if ( V_2 -> V_216 != 0x400 ) {
V_163 = - V_218 ;
F_41 ( F_17 ( V_2 -> V_11 ) , L_20 ,
V_2 -> V_216 ) ;
goto V_219;
}
V_11 -> V_220 = F_65 ( V_2 -> V_147 ) >> 16 ;
V_11 -> V_221 = F_65 ( V_2 -> V_147 ) >> 1 ;
F_12 ( V_2 , 0x2db4 , V_222 ) ;
F_7 ( V_2 , V_2 -> V_69 , V_85 ) ;
if ( ! V_2 -> V_17 ) {
V_2 -> V_51 = F_93 ( & V_183 -> V_53 , L_21 ) ;
} else {
V_185 = F_82 ( V_183 , V_223 , 0 ) ;
if ( V_185 ) {
V_2 -> V_224 = V_185 -> V_195 ;
V_2 -> V_181 . V_225 = V_226 ;
V_2 -> V_181 . V_227 = V_228 ;
V_2 -> V_181 . V_229 = V_2 -> V_224 ;
F_94 ( V_112 ) ;
F_95 ( V_230 , V_112 ) ;
V_2 -> V_51 = F_96 ( V_112 , F_75 , V_2 ) ;
}
}
if ( V_2 -> V_51 )
V_11 -> V_202 = F_97 (
V_2 -> V_51 -> V_52 -> V_53 ) ;
else
F_98 ( F_17 ( V_2 -> V_11 ) , L_22 ) ;
F_99 ( & V_2 -> V_125 , F_56 ) ;
V_163 = F_100 ( & V_183 -> V_53 , V_128 , F_60 , 0 ,
F_101 ( & V_183 -> V_53 ) , V_2 ) ;
if ( V_163 )
goto V_231;
F_102 ( V_183 , V_11 ) ;
if ( V_2 -> V_17 && V_2 -> V_17 -> V_232 ) {
V_163 = V_2 -> V_17 -> V_232 ( & V_183 -> V_53 , F_70 ,
V_2 -> V_11 ) ;
if ( V_163 )
goto V_231;
}
F_103 ( & V_2 -> V_59 ) ;
V_2 -> V_59 . V_233 = & F_77 ;
V_2 -> V_59 . V_28 = ( unsigned long ) V_11 ;
F_104 ( V_11 ) ;
return 0 ;
V_231:
if ( V_2 -> V_51 )
F_69 ( V_2 -> V_51 ) ;
V_219:
F_105 ( V_2 -> V_147 ) ;
F_105 ( V_2 -> V_215 ) ;
V_194:
F_106 ( V_11 ) ;
return V_163 ;
}
static int F_107 ( struct V_182 * V_183 )
{
struct V_137 * V_11 = F_108 ( V_183 ) ;
struct V_1 * V_2 = F_64 ( V_11 ) ;
F_109 ( V_11 ) ;
if ( V_2 -> V_17 && V_2 -> V_17 -> exit )
V_2 -> V_17 -> exit ( & V_183 -> V_53 , V_11 ) ;
if ( V_2 -> V_51 )
F_69 ( V_2 -> V_51 ) ;
F_105 ( V_2 -> V_147 ) ;
F_105 ( V_2 -> V_215 ) ;
F_106 ( V_11 ) ;
return 0 ;
}
static int T_6 F_110 ( struct V_52 * V_53 )
{
struct V_137 * V_11 = F_111 ( V_53 ) ;
struct V_1 * V_2 = F_64 ( V_11 ) ;
F_105 ( V_2 -> V_147 ) ;
F_105 ( V_2 -> V_215 ) ;
return 0 ;
}
static int T_6 F_112 ( struct V_52 * V_53 )
{
struct V_137 * V_11 = F_111 ( V_53 ) ;
struct V_1 * V_2 = F_64 ( V_11 ) ;
F_92 ( V_2 -> V_147 ) ;
F_92 ( V_2 -> V_215 ) ;
return 0 ;
}
