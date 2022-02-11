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
static int F_8 ( struct V_10 * V_11 , unsigned int V_12 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
int V_15 = F_10 ( V_11 ) ;
unsigned int V_2 ;
bool V_16 = true ;
F_1 ( V_14 -> V_1 , V_17 [ V_15 ] . V_18 , & V_2 ) ;
V_2 &= ~ V_19 ;
if ( V_2 == V_20 )
V_16 = false ;
switch ( V_12 ) {
case V_21 :
V_2 |= V_22 ;
break;
case V_23 :
V_2 |= V_24 ;
break;
case V_25 :
V_2 |= V_26 ;
break;
default:
return - V_27 ;
}
V_14 -> V_28 [ V_15 ] = V_2 & V_19 ;
if ( V_16 )
F_4 ( V_14 -> V_1 ,
V_17 [ V_15 ] . V_18 , V_2 ) ;
V_14 -> V_29 [ V_15 ] . V_30 = V_14 -> V_28 [ V_15 ] ;
return 0 ;
}
static unsigned int F_11 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
int V_15 = F_10 ( V_11 ) ;
unsigned int V_2 ;
V_2 = V_14 -> V_28 [ V_15 ] & V_19 ;
switch ( V_2 ) {
case V_22 :
return V_21 ;
case V_24 :
return V_23 ;
case V_26 :
return V_25 ;
}
return 0 ;
}
static int F_12 ( struct V_10 * V_31 ,
int V_32 )
{
struct V_13 * V_14 = F_9 ( V_31 ) ;
int V_15 = F_10 ( V_31 ) ;
unsigned int V_2 = 0 ;
unsigned int V_4 = V_17 [ V_15 ] . V_33 ;
int V_34 ;
switch ( V_15 ) {
case V_35 :
case V_36 :
return 0 ;
}
if ( V_32 <= 0 )
V_2 = 0 ;
else if ( V_32 <= 2500 )
V_2 = 3 ;
else if ( V_32 <= 5000 )
V_2 = 2 ;
else
V_2 = 1 ;
V_34 = F_4 ( V_14 -> V_1 , V_4 , V_2 ) ;
if ( V_34 < 0 ) {
F_13 ( V_14 -> V_1 -> V_11 , L_1 , V_34 ) ;
return V_34 ;
}
V_14 -> V_32 [ V_15 ] = V_37 [ V_2 ] ;
return V_34 ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
int V_15 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_6 ( V_14 -> V_1 , V_17 [ V_15 ] . V_18 , & V_2 ) ;
V_2 &= V_38 ;
return ! ! ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_1 , int V_15 ,
struct V_39 * V_40 )
{
int V_41 = V_17 [ V_15 ] . V_41 ;
int V_34 ;
V_34 = F_16 ( V_1 , V_41 ,
V_40 -> V_42 , true ) ;
if ( V_34 < 0 )
F_13 ( V_1 -> V_11 ,
L_2 ,
V_15 , V_34 ) ;
return V_34 ;
}
static int F_17 ( struct V_1 * V_1 , int V_15 ,
struct V_39 * V_40 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_34 ;
V_4 = V_17 [ V_15 ] . V_18 ;
V_34 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_34 )
return V_34 ;
switch ( V_15 ) {
case V_43 :
case V_44 :
V_2 &= ~ V_45 ;
if ( V_40 -> V_46 )
V_2 |= V_40 -> V_46 <<
V_47 ;
break;
default:
if ( V_40 -> V_48 )
V_2 |= V_49 ;
else
V_2 &= ~ V_49 ;
if ( V_40 -> V_42 )
V_2 |= V_50 ;
else
V_2 &= ~ V_50 ;
V_2 &= ~ V_51 ;
if ( V_40 -> V_46 )
V_2 |= V_40 -> V_46 <<
V_52 ;
}
V_34 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_17 [ V_15 ] . V_53 && V_40 -> V_54 ) {
V_4 = V_17 [ V_15 ] . V_53 ;
V_2 = V_40 -> V_54 ;
V_34 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
}
if ( V_40 -> V_42 && ( V_15 != V_43 ) &&
( V_15 != V_44 ) ) {
V_4 = V_17 [ V_15 ] . V_18 ;
V_34 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ! ( V_2 & V_19 ) ) {
V_2 |= V_22 ;
V_34 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
}
return F_15 ( V_1 , V_15 , V_40 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , int V_15 ,
struct V_39 * V_40 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_34 ;
V_4 = V_17 [ V_15 ] . V_18 ;
V_34 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_40 -> V_48 )
V_2 |= V_55 ;
else
V_2 &= ~ V_55 ;
if ( V_40 -> V_46 )
V_2 |= V_56 ;
else
V_2 &= ~ V_56 ;
V_34 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_40 -> V_42 ) {
V_4 = V_17 [ V_15 ] . V_18 ;
V_34 = F_19 ( V_1 , V_9 ,
V_4 , V_57 ,
V_57 ) ;
if ( V_34 < 0 ) {
F_13 ( V_1 -> V_11 ,
L_3 ,
V_4 , V_34 ) ;
return V_34 ;
}
return F_15 ( V_1 , V_15 , V_40 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , int V_15 ,
struct V_39 * V_40 )
{
unsigned int V_4 ;
int V_34 ;
unsigned int V_58 = 0 ;
V_4 = V_17 [ V_15 ] . V_18 ;
if ( V_40 -> V_46 )
V_58 = V_59 ;
V_34 = F_19 ( V_1 , V_60 ,
V_4 , V_59 , V_58 ) ;
if ( V_34 < 0 ) {
F_13 ( V_1 -> V_11 , L_4 ,
V_4 , V_34 ) ;
return V_34 ;
}
if ( V_40 -> V_42 ) {
V_4 = V_17 [ V_15 ] . V_18 ;
V_34 = F_19 ( V_1 , V_60 ,
V_4 , V_61 ,
V_61 ) ;
if ( V_34 < 0 ) {
F_13 ( V_1 -> V_11 ,
L_5 ,
V_4 , V_34 ) ;
return V_34 ;
}
return F_15 ( V_1 , V_15 , V_40 ) ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_34 ;
V_4 = V_17 [ V_62 ] . V_18 ;
V_34 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_34 ) {
F_13 ( V_1 -> V_11 , L_6 ) ;
return;
}
V_2 |= V_63 ;
V_34 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_34 < 0 ) {
F_13 ( V_1 -> V_11 , L_7 ) ;
return;
}
V_4 = V_17 [ V_62 ] . V_53 ;
V_34 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_34 ) {
F_13 ( V_1 -> V_11 , L_8 ) ;
return;
}
V_2 = ( V_2 << 1 ) & V_64 ;
V_34 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_34 < 0 )
F_13 ( V_1 -> V_11 , L_9 ) ;
return;
}
static void F_22 ( struct V_65 * V_11 ,
struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_66 * V_70 ;
T_1 V_71 ;
int V_72 , V_34 ;
V_67 = F_23 ( V_67 ) ;
V_70 = F_24 ( V_67 , L_10 ) ;
if ( ! V_70 ) {
F_25 ( V_11 , L_11 ) ;
return;
}
V_34 = F_26 ( V_11 , V_70 , V_73 ,
V_74 ) ;
F_27 ( V_70 ) ;
if ( V_34 < 0 ) {
F_13 ( V_11 , L_12 , V_34 ) ;
return;
}
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
if ( ! V_73 [ V_72 ] . V_75 ||
! V_73 [ V_72 ] . V_76 )
continue;
V_69 -> V_77 [ V_72 ] = V_73 [ V_72 ] . V_75 ;
V_69 -> V_40 [ V_72 ] = F_28 ( V_11 ,
sizeof( struct V_39 ) , V_78 ) ;
V_69 -> V_40 [ V_72 ] -> V_48 =
F_29 ( V_73 [ V_72 ] . V_76 ,
L_13 ) ;
V_34 = F_30 ( V_73 [ V_72 ] . V_76 ,
L_14 , & V_71 ) ;
if ( V_34 != - V_27 ) {
int V_79 ;
V_79 = V_80 ;
if ( ! V_34 ) {
switch ( V_71 ) {
case 1 :
V_79 = V_81 ;
break;
case 2 :
V_79 = V_82 ;
break;
case 3 :
V_79 = V_80 ;
break;
default:
F_31 ( 1 ) ;
F_32 ( V_11 ,
L_15 ,
V_73 [ V_72 ] . V_83 , V_71 ) ;
break;
}
}
V_69 -> V_40 [ V_72 ] -> V_42 = V_79 ;
}
V_34 = F_30 ( V_73 [ V_72 ] . V_76 ,
L_16 , & V_71 ) ;
if ( ! V_34 )
V_69 -> V_40 [ V_72 ] -> V_46 = V_71 ;
V_34 = F_29 ( V_73 [ V_72 ] . V_76 ,
L_17 ) ;
if ( V_34 )
V_69 -> V_40 [ V_72 ] -> V_54 =
V_84 ;
if ( V_72 == V_62 )
V_69 -> V_85 = F_29 (
V_73 [ V_72 ] . V_76 ,
L_18 ) ;
}
V_69 -> V_86 = F_29 ( V_67 , L_19 ) ;
}
static int F_33 ( struct V_87 * V_88 )
{
struct V_1 * V_1 = F_34 ( V_88 -> V_11 . V_89 ) ;
struct V_68 * V_69 = F_35 ( & V_88 -> V_11 ) ;
struct V_66 * V_67 = V_88 -> V_11 . V_76 ;
struct V_10 * V_31 ;
struct V_90 V_91 = { } ;
struct V_13 * V_14 ;
struct V_39 * V_40 ;
int V_15 = 0 , V_34 ;
unsigned int V_4 , V_2 ;
if ( V_67 && ! V_69 ) {
V_69 = F_28 ( & V_88 -> V_11 , sizeof( * V_69 ) , V_78 ) ;
if ( ! V_69 )
return - V_92 ;
F_22 ( & V_88 -> V_11 , V_67 , V_69 ) ;
}
V_14 = F_28 ( & V_88 -> V_11 , sizeof( * V_14 ) , V_78 ) ;
if ( ! V_14 )
return - V_92 ;
V_14 -> V_11 = & V_88 -> V_11 ;
V_14 -> V_1 = V_1 ;
V_1 -> V_14 = V_14 ;
F_36 ( V_88 , V_14 ) ;
V_34 = F_1 ( V_1 , V_93 , & V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_2 & V_94 )
V_14 -> V_95 = 1 ;
if ( V_2 & V_96 )
V_14 -> V_97 = 1 ;
V_91 . V_6 = V_1 -> V_6 [ V_7 ] ;
V_91 . V_11 = & V_88 -> V_11 ;
V_91 . V_98 = V_14 ;
for ( V_15 = 0 ; V_15 < V_99 ; V_15 ++ ) {
bool V_100 = false ;
switch ( V_15 ) {
case V_101 :
case V_35 :
if ( V_14 -> V_95 )
continue;
if ( V_15 == V_101 )
V_100 = true ;
break;
case V_102 :
if ( ! V_14 -> V_95 )
continue;
V_100 = true ;
break;
case V_103 :
case V_36 :
if ( V_14 -> V_97 )
continue;
if ( V_15 == V_103 )
V_100 = true ;
break;
case V_104 :
if ( ! V_14 -> V_97 )
continue;
V_100 = true ;
break;
case V_43 :
case V_44 :
if ( ! F_37 ( V_1 , V_105 ) )
continue;
}
if ( ( V_15 == V_106 ) || ( V_15 == V_107 ) )
V_100 = true ;
if ( V_100 ) {
V_4 = V_17 [ V_15 ] . V_33 ;
V_34 = F_1 ( V_14 -> V_1 , V_4 , & V_2 ) ;
if ( V_34 < 0 ) {
F_13 ( & V_88 -> V_11 ,
L_20 , V_34 ) ;
return V_34 ;
}
V_14 -> V_29 [ V_15 ] . V_32 =
V_37 [ V_2 & 0x3 ] ;
V_14 -> V_32 [ V_15 ] = V_14 -> V_29 [ V_15 ] . V_32 ;
}
if ( V_69 && V_69 -> V_40 [ V_15 ] ) {
V_40 = V_69 -> V_40 [ V_15 ] ;
V_34 = F_17 ( V_1 , V_15 , V_40 ) ;
if ( V_34 )
return V_34 ;
} else {
V_40 = NULL ;
}
V_14 -> V_29 [ V_15 ] . V_83 = V_17 [ V_15 ] . V_83 ;
V_14 -> V_29 [ V_15 ] . V_15 = V_15 ;
switch ( V_15 ) {
case V_43 :
case V_44 :
V_14 -> V_29 [ V_15 ] . V_108 = V_109 ;
V_14 -> V_29 [ V_15 ] . V_110 = & V_111 ;
V_14 -> V_29 [ V_15 ] . V_112 =
F_2 ( V_5 ,
V_113 ) ;
V_14 -> V_29 [ V_15 ] . V_114 = V_115 ;
V_14 -> V_29 [ V_15 ] . V_116 =
F_2 ( V_5 ,
V_113 ) ;
if ( V_15 == V_43 )
V_14 -> V_29 [ V_15 ] . V_117 = V_118 ;
else
V_14 -> V_29 [ V_15 ] . V_117 = V_119 ;
V_14 -> V_29 [ V_15 ] . V_120 =
F_2 ( V_5 ,
V_113 ) ;
V_14 -> V_29 [ V_15 ] . V_121 = V_122 ;
V_14 -> V_29 [ V_15 ] . V_123 = 3750000 ;
V_14 -> V_29 [ V_15 ] . V_124 = 1250000 ;
break;
default:
V_4 = V_17 [ V_15 ] . V_53 ;
V_14 -> V_29 [ V_15 ] . V_125 = 3 ;
V_34 = F_1 ( V_14 -> V_1 , V_4 , & V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_2 & V_84 )
V_14 -> V_126 [ V_15 ] = 1 ;
if ( V_14 -> V_126 [ V_15 ] )
V_14 -> V_29 [ V_15 ] . V_127 = V_128 ;
else
V_14 -> V_29 [ V_15 ] . V_127 = V_129 ;
if ( V_40 && V_40 -> V_42 )
V_14 -> V_29 [ V_15 ] . V_110 =
& V_130 ;
else
V_14 -> V_29 [ V_15 ] . V_110 = & V_131 ;
V_14 -> V_29 [ V_15 ] . V_108 = V_132 ;
V_14 -> V_29 [ V_15 ] . V_112 =
F_2 ( V_5 ,
V_17 [ V_15 ] . V_53 ) ;
V_14 -> V_29 [ V_15 ] . V_114 =
V_133 ;
V_4 = V_17 [ V_15 ] . V_18 ;
V_34 = F_1 ( V_14 -> V_1 , V_4 , & V_2 ) ;
if ( V_34 )
return V_34 ;
V_14 -> V_28 [ V_15 ] = V_2 &
V_19 ;
V_14 -> V_29 [ V_15 ] . V_116 =
F_2 ( V_5 ,
V_17 [ V_15 ] . V_18 ) ;
V_14 -> V_29 [ V_15 ] . V_117 =
V_19 ;
V_14 -> V_29 [ V_15 ] . V_30 = V_22 ;
}
V_14 -> V_29 [ V_15 ] . type = V_134 ;
V_14 -> V_29 [ V_15 ] . V_135 = V_136 ;
if ( V_69 )
V_91 . V_75 = V_69 -> V_77 [ V_15 ] ;
else
V_91 . V_75 = NULL ;
V_14 -> V_29 [ V_15 ] . V_137 = V_17 [ V_15 ] . V_138 ;
V_91 . V_76 = V_73 [ V_15 ] . V_76 ;
V_31 = F_38 ( & V_88 -> V_11 , & V_14 -> V_29 [ V_15 ] ,
& V_91 ) ;
if ( F_39 ( V_31 ) ) {
F_13 ( & V_88 -> V_11 ,
L_21 ,
V_88 -> V_83 ) ;
return F_40 ( V_31 ) ;
}
V_14 -> V_31 [ V_15 ] = V_31 ;
}
for (; V_15 < V_74 ; V_15 ++ ) {
if ( V_69 && V_69 -> V_40 [ V_15 ] )
V_40 = V_69 -> V_40 [ V_15 ] ;
else
V_40 = NULL ;
V_14 -> V_29 [ V_15 ] . V_83 = V_17 [ V_15 ] . V_83 ;
V_14 -> V_29 [ V_15 ] . V_15 = V_15 ;
V_14 -> V_29 [ V_15 ] . type = V_134 ;
V_14 -> V_29 [ V_15 ] . V_135 = V_136 ;
if ( V_15 < V_139 ) {
V_14 -> V_29 [ V_15 ] . V_108 = V_140 ;
if ( V_40 && V_40 -> V_42 )
V_14 -> V_29 [ V_15 ] . V_110 =
& V_141 ;
else
V_14 -> V_29 [ V_15 ] . V_110 = & V_142 ;
V_14 -> V_29 [ V_15 ] . V_123 = 900000 ;
V_14 -> V_29 [ V_15 ] . V_124 = 50000 ;
V_14 -> V_29 [ V_15 ] . V_143 = 1 ;
V_14 -> V_29 [ V_15 ] . V_144 = 500 ;
V_14 -> V_29 [ V_15 ] . V_112 =
F_2 ( V_9 ,
V_17 [ V_15 ] . V_53 ) ;
V_14 -> V_29 [ V_15 ] . V_114 =
V_145 ;
V_14 -> V_29 [ V_15 ] . V_116 =
F_2 ( V_9 ,
V_17 [ V_15 ] . V_18 ) ;
V_14 -> V_29 [ V_15 ] . V_117 =
V_57 ;
if ( V_69 && ( V_15 == V_62 ) &&
V_69 -> V_85 ) {
F_21 ( V_1 ) ;
V_14 -> V_29 [ V_15 ] . V_123 = 450000 ;
V_14 -> V_29 [ V_15 ] . V_124 = 25000 ;
}
if ( V_69 && V_69 -> V_86 &&
( V_15 == V_146 ) )
V_14 -> V_29 [ V_15 ] . V_144 = 2000 ;
} else {
V_14 -> V_29 [ V_15 ] . V_108 = 1 ;
if ( V_40 && V_40 -> V_42 )
V_14 -> V_29 [ V_15 ] . V_110 =
& V_147 ;
else
V_14 -> V_29 [ V_15 ] . V_110 = & V_148 ;
V_14 -> V_29 [ V_15 ] . V_116 =
F_2 ( V_60 ,
V_17 [ V_15 ] . V_18 ) ;
V_14 -> V_29 [ V_15 ] . V_117 =
V_61 ;
}
if ( V_69 )
V_91 . V_75 = V_69 -> V_77 [ V_15 ] ;
else
V_91 . V_75 = NULL ;
V_14 -> V_29 [ V_15 ] . V_137 = V_17 [ V_15 ] . V_138 ;
V_91 . V_76 = V_73 [ V_15 ] . V_76 ;
V_31 = F_38 ( & V_88 -> V_11 , & V_14 -> V_29 [ V_15 ] ,
& V_91 ) ;
if ( F_39 ( V_31 ) ) {
F_13 ( & V_88 -> V_11 ,
L_21 ,
V_88 -> V_83 ) ;
return F_40 ( V_31 ) ;
}
V_14 -> V_31 [ V_15 ] = V_31 ;
if ( V_69 ) {
V_40 = V_69 -> V_40 [ V_15 ] ;
if ( V_40 ) {
if ( V_15 < V_139 )
V_34 = F_18 ( V_1 ,
V_15 , V_40 ) ;
else
V_34 = F_20 ( V_1 ,
V_15 , V_40 ) ;
if ( V_34 )
return V_34 ;
}
}
}
return 0 ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_149 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_149 ) ;
}
