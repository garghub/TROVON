static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 . V_6 ;
}
static inline bool F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_7 == V_8 ;
}
static inline void F_3 ( struct V_2 * V_3 , T_1 V_9 , T_1 V_10 )
{
F_4 ( V_10 , V_3 -> V_11 ) ;
F_4 ( V_9 , V_3 -> V_12 ) ;
}
static inline T_1 F_5 ( struct V_2 * V_3 , T_1 V_10 )
{
F_4 ( V_10 , V_3 -> V_11 ) ;
return F_6 ( V_3 -> V_12 ) ;
}
static inline void F_7 ( struct V_2 * V_3 , T_1 V_9 , T_1 V_10 )
{
T_1 V_13 = F_5 ( V_3 , V_10 ) | V_9 ;
F_3 ( V_3 , V_13 , V_10 ) ;
}
static inline void F_8 ( struct V_2 * V_3 , T_1 V_9 , T_1 V_10 )
{
T_1 V_13 = F_5 ( V_3 , V_10 ) & ~ V_9 ;
F_3 ( V_3 , V_13 , V_10 ) ;
}
static inline int F_9 ( struct V_2 * V_3 )
{
if ( ! F_10 ( V_3 -> V_11 , 2 , V_14 ) )
return - V_15 ;
F_4 ( V_16 , V_3 -> V_11 ) ;
F_4 ( V_16 , V_3 -> V_11 ) ;
return 0 ;
}
static inline void F_11 ( struct V_2 * V_3 )
{
F_4 ( V_17 , V_3 -> V_11 ) ;
F_12 ( V_3 -> V_11 , 2 ) ;
}
static inline void F_13 ( struct V_2 * V_3 , T_1 V_18 )
{
F_3 ( V_3 , V_18 , V_19 ) ;
}
static inline void F_14 ( struct V_2 * V_3 , T_1 V_18 )
{
F_9 ( V_3 ) ;
F_13 ( V_3 , V_18 ) ;
F_3 ( V_3 , V_20 , V_21 ) ;
F_11 ( V_3 ) ;
}
static inline void F_15 ( struct V_2 * V_3 , T_1 V_18 )
{
F_9 ( V_3 ) ;
F_13 ( V_3 , V_18 ) ;
F_3 ( V_3 , V_22 , V_21 ) ;
F_11 ( V_3 ) ;
}
static inline void F_16 ( struct V_2 * V_3 , T_1 V_9 , T_1 V_23 )
{
F_4 ( V_9 , V_3 -> V_24 + V_23 ) ;
}
static T_1 F_17 ( struct V_2 * V_3 , T_1 V_23 )
{
return F_6 ( V_3 -> V_24 + V_23 ) ;
}
static inline void F_18 ( struct V_2 * V_3 ,
T_1 V_9 , T_1 V_23 )
{
F_4 ( V_9 , V_3 -> V_25 + V_23 ) ;
}
static T_1 F_19 ( struct V_2 * V_3 , T_1 V_23 )
{
return F_6 ( V_3 -> V_25 + V_23 ) ;
}
static void F_20 ( struct V_2 * V_3 , unsigned long * V_26 )
{
unsigned long V_27 ;
V_27 = F_5 ( V_3 , V_28 ) << 8 ;
V_27 |= F_5 ( V_3 , V_29 ) ;
if ( V_27 )
* V_26 = V_27 ;
else {
F_3 ( V_3 , * V_26 >> 8 , V_28 ) ;
F_3 ( V_3 , * V_26 & 0xff , V_29 ) ;
}
}
static void F_21 ( struct V_30 * V_5 ,
const T_1 * V_31 , int V_32 )
{
T_1 V_33 , V_34 ;
struct V_2 * V_3 = V_5 -> V_35 ;
unsigned long V_36 ;
int V_37 ;
V_33 = F_22 ( V_32 , 10 ) ;
F_23 ( & V_3 -> V_38 , V_36 ) ;
F_24 ( V_3 ) ;
F_18 ( V_3 , V_32 , V_39 ) ;
F_18 ( V_3 , V_33 , V_40 ) ;
V_34 = F_19 ( V_3 , V_41 ) ;
F_18 ( V_3 , V_34 | V_42 ,
V_41 ) ;
if ( V_32 )
F_25 ( L_1 , V_32 ) ;
else
F_25 ( L_2 ) ;
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ )
F_18 ( V_3 , V_31 [ V_37 ] , V_43 ) ;
F_18 ( V_3 , V_34 , V_41 ) ;
F_26 ( & V_3 -> V_38 , V_36 ) ;
}
static T_2 F_27 ( struct V_1 * V_5 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_30 * V_30 = F_28 ( V_5 ) ;
struct V_2 * V_3 = V_30 -> V_35 ;
int V_47 , V_48 ;
unsigned long V_36 ;
T_2 V_49 = 0 ;
int V_37 ;
F_23 ( & V_3 -> V_38 , V_36 ) ;
V_47 = F_19 ( V_3 , V_50 ) ;
V_47 = F_29 ( V_47 , V_51 ) ;
while ( F_19 ( V_3 , V_52 ) )
F_19 ( V_3 , V_53 ) ;
for ( V_37 = 0 ; V_37 < V_47 ; V_37 ++ ) {
V_48 = F_19 ( V_3 , V_53 ) ;
V_48 = ( V_48 & V_54 ) * V_55 ;
V_49 += snprintf ( V_46 + V_49 , V_56 - V_49 ,
L_3 , V_48 ) ;
}
V_49 += snprintf ( V_46 + V_49 , V_56 - V_49 , L_4 ) ;
F_26 ( & V_3 -> V_38 , V_36 ) ;
return V_49 ;
}
static T_2 F_30 ( struct V_1 * V_5 ,
struct V_44 * V_45 ,
const char * V_46 , T_3 V_57 )
{
struct V_30 * V_30 = F_28 ( V_5 ) ;
T_1 V_58 [ V_51 ] ;
char * * V_59 ;
int V_37 , V_32 ;
unsigned int V_9 ;
T_2 V_60 ;
V_59 = F_31 ( V_61 , V_46 , & V_32 ) ;
if ( ! V_59 )
return - V_62 ;
if ( ! V_32 || V_32 > V_51 ) {
V_60 = - V_63 ;
goto V_64;
}
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ ) {
V_60 = F_32 ( V_59 [ V_37 ] , 10 , & V_9 ) ;
if ( V_60 )
goto V_64;
V_9 = F_33 ( V_9 , V_55 ) ;
if ( ! V_9 || V_9 > 0x7f ) {
V_60 = - V_63 ;
goto V_64;
}
V_58 [ V_37 ] = V_9 ;
if ( V_37 % 2 == 0 )
V_58 [ V_37 ] |= V_65 ;
}
F_21 ( V_30 , V_58 , V_32 ) ;
V_60 = V_57 ;
V_64:
F_34 ( V_59 ) ;
return V_60 ;
}
static void F_35 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_13 ( V_3 , V_66 ) ;
F_25 ( L_5 , V_14 ) ;
F_25 ( L_6 ,
F_5 ( V_3 , V_21 ) ) ;
F_25 ( L_7 ,
( F_5 ( V_3 , V_28 ) << 8 ) |
F_5 ( V_3 , V_29 ) ) ;
F_25 ( L_8 ,
F_5 ( V_3 , V_67 ) ) ;
F_11 ( V_3 ) ;
F_25 ( L_9 , V_14 ) ;
F_25 ( L_10 , F_17 ( V_3 , V_68 ) ) ;
F_25 ( L_11 , F_17 ( V_3 , V_69 ) ) ;
F_25 ( L_12 , F_17 ( V_3 , V_70 ) ) ;
F_25 ( L_13 , F_17 ( V_3 , V_71 ) ) ;
F_25 ( L_14 , F_17 ( V_3 , V_72 ) ) ;
F_25 ( L_15 , F_17 ( V_3 , V_73 ) ) ;
F_25 ( L_16 , F_17 ( V_3 , V_74 ) ) ;
F_25 ( L_17 , F_17 ( V_3 , V_75 ) ) ;
F_25 ( L_18 , F_17 ( V_3 , V_76 ) ) ;
F_25 ( L_19 , F_17 ( V_3 , V_77 ) ) ;
F_25 ( L_20 , F_17 ( V_3 , V_78 ) ) ;
F_25 ( L_21 , F_17 ( V_3 , V_79 ) ) ;
F_25 ( L_22 , F_17 ( V_3 , V_80 ) ) ;
F_25 ( L_23 , F_17 ( V_3 , V_81 ) ) ;
F_25 ( L_24 , F_17 ( V_3 , V_82 ) ) ;
F_25 ( L_25 , F_17 ( V_3 , V_83 ) ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
T_1 V_37 , V_47 ;
F_9 ( V_3 ) ;
F_13 ( V_3 , V_84 ) ;
F_25 ( L_26 ,
V_14 ) ;
F_25 ( L_27 ,
F_5 ( V_3 , V_21 ) ) ;
F_25 ( L_28 ,
( F_5 ( V_3 , V_28 ) << 8 ) |
F_5 ( V_3 , V_29 ) ) ;
F_25 ( L_29 ,
F_5 ( V_3 , V_67 ) ) ;
F_11 ( V_3 ) ;
F_25 ( L_30 , V_14 ) ;
F_25 ( L_31 ,
F_19 ( V_3 , V_41 ) ) ;
F_25 ( L_32 ,
F_19 ( V_3 , V_85 ) ) ;
F_25 ( L_33 ,
F_19 ( V_3 , V_86 ) ) ;
F_25 ( L_34 ,
F_19 ( V_3 , V_39 ) ) ;
F_25 ( L_35 ,
F_19 ( V_3 , V_40 ) ) ;
F_25 ( L_36 ,
F_19 ( V_3 , V_50 ) ) ;
F_25 ( L_37 ,
F_19 ( V_3 , V_87 ) ) ;
F_25 ( L_38 ,
F_19 ( V_3 , V_88 ) ) ;
F_25 ( L_39 ,
F_19 ( V_3 , V_89 ) ) ;
F_25 ( L_40 ,
F_19 ( V_3 , V_90 ) ) ;
F_25 ( L_41 ,
F_19 ( V_3 , V_91 ) ) ;
F_25 ( L_42 ,
F_19 ( V_3 , V_43 ) ) ;
F_25 ( L_43 ,
F_19 ( V_3 , V_53 ) ) ;
F_25 ( L_44 ,
F_19 ( V_3 , V_52 ) ) ;
F_25 ( L_45 ,
F_19 ( V_3 , V_92 ) ) ;
F_25 ( L_46 ,
F_19 ( V_3 , V_93 ) ) ;
V_47 = F_19 ( V_3 , V_50 ) ;
F_25 ( L_47 , V_14 , V_47 ) ;
F_25 ( L_48 ) ;
for ( V_37 = 0 ; V_37 < V_47 ; V_37 ++ )
F_37 ( L_49 ,
F_19 ( V_3 , V_53 ) ) ;
F_37 ( L_4 ) ;
}
static inline const char * F_38 ( struct V_2 * V_3 , int V_94 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < F_39 ( V_95 ) ; V_37 ++ )
if ( ( V_94 & V_96 ) == V_95 [ V_37 ] . V_7 ) {
V_3 -> V_7 = V_95 [ V_37 ] . V_7 ;
return V_95 [ V_37 ] . V_97 ;
}
return NULL ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
const char * V_98 ;
int V_99 ;
F_9 ( V_3 ) ;
V_3 -> V_100 = F_5 ( V_3 , V_101 ) ;
if ( V_3 -> V_100 == 0xff ) {
F_11 ( V_3 ) ;
V_3 -> V_11 = V_102 ;
V_3 -> V_12 = V_103 ;
F_9 ( V_3 ) ;
V_3 -> V_100 = F_5 ( V_3 , V_101 ) ;
}
V_3 -> V_104 = F_5 ( V_3 , V_105 ) ;
F_11 ( V_3 ) ;
V_99 = V_3 -> V_100 << 8 | V_3 -> V_104 ;
if ( V_99 == V_106 ) {
F_41 ( V_5 , L_50 ) ;
return - V_107 ;
}
V_98 = F_38 ( V_3 , V_99 ) ;
if ( ! V_98 )
F_42 ( V_5 ,
L_51 ,
V_3 -> V_100 , V_3 -> V_104 ) ;
else
F_43 ( V_5 , L_52 ,
V_98 , V_3 -> V_100 , V_3 -> V_104 ) ;
return 0 ;
}
static void F_44 ( struct V_2 * V_3 )
{
T_1 V_9 , V_108 , V_109 , V_110 ;
if ( F_2 ( V_3 ) ) {
V_108 = V_111 ;
V_109 = V_112 ;
V_110 = V_113 | V_114 ;
} else {
V_108 = V_115 ;
V_109 = V_116 ;
V_110 = V_117 | V_118 ;
}
V_9 = F_5 ( V_3 , V_108 ) ;
V_9 &= V_109 ;
V_9 |= V_110 ;
F_3 ( V_3 , V_9 , V_108 ) ;
F_13 ( V_3 , V_66 ) ;
F_20 ( V_3 , & V_3 -> V_24 ) ;
F_3 ( V_3 , V_3 -> V_119 , V_67 ) ;
F_45 ( L_53 ,
V_3 -> V_24 , V_3 -> V_119 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
F_13 ( V_3 , V_120 ) ;
F_3 ( V_3 , V_20 , V_21 ) ;
F_7 ( V_3 , V_121 , V_122 ) ;
F_7 ( V_3 , V_123 , V_124 ) ;
F_13 ( V_3 , V_84 ) ;
F_20 ( V_3 , & V_3 -> V_25 ) ;
F_45 ( L_54 ,
V_3 -> V_25 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
T_1 V_9 = F_17 ( V_3 , V_76 ) ;
F_16 ( V_3 , V_9 | V_125 , V_76 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
T_1 V_9 , V_34 ;
V_34 = F_19 ( V_3 , V_41 ) ;
F_18 ( V_3 , V_34 & ~ V_126 ,
V_41 ) ;
V_9 = F_19 ( V_3 , V_89 ) ;
F_18 ( V_3 , V_9 | V_127 ,
V_89 ) ;
F_18 ( V_3 , V_34 , V_41 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
T_1 V_9 ;
V_9 = F_17 ( V_3 , V_76 ) ;
F_16 ( V_3 , V_9 | V_128 , V_76 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
T_1 V_129 ;
V_129 = V_130 | V_131 | V_132 ;
F_16 ( V_3 , V_129 , V_70 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_16 ( V_3 , V_133 >> 8 , V_74 ) ;
F_16 ( V_3 , V_133 & 0xff , V_75 ) ;
F_16 ( V_3 , V_134 |
V_135 , V_76 ) ;
F_16 ( V_3 ,
V_136 | V_137 |
V_138 | V_139 ,
V_68 ) ;
F_47 ( V_3 ) ;
F_48 ( V_3 ) ;
F_16 ( V_3 , 0xff , V_69 ) ;
F_49 ( V_3 ) ;
F_14 ( V_3 , V_66 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_18 ( V_3 , V_126 |
V_140 | V_141 |
V_142 ,
V_41 ) ;
F_18 ( V_3 , 0xff , V_85 ) ;
F_14 ( V_3 , V_84 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
unsigned long V_36 ;
F_9 ( V_3 ) ;
F_13 ( V_3 , V_120 ) ;
F_7 ( V_3 , V_121 , V_122 ) ;
F_7 ( V_3 , V_123 , V_124 ) ;
F_13 ( V_3 , V_84 ) ;
F_3 ( V_3 , V_20 , V_21 ) ;
F_11 ( V_3 ) ;
F_23 ( & V_3 -> V_38 , V_36 ) ;
F_18 ( V_3 , V_126 | V_143 |
V_140 | V_141 |
V_142 ,
V_41 ) ;
F_18 ( V_3 , 0xff , V_85 ) ;
F_18 ( V_3 , 0 , V_86 ) ;
F_26 ( & V_3 -> V_38 , V_36 ) ;
}
static int F_53 ( struct V_30 * V_5 , T_4 V_144 )
{
struct V_2 * V_3 = V_5 -> V_35 ;
T_5 V_9 ;
if ( V_144 == 0 )
return - V_63 ;
F_16 ( V_3 , 1 , V_72 ) ;
V_9 = 3000000 / ( V_144 ) - 1 ;
F_16 ( V_3 , V_9 & 0xff , V_73 ) ;
F_45 ( L_55 ,
F_17 ( V_3 , V_72 ) , F_17 ( V_3 , V_73 ) ) ;
return 0 ;
}
static int F_54 ( struct V_30 * V_5 ,
struct V_145 * V_146 )
{
T_1 V_147 ;
int V_37 , V_60 , V_32 ;
unsigned int V_9 ;
struct V_148 * V_149 ;
T_1 V_58 [ V_51 ] ;
bool V_150 ;
if ( ! V_146 -> V_151 )
return 0 ;
V_149 = F_55 ( V_51 , sizeof( * V_149 ) , V_61 ) ;
if ( ! V_149 )
return - V_62 ;
V_60 = F_56 ( V_5 -> V_152 , V_146 -> V_153 ,
V_149 , V_51 ) ;
V_150 = ( V_60 != - V_154 ) ;
if ( ! V_150 )
V_60 = V_51 ;
else if ( V_60 < 0 )
goto V_155;
for ( V_37 = 0 , V_32 = 0 ; V_37 < V_60 && V_32 < V_51 ; ++ V_37 ) {
V_9 = F_22 ( V_149 [ V_37 ] . V_48 , 1000L ) / V_55 ;
while ( V_9 > 0 && V_32 < V_51 ) {
if ( V_150 && V_37 == V_60 - 1 && V_9 < V_54 )
break;
V_147 = ( V_9 > V_54 ) ? V_54 : V_9 ;
V_58 [ V_32 ] = V_147 ;
V_9 -= V_147 ;
if ( ( V_149 [ V_37 ] ) . V_156 )
V_58 [ V_32 ] |= V_65 ;
V_32 ++ ;
}
}
F_21 ( V_5 , V_58 , V_32 ) ;
V_60 = 0 ;
V_155:
F_57 ( V_149 ) ;
return V_60 ;
}
static void F_58 ( struct V_2 * V_3 )
{
int V_37 ;
F_59 ( V_157 L_56 , V_158 , V_3 -> V_159 ) ;
for ( V_37 = 0 ; ( V_37 < V_3 -> V_159 ) && ( V_37 < V_160 ) ; V_37 ++ )
F_59 ( V_161 L_57 , V_3 -> V_46 [ V_37 ] ) ;
F_59 ( V_161 L_4 ) ;
}
static void F_60 ( struct V_2 * V_3 )
{
F_61 ( V_162 ) ;
T_1 V_163 ;
int V_37 ;
F_62 ( L_58 , V_158 ) ;
if ( V_164 )
F_58 ( V_3 ) ;
F_62 ( L_59 , V_3 -> V_159 ) ;
for ( V_37 = 0 ; V_37 < V_3 -> V_159 ; V_37 ++ ) {
V_163 = V_3 -> V_46 [ V_37 ] ;
V_162 . V_156 = ( ( V_163 & V_65 ) != 0 ) ;
V_162 . V_48 = F_63 ( ( V_163 & V_54 )
* V_55 ) ;
F_45 ( L_60 ,
V_162 . V_156 ? L_61 : L_62 , V_162 . V_48 ) ;
F_64 ( V_3 -> V_4 , & V_162 ) ;
}
V_3 -> V_159 = 0 ;
F_45 ( L_63 ) ;
F_65 ( V_3 -> V_4 ) ;
F_62 ( L_64 , V_158 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
F_42 ( F_1 ( V_3 ) , L_65 ) ;
V_3 -> V_159 = 0 ;
F_47 ( V_3 ) ;
F_67 ( V_3 -> V_4 ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
T_1 V_165 ;
int V_37 ;
V_165 = F_17 ( V_3 , V_71 ) ;
F_45 ( L_66 , V_165 ) ;
for ( V_37 = 0 ; V_37 < V_165 ; V_37 ++ )
V_3 -> V_46 [ V_37 ] = F_17 ( V_3 , V_78 ) ;
V_3 -> V_159 = V_165 ;
F_45 ( L_67 , V_158 , V_3 -> V_159 ) ;
F_60 ( V_3 ) ;
}
static void F_69 ( T_1 V_166 , T_1 V_129 )
{
F_45 ( L_68 ,
V_166 , V_129 ,
V_166 & V_167 ? L_69 : L_70 ,
V_166 & V_168 ? L_71 : L_70 ,
V_166 & V_169 ? L_72 : L_70 ,
V_166 & V_170 ? L_73 : L_70 ,
V_166 & V_171 ? L_74 : L_70 ,
V_166 & V_172 ? L_75 : L_70 ,
V_166 & V_173 ? L_76 : L_70 ,
V_166 & V_174 ? L_77 : L_70 ,
V_166 & ~ ( V_167 | V_168 | V_169 |
V_170 | V_171 | V_172 |
V_173 | V_174 ) ? L_78 : L_70 ) ;
}
static T_6 F_70 ( int V_175 , void * V_153 )
{
struct V_2 * V_3 = V_153 ;
T_1 V_166 , V_129 ;
F_62 ( L_58 , V_158 ) ;
F_71 ( & V_3 -> V_38 ) ;
V_166 = F_17 ( V_3 , V_69 ) ;
V_129 = F_17 ( V_3 , V_70 ) ;
if ( V_166 == 0xff && V_129 == 0xff ) {
F_72 ( & V_3 -> V_38 ) ;
F_62 ( L_79 ) ;
return V_176 ;
}
if ( ! ( V_166 & V_129 ) ) {
F_72 ( & V_3 -> V_38 ) ;
F_62 ( L_80 , V_158 ) ;
return V_177 ;
}
F_16 ( V_3 , V_166 , V_69 ) ;
F_16 ( V_3 , 0 , V_69 ) ;
F_69 ( V_166 , V_129 ) ;
if ( V_166 & V_170 )
F_66 ( V_3 ) ;
else if ( V_166 & ( V_168 | V_169 ) )
F_68 ( V_3 ) ;
F_72 ( & V_3 -> V_38 ) ;
F_62 ( L_64 , V_158 ) ;
return V_176 ;
}
static void F_73 ( struct V_2 * V_3 )
{
unsigned long V_36 ;
F_23 ( & V_3 -> V_38 , V_36 ) ;
F_16 ( V_3 , 0 , V_70 ) ;
F_16 ( V_3 , 0xff , V_69 ) ;
F_16 ( V_3 , 0 , V_68 ) ;
F_47 ( V_3 ) ;
F_48 ( V_3 ) ;
F_26 ( & V_3 -> V_38 , V_36 ) ;
F_15 ( V_3 , V_66 ) ;
}
static int F_74 ( struct V_30 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_35 ;
unsigned long V_36 ;
F_23 ( & V_3 -> V_38 , V_36 ) ;
F_16 ( V_3 , V_136 | V_137 |
V_138 | V_139 ,
V_68 ) ;
F_16 ( V_3 , 0xff , V_69 ) ;
F_49 ( V_3 ) ;
F_26 ( & V_3 -> V_38 , V_36 ) ;
F_14 ( V_3 , V_66 ) ;
return 0 ;
}
static void F_75 ( struct V_30 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_35 ;
F_73 ( V_3 ) ;
}
static int F_76 ( struct V_178 * V_179 , const struct V_180 * V_181 )
{
struct V_2 * V_3 ;
struct V_30 * V_4 ;
int V_60 ;
V_3 = F_77 ( & V_179 -> V_5 , sizeof( struct V_2 ) , V_61 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_4 = F_78 ( & V_179 -> V_5 , V_182 ) ;
if ( ! V_3 -> V_4 )
return - V_62 ;
V_4 = V_3 -> V_4 ;
V_60 = F_79 ( V_179 ) ;
if ( V_60 ) {
F_41 ( & V_179 -> V_5 , L_81 ) ;
return V_60 ;
}
if ( ! F_80 ( V_179 , 0 ) ||
F_81 ( V_179 , 0 ) < V_183 ) {
F_41 ( & V_179 -> V_5 , L_82 ) ;
return - V_63 ;
}
if ( ! F_82 ( V_179 , 0 ) ) {
F_41 ( & V_179 -> V_5 , L_83 ) ;
return - V_63 ;
}
if ( ! F_80 ( V_179 , 1 ) ||
F_81 ( V_179 , 1 ) < V_183 ) {
F_41 ( & V_179 -> V_5 , L_84 ) ;
return - V_63 ;
}
V_3 -> V_24 = F_83 ( V_179 , 0 ) ;
V_3 -> V_119 = F_84 ( V_179 , 0 ) ;
V_3 -> V_25 = F_83 ( V_179 , 1 ) ;
V_3 -> V_11 = V_184 ;
V_3 -> V_12 = V_185 ;
F_85 ( & V_3 -> V_38 ) ;
F_86 ( V_179 , V_3 ) ;
V_60 = F_40 ( V_3 ) ;
if ( V_60 )
return V_60 ;
F_9 ( V_3 ) ;
F_44 ( V_3 ) ;
F_46 ( V_3 ) ;
F_11 ( V_3 ) ;
F_50 ( V_3 ) ;
F_51 ( V_3 ) ;
V_4 -> V_35 = V_3 ;
V_4 -> V_186 = V_187 ;
V_4 -> V_188 = V_189 ;
V_4 -> V_190 = true ;
V_4 -> V_191 = F_74 ;
V_4 -> V_192 = F_75 ;
V_4 -> V_193 = F_53 ;
V_4 -> V_194 = F_54 ;
V_4 -> V_195 = L_85 ;
V_4 -> V_196 = L_86 ;
V_4 -> V_197 . V_198 = V_199 ;
V_4 -> V_197 . V_200 = V_201 ;
V_4 -> V_197 . V_202 = V_3 -> V_100 ;
V_4 -> V_197 . V_203 = V_3 -> V_104 ;
V_4 -> V_204 = V_14 ;
V_4 -> V_205 = V_206 ;
V_4 -> V_207 = F_87 ( 100 ) ;
V_4 -> V_208 = F_63 ( V_209 ) ;
#if 0
rdev->min_timeout = XYZ;
rdev->max_timeout = XYZ;
#endif
V_60 = F_88 ( & V_179 -> V_5 , V_4 ) ;
if ( V_60 )
return V_60 ;
if ( ! F_89 ( & V_179 -> V_5 , V_3 -> V_24 ,
V_183 , V_14 ) )
return - V_15 ;
V_60 = F_90 ( & V_179 -> V_5 , V_3 -> V_119 , F_70 ,
V_210 , V_14 , V_3 ) ;
if ( V_60 )
return V_60 ;
if ( ! F_89 ( & V_179 -> V_5 , V_3 -> V_25 ,
V_183 , V_14 L_87 ) )
return - V_15 ;
V_60 = F_91 ( & V_4 -> V_5 , & V_211 ) ;
if ( V_60 )
return V_60 ;
F_92 ( & V_179 -> V_5 , true ) ;
F_93 ( & V_179 -> V_5 , L_88 ) ;
if ( V_164 ) {
F_35 ( V_3 ) ;
F_36 ( V_3 ) ;
}
return 0 ;
}
static void F_94 ( struct V_178 * V_179 )
{
struct V_2 * V_3 = F_95 ( V_179 ) ;
F_96 ( & V_3 -> V_4 -> V_5 , & V_211 ) ;
F_73 ( V_3 ) ;
F_52 ( V_3 ) ;
}
static int F_97 ( struct V_178 * V_179 , T_7 V_212 )
{
struct V_2 * V_3 = F_95 ( V_179 ) ;
unsigned long V_36 ;
F_45 ( L_89 , V_158 ) ;
F_23 ( & V_3 -> V_38 , V_36 ) ;
F_16 ( V_3 , 0 , V_70 ) ;
F_26 ( & V_3 -> V_38 , V_36 ) ;
F_15 ( V_3 , V_66 ) ;
F_52 ( V_3 ) ;
return 0 ;
}
static int F_98 ( struct V_178 * V_179 )
{
struct V_2 * V_3 = F_95 ( V_179 ) ;
F_45 ( L_89 , V_158 ) ;
F_50 ( V_3 ) ;
F_51 ( V_3 ) ;
return 0 ;
}
static void F_99 ( struct V_178 * V_179 )
{
struct V_2 * V_3 = F_95 ( V_179 ) ;
F_52 ( V_3 ) ;
}
