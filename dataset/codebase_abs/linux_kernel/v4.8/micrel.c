static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_5 , V_6 | V_3 ) ;
return F_2 ( V_2 , V_7 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_2 ( V_2 , V_5 , V_3 ) ;
return F_4 ( V_2 , V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_4 ( V_2 , V_10 ) ;
return ( V_9 < 0 ) ? V_9 : 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
int V_14 ;
T_2 V_15 ;
if ( type && type -> V_16 )
V_15 = type -> V_16 ;
else
V_15 = V_17 ;
V_14 = F_4 ( V_2 , V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ V_15 ;
F_2 ( V_2 , V_18 , V_14 ) ;
if ( V_2 -> V_19 == V_20 )
V_14 = V_21 ;
else
V_14 = 0 ;
return F_2 ( V_2 , V_10 , V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 , bool V_4 )
{
int V_22 ;
V_22 = F_4 ( V_2 , V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_4 )
V_22 |= V_23 ;
else
V_22 &= ~ V_23 ;
return F_2 ( V_2 , V_18 , V_22 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_24 , int V_4 )
{
int V_9 , V_14 , V_25 ;
switch ( V_24 ) {
case V_26 :
V_25 = 14 ;
break;
case V_27 :
V_25 = 4 ;
break;
default:
return - V_28 ;
}
V_14 = F_4 ( V_2 , V_24 ) ;
if ( V_14 < 0 ) {
V_9 = V_14 ;
goto V_29;
}
V_14 &= ~ ( 3 << V_25 ) ;
V_14 |= V_4 << V_25 ;
V_9 = F_2 ( V_2 , V_24 , V_14 ) ;
V_29:
if ( V_9 < 0 )
F_9 ( V_2 , L_1 ) ;
return V_9 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_4 ( V_2 , V_31 ) ;
if ( V_30 < 0 )
goto V_29;
V_30 = F_2 ( V_2 , V_31 , V_30 | V_32 ) ;
V_29:
if ( V_30 )
F_9 ( V_2 , L_2 ) ;
return V_30 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_4 ( V_2 , V_31 ) ;
if ( V_30 < 0 )
goto V_29;
if ( ! ( V_30 & V_33 ) )
return 0 ;
V_30 = F_2 ( V_2 , V_31 ,
V_30 & ~ V_33 ) ;
V_29:
if ( V_30 )
F_9 ( V_2 , L_3 ) ;
return V_30 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
const struct V_11 * type ;
int V_30 ;
if ( ! V_35 )
return 0 ;
type = V_35 -> type ;
if ( type -> V_36 )
F_10 ( V_2 ) ;
if ( type -> V_37 )
F_11 ( V_2 ) ;
if ( V_35 -> V_38 ) {
V_30 = F_7 ( V_2 , V_35 -> V_39 ) ;
if ( V_30 ) {
F_9 ( V_2 ,
L_4 ) ;
return V_30 ;
}
}
if ( V_35 -> V_40 >= 0 )
F_8 ( V_2 , type -> V_41 , V_35 -> V_40 ) ;
if ( F_13 ( V_2 ) ) {
int V_42 = F_4 ( V_2 , V_43 ) ;
if ( V_42 < 0 )
return V_42 ;
V_30 = F_2 ( V_2 , V_43 , V_42 & ~ V_44 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_47 . V_48 . V_46 ;
if ( F_15 ( V_46 , L_5 ) ) {
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 &= V_52 |
V_53 |
V_54 ;
V_2 -> V_55 &= V_56 |
V_57 |
V_58 ;
V_2 -> V_59 = V_60 ;
}
return F_12 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 & V_50 ) {
V_2 -> V_61 = V_62 ;
return 0 ;
}
return F_17 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_45 * V_46 ,
T_2 V_24 ,
const char * V_63 , const char * V_64 ,
const char * V_65 , const char * V_66 )
{
int V_67 = - 1 ;
int V_68 = - 2 ;
int V_69 = - 3 ;
int V_70 = - 4 ;
int V_71 ;
int V_72 = 0 ;
if ( ! F_19 ( V_46 , V_63 , & V_67 ) )
V_72 ++ ;
if ( ! F_19 ( V_46 , V_64 , & V_68 ) )
V_72 ++ ;
if ( ! F_19 ( V_46 , V_65 , & V_69 ) )
V_72 ++ ;
if ( ! F_19 ( V_46 , V_66 , & V_70 ) )
V_72 ++ ;
if ( ! V_72 )
return 0 ;
if ( V_72 < 4 )
V_71 = F_3 ( V_2 , V_24 ) ;
else
V_71 = 0 ;
if ( V_67 != - 1 )
V_71 = ( ( V_71 & 0xfff0 ) | ( ( V_67 / V_73 ) & 0xf ) << 0 ) ;
if ( V_68 != - 2 )
V_71 = ( ( V_71 & 0xff0f ) | ( ( V_68 / V_73 ) & 0xf ) << 4 ) ;
if ( V_69 != - 3 )
V_71 = ( ( V_71 & 0xf0ff ) | ( ( V_69 / V_73 ) & 0xf ) << 8 ) ;
if ( V_70 != - 4 )
V_71 = ( ( V_71 & 0x0fff ) | ( ( V_70 / V_73 ) & 0xf ) << 12 ) ;
return F_1 ( V_2 , V_24 , V_71 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
const struct V_74 * V_48 = & V_2 -> V_47 . V_48 ;
const struct V_45 * V_46 = V_48 -> V_46 ;
const struct V_74 * V_75 ;
V_75 = & V_2 -> V_47 . V_48 ;
do {
V_46 = V_75 -> V_46 ;
V_75 = V_75 -> V_76 ;
} while ( ! V_46 && V_75 );
if ( V_46 ) {
F_18 ( V_2 , V_46 ,
V_77 ,
L_6 , L_7 ,
L_8 , L_9 ) ;
F_18 ( V_2 , V_46 ,
V_78 ,
L_10 , L_11 ,
L_12 , L_13 ) ;
F_18 ( V_2 , V_46 ,
V_79 ,
L_14 , L_15 ,
L_16 , L_17 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_80 , T_1 V_81 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_82 , V_81 ) ;
F_2 ( V_2 , V_83 , V_3 ) ;
F_2 ( V_2 , V_82 , ( V_80 << 14 ) | V_81 ) ;
return F_2 ( V_2 , V_83 , V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
T_3 V_80 , T_1 V_81 , T_1 V_3 )
{
F_2 ( V_2 , V_82 , V_81 ) ;
F_2 ( V_2 , V_83 , V_3 ) ;
F_2 ( V_2 , V_82 , ( V_80 << 14 ) | V_81 ) ;
return F_4 ( V_2 , V_83 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_45 * V_46 ,
T_2 V_24 , T_4 V_84 ,
const char * V_85 [] , T_3 V_86 )
{
int V_4 [ 4 ] = { - 1 , - 2 , - 3 , - 4 } ;
int V_72 = 0 ;
T_2 V_15 ;
T_2 V_87 ;
T_2 V_71 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_86 ; V_88 ++ )
if ( ! F_19 ( V_46 , V_85 [ V_88 ] , V_4 + V_88 ) )
V_72 ++ ;
if ( ! V_72 )
return 0 ;
if ( V_72 < V_86 )
V_71 = F_22 ( V_2 , V_89 , 2 , V_24 ) ;
else
V_71 = 0 ;
V_87 = ( V_84 == 4 ) ? 0xf : 0x1f ;
for ( V_88 = 0 ; V_88 < V_86 ; V_88 ++ )
if ( V_4 [ V_88 ] != - ( V_88 + 1 ) ) {
V_15 = 0xffff ;
V_15 ^= V_87 << ( V_84 * V_88 ) ;
V_71 = ( V_71 & V_15 ) |
( ( ( V_4 [ V_88 ] / V_90 ) & V_87 )
<< ( V_84 * V_88 ) ) ;
}
return F_21 ( V_2 , V_89 , 2 , V_24 , V_71 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = F_21 ( V_2 , V_89 , 0 ,
V_92 , 0x0006 ) ;
V_91 = F_21 ( V_2 , V_89 , 0 ,
V_93 , 0x1A80 ) ;
if ( V_91 )
return V_91 ;
return F_25 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
const struct V_74 * V_48 = & V_2 -> V_47 . V_48 ;
const struct V_45 * V_46 = V_48 -> V_46 ;
static const char * V_94 [ 2 ] = { L_9 , L_7 } ;
static const char * V_95 [ 4 ] = {
L_10 , L_11 ,
L_12 , L_13
} ;
static const char * V_96 [ 4 ] = {
L_14 , L_15 ,
L_16 , L_17
} ;
static const char * V_97 [ 2 ] = { L_6 , L_8 } ;
const struct V_74 * V_75 ;
V_75 = & V_2 -> V_47 . V_48 ;
do {
V_46 = V_75 -> V_46 ;
V_75 = V_75 -> V_76 ;
} while ( ! V_46 && V_75 );
if ( V_46 ) {
F_23 ( V_2 , V_46 ,
V_98 , 5 ,
V_94 , 2 ) ;
F_23 ( V_2 , V_46 ,
V_99 , 4 ,
V_97 , 2 ) ;
F_23 ( V_2 , V_46 ,
V_100 , 4 ,
V_95 , 4 ) ;
F_23 ( V_2 , V_46 ,
V_101 , 4 ,
V_96 , 4 ) ;
}
return F_24 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_102 ;
V_102 = F_4 ( V_2 , V_103 ) ;
V_102 = F_4 ( V_2 , V_103 ) ;
if ( V_102 & V_104 )
V_2 -> V_105 = V_106 ;
else
V_2 -> V_105 = V_107 ;
if ( V_102 & V_108 )
V_2 -> V_61 = V_109 ;
else
V_2 -> V_61 = V_62 ;
V_2 -> V_110 = 1 ;
V_2 -> V_111 = V_2 -> V_112 = 0 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_113 ;
int V_102 ;
V_113 = F_29 ( V_2 ) ;
if ( V_113 )
return V_113 ;
V_102 = F_4 ( V_2 , V_114 ) ;
if ( ( V_102 & 0xFF ) == 0xFF ) {
F_30 ( V_2 ) ;
V_2 -> V_110 = 0 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_32 ( struct V_1 * V_2 , int V_115 , int V_116 ,
int V_3 )
{
return - 1 ;
}
static void
F_33 ( struct V_1 * V_2 , int V_115 , int V_116 ,
int V_3 , T_1 V_4 )
{
}
static int F_34 ( struct V_1 * V_2 )
{
return F_35 ( V_117 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_3 * V_118 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < F_35 ( V_117 ) ; V_88 ++ ) {
memcpy ( V_118 + V_88 * V_119 ,
V_117 [ V_88 ] . string , V_119 ) ;
}
}
static T_5 F_37 ( struct V_1 * V_2 , int V_88 )
{
struct V_120 V_121 = V_117 [ V_88 ] ;
struct V_34 * V_35 = V_2 -> V_35 ;
int V_4 ;
T_5 V_30 ;
V_4 = F_4 ( V_2 , V_121 . V_24 ) ;
if ( V_4 < 0 ) {
V_30 = V_122 ;
} else {
V_4 = V_4 & ( ( 1 << V_121 . V_123 ) - 1 ) ;
V_35 -> V_124 [ V_88 ] += V_4 ;
V_30 = V_35 -> V_124 [ V_88 ] ;
}
return V_30 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_125 * V_124 , T_5 * V_118 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < F_35 ( V_117 ) ; V_88 ++ )
V_118 [ V_88 ] = F_37 ( V_2 , V_88 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) ) {
V_2 -> V_19 = V_126 ;
if ( V_2 -> V_12 -> V_127 )
V_2 -> V_12 -> V_127 ( V_2 ) ;
}
return F_40 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
if ( F_13 ( V_2 ) ) {
V_2 -> V_19 = V_20 ;
if ( V_2 -> V_12 -> V_127 )
V_2 -> V_12 -> V_127 ( V_2 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
const struct V_45 * V_128 = V_2 -> V_47 . V_48 . V_46 ;
struct V_34 * V_35 ;
struct V_129 * V_129 ;
int V_30 ;
V_35 = F_44 ( & V_2 -> V_47 . V_48 , sizeof( * V_35 ) , V_130 ) ;
if ( ! V_35 )
return - V_131 ;
V_2 -> V_35 = V_35 ;
V_35 -> type = type ;
if ( type -> V_41 ) {
V_30 = F_19 ( V_128 , L_18 ,
& V_35 -> V_40 ) ;
if ( V_30 )
V_35 -> V_40 = - 1 ;
if ( V_35 -> V_40 > 3 ) {
F_9 ( V_2 , L_19 ,
V_35 -> V_40 ) ;
V_35 -> V_40 = - 1 ;
}
} else {
V_35 -> V_40 = - 1 ;
}
V_129 = F_45 ( & V_2 -> V_47 . V_48 , L_20 ) ;
if ( ! F_46 ( V_129 ) ) {
unsigned long V_132 = F_47 ( V_129 ) ;
bool V_133 ;
V_35 -> V_38 = type -> V_134 ;
V_133 = F_15 ( V_128 ,
L_21 ) ;
if ( V_132 > 24500000 && V_132 < 25500000 ) {
V_35 -> V_39 = V_133 ;
} else if ( V_132 > 49500000 && V_132 < 50500000 ) {
V_35 -> V_39 = ! V_133 ;
} else {
F_9 ( V_2 , L_22 ,
V_132 ) ;
return - V_28 ;
}
}
if ( V_2 -> V_49 & V_135 ) {
V_35 -> V_38 = true ;
V_35 -> V_39 = true ;
}
return 0 ;
}
