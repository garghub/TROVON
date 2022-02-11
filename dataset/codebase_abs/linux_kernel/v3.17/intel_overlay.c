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
F_29 ( V_3 -> V_37 , NULL ,
F_30 ( V_3 -> V_40 -> V_44 ) ) ;
return 0 ;
}
static int F_31 ( T_2 V_45 )
{
switch ( V_45 & V_46 ) {
case V_47 :
return 4 ;
case V_48 :
default:
return - V_49 ;
}
}
static int F_32 ( T_2 V_45 , short V_50 )
{
switch ( V_45 & V_46 ) {
case V_47 :
return V_50 << 1 ;
default:
return - V_49 ;
}
}
static int F_33 ( T_2 V_45 )
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
static int F_34 ( T_2 V_45 )
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
static T_2 F_35 ( struct V_14 * V_6 , T_2 V_53 , T_2 V_50 )
{
T_2 V_54 , V_55 , V_18 ;
if ( F_36 ( V_6 ) ) {
V_54 = 0x1f ;
V_55 = 5 ;
} else {
V_54 = 0x3f ;
V_55 = 6 ;
}
V_18 = ( ( V_53 + V_50 + V_54 ) >> V_55 ) - ( V_53 >> V_55 ) ;
if ( ! F_36 ( V_6 ) )
V_18 <<= 1 ;
V_18 -= 1 ;
return V_18 << 2 ;
}
static void F_37 ( struct V_1 T_1 * V_8 )
{
F_38 ( V_8 -> V_56 , V_57 , sizeof( V_57 ) ) ;
F_38 ( V_8 -> V_58 , V_59 ,
sizeof( V_59 ) ) ;
}
static bool F_39 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 ,
struct V_60 * V_61 )
{
T_2 V_62 , V_63 , V_64 , V_65 ;
#define F_40 12
#define F_41 0xfff
bool V_66 = false ;
int V_67 = F_33 ( V_61 -> V_45 ) ;
int V_68 = F_34 ( V_61 -> V_45 ) ;
if ( V_61 -> V_69 > 1 )
V_62 = ( ( V_61 -> V_70 - 1 ) << F_40 )
/ ( V_61 -> V_69 ) ;
else
V_62 = 1 << F_40 ;
if ( V_61 -> V_71 > 1 )
V_63 = ( ( V_61 -> V_72 - 1 ) << F_40 )
/ ( V_61 -> V_71 ) ;
else
V_63 = 1 << F_40 ;
V_64 = V_62 / V_67 ;
V_65 = V_63 / V_68 ;
V_62 = V_64 * V_67 ;
V_63 = V_65 * V_68 ;
if ( V_62 != V_3 -> V_73 || V_63 != V_3 -> V_74 )
V_66 = true ;
V_3 -> V_73 = V_62 ;
V_3 -> V_74 = V_63 ;
F_42 ( ( ( V_63 & F_41 ) << 20 ) |
( ( V_62 >> F_40 ) << 16 ) |
( ( V_62 & F_41 ) << 3 ) ,
& V_8 -> V_75 ) ;
F_42 ( ( ( V_65 & F_41 ) << 20 ) |
( ( V_64 >> F_40 ) << 16 ) |
( ( V_64 & F_41 ) << 3 ) ,
& V_8 -> V_76 ) ;
F_42 ( ( ( ( V_63 >> F_40 ) << 16 ) |
( ( V_65 >> F_40 ) << 0 ) ) ,
& V_8 -> V_77 ) ;
if ( V_66 )
F_37 ( V_8 ) ;
return V_66 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
T_2 V_78 = V_3 -> V_79 ;
switch ( V_3 -> V_40 -> V_38 . V_80 -> V_81 -> V_82 ) {
case 8 :
F_42 ( 0 , & V_8 -> V_83 ) ;
F_42 ( V_84 | V_85 , & V_8 -> V_86 ) ;
break;
case 16 :
if ( V_3 -> V_40 -> V_38 . V_80 -> V_81 -> V_87 == 15 ) {
F_42 ( F_44 ( V_78 ) , & V_8 -> V_83 ) ;
F_42 ( V_88 | V_85 ,
& V_8 -> V_86 ) ;
} else {
F_42 ( F_45 ( V_78 ) , & V_8 -> V_83 ) ;
F_42 ( V_89 | V_85 ,
& V_8 -> V_86 ) ;
}
break;
case 24 :
case 32 :
F_42 ( V_78 , & V_8 -> V_83 ) ;
F_42 ( V_90 | V_85 , & V_8 -> V_86 ) ;
break;
}
}
static T_2 F_46 ( struct V_60 * V_61 )
{
T_2 V_91 = V_92 | V_93 | V_94 ;
if ( V_61 -> V_45 & V_95 ) {
switch ( V_61 -> V_45 & V_46 ) {
case V_47 :
V_91 |= V_96 ;
break;
case V_51 :
V_91 |= V_97 ;
break;
case V_48 :
case V_52 :
V_91 |= V_98 ;
break;
}
} else {
switch ( V_61 -> V_45 & V_46 ) {
case V_47 :
V_91 |= V_99 ;
break;
case V_48 :
V_91 |= V_100 ;
break;
}
switch ( V_61 -> V_45 & V_101 ) {
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
static int F_47 ( struct V_2 * V_3 ,
struct V_35 * V_109 ,
struct V_60 * V_61 )
{
int V_18 , V_110 ;
struct V_1 T_1 * V_8 ;
bool V_66 = false ;
struct V_14 * V_6 = V_3 -> V_6 ;
T_2 V_111 , V_112 , V_113 , V_114 ;
enum V_44 V_44 = V_3 -> V_40 -> V_44 ;
F_9 ( ! F_48 ( & V_6 -> V_115 ) ) ;
F_9 ( ! F_49 ( & V_6 -> V_116 . V_117 ) ) ;
F_9 ( ! V_3 ) ;
V_18 = F_28 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_50 ( V_109 , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_51 ( V_109 ) ;
if ( V_18 )
goto V_118;
if ( ! V_3 -> V_21 ) {
T_2 V_119 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_120 ;
goto V_118;
}
V_119 = V_121 ;
if ( F_52 ( V_3 -> V_6 ) )
V_119 |= V_122 ;
V_119 |= V_44 == 0 ?
V_123 : V_124 ;
F_42 ( V_119 , & V_8 -> V_125 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_13 ( V_3 ) ;
if ( V_18 != 0 )
goto V_118;
}
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_120 ;
goto V_118;
}
F_42 ( ( V_61 -> V_126 << 16 ) | V_61 -> V_127 , & V_8 -> V_128 ) ;
F_42 ( ( V_61 -> V_71 << 16 ) | V_61 -> V_69 , & V_8 -> V_129 ) ;
if ( V_61 -> V_45 & V_130 )
V_110 = F_32 ( V_61 -> V_45 , V_61 -> V_131 ) ;
else
V_110 = V_61 -> V_131 ;
V_111 = V_61 -> V_131 ;
V_112 = F_35 ( V_3 -> V_6 , V_61 -> V_132 , V_110 ) ;
V_113 = V_61 -> V_133 ;
F_42 ( F_4 ( V_109 ) + V_61 -> V_132 , & V_8 -> V_134 ) ;
V_114 = V_61 -> V_135 ;
if ( V_61 -> V_45 & V_95 ) {
int V_67 = F_33 ( V_61 -> V_45 ) ;
int V_68 = F_34 ( V_61 -> V_45 ) ;
T_2 V_136 , V_137 ;
V_111 |= ( V_61 -> V_131 / V_67 ) << 16 ;
V_136 = F_35 ( V_3 -> V_6 , V_61 -> V_138 ,
V_61 -> V_131 / V_67 ) ;
V_137 = F_35 ( V_3 -> V_6 , V_61 -> V_139 ,
V_61 -> V_131 / V_67 ) ;
V_112 |= F_53 ( T_2 , V_136 , V_137 ) << 16 ;
V_113 |= ( V_61 -> V_133 / V_68 ) << 16 ;
F_42 ( F_4 ( V_109 ) + V_61 -> V_138 , & V_8 -> V_140 ) ;
F_42 ( F_4 ( V_109 ) + V_61 -> V_139 , & V_8 -> V_141 ) ;
V_114 |= V_61 -> V_142 << 16 ;
}
F_42 ( V_111 , & V_8 -> V_143 ) ;
F_42 ( V_112 , & V_8 -> V_144 ) ;
F_42 ( V_113 , & V_8 -> V_145 ) ;
F_42 ( V_114 , & V_8 -> V_146 ) ;
V_66 = F_39 ( V_3 , V_8 , V_61 ) ;
F_43 ( V_3 , V_8 ) ;
F_42 ( F_46 ( V_61 ) , & V_8 -> V_147 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_19 ( V_3 , V_66 ) ;
if ( V_18 )
goto V_118;
F_29 ( V_3 -> V_39 , V_109 ,
F_30 ( V_44 ) ) ;
V_3 -> V_37 = V_3 -> V_39 ;
V_3 -> V_39 = V_109 ;
F_54 ( V_6 ,
F_30 ( V_44 ) ) ;
return 0 ;
V_118:
F_23 ( V_109 ) ;
return V_18 ;
}
int F_55 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_8 ;
struct V_14 * V_6 = V_3 -> V_6 ;
int V_18 ;
F_9 ( ! F_48 ( & V_6 -> V_115 ) ) ;
F_9 ( ! F_49 ( & V_6 -> V_116 . V_117 ) ) ;
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( ! V_3 -> V_21 )
return 0 ;
V_18 = F_28 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_8 = F_1 ( V_3 ) ;
F_42 ( 0 , & V_8 -> V_147 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_26 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
F_25 ( V_3 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_148 * V_40 )
{
if ( ! V_40 -> V_21 )
return - V_49 ;
if ( V_40 -> V_149 . V_150 )
return - V_49 ;
return 0 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_151 = F_20 ( V_152 ) ;
T_2 V_153 ;
if ( F_58 ( V_6 ) -> V_154 >= 4 ) {
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
static int F_59 ( struct V_2 * V_3 ,
struct V_161 * V_162 )
{
struct V_163 * V_164 = & V_3 -> V_40 -> V_38 . V_164 ;
if ( V_162 -> V_127 < V_164 -> V_165 &&
V_162 -> V_127 + V_162 -> V_166 <= V_164 -> V_165 &&
V_162 -> V_126 < V_164 -> V_167 &&
V_162 -> V_126 + V_162 -> V_168 <= V_164 -> V_167 )
return 0 ;
else
return - V_49 ;
}
static int F_60 ( struct V_60 * V_162 )
{
T_2 V_32 ;
V_32 = ( ( V_162 -> V_72 << 16 ) / V_162 -> V_71 ) >> 16 ;
if ( V_32 > 7 )
return - V_49 ;
V_32 = ( ( V_162 -> V_70 << 16 ) / V_162 -> V_69 ) >> 16 ;
if ( V_32 > 7 )
return - V_49 ;
return 0 ;
}
static int F_61 ( struct V_14 * V_6 ,
struct V_161 * V_162 ,
struct V_35 * V_109 )
{
int V_67 = F_33 ( V_162 -> V_169 ) ;
int V_68 = F_34 ( V_162 -> V_169 ) ;
T_2 V_170 ;
int V_87 ;
T_2 V_32 ;
if ( F_62 ( V_6 ) || F_15 ( V_6 ) ) {
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
V_87 = F_31 ( V_162 -> V_169 ) ;
if ( V_87 < 0 )
return V_87 ;
V_162 -> V_142 = 0 ;
V_162 -> V_138 = 0 ;
V_162 -> V_139 = 0 ;
if ( V_162 -> V_132 % V_87 )
return - V_49 ;
break;
case V_95 :
if ( V_68 < 0 || V_67 < 0 )
return - V_49 ;
break;
default:
return - V_49 ;
}
if ( V_162 -> V_173 % V_67 )
return - V_49 ;
if ( F_15 ( V_6 ) || F_62 ( V_6 ) )
V_170 = 255 ;
else
V_170 = 63 ;
if ( V_162 -> V_135 & V_170 || V_162 -> V_142 & V_170 )
return - V_49 ;
if ( F_52 ( V_6 ) && V_162 -> V_135 < 512 )
return - V_49 ;
V_32 = ( V_162 -> V_169 & V_179 ) == V_95 ?
4096 : 8192 ;
if ( V_162 -> V_135 > V_32 || V_162 -> V_142 > 2 * 1024 )
return - V_49 ;
switch ( V_162 -> V_169 & V_179 ) {
case V_180 :
case V_130 :
if ( F_32 ( V_162 -> V_169 , V_162 -> V_173 ) > V_162 -> V_135 )
return - V_49 ;
V_32 = V_162 -> V_135 * V_162 -> V_171 ;
if ( V_162 -> V_132 + V_32 > V_109 -> V_38 . V_181 )
return - V_49 ;
break;
case V_95 :
if ( V_162 -> V_173 > V_162 -> V_135 )
return - V_49 ;
if ( V_162 -> V_173 / V_67 > V_162 -> V_142 )
return - V_49 ;
V_32 = V_162 -> V_135 * V_162 -> V_171 ;
if ( V_162 -> V_132 + V_32 > V_109 -> V_38 . V_181 )
return - V_49 ;
V_32 = V_162 -> V_142 * ( V_162 -> V_171 / V_68 ) ;
if ( V_162 -> V_138 + V_32 > V_109 -> V_38 . V_181 ||
V_162 -> V_139 + V_32 > V_109 -> V_38 . V_181 )
return - V_49 ;
break;
}
return 0 ;
}
static int F_63 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_151 ;
if ( F_58 ( V_6 ) -> V_154 <= 3 && ( F_15 ( V_6 ) || ! F_64 ( V_6 ) ) )
return - 1 ;
V_151 = F_20 ( V_152 ) ;
if ( ( V_151 & V_182 ) == 0 )
return - 1 ;
if ( F_52 ( V_6 ) )
return ( V_151 >> 29 ) & 0x3 ;
return 1 ;
}
int F_65 ( struct V_14 * V_6 , void * V_183 ,
struct V_184 * V_185 )
{
struct V_161 * V_186 = V_183 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_187 * V_188 ;
struct V_148 * V_40 ;
struct V_35 * V_109 ;
struct V_60 * V_61 ;
int V_18 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_21 ( L_2 ) ;
return - V_189 ;
}
if ( ! ( V_186 -> V_169 & V_190 ) ) {
F_66 ( V_6 ) ;
F_67 ( & V_6 -> V_115 ) ;
V_18 = F_55 ( V_3 ) ;
F_68 ( & V_6 -> V_115 ) ;
F_69 ( V_6 ) ;
return V_18 ;
}
V_61 = F_70 ( sizeof( * V_61 ) , V_191 ) ;
if ( ! V_61 )
return - V_120 ;
V_188 = F_71 ( V_6 , V_186 -> V_192 ) ;
if ( ! V_188 ) {
V_18 = - V_193 ;
goto V_194;
}
V_40 = F_72 ( V_188 ) ;
V_109 = F_73 ( F_74 ( V_6 , V_185 ,
V_186 -> V_195 ) ) ;
if ( & V_109 -> V_38 == NULL ) {
V_18 = - V_193 ;
goto V_194;
}
F_66 ( V_6 ) ;
F_67 ( & V_6 -> V_115 ) ;
if ( V_109 -> V_196 ) {
F_75 ( L_3 ) ;
V_18 = - V_49 ;
goto V_197;
}
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
goto V_197;
if ( V_3 -> V_40 != V_40 ) {
struct V_163 * V_164 = & V_40 -> V_38 . V_164 ;
V_18 = F_55 ( V_3 ) ;
if ( V_18 != 0 )
goto V_197;
V_18 = F_56 ( V_3 , V_40 ) ;
if ( V_18 != 0 )
goto V_197;
V_3 -> V_40 = V_40 ;
V_40 -> V_3 = V_3 ;
if ( V_164 -> V_165 > 1024 &&
F_63 ( V_6 ) == V_40 -> V_44 ) {
V_3 -> V_198 = 1 ;
F_57 ( V_3 ) ;
} else
V_3 -> V_198 = 0 ;
}
V_18 = F_59 ( V_3 , V_186 ) ;
if ( V_18 != 0 )
goto V_197;
if ( V_3 -> V_198 ) {
V_61 -> V_126 = ( ( ( ( T_2 ) V_186 -> V_126 ) << 12 ) /
V_3 -> V_160 ) ;
V_61 -> V_71 = ( ( ( ( T_2 ) V_186 -> V_168 ) << 12 ) /
V_3 -> V_160 ) + 1 ;
} else {
V_61 -> V_126 = V_186 -> V_126 ;
V_61 -> V_71 = V_186 -> V_168 ;
}
V_61 -> V_127 = V_186 -> V_127 ;
V_61 -> V_69 = V_186 -> V_166 ;
V_61 -> V_131 = V_186 -> V_173 ;
V_61 -> V_133 = V_186 -> V_171 ;
V_61 -> V_70 = V_186 -> V_199 ;
V_61 -> V_72 = V_186 -> V_200 ;
if ( V_61 -> V_72 > V_61 -> V_133 ||
V_61 -> V_70 > V_61 -> V_131 ) {
V_18 = - V_49 ;
goto V_197;
}
V_18 = F_61 ( V_6 , V_186 , V_109 ) ;
if ( V_18 != 0 )
goto V_197;
V_61 -> V_45 = V_186 -> V_169 & ~ V_201 ;
V_61 -> V_135 = V_186 -> V_135 ;
V_61 -> V_142 = V_186 -> V_142 ;
V_61 -> V_132 = V_186 -> V_132 ;
V_61 -> V_138 = V_186 -> V_138 ;
V_61 -> V_139 = V_186 -> V_139 ;
V_18 = F_60 ( V_61 ) ;
if ( V_18 != 0 )
goto V_197;
V_18 = F_47 ( V_3 , V_109 , V_61 ) ;
if ( V_18 != 0 )
goto V_197;
F_68 ( & V_6 -> V_115 ) ;
F_69 ( V_6 ) ;
F_76 ( V_61 ) ;
return 0 ;
V_197:
F_68 ( & V_6 -> V_115 ) ;
F_69 ( V_6 ) ;
F_77 ( & V_109 -> V_38 ) ;
V_194:
F_76 ( V_61 ) ;
return V_18 ;
}
static void F_78 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
F_42 ( ( V_3 -> V_202 << 18 ) | ( V_3 -> V_203 & 0xff ) ,
& V_8 -> V_204 ) ;
F_42 ( V_3 -> V_205 , & V_8 -> V_206 ) ;
}
static bool F_79 ( T_2 V_207 , T_2 V_208 )
{
int V_209 ;
if ( V_207 & 0xff000000 || V_208 & 0xff000000 )
return false ;
for ( V_209 = 0 ; V_209 < 3 ; V_209 ++ ) {
if ( ( ( V_207 >> V_209 * 8 ) & 0xff ) >= ( ( V_208 >> V_209 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_80 ( T_2 V_210 )
{
int V_209 ;
for ( V_209 = 0 ; V_209 < 3 ; V_209 ++ ) {
if ( ( ( V_210 >> V_209 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_81 ( struct V_211 * V_212 )
{
if ( ! F_79 ( 0 , V_212 -> V_213 ) ||
! F_79 ( V_212 -> V_213 , V_212 -> V_207 ) ||
! F_79 ( V_212 -> V_207 , V_212 -> V_208 ) ||
! F_79 ( V_212 -> V_208 , V_212 -> V_214 ) ||
! F_79 ( V_212 -> V_214 , V_212 -> V_215 ) ||
! F_79 ( V_212 -> V_215 , V_212 -> V_210 ) ||
! F_79 ( V_212 -> V_210 , 0x00ffffff ) )
return - V_49 ;
if ( ! F_80 ( V_212 -> V_210 ) )
return - V_49 ;
return 0 ;
}
int F_82 ( struct V_14 * V_6 , void * V_183 ,
struct V_184 * V_185 )
{
struct V_211 * V_212 = V_183 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_8 ;
int V_18 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_21 ( L_2 ) ;
return - V_189 ;
}
F_66 ( V_6 ) ;
F_67 ( & V_6 -> V_115 ) ;
V_18 = - V_49 ;
if ( ! ( V_212 -> V_169 & V_216 ) ) {
V_212 -> V_79 = V_3 -> V_79 ;
V_212 -> V_203 = V_3 -> V_203 ;
V_212 -> V_202 = V_3 -> V_202 ;
V_212 -> V_205 = V_3 -> V_205 ;
if ( ! F_36 ( V_6 ) ) {
V_212 -> V_213 = F_20 ( V_217 ) ;
V_212 -> V_207 = F_20 ( V_218 ) ;
V_212 -> V_208 = F_20 ( V_219 ) ;
V_212 -> V_214 = F_20 ( V_220 ) ;
V_212 -> V_215 = F_20 ( V_221 ) ;
V_212 -> V_210 = F_20 ( V_222 ) ;
}
} else {
if ( V_212 -> V_203 < - 128 || V_212 -> V_203 > 127 )
goto V_197;
if ( V_212 -> V_202 > 255 )
goto V_197;
if ( V_212 -> V_205 > 1023 )
goto V_197;
V_3 -> V_79 = V_212 -> V_79 ;
V_3 -> V_203 = V_212 -> V_203 ;
V_3 -> V_202 = V_212 -> V_202 ;
V_3 -> V_205 = V_212 -> V_205 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_120 ;
goto V_197;
}
F_78 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
if ( V_212 -> V_169 & V_223 ) {
if ( F_36 ( V_6 ) )
goto V_197;
if ( V_3 -> V_21 ) {
V_18 = - V_224 ;
goto V_197;
}
V_18 = F_81 ( V_212 ) ;
if ( V_18 )
goto V_197;
F_83 ( V_217 , V_212 -> V_213 ) ;
F_83 ( V_218 , V_212 -> V_207 ) ;
F_83 ( V_219 , V_212 -> V_208 ) ;
F_83 ( V_220 , V_212 -> V_214 ) ;
F_83 ( V_221 , V_212 -> V_215 ) ;
F_83 ( V_222 , V_212 -> V_210 ) ;
}
}
V_18 = 0 ;
V_197:
F_68 ( & V_6 -> V_115 ) ;
F_69 ( V_6 ) ;
return V_18 ;
}
void F_84 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_35 * V_9 ;
struct V_1 T_1 * V_8 ;
int V_18 ;
if ( ! F_85 ( V_6 ) )
return;
V_3 = F_86 ( sizeof( * V_3 ) , V_191 ) ;
if ( ! V_3 )
return;
F_67 ( & V_6 -> V_115 ) ;
if ( F_14 ( V_5 -> V_3 ) )
goto V_194;
V_3 -> V_6 = V_6 ;
V_9 = NULL ;
if ( ! F_2 ( V_6 ) )
V_9 = F_87 ( V_6 , V_225 ) ;
if ( V_9 == NULL )
V_9 = F_88 ( V_6 , V_225 ) ;
if ( V_9 == NULL )
goto V_194;
V_3 -> V_9 = V_9 ;
if ( F_2 ( V_6 ) ) {
V_18 = F_89 ( V_9 , V_225 ) ;
if ( V_18 ) {
F_90 ( L_4 ) ;
goto V_226;
}
V_3 -> V_26 = V_9 -> V_10 -> V_227 ;
} else {
V_18 = F_91 ( V_9 , V_225 , V_228 ) ;
if ( V_18 ) {
F_90 ( L_5 ) ;
goto V_226;
}
V_3 -> V_26 = F_4 ( V_9 ) ;
V_18 = F_92 ( V_9 , true ) ;
if ( V_18 ) {
F_90 ( L_6 ) ;
goto V_229;
}
}
V_3 -> V_79 = 0x0101fe ;
V_3 -> V_203 = - 19 ;
V_3 -> V_202 = 75 ;
V_3 -> V_205 = 146 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
goto V_229;
F_93 ( V_8 , 0 , sizeof( struct V_1 ) ) ;
F_37 ( V_8 ) ;
F_78 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
V_5 -> V_3 = V_3 ;
F_68 ( & V_6 -> V_115 ) ;
F_94 ( L_7 ) ;
return;
V_229:
if ( ! F_2 ( V_6 ) )
F_23 ( V_9 ) ;
V_226:
F_24 ( & V_9 -> V_38 ) ;
V_194:
F_68 ( & V_6 -> V_115 ) ;
F_76 ( V_3 ) ;
return;
}
void F_95 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
if ( ! V_5 -> V_3 )
return;
F_9 ( V_5 -> V_3 -> V_21 ) ;
F_77 ( & V_5 -> V_3 -> V_9 -> V_38 ) ;
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
struct V_230 *
F_100 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_230 * error ;
struct V_1 T_1 * V_8 ;
if ( ! V_3 || ! V_3 -> V_21 )
return NULL ;
error = F_70 ( sizeof( * error ) , V_231 ) ;
if ( error == NULL )
return NULL ;
error -> V_232 = F_20 ( V_33 ) ;
error -> V_233 = F_20 ( V_42 ) ;
if ( F_2 ( V_3 -> V_6 ) )
error -> V_38 = ( V_234 long ) V_3 -> V_9 -> V_10 -> V_11 ;
else
error -> V_38 = F_4 ( V_3 -> V_9 ) ;
V_8 = F_96 ( V_3 ) ;
if ( ! V_8 )
goto V_235;
F_101 ( & error -> V_8 , V_8 , sizeof( struct V_1 ) ) ;
F_98 ( V_3 , V_8 ) ;
return error ;
V_235:
F_76 ( error ) ;
return NULL ;
}
void
F_102 ( struct V_236 * V_237 ,
struct V_230 * error )
{
F_103 ( V_237 , L_8 ,
error -> V_232 , error -> V_233 ) ;
F_103 ( V_237 , L_9 ,
error -> V_38 ) ;
#define F_104 ( T_3 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_104 ( V_134 ) ;
F_104 ( V_238 ) ;
F_104 ( V_140 ) ;
F_104 ( V_141 ) ;
F_104 ( V_239 ) ;
F_104 ( V_240 ) ;
F_104 ( V_146 ) ;
F_104 ( V_241 ) ;
F_104 ( V_242 ) ;
F_104 ( V_243 ) ;
F_104 ( V_244 ) ;
F_104 ( V_128 ) ;
F_104 ( V_129 ) ;
F_104 ( V_143 ) ;
F_104 ( V_144 ) ;
F_104 ( V_145 ) ;
F_104 ( V_75 ) ;
F_104 ( V_76 ) ;
F_104 ( V_204 ) ;
F_104 ( V_206 ) ;
F_104 ( V_83 ) ;
F_104 ( V_86 ) ;
F_104 ( V_245 ) ;
F_104 ( V_246 ) ;
F_104 ( V_247 ) ;
F_104 ( V_125 ) ;
F_104 ( V_147 ) ;
F_104 ( V_248 ) ;
F_104 ( V_249 ) ;
F_104 ( V_250 ) ;
F_104 ( V_251 ) ;
F_104 ( V_252 ) ;
F_104 ( V_253 ) ;
F_104 ( V_254 ) ;
F_104 ( V_255 ) ;
F_104 ( V_256 ) ;
F_104 ( V_257 ) ;
F_104 ( V_258 ) ;
F_104 ( V_259 ) ;
F_104 ( V_260 ) ;
F_104 ( V_77 ) ;
#undef F_104
}
