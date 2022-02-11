static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 ;
F_2 ( V_3 , V_7 , & V_6 ) ;
V_6 &= V_8 ;
F_3 ( & V_5 -> V_9 , L_1 ,
V_6 ? L_2 : L_3 ) ;
V_2 -> V_10 = V_6 ? true : false ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_3 ( & V_5 -> V_9 , L_4 ) ;
if ( ! V_2 -> V_10 ) {
F_5 ( V_3 , V_11 , V_12 , 0 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , char V_13 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 * V_17 , V_18 , V_19 , V_20 ;
switch ( V_13 ) {
case 'U' :
V_17 = & V_15 -> V_21 ;
V_18 = V_22 ;
V_20 = V_23 ;
break;
case 'Q' :
V_17 = & V_15 -> V_24 ;
V_18 = V_25 ;
V_20 = V_26 ;
break;
default:
F_7 ( & V_5 -> V_9 , L_5 ) ;
return;
}
F_3 ( & V_5 -> V_9 , L_6 , V_13 ) ;
if ( * V_17 >= V_18 * 2 ) {
* V_17 = 0 ;
} else if ( F_8 ( ( * V_17 % V_18 ) + 3 > V_18 ) ) {
F_7 ( & V_5 -> V_9 , L_7 ) ;
return;
}
F_2 ( V_3 , V_20 , & V_19 ) ;
V_15 -> V_27 [ * V_17 ++ ] = V_19 >> 16 ;
V_15 -> V_27 [ * V_17 ++ ] = V_19 >> 8 ;
V_15 -> V_27 [ * V_17 ++ ] = V_19 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_3 ( & V_5 -> V_9 , L_8 ) ;
if ( V_15 -> V_24 == 0 )
return;
V_15 -> V_28 = ( V_15 -> V_24 - 1 ) / V_25 + 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_19 ;
F_3 ( & V_5 -> V_9 , L_9 ) ;
F_2 ( V_3 , V_23 , & V_19 ) ;
F_2 ( V_3 , V_26 , & V_19 ) ;
V_15 -> V_28 = 0 ;
V_15 -> V_21 = 0 ;
V_15 -> V_24 = 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 , V_29 ;
F_2 ( V_3 , V_30 , & V_19 ) ;
F_2 ( V_3 , V_11 , & V_29 ) ;
F_12 ( V_3 , V_31 , V_19 & V_29 ) ;
return V_19 ;
}
static T_2 F_13 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_34 ;
V_34 = F_11 ( V_2 ) ;
if ( V_34 & V_35 )
F_1 ( V_2 ) ;
if ( V_34 & V_36 )
F_3 ( & V_5 -> V_9 , L_10 ) ;
if ( V_34 & V_37 )
F_3 ( & V_5 -> V_9 , L_11 ) ;
if ( V_34 & V_38 )
F_3 ( & V_5 -> V_9 , L_12 ) ;
if ( V_34 & V_39 )
F_3 ( & V_5 -> V_9 , L_13 ) ;
if ( V_34 & V_12 )
F_4 ( V_2 ) ;
if ( V_34 & V_40 )
F_3 ( & V_5 -> V_9 , L_14 ) ;
if ( V_34 & V_41 )
F_6 ( V_2 , 'U' ) ;
if ( V_34 & V_42 )
F_3 ( & V_5 -> V_9 , L_15 ) ;
if ( V_34 & V_43 )
F_6 ( V_2 , 'Q' ) ;
if ( V_34 & V_44 )
F_3 ( & V_5 -> V_9 , L_16 ) ;
if ( V_34 & V_45 )
F_9 ( V_2 ) ;
if ( V_34 & V_46 )
F_10 ( V_2 ) ;
if ( V_34 & V_47 )
F_3 ( & V_5 -> V_9 , L_17 ) ;
if ( V_34 & V_48 )
F_3 ( & V_5 -> V_9 , L_18 ) ;
if ( V_34 & V_49 )
F_1 ( V_2 ) ;
if ( V_34 & V_50 )
F_3 ( & V_5 -> V_9 , L_19 ) ;
if ( V_34 & V_51 )
F_3 ( & V_5 -> V_9 , L_20 ) ;
return V_52 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 , V_53 = 1000 ;
F_12 ( V_3 , V_54 , V_55 ) ;
do {
F_2 ( V_3 , V_54 , & V_19 ) ;
} while ( ( V_19 & V_55 ) && V_53 -- );
if ( V_53 )
return 0 ;
else
return - V_56 ;
}
static void F_15 ( struct V_14 * V_15 ,
T_3 V_57 , T_3 V_58 )
{
V_15 -> V_59 [ 3 ] &= ~ V_57 ;
V_15 -> V_59 [ 3 ] |= V_58 & V_57 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_59 ;
V_59 = ( F_17 ( V_15 -> V_59 [ 0 ] ) << 16 ) |
( F_17 ( V_15 -> V_59 [ 1 ] ) << 8 ) |
F_17 ( V_15 -> V_59 [ 2 ] ) ;
F_12 ( V_3 , V_60 , V_59 ) ;
F_3 ( & V_5 -> V_9 , L_21 , V_59 ) ;
V_59 = F_17 ( V_15 -> V_59 [ 3 ] ) << 16 ;
F_12 ( V_3 , V_61 , V_59 ) ;
F_3 ( & V_5 -> V_9 , L_22 , V_59 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_62 V_63 , int V_10 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_64 = V_2 -> V_65 ;
if ( V_64 >= V_66 || V_63 >= V_67 )
return - V_68 ;
F_5 ( V_3 , V_7 ,
V_69 | V_70 ,
F_19 ( V_64 ) | F_20 ( V_63 ) ) ;
return 0 ;
}
static int F_21 ( struct V_71 * V_72 ,
int V_73 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_78 = 0 ;
T_1 V_79 , V_57 , V_80 ;
T_3 V_81 , div ;
int V_82 ;
switch ( V_73 ) {
case 32000 :
V_80 = V_83 ;
V_78 = V_84 ;
break;
case 44100 :
V_80 = V_85 ;
V_78 = V_86 ;
break;
case 48000 :
V_80 = V_87 ;
V_78 = V_88 ;
break;
default:
F_7 ( & V_5 -> V_9 , L_23 , V_73 ) ;
return - V_68 ;
}
V_81 = V_2 -> V_89 [ V_80 ] ;
if ( V_81 >= V_90 ) {
F_7 ( & V_5 -> V_9 , L_24 ) ;
return - V_68 ;
}
div = V_2 -> V_91 [ V_80 ] ;
if ( div == 0 ) {
F_7 ( & V_5 -> V_9 , L_25 ) ;
return - V_68 ;
}
V_82 = F_23 ( V_2 -> V_92 [ V_80 ] , 64 * V_73 * ( div + 1 ) ) ;
if ( V_82 ) {
F_7 ( & V_5 -> V_9 , L_26 ) ;
return V_82 ;
}
F_3 ( & V_5 -> V_9 , L_27 ,
( 64 * V_73 * div ) ) ;
F_3 ( & V_5 -> V_9 , L_28 ,
F_24 ( V_2 -> V_92 [ V_80 ] ) ) ;
F_15 ( V_15 , V_93 , V_78 ) ;
V_79 = V_94 | F_25 ( V_81 ) | F_26 ( div ) ;
V_57 = V_95 | V_96 | V_97 ;
F_5 ( V_3 , V_98 , V_57 , V_79 ) ;
F_3 ( & V_5 -> V_9 , L_29 , V_73 ) ;
return 0 ;
}
static int F_27 ( struct V_71 * V_72 ,
struct V_99 * V_77 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_100 , V_57 , V_101 ;
int V_82 ;
if ( ! V_77 -> V_102 ) {
V_82 = F_14 ( V_2 ) ;
if ( V_82 ) {
F_7 ( & V_5 -> V_9 , L_30 ) ;
return V_82 ;
}
F_5 ( V_3 , V_11 , 0xffffff , 0 ) ;
}
if ( V_72 -> V_103 == V_104 ) {
V_100 = V_105 | V_106 |
V_107 | V_108 |
V_109 ;
V_57 = V_110 | V_111 |
V_112 | V_113 |
V_114 ;
for ( V_101 = 0 ; V_101 < V_115 ; V_101 ++ )
F_28 ( V_2 -> V_92 [ V_101 ] ) ;
} else {
V_100 = V_116 | V_117 ;
V_57 = V_118 | V_119 |
V_120 | V_121 ;
F_28 ( V_2 -> V_122 ) ;
}
F_5 ( V_3 , V_54 , V_57 , V_100 ) ;
F_5 ( V_3 , V_54 , V_123 , 0 ) ;
return 0 ;
}
static void F_29 ( struct V_71 * V_72 ,
struct V_99 * V_77 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_100 , V_57 , V_101 ;
if ( V_72 -> V_103 == V_104 ) {
V_100 = 0 ;
V_57 = V_110 | V_111 |
V_112 | V_113 |
V_114 ;
for ( V_101 = 0 ; V_101 < V_115 ; V_101 ++ )
F_30 ( V_2 -> V_92 [ V_101 ] ) ;
} else {
V_100 = V_124 | V_125 ;
V_57 = V_118 | V_119 |
V_120 | V_121 ;
F_30 ( V_2 -> V_122 ) ;
}
F_5 ( V_3 , V_54 , V_57 , V_100 ) ;
if ( ! V_77 -> V_102 ) {
F_11 ( V_2 ) ;
F_5 ( V_3 , V_54 ,
V_123 , V_123 ) ;
}
}
static int F_31 ( struct V_71 * V_72 ,
struct V_126 * V_127 ,
struct V_99 * V_128 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_73 = F_32 ( V_127 ) ;
int V_82 = 0 ;
if ( V_72 -> V_103 == V_104 ) {
V_82 = F_21 ( V_72 , V_73 ) ;
if ( V_82 ) {
F_7 ( & V_5 -> V_9 , L_31 ,
V_129 , V_73 ) ;
return V_82 ;
}
F_15 ( V_15 , V_130 ,
V_131 ) ;
F_16 ( V_2 ) ;
} else {
V_82 = F_18 ( V_2 , V_132 , 1 ) ;
}
return V_82 ;
}
static int F_33 ( struct V_71 * V_72 ,
int V_133 , struct V_99 * V_128 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
int V_134 = ( V_72 -> V_103 == V_104 ) ;
T_1 V_135 = V_134 ? V_136 : V_137 ;
T_1 V_138 = V_134 ? V_139 : V_140 ; ;
switch ( V_133 ) {
case V_141 :
case V_142 :
case V_143 :
F_5 ( V_3 , V_11 , V_135 , V_135 ) ;
F_5 ( V_3 , V_54 , V_138 , V_138 ) ;
break;
case V_144 :
case V_145 :
case V_146 :
F_5 ( V_3 , V_54 , V_138 , 0 ) ;
F_5 ( V_3 , V_11 , V_135 , 0 ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_34 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
V_150 -> type = V_151 ;
V_150 -> V_152 = 1 ;
return 0 ;
}
static int F_35 ( struct V_147 * V_148 ,
struct V_153 * V_154 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
V_154 -> V_155 . V_156 . V_157 [ 0 ] = V_15 -> V_59 [ 0 ] ;
V_154 -> V_155 . V_156 . V_157 [ 1 ] = V_15 -> V_59 [ 1 ] ;
V_154 -> V_155 . V_156 . V_157 [ 2 ] = V_15 -> V_59 [ 2 ] ;
V_154 -> V_155 . V_156 . V_157 [ 3 ] = V_15 -> V_59 [ 3 ] ;
return 0 ;
}
static int F_37 ( struct V_147 * V_148 ,
struct V_153 * V_154 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
V_15 -> V_59 [ 0 ] = V_154 -> V_155 . V_156 . V_157 [ 0 ] ;
V_15 -> V_59 [ 1 ] = V_154 -> V_155 . V_156 . V_157 [ 1 ] ;
V_15 -> V_59 [ 2 ] = V_154 -> V_155 . V_156 . V_157 [ 2 ] ;
V_15 -> V_59 [ 3 ] = V_154 -> V_155 . V_156 . V_157 [ 3 ] ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_147 * V_148 ,
struct V_153 * V_158 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_58 , V_19 ;
F_2 ( V_3 , V_30 , & V_19 ) ;
if ( ! ( V_19 & V_38 ) ) {
return - V_159 ;
}
F_2 ( V_3 , V_160 , & V_58 ) ;
V_158 -> V_155 . V_156 . V_157 [ 0 ] = ( V_58 >> 16 ) & 0xFF ;
V_158 -> V_155 . V_156 . V_157 [ 1 ] = ( V_58 >> 8 ) & 0xFF ;
V_158 -> V_155 . V_156 . V_157 [ 2 ] = V_58 & 0xFF ;
F_2 ( V_3 , V_161 , & V_58 ) ;
V_158 -> V_155 . V_156 . V_157 [ 3 ] = ( V_58 >> 16 ) & 0xFF ;
V_158 -> V_155 . V_156 . V_157 [ 4 ] = ( V_58 >> 8 ) & 0xFF ;
V_158 -> V_155 . V_156 . V_157 [ 5 ] = V_58 & 0xFF ;
F_12 ( V_3 , V_31 , V_38 ) ;
return 0 ;
}
static int F_39 ( struct V_147 * V_148 ,
struct V_153 * V_158 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
unsigned long V_162 ;
int V_82 = 0 ;
F_40 ( & V_15 -> V_163 , V_162 ) ;
if ( V_15 -> V_28 ) {
int V_164 = ( V_15 -> V_28 - 1 ) * V_22 ;
memcpy ( & V_158 -> V_155 . V_156 . V_27 [ 0 ] ,
& V_15 -> V_27 [ V_164 ] , V_22 ) ;
} else {
V_82 = - V_159 ;
}
F_41 ( & V_15 -> V_163 , V_162 ) ;
return V_82 ;
}
static int F_42 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
V_150 -> type = V_165 ;
V_150 -> V_152 = V_25 ;
return 0 ;
}
static int F_43 ( struct V_147 * V_148 ,
struct V_153 * V_158 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
unsigned long V_162 ;
int V_82 = 0 ;
F_40 ( & V_15 -> V_163 , V_162 ) ;
if ( V_15 -> V_28 ) {
int V_164 = ( V_15 -> V_28 - 1 ) * V_25 ;
memcpy ( & V_158 -> V_155 . V_166 . V_167 [ 0 ] ,
& V_15 -> V_168 [ V_164 ] , V_25 ) ;
} else {
V_82 = - V_159 ;
}
F_41 ( & V_15 -> V_163 , V_162 ) ;
return V_82 ;
}
static int F_44 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
V_150 -> type = V_169 ;
V_150 -> V_152 = 1 ;
V_150 -> V_155 . integer . V_170 = 0 ;
V_150 -> V_155 . integer . V_171 = 1 ;
return 0 ;
}
static int F_45 ( struct V_147 * V_148 ,
struct V_153 * V_158 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 ;
V_19 = F_2 ( V_3 , V_30 , & V_19 ) ;
V_158 -> V_155 . integer . V_155 [ 0 ] = ( V_19 & V_39 ) != 0 ;
F_12 ( V_3 , V_31 , V_39 ) ;
return 0 ;
}
static int F_46 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
V_150 -> type = V_172 ;
V_150 -> V_152 = 1 ;
V_150 -> V_155 . integer . V_170 = 16000 ;
V_150 -> V_155 . integer . V_171 = 96000 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
enum V_62 V_63 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_173 , V_174 = 0 ;
T_1 V_175 , V_176 ;
T_3 V_64 ;
F_2 ( V_3 , V_177 , & V_175 ) ;
F_2 ( V_3 , V_7 , & V_176 ) ;
V_64 = ( V_176 >> V_178 ) & 0xf ;
if ( V_179 [ V_64 ] && ( V_176 & V_8 ) ) {
V_174 = F_24 ( V_2 -> V_122 ) ;
}
V_173 = ( T_4 ) V_174 * V_175 ;
F_48 ( V_173 , V_180 [ V_63 ] * 1024 ) ;
F_48 ( V_173 , 128 * 1024 ) ;
F_3 ( & V_5 -> V_9 , L_32 , V_175 ) ;
F_3 ( & V_5 -> V_9 , L_33 , V_174 ) ;
F_3 ( & V_5 -> V_9 , L_34 , V_173 ) ;
return ( int ) V_173 ;
}
static int F_49 ( struct V_147 * V_148 ,
struct V_153 * V_158 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
int V_80 = F_47 ( V_2 , V_132 ) ;
if ( V_2 -> V_10 )
V_158 -> V_155 . integer . V_155 [ 0 ] = V_80 ;
else
V_158 -> V_155 . integer . V_155 [ 0 ] = 0 ;
return 0 ;
}
static int F_50 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
V_150 -> type = V_169 ;
V_150 -> V_152 = 1 ;
V_150 -> V_155 . integer . V_170 = 0 ;
V_150 -> V_155 . integer . V_171 = 1 ;
return 0 ;
}
static int F_51 ( struct V_147 * V_148 ,
struct V_153 * V_158 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 ;
F_2 ( V_3 , V_181 , & V_19 ) ;
V_158 -> V_155 . integer . V_155 [ 0 ] = ( V_19 & V_182 ) != 0 ;
return 0 ;
}
static int F_52 ( struct V_147 * V_148 ,
struct V_153 * V_158 )
{
struct V_99 * V_77 = F_36 ( V_148 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 = V_158 -> V_155 . integer . V_155 [ 0 ] << V_183 ;
F_5 ( V_3 , V_181 , V_182 , V_19 ) ;
return 0 ;
}
static int F_53 ( struct V_99 * V_128 )
{
struct V_1 * V_184 = F_22 ( V_128 ) ;
V_128 -> V_185 = & V_184 -> V_186 ;
V_128 -> V_187 = & V_184 -> V_188 ;
F_54 ( V_128 , V_189 , F_55 ( V_189 ) ) ;
return 0 ;
}
static bool F_56 ( struct V_190 * V_9 , unsigned int V_20 )
{
switch ( V_20 ) {
case V_54 :
case V_181 :
case V_7 :
case V_11 :
case V_30 :
case V_191 :
case V_192 :
case V_160 :
case V_161 :
case V_23 :
case V_26 :
case V_60 :
case V_61 :
case V_177 :
case V_98 :
return true ;
default:
return false ;
} ;
}
static bool F_57 ( struct V_190 * V_9 , unsigned int V_20 )
{
switch ( V_20 ) {
case V_54 :
case V_181 :
case V_7 :
case V_11 :
case V_31 :
case V_193 :
case V_194 :
case V_60 :
case V_61 :
case V_98 :
return true ;
default:
return false ;
} ;
}
static T_1 F_58 ( struct V_1 * V_2 ,
struct V_81 * V_81 , T_4 V_195 ,
enum V_196 V_197 )
{
const T_1 V_80 [] = { 32000 , 44100 , 48000 } ;
T_4 V_198 , V_199 , V_200 ;
T_1 div , V_201 ;
for ( div = 1 ; div <= 128 ; div ++ ) {
V_198 = V_80 [ V_197 ] * ( div + 1 ) * 64 ;
V_199 = F_59 ( V_81 , V_198 ) ;
V_201 = V_199 / 64 ;
V_201 /= div ;
if ( V_201 == V_80 [ V_197 ] ) {
V_195 = 0 ;
V_2 -> V_91 [ V_197 ] = div ;
break;
} else if ( V_201 / V_80 [ V_197 ] == 1 ) {
V_200 = ( V_201 - V_80 [ V_197 ] ) * 100000 ;
F_48 ( V_200 , V_80 [ V_197 ] ) ;
if ( V_200 < V_195 ) {
V_195 = V_200 ;
V_2 -> V_91 [ V_197 ] = div ;
}
} else if ( V_80 [ V_197 ] / V_201 == 1 ) {
V_200 = ( V_80 [ V_197 ] - V_201 ) * 100000 ;
F_48 ( V_200 , V_80 [ V_197 ] ) ;
if ( V_200 < V_195 ) {
V_195 = V_200 ;
V_2 -> V_91 [ V_197 ] = div ;
}
}
}
return V_195 ;
}
static int F_60 ( struct V_1 * V_2 ,
enum V_196 V_197 )
{
const T_1 V_80 [] = { 32000 , 44100 , 48000 } ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_190 * V_9 = & V_5 -> V_9 ;
T_4 V_195 = 100000 , V_82 ;
struct V_81 * V_81 ;
char V_202 [ 16 ] ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_90 ; V_101 ++ ) {
sprintf ( V_202 , L_35 , V_101 ) ;
V_81 = F_61 ( & V_5 -> V_9 , V_202 ) ;
if ( F_62 ( V_81 ) ) {
F_7 ( V_9 , L_36 , V_101 ) ;
return F_63 ( V_81 ) ;
}
if ( ! F_24 ( V_81 ) )
continue;
V_82 = F_58 ( V_2 , V_81 , V_195 , V_197 ) ;
if ( V_195 == V_82 )
continue;
V_195 = V_82 ;
V_2 -> V_92 [ V_197 ] = V_81 ;
V_2 -> V_89 [ V_197 ] = V_101 ;
if ( V_195 < 100 )
break;
}
F_3 ( & V_5 -> V_9 , L_37 ,
V_2 -> V_89 [ V_197 ] , V_80 [ V_197 ] ) ;
F_3 ( & V_5 -> V_9 , L_38 ,
V_2 -> V_91 [ V_197 ] , V_80 [ V_197 ] ) ;
return 0 ;
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_203 * V_204 = V_5 -> V_9 . V_205 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_206 * V_207 ;
void T_5 * V_208 ;
int V_32 , V_82 , V_101 ;
if ( ! V_204 )
return - V_209 ;
V_2 = F_65 ( & V_5 -> V_9 ,
sizeof( struct V_1 ) + strlen ( V_204 -> V_13 ) + 1 ,
V_210 ) ;
if ( ! V_2 )
return - V_211 ;
strcpy ( V_2 -> V_13 , V_204 -> V_13 ) ;
V_2 -> V_5 = V_5 ;
memcpy ( & V_2 -> V_212 , & V_213 , sizeof( V_213 ) ) ;
V_2 -> V_212 . V_13 = V_2 -> V_13 ;
V_207 = F_66 ( V_5 , V_214 , 0 ) ;
if ( F_62 ( V_207 ) ) {
F_7 ( & V_5 -> V_9 , L_39 ) ;
return F_63 ( V_207 ) ;
}
V_208 = F_67 ( & V_5 -> V_9 , V_207 ) ;
if ( F_62 ( V_208 ) )
return F_63 ( V_208 ) ;
V_2 -> V_3 = F_68 ( & V_5 -> V_9 ,
L_40 , V_208 , & V_215 ) ;
if ( F_62 ( V_2 -> V_3 ) ) {
F_7 ( & V_5 -> V_9 , L_41 ) ;
return F_63 ( V_2 -> V_3 ) ;
}
V_32 = F_69 ( V_5 , 0 ) ;
if ( V_32 < 0 ) {
F_7 ( & V_5 -> V_9 , L_42 , V_204 -> V_216 ) ;
return V_32 ;
}
V_82 = F_70 ( & V_5 -> V_9 , V_32 , F_13 , 0 ,
V_2 -> V_13 , V_2 ) ;
if ( V_82 ) {
F_7 ( & V_5 -> V_9 , L_43 , V_32 ) ;
return V_82 ;
}
V_2 -> V_122 = F_61 ( & V_5 -> V_9 , L_44 ) ;
if ( F_62 ( V_2 -> V_122 ) ) {
F_7 ( & V_5 -> V_9 , L_45 ) ;
return F_63 ( V_2 -> V_122 ) ;
}
V_2 -> V_65 = V_217 ;
for ( V_101 = 0 ; V_101 < V_115 ; V_101 ++ ) {
V_82 = F_60 ( V_2 , V_101 ) ;
if ( V_82 )
return V_82 ;
}
V_15 = & V_2 -> V_16 ;
F_71 ( & V_15 -> V_163 ) ;
V_15 -> V_59 [ 0 ] =
V_218 | V_219 ;
V_15 -> V_59 [ 1 ] = V_220 ;
V_15 -> V_59 [ 2 ] = 0x00 ;
V_15 -> V_59 [ 3 ] =
V_86 | V_131 ;
V_2 -> V_10 = false ;
V_2 -> V_186 . V_221 = V_222 ;
V_2 -> V_188 . V_221 = V_223 ;
V_2 -> V_186 . V_224 = V_207 -> V_225 + V_193 ;
V_2 -> V_188 . V_224 = V_207 -> V_225 + V_191 ;
F_72 ( & V_5 -> V_9 , V_2 ) ;
V_82 = F_73 ( & V_5 -> V_9 , & V_226 ,
& V_2 -> V_212 , 1 ) ;
if ( V_82 ) {
F_7 ( & V_5 -> V_9 , L_46 , V_82 ) ;
return V_82 ;
}
V_82 = F_74 ( V_5 ) ;
if ( V_82 ) {
F_7 ( & V_5 -> V_9 , L_47 , V_82 ) ;
goto V_227;
}
return V_82 ;
V_227:
F_75 ( & V_5 -> V_9 ) ;
return V_82 ;
}
static int F_76 ( struct V_4 * V_5 )
{
F_77 ( V_5 ) ;
F_75 ( & V_5 -> V_9 ) ;
return 0 ;
}
