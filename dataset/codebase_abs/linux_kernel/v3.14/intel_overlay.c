static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
T_2 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = (struct V_1 T_1 * ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_3 ( V_4 -> V_12 . V_13 ,
F_4 ( V_3 -> V_8 ) ) ;
return V_7 ;
}
static void F_5 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_6 ( V_7 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
void (* F_8)( struct V_2 * ) )
{
struct V_14 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 = & V_4 -> V_16 [ V_17 ] ;
int V_18 ;
F_9 ( V_3 -> V_19 ) ;
V_18 = F_10 ( V_16 , & V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
V_3 -> V_20 = F_8 ;
V_18 = F_11 ( V_16 , V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
F_12 ( V_5 ) ;
V_3 -> V_19 = 0 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_14 * V_5 = V_3 -> V_5 ;
struct V_21 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 = & V_4 -> V_16 [ V_17 ] ;
int V_18 ;
F_9 ( V_3 -> V_22 ) ;
V_3 -> V_22 = 1 ;
F_14 ( F_15 ( V_5 ) && ! ( V_4 -> V_23 & V_24 ) ) ;
V_18 = F_16 ( V_16 , 4 ) ;
if ( V_18 )
return V_18 ;
F_17 ( V_16 , V_25 | V_26 ) ;
F_17 ( V_16 , V_3 -> V_27 | V_28 ) ;
F_17 ( V_16 , V_29 | V_30 ) ;
F_17 ( V_16 , V_31 ) ;
F_18 ( V_16 ) ;
return F_7 ( V_3 , NULL ) ;
}
static int F_19 ( struct V_2 * V_3 ,
bool V_32 )
{
struct V_14 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 = & V_4 -> V_16 [ V_17 ] ;
T_3 V_27 = V_3 -> V_27 ;
T_3 V_33 ;
int V_18 ;
F_9 ( ! V_3 -> V_22 ) ;
if ( V_32 )
V_27 |= V_28 ;
V_33 = F_20 ( V_34 ) ;
if ( V_33 & ( 1 << 17 ) )
F_21 ( L_1 , V_33 ) ;
V_18 = F_16 ( V_16 , 2 ) ;
if ( V_18 )
return V_18 ;
F_17 ( V_16 , V_25 | V_35 ) ;
F_17 ( V_16 , V_27 ) ;
F_18 ( V_16 ) ;
return F_10 ( V_16 , & V_3 -> V_19 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_38 ;
F_23 ( V_37 ) ;
F_24 ( & V_37 -> V_39 ) ;
V_3 -> V_38 = NULL ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_40 ;
F_9 ( ! V_3 -> V_40 ) ;
F_23 ( V_37 ) ;
F_24 ( & V_37 -> V_39 ) ;
V_3 -> V_40 = NULL ;
V_3 -> V_41 -> V_3 = NULL ;
V_3 -> V_41 = NULL ;
V_3 -> V_22 = 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_14 * V_5 = V_3 -> V_5 ;
struct V_21 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 = & V_4 -> V_16 [ V_17 ] ;
T_3 V_27 = V_3 -> V_27 ;
int V_18 ;
F_9 ( ! V_3 -> V_22 ) ;
V_27 |= V_28 ;
V_18 = F_16 ( V_16 , 6 ) ;
if ( V_18 )
return V_18 ;
F_17 ( V_16 , V_25 | V_35 ) ;
F_17 ( V_16 , V_27 ) ;
F_17 ( V_16 , V_29 | V_30 ) ;
if ( F_15 ( V_5 ) ) {
F_17 ( V_16 , V_31 ) ;
F_17 ( V_16 , V_31 ) ;
F_17 ( V_16 , V_31 ) ;
} else {
F_17 ( V_16 , V_25 | V_42 ) ;
F_17 ( V_16 , V_27 ) ;
F_17 ( V_16 , V_29 | V_30 ) ;
}
F_18 ( V_16 ) ;
return F_7 ( V_3 , F_25 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_14 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 = & V_4 -> V_16 [ V_17 ] ;
int V_18 ;
if ( V_3 -> V_19 == 0 )
return 0 ;
V_18 = F_11 ( V_16 , V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
F_12 ( V_5 ) ;
if ( V_3 -> V_20 )
V_3 -> V_20 ( V_3 ) ;
V_3 -> V_19 = 0 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_14 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 = & V_4 -> V_16 [ V_17 ] ;
int V_18 ;
if ( ! V_3 -> V_38 )
return 0 ;
if ( F_20 ( V_43 ) & V_44 ) {
V_18 = F_16 ( V_16 , 2 ) ;
if ( V_18 )
return V_18 ;
F_17 ( V_16 , V_29 | V_30 ) ;
F_17 ( V_16 , V_31 ) ;
F_18 ( V_16 ) ;
V_18 = F_7 ( V_3 ,
F_22 ) ;
if ( V_18 )
return V_18 ;
}
F_22 ( V_3 ) ;
return 0 ;
}
static int F_29 ( T_3 V_45 )
{
switch ( V_45 & V_46 ) {
case V_47 :
return 4 ;
case V_48 :
default:
return - V_49 ;
}
}
static int F_30 ( T_3 V_45 , short V_50 )
{
switch ( V_45 & V_46 ) {
case V_47 :
return V_50 << 1 ;
default:
return - V_49 ;
}
}
static int F_31 ( T_3 V_45 )
{
switch ( V_45 & V_46 ) {
case V_47 :
case V_51 :
return 2 ;
case V_48 :
case V_52 :
return 4 ;
default:
return - V_49 ;
}
}
static int F_32 ( T_3 V_45 )
{
switch ( V_45 & V_46 ) {
case V_51 :
case V_52 :
return 2 ;
case V_47 :
case V_48 :
return 1 ;
default:
return - V_49 ;
}
}
static T_3 F_33 ( struct V_14 * V_5 , T_3 V_53 , T_3 V_50 )
{
T_3 V_54 , V_55 , V_18 ;
if ( F_34 ( V_5 ) ) {
V_54 = 0x1f ;
V_55 = 5 ;
} else {
V_54 = 0x3f ;
V_55 = 6 ;
}
V_18 = ( ( V_53 + V_50 + V_54 ) >> V_55 ) - ( V_53 >> V_55 ) ;
if ( ! F_34 ( V_5 ) )
V_18 <<= 1 ;
V_18 -= 1 ;
return V_18 << 2 ;
}
static void F_35 ( struct V_1 T_1 * V_7 )
{
F_36 ( V_7 -> V_56 , V_57 , sizeof( V_57 ) ) ;
F_36 ( V_7 -> V_58 , V_59 ,
sizeof( V_59 ) ) ;
}
static bool F_37 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 ,
struct V_60 * V_61 )
{
T_3 V_62 , V_63 , V_64 , V_65 ;
#define F_38 12
#define F_39 0xfff
bool V_66 = false ;
int V_67 = F_31 ( V_61 -> V_45 ) ;
int V_68 = F_32 ( V_61 -> V_45 ) ;
if ( V_61 -> V_69 > 1 )
V_62 = ( ( V_61 -> V_70 - 1 ) << F_38 )
/ ( V_61 -> V_69 ) ;
else
V_62 = 1 << F_38 ;
if ( V_61 -> V_71 > 1 )
V_63 = ( ( V_61 -> V_72 - 1 ) << F_38 )
/ ( V_61 -> V_71 ) ;
else
V_63 = 1 << F_38 ;
V_64 = V_62 / V_67 ;
V_65 = V_63 / V_68 ;
V_62 = V_64 * V_67 ;
V_63 = V_65 * V_68 ;
if ( V_62 != V_3 -> V_73 || V_63 != V_3 -> V_74 )
V_66 = true ;
V_3 -> V_73 = V_62 ;
V_3 -> V_74 = V_63 ;
F_40 ( ( ( V_63 & F_39 ) << 20 ) |
( ( V_62 >> F_38 ) << 16 ) |
( ( V_62 & F_39 ) << 3 ) ,
& V_7 -> V_75 ) ;
F_40 ( ( ( V_65 & F_39 ) << 20 ) |
( ( V_64 >> F_38 ) << 16 ) |
( ( V_64 & F_39 ) << 3 ) ,
& V_7 -> V_76 ) ;
F_40 ( ( ( ( V_63 >> F_38 ) << 16 ) |
( ( V_65 >> F_38 ) << 0 ) ) ,
& V_7 -> V_77 ) ;
if ( V_66 )
F_35 ( V_7 ) ;
return V_66 ;
}
static void F_41 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
T_3 V_78 = V_3 -> V_79 ;
switch ( V_3 -> V_41 -> V_39 . V_80 -> V_81 ) {
case 8 :
F_40 ( 0 , & V_7 -> V_82 ) ;
F_40 ( V_83 | V_84 , & V_7 -> V_85 ) ;
break;
case 16 :
if ( V_3 -> V_41 -> V_39 . V_80 -> V_86 == 15 ) {
F_40 ( F_42 ( V_78 ) , & V_7 -> V_82 ) ;
F_40 ( V_87 | V_84 ,
& V_7 -> V_85 ) ;
} else {
F_40 ( F_43 ( V_78 ) , & V_7 -> V_82 ) ;
F_40 ( V_88 | V_84 ,
& V_7 -> V_85 ) ;
}
break;
case 24 :
case 32 :
F_40 ( V_78 , & V_7 -> V_82 ) ;
F_40 ( V_89 | V_84 , & V_7 -> V_85 ) ;
break;
}
}
static T_3 F_44 ( struct V_60 * V_61 )
{
T_3 V_90 = V_91 | V_92 | V_93 ;
if ( V_61 -> V_45 & V_94 ) {
switch ( V_61 -> V_45 & V_46 ) {
case V_47 :
V_90 |= V_95 ;
break;
case V_51 :
V_90 |= V_96 ;
break;
case V_48 :
case V_52 :
V_90 |= V_97 ;
break;
}
} else {
switch ( V_61 -> V_45 & V_46 ) {
case V_47 :
V_90 |= V_98 ;
break;
case V_48 :
V_90 |= V_99 ;
break;
}
switch ( V_61 -> V_45 & V_100 ) {
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
struct V_36 * V_108 ,
struct V_60 * V_61 )
{
int V_18 , V_109 ;
struct V_1 T_1 * V_7 ;
bool V_66 = false ;
struct V_14 * V_5 = V_3 -> V_5 ;
T_3 V_110 , V_111 , V_112 , V_113 ;
F_9 ( ! F_46 ( & V_5 -> V_114 ) ) ;
F_9 ( ! F_46 ( & V_5 -> V_115 . V_116 ) ) ;
F_9 ( ! V_3 ) ;
V_18 = F_28 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_47 ( V_108 , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_48 ( V_108 ) ;
if ( V_18 )
goto V_117;
if ( ! V_3 -> V_22 ) {
T_3 V_118 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_119 ;
goto V_117;
}
V_118 = V_120 ;
if ( F_49 ( V_3 -> V_5 ) )
V_118 |= V_121 ;
V_118 |= V_3 -> V_41 -> V_122 == 0 ?
V_123 : V_124 ;
F_40 ( V_118 , & V_7 -> V_125 ) ;
F_5 ( V_3 , V_7 ) ;
V_18 = F_13 ( V_3 ) ;
if ( V_18 != 0 )
goto V_117;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_119 ;
goto V_117;
}
F_40 ( ( V_61 -> V_126 << 16 ) | V_61 -> V_127 , & V_7 -> V_128 ) ;
F_40 ( ( V_61 -> V_71 << 16 ) | V_61 -> V_69 , & V_7 -> V_129 ) ;
if ( V_61 -> V_45 & V_130 )
V_109 = F_30 ( V_61 -> V_45 , V_61 -> V_131 ) ;
else
V_109 = V_61 -> V_131 ;
V_110 = V_61 -> V_131 ;
V_111 = F_33 ( V_3 -> V_5 , V_61 -> V_132 , V_109 ) ;
V_112 = V_61 -> V_133 ;
F_40 ( F_4 ( V_108 ) + V_61 -> V_132 , & V_7 -> V_134 ) ;
V_113 = V_61 -> V_135 ;
if ( V_61 -> V_45 & V_94 ) {
int V_67 = F_31 ( V_61 -> V_45 ) ;
int V_68 = F_32 ( V_61 -> V_45 ) ;
T_3 V_136 , V_137 ;
V_110 |= ( V_61 -> V_131 / V_67 ) << 16 ;
V_136 = F_33 ( V_3 -> V_5 , V_61 -> V_138 ,
V_61 -> V_131 / V_67 ) ;
V_137 = F_33 ( V_3 -> V_5 , V_61 -> V_139 ,
V_61 -> V_131 / V_67 ) ;
V_111 |= F_50 ( T_3 , V_136 , V_137 ) << 16 ;
V_112 |= ( V_61 -> V_133 / V_68 ) << 16 ;
F_40 ( F_4 ( V_108 ) + V_61 -> V_138 , & V_7 -> V_140 ) ;
F_40 ( F_4 ( V_108 ) + V_61 -> V_139 , & V_7 -> V_141 ) ;
V_113 |= V_61 -> V_142 << 16 ;
}
F_40 ( V_110 , & V_7 -> V_143 ) ;
F_40 ( V_111 , & V_7 -> V_144 ) ;
F_40 ( V_112 , & V_7 -> V_145 ) ;
F_40 ( V_113 , & V_7 -> V_146 ) ;
V_66 = F_37 ( V_3 , V_7 , V_61 ) ;
F_41 ( V_3 , V_7 ) ;
F_40 ( F_44 ( V_61 ) , & V_7 -> V_147 ) ;
F_5 ( V_3 , V_7 ) ;
V_18 = F_19 ( V_3 , V_66 ) ;
if ( V_18 )
goto V_117;
V_3 -> V_38 = V_3 -> V_40 ;
V_3 -> V_40 = V_108 ;
return 0 ;
V_117:
F_23 ( V_108 ) ;
return V_18 ;
}
int F_51 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_7 ;
struct V_14 * V_5 = V_3 -> V_5 ;
int V_18 ;
F_9 ( ! F_46 ( & V_5 -> V_114 ) ) ;
F_9 ( ! F_46 ( & V_5 -> V_115 . V_116 ) ) ;
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( ! V_3 -> V_22 )
return 0 ;
V_18 = F_28 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_7 = F_1 ( V_3 ) ;
F_40 ( 0 , & V_7 -> V_147 ) ;
F_5 ( V_3 , V_7 ) ;
V_18 = F_26 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
F_25 ( V_3 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_148 * V_41 )
{
if ( ! V_41 -> V_22 )
return - V_49 ;
if ( V_41 -> V_149 . V_150 )
return - V_49 ;
return 0 ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_14 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
T_3 V_151 = F_20 ( V_152 ) ;
T_3 V_153 ;
if ( F_54 ( V_5 ) -> V_154 >= 4 ) {
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
static int F_55 ( struct V_2 * V_3 ,
struct V_161 * V_162 )
{
struct V_163 * V_164 = & V_3 -> V_41 -> V_39 . V_164 ;
if ( V_162 -> V_127 < V_164 -> V_165 &&
V_162 -> V_127 + V_162 -> V_166 <= V_164 -> V_165 &&
V_162 -> V_126 < V_164 -> V_167 &&
V_162 -> V_126 + V_162 -> V_168 <= V_164 -> V_167 )
return 0 ;
else
return - V_49 ;
}
static int F_56 ( struct V_60 * V_162 )
{
T_3 V_33 ;
V_33 = ( ( V_162 -> V_72 << 16 ) / V_162 -> V_71 ) >> 16 ;
if ( V_33 > 7 )
return - V_49 ;
V_33 = ( ( V_162 -> V_70 << 16 ) / V_162 -> V_69 ) >> 16 ;
if ( V_33 > 7 )
return - V_49 ;
return 0 ;
}
static int F_57 ( struct V_14 * V_5 ,
struct V_161 * V_162 ,
struct V_36 * V_108 )
{
int V_67 = F_31 ( V_162 -> V_169 ) ;
int V_68 = F_32 ( V_162 -> V_169 ) ;
T_3 V_170 ;
int V_86 ;
T_3 V_33 ;
if ( F_58 ( V_5 ) || F_15 ( V_5 ) ) {
if ( V_162 -> V_171 > V_172 ||
V_162 -> V_173 > V_174 )
return - V_49 ;
} else {
if ( V_162 -> V_171 > V_175 ||
V_162 -> V_173 > V_176 )
return - V_49 ;
}
if ( V_162 -> V_171 < V_177 * 4 ||
V_162 -> V_173 < V_178 * 4 )
return - V_49 ;
switch ( V_162 -> V_169 & V_179 ) {
case V_180 :
return - V_49 ;
case V_130 :
if ( V_68 != 1 )
return - V_49 ;
V_86 = F_29 ( V_162 -> V_169 ) ;
if ( V_86 < 0 )
return V_86 ;
V_162 -> V_142 = 0 ;
V_162 -> V_138 = 0 ;
V_162 -> V_139 = 0 ;
if ( V_162 -> V_132 % V_86 )
return - V_49 ;
break;
case V_94 :
if ( V_68 < 0 || V_67 < 0 )
return - V_49 ;
break;
default:
return - V_49 ;
}
if ( V_162 -> V_173 % V_67 )
return - V_49 ;
if ( F_15 ( V_5 ) || F_58 ( V_5 ) )
V_170 = 255 ;
else
V_170 = 63 ;
if ( V_162 -> V_135 & V_170 || V_162 -> V_142 & V_170 )
return - V_49 ;
if ( F_49 ( V_5 ) && V_162 -> V_135 < 512 )
return - V_49 ;
V_33 = ( V_162 -> V_169 & V_179 ) == V_94 ?
4096 : 8192 ;
if ( V_162 -> V_135 > V_33 || V_162 -> V_142 > 2 * 1024 )
return - V_49 ;
switch ( V_162 -> V_169 & V_179 ) {
case V_180 :
case V_130 :
if ( F_30 ( V_162 -> V_169 , V_162 -> V_173 ) > V_162 -> V_135 )
return - V_49 ;
V_33 = V_162 -> V_135 * V_162 -> V_171 ;
if ( V_162 -> V_132 + V_33 > V_108 -> V_39 . V_181 )
return - V_49 ;
break;
case V_94 :
if ( V_162 -> V_173 > V_162 -> V_135 )
return - V_49 ;
if ( V_162 -> V_173 / V_67 > V_162 -> V_142 )
return - V_49 ;
V_33 = V_162 -> V_135 * V_162 -> V_171 ;
if ( V_162 -> V_132 + V_33 > V_108 -> V_39 . V_181 )
return - V_49 ;
V_33 = V_162 -> V_142 * ( V_162 -> V_171 / V_68 ) ;
if ( V_162 -> V_138 + V_33 > V_108 -> V_39 . V_181 ||
V_162 -> V_139 + V_33 > V_108 -> V_39 . V_181 )
return - V_49 ;
break;
}
return 0 ;
}
static int F_59 ( struct V_14 * V_5 )
{
struct V_21 * V_4 = V_5 -> V_6 ;
T_3 V_151 ;
if ( F_54 ( V_5 ) -> V_154 <= 3 && ( F_15 ( V_5 ) || ! F_60 ( V_5 ) ) )
return - 1 ;
V_151 = F_20 ( V_152 ) ;
if ( ( V_151 & V_182 ) == 0 )
return - 1 ;
if ( F_49 ( V_5 ) )
return ( V_151 >> 29 ) & 0x3 ;
return 1 ;
}
int F_61 ( struct V_14 * V_5 , void * V_183 ,
struct V_184 * V_185 )
{
struct V_161 * V_186 = V_183 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_187 * V_188 ;
struct V_148 * V_41 ;
struct V_36 * V_108 ;
struct V_60 * V_61 ;
int V_18 ;
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_21 ( L_2 ) ;
return - V_189 ;
}
if ( ! ( V_186 -> V_169 & V_190 ) ) {
F_62 ( V_5 ) ;
F_63 ( & V_5 -> V_114 ) ;
V_18 = F_51 ( V_3 ) ;
F_64 ( & V_5 -> V_114 ) ;
F_65 ( V_5 ) ;
return V_18 ;
}
V_61 = F_66 ( sizeof( * V_61 ) , V_191 ) ;
if ( ! V_61 )
return - V_119 ;
V_188 = F_67 ( V_5 , V_186 -> V_192 ,
V_193 ) ;
if ( ! V_188 ) {
V_18 = - V_194 ;
goto V_195;
}
V_41 = F_68 ( F_69 ( V_188 ) ) ;
V_108 = F_70 ( F_71 ( V_5 , V_185 ,
V_186 -> V_196 ) ) ;
if ( & V_108 -> V_39 == NULL ) {
V_18 = - V_194 ;
goto V_195;
}
F_62 ( V_5 ) ;
F_63 ( & V_5 -> V_114 ) ;
if ( V_108 -> V_197 ) {
F_72 ( L_3 ) ;
V_18 = - V_49 ;
goto V_198;
}
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
goto V_198;
if ( V_3 -> V_41 != V_41 ) {
struct V_163 * V_164 = & V_41 -> V_39 . V_164 ;
V_18 = F_51 ( V_3 ) ;
if ( V_18 != 0 )
goto V_198;
V_18 = F_52 ( V_3 , V_41 ) ;
if ( V_18 != 0 )
goto V_198;
V_3 -> V_41 = V_41 ;
V_41 -> V_3 = V_3 ;
if ( V_164 -> V_165 > 1024 &&
F_59 ( V_5 ) == V_41 -> V_122 ) {
V_3 -> V_199 = 1 ;
F_53 ( V_3 ) ;
} else
V_3 -> V_199 = 0 ;
}
V_18 = F_55 ( V_3 , V_186 ) ;
if ( V_18 != 0 )
goto V_198;
if ( V_3 -> V_199 ) {
V_61 -> V_126 = ( ( ( ( T_3 ) V_186 -> V_126 ) << 12 ) /
V_3 -> V_160 ) ;
V_61 -> V_71 = ( ( ( ( T_3 ) V_186 -> V_168 ) << 12 ) /
V_3 -> V_160 ) + 1 ;
} else {
V_61 -> V_126 = V_186 -> V_126 ;
V_61 -> V_71 = V_186 -> V_168 ;
}
V_61 -> V_127 = V_186 -> V_127 ;
V_61 -> V_69 = V_186 -> V_166 ;
V_61 -> V_131 = V_186 -> V_173 ;
V_61 -> V_133 = V_186 -> V_171 ;
V_61 -> V_70 = V_186 -> V_200 ;
V_61 -> V_72 = V_186 -> V_201 ;
if ( V_61 -> V_72 > V_61 -> V_133 ||
V_61 -> V_70 > V_61 -> V_131 ) {
V_18 = - V_49 ;
goto V_198;
}
V_18 = F_57 ( V_5 , V_186 , V_108 ) ;
if ( V_18 != 0 )
goto V_198;
V_61 -> V_45 = V_186 -> V_169 & ~ V_202 ;
V_61 -> V_135 = V_186 -> V_135 ;
V_61 -> V_142 = V_186 -> V_142 ;
V_61 -> V_132 = V_186 -> V_132 ;
V_61 -> V_138 = V_186 -> V_138 ;
V_61 -> V_139 = V_186 -> V_139 ;
V_18 = F_56 ( V_61 ) ;
if ( V_18 != 0 )
goto V_198;
V_18 = F_45 ( V_3 , V_108 , V_61 ) ;
if ( V_18 != 0 )
goto V_198;
F_64 ( & V_5 -> V_114 ) ;
F_65 ( V_5 ) ;
F_73 ( V_61 ) ;
return 0 ;
V_198:
F_64 ( & V_5 -> V_114 ) ;
F_65 ( V_5 ) ;
F_74 ( & V_108 -> V_39 ) ;
V_195:
F_73 ( V_61 ) ;
return V_18 ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
F_40 ( ( V_3 -> V_203 << 18 ) | ( V_3 -> V_204 & 0xff ) ,
& V_7 -> V_205 ) ;
F_40 ( V_3 -> V_206 , & V_7 -> V_207 ) ;
}
static bool F_76 ( T_3 V_208 , T_3 V_209 )
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
static bool F_77 ( T_3 V_211 )
{
int V_210 ;
for ( V_210 = 0 ; V_210 < 3 ; V_210 ++ ) {
if ( ( ( V_211 >> V_210 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_78 ( struct V_212 * V_213 )
{
if ( ! F_76 ( 0 , V_213 -> V_214 ) ||
! F_76 ( V_213 -> V_214 , V_213 -> V_208 ) ||
! F_76 ( V_213 -> V_208 , V_213 -> V_209 ) ||
! F_76 ( V_213 -> V_209 , V_213 -> V_215 ) ||
! F_76 ( V_213 -> V_215 , V_213 -> V_216 ) ||
! F_76 ( V_213 -> V_216 , V_213 -> V_211 ) ||
! F_76 ( V_213 -> V_211 , 0x00ffffff ) )
return - V_49 ;
if ( ! F_77 ( V_213 -> V_211 ) )
return - V_49 ;
return 0 ;
}
int F_79 ( struct V_14 * V_5 , void * V_183 ,
struct V_184 * V_185 )
{
struct V_212 * V_213 = V_183 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_7 ;
int V_18 ;
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_21 ( L_2 ) ;
return - V_189 ;
}
F_62 ( V_5 ) ;
F_63 ( & V_5 -> V_114 ) ;
V_18 = - V_49 ;
if ( ! ( V_213 -> V_169 & V_217 ) ) {
V_213 -> V_79 = V_3 -> V_79 ;
V_213 -> V_204 = V_3 -> V_204 ;
V_213 -> V_203 = V_3 -> V_203 ;
V_213 -> V_206 = V_3 -> V_206 ;
if ( ! F_34 ( V_5 ) ) {
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
V_3 -> V_79 = V_213 -> V_79 ;
V_3 -> V_204 = V_213 -> V_204 ;
V_3 -> V_203 = V_213 -> V_203 ;
V_3 -> V_206 = V_213 -> V_206 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_119 ;
goto V_198;
}
F_75 ( V_3 , V_7 ) ;
F_5 ( V_3 , V_7 ) ;
if ( V_213 -> V_169 & V_224 ) {
if ( F_34 ( V_5 ) )
goto V_198;
if ( V_3 -> V_22 ) {
V_18 = - V_225 ;
goto V_198;
}
V_18 = F_78 ( V_213 ) ;
if ( V_18 )
goto V_198;
F_80 ( V_218 , V_213 -> V_214 ) ;
F_80 ( V_219 , V_213 -> V_208 ) ;
F_80 ( V_220 , V_213 -> V_209 ) ;
F_80 ( V_221 , V_213 -> V_215 ) ;
F_80 ( V_222 , V_213 -> V_216 ) ;
F_80 ( V_223 , V_213 -> V_211 ) ;
}
}
V_18 = 0 ;
V_198:
F_64 ( & V_5 -> V_114 ) ;
F_65 ( V_5 ) ;
return V_18 ;
}
void F_81 ( struct V_14 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_36 * V_8 ;
struct V_1 T_1 * V_7 ;
int V_18 ;
if ( ! F_82 ( V_5 ) )
return;
V_3 = F_83 ( sizeof( * V_3 ) , V_191 ) ;
if ( ! V_3 )
return;
F_63 ( & V_5 -> V_114 ) ;
if ( F_14 ( V_4 -> V_3 ) )
goto V_195;
V_3 -> V_5 = V_5 ;
V_8 = NULL ;
if ( ! F_2 ( V_5 ) )
V_8 = F_84 ( V_5 , V_226 ) ;
if ( V_8 == NULL )
V_8 = F_85 ( V_5 , V_226 ) ;
if ( V_8 == NULL )
goto V_195;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_18 = F_86 ( V_5 , V_8 ,
V_227 ,
V_226 ) ;
if ( V_18 ) {
F_72 ( L_4 ) ;
goto V_228;
}
V_3 -> V_27 = V_8 -> V_9 -> V_10 -> V_229 ;
} else {
V_18 = F_87 ( V_8 , V_226 , true , false ) ;
if ( V_18 ) {
F_72 ( L_5 ) ;
goto V_228;
}
V_3 -> V_27 = F_4 ( V_8 ) ;
V_18 = F_88 ( V_8 , true ) ;
if ( V_18 ) {
F_72 ( L_6 ) ;
goto V_230;
}
}
V_3 -> V_79 = 0x0101fe ;
V_3 -> V_204 = - 19 ;
V_3 -> V_203 = 75 ;
V_3 -> V_206 = 146 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_230;
F_89 ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_35 ( V_7 ) ;
F_75 ( V_3 , V_7 ) ;
F_5 ( V_3 , V_7 ) ;
V_4 -> V_3 = V_3 ;
F_64 ( & V_5 -> V_114 ) ;
F_90 ( L_7 ) ;
return;
V_230:
if ( ! F_2 ( V_5 ) )
F_23 ( V_8 ) ;
V_228:
F_24 ( & V_8 -> V_39 ) ;
V_195:
F_64 ( & V_5 -> V_114 ) ;
F_73 ( V_3 ) ;
return;
}
void F_91 ( struct V_14 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
if ( ! V_4 -> V_3 )
return;
F_9 ( V_4 -> V_3 -> V_22 ) ;
F_74 ( & V_4 -> V_3 -> V_8 -> V_39 ) ;
F_73 ( V_4 -> V_3 ) ;
}
static struct V_1 T_1 *
F_92 ( struct V_2 * V_3 )
{
T_2 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = (struct V_1 T_1 * )
V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_93 ( V_4 -> V_12 . V_13 ,
F_4 ( V_3 -> V_8 ) ) ;
return V_7 ;
}
static void F_94 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_95 ( V_7 ) ;
}
struct V_231 *
F_96 ( struct V_14 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_231 * error ;
struct V_1 T_1 * V_7 ;
if ( ! V_3 || ! V_3 -> V_22 )
return NULL ;
error = F_66 ( sizeof( * error ) , V_232 ) ;
if ( error == NULL )
return NULL ;
error -> V_233 = F_20 ( V_34 ) ;
error -> V_234 = F_20 ( V_43 ) ;
if ( F_2 ( V_3 -> V_5 ) )
error -> V_39 = ( V_235 long ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
error -> V_39 = F_4 ( V_3 -> V_8 ) ;
V_7 = F_92 ( V_3 ) ;
if ( ! V_7 )
goto V_236;
F_97 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_94 ( V_3 , V_7 ) ;
return error ;
V_236:
F_73 ( error ) ;
return NULL ;
}
void
F_98 ( struct V_237 * V_238 ,
struct V_231 * error )
{
F_99 ( V_238 , L_8 ,
error -> V_233 , error -> V_234 ) ;
F_99 ( V_238 , L_9 ,
error -> V_39 ) ;
#define F_100 ( T_4 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_100 ( V_134 ) ;
F_100 ( V_239 ) ;
F_100 ( V_140 ) ;
F_100 ( V_141 ) ;
F_100 ( V_240 ) ;
F_100 ( V_241 ) ;
F_100 ( V_146 ) ;
F_100 ( V_242 ) ;
F_100 ( V_243 ) ;
F_100 ( V_244 ) ;
F_100 ( V_245 ) ;
F_100 ( V_128 ) ;
F_100 ( V_129 ) ;
F_100 ( V_143 ) ;
F_100 ( V_144 ) ;
F_100 ( V_145 ) ;
F_100 ( V_75 ) ;
F_100 ( V_76 ) ;
F_100 ( V_205 ) ;
F_100 ( V_207 ) ;
F_100 ( V_82 ) ;
F_100 ( V_85 ) ;
F_100 ( V_246 ) ;
F_100 ( V_247 ) ;
F_100 ( V_248 ) ;
F_100 ( V_125 ) ;
F_100 ( V_147 ) ;
F_100 ( V_249 ) ;
F_100 ( V_250 ) ;
F_100 ( V_251 ) ;
F_100 ( V_252 ) ;
F_100 ( V_253 ) ;
F_100 ( V_254 ) ;
F_100 ( V_255 ) ;
F_100 ( V_256 ) ;
F_100 ( V_257 ) ;
F_100 ( V_258 ) ;
F_100 ( V_259 ) ;
F_100 ( V_260 ) ;
F_100 ( V_261 ) ;
F_100 ( V_77 ) ;
#undef F_100
}
