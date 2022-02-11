static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , unsigned int V_4 )
{
unsigned int V_5 = 0 ;
while ( V_2 -> V_6 && V_4 ) {
V_3 [ V_5 ++ ] = V_2 -> V_7 [ 0 ] & 0xff ;
V_2 -> V_7 [ 0 ] >>= 8 ;
V_4 -- ;
V_2 -> V_6 -- ;
}
if ( ! V_4 )
return V_5 ;
while ( ! ( V_8 & F_2 ( V_2 -> V_9 + V_10 ) ) ) {
if ( V_4 < 4 )
break;
* ( unsigned int * ) ( V_3 + V_5 ) = F_3 ( V_2 -> V_9 + V_11 ) ;
V_4 -= 4 ;
V_5 += 4 ;
}
if ( V_4
&& ! ( V_8 & F_2 ( V_2 -> V_9 + V_10 ) ) ) {
V_2 -> V_7 [ 0 ] = F_2 ( V_2 -> V_9 + V_11 ) ;
for ( V_2 -> V_6 = 4 ; V_2 -> V_6 ; -- V_2 -> V_6 ) {
V_3 [ V_5 ++ ] = V_2 -> V_7 [ 0 ] & 0xff ;
V_2 -> V_7 [ 0 ] >>= 8 ;
V_4 -- ;
if ( ! V_4 )
break;
}
}
return V_5 ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 )
{
unsigned int V_5 = 0 ;
while ( V_2 -> V_6 > 4 && V_4 ) {
V_3 [ V_5 ++ ] = V_2 -> V_7 [ 0 ] & 0xff ;
V_2 -> V_7 [ 0 ] >>= 8 ;
V_4 -- ;
V_2 -> V_6 -- ;
}
if ( ! V_4 )
return V_5 ;
while ( V_2 -> V_6 && V_4 ) {
V_3 [ V_5 ++ ] = V_2 -> V_7 [ 1 ] & 0xff ;
V_2 -> V_7 [ 1 ] >>= 8 ;
V_4 -- ;
V_2 -> V_6 -- ;
}
return V_5 ;
}
static unsigned int F_5 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 )
{
unsigned int V_5 = 0 ;
if ( V_2 -> V_6 ) {
while ( V_2 -> V_6 < 4 && V_4 ) {
V_2 -> V_7 [ 0 ] |= V_3 [ V_5 ++ ] << ( V_2 -> V_6 * 8 ) ;
V_2 -> V_6 ++ ;
V_4 -- ;
}
}
if ( V_2 -> V_6 == 4
&& ! ( V_12 & F_2 ( V_2 -> V_9 + V_10 ) ) ) {
F_6 ( V_2 -> V_7 [ 0 ] , V_2 -> V_9 + V_11 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 [ 0 ] = 0 ;
} else if ( V_2 -> V_6 ) {
return V_5 ;
}
if ( ! V_4 )
return V_5 ;
while ( ! ( V_12 & F_2 ( V_2 -> V_9 + V_10 ) ) ) {
if ( V_4 < 4 )
break;
F_7 ( * ( unsigned int * ) ( V_3 + V_5 ) ,
V_2 -> V_9 + V_11 ) ;
V_4 -= 4 ;
V_5 += 4 ;
}
switch ( V_4 ) {
case 3 :
V_2 -> V_7 [ 0 ] |= V_3 [ V_5 + 2 ] << 16 ;
V_2 -> V_6 ++ ;
case 2 :
V_2 -> V_7 [ 0 ] |= V_3 [ V_5 + 1 ] << 8 ;
V_2 -> V_6 ++ ;
case 1 :
V_2 -> V_7 [ 0 ] |= V_3 [ V_5 ] ;
V_2 -> V_6 ++ ;
}
V_5 += V_2 -> V_6 ;
return V_5 ;
}
static unsigned int F_8 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 )
{
unsigned int V_5 = 0 ;
while ( V_2 -> V_6 < 4 && V_4 ) {
V_2 -> V_7 [ 0 ] &= ~ ( 0xff << ( V_2 -> V_6 * 8 ) ) ;
V_2 -> V_7 [ 0 ] |= V_3 [ V_5 ++ ] << ( V_2 -> V_6 * 8 ) ;
V_2 -> V_6 ++ ;
V_4 -- ;
}
if ( ! V_4 )
return V_5 ;
while ( V_2 -> V_6 < 8 && V_4 ) {
V_2 -> V_7 [ 1 ] &= ~ ( 0xff << ( V_2 -> V_6 * 8 ) ) ;
V_2 -> V_7 [ 1 ] |= V_3 [ V_5 ++ ] << ( V_2 -> V_6 * 8 ) ;
V_2 -> V_6 ++ ;
V_4 -- ;
}
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
unsigned int V_5 ;
unsigned int V_13 , V_14 ;
unsigned char * V_3 ;
struct V_15 * V_16 ;
unsigned long V_17 = 0 ;
if ( V_2 -> V_18 -> V_19 ) {
V_4 = V_2 -> V_18 -> V_20 . V_4 - V_2 -> V_21 ;
V_5 = V_2 -> V_18 -> V_20 . V_22 + V_2 -> V_21 ;
} else {
V_4 = V_2 -> V_18 -> V_23 - V_2 -> V_21 ;
V_5 = 0 ;
}
while ( V_4 ) {
unsigned int V_24 ( V_25 ) ;
if ( V_2 -> V_18 -> V_19 ) {
V_16 = F_10 ( F_11 ( & V_2 -> V_18 -> V_20 ) ,
V_5 >> V_26 ) ;
V_25 = F_12 ( V_5 ) ;
V_14 = V_27 - V_25 ;
V_14 = F_13 ( V_14 , V_4 ) ;
F_14 ( V_17 ) ;
V_3 = F_15 ( V_16 ) + V_25 ;
} else {
V_3 = V_2 -> V_18 -> V_28 + V_2 -> V_21 ;
V_14 = V_2 -> V_18 -> V_23 - V_2 -> V_21 ;
}
if ( V_2 -> V_18 -> V_29 == V_30 )
V_13 = ! ( V_2 -> V_31 & V_32 )
? F_5 ( V_2 , V_3 , V_14 )
: F_8 ( V_2 , V_3 , V_14 ) ;
else
V_13 = ! ( V_2 -> V_31 & V_32 )
? F_1 ( V_2 , V_3 , V_14 )
: F_4 ( V_2 , V_3 , V_14 ) ;
if ( V_2 -> V_18 -> V_19 ) {
F_16 ( V_3 - V_25 ) ;
F_17 ( V_17 ) ;
}
if ( ! V_13 )
break;
V_2 -> V_21 += V_13 ;
V_4 -= V_13 ;
V_5 += V_13 ;
}
if ( ! V_4 && V_2 -> V_18 -> V_29 == V_30 ) {
if ( V_2 -> V_31 & V_32 ) {
F_6 ( V_2 -> V_7 [ 0 ] , V_2 -> V_9 + V_33 ) ;
F_6 ( V_2 -> V_7 [ 1 ] , V_2 -> V_9 + V_34 ) ;
} else if ( V_2 -> V_6 ) {
F_6 ( V_2 -> V_7 [ 0 ] , V_2 -> V_9 + V_11 ) ;
}
}
return V_4 ;
}
static int F_18 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned char * V_28 ;
unsigned int V_23 , V_37 , V_38 ;
if ( ! ( V_39 & F_2 ( V_2 -> V_9 + V_10 ) ) ) {
F_20 ( & V_36 -> V_40 , L_1 ) ;
V_2 -> V_18 -> error = - V_41 ;
return V_2 -> V_18 -> error ;
}
F_20 ( & V_36 -> V_40 , L_2 , F_2 ( V_2 -> V_9 + V_42 ) ) ;
F_20 ( & V_36 -> V_40 , L_3 , F_2 ( V_2 -> V_9 + V_43 ) ) ;
F_20 ( & V_36 -> V_40 , L_4 , F_2 ( V_2 -> V_9 + V_10 ) ) ;
V_2 -> V_31 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 [ 0 ] = 0 ;
V_2 -> V_7 [ 1 ] = 0 ;
V_37 = V_2 -> V_18 -> V_44 << 16 ;
V_37 |= V_45 ;
if ( V_2 -> V_18 -> V_29 == V_46 )
V_37 |= V_47 ;
if ( V_2 -> V_18 -> V_48 ) {
if ( V_2 -> V_49 == V_50 )
V_37 |= V_51 ;
else
V_37 |= V_52 ;
}
V_28 = V_2 -> V_18 -> V_28 ;
if ( ! V_53 )
V_2 -> V_31 |= V_54 ;
if ( V_2 -> V_18 -> V_19 ) {
V_23 = V_2 -> V_18 -> V_20 . V_4 ;
} else {
V_23 = V_2 -> V_18 -> V_23 ;
V_2 -> V_31 &= ~ V_54 ;
}
if ( V_23 <= 8 ) {
V_37 &= ~ ( V_45 | 0xf ) ;
V_2 -> V_31 |= V_32 ;
V_37 |= V_23 & 0xf ;
V_2 -> V_31 &= ~ V_54 ;
}
if ( V_2 -> V_31 & V_54 ) {
if ( 1 != F_21 ( V_2 -> V_55 -> V_56 , & V_2 -> V_18 -> V_20 , 1 ,
V_2 -> V_18 -> V_29 == V_46
? V_57
: V_58 ) ) {
V_2 -> V_18 -> error = - V_59 ;
return V_2 -> V_18 -> error ;
}
V_23 = F_22 ( & V_2 -> V_18 -> V_20 ) ;
F_6 ( F_23 ( & V_2 -> V_18 -> V_20 ) ,
V_2 -> V_9 + V_60 ) ;
F_6 ( ( ( 1 << 16 ) & V_61 )
| ( V_23 & V_62 ) ,
V_2 -> V_9 + V_63 ) ;
F_6 ( V_64 , V_2 -> V_9 + V_65 ) ;
} else if ( ! ( V_2 -> V_31 & V_32 ) ) {
F_6 ( ( ( 1 << 16 ) & V_61 )
| ( V_23 & V_62 ) ,
V_2 -> V_9 + V_63 ) ;
V_38 = F_2 ( V_2 -> V_9 + V_66 ) ;
V_38 |= V_2 -> V_18 -> V_29 == V_46
? V_67
: V_68 ;
F_6 ( V_38 , V_2 -> V_9 + V_66 ) ;
F_6 ( V_38 , V_2 -> V_9 + V_69 ) ;
} else {
V_37 &= ~ ( V_45 | 0xf ) ;
V_2 -> V_31 |= V_32 ;
V_37 |= V_23 & 0xf ;
if ( V_2 -> V_18 -> V_29 == V_30 ) {
F_9 ( V_2 ) ;
F_6 ( V_2 -> V_7 [ 0 ] , V_2 -> V_9 + V_33 ) ;
F_6 ( V_2 -> V_7 [ 1 ] , V_2 -> V_9 + V_34 ) ;
}
}
F_24 ( & V_2 -> V_70 , V_71 + V_2 -> V_72 ) ;
F_6 ( V_73 | F_2 ( V_2 -> V_9 + V_42 ) ,
V_2 -> V_9 + V_42 ) ;
V_2 -> V_18 -> error = 0 ;
F_6 ( V_37 , V_2 -> V_9 + V_74 ) ;
F_20 ( & V_36 -> V_40 , L_5 , V_37 , V_23 ) ;
return 0 ;
}
static void F_25 ( struct V_35 * V_36 , int V_75 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned int V_38 = 0 ;
int V_76 ;
F_26 ( & V_2 -> V_70 ) ;
F_20 ( & V_36 -> V_40 , L_6 ,
F_2 ( V_2 -> V_9 + V_42 ) ) ;
F_20 ( & V_36 -> V_40 , L_7 ,
F_2 ( V_2 -> V_9 + V_43 ) ) ;
F_20 ( & V_36 -> V_40 , L_8 , F_2 ( V_2 -> V_9 + V_10 ) ) ;
V_2 -> V_18 -> V_77 = F_2 ( V_2 -> V_9 + V_10 ) & 0xff ;
F_6 ( 0 , V_2 -> V_9 + V_63 ) ;
F_6 ( 0 , V_2 -> V_9 + V_65 ) ;
if ( V_2 -> V_31 & V_54 ) {
F_27 ( V_2 -> V_55 -> V_56 , & V_2 -> V_18 -> V_20 , 1 ,
V_2 -> V_18 -> V_29 == V_46
? V_57 : V_58 ) ;
} else {
V_38 = F_2 ( V_2 -> V_9 + V_66 ) ;
if ( V_2 -> V_18 -> V_29 == V_46 )
V_38 &= ~ V_67 ;
else
V_38 &= ~ V_68 ;
F_6 ( V_38 , V_2 -> V_9 + V_66 ) ;
F_6 ( V_38 , V_2 -> V_9 + V_69 ) ;
}
F_6 ( ( ~ V_73 ) & F_2 ( V_2 -> V_9 + V_42 ) ,
V_2 -> V_9 + V_42 ) ;
if ( ! V_75 ) {
do {
V_76 = F_28 ( V_36 , & V_2 -> V_18 ) ;
} while ( ! V_76 && F_18 ( V_36 ) );
} else {
do {
V_76 = F_28 ( V_36 , & V_2 -> V_18 ) ;
if ( ! V_76 )
V_2 -> V_18 -> error = - V_41 ;
} while ( ! V_76 );
}
}
static T_1 F_29 ( int V_78 , void * V_79 )
{
struct V_35 * V_36 = V_79 ;
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned int V_80 ;
F_30 ( & V_2 -> V_81 ) ;
V_80 = F_2 ( V_2 -> V_9 + V_43 ) ;
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_9 , V_80 ) ;
if ( V_80 == 0 || V_80 == ( ~ 0 ) ) {
F_31 ( & V_2 -> V_81 ) ;
return V_82 ;
}
if ( V_2 -> V_18 ) {
if ( V_80 & V_83 ) {
if ( V_80 & V_84 )
V_2 -> V_18 -> error = - V_85 ;
else if ( V_80 & V_86 ) {
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_10 ) ;
F_25 ( V_36 , 0 ) ;
} else
V_2 -> V_18 -> error = - V_41 ;
} else {
if ( V_2 -> V_31 & V_54 ) {
if ( V_80 & V_87 )
V_2 -> V_31 |= V_88 ;
} else {
if ( V_80 & ( V_67
| V_68 ) )
F_9 ( V_2 ) ;
if ( V_80 & V_87 ) {
F_9 ( V_2 ) ;
V_2 -> V_31 |= V_88 ;
}
}
if ( V_80 & V_89 ) {
V_2 -> V_31 |= V_90 ;
if ( V_2 -> V_31 & V_32 ) {
if ( V_2 -> V_18 -> V_29 == V_46 ) {
V_2 -> V_7 [ 0 ]
= F_2 ( V_2 -> V_9
+ V_33 ) ;
V_2 -> V_7 [ 1 ]
= F_2 ( V_2 -> V_9
+ V_34 ) ;
V_2 -> V_6 = 8 ;
F_9 ( V_2 ) ;
}
V_2 -> V_31 |= V_88 ;
}
}
}
}
if ( V_80 & ( V_91 | V_92 ) ) {
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_11 ) ;
F_32 ( V_36 ) ;
}
F_6 ( V_80 , V_2 -> V_9 + V_43 ) ;
if ( V_2 -> V_18
&& ( ( ( V_2 -> V_31 & V_90 )
&& ( V_2 -> V_31 & V_88 ) )
|| V_2 -> V_18 -> error ) )
F_25 ( V_36 , 0 ) ;
F_31 ( & V_2 -> V_81 ) ;
return V_93 ;
}
static void F_33 ( unsigned long V_28 )
{
struct V_35 * V_36 = (struct V_35 * ) V_28 ;
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned long V_17 ;
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_12 ) ;
F_34 ( & V_2 -> V_81 , V_17 ) ;
if ( V_2 -> V_18 ) {
V_2 -> V_18 -> error = - V_41 ;
F_25 ( V_36 , 0 ) ;
}
F_35 ( & V_2 -> V_81 , V_17 ) ;
}
static void F_36 ( unsigned long V_28 )
{
struct V_35 * V_36 = (struct V_35 * ) V_28 ;
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned long V_17 ;
int V_76 ;
F_34 ( & V_2 -> V_81 , V_17 ) ;
if ( ! V_2 -> V_18 ) {
do {
V_76 = F_28 ( V_36 , & V_2 -> V_18 ) ;
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_13 , V_76 ) ;
} while ( ! V_76 && F_18 ( V_36 ) );
}
F_35 ( & V_2 -> V_81 , V_17 ) ;
}
static void F_37 ( struct V_35 * V_36 )
{
return;
}
static void F_38 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
F_39 ( & V_2 -> V_94 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_95 ;
F_6 ( V_96 | V_97
| F_2 ( V_2 -> V_9 + V_42 ) ,
V_2 -> V_9 + V_42 ) ;
F_41 () ;
for ( V_95 = 0 ; V_95 < 20 ; ++ V_95 ) {
if ( ! ( V_96
& F_2 ( V_2 -> V_9 + V_42 ) ) )
goto V_98;
F_42 ( 20 ) ;
}
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_14 ) ;
V_98:
F_6 ( V_99 | V_97
| F_2 ( V_2 -> V_9 + V_42 ) ,
V_2 -> V_9 + V_42 ) ;
F_41 () ;
for ( V_95 = 0 ; V_95 < 20 ; ++ V_95 ) {
if ( ! ( V_99
& F_2 ( V_2 -> V_9 + V_42 ) ) )
goto V_100;
F_42 ( 20 ) ;
}
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_15 ) ;
return - V_101 ;
V_100:
F_41 () ;
F_6 ( V_102 , V_2 -> V_9 + V_69 ) ;
F_6 ( V_102 , V_2 -> V_9 + V_66 ) ;
return 0 ;
}
static int F_43 ( struct V_35 * V_36 ,
enum V_103 V_104 ,
int V_105 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned int V_106 = F_2 ( V_2 -> V_9 + V_42 ) ;
unsigned int V_107 = V_108 , V_109 = 0 ;
int V_76 = 0 ;
switch ( V_104 ) {
case V_110 :
if ( V_105 == V_111 ) {
V_76 = F_40 ( V_2 ) ;
if ( V_76 )
return V_76 ;
V_106 = 7 ;
V_106 |= V_112
| V_97 ;
F_6 ( V_106 , V_2 -> V_9 + V_42 ) ;
F_6 ( V_2 -> V_113 ? V_114
: V_115 ,
V_2 -> V_9 + V_116 ) ;
F_6 ( V_117 ,
V_2 -> V_9 + V_118 ) ;
F_44 ( 10 ) ;
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_16 ) ;
} else if ( V_105 == V_119 ) {
V_106 &= ~ ( V_112
| V_97 ) ;
F_6 ( V_106 , V_2 -> V_9 + V_42 ) ;
F_6 ( 0 , V_2 -> V_9 + V_118 ) ;
F_6 ( V_120 , V_2 -> V_9 + V_116 ) ;
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 , L_17 ) ;
} else
return - V_121 ;
break;
case V_122 :
F_20 ( & V_2 -> V_55 -> V_56 -> V_40 ,
L_18 , V_105 ) ;
V_106 &= ~ ( V_123 | V_124 |
V_125 ) ;
V_106 |= V_126 | V_127 ;
V_106 &= ~ ( 3 << V_128 ) ;
if ( V_105 == V_50 ) {
V_106 |= V_129
<< V_128 ;
V_106 |= V_124 ;
V_107 |= V_130 ;
V_109 = 0 ;
} else if ( V_105 == V_131 ) {
V_106 |= V_123 ;
V_106 |= V_132
<< V_128 ;
V_106 |= V_125 ;
V_107 |= V_130 ;
V_109 = 4 ;
} else if ( V_105 == V_133 ) {
V_106 |= V_123 ;
V_106 |= V_134
<< V_128 ;
V_107 |= V_135 ;
V_109 = 0 ;
} else
return - V_121 ;
F_6 ( V_106 , V_2 -> V_9 + V_42 ) ;
F_6 ( V_136 , V_2 -> V_9 + V_137 ) ;
F_6 ( V_107 , V_2 -> V_9 + V_137 ) ;
F_45 ( V_2 -> V_55 -> V_56 ,
V_138 + 1 ,
V_109 ) ;
V_2 -> V_49 = V_105 ;
break;
} ;
return 0 ;
}
static int F_46 ( struct V_139 * V_56 , int V_140 )
{
unsigned char V_141 ;
F_47 ( V_56 , V_142 , & V_141 ) ;
if ( V_140 )
V_141 |= V_143 ;
else
V_141 &= ~ V_143 ;
F_45 ( V_56 , V_142 , V_141 ) ;
F_20 ( & V_56 -> V_40 , L_19 , V_141 ) ;
if ( F_48 ( V_56 , 1 ) ) {
F_47 ( V_56 , V_144 , & V_141 ) ;
if ( V_140 )
V_141 |= V_145 ;
else
V_141 &= ~ V_145 ;
F_45 ( V_56 , V_144 , V_141 ) ;
F_20 ( & V_56 -> V_40 , L_20 , V_141 ) ;
}
F_47 ( V_56 , V_146 , & V_141 ) ;
F_45 ( V_56 , V_146 , V_141 & ~ 0x0f ) ;
F_45 ( V_56 , V_146 , V_141 | 0x01 ) ;
F_20 ( & V_56 -> V_40 , L_21 ) ;
return 0 ;
}
static int F_49 ( struct V_139 * V_40 , T_2 V_147 )
{
struct V_148 * V_149 = F_50 ( V_40 ) ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_149 -> V_150 ; ++ V_95 ) {
if ( ! V_149 -> V_151 [ V_95 ] )
break;
F_51 ( V_149 -> V_151 [ V_95 ] ) ;
}
F_52 ( V_40 ) ;
F_53 ( V_40 , F_54 ( V_40 , V_147 ) , 0 ) ;
F_55 ( V_40 ) ;
F_56 ( V_40 , F_54 ( V_40 , V_147 ) ) ;
return 0 ;
}
static int F_57 ( struct V_139 * V_40 )
{
struct V_148 * V_149 = F_50 ( V_40 ) ;
int V_76 ;
F_56 ( V_40 , V_152 ) ;
F_58 ( V_40 ) ;
V_76 = F_59 ( V_40 ) ;
if ( V_76 )
return V_76 ;
F_60 ( V_40 ) ;
F_46 ( V_40 , 1 ) ;
for ( V_76 = 0 ; V_76 < V_149 -> V_150 ; ++ V_76 ) {
if ( ! V_149 -> V_151 [ V_76 ] )
break;
F_61 ( V_149 -> V_151 [ V_76 ] ) ;
F_32 ( V_149 -> V_151 [ V_76 ] ) ;
}
return 0 ;
}
static int F_62 ( struct V_139 * V_56 )
{
int V_95 , V_76 = 0 ;
for ( V_95 = 0 ; V_95 < V_153 ; ++ V_95 ) {
if ( ! ( V_154 & F_48 ( V_56 , V_95 ) ) )
break;
if ( 256 != F_63 ( V_56 , V_95 ) )
break;
++ V_76 ;
}
return V_76 ;
}
static struct V_35 * F_64 ( struct V_148 * V_149 , int V_95 )
{
struct V_35 * V_36 ;
struct V_1 * V_2 ;
V_36 = F_65 ( sizeof( struct V_1 ) ,
& V_149 -> V_56 -> V_40 ) ;
if ( ! V_36 )
return NULL ;
V_2 = F_19 ( V_36 ) ;
V_2 -> V_55 = V_149 ;
V_2 -> V_9 = F_66 ( F_67 ( V_149 -> V_56 , V_95 ) ,
F_63 ( V_149 -> V_56 , V_95 ) ) ;
if ( ! V_2 -> V_9 )
goto V_155;
F_68 ( & V_2 -> V_81 ) ;
V_2 -> V_113 = V_95 ;
snprintf ( V_2 -> V_156 , sizeof( V_2 -> V_156 ) , V_157 L_22 ,
V_2 -> V_113 ) ;
V_2 -> V_78 = V_149 -> V_56 -> V_78 ;
V_2 -> V_72 = F_69 ( 1000 ) ;
F_70 ( & V_2 -> V_94 , F_36 , ( unsigned long ) V_36 ) ;
V_36 -> V_158 = F_38 ;
V_36 -> V_159 = F_43 ;
V_36 -> V_160 = V_161 | V_162 ;
F_71 ( & V_2 -> V_70 , F_33 , ( unsigned long ) V_36 ) ;
if ( ! F_72 ( V_2 -> V_78 , F_29 , V_163 , V_2 -> V_156 ,
V_36 ) )
return V_36 ;
F_73 ( V_2 -> V_9 ) ;
V_155:
F_74 ( V_36 ) ;
return NULL ;
}
static void F_75 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
F_76 ( V_2 -> V_78 , V_36 ) ;
F_73 ( V_2 -> V_9 ) ;
F_77 ( V_36 ) ;
}
static int F_78 ( struct V_139 * V_56 ,
const struct V_164 * V_79 )
{
struct V_148 * V_149 ;
int V_165 = 0 ;
int V_76 , V_95 ;
V_76 = F_79 ( V_56 , F_80 ( 32 ) ) ;
if ( V_76 )
return V_76 ;
V_76 = F_59 ( V_56 ) ;
if ( V_76 )
return V_76 ;
F_60 ( V_56 ) ;
V_76 = F_81 ( V_56 , V_157 ) ;
if ( V_76 ) {
V_165 = 1 ;
goto V_166;
}
F_46 ( V_56 , 1 ) ;
V_95 = F_62 ( V_56 ) ;
if ( ! V_95 ) {
V_76 = - V_167 ;
V_165 = 1 ;
goto V_166;
}
V_149 = F_82 ( sizeof( struct V_148 )
+ V_95 * sizeof( struct V_35 * ) , V_168 ) ;
if ( ! V_149 ) {
V_76 = - V_59 ;
goto V_169;
}
V_149 -> V_56 = V_56 ;
V_149 -> V_150 = V_95 ;
F_83 ( V_56 , V_149 ) ;
for ( V_95 = 0 ; V_95 < V_149 -> V_150 ; ++ V_95 ) {
V_149 -> V_151 [ V_95 ] = F_64 ( V_149 , V_95 ) ;
if ( ! V_149 -> V_151 [ V_95 ] )
break;
V_76 = F_84 ( V_149 -> V_151 [ V_95 ] ) ;
if ( V_76 ) {
F_75 ( V_149 -> V_151 [ V_95 ] ) ;
V_149 -> V_151 [ V_95 ] = NULL ;
break;
}
}
if ( V_95 )
return 0 ;
V_76 = - V_167 ;
F_83 ( V_56 , NULL ) ;
F_74 ( V_149 ) ;
V_169:
F_85 ( V_56 ) ;
V_166:
if ( ! V_165 )
F_55 ( V_56 ) ;
return V_76 ;
}
static void F_86 ( struct V_139 * V_40 )
{
struct V_148 * V_149 = F_50 ( V_40 ) ;
struct V_1 * V_2 ;
int V_95 ;
unsigned long V_17 ;
for ( V_95 = 0 ; V_95 < V_149 -> V_150 ; ++ V_95 ) {
if ( ! V_149 -> V_151 [ V_95 ] )
break;
V_2 = F_19 ( V_149 -> V_151 [ V_95 ] ) ;
V_149 -> V_151 [ V_95 ] -> V_158 = F_37 ;
F_87 ( & V_2 -> V_94 ) ;
F_6 ( 0 , V_2 -> V_9 + V_69 ) ;
F_6 ( 0 , V_2 -> V_9 + V_66 ) ;
F_41 () ;
F_20 ( & V_149 -> V_56 -> V_40 , L_23 ) ;
F_34 ( & V_2 -> V_81 , V_17 ) ;
if ( V_2 -> V_18 ) {
V_2 -> V_18 -> error = - V_41 ;
F_25 ( V_149 -> V_151 [ V_95 ] , 1 ) ;
}
F_35 ( & V_2 -> V_81 , V_17 ) ;
F_88 ( V_149 -> V_151 [ V_95 ] ) ;
F_20 ( & V_149 -> V_56 -> V_40 , L_24 ) ;
F_75 ( V_149 -> V_151 [ V_95 ] ) ;
}
F_46 ( V_40 , 0 ) ;
F_83 ( V_40 , NULL ) ;
F_85 ( V_40 ) ;
F_55 ( V_40 ) ;
F_74 ( V_149 ) ;
}
