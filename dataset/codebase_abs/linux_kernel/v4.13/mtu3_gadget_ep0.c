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
V_2 -> V_3 = V_4 ;
F_7 ( V_2 -> V_19 , L_10 ,
V_34 ? L_11 : L_12 , F_1 ( V_2 ) ) ;
}
static void F_19 ( struct V_42 * V_43 , struct V_9 * V_10 )
{}
static void F_20 ( struct V_42 * V_43 , struct V_9 * V_10 )
{
struct V_44 * V_45 ;
struct V_1 * V_2 ;
struct V_46 V_47 ;
memcpy ( & V_47 , V_10 -> V_48 , sizeof( V_47 ) ) ;
V_45 = F_21 ( V_10 ) ;
V_2 = V_45 -> V_2 ;
F_7 ( V_2 -> V_19 , L_13 ,
V_47 . V_49 , V_47 . V_50 , V_47 . V_51 , V_47 . V_52 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_15 ;
T_2 V_53 = F_23 ( V_13 -> V_54 ) ;
if ( F_24 ( V_53 != 6 ) ) {
F_25 ( V_2 -> V_19 , L_14 ,
V_20 , V_53 ) ;
return - V_55 ;
}
V_2 -> V_56 . V_22 = V_2 -> V_11 ;
V_2 -> V_56 . V_57 . V_53 = 6 ;
V_2 -> V_56 . V_57 . V_48 = V_2 -> V_58 ;
V_2 -> V_56 . V_57 . V_59 = F_20 ;
V_15 = F_26 ( V_2 -> V_11 , & V_2 -> V_56 ) ;
return V_15 < 0 ? V_15 : 1 ;
}
static int
F_27 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
struct V_21 * V_22 = NULL ;
int V_60 = 1 ;
T_1 V_61 [ 2 ] = { 0 , 0 } ;
T_1 V_29 = 0 ;
int V_62 ;
switch ( V_13 -> V_63 & V_64 ) {
case V_65 :
V_61 [ 0 ] = V_2 -> V_66 << V_67 ;
V_61 [ 0 ] |= V_2 -> V_68 << V_69 ;
if ( V_2 -> V_18 . V_70 == V_71 ) {
V_61 [ 0 ] |= V_2 -> V_72 << V_73 ;
V_61 [ 0 ] |= V_2 -> V_74 << V_75 ;
}
F_7 ( V_2 -> V_19 , L_15 , V_20 ,
V_61 [ 0 ] , V_2 -> V_72 , V_2 -> V_74 ) ;
break;
case V_76 :
break;
case V_77 :
V_29 = ( T_1 ) F_23 ( V_13 -> V_78 ) ;
V_62 = V_29 & V_79 ;
V_29 &= V_80 ;
if ( V_29 >= V_2 -> V_81 ) {
V_60 = - V_55 ;
break;
}
if ( ! V_29 )
break;
V_22 = ( V_62 ? V_2 -> V_82 : V_2 -> V_83 ) + V_29 ;
if ( ! V_22 -> V_84 ) {
V_60 = - V_55 ;
break;
}
if ( V_22 -> V_85 & V_86 )
V_61 [ 0 ] |= 1 << V_87 ;
break;
default:
V_60 = 0 ;
break;
}
if ( V_60 > 0 ) {
int V_15 ;
F_7 ( V_2 -> V_19 , L_16 , * ( T_2 * ) V_61 ) ;
memcpy ( V_2 -> V_58 , V_61 , sizeof( V_61 ) ) ;
V_2 -> V_56 . V_22 = V_2 -> V_11 ;
V_2 -> V_56 . V_57 . V_53 = 2 ;
V_2 -> V_56 . V_57 . V_48 = & V_2 -> V_58 ;
V_2 -> V_56 . V_57 . V_59 = F_19 ;
V_15 = F_26 ( V_2 -> V_11 , & V_2 -> V_56 ) ;
if ( V_15 < 0 )
V_60 = V_15 ;
}
return V_60 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
void T_3 * V_36 = V_2 -> V_26 ;
int V_60 = 1 ;
switch ( F_23 ( V_13 -> V_78 ) >> 8 ) {
case V_88 :
F_7 ( V_2 -> V_19 , L_17 ) ;
V_2 -> V_89 = V_90 ;
break;
case V_91 :
F_7 ( V_2 -> V_19 , L_18 ) ;
V_2 -> V_89 = V_92 ;
break;
case V_93 :
F_7 ( V_2 -> V_19 , L_19 ) ;
V_2 -> V_89 = V_94 ;
break;
case V_95 :
F_7 ( V_2 -> V_19 , L_20 ) ;
V_2 -> V_89 = V_96 ;
break;
default:
V_60 = - V_55 ;
goto V_97;
}
V_2 -> V_98 = true ;
if ( V_2 -> V_89 == V_96 )
F_15 ( V_2 ) ;
F_18 ( V_36 , V_99 , V_2 -> V_89 ) ;
V_2 -> V_3 = V_4 ;
V_97:
return V_60 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_12 * V_13 , bool V_34 )
{
void T_3 * V_36 = V_2 -> V_26 ;
int V_60 = - V_55 ;
T_4 V_100 ;
switch ( F_23 ( V_13 -> V_101 ) ) {
case V_69 :
V_2 -> V_68 = ! ! V_34 ;
V_60 = 1 ;
break;
case V_102 :
if ( ! V_34 || ( V_2 -> V_18 . V_70 != V_103 ) ||
( F_23 ( V_13 -> V_78 ) & 0xff ) )
break;
V_60 = F_28 ( V_2 , V_13 ) ;
break;
case V_104 :
if ( V_2 -> V_18 . V_70 != V_71 ||
V_2 -> V_18 . V_105 != V_106 )
break;
V_100 = F_17 ( V_36 , V_107 ) ;
if ( V_34 )
V_100 |= V_108 ;
else
V_100 &= ~ V_108 ;
F_18 ( V_36 , V_107 , V_100 ) ;
V_2 -> V_72 = ! ! V_34 ;
V_60 = 1 ;
break;
case V_109 :
if ( V_2 -> V_18 . V_70 != V_71 ||
V_2 -> V_18 . V_105 != V_106 )
break;
V_100 = F_17 ( V_36 , V_107 ) ;
if ( V_34 )
V_100 |= V_110 ;
else
V_100 &= ~ V_110 ;
F_18 ( V_36 , V_107 , V_100 ) ;
V_2 -> V_74 = ! ! V_34 ;
V_60 = 1 ;
break;
default:
V_60 = - V_55 ;
break;
}
return V_60 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_12 * V_13 , bool V_34 )
{
struct V_21 * V_22 ;
int V_60 = - V_55 ;
int V_62 ;
T_2 V_31 ;
T_2 V_28 ;
T_1 V_29 ;
V_31 = F_23 ( V_13 -> V_101 ) ;
V_28 = F_23 ( V_13 -> V_78 ) ;
switch ( V_13 -> V_63 & V_64 ) {
case V_65 :
V_60 = F_29 ( V_2 , V_13 , V_34 ) ;
break;
case V_76 :
if ( ( V_31 == V_111 )
&& ( V_2 -> V_18 . V_70 == V_71 ) ) {
V_60 = 0 ;
}
break;
case V_77 :
V_29 = V_28 & V_80 ;
if ( V_29 == 0 || V_29 >= V_2 -> V_81 ||
V_31 != V_87 )
break;
V_62 = V_28 & V_79 ;
V_22 = ( V_62 ? V_2 -> V_82 : V_2 -> V_83 ) + V_29 ;
if ( ! V_22 -> V_84 )
break;
V_60 = 1 ;
if ( V_22 -> V_112 )
break;
F_31 ( V_22 , V_34 ) ;
break;
default:
V_60 = 0 ;
break;
}
return V_60 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
void T_3 * V_36 = V_2 -> V_26 ;
enum V_113 V_105 = V_2 -> V_18 . V_105 ;
int V_60 = - V_55 ;
T_4 V_114 ;
T_2 V_31 ;
V_31 = F_23 ( V_13 -> V_101 ) ;
switch ( V_13 -> V_115 ) {
case V_116 :
V_2 -> V_117 = ( T_1 ) ( V_31 & 0x7f ) ;
F_7 ( V_2 -> V_19 , L_21 , V_2 -> V_117 ) ;
V_114 = F_17 ( V_36 , V_118 ) ;
V_114 &= ~ V_119 ;
V_114 |= F_33 ( V_2 -> V_117 ) ;
F_18 ( V_36 , V_118 , V_114 ) ;
if ( V_2 -> V_117 )
F_34 ( & V_2 -> V_18 , V_120 ) ;
else
F_34 ( & V_2 -> V_18 , V_121 ) ;
V_60 = 1 ;
break;
case V_122 :
if ( V_105 == V_120 ) {
F_34 ( & V_2 -> V_18 ,
V_106 ) ;
} else if ( V_105 == V_106 ) {
if ( ! V_31 )
F_34 ( & V_2 -> V_18 ,
V_120 ) ;
}
V_60 = 0 ;
break;
case V_123 :
V_60 = F_30 ( V_2 , V_13 , 0 ) ;
break;
case V_124 :
V_60 = F_30 ( V_2 , V_13 , 1 ) ;
break;
case V_125 :
V_60 = F_27 ( V_2 , V_13 ) ;
break;
case V_126 :
V_60 = F_22 ( V_2 , V_13 ) ;
break;
case V_127 :
V_60 = 1 ;
break;
default:
V_60 = 0 ;
}
return V_60 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
struct V_9 * V_10 ;
void T_3 * V_36 = V_2 -> V_26 ;
T_4 V_128 ;
T_4 V_37 ;
T_2 V_129 = 0 ;
F_7 ( V_2 -> V_19 , L_22 , V_20 ) ;
V_37 = F_17 ( V_36 , V_38 ) & V_39 ;
V_45 = F_36 ( V_2 ) ;
V_10 = & V_45 -> V_57 ;
if ( V_10 ) {
void * V_48 = V_10 -> V_48 + V_10 -> V_130 ;
unsigned int V_24 = V_10 -> V_53 - V_10 -> V_130 ;
V_129 = F_17 ( V_36 , V_131 ) ;
if ( V_129 > V_24 ) {
V_10 -> V_132 = - V_133 ;
V_129 = V_24 ;
}
F_12 ( V_2 -> V_11 , V_48 , V_129 ) ;
V_10 -> V_130 += V_129 ;
V_37 |= V_134 ;
V_128 = V_2 -> V_18 . V_11 -> V_135 ;
if ( V_129 < V_128 || V_10 -> V_130 == V_10 -> V_53 ) {
V_2 -> V_3 = V_4 ;
F_7 ( V_2 -> V_19 , L_23 ,
F_1 ( V_2 ) ) ;
V_37 |= V_136 ;
} else {
V_10 = NULL ;
}
} else {
V_37 |= V_134 | V_40 ;
F_7 ( V_2 -> V_19 , L_24 , V_20 ) ;
}
F_18 ( V_36 , V_38 , V_37 ) ;
if ( V_10 )
F_2 ( V_2 , V_10 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_36 ( V_2 ) ;
struct V_9 * V_10 ;
T_4 V_37 ;
T_1 * V_23 ;
T_1 V_129 ;
T_4 V_128 ;
F_7 ( V_2 -> V_19 , L_22 , V_20 ) ;
if ( ! V_45 )
return;
V_128 = V_2 -> V_18 . V_11 -> V_135 ;
V_10 = & V_45 -> V_57 ;
V_23 = ( T_1 * ) V_10 -> V_48 + V_10 -> V_130 ;
V_129 = F_38 ( V_128 , V_10 -> V_53 - V_10 -> V_130 ) ;
if ( V_129 )
F_8 ( V_2 -> V_11 , V_23 , V_129 ) ;
F_7 ( V_2 -> V_19 , L_25 ,
V_20 , V_10 -> V_130 , V_10 -> V_53 , V_129 , V_128 , V_10 -> V_137 ) ;
V_10 -> V_130 += V_129 ;
if ( ( V_129 < V_128 )
|| ( ( V_10 -> V_130 == V_10 -> V_53 ) && ! V_10 -> V_137 ) )
V_2 -> V_3 = V_7 ;
V_37 = F_17 ( V_2 -> V_26 , V_38 ) & V_39 ;
F_18 ( V_2 -> V_26 , V_38 , V_37 | V_138 ) ;
F_7 ( V_2 -> V_19 , L_26 , V_20 ,
F_17 ( V_2 -> V_26 , V_38 ) ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_44 * V_45 ;
T_4 V_129 ;
T_4 V_37 ;
V_37 = F_17 ( V_2 -> V_26 , V_38 ) & V_39 ;
V_129 = F_17 ( V_2 -> V_26 , V_131 ) ;
F_12 ( V_2 -> V_11 , ( T_1 * ) V_13 , V_129 ) ;
F_7 ( V_2 -> V_19 , L_27 ,
V_13 -> V_63 , V_13 -> V_115 ,
F_23 ( V_13 -> V_101 ) , F_23 ( V_13 -> V_78 ) ,
F_23 ( V_13 -> V_54 ) ) ;
V_45 = F_36 ( V_2 ) ;
if ( V_45 )
F_2 ( V_2 , & V_45 -> V_57 ) ;
if ( F_23 ( V_13 -> V_54 ) == 0 ) {
;
} else if ( V_13 -> V_63 & V_79 ) {
F_18 ( V_2 -> V_26 , V_38 ,
V_37 | V_139 | V_140 ) ;
V_2 -> V_3 = V_5 ;
} else {
F_18 ( V_2 -> V_26 , V_38 ,
( V_37 | V_139 ) & ( ~ V_140 ) ) ;
V_2 -> V_3 = V_6 ;
}
}
static int F_40 ( struct V_1 * V_2 )
__releases( V_2 -> V_14 )
__acquires( V_2 -> V_14 )
{
struct V_12 V_13 ;
struct V_44 * V_45 ;
void T_3 * V_36 = V_2 -> V_26 ;
int V_60 = 0 ;
F_39 ( V_2 , & V_13 ) ;
if ( ( V_13 . V_63 & V_141 ) == V_142 )
V_60 = F_32 ( V_2 , & V_13 ) ;
F_7 ( V_2 -> V_19 , L_28 ,
V_60 , F_1 ( V_2 ) ) ;
if ( V_60 < 0 )
goto V_143;
else if ( V_60 > 0 )
goto V_144;
V_60 = F_4 ( V_2 , & V_13 ) ;
if ( V_60 < 0 ) {
V_143:
F_7 ( V_2 -> V_19 , L_29 , V_20 , V_60 ) ;
F_16 ( V_2 -> V_11 , true ,
F_23 ( V_13 . V_54 ) ? 0 : V_139 ) ;
return 0 ;
}
V_144:
if ( V_2 -> V_98 ) {
;
} else if ( F_23 ( V_13 . V_54 ) == 0 ) {
F_18 ( V_36 , V_38 ,
( F_17 ( V_36 , V_38 ) & V_39 )
| V_139 | V_136 ) ;
V_45 = F_36 ( V_2 ) ;
if ( V_45 && ! V_45 -> V_57 . V_53 )
F_2 ( V_2 , & V_45 -> V_57 ) ;
}
return 0 ;
}
T_5 F_41 ( struct V_1 * V_2 )
{
void T_3 * V_36 = V_2 -> V_26 ;
struct V_44 * V_45 ;
T_4 V_145 ;
T_5 V_15 = V_146 ;
T_4 V_37 ;
T_4 V_24 ;
V_145 = F_17 ( V_36 , V_147 ) ;
V_145 &= F_17 ( V_36 , V_148 ) ;
F_18 ( V_36 , V_147 , V_145 ) ;
if ( ! ( V_145 & V_149 ) )
return V_146 ;
V_37 = F_17 ( V_36 , V_38 ) ;
F_7 ( V_2 -> V_19 , L_30 , V_20 , V_37 ) ;
if ( V_37 & V_41 ) {
F_16 ( V_2 -> V_11 , false , 0 ) ;
V_37 = F_17 ( V_36 , V_38 ) ;
V_15 = V_150 ;
}
F_7 ( V_2 -> V_19 , L_31 , F_1 ( V_2 ) ) ;
switch ( V_2 -> V_3 ) {
case V_5 :
if ( ( V_37 & V_151 ) == 0 ) {
F_37 ( V_2 ) ;
V_15 = V_150 ;
}
break;
case V_6 :
if ( V_37 & V_134 ) {
F_35 ( V_2 ) ;
V_15 = V_150 ;
}
break;
case V_7 :
F_18 ( V_36 , V_38 ,
( V_37 & V_39 ) | V_136 ) ;
V_45 = F_36 ( V_2 ) ;
if ( V_45 )
F_2 ( V_2 , & V_45 -> V_57 ) ;
V_2 -> V_3 = V_4 ;
V_15 = V_150 ;
F_7 ( V_2 -> V_19 , L_31 , F_1 ( V_2 ) ) ;
break;
case V_4 :
if ( ! ( V_37 & V_139 ) )
break;
V_24 = F_17 ( V_36 , V_131 ) ;
if ( V_24 != 8 ) {
F_25 ( V_2 -> V_19 , L_32 , V_24 ) ;
break;
}
F_40 ( V_2 ) ;
V_15 = V_150 ;
break;
default:
F_16 ( V_2 -> V_11 , true , 0 ) ;
F_42 ( 1 ) ;
break;
}
return V_15 ;
}
static int F_43 ( struct V_42 * V_43 ,
const struct V_152 * V_84 )
{
return - V_55 ;
}
static int F_44 ( struct V_42 * V_43 )
{
return - V_55 ;
}
static int F_26 ( struct V_21 * V_22 , struct V_44 * V_45 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
V_45 -> V_2 = V_2 ;
V_45 -> V_57 . V_130 = 0 ;
V_45 -> V_57 . V_132 = - V_153 ;
F_7 ( V_2 -> V_19 , L_33 , V_20 ,
V_22 -> V_154 , F_1 ( V_2 ) , V_45 -> V_57 . V_53 ) ;
if ( ! F_45 ( & V_22 -> V_155 ) )
return - V_156 ;
switch ( V_2 -> V_3 ) {
case V_4 :
case V_6 :
case V_5 :
break;
default:
F_25 ( V_2 -> V_19 , L_34 , V_20 ,
F_1 ( V_2 ) ) ;
return - V_55 ;
}
F_46 ( & V_45 -> V_157 , & V_22 -> V_155 ) ;
if ( V_2 -> V_3 == V_5 )
F_37 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_42 * V_43 ,
struct V_9 * V_10 , T_6 V_158 )
{
struct V_21 * V_22 ;
struct V_44 * V_45 ;
struct V_1 * V_2 ;
unsigned long V_85 ;
int V_15 = 0 ;
if ( ! V_43 || ! V_10 )
return - V_55 ;
V_22 = F_48 ( V_43 ) ;
V_2 = V_22 -> V_2 ;
V_45 = F_21 ( V_10 ) ;
F_49 ( & V_2 -> V_14 , V_85 ) ;
V_15 = F_26 ( V_22 , V_45 ) ;
F_50 ( & V_2 -> V_14 , V_85 ) ;
return V_15 ;
}
static int F_51 ( struct V_42 * V_43 , struct V_9 * V_10 )
{
return - V_55 ;
}
static int F_52 ( struct V_42 * V_43 , int V_31 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
unsigned long V_85 ;
int V_15 = 0 ;
if ( ! V_43 || ! V_31 )
return - V_55 ;
V_22 = F_48 ( V_43 ) ;
V_2 = V_22 -> V_2 ;
F_7 ( V_2 -> V_19 , L_22 , V_20 ) ;
F_49 ( & V_2 -> V_14 , V_85 ) ;
if ( ! F_45 ( & V_22 -> V_155 ) ) {
V_15 = - V_156 ;
goto V_159;
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
V_15 = - V_55 ;
}
V_159:
F_50 ( & V_2 -> V_14 , V_85 ) ;
return V_15 ;
}
