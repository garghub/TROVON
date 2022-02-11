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
void F_96 ( struct V_1 * V_2 , unsigned int clock )
{
T_5 V_259 ;
unsigned long V_50 ;
V_2 -> V_4 -> V_256 = 0 ;
F_74 ( V_2 , 0 , V_16 ) ;
if ( clock == 0 )
return;
V_259 = F_94 ( V_2 , clock , & V_2 -> V_4 -> V_256 ) ;
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
F_20 ( 1 ) ;
}
V_259 |= V_279 ;
F_74 ( V_2 , V_259 , V_16 ) ;
}
static void F_97 ( struct V_1 * V_2 , unsigned char V_193 ,
unsigned short V_280 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
F_98 ( & V_2 -> V_88 ) ;
F_99 ( V_4 , V_4 -> V_281 . V_282 , V_280 ) ;
F_100 ( & V_2 -> V_88 ) ;
if ( V_193 != V_283 )
F_19 ( V_2 , V_284 , V_13 ) ;
else
F_19 ( V_2 , 0 , V_13 ) ;
}
void F_101 ( struct V_1 * V_2 , unsigned char V_193 ,
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
F_102 ( 1 , L_30 ,
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
void F_103 ( struct V_1 * V_2 , unsigned char V_193 ,
unsigned short V_280 )
{
if ( F_104 ( V_2 -> V_4 -> V_281 . V_282 ) )
F_101 ( V_2 , V_193 , V_280 ) ;
else
F_97 ( V_2 , V_193 , V_280 ) ;
}
static void F_105 ( struct V_56 * V_4 , struct V_188 * V_189 )
{
struct V_1 * V_2 ;
int V_40 ;
unsigned long V_28 ;
V_2 = F_106 ( V_4 ) ;
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
F_107 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
void F_108 ( struct V_1 * V_2 , int V_298 )
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
void F_109 ( struct V_1 * V_2 , unsigned V_241 )
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
static void F_110 ( struct V_56 * V_4 , struct V_311 * V_81 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
unsigned long V_28 ;
T_2 V_82 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_28 & V_206 ) {
F_29 ( & V_2 -> V_88 , V_28 ) ;
if ( ! F_104 ( V_4 -> V_281 . V_282 ) &&
V_81 -> V_312 == V_283 )
F_99 ( V_4 , V_4 -> V_281 . V_282 , 0 ) ;
return;
}
if ( V_81 -> V_312 == V_283 ) {
F_11 ( V_2 , 0 , V_20 ) ;
F_23 ( V_2 ) ;
}
if ( V_2 -> V_178 >= V_261 &&
( V_81 -> V_312 == V_313 ) &&
! ( V_2 -> V_53 & V_314 ) )
F_111 ( V_2 , false ) ;
if ( ! V_81 -> clock || V_81 -> clock != V_2 -> clock ) {
V_2 -> V_57 -> V_315 ( V_2 , V_81 -> clock ) ;
V_2 -> clock = V_81 -> clock ;
if ( V_2 -> V_41 & V_316 &&
V_2 -> clock ) {
V_2 -> V_157 = V_2 -> V_4 -> V_256 ?
V_2 -> V_4 -> V_256 / 1000 :
V_2 -> clock / 1000 ;
V_2 -> V_4 -> V_317 =
V_2 -> V_57 -> V_318 ?
V_2 -> V_57 -> V_318 ( V_2 ) :
1 << 27 ;
V_2 -> V_4 -> V_317 /= V_2 -> V_157 ;
}
}
if ( V_2 -> V_57 -> V_319 )
V_2 -> V_57 -> V_319 ( V_2 , V_81 -> V_312 , V_81 -> V_280 ) ;
else
F_103 ( V_2 , V_81 -> V_312 , V_81 -> V_280 ) ;
if ( V_2 -> V_57 -> V_320 )
V_2 -> V_57 -> V_320 ( V_2 , V_81 -> V_312 ) ;
V_2 -> V_57 -> V_321 ( V_2 , V_81 -> V_322 ) ;
V_82 = F_6 ( V_2 , V_12 ) ;
if ( ( V_81 -> V_241 == V_323 ||
V_81 -> V_241 == V_324 )
&& ! ( V_2 -> V_41 & V_325 ) )
V_82 |= V_326 ;
else
V_82 &= ~ V_326 ;
if ( V_2 -> V_178 >= V_261 ) {
T_5 V_259 , V_303 ;
if ( ( V_81 -> V_241 == V_254 ) ||
( V_81 -> V_241 == V_249 ) ||
( V_81 -> V_241 == V_252 ) ||
( V_81 -> V_241 == V_246 ) ||
( V_81 -> V_241 == V_248 ) ||
( V_81 -> V_241 == V_251 ) ||
( V_81 -> V_241 == V_244 ) )
V_82 |= V_326 ;
if ( ! V_2 -> V_62 ) {
F_19 ( V_2 , V_82 , V_12 ) ;
V_303 = F_5 ( V_2 , V_27 ) ;
V_303 &= ~ V_327 ;
if ( V_81 -> V_328 == V_329 )
V_303 |= V_330 ;
else if ( V_81 -> V_328 == V_331 )
V_303 |= V_332 ;
else if ( V_81 -> V_328 == V_333 )
V_303 |= V_334 ;
else if ( V_81 -> V_328 == V_335 )
V_303 |= V_336 ;
else {
F_93 ( L_31 ,
F_3 ( V_4 ) ) ;
V_303 |= V_332 ;
}
F_74 ( V_2 , V_303 , V_27 ) ;
} else {
V_259 = F_5 ( V_2 , V_16 ) ;
V_259 &= ~ V_279 ;
F_74 ( V_2 , V_259 , V_16 ) ;
F_19 ( V_2 , V_82 , V_12 ) ;
V_2 -> V_57 -> V_315 ( V_2 , V_2 -> clock ) ;
}
V_259 = F_5 ( V_2 , V_16 ) ;
V_259 &= ~ V_279 ;
F_74 ( V_2 , V_259 , V_16 ) ;
V_2 -> V_57 -> V_337 ( V_2 , V_81 -> V_241 ) ;
V_2 -> V_241 = V_81 -> V_241 ;
if ( ! ( V_2 -> V_53 & V_314 ) &&
( ( V_81 -> V_241 == V_242 ) ||
( V_81 -> V_241 == V_244 ) ||
( V_81 -> V_241 == V_246 ) ||
( V_81 -> V_241 == V_248 ) ||
( V_81 -> V_241 == V_251 ) ||
( V_81 -> V_241 == V_252 ) ) ) {
T_5 V_240 ;
F_111 ( V_2 , true ) ;
V_240 = F_92 ( V_2 ) ;
V_81 -> V_328 = ( V_240 & V_338 )
>> V_339 ;
}
V_2 -> V_57 -> V_315 ( V_2 , V_2 -> clock ) ;
} else
F_19 ( V_2 , V_82 , V_12 ) ;
if ( V_2 -> V_41 & V_340 )
F_21 ( V_2 , V_64 | V_65 ) ;
F_107 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static int F_112 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
int V_341 = F_113 ( V_4 ) ;
if ( V_2 -> V_28 & V_206 )
return 0 ;
if ( ! F_10 ( V_2 -> V_4 ) )
return 1 ;
if ( V_341 >= 0 )
return ! ! V_341 ;
if ( V_2 -> V_41 & V_42 )
return 1 ;
return ! ! ( F_4 ( V_2 , V_11 ) & V_43 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
int V_342 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_28 & V_206 )
V_342 = 0 ;
else if ( V_2 -> V_57 -> V_343 )
V_342 = V_2 -> V_57 -> V_343 ( V_2 ) ;
else
V_342 = ! ( F_4 ( V_2 , V_11 )
& V_344 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return V_2 -> V_41 & V_345 ?
! V_342 : V_342 ;
}
static int F_115 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
int V_137 , V_346 ;
if ( ! ( V_2 -> V_41 & V_347 ) )
return F_114 ( V_2 ) ;
V_346 = 0 ;
for ( V_137 = 0 ; V_137 < V_348 ; V_137 ++ ) {
if ( F_114 ( V_2 ) ) {
if ( ++ V_346 > V_348 / 2 )
return 1 ;
}
F_116 ( 30 ) ;
}
return 0 ;
}
static void F_117 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
if ( V_2 -> V_57 && V_2 -> V_57 -> V_349 )
V_2 -> V_57 -> V_349 ( V_2 ) ;
}
static void F_118 ( struct V_1 * V_2 , int V_39 )
{
if ( ! ( V_2 -> V_28 & V_206 ) ) {
if ( V_39 )
V_2 -> V_44 |= V_350 ;
else
V_2 -> V_44 &= ~ V_350 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
F_107 () ;
}
}
static void F_119 ( struct V_56 * V_4 , int V_39 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
unsigned long V_28 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_39 )
V_2 -> V_28 |= V_351 ;
else
V_2 -> V_28 &= ~ V_351 ;
F_118 ( V_2 , V_39 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static int F_120 ( struct V_56 * V_4 ,
struct V_311 * V_81 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
T_5 V_82 ;
int V_352 ;
if ( V_2 -> V_178 < V_261 )
return 0 ;
V_82 = F_5 ( V_2 , V_27 ) ;
switch ( V_81 -> V_353 ) {
case V_354 :
if ( ! ( V_2 -> V_28 & V_355 ) )
return - V_224 ;
V_82 &= ~ V_356 ;
F_74 ( V_2 , V_82 , V_27 ) ;
if ( ! F_104 ( V_4 -> V_281 . V_357 ) ) {
V_352 = F_121 ( V_4 , V_81 ) ;
if ( V_352 ) {
F_93 ( L_32 ,
F_3 ( V_4 ) ) ;
return - V_220 ;
}
}
F_122 ( 5000 , 5500 ) ;
V_82 = F_5 ( V_2 , V_27 ) ;
if ( ! ( V_82 & V_356 ) )
return 0 ;
F_93 ( L_33 ,
F_3 ( V_4 ) ) ;
return - V_358 ;
case V_359 :
if ( ! ( V_2 -> V_28 & V_360 ) )
return - V_224 ;
if ( ! F_104 ( V_4 -> V_281 . V_357 ) ) {
V_352 = F_121 ( V_4 , V_81 ) ;
if ( V_352 ) {
F_93 ( L_34 ,
F_3 ( V_4 ) ) ;
return - V_220 ;
}
}
V_82 |= V_356 ;
F_74 ( V_2 , V_82 , V_27 ) ;
if ( V_2 -> V_57 -> V_361 )
V_2 -> V_57 -> V_361 ( V_2 ) ;
V_82 = F_5 ( V_2 , V_27 ) ;
if ( V_82 & V_356 )
return 0 ;
F_93 ( L_35 ,
F_3 ( V_4 ) ) ;
return - V_358 ;
case V_362 :
if ( ! ( V_2 -> V_28 & V_363 ) )
return - V_224 ;
if ( ! F_104 ( V_4 -> V_281 . V_357 ) ) {
V_352 = F_121 ( V_4 , V_81 ) ;
if ( V_352 ) {
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
static int F_123 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
T_1 V_364 ;
V_364 = F_4 ( V_2 , V_11 ) ;
return ! ( V_364 & V_365 ) ;
}
static int F_124 ( struct V_56 * V_4 , struct V_311 * V_81 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
unsigned long V_28 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_28 |= V_366 ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return 0 ;
}
static int F_125 ( struct V_56 * V_4 , T_1 V_158 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
T_5 V_82 ;
int V_367 = V_368 ;
int V_369 = 0 ;
unsigned long V_28 ;
unsigned int V_370 = 0 ;
bool V_371 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_371 = V_2 -> V_28 & V_366 ;
V_2 -> V_28 &= ~ V_366 ;
if ( V_2 -> V_76 == V_372 )
V_370 = V_2 -> V_370 ;
switch ( V_2 -> V_241 ) {
case V_254 :
V_369 = - V_224 ;
goto V_373;
case V_249 :
if ( V_371 )
V_370 = 0 ;
break;
case V_248 :
case V_251 :
break;
case V_246 :
if ( V_2 -> V_28 & V_374 )
break;
default:
goto V_373;
}
if ( V_2 -> V_57 -> V_375 ) {
F_29 ( & V_2 -> V_88 , V_28 ) ;
V_369 = V_2 -> V_57 -> V_375 ( V_2 , V_158 ) ;
return V_369 ;
}
V_82 = F_5 ( V_2 , V_27 ) ;
V_82 |= V_376 ;
if ( V_2 -> V_53 & V_377 )
V_82 |= V_378 ;
F_74 ( V_2 , V_82 , V_27 ) ;
F_11 ( V_2 , V_160 , V_19 ) ;
F_11 ( V_2 , V_160 , V_20 ) ;
do {
struct V_35 V_36 = { 0 } ;
struct V_188 V_189 = { NULL } ;
V_36 . V_158 = V_158 ;
V_36 . V_202 = 0 ;
V_36 . V_28 = V_379 | V_380 ;
V_36 . V_381 = 0 ;
V_36 . V_37 = NULL ;
V_36 . V_189 = & V_189 ;
V_36 . error = 0 ;
if ( V_367 -- == 0 )
break;
V_189 . V_36 = & V_36 ;
if ( V_36 . V_158 == V_235 ) {
if ( V_4 -> V_81 . V_322 == V_299 )
F_74 ( V_2 , F_75 ( 7 , 128 ) ,
V_7 ) ;
else if ( V_4 -> V_81 . V_322 == V_302 )
F_74 ( V_2 , F_75 ( 7 , 64 ) ,
V_7 ) ;
} else {
F_74 ( V_2 , F_75 ( 7 , 64 ) ,
V_7 ) ;
}
F_74 ( V_2 , V_204 , V_10 ) ;
F_84 ( V_2 , & V_36 ) ;
V_2 -> V_36 = NULL ;
F_87 ( V_2 , & V_189 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
F_126 ( V_2 -> V_382 ,
( V_2 -> V_383 == 1 ) ,
F_127 ( 50 ) ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( ! V_2 -> V_383 ) {
F_128 ( V_3 L_37 ) ;
F_21 ( V_2 , V_64 ) ;
F_21 ( V_2 , V_65 ) ;
V_82 = F_5 ( V_2 , V_27 ) ;
V_82 &= ~ V_378 ;
V_82 &= ~ V_376 ;
F_74 ( V_2 , V_82 , V_27 ) ;
V_369 = - V_220 ;
goto V_90;
}
V_2 -> V_383 = 0 ;
V_82 = F_5 ( V_2 , V_27 ) ;
if ( V_158 == V_234 )
F_20 ( 1 ) ;
} while ( V_82 & V_376 );
if ( V_367 < 0 ) {
V_82 &= ~ V_378 ;
F_74 ( V_2 , V_82 , V_27 ) ;
}
if ( ! ( V_82 & V_378 ) ) {
F_128 ( V_3 L_38 ) ;
V_369 = - V_220 ;
}
V_90:
if ( V_370 ) {
V_369 = 0 ;
}
V_2 -> V_4 -> V_384 = V_369 ? 0 : V_370 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
V_373:
F_29 ( & V_2 -> V_88 , V_28 ) ;
return V_369 ;
}
static int F_129 ( struct V_385 * V_386 ,
unsigned int V_387 , int V_388 ,
int V_389 , int * V_328 )
{
struct V_1 * V_2 = F_106 ( V_386 -> V_2 ) ;
if ( ! V_2 -> V_57 -> V_390 )
return 0 ;
return V_2 -> V_57 -> V_390 ( V_2 , V_386 , V_387 , V_388 ,
V_389 , V_328 ) ;
}
static void F_111 ( struct V_1 * V_2 , bool V_39 )
{
if ( V_2 -> V_178 < V_261 )
return;
if ( V_2 -> V_62 != V_39 ) {
T_5 V_82 = F_5 ( V_2 , V_27 ) ;
if ( V_39 )
V_82 |= V_391 ;
else
V_82 &= ~ V_391 ;
F_74 ( V_2 , V_82 , V_27 ) ;
if ( V_39 )
V_2 -> V_28 |= V_392 ;
else
V_2 -> V_28 &= ~ V_392 ;
V_2 -> V_62 = V_39 ;
}
}
static void F_130 ( struct V_56 * V_4 , struct V_188 * V_189 ,
int V_369 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
struct V_114 * V_37 = V_189 -> V_37 ;
if ( V_37 -> V_117 != V_393 )
F_131 ( F_32 ( V_2 -> V_4 ) , V_37 -> V_119 , V_37 -> V_120 ,
V_37 -> V_28 & V_121 ?
V_122 : V_123 ) ;
V_37 -> V_117 = V_393 ;
}
static void F_132 ( struct V_56 * V_4 , struct V_188 * V_189 ,
bool V_394 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
V_189 -> V_37 -> V_117 = V_393 ;
if ( V_2 -> V_28 & V_165 )
F_48 ( V_2 , V_189 -> V_37 , V_118 ) ;
}
static inline bool F_133 ( struct V_1 * V_2 )
{
return V_2 -> V_36 || V_2 -> V_212 ;
}
static void F_134 ( struct V_1 * V_2 , int V_369 )
{
if ( V_2 -> V_212 ) {
V_2 -> V_212 -> error = V_369 ;
F_82 ( V_2 , V_2 -> V_212 -> V_189 ) ;
}
if ( V_2 -> V_36 ) {
V_2 -> V_36 -> error = V_369 ;
F_82 ( V_2 , V_2 -> V_36 -> V_189 ) ;
}
}
static void F_135 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_106 ( V_4 ) ;
unsigned long V_28 ;
int V_40 ;
if ( V_2 -> V_57 -> V_395 )
V_2 -> V_57 -> V_395 ( V_2 ) ;
V_40 = V_4 -> V_57 -> V_58 ( V_4 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( F_133 ( V_2 ) && ! V_40 ) {
F_2 ( L_39 ,
F_3 ( V_2 -> V_4 ) ) ;
F_2 ( L_40 ,
F_3 ( V_2 -> V_4 ) ) ;
F_21 ( V_2 , V_64 ) ;
F_21 ( V_2 , V_65 ) ;
F_134 ( V_2 , - V_297 ) ;
}
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static bool F_136 ( struct V_1 * V_2 )
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
F_131 ( F_32 ( V_2 -> V_4 ) , V_37 -> V_119 , V_37 -> V_120 ,
( V_37 -> V_28 & V_109 ) ?
V_123 : V_122 ) ;
V_37 -> V_117 = V_393 ;
}
}
if ( F_79 ( V_2 , V_189 ) ) {
if ( V_2 -> V_36 || V_2 -> V_212 ) {
F_29 ( & V_2 -> V_88 , V_28 ) ;
return true ;
}
if ( V_2 -> V_41 & V_396 )
V_2 -> V_57 -> V_315 ( V_2 , V_2 -> clock ) ;
F_21 ( V_2 , V_64 ) ;
F_21 ( V_2 , V_65 ) ;
V_2 -> V_213 = false ;
}
if ( ! F_133 ( V_2 ) )
F_36 ( V_2 ) ;
V_2 -> V_210 [ V_137 ] = NULL ;
F_107 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
F_137 ( V_2 -> V_4 , V_189 ) ;
return false ;
}
static void F_138 ( unsigned long V_397 )
{
struct V_1 * V_2 = (struct V_1 * ) V_397 ;
while ( ! F_136 ( V_2 ) )
;
}
static void F_139 ( unsigned long V_37 )
{
struct V_1 * V_2 ;
unsigned long V_28 ;
V_2 = (struct V_1 * ) V_37 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_36 && ! F_8 ( V_2 -> V_36 ) ) {
F_2 ( L_41 ,
F_3 ( V_2 -> V_4 ) ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 -> error = - V_398 ;
F_82 ( V_2 , V_2 -> V_36 -> V_189 ) ;
}
F_107 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static void F_140 ( unsigned long V_37 )
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
V_2 -> V_37 -> error = - V_398 ;
F_83 ( V_2 ) ;
} else if ( V_2 -> V_212 ) {
V_2 -> V_212 -> error = - V_398 ;
F_82 ( V_2 , V_2 -> V_212 -> V_189 ) ;
} else {
V_2 -> V_36 -> error = - V_398 ;
F_82 ( V_2 , V_2 -> V_36 -> V_189 ) ;
}
}
F_107 () ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
static void F_141 ( struct V_1 * V_2 , T_1 V_399 )
{
if ( ! V_2 -> V_36 ) {
if ( V_2 -> V_213 )
return;
F_2 ( L_43 ,
F_3 ( V_2 -> V_4 ) , ( unsigned ) V_399 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_399 & ( V_73 | V_72 |
V_71 | V_70 ) ) {
if ( V_399 & V_73 )
V_2 -> V_36 -> error = - V_398 ;
else
V_2 -> V_36 -> error = - V_400 ;
if ( V_2 -> V_36 -> V_37 &&
( V_399 & ( V_72 | V_73 ) ) ==
V_72 ) {
V_2 -> V_36 = NULL ;
return;
}
F_82 ( V_2 , V_2 -> V_36 -> V_189 ) ;
return;
}
if ( V_399 & V_75 )
F_90 ( V_2 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
const char * V_93 = F_3 ( V_2 -> V_4 ) ;
void * V_128 = V_2 -> V_138 ;
F_1 ( V_2 ) ;
while ( true ) {
struct V_129 * V_130 = V_128 ;
if ( V_2 -> V_28 & V_30 )
F_38 ( L_44 ,
V_93 , V_128 , F_143 ( V_130 -> V_132 ) ,
F_143 ( V_130 -> V_131 ) ,
F_144 ( V_130 -> V_97 ) ,
F_144 ( V_130 -> V_36 ) ) ;
else
F_38 ( L_45 ,
V_93 , V_128 , F_143 ( V_130 -> V_131 ) ,
F_144 ( V_130 -> V_97 ) ,
F_144 ( V_130 -> V_36 ) ) ;
V_128 += V_2 -> V_143 ;
if ( V_130 -> V_36 & F_56 ( V_134 ) )
break;
}
}
static void F_142 ( struct V_1 * V_2 ) { }
static void F_145 ( struct V_1 * V_2 , T_1 V_399 )
{
T_1 V_401 ;
if ( V_399 & V_160 ) {
V_401 = F_146 ( F_5 ( V_2 , V_25 ) ) ;
if ( V_401 == V_234 ||
V_401 == V_235 ) {
V_2 -> V_383 = 1 ;
F_147 ( & V_2 -> V_382 ) ;
return;
}
}
if ( ! V_2 -> V_37 ) {
struct V_35 * V_212 = V_2 -> V_212 ;
if ( V_212 && ( V_212 -> V_28 & V_38 ) ) {
if ( V_399 & V_69 ) {
V_2 -> V_212 = NULL ;
V_212 -> error = - V_398 ;
F_82 ( V_2 , V_212 -> V_189 ) ;
return;
}
if ( V_399 & V_74 ) {
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
F_3 ( V_2 -> V_4 ) , ( unsigned ) V_399 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_399 & V_69 )
V_2 -> V_37 -> error = - V_398 ;
else if ( V_399 & V_67 )
V_2 -> V_37 -> error = - V_400 ;
else if ( ( V_399 & V_68 ) &&
F_146 ( F_5 ( V_2 , V_25 ) )
!= V_402 )
V_2 -> V_37 -> error = - V_400 ;
else if ( V_399 & V_164 ) {
F_2 ( L_47 , F_3 ( V_2 -> V_4 ) ) ;
F_142 ( V_2 ) ;
V_2 -> V_37 -> error = - V_220 ;
if ( V_2 -> V_57 -> V_403 )
V_2 -> V_57 -> V_403 ( V_2 , V_399 ) ;
}
if ( V_2 -> V_37 -> error )
F_83 ( V_2 ) ;
else {
if ( V_399 & ( V_160 | V_161 ) )
F_46 ( V_2 ) ;
if ( V_399 & V_163 ) {
T_1 V_404 , V_405 ;
V_404 = F_61 ( V_2 -> V_37 -> V_119 ) ;
V_405 = V_404 + V_2 -> V_37 -> V_169 ;
V_405 = ( V_405 &
~ ( V_406 - 1 ) ) +
V_406 ;
V_2 -> V_37 -> V_169 = V_405 - V_404 ;
F_38 ( L_48
L_49 ,
F_3 ( V_2 -> V_4 ) , V_404 ,
V_2 -> V_37 -> V_169 , V_405 ) ;
F_11 ( V_2 , V_405 , V_5 ) ;
}
if ( V_399 & V_74 ) {
if ( V_2 -> V_36 == V_2 -> V_212 ) {
V_2 -> V_168 = 1 ;
} else {
F_83 ( V_2 ) ;
}
}
}
}
static T_6 F_148 ( int V_407 , void * V_408 )
{
T_6 V_409 = V_410 ;
struct V_1 * V_2 = V_408 ;
T_1 V_399 , V_49 , V_411 = 0 ;
int V_412 = 16 ;
F_149 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_89 && ! F_150 ( V_2 ) ) {
F_151 ( & V_2 -> V_88 ) ;
return V_410 ;
}
V_399 = F_4 ( V_2 , V_18 ) ;
if ( ! V_399 || V_399 == 0xffffffff ) {
V_409 = V_410 ;
goto V_90;
}
do {
V_49 = V_399 & ( V_413 | V_414 |
V_66 ) ;
F_11 ( V_2 , V_49 , V_18 ) ;
F_38 ( L_50 ,
F_3 ( V_2 -> V_4 ) , V_399 ) ;
if ( V_399 & ( V_46 | V_45 ) ) {
T_1 V_40 = F_4 ( V_2 , V_11 ) &
V_43 ;
V_2 -> V_44 &= ~ ( V_46 |
V_45 ) ;
V_2 -> V_44 |= V_40 ? V_45 :
V_46 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
F_11 ( V_2 , V_399 & ( V_46 |
V_45 ) , V_18 ) ;
V_2 -> V_415 |= V_399 & ( V_46 |
V_45 ) ;
V_409 = V_416 ;
}
if ( V_399 & V_413 )
F_141 ( V_2 , V_399 & V_413 ) ;
if ( V_399 & V_414 )
F_145 ( V_2 , V_399 & V_414 ) ;
if ( V_399 & V_66 )
F_2 ( L_51 ,
F_3 ( V_2 -> V_4 ) ) ;
if ( V_399 & V_79 )
F_152 ( V_2 -> V_4 ) ;
if ( V_399 & V_350 ) {
F_118 ( V_2 , false ) ;
V_2 -> V_415 |= V_350 ;
V_409 = V_416 ;
}
V_399 &= ~ ( V_46 | V_45 |
V_413 | V_414 |
V_417 | V_66 |
V_79 | V_350 ) ;
if ( V_399 ) {
V_411 |= V_399 ;
F_11 ( V_2 , V_399 , V_18 ) ;
}
if ( V_409 == V_410 )
V_409 = V_418 ;
V_399 = F_4 ( V_2 , V_18 ) ;
} while ( V_399 && -- V_412 );
V_90:
F_151 ( & V_2 -> V_88 ) ;
if ( V_411 ) {
F_2 ( L_52 ,
F_3 ( V_2 -> V_4 ) , V_411 ) ;
F_1 ( V_2 ) ;
}
return V_409 ;
}
static T_6 F_153 ( int V_407 , void * V_408 )
{
struct V_1 * V_2 = V_408 ;
unsigned long V_28 ;
T_1 V_419 ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_419 = V_2 -> V_415 ;
V_2 -> V_415 = 0 ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
if ( V_419 & ( V_46 | V_45 ) ) {
struct V_56 * V_4 = V_2 -> V_4 ;
V_4 -> V_57 -> V_395 ( V_4 ) ;
F_154 ( V_4 , F_127 ( 200 ) ) ;
}
if ( V_419 & V_350 ) {
F_155 ( V_2 -> V_4 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
if ( V_2 -> V_28 & V_351 )
F_118 ( V_2 , true ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
return V_419 ? V_418 : V_410 ;
}
void F_156 ( struct V_1 * V_2 )
{
T_2 V_156 ;
T_2 V_49 = V_420 | V_421
| V_422 ;
T_1 V_423 = V_46 | V_45 |
V_350 ;
V_156 = F_6 ( V_2 , V_15 ) ;
V_156 |= V_49 ;
if ( V_2 -> V_41 & V_42 ) {
V_156 &= ~ ( V_420 | V_421 ) ;
V_423 &= ~ ( V_46 | V_45 ) ;
}
F_19 ( V_2 , V_156 , V_15 ) ;
F_11 ( V_2 , V_423 , V_19 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
T_2 V_156 ;
T_2 V_49 = V_420 | V_421
| V_422 ;
V_156 = F_6 ( V_2 , V_15 ) ;
V_156 &= ~ V_49 ;
F_19 ( V_2 , V_156 , V_15 ) ;
}
int F_158 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_159 ( V_2 -> V_4 ) ;
if ( V_2 -> V_76 != V_78 )
F_152 ( V_2 -> V_4 ) ;
if ( ! F_160 ( F_32 ( V_2 -> V_4 ) ) ) {
V_2 -> V_44 = 0 ;
F_11 ( V_2 , 0 , V_19 ) ;
F_11 ( V_2 , 0 , V_20 ) ;
F_161 ( V_2 -> V_407 , V_2 ) ;
} else {
F_156 ( V_2 ) ;
F_162 ( V_2 -> V_407 ) ;
}
return 0 ;
}
int F_163 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
int V_352 = 0 ;
if ( V_2 -> V_28 & ( V_60 | V_29 ) ) {
if ( V_2 -> V_57 -> V_61 )
V_2 -> V_57 -> V_61 ( V_2 ) ;
}
if ( ( V_2 -> V_4 -> V_424 & V_425 ) &&
( V_2 -> V_53 & V_426 ) ) {
F_22 ( V_2 , 0 ) ;
V_2 -> V_285 = 0 ;
V_2 -> clock = 0 ;
V_4 -> V_57 -> V_80 ( V_4 , & V_4 -> V_81 ) ;
} else {
F_22 ( V_2 , ( V_2 -> V_4 -> V_424 & V_425 ) ) ;
F_107 () ;
}
if ( ! F_160 ( F_32 ( V_2 -> V_4 ) ) ) {
V_352 = F_164 ( V_2 -> V_407 , F_148 ,
F_153 , V_427 ,
F_3 ( V_2 -> V_4 ) , V_2 ) ;
if ( V_352 )
return V_352 ;
} else {
F_157 ( V_2 ) ;
F_165 ( V_2 -> V_407 ) ;
}
F_12 ( V_2 ) ;
return V_352 ;
}
int F_166 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_159 ( V_2 -> V_4 ) ;
if ( V_2 -> V_76 != V_78 )
F_152 ( V_2 -> V_4 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_44 &= V_350 ;
F_11 ( V_2 , V_2 -> V_44 , V_19 ) ;
F_11 ( V_2 , V_2 -> V_44 , V_20 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
F_167 ( V_2 -> V_407 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_89 = true ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return 0 ;
}
int F_168 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
unsigned long V_28 ;
int V_428 = V_2 -> V_28 ;
if ( V_428 & ( V_60 | V_29 ) ) {
if ( V_2 -> V_57 -> V_61 )
V_2 -> V_57 -> V_61 ( V_2 ) ;
}
F_22 ( V_2 , 0 ) ;
V_2 -> V_285 = 0 ;
V_2 -> clock = 0 ;
V_4 -> V_57 -> V_429 ( V_4 , & V_4 -> V_81 ) ;
V_4 -> V_57 -> V_80 ( V_4 , & V_4 -> V_81 ) ;
if ( ( V_428 & V_392 ) &&
! ( V_2 -> V_53 & V_314 ) ) {
F_28 ( & V_2 -> V_88 , V_28 ) ;
F_111 ( V_2 , true ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
if ( ( V_4 -> V_430 & V_431 ) &&
V_4 -> V_57 -> V_432 )
V_4 -> V_57 -> V_432 ( V_4 , & V_4 -> V_81 ) ;
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_89 = false ;
if ( V_2 -> V_28 & V_351 )
F_118 ( V_2 , true ) ;
F_12 ( V_2 ) ;
F_29 ( & V_2 -> V_88 , V_28 ) ;
return 0 ;
}
struct V_1 * F_169 ( struct V_433 * V_434 ,
T_3 V_435 )
{
struct V_56 * V_4 ;
struct V_1 * V_2 ;
F_63 ( V_434 == NULL ) ;
V_4 = F_170 ( sizeof( struct V_1 ) + V_435 , V_434 ) ;
if ( ! V_4 )
return F_171 ( - V_436 ) ;
V_2 = F_106 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_437 = V_438 ;
V_4 -> V_57 = & V_2 -> V_437 ;
V_2 -> V_28 = V_355 ;
return V_2 ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
struct V_433 * V_434 = F_32 ( V_4 ) ;
int V_352 = - V_224 ;
if ( V_2 -> V_53 & V_439 )
V_2 -> V_28 &= ~ V_30 ;
if ( V_2 -> V_28 & V_30 ) {
V_352 = F_173 ( V_434 , F_174 ( 64 ) ) ;
if ( V_352 ) {
F_93 ( L_53 ,
F_3 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_30 ;
}
}
if ( V_352 ) {
V_352 = F_173 ( V_434 , F_174 ( 32 ) ) ;
if ( V_352 )
F_93 ( L_54 ,
F_3 ( V_4 ) ) ;
}
return V_352 ;
}
void F_175 ( struct V_1 * V_2 , T_5 * V_440 , T_1 * V_441 , T_1 * V_442 )
{
T_5 V_443 ;
if ( V_2 -> V_444 )
return;
V_2 -> V_444 = true ;
if ( V_445 )
V_2 -> V_41 = V_445 ;
if ( V_446 )
V_2 -> V_53 = V_446 ;
F_21 ( V_2 , V_52 ) ;
V_443 = V_440 ? * V_440 : F_5 ( V_2 , V_6 ) ;
V_2 -> V_178 = ( V_443 & V_447 ) >> V_448 ;
if ( V_2 -> V_41 & V_449 )
return;
V_2 -> V_441 = V_441 ? * V_441 : F_4 ( V_2 , V_23 ) ;
if ( V_2 -> V_178 < V_261 )
return;
V_2 -> V_442 = V_442 ? * V_442 : F_4 ( V_2 , V_24 ) ;
}
int F_176 ( struct V_1 * V_2 )
{
struct V_56 * V_4 ;
T_1 V_450 ;
unsigned int V_451 ;
unsigned int V_452 ;
T_1 V_268 ;
int V_352 ;
F_63 ( V_2 == NULL ) ;
if ( V_2 == NULL )
return - V_224 ;
V_4 = V_2 -> V_4 ;
V_352 = F_177 ( V_4 ) ;
if ( V_352 == - V_453 )
return V_352 ;
F_178 ( V_2 ) ;
V_452 = V_2 -> V_157 ;
if ( V_2 -> V_178 > V_261 ) {
F_2 ( L_55 ,
F_3 ( V_4 ) , V_2 -> V_178 ) ;
}
if ( V_2 -> V_41 & V_454 )
V_2 -> V_28 |= V_60 ;
else if ( ! ( V_2 -> V_441 & V_455 ) )
F_38 ( L_56 ) ;
else
V_2 -> V_28 |= V_60 ;
if ( ( V_2 -> V_41 & V_456 ) &&
( V_2 -> V_28 & V_60 ) ) {
F_38 ( L_57 ) ;
V_2 -> V_28 &= ~ V_60 ;
}
if ( ( V_2 -> V_178 >= V_179 ) &&
( V_2 -> V_441 & V_457 ) )
V_2 -> V_28 |= V_29 ;
if ( ( V_2 -> V_41 & V_458 ) &&
( V_2 -> V_28 & V_29 ) ) {
F_38 ( L_58 ) ;
V_2 -> V_28 &= ~ V_29 ;
}
if ( V_2 -> V_441 & V_459 )
V_2 -> V_28 |= V_30 ;
if ( V_2 -> V_28 & ( V_60 | V_29 ) ) {
V_352 = F_172 ( V_2 ) ;
if ( ! V_352 && V_2 -> V_57 -> V_61 )
V_352 = V_2 -> V_57 -> V_61 ( V_2 ) ;
if ( V_352 ) {
F_93 ( L_59 ,
F_3 ( V_4 ) ) ;
V_2 -> V_28 &= ~ ( V_60 | V_29 ) ;
V_352 = 0 ;
}
}
if ( V_2 -> V_28 & V_30 )
V_2 -> V_28 &= ~ V_60 ;
if ( V_2 -> V_28 & V_29 ) {
T_4 V_460 ;
void * V_101 ;
if ( V_2 -> V_28 & V_30 ) {
V_2 -> V_144 = ( V_461 * 2 + 1 ) *
V_462 ;
V_2 -> V_143 = V_462 ;
} else {
V_2 -> V_144 = ( V_461 * 2 + 1 ) *
V_463 ;
V_2 -> V_143 = V_463 ;
}
V_2 -> V_464 = V_461 * V_140 ;
V_101 = F_179 ( F_32 ( V_4 ) , V_2 -> V_464 +
V_2 -> V_144 , & V_460 , V_465 ) ;
if ( ! V_101 ) {
F_93 ( L_60 ,
F_3 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_29 ;
} else if ( ( V_460 + V_2 -> V_464 ) &
( V_466 - 1 ) ) {
F_93 ( L_61 ,
F_3 ( V_4 ) ) ;
V_2 -> V_28 &= ~ V_29 ;
F_180 ( F_32 ( V_4 ) , V_2 -> V_464 +
V_2 -> V_144 , V_101 , V_460 ) ;
} else {
V_2 -> V_139 = V_101 ;
V_2 -> V_135 = V_460 ;
V_2 -> V_138 = V_101 + V_2 -> V_464 ;
V_2 -> V_177 = V_460 + V_2 -> V_464 ;
}
}
if ( ! ( V_2 -> V_28 & ( V_60 | V_29 ) ) ) {
V_2 -> V_467 = F_174 ( 64 ) ;
F_32 ( V_4 ) -> V_467 = & V_2 -> V_467 ;
}
if ( V_2 -> V_178 >= V_261 )
V_2 -> V_268 = ( V_2 -> V_441 & V_468 )
>> V_469 ;
else
V_2 -> V_268 = ( V_2 -> V_441 & V_470 )
>> V_469 ;
V_2 -> V_268 *= 1000000 ;
if ( V_2 -> V_268 == 0 || V_2 -> V_41 &
V_471 ) {
if ( ! V_2 -> V_57 -> V_472 ) {
F_2 ( L_62 ,
F_3 ( V_4 ) ) ;
V_352 = - V_473 ;
goto V_474;
}
V_2 -> V_268 = V_2 -> V_57 -> V_472 ( V_2 ) ;
}
V_2 -> V_258 = ( V_2 -> V_442 & V_475 ) >>
V_476 ;
if ( V_2 -> V_258 )
V_2 -> V_258 += 1 ;
V_268 = V_2 -> V_268 ;
if ( V_2 -> V_57 -> V_477 )
V_4 -> V_478 = V_2 -> V_57 -> V_477 ( V_2 ) ;
else if ( V_2 -> V_178 >= V_261 ) {
if ( V_2 -> V_258 ) {
V_4 -> V_478 = ( V_2 -> V_268 * V_2 -> V_258 ) / 1024 ;
V_268 = V_2 -> V_268 * V_2 -> V_258 ;
} else
V_4 -> V_478 = V_2 -> V_268 / V_269 ;
} else
V_4 -> V_478 = V_2 -> V_268 / V_271 ;
if ( ! V_4 -> V_479 || V_4 -> V_479 > V_268 )
V_4 -> V_479 = V_268 ;
if ( ! ( V_2 -> V_41 & V_316 ) ) {
V_2 -> V_157 = ( V_2 -> V_441 & V_480 ) >>
V_481 ;
if ( V_2 -> V_157 == 0 ) {
if ( V_2 -> V_57 -> V_482 ) {
V_2 -> V_157 =
V_2 -> V_57 -> V_482 ( V_2 ) ;
} else {
F_2 ( L_63 ,
F_3 ( V_4 ) ) ;
V_352 = - V_473 ;
goto V_474;
}
}
if ( V_2 -> V_441 & V_483 )
V_2 -> V_157 *= 1000 ;
if ( V_452 )
V_2 -> V_157 = V_452 ;
V_4 -> V_317 = V_2 -> V_57 -> V_318 ?
V_2 -> V_57 -> V_318 ( V_2 ) : 1 << 27 ;
V_4 -> V_317 /= V_2 -> V_157 ;
}
V_4 -> V_441 |= V_484 | V_485 | V_486 ;
V_4 -> V_430 |= V_487 ;
if ( V_2 -> V_41 & V_488 )
V_2 -> V_28 |= V_191 ;
if ( ( V_2 -> V_178 >= V_261 ) &&
( ( V_2 -> V_28 & V_29 ) ||
! ( V_2 -> V_28 & V_60 ) ) &&
! ( V_2 -> V_53 & V_489 ) ) {
V_2 -> V_28 |= V_201 ;
F_38 ( L_64 , F_3 ( V_4 ) ) ;
} else {
F_38 ( L_65 , F_3 ( V_4 ) ) ;
}
if ( ! ( V_2 -> V_41 & V_490 ) )
V_4 -> V_441 |= V_491 ;
if ( V_2 -> V_53 & V_492 )
V_4 -> V_441 &= ~ V_486 ;
if ( V_2 -> V_441 & V_493 )
V_4 -> V_441 |= V_494 | V_495 ;
if ( ( V_2 -> V_41 & V_42 ) &&
F_10 ( V_4 ) &&
F_113 ( V_2 -> V_4 ) < 0 )
V_4 -> V_441 |= V_496 ;
if ( ! F_104 ( V_4 -> V_281 . V_357 ) ) {
V_352 = F_181 ( V_4 -> V_281 . V_357 ) ;
if ( ! F_182 ( V_4 -> V_281 . V_357 , 1700000 ,
1950000 ) )
V_2 -> V_442 &= ~ ( V_497 |
V_498 |
V_499 ) ;
if ( V_352 ) {
F_93 ( L_66 ,
F_3 ( V_4 ) , V_352 ) ;
V_4 -> V_281 . V_357 = F_171 ( - V_224 ) ;
}
}
if ( V_2 -> V_53 & V_500 ) {
V_2 -> V_442 &= ~ ( V_497 | V_498 |
V_499 ) ;
}
if ( V_2 -> V_442 & ( V_497 | V_498 |
V_499 ) )
V_4 -> V_441 |= V_501 | V_502 ;
if ( V_2 -> V_442 & V_497 ) {
V_4 -> V_441 |= V_503 | V_504 ;
if ( ! ( V_2 -> V_53 & V_505 ) )
V_4 -> V_430 |= V_506 ;
} else if ( V_2 -> V_442 & V_498 ) {
V_4 -> V_441 |= V_504 ;
}
if ( V_2 -> V_53 & V_507 &&
( V_2 -> V_442 & V_508 ) )
V_4 -> V_430 |= V_509 ;
if ( ( V_4 -> V_430 & V_510 ) &&
( F_104 ( V_4 -> V_281 . V_357 ) ||
! F_182 ( V_4 -> V_281 . V_357 , 1100000 ,
1300000 ) ) )
V_4 -> V_430 &= ~ V_510 ;
if ( ( V_2 -> V_442 & V_499 ) &&
! ( V_2 -> V_53 & V_511 ) )
V_4 -> V_441 |= V_512 ;
if ( V_2 -> V_442 & V_513 )
V_2 -> V_28 |= V_374 ;
if ( V_2 -> V_442 & V_514 )
V_4 -> V_441 |= V_515 ;
if ( V_2 -> V_442 & V_516 )
V_4 -> V_441 |= V_517 ;
if ( V_2 -> V_442 & V_518 )
V_4 -> V_441 |= V_519 ;
V_2 -> V_370 = ( V_2 -> V_442 & V_520 ) >>
V_521 ;
if ( V_2 -> V_370 )
V_2 -> V_370 = 1 << ( V_2 -> V_370 - 1 ) ;
V_2 -> V_76 = ( V_2 -> V_442 & V_522 ) >>
V_523 ;
V_451 = 0 ;
V_450 = F_4 ( V_2 , V_26 ) ;
if ( ! V_450 && ! F_104 ( V_4 -> V_281 . V_282 ) ) {
int V_524 = F_183 ( V_4 -> V_281 . V_282 ) ;
if ( V_524 > 0 ) {
V_524 = V_524 / 1000 ;
V_524 = V_524 / V_525 ;
V_524 = F_184 ( T_1 , V_524 , V_526 ) ;
V_450 =
( V_524 << V_527 ) |
( V_524 << V_528 ) |
( V_524 << V_529 ) ;
}
}
if ( V_2 -> V_441 & V_530 ) {
V_451 |= V_291 | V_292 ;
V_4 -> V_531 = ( ( V_450 &
V_532 ) >>
V_527 ) *
V_525 ;
}
if ( V_2 -> V_441 & V_533 ) {
V_451 |= V_288 | V_289 ;
V_4 -> V_534 = ( ( V_450 &
V_535 ) >>
V_528 ) *
V_525 ;
}
if ( V_2 -> V_441 & V_536 ) {
V_451 |= V_286 ;
V_4 -> V_537 = ( ( V_450 &
V_538 ) >>
V_529 ) *
V_525 ;
}
if ( V_2 -> V_539 )
V_451 = V_2 -> V_539 ;
if ( V_4 -> V_451 )
V_451 = V_4 -> V_451 ;
V_4 -> V_451 = V_451 ;
V_4 -> V_540 = V_451 ;
if ( V_2 -> V_540 )
V_4 -> V_540 &= V_2 -> V_540 ;
V_4 -> V_541 = V_451 ;
if ( V_2 -> V_541 )
V_4 -> V_541 &= V_2 -> V_541 ;
else
V_4 -> V_541 &= ~ V_286 ;
V_4 -> V_542 = V_451 ;
if ( V_2 -> V_542 )
V_4 -> V_542 &= V_2 -> V_542 ;
if ( V_4 -> V_451 == 0 ) {
F_2 ( L_67 ,
F_3 ( V_4 ) ) ;
V_352 = - V_473 ;
goto V_543;
}
if ( ( V_4 -> V_441 & ( V_501 | V_502 |
V_504 | V_503 |
V_512 | V_544 ) ) ||
( V_4 -> V_430 & ( V_545 | V_546 ) ) )
V_2 -> V_28 |= V_360 ;
if ( V_4 -> V_430 & V_510 )
V_2 -> V_28 |= V_363 ;
F_185 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_28 & V_29 )
V_4 -> V_547 = V_461 ;
else if ( V_2 -> V_28 & V_60 )
V_4 -> V_547 = 1 ;
else
V_4 -> V_547 = V_461 ;
V_4 -> V_548 = 524288 ;
if ( V_2 -> V_28 & V_29 ) {
if ( V_2 -> V_41 & V_549 )
V_4 -> V_550 = 65535 ;
else
V_4 -> V_550 = 65536 ;
} else {
V_4 -> V_550 = V_4 -> V_548 ;
}
if ( V_2 -> V_41 & V_551 ) {
V_4 -> V_167 = 2 ;
} else {
V_4 -> V_167 = ( V_2 -> V_441 & V_552 ) >>
V_553 ;
if ( V_4 -> V_167 >= 3 ) {
F_93 ( L_68 ,
F_3 ( V_4 ) ) ;
V_4 -> V_167 = 0 ;
}
}
V_4 -> V_167 = 512 << V_4 -> V_167 ;
V_4 -> V_554 = ( V_2 -> V_41 & V_555 ) ? 1 : 65535 ;
return 0 ;
V_543:
if ( ! F_104 ( V_4 -> V_281 . V_357 ) )
F_186 ( V_4 -> V_281 . V_357 ) ;
V_474:
if ( V_2 -> V_139 )
F_180 ( F_32 ( V_4 ) , V_2 -> V_464 +
V_2 -> V_144 , V_2 -> V_139 ,
V_2 -> V_135 ) ;
V_2 -> V_138 = NULL ;
V_2 -> V_139 = NULL ;
return V_352 ;
}
int F_187 ( struct V_1 * V_2 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
int V_352 ;
F_188 ( & V_2 -> V_211 ,
F_138 , ( unsigned long ) V_2 ) ;
F_189 ( & V_2 -> V_215 , F_139 , ( unsigned long ) V_2 ) ;
F_189 ( & V_2 -> V_214 , F_140 ,
( unsigned long ) V_2 ) ;
F_190 ( & V_2 -> V_382 ) ;
F_22 ( V_2 , 0 ) ;
V_352 = F_164 ( V_2 -> V_407 , F_148 , F_153 ,
V_427 , F_3 ( V_4 ) , V_2 ) ;
if ( V_352 ) {
F_2 ( L_69 ,
F_3 ( V_4 ) , V_2 -> V_407 , V_352 ) ;
goto V_556;
}
#ifdef F_191
F_1 ( V_2 ) ;
#endif
V_352 = F_30 ( V_2 ) ;
if ( V_352 ) {
F_2 ( L_70 ,
F_3 ( V_4 ) , V_352 ) ;
goto V_557;
}
F_107 () ;
V_352 = F_192 ( V_4 ) ;
if ( V_352 )
goto V_558;
F_128 ( L_71 ,
F_3 ( V_4 ) , V_2 -> V_559 , F_193 ( F_32 ( V_4 ) ) ,
( V_2 -> V_28 & V_29 ) ?
( V_2 -> V_28 & V_30 ) ? L_72 : L_73 :
( V_2 -> V_28 & V_60 ) ? L_74 : L_75 ) ;
F_12 ( V_2 ) ;
return 0 ;
V_558:
F_33 ( V_2 ) ;
V_557:
F_21 ( V_2 , V_52 ) ;
F_11 ( V_2 , 0 , V_19 ) ;
F_11 ( V_2 , 0 , V_20 ) ;
F_161 ( V_2 -> V_407 , V_2 ) ;
V_556:
F_194 ( & V_2 -> V_211 ) ;
if ( ! F_104 ( V_4 -> V_281 . V_357 ) )
F_186 ( V_4 -> V_281 . V_357 ) ;
if ( V_2 -> V_139 )
F_180 ( F_32 ( V_4 ) , V_2 -> V_464 +
V_2 -> V_144 , V_2 -> V_139 ,
V_2 -> V_135 ) ;
V_2 -> V_138 = NULL ;
V_2 -> V_139 = NULL ;
return V_352 ;
}
int F_195 ( struct V_1 * V_2 )
{
int V_352 ;
V_352 = F_176 ( V_2 ) ;
if ( V_352 )
return V_352 ;
return F_187 ( V_2 ) ;
}
void F_196 ( struct V_1 * V_2 , int V_560 )
{
struct V_56 * V_4 = V_2 -> V_4 ;
unsigned long V_28 ;
if ( V_560 ) {
F_28 ( & V_2 -> V_88 , V_28 ) ;
V_2 -> V_28 |= V_206 ;
if ( F_133 ( V_2 ) ) {
F_2 ( L_76
L_77 , F_3 ( V_4 ) ) ;
F_134 ( V_2 , - V_297 ) ;
}
F_29 ( & V_2 -> V_88 , V_28 ) ;
}
F_13 ( V_2 ) ;
F_197 ( V_4 ) ;
F_33 ( V_2 ) ;
if ( ! V_560 )
F_21 ( V_2 , V_52 ) ;
F_11 ( V_2 , 0 , V_19 ) ;
F_11 ( V_2 , 0 , V_20 ) ;
F_161 ( V_2 -> V_407 , V_2 ) ;
F_198 ( & V_2 -> V_215 ) ;
F_198 ( & V_2 -> V_214 ) ;
F_194 ( & V_2 -> V_211 ) ;
if ( ! F_104 ( V_4 -> V_281 . V_357 ) )
F_186 ( V_4 -> V_281 . V_357 ) ;
if ( V_2 -> V_139 )
F_180 ( F_32 ( V_4 ) , V_2 -> V_464 +
V_2 -> V_144 , V_2 -> V_139 ,
V_2 -> V_135 ) ;
V_2 -> V_138 = NULL ;
V_2 -> V_139 = NULL ;
}
void F_199 ( struct V_1 * V_2 )
{
F_200 ( V_2 -> V_4 ) ;
}
static int T_7 F_201 ( void )
{
F_128 ( V_3
L_78 ) ;
F_128 ( V_3 L_79 ) ;
return 0 ;
}
static void T_8 F_202 ( void )
{
}
