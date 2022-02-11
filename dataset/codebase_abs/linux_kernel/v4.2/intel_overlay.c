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
F_10 ( & V_3 -> V_19 ,
V_16 -> V_20 ) ;
V_18 = F_11 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_3 -> V_21 = F_8 ;
V_18 = F_12 ( V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
F_10 ( & V_3 -> V_19 , NULL ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
int V_18 ;
F_9 ( V_3 -> V_22 ) ;
F_9 ( F_14 ( V_6 ) && ! ( V_5 -> V_23 & V_24 ) ) ;
V_18 = F_15 ( V_16 , 4 ) ;
if ( V_18 )
return V_18 ;
V_3 -> V_22 = true ;
F_16 ( V_16 , V_25 | V_26 ) ;
F_16 ( V_16 , V_3 -> V_27 | V_28 ) ;
F_16 ( V_16 , V_29 | V_30 ) ;
F_16 ( V_16 , V_31 ) ;
F_17 ( V_16 ) ;
return F_7 ( V_3 , NULL ) ;
}
static int F_18 ( struct V_2 * V_3 ,
bool V_32 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
T_2 V_27 = V_3 -> V_27 ;
T_2 V_33 ;
int V_18 ;
F_9 ( ! V_3 -> V_22 ) ;
if ( V_32 )
V_27 |= V_28 ;
V_33 = F_19 ( V_34 ) ;
if ( V_33 & ( 1 << 17 ) )
F_20 ( L_1 , V_33 ) ;
V_18 = F_15 ( V_16 , 2 ) ;
if ( V_18 )
return V_18 ;
F_16 ( V_16 , V_25 | V_35 ) ;
F_16 ( V_16 , V_27 ) ;
F_17 ( V_16 ) ;
F_9 ( V_3 -> V_19 ) ;
F_10 ( & V_3 -> V_19 ,
V_16 -> V_20 ) ;
return F_11 ( V_16 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_38 ;
F_22 ( V_37 ) ;
F_23 ( & V_37 -> V_39 ) ;
V_3 -> V_38 = NULL ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_40 ;
if ( F_9 ( ! V_37 ) )
return;
F_22 ( V_37 ) ;
F_23 ( & V_37 -> V_39 ) ;
V_3 -> V_40 = NULL ;
V_3 -> V_41 -> V_3 = NULL ;
V_3 -> V_41 = NULL ;
V_3 -> V_22 = false ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
T_2 V_27 = V_3 -> V_27 ;
int V_18 ;
F_9 ( ! V_3 -> V_22 ) ;
V_27 |= V_28 ;
V_18 = F_15 ( V_16 , 6 ) ;
if ( V_18 )
return V_18 ;
F_16 ( V_16 , V_25 | V_35 ) ;
F_16 ( V_16 , V_27 ) ;
F_16 ( V_16 , V_29 | V_30 ) ;
if ( F_14 ( V_6 ) ) {
F_16 ( V_16 , V_31 ) ;
F_16 ( V_16 , V_31 ) ;
F_16 ( V_16 , V_31 ) ;
} else {
F_16 ( V_16 , V_25 | V_42 ) ;
F_16 ( V_16 , V_27 ) ;
F_16 ( V_16 , V_29 | V_30 ) ;
}
F_17 ( V_16 ) ;
return F_7 ( V_3 , F_24 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
int V_18 ;
if ( V_3 -> V_19 == NULL )
return 0 ;
V_18 = F_12 ( V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
if ( V_3 -> V_21 )
V_3 -> V_21 ( V_3 ) ;
F_10 ( & V_3 -> V_19 , NULL ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
int V_18 ;
F_9 ( ! F_28 ( & V_6 -> V_43 ) ) ;
if ( ! V_3 -> V_38 )
return 0 ;
if ( F_19 ( V_44 ) & V_45 ) {
V_18 = F_15 ( V_16 , 2 ) ;
if ( V_18 )
return V_18 ;
F_16 ( V_16 , V_29 | V_30 ) ;
F_16 ( V_16 , V_31 ) ;
F_17 ( V_16 ) ;
V_18 = F_7 ( V_3 ,
F_21 ) ;
if ( V_18 )
return V_18 ;
}
F_21 ( V_3 ) ;
F_29 ( V_3 -> V_38 , NULL ,
F_30 ( V_3 -> V_41 -> V_46 ) ) ;
return 0 ;
}
void F_31 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
F_27 ( V_3 ) ;
V_3 -> V_19 = NULL ;
V_3 -> V_47 = 0 ;
V_3 -> V_48 = 0 ;
V_3 -> V_41 = NULL ;
V_3 -> V_22 = false ;
}
static int F_32 ( T_2 V_49 )
{
switch ( V_49 & V_50 ) {
case V_51 :
return 4 ;
case V_52 :
default:
return - V_53 ;
}
}
static int F_33 ( T_2 V_49 , short V_54 )
{
switch ( V_49 & V_50 ) {
case V_51 :
return V_54 << 1 ;
default:
return - V_53 ;
}
}
static int F_34 ( T_2 V_49 )
{
switch ( V_49 & V_50 ) {
case V_51 :
case V_55 :
return 2 ;
case V_52 :
case V_56 :
return 4 ;
default:
return - V_53 ;
}
}
static int F_35 ( T_2 V_49 )
{
switch ( V_49 & V_50 ) {
case V_55 :
case V_56 :
return 2 ;
case V_51 :
case V_52 :
return 1 ;
default:
return - V_53 ;
}
}
static T_2 F_36 ( struct V_14 * V_6 , T_2 V_57 , T_2 V_54 )
{
T_2 V_58 , V_59 , V_18 ;
if ( F_37 ( V_6 ) ) {
V_58 = 0x1f ;
V_59 = 5 ;
} else {
V_58 = 0x3f ;
V_59 = 6 ;
}
V_18 = ( ( V_57 + V_54 + V_58 ) >> V_59 ) - ( V_57 >> V_59 ) ;
if ( ! F_37 ( V_6 ) )
V_18 <<= 1 ;
V_18 -= 1 ;
return V_18 << 2 ;
}
static void F_38 ( struct V_1 T_1 * V_8 )
{
F_39 ( V_8 -> V_60 , V_61 , sizeof( V_61 ) ) ;
F_39 ( V_8 -> V_62 , V_63 ,
sizeof( V_63 ) ) ;
}
static bool F_40 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 ,
struct V_64 * V_65 )
{
T_2 V_66 , V_67 , V_68 , V_69 ;
#define F_41 12
#define F_42 0xfff
bool V_70 = false ;
int V_71 = F_34 ( V_65 -> V_49 ) ;
int V_72 = F_35 ( V_65 -> V_49 ) ;
if ( V_65 -> V_73 > 1 )
V_66 = ( ( V_65 -> V_74 - 1 ) << F_41 )
/ ( V_65 -> V_73 ) ;
else
V_66 = 1 << F_41 ;
if ( V_65 -> V_75 > 1 )
V_67 = ( ( V_65 -> V_76 - 1 ) << F_41 )
/ ( V_65 -> V_75 ) ;
else
V_67 = 1 << F_41 ;
V_68 = V_66 / V_71 ;
V_69 = V_67 / V_72 ;
V_66 = V_68 * V_71 ;
V_67 = V_69 * V_72 ;
if ( V_66 != V_3 -> V_47 || V_67 != V_3 -> V_48 )
V_70 = true ;
V_3 -> V_47 = V_66 ;
V_3 -> V_48 = V_67 ;
F_43 ( ( ( V_67 & F_42 ) << 20 ) |
( ( V_66 >> F_41 ) << 16 ) |
( ( V_66 & F_42 ) << 3 ) ,
& V_8 -> V_77 ) ;
F_43 ( ( ( V_69 & F_42 ) << 20 ) |
( ( V_68 >> F_41 ) << 16 ) |
( ( V_68 & F_42 ) << 3 ) ,
& V_8 -> V_78 ) ;
F_43 ( ( ( ( V_67 >> F_41 ) << 16 ) |
( ( V_69 >> F_41 ) << 0 ) ) ,
& V_8 -> V_79 ) ;
if ( V_70 )
F_38 ( V_8 ) ;
return V_70 ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
T_2 V_80 = V_3 -> V_81 ;
T_2 V_82 ;
V_82 = 0 ;
if ( V_3 -> V_83 )
V_82 |= V_84 ;
switch ( V_3 -> V_41 -> V_39 . V_85 -> V_86 -> V_87 ) {
case 8 :
V_80 = 0 ;
V_82 |= V_88 ;
break;
case 16 :
if ( V_3 -> V_41 -> V_39 . V_85 -> V_86 -> V_89 == 15 ) {
V_80 = F_45 ( V_80 ) ;
V_82 |= V_90 ;
} else {
V_80 = F_46 ( V_80 ) ;
V_82 |= V_91 ;
}
break;
case 24 :
case 32 :
V_82 |= V_92 ;
break;
}
F_43 ( V_80 , & V_8 -> V_93 ) ;
F_43 ( V_82 , & V_8 -> V_94 ) ;
}
static T_2 F_47 ( struct V_64 * V_65 )
{
T_2 V_95 = V_96 | V_97 | V_98 ;
if ( V_65 -> V_49 & V_99 ) {
switch ( V_65 -> V_49 & V_50 ) {
case V_51 :
V_95 |= V_100 ;
break;
case V_55 :
V_95 |= V_101 ;
break;
case V_52 :
case V_56 :
V_95 |= V_102 ;
break;
}
} else {
switch ( V_65 -> V_49 & V_50 ) {
case V_51 :
V_95 |= V_103 ;
break;
case V_52 :
V_95 |= V_104 ;
break;
}
switch ( V_65 -> V_49 & V_105 ) {
case V_106 :
break;
case V_107 :
V_95 |= V_108 ;
break;
case V_109 :
V_95 |= V_110 ;
break;
case V_111 :
V_95 |= V_112 ;
break;
}
}
return V_95 ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_36 * V_113 ,
struct V_64 * V_65 )
{
int V_18 , V_114 ;
struct V_1 T_1 * V_8 ;
bool V_70 = false ;
struct V_14 * V_6 = V_3 -> V_6 ;
T_2 V_115 , V_116 , V_117 , V_118 ;
enum V_46 V_46 = V_3 -> V_41 -> V_46 ;
F_9 ( ! F_28 ( & V_6 -> V_43 ) ) ;
F_9 ( ! F_49 ( & V_6 -> V_119 . V_120 ) ) ;
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_50 ( V_113 , 0 , NULL ,
& V_121 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_51 ( V_113 ) ;
if ( V_18 )
goto V_122;
if ( ! V_3 -> V_22 ) {
T_2 V_123 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_124 ;
goto V_122;
}
V_123 = V_125 ;
if ( F_52 ( V_3 -> V_6 ) )
V_123 |= V_126 ;
V_123 |= V_46 == 0 ?
V_127 : V_128 ;
F_43 ( V_123 , & V_8 -> V_129 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_13 ( V_3 ) ;
if ( V_18 != 0 )
goto V_122;
}
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_124 ;
goto V_122;
}
F_43 ( ( V_65 -> V_130 << 16 ) | V_65 -> V_131 , & V_8 -> V_132 ) ;
F_43 ( ( V_65 -> V_75 << 16 ) | V_65 -> V_73 , & V_8 -> V_133 ) ;
if ( V_65 -> V_49 & V_134 )
V_114 = F_33 ( V_65 -> V_49 , V_65 -> V_135 ) ;
else
V_114 = V_65 -> V_135 ;
V_115 = V_65 -> V_135 ;
V_116 = F_36 ( V_3 -> V_6 , V_65 -> V_136 , V_114 ) ;
V_117 = V_65 -> V_137 ;
F_43 ( F_4 ( V_113 ) + V_65 -> V_136 , & V_8 -> V_138 ) ;
V_118 = V_65 -> V_139 ;
if ( V_65 -> V_49 & V_99 ) {
int V_71 = F_34 ( V_65 -> V_49 ) ;
int V_72 = F_35 ( V_65 -> V_49 ) ;
T_2 V_140 , V_141 ;
V_115 |= ( V_65 -> V_135 / V_71 ) << 16 ;
V_140 = F_36 ( V_3 -> V_6 , V_65 -> V_142 ,
V_65 -> V_135 / V_71 ) ;
V_141 = F_36 ( V_3 -> V_6 , V_65 -> V_143 ,
V_65 -> V_135 / V_71 ) ;
V_116 |= F_53 ( T_2 , V_140 , V_141 ) << 16 ;
V_117 |= ( V_65 -> V_137 / V_72 ) << 16 ;
F_43 ( F_4 ( V_113 ) + V_65 -> V_142 , & V_8 -> V_144 ) ;
F_43 ( F_4 ( V_113 ) + V_65 -> V_143 , & V_8 -> V_145 ) ;
V_118 |= V_65 -> V_146 << 16 ;
}
F_43 ( V_115 , & V_8 -> V_147 ) ;
F_43 ( V_116 , & V_8 -> V_148 ) ;
F_43 ( V_117 , & V_8 -> V_149 ) ;
F_43 ( V_118 , & V_8 -> V_150 ) ;
V_70 = F_40 ( V_3 , V_8 , V_65 ) ;
F_44 ( V_3 , V_8 ) ;
F_43 ( F_47 ( V_65 ) , & V_8 -> V_151 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_18 ( V_3 , V_70 ) ;
if ( V_18 )
goto V_122;
F_29 ( V_3 -> V_40 , V_113 ,
F_30 ( V_46 ) ) ;
V_3 -> V_38 = V_3 -> V_40 ;
V_3 -> V_40 = V_113 ;
F_54 ( V_6 ,
F_30 ( V_46 ) ) ;
return 0 ;
V_122:
F_22 ( V_113 ) ;
return V_18 ;
}
int F_55 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_8 ;
struct V_14 * V_6 = V_3 -> V_6 ;
int V_18 ;
F_9 ( ! F_28 ( & V_6 -> V_43 ) ) ;
F_9 ( ! F_49 ( & V_6 -> V_119 . V_120 ) ) ;
V_18 = F_26 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( ! V_3 -> V_22 )
return 0 ;
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_8 = F_1 ( V_3 ) ;
F_43 ( 0 , & V_8 -> V_151 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_25 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
F_24 ( V_3 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_152 * V_41 )
{
if ( ! V_41 -> V_22 )
return - V_53 ;
if ( V_41 -> V_153 -> V_154 )
return - V_53 ;
return 0 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_155 = F_19 ( V_156 ) ;
T_2 V_157 ;
if ( F_58 ( V_6 ) -> V_158 >= 4 ) {
V_157 = F_19 ( V_159 ) >> V_160 ;
} else {
if ( V_155 & V_161 )
V_157 = F_19 ( V_162 ) ;
else
V_157 = F_19 ( V_159 ) ;
V_157 >>= V_163 ;
}
V_3 -> V_164 = V_157 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_165 * V_166 )
{
struct V_167 * V_168 = & V_3 -> V_41 -> V_39 . V_168 ;
if ( V_166 -> V_131 < V_168 -> V_169 &&
V_166 -> V_131 + V_166 -> V_170 <= V_168 -> V_169 &&
V_166 -> V_130 < V_168 -> V_171 &&
V_166 -> V_130 + V_166 -> V_172 <= V_168 -> V_171 )
return 0 ;
else
return - V_53 ;
}
static int F_60 ( struct V_64 * V_166 )
{
T_2 V_33 ;
V_33 = ( ( V_166 -> V_76 << 16 ) / V_166 -> V_75 ) >> 16 ;
if ( V_33 > 7 )
return - V_53 ;
V_33 = ( ( V_166 -> V_74 << 16 ) / V_166 -> V_73 ) >> 16 ;
if ( V_33 > 7 )
return - V_53 ;
return 0 ;
}
static int F_61 ( struct V_14 * V_6 ,
struct V_165 * V_166 ,
struct V_36 * V_113 )
{
int V_71 = F_34 ( V_166 -> V_82 ) ;
int V_72 = F_35 ( V_166 -> V_82 ) ;
T_2 V_173 ;
int V_89 ;
T_2 V_33 ;
if ( F_62 ( V_6 ) || F_14 ( V_6 ) ) {
if ( V_166 -> V_174 > V_175 ||
V_166 -> V_176 > V_177 )
return - V_53 ;
} else {
if ( V_166 -> V_174 > V_178 ||
V_166 -> V_176 > V_179 )
return - V_53 ;
}
if ( V_166 -> V_174 < V_180 * 4 ||
V_166 -> V_176 < V_181 * 4 )
return - V_53 ;
switch ( V_166 -> V_82 & V_182 ) {
case V_183 :
return - V_53 ;
case V_134 :
if ( V_72 != 1 )
return - V_53 ;
V_89 = F_32 ( V_166 -> V_82 ) ;
if ( V_89 < 0 )
return V_89 ;
V_166 -> V_146 = 0 ;
V_166 -> V_142 = 0 ;
V_166 -> V_143 = 0 ;
if ( V_166 -> V_136 % V_89 )
return - V_53 ;
break;
case V_99 :
if ( V_72 < 0 || V_71 < 0 )
return - V_53 ;
break;
default:
return - V_53 ;
}
if ( V_166 -> V_176 % V_71 )
return - V_53 ;
if ( F_14 ( V_6 ) || F_62 ( V_6 ) )
V_173 = 255 ;
else
V_173 = 63 ;
if ( V_166 -> V_139 & V_173 || V_166 -> V_146 & V_173 )
return - V_53 ;
if ( F_52 ( V_6 ) && V_166 -> V_139 < 512 )
return - V_53 ;
V_33 = ( V_166 -> V_82 & V_182 ) == V_99 ?
4096 : 8192 ;
if ( V_166 -> V_139 > V_33 || V_166 -> V_146 > 2 * 1024 )
return - V_53 ;
switch ( V_166 -> V_82 & V_182 ) {
case V_183 :
case V_134 :
if ( F_33 ( V_166 -> V_82 , V_166 -> V_176 ) > V_166 -> V_139 )
return - V_53 ;
V_33 = V_166 -> V_139 * V_166 -> V_174 ;
if ( V_166 -> V_136 + V_33 > V_113 -> V_39 . V_184 )
return - V_53 ;
break;
case V_99 :
if ( V_166 -> V_176 > V_166 -> V_139 )
return - V_53 ;
if ( V_166 -> V_176 / V_71 > V_166 -> V_146 )
return - V_53 ;
V_33 = V_166 -> V_139 * V_166 -> V_174 ;
if ( V_166 -> V_136 + V_33 > V_113 -> V_39 . V_184 )
return - V_53 ;
V_33 = V_166 -> V_146 * ( V_166 -> V_174 / V_72 ) ;
if ( V_166 -> V_142 + V_33 > V_113 -> V_39 . V_184 ||
V_166 -> V_143 + V_33 > V_113 -> V_39 . V_184 )
return - V_53 ;
break;
}
return 0 ;
}
static int F_63 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_155 ;
if ( F_58 ( V_6 ) -> V_158 <= 3 && ( F_14 ( V_6 ) || ! F_64 ( V_6 ) ) )
return - 1 ;
V_155 = F_19 ( V_156 ) ;
if ( ( V_155 & V_185 ) == 0 )
return - 1 ;
if ( F_52 ( V_6 ) )
return ( V_155 >> 29 ) & 0x3 ;
return 1 ;
}
int F_65 ( struct V_14 * V_6 , void * V_186 ,
struct V_187 * V_188 )
{
struct V_165 * V_189 = V_186 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_190 * V_191 ;
struct V_152 * V_41 ;
struct V_36 * V_113 ;
struct V_64 * V_65 ;
int V_18 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_20 ( L_2 ) ;
return - V_192 ;
}
if ( ! ( V_189 -> V_82 & V_193 ) ) {
F_66 ( V_6 ) ;
F_67 ( & V_6 -> V_43 ) ;
V_18 = F_55 ( V_3 ) ;
F_68 ( & V_6 -> V_43 ) ;
F_69 ( V_6 ) ;
return V_18 ;
}
V_65 = F_70 ( sizeof( * V_65 ) , V_194 ) ;
if ( ! V_65 )
return - V_124 ;
V_191 = F_71 ( V_6 , V_189 -> V_195 ) ;
if ( ! V_191 ) {
V_18 = - V_196 ;
goto V_197;
}
V_41 = F_72 ( V_191 ) ;
V_113 = F_73 ( F_74 ( V_6 , V_188 ,
V_189 -> V_198 ) ) ;
if ( & V_113 -> V_39 == NULL ) {
V_18 = - V_196 ;
goto V_197;
}
F_66 ( V_6 ) ;
F_67 ( & V_6 -> V_43 ) ;
if ( V_113 -> V_199 ) {
F_75 ( L_3 ) ;
V_18 = - V_53 ;
goto V_200;
}
V_18 = F_26 ( V_3 ) ;
if ( V_18 != 0 )
goto V_200;
if ( V_3 -> V_41 != V_41 ) {
struct V_167 * V_168 = & V_41 -> V_39 . V_168 ;
V_18 = F_55 ( V_3 ) ;
if ( V_18 != 0 )
goto V_200;
V_18 = F_56 ( V_3 , V_41 ) ;
if ( V_18 != 0 )
goto V_200;
V_3 -> V_41 = V_41 ;
V_41 -> V_3 = V_3 ;
if ( V_168 -> V_169 > 1024 &&
F_63 ( V_6 ) == V_41 -> V_46 ) {
V_3 -> V_201 = true ;
F_57 ( V_3 ) ;
} else
V_3 -> V_201 = false ;
}
V_18 = F_59 ( V_3 , V_189 ) ;
if ( V_18 != 0 )
goto V_200;
if ( V_3 -> V_201 ) {
V_65 -> V_130 = ( ( ( ( T_2 ) V_189 -> V_130 ) << 12 ) /
V_3 -> V_164 ) ;
V_65 -> V_75 = ( ( ( ( T_2 ) V_189 -> V_172 ) << 12 ) /
V_3 -> V_164 ) + 1 ;
} else {
V_65 -> V_130 = V_189 -> V_130 ;
V_65 -> V_75 = V_189 -> V_172 ;
}
V_65 -> V_131 = V_189 -> V_131 ;
V_65 -> V_73 = V_189 -> V_170 ;
V_65 -> V_135 = V_189 -> V_176 ;
V_65 -> V_137 = V_189 -> V_174 ;
V_65 -> V_74 = V_189 -> V_202 ;
V_65 -> V_76 = V_189 -> V_203 ;
if ( V_65 -> V_76 > V_65 -> V_137 ||
V_65 -> V_74 > V_65 -> V_135 ) {
V_18 = - V_53 ;
goto V_200;
}
V_18 = F_61 ( V_6 , V_189 , V_113 ) ;
if ( V_18 != 0 )
goto V_200;
V_65 -> V_49 = V_189 -> V_82 & ~ V_204 ;
V_65 -> V_139 = V_189 -> V_139 ;
V_65 -> V_146 = V_189 -> V_146 ;
V_65 -> V_136 = V_189 -> V_136 ;
V_65 -> V_142 = V_189 -> V_142 ;
V_65 -> V_143 = V_189 -> V_143 ;
V_18 = F_60 ( V_65 ) ;
if ( V_18 != 0 )
goto V_200;
V_18 = F_48 ( V_3 , V_113 , V_65 ) ;
if ( V_18 != 0 )
goto V_200;
F_68 ( & V_6 -> V_43 ) ;
F_69 ( V_6 ) ;
F_76 ( V_65 ) ;
return 0 ;
V_200:
F_68 ( & V_6 -> V_43 ) ;
F_69 ( V_6 ) ;
F_77 ( & V_113 -> V_39 ) ;
V_197:
F_76 ( V_65 ) ;
return V_18 ;
}
static void F_78 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
F_43 ( ( V_3 -> V_205 << 18 ) | ( V_3 -> V_206 & 0xff ) ,
& V_8 -> V_207 ) ;
F_43 ( V_3 -> V_208 , & V_8 -> V_209 ) ;
}
static bool F_79 ( T_2 V_210 , T_2 V_211 )
{
int V_212 ;
if ( V_210 & 0xff000000 || V_211 & 0xff000000 )
return false ;
for ( V_212 = 0 ; V_212 < 3 ; V_212 ++ ) {
if ( ( ( V_210 >> V_212 * 8 ) & 0xff ) >= ( ( V_211 >> V_212 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_80 ( T_2 V_213 )
{
int V_212 ;
for ( V_212 = 0 ; V_212 < 3 ; V_212 ++ ) {
if ( ( ( V_213 >> V_212 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_81 ( struct V_214 * V_215 )
{
if ( ! F_79 ( 0 , V_215 -> V_216 ) ||
! F_79 ( V_215 -> V_216 , V_215 -> V_210 ) ||
! F_79 ( V_215 -> V_210 , V_215 -> V_211 ) ||
! F_79 ( V_215 -> V_211 , V_215 -> V_217 ) ||
! F_79 ( V_215 -> V_217 , V_215 -> V_218 ) ||
! F_79 ( V_215 -> V_218 , V_215 -> V_213 ) ||
! F_79 ( V_215 -> V_213 , 0x00ffffff ) )
return - V_53 ;
if ( ! F_80 ( V_215 -> V_213 ) )
return - V_53 ;
return 0 ;
}
int F_82 ( struct V_14 * V_6 , void * V_186 ,
struct V_187 * V_188 )
{
struct V_214 * V_215 = V_186 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_8 ;
int V_18 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_20 ( L_2 ) ;
return - V_192 ;
}
F_66 ( V_6 ) ;
F_67 ( & V_6 -> V_43 ) ;
V_18 = - V_53 ;
if ( ! ( V_215 -> V_82 & V_219 ) ) {
V_215 -> V_81 = V_3 -> V_81 ;
V_215 -> V_206 = V_3 -> V_206 ;
V_215 -> V_205 = V_3 -> V_205 ;
V_215 -> V_208 = V_3 -> V_208 ;
if ( ! F_37 ( V_6 ) ) {
V_215 -> V_216 = F_19 ( V_220 ) ;
V_215 -> V_210 = F_19 ( V_221 ) ;
V_215 -> V_211 = F_19 ( V_222 ) ;
V_215 -> V_217 = F_19 ( V_223 ) ;
V_215 -> V_218 = F_19 ( V_224 ) ;
V_215 -> V_213 = F_19 ( V_225 ) ;
}
} else {
if ( V_215 -> V_206 < - 128 || V_215 -> V_206 > 127 )
goto V_200;
if ( V_215 -> V_205 > 255 )
goto V_200;
if ( V_215 -> V_208 > 1023 )
goto V_200;
V_3 -> V_81 = V_215 -> V_81 ;
V_3 -> V_206 = V_215 -> V_206 ;
V_3 -> V_205 = V_215 -> V_205 ;
V_3 -> V_208 = V_215 -> V_208 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_124 ;
goto V_200;
}
F_78 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
if ( V_215 -> V_82 & V_226 ) {
if ( F_37 ( V_6 ) )
goto V_200;
if ( V_3 -> V_22 ) {
V_18 = - V_227 ;
goto V_200;
}
V_18 = F_81 ( V_215 ) ;
if ( V_18 )
goto V_200;
F_83 ( V_220 , V_215 -> V_216 ) ;
F_83 ( V_221 , V_215 -> V_210 ) ;
F_83 ( V_222 , V_215 -> V_211 ) ;
F_83 ( V_223 , V_215 -> V_217 ) ;
F_83 ( V_224 , V_215 -> V_218 ) ;
F_83 ( V_225 , V_215 -> V_213 ) ;
}
}
V_3 -> V_83 = ( V_215 -> V_82 & V_228 ) == 0 ;
V_18 = 0 ;
V_200:
F_68 ( & V_6 -> V_43 ) ;
F_69 ( V_6 ) ;
return V_18 ;
}
void F_84 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_36 * V_9 ;
struct V_1 T_1 * V_8 ;
int V_18 ;
if ( ! F_85 ( V_6 ) )
return;
V_3 = F_86 ( sizeof( * V_3 ) , V_194 ) ;
if ( ! V_3 )
return;
F_67 ( & V_6 -> V_43 ) ;
if ( F_9 ( V_5 -> V_3 ) )
goto V_197;
V_3 -> V_6 = V_6 ;
V_9 = NULL ;
if ( ! F_2 ( V_6 ) )
V_9 = F_87 ( V_6 , V_229 ) ;
if ( V_9 == NULL )
V_9 = F_88 ( V_6 , V_229 ) ;
if ( V_9 == NULL )
goto V_197;
V_3 -> V_9 = V_9 ;
if ( F_2 ( V_6 ) ) {
V_18 = F_89 ( V_9 , V_229 ) ;
if ( V_18 ) {
F_90 ( L_4 ) ;
goto V_230;
}
V_3 -> V_27 = V_9 -> V_10 -> V_231 ;
} else {
V_18 = F_91 ( V_9 , V_229 , V_232 ) ;
if ( V_18 ) {
F_90 ( L_5 ) ;
goto V_230;
}
V_3 -> V_27 = F_4 ( V_9 ) ;
V_18 = F_92 ( V_9 , true ) ;
if ( V_18 ) {
F_90 ( L_6 ) ;
goto V_233;
}
}
V_3 -> V_81 = 0x0101fe ;
V_3 -> V_83 = true ;
V_3 -> V_206 = - 19 ;
V_3 -> V_205 = 75 ;
V_3 -> V_208 = 146 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
goto V_233;
F_93 ( V_8 , 0 , sizeof( struct V_1 ) ) ;
F_38 ( V_8 ) ;
F_78 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
V_5 -> V_3 = V_3 ;
F_68 ( & V_6 -> V_43 ) ;
F_94 ( L_7 ) ;
return;
V_233:
if ( ! F_2 ( V_6 ) )
F_22 ( V_9 ) ;
V_230:
F_23 ( & V_9 -> V_39 ) ;
V_197:
F_68 ( & V_6 -> V_43 ) ;
F_76 ( V_3 ) ;
return;
}
void F_95 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
if ( ! V_5 -> V_3 )
return;
F_9 ( V_5 -> V_3 -> V_22 ) ;
F_77 ( & V_5 -> V_3 -> V_9 -> V_39 ) ;
F_76 ( V_5 -> V_3 ) ;
}
static struct V_1 T_1 *
F_96 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_1 T_1 * V_8 ;
if ( F_2 ( V_3 -> V_6 ) )
V_8 = (struct V_1 T_1 * )
V_3 -> V_9 -> V_10 -> V_11 ;
else
V_8 = F_97 ( V_5 -> V_12 . V_13 ,
F_4 ( V_3 -> V_9 ) ) ;
return V_8 ;
}
static void F_98 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_99 ( V_8 ) ;
}
struct V_234 *
F_100 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_234 * error ;
struct V_1 T_1 * V_8 ;
if ( ! V_3 || ! V_3 -> V_22 )
return NULL ;
error = F_70 ( sizeof( * error ) , V_235 ) ;
if ( error == NULL )
return NULL ;
error -> V_236 = F_19 ( V_34 ) ;
error -> V_237 = F_19 ( V_44 ) ;
if ( F_2 ( V_3 -> V_6 ) )
error -> V_39 = ( V_238 long ) V_3 -> V_9 -> V_10 -> V_11 ;
else
error -> V_39 = F_4 ( V_3 -> V_9 ) ;
V_8 = F_96 ( V_3 ) ;
if ( ! V_8 )
goto V_239;
F_101 ( & error -> V_8 , V_8 , sizeof( struct V_1 ) ) ;
F_98 ( V_3 , V_8 ) ;
return error ;
V_239:
F_76 ( error ) ;
return NULL ;
}
void
F_102 ( struct V_240 * V_241 ,
struct V_234 * error )
{
F_103 ( V_241 , L_8 ,
error -> V_236 , error -> V_237 ) ;
F_103 ( V_241 , L_9 ,
error -> V_39 ) ;
#define F_104 ( T_3 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_104 ( V_138 ) ;
F_104 ( V_242 ) ;
F_104 ( V_144 ) ;
F_104 ( V_145 ) ;
F_104 ( V_243 ) ;
F_104 ( V_244 ) ;
F_104 ( V_150 ) ;
F_104 ( V_245 ) ;
F_104 ( V_246 ) ;
F_104 ( V_247 ) ;
F_104 ( V_248 ) ;
F_104 ( V_132 ) ;
F_104 ( V_133 ) ;
F_104 ( V_147 ) ;
F_104 ( V_148 ) ;
F_104 ( V_149 ) ;
F_104 ( V_77 ) ;
F_104 ( V_78 ) ;
F_104 ( V_207 ) ;
F_104 ( V_209 ) ;
F_104 ( V_93 ) ;
F_104 ( V_94 ) ;
F_104 ( V_249 ) ;
F_104 ( V_250 ) ;
F_104 ( V_251 ) ;
F_104 ( V_129 ) ;
F_104 ( V_151 ) ;
F_104 ( V_252 ) ;
F_104 ( V_253 ) ;
F_104 ( V_254 ) ;
F_104 ( V_255 ) ;
F_104 ( V_256 ) ;
F_104 ( V_257 ) ;
F_104 ( V_258 ) ;
F_104 ( V_259 ) ;
F_104 ( V_260 ) ;
F_104 ( V_261 ) ;
F_104 ( V_262 ) ;
F_104 ( V_263 ) ;
F_104 ( V_264 ) ;
F_104 ( V_79 ) ;
#undef F_104
}
