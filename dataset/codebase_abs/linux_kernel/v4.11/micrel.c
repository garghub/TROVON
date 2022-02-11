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
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 . V_45 . V_43 ;
if ( F_14 ( V_43 , L_5 ) ) {
V_2 -> V_46 |= V_47 ;
V_2 -> V_48 &= V_49 |
V_50 ;
V_2 -> V_48 |= V_51 ;
V_2 -> V_52 &= V_53 |
V_54 ;
V_2 -> V_52 |= V_55 ;
V_2 -> V_56 = V_57 ;
}
return F_12 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 & V_47 ) {
V_2 -> V_58 = V_59 ;
return 0 ;
}
return F_16 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_42 * V_43 ,
T_2 V_24 ,
const char * V_60 , const char * V_61 ,
const char * V_62 , const char * V_63 )
{
int V_64 = - 1 ;
int V_65 = - 2 ;
int V_66 = - 3 ;
int V_67 = - 4 ;
int V_68 ;
int V_69 = 0 ;
if ( ! F_18 ( V_43 , V_60 , & V_64 ) )
V_69 ++ ;
if ( ! F_18 ( V_43 , V_61 , & V_65 ) )
V_69 ++ ;
if ( ! F_18 ( V_43 , V_62 , & V_66 ) )
V_69 ++ ;
if ( ! F_18 ( V_43 , V_63 , & V_67 ) )
V_69 ++ ;
if ( ! V_69 )
return 0 ;
if ( V_69 < 4 )
V_68 = F_3 ( V_2 , V_24 ) ;
else
V_68 = 0 ;
if ( V_64 != - 1 )
V_68 = ( ( V_68 & 0xfff0 ) | ( ( V_64 / V_70 ) & 0xf ) << 0 ) ;
if ( V_65 != - 2 )
V_68 = ( ( V_68 & 0xff0f ) | ( ( V_65 / V_70 ) & 0xf ) << 4 ) ;
if ( V_66 != - 3 )
V_68 = ( ( V_68 & 0xf0ff ) | ( ( V_66 / V_70 ) & 0xf ) << 8 ) ;
if ( V_67 != - 4 )
V_68 = ( ( V_68 & 0x0fff ) | ( ( V_67 / V_70 ) & 0xf ) << 12 ) ;
return F_1 ( V_2 , V_24 , V_68 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_71 * V_45 = & V_2 -> V_44 . V_45 ;
const struct V_42 * V_43 = V_45 -> V_43 ;
const struct V_71 * V_72 ;
V_72 = & V_2 -> V_44 . V_45 ;
do {
V_43 = V_72 -> V_43 ;
V_72 = V_72 -> V_73 ;
} while ( ! V_43 && V_72 );
if ( V_43 ) {
F_17 ( V_2 , V_43 ,
V_74 ,
L_6 , L_7 ,
L_8 , L_9 ) ;
F_17 ( V_2 , V_43 ,
V_75 ,
L_10 , L_11 ,
L_12 , L_13 ) ;
F_17 ( V_2 , V_43 ,
V_76 ,
L_14 , L_15 ,
L_16 , L_17 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_3 V_77 , T_1 V_78 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_79 , V_78 ) ;
F_2 ( V_2 , V_80 , V_3 ) ;
F_2 ( V_2 , V_79 , ( V_77 << 14 ) | V_78 ) ;
return F_2 ( V_2 , V_80 , V_4 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_77 , T_1 V_78 , T_1 V_3 )
{
F_2 ( V_2 , V_79 , V_78 ) ;
F_2 ( V_2 , V_80 , V_3 ) ;
F_2 ( V_2 , V_79 , ( V_77 << 14 ) | V_78 ) ;
return F_4 ( V_2 , V_80 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_42 * V_43 ,
T_2 V_24 , T_4 V_81 ,
const char * V_82 [] , T_3 V_83 )
{
int V_4 [ 4 ] = { - 1 , - 2 , - 3 , - 4 } ;
int V_69 = 0 ;
T_2 V_15 ;
T_2 V_84 ;
T_2 V_68 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_83 ; V_85 ++ )
if ( ! F_18 ( V_43 , V_82 [ V_85 ] , V_4 + V_85 ) )
V_69 ++ ;
if ( ! V_69 )
return 0 ;
if ( V_69 < V_83 )
V_68 = F_21 ( V_2 , V_86 , 2 , V_24 ) ;
else
V_68 = 0 ;
V_84 = ( V_81 == 4 ) ? 0xf : 0x1f ;
for ( V_85 = 0 ; V_85 < V_83 ; V_85 ++ )
if ( V_4 [ V_85 ] != - ( V_85 + 1 ) ) {
V_15 = 0xffff ;
V_15 ^= V_84 << ( V_81 * V_85 ) ;
V_68 = ( V_68 & V_15 ) |
( ( ( V_4 [ V_85 ] / V_87 ) & V_84 )
<< ( V_81 * V_85 ) ) ;
}
return F_20 ( V_2 , V_86 , 2 , V_24 , V_68 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = F_20 ( V_2 , V_86 , 0 ,
V_89 , 0x0006 ) ;
V_88 = F_20 ( V_2 , V_86 , 0 ,
V_90 , 0x1A80 ) ;
if ( V_88 )
return V_88 ;
return F_24 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_21 ( V_2 , V_86 , 0x1C , V_91 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_20 ( V_2 , V_86 , 0x1C , V_91 ,
V_24 | V_92 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
const struct V_71 * V_45 = & V_2 -> V_44 . V_45 ;
const struct V_42 * V_43 = V_45 -> V_43 ;
static const char * V_93 [ 2 ] = { L_9 , L_7 } ;
static const char * V_94 [ 4 ] = {
L_10 , L_11 ,
L_12 , L_13
} ;
static const char * V_95 [ 4 ] = {
L_14 , L_15 ,
L_16 , L_17
} ;
static const char * V_96 [ 2 ] = { L_6 , L_8 } ;
const struct V_71 * V_72 ;
int V_88 ;
V_88 = F_25 ( V_2 ) ;
if ( V_88 < 0 )
return V_88 ;
V_72 = & V_2 -> V_44 . V_45 ;
do {
V_43 = V_72 -> V_43 ;
V_72 = V_72 -> V_73 ;
} while ( ! V_43 && V_72 );
if ( V_43 ) {
F_22 ( V_2 , V_43 ,
V_97 , 5 ,
V_93 , 2 ) ;
F_22 ( V_2 , V_43 ,
V_98 , 4 ,
V_96 , 2 ) ;
F_22 ( V_2 , V_43 ,
V_99 , 4 ,
V_94 , 4 ) ;
F_22 ( V_2 , V_43 ,
V_100 , 4 ,
V_95 , 4 ) ;
}
return F_23 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_101 ;
V_101 = F_4 ( V_2 , V_102 ) ;
V_101 = F_4 ( V_2 , V_102 ) ;
if ( V_101 & V_103 )
V_2 -> V_104 = V_105 ;
else
V_2 -> V_104 = V_106 ;
if ( V_101 & V_107 )
V_2 -> V_58 = V_108 ;
else
V_2 -> V_58 = V_59 ;
V_2 -> V_109 = 1 ;
V_2 -> V_110 = V_2 -> V_111 = 0 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_112 ;
int V_101 ;
V_112 = F_29 ( V_2 ) ;
if ( V_112 )
return V_112 ;
V_101 = F_4 ( V_2 , V_113 ) ;
if ( ( V_101 & 0xFF ) == 0xFF ) {
F_30 ( V_2 ) ;
V_2 -> V_109 = 0 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_32 ( struct V_1 * V_2 , int V_114 , int V_115 ,
int V_3 )
{
return - 1 ;
}
static void
F_33 ( struct V_1 * V_2 , int V_114 , int V_115 ,
int V_3 , T_1 V_4 )
{
}
static int F_34 ( struct V_1 * V_2 )
{
return F_35 ( V_116 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_3 * V_117 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < F_35 ( V_116 ) ; V_85 ++ ) {
memcpy ( V_117 + V_85 * V_118 ,
V_116 [ V_85 ] . string , V_118 ) ;
}
}
static T_5 F_37 ( struct V_1 * V_2 , int V_85 )
{
struct V_119 V_120 = V_116 [ V_85 ] ;
struct V_34 * V_35 = V_2 -> V_35 ;
int V_4 ;
T_5 V_30 ;
V_4 = F_4 ( V_2 , V_120 . V_24 ) ;
if ( V_4 < 0 ) {
V_30 = V_121 ;
} else {
V_4 = V_4 & ( ( 1 << V_120 . V_122 ) - 1 ) ;
V_35 -> V_123 [ V_85 ] += V_4 ;
V_30 = V_35 -> V_123 [ V_85 ] ;
}
return V_30 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_124 * V_123 , T_5 * V_117 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < F_35 ( V_116 ) ; V_85 ++ )
V_117 [ V_85 ] = F_37 ( V_2 , V_85 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( F_40 ( V_2 ) ) {
V_2 -> V_19 = V_125 ;
if ( V_2 -> V_12 -> V_126 )
V_2 -> V_12 -> V_126 ( V_2 ) ;
}
return F_41 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
if ( F_40 ( V_2 ) ) {
V_2 -> V_19 = V_20 ;
if ( V_2 -> V_12 -> V_126 )
V_2 -> V_12 -> V_126 ( V_2 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
const struct V_42 * V_127 = V_2 -> V_44 . V_45 . V_43 ;
struct V_34 * V_35 ;
struct V_128 * V_128 ;
int V_30 ;
V_35 = F_45 ( & V_2 -> V_44 . V_45 , sizeof( * V_35 ) , V_129 ) ;
if ( ! V_35 )
return - V_130 ;
V_2 -> V_35 = V_35 ;
V_35 -> type = type ;
if ( type -> V_41 ) {
V_30 = F_18 ( V_127 , L_18 ,
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
V_128 = F_46 ( & V_2 -> V_44 . V_45 , L_20 ) ;
if ( ! F_47 ( V_128 ) ) {
unsigned long V_131 = F_48 ( V_128 ) ;
bool V_132 ;
V_35 -> V_38 = type -> V_133 ;
V_132 = F_14 ( V_127 ,
L_21 ) ;
if ( V_131 > 24500000 && V_131 < 25500000 ) {
V_35 -> V_39 = V_132 ;
} else if ( V_131 > 49500000 && V_131 < 50500000 ) {
V_35 -> V_39 = ! V_132 ;
} else {
F_9 ( V_2 , L_22 ,
V_131 ) ;
return - V_28 ;
}
}
if ( V_2 -> V_46 & V_134 ) {
V_35 -> V_38 = true ;
V_35 -> V_39 = true ;
}
return 0 ;
}
