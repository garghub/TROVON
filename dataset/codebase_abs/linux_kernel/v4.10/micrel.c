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
V_53 ;
V_2 -> V_51 |= V_54 ;
V_2 -> V_55 &= V_56 |
V_57 ;
V_2 -> V_55 |= V_58 ;
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
int V_24 ;
V_24 = F_22 ( V_2 , V_89 , 0x1C , V_94 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_21 ( V_2 , V_89 , 0x1C , V_94 ,
V_24 | V_95 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
const struct V_74 * V_48 = & V_2 -> V_47 . V_48 ;
const struct V_45 * V_46 = V_48 -> V_46 ;
static const char * V_96 [ 2 ] = { L_9 , L_7 } ;
static const char * V_97 [ 4 ] = {
L_10 , L_11 ,
L_12 , L_13
} ;
static const char * V_98 [ 4 ] = {
L_14 , L_15 ,
L_16 , L_17
} ;
static const char * V_99 [ 2 ] = { L_6 , L_8 } ;
const struct V_74 * V_75 ;
int V_91 ;
V_91 = F_26 ( V_2 ) ;
if ( V_91 < 0 )
return V_91 ;
V_75 = & V_2 -> V_47 . V_48 ;
do {
V_46 = V_75 -> V_46 ;
V_75 = V_75 -> V_76 ;
} while ( ! V_46 && V_75 );
if ( V_46 ) {
F_23 ( V_2 , V_46 ,
V_100 , 5 ,
V_96 , 2 ) ;
F_23 ( V_2 , V_46 ,
V_101 , 4 ,
V_99 , 2 ) ;
F_23 ( V_2 , V_46 ,
V_102 , 4 ,
V_97 , 4 ) ;
F_23 ( V_2 , V_46 ,
V_103 , 4 ,
V_98 , 4 ) ;
}
return F_24 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_104 ;
V_104 = F_4 ( V_2 , V_105 ) ;
V_104 = F_4 ( V_2 , V_105 ) ;
if ( V_104 & V_106 )
V_2 -> V_107 = V_108 ;
else
V_2 -> V_107 = V_109 ;
if ( V_104 & V_110 )
V_2 -> V_61 = V_111 ;
else
V_2 -> V_61 = V_62 ;
V_2 -> V_112 = 1 ;
V_2 -> V_113 = V_2 -> V_114 = 0 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_115 ;
int V_104 ;
V_115 = F_30 ( V_2 ) ;
if ( V_115 )
return V_115 ;
V_104 = F_4 ( V_2 , V_116 ) ;
if ( ( V_104 & 0xFF ) == 0xFF ) {
F_31 ( V_2 ) ;
V_2 -> V_112 = 0 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 , int V_117 , int V_118 ,
int V_3 )
{
return - 1 ;
}
static void
F_34 ( struct V_1 * V_2 , int V_117 , int V_118 ,
int V_3 , T_1 V_4 )
{
}
static int F_35 ( struct V_1 * V_2 )
{
return F_36 ( V_119 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_3 * V_120 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < F_36 ( V_119 ) ; V_88 ++ ) {
memcpy ( V_120 + V_88 * V_121 ,
V_119 [ V_88 ] . string , V_121 ) ;
}
}
static T_5 F_38 ( struct V_1 * V_2 , int V_88 )
{
struct V_122 V_123 = V_119 [ V_88 ] ;
struct V_34 * V_35 = V_2 -> V_35 ;
int V_4 ;
T_5 V_30 ;
V_4 = F_4 ( V_2 , V_123 . V_24 ) ;
if ( V_4 < 0 ) {
V_30 = V_124 ;
} else {
V_4 = V_4 & ( ( 1 << V_123 . V_125 ) - 1 ) ;
V_35 -> V_126 [ V_88 ] += V_4 ;
V_30 = V_35 -> V_126 [ V_88 ] ;
}
return V_30 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_127 * V_126 , T_5 * V_120 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < F_36 ( V_119 ) ; V_88 ++ )
V_120 [ V_88 ] = F_38 ( V_2 , V_88 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) ) {
V_2 -> V_19 = V_128 ;
if ( V_2 -> V_12 -> V_129 )
V_2 -> V_12 -> V_129 ( V_2 ) ;
}
return F_41 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
if ( F_13 ( V_2 ) ) {
V_2 -> V_19 = V_20 ;
if ( V_2 -> V_12 -> V_129 )
V_2 -> V_12 -> V_129 ( V_2 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
const struct V_45 * V_130 = V_2 -> V_47 . V_48 . V_46 ;
struct V_34 * V_35 ;
struct V_131 * V_131 ;
int V_30 ;
V_35 = F_45 ( & V_2 -> V_47 . V_48 , sizeof( * V_35 ) , V_132 ) ;
if ( ! V_35 )
return - V_133 ;
V_2 -> V_35 = V_35 ;
V_35 -> type = type ;
if ( type -> V_41 ) {
V_30 = F_19 ( V_130 , L_18 ,
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
V_131 = F_46 ( & V_2 -> V_47 . V_48 , L_20 ) ;
if ( ! F_47 ( V_131 ) ) {
unsigned long V_134 = F_48 ( V_131 ) ;
bool V_135 ;
V_35 -> V_38 = type -> V_136 ;
V_135 = F_15 ( V_130 ,
L_21 ) ;
if ( V_134 > 24500000 && V_134 < 25500000 ) {
V_35 -> V_39 = V_135 ;
} else if ( V_134 > 49500000 && V_134 < 50500000 ) {
V_35 -> V_39 = ! V_135 ;
} else {
F_9 ( V_2 , L_22 ,
V_134 ) ;
return - V_28 ;
}
}
if ( V_2 -> V_49 & V_137 ) {
V_35 -> V_38 = true ;
V_35 -> V_39 = true ;
}
return 0 ;
}
