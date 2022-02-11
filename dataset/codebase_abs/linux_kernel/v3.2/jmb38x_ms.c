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
V_3 = F_15 ( V_16 , V_28 ) + V_25 ;
} else {
V_3 = V_2 -> V_18 -> V_29 + V_2 -> V_21 ;
V_14 = V_2 -> V_18 -> V_23 - V_2 -> V_21 ;
}
if ( V_2 -> V_18 -> V_30 == V_31 )
V_13 = ! ( V_2 -> V_32 & V_33 )
? F_5 ( V_2 , V_3 , V_14 )
: F_8 ( V_2 , V_3 , V_14 ) ;
else
V_13 = ! ( V_2 -> V_32 & V_33 )
? F_1 ( V_2 , V_3 , V_14 )
: F_4 ( V_2 , V_3 , V_14 ) ;
if ( V_2 -> V_18 -> V_19 ) {
F_16 ( V_3 - V_25 , V_28 ) ;
F_17 ( V_17 ) ;
}
if ( ! V_13 )
break;
V_2 -> V_21 += V_13 ;
V_4 -= V_13 ;
V_5 += V_13 ;
}
if ( ! V_4 && V_2 -> V_18 -> V_30 == V_31 ) {
if ( V_2 -> V_32 & V_33 ) {
F_6 ( V_2 -> V_7 [ 0 ] , V_2 -> V_9 + V_34 ) ;
F_6 ( V_2 -> V_7 [ 1 ] , V_2 -> V_9 + V_35 ) ;
} else if ( V_2 -> V_6 ) {
F_6 ( V_2 -> V_7 [ 0 ] , V_2 -> V_9 + V_11 ) ;
}
}
return V_4 ;
}
static int F_18 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_19 ( V_37 ) ;
unsigned char * V_29 ;
unsigned int V_23 , V_38 , V_39 ;
if ( ! ( V_40 & F_2 ( V_2 -> V_9 + V_10 ) ) ) {
F_20 ( & V_37 -> V_41 , L_1 ) ;
V_2 -> V_18 -> error = - V_42 ;
return V_2 -> V_18 -> error ;
}
F_20 ( & V_37 -> V_41 , L_2 , F_2 ( V_2 -> V_9 + V_43 ) ) ;
F_20 ( & V_37 -> V_41 , L_3 , F_2 ( V_2 -> V_9 + V_44 ) ) ;
F_20 ( & V_37 -> V_41 , L_4 , F_2 ( V_2 -> V_9 + V_10 ) ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 [ 0 ] = 0 ;
V_2 -> V_7 [ 1 ] = 0 ;
V_38 = V_2 -> V_18 -> V_45 << 16 ;
V_38 |= V_46 ;
if ( V_2 -> V_18 -> V_30 == V_47 )
V_38 |= V_48 ;
if ( V_2 -> V_18 -> V_49 ) {
if ( V_2 -> V_50 == V_51 )
V_38 |= V_52 ;
else
V_38 |= V_53 ;
}
V_29 = V_2 -> V_18 -> V_29 ;
if ( ! V_54 )
V_2 -> V_32 |= V_55 ;
if ( V_2 -> V_18 -> V_19 ) {
V_23 = V_2 -> V_18 -> V_20 . V_4 ;
} else {
V_23 = V_2 -> V_18 -> V_23 ;
V_2 -> V_32 &= ~ V_55 ;
}
if ( V_23 <= 8 ) {
V_38 &= ~ ( V_46 | 0xf ) ;
V_2 -> V_32 |= V_33 ;
V_38 |= V_23 & 0xf ;
V_2 -> V_32 &= ~ V_55 ;
}
if ( V_2 -> V_32 & V_55 ) {
if ( 1 != F_21 ( V_2 -> V_56 -> V_57 , & V_2 -> V_18 -> V_20 , 1 ,
V_2 -> V_18 -> V_30 == V_47
? V_58
: V_59 ) ) {
V_2 -> V_18 -> error = - V_60 ;
return V_2 -> V_18 -> error ;
}
V_23 = F_22 ( & V_2 -> V_18 -> V_20 ) ;
F_6 ( F_23 ( & V_2 -> V_18 -> V_20 ) ,
V_2 -> V_9 + V_61 ) ;
F_6 ( ( ( 1 << 16 ) & V_62 )
| ( V_23 & V_63 ) ,
V_2 -> V_9 + V_64 ) ;
F_6 ( V_65 , V_2 -> V_9 + V_66 ) ;
} else if ( ! ( V_2 -> V_32 & V_33 ) ) {
F_6 ( ( ( 1 << 16 ) & V_62 )
| ( V_23 & V_63 ) ,
V_2 -> V_9 + V_64 ) ;
V_39 = F_2 ( V_2 -> V_9 + V_67 ) ;
V_39 |= V_2 -> V_18 -> V_30 == V_47
? V_68
: V_69 ;
F_6 ( V_39 , V_2 -> V_9 + V_67 ) ;
F_6 ( V_39 , V_2 -> V_9 + V_70 ) ;
} else {
V_38 &= ~ ( V_46 | 0xf ) ;
V_2 -> V_32 |= V_33 ;
V_38 |= V_23 & 0xf ;
if ( V_2 -> V_18 -> V_30 == V_31 ) {
F_9 ( V_2 ) ;
F_6 ( V_2 -> V_7 [ 0 ] , V_2 -> V_9 + V_34 ) ;
F_6 ( V_2 -> V_7 [ 1 ] , V_2 -> V_9 + V_35 ) ;
}
}
F_24 ( & V_2 -> V_71 , V_72 + V_2 -> V_73 ) ;
F_6 ( V_74 | F_2 ( V_2 -> V_9 + V_43 ) ,
V_2 -> V_9 + V_43 ) ;
V_2 -> V_18 -> error = 0 ;
F_6 ( V_38 , V_2 -> V_9 + V_75 ) ;
F_20 ( & V_37 -> V_41 , L_5 , V_38 , V_23 ) ;
return 0 ;
}
static void F_25 ( struct V_36 * V_37 , int V_76 )
{
struct V_1 * V_2 = F_19 ( V_37 ) ;
unsigned int V_39 = 0 ;
int V_77 ;
F_26 ( & V_2 -> V_71 ) ;
F_20 ( & V_37 -> V_41 , L_6 ,
F_2 ( V_2 -> V_9 + V_43 ) ) ;
F_20 ( & V_37 -> V_41 , L_7 ,
F_2 ( V_2 -> V_9 + V_44 ) ) ;
F_20 ( & V_37 -> V_41 , L_8 , F_2 ( V_2 -> V_9 + V_10 ) ) ;
V_2 -> V_18 -> V_78 = F_2 ( V_2 -> V_9 + V_10 ) & 0xff ;
F_6 ( 0 , V_2 -> V_9 + V_64 ) ;
F_6 ( 0 , V_2 -> V_9 + V_66 ) ;
if ( V_2 -> V_32 & V_55 ) {
F_27 ( V_2 -> V_56 -> V_57 , & V_2 -> V_18 -> V_20 , 1 ,
V_2 -> V_18 -> V_30 == V_47
? V_58 : V_59 ) ;
} else {
V_39 = F_2 ( V_2 -> V_9 + V_67 ) ;
if ( V_2 -> V_18 -> V_30 == V_47 )
V_39 &= ~ V_68 ;
else
V_39 &= ~ V_69 ;
F_6 ( V_39 , V_2 -> V_9 + V_67 ) ;
F_6 ( V_39 , V_2 -> V_9 + V_70 ) ;
}
F_6 ( ( ~ V_74 ) & F_2 ( V_2 -> V_9 + V_43 ) ,
V_2 -> V_9 + V_43 ) ;
if ( ! V_76 ) {
do {
V_77 = F_28 ( V_37 , & V_2 -> V_18 ) ;
} while ( ! V_77 && F_18 ( V_37 ) );
} else {
do {
V_77 = F_28 ( V_37 , & V_2 -> V_18 ) ;
if ( ! V_77 )
V_2 -> V_18 -> error = - V_42 ;
} while ( ! V_77 );
}
}
static T_1 F_29 ( int V_79 , void * V_80 )
{
struct V_36 * V_37 = V_80 ;
struct V_1 * V_2 = F_19 ( V_37 ) ;
unsigned int V_81 ;
F_30 ( & V_2 -> V_82 ) ;
V_81 = F_2 ( V_2 -> V_9 + V_44 ) ;
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_9 , V_81 ) ;
if ( V_81 == 0 || V_81 == ( ~ 0 ) ) {
F_31 ( & V_2 -> V_82 ) ;
return V_83 ;
}
if ( V_2 -> V_18 ) {
if ( V_81 & V_84 ) {
if ( V_81 & V_85 )
V_2 -> V_18 -> error = - V_86 ;
else if ( V_81 & V_87 ) {
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_10 ) ;
F_25 ( V_37 , 0 ) ;
} else
V_2 -> V_18 -> error = - V_42 ;
} else {
if ( V_2 -> V_32 & V_55 ) {
if ( V_81 & V_88 )
V_2 -> V_32 |= V_89 ;
} else {
if ( V_81 & ( V_68
| V_69 ) )
F_9 ( V_2 ) ;
if ( V_81 & V_88 ) {
F_9 ( V_2 ) ;
V_2 -> V_32 |= V_89 ;
}
}
if ( V_81 & V_90 ) {
V_2 -> V_32 |= V_91 ;
if ( V_2 -> V_32 & V_33 ) {
if ( V_2 -> V_18 -> V_30 == V_47 ) {
V_2 -> V_7 [ 0 ]
= F_2 ( V_2 -> V_9
+ V_34 ) ;
V_2 -> V_7 [ 1 ]
= F_2 ( V_2 -> V_9
+ V_35 ) ;
V_2 -> V_6 = 8 ;
F_9 ( V_2 ) ;
}
V_2 -> V_32 |= V_89 ;
}
}
}
}
if ( V_81 & ( V_92 | V_93 ) ) {
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_11 ) ;
F_32 ( V_37 ) ;
}
F_6 ( V_81 , V_2 -> V_9 + V_44 ) ;
if ( V_2 -> V_18
&& ( ( ( V_2 -> V_32 & V_91 )
&& ( V_2 -> V_32 & V_89 ) )
|| V_2 -> V_18 -> error ) )
F_25 ( V_37 , 0 ) ;
F_31 ( & V_2 -> V_82 ) ;
return V_94 ;
}
static void F_33 ( unsigned long V_29 )
{
struct V_36 * V_37 = (struct V_36 * ) V_29 ;
struct V_1 * V_2 = F_19 ( V_37 ) ;
unsigned long V_17 ;
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_12 ) ;
F_34 ( & V_2 -> V_82 , V_17 ) ;
if ( V_2 -> V_18 ) {
V_2 -> V_18 -> error = - V_42 ;
F_25 ( V_37 , 0 ) ;
}
F_35 ( & V_2 -> V_82 , V_17 ) ;
}
static void F_36 ( unsigned long V_29 )
{
struct V_36 * V_37 = (struct V_36 * ) V_29 ;
struct V_1 * V_2 = F_19 ( V_37 ) ;
unsigned long V_17 ;
int V_77 ;
F_34 ( & V_2 -> V_82 , V_17 ) ;
if ( ! V_2 -> V_18 ) {
do {
V_77 = F_28 ( V_37 , & V_2 -> V_18 ) ;
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_13 , V_77 ) ;
} while ( ! V_77 && F_18 ( V_37 ) );
}
F_35 ( & V_2 -> V_82 , V_17 ) ;
}
static void F_37 ( struct V_36 * V_37 )
{
return;
}
static void F_38 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_19 ( V_37 ) ;
F_39 ( & V_2 -> V_95 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_96 ;
F_6 ( V_97 | V_98
| F_2 ( V_2 -> V_9 + V_43 ) ,
V_2 -> V_9 + V_43 ) ;
F_41 () ;
for ( V_96 = 0 ; V_96 < 20 ; ++ V_96 ) {
if ( ! ( V_97
& F_2 ( V_2 -> V_9 + V_43 ) ) )
goto V_99;
F_42 ( 20 ) ;
}
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_14 ) ;
V_99:
F_6 ( V_100 | V_98
| F_2 ( V_2 -> V_9 + V_43 ) ,
V_2 -> V_9 + V_43 ) ;
F_41 () ;
for ( V_96 = 0 ; V_96 < 20 ; ++ V_96 ) {
if ( ! ( V_100
& F_2 ( V_2 -> V_9 + V_43 ) ) )
goto V_101;
F_42 ( 20 ) ;
}
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_15 ) ;
return - V_102 ;
V_101:
F_41 () ;
F_6 ( V_103 , V_2 -> V_9 + V_70 ) ;
F_6 ( V_103 , V_2 -> V_9 + V_67 ) ;
return 0 ;
}
static int F_43 ( struct V_36 * V_37 ,
enum V_104 V_105 ,
int V_106 )
{
struct V_1 * V_2 = F_19 ( V_37 ) ;
unsigned int V_107 = F_2 ( V_2 -> V_9 + V_43 ) ;
unsigned int V_108 = V_109 , V_110 = 0 ;
int V_77 = 0 ;
switch ( V_105 ) {
case V_111 :
if ( V_106 == V_112 ) {
V_77 = F_40 ( V_2 ) ;
if ( V_77 )
return V_77 ;
V_107 = 7 ;
V_107 |= V_113
| V_98 ;
F_6 ( V_107 , V_2 -> V_9 + V_43 ) ;
F_6 ( V_2 -> V_114 ? V_115
: V_116 ,
V_2 -> V_9 + V_117 ) ;
F_6 ( V_118 ,
V_2 -> V_9 + V_119 ) ;
F_44 ( 10 ) ;
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_16 ) ;
} else if ( V_106 == V_120 ) {
V_107 &= ~ ( V_113
| V_98 ) ;
F_6 ( V_107 , V_2 -> V_9 + V_43 ) ;
F_6 ( 0 , V_2 -> V_9 + V_119 ) ;
F_6 ( V_121 , V_2 -> V_9 + V_117 ) ;
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 , L_17 ) ;
} else
return - V_122 ;
break;
case V_123 :
F_20 ( & V_2 -> V_56 -> V_57 -> V_41 ,
L_18 , V_106 ) ;
V_107 &= ~ ( V_124 | V_125 |
V_126 ) ;
V_107 |= V_127 | V_128 ;
V_107 &= ~ ( 3 << V_129 ) ;
if ( V_106 == V_51 ) {
V_107 |= V_130
<< V_129 ;
V_107 |= V_125 ;
V_108 |= V_131 ;
V_110 = 0 ;
} else if ( V_106 == V_132 ) {
V_107 |= V_124 ;
V_107 |= V_133
<< V_129 ;
V_107 |= V_126 ;
V_108 |= V_131 ;
V_110 = 4 ;
} else if ( V_106 == V_134 ) {
V_107 |= V_124 ;
V_107 |= V_135
<< V_129 ;
V_108 |= V_136 ;
V_110 = 0 ;
} else
return - V_122 ;
F_6 ( V_107 , V_2 -> V_9 + V_43 ) ;
F_6 ( V_137 , V_2 -> V_9 + V_138 ) ;
F_6 ( V_108 , V_2 -> V_9 + V_138 ) ;
F_45 ( V_2 -> V_56 -> V_57 ,
V_139 + 1 ,
V_110 ) ;
V_2 -> V_50 = V_106 ;
break;
} ;
return 0 ;
}
static int F_46 ( struct V_140 * V_57 , int V_141 )
{
unsigned char V_142 ;
F_47 ( V_57 , V_143 , & V_142 ) ;
if ( V_141 )
V_142 |= V_144 ;
else
V_142 &= ~ V_144 ;
F_45 ( V_57 , V_143 , V_142 ) ;
F_20 ( & V_57 -> V_41 , L_19 , V_142 ) ;
if ( F_48 ( V_57 , 1 ) ) {
F_47 ( V_57 , V_145 , & V_142 ) ;
if ( V_141 )
V_142 |= V_146 ;
else
V_142 &= ~ V_146 ;
F_45 ( V_57 , V_145 , V_142 ) ;
F_20 ( & V_57 -> V_41 , L_20 , V_142 ) ;
}
F_47 ( V_57 , V_147 , & V_142 ) ;
F_45 ( V_57 , V_147 , V_142 & ~ 0x0f ) ;
F_45 ( V_57 , V_147 , V_142 | 0x01 ) ;
F_20 ( & V_57 -> V_41 , L_21 ) ;
return 0 ;
}
static int F_49 ( struct V_140 * V_41 , T_2 V_148 )
{
struct V_149 * V_150 = F_50 ( V_41 ) ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_150 -> V_151 ; ++ V_96 ) {
if ( ! V_150 -> V_152 [ V_96 ] )
break;
F_51 ( V_150 -> V_152 [ V_96 ] ) ;
}
F_52 ( V_41 ) ;
F_53 ( V_41 , F_54 ( V_41 , V_148 ) , 0 ) ;
F_55 ( V_41 ) ;
F_56 ( V_41 , F_54 ( V_41 , V_148 ) ) ;
return 0 ;
}
static int F_57 ( struct V_140 * V_41 )
{
struct V_149 * V_150 = F_50 ( V_41 ) ;
int V_77 ;
F_56 ( V_41 , V_153 ) ;
F_58 ( V_41 ) ;
V_77 = F_59 ( V_41 ) ;
if ( V_77 )
return V_77 ;
F_60 ( V_41 ) ;
F_46 ( V_41 , 1 ) ;
for ( V_77 = 0 ; V_77 < V_150 -> V_151 ; ++ V_77 ) {
if ( ! V_150 -> V_152 [ V_77 ] )
break;
F_61 ( V_150 -> V_152 [ V_77 ] ) ;
F_32 ( V_150 -> V_152 [ V_77 ] ) ;
}
return 0 ;
}
static int F_62 ( struct V_140 * V_57 )
{
int V_96 , V_77 = 0 ;
for ( V_96 = 0 ; V_96 < V_154 ; ++ V_96 ) {
if ( ! ( V_155 & F_48 ( V_57 , V_96 ) ) )
break;
if ( 256 != F_63 ( V_57 , V_96 ) )
break;
++ V_77 ;
}
return V_77 ;
}
static struct V_36 * F_64 ( struct V_149 * V_150 , int V_96 )
{
struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_37 = F_65 ( sizeof( struct V_1 ) ,
& V_150 -> V_57 -> V_41 ) ;
if ( ! V_37 )
return NULL ;
V_2 = F_19 ( V_37 ) ;
V_2 -> V_56 = V_150 ;
V_2 -> V_9 = F_66 ( F_67 ( V_150 -> V_57 , V_96 ) ,
F_63 ( V_150 -> V_57 , V_96 ) ) ;
if ( ! V_2 -> V_9 )
goto V_156;
F_68 ( & V_2 -> V_82 ) ;
V_2 -> V_114 = V_96 ;
snprintf ( V_2 -> V_157 , sizeof( V_2 -> V_157 ) , V_158 L_22 ,
V_2 -> V_114 ) ;
V_2 -> V_79 = V_150 -> V_57 -> V_79 ;
V_2 -> V_73 = F_69 ( 1000 ) ;
F_70 ( & V_2 -> V_95 , F_36 , ( unsigned long ) V_37 ) ;
V_37 -> V_159 = F_38 ;
V_37 -> V_160 = F_43 ;
V_37 -> V_161 = V_162 | V_163 ;
F_71 ( & V_2 -> V_71 , F_33 , ( unsigned long ) V_37 ) ;
if ( ! F_72 ( V_2 -> V_79 , F_29 , V_164 , V_2 -> V_157 ,
V_37 ) )
return V_37 ;
F_73 ( V_2 -> V_9 ) ;
V_156:
F_74 ( V_37 ) ;
return NULL ;
}
static void F_75 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_19 ( V_37 ) ;
F_76 ( V_2 -> V_79 , V_37 ) ;
F_73 ( V_2 -> V_9 ) ;
F_77 ( V_37 ) ;
}
static int F_78 ( struct V_140 * V_57 ,
const struct V_165 * V_80 )
{
struct V_149 * V_150 ;
int V_166 = 0 ;
int V_77 , V_96 ;
V_77 = F_79 ( V_57 , F_80 ( 32 ) ) ;
if ( V_77 )
return V_77 ;
V_77 = F_59 ( V_57 ) ;
if ( V_77 )
return V_77 ;
F_60 ( V_57 ) ;
V_77 = F_81 ( V_57 , V_158 ) ;
if ( V_77 ) {
V_166 = 1 ;
goto V_167;
}
F_46 ( V_57 , 1 ) ;
V_96 = F_62 ( V_57 ) ;
if ( ! V_96 ) {
V_77 = - V_168 ;
V_166 = 1 ;
goto V_167;
}
V_150 = F_82 ( sizeof( struct V_149 )
+ V_96 * sizeof( struct V_36 * ) , V_169 ) ;
if ( ! V_150 ) {
V_77 = - V_60 ;
goto V_170;
}
V_150 -> V_57 = V_57 ;
V_150 -> V_151 = V_96 ;
F_83 ( V_57 , V_150 ) ;
for ( V_96 = 0 ; V_96 < V_150 -> V_151 ; ++ V_96 ) {
V_150 -> V_152 [ V_96 ] = F_64 ( V_150 , V_96 ) ;
if ( ! V_150 -> V_152 [ V_96 ] )
break;
V_77 = F_84 ( V_150 -> V_152 [ V_96 ] ) ;
if ( V_77 ) {
F_75 ( V_150 -> V_152 [ V_96 ] ) ;
V_150 -> V_152 [ V_96 ] = NULL ;
break;
}
}
if ( V_96 )
return 0 ;
V_77 = - V_168 ;
F_83 ( V_57 , NULL ) ;
F_74 ( V_150 ) ;
V_170:
F_85 ( V_57 ) ;
V_167:
if ( ! V_166 )
F_55 ( V_57 ) ;
return V_77 ;
}
static void F_86 ( struct V_140 * V_41 )
{
struct V_149 * V_150 = F_50 ( V_41 ) ;
struct V_1 * V_2 ;
int V_96 ;
unsigned long V_17 ;
for ( V_96 = 0 ; V_96 < V_150 -> V_151 ; ++ V_96 ) {
if ( ! V_150 -> V_152 [ V_96 ] )
break;
V_2 = F_19 ( V_150 -> V_152 [ V_96 ] ) ;
V_150 -> V_152 [ V_96 ] -> V_159 = F_37 ;
F_87 ( & V_2 -> V_95 ) ;
F_6 ( 0 , V_2 -> V_9 + V_70 ) ;
F_6 ( 0 , V_2 -> V_9 + V_67 ) ;
F_41 () ;
F_20 ( & V_150 -> V_57 -> V_41 , L_23 ) ;
F_34 ( & V_2 -> V_82 , V_17 ) ;
if ( V_2 -> V_18 ) {
V_2 -> V_18 -> error = - V_42 ;
F_25 ( V_150 -> V_152 [ V_96 ] , 1 ) ;
}
F_35 ( & V_2 -> V_82 , V_17 ) ;
F_88 ( V_150 -> V_152 [ V_96 ] ) ;
F_20 ( & V_150 -> V_57 -> V_41 , L_24 ) ;
F_75 ( V_150 -> V_152 [ V_96 ] ) ;
}
F_46 ( V_41 , 0 ) ;
F_83 ( V_41 , NULL ) ;
F_85 ( V_41 ) ;
F_55 ( V_41 ) ;
F_74 ( V_150 ) ;
}
static int T_3 F_89 ( void )
{
return F_90 ( & V_171 ) ;
}
static void T_4 F_91 ( void )
{
F_92 ( & V_171 ) ;
}
