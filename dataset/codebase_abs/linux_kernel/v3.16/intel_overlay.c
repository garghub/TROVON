static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_1 T_1 * V_8 ;
if ( F_2 ( V_3 -> V_6 ) )
V_8 = (struct V_1 T_1 * ) V_3 -> V_9 -> V_10 -> V_11 ;
else
V_8 = F_3 ( V_5 -> V_12 . V_13 ,
F_4 ( V_3 -> V_9 ) ) ;
return V_8 ;
}
static void F_5 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_6 ( V_8 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
void (* F_8)( struct V_2 * ) )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
int V_18 ;
F_9 ( V_3 -> V_19 ) ;
V_18 = F_10 ( V_16 , & V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
V_3 -> V_20 = F_8 ;
V_18 = F_11 ( V_16 , V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
F_12 ( V_6 ) ;
V_3 -> V_19 = 0 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
int V_18 ;
F_9 ( V_3 -> V_21 ) ;
V_3 -> V_21 = 1 ;
F_14 ( F_15 ( V_6 ) && ! ( V_5 -> V_22 & V_23 ) ) ;
V_18 = F_16 ( V_16 , 4 ) ;
if ( V_18 )
return V_18 ;
F_17 ( V_16 , V_24 | V_25 ) ;
F_17 ( V_16 , V_3 -> V_26 | V_27 ) ;
F_17 ( V_16 , V_28 | V_29 ) ;
F_17 ( V_16 , V_30 ) ;
F_18 ( V_16 ) ;
return F_7 ( V_3 , NULL ) ;
}
static int F_19 ( struct V_2 * V_3 ,
bool V_31 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
T_2 V_26 = V_3 -> V_26 ;
T_2 V_32 ;
int V_18 ;
F_9 ( ! V_3 -> V_21 ) ;
if ( V_31 )
V_26 |= V_27 ;
V_32 = F_20 ( V_33 ) ;
if ( V_32 & ( 1 << 17 ) )
F_21 ( L_1 , V_32 ) ;
V_18 = F_16 ( V_16 , 2 ) ;
if ( V_18 )
return V_18 ;
F_17 ( V_16 , V_24 | V_34 ) ;
F_17 ( V_16 , V_26 ) ;
F_18 ( V_16 ) ;
return F_10 ( V_16 , & V_3 -> V_19 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_35 * V_36 = V_3 -> V_37 ;
F_23 ( V_36 ) ;
F_24 ( & V_36 -> V_38 ) ;
V_3 -> V_37 = NULL ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_35 * V_36 = V_3 -> V_39 ;
F_9 ( ! V_3 -> V_39 ) ;
F_23 ( V_36 ) ;
F_24 ( & V_36 -> V_38 ) ;
V_3 -> V_39 = NULL ;
V_3 -> V_40 -> V_3 = NULL ;
V_3 -> V_40 = NULL ;
V_3 -> V_21 = 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
T_2 V_26 = V_3 -> V_26 ;
int V_18 ;
F_9 ( ! V_3 -> V_21 ) ;
V_26 |= V_27 ;
V_18 = F_16 ( V_16 , 6 ) ;
if ( V_18 )
return V_18 ;
F_17 ( V_16 , V_24 | V_34 ) ;
F_17 ( V_16 , V_26 ) ;
F_17 ( V_16 , V_28 | V_29 ) ;
if ( F_15 ( V_6 ) ) {
F_17 ( V_16 , V_30 ) ;
F_17 ( V_16 , V_30 ) ;
F_17 ( V_16 , V_30 ) ;
} else {
F_17 ( V_16 , V_24 | V_41 ) ;
F_17 ( V_16 , V_26 ) ;
F_17 ( V_16 , V_28 | V_29 ) ;
}
F_18 ( V_16 ) ;
return F_7 ( V_3 , F_25 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
int V_18 ;
if ( V_3 -> V_19 == 0 )
return 0 ;
V_18 = F_11 ( V_16 , V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
F_12 ( V_6 ) ;
if ( V_3 -> V_20 )
V_3 -> V_20 ( V_3 ) ;
V_3 -> V_19 = 0 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
int V_18 ;
if ( ! V_3 -> V_37 )
return 0 ;
if ( F_20 ( V_42 ) & V_43 ) {
V_18 = F_16 ( V_16 , 2 ) ;
if ( V_18 )
return V_18 ;
F_17 ( V_16 , V_28 | V_29 ) ;
F_17 ( V_16 , V_30 ) ;
F_18 ( V_16 ) ;
V_18 = F_7 ( V_3 ,
F_22 ) ;
if ( V_18 )
return V_18 ;
}
F_22 ( V_3 ) ;
return 0 ;
}
static int F_29 ( T_2 V_44 )
{
switch ( V_44 & V_45 ) {
case V_46 :
return 4 ;
case V_47 :
default:
return - V_48 ;
}
}
static int F_30 ( T_2 V_44 , short V_49 )
{
switch ( V_44 & V_45 ) {
case V_46 :
return V_49 << 1 ;
default:
return - V_48 ;
}
}
static int F_31 ( T_2 V_44 )
{
switch ( V_44 & V_45 ) {
case V_46 :
case V_50 :
return 2 ;
case V_47 :
case V_51 :
return 4 ;
default:
return - V_48 ;
}
}
static int F_32 ( T_2 V_44 )
{
switch ( V_44 & V_45 ) {
case V_50 :
case V_51 :
return 2 ;
case V_46 :
case V_47 :
return 1 ;
default:
return - V_48 ;
}
}
static T_2 F_33 ( struct V_14 * V_6 , T_2 V_52 , T_2 V_49 )
{
T_2 V_53 , V_54 , V_18 ;
if ( F_34 ( V_6 ) ) {
V_53 = 0x1f ;
V_54 = 5 ;
} else {
V_53 = 0x3f ;
V_54 = 6 ;
}
V_18 = ( ( V_52 + V_49 + V_53 ) >> V_54 ) - ( V_52 >> V_54 ) ;
if ( ! F_34 ( V_6 ) )
V_18 <<= 1 ;
V_18 -= 1 ;
return V_18 << 2 ;
}
static void F_35 ( struct V_1 T_1 * V_8 )
{
F_36 ( V_8 -> V_55 , V_56 , sizeof( V_56 ) ) ;
F_36 ( V_8 -> V_57 , V_58 ,
sizeof( V_58 ) ) ;
}
static bool F_37 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 ,
struct V_59 * V_60 )
{
T_2 V_61 , V_62 , V_63 , V_64 ;
#define F_38 12
#define F_39 0xfff
bool V_65 = false ;
int V_66 = F_31 ( V_60 -> V_44 ) ;
int V_67 = F_32 ( V_60 -> V_44 ) ;
if ( V_60 -> V_68 > 1 )
V_61 = ( ( V_60 -> V_69 - 1 ) << F_38 )
/ ( V_60 -> V_68 ) ;
else
V_61 = 1 << F_38 ;
if ( V_60 -> V_70 > 1 )
V_62 = ( ( V_60 -> V_71 - 1 ) << F_38 )
/ ( V_60 -> V_70 ) ;
else
V_62 = 1 << F_38 ;
V_63 = V_61 / V_66 ;
V_64 = V_62 / V_67 ;
V_61 = V_63 * V_66 ;
V_62 = V_64 * V_67 ;
if ( V_61 != V_3 -> V_72 || V_62 != V_3 -> V_73 )
V_65 = true ;
V_3 -> V_72 = V_61 ;
V_3 -> V_73 = V_62 ;
F_40 ( ( ( V_62 & F_39 ) << 20 ) |
( ( V_61 >> F_38 ) << 16 ) |
( ( V_61 & F_39 ) << 3 ) ,
& V_8 -> V_74 ) ;
F_40 ( ( ( V_64 & F_39 ) << 20 ) |
( ( V_63 >> F_38 ) << 16 ) |
( ( V_63 & F_39 ) << 3 ) ,
& V_8 -> V_75 ) ;
F_40 ( ( ( ( V_62 >> F_38 ) << 16 ) |
( ( V_64 >> F_38 ) << 0 ) ) ,
& V_8 -> V_76 ) ;
if ( V_65 )
F_35 ( V_8 ) ;
return V_65 ;
}
static void F_41 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
T_2 V_77 = V_3 -> V_78 ;
switch ( V_3 -> V_40 -> V_38 . V_79 -> V_80 -> V_81 ) {
case 8 :
F_40 ( 0 , & V_8 -> V_82 ) ;
F_40 ( V_83 | V_84 , & V_8 -> V_85 ) ;
break;
case 16 :
if ( V_3 -> V_40 -> V_38 . V_79 -> V_80 -> V_86 == 15 ) {
F_40 ( F_42 ( V_77 ) , & V_8 -> V_82 ) ;
F_40 ( V_87 | V_84 ,
& V_8 -> V_85 ) ;
} else {
F_40 ( F_43 ( V_77 ) , & V_8 -> V_82 ) ;
F_40 ( V_88 | V_84 ,
& V_8 -> V_85 ) ;
}
break;
case 24 :
case 32 :
F_40 ( V_77 , & V_8 -> V_82 ) ;
F_40 ( V_89 | V_84 , & V_8 -> V_85 ) ;
break;
}
}
static T_2 F_44 ( struct V_59 * V_60 )
{
T_2 V_90 = V_91 | V_92 | V_93 ;
if ( V_60 -> V_44 & V_94 ) {
switch ( V_60 -> V_44 & V_45 ) {
case V_46 :
V_90 |= V_95 ;
break;
case V_50 :
V_90 |= V_96 ;
break;
case V_47 :
case V_51 :
V_90 |= V_97 ;
break;
}
} else {
switch ( V_60 -> V_44 & V_45 ) {
case V_46 :
V_90 |= V_98 ;
break;
case V_47 :
V_90 |= V_99 ;
break;
}
switch ( V_60 -> V_44 & V_100 ) {
case V_101 :
break;
case V_102 :
V_90 |= V_103 ;
break;
case V_104 :
V_90 |= V_105 ;
break;
case V_106 :
V_90 |= V_107 ;
break;
}
}
return V_90 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_35 * V_108 ,
struct V_59 * V_60 )
{
int V_18 , V_109 ;
struct V_1 T_1 * V_8 ;
bool V_65 = false ;
struct V_14 * V_6 = V_3 -> V_6 ;
T_2 V_110 , V_111 , V_112 , V_113 ;
F_9 ( ! F_46 ( & V_6 -> V_114 ) ) ;
F_9 ( ! F_47 ( & V_6 -> V_115 . V_116 ) ) ;
F_9 ( ! V_3 ) ;
V_18 = F_28 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_48 ( V_108 , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_49 ( V_108 ) ;
if ( V_18 )
goto V_117;
if ( ! V_3 -> V_21 ) {
T_2 V_118 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_119 ;
goto V_117;
}
V_118 = V_120 ;
if ( F_50 ( V_3 -> V_6 ) )
V_118 |= V_121 ;
V_118 |= V_3 -> V_40 -> V_122 == 0 ?
V_123 : V_124 ;
F_40 ( V_118 , & V_8 -> V_125 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_13 ( V_3 ) ;
if ( V_18 != 0 )
goto V_117;
}
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_119 ;
goto V_117;
}
F_40 ( ( V_60 -> V_126 << 16 ) | V_60 -> V_127 , & V_8 -> V_128 ) ;
F_40 ( ( V_60 -> V_70 << 16 ) | V_60 -> V_68 , & V_8 -> V_129 ) ;
if ( V_60 -> V_44 & V_130 )
V_109 = F_30 ( V_60 -> V_44 , V_60 -> V_131 ) ;
else
V_109 = V_60 -> V_131 ;
V_110 = V_60 -> V_131 ;
V_111 = F_33 ( V_3 -> V_6 , V_60 -> V_132 , V_109 ) ;
V_112 = V_60 -> V_133 ;
F_40 ( F_4 ( V_108 ) + V_60 -> V_132 , & V_8 -> V_134 ) ;
V_113 = V_60 -> V_135 ;
if ( V_60 -> V_44 & V_94 ) {
int V_66 = F_31 ( V_60 -> V_44 ) ;
int V_67 = F_32 ( V_60 -> V_44 ) ;
T_2 V_136 , V_137 ;
V_110 |= ( V_60 -> V_131 / V_66 ) << 16 ;
V_136 = F_33 ( V_3 -> V_6 , V_60 -> V_138 ,
V_60 -> V_131 / V_66 ) ;
V_137 = F_33 ( V_3 -> V_6 , V_60 -> V_139 ,
V_60 -> V_131 / V_66 ) ;
V_111 |= F_51 ( T_2 , V_136 , V_137 ) << 16 ;
V_112 |= ( V_60 -> V_133 / V_67 ) << 16 ;
F_40 ( F_4 ( V_108 ) + V_60 -> V_138 , & V_8 -> V_140 ) ;
F_40 ( F_4 ( V_108 ) + V_60 -> V_139 , & V_8 -> V_141 ) ;
V_113 |= V_60 -> V_142 << 16 ;
}
F_40 ( V_110 , & V_8 -> V_143 ) ;
F_40 ( V_111 , & V_8 -> V_144 ) ;
F_40 ( V_112 , & V_8 -> V_145 ) ;
F_40 ( V_113 , & V_8 -> V_146 ) ;
V_65 = F_37 ( V_3 , V_8 , V_60 ) ;
F_41 ( V_3 , V_8 ) ;
F_40 ( F_44 ( V_60 ) , & V_8 -> V_147 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_19 ( V_3 , V_65 ) ;
if ( V_18 )
goto V_117;
V_3 -> V_37 = V_3 -> V_39 ;
V_3 -> V_39 = V_108 ;
return 0 ;
V_117:
F_23 ( V_108 ) ;
return V_18 ;
}
int F_52 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_8 ;
struct V_14 * V_6 = V_3 -> V_6 ;
int V_18 ;
F_9 ( ! F_46 ( & V_6 -> V_114 ) ) ;
F_9 ( ! F_47 ( & V_6 -> V_115 . V_116 ) ) ;
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( ! V_3 -> V_21 )
return 0 ;
V_18 = F_28 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_8 = F_1 ( V_3 ) ;
F_40 ( 0 , & V_8 -> V_147 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_26 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
F_25 ( V_3 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_148 * V_40 )
{
if ( ! V_40 -> V_21 )
return - V_48 ;
if ( V_40 -> V_149 . V_150 )
return - V_48 ;
return 0 ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_151 = F_20 ( V_152 ) ;
T_2 V_153 ;
if ( F_55 ( V_6 ) -> V_154 >= 4 ) {
V_153 = F_20 ( V_155 ) >> V_156 ;
} else {
if ( V_151 & V_157 )
V_153 = F_20 ( V_158 ) ;
else
V_153 = F_20 ( V_155 ) ;
V_153 >>= V_159 ;
}
V_3 -> V_160 = V_153 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_161 * V_162 )
{
struct V_163 * V_164 = & V_3 -> V_40 -> V_38 . V_164 ;
if ( V_162 -> V_127 < V_164 -> V_165 &&
V_162 -> V_127 + V_162 -> V_166 <= V_164 -> V_165 &&
V_162 -> V_126 < V_164 -> V_167 &&
V_162 -> V_126 + V_162 -> V_168 <= V_164 -> V_167 )
return 0 ;
else
return - V_48 ;
}
static int F_57 ( struct V_59 * V_162 )
{
T_2 V_32 ;
V_32 = ( ( V_162 -> V_71 << 16 ) / V_162 -> V_70 ) >> 16 ;
if ( V_32 > 7 )
return - V_48 ;
V_32 = ( ( V_162 -> V_69 << 16 ) / V_162 -> V_68 ) >> 16 ;
if ( V_32 > 7 )
return - V_48 ;
return 0 ;
}
static int F_58 ( struct V_14 * V_6 ,
struct V_161 * V_162 ,
struct V_35 * V_108 )
{
int V_66 = F_31 ( V_162 -> V_169 ) ;
int V_67 = F_32 ( V_162 -> V_169 ) ;
T_2 V_170 ;
int V_86 ;
T_2 V_32 ;
if ( F_59 ( V_6 ) || F_15 ( V_6 ) ) {
if ( V_162 -> V_171 > V_172 ||
V_162 -> V_173 > V_174 )
return - V_48 ;
} else {
if ( V_162 -> V_171 > V_175 ||
V_162 -> V_173 > V_176 )
return - V_48 ;
}
if ( V_162 -> V_171 < V_177 * 4 ||
V_162 -> V_173 < V_178 * 4 )
return - V_48 ;
switch ( V_162 -> V_169 & V_179 ) {
case V_180 :
return - V_48 ;
case V_130 :
if ( V_67 != 1 )
return - V_48 ;
V_86 = F_29 ( V_162 -> V_169 ) ;
if ( V_86 < 0 )
return V_86 ;
V_162 -> V_142 = 0 ;
V_162 -> V_138 = 0 ;
V_162 -> V_139 = 0 ;
if ( V_162 -> V_132 % V_86 )
return - V_48 ;
break;
case V_94 :
if ( V_67 < 0 || V_66 < 0 )
return - V_48 ;
break;
default:
return - V_48 ;
}
if ( V_162 -> V_173 % V_66 )
return - V_48 ;
if ( F_15 ( V_6 ) || F_59 ( V_6 ) )
V_170 = 255 ;
else
V_170 = 63 ;
if ( V_162 -> V_135 & V_170 || V_162 -> V_142 & V_170 )
return - V_48 ;
if ( F_50 ( V_6 ) && V_162 -> V_135 < 512 )
return - V_48 ;
V_32 = ( V_162 -> V_169 & V_179 ) == V_94 ?
4096 : 8192 ;
if ( V_162 -> V_135 > V_32 || V_162 -> V_142 > 2 * 1024 )
return - V_48 ;
switch ( V_162 -> V_169 & V_179 ) {
case V_180 :
case V_130 :
if ( F_30 ( V_162 -> V_169 , V_162 -> V_173 ) > V_162 -> V_135 )
return - V_48 ;
V_32 = V_162 -> V_135 * V_162 -> V_171 ;
if ( V_162 -> V_132 + V_32 > V_108 -> V_38 . V_181 )
return - V_48 ;
break;
case V_94 :
if ( V_162 -> V_173 > V_162 -> V_135 )
return - V_48 ;
if ( V_162 -> V_173 / V_66 > V_162 -> V_142 )
return - V_48 ;
V_32 = V_162 -> V_135 * V_162 -> V_171 ;
if ( V_162 -> V_132 + V_32 > V_108 -> V_38 . V_181 )
return - V_48 ;
V_32 = V_162 -> V_142 * ( V_162 -> V_171 / V_67 ) ;
if ( V_162 -> V_138 + V_32 > V_108 -> V_38 . V_181 ||
V_162 -> V_139 + V_32 > V_108 -> V_38 . V_181 )
return - V_48 ;
break;
}
return 0 ;
}
static int F_60 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_151 ;
if ( F_55 ( V_6 ) -> V_154 <= 3 && ( F_15 ( V_6 ) || ! F_61 ( V_6 ) ) )
return - 1 ;
V_151 = F_20 ( V_152 ) ;
if ( ( V_151 & V_182 ) == 0 )
return - 1 ;
if ( F_50 ( V_6 ) )
return ( V_151 >> 29 ) & 0x3 ;
return 1 ;
}
int F_62 ( struct V_14 * V_6 , void * V_183 ,
struct V_184 * V_185 )
{
struct V_161 * V_186 = V_183 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_187 * V_188 ;
struct V_148 * V_40 ;
struct V_35 * V_108 ;
struct V_59 * V_60 ;
int V_18 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_21 ( L_2 ) ;
return - V_189 ;
}
if ( ! ( V_186 -> V_169 & V_190 ) ) {
F_63 ( V_6 ) ;
F_64 ( & V_6 -> V_114 ) ;
V_18 = F_52 ( V_3 ) ;
F_65 ( & V_6 -> V_114 ) ;
F_66 ( V_6 ) ;
return V_18 ;
}
V_60 = F_67 ( sizeof( * V_60 ) , V_191 ) ;
if ( ! V_60 )
return - V_119 ;
V_188 = F_68 ( V_6 , V_186 -> V_192 ,
V_193 ) ;
if ( ! V_188 ) {
V_18 = - V_194 ;
goto V_195;
}
V_40 = F_69 ( F_70 ( V_188 ) ) ;
V_108 = F_71 ( F_72 ( V_6 , V_185 ,
V_186 -> V_196 ) ) ;
if ( & V_108 -> V_38 == NULL ) {
V_18 = - V_194 ;
goto V_195;
}
F_63 ( V_6 ) ;
F_64 ( & V_6 -> V_114 ) ;
if ( V_108 -> V_197 ) {
F_73 ( L_3 ) ;
V_18 = - V_48 ;
goto V_198;
}
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
goto V_198;
if ( V_3 -> V_40 != V_40 ) {
struct V_163 * V_164 = & V_40 -> V_38 . V_164 ;
V_18 = F_52 ( V_3 ) ;
if ( V_18 != 0 )
goto V_198;
V_18 = F_53 ( V_3 , V_40 ) ;
if ( V_18 != 0 )
goto V_198;
V_3 -> V_40 = V_40 ;
V_40 -> V_3 = V_3 ;
if ( V_164 -> V_165 > 1024 &&
F_60 ( V_6 ) == V_40 -> V_122 ) {
V_3 -> V_199 = 1 ;
F_54 ( V_3 ) ;
} else
V_3 -> V_199 = 0 ;
}
V_18 = F_56 ( V_3 , V_186 ) ;
if ( V_18 != 0 )
goto V_198;
if ( V_3 -> V_199 ) {
V_60 -> V_126 = ( ( ( ( T_2 ) V_186 -> V_126 ) << 12 ) /
V_3 -> V_160 ) ;
V_60 -> V_70 = ( ( ( ( T_2 ) V_186 -> V_168 ) << 12 ) /
V_3 -> V_160 ) + 1 ;
} else {
V_60 -> V_126 = V_186 -> V_126 ;
V_60 -> V_70 = V_186 -> V_168 ;
}
V_60 -> V_127 = V_186 -> V_127 ;
V_60 -> V_68 = V_186 -> V_166 ;
V_60 -> V_131 = V_186 -> V_173 ;
V_60 -> V_133 = V_186 -> V_171 ;
V_60 -> V_69 = V_186 -> V_200 ;
V_60 -> V_71 = V_186 -> V_201 ;
if ( V_60 -> V_71 > V_60 -> V_133 ||
V_60 -> V_69 > V_60 -> V_131 ) {
V_18 = - V_48 ;
goto V_198;
}
V_18 = F_58 ( V_6 , V_186 , V_108 ) ;
if ( V_18 != 0 )
goto V_198;
V_60 -> V_44 = V_186 -> V_169 & ~ V_202 ;
V_60 -> V_135 = V_186 -> V_135 ;
V_60 -> V_142 = V_186 -> V_142 ;
V_60 -> V_132 = V_186 -> V_132 ;
V_60 -> V_138 = V_186 -> V_138 ;
V_60 -> V_139 = V_186 -> V_139 ;
V_18 = F_57 ( V_60 ) ;
if ( V_18 != 0 )
goto V_198;
V_18 = F_45 ( V_3 , V_108 , V_60 ) ;
if ( V_18 != 0 )
goto V_198;
F_65 ( & V_6 -> V_114 ) ;
F_66 ( V_6 ) ;
F_74 ( V_60 ) ;
return 0 ;
V_198:
F_65 ( & V_6 -> V_114 ) ;
F_66 ( V_6 ) ;
F_75 ( & V_108 -> V_38 ) ;
V_195:
F_74 ( V_60 ) ;
return V_18 ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
F_40 ( ( V_3 -> V_203 << 18 ) | ( V_3 -> V_204 & 0xff ) ,
& V_8 -> V_205 ) ;
F_40 ( V_3 -> V_206 , & V_8 -> V_207 ) ;
}
static bool F_77 ( T_2 V_208 , T_2 V_209 )
{
int V_210 ;
if ( V_208 & 0xff000000 || V_209 & 0xff000000 )
return false ;
for ( V_210 = 0 ; V_210 < 3 ; V_210 ++ ) {
if ( ( ( V_208 >> V_210 * 8 ) & 0xff ) >= ( ( V_209 >> V_210 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_78 ( T_2 V_211 )
{
int V_210 ;
for ( V_210 = 0 ; V_210 < 3 ; V_210 ++ ) {
if ( ( ( V_211 >> V_210 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_79 ( struct V_212 * V_213 )
{
if ( ! F_77 ( 0 , V_213 -> V_214 ) ||
! F_77 ( V_213 -> V_214 , V_213 -> V_208 ) ||
! F_77 ( V_213 -> V_208 , V_213 -> V_209 ) ||
! F_77 ( V_213 -> V_209 , V_213 -> V_215 ) ||
! F_77 ( V_213 -> V_215 , V_213 -> V_216 ) ||
! F_77 ( V_213 -> V_216 , V_213 -> V_211 ) ||
! F_77 ( V_213 -> V_211 , 0x00ffffff ) )
return - V_48 ;
if ( ! F_78 ( V_213 -> V_211 ) )
return - V_48 ;
return 0 ;
}
int F_80 ( struct V_14 * V_6 , void * V_183 ,
struct V_184 * V_185 )
{
struct V_212 * V_213 = V_183 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_8 ;
int V_18 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_21 ( L_2 ) ;
return - V_189 ;
}
F_63 ( V_6 ) ;
F_64 ( & V_6 -> V_114 ) ;
V_18 = - V_48 ;
if ( ! ( V_213 -> V_169 & V_217 ) ) {
V_213 -> V_78 = V_3 -> V_78 ;
V_213 -> V_204 = V_3 -> V_204 ;
V_213 -> V_203 = V_3 -> V_203 ;
V_213 -> V_206 = V_3 -> V_206 ;
if ( ! F_34 ( V_6 ) ) {
V_213 -> V_214 = F_20 ( V_218 ) ;
V_213 -> V_208 = F_20 ( V_219 ) ;
V_213 -> V_209 = F_20 ( V_220 ) ;
V_213 -> V_215 = F_20 ( V_221 ) ;
V_213 -> V_216 = F_20 ( V_222 ) ;
V_213 -> V_211 = F_20 ( V_223 ) ;
}
} else {
if ( V_213 -> V_204 < - 128 || V_213 -> V_204 > 127 )
goto V_198;
if ( V_213 -> V_203 > 255 )
goto V_198;
if ( V_213 -> V_206 > 1023 )
goto V_198;
V_3 -> V_78 = V_213 -> V_78 ;
V_3 -> V_204 = V_213 -> V_204 ;
V_3 -> V_203 = V_213 -> V_203 ;
V_3 -> V_206 = V_213 -> V_206 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_119 ;
goto V_198;
}
F_76 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
if ( V_213 -> V_169 & V_224 ) {
if ( F_34 ( V_6 ) )
goto V_198;
if ( V_3 -> V_21 ) {
V_18 = - V_225 ;
goto V_198;
}
V_18 = F_79 ( V_213 ) ;
if ( V_18 )
goto V_198;
F_81 ( V_218 , V_213 -> V_214 ) ;
F_81 ( V_219 , V_213 -> V_208 ) ;
F_81 ( V_220 , V_213 -> V_209 ) ;
F_81 ( V_221 , V_213 -> V_215 ) ;
F_81 ( V_222 , V_213 -> V_216 ) ;
F_81 ( V_223 , V_213 -> V_211 ) ;
}
}
V_18 = 0 ;
V_198:
F_65 ( & V_6 -> V_114 ) ;
F_66 ( V_6 ) ;
return V_18 ;
}
void F_82 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_35 * V_9 ;
struct V_1 T_1 * V_8 ;
int V_18 ;
if ( ! F_83 ( V_6 ) )
return;
V_3 = F_84 ( sizeof( * V_3 ) , V_191 ) ;
if ( ! V_3 )
return;
F_64 ( & V_6 -> V_114 ) ;
if ( F_14 ( V_5 -> V_3 ) )
goto V_195;
V_3 -> V_6 = V_6 ;
V_9 = NULL ;
if ( ! F_2 ( V_6 ) )
V_9 = F_85 ( V_6 , V_226 ) ;
if ( V_9 == NULL )
V_9 = F_86 ( V_6 , V_226 ) ;
if ( V_9 == NULL )
goto V_195;
V_3 -> V_9 = V_9 ;
if ( F_2 ( V_6 ) ) {
V_18 = F_87 ( V_9 , V_226 ) ;
if ( V_18 ) {
F_88 ( L_4 ) ;
goto V_227;
}
V_3 -> V_26 = V_9 -> V_10 -> V_228 ;
} else {
V_18 = F_89 ( V_9 , V_226 , V_229 ) ;
if ( V_18 ) {
F_88 ( L_5 ) ;
goto V_227;
}
V_3 -> V_26 = F_4 ( V_9 ) ;
V_18 = F_90 ( V_9 , true ) ;
if ( V_18 ) {
F_88 ( L_6 ) ;
goto V_230;
}
}
V_3 -> V_78 = 0x0101fe ;
V_3 -> V_204 = - 19 ;
V_3 -> V_203 = 75 ;
V_3 -> V_206 = 146 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
goto V_230;
F_91 ( V_8 , 0 , sizeof( struct V_1 ) ) ;
F_35 ( V_8 ) ;
F_76 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
V_5 -> V_3 = V_3 ;
F_65 ( & V_6 -> V_114 ) ;
F_92 ( L_7 ) ;
return;
V_230:
if ( ! F_2 ( V_6 ) )
F_23 ( V_9 ) ;
V_227:
F_24 ( & V_9 -> V_38 ) ;
V_195:
F_65 ( & V_6 -> V_114 ) ;
F_74 ( V_3 ) ;
return;
}
void F_93 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
if ( ! V_5 -> V_3 )
return;
F_9 ( V_5 -> V_3 -> V_21 ) ;
F_75 ( & V_5 -> V_3 -> V_9 -> V_38 ) ;
F_74 ( V_5 -> V_3 ) ;
}
static struct V_1 T_1 *
F_94 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_1 T_1 * V_8 ;
if ( F_2 ( V_3 -> V_6 ) )
V_8 = (struct V_1 T_1 * )
V_3 -> V_9 -> V_10 -> V_11 ;
else
V_8 = F_95 ( V_5 -> V_12 . V_13 ,
F_4 ( V_3 -> V_9 ) ) ;
return V_8 ;
}
static void F_96 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_97 ( V_8 ) ;
}
struct V_231 *
F_98 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_231 * error ;
struct V_1 T_1 * V_8 ;
if ( ! V_3 || ! V_3 -> V_21 )
return NULL ;
error = F_67 ( sizeof( * error ) , V_232 ) ;
if ( error == NULL )
return NULL ;
error -> V_233 = F_20 ( V_33 ) ;
error -> V_234 = F_20 ( V_42 ) ;
if ( F_2 ( V_3 -> V_6 ) )
error -> V_38 = ( V_235 long ) V_3 -> V_9 -> V_10 -> V_11 ;
else
error -> V_38 = F_4 ( V_3 -> V_9 ) ;
V_8 = F_94 ( V_3 ) ;
if ( ! V_8 )
goto V_236;
F_99 ( & error -> V_8 , V_8 , sizeof( struct V_1 ) ) ;
F_96 ( V_3 , V_8 ) ;
return error ;
V_236:
F_74 ( error ) ;
return NULL ;
}
void
F_100 ( struct V_237 * V_238 ,
struct V_231 * error )
{
F_101 ( V_238 , L_8 ,
error -> V_233 , error -> V_234 ) ;
F_101 ( V_238 , L_9 ,
error -> V_38 ) ;
#define F_102 ( T_3 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_102 ( V_134 ) ;
F_102 ( V_239 ) ;
F_102 ( V_140 ) ;
F_102 ( V_141 ) ;
F_102 ( V_240 ) ;
F_102 ( V_241 ) ;
F_102 ( V_146 ) ;
F_102 ( V_242 ) ;
F_102 ( V_243 ) ;
F_102 ( V_244 ) ;
F_102 ( V_245 ) ;
F_102 ( V_128 ) ;
F_102 ( V_129 ) ;
F_102 ( V_143 ) ;
F_102 ( V_144 ) ;
F_102 ( V_145 ) ;
F_102 ( V_74 ) ;
F_102 ( V_75 ) ;
F_102 ( V_205 ) ;
F_102 ( V_207 ) ;
F_102 ( V_82 ) ;
F_102 ( V_85 ) ;
F_102 ( V_246 ) ;
F_102 ( V_247 ) ;
F_102 ( V_248 ) ;
F_102 ( V_125 ) ;
F_102 ( V_147 ) ;
F_102 ( V_249 ) ;
F_102 ( V_250 ) ;
F_102 ( V_251 ) ;
F_102 ( V_252 ) ;
F_102 ( V_253 ) ;
F_102 ( V_254 ) ;
F_102 ( V_255 ) ;
F_102 ( V_256 ) ;
F_102 ( V_257 ) ;
F_102 ( V_258 ) ;
F_102 ( V_259 ) ;
F_102 ( V_260 ) ;
F_102 ( V_261 ) ;
F_102 ( V_76 ) ;
#undef F_102
}
