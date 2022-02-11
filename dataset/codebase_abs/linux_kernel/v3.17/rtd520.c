static int F_1 ( unsigned int * V_1 ,
unsigned int V_2 , int V_3 )
{
int V_4 ;
switch ( V_2 & V_5 ) {
case V_6 :
default:
V_4 = ( * V_1 + V_3 / 2 ) / V_3 ;
break;
case V_7 :
V_4 = ( * V_1 ) / V_3 ;
break;
case V_8 :
V_4 = ( * V_1 + V_3 - 1 ) / V_3 ;
break;
}
if ( V_4 < 2 )
V_4 = 2 ;
* V_1 = V_3 * V_4 ;
return V_4 - 1 ;
}
static int F_2 ( unsigned int * V_9 , unsigned int V_2 )
{
return F_1 ( V_9 , V_2 , V_10 ) ;
}
static unsigned short F_3 ( struct V_11 * V_12 ,
unsigned int V_13 , int V_14 )
{
const struct V_15 * V_16 = F_4 ( V_12 ) ;
struct V_17 * V_18 = V_12 -> V_19 ;
unsigned int V_20 = F_5 ( V_13 ) ;
unsigned int V_21 = F_6 ( V_13 ) ;
unsigned int V_22 = F_7 ( V_13 ) ;
unsigned short V_23 = 0 ;
V_23 |= V_20 & 0xf ;
if ( V_21 < V_16 -> V_24 ) {
V_23 |= 0x000 ;
V_23 |= ( V_21 & 0x7 ) << 4 ;
F_8 ( V_14 , V_18 -> V_25 ) ;
} else if ( V_21 < V_16 -> V_26 ) {
V_23 |= 0x100 ;
V_23 |= ( ( V_21 - V_16 -> V_24 ) & 0x7 ) << 4 ;
F_8 ( V_14 , V_18 -> V_25 ) ;
} else {
V_23 |= 0x200 ;
V_23 |= ( ( V_21 - V_16 -> V_26 ) & 0x7 ) << 4 ;
F_9 ( V_14 , V_18 -> V_25 ) ;
}
switch ( V_22 ) {
case V_27 :
break;
case V_28 :
V_23 |= 0x80 ;
break;
case V_29 :
V_23 |= 0x400 ;
break;
case V_30 :
break;
}
return V_23 ;
}
static void F_10 ( struct V_11 * V_12 ,
unsigned int V_31 , unsigned int * V_32 )
{
if ( V_31 > 1 ) {
int V_33 ;
F_11 ( 0 , V_12 -> V_34 + V_35 ) ;
F_11 ( 1 , V_12 -> V_34 + V_36 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
F_11 ( F_3 ( V_12 , V_32 [ V_33 ] , V_33 ) ,
V_12 -> V_34 + V_37 ) ;
}
} else {
F_11 ( 0 , V_12 -> V_34 + V_36 ) ;
F_11 ( F_3 ( V_12 , V_32 [ 0 ] , 0 ) ,
V_12 -> V_34 + V_38 ) ;
}
}
static int F_12 ( struct V_11 * V_12 )
{
unsigned int V_13 = F_13 ( 0 , 0 , V_27 ) ;
unsigned V_39 ;
static const unsigned V_40 = 0x2000 ;
unsigned V_41 = 0 ;
F_11 ( 0 , V_12 -> V_34 + V_42 ) ;
F_10 ( V_12 , 1 , & V_13 ) ;
F_11 ( 0 , V_12 -> V_34 + V_43 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; ++ V_39 ) {
unsigned V_44 ;
F_14 ( 0 , V_12 -> V_34 + V_45 ) ;
F_15 ( 1 ) ;
V_44 = F_16 ( V_12 -> V_34 + V_45 ) ;
if ( ( V_44 & V_46 ) == 0 ) {
V_41 = 2 * V_39 ;
break;
}
}
if ( V_39 == V_40 ) {
F_17 ( V_12 -> V_47 , L_1 ) ;
return - V_48 ;
}
F_11 ( 0 , V_12 -> V_34 + V_42 ) ;
if ( V_41 != 0x400 && V_41 != 0x2000 ) {
F_17 ( V_12 -> V_47 ,
L_2 ,
V_41 ) ;
return - V_48 ;
}
return V_41 ;
}
static int F_18 ( struct V_11 * V_12 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
unsigned long V_53 )
{
unsigned int V_54 ;
V_54 = F_16 ( V_12 -> V_34 + V_45 ) ;
if ( V_54 & V_55 )
return 0 ;
return - V_56 ;
}
static int F_19 ( struct V_11 * V_12 ,
struct V_49 * V_50 , struct V_51 * V_52 ,
unsigned int * V_57 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
int V_58 ;
int V_59 ;
F_11 ( 0 , V_12 -> V_34 + V_42 ) ;
F_10 ( V_12 , 1 , & V_52 -> V_13 ) ;
F_11 ( 0 , V_12 -> V_34 + V_43 ) ;
for ( V_59 = 0 ; V_59 < V_52 -> V_59 ; V_59 ++ ) {
unsigned short V_60 ;
F_14 ( 0 , V_12 -> V_34 + V_45 ) ;
V_58 = F_20 ( V_12 , V_50 , V_52 , F_18 , 0 ) ;
if ( V_58 )
return V_58 ;
V_60 = F_21 ( V_18 -> V_61 + V_62 ) ;
V_60 = V_60 >> 3 ;
if ( F_22 ( 0 , V_18 -> V_25 ) )
V_60 = F_23 ( V_50 , V_60 ) ;
V_57 [ V_59 ] = V_60 & V_50 -> V_63 ;
}
return V_59 ;
}
static int F_24 ( struct V_11 * V_12 , struct V_49 * V_50 ,
int V_64 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_64 ; V_33 ++ ) {
unsigned short V_60 ;
if ( 0 == V_18 -> V_65 ) {
V_60 = F_21 ( V_18 -> V_61 + V_62 ) ;
continue;
}
V_60 = F_21 ( V_18 -> V_61 + V_62 ) ;
V_60 = V_60 >> 3 ;
if ( F_22 ( V_50 -> V_66 -> V_67 , V_18 -> V_25 ) )
V_60 = F_23 ( V_50 , V_60 ) ;
V_60 &= V_50 -> V_63 ;
if ( ! F_25 ( V_50 , V_60 ) )
return - 1 ;
if ( V_18 -> V_65 > 0 )
V_18 -> V_65 -- ;
}
return 0 ;
}
static int F_26 ( struct V_11 * V_12 , struct V_49 * V_50 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
while ( F_16 ( V_12 -> V_34 + V_45 ) & V_55 ) {
unsigned short V_60 = F_21 ( V_18 -> V_61 + V_62 ) ;
if ( 0 == V_18 -> V_65 ) {
continue;
}
V_60 = V_60 >> 3 ;
if ( F_22 ( V_50 -> V_66 -> V_67 , V_18 -> V_25 ) )
V_60 = F_23 ( V_50 , V_60 ) ;
V_60 &= V_50 -> V_63 ;
if ( ! F_25 ( V_50 , V_60 ) )
return - 1 ;
if ( V_18 -> V_65 > 0 )
V_18 -> V_65 -- ;
}
return 0 ;
}
static T_1 F_27 ( int V_68 , void * V_60 )
{
struct V_11 * V_12 = V_60 ;
struct V_49 * V_50 = V_12 -> V_69 ;
struct V_17 * V_18 = V_12 -> V_19 ;
T_2 V_70 ;
T_3 V_54 ;
T_3 V_44 ;
if ( ! V_12 -> V_71 )
return V_72 ;
V_44 = F_16 ( V_12 -> V_34 + V_45 ) ;
if ( ! ( V_44 & V_73 ) )
goto V_74;
V_54 = F_21 ( V_12 -> V_34 + V_75 ) ;
if ( 0 == V_54 )
return V_76 ;
if ( V_54 & V_77 ) {
if ( ! ( V_44 & V_46 ) ) {
if ( F_24 ( V_12 , V_50 , V_18 -> V_78 / 2 ) < 0 )
goto V_74;
if ( 0 == V_18 -> V_65 )
goto V_79;
F_28 ( V_12 , V_50 ) ;
} else if ( V_18 -> V_80 > 0 ) {
if ( V_44 & V_55 ) {
if ( F_24 ( V_12 , V_50 , V_18 -> V_80 ) < 0 )
goto V_74;
if ( 0 == V_18 -> V_65 )
goto V_79;
F_28 ( V_12 , V_50 ) ;
}
}
}
V_70 = F_16 ( V_12 -> V_34 + V_81 ) & 0xffff ;
if ( V_70 )
goto V_74;
F_14 ( V_54 , V_12 -> V_34 + V_82 ) ;
F_21 ( V_12 -> V_34 + V_82 ) ;
return V_76 ;
V_74:
F_11 ( 0 , V_12 -> V_34 + V_42 ) ;
V_50 -> V_66 -> V_83 |= V_84 ;
V_18 -> V_65 = 0 ;
V_79:
F_11 ( 0 , V_12 -> V_34 + V_85 ) ;
F_11 ( 0 , V_12 -> V_34 + V_86 ) ;
F_11 ( 0 , V_12 -> V_34 + V_43 ) ;
F_14 ( 0 , V_12 -> V_34 + V_75 ) ;
if ( V_18 -> V_65 > 0 ) {
V_44 = F_16 ( V_12 -> V_34 + V_45 ) ;
F_26 ( V_12 , V_50 ) ;
}
V_50 -> V_66 -> V_83 |= V_87 ;
F_28 ( V_12 , V_50 ) ;
V_54 = F_21 ( V_12 -> V_34 + V_75 ) ;
F_14 ( V_54 , V_12 -> V_34 + V_82 ) ;
F_21 ( V_12 -> V_34 + V_82 ) ;
V_44 = F_16 ( V_12 -> V_34 + V_45 ) ;
V_70 = F_16 ( V_12 -> V_34 + V_81 ) & 0xffff ;
return V_76 ;
}
static int F_29 ( struct V_11 * V_12 ,
struct V_49 * V_50 , struct V_88 * V_89 )
{
int V_90 = 0 ;
unsigned int V_91 ;
V_90 |= F_30 ( & V_89 -> V_92 , V_93 ) ;
V_90 |= F_30 ( & V_89 -> V_94 ,
V_95 | V_96 ) ;
V_90 |= F_30 ( & V_89 -> V_97 , V_95 | V_96 ) ;
V_90 |= F_30 ( & V_89 -> V_98 , V_99 ) ;
V_90 |= F_30 ( & V_89 -> V_100 , V_99 | V_101 ) ;
if ( V_90 )
return 1 ;
V_90 |= F_31 ( V_89 -> V_94 ) ;
V_90 |= F_31 ( V_89 -> V_97 ) ;
V_90 |= F_31 ( V_89 -> V_100 ) ;
if ( V_90 )
return 2 ;
V_90 |= F_32 ( & V_89 -> V_102 , 0 ) ;
if ( V_89 -> V_94 == V_95 ) {
if ( 1 == V_89 -> V_103 ) {
if ( F_33 ( & V_89 -> V_104 ,
V_105 ) ) {
F_2 ( & V_89 -> V_104 ,
V_8 ) ;
V_90 |= - V_106 ;
}
if ( F_34 ( & V_89 -> V_104 ,
V_107 ) ) {
F_2 ( & V_89 -> V_104 ,
V_7 ) ;
V_90 |= - V_106 ;
}
} else {
if ( F_33 ( & V_89 -> V_104 ,
V_108 ) ) {
F_2 ( & V_89 -> V_104 ,
V_8 ) ;
V_90 |= - V_106 ;
}
if ( F_34 ( & V_89 -> V_104 ,
V_109 ) ) {
F_2 ( & V_89 -> V_104 ,
V_7 ) ;
V_90 |= - V_106 ;
}
}
} else {
V_90 |= F_34 ( & V_89 -> V_104 , 9 ) ;
}
if ( V_89 -> V_97 == V_95 ) {
if ( 1 == V_89 -> V_103 ) {
if ( F_33 ( & V_89 -> V_110 ,
V_105 ) ) {
F_2 ( & V_89 -> V_110 ,
V_8 ) ;
V_90 |= - V_106 ;
}
if ( F_34 ( & V_89 -> V_110 ,
V_107 ) ) {
F_2 ( & V_89 -> V_110 ,
V_7 ) ;
V_90 |= - V_106 ;
}
} else {
if ( F_33 ( & V_89 -> V_110 ,
V_108 ) ) {
F_2 ( & V_89 -> V_110 ,
V_8 ) ;
V_90 |= - V_106 ;
}
if ( F_34 ( & V_89 -> V_110 ,
V_109 ) ) {
F_2 ( & V_89 -> V_110 ,
V_7 ) ;
V_90 |= - V_106 ;
}
}
} else {
V_90 |= F_34 ( & V_89 -> V_110 , 9 ) ;
}
V_90 |= F_32 ( & V_89 -> V_111 , V_89 -> V_103 ) ;
if ( V_89 -> V_100 == V_99 ) {
} else {
V_90 |= F_32 ( & V_89 -> V_112 , 0 ) ;
}
if ( V_90 )
return 3 ;
if ( V_89 -> V_94 == V_95 ) {
V_91 = V_89 -> V_104 ;
F_2 ( & V_91 , V_89 -> V_2 ) ;
V_90 |= F_32 ( & V_89 -> V_104 , V_91 ) ;
}
if ( V_89 -> V_97 == V_95 ) {
V_91 = V_89 -> V_110 ;
F_2 ( & V_91 , V_89 -> V_2 ) ;
V_90 |= F_32 ( & V_89 -> V_110 , V_91 ) ;
if ( V_89 -> V_94 == V_95 ) {
V_91 = V_89 -> V_110 * V_89 -> V_111 ;
V_90 |= F_33 ( & V_89 -> V_104 ,
V_91 ) ;
}
}
if ( V_90 )
return 4 ;
return 0 ;
}
static int F_35 ( struct V_11 * V_12 , struct V_49 * V_50 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
struct V_88 * V_89 = & V_50 -> V_66 -> V_89 ;
int V_113 ;
F_11 ( 0 , V_12 -> V_34 + V_85 ) ;
F_11 ( 0 , V_12 -> V_34 + V_86 ) ;
F_11 ( 0 , V_12 -> V_34 + V_43 ) ;
F_14 ( 0 , V_12 -> V_34 + V_75 ) ;
F_11 ( 0 , V_12 -> V_34 + V_42 ) ;
F_11 ( 0 , V_12 -> V_34 + V_81 ) ;
F_10 ( V_12 , V_89 -> V_103 , V_89 -> V_114 ) ;
if ( V_89 -> V_103 > 1 ) {
F_11 ( 0 , V_12 -> V_34 + V_115 ) ;
F_11 ( 1 , V_12 -> V_34 + V_116 ) ;
F_11 ( 2 , V_12 -> V_34 + V_43 ) ;
} else {
F_11 ( 0 , V_12 -> V_34 + V_115 ) ;
F_11 ( 1 , V_12 -> V_34 + V_43 ) ;
}
F_11 ( ( V_18 -> V_78 / 2 - 1 ) & 0xffff , V_12 -> V_34 + V_117 ) ;
if ( V_95 == V_89 -> V_94 ) {
if ( V_89 -> V_2 & V_118 ) {
V_18 -> V_80 = V_89 -> V_103 ;
V_18 -> V_2 |= V_119 ;
} else {
V_18 -> V_80 =
( V_120 * V_89 -> V_103 ) /
V_89 -> V_104 ;
if ( V_18 -> V_80 < V_89 -> V_103 ) {
V_18 -> V_80 = V_89 -> V_103 ;
} else {
V_18 -> V_80 =
( V_18 -> V_80 +
V_89 -> V_103 - 1 )
/ V_89 -> V_103 ;
V_18 -> V_80 *= V_89 -> V_103 ;
}
V_18 -> V_2 |= V_119 ;
}
if ( V_18 -> V_80 >= ( V_18 -> V_78 / 2 ) ) {
V_18 -> V_80 = 0 ;
V_18 -> V_2 &= ~ V_119 ;
} else {
F_11 ( ( V_18 -> V_80 - 1 ) & 0xffff ,
V_12 -> V_34 + V_117 ) ;
}
} else {
V_18 -> V_80 = 0 ;
V_18 -> V_2 &= ~ V_119 ;
}
F_11 ( 1 , V_12 -> V_34 + V_121 ) ;
F_11 ( 1 , V_12 -> V_34 + V_122 ) ;
switch ( V_89 -> V_100 ) {
case V_99 :
V_18 -> V_65 = V_89 -> V_112 * V_89 -> V_103 ;
if ( ( V_18 -> V_80 > 0 )
&& ( V_18 -> V_80 > V_18 -> V_65 ) ) {
V_18 -> V_80 = V_18 -> V_65 ;
}
break;
case V_101 :
V_18 -> V_65 = - 1 ;
break;
}
switch ( V_89 -> V_94 ) {
case V_95 :
V_113 = F_2 ( & V_89 -> V_104 ,
V_6 ) ;
F_11 ( V_113 & 0xffffff , V_12 -> V_34 + V_123 ) ;
break;
case V_96 :
F_11 ( 1 , V_12 -> V_34 + V_115 ) ;
break;
}
switch ( V_89 -> V_97 ) {
case V_95 :
if ( V_89 -> V_103 > 1 ) {
V_113 = F_2 ( & V_89 -> V_110 ,
V_6 ) ;
F_11 ( V_113 & 0x3ff , V_12 -> V_34 + V_124 ) ;
}
break;
case V_96 :
F_11 ( 2 , V_12 -> V_34 + V_116 ) ;
break;
}
F_14 ( ~ 0 , V_12 -> V_34 + V_82 ) ;
F_21 ( V_12 -> V_34 + V_82 ) ;
if ( V_18 -> V_80 > 0 )
F_14 ( V_77 , V_12 -> V_34 + V_75 ) ;
else
F_14 ( V_77 , V_12 -> V_34 + V_75 ) ;
F_16 ( V_12 -> V_34 + V_86 ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_49 * V_50 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
T_2 V_70 ;
T_3 V_54 ;
F_11 ( 0 , V_12 -> V_34 + V_85 ) ;
F_11 ( 0 , V_12 -> V_34 + V_86 ) ;
F_11 ( 0 , V_12 -> V_34 + V_43 ) ;
F_14 ( 0 , V_12 -> V_34 + V_75 ) ;
V_18 -> V_65 = 0 ;
V_54 = F_21 ( V_12 -> V_34 + V_75 ) ;
V_70 = F_16 ( V_12 -> V_34 + V_81 ) & 0xffff ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
unsigned long V_53 )
{
unsigned int V_20 = F_5 ( V_52 -> V_13 ) ;
unsigned int V_125 = ( V_20 == 0 ) ? V_126 : V_127 ;
unsigned int V_54 ;
V_54 = F_16 ( V_12 -> V_34 + V_45 ) ;
if ( V_54 & V_125 )
return 0 ;
return - V_56 ;
}
static int F_38 ( struct V_11 * V_12 ,
struct V_49 * V_50 , struct V_51 * V_52 ,
unsigned int * V_57 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
int V_39 ;
int V_20 = F_5 ( V_52 -> V_13 ) ;
int V_21 = F_6 ( V_52 -> V_13 ) ;
int V_58 ;
F_14 ( V_21 & 7 ,
V_12 -> V_34 + ( ( V_20 == 0 ) ? V_128 : V_129 ) ) ;
for ( V_39 = 0 ; V_39 < V_52 -> V_59 ; ++ V_39 ) {
int V_130 = V_57 [ V_39 ] << 3 ;
if ( ( V_21 > 1 )
&& ( V_57 [ V_39 ] < 2048 ) ) {
V_130 = ( ( ( int ) V_57 [ V_39 ] ) - 2048 ) << 3 ;
} else {
V_130 = V_57 [ V_39 ] << 3 ;
}
F_14 ( V_130 , V_18 -> V_61 +
( ( V_20 == 0 ) ? V_131 : V_132 ) ) ;
F_14 ( 0 , V_12 -> V_34 + ( ( V_20 == 0 ) ? V_133 : V_134 ) ) ;
V_18 -> V_135 [ V_20 ] = V_57 [ V_39 ] ;
V_58 = F_20 ( V_12 , V_50 , V_52 , F_37 , 0 ) ;
if ( V_58 )
return V_58 ;
}
return V_39 ;
}
static int F_39 ( struct V_11 * V_12 ,
struct V_49 * V_50 , struct V_51 * V_52 ,
unsigned int * V_57 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
int V_39 ;
int V_20 = F_5 ( V_52 -> V_13 ) ;
for ( V_39 = 0 ; V_39 < V_52 -> V_59 ; V_39 ++ )
V_57 [ V_39 ] = V_18 -> V_135 [ V_20 ] ;
return V_39 ;
}
static int F_40 ( struct V_11 * V_12 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
unsigned int * V_57 )
{
if ( F_41 ( V_50 , V_57 ) )
F_14 ( V_50 -> V_136 & 0xff , V_12 -> V_34 + V_137 ) ;
V_57 [ 1 ] = F_21 ( V_12 -> V_34 + V_137 ) & 0xff ;
return V_52 -> V_59 ;
}
static int F_42 ( struct V_11 * V_12 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
unsigned int * V_57 )
{
int V_58 ;
V_58 = F_43 ( V_12 , V_50 , V_52 , V_57 , 0 ) ;
if ( V_58 )
return V_58 ;
F_14 ( 0x01 , V_12 -> V_34 + V_138 ) ;
F_14 ( V_50 -> V_139 & 0xff , V_12 -> V_34 + V_140 ) ;
F_14 ( 0x00 , V_12 -> V_34 + V_138 ) ;
return V_52 -> V_59 ;
}
static void F_44 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
F_11 ( 0 , V_12 -> V_34 + V_141 ) ;
F_15 ( 100 ) ;
F_11 ( 0 , V_18 -> V_142 + V_143 ) ;
F_14 ( 0 , V_12 -> V_34 + V_75 ) ;
F_14 ( ~ 0 , V_12 -> V_34 + V_82 ) ;
F_21 ( V_12 -> V_34 + V_82 ) ;
}
static void F_45 ( struct V_11 * V_12 )
{
F_44 ( V_12 ) ;
F_11 ( 0 , V_12 -> V_34 + V_81 ) ;
F_11 ( 0 , V_12 -> V_34 + V_35 ) ;
F_11 ( 0 , V_12 -> V_34 + V_42 ) ;
F_11 ( 0 , V_12 -> V_34 + V_144 ) ;
F_11 ( 0 , V_12 -> V_34 + V_145 ) ;
F_14 ( 0 , V_12 -> V_34 + V_138 ) ;
F_46 ( ( 0 << 6 ) | 0x30 , V_12 -> V_34 + V_146 ) ;
F_46 ( ( 1 << 6 ) | 0x30 , V_12 -> V_34 + V_146 ) ;
F_46 ( ( 2 << 6 ) | 0x30 , V_12 -> V_34 + V_146 ) ;
F_46 ( ( 3 << 6 ) | 0x00 , V_12 -> V_34 + V_146 ) ;
}
static void F_47 ( struct V_11 * V_12 ,
struct V_147 * V_148 )
{
unsigned char V_149 ;
F_48 ( V_148 , V_150 , & V_149 ) ;
if ( V_149 < 32 ) {
F_17 ( V_12 -> V_47 ,
L_3 ,
V_149 , 32 ) ;
F_49 ( V_148 , V_150 , 32 ) ;
}
}
static int F_50 ( struct V_11 * V_12 ,
unsigned long V_53 )
{
struct V_147 * V_148 = F_51 ( V_12 ) ;
const struct V_15 * V_16 = NULL ;
struct V_17 * V_18 ;
struct V_49 * V_50 ;
int V_58 ;
if ( V_53 < F_52 ( V_151 ) )
V_16 = & V_151 [ V_53 ] ;
if ( ! V_16 )
return - V_152 ;
V_12 -> V_153 = V_16 ;
V_12 -> V_154 = V_16 -> V_155 ;
V_18 = F_53 ( V_12 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return - V_156 ;
V_58 = F_54 ( V_12 ) ;
if ( V_58 )
return V_58 ;
V_12 -> V_34 = F_55 ( V_148 , 2 ) ;
V_18 -> V_61 = F_55 ( V_148 , 3 ) ;
V_18 -> V_142 = F_55 ( V_148 , 0 ) ;
if ( ! V_12 -> V_34 || ! V_18 -> V_61 || ! V_18 -> V_142 )
return - V_156 ;
F_47 ( V_12 , V_148 ) ;
if ( V_148 -> V_68 ) {
V_58 = F_56 ( V_148 -> V_68 , F_27 , V_157 ,
V_12 -> V_154 , V_12 ) ;
if ( V_58 == 0 )
V_12 -> V_68 = V_148 -> V_68 ;
}
V_58 = F_57 ( V_12 , 4 ) ;
if ( V_58 )
return V_58 ;
V_50 = & V_12 -> V_158 [ 0 ] ;
V_50 -> type = V_159 ;
V_50 -> V_160 = V_161 | V_162 | V_163 | V_164 ;
V_50 -> V_31 = 16 ;
V_50 -> V_63 = 0x0fff ;
V_50 -> V_165 = V_16 -> V_166 ;
V_50 -> V_167 = V_168 ;
V_50 -> V_169 = F_19 ;
if ( V_12 -> V_68 ) {
V_12 -> V_69 = V_50 ;
V_50 -> V_160 |= V_170 ;
V_50 -> V_171 = F_35 ;
V_50 -> V_172 = F_29 ;
V_50 -> V_173 = F_36 ;
}
V_50 = & V_12 -> V_158 [ 1 ] ;
V_50 -> type = V_174 ;
V_50 -> V_160 = V_175 ;
V_50 -> V_31 = 2 ;
V_50 -> V_63 = 0x0fff ;
V_50 -> V_165 = & V_176 ;
V_50 -> V_177 = F_38 ;
V_50 -> V_169 = F_39 ;
V_50 = & V_12 -> V_158 [ 2 ] ;
V_50 -> type = V_178 ;
V_50 -> V_160 = V_161 | V_175 ;
V_50 -> V_31 = 8 ;
V_50 -> V_63 = 1 ;
V_50 -> V_165 = & V_179 ;
V_50 -> V_180 = F_40 ;
V_50 -> V_181 = F_42 ;
V_50 = & V_12 -> V_158 [ 3 ] ;
V_50 -> type = V_182 ;
V_50 -> V_160 = V_161 | V_175 ;
V_50 -> V_31 = 3 ;
V_50 -> V_63 = 0xffff ;
F_45 ( V_12 ) ;
V_58 = F_12 ( V_12 ) ;
if ( V_58 < 0 )
return V_58 ;
V_18 -> V_78 = V_58 ;
if ( V_12 -> V_68 )
F_11 ( V_183 | V_184 , V_18 -> V_142 + V_143 ) ;
return 0 ;
}
static void F_58 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
if ( V_18 ) {
if ( V_12 -> V_34 && V_18 -> V_142 )
F_44 ( V_12 ) ;
if ( V_12 -> V_68 ) {
F_11 ( F_16 ( V_18 -> V_142 + V_143 ) &
~ ( V_184 | V_185 | V_186 ) ,
V_18 -> V_142 + V_143 ) ;
F_59 ( V_12 -> V_68 , V_12 ) ;
}
if ( V_12 -> V_34 )
F_60 ( V_12 -> V_34 ) ;
if ( V_18 -> V_61 )
F_60 ( V_18 -> V_61 ) ;
if ( V_18 -> V_142 )
F_60 ( V_18 -> V_142 ) ;
}
F_61 ( V_12 ) ;
}
static int F_62 ( struct V_147 * V_12 ,
const struct V_187 * V_188 )
{
return F_63 ( V_12 , & V_189 , V_188 -> V_190 ) ;
}
