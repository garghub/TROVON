static const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
default:
return L_5 ;
}
}
static int F_2 ( struct V_7 * V_8 , T_1 V_9 , T_2 V_10 ,
T_3 V_11 , T_3 type )
{
struct V_12 V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 ;
struct V_18 * V_19 ;
int V_20 ;
V_19 = V_8 -> V_21 [ V_9 ] ;
if ( V_19 -> V_22 & V_23 ) {
F_3 ( V_8 -> V_24 , L_6 , V_19 -> V_25 ) ;
return 0 ;
}
V_15 = V_8 -> V_26 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_27 = type ;
V_17 . V_28 = V_10 ;
V_17 . V_29 = V_11 ;
V_17 . V_30 = 1 ;
V_17 . V_31 = 1 ;
V_17 . V_32 = 1 ;
V_17 . V_33 = 1 ;
F_4 ( & V_17 , V_15 ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_34 = F_5 ( V_8 -> V_35 ) ;
V_13 . V_36 = F_6 ( V_8 -> V_35 ) ;
V_20 = F_7 ( V_8 , V_19 -> V_37 ,
V_38 , & V_13 ) ;
if ( V_20 < 0 ) {
F_8 ( V_8 -> V_24 , L_7 ) ;
return V_20 ;
}
V_19 -> V_22 |= V_23 ;
V_19 -> V_39 = F_9 ( V_8 ,
V_19 -> V_37 ) ;
V_8 -> V_40 = V_41 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 ,
struct V_42 * V_43 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
int V_20 = 0 ;
V_43 -> V_44 . V_45 = 0 ;
V_43 -> V_44 . V_46 = - V_47 ;
V_43 -> V_9 = V_19 -> V_37 ;
F_11 ( & V_43 -> V_48 , & V_19 -> V_49 ) ;
if ( V_19 -> V_22 & V_50 ) {
unsigned V_51 ;
V_51 = ! ! ( V_19 -> V_22 & V_52 ) ;
if ( V_8 -> V_53 != V_5 ) {
F_12 ( V_8 -> V_24 , L_8 ) ;
return 0 ;
}
V_20 = F_2 ( V_8 , V_51 ,
V_43 -> V_44 . V_54 , V_43 -> V_44 . V_29 ,
V_55 ) ;
V_19 -> V_22 &= ~ ( V_50 |
V_52 ) ;
} else if ( V_8 -> V_56 ) {
V_8 -> V_56 = false ;
if ( V_8 -> V_53 == V_6 )
F_13 ( V_8 , 1 ) ;
else
F_8 ( V_8 -> V_24 , L_9 ) ;
}
return V_20 ;
}
int F_14 ( struct V_57 * V_58 , struct V_59 * V_44 ,
T_4 V_60 )
{
struct V_42 * V_43 = F_15 ( V_44 ) ;
struct V_18 * V_19 = F_16 ( V_58 ) ;
struct V_7 * V_8 = V_19 -> V_8 ;
unsigned long V_22 ;
int V_20 ;
F_17 ( & V_8 -> V_61 , V_22 ) ;
if ( ! V_19 -> V_62 ) {
F_8 ( V_8 -> V_24 , L_10 ,
V_44 , V_19 -> V_25 ) ;
V_20 = - V_63 ;
goto V_64;
}
if ( ! F_18 ( & V_19 -> V_49 ) ) {
V_20 = - V_65 ;
goto V_64;
}
F_3 ( V_8 -> V_24 , L_11 ,
V_44 , V_19 -> V_25 , V_44 -> V_29 ,
F_1 ( V_8 -> V_53 ) ) ;
V_20 = F_10 ( V_19 , V_43 ) ;
V_64:
F_19 ( & V_8 -> V_61 , V_22 ) ;
return V_20 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = V_8 -> V_21 [ 0 ] ;
F_21 ( V_19 , 1 ) ;
V_19 -> V_22 = V_66 ;
V_8 -> V_56 = false ;
if ( ! F_18 ( & V_19 -> V_49 ) ) {
struct V_42 * V_43 ;
V_43 = F_22 ( & V_19 -> V_49 ) ;
F_23 ( V_19 , V_43 , - V_67 ) ;
}
V_8 -> V_53 = V_4 ;
F_24 ( V_8 ) ;
}
void F_24 ( struct V_7 * V_8 )
{
int V_20 ;
V_20 = F_2 ( V_8 , 0 , V_8 -> V_68 , 8 ,
V_69 ) ;
F_25 ( V_20 < 0 ) ;
}
static struct V_18 * F_26 ( struct V_7 * V_8 , T_5 V_70 )
{
struct V_18 * V_19 ;
T_3 V_71 = F_27 ( V_70 ) ;
T_3 V_9 ;
V_9 = ( V_71 & V_72 ) << 1 ;
if ( ( V_71 & V_73 ) == V_74 )
V_9 |= 1 ;
V_19 = V_8 -> V_21 [ V_9 ] ;
if ( V_19 -> V_22 & V_66 )
return V_19 ;
return NULL ;
}
static void F_28 ( struct V_57 * V_58 , struct V_59 * V_43 )
{
}
static int F_29 ( struct V_7 * V_8 ,
struct V_75 * V_76 )
{
struct V_18 * V_19 ;
T_3 V_77 ;
T_6 V_78 = 0 ;
T_5 * V_79 ;
V_77 = V_76 -> V_80 & V_81 ;
switch ( V_77 ) {
case V_82 :
V_78 |= V_8 -> V_83 << V_84 ;
break;
case V_85 :
break;
case V_86 :
V_19 = F_26 ( V_8 , V_76 -> V_87 ) ;
if ( ! V_19 )
return - V_88 ;
if ( V_19 -> V_22 & V_89 )
V_78 = 1 << V_90 ;
break;
default:
return - V_88 ;
} ;
V_79 = ( T_5 * ) V_8 -> V_91 ;
* V_79 = F_30 ( V_78 ) ;
V_19 = V_8 -> V_21 [ 0 ] ;
V_8 -> V_92 . V_19 = V_19 ;
V_8 -> V_92 . V_44 . V_29 = sizeof( * V_79 ) ;
V_8 -> V_92 . V_44 . V_54 = V_8 -> V_93 ;
V_8 -> V_92 . V_44 . V_94 = F_28 ;
return F_10 ( V_19 , & V_8 -> V_92 ) ;
}
static int F_31 ( struct V_7 * V_8 ,
struct V_75 * V_76 , int V_95 )
{
struct V_18 * V_19 ;
T_3 V_77 ;
T_3 V_96 ;
T_3 V_87 ;
T_3 V_97 ;
int V_20 ;
T_3 V_98 ;
V_96 = F_27 ( V_76 -> V_96 ) ;
V_87 = F_27 ( V_76 -> V_87 ) ;
V_77 = V_76 -> V_80 & V_81 ;
switch ( V_77 ) {
case V_82 :
switch ( V_96 ) {
case V_99 :
case V_100 :
case V_101 :
if ( V_8 -> V_102 != V_103 )
return - V_88 ;
if ( V_8 -> V_104 != V_105 )
return - V_88 ;
}
switch ( V_96 ) {
case V_106 :
break;
case V_99 :
break;
case V_100 :
break;
case V_101 :
break;
case V_107 :
if ( ( V_87 & 0xff ) != 0 )
return - V_88 ;
if ( ! V_95 )
return - V_88 ;
V_98 = V_87 >> 8 ;
V_97 = F_32 ( V_8 -> V_108 , V_109 ) ;
V_97 &= ~ V_110 ;
switch ( V_98 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_97 |= V_98 << 1 ;
break;
default:
return - V_88 ;
}
F_33 ( V_8 -> V_108 , V_109 , V_97 ) ;
break;
default:
return - V_88 ;
}
break;
case V_85 :
switch ( V_96 ) {
case V_116 :
if ( V_87 & V_117 )
;
if ( V_87 & V_118 )
;
break;
default:
return - V_88 ;
}
break;
case V_86 :
switch ( V_96 ) {
case V_90 :
V_19 = F_26 ( V_8 , V_87 ) ;
if ( ! V_19 )
return - V_88 ;
V_20 = F_21 ( V_19 , V_95 ) ;
if ( V_20 )
return - V_88 ;
break;
default:
return - V_88 ;
}
break;
default:
return - V_88 ;
} ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 , struct V_75 * V_76 )
{
T_3 V_119 ;
T_3 V_97 ;
V_119 = F_27 ( V_76 -> V_96 ) ;
if ( V_119 > 127 ) {
F_8 ( V_8 -> V_24 , L_12 , V_119 ) ;
return - V_88 ;
}
if ( V_8 -> V_102 == V_103 ) {
F_8 ( V_8 -> V_24 , L_13 ) ;
return - V_88 ;
}
V_97 = F_32 ( V_8 -> V_108 , V_120 ) ;
V_97 &= ~ ( V_121 ) ;
V_97 |= F_35 ( V_119 ) ;
F_33 ( V_8 -> V_108 , V_120 , V_97 ) ;
if ( V_119 )
V_8 -> V_102 = V_122 ;
else
V_8 -> V_102 = V_123 ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 , struct V_75 * V_76 )
{
int V_20 ;
F_37 ( & V_8 -> V_61 ) ;
V_20 = V_8 -> V_124 -> V_125 ( & V_8 -> V_126 , V_76 ) ;
F_38 ( & V_8 -> V_61 ) ;
return V_20 ;
}
static int F_39 ( struct V_7 * V_8 , struct V_75 * V_76 )
{
T_3 V_127 ;
int V_20 ;
V_8 -> V_128 = false ;
V_127 = F_27 ( V_76 -> V_96 ) ;
switch ( V_8 -> V_102 ) {
case V_123 :
return - V_88 ;
break;
case V_122 :
V_20 = F_36 ( V_8 , V_76 ) ;
if ( ! V_20 && V_127 )
V_8 -> V_102 = V_103 ;
break;
case V_103 :
V_20 = F_36 ( V_8 , V_76 ) ;
if ( ! V_127 )
V_8 -> V_102 = V_122 ;
break;
default:
V_20 = - V_88 ;
}
return V_20 ;
}
static int F_40 ( struct V_7 * V_8 , struct V_75 * V_76 )
{
int V_20 ;
switch ( V_76 -> V_129 ) {
case V_130 :
F_3 ( V_8 -> V_24 , L_14 ) ;
V_20 = F_29 ( V_8 , V_76 ) ;
break;
case V_131 :
F_3 ( V_8 -> V_24 , L_15 ) ;
V_20 = F_31 ( V_8 , V_76 , 0 ) ;
break;
case V_132 :
F_3 ( V_8 -> V_24 , L_16 ) ;
V_20 = F_31 ( V_8 , V_76 , 1 ) ;
break;
case V_133 :
F_3 ( V_8 -> V_24 , L_17 ) ;
V_20 = F_34 ( V_8 , V_76 ) ;
break;
case V_134 :
F_3 ( V_8 -> V_24 , L_18 ) ;
V_20 = F_39 ( V_8 , V_76 ) ;
break;
default:
F_3 ( V_8 -> V_24 , L_19 ) ;
V_20 = F_36 ( V_8 , V_76 ) ;
break;
} ;
return V_20 ;
}
static void F_41 ( struct V_7 * V_8 ,
const struct V_135 * V_136 )
{
struct V_75 * V_76 = V_8 -> V_137 ;
int V_20 ;
T_3 V_11 ;
if ( ! V_8 -> V_124 )
goto V_138;
V_11 = F_27 ( V_76 -> V_139 ) ;
if ( ! V_11 ) {
V_8 -> V_140 = false ;
V_8 -> V_141 = false ;
V_8 -> V_40 = V_142 ;
} else {
V_8 -> V_140 = true ;
V_8 -> V_141 = ! ! ( V_76 -> V_80 & V_74 ) ;
V_8 -> V_40 = V_143 ;
}
if ( ( V_76 -> V_80 & V_144 ) == V_145 )
V_20 = F_40 ( V_8 , V_76 ) ;
else
V_20 = F_36 ( V_8 , V_76 ) ;
if ( V_20 == V_146 )
V_8 -> V_56 = true ;
if ( V_20 >= 0 )
return;
V_138:
F_20 ( V_8 ) ;
}
static void F_42 ( struct V_7 * V_8 ,
const struct V_135 * V_136 )
{
struct V_42 * V_147 = NULL ;
struct V_59 * V_148 ;
struct V_16 V_17 ;
struct V_18 * V_149 ;
T_3 V_150 ;
T_1 V_9 ;
V_9 = V_136 -> V_151 ;
V_149 = V_8 -> V_21 [ 0 ] ;
V_8 -> V_40 = V_142 ;
V_147 = F_22 ( & V_149 -> V_49 ) ;
V_148 = & V_147 -> V_44 ;
F_43 ( V_8 -> V_26 , & V_17 ) ;
if ( V_8 -> V_152 ) {
V_150 = F_44 ( T_3 , V_148 -> V_29 ,
V_149 -> V_153 . V_154 - V_17 . V_29 ) ;
memcpy ( V_148 -> V_155 , V_8 -> V_156 , V_150 ) ;
V_8 -> V_152 = false ;
} else {
V_150 = V_148 -> V_29 - V_17 . V_29 ;
V_148 -> V_45 += V_150 ;
}
if ( ( V_9 & 1 ) && V_148 -> V_45 < V_148 -> V_29 ) {
F_20 ( V_8 ) ;
} else {
if ( V_147 )
F_23 ( V_149 , V_147 , 0 ) ;
}
}
static void F_45 ( struct V_7 * V_8 ,
const struct V_135 * V_136 )
{
struct V_42 * V_147 ;
struct V_18 * V_19 ;
V_19 = V_8 -> V_21 [ 0 ] ;
if ( ! F_18 ( & V_19 -> V_49 ) ) {
V_147 = F_22 ( & V_19 -> V_49 ) ;
F_23 ( V_19 , V_147 , 0 ) ;
}
V_8 -> V_53 = V_4 ;
F_24 ( V_8 ) ;
}
static void F_46 ( struct V_7 * V_8 ,
const struct V_135 * V_136 )
{
struct V_18 * V_19 = V_8 -> V_21 [ V_136 -> V_151 ] ;
V_19 -> V_22 &= ~ V_23 ;
V_8 -> V_157 = false ;
switch ( V_8 -> V_53 ) {
case V_4 :
F_3 ( V_8 -> V_24 , L_20 ) ;
F_41 ( V_8 , V_136 ) ;
break;
case V_5 :
F_3 ( V_8 -> V_24 , L_21 ) ;
F_42 ( V_8 , V_136 ) ;
break;
case V_6 :
F_3 ( V_8 -> V_24 , L_22 ) ;
F_45 ( V_8 , V_136 ) ;
break;
default:
F_47 ( true , L_23 , V_8 -> V_53 ) ;
}
}
static void F_48 ( struct V_7 * V_8 ,
const struct V_135 * V_136 )
{
F_24 ( V_8 ) ;
}
static void F_49 ( struct V_7 * V_8 ,
const struct V_135 * V_136 )
{
struct V_18 * V_19 ;
struct V_42 * V_43 ;
int V_20 ;
V_19 = V_8 -> V_21 [ 0 ] ;
if ( F_18 ( & V_19 -> V_49 ) ) {
F_3 ( V_8 -> V_24 , L_24 ) ;
V_19 -> V_22 |= V_50 ;
if ( V_136 -> V_151 )
V_19 -> V_22 |= V_52 ;
return;
}
V_43 = F_22 ( & V_19 -> V_49 ) ;
V_43 -> V_51 = ! ! V_136 -> V_151 ;
if ( V_43 -> V_44 . V_29 == 0 ) {
V_20 = F_2 ( V_8 , V_136 -> V_151 ,
V_8 -> V_68 , 0 ,
V_55 ) ;
} else if ( ( V_43 -> V_44 . V_29 % V_19 -> V_153 . V_154 )
&& ( V_136 -> V_151 == 0 ) ) {
F_50 ( V_43 ) ;
F_25 ( V_43 -> V_44 . V_29 > V_19 -> V_153 . V_154 ) ;
V_8 -> V_152 = true ;
V_20 = F_2 ( V_8 , V_136 -> V_151 ,
V_8 -> V_158 , V_19 -> V_153 . V_154 ,
V_55 ) ;
} else {
F_50 ( V_43 ) ;
V_20 = F_2 ( V_8 , V_136 -> V_151 ,
V_43 -> V_44 . V_54 , V_43 -> V_44 . V_29 ,
V_55 ) ;
}
F_25 ( V_20 < 0 ) ;
}
static int F_51 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
T_3 type ;
type = V_8 -> V_140 ? V_159
: V_160 ;
return F_2 ( V_8 , V_19 -> V_37 ,
V_8 -> V_68 , 0 , type ) ;
}
static void F_13 ( struct V_7 * V_8 , T_3 V_9 )
{
struct V_18 * V_19 = V_8 -> V_21 [ V_9 ] ;
F_25 ( F_51 ( V_19 ) ) ;
}
static void F_52 ( struct V_7 * V_8 ,
const struct V_135 * V_136 )
{
V_8 -> V_157 = true ;
if ( V_8 -> V_40 == V_41 ) {
switch ( V_136 -> V_46 ) {
case V_161 :
F_3 ( V_8 -> V_24 , L_25 ) ;
F_20 ( V_8 ) ;
break;
case V_162 :
case V_163 :
default:
F_3 ( V_8 -> V_24 , L_26 ) ;
}
return;
}
switch ( V_136 -> V_46 ) {
case V_161 :
F_3 ( V_8 -> V_24 , L_27 ) ;
V_8 -> V_53 = V_4 ;
F_48 ( V_8 , V_136 ) ;
break;
case V_162 :
F_3 ( V_8 -> V_24 , L_28 ) ;
V_8 -> V_53 = V_5 ;
if ( V_8 -> V_40 != V_143 ) {
F_3 ( V_8 -> V_24 , L_29 ,
V_8 -> V_40 ,
V_143 ) ;
F_20 ( V_8 ) ;
return;
}
if ( V_8 -> V_141 != V_136 -> V_151 ) {
F_3 ( V_8 -> V_24 , L_30 ) ;
F_20 ( V_8 ) ;
return;
}
F_49 ( V_8 , V_136 ) ;
break;
case V_163 :
F_3 ( V_8 -> V_24 , L_31 ) ;
V_8 -> V_53 = V_6 ;
if ( V_8 -> V_40 != V_142 ) {
F_3 ( V_8 -> V_24 , L_29 ,
V_8 -> V_40 ,
V_142 ) ;
F_20 ( V_8 ) ;
return;
}
if ( V_8 -> V_56 ) {
F_53 ( V_136 -> V_151 != 1 ) ;
F_3 ( V_8 -> V_24 , L_32 ) ;
return;
}
F_13 ( V_8 , V_136 -> V_151 ) ;
}
}
void F_54 ( struct V_7 * V_8 ,
const struct V_135 * V_136 )
{
T_1 V_9 = V_136 -> V_151 ;
F_8 ( V_8 -> V_24 , L_33 ,
F_55 ( V_136 -> V_164 ) ,
V_9 >> 1 , ( V_9 & 1 ) ? L_34 : L_35 ,
F_1 ( V_8 -> V_53 ) ) ;
switch ( V_136 -> V_164 ) {
case V_165 :
F_46 ( V_8 , V_136 ) ;
break;
case V_166 :
F_52 ( V_8 , V_136 ) ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
break;
}
}
