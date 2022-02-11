static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_3 , T_2 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_3 F_9 ( struct V_1 * V_2 , int V_3 )
{
return F_10 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , int V_3 , T_3 V_5 )
{
F_12 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline int F_13 ( struct V_1 * V_2 , int V_6 ,
T_3 * V_7 )
{
int V_8 ;
T_3 V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_10 ;
V_8 = F_14 ( V_11 , V_9 + V_12 , V_6 ) ;
if ( V_8 )
return V_8 ;
return F_15 ( V_11 , V_9 + V_13 , V_7 ) ;
}
static void F_16 ( unsigned long V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_17 ( 0 , V_2 ) ;
F_18 ( & V_2 -> V_15 ) ;
if ( ! V_16 )
V_16 = 2 ;
F_19 ( V_2 , V_16 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_17 )
{
if ( ( V_17 <= 0 ) || ( V_17 > 60 ) )
V_17 = 2 ;
V_2 -> V_15 . V_18 = & F_16 ;
V_2 -> V_15 . V_14 = ( unsigned long ) V_2 ;
V_2 -> V_15 . V_19 = V_20 + V_17 * V_21 ;
F_20 ( & V_2 -> V_15 ) ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
T_2 V_22 = F_5 ( V_2 , V_23 ) ;
return V_22 & 0x1 ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
int V_24 ;
if ( ! F_21 ( V_2 ) )
return 1 ;
for ( V_24 = 0 ; V_24 < 10 ; V_24 ++ ) {
F_23 ( 100 ) ;
if ( ! F_21 ( V_2 ) )
return 1 ;
}
return 0 ;
}
static inline int F_24 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
unsigned long V_26 = F_25 ( 1000 ) ;
int V_8 ;
if ( V_27 )
V_8 = F_22 ( V_2 ) ;
else
V_8 = F_26 ( V_2 -> V_28 ,
! F_21 ( V_2 ) , V_26 ) ;
if ( ! V_8 && F_21 ( V_2 ) ) {
V_25 = - V_29 ;
F_27 ( V_2 , L_1 ) ;
} else if ( V_8 < 0 ) {
V_25 = - V_30 ;
F_28 ( V_2 , L_2 ) ;
}
return V_25 ;
}
static int F_29 ( struct V_31 * V_31 , T_1 V_32 , T_1 V_33 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
T_2 V_22 ;
int V_25 = 0 ;
T_2 V_34 ;
F_30 ( & V_31 -> V_2 -> V_35 ) ;
if ( ! F_22 ( V_2 ) ) {
F_27 ( V_2 , L_3 ) ;
V_25 = - V_36 ;
goto V_37;
}
++ V_32 ;
V_34 = ( V_32 << 8 ) | ( V_33 & 0xFF ) ;
F_31 ( V_2 , L_4 , V_38 , V_32 , V_33 ) ;
F_7 ( V_2 , V_39 , V_34 ) ;
V_25 = F_24 ( V_31 -> V_2 ) ;
if ( V_25 )
goto V_37;
V_22 = F_32 ( V_31 -> V_2 ) ;
if ( V_22 ) {
F_27 ( V_2 , L_5 ,
V_33 , V_22 ) ;
V_25 = - V_29 ;
}
V_37:
F_33 ( & V_31 -> V_2 -> V_35 ) ;
return V_25 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
T_2 V_22 = F_5 ( V_2 , V_23 ) & 0x000F ;
switch ( V_22 >> 1 ) {
case 0 :
V_25 = 0 ;
break;
case 1 :
V_25 = V_40 ;
F_27 ( V_2 , L_6 ) ;
break;
case 2 :
V_25 = V_41 ;
F_27 ( V_2 , L_7 ) ;
break;
case 4 :
V_25 = V_42 ;
F_27 ( V_2 , L_8 ) ;
break;
default:
V_25 = V_22 ;
}
return V_25 ;
}
static int F_34 ( struct V_31 * V_31 , T_1 * V_43 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
T_3 V_44 = F_9 ( V_2 , F_35 ( V_31 -> V_45 ) ) ;
T_1 V_46 = ( V_44 & V_47 ) >> V_48 ;
switch ( V_46 ) {
case V_49 :
* V_43 = 1 ;
break;
case V_50 :
* V_43 = 2 ;
break;
case V_51 :
* V_43 = 0 ;
break;
default:
* V_43 = 0xFF ;
break;
}
return 0 ;
}
static int F_36 ( struct V_31 * V_31 , T_1 * V_43 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
T_3 V_44 = F_9 ( V_2 , F_35 ( V_31 -> V_45 ) ) ;
T_1 V_46 = ( V_44 & V_52 ) >> V_53 ;
switch ( V_46 ) {
case V_54 :
* V_43 = 2 ;
break;
case V_55 :
* V_43 = 1 ;
break;
case V_56 :
* V_43 = 0 ;
break;
default:
* V_43 = 0xFF ;
break;
}
return 0 ;
}
static int F_37 ( struct V_31 * V_31 , T_1 * V_43 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
T_3 V_44 = F_9 ( V_2 , F_35 ( V_31 -> V_45 ) ) ;
* V_43 = ! ! ( V_44 & V_57 ) ;
return 0 ;
}
static int F_38 ( struct V_31 * V_31 , T_1 * V_43 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
T_3 V_44 = F_9 ( V_2 , F_35 ( V_31 -> V_45 ) ) ;
T_1 V_46 = ( V_44 & V_58 ) >> V_59 ;
* V_43 = ( V_46 != 0x3 ) ? 1 : 0 ;
return 0 ;
}
static int F_39 ( struct V_31 * V_31 , T_1 * V_60 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
* V_60 = F_1 ( V_2 , V_61 ) ;
return 0 ;
}
static int F_40 ( struct V_31 * V_31 , enum V_62 * V_7 )
{
int V_25 = 0 ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_3 V_44 = F_9 ( V_2 , F_35 ( V_31 -> V_45 ) ) ;
T_1 V_63 = ! ! ( V_44 & V_64 ) ;
T_1 V_65 , V_66 ;
if ( ( V_25 = F_39 ( V_31 , & V_65 ) ) )
return V_25 ;
switch ( V_65 ) {
case 1 :
V_66 = ( V_44 & V_67 ) >> V_68 ;
break;
case 2 :
V_66 = ( V_44 & V_69 ) >> V_68 ;
break;
default:
return - V_70 ;
}
F_31 ( V_2 , L_9 ,
V_38 , V_44 , V_66 , V_63 ) ;
switch ( V_66 ) {
case 0x0 :
* V_7 = V_63 ? V_71 : V_72 ;
break;
case 0x1 :
* V_7 = V_73 ;
break;
case 0x3 :
* V_7 = V_74 ;
break;
case 0x4 :
* V_7 = V_75 ;
break;
case 0x5 :
* V_7 = V_76 ;
break;
case 0x2 :
default:
* V_7 = V_77 ;
V_25 = - V_70 ;
break;
}
F_31 ( V_2 , L_10 , * V_7 ) ;
return V_25 ;
}
static int F_41 ( struct V_31 * V_31 , T_1 * V_78 )
{
int V_25 = 0 ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_2 V_79 = F_5 ( V_2 , V_80 ) ;
T_1 V_65 = F_1 ( V_2 , V_61 ) ;
if ( V_65 == 2 ) {
* V_78 = ( V_79 & 0x0100 ) >> 8 ;
} else {
V_25 = - 1 ;
}
F_31 ( V_2 , L_11 , * V_78 ) ;
return V_25 ;
}
static int F_42 ( struct V_31 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
T_3 V_44 = F_9 ( V_2 , F_35 ( V_31 -> V_45 ) ) ;
return ! ( V_44 & V_81 ) ;
}
static int F_43 ( struct V_31 * V_31 , T_1 V_7 )
{
T_1 V_82 = 0 ;
switch ( V_7 ) {
case 0 :
V_82 = V_83 ;
break;
case 1 :
V_82 = V_84 ;
break;
case 2 :
V_82 = V_85 ;
break;
default:
return - 1 ;
}
return F_29 ( V_31 , V_31 -> V_45 , V_82 ) ;
}
static void F_44 ( struct V_31 * V_31 )
{
F_29 ( V_31 , V_31 -> V_45 , V_86 ) ;
}
static void F_45 ( struct V_31 * V_31 )
{
F_29 ( V_31 , V_31 -> V_45 , V_87 ) ;
}
static void F_46 ( struct V_31 * V_31 )
{
F_29 ( V_31 , V_31 -> V_45 , V_88 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_24 ;
T_3 V_44 , V_89 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_90 ; V_24 ++ ) {
V_44 = F_9 ( V_2 , F_35 ( V_24 ) ) ;
V_44 |= ( V_91 | V_92 |
V_93 | V_94 |
V_95 | V_96 |
V_97 ) ;
V_44 &= ~ V_98 ;
F_11 ( V_2 , F_35 ( V_24 ) , V_44 ) ;
}
F_48 ( V_2 ) ;
V_89 = F_9 ( V_2 , V_99 ) ;
V_89 |= ( V_100 | V_101 |
V_102 | V_103 ) ;
V_89 &= ~ V_104 ;
F_11 ( V_2 , V_99 , V_89 ) ;
if ( V_27 )
F_49 ( & V_2 -> V_15 ) ;
else {
F_50 ( V_2 -> V_10 -> V_105 , V_2 ) ;
F_51 ( V_2 -> V_10 ) ;
}
F_52 ( V_2 -> V_4 ) ;
F_53 ( V_2 -> V_106 , V_2 -> V_107 ) ;
}
static int F_54 ( struct V_31 * V_31 )
{
int V_25 ;
V_25 = F_29 ( V_31 , V_31 -> V_45 , V_108 ) ;
if ( V_25 )
F_27 ( V_31 -> V_2 , L_12 , V_38 ) ;
return V_25 ;
}
static int F_55 ( struct V_31 * V_31 )
{
int V_25 ;
V_25 = F_29 ( V_31 , V_31 -> V_45 ,
V_109 | V_88 | V_83 ) ;
if ( V_25 )
F_27 ( V_31 -> V_2 , L_12 , V_38 ) ;
return V_25 ;
}
static int F_56 ( struct V_31 * V_31 )
{
int V_25 ;
V_25 = F_29 ( V_31 , V_31 -> V_45 ,
V_110 | V_87 | V_84 ) ;
if ( V_25 )
F_27 ( V_31 -> V_2 , L_12 , V_38 ) ;
return V_25 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
struct V_111 * V_112 = V_2 -> V_10 -> V_113 ;
enum V_62 V_114 = V_77 ;
T_2 V_115 = F_5 ( V_2 , V_80 ) ;
T_1 V_65 = F_1 ( V_2 , V_61 ) ;
T_1 V_116 = ( V_65 == 2 ) ? ( V_115 & 0xF ) : ( V_115 & 0x7 ) ;
if ( ( V_65 == 1 ) && ( V_116 > 4 ) ) {
V_25 = - V_70 ;
goto V_37;
}
switch ( V_116 ) {
case 0x0 :
V_114 = V_72 ;
break;
case 0x1 :
V_114 = V_71 ;
break;
case 0x2 :
V_114 = V_73 ;
break;
case 0x3 :
V_114 = V_117 ;
break;
case 0x4 :
V_114 = V_74 ;
break;
case 0x5 :
V_114 = V_118 ;
break;
case 0x6 :
V_114 = V_119 ;
break;
case 0x7 :
V_114 = V_120 ;
break;
case 0x8 :
V_114 = V_121 ;
break;
case 0x9 :
V_114 = V_122 ;
break;
case 0xa :
V_114 = V_75 ;
break;
case 0xb :
V_114 = V_123 ;
break;
case 0xc :
V_114 = V_124 ;
break;
case 0xd :
V_114 = V_76 ;
break;
default:
V_25 = - V_70 ;
break;
}
V_37:
V_112 -> V_125 = V_114 ;
F_58 ( L_13 , V_114 ) ;
return V_25 ;
}
static int F_59 ( struct V_31 * V_31 , enum V_62 V_7 )
{
int V_25 ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_1 V_65 , V_33 ;
V_65 = F_1 ( V_2 , V_61 ) ;
if ( ( V_65 == 1 ) && ( V_7 > V_74 ) )
return - V_126 ;
switch ( V_7 ) {
case V_72 :
V_33 = V_127 ;
break;
case V_71 :
V_33 = V_128 ;
break;
case V_73 :
V_33 = V_129 ;
break;
case V_117 :
V_33 = V_130 ;
break;
case V_74 :
V_33 = V_131 ;
break;
case V_118 :
V_33 = V_132 ;
break;
case V_119 :
V_33 = V_133 ;
break;
case V_120 :
V_33 = V_134 ;
break;
case V_121 :
V_33 = V_135 ;
break;
case V_122 :
V_33 = V_136 ;
break;
case V_75 :
V_33 = V_137 ;
break;
case V_123 :
V_33 = V_138 ;
break;
case V_124 :
V_33 = V_139 ;
break;
case V_76 :
V_33 = V_140 ;
break;
default:
return - V_126 ;
}
V_25 = F_29 ( V_31 , 0 , V_33 ) ;
if ( V_25 )
F_27 ( V_2 , L_12 , V_38 ) ;
else
F_57 ( V_2 ) ;
return V_25 ;
}
static T_4 F_17 ( int V_105 , void * V_141 )
{
struct V_1 * V_2 = (struct V_1 * ) V_141 ;
T_3 V_89 , V_44 , V_142 , V_143 ;
int V_45 ;
V_142 = F_9 ( V_2 , V_144 ) ;
if ( ! V_142 )
return V_145 ;
F_31 ( V_2 , L_14 , V_38 , V_142 ) ;
if( ! V_27 ) {
V_89 = F_9 ( V_2 , V_99 ) ;
V_89 |= V_100 ;
V_89 &= ~ V_104 ;
F_11 ( V_2 , V_99 , V_89 ) ;
V_143 = F_9 ( V_2 , V_144 ) ;
F_31 ( V_2 , L_15 , V_38 , V_143 ) ;
}
if ( V_142 & V_146 ) {
V_89 = F_9 ( V_2 , V_99 ) ;
V_89 &= ~ V_104 ;
F_11 ( V_2 , V_99 , V_89 ) ;
F_60 ( & V_2 -> V_28 ) ;
}
if ( ! ( V_142 & ~ V_146 ) )
goto V_37;
for ( V_45 = 0 ; V_45 < V_2 -> V_90 ; V_45 ++ ) {
if ( ! ( V_142 & F_61 ( V_45 ) ) )
continue;
V_44 = F_9 ( V_2 , F_35 ( V_45 ) ) ;
F_31 ( V_2 , L_16 ,
V_45 , V_44 ) ;
if ( V_44 & V_147 )
F_62 ( V_45 , V_2 ) ;
if ( V_44 & V_148 )
F_63 ( V_45 , V_2 ) ;
if ( V_44 & V_149 )
F_64 ( V_45 , V_2 ) ;
if ( V_44 & ( V_150 | V_151 ) )
F_65 ( V_45 , V_2 ) ;
V_44 &= ~ V_98 ;
F_11 ( V_2 , F_35 ( V_45 ) , V_44 ) ;
}
V_37:
if ( ! V_27 ) {
V_89 = F_9 ( V_2 , V_99 ) ;
V_89 &= ~ ( V_100 | V_104 ) ;
F_11 ( V_2 , V_99 , V_89 ) ;
}
return V_152 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
struct V_111 * V_112 = V_2 -> V_10 -> V_113 ;
enum V_62 V_114 = V_77 ;
T_1 V_65 = F_1 ( V_2 , V_61 ) ;
T_3 V_153 = F_9 ( V_2 , V_154 ) ;
T_3 V_155 = F_9 ( V_2 , V_156 ) ;
if ( V_65 == 2 ) {
if ( V_155 & V_157 )
V_114 = V_76 ;
else if ( V_155 & V_158 )
V_114 = V_124 ;
else if ( V_155 & V_159 )
V_114 = V_123 ;
else if ( V_155 & V_160 )
V_114 = V_75 ;
else if ( V_155 & V_161 )
V_114 = V_122 ;
else if ( V_155 & V_162 )
V_114 = V_121 ;
}
if ( V_114 == V_77 ) {
if ( V_153 & V_163 )
V_114 = V_74 ;
else if ( V_153 & V_164 )
V_114 = V_117 ;
else if ( V_153 & V_165 )
V_114 = V_73 ;
else if ( V_155 & V_166 )
V_114 = V_71 ;
else if ( V_153 & V_167 )
V_114 = V_72 ;
else
V_25 = - V_70 ;
}
V_112 -> V_168 = V_114 ;
F_31 ( V_2 , L_17 , V_114 ) ;
return V_25 ;
}
int F_67 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_8 = - 1 , V_90 = 0 ;
T_1 V_45 ;
T_3 V_169 ;
T_3 V_170 , V_44 , V_171 ;
T_1 V_24 ;
V_2 -> V_10 = V_11 ;
F_31 ( V_2 , L_18 ) ;
if ( V_11 -> V_172 == V_173 &&
V_11 -> V_174 == V_175 ) {
V_2 -> V_106 = F_68 ( V_11 , 0 ) ;
V_2 -> V_107 = F_69 ( V_11 , 0 ) ;
} else {
V_2 -> V_9 = F_70 ( V_11 , V_176 ) ;
if ( ! V_2 -> V_9 ) {
F_27 ( V_2 , L_19 ) ;
goto abort;
}
F_31 ( V_2 , L_20 , V_2 -> V_9 ) ;
V_8 = F_13 ( V_2 , 0 , & V_169 ) ;
if ( V_8 ) {
F_27 ( V_2 , L_21 ) ;
goto abort;
}
V_8 = F_13 ( V_2 , 3 , & V_170 ) ;
if ( V_8 ) {
F_27 ( V_2 , L_22 ) ;
goto abort;
}
V_90 = V_170 & V_177 ;
F_31 ( V_2 , L_23 , V_90 ) ;
for ( V_24 = 0 ; V_24 < 9 + V_90 ; V_24 ++ ) {
V_8 = F_13 ( V_2 , V_24 , & V_170 ) ;
if ( V_8 ) {
F_27 ( V_2 , L_24 ,
V_24 ) ;
goto abort;
}
F_31 ( V_2 , L_25 , V_24 , V_170 ) ;
}
V_2 -> V_106 =
F_68 ( V_11 , 0 ) + V_169 ;
V_2 -> V_107 = 0x24 + 0x4 * V_90 ;
}
F_28 ( V_2 , L_26 ,
V_11 -> V_172 , V_11 -> V_174 , V_11 -> V_178 ,
V_11 -> V_179 ) ;
V_8 = F_71 ( V_11 ) ;
if ( V_8 ) {
F_27 ( V_2 , L_27 ) ;
goto abort;
}
if ( ! F_72 ( V_2 -> V_106 , V_2 -> V_107 , V_180 ) ) {
F_27 ( V_2 , L_28 ) ;
V_8 = - 1 ;
goto abort;
}
V_2 -> V_4 = F_73 ( V_2 -> V_106 , V_2 -> V_107 ) ;
if ( ! V_2 -> V_4 ) {
F_27 ( V_2 , L_29 ,
V_2 -> V_107 , V_2 -> V_106 ) ;
F_53 ( V_2 -> V_106 , V_2 -> V_107 ) ;
V_8 = - 1 ;
goto abort;
}
F_31 ( V_2 , L_30 , V_2 -> V_4 ) ;
F_74 ( & V_2 -> V_181 ) ;
F_74 ( & V_2 -> V_35 ) ;
F_75 ( & V_2 -> V_28 ) ;
V_2 -> V_182 = & V_183 ;
V_171 = F_9 ( V_2 , V_184 ) ;
V_2 -> V_185 = ( V_171 & V_186 ) >> 8 ;
V_2 -> V_90 = V_171 & V_177 ;
V_2 -> V_187 = ( V_171 & V_188 ) >> 16 ;
V_2 -> V_189 = ( ( V_171 & V_190 ) >> 29 ) ? 1 : - 1 ;
V_170 = F_9 ( V_2 , V_99 ) ;
F_31 ( V_2 , L_31 , V_170 ) ;
V_170 |= ( V_100 | V_101 |
V_102 | V_103 ) ;
V_170 &= ~ V_104 ;
F_11 ( V_2 , V_99 , V_170 ) ;
V_170 = F_9 ( V_2 , V_99 ) ;
F_31 ( V_2 , L_31 , V_170 ) ;
for ( V_45 = 0 ; V_45 < V_2 -> V_90 ; V_45 ++ ) {
V_44 = F_9 ( V_2 , F_35 ( V_45 ) ) ;
F_31 ( V_2 , L_32 ,
V_45 , V_44 ) ;
V_44 |= ( V_91 | V_92 |
V_93 | V_94 |
V_95 | V_96 |
V_97 ) ;
V_44 &= ~ V_98 ;
F_11 ( V_2 , F_35 ( V_45 ) , V_44 ) ;
}
if ( V_27 ) {
F_18 ( & V_2 -> V_15 ) ;
F_19 ( V_2 , 10 ) ;
} else {
V_8 = F_76 ( V_11 ) ;
if ( V_8 ) {
F_28 ( V_2 , L_33 ) ;
F_28 ( V_2 , L_34 ) ;
}
V_8 = F_77 ( V_2 -> V_10 -> V_105 , F_17 , V_191 ,
V_180 , ( void * ) V_2 ) ;
F_31 ( V_2 , L_35 ,
V_2 -> V_10 -> V_105 , V_8 ) ;
if ( V_8 ) {
F_27 ( V_2 , L_36 ,
V_2 -> V_10 -> V_105 ) ;
goto V_192;
}
}
F_31 ( V_2 , L_37 , F_78 ( V_11 ) , V_11 -> V_105 ) ;
F_66 ( V_2 ) ;
F_57 ( V_2 ) ;
for ( V_45 = 0 ; V_45 < V_2 -> V_90 ; V_45 ++ ) {
V_44 = F_9 ( V_2 , F_35 ( V_45 ) ) ;
F_31 ( V_2 , L_32 ,
V_45 , V_44 ) ;
V_44 &= ~ ( V_91 | V_92 |
V_93 | V_94 |
V_95 | V_98 ) ;
F_11 ( V_2 , F_35 ( V_45 ) , V_44 ) ;
}
if ( ! V_27 ) {
V_170 = F_9 ( V_2 , V_99 ) ;
V_170 &= ~ ( V_100 | V_102 |
V_104 ) ;
F_11 ( V_2 , V_99 , V_170 ) ;
V_170 = F_9 ( V_2 , V_99 ) ;
F_31 ( V_2 , L_31 , V_170 ) ;
}
return 0 ;
V_192:
F_52 ( V_2 -> V_4 ) ;
abort:
return V_8 ;
}
