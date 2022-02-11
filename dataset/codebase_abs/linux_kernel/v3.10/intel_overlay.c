static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
T_2 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = (struct V_1 T_1 * ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_3 ( V_4 -> V_12 . V_13 ,
V_3 -> V_8 -> V_14 ) ;
return V_7 ;
}
static void F_4 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_5 ( V_7 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
void (* F_7)( struct V_2 * ) )
{
struct V_15 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_16 * V_17 = & V_4 -> V_17 [ V_18 ] ;
int V_19 ;
F_8 ( V_3 -> V_20 ) ;
V_19 = F_9 ( V_17 , NULL , & V_3 -> V_20 ) ;
if ( V_19 )
return V_19 ;
V_3 -> V_21 = F_7 ;
V_19 = F_10 ( V_17 , V_3 -> V_20 ) ;
if ( V_19 )
return V_19 ;
F_11 ( V_5 ) ;
V_3 -> V_20 = 0 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_15 * V_5 = V_3 -> V_5 ;
struct V_22 * V_4 = V_5 -> V_6 ;
struct V_16 * V_17 = & V_4 -> V_17 [ V_18 ] ;
int V_19 ;
F_8 ( V_3 -> V_23 ) ;
V_3 -> V_23 = 1 ;
F_13 ( F_14 ( V_5 ) && ! ( V_4 -> V_24 & V_25 ) ) ;
V_19 = F_15 ( V_17 , 4 ) ;
if ( V_19 )
return V_19 ;
F_16 ( V_17 , V_26 | V_27 ) ;
F_16 ( V_17 , V_3 -> V_28 | V_29 ) ;
F_16 ( V_17 , V_30 | V_31 ) ;
F_16 ( V_17 , V_32 ) ;
F_17 ( V_17 ) ;
return F_6 ( V_3 , NULL ) ;
}
static int F_18 ( struct V_2 * V_3 ,
bool V_33 )
{
struct V_15 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_16 * V_17 = & V_4 -> V_17 [ V_18 ] ;
T_3 V_28 = V_3 -> V_28 ;
T_3 V_34 ;
int V_19 ;
F_8 ( ! V_3 -> V_23 ) ;
if ( V_33 )
V_28 |= V_29 ;
V_34 = F_19 ( V_35 ) ;
if ( V_34 & ( 1 << 17 ) )
F_20 ( L_1 , V_34 ) ;
V_19 = F_15 ( V_17 , 2 ) ;
if ( V_19 )
return V_19 ;
F_16 ( V_17 , V_26 | V_36 ) ;
F_16 ( V_17 , V_28 ) ;
F_17 ( V_17 ) ;
return F_9 ( V_17 , NULL , & V_3 -> V_20 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_37 * V_38 = V_3 -> V_39 ;
F_22 ( V_38 ) ;
F_23 ( & V_38 -> V_40 ) ;
V_3 -> V_39 = NULL ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_37 * V_38 = V_3 -> V_41 ;
F_8 ( ! V_3 -> V_41 ) ;
F_22 ( V_38 ) ;
F_23 ( & V_38 -> V_40 ) ;
V_3 -> V_41 = NULL ;
V_3 -> V_42 -> V_3 = NULL ;
V_3 -> V_42 = NULL ;
V_3 -> V_23 = 0 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_15 * V_5 = V_3 -> V_5 ;
struct V_22 * V_4 = V_5 -> V_6 ;
struct V_16 * V_17 = & V_4 -> V_17 [ V_18 ] ;
T_3 V_28 = V_3 -> V_28 ;
int V_19 ;
F_8 ( ! V_3 -> V_23 ) ;
V_28 |= V_29 ;
V_19 = F_15 ( V_17 , 6 ) ;
if ( V_19 )
return V_19 ;
F_16 ( V_17 , V_26 | V_36 ) ;
F_16 ( V_17 , V_28 ) ;
F_16 ( V_17 , V_30 | V_31 ) ;
if ( F_14 ( V_5 ) ) {
F_16 ( V_17 , V_32 ) ;
F_16 ( V_17 , V_32 ) ;
F_16 ( V_17 , V_32 ) ;
} else {
F_16 ( V_17 , V_26 | V_43 ) ;
F_16 ( V_17 , V_28 ) ;
F_16 ( V_17 , V_30 | V_31 ) ;
}
F_17 ( V_17 ) ;
return F_6 ( V_3 , F_24 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_15 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_16 * V_17 = & V_4 -> V_17 [ V_18 ] ;
int V_19 ;
if ( V_3 -> V_20 == 0 )
return 0 ;
V_19 = F_10 ( V_17 , V_3 -> V_20 ) ;
if ( V_19 )
return V_19 ;
F_11 ( V_5 ) ;
if ( V_3 -> V_21 )
V_3 -> V_21 ( V_3 ) ;
V_3 -> V_20 = 0 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_15 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_16 * V_17 = & V_4 -> V_17 [ V_18 ] ;
int V_19 ;
if ( ! V_3 -> V_39 )
return 0 ;
if ( F_19 ( V_44 ) & V_45 ) {
V_19 = F_15 ( V_17 , 2 ) ;
if ( V_19 )
return V_19 ;
F_16 ( V_17 , V_30 | V_31 ) ;
F_16 ( V_17 , V_32 ) ;
F_17 ( V_17 ) ;
V_19 = F_6 ( V_3 ,
F_21 ) ;
if ( V_19 )
return V_19 ;
}
F_21 ( V_3 ) ;
return 0 ;
}
static int F_28 ( T_3 V_46 )
{
switch ( V_46 & V_47 ) {
case V_48 :
return 4 ;
case V_49 :
default:
return - V_50 ;
}
}
static int F_29 ( T_3 V_46 , short V_51 )
{
switch ( V_46 & V_47 ) {
case V_48 :
return V_51 << 1 ;
default:
return - V_50 ;
}
}
static int F_30 ( T_3 V_46 )
{
switch ( V_46 & V_47 ) {
case V_48 :
case V_52 :
return 2 ;
case V_49 :
case V_53 :
return 4 ;
default:
return - V_50 ;
}
}
static int F_31 ( T_3 V_46 )
{
switch ( V_46 & V_47 ) {
case V_52 :
case V_53 :
return 2 ;
case V_48 :
case V_49 :
return 1 ;
default:
return - V_50 ;
}
}
static T_3 F_32 ( struct V_15 * V_5 , T_3 V_54 , T_3 V_51 )
{
T_3 V_55 , V_56 , V_19 ;
if ( F_33 ( V_5 ) ) {
V_55 = 0x1f ;
V_56 = 5 ;
} else {
V_55 = 0x3f ;
V_56 = 6 ;
}
V_19 = ( ( V_54 + V_51 + V_55 ) >> V_56 ) - ( V_54 >> V_56 ) ;
if ( ! F_33 ( V_5 ) )
V_19 <<= 1 ;
V_19 -= 1 ;
return V_19 << 2 ;
}
static void F_34 ( struct V_1 T_1 * V_7 )
{
F_35 ( V_7 -> V_57 , V_58 , sizeof( V_58 ) ) ;
F_35 ( V_7 -> V_59 , V_60 ,
sizeof( V_60 ) ) ;
}
static bool F_36 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 ,
struct V_61 * V_62 )
{
T_3 V_63 , V_64 , V_65 , V_66 ;
#define F_37 12
#define F_38 0xfff
bool V_67 = false ;
int V_68 = F_30 ( V_62 -> V_46 ) ;
int V_69 = F_31 ( V_62 -> V_46 ) ;
if ( V_62 -> V_70 > 1 )
V_63 = ( ( V_62 -> V_71 - 1 ) << F_37 )
/ ( V_62 -> V_70 ) ;
else
V_63 = 1 << F_37 ;
if ( V_62 -> V_72 > 1 )
V_64 = ( ( V_62 -> V_73 - 1 ) << F_37 )
/ ( V_62 -> V_72 ) ;
else
V_64 = 1 << F_37 ;
V_65 = V_63 / V_68 ;
V_66 = V_64 / V_69 ;
V_63 = V_65 * V_68 ;
V_64 = V_66 * V_69 ;
if ( V_63 != V_3 -> V_74 || V_64 != V_3 -> V_75 )
V_67 = true ;
V_3 -> V_74 = V_63 ;
V_3 -> V_75 = V_64 ;
F_39 ( ( ( V_64 & F_38 ) << 20 ) |
( ( V_63 >> F_37 ) << 16 ) |
( ( V_63 & F_38 ) << 3 ) ,
& V_7 -> V_76 ) ;
F_39 ( ( ( V_66 & F_38 ) << 20 ) |
( ( V_65 >> F_37 ) << 16 ) |
( ( V_65 & F_38 ) << 3 ) ,
& V_7 -> V_77 ) ;
F_39 ( ( ( ( V_64 >> F_37 ) << 16 ) |
( ( V_66 >> F_37 ) << 0 ) ) ,
& V_7 -> V_78 ) ;
if ( V_67 )
F_34 ( V_7 ) ;
return V_67 ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
T_3 V_79 = V_3 -> V_80 ;
switch ( V_3 -> V_42 -> V_40 . V_81 -> V_82 ) {
case 8 :
F_39 ( 0 , & V_7 -> V_83 ) ;
F_39 ( V_84 | V_85 , & V_7 -> V_86 ) ;
break;
case 16 :
if ( V_3 -> V_42 -> V_40 . V_81 -> V_87 == 15 ) {
F_39 ( F_41 ( V_79 ) , & V_7 -> V_83 ) ;
F_39 ( V_88 | V_85 ,
& V_7 -> V_86 ) ;
} else {
F_39 ( F_42 ( V_79 ) , & V_7 -> V_83 ) ;
F_39 ( V_89 | V_85 ,
& V_7 -> V_86 ) ;
}
break;
case 24 :
case 32 :
F_39 ( V_79 , & V_7 -> V_83 ) ;
F_39 ( V_90 | V_85 , & V_7 -> V_86 ) ;
break;
}
}
static T_3 F_43 ( struct V_61 * V_62 )
{
T_3 V_91 = V_92 | V_93 | V_94 ;
if ( V_62 -> V_46 & V_95 ) {
switch ( V_62 -> V_46 & V_47 ) {
case V_48 :
V_91 |= V_96 ;
break;
case V_52 :
V_91 |= V_97 ;
break;
case V_49 :
case V_53 :
V_91 |= V_98 ;
break;
}
} else {
switch ( V_62 -> V_46 & V_47 ) {
case V_48 :
V_91 |= V_99 ;
break;
case V_49 :
V_91 |= V_100 ;
break;
}
switch ( V_62 -> V_46 & V_101 ) {
case V_102 :
break;
case V_103 :
V_91 |= V_104 ;
break;
case V_105 :
V_91 |= V_106 ;
break;
case V_107 :
V_91 |= V_108 ;
break;
}
}
return V_91 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_37 * V_109 ,
struct V_61 * V_62 )
{
int V_19 , V_110 ;
struct V_1 T_1 * V_7 ;
bool V_67 = false ;
struct V_15 * V_5 = V_3 -> V_5 ;
T_3 V_111 , V_112 , V_113 , V_114 ;
F_8 ( ! F_45 ( & V_5 -> V_115 ) ) ;
F_8 ( ! F_45 ( & V_5 -> V_116 . V_117 ) ) ;
F_8 ( ! V_3 ) ;
V_19 = F_27 ( V_3 ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_46 ( V_109 , 0 , NULL ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_47 ( V_109 ) ;
if ( V_19 )
goto V_118;
if ( ! V_3 -> V_23 ) {
T_3 V_119 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_19 = - V_120 ;
goto V_118;
}
V_119 = V_121 ;
if ( F_48 ( V_3 -> V_5 ) )
V_119 |= V_122 ;
V_119 |= V_3 -> V_42 -> V_123 == 0 ?
V_124 : V_125 ;
F_39 ( V_119 , & V_7 -> V_126 ) ;
F_4 ( V_3 , V_7 ) ;
V_19 = F_12 ( V_3 ) ;
if ( V_19 != 0 )
goto V_118;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_19 = - V_120 ;
goto V_118;
}
F_39 ( ( V_62 -> V_127 << 16 ) | V_62 -> V_128 , & V_7 -> V_129 ) ;
F_39 ( ( V_62 -> V_72 << 16 ) | V_62 -> V_70 , & V_7 -> V_130 ) ;
if ( V_62 -> V_46 & V_131 )
V_110 = F_29 ( V_62 -> V_46 , V_62 -> V_132 ) ;
else
V_110 = V_62 -> V_132 ;
V_111 = V_62 -> V_132 ;
V_112 = F_32 ( V_3 -> V_5 , V_62 -> V_133 , V_110 ) ;
V_113 = V_62 -> V_134 ;
F_39 ( V_109 -> V_14 + V_62 -> V_133 , & V_7 -> V_135 ) ;
V_114 = V_62 -> V_136 ;
if ( V_62 -> V_46 & V_95 ) {
int V_68 = F_30 ( V_62 -> V_46 ) ;
int V_69 = F_31 ( V_62 -> V_46 ) ;
T_3 V_137 , V_138 ;
V_111 |= ( V_62 -> V_132 / V_68 ) << 16 ;
V_137 = F_32 ( V_3 -> V_5 , V_62 -> V_139 ,
V_62 -> V_132 / V_68 ) ;
V_138 = F_32 ( V_3 -> V_5 , V_62 -> V_140 ,
V_62 -> V_132 / V_68 ) ;
V_112 |= F_49 ( T_3 , V_137 , V_138 ) << 16 ;
V_113 |= ( V_62 -> V_134 / V_69 ) << 16 ;
F_39 ( V_109 -> V_14 + V_62 -> V_139 , & V_7 -> V_141 ) ;
F_39 ( V_109 -> V_14 + V_62 -> V_140 , & V_7 -> V_142 ) ;
V_114 |= V_62 -> V_143 << 16 ;
}
F_39 ( V_111 , & V_7 -> V_144 ) ;
F_39 ( V_112 , & V_7 -> V_145 ) ;
F_39 ( V_113 , & V_7 -> V_146 ) ;
F_39 ( V_114 , & V_7 -> V_147 ) ;
V_67 = F_36 ( V_3 , V_7 , V_62 ) ;
F_40 ( V_3 , V_7 ) ;
F_39 ( F_43 ( V_62 ) , & V_7 -> V_148 ) ;
F_4 ( V_3 , V_7 ) ;
V_19 = F_18 ( V_3 , V_67 ) ;
if ( V_19 )
goto V_118;
V_3 -> V_39 = V_3 -> V_41 ;
V_3 -> V_41 = V_109 ;
return 0 ;
V_118:
F_22 ( V_109 ) ;
return V_19 ;
}
int F_50 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_7 ;
struct V_15 * V_5 = V_3 -> V_5 ;
int V_19 ;
F_8 ( ! F_45 ( & V_5 -> V_115 ) ) ;
F_8 ( ! F_45 ( & V_5 -> V_116 . V_117 ) ) ;
V_19 = F_26 ( V_3 ) ;
if ( V_19 != 0 )
return V_19 ;
if ( ! V_3 -> V_23 )
return 0 ;
V_19 = F_27 ( V_3 ) ;
if ( V_19 != 0 )
return V_19 ;
V_7 = F_1 ( V_3 ) ;
F_39 ( 0 , & V_7 -> V_148 ) ;
F_4 ( V_3 , V_7 ) ;
V_19 = F_25 ( V_3 ) ;
if ( V_19 != 0 )
return V_19 ;
F_24 ( V_3 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_149 * V_42 )
{
T_2 * V_4 = V_3 -> V_5 -> V_6 ;
if ( ! V_42 -> V_23 )
return - V_50 ;
if ( F_52 ( V_3 -> V_5 ) -> V_150 < 4 &&
( F_19 ( F_53 ( V_42 -> V_123 ) ) & ( V_151 | V_152 ) ) != V_152 )
return - V_50 ;
return 0 ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_15 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
T_3 V_153 = F_19 ( V_154 ) ;
T_3 V_155 ;
if ( F_52 ( V_5 ) -> V_150 >= 4 ) {
V_155 = F_19 ( V_156 ) >> V_157 ;
} else {
if ( V_153 & V_158 )
V_155 = F_19 ( V_159 ) ;
else
V_155 = F_19 ( V_156 ) ;
V_155 >>= V_160 ;
}
V_3 -> V_161 = V_155 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 = & V_3 -> V_42 -> V_40 . V_165 ;
if ( V_163 -> V_128 < V_165 -> V_166 &&
V_163 -> V_128 + V_163 -> V_167 <= V_165 -> V_166 &&
V_163 -> V_127 < V_165 -> V_168 &&
V_163 -> V_127 + V_163 -> V_169 <= V_165 -> V_168 )
return 0 ;
else
return - V_50 ;
}
static int F_56 ( struct V_61 * V_163 )
{
T_3 V_34 ;
V_34 = ( ( V_163 -> V_73 << 16 ) / V_163 -> V_72 ) >> 16 ;
if ( V_34 > 7 )
return - V_50 ;
V_34 = ( ( V_163 -> V_71 << 16 ) / V_163 -> V_70 ) >> 16 ;
if ( V_34 > 7 )
return - V_50 ;
return 0 ;
}
static int F_57 ( struct V_15 * V_5 ,
struct V_162 * V_163 ,
struct V_37 * V_109 )
{
int V_68 = F_30 ( V_163 -> V_170 ) ;
int V_69 = F_31 ( V_163 -> V_170 ) ;
T_3 V_171 ;
int V_87 ;
T_3 V_34 ;
if ( F_58 ( V_5 ) || F_14 ( V_5 ) ) {
if ( V_163 -> V_172 > V_173 ||
V_163 -> V_174 > V_175 )
return - V_50 ;
} else {
if ( V_163 -> V_172 > V_176 ||
V_163 -> V_174 > V_177 )
return - V_50 ;
}
if ( V_163 -> V_172 < V_178 * 4 ||
V_163 -> V_174 < V_179 * 4 )
return - V_50 ;
switch ( V_163 -> V_170 & V_180 ) {
case V_181 :
return - V_50 ;
case V_131 :
if ( V_69 != 1 )
return - V_50 ;
V_87 = F_28 ( V_163 -> V_170 ) ;
if ( V_87 < 0 )
return V_87 ;
V_163 -> V_143 = 0 ;
V_163 -> V_139 = 0 ;
V_163 -> V_140 = 0 ;
if ( V_163 -> V_133 % V_87 )
return - V_50 ;
break;
case V_95 :
if ( V_69 < 0 || V_68 < 0 )
return - V_50 ;
break;
default:
return - V_50 ;
}
if ( V_163 -> V_174 % V_68 )
return - V_50 ;
if ( F_14 ( V_5 ) || F_58 ( V_5 ) )
V_171 = 255 ;
else
V_171 = 63 ;
if ( V_163 -> V_136 & V_171 || V_163 -> V_143 & V_171 )
return - V_50 ;
if ( F_48 ( V_5 ) && V_163 -> V_136 < 512 )
return - V_50 ;
V_34 = ( V_163 -> V_170 & V_180 ) == V_95 ?
4096 : 8192 ;
if ( V_163 -> V_136 > V_34 || V_163 -> V_143 > 2 * 1024 )
return - V_50 ;
switch ( V_163 -> V_170 & V_180 ) {
case V_181 :
case V_131 :
if ( F_29 ( V_163 -> V_170 , V_163 -> V_174 ) > V_163 -> V_136 )
return - V_50 ;
V_34 = V_163 -> V_136 * V_163 -> V_172 ;
if ( V_163 -> V_133 + V_34 > V_109 -> V_40 . V_182 )
return - V_50 ;
break;
case V_95 :
if ( V_163 -> V_174 > V_163 -> V_136 )
return - V_50 ;
if ( V_163 -> V_174 / V_68 > V_163 -> V_143 )
return - V_50 ;
V_34 = V_163 -> V_136 * V_163 -> V_172 ;
if ( V_163 -> V_133 + V_34 > V_109 -> V_40 . V_182 )
return - V_50 ;
V_34 = V_163 -> V_143 * ( V_163 -> V_172 / V_69 ) ;
if ( V_163 -> V_139 + V_34 > V_109 -> V_40 . V_182 ||
V_163 -> V_140 + V_34 > V_109 -> V_40 . V_182 )
return - V_50 ;
break;
}
return 0 ;
}
static int F_59 ( struct V_15 * V_5 )
{
struct V_22 * V_4 = V_5 -> V_6 ;
T_3 V_153 ;
if ( F_14 ( V_5 ) )
return - 1 ;
V_153 = F_19 ( V_154 ) ;
if ( ( V_153 & V_183 ) == 0 )
return - 1 ;
if ( F_48 ( V_5 ) )
return ( V_153 >> 29 ) & 0x3 ;
return 1 ;
}
int F_60 ( struct V_15 * V_5 , void * V_184 ,
struct V_185 * V_186 )
{
struct V_162 * V_187 = V_184 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_188 * V_189 ;
struct V_149 * V_42 ;
struct V_37 * V_109 ;
struct V_61 * V_62 ;
int V_19 ;
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_20 ( L_2 ) ;
return - V_190 ;
}
if ( ! ( V_187 -> V_170 & V_191 ) ) {
F_61 ( V_5 ) ;
F_62 ( & V_5 -> V_115 ) ;
V_19 = F_50 ( V_3 ) ;
F_63 ( & V_5 -> V_115 ) ;
F_64 ( V_5 ) ;
return V_19 ;
}
V_62 = F_65 ( sizeof( struct V_61 ) , V_192 ) ;
if ( ! V_62 )
return - V_120 ;
V_189 = F_66 ( V_5 , V_187 -> V_193 ,
V_194 ) ;
if ( ! V_189 ) {
V_19 = - V_195 ;
goto V_196;
}
V_42 = F_67 ( F_68 ( V_189 ) ) ;
V_109 = F_69 ( F_70 ( V_5 , V_186 ,
V_187 -> V_197 ) ) ;
if ( & V_109 -> V_40 == NULL ) {
V_19 = - V_195 ;
goto V_196;
}
F_61 ( V_5 ) ;
F_62 ( & V_5 -> V_115 ) ;
if ( V_109 -> V_198 ) {
F_71 ( L_3 ) ;
V_19 = - V_50 ;
goto V_199;
}
V_19 = F_26 ( V_3 ) ;
if ( V_19 != 0 )
goto V_199;
if ( V_3 -> V_42 != V_42 ) {
struct V_164 * V_165 = & V_42 -> V_40 . V_165 ;
V_19 = F_50 ( V_3 ) ;
if ( V_19 != 0 )
goto V_199;
V_19 = F_51 ( V_3 , V_42 ) ;
if ( V_19 != 0 )
goto V_199;
V_3 -> V_42 = V_42 ;
V_42 -> V_3 = V_3 ;
if ( V_165 -> V_166 > 1024 &&
F_59 ( V_5 ) == V_42 -> V_123 ) {
V_3 -> V_200 = 1 ;
F_54 ( V_3 ) ;
} else
V_3 -> V_200 = 0 ;
}
V_19 = F_55 ( V_3 , V_187 ) ;
if ( V_19 != 0 )
goto V_199;
if ( V_3 -> V_200 ) {
V_62 -> V_127 = ( ( ( ( T_3 ) V_187 -> V_127 ) << 12 ) /
V_3 -> V_161 ) ;
V_62 -> V_72 = ( ( ( ( T_3 ) V_187 -> V_169 ) << 12 ) /
V_3 -> V_161 ) + 1 ;
} else {
V_62 -> V_127 = V_187 -> V_127 ;
V_62 -> V_72 = V_187 -> V_169 ;
}
V_62 -> V_128 = V_187 -> V_128 ;
V_62 -> V_70 = V_187 -> V_167 ;
V_62 -> V_132 = V_187 -> V_174 ;
V_62 -> V_134 = V_187 -> V_172 ;
V_62 -> V_71 = V_187 -> V_201 ;
V_62 -> V_73 = V_187 -> V_202 ;
if ( V_62 -> V_73 > V_62 -> V_134 ||
V_62 -> V_71 > V_62 -> V_132 ) {
V_19 = - V_50 ;
goto V_199;
}
V_19 = F_57 ( V_5 , V_187 , V_109 ) ;
if ( V_19 != 0 )
goto V_199;
V_62 -> V_46 = V_187 -> V_170 & ~ V_203 ;
V_62 -> V_136 = V_187 -> V_136 ;
V_62 -> V_143 = V_187 -> V_143 ;
V_62 -> V_133 = V_187 -> V_133 ;
V_62 -> V_139 = V_187 -> V_139 ;
V_62 -> V_140 = V_187 -> V_140 ;
V_19 = F_56 ( V_62 ) ;
if ( V_19 != 0 )
goto V_199;
V_19 = F_44 ( V_3 , V_109 , V_62 ) ;
if ( V_19 != 0 )
goto V_199;
F_63 ( & V_5 -> V_115 ) ;
F_64 ( V_5 ) ;
F_72 ( V_62 ) ;
return 0 ;
V_199:
F_63 ( & V_5 -> V_115 ) ;
F_64 ( V_5 ) ;
F_73 ( & V_109 -> V_40 ) ;
V_196:
F_72 ( V_62 ) ;
return V_19 ;
}
static void F_74 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
F_39 ( ( V_3 -> V_204 << 18 ) | ( V_3 -> V_205 & 0xff ) ,
& V_7 -> V_206 ) ;
F_39 ( V_3 -> V_207 , & V_7 -> V_208 ) ;
}
static bool F_75 ( T_3 V_209 , T_3 V_210 )
{
int V_211 ;
if ( V_209 & 0xff000000 || V_210 & 0xff000000 )
return false ;
for ( V_211 = 0 ; V_211 < 3 ; V_211 ++ ) {
if ( ( ( V_209 >> V_211 * 8 ) & 0xff ) >= ( ( V_210 >> V_211 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_76 ( T_3 V_212 )
{
int V_211 ;
for ( V_211 = 0 ; V_211 < 3 ; V_211 ++ ) {
if ( ( ( V_212 >> V_211 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_77 ( struct V_213 * V_214 )
{
if ( ! F_75 ( 0 , V_214 -> V_215 ) ||
! F_75 ( V_214 -> V_215 , V_214 -> V_209 ) ||
! F_75 ( V_214 -> V_209 , V_214 -> V_210 ) ||
! F_75 ( V_214 -> V_210 , V_214 -> V_216 ) ||
! F_75 ( V_214 -> V_216 , V_214 -> V_217 ) ||
! F_75 ( V_214 -> V_217 , V_214 -> V_212 ) ||
! F_75 ( V_214 -> V_212 , 0x00ffffff ) )
return - V_50 ;
if ( ! F_76 ( V_214 -> V_212 ) )
return - V_50 ;
return 0 ;
}
int F_78 ( struct V_15 * V_5 , void * V_184 ,
struct V_185 * V_186 )
{
struct V_213 * V_214 = V_184 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_7 ;
int V_19 ;
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_20 ( L_2 ) ;
return - V_190 ;
}
F_61 ( V_5 ) ;
F_62 ( & V_5 -> V_115 ) ;
V_19 = - V_50 ;
if ( ! ( V_214 -> V_170 & V_218 ) ) {
V_214 -> V_80 = V_3 -> V_80 ;
V_214 -> V_205 = V_3 -> V_205 ;
V_214 -> V_204 = V_3 -> V_204 ;
V_214 -> V_207 = V_3 -> V_207 ;
if ( ! F_33 ( V_5 ) ) {
V_214 -> V_215 = F_19 ( V_219 ) ;
V_214 -> V_209 = F_19 ( V_220 ) ;
V_214 -> V_210 = F_19 ( V_221 ) ;
V_214 -> V_216 = F_19 ( V_222 ) ;
V_214 -> V_217 = F_19 ( V_223 ) ;
V_214 -> V_212 = F_19 ( V_224 ) ;
}
} else {
if ( V_214 -> V_205 < - 128 || V_214 -> V_205 > 127 )
goto V_199;
if ( V_214 -> V_204 > 255 )
goto V_199;
if ( V_214 -> V_207 > 1023 )
goto V_199;
V_3 -> V_80 = V_214 -> V_80 ;
V_3 -> V_205 = V_214 -> V_205 ;
V_3 -> V_204 = V_214 -> V_204 ;
V_3 -> V_207 = V_214 -> V_207 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_19 = - V_120 ;
goto V_199;
}
F_74 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( V_214 -> V_170 & V_225 ) {
if ( F_33 ( V_5 ) )
goto V_199;
if ( V_3 -> V_23 ) {
V_19 = - V_226 ;
goto V_199;
}
V_19 = F_77 ( V_214 ) ;
if ( V_19 )
goto V_199;
F_79 ( V_219 , V_214 -> V_215 ) ;
F_79 ( V_220 , V_214 -> V_209 ) ;
F_79 ( V_221 , V_214 -> V_210 ) ;
F_79 ( V_222 , V_214 -> V_216 ) ;
F_79 ( V_223 , V_214 -> V_217 ) ;
F_79 ( V_224 , V_214 -> V_212 ) ;
}
}
V_19 = 0 ;
V_199:
F_63 ( & V_5 -> V_115 ) ;
F_64 ( V_5 ) ;
return V_19 ;
}
void F_80 ( struct V_15 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_37 * V_8 ;
struct V_1 T_1 * V_7 ;
int V_19 ;
if ( ! F_81 ( V_5 ) )
return;
V_3 = F_82 ( sizeof( struct V_2 ) , V_192 ) ;
if ( ! V_3 )
return;
F_62 ( & V_5 -> V_115 ) ;
if ( F_13 ( V_4 -> V_3 ) )
goto V_196;
V_3 -> V_5 = V_5 ;
V_8 = F_83 ( V_5 , V_227 ) ;
if ( V_8 == NULL )
V_8 = F_84 ( V_5 , V_227 ) ;
if ( V_8 == NULL )
goto V_196;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_19 = F_85 ( V_5 , V_8 ,
V_228 ,
V_227 ) ;
if ( V_19 ) {
F_71 ( L_4 ) ;
goto V_229;
}
V_3 -> V_28 = V_8 -> V_9 -> V_10 -> V_230 ;
} else {
V_19 = F_86 ( V_8 , V_227 , true , false ) ;
if ( V_19 ) {
F_71 ( L_5 ) ;
goto V_229;
}
V_3 -> V_28 = V_8 -> V_14 ;
V_19 = F_87 ( V_8 , true ) ;
if ( V_19 ) {
F_71 ( L_6 ) ;
goto V_231;
}
}
V_3 -> V_80 = 0x0101fe ;
V_3 -> V_205 = - 19 ;
V_3 -> V_204 = 75 ;
V_3 -> V_207 = 146 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_231;
F_88 ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_34 ( V_7 ) ;
F_74 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
V_4 -> V_3 = V_3 ;
F_63 ( & V_5 -> V_115 ) ;
F_89 ( L_7 ) ;
return;
V_231:
if ( ! F_2 ( V_5 ) )
F_22 ( V_8 ) ;
V_229:
F_23 ( & V_8 -> V_40 ) ;
V_196:
F_63 ( & V_5 -> V_115 ) ;
F_72 ( V_3 ) ;
return;
}
void F_90 ( struct V_15 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
if ( ! V_4 -> V_3 )
return;
F_8 ( V_4 -> V_3 -> V_23 ) ;
F_73 ( & V_4 -> V_3 -> V_8 -> V_40 ) ;
F_72 ( V_4 -> V_3 ) ;
}
static struct V_1 T_1 *
F_91 ( struct V_2 * V_3 )
{
T_2 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = (struct V_1 T_1 * )
V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_92 ( V_4 -> V_12 . V_13 ,
V_3 -> V_8 -> V_14 ) ;
return V_7 ;
}
static void F_93 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_94 ( V_7 ) ;
}
struct V_232 *
F_95 ( struct V_15 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_232 * error ;
struct V_1 T_1 * V_7 ;
if ( ! V_3 || ! V_3 -> V_23 )
return NULL ;
error = F_65 ( sizeof( * error ) , V_233 ) ;
if ( error == NULL )
return NULL ;
error -> V_234 = F_19 ( V_35 ) ;
error -> V_235 = F_19 ( V_44 ) ;
if ( F_2 ( V_3 -> V_5 ) )
error -> V_40 = ( V_236 long ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
error -> V_40 = V_3 -> V_8 -> V_14 ;
V_7 = F_91 ( V_3 ) ;
if ( ! V_7 )
goto V_237;
F_96 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_93 ( V_3 , V_7 ) ;
return error ;
V_237:
F_72 ( error ) ;
return NULL ;
}
void
F_97 ( struct V_238 * V_239 , struct V_232 * error )
{
F_98 ( V_239 , L_8 ,
error -> V_234 , error -> V_235 ) ;
F_98 ( V_239 , L_9 ,
error -> V_40 ) ;
#define F_99 ( T_4 ) seq_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_99 ( V_135 ) ;
F_99 ( V_240 ) ;
F_99 ( V_141 ) ;
F_99 ( V_142 ) ;
F_99 ( V_241 ) ;
F_99 ( V_242 ) ;
F_99 ( V_147 ) ;
F_99 ( V_243 ) ;
F_99 ( V_244 ) ;
F_99 ( V_245 ) ;
F_99 ( V_246 ) ;
F_99 ( V_129 ) ;
F_99 ( V_130 ) ;
F_99 ( V_144 ) ;
F_99 ( V_145 ) ;
F_99 ( V_146 ) ;
F_99 ( V_76 ) ;
F_99 ( V_77 ) ;
F_99 ( V_206 ) ;
F_99 ( V_208 ) ;
F_99 ( V_83 ) ;
F_99 ( V_86 ) ;
F_99 ( V_247 ) ;
F_99 ( V_248 ) ;
F_99 ( V_249 ) ;
F_99 ( V_126 ) ;
F_99 ( V_148 ) ;
F_99 ( V_250 ) ;
F_99 ( V_251 ) ;
F_99 ( V_252 ) ;
F_99 ( V_253 ) ;
F_99 ( V_254 ) ;
F_99 ( V_255 ) ;
F_99 ( V_256 ) ;
F_99 ( V_257 ) ;
F_99 ( V_258 ) ;
F_99 ( V_259 ) ;
F_99 ( V_260 ) ;
F_99 ( V_261 ) ;
F_99 ( V_262 ) ;
F_99 ( V_78 ) ;
#undef F_99
}
