static T_1 *
F_1 ( void )
{
T_1 * V_1 = NULL ;
V_1 = F_2 ( struct V_2 ) ;
V_1 -> V_3 =
F_3 ( V_4 ,
L_1 ) ;
V_1 -> V_5 =
F_3 ( V_4 ,
L_2 ) ;
V_1 -> V_6 = 0 ;
V_1 -> V_7 = 0 ;
return V_1 ;
}
static T_1 *
F_4 ( T_2 * V_8 )
{
T_1 * V_1 = NULL ;
V_1 = ( T_1 * ) F_5 ( V_8 , V_9 ) ;
if ( ! V_1 ) {
V_1 = F_1 () ;
F_6 ( V_8 , V_9 , V_1 ) ;
}
return V_1 ;
}
static T_3 *
F_7 ( T_1 * V_1 , T_4 * V_10 )
{
T_3 * V_11 = NULL ;
V_11 = F_2 ( struct V_12 ) ;
V_11 -> V_13 =
F_3 ( V_4 ,
L_3 ) ;
F_8 ( V_1 -> V_5 , V_10 -> V_14 -> V_15 ,
( void * ) V_11 ) ;
return V_11 ;
}
static T_3 *
F_9 ( T_1 * V_1 , T_4 * V_10 )
{
T_3 * V_11 = NULL ;
V_11 = ( T_3 * ) F_10 ( V_1 -> V_5 , V_10 -> V_14 -> V_15 ) ;
return V_11 ;
}
static T_5 *
F_11 ( T_6 V_16 , T_2 * V_8 )
{
T_5 * V_17 = NULL ;
T_1 * V_1 = NULL ;
V_1 = F_4 ( V_8 ) ;
V_17 = ( T_5 * ) F_10 ( V_1 -> V_3 , V_16 ) ;
if ( ! V_17 ) {
V_17 = F_2 ( struct V_18 ) ;
V_17 -> V_19 = - 1 ;
V_17 -> V_16 = V_16 ;
V_17 -> V_20 = ( V_16 << ( 32 - 13 ) ) | 0x1 ;
F_8 ( V_1 -> V_3 , V_16 , ( void * ) V_17 ) ;
}
return V_17 ;
}
static void
F_12 ( T_7 * V_21 , enum V_22 V_23 ,
T_4 * V_10 , T_8 * V_24 )
{
T_9 V_25 = NULL ;
switch ( V_23 ) {
case V_26 :
V_25 = V_27 ;
break;
case V_28 :
V_25 = V_29 ;
break;
case V_30 :
V_25 = V_31 ;
break;
default:
break;
}
if ( V_25 )
F_13 ( V_25 , V_21 , V_10 , V_24 ) ;
else
F_13 ( V_32 , V_21 , V_10 , V_24 ) ;
}
T_10
F_14 ( T_7 * V_21 , T_10 V_33 , T_4 * V_10 ,
T_6 V_20 , enum V_22 V_23 )
{
T_11 * V_34 = NULL ;
T_7 * V_35 = NULL , * V_36 = NULL , * V_37 = NULL ;
T_12 V_38 = 0 ;
T_10 V_39 ;
V_39 = F_15 ( V_21 , V_33 ) ;
V_34 = F_16 ( & V_40 , V_10 , V_20 , NULL ) ;
if ( V_34 )
V_34 = V_34 -> V_41 ;
if ( ! V_34 ) {
if ( ( V_23 == V_26 && V_39 < 4 ) ||
( V_23 == V_30 && V_39 < 3 ) ||
( V_23 == V_28 && V_39 < 5 ) ) {
return - 1 ;
}
V_35 = V_21 ;
} else {
V_36 = F_17 ( V_34 -> V_42 , V_34 -> V_43 , V_34 -> V_43 ) ;
V_35 = F_18 () ;
F_19 ( V_35 , V_36 ) ;
V_37 = F_20 ( V_21 , V_33 ) ;
F_19 ( V_35 , V_37 ) ;
F_21 ( V_35 ) ;
V_33 = V_34 -> V_33 ;
}
switch ( V_23 ) {
case V_26 :
V_38 = F_22 ( V_35 , V_33 + 2 ) + 6 ;
break;
case V_28 :
V_38 = F_22 ( V_35 , V_33 + 4 ) ;
if ( V_38 )
V_38 += 6 ;
break;
case V_30 :
V_38 = ( F_22 ( V_35 , V_33 + 1 ) & 0xFFF ) + 3 ;
break;
default:
break;
}
if ( V_36 )
F_23 ( V_36 ) ;
return V_38 ;
}
static void
F_24 ( T_7 * V_21 , T_10 V_33 , T_4 * V_10 ,
T_8 * V_24 , T_6 V_20 ,
T_10 V_44 , T_10 V_45 ,
T_13 V_46 , enum V_22 V_23 )
{
T_11 * V_47 = NULL ;
T_7 * V_48 = NULL ;
T_13 V_49 ;
V_49 = V_10 -> V_50 ;
V_10 -> V_50 = TRUE ;
V_47 = F_25 ( & V_40 ,
V_21 , V_33 , V_10 , V_20 , NULL ,
V_44 ,
V_45 ,
! V_46 ) ;
V_48 = F_26 ( V_21 , V_33 , V_10 ,
L_4 ,
V_47 , & V_51 ,
NULL , V_24 ) ;
if ( V_48 ) {
F_27 ( V_24 , V_21 , 0 , 0 , L_5 ) ;
F_12 ( V_48 , V_23 , V_10 , V_24 ) ;
}
V_10 -> V_50 = V_49 ;
return;
}
static void
F_28 ( T_7 * V_21 , T_12 V_33 , T_10 V_39 , T_4 * V_10 ,
T_8 * V_24 , T_8 * V_52 , T_6 V_53 ,
T_5 * V_54 )
{
T_7 * V_55 ;
T_14 V_56 = 0 ;
T_15 * V_57 ;
T_10 V_58 = 0 ;
T_15 * V_59 ;
T_8 * V_60 ;
T_16 * V_61 = NULL ;
T_17 * V_62 = NULL ;
T_6 V_63 = 0 , V_64 = 0 ;
T_13 V_65 = FALSE ;
T_6 V_20 = 0 ;
if ( V_53 && V_54 -> V_23 == V_66
&& V_39 > 3 ) {
if ( F_29 ( V_21 , V_33 ) == 0x000001 ) {
V_54 -> V_23 = V_28 ;
} else {
V_54 -> V_23 = V_30 ;
}
}
if ( V_54 -> V_23 == V_66 )
return;
if ( V_53 && V_54 -> V_23 != V_28 ) {
V_56 = F_30 ( V_21 , V_33 ) ;
V_57 = F_27 ( V_52 , V_21 , V_33 , 1 ,
L_6 , F_30 ( V_21 , V_33 ) ) ;
V_33 ++ ;
V_39 -- ;
if ( V_56 > V_39 ) {
F_31 ( V_10 , V_57 , V_67 ,
V_68 ,
L_7 ,
V_39 ) ;
}
}
if ( ! V_10 -> V_14 -> V_69 . V_70 ) {
V_63 = V_54 -> V_63 ;
V_64 = V_54 -> V_64 ;
V_65 = V_54 -> V_65 ;
V_20 = V_54 -> V_20 ;
V_61 = ( T_16 * ) F_32 ( V_10 -> V_14 , V_9 , 0 ) ;
if ( ! V_61 ) {
V_61 = F_2 ( T_16 ) ;
V_61 -> V_71 = F_3 ( V_4 , L_2 ) ;
F_33 ( V_10 -> V_14 , V_9 , 0 , V_61 ) ;
} else {
V_62 = ( T_17 * ) F_10 ( V_61 -> V_71 , V_33 ) ;
}
if ( ! V_62 ) {
V_62 = F_2 ( T_17 ) ;
V_62 -> V_63 = V_63 ;
V_62 -> V_64 = V_64 ;
V_62 -> V_65 = V_65 ;
V_62 -> V_20 = V_20 ;
F_8 ( V_61 -> V_71 , V_33 , ( void * ) V_62 ) ;
}
} else {
V_61 = ( T_16 * ) F_32 ( V_10 -> V_14 , V_9 , 0 ) ;
if ( ! V_61 ) {
return;
}
V_62 = ( T_17 * ) F_10 ( V_61 -> V_71 , V_33 ) ;
if ( ! V_62 ) {
return;
}
V_63 = V_62 -> V_63 ;
V_64 = V_62 -> V_64 ;
V_65 = V_62 -> V_65 ;
V_20 = V_62 -> V_20 ;
}
if ( V_64 == ( T_10 ) - 1 ) {
V_64 = F_14 ( V_21 , V_33 , V_10 , V_20 , V_54 -> V_23 ) ;
if ( V_64 == ( T_10 ) - 1 ) {
return;
}
}
if ( V_53 ) {
if ( V_56 > V_39 ) {
return;
}
if ( V_65 ) {
F_24 ( V_21 , V_33 , V_10 , V_24 , V_20 , V_63 ,
V_56 , TRUE , V_54 -> V_23 ) ;
V_20 ++ ;
}
V_33 += V_56 ;
V_39 -= V_56 ;
V_65 = FALSE ;
V_63 = 0 ;
V_64 = 0 ;
if ( ! V_39 ) {
goto V_72;
}
while ( V_39 > 0 ) {
V_58 = 0 ;
while ( ( F_30 ( V_21 , V_33 + V_58 ) == 0xFF ) ) {
V_58 ++ ;
if ( V_58 >= V_39 ) {
V_39 = 0 ;
break;
}
}
if ( V_58 ) {
V_59 = F_27 ( V_24 , V_21 , V_33 , V_58 , L_8 ) ;
V_60 = F_34 ( V_59 , V_73 ) ;
F_35 ( V_60 , V_74 , V_21 , V_33 , V_58 , V_75 ) ;
V_33 += V_58 ;
if ( V_58 >= V_39 ) {
V_39 = 0 ;
goto V_72;
}
V_39 -= V_58 ;
}
V_64 = F_14 ( V_21 , V_33 , V_10 , V_20 , V_54 -> V_23 ) ;
if ( V_64 == ( T_10 ) - 1 || ! V_64 ) {
F_24 ( V_21 , V_33 , V_10 , V_24 , V_20 , 0 , V_39 , FALSE , V_54 -> V_23 ) ;
V_65 = TRUE ;
V_33 += V_39 ;
V_63 += V_39 ;
goto V_72;
}
if ( V_64 &&
V_64 <= V_39 ) {
V_55 = F_36 ( V_21 , V_33 , V_64 , V_64 ) ;
F_12 ( V_55 , V_54 -> V_23 , V_10 , V_24 ) ;
V_39 -= V_64 ;
V_33 += V_64 ;
V_64 = 0 ;
} else {
break;
}
}
if ( V_39 == 0 ) {
V_54 -> V_63 = 0 ;
V_54 -> V_64 = 0 ;
goto V_72;
}
}
if ( ( V_64 && V_63 + V_39 >= V_64 ) || ( ! V_64 && V_53 ) ) {
F_24 ( V_21 , V_33 , V_10 , V_24 , V_20 , V_63 , V_39 , TRUE , V_54 -> V_23 ) ;
V_20 ++ ;
V_65 = FALSE ;
V_63 = 0 ;
V_64 = 0 ;
} else {
F_24 ( V_21 , V_33 , V_10 , V_24 , V_20 , V_63 , V_39 , FALSE , V_54 -> V_23 ) ;
V_65 = TRUE ;
V_63 += V_39 ;
}
V_72:
V_54 -> V_65 = V_65 ;
V_54 -> V_63 = V_63 ;
V_54 -> V_64 = V_64 ;
V_54 -> V_20 = V_20 ;
return;
}
static T_6
F_37 ( T_18 V_76 , T_18 V_77 )
{
int V_78 = 0 ;
V_77 += 1 ;
V_78 = V_76 - V_77 ;
if ( V_78 < 0 )
V_78 += 16 ;
return V_78 ;
}
static T_6
F_38 ( T_7 * V_21 , T_8 * V_24 , T_4 * V_10 ,
T_6 V_16 , T_18 V_79 , T_2 * V_8 )
{
T_18 V_19 = - 1 ;
T_5 * V_17 = NULL ;
T_19 * V_80 = NULL ;
T_1 * V_1 = NULL ;
T_3 * V_11 = NULL ;
T_15 * V_81 ;
T_6 V_82 = 0 ;
T_6 V_83 = 0 ;
V_1 = F_4 ( V_8 ) ;
if ( ! V_10 -> V_14 -> V_69 . V_70 ) {
V_17 = F_11 ( V_16 , V_8 ) ;
V_19 = V_17 -> V_19 ;
V_17 -> V_19 = V_79 ;
if ( V_16 == 0x1fff )
return 0 ;
if ( V_19 == V_79 )
return 0 ;
if ( V_19 == - 1 )
return 0 ;
if ( V_79 != ( ( V_19 + 1 ) & V_84 ) ) {
V_82 = 1 ;
V_83 = F_37 ( V_79 , V_19 ) ;
V_1 -> V_6 += V_83 ;
V_1 -> V_7 ++ ;
}
}
if ( V_82 && ! V_10 -> V_14 -> V_69 . V_70 ) {
V_11 = F_9 ( V_1 , V_10 ) ;
if ( ! V_11 )
V_11 = F_7 ( V_1 , V_10 ) ;
V_80 = F_2 ( struct V_85 ) ;
V_80 -> V_19 = V_19 ;
V_80 -> V_16 = V_16 ;
V_80 -> V_83 = V_83 ;
F_8 ( V_11 -> V_13 , F_39 ( V_16 , V_79 ) ,
( void * ) V_80 ) ;
}
if ( V_10 -> V_14 -> V_69 . V_70 ) {
V_11 = F_9 ( V_1 , V_10 ) ;
if ( ! V_11 )
return 0 ;
else {
V_80 = (struct V_85 * ) F_10 ( V_11 -> V_13 ,
F_39 ( V_16 , V_79 ) ) ;
if ( V_80 ) {
if ( V_80 -> V_83 > 0 ) {
V_82 = 1 ;
V_19 = V_80 -> V_19 ;
V_83 = V_80 -> V_83 ;
}
}
}
}
if ( V_82 ) {
V_81 =
F_40 (
V_24 , V_86 , V_21 , 0 , 0 ,
L_9
L_10 ,
V_83 , V_19 ,
V_1 -> V_6 ,
V_1 -> V_7
) ;
F_41 ( V_81 ) ;
F_31 ( V_10 , V_81 , V_67 ,
V_68 , L_11 ) ;
V_81 = F_42 ( V_24 , V_87 ,
V_21 , 0 , 0 , V_83 ) ;
F_41 ( V_81 ) ;
V_81 = F_42 ( V_24 , V_88 ,
V_21 , 0 , 0 , 1 ) ;
F_41 ( V_81 ) ;
}
return V_83 ;
}
static void
F_43 ( T_7 * V_21 , volatile T_12 V_33 , T_4 * V_10 ,
T_8 * V_24 , T_2 * V_8 )
{
T_6 V_89 ;
T_10 V_90 ;
T_12 V_91 = V_33 ;
volatile T_12 V_92 ;
T_5 * V_54 ;
T_6 V_83 ;
T_6 V_16 ;
T_6 V_93 ;
T_6 V_53 ;
T_6 V_94 ;
T_15 * V_95 = NULL ;
T_15 * V_96 = NULL ;
T_15 * V_97 = NULL ;
T_8 * V_98 = NULL ;
T_8 * V_99 = NULL ;
T_8 * V_100 = NULL ;
T_8 * V_101 = NULL ;
T_15 * V_102 = NULL ;
V_95 = F_35 ( V_24 , V_9 , V_21 , V_33 , V_103 , V_75 ) ;
V_98 = F_34 ( V_95 , V_104 ) ;
V_89 = F_44 ( V_21 , V_33 ) ;
V_16 = ( V_89 & V_105 ) >> V_106 ;
V_93 = ( V_89 & V_84 ) >> V_107 ;
V_94 = ( V_89 & V_108 ) ;
V_53 = ( V_89 & 0x00400000 ) ;
F_45 ( V_95 , L_12 , V_16 , V_93 ) ;
F_46 ( V_10 -> V_109 , V_110 , L_13 ) ;
V_96 = F_35 ( V_98 , V_111 , V_21 , V_33 , 4 , V_112 ) ;
V_99 = F_34 ( V_96 , V_113 ) ;
F_35 ( V_99 , V_114 , V_21 , V_33 , 4 , V_112 ) ;
F_35 ( V_99 , V_115 , V_21 , V_33 , 4 , V_112 ) ;
F_35 ( V_99 , V_116 , V_21 , V_33 , 4 , V_112 ) ;
F_35 ( V_99 , V_117 , V_21 , V_33 , 4 , V_112 ) ;
F_35 ( V_99 , V_118 , V_21 , V_33 , 4 , V_112 ) ;
F_35 ( V_99 , V_119 , V_21 , V_33 , 4 , V_112 ) ;
V_102 = F_35 ( V_99 , V_120 , V_21 , V_33 , 4 , V_112 ) ;
F_35 ( V_99 , V_121 , V_21 , V_33 , 4 , V_112 ) ;
V_90 = ( V_89 & V_122 ) >> V_123 ;
V_54 = F_11 ( V_16 , V_8 ) ;
if ( V_54 -> V_23 == V_66 ) {
if ( V_16 == V_124 ) {
V_54 -> V_23 = V_125 ;
} else if ( V_16 == V_126 ) {
V_54 -> V_23 = V_26 ;
}
}
if ( V_54 -> V_23 == V_26 && V_90 ) {
F_45 ( V_102 , L_14 ) ;
}
if ( V_54 -> V_23 == V_125 ) {
F_46 ( V_10 -> V_109 , V_127 , L_15 ) ;
F_45 ( V_102 , L_16 ) ;
return;
}
V_33 += 4 ;
V_97 = F_27 ( V_98 , V_21 , V_33 , 0 , L_17 ) ;
F_41 ( V_97 ) ;
V_101 = F_34 ( V_97 , V_128 ) ;
V_83 = F_38 ( V_21 , V_101 , V_10 , V_16 , V_93 , V_8 ) ;
if ( V_83 > 0 )
F_45 ( V_95 , L_18 , V_83 ) ;
if ( V_90 == 2 || V_90 == 3 )
{
T_12 V_129 = V_33 ;
T_14 V_130 ;
T_14 V_131 ;
T_12 V_132 ;
V_130 = F_30 ( V_21 , V_33 ) ;
F_35 ( V_98 , V_133 , V_21 , V_33 , 1 , V_112 ) ;
V_33 += 1 ;
if ( V_130 > 0 ) {
V_96 = F_35 ( V_98 , V_134 , V_21 , V_33 , V_130 , V_75 ) ;
V_100 = F_34 ( V_96 , V_135 ) ;
V_131 = F_30 ( V_21 , V_33 ) ;
F_35 ( V_100 , V_136 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_137 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_138 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_139 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_140 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_141 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_142 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_143 , V_21 , V_33 , 1 , V_112 ) ;
V_33 += 1 ;
if ( V_131 & V_144 ) {
T_20 V_145 = 0 ;
T_6 V_146 = 0 ;
T_14 V_147 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_145 = ( V_145 << 8 ) | V_147 ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_145 = ( V_145 << 8 ) | V_147 ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_145 = ( V_145 << 8 ) | V_147 ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_145 = ( V_145 << 8 ) | V_147 ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_145 = ( V_145 << 1 ) | ( ( V_147 >> 7 ) & 0x01 ) ;
V_146 = ( V_147 & 0x01 ) ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_146 = ( V_146 << 8 ) | V_147 ;
V_33 += 1 ;
F_40 ( V_100 , V_148 , V_21 , V_33 - 6 , 6 ,
L_19 V_149 L_20 V_149 L_21 ,
V_145 , V_146 , V_145 * 300 + V_146 ) ;
}
if ( V_131 & V_150 ) {
T_20 V_151 = 0 ;
T_6 V_152 = 0 ;
T_14 V_147 = 0 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_151 = ( V_151 << 8 ) | V_147 ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_151 = ( V_151 << 8 ) | V_147 ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_151 = ( V_151 << 8 ) | V_147 ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_151 = ( V_151 << 8 ) | V_147 ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_151 = ( V_151 << 1 ) | ( ( V_147 >> 7 ) & 0x01 ) ;
V_152 = ( V_147 & 0x01 ) ;
V_33 += 1 ;
V_147 = F_30 ( V_21 , V_33 ) ;
V_152 = ( V_152 << 8 ) | V_147 ;
V_33 += 1 ;
F_40 ( V_100 , V_153 , V_21 , V_33 - 6 , 6 ,
L_22 V_149 L_20 V_149 L_21 ,
V_151 , V_152 , V_151 * 300 + V_152 ) ;
V_33 += 6 ;
}
if ( V_131 & V_154 ) {
F_35 ( V_100 , V_155 , V_21 , V_33 , 1 , V_112 ) ;
V_33 += 1 ;
}
if ( V_131 & V_156 ) {
T_14 V_157 ;
V_157 = F_30 ( V_21 , V_33 ) ;
F_35 ( V_100 , V_158 , V_21 , V_33 , 1 , V_112 ) ;
V_33 += 1 ;
F_35 ( V_100 , V_159 , V_21 , V_33 , V_157 , V_75 ) ;
V_33 += V_157 ;
}
if ( V_131 & V_160 ) {
T_14 V_161 ;
T_14 V_162 ;
T_12 V_163 = V_33 ;
T_12 V_164 = 0 ;
V_161 = F_30 ( V_21 , V_33 ) ;
F_35 ( V_100 , V_165 , V_21 , V_33 , 1 , V_112 ) ;
V_33 += 1 ;
V_162 = F_30 ( V_21 , V_33 ) ;
F_35 ( V_100 , V_166 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_167 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_168 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_169 , V_21 , V_33 , 1 , V_112 ) ;
V_33 += 1 ;
if ( V_162 & V_170 ) {
F_35 ( V_100 , V_171 , V_21 , V_33 , 2 , V_112 ) ;
F_35 ( V_100 , V_172 , V_21 , V_33 , 2 , V_112 ) ;
V_33 += 2 ;
}
if ( V_162 & V_173 ) {
F_35 ( V_100 , V_174 , V_21 , V_33 , 3 , V_112 ) ;
F_35 ( V_100 , V_175 , V_21 , V_33 , 3 , V_112 ) ;
V_33 += 3 ;
}
if ( V_162 & V_176 ) {
F_35 ( V_100 , V_177 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_178 , V_21 , V_33 , 1 , V_112 ) ;
F_35 ( V_100 , V_179 , V_21 , V_33 , 1 , V_112 ) ;
V_33 += 1 ;
F_35 ( V_100 , V_180 , V_21 , V_33 , 2 , V_112 ) ;
F_35 ( V_100 , V_181 , V_21 , V_33 , 2 , V_112 ) ;
V_33 += 2 ;
F_35 ( V_100 , V_182 , V_21 , V_33 , 2 , V_112 ) ;
F_35 ( V_100 , V_183 , V_21 , V_33 , 2 , V_112 ) ;
V_33 += 2 ;
}
V_164 = ( V_161 + 1 ) - ( V_33 - V_163 ) ;
if ( V_164 > 0 ) {
F_35 ( V_100 , V_184 , V_21 , V_33 , V_164 , V_75 ) ;
V_33 += V_164 ;
}
}
V_132 = ( V_130 + 1 ) - ( V_33 - V_129 ) ;
if ( V_132 > 0 ) {
F_35 ( V_100 , V_185 , V_21 , V_33 , V_132 , V_75 ) ;
V_33 += V_132 ;
}
}
}
if ( ( V_33 - V_91 ) < V_103 )
V_92 = V_103 - ( V_33 - V_91 ) ;
else
V_92 = 0 ;
if ( ! V_92 )
return;
if ( V_90 == 2 ) {
F_46 ( V_10 -> V_109 , V_127 , L_23 ) ;
F_35 ( V_98 , V_74 , V_21 , V_33 , V_92 , V_75 ) ;
V_33 += V_92 ;
}
if ( ! V_94 ) {
F_28 ( V_21 , V_33 , V_92 , V_10 , V_24 , V_98 , V_53 , V_54 ) ;
} else {
F_46 ( V_10 -> V_109 , V_127 , L_24 ) ;
}
return;
}
static void
F_47 ( T_7 * V_21 , T_4 * V_10 , T_8 * V_24 )
{
T_10 V_33 = 0 ;
T_2 * V_8 ;
V_8 = F_48 ( V_10 ) ;
for (; F_49 ( V_21 , V_33 ) >= V_103 ; V_33 += V_103 ) {
F_43 ( V_21 , V_33 , V_10 , V_24 , V_8 ) ;
}
}
static T_13
F_50 ( T_7 * V_21 , T_4 * V_10 , T_8 * V_24 , void * V_42 V_186 )
{
T_12 V_187 ;
T_10 V_33 = 0 ;
V_187 = F_15 ( V_21 , V_33 ) ;
if ( V_187 == 0 ) {
return FALSE ;
}
if ( ( V_187 % V_103 ) != 0 ) {
return FALSE ;
} else {
while ( F_51 ( V_21 , V_33 ) ) {
if ( F_30 ( V_21 , V_33 ) != V_188 ) {
return FALSE ;
}
V_33 += V_103 ;
}
}
F_47 ( V_21 , V_10 , V_24 ) ;
return TRUE ;
}
static void
F_52 ( void ) {
F_53 ( & V_40 ,
& V_189 ) ;
}
void
F_54 ( void )
{
static T_21 V_190 [] = {
{ & V_111 , {
L_25 , L_26 ,
V_191 , V_192 , NULL , 0 , NULL , V_193
} } ,
{ & V_114 , {
L_27 , L_28 ,
V_191 , V_192 , F_55 ( V_194 ) , V_195 , NULL , V_193
} } ,
{ & V_115 , {
L_29 , L_30 ,
V_191 , V_196 , NULL , V_197 , NULL , V_193
} } ,
{ & V_116 , {
L_31 , L_32 ,
V_191 , V_196 , NULL , V_198 , NULL , V_193
} } ,
{ & V_117 , {
L_33 , L_34 ,
V_191 , V_196 , NULL , V_199 , NULL , V_193
} } ,
{ & V_118 , {
L_35 , L_36 ,
V_191 , V_192 , F_55 ( V_200 ) , V_105 , NULL , V_193
} } ,
{ & V_119 , {
L_37 , L_38 ,
V_191 , V_192 , F_55 ( V_201 ) , V_108 , NULL , V_193
} } ,
{ & V_120 , {
L_39 , L_40 ,
V_191 , V_192 , F_55 ( V_202 ) , V_122 , NULL , V_193
} } ,
{ & V_121 , {
L_41 , L_42 ,
V_191 , V_196 , NULL , V_84 , NULL , V_193
} } ,
{ & V_86 , {
L_43 , L_44 ,
V_203 , V_204 , NULL , 0x0 , NULL , V_193
} } ,
#if 0
{ &hf_mp2t_analysis_flags, {
"MPEG2-TS Analysis Flags", "mp2t.analysis.flags",
FT_NONE, BASE_NONE, NULL, 0x0,
"This frame has some of the MPEG2 analysis flags set", HFILL
} } ,
#endif
{ & V_87 , {
L_45 , L_46 ,
V_205 , V_196 , NULL , 0x0 ,
L_47 , V_193
} } ,
{ & V_88 , {
L_48 , L_49 ,
V_205 , V_196 , NULL , 0x0 ,
L_50 , V_193
} } ,
{ & V_134 , {
L_51 , L_52 ,
V_203 , V_204 , NULL , 0 , NULL , V_193
} } ,
{ & V_133 , {
L_53 , L_54 ,
V_205 , V_196 , NULL , 0x0 , NULL , V_193
} } ,
{ & V_136 , {
L_55 , L_56 ,
V_205 , V_196 , NULL , V_206 , NULL , V_193
} } ,
{ & V_137 , {
L_57 , L_58 ,
V_205 , V_196 , NULL , V_207 , NULL , V_193
} } ,
{ & V_138 , {
L_59 , L_60 ,
V_205 , V_196 , NULL , V_208 , NULL , V_193
} } ,
{ & V_139 , {
L_61 , L_62 ,
V_205 , V_196 , NULL , V_144 , NULL , V_193
} } ,
{ & V_140 , {
L_63 , L_64 ,
V_205 , V_196 , NULL , V_150 , NULL , V_193
} } ,
{ & V_141 , {
L_65 , L_66 ,
V_205 , V_196 , NULL , V_154 , NULL , V_193
} } ,
{ & V_142 , {
L_67 , L_68 ,
V_205 , V_196 , NULL , V_156 , NULL , V_193
} } ,
{ & V_143 , {
L_69 , L_70 ,
V_205 , V_196 , NULL , V_160 , NULL , V_193
} } ,
{ & V_148 , {
L_71 , L_72 ,
V_203 , V_204 , NULL , 0 , NULL , V_193
} } ,
{ & V_153 , {
L_73 , L_74 ,
V_203 , V_204 , NULL , 0 , NULL , V_193
} } ,
{ & V_155 , {
L_75 , L_76 ,
V_205 , V_196 , NULL , 0 , NULL , V_193
} } ,
{ & V_158 , {
L_77 , L_78 ,
V_205 , V_196 , NULL , 0 , NULL , V_193
} } ,
{ & V_159 , {
L_79 , L_80 ,
V_209 , V_204 , NULL , 0 , NULL , V_193
} } ,
{ & V_165 , {
L_81 , L_82 ,
V_205 , V_196 , NULL , 0 , NULL , V_193
} } ,
{ & V_166 , {
L_83 , L_84 ,
V_205 , V_196 , NULL , V_170 , NULL , V_193
} } ,
{ & V_167 , {
L_85 , L_86 ,
V_205 , V_196 , NULL , V_173 , NULL , V_193
} } ,
{ & V_168 , {
L_87 , L_88 ,
V_205 , V_196 , NULL , V_176 , NULL , V_193
} } ,
{ & V_169 , {
L_89 , L_90 ,
V_205 , V_196 , NULL , 0x1F , NULL , V_193
} } ,
{ & V_184 , {
L_89 , L_91 ,
V_209 , V_204 , NULL , 0x0 , NULL , V_193
} } ,
{ & V_185 , {
L_8 , L_92 ,
V_209 , V_204 , NULL , 0x0 , NULL , V_193
} } ,
{ & V_171 , {
L_93 , L_94 ,
V_210 , V_196 , NULL , 0x8000 , NULL , V_193
} } ,
{ & V_172 , {
L_95 , L_96 ,
V_210 , V_196 , NULL , 0x7FFF , NULL , V_193
} } ,
{ & V_174 , {
L_89 , L_97 ,
V_211 , V_196 , NULL , 0xC00000 , NULL , V_193
} } ,
{ & V_175 , {
L_98 , L_99 ,
V_211 , V_196 , NULL , 0x3FFFFF , NULL , V_193
} } ,
{ & V_177 , {
L_100 , L_101 ,
V_205 , V_196 , NULL , 0xF0 , NULL , V_193
} } ,
{ & V_178 , {
L_102 , L_103 ,
V_205 , V_196 , NULL , 0x0E , NULL , V_193
} } ,
{ & V_179 , {
L_104 , L_105 ,
V_205 , V_196 , NULL , 0x01 , NULL , V_193
} } ,
{ & V_180 , {
L_106 , L_107 ,
V_210 , V_196 , NULL , 0xFFFE , NULL , V_193
} } ,
{ & V_181 , {
L_104 , L_108 ,
V_210 , V_196 , NULL , 0x0001 , NULL , V_193
} } ,
{ & V_182 , {
L_109 , L_110 ,
V_210 , V_196 , NULL , 0xFFFE , NULL , V_193
} } ,
{ & V_183 , {
L_104 , L_111 ,
V_210 , V_196 , NULL , 0x0001 , NULL , V_193
} } ,
#if 0
{ &hf_mp2t_payload, {
"Payload", "mp2t.payload",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
} } ,
#endif
{ & V_74 , {
L_8 , L_112 ,
V_209 , V_204 , NULL , 0x0 , NULL , V_193
} } ,
{ & V_212 , {
L_113 , L_114 ,
V_203 , V_204 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_213 , {
L_115 , L_116 ,
V_214 , V_204 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_215 , {
L_117 , L_118 ,
V_216 , V_204 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_217 , {
L_119 ,
L_120 ,
V_216 , V_204 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_218 , {
L_121 ,
L_122 ,
V_216 , V_204 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_219 , {
L_123 , L_124 ,
V_216 , V_204 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_220 , {
L_125 , L_126 ,
V_214 , V_204 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_221 , {
L_127 , L_128 ,
V_191 , V_196 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_222 , {
L_129 , L_130 ,
V_214 , V_204 , NULL , 0x00 , NULL , V_193
} } ,
{ & V_223 , {
L_131 , L_132 ,
V_191 , V_196 , NULL , 0x00 , NULL , V_193
} }
} ;
static T_12 * V_224 [] =
{
& V_104 ,
& V_113 ,
& V_135 ,
& V_128 ,
& V_73 ,
& V_225 ,
& V_226
} ;
V_9 = F_56 ( L_133 , L_134 , L_135 ) ;
F_57 ( L_135 , F_47 , V_9 ) ;
F_58 ( V_9 , V_190 , F_59 ( V_190 ) ) ;
F_60 ( V_224 , F_59 ( V_224 ) ) ;
F_61 ( L_36 , & V_227 ) ;
F_62 ( F_52 ) ;
}
void
F_63 ( void )
{
T_9 V_228 ;
F_64 ( L_136 , F_50 , V_9 ) ;
V_228 = F_65 ( F_47 , V_9 ) ;
F_66 ( L_137 , V_229 , V_228 ) ;
F_67 ( L_138 , V_228 ) ;
F_64 ( L_139 , F_50 , V_9 ) ;
F_66 ( L_140 , V_230 , V_228 ) ;
V_27 = F_68 ( L_141 ) ;
V_29 = F_68 ( L_142 ) ;
V_31 = F_68 ( L_143 ) ;
V_32 = F_68 ( L_144 ) ;
}
