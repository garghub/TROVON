static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 ,
unsigned long V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_11 = F_3 ( V_7 , 5 ) ;
unsigned int V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
if ( ! V_11 )
return - V_15 ;
F_4 ( V_16 , V_9 -> V_17 + V_18 ) ;
V_13 = F_5 ( V_9 -> V_17 + V_19 ) ;
V_13 |= V_20 ;
F_4 ( V_13 , V_9 -> V_17 + V_19 ) ;
F_6 ( V_11 + 0xC8 ) ;
F_7 ( 20 ) ;
V_13 = F_5 ( V_9 -> V_17 + V_18 ) ;
if ( ! ( V_13 & V_21 ) ) {
F_8 ( V_2 -> V_22 , L_1 ) ;
return - V_23 ;
}
V_13 = F_5 ( V_9 -> V_17 + V_19 ) ;
V_13 &= ~ V_20 ;
F_4 ( V_13 , V_9 -> V_17 + V_19 ) ;
V_12 = ( ( ( unsigned int ) V_3 [ 0 ] & 0xff ) << 24 ) +
( ( ( unsigned int ) V_3 [ 1 ] & 0xff ) << 16 ) +
( ( ( unsigned int ) V_3 [ 2 ] & 0xff ) << 8 ) +
( ( unsigned int ) V_3 [ 3 ] & 0xff ) ;
F_7 ( 10 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
F_9 ( V_3 [ 16 + V_14 ] , V_11 ) ;
F_7 ( 10 ) ;
V_13 = F_5 ( V_9 -> V_17 + V_19 ) ;
if ( V_13 & V_24 ) {
F_8 ( V_2 -> V_22 ,
L_2 , V_14 ) ;
return - V_23 ;
}
}
V_13 = F_5 ( V_9 -> V_17 + V_19 ) ;
if ( ! ( V_13 & V_25 ) ) {
F_8 ( V_2 -> V_22 , L_3 ) ;
F_8 ( V_2 -> V_22 , L_4 ) ;
return - V_23 ;
}
V_13 = F_5 ( V_9 -> V_17 + V_19 ) ;
V_13 |= V_20 ;
F_4 ( V_13 , V_9 -> V_17 + V_19 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_13 ;
int V_26 ;
V_13 = F_5 ( V_9 -> V_17 + V_19 ) ;
V_13 |= V_27 ;
F_4 ( V_13 , V_9 -> V_17 + V_19 ) ;
V_13 &= ~ V_27 ;
F_4 ( V_13 , V_9 -> V_17 + V_19 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
F_4 ( 0x8000 , V_2 -> V_28 + F_11 ( V_26 ) ) ;
F_4 ( V_29 | V_30 ,
V_2 -> V_28 + V_31 ) ;
V_13 = V_32 | V_33 ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
F_4 ( V_13 , V_2 -> V_28 + F_12 ( V_26 ) ) ;
F_4 ( V_34 |
V_35 |
V_36 , V_9 -> V_17 + V_18 ) ;
F_4 ( V_37 ,
V_2 -> V_28 + V_38 ) ;
if ( ! ( F_5 ( V_2 -> V_28 + V_39 ) & 0x1 ) )
F_4 ( 0x1 , V_2 -> V_28 + V_40 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_43 * V_44 , unsigned int * V_3 )
{
const struct V_45 * V_46 = V_2 -> V_47 ;
int V_26 = F_14 ( V_44 -> V_48 ) ;
int V_49 = F_15 ( V_44 -> V_48 ) ;
int V_50 = F_16 ( V_44 -> V_48 ) ;
unsigned int V_51 = 0 ;
unsigned int V_52 ;
unsigned int V_53 ;
if ( V_44 -> V_54 == 0 ) {
return 0 ;
} else if ( V_44 -> V_54 > 1 ) {
F_8 ( V_2 -> V_22 , L_5 ,
V_44 -> V_54 ) ;
return - V_55 ;
}
switch ( V_49 ) {
case 0 :
V_51 |= V_56 ;
break;
case 1 :
V_51 |= V_57 ;
break;
case 2 :
V_51 |= V_58 ;
break;
case 3 :
V_51 |= V_59 ;
break;
default:
F_8 ( V_2 -> V_22 , L_6 ) ;
return - V_55 ;
}
switch ( V_50 ) {
case V_60 :
case V_61 :
if ( V_26 >= V_46 -> V_62 ) {
F_8 ( V_2 -> V_22 ,
L_7 ) ;
return - V_55 ;
}
V_51 |= V_63 | V_26 ;
break;
case V_64 :
if ( V_49 == 0 || V_49 == 1 ) {
F_8 ( V_2 -> V_22 ,
L_8 ) ;
return - V_55 ;
}
if ( V_26 >= V_46 -> V_65 ) {
F_8 ( V_2 -> V_22 ,
L_7 ) ;
return - V_55 ;
}
V_51 |= V_66 | V_26 ;
break;
default:
F_8 ( V_2 -> V_22 , L_9 ) ;
return - V_55 ;
}
V_51 |= V_67 ;
V_52 = F_5 ( V_2 -> V_28 + V_31 ) ;
V_52 &= ~ ( V_68 |
V_69 |
V_30 | V_29 ) ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
V_52 &= ~ ( V_70 | V_71 |
V_72 ) ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
V_52 |= V_68 | V_69 ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
F_4 ( V_51 , V_2 -> V_28 + V_73 ) ;
F_4 ( V_74 , V_2 -> V_28 + V_75 ) ;
F_4 ( V_74 , V_2 -> V_28 + V_76 ) ;
F_5 ( V_2 -> V_28 + V_77 ) ;
F_7 ( 10 ) ;
if ( ! ( F_5 ( V_2 -> V_28 + V_78 ) &
V_79 ) ) {
F_8 ( V_2 -> V_22 , L_10 ) ;
return - V_23 ;
}
V_53 = F_5 ( V_2 -> V_28 + V_80 ) & 0xFFFF ;
V_3 [ 0 ] = V_53 ^ 0x8000 ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_41 * V_81 )
{
unsigned int V_52 ;
V_52 = F_5 ( V_2 -> V_28 + V_31 ) ;
V_52 &= ~ ( V_30 | V_29 ) ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
F_4 ( 0x0 , V_2 -> V_28 + V_31 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_82 * V_83 )
{
const struct V_45 * V_84 = V_2 -> V_47 ;
unsigned int V_85 = V_84 -> V_65 ;
unsigned int V_86 = F_16 ( V_83 -> V_87 [ 0 ] ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_83 -> V_88 ; V_14 ++ ) {
unsigned int V_26 = F_14 ( V_83 -> V_87 [ V_14 ] ) ;
unsigned int V_89 = F_15 ( V_83 -> V_87 [ V_14 ] ) ;
unsigned int V_50 = F_16 ( V_83 -> V_87 [ V_14 ] ) ;
if ( V_50 != V_86 ) {
F_19 ( V_2 -> V_22 ,
L_11 ) ;
return - V_55 ;
}
if ( V_50 == V_64 ) {
if ( V_26 >= V_85 ) {
F_19 ( V_2 -> V_22 ,
L_12 ) ;
return - V_55 ;
}
if ( ! F_20 ( V_81 , V_89 ) ) {
F_19 ( V_2 -> V_22 ,
L_13 ) ;
return - V_55 ;
}
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_82 * V_83 ,
unsigned int * V_90 ,
unsigned int * V_91 , unsigned int * V_92 )
{
int V_93 ;
* V_90 = 0 ;
* V_91 = 0 ;
* V_92 = 0 ;
if ( V_83 -> V_94 ) {
* V_90 = ( V_83 -> V_94 * 33 ) / 1000 ;
V_93 = ( V_83 -> V_94 * 33 ) % 1000 ;
if ( ( V_83 -> V_95 & V_96 ) == V_97 ) {
if ( V_93 > 33 )
( * V_90 ) ++ ;
} else if ( ( V_83 -> V_95 & V_96 ) == V_98 ) {
if ( V_93 )
( * V_90 ) ++ ;
}
}
if ( V_83 -> V_99 ) {
* V_91 = ( V_83 -> V_99 * 33 ) / 1000 ;
V_93 = ( V_83 -> V_99 * 33 ) % 1000 ;
if ( ( V_83 -> V_95 & V_96 ) == V_97 ) {
if ( V_93 > 33 )
( * V_91 ) ++ ;
} else if ( ( V_83 -> V_95 & V_96 ) == V_98 ) {
if ( V_93 )
( * V_91 ) ++ ;
}
}
if ( V_83 -> V_100 ) {
* V_92 = ( V_83 -> V_100 * 33 ) / 1000 ;
V_93 = ( V_83 -> V_100 * 33 ) % 1000 ;
if ( ( V_83 -> V_95 & V_96 ) == V_97 ) {
if ( V_93 > 33 )
( * V_92 ) ++ ;
} else if ( ( V_83 -> V_95 & V_96 ) == V_98 ) {
if ( V_93 )
( * V_92 ) ++ ;
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned int V_90 ,
unsigned int V_91 , unsigned int V_92 )
{
F_4 ( V_90 - 1 , V_2 -> V_28 + V_101 ) ;
F_4 ( 0x0 , V_2 -> V_28 + V_102 ) ;
if ( V_91 ) {
F_4 ( V_91 - 1 , V_2 -> V_28 + V_103 ) ;
F_4 ( 0x0 , V_2 -> V_28 + V_104 ) ;
}
F_4 ( V_92 - 1 , V_2 -> V_28 + V_76 ) ;
F_4 ( V_92 - 1 , V_2 -> V_28 + V_75 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_41 * V_81 , struct V_82 * V_83 )
{
unsigned int V_51 ;
unsigned int V_26 ;
unsigned int V_49 ;
unsigned int V_50 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_83 -> V_88 ; V_14 ++ ) {
V_26 = F_14 ( V_83 -> V_87 [ V_14 ] ) ;
V_49 = F_15 ( V_83 -> V_87 [ V_14 ] ) ;
V_50 = F_16 ( V_83 -> V_87 [ V_14 ] ) ;
V_51 = V_26 ;
if ( V_49 == 0 )
V_51 |= V_56 ;
else if ( V_49 == 1 )
V_51 |= V_57 ;
else if ( V_49 == 2 )
V_51 |= V_58 ;
else
V_51 |= V_59 ;
if ( V_50 == V_64 )
V_51 |= V_66 ;
else
V_51 |= V_63 ;
F_4 ( V_51 , V_2 -> V_28 + V_73 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_82 * V_83 ,
unsigned int V_90 ,
unsigned int V_91 , unsigned int V_92 )
{
unsigned int V_52 = 0 ;
F_22 ( V_2 , V_90 , V_91 , V_92 ) ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
if ( ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_108 &&
V_83 -> V_109 == V_108 ) ||
( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_110 &&
V_83 -> V_109 == V_108 ) ) {
V_52 = V_71 |
V_68 |
V_69 ;
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_106 &&
V_83 -> V_109 == V_108 ) {
V_52 = V_72 |
V_68 |
V_69 ;
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_106 &&
V_83 -> V_109 == V_106 ) {
V_52 = V_70 |
V_71 |
V_68 |
V_69 ;
} else {
V_52 = V_70 |
V_68 |
V_69 ;
}
if ( V_83 -> V_111 == V_112 ) {
F_4 ( V_83 -> V_88 * V_83 -> V_113 ,
V_2 -> V_28 + V_114 ) ;
V_52 |= V_115 | V_116 ;
} else if ( V_83 -> V_111 == V_117 &&
V_83 -> V_118 == V_112 ) {
F_4 ( V_83 -> V_119 ,
V_2 -> V_28 + V_114 ) ;
V_52 |= V_115 | V_116 ;
} else {
V_52 |= V_115 ;
}
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
F_23 ( V_2 , V_81 , V_83 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_41 * V_81 )
{
int V_120 ;
unsigned int V_90 = 0 ;
unsigned int V_91 = 0 ;
unsigned int V_92 = 0 ;
struct V_82 * V_83 = & V_81 -> V_121 -> V_83 ;
V_120 = F_17 ( V_2 , V_81 ) ;
if ( V_120 )
return V_120 ;
V_120 = F_21 ( V_2 ,
V_81 , V_83 , & V_90 , & V_91 , & V_92 ) ;
if ( V_120 )
return V_120 ;
V_120 = F_24 ( V_2 , V_81 , V_83 , V_90 , V_91 , V_92 ) ;
if ( V_120 )
return V_120 ;
F_5 ( V_2 -> V_28 + V_77 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_82 * V_83 )
{
unsigned int V_90 ;
unsigned int V_92 ;
unsigned int V_91 ;
int V_120 = 0 ;
F_21 ( V_2 , V_81 , V_83 , & V_90 , & V_91 , & V_92 ) ;
V_120 |= F_27 ( & V_83 -> V_105 , V_122 | V_106 ) ;
V_120 |= F_27 ( & V_83 -> V_107 ,
V_110 | V_108 | V_106 ) ;
V_120 |= F_27 ( & V_83 -> V_109 , V_108 | V_106 ) ;
V_120 |= F_27 ( & V_83 -> V_118 ,
V_117 | V_112 ) ;
V_120 |= F_27 ( & V_83 -> V_111 , V_117 | V_112 ) ;
if ( V_120 )
return 1 ;
V_120 |= F_28 ( V_83 -> V_105 ) ;
V_120 |= F_28 ( V_83 -> V_107 ) ;
V_120 |= F_28 ( V_83 -> V_109 ) ;
V_120 |= F_28 ( V_83 -> V_118 ) ;
V_120 |= F_28 ( V_83 -> V_111 ) ;
if ( V_83 -> V_105 == V_122 &&
V_83 -> V_107 == V_108 &&
V_83 -> V_109 == V_108 ) {
} else if ( V_83 -> V_105 == V_122 &&
V_83 -> V_107 == V_110 &&
V_83 -> V_109 == V_108 ) {
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_108 &&
V_83 -> V_109 == V_108 ) {
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_110 &&
V_83 -> V_109 == V_108 ) {
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_106 &&
V_83 -> V_109 == V_108 ) {
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_106 &&
V_83 -> V_109 == V_106 ) {
} else {
V_120 |= - V_55 ;
}
if ( V_120 )
return 2 ;
V_120 |= F_29 ( & V_83 -> V_94 , 0 ) ;
if ( V_83 -> V_88 < 1 ) {
V_83 -> V_88 = 1 ;
V_120 |= - V_55 ;
}
if ( V_90 < 66 ) {
V_83 -> V_94 = 2000 ;
V_120 |= - V_55 ;
}
if ( V_91 && V_91 < 67 ) {
V_83 -> V_99 = 2031 ;
V_120 |= - V_55 ;
}
if ( V_92 < 66 ) {
V_83 -> V_100 = 2000 ;
V_120 |= - V_55 ;
}
if ( V_83 -> V_111 == V_112 )
V_120 |= F_30 ( & V_83 -> V_113 , 1 ) ;
else
V_120 |= F_29 ( & V_83 -> V_113 , 0 ) ;
if ( V_120 )
return 3 ;
if ( V_83 -> V_105 == V_122 &&
V_83 -> V_107 == V_108 &&
V_83 -> V_109 == V_108 ) {
if ( V_90 < V_74 ) {
F_8 ( V_2 -> V_22 , L_14 ) ;
V_83 -> V_94 = 2000 ;
V_120 ++ ;
}
if ( V_92 < V_74 ) {
F_8 ( V_2 -> V_22 , L_15 ) ;
V_83 -> V_100 = 2000 ;
V_120 ++ ;
}
if ( V_91 <= V_83 -> V_88 * V_92 ) {
F_8 ( V_2 -> V_22 , L_16 ) ;
V_83 -> V_119 = 2000 * V_83 -> V_88 + 31 ;
V_120 ++ ;
}
} else if ( V_83 -> V_105 == V_122 &&
V_83 -> V_107 == V_110 &&
V_83 -> V_109 == V_108 ) {
if ( V_90 < V_74 ) {
F_8 ( V_2 -> V_22 , L_14 ) ;
V_83 -> V_94 = 2000 ;
V_120 ++ ;
}
if ( V_92 < V_74 ) {
F_8 ( V_2 -> V_22 , L_15 ) ;
V_83 -> V_100 = 2000 ;
V_120 ++ ;
}
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_108 &&
V_83 -> V_109 == V_108 ) {
if ( V_90 < V_74 ) {
F_8 ( V_2 -> V_22 , L_14 ) ;
V_83 -> V_94 = 2000 ;
V_120 ++ ;
}
if ( V_92 < V_74 ) {
F_8 ( V_2 -> V_22 , L_15 ) ;
V_83 -> V_100 = 2000 ;
V_120 ++ ;
}
if ( V_91 <= V_83 -> V_88 * V_92 ) {
F_8 ( V_2 -> V_22 , L_16 ) ;
V_83 -> V_119 = 2000 * V_83 -> V_88 + 31 ;
V_120 ++ ;
}
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_110 &&
V_83 -> V_109 == V_108 ) {
if ( V_90 < V_74 ) {
F_8 ( V_2 -> V_22 , L_14 ) ;
V_83 -> V_94 = 2000 ;
V_120 ++ ;
}
if ( V_92 < V_74 ) {
F_8 ( V_2 -> V_22 , L_15 ) ;
V_83 -> V_100 = 2000 ;
V_120 ++ ;
}
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_106 &&
V_83 -> V_109 == V_108 ) {
if ( V_90 < V_74 ) {
F_8 ( V_2 -> V_22 , L_14 ) ;
V_83 -> V_94 = 2000 ;
V_120 ++ ;
}
if ( V_92 < V_74 ) {
F_8 ( V_2 -> V_22 , L_15 ) ;
V_83 -> V_100 = 2000 ;
V_120 ++ ;
}
} else if ( V_83 -> V_105 == V_106 &&
V_83 -> V_107 == V_106 &&
V_83 -> V_109 == V_106 ) {
if ( V_90 < V_74 ) {
F_8 ( V_2 -> V_22 , L_14 ) ;
V_83 -> V_94 = 2000 ;
V_120 ++ ;
}
}
if ( V_83 -> V_118 == V_112 ) {
if ( V_83 -> V_119 == 0 ) {
F_8 ( V_2 -> V_22 , L_16 ) ;
V_83 -> V_119 = 1 ;
V_120 ++ ;
}
}
if ( V_120 )
return 4 ;
if ( V_83 -> V_87 && V_83 -> V_88 > 0 )
V_120 |= F_18 ( V_2 , V_81 , V_83 ) ;
if ( V_120 )
return 5 ;
return 0 ;
}
static T_3 F_31 ( int V_123 , void * V_124 )
{
unsigned int V_52 ;
struct V_1 * V_2 = V_124 ;
struct V_41 * V_81 = V_2 -> V_125 ;
int V_14 ;
int V_126 = 0 ;
unsigned int V_53 ;
if ( ! V_2 -> V_127 )
return V_128 ;
if ( F_5 ( V_2 -> V_28 + V_129 ) &
V_130 ) {
V_52 = F_5 ( V_2 -> V_28 + V_31 ) ;
if ( ! ( V_52 & V_131 ) &&
! ( V_52 & V_132 ) &&
( V_52 & V_79 ) ) {
V_126 = V_133 ;
V_52 |= V_29 ;
V_52 &= ~ ( V_115 |
V_116 ) ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
V_81 -> V_121 -> V_134 |= V_135 ;
F_8 ( V_2 -> V_22 , L_17 ) ;
} else if ( ( V_52 & V_131 )
&& ! ( V_52 & V_132 )
&& ( V_52 & V_79 ) ) {
V_126 = V_133 / 2 ;
} else {
F_8 ( V_2 -> V_22 ,
L_18 ) ;
V_126 = 0 ;
V_52 |= V_29 ;
V_52 &= ~ ( V_115 |
V_116 ) ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
V_81 -> V_121 -> V_134 |= V_135 ;
F_8 ( V_2 -> V_22 , L_19 ) ;
}
for ( V_14 = 0 ; V_14 < V_126 ; V_14 ++ ) {
V_53 = F_5 ( V_2 -> V_28 + V_80 ) & 0xFFFF ;
V_53 ^= 0x8000 ;
if ( ! F_32 ( V_81 , & V_53 , 1 ) ) {
V_52 |= V_29 ;
V_52 &= ~ ( V_115 |
V_116 ) ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
break;
}
}
V_52 |= V_136 ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
V_52 &= ~ V_136 ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
}
if ( F_5 ( V_2 -> V_28 + V_129 ) &
V_137 ) {
V_81 -> V_121 -> V_134 |= V_138 ;
V_52 = F_5 ( V_2 -> V_28 + V_31 ) ;
V_52 |= V_29 ;
V_52 &= ~ ( V_115 | V_116 ) ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
while ( F_5 ( V_2 -> V_28 + V_31 ) &
V_79 ) {
V_53 = F_5 ( V_2 -> V_28 + V_80 ) & 0xFFFF ;
V_53 ^= 0x8000 ;
if ( ! F_32 ( V_81 , & V_53 , 1 ) )
break;
}
V_52 |= V_139 ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
V_52 &= ~ V_139 ;
F_4 ( V_52 , V_2 -> V_28 + V_31 ) ;
}
F_33 ( V_2 , V_81 ) ;
return V_140 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_43 * V_44 ,
unsigned int * V_3 )
{
int V_26 = F_14 ( V_44 -> V_48 ) ;
unsigned int V_52 ;
V_52 = F_5 ( V_2 -> V_28 + F_12 ( V_26 ) ) ;
V_52 |= V_32 ;
F_4 ( V_52 , V_2 -> V_28 + F_12 ( V_26 ) ) ;
F_4 ( 0x0 , V_2 -> V_28 + F_12 ( V_26 ) ) ;
F_4 ( V_3 [ 0 ] , V_2 -> V_28 + F_11 ( V_26 ) ) ;
V_81 -> V_141 [ V_26 ] = V_3 [ 0 ] ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_43 * V_44 ,
unsigned int * V_3 )
{
if ( F_36 ( V_81 , V_3 ) ) {
F_4 ( ( V_81 -> V_142 >> 0 ) & 0xFF ,
V_2 -> V_28 + V_143 ) ;
F_4 ( ( V_81 -> V_142 >> 8 ) & 0xFF ,
V_2 -> V_28 + V_144 ) ;
F_4 ( ( V_81 -> V_142 >> 16 ) & 0xFF ,
V_2 -> V_28 + V_145 ) ;
F_4 ( ( V_81 -> V_142 >> 24 ) & 0xFF ,
V_2 -> V_28 + V_146 ) ;
}
V_3 [ 1 ] = ( ( F_5 ( V_2 -> V_28 + V_143 ) & 0xFF ) << 0 ) |
( ( F_5 ( V_2 -> V_28 + V_144 ) & 0xFF ) << 8 ) |
( ( F_5 ( V_2 -> V_28 + V_145 ) & 0xFF ) << 16 ) |
( ( F_5 ( V_2 -> V_28 + V_146 ) & 0xFF ) << 24 ) ;
return V_44 -> V_54 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_43 * V_44 ,
unsigned int * V_3 )
{
unsigned int V_26 = F_14 ( V_44 -> V_48 ) ;
unsigned int V_147 ;
unsigned int V_52 ;
int V_148 ;
if ( V_26 < 8 )
V_147 = 0x000000ff ;
else if ( V_26 < 16 )
V_147 = 0x0000ff00 ;
else if ( V_26 < 24 )
V_147 = 0x00ff0000 ;
else
V_147 = 0xff000000 ;
V_148 = F_38 ( V_2 , V_81 , V_44 , V_3 , V_147 ) ;
if ( V_148 )
return V_148 ;
V_52 = F_5 ( V_2 -> V_28 + V_40 ) ;
V_52 &= ~ ( V_149 | V_150 |
V_151 | V_152 |
V_153 | V_154 |
V_155 | V_156 ) ;
if ( V_81 -> V_157 & 0x000000ff )
V_52 |= V_149 ;
if ( V_81 -> V_157 & 0x0000ff00 )
V_52 |= V_151 ;
if ( V_81 -> V_157 & 0x00ff0000 )
V_52 |= V_153 ;
if ( V_81 -> V_157 & 0xff000000 )
V_52 |= V_155 ;
if ( F_5 ( V_2 -> V_28 + V_39 ) ) {
V_81 -> V_157 |= 0x000000ff ;
V_81 -> V_157 &= ~ 0x0000ff00 ;
V_52 |= V_149 ;
V_52 &= ~ ( V_151 |
V_152 ) ;
}
F_4 ( V_52 , V_2 -> V_28 + V_40 ) ;
return V_44 -> V_54 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_43 * V_44 ,
unsigned int * V_3 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_26 = F_14 ( V_44 -> V_48 ) ;
int V_120 ;
switch ( V_3 [ 0 ] ) {
case V_158 :
if ( V_44 -> V_54 != 1 )
return - V_55 ;
V_120 = F_40 ( V_9 -> V_159 , 0 , V_26 ,
V_160 | V_161 ) ;
if ( V_120 )
return V_120 ;
F_41 ( V_9 -> V_159 , 0 , V_26 , 0 ) ;
break;
case V_162 :
if ( V_44 -> V_54 != 2 )
return - V_55 ;
V_120 = F_40 ( V_9 -> V_159 , 0 , V_26 ,
( V_3 [ 1 ] << 1 ) | V_161 ) ;
if ( V_120 )
return V_120 ;
break;
default:
return - V_55 ;
}
return V_44 -> V_54 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_43 * V_44 , unsigned int * V_3 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_44 -> V_54 == 0 )
return 0 ;
if ( V_44 -> V_54 > 1 ) {
F_8 ( V_2 -> V_22 , L_5 ,
V_44 -> V_54 ) ;
return - V_55 ;
}
V_3 [ 0 ] = F_43 ( V_9 -> V_159 , 0 , V_44 -> V_48 ) ;
return 1 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_41 * V_81 ,
struct V_43 * V_44 , unsigned int * V_3 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_44 -> V_54 == 0 ) {
return 0 ;
} else if ( V_44 -> V_54 > 1 ) {
F_8 ( V_2 -> V_22 , L_5 ,
V_44 -> V_54 ) ;
return - V_55 ;
}
F_41 ( V_9 -> V_159 , 0 , V_44 -> V_48 , V_3 [ 0 ] ) ;
return 1 ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned long V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_45 * V_46 = NULL ;
struct V_8 * V_9 ;
struct V_41 * V_81 ;
int V_163 ;
if ( V_5 < F_46 ( V_164 ) )
V_46 = & V_164 [ V_5 ] ;
if ( ! V_46 )
return - V_15 ;
V_2 -> V_47 = V_46 ;
V_2 -> V_165 = V_46 -> V_166 ;
V_9 = F_47 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_167 ;
V_163 = F_48 ( V_2 ) ;
if ( V_163 )
return V_163 ;
V_9 -> V_17 = F_3 ( V_7 , 1 ) ;
V_2 -> V_28 = F_3 ( V_7 , 2 ) ;
V_9 -> V_159 = F_3 ( V_7 , 3 ) ;
if ( ! V_9 -> V_17 || ! V_2 -> V_28 || ! V_9 -> V_159 )
return - V_15 ;
V_163 = F_49 ( V_2 , & V_7 -> V_2 , V_168 ,
F_1 , 0 ) ;
if ( V_163 < 0 )
return V_163 ;
F_10 ( V_2 ) ;
if ( V_7 -> V_123 > 0 ) {
V_163 = F_50 ( V_7 -> V_123 , F_31 , V_169 ,
V_2 -> V_165 , V_2 ) ;
if ( V_163 == 0 )
V_2 -> V_123 = V_7 -> V_123 ;
}
V_163 = F_51 ( V_2 , 4 ) ;
if ( V_163 )
return V_163 ;
V_81 = & V_2 -> V_170 [ 0 ] ;
if ( V_46 -> V_62 ) {
V_81 -> type = V_171 ;
V_81 -> V_172 =
V_173 | V_174 | V_175 | V_176 ;
V_81 -> V_177 = V_46 -> V_62 ;
V_81 -> V_178 = 0xFFFF ;
V_81 -> V_179 = V_180 ;
V_81 -> V_181 = & V_182 ;
V_81 -> V_183 = F_13 ;
if ( V_2 -> V_123 ) {
V_2 -> V_125 = V_81 ;
V_81 -> V_172 |= V_184 ;
V_81 -> V_185 = F_17 ;
V_81 -> V_186 = F_26 ;
V_81 -> V_187 = F_25 ;
}
} else {
V_81 -> type = V_188 ;
}
V_81 = & V_2 -> V_170 [ 1 ] ;
if ( V_46 -> V_189 ) {
V_81 -> type = V_190 ;
V_81 -> V_172 = V_191 | V_174 | V_175 ;
V_81 -> V_177 = V_46 -> V_189 ;
V_81 -> V_178 = 0xFFFF ;
V_81 -> V_181 = & V_192 ;
V_81 -> V_193 = F_34 ;
V_163 = F_52 ( V_81 ) ;
if ( V_163 )
return V_163 ;
} else {
V_81 -> type = V_188 ;
}
V_81 = & V_2 -> V_170 [ 2 ] ;
if ( V_46 -> V_194 ) {
V_81 -> type = V_195 ;
V_81 -> V_172 = V_173 | V_191 ;
V_81 -> V_177 = V_46 -> V_194 ;
V_81 -> V_178 = 1 ;
V_81 -> V_181 = & V_196 ;
V_81 -> V_197 = F_35 ;
V_81 -> V_198 = F_37 ;
} else {
V_81 -> type = V_188 ;
}
if ( ! F_5 ( V_2 -> V_28 + V_39 ) ) {
V_81 -> V_157 |= 0xFF ;
F_4 ( V_149 ,
V_2 -> V_28 + V_39 ) ;
}
V_81 = & V_2 -> V_170 [ 3 ] ;
if ( V_46 -> V_199 ) {
V_81 -> type = V_200 ;
V_81 -> V_172 = V_173 | V_191 ;
V_81 -> V_177 = 3 ;
V_81 -> V_178 = 0xFFFF ;
V_81 -> V_183 = F_42 ;
V_81 -> V_193 = F_44 ;
V_81 -> V_198 = F_39 ;
} else {
V_81 -> type = V_188 ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 )
F_10 ( V_2 ) ;
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_6 * V_2 ,
const struct V_201 * V_202 )
{
return F_56 ( V_2 , & V_203 , V_202 -> V_204 ) ;
}
