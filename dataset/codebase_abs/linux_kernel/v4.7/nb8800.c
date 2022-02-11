static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_6 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_3 , T_3 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , int V_3 , T_2 V_5 )
{
F_10 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , int V_3 ,
T_2 V_6 , T_2 V_5 )
{
T_2 V_7 = F_1 ( V_2 , V_3 ) ;
T_2 V_8 = ( V_7 & ~ V_6 ) | ( V_5 & V_6 ) ;
if ( V_8 != V_7 )
F_5 ( V_2 , V_3 , V_8 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , int V_3 ,
T_2 V_6 , T_2 V_5 )
{
T_2 V_7 = F_3 ( V_2 , V_3 ) ;
T_2 V_8 = ( V_7 & ~ V_6 ) | ( V_5 & V_6 ) ;
if ( V_8 != V_7 )
F_9 ( V_2 , V_3 , V_8 ) ;
}
static inline void F_13 ( struct V_1 * V_2 , int V_3 , T_1 V_9 ,
bool V_10 )
{
F_11 ( V_2 , V_3 , V_9 , V_10 ? V_9 : 0 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , int V_3 , T_1 V_9 )
{
F_11 ( V_2 , V_3 , V_9 , V_9 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , int V_3 , T_1 V_9 )
{
F_11 ( V_2 , V_3 , V_9 , 0 ) ;
}
static inline void F_16 ( struct V_1 * V_2 , int V_3 , T_2 V_9 ,
bool V_10 )
{
F_12 ( V_2 , V_3 , V_9 , V_10 ? V_9 : 0 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , int V_3 , T_2 V_9 )
{
F_12 ( V_2 , V_3 , V_9 , V_9 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , int V_3 , T_2 V_9 )
{
F_12 ( V_2 , V_3 , V_9 , 0 ) ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_2 V_5 ;
return F_20 ( V_2 -> V_4 + V_13 ,
V_5 , ! ( V_5 & V_14 ) , 1 , 1000 ) ;
}
static int F_21 ( struct V_11 * V_12 , T_2 V_15 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
int V_16 ;
V_16 = F_19 ( V_12 ) ;
if ( V_16 )
return V_16 ;
F_9 ( V_2 , V_13 , V_15 ) ;
F_22 ( 10 ) ;
F_9 ( V_2 , V_13 , V_15 | V_14 ) ;
return F_19 ( V_12 ) ;
}
static int F_23 ( struct V_11 * V_12 , int V_17 , int V_3 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_2 V_5 ;
int V_16 ;
V_16 = F_21 ( V_12 , F_24 ( V_17 ) | F_25 ( V_3 ) ) ;
if ( V_16 )
return V_16 ;
V_5 = F_3 ( V_2 , V_18 ) ;
if ( V_5 & V_19 )
return 0xffff ;
return V_5 & 0xffff ;
}
static int F_26 ( struct V_11 * V_12 , int V_17 , int V_3 , T_3 V_5 )
{
T_2 V_15 = F_24 ( V_17 ) | F_25 ( V_3 ) |
F_27 ( V_5 ) | V_20 ;
return F_21 ( V_12 , V_15 ) ;
}
static void F_28 ( struct V_21 * V_22 , bool V_23 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
while ( F_3 ( V_2 , V_24 ) & V_25 )
F_30 () ;
F_13 ( V_2 , V_26 , V_27 , V_23 ) ;
}
static void F_31 ( struct V_21 * V_22 , bool V_23 )
{
F_13 ( F_29 ( V_22 ) , V_28 , V_29 , V_23 ) ;
}
static void F_32 ( struct V_21 * V_22 , bool V_23 )
{
F_13 ( F_29 ( V_22 ) , V_28 , V_30 , V_23 ) ;
}
static void F_33 ( struct V_21 * V_22 )
{
F_17 ( F_29 ( V_22 ) , V_31 , V_32 ) ;
}
static int F_34 ( struct V_21 * V_22 , unsigned int V_33 , bool V_34 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_35 * V_36 = & V_2 -> V_37 [ V_33 ] ;
struct V_38 * V_39 = & V_2 -> V_40 [ V_33 ] ;
int V_41 = F_35 ( V_42 ) ;
T_4 V_43 ;
struct V_44 * V_44 ;
unsigned long V_45 ;
void * V_46 ;
V_46 = V_34 ? F_36 ( V_41 ) : F_37 ( V_41 ) ;
if ( ! V_46 )
return - V_47 ;
V_44 = F_38 ( V_46 ) ;
V_45 = V_46 - F_39 ( V_44 ) ;
V_43 = F_40 ( & V_22 -> V_22 , V_44 , V_45 , V_42 ,
V_48 ) ;
if ( F_41 ( & V_22 -> V_22 , V_43 ) ) {
F_42 ( V_46 ) ;
return - V_47 ;
}
V_39 -> V_44 = V_44 ;
V_39 -> V_45 = V_45 ;
V_36 -> V_49 . V_50 = V_43 ;
return 0 ;
}
static void F_43 ( struct V_21 * V_22 , unsigned int V_33 ,
unsigned int V_51 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_35 * V_36 = & V_2 -> V_37 [ V_33 ] ;
struct V_44 * V_44 = V_2 -> V_40 [ V_33 ] . V_44 ;
int V_45 = V_2 -> V_40 [ V_33 ] . V_45 ;
void * V_46 = F_39 ( V_44 ) + V_45 ;
T_4 V_52 = V_36 -> V_49 . V_50 ;
struct V_53 * V_54 ;
unsigned int V_41 ;
int V_16 ;
V_41 = V_51 <= V_55 ? V_51 : V_56 ;
V_54 = F_44 ( & V_2 -> V_34 , V_41 ) ;
if ( ! V_54 ) {
F_45 ( V_22 , L_1 ) ;
V_22 -> V_57 . V_58 ++ ;
return;
}
if ( V_51 <= V_55 ) {
F_46 ( & V_22 -> V_22 , V_52 , V_51 , V_48 ) ;
memcpy ( F_47 ( V_54 , V_51 ) , V_46 , V_51 ) ;
F_48 ( & V_22 -> V_22 , V_52 , V_51 ,
V_48 ) ;
} else {
V_16 = F_34 ( V_22 , V_33 , true ) ;
if ( V_16 ) {
F_45 ( V_22 , L_2 ) ;
V_22 -> V_57 . V_58 ++ ;
F_49 ( V_54 ) ;
return;
}
F_50 ( & V_22 -> V_22 , V_52 , V_42 , V_48 ) ;
memcpy ( F_47 ( V_54 , V_56 ) , V_46 , V_56 ) ;
F_51 ( V_54 , F_52 ( V_54 ) -> V_59 , V_44 ,
V_45 + V_56 , V_51 - V_56 ,
V_42 ) ;
}
V_54 -> V_60 = F_53 ( V_54 , V_22 ) ;
F_54 ( & V_2 -> V_34 , V_54 ) ;
}
static void F_55 ( struct V_21 * V_22 , T_2 V_61 )
{
if ( V_61 & V_62 )
V_22 -> V_57 . V_63 ++ ;
if ( V_61 & V_64 )
V_22 -> V_57 . V_65 ++ ;
if ( V_61 & V_66 )
V_22 -> V_57 . V_67 ++ ;
if ( V_61 & V_68 )
V_22 -> V_57 . V_69 ++ ;
V_22 -> V_57 . V_70 ++ ;
}
static int F_56 ( struct V_71 * V_34 , int V_72 )
{
struct V_21 * V_22 = V_34 -> V_22 ;
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_35 * V_36 ;
unsigned int V_73 = V_2 -> V_74 ;
unsigned int V_75 ;
int V_76 = 0 ;
F_57 ( V_22 ) ;
V_77:
do {
struct V_38 * V_39 ;
unsigned int V_51 ;
V_75 = ( V_73 + 1 ) % V_78 ;
V_39 = & V_2 -> V_40 [ V_75 ] ;
V_36 = & V_2 -> V_37 [ V_75 ] ;
if ( ! V_36 -> V_61 )
break;
V_51 = F_58 ( V_36 -> V_61 ) ;
if ( F_59 ( V_36 -> V_61 ) )
F_55 ( V_22 , V_36 -> V_61 ) ;
else
F_43 ( V_22 , V_75 , V_51 ) ;
V_22 -> V_57 . V_79 ++ ;
V_22 -> V_57 . V_80 += V_51 ;
if ( V_36 -> V_61 & V_81 )
V_22 -> V_57 . V_82 ++ ;
V_36 -> V_61 = 0 ;
V_73 = V_75 ;
V_76 ++ ;
} while ( V_76 < V_72 );
if ( V_76 ) {
V_2 -> V_37 [ V_73 ] . V_49 . V_83 |= V_84 ;
F_60 () ;
V_2 -> V_37 [ V_2 -> V_74 ] . V_49 . V_83 &= ~ V_84 ;
V_2 -> V_74 = V_73 ;
F_33 ( V_22 ) ;
}
if ( V_76 < V_72 ) {
F_9 ( V_2 , V_85 , V_2 -> V_86 ) ;
if ( V_2 -> V_37 [ V_75 ] . V_61 )
goto V_77;
F_61 ( V_34 , V_76 ) ;
}
return V_76 ;
}
static void F_62 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_87 * V_88 ;
T_2 V_89 ;
V_88 = & V_2 -> V_90 [ V_2 -> V_91 ] ;
if ( ! V_88 -> V_92 )
return;
V_89 = F_3 ( V_2 , V_24 ) ;
if ( V_89 & V_25 )
return;
F_9 ( V_2 , V_93 , V_88 -> V_94 ) ;
F_60 () ;
F_9 ( V_2 , V_24 , V_89 | V_25 ) ;
V_2 -> V_91 = ( V_2 -> V_91 + V_88 -> V_95 ) % V_96 ;
}
static void F_63 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
F_64 ( & V_2 -> V_97 ) ;
F_62 ( V_22 ) ;
F_65 ( & V_2 -> V_97 ) ;
}
static void F_66 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
F_67 ( & V_2 -> V_97 ) ;
F_62 ( V_22 ) ;
F_68 ( & V_2 -> V_97 ) ;
}
static int F_69 ( struct V_53 * V_54 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_98 * V_99 ;
struct V_87 * V_88 ;
struct V_100 * V_49 ;
T_4 V_43 ;
unsigned int V_101 ;
unsigned int V_102 ;
unsigned int V_75 ;
if ( F_70 ( & V_2 -> V_103 ) <= V_104 ) {
F_71 ( V_22 ) ;
return V_105 ;
}
V_102 = ( 8 - ( V_106 ) V_54 -> V_46 ) & 7 ;
V_101 = V_54 -> V_51 - V_102 ;
V_43 = F_72 ( & V_22 -> V_22 , V_54 -> V_46 + V_102 ,
V_101 , V_107 ) ;
if ( F_41 ( & V_22 -> V_22 , V_43 ) ) {
F_45 ( V_22 , L_3 ) ;
F_73 ( V_54 ) ;
V_22 -> V_57 . V_108 ++ ;
return V_109 ;
}
if ( F_74 ( & V_2 -> V_103 ) <= V_104 ) {
F_71 ( V_22 ) ;
V_54 -> V_110 = 0 ;
}
V_75 = V_2 -> V_111 ;
V_88 = & V_2 -> V_90 [ V_75 ] ;
V_99 = & V_2 -> V_112 [ V_75 ] ;
V_49 = & V_99 -> V_49 [ 0 ] ;
V_75 = ( V_75 + 1 ) % V_96 ;
if ( V_102 ) {
memcpy ( V_99 -> V_113 , V_54 -> V_46 , V_102 ) ;
V_49 -> V_50 =
V_88 -> V_94 + F_75 ( struct V_98 , V_113 ) ;
V_49 -> V_114 = V_88 -> V_94 + sizeof( V_99 -> V_49 [ 0 ] ) ;
V_49 -> V_83 = F_76 ( 2 ) | V_115 | V_102 ;
V_49 ++ ;
}
V_49 -> V_50 = V_43 ;
V_49 -> V_114 = V_2 -> V_90 [ V_75 ] . V_94 ;
V_49 -> V_83 = F_76 ( 2 ) | V_115 | V_116 | V_101 ;
if ( ! V_54 -> V_110 )
V_49 -> V_83 |= V_84 ;
V_88 -> V_54 = V_54 ;
V_88 -> V_43 = V_43 ;
V_88 -> V_101 = V_101 ;
if ( ! V_2 -> V_117 ) {
V_88 -> V_95 = 1 ;
V_2 -> V_117 = V_88 ;
} else {
V_2 -> V_117 -> V_95 ++ ;
}
F_77 ( V_22 , V_54 -> V_51 ) ;
V_2 -> V_111 = V_75 ;
if ( ! V_54 -> V_110 ) {
F_78 () ;
V_2 -> V_117 -> V_92 = true ;
V_2 -> V_117 = NULL ;
F_63 ( V_22 ) ;
}
return V_109 ;
}
static void F_79 ( struct V_21 * V_22 , T_2 V_61 )
{
if ( V_61 & V_118 )
V_22 -> V_57 . V_119 ++ ;
if ( V_61 & V_120 )
V_22 -> V_57 . V_108 ++ ;
if ( V_61 & V_121 )
V_22 -> V_57 . V_122 ++ ;
V_22 -> V_57 . V_123 ++ ;
}
static void F_57 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
unsigned int V_124 = V_2 -> V_111 ;
unsigned int V_125 = V_2 -> V_126 ;
unsigned int V_127 = 0 ;
unsigned int V_51 = 0 ;
while ( V_125 != V_124 ) {
struct V_98 * V_99 = & V_2 -> V_112 [ V_125 ] ;
struct V_87 * V_88 = & V_2 -> V_90 [ V_125 ] ;
struct V_53 * V_54 ;
if ( ! V_99 -> V_61 )
break;
V_54 = V_88 -> V_54 ;
V_51 += V_54 -> V_51 ;
F_80 ( & V_22 -> V_22 , V_88 -> V_43 , V_88 -> V_101 ,
V_107 ) ;
if ( F_81 ( V_99 -> V_61 ) ) {
F_79 ( V_22 , V_99 -> V_61 ) ;
F_73 ( V_54 ) ;
} else {
F_82 ( V_54 ) ;
}
V_22 -> V_57 . V_128 ++ ;
V_22 -> V_57 . V_129 += F_83 ( V_99 -> V_61 ) ;
V_22 -> V_57 . V_119 += F_84 ( V_99 -> V_61 ) ;
V_88 -> V_54 = NULL ;
V_88 -> V_92 = false ;
V_99 -> V_61 = 0 ;
V_125 = ( V_125 + 1 ) % V_96 ;
V_127 ++ ;
}
if ( V_127 ) {
F_85 () ;
F_86 ( V_127 , & V_2 -> V_103 ) ;
F_87 ( V_22 , V_127 , V_51 ) ;
F_88 ( V_22 ) ;
V_2 -> V_126 = V_125 ;
}
}
static T_5 F_89 ( int V_130 , void * V_131 )
{
struct V_21 * V_22 = V_131 ;
struct V_1 * V_2 = F_29 ( V_22 ) ;
T_5 V_132 = V_133 ;
T_2 V_5 ;
V_5 = F_3 ( V_2 , V_134 ) ;
if ( V_5 ) {
F_9 ( V_2 , V_134 , V_5 ) ;
if ( V_5 & V_135 )
F_66 ( V_22 ) ;
if ( V_5 & V_136 )
F_90 ( & V_2 -> V_34 ) ;
if ( F_91 ( V_5 & V_137 ) )
F_45 ( V_22 , L_4 ) ;
if ( F_91 ( V_5 & V_138 ) )
F_45 ( V_22 , L_5 ) ;
V_132 = V_139 ;
}
V_5 = F_3 ( V_2 , V_140 ) ;
if ( V_5 ) {
F_9 ( V_2 , V_140 , V_5 ) ;
if ( F_92 ( V_5 & ( V_141 | V_142 ) ) ) {
F_9 ( V_2 , V_85 , V_2 -> V_143 ) ;
F_90 ( & V_2 -> V_34 ) ;
}
if ( F_91 ( V_5 & V_144 ) )
F_45 ( V_22 , L_6 ) ;
if ( F_91 ( V_5 & V_145 ) )
F_45 ( V_22 , L_7 ) ;
V_132 = V_139 ;
}
return V_132 ;
}
static void F_93 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
bool V_146 = V_2 -> V_147 == V_148 ;
T_2 V_149 = V_150 | V_151 | V_152 ;
T_2 V_153 = 0 ;
T_2 V_154 ;
T_2 V_155 ;
T_2 V_156 ;
if ( ! V_2 -> V_157 )
V_153 |= V_151 ;
if ( V_146 ) {
if ( V_2 -> V_158 == V_159 )
V_153 |= V_150 ;
V_153 |= V_152 ;
V_155 = 125000000 ;
V_154 = 255 ;
} else {
V_155 = 25000000 ;
V_154 = 128 ;
}
V_156 = F_94 ( V_155 , F_95 ( V_2 -> V_160 ) ) ;
F_5 ( V_2 , V_161 , V_156 ) ;
F_5 ( V_2 , V_162 , V_154 ) ;
F_11 ( V_2 , V_163 , V_149 , V_153 ) ;
}
static void F_96 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_164 * V_165 = V_2 -> V_165 ;
T_2 V_166 ;
if ( V_2 -> V_167 ) {
if ( ! V_165 || ! V_165 -> V_168 )
return;
V_2 -> V_169 = V_165 -> V_170 ;
V_2 -> V_171 = V_165 -> V_170 ^ V_165 -> V_172 ;
}
F_13 ( V_2 , V_28 , V_173 , V_2 -> V_169 ) ;
V_166 = F_3 ( V_2 , V_31 ) ;
if ( ! ! ( V_166 & V_174 ) == V_2 -> V_171 )
return;
if ( F_97 ( V_22 ) ) {
F_98 ( & V_2 -> V_34 ) ;
F_99 ( V_22 ) ;
F_100 ( V_22 ) ;
F_16 ( V_2 , V_31 , V_174 , V_2 -> V_171 ) ;
F_33 ( V_22 ) ;
F_101 ( V_22 ) ;
F_102 ( & V_2 -> V_34 ) ;
} else {
F_16 ( V_2 , V_31 , V_174 , V_2 -> V_171 ) ;
}
}
static void F_103 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_164 * V_165 = V_2 -> V_165 ;
int V_175 = 0 ;
if ( V_165 -> V_168 ) {
if ( V_165 -> V_147 != V_2 -> V_147 ) {
V_2 -> V_147 = V_165 -> V_147 ;
V_175 = 1 ;
}
if ( V_165 -> V_157 != V_2 -> V_157 ) {
V_2 -> V_157 = V_165 -> V_157 ;
V_175 = 1 ;
}
if ( V_175 )
F_93 ( V_22 ) ;
F_96 ( V_22 ) ;
}
if ( V_165 -> V_168 != V_2 -> V_168 ) {
V_2 -> V_168 = V_165 -> V_168 ;
V_175 = 1 ;
}
if ( V_175 )
F_104 ( V_2 -> V_165 ) ;
}
static void F_105 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_176 ; V_33 ++ )
F_5 ( V_2 , F_106 ( V_33 ) , V_22 -> V_177 [ V_33 ] ) ;
for ( V_33 = 0 ; V_33 < V_176 ; V_33 ++ )
F_5 ( V_2 , F_107 ( V_33 ) , V_22 -> V_177 [ V_33 ] ) ;
}
static int F_108 ( struct V_21 * V_22 , void * V_178 )
{
struct V_179 * V_180 = V_178 ;
if ( F_97 ( V_22 ) )
return - V_181 ;
F_109 ( V_22 -> V_177 , V_180 -> V_182 ) ;
F_105 ( V_22 ) ;
return 0 ;
}
static void F_110 ( struct V_21 * V_22 , int V_5 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
F_5 ( V_2 , V_183 , V_5 ) ;
F_111 ( V_2 -> V_4 + V_183 , V_5 , ! V_5 ,
1 , 1000 ) ;
}
static void F_112 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_184 * V_185 ;
int V_33 ;
if ( V_22 -> V_186 & ( V_187 | V_188 ) ) {
F_32 ( V_22 , false ) ;
return;
}
F_32 ( V_22 , true ) ;
F_110 ( V_22 , 0 ) ;
F_113 (ha, dev) {
for ( V_33 = 0 ; V_33 < V_176 ; V_33 ++ )
F_5 ( V_2 , F_114 ( V_33 ) , V_185 -> V_178 [ V_33 ] ) ;
F_110 ( V_22 , 0xff ) ;
}
}
static void F_115 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
unsigned int V_33 ;
if ( V_2 -> V_40 ) {
for ( V_33 = 0 ; V_33 < V_78 ; V_33 ++ )
if ( V_2 -> V_40 [ V_33 ] . V_44 )
F_116 ( V_2 -> V_40 [ V_33 ] . V_44 ) ;
F_117 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
}
if ( V_2 -> V_90 ) {
for ( V_33 = 0 ; V_33 < V_96 ; V_33 ++ )
F_73 ( V_2 -> V_90 [ V_33 ] . V_54 ) ;
F_117 ( V_2 -> V_90 ) ;
V_2 -> V_90 = NULL ;
}
if ( V_2 -> V_37 ) {
F_118 ( V_22 -> V_22 . V_189 , V_190 , V_2 -> V_37 ,
V_2 -> V_191 ) ;
V_2 -> V_37 = NULL ;
}
if ( V_2 -> V_112 ) {
F_118 ( V_22 -> V_22 . V_189 , V_192 , V_2 -> V_112 ,
V_2 -> V_193 ) ;
V_2 -> V_112 = NULL ;
}
}
static void F_119 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_35 * V_36 ;
struct V_98 * V_99 ;
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < V_78 ; V_33 ++ ) {
T_4 V_194 = V_2 -> V_191 + V_33 * sizeof( * V_36 ) ;
V_36 = & V_2 -> V_37 [ V_33 ] ;
V_36 -> V_49 . V_114 = V_194 + sizeof( * V_36 ) ;
V_36 -> V_49 . V_195 =
V_194 + F_75 ( struct V_35 , V_61 ) ;
V_36 -> V_49 . V_83 = V_2 -> V_196 ;
V_36 -> V_61 = 0 ;
}
V_36 -> V_49 . V_114 = V_2 -> V_191 ;
V_36 -> V_49 . V_83 |= V_84 ;
V_2 -> V_74 = V_78 - 1 ;
for ( V_33 = 0 ; V_33 < V_96 ; V_33 ++ ) {
struct V_87 * V_88 = & V_2 -> V_90 [ V_33 ] ;
T_4 V_197 = V_88 -> V_94 +
F_75 ( struct V_98 , V_61 ) ;
V_99 = & V_2 -> V_112 [ V_33 ] ;
V_99 -> V_49 [ 0 ] . V_195 = V_197 ;
V_99 -> V_49 [ 1 ] . V_195 = V_197 ;
V_99 -> V_61 = 0 ;
}
V_2 -> V_111 = 0 ;
V_2 -> V_91 = 0 ;
V_2 -> V_126 = 0 ;
F_120 ( & V_2 -> V_103 , V_96 ) ;
F_9 ( V_2 , V_198 , V_2 -> V_191 ) ;
F_60 () ;
}
static int F_121 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
unsigned int V_199 = V_78 ;
unsigned int V_200 = V_96 ;
unsigned int V_33 ;
int V_16 ;
V_2 -> V_37 = F_122 ( V_22 -> V_22 . V_189 , V_190 ,
& V_2 -> V_191 , V_201 ) ;
if ( ! V_2 -> V_37 )
goto V_202;
V_2 -> V_40 = F_123 ( V_199 , sizeof( * V_2 -> V_40 ) , V_201 ) ;
if ( ! V_2 -> V_40 )
goto V_202;
for ( V_33 = 0 ; V_33 < V_199 ; V_33 ++ ) {
V_16 = F_34 ( V_22 , V_33 , false ) ;
if ( V_16 )
goto V_202;
}
V_2 -> V_112 = F_122 ( V_22 -> V_22 . V_189 , V_192 ,
& V_2 -> V_193 , V_201 ) ;
if ( ! V_2 -> V_112 )
goto V_202;
V_2 -> V_90 = F_123 ( V_200 , sizeof( * V_2 -> V_90 ) , V_201 ) ;
if ( ! V_2 -> V_90 )
goto V_202;
for ( V_33 = 0 ; V_33 < V_200 ; V_33 ++ )
V_2 -> V_90 [ V_33 ] . V_94 =
V_2 -> V_193 + V_33 * sizeof( struct V_98 ) ;
F_119 ( V_22 ) ;
return 0 ;
V_202:
F_115 ( V_22 ) ;
return - V_47 ;
}
static int F_100 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_87 * V_88 = & V_2 -> V_90 [ 0 ] ;
struct V_98 * V_99 = & V_2 -> V_112 [ 0 ] ;
int V_203 = 5 ;
T_2 V_204 ;
T_2 V_166 ;
int V_16 ;
unsigned int V_33 ;
V_16 = F_20 ( V_2 -> V_4 + V_24 , V_204 ,
! ( V_204 & V_25 ) &&
V_2 -> V_126 == V_2 -> V_111 ,
1000 , 1000000 ) ;
if ( V_16 )
return V_16 ;
for ( V_33 = 0 ; V_33 < V_78 ; V_33 ++ )
V_2 -> V_37 [ V_33 ] . V_49 . V_83 |= V_84 ;
V_99 -> V_49 [ 0 ] . V_50 =
V_88 -> V_94 + F_75 ( struct V_98 , V_113 ) ;
V_99 -> V_49 [ 0 ] . V_83 = F_76 ( 2 ) | V_115 | V_116 | V_84 | 8 ;
memset ( V_99 -> V_113 , 0 , sizeof( V_99 -> V_113 ) ) ;
F_32 ( V_22 , false ) ;
F_14 ( V_2 , V_163 , V_205 ) ;
do {
F_9 ( V_2 , V_93 , V_88 -> V_94 ) ;
F_60 () ;
F_9 ( V_2 , V_24 , V_204 | V_25 ) ;
V_16 = F_20 ( V_2 -> V_4 + V_31 ,
V_166 , ! ( V_166 & V_32 ) ,
1000 , 100000 ) ;
} while ( V_16 && -- V_203 );
F_32 ( V_22 , true ) ;
F_15 ( V_2 , V_163 , V_205 ) ;
F_119 ( V_22 ) ;
return V_203 ? 0 : - V_206 ;
}
static void F_124 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
T_2 V_207 = 0 ;
if ( ! V_2 -> V_165 )
return;
if ( V_2 -> V_169 )
V_207 |= V_208 | V_209 ;
if ( V_2 -> V_171 )
V_207 ^= V_209 ;
V_2 -> V_165 -> V_210 |= V_207 ;
V_2 -> V_165 -> V_211 |= V_207 ;
}
static int F_125 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
int V_16 ;
F_9 ( V_2 , V_140 , 0xf ) ;
F_9 ( V_2 , V_134 , 0xf ) ;
V_16 = F_121 ( V_22 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_126 ( V_22 -> V_130 , F_89 , 0 , F_127 ( & V_22 -> V_22 ) , V_22 ) ;
if ( V_16 )
goto V_212;
F_31 ( V_22 , true ) ;
F_28 ( V_22 , true ) ;
V_2 -> V_165 = F_128 ( V_22 , V_2 -> V_213 ,
F_103 , 0 ,
V_2 -> V_158 ) ;
if ( ! V_2 -> V_165 )
goto V_214;
F_124 ( V_22 ) ;
F_129 ( V_22 ) ;
F_102 ( & V_2 -> V_34 ) ;
F_130 ( V_22 ) ;
F_33 ( V_22 ) ;
F_131 ( V_2 -> V_165 ) ;
return 0 ;
V_214:
F_132 ( V_22 -> V_130 , V_22 ) ;
V_212:
F_115 ( V_22 ) ;
return V_16 ;
}
static int F_133 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
F_134 ( V_2 -> V_165 ) ;
F_71 ( V_22 ) ;
F_98 ( & V_2 -> V_34 ) ;
F_100 ( V_22 ) ;
F_31 ( V_22 , false ) ;
F_28 ( V_22 , false ) ;
F_135 ( V_2 -> V_165 ) ;
V_2 -> V_165 = NULL ;
F_132 ( V_22 -> V_130 , V_22 ) ;
F_115 ( V_22 ) ;
return 0 ;
}
static int F_136 ( struct V_21 * V_22 , struct V_215 * V_216 , int V_15 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
return F_137 ( V_2 -> V_165 , V_216 , V_15 ) ;
}
static int F_138 ( struct V_21 * V_22 , struct V_217 * V_15 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
if ( ! V_2 -> V_165 )
return - V_218 ;
return F_139 ( V_2 -> V_165 , V_15 ) ;
}
static int F_140 ( struct V_21 * V_22 , struct V_217 * V_15 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
if ( ! V_2 -> V_165 )
return - V_218 ;
return F_141 ( V_2 -> V_165 , V_15 ) ;
}
static int F_142 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
if ( ! V_2 -> V_165 )
return - V_218 ;
return F_143 ( V_2 -> V_165 ) ;
}
static void F_144 ( struct V_21 * V_22 ,
struct V_219 * V_220 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
V_220 -> V_221 = V_2 -> V_167 ;
V_220 -> V_222 = V_2 -> V_169 ;
V_220 -> V_223 = V_2 -> V_171 ;
}
static int F_145 ( struct V_21 * V_22 ,
struct V_219 * V_220 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
V_2 -> V_167 = V_220 -> V_221 ;
V_2 -> V_169 = V_220 -> V_222 ;
V_2 -> V_171 = V_220 -> V_223 ;
F_124 ( V_22 ) ;
if ( ! V_2 -> V_167 )
F_96 ( V_22 ) ;
else if ( V_2 -> V_165 )
F_146 ( V_2 -> V_165 ) ;
return 0 ;
}
static int F_147 ( struct V_21 * V_22 , int V_224 )
{
if ( V_224 == V_225 )
return V_226 ;
return - V_227 ;
}
static void F_148 ( struct V_21 * V_22 , T_2 V_224 , T_1 * V_113 )
{
if ( V_224 == V_225 )
memcpy ( V_113 , & V_228 , sizeof( V_228 ) ) ;
}
static T_2 F_149 ( struct V_21 * V_22 , int V_229 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
F_5 ( V_2 , V_230 , V_229 ) ;
return F_3 ( V_2 , V_231 ) ;
}
static void F_150 ( struct V_21 * V_22 ,
struct V_232 * V_233 , T_6 * V_234 )
{
unsigned int V_33 ;
T_2 V_235 , V_236 ;
for ( V_33 = 0 ; V_33 < V_226 / 2 ; V_33 ++ ) {
V_235 = F_149 ( V_22 , V_33 ) ;
V_236 = F_149 ( V_22 , V_33 | 0x80 ) ;
V_234 [ V_33 ] = V_235 ;
V_234 [ V_33 + V_226 / 2 ] = V_236 ;
}
}
static int F_151 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
T_2 V_5 ;
V_5 = V_237 | V_238 | V_239 ;
F_5 ( V_2 , V_26 , V_5 ) ;
F_5 ( V_2 , V_240 , 5 ) ;
V_5 = V_241 | V_30 ;
F_5 ( V_2 , V_28 , V_5 ) ;
F_5 ( V_2 , V_242 , 4 ) ;
F_5 ( V_2 , V_243 , 12 ) ;
F_5 ( V_2 , V_244 , 0 ) ;
F_5 ( V_2 , V_245 , 255 ) ;
F_5 ( V_2 , V_246 , 64 ) ;
V_5 = F_3 ( V_2 , V_24 ) ;
V_5 &= V_247 ;
V_5 |= V_248 ;
V_5 |= V_249 ;
V_5 |= V_250 ;
V_5 |= F_152 ( 7 ) ;
V_5 |= F_153 ( 2 ) ;
F_9 ( V_2 , V_24 , V_5 ) ;
V_5 = F_95 ( V_2 -> V_160 ) / 100 ;
F_9 ( V_2 , V_251 , V_5 ) ;
V_5 = F_3 ( V_2 , V_31 ) ;
V_5 &= V_252 ;
V_5 |= V_253 ;
V_5 |= V_254 ;
V_5 |= V_255 ;
V_5 |= F_154 ( 7 ) ;
V_5 |= F_155 ( 2 ) ;
F_9 ( V_2 , V_31 , V_5 ) ;
V_2 -> V_86 = F_95 ( V_2 -> V_160 ) / 20000 ;
V_2 -> V_143 = F_95 ( V_2 -> V_160 ) / 100 ;
F_9 ( V_2 , V_85 , V_2 -> V_86 ) ;
V_2 -> V_196 = V_42 | F_76 ( 2 ) | V_115 | V_116 ;
V_5 = 100000 / 512 ;
F_5 ( V_2 , V_256 , V_5 >> 8 ) ;
F_5 ( V_2 , V_257 , V_5 & 0xff ) ;
V_2 -> V_167 = true ;
V_2 -> V_169 = true ;
V_2 -> V_171 = true ;
F_110 ( V_22 , 0 ) ;
return 0 ;
}
static int F_156 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
T_2 V_258 = V_259 ;
switch ( V_2 -> V_158 ) {
case V_260 :
case V_261 :
V_258 = V_259 ;
break;
case V_159 :
V_258 = V_262 ;
break;
case V_263 :
V_258 = V_262 | V_264 ;
break;
default:
F_157 ( V_22 -> V_22 . V_189 , L_8 ,
F_158 ( V_2 -> V_158 ) ) ;
return - V_265 ;
}
F_5 ( V_2 , V_266 , V_258 ) ;
return 0 ;
}
static int F_159 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
int V_267 ;
F_5 ( V_2 , V_268 , 0 ) ;
F_160 ( 1000 , 10000 ) ;
F_5 ( V_2 , V_268 , 1 ) ;
F_60 () ;
V_267 = F_94 ( F_95 ( V_2 -> V_160 ) , 2 * V_269 ) ;
F_7 ( V_2 , V_270 , V_267 ) ;
return 0 ;
}
static int F_161 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
int V_16 ;
V_16 = F_156 ( V_22 ) ;
if ( V_16 )
return V_16 ;
F_18 ( V_2 , V_31 , F_154 ( 7 ) ) ;
V_2 -> V_196 |= V_271 ;
return 0 ;
}
static int F_162 ( struct V_272 * V_273 )
{
const struct V_274 * V_275 ;
const struct V_276 * V_277 = NULL ;
struct V_1 * V_2 ;
struct V_278 * V_279 ;
struct V_21 * V_22 ;
struct V_11 * V_12 ;
const unsigned char * V_280 ;
void T_7 * V_4 ;
int V_130 ;
int V_132 ;
V_275 = F_163 ( V_281 , & V_273 -> V_22 ) ;
if ( V_275 )
V_277 = V_275 -> V_46 ;
V_130 = F_164 ( V_273 , 0 ) ;
if ( V_130 <= 0 ) {
F_157 ( & V_273 -> V_22 , L_9 ) ;
return - V_265 ;
}
V_279 = F_165 ( V_273 , V_282 , 0 ) ;
V_4 = F_166 ( & V_273 -> V_22 , V_279 ) ;
if ( F_167 ( V_4 ) )
return F_168 ( V_4 ) ;
F_169 ( & V_273 -> V_22 , L_10 , & V_279 -> V_283 ) ;
V_22 = F_170 ( sizeof( * V_2 ) ) ;
if ( ! V_22 )
return - V_47 ;
F_171 ( V_273 , V_22 ) ;
F_172 ( V_22 , & V_273 -> V_22 ) ;
V_2 = F_29 ( V_22 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_158 = F_173 ( V_273 -> V_22 . V_284 ) ;
if ( V_2 -> V_158 < 0 )
V_2 -> V_158 = V_159 ;
V_2 -> V_160 = F_174 ( & V_273 -> V_22 , NULL ) ;
if ( F_167 ( V_2 -> V_160 ) ) {
F_157 ( & V_273 -> V_22 , L_11 ) ;
V_132 = F_168 ( V_2 -> V_160 ) ;
goto V_285;
}
V_132 = F_175 ( V_2 -> V_160 ) ;
if ( V_132 )
goto V_285;
F_176 ( & V_2 -> V_97 ) ;
if ( V_277 && V_277 -> V_286 ) {
V_132 = V_277 -> V_286 ( V_22 ) ;
if ( V_132 )
goto V_285;
}
V_12 = F_177 ( & V_273 -> V_22 ) ;
if ( ! V_12 ) {
V_132 = - V_47 ;
goto V_287;
}
V_12 -> V_288 = L_12 ;
V_12 -> V_289 = F_23 ;
V_12 -> V_290 = F_26 ;
V_12 -> V_189 = & V_273 -> V_22 ;
snprintf ( V_12 -> V_291 , V_292 , L_13 ,
( unsigned long ) V_279 -> V_283 ) ;
V_12 -> V_2 = V_2 ;
V_132 = F_178 ( V_12 , V_273 -> V_22 . V_284 ) ;
if ( V_132 ) {
F_157 ( & V_273 -> V_22 , L_14 ) ;
goto V_287;
}
if ( F_179 ( V_273 -> V_22 . V_284 ) ) {
V_132 = F_180 ( V_273 -> V_22 . V_284 ) ;
if ( V_132 < 0 ) {
F_157 ( & V_273 -> V_22 , L_15 ) ;
goto V_293;
}
V_2 -> V_213 = F_181 ( V_273 -> V_22 . V_284 ) ;
}
if ( ! V_2 -> V_213 )
V_2 -> V_213 = F_182 ( V_273 -> V_22 . V_284 ,
L_16 , 0 ) ;
if ( ! V_2 -> V_213 ) {
F_157 ( & V_273 -> V_22 , L_17 ) ;
V_132 = - V_218 ;
goto V_293;
}
V_2 -> V_11 = V_12 ;
V_132 = F_151 ( V_22 ) ;
if ( V_132 )
goto V_293;
if ( V_277 && V_277 -> V_294 ) {
V_132 = V_277 -> V_294 ( V_22 ) ;
if ( V_132 )
goto V_293;
}
V_22 -> V_295 = & V_296 ;
V_22 -> V_297 = & V_298 ;
V_22 -> V_186 |= V_299 ;
V_22 -> V_130 = V_130 ;
V_280 = F_183 ( V_273 -> V_22 . V_284 ) ;
if ( V_280 )
F_109 ( V_22 -> V_177 , V_280 ) ;
if ( ! F_184 ( V_22 -> V_177 ) )
F_185 ( V_22 ) ;
F_105 ( V_22 ) ;
F_186 ( V_22 ) ;
V_132 = F_187 ( V_22 ) ;
if ( V_132 ) {
F_45 ( V_22 , L_18 ) ;
goto V_212;
}
F_188 ( V_22 , & V_2 -> V_34 , F_56 , V_300 ) ;
F_189 ( V_22 , L_19 , V_22 -> V_177 ) ;
return 0 ;
V_212:
F_115 ( V_22 ) ;
V_293:
F_190 ( V_12 ) ;
V_287:
F_191 ( V_2 -> V_160 ) ;
V_285:
F_192 ( V_22 ) ;
return V_132 ;
}
static int F_193 ( struct V_272 * V_273 )
{
struct V_21 * V_301 = F_194 ( V_273 ) ;
struct V_1 * V_2 = F_29 ( V_301 ) ;
F_195 ( V_301 ) ;
F_190 ( V_2 -> V_11 ) ;
F_191 ( V_2 -> V_160 ) ;
F_115 ( V_301 ) ;
F_192 ( V_301 ) ;
return 0 ;
}
