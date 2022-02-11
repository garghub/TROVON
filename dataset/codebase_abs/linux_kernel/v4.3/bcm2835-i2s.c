static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 & V_5 ;
switch ( V_3 ) {
case V_6 :
case V_7 :
F_2 ( V_2 -> V_8 , V_9 ,
V_10 | V_11 ,
V_12 | V_11 ) ;
break;
default:
break;
}
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_14 = 1000 ;
F_2 ( V_2 -> V_8 , V_9 ,
V_10 | V_11 ,
V_12 ) ;
while ( -- V_14 ) {
F_4 ( V_2 -> V_8 , V_9 , & V_13 ) ;
if ( ! ( V_13 & V_15 ) )
break;
}
if ( ! V_14 ) {
F_5 ( V_2 -> V_2 , L_1 ) ;
F_2 ( V_2 -> V_8 , V_9 ,
V_16 | V_10 ,
V_16 | V_12 ) ;
}
}
static void F_6 ( struct V_1 * V_2 ,
bool V_17 , bool V_18 )
{
int V_14 = 1000 ;
T_1 V_19 ;
T_1 V_20 ;
T_1 V_21 ;
T_1 V_13 ;
T_1 V_22 ;
T_1 V_23 ;
T_1 V_24 ;
V_23 = V_17 ? V_25 : 0 ;
V_23 |= V_18 ? V_26 : 0 ;
V_24 = V_17 ? V_27 : 0 ;
V_24 |= V_18 ? V_28 : 0 ;
F_4 ( V_2 -> V_29 , V_30 , & V_20 ) ;
V_21 = V_20 & ( V_26 | V_25 ) ;
F_4 ( V_2 -> V_8 , V_9 , & V_13 ) ;
V_22 = V_13 & V_11 ;
if ( ! V_22 ) {
F_2 ( V_2 -> V_8 , V_9 ,
V_10 | V_11 ,
V_12 | V_11 ) ;
}
F_2 ( V_2 -> V_29 , V_30 , V_23 , 0 ) ;
F_2 ( V_2 -> V_29 , V_30 , V_24 , V_24 ) ;
F_4 ( V_2 -> V_29 , V_30 , & V_19 ) ;
V_19 &= V_31 ;
F_2 ( V_2 -> V_29 , V_30 ,
V_31 , ~ V_19 ) ;
while ( -- V_14 ) {
F_4 ( V_2 -> V_29 , V_30 , & V_20 ) ;
if ( ( V_20 & V_31 ) != V_19 )
break;
}
if ( ! V_14 )
F_5 ( V_2 -> V_2 , L_2 ) ;
if ( ! V_22 )
F_3 ( V_2 ) ;
F_2 ( V_2 -> V_29 , V_30 ,
V_26 | V_25 , V_21 ) ;
}
static int F_7 ( struct V_32 * V_33 ,
unsigned int V_4 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_9 ( struct V_32 * V_33 ,
unsigned int V_34 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
V_2 -> V_35 = V_34 ;
return 0 ;
}
static int F_10 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
unsigned int V_40 = F_11 ( V_39 ) ;
unsigned int V_41 , V_42 , V_35 ;
unsigned int V_43 , V_44 , V_45 , V_46 ;
unsigned int V_47 = V_48 ;
unsigned int V_49 , V_50 , V_51 ;
int V_52 = - 1 ;
unsigned int V_3 = V_2 -> V_4 & V_5 ;
bool V_53 = ( V_3 == V_6
|| V_3 == V_7 ) ;
bool V_54 = ( V_3 == V_6
|| V_3 == V_55 ) ;
T_1 V_20 ;
F_4 ( V_2 -> V_29 , V_30 , & V_20 ) ;
if ( V_20 & ( V_25 | V_26 ) )
return 0 ;
switch ( F_12 ( V_39 ) ) {
case V_56 :
V_41 = 16 ;
V_35 = 40 ;
break;
case V_57 :
V_41 = 32 ;
V_35 = 80 ;
break;
default:
return - V_58 ;
}
if ( V_2 -> V_35 )
V_35 = V_2 -> V_35 ;
V_51 = V_40 * V_35 ;
V_52 = V_59 ;
V_47 = V_60 ;
if ( V_61 [ V_52 ] % V_51 == 0
&& V_53 && V_54 ) {
V_49 = V_61 [ V_52 ] / V_51 ;
V_50 = 0 ;
} else {
T_2 V_62 ;
if ( ! V_2 -> V_35 ) {
V_35 = 2 * V_41 ;
}
V_51 = V_40 * V_35 ;
V_52 = V_63 ;
V_47 = V_48 ;
V_62 = V_61 [ V_52 ] ;
V_62 <<= V_64 ;
F_13 ( V_62 , V_51 ) ;
V_49 = V_62 >> V_64 ;
V_50 = V_62 & V_65 ;
}
F_14 ( V_2 -> V_8 , V_66 , V_12
| F_15 ( V_49 )
| F_16 ( V_50 ) ) ;
F_14 ( V_2 -> V_8 , V_9 , V_12
| F_17 ( V_47 )
| F_18 ( V_52 ) ) ;
V_46 = V_67 ;
if ( V_41 > 24 )
V_46 |= V_68 ;
V_46 |= F_19 ( ( V_41 - 8 ) & 0xf ) ;
switch ( V_2 -> V_4 & V_69 ) {
case V_70 :
V_42 = 1 ;
break;
default:
F_5 ( V_2 -> V_2 , L_3 , V_71 ) ;
return - V_58 ;
}
V_43 = V_42 ;
V_44 = V_35 / 2 + V_42 ;
switch ( F_20 ( V_39 ) ) {
case 2 :
V_46 = F_21 ( V_46 ) | F_22 ( V_46 ) ;
V_46 |= F_21 ( F_23 ( V_43 ) ) ;
V_46 |= F_22 ( F_23 ( V_44 ) ) ;
break;
default:
return - V_58 ;
}
F_14 ( V_2 -> V_29 , V_72 , V_46 ) ;
F_14 ( V_2 -> V_29 , V_73 , V_46 ) ;
V_45 = 0 ;
if ( V_41 <= 16 ) {
V_45 |= V_74 | V_75 ;
}
V_45 |= F_24 ( V_35 - 1 ) ;
V_45 |= F_25 ( V_35 / 2 ) ;
switch ( V_2 -> V_4 & V_5 ) {
case V_6 :
break;
case V_55 :
V_45 |= V_76 ;
break;
case V_7 :
V_45 |= V_77 ;
break;
case V_78 :
V_45 |= V_76 ;
V_45 |= V_77 ;
break;
default:
F_5 ( V_2 -> V_2 , L_4 , V_71 ) ;
return - V_58 ;
}
switch ( V_2 -> V_4 & V_79 ) {
case V_80 :
V_45 |= V_81 ;
V_45 |= V_82 ;
break;
case V_83 :
break;
case V_84 :
V_45 |= V_81 ;
break;
case V_85 :
V_45 |= V_82 ;
break;
default:
return - V_58 ;
}
F_14 ( V_2 -> V_29 , V_86 , V_45 ) ;
F_2 ( V_2 -> V_29 , V_30 ,
F_26 ( 1 )
| F_27 ( 1 )
| V_87 , 0xffffffff ) ;
F_2 ( V_2 -> V_29 , V_88 ,
F_28 ( 0x10 )
| F_29 ( 0x30 )
| F_30 ( 0x30 )
| F_31 ( 0x20 ) , 0xffffffff ) ;
F_6 ( V_2 , true , true ) ;
return 0 ;
}
static int F_32 ( struct V_36 * V_37 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
T_1 V_89 ;
F_1 ( V_2 ) ;
F_4 ( V_2 -> V_29 , V_30 , & V_89 ) ;
if ( V_37 -> V_90 == V_91
&& ! ( V_89 & V_92 ) )
F_6 ( V_2 , true , false ) ;
else if ( V_37 -> V_90 == V_93
&& ( V_89 & V_94 ) )
F_6 ( V_2 , false , true ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_32 * V_33 )
{
T_1 V_95 ;
if ( V_37 -> V_90 == V_93 )
V_95 = V_26 ;
else
V_95 = V_25 ;
F_2 ( V_2 -> V_29 ,
V_30 , V_95 , 0 ) ;
if ( ! V_33 -> V_96 && ! ( V_2 -> V_4 & V_97 ) )
F_3 ( V_2 ) ;
}
static int F_34 ( struct V_36 * V_37 , int V_98 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
T_1 V_95 ;
switch ( V_98 ) {
case V_99 :
case V_100 :
case V_101 :
F_1 ( V_2 ) ;
if ( V_37 -> V_90 == V_93 )
V_95 = V_26 ;
else
V_95 = V_25 ;
F_2 ( V_2 -> V_29 ,
V_30 , V_95 , V_95 ) ;
break;
case V_102 :
case V_103 :
case V_104 :
F_33 ( V_2 , V_37 , V_33 ) ;
break;
default:
return - V_58 ;
}
return 0 ;
}
static int F_35 ( struct V_36 * V_37 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
if ( V_33 -> V_96 )
return 0 ;
F_3 ( V_2 ) ;
F_2 ( V_2 -> V_29 , V_30 ,
V_105 , V_105 ) ;
F_2 ( V_2 -> V_29 , V_30 ,
V_106 , V_106 ) ;
return 0 ;
}
static void F_36 ( struct V_36 * V_37 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
F_33 ( V_2 , V_37 , V_33 ) ;
if ( V_33 -> V_96 )
return;
F_2 ( V_2 -> V_29 , V_30 ,
V_105 , 0 ) ;
F_3 ( V_2 ) ;
}
static int F_37 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
F_38 ( V_33 ,
& V_2 -> V_107 [ V_91 ] ,
& V_2 -> V_107 [ V_93 ] ) ;
return 0 ;
}
static bool F_39 ( struct V_108 * V_2 , unsigned int V_109 )
{
switch ( V_109 ) {
case V_30 :
case V_110 :
case V_111 :
case V_112 :
return true ;
default:
return false ;
} ;
}
static bool F_40 ( struct V_108 * V_2 , unsigned int V_109 )
{
switch ( V_109 ) {
case V_110 :
return true ;
default:
return false ;
} ;
}
static bool F_41 ( struct V_108 * V_2 , unsigned int V_109 )
{
switch ( V_109 ) {
case V_9 :
return true ;
default:
return false ;
} ;
}
static int F_42 ( struct V_113 * V_114 )
{
struct V_1 * V_2 ;
int V_115 ;
int V_116 ;
struct V_117 * V_117 [ 2 ] ;
struct V_118 * V_119 [ 2 ] ;
for ( V_115 = 0 ; V_115 <= 1 ; V_115 ++ ) {
void T_3 * V_120 ;
V_119 [ V_115 ] = F_43 ( V_114 , V_121 , V_115 ) ;
V_120 = F_44 ( & V_114 -> V_2 , V_119 [ V_115 ] ) ;
if ( F_45 ( V_120 ) )
return F_46 ( V_120 ) ;
V_117 [ V_115 ] = F_47 ( & V_114 -> V_2 , V_120 ,
& V_122 [ V_115 ] ) ;
if ( F_45 ( V_117 [ V_115 ] ) )
return F_46 ( V_117 [ V_115 ] ) ;
}
V_2 = F_48 ( & V_114 -> V_2 , sizeof( * V_2 ) ,
V_123 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_29 = V_117 [ 0 ] ;
V_2 -> V_8 = V_117 [ 1 ] ;
V_2 -> V_107 [ V_91 ] . V_125 =
( V_126 ) V_119 [ 0 ] -> V_127 + V_110
+ V_128 ;
V_2 -> V_107 [ V_93 ] . V_125 =
( V_126 ) V_119 [ 0 ] -> V_127 + V_110
+ V_128 ;
V_2 -> V_107 [ V_91 ] . V_129 =
V_130 ;
V_2 -> V_107 [ V_93 ] . V_129 =
V_130 ;
V_2 -> V_107 [ V_91 ] . V_131 = 2 ;
V_2 -> V_107 [ V_93 ] . V_131 = 2 ;
V_2 -> V_35 = 0 ;
V_2 -> V_2 = & V_114 -> V_2 ;
F_49 ( & V_114 -> V_2 , V_2 ) ;
V_116 = F_50 ( & V_114 -> V_2 ,
& V_132 , & V_133 , 1 ) ;
if ( V_116 ) {
F_5 ( & V_114 -> V_2 , L_5 , V_116 ) ;
return V_116 ;
}
V_116 = F_51 ( & V_114 -> V_2 , NULL , 0 ) ;
if ( V_116 ) {
F_5 ( & V_114 -> V_2 , L_6 , V_116 ) ;
return V_116 ;
}
return 0 ;
}
