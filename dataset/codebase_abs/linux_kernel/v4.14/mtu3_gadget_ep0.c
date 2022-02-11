static char * F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return L_1 ;
case V_5 :
return L_2 ;
case V_6 :
return L_3 ;
case V_7 :
return L_4 ;
case V_8 :
return L_5 ;
default:
return L_6 ;
}
}
static void F_2 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_3 ( V_2 -> V_11 , V_10 , 0 ) ;
}
static int
F_4 ( struct V_1 * V_2 , const struct V_12 * V_13 )
__releases( V_2 -> V_14 )
__acquires( V_2 -> V_14 )
{
int V_15 ;
if ( ! V_2 -> V_16 )
return - V_17 ;
F_5 ( & V_2 -> V_14 ) ;
V_15 = V_2 -> V_16 -> V_13 ( & V_2 -> V_18 , V_13 ) ;
F_6 ( & V_2 -> V_14 ) ;
F_7 ( V_2 -> V_19 , L_7 , V_20 , V_15 ) ;
return V_15 ;
}
static void F_8 ( struct V_21 * V_22 , const T_1 * V_23 , T_2 V_24 )
{
void T_3 * V_25 = V_22 -> V_2 -> V_26 + V_27 ;
T_2 V_28 = 0 ;
F_7 ( V_22 -> V_2 -> V_19 , L_8 ,
V_20 , V_22 -> V_29 , V_24 , V_23 ) ;
if ( V_24 >= 4 ) {
F_9 ( V_25 , V_23 , V_24 >> 2 ) ;
V_28 = V_24 & ~ 0x03 ;
}
if ( V_24 & 0x02 ) {
F_10 ( * ( T_2 * ) & V_23 [ V_28 ] , V_25 ) ;
V_28 += 2 ;
}
if ( V_24 & 0x01 )
F_11 ( V_23 [ V_28 ] , V_25 ) ;
}
static void F_12 ( struct V_21 * V_22 , T_1 * V_30 , T_2 V_24 )
{
void T_3 * V_25 = V_22 -> V_2 -> V_26 + V_27 ;
T_4 V_31 ;
T_2 V_28 = 0 ;
F_7 ( V_22 -> V_2 -> V_19 , L_9 ,
V_20 , V_22 -> V_29 , V_24 , V_30 ) ;
if ( V_24 >= 4 ) {
F_13 ( V_25 , V_30 , V_24 >> 2 ) ;
V_28 = V_24 & ~ 0x03 ;
}
if ( V_24 & 0x3 ) {
V_31 = F_14 ( V_25 ) ;
memcpy ( & V_30 [ V_28 ] , & V_31 , V_24 & 0x3 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_11 , V_32 , sizeof( V_32 ) ) ;
}
static void F_16 ( struct V_21 * V_33 , bool V_34 , T_4 V_35 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
void T_3 * V_36 = V_2 -> V_26 ;
T_4 V_37 ;
V_37 = F_17 ( V_36 , V_38 ) & V_39 ;
if ( V_34 )
V_37 |= V_40 | V_35 ;
else
V_37 = ( V_37 & ~ V_40 ) | V_41 ;
F_18 ( V_2 -> V_26 , V_38 , V_37 ) ;
V_2 -> V_42 = false ;
V_2 -> V_3 = V_4 ;
F_7 ( V_2 -> V_19 , L_10 ,
V_34 ? L_11 : L_12 , F_1 ( V_2 ) ) ;
}
static void F_19 ( struct V_43 * V_44 , struct V_9 * V_10 )
{}
static void F_20 ( struct V_43 * V_44 , struct V_9 * V_10 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 ;
struct V_47 V_48 ;
memcpy ( & V_48 , V_10 -> V_49 , sizeof( V_48 ) ) ;
V_46 = F_21 ( V_10 ) ;
V_2 = V_46 -> V_2 ;
F_7 ( V_2 -> V_19 , L_13 ,
V_48 . V_50 , V_48 . V_51 , V_48 . V_52 , V_48 . V_53 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_15 ;
T_2 V_54 = F_23 ( V_13 -> V_55 ) ;
if ( F_24 ( V_54 != 6 ) ) {
F_25 ( V_2 -> V_19 , L_14 ,
V_20 , V_54 ) ;
return - V_56 ;
}
V_2 -> V_57 . V_22 = V_2 -> V_11 ;
V_2 -> V_57 . V_58 . V_54 = 6 ;
V_2 -> V_57 . V_58 . V_49 = V_2 -> V_59 ;
V_2 -> V_57 . V_58 . V_60 = F_20 ;
V_15 = F_26 ( V_2 -> V_11 , & V_2 -> V_57 ) ;
return V_15 < 0 ? V_15 : 1 ;
}
static int
F_27 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
struct V_21 * V_22 = NULL ;
int V_61 = 1 ;
T_1 V_62 [ 2 ] = { 0 , 0 } ;
T_1 V_29 = 0 ;
int V_63 ;
switch ( V_13 -> V_64 & V_65 ) {
case V_66 :
V_62 [ 0 ] = V_2 -> V_67 << V_68 ;
V_62 [ 0 ] |= V_2 -> V_69 << V_70 ;
if ( V_2 -> V_18 . V_71 == V_72 ) {
V_62 [ 0 ] |= V_2 -> V_73 << V_74 ;
V_62 [ 0 ] |= V_2 -> V_75 << V_76 ;
}
F_7 ( V_2 -> V_19 , L_15 , V_20 ,
V_62 [ 0 ] , V_2 -> V_73 , V_2 -> V_75 ) ;
break;
case V_77 :
break;
case V_78 :
V_29 = ( T_1 ) F_23 ( V_13 -> V_79 ) ;
V_63 = V_29 & V_80 ;
V_29 &= V_81 ;
if ( V_29 >= V_2 -> V_82 ) {
V_61 = - V_56 ;
break;
}
if ( ! V_29 )
break;
V_22 = ( V_63 ? V_2 -> V_83 : V_2 -> V_84 ) + V_29 ;
if ( ! V_22 -> V_85 ) {
V_61 = - V_56 ;
break;
}
if ( V_22 -> V_86 & V_87 )
V_62 [ 0 ] |= 1 << V_88 ;
break;
default:
V_61 = 0 ;
break;
}
if ( V_61 > 0 ) {
int V_15 ;
F_7 ( V_2 -> V_19 , L_16 , * ( T_2 * ) V_62 ) ;
memcpy ( V_2 -> V_59 , V_62 , sizeof( V_62 ) ) ;
V_2 -> V_57 . V_22 = V_2 -> V_11 ;
V_2 -> V_57 . V_58 . V_54 = 2 ;
V_2 -> V_57 . V_58 . V_49 = & V_2 -> V_59 ;
V_2 -> V_57 . V_58 . V_60 = F_19 ;
V_15 = F_26 ( V_2 -> V_11 , & V_2 -> V_57 ) ;
if ( V_15 < 0 )
V_61 = V_15 ;
}
return V_61 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
void T_3 * V_36 = V_2 -> V_26 ;
int V_61 = 1 ;
switch ( F_23 ( V_13 -> V_79 ) >> 8 ) {
case V_89 :
F_7 ( V_2 -> V_19 , L_17 ) ;
V_2 -> V_90 = V_91 ;
break;
case V_92 :
F_7 ( V_2 -> V_19 , L_18 ) ;
V_2 -> V_90 = V_93 ;
break;
case V_94 :
F_7 ( V_2 -> V_19 , L_19 ) ;
V_2 -> V_90 = V_95 ;
break;
case V_96 :
F_7 ( V_2 -> V_19 , L_20 ) ;
V_2 -> V_90 = V_97 ;
break;
default:
V_61 = - V_56 ;
goto V_98;
}
V_2 -> V_99 = true ;
if ( V_2 -> V_90 == V_97 )
F_15 ( V_2 ) ;
F_18 ( V_36 , V_100 , V_2 -> V_90 ) ;
V_2 -> V_3 = V_4 ;
V_98:
return V_61 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_12 * V_13 , bool V_34 )
{
void T_3 * V_36 = V_2 -> V_26 ;
int V_61 = - V_56 ;
T_4 V_101 ;
switch ( F_23 ( V_13 -> V_102 ) ) {
case V_70 :
V_2 -> V_69 = ! ! V_34 ;
V_61 = 1 ;
break;
case V_103 :
if ( ! V_34 || ( V_2 -> V_18 . V_71 != V_104 ) ||
( F_23 ( V_13 -> V_79 ) & 0xff ) )
break;
V_61 = F_28 ( V_2 , V_13 ) ;
break;
case V_105 :
if ( V_2 -> V_18 . V_71 != V_72 ||
V_2 -> V_18 . V_106 != V_107 )
break;
V_101 = F_17 ( V_36 , V_108 ) ;
if ( V_34 )
V_101 |= V_109 ;
else
V_101 &= ~ V_109 ;
F_18 ( V_36 , V_108 , V_101 ) ;
V_2 -> V_73 = ! ! V_34 ;
V_61 = 1 ;
break;
case V_110 :
if ( V_2 -> V_18 . V_71 != V_72 ||
V_2 -> V_18 . V_106 != V_107 )
break;
V_101 = F_17 ( V_36 , V_108 ) ;
if ( V_34 )
V_101 |= V_111 ;
else
V_101 &= ~ V_111 ;
F_18 ( V_36 , V_108 , V_101 ) ;
V_2 -> V_75 = ! ! V_34 ;
V_61 = 1 ;
break;
default:
V_61 = - V_56 ;
break;
}
return V_61 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_12 * V_13 , bool V_34 )
{
struct V_21 * V_22 ;
int V_61 = - V_56 ;
int V_63 ;
T_2 V_31 ;
T_2 V_28 ;
T_1 V_29 ;
V_31 = F_23 ( V_13 -> V_102 ) ;
V_28 = F_23 ( V_13 -> V_79 ) ;
switch ( V_13 -> V_64 & V_65 ) {
case V_66 :
V_61 = F_29 ( V_2 , V_13 , V_34 ) ;
break;
case V_77 :
if ( ( V_31 == V_112 )
&& ( V_2 -> V_18 . V_71 == V_72 ) ) {
V_61 = 0 ;
}
break;
case V_78 :
V_29 = V_28 & V_81 ;
if ( V_29 == 0 || V_29 >= V_2 -> V_82 ||
V_31 != V_88 )
break;
V_63 = V_28 & V_80 ;
V_22 = ( V_63 ? V_2 -> V_83 : V_2 -> V_84 ) + V_29 ;
if ( ! V_22 -> V_85 )
break;
V_61 = 1 ;
if ( V_22 -> V_113 )
break;
F_31 ( V_22 , V_34 ) ;
break;
default:
V_61 = 0 ;
break;
}
return V_61 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
void T_3 * V_36 = V_2 -> V_26 ;
enum V_114 V_106 = V_2 -> V_18 . V_106 ;
int V_61 = - V_56 ;
T_4 V_115 ;
T_2 V_31 ;
V_31 = F_23 ( V_13 -> V_102 ) ;
switch ( V_13 -> V_116 ) {
case V_117 :
V_2 -> V_118 = ( T_1 ) ( V_31 & 0x7f ) ;
F_7 ( V_2 -> V_19 , L_21 , V_2 -> V_118 ) ;
V_115 = F_17 ( V_36 , V_119 ) ;
V_115 &= ~ V_120 ;
V_115 |= F_33 ( V_2 -> V_118 ) ;
F_18 ( V_36 , V_119 , V_115 ) ;
if ( V_2 -> V_118 )
F_34 ( & V_2 -> V_18 , V_121 ) ;
else
F_34 ( & V_2 -> V_18 , V_122 ) ;
V_61 = 1 ;
break;
case V_123 :
if ( V_106 == V_121 ) {
F_34 ( & V_2 -> V_18 ,
V_107 ) ;
} else if ( V_106 == V_107 ) {
if ( ! V_31 )
F_34 ( & V_2 -> V_18 ,
V_121 ) ;
}
V_61 = 0 ;
break;
case V_124 :
V_61 = F_30 ( V_2 , V_13 , 0 ) ;
break;
case V_125 :
V_61 = F_30 ( V_2 , V_13 , 1 ) ;
break;
case V_126 :
V_61 = F_27 ( V_2 , V_13 ) ;
break;
case V_127 :
V_61 = F_22 ( V_2 , V_13 ) ;
break;
case V_128 :
V_61 = 1 ;
break;
default:
V_61 = 0 ;
}
return V_61 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
struct V_9 * V_10 ;
void T_3 * V_36 = V_2 -> V_26 ;
T_4 V_129 ;
T_4 V_37 ;
T_2 V_130 = 0 ;
F_7 ( V_2 -> V_19 , L_22 , V_20 ) ;
V_37 = F_17 ( V_36 , V_38 ) & V_39 ;
V_46 = F_36 ( V_2 ) ;
V_10 = & V_46 -> V_58 ;
if ( V_10 ) {
void * V_49 = V_10 -> V_49 + V_10 -> V_131 ;
unsigned int V_24 = V_10 -> V_54 - V_10 -> V_131 ;
V_130 = F_17 ( V_36 , V_132 ) ;
if ( V_130 > V_24 ) {
V_10 -> V_133 = - V_134 ;
V_130 = V_24 ;
}
F_12 ( V_2 -> V_11 , V_49 , V_130 ) ;
V_10 -> V_131 += V_130 ;
V_37 |= V_135 ;
V_129 = V_2 -> V_18 . V_11 -> V_136 ;
if ( V_130 < V_129 || V_10 -> V_131 == V_10 -> V_54 ) {
V_2 -> V_3 = V_4 ;
F_7 ( V_2 -> V_19 , L_23 ,
F_1 ( V_2 ) ) ;
V_37 |= V_137 ;
} else {
V_10 = NULL ;
}
} else {
V_37 |= V_135 | V_40 ;
F_7 ( V_2 -> V_19 , L_24 , V_20 ) ;
}
F_18 ( V_36 , V_38 , V_37 ) ;
if ( V_10 )
F_2 ( V_2 , V_10 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_36 ( V_2 ) ;
struct V_9 * V_10 ;
T_4 V_37 ;
T_1 * V_23 ;
T_1 V_130 ;
T_4 V_129 ;
F_7 ( V_2 -> V_19 , L_22 , V_20 ) ;
if ( ! V_46 )
return;
V_129 = V_2 -> V_18 . V_11 -> V_136 ;
V_10 = & V_46 -> V_58 ;
V_23 = ( T_1 * ) V_10 -> V_49 + V_10 -> V_131 ;
V_130 = F_38 ( V_129 , V_10 -> V_54 - V_10 -> V_131 ) ;
if ( V_130 )
F_8 ( V_2 -> V_11 , V_23 , V_130 ) ;
F_7 ( V_2 -> V_19 , L_25 ,
V_20 , V_10 -> V_131 , V_10 -> V_54 , V_130 , V_129 , V_10 -> V_138 ) ;
V_10 -> V_131 += V_130 ;
if ( ( V_130 < V_129 )
|| ( ( V_10 -> V_131 == V_10 -> V_54 ) && ! V_10 -> V_138 ) )
V_2 -> V_3 = V_7 ;
V_37 = F_17 ( V_2 -> V_26 , V_38 ) & V_39 ;
F_18 ( V_2 -> V_26 , V_38 , V_37 | V_139 ) ;
F_7 ( V_2 -> V_19 , L_26 , V_20 ,
F_17 ( V_2 -> V_26 , V_38 ) ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_45 * V_46 ;
T_4 V_130 ;
T_4 V_37 ;
V_37 = F_17 ( V_2 -> V_26 , V_38 ) & V_39 ;
V_130 = F_17 ( V_2 -> V_26 , V_132 ) ;
F_12 ( V_2 -> V_11 , ( T_1 * ) V_13 , V_130 ) ;
F_7 ( V_2 -> V_19 , L_27 ,
V_13 -> V_64 , V_13 -> V_116 ,
F_23 ( V_13 -> V_102 ) , F_23 ( V_13 -> V_79 ) ,
F_23 ( V_13 -> V_55 ) ) ;
V_46 = F_36 ( V_2 ) ;
if ( V_46 )
F_2 ( V_2 , & V_46 -> V_58 ) ;
if ( F_23 ( V_13 -> V_55 ) == 0 ) {
;
} else if ( V_13 -> V_64 & V_80 ) {
F_18 ( V_2 -> V_26 , V_38 ,
V_37 | V_140 | V_141 ) ;
V_2 -> V_3 = V_5 ;
} else {
F_18 ( V_2 -> V_26 , V_38 ,
( V_37 | V_140 ) & ( ~ V_141 ) ) ;
V_2 -> V_3 = V_6 ;
}
}
static int F_40 ( struct V_1 * V_2 )
__releases( V_2 -> V_14 )
__acquires( V_2 -> V_14 )
{
struct V_12 V_13 ;
struct V_45 * V_46 ;
void T_3 * V_36 = V_2 -> V_26 ;
int V_61 = 0 ;
F_39 ( V_2 , & V_13 ) ;
if ( ( V_13 . V_64 & V_142 ) == V_143 )
V_61 = F_32 ( V_2 , & V_13 ) ;
F_7 ( V_2 -> V_19 , L_28 ,
V_61 , F_1 ( V_2 ) ) ;
if ( V_61 < 0 )
goto V_144;
else if ( V_61 > 0 )
goto V_145;
V_61 = F_4 ( V_2 , & V_13 ) ;
if ( V_61 < 0 ) {
V_144:
F_7 ( V_2 -> V_19 , L_29 , V_20 , V_61 ) ;
F_16 ( V_2 -> V_11 , true ,
F_23 ( V_13 . V_55 ) ? 0 : V_140 ) ;
return 0 ;
}
V_145:
if ( V_2 -> V_99 ) {
;
} else if ( V_61 == V_146 ) {
V_2 -> V_42 = true ;
} else if ( F_23 ( V_13 . V_55 ) == 0 ) {
F_18 ( V_36 , V_38 ,
( F_17 ( V_36 , V_38 ) & V_39 )
| V_140 | V_137 ) ;
V_46 = F_36 ( V_2 ) ;
if ( V_46 && ! V_46 -> V_58 . V_54 )
F_2 ( V_2 , & V_46 -> V_58 ) ;
}
return 0 ;
}
T_5 F_41 ( struct V_1 * V_2 )
{
void T_3 * V_36 = V_2 -> V_26 ;
struct V_45 * V_46 ;
T_4 V_147 ;
T_5 V_15 = V_148 ;
T_4 V_37 ;
T_4 V_24 ;
V_147 = F_17 ( V_36 , V_149 ) ;
V_147 &= F_17 ( V_36 , V_150 ) ;
F_18 ( V_36 , V_149 , V_147 ) ;
if ( ! ( V_147 & V_151 ) )
return V_148 ;
V_37 = F_17 ( V_36 , V_38 ) ;
F_7 ( V_2 -> V_19 , L_30 , V_20 , V_37 ) ;
if ( V_37 & V_41 ) {
F_16 ( V_2 -> V_11 , false , 0 ) ;
V_37 = F_17 ( V_36 , V_38 ) ;
V_15 = V_152 ;
}
F_7 ( V_2 -> V_19 , L_31 , F_1 ( V_2 ) ) ;
switch ( V_2 -> V_3 ) {
case V_5 :
if ( ( V_37 & V_153 ) == 0 ) {
F_37 ( V_2 ) ;
V_15 = V_152 ;
}
break;
case V_6 :
if ( V_37 & V_135 ) {
F_35 ( V_2 ) ;
V_15 = V_152 ;
}
break;
case V_7 :
F_18 ( V_36 , V_38 ,
( V_37 & V_39 ) | V_137 ) ;
V_46 = F_36 ( V_2 ) ;
if ( V_46 )
F_2 ( V_2 , & V_46 -> V_58 ) ;
V_2 -> V_3 = V_4 ;
V_15 = V_152 ;
F_7 ( V_2 -> V_19 , L_31 , F_1 ( V_2 ) ) ;
break;
case V_4 :
if ( ! ( V_37 & V_140 ) )
break;
V_24 = F_17 ( V_36 , V_132 ) ;
if ( V_24 != 8 ) {
F_25 ( V_2 -> V_19 , L_32 , V_24 ) ;
break;
}
F_40 ( V_2 ) ;
V_15 = V_152 ;
break;
default:
F_16 ( V_2 -> V_11 , true , 0 ) ;
F_42 ( 1 ) ;
break;
}
return V_15 ;
}
static int F_43 ( struct V_43 * V_44 ,
const struct V_154 * V_85 )
{
return - V_56 ;
}
static int F_44 ( struct V_43 * V_44 )
{
return - V_56 ;
}
static int F_26 ( struct V_21 * V_22 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_58 . V_131 = 0 ;
V_46 -> V_58 . V_133 = - V_155 ;
F_7 ( V_2 -> V_19 , L_33 , V_20 ,
V_22 -> V_156 , F_1 ( V_2 ) , V_46 -> V_58 . V_54 ) ;
switch ( V_2 -> V_3 ) {
case V_4 :
case V_6 :
case V_5 :
break;
default:
F_25 ( V_2 -> V_19 , L_34 , V_20 ,
F_1 ( V_2 ) ) ;
return - V_56 ;
}
if ( V_2 -> V_42 ) {
T_4 V_37 ;
V_2 -> V_42 = false ;
V_37 = F_17 ( V_2 -> V_26 , V_38 ) & V_39 ;
V_37 |= V_140 | V_137 ;
F_18 ( V_2 -> V_26 , V_38 , V_37 ) ;
return 0 ;
}
if ( ! F_45 ( & V_22 -> V_157 ) )
return - V_158 ;
F_46 ( & V_46 -> V_159 , & V_22 -> V_157 ) ;
if ( V_2 -> V_3 == V_5 )
F_37 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_43 * V_44 ,
struct V_9 * V_10 , T_6 V_160 )
{
struct V_21 * V_22 ;
struct V_45 * V_46 ;
struct V_1 * V_2 ;
unsigned long V_86 ;
int V_15 = 0 ;
if ( ! V_44 || ! V_10 )
return - V_56 ;
V_22 = F_48 ( V_44 ) ;
V_2 = V_22 -> V_2 ;
V_46 = F_21 ( V_10 ) ;
F_49 ( & V_2 -> V_14 , V_86 ) ;
V_15 = F_26 ( V_22 , V_46 ) ;
F_50 ( & V_2 -> V_14 , V_86 ) ;
return V_15 ;
}
static int F_51 ( struct V_43 * V_44 , struct V_9 * V_10 )
{
return - V_56 ;
}
static int F_52 ( struct V_43 * V_44 , int V_31 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
unsigned long V_86 ;
int V_15 = 0 ;
if ( ! V_44 || ! V_31 )
return - V_56 ;
V_22 = F_48 ( V_44 ) ;
V_2 = V_22 -> V_2 ;
F_7 ( V_2 -> V_19 , L_22 , V_20 ) ;
F_49 ( & V_2 -> V_14 , V_86 ) ;
if ( ! F_45 ( & V_22 -> V_157 ) ) {
V_15 = - V_158 ;
goto V_161;
}
switch ( V_2 -> V_3 ) {
case V_5 :
case V_7 :
case V_6 :
case V_4 :
F_16 ( V_2 -> V_11 , true , 0 ) ;
break;
default:
F_7 ( V_2 -> V_19 , L_35 ,
F_1 ( V_2 ) ) ;
V_15 = - V_56 ;
}
V_161:
F_50 ( & V_2 -> V_14 , V_86 ) ;
return V_15 ;
}
