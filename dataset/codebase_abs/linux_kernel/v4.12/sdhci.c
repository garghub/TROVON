void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_2 ( L_2 ,
F_3 ( V_2 , V_3 ) ,
F_4 ( V_2 , V_4 ) ) ;
F_2 ( L_3 ,
F_4 ( V_2 , V_5 ) ,
F_4 ( V_2 , V_6 ) ) ;
F_2 ( L_4 ,
F_3 ( V_2 , V_7 ) ,
F_4 ( V_2 , V_8 ) ) ;
F_2 ( L_5 ,
F_3 ( V_2 , V_9 ) ,
F_5 ( V_2 , V_10 ) ) ;
F_2 ( L_6 ,
F_5 ( V_2 , V_11 ) ,
F_5 ( V_2 , V_12 ) ) ;
F_2 ( L_7 ,
F_5 ( V_2 , V_13 ) ,
F_4 ( V_2 , V_14 ) ) ;
F_2 ( L_8 ,
F_5 ( V_2 , V_15 ) ,
F_3 ( V_2 , V_16 ) ) ;
F_2 ( L_9 ,
F_3 ( V_2 , V_17 ) ,
F_3 ( V_2 , V_18 ) ) ;
F_2 ( L_10 ,
F_4 ( V_2 , V_19 ) ,
F_4 ( V_2 , V_20 ) ) ;
F_2 ( L_11 ,
F_3 ( V_2 , V_21 ) ,
F_3 ( V_2 , V_22 ) ) ;
F_2 ( L_12 ,
F_4 ( V_2 , V_23 ) ,
F_3 ( V_2 , V_24 ) ) ;
F_2 ( L_13 ,
F_3 ( V_2 , V_25 ) ,
F_3 ( V_2 , V_25 + 4 ) ) ;
F_2 ( L_14 ,
F_3 ( V_2 , V_25 + 8 ) ,
F_3 ( V_2 , V_25 + 12 ) ) ;
F_2 ( L_15 ,
F_4 ( V_2 , V_26 ) ) ;
if ( V_2 -> V_27 & V_28 ) {
if ( V_2 -> V_27 & V_29 ) {
F_2 ( L_16 ,
F_3 ( V_2 , V_30 ) ,
F_3 ( V_2 , V_31 ) ,
F_3 ( V_2 , V_32 ) ) ;
} else {
F_2 ( L_17 ,
F_3 ( V_2 , V_30 ) ,
F_3 ( V_2 , V_32 ) ) ;
}
}
F_2 ( L_18 ) ;
}
static inline bool F_6 ( struct V_33 * V_34 )
{
return V_34 -> V_35 || V_34 -> V_27 & V_36 ;
}
static void F_7 ( struct V_1 * V_2 , bool V_37 )
{
T_1 V_38 ;
if ( ( V_2 -> V_39 & V_40 ) ||
! F_8 ( V_2 -> V_41 ) )
return;
if ( V_37 ) {
V_38 = F_3 ( V_2 , V_9 ) &
V_42 ;
V_2 -> V_43 |= V_38 ? V_44 :
V_45 ;
} else {
V_2 -> V_43 &= ~ ( V_44 | V_45 ) ;
}
F_9 ( V_2 , V_2 -> V_43 , V_17 ) ;
F_9 ( V_2 , V_2 -> V_43 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 , true ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_7 ( V_2 , false ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 )
return;
V_2 -> V_46 = true ;
F_13 ( V_2 -> V_41 -> V_47 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_46 )
return;
V_2 -> V_46 = false ;
F_15 ( V_2 -> V_41 -> V_47 ) ;
}
void F_16 ( struct V_1 * V_2 , T_2 V_48 )
{
T_3 V_49 ;
F_17 ( V_2 , V_48 , V_50 ) ;
if ( V_48 & V_51 ) {
V_2 -> clock = 0 ;
if ( V_2 -> V_52 & V_53 )
F_14 ( V_2 ) ;
}
V_49 = F_18 ( F_19 () , 100 ) ;
while ( F_5 ( V_2 , V_50 ) & V_48 ) {
if ( F_20 ( F_19 () , V_49 ) ) {
F_21 ( L_19 ,
F_22 ( V_2 -> V_41 ) , ( int ) V_48 ) ;
F_1 ( V_2 ) ;
return;
}
F_23 ( 10 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , T_2 V_48 )
{
if ( V_2 -> V_39 & V_54 ) {
struct V_55 * V_41 = V_2 -> V_41 ;
if ( ! V_41 -> V_56 -> V_57 ( V_41 ) )
return;
}
V_2 -> V_56 -> V_58 ( V_2 , V_48 ) ;
if ( V_48 & V_51 ) {
if ( V_2 -> V_27 & ( V_59 | V_28 ) ) {
if ( V_2 -> V_56 -> V_60 )
V_2 -> V_56 -> V_60 ( V_2 ) ;
}
V_2 -> V_61 = false ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_43 = V_62 | V_63 |
V_64 | V_65 |
V_66 | V_67 | V_68 |
V_69 | V_70 |
V_71 ;
if ( V_2 -> V_72 == V_73 ||
V_2 -> V_72 == V_74 )
V_2 -> V_43 |= V_75 ;
F_9 ( V_2 , V_2 -> V_43 , V_17 ) ;
F_9 ( V_2 , V_2 -> V_43 , V_18 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_76 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
if ( V_76 )
F_24 ( V_2 , V_77 | V_78 ) ;
else
F_24 ( V_2 , V_51 ) ;
F_25 ( V_2 ) ;
V_2 -> V_79 = false ;
if ( V_76 ) {
V_2 -> clock = 0 ;
V_41 -> V_56 -> V_80 ( V_41 , & V_41 -> V_81 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 , 0 ) ;
F_10 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_2 V_82 ;
V_82 = F_5 ( V_2 , V_10 ) ;
V_82 |= V_83 ;
F_17 ( V_2 , V_82 , V_10 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_2 V_82 ;
V_82 = F_5 ( V_2 , V_10 ) ;
V_82 &= ~ V_83 ;
F_17 ( V_2 , V_82 , V_10 ) ;
}
static void F_30 ( struct V_84 * V_85 ,
enum V_86 V_87 )
{
struct V_1 * V_2 = F_31 ( V_85 , struct V_1 , V_85 ) ;
unsigned long V_27 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
if ( V_2 -> V_89 )
goto V_90;
if ( V_87 == V_91 )
F_29 ( V_2 ) ;
else
F_28 ( V_2 ) ;
V_90:
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
snprintf ( V_2 -> V_92 , sizeof( V_2 -> V_92 ) ,
L_20 , F_22 ( V_41 ) ) ;
V_2 -> V_85 . V_93 = V_2 -> V_92 ;
V_2 -> V_85 . V_87 = V_91 ;
V_2 -> V_85 . V_94 = F_22 ( V_41 ) ;
V_2 -> V_85 . V_95 = F_30 ;
return F_35 ( F_36 ( V_41 ) , & V_2 -> V_85 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_85 ) ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
}
static inline void F_40 ( struct V_1 * V_2 )
{
}
static inline int F_34 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_37 ( struct V_1 * V_2 )
{
}
static inline void F_39 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
}
static inline void F_40 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
T_4 V_96 , V_97 , V_98 ;
T_1 V_99 ( V_100 ) ;
T_2 * V_101 ;
F_42 ( L_21 ) ;
V_96 = V_2 -> V_35 -> V_102 ;
V_98 = 0 ;
F_43 ( V_27 ) ;
while ( V_96 ) {
F_44 ( ! F_45 ( & V_2 -> V_103 ) ) ;
V_97 = F_46 ( V_2 -> V_103 . V_104 , V_96 ) ;
V_96 -= V_97 ;
V_2 -> V_103 . V_105 = V_97 ;
V_101 = V_2 -> V_103 . V_106 ;
while ( V_97 ) {
if ( V_98 == 0 ) {
V_100 = F_3 ( V_2 , V_107 ) ;
V_98 = 4 ;
}
* V_101 = V_100 & 0xFF ;
V_101 ++ ;
V_100 >>= 8 ;
V_98 -- ;
V_97 -- ;
}
}
F_47 ( & V_2 -> V_103 ) ;
F_48 ( V_27 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
T_4 V_96 , V_97 , V_98 ;
T_1 V_100 ;
T_2 * V_101 ;
F_42 ( L_22 ) ;
V_96 = V_2 -> V_35 -> V_102 ;
V_98 = 0 ;
V_100 = 0 ;
F_43 ( V_27 ) ;
while ( V_96 ) {
F_44 ( ! F_45 ( & V_2 -> V_103 ) ) ;
V_97 = F_46 ( V_2 -> V_103 . V_104 , V_96 ) ;
V_96 -= V_97 ;
V_2 -> V_103 . V_105 = V_97 ;
V_101 = V_2 -> V_103 . V_106 ;
while ( V_97 ) {
V_100 |= ( T_1 ) * V_101 << ( V_98 * 8 ) ;
V_101 ++ ;
V_98 ++ ;
V_97 -- ;
if ( ( V_98 == 4 ) || ( ( V_97 == 0 ) && ( V_96 == 0 ) ) ) {
F_9 ( V_2 , V_100 , V_107 ) ;
V_98 = 0 ;
V_100 = 0 ;
}
}
}
F_47 ( & V_2 -> V_103 ) ;
F_48 ( V_27 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
T_1 V_48 ;
if ( V_2 -> V_108 == 0 )
return;
if ( V_2 -> V_35 -> V_27 & V_109 )
V_48 = V_110 ;
else
V_48 = V_111 ;
if ( ( V_2 -> V_39 & V_112 ) &&
( V_2 -> V_35 -> V_108 == 1 ) )
V_48 = ~ 0 ;
while ( F_3 ( V_2 , V_9 ) & V_48 ) {
if ( V_2 -> V_39 & V_113 )
F_23 ( 100 ) ;
if ( V_2 -> V_35 -> V_27 & V_109 )
F_41 ( V_2 ) ;
else
F_49 ( V_2 ) ;
V_2 -> V_108 -- ;
if ( V_2 -> V_108 == 0 )
break;
}
F_42 ( L_23 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_114 * V_35 , int V_115 )
{
int V_116 ;
if ( V_35 -> V_117 == V_118 )
return V_35 -> V_116 ;
V_116 = F_52 ( F_36 ( V_2 -> V_41 ) , V_35 -> V_119 , V_35 -> V_120 ,
F_53 ( V_35 ) ) ;
if ( V_116 == 0 )
return - V_121 ;
V_35 -> V_116 = V_116 ;
V_35 -> V_117 = V_115 ;
return V_116 ;
}
static char * F_54 ( struct V_122 * V_119 , unsigned long * V_27 )
{
F_43 ( * V_27 ) ;
return F_55 ( F_56 ( V_119 ) ) + V_119 -> V_123 ;
}
static void F_57 ( void * V_124 , unsigned long * V_27 )
{
F_58 ( V_124 ) ;
F_48 ( * V_27 ) ;
}
static void F_59 ( struct V_1 * V_2 , void * V_125 ,
T_5 V_106 , int V_97 , unsigned V_34 )
{
struct V_126 * V_127 = V_125 ;
V_127 -> V_34 = F_60 ( V_34 ) ;
V_127 -> V_97 = F_60 ( V_97 ) ;
V_127 -> V_128 = F_61 ( ( T_1 ) V_106 ) ;
if ( V_2 -> V_27 & V_29 )
V_127 -> V_129 = F_61 ( ( V_130 ) V_106 >> 32 ) ;
}
static void F_62 ( void * V_125 )
{
struct V_126 * V_127 = V_125 ;
V_127 -> V_34 |= F_60 ( V_131 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_114 * V_35 , int V_116 )
{
struct V_122 * V_119 ;
unsigned long V_27 ;
T_5 V_106 , V_132 ;
void * V_125 , * V_133 ;
char * V_124 ;
int V_97 , V_123 , V_134 ;
V_2 -> V_116 = V_116 ;
V_125 = V_2 -> V_135 ;
V_133 = V_2 -> V_136 ;
V_132 = V_2 -> V_132 ;
F_64 (data->sg, sg, host->sg_count, i) {
V_106 = F_65 ( V_119 ) ;
V_97 = F_66 ( V_119 ) ;
V_123 = ( V_137 - ( V_106 & V_138 ) ) &
V_138 ;
if ( V_123 ) {
if ( V_35 -> V_27 & V_139 ) {
V_124 = F_54 ( V_119 , & V_27 ) ;
memcpy ( V_133 , V_124 , V_123 ) ;
F_57 ( V_124 , & V_27 ) ;
}
F_59 ( V_2 , V_125 , V_132 , V_123 ,
V_140 ) ;
F_44 ( V_123 > 65536 ) ;
V_133 += V_137 ;
V_132 += V_137 ;
V_125 += V_2 -> V_141 ;
V_106 += V_123 ;
V_97 -= V_123 ;
}
F_44 ( V_97 > 65536 ) ;
if ( V_97 ) {
F_59 ( V_2 , V_125 , V_106 , V_97 ,
V_140 ) ;
V_125 += V_2 -> V_141 ;
}
F_67 ( ( V_125 - V_2 -> V_135 ) >= V_2 -> V_142 ) ;
}
if ( V_2 -> V_39 & V_143 ) {
if ( V_125 != V_2 -> V_135 ) {
V_125 -= V_2 -> V_141 ;
F_62 ( V_125 ) ;
}
} else {
F_59 ( V_2 , V_125 , 0 , 0 , V_144 ) ;
}
}
static void F_68 ( struct V_1 * V_2 ,
struct V_114 * V_35 )
{
struct V_122 * V_119 ;
int V_134 , V_145 ;
void * V_133 ;
char * V_124 ;
unsigned long V_27 ;
if ( V_35 -> V_27 & V_109 ) {
bool V_146 = false ;
F_64 (data->sg, sg, host->sg_count, i)
if ( F_65 ( V_119 ) & V_138 ) {
V_146 = true ;
break;
}
if ( V_146 ) {
F_69 ( F_36 ( V_2 -> V_41 ) , V_35 -> V_119 ,
V_35 -> V_120 , V_147 ) ;
V_133 = V_2 -> V_136 ;
F_64 (data->sg, sg, host->sg_count, i) {
if ( F_65 ( V_119 ) & V_138 ) {
V_145 = V_137 -
( F_65 ( V_119 ) & V_138 ) ;
V_124 = F_54 ( V_119 , & V_27 ) ;
memcpy ( V_124 , V_133 , V_145 ) ;
F_57 ( V_124 , & V_27 ) ;
V_133 += V_137 ;
}
}
}
}
}
static T_2 F_70 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
T_2 V_148 ;
struct V_114 * V_35 = V_34 -> V_35 ;
unsigned V_149 , V_150 ;
if ( V_2 -> V_39 & V_151 )
return 0xE ;
if ( ! V_35 && ! V_34 -> V_152 )
return 0xE ;
if ( ! V_35 )
V_149 = V_34 -> V_152 * 1000 ;
else {
V_149 = F_71 ( V_35 -> V_153 , 1000 ) ;
if ( V_2 -> clock && V_35 -> V_154 ) {
unsigned long long V_155 ;
V_155 = 1000000ULL * V_35 -> V_154 ;
if ( F_72 ( V_155 , V_2 -> clock ) )
V_149 ++ ;
V_149 += V_155 ;
}
}
V_148 = 0 ;
V_150 = ( 1 << 13 ) * 1000 / V_2 -> V_156 ;
while ( V_150 < V_149 ) {
V_148 ++ ;
V_150 <<= 1 ;
if ( V_148 >= 0xF )
break;
}
if ( V_148 >= 0xF ) {
F_42 ( L_24 ,
V_148 , V_34 -> V_157 ) ;
V_148 = 0xE ;
}
return V_148 ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_1 V_158 = V_159 | V_160 ;
T_1 V_161 = V_162 | V_163 ;
if ( V_2 -> V_27 & V_164 )
V_2 -> V_43 = ( V_2 -> V_43 & ~ V_158 ) | V_161 ;
else
V_2 -> V_43 = ( V_2 -> V_43 & ~ V_161 ) | V_158 ;
F_9 ( V_2 , V_2 -> V_43 , V_17 ) ;
F_9 ( V_2 , V_2 -> V_43 , V_18 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
T_2 V_148 ;
if ( V_2 -> V_56 -> V_165 ) {
V_2 -> V_56 -> V_165 ( V_2 , V_34 ) ;
} else {
V_148 = F_70 ( V_2 , V_34 ) ;
F_17 ( V_2 , V_148 , V_15 ) ;
}
}
static void F_75 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
T_2 V_82 ;
struct V_114 * V_35 = V_34 -> V_35 ;
if ( F_6 ( V_34 ) )
F_74 ( V_2 , V_34 ) ;
if ( ! V_35 )
return;
F_67 ( V_2 -> V_35 ) ;
F_44 ( V_35 -> V_102 * V_35 -> V_108 > 524288 ) ;
F_44 ( V_35 -> V_102 > V_2 -> V_41 -> V_166 ) ;
F_44 ( V_35 -> V_108 > 65535 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_167 = 0 ;
V_2 -> V_35 -> V_168 = 0 ;
if ( V_2 -> V_27 & ( V_59 | V_28 ) ) {
struct V_122 * V_119 ;
unsigned int V_169 , V_170 ;
int V_134 ;
V_2 -> V_27 |= V_164 ;
V_169 = 0 ;
V_170 = 0 ;
if ( V_2 -> V_27 & V_28 ) {
if ( V_2 -> V_39 & V_171 ) {
V_169 = 3 ;
V_170 = 3 ;
}
} else {
if ( V_2 -> V_39 & V_172 )
V_169 = 3 ;
if ( V_2 -> V_39 & V_173 )
V_170 = 3 ;
}
if ( F_76 ( V_169 | V_170 ) ) {
F_64 (data->sg, sg, data->sg_len, i) {
if ( V_119 -> V_104 & V_169 ) {
F_42 ( L_25 ,
V_119 -> V_104 ) ;
V_2 -> V_27 &= ~ V_164 ;
break;
}
if ( V_119 -> V_123 & V_170 ) {
F_42 ( L_26 ) ;
V_2 -> V_27 &= ~ V_164 ;
break;
}
}
}
}
if ( V_2 -> V_27 & V_164 ) {
int V_174 = F_51 ( V_2 , V_35 , V_175 ) ;
if ( V_174 <= 0 ) {
F_67 ( 1 ) ;
V_2 -> V_27 &= ~ V_164 ;
} else if ( V_2 -> V_27 & V_28 ) {
F_63 ( V_2 , V_35 , V_174 ) ;
F_9 ( V_2 , V_2 -> V_176 , V_32 ) ;
if ( V_2 -> V_27 & V_29 )
F_9 ( V_2 ,
( V_130 ) V_2 -> V_176 >> 32 ,
V_31 ) ;
} else {
F_67 ( V_174 != 1 ) ;
F_9 ( V_2 , F_65 ( V_35 -> V_119 ) ,
V_3 ) ;
}
}
if ( V_2 -> V_177 >= V_178 ) {
V_82 = F_5 ( V_2 , V_10 ) ;
V_82 &= ~ V_179 ;
if ( ( V_2 -> V_27 & V_164 ) &&
( V_2 -> V_27 & V_28 ) ) {
if ( V_2 -> V_27 & V_29 )
V_82 |= V_180 ;
else
V_82 |= V_181 ;
} else {
V_82 |= V_182 ;
}
F_17 ( V_2 , V_82 , V_10 ) ;
}
if ( ! ( V_2 -> V_27 & V_164 ) ) {
int V_27 ;
V_27 = V_183 ;
if ( V_2 -> V_35 -> V_27 & V_109 )
V_27 |= V_184 ;
else
V_27 |= V_185 ;
F_77 ( & V_2 -> V_103 , V_35 -> V_119 , V_35 -> V_120 , V_27 ) ;
V_2 -> V_108 = V_35 -> V_108 ;
}
F_73 ( V_2 ) ;
F_78 ( V_2 , F_79 ( V_186 ,
V_35 -> V_102 ) , V_5 ) ;
F_78 ( V_2 , V_35 -> V_108 , V_6 ) ;
}
static inline bool F_80 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
return ! V_188 -> V_189 && ( V_2 -> V_27 & V_190 ) &&
! V_188 -> V_191 ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
T_6 V_192 = 0 ;
struct V_114 * V_35 = V_34 -> V_35 ;
if ( V_35 == NULL ) {
if ( V_2 -> V_52 &
V_193 ) {
F_78 ( V_2 , 0x0 , V_8 ) ;
} else {
V_192 = F_4 ( V_2 , V_8 ) ;
F_78 ( V_2 , V_192 & ~ ( V_194 |
V_195 ) , V_8 ) ;
}
return;
}
F_67 ( ! V_2 -> V_35 ) ;
if ( ! ( V_2 -> V_52 & V_196 ) )
V_192 = V_197 ;
if ( F_82 ( V_34 -> V_157 ) || V_35 -> V_108 > 1 ) {
V_192 = V_197 | V_198 ;
if ( F_80 ( V_2 , V_34 -> V_188 ) &&
( V_34 -> V_157 != V_199 ) )
V_192 |= V_194 ;
else if ( V_34 -> V_188 -> V_189 && ( V_2 -> V_27 & V_200 ) ) {
V_192 |= V_195 ;
F_9 ( V_2 , V_34 -> V_188 -> V_189 -> V_201 , V_202 ) ;
}
}
if ( V_35 -> V_27 & V_109 )
V_192 |= V_203 ;
if ( V_2 -> V_27 & V_164 )
V_192 |= V_204 ;
F_78 ( V_2 , V_192 , V_8 ) ;
}
static bool F_83 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
return ( ! ( V_2 -> V_27 & V_205 ) &&
( ( V_188 -> V_34 && V_188 -> V_34 -> error ) ||
( V_188 -> V_189 && V_188 -> V_189 -> error ) ||
( V_188 -> V_35 && ( ( V_188 -> V_35 -> error && ! V_188 -> V_35 -> V_206 ) ||
( V_188 -> V_35 -> V_206 && V_188 -> V_35 -> V_206 -> error ) ) ) ||
( V_2 -> V_39 & V_207 ) ) ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_208 ; V_134 ++ ) {
if ( V_2 -> V_209 [ V_134 ] == V_188 ) {
F_67 ( 1 ) ;
return;
}
}
for ( V_134 = 0 ; V_134 < V_208 ; V_134 ++ ) {
if ( ! V_2 -> V_209 [ V_134 ] ) {
V_2 -> V_209 [ V_134 ] = V_188 ;
break;
}
}
F_67 ( V_134 >= V_208 ) ;
F_85 ( & V_2 -> V_210 ) ;
}
static void F_86 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
if ( V_2 -> V_34 && V_2 -> V_34 -> V_188 == V_188 )
V_2 -> V_34 = NULL ;
if ( V_2 -> V_211 && V_2 -> V_211 -> V_188 == V_188 )
V_2 -> V_211 = NULL ;
if ( V_2 -> V_35 && V_2 -> V_35 -> V_188 == V_188 )
V_2 -> V_35 = NULL ;
if ( F_83 ( V_2 , V_188 ) )
V_2 -> V_212 = true ;
F_84 ( V_2 , V_188 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_33 * V_211 = V_2 -> V_211 ;
struct V_114 * V_35 = V_2 -> V_35 ;
V_2 -> V_35 = NULL ;
V_2 -> V_211 = NULL ;
if ( ( V_2 -> V_27 & ( V_164 | V_28 ) ) ==
( V_164 | V_28 ) )
F_68 ( V_2 , V_35 ) ;
if ( V_35 -> error )
V_35 -> V_168 = 0 ;
else
V_35 -> V_168 = V_35 -> V_102 * V_35 -> V_108 ;
if ( V_35 -> V_206 &&
( V_35 -> error ||
! V_35 -> V_188 -> V_189 ) ) {
if ( V_35 -> error ) {
if ( ! V_2 -> V_34 || V_2 -> V_34 == V_211 )
F_24 ( V_2 , V_77 ) ;
F_24 ( V_2 , V_78 ) ;
}
if ( V_35 -> V_188 -> V_191 ) {
F_86 ( V_2 , V_35 -> V_188 ) ;
} else {
V_2 -> V_34 = NULL ;
F_88 ( V_2 , V_35 -> V_206 ) ;
}
} else {
F_86 ( V_2 , V_35 -> V_188 ) ;
}
}
static void F_89 ( struct V_1 * V_2 , struct V_187 * V_188 ,
unsigned long V_49 )
{
if ( F_6 ( V_188 -> V_34 ) )
F_90 ( & V_2 -> V_213 , V_49 ) ;
else
F_90 ( & V_2 -> V_214 , V_49 ) ;
}
static void F_91 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
if ( F_6 ( V_188 -> V_34 ) )
F_92 ( & V_2 -> V_213 ) ;
else
F_92 ( & V_2 -> V_214 ) ;
}
void F_88 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
int V_27 ;
T_1 V_48 ;
unsigned long V_49 ;
F_67 ( V_2 -> V_34 ) ;
V_34 -> error = 0 ;
if ( ( V_2 -> V_52 & V_215 ) &&
V_34 -> V_157 == V_216 )
V_34 -> V_27 |= V_36 ;
V_49 = 10 ;
V_48 = V_217 ;
if ( F_6 ( V_34 ) )
V_48 |= V_218 ;
if ( V_34 -> V_188 -> V_35 && ( V_34 == V_34 -> V_188 -> V_35 -> V_206 ) )
V_48 &= ~ V_218 ;
while ( F_3 ( V_2 , V_9 ) & V_48 ) {
if ( V_49 == 0 ) {
F_21 ( L_27 ,
F_22 ( V_2 -> V_41 ) ) ;
F_1 ( V_2 ) ;
V_34 -> error = - V_219 ;
F_86 ( V_2 , V_34 -> V_188 ) ;
return;
}
V_49 -- ;
F_93 ( 1 ) ;
}
V_49 = V_220 ;
if ( ! V_34 -> V_35 && V_34 -> V_152 > 9000 )
V_49 += F_71 ( V_34 -> V_152 , 1000 ) * V_221 + V_221 ;
else
V_49 += 10 * V_221 ;
F_89 ( V_2 , V_34 -> V_188 , V_49 ) ;
V_2 -> V_34 = V_34 ;
if ( F_6 ( V_34 ) ) {
F_67 ( V_2 -> V_211 ) ;
V_2 -> V_211 = V_34 ;
}
F_75 ( V_2 , V_34 ) ;
F_9 ( V_2 , V_34 -> V_201 , V_7 ) ;
F_81 ( V_2 , V_34 ) ;
if ( ( V_34 -> V_27 & V_222 ) && ( V_34 -> V_27 & V_36 ) ) {
F_21 ( L_28 ,
F_22 ( V_2 -> V_41 ) ) ;
V_34 -> error = - V_223 ;
F_86 ( V_2 , V_34 -> V_188 ) ;
return;
}
if ( ! ( V_34 -> V_27 & V_224 ) )
V_27 = V_225 ;
else if ( V_34 -> V_27 & V_222 )
V_27 = V_226 ;
else if ( V_34 -> V_27 & V_36 )
V_27 = V_227 ;
else
V_27 = V_228 ;
if ( V_34 -> V_27 & V_229 )
V_27 |= V_230 ;
if ( V_34 -> V_27 & V_231 )
V_27 |= V_232 ;
if ( V_34 -> V_35 || V_34 -> V_157 == V_233 ||
V_34 -> V_157 == V_234 )
V_27 |= V_235 ;
F_78 ( V_2 , F_94 ( V_34 -> V_157 , V_27 ) , V_23 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
int V_134 ;
V_2 -> V_34 = NULL ;
if ( V_34 -> V_27 & V_224 ) {
if ( V_34 -> V_27 & V_222 ) {
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
V_34 -> V_236 [ V_134 ] = F_3 ( V_2 ,
V_25 + ( 3 - V_134 ) * 4 ) << 8 ;
if ( V_134 != 3 )
V_34 -> V_236 [ V_134 ] |=
F_5 ( V_2 ,
V_25 + ( 3 - V_134 ) * 4 - 1 ) ;
}
} else {
V_34 -> V_236 [ 0 ] = F_3 ( V_2 , V_25 ) ;
}
}
if ( V_34 -> V_188 -> V_191 && V_34 == V_34 -> V_188 -> V_34 )
F_96 ( V_2 -> V_41 , V_34 -> V_188 ) ;
if ( V_34 -> V_27 & V_36 ) {
if ( V_34 -> V_35 ) {
F_42 ( L_29 ) ;
} else if ( ! ( V_2 -> V_39 & V_237 ) &&
V_34 == V_2 -> V_211 ) {
return;
}
}
if ( V_34 == V_34 -> V_188 -> V_189 ) {
F_88 ( V_2 , V_34 -> V_188 -> V_34 ) ;
} else {
if ( V_2 -> V_35 && V_2 -> V_167 )
F_87 ( V_2 ) ;
if ( ! V_34 -> V_35 )
F_86 ( V_2 , V_34 -> V_188 ) ;
}
}
static T_6 F_97 ( struct V_1 * V_2 )
{
T_6 V_238 = 0 ;
switch ( V_2 -> V_239 ) {
case V_240 :
V_238 = F_4 ( V_2 , V_241 ) ;
break;
case V_242 :
V_238 = F_4 ( V_2 , V_243 ) ;
break;
case V_244 :
V_238 = F_4 ( V_2 , V_245 ) ;
break;
case V_246 :
case V_247 :
V_238 = F_4 ( V_2 , V_248 ) ;
break;
case V_249 :
case V_250 :
V_238 = F_4 ( V_2 , V_251 ) ;
break;
case V_252 :
V_238 = F_4 ( V_2 , V_253 ) ;
break;
default:
F_98 ( L_30 ,
F_22 ( V_2 -> V_41 ) ) ;
V_238 = F_4 ( V_2 , V_241 ) ;
break;
}
return V_238 ;
}
T_6 F_99 ( struct V_1 * V_2 , unsigned int clock ,
unsigned int * V_254 )
{
int div = 0 ;
int V_255 = div , V_256 = 1 ;
T_6 V_257 = 0 ;
bool V_258 = false ;
if ( V_2 -> V_177 >= V_259 ) {
if ( V_2 -> V_61 ) {
T_6 V_260 ;
V_257 = F_4 ( V_2 , V_14 ) ;
V_260 = F_97 ( V_2 ) ;
div = ( V_260 & V_261 )
>> V_262 ;
if ( V_2 -> V_256 &&
( V_260 & V_263 ) ) {
V_257 = V_264 ;
V_255 = div + 1 ;
V_256 = V_2 -> V_256 ;
} else {
V_255 = F_100 ( int , 1 , div << 1 ) ;
}
goto V_265;
}
if ( V_2 -> V_256 ) {
for ( div = 1 ; div <= 1024 ; div ++ ) {
if ( ( V_2 -> V_266 * V_2 -> V_256 / div )
<= clock )
break;
}
if ( ( V_2 -> V_266 * V_2 -> V_256 / div ) <= clock ) {
V_257 = V_264 ;
V_255 = div ;
V_256 = V_2 -> V_256 ;
div -- ;
} else {
V_258 = true ;
}
}
if ( ! V_2 -> V_256 || V_258 ) {
if ( V_2 -> V_266 <= clock )
div = 1 ;
else {
for ( div = 2 ; div < V_267 ;
div += 2 ) {
if ( ( V_2 -> V_266 / div ) <= clock )
break;
}
}
V_255 = div ;
div >>= 1 ;
if ( ( V_2 -> V_52 & V_268 )
&& ! div && V_2 -> V_266 <= 25000000 )
div = 1 ;
}
} else {
for ( div = 1 ; div < V_269 ; div *= 2 ) {
if ( ( V_2 -> V_266 / div ) <= clock )
break;
}
V_255 = div ;
div >>= 1 ;
}
V_265:
if ( V_255 )
* V_254 = ( V_2 -> V_266 * V_256 ) / V_255 ;
V_257 |= ( div & V_270 ) << V_271 ;
V_257 |= ( ( div & V_272 ) >> V_273 )
<< V_274 ;
return V_257 ;
}
void F_101 ( struct V_1 * V_2 , T_6 V_257 )
{
T_3 V_49 ;
V_257 |= V_275 ;
F_78 ( V_2 , V_257 , V_14 ) ;
V_49 = F_18 ( F_19 () , 20 ) ;
while ( ! ( ( V_257 = F_4 ( V_2 , V_14 ) )
& V_276 ) ) {
if ( F_20 ( F_19 () , V_49 ) ) {
F_21 ( L_31 ,
F_22 ( V_2 -> V_41 ) ) ;
F_1 ( V_2 ) ;
return;
}
F_23 ( 10 ) ;
}
V_257 |= V_277 ;
F_78 ( V_2 , V_257 , V_14 ) ;
}
void F_102 ( struct V_1 * V_2 , unsigned int clock )
{
T_6 V_257 ;
V_2 -> V_41 -> V_254 = 0 ;
F_78 ( V_2 , 0 , V_14 ) ;
if ( clock == 0 )
return;
V_257 = F_99 ( V_2 , clock , & V_2 -> V_41 -> V_254 ) ;
F_101 ( V_2 , V_257 ) ;
}
static void F_103 ( struct V_1 * V_2 , unsigned char V_192 ,
unsigned short V_278 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
F_104 ( V_41 , V_41 -> V_279 . V_280 , V_278 ) ;
if ( V_192 != V_281 )
F_17 ( V_2 , V_282 , V_11 ) ;
else
F_17 ( V_2 , 0 , V_11 ) ;
}
void F_105 ( struct V_1 * V_2 , unsigned char V_192 ,
unsigned short V_278 )
{
T_2 V_283 = 0 ;
if ( V_192 != V_281 ) {
switch ( 1 << V_278 ) {
case V_284 :
V_283 = V_285 ;
break;
case V_286 :
case V_287 :
V_283 = V_288 ;
break;
case V_289 :
case V_290 :
V_283 = V_291 ;
break;
default:
F_106 ( 1 , L_32 ,
F_22 ( V_2 -> V_41 ) , V_278 ) ;
break;
}
}
if ( V_2 -> V_283 == V_283 )
return;
V_2 -> V_283 = V_283 ;
if ( V_283 == 0 ) {
F_17 ( V_2 , 0 , V_11 ) ;
if ( V_2 -> V_52 & V_53 )
F_14 ( V_2 ) ;
} else {
if ( ! ( V_2 -> V_39 & V_292 ) )
F_17 ( V_2 , 0 , V_11 ) ;
if ( V_2 -> V_39 & V_293 )
F_17 ( V_2 , V_283 , V_11 ) ;
V_283 |= V_282 ;
F_17 ( V_2 , V_283 , V_11 ) ;
if ( V_2 -> V_52 & V_53 )
F_12 ( V_2 ) ;
if ( V_2 -> V_39 & V_294 )
F_93 ( 10 ) ;
}
}
void F_107 ( struct V_1 * V_2 , unsigned char V_192 ,
unsigned short V_278 )
{
if ( F_108 ( V_2 -> V_41 -> V_279 . V_280 ) )
F_105 ( V_2 , V_192 , V_278 ) ;
else
F_103 ( V_2 , V_192 , V_278 ) ;
}
static void F_109 ( struct V_55 * V_41 , struct V_187 * V_188 )
{
struct V_1 * V_2 ;
int V_38 ;
unsigned long V_27 ;
V_2 = F_110 ( V_41 ) ;
V_38 = V_41 -> V_56 -> V_57 ( V_41 ) ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
F_39 ( V_2 ) ;
if ( F_80 ( V_2 , V_188 ) ) {
if ( V_188 -> V_206 ) {
V_188 -> V_35 -> V_206 = NULL ;
V_188 -> V_206 = NULL ;
}
}
if ( ! V_38 || V_2 -> V_27 & V_205 ) {
V_188 -> V_34 -> error = - V_295 ;
F_86 ( V_2 , V_188 ) ;
} else {
if ( V_188 -> V_189 && ! ( V_2 -> V_27 & V_200 ) )
F_88 ( V_2 , V_188 -> V_189 ) ;
else
F_88 ( V_2 , V_188 -> V_34 ) ;
}
F_111 () ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
void F_112 ( struct V_1 * V_2 , int V_296 )
{
T_2 V_82 ;
V_82 = F_5 ( V_2 , V_10 ) ;
if ( V_296 == V_297 ) {
V_82 &= ~ V_298 ;
if ( V_2 -> V_177 >= V_259 )
V_82 |= V_299 ;
} else {
if ( V_2 -> V_177 >= V_259 )
V_82 &= ~ V_299 ;
if ( V_296 == V_300 )
V_82 |= V_298 ;
else
V_82 &= ~ V_298 ;
}
F_17 ( V_2 , V_82 , V_10 ) ;
}
void F_113 ( struct V_1 * V_2 , unsigned V_239 )
{
T_6 V_301 ;
V_301 = F_4 ( V_2 , V_26 ) ;
V_301 &= ~ V_302 ;
if ( ( V_239 == V_247 ) ||
( V_239 == V_246 ) )
V_301 |= V_303 ;
else if ( V_239 == V_240 )
V_301 |= V_304 ;
else if ( V_239 == V_242 )
V_301 |= V_305 ;
else if ( V_239 == V_244 )
V_301 |= V_306 ;
else if ( ( V_239 == V_249 ) ||
( V_239 == V_250 ) )
V_301 |= V_307 ;
else if ( V_239 == V_252 )
V_301 |= V_308 ;
F_78 ( V_2 , V_301 , V_26 ) ;
}
void F_114 ( struct V_55 * V_41 , struct V_309 * V_81 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
T_2 V_82 ;
if ( V_81 -> V_310 == V_311 )
return;
if ( V_2 -> V_27 & V_205 ) {
if ( ! F_108 ( V_41 -> V_279 . V_280 ) &&
V_81 -> V_310 == V_281 )
F_104 ( V_41 , V_41 -> V_279 . V_280 , 0 ) ;
return;
}
if ( V_81 -> V_310 == V_281 ) {
F_9 ( V_2 , 0 , V_18 ) ;
F_27 ( V_2 ) ;
}
if ( V_2 -> V_177 >= V_259 &&
( V_81 -> V_310 == V_312 ) &&
! ( V_2 -> V_52 & V_313 ) )
F_115 ( V_2 , false ) ;
if ( ! V_81 -> clock || V_81 -> clock != V_2 -> clock ) {
V_2 -> V_56 -> V_314 ( V_2 , V_81 -> clock ) ;
V_2 -> clock = V_81 -> clock ;
if ( V_2 -> V_39 & V_315 &&
V_2 -> clock ) {
V_2 -> V_156 = V_2 -> V_41 -> V_254 ?
V_2 -> V_41 -> V_254 / 1000 :
V_2 -> clock / 1000 ;
V_2 -> V_41 -> V_316 =
V_2 -> V_56 -> V_317 ?
V_2 -> V_56 -> V_317 ( V_2 ) :
1 << 27 ;
V_2 -> V_41 -> V_316 /= V_2 -> V_156 ;
}
}
if ( V_2 -> V_56 -> V_318 )
V_2 -> V_56 -> V_318 ( V_2 , V_81 -> V_310 , V_81 -> V_278 ) ;
else
F_107 ( V_2 , V_81 -> V_310 , V_81 -> V_278 ) ;
if ( V_2 -> V_56 -> V_319 )
V_2 -> V_56 -> V_319 ( V_2 , V_81 -> V_310 ) ;
V_2 -> V_56 -> V_320 ( V_2 , V_81 -> V_321 ) ;
V_82 = F_5 ( V_2 , V_10 ) ;
if ( ( V_81 -> V_239 == V_322 ||
V_81 -> V_239 == V_323 ||
V_81 -> V_239 == V_252 ||
V_81 -> V_239 == V_247 ||
V_81 -> V_239 == V_250 ||
V_81 -> V_239 == V_244 ||
V_81 -> V_239 == V_246 ||
V_81 -> V_239 == V_249 ||
V_81 -> V_239 == V_242 )
&& ! ( V_2 -> V_39 & V_324 ) )
V_82 |= V_325 ;
else
V_82 &= ~ V_325 ;
if ( V_2 -> V_177 >= V_259 ) {
T_6 V_257 , V_301 ;
if ( ! V_2 -> V_61 ) {
F_17 ( V_2 , V_82 , V_10 ) ;
V_301 = F_4 ( V_2 , V_26 ) ;
V_301 &= ~ V_326 ;
if ( V_81 -> V_327 == V_328 )
V_301 |= V_329 ;
else if ( V_81 -> V_327 == V_330 )
V_301 |= V_331 ;
else if ( V_81 -> V_327 == V_332 )
V_301 |= V_333 ;
else if ( V_81 -> V_327 == V_334 )
V_301 |= V_335 ;
else {
F_98 ( L_33 ,
F_22 ( V_41 ) ) ;
V_301 |= V_331 ;
}
F_78 ( V_2 , V_301 , V_26 ) ;
} else {
V_257 = F_4 ( V_2 , V_14 ) ;
V_257 &= ~ V_277 ;
F_78 ( V_2 , V_257 , V_14 ) ;
F_17 ( V_2 , V_82 , V_10 ) ;
V_2 -> V_56 -> V_314 ( V_2 , V_2 -> clock ) ;
}
V_257 = F_4 ( V_2 , V_14 ) ;
V_257 &= ~ V_277 ;
F_78 ( V_2 , V_257 , V_14 ) ;
V_2 -> V_56 -> V_336 ( V_2 , V_81 -> V_239 ) ;
V_2 -> V_239 = V_81 -> V_239 ;
if ( ! ( V_2 -> V_52 & V_313 ) &&
( ( V_81 -> V_239 == V_240 ) ||
( V_81 -> V_239 == V_242 ) ||
( V_81 -> V_239 == V_244 ) ||
( V_81 -> V_239 == V_246 ) ||
( V_81 -> V_239 == V_249 ) ||
( V_81 -> V_239 == V_250 ) ) ) {
T_6 V_238 ;
F_115 ( V_2 , true ) ;
V_238 = F_97 ( V_2 ) ;
V_81 -> V_327 = ( V_238 & V_337 )
>> V_338 ;
}
V_2 -> V_56 -> V_314 ( V_2 , V_2 -> clock ) ;
} else
F_17 ( V_2 , V_82 , V_10 ) ;
if ( V_2 -> V_39 & V_339 )
F_24 ( V_2 , V_77 | V_78 ) ;
F_111 () ;
}
static int F_116 ( struct V_55 * V_41 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
int V_340 = F_117 ( V_41 ) ;
if ( V_2 -> V_27 & V_205 )
return 0 ;
if ( ! F_8 ( V_2 -> V_41 ) )
return 1 ;
if ( V_340 >= 0 )
return ! ! V_340 ;
if ( V_2 -> V_39 & V_40 )
return 1 ;
return ! ! ( F_3 ( V_2 , V_9 ) & V_42 ) ;
}
static int F_118 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
int V_341 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
if ( V_2 -> V_27 & V_205 )
V_341 = 0 ;
else if ( V_2 -> V_56 -> V_342 )
V_341 = V_2 -> V_56 -> V_342 ( V_2 ) ;
else
V_341 = ! ( F_3 ( V_2 , V_9 )
& V_343 ) ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
return V_2 -> V_39 & V_344 ?
! V_341 : V_341 ;
}
static int F_119 ( struct V_55 * V_41 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
int V_134 , V_345 ;
if ( ! ( V_2 -> V_39 & V_346 ) )
return F_118 ( V_2 ) ;
V_345 = 0 ;
for ( V_134 = 0 ; V_134 < V_347 ; V_134 ++ ) {
if ( F_118 ( V_2 ) ) {
if ( ++ V_345 > V_347 / 2 )
return 1 ;
}
F_120 ( 30 ) ;
}
return 0 ;
}
static void F_121 ( struct V_55 * V_41 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
if ( V_2 -> V_56 && V_2 -> V_56 -> V_348 )
V_2 -> V_56 -> V_348 ( V_2 ) ;
}
static void F_122 ( struct V_1 * V_2 , int V_37 )
{
if ( ! ( V_2 -> V_27 & V_205 ) ) {
if ( V_37 )
V_2 -> V_43 |= V_349 ;
else
V_2 -> V_43 &= ~ V_349 ;
F_9 ( V_2 , V_2 -> V_43 , V_17 ) ;
F_9 ( V_2 , V_2 -> V_43 , V_18 ) ;
F_111 () ;
}
}
void F_123 ( struct V_55 * V_41 , int V_37 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
unsigned long V_27 ;
if ( V_37 )
F_13 ( V_2 -> V_41 -> V_47 ) ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
if ( V_37 )
V_2 -> V_27 |= V_350 ;
else
V_2 -> V_27 &= ~ V_350 ;
F_122 ( V_2 , V_37 ) ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
if ( ! V_37 )
F_15 ( V_2 -> V_41 -> V_47 ) ;
}
int F_124 ( struct V_55 * V_41 ,
struct V_309 * V_81 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
T_6 V_82 ;
int V_351 ;
if ( V_2 -> V_177 < V_259 )
return 0 ;
V_82 = F_4 ( V_2 , V_26 ) ;
switch ( V_81 -> V_352 ) {
case V_353 :
if ( ! ( V_2 -> V_27 & V_354 ) )
return - V_223 ;
V_82 &= ~ V_355 ;
F_78 ( V_2 , V_82 , V_26 ) ;
if ( ! F_108 ( V_41 -> V_279 . V_356 ) ) {
V_351 = F_125 ( V_41 , V_81 ) ;
if ( V_351 ) {
F_98 ( L_34 ,
F_22 ( V_41 ) ) ;
return - V_219 ;
}
}
F_126 ( 5000 , 5500 ) ;
V_82 = F_4 ( V_2 , V_26 ) ;
if ( ! ( V_82 & V_355 ) )
return 0 ;
F_98 ( L_35 ,
F_22 ( V_41 ) ) ;
return - V_357 ;
case V_358 :
if ( ! ( V_2 -> V_27 & V_359 ) )
return - V_223 ;
if ( ! F_108 ( V_41 -> V_279 . V_356 ) ) {
V_351 = F_125 ( V_41 , V_81 ) ;
if ( V_351 ) {
F_98 ( L_36 ,
F_22 ( V_41 ) ) ;
return - V_219 ;
}
}
V_82 |= V_355 ;
F_78 ( V_2 , V_82 , V_26 ) ;
if ( V_2 -> V_56 -> V_360 )
V_2 -> V_56 -> V_360 ( V_2 ) ;
V_82 = F_4 ( V_2 , V_26 ) ;
if ( V_82 & V_355 )
return 0 ;
F_98 ( L_37 ,
F_22 ( V_41 ) ) ;
return - V_357 ;
case V_361 :
if ( ! ( V_2 -> V_27 & V_362 ) )
return - V_223 ;
if ( ! F_108 ( V_41 -> V_279 . V_356 ) ) {
V_351 = F_125 ( V_41 , V_81 ) ;
if ( V_351 ) {
F_98 ( L_38 ,
F_22 ( V_41 ) ) ;
return - V_219 ;
}
}
return 0 ;
default:
return 0 ;
}
}
static int F_127 ( struct V_55 * V_41 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
T_1 V_363 ;
V_363 = F_3 ( V_2 , V_9 ) ;
return ! ( V_363 & V_364 ) ;
}
static int F_128 ( struct V_55 * V_41 , struct V_309 * V_81 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
unsigned long V_27 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
V_2 -> V_27 |= V_365 ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
return 0 ;
}
static void F_129 ( struct V_1 * V_2 )
{
T_6 V_82 ;
V_82 = F_4 ( V_2 , V_26 ) ;
V_82 |= V_366 ;
if ( V_2 -> V_52 & V_367 )
V_82 |= V_368 ;
F_78 ( V_2 , V_82 , V_26 ) ;
F_9 ( V_2 , V_159 , V_17 ) ;
F_9 ( V_2 , V_159 , V_18 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_2 -> V_43 , V_17 ) ;
F_9 ( V_2 , V_2 -> V_43 , V_18 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
T_6 V_82 ;
V_82 = F_4 ( V_2 , V_26 ) ;
V_82 &= ~ V_368 ;
V_82 &= ~ V_366 ;
F_78 ( V_2 , V_82 , V_26 ) ;
}
static void F_132 ( struct V_1 * V_2 , T_1 V_157 )
{
F_131 ( V_2 ) ;
F_24 ( V_2 , V_77 ) ;
F_24 ( V_2 , V_78 ) ;
F_130 ( V_2 ) ;
F_133 ( V_2 -> V_41 , V_157 ) ;
}
static void F_134 ( struct V_1 * V_2 , T_1 V_157 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
struct V_33 V_34 = {} ;
struct V_187 V_188 = {} ;
unsigned long V_27 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
V_34 . V_157 = V_157 ;
V_34 . V_27 = V_369 | V_370 ;
V_34 . V_188 = & V_188 ;
V_188 . V_34 = & V_34 ;
if ( V_34 . V_157 == V_234 &&
V_41 -> V_81 . V_321 == V_297 )
F_78 ( V_2 , F_79 ( 7 , 128 ) , V_5 ) ;
else
F_78 ( V_2 , F_79 ( 7 , 64 ) , V_5 ) ;
F_78 ( V_2 , V_203 , V_8 ) ;
F_88 ( V_2 , & V_34 ) ;
V_2 -> V_34 = NULL ;
F_91 ( V_2 , & V_188 ) ;
V_2 -> V_371 = 0 ;
F_111 () ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
F_135 ( V_2 -> V_372 , ( V_2 -> V_371 == 1 ) ,
F_136 ( 50 ) ) ;
}
static void F_137 ( struct V_1 * V_2 , T_1 V_157 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_373 ; V_134 ++ ) {
T_6 V_82 ;
F_134 ( V_2 , V_157 ) ;
if ( ! V_2 -> V_371 ) {
F_138 ( L_39 ,
F_22 ( V_2 -> V_41 ) ) ;
F_132 ( V_2 , V_157 ) ;
return;
}
V_82 = F_4 ( V_2 , V_26 ) ;
if ( ! ( V_82 & V_366 ) ) {
if ( V_82 & V_368 )
return;
break;
}
if ( V_2 -> V_374 > 0 )
F_93 ( V_2 -> V_374 ) ;
}
F_138 ( L_40 ,
F_22 ( V_2 -> V_41 ) ) ;
F_131 ( V_2 ) ;
}
int F_139 ( struct V_55 * V_41 , T_1 V_157 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
int V_375 = 0 ;
unsigned int V_376 = 0 ;
bool V_377 ;
V_377 = V_2 -> V_27 & V_365 ;
if ( V_2 -> V_72 == V_378 )
V_376 = V_2 -> V_376 ;
switch ( V_2 -> V_239 ) {
case V_252 :
V_375 = - V_223 ;
goto V_90;
case V_247 :
if ( V_377 )
V_376 = 0 ;
break;
case V_246 :
case V_249 :
break;
case V_244 :
if ( V_2 -> V_27 & V_379 )
break;
default:
goto V_90;
}
if ( V_2 -> V_56 -> V_380 ) {
V_375 = V_2 -> V_56 -> V_380 ( V_2 , V_157 ) ;
goto V_90;
}
V_2 -> V_41 -> V_381 = V_376 ;
if ( V_2 -> V_374 < 0 )
V_2 -> V_374 = V_157 == V_233 ;
F_129 ( V_2 ) ;
F_137 ( V_2 , V_157 ) ;
F_130 ( V_2 ) ;
V_90:
V_2 -> V_27 &= ~ V_365 ;
return V_375 ;
}
static void F_115 ( struct V_1 * V_2 , bool V_37 )
{
if ( V_2 -> V_177 < V_259 )
return;
if ( V_2 -> V_61 != V_37 ) {
T_6 V_82 = F_4 ( V_2 , V_26 ) ;
if ( V_37 )
V_82 |= V_382 ;
else
V_82 &= ~ V_382 ;
F_78 ( V_2 , V_82 , V_26 ) ;
if ( V_37 )
V_2 -> V_27 |= V_383 ;
else
V_2 -> V_27 &= ~ V_383 ;
V_2 -> V_61 = V_37 ;
}
}
static void F_140 ( struct V_55 * V_41 , struct V_187 * V_188 ,
int V_375 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
struct V_114 * V_35 = V_188 -> V_35 ;
if ( V_35 -> V_117 != V_384 )
F_141 ( F_36 ( V_2 -> V_41 ) , V_35 -> V_119 , V_35 -> V_120 ,
F_53 ( V_35 ) ) ;
V_35 -> V_117 = V_384 ;
}
static void F_142 ( struct V_55 * V_41 , struct V_187 * V_188 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
V_188 -> V_35 -> V_117 = V_384 ;
if ( V_2 -> V_27 & V_164 )
F_51 ( V_2 , V_188 -> V_35 , V_118 ) ;
}
static inline bool F_143 ( struct V_1 * V_2 )
{
return V_2 -> V_34 || V_2 -> V_211 ;
}
static void F_144 ( struct V_1 * V_2 , int V_375 )
{
if ( V_2 -> V_211 ) {
V_2 -> V_211 -> error = V_375 ;
F_86 ( V_2 , V_2 -> V_211 -> V_188 ) ;
}
if ( V_2 -> V_34 ) {
V_2 -> V_34 -> error = V_375 ;
F_86 ( V_2 , V_2 -> V_34 -> V_188 ) ;
}
}
static void F_145 ( struct V_55 * V_41 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
unsigned long V_27 ;
int V_38 ;
if ( V_2 -> V_56 -> V_385 )
V_2 -> V_56 -> V_385 ( V_2 ) ;
V_38 = V_41 -> V_56 -> V_57 ( V_41 ) ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
if ( F_143 ( V_2 ) && ! V_38 ) {
F_21 ( L_41 ,
F_22 ( V_2 -> V_41 ) ) ;
F_21 ( L_42 ,
F_22 ( V_2 -> V_41 ) ) ;
F_24 ( V_2 , V_77 ) ;
F_24 ( V_2 , V_78 ) ;
F_144 ( V_2 , - V_295 ) ;
}
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
static bool F_146 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
struct V_187 * V_188 ;
int V_134 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
for ( V_134 = 0 ; V_134 < V_208 ; V_134 ++ ) {
V_188 = V_2 -> V_209 [ V_134 ] ;
if ( V_188 )
break;
}
if ( ! V_188 ) {
F_33 ( & V_2 -> V_88 , V_27 ) ;
return true ;
}
F_91 ( V_2 , V_188 ) ;
if ( V_2 -> V_27 & V_164 ) {
struct V_114 * V_35 = V_188 -> V_35 ;
if ( V_35 && V_35 -> V_117 == V_175 ) {
F_141 ( F_36 ( V_2 -> V_41 ) , V_35 -> V_119 , V_35 -> V_120 ,
F_53 ( V_35 ) ) ;
V_35 -> V_117 = V_384 ;
}
}
if ( F_83 ( V_2 , V_188 ) ) {
if ( V_2 -> V_34 || V_2 -> V_211 ) {
F_33 ( & V_2 -> V_88 , V_27 ) ;
return true ;
}
if ( V_2 -> V_39 & V_386 )
V_2 -> V_56 -> V_314 ( V_2 , V_2 -> clock ) ;
F_24 ( V_2 , V_77 ) ;
F_24 ( V_2 , V_78 ) ;
V_2 -> V_212 = false ;
}
if ( ! F_143 ( V_2 ) )
F_40 ( V_2 ) ;
V_2 -> V_209 [ V_134 ] = NULL ;
F_111 () ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
F_147 ( V_2 -> V_41 , V_188 ) ;
return false ;
}
static void F_148 ( unsigned long V_387 )
{
struct V_1 * V_2 = (struct V_1 * ) V_387 ;
while ( ! F_146 ( V_2 ) )
;
}
static void F_149 ( unsigned long V_35 )
{
struct V_1 * V_2 ;
unsigned long V_27 ;
V_2 = (struct V_1 * ) V_35 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
if ( V_2 -> V_34 && ! F_6 ( V_2 -> V_34 ) ) {
F_21 ( L_43 ,
F_22 ( V_2 -> V_41 ) ) ;
F_1 ( V_2 ) ;
V_2 -> V_34 -> error = - V_388 ;
F_86 ( V_2 , V_2 -> V_34 -> V_188 ) ;
}
F_111 () ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
static void F_150 ( unsigned long V_35 )
{
struct V_1 * V_2 ;
unsigned long V_27 ;
V_2 = (struct V_1 * ) V_35 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
if ( V_2 -> V_35 || V_2 -> V_211 ||
( V_2 -> V_34 && F_6 ( V_2 -> V_34 ) ) ) {
F_21 ( L_44 ,
F_22 ( V_2 -> V_41 ) ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_35 ) {
V_2 -> V_35 -> error = - V_388 ;
F_87 ( V_2 ) ;
} else if ( V_2 -> V_211 ) {
V_2 -> V_211 -> error = - V_388 ;
F_86 ( V_2 , V_2 -> V_211 -> V_188 ) ;
} else {
V_2 -> V_34 -> error = - V_388 ;
F_86 ( V_2 , V_2 -> V_34 -> V_188 ) ;
}
}
F_111 () ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
static void F_151 ( struct V_1 * V_2 , T_1 V_389 )
{
if ( ! V_2 -> V_34 ) {
if ( V_2 -> V_212 )
return;
F_21 ( L_45 ,
F_22 ( V_2 -> V_41 ) , ( unsigned ) V_389 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_389 & ( V_69 | V_68 |
V_67 | V_66 ) ) {
if ( V_389 & V_69 )
V_2 -> V_34 -> error = - V_388 ;
else
V_2 -> V_34 -> error = - V_390 ;
if ( V_2 -> V_34 -> V_35 &&
( V_389 & ( V_68 | V_69 ) ) ==
V_68 ) {
V_2 -> V_34 = NULL ;
return;
}
F_86 ( V_2 , V_2 -> V_34 -> V_188 ) ;
return;
}
if ( V_389 & V_71 )
F_95 ( V_2 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
void * V_125 = V_2 -> V_135 ;
F_1 ( V_2 ) ;
while ( true ) {
struct V_126 * V_127 = V_125 ;
if ( V_2 -> V_27 & V_29 )
F_42 ( L_46 ,
V_125 , F_153 ( V_127 -> V_129 ) ,
F_153 ( V_127 -> V_128 ) ,
F_154 ( V_127 -> V_97 ) ,
F_154 ( V_127 -> V_34 ) ) ;
else
F_42 ( L_47 ,
V_125 , F_153 ( V_127 -> V_128 ) ,
F_154 ( V_127 -> V_97 ) ,
F_154 ( V_127 -> V_34 ) ) ;
V_125 += V_2 -> V_141 ;
if ( V_127 -> V_34 & F_60 ( V_131 ) )
break;
}
}
static void F_152 ( struct V_1 * V_2 ) { }
static void F_155 ( struct V_1 * V_2 , T_1 V_389 )
{
T_1 V_391 ;
if ( V_389 & V_159 ) {
V_391 = F_156 ( F_4 ( V_2 , V_23 ) ) ;
if ( V_391 == V_233 ||
V_391 == V_234 ) {
V_2 -> V_371 = 1 ;
F_157 ( & V_2 -> V_372 ) ;
return;
}
}
if ( ! V_2 -> V_35 ) {
struct V_33 * V_211 = V_2 -> V_211 ;
if ( V_211 && ( V_211 -> V_27 & V_36 ) ) {
if ( V_389 & V_65 ) {
V_2 -> V_211 = NULL ;
V_211 -> error = - V_388 ;
F_86 ( V_2 , V_211 -> V_188 ) ;
return;
}
if ( V_389 & V_70 ) {
V_2 -> V_211 = NULL ;
if ( V_2 -> V_34 == V_211 )
return;
F_86 ( V_2 , V_211 -> V_188 ) ;
return;
}
}
if ( V_2 -> V_212 )
return;
F_21 ( L_48 ,
F_22 ( V_2 -> V_41 ) , ( unsigned ) V_389 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_389 & V_65 )
V_2 -> V_35 -> error = - V_388 ;
else if ( V_389 & V_63 )
V_2 -> V_35 -> error = - V_390 ;
else if ( ( V_389 & V_64 ) &&
F_156 ( F_4 ( V_2 , V_23 ) )
!= V_392 )
V_2 -> V_35 -> error = - V_390 ;
else if ( V_389 & V_163 ) {
F_21 ( L_49 , F_22 ( V_2 -> V_41 ) ) ;
F_152 ( V_2 ) ;
V_2 -> V_35 -> error = - V_219 ;
if ( V_2 -> V_56 -> V_393 )
V_2 -> V_56 -> V_393 ( V_2 , V_389 ) ;
}
if ( V_2 -> V_35 -> error )
F_87 ( V_2 ) ;
else {
if ( V_389 & ( V_159 | V_160 ) )
F_50 ( V_2 ) ;
if ( V_389 & V_162 ) {
T_1 V_394 , V_395 ;
V_394 = F_65 ( V_2 -> V_35 -> V_119 ) ;
V_395 = V_394 + V_2 -> V_35 -> V_168 ;
V_395 = ( V_395 &
~ ( V_396 - 1 ) ) +
V_396 ;
V_2 -> V_35 -> V_168 = V_395 - V_394 ;
F_42 ( L_50 ,
V_394 , V_2 -> V_35 -> V_168 , V_395 ) ;
F_9 ( V_2 , V_395 , V_3 ) ;
}
if ( V_389 & V_70 ) {
if ( V_2 -> V_34 == V_2 -> V_211 ) {
V_2 -> V_167 = 1 ;
} else {
F_87 ( V_2 ) ;
}
}
}
}
static T_7 F_158 ( int V_397 , void * V_398 )
{
T_7 V_399 = V_400 ;
struct V_1 * V_2 = V_398 ;
T_1 V_389 , V_48 , V_401 = 0 ;
int V_402 = 16 ;
F_159 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_89 && ! F_160 ( V_2 ) ) {
F_161 ( & V_2 -> V_88 ) ;
return V_400 ;
}
V_389 = F_3 ( V_2 , V_16 ) ;
if ( ! V_389 || V_389 == 0xffffffff ) {
V_399 = V_400 ;
goto V_90;
}
do {
F_42 ( L_51 , V_389 ) ;
if ( V_2 -> V_56 -> V_397 ) {
V_389 = V_2 -> V_56 -> V_397 ( V_2 , V_389 ) ;
if ( ! V_389 )
goto V_403;
}
V_48 = V_389 & ( V_404 | V_405 |
V_62 ) ;
F_9 ( V_2 , V_48 , V_16 ) ;
if ( V_389 & ( V_45 | V_44 ) ) {
T_1 V_38 = F_3 ( V_2 , V_9 ) &
V_42 ;
V_2 -> V_43 &= ~ ( V_45 |
V_44 ) ;
V_2 -> V_43 |= V_38 ? V_44 :
V_45 ;
F_9 ( V_2 , V_2 -> V_43 , V_17 ) ;
F_9 ( V_2 , V_2 -> V_43 , V_18 ) ;
F_9 ( V_2 , V_389 & ( V_45 |
V_44 ) , V_16 ) ;
V_2 -> V_406 |= V_389 & ( V_45 |
V_44 ) ;
V_399 = V_407 ;
}
if ( V_389 & V_404 )
F_151 ( V_2 , V_389 & V_404 ) ;
if ( V_389 & V_405 )
F_155 ( V_2 , V_389 & V_405 ) ;
if ( V_389 & V_62 )
F_21 ( L_52 ,
F_22 ( V_2 -> V_41 ) ) ;
if ( V_389 & V_75 )
F_162 ( V_2 -> V_41 ) ;
if ( ( V_389 & V_349 ) &&
( V_2 -> V_43 & V_349 ) ) {
F_122 ( V_2 , false ) ;
V_2 -> V_406 |= V_349 ;
V_399 = V_407 ;
}
V_389 &= ~ ( V_45 | V_44 |
V_404 | V_405 |
V_408 | V_62 |
V_75 | V_349 ) ;
if ( V_389 ) {
V_401 |= V_389 ;
F_9 ( V_2 , V_389 , V_16 ) ;
}
V_403:
if ( V_399 == V_400 )
V_399 = V_409 ;
V_389 = F_3 ( V_2 , V_16 ) ;
} while ( V_389 && -- V_402 );
V_90:
F_161 ( & V_2 -> V_88 ) ;
if ( V_401 ) {
F_21 ( L_53 ,
F_22 ( V_2 -> V_41 ) , V_401 ) ;
F_1 ( V_2 ) ;
}
return V_399 ;
}
static T_7 F_163 ( int V_397 , void * V_398 )
{
struct V_1 * V_2 = V_398 ;
unsigned long V_27 ;
T_1 V_410 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
V_410 = V_2 -> V_406 ;
V_2 -> V_406 = 0 ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
if ( V_410 & ( V_45 | V_44 ) ) {
struct V_55 * V_41 = V_2 -> V_41 ;
V_41 -> V_56 -> V_385 ( V_41 ) ;
F_164 ( V_41 , F_136 ( 200 ) ) ;
}
if ( V_410 & V_349 ) {
F_165 ( V_2 -> V_41 ) ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
if ( V_2 -> V_27 & V_350 )
F_122 ( V_2 , true ) ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
return V_410 ? V_409 : V_400 ;
}
void F_166 ( struct V_1 * V_2 )
{
T_2 V_155 ;
T_2 V_48 = V_411 | V_412
| V_413 ;
T_1 V_414 = V_45 | V_44 |
V_349 ;
V_155 = F_5 ( V_2 , V_13 ) ;
V_155 |= V_48 ;
if ( V_2 -> V_39 & V_40 ) {
V_155 &= ~ ( V_411 | V_412 ) ;
V_414 &= ~ ( V_45 | V_44 ) ;
}
F_17 ( V_2 , V_155 , V_13 ) ;
F_9 ( V_2 , V_414 , V_17 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
T_2 V_155 ;
T_2 V_48 = V_411 | V_412
| V_413 ;
V_155 = F_5 ( V_2 , V_13 ) ;
V_155 &= ~ V_48 ;
F_17 ( V_2 , V_155 , V_13 ) ;
}
int F_168 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_169 ( V_2 -> V_41 ) ;
if ( ! F_170 ( F_36 ( V_2 -> V_41 ) ) ) {
V_2 -> V_43 = 0 ;
F_9 ( V_2 , 0 , V_17 ) ;
F_9 ( V_2 , 0 , V_18 ) ;
F_171 ( V_2 -> V_397 , V_2 ) ;
} else {
F_166 ( V_2 ) ;
F_172 ( V_2 -> V_397 ) ;
}
return 0 ;
}
int F_173 ( struct V_1 * V_2 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
int V_351 = 0 ;
if ( V_2 -> V_27 & ( V_59 | V_28 ) ) {
if ( V_2 -> V_56 -> V_60 )
V_2 -> V_56 -> V_60 ( V_2 ) ;
}
if ( ( V_2 -> V_41 -> V_415 & V_416 ) &&
( V_2 -> V_52 & V_417 ) ) {
F_26 ( V_2 , 0 ) ;
V_2 -> V_283 = 0 ;
V_2 -> clock = 0 ;
V_41 -> V_56 -> V_80 ( V_41 , & V_41 -> V_81 ) ;
} else {
F_26 ( V_2 , ( V_2 -> V_41 -> V_415 & V_416 ) ) ;
F_111 () ;
}
if ( ! F_170 ( F_36 ( V_2 -> V_41 ) ) ) {
V_351 = F_174 ( V_2 -> V_397 , F_158 ,
F_163 , V_418 ,
F_22 ( V_2 -> V_41 ) , V_2 ) ;
if ( V_351 )
return V_351 ;
} else {
F_167 ( V_2 ) ;
F_175 ( V_2 -> V_397 ) ;
}
F_10 ( V_2 ) ;
return V_351 ;
}
int F_176 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
F_169 ( V_2 -> V_41 ) ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
V_2 -> V_43 &= V_349 ;
F_9 ( V_2 , V_2 -> V_43 , V_17 ) ;
F_9 ( V_2 , V_2 -> V_43 , V_18 ) ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
F_177 ( V_2 -> V_397 ) ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
V_2 -> V_89 = true ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
return 0 ;
}
int F_178 ( struct V_1 * V_2 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
unsigned long V_27 ;
int V_419 = V_2 -> V_27 ;
if ( V_419 & ( V_59 | V_28 ) ) {
if ( V_2 -> V_56 -> V_60 )
V_2 -> V_56 -> V_60 ( V_2 ) ;
}
F_26 ( V_2 , 0 ) ;
if ( V_41 -> V_81 . V_310 != V_311 ) {
V_2 -> V_283 = 0 ;
V_2 -> clock = 0 ;
V_41 -> V_56 -> V_420 ( V_41 , & V_41 -> V_81 ) ;
V_41 -> V_56 -> V_80 ( V_41 , & V_41 -> V_81 ) ;
if ( ( V_419 & V_383 ) &&
! ( V_2 -> V_52 & V_313 ) ) {
F_32 ( & V_2 -> V_88 , V_27 ) ;
F_115 ( V_2 , true ) ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
if ( ( V_41 -> V_421 & V_422 ) &&
V_41 -> V_56 -> V_423 )
V_41 -> V_56 -> V_423 ( V_41 , & V_41 -> V_81 ) ;
}
F_32 ( & V_2 -> V_88 , V_27 ) ;
V_2 -> V_89 = false ;
if ( V_2 -> V_27 & V_350 )
F_122 ( V_2 , true ) ;
F_10 ( V_2 ) ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
return 0 ;
}
void F_179 ( struct V_55 * V_41 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
unsigned long V_27 ;
T_2 V_82 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
V_82 = F_5 ( V_2 , V_10 ) ;
V_82 &= ~ V_179 ;
if ( V_2 -> V_27 & V_29 )
V_82 |= V_180 ;
else
V_82 |= V_181 ;
F_17 ( V_2 , V_82 , V_10 ) ;
F_78 ( V_2 , F_79 ( V_186 , 512 ) ,
V_5 ) ;
F_17 ( V_2 , 0xE , V_15 ) ;
V_2 -> V_43 = V_2 -> V_424 ;
F_9 ( V_2 , V_2 -> V_43 , V_17 ) ;
F_9 ( V_2 , V_2 -> V_43 , V_18 ) ;
V_2 -> V_79 = true ;
F_180 ( L_54 ,
F_22 ( V_41 ) , V_2 -> V_43 ,
F_3 ( V_2 , V_16 ) ) ;
F_111 () ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
void F_181 ( struct V_55 * V_41 , bool V_425 )
{
struct V_1 * V_2 = F_110 ( V_41 ) ;
unsigned long V_27 ;
F_32 ( & V_2 -> V_88 , V_27 ) ;
F_25 ( V_2 ) ;
V_2 -> V_79 = false ;
if ( V_425 ) {
F_24 ( V_2 , V_77 ) ;
F_24 ( V_2 , V_78 ) ;
}
F_180 ( L_55 ,
F_22 ( V_41 ) , V_2 -> V_43 ,
F_3 ( V_2 , V_16 ) ) ;
F_111 () ;
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
bool F_182 ( struct V_1 * V_2 , T_1 V_389 , int * V_426 ,
int * V_427 )
{
T_1 V_48 ;
if ( ! V_2 -> V_79 )
return false ;
if ( V_389 & ( V_66 | V_67 | V_68 ) )
* V_426 = - V_390 ;
else if ( V_389 & V_69 )
* V_426 = - V_388 ;
else
* V_426 = 0 ;
if ( V_389 & ( V_63 | V_64 ) )
* V_427 = - V_390 ;
else if ( V_389 & V_65 )
* V_427 = - V_388 ;
else if ( V_389 & V_163 )
* V_427 = - V_219 ;
else
* V_427 = 0 ;
V_48 = V_389 & V_2 -> V_424 ;
F_9 ( V_2 , V_48 , V_16 ) ;
if ( V_389 & V_62 )
F_21 ( L_52 ,
F_22 ( V_2 -> V_41 ) ) ;
V_389 &= ~ ( V_2 -> V_424 | V_408 ) ;
if ( V_389 ) {
F_9 ( V_2 , V_389 , V_16 ) ;
F_21 ( L_56 ,
F_22 ( V_2 -> V_41 ) , V_389 ) ;
F_1 ( V_2 ) ;
}
return true ;
}
struct V_1 * F_183 ( struct V_428 * V_429 ,
T_4 V_430 )
{
struct V_55 * V_41 ;
struct V_1 * V_2 ;
F_67 ( V_429 == NULL ) ;
V_41 = F_184 ( sizeof( struct V_1 ) + V_430 , V_429 ) ;
if ( ! V_41 )
return F_185 ( - V_431 ) ;
V_2 = F_110 ( V_41 ) ;
V_2 -> V_41 = V_41 ;
V_2 -> V_432 = V_433 ;
V_41 -> V_56 = & V_2 -> V_432 ;
V_2 -> V_27 = V_354 ;
V_2 -> V_424 = V_434 ;
V_2 -> V_435 = V_436 ;
V_2 -> V_374 = - 1 ;
return V_2 ;
}
static int F_186 ( struct V_1 * V_2 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
struct V_428 * V_429 = F_36 ( V_41 ) ;
int V_351 = - V_223 ;
if ( V_2 -> V_52 & V_437 )
V_2 -> V_27 &= ~ V_29 ;
if ( V_2 -> V_27 & V_29 ) {
V_351 = F_187 ( V_429 , F_188 ( 64 ) ) ;
if ( V_351 ) {
F_98 ( L_57 ,
F_22 ( V_41 ) ) ;
V_2 -> V_27 &= ~ V_29 ;
}
}
if ( V_351 ) {
V_351 = F_187 ( V_429 , F_188 ( 32 ) ) ;
if ( V_351 )
F_98 ( L_58 ,
F_22 ( V_41 ) ) ;
}
return V_351 ;
}
void F_189 ( struct V_1 * V_2 , T_6 * V_438 , T_1 * V_439 , T_1 * V_440 )
{
T_6 V_441 ;
V_130 V_442 = 0 ;
V_130 V_443 = 0 ;
if ( V_2 -> V_444 )
return;
V_2 -> V_444 = true ;
if ( V_445 )
V_2 -> V_39 = V_445 ;
if ( V_446 )
V_2 -> V_52 = V_446 ;
F_24 ( V_2 , V_51 ) ;
F_190 ( F_36 ( V_2 -> V_41 ) -> V_447 ,
L_59 , & V_442 ) ;
F_190 ( F_36 ( V_2 -> V_41 ) -> V_447 ,
L_60 , & V_443 ) ;
V_441 = V_438 ? * V_438 : F_4 ( V_2 , V_4 ) ;
V_2 -> V_177 = ( V_441 & V_448 ) >> V_449 ;
if ( V_2 -> V_39 & V_450 )
return;
if ( V_439 ) {
V_2 -> V_439 = * V_439 ;
} else {
V_2 -> V_439 = F_3 ( V_2 , V_21 ) ;
V_2 -> V_439 &= ~ F_191 ( V_442 ) ;
V_2 -> V_439 |= F_191 ( V_443 ) ;
}
if ( V_2 -> V_177 < V_259 )
return;
if ( V_440 ) {
V_2 -> V_440 = * V_440 ;
} else {
V_2 -> V_440 = F_3 ( V_2 , V_22 ) ;
V_2 -> V_440 &= ~ F_192 ( V_442 ) ;
V_2 -> V_440 |= F_192 ( V_443 ) ;
}
}
int F_193 ( struct V_1 * V_2 )
{
struct V_55 * V_41 ;
T_1 V_451 ;
unsigned int V_452 ;
unsigned int V_453 ;
T_1 V_266 ;
int V_351 ;
F_67 ( V_2 == NULL ) ;
if ( V_2 == NULL )
return - V_223 ;
V_41 = V_2 -> V_41 ;
V_351 = F_194 ( V_41 ) ;
if ( V_351 == - V_454 )
return V_351 ;
F_195 ( V_2 ) ;
V_453 = V_2 -> V_156 ;
if ( V_2 -> V_177 > V_259 ) {
F_21 ( L_61 ,
F_22 ( V_41 ) , V_2 -> V_177 ) ;
}
if ( V_2 -> V_39 & V_455 )
V_2 -> V_27 |= V_59 ;
else if ( ! ( V_2 -> V_439 & V_456 ) )
F_42 ( L_62 ) ;
else
V_2 -> V_27 |= V_59 ;
if ( ( V_2 -> V_39 & V_457 ) &&
( V_2 -> V_27 & V_59 ) ) {
F_42 ( L_63 ) ;
V_2 -> V_27 &= ~ V_59 ;
}
if ( ( V_2 -> V_177 >= V_178 ) &&
( V_2 -> V_439 & V_458 ) )
V_2 -> V_27 |= V_28 ;
if ( ( V_2 -> V_39 & V_459 ) &&
( V_2 -> V_27 & V_28 ) ) {
F_42 ( L_64 ) ;
V_2 -> V_27 &= ~ V_28 ;
}
if ( V_2 -> V_439 & V_460 )
V_2 -> V_27 |= V_29 ;
if ( V_2 -> V_27 & ( V_59 | V_28 ) ) {
V_351 = F_186 ( V_2 ) ;
if ( ! V_351 && V_2 -> V_56 -> V_60 )
V_351 = V_2 -> V_56 -> V_60 ( V_2 ) ;
if ( V_351 ) {
F_98 ( L_65 ,
F_22 ( V_41 ) ) ;
V_2 -> V_27 &= ~ ( V_59 | V_28 ) ;
V_351 = 0 ;
}
}
if ( V_2 -> V_27 & V_29 )
V_2 -> V_27 &= ~ V_59 ;
if ( V_2 -> V_27 & V_28 ) {
T_5 V_461 ;
void * V_101 ;
if ( V_2 -> V_27 & V_29 ) {
V_2 -> V_142 = ( V_462 * 2 + 1 ) *
V_463 ;
V_2 -> V_141 = V_463 ;
} else {
V_2 -> V_142 = ( V_462 * 2 + 1 ) *
V_464 ;
V_2 -> V_141 = V_464 ;
}
V_2 -> V_465 = V_462 * V_137 ;
V_101 = F_196 ( F_36 ( V_41 ) , V_2 -> V_465 +
V_2 -> V_142 , & V_461 , V_466 ) ;
if ( ! V_101 ) {
F_98 ( L_66 ,
F_22 ( V_41 ) ) ;
V_2 -> V_27 &= ~ V_28 ;
} else if ( ( V_461 + V_2 -> V_465 ) &
( V_467 - 1 ) ) {
F_98 ( L_67 ,
F_22 ( V_41 ) ) ;
V_2 -> V_27 &= ~ V_28 ;
F_197 ( F_36 ( V_41 ) , V_2 -> V_465 +
V_2 -> V_142 , V_101 , V_461 ) ;
} else {
V_2 -> V_136 = V_101 ;
V_2 -> V_132 = V_461 ;
V_2 -> V_135 = V_101 + V_2 -> V_465 ;
V_2 -> V_176 = V_461 + V_2 -> V_465 ;
}
}
if ( ! ( V_2 -> V_27 & ( V_59 | V_28 ) ) ) {
V_2 -> V_468 = F_188 ( 64 ) ;
F_36 ( V_41 ) -> V_468 = & V_2 -> V_468 ;
}
if ( V_2 -> V_177 >= V_259 )
V_2 -> V_266 = ( V_2 -> V_439 & V_469 )
>> V_470 ;
else
V_2 -> V_266 = ( V_2 -> V_439 & V_471 )
>> V_470 ;
V_2 -> V_266 *= 1000000 ;
if ( V_2 -> V_266 == 0 || V_2 -> V_39 &
V_472 ) {
if ( ! V_2 -> V_56 -> V_473 ) {
F_21 ( L_68 ,
F_22 ( V_41 ) ) ;
V_351 = - V_474 ;
goto V_475;
}
V_2 -> V_266 = V_2 -> V_56 -> V_473 ( V_2 ) ;
}
V_2 -> V_256 = ( V_2 -> V_440 & V_476 ) >>
V_477 ;
if ( V_2 -> V_256 )
V_2 -> V_256 += 1 ;
V_266 = V_2 -> V_266 ;
if ( V_2 -> V_56 -> V_478 )
V_41 -> V_479 = V_2 -> V_56 -> V_478 ( V_2 ) ;
else if ( V_2 -> V_177 >= V_259 ) {
if ( V_2 -> V_256 ) {
V_41 -> V_479 = ( V_2 -> V_266 * V_2 -> V_256 ) / 1024 ;
V_266 = V_2 -> V_266 * V_2 -> V_256 ;
} else
V_41 -> V_479 = V_2 -> V_266 / V_267 ;
} else
V_41 -> V_479 = V_2 -> V_266 / V_269 ;
if ( ! V_41 -> V_480 || V_41 -> V_480 > V_266 )
V_41 -> V_480 = V_266 ;
if ( ! ( V_2 -> V_39 & V_315 ) ) {
V_2 -> V_156 = ( V_2 -> V_439 & V_481 ) >>
V_482 ;
if ( V_2 -> V_439 & V_483 )
V_2 -> V_156 *= 1000 ;
if ( V_2 -> V_156 == 0 ) {
if ( ! V_2 -> V_56 -> V_484 ) {
F_21 ( L_69 ,
F_22 ( V_41 ) ) ;
V_351 = - V_474 ;
goto V_475;
}
V_2 -> V_156 =
F_71 ( V_2 -> V_56 -> V_484 ( V_2 ) ,
1000 ) ;
}
if ( V_453 )
V_2 -> V_156 = V_453 ;
V_41 -> V_316 = V_2 -> V_56 -> V_317 ?
V_2 -> V_56 -> V_317 ( V_2 ) : 1 << 27 ;
V_41 -> V_316 /= V_2 -> V_156 ;
}
V_41 -> V_439 |= V_485 | V_486 | V_487 ;
V_41 -> V_421 |= V_488 ;
if ( V_2 -> V_39 & V_489 )
V_2 -> V_27 |= V_190 ;
if ( ( V_2 -> V_177 >= V_259 ) &&
( ( V_2 -> V_27 & V_28 ) ||
! ( V_2 -> V_27 & V_59 ) ) &&
! ( V_2 -> V_52 & V_490 ) ) {
V_2 -> V_27 |= V_200 ;
F_42 ( L_70 ) ;
} else {
F_42 ( L_71 ) ;
}
if ( ! ( V_2 -> V_39 & V_491 ) )
V_41 -> V_439 |= V_492 ;
if ( V_2 -> V_52 & V_493 )
V_41 -> V_439 &= ~ V_487 ;
if ( V_2 -> V_439 & V_494 )
V_41 -> V_439 |= V_495 | V_496 ;
if ( ( V_2 -> V_39 & V_40 ) &&
F_8 ( V_41 ) &&
F_117 ( V_2 -> V_41 ) < 0 )
V_41 -> V_439 |= V_497 ;
if ( ! F_108 ( V_41 -> V_279 . V_356 ) ) {
V_351 = F_198 ( V_41 -> V_279 . V_356 ) ;
if ( ! F_199 ( V_41 -> V_279 . V_356 , 1700000 ,
1950000 ) )
V_2 -> V_440 &= ~ ( V_498 |
V_499 |
V_500 ) ;
if ( V_351 ) {
F_98 ( L_72 ,
F_22 ( V_41 ) , V_351 ) ;
V_41 -> V_279 . V_356 = F_185 ( - V_223 ) ;
}
}
if ( V_2 -> V_52 & V_501 ) {
V_2 -> V_440 &= ~ ( V_498 | V_499 |
V_500 ) ;
}
if ( V_2 -> V_440 & ( V_498 | V_499 |
V_500 ) )
V_41 -> V_439 |= V_502 | V_503 ;
if ( V_2 -> V_440 & V_498 ) {
V_41 -> V_439 |= V_504 | V_505 ;
if ( ! ( V_2 -> V_52 & V_506 ) )
V_41 -> V_421 |= V_507 ;
} else if ( V_2 -> V_440 & V_499 ) {
V_41 -> V_439 |= V_505 ;
}
if ( V_2 -> V_52 & V_508 &&
( V_2 -> V_440 & V_509 ) )
V_41 -> V_421 |= V_510 ;
if ( ( V_41 -> V_421 & V_511 ) &&
( F_108 ( V_41 -> V_279 . V_356 ) ||
! F_199 ( V_41 -> V_279 . V_356 , 1100000 ,
1300000 ) ) )
V_41 -> V_421 &= ~ V_511 ;
if ( ( V_2 -> V_440 & V_500 ) &&
! ( V_2 -> V_52 & V_512 ) )
V_41 -> V_439 |= V_513 ;
if ( V_2 -> V_440 & V_514 )
V_2 -> V_27 |= V_379 ;
if ( V_2 -> V_440 & V_515 )
V_41 -> V_439 |= V_516 ;
if ( V_2 -> V_440 & V_517 )
V_41 -> V_439 |= V_518 ;
if ( V_2 -> V_440 & V_519 )
V_41 -> V_439 |= V_520 ;
V_2 -> V_376 = ( V_2 -> V_440 & V_521 ) >>
V_522 ;
if ( V_2 -> V_376 )
V_2 -> V_376 = 1 << ( V_2 -> V_376 - 1 ) ;
V_2 -> V_72 = ( V_2 -> V_440 & V_523 ) >>
V_524 ;
V_452 = 0 ;
V_451 = F_3 ( V_2 , V_24 ) ;
if ( ! V_451 && ! F_108 ( V_41 -> V_279 . V_280 ) ) {
int V_525 = F_200 ( V_41 -> V_279 . V_280 ) ;
if ( V_525 > 0 ) {
V_525 = V_525 / 1000 ;
V_525 = V_525 / V_526 ;
V_525 = F_201 ( T_1 , V_525 , V_527 ) ;
V_451 =
( V_525 << V_528 ) |
( V_525 << V_529 ) |
( V_525 << V_530 ) ;
}
}
if ( V_2 -> V_439 & V_531 ) {
V_452 |= V_289 | V_290 ;
V_41 -> V_532 = ( ( V_451 &
V_533 ) >>
V_528 ) *
V_526 ;
}
if ( V_2 -> V_439 & V_534 ) {
V_452 |= V_286 | V_287 ;
V_41 -> V_535 = ( ( V_451 &
V_536 ) >>
V_529 ) *
V_526 ;
}
if ( V_2 -> V_439 & V_537 ) {
V_452 |= V_284 ;
V_41 -> V_538 = ( ( V_451 &
V_539 ) >>
V_530 ) *
V_526 ;
}
if ( V_2 -> V_540 )
V_452 = V_2 -> V_540 ;
if ( V_41 -> V_452 )
V_452 = V_41 -> V_452 ;
V_41 -> V_452 = V_452 ;
V_41 -> V_541 = V_452 ;
if ( V_2 -> V_541 )
V_41 -> V_541 &= V_2 -> V_541 ;
V_41 -> V_542 = V_452 ;
if ( V_2 -> V_542 )
V_41 -> V_542 &= V_2 -> V_542 ;
else
V_41 -> V_542 &= ~ V_284 ;
V_41 -> V_543 = V_452 ;
if ( V_2 -> V_543 )
V_41 -> V_543 &= V_2 -> V_543 ;
if ( V_41 -> V_452 == 0 ) {
F_21 ( L_73 ,
F_22 ( V_41 ) ) ;
V_351 = - V_474 ;
goto V_544;
}
if ( ( V_41 -> V_439 & ( V_502 | V_503 |
V_505 | V_504 |
V_513 | V_545 ) ) ||
( V_41 -> V_421 & ( V_546 | V_547 ) ) )
V_2 -> V_27 |= V_359 ;
if ( V_41 -> V_421 & V_511 )
V_2 -> V_27 |= V_362 ;
F_202 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_27 & V_28 )
V_41 -> V_548 = V_462 ;
else if ( V_2 -> V_27 & V_59 )
V_41 -> V_548 = 1 ;
else
V_41 -> V_548 = V_462 ;
V_41 -> V_549 = 524288 ;
if ( V_2 -> V_27 & V_28 ) {
if ( V_2 -> V_39 & V_550 )
V_41 -> V_551 = 65535 ;
else
V_41 -> V_551 = 65536 ;
} else {
V_41 -> V_551 = V_41 -> V_549 ;
}
if ( V_2 -> V_39 & V_552 ) {
V_41 -> V_166 = 2 ;
} else {
V_41 -> V_166 = ( V_2 -> V_439 & V_553 ) >>
V_554 ;
if ( V_41 -> V_166 >= 3 ) {
F_98 ( L_74 ,
F_22 ( V_41 ) ) ;
V_41 -> V_166 = 0 ;
}
}
V_41 -> V_166 = 512 << V_41 -> V_166 ;
V_41 -> V_555 = ( V_2 -> V_39 & V_556 ) ? 1 : 65535 ;
return 0 ;
V_544:
if ( ! F_108 ( V_41 -> V_279 . V_356 ) )
F_203 ( V_41 -> V_279 . V_356 ) ;
V_475:
if ( V_2 -> V_136 )
F_197 ( F_36 ( V_41 ) , V_2 -> V_465 +
V_2 -> V_142 , V_2 -> V_136 ,
V_2 -> V_132 ) ;
V_2 -> V_135 = NULL ;
V_2 -> V_136 = NULL ;
return V_351 ;
}
void F_204 ( struct V_1 * V_2 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
if ( ! F_108 ( V_41 -> V_279 . V_356 ) )
F_203 ( V_41 -> V_279 . V_356 ) ;
if ( V_2 -> V_136 )
F_197 ( F_36 ( V_41 ) , V_2 -> V_465 +
V_2 -> V_142 , V_2 -> V_136 ,
V_2 -> V_132 ) ;
V_2 -> V_135 = NULL ;
V_2 -> V_136 = NULL ;
}
int F_205 ( struct V_1 * V_2 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
int V_351 ;
F_206 ( & V_2 -> V_210 ,
F_148 , ( unsigned long ) V_2 ) ;
F_207 ( & V_2 -> V_214 , F_149 , ( unsigned long ) V_2 ) ;
F_207 ( & V_2 -> V_213 , F_150 ,
( unsigned long ) V_2 ) ;
F_208 ( & V_2 -> V_372 ) ;
F_26 ( V_2 , 0 ) ;
V_351 = F_174 ( V_2 -> V_397 , F_158 , F_163 ,
V_418 , F_22 ( V_41 ) , V_2 ) ;
if ( V_351 ) {
F_21 ( L_75 ,
F_22 ( V_41 ) , V_2 -> V_397 , V_351 ) ;
goto V_557;
}
#ifdef F_209
F_1 ( V_2 ) ;
#endif
V_351 = F_34 ( V_2 ) ;
if ( V_351 ) {
F_21 ( L_76 ,
F_22 ( V_41 ) , V_351 ) ;
goto V_558;
}
F_111 () ;
V_351 = F_210 ( V_41 ) ;
if ( V_351 )
goto V_559;
F_138 ( L_77 ,
F_22 ( V_41 ) , V_2 -> V_560 , F_211 ( F_36 ( V_41 ) ) ,
( V_2 -> V_27 & V_28 ) ?
( V_2 -> V_27 & V_29 ) ? L_78 : L_79 :
( V_2 -> V_27 & V_59 ) ? L_80 : L_81 ) ;
F_10 ( V_2 ) ;
return 0 ;
V_559:
F_37 ( V_2 ) ;
V_558:
F_24 ( V_2 , V_51 ) ;
F_9 ( V_2 , 0 , V_17 ) ;
F_9 ( V_2 , 0 , V_18 ) ;
F_171 ( V_2 -> V_397 , V_2 ) ;
V_557:
F_212 ( & V_2 -> V_210 ) ;
return V_351 ;
}
int F_213 ( struct V_1 * V_2 )
{
int V_351 ;
V_351 = F_193 ( V_2 ) ;
if ( V_351 )
return V_351 ;
V_351 = F_205 ( V_2 ) ;
if ( V_351 )
goto V_561;
return 0 ;
V_561:
F_204 ( V_2 ) ;
return V_351 ;
}
void F_214 ( struct V_1 * V_2 , int V_562 )
{
struct V_55 * V_41 = V_2 -> V_41 ;
unsigned long V_27 ;
if ( V_562 ) {
F_32 ( & V_2 -> V_88 , V_27 ) ;
V_2 -> V_27 |= V_205 ;
if ( F_143 ( V_2 ) ) {
F_21 ( L_82
L_83 , F_22 ( V_41 ) ) ;
F_144 ( V_2 , - V_295 ) ;
}
F_33 ( & V_2 -> V_88 , V_27 ) ;
}
F_11 ( V_2 ) ;
F_215 ( V_41 ) ;
F_37 ( V_2 ) ;
if ( ! V_562 )
F_24 ( V_2 , V_51 ) ;
F_9 ( V_2 , 0 , V_17 ) ;
F_9 ( V_2 , 0 , V_18 ) ;
F_171 ( V_2 -> V_397 , V_2 ) ;
F_216 ( & V_2 -> V_214 ) ;
F_216 ( & V_2 -> V_213 ) ;
F_212 ( & V_2 -> V_210 ) ;
if ( ! F_108 ( V_41 -> V_279 . V_356 ) )
F_203 ( V_41 -> V_279 . V_356 ) ;
if ( V_2 -> V_136 )
F_197 ( F_36 ( V_41 ) , V_2 -> V_465 +
V_2 -> V_142 , V_2 -> V_136 ,
V_2 -> V_132 ) ;
V_2 -> V_135 = NULL ;
V_2 -> V_136 = NULL ;
}
void F_217 ( struct V_1 * V_2 )
{
F_218 ( V_2 -> V_41 ) ;
}
static int T_8 F_219 ( void )
{
F_138 ( V_563
L_84 ) ;
F_138 ( V_563 L_85 ) ;
return 0 ;
}
static void T_9 F_220 ( void )
{
}
