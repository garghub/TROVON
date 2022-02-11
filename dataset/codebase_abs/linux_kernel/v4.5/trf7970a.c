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
if ( V_2 -> V_48 ) {
if ( V_2 -> V_41 )
F_22 ( V_2 -> V_41 , V_2 -> V_41 -> V_15 - 1 ) ;
V_2 -> V_48 = false ;
}
V_2 -> V_49 ( V_2 -> V_50 , V_2 -> V_51 , V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
static void F_23 ( struct V_1 * V_2 , int V_52 )
{
F_3 ( V_2 -> V_7 , L_13 , V_2 -> V_45 , V_52 ) ;
F_24 ( & V_2 -> V_53 ) ;
F_20 ( V_2 -> V_41 ) ;
V_2 -> V_41 = F_21 ( V_52 ) ;
F_16 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_54 * V_55 ,
unsigned int V_15 , T_1 * V_56 , unsigned int V_57 )
{
struct V_17 V_18 [ 2 ] ;
struct V_19 V_20 ;
unsigned int V_58 ;
int V_6 ;
F_19 ( L_14 , V_43 ,
16 , 1 , V_55 -> V_44 , V_15 , false ) ;
F_9 ( & V_20 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 0 ] . V_21 = V_56 ;
V_18 [ 0 ] . V_15 = V_57 ;
F_10 ( & V_18 [ 0 ] , & V_20 ) ;
V_18 [ 1 ] . V_21 = V_55 -> V_44 ;
V_18 [ 1 ] . V_15 = V_15 ;
F_10 ( & V_18 [ 1 ] , & V_20 ) ;
V_6 = F_11 ( V_2 -> V_8 , & V_20 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_15 , V_9 ,
V_6 ) ;
return V_6 ;
}
F_26 ( V_55 , V_15 ) ;
if ( V_55 -> V_15 > 0 ) {
V_2 -> V_45 = V_59 ;
V_58 = V_60 ;
} else {
if ( V_2 -> V_61 ) {
V_2 -> V_45 = V_62 ;
V_58 = V_63 ;
} else {
V_2 -> V_45 = V_64 ;
if ( ! V_2 -> V_58 )
V_58 = V_65 ;
else
V_58 = V_2 -> V_58 ;
}
}
F_3 ( V_2 -> V_7 , L_16 , V_58 ,
V_2 -> V_45 ) ;
F_27 ( & V_2 -> V_53 , F_28 ( V_58 ) ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_40 ;
unsigned int V_15 ;
int V_6 ;
T_1 V_66 ;
T_1 V_56 ;
V_6 = F_6 ( V_2 , V_67 , & V_66 ) ;
if ( V_6 ) {
F_23 ( V_2 , V_6 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_17 , V_66 ) ;
V_66 &= ~ V_68 ;
V_15 = V_69 - V_66 ;
if ( ! V_15 ) {
F_27 ( & V_2 -> V_53 ,
F_28 ( V_60 ) ) ;
return;
}
V_15 = F_30 ( V_55 -> V_15 , V_15 ) ;
V_56 = V_16 | V_70 ;
V_6 = F_25 ( V_2 , V_55 , V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_6 )
F_23 ( V_2 , V_6 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_54 * V_55 = V_2 -> V_41 ;
int V_6 ;
T_1 V_66 ;
if ( V_23 & V_71 ) {
F_23 ( V_2 , - V_39 ) ;
return;
}
V_6 = F_6 ( V_2 , V_67 , & V_66 ) ;
if ( V_6 ) {
F_23 ( V_2 , V_6 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_18 , V_66 ) ;
V_66 &= ~ V_68 ;
if ( ! V_66 )
goto V_72;
if ( V_66 > F_32 ( V_55 ) ) {
V_55 = F_33 ( V_55 , F_34 ( V_55 ) ,
F_35 ( int , V_66 ,
V_73 ) ,
V_74 ) ;
if ( ! V_55 ) {
F_23 ( V_2 , - V_75 ) ;
return;
}
F_20 ( V_2 -> V_41 ) ;
V_2 -> V_41 = V_55 ;
}
V_6 = F_8 ( V_2 , V_70 ,
F_36 ( V_55 , V_66 ) , V_66 ) ;
if ( V_6 ) {
F_23 ( V_2 , V_6 ) ;
return;
}
if ( ( V_2 -> V_76 == V_77 ) && ( V_55 -> V_15 == 1 ) &&
( V_2 -> V_78 ==
V_79 ) ) {
V_55 -> V_44 [ 0 ] >>= 4 ;
V_23 = V_80 ;
} else {
V_2 -> V_45 = V_81 ;
V_6 = F_6 ( V_2 , V_67 , & V_66 ) ;
if ( V_6 ) {
F_23 ( V_2 , V_6 ) ;
return;
}
V_66 &= ~ V_68 ;
if ( V_66 )
V_23 = 0 ;
}
V_72:
if ( V_23 == V_80 ) {
F_16 ( V_2 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_19 ,
V_82 ) ;
F_27 ( & V_2 -> V_53 ,
F_28 ( V_82 ) ) ;
}
static T_3 F_37 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
int V_6 ;
T_1 V_23 , V_66 , V_85 ;
F_38 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_45 == V_87 ) {
F_39 ( & V_2 -> V_86 ) ;
return V_88 ;
}
V_6 = F_13 ( V_2 , & V_23 ) ;
if ( V_6 ) {
F_39 ( & V_2 -> V_86 ) ;
return V_88 ;
}
F_3 ( V_2 -> V_7 , L_20 , V_2 -> V_45 ,
V_23 ) ;
if ( ! V_23 ) {
F_39 ( & V_2 -> V_86 ) ;
return V_88 ;
}
switch ( V_2 -> V_45 ) {
case V_46 :
case V_89 :
if ( V_2 -> V_90 && ( V_23 & V_71 ) ) {
F_1 ( V_2 , V_91 ) ;
V_2 -> V_45 = V_89 ;
}
F_1 ( V_2 , V_92 ) ;
break;
case V_59 :
if ( V_23 & V_93 ) {
V_2 -> V_94 =
! F_24 ( & V_2 -> V_53 ) ;
F_29 ( V_2 ) ;
} else {
F_23 ( V_2 , - V_39 ) ;
}
break;
case V_64 :
case V_81 :
if ( V_23 & V_80 ) {
V_2 -> V_94 =
! F_24 ( & V_2 -> V_53 ) ;
F_31 ( V_2 , V_23 ) ;
} else if ( V_23 & V_95 ) {
V_6 = F_6 ( V_2 , V_67 ,
& V_66 ) ;
V_66 &= ~ V_68 ;
if ( V_6 )
F_23 ( V_2 , V_6 ) ;
else if ( ! V_66 )
F_1 ( V_2 , V_92 ) ;
} else if ( ( V_23 == V_93 ) ||
( ! V_2 -> V_90 &&
( V_23 == ( V_93 |
V_96 ) ) ) ) {
F_1 ( V_2 , V_92 ) ;
if ( ! V_2 -> V_58 ) {
V_2 -> V_94 = ! F_24 (
& V_2 -> V_53 ) ;
V_2 -> V_41 = F_21 ( 0 ) ;
F_16 ( V_2 ) ;
break;
}
if ( V_2 -> V_90 )
break;
V_85 = V_2 -> V_85 ;
switch ( V_2 -> V_76 ) {
case V_97 :
V_2 -> V_98 = V_99 ;
V_85 |= V_100 ;
V_2 -> V_85 = 0xff ;
break;
case V_101 :
V_2 -> V_98 = V_102 ;
V_85 &= ~ V_100 ;
V_2 -> V_85 = 0xff ;
break;
case V_103 :
V_6 = F_12 ( V_2 ,
V_104 ,
V_105 ) ;
if ( V_6 )
goto V_106;
V_2 -> V_78 =
V_105 ;
break;
default:
break;
}
if ( V_85 != V_2 -> V_85 ) {
V_6 = F_12 ( V_2 , V_107 ,
V_85 ) ;
if ( V_6 )
goto V_106;
V_2 -> V_85 = V_85 ;
}
} else {
F_23 ( V_2 , - V_39 ) ;
}
break;
case V_62 :
if ( V_23 != V_93 )
F_23 ( V_2 , - V_39 ) ;
break;
case V_108 :
if ( V_23 & V_80 ) {
V_2 -> V_94 =
! F_24 ( & V_2 -> V_53 ) ;
F_31 ( V_2 , V_23 ) ;
} else if ( ! ( V_23 & V_96 ) ) {
F_23 ( V_2 , - V_39 ) ;
}
break;
case V_109 :
if ( V_23 & V_80 ) {
V_2 -> V_94 =
! F_24 ( & V_2 -> V_53 ) ;
V_6 = F_15 ( V_2 , & V_2 -> V_110 ) ;
if ( V_6 ) {
F_23 ( V_2 , V_6 ) ;
} else {
V_2 -> V_45 = V_108 ;
F_31 ( V_2 , V_23 ) ;
}
} else if ( ! ( V_23 & V_96 ) ) {
F_23 ( V_2 , - V_39 ) ;
}
break;
default:
F_5 ( V_2 -> V_7 , L_21 ,
V_9 , V_2 -> V_45 ) ;
}
V_106:
F_39 ( & V_2 -> V_86 ) ;
return V_111 ;
}
static void F_40 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_22 ) ;
V_6 = F_1 ( V_2 , V_92 ) ;
if ( V_6 )
F_23 ( V_2 , V_6 ) ;
V_6 = F_1 ( V_2 , V_112 ) ;
if ( V_6 )
F_23 ( V_2 , V_6 ) ;
V_2 -> V_45 = V_64 ;
F_3 ( V_2 -> V_7 , L_16 ,
V_2 -> V_58 , V_2 -> V_45 ) ;
F_27 ( & V_2 -> V_53 ,
F_28 ( V_2 -> V_58 ) ) ;
}
static void F_41 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = F_42 ( V_114 , struct V_1 ,
V_53 . V_114 ) ;
F_3 ( V_2 -> V_7 , L_23 ,
V_2 -> V_45 , V_2 -> V_94 ) ;
F_38 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_94 )
V_2 -> V_94 = false ;
else if ( V_2 -> V_45 == V_81 )
F_31 ( V_2 , V_80 ) ;
else if ( V_2 -> V_45 == V_62 )
F_40 ( V_2 ) ;
else
F_23 ( V_2 , - V_115 ) ;
F_39 ( & V_2 -> V_86 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_24 , V_2 -> V_45 ) ;
V_6 = F_1 ( V_2 , V_116 ) ;
if ( V_6 )
goto V_117;
V_6 = F_1 ( V_2 , V_118 ) ;
if ( V_6 )
goto V_117;
F_44 ( 1000 , 2000 ) ;
V_2 -> V_119 &= ~ V_120 ;
V_6 = F_12 ( V_2 , V_121 , 0 ) ;
if ( V_6 )
goto V_117;
V_2 -> V_122 = 0 ;
V_6 = F_12 ( V_2 , V_123 ,
V_124 |
V_125 ) ;
if ( V_6 )
goto V_117;
V_6 = F_12 ( V_2 , V_104 , 0 ) ;
if ( V_6 )
goto V_117;
V_2 -> V_78 = 0 ;
V_2 -> V_85 = 0xff ;
return 0 ;
V_117:
F_3 ( V_2 -> V_7 , L_25 , V_6 ) ;
return V_6 ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_45 == V_126 ) ||
( V_2 -> V_45 == V_87 ) )
return;
F_3 ( V_2 -> V_7 , L_26 ) ;
V_2 -> V_119 &= ~ V_120 ;
F_12 ( V_2 , V_127 , V_2 -> V_119 ) ;
V_2 -> V_42 = false ;
V_2 -> V_45 = V_87 ;
F_46 ( V_2 -> V_7 ) ;
F_47 ( V_2 -> V_7 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_27 ) ;
F_49 ( V_2 -> V_7 ) ;
if ( V_2 -> V_45 != V_87 ) {
F_5 ( V_2 -> V_7 , L_28 , V_9 ,
V_2 -> V_45 ) ;
return - V_128 ;
}
V_6 = F_43 ( V_2 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_29 , V_9 , V_6 ) ;
return V_6 ;
}
V_2 -> V_45 = V_46 ;
return 0 ;
}
static int F_50 ( struct V_129 * V_50 , bool V_130 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_30 , V_2 -> V_45 , V_130 ) ;
F_38 ( & V_2 -> V_86 ) ;
if ( V_130 ) {
switch ( V_2 -> V_45 ) {
case V_126 :
case V_87 :
V_6 = F_48 ( V_2 ) ;
break;
case V_46 :
case V_89 :
break;
default:
F_5 ( V_2 -> V_7 , L_31 ,
V_9 , V_2 -> V_45 , V_130 ) ;
F_45 ( V_2 ) ;
V_6 = - V_128 ;
}
} else {
switch ( V_2 -> V_45 ) {
case V_126 :
case V_87 :
break;
default:
F_5 ( V_2 -> V_7 , L_31 ,
V_9 , V_2 -> V_45 , V_130 ) ;
V_6 = - V_128 ;
case V_46 :
case V_89 :
case V_64 :
case V_81 :
F_45 ( V_2 ) ;
}
}
F_39 ( & V_2 -> V_86 ) ;
return V_6 ;
}
static int F_52 ( struct V_1 * V_2 , int V_30 )
{
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_32 , V_30 ) ;
switch ( V_30 ) {
case V_32 :
V_2 -> V_131 = V_132 ;
V_2 -> V_122 = V_133 ;
V_2 -> V_134 = V_135 ;
break;
case V_34 :
V_2 -> V_131 = V_136 ;
V_2 -> V_122 = V_137 ;
V_2 -> V_134 = V_138 ;
break;
case V_36 :
V_2 -> V_131 = V_139 ;
V_2 -> V_122 = V_137 ;
V_2 -> V_134 = V_140 ;
break;
case V_38 :
V_2 -> V_131 = V_141 ;
V_2 -> V_122 = V_137 ;
V_2 -> V_134 = V_140 ;
break;
case V_142 :
V_2 -> V_131 = V_143 ;
V_2 -> V_122 = V_133 ;
V_2 -> V_134 = V_144 ;
break;
default:
F_3 ( V_2 -> V_7 , L_33 , V_30 ) ;
return - V_128 ;
}
V_2 -> V_145 = V_30 ;
if ( V_2 -> V_85 == 0xff )
V_6 = F_12 ( V_2 , V_146 , 0 ) ;
return V_6 ;
}
static int F_53 ( struct V_1 * V_2 , bool * V_147 )
{
int V_6 ;
T_1 V_148 ;
V_6 = F_12 ( V_2 , V_127 ,
V_2 -> V_119 | V_149 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_150 ) ;
if ( V_6 )
return V_6 ;
F_44 ( 50 , 60 ) ;
V_6 = F_6 ( V_2 , V_151 , & V_148 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_12 ( V_2 , V_127 ,
V_2 -> V_119 ) ;
if ( V_6 )
return V_6 ;
if ( V_148 & V_152 )
* V_147 = true ;
else
* V_147 = false ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , int V_76 )
{
T_1 V_85 = V_2 -> V_131 ;
bool V_147 = false ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_34 , V_76 ) ;
switch ( V_76 ) {
case V_153 :
case V_97 :
V_2 -> V_98 = V_99 ;
V_85 |= V_100 ;
break;
case V_101 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
V_2 -> V_98 = V_102 ;
V_85 &= ~ V_100 ;
break;
case V_77 :
V_2 -> V_98 = V_102 ;
V_85 |= V_100 ;
break;
default:
F_3 ( V_2 -> V_7 , L_35 , V_76 ) ;
return - V_128 ;
}
V_2 -> V_76 = V_76 ;
if ( ! ( V_2 -> V_119 & V_120 ) ) {
V_6 = F_53 ( V_2 , & V_147 ) ;
if ( V_6 )
return V_6 ;
if ( V_147 )
return - V_163 ;
}
if ( V_85 != V_2 -> V_85 ) {
V_6 = F_12 ( V_2 , V_107 , V_85 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_85 = V_85 ;
V_6 = F_12 ( V_2 , V_121 ,
V_2 -> V_122 ) ;
if ( V_6 )
return V_6 ;
}
if ( ! ( V_2 -> V_119 & V_120 ) ) {
V_6 = F_12 ( V_2 , V_127 ,
V_2 -> V_119 |
V_120 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_119 |= V_120 ;
F_44 ( V_2 -> V_134 , V_2 -> V_134 + 1000 ) ;
}
return 0 ;
}
static int F_55 ( struct V_129 * V_50 , int type ,
int V_164 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_36 , type , V_164 ) ;
F_38 ( & V_2 -> V_86 ) ;
V_2 -> V_90 = true ;
if ( ( V_2 -> V_45 == V_126 ) ||
( V_2 -> V_45 == V_87 ) ) {
V_6 = F_48 ( V_2 ) ;
if ( V_6 )
goto V_165;
}
switch ( type ) {
case V_166 :
V_6 = F_52 ( V_2 , V_164 ) ;
break;
case V_167 :
V_6 = F_54 ( V_2 , V_164 ) ;
break;
default:
F_3 ( V_2 -> V_7 , L_37 , type ) ;
V_6 = - V_128 ;
}
V_165:
F_39 ( & V_2 -> V_86 ) ;
return V_6 ;
}
static int F_56 ( T_1 V_4 )
{
switch ( V_4 ) {
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
return 1 ;
break;
default:
return 0 ;
}
}
static int F_57 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
T_1 * V_175 = V_55 -> V_44 ;
T_1 V_78 , V_85 ;
int V_6 ;
V_2 -> V_61 = false ;
if ( ( V_2 -> V_145 == V_32 ) &&
( V_2 -> V_76 == V_77 ) ) {
if ( V_175 [ 0 ] == V_176 )
V_78 = 0 ;
else
V_78 = V_79 ;
if ( V_78 != V_2 -> V_78 ) {
V_6 = F_12 ( V_2 , V_104 ,
V_78 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_78 = V_78 ;
}
} else if ( V_2 -> V_145 == V_142 ) {
V_85 = V_2 -> V_85 & ~ V_177 ;
switch ( V_175 [ 0 ] & V_178 ) {
case 0x00 :
V_85 |= V_179 ;
break;
case V_180 :
V_85 |= V_181 ;
break;
case V_182 :
V_85 |= V_143 ;
break;
case ( V_180 |
V_182 ) :
V_85 |= V_183 ;
break;
}
if ( V_85 != V_2 -> V_85 ) {
V_6 = F_12 ( V_2 , V_107 , V_85 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_85 = V_85 ;
}
if ( V_2 -> V_76 == V_160 ) {
if ( F_56 ( V_175 [ 1 ] ) &&
( V_175 [ 0 ] & V_184 ) )
V_2 -> V_61 = true ;
else if ( ( V_2 -> V_25 &
V_185 ) &&
( V_175 [ 1 ] == V_186 ) )
V_2 -> V_48 = true ;
}
}
return 0 ;
}
static int F_58 ( struct V_129 * V_50 ,
struct V_54 * V_55 , T_4 V_58 ,
T_5 V_49 , void * V_187 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
T_1 V_56 [ 5 ] ;
unsigned int V_15 ;
int V_6 ;
T_1 V_23 ;
F_3 ( V_2 -> V_7 , L_38 ,
V_2 -> V_45 , V_58 , V_55 -> V_15 ) ;
if ( V_55 -> V_15 > V_188 )
return - V_128 ;
F_38 ( & V_2 -> V_86 ) ;
if ( ( V_2 -> V_45 != V_46 ) &&
( V_2 -> V_45 != V_89 ) ) {
F_5 ( V_2 -> V_7 , L_39 , V_9 ,
V_2 -> V_45 ) ;
V_6 = - V_39 ;
goto V_189;
}
if ( V_2 -> V_42 ) {
F_3 ( V_2 -> V_7 , L_12 ) ;
V_2 -> V_42 = false ;
V_6 = - V_47 ;
goto V_189;
}
if ( V_58 ) {
V_2 -> V_41 = F_59 ( V_73 ,
V_74 ) ;
if ( ! V_2 -> V_41 ) {
F_3 ( V_2 -> V_7 , L_40 ) ;
V_6 = - V_75 ;
goto V_189;
}
}
if ( V_2 -> V_45 == V_89 ) {
V_6 = F_1 ( V_2 , V_190 ) ;
if ( V_6 )
goto V_189;
V_2 -> V_45 = V_46 ;
}
if ( V_2 -> V_90 ) {
V_6 = F_57 ( V_2 , V_55 ) ;
if ( V_6 )
goto V_189;
}
V_2 -> V_50 = V_50 ;
V_2 -> V_40 = V_55 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_51 = V_187 ;
V_2 -> V_58 = V_58 ;
V_2 -> V_94 = false ;
V_15 = V_55 -> V_15 ;
V_56 [ 0 ] = V_5 |
F_2 ( V_92 ) ;
V_56 [ 1 ] = V_5 |
F_2 ( V_2 -> V_98 ) ;
V_56 [ 2 ] = V_16 | V_191 ;
if ( V_2 -> V_76 == V_153 ) {
V_56 [ 3 ] = 0x00 ;
V_56 [ 4 ] = 0x0f ;
} else {
V_56 [ 3 ] = ( V_15 & 0xf00 ) >> 4 ;
V_56 [ 3 ] |= ( ( V_15 & 0xf0 ) >> 4 ) ;
V_56 [ 4 ] = ( ( V_15 & 0x0f ) << 4 ) ;
}
V_15 = F_60 ( int , V_55 -> V_15 , V_69 ) ;
V_6 = F_13 ( V_2 , & V_23 ) ;
if ( V_6 )
goto V_189;
V_6 = F_25 ( V_2 , V_55 , V_15 , V_56 , sizeof( V_56 ) ) ;
if ( V_6 ) {
F_20 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
V_189:
F_39 ( & V_2 -> V_86 ) ;
return V_6 ;
}
static int F_61 ( struct V_1 * V_2 , int V_30 )
{
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_32 , V_30 ) ;
switch ( V_30 ) {
case V_32 :
V_2 -> V_131 = V_192 |
V_193 |
V_194 ;
V_2 -> V_122 = V_133 ;
break;
case V_36 :
V_2 -> V_131 = V_192 |
V_195 ;
V_2 -> V_122 = V_137 ;
break;
case V_38 :
V_2 -> V_131 = V_192 |
V_196 ;
V_2 -> V_122 = V_137 ;
break;
default:
F_3 ( V_2 -> V_7 , L_33 , V_30 ) ;
return - V_128 ;
}
V_2 -> V_145 = V_30 ;
if ( ( V_2 -> V_76 == V_197 ) &&
( V_2 -> V_131 != V_2 -> V_85 ) ) {
V_6 = F_12 ( V_2 , V_107 ,
V_2 -> V_131 ) ;
V_2 -> V_85 = V_2 -> V_131 ;
}
return V_6 ;
}
static int F_62 ( struct V_1 * V_2 , int V_76 )
{
T_1 V_85 = V_2 -> V_131 ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_34 , V_76 ) ;
switch ( V_76 ) {
case V_161 :
V_2 -> V_98 = V_99 ;
V_85 |= V_100 ;
break;
case V_97 :
case V_101 :
case V_103 :
V_85 = V_2 -> V_85 ;
break;
case V_162 :
V_2 -> V_98 = V_102 ;
V_85 &= ~ V_100 ;
break;
case V_197 :
V_2 -> V_98 = V_102 ;
V_85 &= ~ V_100 ;
break;
default:
F_3 ( V_2 -> V_7 , L_35 , V_76 ) ;
return - V_128 ;
}
V_2 -> V_76 = V_76 ;
if ( V_85 != V_2 -> V_85 ) {
V_6 = F_12 ( V_2 , V_107 , V_85 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_85 = V_85 ;
V_6 = F_12 ( V_2 , V_121 ,
V_2 -> V_122 ) ;
if ( V_6 )
return V_6 ;
}
if ( ! ( V_2 -> V_119 & V_120 ) ) {
V_6 = F_12 ( V_2 , V_127 ,
V_2 -> V_119 |
V_120 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_119 |= V_120 ;
}
return 0 ;
}
static int F_63 ( struct V_129 * V_50 , int type ,
int V_164 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_36 , type , V_164 ) ;
F_38 ( & V_2 -> V_86 ) ;
V_2 -> V_90 = false ;
if ( ( V_2 -> V_45 == V_126 ) ||
( V_2 -> V_45 == V_87 ) ) {
V_6 = F_48 ( V_2 ) ;
if ( V_6 )
goto V_165;
}
switch ( type ) {
case V_166 :
V_6 = F_61 ( V_2 , V_164 ) ;
break;
case V_167 :
V_6 = F_62 ( V_2 , V_164 ) ;
break;
default:
F_3 ( V_2 -> V_7 , L_37 , type ) ;
V_6 = - V_128 ;
}
V_165:
F_39 ( & V_2 -> V_86 ) ;
return V_6 ;
}
static int F_64 ( struct V_129 * V_50 , T_4 V_58 ,
T_5 V_49 , void * V_187 , bool V_198 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
int V_6 ;
F_38 ( & V_2 -> V_86 ) ;
if ( ( V_2 -> V_45 != V_46 ) &&
( V_2 -> V_45 != V_89 ) ) {
F_5 ( V_2 -> V_7 , L_39 , V_9 ,
V_2 -> V_45 ) ;
V_6 = - V_39 ;
goto V_189;
}
if ( V_2 -> V_42 ) {
F_3 ( V_2 -> V_7 , L_12 ) ;
V_2 -> V_42 = false ;
V_6 = - V_47 ;
goto V_189;
}
V_2 -> V_41 = F_59 ( V_73 ,
V_74 ) ;
if ( ! V_2 -> V_41 ) {
F_3 ( V_2 -> V_7 , L_40 ) ;
V_6 = - V_75 ;
goto V_189;
}
V_6 = F_12 ( V_2 , V_199 ,
V_200 |
V_201 |
V_202 |
V_203 ) ;
if ( V_6 )
goto V_189;
V_6 = F_12 ( V_2 , V_204 ,
F_65 ( 0x1 ) ) ;
if ( V_6 )
goto V_189;
V_6 = F_12 ( V_2 , V_205 ,
F_66 ( 0x3 ) ) ;
if ( V_6 )
goto V_189;
V_6 = F_12 ( V_2 , V_146 ,
F_67 ( 0x7 ) ) ;
if ( V_6 )
goto V_189;
V_2 -> V_50 = V_50 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_51 = V_187 ;
V_2 -> V_58 = V_58 ;
V_2 -> V_94 = false ;
V_6 = F_1 ( V_2 , V_190 ) ;
if ( V_6 )
goto V_189;
V_2 -> V_45 = V_198 ? V_109 :
V_108 ;
F_27 ( & V_2 -> V_53 , F_28 ( V_58 ) ) ;
V_189:
F_39 ( & V_2 -> V_86 ) ;
return V_6 ;
}
static int F_68 ( struct V_129 * V_50 , T_4 V_58 ,
T_5 V_49 , void * V_187 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
F_3 ( V_2 -> V_7 , L_41 ,
V_2 -> V_45 , V_58 ) ;
return F_64 ( V_50 , V_58 , V_49 , V_187 , false ) ;
}
static int F_69 ( struct V_129 * V_50 ,
T_4 V_58 , T_5 V_49 , void * V_187 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_42 ,
V_2 -> V_45 , V_58 ) ;
V_6 = F_63 ( V_50 , V_166 ,
V_32 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_63 ( V_50 , V_167 ,
V_161 ) ;
if ( V_6 )
return V_6 ;
return F_64 ( V_50 , V_58 , V_49 , V_187 , true ) ;
}
static int F_70 ( struct V_129 * V_50 , T_1 * V_29 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
F_3 ( V_2 -> V_7 , L_43 ,
V_2 -> V_45 , V_2 -> V_110 ) ;
* V_29 = V_2 -> V_110 ;
return 0 ;
}
static void F_71 ( struct V_129 * V_50 )
{
struct V_1 * V_2 = F_51 ( V_50 ) ;
F_3 ( V_2 -> V_7 , L_44 ) ;
F_38 ( & V_2 -> V_86 ) ;
switch ( V_2 -> V_45 ) {
case V_59 :
case V_64 :
case V_81 :
case V_62 :
V_2 -> V_42 = true ;
break;
case V_108 :
V_2 -> V_94 = ! F_24 ( & V_2 -> V_53 ) ;
F_23 ( V_2 , - V_47 ) ;
F_3 ( V_2 -> V_7 , L_12 ) ;
break;
default:
break;
}
F_39 ( & V_2 -> V_86 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_45 , V_2 -> V_45 ) ;
if ( V_2 -> V_45 != V_126 )
return 0 ;
V_6 = F_73 ( V_2 -> V_206 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_46 , V_9 , V_6 ) ;
return V_6 ;
}
F_44 ( 5000 , 6000 ) ;
if ( ! ( V_2 -> V_25 & V_207 ) ) {
F_74 ( V_2 -> V_208 , 1 ) ;
F_44 ( 1000 , 2000 ) ;
}
F_74 ( V_2 -> V_209 , 1 ) ;
F_44 ( 20000 , 21000 ) ;
V_2 -> V_45 = V_87 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_47 , V_2 -> V_45 ) ;
if ( V_2 -> V_45 == V_126 )
return 0 ;
if ( V_2 -> V_45 != V_87 ) {
F_3 ( V_2 -> V_7 , L_48 ,
V_2 -> V_45 ) ;
return - V_163 ;
}
F_74 ( V_2 -> V_209 , 0 ) ;
F_74 ( V_2 -> V_208 , 0 ) ;
V_6 = F_76 ( V_2 -> V_206 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_49 , V_9 ,
V_6 ) ;
V_2 -> V_45 = V_126 ;
return V_6 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_72 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_78 ( V_2 -> V_7 ) ;
F_79 ( V_2 -> V_7 ) ;
F_46 ( V_2 -> V_7 ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_45 ) {
case V_59 :
case V_64 :
case V_81 :
case V_62 :
case V_108 :
F_23 ( V_2 , - V_47 ) ;
case V_46 :
case V_89 :
F_45 ( V_2 ) ;
break;
default:
break;
}
F_81 ( V_2 -> V_7 ) ;
F_82 ( V_2 -> V_7 ) ;
F_75 ( V_2 ) ;
}
static int F_83 ( struct V_210 * V_211 )
{
int V_212 , V_6 ;
V_6 = F_84 ( V_211 , L_50 , & V_212 ) ;
if ( V_6 )
V_212 = V_213 ;
return V_212 ;
}
static int F_85 ( struct V_210 * V_211 ,
T_6 * V_214 )
{
return F_84 ( V_211 , L_51 , V_214 ) ;
}
static int F_86 ( struct V_215 * V_8 )
{
struct V_210 * V_211 = V_8 -> V_7 . V_216 ;
struct V_1 * V_2 ;
int V_217 , V_212 , V_6 ;
if ( ! V_211 ) {
F_5 ( & V_8 -> V_7 , L_52 ) ;
return - V_128 ;
}
V_2 = F_87 ( & V_8 -> V_7 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_2 -> V_45 = V_126 ;
V_2 -> V_7 = & V_8 -> V_7 ;
V_2 -> V_8 = V_8 ;
V_8 -> V_218 = V_219 ;
V_8 -> V_220 = 8 ;
V_6 = F_88 ( V_8 ) ;
if ( V_6 < 0 ) {
F_5 ( V_2 -> V_7 , L_53 ) ;
return V_6 ;
}
if ( F_89 ( V_211 , L_54 ) )
V_2 -> V_25 |= V_185 ;
if ( F_89 ( V_211 , L_55 ) )
V_2 -> V_25 |= V_26 ;
V_2 -> V_209 = F_90 ( V_211 , L_56 , 0 ) ;
if ( ! F_91 ( V_2 -> V_209 ) ) {
F_5 ( V_2 -> V_7 , L_57 ) ;
return V_2 -> V_209 ;
}
V_6 = F_92 ( V_2 -> V_7 , V_2 -> V_209 ,
V_221 | V_222 , L_58 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_59 , V_6 ) ;
return V_6 ;
}
V_2 -> V_208 = F_90 ( V_211 , L_56 , 1 ) ;
if ( ! F_91 ( V_2 -> V_208 ) ) {
F_5 ( V_2 -> V_7 , L_60 ) ;
return V_2 -> V_208 ;
}
V_6 = F_92 ( V_2 -> V_7 , V_2 -> V_208 ,
V_221 | V_222 , L_61 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_62 , V_6 ) ;
return V_6 ;
}
if ( F_89 ( V_211 , L_63 ) )
V_2 -> V_25 |= V_207 ;
V_6 = F_93 ( V_2 -> V_7 , V_8 -> V_83 , NULL ,
F_37 , V_223 | V_224 ,
L_64 , V_2 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_65 , V_8 -> V_83 , V_6 ) ;
return V_6 ;
}
F_94 ( & V_2 -> V_86 ) ;
F_95 ( & V_2 -> V_53 , F_41 ) ;
V_2 -> V_206 = F_96 ( & V_8 -> V_7 , L_66 ) ;
if ( F_18 ( V_2 -> V_206 ) ) {
V_6 = F_97 ( V_2 -> V_206 ) ;
F_5 ( V_2 -> V_7 , L_67 , V_6 ) ;
goto V_225;
}
V_6 = F_73 ( V_2 -> V_206 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_68 , V_6 ) ;
goto V_225;
}
V_6 = F_85 ( V_211 , & V_217 ) ;
if ( V_6 )
V_217 = F_98 ( V_2 -> V_206 ) ;
if ( V_217 > 4000000 )
V_2 -> V_119 = V_226 ;
V_2 -> V_50 = F_99 ( & V_227 ,
V_228 ,
V_229 |
V_230 , 0 , 0 ) ;
if ( ! V_2 -> V_50 ) {
F_5 ( V_2 -> V_7 , L_69 ) ;
V_6 = - V_75 ;
goto V_231;
}
F_100 ( V_2 -> V_50 , V_2 -> V_7 ) ;
F_101 ( V_2 -> V_50 , V_2 ) ;
F_102 ( V_8 , V_2 ) ;
V_212 = F_83 ( V_211 ) ;
F_103 ( V_2 -> V_7 , V_212 ) ;
F_104 ( V_2 -> V_7 ) ;
V_6 = F_77 ( V_2 ) ;
if ( V_6 )
goto V_232;
V_6 = F_105 ( V_2 -> V_50 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_70 ,
V_6 ) ;
goto V_233;
}
return 0 ;
V_233:
F_80 ( V_2 ) ;
V_232:
F_106 ( V_2 -> V_50 ) ;
V_231:
F_76 ( V_2 -> V_206 ) ;
V_225:
F_107 ( & V_2 -> V_86 ) ;
return V_6 ;
}
static int F_108 ( struct V_215 * V_8 )
{
struct V_1 * V_2 = F_109 ( V_8 ) ;
F_38 ( & V_2 -> V_86 ) ;
F_80 ( V_2 ) ;
F_39 ( & V_2 -> V_86 ) ;
F_110 ( V_2 -> V_50 ) ;
F_106 ( V_2 -> V_50 ) ;
F_76 ( V_2 -> V_206 ) ;
F_107 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_111 ( struct V_234 * V_7 )
{
struct V_215 * V_8 = F_112 ( V_7 ) ;
struct V_1 * V_2 = F_109 ( V_8 ) ;
F_3 ( V_7 , L_71 ) ;
F_38 ( & V_2 -> V_86 ) ;
F_80 ( V_2 ) ;
F_39 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_113 ( struct V_234 * V_7 )
{
struct V_215 * V_8 = F_112 ( V_7 ) ;
struct V_1 * V_2 = F_109 ( V_8 ) ;
int V_6 ;
F_3 ( V_7 , L_72 ) ;
F_38 ( & V_2 -> V_86 ) ;
V_6 = F_77 ( V_2 ) ;
F_39 ( & V_2 -> V_86 ) ;
return V_6 ;
}
static int F_114 ( struct V_234 * V_7 )
{
struct V_215 * V_8 = F_112 ( V_7 ) ;
struct V_1 * V_2 = F_109 ( V_8 ) ;
int V_6 ;
F_3 ( V_7 , L_73 ) ;
F_38 ( & V_2 -> V_86 ) ;
V_6 = F_75 ( V_2 ) ;
F_39 ( & V_2 -> V_86 ) ;
return V_6 ;
}
static int F_115 ( struct V_234 * V_7 )
{
struct V_215 * V_8 = F_112 ( V_7 ) ;
struct V_1 * V_2 = F_109 ( V_8 ) ;
int V_6 ;
F_3 ( V_7 , L_74 ) ;
V_6 = F_72 ( V_2 ) ;
if ( ! V_6 )
F_46 ( V_7 ) ;
return V_6 ;
}
