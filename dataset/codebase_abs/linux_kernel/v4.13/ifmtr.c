unsigned int F_1 (
const struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
if ( ( V_3 == V_2 -> V_4 . V_5 )
|| ( V_6 == V_2 -> V_4 . V_5 ) )
return 1 ;
return 0 ;
}
unsigned int F_2 (
const struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
if ( ( V_7 == V_2 -> V_4 . V_5 )
|| ( V_6 == V_2 -> V_4 . V_5 ) )
return 1 ;
return 0 ;
}
enum V_8 F_3 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned int V_11 , V_12 = 0 ,
V_13 ,
V_14 ,
V_15 ,
V_16 = 2 ,
V_17 ,
V_18 ,
V_19 = 0 ,
V_20 = 0 ,
V_21 = 0 ,
V_22 = 0 ,
V_23 = 0 ,
V_24 ,
V_25 ,
V_26 = 0 ,
V_27 = 0 ,
V_28 = 0 ,
V_29 = 0 ,
V_30 = 0 ,
V_31 = 1 , V_32 ,
V_33 = 0 ;
T_1 V_34 , V_35 ;
enum V_36 V_37 ;
enum V_8 V_38 = V_39 ;
T_2 V_40 ;
enum V_41 V_42 ;
if ( V_10 ) {
V_13 = V_10 -> V_43 . V_44 . V_45 ;
V_14 = V_10 -> V_43 . V_44 . V_46 ;
if ( V_10 -> V_47 -> V_48 . V_49 . V_50 && V_10 -> V_47 -> V_48 . V_51 . V_52 != V_53 )
V_17 = V_54 * V_55 ;
else
V_17 = V_10 -> V_47 -> V_48 . V_56 . V_57 ;
V_37 = V_10 -> V_37 ;
} else {
V_13 = V_2 -> V_4 . V_58 . V_45 ;
V_14 = V_2 -> V_4 . V_58 . V_46 ;
V_17 = V_54 * V_55 ;
V_37 = V_2 -> V_4 . V_59 ;
}
V_18 = V_2 -> V_60 == 2 ;
if ( V_2 -> V_52 == V_61
|| V_2 -> V_52 == V_62 ) {
V_42 = V_2 -> V_63 . V_42 . V_42 ;
V_40 = ( T_2 ) ( V_42 - V_64 ) ;
} else if ( V_2 -> V_52 == V_65 ) {
V_40 = V_66 ;
} else {
V_40 = 0 ;
}
assert ( V_40 <= V_67
|| V_40 == V_66 ) ;
V_38 = F_4 ( V_2 , V_13 , & V_11 ) ;
if ( V_38 != V_39 )
return V_38 ;
V_38 = F_5 ( V_2 , V_14 , & V_12 ) ;
if ( V_38 != V_39 )
return V_38 ;
if ( V_2 -> V_33 == - 1 )
if ( ! V_10 )
V_33 = 0 ;
else
V_33 = V_10 -> V_33 ;
else
V_33 = 2 * V_55 - V_2 -> V_33 ;
if ( V_33 ) {
V_15 = F_6 ( V_14 + V_33 ,
V_55 ) ;
} else {
V_15 = F_6 ( V_14 , V_55 ) ;
V_15 *= V_16 ;
}
V_32 = V_12 ;
V_24 = F_7 ( V_68 )
* 8 / V_55 ;
switch ( V_37 ) {
case V_69 :
if ( V_18 ) {
V_19 = 1 ;
V_20 = 1 ;
V_21 = 1 ;
V_22 = V_14 * V_20 / 2 ;
V_31 = 2 ;
V_23 = V_22 * V_31 ;
V_17 *= V_20 * 2 ;
V_15 *= V_20 ;
V_29 = V_17 / 2 / V_55 ;
V_26 = V_15 / V_16 ;
V_30 = V_26 *
F_7 ( V_68 ) /
2 ;
V_12 /= 2 ;
} else {
V_19 = 1 ;
V_20 = 3 ;
V_22 = V_14 * V_20 / 2 ;
V_17 = V_17 * V_20 / 2 ;
V_15 = V_15 / 2 * V_20 ;
V_12 = V_12 * V_20 / 2 ;
}
break;
case V_70 :
case V_71 :
case V_72 :
if ( V_18 ) {
V_19 = 1 ;
V_20 = 1 ;
V_22 = V_23 = V_14 * V_20 / 2 ;
V_17 *= V_20 * 2 ;
V_15 *= V_20 ;
V_29 = V_17 / 2 / V_55 ;
V_26 = V_15 / V_16 ;
V_30 = V_26 *
F_7 ( V_68 ) /
2 ;
V_12 *= V_20 ;
V_12 /= 2 ;
V_32 = V_12 ;
} else {
V_19 = 1 ;
V_20 = 1 ;
V_22 = V_14 * V_20 ;
V_17 *= V_20 * 2 ;
V_15 *= V_20 ;
V_12 *= V_20 ;
}
break;
case V_73 :
case V_74 :
case V_75 :
if ( V_18 ) {
V_19 = 1 ;
V_20 = 1 ;
V_22 = V_23 = V_14 * V_20 ;
V_17 *= V_20 * 2 ;
V_15 *= V_20 ;
V_12 *= V_20 ;
V_29 = V_17 / 2 / V_55 ;
V_32 = V_12 ;
} else {
V_19 = 1 ;
V_20 = 2 ;
V_22 = V_14 * V_20 ;
V_17 *= V_20 ;
V_15 *= V_20 ;
V_12 *= V_20 ;
}
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_15 *= 2 ;
if ( V_18 ) {
V_20 = 2 ;
V_21 = 1 ;
V_27 = 4 ;
V_32 = V_12 ;
V_12 *= V_20 ;
V_32 *= V_21 ;
} else {
V_20 = 3 ;
V_27 = 3 ;
V_12 *= V_20 ;
}
V_19 = 1 ;
V_22 = V_14 * V_20 ;
V_23 = V_14 * V_21 ;
V_17 *= V_27 ;
V_15 = V_15 / 2 * V_20 ;
V_29 = V_17 / 2 / V_55 ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
if ( V_18 ) {
int V_86 = ( V_12 % 2 ) == 1 ;
V_19 = 2 ;
V_20 = 1 ;
V_22 = V_23 = V_14 / 2 ;
V_28 = V_86 ? 1 : 0 ;
V_29 = V_86 ? 0 : 1 ;
V_32 = V_12 / 2 ;
V_12 = V_12 / 2 + V_86 ;
} else {
V_19 = 1 ;
V_20 = 2 ;
if ( ( ! V_10 ) || ( V_2 -> V_50 && V_10
&& V_10 -> V_47 -> V_48 . V_51 . V_52 == V_53 ) ) {
V_20 = 1 ;
}
V_22 = V_14 ;
V_15 = F_8 ( V_15 , V_20 ) ;
}
V_16 *= 2 ;
if ( ( ! V_10 ) || V_2 -> V_50 )
V_16 *= 2 ;
V_26 = F_6 ( V_14 , V_55 ) ;
V_26 = F_8 ( V_26 , V_20 ) ;
break;
case V_87 :
case V_88 :
if ( V_18 ) {
V_15 *= 2 ;
V_19 = 1 ;
V_20 = 2 ;
V_22 = V_23 = V_14 ;
V_29 = V_17 / V_55 ;
V_24 *= 2 ;
} else {
V_19 = 1 ;
V_20 = 2 ;
V_22 = V_14 ;
V_12 /= V_20 ;
}
V_16 *= 2 ;
break;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
break;
}
if ( V_22 == 0 )
return V_109 ;
if ( V_18 )
V_33 /= 2 ;
if ( V_33 )
V_26 = V_15 ;
if ( ! V_26 ) {
V_26 = F_8 ( V_15 / V_16 ,
V_20 ) ;
V_30 = 0 ;
}
if ( ! V_30 )
V_30 = V_26 *
F_7 ( V_68 ) ;
if ( ! V_27 )
V_27 = V_20 ;
V_30 = F_8 ( V_30 ,
F_7 ( V_68 )
* V_19 ) ;
V_25 = V_16 * V_17 / V_55 ;
if ( V_2 -> V_52 == V_110 &&
( ( V_10 && V_10 -> V_47 -> V_48 . V_51 . V_52 == V_111 ) ||
( ! V_10 ) ) ) {
V_11 = 0 ;
V_12 = 0 ;
V_13 -= V_11 ;
V_22 -= V_12 ;
}
V_34 . V_11 = V_11 ;
V_34 . V_12 = V_12 ;
V_34 . V_33 = V_33 / V_20 ;
V_34 . V_13 = V_13 ;
V_34 . V_14 = V_22 ;
V_34 . V_20 = V_20 ;
V_34 . V_112 = V_25 ;
V_34 . V_113 = V_28 ;
V_34 . V_114 = V_19 ;
V_34 . V_115 =
V_17 * V_24 / 8 - V_30 ;
V_34 . V_116 =
( V_37 == V_70 )
|| ( V_37 == V_71 )
|| ( V_37 == V_72 ) ;
V_34 . V_117 = ( V_2 -> V_52 != V_61 ) ;
if ( V_18 ) {
if ( V_21 ) {
V_20 = V_21 ;
V_23 = V_14 * V_20 ;
V_17 *= V_20 ;
V_15 = V_15 / 2 *
V_20 * V_31 ;
V_26 = V_15 / V_16 ;
V_30 = V_26 *
F_7 ( V_68 ) ;
}
V_35 . V_11 = V_11 ;
V_35 . V_12 = V_32 ;
V_35 . V_33 = V_33 / V_20 ;
V_35 . V_13 = V_13 ;
V_35 . V_14 = V_23 ;
V_35 . V_20 = V_20 ;
V_35 . V_112 = V_25 ;
V_35 . V_113 = V_29 ;
V_35 . V_114 = V_19 ;
V_35 . V_115 =
V_17 * V_24 / 8 - V_30 ;
V_35 . V_116 =
V_37 == V_70
|| V_37 == V_71
|| V_37 == V_72 ;
V_35 . V_117 =
( V_2 -> V_52 != V_61 ) ;
if ( V_66 != V_40 ) {
assert ( V_40 <= V_67 ) ;
F_9 ( & V_34 , & V_35 ) ;
F_10 ( & V_34 , & V_35 ,
V_40 ) ;
}
} else {
if ( V_66 != V_40 ) {
assert ( V_40 <= V_67 ) ;
F_9 ( & V_34 , NULL ) ;
F_10 ( & V_34 , NULL ,
V_40 ) ;
}
}
return V_39 ;
}
static void F_9 (
const T_1 * const V_118 ,
const T_1 * const V_119 )
{
int V_120 ;
bool V_121 [] = { false , false , false , false } ;
assert ( V_122 <= ( sizeof( V_121 ) / sizeof( V_121 [ 0 ] ) ) ) ;
#if ! F_11 ( V_123 )
#error "ifmtr_set_if_blocking_mode: ISP_SYSTEM must be one of {IS_ISP_2400_SYSTEM}"
#endif
V_121 [ V_68 ] = ( bool ) V_118 -> V_117 ;
if ( NULL != V_119 )
V_121 [ V_124 ] = ( bool ) V_119 -> V_117 ;
if ( V_125 ) {
V_125 = false ;
for ( V_120 = 0 ; V_120 < V_122 ; V_120 ++ ) {
T_3 V_126 = ( T_3 ) V_120 ;
F_12 ( V_126 ) ;
F_13 ( V_126 , V_121 [ V_126 ] ) ;
}
}
return;
}
static enum V_8 F_5 (
const struct V_1 * V_2 ,
unsigned int V_127 ,
unsigned int * V_12 )
{
unsigned int V_128 = V_2 -> V_4 . V_58 . V_46 , V_129 ,
V_130 = F_2 ( V_2 ) ;
if ( V_127 + 2 * V_130 > V_128 )
return V_109 ;
V_129 = ( V_128 - V_127 ) / 2 ;
V_129 &= ~ 0x1 ;
V_129 += V_130 ;
* V_12 = V_129 ;
return V_39 ;
}
static enum V_8 F_4 (
const struct V_1 * V_2 ,
unsigned int V_127 ,
unsigned int * V_11 )
{
unsigned int V_128 = V_2 -> V_4 . V_58 . V_45 , V_129 ,
V_130 = F_1 ( V_2 ) ;
if ( V_127 + 2 * V_130 > V_128 )
return V_109 ;
V_129 = ( V_128 - V_127 ) / 2 ;
V_129 &= ~ 0x1 ;
V_129 += V_130 ;
* V_11 = V_129 ;
return V_39 ;
}
