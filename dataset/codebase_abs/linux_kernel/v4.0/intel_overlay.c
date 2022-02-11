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
F_13 ( V_6 ) ;
F_10 ( & V_3 -> V_19 , NULL ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
int V_18 ;
F_9 ( V_3 -> V_22 ) ;
V_3 -> V_22 = 1 ;
F_15 ( F_16 ( V_6 ) && ! ( V_5 -> V_23 & V_24 ) ) ;
V_18 = F_17 ( V_16 , 4 ) ;
if ( V_18 )
return V_18 ;
F_18 ( V_16 , V_25 | V_26 ) ;
F_18 ( V_16 , V_3 -> V_27 | V_28 ) ;
F_18 ( V_16 , V_29 | V_30 ) ;
F_18 ( V_16 , V_31 ) ;
F_19 ( V_16 ) ;
return F_7 ( V_3 , NULL ) ;
}
static int F_20 ( struct V_2 * V_3 ,
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
V_33 = F_21 ( V_34 ) ;
if ( V_33 & ( 1 << 17 ) )
F_22 ( L_1 , V_33 ) ;
V_18 = F_17 ( V_16 , 2 ) ;
if ( V_18 )
return V_18 ;
F_18 ( V_16 , V_25 | V_35 ) ;
F_18 ( V_16 , V_27 ) ;
F_19 ( V_16 ) ;
F_15 ( V_3 -> V_19 ) ;
F_10 ( & V_3 -> V_19 ,
V_16 -> V_20 ) ;
return F_11 ( V_16 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_38 ;
F_24 ( V_37 ) ;
F_25 ( & V_37 -> V_39 ) ;
V_3 -> V_38 = NULL ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_40 ;
F_9 ( ! V_3 -> V_40 ) ;
F_24 ( V_37 ) ;
F_25 ( & V_37 -> V_39 ) ;
V_3 -> V_40 = NULL ;
V_3 -> V_41 -> V_3 = NULL ;
V_3 -> V_41 = NULL ;
V_3 -> V_22 = 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
T_2 V_27 = V_3 -> V_27 ;
int V_18 ;
F_9 ( ! V_3 -> V_22 ) ;
V_27 |= V_28 ;
V_18 = F_17 ( V_16 , 6 ) ;
if ( V_18 )
return V_18 ;
F_18 ( V_16 , V_25 | V_35 ) ;
F_18 ( V_16 , V_27 ) ;
F_18 ( V_16 , V_29 | V_30 ) ;
if ( F_16 ( V_6 ) ) {
F_18 ( V_16 , V_31 ) ;
F_18 ( V_16 , V_31 ) ;
F_18 ( V_16 , V_31 ) ;
} else {
F_18 ( V_16 , V_25 | V_42 ) ;
F_18 ( V_16 , V_27 ) ;
F_18 ( V_16 , V_29 | V_30 ) ;
}
F_19 ( V_16 ) ;
return F_7 ( V_3 , F_26 ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
int V_18 ;
if ( V_3 -> V_19 == NULL )
return 0 ;
V_18 = F_12 ( V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
F_13 ( V_3 -> V_6 ) ;
if ( V_3 -> V_21 )
V_3 -> V_21 ( V_3 ) ;
F_10 ( & V_3 -> V_19 , NULL ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_15 * V_16 = & V_5 -> V_16 [ V_17 ] ;
int V_18 ;
F_15 ( ! F_30 ( & V_6 -> V_43 ) ) ;
if ( ! V_3 -> V_38 )
return 0 ;
if ( F_21 ( V_44 ) & V_45 ) {
V_18 = F_17 ( V_16 , 2 ) ;
if ( V_18 )
return V_18 ;
F_18 ( V_16 , V_29 | V_30 ) ;
F_18 ( V_16 , V_31 ) ;
F_19 ( V_16 ) ;
V_18 = F_7 ( V_3 ,
F_23 ) ;
if ( V_18 )
return V_18 ;
}
F_23 ( V_3 ) ;
F_31 ( V_3 -> V_38 , NULL ,
F_32 ( V_3 -> V_41 -> V_46 ) ) ;
return 0 ;
}
void F_33 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
F_29 ( V_3 ) ;
V_3 -> V_19 = NULL ;
V_3 -> V_47 = 0 ;
V_3 -> V_48 = 0 ;
V_3 -> V_41 = NULL ;
V_3 -> V_22 = false ;
}
static int F_34 ( T_2 V_49 )
{
switch ( V_49 & V_50 ) {
case V_51 :
return 4 ;
case V_52 :
default:
return - V_53 ;
}
}
static int F_35 ( T_2 V_49 , short V_54 )
{
switch ( V_49 & V_50 ) {
case V_51 :
return V_54 << 1 ;
default:
return - V_53 ;
}
}
static int F_36 ( T_2 V_49 )
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
static int F_37 ( T_2 V_49 )
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
static T_2 F_38 ( struct V_14 * V_6 , T_2 V_57 , T_2 V_54 )
{
T_2 V_58 , V_59 , V_18 ;
if ( F_39 ( V_6 ) ) {
V_58 = 0x1f ;
V_59 = 5 ;
} else {
V_58 = 0x3f ;
V_59 = 6 ;
}
V_18 = ( ( V_57 + V_54 + V_58 ) >> V_59 ) - ( V_57 >> V_59 ) ;
if ( ! F_39 ( V_6 ) )
V_18 <<= 1 ;
V_18 -= 1 ;
return V_18 << 2 ;
}
static void F_40 ( struct V_1 T_1 * V_8 )
{
F_41 ( V_8 -> V_60 , V_61 , sizeof( V_61 ) ) ;
F_41 ( V_8 -> V_62 , V_63 ,
sizeof( V_63 ) ) ;
}
static bool F_42 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 ,
struct V_64 * V_65 )
{
T_2 V_66 , V_67 , V_68 , V_69 ;
#define F_43 12
#define F_44 0xfff
bool V_70 = false ;
int V_71 = F_36 ( V_65 -> V_49 ) ;
int V_72 = F_37 ( V_65 -> V_49 ) ;
if ( V_65 -> V_73 > 1 )
V_66 = ( ( V_65 -> V_74 - 1 ) << F_43 )
/ ( V_65 -> V_73 ) ;
else
V_66 = 1 << F_43 ;
if ( V_65 -> V_75 > 1 )
V_67 = ( ( V_65 -> V_76 - 1 ) << F_43 )
/ ( V_65 -> V_75 ) ;
else
V_67 = 1 << F_43 ;
V_68 = V_66 / V_71 ;
V_69 = V_67 / V_72 ;
V_66 = V_68 * V_71 ;
V_67 = V_69 * V_72 ;
if ( V_66 != V_3 -> V_47 || V_67 != V_3 -> V_48 )
V_70 = true ;
V_3 -> V_47 = V_66 ;
V_3 -> V_48 = V_67 ;
F_45 ( ( ( V_67 & F_44 ) << 20 ) |
( ( V_66 >> F_43 ) << 16 ) |
( ( V_66 & F_44 ) << 3 ) ,
& V_8 -> V_77 ) ;
F_45 ( ( ( V_69 & F_44 ) << 20 ) |
( ( V_68 >> F_43 ) << 16 ) |
( ( V_68 & F_44 ) << 3 ) ,
& V_8 -> V_78 ) ;
F_45 ( ( ( ( V_67 >> F_43 ) << 16 ) |
( ( V_69 >> F_43 ) << 0 ) ) ,
& V_8 -> V_79 ) ;
if ( V_70 )
F_40 ( V_8 ) ;
return V_70 ;
}
static void F_46 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
T_2 V_80 = V_3 -> V_81 ;
switch ( V_3 -> V_41 -> V_39 . V_82 -> V_83 -> V_84 ) {
case 8 :
F_45 ( 0 , & V_8 -> V_85 ) ;
F_45 ( V_86 | V_87 , & V_8 -> V_88 ) ;
break;
case 16 :
if ( V_3 -> V_41 -> V_39 . V_82 -> V_83 -> V_89 == 15 ) {
F_45 ( F_47 ( V_80 ) , & V_8 -> V_85 ) ;
F_45 ( V_90 | V_87 ,
& V_8 -> V_88 ) ;
} else {
F_45 ( F_48 ( V_80 ) , & V_8 -> V_85 ) ;
F_45 ( V_91 | V_87 ,
& V_8 -> V_88 ) ;
}
break;
case 24 :
case 32 :
F_45 ( V_80 , & V_8 -> V_85 ) ;
F_45 ( V_92 | V_87 , & V_8 -> V_88 ) ;
break;
}
}
static T_2 F_49 ( struct V_64 * V_65 )
{
T_2 V_93 = V_94 | V_95 | V_96 ;
if ( V_65 -> V_49 & V_97 ) {
switch ( V_65 -> V_49 & V_50 ) {
case V_51 :
V_93 |= V_98 ;
break;
case V_55 :
V_93 |= V_99 ;
break;
case V_52 :
case V_56 :
V_93 |= V_100 ;
break;
}
} else {
switch ( V_65 -> V_49 & V_50 ) {
case V_51 :
V_93 |= V_101 ;
break;
case V_52 :
V_93 |= V_102 ;
break;
}
switch ( V_65 -> V_49 & V_103 ) {
case V_104 :
break;
case V_105 :
V_93 |= V_106 ;
break;
case V_107 :
V_93 |= V_108 ;
break;
case V_109 :
V_93 |= V_110 ;
break;
}
}
return V_93 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_36 * V_111 ,
struct V_64 * V_65 )
{
int V_18 , V_112 ;
struct V_1 T_1 * V_8 ;
bool V_70 = false ;
struct V_14 * V_6 = V_3 -> V_6 ;
T_2 V_113 , V_114 , V_115 , V_116 ;
enum V_46 V_46 = V_3 -> V_41 -> V_46 ;
F_9 ( ! F_30 ( & V_6 -> V_43 ) ) ;
F_9 ( ! F_51 ( & V_6 -> V_117 . V_118 ) ) ;
F_9 ( ! V_3 ) ;
V_18 = F_29 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_52 ( V_111 , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_53 ( V_111 ) ;
if ( V_18 )
goto V_119;
if ( ! V_3 -> V_22 ) {
T_2 V_120 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_121 ;
goto V_119;
}
V_120 = V_122 ;
if ( F_54 ( V_3 -> V_6 ) )
V_120 |= V_123 ;
V_120 |= V_46 == 0 ?
V_124 : V_125 ;
F_45 ( V_120 , & V_8 -> V_126 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_14 ( V_3 ) ;
if ( V_18 != 0 )
goto V_119;
}
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_121 ;
goto V_119;
}
F_45 ( ( V_65 -> V_127 << 16 ) | V_65 -> V_128 , & V_8 -> V_129 ) ;
F_45 ( ( V_65 -> V_75 << 16 ) | V_65 -> V_73 , & V_8 -> V_130 ) ;
if ( V_65 -> V_49 & V_131 )
V_112 = F_35 ( V_65 -> V_49 , V_65 -> V_132 ) ;
else
V_112 = V_65 -> V_132 ;
V_113 = V_65 -> V_132 ;
V_114 = F_38 ( V_3 -> V_6 , V_65 -> V_133 , V_112 ) ;
V_115 = V_65 -> V_134 ;
F_45 ( F_4 ( V_111 ) + V_65 -> V_133 , & V_8 -> V_135 ) ;
V_116 = V_65 -> V_136 ;
if ( V_65 -> V_49 & V_97 ) {
int V_71 = F_36 ( V_65 -> V_49 ) ;
int V_72 = F_37 ( V_65 -> V_49 ) ;
T_2 V_137 , V_138 ;
V_113 |= ( V_65 -> V_132 / V_71 ) << 16 ;
V_137 = F_38 ( V_3 -> V_6 , V_65 -> V_139 ,
V_65 -> V_132 / V_71 ) ;
V_138 = F_38 ( V_3 -> V_6 , V_65 -> V_140 ,
V_65 -> V_132 / V_71 ) ;
V_114 |= F_55 ( T_2 , V_137 , V_138 ) << 16 ;
V_115 |= ( V_65 -> V_134 / V_72 ) << 16 ;
F_45 ( F_4 ( V_111 ) + V_65 -> V_139 , & V_8 -> V_141 ) ;
F_45 ( F_4 ( V_111 ) + V_65 -> V_140 , & V_8 -> V_142 ) ;
V_116 |= V_65 -> V_143 << 16 ;
}
F_45 ( V_113 , & V_8 -> V_144 ) ;
F_45 ( V_114 , & V_8 -> V_145 ) ;
F_45 ( V_115 , & V_8 -> V_146 ) ;
F_45 ( V_116 , & V_8 -> V_147 ) ;
V_70 = F_42 ( V_3 , V_8 , V_65 ) ;
F_46 ( V_3 , V_8 ) ;
F_45 ( F_49 ( V_65 ) , & V_8 -> V_148 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_20 ( V_3 , V_70 ) ;
if ( V_18 )
goto V_119;
F_31 ( V_3 -> V_40 , V_111 ,
F_32 ( V_46 ) ) ;
V_3 -> V_38 = V_3 -> V_40 ;
V_3 -> V_40 = V_111 ;
F_56 ( V_6 ,
F_32 ( V_46 ) ) ;
return 0 ;
V_119:
F_24 ( V_111 ) ;
return V_18 ;
}
int F_57 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_8 ;
struct V_14 * V_6 = V_3 -> V_6 ;
int V_18 ;
F_9 ( ! F_30 ( & V_6 -> V_43 ) ) ;
F_9 ( ! F_51 ( & V_6 -> V_117 . V_118 ) ) ;
V_18 = F_28 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( ! V_3 -> V_22 )
return 0 ;
V_18 = F_29 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_8 = F_1 ( V_3 ) ;
F_45 ( 0 , & V_8 -> V_148 ) ;
F_5 ( V_3 , V_8 ) ;
V_18 = F_27 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
F_26 ( V_3 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_149 * V_41 )
{
if ( ! V_41 -> V_22 )
return - V_53 ;
if ( V_41 -> V_150 -> V_151 )
return - V_53 ;
return 0 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_14 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_152 = F_21 ( V_153 ) ;
T_2 V_154 ;
if ( F_60 ( V_6 ) -> V_155 >= 4 ) {
V_154 = F_21 ( V_156 ) >> V_157 ;
} else {
if ( V_152 & V_158 )
V_154 = F_21 ( V_159 ) ;
else
V_154 = F_21 ( V_156 ) ;
V_154 >>= V_160 ;
}
V_3 -> V_161 = V_154 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 = & V_3 -> V_41 -> V_39 . V_165 ;
if ( V_163 -> V_128 < V_165 -> V_166 &&
V_163 -> V_128 + V_163 -> V_167 <= V_165 -> V_166 &&
V_163 -> V_127 < V_165 -> V_168 &&
V_163 -> V_127 + V_163 -> V_169 <= V_165 -> V_168 )
return 0 ;
else
return - V_53 ;
}
static int F_62 ( struct V_64 * V_163 )
{
T_2 V_33 ;
V_33 = ( ( V_163 -> V_76 << 16 ) / V_163 -> V_75 ) >> 16 ;
if ( V_33 > 7 )
return - V_53 ;
V_33 = ( ( V_163 -> V_74 << 16 ) / V_163 -> V_73 ) >> 16 ;
if ( V_33 > 7 )
return - V_53 ;
return 0 ;
}
static int F_63 ( struct V_14 * V_6 ,
struct V_162 * V_163 ,
struct V_36 * V_111 )
{
int V_71 = F_36 ( V_163 -> V_170 ) ;
int V_72 = F_37 ( V_163 -> V_170 ) ;
T_2 V_171 ;
int V_89 ;
T_2 V_33 ;
if ( F_64 ( V_6 ) || F_16 ( V_6 ) ) {
if ( V_163 -> V_172 > V_173 ||
V_163 -> V_174 > V_175 )
return - V_53 ;
} else {
if ( V_163 -> V_172 > V_176 ||
V_163 -> V_174 > V_177 )
return - V_53 ;
}
if ( V_163 -> V_172 < V_178 * 4 ||
V_163 -> V_174 < V_179 * 4 )
return - V_53 ;
switch ( V_163 -> V_170 & V_180 ) {
case V_181 :
return - V_53 ;
case V_131 :
if ( V_72 != 1 )
return - V_53 ;
V_89 = F_34 ( V_163 -> V_170 ) ;
if ( V_89 < 0 )
return V_89 ;
V_163 -> V_143 = 0 ;
V_163 -> V_139 = 0 ;
V_163 -> V_140 = 0 ;
if ( V_163 -> V_133 % V_89 )
return - V_53 ;
break;
case V_97 :
if ( V_72 < 0 || V_71 < 0 )
return - V_53 ;
break;
default:
return - V_53 ;
}
if ( V_163 -> V_174 % V_71 )
return - V_53 ;
if ( F_16 ( V_6 ) || F_64 ( V_6 ) )
V_171 = 255 ;
else
V_171 = 63 ;
if ( V_163 -> V_136 & V_171 || V_163 -> V_143 & V_171 )
return - V_53 ;
if ( F_54 ( V_6 ) && V_163 -> V_136 < 512 )
return - V_53 ;
V_33 = ( V_163 -> V_170 & V_180 ) == V_97 ?
4096 : 8192 ;
if ( V_163 -> V_136 > V_33 || V_163 -> V_143 > 2 * 1024 )
return - V_53 ;
switch ( V_163 -> V_170 & V_180 ) {
case V_181 :
case V_131 :
if ( F_35 ( V_163 -> V_170 , V_163 -> V_174 ) > V_163 -> V_136 )
return - V_53 ;
V_33 = V_163 -> V_136 * V_163 -> V_172 ;
if ( V_163 -> V_133 + V_33 > V_111 -> V_39 . V_182 )
return - V_53 ;
break;
case V_97 :
if ( V_163 -> V_174 > V_163 -> V_136 )
return - V_53 ;
if ( V_163 -> V_174 / V_71 > V_163 -> V_143 )
return - V_53 ;
V_33 = V_163 -> V_136 * V_163 -> V_172 ;
if ( V_163 -> V_133 + V_33 > V_111 -> V_39 . V_182 )
return - V_53 ;
V_33 = V_163 -> V_143 * ( V_163 -> V_172 / V_72 ) ;
if ( V_163 -> V_139 + V_33 > V_111 -> V_39 . V_182 ||
V_163 -> V_140 + V_33 > V_111 -> V_39 . V_182 )
return - V_53 ;
break;
}
return 0 ;
}
static int F_65 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_152 ;
if ( F_60 ( V_6 ) -> V_155 <= 3 && ( F_16 ( V_6 ) || ! F_66 ( V_6 ) ) )
return - 1 ;
V_152 = F_21 ( V_153 ) ;
if ( ( V_152 & V_183 ) == 0 )
return - 1 ;
if ( F_54 ( V_6 ) )
return ( V_152 >> 29 ) & 0x3 ;
return 1 ;
}
int F_67 ( struct V_14 * V_6 , void * V_184 ,
struct V_185 * V_186 )
{
struct V_162 * V_187 = V_184 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_188 * V_189 ;
struct V_149 * V_41 ;
struct V_36 * V_111 ;
struct V_64 * V_65 ;
int V_18 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_22 ( L_2 ) ;
return - V_190 ;
}
if ( ! ( V_187 -> V_170 & V_191 ) ) {
F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_43 ) ;
V_18 = F_57 ( V_3 ) ;
F_70 ( & V_6 -> V_43 ) ;
F_71 ( V_6 ) ;
return V_18 ;
}
V_65 = F_72 ( sizeof( * V_65 ) , V_192 ) ;
if ( ! V_65 )
return - V_121 ;
V_189 = F_73 ( V_6 , V_187 -> V_193 ) ;
if ( ! V_189 ) {
V_18 = - V_194 ;
goto V_195;
}
V_41 = F_74 ( V_189 ) ;
V_111 = F_75 ( F_76 ( V_6 , V_186 ,
V_187 -> V_196 ) ) ;
if ( & V_111 -> V_39 == NULL ) {
V_18 = - V_194 ;
goto V_195;
}
F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_43 ) ;
if ( V_111 -> V_197 ) {
F_77 ( L_3 ) ;
V_18 = - V_53 ;
goto V_198;
}
V_18 = F_28 ( V_3 ) ;
if ( V_18 != 0 )
goto V_198;
if ( V_3 -> V_41 != V_41 ) {
struct V_164 * V_165 = & V_41 -> V_39 . V_165 ;
V_18 = F_57 ( V_3 ) ;
if ( V_18 != 0 )
goto V_198;
V_18 = F_58 ( V_3 , V_41 ) ;
if ( V_18 != 0 )
goto V_198;
V_3 -> V_41 = V_41 ;
V_41 -> V_3 = V_3 ;
if ( V_165 -> V_166 > 1024 &&
F_65 ( V_6 ) == V_41 -> V_46 ) {
V_3 -> V_199 = 1 ;
F_59 ( V_3 ) ;
} else
V_3 -> V_199 = 0 ;
}
V_18 = F_61 ( V_3 , V_187 ) ;
if ( V_18 != 0 )
goto V_198;
if ( V_3 -> V_199 ) {
V_65 -> V_127 = ( ( ( ( T_2 ) V_187 -> V_127 ) << 12 ) /
V_3 -> V_161 ) ;
V_65 -> V_75 = ( ( ( ( T_2 ) V_187 -> V_169 ) << 12 ) /
V_3 -> V_161 ) + 1 ;
} else {
V_65 -> V_127 = V_187 -> V_127 ;
V_65 -> V_75 = V_187 -> V_169 ;
}
V_65 -> V_128 = V_187 -> V_128 ;
V_65 -> V_73 = V_187 -> V_167 ;
V_65 -> V_132 = V_187 -> V_174 ;
V_65 -> V_134 = V_187 -> V_172 ;
V_65 -> V_74 = V_187 -> V_200 ;
V_65 -> V_76 = V_187 -> V_201 ;
if ( V_65 -> V_76 > V_65 -> V_134 ||
V_65 -> V_74 > V_65 -> V_132 ) {
V_18 = - V_53 ;
goto V_198;
}
V_18 = F_63 ( V_6 , V_187 , V_111 ) ;
if ( V_18 != 0 )
goto V_198;
V_65 -> V_49 = V_187 -> V_170 & ~ V_202 ;
V_65 -> V_136 = V_187 -> V_136 ;
V_65 -> V_143 = V_187 -> V_143 ;
V_65 -> V_133 = V_187 -> V_133 ;
V_65 -> V_139 = V_187 -> V_139 ;
V_65 -> V_140 = V_187 -> V_140 ;
V_18 = F_62 ( V_65 ) ;
if ( V_18 != 0 )
goto V_198;
V_18 = F_50 ( V_3 , V_111 , V_65 ) ;
if ( V_18 != 0 )
goto V_198;
F_70 ( & V_6 -> V_43 ) ;
F_71 ( V_6 ) ;
F_78 ( V_65 ) ;
return 0 ;
V_198:
F_70 ( & V_6 -> V_43 ) ;
F_71 ( V_6 ) ;
F_79 ( & V_111 -> V_39 ) ;
V_195:
F_78 ( V_65 ) ;
return V_18 ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
F_45 ( ( V_3 -> V_203 << 18 ) | ( V_3 -> V_204 & 0xff ) ,
& V_8 -> V_205 ) ;
F_45 ( V_3 -> V_206 , & V_8 -> V_207 ) ;
}
static bool F_81 ( T_2 V_208 , T_2 V_209 )
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
static bool F_82 ( T_2 V_211 )
{
int V_210 ;
for ( V_210 = 0 ; V_210 < 3 ; V_210 ++ ) {
if ( ( ( V_211 >> V_210 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_83 ( struct V_212 * V_213 )
{
if ( ! F_81 ( 0 , V_213 -> V_214 ) ||
! F_81 ( V_213 -> V_214 , V_213 -> V_208 ) ||
! F_81 ( V_213 -> V_208 , V_213 -> V_209 ) ||
! F_81 ( V_213 -> V_209 , V_213 -> V_215 ) ||
! F_81 ( V_213 -> V_215 , V_213 -> V_216 ) ||
! F_81 ( V_213 -> V_216 , V_213 -> V_211 ) ||
! F_81 ( V_213 -> V_211 , 0x00ffffff ) )
return - V_53 ;
if ( ! F_82 ( V_213 -> V_211 ) )
return - V_53 ;
return 0 ;
}
int F_84 ( struct V_14 * V_6 , void * V_184 ,
struct V_185 * V_186 )
{
struct V_212 * V_213 = V_184 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_8 ;
int V_18 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_22 ( L_2 ) ;
return - V_190 ;
}
F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_43 ) ;
V_18 = - V_53 ;
if ( ! ( V_213 -> V_170 & V_217 ) ) {
V_213 -> V_81 = V_3 -> V_81 ;
V_213 -> V_204 = V_3 -> V_204 ;
V_213 -> V_203 = V_3 -> V_203 ;
V_213 -> V_206 = V_3 -> V_206 ;
if ( ! F_39 ( V_6 ) ) {
V_213 -> V_214 = F_21 ( V_218 ) ;
V_213 -> V_208 = F_21 ( V_219 ) ;
V_213 -> V_209 = F_21 ( V_220 ) ;
V_213 -> V_215 = F_21 ( V_221 ) ;
V_213 -> V_216 = F_21 ( V_222 ) ;
V_213 -> V_211 = F_21 ( V_223 ) ;
}
} else {
if ( V_213 -> V_204 < - 128 || V_213 -> V_204 > 127 )
goto V_198;
if ( V_213 -> V_203 > 255 )
goto V_198;
if ( V_213 -> V_206 > 1023 )
goto V_198;
V_3 -> V_81 = V_213 -> V_81 ;
V_3 -> V_204 = V_213 -> V_204 ;
V_3 -> V_203 = V_213 -> V_203 ;
V_3 -> V_206 = V_213 -> V_206 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_18 = - V_121 ;
goto V_198;
}
F_80 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
if ( V_213 -> V_170 & V_224 ) {
if ( F_39 ( V_6 ) )
goto V_198;
if ( V_3 -> V_22 ) {
V_18 = - V_225 ;
goto V_198;
}
V_18 = F_83 ( V_213 ) ;
if ( V_18 )
goto V_198;
F_85 ( V_218 , V_213 -> V_214 ) ;
F_85 ( V_219 , V_213 -> V_208 ) ;
F_85 ( V_220 , V_213 -> V_209 ) ;
F_85 ( V_221 , V_213 -> V_215 ) ;
F_85 ( V_222 , V_213 -> V_216 ) ;
F_85 ( V_223 , V_213 -> V_211 ) ;
}
}
V_18 = 0 ;
V_198:
F_70 ( & V_6 -> V_43 ) ;
F_71 ( V_6 ) ;
return V_18 ;
}
void F_86 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_36 * V_9 ;
struct V_1 T_1 * V_8 ;
int V_18 ;
if ( ! F_87 ( V_6 ) )
return;
V_3 = F_88 ( sizeof( * V_3 ) , V_192 ) ;
if ( ! V_3 )
return;
F_69 ( & V_6 -> V_43 ) ;
if ( F_15 ( V_5 -> V_3 ) )
goto V_195;
V_3 -> V_6 = V_6 ;
V_9 = NULL ;
if ( ! F_2 ( V_6 ) )
V_9 = F_89 ( V_6 , V_226 ) ;
if ( V_9 == NULL )
V_9 = F_90 ( V_6 , V_226 ) ;
if ( V_9 == NULL )
goto V_195;
V_3 -> V_9 = V_9 ;
if ( F_2 ( V_6 ) ) {
V_18 = F_91 ( V_9 , V_226 ) ;
if ( V_18 ) {
F_92 ( L_4 ) ;
goto V_227;
}
V_3 -> V_27 = V_9 -> V_10 -> V_228 ;
} else {
V_18 = F_93 ( V_9 , V_226 , V_229 ) ;
if ( V_18 ) {
F_92 ( L_5 ) ;
goto V_227;
}
V_3 -> V_27 = F_4 ( V_9 ) ;
V_18 = F_94 ( V_9 , true ) ;
if ( V_18 ) {
F_92 ( L_6 ) ;
goto V_230;
}
}
V_3 -> V_81 = 0x0101fe ;
V_3 -> V_204 = - 19 ;
V_3 -> V_203 = 75 ;
V_3 -> V_206 = 146 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
goto V_230;
F_95 ( V_8 , 0 , sizeof( struct V_1 ) ) ;
F_40 ( V_8 ) ;
F_80 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
V_5 -> V_3 = V_3 ;
F_70 ( & V_6 -> V_43 ) ;
F_96 ( L_7 ) ;
return;
V_230:
if ( ! F_2 ( V_6 ) )
F_24 ( V_9 ) ;
V_227:
F_25 ( & V_9 -> V_39 ) ;
V_195:
F_70 ( & V_6 -> V_43 ) ;
F_78 ( V_3 ) ;
return;
}
void F_97 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
if ( ! V_5 -> V_3 )
return;
F_9 ( V_5 -> V_3 -> V_22 ) ;
F_79 ( & V_5 -> V_3 -> V_9 -> V_39 ) ;
F_78 ( V_5 -> V_3 ) ;
}
static struct V_1 T_1 *
F_98 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_1 T_1 * V_8 ;
if ( F_2 ( V_3 -> V_6 ) )
V_8 = (struct V_1 T_1 * )
V_3 -> V_9 -> V_10 -> V_11 ;
else
V_8 = F_99 ( V_5 -> V_12 . V_13 ,
F_4 ( V_3 -> V_9 ) ) ;
return V_8 ;
}
static void F_100 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_101 ( V_8 ) ;
}
struct V_231 *
F_102 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_231 * error ;
struct V_1 T_1 * V_8 ;
if ( ! V_3 || ! V_3 -> V_22 )
return NULL ;
error = F_72 ( sizeof( * error ) , V_232 ) ;
if ( error == NULL )
return NULL ;
error -> V_233 = F_21 ( V_34 ) ;
error -> V_234 = F_21 ( V_44 ) ;
if ( F_2 ( V_3 -> V_6 ) )
error -> V_39 = ( V_235 long ) V_3 -> V_9 -> V_10 -> V_11 ;
else
error -> V_39 = F_4 ( V_3 -> V_9 ) ;
V_8 = F_98 ( V_3 ) ;
if ( ! V_8 )
goto V_236;
F_103 ( & error -> V_8 , V_8 , sizeof( struct V_1 ) ) ;
F_100 ( V_3 , V_8 ) ;
return error ;
V_236:
F_78 ( error ) ;
return NULL ;
}
void
F_104 ( struct V_237 * V_238 ,
struct V_231 * error )
{
F_105 ( V_238 , L_8 ,
error -> V_233 , error -> V_234 ) ;
F_105 ( V_238 , L_9 ,
error -> V_39 ) ;
#define F_106 ( T_3 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_106 ( V_135 ) ;
F_106 ( V_239 ) ;
F_106 ( V_141 ) ;
F_106 ( V_142 ) ;
F_106 ( V_240 ) ;
F_106 ( V_241 ) ;
F_106 ( V_147 ) ;
F_106 ( V_242 ) ;
F_106 ( V_243 ) ;
F_106 ( V_244 ) ;
F_106 ( V_245 ) ;
F_106 ( V_129 ) ;
F_106 ( V_130 ) ;
F_106 ( V_144 ) ;
F_106 ( V_145 ) ;
F_106 ( V_146 ) ;
F_106 ( V_77 ) ;
F_106 ( V_78 ) ;
F_106 ( V_205 ) ;
F_106 ( V_207 ) ;
F_106 ( V_85 ) ;
F_106 ( V_88 ) ;
F_106 ( V_246 ) ;
F_106 ( V_247 ) ;
F_106 ( V_248 ) ;
F_106 ( V_126 ) ;
F_106 ( V_148 ) ;
F_106 ( V_249 ) ;
F_106 ( V_250 ) ;
F_106 ( V_251 ) ;
F_106 ( V_252 ) ;
F_106 ( V_253 ) ;
F_106 ( V_254 ) ;
F_106 ( V_255 ) ;
F_106 ( V_256 ) ;
F_106 ( V_257 ) ;
F_106 ( V_258 ) ;
F_106 ( V_259 ) ;
F_106 ( V_260 ) ;
F_106 ( V_261 ) ;
F_106 ( V_79 ) ;
#undef F_106
}
