static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned char * V_10 ;
unsigned int V_11 = 0 , V_12 ;
V_10 = F_2 ( V_4 , V_13 ) + V_5 ;
if ( V_2 -> V_14 & V_15 ) {
V_10 [ V_11 ++ ] = V_2 -> V_16 [ 0 ] ;
V_2 -> V_14 &= ~ V_15 ;
}
while ( V_11 < V_6 ) {
V_12 = F_3 ( V_8 -> V_17 + V_18 ) ;
V_10 [ V_11 ++ ] = V_12 & 0xff ;
if ( V_11 == V_6 ) {
V_2 -> V_16 [ 0 ] = ( V_12 >> 8 ) & 0xff ;
V_2 -> V_14 |= V_15 ;
break;
}
V_10 [ V_11 ++ ] = ( V_12 >> 8 ) & 0xff ;
}
F_4 ( V_10 - V_5 , V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned char * V_10 ;
unsigned int V_11 = 0 , V_12 ;
V_10 = F_2 ( V_4 , V_19 ) + V_5 ;
if ( V_2 -> V_14 & V_15 ) {
V_12 = V_2 -> V_16 [ 0 ] | ( ( V_10 [ V_11 ++ ] << 8 ) & 0xff00 ) ;
F_6 ( V_12 , V_8 -> V_17 + V_18 ) ;
V_2 -> V_14 &= ~ V_15 ;
}
while ( V_11 < V_6 ) {
V_12 = V_10 [ V_11 ++ ] ;
if ( V_11 == V_6 ) {
V_2 -> V_16 [ 0 ] = V_12 & 0xff ;
V_2 -> V_14 |= V_15 ;
break;
}
V_12 |= ( V_10 [ V_11 ++ ] << 8 ) & 0xff00 ;
F_6 ( V_12 , V_8 -> V_17 + V_18 ) ;
}
F_4 ( V_10 - V_5 , V_19 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_22 -> V_23 -> V_24 ;
struct V_25 * V_26 = V_21 -> V_26 ;
unsigned int V_5 , V_6 , V_27 = V_28 * 2 ;
unsigned int V_29 , V_30 ;
struct V_3 * V_4 ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return;
while ( V_27 ) {
V_6 = V_26 [ V_2 -> V_31 ] . V_33 - V_2 -> V_34 ;
if ( ! V_6 ) {
V_2 -> V_34 = 0 ;
V_2 -> V_31 ++ ;
if ( V_2 -> V_31 == V_2 -> V_32 ) {
if ( ( V_21 -> V_35 & V_36 )
&& ( V_2 -> V_14 & V_15 ) )
F_6 ( V_2 -> V_16 [ 0 ] ,
V_2 -> V_9 -> V_17
+ V_18 ) ;
return;
}
V_6 = V_26 [ V_2 -> V_31 ] . V_33 ;
}
V_5 = V_26 [ V_2 -> V_31 ] . V_37 + V_2 -> V_34 ;
V_4 = F_8 ( F_9 ( & V_26 [ V_2 -> V_31 ] ) , V_5 >> V_38 ) ;
V_29 = F_10 ( V_5 ) ;
V_30 = V_39 - V_29 ;
V_30 = F_11 ( V_30 , V_6 ) ;
V_30 = F_11 ( V_30 , V_27 ) ;
if ( V_21 -> V_35 & V_40 )
F_1 ( V_2 , V_4 , V_29 , V_30 ) ;
else if ( V_21 -> V_35 & V_36 )
F_5 ( V_2 , V_4 , V_29 , V_30 ) ;
V_27 -= V_30 ;
V_2 -> V_34 += V_30 ;
}
}
static void F_12 ( struct V_3 * V_41 , unsigned int V_42 ,
struct V_3 * V_43 , unsigned int V_44 ,
unsigned int V_45 )
{
unsigned char * V_46 = F_2 ( V_43 , V_19 ) + V_44 ;
unsigned char * V_47 = F_2 ( V_41 , V_13 ) + V_42 ;
memcpy ( V_47 , V_46 , V_45 ) ;
F_4 ( V_47 - V_42 , V_13 ) ;
F_4 ( V_46 - V_44 , V_19 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_26 ;
unsigned int V_27 = V_21 -> V_48 ;
unsigned int V_5 , V_6 ;
unsigned int V_29 , V_30 ;
struct V_3 * V_4 ;
F_14 ( & V_2 -> V_9 -> V_9 , L_1 ) ;
while ( V_27 ) {
V_6 = V_26 [ V_2 -> V_31 ] . V_33 - V_2 -> V_34 ;
if ( ! V_6 ) {
V_2 -> V_34 = 0 ;
V_2 -> V_31 ++ ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return;
V_6 = V_26 [ V_2 -> V_31 ] . V_33 ;
}
V_5 = V_26 [ V_2 -> V_31 ] . V_37 + V_2 -> V_34 ;
V_4 = F_8 ( F_9 ( & V_26 [ V_2 -> V_31 ] ) , V_5 >> V_38 ) ;
V_29 = F_10 ( V_5 ) ;
V_30 = V_39 - V_29 ;
V_30 = F_11 ( V_30 , V_6 ) ;
V_30 = F_11 ( V_30 , V_27 ) ;
if ( V_21 -> V_35 & V_36 )
F_12 ( F_9 ( & V_2 -> V_49 ) ,
V_21 -> V_48 - V_27 ,
V_4 , V_29 , V_30 ) ;
else if ( V_21 -> V_35 & V_40 )
F_12 ( V_4 , V_29 , F_9 ( & V_2 -> V_49 ) ,
V_21 -> V_48 - V_27 , V_30 ) ;
V_27 -= V_30 ;
V_2 -> V_34 += V_30 ;
}
}
static int F_15 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_27 = V_50 * V_21 -> V_48 ;
unsigned int V_51 , V_52 , V_53 ;
struct V_25 * V_26 = NULL ;
unsigned long V_35 ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return 1 ;
if ( V_2 -> V_14 & V_15 ) {
V_2 -> V_14 &= ~ V_15 ;
F_16 ( V_35 ) ;
F_13 ( V_2 , V_21 ) ;
F_17 ( V_35 ) ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return 1 ;
}
V_51 = F_18 ( & V_21 -> V_26 [ V_2 -> V_31 ] ) - V_2 -> V_34 ;
if ( ! V_51 ) {
V_2 -> V_34 = 0 ;
V_2 -> V_31 ++ ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return 1 ;
V_51 = F_18 ( & V_21 -> V_26 [ V_2 -> V_31 ] ) ;
}
if ( V_51 < V_27 ) {
V_52 = V_51 / V_21 -> V_48 ;
V_53 = V_2 -> V_34 ;
V_2 -> V_34 += V_52 * V_21 -> V_48 ;
} else {
V_52 = V_50 ;
V_53 = V_2 -> V_34 ;
V_2 -> V_34 += V_27 ;
}
if ( V_52 )
V_26 = & V_21 -> V_26 [ V_2 -> V_31 ] ;
else if ( V_51 ) {
if ( V_21 -> V_35 & V_36 ) {
F_16 ( V_35 ) ;
F_13 ( V_2 , V_21 ) ;
F_17 ( V_35 ) ;
} else
V_2 -> V_14 |= V_15 ;
V_26 = & V_2 -> V_49 ;
V_53 = 0 ;
V_52 = 1 ;
} else
return 1 ;
F_14 ( & V_8 -> V_9 , L_2 , V_52 ) ;
F_6 ( F_19 ( V_26 ) + V_53 , V_8 -> V_17 + V_54 ) ;
if ( V_21 -> V_35 & V_36 )
F_6 ( ( V_52 << 8 ) | V_55 | V_56 ,
V_8 -> V_17 + V_57 ) ;
else
F_6 ( ( V_52 << 8 ) | V_56 ,
V_8 -> V_17 + V_57 ) ;
return 0 ;
}
static unsigned int F_20 ( struct V_58 * V_23 )
{
unsigned int V_59 = 0 ;
switch ( F_21 ( V_23 ) ) {
case V_60 :
V_59 |= V_61 ;
break;
case V_62 :
V_59 |= V_63 ;
case V_64 :
V_59 |= V_65 ;
break;
case V_66 :
V_59 |= V_67 ;
break;
case V_68 :
V_59 |= V_69 ;
break;
default:
F_22 () ;
}
switch ( F_23 ( V_23 ) ) {
case V_70 :
V_59 |= V_71 ;
break;
case V_72 :
V_59 |= V_73 ;
break;
case V_74 :
V_59 |= V_75 ;
break;
case V_76 :
V_59 |= V_77 ;
break;
default:
F_22 () ;
}
return V_59 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_58 * V_23 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_78 = F_20 ( V_23 ) ;
if ( V_2 -> V_79 )
V_78 |= V_80 ;
if ( V_23 -> V_24 && ( V_23 -> V_24 -> V_35 & V_40 ) )
V_78 |= V_81 ;
F_14 ( & V_8 -> V_9 , L_3 ,
V_23 -> V_82 , V_23 -> V_83 , V_78 ) ;
F_6 ( ( V_23 -> V_83 >> 16 ) & 0xffff , V_8 -> V_17 + V_84 ) ;
F_6 ( V_23 -> V_83 & 0xffff , V_8 -> V_17 + V_85 ) ;
F_6 ( V_23 -> V_82 | V_78 , V_8 -> V_17 + V_86 ) ;
}
static void F_25 ( struct V_58 * V_23 , struct V_7 * V_8 )
{
V_23 -> V_87 [ 0 ] = ( F_3 ( V_8 -> V_17 + V_88 + 0x1c ) << 16 )
| F_3 ( V_8 -> V_17 + V_88 + 0x18 ) ;
V_23 -> V_87 [ 1 ] = ( F_3 ( V_8 -> V_17 + V_88 + 0x14 ) << 16 )
| F_3 ( V_8 -> V_17 + V_88 + 0x10 ) ;
V_23 -> V_87 [ 2 ] = ( F_3 ( V_8 -> V_17 + V_88 + 0x0c ) << 16 )
| F_3 ( V_8 -> V_17 + V_88 + 0x08 ) ;
V_23 -> V_87 [ 3 ] = ( F_3 ( V_8 -> V_17 + V_88 + 0x04 ) << 16 )
| F_3 ( V_8 -> V_17 + V_88 + 0x00 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_58 * V_23 = V_2 -> V_22 -> V_23 ;
if ( V_23 -> error )
goto V_89;
if ( ! ( V_2 -> V_14 & V_90 ) )
return;
if ( V_23 -> V_24 ) {
if ( V_23 -> V_24 -> error ) {
if ( ( V_2 -> V_14 & V_91 )
&& ! ( V_2 -> V_14 & V_92 ) )
return;
goto V_89;
}
if ( ! ( V_2 -> V_14 & V_93 ) )
return;
if ( ! ( V_2 -> V_94 || ( V_2 -> V_14 & V_95 ) ) )
return;
if ( V_23 -> V_24 -> V_35 & V_36 ) {
if ( V_2 -> V_22 -> V_96 ) {
if ( ! ( V_2 -> V_14 & V_91 ) ) {
V_2 -> V_14 |= V_91 ;
F_6 ( V_97
| F_3 ( V_8 -> V_17
+ V_98 ) ,
V_8 -> V_17
+ V_98 ) ;
F_24 ( V_2 , V_2 -> V_22 -> V_96 ) ;
return;
} else {
if ( ! ( V_2 -> V_14 & V_92 )
|| ( V_2 -> V_14 & V_99 ) )
return;
F_6 ( ( ~ V_97 )
& F_3 ( V_8 -> V_17
+ V_98 ) ,
V_8 -> V_17
+ V_98 ) ;
}
} else {
if ( V_2 -> V_14 & V_99 )
return;
F_6 ( ( ~ V_97 )
& F_3 ( V_8 -> V_17
+ V_98 ) ,
V_8 -> V_17 + V_98 ) ;
}
} else {
if ( V_2 -> V_22 -> V_96 ) {
if ( ! ( V_2 -> V_14 & V_91 ) ) {
V_2 -> V_14 |= V_91 ;
F_24 ( V_2 , V_2 -> V_22 -> V_96 ) ;
return;
} else {
if ( ! ( V_2 -> V_14 & V_92 ) )
return;
}
}
}
}
V_89:
F_27 ( & V_2 -> V_100 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
unsigned int V_101 = 0 ;
struct V_20 * V_21 = NULL ;
F_29 ( & V_8 -> V_102 ) ;
V_2 = F_30 ( (struct V_103 * ) F_31 ( V_8 ) ) ;
V_101 = F_3 ( V_8 -> V_17 + V_104 ) ;
F_14 ( & V_8 -> V_9 , L_4 ,
V_101 , V_2 -> V_14 ) ;
if ( V_2 -> V_22 ) {
V_21 = V_2 -> V_22 -> V_23 -> V_24 ;
if ( V_21 && ( V_101 & V_105 ) ) {
if ( F_15 ( V_2 , V_21 ) ) {
V_2 -> V_14 |= V_95 ;
F_26 ( V_2 ) ;
}
}
}
F_6 ( V_101 , V_8 -> V_17 + V_104 ) ;
F_32 ( & V_8 -> V_102 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
unsigned int V_106 = 0 ;
int V_107 = 0 ;
struct V_58 * V_23 = NULL ;
unsigned long V_35 ;
F_29 ( & V_8 -> V_102 ) ;
V_2 = F_30 ( (struct V_103 * ) F_31 ( V_8 ) ) ;
V_106 = F_3 ( V_8 -> V_17 + V_108 ) ;
F_14 ( & V_8 -> V_9 , L_5 ,
V_106 , V_2 -> V_14 ) ;
if ( V_2 -> V_22 ) {
V_23 = V_2 -> V_22 -> V_23 ;
if ( V_106 & V_109 ) {
F_6 ( V_106 & V_109 ,
V_8 -> V_17 + V_108 ) ;
if ( V_106 & V_110 )
V_107 = - V_111 ;
else if ( V_106 & V_112 )
V_107 = - V_113 ;
if ( V_23 -> V_24 ) {
if ( V_106 & V_114 )
V_23 -> V_24 -> error = - V_111 ;
else if ( V_106 & V_115 )
V_23 -> V_24 -> error = - V_113 ;
}
F_6 ( V_116 ,
V_8 -> V_17 + V_117 ) ;
F_6 ( V_118 , V_8 -> V_17 + V_57 ) ;
if ( V_2 -> V_22 -> V_96 ) {
if ( V_2 -> V_14 & V_91 ) {
V_2 -> V_22 -> V_96 -> error = V_107 ;
V_2 -> V_14 |= V_92 ;
} else {
V_23 -> error = V_107 ;
V_2 -> V_14 |= V_91 ;
F_24 ( V_2 , V_2 -> V_22 -> V_96 ) ;
goto V_119;
}
} else
V_23 -> error = V_107 ;
} else {
if ( V_106 & ( V_120 | V_121 ) ) {
if ( ! ( V_2 -> V_14 & V_90 ) ) {
V_2 -> V_14 |= V_90 ;
F_25 ( V_23 , V_8 ) ;
} else if ( V_2 -> V_14 & V_91 ) {
V_2 -> V_14 |= V_92 ;
F_25 ( V_2 -> V_22 -> V_96 ,
V_8 ) ;
}
}
if ( V_106 & V_122 )
V_2 -> V_14 |= V_93 ;
}
if ( V_2 -> V_94 && V_23 -> V_24 ) {
if ( V_106 & V_123 )
F_6 ( V_106 & V_123 ,
V_8 -> V_17 + V_108 ) ;
if ( V_106 & ( V_123 | V_124
| V_122 ) ) {
F_16 ( V_35 ) ;
F_7 ( V_2 ) ;
F_17 ( V_35 ) ;
V_106 &= ~ V_123 ;
}
}
if ( V_106 & V_97 )
V_2 -> V_14 &= ~ V_99 ;
else if ( V_106 & V_125 )
V_2 -> V_14 |= V_99 ;
F_26 ( V_2 ) ;
}
V_119:
F_6 ( V_106 , V_8 -> V_17 + V_108 ) ;
F_32 ( & V_8 -> V_102 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_20 * V_24 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_126 = V_24 -> V_127 ;
if ( V_128 )
return;
V_126 += V_24 -> V_129 /
( ( 1000000000UL / V_2 -> V_130 ) * V_2 -> V_131 ) ;
if ( V_126 < 0xffff ) {
F_6 ( V_126 , V_8 -> V_17 + V_132 ) ;
F_6 ( ( ~ V_133 )
& F_3 ( V_8 -> V_17 + V_134 ) ,
V_8 -> V_17 + V_134 ) ;
} else {
V_126 = ( V_126 >> 10 ) + 1 ;
if ( V_126 > 0xffff )
V_126 = 0 ;
F_6 ( V_126 , V_8 -> V_17 + V_132 ) ;
F_6 ( V_133
| F_3 ( V_8 -> V_17 + V_134 ) ,
V_8 -> V_17 + V_134 ) ;
}
}
static void F_35 ( struct V_103 * V_135 , struct V_136 * V_137 )
{
struct V_1 * V_2 = F_30 ( V_135 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_35 ;
struct V_20 * V_21 = V_137 -> V_23 -> V_24 ;
F_36 ( & V_8 -> V_102 , V_35 ) ;
if ( V_2 -> V_138 ) {
V_137 -> V_23 -> error = - V_139 ;
goto V_140;
}
if ( V_2 -> V_22 ) {
F_37 ( V_141 L_6 ,
F_38 ( & V_8 -> V_9 ) ) ;
V_137 -> V_23 -> error = - V_111 ;
goto V_140;
}
V_2 -> V_14 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_31 = 0 ;
if ( V_137 -> V_24 && ! F_39 ( V_137 -> V_24 -> V_48 ) )
V_2 -> V_94 = 1 ;
else
V_2 -> V_94 = V_94 ? 1 : 0 ;
if ( V_21 ) {
F_34 ( V_2 , V_21 ) ;
if ( ( V_21 -> V_35 & V_36 ) && ! V_137 -> V_96 )
F_6 ( V_97
| F_3 ( V_8 -> V_17 + V_98 ) ,
V_8 -> V_17 + V_98 ) ;
if ( V_2 -> V_94 ) {
F_6 ( V_142
| F_3 ( V_8 -> V_17 + V_98 ) ,
V_8 -> V_17 + V_98 ) ;
F_6 ( ( ( V_28 - 1 ) << 8 )
| ( V_28 - 1 ) ,
V_8 -> V_17 + V_143 ) ;
V_2 -> V_32 = V_21 -> V_32 ;
} else {
F_40 ( & V_2 -> V_49 , V_2 -> V_16 ,
V_21 -> V_48 ) ;
if( 1 != F_41 ( V_8 , & V_2 -> V_49 , 1 ,
V_21 -> V_35 & V_36
? V_144
: V_145 ) ) {
F_37 ( V_141 L_7 ,
F_38 ( & V_8 -> V_9 ) ) ;
V_137 -> V_23 -> error = - V_146 ;
goto V_140;
}
V_2 -> V_32 = F_41 ( V_8 , V_21 -> V_26 ,
V_21 -> V_32 ,
V_21 -> V_35
& V_36
? V_144
: V_145 ) ;
if ( V_2 -> V_32 < 1 ) {
F_37 ( V_141 L_7 ,
F_38 ( & V_8 -> V_9 ) ) ;
F_42 ( V_8 , & V_2 -> V_49 , 1 ,
V_21 -> V_35 & V_36
? V_144
: V_145 ) ;
V_137 -> V_23 -> error = - V_146 ;
goto V_140;
}
F_6 ( V_116 ,
V_8 -> V_17 + V_117 ) ;
F_6 ( F_43 ( V_21 -> V_48 ) - 2 ,
V_8 -> V_17 + V_147 ) ;
F_6 ( V_148 ,
V_8 -> V_17 + V_149 ) ;
F_6 ( V_150 ,
V_8 -> V_17 + V_151 ) ;
if ( V_21 -> V_35 & V_36 )
F_6 ( V_152 ,
V_8 -> V_17 + V_143 ) ;
else
F_6 ( V_153 ,
V_8 -> V_17 + V_143 ) ;
F_15 ( V_2 , V_21 ) ;
}
F_6 ( V_21 -> V_154 - 1 ,
V_8 -> V_17 + V_155 ) ;
F_6 ( V_21 -> V_48 - 1 ,
V_8 -> V_17 + V_156 ) ;
}
V_2 -> V_22 = V_137 ;
F_44 ( & V_2 -> V_157 , V_158 + V_2 -> V_159 ) ;
F_6 ( V_160 | F_3 ( V_8 -> V_17 + V_161 ) ,
V_8 -> V_17 + V_161 ) ;
F_24 ( V_2 , V_137 -> V_23 ) ;
F_45 ( & V_8 -> V_102 , V_35 ) ;
return;
V_140:
F_45 ( & V_8 -> V_102 , V_35 ) ;
F_46 ( V_135 , V_137 ) ;
}
static void F_47 ( unsigned long V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_103 * V_135 = F_31 ( V_8 ) ;
struct V_136 * V_137 ;
struct V_20 * V_21 = NULL ;
unsigned long V_35 ;
F_36 ( & V_8 -> V_102 , V_35 ) ;
F_48 ( & V_2 -> V_157 ) ;
V_137 = V_2 -> V_22 ;
V_2 -> V_22 = NULL ;
if ( ! V_137 ) {
F_37 ( V_141 L_8 ,
F_38 ( & V_8 -> V_9 ) ) ;
F_45 ( & V_8 -> V_102 , V_35 ) ;
return;
}
V_21 = V_137 -> V_23 -> V_24 ;
if ( V_21 ) {
if ( V_2 -> V_94 ) {
F_6 ( ( ~ V_142 )
& F_3 ( V_8 -> V_17 + V_98 ) ,
V_8 -> V_17 + V_98 ) ;
} else {
F_42 ( V_8 , & V_2 -> V_49 , 1 ,
( V_21 -> V_35 & V_36 )
? V_144 : V_145 ) ;
F_42 ( V_8 , V_21 -> V_26 , V_21 -> V_32 ,
( V_21 -> V_35 & V_36 )
? V_144 : V_145 ) ;
}
V_21 -> V_162 = V_21 -> V_154
- F_3 ( V_8 -> V_17 + V_155 ) - 1 ;
V_21 -> V_162 *= V_21 -> V_48 ;
V_21 -> V_162 += V_21 -> V_48
- F_3 ( V_8 -> V_17 + V_156 ) + 1 ;
}
F_6 ( ( ~ V_160 ) & F_3 ( V_8 -> V_17 + V_161 ) ,
V_8 -> V_17 + V_161 ) ;
F_45 ( & V_8 -> V_102 , V_35 ) ;
F_46 ( V_135 , V_137 ) ;
}
static void F_49 ( unsigned long V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
F_37 ( V_141
L_9
L_10 ,
F_38 ( & V_2 -> V_9 -> V_9 ) , V_2 -> V_22 -> V_23 -> V_82 , V_2 -> V_14 ) ;
F_50 ( V_2 -> V_9 ) ;
}
static void F_51 ( struct V_103 * V_135 , struct V_163 * V_164 )
{
struct V_1 * V_2 = F_30 ( V_135 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_165 , V_166 ;
unsigned long V_35 ;
F_36 ( & V_8 -> V_102 , V_35 ) ;
F_14 ( & V_8 -> V_9 , L_11
L_12 ,
V_164 -> clock , V_164 -> V_167 , V_164 -> V_168 , V_164 -> V_169 ,
V_164 -> V_170 , V_164 -> V_171 ) ;
if ( V_164 -> V_171 == V_172 ) {
F_6 ( V_173 | F_3 ( V_8 -> V_17 + V_174 ) ,
V_8 -> V_17 + V_174 ) ;
} else {
F_6 ( ( ~ V_173 )
& F_3 ( V_8 -> V_17 + V_174 ) ,
V_8 -> V_17 + V_174 ) ;
}
if ( V_164 -> clock ) {
V_165 = 20000000 / V_164 -> clock ;
if ( ! V_165 )
V_165 = 1 ;
V_166 = 24000000 / V_164 -> clock ;
if ( ! V_166 )
V_166 = 1 ;
if ( ( 20000000 / V_165 ) > V_164 -> clock )
V_165 ++ ;
if ( ( 24000000 / V_166 ) > V_164 -> clock )
V_166 ++ ;
if ( ( 20000000 / V_165 ) > ( 24000000 / V_166 ) ) {
V_2 -> V_130 = 20000000 ;
V_2 -> V_131 = V_165 ;
F_6 ( ( ~ V_175 )
& F_3 ( V_8 -> V_17 + V_161 ) ,
V_8 -> V_17 + V_161 ) ;
} else {
V_2 -> V_130 = 24000000 ;
V_2 -> V_131 = V_166 ;
F_6 ( V_175
| F_3 ( V_8 -> V_17 + V_161 ) ,
V_8 -> V_17 + V_161 ) ;
}
} else {
V_2 -> V_131 = 0 ;
}
V_2 -> V_131 &= V_176 ;
F_6 ( V_2 -> V_131
| ( ( ~ V_176 )
& F_3 ( V_8 -> V_17 + V_174 ) ) ,
V_8 -> V_17 + V_174 ) ;
V_2 -> V_79 = ( V_164 -> V_168 == V_177 ) ;
F_45 ( & V_8 -> V_102 , V_35 ) ;
}
static int F_52 ( struct V_103 * V_135 )
{
int V_59 = 0 ;
struct V_1 * V_2 = F_30 ( V_135 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_35 ;
F_36 ( & V_8 -> V_102 , V_35 ) ;
if ( V_178 & F_3 ( V_8 -> V_17 + V_179 ) )
V_59 = 1 ;
F_45 ( & V_8 -> V_102 , V_35 ) ;
return V_59 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_59 ;
unsigned int V_106 = 0 ;
struct V_7 * V_8 = V_2 -> V_9 ;
F_6 ( 0 , V_8 -> V_17 + V_98 ) ;
F_54 () ;
V_2 -> V_131 = 61 ;
V_2 -> V_130 = 20000000 ;
F_6 ( V_180 , V_8 -> V_17 + V_181 ) ;
F_6 ( V_2 -> V_131 | V_182 ,
V_8 -> V_17 + V_174 ) ;
for ( V_59 = 32 ; V_59 <= 256 ; V_59 <<= 1 ) {
if ( 1 & F_3 ( V_8 -> V_17 + V_183 ) ) {
V_59 = 0 ;
break;
}
F_55 ( V_59 ) ;
}
if ( V_59 ) {
F_37 ( V_141 L_13 ,
F_38 ( & V_8 -> V_9 ) ) ;
return - V_184 ;
}
F_6 ( 0 , V_8 -> V_17 + V_155 ) ;
F_6 ( V_2 -> V_131 | V_182 ,
V_8 -> V_17 + V_174 ) ;
F_6 ( V_153 , V_8 -> V_17 + V_143 ) ;
F_6 ( 64 , V_8 -> V_17 + V_185 ) ;
F_6 ( V_186 , V_8 -> V_17 + V_86 ) ;
for ( V_59 = 16 ; V_59 <= 64 ; V_59 <<= 1 ) {
V_106 = F_3 ( V_8 -> V_17 + V_108 ) ;
F_6 ( V_106 , V_8 -> V_17 + V_108 ) ;
if ( ! ( V_106 & V_109 )
&& ( V_106 & V_120 ) ) {
V_59 = 0 ;
break;
}
F_55 ( V_59 ) ;
}
if ( V_59 ) {
F_37 ( V_141
L_14 ,
F_38 ( & V_8 -> V_9 ) ) ;
return - V_184 ;
}
F_6 ( V_121 | V_122 | V_120
| V_109 ,
V_8 -> V_17 + V_98 ) ;
F_54 () ;
return 0 ;
}
static int F_56 ( struct V_7 * V_8 )
{
struct V_103 * V_135 ;
struct V_1 * V_2 ;
int V_59 = - V_187 ;
if ( ! ( V_188
& F_3 ( V_8 -> V_17 + V_179 ) ) ) {
F_37 ( V_189 L_15 ,
F_38 ( & V_8 -> V_9 ) ) ;
return V_59 ;
}
V_135 = F_57 ( sizeof( struct V_1 ) , & V_8 -> V_9 ) ;
if ( ! V_135 )
return - V_146 ;
V_2 = F_30 ( V_135 ) ;
F_58 ( V_8 , V_135 ) ;
V_2 -> V_9 = V_8 ;
V_2 -> V_159 = F_59 ( 1000 ) ;
F_60 ( & V_2 -> V_100 , F_47 ,
( unsigned long ) V_2 ) ;
F_61 ( & V_2 -> V_157 , F_49 , ( unsigned long ) V_2 ) ;
V_135 -> V_190 = & V_191 ;
V_135 -> V_192 = V_193 | V_194 ;
V_135 -> V_195 = V_196 ;
V_135 -> V_197 = 20000000 / 60 ;
V_135 -> V_198 = 24000000 ;
V_135 -> V_199 = 2048 ;
V_135 -> V_200 = V_135 -> V_199 ;
V_135 -> V_201 = F_11 ( V_202 , V_39 ) ;
V_135 -> V_203 = V_135 -> V_199 * V_135 -> V_201 ;
V_135 -> V_204 = V_135 -> V_203 ;
V_8 -> V_205 = F_33 ;
V_8 -> V_206 = F_28 ;
V_59 = F_53 ( V_2 ) ;
if ( ! V_59 )
V_59 = F_62 ( V_135 ) ;
if ( ! V_59 )
return 0 ;
F_63 ( V_135 ) ;
return V_59 ;
}
static void F_64 ( struct V_7 * V_8 )
{
struct V_103 * V_135 = F_31 ( V_8 ) ;
struct V_1 * V_2 = F_30 ( V_135 ) ;
unsigned long V_35 ;
F_36 ( & V_8 -> V_102 , V_35 ) ;
V_2 -> V_138 = 1 ;
F_6 ( 0 , V_8 -> V_17 + V_98 ) ;
F_54 () ;
F_45 ( & V_8 -> V_102 , V_35 ) ;
F_65 ( & V_2 -> V_100 ) ;
F_36 ( & V_8 -> V_102 , V_35 ) ;
if ( V_2 -> V_22 ) {
F_6 ( V_116 ,
V_8 -> V_17 + V_117 ) ;
F_6 ( 0 , V_8 -> V_17 + V_151 ) ;
V_2 -> V_22 -> V_23 -> error = - V_139 ;
if ( V_2 -> V_22 -> V_96 )
V_2 -> V_22 -> V_96 -> error = - V_139 ;
F_27 ( & V_2 -> V_100 ) ;
}
F_45 ( & V_8 -> V_102 , V_35 ) ;
F_66 ( V_135 ) ;
F_14 ( & V_8 -> V_9 , L_16 ) ;
F_63 ( V_135 ) ;
}
static int F_67 ( struct V_7 * V_8 , T_1 V_207 )
{
return F_68 ( F_31 ( V_8 ) ) ;
}
static int F_69 ( struct V_7 * V_8 )
{
struct V_103 * V_135 = F_31 ( V_8 ) ;
struct V_1 * V_2 = F_30 ( V_135 ) ;
int V_59 ;
V_59 = F_53 ( V_2 ) ;
F_14 ( & V_8 -> V_9 , L_17 , V_59 ) ;
if ( V_59 )
V_2 -> V_138 = 1 ;
else
V_59 = F_70 ( V_135 ) ;
return V_59 ;
}
static int T_2 F_71 ( void )
{
return F_72 ( & V_208 ) ;
}
static void T_3 F_73 ( void )
{
F_74 ( & V_208 ) ;
}
