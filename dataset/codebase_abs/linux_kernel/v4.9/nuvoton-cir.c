static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_6 )
{
F_3 ( V_6 , V_2 -> V_7 ) ;
F_3 ( V_5 , V_2 -> V_8 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_1 V_6 )
{
F_3 ( V_6 , V_2 -> V_7 ) ;
return F_5 ( V_2 -> V_8 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_6 )
{
T_1 V_9 = F_4 ( V_2 , V_6 ) | V_5 ;
F_2 ( V_2 , V_9 , V_6 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_6 )
{
T_1 V_9 = F_4 ( V_2 , V_6 ) & ~ V_5 ;
F_2 ( V_2 , V_9 , V_6 ) ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
if ( ! F_9 ( V_2 -> V_7 , 2 , V_10 ) )
return - V_11 ;
F_3 ( V_12 , V_2 -> V_7 ) ;
F_3 ( V_12 , V_2 -> V_7 ) ;
return 0 ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_3 ( V_13 , V_2 -> V_7 ) ;
F_11 ( V_2 -> V_7 , 2 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , T_1 V_14 )
{
F_2 ( V_2 , V_14 , V_15 ) ;
}
static inline void F_13 ( struct V_1 * V_2 , T_1 V_14 )
{
F_8 ( V_2 ) ;
F_12 ( V_2 , V_14 ) ;
F_2 ( V_2 , V_16 , V_17 ) ;
F_10 ( V_2 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_1 V_14 )
{
F_8 ( V_2 ) ;
F_12 ( V_2 , V_14 ) ;
F_2 ( V_2 , V_18 , V_17 ) ;
F_10 ( V_2 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_19 )
{
F_3 ( V_5 , V_2 -> V_20 + V_19 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 V_19 )
{
return F_5 ( V_2 -> V_20 + V_19 ) ;
}
static inline void F_17 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_19 )
{
F_3 ( V_5 , V_2 -> V_21 + V_19 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_1 V_19 )
{
return F_5 ( V_2 -> V_21 + V_19 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned long * V_22 )
{
unsigned long V_23 ;
V_23 = F_4 ( V_2 , V_24 ) << 8 ;
V_23 |= F_4 ( V_2 , V_25 ) ;
if ( V_23 )
* V_22 = V_23 ;
else {
F_2 ( V_2 , * V_22 >> 8 , V_24 ) ;
F_2 ( V_2 , * V_22 & 0xff , V_25 ) ;
}
}
static T_2 F_20 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_31 = F_21 ( V_27 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
int V_33 , V_34 ;
unsigned long V_35 ;
T_2 V_36 = 0 ;
int V_37 ;
F_22 ( & V_2 -> V_38 , V_35 ) ;
V_33 = F_18 ( V_2 , V_39 ) ;
V_33 = F_23 ( V_33 , V_40 ) ;
while ( F_18 ( V_2 , V_41 ) )
F_18 ( V_2 , V_42 ) ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ ) {
V_34 = F_18 ( V_2 , V_42 ) ;
V_34 = ( V_34 & V_43 ) * V_44 ;
V_36 += snprintf ( V_30 + V_36 , V_45 - V_36 ,
L_1 , V_34 ) ;
}
V_36 += snprintf ( V_30 + V_36 , V_45 - V_36 , L_2 ) ;
F_24 ( & V_2 -> V_38 , V_35 ) ;
return V_36 ;
}
static T_2 F_25 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_30 , T_3 V_46 )
{
struct V_31 * V_31 = F_21 ( V_27 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
unsigned long V_35 ;
T_1 V_47 , V_48 , V_49 [ V_40 ] ;
char * * V_50 ;
int V_37 , V_51 ;
unsigned int V_5 ;
T_2 V_52 ;
V_50 = F_26 ( V_53 , V_30 , & V_51 ) ;
if ( ! V_50 )
return - V_54 ;
if ( ! V_51 || V_51 > V_40 ) {
V_52 = - V_55 ;
goto V_56;
}
for ( V_37 = 0 ; V_37 < V_51 ; V_37 ++ ) {
V_52 = F_27 ( V_50 [ V_37 ] , 10 , & V_5 ) ;
if ( V_52 )
goto V_56;
V_5 = F_28 ( V_5 , V_44 ) ;
if ( ! V_5 || V_5 > 0x7f ) {
V_52 = - V_55 ;
goto V_56;
}
V_49 [ V_37 ] = V_5 ;
if ( V_37 % 2 == 0 )
V_49 [ V_37 ] |= V_57 ;
}
V_47 = F_29 ( V_51 , 10 ) ;
F_22 ( & V_2 -> V_38 , V_35 ) ;
F_30 ( V_2 ) ;
F_17 ( V_2 , V_51 , V_58 ) ;
F_17 ( V_2 , V_47 , V_59 ) ;
V_48 = F_18 ( V_2 , V_60 ) ;
F_17 ( V_2 , V_48 | V_61 ,
V_60 ) ;
for ( V_37 = 0 ; V_37 < V_51 ; V_37 ++ )
F_17 ( V_2 , V_49 [ V_37 ] , V_62 ) ;
F_17 ( V_2 , V_48 , V_60 ) ;
F_24 ( & V_2 -> V_38 , V_35 ) ;
V_52 = V_46 ;
V_56:
F_31 ( V_50 ) ;
return V_52 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_12 ( V_2 , V_63 ) ;
F_33 ( L_3 , V_10 ) ;
F_33 ( L_4 ,
F_4 ( V_2 , V_17 ) ) ;
F_33 ( L_5 ,
( F_4 ( V_2 , V_24 ) << 8 ) |
F_4 ( V_2 , V_25 ) ) ;
F_33 ( L_6 ,
F_4 ( V_2 , V_64 ) ) ;
F_10 ( V_2 ) ;
F_33 ( L_7 , V_10 ) ;
F_33 ( L_8 , F_16 ( V_2 , V_65 ) ) ;
F_33 ( L_9 , F_16 ( V_2 , V_66 ) ) ;
F_33 ( L_10 , F_16 ( V_2 , V_67 ) ) ;
F_33 ( L_11 , F_16 ( V_2 , V_68 ) ) ;
F_33 ( L_12 , F_16 ( V_2 , V_69 ) ) ;
F_33 ( L_13 , F_16 ( V_2 , V_70 ) ) ;
F_33 ( L_14 , F_16 ( V_2 , V_71 ) ) ;
F_33 ( L_15 , F_16 ( V_2 , V_72 ) ) ;
F_33 ( L_16 , F_16 ( V_2 , V_73 ) ) ;
F_33 ( L_17 , F_16 ( V_2 , V_74 ) ) ;
F_33 ( L_18 , F_16 ( V_2 , V_75 ) ) ;
F_33 ( L_19 , F_16 ( V_2 , V_76 ) ) ;
F_33 ( L_20 , F_16 ( V_2 , V_77 ) ) ;
F_33 ( L_21 , F_16 ( V_2 , V_78 ) ) ;
F_33 ( L_22 , F_16 ( V_2 , V_79 ) ) ;
F_33 ( L_23 , F_16 ( V_2 , V_80 ) ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_37 , V_33 ;
F_8 ( V_2 ) ;
F_12 ( V_2 , V_81 ) ;
F_33 ( L_24 ,
V_10 ) ;
F_33 ( L_25 ,
F_4 ( V_2 , V_17 ) ) ;
F_33 ( L_26 ,
( F_4 ( V_2 , V_24 ) << 8 ) |
F_4 ( V_2 , V_25 ) ) ;
F_33 ( L_27 ,
F_4 ( V_2 , V_64 ) ) ;
F_10 ( V_2 ) ;
F_33 ( L_28 , V_10 ) ;
F_33 ( L_29 ,
F_18 ( V_2 , V_60 ) ) ;
F_33 ( L_30 ,
F_18 ( V_2 , V_82 ) ) ;
F_33 ( L_31 ,
F_18 ( V_2 , V_83 ) ) ;
F_33 ( L_32 ,
F_18 ( V_2 , V_58 ) ) ;
F_33 ( L_33 ,
F_18 ( V_2 , V_59 ) ) ;
F_33 ( L_34 ,
F_18 ( V_2 , V_39 ) ) ;
F_33 ( L_35 ,
F_18 ( V_2 , V_84 ) ) ;
F_33 ( L_36 ,
F_18 ( V_2 , V_85 ) ) ;
F_33 ( L_37 ,
F_18 ( V_2 , V_86 ) ) ;
F_33 ( L_38 ,
F_18 ( V_2 , V_87 ) ) ;
F_33 ( L_39 ,
F_18 ( V_2 , V_88 ) ) ;
F_33 ( L_40 ,
F_18 ( V_2 , V_62 ) ) ;
F_33 ( L_41 ,
F_18 ( V_2 , V_42 ) ) ;
F_33 ( L_42 ,
F_18 ( V_2 , V_41 ) ) ;
F_33 ( L_43 ,
F_18 ( V_2 , V_89 ) ) ;
F_33 ( L_44 ,
F_18 ( V_2 , V_90 ) ) ;
V_33 = F_18 ( V_2 , V_39 ) ;
F_33 ( L_45 , V_10 , V_33 ) ;
F_33 ( L_46 ) ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ )
F_35 ( L_47 ,
F_18 ( V_2 , V_42 ) ) ;
F_35 ( L_2 ) ;
}
static inline const char * F_36 ( struct V_1 * V_2 , int V_91 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < F_37 ( V_92 ) ; V_37 ++ )
if ( ( V_91 & V_93 ) == V_92 [ V_37 ] . V_3 ) {
V_2 -> V_3 = V_92 [ V_37 ] . V_3 ;
return V_92 [ V_37 ] . V_94 ;
}
return NULL ;
}
static int F_38 ( struct V_1 * V_2 )
{
const char * V_95 ;
int V_96 ;
F_8 ( V_2 ) ;
V_2 -> V_97 = F_4 ( V_2 , V_98 ) ;
if ( V_2 -> V_97 == 0xff ) {
F_10 ( V_2 ) ;
V_2 -> V_7 = V_99 ;
V_2 -> V_8 = V_100 ;
F_8 ( V_2 ) ;
V_2 -> V_97 = F_4 ( V_2 , V_98 ) ;
}
V_2 -> V_101 = F_4 ( V_2 , V_102 ) ;
F_10 ( V_2 ) ;
V_96 = V_2 -> V_97 << 8 | V_2 -> V_101 ;
if ( V_96 == V_103 ) {
F_39 ( & V_2 -> V_104 -> V_27 ,
L_48 ) ;
return - V_105 ;
}
V_95 = F_36 ( V_2 , V_96 ) ;
if ( ! V_95 )
F_40 ( & V_2 -> V_104 -> V_27 ,
L_49 ,
V_2 -> V_97 , V_2 -> V_101 ) ;
else
F_41 ( & V_2 -> V_104 -> V_27 ,
L_50 ,
V_95 , V_2 -> V_97 , V_2 -> V_101 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_1 V_5 , V_106 , V_107 , V_108 ;
if ( F_1 ( V_2 ) ) {
V_106 = V_109 ;
V_107 = V_110 ;
V_108 = V_111 | V_112 ;
} else {
V_106 = V_113 ;
V_107 = V_114 ;
V_108 = V_115 | V_116 ;
}
V_5 = F_4 ( V_2 , V_106 ) ;
V_5 &= V_107 ;
V_5 |= V_108 ;
F_2 ( V_2 , V_5 , V_106 ) ;
F_12 ( V_2 , V_63 ) ;
F_19 ( V_2 , & V_2 -> V_20 ) ;
F_2 ( V_2 , V_2 -> V_117 , V_64 ) ;
F_43 ( L_51 ,
V_2 -> V_20 , V_2 -> V_117 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_118 ) ;
F_2 ( V_2 , V_16 , V_17 ) ;
F_6 ( V_2 , V_119 , V_120 ) ;
F_6 ( V_2 , V_121 , V_122 ) ;
F_12 ( V_2 , V_81 ) ;
F_19 ( V_2 , & V_2 -> V_21 ) ;
F_43 ( L_52 ,
V_2 -> V_21 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_1 V_5 = F_16 ( V_2 , V_73 ) ;
F_15 ( V_2 , V_5 | V_123 , V_73 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_5 , V_48 ;
V_48 = F_18 ( V_2 , V_60 ) ;
F_17 ( V_2 , V_48 & ~ V_124 ,
V_60 ) ;
V_5 = F_18 ( V_2 , V_86 ) ;
F_17 ( V_2 , V_5 | V_125 ,
V_86 ) ;
F_17 ( V_2 , V_48 , V_60 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_16 ( V_2 , V_73 ) ;
F_15 ( V_2 , V_5 | V_126 , V_73 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
T_1 V_127 ;
V_127 = V_128 | V_129 | V_130 ;
F_15 ( V_2 , V_127 , V_67 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_131 >> 8 , V_71 ) ;
F_15 ( V_2 , V_131 & 0xff , V_72 ) ;
F_15 ( V_2 , V_132 |
V_133 , V_73 ) ;
F_15 ( V_2 ,
V_134 | V_135 |
V_136 | V_137 ,
V_65 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_15 ( V_2 , 0xff , V_66 ) ;
F_47 ( V_2 ) ;
F_13 ( V_2 , V_63 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_124 |
V_138 | V_139 |
V_140 ,
V_60 ) ;
F_17 ( V_2 , 0xff , V_82 ) ;
F_13 ( V_2 , V_81 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
F_8 ( V_2 ) ;
F_12 ( V_2 , V_118 ) ;
F_6 ( V_2 , V_119 , V_120 ) ;
F_6 ( V_2 , V_121 , V_122 ) ;
F_12 ( V_2 , V_81 ) ;
F_2 ( V_2 , V_16 , V_17 ) ;
F_10 ( V_2 ) ;
F_22 ( & V_2 -> V_38 , V_35 ) ;
F_17 ( V_2 , V_124 | V_141 |
V_138 | V_139 |
V_140 ,
V_60 ) ;
F_17 ( V_2 , 0xff , V_82 ) ;
F_17 ( V_2 , 0 , V_83 ) ;
F_24 ( & V_2 -> V_38 , V_35 ) ;
}
static int F_51 ( struct V_31 * V_27 , T_4 V_142 )
{
struct V_1 * V_2 = V_27 -> V_32 ;
T_5 V_5 ;
if ( V_142 == 0 )
return - V_55 ;
F_15 ( V_2 , 1 , V_69 ) ;
V_5 = 3000000 / ( V_142 ) - 1 ;
F_15 ( V_2 , V_5 & 0xff , V_70 ) ;
F_43 ( L_53 ,
F_16 ( V_2 , V_69 ) , F_16 ( V_2 , V_70 ) ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_27 , unsigned * V_143 , unsigned V_144 )
{
struct V_1 * V_2 = V_27 -> V_32 ;
unsigned long V_35 ;
unsigned int V_37 ;
T_1 V_127 ;
int V_52 ;
F_22 ( & V_2 -> V_145 . V_146 , V_35 ) ;
V_52 = F_23 ( ( unsigned ) ( V_147 / sizeof( unsigned ) ) , V_144 ) ;
V_2 -> V_145 . V_148 = ( V_52 * sizeof( unsigned ) ) ;
memcpy ( V_2 -> V_145 . V_30 , V_143 , V_2 -> V_145 . V_148 ) ;
V_2 -> V_145 . V_149 = 0 ;
V_127 = F_16 ( V_2 , V_67 ) ;
F_15 ( V_2 , V_150 | V_151 , V_67 ) ;
V_2 -> V_145 . V_152 = V_153 ;
F_15 ( V_2 , V_154 |
V_123 , V_73 ) ;
for ( V_37 = 0 ; V_37 < 9 ; V_37 ++ )
F_15 ( V_2 , 0x01 , V_77 ) ;
F_24 ( & V_2 -> V_145 . V_146 , V_35 ) ;
F_53 ( V_2 -> V_145 . V_155 , V_2 -> V_145 . V_152 == V_156 ) ;
F_22 ( & V_2 -> V_145 . V_146 , V_35 ) ;
V_2 -> V_145 . V_152 = V_157 ;
F_24 ( & V_2 -> V_145 . V_146 , V_35 ) ;
F_15 ( V_2 , V_127 , V_67 ) ;
return V_52 ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_37 ;
F_55 ( V_158 L_54 , V_159 , V_2 -> V_160 ) ;
for ( V_37 = 0 ; ( V_37 < V_2 -> V_160 ) && ( V_37 < V_161 ) ; V_37 ++ )
F_55 ( V_162 L_55 , V_2 -> V_30 [ V_37 ] ) ;
F_55 ( V_162 L_2 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( V_163 ) ;
T_1 V_164 ;
int V_37 ;
F_58 ( L_56 , V_159 ) ;
if ( V_165 )
F_54 ( V_2 ) ;
F_58 ( L_57 , V_2 -> V_160 ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_160 ; V_37 ++ ) {
V_164 = V_2 -> V_30 [ V_37 ] ;
V_163 . V_166 = ( ( V_164 & V_57 ) != 0 ) ;
V_163 . V_34 = F_59 ( ( V_164 & V_43 )
* V_44 ) ;
F_43 ( L_58 ,
V_163 . V_166 ? L_59 : L_60 , V_163 . V_34 ) ;
F_60 ( V_2 -> V_167 , & V_163 ) ;
}
V_2 -> V_160 = 0 ;
F_43 ( L_61 ) ;
F_61 ( V_2 -> V_167 ) ;
F_58 ( L_62 , V_159 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_104 -> V_27 , L_63 ) ;
V_2 -> V_160 = 0 ;
F_45 ( V_2 ) ;
F_63 ( V_2 -> V_167 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_1 V_168 ;
int V_37 ;
V_168 = F_16 ( V_2 , V_68 ) ;
F_43 ( L_64 , V_168 ) ;
for ( V_37 = 0 ; V_37 < V_168 ; V_37 ++ )
V_2 -> V_30 [ V_37 ] = F_16 ( V_2 , V_75 ) ;
V_2 -> V_160 = V_168 ;
F_43 ( L_65 , V_159 , V_2 -> V_160 ) ;
F_56 ( V_2 ) ;
}
static void F_65 ( T_1 V_169 , T_1 V_127 )
{
F_43 ( L_66 ,
V_169 , V_127 ,
V_169 & V_170 ? L_67 : L_68 ,
V_169 & V_171 ? L_69 : L_68 ,
V_169 & V_172 ? L_70 : L_68 ,
V_169 & V_173 ? L_71 : L_68 ,
V_169 & V_174 ? L_72 : L_68 ,
V_169 & V_175 ? L_73 : L_68 ,
V_169 & V_176 ? L_74 : L_68 ,
V_169 & V_177 ? L_75 : L_68 ,
V_169 & ~ ( V_170 | V_171 | V_172 |
V_173 | V_174 | V_175 |
V_176 | V_177 ) ? L_76 : L_68 ) ;
}
static bool F_66 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
T_1 V_152 ;
F_22 ( & V_2 -> V_145 . V_146 , V_35 ) ;
V_152 = V_2 -> V_145 . V_152 ;
F_24 ( & V_2 -> V_145 . V_146 , V_35 ) ;
return V_152 == V_157 ;
}
static T_6 F_67 ( int V_178 , void * V_179 )
{
struct V_1 * V_2 = V_179 ;
T_1 V_169 , V_127 ;
unsigned long V_35 ;
F_58 ( L_56 , V_159 ) ;
F_22 ( & V_2 -> V_38 , V_35 ) ;
V_169 = F_16 ( V_2 , V_66 ) ;
V_127 = F_16 ( V_2 , V_67 ) ;
if ( V_169 == 0xff && V_127 == 0xff ) {
F_24 ( & V_2 -> V_38 , V_35 ) ;
F_58 ( L_77 ) ;
return V_180 ;
}
if ( ! ( V_169 & V_127 ) ) {
F_24 ( & V_2 -> V_38 , V_35 ) ;
F_58 ( L_78 , V_159 ) ;
return V_181 ;
}
F_15 ( V_2 , V_169 , V_66 ) ;
F_15 ( V_2 , 0 , V_66 ) ;
F_65 ( V_169 , V_127 ) ;
if ( V_169 & V_173 )
F_62 ( V_2 ) ;
else if ( V_169 & ( V_171 | V_172 ) ) {
if ( F_66 ( V_2 ) )
F_64 ( V_2 ) ;
}
F_24 ( & V_2 -> V_38 , V_35 ) ;
if ( V_169 & V_174 )
F_46 ( V_2 ) ;
if ( V_169 & V_175 ) {
unsigned int V_182 , V_51 ;
T_1 V_9 ;
F_22 ( & V_2 -> V_145 . V_146 , V_35 ) ;
V_182 = V_2 -> V_145 . V_149 ;
V_51 = V_2 -> V_145 . V_148 ;
if ( V_182 < V_51 ) {
F_15 ( V_2 , V_2 -> V_145 . V_30 [ V_182 ] , V_77 ) ;
V_2 -> V_145 . V_149 ++ ;
} else {
V_9 = F_16 ( V_2 , V_67 ) ;
F_15 ( V_2 , V_9 & ~ V_151 , V_67 ) ;
}
F_24 ( & V_2 -> V_145 . V_146 , V_35 ) ;
}
if ( V_169 & V_176 ) {
F_22 ( & V_2 -> V_145 . V_146 , V_35 ) ;
if ( V_2 -> V_145 . V_152 == V_153 ) {
V_2 -> V_145 . V_152 = V_156 ;
F_68 ( & V_2 -> V_145 . V_155 ) ;
}
F_24 ( & V_2 -> V_145 . V_146 , V_35 ) ;
}
F_58 ( L_62 , V_159 ) ;
return V_180 ;
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
F_22 ( & V_2 -> V_38 , V_35 ) ;
F_15 ( V_2 , 0 , V_67 ) ;
F_15 ( V_2 , 0xff , V_66 ) ;
F_15 ( V_2 , 0 , V_65 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_24 ( & V_2 -> V_38 , V_35 ) ;
F_14 ( V_2 , V_63 ) ;
}
static int F_70 ( struct V_31 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_32 ;
unsigned long V_35 ;
F_22 ( & V_2 -> V_38 , V_35 ) ;
F_15 ( V_2 , V_134 | V_135 |
V_136 | V_137 ,
V_65 ) ;
F_15 ( V_2 , 0xff , V_66 ) ;
F_47 ( V_2 ) ;
F_24 ( & V_2 -> V_38 , V_35 ) ;
F_13 ( V_2 , V_63 ) ;
return 0 ;
}
static void F_71 ( struct V_31 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_32 ;
F_69 ( V_2 ) ;
}
static int F_72 ( struct V_183 * V_104 , const struct V_184 * V_185 )
{
struct V_1 * V_2 ;
struct V_31 * V_167 ;
int V_52 = - V_54 ;
V_2 = F_73 ( & V_104 -> V_27 , sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_2 )
return V_52 ;
V_167 = F_74 () ;
if ( ! V_167 )
goto V_186;
V_52 = - V_105 ;
if ( F_75 ( V_104 ) < 0 ) {
F_39 ( & V_104 -> V_27 , L_79 ) ;
goto V_186;
}
if ( ! F_76 ( V_104 , 0 ) ||
F_77 ( V_104 , 0 ) < V_187 ) {
F_39 ( & V_104 -> V_27 , L_80 ) ;
goto V_186;
}
if ( ! F_78 ( V_104 , 0 ) ) {
F_39 ( & V_104 -> V_27 , L_81 ) ;
goto V_186;
}
if ( ! F_76 ( V_104 , 1 ) ||
F_77 ( V_104 , 1 ) < V_187 ) {
F_39 ( & V_104 -> V_27 , L_82 ) ;
goto V_186;
}
V_2 -> V_20 = F_79 ( V_104 , 0 ) ;
V_2 -> V_117 = F_80 ( V_104 , 0 ) ;
V_2 -> V_21 = F_79 ( V_104 , 1 ) ;
V_2 -> V_7 = V_188 ;
V_2 -> V_8 = V_189 ;
F_81 ( & V_2 -> V_38 ) ;
F_81 ( & V_2 -> V_145 . V_146 ) ;
F_82 ( V_104 , V_2 ) ;
V_2 -> V_104 = V_104 ;
F_83 ( & V_2 -> V_145 . V_155 ) ;
V_52 = F_38 ( V_2 ) ;
if ( V_52 )
goto V_186;
F_8 ( V_2 ) ;
F_42 ( V_2 ) ;
F_44 ( V_2 ) ;
F_10 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
V_167 -> V_32 = V_2 ;
V_167 -> V_190 = V_191 ;
V_167 -> V_192 = V_193 ;
V_167 -> V_194 = F_70 ;
V_167 -> V_195 = F_71 ;
V_167 -> V_196 = F_52 ;
V_167 -> V_197 = F_51 ;
V_167 -> V_198 = L_83 ;
V_167 -> V_199 = L_84 ;
V_167 -> V_200 . V_201 = V_202 ;
V_167 -> V_200 . V_203 = V_204 ;
V_167 -> V_200 . V_205 = V_2 -> V_97 ;
V_167 -> V_200 . V_206 = V_2 -> V_101 ;
V_167 -> V_27 . V_207 = & V_104 -> V_27 ;
V_167 -> V_208 = V_10 ;
V_167 -> V_209 = V_210 ;
V_167 -> V_211 = F_84 ( 100 ) ;
V_167 -> V_212 = F_59 ( V_213 ) ;
#if 0
rdev->min_timeout = XYZ;
rdev->max_timeout = XYZ;
rdev->tx_resolution = XYZ;
#endif
V_2 -> V_167 = V_167 ;
V_52 = F_85 ( V_167 ) ;
if ( V_52 )
goto V_186;
V_52 = - V_11 ;
if ( ! F_86 ( & V_104 -> V_27 , V_2 -> V_20 ,
V_187 , V_10 ) )
goto V_214;
if ( F_87 ( & V_104 -> V_27 , V_2 -> V_117 , F_67 ,
V_215 , V_10 , ( void * ) V_2 ) )
goto V_214;
if ( ! F_86 ( & V_104 -> V_27 , V_2 -> V_21 ,
V_187 , V_10 L_85 ) )
goto V_214;
V_52 = F_88 ( & V_167 -> V_27 , & V_216 ) ;
if ( V_52 )
goto V_214;
F_89 ( & V_104 -> V_27 , true ) ;
F_90 ( & V_104 -> V_27 , L_86 ) ;
if ( V_165 ) {
F_32 ( V_2 ) ;
F_34 ( V_2 ) ;
}
return 0 ;
V_214:
F_91 ( V_167 ) ;
V_167 = NULL ;
V_186:
F_92 ( V_167 ) ;
return V_52 ;
}
static void F_93 ( struct V_183 * V_104 )
{
struct V_1 * V_2 = F_94 ( V_104 ) ;
F_95 ( & V_2 -> V_167 -> V_27 , & V_216 ) ;
F_69 ( V_2 ) ;
F_50 ( V_2 ) ;
F_91 ( V_2 -> V_167 ) ;
}
static int F_96 ( struct V_183 * V_104 , T_7 V_217 )
{
struct V_1 * V_2 = F_94 ( V_104 ) ;
unsigned long V_35 ;
F_43 ( L_87 , V_159 ) ;
F_22 ( & V_2 -> V_145 . V_146 , V_35 ) ;
V_2 -> V_145 . V_152 = V_157 ;
F_24 ( & V_2 -> V_145 . V_146 , V_35 ) ;
F_22 ( & V_2 -> V_38 , V_35 ) ;
F_15 ( V_2 , 0 , V_67 ) ;
F_24 ( & V_2 -> V_38 , V_35 ) ;
F_14 ( V_2 , V_63 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_183 * V_104 )
{
struct V_1 * V_2 = F_94 ( V_104 ) ;
F_43 ( L_87 , V_159 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static void F_98 ( struct V_183 * V_104 )
{
struct V_1 * V_2 = F_94 ( V_104 ) ;
F_50 ( V_2 ) ;
}
