T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned int V_5 , V_6 ;
V_5 = F_2 ( V_4 ) ;
V_6 = F_3 ( V_4 ) ;
V_6 = ~ V_6 & V_5 ;
if ( V_5 & V_7 ) {
F_4 ( & V_8 ) ;
F_5 ( V_4 -> V_9 , L_1 ) ;
}
if ( V_5 & V_10 ) {
F_4 ( & V_11 ) ;
F_5 ( V_4 -> V_9 , L_2 ) ;
}
F_6 ( V_4 , V_6 ) ;
return V_12 ;
}
static void F_7 ( struct V_3 * V_4 ,
const unsigned char * V_13 , unsigned int V_14 )
{
unsigned int V_15 = 0 , V_16 = 0 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 += 4 ) {
if ( ( V_14 - V_15 ) < 4 ) {
if ( ( V_14 - V_15 ) == 3 ) {
V_16 = V_13 [ V_15 ] |
V_13 [ V_15 + 1 ] << 8 |
V_13 [ V_15 + 2 ] << 16 ;
F_5 ( V_4 -> V_9 , L_3 ,
V_16 , V_13 [ V_15 ] ,
V_13 [ V_15 + 1 ] ,
V_13 [ V_15 + 2 ] ) ;
} else if ( ( V_14 - V_15 ) == 2 ) {
V_16 = V_13 [ V_15 ] |
V_13 [ V_15 + 1 ] << 8 ;
F_5 ( V_4 -> V_9 ,
L_4 , V_16 ,
V_13 [ V_15 ] ,
V_13 [ V_15 + 1 ] ) ;
} else if ( ( V_14 - V_15 ) == 1 ) {
V_16 = V_13 [ V_15 ] ;
}
F_8 ( V_4 , V_16 ) ;
} else {
V_16 = V_13 [ V_15 ] |
V_13 [ V_15 + 1 ] << 8 |
V_13 [ V_15 + 2 ] << 16 |
V_13 [ V_15 + 3 ] << 24 ;
F_5 ( V_4 -> V_9 ,
L_5 ,
V_16 , * ( V_17 * ) ( V_13 + V_15 ) ,
V_13 [ V_15 + 1 ] ,
V_13 [ V_15 + 2 ] ,
V_13 [ V_15 + 3 ] ) ;
F_8 ( V_4 , V_16 ) ;
}
}
}
int F_9 ( struct V_3 * V_4 , unsigned int V_18 ,
const unsigned char * V_13 , unsigned int V_14 )
{
unsigned int V_19 = 0 ;
if ( V_4 -> V_20 == V_21 ) {
F_10 ( V_4 -> V_9 , L_6 ) ;
return - V_22 ;
}
F_11 ( 20 ) ;
F_12 ( & V_4 -> V_23 ) ;
switch ( V_18 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
F_13 ( V_4 , V_18 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
if ( V_19 ) {
F_14 ( & V_4 -> V_23 ) ;
return 0 ;
} else {
F_14 ( & V_4 -> V_23 ) ;
return - V_22 ;
}
case V_30 :
case V_31 :
case V_32 :
case V_33 :
F_13 ( V_4 , V_18 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
if ( V_19 ) {
F_14 ( & V_4 -> V_23 ) ;
return 0 ;
} else {
F_14 ( & V_4 -> V_23 ) ;
return - V_22 ;
}
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
F_14 ( & V_4 -> V_23 ) ;
return 0 ;
case V_39 :
case V_40 :
F_14 ( & V_4 -> V_23 ) ;
return 0 ;
case V_41 :
case V_42 :
{
unsigned int V_43 , V_16 = 0 ;
F_15 ( & V_11 ) ;
V_43 = V_14 * 4 ;
if ( V_14 < 4 ) {
V_16 = V_13 [ 0 ] |
V_13 [ 1 ] << 8 |
V_13 [ 2 ] << 16 ;
F_8 ( V_4 , V_16 ) ;
F_5 ( V_4 -> V_9 , L_7 ,
V_14 , V_16 , V_13 [ 0 ] ,
V_13 [ 1 ] , V_13 [ 2 ] ) ;
} else
F_7 ( V_4 , V_13 , V_14 ) ;
F_13 ( V_4 , V_18 , V_14 & 0xff ,
( V_14 & 0xff00 ) >> 8 ) ;
if ( ! F_16 ( & V_11 ,
V_44 ) ) {
F_17 ( V_4 -> V_9 , L_8 ) ;
F_14 ( & V_4 -> V_23 ) ;
return - V_45 ;
}
if ( V_19 ) {
F_14 ( & V_4 -> V_23 ) ;
return 0 ;
} else {
F_14 ( & V_4 -> V_23 ) ;
return - V_22 ;
}
}
case V_46 :
case V_47 :
case V_48 :
case V_49 :
if ( V_19 ) {
F_14 ( & V_4 -> V_23 ) ;
return 0 ;
} else {
F_14 ( & V_4 -> V_23 ) ;
return - V_22 ;
}
default:
F_17 ( V_4 -> V_9 ,
L_9 ,
V_18 ) ;
F_14 ( & V_4 -> V_23 ) ;
return - V_22 ;
}
}
static unsigned int F_18 ( struct V_3 * V_4 ,
unsigned int V_50 , unsigned int V_51 , V_17 * V_52 )
{
unsigned int V_53 , V_54 , V_55 ;
T_2 V_56 ;
V_56 = ( T_2 ) ( ( V_51 & 0x00ffff00 ) >> 8 ) ;
F_5 ( V_4 -> V_9 , L_10 , V_56 ) ;
if ( V_56 != V_50 ) {
F_5 ( V_4 -> V_9 ,
L_11 ,
V_56 , V_50 ) ;
goto V_57;
}
for ( V_54 = 0 ; V_54 < ( V_56 >> 2 ) ; V_54 ++ ) {
V_53 = F_19 ( V_4 ) ;
F_5 ( V_4 -> V_9 , L_12 , V_53 ) ;
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
V_52 [ ( V_54 * 4 ) + V_55 ] =
( V_17 ) ( V_53 >> ( V_55 * 8 ) ) & 0xff ;
F_5 ( V_4 -> V_9 , L_13 ,
( V_53 >> ( V_55 * 8 ) ) & 0xff ) ;
}
}
if ( V_56 % 4 ) {
V_53 = F_19 ( V_4 ) ;
F_5 ( V_4 -> V_9 , L_12 , V_53 ) ;
for ( V_55 = 0 ; V_55 < ( V_56 % 4 ) ; V_55 ++ ) {
V_52 [ ( V_54 * 4 ) + V_55 ] =
( V_17 ) ( V_53 >> ( V_55 * 8 ) ) & 0xff ;
F_5 ( V_4 -> V_9 , L_13 ,
( V_53 >> ( V_55 * 8 ) ) & 0xff ) ;
}
}
return V_56 ;
V_57:
return - V_22 ;
}
static unsigned int F_20 ( unsigned int V_50 )
{
switch ( V_50 ) {
case 1 :
return V_58 ;
case 2 :
return V_59 ;
default:
return V_60 ;
}
}
int F_21 ( struct V_3 * V_4 , unsigned int V_18 ,
unsigned int V_13 , unsigned int V_50 , V_17 * V_52 )
{
unsigned int V_51 , V_53 , V_54 ;
V_17 V_61 = 0 ;
T_2 V_56 ;
if ( V_4 -> V_20 == V_21 ) {
F_10 ( V_4 -> V_9 , L_6 ) ;
return - V_22 ;
}
F_11 ( 20 ) ;
F_12 ( & V_4 -> V_23 ) ;
F_15 ( & V_8 ) ;
F_22 ( V_4 ,
V_29 , V_50 ) ;
V_61 = F_20 ( V_50 ) ;
switch ( V_18 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
F_22 ( V_4 ,
V_18 , V_13 ) ;
break;
default:
F_17 ( V_4 -> V_9 ,
L_9 ,
V_18 ) ;
F_14 ( & V_4 -> V_23 ) ;
return - V_22 ;
}
if ( ! F_16 ( & V_8 ,
V_44 ) ) {
F_23 ( L_14 ) ;
F_14 ( & V_4 -> V_23 ) ;
return 0 ;
}
F_11 ( 20 ) ;
V_51 = F_19 ( V_4 ) ;
if ( ( V_17 ) ( V_51 & 0xff ) != V_61 ) {
F_24 ( V_66
L_15 ,
V_51 , V_61 ) ;
goto V_67;
}
if ( V_50 <= 2 ) {
for ( V_54 = 0 ; V_54 < V_50 ; V_54 ++ )
V_52 [ V_54 ] = ( V_51 >> ( 8 + ( V_54 * 8 ) ) ) & 0xff ;
V_56 = V_50 ;
} else {
V_56 = F_18 ( V_4 , V_50 , V_51 ,
V_52 ) ;
if ( V_56 != V_50 )
goto V_67;
}
V_53 = F_19 ( V_4 ) ;
F_11 ( 20 ) ;
if ( V_53 != V_68 ) {
F_25 ( V_4 -> V_9 ,
L_16 , V_53 ) ;
goto V_67;
}
F_14 ( & V_4 -> V_23 ) ;
return V_56 ;
V_67:
V_54 = 0 ;
while ( 1 ) {
V_53 = F_19 ( V_4 ) ;
if ( ( V_53 == V_68 )
|| ( V_54 > V_69 ) )
break;
F_5 ( V_4 -> V_9 ,
L_17 , V_53 ) ;
V_54 ++ ;
}
F_25 ( V_4 -> V_9 ,
L_18 , V_54 , V_53 ) ;
F_14 ( & V_4 -> V_23 ) ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 ,
unsigned int V_70 )
{
int V_71 ;
if ( V_70 ) {
V_71 = 1000 ;
F_27 ( V_4 , 1 ) ;
while ( 1 ) {
V_71 -- ;
if ( F_28 ( V_4 ) )
return 0 ;
if ( V_71 == 0 )
return - V_22 ;
}
} else
F_27 ( V_4 , 0 ) ;
return 0 ;
}
static unsigned long F_29 ( struct V_3 * V_4 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int V_74 )
{
unsigned long V_75 , V_76 , V_77 ;
unsigned int V_54 , V_78 = 0xf ;
V_75 = ( V_79 / V_72 ) ;
if ( V_75 < V_80 || V_75 > V_81 ) {
F_17 ( V_4 -> V_9 , L_19 ) ;
F_30 ( V_4 , 0 , 0 ) ;
} else {
if ( V_75 < 7 * V_82 )
F_30 ( V_4 , 1 , 0x1 ) ;
else if ( V_75 < 8 * V_82 )
F_30 ( V_4 , 1 , 0x0 ) ;
else if ( V_75 < 9 * V_82 )
F_30 ( V_4 , 1 , 0x3 ) ;
else if ( V_75 < 10 * V_82 )
F_30 ( V_4 , 1 , 0x2 ) ;
else if ( V_75 < 11 * V_82 )
F_30 ( V_4 , 1 , 0x5 ) ;
else
F_30 ( V_4 , 1 , 0x4 ) ;
}
V_76 = V_75 * V_73 ;
F_5 ( V_4 -> V_9 , L_20 ,
V_76 , V_75 , V_73 ) ;
if ( V_76 < V_83 || V_76 > V_84 )
F_17 ( V_4 -> V_9 , L_21 ) ;
V_77 = V_76 / ( 1 << V_74 ) ;
F_5 ( V_4 -> V_9 , L_22 ,
V_77 , V_76 , V_74 ) ;
for ( V_54 = 0 ; V_54 < F_31 ( V_85 ) ; V_54 ++ ) {
if ( V_77 < V_85 [ V_54 ] * V_82 ) {
V_78 = V_54 ;
break;
}
}
F_5 ( V_4 -> V_9 , L_23 , V_78 ) ;
F_32 ( V_4 , V_72 , V_73 , V_74 ) ;
F_33 ( V_4 , 0 ) ;
F_34 ( V_4 , 0 ) ;
F_35 ( V_4 , V_78 ) ;
F_36 ( V_4 , V_4 -> V_86 -> V_87 ) ;
F_5 ( V_4 -> V_9 , L_24 ,
( V_77 / V_82 ) ) ;
return V_77 ;
}
static int F_37 ( struct V_3 * V_4 ,
unsigned int V_88 , unsigned int V_70 )
{
unsigned int V_89 ;
unsigned long V_90 ;
unsigned long V_91 = 0 , V_92 = 0 , V_93 = 0 ;
if ( V_70 ) {
V_4 -> V_94 = V_88 ;
F_38 ( V_4 , V_88 ) ;
if ( V_88 == V_95 ) {
V_91 = F_29 ( V_4 ,
V_4 -> V_86 -> V_96 , V_4 -> V_86 -> V_97 ,
V_4 -> V_86 -> V_98 ) ;
if ( V_91 == 0 ) {
F_10 ( V_4 -> V_9 ,
L_25 ) ;
return - V_22 ;
}
V_92 = V_91 / 8 ;
F_39 ( V_4 , 0 ) ;
F_26 ( V_4 , 1 ) ;
} else if ( V_88 == V_99 ) {
F_17 ( V_4 -> V_9 , L_26 ) ;
F_17 ( V_4 -> V_9 ,
L_27 ) ;
} else if ( V_88 == V_100 ) {
F_17 ( V_4 -> V_9 , L_26 ) ;
F_17 ( V_4 -> V_9 ,
L_28 ) ;
}
V_89 = V_92 / ( V_4 -> V_86 -> V_101 ) ;
F_5 ( V_4 -> V_9 ,
L_29 ,
V_89 , V_92 , V_4 -> V_86 -> V_101 ) ;
if ( ( V_92 / V_89 ) >= ( 20 * V_82 ) ||
( V_92 / V_89 ) >
V_4 -> V_86 -> V_101 )
V_89 += 1 ;
V_93 = V_92 / V_89 ;
F_5 ( V_4 -> V_9 ,
L_30 ,
V_93 , V_92 , V_89 ) ;
F_40 ( V_4 , 1 ) ;
F_41 ( V_4 , 1 , V_89 ) ;
F_42 ( V_4 ,
( V_102 | V_4 -> V_103 ) , 1 ) ;
F_5 ( V_4 -> V_9 , L_31 ,
( V_92 / V_82 ) ) ;
F_5 ( V_4 -> V_9 , L_32 ,
( V_4 -> V_86 -> V_101 / V_82 ) ) ;
F_5 ( V_4 -> V_9 , L_33 , V_89 ) ;
F_5 ( V_4 -> V_9 , L_34 ,
( ( V_92 / V_89 ) / V_82 ) ) ;
if ( ( V_92 / V_89 ) > V_93 ) {
V_90 = V_93 /
( V_92 / V_89 ) ;
F_17 ( V_4 -> V_9 , L_35 ,
( V_90 / 100 ) ) ;
} else if ( ( V_92 / V_89 ) < ( V_93 ) ) {
V_90 = ( V_92 / V_89 ) /
V_93 ;
F_17 ( V_4 -> V_9 , L_36 ,
( V_90 / 100 ) ) ;
}
} else {
F_42 ( V_4 ,
( V_102 | V_4 -> V_103 ) , 0 ) ;
F_41 ( V_4 , 0 , 0 ) ;
F_40 ( V_4 , 0 ) ;
if ( V_88 == V_95 )
F_26 ( V_4 , 0 ) ;
}
return 0 ;
}
int F_43 ( struct V_3 * V_4 )
{
V_4 -> V_20 = V_104 ;
switch ( V_4 -> V_86 -> V_105 ) {
case V_106 :
V_4 -> V_103 = V_107 ;
break;
case V_108 :
V_4 -> V_103 = V_107 | V_109 ;
break;
case V_110 :
V_4 -> V_103 = V_107 | V_109 |
V_111 ;
break;
case V_112 :
V_4 -> V_103 = V_107 | V_109 |
V_111 | V_113 ;
break;
default:
F_25 ( V_4 -> V_9 , L_37 ) ;
return - V_22 ;
}
F_44 ( V_4 ) ;
F_45 ( V_4 ) ;
F_46 ( V_4 , 0 ) ;
return 0 ;
}
void F_47 ( struct V_3 * V_4 )
{
unsigned int V_114 = 0 ;
V_114 = ( V_115 | V_116 ) ;
F_48 ( V_4 , V_114 , 1 ) ;
V_114 = 0 ;
V_114 = ~ ( V_7 | V_10 ) ;
F_49 ( V_4 , V_114 , 1 ) ;
}
int F_50 ( struct V_3 * V_4 ,
unsigned int V_70 )
{
F_49 ( V_4 , V_117 , V_70 ) ;
return 0 ;
}
void F_51 ( struct V_3 * V_4 ,
unsigned int V_70 )
{
F_52 ( V_4 , V_70 ) ;
}
int F_53 ( struct V_3 * V_4 ,
struct V_118 * V_86 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 ;
V_120 = (struct V_119 * ) V_4 -> V_123 ;
V_122 = (struct V_121 * ) V_120 -> V_124 ;
if ( V_86 -> V_125 == ( V_126 ) V_127 ) {
if ( V_86 -> V_128 == 0 ) {
F_54 ( V_4 ,
V_86 -> V_129 ,
V_122 -> V_130 ,
V_122 -> V_131 ) ;
F_55 ( V_4 ,
V_122 -> V_132 ,
V_122 -> V_133 ) ;
F_56 ( V_4 ,
V_122 -> V_134 ,
V_122 -> V_135 ) ;
}
}
F_57 ( V_4 , V_122 -> V_136 ,
V_122 -> V_137 ) ;
F_58 ( V_4 , V_86 ) ;
F_25 ( V_4 -> V_9 , L_38 ,
V_122 -> V_136 , V_122 -> V_137 ) ;
return 0 ;
}
int F_59 ( struct V_3 * V_4 )
{
unsigned int V_138 = 100 ;
switch ( V_4 -> V_20 ) {
case V_104 :
F_60 ( V_4 , 0x1f ) ;
F_61 ( V_4 ) ;
F_62 ( V_4 , V_102 , 1 ) ;
F_62 ( V_4 , V_4 -> V_103 , 1 ) ;
F_37 ( V_4 , V_4 -> V_86 -> V_139 , 1 ) ;
while ( ! ( F_63 ( V_4 ) ) ) {
V_138 -- ;
if ( V_138 == 0 ) {
F_10 ( V_4 -> V_9 ,
L_39 ) ;
F_10 ( V_4 -> V_9 ,
L_40 ) ;
return - V_22 ;
}
}
if ( V_138 != 0 ) {
F_25 ( V_4 -> V_9 ,
L_41 ) ;
F_25 ( V_4 -> V_9 , L_42 ) ;
}
V_4 -> V_20 = V_140 ;
F_64 ( V_4 ,
V_4 -> V_86 -> V_141 ) ;
F_65 ( V_4 ,
V_4 -> V_86 -> V_142 ) ;
F_66 ( V_4 ,
V_4 -> V_86 -> V_143 ) ;
return 0 ;
default:
F_25 ( V_4 -> V_9 , L_43 ) ;
return 0 ;
}
return 0 ;
}
int F_67 ( struct V_3 * V_4 )
{
if ( V_4 -> V_20 != V_140 ) {
F_17 ( V_4 -> V_9 , L_44 ) ;
return 0 ;
}
if ( V_4 -> V_94 == V_100 ) {
F_17 ( V_4 -> V_9 , L_45 ) ;
return 0 ;
}
V_4 -> V_20 = V_144 ;
F_68 ( V_4 , 0 ) ;
F_69 ( V_4 , 0 ) ;
F_70 ( V_4 , 1 ) ;
return 0 ;
}
int F_71 ( struct V_3 * V_4 ,
unsigned int V_145 )
{
if ( V_145 ) {
if ( V_4 -> V_20 != V_144 ) {
F_10 ( V_4 -> V_9 , L_46 ) ;
return - V_22 ;
}
F_68 ( V_4 , 0 ) ;
} else {
if ( V_4 -> V_20 == V_104 || V_4 -> V_20 ==
V_21 ) {
F_10 ( V_4 -> V_9 ,
L_47 ) ;
return - V_22 ;
}
F_69 ( V_4 , 0 ) ;
}
return 0 ;
}
int F_72 ( struct V_3 * V_4 )
{
return F_73 ( V_4 ) ;
}
int F_74 ( struct V_3 * V_4 )
{
F_75 ( V_4 ) ;
return 0 ;
}
int F_76 ( struct V_3 * V_4 ,
unsigned int V_146 )
{
int V_147 = V_148 ;
F_77 ( V_4 ) ;
F_45 ( V_4 ) ;
do {
if ( F_78 ( V_4 ) ) {
F_47 ( V_4 ) ;
F_5 ( V_4 -> V_9 , L_48 ) ;
return 0 ;
}
} while ( -- V_147 );
F_10 ( V_4 -> V_9 , L_49 ) ;
return - V_45 ;
}
