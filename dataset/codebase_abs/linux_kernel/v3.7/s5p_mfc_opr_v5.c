int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 -> V_6 -> V_8 ;
V_2 -> V_9 . V_10 = V_11 . V_10 (
V_4 -> V_12 [ V_13 ] ,
V_6 -> V_9 ) ;
if ( F_2 ( ( int ) V_2 -> V_9 . V_10 ) ) {
V_2 -> V_9 . V_10 = NULL ;
F_3 ( L_1 ) ;
return - V_14 ;
}
V_2 -> V_9 . V_15 = F_4 (
V_4 -> V_12 [ V_13 ] , V_2 -> V_9 . V_10 ) ;
F_5 ( V_2 -> V_9 . V_15 & ( ( 1 << V_16 ) - 1 ) ) ;
V_2 -> V_9 . V_17 = V_11 . V_18 ( V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_9 . V_17 == NULL ) {
V_11 . V_19 ( V_2 -> V_9 . V_10 ) ;
V_2 -> V_9 . V_15 = 0 ;
V_2 -> V_9 . V_10 = NULL ;
F_3 ( L_2 ) ;
return - V_14 ;
}
memset ( V_2 -> V_9 . V_17 , 0 , V_6 -> V_9 ) ;
F_6 () ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 . V_15 ) {
V_11 . V_19 ( V_2 -> V_9 . V_10 ) ;
V_2 -> V_9 . V_10 = NULL ;
V_2 -> V_9 . V_15 = 0 ;
}
}
int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_20 = 0 ;
unsigned int V_21 = 0 ;
unsigned int V_22 , V_23 ;
if ( V_2 -> type == V_24 ) {
F_9 ( 2 , L_3 ,
V_2 -> V_25 , V_2 -> V_26 , V_2 -> V_27 ) ;
F_9 ( 2 , L_4 , V_2 -> V_28 ) ;
} else if ( V_2 -> type == V_29 ) {
V_20 = F_10 ( V_2 -> V_30 , V_31 )
* F_10 ( V_2 -> V_32 , V_33 ) ;
V_20 = F_10 ( V_20 , V_34 ) ;
if ( V_2 -> V_35 == V_36 ) {
V_21 = F_10 ( V_2 -> V_30 ,
V_31 )
* F_10 ( V_2 -> V_32 >> 1 ,
V_33 ) ;
V_21 = F_10 ( V_21 ,
V_34 ) ;
} else {
V_22 = F_10 ( V_2 -> V_30 + 16 ,
V_31 ) ;
V_23 = F_10 ( ( V_2 -> V_32 >> 1 ) + 4 ,
V_33 ) ;
V_21 = F_10 ( V_22 * V_23 ,
V_34 ) ;
}
F_9 ( 2 , L_5 ,
V_20 , V_21 ) ;
} else {
return - V_37 ;
}
switch ( V_2 -> V_35 ) {
case V_38 :
V_2 -> V_39 =
F_10 ( V_40 +
V_41 ,
V_42 ) ;
V_2 -> V_43 = V_2 -> V_28 * V_2 -> V_27 ;
break;
case V_44 :
V_2 -> V_39 =
F_10 ( V_45 +
V_46 +
V_47 +
V_48 +
V_49 ,
V_42 ) ;
V_2 -> V_43 = 0 ;
break;
case V_50 :
case V_51 :
V_2 -> V_39 =
F_10 ( V_49 +
V_46 +
V_47 +
V_45 +
3 * V_52 ,
V_42 ) ;
V_2 -> V_43 = 0 ;
break;
case V_53 :
V_2 -> V_39 = 0 ;
V_2 -> V_43 = 0 ;
break;
case V_54 :
V_2 -> V_39 =
F_10 ( V_49 +
V_46 +
V_47 +
V_45 ,
V_42 ) ;
V_2 -> V_43 = 0 ;
break;
case V_36 :
V_2 -> V_39 = ( V_20 * 2 ) +
V_55 +
V_56 +
V_57 +
V_58 ;
V_2 -> V_43 = ( V_20 * 2 ) +
( V_21 * 4 ) +
V_59 ;
break;
case V_60 :
V_2 -> V_39 = ( V_20 * 2 ) +
V_55 +
V_56 +
V_61 ;
V_2 -> V_43 = ( V_20 * 2 ) +
( V_21 * 4 ) ;
break;
case V_62 :
V_2 -> V_39 = ( V_20 * 2 ) +
V_55 +
V_61 ;
V_2 -> V_43 = ( V_20 * 2 ) +
( V_21 * 4 ) ;
break;
default:
break;
}
if ( V_2 -> V_39 > 0 ) {
V_2 -> V_63 = V_11 . V_10 (
V_4 -> V_12 [ V_13 ] , V_2 -> V_39 ) ;
if ( F_11 ( V_2 -> V_63 ) ) {
V_2 -> V_63 = NULL ;
F_12 ( V_64
L_6 ) ;
return - V_14 ;
}
V_2 -> V_65 = F_4 (
V_4 -> V_12 [ V_13 ] , V_2 -> V_63 ) ;
F_5 ( V_2 -> V_65 & ( ( 1 << V_16 ) - 1 ) ) ;
}
if ( V_2 -> V_43 > 0 ) {
V_2 -> V_66 = V_11 . V_10 (
V_4 -> V_12 [ V_67 ] , V_2 -> V_43 ) ;
if ( F_11 ( V_2 -> V_66 ) ) {
V_2 -> V_66 = NULL ;
F_3 ( L_7 ) ;
return - V_14 ;
}
V_2 -> V_68 = F_4 (
V_4 -> V_12 [ V_67 ] , V_2 -> V_66 ) ;
F_5 ( V_2 -> V_68 & ( ( 1 << V_69 ) - 1 ) ) ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 ) {
V_11 . V_19 ( V_2 -> V_63 ) ;
V_2 -> V_63 = NULL ;
V_2 -> V_65 = 0 ;
V_2 -> V_39 = 0 ;
}
if ( V_2 -> V_66 ) {
V_11 . V_19 ( V_2 -> V_66 ) ;
V_2 -> V_66 = NULL ;
V_2 -> V_68 = 0 ;
V_2 -> V_43 = 0 ;
}
}
int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 -> V_6 -> V_8 ;
if ( V_2 -> V_35 == V_38 ||
V_2 -> V_35 == V_36 )
V_2 -> V_2 . V_70 = V_6 -> V_71 ;
else
V_2 -> V_2 . V_70 = V_6 -> V_72 ;
V_2 -> V_2 . V_10 = V_11 . V_10 (
V_4 -> V_12 [ V_13 ] , V_2 -> V_2 . V_70 ) ;
if ( F_11 ( V_2 -> V_2 . V_10 ) ) {
F_3 ( L_8 ) ;
V_2 -> V_2 . V_10 = NULL ;
return - V_14 ;
}
V_2 -> V_2 . V_15 = F_4 (
V_4 -> V_12 [ V_13 ] , V_2 -> V_2 . V_10 ) ;
F_5 ( V_2 -> V_2 . V_15 & ( ( 1 << V_16 ) - 1 ) ) ;
V_2 -> V_2 . V_73 = F_15 ( V_2 -> V_2 . V_15 ) ;
V_2 -> V_2 . V_17 = V_11 . V_18 ( V_2 -> V_2 . V_10 ) ;
if ( ! V_2 -> V_2 . V_17 ) {
F_3 ( L_9 ) ;
V_11 . V_19 ( V_2 -> V_2 . V_10 ) ;
V_2 -> V_2 . V_10 = NULL ;
V_2 -> V_2 . V_73 = 0 ;
V_2 -> V_2 . V_15 = 0 ;
return - V_14 ;
}
memset ( V_2 -> V_2 . V_17 , 0 , V_2 -> V_2 . V_70 ) ;
F_6 () ;
V_2 -> V_74 . V_10 = V_11 . V_10 (
V_4 -> V_12 [ V_13 ] , V_6 -> V_74 ) ;
if ( F_11 ( V_2 -> V_74 . V_10 ) ) {
F_3 ( L_10 ) ;
return F_16 ( V_2 -> V_74 . V_10 ) ;
}
V_2 -> V_74 . V_73 = F_4 (
V_4 -> V_12 [ V_13 ] , V_2 -> V_74 . V_10 )
- V_4 -> V_75 ;
F_5 ( V_2 -> V_74 . V_73 & ( ( 1 << V_16 ) - 1 ) ) ;
V_2 -> V_74 . V_17 = V_11 . V_18 ( V_2 -> V_74 . V_10 ) ;
if ( ! V_2 -> V_74 . V_17 ) {
V_11 . V_19 ( V_2 -> V_74 . V_10 ) ;
V_2 -> V_74 . V_10 = NULL ;
V_2 -> V_74 . V_73 = 0 ;
F_3 ( L_11 ) ;
return - V_14 ;
}
memset ( ( void * ) V_2 -> V_74 . V_17 , 0 , V_6 -> V_74 ) ;
F_6 () ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_2 . V_10 ) {
V_11 . V_19 ( V_2 -> V_2 . V_10 ) ;
V_2 -> V_2 . V_10 = NULL ;
V_2 -> V_2 . V_73 = 0 ;
V_2 -> V_2 . V_17 = NULL ;
V_2 -> V_2 . V_15 = 0 ;
}
if ( V_2 -> V_74 . V_10 ) {
V_11 . V_19 ( V_2 -> V_74 . V_10 ) ;
V_2 -> V_74 . V_10 = NULL ;
V_2 -> V_74 . V_73 = 0 ;
V_2 -> V_74 . V_17 = NULL ;
}
}
int F_18 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_19 ( struct V_3 * V_4 )
{
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_76 ,
unsigned int V_73 )
{
F_21 ( V_76 , ( V_2 -> V_74 . V_17 + V_73 ) ) ;
F_6 () ;
}
static unsigned int F_22 ( struct V_1 * V_2 ,
unsigned int V_73 )
{
F_23 () ;
return F_24 ( V_2 -> V_74 . V_17 + V_73 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
unsigned int V_22 , V_23 ;
V_2 -> V_77 = F_10 ( V_2 -> V_30 , V_31 ) ;
V_2 -> V_78 = F_10 ( V_2 -> V_32 , V_33 ) ;
F_9 ( 2 ,
L_12 ,
V_2 -> V_30 , V_2 -> V_32 , V_2 -> V_77 ,
V_2 -> V_78 ) ;
if ( V_2 -> V_35 == V_38 ) {
V_2 -> V_25 = F_10 ( V_2 -> V_77 * V_2 -> V_78 ,
V_42 ) ;
V_2 -> V_26 = F_10 ( V_2 -> V_77 *
F_10 ( ( V_2 -> V_32 >> 1 ) ,
V_33 ) ,
V_42 ) ;
V_2 -> V_27 = F_10 ( V_2 -> V_77 *
F_10 ( ( V_2 -> V_78 >> 2 ) ,
V_33 ) ,
V_42 ) ;
} else {
V_22 =
F_10 ( V_2 -> V_30 + 24 , V_31 ) ;
V_23 =
F_10 ( V_2 -> V_32 + 16 , V_33 ) ;
V_2 -> V_25 = F_10 ( V_22 * V_23 ,
V_42 ) ;
V_22 =
F_10 ( V_2 -> V_30 + 16 , V_31 ) ;
V_23 =
F_10 ( ( V_2 -> V_32 >> 1 ) + 4 ,
V_33 ) ;
V_2 -> V_26 = F_10 ( V_22 * V_23 ,
V_42 ) ;
V_2 -> V_27 = 0 ;
}
}
void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 -> V_80 == V_81 ) {
V_2 -> V_77 = F_10 ( V_2 -> V_30 , V_82 ) ;
V_2 -> V_25 = F_10 ( V_2 -> V_30 , V_82 )
* F_10 ( V_2 -> V_32 , V_83 ) ;
V_2 -> V_26 = F_10 ( V_2 -> V_30 , V_82 )
* F_10 ( ( V_2 -> V_32 >> 1 ) , V_84 ) ;
V_2 -> V_25 = F_10 ( V_2 -> V_25 , V_85 ) ;
V_2 -> V_26 =
F_10 ( V_2 -> V_26 , V_85 ) ;
} else if ( V_2 -> V_79 -> V_80 == V_86 ) {
V_2 -> V_77 = F_10 ( V_2 -> V_30 , V_31 ) ;
V_2 -> V_25 = F_10 ( V_2 -> V_30 , V_31 )
* F_10 ( V_2 -> V_32 , V_33 ) ;
V_2 -> V_26 =
F_10 ( V_2 -> V_30 , V_31 )
* F_10 ( ( V_2 -> V_32 >> 1 ) , V_33 ) ;
V_2 -> V_25 = F_10 ( V_2 -> V_25 , V_34 ) ;
V_2 -> V_26 =
F_10 ( V_2 -> V_26 , V_34 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 -> V_6 -> V_8 ;
F_28 ( V_4 , F_15 ( V_2 -> V_9 . V_15 ) , V_87 ) ;
F_28 ( V_4 , V_6 -> V_9 , V_88 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_28 ( V_4 , V_2 -> V_74 . V_73 , V_89 ) ;
}
int F_30 ( struct V_1 * V_2 , int V_90 ,
unsigned int V_91 , unsigned int V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_28 ( V_4 , F_15 ( V_90 ) , V_92 ) ;
F_28 ( V_4 , V_2 -> V_93 , V_94 ) ;
F_28 ( V_4 , V_6 , V_95 ) ;
F_20 ( V_2 , V_91 , V_96 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
unsigned int V_97 , V_98 ;
unsigned int V_99 , V_100 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_101 ;
T_1 V_102 , V_103 ;
int V_104 , V_105 ;
V_102 = V_2 -> V_65 ;
V_104 = V_2 -> V_39 ;
V_103 = V_2 -> V_68 ;
V_105 = V_2 -> V_43 ;
V_101 = F_32 ( V_4 , V_106 ) &
~ V_107 ;
F_28 ( V_4 , V_2 -> V_28 | V_101 ,
V_106 ) ;
F_29 ( V_2 ) ;
switch ( V_2 -> V_35 ) {
case V_38 :
F_28 ( V_4 , F_15 ( V_102 ) ,
V_108 ) ;
V_102 += V_41 ;
V_104 -= V_41 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_109 ) ;
V_102 += V_40 ;
V_104 -= V_40 ;
break;
case V_44 :
F_28 ( V_4 , F_15 ( V_102 ) , V_110 ) ;
V_102 += V_45 ;
V_104 -= V_45 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_111 ) ;
V_102 += V_46 ;
V_104 -= V_46 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_112 ) ;
V_102 += V_47 ;
V_104 -= V_47 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_113 ) ;
V_102 += V_48 ;
V_104 -= V_48 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_114 ) ;
V_102 += V_49 ;
V_104 -= V_49 ;
break;
case V_54 :
F_28 ( V_4 , F_15 ( V_102 ) , V_115 ) ;
V_102 += V_49 ;
V_104 -= V_49 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_116 ) ;
V_102 += V_46 ;
V_104 -= V_46 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_117 ) ;
V_102 += V_47 ;
V_104 -= V_47 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_118 ) ;
V_102 += V_45 ;
V_104 -= V_45 ;
break;
case V_51 :
case V_50 :
F_28 ( V_4 , F_15 ( V_102 ) , V_119 ) ;
V_102 += V_45 ;
V_104 -= V_45 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_120 ) ;
V_102 += V_49 ;
V_104 -= V_49 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_121 ) ;
V_102 += V_46 ;
V_104 -= V_46 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_122 ) ;
V_102 += V_47 ;
V_104 -= V_47 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_123 ) ;
V_102 += V_52 ;
V_104 -= V_52 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_124 ) ;
V_102 += V_52 ;
V_104 -= V_52 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_125 ) ;
V_102 += V_52 ;
V_104 -= V_52 ;
break;
case V_53 :
break;
default:
F_3 ( L_13 ,
V_2 -> V_35 ) ;
return - V_37 ;
break;
}
V_97 = V_2 -> V_25 ;
V_99 = V_2 -> V_26 ;
V_100 = V_2 -> V_27 ;
F_9 ( 2 , L_14 , V_97 , V_99 ,
V_100 ) ;
for ( V_98 = 0 ; V_98 < V_2 -> V_28 ; V_98 ++ ) {
F_9 ( 2 , L_15 , V_98 ,
V_2 -> V_126 [ V_98 ] . V_127 . V_128 . V_129 ) ;
F_28 ( V_4 , F_33 ( V_2 -> V_126 [ V_98 ] . V_127 . V_128 . V_129 ) ,
V_130 + V_98 * 4 ) ;
F_9 ( 2 , L_16 , V_98 ,
V_2 -> V_126 [ V_98 ] . V_127 . V_128 . V_131 ) ;
F_28 ( V_4 , F_15 ( V_2 -> V_126 [ V_98 ] . V_127 . V_128 . V_131 ) ,
V_132 + V_98 * 4 ) ;
if ( V_2 -> V_35 == V_38 ) {
F_9 ( 2 , L_17 ,
V_103 , V_105 ) ;
F_28 ( V_4 , F_33 ( V_103 ) ,
V_133 + V_98 * 4 ) ;
V_103 += V_100 ;
V_105 -= V_100 ;
}
}
F_9 ( 2 , L_18 , V_102 , V_104 ) ;
F_9 ( 2 , L_19 ,
V_104 , V_105 , V_2 -> V_28 ) ;
if ( V_104 < 0 || V_105 < 0 ) {
F_9 ( 2 , L_20 ) ;
return - V_14 ;
}
F_20 ( V_2 , V_97 , V_134 ) ;
F_20 ( V_2 , V_99 , V_135 ) ;
if ( V_2 -> V_35 == V_38 )
F_20 ( V_2 , V_100 , V_136 ) ;
F_28 ( V_4 , ( ( V_137 & V_138 )
<< V_139 ) | ( V_2 -> V_140 ) ,
V_141 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
unsigned long V_142 , unsigned int V_70 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_28 ( V_4 , F_15 ( V_142 ) , V_143 ) ;
F_28 ( V_4 , V_70 , V_144 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 ,
unsigned long V_145 , unsigned long V_146 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_28 ( V_4 , F_33 ( V_145 ) , V_147 ) ;
F_28 ( V_4 , F_33 ( V_146 ) , V_148 ) ;
}
void F_36 ( struct V_1 * V_2 ,
unsigned long * V_145 , unsigned long * V_146 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
* V_145 = V_4 -> V_149 + ( F_32 ( V_4 , V_150 )
<< V_151 ) ;
* V_146 = V_4 -> V_149 + ( F_32 ( V_4 , V_152 )
<< V_151 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_102 , V_103 ;
T_1 V_104 , V_105 ;
unsigned int V_20 , V_21 ;
unsigned int V_22 , V_23 ;
int V_98 ;
V_102 = V_2 -> V_65 ;
V_104 = V_2 -> V_39 ;
V_103 = V_2 -> V_68 ;
V_105 = V_2 -> V_43 ;
V_20 = F_10 ( V_2 -> V_30 , V_31 )
* F_10 ( V_2 -> V_32 , V_33 ) ;
V_20 = F_10 ( V_20 , V_34 ) ;
if ( V_2 -> V_35 == V_36 ) {
V_21 = F_10 ( V_2 -> V_30 , V_31 )
* F_10 ( ( V_2 -> V_32 >> 1 ) , V_33 ) ;
V_21 = F_10 ( V_21 , V_34 ) ;
} else {
V_22 = F_10 ( V_2 -> V_30 + 16 ,
V_31 ) ;
V_23 = F_10 ( ( V_2 -> V_32 >> 1 ) + 4 ,
V_33 ) ;
V_21 = F_10 ( V_22 * V_23 ,
V_34 ) ;
}
F_9 ( 2 , L_21 , V_104 , V_105 ) ;
switch ( V_2 -> V_35 ) {
case V_36 :
for ( V_98 = 0 ; V_98 < 2 ; V_98 ++ ) {
F_28 ( V_4 , F_15 ( V_102 ) ,
V_153 + ( 4 * V_98 ) ) ;
V_102 += V_20 ;
V_104 -= V_20 ;
F_28 ( V_4 , F_33 ( V_103 ) ,
V_154 + ( 4 * V_98 ) ) ;
V_103 += V_20 ;
V_105 -= V_20 ;
}
for ( V_98 = 0 ; V_98 < 4 ; V_98 ++ ) {
F_28 ( V_4 , F_33 ( V_103 ) ,
V_155 + ( 4 * V_98 ) ) ;
V_103 += V_21 ;
V_105 -= V_21 ;
}
F_28 ( V_4 , F_15 ( V_102 ) , V_156 ) ;
V_102 += V_55 ;
V_104 -= V_55 ;
F_28 ( V_4 , F_15 ( V_102 ) ,
V_157 ) ;
V_102 += V_56 ;
V_104 -= V_56 ;
F_28 ( V_4 , F_15 ( V_102 ) ,
V_158 ) ;
V_102 += V_57 ;
V_104 -= V_57 ;
F_28 ( V_4 , F_33 ( V_103 ) ,
V_159 ) ;
V_103 += V_59 ;
V_105 -= V_59 ;
F_28 ( V_4 , F_15 ( V_102 ) ,
V_160 ) ;
V_102 += V_58 ;
V_104 -= V_58 ;
F_9 ( 2 , L_21 ,
V_104 , V_105 ) ;
break;
case V_60 :
for ( V_98 = 0 ; V_98 < 2 ; V_98 ++ ) {
F_28 ( V_4 , F_15 ( V_102 ) ,
V_153 + ( 4 * V_98 ) ) ;
V_102 += V_20 ;
V_104 -= V_20 ;
F_28 ( V_4 , F_33 ( V_103 ) ,
V_154 + ( 4 * V_98 ) ) ;
V_103 += V_20 ;
V_105 -= V_20 ;
}
for ( V_98 = 0 ; V_98 < 4 ; V_98 ++ ) {
F_28 ( V_4 , F_33 ( V_103 ) ,
V_155 + ( 4 * V_98 ) ) ;
V_103 += V_21 ;
V_105 -= V_21 ;
}
F_28 ( V_4 , F_15 ( V_102 ) , V_161 ) ;
V_102 += V_55 ;
V_104 -= V_55 ;
F_28 ( V_4 , F_15 ( V_102 ) ,
V_162 ) ;
V_102 += V_56 ;
V_104 -= V_56 ;
F_28 ( V_4 , F_15 ( V_102 ) ,
V_163 ) ;
V_102 += V_61 ;
V_104 -= V_61 ;
F_9 ( 2 , L_21 ,
V_104 , V_105 ) ;
break;
case V_62 :
for ( V_98 = 0 ; V_98 < 2 ; V_98 ++ ) {
F_28 ( V_4 , F_15 ( V_102 ) ,
V_153 + ( 4 * V_98 ) ) ;
V_102 += V_20 ;
V_104 -= V_20 ;
F_28 ( V_4 , F_33 ( V_103 ) ,
V_154 + ( 4 * V_98 ) ) ;
V_103 += V_20 ;
V_105 -= V_20 ;
}
for ( V_98 = 0 ; V_98 < 4 ; V_98 ++ ) {
F_28 ( V_4 , F_33 ( V_103 ) ,
V_155 + ( 4 * V_98 ) ) ;
V_103 += V_21 ;
V_105 -= V_21 ;
}
F_28 ( V_4 , F_15 ( V_102 ) , V_164 ) ;
V_102 += V_55 ;
V_104 -= V_55 ;
F_28 ( V_4 , F_15 ( V_102 ) , V_165 ) ;
V_102 += V_61 ;
V_104 -= V_61 ;
F_9 ( 2 , L_21 ,
V_104 , V_105 ) ;
break;
default:
F_3 ( L_22 ,
V_2 -> V_35 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_166 * V_167 = & V_2 -> V_168 ;
unsigned int V_169 ;
unsigned int V_74 ;
F_28 ( V_4 , V_2 -> V_30 , V_170 ) ;
F_28 ( V_4 , V_2 -> V_32 , V_171 ) ;
V_169 = F_32 ( V_4 , V_172 ) ;
V_169 |= ( 1 << 18 ) ;
V_169 &= ~ ( 0xFFFF ) ;
V_169 |= V_167 -> V_173 ;
F_28 ( V_4 , V_169 , V_172 ) ;
F_28 ( V_4 , 0 , V_174 ) ;
F_28 ( V_4 , V_167 -> V_175 , V_176 ) ;
if ( V_167 -> V_175 == V_177 ) {
F_28 ( V_4 , V_167 -> V_178 , V_179 ) ;
} else if ( V_167 -> V_175 == V_180 ) {
F_28 ( V_4 , V_167 -> V_181 , V_182 ) ;
} else {
F_28 ( V_4 , 0 , V_179 ) ;
F_28 ( V_4 , 0 , V_182 ) ;
}
F_28 ( V_4 , V_167 -> V_183 , V_184 ) ;
if ( V_2 -> V_79 -> V_80 == V_81 )
F_28 ( V_4 , 0 , V_185 ) ;
else if ( V_2 -> V_79 -> V_80 == V_86 )
F_28 ( V_4 , 3 , V_185 ) ;
V_169 = F_32 ( V_4 , V_186 ) ;
if ( V_167 -> V_187 ) {
V_169 |= ( 1 << 31 ) ;
V_169 &= ~ ( 0xFF << 16 ) ;
V_169 |= ( V_167 -> V_188 << 16 ) ;
V_169 &= ~ ( 0xFF << 8 ) ;
V_169 |= ( V_167 -> V_189 << 8 ) ;
V_169 &= ~ ( 0xFF ) ;
V_169 |= ( V_167 -> V_190 ) ;
} else {
V_169 = 0 ;
}
F_28 ( V_4 , V_169 , V_186 ) ;
V_169 = F_32 ( V_4 , V_191 ) ;
V_169 &= ~ ( 0x1 << 9 ) ;
V_169 |= ( V_167 -> V_192 << 9 ) ;
F_28 ( V_4 , V_169 , V_191 ) ;
if ( V_167 -> V_192 )
F_28 ( V_4 , V_167 -> V_193 ,
V_194 ) ;
else
F_28 ( V_4 , 0 , V_194 ) ;
if ( V_167 -> V_192 )
F_28 ( V_4 , V_167 -> V_195 , V_196 ) ;
V_74 = F_22 ( V_2 , V_197 ) ;
V_74 &= ~ ( 0x1 << 3 ) ;
V_74 |= ( V_167 -> V_198 << 3 ) ;
V_74 &= ~ ( 0x3 << 1 ) ;
V_74 |= ( V_167 -> V_199 << 1 ) ;
F_20 ( V_2 , V_74 , V_197 ) ;
F_20 ( V_2 , V_167 -> V_200 , V_201 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_166 * V_167 = & V_2 -> V_168 ;
struct V_202 * V_203 = & V_167 -> V_204 . V_205 ;
unsigned int V_169 ;
unsigned int V_74 ;
F_38 ( V_2 ) ;
V_169 = F_32 ( V_4 , V_172 ) ;
V_169 &= ~ ( 0x3 << 16 ) ;
V_169 |= ( V_167 -> V_206 << 16 ) ;
F_28 ( V_4 , V_169 , V_172 ) ;
V_169 = F_32 ( V_4 , V_207 ) ;
V_169 &= ~ ( 0xFF << 8 ) ;
V_169 |= ( V_203 -> V_208 << 8 ) ;
V_169 &= ~ ( 0x3F ) ;
V_169 |= V_203 -> V_209 ;
F_28 ( V_4 , V_169 , V_207 ) ;
F_28 ( V_4 , V_203 -> V_210 , V_211 ) ;
if ( V_203 -> V_210 )
F_28 ( V_4 , V_2 -> V_32 >> 1 , V_171 ) ;
F_28 ( V_4 , V_203 -> V_212 , V_213 ) ;
if ( V_203 -> V_214 < 0 ) {
V_169 = 0x10 ;
V_169 |= ( 0xFF - V_203 -> V_214 ) + 1 ;
} else {
V_169 = 0x00 ;
V_169 |= ( V_203 -> V_214 & 0xF ) ;
}
F_28 ( V_4 , V_169 , V_215 ) ;
if ( V_203 -> V_216 < 0 ) {
V_169 = 0x10 ;
V_169 |= ( 0xFF - V_203 -> V_216 ) + 1 ;
} else {
V_169 = 0x00 ;
V_169 |= ( V_203 -> V_216 & 0xF ) ;
}
F_28 ( V_4 , V_169 , V_217 ) ;
if ( V_203 -> V_218 == V_219 )
F_28 ( V_4 , 1 , V_220 ) ;
else
F_28 ( V_4 , 0 , V_220 ) ;
V_169 = F_32 ( V_4 , V_221 ) ;
V_169 &= ~ ( 0x3 << 5 ) ;
V_169 |= ( V_203 -> V_222 << 5 ) ;
V_169 &= ~ ( 0x1F ) ;
V_169 |= V_203 -> V_223 ;
F_28 ( V_4 , V_169 , V_221 ) ;
F_28 ( V_4 , V_203 -> V_224 , V_225 ) ;
V_169 = F_32 ( V_4 , V_191 ) ;
V_169 &= ~ ( 0x1 << 8 ) ;
V_169 |= ( V_167 -> V_226 << 8 ) ;
V_169 &= ~ ( 0x3F ) ;
V_169 |= V_203 -> V_227 ;
F_28 ( V_4 , V_169 , V_191 ) ;
if ( V_167 -> V_192 && V_167 -> V_228 )
F_28 ( V_4 , V_167 -> V_229 * 1000
/ V_167 -> V_228 , V_230 ) ;
else
F_28 ( V_4 , 0 , V_230 ) ;
V_169 = F_32 ( V_4 , V_231 ) ;
V_169 &= ~ ( 0x3F << 8 ) ;
V_169 |= ( V_203 -> V_232 << 8 ) ;
V_169 &= ~ ( 0x3F ) ;
V_169 |= V_203 -> V_233 ;
F_28 ( V_4 , V_169 , V_231 ) ;
if ( V_167 -> V_226 ) {
V_169 = F_32 ( V_4 , V_234 ) ;
V_169 &= ~ ( 0x1 << 3 ) ;
V_169 |= ( V_203 -> V_235 << 3 ) ;
V_169 &= ~ ( 0x1 << 2 ) ;
V_169 |= ( V_203 -> V_236 << 2 ) ;
V_169 &= ~ ( 0x1 << 1 ) ;
V_169 |= ( V_203 -> V_237 << 1 ) ;
V_169 &= ~ ( 0x1 ) ;
V_169 |= V_203 -> V_238 ;
F_28 ( V_4 , V_169 , V_234 ) ;
}
if ( ! V_167 -> V_192 && ! V_167 -> V_226 ) {
V_74 = F_22 ( V_2 , V_239 ) ;
V_74 &= ~ ( 0xFFF ) ;
V_74 |= ( ( V_203 -> V_240 & 0x3F ) << 6 ) ;
V_74 |= ( V_203 -> V_241 & 0x3F ) ;
F_20 ( V_2 , V_74 , V_239 ) ;
}
V_74 = F_22 ( V_2 , V_197 ) ;
V_74 &= ~ ( 0x1 << 15 ) ;
V_74 |= ( V_203 -> V_242 << 1 ) ;
F_20 ( V_2 , V_74 , V_197 ) ;
if ( V_203 -> V_242 ) {
V_74 = F_22 ( V_2 , V_243 ) ;
V_74 &= ~ ( 0xFF ) ;
V_74 |= V_203 -> V_244 ;
F_20 ( V_2 , V_74 , V_243 ) ;
if ( V_203 -> V_244 == 0xFF ) {
V_74 = F_22 ( V_2 , V_245 ) ;
V_74 &= ~ ( 0xFFFFFFFF ) ;
V_74 |= V_203 -> V_246 << 16 ;
V_74 |= V_203 -> V_247 ;
F_20 ( V_2 , V_74 , V_245 ) ;
}
}
V_74 = F_22 ( V_2 , V_248 ) ;
V_74 &= ~ ( 0x1 << 16 ) ;
V_74 |= ( V_203 -> V_249 << 16 ) ;
if ( V_203 -> V_249 ) {
V_74 &= ~ ( 0xFFFF ) ;
V_74 |= V_203 -> V_250 ;
}
F_20 ( V_2 , V_74 , V_248 ) ;
V_74 = F_22 ( V_2 , V_197 ) ;
if ( V_167 -> V_199 ==
V_251 ) {
V_74 &= ~ ( 0xFFFF << 16 ) ;
V_74 |= ( V_203 -> V_252 << 16 ) ;
}
F_20 ( V_2 , V_74 , V_197 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_166 * V_167 = & V_2 -> V_168 ;
struct V_253 * V_254 = & V_167 -> V_204 . V_255 ;
unsigned int V_169 ;
unsigned int V_74 ;
unsigned int V_256 ;
F_38 ( V_2 ) ;
V_169 = F_32 ( V_4 , V_172 ) ;
V_169 &= ~ ( 0x3 << 16 ) ;
V_169 |= ( V_167 -> V_206 << 16 ) ;
F_28 ( V_4 , V_169 , V_172 ) ;
V_169 = F_32 ( V_4 , V_207 ) ;
V_169 &= ~ ( 0xFF << 8 ) ;
V_169 |= ( V_254 -> V_208 << 8 ) ;
V_169 &= ~ ( 0x3F ) ;
V_169 |= V_254 -> V_209 ;
F_28 ( V_4 , V_169 , V_207 ) ;
F_28 ( V_4 , V_254 -> V_257 , V_258 ) ;
if ( ! V_167 -> V_192 ) {
V_74 = F_22 ( V_2 , V_239 ) ;
V_74 &= ~ ( 0xFFF ) ;
V_74 |= ( ( V_254 -> V_240 & 0x3F ) << 6 ) ;
V_74 |= ( V_254 -> V_241 & 0x3F ) ;
F_20 ( V_2 , V_74 , V_239 ) ;
}
if ( V_167 -> V_192 ) {
if ( V_167 -> V_228 > 0 ) {
V_256 = V_167 -> V_229 * 1000 /
V_167 -> V_228 ;
F_28 ( V_4 , V_256 ,
V_230 ) ;
V_74 = F_22 ( V_2 , V_259 ) ;
V_74 &= ~ ( 0xFFFFFFFF ) ;
V_74 |= ( 1 << 31 ) ;
V_74 |= ( ( V_167 -> V_229 & 0x7FFF ) << 16 ) ;
V_74 |= ( V_167 -> V_228 & 0xFFFF ) ;
F_20 ( V_2 , V_74 , V_259 ) ;
}
} else {
F_28 ( V_4 , 0 , V_230 ) ;
}
V_169 = F_32 ( V_4 , V_191 ) ;
V_169 &= ~ ( 0x3F ) ;
V_169 |= V_254 -> V_227 ;
F_28 ( V_4 , V_169 , V_191 ) ;
V_169 = F_32 ( V_4 , V_231 ) ;
V_169 &= ~ ( 0x3F << 8 ) ;
V_169 |= ( V_254 -> V_232 << 8 ) ;
V_169 &= ~ ( 0x3F ) ;
V_169 |= V_254 -> V_233 ;
F_28 ( V_4 , V_169 , V_231 ) ;
V_74 = F_22 ( V_2 , V_197 ) ;
if ( V_167 -> V_199 ==
V_251 ) {
V_74 &= ~ ( 0xFFFF << 16 ) ;
V_74 |= ( V_167 -> V_260 << 16 ) ;
}
F_20 ( V_2 , V_74 , V_197 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_166 * V_167 = & V_2 -> V_168 ;
struct V_253 * V_261 = & V_167 -> V_204 . V_255 ;
unsigned int V_169 ;
unsigned int V_74 ;
F_38 ( V_2 ) ;
if ( ! V_167 -> V_192 ) {
V_74 = F_22 ( V_2 , V_239 ) ;
V_74 &= ~ ( 0xFFF ) ;
V_74 |= ( V_261 -> V_241 & 0x3F ) ;
F_20 ( V_2 , V_74 , V_239 ) ;
}
if ( V_167 -> V_192 && V_167 -> V_228 )
F_28 ( V_4 , V_167 -> V_229 * 1000
/ V_167 -> V_228 , V_230 ) ;
else
F_28 ( V_4 , 0 , V_230 ) ;
V_169 = F_32 ( V_4 , V_191 ) ;
V_169 &= ~ ( 0x3F ) ;
V_169 |= V_261 -> V_227 ;
F_28 ( V_4 , V_169 , V_191 ) ;
V_169 = F_32 ( V_4 , V_231 ) ;
V_169 &= ~ ( 0x3F << 8 ) ;
V_169 |= ( V_261 -> V_232 << 8 ) ;
V_169 &= ~ ( 0x3F ) ;
V_169 |= V_261 -> V_233 ;
F_28 ( V_4 , V_169 , V_231 ) ;
V_74 = F_22 ( V_2 , V_197 ) ;
if ( V_167 -> V_199 ==
V_251 ) {
V_74 &= ~ ( 0xFFFF << 16 ) ;
V_74 |= ( V_167 -> V_260 << 16 ) ;
}
F_20 ( V_2 , V_74 , V_197 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_29 ( V_2 ) ;
if ( V_2 -> V_35 == V_44 )
F_28 ( V_4 , V_2 -> V_262 , V_213 ) ;
else
F_28 ( V_4 , 0 , V_213 ) ;
F_28 ( V_4 , ( ( V_2 -> V_263 & V_264 ) <<
V_265 ) | ( V_2 -> V_266 <<
V_267 ) | ( ( V_2 -> V_268 &
V_269 ) << V_270 ) ,
V_106 ) ;
F_28 ( V_4 ,
( ( V_271 & V_138 ) << V_139 )
| ( V_2 -> V_140 ) , V_141 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , int V_272 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_101 ;
if ( V_272 )
V_101 = F_32 ( V_4 , V_106 ) | (
V_273 << V_274 ) ;
else
V_101 = F_32 ( V_4 , V_106 ) &
~ ( V_273 << V_274 ) ;
F_28 ( V_4 , V_101 , V_106 ) ;
}
int F_44 ( struct V_1 * V_2 ,
enum V_275 V_276 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_28 ( V_4 , V_2 -> V_277 , V_278 ) ;
F_29 ( V_2 ) ;
F_43 ( V_2 , V_2 -> V_279 ) ;
switch ( V_276 ) {
case V_280 :
F_28 ( V_4 , ( ( V_281 & V_138 ) <<
V_139 ) | ( V_2 -> V_140 ) , V_141 ) ;
break;
case V_282 :
F_28 ( V_4 , ( ( V_283 & V_138 ) <<
V_139 ) | ( V_2 -> V_140 ) , V_141 ) ;
break;
case V_284 :
F_28 ( V_4 , ( ( V_285 &
V_138 ) << V_139 ) | ( V_2 -> V_140 ) ,
V_141 ) ;
break;
}
F_9 ( 2 , L_23 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_35 == V_36 )
F_39 ( V_2 ) ;
else if ( V_2 -> V_35 == V_60 )
F_40 ( V_2 ) ;
else if ( V_2 -> V_35 == V_62 )
F_41 ( V_2 ) ;
else {
F_3 ( L_24 ,
V_2 -> V_35 ) ;
return - V_37 ;
}
F_29 ( V_2 ) ;
F_28 ( V_4 , ( ( V_271 << 16 ) & 0x70000 ) |
( V_2 -> V_140 ) , V_141 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_286 ;
if ( V_2 -> V_79 -> V_80 == V_81 )
F_28 ( V_4 , 0 , V_185 ) ;
else if ( V_2 -> V_79 -> V_80 == V_86 )
F_28 ( V_4 , 3 , V_185 ) ;
F_29 ( V_2 ) ;
if ( V_2 -> V_287 == V_288 )
V_286 = V_283 ;
else
V_286 = V_281 ;
F_28 ( V_4 , ( ( V_286 & V_138 ) << V_139 )
| ( V_2 -> V_140 ) , V_141 ) ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 )
{
unsigned long V_289 ;
int V_290 ;
int V_291 ;
F_48 ( & V_4 -> V_292 , V_289 ) ;
V_290 = ( V_4 -> V_293 + 1 ) % V_294 ;
V_291 = 0 ;
while ( ! F_49 ( V_290 , & V_4 -> V_295 ) ) {
V_290 = ( V_290 + 1 ) % V_294 ;
if ( ++ V_291 > V_294 ) {
F_50 ( & V_4 -> V_292 , V_289 ) ;
return - V_296 ;
}
}
F_50 ( & V_4 -> V_292 , V_289 ) ;
return V_290 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_30 ( V_2 , 0 , 0 , 0 ) ;
V_4 -> V_293 = V_2 -> V_297 ;
F_52 ( V_2 ) ;
F_44 ( V_2 , V_284 ) ;
}
static int F_53 ( struct V_1 * V_2 , int V_276 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_298 * V_299 ;
unsigned long V_289 ;
unsigned int V_300 ;
F_48 ( & V_4 -> V_301 , V_289 ) ;
if ( F_54 ( & V_2 -> V_302 ) ) {
F_9 ( 2 , L_25 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
return - V_296 ;
}
V_299 = F_55 ( V_2 -> V_302 . V_303 , struct V_298 , V_304 ) ;
V_299 -> V_289 |= V_305 ;
F_30 ( V_2 ,
F_56 ( V_299 -> V_306 , 0 ) ,
V_2 -> V_307 , V_299 -> V_306 -> V_308 [ 0 ] . V_309 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
V_300 = V_299 -> V_306 -> V_310 . V_300 ;
V_4 -> V_293 = V_2 -> V_297 ;
F_52 ( V_2 ) ;
if ( V_299 -> V_306 -> V_308 [ 0 ] . V_309 == 0 ) {
V_276 = V_282 ;
F_9 ( 2 , L_26 ) ;
V_2 -> V_287 = V_288 ;
}
F_44 ( V_2 , V_276 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_289 ;
struct V_298 * V_311 ;
struct V_298 * V_312 ;
unsigned long V_313 , V_314 , V_315 ;
unsigned int V_316 ;
F_48 ( & V_4 -> V_301 , V_289 ) ;
if ( F_54 ( & V_2 -> V_302 ) && V_2 -> V_287 != V_288 ) {
F_9 ( 2 , L_27 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
return - V_296 ;
}
if ( F_54 ( & V_2 -> V_317 ) ) {
F_9 ( 2 , L_28 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
return - V_296 ;
}
if ( F_54 ( & V_2 -> V_302 ) ) {
F_35 ( V_2 , V_4 -> V_149 , V_4 -> V_149 ) ;
V_312 = NULL ;
} else {
V_312 = F_55 ( V_2 -> V_302 . V_303 , struct V_298 ,
V_304 ) ;
V_312 -> V_289 |= V_305 ;
if ( V_312 -> V_306 -> V_308 [ 0 ] . V_309 == 0 ) {
F_35 ( V_2 , V_4 -> V_149 ,
V_4 -> V_149 ) ;
V_2 -> V_287 = V_288 ;
} else {
V_313 = F_56 ( V_312 -> V_306 ,
0 ) ;
V_314 = F_56 ( V_312 -> V_306 ,
1 ) ;
F_35 ( V_2 , V_313 ,
V_314 ) ;
if ( V_312 -> V_289 & V_318 )
V_2 -> V_287 = V_288 ;
}
}
V_311 = F_55 ( V_2 -> V_317 . V_303 , struct V_298 , V_304 ) ;
V_311 -> V_289 |= V_305 ;
V_315 = F_56 ( V_311 -> V_306 , 0 ) ;
V_316 = F_58 ( V_311 -> V_306 , 0 ) ;
F_34 ( V_2 , V_315 , V_316 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
V_4 -> V_293 = V_2 -> V_297 ;
F_52 ( V_2 ) ;
F_9 ( 2 , L_29 ,
V_312 ? V_312 -> V_306 -> V_310 . V_300 : - 1 , V_2 -> V_287 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_289 ;
struct V_298 * V_299 ;
F_48 ( & V_4 -> V_301 , V_289 ) ;
F_9 ( 2 , L_30 ) ;
V_299 = F_55 ( V_2 -> V_302 . V_303 , struct V_298 , V_304 ) ;
F_27 ( V_2 ) ;
F_9 ( 2 , L_31 , V_299 -> V_306 -> V_308 [ 0 ] . V_309 ) ;
F_30 ( V_2 ,
F_56 ( V_299 -> V_306 , 0 ) ,
0 , V_299 -> V_306 -> V_308 [ 0 ] . V_309 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
V_4 -> V_293 = V_2 -> V_297 ;
F_52 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_289 ;
struct V_298 * V_311 ;
unsigned long V_315 ;
unsigned int V_316 ;
F_37 ( V_2 ) ;
F_48 ( & V_4 -> V_301 , V_289 ) ;
V_311 = F_55 ( V_2 -> V_317 . V_303 , struct V_298 , V_304 ) ;
V_315 = F_56 ( V_311 -> V_306 , 0 ) ;
V_316 = F_58 ( V_311 -> V_306 , 0 ) ;
F_34 ( V_2 , V_315 , V_316 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
V_4 -> V_293 = V_2 -> V_297 ;
F_52 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_289 ;
struct V_298 * V_299 ;
int V_319 ;
if ( V_2 -> V_320 != V_321 ) {
F_3 ( L_32
L_33
L_34 ) ;
return - V_296 ;
}
F_48 ( & V_4 -> V_301 , V_289 ) ;
if ( F_54 ( & V_2 -> V_302 ) ) {
F_3 ( L_35
L_36 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
return - V_322 ;
}
V_299 = F_55 ( V_2 -> V_302 . V_303 , struct V_298 , V_304 ) ;
F_9 ( 2 , L_31 , V_299 -> V_306 -> V_308 [ 0 ] . V_309 ) ;
F_30 ( V_2 ,
F_56 ( V_299 -> V_306 , 0 ) ,
0 , V_299 -> V_306 -> V_308 [ 0 ] . V_309 ) ;
F_50 ( & V_4 -> V_301 , V_289 ) ;
V_4 -> V_293 = V_2 -> V_297 ;
F_52 ( V_2 ) ;
V_319 = F_31 ( V_2 ) ;
if ( V_319 ) {
F_3 ( L_37 ) ;
V_2 -> V_287 = V_323 ;
}
return V_319 ;
}
void F_62 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_290 ;
unsigned int V_319 = 0 ;
if ( F_49 ( 0 , & V_4 -> V_324 ) ) {
F_9 ( 1 , L_38 ) ;
return;
}
if ( F_63 ( 0 , & V_4 -> V_325 ) != 0 ) {
F_9 ( 1 , L_39 ) ;
return;
}
V_290 = F_47 ( V_4 ) ;
if ( V_290 < 0 ) {
if ( F_64 ( 0 , & V_4 -> V_325 ) == 0 ) {
F_3 ( L_40 ) ;
return;
}
F_9 ( 1 , L_41 ) ;
return;
}
V_2 = V_4 -> V_2 [ V_290 ] ;
F_65 () ;
if ( V_2 -> type == V_24 ) {
F_27 ( V_2 ) ;
switch ( V_2 -> V_287 ) {
case V_288 :
F_53 ( V_2 , V_282 ) ;
break;
case V_326 :
V_319 = F_53 ( V_2 , V_280 ) ;
break;
case V_327 :
F_52 ( V_2 ) ;
V_319 = F_66 ( V_4 -> V_328 , V_329 ,
V_2 ) ;
break;
case V_330 :
F_52 ( V_2 ) ;
V_319 = F_66 ( V_4 -> V_328 , V_331 ,
V_2 ) ;
break;
case V_332 :
F_59 ( V_2 ) ;
break;
case V_333 :
V_319 = F_61 ( V_2 ) ;
F_9 ( 1 , L_42 ) ;
break;
case V_334 :
F_51 ( V_2 ) ;
break;
case V_335 :
F_53 ( V_2 , V_280 ) ;
break;
case V_336 :
F_9 ( 2 , L_43 ) ;
V_2 -> V_320 = V_337 ;
F_9 ( 2 , L_44 ) ;
F_59 ( V_2 ) ;
break;
default:
V_319 = - V_296 ;
}
} else if ( V_2 -> type == V_29 ) {
switch ( V_2 -> V_287 ) {
case V_288 :
case V_326 :
V_319 = F_57 ( V_2 ) ;
break;
case V_327 :
F_52 ( V_2 ) ;
V_319 = F_66 ( V_4 -> V_328 , V_329 ,
V_2 ) ;
break;
case V_330 :
F_52 ( V_2 ) ;
V_319 = F_66 ( V_4 -> V_328 , V_331 ,
V_2 ) ;
break;
case V_332 :
F_60 ( V_2 ) ;
break;
default:
V_319 = - V_296 ;
}
} else {
F_3 ( L_45 , V_2 -> type ) ;
V_319 = - V_296 ;
}
if ( V_319 ) {
if ( F_64 ( 0 , & V_4 -> V_325 ) == 0 )
F_3 ( L_40 ) ;
F_67 () ;
}
}
void F_68 ( struct V_338 * V_339 , struct V_340 * V_341 )
{
struct V_298 * V_306 ;
int V_98 ;
while ( ! F_54 ( V_339 ) ) {
V_306 = F_55 ( V_339 -> V_303 , struct V_298 , V_304 ) ;
for ( V_98 = 0 ; V_98 < V_306 -> V_306 -> V_342 ; V_98 ++ )
F_69 ( V_306 -> V_306 , V_98 , 0 ) ;
F_70 ( V_306 -> V_306 , V_343 ) ;
F_71 ( & V_306 -> V_304 ) ;
}
}
void F_72 ( struct V_3 * V_4 )
{
F_28 ( V_4 , 0 , V_344 ) ;
F_28 ( V_4 , 0 , V_345 ) ;
F_28 ( V_4 , 0xffff , V_346 ) ;
}
int F_73 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_347 ) << V_151 ;
}
int F_74 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_348 ) << V_151 ;
}
int F_75 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_349 ) ;
}
int F_76 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_350 ) ;
}
int F_77 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_351 ) &
V_352 ;
}
int F_78 ( struct V_1 * V_2 )
{
return ( F_22 ( V_2 , V_353 ) >>
V_354 ) &
V_352 ;
}
int F_79 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_355 ) ;
}
int F_80 ( struct V_3 * V_4 )
{
int V_356 ;
V_356 = F_32 ( V_4 , V_345 ) &
V_357 ;
switch ( V_356 ) {
case V_358 :
V_356 = V_359 ;
break;
case V_360 :
V_356 = V_361 ;
break;
case V_362 :
V_356 = V_363 ;
break;
case V_364 :
V_356 = V_365 ;
break;
case V_366 :
V_356 = V_367 ;
break;
case V_368 :
V_356 = V_369 ;
break;
case V_370 :
V_356 = V_371 ;
break;
case V_372 :
V_356 = V_373 ;
break;
case V_374 :
V_356 = V_375 ;
break;
case V_376 :
V_356 = V_377 ;
break;
case V_378 :
V_356 = V_379 ;
break;
case V_380 :
V_356 = V_381 ;
break;
default:
V_356 = V_382 ;
} ;
return V_356 ;
}
int F_81 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_383 ) ;
}
int F_82 ( unsigned int V_384 )
{
return ( V_384 & V_385 ) >> V_386 ;
}
int F_83 ( unsigned int V_384 )
{
return ( V_384 & V_387 ) >> V_388 ;
}
int F_84 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_389 ) ;
}
int F_85 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_390 ) ;
}
int F_86 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_391 ) ;
}
int F_87 ( struct V_3 * V_4 )
{
return - 1 ;
}
int F_88 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_392 ) ;
}
int F_89 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_393 ) ;
}
int F_90 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_394 ) ;
}
int F_91 ( struct V_3 * V_4 )
{
return - 1 ;
}
int F_92 ( struct V_3 * V_4 )
{
return F_32 ( V_4 , V_395 ) ;
}
int F_93 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_396 ) ;
}
int F_94 ( struct V_3 * V_4 )
{
return - 1 ;
}
int F_95 ( struct V_3 * V_4 )
{
return - 1 ;
}
unsigned int F_96 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_397 ) ;
}
unsigned int F_97 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_398 ) ;
}
unsigned int F_98 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_399 ) ;
}
unsigned int F_99 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_400 ) ;
}
struct V_401 * F_100 ( void )
{
return & V_402 ;
}
