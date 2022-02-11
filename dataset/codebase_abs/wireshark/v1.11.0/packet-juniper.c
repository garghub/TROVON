static int
F_1 ( T_1 * V_1 , T_2 V_2 , T_2 V_3 , T_2 V_4 ) {
int V_5 ;
if ( V_2 < 128 ) {
switch ( V_3 ) {
case 1 :
V_5 = F_2 ( V_1 , V_4 ) ;
break;
case 2 :
V_5 = F_3 ( V_1 , V_4 ) ;
break;
case 3 :
V_5 = F_4 ( V_1 , V_4 ) ;
break;
case 4 :
V_5 = F_5 ( V_1 , V_4 ) ;
break;
default:
V_5 = - 1 ;
break;
}
} else {
switch ( V_3 ) {
case 1 :
V_5 = F_2 ( V_1 , V_4 ) ;
break;
case 2 :
V_5 = F_6 ( V_1 , V_4 ) ;
break;
case 3 :
V_5 = F_7 ( V_1 , V_4 ) ;
break;
case 4 :
V_5 = F_8 ( V_1 , V_4 ) ;
break;
default:
V_5 = - 1 ;
break;
}
}
return V_5 ;
}
static int
F_9 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 , T_5 * V_8 , T_6 * V_9 )
{
T_5 * V_10 ;
T_6 V_11 , V_12 , V_13 , V_14 ;
T_7 V_15 , V_16 = 6 , V_17 ;
T_8 V_18 , V_19 ;
T_4 * V_20 = NULL , * V_21 = NULL ;
V_18 = F_7 ( V_1 , 0 ) ;
* V_9 = F_2 ( V_1 , 3 ) ;
V_11 = * V_9 & V_22 ;
V_23 = F_10 ( V_8 , V_24 ) ;
if ( V_18 != V_25 ) {
F_11 ( V_23 , V_1 , 0 , 0 , L_1 ) ;
return 0 ;
}
F_11 ( V_23 , V_1 , 0 , 3 ,
L_2 , V_18 ) ;
F_12 ( V_23 , V_26 , V_1 , 3 , 1 , V_27 ) ;
F_13 ( V_23 , V_28 , V_1 , 3 , 1 ,
V_11 , L_3 ,
F_14 ( V_11 , V_29 , L_4 ) ) ;
if ( ( * V_9 & V_30 ) == V_30 ) {
V_15 = F_6 ( V_1 , 4 ) ;
V_17 = 6 + V_15 ;
V_10 = F_15 ( V_23 , V_31 , V_1 , 4 , 2 , V_15 ) ;
V_20 = F_10 ( V_10 , V_24 ) ;
while ( V_15 > V_32 ) {
V_13 = F_2 ( V_1 , V_16 ) ;
V_14 = F_2 ( V_1 , V_16 + 1 ) ;
if ( V_14 == 0 || V_14 > ( V_15 - V_32 ) )
break;
V_10 = F_11 ( V_20 , V_1 , V_16 , V_32 + V_14 ,
L_5 ,
F_14 ( V_13 , V_33 , L_4 ) ,
V_13 ,
V_14 ) ;
V_19 = F_1 ( V_1 , V_13 , V_14 , V_16 + V_32 ) ;
V_21 = F_10 ( V_10 , V_24 ) ;
switch ( V_13 ) {
case V_34 :
F_15 ( V_21 , V_35 ,
V_1 , V_16 + V_32 , V_14 , V_19 ) ;
break;
case V_36 :
F_15 ( V_21 , V_37 ,
V_1 , V_16 + V_32 , V_14 , V_19 ) ;
break;
case V_38 :
F_15 ( V_21 , V_39 ,
V_1 , V_16 + V_32 , V_14 , V_19 ) ;
break;
case V_40 :
F_15 ( V_21 , V_41 ,
V_1 , V_16 + V_32 , V_14 , V_19 ) ;
break;
case V_42 :
F_15 ( V_21 , V_43 ,
V_1 , V_16 + V_32 , V_14 , V_19 ) ;
break;
case V_44 :
F_15 ( V_21 , V_45 ,
V_1 , V_16 + V_32 , V_14 , V_19 ) ;
break;
case V_46 :
F_15 ( V_21 , V_47 ,
V_1 , V_16 + V_32 , V_14 , V_19 ) ;
break;
case V_48 :
default:
F_16 ( V_10 , L_4 ) ;
break;
}
V_16 += V_32 + V_14 ;
V_15 -= V_32 + V_14 ;
}
} else
V_17 = 4 ;
if ( ( * V_9 & V_22 ) == V_22 ) {
V_12 = F_5 ( V_1 , V_17 ) ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_12 , V_17 + 4 ) ;
return - 1 ;
}
return V_17 ;
}
static int
F_17 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 ,
T_5 * V_8 V_49 , T_2 V_12 , T_2 V_4 )
{
T_1 * V_50 ;
T_6 V_51 ;
F_11 ( V_23 , V_1 , V_4 , 0 , L_6 ,
F_14 ( V_12 , V_52 , L_4 ) ) ;
V_50 = F_18 ( V_1 , V_4 ) ;
switch ( V_12 ) {
case V_53 :
case V_54 :
F_19 ( V_55 , V_50 , V_6 , V_7 ) ;
break;
case V_56 :
case V_57 :
F_19 ( V_58 , V_50 , V_6 , V_7 ) ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
F_19 ( V_63 , V_50 , V_6 , V_7 ) ;
break;
case V_64 :
F_19 ( V_65 , V_50 , V_6 , V_7 ) ;
break;
case V_66 :
F_19 ( V_67 , V_50 , V_6 , V_7 ) ;
break;
case V_68 :
case V_69 :
F_19 ( V_70 , V_50 , V_6 , V_7 ) ;
break;
case V_71 :
case V_72 :
case V_73 :
V_51 = F_2 ( V_1 , V_4 ) ;
if( F_20 ( V_74 , V_51 , V_50 , V_6 , V_7 ) )
return 0 ;
V_50 = F_18 ( V_1 , V_4 + 1 ) ;
if( F_20 ( V_75 , V_51 , V_50 , V_6 , V_7 ) )
return 0 ;
break;
case V_76 :
F_19 ( V_77 , V_50 , V_6 , V_7 ) ;
break;
case V_78 :
F_19 ( V_79 , V_50 , V_6 , V_7 ) ;
break;
case V_80 :
F_19 ( V_81 , V_50 , V_6 , V_7 ) ;
break;
case 0xa248 :
F_11 ( V_23 , V_1 , V_4 , 4 , L_7 ) ;
V_50 = F_18 ( V_1 , V_4 + 4 ) ;
F_19 ( V_55 , V_50 , V_6 , V_7 ) ;
break;
case V_82 :
default:
F_19 ( V_83 , V_50 , V_6 , V_7 ) ;
break;
}
return 0 ;
}
static void
F_21 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
T_5 * V_8 ;
T_2 V_4 ;
int V_84 ;
T_6 V_9 ;
T_9 V_85 ;
T_8 V_86 ;
T_7 V_87 ;
T_2 V_12 , V_88 ;
F_22 ( V_6 -> V_89 , V_90 , L_8 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_4 = 0 ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_9 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
V_85 = F_24 ( V_1 , V_4 ) ;
V_12 = F_25 ( V_85 , V_92 , V_9 ) ;
V_88 = F_26 ( V_85 ) ;
if ( V_88 == V_93 )
F_27 ( V_23 , V_94 ,
V_1 , V_4 , V_93 , V_85 ) ;
if ( V_88 == V_95 ) {
V_86 = F_8 ( V_1 , V_4 ) ;
F_15 ( V_23 , V_96 ,
V_1 , V_4 , V_95 , V_86 ) ;
}
V_4 += V_88 ;
V_87 = F_6 ( V_1 , V_4 ) ;
if ( V_88 == V_93 &&
V_12 == V_97 &&
F_2 ( V_1 , V_4 ) == V_98 ) {
V_4 += 1 ;
V_12 = V_71 ;
}
if ( V_88 == V_95 ) {
if ( F_6 ( V_1 , V_4 ) == V_98 ||
F_6 ( V_1 , V_4 ) == ( V_98 << 8 ) ) {
V_4 += 2 ;
}
}
if ( V_88 == V_95 && F_2 ( V_1 , V_4 ) == V_98 ) {
V_4 += 1 ;
}
if ( V_88 == 0 && F_6 ( V_1 , V_4 + V_99 ) ==
( V_98 << 8 | V_100 ) ) {
V_88 = V_99 ;
F_15 ( V_23 , V_101 ,
V_1 , V_4 , V_99 , V_87 ) ;
V_4 += 3 ;
V_12 = V_76 ;
}
if ( V_88 == 0 ) {
if ( F_6 ( V_1 , V_4 + V_99 ) == V_98 ||
F_6 ( V_1 , V_4 + V_99 ) == ( V_98 << 8 ) ) {
V_88 = V_99 ;
F_15 ( V_23 , V_101 ,
V_1 , V_4 , V_99 , V_87 ) ;
V_4 += 4 ;
V_12 = V_71 ;
}
}
if ( V_88 == 0 && F_2 ( V_1 , V_4 + V_99 ) == V_98 ) {
V_88 = V_99 ;
F_15 ( V_23 , V_101 ,
V_1 , V_4 , V_99 , V_87 ) ;
V_4 += 3 ;
V_12 = V_71 ;
}
V_8 = F_11 ( V_23 , V_1 , V_4 , 0 , L_10 , V_88 ) ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_12 , V_4 ) ;
}
static void
F_28 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
T_5 * V_8 ;
T_2 V_4 ;
int V_84 ;
T_6 V_9 ;
T_9 V_85 ;
T_8 V_86 ;
T_7 V_87 ;
T_2 V_12 , V_88 ;
F_22 ( V_6 -> V_89 , V_90 , L_11 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_4 = 0 ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_11 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
V_85 = F_24 ( V_1 , V_4 ) ;
V_12 = F_25 ( V_85 , V_102 , V_9 ) ;
V_88 = F_26 ( V_85 ) ;
if ( V_88 == V_93 )
F_27 ( V_23 , V_94 ,
V_1 , V_4 , V_93 , V_85 ) ;
if ( V_88 == V_95 ) {
V_86 = F_8 ( V_1 , V_4 ) ;
F_15 ( V_23 , V_96 ,
V_1 , V_4 , V_95 , V_86 ) ;
}
if ( V_88 == 0 && F_6 ( V_1 , V_4 ) == V_103 ) {
V_12 = V_64 ;
V_4 += 2 ;
}
if ( V_88 == 0 && F_29 ( F_6 ( V_1 , V_4 + 2 ) ) ) {
V_12 = V_64 ;
V_88 = 2 ;
V_87 = F_6 ( V_1 , V_4 ) ;
F_15 ( V_23 , V_101 ,
V_1 , V_4 , V_99 , V_87 ) ;
}
if ( V_88 == 0 && F_29 ( F_6 ( V_1 , V_4 ) ) ) {
V_12 = V_64 ;
}
V_8 = F_11 ( V_23 , V_1 , V_4 , 0 , L_10 , V_88 ) ;
V_4 += V_88 ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_12 , V_4 ) ;
}
static void
F_30 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
T_5 * V_8 ;
T_2 V_4 ;
int V_84 ;
T_6 V_9 ;
F_22 ( V_6 -> V_89 , V_90 , L_12 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_4 = 0 ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_13 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_66 , V_4 ) ;
}
static void
F_31 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
T_5 * V_8 ;
T_2 V_4 ;
int V_84 ;
T_6 V_9 ;
F_22 ( V_6 -> V_89 , V_90 , L_14 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_4 = 0 ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_14 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_66 , V_4 ) ;
}
static void
F_32 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
T_5 * V_8 ;
T_2 V_4 ;
int V_84 ;
T_6 V_9 ;
F_22 ( V_6 -> V_89 , V_90 , L_15 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_4 = 0 ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_15 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_64 , V_4 + 2 ) ;
}
static void
F_33 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
T_5 * V_8 ;
T_2 V_4 ;
int V_84 ;
T_6 V_9 ;
F_22 ( V_6 -> V_89 , V_90 , L_16 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_4 = 0 ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_16 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_78 , V_4 ) ;
}
static void
F_34 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
T_5 * V_8 ;
T_2 V_4 = 0 ;
int V_84 ;
T_6 V_9 ;
F_22 ( V_6 -> V_89 , V_90 , L_17 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_17 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_80 , V_4 ) ;
}
static void
F_35 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
F_36 ( V_1 , V_6 , V_7 , V_104 ) ;
}
static void
F_37 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
F_36 ( V_1 , V_6 , V_7 , V_105 ) ;
}
static void
F_36 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 , T_7 V_106 )
{
T_5 * V_8 ;
T_6 V_107 = V_97 , V_108 , V_109 , V_9 ;
T_8 V_110 , V_12 ;
T_9 V_111 ;
T_2 V_4 = 0 ;
int V_84 ;
T_1 * V_50 ;
F_23 ( V_6 -> V_89 , V_91 ) ;
switch ( V_106 ) {
case V_104 :
F_22 ( V_6 -> V_89 , V_90 , L_18 ) ;
V_8 = F_11 ( V_7 , V_1 , 0 , 0 , L_19 ) ;
break;
case V_105 :
F_22 ( V_6 -> V_89 , V_90 , L_20 ) ;
V_8 = F_11 ( V_7 , V_1 , 0 , 0 , L_21 ) ;
break;
default:
F_22 ( V_6 -> V_89 , V_90 , L_22 ) ;
F_11 ( V_7 , V_1 , 0 , 0 , L_23 ) ;
return;
}
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
if ( ( V_9 & V_22 ) == V_22 ) {
V_108 = 4 ;
V_109 = 4 ;
}
else {
V_108 = 4 ;
V_109 = 8 ;
}
V_110 = F_8 ( V_1 , V_4 ) ;
V_111 = F_24 ( V_1 , V_4 ) ;
if ( V_106 == V_104 ) {
F_15 ( V_23 , V_112 , V_1 , V_4 , 4 , V_110 ) ;
V_4 += V_108 ;
if ( ( V_110 >> 24 ) == 0x80 )
V_107 = V_82 ;
}
else {
F_27 ( V_23 , V_113 , V_1 , V_4 , 8 , V_111 ) ;
V_4 += V_109 ;
if ( V_111 & 0x70 )
V_107 = V_82 ;
}
V_50 = F_18 ( V_1 , V_4 ) ;
if ( V_107 == V_82 ) {
F_17 ( V_1 , V_6 , V_7 , V_8 , V_82 , V_4 ) ;
return;
}
V_12 = F_7 ( V_1 , V_4 ) ;
if ( V_12 == V_114 ) {
F_17 ( V_1 , V_6 , V_7 , V_8 , V_68 , V_4 ) ;
return;
}
if ( V_12 == V_115 ) {
F_17 ( V_1 , V_6 , V_7 , V_8 , V_69 , V_4 ) ;
return;
}
if ( ( V_9 & V_116 ) != V_116 &&
( V_110 & V_117 ) &&
V_106 != V_104 ) {
F_17 ( V_1 , V_6 , V_7 , V_8 , V_66 , V_4 ) ;
return;
}
V_12 = F_6 ( V_1 , V_4 ) ;
if ( F_29 ( ( T_7 ) V_12 ) &&
V_106 != V_104 ) {
V_8 = F_11 ( V_23 , V_1 , V_4 , 0 , L_24 ) ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_64 , V_4 ) ;
return;
}
V_12 = F_2 ( V_1 , V_4 ) ;
if ( V_12 == V_98 ) {
V_8 = F_11 ( V_23 , V_1 , V_4 , 1 , L_25 ) ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_71 , V_4 + 1 ) ;
return;
}
V_107 = F_38 ( ( T_6 ) V_12 ) ;
if ( V_107 != V_97 ) {
V_8 = F_11 ( V_23 , V_1 , V_4 , 0 , L_24 ) ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_107 , V_4 ) ;
return;
}
F_11 ( V_23 , V_1 , V_4 , - 1 , L_26 ) ;
F_19 ( V_83 , V_50 , V_6 , V_7 ) ;
}
static void F_39 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 ) {
T_5 * V_8 ;
T_2 V_4 = 0 ;
int V_84 ;
T_6 V_9 ;
T_7 V_12 ;
F_22 ( V_6 -> V_89 , V_90 , L_27 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_27 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
V_12 = F_3 ( V_1 , V_4 ) ;
F_15 ( V_23 , V_118 , V_1 , V_4 , 2 , V_12 ) ;
F_12 ( V_23 , V_119 , V_1 , V_4 + 2 , 2 , V_120 ) ;
V_4 += 4 ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_12 , V_4 ) ;
}
static void F_40 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 ) {
T_5 * V_8 ;
T_2 V_4 = 0 ;
int V_84 ;
T_6 V_9 ;
F_22 ( V_6 -> V_89 , V_90 , L_28 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_8 = F_11 ( V_7 , V_1 , V_4 , 4 , L_28 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if( V_84 == - 1 )
return;
else
V_4 += V_84 ;
F_17 ( V_1 , V_6 , V_7 , V_8 , V_53 , V_4 + 18 ) ;
}
static void
F_41 ( T_1 * V_1 , T_3 * V_6 , T_4 * V_7 )
{
T_5 * V_8 ;
T_2 V_4 = 0 ;
int V_84 = 0 ;
T_6 V_9 ;
F_22 ( V_6 -> V_89 , V_90 , L_29 ) ;
F_23 ( V_6 -> V_89 , V_91 ) ;
V_8 = F_11 ( V_7 , V_1 , 0 , 4 , L_30 ) ;
V_84 = F_9 ( V_1 , V_6 , V_7 , V_8 , & V_9 ) ;
if ( V_84 == - 1 )
return;
else
V_4 += V_84 ;
if ( V_9 & V_116 ) {
F_15 ( V_23 , V_118 , V_1 , V_4 , 2 , V_53 ) ;
V_4 += 16 ;
} else {
V_4 += 12 ;
}
F_17 ( V_1 , V_6 , V_7 , V_8 , V_53 , V_4 ) ;
}
static T_10
F_29 ( T_7 V_12 ) {
switch( V_12 ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
return TRUE ;
default:
return FALSE ;
}
}
static T_2
F_38 ( T_6 V_134 ) {
switch( V_134 ) {
case 0x45 :
case 0x46 :
case 0x47 :
case 0x48 :
case 0x49 :
case 0x4a :
case 0x4b :
case 0x4c :
case 0x4d :
case 0x4e :
case 0x4f :
return V_53 ;
case 0x60 :
case 0x61 :
case 0x62 :
case 0x63 :
case 0x64 :
case 0x65 :
case 0x66 :
case 0x67 :
case 0x68 :
case 0x69 :
case 0x6a :
case 0x6b :
case 0x6c :
case 0x6d :
case 0x6e :
case 0x6f :
return V_56 ;
default:
return V_97 ;
}
}
static
T_2 F_26 ( T_9 V_135 ) {
T_6 V_136 ;
V_136 = ( T_6 ) ( V_135 >> 56 ) & 0xff ;
switch( V_136 ) {
case 0x54 :
return V_95 ;
case V_137 :
case V_138 :
return V_93 ;
default:
return 0 ;
}
}
static T_2
F_25 ( T_9 V_135 , T_7 V_139 , T_6 V_9 ) {
T_6 V_136 ;
T_7 V_140 ;
T_6 V_141 ;
V_136 = ( T_6 ) ( V_135 >> 56 ) & 0xff ;
V_140 = ( T_7 ) ( ( V_135 >> 16 ) & V_142 ) ;
V_141 = ( T_6 ) ( V_135 >> 24 ) & 0x3 ;
switch ( V_136 ) {
case 0x54 :
switch ( V_139 ) {
case V_102 :
return V_64 ;
case V_92 :
return V_71 ;
default:
return V_97 ;
}
case V_137 :
case V_138 :
switch( V_140 ) {
case V_143 :
switch( V_139 ) {
case V_102 :
if ( ( V_9 & V_116 ) == V_116 &&
V_141 != ( V_144 | V_145 ) )
return V_64 ;
else
return V_53 ;
case V_92 :
if ( V_141 == ( V_144 | V_145 ) )
return V_97 ;
else
return V_53 ;
default:
return V_97 ;
}
case V_146 :
return V_56 ;
case V_147 :
return V_59 ;
case V_148 :
return V_71 ;
default:
return V_97 ;
}
default:
return V_97 ;
}
}
void
F_42 ( void )
{
static T_11 V_149 [] = {
#if 0
{ &hf_juniper_magic,
{ "Magic Number", "juniper.magic-number", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
#endif
{ & V_26 ,
{ L_31 , L_32 , V_150 , V_151 ,
F_43 ( V_152 ) , 0x0 , NULL , V_153 } } ,
{ & V_28 ,
{ L_33 , L_34 , V_150 , V_151 ,
F_43 ( V_29 ) , 0x0 , NULL , V_153 } } ,
{ & V_31 ,
{ L_35 , L_36 , V_154 , V_155 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_113 ,
{ L_37 , L_38 , V_156 , V_151 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_112 ,
{ L_37 , L_39 , V_157 , V_151 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_101 ,
{ L_37 , L_40 , V_154 , V_151 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_96 ,
{ L_37 , L_41 , V_157 , V_151 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_94 ,
{ L_37 , L_42 , V_156 , V_151 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_119 ,
{ L_43 , L_44 , V_154 , V_155 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_118 ,
{ L_45 , L_46 , V_154 , V_155 ,
F_43 ( V_52 ) , 0x0 , NULL , V_153 } } ,
{ & V_47 ,
{ L_47 , L_48 , V_157 , V_155 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_43 ,
{ L_49 , L_50 , V_157 , V_155 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_45 ,
{ L_51 , L_52 , V_157 , V_155 ,
NULL , 0x0 , NULL , V_153 } } ,
{ & V_35 ,
{ L_53 , L_54 , V_154 , V_155 ,
F_43 ( V_158 ) , 0x0 , NULL , V_153 } } ,
{ & V_39 ,
{ L_55 , L_56 , V_154 , V_155 ,
F_43 ( V_159 ) , 0x0 , NULL , V_153 } } ,
{ & V_37 ,
{ L_57 , L_58 , V_154 , V_155 ,
F_43 ( V_158 ) , 0x0 , NULL , V_153 } } ,
{ & V_41 ,
{ L_59 , L_60 , V_154 , V_155 ,
F_43 ( V_159 ) , 0x0 , NULL , V_153 } } ,
} ;
static T_12 * V_160 [] = {
& V_24 ,
} ;
V_161 = F_44 ( L_61 , L_61 , L_62 ) ;
F_45 ( V_161 , V_149 , F_46 ( V_149 ) ) ;
F_47 ( V_160 , F_46 ( V_160 ) ) ;
}
void
F_48 ( void )
{
T_13 V_162 ;
T_13 V_163 ;
T_13 V_164 ;
T_13 V_165 ;
T_13 V_166 ;
T_13 V_167 ;
T_13 V_168 ;
T_13 V_169 ;
T_13 V_170 ;
T_13 V_171 ;
T_13 V_172 ;
T_13 V_173 ;
V_74 = F_49 ( L_63 ) ;
V_75 = F_49 ( L_64 ) ;
V_67 = F_50 ( L_65 ) ;
V_65 = F_50 ( L_66 ) ;
V_70 = F_50 ( L_67 ) ;
V_55 = F_50 ( L_68 ) ;
V_58 = F_50 ( L_69 ) ;
V_63 = F_50 ( L_70 ) ;
V_77 = F_50 ( L_71 ) ;
V_79 = F_50 ( L_72 ) ;
V_81 = F_50 ( L_73 ) ;
V_83 = F_50 ( L_74 ) ;
V_163 = F_51 ( F_37 , V_161 ) ;
V_162 = F_51 ( F_35 , V_161 ) ;
V_164 = F_51 ( F_30 , V_161 ) ;
V_165 = F_51 ( F_28 , V_161 ) ;
V_166 = F_51 ( F_21 , V_161 ) ;
V_167 = F_51 ( F_31 , V_161 ) ;
V_168 = F_51 ( F_32 , V_161 ) ;
V_169 = F_51 ( F_33 , V_161 ) ;
V_170 = F_51 ( F_34 , V_161 ) ;
V_171 = F_51 ( F_39 , V_161 ) ;
V_172 = F_51 ( F_40 , V_161 ) ;
V_173 = F_51 ( F_41 , V_161 ) ;
F_52 ( L_75 , V_174 , V_163 ) ;
F_52 ( L_75 , V_175 , V_162 ) ;
F_52 ( L_75 , V_176 , V_164 ) ;
F_52 ( L_75 , V_177 , V_165 ) ;
F_52 ( L_75 , V_178 , V_166 ) ;
F_52 ( L_75 , V_179 , V_167 ) ;
F_52 ( L_75 , V_180 , V_168 ) ;
F_52 ( L_75 , V_181 , V_169 ) ;
F_52 ( L_75 , V_182 , V_170 ) ;
F_52 ( L_75 , V_183 , V_171 ) ;
F_52 ( L_75 , V_184 , V_172 ) ;
F_52 ( L_75 , V_185 , V_173 ) ;
}
