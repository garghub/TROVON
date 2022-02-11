static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
F_2 ( V_2 -> V_5 , L_1 , F_3 ( V_2 -> V_6 + V_7 ) ) ;
V_3 = F_3 ( V_2 -> V_6 + V_8 ) ;
F_2 ( V_2 -> V_5 , L_2 , V_3 ) ;
if ( V_3 & V_9 )
F_2 ( V_2 -> V_5 , L_3 ) ;
F_2 ( V_2 -> V_5 , L_4 , F_3 ( V_2 -> V_6 + V_10 ) ) ;
F_2 ( V_2 -> V_5 , L_5 , F_3 ( V_2 -> V_6 + V_11 ) ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ )
F_2 ( V_2 -> V_5 , L_6 ,
V_4 , F_3 ( V_2 -> V_6 + F_4 ( V_4 ) ) ) ;
F_2 ( V_2 -> V_5 , L_7 , F_3 ( V_2 -> V_6 + V_12 ) ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_13 ; V_4 ++ )
F_2 ( V_2 -> V_5 , L_8 , V_4 ,
F_3 ( V_2 -> V_6 + F_5 ( V_4 ) ) ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ )
F_2 ( V_2 -> V_5 , L_9 , V_4 ,
F_3 ( V_2 -> V_15 + F_6 ( V_4 ) ) ) ;
V_3 = F_3 ( V_2 -> V_16 + V_17 ) ;
F_2 ( V_2 -> V_5 , L_10 , V_3 ) ;
F_2 ( V_2 -> V_5 , L_11 ,
F_3 ( V_2 -> V_16 + V_18 ) ) ;
F_2 ( V_2 -> V_5 , L_12 , F_3 ( V_2 -> V_16 + V_19 ) ) ;
F_2 ( V_2 -> V_5 , L_13 , F_3 ( V_2 -> V_16 + V_20 ) ) ;
if ( V_2 -> V_21 -> type == V_22 )
F_2 ( V_2 -> V_5 , L_14 , F_3 ( V_2 -> V_6 + V_23 ) ) ;
F_2 ( V_2 -> V_5 , L_15 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
T_1 V_6 , V_24 ;
V_3 = F_3 ( V_2 -> V_15 + F_6 ( V_4 ) ) ;
if ( ! ( V_3 & ( V_25 | V_26 ) ) )
continue;
V_24 = ( V_3 & V_27 ) >> V_28 ;
V_6 = V_3 & V_29 ;
F_2 ( V_2 -> V_5 , L_16 ,
V_4 , V_6 << 12 , ( V_24 << 12 ) | 0xfff ,
V_3 & V_25 ? 'W' : '.' ,
V_3 & V_26 ? 'R' : '.' ) ;
}
F_2 ( V_2 -> V_5 , L_17 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_13 ; V_4 ++ ) {
T_1 V_30 , V_6 , V_24 ;
V_30 = F_3 ( V_2 -> V_6 + F_5 ( V_4 ) ) ;
V_6 = V_30 & V_31 ;
V_24 = ( V_30 & V_32 ) >> V_33 ;
if ( V_6 >= V_24 || ( V_4 > 0 && V_24 == 0 ) )
F_2 ( V_2 -> V_5 , L_18 , V_4 ) ;
else
F_2 ( V_2 -> V_5 , L_19 ,
V_4 , V_6 << 12 , ( V_24 << 12 ) | 0xfff ) ;
}
F_2 ( V_2 -> V_5 , L_20 ,
V_2 -> V_34 ? 'S' : 'H' ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_35 , T_2 V_36 )
{
T_2 V_37 ;
int V_4 = 0 ;
if ( V_36 > V_38 )
return - V_39 ;
while ( V_36 > 0 ) {
V_37 = F_8 ( T_2 , V_36 , 4 ) ;
F_9 ( V_35 , V_2 -> V_6 + F_4 ( V_4 ) , V_37 ) ;
V_36 -= V_37 ;
V_35 += V_37 ;
V_4 ++ ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , const void * V_35 ,
T_2 V_36 )
{
T_2 V_37 ;
int V_4 = 0 ;
if ( V_36 > V_38 )
return - V_39 ;
while ( V_36 > 0 ) {
V_37 = F_8 ( T_2 , V_36 , 4 ) ;
F_11 ( V_2 -> V_6 + F_4 ( V_4 ) , V_35 , V_37 ) ;
V_36 -= V_37 ;
V_35 += V_37 ;
V_4 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_40 ;
return F_13 ( V_2 -> V_6 + V_8 , V_40 ,
! ( V_40 & V_41 ) , 0 ,
V_42 * 1000 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_40 ;
return F_13 ( V_2 -> V_16 + V_17 , V_40 ,
! ( V_40 & V_43 ) , 0 ,
V_42 * 1000 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_44 , V_45 , V_40 ;
int V_4 ;
switch ( V_2 -> V_21 -> type ) {
case V_22 :
V_2 -> V_16 = V_2 -> V_6 + V_46 ;
V_2 -> V_15 = V_2 -> V_6 + V_47 ;
V_2 -> V_13 = V_48 ;
if ( V_49 ) {
V_40 = F_3 ( V_2 -> V_6 + V_23 ) ;
if ( ! ( V_40 & V_50 ) ) {
V_40 |= V_50 ;
F_16 ( V_40 , V_2 -> V_6 + V_23 ) ;
V_40 = F_3 ( V_2 -> V_6 + V_23 ) ;
}
V_2 -> V_49 = ! ! ( V_40 & V_50 ) ;
}
break;
case V_51 :
V_2 -> V_16 = V_2 -> V_6 + V_52 ;
V_2 -> V_15 = V_2 -> V_6 + V_53 ;
V_2 -> V_13 = V_54 ;
break;
case V_55 :
V_2 -> V_16 = V_2 -> V_6 + V_56 ;
V_2 -> V_15 = V_2 -> V_6 + V_57 ;
V_2 -> V_13 = V_58 ;
V_2 -> V_59 = true ;
break;
default:
return - V_39 ;
}
V_40 = F_3 ( V_2 -> V_6 + V_8 ) ;
V_40 &= ~ V_60 ;
F_16 ( V_40 , V_2 -> V_6 + V_8 ) ;
V_44 = F_3 ( V_2 -> V_16 + V_19 ) ;
V_45 = F_3 ( V_2 -> V_16 + V_20 ) ;
if ( V_44 && V_45 ) {
for ( V_4 = 0 ; V_4 < F_17 ( V_2 -> V_61 ) / 2 ; V_4 ++ ) {
V_2 -> V_61 [ V_4 ] = V_44 >> V_4 * 8 ;
V_2 -> V_61 [ V_4 + 4 ] = V_45 >> V_4 * 8 ;
}
V_40 = F_3 ( V_2 -> V_16 + V_18 ) ;
V_2 -> V_62 [ 0 ] = V_40 ;
V_2 -> V_62 [ 1 ] = V_40 >> 8 ;
V_40 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_40 &= ~ V_63 ;
F_16 ( V_40 , V_2 -> V_16 + V_17 ) ;
V_2 -> V_34 = true ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_3 V_64 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_17 ( V_2 -> V_61 ) ; V_4 ++ )
if ( V_2 -> V_61 [ V_4 ] == V_64 )
return V_4 ;
return - V_39 ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_64 , T_3 * V_35 ,
int V_65 )
{
T_1 V_40 , V_66 ;
int V_67 ;
V_40 = F_3 ( V_2 -> V_6 + V_8 ) ;
V_40 &= ~ ( V_68 | V_69 ) ;
switch ( V_64 ) {
case V_70 :
V_40 |= V_71 ;
break;
case V_72 :
V_40 |= V_73 ;
break;
case V_74 :
V_40 |= V_75 ;
break;
default:
return - V_39 ;
}
V_40 |= ( V_65 - 1 ) << V_76 ;
V_40 |= V_77 | V_78 ;
V_40 |= V_79 ;
F_16 ( V_40 , V_2 -> V_6 + V_8 ) ;
V_67 = F_12 ( V_2 ) ;
if ( V_67 )
return V_67 ;
V_66 = F_3 ( V_2 -> V_6 + V_8 ) ;
if ( V_66 & V_77 )
return - V_80 ;
else if ( V_66 & V_81 )
return - V_82 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_64 , T_3 * V_35 ,
int V_65 )
{
T_1 V_40 , V_66 ;
int V_67 ;
V_67 = F_18 ( V_2 , V_64 ) ;
if ( V_67 < 0 )
return V_67 ;
V_40 = ( V_65 << V_83 ) | V_84 ;
V_40 |= V_67 << V_85 ;
V_40 |= V_86 | V_87 ;
V_40 |= V_88 ;
F_16 ( V_40 , V_2 -> V_16 + V_17 ) ;
V_67 = F_14 ( V_2 ) ;
if ( V_67 )
return V_67 ;
V_66 = F_3 ( V_2 -> V_6 + V_17 ) ;
if ( V_66 & V_86 )
return - V_80 ;
else if ( V_66 & V_89 )
return - V_82 ;
return 0 ;
}
static int F_21 ( struct V_90 * V_91 , T_3 V_64 , T_3 * V_35 , int V_65 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
int V_67 ;
F_16 ( 0 , V_2 -> V_6 + V_10 ) ;
if ( V_2 -> V_34 )
V_67 = F_20 ( V_2 , V_64 , V_35 , V_65 ) ;
else
V_67 = F_19 ( V_2 , V_64 , V_35 , V_65 ) ;
if ( V_67 )
return V_67 ;
return F_7 ( V_2 , V_35 , V_65 ) ;
}
static int F_22 ( struct V_90 * V_91 , T_3 V_64 , T_3 * V_35 , int V_65 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
int V_67 ;
if ( V_64 == V_93 )
return 0 ;
F_16 ( 0 , V_2 -> V_6 + V_10 ) ;
V_67 = F_10 ( V_2 , V_35 , V_65 ) ;
if ( V_67 )
return V_67 ;
if ( V_2 -> V_34 )
return F_20 ( V_2 , V_64 , V_35 , V_65 ) ;
return F_19 ( V_2 , V_64 , V_35 , V_65 ) ;
}
static T_4 F_23 ( struct V_90 * V_91 , T_5 V_94 , T_2 V_65 ,
T_6 * V_95 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
T_2 V_96 , V_97 = 0 ;
T_1 V_40 , V_66 ;
T_4 V_67 ;
switch ( V_91 -> V_98 ) {
case V_99 :
case V_100 :
break;
default:
return - V_39 ;
}
while ( V_65 > 0 ) {
V_96 = F_8 ( T_2 , V_65 , V_38 ) ;
F_16 ( V_94 , V_2 -> V_6 + V_10 ) ;
V_40 = F_3 ( V_2 -> V_6 + V_8 ) ;
V_40 &= ~ ( V_69 | V_68 ) ;
V_40 |= V_81 | V_77 | V_78 ;
V_40 |= ( V_96 - 1 ) << V_76 ;
V_40 |= V_101 ;
V_40 |= V_79 ;
F_16 ( V_40 , V_2 -> V_6 + V_8 ) ;
V_67 = F_12 ( V_2 ) ;
if ( V_67 )
return V_67 ;
V_66 = F_3 ( V_2 -> V_6 + V_8 ) ;
if ( V_66 & V_77 )
V_67 = - V_80 ;
else if ( V_66 & V_81 )
V_67 = - V_82 ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_5 , L_21 , V_94 ,
V_66 ) ;
return V_67 ;
}
V_67 = F_7 ( V_2 , V_95 , V_96 ) ;
if ( V_67 )
return V_67 ;
V_65 -= V_96 ;
V_94 += V_96 ;
V_97 += V_96 ;
V_95 += V_96 ;
}
return V_97 ;
}
static T_4 F_25 ( struct V_90 * V_91 , T_5 V_102 , T_2 V_65 ,
const T_6 * V_103 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
T_2 V_96 , V_97 = 0 ;
T_1 V_40 , V_66 ;
T_4 V_67 ;
while ( V_65 > 0 ) {
V_96 = F_8 ( T_2 , V_65 , V_38 ) ;
F_16 ( V_102 , V_2 -> V_6 + V_10 ) ;
V_40 = F_3 ( V_2 -> V_6 + V_8 ) ;
V_40 &= ~ ( V_69 | V_68 ) ;
V_40 |= V_81 | V_77 | V_78 ;
V_40 |= ( V_96 - 1 ) << V_76 ;
V_40 |= V_104 ;
if ( V_2 -> V_62 [ 1 ] == V_93 )
V_40 |= V_105 ;
V_40 |= V_106 ;
F_16 ( V_40 , V_2 -> V_6 + V_8 ) ;
V_67 = F_10 ( V_2 , V_103 , V_96 ) ;
if ( V_67 ) {
F_24 ( V_2 -> V_5 , L_22 ) ;
return V_67 ;
}
V_40 = F_3 ( V_2 -> V_6 + V_8 ) ;
F_16 ( V_40 | V_79 , V_2 -> V_6 + V_8 ) ;
V_67 = F_12 ( V_2 ) ;
if ( V_67 ) {
F_24 ( V_2 -> V_5 , L_23 ) ;
return V_67 ;
}
V_66 = F_3 ( V_2 -> V_6 + V_8 ) ;
if ( V_66 & V_77 )
V_67 = - V_80 ;
else if ( V_66 & V_81 )
V_67 = - V_82 ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_5 , L_24 , V_102 ,
V_66 ) ;
return V_67 ;
}
V_65 -= V_96 ;
V_102 += V_96 ;
V_97 += V_96 ;
V_103 += V_96 ;
}
return V_97 ;
}
static int F_26 ( struct V_90 * V_91 , T_5 V_107 )
{
T_2 V_108 , V_65 = V_91 -> V_109 . V_110 ;
struct V_1 * V_2 = V_91 -> V_92 ;
T_1 V_40 , V_66 , V_111 ;
int V_67 ;
if ( V_65 >= V_112 && V_2 -> V_59 ) {
V_111 = V_113 ;
V_108 = V_112 ;
} else {
V_111 = V_114 ;
V_108 = V_115 ;
}
while ( V_65 > 0 ) {
F_16 ( V_107 , V_2 -> V_6 + V_10 ) ;
V_40 = F_3 ( V_2 -> V_6 + V_8 ) ;
V_40 &= ~ ( V_69 | V_68 ) ;
V_40 |= V_81 | V_77 | V_78 ;
V_40 |= V_111 ;
V_40 |= V_79 ;
F_16 ( V_40 , V_2 -> V_6 + V_8 ) ;
V_67 = F_12 ( V_2 ) ;
if ( V_67 )
return V_67 ;
V_66 = F_3 ( V_2 -> V_6 + V_8 ) ;
if ( V_66 & V_77 )
return - V_80 ;
else if ( V_66 & V_81 )
return - V_82 ;
V_107 += V_108 ;
V_65 -= V_108 ;
}
return 0 ;
}
static bool F_27 ( const struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_24 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
T_1 V_116 , V_117 , V_118 ;
V_118 = F_3 ( V_2 -> V_15 + F_6 ( V_4 ) ) ;
if ( ! ( V_118 & ( V_25 | V_26 ) ) )
continue;
V_117 = ( V_118 & V_27 ) >> V_28 ;
V_116 = V_118 & V_29 ;
if ( V_116 >= V_6 && V_117 <= V_24 )
return true ;
}
return false ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
T_7 V_121 ;
int V_4 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
V_120 -> V_36 = 4096 ;
V_120 -> V_122 = L_25 ;
for ( V_4 = 1 ; V_4 < V_2 -> V_13 ; V_4 ++ ) {
T_1 V_30 , V_6 , V_24 ;
V_30 = F_3 ( V_2 -> V_6 + F_5 ( V_4 ) ) ;
V_6 = V_30 & V_31 ;
V_24 = ( V_30 & V_32 ) >> V_33 ;
if ( V_6 >= V_24 || V_24 == 0 )
continue;
if ( F_27 ( V_2 , V_6 , V_24 ) )
V_2 -> V_49 = 0 ;
V_121 = ( V_24 << 12 ) + 4096 ;
if ( V_121 > V_120 -> V_36 )
V_120 -> V_36 = V_121 ;
}
}
struct V_1 * F_29 ( struct V_123 * V_5 ,
struct V_124 * V_125 , const struct V_126 * V_21 )
{
struct V_119 V_120 ;
struct V_1 * V_2 ;
int V_67 ;
if ( ! V_21 || ! V_125 )
return F_30 ( - V_39 ) ;
V_2 = F_31 ( V_5 , sizeof( * V_2 ) , V_127 ) ;
if ( ! V_2 )
return F_30 ( - V_128 ) ;
V_2 -> V_6 = F_32 ( V_5 , V_125 ) ;
if ( F_33 ( V_2 -> V_6 ) )
return V_2 -> V_6 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_49 = V_21 -> V_49 ;
V_67 = F_15 ( V_2 ) ;
if ( V_67 )
return F_30 ( V_67 ) ;
V_2 -> V_91 . V_5 = V_2 -> V_5 ;
V_2 -> V_91 . V_92 = V_2 ;
V_2 -> V_91 . V_129 = F_21 ;
V_2 -> V_91 . V_130 = F_22 ;
V_2 -> V_91 . V_131 = F_23 ;
V_2 -> V_91 . V_132 = F_25 ;
V_2 -> V_91 . V_133 = F_26 ;
V_67 = F_34 ( & V_2 -> V_91 , NULL , V_134 ) ;
if ( V_67 ) {
F_35 ( V_5 , L_26 ) ;
return F_30 ( V_67 ) ;
}
F_28 ( V_2 , & V_120 ) ;
if ( ! V_2 -> V_49 || ! V_49 )
V_2 -> V_91 . V_109 . V_135 &= ~ V_136 ;
V_67 = F_36 ( & V_2 -> V_91 . V_109 , NULL , NULL , & V_120 , 1 ) ;
if ( V_67 )
return F_30 ( V_67 ) ;
return V_2 ;
}
int F_37 ( struct V_1 * V_2 )
{
return F_38 ( & V_2 -> V_91 . V_109 ) ;
}
