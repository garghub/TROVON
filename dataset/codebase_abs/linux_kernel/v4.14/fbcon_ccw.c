static void F_1 ( T_1 * V_1 , T_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
int V_6 , V_7 , V_8 = ( V_5 -> V_9 . V_10 < 10 ) ? 1 : 2 ;
int V_11 = ( V_5 -> V_9 . V_10 + 7 ) >> 3 ;
int V_12 = V_5 -> V_9 . V_10 % 8 ;
T_1 V_13 , V_14 = ~ ( 0xff << V_8 ) , V_15 = 0 ;
if ( V_12 )
V_14 <<= ( 8 - V_12 ) ;
if ( V_8 > V_12 )
V_15 |= 0x01 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_9 . V_11 ; V_6 ++ ) {
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_13 = * V_2 ;
if ( V_3 & V_16 ) {
if ( V_7 == V_11 - 1 )
V_13 |= V_14 ;
if ( V_15 && V_7 == V_11 - 2 )
V_13 |= V_15 ;
}
if ( V_3 & V_17 && V_6 )
* ( V_1 - V_11 ) |= V_13 ;
if ( V_3 & V_18 )
V_13 = ~ V_13 ;
V_2 ++ ;
* V_1 ++ = V_13 ;
}
}
}
static void F_2 ( struct V_4 * V_5 , struct V_19 * V_20 , int V_21 ,
int V_22 , int V_23 , int V_24 , int V_10 , int V_11 )
{
struct V_25 * V_26 = V_20 -> V_27 ;
struct V_28 V_29 ;
T_2 V_30 = F_3 ( V_26 -> V_31 -> V_32 , V_20 ) ;
V_29 . V_22 = V_21 * V_5 -> V_9 . V_10 ;
V_29 . V_21 = V_30 - ( ( V_22 + V_11 ) * V_5 -> V_9 . V_11 ) ;
V_29 . V_24 = V_23 * V_5 -> V_9 . V_10 ;
V_29 . V_23 = V_30 - ( ( V_24 + V_11 ) * V_5 -> V_9 . V_11 ) ;
V_29 . V_11 = V_10 * V_5 -> V_9 . V_10 ;
V_29 . V_10 = V_11 * V_5 -> V_9 . V_11 ;
V_20 -> V_33 -> V_28 ( V_20 , & V_29 ) ;
}
static void F_4 ( struct V_4 * V_5 , struct V_19 * V_20 , int V_21 ,
int V_22 , int V_10 , int V_11 )
{
struct V_25 * V_26 = V_20 -> V_27 ;
struct V_34 V_35 ;
int V_36 = ( V_5 -> V_37 ) ? 13 : 12 ;
T_2 V_30 = F_3 ( V_26 -> V_31 -> V_32 , V_20 ) ;
V_35 . V_38 = F_5 ( V_36 , V_5 , V_20 ) ;
V_35 . V_24 = V_21 * V_5 -> V_9 . V_10 ;
V_35 . V_23 = V_30 - ( ( V_22 + V_11 ) * V_5 -> V_9 . V_11 ) ;
V_35 . V_10 = V_11 * V_5 -> V_9 . V_11 ;
V_35 . V_11 = V_10 * V_5 -> V_9 . V_10 ;
V_35 . V_39 = V_40 ;
V_20 -> V_33 -> V_34 ( V_20 , & V_35 ) ;
}
static inline void F_6 ( struct V_4 * V_5 , struct V_19 * V_20 ,
const T_3 * V_41 , T_2 V_42 , T_2 V_43 ,
T_2 V_44 , T_2 V_45 , T_2 V_46 ,
struct V_47 * V_48 , T_1 * V_49 , T_1 * V_1 )
{
struct V_25 * V_26 = V_20 -> V_27 ;
T_3 V_50 = V_5 -> V_37 ? 0x1ff : 0xff ;
T_2 V_51 = ( V_5 -> V_9 . V_10 + 7 ) >> 3 ;
T_1 * V_2 ;
while ( V_43 -- ) {
V_2 = V_26 -> V_52 + ( F_7 ( V_41 -- ) & V_50 ) * V_46 ;
if ( V_42 ) {
F_1 ( V_49 , V_2 , V_42 , V_5 ) ;
V_2 = V_49 ;
}
if ( F_8 ( V_51 == 1 ) )
F_9 ( V_1 , V_44 , V_2 , V_51 ,
V_5 -> V_9 . V_11 ) ;
else
F_10 ( V_1 , V_44 , V_2 , V_51 ,
V_5 -> V_9 . V_11 ) ;
V_1 += V_44 * V_5 -> V_9 . V_11 ;
}
V_20 -> V_33 -> V_53 ( V_20 , V_48 ) ;
}
static void F_11 ( struct V_4 * V_5 , struct V_19 * V_20 ,
const unsigned short * V_41 , int V_54 , int V_55 , int V_56 ,
int V_57 , int V_58 )
{
struct V_47 V_48 ;
struct V_25 * V_26 = V_20 -> V_27 ;
T_2 V_11 = ( V_5 -> V_9 . V_10 + 7 ) / 8 ;
T_2 V_46 = V_11 * V_5 -> V_9 . V_11 ;
T_2 V_59 = V_20 -> V_60 . V_61 / V_46 ;
T_2 V_62 = V_20 -> V_60 . V_62 - 1 ;
T_2 V_63 = V_20 -> V_60 . V_63 - 1 ;
T_2 V_43 , V_64 , V_61 ;
T_2 V_3 = F_12 ( V_20 , F_7 ( V_41 ) ) ;
T_1 * V_1 , * V_49 = NULL ;
T_2 V_30 = F_3 ( V_26 -> V_31 -> V_32 , V_20 ) ;
if ( ! V_26 -> V_52 )
return;
V_48 . V_65 = V_57 ;
V_48 . V_66 = V_58 ;
V_48 . V_24 = V_55 * V_5 -> V_9 . V_10 ;
V_48 . V_23 = V_30 - ( ( V_56 + V_54 ) * V_5 -> V_9 . V_11 ) ;
V_48 . V_11 = V_5 -> V_9 . V_10 ;
V_48 . V_67 = 1 ;
if ( V_3 ) {
V_49 = F_13 ( V_46 , V_68 ) ;
if ( ! V_49 )
return;
}
V_41 += V_54 - 1 ;
while ( V_54 ) {
if ( V_54 > V_59 )
V_43 = V_59 ;
else
V_43 = V_54 ;
V_48 . V_10 = V_5 -> V_9 . V_11 * V_43 ;
V_64 = ( ( V_48 . V_11 + 7 ) >> 3 ) + V_62 ;
V_64 &= ~ V_62 ;
V_61 = V_64 * V_48 . V_10 + V_63 ;
V_61 &= ~ V_63 ;
V_1 = F_14 ( V_20 , & V_20 -> V_60 , V_61 ) ;
V_48 . V_69 = V_1 ;
F_6 ( V_5 , V_20 , V_41 , V_3 , V_43 , V_64 ,
V_11 , V_46 , & V_48 , V_49 , V_1 ) ;
V_48 . V_23 += V_48 . V_10 ;
V_54 -= V_43 ;
V_41 -= V_43 ;
}
if ( F_15 ( V_49 ) )
F_16 ( V_49 ) ;
}
static void F_17 ( struct V_4 * V_5 , struct V_19 * V_20 ,
int V_38 , int V_70 )
{
unsigned int V_71 = V_5 -> V_9 . V_11 ;
unsigned int V_72 = V_5 -> V_9 . V_10 ;
unsigned int V_73 = V_20 -> V_74 . V_75 - ( V_5 -> V_76 * V_71 ) ;
unsigned int V_77 = V_20 -> V_74 . V_78 - ( V_5 -> V_79 * V_72 ) ;
unsigned int V_80 = V_5 -> V_79 * V_72 ;
struct V_34 V_35 ;
V_35 . V_38 = V_38 ;
V_35 . V_39 = V_40 ;
if ( V_73 && ! V_70 ) {
V_35 . V_24 = 0 ;
V_35 . V_23 = V_20 -> V_74 . V_81 ;
V_35 . V_10 = V_73 ;
V_35 . V_11 = V_20 -> V_74 . V_82 ;
V_20 -> V_33 -> V_34 ( V_20 , & V_35 ) ;
}
if ( V_77 ) {
V_35 . V_24 = V_20 -> V_74 . V_83 + V_80 ;
V_35 . V_23 = 0 ;
V_35 . V_10 = V_20 -> V_74 . V_84 ;
V_35 . V_11 = V_77 ;
V_20 -> V_33 -> V_34 ( V_20 , & V_35 ) ;
}
}
static void F_18 ( struct V_4 * V_5 , struct V_19 * V_20 , int V_85 ,
int V_86 , int V_57 , int V_58 )
{
struct V_87 V_88 ;
struct V_25 * V_26 = V_20 -> V_27 ;
unsigned short V_50 = V_5 -> V_37 ? 0x1ff : 0xff ;
int V_89 = ( V_5 -> V_9 . V_10 + 7 ) >> 3 , V_13 ;
int V_90 = F_19 ( V_26 -> V_31 , V_5 -> V_91 ) ;
int V_3 , V_92 = ( V_5 -> V_93 & 0x10 ) ;
int V_94 = 1 , V_24 , V_23 ;
char * V_2 ;
T_2 V_30 = F_3 ( V_26 -> V_31 -> V_32 , V_20 ) ;
if ( ! V_26 -> V_52 )
return;
V_88 . V_95 = 0 ;
if ( V_86 ) {
if ( V_90 + V_86 >= V_5 -> V_79 ) {
V_85 = V_96 ;
V_26 -> V_97 = 0 ;
return;
} else
V_90 += V_86 ;
}
V_13 = F_7 ( ( T_3 * ) V_5 -> V_98 ) ;
V_3 = F_12 ( V_20 , V_13 ) ;
V_2 = V_26 -> V_52 + ( ( V_13 & V_50 ) * ( V_89 * V_5 -> V_9 . V_11 ) ) ;
if ( V_26 -> V_99 . V_48 . V_69 != V_2 ||
V_26 -> V_100 ) {
V_26 -> V_99 . V_48 . V_69 = V_2 ;
V_88 . V_95 |= V_101 ;
}
if ( V_3 ) {
T_1 * V_1 ;
V_1 = F_13 ( V_89 * V_5 -> V_9 . V_11 , V_102 ) ;
if ( ! V_1 )
return;
F_16 ( V_26 -> V_103 ) ;
V_26 -> V_103 = V_1 ;
F_1 ( V_1 , V_2 , V_3 , V_5 ) ;
V_2 = V_1 ;
}
if ( V_26 -> V_99 . V_48 . V_65 != V_57 ||
V_26 -> V_99 . V_48 . V_66 != V_58 ||
V_26 -> V_100 ) {
V_26 -> V_99 . V_48 . V_65 = V_57 ;
V_26 -> V_99 . V_48 . V_66 = V_58 ;
V_88 . V_95 |= V_104 ;
}
if ( V_26 -> V_99 . V_48 . V_10 != V_5 -> V_9 . V_11 ||
V_26 -> V_99 . V_48 . V_11 != V_5 -> V_9 . V_10 ||
V_26 -> V_100 ) {
V_26 -> V_99 . V_48 . V_10 = V_5 -> V_9 . V_11 ;
V_26 -> V_99 . V_48 . V_11 = V_5 -> V_9 . V_10 ;
V_88 . V_95 |= V_105 ;
}
V_24 = V_90 * V_5 -> V_9 . V_10 ;
V_23 = V_30 - ( ( V_5 -> V_106 + 1 ) * V_5 -> V_9 . V_11 ) ;
if ( V_26 -> V_99 . V_48 . V_24 != V_24 ||
V_26 -> V_99 . V_48 . V_23 != V_23 ||
V_26 -> V_100 ) {
V_26 -> V_99 . V_48 . V_24 = V_24 ;
V_26 -> V_99 . V_48 . V_23 = V_23 ;
V_88 . V_95 |= V_107 ;
}
if ( V_26 -> V_99 . V_108 . V_109 || V_26 -> V_99 . V_108 . V_90 ||
V_26 -> V_100 ) {
V_26 -> V_99 . V_108 . V_109 = V_88 . V_108 . V_90 = 0 ;
V_88 . V_95 |= V_110 ;
}
if ( V_88 . V_95 & V_105 ||
V_5 -> V_93 != V_26 -> V_31 -> V_111 ||
V_26 -> V_99 . V_112 == NULL ||
V_26 -> V_100 ) {
char * V_113 , * V_112 = F_13 ( V_89 * V_5 -> V_9 . V_11 , V_102 ) ;
int V_114 , V_61 , V_6 = 0 ;
int V_11 = ( V_5 -> V_9 . V_11 + 7 ) / 8 ;
if ( ! V_112 )
return;
V_113 = F_13 ( V_11 * V_5 -> V_9 . V_10 , V_102 ) ;
if ( ! V_113 ) {
F_16 ( V_112 ) ;
return;
}
F_16 ( V_26 -> V_99 . V_112 ) ;
V_26 -> V_99 . V_112 = V_112 ;
V_26 -> V_31 -> V_111 = V_5 -> V_93 ;
V_88 . V_95 |= V_115 ;
switch ( V_26 -> V_31 -> V_111 & V_116 ) {
case V_117 :
V_114 = 0 ;
break;
case V_118 :
V_114 = ( V_5 -> V_9 . V_10 < 10 ) ? 1 : 2 ;
break;
case V_119 :
V_114 = V_5 -> V_9 . V_10 / 3 ;
break;
case V_120 :
V_114 = V_5 -> V_9 . V_10 >> 1 ;
break;
case V_121 :
V_114 = ( V_5 -> V_9 . V_10 << 1 ) / 3 ;
break;
case V_122 :
default:
V_114 = V_5 -> V_9 . V_10 ;
break;
}
V_61 = ( V_5 -> V_9 . V_10 - V_114 ) * V_11 ;
while ( V_61 -- )
V_113 [ V_6 ++ ] = 0 ;
V_61 = V_114 * V_11 ;
while ( V_61 -- )
V_113 [ V_6 ++ ] = 0xff ;
memset ( V_112 , 0 , V_89 * V_5 -> V_9 . V_11 ) ;
F_20 ( V_113 , V_112 , V_5 -> V_9 . V_11 , V_5 -> V_9 . V_10 ) ;
F_16 ( V_113 ) ;
}
switch ( V_85 ) {
case V_96 :
V_26 -> V_99 . V_123 = 0 ;
break;
case V_124 :
case V_125 :
default:
V_26 -> V_99 . V_123 = ( V_92 ) ? 0 : 1 ;
break;
}
V_88 . V_48 . V_69 = V_2 ;
V_88 . V_48 . V_65 = V_26 -> V_99 . V_48 . V_65 ;
V_88 . V_48 . V_66 = V_26 -> V_99 . V_48 . V_66 ;
V_88 . V_48 . V_24 = V_26 -> V_99 . V_48 . V_24 ;
V_88 . V_48 . V_23 = V_26 -> V_99 . V_48 . V_23 ;
V_88 . V_48 . V_10 = V_26 -> V_99 . V_48 . V_10 ;
V_88 . V_48 . V_11 = V_26 -> V_99 . V_48 . V_11 ;
V_88 . V_108 . V_109 = V_26 -> V_99 . V_108 . V_109 ;
V_88 . V_108 . V_90 = V_26 -> V_99 . V_108 . V_90 ;
V_88 . V_112 = V_26 -> V_99 . V_112 ;
V_88 . V_123 = V_26 -> V_99 . V_123 ;
V_88 . V_48 . V_67 = 1 ;
V_88 . V_39 = V_126 ;
if ( V_20 -> V_33 -> V_87 )
V_94 = V_20 -> V_33 -> V_87 ( V_20 , & V_88 ) ;
if ( V_94 )
F_21 ( V_20 , & V_88 ) ;
V_26 -> V_100 = 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_27 ;
T_2 V_81 ;
T_2 V_30 = F_3 ( V_26 -> V_31 -> V_32 , V_20 ) ;
int V_94 ;
V_81 = ( V_30 - V_20 -> V_74 . V_75 ) - V_26 -> V_74 . V_83 ;
V_26 -> V_74 . V_83 = V_26 -> V_74 . V_81 ;
V_26 -> V_74 . V_81 = V_81 ;
V_94 = F_23 ( V_20 , & V_26 -> V_74 ) ;
V_26 -> V_74 . V_83 = V_20 -> V_74 . V_83 ;
V_26 -> V_74 . V_81 = V_20 -> V_74 . V_81 ;
V_26 -> V_74 . V_127 = V_20 -> V_74 . V_127 ;
return V_94 ;
}
void F_24 ( struct V_25 * V_26 )
{
V_26 -> V_128 = F_2 ;
V_26 -> V_129 = F_4 ;
V_26 -> V_130 = F_11 ;
V_26 -> V_131 = F_17 ;
V_26 -> V_88 = F_18 ;
V_26 -> V_132 = F_22 ;
}
