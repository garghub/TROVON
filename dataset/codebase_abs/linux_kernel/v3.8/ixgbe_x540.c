static enum V_1 F_1 ( struct V_2 * V_3 )
{
return V_4 ;
}
static T_1 F_2 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = & V_3 -> V_6 ;
F_3 ( V_3 ) ;
V_6 -> V_7 = V_8 ;
V_6 -> V_9 = V_10 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_13 = V_14 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_17 = F_4 ( V_3 ) ;
return 0 ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
T_2 V_18 , bool V_19 ,
bool V_20 )
{
return V_3 -> V_21 . V_22 . V_23 ( V_3 , V_18 , V_19 ,
V_20 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 )
{
T_1 V_24 ;
T_3 V_25 , V_26 ;
V_24 = V_3 -> V_6 . V_22 . V_27 ( V_3 ) ;
if ( V_24 != 0 )
goto V_28;
F_7 ( V_3 ) ;
V_29:
V_25 = V_30 ;
V_25 |= F_8 ( V_3 , V_31 ) ;
F_9 ( V_3 , V_31 , V_25 ) ;
F_10 ( V_3 ) ;
for ( V_26 = 0 ; V_26 < 10 ; V_26 ++ ) {
F_11 ( 1 ) ;
V_25 = F_8 ( V_3 , V_31 ) ;
if ( ! ( V_25 & V_32 ) )
break;
}
if ( V_25 & V_32 ) {
V_24 = V_33 ;
F_12 ( V_3 , L_1 ) ;
}
F_13 ( 100 ) ;
if ( V_3 -> V_6 . V_34 & V_35 ) {
V_3 -> V_6 . V_34 &= ~ V_35 ;
goto V_29;
}
F_9 ( V_3 , F_14 ( 0 ) , 384 << V_36 ) ;
V_3 -> V_6 . V_22 . V_37 ( V_3 , V_3 -> V_6 . V_38 ) ;
V_3 -> V_6 . V_11 = V_16 ;
V_3 -> V_6 . V_22 . V_39 ( V_3 ) ;
V_3 -> V_6 . V_22 . V_40 ( V_3 , V_3 -> V_6 . V_41 ) ;
if ( F_15 ( V_3 -> V_6 . V_41 ) ) {
V_3 -> V_6 . V_22 . V_42 ( V_3 , V_3 -> V_6 . V_11 - 1 ,
V_3 -> V_6 . V_41 , 0 , V_43 ) ;
V_3 -> V_6 . V_44 = V_3 -> V_6 . V_11 - 1 ;
V_3 -> V_6 . V_11 -- ;
}
V_3 -> V_6 . V_22 . V_45 ( V_3 , & V_3 -> V_6 . V_46 ,
& V_3 -> V_6 . V_47 ) ;
V_28:
return V_24 ;
}
static T_1 F_16 ( struct V_2 * V_3 )
{
T_1 V_48 = 0 ;
V_48 = F_17 ( V_3 ) ;
if ( V_48 != 0 )
goto V_49;
V_48 = F_18 ( V_3 ) ;
V_3 -> V_6 . V_50 = V_51 ;
V_49:
return V_48 ;
}
static T_3 F_19 ( struct V_2 * V_3 )
{
T_3 V_52 = V_53 ;
T_4 V_54 = 0 ;
V_3 -> V_21 . V_22 . V_55 ( V_3 ) ;
V_3 -> V_21 . V_22 . V_56 ( V_3 , V_57 , V_58 ,
& V_54 ) ;
if ( V_54 & V_59 )
V_52 |= V_60 ;
if ( V_54 & V_61 )
V_52 |= V_62 ;
if ( V_54 & V_63 )
V_52 |= V_64 ;
return V_52 ;
}
static T_1 F_20 ( struct V_2 * V_3 )
{
struct V_65 * V_66 = & V_3 -> V_66 ;
T_3 V_67 ;
T_4 V_68 ;
if ( V_66 -> type == V_69 ) {
V_66 -> V_70 = 10 ;
V_66 -> type = V_71 ;
V_67 = F_8 ( V_3 , V_72 ) ;
V_68 = ( T_4 ) ( ( V_67 & V_73 ) >>
V_74 ) ;
V_66 -> V_75 = 1 << ( V_68 +
V_76 ) ;
F_12 ( V_3 , L_2 ,
V_66 -> type , V_66 -> V_75 ) ;
}
return 0 ;
}
static T_1 F_21 ( struct V_2 * V_3 , T_4 V_77 , T_4 * V_78 )
{
T_1 V_24 = 0 ;
if ( V_3 -> V_6 . V_22 . V_79 ( V_3 , V_80 ) ==
0 )
V_24 = F_22 ( V_3 , V_77 , V_78 ) ;
else
V_24 = V_81 ;
V_3 -> V_6 . V_22 . V_82 ( V_3 , V_80 ) ;
return V_24 ;
}
static T_1 F_23 ( struct V_2 * V_3 ,
T_4 V_77 , T_4 V_83 , T_4 * V_78 )
{
T_1 V_24 = 0 ;
if ( V_3 -> V_6 . V_22 . V_79 ( V_3 , V_80 ) ==
0 )
V_24 = F_24 ( V_3 , V_77 ,
V_83 , V_78 ) ;
else
V_24 = V_81 ;
V_3 -> V_6 . V_22 . V_82 ( V_3 , V_80 ) ;
return V_24 ;
}
static T_1 F_25 ( struct V_2 * V_3 , T_4 V_77 , T_4 V_78 )
{
T_1 V_24 = 0 ;
if ( V_3 -> V_6 . V_22 . V_79 ( V_3 , V_80 ) == 0 )
V_24 = F_26 ( V_3 , V_77 , V_78 ) ;
else
V_24 = V_81 ;
V_3 -> V_6 . V_22 . V_82 ( V_3 , V_80 ) ;
return V_24 ;
}
static T_1 F_27 ( struct V_2 * V_3 ,
T_4 V_77 , T_4 V_83 , T_4 * V_78 )
{
T_1 V_24 = 0 ;
if ( V_3 -> V_6 . V_22 . V_79 ( V_3 , V_80 ) ==
0 )
V_24 = F_28 ( V_3 , V_77 ,
V_83 , V_78 ) ;
else
V_24 = V_81 ;
V_3 -> V_6 . V_22 . V_82 ( V_3 , V_80 ) ;
return V_24 ;
}
static T_4 F_29 ( struct V_2 * V_3 )
{
T_4 V_26 ;
T_4 V_84 ;
T_4 V_85 = 0 ;
T_4 V_86 = 0 ;
T_4 V_87 = 0 ;
T_4 V_88 = 0 ;
for ( V_26 = 0 ; V_26 < V_89 ; V_26 ++ ) {
if ( F_22 ( V_3 , V_26 , & V_88 ) != 0 ) {
F_12 ( V_3 , L_3 ) ;
break;
}
V_85 += V_88 ;
}
for ( V_26 = V_90 ; V_26 < V_91 ; V_26 ++ ) {
if ( V_26 == V_92 || V_26 == V_93 )
continue;
if ( F_22 ( V_3 , V_26 , & V_87 ) != 0 ) {
F_12 ( V_3 , L_3 ) ;
break;
}
if ( V_87 == 0xFFFF || V_87 == 0 ||
V_87 >= V_3 -> V_66 . V_75 )
continue;
if ( F_22 ( V_3 , V_87 , & V_86 ) != 0 ) {
F_12 ( V_3 , L_3 ) ;
break;
}
if ( V_86 == 0xFFFF || V_86 == 0 ||
( V_87 + V_86 ) >= V_3 -> V_66 . V_75 )
continue;
for ( V_84 = V_87 + 1 ; V_84 <= V_87 + V_86 ; V_84 ++ ) {
if ( F_22 ( V_3 , V_84 , & V_88 ) != 0 ) {
F_12 ( V_3 , L_3 ) ;
break;
}
V_85 += V_88 ;
}
}
V_85 = ( T_4 ) V_94 - V_85 ;
return V_85 ;
}
static T_1 F_30 ( struct V_2 * V_3 ,
T_4 * V_95 )
{
T_1 V_24 ;
T_4 V_85 ;
T_4 V_96 = 0 ;
V_24 = V_3 -> V_66 . V_22 . V_97 ( V_3 , 0 , & V_85 ) ;
if ( V_24 != 0 ) {
F_12 ( V_3 , L_3 ) ;
goto V_49;
}
if ( V_3 -> V_6 . V_22 . V_79 ( V_3 , V_80 ) == 0 ) {
V_85 = V_3 -> V_66 . V_22 . V_98 ( V_3 ) ;
F_22 ( V_3 , V_89 ,
& V_96 ) ;
if ( V_96 != V_85 )
V_24 = V_99 ;
if ( V_95 )
* V_95 = V_85 ;
} else {
V_24 = V_81 ;
}
V_3 -> V_6 . V_22 . V_82 ( V_3 , V_80 ) ;
V_49:
return V_24 ;
}
static T_1 F_31 ( struct V_2 * V_3 )
{
T_1 V_24 ;
T_4 V_85 ;
V_24 = V_3 -> V_66 . V_22 . V_97 ( V_3 , 0 , & V_85 ) ;
if ( V_24 != 0 )
F_12 ( V_3 , L_3 ) ;
if ( V_3 -> V_6 . V_22 . V_79 ( V_3 , V_80 ) == 0 ) {
V_85 = V_3 -> V_66 . V_22 . V_98 ( V_3 ) ;
V_24 = F_26 ( V_3 , V_89 ,
V_85 ) ;
if ( V_24 == 0 )
V_24 = F_32 ( V_3 ) ;
else
V_24 = V_81 ;
}
V_3 -> V_6 . V_22 . V_82 ( V_3 , V_80 ) ;
return V_24 ;
}
static T_1 F_32 ( struct V_2 * V_3 )
{
T_3 V_100 ;
T_1 V_24 = V_101 ;
V_24 = F_33 ( V_3 ) ;
if ( V_24 == V_101 ) {
F_12 ( V_3 , L_4 ) ;
goto V_49;
}
V_100 = F_8 ( V_3 , V_72 ) | V_102 ;
F_9 ( V_3 , V_72 , V_100 ) ;
V_24 = F_33 ( V_3 ) ;
if ( V_24 == 0 )
F_12 ( V_3 , L_5 ) ;
else
F_12 ( V_3 , L_4 ) ;
if ( V_3 -> V_103 == 0 ) {
V_100 = F_8 ( V_3 , V_72 ) ;
if ( V_100 & V_104 ) {
V_100 |= V_102 ;
F_9 ( V_3 , V_72 , V_100 ) ;
}
V_24 = F_33 ( V_3 ) ;
if ( V_24 == 0 )
F_12 ( V_3 , L_5 ) ;
else
F_12 ( V_3 , L_4 ) ;
}
V_49:
return V_24 ;
}
static T_1 F_33 ( struct V_2 * V_3 )
{
T_3 V_26 ;
T_3 V_105 ;
T_1 V_24 = V_101 ;
for ( V_26 = 0 ; V_26 < V_106 ; V_26 ++ ) {
V_105 = F_8 ( V_3 , V_72 ) ;
if ( V_105 & V_107 ) {
V_24 = 0 ;
break;
}
F_11 ( 5 ) ;
}
return V_24 ;
}
static T_1 F_34 ( struct V_2 * V_3 , T_4 V_108 )
{
T_3 V_109 ;
T_3 V_110 = V_108 ;
T_3 V_111 = V_108 << 5 ;
T_3 V_112 = 0 ;
T_3 V_113 = 200 ;
T_3 V_26 ;
if ( V_110 == V_80 )
V_112 = V_114 ;
for ( V_26 = 0 ; V_26 < V_113 ; V_26 ++ ) {
if ( F_35 ( V_3 ) )
return V_81 ;
V_109 = F_8 ( V_3 , V_115 ) ;
if ( ! ( V_109 & ( V_111 | V_110 | V_112 ) ) ) {
V_109 |= V_110 ;
F_9 ( V_3 , V_115 , V_109 ) ;
F_36 ( V_3 ) ;
break;
} else {
F_36 ( V_3 ) ;
F_37 ( 5000 , 10000 ) ;
}
}
if ( V_26 >= V_113 ) {
V_109 = F_8 ( V_3 , V_115 ) ;
if ( V_109 & ( V_111 | V_112 ) ) {
if ( F_35 ( V_3 ) )
return V_81 ;
V_109 |= V_110 ;
F_9 ( V_3 , V_115 , V_109 ) ;
F_36 ( V_3 ) ;
}
}
F_37 ( 5000 , 10000 ) ;
return 0 ;
}
static void F_38 ( struct V_2 * V_3 , T_4 V_108 )
{
T_3 V_109 ;
T_3 V_110 = V_108 ;
F_35 ( V_3 ) ;
V_109 = F_8 ( V_3 , V_115 ) ;
V_109 &= ~ V_110 ;
F_9 ( V_3 , V_115 , V_109 ) ;
F_36 ( V_3 ) ;
F_37 ( 5000 , 10000 ) ;
}
static T_1 F_35 ( struct V_2 * V_3 )
{
T_1 V_24 = V_101 ;
T_3 V_113 = 2000 ;
T_3 V_26 ;
T_3 V_116 ;
for ( V_26 = 0 ; V_26 < V_113 ; V_26 ++ ) {
V_116 = F_8 ( V_3 , V_117 ) ;
if ( ! ( V_116 & V_118 ) ) {
V_24 = 0 ;
break;
}
F_11 ( 50 ) ;
}
if ( V_24 ) {
for ( V_26 = 0 ; V_26 < V_113 ; V_26 ++ ) {
V_116 = F_8 ( V_3 , V_115 ) ;
if ( ! ( V_116 & V_119 ) )
break;
F_11 ( 50 ) ;
}
} else {
F_12 ( V_3 , L_6
L_7 ) ;
}
return V_24 ;
}
static void F_36 ( struct V_2 * V_3 )
{
T_3 V_116 ;
V_116 = F_8 ( V_3 , V_117 ) ;
V_116 &= ~ V_118 ;
F_9 ( V_3 , V_117 , V_116 ) ;
V_116 = F_8 ( V_3 , V_115 ) ;
V_116 &= ~ V_119 ;
F_9 ( V_3 , V_115 , V_116 ) ;
F_10 ( V_3 ) ;
}
static T_1 F_39 ( struct V_2 * V_3 , T_3 V_120 )
{
T_3 V_121 ;
T_3 V_122 ;
T_2 V_18 ;
bool V_123 ;
V_3 -> V_6 . V_22 . V_124 ( V_3 , & V_18 , & V_123 , false ) ;
if ( ! V_123 ) {
V_121 = F_8 ( V_3 , V_125 ) ;
V_121 |= V_126 | V_127 | V_128 ;
F_9 ( V_3 , V_125 , V_121 ) ;
}
V_122 = F_8 ( V_3 , V_129 ) ;
V_122 &= ~ F_40 ( V_120 ) ;
V_122 |= F_41 ( V_120 ) ;
F_9 ( V_3 , V_129 , V_122 ) ;
F_10 ( V_3 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_2 * V_3 , T_3 V_120 )
{
T_3 V_121 ;
T_3 V_122 ;
V_122 = F_8 ( V_3 , V_129 ) ;
V_122 &= ~ F_40 ( V_120 ) ;
V_122 |= V_130 << F_43 ( V_120 ) ;
V_122 &= ~ F_41 ( V_120 ) ;
F_9 ( V_3 , V_129 , V_122 ) ;
V_121 = F_8 ( V_3 , V_125 ) ;
V_121 &= ~ ( V_126 | V_127 | V_128 ) ;
F_9 ( V_3 , V_125 , V_121 ) ;
F_10 ( V_3 ) ;
return 0 ;
}
