static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 V_7 , V_8 ;
unsigned long V_9 ;
int V_10 = 0 ;
F_2 ( V_4 -> V_11 , V_12 , & V_7 ) ;
F_2 ( V_4 -> V_11 , V_13 , & V_8 ) ;
V_9 = V_7 & V_8 ;
if ( ! V_9 ) {
F_3 ( & V_6 -> V_14 , L_1 ,
V_7 , V_8 ) ;
return V_15 ;
}
F_4 ( V_4 -> V_11 , V_16 ,
V_17 , V_9 ) ;
if ( V_9 & V_18 ) {
F_3 ( & V_6 -> V_14 , L_2 ) ;
V_10 = 1 ;
}
if ( V_9 & V_19 ) {
F_3 ( & V_6 -> V_14 , L_3 ) ;
V_10 = 1 ;
}
if ( V_9 & V_20 )
F_3 ( & V_6 -> V_14 , L_4 ) ;
if ( V_10 )
F_5 ( V_4 -> V_21 ) ;
return V_22 ;
}
static bool F_6 ( struct V_23 * V_14 , unsigned int V_24 )
{
switch ( V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_13 :
case V_12 :
case V_16 :
case V_28 :
case V_29 :
case V_30 :
return true ;
default:
return false ;
}
}
static bool F_7 ( struct V_23 * V_14 , unsigned int V_24 )
{
switch ( V_24 ) {
case V_28 :
case V_29 :
return true ;
default:
return false ;
}
}
static bool F_8 ( struct V_23 * V_14 , unsigned int V_24 )
{
switch ( V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_13 :
case V_16 :
case V_28 :
case V_30 :
return true ;
default:
return false ;
}
}
static int F_9 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_3 * V_4 = F_10 ( V_32 ) ;
T_2 V_34 ;
T_2 V_35 = V_36 | V_37 |
V_38 | V_39 ;
F_3 ( V_32 -> V_14 , L_5 , V_33 ) ;
switch ( V_33 & V_40 ) {
case V_41 :
V_34 = F_11 ( V_42 ) ;
break;
case V_43 :
V_34 = F_11 ( V_44 ) ;
break;
case V_45 :
V_34 = F_11 ( V_46 ) ;
break;
case V_47 :
V_34 = F_11 ( V_48 ) ;
break;
default:
F_12 ( V_32 -> V_14 , L_6 ,
V_33 & V_40 ) ;
return - V_49 ;
}
switch ( V_33 & V_50 ) {
case V_51 :
break;
case V_52 :
V_34 |= V_37 ;
break;
case V_53 :
V_34 |= V_38 ;
break;
case V_54 :
V_34 |= V_37 ;
V_34 |= V_38 ;
break;
default:
F_12 ( V_32 -> V_14 , L_7 ,
V_33 & V_50 ) ;
return - V_49 ;
}
switch ( V_33 & V_55 ) {
case V_56 :
V_4 -> V_57 = V_58 ;
break;
case V_59 :
V_4 -> V_57 = V_60 ;
break;
default:
F_12 ( V_32 -> V_14 , L_8 ,
V_33 & V_55 ) ;
return - V_49 ;
}
V_4 -> V_33 = V_33 ;
return F_4 ( V_4 -> V_11 , V_30 ,
V_35 , V_34 ) ;
}
static int F_13 ( struct V_31 * V_32 ,
int V_61 , unsigned int V_62 , int V_63 )
{
struct V_3 * V_4 = F_10 ( V_32 ) ;
F_3 ( V_32 -> V_14 , L_9 , V_62 ) ;
if ( ( V_63 == V_64 ) && F_14 ( V_4 ) ) {
V_4 -> V_65 = V_62 ;
return F_4 ( V_4 -> V_11 , V_30 ,
V_66 , V_66 ) ;
}
return 0 ;
}
static int F_15 ( struct V_31 * V_32 ,
struct V_67 * V_68 )
{
struct V_3 * V_4 = F_10 ( V_32 ) ;
unsigned long V_69 ;
unsigned int V_70 , div , V_71 , V_72 , V_73 ;
unsigned int V_74 = F_16 ( V_68 ) ;
int V_75 ;
T_2 V_34 , V_35 ;
bool V_76 ;
if ( ! ( V_74 % 11025 ) )
F_17 ( V_4 -> V_77 , V_4 -> V_78 ) ;
else
F_17 ( V_4 -> V_77 , V_4 -> V_79 ) ;
V_69 = F_18 ( V_4 -> V_77 ) ;
if ( V_4 -> V_65 ) {
V_70 = F_19 ( V_69 , V_4 -> V_65 ) ;
} else {
V_73 = 32 ;
if ( ( V_4 -> V_33 & V_40 ) ==
V_47 )
V_73 = 16 ;
V_75 = F_2 ( V_4 -> V_11 , V_30 , & V_34 ) ;
if ( V_75 < 0 )
return V_75 ;
V_72 = V_73 * ( ( V_34 & V_80 ) + 1 ) ;
V_70 = F_19 ( V_69 , ( V_72 * V_74 ) ) ;
}
V_76 = V_70 & 0x1 ;
div = V_70 >> 1 ;
V_34 = F_20 ( div ) | ( V_76 << V_81 ) ;
V_35 = V_82 | V_83 ;
V_71 = ( ( 2 * div ) + V_76 ) ;
F_3 ( V_32 -> V_14 , L_10 ,
V_69 , V_74 ) ;
F_3 ( V_32 -> V_14 , L_11 ,
div , V_76 , V_71 ) ;
if ( ( ( div == 1 ) && V_76 ) || ( div > V_84 ) ) {
F_12 ( V_32 -> V_14 , L_12 ) ;
return - V_49 ;
}
if ( ! div && ! V_76 )
F_21 ( V_32 -> V_14 , L_13 ) ;
V_75 = F_4 ( V_4 -> V_11 , V_30 ,
V_35 , V_34 ) ;
if ( V_75 < 0 )
return V_75 ;
return F_4 ( V_4 -> V_11 , V_27 ,
V_85 , V_85 ) ;
}
static int F_22 ( struct V_31 * V_32 ,
struct V_67 * V_68 ,
struct V_86 * V_21 )
{
struct V_3 * V_4 = F_10 ( V_32 ) ;
int V_87 = F_23 ( V_68 ) ;
T_2 V_88 , V_89 , V_90 , V_91 ;
unsigned int V_92 ;
int V_75 ;
if ( ( F_24 ( V_68 ) == 1 ) &&
( ( V_4 -> V_33 & V_40 ) != V_47 ) ) {
F_12 ( V_32 -> V_14 , L_14 ) ;
return - V_49 ;
}
switch ( V_87 ) {
case 16 :
V_88 = F_25 ( V_93 ) ;
V_89 = V_94 ;
break;
case 32 :
V_88 = F_25 ( V_95 ) |
V_80 ;
V_89 = V_94 | V_80 ;
break;
default:
F_12 ( V_32 -> V_14 , L_15 , V_87 ) ;
return - V_49 ;
}
if ( F_26 ( V_4 ) ) {
V_88 |= F_27 ( V_96 ) ;
V_88 |= V_97 ;
V_89 |= V_97 ;
} else {
V_88 |= F_27 ( V_98 ) ;
}
V_89 |= V_39 ;
V_75 = F_4 ( V_4 -> V_11 , V_30 ,
V_89 , V_88 ) ;
if ( V_75 < 0 )
return V_75 ;
V_90 = V_99 | V_100 ;
V_91 = V_90 ;
V_92 = V_101 * V_102 / 4 ;
V_90 |= F_28 ( V_92 - 1 ) ;
V_91 |= V_103 ;
return F_4 ( V_4 -> V_11 , V_26 ,
V_91 , V_90 ) ;
}
static int F_29 ( struct V_86 * V_21 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_10 ( V_32 ) ;
V_4 -> V_21 = V_21 ;
F_30 ( & V_4 -> V_104 ) ;
V_4 -> V_105 ++ ;
F_31 ( & V_4 -> V_104 ) ;
return F_4 ( V_4 -> V_11 , V_16 ,
V_17 , V_17 ) ;
}
static int F_32 ( struct V_86 * V_21 ,
struct V_67 * V_68 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_10 ( V_32 ) ;
int V_75 ;
V_75 = F_22 ( V_32 , V_68 , V_21 ) ;
if ( V_75 < 0 ) {
F_12 ( V_32 -> V_14 , L_16 , V_75 ) ;
return V_75 ;
}
if ( F_14 ( V_4 ) )
V_75 = F_15 ( V_32 , V_68 ) ;
return V_75 ;
}
static int F_33 ( struct V_86 * V_21 , int V_106 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_10 ( V_32 ) ;
bool V_107 = ( V_21 -> V_108 == V_109 ) ;
T_2 V_91 , V_8 ;
int V_75 ;
switch ( V_106 ) {
case V_110 :
case V_111 :
case V_112 :
F_3 ( V_32 -> V_14 , L_17 ) ;
V_75 = F_4 ( V_4 -> V_11 , V_25 ,
V_113 , V_113 ) ;
if ( V_75 < 0 ) {
F_12 ( V_32 -> V_14 , L_18 , V_75 ) ;
return V_75 ;
}
V_75 = F_4 ( V_4 -> V_11 , V_25 ,
V_114 , V_114 ) ;
if ( V_75 < 0 ) {
F_12 ( V_32 -> V_14 , L_19 , V_75 ) ;
return V_75 ;
}
F_4 ( V_4 -> V_11 , V_16 ,
V_17 , V_17 ) ;
if ( V_107 ) {
V_8 = V_115 ;
} else {
V_8 = V_116 ;
F_30 ( & V_4 -> V_104 ) ;
if ( V_4 -> V_105 == 1 )
F_34 ( V_4 -> V_11 ,
V_28 , 0 ) ;
F_31 ( & V_4 -> V_104 ) ;
}
if ( F_26 ( V_4 ) )
V_8 |= V_117 ;
F_4 ( V_4 -> V_11 , V_13 , V_8 , V_8 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
if ( V_107 )
F_4 ( V_4 -> V_11 , V_13 ,
V_115 ,
( unsigned int ) ~ V_115 ) ;
else
F_4 ( V_4 -> V_11 , V_13 ,
V_116 ,
( unsigned int ) ~ V_116 ) ;
F_30 ( & V_4 -> V_104 ) ;
V_4 -> V_105 -- ;
if ( V_4 -> V_105 ) {
F_31 ( & V_4 -> V_104 ) ;
break;
}
F_31 ( & V_4 -> V_104 ) ;
F_3 ( V_32 -> V_14 , L_20 ) ;
V_75 = F_4 ( V_4 -> V_11 , V_25 ,
V_113 , 0 ) ;
if ( V_75 < 0 ) {
F_12 ( V_32 -> V_14 , L_21 , V_75 ) ;
return V_75 ;
}
V_91 = V_99 | V_100 ;
F_4 ( V_4 -> V_11 , V_26 ,
V_91 , 0 ) ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static void F_35 ( struct V_86 * V_21 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_10 ( V_32 ) ;
V_4 -> V_21 = NULL ;
F_4 ( V_4 -> V_11 , V_30 ,
V_66 , ( unsigned int ) ~ V_66 ) ;
}
static int F_36 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_37 ( V_32 -> V_14 ) ;
struct V_121 * V_122 = & V_4 -> V_122 ;
struct V_121 * V_123 = & V_4 -> V_123 ;
V_122 -> V_124 = V_125 ;
V_122 -> V_126 = ( V_127 ) ( V_4 -> V_128 ) + V_28 ;
V_122 -> V_129 = 1 ;
V_123 -> V_124 = V_125 ;
V_123 -> V_126 = ( V_127 ) ( V_4 -> V_128 ) + V_29 ;
V_123 -> V_129 = 1 ;
F_38 ( V_32 , V_122 , V_123 ) ;
return 0 ;
}
static void F_39 ( struct V_130 * V_108 ,
char * V_131 )
{
V_108 -> V_131 = V_131 ;
V_108 -> V_132 = 1 ;
V_108 -> V_133 = 2 ;
V_108 -> V_134 = V_135 ;
V_108 -> V_136 = V_137 |
V_138 ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_139 * V_140 ;
V_140 = F_41 ( & V_6 -> V_14 , sizeof( struct V_139 ) ,
V_141 ) ;
if ( ! V_140 )
return - V_142 ;
snprintf ( V_4 -> V_143 , V_144 ,
L_22 , F_42 ( & V_6 -> V_14 ) ) ;
V_140 -> V_145 = F_36 ;
V_140 -> V_146 = & V_147 ;
V_140 -> V_148 = V_4 -> V_143 ;
V_140 -> V_149 = 1 ;
F_39 ( & V_140 -> V_150 , L_23 ) ;
F_39 ( & V_140 -> V_151 , L_24 ) ;
V_4 -> V_152 = V_140 ;
return 0 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_153 * V_154 = V_6 -> V_14 . V_155 ;
const struct V_156 * V_157 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
int V_1 , V_75 ;
if ( ! V_154 )
return - V_162 ;
V_157 = F_44 ( V_163 , & V_6 -> V_14 ) ;
if ( V_157 )
V_4 -> V_164 = ( const struct V_165 * ) V_157 -> V_166 ;
else
return - V_49 ;
V_161 = F_45 ( V_6 , V_167 , 0 ) ;
V_4 -> V_168 = F_46 ( & V_6 -> V_14 , V_161 ) ;
if ( F_47 ( V_4 -> V_168 ) )
return F_48 ( V_4 -> V_168 ) ;
V_4 -> V_128 = V_161 -> V_169 ;
V_4 -> V_170 = F_49 ( & V_6 -> V_14 , L_25 ) ;
if ( F_47 ( V_4 -> V_170 ) ) {
F_12 ( & V_6 -> V_14 , L_26 ) ;
return F_48 ( V_4 -> V_170 ) ;
}
V_4 -> V_77 = F_49 ( & V_6 -> V_14 , L_27 ) ;
if ( F_47 ( V_4 -> V_77 ) ) {
F_12 ( & V_6 -> V_14 , L_28 ) ;
return F_48 ( V_4 -> V_77 ) ;
}
V_4 -> V_79 = F_49 ( & V_6 -> V_14 , L_29 ) ;
if ( F_47 ( V_4 -> V_79 ) ) {
F_12 ( & V_6 -> V_14 , L_30 ) ;
return F_48 ( V_4 -> V_79 ) ;
}
V_4 -> V_78 = F_49 ( & V_6 -> V_14 , L_31 ) ;
if ( F_47 ( V_4 -> V_78 ) ) {
F_12 ( & V_6 -> V_14 , L_32 ) ;
return F_48 ( V_4 -> V_78 ) ;
}
V_1 = F_50 ( V_6 , 0 ) ;
if ( V_1 < 0 ) {
F_12 ( & V_6 -> V_14 , L_33 , V_6 -> V_148 ) ;
return - V_171 ;
}
V_75 = F_51 ( & V_6 -> V_14 , V_1 , F_1 , V_172 ,
F_42 ( & V_6 -> V_14 ) , V_4 ) ;
if ( V_75 ) {
F_12 ( & V_6 -> V_14 , L_34 , V_75 ) ;
return V_75 ;
}
V_159 = F_52 ( & V_6 -> V_14 , NULL ) ;
if ( ! F_47 ( V_159 ) ) {
F_53 ( V_159 ) ;
F_54 ( 2 ) ;
F_55 ( V_159 ) ;
}
return 0 ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
int V_75 ;
V_4 = F_41 ( & V_6 -> V_14 , sizeof( * V_4 ) , V_141 ) ;
if ( ! V_4 )
return - V_142 ;
V_75 = F_43 ( V_6 , V_4 ) ;
if ( V_75 )
return V_75 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_57 = V_173 ;
F_57 ( & V_4 -> V_104 ) ;
F_58 ( V_6 , V_4 ) ;
V_75 = F_40 ( V_6 , V_4 ) ;
if ( V_75 )
return V_75 ;
V_4 -> V_11 = F_59 ( & V_6 -> V_14 , V_4 -> V_168 ,
V_4 -> V_164 ) ;
if ( F_47 ( V_4 -> V_11 ) ) {
F_12 ( & V_6 -> V_14 , L_35 ) ;
return F_48 ( V_4 -> V_11 ) ;
}
V_75 = F_60 ( V_4 -> V_170 ) ;
if ( V_75 ) {
F_12 ( & V_6 -> V_14 , L_36 , V_75 ) ;
return V_75 ;
}
V_75 = F_60 ( V_4 -> V_77 ) ;
if ( V_75 ) {
F_12 ( & V_6 -> V_14 , L_37 , V_75 ) ;
goto V_174;
}
V_75 = F_61 ( & V_6 -> V_14 , & V_175 ,
V_4 -> V_152 , 1 ) ;
if ( V_75 )
goto V_176;
V_75 = F_62 ( & V_6 -> V_14 ,
& V_177 , 0 ) ;
if ( V_75 )
goto V_176;
V_75 = F_4 ( V_4 -> V_11 , V_30 ,
V_178 , V_178 ) ;
if ( V_75 )
goto V_176;
return V_75 ;
V_176:
F_63 ( V_4 -> V_77 ) ;
V_174:
F_63 ( V_4 -> V_170 ) ;
return V_75 ;
}
static int F_64 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_65 ( V_6 ) ;
F_63 ( V_4 -> V_77 ) ;
F_63 ( V_4 -> V_170 ) ;
return 0 ;
}
