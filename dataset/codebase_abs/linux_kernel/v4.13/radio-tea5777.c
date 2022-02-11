static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
return ( V_3 * V_6 + V_7 ) * 16 ;
case V_8 :
return ( V_3 * V_9 + V_10 ) * 16 ;
}
return 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_11 ;
V_3 = F_3 ( V_2 -> V_3 , V_12 [ V_2 -> V_4 ] . V_13 ,
V_12 [ V_2 -> V_4 ] . V_14 ) ;
V_3 = ( V_3 + 8 ) / 16 ;
switch ( V_2 -> V_4 ) {
case V_5 :
V_2 -> V_15 &= ~ V_16 ;
V_3 = ( V_3 - V_7 ) / V_6 ;
V_2 -> V_15 &= ~ V_17 ;
V_2 -> V_15 |= ( V_18 ) V_3 << V_19 ;
V_2 -> V_15 &= ~ V_20 ;
V_2 -> V_15 |= V_21 <<
V_22 ;
V_2 -> V_15 &= ~ V_23 ;
if ( V_2 -> V_24 == V_25 )
V_2 -> V_15 |= 1LL << V_26 ;
break;
case V_8 :
V_2 -> V_15 &= ~ V_16 ;
V_2 -> V_15 |= ( 1LL << V_27 ) ;
V_3 = ( V_3 - V_10 ) / V_9 ;
V_2 -> V_15 &= ~ V_28 ;
V_2 -> V_15 |= ( V_18 ) V_3 << V_29 ;
V_2 -> V_15 &= ~ V_30 ;
V_2 -> V_15 &= ~ V_30 ;
V_2 -> V_15 &= ~ V_31 ;
V_2 -> V_15 |= V_32 << V_33 ;
V_2 -> V_15 &= ~ V_34 ;
V_2 -> V_15 |= 1LL << V_35 ;
V_2 -> V_15 &= ~ V_36 ;
V_2 -> V_15 |= 1LL << V_37 ;
V_2 -> V_15 &= ~ V_38 ;
break;
}
V_11 = V_2 -> V_39 -> V_15 ( V_2 , V_2 -> V_15 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_40 = false ;
V_2 -> V_41 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_42 )
{
int V_11 ;
if ( V_2 -> V_41 != - 1 )
return 0 ;
if ( V_2 -> V_43 && V_2 -> V_40 ) {
V_11 = F_2 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_42 ) {
if ( F_5 ( F_6 ( V_42 ) ) )
return - V_44 ;
}
V_11 = V_2 -> V_39 -> V_41 ( V_2 , & V_2 -> V_41 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_40 = true ;
return 0 ;
}
static int F_7 ( struct V_45 * V_45 , void * V_46 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
F_9 ( V_48 -> V_49 , V_2 -> V_50 -> V_51 , sizeof( V_48 -> V_49 ) ) ;
F_9 ( V_48 -> V_52 , V_2 -> V_52 , sizeof( V_48 -> V_52 ) ) ;
F_10 ( V_48 -> V_52 , L_1 , sizeof( V_48 -> V_52 ) ) ;
F_9 ( V_48 -> V_53 , V_2 -> V_53 , sizeof( V_48 -> V_53 ) ) ;
V_48 -> V_54 = V_55 | V_56 ;
V_48 -> V_54 |= V_57 ;
V_48 -> V_58 = V_48 -> V_54 | V_59 ;
return 0 ;
}
static int F_11 ( struct V_45 * V_45 , void * V_46 ,
struct V_60 * V_4 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
if ( V_4 -> V_61 != 0 || V_4 -> V_62 >= F_12 ( V_12 ) ||
( ! V_2 -> V_63 && V_4 -> V_62 == V_8 ) )
return - V_64 ;
* V_4 = V_12 [ V_4 -> V_62 ] ;
return 0 ;
}
static int F_13 ( struct V_45 * V_45 , void * V_46 ,
struct V_65 * V_48 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
int V_11 ;
if ( V_48 -> V_62 > 0 )
return - V_64 ;
V_11 = F_4 ( V_2 , 0 ) ;
if ( V_11 )
return V_11 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
if ( V_2 -> V_63 )
F_9 ( V_48 -> V_51 , L_2 , sizeof( V_48 -> V_51 ) ) ;
else
F_9 ( V_48 -> V_51 , L_3 , sizeof( V_48 -> V_51 ) ) ;
V_48 -> type = V_66 ;
V_48 -> V_67 = V_68 | V_69 |
V_70 |
V_71 |
V_72 ;
V_48 -> V_13 = V_2 -> V_63 ? V_12 [ V_8 ] . V_13 :
V_12 [ V_5 ] . V_13 ;
V_48 -> V_14 = V_12 [ V_5 ] . V_14 ;
if ( V_2 -> V_4 == V_5 &&
( V_2 -> V_41 & V_73 ) )
V_48 -> V_74 = V_75 ;
else
V_48 -> V_74 = V_76 ;
V_48 -> V_24 = V_2 -> V_24 ;
V_48 -> signal = ( V_2 -> V_41 & V_77 ) >>
( V_78 - 12 ) ;
V_2 -> V_41 = - 1 ;
return 0 ;
}
static int F_14 ( struct V_45 * V_45 , void * V_46 ,
const struct V_65 * V_48 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
T_1 V_79 = V_2 -> V_24 ;
if ( V_48 -> V_62 )
return - V_64 ;
V_2 -> V_24 = V_48 -> V_24 ;
if ( V_2 -> V_24 > V_80 )
V_2 -> V_24 = V_80 ;
if ( V_2 -> V_24 != V_79 && V_2 -> V_4 == V_5 )
return F_2 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_45 * V_45 , void * V_46 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
if ( V_82 -> V_61 != 0 )
return - V_64 ;
V_82 -> type = V_66 ;
V_82 -> V_83 = V_2 -> V_3 ;
return 0 ;
}
static int F_16 ( struct V_45 * V_45 , void * V_46 ,
const struct V_81 * V_82 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
if ( V_82 -> V_61 != 0 || V_82 -> type != V_66 )
return - V_64 ;
if ( V_2 -> V_63 && V_82 -> V_83 < ( 20000 * 16 ) )
V_2 -> V_4 = V_8 ;
else
V_2 -> V_4 = V_5 ;
V_2 -> V_3 = V_82 -> V_83 ;
return F_2 ( V_2 ) ;
}
static int F_17 ( struct V_45 * V_45 , void * V_84 ,
const struct V_85 * V_86 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
unsigned long V_87 ;
T_1 V_13 = V_86 -> V_13 ;
T_1 V_14 = V_86 -> V_14 ;
int V_88 , V_11 , V_89 ;
T_1 V_90 ;
if ( V_86 -> V_61 || V_86 -> V_91 )
return - V_64 ;
if ( V_45 -> V_92 & V_93 )
return - V_94 ;
if ( V_13 || V_14 ) {
for ( V_88 = 0 ; V_88 < F_12 ( V_12 ) ; V_88 ++ ) {
if ( V_88 == V_8 && ! V_2 -> V_63 )
continue;
if ( V_12 [ V_88 ] . V_13 >= V_13 &&
V_12 [ V_88 ] . V_14 <= V_14 )
break;
}
if ( V_88 == F_12 ( V_12 ) )
return - V_64 ;
V_2 -> V_4 = V_88 ;
if ( V_2 -> V_3 < V_13 || V_2 -> V_3 > V_14 ) {
V_2 -> V_3 = F_3 ( V_2 -> V_3 , V_13 ,
V_14 ) ;
V_11 = F_2 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
} else {
V_13 = V_12 [ V_2 -> V_4 ] . V_13 ;
V_14 = V_12 [ V_2 -> V_4 ] . V_14 ;
}
V_89 = ( V_2 -> V_4 == V_8 ) ? ( 5 * 16 ) : ( 200 * 16 ) ;
V_90 = V_2 -> V_3 ;
V_2 -> V_15 |= V_95 ;
if ( V_2 -> V_96 != V_13 ) {
V_2 -> V_15 &= ~ V_97 ;
V_2 -> V_3 = V_13 ;
V_11 = F_2 ( V_2 ) ;
if ( V_11 )
goto V_98;
V_2 -> V_96 = V_13 ;
}
if ( V_2 -> V_99 != V_14 ) {
V_2 -> V_15 |= V_97 ;
V_2 -> V_3 = V_14 ;
V_11 = F_2 ( V_2 ) ;
if ( V_11 )
goto V_98;
V_2 -> V_99 = V_14 ;
}
V_2 -> V_15 &= ~ V_95 ;
V_2 -> V_15 |= V_100 ;
if ( V_86 -> V_101 ) {
V_2 -> V_15 |= V_97 ;
V_2 -> V_3 = V_90 + V_89 ;
} else {
V_2 -> V_15 &= ~ V_97 ;
V_2 -> V_3 = V_90 - V_89 ;
}
V_11 = F_2 ( V_2 ) ;
if ( V_11 )
goto V_98;
V_87 = V_102 + F_6 ( 5000 ) ;
for (; ; ) {
if ( F_18 ( V_102 , V_87 ) ) {
V_11 = - V_103 ;
break;
}
V_11 = F_4 ( V_2 , 100 ) ;
if ( V_11 )
break;
V_2 -> V_3 = ( V_2 -> V_41 & V_104 ) ;
V_2 -> V_3 = F_1 ( V_2 , V_2 -> V_3 ) ;
if ( ( V_2 -> V_41 & V_105 ) ) {
V_2 -> V_15 &= ~ V_100 ;
return 0 ;
}
if ( V_2 -> V_41 & V_106 ) {
V_11 = - V_103 ;
break;
}
V_2 -> V_41 = - 1 ;
}
V_98:
V_2 -> V_15 &= ~ V_95 ;
V_2 -> V_15 &= ~ V_100 ;
V_2 -> V_3 = V_90 ;
F_2 ( V_2 ) ;
return V_11 ;
}
static int F_19 ( struct V_107 * V_108 )
{
struct V_1 * V_2 =
F_20 ( V_108 -> V_109 , struct V_1 , V_110 ) ;
switch ( V_108 -> V_111 ) {
case V_112 :
if ( V_108 -> V_113 )
V_2 -> V_15 |= V_114 ;
else
V_2 -> V_15 &= ~ V_114 ;
return F_2 ( V_2 ) ;
}
return - V_64 ;
}
int F_21 ( struct V_1 * V_2 , struct V_115 * V_116 )
{
int V_11 ;
V_2 -> V_15 = ( 1LL << V_117 ) |
( 1LL << V_118 ) |
( 1LL << V_119 ) |
( 1LL << V_120 ) |
( 1LL << V_121 ) ;
V_2 -> V_3 = 90500 * 16 ;
V_2 -> V_24 = V_80 ;
V_11 = F_2 ( V_2 ) ;
if ( V_11 ) {
F_22 ( V_2 -> V_50 , L_4 , V_11 ) ;
return V_11 ;
}
V_2 -> V_122 = V_123 ;
F_23 ( & V_2 -> V_122 , V_2 ) ;
F_24 ( & V_2 -> V_124 ) ;
F_9 ( V_2 -> V_122 . V_51 , V_2 -> V_50 -> V_51 , sizeof( V_2 -> V_122 . V_51 ) ) ;
V_2 -> V_122 . V_125 = & V_2 -> V_124 ;
V_2 -> V_122 . V_50 = V_2 -> V_50 ;
V_2 -> V_126 = V_127 ;
V_2 -> V_126 . V_116 = V_116 ;
V_2 -> V_122 . V_126 = & V_2 -> V_126 ;
V_2 -> V_122 . V_110 = & V_2 -> V_110 ;
F_25 ( & V_2 -> V_110 , 1 ) ;
F_26 ( & V_2 -> V_110 , & V_128 ,
V_112 , 0 , 1 , 1 , 1 ) ;
V_11 = V_2 -> V_110 . error ;
if ( V_11 ) {
F_22 ( V_2 -> V_50 , L_5 ) ;
F_27 ( & V_2 -> V_110 ) ;
return V_11 ;
}
F_28 ( & V_2 -> V_110 ) ;
V_11 = F_29 ( & V_2 -> V_122 , V_129 , - 1 ) ;
if ( V_11 ) {
F_22 ( V_2 -> V_50 , L_6 ) ;
F_27 ( V_2 -> V_122 . V_110 ) ;
return V_11 ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_122 ) ;
F_27 ( V_2 -> V_122 . V_110 ) ;
}
