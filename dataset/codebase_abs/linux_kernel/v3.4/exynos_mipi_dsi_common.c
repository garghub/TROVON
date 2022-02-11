T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned int V_3 = 0 ;
unsigned int V_4 = 0 ;
struct V_5 * V_6 = NULL ;
V_6 = V_2 ;
if ( ! V_6 ) {
F_2 ( V_6 -> V_7 , V_8 L_1 ,
V_9 ) ;
return V_10 ;
}
V_3 = F_3 ( V_6 ) ;
V_4 = F_4 ( V_6 ) ;
V_4 = ~ ( V_4 ) & V_3 ;
switch ( V_4 ) {
case V_11 :
F_5 ( & V_12 ) ;
F_2 ( V_6 -> V_7 , L_2 ) ;
break;
case V_13 :
F_5 ( & V_14 ) ;
F_2 ( V_6 -> V_7 , L_3 ) ;
break;
default:
break;
}
F_6 ( V_6 , V_4 ) ;
return V_10 ;
}
static void F_7 ( struct V_5 * V_6 ,
const unsigned char * V_15 , unsigned int V_16 )
{
unsigned int V_17 = 0 , V_18 = 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 += 4 ) {
if ( ( V_16 - V_17 ) < 4 ) {
if ( ( V_16 - V_17 ) == 3 ) {
V_18 = V_15 [ V_17 ] |
V_15 [ V_17 + 1 ] << 8 |
V_15 [ V_17 + 2 ] << 16 ;
F_2 ( V_6 -> V_7 , L_4 ,
V_18 , V_15 [ V_17 ] ,
V_15 [ V_17 + 1 ] ,
V_15 [ V_17 + 2 ] ) ;
} else if ( ( V_16 - V_17 ) == 2 ) {
V_18 = V_15 [ V_17 ] |
V_15 [ V_17 + 1 ] << 8 ;
F_2 ( V_6 -> V_7 ,
L_5 , V_18 ,
V_15 [ V_17 ] ,
V_15 [ V_17 + 1 ] ) ;
} else if ( ( V_16 - V_17 ) == 1 ) {
V_18 = V_15 [ V_17 ] ;
}
F_8 ( V_6 , V_18 ) ;
} else {
V_18 = V_15 [ V_17 ] |
V_15 [ V_17 + 1 ] << 8 |
V_15 [ V_17 + 2 ] << 16 |
V_15 [ V_17 + 3 ] << 24 ;
F_2 ( V_6 -> V_7 ,
L_6 ,
V_18 , * ( V_19 * ) ( V_15 + V_17 ) ,
V_15 [ V_17 + 1 ] ,
V_15 [ V_17 + 2 ] ,
V_15 [ V_17 + 3 ] ) ;
F_8 ( V_6 , V_18 ) ;
}
}
}
int F_9 ( struct V_5 * V_6 , unsigned int V_20 ,
const unsigned char * V_15 , unsigned int V_16 )
{
unsigned int V_21 = 0 ;
if ( V_6 -> V_22 == V_23 ) {
F_10 ( V_6 -> V_7 , L_7 ) ;
return - V_24 ;
}
F_11 ( 20 ) ;
F_12 ( & V_6 -> V_25 ) ;
switch ( V_20 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
F_13 ( V_6 , V_20 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_21 ) {
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
} else {
F_14 ( & V_6 -> V_25 ) ;
return - V_24 ;
}
case V_32 :
case V_33 :
case V_34 :
case V_35 :
F_13 ( V_6 , V_20 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_21 ) {
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
} else {
F_14 ( & V_6 -> V_25 ) ;
return - V_24 ;
}
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
case V_41 :
case V_42 :
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
case V_43 :
case V_44 :
{
unsigned int V_45 , V_18 = 0 ;
F_15 ( V_14 ) ;
V_45 = V_16 * 4 ;
if ( V_16 < 4 ) {
V_18 = V_15 [ 0 ] |
V_15 [ 1 ] << 8 |
V_15 [ 2 ] << 16 ;
F_8 ( V_6 , V_18 ) ;
F_2 ( V_6 -> V_7 , L_8 ,
V_16 , V_18 , V_15 [ 0 ] ,
V_15 [ 1 ] , V_15 [ 2 ] ) ;
} else
F_7 ( V_6 , V_15 , V_16 ) ;
F_13 ( V_6 , V_20 , V_16 & 0xff ,
( V_16 & 0xff00 ) >> 8 ) ;
if ( ! F_16 ( & V_14 ,
V_46 ) ) {
F_17 ( V_6 -> V_7 , L_9 ) ;
F_14 ( & V_6 -> V_25 ) ;
return - V_47 ;
}
if ( V_21 ) {
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
} else {
F_14 ( & V_6 -> V_25 ) ;
return - V_24 ;
}
}
case V_48 :
case V_49 :
case V_50 :
case V_51 :
if ( V_21 ) {
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
} else {
F_14 ( & V_6 -> V_25 ) ;
return - V_24 ;
}
default:
F_17 ( V_6 -> V_7 ,
L_10 ,
V_20 ) ;
F_14 ( & V_6 -> V_25 ) ;
return - V_24 ;
}
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
}
static unsigned int F_18 ( struct V_5 * V_6 ,
unsigned int V_52 , unsigned int V_53 , V_19 * V_54 )
{
unsigned int V_55 , V_56 , V_57 ;
T_2 V_58 ;
V_58 = ( T_2 ) ( ( V_53 & 0x00ffff00 ) >> 8 ) ;
F_2 ( V_6 -> V_7 , L_11 , V_58 ) ;
if ( V_58 != V_52 ) {
F_2 ( V_6 -> V_7 ,
L_12 ,
V_58 , V_52 ) ;
goto V_59;
}
for ( V_56 = 0 ; V_56 < ( V_58 >> 2 ) ; V_56 ++ ) {
V_55 = F_19 ( V_6 ) ;
F_2 ( V_6 -> V_7 , L_13 , V_55 ) ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
V_54 [ ( V_56 * 4 ) + V_57 ] =
( V_19 ) ( V_55 >> ( V_57 * 8 ) ) & 0xff ;
F_2 ( V_6 -> V_7 , L_14 ,
( V_55 >> ( V_57 * 8 ) ) & 0xff ) ;
}
}
if ( V_58 % 4 ) {
V_55 = F_19 ( V_6 ) ;
F_2 ( V_6 -> V_7 , L_13 , V_55 ) ;
for ( V_57 = 0 ; V_57 < ( V_58 % 4 ) ; V_57 ++ ) {
V_54 [ ( V_56 * 4 ) + V_57 ] =
( V_19 ) ( V_55 >> ( V_57 * 8 ) ) & 0xff ;
F_2 ( V_6 -> V_7 , L_14 ,
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
int F_21 ( struct V_5 * V_6 , unsigned int V_20 ,
unsigned int V_15 , unsigned int V_52 , V_19 * V_54 )
{
unsigned int V_53 , V_55 , V_56 ;
V_19 V_63 = 0 ;
T_2 V_58 ;
if ( V_6 -> V_22 == V_23 ) {
F_10 ( V_6 -> V_7 , L_7 ) ;
return - V_24 ;
}
F_11 ( 20 ) ;
F_12 ( & V_6 -> V_25 ) ;
F_15 ( V_12 ) ;
F_22 ( V_6 ,
V_31 , V_52 ) ;
V_63 = F_20 ( V_52 ) ;
switch ( V_20 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
F_22 ( V_6 ,
V_20 , V_15 ) ;
break;
default:
F_17 ( V_6 -> V_7 ,
L_10 ,
V_20 ) ;
return - V_24 ;
}
if ( ! F_16 ( & V_12 ,
V_46 ) ) {
F_23 ( L_15 ) ;
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
}
F_11 ( 20 ) ;
V_53 = F_19 ( V_6 ) ;
if ( ( V_19 ) ( V_53 & 0xff ) != V_63 ) {
F_24 ( V_8
L_16 ,
V_53 , V_63 ) ;
goto V_68;
}
if ( V_52 <= 2 ) {
for ( V_56 = 0 ; V_56 < V_52 ; V_56 ++ )
V_54 [ V_56 ] = ( V_53 >> ( 8 + ( V_56 * 8 ) ) ) & 0xff ;
V_58 = V_52 ;
} else {
V_58 = F_18 ( V_6 , V_52 , V_53 ,
V_54 ) ;
if ( V_58 != V_52 )
goto V_68;
}
V_55 = F_19 ( V_6 ) ;
F_11 ( 20 ) ;
if ( V_55 != V_69 ) {
F_25 ( V_6 -> V_7 ,
L_17 , V_55 ) ;
goto V_68;
}
F_14 ( & V_6 -> V_25 ) ;
return V_58 ;
V_68:
V_56 = 0 ;
while ( 1 ) {
V_55 = F_19 ( V_6 ) ;
if ( ( V_55 == V_69 )
|| ( V_56 > V_70 ) )
break;
F_2 ( V_6 -> V_7 ,
L_18 , V_55 ) ;
V_56 ++ ;
}
F_25 ( V_6 -> V_7 ,
L_19 , V_56 , V_55 ) ;
F_14 ( & V_6 -> V_25 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
unsigned int V_71 )
{
int V_72 ;
if ( V_71 ) {
V_72 = 1000 ;
F_27 ( V_6 , 1 ) ;
while ( 1 ) {
V_72 -- ;
if ( F_28 ( V_6 ) )
return 0 ;
if ( V_72 == 0 )
return - V_24 ;
}
} else
F_27 ( V_6 , 0 ) ;
return 0 ;
}
static unsigned long F_29 ( struct V_5 * V_6 ,
unsigned int V_73 , unsigned int V_74 ,
unsigned int V_75 )
{
unsigned long V_76 , V_77 , V_78 ;
unsigned int V_56 , V_79 = 0xf ;
V_76 = ( V_80 / V_73 ) ;
if ( V_76 < V_81 || V_76 > V_82 ) {
F_17 ( V_6 -> V_7 , L_20 ) ;
F_30 ( V_6 , 0 , 0 ) ;
} else {
if ( V_76 < 7 * V_83 )
F_30 ( V_6 , 1 , 0x1 ) ;
else if ( V_76 < 8 * V_83 )
F_30 ( V_6 , 1 , 0x0 ) ;
else if ( V_76 < 9 * V_83 )
F_30 ( V_6 , 1 , 0x3 ) ;
else if ( V_76 < 10 * V_83 )
F_30 ( V_6 , 1 , 0x2 ) ;
else if ( V_76 < 11 * V_83 )
F_30 ( V_6 , 1 , 0x5 ) ;
else
F_30 ( V_6 , 1 , 0x4 ) ;
}
V_77 = V_76 * V_74 ;
F_2 ( V_6 -> V_7 , L_21 ,
V_77 , V_76 , V_74 ) ;
if ( V_77 < V_84 || V_77 > V_85 )
F_17 ( V_6 -> V_7 , L_22 ) ;
V_78 = V_77 / ( 1 << V_75 ) ;
F_2 ( V_6 -> V_7 , L_23 ,
V_78 , V_77 , V_75 ) ;
for ( V_56 = 0 ; V_56 < F_31 ( V_86 ) ; V_56 ++ ) {
if ( V_78 < V_86 [ V_56 ] * V_83 ) {
V_79 = V_56 ;
break;
}
}
F_2 ( V_6 -> V_7 , L_24 , V_79 ) ;
F_32 ( V_6 , V_73 , V_74 , V_75 ) ;
F_33 ( V_6 , 0 ) ;
F_34 ( V_6 , 0 ) ;
F_35 ( V_6 , V_79 ) ;
F_36 ( V_6 , V_6 -> V_87 -> V_88 ) ;
F_2 ( V_6 -> V_7 , L_25 ,
( V_78 / V_83 ) ) ;
return V_78 ;
}
static int F_37 ( struct V_5 * V_6 ,
unsigned int V_89 , unsigned int V_71 )
{
unsigned int V_90 ;
unsigned long V_91 ;
unsigned long V_92 = 0 , V_93 = 0 , V_94 = 0 ;
if ( V_71 ) {
V_6 -> V_95 = V_89 ;
F_38 ( V_6 , V_89 ) ;
if ( V_89 == V_96 ) {
V_92 = F_29 ( V_6 ,
V_6 -> V_87 -> V_97 , V_6 -> V_87 -> V_98 ,
V_6 -> V_87 -> V_99 ) ;
if ( V_92 == 0 ) {
F_10 ( V_6 -> V_7 ,
L_26 ) ;
return - V_24 ;
}
V_93 = V_92 / 8 ;
F_39 ( V_6 , 0 ) ;
F_26 ( V_6 , 1 ) ;
} else if ( V_89 == V_100 ) {
F_17 ( V_6 -> V_7 , L_27 ) ;
F_17 ( V_6 -> V_7 ,
L_28 ) ;
} else if ( V_89 == V_101 ) {
F_17 ( V_6 -> V_7 , L_27 ) ;
F_17 ( V_6 -> V_7 ,
L_29 ) ;
}
V_90 = V_93 / ( V_6 -> V_87 -> V_102 ) ;
F_2 ( V_6 -> V_7 ,
L_30 ,
V_90 , V_93 , V_6 -> V_87 -> V_102 ) ;
if ( ( V_93 / V_90 ) >= ( 20 * V_83 ) ||
( V_93 / V_90 ) >
V_6 -> V_87 -> V_102 )
V_90 += 1 ;
V_94 = V_93 / V_90 ;
F_2 ( V_6 -> V_7 ,
L_31 ,
V_94 , V_93 , V_90 ) ;
F_40 ( V_6 , 1 ) ;
F_41 ( V_6 , 1 , V_90 ) ;
F_42 ( V_6 ,
( V_103 | V_6 -> V_104 ) , 1 ) ;
F_2 ( V_6 -> V_7 , L_32 ,
( V_93 / V_83 ) ) ;
F_2 ( V_6 -> V_7 , L_33 ,
( V_6 -> V_87 -> V_102 / V_83 ) ) ;
F_2 ( V_6 -> V_7 , L_34 , V_90 ) ;
F_2 ( V_6 -> V_7 , L_35 ,
( ( V_93 / V_90 ) / V_83 ) ) ;
if ( ( V_93 / V_90 ) > V_94 ) {
V_91 = V_94 /
( V_93 / V_90 ) ;
F_17 ( V_6 -> V_7 , L_36 ,
( V_91 / 100 ) ) ;
} else if ( ( V_93 / V_90 ) < ( V_94 ) ) {
V_91 = ( V_93 / V_90 ) /
V_94 ;
F_17 ( V_6 -> V_7 , L_37 ,
( V_91 / 100 ) ) ;
}
} else {
F_42 ( V_6 ,
( V_103 | V_6 -> V_104 ) , 0 ) ;
F_41 ( V_6 , 0 , 0 ) ;
F_40 ( V_6 , 0 ) ;
if ( V_89 == V_96 )
F_26 ( V_6 , 0 ) ;
}
return 0 ;
}
int F_43 ( struct V_5 * V_6 )
{
V_6 -> V_22 = V_105 ;
switch ( V_6 -> V_87 -> V_106 ) {
case V_107 :
V_6 -> V_104 = V_108 ;
break;
case V_109 :
V_6 -> V_104 = V_108 | V_110 ;
break;
case V_111 :
V_6 -> V_104 = V_108 | V_110 |
V_112 ;
break;
case V_113 :
V_6 -> V_104 = V_108 | V_110 |
V_112 | V_114 ;
break;
default:
F_25 ( V_6 -> V_7 , L_38 ) ;
return - V_24 ;
} ;
F_44 ( V_6 ) ;
F_45 ( V_6 ) ;
F_46 ( V_6 , 0 ) ;
return 0 ;
}
void F_47 ( struct V_5 * V_6 )
{
unsigned int V_115 = 0 ;
V_115 = ( V_116 | V_117 ) ;
F_48 ( V_6 , V_115 , 1 ) ;
V_115 = 0 ;
V_115 = ~ ( V_11 | V_13 ) ;
F_49 ( V_6 , V_115 , 1 ) ;
}
int F_50 ( struct V_5 * V_6 ,
unsigned int V_71 )
{
F_49 ( V_6 , V_118 , V_71 ) ;
return 0 ;
}
void F_51 ( struct V_5 * V_6 ,
unsigned int V_71 )
{
F_52 ( V_6 , V_71 ) ;
}
int F_53 ( struct V_5 * V_6 ,
struct V_119 * V_87 )
{
struct V_120 * V_121 ;
struct V_122 * V_123 ;
V_121 = (struct V_120 * ) V_6 -> V_124 ;
V_123 = (struct V_122 * ) V_121 -> V_125 ;
if ( V_87 -> V_126 == ( V_127 ) V_128 ) {
if ( V_87 -> V_129 == 0 ) {
F_54 ( V_6 ,
V_87 -> V_130 ,
V_123 -> V_131 ,
V_123 -> V_132 ) ;
F_55 ( V_6 ,
V_123 -> V_133 ,
V_123 -> V_134 ) ;
F_56 ( V_6 ,
V_123 -> V_135 ,
V_123 -> V_136 ) ;
}
}
F_57 ( V_6 , V_123 -> V_137 ,
V_123 -> V_138 ) ;
F_58 ( V_6 , V_87 ) ;
F_25 ( V_6 -> V_7 , L_39 ,
V_123 -> V_137 , V_123 -> V_138 ) ;
return 0 ;
}
int F_59 ( struct V_5 * V_6 )
{
unsigned int V_139 = 100 ;
switch ( V_6 -> V_22 ) {
case V_105 :
F_60 ( V_6 , 0x1f ) ;
F_61 ( V_6 ) ;
F_62 ( V_6 , V_103 , 1 ) ;
F_62 ( V_6 , V_6 -> V_104 , 1 ) ;
F_37 ( V_6 , V_6 -> V_87 -> V_140 , 1 ) ;
while ( ! ( F_63 ( V_6 ) ) ) {
V_139 -- ;
if ( V_139 == 0 ) {
F_10 ( V_6 -> V_7 ,
L_40 ) ;
F_10 ( V_6 -> V_7 ,
L_41 ) ;
return - V_24 ;
}
}
if ( V_139 != 0 ) {
F_25 ( V_6 -> V_7 ,
L_42 ) ;
F_25 ( V_6 -> V_7 , L_43 ) ;
}
V_6 -> V_22 = V_141 ;
F_64 ( V_6 ,
V_6 -> V_87 -> V_142 ) ;
F_65 ( V_6 ,
V_6 -> V_87 -> V_143 ) ;
F_66 ( V_6 ,
V_6 -> V_87 -> V_144 ) ;
return 0 ;
default:
F_25 ( V_6 -> V_7 , L_44 ) ;
return 0 ;
}
return 0 ;
}
int F_67 ( struct V_5 * V_6 )
{
if ( V_6 -> V_22 != V_141 ) {
F_17 ( V_6 -> V_7 , L_45 ) ;
return 0 ;
}
if ( V_6 -> V_95 == V_101 ) {
F_17 ( V_6 -> V_7 , L_46 ) ;
return 0 ;
}
V_6 -> V_22 = V_145 ;
F_68 ( V_6 , 0 ) ;
F_69 ( V_6 , 0 ) ;
F_70 ( V_6 , 1 ) ;
return 0 ;
}
int F_71 ( struct V_5 * V_6 ,
unsigned int V_146 )
{
if ( V_146 ) {
if ( V_6 -> V_22 != V_145 ) {
F_10 ( V_6 -> V_7 , L_47 ) ;
return - V_24 ;
}
F_68 ( V_6 , 0 ) ;
} else {
if ( V_6 -> V_22 == V_105 || V_6 -> V_22 ==
V_23 ) {
F_10 ( V_6 -> V_7 ,
L_48 ) ;
return - V_24 ;
}
F_69 ( V_6 , 0 ) ;
}
return 0 ;
}
int F_72 ( struct V_5 * V_6 )
{
return F_73 ( V_6 ) ;
}
int F_74 ( struct V_5 * V_6 )
{
F_75 ( V_6 ) ;
return 0 ;
}
int F_76 ( struct V_5 * V_6 ,
unsigned int V_147 )
{
int V_148 = V_149 ;
F_77 ( V_6 ) ;
F_45 ( V_6 ) ;
do {
if ( F_78 ( V_6 ) ) {
F_47 ( V_6 ) ;
F_2 ( V_6 -> V_7 , L_49 ) ;
return 0 ;
}
} while ( -- V_148 );
F_10 ( V_6 -> V_7 , L_50 ) ;
return - V_47 ;
}
