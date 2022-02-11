static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
int F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 -> V_10 ) ;
int V_11 , V_12 ;
T_1 V_4 ;
F_7 ( V_2 -> V_13 , V_14 , & V_4 ) ;
if ( V_4 & F_8 ( 4 ) )
F_9 ( V_2 -> V_13 , V_15 , F_8 ( 4 ) ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = F_10 ( V_2 -> V_17 [ V_12 ] ) ;
if ( V_11 ) {
while ( V_12 -- )
F_11 ( V_2 -> V_17 [ V_12 ] ) ;
return V_11 ;
}
}
V_11 = F_12 ( V_2 -> V_17 [ V_18 ] , 49152000 ) ;
if ( V_11 ) {
F_13 ( V_2 -> V_10 , L_1 ,
V_19 , V_11 ) ;
return V_11 ;
}
F_9 ( V_2 -> V_13 , V_20 , F_8 ( 9 ) ) ;
F_9 ( V_2 -> V_13 , V_21 , F_8 ( 5 ) ) ;
F_9 ( V_2 -> V_13 , V_22 , F_8 ( 5 ) ) ;
F_9 ( V_2 -> V_13 , V_23 , F_8 ( 5 ) ) ;
V_4 = F_3 ( V_2 , V_24 ) ;
V_4 |= 0x3f ;
F_1 ( V_2 , V_24 , V_4 ) ;
V_4 = F_3 ( V_2 , V_25 ) ;
V_4 |= ( F_8 ( 5 ) | F_8 ( 4 ) ) ;
F_1 ( V_2 , V_25 , V_4 ) ;
V_4 = F_3 ( V_2 , V_25 ) ;
V_4 &= ~ ( F_8 ( 5 ) | F_8 ( 4 ) ) ;
F_1 ( V_2 , V_25 , V_4 ) ;
V_4 = F_3 ( V_2 , V_26 ) ;
V_4 &= ~ ( V_27 <<
V_28 ) ;
V_4 |= ( V_29 << V_28 ) ;
F_1 ( V_2 , V_26 , V_4 ) ;
V_4 = F_3 ( V_2 , V_30 ) ;
V_4 &= ~ V_31 ;
V_4 &= ~ V_32 ;
V_4 &= ~ V_33 ;
V_4 |= V_32 ;
V_4 |= V_33 ;
F_1 ( V_2 , V_30 , V_4 ) ;
V_4 = F_3 ( V_2 , V_26 ) ;
V_4 |= V_34 ;
F_1 ( V_2 , V_26 , V_4 ) ;
return 0 ;
}
void F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 -> V_10 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ )
F_11 ( V_2 -> V_17 [ V_12 ] ) ;
F_9 ( V_2 -> V_13 , V_22 , F_8 ( 5 ) ) ;
}
static void F_15 ( struct V_8 * V_9 , int V_35 )
{
struct V_1 * V_2 = F_6 ( V_9 -> V_10 ) ;
T_1 V_4 ;
F_16 ( & V_2 -> V_36 ) ;
if ( V_35 ) {
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 |= V_38 ;
F_1 ( V_2 , V_37 , V_4 ) ;
} else {
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 &= ~ V_38 ;
F_1 ( V_2 , V_37 , V_4 ) ;
}
F_17 ( & V_2 -> V_36 ) ;
}
static void F_18 ( struct V_8 * V_9 , int V_35 )
{
struct V_1 * V_2 = F_6 ( V_9 -> V_10 ) ;
T_1 V_4 ;
F_16 ( & V_2 -> V_36 ) ;
if ( V_35 ) {
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 |= V_39 ;
F_1 ( V_2 , V_37 , V_4 ) ;
} else {
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 &= ~ V_39 ;
F_1 ( V_2 , V_37 , V_4 ) ;
}
F_17 ( & V_2 -> V_36 ) ;
}
static int F_19 ( struct V_8 * V_9 , unsigned int V_40 )
{
struct V_1 * V_2 = F_6 ( V_9 -> V_10 ) ;
switch ( V_40 & V_41 ) {
case V_42 :
case V_43 :
break;
default:
return - V_44 ;
}
switch ( V_40 & V_45 ) {
case V_46 :
case V_47 :
case V_48 :
break;
default:
return - V_44 ;
}
V_2 -> V_49 = V_40 ;
V_2 -> V_50 = ( V_2 -> V_49 & V_41 ) ==
V_43 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_51 * V_52 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 -> V_10 ) ;
T_1 V_53 = 0 , V_54 = 0 , V_55 = 0 , V_40 = 0 ;
T_1 V_4 ;
struct V_56 * V_57 ;
switch ( F_21 ( V_52 ) ) {
case V_58 :
V_55 = V_59 ;
case V_60 :
V_53 = V_29 ;
break;
case V_61 :
V_55 = V_59 ;
case V_62 :
V_53 = V_63 ;
break;
default:
F_13 ( V_9 -> V_10 , L_2 ) ;
return - V_44 ;
}
switch ( F_22 ( V_52 ) ) {
case 8000 :
V_54 = V_64 ;
break;
case 16000 :
V_54 = V_65 ;
break;
case 32000 :
V_54 = V_66 ;
break;
case 48000 :
V_54 = V_67 ;
break;
case 96000 :
V_54 = V_68 ;
break;
case 192000 :
V_54 = V_69 ;
break;
default:
F_13 ( V_9 -> V_10 , L_3 , F_22 ( V_52 ) ) ;
return - V_44 ;
}
if ( ! ( F_23 ( V_52 ) ) ) {
F_13 ( V_9 -> V_10 , L_4 ) ;
return - V_44 ;
}
V_57 = F_24 ( V_9 , V_7 ) ;
switch ( V_53 ) {
case V_63 :
V_2 -> V_53 = 32 ;
V_57 -> V_70 = 3 ;
break;
default:
V_2 -> V_53 = 16 ;
V_57 -> V_70 = 2 ;
break;
}
V_2 -> V_54 = F_22 ( V_52 ) ;
V_2 -> V_71 = F_23 ( V_52 ) ;
V_2 -> V_72 = V_2 -> V_71 * V_2 -> V_53 ;
V_4 = F_3 ( V_2 , V_73 ) ;
V_4 &= ~ ( ( V_74 <<
V_75 ) |
( V_76 <<
V_77 ) |
( V_78 <<
V_79 ) |
( V_80 <<
V_81 ) ) ;
V_4 |= ( ( 16 << V_75 ) |
( 30 << V_77 ) |
( 16 << V_79 ) |
( 30 << V_81 ) ) ;
F_1 ( V_2 , V_73 , V_4 ) ;
V_4 = F_3 ( V_2 , V_82 ) ;
V_4 |= ( F_8 ( 19 ) | F_8 ( 18 ) | F_8 ( 17 ) |
V_83 |
V_84 |
V_85 |
V_86 |
V_87 ) ;
F_1 ( V_2 , V_82 , V_4 ) ;
V_4 = F_3 ( V_2 , V_88 ) ;
V_4 &= ~ ( V_89 |
V_90 |
V_91 |
V_92 |
V_93 |
V_94 ) ;
V_4 |= ( V_95 |
V_96 ) ;
F_1 ( V_2 , V_88 , V_4 ) ;
V_4 = F_3 ( V_2 , V_97 ) ;
V_4 &= ~ ( V_98 |
V_99 ) ;
F_1 ( V_2 , V_97 , V_4 ) ;
V_4 = F_3 ( V_2 , V_100 ) ;
V_4 &= ~ ( V_101 |
V_102 |
V_103 |
V_104 ) ;
F_1 ( V_2 , V_100 , V_4 ) ;
switch ( V_2 -> V_49 & V_41 ) {
case V_42 :
V_2 -> V_50 = false ;
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 |= V_105 ;
F_1 ( V_2 , V_37 , V_4 ) ;
break;
case V_43 :
V_2 -> V_50 = true ;
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 &= ~ V_105 ;
F_1 ( V_2 , V_37 , V_4 ) ;
break;
default:
F_25 ( 1 , L_5 ) ;
return - V_44 ;
}
switch ( V_2 -> V_49 & V_45 ) {
case V_46 :
V_40 = V_106 ;
break;
case V_47 :
V_40 = V_107 ;
break;
case V_48 :
V_40 = V_108 ;
break;
default:
F_25 ( 1 , L_6 ) ;
return - V_44 ;
}
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 &= ~ ( V_109 <<
V_110 ) ;
V_4 |= V_40 << V_110 ;
F_1 ( V_2 , V_37 , V_4 ) ;
V_4 = F_3 ( V_2 , V_111 ) ;
V_4 &= ~ ( V_112 |
V_113 ) ;
F_1 ( V_2 , V_111 , V_4 ) ;
V_57 -> V_114 = 2 ;
if ( V_7 -> V_115 == V_116 )
V_57 -> V_117 = V_2 -> V_118 + V_119 ;
else
V_57 -> V_117 = V_2 -> V_118 + V_120 ;
switch ( V_2 -> V_71 ) {
case 1 :
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 |= V_121 ;
F_1 ( V_2 , V_37 , V_4 ) ;
break;
default:
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 &= ~ V_121 ;
F_1 ( V_2 , V_37 , V_4 ) ;
break;
}
V_4 = F_3 ( V_2 , V_37 ) ;
V_4 &= ~ V_59 ;
V_4 &= ~ ( V_122 <<
V_123 ) ;
V_4 &= ~ ( V_124 <<
V_125 ) ;
V_4 |= V_55 ;
V_4 |= ( V_53 << V_123 ) ;
F_1 ( V_2 , V_37 , V_4 ) ;
if ( ! V_2 -> V_50 )
return 0 ;
V_4 = F_3 ( V_2 , V_126 ) ;
V_4 &= ~ ( V_127 << V_128 ) ;
V_4 &= ~ ( V_129 << V_130 ) ;
V_4 &= ~ ( V_131 <<
V_132 ) ;
V_4 &= ~ ( V_133 <<
V_134 ) ;
V_4 |= ( V_54 << V_128 ) ;
V_4 |= ( V_54 << V_130 ) ;
V_4 |= ( V_54 << V_132 ) ;
V_4 |= ( V_54 << V_134 ) ;
F_1 ( V_2 , V_126 , V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 , int V_135 ,
struct V_8 * V_9 )
{
F_27 ( L_7 , V_19 ) ;
switch ( V_135 ) {
case V_136 :
case V_137 :
if ( V_7 -> V_115 == V_138 )
F_18 ( V_9 , 1 ) ;
else
F_15 ( V_9 , 1 ) ;
break;
case V_139 :
case V_140 :
if ( V_7 -> V_115 == V_138 )
F_18 ( V_9 , 0 ) ;
else
F_15 ( V_9 , 0 ) ;
break;
default:
F_13 ( V_9 -> V_10 , L_8 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_28 ( struct V_8 * V_141 )
{
struct V_1 * V_2 = F_29 ( V_141 ) ;
F_30 ( V_141 ,
& V_2 -> V_57 [ V_116 ] ,
& V_2 -> V_57 [ V_138 ] ) ;
return 0 ;
}
static int F_31 ( struct V_142 * V_143 )
{
struct V_144 * V_145 = V_143 -> V_10 . V_146 ;
struct V_147 * V_10 = & V_143 -> V_10 ;
struct V_1 * V_2 ;
struct V_148 * V_149 ;
int V_11 ;
V_2 = F_32 ( & V_143 -> V_10 , sizeof( * V_2 ) , V_150 ) ;
if ( ! V_2 )
return - V_151 ;
V_2 -> V_10 = V_10 ;
F_33 ( & V_2 -> V_36 ) ;
V_149 = F_34 ( V_143 , V_152 , 0 ) ;
V_2 -> V_5 = F_35 ( V_10 , V_149 ) ;
if ( F_36 ( V_2 -> V_5 ) )
return F_37 ( V_2 -> V_5 ) ;
V_2 -> V_118 = ( V_153 ) V_149 -> V_154 ;
V_2 -> V_141 = V_155 ;
F_38 ( & V_143 -> V_10 , V_2 ) ;
V_2 -> V_13 = F_39 ( V_145 ,
L_9 ) ;
if ( F_36 ( V_2 -> V_13 ) )
return F_37 ( V_2 -> V_13 ) ;
V_2 -> V_17 [ V_156 ] = F_40 ( & V_143 -> V_10 , L_10 ) ;
if ( F_41 ( V_2 -> V_17 [ V_156 ] ) )
return F_37 ( V_2 -> V_17 [ V_156 ] ) ;
V_2 -> V_16 ++ ;
V_2 -> V_17 [ V_18 ] = F_40 ( & V_143 -> V_10 , L_11 ) ;
if ( F_41 ( V_2 -> V_17 [ V_18 ] ) )
return F_37 ( V_2 -> V_17 [ V_18 ] ) ;
V_2 -> V_16 ++ ;
V_11 = F_42 ( & V_143 -> V_10 , NULL , 0 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_43 ( & V_143 -> V_10 , & V_157 ,
& V_2 -> V_141 , 1 ) ;
return V_11 ;
}
