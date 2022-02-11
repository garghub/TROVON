static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_5 , V_2 ) ;
return F_3 ( V_1 -> V_6 [ V_7 ] , V_4 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_8 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_5 , V_2 ) ;
return F_5 ( V_1 -> V_6 [ V_7 ] , V_4 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_9 , V_2 ) ;
return F_3 ( V_1 -> V_6 [ V_7 ] , V_4 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_8 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_9 , V_2 ) ;
return F_5 ( V_1 -> V_6 [ V_7 ] , V_4 , V_8 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= V_17 ;
V_2 >>= V_18 ;
return ! ! ( V_2 ) ;
}
static int F_11 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= ~ V_19 ;
if ( V_13 -> V_20 [ V_14 ] )
V_2 |= V_13 -> V_20 [ V_14 ] ;
else
V_2 |= V_21 ;
F_4 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= ~ V_19 ;
F_4 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , unsigned int V_22 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
bool V_23 = true ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= ~ V_19 ;
if ( V_2 == V_24 )
V_23 = false ;
switch ( V_22 ) {
case V_25 :
V_2 |= V_21 ;
break;
case V_26 :
V_2 |= V_27 ;
break;
case V_28 :
V_2 |= V_29 ;
break;
default:
return - V_30 ;
}
V_13 -> V_20 [ V_14 ] = V_2 & V_19 ;
if ( V_23 )
F_4 ( V_13 -> V_1 ,
V_15 [ V_14 ] . V_16 , V_2 ) ;
return 0 ;
}
static unsigned int F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
V_2 = V_13 -> V_20 [ V_14 ] & V_19 ;
switch ( V_2 ) {
case V_21 :
return V_25 ;
case V_27 :
return V_26 ;
case V_29 :
return V_28 ;
}
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
unsigned V_31 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
int V_32 = 1 ;
if ( V_13 -> V_33 [ V_14 ] )
V_32 = 2 ;
if ( V_31 == 0 )
return 0 ;
else if ( V_31 < 6 )
return 500000 * V_32 ;
else
return ( 490000 + ( ( V_31 - 5 ) * 10000 ) ) * V_32 ;
}
static int F_16 ( struct V_10 * V_34 ,
int V_35 , int V_36 )
{
struct V_12 * V_13 = F_9 ( V_34 ) ;
int V_14 = F_10 ( V_34 ) ;
int V_37 , V_38 ;
if ( V_35 == 0 )
return 0 ;
if ( V_13 -> V_33 [ V_14 ] ) {
if ( V_35 < 1000000 )
V_35 = 1000000 ;
V_37 = F_17 ( V_35 - 1000000 , 20000 ) + 6 ;
} else {
if ( V_35 < 500000 )
V_35 = 500000 ;
V_37 = F_17 ( V_35 - 500000 , 10000 ) + 6 ;
}
V_38 = F_15 ( V_34 , V_37 ) ;
if ( V_38 < V_35 || V_38 > V_36 )
return - V_30 ;
return V_37 ;
}
static int F_18 ( struct V_10 * V_34 ,
unsigned int V_39 , unsigned int V_40 )
{
struct V_12 * V_13 = F_9 ( V_34 ) ;
int V_14 = F_10 ( V_34 ) ;
int V_41 , V_42 ;
unsigned int V_43 = V_13 -> V_43 [ V_14 ] ;
if ( ! V_43 )
return 0 ;
V_41 = F_15 ( V_34 , V_39 ) ;
if ( V_41 < 0 )
return V_41 ;
V_42 = F_15 ( V_34 , V_40 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_17 ( abs ( V_41 - V_42 ) , V_43 ) ;
}
static int F_19 ( struct V_10 * V_34 ,
int V_43 )
{
struct V_12 * V_13 = F_9 ( V_34 ) ;
int V_14 = F_10 ( V_34 ) ;
unsigned int V_2 = 0 ;
unsigned int V_4 = V_15 [ V_14 ] . V_44 ;
int V_37 ;
switch ( V_14 ) {
case V_45 :
case V_46 :
return 0 ;
}
if ( V_43 <= 0 )
V_2 = 0 ;
else if ( V_43 <= 2500 )
V_2 = 3 ;
else if ( V_43 <= 5000 )
V_2 = 2 ;
else
V_2 = 1 ;
V_37 = F_4 ( V_13 -> V_1 , V_4 , V_2 ) ;
if ( V_37 < 0 ) {
F_20 ( V_13 -> V_1 -> V_11 , L_1 , V_37 ) ;
return V_37 ;
}
V_13 -> V_43 [ V_14 ] = V_47 [ V_2 ] ;
return V_37 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_6 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= V_48 ;
return ! ! ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_1 , int V_14 ,
struct V_49 * V_50 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_37 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
switch ( V_14 ) {
case V_51 :
case V_52 :
V_2 &= ~ V_53 ;
if ( V_50 -> V_54 )
V_2 |= V_50 -> V_54 <<
V_55 ;
break;
default:
if ( V_50 -> V_56 )
V_2 |= V_57 ;
else
V_2 &= ~ V_57 ;
if ( V_50 -> V_58 )
V_2 |= V_59 ;
else
V_2 &= ~ V_59 ;
V_2 &= ~ V_60 ;
if ( V_50 -> V_54 )
V_2 |= V_50 -> V_54 <<
V_61 ;
}
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_15 [ V_14 ] . V_62 && V_50 -> V_63 ) {
V_4 = V_15 [ V_14 ] . V_62 ;
V_2 = V_50 -> V_63 ;
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , int V_14 ,
struct V_49 * V_50 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_37 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_50 -> V_56 )
V_2 |= V_64 ;
else
V_2 &= ~ V_64 ;
if ( V_50 -> V_54 )
V_2 |= V_65 ;
else
V_2 &= ~ V_65 ;
V_37 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , int V_14 ,
struct V_49 * V_50 )
{
unsigned int V_4 ;
int V_37 ;
unsigned int V_66 = 0 ;
V_4 = V_15 [ V_14 ] . V_16 ;
if ( V_50 -> V_54 )
V_66 = V_67 ;
V_37 = F_25 ( V_1 , V_68 ,
V_4 , V_67 , V_66 ) ;
if ( V_37 < 0 ) {
F_20 ( V_1 -> V_11 , L_2 ,
V_4 , V_37 ) ;
return V_37 ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
V_4 = V_15 [ V_69 ] . V_16 ;
V_37 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 ) {
F_20 ( V_1 -> V_11 , L_3 ) ;
return;
}
V_2 |= V_70 ;
V_37 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_37 < 0 ) {
F_20 ( V_1 -> V_11 , L_4 ) ;
return;
}
V_4 = V_15 [ V_69 ] . V_62 ;
V_37 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 ) {
F_20 ( V_1 -> V_11 , L_5 ) ;
return;
}
V_2 = ( V_2 << 1 ) & V_71 ;
V_37 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_37 < 0 )
F_20 ( V_1 -> V_11 , L_6 ) ;
return;
}
static void F_27 ( struct V_72 * V_11 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_73 * V_77 ;
T_1 V_78 ;
int V_79 , V_37 ;
V_74 = F_28 ( V_74 ) ;
V_77 = F_29 ( V_74 , L_7 ) ;
if ( ! V_77 ) {
F_30 ( V_11 , L_8 ) ;
return;
}
V_37 = F_31 ( V_11 , V_77 , V_80 ,
V_81 ) ;
F_32 ( V_77 ) ;
if ( V_37 < 0 ) {
F_20 ( V_11 , L_9 , V_37 ) ;
return;
}
for ( V_79 = 0 ; V_79 < V_81 ; V_79 ++ ) {
if ( ! V_80 [ V_79 ] . V_82 ||
! V_80 [ V_79 ] . V_83 )
continue;
V_76 -> V_84 [ V_79 ] = V_80 [ V_79 ] . V_82 ;
V_76 -> V_50 [ V_79 ] = F_33 ( V_11 ,
sizeof( struct V_49 ) , V_85 ) ;
V_76 -> V_50 [ V_79 ] -> V_56 =
F_34 ( V_80 [ V_79 ] . V_83 ,
L_10 ) ;
V_76 -> V_50 [ V_79 ] -> V_58 =
F_34 ( V_80 [ V_79 ] . V_83 ,
L_11 ) ;
V_37 = F_35 ( V_80 [ V_79 ] . V_83 ,
L_12 , & V_78 ) ;
if ( ! V_37 )
V_76 -> V_50 [ V_79 ] -> V_54 = V_78 ;
V_37 = F_34 ( V_80 [ V_79 ] . V_83 ,
L_13 ) ;
if ( V_37 )
V_76 -> V_50 [ V_79 ] -> V_63 =
V_86 ;
if ( V_79 == V_69 )
V_76 -> V_87 = F_34 (
V_80 [ V_79 ] . V_83 ,
L_14 ) ;
}
V_76 -> V_88 = F_34 ( V_74 , L_15 ) ;
}
static int F_36 ( struct V_89 * V_90 )
{
struct V_1 * V_1 = F_37 ( V_90 -> V_11 . V_91 ) ;
struct V_75 * V_76 = F_38 ( & V_90 -> V_11 ) ;
struct V_73 * V_74 = V_90 -> V_11 . V_83 ;
struct V_10 * V_34 ;
struct V_92 V_93 = { } ;
struct V_12 * V_13 ;
struct V_49 * V_50 ;
int V_14 = 0 , V_37 ;
unsigned int V_4 , V_2 ;
if ( V_74 && ! V_76 ) {
V_76 = F_33 ( & V_90 -> V_11 , sizeof( * V_76 ) , V_85 ) ;
if ( ! V_76 )
return - V_94 ;
F_27 ( & V_90 -> V_11 , V_74 , V_76 ) ;
}
V_13 = F_33 ( & V_90 -> V_11 , sizeof( * V_13 ) , V_85 ) ;
if ( ! V_13 )
return - V_94 ;
V_13 -> V_11 = & V_90 -> V_11 ;
V_13 -> V_1 = V_1 ;
V_1 -> V_13 = V_13 ;
F_39 ( V_90 , V_13 ) ;
V_37 = F_1 ( V_1 , V_95 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_2 & V_96 )
V_13 -> V_97 = 1 ;
if ( V_2 & V_98 )
V_13 -> V_99 = 1 ;
V_93 . V_6 = V_1 -> V_6 [ V_7 ] ;
V_93 . V_11 = & V_90 -> V_11 ;
V_93 . V_100 = V_13 ;
for ( V_14 = 0 ; V_14 < V_101 ; V_14 ++ ) {
bool V_102 = false ;
switch ( V_14 ) {
case V_103 :
case V_45 :
if ( V_13 -> V_97 )
continue;
if ( V_14 == V_103 )
V_102 = true ;
break;
case V_104 :
if ( ! V_13 -> V_97 )
continue;
V_102 = true ;
break;
case V_105 :
case V_46 :
if ( V_13 -> V_99 )
continue;
if ( V_14 == V_105 )
V_102 = true ;
break;
case V_106 :
if ( ! V_13 -> V_99 )
continue;
V_102 = true ;
break;
case V_51 :
case V_52 :
if ( ! F_40 ( V_1 , V_107 ) )
continue;
}
if ( ( V_14 == V_108 ) || ( V_14 == V_109 ) )
V_102 = true ;
if ( V_102 ) {
V_4 = V_15 [ V_14 ] . V_44 ;
V_37 = F_1 ( V_13 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 < 0 ) {
F_20 ( & V_90 -> V_11 ,
L_16 , V_37 ) ;
goto V_110;
}
V_13 -> V_111 [ V_14 ] . V_43 =
V_47 [ V_2 & 0x3 ] ;
V_13 -> V_43 [ V_14 ] = V_13 -> V_111 [ V_14 ] . V_43 ;
}
if ( V_76 && V_76 -> V_50 [ V_14 ] ) {
V_50 = V_76 -> V_50 [ V_14 ] ;
V_37 = F_22 ( V_1 , V_14 , V_50 ) ;
if ( V_37 )
goto V_110;
}
V_13 -> V_111 [ V_14 ] . V_112 = V_15 [ V_14 ] . V_112 ;
V_13 -> V_111 [ V_14 ] . V_14 = V_14 ;
switch ( V_14 ) {
case V_51 :
case V_52 :
V_13 -> V_111 [ V_14 ] . V_113 = V_114 ;
V_13 -> V_111 [ V_14 ] . V_115 = & V_116 ;
V_13 -> V_111 [ V_14 ] . V_117 =
F_2 ( V_5 ,
V_118 ) ;
V_13 -> V_111 [ V_14 ] . V_119 = V_120 ;
V_13 -> V_111 [ V_14 ] . V_121 =
F_2 ( V_5 ,
V_118 ) ;
if ( V_14 == V_51 )
V_13 -> V_111 [ V_14 ] . V_122 = V_123 ;
else
V_13 -> V_111 [ V_14 ] . V_122 = V_124 ;
V_13 -> V_111 [ V_14 ] . V_125 =
F_2 ( V_5 ,
V_118 ) ;
V_13 -> V_111 [ V_14 ] . V_126 = V_127 ;
V_13 -> V_111 [ V_14 ] . V_35 = 3750000 ;
V_13 -> V_111 [ V_14 ] . V_128 = 1250000 ;
break;
default:
V_4 = V_15 [ V_14 ] . V_62 ;
V_37 = F_1 ( V_13 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 )
goto V_110;
if ( V_2 & V_86 )
V_13 -> V_33 [ V_14 ] = 1 ;
V_13 -> V_111 [ V_14 ] . V_115 = & V_129 ;
V_13 -> V_111 [ V_14 ] . V_113 = V_130 ;
V_13 -> V_111 [ V_14 ] . V_117 =
F_2 ( V_5 ,
V_15 [ V_14 ] . V_62 ) ;
V_13 -> V_111 [ V_14 ] . V_119 =
V_131 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_37 = F_1 ( V_13 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 )
goto V_110;
V_13 -> V_20 [ V_14 ] = V_2 &
V_19 ;
}
V_13 -> V_111 [ V_14 ] . type = V_132 ;
V_13 -> V_111 [ V_14 ] . V_133 = V_134 ;
if ( V_76 )
V_93 . V_82 = V_76 -> V_84 [ V_14 ] ;
else
V_93 . V_82 = NULL ;
V_13 -> V_111 [ V_14 ] . V_135 = V_15 [ V_14 ] . V_136 ;
V_93 . V_83 = V_80 [ V_14 ] . V_83 ;
V_34 = F_41 ( & V_13 -> V_111 [ V_14 ] , & V_93 ) ;
if ( F_42 ( V_34 ) ) {
F_20 ( & V_90 -> V_11 ,
L_17 ,
V_90 -> V_112 ) ;
V_37 = F_43 ( V_34 ) ;
goto V_110;
}
V_13 -> V_34 [ V_14 ] = V_34 ;
}
for (; V_14 < V_81 ; V_14 ++ ) {
V_13 -> V_111 [ V_14 ] . V_112 = V_15 [ V_14 ] . V_112 ;
V_13 -> V_111 [ V_14 ] . V_14 = V_14 ;
V_13 -> V_111 [ V_14 ] . type = V_132 ;
V_13 -> V_111 [ V_14 ] . V_133 = V_134 ;
if ( V_14 < V_137 ) {
V_13 -> V_111 [ V_14 ] . V_113 = V_138 ;
V_13 -> V_111 [ V_14 ] . V_115 = & V_139 ;
V_13 -> V_111 [ V_14 ] . V_35 = 900000 ;
V_13 -> V_111 [ V_14 ] . V_128 = 50000 ;
V_13 -> V_111 [ V_14 ] . V_140 = 1 ;
V_13 -> V_111 [ V_14 ] . V_141 = 500 ;
V_13 -> V_111 [ V_14 ] . V_117 =
F_2 ( V_9 ,
V_15 [ V_14 ] . V_62 ) ;
V_13 -> V_111 [ V_14 ] . V_119 =
V_142 ;
V_13 -> V_111 [ V_14 ] . V_121 =
F_2 ( V_9 ,
V_15 [ V_14 ] . V_16 ) ;
V_13 -> V_111 [ V_14 ] . V_122 =
V_143 ;
if ( V_76 && ( V_14 == V_69 ) &&
V_76 -> V_87 ) {
F_26 ( V_1 ) ;
V_13 -> V_111 [ V_14 ] . V_35 = 450000 ;
V_13 -> V_111 [ V_14 ] . V_128 = 25000 ;
}
if ( V_76 && V_76 -> V_88 &&
( V_14 == V_144 ) )
V_13 -> V_111 [ V_14 ] . V_141 = 2000 ;
} else {
V_13 -> V_111 [ V_14 ] . V_113 = 1 ;
V_13 -> V_111 [ V_14 ] . V_115 = & V_145 ;
V_13 -> V_111 [ V_14 ] . V_121 =
F_2 ( V_68 ,
V_15 [ V_14 ] . V_16 ) ;
V_13 -> V_111 [ V_14 ] . V_122 =
V_146 ;
}
if ( V_76 )
V_93 . V_82 = V_76 -> V_84 [ V_14 ] ;
else
V_93 . V_82 = NULL ;
V_13 -> V_111 [ V_14 ] . V_135 = V_15 [ V_14 ] . V_136 ;
V_93 . V_83 = V_80 [ V_14 ] . V_83 ;
V_34 = F_41 ( & V_13 -> V_111 [ V_14 ] , & V_93 ) ;
if ( F_42 ( V_34 ) ) {
F_20 ( & V_90 -> V_11 ,
L_17 ,
V_90 -> V_112 ) ;
V_37 = F_43 ( V_34 ) ;
goto V_110;
}
V_13 -> V_34 [ V_14 ] = V_34 ;
if ( V_76 ) {
V_50 = V_76 -> V_50 [ V_14 ] ;
if ( V_50 ) {
if ( V_14 < V_137 )
V_37 = F_23 ( V_1 ,
V_14 , V_50 ) ;
else
V_37 = F_24 ( V_1 ,
V_14 , V_50 ) ;
if ( V_37 ) {
F_44 ( V_13 -> V_34 [ V_14 ] ) ;
goto V_110;
}
}
}
}
return 0 ;
V_110:
while ( -- V_14 >= 0 )
F_44 ( V_13 -> V_34 [ V_14 ] ) ;
return V_37 ;
}
static int F_45 ( struct V_89 * V_90 )
{
struct V_12 * V_13 = F_46 ( V_90 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_81 ; V_14 ++ )
F_44 ( V_13 -> V_34 [ V_14 ] ) ;
return 0 ;
}
static int T_2 F_47 ( void )
{
return F_48 ( & V_147 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_147 ) ;
}
