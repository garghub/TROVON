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
static int F_14 ( struct V_1 * V_2 ,
const struct V_45 * V_46 ,
T_2 V_24 ,
const char * V_47 , const char * V_48 ,
const char * V_49 , const char * V_50 )
{
int V_51 = - 1 ;
int V_52 = - 2 ;
int V_53 = - 3 ;
int V_54 = - 4 ;
int V_55 ;
int V_56 = 0 ;
if ( ! F_15 ( V_46 , V_47 , & V_51 ) )
V_56 ++ ;
if ( ! F_15 ( V_46 , V_48 , & V_52 ) )
V_56 ++ ;
if ( ! F_15 ( V_46 , V_49 , & V_53 ) )
V_56 ++ ;
if ( ! F_15 ( V_46 , V_50 , & V_54 ) )
V_56 ++ ;
if ( ! V_56 )
return 0 ;
if ( V_56 < 4 )
V_55 = F_3 ( V_2 , V_24 ) ;
else
V_55 = 0 ;
if ( V_51 != - 1 )
V_55 = ( ( V_55 & 0xfff0 ) | ( ( V_51 / V_57 ) & 0xf ) << 0 ) ;
if ( V_52 != - 2 )
V_55 = ( ( V_55 & 0xff0f ) | ( ( V_52 / V_57 ) & 0xf ) << 4 ) ;
if ( V_53 != - 3 )
V_55 = ( ( V_55 & 0xf0ff ) | ( ( V_53 / V_57 ) & 0xf ) << 8 ) ;
if ( V_54 != - 4 )
V_55 = ( ( V_55 & 0x0fff ) | ( ( V_54 / V_57 ) & 0xf ) << 12 ) ;
return F_1 ( V_2 , V_24 , V_55 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
const struct V_58 * V_59 = & V_2 -> V_60 . V_59 ;
const struct V_45 * V_46 = V_59 -> V_46 ;
const struct V_58 * V_61 ;
V_61 = & V_2 -> V_60 . V_59 ;
do {
V_46 = V_61 -> V_46 ;
V_61 = V_61 -> V_62 ;
} while ( ! V_46 && V_61 );
if ( V_46 ) {
F_14 ( V_2 , V_46 ,
V_63 ,
L_5 , L_6 ,
L_7 , L_8 ) ;
F_14 ( V_2 , V_46 ,
V_64 ,
L_9 , L_10 ,
L_11 , L_12 ) ;
F_14 ( V_2 , V_46 ,
V_65 ,
L_13 , L_14 ,
L_15 , L_16 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_3 V_66 , T_1 V_67 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_68 , V_67 ) ;
F_2 ( V_2 , V_69 , V_3 ) ;
F_2 ( V_2 , V_68 , ( V_66 << 14 ) | V_67 ) ;
return F_2 ( V_2 , V_69 , V_4 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
T_3 V_66 , T_1 V_67 , T_1 V_3 )
{
F_2 ( V_2 , V_68 , V_67 ) ;
F_2 ( V_2 , V_69 , V_3 ) ;
F_2 ( V_2 , V_68 , ( V_66 << 14 ) | V_67 ) ;
return F_4 ( V_2 , V_69 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_45 * V_46 ,
T_2 V_24 , T_4 V_70 ,
const char * V_71 [] , T_3 V_72 )
{
int V_4 [ 4 ] = { - 1 , - 2 , - 3 , - 4 } ;
int V_56 = 0 ;
T_2 V_15 ;
T_2 V_73 ;
T_2 V_55 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ )
if ( ! F_15 ( V_46 , V_71 [ V_74 ] , V_4 + V_74 ) )
V_56 ++ ;
if ( ! V_56 )
return 0 ;
if ( V_56 < V_72 )
V_55 = F_18 ( V_2 , V_75 , 2 , V_24 ) ;
else
V_55 = 0 ;
V_73 = ( V_70 == 4 ) ? 0xf : 0x1f ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ )
if ( V_4 [ V_74 ] != - ( V_74 + 1 ) ) {
V_15 = 0xffff ;
V_15 ^= V_73 << ( V_70 * V_74 ) ;
V_55 = ( V_55 & V_15 ) |
( ( ( V_4 [ V_74 ] / V_76 ) & V_73 )
<< ( V_70 * V_74 ) ) ;
}
return F_17 ( V_2 , V_75 , 2 , V_24 , V_55 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_77 ;
V_77 = F_17 ( V_2 , V_75 , 0 ,
V_78 , 0x0006 ) ;
V_77 = F_17 ( V_2 , V_75 , 0 ,
V_79 , 0x1A80 ) ;
if ( V_77 )
return V_77 ;
return F_21 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_58 * V_59 = & V_2 -> V_60 . V_59 ;
const struct V_45 * V_46 = V_59 -> V_46 ;
static const char * V_80 [ 2 ] = { L_8 , L_6 } ;
static const char * V_81 [ 4 ] = {
L_9 , L_10 ,
L_11 , L_12
} ;
static const char * V_82 [ 4 ] = {
L_13 , L_14 ,
L_15 , L_16
} ;
static const char * V_83 [ 2 ] = { L_5 , L_7 } ;
const struct V_58 * V_61 ;
V_61 = & V_2 -> V_60 . V_59 ;
do {
V_46 = V_61 -> V_46 ;
V_61 = V_61 -> V_62 ;
} while ( ! V_46 && V_61 );
if ( V_46 ) {
F_19 ( V_2 , V_46 ,
V_84 , 5 ,
V_80 , 2 ) ;
F_19 ( V_2 , V_46 ,
V_85 , 4 ,
V_83 , 2 ) ;
F_19 ( V_2 , V_46 ,
V_86 , 4 ,
V_81 , 4 ) ;
F_19 ( V_2 , V_46 ,
V_87 , 4 ,
V_82 , 4 ) ;
}
return F_20 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = F_4 ( V_2 , V_89 ) ;
V_88 = F_4 ( V_2 , V_89 ) ;
if ( V_88 & V_90 )
V_2 -> V_91 = V_92 ;
else
V_2 -> V_91 = V_93 ;
if ( V_88 & V_94 )
V_2 -> V_95 = V_96 ;
else
V_2 -> V_95 = V_97 ;
V_2 -> V_98 = 1 ;
V_2 -> V_99 = V_2 -> V_100 = 0 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_101 ;
int V_88 ;
V_101 = F_25 ( V_2 ) ;
if ( V_101 )
return V_101 ;
V_88 = F_4 ( V_2 , V_102 ) ;
if ( ( V_88 & 0xFF ) == 0xFF ) {
F_26 ( V_2 ) ;
V_2 -> V_98 = 0 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_28 ( struct V_1 * V_2 , int V_103 , int V_104 ,
int V_3 )
{
return - 1 ;
}
static void
F_29 ( struct V_1 * V_2 , int V_103 , int V_104 ,
int V_3 , T_1 V_4 )
{
}
static int F_30 ( struct V_1 * V_2 )
{
return F_31 ( V_105 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_3 * V_106 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < F_31 ( V_105 ) ; V_74 ++ ) {
memcpy ( V_106 + V_74 * V_107 ,
V_105 [ V_74 ] . string , V_107 ) ;
}
}
static T_5 F_33 ( struct V_1 * V_2 , int V_74 )
{
struct V_108 V_109 = V_105 [ V_74 ] ;
struct V_34 * V_35 = V_2 -> V_35 ;
T_5 V_4 ;
V_4 = F_4 ( V_2 , V_109 . V_24 ) ;
if ( V_4 < 0 ) {
V_4 = V_110 ;
} else {
V_4 = V_4 & ( ( 1 << V_109 . V_111 ) - 1 ) ;
V_35 -> V_112 [ V_74 ] += V_4 ;
V_4 = V_35 -> V_112 [ V_74 ] ;
}
return V_4 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_113 * V_112 , T_5 * V_106 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < F_31 ( V_105 ) ; V_74 ++ )
V_106 [ V_74 ] = F_33 ( V_2 , V_74 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_114 ;
F_36 ( & V_2 -> V_115 ) ;
V_114 = F_4 ( V_2 , V_43 ) ;
F_2 ( V_2 , V_43 , V_114 & ~ V_116 ) ;
F_6 ( V_2 ) ;
F_37 ( & V_2 -> V_115 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
const struct V_45 * V_117 = V_2 -> V_60 . V_59 . V_46 ;
struct V_34 * V_35 ;
struct V_118 * V_118 ;
int V_30 ;
V_35 = F_39 ( & V_2 -> V_60 . V_59 , sizeof( * V_35 ) , V_119 ) ;
if ( ! V_35 )
return - V_120 ;
V_2 -> V_35 = V_35 ;
V_35 -> type = type ;
if ( type -> V_41 ) {
V_30 = F_15 ( V_117 , L_17 ,
& V_35 -> V_40 ) ;
if ( V_30 )
V_35 -> V_40 = - 1 ;
if ( V_35 -> V_40 > 3 ) {
F_9 ( V_2 , L_18 ,
V_35 -> V_40 ) ;
V_35 -> V_40 = - 1 ;
}
} else {
V_35 -> V_40 = - 1 ;
}
V_118 = F_40 ( & V_2 -> V_60 . V_59 , L_19 ) ;
if ( ! F_41 ( V_118 ) ) {
unsigned long V_121 = F_42 ( V_118 ) ;
bool V_122 ;
V_35 -> V_38 = type -> V_123 ;
V_122 = F_43 ( V_117 ,
L_20 ) ;
if ( V_121 > 24500000 && V_121 < 25500000 ) {
V_35 -> V_39 = V_122 ;
} else if ( V_121 > 49500000 && V_121 < 50500000 ) {
V_35 -> V_39 = ! V_122 ;
} else {
F_9 ( V_2 , L_21 ,
V_121 ) ;
return - V_28 ;
}
}
if ( V_2 -> V_124 & V_125 ) {
V_35 -> V_38 = true ;
V_35 -> V_39 = true ;
}
return 0 ;
}
