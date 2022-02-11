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
struct V_16 * V_17 ;
int V_18 ;
V_17 = V_8 -> V_19 [ V_9 ] ;
if ( V_17 -> V_20 & V_21 ) {
F_3 ( V_8 -> V_22 , L_6 , V_17 -> V_23 ) ;
return 0 ;
}
V_15 = V_8 -> V_24 ;
V_15 -> V_25 = F_4 ( V_10 ) ;
V_15 -> V_26 = F_5 ( V_10 ) ;
V_15 -> V_27 = V_11 ;
V_15 -> V_28 = type ;
V_15 -> V_28 |= ( V_29
| V_30
| V_31
| V_32 ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_33 = F_5 ( V_8 -> V_34 ) ;
V_13 . V_35 = F_4 ( V_8 -> V_34 ) ;
V_18 = F_6 ( V_8 , V_17 -> V_36 ,
V_37 , & V_13 ) ;
if ( V_18 < 0 ) {
F_7 ( V_8 -> V_22 , L_7 ) ;
return V_18 ;
}
V_17 -> V_20 |= V_21 ;
V_17 -> V_38 = F_8 ( V_8 ,
V_17 -> V_36 ) ;
V_8 -> V_39 = V_40 ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 ,
struct V_41 * V_42 )
{
struct V_7 * V_8 = V_17 -> V_8 ;
int V_18 = 0 ;
V_42 -> V_43 . V_44 = 0 ;
V_42 -> V_43 . V_45 = - V_46 ;
V_42 -> V_9 = V_17 -> V_36 ;
F_10 ( & V_42 -> V_47 , & V_17 -> V_48 ) ;
if ( V_17 -> V_20 & V_49 ) {
unsigned V_50 ;
V_50 = ! ! ( V_17 -> V_20 & V_51 ) ;
if ( V_8 -> V_52 != V_5 ) {
F_11 ( V_8 -> V_22 , L_8 ) ;
return 0 ;
}
V_18 = F_2 ( V_8 , V_50 ,
V_42 -> V_43 . V_53 , V_42 -> V_43 . V_54 ,
V_55 ) ;
V_17 -> V_20 &= ~ ( V_49 |
V_51 ) ;
} else if ( V_8 -> V_56 ) {
V_8 -> V_56 = false ;
if ( V_8 -> V_52 == V_6 )
F_12 ( V_8 , 1 ) ;
else
F_7 ( V_8 -> V_22 , L_9 ) ;
}
return V_18 ;
}
int F_13 ( struct V_57 * V_58 , struct V_59 * V_43 ,
T_4 V_60 )
{
struct V_41 * V_42 = F_14 ( V_43 ) ;
struct V_16 * V_17 = F_15 ( V_58 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
unsigned long V_20 ;
int V_18 ;
F_16 ( & V_8 -> V_61 , V_20 ) ;
if ( ! V_17 -> V_62 ) {
F_7 ( V_8 -> V_22 , L_10 ,
V_43 , V_17 -> V_23 ) ;
V_18 = - V_63 ;
goto V_64;
}
if ( ! F_17 ( & V_17 -> V_48 ) ) {
V_18 = - V_65 ;
goto V_64;
}
F_3 ( V_8 -> V_22 , L_11 ,
V_43 , V_17 -> V_23 , V_43 -> V_54 ,
F_1 ( V_8 -> V_52 ) ) ;
V_18 = F_9 ( V_17 , V_42 ) ;
V_64:
F_18 ( & V_8 -> V_61 , V_20 ) ;
return V_18 ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_19 [ 0 ] ;
F_20 ( V_17 , 1 ) ;
V_17 -> V_20 = V_66 ;
V_8 -> V_56 = false ;
if ( ! F_17 ( & V_17 -> V_48 ) ) {
struct V_41 * V_42 ;
V_42 = F_21 ( & V_17 -> V_48 ) ;
F_22 ( V_17 , V_42 , - V_67 ) ;
}
V_8 -> V_52 = V_4 ;
F_23 ( V_8 ) ;
}
void F_23 ( struct V_7 * V_8 )
{
int V_18 ;
V_18 = F_2 ( V_8 , 0 , V_8 -> V_68 , 8 ,
V_69 ) ;
F_24 ( V_18 < 0 ) ;
}
static struct V_16 * F_25 ( struct V_7 * V_8 , T_5 V_70 )
{
struct V_16 * V_17 ;
T_3 V_71 = F_26 ( V_70 ) ;
T_3 V_9 ;
V_9 = ( V_71 & V_72 ) << 1 ;
if ( ( V_71 & V_73 ) == V_74 )
V_9 |= 1 ;
V_17 = V_8 -> V_19 [ V_9 ] ;
if ( V_17 -> V_20 & V_66 )
return V_17 ;
return NULL ;
}
static void F_27 ( struct V_57 * V_58 , struct V_59 * V_42 )
{
}
static int F_28 ( struct V_7 * V_8 ,
struct V_75 * V_28 )
{
struct V_16 * V_17 ;
T_3 V_76 ;
T_6 V_77 = 0 ;
T_5 * V_78 ;
V_76 = V_28 -> V_79 & V_80 ;
switch ( V_76 ) {
case V_81 :
V_77 |= V_8 -> V_82 << V_83 ;
break;
case V_84 :
break;
case V_85 :
V_17 = F_25 ( V_8 , V_28 -> V_86 ) ;
if ( ! V_17 )
return - V_87 ;
if ( V_17 -> V_20 & V_88 )
V_77 = 1 << V_89 ;
break;
default:
return - V_87 ;
} ;
V_78 = ( T_5 * ) V_8 -> V_90 ;
* V_78 = F_29 ( V_77 ) ;
V_17 = V_8 -> V_19 [ 0 ] ;
V_8 -> V_91 . V_17 = V_17 ;
V_8 -> V_91 . V_43 . V_54 = sizeof( * V_78 ) ;
V_8 -> V_91 . V_43 . V_92 = V_8 -> V_90 ;
V_8 -> V_91 . V_43 . V_93 = F_27 ;
return F_9 ( V_17 , & V_8 -> V_91 ) ;
}
static int F_30 ( struct V_7 * V_8 ,
struct V_75 * V_28 , int V_94 )
{
struct V_16 * V_17 ;
T_3 V_76 ;
T_3 V_95 ;
T_3 V_86 ;
int V_18 ;
V_95 = F_26 ( V_28 -> V_95 ) ;
V_86 = F_26 ( V_28 -> V_86 ) ;
V_76 = V_28 -> V_79 & V_80 ;
switch ( V_76 ) {
case V_81 :
switch ( V_95 ) {
case V_96 :
case V_97 :
case V_98 :
if ( V_8 -> V_99 != V_100 )
return - V_87 ;
if ( V_8 -> V_101 != V_102 )
return - V_87 ;
}
switch ( V_95 ) {
case V_103 :
break;
case V_96 :
break;
case V_97 :
break;
case V_98 :
break;
case V_104 :
if ( ( V_86 & 0xff ) != 0 )
return - V_87 ;
if ( ! V_94 )
return - V_87 ;
V_8 -> V_105 = V_86 >> 8 ;
V_8 -> V_106 = true ;
break;
default:
return - V_87 ;
}
break;
case V_84 :
switch ( V_95 ) {
case V_107 :
if ( V_86 & V_108 )
;
if ( V_86 & V_109 )
;
break;
default:
return - V_87 ;
}
break;
case V_85 :
switch ( V_95 ) {
case V_89 :
V_17 = F_25 ( V_8 , V_86 ) ;
if ( ! V_17 )
return - V_87 ;
V_18 = F_20 ( V_17 , V_94 ) ;
if ( V_18 )
return - V_87 ;
break;
default:
return - V_87 ;
}
break;
default:
return - V_87 ;
} ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_75 * V_28 )
{
T_3 V_110 ;
T_3 V_111 ;
V_110 = F_26 ( V_28 -> V_95 ) ;
if ( V_110 > 127 ) {
F_7 ( V_8 -> V_22 , L_12 , V_110 ) ;
return - V_87 ;
}
if ( V_8 -> V_99 == V_100 ) {
F_7 ( V_8 -> V_22 , L_13 ) ;
return - V_87 ;
}
V_111 = F_32 ( V_8 -> V_112 , V_113 ) ;
V_111 &= ~ ( V_114 ) ;
V_111 |= F_33 ( V_110 ) ;
F_34 ( V_8 -> V_112 , V_113 , V_111 ) ;
if ( V_110 )
V_8 -> V_99 = V_115 ;
else
V_8 -> V_99 = V_116 ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 , struct V_75 * V_28 )
{
int V_18 ;
F_36 ( & V_8 -> V_61 ) ;
V_18 = V_8 -> V_117 -> V_118 ( & V_8 -> V_119 , V_28 ) ;
F_37 ( & V_8 -> V_61 ) ;
return V_18 ;
}
static int F_38 ( struct V_7 * V_8 , struct V_75 * V_28 )
{
T_3 V_120 ;
int V_18 ;
V_8 -> V_121 = false ;
V_120 = F_26 ( V_28 -> V_95 ) ;
switch ( V_8 -> V_99 ) {
case V_116 :
return - V_87 ;
break;
case V_115 :
V_18 = F_35 ( V_8 , V_28 ) ;
if ( V_120 && ( ! V_18 || ( V_18 == V_122 ) ) ) {
V_8 -> V_99 = V_100 ;
V_8 -> V_123 = true ;
F_7 ( V_8 -> V_22 , L_14 ) ;
}
break;
case V_100 :
V_18 = F_35 ( V_8 , V_28 ) ;
if ( ! V_120 )
V_8 -> V_99 = V_115 ;
break;
default:
V_18 = - V_87 ;
}
return V_18 ;
}
static int F_39 ( struct V_7 * V_8 , struct V_75 * V_28 )
{
int V_18 ;
switch ( V_28 -> V_124 ) {
case V_125 :
F_3 ( V_8 -> V_22 , L_15 ) ;
V_18 = F_28 ( V_8 , V_28 ) ;
break;
case V_126 :
F_3 ( V_8 -> V_22 , L_16 ) ;
V_18 = F_30 ( V_8 , V_28 , 0 ) ;
break;
case V_127 :
F_3 ( V_8 -> V_22 , L_17 ) ;
V_18 = F_30 ( V_8 , V_28 , 1 ) ;
break;
case V_128 :
F_3 ( V_8 -> V_22 , L_18 ) ;
V_18 = F_31 ( V_8 , V_28 ) ;
break;
case V_129 :
F_3 ( V_8 -> V_22 , L_19 ) ;
V_18 = F_38 ( V_8 , V_28 ) ;
break;
default:
F_3 ( V_8 -> V_22 , L_20 ) ;
V_18 = F_35 ( V_8 , V_28 ) ;
break;
} ;
return V_18 ;
}
static void F_40 ( struct V_7 * V_8 ,
const struct V_130 * V_131 )
{
struct V_75 * V_28 = V_8 -> V_132 ;
int V_18 ;
T_3 V_11 ;
if ( ! V_8 -> V_117 )
goto V_133;
V_11 = F_26 ( V_28 -> V_134 ) ;
if ( ! V_11 ) {
V_8 -> V_135 = false ;
V_8 -> V_136 = false ;
V_8 -> V_39 = V_137 ;
} else {
V_8 -> V_135 = true ;
V_8 -> V_136 = ! ! ( V_28 -> V_79 & V_74 ) ;
V_8 -> V_39 = V_138 ;
}
if ( ( V_28 -> V_79 & V_139 ) == V_140 )
V_18 = F_39 ( V_8 , V_28 ) ;
else
V_18 = F_35 ( V_8 , V_28 ) ;
if ( V_18 == V_122 )
V_8 -> V_56 = true ;
if ( V_18 >= 0 )
return;
V_133:
F_19 ( V_8 ) ;
}
static void F_41 ( struct V_7 * V_8 ,
const struct V_130 * V_131 )
{
struct V_41 * V_141 = NULL ;
struct V_59 * V_142 ;
struct V_14 * V_15 ;
struct V_16 * V_143 ;
T_3 V_144 ;
T_3 V_54 ;
T_1 V_9 ;
V_9 = V_131 -> V_145 ;
V_143 = V_8 -> V_19 [ 0 ] ;
V_8 -> V_39 = V_137 ;
V_141 = F_21 ( & V_143 -> V_48 ) ;
V_142 = & V_141 -> V_43 ;
V_15 = V_8 -> V_24 ;
V_54 = V_15 -> V_27 & V_146 ;
if ( V_8 -> V_147 ) {
unsigned V_148 = V_142 -> V_54 ;
unsigned V_149 = V_143 -> V_150 . V_151 ;
V_148 += ( V_149 - ( V_148 % V_149 ) ) ;
V_144 = F_42 ( T_3 , V_142 -> V_54 ,
V_148 - V_54 ) ;
memcpy ( V_142 -> V_92 , V_8 -> V_152 , V_144 ) ;
V_8 -> V_147 = false ;
} else {
V_144 = V_142 -> V_54 - V_54 ;
}
V_142 -> V_44 += V_144 ;
if ( ( V_9 & 1 ) && V_142 -> V_44 < V_142 -> V_54 ) {
F_19 ( V_8 ) ;
} else {
if ( V_141 )
F_22 ( V_143 , V_141 , 0 ) ;
}
}
static void F_43 ( struct V_7 * V_8 ,
const struct V_130 * V_131 )
{
struct V_41 * V_141 ;
struct V_16 * V_17 ;
V_17 = V_8 -> V_19 [ 0 ] ;
if ( ! F_17 ( & V_17 -> V_48 ) ) {
V_141 = F_21 ( & V_17 -> V_48 ) ;
F_22 ( V_17 , V_141 , 0 ) ;
}
if ( V_8 -> V_106 ) {
int V_18 ;
V_18 = F_44 ( V_8 , V_8 -> V_105 ) ;
if ( V_18 < 0 ) {
F_7 ( V_8 -> V_22 , L_21 ,
V_8 -> V_105 ) ;
F_19 ( V_8 ) ;
}
}
V_8 -> V_52 = V_4 ;
F_23 ( V_8 ) ;
}
static void F_45 ( struct V_7 * V_8 ,
const struct V_130 * V_131 )
{
struct V_16 * V_17 = V_8 -> V_19 [ V_131 -> V_145 ] ;
V_17 -> V_20 &= ~ V_21 ;
V_17 -> V_38 = 0 ;
V_8 -> V_153 = false ;
switch ( V_8 -> V_52 ) {
case V_4 :
F_3 ( V_8 -> V_22 , L_22 ) ;
F_40 ( V_8 , V_131 ) ;
break;
case V_5 :
F_3 ( V_8 -> V_22 , L_23 ) ;
F_41 ( V_8 , V_131 ) ;
break;
case V_6 :
F_3 ( V_8 -> V_22 , L_24 ) ;
F_43 ( V_8 , V_131 ) ;
break;
default:
F_46 ( true , L_25 , V_8 -> V_52 ) ;
}
}
static void F_47 ( struct V_7 * V_8 ,
const struct V_130 * V_131 )
{
F_23 ( V_8 ) ;
}
static void F_48 ( struct V_7 * V_8 ,
const struct V_130 * V_131 )
{
struct V_16 * V_17 ;
struct V_41 * V_42 ;
int V_18 ;
V_17 = V_8 -> V_19 [ 0 ] ;
if ( F_17 ( & V_17 -> V_48 ) ) {
F_3 ( V_8 -> V_22 , L_26 ) ;
V_17 -> V_20 |= V_49 ;
if ( V_131 -> V_145 )
V_17 -> V_20 |= V_51 ;
return;
}
V_42 = F_21 ( & V_17 -> V_48 ) ;
V_42 -> V_50 = ! ! V_131 -> V_145 ;
if ( V_42 -> V_43 . V_54 == 0 ) {
V_18 = F_2 ( V_8 , V_131 -> V_145 ,
V_8 -> V_68 , 0 ,
V_55 ) ;
} else if ( ( V_42 -> V_43 . V_54 % V_17 -> V_150 . V_151 )
&& ( V_131 -> V_145 == 0 ) ) {
V_18 = F_49 ( & V_8 -> V_119 , & V_42 -> V_43 ,
V_131 -> V_145 ) ;
if ( V_18 ) {
F_7 ( V_8 -> V_22 , L_27 ) ;
return;
}
F_24 ( V_42 -> V_43 . V_54 > V_17 -> V_150 . V_151 ) ;
V_8 -> V_147 = true ;
V_18 = F_2 ( V_8 , V_131 -> V_145 ,
V_8 -> V_154 , V_17 -> V_150 . V_151 ,
V_55 ) ;
} else {
V_18 = F_49 ( & V_8 -> V_119 , & V_42 -> V_43 ,
V_131 -> V_145 ) ;
if ( V_18 ) {
F_7 ( V_8 -> V_22 , L_27 ) ;
return;
}
V_18 = F_2 ( V_8 , V_131 -> V_145 ,
V_42 -> V_43 . V_53 , V_42 -> V_43 . V_54 ,
V_55 ) ;
}
F_24 ( V_18 < 0 ) ;
}
static int F_50 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_8 ;
T_3 type ;
type = V_8 -> V_135 ? V_155
: V_156 ;
return F_2 ( V_8 , V_17 -> V_36 ,
V_8 -> V_68 , 0 , type ) ;
}
static void F_12 ( struct V_7 * V_8 , T_3 V_9 )
{
struct V_16 * V_17 = V_8 -> V_19 [ V_9 ] ;
if ( V_8 -> V_123 ) {
F_7 ( V_8 -> V_22 , L_28 ) ;
F_51 ( V_8 ) ;
V_8 -> V_123 = 0 ;
}
F_24 ( F_50 ( V_17 ) ) ;
}
static void F_52 ( struct V_7 * V_8 ,
const struct V_130 * V_131 )
{
V_8 -> V_153 = true ;
if ( V_8 -> V_39 == V_40 ) {
switch ( V_131 -> V_45 ) {
case V_157 :
F_3 ( V_8 -> V_22 , L_29 ) ;
F_19 ( V_8 ) ;
break;
case V_158 :
case V_159 :
default:
F_3 ( V_8 -> V_22 , L_30 ) ;
}
return;
}
switch ( V_131 -> V_45 ) {
case V_157 :
F_3 ( V_8 -> V_22 , L_31 ) ;
V_8 -> V_52 = V_4 ;
F_47 ( V_8 , V_131 ) ;
break;
case V_158 :
F_3 ( V_8 -> V_22 , L_32 ) ;
V_8 -> V_52 = V_5 ;
if ( V_8 -> V_39 != V_138 ) {
F_3 ( V_8 -> V_22 , L_33 ,
V_8 -> V_39 ,
V_138 ) ;
F_19 ( V_8 ) ;
return;
}
if ( V_8 -> V_136 != V_131 -> V_145 ) {
F_3 ( V_8 -> V_22 , L_34 ) ;
F_19 ( V_8 ) ;
return;
}
F_48 ( V_8 , V_131 ) ;
break;
case V_159 :
F_3 ( V_8 -> V_22 , L_35 ) ;
V_8 -> V_52 = V_6 ;
if ( V_8 -> V_39 != V_137 ) {
F_3 ( V_8 -> V_22 , L_33 ,
V_8 -> V_39 ,
V_137 ) ;
F_19 ( V_8 ) ;
return;
}
if ( V_8 -> V_56 ) {
F_53 ( V_131 -> V_145 != 1 ) ;
F_3 ( V_8 -> V_22 , L_36 ) ;
return;
}
F_12 ( V_8 , V_131 -> V_145 ) ;
}
}
void F_54 ( struct V_7 * V_8 ,
const struct V_130 * V_131 )
{
T_1 V_9 = V_131 -> V_145 ;
F_7 ( V_8 -> V_22 , L_37 ,
F_55 ( V_131 -> V_160 ) ,
V_9 >> 1 , ( V_9 & 1 ) ? L_38 : L_39 ,
F_1 ( V_8 -> V_52 ) ) ;
switch ( V_131 -> V_160 ) {
case V_161 :
F_45 ( V_8 , V_131 ) ;
break;
case V_162 :
F_52 ( V_8 , V_131 ) ;
break;
case V_163 :
case V_164 :
case V_165 :
case V_166 :
break;
}
}
