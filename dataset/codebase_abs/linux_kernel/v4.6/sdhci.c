static inline int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
static void F_4 ( struct V_1 * V_2 )
{
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_3 L_1 ,
F_7 ( V_2 -> V_4 ) ) ;
F_6 ( V_3 L_2 ,
F_8 ( V_2 , V_5 ) ,
F_9 ( V_2 , V_6 ) ) ;
F_6 ( V_3 L_3 ,
F_9 ( V_2 , V_7 ) ,
F_9 ( V_2 , V_8 ) ) ;
F_6 ( V_3 L_4 ,
F_8 ( V_2 , V_9 ) ,
F_9 ( V_2 , V_10 ) ) ;
F_6 ( V_3 L_5 ,
F_8 ( V_2 , V_11 ) ,
F_10 ( V_2 , V_12 ) ) ;
F_6 ( V_3 L_6 ,
F_10 ( V_2 , V_13 ) ,
F_10 ( V_2 , V_14 ) ) ;
F_6 ( V_3 L_7 ,
F_10 ( V_2 , V_15 ) ,
F_9 ( V_2 , V_16 ) ) ;
F_6 ( V_3 L_8 ,
F_10 ( V_2 , V_17 ) ,
F_8 ( V_2 , V_18 ) ) ;
F_6 ( V_3 L_9 ,
F_8 ( V_2 , V_19 ) ,
F_8 ( V_2 , V_20 ) ) ;
F_6 ( V_3 L_10 ,
F_9 ( V_2 , V_21 ) ,
F_9 ( V_2 , V_22 ) ) ;
F_6 ( V_3 L_11 ,
F_8 ( V_2 , V_23 ) ,
F_8 ( V_2 , V_24 ) ) ;
F_6 ( V_3 L_12 ,
F_9 ( V_2 , V_25 ) ,
F_8 ( V_2 , V_26 ) ) ;
F_6 ( V_3 L_13 ,
F_9 ( V_2 , V_27 ) ) ;
if ( V_2 -> V_28 & V_29 ) {
if ( V_2 -> V_28 & V_30 )
F_6 ( V_3 L_14 ,
F_11 ( V_2 -> V_31 + V_32 ) ,
F_11 ( V_2 -> V_31 + V_33 ) ,
F_11 ( V_2 -> V_31 + V_34 ) ) ;
else
F_6 ( V_3 L_15 ,
F_11 ( V_2 -> V_31 + V_32 ) ,
F_11 ( V_2 -> V_31 + V_34 ) ) ;
}
F_6 ( V_3 L_16 ) ;
}
static void F_12 ( struct V_1 * V_2 , bool V_35 )
{
T_1 V_36 ;
if ( ( V_2 -> V_37 & V_38 ) ||
( V_2 -> V_4 -> V_39 & V_40 ) )
return;
if ( V_35 ) {
V_36 = F_8 ( V_2 , V_11 ) &
V_41 ;
V_2 -> V_42 |= V_36 ? V_43 :
V_44 ;
} else {
V_2 -> V_42 &= ~ ( V_43 | V_44 ) ;
}
F_13 ( V_2 , V_2 -> V_42 , V_19 ) ;
F_13 ( V_2 , V_2 -> V_42 , V_20 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_12 ( V_2 , true ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_12 ( V_2 , false ) ;
}
void F_16 ( struct V_1 * V_2 , T_2 V_45 )
{
unsigned long V_46 ;
F_17 ( V_2 , V_45 , V_47 ) ;
if ( V_45 & V_48 ) {
V_2 -> clock = 0 ;
if ( V_2 -> V_49 & V_50 )
F_4 ( V_2 ) ;
}
V_46 = 100 ;
while ( F_10 ( V_2 , V_47 ) & V_45 ) {
if ( V_46 == 0 ) {
F_18 ( L_17 ,
F_7 ( V_2 -> V_4 ) , ( int ) V_45 ) ;
F_5 ( V_2 ) ;
return;
}
V_46 -- ;
F_19 ( 1 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , T_2 V_45 )
{
if ( V_2 -> V_37 & V_51 ) {
if ( ! F_21 ( V_2 ) )
return;
}
V_2 -> V_52 -> V_53 ( V_2 , V_45 ) ;
if ( V_45 & V_48 ) {
if ( V_2 -> V_28 & ( V_54 | V_29 ) ) {
if ( V_2 -> V_52 -> V_55 )
V_2 -> V_52 -> V_55 ( V_2 ) ;
}
V_2 -> V_56 = false ;
}
}
static void F_22 ( struct V_1 * V_2 , int V_57 )
{
if ( V_57 )
F_20 ( V_2 , V_58 | V_59 ) ;
else
F_20 ( V_2 , V_48 ) ;
V_2 -> V_42 = V_60 | V_61 |
V_62 | V_63 |
V_64 | V_65 | V_66 |
V_67 | V_68 |
V_69 ;
F_13 ( V_2 , V_2 -> V_42 , V_19 ) ;
F_13 ( V_2 , V_2 -> V_42 , V_20 ) ;
if ( V_57 ) {
V_2 -> clock = 0 ;
F_23 ( V_2 -> V_4 , & V_2 -> V_4 -> V_70 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
F_22 ( V_2 , 0 ) ;
F_14 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_2 V_71 ;
V_71 = F_10 ( V_2 , V_12 ) ;
V_71 |= V_72 ;
F_17 ( V_2 , V_71 , V_12 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_2 V_71 ;
V_71 = F_10 ( V_2 , V_12 ) ;
V_71 &= ~ V_72 ;
F_17 ( V_2 , V_71 , V_12 ) ;
}
static void F_27 ( struct V_73 * V_74 ,
enum V_75 V_76 )
{
struct V_1 * V_2 = F_28 ( V_74 , struct V_1 , V_74 ) ;
unsigned long V_28 ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( V_2 -> V_78 )
goto V_79;
if ( V_76 == V_80 )
F_26 ( V_2 ) ;
else
F_25 ( V_2 ) ;
V_79:
F_30 ( & V_2 -> V_77 , V_28 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
T_3 V_81 , V_82 , V_83 ;
T_1 V_84 ( V_85 ) ;
T_2 * V_86 ;
F_32 ( L_18 ) ;
V_81 = V_2 -> V_87 -> V_88 ;
V_83 = 0 ;
F_33 ( V_28 ) ;
while ( V_81 ) {
F_34 ( ! F_35 ( & V_2 -> V_89 ) ) ;
V_82 = F_36 ( V_2 -> V_89 . V_90 , V_81 ) ;
V_81 -= V_82 ;
V_2 -> V_89 . V_91 = V_82 ;
V_86 = V_2 -> V_89 . V_92 ;
while ( V_82 ) {
if ( V_83 == 0 ) {
V_85 = F_8 ( V_2 , V_93 ) ;
V_83 = 4 ;
}
* V_86 = V_85 & 0xFF ;
V_86 ++ ;
V_85 >>= 8 ;
V_83 -- ;
V_82 -- ;
}
}
F_37 ( & V_2 -> V_89 ) ;
F_38 ( V_28 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
T_3 V_81 , V_82 , V_83 ;
T_1 V_85 ;
T_2 * V_86 ;
F_32 ( L_19 ) ;
V_81 = V_2 -> V_87 -> V_88 ;
V_83 = 0 ;
V_85 = 0 ;
F_33 ( V_28 ) ;
while ( V_81 ) {
F_34 ( ! F_35 ( & V_2 -> V_89 ) ) ;
V_82 = F_36 ( V_2 -> V_89 . V_90 , V_81 ) ;
V_81 -= V_82 ;
V_2 -> V_89 . V_91 = V_82 ;
V_86 = V_2 -> V_89 . V_92 ;
while ( V_82 ) {
V_85 |= ( T_1 ) * V_86 << ( V_83 * 8 ) ;
V_86 ++ ;
V_83 ++ ;
V_82 -- ;
if ( ( V_83 == 4 ) || ( ( V_82 == 0 ) && ( V_81 == 0 ) ) ) {
F_13 ( V_2 , V_85 , V_93 ) ;
V_83 = 0 ;
V_85 = 0 ;
}
}
}
F_37 ( & V_2 -> V_89 ) ;
F_38 ( V_28 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_45 ;
F_34 ( ! V_2 -> V_87 ) ;
if ( V_2 -> V_94 == 0 )
return;
if ( V_2 -> V_87 -> V_28 & V_95 )
V_45 = V_96 ;
else
V_45 = V_97 ;
if ( ( V_2 -> V_37 & V_98 ) &&
( V_2 -> V_87 -> V_94 == 1 ) )
V_45 = ~ 0 ;
while ( F_8 ( V_2 , V_11 ) & V_45 ) {
if ( V_2 -> V_37 & V_99 )
F_41 ( 100 ) ;
if ( V_2 -> V_87 -> V_28 & V_95 )
F_31 ( V_2 ) ;
else
F_39 ( V_2 ) ;
V_2 -> V_94 -- ;
if ( V_2 -> V_94 == 0 )
break;
}
F_32 ( L_20 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_100 * V_87 , int V_101 )
{
int V_102 ;
if ( V_87 -> V_103 == V_104 )
return V_87 -> V_102 ;
V_102 = F_43 ( F_44 ( V_2 -> V_4 ) , V_87 -> V_105 , V_87 -> V_106 ,
V_87 -> V_28 & V_107 ?
V_108 : V_109 ) ;
if ( V_102 == 0 )
return - V_110 ;
V_87 -> V_102 = V_102 ;
V_87 -> V_103 = V_101 ;
return V_102 ;
}
static char * F_45 ( struct V_111 * V_105 , unsigned long * V_28 )
{
F_33 ( * V_28 ) ;
return F_46 ( F_47 ( V_105 ) ) + V_105 -> V_112 ;
}
static void F_48 ( void * V_113 , unsigned long * V_28 )
{
F_49 ( V_113 ) ;
F_38 ( * V_28 ) ;
}
static void F_50 ( struct V_1 * V_2 , void * V_114 ,
T_4 V_92 , int V_82 , unsigned V_115 )
{
struct V_116 * V_117 = V_114 ;
V_117 -> V_115 = F_51 ( V_115 ) ;
V_117 -> V_82 = F_51 ( V_82 ) ;
V_117 -> V_118 = F_52 ( ( T_1 ) V_92 ) ;
if ( V_2 -> V_28 & V_30 )
V_117 -> V_119 = F_52 ( ( V_120 ) V_92 >> 32 ) ;
}
static void F_53 ( void * V_114 )
{
struct V_116 * V_117 = V_114 ;
V_117 -> V_115 |= F_51 ( V_121 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_100 * V_87 , int V_102 )
{
struct V_111 * V_105 ;
unsigned long V_28 ;
T_4 V_92 , V_122 ;
void * V_114 , * V_123 ;
char * V_113 ;
int V_82 , V_112 , V_124 ;
V_2 -> V_102 = V_102 ;
V_114 = V_2 -> V_125 ;
V_123 = V_2 -> V_126 ;
V_122 = V_2 -> V_122 ;
F_55 (data->sg, sg, host->sg_count, i) {
V_92 = F_56 ( V_105 ) ;
V_82 = F_57 ( V_105 ) ;
V_112 = ( V_127 - ( V_92 & V_128 ) ) &
V_128 ;
if ( V_112 ) {
if ( V_87 -> V_28 & V_107 ) {
V_113 = F_45 ( V_105 , & V_28 ) ;
memcpy ( V_123 , V_113 , V_112 ) ;
F_48 ( V_113 , & V_28 ) ;
}
F_50 ( V_2 , V_114 , V_122 , V_112 ,
V_129 ) ;
F_34 ( V_112 > 65536 ) ;
V_123 += V_127 ;
V_122 += V_127 ;
V_114 += V_2 -> V_130 ;
V_92 += V_112 ;
V_82 -= V_112 ;
}
F_34 ( V_82 > 65536 ) ;
if ( V_82 ) {
F_50 ( V_2 , V_114 , V_92 , V_82 ,
V_129 ) ;
V_114 += V_2 -> V_130 ;
}
F_58 ( ( V_114 - V_2 -> V_125 ) >= V_2 -> V_131 ) ;
}
if ( V_2 -> V_37 & V_132 ) {
if ( V_114 != V_2 -> V_125 ) {
V_114 -= V_2 -> V_130 ;
F_53 ( V_114 ) ;
}
} else {
F_50 ( V_2 , V_114 , 0 , 0 , V_133 ) ;
}
}
static void F_59 ( struct V_1 * V_2 ,
struct V_100 * V_87 )
{
struct V_111 * V_105 ;
int V_124 , V_134 ;
void * V_123 ;
char * V_113 ;
unsigned long V_28 ;
if ( V_87 -> V_28 & V_95 ) {
bool V_135 = false ;
F_55 (data->sg, sg, host->sg_count, i)
if ( F_56 ( V_105 ) & V_128 ) {
V_135 = true ;
break;
}
if ( V_135 ) {
F_60 ( F_44 ( V_2 -> V_4 ) , V_87 -> V_105 ,
V_87 -> V_106 , V_109 ) ;
V_123 = V_2 -> V_126 ;
F_55 (data->sg, sg, host->sg_count, i) {
if ( F_56 ( V_105 ) & V_128 ) {
V_134 = V_127 -
( F_56 ( V_105 ) & V_128 ) ;
V_113 = F_45 ( V_105 , & V_28 ) ;
memcpy ( V_113 , V_123 , V_134 ) ;
F_48 ( V_113 , & V_28 ) ;
V_123 += V_127 ;
}
}
}
}
}
static T_2 F_61 ( struct V_1 * V_2 , struct V_136 * V_115 )
{
T_2 V_137 ;
struct V_100 * V_87 = V_115 -> V_87 ;
unsigned V_138 , V_139 ;
if ( V_2 -> V_37 & V_140 )
return 0xE ;
if ( ! V_87 && ! V_115 -> V_141 )
return 0xE ;
if ( ! V_87 )
V_138 = V_115 -> V_141 * 1000 ;
else {
V_138 = F_62 ( V_87 -> V_142 , 1000 ) ;
if ( V_2 -> clock && V_87 -> V_143 ) {
unsigned long long V_144 ;
V_144 = 1000000 * V_87 -> V_143 ;
if ( F_63 ( V_144 , V_2 -> clock ) )
V_138 ++ ;
V_138 += V_144 ;
}
}
V_137 = 0 ;
V_139 = ( 1 << 13 ) * 1000 / V_2 -> V_145 ;
while ( V_139 < V_138 ) {
V_137 ++ ;
V_139 <<= 1 ;
if ( V_137 >= 0xF )
break;
}
if ( V_137 >= 0xF ) {
F_32 ( L_21 ,
F_7 ( V_2 -> V_4 ) , V_137 , V_115 -> V_146 ) ;
V_137 = 0xE ;
}
return V_137 ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_1 V_147 = V_148 | V_149 ;
T_1 V_150 = V_151 | V_152 ;
if ( V_2 -> V_28 & V_153 )
V_2 -> V_42 = ( V_2 -> V_42 & ~ V_147 ) | V_150 ;
else
V_2 -> V_42 = ( V_2 -> V_42 & ~ V_150 ) | V_147 ;
F_13 ( V_2 , V_2 -> V_42 , V_19 ) ;
F_13 ( V_2 , V_2 -> V_42 , V_20 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_136 * V_115 )
{
T_2 V_137 ;
if ( V_2 -> V_52 -> V_154 ) {
V_2 -> V_52 -> V_154 ( V_2 , V_115 ) ;
} else {
V_137 = F_61 ( V_2 , V_115 ) ;
F_17 ( V_2 , V_137 , V_17 ) ;
}
}
static void F_66 ( struct V_1 * V_2 , struct V_136 * V_115 )
{
T_2 V_71 ;
struct V_100 * V_87 = V_115 -> V_87 ;
F_58 ( V_2 -> V_87 ) ;
if ( V_87 || ( V_115 -> V_28 & V_155 ) )
F_65 ( V_2 , V_115 ) ;
if ( ! V_87 )
return;
F_34 ( V_87 -> V_88 * V_87 -> V_94 > 524288 ) ;
F_34 ( V_87 -> V_88 > V_2 -> V_4 -> V_156 ) ;
F_34 ( V_87 -> V_94 > 65535 ) ;
V_2 -> V_87 = V_87 ;
V_2 -> V_157 = 0 ;
V_2 -> V_87 -> V_158 = 0 ;
if ( V_2 -> V_28 & ( V_54 | V_29 ) ) {
struct V_111 * V_105 ;
unsigned int V_159 , V_160 ;
int V_124 ;
V_2 -> V_28 |= V_153 ;
V_159 = 0 ;
V_160 = 0 ;
if ( V_2 -> V_28 & V_29 ) {
if ( V_2 -> V_37 & V_161 ) {
V_159 = 3 ;
V_160 = 3 ;
}
} else {
if ( V_2 -> V_37 & V_162 )
V_159 = 3 ;
if ( V_2 -> V_37 & V_163 )
V_160 = 3 ;
}
if ( F_67 ( V_159 | V_160 ) ) {
F_55 (data->sg, sg, data->sg_len, i) {
if ( V_105 -> V_90 & V_159 ) {
F_32 ( L_22 ,
V_105 -> V_90 ) ;
V_2 -> V_28 &= ~ V_153 ;
break;
}
if ( V_105 -> V_112 & V_160 ) {
F_32 ( L_23 ) ;
V_2 -> V_28 &= ~ V_153 ;
break;
}
}
}
}
if ( V_2 -> V_28 & V_153 ) {
int V_164 = F_42 ( V_2 , V_87 , V_165 ) ;
if ( V_164 <= 0 ) {
F_58 ( 1 ) ;
V_2 -> V_28 &= ~ V_153 ;
} else if ( V_2 -> V_28 & V_29 ) {
F_54 ( V_2 , V_87 , V_164 ) ;
F_13 ( V_2 , V_2 -> V_166 , V_34 ) ;
if ( V_2 -> V_28 & V_30 )
F_13 ( V_2 ,
( V_120 ) V_2 -> V_166 >> 32 ,
V_33 ) ;
} else {
F_58 ( V_164 != 1 ) ;
F_13 ( V_2 , F_56 ( V_87 -> V_105 ) ,
V_5 ) ;
}
}
if ( V_2 -> V_167 >= V_168 ) {
V_71 = F_10 ( V_2 , V_12 ) ;
V_71 &= ~ V_169 ;
if ( ( V_2 -> V_28 & V_153 ) &&
( V_2 -> V_28 & V_29 ) ) {
if ( V_2 -> V_28 & V_30 )
V_71 |= V_170 ;
else
V_71 |= V_171 ;
} else {
V_71 |= V_172 ;
}
F_17 ( V_2 , V_71 , V_12 ) ;
}
if ( ! ( V_2 -> V_28 & V_153 ) ) {
int V_28 ;
V_28 = V_173 ;
if ( V_2 -> V_87 -> V_28 & V_95 )
V_28 |= V_174 ;
else
V_28 |= V_175 ;
F_68 ( & V_2 -> V_89 , V_87 -> V_105 , V_87 -> V_106 , V_28 ) ;
V_2 -> V_94 = V_87 -> V_94 ;
}
F_64 ( V_2 ) ;
F_69 ( V_2 , F_70 ( V_176 ,
V_87 -> V_88 ) , V_7 ) ;
F_69 ( V_2 , V_87 -> V_94 , V_8 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_136 * V_115 )
{
T_5 V_177 = 0 ;
struct V_100 * V_87 = V_115 -> V_87 ;
if ( V_87 == NULL ) {
if ( V_2 -> V_49 &
V_178 ) {
F_69 ( V_2 , 0x0 , V_10 ) ;
} else {
V_177 = F_9 ( V_2 , V_10 ) ;
F_69 ( V_2 , V_177 & ~ ( V_179 |
V_180 ) , V_10 ) ;
}
return;
}
F_58 ( ! V_2 -> V_87 ) ;
if ( ! ( V_2 -> V_49 & V_181 ) )
V_177 = V_182 ;
if ( F_72 ( V_115 -> V_146 ) || V_87 -> V_94 > 1 ) {
V_177 = V_182 | V_183 ;
if ( ! V_2 -> V_184 -> V_185 && ( V_2 -> V_28 & V_186 ) &&
( V_115 -> V_146 != V_187 ) )
V_177 |= V_179 ;
else if ( V_2 -> V_184 -> V_185 && ( V_2 -> V_28 & V_188 ) ) {
V_177 |= V_180 ;
F_13 ( V_2 , V_2 -> V_184 -> V_185 -> V_189 , V_190 ) ;
}
}
if ( V_87 -> V_28 & V_95 )
V_177 |= V_191 ;
if ( V_2 -> V_28 & V_153 )
V_177 |= V_192 ;
F_69 ( V_2 , V_177 , V_10 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_100 * V_87 ;
F_34 ( ! V_2 -> V_87 ) ;
V_87 = V_2 -> V_87 ;
V_2 -> V_87 = NULL ;
if ( ( V_2 -> V_28 & ( V_153 | V_29 ) ) ==
( V_153 | V_29 ) )
F_59 ( V_2 , V_87 ) ;
if ( V_87 -> error )
V_87 -> V_158 = 0 ;
else
V_87 -> V_158 = V_87 -> V_88 * V_87 -> V_94 ;
if ( V_87 -> V_193 &&
( V_87 -> error ||
! V_2 -> V_184 -> V_185 ) ) {
if ( V_87 -> error ) {
F_20 ( V_2 , V_58 ) ;
F_20 ( V_2 , V_59 ) ;
}
F_74 ( V_2 , V_87 -> V_193 ) ;
} else
F_75 ( & V_2 -> V_194 ) ;
}
void F_74 ( struct V_1 * V_2 , struct V_136 * V_115 )
{
int V_28 ;
T_1 V_45 ;
unsigned long V_46 ;
F_58 ( V_2 -> V_115 ) ;
V_115 -> error = 0 ;
V_46 = 10 ;
V_45 = V_195 ;
if ( ( V_115 -> V_87 != NULL ) || ( V_115 -> V_28 & V_155 ) )
V_45 |= V_196 ;
if ( V_2 -> V_184 -> V_87 && ( V_115 == V_2 -> V_184 -> V_87 -> V_193 ) )
V_45 &= ~ V_196 ;
while ( F_8 ( V_2 , V_11 ) & V_45 ) {
if ( V_46 == 0 ) {
F_18 ( L_24 ,
F_7 ( V_2 -> V_4 ) ) ;
F_5 ( V_2 ) ;
V_115 -> error = - V_197 ;
F_75 ( & V_2 -> V_194 ) ;
return;
}
V_46 -- ;
F_19 ( 1 ) ;
}
V_46 = V_198 ;
if ( ! V_115 -> V_87 && V_115 -> V_141 > 9000 )
V_46 += F_62 ( V_115 -> V_141 , 1000 ) * V_199 + V_199 ;
else
V_46 += 10 * V_199 ;
F_76 ( & V_2 -> V_200 , V_46 ) ;
V_2 -> V_115 = V_115 ;
V_2 -> V_201 = 0 ;
F_66 ( V_2 , V_115 ) ;
F_13 ( V_2 , V_115 -> V_189 , V_9 ) ;
F_71 ( V_2 , V_115 ) ;
if ( ( V_115 -> V_28 & V_202 ) && ( V_115 -> V_28 & V_155 ) ) {
F_18 ( L_25 ,
F_7 ( V_2 -> V_4 ) ) ;
V_115 -> error = - V_203 ;
F_75 ( & V_2 -> V_194 ) ;
return;
}
if ( ! ( V_115 -> V_28 & V_204 ) )
V_28 = V_205 ;
else if ( V_115 -> V_28 & V_202 )
V_28 = V_206 ;
else if ( V_115 -> V_28 & V_155 )
V_28 = V_207 ;
else
V_28 = V_208 ;
if ( V_115 -> V_28 & V_209 )
V_28 |= V_210 ;
if ( V_115 -> V_28 & V_211 )
V_28 |= V_212 ;
if ( V_115 -> V_87 || V_115 -> V_146 == V_213 ||
V_115 -> V_146 == V_214 )
V_28 |= V_215 ;
F_69 ( V_2 , F_77 ( V_115 -> V_146 , V_28 ) , V_25 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
int V_124 ;
F_34 ( V_2 -> V_115 == NULL ) ;
if ( V_2 -> V_115 -> V_28 & V_204 ) {
if ( V_2 -> V_115 -> V_28 & V_202 ) {
for ( V_124 = 0 ; V_124 < 4 ; V_124 ++ ) {
V_2 -> V_115 -> V_216 [ V_124 ] = F_8 ( V_2 ,
V_217 + ( 3 - V_124 ) * 4 ) << 8 ;
if ( V_124 != 3 )
V_2 -> V_115 -> V_216 [ V_124 ] |=
F_10 ( V_2 ,
V_217 + ( 3 - V_124 ) * 4 - 1 ) ;
}
} else {
V_2 -> V_115 -> V_216 [ 0 ] = F_8 ( V_2 , V_217 ) ;
}
}
if ( V_2 -> V_115 == V_2 -> V_184 -> V_185 ) {
V_2 -> V_115 = NULL ;
F_74 ( V_2 , V_2 -> V_184 -> V_115 ) ;
} else {
if ( V_2 -> V_87 && V_2 -> V_157 )
F_73 ( V_2 ) ;
if ( ! V_2 -> V_115 -> V_87 )
F_75 ( & V_2 -> V_194 ) ;
V_2 -> V_115 = NULL ;
}
}
static T_5 F_79 ( struct V_1 * V_2 )
{
T_5 V_218 = 0 ;
switch ( V_2 -> V_219 ) {
case V_220 :
V_218 = F_9 ( V_2 , V_221 ) ;
break;
case V_222 :
V_218 = F_9 ( V_2 , V_223 ) ;
break;
case V_224 :
V_218 = F_9 ( V_2 , V_225 ) ;
break;
case V_226 :
case V_227 :
V_218 = F_9 ( V_2 , V_228 ) ;
break;
case V_229 :
case V_230 :
V_218 = F_9 ( V_2 , V_231 ) ;
break;
case V_232 :
V_218 = F_9 ( V_2 , V_233 ) ;
break;
default:
F_80 ( L_26 ,
F_7 ( V_2 -> V_4 ) ) ;
V_218 = F_9 ( V_2 , V_221 ) ;
break;
}
return V_218 ;
}
void F_81 ( struct V_1 * V_2 , unsigned int clock )
{
int div = 0 ;
int V_234 = div , V_235 = 1 ;
T_5 V_236 = 0 ;
unsigned long V_46 ;
bool V_237 = false ;
V_2 -> V_4 -> V_238 = 0 ;
F_69 ( V_2 , 0 , V_16 ) ;
if ( V_2 -> V_49 & V_239 )
F_19 ( 1 ) ;
if ( clock == 0 )
return;
if ( V_2 -> V_167 >= V_240 ) {
if ( V_2 -> V_56 ) {
T_5 V_241 ;
V_236 = F_9 ( V_2 , V_16 ) ;
V_241 = F_79 ( V_2 ) ;
div = ( V_241 & V_242 )
>> V_243 ;
if ( V_2 -> V_235 &&
( V_241 & V_244 ) ) {
V_236 = V_245 ;
V_234 = div + 1 ;
V_235 = V_2 -> V_235 ;
} else {
V_234 = F_82 ( int , 1 , div << 1 ) ;
}
goto V_246;
}
if ( V_2 -> V_235 ) {
for ( div = 1 ; div <= 1024 ; div ++ ) {
if ( ( V_2 -> V_247 * V_2 -> V_235 / div )
<= clock )
break;
}
if ( ( V_2 -> V_247 * V_2 -> V_235 / div ) <= clock ) {
V_236 = V_245 ;
V_234 = div ;
V_235 = V_2 -> V_235 ;
div -- ;
} else {
V_237 = true ;
}
}
if ( ! V_2 -> V_235 || V_237 ) {
if ( V_2 -> V_247 <= clock )
div = 1 ;
else {
for ( div = 2 ; div < V_248 ;
div += 2 ) {
if ( ( V_2 -> V_247 / div ) <= clock )
break;
}
}
V_234 = div ;
div >>= 1 ;
if ( ( V_2 -> V_49 & V_249 )
&& ! div && V_2 -> V_247 <= 25000000 )
div = 1 ;
}
} else {
for ( div = 1 ; div < V_250 ; div *= 2 ) {
if ( ( V_2 -> V_247 / div ) <= clock )
break;
}
V_234 = div ;
div >>= 1 ;
}
V_246:
if ( V_234 )
V_2 -> V_4 -> V_238 = ( V_2 -> V_247 * V_235 ) / V_234 ;
V_236 |= ( div & V_251 ) << V_252 ;
V_236 |= ( ( div & V_253 ) >> V_254 )
<< V_255 ;
V_236 |= V_256 ;
F_69 ( V_2 , V_236 , V_16 ) ;
V_46 = 20 ;
while ( ! ( ( V_236 = F_9 ( V_2 , V_16 ) )
& V_257 ) ) {
if ( V_46 == 0 ) {
F_18 ( L_27 ,
F_7 ( V_2 -> V_4 ) ) ;
F_5 ( V_2 ) ;
return;
}
V_46 -- ;
F_19 ( 1 ) ;
}
V_236 |= V_258 ;
F_69 ( V_2 , V_236 , V_16 ) ;
}
static void F_83 ( struct V_1 * V_2 , unsigned char V_177 ,
unsigned short V_259 )
{
struct V_260 * V_4 = V_2 -> V_4 ;
F_84 ( & V_2 -> V_77 ) ;
F_85 ( V_4 , V_4 -> V_261 . V_262 , V_259 ) ;
F_86 ( & V_2 -> V_77 ) ;
if ( V_177 != V_263 )
F_17 ( V_2 , V_264 , V_13 ) ;
else
F_17 ( V_2 , 0 , V_13 ) ;
}
void F_87 ( struct V_1 * V_2 , unsigned char V_177 ,
unsigned short V_259 )
{
T_2 V_265 = 0 ;
if ( V_177 != V_263 ) {
switch ( 1 << V_259 ) {
case V_266 :
V_265 = V_267 ;
break;
case V_268 :
case V_269 :
V_265 = V_270 ;
break;
case V_271 :
case V_272 :
V_265 = V_273 ;
break;
default:
F_88 ( 1 , L_28 ,
F_7 ( V_2 -> V_4 ) , V_259 ) ;
break;
}
}
if ( V_2 -> V_265 == V_265 )
return;
V_2 -> V_265 = V_265 ;
if ( V_265 == 0 ) {
F_17 ( V_2 , 0 , V_13 ) ;
if ( V_2 -> V_49 & V_50 )
F_4 ( V_2 ) ;
} else {
if ( ! ( V_2 -> V_37 & V_274 ) )
F_17 ( V_2 , 0 , V_13 ) ;
if ( V_2 -> V_37 & V_275 )
F_17 ( V_2 , V_265 , V_13 ) ;
V_265 |= V_264 ;
F_17 ( V_2 , V_265 , V_13 ) ;
if ( V_2 -> V_49 & V_50 )
F_3 ( V_2 ) ;
if ( V_2 -> V_37 & V_276 )
F_19 ( 10 ) ;
}
}
static void F_89 ( struct V_1 * V_2 , unsigned char V_177 ,
unsigned short V_259 )
{
struct V_260 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_52 -> V_277 )
V_2 -> V_52 -> V_277 ( V_2 , V_177 , V_259 ) ;
else if ( ! F_90 ( V_4 -> V_261 . V_262 ) )
F_83 ( V_2 , V_177 , V_259 ) ;
else
F_87 ( V_2 , V_177 , V_259 ) ;
}
static void F_91 ( struct V_260 * V_4 , struct V_278 * V_184 )
{
struct V_1 * V_2 ;
int V_36 ;
unsigned long V_28 ;
V_2 = F_92 ( V_4 ) ;
F_1 ( V_2 ) ;
V_36 = V_4 -> V_52 -> V_279 ( V_4 ) ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
F_58 ( V_2 -> V_184 != NULL ) ;
#ifndef F_93
F_25 ( V_2 ) ;
#endif
if ( ! V_184 -> V_185 && ( V_2 -> V_28 & V_186 ) ) {
if ( V_184 -> V_193 ) {
V_184 -> V_87 -> V_193 = NULL ;
V_184 -> V_193 = NULL ;
}
}
V_2 -> V_184 = V_184 ;
if ( ! V_36 || V_2 -> V_28 & V_280 ) {
V_2 -> V_184 -> V_115 -> error = - V_281 ;
F_75 ( & V_2 -> V_194 ) ;
} else {
if ( V_184 -> V_185 && ! ( V_2 -> V_28 & V_188 ) )
F_74 ( V_2 , V_184 -> V_185 ) ;
else
F_74 ( V_2 , V_184 -> V_115 ) ;
}
F_94 () ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
}
void F_95 ( struct V_1 * V_2 , int V_282 )
{
T_2 V_71 ;
V_71 = F_10 ( V_2 , V_12 ) ;
if ( V_282 == V_283 ) {
V_71 &= ~ V_284 ;
if ( V_2 -> V_167 >= V_240 )
V_71 |= V_285 ;
} else {
if ( V_2 -> V_167 >= V_240 )
V_71 &= ~ V_285 ;
if ( V_282 == V_286 )
V_71 |= V_284 ;
else
V_71 &= ~ V_284 ;
}
F_17 ( V_2 , V_71 , V_12 ) ;
}
void F_96 ( struct V_1 * V_2 , unsigned V_219 )
{
T_5 V_287 ;
V_287 = F_9 ( V_2 , V_27 ) ;
V_287 &= ~ V_288 ;
if ( ( V_219 == V_227 ) ||
( V_219 == V_226 ) )
V_287 |= V_289 ;
else if ( V_219 == V_220 )
V_287 |= V_290 ;
else if ( V_219 == V_222 )
V_287 |= V_291 ;
else if ( V_219 == V_224 )
V_287 |= V_292 ;
else if ( ( V_219 == V_229 ) ||
( V_219 == V_230 ) )
V_287 |= V_293 ;
else if ( V_219 == V_232 )
V_287 |= V_294 ;
F_69 ( V_2 , V_287 , V_27 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_295 * V_70 )
{
unsigned long V_28 ;
T_2 V_71 ;
struct V_260 * V_4 = V_2 -> V_4 ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( V_2 -> V_28 & V_280 ) {
F_30 ( & V_2 -> V_77 , V_28 ) ;
if ( ! F_90 ( V_4 -> V_261 . V_262 ) &&
V_70 -> V_296 == V_263 )
F_85 ( V_4 , V_4 -> V_261 . V_262 , 0 ) ;
return;
}
if ( V_70 -> V_296 == V_263 ) {
F_13 ( V_2 , 0 , V_20 ) ;
F_24 ( V_2 ) ;
}
if ( V_2 -> V_167 >= V_240 &&
( V_70 -> V_296 == V_297 ) &&
! ( V_2 -> V_49 & V_298 ) )
F_98 ( V_2 , false ) ;
if ( ! V_70 -> clock || V_70 -> clock != V_2 -> clock ) {
V_2 -> V_52 -> V_299 ( V_2 , V_70 -> clock ) ;
V_2 -> clock = V_70 -> clock ;
if ( V_2 -> V_37 & V_300 &&
V_2 -> clock ) {
V_2 -> V_145 = V_2 -> V_4 -> V_238 ?
V_2 -> V_4 -> V_238 / 1000 :
V_2 -> clock / 1000 ;
V_2 -> V_4 -> V_301 =
V_2 -> V_52 -> V_302 ?
V_2 -> V_52 -> V_302 ( V_2 ) :
1 << 27 ;
V_2 -> V_4 -> V_301 /= V_2 -> V_145 ;
}
}
F_89 ( V_2 , V_70 -> V_296 , V_70 -> V_259 ) ;
if ( V_2 -> V_52 -> V_303 )
V_2 -> V_52 -> V_303 ( V_2 , V_70 -> V_296 ) ;
V_2 -> V_52 -> V_304 ( V_2 , V_70 -> V_305 ) ;
V_71 = F_10 ( V_2 , V_12 ) ;
if ( ( V_70 -> V_219 == V_306 ||
V_70 -> V_219 == V_307 )
&& ! ( V_2 -> V_37 & V_308 ) )
V_71 |= V_309 ;
else
V_71 &= ~ V_309 ;
if ( V_2 -> V_167 >= V_240 ) {
T_5 V_236 , V_287 ;
if ( ( V_70 -> V_219 == V_232 ) ||
( V_70 -> V_219 == V_227 ) ||
( V_70 -> V_219 == V_230 ) ||
( V_70 -> V_219 == V_224 ) ||
( V_70 -> V_219 == V_226 ) ||
( V_70 -> V_219 == V_229 ) ||
( V_70 -> V_219 == V_222 ) )
V_71 |= V_309 ;
if ( ! V_2 -> V_56 ) {
F_17 ( V_2 , V_71 , V_12 ) ;
V_287 = F_9 ( V_2 , V_27 ) ;
V_287 &= ~ V_310 ;
if ( V_70 -> V_311 == V_312 )
V_287 |= V_313 ;
else if ( V_70 -> V_311 == V_314 )
V_287 |= V_315 ;
else if ( V_70 -> V_311 == V_316 )
V_287 |= V_317 ;
else if ( V_70 -> V_311 == V_318 )
V_287 |= V_319 ;
else {
F_80 ( L_29 ,
F_7 ( V_4 ) ) ;
V_287 |= V_315 ;
}
F_69 ( V_2 , V_287 , V_27 ) ;
} else {
V_236 = F_9 ( V_2 , V_16 ) ;
V_236 &= ~ V_258 ;
F_69 ( V_2 , V_236 , V_16 ) ;
F_17 ( V_2 , V_71 , V_12 ) ;
V_2 -> V_52 -> V_299 ( V_2 , V_2 -> clock ) ;
}
V_236 = F_9 ( V_2 , V_16 ) ;
V_236 &= ~ V_258 ;
F_69 ( V_2 , V_236 , V_16 ) ;
V_2 -> V_52 -> V_320 ( V_2 , V_70 -> V_219 ) ;
V_2 -> V_219 = V_70 -> V_219 ;
if ( ! ( V_2 -> V_49 & V_298 ) &&
( ( V_70 -> V_219 == V_220 ) ||
( V_70 -> V_219 == V_222 ) ||
( V_70 -> V_219 == V_224 ) ||
( V_70 -> V_219 == V_226 ) ||
( V_70 -> V_219 == V_229 ) ||
( V_70 -> V_219 == V_230 ) ) ) {
T_5 V_218 ;
F_98 ( V_2 , true ) ;
V_218 = F_79 ( V_2 ) ;
V_70 -> V_311 = ( V_218 & V_321 )
>> V_322 ;
}
V_2 -> V_52 -> V_299 ( V_2 , V_2 -> clock ) ;
} else
F_17 ( V_2 , V_71 , V_12 ) ;
if ( V_2 -> V_37 & V_323 )
F_20 ( V_2 , V_58 | V_59 ) ;
F_94 () ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
}
static void F_23 ( struct V_260 * V_4 , struct V_295 * V_70 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
F_1 ( V_2 ) ;
F_97 ( V_2 , V_70 ) ;
F_2 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_324 = F_99 ( V_2 -> V_4 ) ;
if ( V_2 -> V_28 & V_280 )
return 0 ;
if ( V_2 -> V_4 -> V_39 & V_40 )
return 1 ;
if ( ! F_100 ( V_324 ) )
return ! ! V_324 ;
if ( V_2 -> V_37 & V_38 )
return 1 ;
return ! ! ( F_8 ( V_2 , V_11 ) & V_41 ) ;
}
static int F_101 ( struct V_260 * V_4 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
int V_325 ;
F_1 ( V_2 ) ;
V_325 = F_21 ( V_2 ) ;
F_2 ( V_2 ) ;
return V_325 ;
}
static int F_102 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
int V_326 ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( V_2 -> V_28 & V_280 )
V_326 = 0 ;
else if ( V_2 -> V_52 -> V_327 )
V_326 = V_2 -> V_52 -> V_327 ( V_2 ) ;
else
V_326 = ! ( F_8 ( V_2 , V_11 )
& V_328 ) ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
return V_2 -> V_37 & V_329 ?
! V_326 : V_326 ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_124 , V_330 ;
if ( ! ( V_2 -> V_37 & V_331 ) )
return F_102 ( V_2 ) ;
V_330 = 0 ;
for ( V_124 = 0 ; V_124 < V_332 ; V_124 ++ ) {
if ( F_102 ( V_2 ) ) {
if ( ++ V_330 > V_332 / 2 )
return 1 ;
}
F_104 ( 30 ) ;
}
return 0 ;
}
static void F_105 ( struct V_260 * V_4 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
if ( V_2 -> V_52 && V_2 -> V_52 -> V_333 )
V_2 -> V_52 -> V_333 ( V_2 ) ;
}
static int F_106 ( struct V_260 * V_4 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
int V_325 ;
F_1 ( V_2 ) ;
V_325 = F_103 ( V_2 ) ;
F_2 ( V_2 ) ;
return V_325 ;
}
static void F_107 ( struct V_1 * V_2 , int V_35 )
{
if ( ! ( V_2 -> V_28 & V_280 ) ) {
if ( V_35 )
V_2 -> V_42 |= V_334 ;
else
V_2 -> V_42 &= ~ V_334 ;
F_13 ( V_2 , V_2 -> V_42 , V_19 ) ;
F_13 ( V_2 , V_2 -> V_42 , V_20 ) ;
F_94 () ;
}
}
static void F_108 ( struct V_260 * V_4 , int V_35 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
unsigned long V_28 ;
F_1 ( V_2 ) ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( V_35 )
V_2 -> V_28 |= V_335 ;
else
V_2 -> V_28 &= ~ V_335 ;
F_107 ( V_2 , V_35 ) ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
F_2 ( V_2 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_295 * V_70 )
{
struct V_260 * V_4 = V_2 -> V_4 ;
T_5 V_71 ;
int V_325 ;
if ( V_2 -> V_167 < V_240 )
return 0 ;
V_71 = F_9 ( V_2 , V_27 ) ;
switch ( V_70 -> V_336 ) {
case V_337 :
V_71 &= ~ V_338 ;
F_69 ( V_2 , V_71 , V_27 ) ;
if ( ! F_90 ( V_4 -> V_261 . V_339 ) ) {
V_325 = F_110 ( V_4 -> V_261 . V_339 , 2700000 ,
3600000 ) ;
if ( V_325 ) {
F_80 ( L_30 ,
F_7 ( V_4 ) ) ;
return - V_197 ;
}
}
F_111 ( 5000 , 5500 ) ;
V_71 = F_9 ( V_2 , V_27 ) ;
if ( ! ( V_71 & V_338 ) )
return 0 ;
F_80 ( L_31 ,
F_7 ( V_4 ) ) ;
return - V_340 ;
case V_341 :
if ( ! F_90 ( V_4 -> V_261 . V_339 ) ) {
V_325 = F_110 ( V_4 -> V_261 . V_339 ,
1700000 , 1950000 ) ;
if ( V_325 ) {
F_80 ( L_32 ,
F_7 ( V_4 ) ) ;
return - V_197 ;
}
}
V_71 |= V_338 ;
F_69 ( V_2 , V_71 , V_27 ) ;
if ( V_2 -> V_52 -> V_342 )
V_2 -> V_52 -> V_342 ( V_2 ) ;
V_71 = F_9 ( V_2 , V_27 ) ;
if ( V_71 & V_338 )
return 0 ;
F_80 ( L_33 ,
F_7 ( V_4 ) ) ;
return - V_340 ;
case V_343 :
if ( ! F_90 ( V_4 -> V_261 . V_339 ) ) {
V_325 = F_110 ( V_4 -> V_261 . V_339 , 1100000 ,
1300000 ) ;
if ( V_325 ) {
F_80 ( L_34 ,
F_7 ( V_4 ) ) ;
return - V_197 ;
}
}
return 0 ;
default:
return 0 ;
}
}
static int F_112 ( struct V_260 * V_4 ,
struct V_295 * V_70 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
int V_344 ;
if ( V_2 -> V_167 < V_240 )
return 0 ;
F_1 ( V_2 ) ;
V_344 = F_109 ( V_2 , V_70 ) ;
F_2 ( V_2 ) ;
return V_344 ;
}
static int F_113 ( struct V_260 * V_4 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
T_1 V_345 ;
F_1 ( V_2 ) ;
V_345 = F_8 ( V_2 , V_11 ) ;
F_2 ( V_2 ) ;
return ! ( V_345 & V_346 ) ;
}
static int F_114 ( struct V_260 * V_4 , struct V_295 * V_70 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
unsigned long V_28 ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
V_2 -> V_28 |= V_347 ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
return 0 ;
}
static int F_115 ( struct V_260 * V_4 , T_1 V_146 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
T_5 V_71 ;
int V_348 = V_349 ;
int V_344 = 0 ;
unsigned long V_28 ;
unsigned int V_350 = 0 ;
bool V_351 ;
F_1 ( V_2 ) ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
V_351 = V_2 -> V_28 & V_347 ;
V_2 -> V_28 &= ~ V_347 ;
if ( V_2 -> V_352 == V_353 )
V_350 = V_2 -> V_350 ;
switch ( V_2 -> V_219 ) {
case V_232 :
V_344 = - V_203 ;
goto V_354;
case V_227 :
if ( V_351 )
V_350 = 0 ;
break;
case V_226 :
case V_229 :
break;
case V_224 :
if ( V_2 -> V_28 & V_355 ||
V_2 -> V_28 & V_356 )
break;
default:
goto V_354;
}
if ( V_2 -> V_52 -> V_357 ) {
F_30 ( & V_2 -> V_77 , V_28 ) ;
V_344 = V_2 -> V_52 -> V_357 ( V_2 , V_146 ) ;
F_2 ( V_2 ) ;
return V_344 ;
}
V_71 = F_9 ( V_2 , V_27 ) ;
V_71 |= V_358 ;
if ( V_2 -> V_49 & V_359 )
V_71 |= V_360 ;
F_69 ( V_2 , V_71 , V_27 ) ;
F_13 ( V_2 , V_148 , V_19 ) ;
F_13 ( V_2 , V_148 , V_20 ) ;
do {
struct V_136 V_115 = { 0 } ;
struct V_278 V_184 = { NULL } ;
V_115 . V_146 = V_146 ;
V_115 . V_189 = 0 ;
V_115 . V_28 = V_361 | V_362 ;
V_115 . V_363 = 0 ;
V_115 . V_87 = NULL ;
V_115 . error = 0 ;
if ( V_348 -- == 0 )
break;
V_184 . V_115 = & V_115 ;
V_2 -> V_184 = & V_184 ;
if ( V_115 . V_146 == V_214 ) {
if ( V_4 -> V_70 . V_305 == V_283 )
F_69 ( V_2 , F_70 ( 7 , 128 ) ,
V_7 ) ;
else if ( V_4 -> V_70 . V_305 == V_286 )
F_69 ( V_2 , F_70 ( 7 , 64 ) ,
V_7 ) ;
} else {
F_69 ( V_2 , F_70 ( 7 , 64 ) ,
V_7 ) ;
}
F_69 ( V_2 , V_191 , V_10 ) ;
F_74 ( V_2 , & V_115 ) ;
V_2 -> V_115 = NULL ;
V_2 -> V_184 = NULL ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
F_116 ( V_2 -> V_364 ,
( V_2 -> V_365 == 1 ) ,
F_117 ( 50 ) ) ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( ! V_2 -> V_365 ) {
F_118 ( V_3 L_35 ) ;
V_71 = F_9 ( V_2 , V_27 ) ;
V_71 &= ~ V_360 ;
V_71 &= ~ V_358 ;
F_69 ( V_2 , V_71 , V_27 ) ;
V_344 = - V_197 ;
goto V_79;
}
V_2 -> V_365 = 0 ;
V_71 = F_9 ( V_2 , V_27 ) ;
if ( V_146 == V_213 )
F_19 ( 1 ) ;
} while ( V_71 & V_358 );
if ( V_348 < 0 ) {
V_71 &= ~ V_360 ;
F_69 ( V_2 , V_71 , V_27 ) ;
}
if ( ! ( V_71 & V_360 ) ) {
F_118 ( V_3 L_36 ) ;
V_344 = - V_197 ;
}
V_79:
if ( V_350 ) {
V_344 = 0 ;
}
V_2 -> V_4 -> V_366 = V_344 ? 0 : V_350 ;
F_13 ( V_2 , V_2 -> V_42 , V_19 ) ;
F_13 ( V_2 , V_2 -> V_42 , V_20 ) ;
V_354:
F_30 ( & V_2 -> V_77 , V_28 ) ;
F_2 ( V_2 ) ;
return V_344 ;
}
static int F_119 ( struct V_367 * V_368 ,
unsigned int V_369 , int V_370 ,
int V_371 , int * V_311 )
{
struct V_1 * V_2 = F_92 ( V_368 -> V_2 ) ;
if ( ! V_2 -> V_52 -> V_372 )
return 0 ;
return V_2 -> V_52 -> V_372 ( V_2 , V_368 , V_369 , V_370 ,
V_371 , V_311 ) ;
}
static void F_98 ( struct V_1 * V_2 , bool V_35 )
{
if ( V_2 -> V_167 < V_240 )
return;
if ( V_2 -> V_56 != V_35 ) {
T_5 V_71 = F_9 ( V_2 , V_27 ) ;
if ( V_35 )
V_71 |= V_373 ;
else
V_71 &= ~ V_373 ;
F_69 ( V_2 , V_71 , V_27 ) ;
if ( V_35 )
V_2 -> V_28 |= V_374 ;
else
V_2 -> V_28 &= ~ V_374 ;
V_2 -> V_56 = V_35 ;
}
}
static void F_120 ( struct V_260 * V_4 , struct V_278 * V_184 ,
int V_344 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
struct V_100 * V_87 = V_184 -> V_87 ;
if ( V_87 -> V_103 != V_375 )
F_121 ( F_44 ( V_2 -> V_4 ) , V_87 -> V_105 , V_87 -> V_106 ,
V_87 -> V_28 & V_107 ?
V_108 : V_109 ) ;
V_87 -> V_103 = V_375 ;
}
static void F_122 ( struct V_260 * V_4 , struct V_278 * V_184 ,
bool V_376 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
V_184 -> V_87 -> V_103 = V_375 ;
if ( V_2 -> V_28 & V_153 )
F_42 ( V_2 , V_184 -> V_87 , V_104 ) ;
}
static void F_123 ( struct V_260 * V_4 )
{
struct V_1 * V_2 = F_92 ( V_4 ) ;
unsigned long V_28 ;
int V_36 ;
if ( V_2 -> V_52 -> V_377 )
V_2 -> V_52 -> V_377 ( V_2 ) ;
V_36 = F_21 ( V_2 ) ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( V_2 -> V_184 && ! V_36 ) {
F_18 ( L_37 ,
F_7 ( V_2 -> V_4 ) ) ;
F_18 ( L_38 ,
F_7 ( V_2 -> V_4 ) ) ;
F_20 ( V_2 , V_58 ) ;
F_20 ( V_2 , V_59 ) ;
V_2 -> V_184 -> V_115 -> error = - V_281 ;
F_75 ( & V_2 -> V_194 ) ;
}
F_30 ( & V_2 -> V_77 , V_28 ) ;
}
static void F_124 ( unsigned long V_378 )
{
struct V_1 * V_2 ;
unsigned long V_28 ;
struct V_278 * V_184 ;
V_2 = (struct V_1 * ) V_378 ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( ! V_2 -> V_184 ) {
F_30 ( & V_2 -> V_77 , V_28 ) ;
return;
}
F_125 ( & V_2 -> V_200 ) ;
V_184 = V_2 -> V_184 ;
if ( V_2 -> V_28 & V_153 ) {
struct V_100 * V_87 = V_184 -> V_87 ;
if ( V_87 && V_87 -> V_103 == V_165 ) {
F_121 ( F_44 ( V_2 -> V_4 ) , V_87 -> V_105 , V_87 -> V_106 ,
( V_87 -> V_28 & V_95 ) ?
V_109 : V_108 ) ;
V_87 -> V_103 = V_375 ;
}
}
if ( ! ( V_2 -> V_28 & V_280 ) &&
( ( V_184 -> V_115 && V_184 -> V_115 -> error ) ||
( V_184 -> V_185 && V_184 -> V_185 -> error ) ||
( V_184 -> V_87 && ( ( V_184 -> V_87 -> error && ! V_184 -> V_87 -> V_193 ) ||
( V_184 -> V_87 -> V_193 && V_184 -> V_87 -> V_193 -> error ) ) ) ||
( V_2 -> V_37 & V_379 ) ) ) {
if ( V_2 -> V_37 & V_380 )
V_2 -> V_52 -> V_299 ( V_2 , V_2 -> clock ) ;
F_20 ( V_2 , V_58 ) ;
F_20 ( V_2 , V_59 ) ;
}
V_2 -> V_184 = NULL ;
V_2 -> V_115 = NULL ;
V_2 -> V_87 = NULL ;
#ifndef F_93
F_26 ( V_2 ) ;
#endif
F_94 () ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
F_126 ( V_2 -> V_4 , V_184 ) ;
F_2 ( V_2 ) ;
}
static void F_127 ( unsigned long V_87 )
{
struct V_1 * V_2 ;
unsigned long V_28 ;
V_2 = (struct V_1 * ) V_87 ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( V_2 -> V_184 ) {
F_18 ( L_39 ,
F_7 ( V_2 -> V_4 ) ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_87 ) {
V_2 -> V_87 -> error = - V_381 ;
F_73 ( V_2 ) ;
} else {
if ( V_2 -> V_115 )
V_2 -> V_115 -> error = - V_381 ;
else
V_2 -> V_184 -> V_115 -> error = - V_381 ;
F_75 ( & V_2 -> V_194 ) ;
}
}
F_94 () ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
}
static void F_128 ( struct V_1 * V_2 , T_1 V_382 , T_1 * V_45 )
{
F_34 ( V_382 == 0 ) ;
if ( ! V_2 -> V_115 ) {
F_18 ( L_40 ,
F_7 ( V_2 -> V_4 ) , ( unsigned ) V_382 ) ;
F_5 ( V_2 ) ;
return;
}
if ( V_382 & ( V_67 | V_66 |
V_65 | V_64 ) ) {
if ( V_382 & V_67 )
V_2 -> V_115 -> error = - V_381 ;
else
V_2 -> V_115 -> error = - V_383 ;
if ( V_2 -> V_115 -> V_87 &&
( V_382 & ( V_66 | V_67 ) ) ==
V_66 ) {
V_2 -> V_115 = NULL ;
return;
}
F_75 ( & V_2 -> V_194 ) ;
return;
}
if ( V_2 -> V_115 -> V_28 & V_155 ) {
if ( V_2 -> V_115 -> V_87 )
F_32 ( L_41 ) ;
else if ( ! ( V_2 -> V_37 & V_384 )
&& ! V_2 -> V_201 ) {
V_2 -> V_201 = 1 ;
return;
}
} else if ( ( V_2 -> V_49 & V_385 ) &&
V_2 -> V_115 -> V_146 == V_386 && ! V_2 -> V_87 ) {
* V_45 &= ~ V_68 ;
}
if ( V_382 & V_69 )
F_78 ( V_2 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
const char * V_387 = F_7 ( V_2 -> V_4 ) ;
void * V_114 = V_2 -> V_125 ;
F_5 ( V_2 ) ;
while ( true ) {
struct V_116 * V_117 = V_114 ;
if ( V_2 -> V_28 & V_30 )
F_32 ( L_42 ,
V_387 , V_114 , F_130 ( V_117 -> V_119 ) ,
F_130 ( V_117 -> V_118 ) ,
F_131 ( V_117 -> V_82 ) ,
F_131 ( V_117 -> V_115 ) ) ;
else
F_32 ( L_43 ,
V_387 , V_114 , F_130 ( V_117 -> V_118 ) ,
F_131 ( V_117 -> V_82 ) ,
F_131 ( V_117 -> V_115 ) ) ;
V_114 += V_2 -> V_130 ;
if ( V_117 -> V_115 & F_51 ( V_121 ) )
break;
}
}
static void F_129 ( struct V_1 * V_2 ) { }
static void F_132 ( struct V_1 * V_2 , T_1 V_382 )
{
T_1 V_388 ;
F_34 ( V_382 == 0 ) ;
if ( V_382 & V_148 ) {
V_388 = F_133 ( F_9 ( V_2 , V_25 ) ) ;
if ( V_388 == V_213 ||
V_388 == V_214 ) {
V_2 -> V_365 = 1 ;
F_134 ( & V_2 -> V_364 ) ;
return;
}
}
if ( ! V_2 -> V_87 ) {
if ( V_2 -> V_115 && ( V_2 -> V_115 -> V_28 & V_155 ) ) {
if ( V_382 & V_63 ) {
V_2 -> V_115 -> error = - V_381 ;
F_75 ( & V_2 -> V_194 ) ;
return;
}
if ( V_382 & V_68 ) {
if ( V_2 -> V_201 )
F_78 ( V_2 ) ;
else
V_2 -> V_201 = 1 ;
return;
}
}
F_18 ( L_44 ,
F_7 ( V_2 -> V_4 ) , ( unsigned ) V_382 ) ;
F_5 ( V_2 ) ;
return;
}
if ( V_382 & V_63 )
V_2 -> V_87 -> error = - V_381 ;
else if ( V_382 & V_61 )
V_2 -> V_87 -> error = - V_383 ;
else if ( ( V_382 & V_62 ) &&
F_133 ( F_9 ( V_2 , V_25 ) )
!= V_389 )
V_2 -> V_87 -> error = - V_383 ;
else if ( V_382 & V_152 ) {
F_18 ( L_45 , F_7 ( V_2 -> V_4 ) ) ;
F_129 ( V_2 ) ;
V_2 -> V_87 -> error = - V_197 ;
if ( V_2 -> V_52 -> V_390 )
V_2 -> V_52 -> V_390 ( V_2 , V_382 ) ;
}
if ( V_2 -> V_87 -> error )
F_73 ( V_2 ) ;
else {
if ( V_382 & ( V_148 | V_149 ) )
F_40 ( V_2 ) ;
if ( V_382 & V_151 ) {
T_1 V_391 , V_392 ;
V_391 = F_56 ( V_2 -> V_87 -> V_105 ) ;
V_392 = V_391 + V_2 -> V_87 -> V_158 ;
V_392 = ( V_392 &
~ ( V_393 - 1 ) ) +
V_393 ;
V_2 -> V_87 -> V_158 = V_392 - V_391 ;
F_32 ( L_46
L_47 ,
F_7 ( V_2 -> V_4 ) , V_391 ,
V_2 -> V_87 -> V_158 , V_392 ) ;
F_13 ( V_2 , V_392 , V_5 ) ;
}
if ( V_382 & V_68 ) {
if ( V_2 -> V_115 ) {
V_2 -> V_157 = 1 ;
} else {
F_73 ( V_2 ) ;
}
}
}
}
static T_6 F_135 ( int V_394 , void * V_395 )
{
T_6 V_396 = V_397 ;
struct V_1 * V_2 = V_395 ;
T_1 V_382 , V_45 , V_398 = 0 ;
int V_399 = 16 ;
F_136 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 && ! F_137 ( V_2 ) ) {
F_138 ( & V_2 -> V_77 ) ;
return V_397 ;
}
V_382 = F_8 ( V_2 , V_18 ) ;
if ( ! V_382 || V_382 == 0xffffffff ) {
V_396 = V_397 ;
goto V_79;
}
do {
V_45 = V_382 & ( V_400 | V_401 |
V_60 ) ;
F_13 ( V_2 , V_45 , V_18 ) ;
F_32 ( L_48 ,
F_7 ( V_2 -> V_4 ) , V_382 ) ;
if ( V_382 & ( V_44 | V_43 ) ) {
T_1 V_36 = F_8 ( V_2 , V_11 ) &
V_41 ;
V_2 -> V_42 &= ~ ( V_44 |
V_43 ) ;
V_2 -> V_42 |= V_36 ? V_43 :
V_44 ;
F_13 ( V_2 , V_2 -> V_42 , V_19 ) ;
F_13 ( V_2 , V_2 -> V_42 , V_20 ) ;
F_13 ( V_2 , V_382 & ( V_44 |
V_43 ) , V_18 ) ;
V_2 -> V_402 |= V_382 & ( V_44 |
V_43 ) ;
V_396 = V_403 ;
}
if ( V_382 & V_400 )
F_128 ( V_2 , V_382 & V_400 ,
& V_382 ) ;
if ( V_382 & V_401 )
F_132 ( V_2 , V_382 & V_401 ) ;
if ( V_382 & V_60 )
F_18 ( L_49 ,
F_7 ( V_2 -> V_4 ) ) ;
if ( V_382 & V_334 ) {
F_107 ( V_2 , false ) ;
V_2 -> V_402 |= V_334 ;
V_396 = V_403 ;
}
V_382 &= ~ ( V_44 | V_43 |
V_400 | V_401 |
V_404 | V_60 |
V_334 ) ;
if ( V_382 ) {
V_398 |= V_382 ;
F_13 ( V_2 , V_382 , V_18 ) ;
}
if ( V_396 == V_397 )
V_396 = V_405 ;
V_382 = F_8 ( V_2 , V_18 ) ;
} while ( V_382 && -- V_399 );
V_79:
F_138 ( & V_2 -> V_77 ) ;
if ( V_398 ) {
F_18 ( L_50 ,
F_7 ( V_2 -> V_4 ) , V_398 ) ;
F_5 ( V_2 ) ;
}
return V_396 ;
}
static T_6 F_139 ( int V_394 , void * V_395 )
{
struct V_1 * V_2 = V_395 ;
unsigned long V_28 ;
T_1 V_406 ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
V_406 = V_2 -> V_402 ;
V_2 -> V_402 = 0 ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
if ( V_406 & ( V_44 | V_43 ) ) {
F_123 ( V_2 -> V_4 ) ;
F_140 ( V_2 -> V_4 , F_117 ( 200 ) ) ;
}
if ( V_406 & V_334 ) {
F_141 ( V_2 -> V_4 ) ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
if ( V_2 -> V_28 & V_335 )
F_107 ( V_2 , true ) ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
}
return V_406 ? V_405 : V_397 ;
}
void F_142 ( struct V_1 * V_2 )
{
T_2 V_144 ;
T_2 V_45 = V_407 | V_408
| V_409 ;
V_144 = F_10 ( V_2 , V_15 ) ;
V_144 |= V_45 ;
if ( V_2 -> V_37 & V_38 )
V_144 &= ~ ( V_407 | V_408 ) ;
F_17 ( V_2 , V_144 , V_15 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
T_2 V_144 ;
T_2 V_45 = V_407 | V_408
| V_409 ;
V_144 = F_10 ( V_2 , V_15 ) ;
V_144 &= ~ V_45 ;
F_17 ( V_2 , V_144 , V_15 ) ;
}
int F_144 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_145 ( V_2 -> V_4 ) ;
F_146 ( V_2 -> V_4 ) ;
if ( ! F_147 ( F_44 ( V_2 -> V_4 ) ) ) {
V_2 -> V_42 = 0 ;
F_13 ( V_2 , 0 , V_19 ) ;
F_13 ( V_2 , 0 , V_20 ) ;
F_148 ( V_2 -> V_394 , V_2 ) ;
} else {
F_142 ( V_2 ) ;
F_149 ( V_2 -> V_394 ) ;
}
return 0 ;
}
int F_150 ( struct V_1 * V_2 )
{
int V_325 = 0 ;
if ( V_2 -> V_28 & ( V_54 | V_29 ) ) {
if ( V_2 -> V_52 -> V_55 )
V_2 -> V_52 -> V_55 ( V_2 ) ;
}
if ( ( V_2 -> V_4 -> V_410 & V_411 ) &&
( V_2 -> V_49 & V_412 ) ) {
F_22 ( V_2 , 0 ) ;
V_2 -> V_265 = 0 ;
V_2 -> clock = 0 ;
F_97 ( V_2 , & V_2 -> V_4 -> V_70 ) ;
} else {
F_22 ( V_2 , ( V_2 -> V_4 -> V_410 & V_411 ) ) ;
F_94 () ;
}
if ( ! F_147 ( F_44 ( V_2 -> V_4 ) ) ) {
V_325 = F_151 ( V_2 -> V_394 , F_135 ,
F_139 , V_413 ,
F_7 ( V_2 -> V_4 ) , V_2 ) ;
if ( V_325 )
return V_325 ;
} else {
F_143 ( V_2 ) ;
F_152 ( V_2 -> V_394 ) ;
}
F_14 ( V_2 ) ;
return V_325 ;
}
static int F_1 ( struct V_1 * V_2 )
{
return F_153 ( V_2 -> V_4 -> V_414 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_154 ( V_2 -> V_4 -> V_414 ) ;
return F_155 ( V_2 -> V_4 -> V_414 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_415 )
return;
V_2 -> V_415 = true ;
F_156 ( V_2 -> V_4 -> V_414 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_415 )
return;
V_2 -> V_415 = false ;
F_157 ( V_2 -> V_4 -> V_414 ) ;
}
int F_158 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_145 ( V_2 -> V_4 ) ;
F_146 ( V_2 -> V_4 ) ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
V_2 -> V_42 &= V_334 ;
F_13 ( V_2 , V_2 -> V_42 , V_19 ) ;
F_13 ( V_2 , V_2 -> V_42 , V_20 ) ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
F_159 ( V_2 -> V_394 ) ;
F_29 ( & V_2 -> V_77 , V_28 ) ;
V_2 -> V_78 = true ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
int V_416 = V_2 -> V_28 ;
if ( V_416 & ( V_54 | V_29 ) ) {
if ( V_2 -> V_52 -> V_55 )
V_2 -> V_52 -> V_55 ( V_2 ) ;
}
F_22 ( V_2 , 0 ) ;
V_2 -> V_265 = 0 ;
V_2 -> clock = 0 ;
F_109 ( V_2 , & V_2 -> V_4 -> V_70 ) ;
F_97 ( V_2 , & V_2 -> V_4 -> V_70 ) ;
if ( ( V_416 & V_374 ) &&
! ( V_2 -> V_49 & V_298 ) ) {
F_29 ( & V_2 -> V_77 , V_28 ) ;
F_98 ( V_2 , true ) ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
}
F_29 ( & V_2 -> V_77 , V_28 ) ;
V_2 -> V_78 = false ;
if ( V_2 -> V_28 & V_335 )
F_107 ( V_2 , true ) ;
F_14 ( V_2 ) ;
F_30 ( & V_2 -> V_77 , V_28 ) ;
return 0 ;
}
struct V_1 * F_161 ( struct V_417 * V_418 ,
T_3 V_419 )
{
struct V_260 * V_4 ;
struct V_1 * V_2 ;
F_58 ( V_418 == NULL ) ;
V_4 = F_162 ( sizeof( struct V_1 ) + V_419 , V_418 ) ;
if ( ! V_4 )
return F_163 ( - V_420 ) ;
V_2 = F_92 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_421 = V_422 ;
V_4 -> V_52 = & V_2 -> V_421 ;
return V_2 ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_260 * V_4 = V_2 -> V_4 ;
struct V_417 * V_418 = F_44 ( V_4 ) ;
int V_325 = - V_203 ;
if ( V_2 -> V_49 & V_423 )
V_2 -> V_28 &= ~ V_30 ;
if ( V_2 -> V_28 & V_30 ) {
V_325 = F_165 ( V_418 , F_166 ( 64 ) ) ;
if ( V_325 ) {
F_80 ( L_51 ,
F_7 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_30 ;
}
}
if ( V_325 ) {
V_325 = F_165 ( V_418 , F_166 ( 32 ) ) ;
if ( V_325 )
F_80 ( L_52 ,
F_7 ( V_4 ) ) ;
}
return V_325 ;
}
int F_167 ( struct V_1 * V_2 )
{
struct V_260 * V_4 ;
T_1 V_39 [ 2 ] = { 0 , 0 } ;
T_1 V_424 ;
unsigned int V_425 ;
unsigned int V_426 ;
T_1 V_247 ;
int V_325 ;
F_58 ( V_2 == NULL ) ;
if ( V_2 == NULL )
return - V_203 ;
V_4 = V_2 -> V_4 ;
if ( V_427 )
V_2 -> V_37 = V_427 ;
if ( V_428 )
V_2 -> V_49 = V_428 ;
V_426 = V_2 -> V_145 ;
F_20 ( V_2 , V_48 ) ;
V_2 -> V_167 = F_9 ( V_2 , V_6 ) ;
V_2 -> V_167 = ( V_2 -> V_167 & V_429 )
>> V_430 ;
if ( V_2 -> V_167 > V_240 ) {
F_18 ( L_53 ,
F_7 ( V_4 ) , V_2 -> V_167 ) ;
}
V_39 [ 0 ] = ( V_2 -> V_37 & V_431 ) ? V_2 -> V_39 :
F_8 ( V_2 , V_23 ) ;
if ( V_2 -> V_167 >= V_240 )
V_39 [ 1 ] = ( V_2 -> V_37 & V_431 ) ?
V_2 -> V_432 :
F_8 ( V_2 , V_24 ) ;
if ( V_2 -> V_37 & V_433 )
V_2 -> V_28 |= V_54 ;
else if ( ! ( V_39 [ 0 ] & V_434 ) )
F_32 ( L_54 ) ;
else
V_2 -> V_28 |= V_54 ;
if ( ( V_2 -> V_37 & V_435 ) &&
( V_2 -> V_28 & V_54 ) ) {
F_32 ( L_55 ) ;
V_2 -> V_28 &= ~ V_54 ;
}
if ( ( V_2 -> V_167 >= V_168 ) &&
( V_39 [ 0 ] & V_436 ) )
V_2 -> V_28 |= V_29 ;
if ( ( V_2 -> V_37 & V_437 ) &&
( V_2 -> V_28 & V_29 ) ) {
F_32 ( L_56 ) ;
V_2 -> V_28 &= ~ V_29 ;
}
if ( V_39 [ 0 ] & V_438 )
V_2 -> V_28 |= V_30 ;
if ( V_2 -> V_28 & ( V_54 | V_29 ) ) {
V_325 = F_164 ( V_2 ) ;
if ( ! V_325 && V_2 -> V_52 -> V_55 )
V_325 = V_2 -> V_52 -> V_55 ( V_2 ) ;
if ( V_325 ) {
F_80 ( L_57 ,
F_7 ( V_4 ) ) ;
V_2 -> V_28 &= ~ ( V_54 | V_29 ) ;
V_325 = 0 ;
}
}
if ( V_2 -> V_28 & V_30 )
V_2 -> V_28 &= ~ V_54 ;
if ( V_2 -> V_28 & V_29 ) {
T_4 V_439 ;
void * V_86 ;
if ( V_2 -> V_28 & V_30 ) {
V_2 -> V_131 = ( V_440 * 2 + 1 ) *
V_441 ;
V_2 -> V_130 = V_441 ;
} else {
V_2 -> V_131 = ( V_440 * 2 + 1 ) *
V_442 ;
V_2 -> V_130 = V_442 ;
}
V_2 -> V_443 = V_440 * V_127 ;
V_86 = F_168 ( F_44 ( V_4 ) , V_2 -> V_443 +
V_2 -> V_131 , & V_439 , V_444 ) ;
if ( ! V_86 ) {
F_80 ( L_58 ,
F_7 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_29 ;
} else if ( ( V_439 + V_2 -> V_443 ) &
( V_445 - 1 ) ) {
F_80 ( L_59 ,
F_7 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_29 ;
F_169 ( F_44 ( V_4 ) , V_2 -> V_443 +
V_2 -> V_131 , V_86 , V_439 ) ;
} else {
V_2 -> V_126 = V_86 ;
V_2 -> V_122 = V_439 ;
V_2 -> V_125 = V_86 + V_2 -> V_443 ;
V_2 -> V_166 = V_439 + V_2 -> V_443 ;
}
}
if ( ! ( V_2 -> V_28 & ( V_54 | V_29 ) ) ) {
V_2 -> V_446 = F_166 ( 64 ) ;
F_44 ( V_4 ) -> V_446 = & V_2 -> V_446 ;
}
if ( V_2 -> V_167 >= V_240 )
V_2 -> V_247 = ( V_39 [ 0 ] & V_447 )
>> V_448 ;
else
V_2 -> V_247 = ( V_39 [ 0 ] & V_449 )
>> V_448 ;
V_2 -> V_247 *= 1000000 ;
if ( V_2 -> V_247 == 0 || V_2 -> V_37 &
V_450 ) {
if ( ! V_2 -> V_52 -> V_451 ) {
F_18 ( L_60 ,
F_7 ( V_4 ) ) ;
return - V_452 ;
}
V_2 -> V_247 = V_2 -> V_52 -> V_451 ( V_2 ) ;
}
V_2 -> V_235 = ( V_39 [ 1 ] & V_453 ) >>
V_454 ;
if ( V_2 -> V_235 )
V_2 -> V_235 += 1 ;
V_247 = V_2 -> V_247 ;
if ( V_2 -> V_52 -> V_455 )
V_4 -> V_456 = V_2 -> V_52 -> V_455 ( V_2 ) ;
else if ( V_2 -> V_167 >= V_240 ) {
if ( V_2 -> V_235 ) {
V_4 -> V_456 = ( V_2 -> V_247 * V_2 -> V_235 ) / 1024 ;
V_247 = V_2 -> V_247 * V_2 -> V_235 ;
} else
V_4 -> V_456 = V_2 -> V_247 / V_248 ;
} else
V_4 -> V_456 = V_2 -> V_247 / V_250 ;
if ( ! V_4 -> V_457 || ( V_4 -> V_457 && ( V_4 -> V_457 > V_247 ) ) )
V_4 -> V_457 = V_247 ;
if ( ! ( V_2 -> V_37 & V_300 ) ) {
V_2 -> V_145 = ( V_39 [ 0 ] & V_458 ) >>
V_459 ;
if ( V_2 -> V_145 == 0 ) {
if ( V_2 -> V_52 -> V_460 ) {
V_2 -> V_145 =
V_2 -> V_52 -> V_460 ( V_2 ) ;
} else {
F_18 ( L_61 ,
F_7 ( V_4 ) ) ;
return - V_452 ;
}
}
if ( V_39 [ 0 ] & V_461 )
V_2 -> V_145 *= 1000 ;
if ( V_426 )
V_2 -> V_145 = V_426 ;
V_4 -> V_301 = V_2 -> V_52 -> V_302 ?
V_2 -> V_52 -> V_302 ( V_2 ) : 1 << 27 ;
V_4 -> V_301 /= V_2 -> V_145 ;
}
V_4 -> V_39 |= V_462 | V_463 | V_464 ;
V_4 -> V_465 |= V_466 ;
if ( V_2 -> V_37 & V_467 )
V_2 -> V_28 |= V_186 ;
if ( ( V_2 -> V_167 >= V_240 ) &&
( ( V_2 -> V_28 & V_29 ) ||
! ( V_2 -> V_28 & V_54 ) ) &&
! ( V_2 -> V_49 & V_468 ) ) {
V_2 -> V_28 |= V_188 ;
F_32 ( L_62 , F_7 ( V_4 ) ) ;
} else {
F_32 ( L_63 , F_7 ( V_4 ) ) ;
}
if ( ! ( V_2 -> V_37 & V_469 ) )
V_4 -> V_39 |= V_470 ;
if ( V_2 -> V_49 & V_471 )
V_4 -> V_39 &= ~ V_464 ;
if ( V_39 [ 0 ] & V_472 )
V_4 -> V_39 |= V_473 | V_474 ;
if ( ( V_2 -> V_37 & V_38 ) &&
! ( V_4 -> V_39 & V_40 ) &&
F_100 ( F_99 ( V_2 -> V_4 ) ) )
V_4 -> V_39 |= V_475 ;
if ( F_170 ( V_4 ) == - V_476 )
return - V_476 ;
if ( ! F_90 ( V_4 -> V_261 . V_339 ) ) {
V_325 = F_171 ( V_4 -> V_261 . V_339 ) ;
if ( ! F_172 ( V_4 -> V_261 . V_339 , 1700000 ,
1950000 ) )
V_39 [ 1 ] &= ~ ( V_477 |
V_478 |
V_479 ) ;
if ( V_325 ) {
F_80 ( L_64 ,
F_7 ( V_4 ) , V_325 ) ;
V_4 -> V_261 . V_339 = F_163 ( - V_203 ) ;
}
}
if ( V_2 -> V_49 & V_480 )
V_39 [ 1 ] &= ~ ( V_477 | V_478 |
V_479 ) ;
if ( V_39 [ 1 ] & ( V_477 | V_478 |
V_479 ) )
V_4 -> V_39 |= V_481 | V_482 ;
if ( V_39 [ 1 ] & V_477 ) {
V_4 -> V_39 |= V_483 | V_484 ;
if ( ! ( V_2 -> V_49 & V_485 ) )
V_4 -> V_465 |= V_486 ;
} else if ( V_39 [ 1 ] & V_478 )
V_4 -> V_39 |= V_484 ;
if ( V_2 -> V_49 & V_487 &&
( V_39 [ 1 ] & V_488 ) )
V_4 -> V_465 |= V_489 ;
if ( ( V_4 -> V_465 & V_490 ) &&
( F_90 ( V_4 -> V_261 . V_339 ) ||
! F_172 ( V_4 -> V_261 . V_339 , 1100000 ,
1300000 ) ) )
V_4 -> V_465 &= ~ V_490 ;
if ( ( V_39 [ 1 ] & V_479 ) &&
! ( V_2 -> V_49 & V_491 ) )
V_4 -> V_39 |= V_492 ;
if ( V_39 [ 1 ] & V_493 )
V_2 -> V_28 |= V_355 ;
if ( V_4 -> V_465 & V_486 )
V_2 -> V_28 |= V_356 ;
if ( V_39 [ 1 ] & V_494 )
V_4 -> V_39 |= V_495 ;
if ( V_39 [ 1 ] & V_496 )
V_4 -> V_39 |= V_497 ;
if ( V_39 [ 1 ] & V_498 )
V_4 -> V_39 |= V_499 ;
V_2 -> V_350 = ( V_39 [ 1 ] & V_500 ) >>
V_501 ;
if ( V_2 -> V_350 )
V_2 -> V_350 = 1 << ( V_2 -> V_350 - 1 ) ;
V_2 -> V_352 = ( V_39 [ 1 ] & V_502 ) >>
V_503 ;
V_425 = 0 ;
V_424 = F_8 ( V_2 , V_26 ) ;
if ( ! V_424 && ! F_90 ( V_4 -> V_261 . V_262 ) ) {
int V_504 = F_173 ( V_4 -> V_261 . V_262 ) ;
if ( V_504 > 0 ) {
V_504 = V_504 / 1000 ;
V_504 = V_504 / V_505 ;
V_504 = F_174 ( T_1 , V_504 , V_506 ) ;
V_424 =
( V_504 << V_507 ) |
( V_504 << V_508 ) |
( V_504 << V_509 ) ;
}
}
if ( V_39 [ 0 ] & V_510 ) {
V_425 |= V_271 | V_272 ;
V_4 -> V_511 = ( ( V_424 &
V_512 ) >>
V_507 ) *
V_505 ;
}
if ( V_39 [ 0 ] & V_513 ) {
V_425 |= V_268 | V_269 ;
V_4 -> V_514 = ( ( V_424 &
V_515 ) >>
V_508 ) *
V_505 ;
}
if ( V_39 [ 0 ] & V_516 ) {
V_425 |= V_266 ;
V_4 -> V_517 = ( ( V_424 &
V_518 ) >>
V_509 ) *
V_505 ;
}
if ( V_2 -> V_519 )
V_425 = V_2 -> V_519 ;
if ( V_4 -> V_425 )
V_425 = V_4 -> V_425 ;
V_4 -> V_425 = V_425 ;
V_4 -> V_520 = V_425 ;
if ( V_2 -> V_520 )
V_4 -> V_520 &= V_2 -> V_520 ;
V_4 -> V_521 = V_425 ;
if ( V_2 -> V_521 )
V_4 -> V_521 &= V_2 -> V_521 ;
else
V_4 -> V_521 &= ~ V_266 ;
V_4 -> V_522 = V_425 ;
if ( V_2 -> V_522 )
V_4 -> V_522 &= V_2 -> V_522 ;
if ( V_4 -> V_425 == 0 ) {
F_18 ( L_65 ,
F_7 ( V_4 ) ) ;
return - V_452 ;
}
F_175 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_28 & V_29 )
V_4 -> V_523 = V_440 ;
else if ( V_2 -> V_28 & V_54 )
V_4 -> V_523 = 1 ;
else
V_4 -> V_523 = V_440 ;
V_4 -> V_524 = 524288 ;
if ( V_2 -> V_28 & V_29 ) {
if ( V_2 -> V_37 & V_525 )
V_4 -> V_526 = 65535 ;
else
V_4 -> V_526 = 65536 ;
} else {
V_4 -> V_526 = V_4 -> V_524 ;
}
if ( V_2 -> V_37 & V_527 ) {
V_4 -> V_156 = 2 ;
} else {
V_4 -> V_156 = ( V_39 [ 0 ] & V_528 ) >>
V_529 ;
if ( V_4 -> V_156 >= 3 ) {
F_80 ( L_66 ,
F_7 ( V_4 ) ) ;
V_4 -> V_156 = 0 ;
}
}
V_4 -> V_156 = 512 << V_4 -> V_156 ;
V_4 -> V_530 = ( V_2 -> V_37 & V_531 ) ? 1 : 65535 ;
F_176 ( & V_2 -> V_194 ,
F_124 , ( unsigned long ) V_2 ) ;
F_177 ( & V_2 -> V_200 , F_127 , ( unsigned long ) V_2 ) ;
F_178 ( & V_2 -> V_364 ) ;
F_22 ( V_2 , 0 ) ;
V_325 = F_151 ( V_2 -> V_394 , F_135 , F_139 ,
V_413 , F_7 ( V_4 ) , V_2 ) ;
if ( V_325 ) {
F_18 ( L_67 ,
F_7 ( V_4 ) , V_2 -> V_394 , V_325 ) ;
goto V_532;
}
#ifdef F_179
F_5 ( V_2 ) ;
#endif
#ifdef F_93
snprintf ( V_2 -> V_533 , sizeof( V_2 -> V_533 ) ,
L_68 , F_7 ( V_4 ) ) ;
V_2 -> V_74 . V_387 = V_2 -> V_533 ;
V_2 -> V_74 . V_76 = V_80 ;
V_2 -> V_74 . V_534 = F_7 ( V_4 ) ;
V_2 -> V_74 . V_535 = F_27 ;
V_325 = F_180 ( F_44 ( V_4 ) , & V_2 -> V_74 ) ;
if ( V_325 ) {
F_18 ( L_69 ,
F_7 ( V_4 ) , V_325 ) ;
goto V_53;
}
#endif
F_94 () ;
F_181 ( V_4 ) ;
F_118 ( L_70 ,
F_7 ( V_4 ) , V_2 -> V_536 , F_182 ( F_44 ( V_4 ) ) ,
( V_2 -> V_28 & V_29 ) ?
( V_2 -> V_28 & V_30 ) ? L_71 : L_72 :
( V_2 -> V_28 & V_54 ) ? L_73 : L_74 ) ;
F_14 ( V_2 ) ;
return 0 ;
#ifdef F_93
V_53:
F_20 ( V_2 , V_48 ) ;
F_13 ( V_2 , 0 , V_19 ) ;
F_13 ( V_2 , 0 , V_20 ) ;
F_148 ( V_2 -> V_394 , V_2 ) ;
#endif
V_532:
F_183 ( & V_2 -> V_194 ) ;
return V_325 ;
}
void F_184 ( struct V_1 * V_2 , int V_537 )
{
struct V_260 * V_4 = V_2 -> V_4 ;
unsigned long V_28 ;
if ( V_537 ) {
F_29 ( & V_2 -> V_77 , V_28 ) ;
V_2 -> V_28 |= V_280 ;
if ( V_2 -> V_184 ) {
F_18 ( L_75
L_76 , F_7 ( V_4 ) ) ;
V_2 -> V_184 -> V_115 -> error = - V_281 ;
F_75 ( & V_2 -> V_194 ) ;
}
F_30 ( & V_2 -> V_77 , V_28 ) ;
}
F_15 ( V_2 ) ;
F_185 ( V_4 ) ;
#ifdef F_93
F_186 ( & V_2 -> V_74 ) ;
#endif
if ( ! V_537 )
F_20 ( V_2 , V_48 ) ;
F_13 ( V_2 , 0 , V_19 ) ;
F_13 ( V_2 , 0 , V_20 ) ;
F_148 ( V_2 -> V_394 , V_2 ) ;
F_187 ( & V_2 -> V_200 ) ;
F_183 ( & V_2 -> V_194 ) ;
if ( ! F_90 ( V_4 -> V_261 . V_339 ) )
F_188 ( V_4 -> V_261 . V_339 ) ;
if ( V_2 -> V_126 )
F_169 ( F_44 ( V_4 ) , V_2 -> V_443 +
V_2 -> V_131 , V_2 -> V_126 ,
V_2 -> V_122 ) ;
V_2 -> V_125 = NULL ;
V_2 -> V_126 = NULL ;
}
void F_189 ( struct V_1 * V_2 )
{
F_190 ( V_2 -> V_4 ) ;
}
static int T_7 F_191 ( void )
{
F_118 ( V_3
L_77 ) ;
F_118 ( V_3 L_78 ) ;
return 0 ;
}
static void T_8 F_192 ( void )
{
}
