static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 &= ~ V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 , V_12 ;
T_1 V_3 ;
struct V_13 * V_14 = V_10 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_11 = V_14 -> V_18 & V_19 ? 1 : 0 ;
V_12 = V_14 -> V_18 & V_20 ? 1 : 0 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( V_11 )
V_3 |= V_21 ;
else
V_3 &= ~ V_21 ;
if ( V_12 )
V_3 |= V_22 ;
else
V_3 &= ~ V_22 ;
if ( V_16 -> V_23 )
V_3 |= V_24 ;
else
V_3 &= ~ V_24 ;
if ( V_16 -> V_25 )
V_3 |= V_26 ;
else
V_3 &= ~ V_26 ;
#ifdef F_6
V_3 &= ~ V_27 ;
V_3 &= ~ V_28 ;
#else
V_3 |= V_27 ;
V_3 |= V_28 ;
#endif
if ( V_2 -> V_29 -> V_30 ) {
if ( V_16 -> V_31 )
V_3 |= V_32 ;
else
V_3 &= ~ V_32 ;
if ( V_16 -> V_33 )
V_3 |= V_34 ;
else
V_3 &= ~ V_34 ;
}
V_3 |= V_35 | V_36 ;
V_3 &= ~ ( V_37 | V_38 ) ;
V_3 &= ~ V_39 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
if ( V_2 -> V_29 -> V_40 )
F_3 ( V_2 -> V_41 [ V_14 -> V_42 ] ,
V_2 -> V_4 + V_43 ) ;
return 0 ;
}
static void F_7 ( struct V_13 * V_14 , bool V_44 )
{
T_1 V_3 ;
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( ! V_44 ) {
V_3 |= V_45 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
} else {
V_3 &= ~ V_45 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_46 = V_47 ;
F_1 ( V_2 ) ;
}
}
static void F_8 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
T_1 V_50 , div , V_51 , V_52 , V_3 = 0 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_50 = F_9 ( V_2 -> V_53 ) ;
if ( V_49 -> V_54 < V_50 / 2 )
div = F_10 ( V_50 , V_49 -> V_54 ) ;
else
div = 1 ;
V_51 = ( div + 1 ) / 2 ;
V_52 = V_51 * 2 ;
if ( V_2 -> V_29 -> V_30 ) {
V_3 |= ( ( ( V_51 - 1 ) & 0xffff )
<< V_55 ) ;
V_3 |= ( ( ( V_51 - 1 ) & 0xffff )
<< V_56 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_57 ) ;
V_3 |= ( ( ( V_52 - 1 ) & 0xffff )
<< V_58 ) ;
V_3 |= ( ( ( V_52 - 1 ) & 0xffff )
<< V_59 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_60 ) ;
} else {
V_3 |= ( ( ( V_51 - 1 ) & 0xff )
<< V_55 ) ;
V_3 |= ( ( ( V_51 - 1 ) & 0xff ) << V_61 ) ;
V_3 |= ( ( ( V_52 - 1 ) & 0xff ) << V_62 ) ;
V_3 |= ( ( ( V_52 - 1 ) & 0xff ) << V_63 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_60 ) ;
}
V_3 = F_2 ( V_2 -> V_4 + V_64 ) ;
V_3 &= ~ V_65 ;
V_3 |= ( ( ( V_52 - 1 ) & 0xff ) << V_66 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_64 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
T_1 V_67 , V_68 , V_3 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_67 = F_12 ( T_1 , V_2 -> V_69 , V_70 ) ;
V_68 = V_2 -> V_69 / V_67 ;
V_3 = F_2 ( V_2 -> V_4 + V_64 ) ;
V_3 &= ~ ( V_71 | V_72 ) ;
V_3 |= ( V_67 - 1 ) << V_73 ;
V_3 |= ( V_68 - 1 ) << V_74 ;
F_3 ( V_3 , V_2 -> V_4 + V_64 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
T_1 V_75 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_75 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( V_2 -> V_46 == V_47 )
V_75 |= V_76 ;
else
V_75 |= V_77 ;
F_3 ( V_75 , V_2 -> V_4 + V_5 ) ;
}
static int F_14 ( T_1 V_69 )
{
T_1 V_78 ;
if ( V_69 > V_70 )
V_78 = V_69 % V_70 ;
else
V_78 = 0 ;
return V_78 ;
}
static void F_15 ( struct V_7 * V_8 )
{
int V_78 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
if ( V_2 -> V_79 && V_2 -> V_80 ) {
if ( V_2 -> V_79 > V_2 -> V_80 ) {
V_78 = F_14 ( V_2 -> V_80 ) ;
V_2 -> V_69 = V_2 -> V_80 - V_78 ;
V_2 -> V_80 = V_78 ;
V_2 -> V_79 -= V_2 -> V_69 ;
} else {
V_78 = F_14 ( V_2 -> V_79 ) ;
V_2 -> V_69 = V_2 -> V_79 - V_78 ;
V_2 -> V_79 = V_78 ;
V_2 -> V_80 -= V_2 -> V_69 ;
}
} else if ( V_2 -> V_79 ) {
V_78 = F_14 ( V_2 -> V_79 ) ;
V_2 -> V_69 = V_2 -> V_79 - V_78 ;
V_2 -> V_79 = V_78 ;
} else if ( V_2 -> V_80 ) {
V_78 = F_14 ( V_2 -> V_80 ) ;
V_2 -> V_69 = V_2 -> V_80 - V_78 ;
V_2 -> V_80 = V_78 ;
}
}
static void F_16 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
if ( V_2 -> V_81 )
F_3 ( V_49 -> V_82 , V_2 -> V_4 + V_83 ) ;
if ( V_2 -> V_84 )
F_3 ( V_49 -> V_85 , V_2 -> V_4 + V_86 ) ;
}
static int F_17 ( struct V_7 * V_8 ,
struct V_13 * V_14 ,
struct V_48 * V_49 )
{
int V_87 , V_88 ;
T_1 V_3 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_2 -> V_89 = V_49 ;
V_2 -> V_69 = F_18 ( V_90 , V_49 -> V_91 ) ;
F_8 ( V_8 , V_49 ) ;
F_11 ( V_8 ) ;
V_87 = V_49 -> V_91 / 4 ;
F_19 ( V_2 -> V_4 + V_92 , V_49 -> V_93 , V_87 ) ;
V_88 = V_49 -> V_91 % 4 ;
if ( V_88 > 0 ) {
V_3 = 0 ;
memcpy ( & V_3 , V_49 -> V_93 + ( V_87 * 4 ) , V_88 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_92 ) ;
}
F_13 ( V_8 ) ;
return 1 ;
}
static int F_20 ( struct V_7 * V_8 ,
struct V_13 * V_14 ,
struct V_48 * V_49 )
{
int V_75 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_2 -> V_81 = NULL ;
V_2 -> V_84 = NULL ;
V_2 -> V_79 = 0 ;
V_2 -> V_80 = 0 ;
V_2 -> V_89 = V_49 ;
F_8 ( V_8 , V_49 ) ;
V_75 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( V_49 -> V_93 )
V_75 |= V_37 ;
if ( V_49 -> V_94 )
V_75 |= V_38 ;
F_3 ( V_75 , V_2 -> V_4 + V_5 ) ;
if ( V_49 -> V_93 )
V_2 -> V_81 = V_49 -> V_95 . V_96 ;
if ( V_49 -> V_94 )
V_2 -> V_84 = V_49 -> V_97 . V_96 ;
if ( V_2 -> V_81 ) {
V_49 -> V_82 = F_21 ( V_2 -> V_81 ) ;
V_2 -> V_79 = F_22 ( V_2 -> V_81 ) ;
}
if ( V_2 -> V_84 ) {
V_49 -> V_85 = F_21 ( V_2 -> V_84 ) ;
V_2 -> V_80 = F_22 ( V_2 -> V_84 ) ;
}
F_15 ( V_8 ) ;
F_11 ( V_8 ) ;
F_16 ( V_8 , V_49 ) ;
F_13 ( V_8 ) ;
return 1 ;
}
static int F_23 ( struct V_7 * V_8 ,
struct V_13 * V_14 ,
struct V_48 * V_49 )
{
if ( V_8 -> V_98 ( V_8 , V_14 , V_49 ) )
return F_20 ( V_8 , V_14 , V_49 ) ;
else
return F_17 ( V_8 , V_14 , V_49 ) ;
}
static bool F_24 ( struct V_7 * V_8 ,
struct V_13 * V_14 ,
struct V_48 * V_49 )
{
return ( V_49 -> V_91 > V_90 &&
( unsigned long ) V_49 -> V_93 % 4 == 0 &&
( unsigned long ) V_49 -> V_94 % 4 == 0 ) ;
}
static int F_25 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
if ( ! V_14 -> V_17 )
V_14 -> V_17 = ( void * ) & V_99 ;
if ( V_2 -> V_29 -> V_40 && F_26 ( V_14 -> V_100 ) )
F_27 ( V_14 -> V_100 , ! ( V_14 -> V_18 & V_101 ) ) ;
return 0 ;
}
static T_3 F_28 ( int V_102 , void * V_103 )
{
T_1 V_75 , V_3 , V_87 , V_88 ;
struct V_7 * V_8 = V_103 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
struct V_48 * V_104 = V_2 -> V_89 ;
V_3 = F_2 ( V_2 -> V_4 + V_105 ) ;
if ( V_3 & V_106 )
V_2 -> V_46 = V_107 ;
else
V_2 -> V_46 = V_47 ;
if ( ! V_8 -> V_98 ( V_8 , V_8 -> V_108 -> V_14 , V_104 ) ) {
if ( V_104 -> V_94 ) {
V_87 = V_2 -> V_69 / 4 ;
F_29 ( V_2 -> V_4 + V_109 ,
V_104 -> V_94 , V_87 ) ;
V_88 = V_2 -> V_69 % 4 ;
if ( V_88 > 0 ) {
V_3 = F_2 ( V_2 -> V_4 + V_109 ) ;
memcpy ( V_104 -> V_94 + ( V_87 * 4 ) ,
& V_3 , V_88 ) ;
}
}
V_104 -> V_91 -= V_2 -> V_69 ;
if ( ! V_104 -> V_91 ) {
F_30 ( V_8 ) ;
return V_110 ;
}
if ( V_104 -> V_93 )
V_104 -> V_93 += V_2 -> V_69 ;
if ( V_104 -> V_94 )
V_104 -> V_94 += V_2 -> V_69 ;
V_2 -> V_69 = F_18 ( V_90 , V_104 -> V_91 ) ;
F_11 ( V_8 ) ;
V_87 = V_104 -> V_91 / 4 ;
F_19 ( V_2 -> V_4 + V_92 , V_104 -> V_93 , V_87 ) ;
V_88 = V_104 -> V_91 % 4 ;
if ( V_88 > 0 ) {
V_3 = 0 ;
memcpy ( & V_3 , V_104 -> V_93 + ( V_87 * 4 ) , V_88 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_92 ) ;
}
F_13 ( V_8 ) ;
return V_110 ;
}
if ( V_2 -> V_81 )
V_104 -> V_82 += V_2 -> V_69 ;
if ( V_2 -> V_84 )
V_104 -> V_85 += V_2 -> V_69 ;
if ( V_2 -> V_81 && ( V_2 -> V_79 == 0 ) ) {
V_2 -> V_81 = F_31 ( V_2 -> V_81 ) ;
if ( V_2 -> V_81 ) {
V_104 -> V_82 = F_21 ( V_2 -> V_81 ) ;
V_2 -> V_79 = F_22 ( V_2 -> V_81 ) ;
}
}
if ( V_2 -> V_84 && ( V_2 -> V_80 == 0 ) ) {
V_2 -> V_84 = F_31 ( V_2 -> V_84 ) ;
if ( V_2 -> V_84 ) {
V_104 -> V_85 = F_21 ( V_2 -> V_84 ) ;
V_2 -> V_80 = F_22 ( V_2 -> V_84 ) ;
}
}
if ( ! V_2 -> V_81 && ! V_2 -> V_84 ) {
V_75 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_75 &= ~ V_37 ;
V_75 &= ~ V_38 ;
F_3 ( V_75 , V_2 -> V_4 + V_5 ) ;
F_30 ( V_8 ) ;
return V_110 ;
}
F_15 ( V_8 ) ;
F_11 ( V_8 ) ;
F_16 ( V_8 , V_104 ) ;
F_13 ( V_8 ) ;
return V_110 ;
}
static int F_32 ( struct V_111 * V_112 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
const struct V_113 * V_114 ;
struct V_115 * V_116 ;
int V_117 , V_102 , V_118 ;
V_8 = F_33 ( & V_112 -> V_119 , sizeof( * V_2 ) ) ;
if ( ! V_8 ) {
F_34 ( & V_112 -> V_119 , L_1 ) ;
return - V_120 ;
}
V_8 -> V_121 = true ;
V_8 -> V_119 . V_122 = V_112 -> V_119 . V_122 ;
V_8 -> V_123 = V_20 | V_19 ;
V_8 -> V_124 = F_7 ;
V_8 -> V_125 = F_4 ;
V_8 -> V_126 = F_23 ;
V_8 -> V_98 = F_24 ;
V_8 -> V_127 = F_25 ;
V_114 = F_35 ( V_128 , V_112 -> V_119 . V_122 ) ;
if ( ! V_114 ) {
F_34 ( & V_112 -> V_119 , L_2 ) ;
V_118 = - V_129 ;
goto V_130;
}
V_2 = F_5 ( V_8 ) ;
V_2 -> V_29 = V_114 -> V_131 ;
if ( V_2 -> V_29 -> V_132 )
V_8 -> V_133 = V_134 ;
if ( V_2 -> V_29 -> V_40 ) {
V_2 -> V_135 = F_36 (
V_112 -> V_119 . V_122 ,
L_3 ) ;
if ( V_2 -> V_135 < 0 ) {
F_34 ( & V_112 -> V_119 ,
L_4 ) ;
V_118 = - V_129 ;
goto V_130;
}
V_2 -> V_41 = F_37 ( & V_112 -> V_119 , V_2 -> V_135 ,
sizeof( T_1 ) , V_136 ) ;
if ( ! V_2 -> V_41 ) {
V_118 = - V_120 ;
goto V_130;
}
for ( V_117 = 0 ; V_117 < V_2 -> V_135 ; V_117 ++ ) {
F_38 ( V_112 -> V_119 . V_122 ,
L_3 ,
V_117 , & V_2 -> V_41 [ V_117 ] ) ;
if ( V_2 -> V_41 [ V_117 ] > V_137 ) {
F_34 ( & V_112 -> V_119 , L_5 ,
V_117 , V_2 -> V_41 [ V_117 ] ) ;
V_118 = - V_129 ;
goto V_130;
}
}
}
F_39 ( V_112 , V_8 ) ;
V_116 = F_40 ( V_112 , V_138 , 0 ) ;
if ( ! V_116 ) {
V_118 = - V_139 ;
F_34 ( & V_112 -> V_119 , L_6 ) ;
goto V_130;
}
V_2 -> V_4 = F_41 ( & V_112 -> V_119 , V_116 ) ;
if ( F_42 ( V_2 -> V_4 ) ) {
V_118 = F_43 ( V_2 -> V_4 ) ;
goto V_130;
}
V_102 = F_44 ( V_112 , 0 ) ;
if ( V_102 < 0 ) {
F_34 ( & V_112 -> V_119 , L_7 , V_102 ) ;
V_118 = V_102 ;
goto V_130;
}
if ( ! V_112 -> V_119 . V_140 )
V_112 -> V_119 . V_140 = & V_112 -> V_119 . V_141 ;
V_118 = F_45 ( & V_112 -> V_119 , V_102 , F_28 ,
V_142 , F_46 ( & V_112 -> V_119 ) , V_8 ) ;
if ( V_118 ) {
F_34 ( & V_112 -> V_119 , L_8 , V_118 ) ;
goto V_130;
}
V_2 -> V_143 = F_47 ( & V_112 -> V_119 , L_9 ) ;
if ( F_42 ( V_2 -> V_143 ) ) {
V_118 = F_43 ( V_2 -> V_143 ) ;
F_34 ( & V_112 -> V_119 , L_10 , V_118 ) ;
goto V_130;
}
V_2 -> V_144 = F_47 ( & V_112 -> V_119 , L_11 ) ;
if ( F_42 ( V_2 -> V_144 ) ) {
V_118 = F_43 ( V_2 -> V_144 ) ;
F_34 ( & V_112 -> V_119 , L_12 , V_118 ) ;
goto V_130;
}
V_2 -> V_53 = F_47 ( & V_112 -> V_119 , L_13 ) ;
if ( F_42 ( V_2 -> V_53 ) ) {
V_118 = F_43 ( V_2 -> V_53 ) ;
F_34 ( & V_112 -> V_119 , L_14 , V_118 ) ;
goto V_130;
}
V_118 = F_48 ( V_2 -> V_53 ) ;
if ( V_118 < 0 ) {
F_34 ( & V_112 -> V_119 , L_15 , V_118 ) ;
goto V_130;
}
V_118 = F_49 ( V_2 -> V_144 , V_2 -> V_143 ) ;
if ( V_118 < 0 ) {
F_34 ( & V_112 -> V_119 , L_16 , V_118 ) ;
F_50 ( V_2 -> V_53 ) ;
goto V_130;
}
F_50 ( V_2 -> V_53 ) ;
F_51 ( & V_112 -> V_119 ) ;
V_118 = F_52 ( & V_112 -> V_119 , V_8 ) ;
if ( V_118 ) {
F_34 ( & V_112 -> V_119 , L_17 , V_118 ) ;
goto V_145;
}
if ( V_2 -> V_29 -> V_40 ) {
if ( V_2 -> V_135 != V_8 -> V_146 ) {
F_34 ( & V_112 -> V_119 ,
L_18 ,
V_2 -> V_135 , V_8 -> V_146 ) ;
V_118 = - V_129 ;
goto V_145;
}
if ( ! V_8 -> V_147 && V_8 -> V_146 > 1 ) {
F_34 ( & V_112 -> V_119 ,
L_19 ) ;
V_118 = - V_129 ;
goto V_145;
}
if ( V_8 -> V_147 ) {
for ( V_117 = 0 ; V_117 < V_8 -> V_146 ; V_117 ++ ) {
V_118 = F_53 ( & V_112 -> V_119 ,
V_8 -> V_147 [ V_117 ] ,
F_46 ( & V_112 -> V_119 ) ) ;
if ( V_118 ) {
F_34 ( & V_112 -> V_119 ,
L_20 , V_117 ) ;
goto V_145;
}
}
}
}
return 0 ;
V_145:
F_54 ( & V_112 -> V_119 ) ;
V_130:
F_55 ( V_8 ) ;
return V_118 ;
}
static int F_56 ( struct V_111 * V_112 )
{
struct V_7 * V_8 = F_57 ( V_112 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
F_54 ( & V_112 -> V_119 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_148 * V_119 )
{
int V_118 ;
struct V_7 * V_8 = F_59 ( V_119 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_118 = F_60 ( V_8 ) ;
if ( V_118 )
return V_118 ;
if ( ! F_61 ( V_119 ) )
F_50 ( V_2 -> V_53 ) ;
return V_118 ;
}
static int F_62 ( struct V_148 * V_119 )
{
int V_118 ;
struct V_7 * V_8 = F_59 ( V_119 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
if ( ! F_61 ( V_119 ) ) {
V_118 = F_48 ( V_2 -> V_53 ) ;
if ( V_118 < 0 ) {
F_34 ( V_119 , L_15 , V_118 ) ;
return V_118 ;
}
}
V_118 = F_63 ( V_8 ) ;
if ( V_118 < 0 )
F_50 ( V_2 -> V_53 ) ;
return V_118 ;
}
static int F_64 ( struct V_148 * V_119 )
{
struct V_7 * V_8 = F_59 ( V_119 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
F_50 ( V_2 -> V_53 ) ;
return 0 ;
}
static int F_65 ( struct V_148 * V_119 )
{
struct V_7 * V_8 = F_59 ( V_119 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_118 ;
V_118 = F_48 ( V_2 -> V_53 ) ;
if ( V_118 < 0 ) {
F_34 ( V_119 , L_15 , V_118 ) ;
return V_118 ;
}
return 0 ;
}
