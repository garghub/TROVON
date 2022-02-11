static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_11 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static T_1 F_4 ( int V_14 , void * V_15 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_17 -> V_21 ;
unsigned int V_22 , V_23 , V_24 ;
T_2 V_25 = V_26 ;
F_5 ( V_17 -> V_27 , V_8 , & V_23 ) ;
F_5 ( V_17 -> V_27 , V_9 , & V_22 ) ;
V_24 = V_22 & V_23 ;
if ( ! V_24 )
return V_28 ;
F_6 ( V_17 -> V_27 , V_10 , V_29 ,
V_29 ) ;
if ( V_24 & V_30 ) {
F_7 ( & V_21 -> V_2 , L_1 ,
F_8 ( V_17 ) ? L_2 : L_3 ) ;
V_25 = V_31 ;
}
if ( V_24 & V_32 )
F_9 ( & V_21 -> V_2 , L_4 ) ;
if ( V_24 & V_33 ) {
F_7 ( & V_21 -> V_2 , L_5 ) ;
V_25 = V_34 ;
}
if ( V_24 & V_35 )
F_7 ( & V_21 -> V_2 , L_6 ) ;
if ( V_24 & V_36 ) {
F_7 ( & V_21 -> V_2 , L_7 ) ;
V_25 = V_31 ;
}
if ( V_24 & V_37 ) {
F_7 ( & V_21 -> V_2 , L_8 ) ;
V_25 = V_31 ;
}
if ( V_25 != V_26 ) {
F_10 ( V_19 ) ;
F_11 ( V_19 , V_31 ) ;
F_12 ( V_19 ) ;
}
return V_38 ;
}
static int F_13 ( struct V_39 * V_40 ,
int V_41 , unsigned int V_42 , int V_43 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_44 ;
if ( ( V_43 == V_45 ) && V_17 -> V_46 ) {
V_44 = F_6 ( V_17 -> V_27 , V_4 ,
V_47 ,
( unsigned int ) ~ V_47 ) ;
if ( V_44 < 0 )
return V_44 ;
V_17 -> V_48 = V_42 ;
F_9 ( V_40 -> V_2 , L_9 , V_42 ) ;
}
return 0 ;
}
static int F_15 ( struct V_39 * V_40 , T_3 V_49 ,
T_3 V_50 , int V_51 , int V_52 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_53 , V_54 , V_55 ;
F_9 ( V_40 -> V_2 , L_10 ,
V_49 , V_50 , V_51 , V_52 ) ;
switch ( V_52 ) {
case 16 :
V_55 = V_56 ;
break;
case 32 :
V_55 = V_57 ;
break;
default:
V_55 = V_58 ;
break;
}
V_53 = F_16 ( V_55 ) |
F_17 ( V_51 - 1 ) ;
V_54 = V_59 | V_60 ;
if ( F_8 ( V_17 ) ) {
V_17 -> V_61 = V_49 ;
V_53 |= F_18 ( V_49 ) ;
}
if ( F_19 ( V_17 ) ) {
V_17 -> V_61 = V_50 ;
V_53 |= F_18 ( V_50 ) ;
}
V_54 |= V_62 ;
F_6 ( V_17 -> V_27 , V_7 , V_54 , V_53 ) ;
V_17 -> V_52 = V_52 ;
V_17 -> V_51 = V_51 ;
return 0 ;
}
static int F_20 ( struct V_39 * V_40 , unsigned int V_63 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_64 = 0 , V_65 = 0 ;
int V_66 = 0 , V_67 = 0 ;
int V_44 ;
F_9 ( V_40 -> V_2 , L_11 , V_63 ) ;
switch ( V_63 & V_68 ) {
case V_69 :
V_64 |= V_70 ;
V_65 |= V_71 | V_72 ;
break;
case V_73 :
V_65 |= V_74 | V_72 ;
break;
case V_75 :
V_65 |= V_74 | V_72 ;
break;
case V_76 :
V_65 |= V_74 | V_71 ;
break;
case V_77 :
V_65 |= V_74 ;
break;
default:
F_7 ( V_40 -> V_2 , L_12 ,
V_63 & V_68 ) ;
return - V_78 ;
}
V_66 |= V_79 | V_70 ;
V_67 |= V_74 | V_71 |
V_72 ;
switch ( V_63 & V_80 ) {
case V_81 :
break;
case V_82 :
V_64 ^= V_70 ;
break;
case V_83 :
V_65 ^= V_74 ;
break;
case V_84 :
V_64 ^= V_70 ;
V_65 ^= V_74 ;
break;
default:
F_7 ( V_40 -> V_2 , L_13 ,
V_63 & V_80 ) ;
return - V_78 ;
}
V_66 |= V_70 ;
V_67 |= V_74 ;
F_6 ( V_17 -> V_27 , V_6 , V_67 , V_65 ) ;
switch ( V_63 & V_85 ) {
case V_86 :
V_64 |= V_87 ;
V_17 -> V_46 = false ;
break;
case V_88 :
V_17 -> V_46 = true ;
break;
default:
F_7 ( V_40 -> V_2 , L_14 ,
V_63 & V_85 ) ;
return - V_78 ;
}
V_66 |= V_87 ;
V_64 |= V_47 ;
V_66 |= V_47 ;
V_44 = F_6 ( V_17 -> V_27 , V_4 , V_66 , V_64 ) ;
if ( V_44 < 0 ) {
F_7 ( V_40 -> V_2 , L_15 ) ;
return V_44 ;
}
V_17 -> V_63 = V_63 ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 ,
struct V_39 * V_40 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_23 , V_89 , V_44 ;
V_17 -> V_19 = V_19 ;
V_44 = F_22 ( V_17 -> V_90 ) ;
if ( V_44 < 0 ) {
F_7 ( V_40 -> V_2 , L_16 , V_44 ) ;
return V_44 ;
}
F_6 ( V_17 -> V_27 , V_9 ,
V_91 , ( unsigned int ) ~ V_91 ) ;
F_6 ( V_17 -> V_27 , V_10 ,
V_29 , V_29 ) ;
V_23 = V_30 ;
if ( F_19 ( V_17 ) ) {
F_5 ( V_17 -> V_27 , V_5 , & V_89 ) ;
if ( V_89 & V_92 )
V_23 |= V_32 ;
}
if ( V_17 -> V_46 )
V_23 |= V_33 ;
else
V_23 |= V_36 | V_37 ;
F_6 ( V_17 -> V_27 , V_8 ,
V_93 , V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_40 ,
struct V_18 * V_19 ,
struct V_94 * V_95 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_64 , V_66 , V_44 ;
int V_96 = V_97 ;
F_6 ( V_17 -> V_27 , V_5 ,
V_98 | V_99 ,
V_98 | F_24 ( V_96 ) ) ;
V_64 = F_25 ( V_100 ) ;
switch ( F_26 ( V_95 ) ) {
case V_101 :
V_64 |= F_27 ( V_102 ) ;
break;
case V_103 :
V_64 |= F_27 ( V_104 ) ;
break;
case V_105 :
V_64 |= F_27 ( V_106 ) ;
break;
default:
F_7 ( V_40 -> V_2 , L_17 ) ;
return - V_78 ;
}
V_66 = V_107 | V_79 ;
V_66 |= V_108 ;
if ( F_19 ( V_17 ) )
V_64 |= V_108 ;
V_66 |= V_109 ;
if ( ( V_17 -> V_51 == 2 ) && ( F_28 ( V_95 ) == 1 ) )
V_64 |= V_109 ;
V_44 = F_6 ( V_17 -> V_27 , V_4 , V_66 , V_64 ) ;
if ( V_44 < 0 ) {
F_7 ( V_40 -> V_2 , L_15 ) ;
return V_44 ;
}
V_17 -> V_110 . V_111 = V_112 * V_96 / sizeof( T_3 ) ;
F_29 ( V_40 , V_19 , ( void * ) & V_17 -> V_110 ) ;
return 0 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_53 , V_113 ;
F_5 ( V_17 -> V_27 , V_7 , & V_53 ) ;
V_113 = V_53 & V_59 ;
if ( V_113 == F_16 ( V_58 ) )
V_17 -> V_52 = V_17 -> V_114 ;
if ( V_17 -> V_52 < V_17 -> V_114 ) {
F_7 ( V_40 -> V_2 ,
L_18 ,
V_17 -> V_114 ) ;
return - V_78 ;
}
if ( ! V_17 -> V_51 )
V_17 -> V_51 = 2 ;
F_6 ( V_17 -> V_27 , V_7 ,
V_60 ,
F_17 ( ( V_17 -> V_51 - 1 ) ) ) ;
if ( ! ( V_53 & V_62 ) ) {
V_17 -> V_61 = ( 1 << V_17 -> V_51 ) - 1 ;
F_6 ( V_17 -> V_27 ,
V_7 , V_62 ,
F_18 ( V_17 -> V_61 ) ) ;
}
F_9 ( V_40 -> V_2 , L_19 ,
V_17 -> V_51 , V_17 -> V_52 ) ;
return 0 ;
}
static void F_31 ( struct V_39 * V_40 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_115 , V_116 , V_117 ;
int V_65 , V_67 ;
V_117 = V_17 -> V_63 & V_68 ;
V_17 -> V_118 = V_17 -> V_52 * V_17 -> V_51 ;
V_115 = V_17 -> V_118 / 2 ;
if ( ( V_117 == V_76 ) ||
( V_117 == V_77 ) )
V_115 = 1 ;
V_65 = F_32 ( ( V_17 -> V_118 - 1 ) ) ;
V_65 |= F_33 ( ( V_115 - 1 ) ) ;
V_67 = V_119 | V_120 ;
F_9 ( V_40 -> V_2 , L_20 ,
V_17 -> V_118 , V_115 ) ;
F_6 ( V_17 -> V_27 , V_6 , V_67 , V_65 ) ;
if ( ( V_17 -> V_63 & V_68 ) == V_75 ) {
V_116 = V_17 -> V_52 - V_17 -> V_114 ;
F_6 ( V_17 -> V_27 , V_7 ,
V_121 ,
F_34 ( V_116 ) ) ;
}
}
static int F_35 ( struct V_39 * V_40 ,
struct V_94 * V_95 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_64 , V_122 , div = 0 ;
int V_123 , V_124 , V_125 , V_44 ;
int V_126 = V_17 -> V_127 -> V_128 -> V_126 ;
if ( ! V_17 -> V_48 ) {
F_7 ( V_40 -> V_2 , L_21 ) ;
return - V_78 ;
}
if ( ! ( F_36 ( V_95 ) % 11025 ) )
F_37 ( V_17 -> V_90 , V_17 -> V_127 -> V_129 ) ;
else
F_37 ( V_17 -> V_90 , V_17 -> V_127 -> V_130 ) ;
V_123 = F_38 ( V_17 -> V_90 ) ;
if ( F_39 ( V_17 -> V_127 ) ) {
if ( 2 * V_123 >= 3 * V_17 -> V_48 )
div = F_40 ( V_123 ,
2 * V_17 -> V_48 ) ;
} else {
if ( V_17 -> V_48 ) {
V_124 = V_17 -> V_48 / F_36 ( V_95 ) ;
if ( V_124 != 256 ) {
if ( V_124 == 512 ) {
V_122 = V_131 ;
V_64 = V_131 ;
} else {
F_7 ( V_40 -> V_2 ,
L_22 ,
V_124 ) ;
return - V_78 ;
}
}
div = F_40 ( V_123 , V_17 -> V_48 ) ;
} else {
V_125 = V_17 -> V_118 * F_36 ( V_95 ) ;
div = F_40 ( V_123 , V_125 ) ;
}
}
if ( div > F_41 ( V_126 ) ) {
F_7 ( V_40 -> V_2 , L_23 , div ) ;
return - V_78 ;
}
F_9 ( V_40 -> V_2 , L_24 , V_123 , div ) ;
V_122 = F_42 ( F_43 ( V_126 ) ) ;
V_64 = F_44 ( div ) ;
V_44 = F_6 ( V_17 -> V_27 , V_4 , V_122 , V_64 ) ;
if ( V_44 < 0 ) {
F_7 ( V_40 -> V_2 , L_15 ) ;
return V_44 ;
}
return 0 ;
}
static int F_45 ( struct V_18 * V_19 ,
struct V_94 * V_95 ,
struct V_39 * V_40 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_44 ;
V_17 -> V_114 = F_46 ( V_95 ) ;
V_44 = F_30 ( V_40 ) ;
if ( V_44 < 0 )
return V_44 ;
F_31 ( V_40 ) ;
V_44 = F_23 ( V_40 , V_19 , V_95 ) ;
if ( V_44 )
return V_44 ;
if ( V_17 -> V_46 )
V_44 = F_35 ( V_40 , V_95 ) ;
return V_44 ;
}
static int F_47 ( struct V_18 * V_19 , int V_132 ,
struct V_39 * V_40 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
int V_44 ;
switch ( V_132 ) {
case V_133 :
case V_134 :
case V_135 :
F_9 ( V_40 -> V_2 , L_25 ) ;
F_6 ( V_17 -> V_27 , V_4 ,
V_136 , V_136 ) ;
V_44 = F_6 ( V_17 -> V_27 , V_4 ,
V_137 , V_137 ) ;
if ( V_44 < 0 )
F_7 ( V_40 -> V_2 , L_15 ) ;
break;
case V_138 :
case V_139 :
case V_140 :
F_9 ( V_40 -> V_2 , L_26 ) ;
F_6 ( V_17 -> V_27 , V_4 ,
V_137 ,
( unsigned int ) ~ V_137 ) ;
V_44 = F_6 ( V_17 -> V_27 , V_4 ,
V_136 ,
( unsigned int ) ~ V_136 ) ;
if ( V_44 < 0 )
F_7 ( V_40 -> V_2 , L_15 ) ;
break;
default:
return - V_78 ;
}
return V_44 ;
}
static void F_48 ( struct V_18 * V_19 ,
struct V_39 * V_40 )
{
struct V_16 * V_17 = F_14 ( V_40 ) ;
F_6 ( V_17 -> V_27 , V_8 , V_93 , 0 ) ;
F_6 ( V_17 -> V_27 , V_4 , V_47 ,
V_47 ) ;
F_49 ( V_17 -> V_90 ) ;
V_17 -> V_19 = NULL ;
}
static int F_50 ( struct V_39 * V_40 )
{
struct V_16 * V_17 = F_51 ( V_40 -> V_2 ) ;
V_17 -> V_110 . V_141 = ( V_142 ) ( V_17 -> V_143 + V_11 ) ;
V_17 -> V_110 . V_111 = 1 ;
V_17 -> V_110 . V_144 = V_145 ;
if ( F_8 ( V_17 ) )
F_52 ( V_40 , & V_17 -> V_110 , NULL ) ;
else
F_52 ( V_40 , NULL , & V_17 -> V_110 ) ;
return 0 ;
}
static int F_53 ( struct V_20 * V_21 ,
struct V_16 * V_17 )
{
struct V_146 * V_147 = V_21 -> V_2 . V_148 ;
struct V_149 * V_150 ;
void T_4 * V_151 ;
if ( ! V_147 )
return - V_152 ;
V_150 = F_54 ( V_21 , V_153 , 0 ) ;
V_151 = F_55 ( & V_21 -> V_2 , V_150 ) ;
if ( F_56 ( V_151 ) )
return F_57 ( V_151 ) ;
V_17 -> V_143 = V_150 -> V_154 ;
V_17 -> V_155 = & V_156 ;
if ( F_58 ( V_17 -> V_127 ) && F_59 ( V_17 ) )
V_17 -> V_155 = & V_157 ;
V_17 -> V_27 = F_60 ( & V_21 -> V_2 , L_27 ,
V_151 , V_17 -> V_155 ) ;
if ( F_56 ( V_17 -> V_27 ) ) {
F_7 ( & V_21 -> V_2 , L_28 ) ;
return F_57 ( V_17 -> V_27 ) ;
}
if ( F_61 ( V_147 , L_29 , L_30 ) >= 0 ) {
V_17 -> V_43 = V_158 ;
} else if ( F_61 ( V_147 , L_29 , L_31 ) >= 0 ) {
V_17 -> V_43 = V_159 ;
} else {
F_7 ( & V_21 -> V_2 , L_32 ) ;
return - V_78 ;
}
V_17 -> V_90 = F_62 ( & V_21 -> V_2 , L_27 ) ;
if ( F_56 ( V_17 -> V_90 ) ) {
F_7 ( & V_21 -> V_2 , L_33 ) ;
return F_57 ( V_17 -> V_90 ) ;
}
return 0 ;
}
static int F_63 ( struct V_20 * V_21 ,
struct V_16 * V_17 )
{
V_17 -> V_160 = F_64 ( & V_21 -> V_2 ,
sizeof( struct V_161 ) ,
V_162 ) ;
if ( ! V_17 -> V_160 )
return - V_163 ;
V_17 -> V_160 -> V_164 = F_65 ( & V_21 -> V_2 ) ;
if ( F_8 ( V_17 ) ) {
memcpy ( V_17 -> V_160 , & V_165 ,
sizeof( V_165 ) ) ;
V_17 -> V_160 -> V_166 . V_167 = V_17 -> V_160 -> V_164 ;
} else {
memcpy ( V_17 -> V_160 , & V_168 ,
sizeof( V_168 ) ) ;
V_17 -> V_160 -> V_169 . V_167 = V_17 -> V_160 -> V_164 ;
}
return 0 ;
}
static int F_66 ( struct V_20 * V_21 )
{
struct V_16 * V_17 ;
const struct V_170 * V_171 ;
int V_44 ;
V_17 = F_64 ( & V_21 -> V_2 , sizeof( * V_17 ) , V_162 ) ;
if ( ! V_17 )
return - V_163 ;
V_171 = F_67 ( V_172 , & V_21 -> V_2 ) ;
if ( ! V_171 )
return - V_78 ;
V_17 -> V_173 = ( V_174 ) V_171 -> V_175 ;
V_17 -> V_21 = V_21 ;
F_68 ( V_21 , V_17 ) ;
V_17 -> V_127 = F_51 ( V_21 -> V_2 . V_176 ) ;
if ( ! V_17 -> V_127 ) {
F_7 ( & V_21 -> V_2 , L_34 ) ;
return - V_78 ;
}
V_44 = F_53 ( V_21 , V_17 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_63 ( V_21 , V_17 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_69 ( & V_21 -> V_2 , V_17 -> V_127 -> V_14 , F_4 ,
V_177 , F_65 ( & V_21 -> V_2 ) , V_17 ) ;
if ( V_44 ) {
F_7 ( & V_21 -> V_2 , L_35 , V_44 ) ;
return V_44 ;
}
V_44 = F_70 ( & V_21 -> V_2 , & V_178 ,
V_17 -> V_160 , 1 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_71 ( & V_21 -> V_2 ,
& V_179 , 0 ) ;
if ( V_44 ) {
F_7 ( & V_21 -> V_2 , L_36 ) ;
return V_44 ;
}
return 0 ;
}
