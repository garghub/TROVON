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
if ( ! V_2 -> V_10 )
F_5 ( V_3 , V_11 , V_12 , 0 ) ;
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
T_3 V_81 , V_82 , V_83 ;
int V_84 ;
switch ( V_73 ) {
case 32000 :
V_80 = V_85 ;
V_78 = V_86 ;
break;
case 44100 :
V_80 = V_87 ;
V_78 = V_88 ;
break;
case 48000 :
V_80 = V_89 ;
V_78 = V_90 ;
break;
case 96000 :
V_80 = V_91 ;
V_78 = V_92 ;
break;
case 192000 :
V_80 = V_93 ;
V_78 = V_94 ;
break;
default:
F_7 ( & V_5 -> V_9 , L_23 , V_73 ) ;
return - V_68 ;
}
V_81 = V_2 -> V_95 [ V_80 ] ;
if ( V_81 >= V_96 ) {
F_7 ( & V_5 -> V_9 , L_24 ) ;
return - V_68 ;
}
V_82 = V_2 -> V_82 [ V_80 ] ;
if ( V_82 == 0 ) {
F_7 ( & V_5 -> V_9 , L_25 ) ;
return - V_68 ;
}
V_83 = V_2 -> V_83 [ V_80 ] ;
if ( V_81 != V_97 )
goto V_98;
V_84 = F_23 ( V_2 -> V_99 [ V_80 ] , 64 * V_73 * ( V_82 + 1 ) ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_26 ) ;
return V_84 ;
}
V_98:
F_3 ( & V_5 -> V_9 , L_27 ,
( 64 * V_73 * V_82 * V_83 ) ) ;
F_3 ( & V_5 -> V_9 , L_28 ,
F_24 ( V_2 -> V_99 [ V_80 ] ) ) ;
F_15 ( V_15 , V_100 , V_78 ) ;
V_79 = V_101 | F_25 ( V_81 ) |
F_26 ( V_82 ) | F_27 ( V_83 ) ;
V_57 = V_102 | V_103 |
V_104 | V_105 ;
F_5 ( V_3 , V_106 , V_57 , V_79 ) ;
F_3 ( & V_5 -> V_9 , L_29 ,
V_2 -> V_107 [ V_80 ] , V_73 ) ;
return 0 ;
}
static int F_28 ( struct V_71 * V_72 ,
struct V_108 * V_77 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_109 , V_57 , V_110 ;
int V_84 ;
if ( ! V_77 -> V_111 ) {
V_84 = F_29 ( V_2 -> V_112 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_30 ) ;
return V_84 ;
}
V_84 = F_14 ( V_2 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_31 ) ;
goto V_113;
}
F_5 ( V_3 , V_11 , 0xffffff , 0 ) ;
}
if ( V_72 -> V_114 == V_115 ) {
V_109 = V_116 | V_117 |
V_118 | V_119 |
V_120 ;
V_57 = V_121 | V_122 |
V_123 | V_124 |
V_125 ;
for ( V_110 = 0 ; V_110 < V_126 ; V_110 ++ )
F_29 ( V_2 -> V_99 [ V_110 ] ) ;
} else {
V_109 = V_127 | V_128 ;
V_57 = V_129 | V_130 |
V_131 | V_132 ;
F_29 ( V_2 -> V_133 ) ;
}
F_5 ( V_3 , V_54 , V_57 , V_109 ) ;
F_5 ( V_3 , V_54 , V_134 , 0 ) ;
return 0 ;
V_113:
F_30 ( V_2 -> V_112 ) ;
return V_84 ;
}
static void F_31 ( struct V_71 * V_72 ,
struct V_108 * V_77 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_109 , V_57 , V_110 ;
if ( V_72 -> V_114 == V_115 ) {
V_109 = 0 ;
V_57 = V_121 | V_122 |
V_123 | V_124 |
V_125 ;
for ( V_110 = 0 ; V_110 < V_126 ; V_110 ++ )
F_30 ( V_2 -> V_99 [ V_110 ] ) ;
} else {
V_109 = V_135 | V_136 ;
V_57 = V_129 | V_130 |
V_131 | V_132 ;
F_30 ( V_2 -> V_133 ) ;
}
F_5 ( V_3 , V_54 , V_57 , V_109 ) ;
if ( ! V_77 -> V_111 ) {
F_11 ( V_2 ) ;
F_5 ( V_3 , V_54 ,
V_134 , V_134 ) ;
F_30 ( V_2 -> V_112 ) ;
}
}
static int F_32 ( struct V_71 * V_72 ,
struct V_137 * V_138 ,
struct V_108 * V_139 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_73 = F_33 ( V_138 ) ;
int V_84 = 0 ;
if ( V_72 -> V_114 == V_115 ) {
V_84 = F_21 ( V_72 , V_73 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_32 ,
V_140 , V_73 ) ;
return V_84 ;
}
F_15 ( V_15 , V_141 ,
V_142 ) ;
F_16 ( V_2 ) ;
} else {
V_84 = F_18 ( V_2 , V_143 , 1 ) ;
}
return V_84 ;
}
static int F_34 ( struct V_71 * V_72 ,
int V_144 , struct V_108 * V_139 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_75 -> V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
bool V_145 = V_72 -> V_114 == V_115 ;
T_1 V_146 = F_35 ( V_145 ) ;
T_1 V_147 = F_36 ( V_145 ) ;
switch ( V_144 ) {
case V_148 :
case V_149 :
case V_150 :
F_5 ( V_3 , V_11 , V_146 , V_146 ) ;
F_5 ( V_3 , V_54 , V_147 , V_147 ) ;
break;
case V_151 :
case V_152 :
case V_153 :
F_5 ( V_3 , V_54 , V_147 , 0 ) ;
F_5 ( V_3 , V_11 , V_146 , 0 ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_37 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
V_157 -> type = V_158 ;
V_157 -> V_159 = 1 ;
return 0 ;
}
static int F_38 ( struct V_154 * V_155 ,
struct V_160 * V_161 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
V_161 -> V_162 . V_163 . V_164 [ 0 ] = V_15 -> V_59 [ 0 ] ;
V_161 -> V_162 . V_163 . V_164 [ 1 ] = V_15 -> V_59 [ 1 ] ;
V_161 -> V_162 . V_163 . V_164 [ 2 ] = V_15 -> V_59 [ 2 ] ;
V_161 -> V_162 . V_163 . V_164 [ 3 ] = V_15 -> V_59 [ 3 ] ;
return 0 ;
}
static int F_40 ( struct V_154 * V_155 ,
struct V_160 * V_161 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
V_15 -> V_59 [ 0 ] = V_161 -> V_162 . V_163 . V_164 [ 0 ] ;
V_15 -> V_59 [ 1 ] = V_161 -> V_162 . V_163 . V_164 [ 1 ] ;
V_15 -> V_59 [ 2 ] = V_161 -> V_162 . V_163 . V_164 [ 2 ] ;
V_15 -> V_59 [ 3 ] = V_161 -> V_162 . V_163 . V_164 [ 3 ] ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_154 * V_155 ,
struct V_160 * V_165 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_58 , V_19 ;
F_2 ( V_3 , V_30 , & V_19 ) ;
if ( ! ( V_19 & V_38 ) )
return - V_166 ;
F_2 ( V_3 , V_167 , & V_58 ) ;
V_165 -> V_162 . V_163 . V_164 [ 0 ] = ( V_58 >> 16 ) & 0xFF ;
V_165 -> V_162 . V_163 . V_164 [ 1 ] = ( V_58 >> 8 ) & 0xFF ;
V_165 -> V_162 . V_163 . V_164 [ 2 ] = V_58 & 0xFF ;
F_2 ( V_3 , V_168 , & V_58 ) ;
V_165 -> V_162 . V_163 . V_164 [ 3 ] = ( V_58 >> 16 ) & 0xFF ;
V_165 -> V_162 . V_163 . V_164 [ 4 ] = ( V_58 >> 8 ) & 0xFF ;
V_165 -> V_162 . V_163 . V_164 [ 5 ] = V_58 & 0xFF ;
F_12 ( V_3 , V_31 , V_38 ) ;
return 0 ;
}
static int F_42 ( struct V_154 * V_155 ,
struct V_160 * V_165 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
unsigned long V_169 ;
int V_84 = - V_166 ;
F_43 ( & V_15 -> V_170 , V_169 ) ;
if ( V_15 -> V_28 ) {
int V_171 = ( V_15 -> V_28 - 1 ) * V_22 ;
memcpy ( & V_165 -> V_162 . V_163 . V_27 [ 0 ] ,
& V_15 -> V_27 [ V_171 ] , V_22 ) ;
V_84 = 0 ;
}
F_44 ( & V_15 -> V_170 , V_169 ) ;
return V_84 ;
}
static int F_45 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
V_157 -> type = V_172 ;
V_157 -> V_159 = V_25 ;
return 0 ;
}
static int F_46 ( struct V_154 * V_155 ,
struct V_160 * V_165 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
unsigned long V_169 ;
int V_84 = - V_166 ;
F_43 ( & V_15 -> V_170 , V_169 ) ;
if ( V_15 -> V_28 ) {
int V_171 = ( V_15 -> V_28 - 1 ) * V_25 ;
memcpy ( & V_165 -> V_162 . V_173 . V_174 [ 0 ] ,
& V_15 -> V_175 [ V_171 ] , V_25 ) ;
V_84 = 0 ;
}
F_44 ( & V_15 -> V_170 , V_169 ) ;
return V_84 ;
}
static int F_47 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
V_157 -> type = V_176 ;
V_157 -> V_159 = 1 ;
V_157 -> V_162 . integer . V_177 = 0 ;
V_157 -> V_162 . integer . V_178 = 1 ;
return 0 ;
}
static int F_48 ( struct V_154 * V_155 ,
struct V_160 * V_165 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 ;
F_2 ( V_3 , V_30 , & V_19 ) ;
V_165 -> V_162 . integer . V_162 [ 0 ] = ( V_19 & V_39 ) != 0 ;
F_12 ( V_3 , V_31 , V_39 ) ;
return 0 ;
}
static int F_49 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
V_157 -> type = V_179 ;
V_157 -> V_159 = 1 ;
V_157 -> V_162 . integer . V_177 = 16000 ;
V_157 -> V_162 . integer . V_178 = 96000 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
enum V_62 V_63 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_180 , V_181 = 0 ;
T_1 V_182 , V_183 ;
T_3 V_64 ;
F_2 ( V_3 , V_184 , & V_182 ) ;
F_2 ( V_3 , V_7 , & V_183 ) ;
V_64 = ( V_183 >> V_185 ) & 0xf ;
if ( V_186 [ V_64 ] && ( V_183 & V_8 ) )
V_181 = F_24 ( V_2 -> V_187 ) ;
V_180 = ( T_4 ) V_181 * V_182 ;
F_51 ( V_180 , V_188 [ V_63 ] * 1024 ) ;
F_51 ( V_180 , 128 * 1024 ) ;
F_3 ( & V_5 -> V_9 , L_33 , V_182 ) ;
F_3 ( & V_5 -> V_9 , L_34 , V_181 ) ;
F_3 ( & V_5 -> V_9 , L_35 , V_180 ) ;
return ( int ) V_180 ;
}
static int F_52 ( struct V_154 * V_155 ,
struct V_160 * V_165 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
int V_80 = 0 ;
if ( V_2 -> V_10 )
V_80 = F_50 ( V_2 , V_143 ) ;
V_165 -> V_162 . integer . V_162 [ 0 ] = V_80 ;
return 0 ;
}
static int F_53 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
V_157 -> type = V_176 ;
V_157 -> V_159 = 1 ;
V_157 -> V_162 . integer . V_177 = 0 ;
V_157 -> V_162 . integer . V_178 = 1 ;
return 0 ;
}
static int F_54 ( struct V_154 * V_155 ,
struct V_160 * V_165 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 ;
F_2 ( V_3 , V_189 , & V_19 ) ;
V_165 -> V_162 . integer . V_162 [ 0 ] = ( V_19 & V_190 ) != 0 ;
return 0 ;
}
static int F_55 ( struct V_154 * V_155 ,
struct V_160 * V_165 )
{
struct V_108 * V_77 = F_39 ( V_155 ) ;
struct V_1 * V_2 = F_22 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 = V_165 -> V_162 . integer . V_162 [ 0 ] << V_191 ;
F_5 ( V_3 , V_189 , V_190 , V_19 ) ;
return 0 ;
}
static int F_56 ( struct V_108 * V_139 )
{
struct V_1 * V_192 = F_22 ( V_139 ) ;
F_57 ( V_139 , & V_192 -> V_193 ,
& V_192 -> V_194 ) ;
F_58 ( V_139 , V_195 , F_59 ( V_195 ) ) ;
return 0 ;
}
static bool F_60 ( struct V_196 * V_9 , unsigned int V_20 )
{
switch ( V_20 ) {
case V_54 :
case V_189 :
case V_7 :
case V_11 :
case V_30 :
case V_197 :
case V_198 :
case V_167 :
case V_168 :
case V_23 :
case V_26 :
case V_60 :
case V_61 :
case V_184 :
case V_106 :
return true ;
default:
return false ;
}
}
static bool F_61 ( struct V_196 * V_9 , unsigned int V_20 )
{
switch ( V_20 ) {
case V_54 :
case V_189 :
case V_7 :
case V_11 :
case V_31 :
case V_199 :
case V_200 :
case V_60 :
case V_61 :
case V_106 :
return true ;
default:
return false ;
}
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_81 * V_81 , T_4 V_201 ,
enum V_202 V_203 , bool V_204 )
{
const T_1 V_80 [] = { 32000 , 44100 , 48000 , 96000 , 192000 } ;
bool V_205 = V_81 == V_2 -> V_187 ;
T_4 V_206 , V_207 , V_208 ;
T_1 V_209 , V_210 ;
T_1 V_82 , V_83 , V_211 ;
V_209 = V_205 ? 2 : 1 ;
V_210 = V_205 ? 512 : 1 ;
for ( V_83 = V_209 ; V_83 <= V_210 ; V_83 ++ ) {
for ( V_82 = 1 ; V_82 <= 128 ; V_82 ++ ) {
V_206 = V_80 [ V_203 ] * ( V_82 + 1 ) * 64 ;
if ( V_204 )
V_207 = F_63 ( V_81 , V_206 ) ;
else
V_207 = F_24 ( V_81 ) ;
V_211 = V_207 / 64 ;
V_211 /= V_82 * V_83 ;
if ( V_211 == V_80 [ V_203 ] ) {
V_201 = 0 ;
V_2 -> V_82 [ V_203 ] = V_82 ;
V_2 -> V_83 [ V_203 ] = V_83 ;
V_2 -> V_107 [ V_203 ] = V_211 ;
goto V_212;
} else if ( V_211 / V_80 [ V_203 ] == 1 ) {
V_208 = ( T_4 ) ( V_211 - V_80 [ V_203 ] ) * 100000 ;
F_51 ( V_208 , V_80 [ V_203 ] ) ;
if ( V_208 >= V_201 )
continue;
V_201 = V_208 ;
V_2 -> V_82 [ V_203 ] = V_82 ;
V_2 -> V_83 [ V_203 ] = V_83 ;
V_2 -> V_107 [ V_203 ] = V_211 ;
} else if ( V_80 [ V_203 ] / V_211 == 1 ) {
V_208 = ( T_4 ) ( V_80 [ V_203 ] - V_211 ) * 100000 ;
F_51 ( V_208 , V_80 [ V_203 ] ) ;
if ( V_208 >= V_201 )
continue;
V_201 = V_208 ;
V_2 -> V_82 [ V_203 ] = V_82 ;
V_2 -> V_83 [ V_203 ] = V_83 ;
V_2 -> V_107 [ V_203 ] = V_211 ;
}
}
}
V_212:
return V_201 ;
}
static int F_64 ( struct V_1 * V_2 ,
enum V_202 V_203 )
{
const T_1 V_80 [] = { 32000 , 44100 , 48000 , 96000 , 192000 } ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_196 * V_9 = & V_5 -> V_9 ;
T_4 V_201 = 100000 , V_84 ;
struct V_81 * V_81 ;
char V_213 [ 16 ] ;
int V_110 ;
for ( V_110 = 0 ; V_110 < V_96 ; V_110 ++ ) {
sprintf ( V_213 , L_36 , V_110 ) ;
V_81 = F_65 ( & V_5 -> V_9 , V_213 ) ;
if ( F_66 ( V_81 ) ) {
F_7 ( V_9 , L_37 , V_110 ) ;
return F_67 ( V_81 ) ;
}
if ( ! F_24 ( V_81 ) )
continue;
V_84 = F_62 ( V_2 , V_81 , V_201 , V_203 ,
V_110 == V_97 ) ;
if ( V_201 == V_84 )
continue;
V_201 = V_84 ;
V_2 -> V_99 [ V_203 ] = V_81 ;
V_2 -> V_95 [ V_203 ] = V_110 ;
if ( V_201 < 100 )
break;
}
F_3 ( & V_5 -> V_9 , L_38 ,
V_2 -> V_95 [ V_203 ] , V_80 [ V_203 ] ) ;
F_3 ( & V_5 -> V_9 , L_39 ,
V_2 -> V_82 [ V_203 ] , V_80 [ V_203 ] ) ;
if ( V_2 -> V_99 [ V_203 ] == V_2 -> V_187 )
F_3 ( & V_5 -> V_9 , L_40 ,
V_2 -> V_83 [ V_203 ] , V_80 [ V_203 ] ) ;
F_3 ( & V_5 -> V_9 , L_41 ,
V_80 [ V_203 ] , V_2 -> V_107 [ V_203 ] ) ;
return 0 ;
}
static int F_68 ( struct V_4 * V_5 )
{
struct V_214 * V_215 = V_5 -> V_9 . V_216 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_217 * V_218 ;
void T_5 * V_219 ;
int V_32 , V_84 , V_110 ;
if ( ! V_215 )
return - V_220 ;
V_2 = F_69 ( & V_5 -> V_9 ,
sizeof( struct V_1 ) + strlen ( V_215 -> V_13 ) + 1 ,
V_221 ) ;
if ( ! V_2 )
return - V_222 ;
strcpy ( V_2 -> V_13 , V_215 -> V_13 ) ;
V_2 -> V_5 = V_5 ;
memcpy ( & V_2 -> V_223 , & V_224 , sizeof( V_224 ) ) ;
V_2 -> V_223 . V_13 = V_2 -> V_13 ;
if ( F_70 ( V_215 , L_42 ) )
V_225 . V_226 = V_227 ;
V_218 = F_71 ( V_5 , V_228 , 0 ) ;
V_219 = F_72 ( & V_5 -> V_9 , V_218 ) ;
if ( F_66 ( V_219 ) )
return F_67 ( V_219 ) ;
V_2 -> V_3 = F_73 ( & V_5 -> V_9 ,
L_43 , V_219 , & V_225 ) ;
if ( F_66 ( V_2 -> V_3 ) ) {
F_7 ( & V_5 -> V_9 , L_44 ) ;
return F_67 ( V_2 -> V_3 ) ;
}
V_32 = F_74 ( V_5 , 0 ) ;
if ( V_32 < 0 ) {
F_7 ( & V_5 -> V_9 , L_45 , V_215 -> V_229 ) ;
return V_32 ;
}
V_84 = F_75 ( & V_5 -> V_9 , V_32 , F_13 , 0 ,
V_2 -> V_13 , V_2 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_46 , V_32 ) ;
return V_84 ;
}
V_2 -> V_187 = F_65 ( & V_5 -> V_9 , L_47 ) ;
if ( F_66 ( V_2 -> V_187 ) ) {
F_7 ( & V_5 -> V_9 , L_48 ) ;
return F_67 ( V_2 -> V_187 ) ;
}
V_2 -> V_112 = F_65 ( & V_5 -> V_9 , L_43 ) ;
if ( F_66 ( V_2 -> V_112 ) ) {
F_7 ( & V_5 -> V_9 , L_49 ) ;
return F_67 ( V_2 -> V_112 ) ;
}
V_2 -> V_133 = F_65 ( & V_5 -> V_9 , L_50 ) ;
if ( F_66 ( V_2 -> V_133 ) ) {
F_7 ( & V_5 -> V_9 , L_51 ) ;
return F_67 ( V_2 -> V_133 ) ;
}
V_2 -> V_65 = V_230 ;
for ( V_110 = 0 ; V_110 < V_126 ; V_110 ++ ) {
V_84 = F_64 ( V_2 , V_110 ) ;
if ( V_84 )
return V_84 ;
}
V_15 = & V_2 -> V_16 ;
F_76 ( & V_15 -> V_170 ) ;
V_15 -> V_59 [ 0 ] = V_231 |
V_232 ;
V_15 -> V_59 [ 1 ] = V_233 ;
V_15 -> V_59 [ 2 ] = 0x00 ;
V_15 -> V_59 [ 3 ] = V_88 |
V_142 ;
V_2 -> V_10 = false ;
V_2 -> V_193 . V_234 = V_235 ;
V_2 -> V_194 . V_234 = V_236 ;
V_2 -> V_193 . V_237 = V_218 -> V_238 + V_199 ;
V_2 -> V_194 . V_237 = V_218 -> V_238 + V_197 ;
F_77 ( & V_5 -> V_9 , V_2 ) ;
V_84 = F_78 ( & V_5 -> V_9 , & V_239 ,
& V_2 -> V_223 , 1 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_52 , V_84 ) ;
return V_84 ;
}
V_84 = F_79 ( V_5 ) ;
if ( V_84 )
F_7 ( & V_5 -> V_9 , L_53 , V_84 ) ;
return V_84 ;
}
