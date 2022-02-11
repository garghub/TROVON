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
V_3 -> V_18 . V_17 = V_17 ;
F_9 ( & V_3 -> V_18 , V_16 ) ;
F_10 ( V_16 ) ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
T_2 V_17 )
{
F_6 ( V_3 , V_16 , V_17 ) ;
return F_12 ( & V_3 -> V_18 ,
& V_3 -> V_6 -> V_19 . V_20 ) ;
}
static struct V_15 * F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_21 * V_22 = & V_5 -> V_22 [ V_23 ] ;
return F_14 ( V_22 , V_5 -> V_24 ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
int V_27 ;
F_16 ( V_3 -> V_28 ) ;
F_16 ( F_17 ( V_5 ) && ! ( V_5 -> V_29 & V_30 ) ) ;
V_16 = F_13 ( V_3 ) ;
if ( F_18 ( V_16 ) )
return F_19 ( V_16 ) ;
V_27 = F_20 ( V_16 , 4 ) ;
if ( V_27 ) {
F_21 ( V_16 ) ;
return V_27 ;
}
V_3 -> V_28 = true ;
V_26 = V_16 -> V_26 ;
F_22 ( V_26 , V_31 | V_32 ) ;
F_22 ( V_26 , V_3 -> V_13 | V_33 ) ;
F_22 ( V_26 , V_34 | V_35 ) ;
F_22 ( V_26 , V_36 ) ;
F_23 ( V_26 ) ;
return F_11 ( V_3 , V_16 , NULL ) ;
}
static int F_24 ( struct V_2 * V_3 ,
bool V_37 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
T_3 V_13 = V_3 -> V_13 ;
T_3 V_38 ;
int V_27 ;
F_16 ( ! V_3 -> V_28 ) ;
if ( V_37 )
V_13 |= V_33 ;
V_38 = F_25 ( V_39 ) ;
if ( V_38 & ( 1 << 17 ) )
F_26 ( L_1 , V_38 ) ;
V_16 = F_13 ( V_3 ) ;
if ( F_18 ( V_16 ) )
return F_19 ( V_16 ) ;
V_27 = F_20 ( V_16 , 2 ) ;
if ( V_27 ) {
F_21 ( V_16 ) ;
return V_27 ;
}
V_26 = V_16 -> V_26 ;
F_22 ( V_26 , V_31 | V_40 ) ;
F_22 ( V_26 , V_13 ) ;
F_23 ( V_26 ) ;
F_6 ( V_3 , V_16 , NULL ) ;
return 0 ;
}
static void F_27 ( struct V_41 * V_28 ,
struct V_15 * V_16 )
{
struct V_2 * V_3 =
F_28 ( V_28 , F_29 ( * V_3 ) , V_18 ) ;
struct V_42 * V_43 ;
V_43 = F_30 ( & V_3 -> V_44 ) ;
if ( F_16 ( ! V_43 ) )
return;
F_31 ( V_43 -> V_45 , NULL ,
F_32 ( V_3 -> V_46 -> V_47 ) ) ;
F_33 ( V_43 ) ;
F_34 ( V_43 ) ;
}
static void F_35 ( struct V_41 * V_28 ,
struct V_15 * V_16 )
{
struct V_2 * V_3 =
F_28 ( V_28 , F_29 ( * V_3 ) , V_18 ) ;
struct V_42 * V_43 ;
V_43 = F_30 ( & V_3 -> V_43 ) ;
if ( F_16 ( ! V_43 ) )
return;
F_33 ( V_43 ) ;
F_34 ( V_43 ) ;
V_3 -> V_46 -> V_3 = NULL ;
V_3 -> V_46 = NULL ;
V_3 -> V_28 = false ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
T_3 V_13 = V_3 -> V_13 ;
int V_27 ;
F_16 ( ! V_3 -> V_28 ) ;
V_13 |= V_33 ;
V_16 = F_13 ( V_3 ) ;
if ( F_18 ( V_16 ) )
return F_19 ( V_16 ) ;
V_27 = F_20 ( V_16 , 6 ) ;
if ( V_27 ) {
F_21 ( V_16 ) ;
return V_27 ;
}
V_26 = V_16 -> V_26 ;
F_22 ( V_26 , V_31 | V_40 ) ;
F_22 ( V_26 , V_13 ) ;
F_22 ( V_26 , V_34 | V_35 ) ;
if ( F_17 ( V_5 ) ) {
F_22 ( V_26 , V_36 ) ;
F_22 ( V_26 , V_36 ) ;
F_22 ( V_26 , V_36 ) ;
} else {
F_22 ( V_26 , V_31 | V_48 ) ;
F_22 ( V_26 , V_13 ) ;
F_22 ( V_26 ,
V_34 | V_35 ) ;
}
F_23 ( V_26 ) ;
return F_11 ( V_3 , V_16 ,
F_35 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
return F_12 ( & V_3 -> V_18 ,
& V_3 -> V_6 -> V_19 . V_20 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_27 ;
F_39 ( & V_5 -> V_19 . V_20 ) ;
if ( ! V_3 -> V_44 )
return 0 ;
if ( F_25 ( V_49 ) & V_50 ) {
struct V_15 * V_16 ;
struct V_25 * V_26 ;
V_16 = F_13 ( V_3 ) ;
if ( F_18 ( V_16 ) )
return F_19 ( V_16 ) ;
V_27 = F_20 ( V_16 , 2 ) ;
if ( V_27 ) {
F_21 ( V_16 ) ;
return V_27 ;
}
V_26 = V_16 -> V_26 ;
F_22 ( V_26 ,
V_34 | V_35 ) ;
F_22 ( V_26 , V_36 ) ;
F_23 ( V_26 ) ;
V_27 = F_11 ( V_3 , V_16 ,
F_27 ) ;
if ( V_27 )
return V_27 ;
} else
F_27 ( & V_3 -> V_18 , NULL ) ;
return 0 ;
}
void F_40 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
F_38 ( V_3 ) ;
V_3 -> V_51 = 0 ;
V_3 -> V_52 = 0 ;
V_3 -> V_46 = NULL ;
V_3 -> V_28 = false ;
}
static int F_41 ( T_3 V_53 )
{
switch ( V_53 & V_54 ) {
case V_55 :
return 4 ;
case V_56 :
default:
return - V_57 ;
}
}
static int F_42 ( T_3 V_53 , short V_58 )
{
switch ( V_53 & V_54 ) {
case V_55 :
return V_58 << 1 ;
default:
return - V_57 ;
}
}
static int F_43 ( T_3 V_53 )
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
static int F_44 ( T_3 V_53 )
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
static T_3 F_45 ( struct V_4 * V_5 , T_3 V_61 , T_3 V_58 )
{
T_3 V_62 , V_63 , V_27 ;
if ( F_46 ( V_5 ) ) {
V_62 = 0x1f ;
V_63 = 5 ;
} else {
V_62 = 0x3f ;
V_63 = 6 ;
}
V_27 = ( ( V_61 + V_58 + V_62 ) >> V_63 ) - ( V_61 >> V_63 ) ;
if ( ! F_46 ( V_5 ) )
V_27 <<= 1 ;
V_27 -= 1 ;
return V_27 << 2 ;
}
static void F_47 ( struct V_1 T_1 * V_7 )
{
F_48 ( V_7 -> V_64 , V_65 , sizeof( V_65 ) ) ;
F_48 ( V_7 -> V_66 , V_67 ,
sizeof( V_67 ) ) ;
}
static bool F_49 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 ,
struct V_68 * V_69 )
{
T_3 V_70 , V_71 , V_72 , V_73 ;
#define F_50 12
#define F_51 0xfff
bool V_74 = false ;
int V_75 = F_43 ( V_69 -> V_53 ) ;
int V_76 = F_44 ( V_69 -> V_53 ) ;
if ( V_69 -> V_77 > 1 )
V_70 = ( ( V_69 -> V_78 - 1 ) << F_50 )
/ ( V_69 -> V_77 ) ;
else
V_70 = 1 << F_50 ;
if ( V_69 -> V_79 > 1 )
V_71 = ( ( V_69 -> V_80 - 1 ) << F_50 )
/ ( V_69 -> V_79 ) ;
else
V_71 = 1 << F_50 ;
V_72 = V_70 / V_75 ;
V_73 = V_71 / V_76 ;
V_70 = V_72 * V_75 ;
V_71 = V_73 * V_76 ;
if ( V_70 != V_3 -> V_51 || V_71 != V_3 -> V_52 )
V_74 = true ;
V_3 -> V_51 = V_70 ;
V_3 -> V_52 = V_71 ;
F_52 ( ( ( V_71 & F_51 ) << 20 ) |
( ( V_70 >> F_50 ) << 16 ) |
( ( V_70 & F_51 ) << 3 ) ,
& V_7 -> V_81 ) ;
F_52 ( ( ( V_73 & F_51 ) << 20 ) |
( ( V_72 >> F_50 ) << 16 ) |
( ( V_72 & F_51 ) << 3 ) ,
& V_7 -> V_82 ) ;
F_52 ( ( ( ( V_71 >> F_50 ) << 16 ) |
( ( V_73 >> F_50 ) << 0 ) ) ,
& V_7 -> V_83 ) ;
if ( V_74 )
F_47 ( V_7 ) ;
return V_74 ;
}
static void F_53 ( struct V_2 * V_3 ,
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
V_84 = F_54 ( V_84 ) ;
V_86 |= V_95 ;
} else {
V_84 = F_55 ( V_84 ) ;
V_86 |= V_96 ;
}
break;
case 24 :
case 32 :
V_86 |= V_97 ;
break;
}
F_52 ( V_84 , & V_7 -> V_98 ) ;
F_52 ( V_86 , & V_7 -> V_99 ) ;
}
static T_3 F_56 ( struct V_68 * V_69 )
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
static int F_57 ( struct V_2 * V_3 ,
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
F_39 ( & V_5 -> V_19 . V_20 ) ;
F_16 ( ! F_58 ( & V_5 -> V_19 . V_125 . V_126 ) ) ;
V_27 = F_38 ( V_3 ) ;
if ( V_27 != 0 )
return V_27 ;
V_43 = F_59 ( V_119 , 0 ,
& V_127 ) ;
if ( F_18 ( V_43 ) )
return F_19 ( V_43 ) ;
V_27 = F_60 ( V_43 ) ;
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
if ( F_61 ( V_5 ) )
V_129 |= V_132 ;
V_129 |= V_47 == 0 ?
V_133 : V_134 ;
F_52 ( V_129 , & V_7 -> V_135 ) ;
F_4 ( V_3 , V_7 ) ;
V_27 = F_15 ( V_3 ) ;
if ( V_27 != 0 )
goto V_128;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_27 = - V_130 ;
goto V_128;
}
F_52 ( ( V_69 -> V_136 << 16 ) | V_69 -> V_137 , & V_7 -> V_138 ) ;
F_52 ( ( V_69 -> V_79 << 16 ) | V_69 -> V_77 , & V_7 -> V_139 ) ;
if ( V_69 -> V_53 & V_140 )
V_120 = F_42 ( V_69 -> V_53 , V_69 -> V_141 ) ;
else
V_120 = V_69 -> V_141 ;
V_121 = V_69 -> V_141 ;
V_122 = F_45 ( V_5 , V_69 -> V_142 , V_120 ) ;
V_123 = V_69 -> V_143 ;
F_52 ( F_62 ( V_43 ) + V_69 -> V_142 , & V_7 -> V_144 ) ;
V_124 = V_69 -> V_145 ;
if ( V_69 -> V_53 & V_104 ) {
int V_75 = F_43 ( V_69 -> V_53 ) ;
int V_76 = F_44 ( V_69 -> V_53 ) ;
T_3 V_146 , V_147 ;
V_121 |= ( V_69 -> V_141 / V_75 ) << 16 ;
V_146 = F_45 ( V_5 , V_69 -> V_148 ,
V_69 -> V_141 / V_75 ) ;
V_147 = F_45 ( V_5 , V_69 -> V_149 ,
V_69 -> V_141 / V_75 ) ;
V_122 |= F_63 ( T_3 , V_146 , V_147 ) << 16 ;
V_123 |= ( V_69 -> V_143 / V_76 ) << 16 ;
F_52 ( F_62 ( V_43 ) + V_69 -> V_148 ,
& V_7 -> V_150 ) ;
F_52 ( F_62 ( V_43 ) + V_69 -> V_149 ,
& V_7 -> V_151 ) ;
V_124 |= V_69 -> V_152 << 16 ;
}
F_52 ( V_121 , & V_7 -> V_153 ) ;
F_52 ( V_122 , & V_7 -> V_154 ) ;
F_52 ( V_123 , & V_7 -> V_155 ) ;
F_52 ( V_124 , & V_7 -> V_156 ) ;
V_74 = F_49 ( V_3 , V_7 , V_69 ) ;
F_53 ( V_3 , V_7 ) ;
F_52 ( F_56 ( V_69 ) , & V_7 -> V_157 ) ;
F_4 ( V_3 , V_7 ) ;
V_27 = F_24 ( V_3 , V_74 ) ;
if ( V_27 )
goto V_128;
F_31 ( V_3 -> V_43 -> V_45 , V_119 ,
F_32 ( V_47 ) ) ;
V_3 -> V_44 = V_3 -> V_43 ;
V_3 -> V_43 = V_43 ;
F_64 ( V_5 , F_32 ( V_47 ) ) ;
return 0 ;
V_128:
F_33 ( V_43 ) ;
return V_27 ;
}
int F_65 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 T_1 * V_7 ;
int V_27 ;
F_39 ( & V_5 -> V_19 . V_20 ) ;
F_16 ( ! F_58 ( & V_5 -> V_19 . V_125 . V_126 ) ) ;
V_27 = F_37 ( V_3 ) ;
if ( V_27 != 0 )
return V_27 ;
if ( ! V_3 -> V_28 )
return 0 ;
V_27 = F_38 ( V_3 ) ;
if ( V_27 != 0 )
return V_27 ;
V_7 = F_1 ( V_3 ) ;
F_52 ( 0 , & V_7 -> V_157 ) ;
F_4 ( V_3 , V_7 ) ;
return F_36 ( V_3 ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_158 * V_46 )
{
if ( ! V_46 -> V_28 )
return - V_57 ;
if ( V_46 -> V_159 -> V_160 )
return - V_57 ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
T_3 V_161 = F_25 ( V_162 ) ;
T_3 V_163 ;
if ( F_68 ( V_5 ) >= 4 ) {
V_163 = F_25 ( V_164 ) >> V_165 ;
} else {
if ( V_161 & V_166 )
V_163 = F_25 ( V_167 ) ;
else
V_163 = F_25 ( V_164 ) ;
V_163 >>= V_168 ;
}
V_3 -> V_169 = V_163 ;
}
static int F_69 ( struct V_2 * V_3 ,
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
static int F_70 ( struct V_68 * V_171 )
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
static int F_71 ( struct V_4 * V_5 ,
struct V_170 * V_171 ,
struct V_118 * V_119 )
{
int V_75 = F_43 ( V_171 -> V_86 ) ;
int V_76 = F_44 ( V_171 -> V_86 ) ;
T_3 V_178 ;
int V_94 ;
T_3 V_38 ;
if ( F_72 ( V_5 ) || F_17 ( V_5 ) ) {
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
V_94 = F_41 ( V_171 -> V_86 ) ;
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
if ( F_17 ( V_5 ) || F_72 ( V_5 ) )
V_178 = 255 ;
else
V_178 = 63 ;
if ( V_171 -> V_145 & V_178 || V_171 -> V_152 & V_178 )
return - V_57 ;
if ( F_61 ( V_5 ) && V_171 -> V_145 < 512 )
return - V_57 ;
V_38 = ( V_171 -> V_86 & V_187 ) == V_104 ?
4096 : 8192 ;
if ( V_171 -> V_145 > V_38 || V_171 -> V_152 > 2 * 1024 )
return - V_57 ;
switch ( V_171 -> V_86 & V_187 ) {
case V_188 :
case V_140 :
if ( F_42 ( V_171 -> V_86 , V_171 -> V_181 ) > V_171 -> V_145 )
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
static int F_73 ( struct V_4 * V_5 )
{
T_3 V_161 ;
if ( F_68 ( V_5 ) <= 3 &&
( F_17 ( V_5 ) || ! F_74 ( V_5 ) ) )
return - 1 ;
V_161 = F_25 ( V_162 ) ;
if ( ( V_161 & V_190 ) == 0 )
return - 1 ;
if ( F_61 ( V_5 ) )
return ( V_161 >> 29 ) & 0x3 ;
return 1 ;
}
int F_75 ( struct V_191 * V_192 , void * V_193 ,
struct V_194 * V_195 )
{
struct V_170 * V_196 = V_193 ;
struct V_4 * V_5 = F_76 ( V_192 ) ;
struct V_2 * V_3 ;
struct V_197 * V_198 ;
struct V_158 * V_46 ;
struct V_118 * V_119 ;
struct V_68 * V_69 ;
int V_27 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_26 ( L_2 ) ;
return - V_199 ;
}
if ( ! ( V_196 -> V_86 & V_200 ) ) {
F_77 ( V_192 ) ;
F_78 ( & V_192 -> V_20 ) ;
V_27 = F_65 ( V_3 ) ;
F_79 ( & V_192 -> V_20 ) ;
F_80 ( V_192 ) ;
return V_27 ;
}
V_69 = F_81 ( sizeof( * V_69 ) , V_201 ) ;
if ( ! V_69 )
return - V_130 ;
V_198 = F_82 ( V_192 , V_196 -> V_202 ) ;
if ( ! V_198 ) {
V_27 = - V_203 ;
goto V_204;
}
V_46 = F_83 ( V_198 ) ;
V_119 = F_84 ( V_195 , V_196 -> V_205 ) ;
if ( ! V_119 ) {
V_27 = - V_203 ;
goto V_204;
}
F_77 ( V_192 ) ;
F_78 ( & V_192 -> V_20 ) ;
if ( F_85 ( V_119 ) ) {
F_86 ( L_3 ) ;
V_27 = - V_57 ;
goto V_206;
}
V_27 = F_37 ( V_3 ) ;
if ( V_27 != 0 )
goto V_206;
if ( V_3 -> V_46 != V_46 ) {
struct V_172 * V_173 = & V_46 -> V_89 . V_173 ;
V_27 = F_65 ( V_3 ) ;
if ( V_27 != 0 )
goto V_206;
V_27 = F_66 ( V_3 , V_46 ) ;
if ( V_27 != 0 )
goto V_206;
V_3 -> V_46 = V_46 ;
V_46 -> V_3 = V_3 ;
if ( V_173 -> V_174 > 1024 &&
F_73 ( V_5 ) == V_46 -> V_47 ) {
V_3 -> V_207 = true ;
F_67 ( V_3 ) ;
} else
V_3 -> V_207 = false ;
}
V_27 = F_69 ( V_3 , V_196 ) ;
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
V_27 = F_71 ( V_5 , V_196 , V_119 ) ;
if ( V_27 != 0 )
goto V_206;
V_69 -> V_53 = V_196 -> V_86 & ~ V_210 ;
V_69 -> V_145 = V_196 -> V_145 ;
V_69 -> V_152 = V_196 -> V_152 ;
V_69 -> V_142 = V_196 -> V_142 ;
V_69 -> V_148 = V_196 -> V_148 ;
V_69 -> V_149 = V_196 -> V_149 ;
V_27 = F_70 ( V_69 ) ;
if ( V_27 != 0 )
goto V_206;
V_27 = F_57 ( V_3 , V_119 , V_69 ) ;
if ( V_27 != 0 )
goto V_206;
F_79 ( & V_192 -> V_20 ) ;
F_80 ( V_192 ) ;
F_87 ( V_69 ) ;
return 0 ;
V_206:
F_79 ( & V_192 -> V_20 ) ;
F_80 ( V_192 ) ;
F_88 ( V_119 ) ;
V_204:
F_87 ( V_69 ) ;
return V_27 ;
}
static void F_89 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
F_52 ( ( V_3 -> V_211 << 18 ) | ( V_3 -> V_212 & 0xff ) ,
& V_7 -> V_213 ) ;
F_52 ( V_3 -> V_214 , & V_7 -> V_215 ) ;
}
static bool F_90 ( T_3 V_216 , T_3 V_217 )
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
static bool F_91 ( T_3 V_219 )
{
int V_218 ;
for ( V_218 = 0 ; V_218 < 3 ; V_218 ++ ) {
if ( ( ( V_219 >> V_218 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_92 ( struct V_220 * V_221 )
{
if ( ! F_90 ( 0 , V_221 -> V_222 ) ||
! F_90 ( V_221 -> V_222 , V_221 -> V_216 ) ||
! F_90 ( V_221 -> V_216 , V_221 -> V_217 ) ||
! F_90 ( V_221 -> V_217 , V_221 -> V_223 ) ||
! F_90 ( V_221 -> V_223 , V_221 -> V_224 ) ||
! F_90 ( V_221 -> V_224 , V_221 -> V_219 ) ||
! F_90 ( V_221 -> V_219 , 0x00ffffff ) )
return - V_57 ;
if ( ! F_91 ( V_221 -> V_219 ) )
return - V_57 ;
return 0 ;
}
int F_93 ( struct V_191 * V_192 , void * V_193 ,
struct V_194 * V_195 )
{
struct V_220 * V_221 = V_193 ;
struct V_4 * V_5 = F_76 ( V_192 ) ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_7 ;
int V_27 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_26 ( L_2 ) ;
return - V_199 ;
}
F_77 ( V_192 ) ;
F_78 ( & V_192 -> V_20 ) ;
V_27 = - V_57 ;
if ( ! ( V_221 -> V_86 & V_225 ) ) {
V_221 -> V_85 = V_3 -> V_85 ;
V_221 -> V_212 = V_3 -> V_212 ;
V_221 -> V_211 = V_3 -> V_211 ;
V_221 -> V_214 = V_3 -> V_214 ;
if ( ! F_46 ( V_5 ) ) {
V_221 -> V_222 = F_25 ( V_226 ) ;
V_221 -> V_216 = F_25 ( V_227 ) ;
V_221 -> V_217 = F_25 ( V_228 ) ;
V_221 -> V_223 = F_25 ( V_229 ) ;
V_221 -> V_224 = F_25 ( V_230 ) ;
V_221 -> V_219 = F_25 ( V_231 ) ;
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
F_89 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( V_221 -> V_86 & V_232 ) {
if ( F_46 ( V_5 ) )
goto V_206;
if ( V_3 -> V_28 ) {
V_27 = - V_233 ;
goto V_206;
}
V_27 = F_92 ( V_221 ) ;
if ( V_27 )
goto V_206;
F_94 ( V_226 , V_221 -> V_222 ) ;
F_94 ( V_227 , V_221 -> V_216 ) ;
F_94 ( V_228 , V_221 -> V_217 ) ;
F_94 ( V_229 , V_221 -> V_223 ) ;
F_94 ( V_230 , V_221 -> V_224 ) ;
F_94 ( V_231 , V_221 -> V_219 ) ;
}
}
V_3 -> V_87 = ( V_221 -> V_86 & V_234 ) == 0 ;
V_27 = 0 ;
V_206:
F_79 ( & V_192 -> V_20 ) ;
F_80 ( V_192 ) ;
return V_27 ;
}
void F_95 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_118 * V_8 ;
struct V_1 T_1 * V_7 ;
struct V_42 * V_43 = NULL ;
int V_27 ;
if ( ! F_96 ( V_5 ) )
return;
V_3 = F_97 ( sizeof( * V_3 ) , V_201 ) ;
if ( ! V_3 )
return;
F_78 ( & V_5 -> V_19 . V_20 ) ;
if ( F_16 ( V_5 -> V_3 ) )
goto V_204;
V_3 -> V_6 = V_5 ;
V_8 = NULL ;
if ( ! F_2 ( V_5 ) )
V_8 = F_98 ( & V_5 -> V_19 ,
V_14 ) ;
if ( V_8 == NULL )
V_8 = F_99 ( & V_5 -> V_19 , V_14 ) ;
if ( F_18 ( V_8 ) )
goto V_204;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_27 = F_100 ( V_8 , V_14 ) ;
if ( V_27 ) {
F_101 ( L_4 ) ;
goto V_235;
}
V_3 -> V_13 = V_8 -> V_9 -> V_236 ;
} else {
V_43 = F_102 ( V_8 , NULL ,
0 , V_14 , V_237 ) ;
if ( F_18 ( V_43 ) ) {
F_101 ( L_5 ) ;
V_27 = F_19 ( V_43 ) ;
goto V_235;
}
V_3 -> V_13 = F_62 ( V_43 ) ;
V_27 = F_103 ( V_8 , true ) ;
if ( V_27 ) {
F_101 ( L_6 ) ;
goto V_238;
}
}
V_3 -> V_85 = 0x0101fe ;
V_3 -> V_87 = true ;
V_3 -> V_212 = - 19 ;
V_3 -> V_211 = 75 ;
V_3 -> V_214 = 146 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_238;
F_104 ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_47 ( V_7 ) ;
F_89 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
V_5 -> V_3 = V_3 ;
F_79 ( & V_5 -> V_19 . V_20 ) ;
F_105 ( L_7 ) ;
return;
V_238:
if ( V_43 )
F_106 ( V_43 ) ;
V_235:
F_107 ( V_8 ) ;
V_204:
F_79 ( & V_5 -> V_19 . V_20 ) ;
F_87 ( V_3 ) ;
return;
}
void F_108 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_3 )
return;
F_16 ( V_5 -> V_3 -> V_28 ) ;
F_88 ( V_5 -> V_3 -> V_8 ) ;
F_87 ( V_5 -> V_3 ) ;
}
static struct V_1 T_1 *
F_109 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_5 ) )
V_7 = (struct V_1 T_1 * )
V_3 -> V_8 -> V_9 -> V_10 ;
else
V_7 = F_110 ( & V_5 -> V_11 . V_12 ,
V_3 -> V_13 ) ;
return V_7 ;
}
static void F_111 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_112 ( V_7 ) ;
}
struct V_239 *
F_113 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_239 * error ;
struct V_1 T_1 * V_7 ;
if ( ! V_3 || ! V_3 -> V_28 )
return NULL ;
error = F_81 ( sizeof( * error ) , V_240 ) ;
if ( error == NULL )
return NULL ;
error -> V_241 = F_25 ( V_39 ) ;
error -> V_242 = F_25 ( V_49 ) ;
error -> V_89 = V_3 -> V_13 ;
V_7 = F_109 ( V_3 ) ;
if ( ! V_7 )
goto V_243;
F_114 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_111 ( V_3 , V_7 ) ;
return error ;
V_243:
F_87 ( error ) ;
return NULL ;
}
void
F_115 ( struct V_244 * V_245 ,
struct V_239 * error )
{
F_116 ( V_245 , L_8 ,
error -> V_241 , error -> V_242 ) ;
F_116 ( V_245 , L_9 ,
error -> V_89 ) ;
#define F_117 ( T_4 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_117 ( V_144 ) ;
F_117 ( V_246 ) ;
F_117 ( V_150 ) ;
F_117 ( V_151 ) ;
F_117 ( V_247 ) ;
F_117 ( V_248 ) ;
F_117 ( V_156 ) ;
F_117 ( V_249 ) ;
F_117 ( V_250 ) ;
F_117 ( V_251 ) ;
F_117 ( V_252 ) ;
F_117 ( V_138 ) ;
F_117 ( V_139 ) ;
F_117 ( V_153 ) ;
F_117 ( V_154 ) ;
F_117 ( V_155 ) ;
F_117 ( V_81 ) ;
F_117 ( V_82 ) ;
F_117 ( V_213 ) ;
F_117 ( V_215 ) ;
F_117 ( V_98 ) ;
F_117 ( V_99 ) ;
F_117 ( V_253 ) ;
F_117 ( V_254 ) ;
F_117 ( V_255 ) ;
F_117 ( V_135 ) ;
F_117 ( V_157 ) ;
F_117 ( V_256 ) ;
F_117 ( V_257 ) ;
F_117 ( V_258 ) ;
F_117 ( V_259 ) ;
F_117 ( V_260 ) ;
F_117 ( V_261 ) ;
F_117 ( V_262 ) ;
F_117 ( V_263 ) ;
F_117 ( V_264 ) ;
F_117 ( V_265 ) ;
F_117 ( V_266 ) ;
F_117 ( V_267 ) ;
F_117 ( V_268 ) ;
F_117 ( V_83 ) ;
#undef F_117
}
