static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 L_1 ,
F_3 ( V_2 -> V_4 ) ) ;
F_2 ( V_3 L_2 ,
F_4 ( V_2 , V_5 ) ,
F_5 ( V_2 , V_6 ) ) ;
F_2 ( V_3 L_3 ,
F_5 ( V_2 , V_7 ) ,
F_5 ( V_2 , V_8 ) ) ;
F_2 ( V_3 L_4 ,
F_4 ( V_2 , V_9 ) ,
F_5 ( V_2 , V_10 ) ) ;
F_2 ( V_3 L_5 ,
F_4 ( V_2 , V_11 ) ,
F_6 ( V_2 , V_12 ) ) ;
F_2 ( V_3 L_6 ,
F_6 ( V_2 , V_13 ) ,
F_6 ( V_2 , V_14 ) ) ;
F_2 ( V_3 L_7 ,
F_6 ( V_2 , V_15 ) ,
F_5 ( V_2 , V_16 ) ) ;
F_2 ( V_3 L_8 ,
F_6 ( V_2 , V_17 ) ,
F_4 ( V_2 , V_18 ) ) ;
F_2 ( V_3 L_9 ,
F_4 ( V_2 , V_19 ) ,
F_4 ( V_2 , V_20 ) ) ;
F_2 ( V_3 L_10 ,
F_5 ( V_2 , V_21 ) ,
F_5 ( V_2 , V_22 ) ) ;
F_2 ( V_3 L_11 ,
F_4 ( V_2 , V_23 ) ,
F_4 ( V_2 , V_24 ) ) ;
F_2 ( V_3 L_12 ,
F_5 ( V_2 , V_25 ) ,
F_4 ( V_2 , V_26 ) ) ;
F_2 ( V_3 L_13 ,
F_5 ( V_2 , V_27 ) ) ;
if ( V_2 -> V_28 & V_29 ) {
if ( V_2 -> V_28 & V_30 )
F_2 ( V_3 L_14 ,
F_7 ( V_2 -> V_31 + V_32 ) ,
F_7 ( V_2 -> V_31 + V_33 ) ,
F_7 ( V_2 -> V_31 + V_34 ) ) ;
else
F_2 ( V_3 L_15 ,
F_7 ( V_2 -> V_31 + V_32 ) ,
F_7 ( V_2 -> V_31 + V_34 ) ) ;
}
F_2 ( V_3 L_16 ) ;
}
static inline bool F_8 ( struct V_35 * V_36 )
{
return V_36 -> V_37 || V_36 -> V_28 & V_38 ;
}
static void F_9 ( struct V_1 * V_2 , bool V_39 )
{
T_1 V_40 ;
if ( ( V_2 -> V_41 & V_42 ) ||
! F_10 ( V_2 -> V_4 ) )
return;
if ( V_39 ) {
V_40 = F_4 ( V_2 , V_11 ) &
V_43 ;
V_2 -> V_44 |= V_40 ? V_45 :
V_46 ;
} else {
V_2 -> V_44 &= ~ ( V_45 | V_46 ) ;
}
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_9 ( V_2 , true ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_9 ( V_2 , false ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 )
return;
V_2 -> V_47 = true ;
F_15 ( V_2 -> V_4 -> V_48 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_47 )
return;
V_2 -> V_47 = false ;
F_17 ( V_2 -> V_4 -> V_48 ) ;
}
void F_18 ( struct V_1 * V_2 , T_2 V_49 )
{
unsigned long V_50 ;
F_19 ( V_2 , V_49 , V_51 ) ;
if ( V_49 & V_52 ) {
V_2 -> clock = 0 ;
if ( V_2 -> V_53 & V_54 )
F_16 ( V_2 ) ;
}
V_50 = 100 ;
while ( F_6 ( V_2 , V_51 ) & V_49 ) {
if ( V_50 == 0 ) {
F_2 ( L_17 ,
F_3 ( V_2 -> V_4 ) , ( int ) V_49 ) ;
F_1 ( V_2 ) ;
return;
}
V_50 -- ;
F_20 ( 1 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , T_2 V_49 )
{
if ( V_2 -> V_41 & V_55 ) {
struct V_56 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_57 -> V_58 ( V_4 ) )
return;
}
V_2 -> V_57 -> V_59 ( V_2 , V_49 ) ;
if ( V_49 & V_52 ) {
if ( V_2 -> V_28 & ( V_60 | V_29 ) ) {
if ( V_2 -> V_57 -> V_61 )
V_2 -> V_57 -> V_61 ( V_2 ) ;
}
V_2 -> V_62 = false ;
}
}
static void F_22 ( struct V_1 * V_2 , int V_63 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
if ( V_63 )
F_21 ( V_2 , V_64 | V_65 ) ;
else
F_21 ( V_2 , V_52 ) ;
V_2 -> V_44 = V_66 | V_67 |
V_68 | V_69 |
V_70 | V_71 | V_72 |
V_73 | V_74 |
V_75 ;
if ( V_2 -> V_76 == V_77 ||
V_2 -> V_76 == V_78 )
V_2 -> V_44 |= V_79 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
if ( V_63 ) {
V_2 -> clock = 0 ;
V_4 -> V_57 -> V_80 ( V_4 , & V_4 -> V_81 ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 , 0 ) ;
F_12 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_82 ;
V_82 = F_6 ( V_2 , V_12 ) ;
V_82 |= V_83 ;
F_19 ( V_2 , V_82 , V_12 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_2 V_82 ;
V_82 = F_6 ( V_2 , V_12 ) ;
V_82 &= ~ V_83 ;
F_19 ( V_2 , V_82 , V_12 ) ;
}
static void F_26 ( struct V_84 * V_85 ,
enum V_86 V_87 )
{
struct V_1 * V_2 = F_27 ( V_85 , struct V_1 , V_85 ) ;
unsigned long V_28 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_89 )
goto V_90;
if ( V_87 == V_91 )
F_25 ( V_2 ) ;
else
F_24 ( V_2 ) ;
V_90:
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
snprintf ( V_2 -> V_92 , sizeof( V_2 -> V_92 ) ,
L_18 , F_3 ( V_4 ) ) ;
V_2 -> V_85 . V_93 = V_2 -> V_92 ;
V_2 -> V_85 . V_87 = V_91 ;
V_2 -> V_85 . V_94 = F_3 ( V_4 ) ;
V_2 -> V_85 . V_95 = F_26 ;
return F_31 ( F_32 ( V_4 ) , & V_2 -> V_85 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_85 ) ;
}
static inline void F_35 ( struct V_1 * V_2 )
{
}
static inline void F_36 ( struct V_1 * V_2 )
{
}
static inline int F_30 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
}
static inline void F_35 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
static inline void F_36 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
T_3 V_96 , V_97 , V_98 ;
T_1 V_99 ( V_100 ) ;
T_2 * V_101 ;
F_38 ( L_19 ) ;
V_96 = V_2 -> V_37 -> V_102 ;
V_98 = 0 ;
F_39 ( V_28 ) ;
while ( V_96 ) {
F_40 ( ! F_41 ( & V_2 -> V_103 ) ) ;
V_97 = F_42 ( V_2 -> V_103 . V_104 , V_96 ) ;
V_96 -= V_97 ;
V_2 -> V_103 . V_105 = V_97 ;
V_101 = V_2 -> V_103 . V_106 ;
while ( V_97 ) {
if ( V_98 == 0 ) {
V_100 = F_4 ( V_2 , V_107 ) ;
V_98 = 4 ;
}
* V_101 = V_100 & 0xFF ;
V_101 ++ ;
V_100 >>= 8 ;
V_98 -- ;
V_97 -- ;
}
}
F_43 ( & V_2 -> V_103 ) ;
F_44 ( V_28 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
T_3 V_96 , V_97 , V_98 ;
T_1 V_100 ;
T_2 * V_101 ;
F_38 ( L_20 ) ;
V_96 = V_2 -> V_37 -> V_102 ;
V_98 = 0 ;
V_100 = 0 ;
F_39 ( V_28 ) ;
while ( V_96 ) {
F_40 ( ! F_41 ( & V_2 -> V_103 ) ) ;
V_97 = F_42 ( V_2 -> V_103 . V_104 , V_96 ) ;
V_96 -= V_97 ;
V_2 -> V_103 . V_105 = V_97 ;
V_101 = V_2 -> V_103 . V_106 ;
while ( V_97 ) {
V_100 |= ( T_1 ) * V_101 << ( V_98 * 8 ) ;
V_101 ++ ;
V_98 ++ ;
V_97 -- ;
if ( ( V_98 == 4 ) || ( ( V_97 == 0 ) && ( V_96 == 0 ) ) ) {
F_11 ( V_2 , V_100 , V_107 ) ;
V_98 = 0 ;
V_100 = 0 ;
}
}
}
F_43 ( & V_2 -> V_103 ) ;
F_44 ( V_28 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_49 ;
if ( V_2 -> V_108 == 0 )
return;
if ( V_2 -> V_37 -> V_28 & V_109 )
V_49 = V_110 ;
else
V_49 = V_111 ;
if ( ( V_2 -> V_41 & V_112 ) &&
( V_2 -> V_37 -> V_108 == 1 ) )
V_49 = ~ 0 ;
while ( F_4 ( V_2 , V_11 ) & V_49 ) {
if ( V_2 -> V_41 & V_113 )
F_47 ( 100 ) ;
if ( V_2 -> V_37 -> V_28 & V_109 )
F_37 ( V_2 ) ;
else
F_45 ( V_2 ) ;
V_2 -> V_108 -- ;
if ( V_2 -> V_108 == 0 )
break;
}
F_38 ( L_21 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_114 * V_37 , int V_115 )
{
int V_116 ;
if ( V_37 -> V_117 == V_118 )
return V_37 -> V_116 ;
V_116 = F_49 ( F_32 ( V_2 -> V_4 ) , V_37 -> V_119 , V_37 -> V_120 ,
V_37 -> V_28 & V_121 ?
V_122 : V_123 ) ;
if ( V_116 == 0 )
return - V_124 ;
V_37 -> V_116 = V_116 ;
V_37 -> V_117 = V_115 ;
return V_116 ;
}
static char * F_50 ( struct V_125 * V_119 , unsigned long * V_28 )
{
F_39 ( * V_28 ) ;
return F_51 ( F_52 ( V_119 ) ) + V_119 -> V_126 ;
}
static void F_53 ( void * V_127 , unsigned long * V_28 )
{
F_54 ( V_127 ) ;
F_44 ( * V_28 ) ;
}
static void F_55 ( struct V_1 * V_2 , void * V_128 ,
T_4 V_106 , int V_97 , unsigned V_36 )
{
struct V_129 * V_130 = V_128 ;
V_130 -> V_36 = F_56 ( V_36 ) ;
V_130 -> V_97 = F_56 ( V_97 ) ;
V_130 -> V_131 = F_57 ( ( T_1 ) V_106 ) ;
if ( V_2 -> V_28 & V_30 )
V_130 -> V_132 = F_57 ( ( V_133 ) V_106 >> 32 ) ;
}
static void F_58 ( void * V_128 )
{
struct V_129 * V_130 = V_128 ;
V_130 -> V_36 |= F_56 ( V_134 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_114 * V_37 , int V_116 )
{
struct V_125 * V_119 ;
unsigned long V_28 ;
T_4 V_106 , V_135 ;
void * V_128 , * V_136 ;
char * V_127 ;
int V_97 , V_126 , V_137 ;
V_2 -> V_116 = V_116 ;
V_128 = V_2 -> V_138 ;
V_136 = V_2 -> V_139 ;
V_135 = V_2 -> V_135 ;
F_60 (data->sg, sg, host->sg_count, i) {
V_106 = F_61 ( V_119 ) ;
V_97 = F_62 ( V_119 ) ;
V_126 = ( V_140 - ( V_106 & V_141 ) ) &
V_141 ;
if ( V_126 ) {
if ( V_37 -> V_28 & V_121 ) {
V_127 = F_50 ( V_119 , & V_28 ) ;
memcpy ( V_136 , V_127 , V_126 ) ;
F_53 ( V_127 , & V_28 ) ;
}
F_55 ( V_2 , V_128 , V_135 , V_126 ,
V_142 ) ;
F_40 ( V_126 > 65536 ) ;
V_136 += V_140 ;
V_135 += V_140 ;
V_128 += V_2 -> V_143 ;
V_106 += V_126 ;
V_97 -= V_126 ;
}
F_40 ( V_97 > 65536 ) ;
if ( V_97 ) {
F_55 ( V_2 , V_128 , V_106 , V_97 ,
V_142 ) ;
V_128 += V_2 -> V_143 ;
}
F_63 ( ( V_128 - V_2 -> V_138 ) >= V_2 -> V_144 ) ;
}
if ( V_2 -> V_41 & V_145 ) {
if ( V_128 != V_2 -> V_138 ) {
V_128 -= V_2 -> V_143 ;
F_58 ( V_128 ) ;
}
} else {
F_55 ( V_2 , V_128 , 0 , 0 , V_146 ) ;
}
}
static void F_64 ( struct V_1 * V_2 ,
struct V_114 * V_37 )
{
struct V_125 * V_119 ;
int V_137 , V_147 ;
void * V_136 ;
char * V_127 ;
unsigned long V_28 ;
if ( V_37 -> V_28 & V_109 ) {
bool V_148 = false ;
F_60 (data->sg, sg, host->sg_count, i)
if ( F_61 ( V_119 ) & V_141 ) {
V_148 = true ;
break;
}
if ( V_148 ) {
F_65 ( F_32 ( V_2 -> V_4 ) , V_37 -> V_119 ,
V_37 -> V_120 , V_123 ) ;
V_136 = V_2 -> V_139 ;
F_60 (data->sg, sg, host->sg_count, i) {
if ( F_61 ( V_119 ) & V_141 ) {
V_147 = V_140 -
( F_61 ( V_119 ) & V_141 ) ;
V_127 = F_50 ( V_119 , & V_28 ) ;
memcpy ( V_127 , V_136 , V_147 ) ;
F_53 ( V_127 , & V_28 ) ;
V_136 += V_140 ;
}
}
}
}
}
static T_2 F_66 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
T_2 V_149 ;
struct V_114 * V_37 = V_36 -> V_37 ;
unsigned V_150 , V_151 ;
if ( V_2 -> V_41 & V_152 )
return 0xE ;
if ( ! V_37 && ! V_36 -> V_153 )
return 0xE ;
if ( ! V_37 )
V_150 = V_36 -> V_153 * 1000 ;
else {
V_150 = F_67 ( V_37 -> V_154 , 1000 ) ;
if ( V_2 -> clock && V_37 -> V_155 ) {
unsigned long long V_156 ;
V_156 = 1000000ULL * V_37 -> V_155 ;
if ( F_68 ( V_156 , V_2 -> clock ) )
V_150 ++ ;
V_150 += V_156 ;
}
}
V_149 = 0 ;
V_151 = ( 1 << 13 ) * 1000 / V_2 -> V_157 ;
while ( V_151 < V_150 ) {
V_149 ++ ;
V_151 <<= 1 ;
if ( V_149 >= 0xF )
break;
}
if ( V_149 >= 0xF ) {
F_38 ( L_22 ,
F_3 ( V_2 -> V_4 ) , V_149 , V_36 -> V_158 ) ;
V_149 = 0xE ;
}
return V_149 ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_1 V_159 = V_160 | V_161 ;
T_1 V_162 = V_163 | V_164 ;
if ( V_2 -> V_28 & V_165 )
V_2 -> V_44 = ( V_2 -> V_44 & ~ V_159 ) | V_162 ;
else
V_2 -> V_44 = ( V_2 -> V_44 & ~ V_162 ) | V_159 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
T_2 V_149 ;
if ( V_2 -> V_57 -> V_166 ) {
V_2 -> V_57 -> V_166 ( V_2 , V_36 ) ;
} else {
V_149 = F_66 ( V_2 , V_36 ) ;
F_19 ( V_2 , V_149 , V_17 ) ;
}
}
static void F_71 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
T_2 V_82 ;
struct V_114 * V_37 = V_36 -> V_37 ;
if ( F_8 ( V_36 ) )
F_70 ( V_2 , V_36 ) ;
if ( ! V_37 )
return;
F_63 ( V_2 -> V_37 ) ;
F_40 ( V_37 -> V_102 * V_37 -> V_108 > 524288 ) ;
F_40 ( V_37 -> V_102 > V_2 -> V_4 -> V_167 ) ;
F_40 ( V_37 -> V_108 > 65535 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_168 = 0 ;
V_2 -> V_37 -> V_169 = 0 ;
if ( V_2 -> V_28 & ( V_60 | V_29 ) ) {
struct V_125 * V_119 ;
unsigned int V_170 , V_171 ;
int V_137 ;
V_2 -> V_28 |= V_165 ;
V_170 = 0 ;
V_171 = 0 ;
if ( V_2 -> V_28 & V_29 ) {
if ( V_2 -> V_41 & V_172 ) {
V_170 = 3 ;
V_171 = 3 ;
}
} else {
if ( V_2 -> V_41 & V_173 )
V_170 = 3 ;
if ( V_2 -> V_41 & V_174 )
V_171 = 3 ;
}
if ( F_72 ( V_170 | V_171 ) ) {
F_60 (data->sg, sg, data->sg_len, i) {
if ( V_119 -> V_104 & V_170 ) {
F_38 ( L_23 ,
V_119 -> V_104 ) ;
V_2 -> V_28 &= ~ V_165 ;
break;
}
if ( V_119 -> V_126 & V_171 ) {
F_38 ( L_24 ) ;
V_2 -> V_28 &= ~ V_165 ;
break;
}
}
}
}
if ( V_2 -> V_28 & V_165 ) {
int V_175 = F_48 ( V_2 , V_37 , V_176 ) ;
if ( V_175 <= 0 ) {
F_63 ( 1 ) ;
V_2 -> V_28 &= ~ V_165 ;
} else if ( V_2 -> V_28 & V_29 ) {
F_59 ( V_2 , V_37 , V_175 ) ;
F_11 ( V_2 , V_2 -> V_177 , V_34 ) ;
if ( V_2 -> V_28 & V_30 )
F_11 ( V_2 ,
( V_133 ) V_2 -> V_177 >> 32 ,
V_33 ) ;
} else {
F_63 ( V_175 != 1 ) ;
F_11 ( V_2 , F_61 ( V_37 -> V_119 ) ,
V_5 ) ;
}
}
if ( V_2 -> V_178 >= V_179 ) {
V_82 = F_6 ( V_2 , V_12 ) ;
V_82 &= ~ V_180 ;
if ( ( V_2 -> V_28 & V_165 ) &&
( V_2 -> V_28 & V_29 ) ) {
if ( V_2 -> V_28 & V_30 )
V_82 |= V_181 ;
else
V_82 |= V_182 ;
} else {
V_82 |= V_183 ;
}
F_19 ( V_2 , V_82 , V_12 ) ;
}
if ( ! ( V_2 -> V_28 & V_165 ) ) {
int V_28 ;
V_28 = V_184 ;
if ( V_2 -> V_37 -> V_28 & V_109 )
V_28 |= V_185 ;
else
V_28 |= V_186 ;
F_73 ( & V_2 -> V_103 , V_37 -> V_119 , V_37 -> V_120 , V_28 ) ;
V_2 -> V_108 = V_37 -> V_108 ;
}
F_69 ( V_2 ) ;
F_74 ( V_2 , F_75 ( V_187 ,
V_37 -> V_102 ) , V_7 ) ;
F_74 ( V_2 , V_37 -> V_108 , V_8 ) ;
}
static inline bool F_76 ( struct V_1 * V_2 ,
struct V_188 * V_189 )
{
return ! V_189 -> V_190 && ( V_2 -> V_28 & V_191 ) &&
! V_189 -> V_192 ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_5 V_193 = 0 ;
struct V_114 * V_37 = V_36 -> V_37 ;
if ( V_37 == NULL ) {
if ( V_2 -> V_53 &
V_194 ) {
F_74 ( V_2 , 0x0 , V_10 ) ;
} else {
V_193 = F_5 ( V_2 , V_10 ) ;
F_74 ( V_2 , V_193 & ~ ( V_195 |
V_196 ) , V_10 ) ;
}
return;
}
F_63 ( ! V_2 -> V_37 ) ;
if ( ! ( V_2 -> V_53 & V_197 ) )
V_193 = V_198 ;
if ( F_78 ( V_36 -> V_158 ) || V_37 -> V_108 > 1 ) {
V_193 = V_198 | V_199 ;
if ( F_76 ( V_2 , V_36 -> V_189 ) &&
( V_36 -> V_158 != V_200 ) )
V_193 |= V_195 ;
else if ( V_36 -> V_189 -> V_190 && ( V_2 -> V_28 & V_201 ) ) {
V_193 |= V_196 ;
F_11 ( V_2 , V_36 -> V_189 -> V_190 -> V_202 , V_203 ) ;
}
}
if ( V_37 -> V_28 & V_109 )
V_193 |= V_204 ;
if ( V_2 -> V_28 & V_165 )
V_193 |= V_205 ;
F_74 ( V_2 , V_193 , V_10 ) ;
}
static bool F_79 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
return ( ! ( V_2 -> V_28 & V_206 ) &&
( ( V_189 -> V_36 && V_189 -> V_36 -> error ) ||
( V_189 -> V_190 && V_189 -> V_190 -> error ) ||
( V_189 -> V_37 && ( ( V_189 -> V_37 -> error && ! V_189 -> V_37 -> V_207 ) ||
( V_189 -> V_37 -> V_207 && V_189 -> V_37 -> V_207 -> error ) ) ) ||
( V_2 -> V_41 & V_208 ) ) ) ;
}
static void F_80 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_209 ; V_137 ++ ) {
if ( V_2 -> V_210 [ V_137 ] == V_189 ) {
F_63 ( 1 ) ;
return;
}
}
for ( V_137 = 0 ; V_137 < V_209 ; V_137 ++ ) {
if ( ! V_2 -> V_210 [ V_137 ] ) {
V_2 -> V_210 [ V_137 ] = V_189 ;
break;
}
}
F_63 ( V_137 >= V_209 ) ;
F_81 ( & V_2 -> V_211 ) ;
}
static void F_82 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
if ( V_2 -> V_36 && V_2 -> V_36 -> V_189 == V_189 )
V_2 -> V_36 = NULL ;
if ( V_2 -> V_212 && V_2 -> V_212 -> V_189 == V_189 )
V_2 -> V_212 = NULL ;
if ( V_2 -> V_37 && V_2 -> V_37 -> V_189 == V_189 )
V_2 -> V_37 = NULL ;
if ( F_79 ( V_2 , V_189 ) )
V_2 -> V_213 = true ;
F_80 ( V_2 , V_189 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_35 * V_212 = V_2 -> V_212 ;
struct V_114 * V_37 = V_2 -> V_37 ;
V_2 -> V_37 = NULL ;
V_2 -> V_212 = NULL ;
if ( ( V_2 -> V_28 & ( V_165 | V_29 ) ) ==
( V_165 | V_29 ) )
F_64 ( V_2 , V_37 ) ;
if ( V_37 -> error )
V_37 -> V_169 = 0 ;
else
V_37 -> V_169 = V_37 -> V_102 * V_37 -> V_108 ;
if ( V_37 -> V_207 &&
( V_37 -> error ||
! V_37 -> V_189 -> V_190 ) ) {
if ( V_37 -> error ) {
if ( ! V_2 -> V_36 || V_2 -> V_36 == V_212 )
F_21 ( V_2 , V_64 ) ;
F_21 ( V_2 , V_65 ) ;
}
if ( V_37 -> V_189 -> V_192 ) {
F_82 ( V_2 , V_37 -> V_189 ) ;
} else {
V_2 -> V_36 = NULL ;
F_84 ( V_2 , V_37 -> V_207 ) ;
}
} else {
F_82 ( V_2 , V_37 -> V_189 ) ;
}
}
static void F_85 ( struct V_1 * V_2 , struct V_188 * V_189 ,
unsigned long V_50 )
{
if ( F_8 ( V_189 -> V_36 ) )
F_86 ( & V_2 -> V_214 , V_50 ) ;
else
F_86 ( & V_2 -> V_215 , V_50 ) ;
}
static void F_87 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
if ( F_8 ( V_189 -> V_36 ) )
F_88 ( & V_2 -> V_214 ) ;
else
F_88 ( & V_2 -> V_215 ) ;
}
void F_84 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
int V_28 ;
T_1 V_49 ;
unsigned long V_50 ;
F_63 ( V_2 -> V_36 ) ;
V_36 -> error = 0 ;
if ( ( V_2 -> V_53 & V_216 ) &&
V_36 -> V_158 == V_217 )
V_36 -> V_28 |= V_38 ;
V_50 = 10 ;
V_49 = V_218 ;
if ( F_8 ( V_36 ) )
V_49 |= V_219 ;
if ( V_36 -> V_189 -> V_37 && ( V_36 == V_36 -> V_189 -> V_37 -> V_207 ) )
V_49 &= ~ V_219 ;
while ( F_4 ( V_2 , V_11 ) & V_49 ) {
if ( V_50 == 0 ) {
F_2 ( L_25 ,
F_3 ( V_2 -> V_4 ) ) ;
F_1 ( V_2 ) ;
V_36 -> error = - V_220 ;
F_82 ( V_2 , V_36 -> V_189 ) ;
return;
}
V_50 -- ;
F_20 ( 1 ) ;
}
V_50 = V_221 ;
if ( ! V_36 -> V_37 && V_36 -> V_153 > 9000 )
V_50 += F_67 ( V_36 -> V_153 , 1000 ) * V_222 + V_222 ;
else
V_50 += 10 * V_222 ;
F_85 ( V_2 , V_36 -> V_189 , V_50 ) ;
V_2 -> V_36 = V_36 ;
if ( F_8 ( V_36 ) ) {
F_63 ( V_2 -> V_212 ) ;
V_2 -> V_212 = V_36 ;
}
F_71 ( V_2 , V_36 ) ;
F_11 ( V_2 , V_36 -> V_202 , V_9 ) ;
F_77 ( V_2 , V_36 ) ;
if ( ( V_36 -> V_28 & V_223 ) && ( V_36 -> V_28 & V_38 ) ) {
F_2 ( L_26 ,
F_3 ( V_2 -> V_4 ) ) ;
V_36 -> error = - V_224 ;
F_82 ( V_2 , V_36 -> V_189 ) ;
return;
}
if ( ! ( V_36 -> V_28 & V_225 ) )
V_28 = V_226 ;
else if ( V_36 -> V_28 & V_223 )
V_28 = V_227 ;
else if ( V_36 -> V_28 & V_38 )
V_28 = V_228 ;
else
V_28 = V_229 ;
if ( V_36 -> V_28 & V_230 )
V_28 |= V_231 ;
if ( V_36 -> V_28 & V_232 )
V_28 |= V_233 ;
if ( V_36 -> V_37 || V_36 -> V_158 == V_234 ||
V_36 -> V_158 == V_235 )
V_28 |= V_236 ;
F_74 ( V_2 , F_89 ( V_36 -> V_158 , V_28 ) , V_25 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_137 ;
V_2 -> V_36 = NULL ;
if ( V_36 -> V_28 & V_225 ) {
if ( V_36 -> V_28 & V_223 ) {
for ( V_137 = 0 ; V_137 < 4 ; V_137 ++ ) {
V_36 -> V_237 [ V_137 ] = F_4 ( V_2 ,
V_238 + ( 3 - V_137 ) * 4 ) << 8 ;
if ( V_137 != 3 )
V_36 -> V_237 [ V_137 ] |=
F_6 ( V_2 ,
V_238 + ( 3 - V_137 ) * 4 - 1 ) ;
}
} else {
V_36 -> V_237 [ 0 ] = F_4 ( V_2 , V_238 ) ;
}
}
if ( V_36 -> V_189 -> V_192 && V_36 == V_36 -> V_189 -> V_36 )
F_91 ( V_2 -> V_4 , V_36 -> V_189 ) ;
if ( V_36 -> V_28 & V_38 ) {
if ( V_36 -> V_37 ) {
F_38 ( L_27 ) ;
} else if ( ! ( V_2 -> V_41 & V_239 ) &&
V_36 == V_2 -> V_212 ) {
return;
}
}
if ( V_36 == V_36 -> V_189 -> V_190 ) {
F_84 ( V_2 , V_36 -> V_189 -> V_36 ) ;
} else {
if ( V_2 -> V_37 && V_2 -> V_168 )
F_83 ( V_2 ) ;
if ( ! V_36 -> V_37 )
F_82 ( V_2 , V_36 -> V_189 ) ;
}
}
static T_5 F_92 ( struct V_1 * V_2 )
{
T_5 V_240 = 0 ;
switch ( V_2 -> V_241 ) {
case V_242 :
V_240 = F_5 ( V_2 , V_243 ) ;
break;
case V_244 :
V_240 = F_5 ( V_2 , V_245 ) ;
break;
case V_246 :
V_240 = F_5 ( V_2 , V_247 ) ;
break;
case V_248 :
case V_249 :
V_240 = F_5 ( V_2 , V_250 ) ;
break;
case V_251 :
case V_252 :
V_240 = F_5 ( V_2 , V_253 ) ;
break;
case V_254 :
V_240 = F_5 ( V_2 , V_255 ) ;
break;
default:
F_93 ( L_28 ,
F_3 ( V_2 -> V_4 ) ) ;
V_240 = F_5 ( V_2 , V_243 ) ;
break;
}
return V_240 ;
}
T_5 F_94 ( struct V_1 * V_2 , unsigned int clock ,
unsigned int * V_256 )
{
int div = 0 ;
int V_257 = div , V_258 = 1 ;
T_5 V_259 = 0 ;
bool V_260 = false ;
if ( V_2 -> V_178 >= V_261 ) {
if ( V_2 -> V_62 ) {
T_5 V_262 ;
V_259 = F_5 ( V_2 , V_16 ) ;
V_262 = F_92 ( V_2 ) ;
div = ( V_262 & V_263 )
>> V_264 ;
if ( V_2 -> V_258 &&
( V_262 & V_265 ) ) {
V_259 = V_266 ;
V_257 = div + 1 ;
V_258 = V_2 -> V_258 ;
} else {
V_257 = F_95 ( int , 1 , div << 1 ) ;
}
goto V_267;
}
if ( V_2 -> V_258 ) {
for ( div = 1 ; div <= 1024 ; div ++ ) {
if ( ( V_2 -> V_268 * V_2 -> V_258 / div )
<= clock )
break;
}
if ( ( V_2 -> V_268 * V_2 -> V_258 / div ) <= clock ) {
V_259 = V_266 ;
V_257 = div ;
V_258 = V_2 -> V_258 ;
div -- ;
} else {
V_260 = true ;
}
}
if ( ! V_2 -> V_258 || V_260 ) {
if ( V_2 -> V_268 <= clock )
div = 1 ;
else {
for ( div = 2 ; div < V_269 ;
div += 2 ) {
if ( ( V_2 -> V_268 / div ) <= clock )
break;
}
}
V_257 = div ;
div >>= 1 ;
if ( ( V_2 -> V_53 & V_270 )
&& ! div && V_2 -> V_268 <= 25000000 )
div = 1 ;
}
} else {
for ( div = 1 ; div < V_271 ; div *= 2 ) {
if ( ( V_2 -> V_268 / div ) <= clock )
break;
}
V_257 = div ;
div >>= 1 ;
}
V_267:
if ( V_257 )
* V_256 = ( V_2 -> V_268 * V_258 ) / V_257 ;
V_259 |= ( div & V_272 ) << V_273 ;
V_259 |= ( ( div & V_274 ) >> V_275 )
<< V_276 ;
return V_259 ;
}
void F_96 ( struct V_1 * V_2 , T_5 V_259 )
{
unsigned long V_50 ;
V_259 |= V_277 ;
F_74 ( V_2 , V_259 , V_16 ) ;
V_50 = 20 ;
while ( ! ( ( V_259 = F_5 ( V_2 , V_16 ) )
& V_278 ) ) {
if ( V_50 == 0 ) {
F_2 ( L_29 ,
F_3 ( V_2 -> V_4 ) ) ;
F_1 ( V_2 ) ;
return;
}
V_50 -- ;
F_97 ( & V_2 -> V_88 ) ;
F_98 ( 900 , 1100 ) ;
F_99 ( & V_2 -> V_88 ) ;
}
V_259 |= V_279 ;
F_74 ( V_2 , V_259 , V_16 ) ;
}
void F_100 ( struct V_1 * V_2 , unsigned int clock )
{
T_5 V_259 ;
V_2 -> V_4 -> V_256 = 0 ;
F_74 ( V_2 , 0 , V_16 ) ;
if ( clock == 0 )
return;
V_259 = F_94 ( V_2 , clock , & V_2 -> V_4 -> V_256 ) ;
F_96 ( V_2 , V_259 ) ;
}
static void F_101 ( struct V_1 * V_2 , unsigned char V_193 ,
unsigned short V_280 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
F_97 ( & V_2 -> V_88 ) ;
F_102 ( V_4 , V_4 -> V_281 . V_282 , V_280 ) ;
F_99 ( & V_2 -> V_88 ) ;
if ( V_193 != V_283 )
F_19 ( V_2 , V_284 , V_13 ) ;
else
F_19 ( V_2 , 0 , V_13 ) ;
}
void F_103 ( struct V_1 * V_2 , unsigned char V_193 ,
unsigned short V_280 )
{
T_2 V_285 = 0 ;
if ( V_193 != V_283 ) {
switch ( 1 << V_280 ) {
case V_286 :
V_285 = V_287 ;
break;
case V_288 :
case V_289 :
V_285 = V_290 ;
break;
case V_291 :
case V_292 :
V_285 = V_293 ;
break;
default:
F_104 ( 1 , L_30 ,
F_3 ( V_2 -> V_4 ) , V_280 ) ;
break;
}
}
if ( V_2 -> V_285 == V_285 )
return;
V_2 -> V_285 = V_285 ;
if ( V_285 == 0 ) {
F_19 ( V_2 , 0 , V_13 ) ;
if ( V_2 -> V_53 & V_54 )
F_16 ( V_2 ) ;
} else {
if ( ! ( V_2 -> V_41 & V_294 ) )
F_19 ( V_2 , 0 , V_13 ) ;
if ( V_2 -> V_41 & V_295 )
F_19 ( V_2 , V_285 , V_13 ) ;
V_285 |= V_284 ;
F_19 ( V_2 , V_285 , V_13 ) ;
if ( V_2 -> V_53 & V_54 )
F_14 ( V_2 ) ;
if ( V_2 -> V_41 & V_296 )
F_20 ( 10 ) ;
}
}
void F_105 ( struct V_1 * V_2 , unsigned char V_193 ,
unsigned short V_280 )
{
if ( F_106 ( V_2 -> V_4 -> V_281 . V_282 ) )
F_103 ( V_2 , V_193 , V_280 ) ;
else
F_101 ( V_2 , V_193 , V_280 ) ;
}
static void F_107 ( struct V_56 * V_4 , struct V_188 * V_189 )
{
struct V_1 * V_2 ;
int V_40 ;
unsigned long V_28 ;
V_2 = F_108 ( V_4 ) ;
V_40 = V_4 -> V_57 -> V_58 ( V_4 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
F_35 ( V_2 ) ;
if ( F_76 ( V_2 , V_189 ) ) {
if ( V_189 -> V_207 ) {
V_189 -> V_37 -> V_207 = NULL ;
V_189 -> V_207 = NULL ;
}
}
if ( ! V_40 || V_2 -> V_28 & V_206 ) {
V_189 -> V_36 -> error = - V_297 ;
F_82 ( V_2 , V_189 ) ;
} else {
if ( V_189 -> V_190 && ! ( V_2 -> V_28 & V_201 ) )
F_84 ( V_2 , V_189 -> V_190 ) ;
else
F_84 ( V_2 , V_189 -> V_36 ) ;
}
F_109 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
void F_110 ( struct V_1 * V_2 , int V_298 )
{
T_2 V_82 ;
V_82 = F_6 ( V_2 , V_12 ) ;
if ( V_298 == V_299 ) {
V_82 &= ~ V_300 ;
if ( V_2 -> V_178 >= V_261 )
V_82 |= V_301 ;
} else {
if ( V_2 -> V_178 >= V_261 )
V_82 &= ~ V_301 ;
if ( V_298 == V_302 )
V_82 |= V_300 ;
else
V_82 &= ~ V_300 ;
}
F_19 ( V_2 , V_82 , V_12 ) ;
}
void F_111 ( struct V_1 * V_2 , unsigned V_241 )
{
T_5 V_303 ;
V_303 = F_5 ( V_2 , V_27 ) ;
V_303 &= ~ V_304 ;
if ( ( V_241 == V_249 ) ||
( V_241 == V_248 ) )
V_303 |= V_305 ;
else if ( V_241 == V_242 )
V_303 |= V_306 ;
else if ( V_241 == V_244 )
V_303 |= V_307 ;
else if ( V_241 == V_246 )
V_303 |= V_308 ;
else if ( ( V_241 == V_251 ) ||
( V_241 == V_252 ) )
V_303 |= V_309 ;
else if ( V_241 == V_254 )
V_303 |= V_310 ;
F_74 ( V_2 , V_303 , V_27 ) ;
}
static void F_112 ( struct V_56 * V_4 , struct V_311 * V_81 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
unsigned long V_28 ;
T_2 V_82 ;
if ( V_81 -> V_312 == V_313 )
return;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_28 & V_206 ) {
F_29 ( & V_2 -> V_88 , V_28 ) ;
if ( ! F_106 ( V_4 -> V_281 . V_282 ) &&
V_81 -> V_312 == V_283 )
F_102 ( V_4 , V_4 -> V_281 . V_282 , 0 ) ;
return;
}
if ( V_81 -> V_312 == V_283 ) {
F_11 ( V_2 , 0 , V_20 ) ;
F_23 ( V_2 ) ;
}
if ( V_2 -> V_178 >= V_261 &&
( V_81 -> V_312 == V_314 ) &&
! ( V_2 -> V_53 & V_315 ) )
F_113 ( V_2 , false ) ;
if ( ! V_81 -> clock || V_81 -> clock != V_2 -> clock ) {
V_2 -> V_57 -> V_316 ( V_2 , V_81 -> clock ) ;
V_2 -> clock = V_81 -> clock ;
if ( V_2 -> V_41 & V_317 &&
V_2 -> clock ) {
V_2 -> V_157 = V_2 -> V_4 -> V_256 ?
V_2 -> V_4 -> V_256 / 1000 :
V_2 -> clock / 1000 ;
V_2 -> V_4 -> V_318 =
V_2 -> V_57 -> V_319 ?
V_2 -> V_57 -> V_319 ( V_2 ) :
1 << 27 ;
V_2 -> V_4 -> V_318 /= V_2 -> V_157 ;
}
}
if ( V_2 -> V_57 -> V_320 )
V_2 -> V_57 -> V_320 ( V_2 , V_81 -> V_312 , V_81 -> V_280 ) ;
else
F_105 ( V_2 , V_81 -> V_312 , V_81 -> V_280 ) ;
if ( V_2 -> V_57 -> V_321 )
V_2 -> V_57 -> V_321 ( V_2 , V_81 -> V_312 ) ;
V_2 -> V_57 -> V_322 ( V_2 , V_81 -> V_323 ) ;
V_82 = F_6 ( V_2 , V_12 ) ;
if ( ( V_81 -> V_241 == V_324 ||
V_81 -> V_241 == V_325 ||
V_81 -> V_241 == V_254 ||
V_81 -> V_241 == V_249 ||
V_81 -> V_241 == V_252 ||
V_81 -> V_241 == V_246 ||
V_81 -> V_241 == V_248 ||
V_81 -> V_241 == V_251 ||
V_81 -> V_241 == V_244 )
&& ! ( V_2 -> V_41 & V_326 ) )
V_82 |= V_327 ;
else
V_82 &= ~ V_327 ;
if ( V_2 -> V_178 >= V_261 ) {
T_5 V_259 , V_303 ;
if ( ! V_2 -> V_62 ) {
F_19 ( V_2 , V_82 , V_12 ) ;
V_303 = F_5 ( V_2 , V_27 ) ;
V_303 &= ~ V_328 ;
if ( V_81 -> V_329 == V_330 )
V_303 |= V_331 ;
else if ( V_81 -> V_329 == V_332 )
V_303 |= V_333 ;
else if ( V_81 -> V_329 == V_334 )
V_303 |= V_335 ;
else if ( V_81 -> V_329 == V_336 )
V_303 |= V_337 ;
else {
F_93 ( L_31 ,
F_3 ( V_4 ) ) ;
V_303 |= V_333 ;
}
F_74 ( V_2 , V_303 , V_27 ) ;
} else {
V_259 = F_5 ( V_2 , V_16 ) ;
V_259 &= ~ V_279 ;
F_74 ( V_2 , V_259 , V_16 ) ;
F_19 ( V_2 , V_82 , V_12 ) ;
V_2 -> V_57 -> V_316 ( V_2 , V_2 -> clock ) ;
}
V_259 = F_5 ( V_2 , V_16 ) ;
V_259 &= ~ V_279 ;
F_74 ( V_2 , V_259 , V_16 ) ;
V_2 -> V_57 -> V_338 ( V_2 , V_81 -> V_241 ) ;
V_2 -> V_241 = V_81 -> V_241 ;
if ( ! ( V_2 -> V_53 & V_315 ) &&
( ( V_81 -> V_241 == V_242 ) ||
( V_81 -> V_241 == V_244 ) ||
( V_81 -> V_241 == V_246 ) ||
( V_81 -> V_241 == V_248 ) ||
( V_81 -> V_241 == V_251 ) ||
( V_81 -> V_241 == V_252 ) ) ) {
T_5 V_240 ;
F_113 ( V_2 , true ) ;
V_240 = F_92 ( V_2 ) ;
V_81 -> V_329 = ( V_240 & V_339 )
>> V_340 ;
}
V_2 -> V_57 -> V_316 ( V_2 , V_2 -> clock ) ;
} else
F_19 ( V_2 , V_82 , V_12 ) ;
if ( V_2 -> V_41 & V_341 )
F_21 ( V_2 , V_64 | V_65 ) ;
F_109 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static int F_114 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
int V_342 = F_115 ( V_4 ) ;
if ( V_2 -> V_28 & V_206 )
return 0 ;
if ( ! F_10 ( V_2 -> V_4 ) )
return 1 ;
if ( V_342 >= 0 )
return ! ! V_342 ;
if ( V_2 -> V_41 & V_42 )
return 1 ;
return ! ! ( F_4 ( V_2 , V_11 ) & V_43 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
int V_343 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_28 & V_206 )
V_343 = 0 ;
else if ( V_2 -> V_57 -> V_344 )
V_343 = V_2 -> V_57 -> V_344 ( V_2 ) ;
else
V_343 = ! ( F_4 ( V_2 , V_11 )
& V_345 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return V_2 -> V_41 & V_346 ?
! V_343 : V_343 ;
}
static int F_117 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
int V_137 , V_347 ;
if ( ! ( V_2 -> V_41 & V_348 ) )
return F_116 ( V_2 ) ;
V_347 = 0 ;
for ( V_137 = 0 ; V_137 < V_349 ; V_137 ++ ) {
if ( F_116 ( V_2 ) ) {
if ( ++ V_347 > V_349 / 2 )
return 1 ;
}
F_118 ( 30 ) ;
}
return 0 ;
}
static void F_119 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
if ( V_2 -> V_57 && V_2 -> V_57 -> V_350 )
V_2 -> V_57 -> V_350 ( V_2 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_39 )
{
if ( ! ( V_2 -> V_28 & V_206 ) ) {
if ( V_39 )
V_2 -> V_44 |= V_351 ;
else
V_2 -> V_44 &= ~ V_351 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
F_109 () ;
}
}
static void F_121 ( struct V_56 * V_4 , int V_39 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
unsigned long V_28 ;
if ( V_39 )
F_15 ( V_2 -> V_4 -> V_48 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_39 )
V_2 -> V_28 |= V_352 ;
else
V_2 -> V_28 &= ~ V_352 ;
F_120 ( V_2 , V_39 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
if ( ! V_39 )
F_17 ( V_2 -> V_4 -> V_48 ) ;
}
static int F_122 ( struct V_56 * V_4 ,
struct V_311 * V_81 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
T_5 V_82 ;
int V_353 ;
if ( V_2 -> V_178 < V_261 )
return 0 ;
V_82 = F_5 ( V_2 , V_27 ) ;
switch ( V_81 -> V_354 ) {
case V_355 :
if ( ! ( V_2 -> V_28 & V_356 ) )
return - V_224 ;
V_82 &= ~ V_357 ;
F_74 ( V_2 , V_82 , V_27 ) ;
if ( ! F_106 ( V_4 -> V_281 . V_358 ) ) {
V_353 = F_123 ( V_4 , V_81 ) ;
if ( V_353 ) {
F_93 ( L_32 ,
F_3 ( V_4 ) ) ;
return - V_220 ;
}
}
F_98 ( 5000 , 5500 ) ;
V_82 = F_5 ( V_2 , V_27 ) ;
if ( ! ( V_82 & V_357 ) )
return 0 ;
F_93 ( L_33 ,
F_3 ( V_4 ) ) ;
return - V_359 ;
case V_360 :
if ( ! ( V_2 -> V_28 & V_361 ) )
return - V_224 ;
if ( ! F_106 ( V_4 -> V_281 . V_358 ) ) {
V_353 = F_123 ( V_4 , V_81 ) ;
if ( V_353 ) {
F_93 ( L_34 ,
F_3 ( V_4 ) ) ;
return - V_220 ;
}
}
V_82 |= V_357 ;
F_74 ( V_2 , V_82 , V_27 ) ;
if ( V_2 -> V_57 -> V_362 )
V_2 -> V_57 -> V_362 ( V_2 ) ;
V_82 = F_5 ( V_2 , V_27 ) ;
if ( V_82 & V_357 )
return 0 ;
F_93 ( L_35 ,
F_3 ( V_4 ) ) ;
return - V_359 ;
case V_363 :
if ( ! ( V_2 -> V_28 & V_364 ) )
return - V_224 ;
if ( ! F_106 ( V_4 -> V_281 . V_358 ) ) {
V_353 = F_123 ( V_4 , V_81 ) ;
if ( V_353 ) {
F_93 ( L_36 ,
F_3 ( V_4 ) ) ;
return - V_220 ;
}
}
return 0 ;
default:
return 0 ;
}
}
static int F_124 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
T_1 V_365 ;
V_365 = F_4 ( V_2 , V_11 ) ;
return ! ( V_365 & V_366 ) ;
}
static int F_125 ( struct V_56 * V_4 , struct V_311 * V_81 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
unsigned long V_28 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_28 |= V_367 ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return 0 ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_5 V_82 ;
V_82 = F_5 ( V_2 , V_27 ) ;
V_82 |= V_368 ;
if ( V_2 -> V_53 & V_369 )
V_82 |= V_370 ;
F_74 ( V_2 , V_82 , V_27 ) ;
F_11 ( V_2 , V_160 , V_19 ) ;
F_11 ( V_2 , V_160 , V_20 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
T_5 V_82 ;
V_82 = F_5 ( V_2 , V_27 ) ;
V_82 &= ~ V_370 ;
V_82 &= ~ V_368 ;
F_74 ( V_2 , V_82 , V_27 ) ;
}
static void F_129 ( struct V_1 * V_2 , T_1 V_158 ,
unsigned long V_28 )
{
F_128 ( V_2 ) ;
F_21 ( V_2 , V_64 ) ;
F_21 ( V_2 , V_65 ) ;
F_127 ( V_2 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
F_130 ( V_2 -> V_4 , V_158 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
}
static void F_131 ( struct V_1 * V_2 , T_1 V_158 ,
unsigned long V_28 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
struct V_35 V_36 = {} ;
struct V_188 V_189 = {} ;
V_36 . V_158 = V_158 ;
V_36 . V_28 = V_371 | V_372 ;
V_36 . V_189 = & V_189 ;
V_189 . V_36 = & V_36 ;
if ( V_36 . V_158 == V_235 &&
V_4 -> V_81 . V_323 == V_299 )
F_74 ( V_2 , F_75 ( 7 , 128 ) , V_7 ) ;
else
F_74 ( V_2 , F_75 ( 7 , 64 ) , V_7 ) ;
F_74 ( V_2 , V_204 , V_10 ) ;
F_84 ( V_2 , & V_36 ) ;
V_2 -> V_36 = NULL ;
F_87 ( V_2 , & V_189 ) ;
V_2 -> V_373 = 0 ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
F_132 ( V_2 -> V_374 , ( V_2 -> V_373 == 1 ) ,
F_133 ( 50 ) ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
}
static void F_134 ( struct V_1 * V_2 , T_1 V_158 ,
unsigned long V_28 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_375 ; V_137 ++ ) {
T_5 V_82 ;
F_131 ( V_2 , V_158 , V_28 ) ;
if ( ! V_2 -> V_373 ) {
F_135 ( L_37 ,
F_3 ( V_2 -> V_4 ) ) ;
F_129 ( V_2 , V_158 , V_28 ) ;
return;
}
V_82 = F_5 ( V_2 , V_27 ) ;
if ( ! ( V_82 & V_368 ) ) {
if ( V_82 & V_370 )
return;
break;
}
if ( V_158 == V_234 )
F_20 ( 1 ) ;
}
F_135 ( L_38 ,
F_3 ( V_2 -> V_4 ) ) ;
F_128 ( V_2 ) ;
}
int F_136 ( struct V_56 * V_4 , T_1 V_158 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
int V_376 = 0 ;
unsigned long V_28 ;
unsigned int V_377 = 0 ;
bool V_378 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_378 = V_2 -> V_28 & V_367 ;
if ( V_2 -> V_76 == V_379 )
V_377 = V_2 -> V_377 ;
switch ( V_2 -> V_241 ) {
case V_254 :
V_376 = - V_224 ;
goto V_380;
case V_249 :
if ( V_378 )
V_377 = 0 ;
break;
case V_248 :
case V_251 :
break;
case V_246 :
if ( V_2 -> V_28 & V_381 )
break;
default:
goto V_380;
}
if ( V_2 -> V_57 -> V_382 ) {
F_29 ( & V_2 -> V_88 , V_28 ) ;
V_376 = V_2 -> V_57 -> V_382 ( V_2 , V_158 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
goto V_380;
}
V_2 -> V_4 -> V_383 = V_377 ;
F_126 ( V_2 ) ;
F_134 ( V_2 , V_158 , V_28 ) ;
F_127 ( V_2 ) ;
V_380:
V_2 -> V_28 &= ~ V_367 ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return V_376 ;
}
static int F_137 ( struct V_384 * V_385 ,
unsigned int V_386 , int V_387 ,
int V_388 , int * V_329 )
{
struct V_1 * V_2 = F_108 ( V_385 -> V_2 ) ;
if ( ! V_2 -> V_57 -> V_389 )
return 0 ;
return V_2 -> V_57 -> V_389 ( V_2 , V_385 , V_386 , V_387 ,
V_388 , V_329 ) ;
}
static void F_113 ( struct V_1 * V_2 , bool V_39 )
{
if ( V_2 -> V_178 < V_261 )
return;
if ( V_2 -> V_62 != V_39 ) {
T_5 V_82 = F_5 ( V_2 , V_27 ) ;
if ( V_39 )
V_82 |= V_390 ;
else
V_82 &= ~ V_390 ;
F_74 ( V_2 , V_82 , V_27 ) ;
if ( V_39 )
V_2 -> V_28 |= V_391 ;
else
V_2 -> V_28 &= ~ V_391 ;
V_2 -> V_62 = V_39 ;
}
}
static void F_138 ( struct V_56 * V_4 , struct V_188 * V_189 ,
int V_376 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
struct V_114 * V_37 = V_189 -> V_37 ;
if ( V_37 -> V_117 != V_392 )
F_139 ( F_32 ( V_2 -> V_4 ) , V_37 -> V_119 , V_37 -> V_120 ,
V_37 -> V_28 & V_121 ?
V_122 : V_123 ) ;
V_37 -> V_117 = V_392 ;
}
static void F_140 ( struct V_56 * V_4 , struct V_188 * V_189 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
V_189 -> V_37 -> V_117 = V_392 ;
if ( V_2 -> V_28 & V_165 )
F_48 ( V_2 , V_189 -> V_37 , V_118 ) ;
}
static inline bool F_141 ( struct V_1 * V_2 )
{
return V_2 -> V_36 || V_2 -> V_212 ;
}
static void F_142 ( struct V_1 * V_2 , int V_376 )
{
if ( V_2 -> V_212 ) {
V_2 -> V_212 -> error = V_376 ;
F_82 ( V_2 , V_2 -> V_212 -> V_189 ) ;
}
if ( V_2 -> V_36 ) {
V_2 -> V_36 -> error = V_376 ;
F_82 ( V_2 , V_2 -> V_36 -> V_189 ) ;
}
}
static void F_143 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_108 ( V_4 ) ;
unsigned long V_28 ;
int V_40 ;
if ( V_2 -> V_57 -> V_393 )
V_2 -> V_57 -> V_393 ( V_2 ) ;
V_40 = V_4 -> V_57 -> V_58 ( V_4 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( F_141 ( V_2 ) && ! V_40 ) {
F_2 ( L_39 ,
F_3 ( V_2 -> V_4 ) ) ;
F_2 ( L_40 ,
F_3 ( V_2 -> V_4 ) ) ;
F_21 ( V_2 , V_64 ) ;
F_21 ( V_2 , V_65 ) ;
F_142 ( V_2 , - V_297 ) ;
}
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static bool F_144 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
struct V_188 * V_189 ;
int V_137 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
for ( V_137 = 0 ; V_137 < V_209 ; V_137 ++ ) {
V_189 = V_2 -> V_210 [ V_137 ] ;
if ( V_189 )
break;
}
if ( ! V_189 ) {
F_29 ( & V_2 -> V_88 , V_28 ) ;
return true ;
}
F_87 ( V_2 , V_189 ) ;
if ( V_2 -> V_28 & V_165 ) {
struct V_114 * V_37 = V_189 -> V_37 ;
if ( V_37 && V_37 -> V_117 == V_176 ) {
F_139 ( F_32 ( V_2 -> V_4 ) , V_37 -> V_119 , V_37 -> V_120 ,
( V_37 -> V_28 & V_109 ) ?
V_123 : V_122 ) ;
V_37 -> V_117 = V_392 ;
}
}
if ( F_79 ( V_2 , V_189 ) ) {
if ( V_2 -> V_36 || V_2 -> V_212 ) {
F_29 ( & V_2 -> V_88 , V_28 ) ;
return true ;
}
if ( V_2 -> V_41 & V_394 )
V_2 -> V_57 -> V_316 ( V_2 , V_2 -> clock ) ;
F_21 ( V_2 , V_64 ) ;
F_21 ( V_2 , V_65 ) ;
V_2 -> V_213 = false ;
}
if ( ! F_141 ( V_2 ) )
F_36 ( V_2 ) ;
V_2 -> V_210 [ V_137 ] = NULL ;
F_109 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
F_145 ( V_2 -> V_4 , V_189 ) ;
return false ;
}
static void F_146 ( unsigned long V_395 )
{
struct V_1 * V_2 = (struct V_1 * ) V_395 ;
while ( ! F_144 ( V_2 ) )
;
}
static void F_147 ( unsigned long V_37 )
{
struct V_1 * V_2 ;
unsigned long V_28 ;
V_2 = (struct V_1 * ) V_37 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_36 && ! F_8 ( V_2 -> V_36 ) ) {
F_2 ( L_41 ,
F_3 ( V_2 -> V_4 ) ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 -> error = - V_396 ;
F_82 ( V_2 , V_2 -> V_36 -> V_189 ) ;
}
F_109 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static void F_148 ( unsigned long V_37 )
{
struct V_1 * V_2 ;
unsigned long V_28 ;
V_2 = (struct V_1 * ) V_37 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_37 || V_2 -> V_212 ||
( V_2 -> V_36 && F_8 ( V_2 -> V_36 ) ) ) {
F_2 ( L_42 ,
F_3 ( V_2 -> V_4 ) ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_37 ) {
V_2 -> V_37 -> error = - V_396 ;
F_83 ( V_2 ) ;
} else if ( V_2 -> V_212 ) {
V_2 -> V_212 -> error = - V_396 ;
F_82 ( V_2 , V_2 -> V_212 -> V_189 ) ;
} else {
V_2 -> V_36 -> error = - V_396 ;
F_82 ( V_2 , V_2 -> V_36 -> V_189 ) ;
}
}
F_109 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static void F_149 ( struct V_1 * V_2 , T_1 V_397 )
{
if ( ! V_2 -> V_36 ) {
if ( V_2 -> V_213 )
return;
F_2 ( L_43 ,
F_3 ( V_2 -> V_4 ) , ( unsigned ) V_397 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_397 & ( V_73 | V_72 |
V_71 | V_70 ) ) {
if ( V_397 & V_73 )
V_2 -> V_36 -> error = - V_396 ;
else
V_2 -> V_36 -> error = - V_398 ;
if ( V_2 -> V_36 -> V_37 &&
( V_397 & ( V_72 | V_73 ) ) ==
V_72 ) {
V_2 -> V_36 = NULL ;
return;
}
F_82 ( V_2 , V_2 -> V_36 -> V_189 ) ;
return;
}
if ( V_397 & V_75 )
F_90 ( V_2 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
const char * V_93 = F_3 ( V_2 -> V_4 ) ;
void * V_128 = V_2 -> V_138 ;
F_1 ( V_2 ) ;
while ( true ) {
struct V_129 * V_130 = V_128 ;
if ( V_2 -> V_28 & V_30 )
F_38 ( L_44 ,
V_93 , V_128 , F_151 ( V_130 -> V_132 ) ,
F_151 ( V_130 -> V_131 ) ,
F_152 ( V_130 -> V_97 ) ,
F_152 ( V_130 -> V_36 ) ) ;
else
F_38 ( L_45 ,
V_93 , V_128 , F_151 ( V_130 -> V_131 ) ,
F_152 ( V_130 -> V_97 ) ,
F_152 ( V_130 -> V_36 ) ) ;
V_128 += V_2 -> V_143 ;
if ( V_130 -> V_36 & F_56 ( V_134 ) )
break;
}
}
static void F_150 ( struct V_1 * V_2 ) { }
static void F_153 ( struct V_1 * V_2 , T_1 V_397 )
{
T_1 V_399 ;
if ( V_397 & V_160 ) {
V_399 = F_154 ( F_5 ( V_2 , V_25 ) ) ;
if ( V_399 == V_234 ||
V_399 == V_235 ) {
V_2 -> V_373 = 1 ;
F_155 ( & V_2 -> V_374 ) ;
return;
}
}
if ( ! V_2 -> V_37 ) {
struct V_35 * V_212 = V_2 -> V_212 ;
if ( V_212 && ( V_212 -> V_28 & V_38 ) ) {
if ( V_397 & V_69 ) {
V_2 -> V_212 = NULL ;
V_212 -> error = - V_396 ;
F_82 ( V_2 , V_212 -> V_189 ) ;
return;
}
if ( V_397 & V_74 ) {
V_2 -> V_212 = NULL ;
if ( V_2 -> V_36 == V_212 )
return;
F_82 ( V_2 , V_212 -> V_189 ) ;
return;
}
}
if ( V_2 -> V_213 )
return;
F_2 ( L_46 ,
F_3 ( V_2 -> V_4 ) , ( unsigned ) V_397 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_397 & V_69 )
V_2 -> V_37 -> error = - V_396 ;
else if ( V_397 & V_67 )
V_2 -> V_37 -> error = - V_398 ;
else if ( ( V_397 & V_68 ) &&
F_154 ( F_5 ( V_2 , V_25 ) )
!= V_400 )
V_2 -> V_37 -> error = - V_398 ;
else if ( V_397 & V_164 ) {
F_2 ( L_47 , F_3 ( V_2 -> V_4 ) ) ;
F_150 ( V_2 ) ;
V_2 -> V_37 -> error = - V_220 ;
if ( V_2 -> V_57 -> V_401 )
V_2 -> V_57 -> V_401 ( V_2 , V_397 ) ;
}
if ( V_2 -> V_37 -> error )
F_83 ( V_2 ) ;
else {
if ( V_397 & ( V_160 | V_161 ) )
F_46 ( V_2 ) ;
if ( V_397 & V_163 ) {
T_1 V_402 , V_403 ;
V_402 = F_61 ( V_2 -> V_37 -> V_119 ) ;
V_403 = V_402 + V_2 -> V_37 -> V_169 ;
V_403 = ( V_403 &
~ ( V_404 - 1 ) ) +
V_404 ;
V_2 -> V_37 -> V_169 = V_403 - V_402 ;
F_38 ( L_48
L_49 ,
F_3 ( V_2 -> V_4 ) , V_402 ,
V_2 -> V_37 -> V_169 , V_403 ) ;
F_11 ( V_2 , V_403 , V_5 ) ;
}
if ( V_397 & V_74 ) {
if ( V_2 -> V_36 == V_2 -> V_212 ) {
V_2 -> V_168 = 1 ;
} else {
F_83 ( V_2 ) ;
}
}
}
}
static T_6 F_156 ( int V_405 , void * V_406 )
{
T_6 V_407 = V_408 ;
struct V_1 * V_2 = V_406 ;
T_1 V_397 , V_49 , V_409 = 0 ;
int V_410 = 16 ;
F_157 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_89 && ! F_158 ( V_2 ) ) {
F_159 ( & V_2 -> V_88 ) ;
return V_408 ;
}
V_397 = F_4 ( V_2 , V_18 ) ;
if ( ! V_397 || V_397 == 0xffffffff ) {
V_407 = V_408 ;
goto V_90;
}
do {
V_49 = V_397 & ( V_411 | V_412 |
V_66 ) ;
F_11 ( V_2 , V_49 , V_18 ) ;
F_38 ( L_50 ,
F_3 ( V_2 -> V_4 ) , V_397 ) ;
if ( V_397 & ( V_46 | V_45 ) ) {
T_1 V_40 = F_4 ( V_2 , V_11 ) &
V_43 ;
V_2 -> V_44 &= ~ ( V_46 |
V_45 ) ;
V_2 -> V_44 |= V_40 ? V_45 :
V_46 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
F_11 ( V_2 , V_397 & ( V_46 |
V_45 ) , V_18 ) ;
V_2 -> V_413 |= V_397 & ( V_46 |
V_45 ) ;
V_407 = V_414 ;
}
if ( V_397 & V_411 )
F_149 ( V_2 , V_397 & V_411 ) ;
if ( V_397 & V_412 )
F_153 ( V_2 , V_397 & V_412 ) ;
if ( V_397 & V_66 )
F_2 ( L_51 ,
F_3 ( V_2 -> V_4 ) ) ;
if ( V_397 & V_79 )
F_160 ( V_2 -> V_4 ) ;
if ( ( V_397 & V_351 ) &&
( V_2 -> V_44 & V_351 ) ) {
F_120 ( V_2 , false ) ;
V_2 -> V_413 |= V_351 ;
V_407 = V_414 ;
}
V_397 &= ~ ( V_46 | V_45 |
V_411 | V_412 |
V_415 | V_66 |
V_79 | V_351 ) ;
if ( V_397 ) {
V_409 |= V_397 ;
F_11 ( V_2 , V_397 , V_18 ) ;
}
if ( V_407 == V_408 )
V_407 = V_416 ;
V_397 = F_4 ( V_2 , V_18 ) ;
} while ( V_397 && -- V_410 );
V_90:
F_159 ( & V_2 -> V_88 ) ;
if ( V_409 ) {
F_2 ( L_52 ,
F_3 ( V_2 -> V_4 ) , V_409 ) ;
F_1 ( V_2 ) ;
}
return V_407 ;
}
static T_6 F_161 ( int V_405 , void * V_406 )
{
struct V_1 * V_2 = V_406 ;
unsigned long V_28 ;
T_1 V_417 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_417 = V_2 -> V_413 ;
V_2 -> V_413 = 0 ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
if ( V_417 & ( V_46 | V_45 ) ) {
struct V_56 * V_4 = V_2 -> V_4 ;
V_4 -> V_57 -> V_393 ( V_4 ) ;
F_162 ( V_4 , F_133 ( 200 ) ) ;
}
if ( V_417 & V_351 ) {
F_163 ( V_2 -> V_4 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_28 & V_352 )
F_120 ( V_2 , true ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
return V_417 ? V_416 : V_408 ;
}
void F_164 ( struct V_1 * V_2 )
{
T_2 V_156 ;
T_2 V_49 = V_418 | V_419
| V_420 ;
T_1 V_421 = V_46 | V_45 |
V_351 ;
V_156 = F_6 ( V_2 , V_15 ) ;
V_156 |= V_49 ;
if ( V_2 -> V_41 & V_42 ) {
V_156 &= ~ ( V_418 | V_419 ) ;
V_421 &= ~ ( V_46 | V_45 ) ;
}
F_19 ( V_2 , V_156 , V_15 ) ;
F_11 ( V_2 , V_421 , V_19 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
T_2 V_156 ;
T_2 V_49 = V_418 | V_419
| V_420 ;
V_156 = F_6 ( V_2 , V_15 ) ;
V_156 &= ~ V_49 ;
F_19 ( V_2 , V_156 , V_15 ) ;
}
int F_166 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_167 ( V_2 -> V_4 ) ;
if ( V_2 -> V_76 != V_78 )
F_160 ( V_2 -> V_4 ) ;
if ( ! F_168 ( F_32 ( V_2 -> V_4 ) ) ) {
V_2 -> V_44 = 0 ;
F_11 ( V_2 , 0 , V_19 ) ;
F_11 ( V_2 , 0 , V_20 ) ;
F_169 ( V_2 -> V_405 , V_2 ) ;
} else {
F_164 ( V_2 ) ;
F_170 ( V_2 -> V_405 ) ;
}
return 0 ;
}
int F_171 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
int V_353 = 0 ;
if ( V_2 -> V_28 & ( V_60 | V_29 ) ) {
if ( V_2 -> V_57 -> V_61 )
V_2 -> V_57 -> V_61 ( V_2 ) ;
}
if ( ( V_2 -> V_4 -> V_422 & V_423 ) &&
( V_2 -> V_53 & V_424 ) ) {
F_22 ( V_2 , 0 ) ;
V_2 -> V_285 = 0 ;
V_2 -> clock = 0 ;
V_4 -> V_57 -> V_80 ( V_4 , & V_4 -> V_81 ) ;
} else {
F_22 ( V_2 , ( V_2 -> V_4 -> V_422 & V_423 ) ) ;
F_109 () ;
}
if ( ! F_168 ( F_32 ( V_2 -> V_4 ) ) ) {
V_353 = F_172 ( V_2 -> V_405 , F_156 ,
F_161 , V_425 ,
F_3 ( V_2 -> V_4 ) , V_2 ) ;
if ( V_353 )
return V_353 ;
} else {
F_165 ( V_2 ) ;
F_173 ( V_2 -> V_405 ) ;
}
F_12 ( V_2 ) ;
return V_353 ;
}
int F_174 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_167 ( V_2 -> V_4 ) ;
if ( V_2 -> V_76 != V_78 )
F_160 ( V_2 -> V_4 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_44 &= V_351 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
F_175 ( V_2 -> V_405 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_89 = true ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return 0 ;
}
int F_176 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
unsigned long V_28 ;
int V_426 = V_2 -> V_28 ;
if ( V_426 & ( V_60 | V_29 ) ) {
if ( V_2 -> V_57 -> V_61 )
V_2 -> V_57 -> V_61 ( V_2 ) ;
}
F_22 ( V_2 , 0 ) ;
if ( V_4 -> V_81 . V_312 != V_313 ) {
V_2 -> V_285 = 0 ;
V_2 -> clock = 0 ;
V_4 -> V_57 -> V_427 ( V_4 , & V_4 -> V_81 ) ;
V_4 -> V_57 -> V_80 ( V_4 , & V_4 -> V_81 ) ;
if ( ( V_426 & V_391 ) &&
! ( V_2 -> V_53 & V_315 ) ) {
F_28 ( & V_2 -> V_88 , V_28 ) ;
F_113 ( V_2 , true ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
if ( ( V_4 -> V_428 & V_429 ) &&
V_4 -> V_57 -> V_430 )
V_4 -> V_57 -> V_430 ( V_4 , & V_4 -> V_81 ) ;
}
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_89 = false ;
if ( V_2 -> V_28 & V_352 )
F_120 ( V_2 , true ) ;
F_12 ( V_2 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return 0 ;
}
struct V_1 * F_177 ( struct V_431 * V_432 ,
T_3 V_433 )
{
struct V_56 * V_4 ;
struct V_1 * V_2 ;
F_63 ( V_432 == NULL ) ;
V_4 = F_178 ( sizeof( struct V_1 ) + V_433 , V_432 ) ;
if ( ! V_4 )
return F_179 ( - V_434 ) ;
V_2 = F_108 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_435 = V_436 ;
V_4 -> V_57 = & V_2 -> V_435 ;
V_2 -> V_28 = V_356 ;
return V_2 ;
}
static int F_180 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
struct V_431 * V_432 = F_32 ( V_4 ) ;
int V_353 = - V_224 ;
if ( V_2 -> V_53 & V_437 )
V_2 -> V_28 &= ~ V_30 ;
if ( V_2 -> V_28 & V_30 ) {
V_353 = F_181 ( V_432 , F_182 ( 64 ) ) ;
if ( V_353 ) {
F_93 ( L_53 ,
F_3 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_30 ;
}
}
if ( V_353 ) {
V_353 = F_181 ( V_432 , F_182 ( 32 ) ) ;
if ( V_353 )
F_93 ( L_54 ,
F_3 ( V_4 ) ) ;
}
return V_353 ;
}
void F_183 ( struct V_1 * V_2 , T_5 * V_438 , T_1 * V_439 , T_1 * V_440 )
{
T_5 V_441 ;
V_133 V_442 = 0 ;
V_133 V_443 = 0 ;
if ( V_2 -> V_444 )
return;
V_2 -> V_444 = true ;
if ( V_445 )
V_2 -> V_41 = V_445 ;
if ( V_446 )
V_2 -> V_53 = V_446 ;
F_21 ( V_2 , V_52 ) ;
F_184 ( F_32 ( V_2 -> V_4 ) -> V_447 ,
L_55 , & V_442 ) ;
F_184 ( F_32 ( V_2 -> V_4 ) -> V_447 ,
L_56 , & V_443 ) ;
V_441 = V_438 ? * V_438 : F_5 ( V_2 , V_6 ) ;
V_2 -> V_178 = ( V_441 & V_448 ) >> V_449 ;
if ( V_2 -> V_41 & V_450 )
return;
if ( V_439 ) {
V_2 -> V_439 = * V_439 ;
} else {
V_2 -> V_439 = F_4 ( V_2 , V_23 ) ;
V_2 -> V_439 &= ~ F_185 ( V_442 ) ;
V_2 -> V_439 |= F_185 ( V_443 ) ;
}
if ( V_2 -> V_178 < V_261 )
return;
if ( V_440 ) {
V_2 -> V_440 = * V_440 ;
} else {
V_2 -> V_440 = F_4 ( V_2 , V_24 ) ;
V_2 -> V_440 &= ~ F_186 ( V_442 ) ;
V_2 -> V_440 |= F_186 ( V_443 ) ;
}
}
int F_187 ( struct V_1 * V_2 )
{
struct V_56 * V_4 ;
T_1 V_451 ;
unsigned int V_452 ;
unsigned int V_453 ;
T_1 V_268 ;
int V_353 ;
F_63 ( V_2 == NULL ) ;
if ( V_2 == NULL )
return - V_224 ;
V_4 = V_2 -> V_4 ;
V_353 = F_188 ( V_4 ) ;
if ( V_353 == - V_454 )
return V_353 ;
F_189 ( V_2 ) ;
V_453 = V_2 -> V_157 ;
if ( V_2 -> V_178 > V_261 ) {
F_2 ( L_57 ,
F_3 ( V_4 ) , V_2 -> V_178 ) ;
}
if ( V_2 -> V_41 & V_455 )
V_2 -> V_28 |= V_60 ;
else if ( ! ( V_2 -> V_439 & V_456 ) )
F_38 ( L_58 ) ;
else
V_2 -> V_28 |= V_60 ;
if ( ( V_2 -> V_41 & V_457 ) &&
( V_2 -> V_28 & V_60 ) ) {
F_38 ( L_59 ) ;
V_2 -> V_28 &= ~ V_60 ;
}
if ( ( V_2 -> V_178 >= V_179 ) &&
( V_2 -> V_439 & V_458 ) )
V_2 -> V_28 |= V_29 ;
if ( ( V_2 -> V_41 & V_459 ) &&
( V_2 -> V_28 & V_29 ) ) {
F_38 ( L_60 ) ;
V_2 -> V_28 &= ~ V_29 ;
}
if ( V_2 -> V_439 & V_460 )
V_2 -> V_28 |= V_30 ;
if ( V_2 -> V_28 & ( V_60 | V_29 ) ) {
V_353 = F_180 ( V_2 ) ;
if ( ! V_353 && V_2 -> V_57 -> V_61 )
V_353 = V_2 -> V_57 -> V_61 ( V_2 ) ;
if ( V_353 ) {
F_93 ( L_61 ,
F_3 ( V_4 ) ) ;
V_2 -> V_28 &= ~ ( V_60 | V_29 ) ;
V_353 = 0 ;
}
}
if ( V_2 -> V_28 & V_30 )
V_2 -> V_28 &= ~ V_60 ;
if ( V_2 -> V_28 & V_29 ) {
T_4 V_461 ;
void * V_101 ;
if ( V_2 -> V_28 & V_30 ) {
V_2 -> V_144 = ( V_462 * 2 + 1 ) *
V_463 ;
V_2 -> V_143 = V_463 ;
} else {
V_2 -> V_144 = ( V_462 * 2 + 1 ) *
V_464 ;
V_2 -> V_143 = V_464 ;
}
V_2 -> V_465 = V_462 * V_140 ;
V_101 = F_190 ( F_32 ( V_4 ) , V_2 -> V_465 +
V_2 -> V_144 , & V_461 , V_466 ) ;
if ( ! V_101 ) {
F_93 ( L_62 ,
F_3 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_29 ;
} else if ( ( V_461 + V_2 -> V_465 ) &
( V_467 - 1 ) ) {
F_93 ( L_63 ,
F_3 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_29 ;
F_191 ( F_32 ( V_4 ) , V_2 -> V_465 +
V_2 -> V_144 , V_101 , V_461 ) ;
} else {
V_2 -> V_139 = V_101 ;
V_2 -> V_135 = V_461 ;
V_2 -> V_138 = V_101 + V_2 -> V_465 ;
V_2 -> V_177 = V_461 + V_2 -> V_465 ;
}
}
if ( ! ( V_2 -> V_28 & ( V_60 | V_29 ) ) ) {
V_2 -> V_468 = F_182 ( 64 ) ;
F_32 ( V_4 ) -> V_468 = & V_2 -> V_468 ;
}
if ( V_2 -> V_178 >= V_261 )
V_2 -> V_268 = ( V_2 -> V_439 & V_469 )
>> V_470 ;
else
V_2 -> V_268 = ( V_2 -> V_439 & V_471 )
>> V_470 ;
V_2 -> V_268 *= 1000000 ;
if ( V_2 -> V_268 == 0 || V_2 -> V_41 &
V_472 ) {
if ( ! V_2 -> V_57 -> V_473 ) {
F_2 ( L_64 ,
F_3 ( V_4 ) ) ;
V_353 = - V_474 ;
goto V_475;
}
V_2 -> V_268 = V_2 -> V_57 -> V_473 ( V_2 ) ;
}
V_2 -> V_258 = ( V_2 -> V_440 & V_476 ) >>
V_477 ;
if ( V_2 -> V_258 )
V_2 -> V_258 += 1 ;
V_268 = V_2 -> V_268 ;
if ( V_2 -> V_57 -> V_478 )
V_4 -> V_479 = V_2 -> V_57 -> V_478 ( V_2 ) ;
else if ( V_2 -> V_178 >= V_261 ) {
if ( V_2 -> V_258 ) {
V_4 -> V_479 = ( V_2 -> V_268 * V_2 -> V_258 ) / 1024 ;
V_268 = V_2 -> V_268 * V_2 -> V_258 ;
} else
V_4 -> V_479 = V_2 -> V_268 / V_269 ;
} else
V_4 -> V_479 = V_2 -> V_268 / V_271 ;
if ( ! V_4 -> V_480 || V_4 -> V_480 > V_268 )
V_4 -> V_480 = V_268 ;
if ( ! ( V_2 -> V_41 & V_317 ) ) {
V_2 -> V_157 = ( V_2 -> V_439 & V_481 ) >>
V_482 ;
if ( V_2 -> V_157 == 0 ) {
if ( V_2 -> V_57 -> V_483 ) {
V_2 -> V_157 =
V_2 -> V_57 -> V_483 ( V_2 ) ;
} else {
F_2 ( L_65 ,
F_3 ( V_4 ) ) ;
V_353 = - V_474 ;
goto V_475;
}
}
if ( V_2 -> V_439 & V_484 )
V_2 -> V_157 *= 1000 ;
if ( V_453 )
V_2 -> V_157 = V_453 ;
V_4 -> V_318 = V_2 -> V_57 -> V_319 ?
V_2 -> V_57 -> V_319 ( V_2 ) : 1 << 27 ;
V_4 -> V_318 /= V_2 -> V_157 ;
}
V_4 -> V_439 |= V_485 | V_486 | V_487 ;
V_4 -> V_428 |= V_488 ;
if ( V_2 -> V_41 & V_489 )
V_2 -> V_28 |= V_191 ;
if ( ( V_2 -> V_178 >= V_261 ) &&
( ( V_2 -> V_28 & V_29 ) ||
! ( V_2 -> V_28 & V_60 ) ) &&
! ( V_2 -> V_53 & V_490 ) ) {
V_2 -> V_28 |= V_201 ;
F_38 ( L_66 , F_3 ( V_4 ) ) ;
} else {
F_38 ( L_67 , F_3 ( V_4 ) ) ;
}
if ( ! ( V_2 -> V_41 & V_491 ) )
V_4 -> V_439 |= V_492 ;
if ( V_2 -> V_53 & V_493 )
V_4 -> V_439 &= ~ V_487 ;
if ( V_2 -> V_439 & V_494 )
V_4 -> V_439 |= V_495 | V_496 ;
if ( ( V_2 -> V_41 & V_42 ) &&
F_10 ( V_4 ) &&
F_115 ( V_2 -> V_4 ) < 0 )
V_4 -> V_439 |= V_497 ;
if ( ! F_106 ( V_4 -> V_281 . V_358 ) ) {
V_353 = F_192 ( V_4 -> V_281 . V_358 ) ;
if ( ! F_193 ( V_4 -> V_281 . V_358 , 1700000 ,
1950000 ) )
V_2 -> V_440 &= ~ ( V_498 |
V_499 |
V_500 ) ;
if ( V_353 ) {
F_93 ( L_68 ,
F_3 ( V_4 ) , V_353 ) ;
V_4 -> V_281 . V_358 = F_179 ( - V_224 ) ;
}
}
if ( V_2 -> V_53 & V_501 ) {
V_2 -> V_440 &= ~ ( V_498 | V_499 |
V_500 ) ;
}
if ( V_2 -> V_440 & ( V_498 | V_499 |
V_500 ) )
V_4 -> V_439 |= V_502 | V_503 ;
if ( V_2 -> V_440 & V_498 ) {
V_4 -> V_439 |= V_504 | V_505 ;
if ( ! ( V_2 -> V_53 & V_506 ) )
V_4 -> V_428 |= V_507 ;
} else if ( V_2 -> V_440 & V_499 ) {
V_4 -> V_439 |= V_505 ;
}
if ( V_2 -> V_53 & V_508 &&
( V_2 -> V_440 & V_509 ) )
V_4 -> V_428 |= V_510 ;
if ( ( V_4 -> V_428 & V_511 ) &&
( F_106 ( V_4 -> V_281 . V_358 ) ||
! F_193 ( V_4 -> V_281 . V_358 , 1100000 ,
1300000 ) ) )
V_4 -> V_428 &= ~ V_511 ;
if ( ( V_2 -> V_440 & V_500 ) &&
! ( V_2 -> V_53 & V_512 ) )
V_4 -> V_439 |= V_513 ;
if ( V_2 -> V_440 & V_514 )
V_2 -> V_28 |= V_381 ;
if ( V_2 -> V_440 & V_515 )
V_4 -> V_439 |= V_516 ;
if ( V_2 -> V_440 & V_517 )
V_4 -> V_439 |= V_518 ;
if ( V_2 -> V_440 & V_519 )
V_4 -> V_439 |= V_520 ;
V_2 -> V_377 = ( V_2 -> V_440 & V_521 ) >>
V_522 ;
if ( V_2 -> V_377 )
V_2 -> V_377 = 1 << ( V_2 -> V_377 - 1 ) ;
V_2 -> V_76 = ( V_2 -> V_440 & V_523 ) >>
V_524 ;
V_452 = 0 ;
V_451 = F_4 ( V_2 , V_26 ) ;
if ( ! V_451 && ! F_106 ( V_4 -> V_281 . V_282 ) ) {
int V_525 = F_194 ( V_4 -> V_281 . V_282 ) ;
if ( V_525 > 0 ) {
V_525 = V_525 / 1000 ;
V_525 = V_525 / V_526 ;
V_525 = F_195 ( T_1 , V_525 , V_527 ) ;
V_451 =
( V_525 << V_528 ) |
( V_525 << V_529 ) |
( V_525 << V_530 ) ;
}
}
if ( V_2 -> V_439 & V_531 ) {
V_452 |= V_291 | V_292 ;
V_4 -> V_532 = ( ( V_451 &
V_533 ) >>
V_528 ) *
V_526 ;
}
if ( V_2 -> V_439 & V_534 ) {
V_452 |= V_288 | V_289 ;
V_4 -> V_535 = ( ( V_451 &
V_536 ) >>
V_529 ) *
V_526 ;
}
if ( V_2 -> V_439 & V_537 ) {
V_452 |= V_286 ;
V_4 -> V_538 = ( ( V_451 &
V_539 ) >>
V_530 ) *
V_526 ;
}
if ( V_2 -> V_540 )
V_452 = V_2 -> V_540 ;
if ( V_4 -> V_452 )
V_452 = V_4 -> V_452 ;
V_4 -> V_452 = V_452 ;
V_4 -> V_541 = V_452 ;
if ( V_2 -> V_541 )
V_4 -> V_541 &= V_2 -> V_541 ;
V_4 -> V_542 = V_452 ;
if ( V_2 -> V_542 )
V_4 -> V_542 &= V_2 -> V_542 ;
else
V_4 -> V_542 &= ~ V_286 ;
V_4 -> V_543 = V_452 ;
if ( V_2 -> V_543 )
V_4 -> V_543 &= V_2 -> V_543 ;
if ( V_4 -> V_452 == 0 ) {
F_2 ( L_69 ,
F_3 ( V_4 ) ) ;
V_353 = - V_474 ;
goto V_544;
}
if ( ( V_4 -> V_439 & ( V_502 | V_503 |
V_505 | V_504 |
V_513 | V_545 ) ) ||
( V_4 -> V_428 & ( V_546 | V_547 ) ) )
V_2 -> V_28 |= V_361 ;
if ( V_4 -> V_428 & V_511 )
V_2 -> V_28 |= V_364 ;
F_196 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_28 & V_29 )
V_4 -> V_548 = V_462 ;
else if ( V_2 -> V_28 & V_60 )
V_4 -> V_548 = 1 ;
else
V_4 -> V_548 = V_462 ;
V_4 -> V_549 = 524288 ;
if ( V_2 -> V_28 & V_29 ) {
if ( V_2 -> V_41 & V_550 )
V_4 -> V_551 = 65535 ;
else
V_4 -> V_551 = 65536 ;
} else {
V_4 -> V_551 = V_4 -> V_549 ;
}
if ( V_2 -> V_41 & V_552 ) {
V_4 -> V_167 = 2 ;
} else {
V_4 -> V_167 = ( V_2 -> V_439 & V_553 ) >>
V_554 ;
if ( V_4 -> V_167 >= 3 ) {
F_93 ( L_70 ,
F_3 ( V_4 ) ) ;
V_4 -> V_167 = 0 ;
}
}
V_4 -> V_167 = 512 << V_4 -> V_167 ;
V_4 -> V_555 = ( V_2 -> V_41 & V_556 ) ? 1 : 65535 ;
return 0 ;
V_544:
if ( ! F_106 ( V_4 -> V_281 . V_358 ) )
F_197 ( V_4 -> V_281 . V_358 ) ;
V_475:
if ( V_2 -> V_139 )
F_191 ( F_32 ( V_4 ) , V_2 -> V_465 +
V_2 -> V_144 , V_2 -> V_139 ,
V_2 -> V_135 ) ;
V_2 -> V_138 = NULL ;
V_2 -> V_139 = NULL ;
return V_353 ;
}
int F_198 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
int V_353 ;
F_199 ( & V_2 -> V_211 ,
F_146 , ( unsigned long ) V_2 ) ;
F_200 ( & V_2 -> V_215 , F_147 , ( unsigned long ) V_2 ) ;
F_200 ( & V_2 -> V_214 , F_148 ,
( unsigned long ) V_2 ) ;
F_201 ( & V_2 -> V_374 ) ;
F_22 ( V_2 , 0 ) ;
V_353 = F_172 ( V_2 -> V_405 , F_156 , F_161 ,
V_425 , F_3 ( V_4 ) , V_2 ) ;
if ( V_353 ) {
F_2 ( L_71 ,
F_3 ( V_4 ) , V_2 -> V_405 , V_353 ) ;
goto V_557;
}
#ifdef F_202
F_1 ( V_2 ) ;
#endif
V_353 = F_30 ( V_2 ) ;
if ( V_353 ) {
F_2 ( L_72 ,
F_3 ( V_4 ) , V_353 ) ;
goto V_558;
}
F_109 () ;
V_353 = F_203 ( V_4 ) ;
if ( V_353 )
goto V_559;
F_135 ( L_73 ,
F_3 ( V_4 ) , V_2 -> V_560 , F_204 ( F_32 ( V_4 ) ) ,
( V_2 -> V_28 & V_29 ) ?
( V_2 -> V_28 & V_30 ) ? L_74 : L_75 :
( V_2 -> V_28 & V_60 ) ? L_76 : L_77 ) ;
F_12 ( V_2 ) ;
return 0 ;
V_559:
F_33 ( V_2 ) ;
V_558:
F_21 ( V_2 , V_52 ) ;
F_11 ( V_2 , 0 , V_19 ) ;
F_11 ( V_2 , 0 , V_20 ) ;
F_169 ( V_2 -> V_405 , V_2 ) ;
V_557:
F_205 ( & V_2 -> V_211 ) ;
if ( ! F_106 ( V_4 -> V_281 . V_358 ) )
F_197 ( V_4 -> V_281 . V_358 ) ;
if ( V_2 -> V_139 )
F_191 ( F_32 ( V_4 ) , V_2 -> V_465 +
V_2 -> V_144 , V_2 -> V_139 ,
V_2 -> V_135 ) ;
V_2 -> V_138 = NULL ;
V_2 -> V_139 = NULL ;
return V_353 ;
}
int F_206 ( struct V_1 * V_2 )
{
int V_353 ;
V_353 = F_187 ( V_2 ) ;
if ( V_353 )
return V_353 ;
return F_198 ( V_2 ) ;
}
void F_207 ( struct V_1 * V_2 , int V_561 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
unsigned long V_28 ;
if ( V_561 ) {
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_28 |= V_206 ;
if ( F_141 ( V_2 ) ) {
F_2 ( L_78
L_79 , F_3 ( V_4 ) ) ;
F_142 ( V_2 , - V_297 ) ;
}
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
F_13 ( V_2 ) ;
F_208 ( V_4 ) ;
F_33 ( V_2 ) ;
if ( ! V_561 )
F_21 ( V_2 , V_52 ) ;
F_11 ( V_2 , 0 , V_19 ) ;
F_11 ( V_2 , 0 , V_20 ) ;
F_169 ( V_2 -> V_405 , V_2 ) ;
F_209 ( & V_2 -> V_215 ) ;
F_209 ( & V_2 -> V_214 ) ;
F_205 ( & V_2 -> V_211 ) ;
if ( ! F_106 ( V_4 -> V_281 . V_358 ) )
F_197 ( V_4 -> V_281 . V_358 ) ;
if ( V_2 -> V_139 )
F_191 ( F_32 ( V_4 ) , V_2 -> V_465 +
V_2 -> V_144 , V_2 -> V_139 ,
V_2 -> V_135 ) ;
V_2 -> V_138 = NULL ;
V_2 -> V_139 = NULL ;
}
void F_210 ( struct V_1 * V_2 )
{
F_211 ( V_2 -> V_4 ) ;
}
static int T_7 F_212 ( void )
{
F_135 ( V_3
L_80 ) ;
F_135 ( V_3 L_81 ) ;
return 0 ;
}
static void T_8 F_213 ( void )
{
}
