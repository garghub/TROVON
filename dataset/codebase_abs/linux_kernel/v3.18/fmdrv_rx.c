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
int F_3 ( struct V_1 * V_1 , T_1 V_19 )
{
unsigned long V_20 ;
T_2 V_21 , V_22 , V_23 ;
T_1 V_24 ;
T_1 V_25 ;
int V_26 ;
if ( V_19 < V_1 -> V_2 . V_27 . V_28 || V_19 > V_1 -> V_2 . V_27 . V_29 ) {
F_4 ( L_1 , V_19 ) ;
return - V_30 ;
}
V_21 = V_31 ;
V_26 = F_5 ( V_1 , V_32 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_34 ;
V_26 = F_5 ( V_1 , V_35 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = ( V_19 - V_1 -> V_2 . V_27 . V_28 ) / V_36 ;
V_26 = F_5 ( V_1 , V_37 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_5 ( V_1 , V_38 , V_39 , NULL , 2 , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_23 = V_1 -> V_11 . V_12 ;
V_1 -> V_11 . V_12 = ( V_40 | V_41 ) ;
V_21 = V_1 -> V_11 . V_12 ;
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_43 ;
V_26 = F_5 ( V_1 , V_44 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
goto exit;
F_6 ( & V_1 -> V_45 ) ;
V_20 = F_7 ( & V_1 -> V_45 ,
V_46 ) ;
if ( ! V_20 ) {
F_4 ( L_2 ,
F_8 ( V_46 ) / 1000 ) ;
V_26 = - V_47 ;
goto exit;
}
V_26 = F_5 ( V_1 , V_37 , V_39 , NULL , 2 , & V_22 , & V_25 ) ;
if ( V_26 < 0 )
goto exit;
V_22 = F_9 ( ( V_48 V_49 ) V_22 ) ;
V_24 = ( V_1 -> V_2 . V_27 . V_28 + ( ( T_1 ) V_22 * V_36 ) ) ;
if ( V_24 != V_19 ) {
F_10 ( L_3
L_4 , V_24 , V_19 ) ;
}
V_1 -> V_2 . V_19 = V_24 ;
exit:
V_1 -> V_11 . V_12 = V_23 ;
V_21 = V_1 -> V_11 . V_12 ;
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
F_1 ( V_1 ) ;
F_2 ( V_1 ) ;
return V_26 ;
}
static int F_11 ( struct V_1 * V_1 , T_1 V_50 )
{
T_2 V_21 ;
int V_26 ;
if ( V_50 > 0 && V_50 <= 50000 )
V_50 = V_51 ;
else if ( V_50 > 50000 && V_50 <= 100000 )
V_50 = V_52 ;
else
V_50 = V_53 ;
V_21 = V_50 ;
V_26 = F_5 ( V_1 , V_54 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_27 . V_55 = V_50 * V_36 ;
return V_26 ;
}
int F_12 ( struct V_1 * V_1 , T_1 V_56 ,
T_1 V_57 , T_1 V_50 )
{
T_1 V_25 ;
T_2 V_22 , V_58 , V_59 ;
T_2 V_21 , V_60 , V_23 ;
T_2 V_61 , V_62 ;
unsigned long V_20 ;
int V_26 ;
V_26 = F_11 ( V_1 , V_50 ) ;
if ( V_26 < 0 ) {
F_4 ( L_5 ) ;
return V_26 ;
}
V_26 = F_5 ( V_1 , V_37 , V_39 , NULL ,
sizeof( V_22 ) , & V_22 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
V_22 = F_9 ( ( V_48 V_49 ) V_22 ) ;
V_59 = ( V_1 -> V_2 . V_27 . V_29 - V_1 -> V_2 . V_27 . V_28 ) / V_36 ;
V_62 = V_1 -> V_2 . V_27 . V_55 / V_36 ;
V_61 = V_22 % V_62 ;
V_58 = V_56 ? V_22 + V_62 :
V_22 - V_62 ;
if ( ( short ) V_58 < 0 )
V_58 = V_59 - V_61 ;
else if ( V_58 > V_59 )
V_58 = 0 + V_61 ;
V_63:
V_21 = V_58 ;
V_26 = F_5 ( V_1 , V_37 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = ( V_56 ? V_64 : V_65 ) ;
V_26 = F_5 ( V_1 , V_66 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_5 ( V_1 , V_38 , V_39 , NULL , 2 , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_23 = V_1 -> V_11 . V_12 ;
V_1 -> V_11 . V_12 = ( V_40 | V_41 ) ;
V_21 = V_1 -> V_11 . V_12 ;
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_67 ;
V_26 = F_5 ( V_1 , V_44 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
F_6 ( & V_1 -> V_45 ) ;
V_20 = F_7 ( & V_1 -> V_45 ,
V_68 ) ;
if ( ! V_20 ) {
F_4 ( L_2 ,
F_8 ( V_68 ) / 1000 ) ;
return - V_69 ;
}
V_60 = V_1 -> V_11 . V_4 & ( V_70 | V_71 ) ;
V_1 -> V_11 . V_12 = V_23 ;
V_21 = V_1 -> V_11 . V_12 ;
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_60 & V_41 ) {
if ( V_57 == 0 ) {
V_1 -> V_2 . V_19 = V_56 ?
V_1 -> V_2 . V_27 . V_29 :
V_1 -> V_2 . V_27 . V_28 ;
} else {
V_1 -> V_2 . V_19 = V_56 ?
V_1 -> V_2 . V_27 . V_28 :
V_1 -> V_2 . V_27 . V_29 ;
V_58 = ( V_1 -> V_2 . V_19 -
V_1 -> V_2 . V_27 . V_28 ) / V_36 ;
goto V_63;
}
} else {
V_26 = F_5 ( V_1 , V_37 , V_39 , NULL , 2 ,
& V_22 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
V_22 = F_9 ( ( V_48 V_49 ) V_22 ) ;
V_1 -> V_2 . V_19 = ( V_1 -> V_2 . V_27 . V_28 +
( ( T_1 ) V_22 * V_36 ) ) ;
}
F_1 ( V_1 ) ;
F_2 ( V_1 ) ;
return V_26 ;
}
int F_13 ( struct V_1 * V_1 , T_2 V_72 )
{
T_2 V_21 ;
int V_26 ;
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_72 > V_76 ) {
F_4 ( L_6 ,
V_77 , V_76 ) ;
return - V_30 ;
}
V_72 *= V_78 ;
V_21 = V_72 ;
V_26 = F_5 ( V_1 , V_79 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_80 = V_72 ;
return V_26 ;
}
int F_14 ( struct V_1 * V_1 , T_2 * V_81 )
{
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_81 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
* V_81 = V_1 -> V_2 . V_80 / V_78 ;
return 0 ;
}
int F_15 ( struct V_1 * V_1 , T_1 * V_28 , T_1 * V_29 )
{
if ( V_28 != NULL )
* V_28 = V_1 -> V_2 . V_27 . V_28 ;
if ( V_29 != NULL )
* V_29 = V_1 -> V_2 . V_27 . V_29 ;
return 0 ;
}
void F_16 ( struct V_1 * V_1 , T_3 * V_27 )
{
* V_27 = V_1 -> V_2 . V_27 . V_83 ;
}
int F_17 ( struct V_1 * V_1 , T_3 V_84 )
{
T_2 V_21 ;
T_1 V_85 = 0 ;
int V_26 ;
if ( V_84 != V_86 &&
V_84 != V_87 ) {
F_4 ( L_8 ) ;
return - V_30 ;
}
if ( V_1 -> V_2 . V_27 . V_83 == V_84 ) {
F_4 ( L_9 ) ;
return 0 ;
}
V_21 = ( T_2 ) V_84 ;
V_26 = F_5 ( V_1 , V_88 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
F_18 ( V_1 , V_84 ) ;
if ( V_1 -> V_2 . V_19 < V_1 -> V_2 . V_27 . V_28 )
V_85 = V_1 -> V_2 . V_27 . V_28 ;
else if ( V_1 -> V_2 . V_19 > V_1 -> V_2 . V_27 . V_29 )
V_85 = V_1 -> V_2 . V_27 . V_29 ;
if ( V_85 ) {
F_19 ( L_10
L_11 , V_85 ) ;
V_26 = F_3 ( V_1 , V_85 ) ;
}
return V_26 ;
}
int F_20 ( struct V_1 * V_1 , T_3 * V_89 )
{
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_89 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
* V_89 = V_1 -> V_2 . V_90 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
T_2 V_21 , V_91 ;
int V_26 ;
V_91 = 0 ;
switch ( V_1 -> V_2 . V_90 ) {
case V_92 :
V_91 = V_93 ;
break;
case V_94 :
V_91 = V_95 ;
break;
case V_96 :
V_91 = V_97 ;
break;
}
if ( V_1 -> V_2 . V_98 == V_99 )
V_91 |= V_100 ;
else
V_91 &= ~ V_100 ;
V_21 = V_91 ;
V_26 = F_5 ( V_1 , V_101 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
}
int F_22 ( struct V_1 * V_1 , T_3 V_102 )
{
T_3 V_103 ;
int V_26 ;
if ( V_1 -> V_2 . V_90 == V_102 )
return 0 ;
V_103 = V_1 -> V_2 . V_90 ;
V_1 -> V_2 . V_90 = V_102 ;
V_26 = F_21 ( V_1 ) ;
if ( V_26 < 0 ) {
V_1 -> V_2 . V_90 = V_103 ;
return V_26 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_1 , T_3 * V_89 )
{
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_89 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
* V_89 = V_1 -> V_2 . V_98 ;
return 0 ;
}
int F_24 ( struct V_1 * V_1 , T_3 V_104 )
{
T_3 V_103 ;
int V_26 ;
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_104 != V_99 &&
V_104 != V_105 ) {
F_4 ( L_12 ) ;
return - V_30 ;
}
if ( V_1 -> V_2 . V_98 == V_104 )
return 0 ;
V_103 = V_1 -> V_2 . V_98 ;
V_1 -> V_2 . V_98 = V_104 ;
V_26 = F_21 ( V_1 ) ;
if ( V_26 < 0 ) {
V_1 -> V_2 . V_98 = V_103 ;
return V_26 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_1 , T_2 * V_106 )
{
V_49 V_107 ;
T_1 V_25 ;
int V_26 ;
if ( V_106 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
V_26 = F_5 ( V_1 , V_108 , V_39 , NULL , 2 ,
& V_107 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_106 = F_9 ( V_107 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_1 , short V_109 )
{
T_2 V_21 ;
int V_26 ;
if ( V_109 < V_110 ||
V_109 > V_111 ) {
F_4 ( L_13 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_109 ;
V_26 = F_5 ( V_1 , V_112 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_113 = V_109 ;
return 0 ;
}
int F_27 ( struct V_1 * V_1 , short * V_114 )
{
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_114 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
* V_114 = V_1 -> V_2 . V_113 ;
return 0 ;
}
int F_28 ( struct V_1 * V_1 , T_2 V_115 )
{
T_2 V_21 ;
int V_26 ;
if ( V_115 != V_116 && V_115 != V_117 ) {
F_4 ( L_14 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_115 ;
V_26 = F_5 ( V_1 , V_118 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_119 ;
V_26 = F_5 ( V_1 , V_120 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
}
int F_29 ( struct V_1 * V_1 , T_2 * V_115 )
{
V_49 V_121 ;
T_1 V_25 ;
int V_26 ;
if ( V_115 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
V_26 = F_5 ( V_1 , V_118 , V_39 , NULL , 2 ,
& V_121 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_115 = F_9 ( V_121 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_1 , T_2 V_115 )
{
T_2 V_21 ;
int V_26 ;
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_115 != V_122 &&
V_115 != V_123 ) {
F_4 ( L_15 , V_115 ) ;
return - V_30 ;
}
V_21 = V_115 ;
V_26 = F_5 ( V_1 , V_124 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_125 = V_115 ;
return 0 ;
}
int F_31 ( struct V_1 * V_1 , T_2 * V_126 )
{
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_126 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
* V_126 = V_1 -> V_2 . V_125 ;
return 0 ;
}
int F_32 ( struct V_1 * V_1 , T_3 V_127 )
{
T_2 V_21 ;
int V_26 ;
if ( V_127 != V_128 && V_127 != V_5 ) {
F_4 ( L_16 ) ;
return - V_30 ;
}
if ( V_127 == V_128
&& V_1 -> V_2 . V_3 . V_4 == V_5 ) {
V_21 = V_129 ;
V_26 = F_5 ( V_1 , V_130 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_131 ;
V_26 = F_5 ( V_1 , V_132 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_5 ( V_1 , V_38 , V_39 , NULL , 2 ,
NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_133 ;
V_26 = F_5 ( V_1 , V_134 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_11 . V_12 |= V_135 ;
V_21 = V_1 -> V_11 . V_12 ;
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 ) {
V_1 -> V_11 . V_12 &= ~ V_135 ;
return V_26 ;
}
V_1 -> V_2 . V_3 . V_4 = V_128 ;
} else if ( V_127 == V_5
&& V_1 -> V_2 . V_3 . V_4 == V_128 ) {
V_21 = V_136 ;
V_26 = F_5 ( V_1 , V_130 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_3 . V_6 = 0 ;
V_1 -> V_2 . V_3 . V_7 = 0 ;
V_1 -> V_2 . V_3 . V_8 = 0 ;
F_2 ( V_1 ) ;
V_1 -> V_11 . V_12 &= ~ ( V_135 ) ;
V_1 -> V_2 . V_3 . V_4 = V_5 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_1 , T_3 * V_137 )
{
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_137 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
* V_137 = V_1 -> V_2 . V_3 . V_4 ;
return 0 ;
}
int F_34 ( struct V_1 * V_1 , T_3 V_138 )
{
T_2 V_21 ;
int V_26 ;
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_138 != V_139 && V_138 != V_140 ) {
F_4 ( L_17 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_138 ;
V_26 = F_5 ( V_1 , V_141 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_138 = V_138 ;
return 0 ;
}
int F_35 ( struct V_1 * V_1 , T_3 * V_138 )
{
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_138 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
* V_138 = V_1 -> V_2 . V_138 ;
return 0 ;
}
int F_36 ( struct V_1 * V_1 , T_3 V_9 )
{
T_2 V_21 ;
int V_26 ;
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_9 != V_10 &&
V_9 != V_142 ) {
F_4 ( L_18 ) ;
return - V_30 ;
}
if ( V_9 == V_10 )
V_1 -> V_11 . V_12 |= V_13 ;
else
V_1 -> V_11 . V_12 &= ~ V_13 ;
V_21 = V_1 -> V_11 . V_12 ;
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_9 = V_9 ;
return 0 ;
}
int F_37 ( struct V_1 * V_1 , T_3 * V_9 )
{
if ( V_1 -> V_73 != V_74 )
return - V_75 ;
if ( V_9 == NULL ) {
F_4 ( L_7 ) ;
return - V_82 ;
}
* V_9 = V_1 -> V_2 . V_9 ;
return 0 ;
}
