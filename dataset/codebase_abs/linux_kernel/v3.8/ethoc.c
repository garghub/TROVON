static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_6 ,
struct V_7 * V_8 )
{
T_2 V_3 = V_9 + ( V_6 * sizeof( struct V_7 ) ) ;
V_8 -> V_10 = F_1 ( V_2 , V_3 + 0 ) ;
V_8 -> V_11 = F_1 ( V_2 , V_3 + 4 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_6 ,
const struct V_7 * V_8 )
{
T_2 V_3 = V_9 + ( V_6 * sizeof( struct V_7 ) ) ;
F_3 ( V_2 , V_3 + 0 , V_8 -> V_10 ) ;
F_3 ( V_2 , V_3 + 4 , V_8 -> V_11 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_12 )
{
T_1 V_13 = F_1 ( V_2 , V_14 ) ;
V_13 |= V_12 ;
F_3 ( V_2 , V_14 , V_13 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_12 )
{
T_1 V_13 = F_1 ( V_2 , V_14 ) ;
V_13 &= ~ V_12 ;
F_3 ( V_2 , V_14 , V_13 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_12 )
{
F_3 ( V_2 , V_15 , V_12 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
T_1 V_16 = F_1 ( V_2 , V_17 ) ;
V_16 |= V_18 | V_19 ;
F_3 ( V_2 , V_17 , V_16 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
T_1 V_16 = F_1 ( V_2 , V_17 ) ;
V_16 &= ~ ( V_18 | V_19 ) ;
F_3 ( V_2 , V_17 , V_16 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_20 )
{
struct V_7 V_8 ;
int V_21 ;
void * V_22 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
F_3 ( V_2 , V_26 , V_2 -> V_27 ) ;
V_8 . V_11 = V_20 ;
V_8 . V_10 = V_28 | V_29 ;
V_22 = V_2 -> V_30 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_27 ; V_21 ++ ) {
if ( V_21 == V_2 -> V_27 - 1 )
V_8 . V_10 |= V_31 ;
F_6 ( V_2 , V_21 , & V_8 ) ;
V_8 . V_11 += V_32 ;
V_2 -> V_22 [ V_21 ] = V_22 ;
V_22 += V_32 ;
}
V_8 . V_10 = V_33 | V_34 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_35 ; V_21 ++ ) {
if ( V_21 == V_2 -> V_35 - 1 )
V_8 . V_10 |= V_36 ;
F_6 ( V_2 , V_2 -> V_27 + V_21 , & V_8 ) ;
V_8 . V_11 += V_32 ;
V_2 -> V_22 [ V_2 -> V_27 + V_21 ] = V_22 ;
V_22 += V_32 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_16 ;
F_11 ( V_2 ) ;
V_16 = F_1 ( V_2 , V_17 ) ;
V_16 |= V_37 | V_38 ;
F_3 ( V_2 , V_17 , V_16 ) ;
V_16 = F_1 ( V_2 , V_17 ) ;
V_16 |= V_39 ;
F_3 ( V_2 , V_17 , V_16 ) ;
F_3 ( V_2 , V_40 , 0x15 ) ;
F_9 ( V_2 , V_41 ) ;
F_7 ( V_2 , V_41 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static unsigned int F_14 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
unsigned int V_44 = 0 ;
if ( V_8 -> V_10 & V_45 ) {
F_15 ( & V_43 -> V_2 , L_1 ) ;
V_43 -> V_46 . V_47 ++ ;
V_44 ++ ;
}
if ( V_8 -> V_10 & V_48 ) {
F_15 ( & V_43 -> V_2 , L_2 ) ;
V_43 -> V_46 . V_47 ++ ;
V_44 ++ ;
}
if ( V_8 -> V_10 & V_49 ) {
F_15 ( & V_43 -> V_2 , L_3 ) ;
V_43 -> V_46 . V_50 ++ ;
}
if ( V_8 -> V_10 & V_51 ) {
F_15 ( & V_43 -> V_2 , L_4 ) ;
V_43 -> V_46 . V_52 ++ ;
V_44 ++ ;
}
if ( V_8 -> V_10 & V_53 ) {
F_15 ( & V_43 -> V_2 , L_5 ) ;
V_43 -> V_46 . V_54 ++ ;
V_44 ++ ;
}
if ( V_8 -> V_10 & V_55 )
V_43 -> V_46 . V_56 ++ ;
if ( V_8 -> V_10 & V_57 ) {
F_15 ( & V_43 -> V_2 , L_6 ) ;
V_43 -> V_46 . V_58 ++ ;
V_44 ++ ;
}
return V_44 ;
}
static int F_16 ( struct V_42 * V_2 , int V_59 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_59 ; ++ V_61 ) {
unsigned int V_62 ;
struct V_7 V_8 ;
V_62 = V_60 -> V_27 + V_60 -> V_25 ;
F_5 ( V_60 , V_62 , & V_8 ) ;
if ( V_8 . V_10 & V_33 ) {
F_9 ( V_60 , V_63 ) ;
F_5 ( V_60 , V_62 , & V_8 ) ;
if ( V_8 . V_10 & V_33 )
break;
}
if ( F_14 ( V_60 , & V_8 ) == 0 ) {
int V_64 = V_8 . V_10 >> 16 ;
struct V_65 * V_66 ;
V_64 -= 4 ;
V_66 = F_18 ( V_2 , V_64 ) ;
if ( F_19 ( V_66 ) ) {
void * V_67 = V_60 -> V_22 [ V_62 ] ;
F_20 ( F_21 ( V_66 , V_64 ) , V_67 , V_64 ) ;
V_66 -> V_68 = F_22 ( V_66 , V_2 ) ;
V_2 -> V_46 . V_69 ++ ;
V_2 -> V_46 . V_70 += V_64 ;
F_23 ( V_66 ) ;
} else {
if ( F_24 () )
F_25 ( & V_2 -> V_2 , L_7
L_8 ) ;
V_2 -> V_46 . V_71 ++ ;
break;
}
}
V_8 . V_10 &= ~ V_72 ;
V_8 . V_10 |= V_33 ;
F_6 ( V_60 , V_62 , & V_8 ) ;
if ( ++ V_60 -> V_25 == V_60 -> V_35 )
V_60 -> V_25 = 0 ;
}
return V_61 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
if ( V_8 -> V_10 & V_73 ) {
F_15 ( & V_43 -> V_2 , L_9 ) ;
V_43 -> V_46 . V_74 ++ ;
}
if ( V_8 -> V_10 & V_75 ) {
F_15 ( & V_43 -> V_2 , L_10 ) ;
V_43 -> V_46 . V_76 ++ ;
}
if ( V_8 -> V_10 & V_77 ) {
F_15 ( & V_43 -> V_2 , L_11 ) ;
V_43 -> V_46 . V_78 ++ ;
}
if ( V_8 -> V_10 & V_79 ) {
F_15 ( & V_43 -> V_2 , L_12 ) ;
V_43 -> V_46 . V_80 ++ ;
}
if ( V_8 -> V_10 & V_81 )
V_43 -> V_46 . V_82 ++ ;
V_43 -> V_46 . V_58 += ( V_8 -> V_10 >> 4 ) & 0xf ;
V_43 -> V_46 . V_83 += V_8 -> V_10 >> 16 ;
V_43 -> V_46 . V_84 ++ ;
}
static int F_27 ( struct V_42 * V_2 , int V_59 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
int V_61 ;
struct V_7 V_8 ;
for ( V_61 = 0 ; V_61 < V_59 ; ++ V_61 ) {
unsigned int V_62 ;
V_62 = V_60 -> V_24 & ( V_60 -> V_27 - 1 ) ;
F_5 ( V_60 , V_62 , & V_8 ) ;
if ( V_8 . V_10 & V_85 || ( V_60 -> V_24 == V_60 -> V_23 ) ) {
F_9 ( V_60 , V_86 ) ;
F_5 ( V_60 , V_62 , & V_8 ) ;
if ( V_8 . V_10 & V_85 ||
( V_60 -> V_24 == V_60 -> V_23 ) )
break;
}
F_26 ( V_60 , & V_8 ) ;
V_60 -> V_24 ++ ;
}
if ( ( V_60 -> V_23 - V_60 -> V_24 ) <= ( V_60 -> V_27 / 2 ) )
F_28 ( V_2 ) ;
return V_61 ;
}
static T_3 F_29 ( int V_87 , void * V_88 )
{
struct V_42 * V_2 = V_88 ;
struct V_1 * V_60 = F_17 ( V_2 ) ;
T_1 V_89 ;
T_1 V_12 ;
V_12 = F_1 ( V_60 , V_14 ) ;
V_89 = F_1 ( V_60 , V_15 ) ;
V_89 &= V_12 ;
if ( F_30 ( V_89 == 0 ) ) {
return V_90 ;
}
F_9 ( V_60 , V_89 ) ;
if ( V_89 & V_91 ) {
F_15 ( & V_2 -> V_2 , L_8 ) ;
V_2 -> V_46 . V_71 ++ ;
}
if ( V_89 & ( V_86 | V_63 ) ) {
F_8 ( V_60 , V_86 | V_63 ) ;
F_31 ( & V_60 -> V_92 ) ;
}
return V_93 ;
}
static int F_32 ( struct V_42 * V_2 , void * V_11 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
T_4 * V_94 = ( T_4 * ) V_11 ;
T_1 V_95 ;
V_95 = F_1 ( V_60 , V_96 ) ;
V_94 [ 2 ] = ( V_95 >> 24 ) & 0xff ;
V_94 [ 3 ] = ( V_95 >> 16 ) & 0xff ;
V_94 [ 4 ] = ( V_95 >> 8 ) & 0xff ;
V_94 [ 5 ] = ( V_95 >> 0 ) & 0xff ;
V_95 = F_1 ( V_60 , V_97 ) ;
V_94 [ 0 ] = ( V_95 >> 8 ) & 0xff ;
V_94 [ 1 ] = ( V_95 >> 0 ) & 0xff ;
return 0 ;
}
static int F_33 ( struct V_98 * V_92 , int V_99 )
{
struct V_1 * V_60 = F_34 ( V_92 , struct V_1 , V_92 ) ;
int V_100 = 0 ;
int V_101 = 0 ;
V_100 = F_16 ( V_60 -> V_43 , V_99 ) ;
V_101 = F_27 ( V_60 -> V_43 , V_99 ) ;
if ( V_100 < V_99 && V_101 < V_99 ) {
F_35 ( V_92 ) ;
F_7 ( V_60 , V_86 | V_63 ) ;
}
return V_100 ;
}
static int F_36 ( struct V_102 * V_103 , int V_104 , int V_95 )
{
struct V_1 * V_60 = V_103 -> V_60 ;
int V_21 ;
F_3 ( V_60 , V_105 , F_37 ( V_104 , V_95 ) ) ;
F_3 ( V_60 , V_106 , V_107 ) ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
T_1 V_108 = F_1 ( V_60 , V_109 ) ;
if ( ! ( V_108 & V_110 ) ) {
T_1 V_5 = F_1 ( V_60 , V_111 ) ;
F_3 ( V_60 , V_106 , 0 ) ;
return V_5 ;
}
F_38 ( 100 , 200 ) ;
}
return - V_112 ;
}
static int F_39 ( struct V_102 * V_103 , int V_104 , int V_95 , T_5 V_113 )
{
struct V_1 * V_60 = V_103 -> V_60 ;
int V_21 ;
F_3 ( V_60 , V_105 , F_37 ( V_104 , V_95 ) ) ;
F_3 ( V_60 , V_114 , V_113 ) ;
F_3 ( V_60 , V_106 , V_115 ) ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
T_1 V_10 = F_1 ( V_60 , V_109 ) ;
if ( ! ( V_10 & V_110 ) ) {
F_3 ( V_60 , V_106 , 0 ) ;
return 0 ;
}
F_38 ( 100 , 200 ) ;
}
return - V_112 ;
}
static int F_40 ( struct V_102 * V_103 )
{
return 0 ;
}
static void F_41 ( struct V_42 * V_2 )
{
}
static int F_42 ( struct V_42 * V_2 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
struct V_116 * V_104 ;
int V_117 ;
if ( V_60 -> V_118 != - 1 ) {
V_104 = V_60 -> V_119 -> V_120 [ V_60 -> V_118 ] ;
} else {
V_104 = F_43 ( V_60 -> V_119 ) ;
}
if ( ! V_104 ) {
F_15 ( & V_2 -> V_2 , L_13 ) ;
return - V_121 ;
}
V_117 = F_44 ( V_2 , V_104 , F_41 , 0 ,
V_122 ) ;
if ( V_117 ) {
F_15 ( & V_2 -> V_2 , L_14 ) ;
return V_117 ;
}
V_60 -> V_104 = V_104 ;
return 0 ;
}
static int F_45 ( struct V_42 * V_2 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
int V_44 ;
V_44 = F_46 ( V_2 -> V_87 , F_29 , V_123 ,
V_2 -> V_124 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_12 ( V_60 , V_2 -> V_20 ) ;
F_13 ( V_60 ) ;
if ( F_47 ( V_2 ) ) {
F_48 ( & V_2 -> V_2 , L_15 ) ;
F_28 ( V_2 ) ;
} else {
F_48 ( & V_2 -> V_2 , L_16 ) ;
F_49 ( V_2 ) ;
}
F_50 ( V_60 -> V_104 ) ;
F_51 ( & V_60 -> V_92 ) ;
if ( F_52 ( V_60 ) ) {
F_53 ( & V_2 -> V_2 , L_17 ,
V_2 -> V_125 , V_2 -> V_20 , V_2 -> V_126 ) ;
}
return 0 ;
}
static int F_54 ( struct V_42 * V_2 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
F_55 ( & V_60 -> V_92 ) ;
if ( V_60 -> V_104 )
F_56 ( V_60 -> V_104 ) ;
F_11 ( V_60 ) ;
F_57 ( V_2 -> V_87 , V_2 ) ;
if ( ! F_47 ( V_2 ) )
F_58 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_42 * V_2 , struct V_127 * V_128 , int V_129 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
struct V_130 * V_119 = F_60 ( V_128 ) ;
struct V_116 * V_104 = NULL ;
if ( ! F_61 ( V_2 ) )
return - V_131 ;
if ( V_129 != V_132 ) {
if ( V_119 -> V_118 >= V_133 )
return - V_134 ;
V_104 = V_60 -> V_119 -> V_120 [ V_119 -> V_118 ] ;
if ( ! V_104 )
return - V_135 ;
} else {
V_104 = V_60 -> V_104 ;
}
return F_62 ( V_104 , V_128 , V_129 ) ;
}
static int F_63 ( struct V_42 * V_2 , struct V_136 * V_137 )
{
return - V_138 ;
}
static int F_64 ( struct V_42 * V_2 , void * V_11 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
T_4 * V_94 = ( T_4 * ) V_11 ;
if ( ! F_65 ( V_94 ) )
return - V_139 ;
F_3 ( V_60 , V_96 , ( V_94 [ 2 ] << 24 ) | ( V_94 [ 3 ] << 16 ) |
( V_94 [ 4 ] << 8 ) | ( V_94 [ 5 ] << 0 ) ) ;
F_3 ( V_60 , V_97 , ( V_94 [ 0 ] << 8 ) | ( V_94 [ 1 ] << 0 ) ) ;
memcpy ( V_2 -> V_140 , V_94 , V_141 ) ;
V_2 -> V_142 &= ~ V_143 ;
return 0 ;
}
static void F_66 ( struct V_42 * V_2 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
T_1 V_16 = F_1 ( V_60 , V_17 ) ;
struct V_144 * V_145 ;
T_1 V_146 [ 2 ] = { 0 , 0 } ;
if ( V_2 -> V_147 & V_148 )
V_16 |= V_149 ;
else
V_16 &= ~ V_149 ;
if ( V_2 -> V_147 & V_150 )
V_16 &= ~ V_151 ;
else
V_16 |= V_151 ;
if ( V_2 -> V_147 & V_152 )
V_16 |= V_153 ;
else
V_16 &= ~ V_153 ;
F_3 ( V_60 , V_17 , V_16 ) ;
if ( V_2 -> V_147 & V_154 ) {
V_146 [ 0 ] = 0xffffffff ;
V_146 [ 1 ] = 0xffffffff ;
} else {
F_67 (ha, dev) {
T_1 V_155 = F_68 ( V_141 , V_145 -> V_11 ) ;
int V_156 = ( V_155 >> 26 ) & 0x3f ;
V_146 [ V_156 >> 5 ] |= 1 << ( V_156 & 0x1f ) ;
}
}
F_3 ( V_60 , V_157 , V_146 [ 0 ] ) ;
F_3 ( V_60 , V_158 , V_146 [ 1 ] ) ;
}
static int F_69 ( struct V_42 * V_2 , int V_159 )
{
return - V_138 ;
}
static void F_70 ( struct V_42 * V_2 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
T_1 V_89 = F_1 ( V_60 , V_15 ) ;
if ( F_19 ( V_89 ) )
F_29 ( V_2 -> V_87 , V_2 ) ;
}
static T_6 F_71 ( struct V_65 * V_66 , struct V_42 * V_2 )
{
struct V_1 * V_60 = F_17 ( V_2 ) ;
struct V_7 V_8 ;
unsigned int V_62 ;
void * V_160 ;
if ( F_30 ( V_66 -> V_161 > V_32 ) ) {
V_2 -> V_46 . V_82 ++ ;
goto V_162;
}
V_62 = V_60 -> V_23 % V_60 -> V_27 ;
F_72 ( & V_60 -> V_163 ) ;
V_60 -> V_23 ++ ;
F_5 ( V_60 , V_62 , & V_8 ) ;
if ( F_30 ( V_66 -> V_161 < V_164 ) )
V_8 . V_10 |= V_165 ;
else
V_8 . V_10 &= ~ V_165 ;
V_160 = V_60 -> V_22 [ V_62 ] ;
F_73 ( V_160 , V_66 -> V_5 , V_66 -> V_161 ) ;
V_8 . V_10 &= ~ ( V_81 | V_166 ) ;
V_8 . V_10 |= F_74 ( V_66 -> V_161 ) ;
F_6 ( V_60 , V_62 , & V_8 ) ;
V_8 . V_10 |= V_85 ;
F_6 ( V_60 , V_62 , & V_8 ) ;
if ( V_60 -> V_23 == ( V_60 -> V_24 + V_60 -> V_27 ) ) {
F_48 ( & V_2 -> V_2 , L_18 ) ;
F_58 ( V_2 ) ;
}
F_75 ( & V_60 -> V_163 ) ;
F_76 ( V_66 ) ;
V_162:
F_77 ( V_66 ) ;
return V_167 ;
}
static int F_78 ( struct V_168 * V_169 )
{
struct V_42 * V_43 = NULL ;
struct V_170 * V_171 = NULL ;
struct V_170 * V_172 = NULL ;
struct V_170 * V_173 = NULL ;
struct V_1 * V_60 = NULL ;
unsigned int V_104 ;
int V_174 ;
int V_44 = 0 ;
bool V_175 = false ;
V_43 = F_79 ( sizeof( struct V_1 ) ) ;
if ( ! V_43 ) {
V_44 = - V_176 ;
goto V_162;
}
F_80 ( V_43 , & V_169 -> V_2 ) ;
F_81 ( V_169 , V_43 ) ;
V_171 = F_82 ( V_169 , V_177 , 0 ) ;
if ( ! V_171 ) {
F_15 ( & V_169 -> V_2 , L_19 ) ;
V_44 = - V_121 ;
goto free;
}
V_172 = F_83 ( & V_169 -> V_2 , V_171 -> V_178 ,
F_84 ( V_171 ) , V_171 -> V_124 ) ;
if ( ! V_172 ) {
F_15 ( & V_169 -> V_2 , L_20 ) ;
V_44 = - V_121 ;
goto free;
}
V_43 -> V_125 = V_172 -> V_178 ;
V_171 = F_82 ( V_169 , V_177 , 1 ) ;
if ( V_171 ) {
V_173 = F_83 ( & V_169 -> V_2 , V_171 -> V_178 ,
F_84 ( V_171 ) , V_171 -> V_124 ) ;
if ( ! V_173 ) {
F_15 ( & V_169 -> V_2 , L_21 ) ;
V_44 = - V_121 ;
goto free;
}
V_43 -> V_20 = V_173 -> V_178 ;
V_43 -> V_126 = V_173 -> V_179 ;
}
V_171 = F_82 ( V_169 , V_180 , 0 ) ;
if ( ! V_171 ) {
F_15 ( & V_169 -> V_2 , L_22 ) ;
V_44 = - V_121 ;
goto free;
}
V_43 -> V_87 = V_171 -> V_178 ;
V_60 = F_17 ( V_43 ) ;
V_60 -> V_43 = V_43 ;
V_60 -> V_181 = 0 ;
V_60 -> V_182 = F_84 ( V_172 ) ;
V_60 -> V_4 = F_85 ( & V_169 -> V_2 , V_43 -> V_125 ,
F_84 ( V_172 ) ) ;
if ( ! V_60 -> V_4 ) {
F_15 ( & V_169 -> V_2 , L_23 ) ;
V_44 = - V_121 ;
goto error;
}
if ( V_43 -> V_126 ) {
V_60 -> V_30 = F_85 ( & V_169 -> V_2 ,
V_43 -> V_20 , F_84 ( V_173 ) ) ;
if ( ! V_60 -> V_30 ) {
F_15 ( & V_169 -> V_2 , L_24 ) ;
V_44 = - V_121 ;
goto error;
}
} else {
V_60 -> V_30 = F_86 ( & V_169 -> V_2 ,
V_183 , ( void * ) & V_43 -> V_20 ,
V_184 ) ;
if ( ! V_60 -> V_30 ) {
F_15 ( & V_169 -> V_2 , L_25 ,
V_183 ) ;
V_44 = - V_176 ;
goto error;
}
V_43 -> V_126 = V_43 -> V_20 + V_183 ;
V_60 -> V_181 = V_183 ;
}
V_174 = F_87 (unsigned int,
128 , (netdev->mem_end - netdev->mem_start + 1) / ETHOC_BUFSIZ) ;
if ( V_174 < 4 ) {
V_44 = - V_135 ;
goto error;
}
V_60 -> V_27 = F_88 ( V_174 >> 1 ) ;
V_60 -> V_35 = V_174 - V_60 -> V_27 ;
F_48 ( & V_169 -> V_2 , L_26 ,
V_60 -> V_27 , V_60 -> V_35 ) ;
V_60 -> V_22 = F_89 ( & V_169 -> V_2 , V_174 * sizeof( void * ) , V_184 ) ;
if ( ! V_60 -> V_22 ) {
V_44 = - V_176 ;
goto error;
}
if ( V_169 -> V_2 . V_185 ) {
struct V_186 * V_187 = V_169 -> V_2 . V_185 ;
memcpy ( V_43 -> V_140 , V_187 -> V_188 , V_189 ) ;
V_60 -> V_118 = V_187 -> V_118 ;
} else {
V_60 -> V_118 = - 1 ;
#ifdef F_90
{
const T_7 * V_94 ;
V_94 = F_91 ( V_169 -> V_2 . V_190 ,
L_27 ,
NULL ) ;
if ( V_94 )
memcpy ( V_43 -> V_140 , V_94 , V_189 ) ;
}
#endif
}
if ( ! F_65 ( V_43 -> V_140 ) )
F_32 ( V_43 , V_43 -> V_140 ) ;
if ( ! F_65 ( V_43 -> V_140 ) ) {
F_92 ( V_43 -> V_140 ) ;
V_175 = true ;
}
V_44 = F_64 ( V_43 , V_43 -> V_140 ) ;
if ( V_44 ) {
F_15 ( & V_43 -> V_2 , L_28 ) ;
goto error;
}
if ( V_175 )
V_43 -> V_142 |= V_143 ;
V_60 -> V_119 = F_93 () ;
if ( ! V_60 -> V_119 ) {
V_44 = - V_176 ;
goto free;
}
V_60 -> V_119 -> V_124 = L_29 ;
snprintf ( V_60 -> V_119 -> V_191 , V_192 , L_30 ,
V_60 -> V_119 -> V_124 , V_169 -> V_191 ) ;
V_60 -> V_119 -> V_193 = F_36 ;
V_60 -> V_119 -> V_194 = F_39 ;
V_60 -> V_119 -> V_195 = F_40 ;
V_60 -> V_119 -> V_60 = V_60 ;
V_60 -> V_119 -> V_87 = F_94 ( sizeof( int ) * V_133 , V_184 ) ;
if ( ! V_60 -> V_119 -> V_87 ) {
V_44 = - V_176 ;
goto V_196;
}
for ( V_104 = 0 ; V_104 < V_133 ; V_104 ++ )
V_60 -> V_119 -> V_87 [ V_104 ] = V_197 ;
V_44 = F_95 ( V_60 -> V_119 ) ;
if ( V_44 ) {
F_15 ( & V_43 -> V_2 , L_31 ) ;
goto V_196;
}
V_44 = F_42 ( V_43 ) ;
if ( V_44 ) {
F_15 ( & V_43 -> V_2 , L_32 ) ;
goto error;
}
F_96 ( V_43 ) ;
V_43 -> V_198 = & V_199 ;
V_43 -> V_200 = V_201 ;
V_43 -> V_202 |= 0 ;
F_97 ( V_43 , & V_60 -> V_92 , F_33 , 64 ) ;
F_98 ( & V_60 -> V_163 ) ;
V_44 = F_99 ( V_43 ) ;
if ( V_44 < 0 ) {
F_15 ( & V_43 -> V_2 , L_33 ) ;
goto V_203;
}
goto V_162;
V_203:
F_100 ( & V_60 -> V_92 ) ;
error:
F_101 ( V_60 -> V_119 ) ;
V_196:
F_102 ( V_60 -> V_119 -> V_87 ) ;
F_103 ( V_60 -> V_119 ) ;
free:
F_104 ( V_43 ) ;
V_162:
return V_44 ;
}
static int F_105 ( struct V_168 * V_169 )
{
struct V_42 * V_43 = F_106 ( V_169 ) ;
struct V_1 * V_60 = F_17 ( V_43 ) ;
F_81 ( V_169 , NULL ) ;
if ( V_43 ) {
F_100 ( & V_60 -> V_92 ) ;
F_107 ( V_60 -> V_104 ) ;
V_60 -> V_104 = NULL ;
if ( V_60 -> V_119 ) {
F_101 ( V_60 -> V_119 ) ;
F_102 ( V_60 -> V_119 -> V_87 ) ;
F_103 ( V_60 -> V_119 ) ;
}
F_108 ( V_43 ) ;
F_104 ( V_43 ) ;
}
return 0 ;
}
static int F_109 ( struct V_168 * V_169 , T_8 V_204 )
{
return - V_138 ;
}
static int F_110 ( struct V_168 * V_169 )
{
return - V_138 ;
}
