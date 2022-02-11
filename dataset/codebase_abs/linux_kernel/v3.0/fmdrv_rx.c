void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_3 . V_4 = V_5 ;
V_1 -> V_2 . V_3 . V_6 = 0 ;
V_1 -> V_2 . V_3 . V_7 = 0 ;
V_1 -> V_2 . V_3 . V_8 = 0 ;
if ( V_1 -> V_2 . V_9 == V_10 )
V_1 -> V_11 . V_12 |= V_13 ;
}
void F_2 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_14 . V_15 = V_16 ;
V_1 -> V_2 . V_14 . V_17 = 0 ;
V_1 -> V_2 . V_14 . V_18 = 0 ;
}
T_1 F_3 ( struct V_1 * V_1 , T_1 V_19 )
{
unsigned long V_20 ;
T_2 V_21 , V_22 , V_23 ;
T_1 V_24 ;
T_1 V_25 , V_26 ;
if ( V_19 < V_1 -> V_2 . V_27 . V_28 || V_19 > V_1 -> V_2 . V_27 . V_29 ) {
F_4 ( L_1 , V_19 ) ;
return - V_30 ;
}
V_21 = V_31 ;
V_25 = F_5 ( V_1 , V_32 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = V_34 ;
V_25 = F_5 ( V_1 , V_35 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = ( V_19 - V_1 -> V_2 . V_27 . V_28 ) / V_36 ;
V_25 = F_5 ( V_1 , V_37 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_5 ( V_1 , V_38 , V_39 , NULL , 2 , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_23 = V_1 -> V_11 . V_12 ;
V_1 -> V_11 . V_12 = ( V_40 | V_41 ) ;
V_21 = V_1 -> V_11 . V_12 ;
V_25 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = V_43 ;
V_25 = F_5 ( V_1 , V_44 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
goto exit;
F_6 ( & V_1 -> V_45 ) ;
V_20 = F_7 ( & V_1 -> V_45 ,
V_46 ) ;
if ( ! V_20 ) {
F_4 ( L_2 ,
F_8 ( V_46 ) / 1000 ) ;
V_25 = - V_47 ;
goto exit;
}
V_25 = F_5 ( V_1 , V_37 , V_39 , NULL , 2 , & V_22 , & V_26 ) ;
if ( V_25 < 0 )
goto exit;
V_22 = F_9 ( V_22 ) ;
V_24 = ( V_1 -> V_2 . V_27 . V_28 + ( ( T_1 ) V_22 * V_36 ) ) ;
if ( V_24 != V_19 ) {
F_10 ( L_3
L_4 , V_24 , V_19 ) ;
}
V_1 -> V_2 . V_19 = V_24 ;
exit:
V_1 -> V_11 . V_12 = V_23 ;
V_21 = V_1 -> V_11 . V_12 ;
V_25 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 ) ;
F_2 ( V_1 ) ;
return V_25 ;
}
static T_1 F_11 ( struct V_1 * V_1 , T_1 V_48 )
{
T_2 V_21 ;
T_1 V_25 ;
if ( V_48 > 0 && V_48 <= 50000 )
V_48 = V_49 ;
else if ( V_48 > 50000 && V_48 <= 100000 )
V_48 = V_50 ;
else
V_48 = V_51 ;
V_21 = V_48 ;
V_25 = F_5 ( V_1 , V_52 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_1 -> V_2 . V_27 . V_53 = V_48 * V_36 ;
return V_25 ;
}
T_1 F_12 ( struct V_1 * V_1 , T_1 V_54 ,
T_1 V_55 , T_1 V_48 )
{
T_1 V_26 ;
T_2 V_22 , V_56 , V_57 ;
T_2 V_21 , V_58 , V_23 ;
T_2 V_59 , V_60 ;
unsigned long V_20 ;
T_1 V_25 ;
V_25 = F_11 ( V_1 , V_48 ) ;
if ( V_25 < 0 ) {
F_4 ( L_5 ) ;
return V_25 ;
}
V_25 = F_5 ( V_1 , V_37 , V_39 , NULL ,
sizeof( V_22 ) , & V_22 , & V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
V_22 = F_9 ( V_22 ) ;
V_57 = ( V_1 -> V_2 . V_27 . V_29 - V_1 -> V_2 . V_27 . V_28 ) / V_36 ;
V_60 = V_1 -> V_2 . V_27 . V_53 / V_36 ;
V_59 = V_22 % V_60 ;
V_56 = V_54 ? V_22 + V_60 :
V_22 - V_60 ;
if ( ( short ) V_56 < 0 )
V_56 = V_57 - V_59 ;
else if ( V_56 > V_57 )
V_56 = 0 + V_59 ;
V_61:
V_21 = V_56 ;
V_25 = F_5 ( V_1 , V_37 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = ( V_54 ? V_62 : V_63 ) ;
V_25 = F_5 ( V_1 , V_64 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_5 ( V_1 , V_38 , V_39 , NULL , 2 , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_23 = V_1 -> V_11 . V_12 ;
V_1 -> V_11 . V_12 = ( V_40 | V_41 ) ;
V_21 = V_1 -> V_11 . V_12 ;
V_25 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = V_65 ;
V_25 = F_5 ( V_1 , V_44 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
F_6 ( & V_1 -> V_45 ) ;
V_20 = F_7 ( & V_1 -> V_45 ,
V_66 ) ;
if ( ! V_20 ) {
F_4 ( L_2 ,
F_8 ( V_66 ) / 1000 ) ;
return - V_47 ;
}
V_58 = V_1 -> V_11 . V_4 & ( V_67 | V_68 ) ;
V_1 -> V_11 . V_12 = V_23 ;
V_21 = V_1 -> V_11 . V_12 ;
V_25 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_58 & V_41 ) {
if ( V_55 == 0 ) {
V_1 -> V_2 . V_19 = V_54 ?
V_1 -> V_2 . V_27 . V_29 :
V_1 -> V_2 . V_27 . V_28 ;
} else {
V_1 -> V_2 . V_19 = V_54 ?
V_1 -> V_2 . V_27 . V_28 :
V_1 -> V_2 . V_27 . V_29 ;
V_56 = ( V_1 -> V_2 . V_19 -
V_1 -> V_2 . V_27 . V_28 ) / V_36 ;
goto V_61;
}
} else {
V_25 = F_5 ( V_1 , V_37 , V_39 , NULL , 2 ,
& V_22 , & V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
V_22 = F_9 ( V_22 ) ;
V_1 -> V_2 . V_19 = ( V_1 -> V_2 . V_27 . V_28 +
( ( T_1 ) V_22 * V_36 ) ) ;
}
F_1 ( V_1 ) ;
F_2 ( V_1 ) ;
return V_25 ;
}
T_1 F_13 ( struct V_1 * V_1 , T_2 V_69 )
{
T_2 V_21 ;
T_1 V_25 ;
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_69 < V_73 || V_69 > V_74 ) {
F_4 ( L_6 ,
V_73 , V_74 ) ;
return - V_30 ;
}
V_69 *= V_75 ;
V_21 = V_69 ;
V_25 = F_5 ( V_1 , V_76 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_1 -> V_2 . V_77 = V_69 ;
return V_25 ;
}
T_1 F_14 ( struct V_1 * V_1 , T_2 * V_78 )
{
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_78 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
* V_78 = V_1 -> V_2 . V_77 / V_75 ;
return 0 ;
}
T_1 F_15 ( struct V_1 * V_1 , T_1 * V_28 , T_1 * V_29 )
{
if ( V_28 != NULL )
* V_28 = V_1 -> V_2 . V_27 . V_28 ;
if ( V_29 != NULL )
* V_29 = V_1 -> V_2 . V_27 . V_29 ;
return 0 ;
}
void F_16 ( struct V_1 * V_1 , T_3 * V_27 )
{
* V_27 = V_1 -> V_2 . V_27 . V_80 ;
}
T_1 F_17 ( struct V_1 * V_1 , T_3 V_81 )
{
T_2 V_21 ;
T_1 V_82 = 0 ;
T_1 V_25 ;
if ( V_81 != V_83 &&
V_81 != V_84 ) {
F_4 ( L_8 ) ;
return - V_30 ;
}
if ( V_1 -> V_2 . V_27 . V_80 == V_81 ) {
F_4 ( L_9 ) ;
return 0 ;
}
V_21 = ( T_2 ) V_81 ;
V_25 = F_5 ( V_1 , V_85 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
F_18 ( V_1 , V_81 ) ;
if ( V_1 -> V_2 . V_19 < V_1 -> V_2 . V_27 . V_28 )
V_82 = V_1 -> V_2 . V_27 . V_28 ;
else if ( V_1 -> V_2 . V_19 > V_1 -> V_2 . V_27 . V_29 )
V_82 = V_1 -> V_2 . V_27 . V_29 ;
if ( V_82 ) {
F_19 ( L_10
L_11 , V_82 ) ;
V_25 = F_3 ( V_1 , V_82 ) ;
}
return V_25 ;
}
T_1 F_20 ( struct V_1 * V_1 , T_3 * V_86 )
{
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_86 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
* V_86 = V_1 -> V_2 . V_87 ;
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_1 )
{
T_2 V_21 , V_88 ;
T_1 V_25 ;
V_88 = 0 ;
switch ( V_1 -> V_2 . V_87 ) {
case V_89 :
V_88 = V_90 ;
break;
case V_91 :
V_88 = V_92 ;
break;
case V_93 :
V_88 = V_94 ;
break;
}
if ( V_1 -> V_2 . V_95 == V_96 )
V_88 |= V_97 ;
else
V_88 &= ~ V_97 ;
V_21 = V_88 ;
V_25 = F_5 ( V_1 , V_98 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
T_1 F_22 ( struct V_1 * V_1 , T_3 V_99 )
{
T_3 V_100 ;
T_1 V_25 ;
if ( V_1 -> V_2 . V_87 == V_99 )
return 0 ;
V_100 = V_1 -> V_2 . V_87 ;
V_1 -> V_2 . V_87 = V_99 ;
V_25 = F_21 ( V_1 ) ;
if ( V_25 < 0 ) {
V_1 -> V_2 . V_87 = V_100 ;
return V_25 ;
}
return 0 ;
}
T_1 F_23 ( struct V_1 * V_1 , T_3 * V_86 )
{
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_86 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
* V_86 = V_1 -> V_2 . V_95 ;
return 0 ;
}
T_1 F_24 ( struct V_1 * V_1 , T_3 V_101 )
{
T_3 V_100 ;
T_1 V_25 ;
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_101 != V_96 &&
V_101 != V_102 ) {
F_4 ( L_12 ) ;
return - V_30 ;
}
if ( V_1 -> V_2 . V_95 == V_101 )
return 0 ;
V_100 = V_1 -> V_2 . V_95 ;
V_1 -> V_2 . V_95 = V_101 ;
V_25 = F_21 ( V_1 ) ;
if ( V_25 < 0 ) {
V_1 -> V_2 . V_95 = V_100 ;
return V_25 ;
}
return 0 ;
}
T_1 F_25 ( struct V_1 * V_1 , T_2 * V_103 )
{
T_2 V_104 ;
T_1 V_26 ;
T_1 V_25 ;
if ( V_103 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
V_25 = F_5 ( V_1 , V_105 , V_39 , NULL , 2 ,
& V_104 , & V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
* V_103 = F_9 ( V_104 ) ;
return 0 ;
}
T_1 F_26 ( struct V_1 * V_1 , short V_106 )
{
T_2 V_21 ;
T_1 V_25 ;
if ( V_106 < V_107 ||
V_106 > V_108 ) {
F_4 ( L_13 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_106 ;
V_25 = F_5 ( V_1 , V_109 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_1 -> V_2 . V_110 = V_106 ;
return 0 ;
}
T_1 F_27 ( struct V_1 * V_1 , short * V_111 )
{
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_111 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
* V_111 = V_1 -> V_2 . V_110 ;
return 0 ;
}
T_1 F_28 ( struct V_1 * V_1 , T_2 V_112 )
{
T_2 V_21 ;
T_1 V_25 ;
if ( V_112 != V_113 && V_112 != V_114 ) {
F_4 ( L_14 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_112 ;
V_25 = F_5 ( V_1 , V_115 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = V_116 ;
V_25 = F_5 ( V_1 , V_117 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
T_1 F_29 ( struct V_1 * V_1 , T_2 * V_112 )
{
T_2 V_118 ;
T_1 V_25 , V_26 ;
if ( V_112 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
V_25 = F_5 ( V_1 , V_115 , V_39 , NULL , 2 ,
& V_118 , & V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
* V_112 = F_9 ( V_118 ) ;
return 0 ;
}
T_1 F_30 ( struct V_1 * V_1 , T_2 V_112 )
{
T_2 V_21 ;
T_1 V_25 ;
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_112 != V_119 &&
V_112 != V_120 ) {
F_4 ( L_15 , V_112 ) ;
return - V_30 ;
}
V_21 = V_112 ;
V_25 = F_5 ( V_1 , V_121 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_1 -> V_2 . V_122 = V_112 ;
return 0 ;
}
T_1 F_31 ( struct V_1 * V_1 , T_2 * V_123 )
{
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_123 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
* V_123 = V_1 -> V_2 . V_122 ;
return 0 ;
}
T_1 F_32 ( struct V_1 * V_1 , T_3 V_124 )
{
T_2 V_21 ;
T_1 V_25 ;
if ( V_124 != V_125 && V_124 != V_5 ) {
F_4 ( L_16 ) ;
return - V_30 ;
}
if ( V_124 == V_125
&& V_1 -> V_2 . V_3 . V_4 == V_5 ) {
V_21 = V_126 ;
V_25 = F_5 ( V_1 , V_127 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = V_128 ;
V_25 = F_5 ( V_1 , V_129 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_5 ( V_1 , V_38 , V_39 , NULL , 2 ,
NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = V_130 ;
V_25 = F_5 ( V_1 , V_131 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_1 -> V_11 . V_12 |= V_132 ;
V_21 = V_1 -> V_11 . V_12 ;
V_25 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 ) {
V_1 -> V_11 . V_12 &= ~ V_132 ;
return V_25 ;
}
V_1 -> V_2 . V_3 . V_4 = V_125 ;
} else if ( V_124 == V_5
&& V_1 -> V_2 . V_3 . V_4 == V_125 ) {
V_21 = V_133 ;
V_25 = F_5 ( V_1 , V_127 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_1 -> V_2 . V_3 . V_6 = 0 ;
V_1 -> V_2 . V_3 . V_7 = 0 ;
V_1 -> V_2 . V_3 . V_8 = 0 ;
F_2 ( V_1 ) ;
V_1 -> V_11 . V_12 &= ~ ( V_132 ) ;
V_1 -> V_2 . V_3 . V_4 = V_5 ;
}
return 0 ;
}
T_1 F_33 ( struct V_1 * V_1 , T_3 * V_134 )
{
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_134 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
* V_134 = V_1 -> V_2 . V_3 . V_4 ;
return 0 ;
}
T_1 F_34 ( struct V_1 * V_1 , T_3 V_135 )
{
T_2 V_21 ;
T_1 V_25 ;
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_135 != V_136 && V_135 != V_137 ) {
F_4 ( L_17 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_135 ;
V_25 = F_5 ( V_1 , V_138 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_1 -> V_2 . V_135 = V_135 ;
return 0 ;
}
T_1 F_35 ( struct V_1 * V_1 , T_3 * V_135 )
{
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_135 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
* V_135 = V_1 -> V_2 . V_135 ;
return 0 ;
}
T_1 F_36 ( struct V_1 * V_1 , T_3 V_9 )
{
T_2 V_21 ;
T_1 V_25 ;
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_9 != V_10 &&
V_9 != V_139 ) {
F_4 ( L_18 ) ;
return - V_30 ;
}
if ( V_9 == V_10 )
V_1 -> V_11 . V_12 |= V_13 ;
else
V_1 -> V_11 . V_12 &= ~ V_13 ;
V_21 = V_1 -> V_11 . V_12 ;
V_25 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
V_1 -> V_2 . V_9 = V_9 ;
return 0 ;
}
T_1 F_37 ( struct V_1 * V_1 , T_3 * V_9 )
{
if ( V_1 -> V_70 != V_71 )
return - V_72 ;
if ( V_9 == NULL ) {
F_4 ( L_7 ) ;
return - V_79 ;
}
* V_9 = V_1 -> V_2 . V_9 ;
return 0 ;
}
