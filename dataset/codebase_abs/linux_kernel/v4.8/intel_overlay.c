static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_5 ) )
V_7 = (struct V_1 T_1 * ) V_3 -> V_8 -> V_9 -> V_10 ;
else
V_7 = F_3 ( V_5 -> V_11 . V_12 ,
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
static int F_6 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
void (* F_7)( struct V_2 * ) )
{
int V_17 ;
F_8 ( V_3 -> V_18 ) ;
F_9 ( & V_3 -> V_18 , V_16 ) ;
F_10 ( V_16 ) ;
V_3 -> V_19 = F_7 ;
V_17 = F_11 ( V_3 -> V_18 ) ;
if ( V_17 )
return V_17 ;
F_9 ( & V_3 -> V_18 , NULL ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_20 * V_21 = & V_5 -> V_21 [ V_22 ] ;
struct V_15 * V_16 ;
int V_17 ;
F_8 ( V_3 -> V_23 ) ;
F_8 ( F_13 ( V_5 ) && ! ( V_5 -> V_24 & V_25 ) ) ;
V_16 = F_14 ( V_21 , NULL ) ;
if ( F_15 ( V_16 ) )
return F_16 ( V_16 ) ;
V_17 = F_17 ( V_16 , 4 ) ;
if ( V_17 ) {
F_18 ( V_16 ) ;
return V_17 ;
}
V_3 -> V_23 = true ;
F_19 ( V_21 , V_26 | V_27 ) ;
F_19 ( V_21 , V_3 -> V_13 | V_28 ) ;
F_19 ( V_21 , V_29 | V_30 ) ;
F_19 ( V_21 , V_31 ) ;
F_20 ( V_21 ) ;
return F_6 ( V_3 , V_16 , NULL ) ;
}
static int F_21 ( struct V_2 * V_3 ,
bool V_32 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_20 * V_21 = & V_5 -> V_21 [ V_22 ] ;
struct V_15 * V_16 ;
T_2 V_13 = V_3 -> V_13 ;
T_2 V_33 ;
int V_17 ;
F_8 ( ! V_3 -> V_23 ) ;
if ( V_32 )
V_13 |= V_28 ;
V_33 = F_22 ( V_34 ) ;
if ( V_33 & ( 1 << 17 ) )
F_23 ( L_1 , V_33 ) ;
V_16 = F_14 ( V_21 , NULL ) ;
if ( F_15 ( V_16 ) )
return F_16 ( V_16 ) ;
V_17 = F_17 ( V_16 , 2 ) ;
if ( V_17 ) {
F_18 ( V_16 ) ;
return V_17 ;
}
F_19 ( V_21 , V_26 | V_35 ) ;
F_19 ( V_21 , V_13 ) ;
F_20 ( V_21 ) ;
F_8 ( V_3 -> V_18 ) ;
F_9 ( & V_3 -> V_18 , V_16 ) ;
F_10 ( V_16 ) ;
return 0 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_38 ;
F_25 ( V_37 ) ;
F_26 ( & V_37 -> V_39 ) ;
V_3 -> V_38 = NULL ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_40 ;
if ( F_8 ( ! V_37 ) )
return;
F_25 ( V_37 ) ;
F_26 ( & V_37 -> V_39 ) ;
V_3 -> V_40 = NULL ;
V_3 -> V_41 -> V_3 = NULL ;
V_3 -> V_41 = NULL ;
V_3 -> V_23 = false ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_20 * V_21 = & V_5 -> V_21 [ V_22 ] ;
struct V_15 * V_16 ;
T_2 V_13 = V_3 -> V_13 ;
int V_17 ;
F_8 ( ! V_3 -> V_23 ) ;
V_13 |= V_28 ;
V_16 = F_14 ( V_21 , NULL ) ;
if ( F_15 ( V_16 ) )
return F_16 ( V_16 ) ;
V_17 = F_17 ( V_16 , 6 ) ;
if ( V_17 ) {
F_18 ( V_16 ) ;
return V_17 ;
}
F_19 ( V_21 , V_26 | V_35 ) ;
F_19 ( V_21 , V_13 ) ;
F_19 ( V_21 , V_29 | V_30 ) ;
if ( F_13 ( V_5 ) ) {
F_19 ( V_21 , V_31 ) ;
F_19 ( V_21 , V_31 ) ;
F_19 ( V_21 , V_31 ) ;
} else {
F_19 ( V_21 , V_26 | V_42 ) ;
F_19 ( V_21 , V_13 ) ;
F_19 ( V_21 ,
V_29 | V_30 ) ;
}
F_20 ( V_21 ) ;
return F_6 ( V_3 , V_16 , F_27 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_17 ;
if ( V_3 -> V_18 == NULL )
return 0 ;
V_17 = F_11 ( V_3 -> V_18 ) ;
if ( V_17 )
return V_17 ;
if ( V_3 -> V_19 )
V_3 -> V_19 ( V_3 ) ;
F_9 ( & V_3 -> V_18 , NULL ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_20 * V_21 = & V_5 -> V_21 [ V_22 ] ;
int V_17 ;
F_31 ( & V_5 -> V_43 . V_44 ) ;
if ( ! V_3 -> V_38 )
return 0 ;
if ( F_22 ( V_45 ) & V_46 ) {
struct V_15 * V_16 ;
V_16 = F_14 ( V_21 , NULL ) ;
if ( F_15 ( V_16 ) )
return F_16 ( V_16 ) ;
V_17 = F_17 ( V_16 , 2 ) ;
if ( V_17 ) {
F_18 ( V_16 ) ;
return V_17 ;
}
F_19 ( V_21 ,
V_29 | V_30 ) ;
F_19 ( V_21 , V_31 ) ;
F_20 ( V_21 ) ;
V_17 = F_6 ( V_3 , V_16 ,
F_24 ) ;
if ( V_17 )
return V_17 ;
}
F_24 ( V_3 ) ;
F_32 ( V_3 -> V_38 , NULL ,
F_33 ( V_3 -> V_41 -> V_47 ) ) ;
return 0 ;
}
void F_34 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
F_30 ( V_3 ) ;
V_3 -> V_18 = NULL ;
V_3 -> V_48 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_41 = NULL ;
V_3 -> V_23 = false ;
}
static int F_35 ( T_2 V_50 )
{
switch ( V_50 & V_51 ) {
case V_52 :
return 4 ;
case V_53 :
default:
return - V_54 ;
}
}
static int F_36 ( T_2 V_50 , short V_55 )
{
switch ( V_50 & V_51 ) {
case V_52 :
return V_55 << 1 ;
default:
return - V_54 ;
}
}
static int F_37 ( T_2 V_50 )
{
switch ( V_50 & V_51 ) {
case V_52 :
case V_56 :
return 2 ;
case V_53 :
case V_57 :
return 4 ;
default:
return - V_54 ;
}
}
static int F_38 ( T_2 V_50 )
{
switch ( V_50 & V_51 ) {
case V_56 :
case V_57 :
return 2 ;
case V_52 :
case V_53 :
return 1 ;
default:
return - V_54 ;
}
}
static T_2 F_39 ( struct V_4 * V_5 , T_2 V_58 , T_2 V_55 )
{
T_2 V_59 , V_60 , V_17 ;
if ( F_40 ( V_5 ) ) {
V_59 = 0x1f ;
V_60 = 5 ;
} else {
V_59 = 0x3f ;
V_60 = 6 ;
}
V_17 = ( ( V_58 + V_55 + V_59 ) >> V_60 ) - ( V_58 >> V_60 ) ;
if ( ! F_40 ( V_5 ) )
V_17 <<= 1 ;
V_17 -= 1 ;
return V_17 << 2 ;
}
static void F_41 ( struct V_1 T_1 * V_7 )
{
F_42 ( V_7 -> V_61 , V_62 , sizeof( V_62 ) ) ;
F_42 ( V_7 -> V_63 , V_64 ,
sizeof( V_64 ) ) ;
}
static bool F_43 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 ,
struct V_65 * V_66 )
{
T_2 V_67 , V_68 , V_69 , V_70 ;
#define F_44 12
#define F_45 0xfff
bool V_71 = false ;
int V_72 = F_37 ( V_66 -> V_50 ) ;
int V_73 = F_38 ( V_66 -> V_50 ) ;
if ( V_66 -> V_74 > 1 )
V_67 = ( ( V_66 -> V_75 - 1 ) << F_44 )
/ ( V_66 -> V_74 ) ;
else
V_67 = 1 << F_44 ;
if ( V_66 -> V_76 > 1 )
V_68 = ( ( V_66 -> V_77 - 1 ) << F_44 )
/ ( V_66 -> V_76 ) ;
else
V_68 = 1 << F_44 ;
V_69 = V_67 / V_72 ;
V_70 = V_68 / V_73 ;
V_67 = V_69 * V_72 ;
V_68 = V_70 * V_73 ;
if ( V_67 != V_3 -> V_48 || V_68 != V_3 -> V_49 )
V_71 = true ;
V_3 -> V_48 = V_67 ;
V_3 -> V_49 = V_68 ;
F_46 ( ( ( V_68 & F_45 ) << 20 ) |
( ( V_67 >> F_44 ) << 16 ) |
( ( V_67 & F_45 ) << 3 ) ,
& V_7 -> V_78 ) ;
F_46 ( ( ( V_70 & F_45 ) << 20 ) |
( ( V_69 >> F_44 ) << 16 ) |
( ( V_69 & F_45 ) << 3 ) ,
& V_7 -> V_79 ) ;
F_46 ( ( ( ( V_68 >> F_44 ) << 16 ) |
( ( V_70 >> F_44 ) << 0 ) ) ,
& V_7 -> V_80 ) ;
if ( V_71 )
F_41 ( V_7 ) ;
return V_71 ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
T_2 V_81 = V_3 -> V_82 ;
T_2 V_83 ;
V_83 = 0 ;
if ( V_3 -> V_84 )
V_83 |= V_85 ;
switch ( V_3 -> V_41 -> V_39 . V_86 -> V_87 -> V_88 ) {
case 8 :
V_81 = 0 ;
V_83 |= V_89 ;
break;
case 16 :
if ( V_3 -> V_41 -> V_39 . V_86 -> V_87 -> V_90 == 15 ) {
V_81 = F_48 ( V_81 ) ;
V_83 |= V_91 ;
} else {
V_81 = F_49 ( V_81 ) ;
V_83 |= V_92 ;
}
break;
case 24 :
case 32 :
V_83 |= V_93 ;
break;
}
F_46 ( V_81 , & V_7 -> V_94 ) ;
F_46 ( V_83 , & V_7 -> V_95 ) ;
}
static T_2 F_50 ( struct V_65 * V_66 )
{
T_2 V_96 = V_97 | V_98 | V_99 ;
if ( V_66 -> V_50 & V_100 ) {
switch ( V_66 -> V_50 & V_51 ) {
case V_52 :
V_96 |= V_101 ;
break;
case V_56 :
V_96 |= V_102 ;
break;
case V_53 :
case V_57 :
V_96 |= V_103 ;
break;
}
} else {
switch ( V_66 -> V_50 & V_51 ) {
case V_52 :
V_96 |= V_104 ;
break;
case V_53 :
V_96 |= V_105 ;
break;
}
switch ( V_66 -> V_50 & V_106 ) {
case V_107 :
break;
case V_108 :
V_96 |= V_109 ;
break;
case V_110 :
V_96 |= V_111 ;
break;
case V_112 :
V_96 |= V_113 ;
break;
}
}
return V_96 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_36 * V_114 ,
struct V_65 * V_66 )
{
int V_17 , V_115 ;
struct V_1 T_1 * V_7 ;
bool V_71 = false ;
struct V_4 * V_5 = V_3 -> V_6 ;
T_2 V_116 , V_117 , V_118 , V_119 ;
enum V_47 V_47 = V_3 -> V_41 -> V_47 ;
F_31 ( & V_5 -> V_43 . V_44 ) ;
F_8 ( ! F_52 ( & V_5 -> V_43 . V_120 . V_121 ) ) ;
V_17 = F_30 ( V_3 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_53 ( V_114 , 0 ,
& V_122 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_54 ( V_114 ) ;
if ( V_17 )
goto V_123;
if ( ! V_3 -> V_23 ) {
T_2 V_124 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_17 = - V_125 ;
goto V_123;
}
V_124 = V_126 ;
if ( F_55 ( V_5 ) )
V_124 |= V_127 ;
V_124 |= V_47 == 0 ?
V_128 : V_129 ;
F_46 ( V_124 , & V_7 -> V_130 ) ;
F_4 ( V_3 , V_7 ) ;
V_17 = F_12 ( V_3 ) ;
if ( V_17 != 0 )
goto V_123;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_17 = - V_125 ;
goto V_123;
}
F_46 ( ( V_66 -> V_131 << 16 ) | V_66 -> V_132 , & V_7 -> V_133 ) ;
F_46 ( ( V_66 -> V_76 << 16 ) | V_66 -> V_74 , & V_7 -> V_134 ) ;
if ( V_66 -> V_50 & V_135 )
V_115 = F_36 ( V_66 -> V_50 , V_66 -> V_136 ) ;
else
V_115 = V_66 -> V_136 ;
V_116 = V_66 -> V_136 ;
V_117 = F_39 ( V_5 , V_66 -> V_137 , V_115 ) ;
V_118 = V_66 -> V_138 ;
F_46 ( F_56 ( V_114 ) + V_66 -> V_137 , & V_7 -> V_139 ) ;
V_119 = V_66 -> V_140 ;
if ( V_66 -> V_50 & V_100 ) {
int V_72 = F_37 ( V_66 -> V_50 ) ;
int V_73 = F_38 ( V_66 -> V_50 ) ;
T_2 V_141 , V_142 ;
V_116 |= ( V_66 -> V_136 / V_72 ) << 16 ;
V_141 = F_39 ( V_5 , V_66 -> V_143 ,
V_66 -> V_136 / V_72 ) ;
V_142 = F_39 ( V_5 , V_66 -> V_144 ,
V_66 -> V_136 / V_72 ) ;
V_117 |= F_57 ( T_2 , V_141 , V_142 ) << 16 ;
V_118 |= ( V_66 -> V_138 / V_73 ) << 16 ;
F_46 ( F_56 ( V_114 ) + V_66 -> V_143 , & V_7 -> V_145 ) ;
F_46 ( F_56 ( V_114 ) + V_66 -> V_144 , & V_7 -> V_146 ) ;
V_119 |= V_66 -> V_147 << 16 ;
}
F_46 ( V_116 , & V_7 -> V_148 ) ;
F_46 ( V_117 , & V_7 -> V_149 ) ;
F_46 ( V_118 , & V_7 -> V_150 ) ;
F_46 ( V_119 , & V_7 -> V_151 ) ;
V_71 = F_43 ( V_3 , V_7 , V_66 ) ;
F_47 ( V_3 , V_7 ) ;
F_46 ( F_50 ( V_66 ) , & V_7 -> V_152 ) ;
F_4 ( V_3 , V_7 ) ;
V_17 = F_21 ( V_3 , V_71 ) ;
if ( V_17 )
goto V_123;
F_32 ( V_3 -> V_40 , V_114 ,
F_33 ( V_47 ) ) ;
V_3 -> V_38 = V_3 -> V_40 ;
V_3 -> V_40 = V_114 ;
F_58 ( & V_5 -> V_43 ,
F_33 ( V_47 ) ) ;
return 0 ;
V_123:
F_25 ( V_114 ) ;
return V_17 ;
}
int F_59 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 T_1 * V_7 ;
int V_17 ;
F_31 ( & V_5 -> V_43 . V_44 ) ;
F_8 ( ! F_52 ( & V_5 -> V_43 . V_120 . V_121 ) ) ;
V_17 = F_29 ( V_3 ) ;
if ( V_17 != 0 )
return V_17 ;
if ( ! V_3 -> V_23 )
return 0 ;
V_17 = F_30 ( V_3 ) ;
if ( V_17 != 0 )
return V_17 ;
V_7 = F_1 ( V_3 ) ;
F_46 ( 0 , & V_7 -> V_152 ) ;
F_4 ( V_3 , V_7 ) ;
V_17 = F_28 ( V_3 ) ;
if ( V_17 != 0 )
return V_17 ;
F_27 ( V_3 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_153 * V_41 )
{
if ( ! V_41 -> V_23 )
return - V_54 ;
if ( V_41 -> V_154 -> V_155 )
return - V_54 ;
return 0 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
T_2 V_156 = F_22 ( V_157 ) ;
T_2 V_158 ;
if ( F_62 ( V_5 ) >= 4 ) {
V_158 = F_22 ( V_159 ) >> V_160 ;
} else {
if ( V_156 & V_161 )
V_158 = F_22 ( V_162 ) ;
else
V_158 = F_22 ( V_159 ) ;
V_158 >>= V_163 ;
}
V_3 -> V_164 = V_158 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_165 * V_166 )
{
struct V_167 * V_168 = & V_3 -> V_41 -> V_39 . V_168 ;
if ( V_166 -> V_132 < V_168 -> V_169 &&
V_166 -> V_132 + V_166 -> V_170 <= V_168 -> V_169 &&
V_166 -> V_131 < V_168 -> V_171 &&
V_166 -> V_131 + V_166 -> V_172 <= V_168 -> V_171 )
return 0 ;
else
return - V_54 ;
}
static int F_64 ( struct V_65 * V_166 )
{
T_2 V_33 ;
V_33 = ( ( V_166 -> V_77 << 16 ) / V_166 -> V_76 ) >> 16 ;
if ( V_33 > 7 )
return - V_54 ;
V_33 = ( ( V_166 -> V_75 << 16 ) / V_166 -> V_74 ) >> 16 ;
if ( V_33 > 7 )
return - V_54 ;
return 0 ;
}
static int F_65 ( struct V_4 * V_5 ,
struct V_165 * V_166 ,
struct V_36 * V_114 )
{
int V_72 = F_37 ( V_166 -> V_83 ) ;
int V_73 = F_38 ( V_166 -> V_83 ) ;
T_2 V_173 ;
int V_90 ;
T_2 V_33 ;
if ( F_66 ( V_5 ) || F_13 ( V_5 ) ) {
if ( V_166 -> V_174 > V_175 ||
V_166 -> V_176 > V_177 )
return - V_54 ;
} else {
if ( V_166 -> V_174 > V_178 ||
V_166 -> V_176 > V_179 )
return - V_54 ;
}
if ( V_166 -> V_174 < V_180 * 4 ||
V_166 -> V_176 < V_181 * 4 )
return - V_54 ;
switch ( V_166 -> V_83 & V_182 ) {
case V_183 :
return - V_54 ;
case V_135 :
if ( V_73 != 1 )
return - V_54 ;
V_90 = F_35 ( V_166 -> V_83 ) ;
if ( V_90 < 0 )
return V_90 ;
V_166 -> V_147 = 0 ;
V_166 -> V_143 = 0 ;
V_166 -> V_144 = 0 ;
if ( V_166 -> V_137 % V_90 )
return - V_54 ;
break;
case V_100 :
if ( V_73 < 0 || V_72 < 0 )
return - V_54 ;
break;
default:
return - V_54 ;
}
if ( V_166 -> V_176 % V_72 )
return - V_54 ;
if ( F_13 ( V_5 ) || F_66 ( V_5 ) )
V_173 = 255 ;
else
V_173 = 63 ;
if ( V_166 -> V_140 & V_173 || V_166 -> V_147 & V_173 )
return - V_54 ;
if ( F_55 ( V_5 ) && V_166 -> V_140 < 512 )
return - V_54 ;
V_33 = ( V_166 -> V_83 & V_182 ) == V_100 ?
4096 : 8192 ;
if ( V_166 -> V_140 > V_33 || V_166 -> V_147 > 2 * 1024 )
return - V_54 ;
switch ( V_166 -> V_83 & V_182 ) {
case V_183 :
case V_135 :
if ( F_36 ( V_166 -> V_83 , V_166 -> V_176 ) > V_166 -> V_140 )
return - V_54 ;
V_33 = V_166 -> V_140 * V_166 -> V_174 ;
if ( V_166 -> V_137 + V_33 > V_114 -> V_39 . V_184 )
return - V_54 ;
break;
case V_100 :
if ( V_166 -> V_176 > V_166 -> V_140 )
return - V_54 ;
if ( V_166 -> V_176 / V_72 > V_166 -> V_147 )
return - V_54 ;
V_33 = V_166 -> V_140 * V_166 -> V_174 ;
if ( V_166 -> V_137 + V_33 > V_114 -> V_39 . V_184 )
return - V_54 ;
V_33 = V_166 -> V_147 * ( V_166 -> V_174 / V_73 ) ;
if ( V_166 -> V_143 + V_33 > V_114 -> V_39 . V_184 ||
V_166 -> V_144 + V_33 > V_114 -> V_39 . V_184 )
return - V_54 ;
break;
}
return 0 ;
}
static int F_67 ( struct V_4 * V_5 )
{
T_2 V_156 ;
if ( F_62 ( V_5 ) <= 3 &&
( F_13 ( V_5 ) || ! F_68 ( V_5 ) ) )
return - 1 ;
V_156 = F_22 ( V_157 ) ;
if ( ( V_156 & V_185 ) == 0 )
return - 1 ;
if ( F_55 ( V_5 ) )
return ( V_156 >> 29 ) & 0x3 ;
return 1 ;
}
int F_69 ( struct V_186 * V_187 , void * V_188 ,
struct V_189 * V_190 )
{
struct V_165 * V_191 = V_188 ;
struct V_4 * V_5 = F_70 ( V_187 ) ;
struct V_2 * V_3 ;
struct V_192 * V_193 ;
struct V_153 * V_41 ;
struct V_36 * V_114 ;
struct V_65 * V_66 ;
int V_17 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_23 ( L_2 ) ;
return - V_194 ;
}
if ( ! ( V_191 -> V_83 & V_195 ) ) {
F_71 ( V_187 ) ;
F_72 ( & V_187 -> V_44 ) ;
V_17 = F_59 ( V_3 ) ;
F_73 ( & V_187 -> V_44 ) ;
F_74 ( V_187 ) ;
return V_17 ;
}
V_66 = F_75 ( sizeof( * V_66 ) , V_196 ) ;
if ( ! V_66 )
return - V_125 ;
V_193 = F_76 ( V_187 , V_191 -> V_197 ) ;
if ( ! V_193 ) {
V_17 = - V_198 ;
goto V_199;
}
V_41 = F_77 ( V_193 ) ;
V_114 = F_78 ( F_79 ( V_190 ,
V_191 -> V_200 ) ) ;
if ( & V_114 -> V_39 == NULL ) {
V_17 = - V_198 ;
goto V_199;
}
F_71 ( V_187 ) ;
F_72 ( & V_187 -> V_44 ) ;
if ( V_114 -> V_201 ) {
F_80 ( L_3 ) ;
V_17 = - V_54 ;
goto V_202;
}
V_17 = F_29 ( V_3 ) ;
if ( V_17 != 0 )
goto V_202;
if ( V_3 -> V_41 != V_41 ) {
struct V_167 * V_168 = & V_41 -> V_39 . V_168 ;
V_17 = F_59 ( V_3 ) ;
if ( V_17 != 0 )
goto V_202;
V_17 = F_60 ( V_3 , V_41 ) ;
if ( V_17 != 0 )
goto V_202;
V_3 -> V_41 = V_41 ;
V_41 -> V_3 = V_3 ;
if ( V_168 -> V_169 > 1024 &&
F_67 ( V_5 ) == V_41 -> V_47 ) {
V_3 -> V_203 = true ;
F_61 ( V_3 ) ;
} else
V_3 -> V_203 = false ;
}
V_17 = F_63 ( V_3 , V_191 ) ;
if ( V_17 != 0 )
goto V_202;
if ( V_3 -> V_203 ) {
V_66 -> V_131 = ( ( ( ( T_2 ) V_191 -> V_131 ) << 12 ) /
V_3 -> V_164 ) ;
V_66 -> V_76 = ( ( ( ( T_2 ) V_191 -> V_172 ) << 12 ) /
V_3 -> V_164 ) + 1 ;
} else {
V_66 -> V_131 = V_191 -> V_131 ;
V_66 -> V_76 = V_191 -> V_172 ;
}
V_66 -> V_132 = V_191 -> V_132 ;
V_66 -> V_74 = V_191 -> V_170 ;
V_66 -> V_136 = V_191 -> V_176 ;
V_66 -> V_138 = V_191 -> V_174 ;
V_66 -> V_75 = V_191 -> V_204 ;
V_66 -> V_77 = V_191 -> V_205 ;
if ( V_66 -> V_77 > V_66 -> V_138 ||
V_66 -> V_75 > V_66 -> V_136 ) {
V_17 = - V_54 ;
goto V_202;
}
V_17 = F_65 ( V_5 , V_191 , V_114 ) ;
if ( V_17 != 0 )
goto V_202;
V_66 -> V_50 = V_191 -> V_83 & ~ V_206 ;
V_66 -> V_140 = V_191 -> V_140 ;
V_66 -> V_147 = V_191 -> V_147 ;
V_66 -> V_137 = V_191 -> V_137 ;
V_66 -> V_143 = V_191 -> V_143 ;
V_66 -> V_144 = V_191 -> V_144 ;
V_17 = F_64 ( V_66 ) ;
if ( V_17 != 0 )
goto V_202;
V_17 = F_51 ( V_3 , V_114 , V_66 ) ;
if ( V_17 != 0 )
goto V_202;
F_73 ( & V_187 -> V_44 ) ;
F_74 ( V_187 ) ;
F_81 ( V_66 ) ;
return 0 ;
V_202:
F_73 ( & V_187 -> V_44 ) ;
F_74 ( V_187 ) ;
F_82 ( & V_114 -> V_39 ) ;
V_199:
F_81 ( V_66 ) ;
return V_17 ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
F_46 ( ( V_3 -> V_207 << 18 ) | ( V_3 -> V_208 & 0xff ) ,
& V_7 -> V_209 ) ;
F_46 ( V_3 -> V_210 , & V_7 -> V_211 ) ;
}
static bool F_84 ( T_2 V_212 , T_2 V_213 )
{
int V_214 ;
if ( V_212 & 0xff000000 || V_213 & 0xff000000 )
return false ;
for ( V_214 = 0 ; V_214 < 3 ; V_214 ++ ) {
if ( ( ( V_212 >> V_214 * 8 ) & 0xff ) >= ( ( V_213 >> V_214 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_85 ( T_2 V_215 )
{
int V_214 ;
for ( V_214 = 0 ; V_214 < 3 ; V_214 ++ ) {
if ( ( ( V_215 >> V_214 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_86 ( struct V_216 * V_217 )
{
if ( ! F_84 ( 0 , V_217 -> V_218 ) ||
! F_84 ( V_217 -> V_218 , V_217 -> V_212 ) ||
! F_84 ( V_217 -> V_212 , V_217 -> V_213 ) ||
! F_84 ( V_217 -> V_213 , V_217 -> V_219 ) ||
! F_84 ( V_217 -> V_219 , V_217 -> V_220 ) ||
! F_84 ( V_217 -> V_220 , V_217 -> V_215 ) ||
! F_84 ( V_217 -> V_215 , 0x00ffffff ) )
return - V_54 ;
if ( ! F_85 ( V_217 -> V_215 ) )
return - V_54 ;
return 0 ;
}
int F_87 ( struct V_186 * V_187 , void * V_188 ,
struct V_189 * V_190 )
{
struct V_216 * V_217 = V_188 ;
struct V_4 * V_5 = F_70 ( V_187 ) ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_7 ;
int V_17 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_23 ( L_2 ) ;
return - V_194 ;
}
F_71 ( V_187 ) ;
F_72 ( & V_187 -> V_44 ) ;
V_17 = - V_54 ;
if ( ! ( V_217 -> V_83 & V_221 ) ) {
V_217 -> V_82 = V_3 -> V_82 ;
V_217 -> V_208 = V_3 -> V_208 ;
V_217 -> V_207 = V_3 -> V_207 ;
V_217 -> V_210 = V_3 -> V_210 ;
if ( ! F_40 ( V_5 ) ) {
V_217 -> V_218 = F_22 ( V_222 ) ;
V_217 -> V_212 = F_22 ( V_223 ) ;
V_217 -> V_213 = F_22 ( V_224 ) ;
V_217 -> V_219 = F_22 ( V_225 ) ;
V_217 -> V_220 = F_22 ( V_226 ) ;
V_217 -> V_215 = F_22 ( V_227 ) ;
}
} else {
if ( V_217 -> V_208 < - 128 || V_217 -> V_208 > 127 )
goto V_202;
if ( V_217 -> V_207 > 255 )
goto V_202;
if ( V_217 -> V_210 > 1023 )
goto V_202;
V_3 -> V_82 = V_217 -> V_82 ;
V_3 -> V_208 = V_217 -> V_208 ;
V_3 -> V_207 = V_217 -> V_207 ;
V_3 -> V_210 = V_217 -> V_210 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_17 = - V_125 ;
goto V_202;
}
F_83 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( V_217 -> V_83 & V_228 ) {
if ( F_40 ( V_5 ) )
goto V_202;
if ( V_3 -> V_23 ) {
V_17 = - V_229 ;
goto V_202;
}
V_17 = F_86 ( V_217 ) ;
if ( V_17 )
goto V_202;
F_88 ( V_222 , V_217 -> V_218 ) ;
F_88 ( V_223 , V_217 -> V_212 ) ;
F_88 ( V_224 , V_217 -> V_213 ) ;
F_88 ( V_225 , V_217 -> V_219 ) ;
F_88 ( V_226 , V_217 -> V_220 ) ;
F_88 ( V_227 , V_217 -> V_215 ) ;
}
}
V_3 -> V_84 = ( V_217 -> V_83 & V_230 ) == 0 ;
V_17 = 0 ;
V_202:
F_73 ( & V_187 -> V_44 ) ;
F_74 ( V_187 ) ;
return V_17 ;
}
void F_89 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_36 * V_8 ;
struct V_1 T_1 * V_7 ;
int V_17 ;
if ( ! F_90 ( V_5 ) )
return;
V_3 = F_91 ( sizeof( * V_3 ) , V_196 ) ;
if ( ! V_3 )
return;
F_72 ( & V_5 -> V_43 . V_44 ) ;
if ( F_8 ( V_5 -> V_3 ) )
goto V_199;
V_3 -> V_6 = V_5 ;
V_8 = NULL ;
if ( ! F_2 ( V_5 ) )
V_8 = F_92 ( & V_5 -> V_43 ,
V_14 ) ;
if ( V_8 == NULL )
V_8 = F_93 ( & V_5 -> V_43 , V_14 ) ;
if ( F_15 ( V_8 ) )
goto V_199;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_17 = F_94 ( V_8 , V_14 ) ;
if ( V_17 ) {
F_95 ( L_4 ) ;
goto V_231;
}
V_3 -> V_13 = V_8 -> V_9 -> V_232 ;
} else {
V_17 = F_96 ( V_8 , V_14 , V_233 ) ;
if ( V_17 ) {
F_95 ( L_5 ) ;
goto V_231;
}
V_3 -> V_13 = F_56 ( V_8 ) ;
V_17 = F_97 ( V_8 , true ) ;
if ( V_17 ) {
F_95 ( L_6 ) ;
goto V_234;
}
}
V_3 -> V_82 = 0x0101fe ;
V_3 -> V_84 = true ;
V_3 -> V_208 = - 19 ;
V_3 -> V_207 = 75 ;
V_3 -> V_210 = 146 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_234;
F_98 ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_41 ( V_7 ) ;
F_83 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
V_5 -> V_3 = V_3 ;
F_73 ( & V_5 -> V_43 . V_44 ) ;
F_99 ( L_7 ) ;
return;
V_234:
if ( ! F_2 ( V_5 ) )
F_25 ( V_8 ) ;
V_231:
F_26 ( & V_8 -> V_39 ) ;
V_199:
F_73 ( & V_5 -> V_43 . V_44 ) ;
F_81 ( V_3 ) ;
return;
}
void F_100 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_3 )
return;
F_8 ( V_5 -> V_3 -> V_23 ) ;
F_82 ( & V_5 -> V_3 -> V_8 -> V_39 ) ;
F_81 ( V_5 -> V_3 ) ;
}
static struct V_1 T_1 *
F_101 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_5 ) )
V_7 = (struct V_1 T_1 * )
V_3 -> V_8 -> V_9 -> V_10 ;
else
V_7 = F_102 ( V_5 -> V_11 . V_12 ,
V_3 -> V_13 ) ;
return V_7 ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_104 ( V_7 ) ;
}
struct V_235 *
F_105 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_235 * error ;
struct V_1 T_1 * V_7 ;
if ( ! V_3 || ! V_3 -> V_23 )
return NULL ;
error = F_75 ( sizeof( * error ) , V_236 ) ;
if ( error == NULL )
return NULL ;
error -> V_237 = F_22 ( V_34 ) ;
error -> V_238 = F_22 ( V_45 ) ;
error -> V_39 = V_3 -> V_13 ;
V_7 = F_101 ( V_3 ) ;
if ( ! V_7 )
goto V_239;
F_106 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_103 ( V_3 , V_7 ) ;
return error ;
V_239:
F_81 ( error ) ;
return NULL ;
}
void
F_107 ( struct V_240 * V_241 ,
struct V_235 * error )
{
F_108 ( V_241 , L_8 ,
error -> V_237 , error -> V_238 ) ;
F_108 ( V_241 , L_9 ,
error -> V_39 ) ;
#define F_109 ( T_3 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_109 ( V_139 ) ;
F_109 ( V_242 ) ;
F_109 ( V_145 ) ;
F_109 ( V_146 ) ;
F_109 ( V_243 ) ;
F_109 ( V_244 ) ;
F_109 ( V_151 ) ;
F_109 ( V_245 ) ;
F_109 ( V_246 ) ;
F_109 ( V_247 ) ;
F_109 ( V_248 ) ;
F_109 ( V_133 ) ;
F_109 ( V_134 ) ;
F_109 ( V_148 ) ;
F_109 ( V_149 ) ;
F_109 ( V_150 ) ;
F_109 ( V_78 ) ;
F_109 ( V_79 ) ;
F_109 ( V_209 ) ;
F_109 ( V_211 ) ;
F_109 ( V_94 ) ;
F_109 ( V_95 ) ;
F_109 ( V_249 ) ;
F_109 ( V_250 ) ;
F_109 ( V_251 ) ;
F_109 ( V_130 ) ;
F_109 ( V_152 ) ;
F_109 ( V_252 ) ;
F_109 ( V_253 ) ;
F_109 ( V_254 ) ;
F_109 ( V_255 ) ;
F_109 ( V_256 ) ;
F_109 ( V_257 ) ;
F_109 ( V_258 ) ;
F_109 ( V_259 ) ;
F_109 ( V_260 ) ;
F_109 ( V_261 ) ;
F_109 ( V_262 ) ;
F_109 ( V_263 ) ;
F_109 ( V_264 ) ;
F_109 ( V_80 ) ;
#undef F_109
}
