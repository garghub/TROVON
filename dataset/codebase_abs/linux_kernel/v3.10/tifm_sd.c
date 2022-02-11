static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned char * V_10 ;
unsigned int V_11 = 0 , V_12 ;
V_10 = F_2 ( V_4 ) + V_5 ;
if ( V_2 -> V_13 & V_14 ) {
V_10 [ V_11 ++ ] = V_2 -> V_15 [ 0 ] ;
V_2 -> V_13 &= ~ V_14 ;
}
while ( V_11 < V_6 ) {
V_12 = F_3 ( V_8 -> V_16 + V_17 ) ;
V_10 [ V_11 ++ ] = V_12 & 0xff ;
if ( V_11 == V_6 ) {
V_2 -> V_15 [ 0 ] = ( V_12 >> 8 ) & 0xff ;
V_2 -> V_13 |= V_14 ;
break;
}
V_10 [ V_11 ++ ] = ( V_12 >> 8 ) & 0xff ;
}
F_4 ( V_10 - V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned char * V_10 ;
unsigned int V_11 = 0 , V_12 ;
V_10 = F_2 ( V_4 ) + V_5 ;
if ( V_2 -> V_13 & V_14 ) {
V_12 = V_2 -> V_15 [ 0 ] | ( ( V_10 [ V_11 ++ ] << 8 ) & 0xff00 ) ;
F_6 ( V_12 , V_8 -> V_16 + V_17 ) ;
V_2 -> V_13 &= ~ V_14 ;
}
while ( V_11 < V_6 ) {
V_12 = V_10 [ V_11 ++ ] ;
if ( V_11 == V_6 ) {
V_2 -> V_15 [ 0 ] = V_12 & 0xff ;
V_2 -> V_13 |= V_14 ;
break;
}
V_12 |= ( V_10 [ V_11 ++ ] << 8 ) & 0xff00 ;
F_6 ( V_12 , V_8 -> V_16 + V_17 ) ;
}
F_4 ( V_10 - V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 -> V_21 -> V_22 ;
struct V_23 * V_24 = V_19 -> V_24 ;
unsigned int V_5 , V_6 , V_25 = V_26 * 2 ;
unsigned int V_27 , V_28 ;
struct V_3 * V_4 ;
if ( V_2 -> V_29 == V_2 -> V_30 )
return;
while ( V_25 ) {
V_6 = V_24 [ V_2 -> V_29 ] . V_31 - V_2 -> V_32 ;
if ( ! V_6 ) {
V_2 -> V_32 = 0 ;
V_2 -> V_29 ++ ;
if ( V_2 -> V_29 == V_2 -> V_30 ) {
if ( ( V_19 -> V_33 & V_34 )
&& ( V_2 -> V_13 & V_14 ) )
F_6 ( V_2 -> V_15 [ 0 ] ,
V_2 -> V_9 -> V_16
+ V_17 ) ;
return;
}
V_6 = V_24 [ V_2 -> V_29 ] . V_31 ;
}
V_5 = V_24 [ V_2 -> V_29 ] . V_35 + V_2 -> V_32 ;
V_4 = F_8 ( F_9 ( & V_24 [ V_2 -> V_29 ] ) , V_5 >> V_36 ) ;
V_27 = F_10 ( V_5 ) ;
V_28 = V_37 - V_27 ;
V_28 = F_11 ( V_28 , V_6 ) ;
V_28 = F_11 ( V_28 , V_25 ) ;
if ( V_19 -> V_33 & V_38 )
F_1 ( V_2 , V_4 , V_27 , V_28 ) ;
else if ( V_19 -> V_33 & V_34 )
F_5 ( V_2 , V_4 , V_27 , V_28 ) ;
V_25 -= V_28 ;
V_2 -> V_32 += V_28 ;
}
}
static void F_12 ( struct V_3 * V_39 , unsigned int V_40 ,
struct V_3 * V_41 , unsigned int V_42 ,
unsigned int V_43 )
{
unsigned char * V_44 = F_2 ( V_41 ) + V_42 ;
unsigned char * V_45 = F_2 ( V_39 ) + V_40 ;
memcpy ( V_45 , V_44 , V_43 ) ;
F_4 ( V_45 - V_40 ) ;
F_4 ( V_44 - V_42 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
unsigned int V_25 = V_19 -> V_46 ;
unsigned int V_5 , V_6 ;
unsigned int V_27 , V_28 ;
struct V_3 * V_4 ;
F_14 ( & V_2 -> V_9 -> V_9 , L_1 ) ;
while ( V_25 ) {
V_6 = V_24 [ V_2 -> V_29 ] . V_31 - V_2 -> V_32 ;
if ( ! V_6 ) {
V_2 -> V_32 = 0 ;
V_2 -> V_29 ++ ;
if ( V_2 -> V_29 == V_2 -> V_30 )
return;
V_6 = V_24 [ V_2 -> V_29 ] . V_31 ;
}
V_5 = V_24 [ V_2 -> V_29 ] . V_35 + V_2 -> V_32 ;
V_4 = F_8 ( F_9 ( & V_24 [ V_2 -> V_29 ] ) , V_5 >> V_36 ) ;
V_27 = F_10 ( V_5 ) ;
V_28 = V_37 - V_27 ;
V_28 = F_11 ( V_28 , V_6 ) ;
V_28 = F_11 ( V_28 , V_25 ) ;
if ( V_19 -> V_33 & V_34 )
F_12 ( F_9 ( & V_2 -> V_47 ) ,
V_19 -> V_46 - V_25 ,
V_4 , V_27 , V_28 ) ;
else if ( V_19 -> V_33 & V_38 )
F_12 ( V_4 , V_27 , F_9 ( & V_2 -> V_47 ) ,
V_19 -> V_46 - V_25 , V_28 ) ;
V_25 -= V_28 ;
V_2 -> V_32 += V_28 ;
}
}
static int F_15 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_25 = V_48 * V_19 -> V_46 ;
unsigned int V_49 , V_50 , V_51 ;
struct V_23 * V_24 = NULL ;
unsigned long V_33 ;
if ( V_2 -> V_29 == V_2 -> V_30 )
return 1 ;
if ( V_2 -> V_13 & V_14 ) {
V_2 -> V_13 &= ~ V_14 ;
F_16 ( V_33 ) ;
F_13 ( V_2 , V_19 ) ;
F_17 ( V_33 ) ;
if ( V_2 -> V_29 == V_2 -> V_30 )
return 1 ;
}
V_49 = F_18 ( & V_19 -> V_24 [ V_2 -> V_29 ] ) - V_2 -> V_32 ;
if ( ! V_49 ) {
V_2 -> V_32 = 0 ;
V_2 -> V_29 ++ ;
if ( V_2 -> V_29 == V_2 -> V_30 )
return 1 ;
V_49 = F_18 ( & V_19 -> V_24 [ V_2 -> V_29 ] ) ;
}
if ( V_49 < V_25 ) {
V_50 = V_49 / V_19 -> V_46 ;
V_51 = V_2 -> V_32 ;
V_2 -> V_32 += V_50 * V_19 -> V_46 ;
} else {
V_50 = V_48 ;
V_51 = V_2 -> V_32 ;
V_2 -> V_32 += V_25 ;
}
if ( V_50 )
V_24 = & V_19 -> V_24 [ V_2 -> V_29 ] ;
else if ( V_49 ) {
if ( V_19 -> V_33 & V_34 ) {
F_16 ( V_33 ) ;
F_13 ( V_2 , V_19 ) ;
F_17 ( V_33 ) ;
} else
V_2 -> V_13 |= V_14 ;
V_24 = & V_2 -> V_47 ;
V_51 = 0 ;
V_50 = 1 ;
} else
return 1 ;
F_14 ( & V_8 -> V_9 , L_2 , V_50 ) ;
F_6 ( F_19 ( V_24 ) + V_51 , V_8 -> V_16 + V_52 ) ;
if ( V_19 -> V_33 & V_34 )
F_6 ( ( V_50 << 8 ) | V_53 | V_54 ,
V_8 -> V_16 + V_55 ) ;
else
F_6 ( ( V_50 << 8 ) | V_54 ,
V_8 -> V_16 + V_55 ) ;
return 0 ;
}
static unsigned int F_20 ( struct V_56 * V_21 )
{
unsigned int V_57 = 0 ;
switch ( F_21 ( V_21 ) ) {
case V_58 :
V_57 |= V_59 ;
break;
case V_60 :
V_57 |= V_61 ;
case V_62 :
V_57 |= V_63 ;
break;
case V_64 :
V_57 |= V_65 ;
break;
case V_66 :
V_57 |= V_67 ;
break;
default:
F_22 () ;
}
switch ( F_23 ( V_21 ) ) {
case V_68 :
V_57 |= V_69 ;
break;
case V_70 :
V_57 |= V_71 ;
break;
case V_72 :
V_57 |= V_73 ;
break;
case V_74 :
V_57 |= V_75 ;
break;
default:
F_22 () ;
}
return V_57 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_56 * V_21 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_76 = F_20 ( V_21 ) ;
if ( V_2 -> V_77 )
V_76 |= V_78 ;
if ( V_21 -> V_22 && ( V_21 -> V_22 -> V_33 & V_38 ) )
V_76 |= V_79 ;
F_14 ( & V_8 -> V_9 , L_3 ,
V_21 -> V_80 , V_21 -> V_81 , V_76 ) ;
F_6 ( ( V_21 -> V_81 >> 16 ) & 0xffff , V_8 -> V_16 + V_82 ) ;
F_6 ( V_21 -> V_81 & 0xffff , V_8 -> V_16 + V_83 ) ;
F_6 ( V_21 -> V_80 | V_76 , V_8 -> V_16 + V_84 ) ;
}
static void F_25 ( struct V_56 * V_21 , struct V_7 * V_8 )
{
V_21 -> V_85 [ 0 ] = ( F_3 ( V_8 -> V_16 + V_86 + 0x1c ) << 16 )
| F_3 ( V_8 -> V_16 + V_86 + 0x18 ) ;
V_21 -> V_85 [ 1 ] = ( F_3 ( V_8 -> V_16 + V_86 + 0x14 ) << 16 )
| F_3 ( V_8 -> V_16 + V_86 + 0x10 ) ;
V_21 -> V_85 [ 2 ] = ( F_3 ( V_8 -> V_16 + V_86 + 0x0c ) << 16 )
| F_3 ( V_8 -> V_16 + V_86 + 0x08 ) ;
V_21 -> V_85 [ 3 ] = ( F_3 ( V_8 -> V_16 + V_86 + 0x04 ) << 16 )
| F_3 ( V_8 -> V_16 + V_86 + 0x00 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_56 * V_21 = V_2 -> V_20 -> V_21 ;
if ( V_21 -> error )
goto V_87;
if ( ! ( V_2 -> V_13 & V_88 ) )
return;
if ( V_21 -> V_22 ) {
if ( V_21 -> V_22 -> error ) {
if ( ( V_2 -> V_13 & V_89 )
&& ! ( V_2 -> V_13 & V_90 ) )
return;
goto V_87;
}
if ( ! ( V_2 -> V_13 & V_91 ) )
return;
if ( ! ( V_2 -> V_92 || ( V_2 -> V_13 & V_93 ) ) )
return;
if ( V_21 -> V_22 -> V_33 & V_34 ) {
if ( V_2 -> V_20 -> V_94 ) {
if ( ! ( V_2 -> V_13 & V_89 ) ) {
V_2 -> V_13 |= V_89 ;
F_6 ( V_95
| F_3 ( V_8 -> V_16
+ V_96 ) ,
V_8 -> V_16
+ V_96 ) ;
F_24 ( V_2 , V_2 -> V_20 -> V_94 ) ;
return;
} else {
if ( ! ( V_2 -> V_13 & V_90 )
|| ( V_2 -> V_13 & V_97 ) )
return;
F_6 ( ( ~ V_95 )
& F_3 ( V_8 -> V_16
+ V_96 ) ,
V_8 -> V_16
+ V_96 ) ;
}
} else {
if ( V_2 -> V_13 & V_97 )
return;
F_6 ( ( ~ V_95 )
& F_3 ( V_8 -> V_16
+ V_96 ) ,
V_8 -> V_16 + V_96 ) ;
}
} else {
if ( V_2 -> V_20 -> V_94 ) {
if ( ! ( V_2 -> V_13 & V_89 ) ) {
V_2 -> V_13 |= V_89 ;
F_24 ( V_2 , V_2 -> V_20 -> V_94 ) ;
return;
} else {
if ( ! ( V_2 -> V_13 & V_90 ) )
return;
}
}
}
}
V_87:
F_27 ( & V_2 -> V_98 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
unsigned int V_99 = 0 ;
struct V_18 * V_19 = NULL ;
F_29 ( & V_8 -> V_100 ) ;
V_2 = F_30 ( (struct V_101 * ) F_31 ( V_8 ) ) ;
V_99 = F_3 ( V_8 -> V_16 + V_102 ) ;
F_14 ( & V_8 -> V_9 , L_4 ,
V_99 , V_2 -> V_13 ) ;
if ( V_2 -> V_20 ) {
V_19 = V_2 -> V_20 -> V_21 -> V_22 ;
if ( V_19 && ( V_99 & V_103 ) ) {
if ( F_15 ( V_2 , V_19 ) ) {
V_2 -> V_13 |= V_93 ;
F_26 ( V_2 ) ;
}
}
}
F_6 ( V_99 , V_8 -> V_16 + V_102 ) ;
F_32 ( & V_8 -> V_100 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
unsigned int V_104 = 0 ;
int V_105 = 0 ;
struct V_56 * V_21 = NULL ;
unsigned long V_33 ;
F_29 ( & V_8 -> V_100 ) ;
V_2 = F_30 ( (struct V_101 * ) F_31 ( V_8 ) ) ;
V_104 = F_3 ( V_8 -> V_16 + V_106 ) ;
F_14 ( & V_8 -> V_9 , L_5 ,
V_104 , V_2 -> V_13 ) ;
if ( V_2 -> V_20 ) {
V_21 = V_2 -> V_20 -> V_21 ;
if ( V_104 & V_107 ) {
F_6 ( V_104 & V_107 ,
V_8 -> V_16 + V_106 ) ;
if ( V_104 & V_108 )
V_105 = - V_109 ;
else if ( V_104 & V_110 )
V_105 = - V_111 ;
if ( V_21 -> V_22 ) {
if ( V_104 & V_112 )
V_21 -> V_22 -> error = - V_109 ;
else if ( V_104 & V_113 )
V_21 -> V_22 -> error = - V_111 ;
}
F_6 ( V_114 ,
V_8 -> V_16 + V_115 ) ;
F_6 ( V_116 , V_8 -> V_16 + V_55 ) ;
if ( V_2 -> V_20 -> V_94 ) {
if ( V_2 -> V_13 & V_89 ) {
V_2 -> V_20 -> V_94 -> error = V_105 ;
V_2 -> V_13 |= V_90 ;
} else {
V_21 -> error = V_105 ;
V_2 -> V_13 |= V_89 ;
F_24 ( V_2 , V_2 -> V_20 -> V_94 ) ;
goto V_117;
}
} else
V_21 -> error = V_105 ;
} else {
if ( V_104 & ( V_118 | V_119 ) ) {
if ( ! ( V_2 -> V_13 & V_88 ) ) {
V_2 -> V_13 |= V_88 ;
F_25 ( V_21 , V_8 ) ;
} else if ( V_2 -> V_13 & V_89 ) {
V_2 -> V_13 |= V_90 ;
F_25 ( V_2 -> V_20 -> V_94 ,
V_8 ) ;
}
}
if ( V_104 & V_120 )
V_2 -> V_13 |= V_91 ;
}
if ( V_2 -> V_92 && V_21 -> V_22 ) {
if ( V_104 & V_121 )
F_6 ( V_104 & V_121 ,
V_8 -> V_16 + V_106 ) ;
if ( V_104 & ( V_121 | V_122
| V_120 ) ) {
F_16 ( V_33 ) ;
F_7 ( V_2 ) ;
F_17 ( V_33 ) ;
V_104 &= ~ V_121 ;
}
}
if ( V_104 & V_95 )
V_2 -> V_13 &= ~ V_97 ;
else if ( V_104 & V_123 )
V_2 -> V_13 |= V_97 ;
F_26 ( V_2 ) ;
}
V_117:
F_6 ( V_104 , V_8 -> V_16 + V_106 ) ;
F_32 ( & V_8 -> V_100 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_18 * V_22 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_124 = V_22 -> V_125 ;
if ( V_126 )
return;
V_124 += V_22 -> V_127 /
( ( 1000000000UL / V_2 -> V_128 ) * V_2 -> V_129 ) ;
if ( V_124 < 0xffff ) {
F_6 ( V_124 , V_8 -> V_16 + V_130 ) ;
F_6 ( ( ~ V_131 )
& F_3 ( V_8 -> V_16 + V_132 ) ,
V_8 -> V_16 + V_132 ) ;
} else {
V_124 = ( V_124 >> 10 ) + 1 ;
if ( V_124 > 0xffff )
V_124 = 0 ;
F_6 ( V_124 , V_8 -> V_16 + V_130 ) ;
F_6 ( V_131
| F_3 ( V_8 -> V_16 + V_132 ) ,
V_8 -> V_16 + V_132 ) ;
}
}
static void F_35 ( struct V_101 * V_133 , struct V_134 * V_135 )
{
struct V_1 * V_2 = F_30 ( V_133 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_33 ;
struct V_18 * V_19 = V_135 -> V_21 -> V_22 ;
F_36 ( & V_8 -> V_100 , V_33 ) ;
if ( V_2 -> V_136 ) {
V_135 -> V_21 -> error = - V_137 ;
goto V_138;
}
if ( V_2 -> V_20 ) {
F_37 ( L_6 ,
F_38 ( & V_8 -> V_9 ) ) ;
V_135 -> V_21 -> error = - V_109 ;
goto V_138;
}
V_2 -> V_13 = 0 ;
V_2 -> V_32 = 0 ;
V_2 -> V_29 = 0 ;
if ( V_135 -> V_22 && ! F_39 ( V_135 -> V_22 -> V_46 ) )
V_2 -> V_92 = 1 ;
else
V_2 -> V_92 = V_92 ? 1 : 0 ;
if ( V_19 ) {
F_34 ( V_2 , V_19 ) ;
if ( ( V_19 -> V_33 & V_34 ) && ! V_135 -> V_94 )
F_6 ( V_95
| F_3 ( V_8 -> V_16 + V_96 ) ,
V_8 -> V_16 + V_96 ) ;
if ( V_2 -> V_92 ) {
F_6 ( V_139
| F_3 ( V_8 -> V_16 + V_96 ) ,
V_8 -> V_16 + V_96 ) ;
F_6 ( ( ( V_26 - 1 ) << 8 )
| ( V_26 - 1 ) ,
V_8 -> V_16 + V_140 ) ;
V_2 -> V_30 = V_19 -> V_30 ;
} else {
F_40 ( & V_2 -> V_47 , V_2 -> V_15 ,
V_19 -> V_46 ) ;
if( 1 != F_41 ( V_8 , & V_2 -> V_47 , 1 ,
V_19 -> V_33 & V_34
? V_141
: V_142 ) ) {
F_37 ( L_7 ,
F_38 ( & V_8 -> V_9 ) ) ;
V_135 -> V_21 -> error = - V_143 ;
goto V_138;
}
V_2 -> V_30 = F_41 ( V_8 , V_19 -> V_24 ,
V_19 -> V_30 ,
V_19 -> V_33
& V_34
? V_141
: V_142 ) ;
if ( V_2 -> V_30 < 1 ) {
F_37 ( L_7 ,
F_38 ( & V_8 -> V_9 ) ) ;
F_42 ( V_8 , & V_2 -> V_47 , 1 ,
V_19 -> V_33 & V_34
? V_141
: V_142 ) ;
V_135 -> V_21 -> error = - V_143 ;
goto V_138;
}
F_6 ( V_114 ,
V_8 -> V_16 + V_115 ) ;
F_6 ( F_43 ( V_19 -> V_46 ) - 2 ,
V_8 -> V_16 + V_144 ) ;
F_6 ( V_145 ,
V_8 -> V_16 + V_146 ) ;
F_6 ( V_147 ,
V_8 -> V_16 + V_148 ) ;
if ( V_19 -> V_33 & V_34 )
F_6 ( V_149 ,
V_8 -> V_16 + V_140 ) ;
else
F_6 ( V_150 ,
V_8 -> V_16 + V_140 ) ;
F_15 ( V_2 , V_19 ) ;
}
F_6 ( V_19 -> V_151 - 1 ,
V_8 -> V_16 + V_152 ) ;
F_6 ( V_19 -> V_46 - 1 ,
V_8 -> V_16 + V_153 ) ;
}
V_2 -> V_20 = V_135 ;
F_44 ( & V_2 -> V_154 , V_155 + V_2 -> V_156 ) ;
F_6 ( V_157 | F_3 ( V_8 -> V_16 + V_158 ) ,
V_8 -> V_16 + V_158 ) ;
F_24 ( V_2 , V_135 -> V_21 ) ;
F_45 ( & V_8 -> V_100 , V_33 ) ;
return;
V_138:
F_45 ( & V_8 -> V_100 , V_33 ) ;
F_46 ( V_133 , V_135 ) ;
}
static void F_47 ( unsigned long V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_101 * V_133 = F_31 ( V_8 ) ;
struct V_134 * V_135 ;
struct V_18 * V_19 = NULL ;
unsigned long V_33 ;
F_36 ( & V_8 -> V_100 , V_33 ) ;
F_48 ( & V_2 -> V_154 ) ;
V_135 = V_2 -> V_20 ;
V_2 -> V_20 = NULL ;
if ( ! V_135 ) {
F_37 ( L_8 ,
F_38 ( & V_8 -> V_9 ) ) ;
F_45 ( & V_8 -> V_100 , V_33 ) ;
return;
}
V_19 = V_135 -> V_21 -> V_22 ;
if ( V_19 ) {
if ( V_2 -> V_92 ) {
F_6 ( ( ~ V_139 )
& F_3 ( V_8 -> V_16 + V_96 ) ,
V_8 -> V_16 + V_96 ) ;
} else {
F_42 ( V_8 , & V_2 -> V_47 , 1 ,
( V_19 -> V_33 & V_34 )
? V_141 : V_142 ) ;
F_42 ( V_8 , V_19 -> V_24 , V_19 -> V_30 ,
( V_19 -> V_33 & V_34 )
? V_141 : V_142 ) ;
}
V_19 -> V_159 = V_19 -> V_151
- F_3 ( V_8 -> V_16 + V_152 ) - 1 ;
V_19 -> V_159 *= V_19 -> V_46 ;
V_19 -> V_159 += V_19 -> V_46
- F_3 ( V_8 -> V_16 + V_153 ) + 1 ;
}
F_6 ( ( ~ V_157 ) & F_3 ( V_8 -> V_16 + V_158 ) ,
V_8 -> V_16 + V_158 ) ;
F_45 ( & V_8 -> V_100 , V_33 ) ;
F_46 ( V_133 , V_135 ) ;
}
static void F_49 ( unsigned long V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_37 ( L_9
L_10 ,
F_38 ( & V_2 -> V_9 -> V_9 ) , V_2 -> V_20 -> V_21 -> V_80 , V_2 -> V_13 ) ;
F_50 ( V_2 -> V_9 ) ;
}
static void F_51 ( struct V_101 * V_133 , struct V_160 * V_161 )
{
struct V_1 * V_2 = F_30 ( V_133 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_162 , V_163 ;
unsigned long V_33 ;
F_36 ( & V_8 -> V_100 , V_33 ) ;
F_14 ( & V_8 -> V_9 , L_11
L_12 ,
V_161 -> clock , V_161 -> V_164 , V_161 -> V_165 , V_161 -> V_166 ,
V_161 -> V_167 , V_161 -> V_168 ) ;
if ( V_161 -> V_168 == V_169 ) {
F_6 ( V_170 | F_3 ( V_8 -> V_16 + V_171 ) ,
V_8 -> V_16 + V_171 ) ;
} else {
F_6 ( ( ~ V_170 )
& F_3 ( V_8 -> V_16 + V_171 ) ,
V_8 -> V_16 + V_171 ) ;
}
if ( V_161 -> clock ) {
V_162 = 20000000 / V_161 -> clock ;
if ( ! V_162 )
V_162 = 1 ;
V_163 = 24000000 / V_161 -> clock ;
if ( ! V_163 )
V_163 = 1 ;
if ( ( 20000000 / V_162 ) > V_161 -> clock )
V_162 ++ ;
if ( ( 24000000 / V_163 ) > V_161 -> clock )
V_163 ++ ;
if ( ( 20000000 / V_162 ) > ( 24000000 / V_163 ) ) {
V_2 -> V_128 = 20000000 ;
V_2 -> V_129 = V_162 ;
F_6 ( ( ~ V_172 )
& F_3 ( V_8 -> V_16 + V_158 ) ,
V_8 -> V_16 + V_158 ) ;
} else {
V_2 -> V_128 = 24000000 ;
V_2 -> V_129 = V_163 ;
F_6 ( V_172
| F_3 ( V_8 -> V_16 + V_158 ) ,
V_8 -> V_16 + V_158 ) ;
}
} else {
V_2 -> V_129 = 0 ;
}
V_2 -> V_129 &= V_173 ;
F_6 ( V_2 -> V_129
| ( ( ~ V_173 )
& F_3 ( V_8 -> V_16 + V_171 ) ) ,
V_8 -> V_16 + V_171 ) ;
V_2 -> V_77 = ( V_161 -> V_165 == V_174 ) ;
F_45 ( & V_8 -> V_100 , V_33 ) ;
}
static int F_52 ( struct V_101 * V_133 )
{
int V_57 = 0 ;
struct V_1 * V_2 = F_30 ( V_133 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_33 ;
F_36 ( & V_8 -> V_100 , V_33 ) ;
if ( V_175 & F_3 ( V_8 -> V_16 + V_176 ) )
V_57 = 1 ;
F_45 ( & V_8 -> V_100 , V_33 ) ;
return V_57 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_57 ;
unsigned int V_104 = 0 ;
struct V_7 * V_8 = V_2 -> V_9 ;
F_6 ( 0 , V_8 -> V_16 + V_96 ) ;
F_54 () ;
V_2 -> V_129 = 61 ;
V_2 -> V_128 = 20000000 ;
F_6 ( V_177 , V_8 -> V_16 + V_178 ) ;
F_6 ( V_2 -> V_129 | V_179 ,
V_8 -> V_16 + V_171 ) ;
for ( V_57 = 32 ; V_57 <= 256 ; V_57 <<= 1 ) {
if ( 1 & F_3 ( V_8 -> V_16 + V_180 ) ) {
V_57 = 0 ;
break;
}
F_55 ( V_57 ) ;
}
if ( V_57 ) {
F_37 ( L_13 ,
F_38 ( & V_8 -> V_9 ) ) ;
return - V_181 ;
}
F_6 ( 0 , V_8 -> V_16 + V_152 ) ;
F_6 ( V_2 -> V_129 | V_179 ,
V_8 -> V_16 + V_171 ) ;
F_6 ( V_150 , V_8 -> V_16 + V_140 ) ;
F_6 ( 64 , V_8 -> V_16 + V_182 ) ;
F_6 ( V_183 , V_8 -> V_16 + V_84 ) ;
for ( V_57 = 16 ; V_57 <= 64 ; V_57 <<= 1 ) {
V_104 = F_3 ( V_8 -> V_16 + V_106 ) ;
F_6 ( V_104 , V_8 -> V_16 + V_106 ) ;
if ( ! ( V_104 & V_107 )
&& ( V_104 & V_118 ) ) {
V_57 = 0 ;
break;
}
F_55 ( V_57 ) ;
}
if ( V_57 ) {
F_37 ( L_14 ,
F_38 ( & V_8 -> V_9 ) ) ;
return - V_181 ;
}
F_6 ( V_119 | V_120 | V_118
| V_107 ,
V_8 -> V_16 + V_96 ) ;
F_54 () ;
return 0 ;
}
static int F_56 ( struct V_7 * V_8 )
{
struct V_101 * V_133 ;
struct V_1 * V_2 ;
int V_57 = - V_184 ;
if ( ! ( V_185
& F_3 ( V_8 -> V_16 + V_176 ) ) ) {
F_57 ( L_15 ,
F_38 ( & V_8 -> V_9 ) ) ;
return V_57 ;
}
V_133 = F_58 ( sizeof( struct V_1 ) , & V_8 -> V_9 ) ;
if ( ! V_133 )
return - V_143 ;
V_2 = F_30 ( V_133 ) ;
F_59 ( V_8 , V_133 ) ;
V_2 -> V_9 = V_8 ;
V_2 -> V_156 = F_60 ( 1000 ) ;
F_61 ( & V_2 -> V_98 , F_47 ,
( unsigned long ) V_2 ) ;
F_62 ( & V_2 -> V_154 , F_49 , ( unsigned long ) V_2 ) ;
V_133 -> V_186 = & V_187 ;
V_133 -> V_188 = V_189 | V_190 ;
V_133 -> V_191 = V_192 ;
V_133 -> V_193 = 20000000 / 60 ;
V_133 -> V_194 = 24000000 ;
V_133 -> V_195 = 2048 ;
V_133 -> V_196 = V_133 -> V_195 ;
V_133 -> V_197 = F_11 ( V_198 , V_37 ) ;
V_133 -> V_199 = V_133 -> V_195 * V_133 -> V_197 ;
V_133 -> V_200 = V_133 -> V_199 ;
V_8 -> V_201 = F_33 ;
V_8 -> V_202 = F_28 ;
V_57 = F_53 ( V_2 ) ;
if ( ! V_57 )
V_57 = F_63 ( V_133 ) ;
if ( ! V_57 )
return 0 ;
F_64 ( V_133 ) ;
return V_57 ;
}
static void F_65 ( struct V_7 * V_8 )
{
struct V_101 * V_133 = F_31 ( V_8 ) ;
struct V_1 * V_2 = F_30 ( V_133 ) ;
unsigned long V_33 ;
F_36 ( & V_8 -> V_100 , V_33 ) ;
V_2 -> V_136 = 1 ;
F_6 ( 0 , V_8 -> V_16 + V_96 ) ;
F_54 () ;
F_45 ( & V_8 -> V_100 , V_33 ) ;
F_66 ( & V_2 -> V_98 ) ;
F_36 ( & V_8 -> V_100 , V_33 ) ;
if ( V_2 -> V_20 ) {
F_6 ( V_114 ,
V_8 -> V_16 + V_115 ) ;
F_6 ( 0 , V_8 -> V_16 + V_148 ) ;
V_2 -> V_20 -> V_21 -> error = - V_137 ;
if ( V_2 -> V_20 -> V_94 )
V_2 -> V_20 -> V_94 -> error = - V_137 ;
F_27 ( & V_2 -> V_98 ) ;
}
F_45 ( & V_8 -> V_100 , V_33 ) ;
F_67 ( V_133 ) ;
F_14 ( & V_8 -> V_9 , L_16 ) ;
F_64 ( V_133 ) ;
}
static int F_68 ( struct V_7 * V_8 , T_1 V_203 )
{
return F_69 ( F_31 ( V_8 ) ) ;
}
static int F_70 ( struct V_7 * V_8 )
{
struct V_101 * V_133 = F_31 ( V_8 ) ;
struct V_1 * V_2 = F_30 ( V_133 ) ;
int V_57 ;
V_57 = F_53 ( V_2 ) ;
F_14 ( & V_8 -> V_9 , L_17 , V_57 ) ;
if ( V_57 )
V_2 -> V_136 = 1 ;
else
V_57 = F_71 ( V_133 ) ;
return V_57 ;
}
static int T_2 F_72 ( void )
{
return F_73 ( & V_204 ) ;
}
static void T_3 F_74 ( void )
{
F_75 ( & V_204 ) ;
}
