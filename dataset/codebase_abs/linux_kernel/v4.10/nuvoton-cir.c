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
static T_2 F_21 ( struct V_1 * V_5 ,
struct V_30 * V_31 ,
char * V_32 )
{
struct V_33 * V_33 = F_22 ( V_5 ) ;
struct V_2 * V_3 = V_33 -> V_34 ;
int V_35 , V_36 ;
unsigned long V_37 ;
T_2 V_38 = 0 ;
int V_39 ;
F_23 ( & V_3 -> V_40 , V_37 ) ;
V_35 = F_19 ( V_3 , V_41 ) ;
V_35 = F_24 ( V_35 , V_42 ) ;
while ( F_19 ( V_3 , V_43 ) )
F_19 ( V_3 , V_44 ) ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 ++ ) {
V_36 = F_19 ( V_3 , V_44 ) ;
V_36 = ( V_36 & V_45 ) * V_46 ;
V_38 += snprintf ( V_32 + V_38 , V_47 - V_38 ,
L_1 , V_36 ) ;
}
V_38 += snprintf ( V_32 + V_38 , V_47 - V_38 , L_2 ) ;
F_25 ( & V_3 -> V_40 , V_37 ) ;
return V_38 ;
}
static T_2 F_26 ( struct V_1 * V_5 ,
struct V_30 * V_31 ,
const char * V_32 , T_3 V_48 )
{
struct V_33 * V_33 = F_22 ( V_5 ) ;
struct V_2 * V_3 = V_33 -> V_34 ;
unsigned long V_37 ;
T_1 V_49 , V_50 , V_51 [ V_42 ] ;
char * * V_52 ;
int V_39 , V_53 ;
unsigned int V_9 ;
T_2 V_54 ;
V_52 = F_27 ( V_55 , V_32 , & V_53 ) ;
if ( ! V_52 )
return - V_56 ;
if ( ! V_53 || V_53 > V_42 ) {
V_54 = - V_57 ;
goto V_58;
}
for ( V_39 = 0 ; V_39 < V_53 ; V_39 ++ ) {
V_54 = F_28 ( V_52 [ V_39 ] , 10 , & V_9 ) ;
if ( V_54 )
goto V_58;
V_9 = F_29 ( V_9 , V_46 ) ;
if ( ! V_9 || V_9 > 0x7f ) {
V_54 = - V_57 ;
goto V_58;
}
V_51 [ V_39 ] = V_9 ;
if ( V_39 % 2 == 0 )
V_51 [ V_39 ] |= V_59 ;
}
V_49 = F_30 ( V_53 , 10 ) ;
F_23 ( & V_3 -> V_40 , V_37 ) ;
F_31 ( V_3 ) ;
F_18 ( V_3 , V_53 , V_60 ) ;
F_18 ( V_3 , V_49 , V_61 ) ;
V_50 = F_19 ( V_3 , V_62 ) ;
F_18 ( V_3 , V_50 | V_63 ,
V_62 ) ;
for ( V_39 = 0 ; V_39 < V_53 ; V_39 ++ )
F_18 ( V_3 , V_51 [ V_39 ] , V_64 ) ;
F_18 ( V_3 , V_50 , V_62 ) ;
F_25 ( & V_3 -> V_40 , V_37 ) ;
V_54 = V_48 ;
V_58:
F_32 ( V_52 ) ;
return V_54 ;
}
static void F_33 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_13 ( V_3 , V_65 ) ;
F_34 ( L_3 , V_14 ) ;
F_34 ( L_4 ,
F_5 ( V_3 , V_21 ) ) ;
F_34 ( L_5 ,
( F_5 ( V_3 , V_28 ) << 8 ) |
F_5 ( V_3 , V_29 ) ) ;
F_34 ( L_6 ,
F_5 ( V_3 , V_66 ) ) ;
F_11 ( V_3 ) ;
F_34 ( L_7 , V_14 ) ;
F_34 ( L_8 , F_17 ( V_3 , V_67 ) ) ;
F_34 ( L_9 , F_17 ( V_3 , V_68 ) ) ;
F_34 ( L_10 , F_17 ( V_3 , V_69 ) ) ;
F_34 ( L_11 , F_17 ( V_3 , V_70 ) ) ;
F_34 ( L_12 , F_17 ( V_3 , V_71 ) ) ;
F_34 ( L_13 , F_17 ( V_3 , V_72 ) ) ;
F_34 ( L_14 , F_17 ( V_3 , V_73 ) ) ;
F_34 ( L_15 , F_17 ( V_3 , V_74 ) ) ;
F_34 ( L_16 , F_17 ( V_3 , V_75 ) ) ;
F_34 ( L_17 , F_17 ( V_3 , V_76 ) ) ;
F_34 ( L_18 , F_17 ( V_3 , V_77 ) ) ;
F_34 ( L_19 , F_17 ( V_3 , V_78 ) ) ;
F_34 ( L_20 , F_17 ( V_3 , V_79 ) ) ;
F_34 ( L_21 , F_17 ( V_3 , V_80 ) ) ;
F_34 ( L_22 , F_17 ( V_3 , V_81 ) ) ;
F_34 ( L_23 , F_17 ( V_3 , V_82 ) ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
T_1 V_39 , V_35 ;
F_9 ( V_3 ) ;
F_13 ( V_3 , V_83 ) ;
F_34 ( L_24 ,
V_14 ) ;
F_34 ( L_25 ,
F_5 ( V_3 , V_21 ) ) ;
F_34 ( L_26 ,
( F_5 ( V_3 , V_28 ) << 8 ) |
F_5 ( V_3 , V_29 ) ) ;
F_34 ( L_27 ,
F_5 ( V_3 , V_66 ) ) ;
F_11 ( V_3 ) ;
F_34 ( L_28 , V_14 ) ;
F_34 ( L_29 ,
F_19 ( V_3 , V_62 ) ) ;
F_34 ( L_30 ,
F_19 ( V_3 , V_84 ) ) ;
F_34 ( L_31 ,
F_19 ( V_3 , V_85 ) ) ;
F_34 ( L_32 ,
F_19 ( V_3 , V_60 ) ) ;
F_34 ( L_33 ,
F_19 ( V_3 , V_61 ) ) ;
F_34 ( L_34 ,
F_19 ( V_3 , V_41 ) ) ;
F_34 ( L_35 ,
F_19 ( V_3 , V_86 ) ) ;
F_34 ( L_36 ,
F_19 ( V_3 , V_87 ) ) ;
F_34 ( L_37 ,
F_19 ( V_3 , V_88 ) ) ;
F_34 ( L_38 ,
F_19 ( V_3 , V_89 ) ) ;
F_34 ( L_39 ,
F_19 ( V_3 , V_90 ) ) ;
F_34 ( L_40 ,
F_19 ( V_3 , V_64 ) ) ;
F_34 ( L_41 ,
F_19 ( V_3 , V_44 ) ) ;
F_34 ( L_42 ,
F_19 ( V_3 , V_43 ) ) ;
F_34 ( L_43 ,
F_19 ( V_3 , V_91 ) ) ;
F_34 ( L_44 ,
F_19 ( V_3 , V_92 ) ) ;
V_35 = F_19 ( V_3 , V_41 ) ;
F_34 ( L_45 , V_14 , V_35 ) ;
F_34 ( L_46 ) ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 ++ )
F_36 ( L_47 ,
F_19 ( V_3 , V_44 ) ) ;
F_36 ( L_2 ) ;
}
static inline const char * F_37 ( struct V_2 * V_3 , int V_93 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_38 ( V_94 ) ; V_39 ++ )
if ( ( V_93 & V_95 ) == V_94 [ V_39 ] . V_7 ) {
V_3 -> V_7 = V_94 [ V_39 ] . V_7 ;
return V_94 [ V_39 ] . V_96 ;
}
return NULL ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
const char * V_97 ;
int V_98 ;
F_9 ( V_3 ) ;
V_3 -> V_99 = F_5 ( V_3 , V_100 ) ;
if ( V_3 -> V_99 == 0xff ) {
F_11 ( V_3 ) ;
V_3 -> V_11 = V_101 ;
V_3 -> V_12 = V_102 ;
F_9 ( V_3 ) ;
V_3 -> V_99 = F_5 ( V_3 , V_100 ) ;
}
V_3 -> V_103 = F_5 ( V_3 , V_104 ) ;
F_11 ( V_3 ) ;
V_98 = V_3 -> V_99 << 8 | V_3 -> V_103 ;
if ( V_98 == V_105 ) {
F_40 ( V_5 , L_48 ) ;
return - V_106 ;
}
V_97 = F_37 ( V_3 , V_98 ) ;
if ( ! V_97 )
F_41 ( V_5 ,
L_49 ,
V_3 -> V_99 , V_3 -> V_103 ) ;
else
F_42 ( V_5 , L_50 ,
V_97 , V_3 -> V_99 , V_3 -> V_103 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
T_1 V_9 , V_107 , V_108 , V_109 ;
if ( F_2 ( V_3 ) ) {
V_107 = V_110 ;
V_108 = V_111 ;
V_109 = V_112 | V_113 ;
} else {
V_107 = V_114 ;
V_108 = V_115 ;
V_109 = V_116 | V_117 ;
}
V_9 = F_5 ( V_3 , V_107 ) ;
V_9 &= V_108 ;
V_9 |= V_109 ;
F_3 ( V_3 , V_9 , V_107 ) ;
F_13 ( V_3 , V_65 ) ;
F_20 ( V_3 , & V_3 -> V_24 ) ;
F_3 ( V_3 , V_3 -> V_118 , V_66 ) ;
F_44 ( L_51 ,
V_3 -> V_24 , V_3 -> V_118 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
F_13 ( V_3 , V_119 ) ;
F_3 ( V_3 , V_20 , V_21 ) ;
F_7 ( V_3 , V_120 , V_121 ) ;
F_7 ( V_3 , V_122 , V_123 ) ;
F_13 ( V_3 , V_83 ) ;
F_20 ( V_3 , & V_3 -> V_25 ) ;
F_44 ( L_52 ,
V_3 -> V_25 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
T_1 V_9 = F_17 ( V_3 , V_75 ) ;
F_16 ( V_3 , V_9 | V_124 , V_75 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
T_1 V_9 , V_50 ;
V_50 = F_19 ( V_3 , V_62 ) ;
F_18 ( V_3 , V_50 & ~ V_125 ,
V_62 ) ;
V_9 = F_19 ( V_3 , V_88 ) ;
F_18 ( V_3 , V_9 | V_126 ,
V_88 ) ;
F_18 ( V_3 , V_50 , V_62 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
T_1 V_9 ;
V_9 = F_17 ( V_3 , V_75 ) ;
F_16 ( V_3 , V_9 | V_127 , V_75 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
T_1 V_128 ;
V_128 = V_129 | V_130 | V_131 ;
F_16 ( V_3 , V_128 , V_69 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_16 ( V_3 , V_132 >> 8 , V_73 ) ;
F_16 ( V_3 , V_132 & 0xff , V_74 ) ;
F_16 ( V_3 , V_133 |
V_134 , V_75 ) ;
F_16 ( V_3 ,
V_135 | V_136 |
V_137 | V_138 ,
V_67 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 ) ;
F_16 ( V_3 , 0xff , V_68 ) ;
F_48 ( V_3 ) ;
F_14 ( V_3 , V_65 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_18 ( V_3 , V_125 |
V_139 | V_140 |
V_141 ,
V_62 ) ;
F_18 ( V_3 , 0xff , V_84 ) ;
F_14 ( V_3 , V_83 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
unsigned long V_37 ;
F_9 ( V_3 ) ;
F_13 ( V_3 , V_119 ) ;
F_7 ( V_3 , V_120 , V_121 ) ;
F_7 ( V_3 , V_122 , V_123 ) ;
F_13 ( V_3 , V_83 ) ;
F_3 ( V_3 , V_20 , V_21 ) ;
F_11 ( V_3 ) ;
F_23 ( & V_3 -> V_40 , V_37 ) ;
F_18 ( V_3 , V_125 | V_142 |
V_139 | V_140 |
V_141 ,
V_62 ) ;
F_18 ( V_3 , 0xff , V_84 ) ;
F_18 ( V_3 , 0 , V_85 ) ;
F_25 ( & V_3 -> V_40 , V_37 ) ;
}
static int F_52 ( struct V_33 * V_5 , T_4 V_143 )
{
struct V_2 * V_3 = V_5 -> V_34 ;
T_5 V_9 ;
if ( V_143 == 0 )
return - V_57 ;
F_16 ( V_3 , 1 , V_71 ) ;
V_9 = 3000000 / ( V_143 ) - 1 ;
F_16 ( V_3 , V_9 & 0xff , V_72 ) ;
F_44 ( L_53 ,
F_17 ( V_3 , V_71 ) , F_17 ( V_3 , V_72 ) ) ;
return 0 ;
}
static int F_53 ( struct V_33 * V_5 , unsigned * V_144 , unsigned V_145 )
{
struct V_2 * V_3 = V_5 -> V_34 ;
unsigned long V_37 ;
unsigned int V_39 ;
T_1 V_128 ;
int V_54 ;
F_23 ( & V_3 -> V_40 , V_37 ) ;
V_54 = F_24 ( ( unsigned ) ( V_146 / sizeof( unsigned ) ) , V_145 ) ;
V_3 -> V_147 . V_148 = ( V_54 * sizeof( unsigned ) ) ;
memcpy ( V_3 -> V_147 . V_32 , V_144 , V_3 -> V_147 . V_148 ) ;
V_3 -> V_147 . V_149 = 0 ;
V_128 = F_17 ( V_3 , V_69 ) ;
F_16 ( V_3 , V_150 | V_151 , V_69 ) ;
V_3 -> V_147 . V_152 = V_153 ;
F_16 ( V_3 , V_154 |
V_124 , V_75 ) ;
for ( V_39 = 0 ; V_39 < 9 ; V_39 ++ )
F_16 ( V_3 , 0x01 , V_79 ) ;
F_25 ( & V_3 -> V_40 , V_37 ) ;
F_54 ( V_3 -> V_147 . V_155 , V_3 -> V_147 . V_152 == V_156 ) ;
F_23 ( & V_3 -> V_40 , V_37 ) ;
V_3 -> V_147 . V_152 = V_157 ;
F_25 ( & V_3 -> V_40 , V_37 ) ;
F_16 ( V_3 , V_128 , V_69 ) ;
return V_54 ;
}
static void F_55 ( struct V_2 * V_3 )
{
int V_39 ;
F_56 ( V_158 L_54 , V_159 , V_3 -> V_160 ) ;
for ( V_39 = 0 ; ( V_39 < V_3 -> V_160 ) && ( V_39 < V_161 ) ; V_39 ++ )
F_56 ( V_162 L_55 , V_3 -> V_32 [ V_39 ] ) ;
F_56 ( V_162 L_2 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_58 ( V_163 ) ;
T_1 V_164 ;
int V_39 ;
F_59 ( L_56 , V_159 ) ;
if ( V_165 )
F_55 ( V_3 ) ;
F_59 ( L_57 , V_3 -> V_160 ) ;
for ( V_39 = 0 ; V_39 < V_3 -> V_160 ; V_39 ++ ) {
V_164 = V_3 -> V_32 [ V_39 ] ;
V_163 . V_166 = ( ( V_164 & V_59 ) != 0 ) ;
V_163 . V_36 = F_60 ( ( V_164 & V_45 )
* V_46 ) ;
F_44 ( L_58 ,
V_163 . V_166 ? L_59 : L_60 , V_163 . V_36 ) ;
F_61 ( V_3 -> V_4 , & V_163 ) ;
}
V_3 -> V_160 = 0 ;
F_44 ( L_61 ) ;
F_62 ( V_3 -> V_4 ) ;
F_59 ( L_62 , V_159 ) ;
}
static void F_63 ( struct V_2 * V_3 )
{
F_41 ( F_1 ( V_3 ) , L_63 ) ;
V_3 -> V_160 = 0 ;
F_46 ( V_3 ) ;
F_64 ( V_3 -> V_4 ) ;
}
static void F_65 ( struct V_2 * V_3 )
{
T_1 V_167 ;
int V_39 ;
V_167 = F_17 ( V_3 , V_70 ) ;
F_44 ( L_64 , V_167 ) ;
for ( V_39 = 0 ; V_39 < V_167 ; V_39 ++ )
V_3 -> V_32 [ V_39 ] = F_17 ( V_3 , V_77 ) ;
V_3 -> V_160 = V_167 ;
F_44 ( L_65 , V_159 , V_3 -> V_160 ) ;
F_57 ( V_3 ) ;
}
static void F_66 ( T_1 V_168 , T_1 V_128 )
{
F_44 ( L_66 ,
V_168 , V_128 ,
V_168 & V_169 ? L_67 : L_68 ,
V_168 & V_170 ? L_69 : L_68 ,
V_168 & V_171 ? L_70 : L_68 ,
V_168 & V_172 ? L_71 : L_68 ,
V_168 & V_173 ? L_72 : L_68 ,
V_168 & V_174 ? L_73 : L_68 ,
V_168 & V_175 ? L_74 : L_68 ,
V_168 & V_176 ? L_75 : L_68 ,
V_168 & ~ ( V_169 | V_170 | V_171 |
V_172 | V_173 | V_174 |
V_175 | V_176 ) ? L_76 : L_68 ) ;
}
static bool F_67 ( struct V_2 * V_3 )
{
return V_3 -> V_147 . V_152 == V_157 ;
}
static T_6 F_68 ( int V_177 , void * V_178 )
{
struct V_2 * V_3 = V_178 ;
T_1 V_168 , V_128 ;
F_59 ( L_56 , V_159 ) ;
F_69 ( & V_3 -> V_40 ) ;
V_168 = F_17 ( V_3 , V_68 ) ;
V_128 = F_17 ( V_3 , V_69 ) ;
if ( V_168 == 0xff && V_128 == 0xff ) {
F_70 ( & V_3 -> V_40 ) ;
F_59 ( L_77 ) ;
return V_179 ;
}
if ( ! ( V_168 & V_128 ) ) {
F_70 ( & V_3 -> V_40 ) ;
F_59 ( L_78 , V_159 ) ;
return V_180 ;
}
F_16 ( V_3 , V_168 , V_68 ) ;
F_16 ( V_3 , 0 , V_68 ) ;
F_66 ( V_168 , V_128 ) ;
if ( V_168 & V_172 )
F_63 ( V_3 ) ;
else if ( V_168 & ( V_170 | V_171 ) ) {
if ( F_67 ( V_3 ) )
F_65 ( V_3 ) ;
}
if ( V_168 & V_173 )
F_47 ( V_3 ) ;
if ( V_168 & V_174 ) {
unsigned int V_181 , V_53 ;
T_1 V_13 ;
V_181 = V_3 -> V_147 . V_149 ;
V_53 = V_3 -> V_147 . V_148 ;
if ( V_181 < V_53 ) {
F_16 ( V_3 , V_3 -> V_147 . V_32 [ V_181 ] , V_79 ) ;
V_3 -> V_147 . V_149 ++ ;
} else {
V_13 = F_17 ( V_3 , V_69 ) ;
F_16 ( V_3 , V_13 & ~ V_151 , V_69 ) ;
}
}
if ( V_168 & V_175 ) {
if ( V_3 -> V_147 . V_152 == V_153 ) {
V_3 -> V_147 . V_152 = V_156 ;
F_71 ( & V_3 -> V_147 . V_155 ) ;
}
}
F_70 ( & V_3 -> V_40 ) ;
F_59 ( L_62 , V_159 ) ;
return V_179 ;
}
static void F_72 ( struct V_2 * V_3 )
{
unsigned long V_37 ;
F_23 ( & V_3 -> V_40 , V_37 ) ;
F_16 ( V_3 , 0 , V_69 ) ;
F_16 ( V_3 , 0xff , V_68 ) ;
F_16 ( V_3 , 0 , V_67 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 ) ;
F_25 ( & V_3 -> V_40 , V_37 ) ;
F_15 ( V_3 , V_65 ) ;
}
static int F_73 ( struct V_33 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_34 ;
unsigned long V_37 ;
F_23 ( & V_3 -> V_40 , V_37 ) ;
F_16 ( V_3 , V_135 | V_136 |
V_137 | V_138 ,
V_67 ) ;
F_16 ( V_3 , 0xff , V_68 ) ;
F_48 ( V_3 ) ;
F_25 ( & V_3 -> V_40 , V_37 ) ;
F_14 ( V_3 , V_65 ) ;
return 0 ;
}
static void F_74 ( struct V_33 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_34 ;
F_72 ( V_3 ) ;
}
static int F_75 ( struct V_182 * V_183 , const struct V_184 * V_185 )
{
struct V_2 * V_3 ;
struct V_33 * V_4 ;
int V_54 ;
V_3 = F_76 ( & V_183 -> V_5 , sizeof( struct V_2 ) , V_55 ) ;
if ( ! V_3 )
return - V_56 ;
V_3 -> V_4 = F_77 ( & V_183 -> V_5 ) ;
if ( ! V_3 -> V_4 )
return - V_56 ;
V_4 = V_3 -> V_4 ;
V_54 = F_78 ( V_183 ) ;
if ( V_54 ) {
F_40 ( & V_183 -> V_5 , L_79 ) ;
return V_54 ;
}
if ( ! F_79 ( V_183 , 0 ) ||
F_80 ( V_183 , 0 ) < V_186 ) {
F_40 ( & V_183 -> V_5 , L_80 ) ;
return - V_57 ;
}
if ( ! F_81 ( V_183 , 0 ) ) {
F_40 ( & V_183 -> V_5 , L_81 ) ;
return - V_57 ;
}
if ( ! F_79 ( V_183 , 1 ) ||
F_80 ( V_183 , 1 ) < V_186 ) {
F_40 ( & V_183 -> V_5 , L_82 ) ;
return - V_57 ;
}
V_3 -> V_24 = F_82 ( V_183 , 0 ) ;
V_3 -> V_118 = F_83 ( V_183 , 0 ) ;
V_3 -> V_25 = F_82 ( V_183 , 1 ) ;
V_3 -> V_11 = V_187 ;
V_3 -> V_12 = V_188 ;
F_84 ( & V_3 -> V_40 ) ;
F_85 ( V_183 , V_3 ) ;
F_86 ( & V_3 -> V_147 . V_155 ) ;
V_54 = F_39 ( V_3 ) ;
if ( V_54 )
return V_54 ;
F_9 ( V_3 ) ;
F_43 ( V_3 ) ;
F_45 ( V_3 ) ;
F_11 ( V_3 ) ;
F_49 ( V_3 ) ;
F_50 ( V_3 ) ;
V_4 -> V_34 = V_3 ;
V_4 -> V_189 = V_190 ;
V_4 -> V_191 = V_192 ;
V_4 -> V_193 = F_73 ;
V_4 -> V_194 = F_74 ;
V_4 -> V_195 = F_53 ;
V_4 -> V_196 = F_52 ;
V_4 -> V_197 = L_83 ;
V_4 -> V_198 = L_84 ;
V_4 -> V_199 . V_200 = V_201 ;
V_4 -> V_199 . V_202 = V_203 ;
V_4 -> V_199 . V_204 = V_3 -> V_99 ;
V_4 -> V_199 . V_205 = V_3 -> V_103 ;
V_4 -> V_206 = V_14 ;
V_4 -> V_207 = V_208 ;
V_4 -> V_209 = F_87 ( 100 ) ;
V_4 -> V_210 = F_60 ( V_211 ) ;
#if 0
rdev->min_timeout = XYZ;
rdev->max_timeout = XYZ;
rdev->tx_resolution = XYZ;
#endif
V_54 = F_88 ( & V_183 -> V_5 , V_4 ) ;
if ( V_54 )
return V_54 ;
if ( ! F_89 ( & V_183 -> V_5 , V_3 -> V_24 ,
V_186 , V_14 ) )
return - V_15 ;
V_54 = F_90 ( & V_183 -> V_5 , V_3 -> V_118 , F_68 ,
V_212 , V_14 , V_3 ) ;
if ( V_54 )
return V_54 ;
if ( ! F_89 ( & V_183 -> V_5 , V_3 -> V_25 ,
V_186 , V_14 L_85 ) )
return - V_15 ;
V_54 = F_91 ( & V_4 -> V_5 , & V_213 ) ;
if ( V_54 )
return V_54 ;
F_92 ( & V_183 -> V_5 , true ) ;
F_93 ( & V_183 -> V_5 , L_86 ) ;
if ( V_165 ) {
F_33 ( V_3 ) ;
F_35 ( V_3 ) ;
}
return 0 ;
}
static void F_94 ( struct V_182 * V_183 )
{
struct V_2 * V_3 = F_95 ( V_183 ) ;
F_96 ( & V_3 -> V_4 -> V_5 , & V_213 ) ;
F_72 ( V_3 ) ;
F_51 ( V_3 ) ;
}
static int F_97 ( struct V_182 * V_183 , T_7 V_214 )
{
struct V_2 * V_3 = F_95 ( V_183 ) ;
unsigned long V_37 ;
F_44 ( L_87 , V_159 ) ;
F_23 ( & V_3 -> V_40 , V_37 ) ;
V_3 -> V_147 . V_152 = V_157 ;
F_16 ( V_3 , 0 , V_69 ) ;
F_25 ( & V_3 -> V_40 , V_37 ) ;
F_15 ( V_3 , V_65 ) ;
F_51 ( V_3 ) ;
return 0 ;
}
static int F_98 ( struct V_182 * V_183 )
{
struct V_2 * V_3 = F_95 ( V_183 ) ;
F_44 ( L_87 , V_159 ) ;
F_49 ( V_3 ) ;
F_50 ( V_3 ) ;
return 0 ;
}
static void F_99 ( struct V_182 * V_183 )
{
struct V_2 * V_3 = F_95 ( V_183 ) ;
F_51 ( V_3 ) ;
}
