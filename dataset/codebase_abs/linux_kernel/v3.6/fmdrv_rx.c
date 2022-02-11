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
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
F_1 ( V_1 ) ;
F_2 ( V_1 ) ;
return V_26 ;
}
static int F_11 ( struct V_1 * V_1 , T_1 V_48 )
{
T_2 V_21 ;
int V_26 ;
if ( V_48 > 0 && V_48 <= 50000 )
V_48 = V_49 ;
else if ( V_48 > 50000 && V_48 <= 100000 )
V_48 = V_50 ;
else
V_48 = V_51 ;
V_21 = V_48 ;
V_26 = F_5 ( V_1 , V_52 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_27 . V_53 = V_48 * V_36 ;
return V_26 ;
}
int F_12 ( struct V_1 * V_1 , T_1 V_54 ,
T_1 V_55 , T_1 V_48 )
{
T_1 V_25 ;
T_2 V_22 , V_56 , V_57 ;
T_2 V_21 , V_58 , V_23 ;
T_2 V_59 , V_60 ;
unsigned long V_20 ;
int V_26 ;
V_26 = F_11 ( V_1 , V_48 ) ;
if ( V_26 < 0 ) {
F_4 ( L_5 ) ;
return V_26 ;
}
V_26 = F_5 ( V_1 , V_37 , V_39 , NULL ,
sizeof( V_22 ) , & V_22 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
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
V_26 = F_5 ( V_1 , V_37 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = ( V_54 ? V_62 : V_63 ) ;
V_26 = F_5 ( V_1 , V_64 , V_33 , & V_21 ,
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
V_21 = V_65 ;
V_26 = F_5 ( V_1 , V_44 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
F_6 ( & V_1 -> V_45 ) ;
V_20 = F_7 ( & V_1 -> V_45 ,
V_66 ) ;
if ( ! V_20 ) {
F_4 ( L_2 ,
F_8 ( V_66 ) / 1000 ) ;
return - V_67 ;
}
V_58 = V_1 -> V_11 . V_4 & ( V_68 | V_69 ) ;
V_1 -> V_11 . V_12 = V_23 ;
V_21 = V_1 -> V_11 . V_12 ;
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
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
V_26 = F_5 ( V_1 , V_37 , V_39 , NULL , 2 ,
& V_22 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
V_22 = F_9 ( V_22 ) ;
V_1 -> V_2 . V_19 = ( V_1 -> V_2 . V_27 . V_28 +
( ( T_1 ) V_22 * V_36 ) ) ;
}
F_1 ( V_1 ) ;
F_2 ( V_1 ) ;
return V_26 ;
}
int F_13 ( struct V_1 * V_1 , T_2 V_70 )
{
T_2 V_21 ;
int V_26 ;
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_70 < V_74 || V_70 > V_75 ) {
F_4 ( L_6 ,
V_74 , V_75 ) ;
return - V_30 ;
}
V_70 *= V_76 ;
V_21 = V_70 ;
V_26 = F_5 ( V_1 , V_77 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_78 = V_70 ;
return V_26 ;
}
int F_14 ( struct V_1 * V_1 , T_2 * V_79 )
{
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_79 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
* V_79 = V_1 -> V_2 . V_78 / V_76 ;
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
* V_27 = V_1 -> V_2 . V_27 . V_81 ;
}
int F_17 ( struct V_1 * V_1 , T_3 V_82 )
{
T_2 V_21 ;
T_1 V_83 = 0 ;
int V_26 ;
if ( V_82 != V_84 &&
V_82 != V_85 ) {
F_4 ( L_8 ) ;
return - V_30 ;
}
if ( V_1 -> V_2 . V_27 . V_81 == V_82 ) {
F_4 ( L_9 ) ;
return 0 ;
}
V_21 = ( T_2 ) V_82 ;
V_26 = F_5 ( V_1 , V_86 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
F_18 ( V_1 , V_82 ) ;
if ( V_1 -> V_2 . V_19 < V_1 -> V_2 . V_27 . V_28 )
V_83 = V_1 -> V_2 . V_27 . V_28 ;
else if ( V_1 -> V_2 . V_19 > V_1 -> V_2 . V_27 . V_29 )
V_83 = V_1 -> V_2 . V_27 . V_29 ;
if ( V_83 ) {
F_19 ( L_10
L_11 , V_83 ) ;
V_26 = F_3 ( V_1 , V_83 ) ;
}
return V_26 ;
}
int F_20 ( struct V_1 * V_1 , T_3 * V_87 )
{
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_87 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
* V_87 = V_1 -> V_2 . V_88 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
T_2 V_21 , V_89 ;
int V_26 ;
V_89 = 0 ;
switch ( V_1 -> V_2 . V_88 ) {
case V_90 :
V_89 = V_91 ;
break;
case V_92 :
V_89 = V_93 ;
break;
case V_94 :
V_89 = V_95 ;
break;
}
if ( V_1 -> V_2 . V_96 == V_97 )
V_89 |= V_98 ;
else
V_89 &= ~ V_98 ;
V_21 = V_89 ;
V_26 = F_5 ( V_1 , V_99 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
}
int F_22 ( struct V_1 * V_1 , T_3 V_100 )
{
T_3 V_101 ;
int V_26 ;
if ( V_1 -> V_2 . V_88 == V_100 )
return 0 ;
V_101 = V_1 -> V_2 . V_88 ;
V_1 -> V_2 . V_88 = V_100 ;
V_26 = F_21 ( V_1 ) ;
if ( V_26 < 0 ) {
V_1 -> V_2 . V_88 = V_101 ;
return V_26 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_1 , T_3 * V_87 )
{
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_87 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
* V_87 = V_1 -> V_2 . V_96 ;
return 0 ;
}
int F_24 ( struct V_1 * V_1 , T_3 V_102 )
{
T_3 V_101 ;
int V_26 ;
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_102 != V_97 &&
V_102 != V_103 ) {
F_4 ( L_12 ) ;
return - V_30 ;
}
if ( V_1 -> V_2 . V_96 == V_102 )
return 0 ;
V_101 = V_1 -> V_2 . V_96 ;
V_1 -> V_2 . V_96 = V_102 ;
V_26 = F_21 ( V_1 ) ;
if ( V_26 < 0 ) {
V_1 -> V_2 . V_96 = V_101 ;
return V_26 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_1 , T_2 * V_104 )
{
T_2 V_105 ;
T_1 V_25 ;
int V_26 ;
if ( V_104 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
V_26 = F_5 ( V_1 , V_106 , V_39 , NULL , 2 ,
& V_105 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_104 = F_9 ( V_105 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_1 , short V_107 )
{
T_2 V_21 ;
int V_26 ;
if ( V_107 < V_108 ||
V_107 > V_109 ) {
F_4 ( L_13 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_107 ;
V_26 = F_5 ( V_1 , V_110 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_111 = V_107 ;
return 0 ;
}
int F_27 ( struct V_1 * V_1 , short * V_112 )
{
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_112 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
* V_112 = V_1 -> V_2 . V_111 ;
return 0 ;
}
int F_28 ( struct V_1 * V_1 , T_2 V_113 )
{
T_2 V_21 ;
int V_26 ;
if ( V_113 != V_114 && V_113 != V_115 ) {
F_4 ( L_14 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_113 ;
V_26 = F_5 ( V_1 , V_116 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_117 ;
V_26 = F_5 ( V_1 , V_118 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
}
int F_29 ( struct V_1 * V_1 , T_2 * V_113 )
{
T_2 V_119 ;
T_1 V_25 ;
int V_26 ;
if ( V_113 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
V_26 = F_5 ( V_1 , V_116 , V_39 , NULL , 2 ,
& V_119 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_113 = F_9 ( V_119 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_1 , T_2 V_113 )
{
T_2 V_21 ;
int V_26 ;
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_113 != V_120 &&
V_113 != V_121 ) {
F_4 ( L_15 , V_113 ) ;
return - V_30 ;
}
V_21 = V_113 ;
V_26 = F_5 ( V_1 , V_122 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_123 = V_113 ;
return 0 ;
}
int F_31 ( struct V_1 * V_1 , T_2 * V_124 )
{
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_124 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
* V_124 = V_1 -> V_2 . V_123 ;
return 0 ;
}
int F_32 ( struct V_1 * V_1 , T_3 V_125 )
{
T_2 V_21 ;
int V_26 ;
if ( V_125 != V_126 && V_125 != V_5 ) {
F_4 ( L_16 ) ;
return - V_30 ;
}
if ( V_125 == V_126
&& V_1 -> V_2 . V_3 . V_4 == V_5 ) {
V_21 = V_127 ;
V_26 = F_5 ( V_1 , V_128 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_129 ;
V_26 = F_5 ( V_1 , V_130 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_5 ( V_1 , V_38 , V_39 , NULL , 2 ,
NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_21 = V_131 ;
V_26 = F_5 ( V_1 , V_132 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_11 . V_12 |= V_133 ;
V_21 = V_1 -> V_11 . V_12 ;
V_26 = F_5 ( V_1 , V_42 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 ) {
V_1 -> V_11 . V_12 &= ~ V_133 ;
return V_26 ;
}
V_1 -> V_2 . V_3 . V_4 = V_126 ;
} else if ( V_125 == V_5
&& V_1 -> V_2 . V_3 . V_4 == V_126 ) {
V_21 = V_134 ;
V_26 = F_5 ( V_1 , V_128 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_3 . V_6 = 0 ;
V_1 -> V_2 . V_3 . V_7 = 0 ;
V_1 -> V_2 . V_3 . V_8 = 0 ;
F_2 ( V_1 ) ;
V_1 -> V_11 . V_12 &= ~ ( V_133 ) ;
V_1 -> V_2 . V_3 . V_4 = V_5 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_1 , T_3 * V_135 )
{
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_135 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
* V_135 = V_1 -> V_2 . V_3 . V_4 ;
return 0 ;
}
int F_34 ( struct V_1 * V_1 , T_3 V_136 )
{
T_2 V_21 ;
int V_26 ;
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_136 != V_137 && V_136 != V_138 ) {
F_4 ( L_17 ) ;
return - V_30 ;
}
V_21 = ( T_2 ) V_136 ;
V_26 = F_5 ( V_1 , V_139 , V_33 , & V_21 ,
sizeof( V_21 ) , NULL , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_1 -> V_2 . V_136 = V_136 ;
return 0 ;
}
int F_35 ( struct V_1 * V_1 , T_3 * V_136 )
{
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_136 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
* V_136 = V_1 -> V_2 . V_136 ;
return 0 ;
}
int F_36 ( struct V_1 * V_1 , T_3 V_9 )
{
T_2 V_21 ;
int V_26 ;
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_9 != V_10 &&
V_9 != V_140 ) {
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
if ( V_1 -> V_71 != V_72 )
return - V_73 ;
if ( V_9 == NULL ) {
F_4 ( L_7 ) ;
return - V_80 ;
}
* V_9 = V_1 -> V_2 . V_9 ;
return 0 ;
}
