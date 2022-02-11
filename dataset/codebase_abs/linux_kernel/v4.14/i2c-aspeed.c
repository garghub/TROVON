static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 ;
int V_5 = 0 ;
T_1 V_6 ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
V_6 = F_3 ( V_2 -> V_8 + V_9 ) ;
if ( V_6 & V_10 ) {
if ( V_6 & V_11 )
goto V_12;
F_4 ( V_2 -> V_13 , L_1 ,
V_6 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( V_15 , V_2 -> V_8 + V_9 ) ;
F_7 ( & V_2 -> V_7 , V_4 ) ;
V_3 = F_8 (
& V_2 -> V_14 , V_2 -> V_16 . V_17 ) ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
if ( V_3 == 0 )
goto V_18;
else if ( V_2 -> V_19 )
goto V_18;
else if ( ! ( F_3 ( V_2 -> V_8 + V_9 ) &
V_11 ) )
goto V_18;
} else {
F_4 ( V_2 -> V_13 , L_2 ,
V_6 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( V_20 ,
V_2 -> V_8 + V_9 ) ;
F_7 ( & V_2 -> V_7 , V_4 ) ;
V_3 = F_8 (
& V_2 -> V_14 , V_2 -> V_16 . V_17 ) ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
if ( V_3 == 0 )
goto V_18;
else if ( V_2 -> V_19 )
goto V_18;
else if ( ! ( F_3 ( V_2 -> V_8 + V_9 ) &
V_10 ) )
goto V_18;
}
V_12:
F_7 ( & V_2 -> V_7 , V_4 ) ;
return V_5 ;
V_18:
F_7 ( & V_2 -> V_7 , V_4 ) ;
return F_9 ( V_2 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
T_1 V_6 , V_21 , V_22 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
bool V_25 = true ;
T_2 V_26 ;
F_11 ( & V_2 -> V_7 ) ;
if ( ! V_24 ) {
V_25 = false ;
goto V_12;
}
V_6 = F_3 ( V_2 -> V_8 + V_9 ) ;
V_21 = F_3 ( V_2 -> V_8 + V_27 ) ;
if ( V_21 & V_28 ) {
V_22 |= V_28 ;
V_2 -> V_29 = V_30 ;
}
if ( V_2 -> V_29 == V_31 ) {
V_25 = false ;
goto V_12;
}
F_4 ( V_2 -> V_13 , L_3 ,
V_21 , V_6 ) ;
if ( V_21 & V_32 ) {
V_26 = F_3 ( V_2 -> V_8 + V_33 ) >> 8 ;
if ( V_2 -> V_29 == V_30 ) {
if ( V_26 & 0x1 )
V_2 -> V_29 =
V_34 ;
else
V_2 -> V_29 =
V_35 ;
}
V_22 |= V_32 ;
}
if ( V_21 & V_36 ) {
V_22 |= V_36 ;
V_2 -> V_29 = V_31 ;
}
if ( V_21 & V_37 ) {
V_22 |= V_37 ;
V_2 -> V_29 = V_31 ;
}
switch ( V_2 -> V_29 ) {
case V_34 :
if ( V_21 & V_38 )
F_12 ( V_2 -> V_13 , L_4 ) ;
V_2 -> V_29 = V_39 ;
F_13 ( V_24 , V_40 , & V_26 ) ;
F_6 ( V_26 , V_2 -> V_8 + V_33 ) ;
F_6 ( V_41 , V_2 -> V_8 + V_9 ) ;
break;
case V_39 :
V_22 |= V_38 ;
if ( ! ( V_21 & V_38 ) )
F_12 ( V_2 -> V_13 ,
L_5 ) ;
F_13 ( V_24 , V_42 , & V_26 ) ;
F_6 ( V_26 , V_2 -> V_8 + V_33 ) ;
F_6 ( V_41 , V_2 -> V_8 + V_9 ) ;
break;
case V_35 :
V_2 -> V_29 = V_43 ;
F_13 ( V_24 , V_44 , & V_26 ) ;
break;
case V_43 :
F_13 ( V_24 , V_45 , & V_26 ) ;
break;
case V_31 :
F_13 ( V_24 , V_46 , & V_26 ) ;
break;
default:
F_12 ( V_2 -> V_13 , L_6 ,
V_2 -> V_29 ) ;
break;
}
if ( V_22 != V_21 )
F_12 ( V_2 -> V_13 ,
L_7 ,
V_21 , V_22 ) ;
F_6 ( V_22 , V_2 -> V_8 + V_27 ) ;
V_12:
F_14 ( & V_2 -> V_7 ) ;
return V_25 ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_6 = V_47 | V_48 ;
struct V_49 * V_50 = & V_2 -> V_51 [ V_2 -> V_52 ] ;
T_2 V_53 = V_50 -> V_54 << 1 ;
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = 0 ;
if ( V_50 -> V_4 & V_58 ) {
V_53 |= 1 ;
V_6 |= V_59 ;
if ( V_50 -> V_60 == 1 && ! ( V_50 -> V_4 & V_61 ) )
V_6 |= V_62 ;
}
F_6 ( V_53 , V_2 -> V_8 + V_33 ) ;
F_6 ( V_6 , V_2 -> V_8 + V_9 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_55 = V_63 ;
F_6 ( V_15 , V_2 -> V_8 + V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 + 1 < V_2 -> V_64 ) {
V_2 -> V_52 ++ ;
F_15 ( V_2 ) ;
} else {
F_16 ( V_2 ) ;
}
}
static int F_18 ( T_1 V_21 )
{
if ( V_21 & V_65 )
return - V_66 ;
if ( V_21 & ( V_67 |
V_68 ) )
return - V_69 ;
if ( V_21 & ( V_70 ) )
return - V_71 ;
return 0 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
T_1 V_21 , V_22 = 0 , V_6 = 0 ;
struct V_49 * V_50 ;
T_2 V_72 ;
int V_5 ;
F_11 ( & V_2 -> V_7 ) ;
V_21 = F_3 ( V_2 -> V_8 + V_27 ) ;
F_6 ( V_21 , V_2 -> V_8 + V_27 ) ;
if ( V_21 & V_73 ) {
V_2 -> V_55 = V_74 ;
V_22 |= V_73 ;
goto V_75;
}
V_5 = F_18 ( V_21 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 , L_8 ,
V_21 ) ;
V_2 -> V_19 = V_5 ;
V_2 -> V_55 = V_74 ;
goto V_75;
}
if ( ! V_2 -> V_51 ) {
F_12 ( V_2 -> V_13 , L_9 ) ;
V_2 -> V_19 = - V_76 ;
if ( V_2 -> V_55 != V_63 )
F_16 ( V_2 ) ;
goto V_77;
}
V_50 = & V_2 -> V_51 [ V_2 -> V_52 ] ;
if ( V_2 -> V_55 == V_56 ) {
if ( F_20 ( ! ( V_21 & V_38 ) ) ) {
F_21 ( L_10 , V_50 -> V_54 ) ;
V_22 |= V_37 ;
V_2 -> V_19 = - V_78 ;
F_16 ( V_2 ) ;
goto V_77;
}
V_22 |= V_38 ;
if ( V_50 -> V_60 == 0 ) {
F_16 ( V_2 ) ;
goto V_77;
}
if ( V_50 -> V_4 & V_58 )
V_2 -> V_55 = V_79 ;
else
V_2 -> V_55 = V_80 ;
}
switch ( V_2 -> V_55 ) {
case V_81 :
if ( F_20 ( V_21 & V_37 ) ) {
F_4 ( V_2 -> V_13 , L_11 ) ;
V_22 |= V_37 ;
goto V_82;
} else if ( F_20 ( ! ( V_21 & V_38 ) ) ) {
F_12 ( V_2 -> V_13 , L_12 ) ;
goto V_82;
}
V_22 |= V_38 ;
case V_80 :
if ( V_2 -> V_57 < V_50 -> V_60 ) {
V_2 -> V_55 = V_81 ;
F_6 ( V_50 -> V_83 [ V_2 -> V_57 ++ ] ,
V_2 -> V_8 + V_33 ) ;
F_6 ( V_48 ,
V_2 -> V_8 + V_9 ) ;
} else {
F_17 ( V_2 ) ;
}
goto V_77;
case V_79 :
if ( ! ( V_21 & V_32 ) )
goto V_77;
case V_84 :
if ( F_20 ( ! ( V_21 & V_32 ) ) ) {
F_12 ( V_2 -> V_13 , L_13 ) ;
goto V_82;
}
V_22 |= V_32 ;
V_72 = F_3 ( V_2 -> V_8 + V_33 ) >> 8 ;
V_50 -> V_83 [ V_2 -> V_57 ++ ] = V_72 ;
if ( V_50 -> V_4 & V_61 ) {
if ( F_20 ( V_72 > V_85 ) ) {
V_2 -> V_19 = - V_71 ;
F_16 ( V_2 ) ;
goto V_77;
}
V_50 -> V_60 = V_72 +
( ( V_50 -> V_4 & V_86 ) ? 2 : 1 ) ;
V_50 -> V_4 &= ~ V_61 ;
}
if ( V_2 -> V_57 < V_50 -> V_60 ) {
V_2 -> V_55 = V_84 ;
V_6 = V_59 ;
if ( V_2 -> V_57 + 1 == V_50 -> V_60 )
V_6 |= V_62 ;
F_6 ( V_6 , V_2 -> V_8 + V_9 ) ;
} else {
F_17 ( V_2 ) ;
}
goto V_77;
case V_63 :
if ( F_20 ( ! ( V_21 & V_36 ) ) ) {
F_12 ( V_2 -> V_13 , L_14 ) ;
V_2 -> V_19 = - V_76 ;
} else {
V_22 |= V_36 ;
}
V_2 -> V_55 = V_74 ;
goto V_75;
case V_74 :
F_12 ( V_2 -> V_13 ,
L_15 ,
V_21 ) ;
V_2 -> V_19 = - V_76 ;
goto V_75;
default:
F_22 ( 1 , L_16 ) ;
V_2 -> V_55 = V_74 ;
V_2 -> V_19 = - V_87 ;
goto V_75;
}
V_82:
V_2 -> V_19 = - V_76 ;
F_16 ( V_2 ) ;
goto V_77;
V_75:
V_2 -> V_51 = NULL ;
if ( V_2 -> V_19 )
V_2 -> V_88 = V_2 -> V_19 ;
else
V_2 -> V_88 = V_2 -> V_52 + 1 ;
F_23 ( & V_2 -> V_14 ) ;
V_77:
if ( V_21 != V_22 )
F_12 ( V_2 -> V_13 ,
L_17 ,
V_21 , V_22 ) ;
F_14 ( & V_2 -> V_7 ) ;
return ! ! V_21 ;
}
static T_3 F_24 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
#if F_25 ( V_91 )
if ( F_10 ( V_2 ) ) {
F_4 ( V_2 -> V_13 , L_18 ) ;
return V_92 ;
}
#endif
return F_19 ( V_2 ) ? V_92 : V_93 ;
}
static int F_26 ( struct V_94 * V_16 ,
struct V_49 * V_51 , int V_95 )
{
struct V_1 * V_2 = F_27 ( V_16 ) ;
unsigned long V_3 , V_4 ;
int V_5 = 0 ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
V_2 -> V_19 = 0 ;
if ( F_3 ( V_2 -> V_8 + V_9 ) & V_96 ) {
F_7 ( & V_2 -> V_7 , V_4 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
}
V_2 -> V_19 = 0 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_52 = 0 ;
V_2 -> V_64 = V_95 ;
F_5 ( & V_2 -> V_14 ) ;
F_15 ( V_2 ) ;
F_7 ( & V_2 -> V_7 , V_4 ) ;
V_3 = F_8 ( & V_2 -> V_14 ,
V_2 -> V_16 . V_17 ) ;
if ( V_3 == 0 )
return - V_97 ;
else
return V_2 -> V_88 ;
}
static T_1 F_28 ( struct V_94 * V_16 )
{
return V_98 | V_99 | V_100 ;
}
static void F_29 ( struct V_1 * V_2 , T_4 V_53 )
{
T_1 V_101 , V_102 ;
V_101 = F_3 ( V_2 -> V_8 + V_103 ) ;
V_101 &= ~ V_104 ;
V_101 |= V_53 & V_104 ;
F_6 ( V_101 , V_2 -> V_8 + V_103 ) ;
V_102 = F_3 ( V_2 -> V_8 + V_105 ) ;
V_102 |= V_106 ;
F_6 ( V_102 , V_2 -> V_8 + V_105 ) ;
}
static int F_30 ( struct V_23 * V_107 )
{
struct V_1 * V_2 = F_27 ( V_107 -> V_108 ) ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
if ( V_2 -> V_24 ) {
F_7 ( & V_2 -> V_7 , V_4 ) ;
return - V_87 ;
}
F_29 ( V_2 , V_107 -> V_54 ) ;
V_2 -> V_24 = V_107 ;
V_2 -> V_29 = V_31 ;
F_7 ( & V_2 -> V_7 , V_4 ) ;
return 0 ;
}
static int F_31 ( struct V_23 * V_107 )
{
struct V_1 * V_2 = F_27 ( V_107 -> V_108 ) ;
T_1 V_102 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
if ( ! V_2 -> V_24 ) {
F_7 ( & V_2 -> V_7 , V_4 ) ;
return - V_87 ;
}
V_102 = F_3 ( V_2 -> V_8 + V_105 ) ;
V_102 &= ~ V_106 ;
F_6 ( V_102 , V_2 -> V_8 + V_105 ) ;
V_2 -> V_24 = NULL ;
F_7 ( & V_2 -> V_7 , V_4 ) ;
return 0 ;
}
static T_1 F_32 ( T_1 V_109 , T_1 V_110 )
{
T_1 V_111 , V_112 , V_113 , V_114 ;
V_111 = V_110 > V_109 ?
F_33 ( ( V_110 - 1 ) / V_109 ) + 1 : 0 ;
V_114 = ( V_110 + ( 1 << V_111 ) - 1 ) >> V_111 ;
V_113 = V_114 / 2 ;
V_112 = V_114 - V_113 ;
if ( V_112 )
V_112 -- ;
if ( V_113 )
V_113 -- ;
return ( ( V_112 << V_115 )
& V_116 )
| ( ( V_113 << V_117 )
& V_118 )
| ( V_111 & V_119 ) ;
}
static T_1 F_34 ( T_1 V_110 )
{
return F_32 ( 16 , V_110 ) ;
}
static T_1 F_35 ( T_1 V_110 )
{
return F_32 ( 32 , V_110 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_110 , V_120 ;
V_110 = F_37 ( V_2 -> V_121 , V_2 -> V_122 ) ;
V_120 = F_3 ( V_2 -> V_8 + V_123 ) ;
V_120 &= ( V_124 |
V_125 |
V_126 ) ;
V_120 |= V_2 -> V_127 ( V_110 ) ;
F_6 ( V_120 , V_2 -> V_8 + V_123 ) ;
F_6 ( V_128 , V_2 -> V_8 + V_129 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
T_1 V_132 = V_133 ;
int V_5 ;
F_6 ( 0 , V_2 -> V_8 + V_105 ) ;
V_5 = F_36 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! F_39 ( V_131 -> V_13 . V_134 , L_19 ) )
V_132 |= V_135 ;
F_6 ( F_3 ( V_2 -> V_8 + V_105 ) | V_132 ,
V_2 -> V_8 + V_105 ) ;
#if F_25 ( V_91 )
if ( V_2 -> V_24 )
F_29 ( V_2 , V_2 -> V_24 -> V_54 ) ;
#endif
F_6 ( V_136 , V_2 -> V_8 + V_137 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_130 * V_131 = F_40 ( V_2 -> V_13 ) ;
unsigned long V_4 ;
int V_5 ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
F_6 ( 0 , V_2 -> V_8 + V_137 ) ;
F_6 ( 0xffffffff , V_2 -> V_8 + V_27 ) ;
V_5 = F_38 ( V_2 , V_131 ) ;
F_7 ( & V_2 -> V_7 , V_4 ) ;
return V_5 ;
}
static int F_41 ( struct V_130 * V_131 )
{
const struct V_138 * V_139 ;
struct V_1 * V_2 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
int V_89 , V_5 ;
V_2 = F_42 ( & V_131 -> V_13 , sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 )
return - V_145 ;
V_143 = F_43 ( V_131 , V_146 , 0 ) ;
V_2 -> V_8 = F_44 ( & V_131 -> V_13 , V_143 ) ;
if ( F_45 ( V_2 -> V_8 ) )
return F_46 ( V_2 -> V_8 ) ;
V_141 = F_47 ( & V_131 -> V_13 , NULL ) ;
if ( F_45 ( V_141 ) )
return F_46 ( V_141 ) ;
V_2 -> V_121 = F_48 ( V_141 ) ;
F_49 ( & V_131 -> V_13 , V_141 ) ;
V_5 = F_50 ( V_131 -> V_13 . V_134 ,
L_20 , & V_2 -> V_122 ) ;
if ( V_5 < 0 ) {
F_12 ( & V_131 -> V_13 ,
L_21 ) ;
V_2 -> V_122 = 100000 ;
}
V_139 = F_51 ( V_147 , V_131 -> V_13 . V_134 ) ;
if ( ! V_139 )
V_2 -> V_127 = F_34 ;
else
V_2 -> V_127 = V_139 -> V_148 ;
F_52 ( & V_2 -> V_7 ) ;
F_53 ( & V_2 -> V_14 ) ;
V_2 -> V_16 . V_149 = V_150 ;
V_2 -> V_16 . V_151 = 0 ;
V_2 -> V_16 . V_17 = 5 * V_152 ;
V_2 -> V_16 . V_153 = & V_154 ;
V_2 -> V_16 . V_13 . V_155 = & V_131 -> V_13 ;
V_2 -> V_16 . V_13 . V_134 = V_131 -> V_13 . V_134 ;
F_54 ( V_2 -> V_16 . V_156 , V_131 -> V_156 , sizeof( V_2 -> V_16 . V_156 ) ) ;
F_55 ( & V_2 -> V_16 , V_2 ) ;
V_2 -> V_13 = & V_131 -> V_13 ;
F_6 ( 0 , V_2 -> V_8 + V_137 ) ;
F_6 ( 0xffffffff , V_2 -> V_8 + V_27 ) ;
V_5 = F_38 ( V_2 , V_131 ) ;
if ( V_5 < 0 )
return V_5 ;
V_89 = F_56 ( V_131 -> V_13 . V_134 , 0 ) ;
V_5 = F_57 ( & V_131 -> V_13 , V_89 , F_24 ,
0 , F_58 ( & V_131 -> V_13 ) , V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_59 ( & V_2 -> V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
F_60 ( V_131 , V_2 ) ;
F_61 ( V_2 -> V_13 , L_22 ,
V_2 -> V_16 . V_157 , V_89 ) ;
return 0 ;
}
static int F_62 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_63 ( V_131 ) ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_7 , V_4 ) ;
F_6 ( 0 , V_2 -> V_8 + V_105 ) ;
F_6 ( 0 , V_2 -> V_8 + V_137 ) ;
F_7 ( & V_2 -> V_7 , V_4 ) ;
F_64 ( & V_2 -> V_16 ) ;
return 0 ;
}
