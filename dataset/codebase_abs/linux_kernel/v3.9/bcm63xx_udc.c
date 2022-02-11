static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
static inline struct V_8 * F_4 ( struct V_9 * V_10 )
{
return F_2 ( V_10 , struct V_8 , V_10 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_11 , T_1 V_12 )
{
return F_6 ( V_11 -> V_13 + V_12 ) ;
}
static inline void F_7 ( struct V_1 * V_11 , T_1 V_14 , T_1 V_12 )
{
F_8 ( V_14 , V_11 -> V_13 + V_12 ) ;
}
static inline T_1 F_9 ( struct V_1 * V_11 , T_1 V_12 )
{
return F_6 ( V_11 -> V_15 + V_12 ) ;
}
static inline void F_10 ( struct V_1 * V_11 , T_1 V_14 , T_1 V_12 )
{
F_8 ( V_14 , V_11 -> V_15 + V_12 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_11 , T_1 V_12 )
{
return F_6 ( V_11 -> V_15 + V_16 + V_12 ) ;
}
static inline void F_12 ( struct V_1 * V_11 , T_1 V_14 , T_1 V_12 )
{
F_8 ( V_14 , V_11 -> V_15 + V_16 + V_12 ) ;
}
static inline T_1 F_13 ( struct V_1 * V_11 , T_1 V_12 )
{
return F_6 ( V_11 -> V_15 + V_17 + V_12 ) ;
}
static inline void F_14 ( struct V_1 * V_11 , T_1 V_14 , T_1 V_12 )
{
F_8 ( V_14 , V_11 -> V_15 + V_17 + V_12 ) ;
}
static inline void F_15 ( struct V_1 * V_11 , bool V_18 )
{
if ( V_18 ) {
F_16 ( V_11 -> V_19 ) ;
F_16 ( V_11 -> V_20 ) ;
F_17 ( 10 ) ;
} else {
F_18 ( V_11 -> V_20 ) ;
F_18 ( V_11 -> V_19 ) ;
}
}
static void F_19 ( struct V_1 * V_11 , int V_21 )
{
T_1 V_14 = F_5 ( V_11 , V_22 ) ;
V_14 &= ~ V_23 ;
V_14 |= V_21 << V_24 ;
F_7 ( V_11 , V_14 , V_22 ) ;
}
static void F_20 ( struct V_1 * V_11 , struct V_5 * V_25 ,
bool V_26 )
{
T_1 V_14 ;
V_14 = V_27 |
( V_26 ? V_28 : 0 ) |
( V_25 -> V_29 << V_30 ) ;
F_7 ( V_11 , V_14 , V_31 ) ;
}
static void F_21 ( struct V_1 * V_11 )
{
int V_32 = V_11 -> V_4 . V_33 == V_34 ;
T_1 V_35 , V_14 , V_36 , V_37 ;
V_36 = V_37 = 0 ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 += 2 ) {
const struct V_39 * V_40 = & V_41 [ V_35 ] ;
const struct V_39 * V_42 = & V_41 [ V_35 + 1 ] ;
F_19 ( V_11 , V_35 >> 1 ) ;
V_14 = ( V_36 << V_43 ) |
( ( V_36 + V_40 -> V_44 - 1 ) <<
V_45 ) ;
V_36 += V_40 -> V_44 ;
F_7 ( V_11 , V_14 , V_46 ) ;
F_7 ( V_11 ,
V_32 ? V_40 -> V_47 : V_40 -> V_48 ,
V_49 ) ;
V_14 = ( V_37 << V_50 ) |
( ( V_37 + V_42 -> V_44 - 1 ) <<
V_51 ) ;
V_37 += V_42 -> V_44 ;
F_7 ( V_11 , V_14 , V_52 ) ;
F_7 ( V_11 ,
V_32 ? V_42 -> V_47 : V_42 -> V_48 ,
V_53 ) ;
F_5 ( V_11 , V_53 ) ;
}
}
static void F_22 ( struct V_1 * V_11 , int V_29 )
{
T_1 V_14 ;
F_19 ( V_11 , V_29 ) ;
V_14 = F_5 ( V_11 , V_22 ) ;
V_14 |= V_54 ;
F_7 ( V_11 , V_14 , V_22 ) ;
F_5 ( V_11 , V_22 ) ;
}
static void F_23 ( struct V_1 * V_11 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_55 ; V_35 ++ )
F_22 ( V_11 , V_35 ) ;
}
static void F_24 ( struct V_1 * V_11 )
{
T_1 V_35 , V_14 ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
const struct V_39 * V_56 = & V_41 [ V_35 ] ;
if ( V_56 -> V_29 < 0 )
continue;
F_19 ( V_11 , V_56 -> V_29 ) ;
V_14 = ( V_56 -> V_57 << V_58 ) |
( ( V_35 >> 1 ) << V_59 ) ;
F_7 ( V_11 , V_14 , V_60 ) ;
}
}
static void F_25 ( struct V_1 * V_11 )
{
T_1 V_14 , V_35 ;
F_7 ( V_11 , V_61 , V_62 ) ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
const struct V_39 * V_56 = & V_41 [ V_35 ] ;
int V_63 = V_11 -> V_4 . V_33 == V_34 ?
V_56 -> V_47 : V_56 -> V_48 ;
int V_21 = V_56 -> V_29 ;
V_11 -> V_64 [ V_35 ] . V_63 = V_63 ;
if ( V_21 < 0 )
continue;
V_11 -> V_25 [ V_21 ] . V_7 . V_65 = V_63 ;
V_14 = ( V_21 << V_66 ) |
( V_56 -> V_67 << V_68 ) |
( V_56 -> V_57 << V_69 ) |
( V_11 -> V_56 << V_70 ) |
( V_11 -> V_71 << V_72 ) |
( V_11 -> V_73 << V_74 ) |
( V_63 << V_75 ) ;
F_7 ( V_11 , V_14 , F_26 ( V_21 ) ) ;
}
}
static void F_27 ( struct V_1 * V_11 , struct V_76 * V_64 ,
struct V_8 * V_77 )
{
int V_78 = 1 , V_79 = 0 , V_80 = 0 ;
unsigned int V_81 = V_77 -> V_10 . V_82 - V_77 -> V_83 ;
const int V_84 = ! V_85 && ! V_64 -> V_86 ?
V_64 -> V_63 : V_87 ;
V_64 -> V_88 = 0 ;
V_77 -> V_89 = 0 ;
V_77 -> V_64 = V_64 ;
if ( ( V_81 % V_64 -> V_63 == 0 ) && V_81 && V_77 -> V_10 . V_90 )
V_80 = 1 ;
do {
struct V_91 * V_92 = V_64 -> V_93 ;
T_1 V_94 = 0 ;
unsigned int V_95 ;
if ( V_92 == V_64 -> V_96 ) {
V_94 |= V_97 ;
V_64 -> V_93 = V_64 -> V_98 ;
} else {
V_64 -> V_93 ++ ;
}
V_64 -> V_88 ++ ;
V_95 = F_28 ( int , V_81 , V_84 ) ;
if ( V_95 )
V_94 |= V_95 << V_99 ;
else
V_94 |= ( 1 << V_99 ) |
V_100 ;
V_94 |= V_101 ;
if ( V_78 ) {
V_94 |= V_102 ;
V_78 = 0 ;
}
if ( V_80 && ! V_81 )
V_80 = 0 ;
if ( ! V_64 -> V_86 || V_64 -> V_88 == V_64 -> V_103 ||
( V_95 == V_81 && ! V_80 ) ) {
V_79 = 1 ;
V_94 |= V_104 ;
}
V_92 -> V_105 = V_77 -> V_10 . V_106 + V_77 -> V_83 ;
F_29 () ;
V_92 -> V_107 = V_94 ;
V_77 -> V_83 += V_95 ;
V_77 -> V_89 += V_95 ;
V_81 -= V_95 ;
} while ( ! V_79 );
F_12 ( V_11 , V_108 ,
F_30 ( V_64 -> V_109 ) ) ;
}
static int F_31 ( struct V_1 * V_11 , struct V_76 * V_64 )
{
int V_35 , V_110 = 0 ;
struct V_91 * V_92 = V_64 -> V_111 ;
if ( ! V_64 -> V_88 )
return - V_112 ;
for ( V_35 = 0 ; V_35 < V_64 -> V_88 ; V_35 ++ ) {
T_1 V_94 ;
V_94 = V_92 -> V_107 ;
if ( V_94 & V_101 )
return - V_113 ;
V_110 += ( V_94 & V_114 ) >>
V_99 ;
if ( V_92 == V_64 -> V_96 )
V_92 = V_64 -> V_98 ;
else
V_92 ++ ;
}
V_64 -> V_111 = V_92 ;
V_64 -> V_88 = 0 ;
return V_110 ;
}
static void F_32 ( struct V_1 * V_11 , struct V_76 * V_64 )
{
int V_115 = V_116 ;
struct V_91 * V_92 ;
int V_109 = V_64 -> V_109 ;
if ( ! V_64 -> V_86 )
F_22 ( V_11 , F_33 ( 0 , V_64 -> V_29 ) ) ;
F_12 ( V_11 , 0 , F_30 ( V_109 ) ) ;
while ( F_11 ( V_11 , F_30 ( V_109 ) ) &
V_108 ) {
F_17 ( 1 ) ;
if ( V_64 -> V_86 && V_64 -> V_29 >= 0 )
F_22 ( V_11 , V_64 -> V_29 ) ;
if ( ! V_115 -- ) {
F_34 ( V_11 -> V_117 , L_1 ,
V_109 ) ;
break;
}
if ( V_115 == V_116 / 2 ) {
F_35 ( V_11 -> V_117 , L_2 ,
V_109 ) ;
F_12 ( V_11 , V_118 ,
F_30 ( V_109 ) ) ;
}
}
F_12 ( V_11 , ~ 0 , F_36 ( V_109 ) ) ;
for ( V_92 = V_64 -> V_98 ; V_92 <= V_64 -> V_96 ; V_92 ++ )
V_92 -> V_107 = 0 ;
F_29 () ;
V_64 -> V_111 = V_64 -> V_93 = V_64 -> V_98 ;
V_64 -> V_88 = 0 ;
F_12 ( V_11 , V_119 ,
F_37 ( V_109 ) ) ;
F_12 ( V_11 , 8 , F_38 ( V_109 ) ) ;
F_14 ( V_11 , V_64 -> V_120 , F_39 ( V_109 ) ) ;
F_14 ( V_11 , 0 , F_40 ( V_109 ) ) ;
}
static int F_41 ( struct V_1 * V_11 , unsigned int V_109 )
{
struct V_76 * V_64 = & V_11 -> V_64 [ V_109 ] ;
const struct V_39 * V_56 = & V_41 [ V_109 ] ;
unsigned int V_103 = V_56 -> V_103 ;
struct V_5 * V_25 = NULL ;
V_64 -> V_29 = V_56 -> V_29 ;
V_64 -> V_109 = V_109 ;
V_64 -> V_86 = ! ! ( V_109 & 0x01 ) ;
if ( V_64 -> V_29 >= 0 ) {
V_25 = & V_11 -> V_25 [ V_64 -> V_29 ] ;
V_25 -> V_64 = V_64 ;
F_42 ( & V_25 -> V_121 ) ;
}
V_64 -> V_25 = V_25 ;
V_64 -> V_11 = V_11 ;
if ( V_64 -> V_29 <= 0 )
V_64 -> V_122 = true ;
V_64 -> V_103 = V_103 ;
V_64 -> V_98 = F_43 ( V_11 -> V_117 ,
V_103 * sizeof( struct V_91 ) ,
& V_64 -> V_120 , V_123 ) ;
if ( ! V_64 -> V_98 )
return - V_124 ;
V_64 -> V_96 = & V_64 -> V_98 [ V_103 - 1 ] ;
return 0 ;
}
static int F_44 ( struct V_1 * V_11 )
{
int V_35 , V_125 ;
F_10 ( V_11 , V_126 , V_127 ) ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
V_125 = F_41 ( V_11 , V_35 ) ;
if ( V_125 )
return V_125 ;
F_32 ( V_11 , & V_11 -> V_64 [ V_35 ] ) ;
}
F_10 ( V_11 , F_45 ( V_38 ) - 1 , V_128 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_11 )
{
int V_35 ;
F_10 ( V_11 , 0 , V_128 ) ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ )
F_32 ( V_11 , & V_11 -> V_64 [ V_35 ] ) ;
F_10 ( V_11 , 0 , V_127 ) ;
}
static void F_47 ( struct V_1 * V_11 , bool V_129 )
{
T_1 V_14 ;
F_7 ( V_11 , 0 , V_130 ) ;
V_14 = F_45 ( V_131 ) |
F_45 ( V_132 ) |
F_45 ( V_133 ) |
F_45 ( V_134 ) |
F_45 ( V_135 ) ;
F_7 ( V_11 , V_129 ? V_14 : 0 , V_136 ) ;
F_7 ( V_11 , V_14 , V_137 ) ;
}
static void F_48 ( struct V_1 * V_11 , bool V_138 )
{
T_1 V_14 , V_139 = F_45 ( V_11 -> V_140 -> V_141 ) ;
if ( F_49 () ) {
V_14 = F_50 ( V_142 ) ;
V_14 &= ~ V_143 ;
V_14 |= V_138 ? V_144 :
V_145 ;
F_51 ( V_14 , V_142 ) ;
}
V_14 = F_52 ( V_146 , V_147 ) ;
if ( V_138 ) {
V_14 |= ( V_139 << V_148 ) ;
V_14 |= ( V_139 << V_149 ) ;
} else {
V_14 &= ~ ( V_139 << V_148 ) ;
V_14 &= ~ ( V_139 << V_149 ) ;
}
F_53 ( V_146 , V_14 , V_147 ) ;
V_14 = F_52 ( V_146 , V_150 ) ;
if ( V_138 )
V_14 |= V_151 ;
else
V_14 &= ~ V_151 ;
F_53 ( V_146 , V_14 , V_150 ) ;
}
static void F_54 ( struct V_1 * V_11 , bool V_152 )
{
T_1 V_14 , V_139 = F_45 ( V_11 -> V_140 -> V_141 ) ;
V_14 = F_52 ( V_146 , V_147 ) ;
if ( V_152 )
V_14 &= ~ ( V_139 << V_149 ) ;
else
V_14 |= ( V_139 << V_149 ) ;
F_53 ( V_146 , V_14 , V_147 ) ;
}
static void F_55 ( struct V_1 * V_11 )
{
F_15 ( V_11 , true ) ;
F_46 ( V_11 ) ;
F_15 ( V_11 , false ) ;
F_56 ( V_11 -> V_20 ) ;
F_56 ( V_11 -> V_19 ) ;
}
static int F_57 ( struct V_1 * V_11 )
{
int V_35 , V_125 = 0 ;
T_1 V_14 ;
V_11 -> V_153 = F_58 ( V_11 -> V_117 , V_154 ,
V_123 ) ;
if ( ! V_11 -> V_153 )
return - V_124 ;
F_42 ( & V_11 -> V_4 . V_155 ) ;
for ( V_35 = 0 ; V_35 < V_156 ; V_35 ++ ) {
struct V_5 * V_25 = & V_11 -> V_25 [ V_35 ] ;
V_25 -> V_7 . V_157 = V_158 [ V_35 ] ;
V_25 -> V_29 = V_35 ;
V_25 -> V_7 . V_159 = & V_160 ;
F_59 ( & V_25 -> V_7 . V_155 , & V_11 -> V_4 . V_155 ) ;
V_25 -> V_161 = 0 ;
V_25 -> V_7 . V_65 = V_154 ;
V_25 -> V_11 = V_11 ;
V_25 -> V_7 . V_162 = NULL ;
F_42 ( & V_25 -> V_121 ) ;
}
V_11 -> V_4 . V_163 = & V_11 -> V_25 [ 0 ] . V_7 ;
F_60 ( & V_11 -> V_25 [ 0 ] . V_7 . V_155 ) ;
V_11 -> V_4 . V_33 = V_164 ;
V_11 -> V_165 = V_166 ;
V_11 -> V_19 = F_61 ( V_11 -> V_117 , L_3 ) ;
if ( F_62 ( V_11 -> V_19 ) )
return - V_167 ;
V_11 -> V_20 = F_61 ( V_11 -> V_117 , L_4 ) ;
if ( F_62 ( V_11 -> V_20 ) ) {
F_56 ( V_11 -> V_19 ) ;
return - V_167 ;
}
F_15 ( V_11 , true ) ;
V_14 = V_168 |
V_169 |
( V_85 ? V_170 : 0 ) ;
F_7 ( V_11 , V_14 , V_22 ) ;
V_14 = V_171 |
V_172 |
V_173 |
V_174 |
V_175 ;
if ( V_11 -> V_4 . V_176 == V_34 )
V_14 |= ( V_177 << V_178 ) ;
else
V_14 |= ( V_179 << V_178 ) ;
F_7 ( V_11 , V_14 , V_180 ) ;
F_47 ( V_11 , false ) ;
F_7 ( V_11 , 0 , V_181 ) ;
V_14 = F_63 ( V_182 ) |
F_63 ( V_183 ) ;
F_7 ( V_11 , V_14 , V_184 ) ;
V_125 = F_44 ( V_11 ) ;
F_15 ( V_11 , false ) ;
if ( V_125 )
F_55 ( V_11 ) ;
return 0 ;
}
static int F_64 ( struct V_6 * V_7 ,
const struct V_185 * V_162 )
{
struct V_5 * V_25 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_25 -> V_11 ;
struct V_76 * V_64 = V_25 -> V_64 ;
unsigned long V_186 ;
if ( ! V_7 || ! V_162 || V_7 -> V_157 == V_187 )
return - V_112 ;
if ( ! V_11 -> V_188 )
return - V_189 ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
if ( V_64 -> V_122 ) {
F_66 ( & V_11 -> V_190 , V_186 ) ;
return - V_112 ;
}
V_64 -> V_122 = true ;
F_67 ( ! F_68 ( & V_25 -> V_121 ) ) ;
F_32 ( V_11 , V_64 ) ;
V_25 -> V_161 = 0 ;
F_20 ( V_11 , V_25 , false ) ;
F_69 ( V_25 -> V_29 , & V_11 -> V_191 ) ;
V_7 -> V_162 = V_162 ;
V_7 -> V_65 = F_70 ( V_162 ) ;
F_66 ( & V_11 -> V_190 , V_186 ) ;
return 0 ;
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_5 * V_25 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_25 -> V_11 ;
struct V_76 * V_64 = V_25 -> V_64 ;
struct V_192 * V_193 , * V_194 ;
unsigned long V_186 ;
if ( ! V_7 || ! V_7 -> V_162 )
return - V_112 ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
if ( ! V_64 -> V_122 ) {
F_66 ( & V_11 -> V_190 , V_186 ) ;
return - V_112 ;
}
V_64 -> V_122 = false ;
F_32 ( V_11 , V_64 ) ;
if ( ! F_68 ( & V_25 -> V_121 ) ) {
F_72 (pos, n, &bep->queue) {
struct V_8 * V_77 =
F_73 ( V_193 , struct V_8 , V_121 ) ;
F_74 ( & V_11 -> V_4 , & V_77 -> V_10 ,
V_64 -> V_86 ) ;
F_60 ( & V_77 -> V_121 ) ;
V_77 -> V_10 . V_195 = - V_189 ;
F_66 ( & V_11 -> V_190 , V_186 ) ;
V_77 -> V_10 . V_196 ( & V_64 -> V_25 -> V_7 , & V_77 -> V_10 ) ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
}
}
V_7 -> V_162 = NULL ;
F_66 ( & V_11 -> V_190 , V_186 ) ;
return 0 ;
}
static struct V_9 * F_75 ( struct V_6 * V_7 ,
T_2 V_197 )
{
struct V_8 * V_77 ;
V_77 = F_76 ( sizeof( * V_77 ) , V_197 ) ;
if ( ! V_77 )
return NULL ;
return & V_77 -> V_10 ;
}
static void F_77 ( struct V_6 * V_7 ,
struct V_9 * V_10 )
{
struct V_8 * V_77 = F_4 ( V_10 ) ;
F_78 ( V_77 ) ;
}
static int F_79 ( struct V_6 * V_7 , struct V_9 * V_10 ,
T_2 V_197 )
{
struct V_5 * V_25 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_25 -> V_11 ;
struct V_8 * V_77 = F_4 ( V_10 ) ;
unsigned long V_186 ;
int V_125 = 0 ;
if ( F_80 ( ! V_10 || ! V_10 -> V_196 || ! V_10 -> V_198 || ! V_7 ) )
return - V_112 ;
V_10 -> V_199 = 0 ;
V_10 -> V_195 = 0 ;
V_77 -> V_83 = 0 ;
if ( V_25 == & V_11 -> V_25 [ 0 ] ) {
if ( V_11 -> V_200 )
return - V_112 ;
V_11 -> V_200 = V_10 ;
F_81 ( & V_11 -> V_201 ) ;
return 0 ;
}
F_65 ( & V_11 -> V_190 , V_186 ) ;
if ( ! V_25 -> V_64 -> V_122 ) {
V_125 = - V_189 ;
goto V_202;
}
V_125 = F_82 ( & V_11 -> V_4 , V_10 , V_25 -> V_64 -> V_86 ) ;
if ( V_125 == 0 ) {
F_59 ( & V_77 -> V_121 , & V_25 -> V_121 ) ;
if ( F_83 ( & V_25 -> V_121 ) )
F_27 ( V_11 , V_25 -> V_64 , V_77 ) ;
}
V_202:
F_66 ( & V_11 -> V_190 , V_186 ) ;
return V_125 ;
}
static int F_84 ( struct V_6 * V_7 , struct V_9 * V_10 )
{
struct V_5 * V_25 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_25 -> V_11 ;
struct V_8 * V_77 = F_4 ( V_10 ) , * V_203 ;
unsigned long V_186 ;
int V_125 = 0 ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
if ( F_68 ( & V_25 -> V_121 ) ) {
V_125 = - V_112 ;
goto V_202;
}
V_203 = F_85 ( & V_25 -> V_121 , struct V_8 , V_121 ) ;
F_74 ( & V_11 -> V_4 , & V_77 -> V_10 , V_25 -> V_64 -> V_86 ) ;
if ( V_77 == V_203 ) {
F_32 ( V_11 , V_25 -> V_64 ) ;
F_60 ( & V_77 -> V_121 ) ;
if ( ! F_68 ( & V_25 -> V_121 ) ) {
struct V_8 * V_204 ;
V_204 = F_85 ( & V_25 -> V_121 ,
struct V_8 , V_121 ) ;
F_27 ( V_11 , V_25 -> V_64 , V_204 ) ;
}
} else {
F_60 ( & V_77 -> V_121 ) ;
}
V_202:
F_66 ( & V_11 -> V_190 , V_186 ) ;
V_10 -> V_195 = - V_189 ;
V_10 -> V_196 ( V_7 , V_10 ) ;
return V_125 ;
}
static int F_86 ( struct V_6 * V_7 , int V_205 )
{
struct V_5 * V_25 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_25 -> V_11 ;
unsigned long V_186 ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
F_20 ( V_11 , V_25 , ! ! V_205 ) ;
V_25 -> V_161 = V_205 ;
F_66 ( & V_11 -> V_190 , V_186 ) ;
return 0 ;
}
static int F_87 ( struct V_6 * V_7 )
{
struct V_5 * V_25 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_25 -> V_11 ;
unsigned long V_186 ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
F_88 ( V_25 -> V_29 , & V_11 -> V_191 ) ;
F_20 ( V_11 , V_25 , true ) ;
F_66 ( & V_11 -> V_190 , V_186 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_11 ,
struct V_206 * V_207 )
{
int V_125 ;
F_90 ( & V_11 -> V_190 ) ;
V_125 = V_11 -> V_188 -> V_208 ( & V_11 -> V_4 , V_207 ) ;
F_91 ( & V_11 -> V_190 ) ;
return V_125 ;
}
static int F_92 ( struct V_1 * V_11 )
{
struct V_206 V_207 ;
int V_125 ;
V_207 . V_209 = V_210 | V_211 ;
V_207 . V_212 = V_213 ;
V_207 . V_214 = F_93 ( V_11 -> V_56 ) ;
V_207 . V_215 = 0 ;
V_207 . V_216 = 0 ;
V_125 = F_89 ( V_11 , & V_207 ) ;
if ( V_125 < 0 ) {
F_94 ( V_11 -> V_117 ,
L_5 ,
V_11 -> V_56 ) ;
}
return V_125 ;
}
static int F_95 ( struct V_1 * V_11 )
{
struct V_206 V_207 ;
int V_125 ;
V_207 . V_209 = V_210 | V_217 ;
V_207 . V_212 = V_218 ;
V_207 . V_214 = F_93 ( V_11 -> V_73 ) ;
V_207 . V_215 = F_93 ( V_11 -> V_71 ) ;
V_207 . V_216 = 0 ;
V_125 = F_89 ( V_11 , & V_207 ) ;
if ( V_125 < 0 ) {
F_94 ( V_11 -> V_117 ,
L_6 ,
V_11 -> V_71 , V_11 -> V_73 ) ;
}
return V_125 ;
}
static void F_96 ( struct V_1 * V_11 , int V_109 ,
struct V_9 * V_10 )
{
struct V_8 * V_77 = F_4 ( V_10 ) ;
struct V_76 * V_64 = & V_11 -> V_64 [ V_109 ] ;
F_67 ( V_11 -> V_219 ) ;
V_11 -> V_219 = V_10 ;
V_10 -> V_199 = 0 ;
V_77 -> V_83 = 0 ;
F_82 ( & V_11 -> V_4 , V_10 , V_64 -> V_86 ) ;
F_27 ( V_11 , V_64 , V_77 ) ;
}
static void F_97 ( struct V_1 * V_11 ,
struct V_9 * V_10 , int V_195 )
{
V_10 -> V_195 = V_195 ;
if ( V_195 )
V_10 -> V_199 = 0 ;
if ( V_10 -> V_196 ) {
F_90 ( & V_11 -> V_190 ) ;
V_10 -> V_196 ( & V_11 -> V_25 [ 0 ] . V_7 , V_10 ) ;
F_91 ( & V_11 -> V_190 ) ;
}
}
static void F_98 ( struct V_1 * V_11 , int V_86 )
{
struct V_9 * V_10 = V_11 -> V_200 ;
V_11 -> V_200 = NULL ;
F_74 ( & V_11 -> V_4 , V_10 , V_86 ) ;
if ( V_11 -> V_219 == V_10 ) {
V_11 -> V_220 = 0 ;
V_11 -> V_219 = NULL ;
}
F_97 ( V_11 , V_10 , - V_189 ) ;
}
static int F_99 ( struct V_1 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_219 ;
V_11 -> V_220 = 0 ;
V_11 -> V_219 = NULL ;
return V_10 -> V_199 ;
}
static void F_100 ( struct V_1 * V_11 , int V_109 ,
int V_82 )
{
struct V_9 * V_10 = & V_11 -> V_221 . V_10 ;
V_10 -> V_198 = V_11 -> V_153 ;
V_10 -> V_82 = V_82 ;
V_10 -> V_196 = NULL ;
F_96 ( V_11 , V_109 , V_10 ) ;
}
static enum V_222 F_101 ( struct V_1 * V_11 )
{
int V_125 ;
struct V_206 * V_207 = ( void * ) V_11 -> V_153 ;
V_125 = F_99 ( V_11 ) ;
if ( V_125 < 0 ) {
F_34 ( V_11 -> V_117 , L_7 ) ;
return V_223 ;
}
if ( V_125 == 0 )
return V_224 ;
if ( V_125 != sizeof( * V_207 ) ) {
F_94 ( V_11 -> V_117 ,
L_8 , V_125 ) ;
return V_224 ;
}
V_125 = F_89 ( V_11 , V_207 ) ;
if ( V_125 < 0 ) {
F_20 ( V_11 , & V_11 -> V_25 [ 0 ] , true ) ;
return V_224 ;
}
if ( ! V_207 -> V_216 )
return V_224 ;
else if ( V_207 -> V_209 & V_225 )
return V_226 ;
else
return V_227 ;
}
static int F_102 ( struct V_1 * V_11 )
{
if ( V_11 -> V_228 ) {
V_11 -> V_228 = 0 ;
} else if ( V_11 -> V_229 ) {
V_11 -> V_229 = 0 ;
if ( F_92 ( V_11 ) >= 0 )
V_11 -> V_165 = V_230 ;
} else if ( V_11 -> V_231 ) {
V_11 -> V_231 = 0 ;
if ( F_95 ( V_11 ) >= 0 )
V_11 -> V_165 = V_230 ;
} else if ( V_11 -> V_220 ) {
V_11 -> V_165 = F_101 ( V_11 ) ;
return V_11 -> V_165 == V_223 ? - V_232 : 0 ;
} else if ( V_11 -> V_233 ) {
V_11 -> V_233 = 0 ;
V_11 -> V_220 = 0 ;
V_11 -> V_219 = NULL ;
F_32 ( V_11 , & V_11 -> V_64 [ V_234 ] ) ;
F_74 ( & V_11 -> V_4 ,
& V_11 -> V_221 . V_10 , 0 ) ;
F_29 () ;
V_11 -> V_165 = V_166 ;
} else if ( V_11 -> V_200 ) {
F_35 ( V_11 -> V_117 , L_9 ) ;
F_98 ( V_11 , 0 ) ;
} else {
return - V_232 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_11 )
{
enum V_222 V_165 = V_11 -> V_165 ;
bool V_235 = V_11 -> V_228 || V_11 -> V_233 ;
switch ( V_11 -> V_165 ) {
case V_224 :
F_100 ( V_11 , V_234 ,
V_154 ) ;
V_165 = V_223 ;
break;
case V_223 :
return F_102 ( V_11 ) ;
case V_226 :
if ( V_11 -> V_200 ) {
F_96 ( V_11 , V_236 ,
V_11 -> V_200 ) ;
V_165 = V_237 ;
} else if ( V_235 ) {
V_165 = V_224 ;
}
break;
case V_237 : {
if ( V_11 -> V_220 ) {
V_11 -> V_200 = NULL ;
F_99 ( V_11 ) ;
V_165 = V_224 ;
} else if ( V_235 ) {
F_32 ( V_11 , & V_11 -> V_64 [ V_236 ] ) ;
F_98 ( V_11 , 1 ) ;
V_165 = V_224 ;
}
break;
}
case V_227 :
if ( V_11 -> V_200 ) {
F_96 ( V_11 , V_234 ,
V_11 -> V_200 ) ;
V_165 = V_238 ;
} else if ( V_235 ) {
V_165 = V_224 ;
}
break;
case V_238 : {
if ( V_11 -> V_220 ) {
V_11 -> V_200 = NULL ;
F_99 ( V_11 ) ;
F_100 ( V_11 , V_236 , 0 ) ;
V_165 = V_239 ;
} else if ( V_235 ) {
F_32 ( V_11 , & V_11 -> V_64 [ V_234 ] ) ;
F_98 ( V_11 , 0 ) ;
V_165 = V_224 ;
}
break;
}
case V_239 :
if ( V_11 -> V_220 ) {
F_99 ( V_11 ) ;
V_165 = V_224 ;
} else if ( V_235 ) {
F_32 ( V_11 , & V_11 -> V_64 [ V_236 ] ) ;
V_11 -> V_219 = NULL ;
V_165 = V_224 ;
}
break;
case V_230 : {
struct V_9 * V_240 = V_11 -> V_200 ;
if ( ! V_240 ) {
if ( V_235 )
V_165 = V_223 ;
break;
}
F_97 ( V_11 , V_240 , 0 ) ;
V_11 -> V_200 = NULL ;
V_165 = V_223 ;
break;
}
case V_166 :
break;
}
if ( V_11 -> V_165 == V_165 )
return - V_232 ;
V_11 -> V_165 = V_165 ;
return 0 ;
}
static void F_104 ( struct V_241 * V_242 )
{
struct V_1 * V_11 = F_2 ( V_242 , struct V_1 , V_201 ) ;
F_91 ( & V_11 -> V_190 ) ;
while ( F_103 ( V_11 ) == 0 )
;
F_90 ( & V_11 -> V_190 ) ;
}
static int F_105 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
return ( F_5 ( V_11 , V_130 ) &
V_243 ) >> V_244 ;
}
static int F_106 ( struct V_2 * V_4 , int V_152 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_186 ;
int V_35 , V_125 = - V_112 ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
if ( V_152 && V_11 -> V_165 == V_166 ) {
V_11 -> V_4 . V_33 = V_164 ;
V_11 -> V_165 = V_224 ;
F_21 ( V_11 ) ;
F_23 ( V_11 ) ;
F_25 ( V_11 ) ;
F_107 ( & V_11 -> V_191 , V_156 ) ;
for ( V_35 = 0 ; V_35 < V_156 ; V_35 ++ )
F_20 ( V_11 , & V_11 -> V_25 [ V_35 ] , false ) ;
F_47 ( V_11 , true ) ;
F_54 ( F_1 ( V_4 ) , true ) ;
V_125 = 0 ;
} else if ( ! V_152 && V_11 -> V_165 != V_166 ) {
F_54 ( F_1 ( V_4 ) , false ) ;
V_11 -> V_233 = 1 ;
F_66 ( & V_11 -> V_190 , V_186 ) ;
while ( 1 ) {
F_81 ( & V_11 -> V_201 ) ;
if ( V_11 -> V_165 == V_166 )
break;
F_108 ( 50 ) ;
}
F_47 ( V_11 , false ) ;
F_109 ( & V_11 -> V_201 ) ;
return 0 ;
}
F_66 ( & V_11 -> V_190 , V_186 ) ;
return V_125 ;
}
static int F_110 ( struct V_2 * V_4 ,
struct V_245 * V_188 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_186 ;
if ( ! V_188 || V_188 -> V_176 < V_34 ||
! V_188 -> V_208 )
return - V_112 ;
if ( ! V_11 )
return - V_246 ;
if ( V_11 -> V_188 )
return - V_113 ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
F_15 ( V_11 , true ) ;
F_21 ( V_11 ) ;
F_24 ( V_11 ) ;
F_25 ( V_11 ) ;
F_23 ( V_11 ) ;
F_48 ( V_11 , true ) ;
V_11 -> V_188 = V_188 ;
V_188 -> V_188 . V_247 = NULL ;
V_11 -> V_4 . V_117 . V_188 = & V_188 -> V_188 ;
V_11 -> V_4 . V_117 . V_248 = V_11 -> V_117 -> V_248 ;
F_66 ( & V_11 -> V_190 , V_186 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_4 ,
struct V_245 * V_188 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_186 ;
F_65 ( & V_11 -> V_190 , V_186 ) ;
V_11 -> V_188 = NULL ;
V_11 -> V_4 . V_117 . V_188 = NULL ;
F_108 ( 100 ) ;
F_48 ( V_11 , false ) ;
F_15 ( V_11 , false ) ;
F_66 ( & V_11 -> V_190 , V_186 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_11 )
{
T_1 V_249 = F_5 ( V_11 , V_130 ) ;
V_11 -> V_56 = ( V_249 & V_250 ) >> V_251 ;
V_11 -> V_71 = ( V_249 & V_252 ) >> V_253 ;
V_11 -> V_73 = ( V_249 & V_254 ) >>
V_255 ;
F_25 ( V_11 ) ;
}
static int F_113 ( struct V_1 * V_11 )
{
T_1 V_249 = F_5 ( V_11 , V_130 ) ;
enum V_256 V_257 = V_11 -> V_4 . V_33 ;
switch ( ( V_249 & V_258 ) >> V_259 ) {
case V_177 :
V_11 -> V_4 . V_33 = V_34 ;
break;
case V_179 :
V_11 -> V_4 . V_33 = V_260 ;
break;
default:
V_11 -> V_4 . V_33 = V_164 ;
F_34 ( V_11 -> V_117 ,
L_10 ) ;
return 0 ;
}
if ( V_11 -> V_4 . V_33 != V_257 ) {
F_114 ( V_11 -> V_117 , L_11 ,
V_11 -> V_4 . V_33 == V_34 ? L_12 : L_13 ) ;
return 1 ;
} else {
return 0 ;
}
}
static void F_115 ( struct V_1 * V_11 , bool V_261 )
{
int V_35 ;
F_116 (i, &udc->wedgemap, BCM63XX_NUM_EP) {
F_20 ( V_11 , & V_11 -> V_25 [ V_35 ] , V_261 ) ;
if ( ! V_261 )
F_69 ( V_35 , & V_11 -> V_191 ) ;
}
}
static T_3 F_117 ( int V_262 , void * V_263 )
{
struct V_1 * V_11 = V_263 ;
T_1 V_264 ;
bool V_265 = false ;
V_264 = F_5 ( V_11 , V_137 ) &
F_5 ( V_11 , V_136 ) ;
F_7 ( V_11 , V_264 , V_137 ) ;
F_118 ( & V_11 -> V_190 ) ;
if ( V_264 & F_45 ( V_135 ) ) {
if ( ! ( F_5 ( V_11 , V_266 ) &
V_267 ) &&
V_11 -> V_4 . V_33 != V_164 )
F_114 ( V_11 -> V_117 , L_14 ) ;
V_11 -> V_4 . V_33 = V_164 ;
V_265 = true ;
}
if ( V_264 & F_45 ( V_131 ) ) {
F_21 ( V_11 ) ;
F_23 ( V_11 ) ;
F_25 ( V_11 ) ;
F_115 ( V_11 , false ) ;
V_11 -> V_228 = 1 ;
F_81 ( & V_11 -> V_201 ) ;
V_265 = true ;
}
if ( V_264 & F_45 ( V_132 ) ) {
if ( F_113 ( V_11 ) ) {
F_21 ( V_11 ) ;
F_25 ( V_11 ) ;
}
F_115 ( V_11 , true ) ;
}
if ( V_264 & F_45 ( V_133 ) ) {
F_112 ( V_11 ) ;
V_11 -> V_229 = 1 ;
F_81 ( & V_11 -> V_201 ) ;
}
if ( V_264 & F_45 ( V_134 ) ) {
F_112 ( V_11 ) ;
V_11 -> V_231 = 1 ;
F_81 ( & V_11 -> V_201 ) ;
}
F_119 ( & V_11 -> V_190 ) ;
if ( V_265 && V_11 -> V_188 )
V_11 -> V_188 -> V_268 ( & V_11 -> V_4 ) ;
return V_269 ;
}
static T_3 F_120 ( int V_262 , void * V_263 )
{
struct V_76 * V_64 = V_263 ;
struct V_1 * V_11 = V_64 -> V_11 ;
struct V_5 * V_25 ;
struct V_9 * V_10 = NULL ;
struct V_8 * V_77 = NULL ;
int V_125 ;
bool V_270 = false ;
F_118 ( & V_11 -> V_190 ) ;
F_12 ( V_11 , V_119 ,
F_36 ( V_64 -> V_109 ) ) ;
V_25 = V_64 -> V_25 ;
V_125 = F_31 ( V_11 , V_64 ) ;
if ( V_64 -> V_109 == V_234 ||
V_64 -> V_109 == V_236 ) {
V_10 = V_11 -> V_219 ;
V_77 = F_4 ( V_10 ) ;
if ( V_125 >= 0 ) {
V_10 -> V_199 += V_125 ;
if ( V_10 -> V_199 >= V_10 -> V_82 || V_77 -> V_89 > V_125 ) {
V_11 -> V_220 = 1 ;
V_270 = true ;
F_81 ( & V_11 -> V_201 ) ;
V_10 -> V_199 = F_121 ( V_10 -> V_199 , V_10 -> V_82 ) ;
} else {
F_27 ( V_11 , V_64 , V_77 ) ;
}
}
} else if ( ! F_68 ( & V_25 -> V_121 ) ) {
V_77 = F_85 ( & V_25 -> V_121 , struct V_8 , V_121 ) ;
V_10 = & V_77 -> V_10 ;
if ( V_125 >= 0 ) {
V_10 -> V_199 += V_125 ;
if ( V_10 -> V_199 >= V_10 -> V_82 || V_77 -> V_89 > V_125 ) {
V_270 = true ;
F_60 ( & V_77 -> V_121 ) ;
V_10 -> V_199 = F_121 ( V_10 -> V_199 , V_10 -> V_82 ) ;
if ( ! F_68 ( & V_25 -> V_121 ) ) {
struct V_8 * V_204 ;
V_204 = F_85 ( & V_25 -> V_121 ,
struct V_8 , V_121 ) ;
F_27 ( V_11 , V_64 , V_204 ) ;
}
} else {
F_27 ( V_11 , V_64 , V_77 ) ;
}
}
}
F_119 ( & V_11 -> V_190 ) ;
if ( V_270 ) {
F_74 ( & V_11 -> V_4 , V_10 , V_64 -> V_86 ) ;
if ( V_10 -> V_196 )
V_10 -> V_196 ( & V_25 -> V_7 , V_10 ) ;
}
return V_269 ;
}
static int F_122 ( struct V_271 * V_272 , void * V_273 )
{
struct V_1 * V_11 = V_272 -> V_274 ;
if ( ! V_11 -> V_188 )
return - V_246 ;
F_123 ( V_272 , L_15 ,
V_275 [ V_11 -> V_165 ] ) ;
F_123 ( V_272 , L_16 ,
V_11 -> V_228 ? L_17 : L_18 ,
V_11 -> V_229 ? L_19 : L_18 ,
V_11 -> V_231 ? L_20 : L_18 ,
V_11 -> V_233 ? L_21 : L_18 ,
V_11 -> V_219 ? L_22 : L_18 ,
V_11 -> V_220 ? L_23 : L_18 ,
V_11 -> V_200 ? L_24 : L_18 ) ;
F_123 ( V_272 , L_25 ,
V_11 -> V_56 , V_11 -> V_71 , V_11 -> V_73 ) ;
F_123 ( V_272 , L_26 ) ;
F_123 ( V_272 , L_27 ,
F_5 ( V_11 , V_22 ) ,
F_5 ( V_11 , V_180 ) ,
F_5 ( V_11 , V_130 ) ) ;
F_123 ( V_272 , L_28 ,
F_5 ( V_11 , V_266 ) ,
F_5 ( V_11 , V_31 ) ) ;
return 0 ;
}
static int F_124 ( struct V_271 * V_272 , void * V_273 )
{
struct V_1 * V_11 = V_272 -> V_274 ;
int V_109 , V_35 ;
T_1 V_276 , V_277 ;
if ( ! V_11 -> V_188 )
return - V_246 ;
for ( V_109 = 0 ; V_109 < V_38 ; V_109 ++ ) {
struct V_76 * V_64 = & V_11 -> V_64 [ V_109 ] ;
struct V_192 * V_193 ;
F_123 ( V_272 , L_29 , V_109 ) ;
switch ( V_41 [ V_109 ] . V_57 ) {
case V_278 :
F_123 ( V_272 , L_30 ) ;
break;
case V_279 :
F_123 ( V_272 , L_31 ) ;
break;
case V_280 :
F_123 ( V_272 , L_32 ) ;
break;
}
F_123 ( V_272 , V_109 & 0x01 ? L_33 : L_34 ) ;
F_123 ( V_272 , L_35 ,
F_125 ( int , V_41 [ V_109 ] . V_29 , 0 ) ) ;
F_123 ( V_272 , L_36 ,
F_11 ( V_11 , F_30 ( V_109 ) ) ,
F_11 ( V_11 , F_36 ( V_109 ) ) ,
F_11 ( V_11 , F_37 ( V_109 ) ) ,
F_11 ( V_11 , F_38 ( V_109 ) ) ) ;
V_276 = F_13 ( V_11 , F_40 ( V_109 ) ) ;
V_277 = F_13 ( V_11 , F_126 ( V_109 ) ) ;
F_123 ( V_272 , L_37 ,
F_13 ( V_11 , F_39 ( V_109 ) ) ,
V_276 >> 16 , V_276 & 0xffff ,
V_277 >> 16 , V_277 & 0xffff ,
F_13 ( V_11 , F_127 ( V_109 ) ) ) ;
F_123 ( V_272 , L_38 , V_64 -> V_88 ,
V_64 -> V_103 ) ;
if ( V_64 -> V_25 ) {
V_35 = 0 ;
F_128 (pos, &iudma->bep->queue)
V_35 ++ ;
F_123 ( V_272 , L_39 , V_35 ) ;
} else {
F_123 ( V_272 , L_40 ) ;
}
for ( V_35 = 0 ; V_35 < V_64 -> V_103 ; V_35 ++ ) {
struct V_91 * V_92 = & V_64 -> V_98 [ V_35 ] ;
F_123 ( V_272 , L_41 ,
V_35 * sizeof( * V_92 ) , V_35 ,
V_92 -> V_107 >> 16 , V_92 -> V_107 & 0xffff ,
V_92 -> V_105 ) ;
if ( V_92 == V_64 -> V_111 )
F_123 ( V_272 , L_42 ) ;
if ( V_92 == V_64 -> V_93 )
F_123 ( V_272 , L_43 ) ;
F_123 ( V_272 , L_40 ) ;
}
F_123 ( V_272 , L_40 ) ;
}
return 0 ;
}
static int F_129 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
return F_130 ( V_282 , F_122 , V_281 -> V_283 ) ;
}
static int F_131 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
return F_130 ( V_282 , F_124 , V_281 -> V_283 ) ;
}
static void F_132 ( struct V_1 * V_11 )
{
struct V_284 * V_285 , * V_286 , * V_64 ;
if ( ! F_133 ( V_287 ) )
return;
V_285 = F_134 ( V_11 -> V_4 . V_157 , NULL ) ;
if ( F_62 ( V_285 ) || ! V_285 )
goto V_288;
V_286 = F_135 ( L_4 , 0400 , V_285 , V_11 ,
& V_289 ) ;
if ( ! V_286 )
goto V_290;
V_64 = F_135 ( L_44 , 0400 , V_285 , V_11 ,
& V_291 ) ;
if ( ! V_64 )
goto V_292;
V_11 -> V_293 = V_285 ;
V_11 -> V_294 = V_286 ;
V_11 -> V_295 = V_64 ;
return;
V_292:
F_136 ( V_286 ) ;
V_290:
F_136 ( V_285 ) ;
V_288:
F_34 ( V_11 -> V_117 , L_45 ) ;
}
static void F_137 ( struct V_1 * V_11 )
{
F_136 ( V_11 -> V_295 ) ;
F_136 ( V_11 -> V_294 ) ;
F_136 ( V_11 -> V_293 ) ;
V_11 -> V_295 = NULL ;
V_11 -> V_294 = NULL ;
V_11 -> V_293 = NULL ;
}
static void F_138 ( struct V_296 * V_117 )
{
}
static int F_139 ( struct V_297 * V_298 )
{
struct V_296 * V_117 = & V_298 -> V_117 ;
struct V_299 * V_140 = V_117 -> V_300 ;
struct V_1 * V_11 ;
struct V_301 * V_302 ;
int V_125 = - V_124 , V_35 , V_262 ;
V_11 = F_58 ( V_117 , sizeof( * V_11 ) , V_123 ) ;
if ( ! V_11 ) {
F_34 ( V_117 , L_46 ) ;
return - V_124 ;
}
F_140 ( V_298 , V_11 ) ;
V_11 -> V_117 = V_117 ;
V_11 -> V_140 = V_140 ;
if ( ! V_140 ) {
F_34 ( V_117 , L_47 ) ;
return - V_112 ;
}
V_302 = F_141 ( V_298 , V_303 , 0 ) ;
if ( ! V_302 ) {
F_34 ( V_117 , L_48 ) ;
return - V_304 ;
}
V_11 -> V_13 = F_142 ( V_117 , V_302 ) ;
if ( F_62 ( V_11 -> V_13 ) )
return F_143 ( V_11 -> V_13 ) ;
V_302 = F_141 ( V_298 , V_303 , 1 ) ;
if ( ! V_302 ) {
F_34 ( V_117 , L_49 ) ;
return - V_304 ;
}
V_11 -> V_15 = F_142 ( V_117 , V_302 ) ;
if ( F_62 ( V_11 -> V_15 ) )
return F_143 ( V_11 -> V_15 ) ;
F_144 ( & V_11 -> V_190 ) ;
F_145 ( & V_11 -> V_201 , F_104 ) ;
F_146 ( & V_11 -> V_4 . V_117 , L_50 ) ;
V_11 -> V_4 . V_159 = & V_305 ;
V_11 -> V_4 . V_157 = F_147 ( V_117 ) ;
V_11 -> V_4 . V_117 . V_306 = V_117 ;
V_11 -> V_4 . V_117 . V_307 = F_138 ;
V_11 -> V_4 . V_117 . V_308 = V_117 -> V_308 ;
if ( ! V_140 -> V_309 && ! V_309 )
V_11 -> V_4 . V_176 = V_34 ;
else
V_11 -> V_4 . V_176 = V_260 ;
V_125 = F_57 ( V_11 ) ;
if ( V_125 )
return V_125 ;
V_125 = - V_304 ;
V_262 = F_148 ( V_298 , 0 ) ;
if ( V_262 < 0 ) {
F_34 ( V_117 , L_51 ) ;
goto V_310;
}
if ( F_149 ( V_117 , V_262 , & F_117 , 0 ,
F_147 ( V_117 ) , V_11 ) < 0 ) {
F_34 ( V_117 , L_52 , V_262 ) ;
goto V_310;
}
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
V_262 = F_148 ( V_298 , V_35 + 1 ) ;
if ( V_262 < 0 ) {
F_34 ( V_117 , L_53 , V_35 + 1 ) ;
goto V_310;
}
if ( F_149 ( V_117 , V_262 , & F_120 , 0 ,
F_147 ( V_117 ) , & V_11 -> V_64 [ V_35 ] ) < 0 ) {
F_34 ( V_117 , L_52 , V_262 ) ;
goto V_310;
}
}
V_125 = F_150 ( & V_11 -> V_4 . V_117 ) ;
if ( V_125 )
goto V_310;
F_132 ( V_11 ) ;
V_125 = F_151 ( V_117 , & V_11 -> V_4 ) ;
if ( ! V_125 )
return 0 ;
F_137 ( V_11 ) ;
F_152 ( & V_11 -> V_4 . V_117 ) ;
V_310:
F_55 ( V_11 ) ;
return V_125 ;
}
static int F_153 ( struct V_297 * V_298 )
{
struct V_1 * V_11 = F_154 ( V_298 ) ;
F_137 ( V_11 ) ;
F_155 ( & V_11 -> V_4 ) ;
F_152 ( & V_11 -> V_4 . V_117 ) ;
F_67 ( V_11 -> V_188 ) ;
F_140 ( V_298 , NULL ) ;
F_55 ( V_11 ) ;
return 0 ;
}
