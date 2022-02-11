static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_6 , V_8 ) ;
V_4 -> V_9 . integer . V_9 [ 0 ] = ( V_7 & 0x01 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
T_1 V_10 ;
V_7 = F_3 ( V_6 , V_11 ) ;
V_10 = ( V_7 & V_12 ) ;
if ( V_10 != V_12 ) {
F_5 ( V_13 L_1 ,
V_14 ) ;
return - V_15 ;
}
if ( V_4 -> V_9 . integer . V_9 [ 0 ] == ( V_7 & V_16 ) )
return 0 ;
if ( V_4 -> V_9 . integer . V_9 [ 0 ] )
V_7 |= V_4 -> V_9 . integer . V_9 [ 0 ] ;
else
V_7 &= ~ V_16 ;
F_6 ( V_6 , V_11 , V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_6 , V_17 ) ;
V_4 -> V_9 . integer . V_9 [ 0 ] = ( V_7 & 0x01 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
T_1 V_10 ;
V_7 = F_3 ( V_6 , V_18 ) ;
V_10 = ( V_7 & V_12 ) ;
if ( V_10 != V_12 ) {
F_5 ( V_13 L_2 ,
V_14 ) ;
return - V_15 ;
}
if ( V_4 -> V_9 . integer . V_9 [ 0 ] == ( V_7 & V_19 ) )
return 0 ;
if ( V_4 -> V_9 . integer . V_9 [ 0 ] )
V_7 |= V_4 -> V_9 . integer . V_9 [ 0 ] ;
else
V_7 &= ~ V_19 ;
F_6 ( V_6 , V_18 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_6 , V_20 ) ;
V_4 -> V_9 . integer . V_9 [ 0 ] = ( ( V_7 & 0x2 ) >> 1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
T_1 V_10 ;
V_7 = F_3 ( V_6 , V_20 ) ;
V_10 = ( V_7 & V_21 ) ;
if ( V_10 != V_21 ) {
F_5 ( V_13 L_3 ,
V_14 ) ;
return - V_15 ;
}
if ( V_4 -> V_9 . integer . V_9 [ 0 ] == ( V_7 & 0x1 ) )
return 0 ;
if ( V_4 -> V_9 . integer . V_9 [ 0 ] )
V_7 |= V_4 -> V_9 . integer . V_9 [ 0 ] ;
else
V_7 &= 0xfe ;
F_6 ( V_6 , V_20 , V_7 ) ;
return 0 ;
}
static inline int F_11 ( int V_22 , int V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < F_12 ( V_25 ) ; V_24 ++ ) {
if ( ( V_25 [ V_24 ] . V_23 == V_23 )
&& ( V_25 [ V_24 ] . V_22 == V_22 ) ) {
return V_24 ;
}
}
F_5 ( V_13 L_4 ) ;
return - V_15 ;
}
static int F_13 ( struct V_26 * V_27 ,
int V_28 , unsigned int V_29 , int V_30 )
{
struct V_5 * V_6 = V_27 -> V_6 ;
struct V_31 * V_32 = F_14 ( V_6 ) ;
switch ( V_29 ) {
case V_33 :
case V_34 :
case V_35 :
V_32 -> V_36 = V_29 ;
return 0 ;
}
F_5 ( V_13 L_5 ) ;
return - V_15 ;
}
static int F_15 ( struct V_26 * V_27 , unsigned int V_37 )
{
struct V_5 * V_6 = V_27 -> V_6 ;
T_1 V_38 ;
T_1 V_39 ;
T_1 V_40 ;
V_38 = F_3 ( V_6 , V_41 ) ;
V_38 = V_38 & ~ ( 3 << 6 | 3 << 2 ) ;
V_39 = F_3 ( V_6 , V_42 ) ;
V_39 = 0 ;
V_40 = F_3 ( V_6 , V_43 ) ;
V_40 = V_40 & ~ ( 1 << 3 ) ;
switch ( V_37 & V_44 ) {
case V_45 :
V_38 |= V_46 | V_47 ;
break;
case V_48 :
break;
default:
F_5 ( V_13 L_6 ) ;
return - V_15 ;
}
switch ( V_37 & V_49 ) {
case V_50 :
break;
case V_51 :
V_38 |= ( V_52 << V_53 ) ;
V_40 |= ( 1 << 3 ) ;
V_39 = 0x01 ;
break;
case V_54 :
V_38 |= ( V_52 << V_53 ) ;
V_40 |= ( 1 << 3 ) ;
break;
case V_55 :
V_38 |=
( V_56 << V_53 ) ;
break;
case V_57 :
V_38 |=
( V_58 << V_53 ) ;
break;
default:
F_5 ( V_13 L_7 ) ;
return - V_15 ;
}
F_6 ( V_6 , V_41 , V_38 ) ;
F_6 ( V_6 , V_42 , V_39 ) ;
F_6 ( V_6 , V_43 , V_40 ) ;
return 0 ;
}
static int F_16 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_26 * V_63 )
{
struct V_5 * V_6 = V_63 -> V_6 ;
struct V_31 * V_32 = F_14 ( V_6 ) ;
T_1 V_64 ;
int V_24 ;
V_24 = F_11 ( V_32 -> V_36 , F_17 ( V_62 ) ) ;
if ( V_24 < 0 ) {
F_5 ( V_13 L_8 ) ;
return V_24 ;
}
F_6 ( V_6 , V_65 , V_66 ) ;
F_6 ( V_6 , V_43 , V_67 ) ;
V_64 = F_3 ( V_6 , V_68 ) ;
V_64 &= ~ ( 7 << 4 ) ;
F_6 ( V_6 , V_68 ,
( V_64 | ( V_25 [ V_24 ] . V_69 << 4 ) | 0x01 ) ) ;
F_6 ( V_6 , V_70 , V_25 [ V_24 ] . V_71 ) ;
F_6 ( V_6 , V_72 , ( V_25 [ V_24 ] . V_73 >> 8 ) ) ;
F_6 ( V_6 , V_74 ,
( V_25 [ V_24 ] . V_73 & 0xff ) ) ;
V_64 = F_3 ( V_6 , V_75 ) ;
V_64 &= ~ ( 0x7f ) ;
F_6 ( V_6 , V_75 , V_64 | V_25 [ V_24 ] . V_76 ) ;
V_64 = F_3 ( V_6 , V_77 ) ;
V_64 &= ~ ( 0x7f ) ;
F_6 ( V_6 , V_77 , V_64 | V_25 [ V_24 ] . V_78 ) ;
F_6 ( V_6 , V_79 , V_25 [ V_24 ] . V_80 >> 8 ) ;
F_6 ( V_6 , V_81 ,
( V_25 [ V_24 ] . V_80 & 0xff ) ) ;
V_64 = F_3 ( V_6 , V_82 ) ;
V_64 &= ~ ( 0x7f ) ;
F_6 ( V_6 , V_82 , V_64 | V_25 [ V_24 ] . V_83 ) ;
V_64 = F_3 ( V_6 , V_84 ) ;
V_64 &= ~ ( 0x7f ) ;
F_6 ( V_6 , V_84 , V_64 | V_25 [ V_24 ] . V_85 ) ;
F_6 ( V_6 , V_86 , V_25 [ V_24 ] . V_87 ) ;
V_64 = F_3 ( V_6 , V_88 ) ;
V_64 &= ~ ( 0x7f ) ;
F_6 ( V_6 , V_88 , V_64 | V_25 [ V_24 ] . V_89 ) ;
V_64 = F_3 ( V_6 , V_41 ) ;
V_64 = V_64 & ~ ( 3 << 4 ) ;
switch ( F_18 ( V_62 ) ) {
case 16 :
break;
case 20 :
V_64 |= ( V_90 << V_91 ) ;
break;
case 24 :
V_64 |= ( V_92 << V_91 ) ;
break;
case 32 :
V_64 |= ( V_93 << V_91 ) ;
break;
}
F_6 ( V_6 , V_41 , V_64 ) ;
if ( F_19 ( V_62 ) == 1 ) {
V_64 = V_94 | V_95 ;
} else {
if ( V_32 -> V_96 )
V_64 = V_94 | V_97 ;
else
V_64 = V_95 | V_98 ;
}
F_20 ( V_6 , V_99 , V_100 ,
V_64 ) ;
return 0 ;
}
static int F_21 ( struct V_26 * V_63 , int V_101 )
{
struct V_5 * V_6 = V_63 -> V_6 ;
T_1 V_102 ;
V_102 = F_3 ( V_6 , V_103 ) & ~ V_104 ;
if ( V_101 )
F_6 ( V_6 , V_103 , V_102 | V_104 ) ;
else
F_6 ( V_6 , V_103 , V_102 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
enum V_105 V_106 )
{
struct V_31 * V_32 = F_14 ( V_6 ) ;
int V_107 ;
switch ( V_106 ) {
case V_108 :
V_107 = F_23 ( V_32 -> V_22 ) ;
if ( V_107 ) {
F_24 ( V_6 -> V_109 , L_9 ) ;
return V_107 ;
}
F_20 ( V_6 , V_68 ,
V_110 , V_110 ) ;
F_20 ( V_6 , V_75 ,
V_111 , V_111 ) ;
F_20 ( V_6 , V_77 ,
V_112 , V_112 ) ;
F_20 ( V_6 , V_82 ,
V_113 , V_113 ) ;
F_20 ( V_6 , V_84 ,
V_114 , V_114 ) ;
F_20 ( V_6 , V_88 ,
V_115 , V_115 ) ;
break;
case V_116 :
break;
case V_117 :
F_20 ( V_6 , V_88 ,
V_115 , 0 ) ;
F_20 ( V_6 , V_84 ,
V_114 , 0 ) ;
F_20 ( V_6 , V_82 ,
V_113 , 0 ) ;
F_20 ( V_6 , V_77 ,
V_112 , 0 ) ;
F_20 ( V_6 , V_75 ,
V_111 , 0 ) ;
F_20 ( V_6 , V_68 ,
V_110 , 0 ) ;
F_25 ( V_32 -> V_22 ) ;
break;
case V_118 :
break;
}
return 0 ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_31 * V_32 = F_14 ( V_6 ) ;
if ( V_32 -> V_119 -> V_120 [ 0 ] != V_121 ) {
F_6 ( V_6 , V_8 ,
V_32 -> V_119 -> V_120 [ 0 ] ) ;
F_27 ( V_6 , V_122 ,
F_12 ( V_122 ) ) ;
}
if ( V_32 -> V_119 -> V_120 [ 1 ] != V_121 ) {
F_6 ( V_6 , V_11 ,
V_32 -> V_119 -> V_120 [ 1 ] ) ;
F_27 ( V_6 , V_123 ,
F_12 ( V_123 ) ) ;
}
if ( V_32 -> V_119 -> V_120 [ 2 ] != V_121 ) {
F_6 ( V_6 , V_17 ,
V_32 -> V_119 -> V_120 [ 2 ] ) ;
F_27 ( V_6 , V_124 ,
F_12 ( V_124 ) ) ;
}
if ( V_32 -> V_119 -> V_120 [ 3 ] != V_121 ) {
F_6 ( V_6 , V_18 ,
V_32 -> V_119 -> V_120 [ 3 ] ) ;
F_27 ( V_6 , V_125 ,
F_12 ( V_125 ) ) ;
}
if ( V_32 -> V_119 -> V_120 [ 4 ] != V_121 ) {
F_6 ( V_6 , V_20 ,
V_32 -> V_119 -> V_120 [ 4 ] ) ;
F_27 ( V_6 , V_126 ,
F_12 ( V_126 ) ) ;
}
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_31 * V_32 = F_14 ( V_6 ) ;
T_2 V_127 ;
if ( F_29 ( V_32 -> V_128 ) ) {
F_30 ( 10 ) ;
F_31 ( V_32 -> V_128 , 1 ) ;
}
F_6 ( V_6 , V_129 , 0x01 ) ;
if ( V_32 -> V_119 )
F_26 ( V_6 ) ;
if ( V_32 -> V_130 & V_131 ) {
F_6 ( V_6 , V_132 , V_133 |
V_134 ) ;
}
if ( V_32 -> V_130 & V_135 )
F_6 ( V_6 , V_136 , V_137 ) ;
V_127 = ( V_32 -> V_130 & V_138 ) ?
V_139 : 0 ;
F_6 ( V_6 , V_140 , V_127 ) ;
V_127 = F_3 ( V_6 , V_141 ) ;
if ( V_32 -> V_130 & V_142 )
V_127 |= V_143 ;
if ( V_32 -> V_130 & V_144 )
V_127 |= V_145 ;
F_6 ( V_6 , V_141 , V_127 ) ;
if ( V_32 -> V_146 & V_147 )
F_6 ( V_6 , V_148 ,
V_149 ) ;
else
F_6 ( V_6 , V_148 ,
V_150 ) ;
if ( V_32 -> V_146 & V_151 )
F_6 ( V_6 , V_152 ,
V_153 ) ;
else
F_6 ( V_6 , V_152 ,
V_154 ) ;
V_127 = F_3 ( V_6 , V_155 ) ;
F_6 ( V_6 , V_155 , V_127 |
V_156 | V_157 ) ;
F_6 ( V_6 , V_155 , V_127 ) ;
return 0 ;
}
static int F_32 ( struct V_31 * V_32 ,
struct V_158 * V_159 )
{
struct V_160 * V_161 ;
V_161 = F_33 ( V_32 -> V_109 , sizeof( * V_161 ) ,
V_162 ) ;
if ( ! V_161 )
return - V_163 ;
V_32 -> V_96 = false ;
V_32 -> V_146 = 0 ;
V_32 -> V_128 = F_34 ( V_159 , L_10 , 0 ) ;
if ( F_35 ( V_159 , L_11 ,
V_161 -> V_120 , 5 ) >= 0 )
V_32 -> V_119 = V_161 ;
return 0 ;
}
static void F_36 ( struct V_31 * V_32 )
{
F_37 ( V_32 -> V_164 ) ;
if ( ! F_38 ( V_32 -> V_165 ) )
F_37 ( V_32 -> V_165 ) ;
if ( ! F_38 ( V_32 -> V_166 ) )
F_37 ( V_32 -> V_166 ) ;
if ( ! F_38 ( V_32 -> V_167 ) )
F_37 ( V_32 -> V_167 ) ;
}
static int F_39 ( struct V_168 * V_109 ,
struct V_31 * V_32 )
{
int V_107 = 0 ;
V_32 -> V_165 = F_40 ( V_109 , L_12 ) ;
V_32 -> V_164 = F_41 ( V_109 , L_13 ) ;
V_32 -> V_166 = F_40 ( V_109 , L_14 ) ;
V_32 -> V_167 = F_40 ( V_109 , L_15 ) ;
if ( F_38 ( V_32 -> V_164 ) ) {
F_24 ( V_109 , L_16 ) ;
return F_42 ( V_32 -> V_164 ) ;
}
if ( F_38 ( V_32 -> V_165 ) ) {
if ( F_42 ( V_32 -> V_165 ) == - V_169 )
return - V_169 ;
if ( F_38 ( V_32 -> V_166 ) ) {
F_24 ( V_109 , L_17 ) ;
return F_42 ( V_32 -> V_166 ) ;
}
if ( F_38 ( V_32 -> V_167 ) ) {
F_24 ( V_109 , L_18 ) ;
return F_42 ( V_32 -> V_167 ) ;
}
} else {
if ( F_38 ( V_32 -> V_166 ) &&
F_42 ( V_32 -> V_166 ) == - V_169 )
return - V_169 ;
if ( F_38 ( V_32 -> V_167 ) &&
F_42 ( V_32 -> V_167 ) == - V_169 )
return - V_169 ;
}
V_107 = F_43 ( V_32 -> V_164 ) ;
if ( V_107 ) {
F_24 ( V_109 , L_19 ) ;
return V_107 ;
}
if ( ! F_38 ( V_32 -> V_165 ) ) {
V_107 = F_43 ( V_32 -> V_165 ) ;
if ( V_107 ) {
F_24 ( V_109 , L_20 ) ;
goto V_170;
}
}
if ( ! F_38 ( V_32 -> V_166 ) ) {
V_107 = F_43 ( V_32 -> V_166 ) ;
if ( V_107 ) {
F_24 ( V_109 , L_21 ) ;
goto V_171;
}
}
if ( ! F_38 ( V_32 -> V_167 ) ) {
V_107 = F_43 ( V_32 -> V_167 ) ;
if ( V_107 ) {
F_24 ( V_109 , L_22 ) ;
goto V_172;
}
}
if ( ! F_38 ( V_32 -> V_165 ) && F_38 ( V_32 -> V_167 ) )
V_32 -> V_130 |= V_138 ;
return 0 ;
V_172:
if ( ! F_38 ( V_32 -> V_166 ) )
F_37 ( V_32 -> V_166 ) ;
V_171:
if ( ! F_38 ( V_32 -> V_165 ) )
F_37 ( V_32 -> V_165 ) ;
V_170:
F_37 ( V_32 -> V_164 ) ;
return V_107 ;
}
int F_44 ( struct V_168 * V_109 , struct V_173 * V_173 )
{
struct V_31 * V_32 ;
struct V_174 * V_175 = V_109 -> V_176 ;
struct V_158 * V_159 = V_109 -> V_177 ;
int V_107 ;
if ( F_38 ( V_173 ) )
return F_42 ( V_173 ) ;
V_32 = F_33 ( V_109 , sizeof( struct V_31 ) ,
V_162 ) ;
if ( V_32 == NULL )
return - V_163 ;
V_32 -> V_109 = V_109 ;
F_45 ( V_109 , V_32 ) ;
if ( V_175 ) {
V_32 -> V_130 = V_175 -> V_130 ;
V_32 -> V_96 = V_175 -> V_96 ;
V_32 -> V_146 = V_175 -> V_146 ;
V_32 -> V_128 = V_175 -> V_128 ;
} else if ( V_159 ) {
V_107 = F_32 ( V_32 , V_159 ) ;
if ( V_107 ) {
F_24 ( V_109 , L_23 ) ;
return V_107 ;
}
} else {
V_32 -> V_130 = 0 ;
V_32 -> V_96 = false ;
V_32 -> V_146 = 0 ;
V_32 -> V_128 = - 1 ;
}
V_32 -> V_22 = F_46 ( V_109 , L_24 ) ;
if ( F_38 ( V_32 -> V_22 ) ) {
F_24 ( V_109 , L_25 ) ;
return F_42 ( V_32 -> V_22 ) ;
}
if ( F_29 ( V_32 -> V_128 ) ) {
V_107 = F_47 ( V_109 , V_32 -> V_128 ,
V_178 , L_26 ) ;
if ( V_107 != 0 )
return V_107 ;
}
V_107 = F_39 ( V_109 , V_32 ) ;
if ( V_107 ) {
F_24 ( V_109 , L_27 ) ;
return V_107 ;
}
V_107 = F_48 ( V_109 ,
& V_179 , & V_180 , 1 ) ;
if ( V_107 ) {
F_24 ( V_109 , L_28 ) ;
F_36 ( V_32 ) ;
return V_107 ;
}
return 0 ;
}
int F_49 ( struct V_168 * V_109 )
{
struct V_31 * V_32 = F_50 ( V_109 ) ;
F_36 ( V_32 ) ;
F_51 ( V_109 ) ;
return 0 ;
}
