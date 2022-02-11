static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_5 ) )
V_7 = (struct V_1 T_1 * ) V_3 -> V_8 -> V_9 -> V_10 ;
else
V_7 = F_3 ( & V_5 -> V_11 . V_12 ,
V_3 -> V_13 ,
V_14 ) ;
return V_7 ;
}
static void F_4 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_5 ( V_7 ) ;
}
static void F_6 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
T_2 V_17 )
{
F_7 ( F_8 ( & V_3 -> V_18 ,
& V_3 -> V_6 -> V_19 . V_20 ) ) ;
F_9 ( & V_3 -> V_18 , V_17 ,
& V_3 -> V_6 -> V_19 . V_20 ) ;
F_10 ( & V_3 -> V_18 , V_16 ) ;
F_11 ( V_16 ) ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
T_2 V_17 )
{
F_6 ( V_3 , V_16 , V_17 ) ;
return F_13 ( & V_3 -> V_18 ,
& V_3 -> V_6 -> V_19 . V_20 ) ;
}
static struct V_15 * F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_21 * V_22 = V_5 -> V_22 [ V_23 ] ;
return F_15 ( V_22 , V_5 -> V_24 ) ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
int V_27 ;
F_17 ( V_3 -> V_28 ) ;
F_17 ( F_18 ( V_5 ) && ! ( V_5 -> V_29 & V_30 ) ) ;
V_16 = F_14 ( V_3 ) ;
if ( F_19 ( V_16 ) )
return F_20 ( V_16 ) ;
V_27 = F_21 ( V_16 , 4 ) ;
if ( V_27 ) {
F_22 ( V_16 ) ;
return V_27 ;
}
V_3 -> V_28 = true ;
V_26 = V_16 -> V_26 ;
F_23 ( V_26 , V_31 | V_32 ) ;
F_23 ( V_26 , V_3 -> V_13 | V_33 ) ;
F_23 ( V_26 , V_34 | V_35 ) ;
F_23 ( V_26 , V_36 ) ;
F_24 ( V_26 ) ;
return F_12 ( V_3 , V_16 , NULL ) ;
}
static int F_25 ( struct V_2 * V_3 ,
bool V_37 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
T_3 V_13 = V_3 -> V_13 ;
T_3 V_38 ;
int V_27 ;
F_17 ( ! V_3 -> V_28 ) ;
if ( V_37 )
V_13 |= V_33 ;
V_38 = F_26 ( V_39 ) ;
if ( V_38 & ( 1 << 17 ) )
F_27 ( L_1 , V_38 ) ;
V_16 = F_14 ( V_3 ) ;
if ( F_19 ( V_16 ) )
return F_20 ( V_16 ) ;
V_27 = F_21 ( V_16 , 2 ) ;
if ( V_27 ) {
F_22 ( V_16 ) ;
return V_27 ;
}
V_26 = V_16 -> V_26 ;
F_23 ( V_26 , V_31 | V_40 ) ;
F_23 ( V_26 , V_13 ) ;
F_24 ( V_26 ) ;
F_6 ( V_3 , V_16 , NULL ) ;
return 0 ;
}
static void F_28 ( struct V_41 * V_28 ,
struct V_15 * V_16 )
{
struct V_2 * V_3 =
F_29 ( V_28 , F_30 ( * V_3 ) , V_18 ) ;
struct V_42 * V_43 ;
V_43 = F_31 ( & V_3 -> V_44 ) ;
if ( F_17 ( ! V_43 ) )
return;
F_32 ( V_43 -> V_45 , NULL ,
F_33 ( V_3 -> V_46 -> V_47 ) ) ;
F_34 ( V_43 ) ;
F_35 ( V_43 ) ;
}
static void F_36 ( struct V_41 * V_28 ,
struct V_15 * V_16 )
{
struct V_2 * V_3 =
F_29 ( V_28 , F_30 ( * V_3 ) , V_18 ) ;
struct V_42 * V_43 ;
V_43 = F_31 ( & V_3 -> V_43 ) ;
if ( F_17 ( ! V_43 ) )
return;
F_34 ( V_43 ) ;
F_35 ( V_43 ) ;
V_3 -> V_46 -> V_3 = NULL ;
V_3 -> V_46 = NULL ;
V_3 -> V_28 = false ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
T_3 V_13 = V_3 -> V_13 ;
int V_27 ;
F_17 ( ! V_3 -> V_28 ) ;
V_13 |= V_33 ;
V_16 = F_14 ( V_3 ) ;
if ( F_19 ( V_16 ) )
return F_20 ( V_16 ) ;
V_27 = F_21 ( V_16 , 6 ) ;
if ( V_27 ) {
F_22 ( V_16 ) ;
return V_27 ;
}
V_26 = V_16 -> V_26 ;
F_23 ( V_26 , V_31 | V_40 ) ;
F_23 ( V_26 , V_13 ) ;
F_23 ( V_26 , V_34 | V_35 ) ;
if ( F_18 ( V_5 ) ) {
F_23 ( V_26 , V_36 ) ;
F_23 ( V_26 , V_36 ) ;
F_23 ( V_26 , V_36 ) ;
} else {
F_23 ( V_26 , V_31 | V_48 ) ;
F_23 ( V_26 , V_13 ) ;
F_23 ( V_26 ,
V_34 | V_35 ) ;
}
F_24 ( V_26 ) ;
return F_12 ( V_3 , V_16 ,
F_36 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
return F_13 ( & V_3 -> V_18 ,
& V_3 -> V_6 -> V_19 . V_20 ) ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_27 ;
F_40 ( & V_5 -> V_19 . V_20 ) ;
if ( ! V_3 -> V_44 )
return 0 ;
if ( F_26 ( V_49 ) & V_50 ) {
struct V_15 * V_16 ;
struct V_25 * V_26 ;
V_16 = F_14 ( V_3 ) ;
if ( F_19 ( V_16 ) )
return F_20 ( V_16 ) ;
V_27 = F_21 ( V_16 , 2 ) ;
if ( V_27 ) {
F_22 ( V_16 ) ;
return V_27 ;
}
V_26 = V_16 -> V_26 ;
F_23 ( V_26 ,
V_34 | V_35 ) ;
F_23 ( V_26 , V_36 ) ;
F_24 ( V_26 ) ;
V_27 = F_12 ( V_3 , V_16 ,
F_28 ) ;
if ( V_27 )
return V_27 ;
} else
F_28 ( & V_3 -> V_18 , NULL ) ;
return 0 ;
}
void F_41 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
F_39 ( V_3 ) ;
V_3 -> V_51 = 0 ;
V_3 -> V_52 = 0 ;
V_3 -> V_46 = NULL ;
V_3 -> V_28 = false ;
}
static int F_42 ( T_3 V_53 )
{
switch ( V_53 & V_54 ) {
case V_55 :
return 4 ;
case V_56 :
default:
return - V_57 ;
}
}
static int F_43 ( T_3 V_53 , short V_58 )
{
switch ( V_53 & V_54 ) {
case V_55 :
return V_58 << 1 ;
default:
return - V_57 ;
}
}
static int F_44 ( T_3 V_53 )
{
switch ( V_53 & V_54 ) {
case V_55 :
case V_59 :
return 2 ;
case V_56 :
case V_60 :
return 4 ;
default:
return - V_57 ;
}
}
static int F_45 ( T_3 V_53 )
{
switch ( V_53 & V_54 ) {
case V_59 :
case V_60 :
return 2 ;
case V_55 :
case V_56 :
return 1 ;
default:
return - V_57 ;
}
}
static T_3 F_46 ( struct V_4 * V_5 , T_3 V_61 , T_3 V_58 )
{
T_3 V_62 , V_63 , V_27 ;
if ( F_47 ( V_5 ) ) {
V_62 = 0x1f ;
V_63 = 5 ;
} else {
V_62 = 0x3f ;
V_63 = 6 ;
}
V_27 = ( ( V_61 + V_58 + V_62 ) >> V_63 ) - ( V_61 >> V_63 ) ;
if ( ! F_47 ( V_5 ) )
V_27 <<= 1 ;
V_27 -= 1 ;
return V_27 << 2 ;
}
static void F_48 ( struct V_1 T_1 * V_7 )
{
F_49 ( V_7 -> V_64 , V_65 , sizeof( V_65 ) ) ;
F_49 ( V_7 -> V_66 , V_67 ,
sizeof( V_67 ) ) ;
}
static bool F_50 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 ,
struct V_68 * V_69 )
{
T_3 V_70 , V_71 , V_72 , V_73 ;
#define F_51 12
#define F_52 0xfff
bool V_74 = false ;
int V_75 = F_44 ( V_69 -> V_53 ) ;
int V_76 = F_45 ( V_69 -> V_53 ) ;
if ( V_69 -> V_77 > 1 )
V_70 = ( ( V_69 -> V_78 - 1 ) << F_51 )
/ ( V_69 -> V_77 ) ;
else
V_70 = 1 << F_51 ;
if ( V_69 -> V_79 > 1 )
V_71 = ( ( V_69 -> V_80 - 1 ) << F_51 )
/ ( V_69 -> V_79 ) ;
else
V_71 = 1 << F_51 ;
V_72 = V_70 / V_75 ;
V_73 = V_71 / V_76 ;
V_70 = V_72 * V_75 ;
V_71 = V_73 * V_76 ;
if ( V_70 != V_3 -> V_51 || V_71 != V_3 -> V_52 )
V_74 = true ;
V_3 -> V_51 = V_70 ;
V_3 -> V_52 = V_71 ;
F_53 ( ( ( V_71 & F_52 ) << 20 ) |
( ( V_70 >> F_51 ) << 16 ) |
( ( V_70 & F_52 ) << 3 ) ,
& V_7 -> V_81 ) ;
F_53 ( ( ( V_73 & F_52 ) << 20 ) |
( ( V_72 >> F_51 ) << 16 ) |
( ( V_72 & F_52 ) << 3 ) ,
& V_7 -> V_82 ) ;
F_53 ( ( ( ( V_71 >> F_51 ) << 16 ) |
( ( V_73 >> F_51 ) << 0 ) ) ,
& V_7 -> V_83 ) ;
if ( V_74 )
F_48 ( V_7 ) ;
return V_74 ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
T_3 V_84 = V_3 -> V_85 ;
T_3 V_86 ;
V_86 = 0 ;
if ( V_3 -> V_87 )
V_86 |= V_88 ;
switch ( V_3 -> V_46 -> V_89 . V_90 -> V_91 -> V_92 ) {
case 8 :
V_84 = 0 ;
V_86 |= V_93 ;
break;
case 16 :
if ( V_3 -> V_46 -> V_89 . V_90 -> V_91 -> V_94 == 15 ) {
V_84 = F_55 ( V_84 ) ;
V_86 |= V_95 ;
} else {
V_84 = F_56 ( V_84 ) ;
V_86 |= V_96 ;
}
break;
case 24 :
case 32 :
V_86 |= V_97 ;
break;
}
F_53 ( V_84 , & V_7 -> V_98 ) ;
F_53 ( V_86 , & V_7 -> V_99 ) ;
}
static T_3 F_57 ( struct V_68 * V_69 )
{
T_3 V_100 = V_101 | V_102 | V_103 ;
if ( V_69 -> V_53 & V_104 ) {
switch ( V_69 -> V_53 & V_54 ) {
case V_55 :
V_100 |= V_105 ;
break;
case V_59 :
V_100 |= V_106 ;
break;
case V_56 :
case V_60 :
V_100 |= V_107 ;
break;
}
} else {
switch ( V_69 -> V_53 & V_54 ) {
case V_55 :
V_100 |= V_108 ;
break;
case V_56 :
V_100 |= V_109 ;
break;
}
switch ( V_69 -> V_53 & V_110 ) {
case V_111 :
break;
case V_112 :
V_100 |= V_113 ;
break;
case V_114 :
V_100 |= V_115 ;
break;
case V_116 :
V_100 |= V_117 ;
break;
}
}
return V_100 ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_118 * V_119 ,
struct V_68 * V_69 )
{
int V_27 , V_120 ;
struct V_1 T_1 * V_7 ;
bool V_74 = false ;
struct V_4 * V_5 = V_3 -> V_6 ;
T_3 V_121 , V_122 , V_123 , V_124 ;
enum V_47 V_47 = V_3 -> V_46 -> V_47 ;
struct V_42 * V_43 ;
F_40 ( & V_5 -> V_19 . V_20 ) ;
F_17 ( ! F_59 ( & V_5 -> V_19 . V_125 . V_126 ) ) ;
V_27 = F_39 ( V_3 ) ;
if ( V_27 != 0 )
return V_27 ;
V_43 = F_60 ( V_119 , 0 ,
& V_127 ) ;
if ( F_19 ( V_43 ) )
return F_20 ( V_43 ) ;
V_27 = F_61 ( V_43 ) ;
if ( V_27 )
goto V_128;
if ( ! V_3 -> V_28 ) {
T_3 V_129 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_27 = - V_130 ;
goto V_128;
}
V_129 = V_131 ;
if ( F_62 ( V_5 ) )
V_129 |= V_132 ;
V_129 |= V_47 == 0 ?
V_133 : V_134 ;
F_53 ( V_129 , & V_7 -> V_135 ) ;
F_4 ( V_3 , V_7 ) ;
V_27 = F_16 ( V_3 ) ;
if ( V_27 != 0 )
goto V_128;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_27 = - V_130 ;
goto V_128;
}
F_53 ( ( V_69 -> V_136 << 16 ) | V_69 -> V_137 , & V_7 -> V_138 ) ;
F_53 ( ( V_69 -> V_79 << 16 ) | V_69 -> V_77 , & V_7 -> V_139 ) ;
if ( V_69 -> V_53 & V_140 )
V_120 = F_43 ( V_69 -> V_53 , V_69 -> V_141 ) ;
else
V_120 = V_69 -> V_141 ;
V_121 = V_69 -> V_141 ;
V_122 = F_46 ( V_5 , V_69 -> V_142 , V_120 ) ;
V_123 = V_69 -> V_143 ;
F_53 ( F_63 ( V_43 ) + V_69 -> V_142 , & V_7 -> V_144 ) ;
V_124 = V_69 -> V_145 ;
if ( V_69 -> V_53 & V_104 ) {
int V_75 = F_44 ( V_69 -> V_53 ) ;
int V_76 = F_45 ( V_69 -> V_53 ) ;
T_3 V_146 , V_147 ;
V_121 |= ( V_69 -> V_141 / V_75 ) << 16 ;
V_146 = F_46 ( V_5 , V_69 -> V_148 ,
V_69 -> V_141 / V_75 ) ;
V_147 = F_46 ( V_5 , V_69 -> V_149 ,
V_69 -> V_141 / V_75 ) ;
V_122 |= F_64 ( T_3 , V_146 , V_147 ) << 16 ;
V_123 |= ( V_69 -> V_143 / V_76 ) << 16 ;
F_53 ( F_63 ( V_43 ) + V_69 -> V_148 ,
& V_7 -> V_150 ) ;
F_53 ( F_63 ( V_43 ) + V_69 -> V_149 ,
& V_7 -> V_151 ) ;
V_124 |= V_69 -> V_152 << 16 ;
}
F_53 ( V_121 , & V_7 -> V_153 ) ;
F_53 ( V_122 , & V_7 -> V_154 ) ;
F_53 ( V_123 , & V_7 -> V_155 ) ;
F_53 ( V_124 , & V_7 -> V_156 ) ;
V_74 = F_50 ( V_3 , V_7 , V_69 ) ;
F_54 ( V_3 , V_7 ) ;
F_53 ( F_57 ( V_69 ) , & V_7 -> V_157 ) ;
F_4 ( V_3 , V_7 ) ;
V_27 = F_25 ( V_3 , V_74 ) ;
if ( V_27 )
goto V_128;
F_32 ( V_3 -> V_43 ? V_3 -> V_43 -> V_45 : NULL ,
V_43 -> V_45 , F_33 ( V_47 ) ) ;
V_3 -> V_44 = V_3 -> V_43 ;
V_3 -> V_43 = V_43 ;
F_65 ( V_5 , F_33 ( V_47 ) ) ;
return 0 ;
V_128:
F_34 ( V_43 ) ;
return V_27 ;
}
int F_66 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 T_1 * V_7 ;
int V_27 ;
F_40 ( & V_5 -> V_19 . V_20 ) ;
F_17 ( ! F_59 ( & V_5 -> V_19 . V_125 . V_126 ) ) ;
V_27 = F_38 ( V_3 ) ;
if ( V_27 != 0 )
return V_27 ;
if ( ! V_3 -> V_28 )
return 0 ;
V_27 = F_39 ( V_3 ) ;
if ( V_27 != 0 )
return V_27 ;
V_7 = F_1 ( V_3 ) ;
F_53 ( 0 , & V_7 -> V_157 ) ;
F_4 ( V_3 , V_7 ) ;
return F_37 ( V_3 ) ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_158 * V_46 )
{
if ( ! V_46 -> V_28 )
return - V_57 ;
if ( V_46 -> V_159 -> V_160 )
return - V_57 ;
return 0 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
T_3 V_161 = F_26 ( V_162 ) ;
T_3 V_163 ;
if ( F_69 ( V_5 ) >= 4 ) {
V_163 = F_26 ( V_164 ) >> V_165 ;
} else {
if ( V_161 & V_166 )
V_163 = F_26 ( V_167 ) ;
else
V_163 = F_26 ( V_164 ) ;
V_163 >>= V_168 ;
}
V_3 -> V_169 = V_163 ;
}
static int F_70 ( struct V_2 * V_3 ,
struct V_170 * V_171 )
{
struct V_172 * V_173 = & V_3 -> V_46 -> V_89 . V_173 ;
if ( V_171 -> V_137 < V_173 -> V_174 &&
V_171 -> V_137 + V_171 -> V_175 <= V_173 -> V_174 &&
V_171 -> V_136 < V_173 -> V_176 &&
V_171 -> V_136 + V_171 -> V_177 <= V_173 -> V_176 )
return 0 ;
else
return - V_57 ;
}
static int F_71 ( struct V_68 * V_171 )
{
T_3 V_38 ;
V_38 = ( ( V_171 -> V_80 << 16 ) / V_171 -> V_79 ) >> 16 ;
if ( V_38 > 7 )
return - V_57 ;
V_38 = ( ( V_171 -> V_78 << 16 ) / V_171 -> V_77 ) >> 16 ;
if ( V_38 > 7 )
return - V_57 ;
return 0 ;
}
static int F_72 ( struct V_4 * V_5 ,
struct V_170 * V_171 ,
struct V_118 * V_119 )
{
int V_75 = F_44 ( V_171 -> V_86 ) ;
int V_76 = F_45 ( V_171 -> V_86 ) ;
T_3 V_178 ;
int V_94 ;
T_3 V_38 ;
if ( F_73 ( V_5 ) || F_18 ( V_5 ) ) {
if ( V_171 -> V_179 > V_180 ||
V_171 -> V_181 > V_182 )
return - V_57 ;
} else {
if ( V_171 -> V_179 > V_183 ||
V_171 -> V_181 > V_184 )
return - V_57 ;
}
if ( V_171 -> V_179 < V_185 * 4 ||
V_171 -> V_181 < V_186 * 4 )
return - V_57 ;
switch ( V_171 -> V_86 & V_187 ) {
case V_188 :
return - V_57 ;
case V_140 :
if ( V_76 != 1 )
return - V_57 ;
V_94 = F_42 ( V_171 -> V_86 ) ;
if ( V_94 < 0 )
return V_94 ;
V_171 -> V_152 = 0 ;
V_171 -> V_148 = 0 ;
V_171 -> V_149 = 0 ;
if ( V_171 -> V_142 % V_94 )
return - V_57 ;
break;
case V_104 :
if ( V_76 < 0 || V_75 < 0 )
return - V_57 ;
break;
default:
return - V_57 ;
}
if ( V_171 -> V_181 % V_75 )
return - V_57 ;
if ( F_18 ( V_5 ) || F_73 ( V_5 ) )
V_178 = 255 ;
else
V_178 = 63 ;
if ( V_171 -> V_145 & V_178 || V_171 -> V_152 & V_178 )
return - V_57 ;
if ( F_62 ( V_5 ) && V_171 -> V_145 < 512 )
return - V_57 ;
V_38 = ( V_171 -> V_86 & V_187 ) == V_104 ?
4096 : 8192 ;
if ( V_171 -> V_145 > V_38 || V_171 -> V_152 > 2 * 1024 )
return - V_57 ;
switch ( V_171 -> V_86 & V_187 ) {
case V_188 :
case V_140 :
if ( F_43 ( V_171 -> V_86 , V_171 -> V_181 ) > V_171 -> V_145 )
return - V_57 ;
V_38 = V_171 -> V_145 * V_171 -> V_179 ;
if ( V_171 -> V_142 + V_38 > V_119 -> V_89 . V_189 )
return - V_57 ;
break;
case V_104 :
if ( V_171 -> V_181 > V_171 -> V_145 )
return - V_57 ;
if ( V_171 -> V_181 / V_75 > V_171 -> V_152 )
return - V_57 ;
V_38 = V_171 -> V_145 * V_171 -> V_179 ;
if ( V_171 -> V_142 + V_38 > V_119 -> V_89 . V_189 )
return - V_57 ;
V_38 = V_171 -> V_152 * ( V_171 -> V_179 / V_76 ) ;
if ( V_171 -> V_148 + V_38 > V_119 -> V_89 . V_189 ||
V_171 -> V_149 + V_38 > V_119 -> V_89 . V_189 )
return - V_57 ;
break;
}
return 0 ;
}
static int F_74 ( struct V_4 * V_5 )
{
T_3 V_161 ;
if ( F_69 ( V_5 ) <= 3 &&
( F_18 ( V_5 ) || ! F_75 ( V_5 ) ) )
return - 1 ;
V_161 = F_26 ( V_162 ) ;
if ( ( V_161 & V_190 ) == 0 )
return - 1 ;
if ( F_62 ( V_5 ) )
return ( V_161 >> 29 ) & 0x3 ;
return 1 ;
}
int F_76 ( struct V_191 * V_192 , void * V_193 ,
struct V_194 * V_195 )
{
struct V_170 * V_196 = V_193 ;
struct V_4 * V_5 = F_77 ( V_192 ) ;
struct V_2 * V_3 ;
struct V_197 * V_198 ;
struct V_158 * V_46 ;
struct V_118 * V_119 ;
struct V_68 * V_69 ;
int V_27 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_27 ( L_2 ) ;
return - V_199 ;
}
if ( ! ( V_196 -> V_86 & V_200 ) ) {
F_78 ( V_192 ) ;
F_79 ( & V_192 -> V_20 ) ;
V_27 = F_66 ( V_3 ) ;
F_80 ( & V_192 -> V_20 ) ;
F_81 ( V_192 ) ;
return V_27 ;
}
V_69 = F_82 ( sizeof( * V_69 ) , V_201 ) ;
if ( ! V_69 )
return - V_130 ;
V_198 = F_83 ( V_192 , V_196 -> V_202 ) ;
if ( ! V_198 ) {
V_27 = - V_203 ;
goto V_204;
}
V_46 = F_84 ( V_198 ) ;
V_119 = F_85 ( V_195 , V_196 -> V_205 ) ;
if ( ! V_119 ) {
V_27 = - V_203 ;
goto V_204;
}
F_78 ( V_192 ) ;
F_79 ( & V_192 -> V_20 ) ;
if ( F_86 ( V_119 ) ) {
F_87 ( L_3 ) ;
V_27 = - V_57 ;
goto V_206;
}
V_27 = F_38 ( V_3 ) ;
if ( V_27 != 0 )
goto V_206;
if ( V_3 -> V_46 != V_46 ) {
struct V_172 * V_173 = & V_46 -> V_89 . V_173 ;
V_27 = F_66 ( V_3 ) ;
if ( V_27 != 0 )
goto V_206;
V_27 = F_67 ( V_3 , V_46 ) ;
if ( V_27 != 0 )
goto V_206;
V_3 -> V_46 = V_46 ;
V_46 -> V_3 = V_3 ;
if ( V_173 -> V_174 > 1024 &&
F_74 ( V_5 ) == V_46 -> V_47 ) {
V_3 -> V_207 = true ;
F_68 ( V_3 ) ;
} else
V_3 -> V_207 = false ;
}
V_27 = F_70 ( V_3 , V_196 ) ;
if ( V_27 != 0 )
goto V_206;
if ( V_3 -> V_207 ) {
V_69 -> V_136 = ( ( ( ( T_3 ) V_196 -> V_136 ) << 12 ) /
V_3 -> V_169 ) ;
V_69 -> V_79 = ( ( ( ( T_3 ) V_196 -> V_177 ) << 12 ) /
V_3 -> V_169 ) + 1 ;
} else {
V_69 -> V_136 = V_196 -> V_136 ;
V_69 -> V_79 = V_196 -> V_177 ;
}
V_69 -> V_137 = V_196 -> V_137 ;
V_69 -> V_77 = V_196 -> V_175 ;
V_69 -> V_141 = V_196 -> V_181 ;
V_69 -> V_143 = V_196 -> V_179 ;
V_69 -> V_78 = V_196 -> V_208 ;
V_69 -> V_80 = V_196 -> V_209 ;
if ( V_69 -> V_80 > V_69 -> V_143 ||
V_69 -> V_78 > V_69 -> V_141 ) {
V_27 = - V_57 ;
goto V_206;
}
V_27 = F_72 ( V_5 , V_196 , V_119 ) ;
if ( V_27 != 0 )
goto V_206;
V_69 -> V_53 = V_196 -> V_86 & ~ V_210 ;
V_69 -> V_145 = V_196 -> V_145 ;
V_69 -> V_152 = V_196 -> V_152 ;
V_69 -> V_142 = V_196 -> V_142 ;
V_69 -> V_148 = V_196 -> V_148 ;
V_69 -> V_149 = V_196 -> V_149 ;
V_27 = F_71 ( V_69 ) ;
if ( V_27 != 0 )
goto V_206;
V_27 = F_58 ( V_3 , V_119 , V_69 ) ;
if ( V_27 != 0 )
goto V_206;
F_80 ( & V_192 -> V_20 ) ;
F_81 ( V_192 ) ;
F_88 ( V_69 ) ;
return 0 ;
V_206:
F_80 ( & V_192 -> V_20 ) ;
F_81 ( V_192 ) ;
F_89 ( V_119 ) ;
V_204:
F_88 ( V_69 ) ;
return V_27 ;
}
static void F_90 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
F_53 ( ( V_3 -> V_211 << 18 ) | ( V_3 -> V_212 & 0xff ) ,
& V_7 -> V_213 ) ;
F_53 ( V_3 -> V_214 , & V_7 -> V_215 ) ;
}
static bool F_91 ( T_3 V_216 , T_3 V_217 )
{
int V_218 ;
if ( V_216 & 0xff000000 || V_217 & 0xff000000 )
return false ;
for ( V_218 = 0 ; V_218 < 3 ; V_218 ++ ) {
if ( ( ( V_216 >> V_218 * 8 ) & 0xff ) >= ( ( V_217 >> V_218 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_92 ( T_3 V_219 )
{
int V_218 ;
for ( V_218 = 0 ; V_218 < 3 ; V_218 ++ ) {
if ( ( ( V_219 >> V_218 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_93 ( struct V_220 * V_221 )
{
if ( ! F_91 ( 0 , V_221 -> V_222 ) ||
! F_91 ( V_221 -> V_222 , V_221 -> V_216 ) ||
! F_91 ( V_221 -> V_216 , V_221 -> V_217 ) ||
! F_91 ( V_221 -> V_217 , V_221 -> V_223 ) ||
! F_91 ( V_221 -> V_223 , V_221 -> V_224 ) ||
! F_91 ( V_221 -> V_224 , V_221 -> V_219 ) ||
! F_91 ( V_221 -> V_219 , 0x00ffffff ) )
return - V_57 ;
if ( ! F_92 ( V_221 -> V_219 ) )
return - V_57 ;
return 0 ;
}
int F_94 ( struct V_191 * V_192 , void * V_193 ,
struct V_194 * V_195 )
{
struct V_220 * V_221 = V_193 ;
struct V_4 * V_5 = F_77 ( V_192 ) ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_7 ;
int V_27 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_27 ( L_2 ) ;
return - V_199 ;
}
F_78 ( V_192 ) ;
F_79 ( & V_192 -> V_20 ) ;
V_27 = - V_57 ;
if ( ! ( V_221 -> V_86 & V_225 ) ) {
V_221 -> V_85 = V_3 -> V_85 ;
V_221 -> V_212 = V_3 -> V_212 ;
V_221 -> V_211 = V_3 -> V_211 ;
V_221 -> V_214 = V_3 -> V_214 ;
if ( ! F_47 ( V_5 ) ) {
V_221 -> V_222 = F_26 ( V_226 ) ;
V_221 -> V_216 = F_26 ( V_227 ) ;
V_221 -> V_217 = F_26 ( V_228 ) ;
V_221 -> V_223 = F_26 ( V_229 ) ;
V_221 -> V_224 = F_26 ( V_230 ) ;
V_221 -> V_219 = F_26 ( V_231 ) ;
}
} else {
if ( V_221 -> V_212 < - 128 || V_221 -> V_212 > 127 )
goto V_206;
if ( V_221 -> V_211 > 255 )
goto V_206;
if ( V_221 -> V_214 > 1023 )
goto V_206;
V_3 -> V_85 = V_221 -> V_85 ;
V_3 -> V_212 = V_221 -> V_212 ;
V_3 -> V_211 = V_221 -> V_211 ;
V_3 -> V_214 = V_221 -> V_214 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_27 = - V_130 ;
goto V_206;
}
F_90 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( V_221 -> V_86 & V_232 ) {
if ( F_47 ( V_5 ) )
goto V_206;
if ( V_3 -> V_28 ) {
V_27 = - V_233 ;
goto V_206;
}
V_27 = F_93 ( V_221 ) ;
if ( V_27 )
goto V_206;
F_95 ( V_226 , V_221 -> V_222 ) ;
F_95 ( V_227 , V_221 -> V_216 ) ;
F_95 ( V_228 , V_221 -> V_217 ) ;
F_95 ( V_229 , V_221 -> V_223 ) ;
F_95 ( V_230 , V_221 -> V_224 ) ;
F_95 ( V_231 , V_221 -> V_219 ) ;
}
}
V_3 -> V_87 = ( V_221 -> V_86 & V_234 ) == 0 ;
V_27 = 0 ;
V_206:
F_80 ( & V_192 -> V_20 ) ;
F_81 ( V_192 ) ;
return V_27 ;
}
void F_96 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_118 * V_8 ;
struct V_1 T_1 * V_7 ;
struct V_42 * V_43 = NULL ;
int V_27 ;
if ( ! F_97 ( V_5 ) )
return;
V_3 = F_98 ( sizeof( * V_3 ) , V_201 ) ;
if ( ! V_3 )
return;
F_79 ( & V_5 -> V_19 . V_20 ) ;
if ( F_17 ( V_5 -> V_3 ) )
goto V_204;
V_3 -> V_6 = V_5 ;
V_8 = NULL ;
if ( ! F_2 ( V_5 ) )
V_8 = F_99 ( & V_5 -> V_19 ,
V_14 ) ;
if ( V_8 == NULL )
V_8 = F_100 ( & V_5 -> V_19 , V_14 ) ;
if ( F_19 ( V_8 ) )
goto V_204;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_27 = F_101 ( V_8 , V_14 ) ;
if ( V_27 ) {
F_102 ( L_4 ) ;
goto V_235;
}
V_3 -> V_13 = V_8 -> V_9 -> V_236 ;
} else {
V_43 = F_103 ( V_8 , NULL ,
0 , V_14 , V_237 ) ;
if ( F_19 ( V_43 ) ) {
F_102 ( L_5 ) ;
V_27 = F_20 ( V_43 ) ;
goto V_235;
}
V_3 -> V_13 = F_63 ( V_43 ) ;
V_27 = F_104 ( V_8 , true ) ;
if ( V_27 ) {
F_102 ( L_6 ) ;
goto V_238;
}
}
V_3 -> V_85 = 0x0101fe ;
V_3 -> V_87 = true ;
V_3 -> V_212 = - 19 ;
V_3 -> V_211 = 75 ;
V_3 -> V_214 = 146 ;
F_105 ( & V_3 -> V_18 , NULL ) ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_238;
F_106 ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_48 ( V_7 ) ;
F_90 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
V_5 -> V_3 = V_3 ;
F_80 ( & V_5 -> V_19 . V_20 ) ;
F_107 ( L_7 ) ;
return;
V_238:
if ( V_43 )
F_108 ( V_43 ) ;
V_235:
F_89 ( V_8 ) ;
V_204:
F_80 ( & V_5 -> V_19 . V_20 ) ;
F_88 ( V_3 ) ;
return;
}
void F_109 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_3 )
return;
F_17 ( V_5 -> V_3 -> V_28 ) ;
F_89 ( V_5 -> V_3 -> V_8 ) ;
F_88 ( V_5 -> V_3 ) ;
}
static struct V_1 T_1 *
F_110 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_5 ) )
V_7 = (struct V_1 T_1 * )
V_3 -> V_8 -> V_9 -> V_10 ;
else
V_7 = F_111 ( & V_5 -> V_11 . V_12 ,
V_3 -> V_13 ) ;
return V_7 ;
}
static void F_112 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_113 ( V_7 ) ;
}
struct V_239 *
F_114 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_239 * error ;
struct V_1 T_1 * V_7 ;
if ( ! V_3 || ! V_3 -> V_28 )
return NULL ;
error = F_82 ( sizeof( * error ) , V_240 ) ;
if ( error == NULL )
return NULL ;
error -> V_241 = F_26 ( V_39 ) ;
error -> V_242 = F_26 ( V_49 ) ;
error -> V_89 = V_3 -> V_13 ;
V_7 = F_110 ( V_3 ) ;
if ( ! V_7 )
goto V_243;
F_115 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_112 ( V_3 , V_7 ) ;
return error ;
V_243:
F_88 ( error ) ;
return NULL ;
}
void
F_116 ( struct V_244 * V_245 ,
struct V_239 * error )
{
F_117 ( V_245 , L_8 ,
error -> V_241 , error -> V_242 ) ;
F_117 ( V_245 , L_9 ,
error -> V_89 ) ;
#define F_118 ( T_4 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_118 ( V_144 ) ;
F_118 ( V_246 ) ;
F_118 ( V_150 ) ;
F_118 ( V_151 ) ;
F_118 ( V_247 ) ;
F_118 ( V_248 ) ;
F_118 ( V_156 ) ;
F_118 ( V_249 ) ;
F_118 ( V_250 ) ;
F_118 ( V_251 ) ;
F_118 ( V_252 ) ;
F_118 ( V_138 ) ;
F_118 ( V_139 ) ;
F_118 ( V_153 ) ;
F_118 ( V_154 ) ;
F_118 ( V_155 ) ;
F_118 ( V_81 ) ;
F_118 ( V_82 ) ;
F_118 ( V_213 ) ;
F_118 ( V_215 ) ;
F_118 ( V_98 ) ;
F_118 ( V_99 ) ;
F_118 ( V_253 ) ;
F_118 ( V_254 ) ;
F_118 ( V_255 ) ;
F_118 ( V_135 ) ;
F_118 ( V_157 ) ;
F_118 ( V_256 ) ;
F_118 ( V_257 ) ;
F_118 ( V_258 ) ;
F_118 ( V_259 ) ;
F_118 ( V_260 ) ;
F_118 ( V_261 ) ;
F_118 ( V_262 ) ;
F_118 ( V_263 ) ;
F_118 ( V_264 ) ;
F_118 ( V_265 ) ;
F_118 ( V_266 ) ;
F_118 ( V_267 ) ;
F_118 ( V_268 ) ;
F_118 ( V_83 ) ;
#undef F_118
}
