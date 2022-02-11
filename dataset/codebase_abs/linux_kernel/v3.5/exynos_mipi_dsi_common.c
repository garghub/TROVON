T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned int V_5 , V_6 ;
if ( V_4 == NULL ) {
F_2 ( V_4 -> V_7 , L_1 , V_8 ) ;
return V_9 ;
}
V_5 = F_3 ( V_4 ) ;
V_6 = F_4 ( V_4 ) ;
V_6 = ~ V_6 & V_5 ;
if ( V_5 & V_10 ) {
F_5 ( & V_11 ) ;
F_6 ( V_4 -> V_7 , L_2 ) ;
}
if ( V_5 & V_12 ) {
F_5 ( & V_13 ) ;
F_6 ( V_4 -> V_7 , L_3 ) ;
}
F_7 ( V_4 , V_6 ) ;
return V_14 ;
}
static void F_8 ( struct V_3 * V_4 ,
const unsigned char * V_15 , unsigned int V_16 )
{
unsigned int V_17 = 0 , V_18 = 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 += 4 ) {
if ( ( V_16 - V_17 ) < 4 ) {
if ( ( V_16 - V_17 ) == 3 ) {
V_18 = V_15 [ V_17 ] |
V_15 [ V_17 + 1 ] << 8 |
V_15 [ V_17 + 2 ] << 16 ;
F_6 ( V_4 -> V_7 , L_4 ,
V_18 , V_15 [ V_17 ] ,
V_15 [ V_17 + 1 ] ,
V_15 [ V_17 + 2 ] ) ;
} else if ( ( V_16 - V_17 ) == 2 ) {
V_18 = V_15 [ V_17 ] |
V_15 [ V_17 + 1 ] << 8 ;
F_6 ( V_4 -> V_7 ,
L_5 , V_18 ,
V_15 [ V_17 ] ,
V_15 [ V_17 + 1 ] ) ;
} else if ( ( V_16 - V_17 ) == 1 ) {
V_18 = V_15 [ V_17 ] ;
}
F_9 ( V_4 , V_18 ) ;
} else {
V_18 = V_15 [ V_17 ] |
V_15 [ V_17 + 1 ] << 8 |
V_15 [ V_17 + 2 ] << 16 |
V_15 [ V_17 + 3 ] << 24 ;
F_6 ( V_4 -> V_7 ,
L_6 ,
V_18 , * ( V_19 * ) ( V_15 + V_17 ) ,
V_15 [ V_17 + 1 ] ,
V_15 [ V_17 + 2 ] ,
V_15 [ V_17 + 3 ] ) ;
F_9 ( V_4 , V_18 ) ;
}
}
}
int F_10 ( struct V_3 * V_4 , unsigned int V_20 ,
const unsigned char * V_15 , unsigned int V_16 )
{
unsigned int V_21 = 0 ;
if ( V_4 -> V_22 == V_23 ) {
F_2 ( V_4 -> V_7 , L_7 ) ;
return - V_24 ;
}
F_11 ( 20 ) ;
F_12 ( & V_4 -> V_25 ) ;
switch ( V_20 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
F_13 ( V_4 , V_20 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_21 ) {
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
} else {
F_14 ( & V_4 -> V_25 ) ;
return - V_24 ;
}
case V_32 :
case V_33 :
case V_34 :
case V_35 :
F_13 ( V_4 , V_20 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_21 ) {
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
} else {
F_14 ( & V_4 -> V_25 ) ;
return - V_24 ;
}
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
case V_41 :
case V_42 :
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
case V_43 :
case V_44 :
{
unsigned int V_45 , V_18 = 0 ;
F_15 ( V_13 ) ;
V_45 = V_16 * 4 ;
if ( V_16 < 4 ) {
V_18 = V_15 [ 0 ] |
V_15 [ 1 ] << 8 |
V_15 [ 2 ] << 16 ;
F_9 ( V_4 , V_18 ) ;
F_6 ( V_4 -> V_7 , L_8 ,
V_16 , V_18 , V_15 [ 0 ] ,
V_15 [ 1 ] , V_15 [ 2 ] ) ;
} else
F_8 ( V_4 , V_15 , V_16 ) ;
F_13 ( V_4 , V_20 , V_16 & 0xff ,
( V_16 & 0xff00 ) >> 8 ) ;
if ( ! F_16 ( & V_13 ,
V_46 ) ) {
F_17 ( V_4 -> V_7 , L_9 ) ;
F_14 ( & V_4 -> V_25 ) ;
return - V_47 ;
}
if ( V_21 ) {
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
} else {
F_14 ( & V_4 -> V_25 ) ;
return - V_24 ;
}
}
case V_48 :
case V_49 :
case V_50 :
case V_51 :
if ( V_21 ) {
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
} else {
F_14 ( & V_4 -> V_25 ) ;
return - V_24 ;
}
default:
F_17 ( V_4 -> V_7 ,
L_10 ,
V_20 ) ;
F_14 ( & V_4 -> V_25 ) ;
return - V_24 ;
}
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
}
static unsigned int F_18 ( struct V_3 * V_4 ,
unsigned int V_52 , unsigned int V_53 , V_19 * V_54 )
{
unsigned int V_55 , V_56 , V_57 ;
T_2 V_58 ;
V_58 = ( T_2 ) ( ( V_53 & 0x00ffff00 ) >> 8 ) ;
F_6 ( V_4 -> V_7 , L_11 , V_58 ) ;
if ( V_58 != V_52 ) {
F_6 ( V_4 -> V_7 ,
L_12 ,
V_58 , V_52 ) ;
goto V_59;
}
for ( V_56 = 0 ; V_56 < ( V_58 >> 2 ) ; V_56 ++ ) {
V_55 = F_19 ( V_4 ) ;
F_6 ( V_4 -> V_7 , L_13 , V_55 ) ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
V_54 [ ( V_56 * 4 ) + V_57 ] =
( V_19 ) ( V_55 >> ( V_57 * 8 ) ) & 0xff ;
F_6 ( V_4 -> V_7 , L_14 ,
( V_55 >> ( V_57 * 8 ) ) & 0xff ) ;
}
}
if ( V_58 % 4 ) {
V_55 = F_19 ( V_4 ) ;
F_6 ( V_4 -> V_7 , L_13 , V_55 ) ;
for ( V_57 = 0 ; V_57 < ( V_58 % 4 ) ; V_57 ++ ) {
V_54 [ ( V_56 * 4 ) + V_57 ] =
( V_19 ) ( V_55 >> ( V_57 * 8 ) ) & 0xff ;
F_6 ( V_4 -> V_7 , L_14 ,
( V_55 >> ( V_57 * 8 ) ) & 0xff ) ;
}
}
return V_58 ;
V_59:
return - V_24 ;
}
static unsigned int F_20 ( unsigned int V_52 )
{
switch ( V_52 ) {
case 1 :
return V_60 ;
case 2 :
return V_61 ;
default:
return V_62 ;
}
}
int F_21 ( struct V_3 * V_4 , unsigned int V_20 ,
unsigned int V_15 , unsigned int V_52 , V_19 * V_54 )
{
unsigned int V_53 , V_55 , V_56 ;
V_19 V_63 = 0 ;
T_2 V_58 ;
if ( V_4 -> V_22 == V_23 ) {
F_2 ( V_4 -> V_7 , L_7 ) ;
return - V_24 ;
}
F_11 ( 20 ) ;
F_12 ( & V_4 -> V_25 ) ;
F_15 ( V_11 ) ;
F_22 ( V_4 ,
V_31 , V_52 ) ;
V_63 = F_20 ( V_52 ) ;
switch ( V_20 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
F_22 ( V_4 ,
V_20 , V_15 ) ;
break;
default:
F_17 ( V_4 -> V_7 ,
L_10 ,
V_20 ) ;
return - V_24 ;
}
if ( ! F_16 ( & V_11 ,
V_46 ) ) {
F_23 ( L_15 ) ;
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
}
F_11 ( 20 ) ;
V_53 = F_19 ( V_4 ) ;
if ( ( V_19 ) ( V_53 & 0xff ) != V_63 ) {
F_24 ( V_68
L_16 ,
V_53 , V_63 ) ;
goto V_69;
}
if ( V_52 <= 2 ) {
for ( V_56 = 0 ; V_56 < V_52 ; V_56 ++ )
V_54 [ V_56 ] = ( V_53 >> ( 8 + ( V_56 * 8 ) ) ) & 0xff ;
V_58 = V_52 ;
} else {
V_58 = F_18 ( V_4 , V_52 , V_53 ,
V_54 ) ;
if ( V_58 != V_52 )
goto V_69;
}
V_55 = F_19 ( V_4 ) ;
F_11 ( 20 ) ;
if ( V_55 != V_70 ) {
F_25 ( V_4 -> V_7 ,
L_17 , V_55 ) ;
goto V_69;
}
F_14 ( & V_4 -> V_25 ) ;
return V_58 ;
V_69:
V_56 = 0 ;
while ( 1 ) {
V_55 = F_19 ( V_4 ) ;
if ( ( V_55 == V_70 )
|| ( V_56 > V_71 ) )
break;
F_6 ( V_4 -> V_7 ,
L_18 , V_55 ) ;
V_56 ++ ;
}
F_25 ( V_4 -> V_7 ,
L_19 , V_56 , V_55 ) ;
F_14 ( & V_4 -> V_25 ) ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 ,
unsigned int V_72 )
{
int V_73 ;
if ( V_72 ) {
V_73 = 1000 ;
F_27 ( V_4 , 1 ) ;
while ( 1 ) {
V_73 -- ;
if ( F_28 ( V_4 ) )
return 0 ;
if ( V_73 == 0 )
return - V_24 ;
}
} else
F_27 ( V_4 , 0 ) ;
return 0 ;
}
static unsigned long F_29 ( struct V_3 * V_4 ,
unsigned int V_74 , unsigned int V_75 ,
unsigned int V_76 )
{
unsigned long V_77 , V_78 , V_79 ;
unsigned int V_56 , V_80 = 0xf ;
V_77 = ( V_81 / V_74 ) ;
if ( V_77 < V_82 || V_77 > V_83 ) {
F_17 ( V_4 -> V_7 , L_20 ) ;
F_30 ( V_4 , 0 , 0 ) ;
} else {
if ( V_77 < 7 * V_84 )
F_30 ( V_4 , 1 , 0x1 ) ;
else if ( V_77 < 8 * V_84 )
F_30 ( V_4 , 1 , 0x0 ) ;
else if ( V_77 < 9 * V_84 )
F_30 ( V_4 , 1 , 0x3 ) ;
else if ( V_77 < 10 * V_84 )
F_30 ( V_4 , 1 , 0x2 ) ;
else if ( V_77 < 11 * V_84 )
F_30 ( V_4 , 1 , 0x5 ) ;
else
F_30 ( V_4 , 1 , 0x4 ) ;
}
V_78 = V_77 * V_75 ;
F_6 ( V_4 -> V_7 , L_21 ,
V_78 , V_77 , V_75 ) ;
if ( V_78 < V_85 || V_78 > V_86 )
F_17 ( V_4 -> V_7 , L_22 ) ;
V_79 = V_78 / ( 1 << V_76 ) ;
F_6 ( V_4 -> V_7 , L_23 ,
V_79 , V_78 , V_76 ) ;
for ( V_56 = 0 ; V_56 < F_31 ( V_87 ) ; V_56 ++ ) {
if ( V_79 < V_87 [ V_56 ] * V_84 ) {
V_80 = V_56 ;
break;
}
}
F_6 ( V_4 -> V_7 , L_24 , V_80 ) ;
F_32 ( V_4 , V_74 , V_75 , V_76 ) ;
F_33 ( V_4 , 0 ) ;
F_34 ( V_4 , 0 ) ;
F_35 ( V_4 , V_80 ) ;
F_36 ( V_4 , V_4 -> V_88 -> V_89 ) ;
F_6 ( V_4 -> V_7 , L_25 ,
( V_79 / V_84 ) ) ;
return V_79 ;
}
static int F_37 ( struct V_3 * V_4 ,
unsigned int V_90 , unsigned int V_72 )
{
unsigned int V_91 ;
unsigned long V_92 ;
unsigned long V_93 = 0 , V_94 = 0 , V_95 = 0 ;
if ( V_72 ) {
V_4 -> V_96 = V_90 ;
F_38 ( V_4 , V_90 ) ;
if ( V_90 == V_97 ) {
V_93 = F_29 ( V_4 ,
V_4 -> V_88 -> V_98 , V_4 -> V_88 -> V_99 ,
V_4 -> V_88 -> V_100 ) ;
if ( V_93 == 0 ) {
F_2 ( V_4 -> V_7 ,
L_26 ) ;
return - V_24 ;
}
V_94 = V_93 / 8 ;
F_39 ( V_4 , 0 ) ;
F_26 ( V_4 , 1 ) ;
} else if ( V_90 == V_101 ) {
F_17 ( V_4 -> V_7 , L_27 ) ;
F_17 ( V_4 -> V_7 ,
L_28 ) ;
} else if ( V_90 == V_102 ) {
F_17 ( V_4 -> V_7 , L_27 ) ;
F_17 ( V_4 -> V_7 ,
L_29 ) ;
}
V_91 = V_94 / ( V_4 -> V_88 -> V_103 ) ;
F_6 ( V_4 -> V_7 ,
L_30 ,
V_91 , V_94 , V_4 -> V_88 -> V_103 ) ;
if ( ( V_94 / V_91 ) >= ( 20 * V_84 ) ||
( V_94 / V_91 ) >
V_4 -> V_88 -> V_103 )
V_91 += 1 ;
V_95 = V_94 / V_91 ;
F_6 ( V_4 -> V_7 ,
L_31 ,
V_95 , V_94 , V_91 ) ;
F_40 ( V_4 , 1 ) ;
F_41 ( V_4 , 1 , V_91 ) ;
F_42 ( V_4 ,
( V_104 | V_4 -> V_105 ) , 1 ) ;
F_6 ( V_4 -> V_7 , L_32 ,
( V_94 / V_84 ) ) ;
F_6 ( V_4 -> V_7 , L_33 ,
( V_4 -> V_88 -> V_103 / V_84 ) ) ;
F_6 ( V_4 -> V_7 , L_34 , V_91 ) ;
F_6 ( V_4 -> V_7 , L_35 ,
( ( V_94 / V_91 ) / V_84 ) ) ;
if ( ( V_94 / V_91 ) > V_95 ) {
V_92 = V_95 /
( V_94 / V_91 ) ;
F_17 ( V_4 -> V_7 , L_36 ,
( V_92 / 100 ) ) ;
} else if ( ( V_94 / V_91 ) < ( V_95 ) ) {
V_92 = ( V_94 / V_91 ) /
V_95 ;
F_17 ( V_4 -> V_7 , L_37 ,
( V_92 / 100 ) ) ;
}
} else {
F_42 ( V_4 ,
( V_104 | V_4 -> V_105 ) , 0 ) ;
F_41 ( V_4 , 0 , 0 ) ;
F_40 ( V_4 , 0 ) ;
if ( V_90 == V_97 )
F_26 ( V_4 , 0 ) ;
}
return 0 ;
}
int F_43 ( struct V_3 * V_4 )
{
V_4 -> V_22 = V_106 ;
switch ( V_4 -> V_88 -> V_107 ) {
case V_108 :
V_4 -> V_105 = V_109 ;
break;
case V_110 :
V_4 -> V_105 = V_109 | V_111 ;
break;
case V_112 :
V_4 -> V_105 = V_109 | V_111 |
V_113 ;
break;
case V_114 :
V_4 -> V_105 = V_109 | V_111 |
V_113 | V_115 ;
break;
default:
F_25 ( V_4 -> V_7 , L_38 ) ;
return - V_24 ;
} ;
F_44 ( V_4 ) ;
F_45 ( V_4 ) ;
F_46 ( V_4 , 0 ) ;
return 0 ;
}
void F_47 ( struct V_3 * V_4 )
{
unsigned int V_116 = 0 ;
V_116 = ( V_117 | V_118 ) ;
F_48 ( V_4 , V_116 , 1 ) ;
V_116 = 0 ;
V_116 = ~ ( V_10 | V_12 ) ;
F_49 ( V_4 , V_116 , 1 ) ;
}
int F_50 ( struct V_3 * V_4 ,
unsigned int V_72 )
{
F_49 ( V_4 , V_119 , V_72 ) ;
return 0 ;
}
void F_51 ( struct V_3 * V_4 ,
unsigned int V_72 )
{
F_52 ( V_4 , V_72 ) ;
}
int F_53 ( struct V_3 * V_4 ,
struct V_120 * V_88 )
{
struct V_121 * V_122 ;
struct V_123 * V_124 ;
V_122 = (struct V_121 * ) V_4 -> V_125 ;
V_124 = (struct V_123 * ) V_122 -> V_126 ;
if ( V_88 -> V_127 == ( V_128 ) V_129 ) {
if ( V_88 -> V_130 == 0 ) {
F_54 ( V_4 ,
V_88 -> V_131 ,
V_124 -> V_132 ,
V_124 -> V_133 ) ;
F_55 ( V_4 ,
V_124 -> V_134 ,
V_124 -> V_135 ) ;
F_56 ( V_4 ,
V_124 -> V_136 ,
V_124 -> V_137 ) ;
}
}
F_57 ( V_4 , V_124 -> V_138 ,
V_124 -> V_139 ) ;
F_58 ( V_4 , V_88 ) ;
F_25 ( V_4 -> V_7 , L_39 ,
V_124 -> V_138 , V_124 -> V_139 ) ;
return 0 ;
}
int F_59 ( struct V_3 * V_4 )
{
unsigned int V_140 = 100 ;
switch ( V_4 -> V_22 ) {
case V_106 :
F_60 ( V_4 , 0x1f ) ;
F_61 ( V_4 ) ;
F_62 ( V_4 , V_104 , 1 ) ;
F_62 ( V_4 , V_4 -> V_105 , 1 ) ;
F_37 ( V_4 , V_4 -> V_88 -> V_141 , 1 ) ;
while ( ! ( F_63 ( V_4 ) ) ) {
V_140 -- ;
if ( V_140 == 0 ) {
F_2 ( V_4 -> V_7 ,
L_40 ) ;
F_2 ( V_4 -> V_7 ,
L_41 ) ;
return - V_24 ;
}
}
if ( V_140 != 0 ) {
F_25 ( V_4 -> V_7 ,
L_42 ) ;
F_25 ( V_4 -> V_7 , L_43 ) ;
}
V_4 -> V_22 = V_142 ;
F_64 ( V_4 ,
V_4 -> V_88 -> V_143 ) ;
F_65 ( V_4 ,
V_4 -> V_88 -> V_144 ) ;
F_66 ( V_4 ,
V_4 -> V_88 -> V_145 ) ;
return 0 ;
default:
F_25 ( V_4 -> V_7 , L_44 ) ;
return 0 ;
}
return 0 ;
}
int F_67 ( struct V_3 * V_4 )
{
if ( V_4 -> V_22 != V_142 ) {
F_17 ( V_4 -> V_7 , L_45 ) ;
return 0 ;
}
if ( V_4 -> V_96 == V_102 ) {
F_17 ( V_4 -> V_7 , L_46 ) ;
return 0 ;
}
V_4 -> V_22 = V_146 ;
F_68 ( V_4 , 0 ) ;
F_69 ( V_4 , 0 ) ;
F_70 ( V_4 , 1 ) ;
return 0 ;
}
int F_71 ( struct V_3 * V_4 ,
unsigned int V_147 )
{
if ( V_147 ) {
if ( V_4 -> V_22 != V_146 ) {
F_2 ( V_4 -> V_7 , L_47 ) ;
return - V_24 ;
}
F_68 ( V_4 , 0 ) ;
} else {
if ( V_4 -> V_22 == V_106 || V_4 -> V_22 ==
V_23 ) {
F_2 ( V_4 -> V_7 ,
L_48 ) ;
return - V_24 ;
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
unsigned int V_148 )
{
int V_149 = V_150 ;
F_77 ( V_4 ) ;
F_45 ( V_4 ) ;
do {
if ( F_78 ( V_4 ) ) {
F_47 ( V_4 ) ;
F_6 ( V_4 -> V_7 , L_49 ) ;
return 0 ;
}
} while ( -- V_149 );
F_2 ( V_4 -> V_7 , L_50 ) ;
return - V_47 ;
}
