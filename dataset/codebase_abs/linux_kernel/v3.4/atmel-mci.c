static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_9 * V_11 ;
struct V_12 * V_13 ;
F_2 ( & V_5 -> V_14 -> V_15 ) ;
V_8 = V_5 -> V_8 ;
if ( V_8 ) {
V_10 = V_8 -> V_10 ;
V_13 = V_8 -> V_13 ;
V_11 = V_8 -> V_11 ;
if ( V_10 )
F_3 ( V_2 ,
L_1 ,
V_10 -> V_16 , V_10 -> V_17 , V_10 -> V_18 ,
V_10 -> V_19 [ 0 ] , V_10 -> V_19 [ 1 ] , V_10 -> V_19 [ 2 ] ,
V_10 -> V_19 [ 3 ] , V_10 -> error ) ;
if ( V_13 )
F_3 ( V_2 , L_2 ,
V_13 -> V_20 , V_13 -> V_21 ,
V_13 -> V_22 , V_13 -> V_18 , V_13 -> error ) ;
if ( V_11 )
F_3 ( V_2 ,
L_1 ,
V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 ,
V_11 -> V_19 [ 0 ] , V_11 -> V_19 [ 1 ] , V_11 -> V_19 [ 2 ] ,
V_11 -> V_19 [ 3 ] , V_11 -> error ) ;
}
F_4 ( & V_5 -> V_14 -> V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_6 ( V_24 , F_1 , V_23 -> V_25 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
const char * V_26 , T_1 V_27 )
{
static const char * V_28 [] = {
[ 0 ] = L_3 ,
[ 1 ] = L_4 ,
[ 2 ] = L_5 ,
[ 3 ] = L_6 ,
[ 4 ] = L_7 ,
[ 5 ] = L_8 ,
[ 6 ] = L_9 ,
[ 7 ] = L_10 ,
[ 8 ] = L_11 ,
[ 9 ] = L_12 ,
[ 12 ] = L_13 ,
[ 14 ] = L_14 ,
[ 15 ] = L_15 ,
[ 16 ] = L_16 ,
[ 17 ] = L_17 ,
[ 18 ] = L_18 ,
[ 19 ] = L_19 ,
[ 20 ] = L_20 ,
[ 21 ] = L_21 ,
[ 22 ] = L_22 ,
[ 23 ] = L_23 ,
[ 24 ] = L_24 ,
[ 25 ] = L_25 ,
[ 26 ] = L_26 ,
[ 27 ] = L_27 ,
[ 30 ] = L_28 ,
[ 31 ] = L_29 ,
} ;
unsigned int V_29 ;
F_3 ( V_2 , L_30 , V_26 , V_27 ) ;
for ( V_29 = 0 ; V_29 < F_8 ( V_28 ) ; V_29 ++ ) {
if ( V_27 & ( 1 << V_29 ) ) {
if ( V_28 [ V_29 ] )
F_3 ( V_2 , L_31 , V_28 [ V_29 ] ) ;
else
F_9 ( V_2 , L_32 ) ;
}
}
F_10 ( V_2 , '\n' ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_3 )
{
struct V_30 * V_14 = V_2 -> V_6 ;
T_1 * V_31 ;
V_31 = F_12 ( V_32 , V_33 ) ;
if ( ! V_31 )
return - V_34 ;
F_2 ( & V_14 -> V_15 ) ;
F_13 ( V_14 -> V_35 ) ;
F_14 ( V_31 , V_14 -> V_36 , V_32 ) ;
F_15 ( V_14 -> V_35 ) ;
F_4 ( & V_14 -> V_15 ) ;
F_3 ( V_2 , L_33 ,
V_31 [ V_37 / 4 ] ,
V_31 [ V_37 / 4 ] & V_38 ? L_34 : L_35 ,
V_31 [ V_37 / 4 ] & V_39 ? L_36 : L_35 ,
V_31 [ V_37 / 4 ] & 0xff ) ;
F_3 ( V_2 , L_37 , V_31 [ V_40 / 4 ] ) ;
F_3 ( V_2 , L_38 , V_31 [ V_41 / 4 ] ) ;
F_3 ( V_2 , L_39 , V_31 [ V_42 / 4 ] ) ;
F_3 ( V_2 , L_40 ,
V_31 [ V_43 / 4 ] ,
V_31 [ V_43 / 4 ] & 0xffff ,
( V_31 [ V_43 / 4 ] >> 16 ) & 0xffff ) ;
if ( V_14 -> V_44 . V_45 )
F_3 ( V_2 , L_41 , V_31 [ V_46 / 4 ] ) ;
F_7 ( V_2 , L_42 , V_31 [ V_47 / 4 ] ) ;
F_7 ( V_2 , L_43 , V_31 [ V_48 / 4 ] ) ;
if ( V_14 -> V_44 . V_49 ) {
T_1 V_50 ;
V_50 = V_31 [ V_51 / 4 ] ;
F_3 ( V_2 , L_44 ,
V_50 , V_50 & 3 ,
( ( V_50 >> 4 ) & 3 ) ?
1 << ( ( ( V_50 >> 4 ) & 3 ) + 1 ) : 1 ,
V_50 & V_52 ? L_45 : L_35 ) ;
}
if ( V_14 -> V_44 . V_53 ) {
T_1 V_50 ;
V_50 = V_31 [ V_54 / 4 ] ;
F_3 ( V_2 , L_46 ,
V_50 ,
V_50 & V_55 ? L_47 : L_35 ,
V_50 & V_56 ? L_48 : L_35 ,
V_50 & V_57 ? L_49 : L_35 ,
V_50 & V_58 ? L_50 : L_35 ) ;
}
F_16 ( V_31 ) ;
return 0 ;
}
static int F_17 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_6 ( V_24 , F_11 , V_23 -> V_25 ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
struct V_59 * V_60 = V_5 -> V_60 ;
struct V_30 * V_14 = V_5 -> V_14 ;
struct V_61 * V_62 ;
struct V_61 * V_63 ;
V_62 = V_60 -> V_64 ;
if ( ! V_62 )
return;
V_63 = F_19 ( L_51 , V_65 , V_62 , V_14 ,
& V_66 ) ;
if ( F_20 ( V_63 ) )
return;
if ( ! V_63 )
goto V_67;
V_63 = F_19 ( L_52 , V_65 , V_62 , V_5 , & V_68 ) ;
if ( ! V_63 )
goto V_67;
V_63 = F_21 ( L_53 , V_65 , V_62 , ( T_1 * ) & V_14 -> V_69 ) ;
if ( ! V_63 )
goto V_67;
V_63 = F_22 ( L_54 , V_65 , V_62 ,
( T_1 * ) & V_14 -> V_70 ) ;
if ( ! V_63 )
goto V_67;
V_63 = F_22 ( L_55 , V_65 , V_62 ,
( T_1 * ) & V_14 -> V_71 ) ;
if ( ! V_63 )
goto V_67;
return;
V_67:
F_23 ( & V_60 -> V_72 , L_56 ) ;
}
static inline unsigned int F_24 ( struct V_30 * V_14 ,
unsigned int V_73 )
{
unsigned int V_74 = F_25 ( V_73 , 1000 ) ;
return V_74 * ( F_25 ( V_14 -> V_75 , 2000000 ) ) ;
}
static void F_26 ( struct V_30 * V_14 ,
struct V_4 * V_5 , struct V_12 * V_13 )
{
static unsigned V_76 [] = {
0 , 4 , 7 , 8 , 10 , 12 , 16 , 20
} ;
unsigned V_77 ;
unsigned V_78 ;
unsigned V_79 ;
V_77 = F_24 ( V_14 , V_13 -> V_80 )
+ V_13 -> V_81 ;
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ ) {
unsigned V_82 = V_76 [ V_79 ] ;
V_78 = ( V_77 + ( 1 << V_82 ) - 1 ) >> V_82 ;
if ( V_78 < 15 )
break;
}
if ( V_79 >= 8 ) {
V_79 = 7 ;
V_78 = 15 ;
}
F_27 ( & V_5 -> V_60 -> V_72 , L_57 ,
V_78 << V_76 [ V_79 ] ) ;
F_28 ( V_14 , V_40 , ( F_29 ( V_79 ) | F_30 ( V_78 ) ) ) ;
}
static T_1 F_31 ( struct V_59 * V_60 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 ;
T_1 V_83 ;
V_10 -> error = - V_84 ;
V_83 = F_32 ( V_10 -> V_16 ) ;
if ( V_10 -> V_18 & V_85 ) {
if ( V_10 -> V_18 & V_86 )
V_83 |= V_87 ;
else
V_83 |= V_88 ;
}
V_83 |= V_89 ;
if ( V_60 -> V_90 . V_91 == V_92 )
V_83 |= V_93 ;
V_13 = V_10 -> V_13 ;
if ( V_13 ) {
V_83 |= V_94 ;
if ( V_10 -> V_16 == V_95 ) {
V_83 |= V_96 ;
} else {
if ( V_13 -> V_18 & V_97 )
V_83 |= V_98 ;
else if ( V_13 -> V_21 > 1 )
V_83 |= V_99 ;
else
V_83 |= V_100 ;
}
if ( V_13 -> V_18 & V_101 )
V_83 |= V_102 ;
}
return V_83 ;
}
static void F_33 ( struct V_30 * V_14 ,
struct V_9 * V_10 , T_1 V_103 )
{
F_34 ( V_14 -> V_10 ) ;
V_14 -> V_10 = V_10 ;
F_27 ( & V_14 -> V_104 -> V_105 ,
L_58 ,
V_10 -> V_17 , V_103 ) ;
F_28 ( V_14 , V_42 , V_10 -> V_17 ) ;
F_28 ( V_14 , V_106 , V_103 ) ;
}
static void F_35 ( struct V_30 * V_14 , struct V_12 * V_13 )
{
F_33 ( V_14 , V_13 -> V_11 , V_14 -> V_107 ) ;
F_28 ( V_14 , V_108 , V_109 ) ;
}
static void F_36 ( struct V_30 * V_14 ,
enum V_110 V_111 , enum V_112 V_113 )
{
T_1 V_114 , V_115 ;
if ( V_111 == V_116 ) {
V_114 = V_117 ;
V_115 = V_118 ;
} else {
V_114 = V_119 ;
V_115 = V_120 ;
}
if ( V_113 == V_121 ) {
V_114 += V_122 ;
V_115 += V_122 ;
}
F_28 ( V_14 , V_114 , F_37 ( V_14 -> V_123 ) ) ;
if ( V_14 -> V_124 <= F_38 ( V_14 -> V_123 ) ) {
if ( V_14 -> V_124 & 0x3 ) {
F_28 ( V_14 , V_115 , V_14 -> V_124 ) ;
F_28 ( V_14 , V_37 , V_14 -> V_125 | V_126 ) ;
} else {
F_28 ( V_14 , V_115 , V_14 -> V_124 / 4 ) ;
}
V_14 -> V_124 = 0 ;
} else {
F_28 ( V_14 , V_115 , F_38 ( V_14 -> V_123 ) / 4 ) ;
V_14 -> V_124 -= F_38 ( V_14 -> V_123 ) ;
if ( V_14 -> V_124 )
V_14 -> V_123 = F_39 ( V_14 -> V_123 ) ;
}
}
static void F_40 ( struct V_30 * V_14 , int V_111 )
{
F_36 ( V_14 , V_111 , V_127 ) ;
if ( V_14 -> V_124 )
F_36 ( V_14 , V_111 , V_121 ) ;
}
static void F_41 ( struct V_30 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 )
F_42 ( & V_14 -> V_104 -> V_105 ,
V_13 -> V_123 , V_13 -> V_128 ,
( ( V_13 -> V_18 & V_129 )
? V_130 : V_131 ) ) ;
}
static void F_43 ( struct V_30 * V_14 )
{
F_28 ( V_14 , V_132 , V_133 | V_134 ) ;
F_41 ( V_14 ) ;
if ( V_14 -> V_13 ) {
F_44 ( V_14 , V_135 ) ;
F_45 ( & V_14 -> V_136 ) ;
F_28 ( V_14 , V_108 , V_137 ) ;
}
}
static void F_46 ( struct V_30 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 )
F_42 ( V_14 -> V_138 . V_139 -> V_140 -> V_105 ,
V_13 -> V_123 , V_13 -> V_128 ,
( ( V_13 -> V_18 & V_129 )
? V_130 : V_131 ) ) ;
}
static void F_47 ( void * V_17 )
{
struct V_30 * V_14 = V_17 ;
struct V_12 * V_13 = V_14 -> V_13 ;
F_27 ( & V_14 -> V_104 -> V_105 , L_59 ) ;
if ( V_14 -> V_44 . V_49 )
F_28 ( V_14 , V_51 , F_48 ( V_14 , V_51 ) & ~ V_52 ) ;
F_46 ( V_14 ) ;
if ( V_13 ) {
F_44 ( V_14 , V_135 ) ;
F_45 ( & V_14 -> V_136 ) ;
F_28 ( V_14 , V_108 , V_137 ) ;
}
}
static T_1 F_49 ( struct V_30 * V_14 , struct V_12 * V_13 )
{
T_1 V_141 ;
V_13 -> error = - V_84 ;
V_14 -> V_123 = V_13 -> V_123 ;
V_14 -> V_13 = V_13 ;
V_14 -> V_142 = NULL ;
V_141 = V_143 ;
if ( V_13 -> V_21 * V_13 -> V_22 < 12
|| ( V_13 -> V_21 * V_13 -> V_22 ) & 3 )
V_14 -> V_144 = true ;
V_14 -> V_145 = 0 ;
if ( V_13 -> V_18 & V_101 )
V_141 |= V_146 ;
else
V_141 |= V_147 ;
return V_141 ;
}
static T_1
F_50 ( struct V_30 * V_14 , struct V_12 * V_13 )
{
T_1 V_141 , V_148 ;
unsigned int V_128 ;
enum V_149 V_111 ;
V_13 -> error = - V_84 ;
V_14 -> V_13 = V_13 ;
V_14 -> V_123 = V_13 -> V_123 ;
V_141 = V_143 ;
F_28 ( V_14 , V_37 , V_14 -> V_125 | V_150 ) ;
if ( V_13 -> V_18 & V_101 ) {
V_111 = V_131 ;
V_141 |= V_151 | V_152 ;
} else {
V_111 = V_130 ;
V_141 |= V_153 | V_154 ;
}
V_148 = F_48 ( V_14 , V_37 ) ;
V_148 &= 0x0000ffff ;
V_148 |= F_51 ( V_13 -> V_22 ) ;
F_28 ( V_14 , V_37 , V_148 ) ;
V_14 -> V_124 = V_13 -> V_21 * V_13 -> V_22 ;
V_128 = F_52 ( & V_14 -> V_104 -> V_105 , V_13 -> V_123 , V_13 -> V_128 , V_111 ) ;
if ( V_14 -> V_124 )
F_40 ( V_14 ,
( ( V_111 == V_131 ) ? V_116 : V_155 ) ) ;
return V_141 ;
}
static T_1
F_53 ( struct V_30 * V_14 , struct V_12 * V_13 )
{
struct V_156 * V_139 ;
struct V_157 * V_158 ;
struct V_159 * V_123 ;
unsigned int V_29 ;
enum V_149 V_160 ;
enum V_161 V_162 ;
unsigned int V_163 ;
T_1 V_141 ;
V_13 -> error = - V_84 ;
F_34 ( V_14 -> V_13 ) ;
V_14 -> V_123 = NULL ;
V_14 -> V_13 = V_13 ;
V_141 = V_143 ;
if ( V_13 -> V_21 * V_13 -> V_22 < V_164 )
return F_49 ( V_14 , V_13 ) ;
if ( V_13 -> V_22 & 3 )
return F_49 ( V_14 , V_13 ) ;
F_54 (data->sg, sg, data->sg_len, i) {
if ( V_123 -> V_165 & 3 || V_123 -> V_166 & 3 )
return F_49 ( V_14 , V_13 ) ;
}
V_139 = V_14 -> V_138 . V_139 ;
if ( V_139 )
V_14 -> V_142 = V_139 ;
if ( ! V_139 )
return - V_167 ;
if ( V_14 -> V_44 . V_49 )
F_28 ( V_14 , V_51 , F_55 ( 3 ) | V_52 ) ;
if ( V_13 -> V_18 & V_101 ) {
V_160 = V_131 ;
V_14 -> V_168 . V_160 = V_162 = V_169 ;
} else {
V_160 = V_130 ;
V_14 -> V_168 . V_160 = V_162 = V_170 ;
}
V_163 = F_52 ( V_139 -> V_140 -> V_105 , V_13 -> V_123 ,
V_13 -> V_128 , V_160 ) ;
F_56 ( V_139 , & V_14 -> V_168 ) ;
V_158 = F_57 ( V_139 ,
V_13 -> V_123 , V_163 , V_162 ,
V_171 | V_172 ) ;
if ( ! V_158 )
goto V_173;
V_14 -> V_138 . V_174 = V_158 ;
V_158 -> V_175 = F_47 ;
V_158 -> V_176 = V_14 ;
return V_141 ;
V_173:
F_42 ( V_139 -> V_140 -> V_105 , V_13 -> V_123 , V_13 -> V_128 , V_160 ) ;
return - V_34 ;
}
static void
F_58 ( struct V_30 * V_14 , struct V_12 * V_13 )
{
return;
}
static void
F_59 ( struct V_30 * V_14 , struct V_12 * V_13 )
{
if ( V_13 -> V_18 & V_101 )
F_28 ( V_14 , V_132 , V_177 ) ;
else
F_28 ( V_14 , V_132 , V_178 ) ;
}
static void
F_60 ( struct V_30 * V_14 , struct V_12 * V_13 )
{
struct V_156 * V_139 = V_14 -> V_142 ;
struct V_157 * V_158 = V_14 -> V_138 . V_174 ;
if ( V_139 ) {
F_61 ( V_158 ) ;
F_62 ( V_139 ) ;
}
}
static void F_63 ( struct V_30 * V_14 )
{
F_44 ( V_14 , V_135 ) ;
F_28 ( V_14 , V_108 , V_137 ) ;
}
static void F_64 ( struct V_30 * V_14 )
{
F_44 ( V_14 , V_135 ) ;
F_28 ( V_14 , V_108 , V_137 ) ;
}
static void F_65 ( struct V_30 * V_14 )
{
struct V_156 * V_139 = V_14 -> V_142 ;
if ( V_139 ) {
F_66 ( V_139 ) ;
F_46 ( V_14 ) ;
} else {
F_44 ( V_14 , V_135 ) ;
F_28 ( V_14 , V_108 , V_137 ) ;
}
}
static void F_67 ( struct V_30 * V_14 ,
struct V_4 * V_5 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
T_1 V_141 ;
T_1 V_179 ;
V_8 = V_5 -> V_8 ;
V_14 -> V_180 = V_5 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_70 = 0 ;
V_14 -> V_71 = 0 ;
V_14 -> V_181 = 0 ;
if ( V_14 -> V_144 ) {
V_141 = F_48 ( V_14 , V_48 ) ;
V_141 &= ( V_182 | V_183 ) ;
F_28 ( V_14 , V_184 , V_185 ) ;
F_28 ( V_14 , V_184 , V_186 ) ;
F_28 ( V_14 , V_37 , V_14 -> V_125 ) ;
if ( V_14 -> V_44 . V_53 )
F_28 ( V_14 , V_54 , V_14 -> V_187 ) ;
F_28 ( V_14 , V_108 , V_141 ) ;
V_14 -> V_144 = false ;
}
F_28 ( V_14 , V_41 , V_5 -> V_188 ) ;
V_141 = F_48 ( V_14 , V_48 ) ;
if ( V_141 & ~ ( V_182 | V_183 ) )
F_68 ( & V_5 -> V_60 -> V_72 , L_60 ,
V_141 ) ;
if ( F_69 ( F_70 ( V_189 , & V_5 -> V_18 ) ) ) {
F_28 ( V_14 , V_106 , V_190 ) ;
while ( ! ( F_48 ( V_14 , V_47 ) & V_109 ) )
F_71 () ;
}
V_141 = 0 ;
V_13 = V_8 -> V_13 ;
if ( V_13 ) {
F_26 ( V_14 , V_5 , V_13 ) ;
F_28 ( V_14 , V_43 , F_72 ( V_13 -> V_21 )
| F_51 ( V_13 -> V_22 ) ) ;
F_27 ( & V_5 -> V_60 -> V_72 , L_61 ,
F_72 ( V_13 -> V_21 ) | F_51 ( V_13 -> V_22 ) ) ;
V_141 |= V_14 -> V_191 ( V_14 , V_13 ) ;
}
V_141 |= V_109 ;
V_10 = V_8 -> V_10 ;
V_179 = F_31 ( V_5 -> V_60 , V_10 ) ;
F_33 ( V_14 , V_10 , V_179 ) ;
if ( V_13 )
V_14 -> V_192 ( V_14 , V_13 ) ;
if ( V_8 -> V_11 ) {
V_14 -> V_107 = F_31 ( V_5 -> V_60 , V_8 -> V_11 ) ;
V_14 -> V_107 |= V_193 ;
if ( ! ( V_13 -> V_18 & V_129 ) )
V_14 -> V_107 |= V_102 ;
if ( V_13 -> V_18 & V_97 )
V_14 -> V_107 |= V_98 ;
else
V_14 -> V_107 |= V_99 ;
}
F_28 ( V_14 , V_108 , V_141 ) ;
}
static void F_73 ( struct V_30 * V_14 ,
struct V_4 * V_5 , struct V_7 * V_8 )
{
F_27 ( & V_5 -> V_60 -> V_72 , L_62 ,
V_14 -> V_69 ) ;
F_2 ( & V_14 -> V_15 ) ;
V_5 -> V_8 = V_8 ;
if ( V_14 -> V_69 == V_194 ) {
V_14 -> V_69 = V_195 ;
F_67 ( V_14 , V_5 ) ;
} else {
F_74 ( & V_5 -> V_196 , & V_14 -> V_197 ) ;
}
F_4 ( & V_14 -> V_15 ) ;
}
static void F_75 ( struct V_59 * V_60 , struct V_7 * V_8 )
{
struct V_4 * V_5 = F_76 ( V_60 ) ;
struct V_30 * V_14 = V_5 -> V_14 ;
struct V_12 * V_13 ;
F_34 ( V_5 -> V_8 ) ;
if ( ! F_77 ( V_198 , & V_5 -> V_18 ) ) {
V_8 -> V_10 -> error = - V_199 ;
F_78 ( V_60 , V_8 ) ;
return;
}
V_13 = V_8 -> V_13 ;
if ( V_13 && V_13 -> V_21 > 1 && V_13 -> V_22 & 3 ) {
V_8 -> V_10 -> error = - V_200 ;
F_78 ( V_60 , V_8 ) ;
}
F_73 ( V_14 , V_5 , V_8 ) ;
}
static void F_79 ( struct V_59 * V_60 , struct V_201 * V_90 )
{
struct V_4 * V_5 = F_76 ( V_60 ) ;
struct V_30 * V_14 = V_5 -> V_14 ;
unsigned int V_29 ;
V_5 -> V_188 &= ~ V_202 ;
switch ( V_90 -> V_203 ) {
case V_204 :
V_5 -> V_188 |= V_205 ;
break;
case V_206 :
V_5 -> V_188 |= V_207 ;
break;
}
if ( V_90 -> clock ) {
unsigned int V_208 = ~ 0U ;
T_1 V_209 ;
F_2 ( & V_14 -> V_15 ) ;
if ( ! V_14 -> V_125 ) {
F_13 ( V_14 -> V_35 ) ;
F_28 ( V_14 , V_184 , V_185 ) ;
F_28 ( V_14 , V_184 , V_186 ) ;
if ( V_14 -> V_44 . V_53 )
F_28 ( V_14 , V_54 , V_14 -> V_187 ) ;
}
V_5 -> clock = V_90 -> clock ;
for ( V_29 = 0 ; V_29 < V_210 ; V_29 ++ ) {
if ( V_14 -> V_5 [ V_29 ] && V_14 -> V_5 [ V_29 ] -> clock
&& V_14 -> V_5 [ V_29 ] -> clock < V_208 )
V_208 = V_14 -> V_5 [ V_29 ] -> clock ;
}
if ( V_14 -> V_44 . V_211 ) {
V_209 = F_25 ( V_14 -> V_75 , V_208 ) - 2 ;
if ( V_209 > 511 ) {
F_68 ( & V_60 -> V_72 ,
L_63 ,
V_208 , V_14 -> V_75 / ( 511 + 2 ) ) ;
V_209 = 511 ;
}
V_14 -> V_125 = F_80 ( V_209 >> 1 )
| F_81 ( V_209 & 1 ) ;
} else {
V_209 = F_25 ( V_14 -> V_75 , 2 * V_208 ) - 1 ;
if ( V_209 > 255 ) {
F_68 ( & V_60 -> V_72 ,
L_63 ,
V_208 , V_14 -> V_75 / ( 2 * 256 ) ) ;
V_209 = 255 ;
}
V_14 -> V_125 = F_80 ( V_209 ) ;
}
if ( V_14 -> V_44 . V_212 )
V_14 -> V_125 |= ( V_39 | V_38 ) ;
if ( V_14 -> V_44 . V_53 ) {
if ( V_90 -> V_213 == V_214 )
V_14 -> V_187 |= V_57 ;
else
V_14 -> V_187 &= ~ V_57 ;
}
if ( F_82 ( & V_14 -> V_197 ) ) {
F_28 ( V_14 , V_37 , V_14 -> V_125 ) ;
if ( V_14 -> V_44 . V_53 )
F_28 ( V_14 , V_54 , V_14 -> V_187 ) ;
} else {
V_14 -> V_215 = true ;
}
F_4 ( & V_14 -> V_15 ) ;
} else {
bool V_216 = false ;
F_2 ( & V_14 -> V_15 ) ;
V_5 -> clock = 0 ;
for ( V_29 = 0 ; V_29 < V_210 ; V_29 ++ ) {
if ( V_14 -> V_5 [ V_29 ] && V_14 -> V_5 [ V_29 ] -> clock ) {
V_216 = true ;
break;
}
}
if ( ! V_216 ) {
F_28 ( V_14 , V_184 , V_217 ) ;
if ( V_14 -> V_125 ) {
F_48 ( V_14 , V_37 ) ;
F_15 ( V_14 -> V_35 ) ;
}
V_14 -> V_125 = 0 ;
}
F_4 ( & V_14 -> V_15 ) ;
}
switch ( V_90 -> V_218 ) {
case V_219 :
F_83 ( V_189 , & V_5 -> V_18 ) ;
break;
default:
break;
}
}
static int F_84 ( struct V_59 * V_60 )
{
int V_220 = - V_221 ;
struct V_4 * V_5 = F_76 ( V_60 ) ;
if ( F_85 ( V_5 -> V_222 ) ) {
V_220 = F_86 ( V_5 -> V_222 ) ;
F_87 ( & V_60 -> V_72 , L_64 ,
V_220 ? L_65 : L_66 ) ;
}
return V_220 ;
}
static int F_88 ( struct V_59 * V_60 )
{
int V_223 = - V_221 ;
struct V_4 * V_5 = F_76 ( V_60 ) ;
if ( F_85 ( V_5 -> V_224 ) ) {
V_223 = ! ( F_86 ( V_5 -> V_224 ) ^
V_5 -> V_225 ) ;
F_87 ( & V_60 -> V_72 , L_67 ,
V_223 ? L_35 : L_68 ) ;
}
return V_223 ;
}
static void F_89 ( struct V_59 * V_60 , int V_226 )
{
struct V_4 * V_5 = F_76 ( V_60 ) ;
struct V_30 * V_14 = V_5 -> V_14 ;
if ( V_226 )
F_28 ( V_14 , V_108 , V_5 -> V_227 ) ;
else
F_28 ( V_14 , V_228 , V_5 -> V_227 ) ;
}
static void F_90 ( struct V_30 * V_14 , struct V_7 * V_8 )
__releases( &host->lock
static void F_91 ( struct V_30 * V_14 ,
struct V_9 * V_10 )
{
T_1 V_229 = V_14 -> V_230 ;
V_10 -> V_19 [ 0 ] = F_48 ( V_14 , V_231 ) ;
V_10 -> V_19 [ 1 ] = F_48 ( V_14 , V_231 ) ;
V_10 -> V_19 [ 2 ] = F_48 ( V_14 , V_231 ) ;
V_10 -> V_19 [ 3 ] = F_48 ( V_14 , V_231 ) ;
if ( V_229 & V_232 )
V_10 -> error = - V_233 ;
else if ( ( V_10 -> V_18 & V_234 ) && ( V_229 & V_235 ) )
V_10 -> error = - V_236 ;
else if ( V_229 & ( V_237 | V_238 | V_239 ) )
V_10 -> error = - V_240 ;
else
V_10 -> error = 0 ;
if ( V_10 -> error ) {
F_87 ( & V_14 -> V_104 -> V_105 ,
L_69 , V_229 ) ;
if ( V_10 -> V_13 ) {
V_14 -> V_241 ( V_14 ) ;
V_14 -> V_13 = NULL ;
F_28 ( V_14 , V_228 , V_137
| V_147 | V_146
| V_143 ) ;
}
}
}
static void F_92 ( unsigned long V_13 )
{
struct V_4 * V_5 = (struct V_4 * ) V_13 ;
bool V_223 ;
bool V_242 ;
F_93 () ;
if ( F_77 ( V_243 , & V_5 -> V_18 ) )
return;
F_94 ( F_95 ( V_5 -> V_224 ) ) ;
V_223 = ! ( F_86 ( V_5 -> V_224 ) ^
V_5 -> V_225 ) ;
V_242 = F_77 ( V_198 , & V_5 -> V_18 ) ;
F_27 ( & V_5 -> V_60 -> V_72 , L_70 ,
V_223 , V_242 ) ;
if ( V_223 != V_242 ) {
struct V_30 * V_14 = V_5 -> V_14 ;
struct V_7 * V_8 ;
F_87 ( & V_5 -> V_60 -> V_72 , L_71 ,
V_223 ? L_72 : L_73 ) ;
F_96 ( & V_14 -> V_15 ) ;
if ( ! V_223 )
F_97 ( V_198 , & V_5 -> V_18 ) ;
else
F_83 ( V_198 , & V_5 -> V_18 ) ;
V_8 = V_5 -> V_8 ;
if ( V_8 ) {
if ( V_8 == V_14 -> V_8 ) {
F_28 ( V_14 , V_184 , V_185 ) ;
F_28 ( V_14 , V_184 , V_186 ) ;
F_28 ( V_14 , V_37 , V_14 -> V_125 ) ;
if ( V_14 -> V_44 . V_53 )
F_28 ( V_14 , V_54 , V_14 -> V_187 ) ;
V_14 -> V_13 = NULL ;
V_14 -> V_10 = NULL ;
switch ( V_14 -> V_69 ) {
case V_194 :
break;
case V_195 :
V_8 -> V_10 -> error = - V_199 ;
if ( ! V_8 -> V_13 )
break;
case V_244 :
V_8 -> V_13 -> error = - V_199 ;
V_14 -> V_241 ( V_14 ) ;
break;
case V_245 :
case V_246 :
if ( V_8 -> V_13 -> error == - V_84 )
V_8 -> V_13 -> error = - V_199 ;
if ( ! V_8 -> V_11 )
break;
case V_247 :
V_8 -> V_11 -> error = - V_199 ;
break;
}
F_90 ( V_14 , V_8 ) ;
} else {
F_98 ( & V_5 -> V_196 ) ;
V_8 -> V_10 -> error = - V_199 ;
if ( V_8 -> V_13 )
V_8 -> V_13 -> error = - V_199 ;
if ( V_8 -> V_11 )
V_8 -> V_11 -> error = - V_199 ;
F_99 ( & V_14 -> V_15 ) ;
F_78 ( V_5 -> V_60 , V_8 ) ;
F_96 ( & V_14 -> V_15 ) ;
}
}
F_99 ( & V_14 -> V_15 ) ;
F_100 ( V_5 -> V_60 , 0 ) ;
}
}
static void F_101 ( unsigned long V_248 )
{
struct V_30 * V_14 = (struct V_30 * ) V_248 ;
struct V_7 * V_8 = V_14 -> V_8 ;
struct V_12 * V_13 = V_14 -> V_13 ;
struct V_9 * V_10 = V_14 -> V_10 ;
enum V_249 V_69 = V_14 -> V_69 ;
enum V_249 V_250 ;
T_1 V_229 ;
F_96 ( & V_14 -> V_15 ) ;
V_69 = V_14 -> V_69 ;
F_27 ( & V_14 -> V_104 -> V_105 ,
L_74 ,
V_69 , V_14 -> V_70 , V_14 -> V_71 ,
F_48 ( V_14 , V_48 ) ) ;
do {
V_250 = V_69 ;
switch ( V_69 ) {
case V_194 :
break;
case V_195 :
if ( ! F_102 ( V_14 ,
V_251 ) )
break;
V_14 -> V_10 = NULL ;
F_103 ( V_14 , V_251 ) ;
F_91 ( V_14 , V_8 -> V_10 ) ;
if ( ! V_8 -> V_13 || V_10 -> error ) {
F_90 ( V_14 , V_14 -> V_8 ) ;
goto V_252;
}
V_250 = V_69 = V_244 ;
case V_244 :
if ( F_102 ( V_14 ,
V_253 ) ) {
V_14 -> V_241 ( V_14 ) ;
if ( V_13 -> V_11 )
F_35 ( V_14 , V_13 ) ;
V_69 = V_246 ;
break;
}
if ( ! F_102 ( V_14 ,
V_135 ) )
break;
F_103 ( V_14 , V_135 ) ;
V_250 = V_69 = V_245 ;
case V_245 :
if ( ! F_102 ( V_14 ,
V_254 ) )
break;
V_14 -> V_13 = NULL ;
F_103 ( V_14 , V_254 ) ;
V_229 = V_14 -> V_181 ;
if ( F_69 ( V_229 & V_143 ) ) {
if ( V_229 & V_255 ) {
F_87 ( & V_14 -> V_104 -> V_105 ,
L_75 ) ;
V_13 -> error = - V_233 ;
} else if ( V_229 & V_256 ) {
F_87 ( & V_14 -> V_104 -> V_105 ,
L_76 ) ;
V_13 -> error = - V_236 ;
} else {
F_87 ( & V_14 -> V_104 -> V_105 ,
L_77 ,
V_229 ) ;
V_13 -> error = - V_240 ;
}
} else {
V_13 -> V_20 = V_13 -> V_21 * V_13 -> V_22 ;
V_13 -> error = 0 ;
F_28 ( V_14 , V_228 , V_143 ) ;
}
if ( ! V_13 -> V_11 ) {
F_90 ( V_14 , V_14 -> V_8 ) ;
goto V_252;
}
V_250 = V_69 = V_247 ;
if ( ! V_13 -> error )
F_35 ( V_14 , V_13 ) ;
case V_247 :
if ( ! F_102 ( V_14 ,
V_251 ) )
break;
V_14 -> V_10 = NULL ;
F_91 ( V_14 , V_8 -> V_11 ) ;
F_90 ( V_14 , V_14 -> V_8 ) ;
goto V_252;
case V_246 :
if ( ! F_102 ( V_14 ,
V_135 ) )
break;
V_69 = V_245 ;
break;
}
} while ( V_69 != V_250 );
V_14 -> V_69 = V_69 ;
V_252:
F_99 ( & V_14 -> V_15 ) ;
}
static void F_104 ( struct V_30 * V_14 )
{
struct V_159 * V_123 = V_14 -> V_123 ;
void * V_31 = F_105 ( V_123 ) ;
unsigned int V_165 = V_14 -> V_145 ;
struct V_12 * V_13 = V_14 -> V_13 ;
T_1 V_27 ;
T_1 V_229 ;
unsigned int V_257 = 0 ;
do {
V_27 = F_48 ( V_14 , V_258 ) ;
if ( F_106 ( V_165 + 4 <= V_123 -> V_166 ) ) {
F_107 ( V_27 , ( T_1 * ) ( V_31 + V_165 ) ) ;
V_165 += 4 ;
V_257 += 4 ;
if ( V_165 == V_123 -> V_166 ) {
F_108 ( F_109 ( V_123 ) ) ;
V_14 -> V_123 = V_123 = F_39 ( V_123 ) ;
if ( ! V_123 )
goto V_259;
V_165 = 0 ;
V_31 = F_105 ( V_123 ) ;
}
} else {
unsigned int V_260 = V_123 -> V_166 - V_165 ;
memcpy ( V_31 + V_165 , & V_27 , V_260 ) ;
V_257 += V_260 ;
F_108 ( F_109 ( V_123 ) ) ;
V_14 -> V_123 = V_123 = F_39 ( V_123 ) ;
if ( ! V_123 )
goto V_259;
V_165 = 4 - V_260 ;
V_31 = F_105 ( V_123 ) ;
memcpy ( V_31 , ( V_261 * ) & V_27 + V_260 , V_165 ) ;
V_257 += V_165 ;
}
V_229 = F_48 ( V_14 , V_47 ) ;
if ( V_229 & V_143 ) {
F_28 ( V_14 , V_228 , ( V_137 | V_146
| V_143 ) ) ;
V_14 -> V_181 = V_229 ;
V_13 -> V_20 += V_257 ;
F_110 () ;
F_44 ( V_14 , V_253 ) ;
F_45 ( & V_14 -> V_136 ) ;
return;
}
} while ( V_229 & V_146 );
V_14 -> V_145 = V_165 ;
V_13 -> V_20 += V_257 ;
return;
V_259:
F_28 ( V_14 , V_228 , V_146 ) ;
F_28 ( V_14 , V_108 , V_137 ) ;
V_13 -> V_20 += V_257 ;
F_110 () ;
F_44 ( V_14 , V_135 ) ;
}
static void F_111 ( struct V_30 * V_14 )
{
struct V_159 * V_123 = V_14 -> V_123 ;
void * V_31 = F_105 ( V_123 ) ;
unsigned int V_165 = V_14 -> V_145 ;
struct V_12 * V_13 = V_14 -> V_13 ;
T_1 V_27 ;
T_1 V_229 ;
unsigned int V_257 = 0 ;
do {
if ( F_106 ( V_165 + 4 <= V_123 -> V_166 ) ) {
V_27 = F_112 ( ( T_1 * ) ( V_31 + V_165 ) ) ;
F_28 ( V_14 , V_262 , V_27 ) ;
V_165 += 4 ;
V_257 += 4 ;
if ( V_165 == V_123 -> V_166 ) {
V_14 -> V_123 = V_123 = F_39 ( V_123 ) ;
if ( ! V_123 )
goto V_259;
V_165 = 0 ;
V_31 = F_105 ( V_123 ) ;
}
} else {
unsigned int V_260 = V_123 -> V_166 - V_165 ;
V_27 = 0 ;
memcpy ( & V_27 , V_31 + V_165 , V_260 ) ;
V_257 += V_260 ;
V_14 -> V_123 = V_123 = F_39 ( V_123 ) ;
if ( ! V_123 ) {
F_28 ( V_14 , V_262 , V_27 ) ;
goto V_259;
}
V_165 = 4 - V_260 ;
V_31 = F_105 ( V_123 ) ;
memcpy ( ( V_261 * ) & V_27 + V_260 , V_31 , V_165 ) ;
F_28 ( V_14 , V_262 , V_27 ) ;
V_257 += V_165 ;
}
V_229 = F_48 ( V_14 , V_47 ) ;
if ( V_229 & V_143 ) {
F_28 ( V_14 , V_228 , ( V_137 | V_147
| V_143 ) ) ;
V_14 -> V_181 = V_229 ;
V_13 -> V_20 += V_257 ;
F_110 () ;
F_44 ( V_14 , V_253 ) ;
F_45 ( & V_14 -> V_136 ) ;
return;
}
} while ( V_229 & V_147 );
V_14 -> V_145 = V_165 ;
V_13 -> V_20 += V_257 ;
return;
V_259:
F_28 ( V_14 , V_228 , V_147 ) ;
F_28 ( V_14 , V_108 , V_137 ) ;
V_13 -> V_20 += V_257 ;
F_110 () ;
F_44 ( V_14 , V_135 ) ;
}
static void F_113 ( struct V_30 * V_14 , T_1 V_229 )
{
F_28 ( V_14 , V_228 , V_109 ) ;
V_14 -> V_230 = V_229 ;
F_110 () ;
F_44 ( V_14 , V_251 ) ;
F_45 ( & V_14 -> V_136 ) ;
}
static void F_114 ( struct V_30 * V_14 , T_1 V_229 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_210 ; V_29 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_29 ] ;
if ( V_5 && ( V_229 & V_5 -> V_227 ) ) {
F_115 ( V_5 -> V_60 ) ;
}
}
}
static T_2 F_116 ( int V_263 , void * V_264 )
{
struct V_30 * V_14 = V_264 ;
T_1 V_229 , V_265 , V_266 ;
unsigned int V_267 = 0 ;
do {
V_229 = F_48 ( V_14 , V_47 ) ;
V_265 = F_48 ( V_14 , V_48 ) ;
V_266 = V_229 & V_265 ;
if ( ! V_266 )
break;
if ( V_266 & V_143 ) {
F_28 ( V_14 , V_228 , V_143
| V_146 | V_147 ) ;
V_266 &= F_48 ( V_14 , V_48 ) ;
V_14 -> V_181 = V_229 ;
F_110 () ;
F_44 ( V_14 , V_253 ) ;
F_45 ( & V_14 -> V_136 ) ;
}
if ( V_266 & V_154 ) {
F_28 ( V_14 , V_228 , V_154 ) ;
F_28 ( V_14 , V_228 , V_153 ) ;
if ( V_14 -> V_124 ) {
F_40 ( V_14 , V_155 ) ;
F_28 ( V_14 , V_108 , V_153 ) ;
F_28 ( V_14 , V_108 , V_154 ) ;
} else {
F_43 ( V_14 ) ;
}
} else if ( V_266 & V_153 ) {
F_28 ( V_14 , V_228 , V_153 ) ;
if ( V_14 -> V_124 ) {
F_36 ( V_14 ,
V_155 , V_121 ) ;
F_28 ( V_14 , V_108 , V_153 ) ;
}
}
if ( V_266 & V_152 ) {
F_28 ( V_14 , V_228 , V_152 ) ;
F_28 ( V_14 , V_228 , V_151 ) ;
if ( V_14 -> V_124 ) {
F_40 ( V_14 , V_116 ) ;
F_28 ( V_14 , V_108 , V_151 ) ;
F_28 ( V_14 , V_108 , V_152 ) ;
} else {
F_43 ( V_14 ) ;
}
} else if ( V_266 & V_151 ) {
F_28 ( V_14 , V_228 , V_151 ) ;
if ( V_14 -> V_124 ) {
F_36 ( V_14 ,
V_116 , V_121 ) ;
F_28 ( V_14 , V_108 , V_151 ) ;
}
}
if ( V_266 & V_137 ) {
F_28 ( V_14 , V_228 ,
V_143 | V_137 ) ;
if ( ! V_14 -> V_181 )
V_14 -> V_181 = V_229 ;
F_110 () ;
F_44 ( V_14 , V_254 ) ;
F_45 ( & V_14 -> V_136 ) ;
}
if ( V_266 & V_146 )
F_104 ( V_14 ) ;
if ( V_266 & V_147 )
F_111 ( V_14 ) ;
if ( V_266 & V_109 )
F_113 ( V_14 , V_229 ) ;
if ( V_266 & ( V_182 | V_183 ) )
F_114 ( V_14 , V_229 ) ;
} while ( V_267 ++ < 5 );
return V_267 ? V_268 : V_269 ;
}
static T_2 F_117 ( int V_263 , void * V_264 )
{
struct V_4 * V_5 = V_264 ;
F_118 ( V_263 ) ;
F_119 ( & V_5 -> V_270 , V_271 + F_120 ( 20 ) ) ;
return V_268 ;
}
static int T_3 F_121 ( struct V_30 * V_14 ,
struct V_272 * V_273 , unsigned int V_274 ,
T_1 V_188 , T_1 V_227 )
{
struct V_59 * V_60 ;
struct V_4 * V_5 ;
V_60 = F_122 ( sizeof( struct V_4 ) , & V_14 -> V_104 -> V_105 ) ;
if ( ! V_60 )
return - V_34 ;
V_5 = F_76 ( V_60 ) ;
V_5 -> V_60 = V_60 ;
V_5 -> V_14 = V_14 ;
V_5 -> V_224 = V_273 -> V_224 ;
V_5 -> V_222 = V_273 -> V_222 ;
V_5 -> V_225 = V_273 -> V_225 ;
V_5 -> V_188 = V_188 ;
V_5 -> V_227 = V_227 ;
V_60 -> V_275 = & V_276 ;
V_60 -> V_277 = F_25 ( V_14 -> V_75 , 512 ) ;
V_60 -> V_278 = V_14 -> V_75 / 2 ;
V_60 -> V_279 = V_280 | V_281 ;
if ( V_227 )
V_60 -> V_44 |= V_282 ;
if ( V_14 -> V_44 . V_283 )
V_60 -> V_44 |= V_284 ;
if ( V_273 -> V_203 >= 4 )
V_60 -> V_44 |= V_285 ;
V_60 -> V_286 = 64 ;
V_60 -> V_287 = 32768 * 512 ;
V_60 -> V_288 = 32768 ;
V_60 -> V_289 = 512 ;
F_83 ( V_198 , & V_5 -> V_18 ) ;
if ( F_85 ( V_5 -> V_224 ) ) {
if ( F_123 ( V_5 -> V_224 , L_78 ) ) {
F_87 ( & V_60 -> V_72 , L_79 ) ;
V_5 -> V_224 = - V_290 ;
} else if ( F_86 ( V_5 -> V_224 ) ^
V_5 -> V_225 ) {
F_97 ( V_198 , & V_5 -> V_18 ) ;
}
}
if ( ! F_85 ( V_5 -> V_224 ) )
V_60 -> V_44 |= V_291 ;
if ( F_85 ( V_5 -> V_222 ) ) {
if ( F_123 ( V_5 -> V_222 , L_80 ) ) {
F_87 ( & V_60 -> V_72 , L_81 ) ;
V_5 -> V_222 = - V_290 ;
}
}
V_14 -> V_5 [ V_274 ] = V_5 ;
F_124 ( V_60 ) ;
if ( F_85 ( V_5 -> V_224 ) ) {
int V_292 ;
F_125 ( & V_5 -> V_270 , F_92 ,
( unsigned long ) V_5 ) ;
V_292 = F_126 ( F_95 ( V_5 -> V_224 ) ,
F_117 ,
V_293 | V_294 ,
L_82 , V_5 ) ;
if ( V_292 ) {
F_87 ( & V_60 -> V_72 ,
L_83 ,
F_95 ( V_5 -> V_224 ) ) ;
F_127 ( V_5 -> V_224 ) ;
V_5 -> V_224 = - V_290 ;
}
}
F_18 ( V_5 ) ;
return 0 ;
}
static void T_4 F_128 ( struct V_4 * V_5 ,
unsigned int V_274 )
{
F_83 ( V_243 , & V_5 -> V_18 ) ;
F_110 () ;
F_129 ( V_5 -> V_60 ) ;
if ( F_85 ( V_5 -> V_224 ) ) {
int V_295 = V_5 -> V_224 ;
F_130 ( F_95 ( V_295 ) , V_5 ) ;
F_131 ( & V_5 -> V_270 ) ;
F_127 ( V_295 ) ;
}
if ( F_85 ( V_5 -> V_222 ) )
F_127 ( V_5 -> V_222 ) ;
V_5 -> V_14 -> V_5 [ V_274 ] = NULL ;
F_132 ( V_5 -> V_60 ) ;
}
static bool F_133 ( struct V_156 * V_139 , void * V_296 )
{
struct V_297 * V_298 = V_296 ;
if ( V_298 && F_134 ( V_298 ) == V_139 -> V_140 -> V_105 ) {
V_139 -> V_6 = F_135 ( V_298 ) ;
return true ;
} else {
return false ;
}
}
static bool F_136 ( struct V_30 * V_14 )
{
struct V_299 * V_300 ;
if ( V_14 == NULL )
return false ;
V_300 = V_14 -> V_104 -> V_105 . V_301 ;
if ( V_300 && F_134 ( V_300 -> V_302 ) ) {
T_5 V_265 ;
F_137 ( V_265 ) ;
F_138 ( V_303 , V_265 ) ;
V_14 -> V_138 . V_139 =
F_139 ( V_265 , F_133 , V_300 -> V_302 ) ;
}
if ( ! V_14 -> V_138 . V_139 ) {
F_68 ( & V_14 -> V_104 -> V_105 , L_84 ) ;
return false ;
} else {
F_140 ( & V_14 -> V_104 -> V_105 ,
L_85 ,
F_141 ( V_14 -> V_138 . V_139 ) ) ;
V_14 -> V_168 . V_304 = V_14 -> V_305 + V_258 ;
V_14 -> V_168 . V_306 = V_307 ;
V_14 -> V_168 . V_308 = 1 ;
V_14 -> V_168 . V_309 = V_14 -> V_305 + V_262 ;
V_14 -> V_168 . V_310 = V_307 ;
V_14 -> V_168 . V_311 = 1 ;
V_14 -> V_168 . V_312 = false ;
return true ;
}
}
static inline unsigned int F_142 ( struct V_30 * V_14 )
{
return F_48 ( V_14 , V_313 ) & 0x00000fff ;
}
static void T_3 F_143 ( struct V_30 * V_14 )
{
unsigned int V_314 ;
V_314 = F_142 ( V_14 ) ;
F_140 ( & V_14 -> V_104 -> V_105 ,
L_86 , V_314 ) ;
V_14 -> V_44 . V_49 = 0 ;
V_14 -> V_44 . V_315 = 1 ;
V_14 -> V_44 . V_53 = 0 ;
V_14 -> V_44 . V_45 = 0 ;
V_14 -> V_44 . V_283 = 0 ;
V_14 -> V_44 . V_212 = 0 ;
V_14 -> V_44 . V_211 = 0 ;
switch ( V_314 & 0xf00 ) {
case 0x500 :
V_14 -> V_44 . V_211 = 1 ;
case 0x400 :
case 0x300 :
#ifdef F_144
V_14 -> V_44 . V_49 = 1 ;
#else
F_140 ( & V_14 -> V_104 -> V_105 ,
L_87 ) ;
#endif
V_14 -> V_44 . V_315 = 0 ;
V_14 -> V_44 . V_53 = 1 ;
V_14 -> V_44 . V_45 = 1 ;
V_14 -> V_44 . V_283 = 1 ;
case 0x200 :
V_14 -> V_44 . V_212 = 1 ;
case 0x100 :
break;
default:
V_14 -> V_44 . V_315 = 0 ;
F_68 ( & V_14 -> V_104 -> V_105 ,
L_88 ) ;
break;
}
}
static int T_3 F_145 ( struct V_316 * V_104 )
{
struct V_299 * V_300 ;
struct V_30 * V_14 ;
struct V_317 * V_36 ;
unsigned int V_318 ;
int V_263 ;
int V_292 ;
V_36 = F_146 ( V_104 , V_319 , 0 ) ;
if ( ! V_36 )
return - V_320 ;
V_300 = V_104 -> V_105 . V_301 ;
if ( ! V_300 )
return - V_320 ;
V_263 = F_147 ( V_104 , 0 ) ;
if ( V_263 < 0 )
return V_263 ;
V_14 = F_148 ( sizeof( struct V_30 ) , V_33 ) ;
if ( ! V_14 )
return - V_34 ;
V_14 -> V_104 = V_104 ;
F_149 ( & V_14 -> V_15 ) ;
F_150 ( & V_14 -> V_197 ) ;
V_14 -> V_35 = F_151 ( & V_104 -> V_105 , L_89 ) ;
if ( F_20 ( V_14 -> V_35 ) ) {
V_292 = F_152 ( V_14 -> V_35 ) ;
goto V_321;
}
V_292 = - V_34 ;
V_14 -> V_36 = F_153 ( V_36 -> V_322 , F_154 ( V_36 ) ) ;
if ( ! V_14 -> V_36 )
goto V_323;
F_13 ( V_14 -> V_35 ) ;
F_28 ( V_14 , V_184 , V_185 ) ;
V_14 -> V_75 = F_155 ( V_14 -> V_35 ) ;
F_15 ( V_14 -> V_35 ) ;
V_14 -> V_305 = V_36 -> V_322 ;
F_156 ( & V_14 -> V_136 , F_101 , ( unsigned long ) V_14 ) ;
V_292 = F_126 ( V_263 , F_116 , 0 , F_157 ( & V_104 -> V_105 ) , V_14 ) ;
if ( V_292 )
goto V_324;
F_143 ( V_14 ) ;
if ( V_14 -> V_44 . V_49 && F_136 ( V_14 ) ) {
V_14 -> V_191 = & F_53 ;
V_14 -> V_192 = & F_60 ;
V_14 -> V_241 = & F_65 ;
} else if ( V_14 -> V_44 . V_315 ) {
F_140 ( & V_104 -> V_105 , L_90 ) ;
V_14 -> V_191 = & F_50 ;
V_14 -> V_192 = & F_59 ;
V_14 -> V_241 = & F_64 ;
} else {
F_140 ( & V_104 -> V_105 , L_91 ) ;
V_14 -> V_191 = & F_49 ;
V_14 -> V_192 = & F_58 ;
V_14 -> V_241 = & F_63 ;
}
F_158 ( V_104 , V_14 ) ;
V_318 = 0 ;
V_292 = - V_167 ;
if ( V_300 -> V_5 [ 0 ] . V_203 ) {
V_292 = F_121 ( V_14 , & V_300 -> V_5 [ 0 ] ,
0 , V_325 , V_182 ) ;
if ( ! V_292 )
V_318 ++ ;
}
if ( V_300 -> V_5 [ 1 ] . V_203 ) {
V_292 = F_121 ( V_14 , & V_300 -> V_5 [ 1 ] ,
1 , V_326 , V_183 ) ;
if ( ! V_292 )
V_318 ++ ;
}
if ( ! V_318 ) {
F_23 ( & V_104 -> V_105 , L_92 ) ;
goto V_327;
}
F_140 ( & V_104 -> V_105 ,
L_93 ,
V_14 -> V_305 , V_263 , V_318 ) ;
return 0 ;
V_327:
if ( V_14 -> V_138 . V_139 )
F_159 ( V_14 -> V_138 . V_139 ) ;
F_130 ( V_263 , V_14 ) ;
V_324:
F_160 ( V_14 -> V_36 ) ;
V_323:
F_161 ( V_14 -> V_35 ) ;
V_321:
F_16 ( V_14 ) ;
return V_292 ;
}
static int T_4 F_162 ( struct V_316 * V_104 )
{
struct V_30 * V_14 = F_163 ( V_104 ) ;
unsigned int V_29 ;
F_158 ( V_104 , NULL ) ;
for ( V_29 = 0 ; V_29 < V_210 ; V_29 ++ ) {
if ( V_14 -> V_5 [ V_29 ] )
F_128 ( V_14 -> V_5 [ V_29 ] , V_29 ) ;
}
F_13 ( V_14 -> V_35 ) ;
F_28 ( V_14 , V_228 , ~ 0UL ) ;
F_28 ( V_14 , V_184 , V_217 ) ;
F_48 ( V_14 , V_47 ) ;
F_15 ( V_14 -> V_35 ) ;
#ifdef F_164
if ( V_14 -> V_138 . V_139 )
F_159 ( V_14 -> V_138 . V_139 ) ;
#endif
F_130 ( F_147 ( V_104 , 0 ) , V_14 ) ;
F_160 ( V_14 -> V_36 ) ;
F_161 ( V_14 -> V_35 ) ;
F_16 ( V_14 ) ;
return 0 ;
}
static int F_165 ( struct V_140 * V_105 )
{
struct V_30 * V_14 = F_166 ( V_105 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_210 ; V_29 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_29 ] ;
int V_292 ;
if ( ! V_5 )
continue;
V_292 = F_167 ( V_5 -> V_60 ) ;
if ( V_292 < 0 ) {
while ( -- V_29 >= 0 ) {
V_5 = V_14 -> V_5 [ V_29 ] ;
if ( V_5
&& F_77 ( V_328 , & V_5 -> V_18 ) ) {
F_168 ( V_14 -> V_5 [ V_29 ] -> V_60 ) ;
F_97 ( V_328 , & V_5 -> V_18 ) ;
}
}
return V_292 ;
} else {
F_83 ( V_328 , & V_5 -> V_18 ) ;
}
}
return 0 ;
}
static int F_169 ( struct V_140 * V_105 )
{
struct V_30 * V_14 = F_166 ( V_105 ) ;
int V_29 ;
int V_292 = 0 ;
for ( V_29 = 0 ; V_29 < V_210 ; V_29 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_29 ] ;
int V_67 ;
V_5 = V_14 -> V_5 [ V_29 ] ;
if ( ! V_5 )
continue;
if ( ! F_77 ( V_328 , & V_5 -> V_18 ) )
continue;
V_67 = F_168 ( V_5 -> V_60 ) ;
if ( V_67 < 0 )
V_292 = V_67 ;
else
F_97 ( V_328 , & V_5 -> V_18 ) ;
}
return V_292 ;
}
static int T_3 F_170 ( void )
{
return F_171 ( & V_329 , F_145 ) ;
}
static void T_4 F_172 ( void )
{
F_173 ( & V_329 ) ;
}
