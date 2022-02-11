static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = V_5 | F_2 ( V_3 ) ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_1 , V_4 ) ;
V_6 = F_4 ( V_2 -> V_8 , & V_4 , 1 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_2 , V_9 , V_4 ,
V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_10 , T_1 * V_11 )
{
T_1 V_12 = V_13 | V_10 ;
int V_6 ;
V_6 = F_7 ( V_2 -> V_8 , & V_12 , 1 , V_11 , 1 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_3 , V_9 , V_12 ,
V_6 ) ;
F_3 ( V_2 -> V_7 , L_4 , V_12 , * V_11 ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_10 , T_1 * V_14 , T_2 V_15 )
{
T_1 V_12 = V_10 | V_13 | V_16 ;
struct V_17 V_18 [ 2 ] ;
struct V_19 V_20 ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_5 , V_12 , V_15 ) ;
F_9 ( & V_20 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 0 ] . V_21 = & V_12 ;
V_18 [ 0 ] . V_15 = sizeof( V_12 ) ;
F_10 ( & V_18 [ 0 ] , & V_20 ) ;
V_18 [ 1 ] . V_22 = V_14 ;
V_18 [ 1 ] . V_15 = V_15 ;
F_10 ( & V_18 [ 1 ] , & V_20 ) ;
V_6 = F_11 ( V_2 -> V_8 , & V_20 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_3 , V_9 , V_12 ,
V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 )
{
T_1 V_14 [ 2 ] = { V_10 , V_11 } ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_6 , V_10 , V_11 ) ;
V_6 = F_4 ( V_2 -> V_8 , V_14 , 2 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_7 , V_9 ,
V_14 [ 0 ] , V_14 [ 1 ] , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_23 )
{
int V_6 ;
T_1 V_14 [ 2 ] ;
T_1 V_12 ;
V_12 = V_24 | V_13 ;
if ( V_2 -> V_25 & V_26 ) {
V_12 |= V_16 ;
V_6 = F_7 ( V_2 -> V_8 , & V_12 , 1 , V_14 , 2 ) ;
} else {
V_6 = F_7 ( V_2 -> V_8 , & V_12 , 1 , V_14 , 1 ) ;
}
if ( V_6 )
F_5 ( V_2 -> V_7 , L_8 ,
V_9 , V_6 ) ;
else
* V_23 = V_14 [ 0 ] ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_27 )
{
int V_6 ;
T_1 V_14 [ 2 ] ;
T_1 V_12 ;
V_12 = V_28 | V_13 |
V_16 ;
V_6 = F_7 ( V_2 -> V_8 , & V_12 , 1 , V_14 , 2 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_9 ,
V_9 , V_6 ) ;
else
* V_27 = V_14 [ 0 ] ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_29 )
{
int V_6 ;
T_1 V_27 , V_30 ;
V_6 = F_14 ( V_2 , & V_27 ) ;
if ( V_6 )
return V_6 ;
switch ( V_27 ) {
case V_31 :
V_30 = V_32 ;
break;
case V_33 :
V_30 = V_34 ;
break;
case V_35 :
V_30 = V_36 ;
break;
case V_37 :
V_30 = V_38 ;
break;
default:
F_3 ( V_2 -> V_7 , L_10 ,
V_9 , V_27 ) ;
return - V_39 ;
}
* V_29 = V_30 ;
return V_6 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
if ( V_2 -> V_41 && ! F_18 ( V_2 -> V_41 ) && ! V_2 -> V_42 )
F_19 ( L_11 , V_43 ,
16 , 1 , V_2 -> V_41 -> V_44 , V_2 -> V_41 -> V_15 ,
false ) ;
V_2 -> V_45 = V_46 ;
if ( V_2 -> V_42 ) {
F_3 ( V_2 -> V_7 , L_12 ) ;
if ( ! F_18 ( V_2 -> V_41 ) ) {
F_20 ( V_2 -> V_41 ) ;
V_2 -> V_41 = F_21 ( - V_47 ) ;
}
V_2 -> V_42 = false ;
}
V_2 -> V_48 ( V_2 -> V_49 , V_2 -> V_50 , V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
static void F_22 ( struct V_1 * V_2 , int V_51 )
{
F_3 ( V_2 -> V_7 , L_13 , V_2 -> V_45 , V_51 ) ;
F_23 ( & V_2 -> V_52 ) ;
F_20 ( V_2 -> V_41 ) ;
V_2 -> V_41 = F_21 ( V_51 ) ;
F_16 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_53 * V_54 ,
unsigned int V_15 , T_1 * V_55 , unsigned int V_56 )
{
struct V_17 V_18 [ 2 ] ;
struct V_19 V_20 ;
unsigned int V_57 ;
int V_6 ;
F_19 ( L_14 , V_43 ,
16 , 1 , V_54 -> V_44 , V_15 , false ) ;
F_9 ( & V_20 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 0 ] . V_21 = V_55 ;
V_18 [ 0 ] . V_15 = V_56 ;
F_10 ( & V_18 [ 0 ] , & V_20 ) ;
V_18 [ 1 ] . V_21 = V_54 -> V_44 ;
V_18 [ 1 ] . V_15 = V_15 ;
F_10 ( & V_18 [ 1 ] , & V_20 ) ;
V_6 = F_11 ( V_2 -> V_8 , & V_20 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_15 , V_9 ,
V_6 ) ;
return V_6 ;
}
F_25 ( V_54 , V_15 ) ;
if ( V_54 -> V_15 > 0 ) {
V_2 -> V_45 = V_58 ;
V_57 = V_59 ;
} else {
if ( V_2 -> V_60 ) {
V_2 -> V_45 = V_61 ;
V_57 = V_62 ;
} else {
V_2 -> V_45 = V_63 ;
if ( ! V_2 -> V_57 )
V_57 = V_64 ;
else
V_57 = V_2 -> V_57 ;
}
}
F_3 ( V_2 -> V_7 , L_16 , V_57 ,
V_2 -> V_45 ) ;
F_26 ( & V_2 -> V_52 , F_27 ( V_57 ) ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_40 ;
unsigned int V_15 ;
int V_6 ;
T_1 V_65 ;
T_1 V_55 ;
V_6 = F_6 ( V_2 , V_66 , & V_65 ) ;
if ( V_6 ) {
F_22 ( V_2 , V_6 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_17 , V_65 ) ;
V_65 &= ~ V_67 ;
V_15 = V_68 - V_65 ;
if ( ! V_15 ) {
F_26 ( & V_2 -> V_52 ,
F_27 ( V_59 ) ) ;
return;
}
V_15 = F_29 ( V_54 -> V_15 , V_15 ) ;
V_55 = V_16 | V_69 ;
V_6 = F_24 ( V_2 , V_54 , V_15 , & V_55 , sizeof( V_55 ) ) ;
if ( V_6 )
F_22 ( V_2 , V_6 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_53 * V_54 = V_2 -> V_41 ;
int V_6 ;
T_1 V_65 ;
if ( V_23 & V_70 ) {
F_22 ( V_2 , - V_39 ) ;
return;
}
V_6 = F_6 ( V_2 , V_66 , & V_65 ) ;
if ( V_6 ) {
F_22 ( V_2 , V_6 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_18 , V_65 ) ;
V_65 &= ~ V_67 ;
if ( ! V_65 )
goto V_71;
if ( V_65 > F_31 ( V_54 ) ) {
V_54 = F_32 ( V_54 , F_33 ( V_54 ) ,
F_34 ( int , V_65 ,
V_72 ) ,
V_73 ) ;
if ( ! V_54 ) {
F_22 ( V_2 , - V_74 ) ;
return;
}
F_20 ( V_2 -> V_41 ) ;
V_2 -> V_41 = V_54 ;
}
V_6 = F_8 ( V_2 , V_69 ,
F_35 ( V_54 , V_65 ) , V_65 ) ;
if ( V_6 ) {
F_22 ( V_2 , V_6 ) ;
return;
}
if ( ( V_2 -> V_75 == V_76 ) && ( V_54 -> V_15 == 1 ) &&
( V_2 -> V_77 ==
V_78 ) ) {
V_54 -> V_44 [ 0 ] >>= 4 ;
V_23 = V_79 ;
} else {
V_2 -> V_45 = V_80 ;
V_6 = F_6 ( V_2 , V_66 , & V_65 ) ;
if ( V_6 ) {
F_22 ( V_2 , V_6 ) ;
return;
}
V_65 &= ~ V_67 ;
if ( V_65 )
V_23 = 0 ;
}
V_71:
if ( V_23 == V_79 ) {
F_16 ( V_2 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_19 ,
V_81 ) ;
F_26 ( & V_2 -> V_52 ,
F_27 ( V_81 ) ) ;
}
static T_3 F_36 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
int V_6 ;
T_1 V_23 , V_65 , V_84 ;
F_37 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_45 == V_86 ) {
F_38 ( & V_2 -> V_85 ) ;
return V_87 ;
}
V_6 = F_13 ( V_2 , & V_23 ) ;
if ( V_6 ) {
F_38 ( & V_2 -> V_85 ) ;
return V_87 ;
}
F_3 ( V_2 -> V_7 , L_20 , V_2 -> V_45 ,
V_23 ) ;
if ( ! V_23 ) {
F_38 ( & V_2 -> V_85 ) ;
return V_87 ;
}
switch ( V_2 -> V_45 ) {
case V_46 :
case V_88 :
if ( V_2 -> V_89 && ( V_23 & V_70 ) ) {
F_1 ( V_2 , V_90 ) ;
V_2 -> V_45 = V_88 ;
}
F_1 ( V_2 , V_91 ) ;
break;
case V_58 :
if ( V_23 & V_92 ) {
V_2 -> V_93 =
! F_23 ( & V_2 -> V_52 ) ;
F_28 ( V_2 ) ;
} else {
F_22 ( V_2 , - V_39 ) ;
}
break;
case V_63 :
case V_80 :
if ( V_23 & V_79 ) {
V_2 -> V_93 =
! F_23 ( & V_2 -> V_52 ) ;
F_30 ( V_2 , V_23 ) ;
} else if ( V_23 & V_94 ) {
V_6 = F_6 ( V_2 , V_66 ,
& V_65 ) ;
V_65 &= ~ V_67 ;
if ( V_6 )
F_22 ( V_2 , V_6 ) ;
else if ( ! V_65 )
F_1 ( V_2 , V_91 ) ;
} else if ( ( V_23 == V_92 ) ||
( ! V_2 -> V_89 &&
( V_23 == ( V_92 |
V_95 ) ) ) ) {
F_1 ( V_2 , V_91 ) ;
if ( ! V_2 -> V_57 ) {
V_2 -> V_93 = ! F_23 (
& V_2 -> V_52 ) ;
V_2 -> V_41 = F_21 ( 0 ) ;
F_16 ( V_2 ) ;
break;
}
if ( V_2 -> V_89 )
break;
V_84 = V_2 -> V_84 ;
switch ( V_2 -> V_75 ) {
case V_96 :
V_2 -> V_97 = V_98 ;
V_84 |= V_99 ;
V_2 -> V_84 = 0xff ;
break;
case V_100 :
V_2 -> V_97 = V_101 ;
V_84 &= ~ V_99 ;
V_2 -> V_84 = 0xff ;
break;
case V_102 :
V_6 = F_12 ( V_2 ,
V_103 ,
V_104 ) ;
if ( V_6 )
goto V_105;
V_2 -> V_77 =
V_104 ;
break;
default:
break;
}
if ( V_84 != V_2 -> V_84 ) {
V_6 = F_12 ( V_2 , V_106 ,
V_84 ) ;
if ( V_6 )
goto V_105;
V_2 -> V_84 = V_84 ;
}
} else {
F_22 ( V_2 , - V_39 ) ;
}
break;
case V_61 :
if ( V_23 != V_92 )
F_22 ( V_2 , - V_39 ) ;
break;
case V_107 :
if ( V_23 & V_79 ) {
V_2 -> V_93 =
! F_23 ( & V_2 -> V_52 ) ;
F_30 ( V_2 , V_23 ) ;
} else if ( ! ( V_23 & V_95 ) ) {
F_22 ( V_2 , - V_39 ) ;
}
break;
case V_108 :
if ( V_23 & V_79 ) {
V_2 -> V_93 =
! F_23 ( & V_2 -> V_52 ) ;
V_6 = F_15 ( V_2 , & V_2 -> V_109 ) ;
if ( V_6 ) {
F_22 ( V_2 , V_6 ) ;
} else {
V_2 -> V_45 = V_107 ;
F_30 ( V_2 , V_23 ) ;
}
} else if ( ! ( V_23 & V_95 ) ) {
F_22 ( V_2 , - V_39 ) ;
}
break;
default:
F_5 ( V_2 -> V_7 , L_21 ,
V_9 , V_2 -> V_45 ) ;
}
V_105:
F_38 ( & V_2 -> V_85 ) ;
return V_110 ;
}
static void F_39 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_22 ) ;
V_6 = F_1 ( V_2 , V_91 ) ;
if ( V_6 )
F_22 ( V_2 , V_6 ) ;
V_6 = F_1 ( V_2 , V_111 ) ;
if ( V_6 )
F_22 ( V_2 , V_6 ) ;
V_2 -> V_45 = V_63 ;
F_3 ( V_2 -> V_7 , L_16 ,
V_2 -> V_57 , V_2 -> V_45 ) ;
F_26 ( & V_2 -> V_52 ,
F_27 ( V_2 -> V_57 ) ) ;
}
static void F_40 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_41 ( V_113 , struct V_1 ,
V_52 . V_113 ) ;
F_3 ( V_2 -> V_7 , L_23 ,
V_2 -> V_45 , V_2 -> V_93 ) ;
F_37 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_93 )
V_2 -> V_93 = false ;
else if ( V_2 -> V_45 == V_80 )
F_30 ( V_2 , V_79 ) ;
else if ( V_2 -> V_45 == V_61 )
F_39 ( V_2 ) ;
else
F_22 ( V_2 , - V_114 ) ;
F_38 ( & V_2 -> V_85 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_24 , V_2 -> V_45 ) ;
V_6 = F_1 ( V_2 , V_115 ) ;
if ( V_6 )
goto V_116;
V_6 = F_1 ( V_2 , V_117 ) ;
if ( V_6 )
goto V_116;
F_43 ( 1000 , 2000 ) ;
V_2 -> V_118 &= ~ V_119 ;
V_6 = F_12 ( V_2 , V_120 , 0 ) ;
if ( V_6 )
goto V_116;
V_2 -> V_121 = 0 ;
V_6 = F_12 ( V_2 , V_122 ,
V_123 |
V_124 ) ;
if ( V_6 )
goto V_116;
V_6 = F_12 ( V_2 , V_103 , 0 ) ;
if ( V_6 )
goto V_116;
V_2 -> V_77 = 0 ;
V_2 -> V_84 = 0xff ;
return 0 ;
V_116:
F_3 ( V_2 -> V_7 , L_25 , V_6 ) ;
return V_6 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_45 == V_125 ) ||
( V_2 -> V_45 == V_86 ) )
return;
F_3 ( V_2 -> V_7 , L_26 ) ;
V_2 -> V_118 &= ~ V_119 ;
F_12 ( V_2 , V_126 , V_2 -> V_118 ) ;
V_2 -> V_42 = false ;
V_2 -> V_45 = V_86 ;
F_45 ( V_2 -> V_7 ) ;
F_46 ( V_2 -> V_7 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_27 ) ;
F_48 ( V_2 -> V_7 ) ;
if ( V_2 -> V_45 != V_86 ) {
F_5 ( V_2 -> V_7 , L_28 , V_9 ,
V_2 -> V_45 ) ;
return - V_127 ;
}
V_6 = F_42 ( V_2 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_29 , V_9 , V_6 ) ;
return V_6 ;
}
V_2 -> V_45 = V_46 ;
return 0 ;
}
static int F_49 ( struct V_128 * V_49 , bool V_129 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_30 , V_2 -> V_45 , V_129 ) ;
F_37 ( & V_2 -> V_85 ) ;
if ( V_129 ) {
switch ( V_2 -> V_45 ) {
case V_125 :
case V_86 :
V_6 = F_47 ( V_2 ) ;
break;
case V_46 :
case V_88 :
break;
default:
F_5 ( V_2 -> V_7 , L_31 ,
V_9 , V_2 -> V_45 , V_129 ) ;
F_44 ( V_2 ) ;
V_6 = - V_127 ;
}
} else {
switch ( V_2 -> V_45 ) {
case V_125 :
case V_86 :
break;
default:
F_5 ( V_2 -> V_7 , L_31 ,
V_9 , V_2 -> V_45 , V_129 ) ;
V_6 = - V_127 ;
case V_46 :
case V_88 :
case V_63 :
case V_80 :
F_44 ( V_2 ) ;
}
}
F_38 ( & V_2 -> V_85 ) ;
return V_6 ;
}
static int F_51 ( struct V_1 * V_2 , int V_30 )
{
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_32 , V_30 ) ;
switch ( V_30 ) {
case V_32 :
V_2 -> V_130 = V_131 ;
V_2 -> V_121 = V_132 ;
V_2 -> V_133 = V_134 ;
break;
case V_34 :
V_2 -> V_130 = V_135 ;
V_2 -> V_121 = V_136 ;
V_2 -> V_133 = V_137 ;
break;
case V_36 :
V_2 -> V_130 = V_138 ;
V_2 -> V_121 = V_136 ;
V_2 -> V_133 = V_139 ;
break;
case V_38 :
V_2 -> V_130 = V_140 ;
V_2 -> V_121 = V_136 ;
V_2 -> V_133 = V_139 ;
break;
case V_141 :
V_2 -> V_130 = V_142 ;
V_2 -> V_121 = V_132 ;
V_2 -> V_133 = V_143 ;
break;
default:
F_3 ( V_2 -> V_7 , L_33 , V_30 ) ;
return - V_127 ;
}
V_2 -> V_144 = V_30 ;
if ( V_2 -> V_84 == 0xff )
V_6 = F_12 ( V_2 , V_145 , 0 ) ;
return V_6 ;
}
static int F_52 ( struct V_1 * V_2 , bool * V_146 )
{
int V_6 ;
T_1 V_147 ;
V_6 = F_12 ( V_2 , V_126 ,
V_2 -> V_118 | V_148 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_149 ) ;
if ( V_6 )
return V_6 ;
F_43 ( 50 , 60 ) ;
V_6 = F_6 ( V_2 , V_150 , & V_147 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_12 ( V_2 , V_126 ,
V_2 -> V_118 ) ;
if ( V_6 )
return V_6 ;
if ( V_147 & V_151 )
* V_146 = true ;
else
* V_146 = false ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , int V_75 )
{
T_1 V_84 = V_2 -> V_130 ;
bool V_146 = false ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_34 , V_75 ) ;
switch ( V_75 ) {
case V_152 :
case V_96 :
V_2 -> V_97 = V_98 ;
V_84 |= V_99 ;
break;
case V_100 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
V_2 -> V_97 = V_101 ;
V_84 &= ~ V_99 ;
break;
case V_76 :
V_2 -> V_97 = V_101 ;
V_84 |= V_99 ;
break;
default:
F_3 ( V_2 -> V_7 , L_35 , V_75 ) ;
return - V_127 ;
}
V_2 -> V_75 = V_75 ;
if ( ! ( V_2 -> V_118 & V_119 ) ) {
V_6 = F_52 ( V_2 , & V_146 ) ;
if ( V_6 )
return V_6 ;
if ( V_146 )
return - V_162 ;
}
if ( V_84 != V_2 -> V_84 ) {
V_6 = F_12 ( V_2 , V_106 , V_84 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_84 = V_84 ;
V_6 = F_12 ( V_2 , V_120 ,
V_2 -> V_121 ) ;
if ( V_6 )
return V_6 ;
}
if ( ! ( V_2 -> V_118 & V_119 ) ) {
V_6 = F_12 ( V_2 , V_126 ,
V_2 -> V_118 |
V_119 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_118 |= V_119 ;
F_43 ( V_2 -> V_133 , V_2 -> V_133 + 1000 ) ;
}
return 0 ;
}
static int F_54 ( struct V_128 * V_49 , int type ,
int V_163 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_36 , type , V_163 ) ;
F_37 ( & V_2 -> V_85 ) ;
V_2 -> V_89 = true ;
if ( ( V_2 -> V_45 == V_125 ) ||
( V_2 -> V_45 == V_86 ) ) {
V_6 = F_47 ( V_2 ) ;
if ( V_6 )
goto V_164;
}
switch ( type ) {
case V_165 :
V_6 = F_51 ( V_2 , V_163 ) ;
break;
case V_166 :
V_6 = F_53 ( V_2 , V_163 ) ;
break;
default:
F_3 ( V_2 -> V_7 , L_37 , type ) ;
V_6 = - V_127 ;
}
V_164:
F_38 ( & V_2 -> V_85 ) ;
return V_6 ;
}
static int F_55 ( T_1 V_4 )
{
switch ( V_4 ) {
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
return 1 ;
break;
default:
return 0 ;
}
}
static int F_56 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
T_1 * V_174 = V_54 -> V_44 ;
T_1 V_77 , V_84 ;
int V_6 ;
V_2 -> V_60 = false ;
if ( ( V_2 -> V_144 == V_32 ) &&
( V_2 -> V_75 == V_76 ) ) {
if ( V_174 [ 0 ] == V_175 )
V_77 = 0 ;
else
V_77 = V_78 ;
if ( V_77 != V_2 -> V_77 ) {
V_6 = F_12 ( V_2 , V_103 ,
V_77 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_77 = V_77 ;
}
} else if ( V_2 -> V_144 == V_141 ) {
V_84 = V_2 -> V_84 & ~ V_176 ;
switch ( V_174 [ 0 ] & V_177 ) {
case 0x00 :
V_84 |= V_178 ;
break;
case V_179 :
V_84 |= V_180 ;
break;
case V_181 :
V_84 |= V_142 ;
break;
case ( V_179 |
V_181 ) :
V_84 |= V_182 ;
break;
}
if ( V_84 != V_2 -> V_84 ) {
V_6 = F_12 ( V_2 , V_106 , V_84 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_84 = V_84 ;
}
if ( ( V_2 -> V_75 == V_159 ) &&
F_55 ( V_174 [ 1 ] ) &&
( V_174 [ 0 ] & V_183 ) )
V_2 -> V_60 = true ;
}
return 0 ;
}
static int F_57 ( struct V_128 * V_49 ,
struct V_53 * V_54 , T_4 V_57 ,
T_5 V_48 , void * V_184 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
T_1 V_55 [ 5 ] ;
unsigned int V_15 ;
int V_6 ;
T_1 V_23 ;
F_3 ( V_2 -> V_7 , L_38 ,
V_2 -> V_45 , V_57 , V_54 -> V_15 ) ;
if ( V_54 -> V_15 > V_185 )
return - V_127 ;
F_37 ( & V_2 -> V_85 ) ;
if ( ( V_2 -> V_45 != V_46 ) &&
( V_2 -> V_45 != V_88 ) ) {
F_5 ( V_2 -> V_7 , L_39 , V_9 ,
V_2 -> V_45 ) ;
V_6 = - V_39 ;
goto V_186;
}
if ( V_2 -> V_42 ) {
F_3 ( V_2 -> V_7 , L_12 ) ;
V_2 -> V_42 = false ;
V_6 = - V_47 ;
goto V_186;
}
if ( V_57 ) {
V_2 -> V_41 = F_58 ( V_72 ,
V_73 ) ;
if ( ! V_2 -> V_41 ) {
F_3 ( V_2 -> V_7 , L_40 ) ;
V_6 = - V_74 ;
goto V_186;
}
}
if ( V_2 -> V_45 == V_88 ) {
V_6 = F_1 ( V_2 , V_187 ) ;
if ( V_6 )
goto V_186;
V_2 -> V_45 = V_46 ;
}
if ( V_2 -> V_89 ) {
V_6 = F_56 ( V_2 , V_54 ) ;
if ( V_6 )
goto V_186;
}
V_2 -> V_49 = V_49 ;
V_2 -> V_40 = V_54 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_50 = V_184 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_93 = false ;
V_15 = V_54 -> V_15 ;
V_55 [ 0 ] = V_5 |
F_2 ( V_91 ) ;
V_55 [ 1 ] = V_5 |
F_2 ( V_2 -> V_97 ) ;
V_55 [ 2 ] = V_16 | V_188 ;
if ( V_2 -> V_75 == V_152 ) {
V_55 [ 3 ] = 0x00 ;
V_55 [ 4 ] = 0x0f ;
} else {
V_55 [ 3 ] = ( V_15 & 0xf00 ) >> 4 ;
V_55 [ 3 ] |= ( ( V_15 & 0xf0 ) >> 4 ) ;
V_55 [ 4 ] = ( ( V_15 & 0x0f ) << 4 ) ;
}
V_15 = F_59 ( int , V_54 -> V_15 , V_68 ) ;
V_6 = F_13 ( V_2 , & V_23 ) ;
if ( V_6 )
goto V_186;
V_6 = F_24 ( V_2 , V_54 , V_15 , V_55 , sizeof( V_55 ) ) ;
if ( V_6 ) {
F_20 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
V_186:
F_38 ( & V_2 -> V_85 ) ;
return V_6 ;
}
static int F_60 ( struct V_1 * V_2 , int V_30 )
{
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_32 , V_30 ) ;
switch ( V_30 ) {
case V_32 :
V_2 -> V_130 = V_189 |
V_190 |
V_191 ;
V_2 -> V_121 = V_132 ;
break;
case V_36 :
V_2 -> V_130 = V_189 |
V_192 ;
V_2 -> V_121 = V_136 ;
break;
case V_38 :
V_2 -> V_130 = V_189 |
V_193 ;
V_2 -> V_121 = V_136 ;
break;
default:
F_3 ( V_2 -> V_7 , L_33 , V_30 ) ;
return - V_127 ;
}
V_2 -> V_144 = V_30 ;
if ( ( V_2 -> V_75 == V_194 ) &&
( V_2 -> V_130 != V_2 -> V_84 ) ) {
V_6 = F_12 ( V_2 , V_106 ,
V_2 -> V_130 ) ;
V_2 -> V_84 = V_2 -> V_130 ;
}
return V_6 ;
}
static int F_61 ( struct V_1 * V_2 , int V_75 )
{
T_1 V_84 = V_2 -> V_130 ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_34 , V_75 ) ;
switch ( V_75 ) {
case V_160 :
V_2 -> V_97 = V_98 ;
V_84 |= V_99 ;
break;
case V_96 :
case V_100 :
case V_102 :
V_84 = V_2 -> V_84 ;
break;
case V_161 :
V_2 -> V_97 = V_101 ;
V_84 &= ~ V_99 ;
break;
case V_194 :
V_2 -> V_97 = V_101 ;
V_84 &= ~ V_99 ;
break;
default:
F_3 ( V_2 -> V_7 , L_35 , V_75 ) ;
return - V_127 ;
}
V_2 -> V_75 = V_75 ;
if ( V_84 != V_2 -> V_84 ) {
V_6 = F_12 ( V_2 , V_106 , V_84 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_84 = V_84 ;
V_6 = F_12 ( V_2 , V_120 ,
V_2 -> V_121 ) ;
if ( V_6 )
return V_6 ;
}
if ( ! ( V_2 -> V_118 & V_119 ) ) {
V_6 = F_12 ( V_2 , V_126 ,
V_2 -> V_118 |
V_119 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_118 |= V_119 ;
}
return 0 ;
}
static int F_62 ( struct V_128 * V_49 , int type ,
int V_163 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_36 , type , V_163 ) ;
F_37 ( & V_2 -> V_85 ) ;
V_2 -> V_89 = false ;
if ( ( V_2 -> V_45 == V_125 ) ||
( V_2 -> V_45 == V_86 ) ) {
V_6 = F_47 ( V_2 ) ;
if ( V_6 )
goto V_164;
}
switch ( type ) {
case V_165 :
V_6 = F_60 ( V_2 , V_163 ) ;
break;
case V_166 :
V_6 = F_61 ( V_2 , V_163 ) ;
break;
default:
F_3 ( V_2 -> V_7 , L_37 , type ) ;
V_6 = - V_127 ;
}
V_164:
F_38 ( & V_2 -> V_85 ) ;
return V_6 ;
}
static int F_63 ( struct V_128 * V_49 , T_4 V_57 ,
T_5 V_48 , void * V_184 , bool V_195 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
int V_6 ;
F_37 ( & V_2 -> V_85 ) ;
if ( ( V_2 -> V_45 != V_46 ) &&
( V_2 -> V_45 != V_88 ) ) {
F_5 ( V_2 -> V_7 , L_39 , V_9 ,
V_2 -> V_45 ) ;
V_6 = - V_39 ;
goto V_186;
}
if ( V_2 -> V_42 ) {
F_3 ( V_2 -> V_7 , L_12 ) ;
V_2 -> V_42 = false ;
V_6 = - V_47 ;
goto V_186;
}
V_2 -> V_41 = F_58 ( V_72 ,
V_73 ) ;
if ( ! V_2 -> V_41 ) {
F_3 ( V_2 -> V_7 , L_40 ) ;
V_6 = - V_74 ;
goto V_186;
}
V_6 = F_12 ( V_2 , V_196 ,
V_197 |
V_198 |
V_199 |
V_200 ) ;
if ( V_6 )
goto V_186;
V_6 = F_12 ( V_2 , V_201 ,
F_64 ( 0x1 ) ) ;
if ( V_6 )
goto V_186;
V_6 = F_12 ( V_2 , V_202 ,
F_65 ( 0x3 ) ) ;
if ( V_6 )
goto V_186;
V_6 = F_12 ( V_2 , V_145 ,
F_66 ( 0x7 ) ) ;
if ( V_6 )
goto V_186;
V_2 -> V_49 = V_49 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_50 = V_184 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_93 = false ;
V_6 = F_1 ( V_2 , V_187 ) ;
if ( V_6 )
goto V_186;
V_2 -> V_45 = V_195 ? V_108 :
V_107 ;
F_26 ( & V_2 -> V_52 , F_27 ( V_57 ) ) ;
V_186:
F_38 ( & V_2 -> V_85 ) ;
return V_6 ;
}
static int F_67 ( struct V_128 * V_49 , T_4 V_57 ,
T_5 V_48 , void * V_184 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
F_3 ( V_2 -> V_7 , L_41 ,
V_2 -> V_45 , V_57 ) ;
return F_63 ( V_49 , V_57 , V_48 , V_184 , false ) ;
}
static int F_68 ( struct V_128 * V_49 ,
T_4 V_57 , T_5 V_48 , void * V_184 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_42 ,
V_2 -> V_45 , V_57 ) ;
V_6 = F_62 ( V_49 , V_165 ,
V_32 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_62 ( V_49 , V_166 ,
V_160 ) ;
if ( V_6 )
return V_6 ;
return F_63 ( V_49 , V_57 , V_48 , V_184 , true ) ;
}
static int F_69 ( struct V_128 * V_49 , T_1 * V_29 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
F_3 ( V_2 -> V_7 , L_43 ,
V_2 -> V_45 , V_2 -> V_109 ) ;
* V_29 = V_2 -> V_109 ;
return 0 ;
}
static void F_70 ( struct V_128 * V_49 )
{
struct V_1 * V_2 = F_50 ( V_49 ) ;
F_3 ( V_2 -> V_7 , L_44 ) ;
F_37 ( & V_2 -> V_85 ) ;
switch ( V_2 -> V_45 ) {
case V_58 :
case V_63 :
case V_80 :
case V_61 :
V_2 -> V_42 = true ;
break;
case V_107 :
V_2 -> V_93 = ! F_23 ( & V_2 -> V_52 ) ;
F_22 ( V_2 , - V_47 ) ;
F_3 ( V_2 -> V_7 , L_12 ) ;
break;
default:
break;
}
F_38 ( & V_2 -> V_85 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_45 , V_2 -> V_45 ) ;
if ( V_2 -> V_45 != V_125 )
return 0 ;
V_6 = F_72 ( V_2 -> V_203 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_46 , V_9 , V_6 ) ;
return V_6 ;
}
F_43 ( 5000 , 6000 ) ;
if ( ! ( V_2 -> V_25 & V_204 ) ) {
F_73 ( V_2 -> V_205 , 1 ) ;
F_43 ( 1000 , 2000 ) ;
}
F_73 ( V_2 -> V_206 , 1 ) ;
F_43 ( 20000 , 21000 ) ;
V_2 -> V_45 = V_86 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_47 , V_2 -> V_45 ) ;
if ( V_2 -> V_45 == V_125 )
return 0 ;
if ( V_2 -> V_45 != V_86 ) {
F_3 ( V_2 -> V_7 , L_48 ,
V_2 -> V_45 ) ;
return - V_162 ;
}
F_73 ( V_2 -> V_206 , 0 ) ;
F_73 ( V_2 -> V_205 , 0 ) ;
V_6 = F_75 ( V_2 -> V_203 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_49 , V_9 ,
V_6 ) ;
V_2 -> V_45 = V_125 ;
return V_6 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_71 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_77 ( V_2 -> V_7 ) ;
F_78 ( V_2 -> V_7 ) ;
F_45 ( V_2 -> V_7 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_45 ) {
case V_58 :
case V_63 :
case V_80 :
case V_61 :
case V_107 :
F_22 ( V_2 , - V_47 ) ;
case V_46 :
case V_88 :
F_44 ( V_2 ) ;
break;
default:
break;
}
F_80 ( V_2 -> V_7 ) ;
F_81 ( V_2 -> V_7 ) ;
F_74 ( V_2 ) ;
}
static int F_82 ( struct V_207 * V_208 )
{
int V_209 , V_6 ;
V_6 = F_83 ( V_208 , L_50 , & V_209 ) ;
if ( V_6 )
V_209 = V_210 ;
return V_209 ;
}
static int F_84 ( struct V_207 * V_208 ,
T_6 * V_211 )
{
return F_83 ( V_208 , L_51 , V_211 ) ;
}
static int F_85 ( struct V_212 * V_8 )
{
struct V_207 * V_208 = V_8 -> V_7 . V_213 ;
struct V_1 * V_2 ;
int V_214 , V_209 , V_6 ;
if ( ! V_208 ) {
F_5 ( & V_8 -> V_7 , L_52 ) ;
return - V_127 ;
}
V_2 = F_86 ( & V_8 -> V_7 , sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_45 = V_125 ;
V_2 -> V_7 = & V_8 -> V_7 ;
V_2 -> V_8 = V_8 ;
V_8 -> V_215 = V_216 ;
V_8 -> V_217 = 8 ;
V_6 = F_87 ( V_8 ) ;
if ( V_6 < 0 ) {
F_5 ( V_2 -> V_7 , L_53 ) ;
return V_6 ;
}
if ( F_88 ( V_208 , L_54 ) )
V_2 -> V_25 |= V_26 ;
V_2 -> V_206 = F_89 ( V_208 , L_55 , 0 ) ;
if ( ! F_90 ( V_2 -> V_206 ) ) {
F_5 ( V_2 -> V_7 , L_56 ) ;
return V_2 -> V_206 ;
}
V_6 = F_91 ( V_2 -> V_7 , V_2 -> V_206 ,
V_218 | V_219 , L_57 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_58 , V_6 ) ;
return V_6 ;
}
V_2 -> V_205 = F_89 ( V_208 , L_55 , 1 ) ;
if ( ! F_90 ( V_2 -> V_205 ) ) {
F_5 ( V_2 -> V_7 , L_59 ) ;
return V_2 -> V_205 ;
}
V_6 = F_91 ( V_2 -> V_7 , V_2 -> V_205 ,
V_218 | V_219 , L_60 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_61 , V_6 ) ;
return V_6 ;
}
if ( F_88 ( V_208 , L_62 ) )
V_2 -> V_25 |= V_204 ;
V_6 = F_92 ( V_2 -> V_7 , V_8 -> V_82 , NULL ,
F_36 , V_220 | V_221 ,
L_63 , V_2 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_64 , V_8 -> V_82 , V_6 ) ;
return V_6 ;
}
F_93 ( & V_2 -> V_85 ) ;
F_94 ( & V_2 -> V_52 , F_40 ) ;
V_2 -> V_203 = F_95 ( & V_8 -> V_7 , L_65 ) ;
if ( F_18 ( V_2 -> V_203 ) ) {
V_6 = F_96 ( V_2 -> V_203 ) ;
F_5 ( V_2 -> V_7 , L_66 , V_6 ) ;
goto V_222;
}
V_6 = F_72 ( V_2 -> V_203 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_67 , V_6 ) ;
goto V_222;
}
V_6 = F_84 ( V_208 , & V_214 ) ;
if ( V_6 )
V_214 = F_97 ( V_2 -> V_203 ) ;
if ( V_214 > 4000000 )
V_2 -> V_118 = V_223 ;
V_2 -> V_49 = F_98 ( & V_224 ,
V_225 ,
V_226 |
V_227 , 0 , 0 ) ;
if ( ! V_2 -> V_49 ) {
F_5 ( V_2 -> V_7 , L_68 ) ;
V_6 = - V_74 ;
goto V_228;
}
F_99 ( V_2 -> V_49 , V_2 -> V_7 ) ;
F_100 ( V_2 -> V_49 , V_2 ) ;
F_101 ( V_8 , V_2 ) ;
V_209 = F_82 ( V_208 ) ;
F_102 ( V_2 -> V_7 , V_209 ) ;
F_103 ( V_2 -> V_7 ) ;
V_6 = F_76 ( V_2 ) ;
if ( V_6 )
goto V_229;
V_6 = F_104 ( V_2 -> V_49 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_69 ,
V_6 ) ;
goto V_230;
}
return 0 ;
V_230:
F_79 ( V_2 ) ;
V_229:
F_105 ( V_2 -> V_49 ) ;
V_228:
F_75 ( V_2 -> V_203 ) ;
V_222:
F_106 ( & V_2 -> V_85 ) ;
return V_6 ;
}
static int F_107 ( struct V_212 * V_8 )
{
struct V_1 * V_2 = F_108 ( V_8 ) ;
F_37 ( & V_2 -> V_85 ) ;
F_79 ( V_2 ) ;
F_38 ( & V_2 -> V_85 ) ;
F_109 ( V_2 -> V_49 ) ;
F_105 ( V_2 -> V_49 ) ;
F_75 ( V_2 -> V_203 ) ;
F_106 ( & V_2 -> V_85 ) ;
return 0 ;
}
static int F_110 ( struct V_231 * V_7 )
{
struct V_212 * V_8 = F_41 ( V_7 , struct V_212 , V_7 ) ;
struct V_1 * V_2 = F_108 ( V_8 ) ;
F_3 ( V_7 , L_70 ) ;
F_37 ( & V_2 -> V_85 ) ;
F_79 ( V_2 ) ;
F_38 ( & V_2 -> V_85 ) ;
return 0 ;
}
static int F_111 ( struct V_231 * V_7 )
{
struct V_212 * V_8 = F_41 ( V_7 , struct V_212 , V_7 ) ;
struct V_1 * V_2 = F_108 ( V_8 ) ;
int V_6 ;
F_3 ( V_7 , L_71 ) ;
F_37 ( & V_2 -> V_85 ) ;
V_6 = F_76 ( V_2 ) ;
F_38 ( & V_2 -> V_85 ) ;
return V_6 ;
}
static int F_112 ( struct V_231 * V_7 )
{
struct V_212 * V_8 = F_41 ( V_7 , struct V_212 , V_7 ) ;
struct V_1 * V_2 = F_108 ( V_8 ) ;
int V_6 ;
F_3 ( V_7 , L_72 ) ;
F_37 ( & V_2 -> V_85 ) ;
V_6 = F_74 ( V_2 ) ;
F_38 ( & V_2 -> V_85 ) ;
return V_6 ;
}
static int F_113 ( struct V_231 * V_7 )
{
struct V_212 * V_8 = F_41 ( V_7 , struct V_212 , V_7 ) ;
struct V_1 * V_2 = F_108 ( V_8 ) ;
int V_6 ;
F_3 ( V_7 , L_73 ) ;
V_6 = F_71 ( V_2 ) ;
if ( ! V_6 )
F_45 ( V_7 ) ;
return V_6 ;
}
