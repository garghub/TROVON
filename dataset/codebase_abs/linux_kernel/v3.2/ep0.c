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
int V_20 = 0 ;
V_43 -> V_44 . V_45 = 0 ;
V_43 -> V_44 . V_46 = - V_47 ;
V_43 -> V_9 = V_19 -> V_37 ;
F_11 ( & V_43 -> V_48 , & V_19 -> V_49 ) ;
if ( V_19 -> V_22 & V_50 ) {
struct V_7 * V_8 = V_19 -> V_8 ;
unsigned V_51 ;
T_3 type ;
V_51 = ! ! ( V_19 -> V_22 & V_52 ) ;
if ( V_8 -> V_53 == V_6 ) {
type = V_8 -> V_54
? V_55
: V_56 ;
} else if ( V_8 -> V_53 == V_5 ) {
type = V_57 ;
} else {
F_12 ( 1 ) ;
return 0 ;
}
V_20 = F_2 ( V_8 , V_51 ,
V_43 -> V_44 . V_58 , V_43 -> V_44 . V_29 , type ) ;
V_19 -> V_22 &= ~ ( V_50 |
V_52 ) ;
}
return V_20 ;
}
int F_13 ( struct V_59 * V_60 , struct V_61 * V_44 ,
T_4 V_62 )
{
struct V_42 * V_43 = F_14 ( V_44 ) ;
struct V_18 * V_19 = F_15 ( V_60 ) ;
struct V_7 * V_8 = V_19 -> V_8 ;
unsigned long V_22 ;
int V_20 ;
F_16 ( & V_8 -> V_63 , V_22 ) ;
if ( ! V_19 -> V_64 ) {
F_8 ( V_8 -> V_24 , L_8 ,
V_44 , V_19 -> V_25 ) ;
V_20 = - V_65 ;
goto V_66;
}
if ( ! F_17 ( & V_8 -> V_21 [ 0 ] -> V_49 ) ||
! F_17 ( & V_8 -> V_21 [ 1 ] -> V_49 ) ||
V_8 -> V_67 ) {
V_20 = - V_68 ;
goto V_66;
}
F_3 ( V_8 -> V_24 , L_9 ,
V_44 , V_19 -> V_25 , V_44 -> V_29 ,
F_1 ( V_8 -> V_53 ) ) ;
V_20 = F_10 ( V_19 , V_43 ) ;
V_66:
F_18 ( & V_8 -> V_63 , V_22 ) ;
return V_20 ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = V_8 -> V_21 [ 0 ] ;
F_20 ( V_8 -> V_21 [ 0 ] , 1 ) ;
V_8 -> V_21 [ 0 ] -> V_22 = V_69 ;
if ( ! F_17 ( & V_19 -> V_49 ) ) {
struct V_42 * V_43 ;
V_43 = F_21 ( & V_19 -> V_49 ) ;
F_22 ( V_19 , V_43 , - V_70 ) ;
}
V_8 -> V_53 = V_4 ;
F_23 ( V_8 ) ;
}
void F_23 ( struct V_7 * V_8 )
{
int V_20 ;
V_20 = F_2 ( V_8 , 0 , V_8 -> V_71 , 8 ,
V_72 ) ;
F_12 ( V_20 < 0 ) ;
}
static struct V_18 * F_24 ( struct V_7 * V_8 , T_5 V_73 )
{
struct V_18 * V_19 ;
T_3 V_74 = F_25 ( V_73 ) ;
T_3 V_9 ;
V_9 = ( V_74 & V_75 ) << 1 ;
if ( ( V_74 & V_76 ) == V_77 )
V_9 |= 1 ;
V_19 = V_8 -> V_21 [ V_9 ] ;
if ( V_19 -> V_22 & V_69 )
return V_19 ;
return NULL ;
}
static void F_26 ( struct V_7 * V_8 )
{
F_2 ( V_8 , 1 , V_8 -> V_78 ,
V_8 -> V_79 . V_29 ,
V_57 ) ;
}
static int F_27 ( struct V_7 * V_8 , struct V_80 * V_81 )
{
struct V_18 * V_19 ;
T_3 V_82 ;
T_6 V_83 = 0 ;
T_5 * V_84 ;
V_82 = V_81 -> V_85 & V_86 ;
switch ( V_82 ) {
case V_87 :
V_83 |= V_8 -> V_88 << V_89 ;
break;
case V_90 :
break;
case V_91 :
V_19 = F_24 ( V_8 , V_81 -> V_92 ) ;
if ( ! V_19 )
return - V_93 ;
if ( V_19 -> V_22 & V_94 )
V_83 = 1 << V_95 ;
break;
default:
return - V_93 ;
} ;
V_84 = ( T_5 * ) V_8 -> V_96 ;
* V_84 = F_28 ( V_83 ) ;
V_8 -> V_79 . V_29 = sizeof( * V_84 ) ;
V_8 -> V_67 = 1 ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 ,
struct V_80 * V_81 , int V_97 )
{
struct V_18 * V_19 ;
T_3 V_82 ;
T_3 V_98 ;
T_3 V_92 ;
T_3 V_99 ;
int V_20 ;
T_3 V_100 ;
V_98 = F_25 ( V_81 -> V_98 ) ;
V_92 = F_25 ( V_81 -> V_92 ) ;
V_82 = V_81 -> V_85 & V_86 ;
switch ( V_82 ) {
case V_87 :
switch ( V_98 ) {
case V_101 :
case V_102 :
case V_103 :
if ( V_8 -> V_104 != V_105 )
return - V_93 ;
if ( V_8 -> V_106 != V_107 )
return - V_93 ;
}
switch ( V_98 ) {
case V_108 :
break;
case V_101 :
break;
case V_102 :
break;
case V_103 :
break;
case V_109 :
if ( ( V_92 & 0xff ) != 0 )
return - V_93 ;
if ( ! V_97 )
return - V_93 ;
V_100 = V_92 >> 8 ;
V_99 = F_30 ( V_8 -> V_110 , V_111 ) ;
V_99 &= ~ V_112 ;
switch ( V_100 ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_99 |= V_100 << 1 ;
break;
default:
return - V_93 ;
}
F_31 ( V_8 -> V_110 , V_111 , V_99 ) ;
break;
default:
return - V_93 ;
}
break;
case V_90 :
switch ( V_98 ) {
case V_118 :
if ( V_92 & V_119 )
;
if ( V_92 & V_120 )
;
break;
default:
return - V_93 ;
}
break;
case V_91 :
switch ( V_98 ) {
case V_95 :
V_19 = F_24 ( V_8 , V_81 -> V_92 ) ;
if ( ! V_19 )
return - V_93 ;
V_20 = F_20 ( V_19 , V_97 ) ;
if ( V_20 )
return - V_93 ;
break;
default:
return - V_93 ;
}
break;
default:
return - V_93 ;
} ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 , struct V_80 * V_81 )
{
T_3 V_121 ;
T_3 V_99 ;
V_121 = F_25 ( V_81 -> V_98 ) ;
if ( V_121 > 127 )
return - V_93 ;
V_99 = F_30 ( V_8 -> V_110 , V_122 ) ;
V_99 &= ~ ( V_123 ) ;
V_99 |= F_33 ( V_121 ) ;
F_31 ( V_8 -> V_110 , V_122 , V_99 ) ;
if ( V_121 )
V_8 -> V_104 = V_124 ;
else
V_8 -> V_104 = V_125 ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 , struct V_80 * V_81 )
{
int V_20 ;
F_35 ( & V_8 -> V_63 ) ;
V_20 = V_8 -> V_126 -> V_127 ( & V_8 -> V_128 , V_81 ) ;
F_36 ( & V_8 -> V_63 ) ;
return V_20 ;
}
static int F_37 ( struct V_7 * V_8 , struct V_80 * V_81 )
{
T_3 V_129 ;
int V_20 ;
V_8 -> V_130 = false ;
V_129 = F_25 ( V_81 -> V_98 ) ;
switch ( V_8 -> V_104 ) {
case V_125 :
return - V_93 ;
break;
case V_124 :
V_20 = F_34 ( V_8 , V_81 ) ;
if ( ! V_20 && V_129 )
V_8 -> V_104 = V_105 ;
break;
case V_105 :
V_20 = F_34 ( V_8 , V_81 ) ;
if ( ! V_129 )
V_8 -> V_104 = V_124 ;
break;
}
return 0 ;
}
static int F_38 ( struct V_7 * V_8 , struct V_80 * V_81 )
{
int V_20 ;
switch ( V_81 -> V_131 ) {
case V_132 :
F_3 ( V_8 -> V_24 , L_10 ) ;
V_20 = F_27 ( V_8 , V_81 ) ;
break;
case V_133 :
F_3 ( V_8 -> V_24 , L_11 ) ;
V_20 = F_29 ( V_8 , V_81 , 0 ) ;
break;
case V_134 :
F_3 ( V_8 -> V_24 , L_12 ) ;
V_20 = F_29 ( V_8 , V_81 , 1 ) ;
break;
case V_135 :
F_3 ( V_8 -> V_24 , L_13 ) ;
V_20 = F_32 ( V_8 , V_81 ) ;
break;
case V_136 :
F_3 ( V_8 -> V_24 , L_14 ) ;
V_20 = F_37 ( V_8 , V_81 ) ;
break;
default:
F_3 ( V_8 -> V_24 , L_15 ) ;
V_20 = F_34 ( V_8 , V_81 ) ;
break;
} ;
return V_20 ;
}
static void F_39 ( struct V_7 * V_8 ,
const struct V_137 * V_138 )
{
struct V_80 * V_81 = V_8 -> V_139 ;
int V_20 ;
T_3 V_11 ;
if ( ! V_8 -> V_126 )
goto V_140;
V_11 = F_25 ( V_81 -> V_141 ) ;
if ( ! V_11 ) {
V_8 -> V_54 = false ;
V_8 -> V_142 = false ;
V_8 -> V_40 = V_143 ;
} else {
V_8 -> V_54 = true ;
V_8 -> V_142 = ! ! ( V_81 -> V_85 & V_77 ) ;
V_8 -> V_40 = V_144 ;
}
if ( ( V_81 -> V_85 & V_145 ) == V_146 )
V_20 = F_38 ( V_8 , V_81 ) ;
else
V_20 = F_34 ( V_8 , V_81 ) ;
if ( V_20 >= 0 )
return;
V_140:
F_19 ( V_8 ) ;
}
static void F_40 ( struct V_7 * V_8 ,
const struct V_137 * V_138 )
{
struct V_42 * V_147 = NULL ;
struct V_61 * V_148 ;
struct V_16 V_17 ;
struct V_18 * V_19 ;
T_3 V_149 ;
T_1 V_9 ;
V_9 = V_138 -> V_150 ;
V_19 = V_8 -> V_21 [ V_9 ] ;
V_8 -> V_40 = V_143 ;
if ( ! V_8 -> V_67 ) {
V_147 = F_21 ( & V_8 -> V_21 [ 0 ] -> V_49 ) ;
V_148 = & V_147 -> V_44 ;
} else {
V_148 = & V_8 -> V_79 ;
V_8 -> V_67 = 0 ;
}
F_41 ( V_8 -> V_26 , & V_17 ) ;
if ( V_8 -> V_151 ) {
struct V_18 * V_152 = V_8 -> V_21 [ 0 ] ;
V_149 = F_42 ( T_3 , V_148 -> V_29 ,
V_152 -> V_153 . V_154 - V_17 . V_29 ) ;
memcpy ( V_148 -> V_155 , V_8 -> V_156 , V_149 ) ;
V_8 -> V_151 = false ;
} else {
V_149 = V_148 -> V_29 - V_17 . V_29 ;
V_148 -> V_45 += V_149 ;
}
if ( ( V_9 & 1 ) && V_148 -> V_45 < V_148 -> V_29 ) {
F_19 ( V_8 ) ;
} else {
if ( V_147 )
F_22 ( V_19 , V_147 , 0 ) ;
}
}
static void F_43 ( struct V_7 * V_8 ,
const struct V_137 * V_138 )
{
struct V_42 * V_147 ;
struct V_18 * V_19 ;
V_19 = V_8 -> V_21 [ 0 ] ;
if ( ! F_17 ( & V_19 -> V_49 ) ) {
V_147 = F_21 ( & V_19 -> V_49 ) ;
F_22 ( V_19 , V_147 , 0 ) ;
}
V_8 -> V_53 = V_4 ;
F_23 ( V_8 ) ;
}
static void F_44 ( struct V_7 * V_8 ,
const struct V_137 * V_138 )
{
struct V_18 * V_19 = V_8 -> V_21 [ V_138 -> V_150 ] ;
V_19 -> V_22 &= ~ V_23 ;
switch ( V_8 -> V_53 ) {
case V_4 :
F_3 ( V_8 -> V_24 , L_16 ) ;
F_39 ( V_8 , V_138 ) ;
break;
case V_5 :
F_3 ( V_8 -> V_24 , L_17 ) ;
F_40 ( V_8 , V_138 ) ;
break;
case V_6 :
F_3 ( V_8 -> V_24 , L_18 ) ;
F_43 ( V_8 , V_138 ) ;
break;
default:
F_45 ( true , L_19 , V_8 -> V_53 ) ;
}
}
static void F_46 ( struct V_7 * V_8 ,
const struct V_137 * V_138 )
{
V_8 -> V_53 = V_4 ;
F_23 ( V_8 ) ;
}
static void F_47 ( struct V_7 * V_8 ,
const struct V_137 * V_138 )
{
struct V_18 * V_19 ;
struct V_42 * V_43 ;
int V_20 ;
V_19 = V_8 -> V_21 [ 0 ] ;
V_8 -> V_53 = V_5 ;
if ( V_8 -> V_67 ) {
F_26 ( V_8 ) ;
return;
}
if ( F_17 ( & V_19 -> V_49 ) ) {
F_3 ( V_8 -> V_24 , L_20 ) ;
V_19 -> V_22 |= V_50 ;
if ( V_138 -> V_150 )
V_19 -> V_22 |= V_52 ;
return;
}
V_43 = F_21 ( & V_19 -> V_49 ) ;
V_43 -> V_51 = ! ! V_138 -> V_150 ;
V_8 -> V_53 = V_5 ;
if ( V_43 -> V_44 . V_29 == 0 ) {
V_20 = F_2 ( V_8 , V_138 -> V_150 ,
V_8 -> V_71 , 0 ,
V_57 ) ;
} else if ( ( V_43 -> V_44 . V_29 % V_19 -> V_153 . V_154 )
&& ( V_138 -> V_150 == 0 ) ) {
F_48 ( V_43 ) ;
F_12 ( V_43 -> V_44 . V_29 > V_19 -> V_153 . V_154 ) ;
V_8 -> V_151 = true ;
V_20 = F_2 ( V_8 , V_138 -> V_150 ,
V_8 -> V_157 , V_19 -> V_153 . V_154 ,
V_57 ) ;
} else {
F_48 ( V_43 ) ;
V_20 = F_2 ( V_8 , V_138 -> V_150 ,
V_43 -> V_44 . V_58 , V_43 -> V_44 . V_29 ,
V_57 ) ;
}
F_12 ( V_20 < 0 ) ;
}
static void F_49 ( struct V_7 * V_8 ,
const struct V_137 * V_138 )
{
T_3 type ;
int V_20 ;
V_8 -> V_53 = V_6 ;
type = V_8 -> V_54 ? V_55
: V_56 ;
V_20 = F_2 ( V_8 , V_138 -> V_150 ,
V_8 -> V_71 , 0 , type ) ;
F_12 ( V_20 < 0 ) ;
}
static void F_50 ( struct V_7 * V_8 ,
const struct V_137 * V_138 )
{
switch ( V_138 -> V_46 ) {
case V_158 :
F_3 ( V_8 -> V_24 , L_21 ) ;
F_46 ( V_8 , V_138 ) ;
break;
case V_159 :
F_3 ( V_8 -> V_24 , L_22 ) ;
if ( V_8 -> V_40 != V_144 ) {
F_3 ( V_8 -> V_24 , L_23 ,
V_8 -> V_40 ,
V_144 ) ;
F_19 ( V_8 ) ;
return;
}
if ( V_8 -> V_142 != V_138 -> V_150 ) {
F_3 ( V_8 -> V_24 , L_24 ) ;
F_19 ( V_8 ) ;
return;
}
F_47 ( V_8 , V_138 ) ;
break;
case V_160 :
F_3 ( V_8 -> V_24 , L_25 ) ;
if ( V_8 -> V_40 != V_143 ) {
F_3 ( V_8 -> V_24 , L_23 ,
V_8 -> V_40 ,
V_143 ) ;
F_19 ( V_8 ) ;
return;
}
F_49 ( V_8 , V_138 ) ;
}
}
void F_51 ( struct V_7 * V_8 ,
const const struct V_137 * V_138 )
{
T_1 V_9 = V_138 -> V_150 ;
F_8 ( V_8 -> V_24 , L_26 ,
F_52 ( V_138 -> V_161 ) ,
V_9 >> 1 , ( V_9 & 1 ) ? L_27 : L_28 ,
F_1 ( V_8 -> V_53 ) ) ;
switch ( V_138 -> V_161 ) {
case V_162 :
F_44 ( V_8 , V_138 ) ;
break;
case V_163 :
F_50 ( V_8 , V_138 ) ;
break;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
break;
}
}
