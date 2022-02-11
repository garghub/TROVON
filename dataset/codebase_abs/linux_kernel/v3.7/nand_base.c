static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
if ( V_3 & ( ( 1 << V_6 -> V_9 ) - 1 ) ) {
F_2 ( L_1 , V_10 ) ;
V_8 = - V_11 ;
}
if ( V_4 & ( ( 1 << V_6 -> V_9 ) - 1 ) ) {
F_2 ( L_2 , V_10 ) ;
V_8 = - V_11 ;
}
return V_8 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_12 ( V_2 , - 1 ) ;
F_4 ( & V_6 -> V_13 -> V_14 ) ;
V_6 -> V_13 -> V_15 = NULL ;
V_6 -> V_16 = V_17 ;
F_5 ( & V_6 -> V_13 -> V_18 ) ;
F_6 ( & V_6 -> V_13 -> V_14 ) ;
}
static T_3 F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_8 ( V_6 -> V_19 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return ( T_3 ) F_10 ( F_11 ( V_6 -> V_19 ) ) ;
}
static T_4 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_11 ( V_6 -> V_19 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_20 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_20 ) {
case - 1 :
V_6 -> V_21 ( V_2 , V_22 , 0 | V_23 ) ;
break;
case 0 :
break;
default:
F_14 () ;
}
}
static void F_15 ( struct V_1 * V_2 , const T_3 * V_24 , int V_4 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ )
F_16 ( V_24 [ V_25 ] , V_6 -> V_26 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_3 * V_24 , int V_4 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ )
V_24 [ V_25 ] = F_8 ( V_6 -> V_19 ) ;
}
static void F_18 ( struct V_1 * V_2 , const T_3 * V_24 , int V_4 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_27 = ( T_4 * ) V_24 ;
V_4 >>= 1 ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ )
F_19 ( V_27 [ V_25 ] , V_6 -> V_26 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_3 * V_24 , int V_4 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_27 = ( T_4 * ) V_24 ;
V_4 >>= 1 ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ )
V_27 [ V_25 ] = F_11 ( V_6 -> V_19 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_3 , int V_28 )
{
int V_29 , V_20 , V_30 = 0 , V_25 = 0 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 V_31 ;
if ( V_6 -> V_32 & V_33 )
V_3 += V_2 -> V_34 - V_2 -> V_35 ;
V_29 = ( int ) ( V_3 >> V_6 -> V_36 ) & V_6 -> V_37 ;
if ( V_28 ) {
V_20 = ( int ) ( V_3 >> V_6 -> V_38 ) ;
F_22 ( V_6 , V_2 , V_39 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
}
do {
if ( V_6 -> V_40 & V_41 ) {
V_6 -> V_42 ( V_2 , V_43 ,
V_6 -> V_44 & 0xFE , V_29 ) ;
V_31 = F_10 ( V_6 -> V_45 ( V_2 ) ) ;
if ( V_6 -> V_44 & 0x1 )
V_31 >>= 8 ;
else
V_31 &= 0xFF ;
} else {
V_6 -> V_42 ( V_2 , V_43 , V_6 -> V_44 ,
V_29 ) ;
V_31 = V_6 -> V_46 ( V_2 ) ;
}
if ( F_23 ( V_6 -> V_47 == 8 ) )
V_30 = V_31 != 0xFF ;
else
V_30 = F_24 ( V_31 ) < V_6 -> V_47 ;
V_3 += V_2 -> V_35 ;
V_29 = ( int ) ( V_3 >> V_6 -> V_36 ) & V_6 -> V_37 ;
V_25 ++ ;
} while ( ! V_30 && V_25 < 2 && ( V_6 -> V_32 & V_48 ) );
if ( V_28 )
F_3 ( V_2 ) ;
return V_30 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_24 [ 2 ] = { 0 , 0 } ;
int V_49 , V_30 , V_8 = 0 , V_25 = 0 ;
int V_50 = ! ( V_6 -> V_32 & V_51 ) ;
if ( V_50 ) {
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_2 = V_2 ;
V_53 . V_54 = V_3 ;
V_53 . V_4 = 1 << V_6 -> V_9 ;
F_26 ( V_2 , & V_53 , 0 ) ;
}
V_49 = ( int ) ( V_3 >> V_6 -> V_55 ) ;
if ( V_6 -> V_56 )
V_6 -> V_56 [ V_49 >> 2 ] |= 0x01 << ( ( V_49 & 0x03 ) << 1 ) ;
if ( V_50 ) {
struct V_57 V_58 ;
T_1 V_59 = V_3 ;
F_22 ( V_6 , V_2 , V_60 ) ;
V_58 . V_61 = NULL ;
V_58 . V_62 = V_24 ;
V_58 . V_63 = V_6 -> V_44 ;
if ( V_6 -> V_40 & V_41 ) {
V_58 . V_63 &= ~ 0x01 ;
V_58 . V_4 = V_58 . V_64 = 2 ;
} else {
V_58 . V_4 = V_58 . V_64 = 1 ;
}
V_58 . V_65 = V_66 ;
if ( V_6 -> V_32 & V_33 )
V_59 += V_2 -> V_34 - V_2 -> V_35 ;
do {
V_30 = F_27 ( V_2 , V_59 , & V_58 ) ;
if ( ! V_8 )
V_8 = V_30 ;
V_25 ++ ;
V_59 += V_2 -> V_35 ;
} while ( ( V_6 -> V_32 & V_48 ) && V_25 < 2 );
F_3 ( V_2 ) ;
}
if ( V_6 -> V_32 & V_67 ) {
V_30 = F_28 ( V_2 , V_3 ) ;
if ( ! V_8 )
V_8 = V_30 ;
}
if ( ! V_8 )
V_2 -> V_68 . V_69 ++ ;
return V_8 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_40 & V_70 )
return 0 ;
V_6 -> V_42 ( V_2 , V_71 , - 1 , - 1 ) ;
return ( V_6 -> V_46 ( V_2 ) & V_72 ) ? 0 : 1 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_3 , int V_28 ,
int V_73 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_56 )
return V_6 -> V_74 ( V_2 , V_3 , V_28 ) ;
return F_31 ( V_2 , V_3 , V_73 ) ;
}
static void F_32 ( struct V_1 * V_2 , unsigned long V_75 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_75 ; V_25 ++ ) {
if ( V_6 -> V_76 ( V_2 ) )
break;
F_33 () ;
F_34 ( 1 ) ;
}
}
void F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_75 = V_77 + 2 ;
if ( F_36 () || V_78 )
return F_32 ( V_2 , 400 ) ;
F_37 ( V_79 , V_80 ) ;
do {
if ( V_6 -> V_76 ( V_2 ) )
break;
F_33 () ;
} while ( F_38 ( V_77 , V_75 ) );
F_37 ( V_79 , V_81 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned int V_82 ,
int V_83 , int V_84 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
int V_85 = V_86 | V_23 ;
if ( V_82 == V_87 ) {
int V_88 ;
if ( V_83 >= V_2 -> V_35 ) {
V_83 -= V_2 -> V_35 ;
V_88 = V_43 ;
} else if ( V_83 < 256 ) {
V_88 = V_89 ;
} else {
V_83 -= 256 ;
V_88 = V_90 ;
}
V_6 -> V_21 ( V_2 , V_88 , V_85 ) ;
V_85 &= ~ V_23 ;
}
V_6 -> V_21 ( V_2 , V_82 , V_85 ) ;
V_85 = V_91 | V_23 ;
if ( V_83 != - 1 ) {
if ( V_6 -> V_40 & V_41 )
V_83 >>= 1 ;
V_6 -> V_21 ( V_2 , V_83 , V_85 ) ;
V_85 &= ~ V_23 ;
}
if ( V_84 != - 1 ) {
V_6 -> V_21 ( V_2 , V_84 , V_85 ) ;
V_85 &= ~ V_23 ;
V_6 -> V_21 ( V_2 , V_84 >> 8 , V_85 ) ;
if ( V_6 -> V_92 > ( 32 << 20 ) )
V_6 -> V_21 ( V_2 , V_84 >> 16 , V_85 ) ;
}
V_6 -> V_21 ( V_2 , V_22 , V_93 | V_23 ) ;
switch ( V_82 ) {
case V_94 :
case V_95 :
case V_96 :
case V_87 :
case V_71 :
return;
case V_97 :
if ( V_6 -> V_76 )
break;
F_40 ( V_6 -> V_98 ) ;
V_6 -> V_21 ( V_2 , V_71 ,
V_86 | V_23 ) ;
V_6 -> V_21 ( V_2 ,
V_22 , V_93 | V_23 ) ;
while ( ! ( V_6 -> V_46 ( V_2 ) & V_99 ) )
;
return;
default:
if ( ! V_6 -> V_76 ) {
F_40 ( V_6 -> V_98 ) ;
return;
}
}
F_41 ( 100 ) ;
F_35 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_82 ,
int V_83 , int V_84 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_82 == V_43 ) {
V_83 += V_2 -> V_35 ;
V_82 = V_89 ;
}
V_6 -> V_21 ( V_2 , V_82 & 0xff ,
V_93 | V_100 | V_23 ) ;
if ( V_83 != - 1 || V_84 != - 1 ) {
int V_85 = V_23 | V_93 | V_101 ;
if ( V_83 != - 1 ) {
if ( V_6 -> V_40 & V_41 )
V_83 >>= 1 ;
V_6 -> V_21 ( V_2 , V_83 , V_85 ) ;
V_85 &= ~ V_23 ;
V_6 -> V_21 ( V_2 , V_83 >> 8 , V_85 ) ;
}
if ( V_84 != - 1 ) {
V_6 -> V_21 ( V_2 , V_84 , V_85 ) ;
V_6 -> V_21 ( V_2 , V_84 >> 8 ,
V_93 | V_101 ) ;
if ( V_6 -> V_92 > ( 128 << 20 ) )
V_6 -> V_21 ( V_2 , V_84 >> 16 ,
V_93 | V_101 ) ;
}
}
V_6 -> V_21 ( V_2 , V_22 , V_93 | V_23 ) ;
switch ( V_82 ) {
case V_102 :
case V_94 :
case V_95 :
case V_96 :
case V_87 :
case V_103 :
case V_71 :
case V_104 :
return;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
F_40 ( V_6 -> V_98 ) ;
return;
case V_97 :
if ( V_6 -> V_76 )
break;
F_40 ( V_6 -> V_98 ) ;
V_6 -> V_21 ( V_2 , V_71 ,
V_93 | V_100 | V_23 ) ;
V_6 -> V_21 ( V_2 , V_22 ,
V_93 | V_23 ) ;
while ( ! ( V_6 -> V_46 ( V_2 ) & V_99 ) )
;
return;
case V_110 :
V_6 -> V_21 ( V_2 , V_111 ,
V_93 | V_100 | V_23 ) ;
V_6 -> V_21 ( V_2 , V_22 ,
V_93 | V_23 ) ;
return;
case V_89 :
V_6 -> V_21 ( V_2 , V_112 ,
V_93 | V_100 | V_23 ) ;
V_6 -> V_21 ( V_2 , V_22 ,
V_93 | V_23 ) ;
default:
if ( ! V_6 -> V_76 ) {
F_40 ( V_6 -> V_98 ) ;
return;
}
}
F_41 ( 100 ) ;
F_35 ( V_2 ) ;
}
static void F_43 ( struct V_5 * V_6 ,
struct V_1 * V_2 , int V_113 )
{
V_6 -> V_13 -> V_15 = V_6 ;
V_6 -> V_16 = V_113 ;
}
static int
F_22 ( struct V_5 * V_6 , struct V_1 * V_2 , int V_113 )
{
T_5 * V_14 = & V_6 -> V_13 -> V_14 ;
T_6 * V_18 = & V_6 -> V_13 -> V_18 ;
F_44 ( V_114 , V_115 ) ;
V_116:
F_4 ( V_14 ) ;
if ( ! V_6 -> V_13 -> V_15 )
V_6 -> V_13 -> V_15 = V_6 ;
if ( V_6 -> V_13 -> V_15 == V_6 && V_6 -> V_16 == V_17 ) {
V_6 -> V_16 = V_113 ;
F_6 ( V_14 ) ;
return 0 ;
}
if ( V_113 == V_117 ) {
if ( V_6 -> V_13 -> V_15 -> V_16 == V_117 ) {
V_6 -> V_16 = V_117 ;
F_6 ( V_14 ) ;
return 0 ;
}
}
F_45 ( V_118 ) ;
F_46 ( V_18 , & V_114 ) ;
F_6 ( V_14 ) ;
F_47 () ;
F_48 ( V_18 , & V_114 ) ;
goto V_116;
}
static void F_49 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned long V_75 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_75 ; V_25 ++ ) {
if ( V_6 -> V_76 ) {
if ( V_6 -> V_76 ( V_2 ) )
break;
} else {
if ( V_6 -> V_46 ( V_2 ) & V_99 )
break;
}
F_34 ( 1 ) ;
}
}
static int F_50 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned long V_75 = V_77 ;
int V_119 , V_16 = V_6 -> V_16 ;
if ( V_16 == V_120 )
V_75 += ( V_121 * 400 ) / 1000 ;
else
V_75 += ( V_121 * 20 ) / 1000 ;
F_37 ( V_79 , V_80 ) ;
F_41 ( 100 ) ;
if ( ( V_16 == V_120 ) && ( V_6 -> V_40 & V_122 ) )
V_6 -> V_42 ( V_2 , V_123 , - 1 , - 1 ) ;
else
V_6 -> V_42 ( V_2 , V_71 , - 1 , - 1 ) ;
if ( F_36 () || V_78 )
F_49 ( V_2 , V_6 , V_75 ) ;
else {
while ( F_38 ( V_77 , V_75 ) ) {
if ( V_6 -> V_76 ) {
if ( V_6 -> V_76 ( V_2 ) )
break;
} else {
if ( V_6 -> V_46 ( V_2 ) & V_99 )
break;
}
F_51 () ;
}
}
F_37 ( V_79 , V_81 ) ;
V_119 = ( int ) V_6 -> V_46 ( V_2 ) ;
return V_119 ;
}
static int F_52 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , int V_124 )
{
int V_8 = 0 ;
int V_119 , V_29 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_29 = V_3 >> V_6 -> V_36 ;
V_6 -> V_42 ( V_2 , V_125 , - 1 , V_29 & V_6 -> V_37 ) ;
V_29 = ( V_3 + V_4 ) >> V_6 -> V_36 ;
V_6 -> V_42 ( V_2 , V_126 , - 1 ,
( V_29 | V_124 ) & V_6 -> V_37 ) ;
V_119 = V_6 -> V_127 ( V_2 , V_6 ) ;
if ( V_119 & 0x01 ) {
F_2 ( L_3 ,
V_10 , V_119 ) ;
V_8 = - V_128 ;
}
return V_8 ;
}
int F_53 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
V_8 = - V_11 ;
if ( V_3 + V_4 == V_2 -> V_129 )
V_4 -= V_2 -> V_34 ;
F_22 ( V_6 , V_2 , V_130 ) ;
V_20 = V_3 >> V_6 -> V_38 ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( F_29 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_8 = - V_128 ;
goto V_131;
}
V_8 = F_52 ( V_2 , V_3 , V_4 , 0 ) ;
V_131:
F_3 ( V_2 ) ;
return V_8 ;
}
int F_54 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_20 , V_119 , V_29 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
V_8 = - V_11 ;
F_22 ( V_6 , V_2 , V_132 ) ;
V_20 = V_3 >> V_6 -> V_38 ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( F_29 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_119 = V_133 ;
V_8 = - V_128 ;
goto V_131;
}
V_29 = V_3 >> V_6 -> V_36 ;
V_6 -> V_42 ( V_2 , V_134 , - 1 , V_29 & V_6 -> V_37 ) ;
V_119 = V_6 -> V_127 ( V_2 , V_6 ) ;
if ( V_119 & 0x01 ) {
F_2 ( L_3 ,
V_10 , V_119 ) ;
V_8 = - V_128 ;
goto V_131;
}
V_8 = F_52 ( V_2 , V_3 , V_4 , 0x1 ) ;
V_131:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_24 , int V_135 , int V_29 )
{
V_6 -> V_136 ( V_2 , V_24 , V_2 -> V_35 ) ;
if ( V_135 )
V_6 -> V_136 ( V_2 , V_6 -> V_137 , V_2 -> V_138 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_24 ,
int V_135 , int V_29 )
{
int V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
T_3 * V_143 = V_6 -> V_137 ;
int V_144 , V_129 ;
for ( V_144 = V_6 -> V_140 . V_144 ; V_144 > 0 ; V_144 -- ) {
V_6 -> V_136 ( V_2 , V_24 , V_139 ) ;
V_24 += V_139 ;
if ( V_6 -> V_140 . V_145 ) {
V_6 -> V_136 ( V_2 , V_143 , V_6 -> V_140 . V_145 ) ;
V_143 += V_6 -> V_140 . V_145 ;
}
V_6 -> V_136 ( V_2 , V_143 , V_141 ) ;
V_143 += V_141 ;
if ( V_6 -> V_140 . V_146 ) {
V_6 -> V_136 ( V_2 , V_143 , V_6 -> V_140 . V_146 ) ;
V_143 += V_6 -> V_140 . V_146 ;
}
}
V_129 = V_2 -> V_138 - ( V_143 - V_6 -> V_137 ) ;
if ( V_129 )
V_6 -> V_136 ( V_2 , V_143 , V_129 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_24 , int V_135 , int V_29 )
{
int V_25 , V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
int V_147 = V_6 -> V_140 . V_144 ;
T_3 * V_27 = V_24 ;
T_3 * V_148 = V_6 -> V_149 -> V_150 ;
T_3 * V_151 = V_6 -> V_149 -> V_152 ;
T_7 * V_153 = V_6 -> V_140 . V_154 -> V_153 ;
unsigned int V_155 = 0 ;
V_6 -> V_140 . V_156 ( V_2 , V_6 , V_24 , 1 , V_29 ) ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 )
V_6 -> V_140 . V_157 ( V_2 , V_27 , & V_148 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_140 . V_158 ; V_25 ++ )
V_151 [ V_25 ] = V_6 -> V_137 [ V_153 [ V_25 ] ] ;
V_147 = V_6 -> V_140 . V_144 ;
V_27 = V_24 ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 ) {
int V_159 ;
V_159 = V_6 -> V_140 . V_160 ( V_2 , V_27 , & V_151 [ V_25 ] , & V_148 [ V_25 ] ) ;
if ( V_159 < 0 ) {
V_2 -> V_68 . V_161 ++ ;
} else {
V_2 -> V_68 . V_162 += V_159 ;
V_155 = F_58 (unsigned int, max_bitflips, stat) ;
}
}
return V_155 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_7 V_163 , T_7 V_164 , T_3 * V_165 )
{
int V_166 , V_167 , V_168 ;
T_7 * V_153 = V_6 -> V_140 . V_154 -> V_153 ;
T_3 * V_27 ;
int V_169 , V_25 , V_170 = 0 ;
int V_171 , V_172 , V_173 , V_174 ;
int V_175 = ( V_6 -> V_40 & V_41 ) ? 2 : 1 ;
int V_176 = 0 ;
unsigned int V_155 = 0 ;
V_166 = V_163 / V_6 -> V_140 . V_129 ;
V_167 = ( V_163 + V_164 - 1 ) / V_6 -> V_140 . V_129 ;
V_168 = V_167 - V_166 + 1 ;
V_171 = V_168 * V_6 -> V_140 . V_129 ;
V_172 = V_168 * V_6 -> V_140 . V_142 ;
V_169 = V_166 * V_6 -> V_140 . V_129 ;
if ( V_169 != 0 )
V_6 -> V_42 ( V_2 , V_110 , V_169 , - 1 ) ;
V_27 = V_165 + V_169 ;
V_6 -> V_136 ( V_2 , V_27 , V_171 ) ;
for ( V_25 = 0 ; V_25 < V_172 ; V_25 += V_6 -> V_140 . V_142 , V_27 += V_6 -> V_140 . V_129 )
V_6 -> V_140 . V_157 ( V_2 , V_27 , & V_6 -> V_149 -> V_150 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_172 - 1 ; V_25 ++ ) {
if ( V_153 [ V_25 + V_166 * V_6 -> V_140 . V_142 ] + 1 !=
V_153 [ V_25 + V_166 * V_6 -> V_140 . V_142 + 1 ] ) {
V_170 = 1 ;
break;
}
}
if ( V_170 ) {
V_6 -> V_42 ( V_2 , V_110 , V_2 -> V_35 , - 1 ) ;
V_6 -> V_136 ( V_2 , V_6 -> V_137 , V_2 -> V_138 ) ;
} else {
V_176 = V_166 * V_6 -> V_140 . V_142 ;
V_174 = V_153 [ V_176 ] & ~ ( V_175 - 1 ) ;
V_173 = V_172 ;
if ( V_153 [ V_176 ] & ( V_175 - 1 ) )
V_173 ++ ;
if ( V_153 [ V_176 + ( V_168 * V_6 -> V_140 . V_142 ) ] & ( V_175 - 1 ) )
V_173 ++ ;
V_6 -> V_42 ( V_2 , V_110 ,
V_2 -> V_35 + V_174 , - 1 ) ;
V_6 -> V_136 ( V_2 , & V_6 -> V_137 [ V_174 ] , V_173 ) ;
}
for ( V_25 = 0 ; V_25 < V_172 ; V_25 ++ )
V_6 -> V_149 -> V_152 [ V_25 ] = V_6 -> V_137 [ V_153 [ V_25 + V_176 ] ] ;
V_27 = V_165 + V_169 ;
for ( V_25 = 0 ; V_25 < V_172 ; V_25 += V_6 -> V_140 . V_142 , V_27 += V_6 -> V_140 . V_129 ) {
int V_159 ;
V_159 = V_6 -> V_140 . V_160 ( V_2 , V_27 ,
& V_6 -> V_149 -> V_152 [ V_25 ] , & V_6 -> V_149 -> V_150 [ V_25 ] ) ;
if ( V_159 < 0 ) {
V_2 -> V_68 . V_161 ++ ;
} else {
V_2 -> V_68 . V_162 += V_159 ;
V_155 = F_58 (unsigned int, max_bitflips, stat) ;
}
}
return V_155 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_24 , int V_135 , int V_29 )
{
int V_25 , V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
int V_147 = V_6 -> V_140 . V_144 ;
T_3 * V_27 = V_24 ;
T_3 * V_148 = V_6 -> V_149 -> V_150 ;
T_3 * V_151 = V_6 -> V_149 -> V_152 ;
T_7 * V_153 = V_6 -> V_140 . V_154 -> V_153 ;
unsigned int V_155 = 0 ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 ) {
V_6 -> V_140 . V_177 ( V_2 , V_178 ) ;
V_6 -> V_136 ( V_2 , V_27 , V_139 ) ;
V_6 -> V_140 . V_157 ( V_2 , V_27 , & V_148 [ V_25 ] ) ;
}
V_6 -> V_136 ( V_2 , V_6 -> V_137 , V_2 -> V_138 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_140 . V_158 ; V_25 ++ )
V_151 [ V_25 ] = V_6 -> V_137 [ V_153 [ V_25 ] ] ;
V_147 = V_6 -> V_140 . V_144 ;
V_27 = V_24 ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 ) {
int V_159 ;
V_159 = V_6 -> V_140 . V_160 ( V_2 , V_27 , & V_151 [ V_25 ] , & V_148 [ V_25 ] ) ;
if ( V_159 < 0 ) {
V_2 -> V_68 . V_161 ++ ;
} else {
V_2 -> V_68 . V_162 += V_159 ;
V_155 = F_58 (unsigned int, max_bitflips, stat) ;
}
}
return V_155 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_24 , int V_135 , int V_29 )
{
int V_25 , V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
int V_147 = V_6 -> V_140 . V_144 ;
T_3 * V_27 = V_24 ;
T_3 * V_151 = V_6 -> V_149 -> V_152 ;
T_7 * V_153 = V_6 -> V_140 . V_154 -> V_153 ;
T_3 * V_148 = V_6 -> V_149 -> V_150 ;
unsigned int V_155 = 0 ;
V_6 -> V_42 ( V_2 , V_43 , 0 , V_29 ) ;
V_6 -> V_136 ( V_2 , V_6 -> V_137 , V_2 -> V_138 ) ;
V_6 -> V_42 ( V_2 , V_89 , 0 , V_29 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_140 . V_158 ; V_25 ++ )
V_151 [ V_25 ] = V_6 -> V_137 [ V_153 [ V_25 ] ] ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 ) {
int V_159 ;
V_6 -> V_140 . V_177 ( V_2 , V_178 ) ;
V_6 -> V_136 ( V_2 , V_27 , V_139 ) ;
V_6 -> V_140 . V_157 ( V_2 , V_27 , & V_148 [ V_25 ] ) ;
V_159 = V_6 -> V_140 . V_160 ( V_2 , V_27 , & V_151 [ V_25 ] , NULL ) ;
if ( V_159 < 0 ) {
V_2 -> V_68 . V_161 ++ ;
} else {
V_2 -> V_68 . V_162 += V_159 ;
V_155 = F_58 (unsigned int, max_bitflips, stat) ;
}
}
return V_155 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_24 , int V_135 , int V_29 )
{
int V_25 , V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
int V_147 = V_6 -> V_140 . V_144 ;
T_3 * V_27 = V_24 ;
T_3 * V_143 = V_6 -> V_137 ;
unsigned int V_155 = 0 ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 ) {
int V_159 ;
V_6 -> V_140 . V_177 ( V_2 , V_178 ) ;
V_6 -> V_136 ( V_2 , V_27 , V_139 ) ;
if ( V_6 -> V_140 . V_145 ) {
V_6 -> V_136 ( V_2 , V_143 , V_6 -> V_140 . V_145 ) ;
V_143 += V_6 -> V_140 . V_145 ;
}
V_6 -> V_140 . V_177 ( V_2 , V_179 ) ;
V_6 -> V_136 ( V_2 , V_143 , V_141 ) ;
V_159 = V_6 -> V_140 . V_160 ( V_2 , V_27 , V_143 , NULL ) ;
if ( V_159 < 0 ) {
V_2 -> V_68 . V_161 ++ ;
} else {
V_2 -> V_68 . V_162 += V_159 ;
V_155 = F_58 (unsigned int, max_bitflips, stat) ;
}
V_143 += V_141 ;
if ( V_6 -> V_140 . V_146 ) {
V_6 -> V_136 ( V_2 , V_143 , V_6 -> V_140 . V_146 ) ;
V_143 += V_6 -> V_140 . V_146 ;
}
}
V_25 = V_2 -> V_138 - ( V_143 - V_6 -> V_137 ) ;
if ( V_25 )
V_6 -> V_136 ( V_2 , V_143 , V_25 ) ;
return V_155 ;
}
static T_3 * F_63 ( struct V_5 * V_6 , T_3 * V_143 ,
struct V_57 * V_58 , T_8 V_4 )
{
switch ( V_58 -> V_65 ) {
case V_66 :
case V_180 :
memcpy ( V_143 , V_6 -> V_137 + V_58 -> V_63 , V_4 ) ;
return V_143 + V_4 ;
case V_181 : {
struct V_182 * free = V_6 -> V_140 . V_154 -> V_183 ;
T_7 V_184 = 0 , V_185 = V_58 -> V_63 ;
T_8 V_142 = 0 ;
for (; free -> V_186 && V_4 ; free ++ , V_4 -= V_142 ) {
if ( F_64 ( V_185 ) ) {
if ( V_185 >= free -> V_186 ) {
V_185 -= free -> V_186 ;
continue;
}
V_184 = free -> V_187 + V_185 ;
V_142 = F_65 ( T_8 , V_4 ,
( free -> V_186 - V_185 ) ) ;
V_185 = 0 ;
} else {
V_142 = F_65 ( T_8 , V_4 , free -> V_186 ) ;
V_184 = free -> V_187 ;
}
memcpy ( V_143 , V_6 -> V_137 + V_184 , V_142 ) ;
V_143 += V_142 ;
}
return V_143 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_66 ( struct V_1 * V_2 , T_1 V_188 ,
struct V_57 * V_58 )
{
int V_20 , V_29 , V_189 , V_190 , V_142 , V_191 , V_135 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_192 V_193 ;
int V_8 = 0 ;
T_7 V_164 = V_58 -> V_4 ;
T_7 V_194 = V_58 -> V_64 ;
T_7 V_195 = V_58 -> V_65 == V_181 ?
V_2 -> V_196 : V_2 -> V_138 ;
T_3 * V_165 , * V_143 , * V_24 ;
unsigned int V_155 = 0 ;
V_193 = V_2 -> V_68 ;
V_20 = ( int ) ( V_188 >> V_6 -> V_38 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
V_189 = ( int ) ( V_188 >> V_6 -> V_36 ) ;
V_29 = V_189 & V_6 -> V_37 ;
V_190 = ( int ) ( V_188 & ( V_2 -> V_35 - 1 ) ) ;
V_24 = V_58 -> V_61 ;
V_143 = V_58 -> V_62 ;
V_135 = V_143 ? 1 : 0 ;
while ( 1 ) {
V_142 = F_67 ( V_2 -> V_35 - V_190 , V_164 ) ;
V_191 = ( V_142 == V_2 -> V_35 ) ;
if ( V_189 != V_6 -> V_197 || V_143 ) {
V_165 = V_191 ? V_24 : V_6 -> V_149 -> V_198 ;
V_6 -> V_42 ( V_2 , V_89 , 0x00 , V_29 ) ;
if ( F_64 ( V_58 -> V_65 == V_180 ) )
V_8 = V_6 -> V_140 . V_156 ( V_2 , V_6 , V_165 ,
V_135 ,
V_29 ) ;
else if ( ! V_191 && F_68 ( V_6 ) &&
! V_143 )
V_8 = V_6 -> V_140 . V_199 ( V_2 , V_6 ,
V_190 , V_142 , V_165 ) ;
else
V_8 = V_6 -> V_140 . V_200 ( V_2 , V_6 , V_165 ,
V_135 , V_29 ) ;
if ( V_8 < 0 ) {
if ( ! V_191 )
V_6 -> V_197 = - 1 ;
break;
}
V_155 = F_58 (unsigned int, max_bitflips, ret) ;
if ( ! V_191 ) {
if ( ! F_68 ( V_6 ) && ! V_143 &&
! ( V_2 -> V_68 . V_161 - V_193 . V_161 ) &&
( V_58 -> V_65 != V_180 ) ) {
V_6 -> V_197 = V_189 ;
V_6 -> V_201 = V_8 ;
} else {
V_6 -> V_197 = - 1 ;
}
memcpy ( V_24 , V_6 -> V_149 -> V_198 + V_190 , V_142 ) ;
}
V_24 += V_142 ;
if ( F_64 ( V_143 ) ) {
int V_202 = F_67 ( V_194 , V_195 ) ;
if ( V_202 ) {
V_143 = F_63 ( V_6 ,
V_143 , V_58 , V_202 ) ;
V_194 -= V_202 ;
}
}
} else {
memcpy ( V_24 , V_6 -> V_149 -> V_198 + V_190 , V_142 ) ;
V_24 += V_142 ;
V_155 = F_58 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_164 -= V_142 ;
if ( ! V_164 )
break;
V_190 = 0 ;
V_189 ++ ;
V_29 = V_189 & V_6 -> V_37 ;
if ( ! V_29 ) {
V_20 ++ ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
}
}
V_58 -> V_203 = V_58 -> V_4 - ( T_8 ) V_164 ;
if ( V_143 )
V_58 -> V_204 = V_58 -> V_64 - V_194 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_68 . V_161 - V_193 . V_161 )
return - V_205 ;
return V_155 ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_188 , T_8 V_4 ,
T_8 * V_203 , T_3 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_57 V_58 ;
int V_8 ;
F_22 ( V_6 , V_2 , V_39 ) ;
V_58 . V_4 = V_4 ;
V_58 . V_61 = V_24 ;
V_58 . V_62 = NULL ;
V_58 . V_65 = V_66 ;
V_8 = F_66 ( V_2 , V_188 , & V_58 ) ;
* V_203 = V_58 . V_203 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_29 )
{
V_6 -> V_42 ( V_2 , V_43 , 0 , V_29 ) ;
V_6 -> V_136 ( V_2 , V_6 -> V_137 , V_2 -> V_138 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_29 )
{
T_3 * V_24 = V_6 -> V_137 ;
int V_186 = V_2 -> V_138 ;
int V_206 = V_6 -> V_140 . V_142 + V_6 -> V_140 . V_145 + V_6 -> V_140 . V_146 ;
int V_139 = V_6 -> V_140 . V_129 ;
T_3 * V_165 = V_24 ;
int V_25 , V_202 , V_207 = 0 , V_208 ;
V_6 -> V_42 ( V_2 , V_89 , V_6 -> V_140 . V_129 , V_29 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_140 . V_144 ; V_25 ++ ) {
if ( V_207 ) {
V_208 = V_139 + V_25 * ( V_139 + V_206 ) ;
if ( V_2 -> V_35 > 512 )
V_6 -> V_42 ( V_2 , V_110 , V_208 , - 1 ) ;
else
V_6 -> V_42 ( V_2 , V_89 , V_208 , V_29 ) ;
} else
V_207 = 1 ;
V_202 = F_65 ( int , V_186 , V_206 ) ;
V_6 -> V_136 ( V_2 , V_165 , V_202 ) ;
V_165 += V_202 ;
V_186 -= V_202 ;
}
if ( V_186 > 0 )
V_6 -> V_136 ( V_2 , V_165 , V_186 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_29 )
{
int V_119 = 0 ;
const T_3 * V_24 = V_6 -> V_137 ;
int V_186 = V_2 -> V_138 ;
V_6 -> V_42 ( V_2 , V_87 , V_2 -> V_35 , V_29 ) ;
V_6 -> V_209 ( V_2 , V_24 , V_186 ) ;
V_6 -> V_42 ( V_2 , V_94 , - 1 , - 1 ) ;
V_119 = V_6 -> V_127 ( V_2 , V_6 ) ;
return V_119 & V_210 ? - V_128 : 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_29 )
{
int V_206 = V_6 -> V_140 . V_142 + V_6 -> V_140 . V_145 + V_6 -> V_140 . V_146 ;
int V_139 = V_6 -> V_140 . V_129 , V_186 = V_2 -> V_138 ;
int V_25 , V_4 , V_208 , V_119 = 0 , V_211 = 0 , V_144 = V_6 -> V_140 . V_144 ;
const T_3 * V_165 = V_6 -> V_137 ;
if ( ! V_6 -> V_140 . V_145 && ! V_6 -> V_140 . V_146 ) {
V_208 = V_144 * ( V_139 + V_206 ) ;
V_144 = 0 ;
} else
V_208 = V_139 ;
V_6 -> V_42 ( V_2 , V_87 , V_208 , V_29 ) ;
for ( V_25 = 0 ; V_25 < V_144 ; V_25 ++ ) {
if ( V_211 ) {
if ( V_2 -> V_35 <= 512 ) {
T_7 V_212 = 0xFFFFFFFF ;
V_4 = V_139 ;
while ( V_4 > 0 ) {
int V_213 = F_65 ( int , V_4 , 4 ) ;
V_6 -> V_209 ( V_2 , ( T_3 * ) & V_212 ,
V_213 ) ;
V_4 -= V_213 ;
}
} else {
V_208 = V_139 + V_25 * ( V_139 + V_206 ) ;
V_6 -> V_42 ( V_2 , V_103 , V_208 , - 1 ) ;
}
} else
V_211 = 1 ;
V_4 = F_65 ( int , V_186 , V_206 ) ;
V_6 -> V_209 ( V_2 , V_165 , V_4 ) ;
V_165 += V_4 ;
V_186 -= V_4 ;
}
if ( V_186 > 0 )
V_6 -> V_209 ( V_2 , V_165 , V_186 ) ;
V_6 -> V_42 ( V_2 , V_94 , - 1 , - 1 ) ;
V_119 = V_6 -> V_127 ( V_2 , V_6 ) ;
return V_119 & V_210 ? - V_128 : 0 ;
}
static int F_74 ( struct V_1 * V_2 , T_1 V_188 ,
struct V_57 * V_58 )
{
int V_29 , V_189 , V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_192 V_193 ;
int V_164 = V_58 -> V_64 ;
int V_4 ;
T_3 * V_24 = V_58 -> V_62 ;
int V_8 = 0 ;
F_2 ( L_6 ,
V_10 , ( unsigned long long ) V_188 , V_164 ) ;
V_193 = V_2 -> V_68 ;
if ( V_58 -> V_65 == V_181 )
V_4 = V_6 -> V_140 . V_154 -> V_196 ;
else
V_4 = V_2 -> V_138 ;
if ( F_64 ( V_58 -> V_63 >= V_4 ) ) {
F_2 ( L_7 ,
V_10 ) ;
return - V_11 ;
}
if ( F_64 ( V_188 >= V_2 -> V_129 ||
V_58 -> V_63 + V_164 > ( ( V_2 -> V_129 >> V_6 -> V_36 ) -
( V_188 >> V_6 -> V_36 ) ) * V_4 ) ) {
F_2 ( L_8 ,
V_10 ) ;
return - V_11 ;
}
V_20 = ( int ) ( V_188 >> V_6 -> V_38 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
V_189 = ( int ) ( V_188 >> V_6 -> V_36 ) ;
V_29 = V_189 & V_6 -> V_37 ;
while ( 1 ) {
if ( V_58 -> V_65 == V_180 )
V_8 = V_6 -> V_140 . V_214 ( V_2 , V_6 , V_29 ) ;
else
V_8 = V_6 -> V_140 . V_215 ( V_2 , V_6 , V_29 ) ;
if ( V_8 < 0 )
break;
V_4 = F_67 ( V_4 , V_164 ) ;
V_24 = F_63 ( V_6 , V_24 , V_58 , V_4 ) ;
V_164 -= V_4 ;
if ( ! V_164 )
break;
V_189 ++ ;
V_29 = V_189 & V_6 -> V_37 ;
if ( ! V_29 ) {
V_20 ++ ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
}
}
V_58 -> V_204 = V_58 -> V_64 - V_164 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_68 . V_161 - V_193 . V_161 )
return - V_205 ;
return V_2 -> V_68 . V_162 - V_193 . V_162 ? - V_216 : 0 ;
}
static int F_75 ( struct V_1 * V_2 , T_1 V_188 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = - V_217 ;
V_58 -> V_203 = 0 ;
if ( V_58 -> V_61 && ( V_188 + V_58 -> V_4 ) > V_2 -> V_129 ) {
F_2 ( L_8 ,
V_10 ) ;
return - V_11 ;
}
F_22 ( V_6 , V_2 , V_39 ) ;
switch ( V_58 -> V_65 ) {
case V_66 :
case V_181 :
case V_180 :
break;
default:
goto V_131;
}
if ( ! V_58 -> V_61 )
V_8 = F_74 ( V_2 , V_188 , V_58 ) ;
else
V_8 = F_66 ( V_2 , V_188 , V_58 ) ;
V_131:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_24 , int V_135 )
{
V_6 -> V_209 ( V_2 , V_24 , V_2 -> V_35 ) ;
if ( V_135 )
V_6 -> V_209 ( V_2 , V_6 -> V_137 , V_2 -> V_138 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_24 , int V_135 )
{
int V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
T_3 * V_143 = V_6 -> V_137 ;
int V_144 , V_129 ;
for ( V_144 = V_6 -> V_140 . V_144 ; V_144 > 0 ; V_144 -- ) {
V_6 -> V_209 ( V_2 , V_24 , V_139 ) ;
V_24 += V_139 ;
if ( V_6 -> V_140 . V_145 ) {
V_6 -> V_209 ( V_2 , V_143 , V_6 -> V_140 . V_145 ) ;
V_143 += V_6 -> V_140 . V_145 ;
}
V_6 -> V_136 ( V_2 , V_143 , V_141 ) ;
V_143 += V_141 ;
if ( V_6 -> V_140 . V_146 ) {
V_6 -> V_209 ( V_2 , V_143 , V_6 -> V_140 . V_146 ) ;
V_143 += V_6 -> V_140 . V_146 ;
}
}
V_129 = V_2 -> V_138 - ( V_143 - V_6 -> V_137 ) ;
if ( V_129 )
V_6 -> V_209 ( V_2 , V_143 , V_129 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_24 , int V_135 )
{
int V_25 , V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
int V_147 = V_6 -> V_140 . V_144 ;
T_3 * V_148 = V_6 -> V_149 -> V_150 ;
const T_3 * V_27 = V_24 ;
T_7 * V_153 = V_6 -> V_140 . V_154 -> V_153 ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 )
V_6 -> V_140 . V_157 ( V_2 , V_27 , & V_148 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_140 . V_158 ; V_25 ++ )
V_6 -> V_137 [ V_153 [ V_25 ] ] = V_148 [ V_25 ] ;
return V_6 -> V_140 . V_218 ( V_2 , V_6 , V_24 , 1 ) ;
}
static int F_79 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_24 , int V_135 )
{
int V_25 , V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
int V_147 = V_6 -> V_140 . V_144 ;
T_3 * V_148 = V_6 -> V_149 -> V_150 ;
const T_3 * V_27 = V_24 ;
T_7 * V_153 = V_6 -> V_140 . V_154 -> V_153 ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 ) {
V_6 -> V_140 . V_177 ( V_2 , V_219 ) ;
V_6 -> V_209 ( V_2 , V_27 , V_139 ) ;
V_6 -> V_140 . V_157 ( V_2 , V_27 , & V_148 [ V_25 ] ) ;
}
for ( V_25 = 0 ; V_25 < V_6 -> V_140 . V_158 ; V_25 ++ )
V_6 -> V_137 [ V_153 [ V_25 ] ] = V_148 [ V_25 ] ;
V_6 -> V_209 ( V_2 , V_6 -> V_137 , V_2 -> V_138 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_24 , int V_135 )
{
int V_25 , V_139 = V_6 -> V_140 . V_129 ;
int V_141 = V_6 -> V_140 . V_142 ;
int V_147 = V_6 -> V_140 . V_144 ;
const T_3 * V_27 = V_24 ;
T_3 * V_143 = V_6 -> V_137 ;
for ( V_25 = 0 ; V_147 ; V_147 -- , V_25 += V_141 , V_27 += V_139 ) {
V_6 -> V_140 . V_177 ( V_2 , V_219 ) ;
V_6 -> V_209 ( V_2 , V_27 , V_139 ) ;
if ( V_6 -> V_140 . V_145 ) {
V_6 -> V_209 ( V_2 , V_143 , V_6 -> V_140 . V_145 ) ;
V_143 += V_6 -> V_140 . V_145 ;
}
V_6 -> V_140 . V_157 ( V_2 , V_27 , V_143 ) ;
V_6 -> V_209 ( V_2 , V_143 , V_141 ) ;
V_143 += V_141 ;
if ( V_6 -> V_140 . V_146 ) {
V_6 -> V_209 ( V_2 , V_143 , V_6 -> V_140 . V_146 ) ;
V_143 += V_6 -> V_140 . V_146 ;
}
}
V_25 = V_2 -> V_138 - ( V_143 - V_6 -> V_137 ) ;
if ( V_25 )
V_6 -> V_209 ( V_2 , V_143 , V_25 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_24 , int V_135 , int V_29 ,
int V_220 , int V_221 )
{
int V_119 ;
V_6 -> V_42 ( V_2 , V_87 , 0x00 , V_29 ) ;
if ( F_64 ( V_221 ) )
V_119 = V_6 -> V_140 . V_218 ( V_2 , V_6 , V_24 , V_135 ) ;
else
V_119 = V_6 -> V_140 . V_222 ( V_2 , V_6 , V_24 , V_135 ) ;
if ( V_119 < 0 )
return V_119 ;
V_220 = 0 ;
if ( ! V_220 || ! ( V_6 -> V_40 & V_223 ) ) {
V_6 -> V_42 ( V_2 , V_94 , - 1 , - 1 ) ;
V_119 = V_6 -> V_127 ( V_2 , V_6 ) ;
if ( ( V_119 & V_210 ) && ( V_6 -> V_224 ) )
V_119 = V_6 -> V_224 ( V_2 , V_6 , V_60 , V_119 ,
V_29 ) ;
if ( V_119 & V_210 )
return - V_128 ;
} else {
V_6 -> V_42 ( V_2 , V_102 , - 1 , - 1 ) ;
V_119 = V_6 -> V_127 ( V_2 , V_6 ) ;
}
return 0 ;
}
static T_3 * F_82 ( struct V_1 * V_2 , T_3 * V_143 , T_8 V_4 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
memset ( V_6 -> V_137 , 0xff , V_2 -> V_138 ) ;
switch ( V_58 -> V_65 ) {
case V_66 :
case V_180 :
memcpy ( V_6 -> V_137 + V_58 -> V_63 , V_143 , V_4 ) ;
return V_143 + V_4 ;
case V_181 : {
struct V_182 * free = V_6 -> V_140 . V_154 -> V_183 ;
T_7 V_184 = 0 , V_225 = V_58 -> V_63 ;
T_8 V_142 = 0 ;
for (; free -> V_186 && V_4 ; free ++ , V_4 -= V_142 ) {
if ( F_64 ( V_225 ) ) {
if ( V_225 >= free -> V_186 ) {
V_225 -= free -> V_186 ;
continue;
}
V_184 = free -> V_187 + V_225 ;
V_142 = F_65 ( T_8 , V_4 ,
( free -> V_186 - V_225 ) ) ;
V_225 = 0 ;
} else {
V_142 = F_65 ( T_8 , V_4 , free -> V_186 ) ;
V_184 = free -> V_187 ;
}
memcpy ( V_6 -> V_137 + V_184 , V_143 , V_142 ) ;
V_143 += V_142 ;
}
return V_143 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_226 ,
struct V_57 * V_58 )
{
int V_20 , V_189 , V_29 , V_227 , V_83 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_7 V_228 = V_58 -> V_4 ;
T_7 V_229 = V_58 -> V_64 ;
T_7 V_230 = V_58 -> V_65 == V_181 ?
V_2 -> V_196 : V_2 -> V_138 ;
T_3 * V_143 = V_58 -> V_62 ;
T_3 * V_24 = V_58 -> V_61 ;
int V_8 , V_231 ;
int V_135 = V_143 ? 1 : 0 ;
V_58 -> V_203 = 0 ;
if ( ! V_228 )
return 0 ;
if ( F_84 ( V_226 ) || F_84 ( V_58 -> V_4 ) ) {
F_85 ( L_9 ,
V_10 ) ;
return - V_11 ;
}
V_83 = V_226 & ( V_2 -> V_35 - 1 ) ;
V_231 = V_83 || ( V_228 & ( V_2 -> V_35 - 1 ) ) ;
if ( V_231 && V_143 )
return - V_11 ;
V_20 = ( int ) ( V_226 >> V_6 -> V_38 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( F_29 ( V_2 ) )
return - V_128 ;
V_189 = ( int ) ( V_226 >> V_6 -> V_36 ) ;
V_29 = V_189 & V_6 -> V_37 ;
V_227 = ( 1 << ( V_6 -> V_9 - V_6 -> V_36 ) ) - 1 ;
if ( V_226 <= ( V_6 -> V_197 << V_6 -> V_36 ) &&
( V_6 -> V_197 << V_6 -> V_36 ) < ( V_226 + V_58 -> V_4 ) )
V_6 -> V_197 = - 1 ;
if ( V_143 && V_58 -> V_63 && ( V_58 -> V_63 + V_58 -> V_64 > V_230 ) )
return - V_11 ;
while ( 1 ) {
int V_142 = V_2 -> V_35 ;
int V_220 = V_228 > V_142 && V_29 != V_227 ;
T_3 * V_232 = V_24 ;
if ( F_64 ( V_83 || V_228 < ( V_2 -> V_35 - 1 ) ) ) {
V_220 = 0 ;
V_142 = F_65 ( int , V_142 - V_83 , ( int ) V_228 ) ;
V_6 -> V_197 = - 1 ;
memset ( V_6 -> V_149 -> V_198 , 0xff , V_2 -> V_35 ) ;
memcpy ( & V_6 -> V_149 -> V_198 [ V_83 ] , V_24 , V_142 ) ;
V_232 = V_6 -> V_149 -> V_198 ;
}
if ( F_64 ( V_143 ) ) {
T_8 V_4 = F_67 ( V_229 , V_230 ) ;
V_143 = F_82 ( V_2 , V_143 , V_4 , V_58 ) ;
V_229 -= V_4 ;
} else {
memset ( V_6 -> V_137 , 0xff , V_2 -> V_138 ) ;
}
V_8 = V_6 -> V_222 ( V_2 , V_6 , V_232 , V_135 , V_29 ,
V_220 , ( V_58 -> V_65 == V_180 ) ) ;
if ( V_8 )
break;
V_228 -= V_142 ;
if ( ! V_228 )
break;
V_83 = 0 ;
V_24 += V_142 ;
V_189 ++ ;
V_29 = V_189 & V_6 -> V_37 ;
if ( ! V_29 ) {
V_20 ++ ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
}
}
V_58 -> V_203 = V_58 -> V_4 - V_228 ;
if ( F_64 ( V_143 ) )
V_58 -> V_204 = V_58 -> V_64 ;
return V_8 ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_226 , T_8 V_4 ,
T_8 * V_203 , const T_3 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_57 V_58 ;
int V_8 ;
F_49 ( V_2 , V_6 , 400 ) ;
F_43 ( V_6 , V_2 , V_60 ) ;
V_58 . V_4 = V_4 ;
V_58 . V_61 = ( T_3 * ) V_24 ;
V_58 . V_62 = NULL ;
V_58 . V_65 = V_66 ;
V_8 = F_83 ( V_2 , V_226 , & V_58 ) ;
* V_203 = V_58 . V_203 ;
return V_8 ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_226 , T_8 V_4 ,
T_8 * V_203 , const T_3 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_57 V_58 ;
int V_8 ;
F_22 ( V_6 , V_2 , V_60 ) ;
V_58 . V_4 = V_4 ;
V_58 . V_61 = ( T_3 * ) V_24 ;
V_58 . V_62 = NULL ;
V_58 . V_65 = V_66 ;
V_8 = F_83 ( V_2 , V_226 , & V_58 ) ;
* V_203 = V_58 . V_203 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_226 ,
struct V_57 * V_58 )
{
int V_20 , V_29 , V_119 , V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_10 ,
V_10 , ( unsigned int ) V_226 , ( int ) V_58 -> V_64 ) ;
if ( V_58 -> V_65 == V_181 )
V_4 = V_6 -> V_140 . V_154 -> V_196 ;
else
V_4 = V_2 -> V_138 ;
if ( ( V_58 -> V_63 + V_58 -> V_64 ) > V_4 ) {
F_2 ( L_11 ,
V_10 ) ;
return - V_11 ;
}
if ( F_64 ( V_58 -> V_63 >= V_4 ) ) {
F_2 ( L_12 ,
V_10 ) ;
return - V_11 ;
}
if ( F_64 ( V_226 >= V_2 -> V_129 ||
V_58 -> V_63 + V_58 -> V_64 >
( ( V_2 -> V_129 >> V_6 -> V_36 ) -
( V_226 >> V_6 -> V_36 ) ) * V_4 ) ) {
F_2 ( L_13 ,
V_10 ) ;
return - V_11 ;
}
V_20 = ( int ) ( V_226 >> V_6 -> V_38 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
V_29 = ( int ) ( V_226 >> V_6 -> V_36 ) ;
V_6 -> V_42 ( V_2 , V_97 , - 1 , - 1 ) ;
if ( F_29 ( V_2 ) )
return - V_233 ;
if ( V_29 == V_6 -> V_197 )
V_6 -> V_197 = - 1 ;
F_82 ( V_2 , V_58 -> V_62 , V_58 -> V_64 , V_58 ) ;
if ( V_58 -> V_65 == V_180 )
V_119 = V_6 -> V_140 . V_234 ( V_2 , V_6 , V_29 & V_6 -> V_37 ) ;
else
V_119 = V_6 -> V_140 . V_50 ( V_2 , V_6 , V_29 & V_6 -> V_37 ) ;
if ( V_119 )
return V_119 ;
V_58 -> V_204 = V_58 -> V_64 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , T_1 V_226 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = - V_217 ;
V_58 -> V_203 = 0 ;
if ( V_58 -> V_61 && ( V_226 + V_58 -> V_4 ) > V_2 -> V_129 ) {
F_2 ( L_13 ,
V_10 ) ;
return - V_11 ;
}
F_22 ( V_6 , V_2 , V_60 ) ;
switch ( V_58 -> V_65 ) {
case V_66 :
case V_181 :
case V_180 :
break;
default:
goto V_131;
}
if ( ! V_58 -> V_61 )
V_8 = F_27 ( V_2 , V_226 , V_58 ) ;
else
V_8 = F_83 ( V_2 , V_226 , V_58 ) ;
V_131:
F_3 ( V_2 ) ;
return V_8 ;
}
static void F_89 ( struct V_1 * V_2 , int V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_42 ( V_2 , V_95 , - 1 , V_29 ) ;
V_6 -> V_42 ( V_2 , V_96 , - 1 , - 1 ) ;
}
static void F_90 ( struct V_1 * V_2 , int V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_42 ( V_2 , V_95 , - 1 , V_29 ++ ) ;
V_6 -> V_42 ( V_2 , V_95 , - 1 , V_29 ++ ) ;
V_6 -> V_42 ( V_2 , V_95 , - 1 , V_29 ++ ) ;
V_6 -> V_42 ( V_2 , V_95 , - 1 , V_29 ) ;
V_6 -> V_42 ( V_2 , V_96 , - 1 , - 1 ) ;
}
static int F_91 ( struct V_1 * V_2 , struct V_52 * V_235 )
{
return F_26 ( V_2 , V_235 , 0 ) ;
}
int F_26 ( struct V_1 * V_2 , struct V_52 * V_235 ,
int V_73 )
{
int V_29 , V_119 , V_236 , V_8 , V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_237 [ V_238 ] = { 0 } ;
unsigned int V_239 = 0xffffffff ;
T_1 V_4 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_235 -> V_54 ,
( unsigned long long ) V_235 -> V_4 ) ;
if ( F_1 ( V_2 , V_235 -> V_54 , V_235 -> V_4 ) )
return - V_11 ;
F_22 ( V_6 , V_2 , V_120 ) ;
V_29 = ( int ) ( V_235 -> V_54 >> V_6 -> V_36 ) ;
V_20 = ( int ) ( V_235 -> V_54 >> V_6 -> V_38 ) ;
V_236 = 1 << ( V_6 -> V_9 - V_6 -> V_36 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( F_29 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_235 -> V_16 = V_133 ;
goto V_240;
}
if ( V_6 -> V_40 & V_241 && ! V_73 )
V_239 = V_6 -> V_242 -> V_243 [ V_20 ] & V_244 ;
V_4 = V_235 -> V_4 ;
V_235 -> V_16 = V_245 ;
while ( V_4 ) {
if ( F_30 ( V_2 , ( ( T_1 ) V_29 ) <<
V_6 -> V_36 , 0 , V_73 ) ) {
F_92 ( L_14 ,
V_10 , V_29 ) ;
V_235 -> V_16 = V_133 ;
goto V_240;
}
if ( V_29 <= V_6 -> V_197 && V_6 -> V_197 <
( V_29 + V_236 ) )
V_6 -> V_197 = - 1 ;
V_6 -> V_246 ( V_2 , V_29 & V_6 -> V_37 ) ;
V_119 = V_6 -> V_127 ( V_2 , V_6 ) ;
if ( ( V_119 & V_210 ) && ( V_6 -> V_224 ) )
V_119 = V_6 -> V_224 ( V_2 , V_6 , V_120 ,
V_119 , V_29 ) ;
if ( V_119 & V_210 ) {
F_2 ( L_15 ,
V_10 , V_29 ) ;
V_235 -> V_16 = V_133 ;
V_235 -> V_247 =
( ( T_1 ) V_29 << V_6 -> V_36 ) ;
goto V_240;
}
if ( V_239 != 0xffffffff &&
( V_29 & V_244 ) == V_239 )
V_237 [ V_20 ] =
( ( T_1 ) V_29 << V_6 -> V_36 ) ;
V_4 -= ( 1 << V_6 -> V_9 ) ;
V_29 += V_236 ;
if ( V_4 && ! ( V_29 & V_6 -> V_37 ) ) {
V_20 ++ ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( V_239 != 0xffffffff &&
( V_6 -> V_242 -> V_40 & V_248 ) )
V_239 = V_6 -> V_242 -> V_243 [ V_20 ] &
V_244 ;
}
}
V_235 -> V_16 = V_249 ;
V_240:
V_8 = V_235 -> V_16 == V_249 ? 0 : - V_128 ;
F_3 ( V_2 ) ;
if ( ! V_8 )
F_93 ( V_235 ) ;
if ( V_239 == 0xffffffff || V_8 )
return V_8 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_250 ; V_20 ++ ) {
if ( ! V_237 [ V_20 ] )
continue;
F_2 ( L_16 ,
V_10 , V_20 , V_237 [ V_20 ] ,
V_6 -> V_242 -> V_243 [ V_20 ] ) ;
F_28 ( V_2 , V_237 [ V_20 ] ) ;
}
return V_8 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_17 , V_10 ) ;
F_22 ( V_6 , V_2 , V_251 ) ;
F_3 ( V_2 ) ;
}
static int F_95 ( struct V_1 * V_2 , T_1 V_252 )
{
return F_30 ( V_2 , V_252 , 1 , 0 ) ;
}
static int F_96 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_95 ( V_2 , V_3 ) ;
if ( V_8 ) {
if ( V_8 > 0 )
return 0 ;
return V_8 ;
}
return V_6 -> V_253 ( V_2 , V_3 ) ;
}
static int F_97 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_54 , T_3 * V_254 )
{
int V_119 ;
if ( ! V_6 -> V_255 )
return - V_11 ;
V_6 -> V_42 ( V_2 , V_256 , V_54 , - 1 ) ;
V_6 -> V_209 ( V_2 , V_254 , V_257 ) ;
V_119 = V_6 -> V_127 ( V_2 , V_6 ) ;
if ( V_119 & V_210 )
return - V_128 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_54 , T_3 * V_254 )
{
if ( ! V_6 -> V_255 )
return - V_11 ;
memset ( V_254 , 0 , V_257 ) ;
V_6 -> V_42 ( V_2 , V_258 , V_54 , - 1 ) ;
V_6 -> V_136 ( V_2 , V_254 , V_257 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_22 ( V_6 , V_2 , V_117 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_16 == V_117 )
F_3 ( V_2 ) ;
else
F_101 ( L_18 ,
V_10 ) ;
}
static void F_102 ( struct V_5 * V_6 , int V_175 )
{
if ( ! V_6 -> V_98 )
V_6 -> V_98 = 20 ;
if ( V_6 -> V_42 == NULL )
V_6 -> V_42 = F_39 ;
if ( V_6 -> V_127 == NULL )
V_6 -> V_127 = F_50 ;
if ( ! V_6 -> V_12 )
V_6 -> V_12 = F_13 ;
if ( ! V_6 -> V_46 )
V_6 -> V_46 = V_175 ? F_9 : F_7 ;
if ( ! V_6 -> V_45 )
V_6 -> V_45 = F_12 ;
if ( ! V_6 -> V_74 )
V_6 -> V_74 = F_21 ;
if ( ! V_6 -> V_253 )
V_6 -> V_253 = F_25 ;
if ( ! V_6 -> V_209 )
V_6 -> V_209 = V_175 ? F_18 : F_15 ;
if ( ! V_6 -> V_136 )
V_6 -> V_136 = V_175 ? F_20 : F_17 ;
if ( ! V_6 -> V_259 )
V_6 -> V_259 = V_260 ;
if ( ! V_6 -> V_13 ) {
V_6 -> V_13 = & V_6 -> V_261 ;
F_103 ( & V_6 -> V_13 -> V_14 ) ;
F_104 ( & V_6 -> V_13 -> V_18 ) ;
}
}
static void F_105 ( T_3 * V_262 , T_8 V_4 )
{
T_9 V_25 ;
V_262 [ V_4 - 1 ] = 0 ;
for ( V_25 = 0 ; V_25 < V_4 - 1 ; V_25 ++ ) {
if ( V_262 [ V_25 ] < ' ' || V_262 [ V_25 ] > 127 )
V_262 [ V_25 ] = '?' ;
}
F_106 ( V_262 ) ;
}
static T_4 F_107 ( T_4 V_263 , T_10 const * V_27 , T_8 V_4 )
{
int V_25 ;
while ( V_4 -- ) {
V_263 ^= * V_27 ++ << 8 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
V_263 = ( V_263 << 1 ) ^ ( ( V_263 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_263 ;
}
static int F_108 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_175 )
{
struct V_264 * V_27 = & V_6 -> V_265 ;
int V_25 ;
int V_266 ;
V_6 -> V_42 ( V_2 , V_267 , 0x20 , - 1 ) ;
if ( V_6 -> V_46 ( V_2 ) != 'O' || V_6 -> V_46 ( V_2 ) != 'N' ||
V_6 -> V_46 ( V_2 ) != 'F' || V_6 -> V_46 ( V_2 ) != 'I' )
return 0 ;
V_6 -> V_42 ( V_2 , V_268 , 0 , - 1 ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
V_6 -> V_136 ( V_2 , ( T_3 * ) V_27 , sizeof( * V_27 ) ) ;
if ( F_107 ( V_269 , ( T_3 * ) V_27 , 254 ) ==
F_109 ( V_27 -> V_263 ) ) {
F_110 ( L_19 , V_25 ) ;
break;
}
}
if ( V_25 == 3 )
return 0 ;
V_266 = F_109 ( V_27 -> V_270 ) ;
if ( V_266 & ( 1 << 5 ) )
V_6 -> V_255 = 23 ;
else if ( V_266 & ( 1 << 4 ) )
V_6 -> V_255 = 22 ;
else if ( V_266 & ( 1 << 3 ) )
V_6 -> V_255 = 21 ;
else if ( V_266 & ( 1 << 2 ) )
V_6 -> V_255 = 20 ;
else if ( V_266 & ( 1 << 1 ) )
V_6 -> V_255 = 10 ;
else
V_6 -> V_255 = 0 ;
if ( ! V_6 -> V_255 ) {
F_110 ( L_20 , V_10 , V_266 ) ;
return 0 ;
}
F_105 ( V_27 -> V_271 , sizeof( V_27 -> V_271 ) ) ;
F_105 ( V_27 -> V_272 , sizeof( V_27 -> V_272 ) ) ;
if ( ! V_2 -> V_273 )
V_2 -> V_273 = V_27 -> V_272 ;
V_2 -> V_35 = F_111 ( V_27 -> V_274 ) ;
V_2 -> V_34 = F_111 ( V_27 -> V_236 ) * V_2 -> V_35 ;
V_2 -> V_138 = F_109 ( V_27 -> V_275 ) ;
V_6 -> V_92 = F_111 ( V_27 -> V_276 ) ;
V_6 -> V_92 *= ( T_2 ) V_2 -> V_34 * V_27 -> V_277 ;
* V_175 = 0 ;
if ( F_109 ( V_27 -> V_278 ) & 1 )
* V_175 = V_41 ;
F_110 ( L_21 ) ;
return 1 ;
}
static int F_112 ( T_10 * V_279 , int V_280 , int V_281 )
{
int V_25 , V_282 ;
for ( V_25 = 0 ; V_25 < V_281 ; V_25 ++ )
for ( V_282 = V_25 + V_281 ; V_282 < V_280 ; V_282 += V_281 )
if ( V_279 [ V_25 ] != V_279 [ V_282 ] )
return 0 ;
return 1 ;
}
static int F_113 ( T_10 * V_279 , int V_280 )
{
int V_283 , V_281 ;
for ( V_283 = V_280 - 1 ; V_283 >= 0 ; V_283 -- )
if ( V_279 [ V_283 ] )
break;
if ( V_283 < 0 )
return 0 ;
for ( V_281 = 1 ; V_281 < V_280 ; V_281 ++ )
if ( F_112 ( V_279 , V_280 , V_281 ) )
break;
if ( V_281 < V_280 )
return V_281 ;
if ( V_283 < V_280 - 1 )
return V_283 + 1 ;
return V_280 ;
}
static void F_114 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_10 V_279 [ 8 ] , int * V_175 )
{
int V_284 , V_285 ;
V_6 -> V_286 = V_279 [ 2 ] ;
V_284 = V_279 [ 3 ] ;
V_285 = F_113 ( V_279 , 8 ) ;
if ( V_285 == 6 && V_279 [ 0 ] == V_287 &&
( V_6 -> V_286 & V_288 ) &&
V_279 [ 5 ] != 0x00 ) {
V_2 -> V_35 = 2048 << ( V_284 & 0x03 ) ;
V_284 >>= 2 ;
switch ( ( ( V_284 >> 2 ) & 0x04 ) | ( V_284 & 0x03 ) ) {
case 1 :
V_2 -> V_138 = 128 ;
break;
case 2 :
V_2 -> V_138 = 218 ;
break;
case 3 :
V_2 -> V_138 = 400 ;
break;
case 4 :
V_2 -> V_138 = 436 ;
break;
case 5 :
V_2 -> V_138 = 512 ;
break;
case 6 :
default:
V_2 -> V_138 = 640 ;
break;
}
V_284 >>= 2 ;
V_2 -> V_34 = ( 128 * 1024 ) <<
( ( ( V_284 >> 1 ) & 0x04 ) | ( V_284 & 0x03 ) ) ;
* V_175 = 0 ;
} else if ( V_285 == 6 && V_279 [ 0 ] == V_289 &&
( V_6 -> V_286 & V_288 ) ) {
unsigned int V_290 ;
V_2 -> V_35 = 2048 << ( V_284 & 0x03 ) ;
V_284 >>= 2 ;
switch ( ( ( V_284 >> 2 ) & 0x04 ) | ( V_284 & 0x03 ) ) {
case 0 :
V_2 -> V_138 = 128 ;
break;
case 1 :
V_2 -> V_138 = 224 ;
break;
case 2 :
V_2 -> V_138 = 448 ;
break;
case 3 :
V_2 -> V_138 = 64 ;
break;
case 4 :
V_2 -> V_138 = 32 ;
break;
case 5 :
V_2 -> V_138 = 16 ;
break;
default:
V_2 -> V_138 = 640 ;
break;
}
V_284 >>= 2 ;
V_290 = ( ( V_284 >> 1 ) & 0x04 ) | ( V_284 & 0x03 ) ;
if ( V_290 < 0x03 )
V_2 -> V_34 = ( 128 * 1024 ) << V_290 ;
else if ( V_290 == 0x03 )
V_2 -> V_34 = 768 * 1024 ;
else
V_2 -> V_34 = ( 64 * 1024 ) << V_290 ;
* V_175 = 0 ;
} else {
V_2 -> V_35 = 1024 << ( V_284 & 0x03 ) ;
V_284 >>= 2 ;
V_2 -> V_138 = ( 8 << ( V_284 & 0x01 ) ) *
( V_2 -> V_35 >> 9 ) ;
V_284 >>= 2 ;
V_2 -> V_34 = ( 64 * 1024 ) << ( V_284 & 0x03 ) ;
V_284 >>= 2 ;
* V_175 = ( V_284 & 0x01 ) ? V_41 : 0 ;
}
}
static void F_115 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_291 * type , T_10 V_279 [ 8 ] ,
int * V_175 )
{
int V_292 = V_279 [ 0 ] ;
V_2 -> V_34 = type -> V_34 ;
V_2 -> V_35 = type -> V_293 ;
V_2 -> V_138 = V_2 -> V_35 / 32 ;
* V_175 = type -> V_40 & V_41 ;
if ( V_292 == V_294 && V_279 [ 4 ] != 0x00 && V_279 [ 5 ] == 0x00
&& V_279 [ 6 ] == 0x00 && V_279 [ 7 ] == 0x00
&& V_2 -> V_35 == 512 ) {
V_2 -> V_34 = 128 * 1024 ;
V_2 -> V_34 <<= ( ( V_279 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_116 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_10 V_279 [ 8 ] )
{
int V_292 = V_279 [ 0 ] ;
if ( V_2 -> V_35 > 512 || ( V_6 -> V_40 & V_41 ) )
V_6 -> V_44 = V_295 ;
else
V_6 -> V_44 = V_296 ;
if ( ( V_6 -> V_286 & V_288 ) &&
( V_292 == V_287 ||
V_292 == V_289 ) )
V_6 -> V_32 |= V_33 ;
else if ( ( ! ( V_6 -> V_286 & V_288 ) &&
( V_292 == V_287 ||
V_292 == V_289 ||
V_292 == V_297 ||
V_292 == V_294 ||
V_292 == V_298 ) ) ||
( V_2 -> V_35 == 2048 &&
V_292 == V_299 ) )
V_6 -> V_32 |= V_48 ;
}
static struct V_291 * F_117 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int V_175 ,
int * V_292 , int * V_300 ,
struct V_291 * type )
{
int V_25 , V_301 ;
T_10 V_279 [ 8 ] ;
V_6 -> V_12 ( V_2 , 0 ) ;
V_6 -> V_42 ( V_2 , V_97 , - 1 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_267 , 0x00 , - 1 ) ;
* V_292 = V_6 -> V_46 ( V_2 ) ;
* V_300 = V_6 -> V_46 ( V_2 ) ;
V_6 -> V_42 ( V_2 , V_267 , 0x00 , - 1 ) ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
V_279 [ V_25 ] = V_6 -> V_46 ( V_2 ) ;
if ( V_279 [ 0 ] != * V_292 || V_279 [ 1 ] != * V_300 ) {
F_110 ( L_22
L_23 , V_10 ,
* V_292 , * V_300 , V_279 [ 0 ] , V_279 [ 1 ] ) ;
return F_118 ( - V_302 ) ;
}
if ( ! type )
type = V_303 ;
for (; type -> V_273 != NULL ; type ++ )
if ( * V_300 == type -> V_304 )
break;
V_6 -> V_255 = 0 ;
if ( ! type -> V_273 || ! type -> V_293 ) {
if ( F_108 ( V_2 , V_6 , & V_175 ) )
goto V_305;
}
if ( ! type -> V_273 )
return F_118 ( - V_302 ) ;
if ( ! V_2 -> V_273 )
V_2 -> V_273 = type -> V_273 ;
V_6 -> V_92 = ( T_2 ) type -> V_92 << 20 ;
if ( ! type -> V_293 && V_6 -> V_306 ) {
V_175 = V_6 -> V_306 ( V_2 , V_6 , V_279 ) ;
} else if ( ! type -> V_293 ) {
F_114 ( V_2 , V_6 , V_279 , & V_175 ) ;
} else {
F_115 ( V_2 , V_6 , type , V_279 , & V_175 ) ;
}
V_6 -> V_40 |= type -> V_40 ;
if ( * V_292 != V_287 && ! type -> V_293 )
V_6 -> V_40 &= ~ V_307 ;
V_305:
for ( V_301 = 0 ; V_308 [ V_301 ] . V_304 != 0x0 ; V_301 ++ ) {
if ( V_308 [ V_301 ] . V_304 == * V_292 )
break;
}
if ( V_175 != ( V_6 -> V_40 & V_41 ) ) {
F_110 ( L_24
L_25 , * V_292 ,
* V_300 , V_308 [ V_301 ] . V_273 , V_2 -> V_273 ) ;
F_92 ( L_26 ,
( V_6 -> V_40 & V_41 ) ? 16 : 8 ,
V_175 ? 16 : 8 ) ;
return F_118 ( - V_11 ) ;
}
F_116 ( V_2 , V_6 , V_279 ) ;
V_6 -> V_36 = F_119 ( V_2 -> V_35 ) - 1 ;
V_6 -> V_37 = ( V_6 -> V_92 >> V_6 -> V_36 ) - 1 ;
V_6 -> V_55 = V_6 -> V_9 =
F_119 ( V_2 -> V_34 ) - 1 ;
if ( V_6 -> V_92 & 0xffffffff )
V_6 -> V_38 = F_119 ( ( unsigned ) V_6 -> V_92 ) - 1 ;
else {
V_6 -> V_38 = F_119 ( ( unsigned ) ( V_6 -> V_92 >> 32 ) ) ;
V_6 -> V_38 += 32 - 1 ;
}
V_6 -> V_47 = 8 ;
if ( V_6 -> V_40 & V_309 )
V_6 -> V_246 = F_90 ;
else
V_6 -> V_246 = F_89 ;
if ( V_2 -> V_35 > 512 && V_6 -> V_42 == F_39 )
V_6 -> V_42 = F_42 ;
F_110 ( L_27
L_28 ,
* V_292 , * V_300 , V_308 [ V_301 ] . V_273 ,
V_6 -> V_255 ? V_6 -> V_265 . V_272 : type -> V_273 ,
V_2 -> V_35 , V_2 -> V_138 ) ;
return type ;
}
int F_120 ( struct V_1 * V_2 , int V_310 ,
struct V_291 * V_311 )
{
int V_25 , V_175 , V_312 , V_313 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_291 * type ;
V_175 = V_6 -> V_40 & V_41 ;
F_102 ( V_6 , V_175 ) ;
type = F_117 ( V_2 , V_6 , V_175 ,
& V_312 , & V_313 , V_311 ) ;
if ( F_121 ( type ) ) {
if ( ! ( V_6 -> V_40 & V_314 ) )
F_92 ( L_29 ) ;
V_6 -> V_12 ( V_2 , - 1 ) ;
return F_122 ( type ) ;
}
for ( V_25 = 1 ; V_25 < V_310 ; V_25 ++ ) {
V_6 -> V_12 ( V_2 , V_25 ) ;
V_6 -> V_42 ( V_2 , V_97 , - 1 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_267 , 0x00 , - 1 ) ;
if ( V_312 != V_6 -> V_46 ( V_2 ) ||
V_313 != V_6 -> V_46 ( V_2 ) )
break;
}
if ( V_25 > 1 )
F_110 ( L_30 , V_25 ) ;
V_6 -> V_250 = V_25 ;
V_2 -> V_129 = V_25 * V_6 -> V_92 ;
return 0 ;
}
int F_123 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_124 ( ( V_6 -> V_32 & V_51 ) &&
! ( V_6 -> V_32 & V_67 ) ) ;
if ( ! ( V_6 -> V_40 & V_315 ) )
V_6 -> V_149 = F_125 ( sizeof( * V_6 -> V_149 ) , V_316 ) ;
if ( ! V_6 -> V_149 )
return - V_317 ;
V_6 -> V_137 = V_6 -> V_149 -> V_198 + V_2 -> V_35 ;
if ( ! V_6 -> V_140 . V_154 && ( V_6 -> V_140 . V_65 != V_318 ) ) {
switch ( V_2 -> V_138 ) {
case 8 :
V_6 -> V_140 . V_154 = & V_319 ;
break;
case 16 :
V_6 -> V_140 . V_154 = & V_320 ;
break;
case 64 :
V_6 -> V_140 . V_154 = & V_321 ;
break;
case 128 :
V_6 -> V_140 . V_154 = & V_322 ;
break;
default:
F_92 ( L_31 ,
V_2 -> V_138 ) ;
F_14 () ;
}
}
if ( ! V_6 -> V_222 )
V_6 -> V_222 = F_81 ;
if ( ! V_6 -> V_323 )
V_6 -> V_323 = F_97 ;
if ( ! V_6 -> V_324 )
V_6 -> V_324 = F_98 ;
switch ( V_6 -> V_140 . V_65 ) {
case V_325 :
if ( ! V_6 -> V_140 . V_157 || ! V_6 -> V_140 . V_160 ||
! V_6 -> V_140 . V_177 ) {
F_92 ( L_32
L_33 ) ;
F_14 () ;
}
if ( ! V_6 -> V_140 . V_200 )
V_6 -> V_140 . V_200 = F_61 ;
case V_326 :
if ( ! V_6 -> V_140 . V_200 )
V_6 -> V_140 . V_200 = F_60 ;
if ( ! V_6 -> V_140 . V_222 )
V_6 -> V_140 . V_222 = F_79 ;
if ( ! V_6 -> V_140 . V_156 )
V_6 -> V_140 . V_156 = F_55 ;
if ( ! V_6 -> V_140 . V_218 )
V_6 -> V_140 . V_218 = F_76 ;
if ( ! V_6 -> V_140 . V_215 )
V_6 -> V_140 . V_215 = F_70 ;
if ( ! V_6 -> V_140 . V_50 )
V_6 -> V_140 . V_50 = F_72 ;
case V_327 :
if ( ( ! V_6 -> V_140 . V_157 || ! V_6 -> V_140 . V_160 ||
! V_6 -> V_140 . V_177 ) &&
( ! V_6 -> V_140 . V_200 ||
V_6 -> V_140 . V_200 == F_60 ||
! V_6 -> V_140 . V_222 ||
V_6 -> V_140 . V_222 == F_79 ) ) {
F_92 ( L_32
L_33 ) ;
F_14 () ;
}
if ( ! V_6 -> V_140 . V_200 )
V_6 -> V_140 . V_200 = F_62 ;
if ( ! V_6 -> V_140 . V_222 )
V_6 -> V_140 . V_222 = F_80 ;
if ( ! V_6 -> V_140 . V_156 )
V_6 -> V_140 . V_156 = F_56 ;
if ( ! V_6 -> V_140 . V_218 )
V_6 -> V_140 . V_218 = F_77 ;
if ( ! V_6 -> V_140 . V_215 )
V_6 -> V_140 . V_215 = F_71 ;
if ( ! V_6 -> V_140 . V_50 )
V_6 -> V_140 . V_50 = F_73 ;
if ( V_2 -> V_35 >= V_6 -> V_140 . V_129 ) {
if ( ! V_6 -> V_140 . V_328 ) {
F_92 ( L_34 ) ;
F_14 () ;
}
break;
}
F_92 ( L_35
L_36 ,
V_6 -> V_140 . V_129 , V_2 -> V_35 ) ;
V_6 -> V_140 . V_65 = V_329 ;
case V_329 :
V_6 -> V_140 . V_157 = V_330 ;
V_6 -> V_140 . V_160 = V_331 ;
V_6 -> V_140 . V_200 = F_57 ;
V_6 -> V_140 . V_199 = F_59 ;
V_6 -> V_140 . V_222 = F_78 ;
V_6 -> V_140 . V_156 = F_55 ;
V_6 -> V_140 . V_218 = F_76 ;
V_6 -> V_140 . V_215 = F_70 ;
V_6 -> V_140 . V_50 = F_72 ;
if ( ! V_6 -> V_140 . V_129 )
V_6 -> V_140 . V_129 = 256 ;
V_6 -> V_140 . V_142 = 3 ;
V_6 -> V_140 . V_328 = 1 ;
break;
case V_318 :
if ( ! F_126 () ) {
F_92 ( L_37 ) ;
F_14 () ;
}
V_6 -> V_140 . V_157 = V_332 ;
V_6 -> V_140 . V_160 = V_333 ;
V_6 -> V_140 . V_200 = F_57 ;
V_6 -> V_140 . V_199 = F_59 ;
V_6 -> V_140 . V_222 = F_78 ;
V_6 -> V_140 . V_156 = F_55 ;
V_6 -> V_140 . V_218 = F_76 ;
V_6 -> V_140 . V_215 = F_70 ;
V_6 -> V_140 . V_50 = F_72 ;
if ( ! V_6 -> V_140 . V_129 && ( V_2 -> V_138 >= 64 ) ) {
V_6 -> V_140 . V_129 = 512 ;
V_6 -> V_140 . V_142 = 7 ;
}
V_6 -> V_140 . V_7 = F_127 ( V_2 ,
V_6 -> V_140 . V_129 ,
V_6 -> V_140 . V_142 ,
& V_6 -> V_140 . V_154 ) ;
if ( ! V_6 -> V_140 . V_7 ) {
F_92 ( L_38 ) ;
F_14 () ;
}
V_6 -> V_140 . V_328 =
V_6 -> V_140 . V_142 * 8 / F_128 ( 8 * V_6 -> V_140 . V_129 ) ;
break;
case V_334 :
F_92 ( L_39
L_40 ) ;
V_6 -> V_140 . V_200 = F_55 ;
V_6 -> V_140 . V_222 = F_76 ;
V_6 -> V_140 . V_215 = F_70 ;
V_6 -> V_140 . V_156 = F_55 ;
V_6 -> V_140 . V_218 = F_76 ;
V_6 -> V_140 . V_50 = F_72 ;
V_6 -> V_140 . V_129 = V_2 -> V_35 ;
V_6 -> V_140 . V_142 = 0 ;
V_6 -> V_140 . V_328 = 0 ;
break;
default:
F_92 ( L_41 , V_6 -> V_140 . V_65 ) ;
F_14 () ;
}
if ( ! V_6 -> V_140 . V_214 )
V_6 -> V_140 . V_214 = V_6 -> V_140 . V_215 ;
if ( ! V_6 -> V_140 . V_234 )
V_6 -> V_140 . V_234 = V_6 -> V_140 . V_50 ;
V_6 -> V_140 . V_154 -> V_196 = 0 ;
for ( V_25 = 0 ; V_6 -> V_140 . V_154 -> V_183 [ V_25 ] . V_186
&& V_25 < F_129 ( V_6 -> V_140 . V_154 -> V_183 ) ; V_25 ++ )
V_6 -> V_140 . V_154 -> V_196 +=
V_6 -> V_140 . V_154 -> V_183 [ V_25 ] . V_186 ;
V_2 -> V_196 = V_6 -> V_140 . V_154 -> V_196 ;
V_6 -> V_140 . V_144 = V_2 -> V_35 / V_6 -> V_140 . V_129 ;
if ( V_6 -> V_140 . V_144 * V_6 -> V_140 . V_129 != V_2 -> V_35 ) {
F_92 ( L_42 ) ;
F_14 () ;
}
V_6 -> V_140 . V_158 = V_6 -> V_140 . V_144 * V_6 -> V_140 . V_142 ;
if ( ! ( V_6 -> V_40 & V_335 ) &&
! ( V_6 -> V_286 & V_288 ) ) {
switch ( V_6 -> V_140 . V_144 ) {
case 2 :
V_2 -> V_336 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_336 = 2 ;
break;
}
}
V_6 -> V_337 = V_2 -> V_35 >> V_2 -> V_336 ;
V_6 -> V_16 = V_17 ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_197 = - 1 ;
if ( ( V_6 -> V_140 . V_65 == V_329 ) && ( V_6 -> V_36 > 9 ) )
V_6 -> V_40 |= V_338 ;
V_2 -> type = V_339 ;
V_2 -> V_340 = ( V_6 -> V_40 & V_341 ) ? V_342 :
V_343 ;
V_2 -> V_344 = F_91 ;
V_2 -> V_345 = NULL ;
V_2 -> V_346 = NULL ;
V_2 -> V_347 = F_69 ;
V_2 -> V_348 = F_87 ;
V_2 -> V_349 = F_86 ;
V_2 -> V_350 = F_75 ;
V_2 -> V_351 = F_88 ;
V_2 -> V_352 = F_94 ;
V_2 -> V_353 = NULL ;
V_2 -> V_354 = NULL ;
V_2 -> V_355 = F_99 ;
V_2 -> V_356 = F_100 ;
V_2 -> V_357 = F_95 ;
V_2 -> V_358 = F_96 ;
V_2 -> V_359 = V_2 -> V_35 ;
V_2 -> V_360 = V_6 -> V_140 . V_154 ;
V_2 -> V_361 = V_6 -> V_140 . V_328 ;
if ( ! V_2 -> V_362 )
V_2 -> V_362 = V_2 -> V_361 ;
if ( V_6 -> V_40 & V_363 )
return 0 ;
return V_6 -> V_259 ( V_2 ) ;
}
int F_130 ( struct V_1 * V_2 , int V_310 )
{
int V_8 ;
if ( ! V_2 -> V_364 && F_131 () ) {
F_132 ( L_43 , V_10 ) ;
F_14 () ;
}
V_8 = F_120 ( V_2 , V_310 , NULL ) ;
if ( ! V_8 )
V_8 = F_123 ( V_2 ) ;
return V_8 ;
}
void F_133 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_140 . V_65 == V_318 )
F_134 ( (struct V_365 * ) V_6 -> V_140 . V_7 ) ;
F_135 ( V_2 ) ;
F_136 ( V_6 -> V_56 ) ;
if ( ! ( V_6 -> V_40 & V_315 ) )
F_136 ( V_6 -> V_149 ) ;
if ( V_6 -> V_366 && V_6 -> V_366 -> V_40
& V_367 )
F_136 ( V_6 -> V_366 ) ;
}
static int T_11 F_137 ( void )
{
F_138 ( L_44 , & V_79 ) ;
return 0 ;
}
static void T_12 F_139 ( void )
{
F_140 ( V_79 ) ;
}
