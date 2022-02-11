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
const struct V_15 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_12 -> V_20 ;
unsigned int V_21 = F_4 ( V_13 ) ;
unsigned int V_22 = F_5 ( V_13 ) ;
unsigned int V_23 = F_6 ( V_13 ) ;
unsigned short V_24 = 0 ;
V_24 |= V_21 & 0xf ;
if ( V_22 < V_16 -> V_25 ) {
V_24 |= 0x000 ;
V_24 |= ( V_22 & 0x7 ) << 4 ;
F_7 ( V_14 , V_19 -> V_26 ) ;
} else if ( V_22 < V_16 -> V_27 ) {
V_24 |= 0x100 ;
V_24 |= ( ( V_22 - V_16 -> V_25 ) & 0x7 ) << 4 ;
F_7 ( V_14 , V_19 -> V_26 ) ;
} else {
V_24 |= 0x200 ;
V_24 |= ( ( V_22 - V_16 -> V_27 ) & 0x7 ) << 4 ;
F_8 ( V_14 , V_19 -> V_26 ) ;
}
switch ( V_23 ) {
case V_28 :
break;
case V_29 :
V_24 |= 0x80 ;
break;
case V_30 :
V_24 |= 0x400 ;
break;
case V_31 :
break;
}
return V_24 ;
}
static void F_9 ( struct V_11 * V_12 ,
unsigned int V_32 , unsigned int * V_33 )
{
if ( V_32 > 1 ) {
int V_34 ;
F_10 ( 0 , V_12 -> V_35 + V_36 ) ;
F_10 ( 1 , V_12 -> V_35 + V_37 ) ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
F_10 ( F_3 ( V_12 , V_33 [ V_34 ] , V_34 ) ,
V_12 -> V_35 + V_38 ) ;
}
} else {
F_10 ( 0 , V_12 -> V_35 + V_37 ) ;
F_10 ( F_3 ( V_12 , V_33 [ 0 ] , 0 ) ,
V_12 -> V_35 + V_39 ) ;
}
}
static int F_11 ( struct V_11 * V_12 )
{
unsigned int V_13 = F_12 ( 0 , 0 , V_28 ) ;
unsigned V_40 ;
static const unsigned V_41 = 0x2000 ;
unsigned V_42 = 0 ;
F_10 ( 0 , V_12 -> V_35 + V_43 ) ;
F_9 ( V_12 , 1 , & V_13 ) ;
F_10 ( 0 , V_12 -> V_35 + V_44 ) ;
for ( V_40 = 0 ; V_40 < V_41 ; ++ V_40 ) {
unsigned V_45 ;
F_13 ( 0 , V_12 -> V_35 + V_46 ) ;
F_14 ( 1 ) ;
V_45 = F_15 ( V_12 -> V_35 + V_46 ) ;
if ( ( V_45 & V_47 ) == 0 ) {
V_42 = 2 * V_40 ;
break;
}
}
if ( V_40 == V_41 ) {
F_16 ( V_12 -> V_48 , L_1 ) ;
return - V_49 ;
}
F_10 ( 0 , V_12 -> V_35 + V_43 ) ;
if ( V_42 != 0x400 && V_42 != 0x2000 ) {
F_16 ( V_12 -> V_48 ,
L_2 ,
V_42 ) ;
return - V_49 ;
}
return V_42 ;
}
static int F_17 ( struct V_11 * V_12 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
unsigned long V_54 )
{
unsigned int V_55 ;
V_55 = F_15 ( V_12 -> V_35 + V_46 ) ;
if ( V_55 & V_56 )
return 0 ;
return - V_57 ;
}
static int F_18 ( struct V_11 * V_12 ,
struct V_50 * V_51 , struct V_52 * V_53 ,
unsigned int * V_58 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
int V_59 ;
int V_60 ;
F_10 ( 0 , V_12 -> V_35 + V_43 ) ;
F_9 ( V_12 , 1 , & V_53 -> V_13 ) ;
F_10 ( 0 , V_12 -> V_35 + V_44 ) ;
for ( V_60 = 0 ; V_60 < V_53 -> V_60 ; V_60 ++ ) {
unsigned short V_61 ;
F_13 ( 0 , V_12 -> V_35 + V_46 ) ;
V_59 = F_19 ( V_12 , V_51 , V_53 , F_17 , 0 ) ;
if ( V_59 )
return V_59 ;
V_61 = F_20 ( V_19 -> V_62 + V_63 ) ;
V_61 = V_61 >> 3 ;
if ( F_21 ( 0 , V_19 -> V_26 ) )
V_61 = F_22 ( V_51 , V_61 ) ;
V_58 [ V_60 ] = V_61 & V_51 -> V_64 ;
}
return V_60 ;
}
static int F_23 ( struct V_11 * V_12 , struct V_50 * V_51 ,
int V_65 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_65 ; V_34 ++ ) {
unsigned short V_61 ;
if ( 0 == V_19 -> V_66 ) {
V_61 = F_20 ( V_19 -> V_62 + V_63 ) ;
continue;
}
V_61 = F_20 ( V_19 -> V_62 + V_63 ) ;
V_61 = V_61 >> 3 ;
if ( F_21 ( V_51 -> V_67 -> V_68 , V_19 -> V_26 ) )
V_61 = F_22 ( V_51 , V_61 ) ;
V_61 &= V_51 -> V_64 ;
if ( ! F_24 ( V_51 , V_61 ) )
return - 1 ;
if ( V_19 -> V_66 > 0 )
V_19 -> V_66 -- ;
}
return 0 ;
}
static int F_25 ( struct V_11 * V_12 , struct V_50 * V_51 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
while ( F_15 ( V_12 -> V_35 + V_46 ) & V_56 ) {
unsigned short V_61 = F_20 ( V_19 -> V_62 + V_63 ) ;
if ( 0 == V_19 -> V_66 ) {
continue;
}
V_61 = V_61 >> 3 ;
if ( F_21 ( V_51 -> V_67 -> V_68 , V_19 -> V_26 ) )
V_61 = F_22 ( V_51 , V_61 ) ;
V_61 &= V_51 -> V_64 ;
if ( ! F_24 ( V_51 , V_61 ) )
return - 1 ;
if ( V_19 -> V_66 > 0 )
V_19 -> V_66 -- ;
}
return 0 ;
}
static T_1 F_26 ( int V_69 , void * V_61 )
{
struct V_11 * V_12 = V_61 ;
struct V_50 * V_51 = V_12 -> V_70 ;
struct V_18 * V_19 = V_12 -> V_20 ;
T_2 V_71 ;
T_3 V_55 ;
T_3 V_45 ;
if ( ! V_12 -> V_72 )
return V_73 ;
V_45 = F_15 ( V_12 -> V_35 + V_46 ) ;
if ( ! ( V_45 & V_74 ) )
goto V_75;
V_55 = F_20 ( V_12 -> V_35 + V_76 ) ;
if ( 0 == V_55 )
return V_77 ;
if ( V_55 & V_78 ) {
if ( ! ( V_45 & V_47 ) ) {
if ( F_23 ( V_12 , V_51 , V_19 -> V_79 / 2 ) < 0 )
goto V_75;
if ( 0 == V_19 -> V_66 )
goto V_80;
F_27 ( V_12 , V_51 ) ;
} else if ( V_19 -> V_81 > 0 ) {
if ( V_45 & V_56 ) {
if ( F_23 ( V_12 , V_51 , V_19 -> V_81 ) < 0 )
goto V_75;
if ( 0 == V_19 -> V_66 )
goto V_80;
F_27 ( V_12 , V_51 ) ;
}
}
}
V_71 = F_15 ( V_12 -> V_35 + V_82 ) & 0xffff ;
if ( V_71 )
goto V_75;
F_13 ( V_55 , V_12 -> V_35 + V_83 ) ;
F_20 ( V_12 -> V_35 + V_83 ) ;
return V_77 ;
V_75:
F_10 ( 0 , V_12 -> V_35 + V_43 ) ;
V_51 -> V_67 -> V_84 |= V_85 ;
V_19 -> V_66 = 0 ;
V_80:
F_10 ( 0 , V_12 -> V_35 + V_86 ) ;
F_10 ( 0 , V_12 -> V_35 + V_87 ) ;
F_10 ( 0 , V_12 -> V_35 + V_44 ) ;
F_13 ( 0 , V_12 -> V_35 + V_76 ) ;
if ( V_19 -> V_66 > 0 ) {
V_45 = F_15 ( V_12 -> V_35 + V_46 ) ;
F_25 ( V_12 , V_51 ) ;
}
V_51 -> V_67 -> V_84 |= V_88 ;
F_27 ( V_12 , V_51 ) ;
V_55 = F_20 ( V_12 -> V_35 + V_76 ) ;
F_13 ( V_55 , V_12 -> V_35 + V_83 ) ;
F_20 ( V_12 -> V_35 + V_83 ) ;
V_45 = F_15 ( V_12 -> V_35 + V_46 ) ;
V_71 = F_15 ( V_12 -> V_35 + V_82 ) & 0xffff ;
return V_77 ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_50 * V_51 , struct V_89 * V_90 )
{
int V_91 = 0 ;
unsigned int V_92 ;
V_91 |= F_29 ( & V_90 -> V_93 , V_94 ) ;
V_91 |= F_29 ( & V_90 -> V_95 ,
V_96 | V_97 ) ;
V_91 |= F_29 ( & V_90 -> V_98 , V_96 | V_97 ) ;
V_91 |= F_29 ( & V_90 -> V_99 , V_100 ) ;
V_91 |= F_29 ( & V_90 -> V_101 , V_100 | V_102 ) ;
if ( V_91 )
return 1 ;
V_91 |= F_30 ( V_90 -> V_95 ) ;
V_91 |= F_30 ( V_90 -> V_98 ) ;
V_91 |= F_30 ( V_90 -> V_101 ) ;
if ( V_91 )
return 2 ;
V_91 |= F_31 ( & V_90 -> V_103 , 0 ) ;
if ( V_90 -> V_95 == V_96 ) {
if ( 1 == V_90 -> V_104 ) {
if ( F_32 ( & V_90 -> V_105 ,
V_106 ) ) {
F_2 ( & V_90 -> V_105 ,
V_8 ) ;
V_91 |= - V_107 ;
}
if ( F_33 ( & V_90 -> V_105 ,
V_108 ) ) {
F_2 ( & V_90 -> V_105 ,
V_7 ) ;
V_91 |= - V_107 ;
}
} else {
if ( F_32 ( & V_90 -> V_105 ,
V_109 ) ) {
F_2 ( & V_90 -> V_105 ,
V_8 ) ;
V_91 |= - V_107 ;
}
if ( F_33 ( & V_90 -> V_105 ,
V_110 ) ) {
F_2 ( & V_90 -> V_105 ,
V_7 ) ;
V_91 |= - V_107 ;
}
}
} else {
V_91 |= F_33 ( & V_90 -> V_105 , 9 ) ;
}
if ( V_90 -> V_98 == V_96 ) {
if ( 1 == V_90 -> V_104 ) {
if ( F_32 ( & V_90 -> V_111 ,
V_106 ) ) {
F_2 ( & V_90 -> V_111 ,
V_8 ) ;
V_91 |= - V_107 ;
}
if ( F_33 ( & V_90 -> V_111 ,
V_108 ) ) {
F_2 ( & V_90 -> V_111 ,
V_7 ) ;
V_91 |= - V_107 ;
}
} else {
if ( F_32 ( & V_90 -> V_111 ,
V_109 ) ) {
F_2 ( & V_90 -> V_111 ,
V_8 ) ;
V_91 |= - V_107 ;
}
if ( F_33 ( & V_90 -> V_111 ,
V_110 ) ) {
F_2 ( & V_90 -> V_111 ,
V_7 ) ;
V_91 |= - V_107 ;
}
}
} else {
V_91 |= F_33 ( & V_90 -> V_111 , 9 ) ;
}
V_91 |= F_31 ( & V_90 -> V_112 , V_90 -> V_104 ) ;
if ( V_90 -> V_101 == V_100 )
V_91 |= F_32 ( & V_90 -> V_113 , 1 ) ;
else
V_91 |= F_31 ( & V_90 -> V_113 , 0 ) ;
if ( V_91 )
return 3 ;
if ( V_90 -> V_95 == V_96 ) {
V_92 = V_90 -> V_105 ;
F_2 ( & V_92 , V_90 -> V_2 ) ;
V_91 |= F_31 ( & V_90 -> V_105 , V_92 ) ;
}
if ( V_90 -> V_98 == V_96 ) {
V_92 = V_90 -> V_111 ;
F_2 ( & V_92 , V_90 -> V_2 ) ;
V_91 |= F_31 ( & V_90 -> V_111 , V_92 ) ;
if ( V_90 -> V_95 == V_96 ) {
V_92 = V_90 -> V_111 * V_90 -> V_112 ;
V_91 |= F_32 ( & V_90 -> V_105 ,
V_92 ) ;
}
}
if ( V_91 )
return 4 ;
return 0 ;
}
static int F_34 ( struct V_11 * V_12 , struct V_50 * V_51 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_89 * V_90 = & V_51 -> V_67 -> V_90 ;
int V_114 ;
F_10 ( 0 , V_12 -> V_35 + V_86 ) ;
F_10 ( 0 , V_12 -> V_35 + V_87 ) ;
F_10 ( 0 , V_12 -> V_35 + V_44 ) ;
F_13 ( 0 , V_12 -> V_35 + V_76 ) ;
F_10 ( 0 , V_12 -> V_35 + V_43 ) ;
F_10 ( 0 , V_12 -> V_35 + V_82 ) ;
F_9 ( V_12 , V_90 -> V_104 , V_90 -> V_115 ) ;
if ( V_90 -> V_104 > 1 ) {
F_10 ( 0 , V_12 -> V_35 + V_116 ) ;
F_10 ( 1 , V_12 -> V_35 + V_117 ) ;
F_10 ( 2 , V_12 -> V_35 + V_44 ) ;
} else {
F_10 ( 0 , V_12 -> V_35 + V_116 ) ;
F_10 ( 1 , V_12 -> V_35 + V_44 ) ;
}
F_10 ( ( V_19 -> V_79 / 2 - 1 ) & 0xffff , V_12 -> V_35 + V_118 ) ;
if ( V_96 == V_90 -> V_95 ) {
if ( V_90 -> V_2 & V_119 ) {
V_19 -> V_81 = V_90 -> V_104 ;
V_19 -> V_2 |= V_120 ;
} else {
V_19 -> V_81 =
( V_121 * V_90 -> V_104 ) /
V_90 -> V_105 ;
if ( V_19 -> V_81 < V_90 -> V_104 ) {
V_19 -> V_81 = V_90 -> V_104 ;
} else {
V_19 -> V_81 =
( V_19 -> V_81 +
V_90 -> V_104 - 1 )
/ V_90 -> V_104 ;
V_19 -> V_81 *= V_90 -> V_104 ;
}
V_19 -> V_2 |= V_120 ;
}
if ( V_19 -> V_81 >= ( V_19 -> V_79 / 2 ) ) {
V_19 -> V_81 = 0 ;
V_19 -> V_2 &= ~ V_120 ;
} else {
F_10 ( ( V_19 -> V_81 - 1 ) & 0xffff ,
V_12 -> V_35 + V_118 ) ;
}
} else {
V_19 -> V_81 = 0 ;
V_19 -> V_2 &= ~ V_120 ;
}
F_10 ( 1 , V_12 -> V_35 + V_122 ) ;
F_10 ( 1 , V_12 -> V_35 + V_123 ) ;
switch ( V_90 -> V_101 ) {
case V_100 :
V_19 -> V_66 = V_90 -> V_113 * V_90 -> V_104 ;
if ( ( V_19 -> V_81 > 0 )
&& ( V_19 -> V_81 > V_19 -> V_66 ) ) {
V_19 -> V_81 = V_19 -> V_66 ;
}
break;
case V_102 :
V_19 -> V_66 = - 1 ;
break;
}
switch ( V_90 -> V_95 ) {
case V_96 :
V_114 = F_2 ( & V_90 -> V_105 ,
V_6 ) ;
F_10 ( V_114 & 0xffffff , V_12 -> V_35 + V_124 ) ;
break;
case V_97 :
F_10 ( 1 , V_12 -> V_35 + V_116 ) ;
break;
}
switch ( V_90 -> V_98 ) {
case V_96 :
if ( V_90 -> V_104 > 1 ) {
V_114 = F_2 ( & V_90 -> V_111 ,
V_6 ) ;
F_10 ( V_114 & 0x3ff , V_12 -> V_35 + V_125 ) ;
}
break;
case V_97 :
F_10 ( 2 , V_12 -> V_35 + V_117 ) ;
break;
}
F_13 ( ~ 0 , V_12 -> V_35 + V_83 ) ;
F_20 ( V_12 -> V_35 + V_83 ) ;
if ( V_19 -> V_81 > 0 )
F_13 ( V_78 , V_12 -> V_35 + V_76 ) ;
else
F_13 ( V_78 , V_12 -> V_35 + V_76 ) ;
F_15 ( V_12 -> V_35 + V_87 ) ;
return 0 ;
}
static int F_35 ( struct V_11 * V_12 , struct V_50 * V_51 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
T_2 V_71 ;
T_3 V_55 ;
F_10 ( 0 , V_12 -> V_35 + V_86 ) ;
F_10 ( 0 , V_12 -> V_35 + V_87 ) ;
F_10 ( 0 , V_12 -> V_35 + V_44 ) ;
F_13 ( 0 , V_12 -> V_35 + V_76 ) ;
V_19 -> V_66 = 0 ;
V_55 = F_20 ( V_12 -> V_35 + V_76 ) ;
V_71 = F_15 ( V_12 -> V_35 + V_82 ) & 0xffff ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
unsigned long V_54 )
{
unsigned int V_21 = F_4 ( V_53 -> V_13 ) ;
unsigned int V_126 = ( V_21 == 0 ) ? V_127 : V_128 ;
unsigned int V_55 ;
V_55 = F_15 ( V_12 -> V_35 + V_46 ) ;
if ( V_55 & V_126 )
return 0 ;
return - V_57 ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_50 * V_51 , struct V_52 * V_53 ,
unsigned int * V_58 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
int V_40 ;
int V_21 = F_4 ( V_53 -> V_13 ) ;
int V_22 = F_5 ( V_53 -> V_13 ) ;
int V_59 ;
F_13 ( V_22 & 7 ,
V_12 -> V_35 + ( ( V_21 == 0 ) ? V_129 : V_130 ) ) ;
for ( V_40 = 0 ; V_40 < V_53 -> V_60 ; ++ V_40 ) {
int V_131 = V_58 [ V_40 ] << 3 ;
if ( ( V_22 > 1 )
&& ( V_58 [ V_40 ] < 2048 ) ) {
V_131 = ( ( ( int ) V_58 [ V_40 ] ) - 2048 ) << 3 ;
} else {
V_131 = V_58 [ V_40 ] << 3 ;
}
F_13 ( V_131 , V_19 -> V_62 +
( ( V_21 == 0 ) ? V_132 : V_133 ) ) ;
F_13 ( 0 , V_12 -> V_35 + ( ( V_21 == 0 ) ? V_134 : V_135 ) ) ;
V_51 -> V_136 [ V_21 ] = V_58 [ V_40 ] ;
V_59 = F_19 ( V_12 , V_51 , V_53 , F_36 , 0 ) ;
if ( V_59 )
return V_59 ;
}
return V_40 ;
}
static int F_38 ( struct V_11 * V_12 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
unsigned int * V_58 )
{
if ( F_39 ( V_51 , V_58 ) )
F_13 ( V_51 -> V_137 & 0xff , V_12 -> V_35 + V_138 ) ;
V_58 [ 1 ] = F_20 ( V_12 -> V_35 + V_138 ) & 0xff ;
return V_53 -> V_60 ;
}
static int F_40 ( struct V_11 * V_12 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
unsigned int * V_58 )
{
int V_59 ;
V_59 = F_41 ( V_12 , V_51 , V_53 , V_58 , 0 ) ;
if ( V_59 )
return V_59 ;
F_13 ( 0x01 , V_12 -> V_35 + V_139 ) ;
F_13 ( V_51 -> V_140 & 0xff , V_12 -> V_35 + V_141 ) ;
F_13 ( 0x00 , V_12 -> V_35 + V_139 ) ;
return V_53 -> V_60 ;
}
static void F_42 ( struct V_11 * V_12 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
F_10 ( 0 , V_12 -> V_35 + V_142 ) ;
F_14 ( 100 ) ;
F_10 ( 0 , V_19 -> V_143 + V_144 ) ;
F_13 ( 0 , V_12 -> V_35 + V_76 ) ;
F_13 ( ~ 0 , V_12 -> V_35 + V_83 ) ;
F_20 ( V_12 -> V_35 + V_83 ) ;
}
static void F_43 ( struct V_11 * V_12 )
{
F_42 ( V_12 ) ;
F_10 ( 0 , V_12 -> V_35 + V_82 ) ;
F_10 ( 0 , V_12 -> V_35 + V_36 ) ;
F_10 ( 0 , V_12 -> V_35 + V_43 ) ;
F_10 ( 0 , V_12 -> V_35 + V_145 ) ;
F_10 ( 0 , V_12 -> V_35 + V_146 ) ;
F_13 ( 0 , V_12 -> V_35 + V_139 ) ;
F_44 ( ( 0 << 6 ) | 0x30 , V_12 -> V_35 + V_147 ) ;
F_44 ( ( 1 << 6 ) | 0x30 , V_12 -> V_35 + V_147 ) ;
F_44 ( ( 2 << 6 ) | 0x30 , V_12 -> V_35 + V_147 ) ;
F_44 ( ( 3 << 6 ) | 0x00 , V_12 -> V_35 + V_147 ) ;
}
static void F_45 ( struct V_11 * V_12 ,
struct V_148 * V_149 )
{
unsigned char V_150 ;
F_46 ( V_149 , V_151 , & V_150 ) ;
if ( V_150 < 32 ) {
F_16 ( V_12 -> V_48 ,
L_3 ,
V_150 , 32 ) ;
F_47 ( V_149 , V_151 , 32 ) ;
}
}
static int F_48 ( struct V_11 * V_12 ,
unsigned long V_54 )
{
struct V_148 * V_149 = F_49 ( V_12 ) ;
const struct V_15 * V_16 = NULL ;
struct V_18 * V_19 ;
struct V_50 * V_51 ;
int V_59 ;
if ( V_54 < F_50 ( V_152 ) )
V_16 = & V_152 [ V_54 ] ;
if ( ! V_16 )
return - V_153 ;
V_12 -> V_17 = V_16 ;
V_12 -> V_154 = V_16 -> V_155 ;
V_19 = F_51 ( V_12 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_156 ;
V_59 = F_52 ( V_12 ) ;
if ( V_59 )
return V_59 ;
V_12 -> V_35 = F_53 ( V_149 , 2 ) ;
V_19 -> V_62 = F_53 ( V_149 , 3 ) ;
V_19 -> V_143 = F_53 ( V_149 , 0 ) ;
if ( ! V_12 -> V_35 || ! V_19 -> V_62 || ! V_19 -> V_143 )
return - V_156 ;
F_45 ( V_12 , V_149 ) ;
if ( V_149 -> V_69 ) {
V_59 = F_54 ( V_149 -> V_69 , F_26 , V_157 ,
V_12 -> V_154 , V_12 ) ;
if ( V_59 == 0 )
V_12 -> V_69 = V_149 -> V_69 ;
}
V_59 = F_55 ( V_12 , 4 ) ;
if ( V_59 )
return V_59 ;
V_51 = & V_12 -> V_158 [ 0 ] ;
V_51 -> type = V_159 ;
V_51 -> V_160 = V_161 | V_162 | V_163 | V_164 ;
V_51 -> V_32 = 16 ;
V_51 -> V_64 = 0x0fff ;
V_51 -> V_165 = V_16 -> V_166 ;
V_51 -> V_167 = V_168 ;
V_51 -> V_169 = F_18 ;
if ( V_12 -> V_69 ) {
V_12 -> V_70 = V_51 ;
V_51 -> V_160 |= V_170 ;
V_51 -> V_171 = F_34 ;
V_51 -> V_172 = F_28 ;
V_51 -> V_173 = F_35 ;
}
V_51 = & V_12 -> V_158 [ 1 ] ;
V_51 -> type = V_174 ;
V_51 -> V_160 = V_175 ;
V_51 -> V_32 = 2 ;
V_51 -> V_64 = 0x0fff ;
V_51 -> V_165 = & V_176 ;
V_51 -> V_177 = F_37 ;
V_51 -> V_169 = V_178 ;
V_59 = F_56 ( V_51 ) ;
if ( V_59 )
return V_59 ;
V_51 = & V_12 -> V_158 [ 2 ] ;
V_51 -> type = V_179 ;
V_51 -> V_160 = V_161 | V_175 ;
V_51 -> V_32 = 8 ;
V_51 -> V_64 = 1 ;
V_51 -> V_165 = & V_180 ;
V_51 -> V_181 = F_38 ;
V_51 -> V_182 = F_40 ;
V_51 = & V_12 -> V_158 [ 3 ] ;
V_51 -> type = V_183 ;
V_51 -> V_160 = V_161 | V_175 ;
V_51 -> V_32 = 3 ;
V_51 -> V_64 = 0xffff ;
F_43 ( V_12 ) ;
V_59 = F_11 ( V_12 ) ;
if ( V_59 < 0 )
return V_59 ;
V_19 -> V_79 = V_59 ;
if ( V_12 -> V_69 )
F_10 ( V_184 | V_185 , V_19 -> V_143 + V_144 ) ;
return 0 ;
}
static void F_57 ( struct V_11 * V_12 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
if ( V_19 ) {
if ( V_12 -> V_35 && V_19 -> V_143 )
F_42 ( V_12 ) ;
if ( V_12 -> V_69 ) {
F_10 ( F_15 ( V_19 -> V_143 + V_144 ) &
~ ( V_185 | V_186 | V_187 ) ,
V_19 -> V_143 + V_144 ) ;
F_58 ( V_12 -> V_69 , V_12 ) ;
}
if ( V_12 -> V_35 )
F_59 ( V_12 -> V_35 ) ;
if ( V_19 -> V_62 )
F_59 ( V_19 -> V_62 ) ;
if ( V_19 -> V_143 )
F_59 ( V_19 -> V_143 ) ;
}
F_60 ( V_12 ) ;
}
static int F_61 ( struct V_148 * V_12 ,
const struct V_188 * V_189 )
{
return F_62 ( V_12 , & V_190 , V_189 -> V_191 ) ;
}
