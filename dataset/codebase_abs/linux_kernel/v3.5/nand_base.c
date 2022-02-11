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
static int F_18 ( struct V_1 * V_2 , const T_3 * V_24 , int V_4 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ )
if ( V_24 [ V_25 ] != F_8 ( V_6 -> V_19 ) )
return - V_27 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , const T_3 * V_24 , int V_4 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_28 = ( T_4 * ) V_24 ;
V_4 >>= 1 ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ )
F_20 ( V_28 [ V_25 ] , V_6 -> V_26 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_3 * V_24 , int V_4 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_28 = ( T_4 * ) V_24 ;
V_4 >>= 1 ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ )
V_28 [ V_25 ] = F_11 ( V_6 -> V_19 ) ;
}
static int F_22 ( struct V_1 * V_2 , const T_3 * V_24 , int V_4 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_28 = ( T_4 * ) V_24 ;
V_4 >>= 1 ;
for ( V_25 = 0 ; V_25 < V_4 ; V_25 ++ )
if ( V_28 [ V_25 ] != F_11 ( V_6 -> V_19 ) )
return - V_27 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_3 , int V_29 )
{
int V_30 , V_20 , V_31 = 0 , V_25 = 0 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 V_32 ;
if ( V_6 -> V_33 & V_34 )
V_3 += V_2 -> V_35 - V_2 -> V_36 ;
V_30 = ( int ) ( V_3 >> V_6 -> V_37 ) & V_6 -> V_38 ;
if ( V_29 ) {
V_20 = ( int ) ( V_3 >> V_6 -> V_39 ) ;
F_24 ( V_6 , V_2 , V_40 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
}
do {
if ( V_6 -> V_41 & V_42 ) {
V_6 -> V_43 ( V_2 , V_44 ,
V_6 -> V_45 & 0xFE , V_30 ) ;
V_32 = F_10 ( V_6 -> V_46 ( V_2 ) ) ;
if ( V_6 -> V_45 & 0x1 )
V_32 >>= 8 ;
else
V_32 &= 0xFF ;
} else {
V_6 -> V_43 ( V_2 , V_44 , V_6 -> V_45 ,
V_30 ) ;
V_32 = V_6 -> V_47 ( V_2 ) ;
}
if ( F_25 ( V_6 -> V_48 == 8 ) )
V_31 = V_32 != 0xFF ;
else
V_31 = F_26 ( V_32 ) < V_6 -> V_48 ;
V_3 += V_2 -> V_36 ;
V_30 = ( int ) ( V_3 >> V_6 -> V_37 ) & V_6 -> V_38 ;
V_25 ++ ;
} while ( ! V_31 && V_25 < 2 && ( V_6 -> V_33 & V_49 ) );
if ( V_29 )
F_3 ( V_2 ) ;
return V_31 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_24 [ 2 ] = { 0 , 0 } ;
int V_50 , V_31 , V_8 = 0 , V_25 = 0 ;
int V_51 = ! ( V_6 -> V_33 & V_52 ) ;
if ( V_51 ) {
struct V_53 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_2 = V_2 ;
V_54 . V_55 = V_3 ;
V_54 . V_4 = 1 << V_6 -> V_9 ;
F_28 ( V_2 , & V_54 , 0 ) ;
}
V_50 = ( int ) ( V_3 >> V_6 -> V_56 ) ;
if ( V_6 -> V_57 )
V_6 -> V_57 [ V_50 >> 2 ] |= 0x01 << ( ( V_50 & 0x03 ) << 1 ) ;
if ( V_51 ) {
struct V_58 V_59 ;
T_1 V_60 = V_3 ;
F_24 ( V_6 , V_2 , V_61 ) ;
V_59 . V_62 = NULL ;
V_59 . V_63 = V_24 ;
V_59 . V_64 = V_6 -> V_45 ;
if ( V_6 -> V_41 & V_42 ) {
V_59 . V_64 &= ~ 0x01 ;
V_59 . V_4 = V_59 . V_65 = 2 ;
} else {
V_59 . V_4 = V_59 . V_65 = 1 ;
}
V_59 . V_66 = V_67 ;
if ( V_6 -> V_33 & V_34 )
V_60 += V_2 -> V_35 - V_2 -> V_36 ;
do {
V_31 = F_29 ( V_2 , V_60 , & V_59 ) ;
if ( ! V_8 )
V_8 = V_31 ;
V_25 ++ ;
V_60 += V_2 -> V_36 ;
} while ( ( V_6 -> V_33 & V_49 ) && V_25 < 2 );
F_3 ( V_2 ) ;
}
if ( V_6 -> V_33 & V_68 ) {
V_31 = F_30 ( V_2 , V_3 ) ;
if ( ! V_8 )
V_8 = V_31 ;
}
if ( ! V_8 )
V_2 -> V_69 . V_70 ++ ;
return V_8 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_41 & V_71 )
return 0 ;
V_6 -> V_43 ( V_2 , V_72 , - 1 , - 1 ) ;
return ( V_6 -> V_47 ( V_2 ) & V_73 ) ? 0 : 1 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_3 , int V_29 ,
int V_74 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_57 )
return V_6 -> V_75 ( V_2 , V_3 , V_29 ) ;
return F_33 ( V_2 , V_3 , V_74 ) ;
}
static void F_34 ( struct V_1 * V_2 , unsigned long V_76 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_76 ; V_25 ++ ) {
if ( V_6 -> V_77 ( V_2 ) )
break;
F_35 () ;
F_36 ( 1 ) ;
}
}
void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_76 = V_78 + 2 ;
if ( F_38 () || V_79 )
return F_34 ( V_2 , 400 ) ;
F_39 ( V_80 , V_81 ) ;
do {
if ( V_6 -> V_77 ( V_2 ) )
break;
F_35 () ;
} while ( F_40 ( V_78 , V_76 ) );
F_39 ( V_80 , V_82 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_83 ,
int V_84 , int V_85 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
int V_86 = V_87 | V_23 ;
if ( V_83 == V_88 ) {
int V_89 ;
if ( V_84 >= V_2 -> V_36 ) {
V_84 -= V_2 -> V_36 ;
V_89 = V_44 ;
} else if ( V_84 < 256 ) {
V_89 = V_90 ;
} else {
V_84 -= 256 ;
V_89 = V_91 ;
}
V_6 -> V_21 ( V_2 , V_89 , V_86 ) ;
V_86 &= ~ V_23 ;
}
V_6 -> V_21 ( V_2 , V_83 , V_86 ) ;
V_86 = V_92 | V_23 ;
if ( V_84 != - 1 ) {
if ( V_6 -> V_41 & V_42 )
V_84 >>= 1 ;
V_6 -> V_21 ( V_2 , V_84 , V_86 ) ;
V_86 &= ~ V_23 ;
}
if ( V_85 != - 1 ) {
V_6 -> V_21 ( V_2 , V_85 , V_86 ) ;
V_86 &= ~ V_23 ;
V_6 -> V_21 ( V_2 , V_85 >> 8 , V_86 ) ;
if ( V_6 -> V_93 > ( 32 << 20 ) )
V_6 -> V_21 ( V_2 , V_85 >> 16 , V_86 ) ;
}
V_6 -> V_21 ( V_2 , V_22 , V_94 | V_23 ) ;
switch ( V_83 ) {
case V_95 :
case V_96 :
case V_97 :
case V_88 :
case V_72 :
return;
case V_98 :
if ( V_6 -> V_77 )
break;
F_42 ( V_6 -> V_99 ) ;
V_6 -> V_21 ( V_2 , V_72 ,
V_87 | V_23 ) ;
V_6 -> V_21 ( V_2 ,
V_22 , V_94 | V_23 ) ;
while ( ! ( V_6 -> V_47 ( V_2 ) & V_100 ) )
;
return;
default:
if ( ! V_6 -> V_77 ) {
F_42 ( V_6 -> V_99 ) ;
return;
}
}
F_43 ( 100 ) ;
F_37 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned int V_83 ,
int V_84 , int V_85 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_83 == V_44 ) {
V_84 += V_2 -> V_36 ;
V_83 = V_90 ;
}
V_6 -> V_21 ( V_2 , V_83 & 0xff ,
V_94 | V_101 | V_23 ) ;
if ( V_84 != - 1 || V_85 != - 1 ) {
int V_86 = V_23 | V_94 | V_102 ;
if ( V_84 != - 1 ) {
if ( V_6 -> V_41 & V_42 )
V_84 >>= 1 ;
V_6 -> V_21 ( V_2 , V_84 , V_86 ) ;
V_86 &= ~ V_23 ;
V_6 -> V_21 ( V_2 , V_84 >> 8 , V_86 ) ;
}
if ( V_85 != - 1 ) {
V_6 -> V_21 ( V_2 , V_85 , V_86 ) ;
V_6 -> V_21 ( V_2 , V_85 >> 8 ,
V_94 | V_102 ) ;
if ( V_6 -> V_93 > ( 128 << 20 ) )
V_6 -> V_21 ( V_2 , V_85 >> 16 ,
V_94 | V_102 ) ;
}
}
V_6 -> V_21 ( V_2 , V_22 , V_94 | V_23 ) ;
switch ( V_83 ) {
case V_103 :
case V_95 :
case V_96 :
case V_97 :
case V_88 :
case V_104 :
case V_72 :
case V_105 :
return;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
F_42 ( V_6 -> V_99 ) ;
return;
case V_98 :
if ( V_6 -> V_77 )
break;
F_42 ( V_6 -> V_99 ) ;
V_6 -> V_21 ( V_2 , V_72 ,
V_94 | V_101 | V_23 ) ;
V_6 -> V_21 ( V_2 , V_22 ,
V_94 | V_23 ) ;
while ( ! ( V_6 -> V_47 ( V_2 ) & V_100 ) )
;
return;
case V_111 :
V_6 -> V_21 ( V_2 , V_112 ,
V_94 | V_101 | V_23 ) ;
V_6 -> V_21 ( V_2 , V_22 ,
V_94 | V_23 ) ;
return;
case V_90 :
V_6 -> V_21 ( V_2 , V_113 ,
V_94 | V_101 | V_23 ) ;
V_6 -> V_21 ( V_2 , V_22 ,
V_94 | V_23 ) ;
default:
if ( ! V_6 -> V_77 ) {
F_42 ( V_6 -> V_99 ) ;
return;
}
}
F_43 ( 100 ) ;
F_37 ( V_2 ) ;
}
static void F_45 ( struct V_5 * V_6 ,
struct V_1 * V_2 , int V_114 )
{
V_6 -> V_13 -> V_15 = V_6 ;
V_6 -> V_16 = V_114 ;
}
static int
F_24 ( struct V_5 * V_6 , struct V_1 * V_2 , int V_114 )
{
T_5 * V_14 = & V_6 -> V_13 -> V_14 ;
T_6 * V_18 = & V_6 -> V_13 -> V_18 ;
F_46 ( V_115 , V_116 ) ;
V_117:
F_4 ( V_14 ) ;
if ( ! V_6 -> V_13 -> V_15 )
V_6 -> V_13 -> V_15 = V_6 ;
if ( V_6 -> V_13 -> V_15 == V_6 && V_6 -> V_16 == V_17 ) {
V_6 -> V_16 = V_114 ;
F_6 ( V_14 ) ;
return 0 ;
}
if ( V_114 == V_118 ) {
if ( V_6 -> V_13 -> V_15 -> V_16 == V_118 ) {
V_6 -> V_16 = V_118 ;
F_6 ( V_14 ) ;
return 0 ;
}
}
F_47 ( V_119 ) ;
F_48 ( V_18 , & V_115 ) ;
F_6 ( V_14 ) ;
F_49 () ;
F_50 ( V_18 , & V_115 ) ;
goto V_117;
}
static void F_51 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned long V_76 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_76 ; V_25 ++ ) {
if ( V_6 -> V_77 ) {
if ( V_6 -> V_77 ( V_2 ) )
break;
} else {
if ( V_6 -> V_47 ( V_2 ) & V_100 )
break;
}
F_36 ( 1 ) ;
}
}
static int F_52 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned long V_76 = V_78 ;
int V_120 , V_16 = V_6 -> V_16 ;
if ( V_16 == V_121 )
V_76 += ( V_122 * 400 ) / 1000 ;
else
V_76 += ( V_122 * 20 ) / 1000 ;
F_39 ( V_80 , V_81 ) ;
F_43 ( 100 ) ;
if ( ( V_16 == V_121 ) && ( V_6 -> V_41 & V_123 ) )
V_6 -> V_43 ( V_2 , V_124 , - 1 , - 1 ) ;
else
V_6 -> V_43 ( V_2 , V_72 , - 1 , - 1 ) ;
if ( F_38 () || V_79 )
F_51 ( V_2 , V_6 , V_76 ) ;
else {
while ( F_40 ( V_78 , V_76 ) ) {
if ( V_6 -> V_77 ) {
if ( V_6 -> V_77 ( V_2 ) )
break;
} else {
if ( V_6 -> V_47 ( V_2 ) & V_100 )
break;
}
F_53 () ;
}
}
F_39 ( V_80 , V_82 ) ;
V_120 = ( int ) V_6 -> V_47 ( V_2 ) ;
return V_120 ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , int V_125 )
{
int V_8 = 0 ;
int V_120 , V_30 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_30 = V_3 >> V_6 -> V_37 ;
V_6 -> V_43 ( V_2 , V_126 , - 1 , V_30 & V_6 -> V_38 ) ;
V_30 = ( V_3 + V_4 ) >> V_6 -> V_37 ;
V_6 -> V_43 ( V_2 , V_127 , - 1 ,
( V_30 | V_125 ) & V_6 -> V_38 ) ;
V_120 = V_6 -> V_128 ( V_2 , V_6 ) ;
if ( V_120 & 0x01 ) {
F_2 ( L_3 ,
V_10 , V_120 ) ;
V_8 = - V_129 ;
}
return V_8 ;
}
int F_55 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
V_8 = - V_11 ;
if ( V_3 + V_4 == V_2 -> V_130 )
V_4 -= V_2 -> V_35 ;
F_24 ( V_6 , V_2 , V_131 ) ;
V_20 = V_3 >> V_6 -> V_39 ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( F_31 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_8 = - V_129 ;
goto V_132;
}
V_8 = F_54 ( V_2 , V_3 , V_4 , 0 ) ;
V_132:
F_3 ( V_2 ) ;
return V_8 ;
}
int F_56 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_20 , V_120 , V_30 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
V_8 = - V_11 ;
F_24 ( V_6 , V_2 , V_133 ) ;
V_20 = V_3 >> V_6 -> V_39 ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( F_31 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_120 = V_134 ;
V_8 = - V_129 ;
goto V_132;
}
V_30 = V_3 >> V_6 -> V_37 ;
V_6 -> V_43 ( V_2 , V_135 , - 1 , V_30 & V_6 -> V_38 ) ;
V_120 = V_6 -> V_128 ( V_2 , V_6 ) ;
if ( V_120 & 0x01 ) {
F_2 ( L_3 ,
V_10 , V_120 ) ;
V_8 = - V_129 ;
goto V_132;
}
V_8 = F_54 ( V_2 , V_3 , V_4 , 0x1 ) ;
V_132:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_24 , int V_136 , int V_30 )
{
V_6 -> V_137 ( V_2 , V_24 , V_2 -> V_36 ) ;
if ( V_136 )
V_6 -> V_137 ( V_2 , V_6 -> V_138 , V_2 -> V_139 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_24 ,
int V_136 , int V_30 )
{
int V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
T_3 * V_144 = V_6 -> V_138 ;
int V_145 , V_130 ;
for ( V_145 = V_6 -> V_141 . V_145 ; V_145 > 0 ; V_145 -- ) {
V_6 -> V_137 ( V_2 , V_24 , V_140 ) ;
V_24 += V_140 ;
if ( V_6 -> V_141 . V_146 ) {
V_6 -> V_137 ( V_2 , V_144 , V_6 -> V_141 . V_146 ) ;
V_144 += V_6 -> V_141 . V_146 ;
}
V_6 -> V_137 ( V_2 , V_144 , V_142 ) ;
V_144 += V_142 ;
if ( V_6 -> V_141 . V_147 ) {
V_6 -> V_137 ( V_2 , V_144 , V_6 -> V_141 . V_147 ) ;
V_144 += V_6 -> V_141 . V_147 ;
}
}
V_130 = V_2 -> V_139 - ( V_144 - V_6 -> V_138 ) ;
if ( V_130 )
V_6 -> V_137 ( V_2 , V_144 , V_130 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_24 , int V_136 , int V_30 )
{
int V_25 , V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
int V_148 = V_6 -> V_141 . V_145 ;
T_3 * V_28 = V_24 ;
T_3 * V_149 = V_6 -> V_150 -> V_151 ;
T_3 * V_152 = V_6 -> V_150 -> V_153 ;
T_7 * V_154 = V_6 -> V_141 . V_155 -> V_154 ;
unsigned int V_156 = 0 ;
V_6 -> V_141 . V_157 ( V_2 , V_6 , V_24 , 1 , V_30 ) ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 )
V_6 -> V_141 . V_158 ( V_2 , V_28 , & V_149 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_141 . V_159 ; V_25 ++ )
V_152 [ V_25 ] = V_6 -> V_138 [ V_154 [ V_25 ] ] ;
V_148 = V_6 -> V_141 . V_145 ;
V_28 = V_24 ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 ) {
int V_160 ;
V_160 = V_6 -> V_141 . V_161 ( V_2 , V_28 , & V_152 [ V_25 ] , & V_149 [ V_25 ] ) ;
if ( V_160 < 0 ) {
V_2 -> V_69 . V_162 ++ ;
} else {
V_2 -> V_69 . V_163 += V_160 ;
V_156 = F_60 (unsigned int, max_bitflips, stat) ;
}
}
return V_156 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_7 V_164 , T_7 V_165 , T_3 * V_166 )
{
int V_167 , V_168 , V_169 ;
T_7 * V_154 = V_6 -> V_141 . V_155 -> V_154 ;
T_3 * V_28 ;
int V_170 , V_25 , V_171 = 0 ;
int V_172 , V_173 , V_174 , V_175 ;
int V_176 = ( V_6 -> V_41 & V_42 ) ? 2 : 1 ;
int V_177 = 0 ;
unsigned int V_156 = 0 ;
V_167 = V_164 / V_6 -> V_141 . V_130 ;
V_168 = ( V_164 + V_165 - 1 ) / V_6 -> V_141 . V_130 ;
V_169 = V_168 - V_167 + 1 ;
V_172 = V_169 * V_6 -> V_141 . V_130 ;
V_173 = V_169 * V_6 -> V_141 . V_143 ;
V_170 = V_167 * V_6 -> V_141 . V_130 ;
if ( V_170 != 0 )
V_6 -> V_43 ( V_2 , V_111 , V_170 , - 1 ) ;
V_28 = V_166 + V_170 ;
V_6 -> V_137 ( V_2 , V_28 , V_172 ) ;
for ( V_25 = 0 ; V_25 < V_173 ; V_25 += V_6 -> V_141 . V_143 , V_28 += V_6 -> V_141 . V_130 )
V_6 -> V_141 . V_158 ( V_2 , V_28 , & V_6 -> V_150 -> V_151 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_173 - 1 ; V_25 ++ ) {
if ( V_154 [ V_25 + V_167 * V_6 -> V_141 . V_143 ] + 1 !=
V_154 [ V_25 + V_167 * V_6 -> V_141 . V_143 + 1 ] ) {
V_171 = 1 ;
break;
}
}
if ( V_171 ) {
V_6 -> V_43 ( V_2 , V_111 , V_2 -> V_36 , - 1 ) ;
V_6 -> V_137 ( V_2 , V_6 -> V_138 , V_2 -> V_139 ) ;
} else {
V_177 = V_167 * V_6 -> V_141 . V_143 ;
V_175 = V_154 [ V_177 ] & ~ ( V_176 - 1 ) ;
V_174 = V_173 ;
if ( V_154 [ V_177 ] & ( V_176 - 1 ) )
V_174 ++ ;
if ( V_154 [ V_177 + ( V_169 * V_6 -> V_141 . V_143 ) ] & ( V_176 - 1 ) )
V_174 ++ ;
V_6 -> V_43 ( V_2 , V_111 ,
V_2 -> V_36 + V_175 , - 1 ) ;
V_6 -> V_137 ( V_2 , & V_6 -> V_138 [ V_175 ] , V_174 ) ;
}
for ( V_25 = 0 ; V_25 < V_173 ; V_25 ++ )
V_6 -> V_150 -> V_153 [ V_25 ] = V_6 -> V_138 [ V_154 [ V_25 + V_177 ] ] ;
V_28 = V_166 + V_170 ;
for ( V_25 = 0 ; V_25 < V_173 ; V_25 += V_6 -> V_141 . V_143 , V_28 += V_6 -> V_141 . V_130 ) {
int V_160 ;
V_160 = V_6 -> V_141 . V_161 ( V_2 , V_28 ,
& V_6 -> V_150 -> V_153 [ V_25 ] , & V_6 -> V_150 -> V_151 [ V_25 ] ) ;
if ( V_160 < 0 ) {
V_2 -> V_69 . V_162 ++ ;
} else {
V_2 -> V_69 . V_163 += V_160 ;
V_156 = F_60 (unsigned int, max_bitflips, stat) ;
}
}
return V_156 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_24 , int V_136 , int V_30 )
{
int V_25 , V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
int V_148 = V_6 -> V_141 . V_145 ;
T_3 * V_28 = V_24 ;
T_3 * V_149 = V_6 -> V_150 -> V_151 ;
T_3 * V_152 = V_6 -> V_150 -> V_153 ;
T_7 * V_154 = V_6 -> V_141 . V_155 -> V_154 ;
unsigned int V_156 = 0 ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 ) {
V_6 -> V_141 . V_178 ( V_2 , V_179 ) ;
V_6 -> V_137 ( V_2 , V_28 , V_140 ) ;
V_6 -> V_141 . V_158 ( V_2 , V_28 , & V_149 [ V_25 ] ) ;
}
V_6 -> V_137 ( V_2 , V_6 -> V_138 , V_2 -> V_139 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_141 . V_159 ; V_25 ++ )
V_152 [ V_25 ] = V_6 -> V_138 [ V_154 [ V_25 ] ] ;
V_148 = V_6 -> V_141 . V_145 ;
V_28 = V_24 ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 ) {
int V_160 ;
V_160 = V_6 -> V_141 . V_161 ( V_2 , V_28 , & V_152 [ V_25 ] , & V_149 [ V_25 ] ) ;
if ( V_160 < 0 ) {
V_2 -> V_69 . V_162 ++ ;
} else {
V_2 -> V_69 . V_163 += V_160 ;
V_156 = F_60 (unsigned int, max_bitflips, stat) ;
}
}
return V_156 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_24 , int V_136 , int V_30 )
{
int V_25 , V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
int V_148 = V_6 -> V_141 . V_145 ;
T_3 * V_28 = V_24 ;
T_3 * V_152 = V_6 -> V_150 -> V_153 ;
T_7 * V_154 = V_6 -> V_141 . V_155 -> V_154 ;
T_3 * V_149 = V_6 -> V_150 -> V_151 ;
unsigned int V_156 = 0 ;
V_6 -> V_43 ( V_2 , V_44 , 0 , V_30 ) ;
V_6 -> V_137 ( V_2 , V_6 -> V_138 , V_2 -> V_139 ) ;
V_6 -> V_43 ( V_2 , V_90 , 0 , V_30 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_141 . V_159 ; V_25 ++ )
V_152 [ V_25 ] = V_6 -> V_138 [ V_154 [ V_25 ] ] ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 ) {
int V_160 ;
V_6 -> V_141 . V_178 ( V_2 , V_179 ) ;
V_6 -> V_137 ( V_2 , V_28 , V_140 ) ;
V_6 -> V_141 . V_158 ( V_2 , V_28 , & V_149 [ V_25 ] ) ;
V_160 = V_6 -> V_141 . V_161 ( V_2 , V_28 , & V_152 [ V_25 ] , NULL ) ;
if ( V_160 < 0 ) {
V_2 -> V_69 . V_162 ++ ;
} else {
V_2 -> V_69 . V_163 += V_160 ;
V_156 = F_60 (unsigned int, max_bitflips, stat) ;
}
}
return V_156 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_24 , int V_136 , int V_30 )
{
int V_25 , V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
int V_148 = V_6 -> V_141 . V_145 ;
T_3 * V_28 = V_24 ;
T_3 * V_144 = V_6 -> V_138 ;
unsigned int V_156 = 0 ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 ) {
int V_160 ;
V_6 -> V_141 . V_178 ( V_2 , V_179 ) ;
V_6 -> V_137 ( V_2 , V_28 , V_140 ) ;
if ( V_6 -> V_141 . V_146 ) {
V_6 -> V_137 ( V_2 , V_144 , V_6 -> V_141 . V_146 ) ;
V_144 += V_6 -> V_141 . V_146 ;
}
V_6 -> V_141 . V_178 ( V_2 , V_180 ) ;
V_6 -> V_137 ( V_2 , V_144 , V_142 ) ;
V_160 = V_6 -> V_141 . V_161 ( V_2 , V_28 , V_144 , NULL ) ;
if ( V_160 < 0 ) {
V_2 -> V_69 . V_162 ++ ;
} else {
V_2 -> V_69 . V_163 += V_160 ;
V_156 = F_60 (unsigned int, max_bitflips, stat) ;
}
V_144 += V_142 ;
if ( V_6 -> V_141 . V_147 ) {
V_6 -> V_137 ( V_2 , V_144 , V_6 -> V_141 . V_147 ) ;
V_144 += V_6 -> V_141 . V_147 ;
}
}
V_25 = V_2 -> V_139 - ( V_144 - V_6 -> V_138 ) ;
if ( V_25 )
V_6 -> V_137 ( V_2 , V_144 , V_25 ) ;
return V_156 ;
}
static T_3 * F_65 ( struct V_5 * V_6 , T_3 * V_144 ,
struct V_58 * V_59 , T_8 V_4 )
{
switch ( V_59 -> V_66 ) {
case V_67 :
case V_181 :
memcpy ( V_144 , V_6 -> V_138 + V_59 -> V_64 , V_4 ) ;
return V_144 + V_4 ;
case V_182 : {
struct V_183 * free = V_6 -> V_141 . V_155 -> V_184 ;
T_7 V_185 = 0 , V_186 = V_59 -> V_64 ;
T_8 V_143 = 0 ;
for (; free -> V_187 && V_4 ; free ++ , V_4 -= V_143 ) {
if ( F_66 ( V_186 ) ) {
if ( V_186 >= free -> V_187 ) {
V_186 -= free -> V_187 ;
continue;
}
V_185 = free -> V_188 + V_186 ;
V_143 = F_67 ( T_8 , V_4 ,
( free -> V_187 - V_186 ) ) ;
V_186 = 0 ;
} else {
V_143 = F_67 ( T_8 , V_4 , free -> V_187 ) ;
V_185 = free -> V_188 ;
}
memcpy ( V_144 , V_6 -> V_138 + V_185 , V_143 ) ;
V_144 += V_143 ;
}
return V_144 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_189 ,
struct V_58 * V_59 )
{
int V_20 , V_30 , V_190 , V_191 , V_143 , V_192 , V_136 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_193 V_194 ;
int V_8 = 0 ;
T_7 V_165 = V_59 -> V_4 ;
T_7 V_195 = V_59 -> V_65 ;
T_7 V_196 = V_59 -> V_66 == V_182 ?
V_2 -> V_197 : V_2 -> V_139 ;
T_3 * V_166 , * V_144 , * V_24 ;
unsigned int V_156 = 0 ;
V_194 = V_2 -> V_69 ;
V_20 = ( int ) ( V_189 >> V_6 -> V_39 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
V_190 = ( int ) ( V_189 >> V_6 -> V_37 ) ;
V_30 = V_190 & V_6 -> V_38 ;
V_191 = ( int ) ( V_189 & ( V_2 -> V_36 - 1 ) ) ;
V_24 = V_59 -> V_62 ;
V_144 = V_59 -> V_63 ;
V_136 = V_144 ? 1 : 0 ;
while ( 1 ) {
V_143 = F_69 ( V_2 -> V_36 - V_191 , V_165 ) ;
V_192 = ( V_143 == V_2 -> V_36 ) ;
if ( V_190 != V_6 -> V_198 || V_144 ) {
V_166 = V_192 ? V_24 : V_6 -> V_150 -> V_199 ;
V_6 -> V_43 ( V_2 , V_90 , 0x00 , V_30 ) ;
if ( F_66 ( V_59 -> V_66 == V_181 ) )
V_8 = V_6 -> V_141 . V_157 ( V_2 , V_6 , V_166 ,
V_136 ,
V_30 ) ;
else if ( ! V_192 && F_70 ( V_6 ) && ! V_144 )
V_8 = V_6 -> V_141 . V_200 ( V_2 , V_6 ,
V_191 , V_143 , V_166 ) ;
else
V_8 = V_6 -> V_141 . V_201 ( V_2 , V_6 , V_166 ,
V_136 , V_30 ) ;
if ( V_8 < 0 ) {
if ( ! V_192 )
V_6 -> V_198 = - 1 ;
break;
}
V_156 = F_60 (unsigned int, max_bitflips, ret) ;
if ( ! V_192 ) {
if ( ! F_70 ( V_6 ) && ! V_144 &&
! ( V_2 -> V_69 . V_162 - V_194 . V_162 ) &&
( V_59 -> V_66 != V_181 ) ) {
V_6 -> V_198 = V_190 ;
V_6 -> V_202 = V_8 ;
} else {
V_6 -> V_198 = - 1 ;
}
memcpy ( V_24 , V_6 -> V_150 -> V_199 + V_191 , V_143 ) ;
}
V_24 += V_143 ;
if ( F_66 ( V_144 ) ) {
int V_203 = F_69 ( V_195 , V_196 ) ;
if ( V_203 ) {
V_144 = F_65 ( V_6 ,
V_144 , V_59 , V_203 ) ;
V_195 -= V_203 ;
}
}
if ( ! ( V_6 -> V_41 & V_204 ) ) {
if ( ! V_6 -> V_77 )
F_42 ( V_6 -> V_99 ) ;
else
F_37 ( V_2 ) ;
}
} else {
memcpy ( V_24 , V_6 -> V_150 -> V_199 + V_191 , V_143 ) ;
V_24 += V_143 ;
V_156 = F_60 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_165 -= V_143 ;
if ( ! V_165 )
break;
V_191 = 0 ;
V_190 ++ ;
V_30 = V_190 & V_6 -> V_38 ;
if ( ! V_30 ) {
V_20 ++ ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
}
}
V_59 -> V_205 = V_59 -> V_4 - ( T_8 ) V_165 ;
if ( V_144 )
V_59 -> V_206 = V_59 -> V_65 - V_195 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_69 . V_162 - V_194 . V_162 )
return - V_207 ;
return V_156 ;
}
static int F_71 ( struct V_1 * V_2 , T_1 V_189 , T_8 V_4 ,
T_8 * V_205 , T_3 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_58 V_59 ;
int V_8 ;
F_24 ( V_6 , V_2 , V_40 ) ;
V_59 . V_4 = V_4 ;
V_59 . V_62 = V_24 ;
V_59 . V_63 = NULL ;
V_59 . V_66 = 0 ;
V_8 = F_68 ( V_2 , V_189 , & V_59 ) ;
* V_205 = V_59 . V_205 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
V_6 -> V_43 ( V_2 , V_44 , 0 , V_30 ) ;
V_6 -> V_137 ( V_2 , V_6 -> V_138 , V_2 -> V_139 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
T_3 * V_24 = V_6 -> V_138 ;
int V_187 = V_2 -> V_139 ;
int V_208 = V_6 -> V_141 . V_143 + V_6 -> V_141 . V_146 + V_6 -> V_141 . V_147 ;
int V_140 = V_6 -> V_141 . V_130 ;
T_3 * V_166 = V_24 ;
int V_25 , V_203 , V_209 = 0 , V_210 ;
V_6 -> V_43 ( V_2 , V_90 , V_6 -> V_141 . V_130 , V_30 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_141 . V_145 ; V_25 ++ ) {
if ( V_209 ) {
V_210 = V_140 + V_25 * ( V_140 + V_208 ) ;
if ( V_2 -> V_36 > 512 )
V_6 -> V_43 ( V_2 , V_111 , V_210 , - 1 ) ;
else
V_6 -> V_43 ( V_2 , V_90 , V_210 , V_30 ) ;
} else
V_209 = 1 ;
V_203 = F_67 ( int , V_187 , V_208 ) ;
V_6 -> V_137 ( V_2 , V_166 , V_203 ) ;
V_166 += V_203 ;
V_187 -= V_203 ;
}
if ( V_187 > 0 )
V_6 -> V_137 ( V_2 , V_166 , V_187 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
int V_120 = 0 ;
const T_3 * V_24 = V_6 -> V_138 ;
int V_187 = V_2 -> V_139 ;
V_6 -> V_43 ( V_2 , V_88 , V_2 -> V_36 , V_30 ) ;
V_6 -> V_211 ( V_2 , V_24 , V_187 ) ;
V_6 -> V_43 ( V_2 , V_95 , - 1 , - 1 ) ;
V_120 = V_6 -> V_128 ( V_2 , V_6 ) ;
return V_120 & V_212 ? - V_129 : 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_30 )
{
int V_208 = V_6 -> V_141 . V_143 + V_6 -> V_141 . V_146 + V_6 -> V_141 . V_147 ;
int V_140 = V_6 -> V_141 . V_130 , V_187 = V_2 -> V_139 ;
int V_25 , V_4 , V_210 , V_120 = 0 , V_213 = 0 , V_145 = V_6 -> V_141 . V_145 ;
const T_3 * V_166 = V_6 -> V_138 ;
if ( ! V_6 -> V_141 . V_146 && ! V_6 -> V_141 . V_147 ) {
V_210 = V_145 * ( V_140 + V_208 ) ;
V_145 = 0 ;
} else
V_210 = V_140 ;
V_6 -> V_43 ( V_2 , V_88 , V_210 , V_30 ) ;
for ( V_25 = 0 ; V_25 < V_145 ; V_25 ++ ) {
if ( V_213 ) {
if ( V_2 -> V_36 <= 512 ) {
T_7 V_214 = 0xFFFFFFFF ;
V_4 = V_140 ;
while ( V_4 > 0 ) {
int V_215 = F_67 ( int , V_4 , 4 ) ;
V_6 -> V_211 ( V_2 , ( T_3 * ) & V_214 ,
V_215 ) ;
V_4 -= V_215 ;
}
} else {
V_210 = V_140 + V_25 * ( V_140 + V_208 ) ;
V_6 -> V_43 ( V_2 , V_104 , V_210 , - 1 ) ;
}
} else
V_213 = 1 ;
V_4 = F_67 ( int , V_187 , V_208 ) ;
V_6 -> V_211 ( V_2 , V_166 , V_4 ) ;
V_166 += V_4 ;
V_187 -= V_4 ;
}
if ( V_187 > 0 )
V_6 -> V_211 ( V_2 , V_166 , V_187 ) ;
V_6 -> V_43 ( V_2 , V_95 , - 1 , - 1 ) ;
V_120 = V_6 -> V_128 ( V_2 , V_6 ) ;
return V_120 & V_212 ? - V_129 : 0 ;
}
static int F_76 ( struct V_1 * V_2 , T_1 V_189 ,
struct V_58 * V_59 )
{
int V_30 , V_190 , V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_193 V_194 ;
int V_165 = V_59 -> V_65 ;
int V_4 ;
T_3 * V_24 = V_59 -> V_63 ;
int V_8 = 0 ;
F_2 ( L_6 ,
V_10 , ( unsigned long long ) V_189 , V_165 ) ;
V_194 = V_2 -> V_69 ;
if ( V_59 -> V_66 == V_182 )
V_4 = V_6 -> V_141 . V_155 -> V_197 ;
else
V_4 = V_2 -> V_139 ;
if ( F_66 ( V_59 -> V_64 >= V_4 ) ) {
F_2 ( L_7 ,
V_10 ) ;
return - V_11 ;
}
if ( F_66 ( V_189 >= V_2 -> V_130 ||
V_59 -> V_64 + V_165 > ( ( V_2 -> V_130 >> V_6 -> V_37 ) -
( V_189 >> V_6 -> V_37 ) ) * V_4 ) ) {
F_2 ( L_8 ,
V_10 ) ;
return - V_11 ;
}
V_20 = ( int ) ( V_189 >> V_6 -> V_39 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
V_190 = ( int ) ( V_189 >> V_6 -> V_37 ) ;
V_30 = V_190 & V_6 -> V_38 ;
while ( 1 ) {
if ( V_59 -> V_66 == V_181 )
V_8 = V_6 -> V_141 . V_216 ( V_2 , V_6 , V_30 ) ;
else
V_8 = V_6 -> V_141 . V_217 ( V_2 , V_6 , V_30 ) ;
if ( V_8 < 0 )
break;
V_4 = F_69 ( V_4 , V_165 ) ;
V_24 = F_65 ( V_6 , V_24 , V_59 , V_4 ) ;
if ( ! ( V_6 -> V_41 & V_204 ) ) {
if ( ! V_6 -> V_77 )
F_42 ( V_6 -> V_99 ) ;
else
F_37 ( V_2 ) ;
}
V_165 -= V_4 ;
if ( ! V_165 )
break;
V_190 ++ ;
V_30 = V_190 & V_6 -> V_38 ;
if ( ! V_30 ) {
V_20 ++ ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
}
}
V_59 -> V_206 = V_59 -> V_65 - V_165 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_69 . V_162 - V_194 . V_162 )
return - V_207 ;
return V_2 -> V_69 . V_163 - V_194 . V_163 ? - V_218 : 0 ;
}
static int F_77 ( struct V_1 * V_2 , T_1 V_189 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = - V_219 ;
V_59 -> V_205 = 0 ;
if ( V_59 -> V_62 && ( V_189 + V_59 -> V_4 ) > V_2 -> V_130 ) {
F_2 ( L_8 ,
V_10 ) ;
return - V_11 ;
}
F_24 ( V_6 , V_2 , V_40 ) ;
switch ( V_59 -> V_66 ) {
case V_67 :
case V_182 :
case V_181 :
break;
default:
goto V_132;
}
if ( ! V_59 -> V_62 )
V_8 = F_76 ( V_2 , V_189 , V_59 ) ;
else
V_8 = F_68 ( V_2 , V_189 , V_59 ) ;
V_132:
F_3 ( V_2 ) ;
return V_8 ;
}
static void F_78 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_24 , int V_136 )
{
V_6 -> V_211 ( V_2 , V_24 , V_2 -> V_36 ) ;
if ( V_136 )
V_6 -> V_211 ( V_2 , V_6 -> V_138 , V_2 -> V_139 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_24 , int V_136 )
{
int V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
T_3 * V_144 = V_6 -> V_138 ;
int V_145 , V_130 ;
for ( V_145 = V_6 -> V_141 . V_145 ; V_145 > 0 ; V_145 -- ) {
V_6 -> V_211 ( V_2 , V_24 , V_140 ) ;
V_24 += V_140 ;
if ( V_6 -> V_141 . V_146 ) {
V_6 -> V_211 ( V_2 , V_144 , V_6 -> V_141 . V_146 ) ;
V_144 += V_6 -> V_141 . V_146 ;
}
V_6 -> V_137 ( V_2 , V_144 , V_142 ) ;
V_144 += V_142 ;
if ( V_6 -> V_141 . V_147 ) {
V_6 -> V_211 ( V_2 , V_144 , V_6 -> V_141 . V_147 ) ;
V_144 += V_6 -> V_141 . V_147 ;
}
}
V_130 = V_2 -> V_139 - ( V_144 - V_6 -> V_138 ) ;
if ( V_130 )
V_6 -> V_211 ( V_2 , V_144 , V_130 ) ;
}
static void F_80 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_24 , int V_136 )
{
int V_25 , V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
int V_148 = V_6 -> V_141 . V_145 ;
T_3 * V_149 = V_6 -> V_150 -> V_151 ;
const T_3 * V_28 = V_24 ;
T_7 * V_154 = V_6 -> V_141 . V_155 -> V_154 ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 )
V_6 -> V_141 . V_158 ( V_2 , V_28 , & V_149 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_141 . V_159 ; V_25 ++ )
V_6 -> V_138 [ V_154 [ V_25 ] ] = V_149 [ V_25 ] ;
V_6 -> V_141 . V_220 ( V_2 , V_6 , V_24 , 1 ) ;
}
static void F_81 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_24 , int V_136 )
{
int V_25 , V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
int V_148 = V_6 -> V_141 . V_145 ;
T_3 * V_149 = V_6 -> V_150 -> V_151 ;
const T_3 * V_28 = V_24 ;
T_7 * V_154 = V_6 -> V_141 . V_155 -> V_154 ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 ) {
V_6 -> V_141 . V_178 ( V_2 , V_221 ) ;
V_6 -> V_211 ( V_2 , V_28 , V_140 ) ;
V_6 -> V_141 . V_158 ( V_2 , V_28 , & V_149 [ V_25 ] ) ;
}
for ( V_25 = 0 ; V_25 < V_6 -> V_141 . V_159 ; V_25 ++ )
V_6 -> V_138 [ V_154 [ V_25 ] ] = V_149 [ V_25 ] ;
V_6 -> V_211 ( V_2 , V_6 -> V_138 , V_2 -> V_139 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_24 , int V_136 )
{
int V_25 , V_140 = V_6 -> V_141 . V_130 ;
int V_142 = V_6 -> V_141 . V_143 ;
int V_148 = V_6 -> V_141 . V_145 ;
const T_3 * V_28 = V_24 ;
T_3 * V_144 = V_6 -> V_138 ;
for ( V_25 = 0 ; V_148 ; V_148 -- , V_25 += V_142 , V_28 += V_140 ) {
V_6 -> V_141 . V_178 ( V_2 , V_221 ) ;
V_6 -> V_211 ( V_2 , V_28 , V_140 ) ;
if ( V_6 -> V_141 . V_146 ) {
V_6 -> V_211 ( V_2 , V_144 , V_6 -> V_141 . V_146 ) ;
V_144 += V_6 -> V_141 . V_146 ;
}
V_6 -> V_141 . V_158 ( V_2 , V_28 , V_144 ) ;
V_6 -> V_211 ( V_2 , V_144 , V_142 ) ;
V_144 += V_142 ;
if ( V_6 -> V_141 . V_147 ) {
V_6 -> V_211 ( V_2 , V_144 , V_6 -> V_141 . V_147 ) ;
V_144 += V_6 -> V_141 . V_147 ;
}
}
V_25 = V_2 -> V_139 - ( V_144 - V_6 -> V_138 ) ;
if ( V_25 )
V_6 -> V_211 ( V_2 , V_144 , V_25 ) ;
}
static int F_83 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_24 , int V_136 , int V_30 ,
int V_222 , int V_223 )
{
int V_120 ;
V_6 -> V_43 ( V_2 , V_88 , 0x00 , V_30 ) ;
if ( F_66 ( V_223 ) )
V_6 -> V_141 . V_220 ( V_2 , V_6 , V_24 , V_136 ) ;
else
V_6 -> V_141 . V_224 ( V_2 , V_6 , V_24 , V_136 ) ;
V_222 = 0 ;
if ( ! V_222 || ! ( V_6 -> V_41 & V_225 ) ) {
V_6 -> V_43 ( V_2 , V_95 , - 1 , - 1 ) ;
V_120 = V_6 -> V_128 ( V_2 , V_6 ) ;
if ( ( V_120 & V_212 ) && ( V_6 -> V_226 ) )
V_120 = V_6 -> V_226 ( V_2 , V_6 , V_61 , V_120 ,
V_30 ) ;
if ( V_120 & V_212 )
return - V_129 ;
} else {
V_6 -> V_43 ( V_2 , V_103 , - 1 , - 1 ) ;
V_120 = V_6 -> V_128 ( V_2 , V_6 ) ;
}
#ifdef F_84
V_6 -> V_43 ( V_2 , V_90 , 0 , V_30 ) ;
if ( V_6 -> V_227 ( V_2 , V_24 , V_2 -> V_36 ) )
return - V_129 ;
V_6 -> V_43 ( V_2 , V_72 , - 1 , - 1 ) ;
#endif
return 0 ;
}
static T_3 * F_85 ( struct V_1 * V_2 , T_3 * V_144 , T_8 V_4 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
memset ( V_6 -> V_138 , 0xff , V_2 -> V_139 ) ;
switch ( V_59 -> V_66 ) {
case V_67 :
case V_181 :
memcpy ( V_6 -> V_138 + V_59 -> V_64 , V_144 , V_4 ) ;
return V_144 + V_4 ;
case V_182 : {
struct V_183 * free = V_6 -> V_141 . V_155 -> V_184 ;
T_7 V_185 = 0 , V_228 = V_59 -> V_64 ;
T_8 V_143 = 0 ;
for (; free -> V_187 && V_4 ; free ++ , V_4 -= V_143 ) {
if ( F_66 ( V_228 ) ) {
if ( V_228 >= free -> V_187 ) {
V_228 -= free -> V_187 ;
continue;
}
V_185 = free -> V_188 + V_228 ;
V_143 = F_67 ( T_8 , V_4 ,
( free -> V_187 - V_228 ) ) ;
V_228 = 0 ;
} else {
V_143 = F_67 ( T_8 , V_4 , free -> V_187 ) ;
V_185 = free -> V_188 ;
}
memcpy ( V_6 -> V_138 + V_185 , V_144 , V_143 ) ;
V_144 += V_143 ;
}
return V_144 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_229 ,
struct V_58 * V_59 )
{
int V_20 , V_190 , V_30 , V_230 , V_84 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_7 V_231 = V_59 -> V_4 ;
T_7 V_232 = V_59 -> V_65 ;
T_7 V_233 = V_59 -> V_66 == V_182 ?
V_2 -> V_197 : V_2 -> V_139 ;
T_3 * V_144 = V_59 -> V_63 ;
T_3 * V_24 = V_59 -> V_62 ;
int V_8 , V_234 ;
int V_136 = V_144 ? 1 : 0 ;
V_59 -> V_205 = 0 ;
if ( ! V_231 )
return 0 ;
if ( F_87 ( V_229 ) || F_87 ( V_59 -> V_4 ) ) {
F_88 ( L_9 ,
V_10 ) ;
return - V_11 ;
}
V_84 = V_229 & ( V_2 -> V_36 - 1 ) ;
V_234 = V_84 || ( V_231 & ( V_2 -> V_36 - 1 ) ) ;
if ( V_234 && V_144 )
return - V_11 ;
V_20 = ( int ) ( V_229 >> V_6 -> V_39 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( F_31 ( V_2 ) )
return - V_129 ;
V_190 = ( int ) ( V_229 >> V_6 -> V_37 ) ;
V_30 = V_190 & V_6 -> V_38 ;
V_230 = ( 1 << ( V_6 -> V_9 - V_6 -> V_37 ) ) - 1 ;
if ( V_229 <= ( V_6 -> V_198 << V_6 -> V_37 ) &&
( V_6 -> V_198 << V_6 -> V_37 ) < ( V_229 + V_59 -> V_4 ) )
V_6 -> V_198 = - 1 ;
if ( V_144 && V_59 -> V_64 && ( V_59 -> V_64 + V_59 -> V_65 > V_233 ) )
return - V_11 ;
while ( 1 ) {
int V_143 = V_2 -> V_36 ;
int V_222 = V_231 > V_143 && V_30 != V_230 ;
T_3 * V_235 = V_24 ;
if ( F_66 ( V_84 || V_231 < ( V_2 -> V_36 - 1 ) ) ) {
V_222 = 0 ;
V_143 = F_67 ( int , V_143 - V_84 , ( int ) V_231 ) ;
V_6 -> V_198 = - 1 ;
memset ( V_6 -> V_150 -> V_199 , 0xff , V_2 -> V_36 ) ;
memcpy ( & V_6 -> V_150 -> V_199 [ V_84 ] , V_24 , V_143 ) ;
V_235 = V_6 -> V_150 -> V_199 ;
}
if ( F_66 ( V_144 ) ) {
T_8 V_4 = F_69 ( V_232 , V_233 ) ;
V_144 = F_85 ( V_2 , V_144 , V_4 , V_59 ) ;
V_232 -= V_4 ;
} else {
memset ( V_6 -> V_138 , 0xff , V_2 -> V_139 ) ;
}
V_8 = V_6 -> V_224 ( V_2 , V_6 , V_235 , V_136 , V_30 ,
V_222 , ( V_59 -> V_66 == V_181 ) ) ;
if ( V_8 )
break;
V_231 -= V_143 ;
if ( ! V_231 )
break;
V_84 = 0 ;
V_24 += V_143 ;
V_190 ++ ;
V_30 = V_190 & V_6 -> V_38 ;
if ( ! V_30 ) {
V_20 ++ ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
}
}
V_59 -> V_205 = V_59 -> V_4 - V_231 ;
if ( F_66 ( V_144 ) )
V_59 -> V_206 = V_59 -> V_65 ;
return V_8 ;
}
static int F_89 ( struct V_1 * V_2 , T_1 V_229 , T_8 V_4 ,
T_8 * V_205 , const T_3 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_58 V_59 ;
int V_8 ;
F_51 ( V_2 , V_6 , 400 ) ;
F_45 ( V_6 , V_2 , V_61 ) ;
V_59 . V_4 = V_4 ;
V_59 . V_62 = ( T_3 * ) V_24 ;
V_59 . V_63 = NULL ;
V_59 . V_66 = 0 ;
V_8 = F_86 ( V_2 , V_229 , & V_59 ) ;
* V_205 = V_59 . V_205 ;
return V_8 ;
}
static int F_90 ( struct V_1 * V_2 , T_1 V_229 , T_8 V_4 ,
T_8 * V_205 , const T_3 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_58 V_59 ;
int V_8 ;
F_24 ( V_6 , V_2 , V_61 ) ;
V_59 . V_4 = V_4 ;
V_59 . V_62 = ( T_3 * ) V_24 ;
V_59 . V_63 = NULL ;
V_59 . V_66 = 0 ;
V_8 = F_86 ( V_2 , V_229 , & V_59 ) ;
* V_205 = V_59 . V_205 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_229 ,
struct V_58 * V_59 )
{
int V_20 , V_30 , V_120 , V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_10 ,
V_10 , ( unsigned int ) V_229 , ( int ) V_59 -> V_65 ) ;
if ( V_59 -> V_66 == V_182 )
V_4 = V_6 -> V_141 . V_155 -> V_197 ;
else
V_4 = V_2 -> V_139 ;
if ( ( V_59 -> V_64 + V_59 -> V_65 ) > V_4 ) {
F_2 ( L_11 ,
V_10 ) ;
return - V_11 ;
}
if ( F_66 ( V_59 -> V_64 >= V_4 ) ) {
F_2 ( L_12 ,
V_10 ) ;
return - V_11 ;
}
if ( F_66 ( V_229 >= V_2 -> V_130 ||
V_59 -> V_64 + V_59 -> V_65 >
( ( V_2 -> V_130 >> V_6 -> V_37 ) -
( V_229 >> V_6 -> V_37 ) ) * V_4 ) ) {
F_2 ( L_13 ,
V_10 ) ;
return - V_11 ;
}
V_20 = ( int ) ( V_229 >> V_6 -> V_39 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
V_30 = ( int ) ( V_229 >> V_6 -> V_37 ) ;
V_6 -> V_43 ( V_2 , V_98 , - 1 , - 1 ) ;
if ( F_31 ( V_2 ) )
return - V_236 ;
if ( V_30 == V_6 -> V_198 )
V_6 -> V_198 = - 1 ;
F_85 ( V_2 , V_59 -> V_63 , V_59 -> V_65 , V_59 ) ;
if ( V_59 -> V_66 == V_181 )
V_120 = V_6 -> V_141 . V_237 ( V_2 , V_6 , V_30 & V_6 -> V_38 ) ;
else
V_120 = V_6 -> V_141 . V_51 ( V_2 , V_6 , V_30 & V_6 -> V_38 ) ;
if ( V_120 )
return V_120 ;
V_59 -> V_206 = V_59 -> V_65 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_1 V_229 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = - V_219 ;
V_59 -> V_205 = 0 ;
if ( V_59 -> V_62 && ( V_229 + V_59 -> V_4 ) > V_2 -> V_130 ) {
F_2 ( L_13 ,
V_10 ) ;
return - V_11 ;
}
F_24 ( V_6 , V_2 , V_61 ) ;
switch ( V_59 -> V_66 ) {
case V_67 :
case V_182 :
case V_181 :
break;
default:
goto V_132;
}
if ( ! V_59 -> V_62 )
V_8 = F_29 ( V_2 , V_229 , V_59 ) ;
else
V_8 = F_86 ( V_2 , V_229 , V_59 ) ;
V_132:
F_3 ( V_2 ) ;
return V_8 ;
}
static void F_92 ( struct V_1 * V_2 , int V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_43 ( V_2 , V_96 , - 1 , V_30 ) ;
V_6 -> V_43 ( V_2 , V_97 , - 1 , - 1 ) ;
}
static void F_93 ( struct V_1 * V_2 , int V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_43 ( V_2 , V_96 , - 1 , V_30 ++ ) ;
V_6 -> V_43 ( V_2 , V_96 , - 1 , V_30 ++ ) ;
V_6 -> V_43 ( V_2 , V_96 , - 1 , V_30 ++ ) ;
V_6 -> V_43 ( V_2 , V_96 , - 1 , V_30 ) ;
V_6 -> V_43 ( V_2 , V_97 , - 1 , - 1 ) ;
}
static int F_94 ( struct V_1 * V_2 , struct V_53 * V_238 )
{
return F_28 ( V_2 , V_238 , 0 ) ;
}
int F_28 ( struct V_1 * V_2 , struct V_53 * V_238 ,
int V_74 )
{
int V_30 , V_120 , V_239 , V_8 , V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_240 [ V_241 ] = { 0 } ;
unsigned int V_242 = 0xffffffff ;
T_1 V_4 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_238 -> V_55 ,
( unsigned long long ) V_238 -> V_4 ) ;
if ( F_1 ( V_2 , V_238 -> V_55 , V_238 -> V_4 ) )
return - V_11 ;
F_24 ( V_6 , V_2 , V_121 ) ;
V_30 = ( int ) ( V_238 -> V_55 >> V_6 -> V_37 ) ;
V_20 = ( int ) ( V_238 -> V_55 >> V_6 -> V_39 ) ;
V_239 = 1 << ( V_6 -> V_9 - V_6 -> V_37 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( F_31 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_238 -> V_16 = V_134 ;
goto V_243;
}
if ( V_6 -> V_41 & V_244 && ! V_74 )
V_242 = V_6 -> V_245 -> V_246 [ V_20 ] & V_247 ;
V_4 = V_238 -> V_4 ;
V_238 -> V_16 = V_248 ;
while ( V_4 ) {
if ( F_32 ( V_2 , ( ( T_1 ) V_30 ) <<
V_6 -> V_37 , 0 , V_74 ) ) {
F_95 ( L_14 ,
V_10 , V_30 ) ;
V_238 -> V_16 = V_134 ;
goto V_243;
}
if ( V_30 <= V_6 -> V_198 && V_6 -> V_198 <
( V_30 + V_239 ) )
V_6 -> V_198 = - 1 ;
V_6 -> V_249 ( V_2 , V_30 & V_6 -> V_38 ) ;
V_120 = V_6 -> V_128 ( V_2 , V_6 ) ;
if ( ( V_120 & V_212 ) && ( V_6 -> V_226 ) )
V_120 = V_6 -> V_226 ( V_2 , V_6 , V_121 ,
V_120 , V_30 ) ;
if ( V_120 & V_212 ) {
F_2 ( L_15 ,
V_10 , V_30 ) ;
V_238 -> V_16 = V_134 ;
V_238 -> V_250 =
( ( T_1 ) V_30 << V_6 -> V_37 ) ;
goto V_243;
}
if ( V_242 != 0xffffffff &&
( V_30 & V_247 ) == V_242 )
V_240 [ V_20 ] =
( ( T_1 ) V_30 << V_6 -> V_37 ) ;
V_4 -= ( 1 << V_6 -> V_9 ) ;
V_30 += V_239 ;
if ( V_4 && ! ( V_30 & V_6 -> V_38 ) ) {
V_20 ++ ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_12 ( V_2 , V_20 ) ;
if ( V_242 != 0xffffffff &&
( V_6 -> V_245 -> V_41 & V_251 ) )
V_242 = V_6 -> V_245 -> V_246 [ V_20 ] &
V_247 ;
}
}
V_238 -> V_16 = V_252 ;
V_243:
V_8 = V_238 -> V_16 == V_252 ? 0 : - V_129 ;
F_3 ( V_2 ) ;
if ( ! V_8 )
F_96 ( V_238 ) ;
if ( V_242 == 0xffffffff || V_8 )
return V_8 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_253 ; V_20 ++ ) {
if ( ! V_240 [ V_20 ] )
continue;
F_2 ( L_16 ,
V_10 , V_20 , V_240 [ V_20 ] ,
V_6 -> V_245 -> V_246 [ V_20 ] ) ;
F_30 ( V_2 , V_240 [ V_20 ] ) ;
}
return V_8 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_17 , V_10 ) ;
F_24 ( V_6 , V_2 , V_254 ) ;
F_3 ( V_2 ) ;
}
static int F_98 ( struct V_1 * V_2 , T_1 V_255 )
{
return F_32 ( V_2 , V_255 , 1 , 0 ) ;
}
static int F_99 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_98 ( V_2 , V_3 ) ;
if ( V_8 ) {
if ( V_8 > 0 )
return 0 ;
return V_8 ;
}
return V_6 -> V_256 ( V_2 , V_3 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_24 ( V_6 , V_2 , V_118 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_16 == V_118 )
F_3 ( V_2 ) ;
else
F_102 ( L_18 ,
V_10 ) ;
}
static void F_103 ( struct V_5 * V_6 , int V_176 )
{
if ( ! V_6 -> V_99 )
V_6 -> V_99 = 20 ;
if ( V_6 -> V_43 == NULL )
V_6 -> V_43 = F_41 ;
if ( V_6 -> V_128 == NULL )
V_6 -> V_128 = F_52 ;
if ( ! V_6 -> V_12 )
V_6 -> V_12 = F_13 ;
if ( ! V_6 -> V_47 )
V_6 -> V_47 = V_176 ? F_9 : F_7 ;
if ( ! V_6 -> V_46 )
V_6 -> V_46 = F_12 ;
if ( ! V_6 -> V_75 )
V_6 -> V_75 = F_23 ;
if ( ! V_6 -> V_256 )
V_6 -> V_256 = F_27 ;
if ( ! V_6 -> V_211 )
V_6 -> V_211 = V_176 ? F_19 : F_15 ;
if ( ! V_6 -> V_137 )
V_6 -> V_137 = V_176 ? F_21 : F_17 ;
if ( ! V_6 -> V_227 )
V_6 -> V_227 = V_176 ? F_22 : F_18 ;
if ( ! V_6 -> V_257 )
V_6 -> V_257 = V_258 ;
if ( ! V_6 -> V_13 ) {
V_6 -> V_13 = & V_6 -> V_259 ;
F_104 ( & V_6 -> V_13 -> V_14 ) ;
F_105 ( & V_6 -> V_13 -> V_18 ) ;
}
}
static void F_106 ( T_3 * V_260 , T_8 V_4 )
{
T_9 V_25 ;
V_260 [ V_4 - 1 ] = 0 ;
for ( V_25 = 0 ; V_25 < V_4 - 1 ; V_25 ++ ) {
if ( V_260 [ V_25 ] < ' ' || V_260 [ V_25 ] > 127 )
V_260 [ V_25 ] = '?' ;
}
F_107 ( V_260 ) ;
}
static T_4 F_108 ( T_4 V_261 , T_10 const * V_28 , T_8 V_4 )
{
int V_25 ;
while ( V_4 -- ) {
V_261 ^= * V_28 ++ << 8 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
V_261 = ( V_261 << 1 ) ^ ( ( V_261 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_261 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_176 )
{
struct V_262 * V_28 = & V_6 -> V_263 ;
int V_25 ;
int V_264 ;
V_6 -> V_43 ( V_2 , V_265 , 0x20 , - 1 ) ;
if ( V_6 -> V_47 ( V_2 ) != 'O' || V_6 -> V_47 ( V_2 ) != 'N' ||
V_6 -> V_47 ( V_2 ) != 'F' || V_6 -> V_47 ( V_2 ) != 'I' )
return 0 ;
V_6 -> V_43 ( V_2 , V_266 , 0 , - 1 ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
V_6 -> V_137 ( V_2 , ( T_3 * ) V_28 , sizeof( * V_28 ) ) ;
if ( F_108 ( V_267 , ( T_3 * ) V_28 , 254 ) ==
F_110 ( V_28 -> V_261 ) ) {
F_111 ( L_19 , V_25 ) ;
break;
}
}
if ( V_25 == 3 )
return 0 ;
V_264 = F_110 ( V_28 -> V_268 ) ;
if ( V_264 & ( 1 << 5 ) )
V_6 -> V_269 = 23 ;
else if ( V_264 & ( 1 << 4 ) )
V_6 -> V_269 = 22 ;
else if ( V_264 & ( 1 << 3 ) )
V_6 -> V_269 = 21 ;
else if ( V_264 & ( 1 << 2 ) )
V_6 -> V_269 = 20 ;
else if ( V_264 & ( 1 << 1 ) )
V_6 -> V_269 = 10 ;
else
V_6 -> V_269 = 0 ;
if ( ! V_6 -> V_269 ) {
F_111 ( L_20 , V_10 , V_264 ) ;
return 0 ;
}
F_106 ( V_28 -> V_270 , sizeof( V_28 -> V_270 ) ) ;
F_106 ( V_28 -> V_271 , sizeof( V_28 -> V_271 ) ) ;
if ( ! V_2 -> V_272 )
V_2 -> V_272 = V_28 -> V_271 ;
V_2 -> V_36 = F_112 ( V_28 -> V_273 ) ;
V_2 -> V_35 = F_112 ( V_28 -> V_239 ) * V_2 -> V_36 ;
V_2 -> V_139 = F_110 ( V_28 -> V_274 ) ;
V_6 -> V_93 = F_112 ( V_28 -> V_275 ) ;
V_6 -> V_93 *= ( T_2 ) V_2 -> V_35 * V_28 -> V_276 ;
* V_176 = 0 ;
if ( F_110 ( V_28 -> V_277 ) & 1 )
* V_176 = V_42 ;
V_6 -> V_41 &= ~ V_278 ;
V_6 -> V_41 |= V_204 & V_278 ;
F_111 ( L_21 ) ;
return 1 ;
}
static struct V_279 * F_113 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int V_176 ,
int * V_280 , int * V_281 ,
struct V_279 * type )
{
int V_25 , V_282 ;
T_10 V_283 [ 8 ] ;
int V_8 ;
V_6 -> V_12 ( V_2 , 0 ) ;
V_6 -> V_43 ( V_2 , V_98 , - 1 , - 1 ) ;
V_6 -> V_43 ( V_2 , V_265 , 0x00 , - 1 ) ;
* V_280 = V_6 -> V_47 ( V_2 ) ;
* V_281 = V_6 -> V_47 ( V_2 ) ;
V_6 -> V_43 ( V_2 , V_265 , 0x00 , - 1 ) ;
for ( V_25 = 0 ; V_25 < 2 ; V_25 ++ )
V_283 [ V_25 ] = V_6 -> V_47 ( V_2 ) ;
if ( V_283 [ 0 ] != * V_280 || V_283 [ 1 ] != * V_281 ) {
F_111 ( L_22
L_23 , V_10 ,
* V_280 , * V_281 , V_283 [ 0 ] , V_283 [ 1 ] ) ;
return F_114 ( - V_284 ) ;
}
if ( ! type )
type = V_285 ;
for (; type -> V_272 != NULL ; type ++ )
if ( * V_281 == type -> V_286 )
break;
V_6 -> V_269 = 0 ;
if ( ! type -> V_272 || ! type -> V_287 ) {
V_8 = F_109 ( V_2 , V_6 , & V_176 ) ;
if ( V_8 )
goto V_288;
}
V_6 -> V_43 ( V_2 , V_265 , 0x00 , - 1 ) ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
V_283 [ V_25 ] = V_6 -> V_47 ( V_2 ) ;
if ( ! type -> V_272 )
return F_114 ( - V_284 ) ;
if ( ! V_2 -> V_272 )
V_2 -> V_272 = type -> V_272 ;
V_6 -> V_93 = ( T_2 ) type -> V_93 << 20 ;
if ( ! type -> V_287 && V_6 -> V_289 ) {
V_176 = V_6 -> V_289 ( V_2 , V_6 , V_283 ) ;
} else if ( ! type -> V_287 ) {
int V_290 ;
V_6 -> V_291 = V_283 [ 2 ] ;
V_290 = V_283 [ 3 ] ;
if ( V_283 [ 0 ] == V_283 [ 6 ] && V_283 [ 1 ] == V_283 [ 7 ] &&
V_283 [ 0 ] == V_292 &&
( V_6 -> V_291 & V_293 ) &&
V_283 [ 5 ] != 0x00 ) {
V_2 -> V_36 = 2048 << ( V_290 & 0x03 ) ;
V_290 >>= 2 ;
switch ( V_290 & 0x03 ) {
case 1 :
V_2 -> V_139 = 128 ;
break;
case 2 :
V_2 -> V_139 = 218 ;
break;
case 3 :
V_2 -> V_139 = 400 ;
break;
default:
V_2 -> V_139 = 436 ;
break;
}
V_290 >>= 2 ;
V_2 -> V_35 = ( 128 * 1024 ) <<
( ( ( V_290 >> 1 ) & 0x04 ) | ( V_290 & 0x03 ) ) ;
V_176 = 0 ;
} else {
V_2 -> V_36 = 1024 << ( V_290 & 0x03 ) ;
V_290 >>= 2 ;
V_2 -> V_139 = ( 8 << ( V_290 & 0x01 ) ) *
( V_2 -> V_36 >> 9 ) ;
V_290 >>= 2 ;
V_2 -> V_35 = ( 64 * 1024 ) << ( V_290 & 0x03 ) ;
V_290 >>= 2 ;
V_176 = ( V_290 & 0x01 ) ? V_42 : 0 ;
}
} else {
V_2 -> V_35 = type -> V_35 ;
V_2 -> V_36 = type -> V_287 ;
V_2 -> V_139 = V_2 -> V_36 / 32 ;
V_176 = type -> V_41 & V_42 ;
if ( * V_280 == V_294 && V_283 [ 4 ] != 0x00 &&
V_283 [ 5 ] == 0x00 && V_283 [ 6 ] == 0x00 &&
V_283 [ 7 ] == 0x00 && V_2 -> V_36 == 512 ) {
V_2 -> V_35 = 128 * 1024 ;
V_2 -> V_35 <<= ( ( V_283 [ 3 ] & 0x03 ) << 1 ) ;
}
}
V_6 -> V_41 &= ~ V_278 ;
V_6 -> V_41 |= type -> V_41 & V_278 ;
if ( * V_280 != V_292 && ! type -> V_287 )
V_6 -> V_41 &= ~ V_295 ;
V_288:
for ( V_282 = 0 ; V_296 [ V_282 ] . V_286 != 0x0 ; V_282 ++ ) {
if ( V_296 [ V_282 ] . V_286 == * V_280 )
break;
}
if ( V_176 != ( V_6 -> V_41 & V_42 ) ) {
F_111 ( L_24
L_25 , * V_280 ,
* V_281 , V_296 [ V_282 ] . V_272 , V_2 -> V_272 ) ;
F_95 ( L_26 ,
( V_6 -> V_41 & V_42 ) ? 16 : 8 ,
V_176 ? 16 : 8 ) ;
return F_114 ( - V_11 ) ;
}
V_6 -> V_37 = F_115 ( V_2 -> V_36 ) - 1 ;
V_6 -> V_38 = ( V_6 -> V_93 >> V_6 -> V_37 ) - 1 ;
V_6 -> V_56 = V_6 -> V_9 =
F_115 ( V_2 -> V_35 ) - 1 ;
if ( V_6 -> V_93 & 0xffffffff )
V_6 -> V_39 = F_115 ( ( unsigned ) V_6 -> V_93 ) - 1 ;
else {
V_6 -> V_39 = F_115 ( ( unsigned ) ( V_6 -> V_93 >> 32 ) ) ;
V_6 -> V_39 += 32 - 1 ;
}
V_6 -> V_48 = 8 ;
if ( V_2 -> V_36 > 512 || ( V_176 & V_42 ) )
V_6 -> V_45 = V_297 ;
else
V_6 -> V_45 = V_298 ;
if ( ( V_6 -> V_291 & V_293 ) &&
( * V_280 == V_292 ||
* V_280 == V_299 ) )
V_6 -> V_33 |= V_34 ;
else if ( ( ! ( V_6 -> V_291 & V_293 ) &&
( * V_280 == V_292 ||
* V_280 == V_299 ||
* V_280 == V_300 ||
* V_280 == V_294 ||
* V_280 == V_301 ) ) ||
( V_2 -> V_36 == 2048 &&
* V_280 == V_302 ) )
V_6 -> V_33 |= V_49 ;
if ( V_6 -> V_41 & V_303 )
V_6 -> V_249 = F_93 ;
else
V_6 -> V_249 = F_92 ;
if ( V_2 -> V_36 > 512 && V_6 -> V_43 == F_41 )
V_6 -> V_43 = F_44 ;
F_111 ( L_27
L_28 ,
* V_280 , * V_281 , V_296 [ V_282 ] . V_272 ,
V_6 -> V_269 ? V_6 -> V_263 . V_271 : type -> V_272 ,
V_2 -> V_36 , V_2 -> V_139 ) ;
return type ;
}
int F_116 ( struct V_1 * V_2 , int V_304 ,
struct V_279 * V_305 )
{
int V_25 , V_176 , V_306 , V_307 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_279 * type ;
V_176 = V_6 -> V_41 & V_42 ;
F_103 ( V_6 , V_176 ) ;
type = F_113 ( V_2 , V_6 , V_176 ,
& V_306 , & V_307 , V_305 ) ;
if ( F_117 ( type ) ) {
if ( ! ( V_6 -> V_41 & V_308 ) )
F_95 ( L_29 ) ;
V_6 -> V_12 ( V_2 , - 1 ) ;
return F_118 ( type ) ;
}
for ( V_25 = 1 ; V_25 < V_304 ; V_25 ++ ) {
V_6 -> V_12 ( V_2 , V_25 ) ;
V_6 -> V_43 ( V_2 , V_98 , - 1 , - 1 ) ;
V_6 -> V_43 ( V_2 , V_265 , 0x00 , - 1 ) ;
if ( V_306 != V_6 -> V_47 ( V_2 ) ||
V_307 != V_6 -> V_47 ( V_2 ) )
break;
}
if ( V_25 > 1 )
F_111 ( L_30 , V_25 ) ;
V_6 -> V_253 = V_25 ;
V_2 -> V_130 = V_25 * V_6 -> V_93 ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_120 ( ( V_6 -> V_33 & V_52 ) &&
! ( V_6 -> V_33 & V_68 ) ) ;
if ( ! ( V_6 -> V_41 & V_309 ) )
V_6 -> V_150 = F_121 ( sizeof( * V_6 -> V_150 ) , V_310 ) ;
if ( ! V_6 -> V_150 )
return - V_311 ;
V_6 -> V_138 = V_6 -> V_150 -> V_199 + V_2 -> V_36 ;
if ( ! V_6 -> V_141 . V_155 && ( V_6 -> V_141 . V_66 != V_312 ) ) {
switch ( V_2 -> V_139 ) {
case 8 :
V_6 -> V_141 . V_155 = & V_313 ;
break;
case 16 :
V_6 -> V_141 . V_155 = & V_314 ;
break;
case 64 :
V_6 -> V_141 . V_155 = & V_315 ;
break;
case 128 :
V_6 -> V_141 . V_155 = & V_316 ;
break;
default:
F_95 ( L_31 ,
V_2 -> V_139 ) ;
F_14 () ;
}
}
if ( ! V_6 -> V_224 )
V_6 -> V_224 = F_83 ;
switch ( V_6 -> V_141 . V_66 ) {
case V_317 :
if ( ! V_6 -> V_141 . V_158 || ! V_6 -> V_141 . V_161 ||
! V_6 -> V_141 . V_178 ) {
F_95 ( L_32
L_33 ) ;
F_14 () ;
}
if ( ! V_6 -> V_141 . V_201 )
V_6 -> V_141 . V_201 = F_63 ;
case V_318 :
if ( ! V_6 -> V_141 . V_201 )
V_6 -> V_141 . V_201 = F_62 ;
if ( ! V_6 -> V_141 . V_224 )
V_6 -> V_141 . V_224 = F_81 ;
if ( ! V_6 -> V_141 . V_157 )
V_6 -> V_141 . V_157 = F_57 ;
if ( ! V_6 -> V_141 . V_220 )
V_6 -> V_141 . V_220 = F_78 ;
if ( ! V_6 -> V_141 . V_217 )
V_6 -> V_141 . V_217 = F_72 ;
if ( ! V_6 -> V_141 . V_51 )
V_6 -> V_141 . V_51 = F_74 ;
case V_319 :
if ( ( ! V_6 -> V_141 . V_158 || ! V_6 -> V_141 . V_161 ||
! V_6 -> V_141 . V_178 ) &&
( ! V_6 -> V_141 . V_201 ||
V_6 -> V_141 . V_201 == F_62 ||
! V_6 -> V_141 . V_224 ||
V_6 -> V_141 . V_224 == F_81 ) ) {
F_95 ( L_32
L_33 ) ;
F_14 () ;
}
if ( ! V_6 -> V_141 . V_201 )
V_6 -> V_141 . V_201 = F_64 ;
if ( ! V_6 -> V_141 . V_224 )
V_6 -> V_141 . V_224 = F_82 ;
if ( ! V_6 -> V_141 . V_157 )
V_6 -> V_141 . V_157 = F_58 ;
if ( ! V_6 -> V_141 . V_220 )
V_6 -> V_141 . V_220 = F_79 ;
if ( ! V_6 -> V_141 . V_217 )
V_6 -> V_141 . V_217 = F_73 ;
if ( ! V_6 -> V_141 . V_51 )
V_6 -> V_141 . V_51 = F_75 ;
if ( V_2 -> V_36 >= V_6 -> V_141 . V_130 ) {
if ( ! V_6 -> V_141 . V_320 ) {
F_95 ( L_34 ) ;
F_14 () ;
}
break;
}
F_95 ( L_35
L_36 ,
V_6 -> V_141 . V_130 , V_2 -> V_36 ) ;
V_6 -> V_141 . V_66 = V_321 ;
case V_321 :
V_6 -> V_141 . V_158 = V_322 ;
V_6 -> V_141 . V_161 = V_323 ;
V_6 -> V_141 . V_201 = F_59 ;
V_6 -> V_141 . V_200 = F_61 ;
V_6 -> V_141 . V_224 = F_80 ;
V_6 -> V_141 . V_157 = F_57 ;
V_6 -> V_141 . V_220 = F_78 ;
V_6 -> V_141 . V_217 = F_72 ;
V_6 -> V_141 . V_51 = F_74 ;
if ( ! V_6 -> V_141 . V_130 )
V_6 -> V_141 . V_130 = 256 ;
V_6 -> V_141 . V_143 = 3 ;
V_6 -> V_141 . V_320 = 1 ;
break;
case V_312 :
if ( ! F_122 () ) {
F_95 ( L_37 ) ;
F_14 () ;
}
V_6 -> V_141 . V_158 = V_324 ;
V_6 -> V_141 . V_161 = V_325 ;
V_6 -> V_141 . V_201 = F_59 ;
V_6 -> V_141 . V_200 = F_61 ;
V_6 -> V_141 . V_224 = F_80 ;
V_6 -> V_141 . V_157 = F_57 ;
V_6 -> V_141 . V_220 = F_78 ;
V_6 -> V_141 . V_217 = F_72 ;
V_6 -> V_141 . V_51 = F_74 ;
if ( ! V_6 -> V_141 . V_130 && ( V_2 -> V_139 >= 64 ) ) {
V_6 -> V_141 . V_130 = 512 ;
V_6 -> V_141 . V_143 = 7 ;
}
V_6 -> V_141 . V_7 = F_123 ( V_2 ,
V_6 -> V_141 . V_130 ,
V_6 -> V_141 . V_143 ,
& V_6 -> V_141 . V_155 ) ;
if ( ! V_6 -> V_141 . V_7 ) {
F_95 ( L_38 ) ;
F_14 () ;
}
V_6 -> V_141 . V_320 =
V_6 -> V_141 . V_143 * 8 / F_124 ( 8 * V_6 -> V_141 . V_130 ) ;
break;
case V_326 :
F_95 ( L_39
L_40 ) ;
V_6 -> V_141 . V_201 = F_57 ;
V_6 -> V_141 . V_224 = F_78 ;
V_6 -> V_141 . V_217 = F_72 ;
V_6 -> V_141 . V_157 = F_57 ;
V_6 -> V_141 . V_220 = F_78 ;
V_6 -> V_141 . V_51 = F_74 ;
V_6 -> V_141 . V_130 = V_2 -> V_36 ;
V_6 -> V_141 . V_143 = 0 ;
V_6 -> V_141 . V_320 = 0 ;
break;
default:
F_95 ( L_41 , V_6 -> V_141 . V_66 ) ;
F_14 () ;
}
if ( ! V_6 -> V_141 . V_216 )
V_6 -> V_141 . V_216 = V_6 -> V_141 . V_217 ;
if ( ! V_6 -> V_141 . V_237 )
V_6 -> V_141 . V_237 = V_6 -> V_141 . V_51 ;
V_6 -> V_141 . V_155 -> V_197 = 0 ;
for ( V_25 = 0 ; V_6 -> V_141 . V_155 -> V_184 [ V_25 ] . V_187
&& V_25 < F_125 ( V_6 -> V_141 . V_155 -> V_184 ) ; V_25 ++ )
V_6 -> V_141 . V_155 -> V_197 +=
V_6 -> V_141 . V_155 -> V_184 [ V_25 ] . V_187 ;
V_2 -> V_197 = V_6 -> V_141 . V_155 -> V_197 ;
V_6 -> V_141 . V_145 = V_2 -> V_36 / V_6 -> V_141 . V_130 ;
if ( V_6 -> V_141 . V_145 * V_6 -> V_141 . V_130 != V_2 -> V_36 ) {
F_95 ( L_42 ) ;
F_14 () ;
}
V_6 -> V_141 . V_159 = V_6 -> V_141 . V_145 * V_6 -> V_141 . V_143 ;
if ( ! ( V_6 -> V_41 & V_327 ) &&
! ( V_6 -> V_291 & V_293 ) ) {
switch ( V_6 -> V_141 . V_145 ) {
case 2 :
V_2 -> V_328 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_328 = 2 ;
break;
}
}
V_6 -> V_329 = V_2 -> V_36 >> V_2 -> V_328 ;
V_6 -> V_16 = V_17 ;
V_6 -> V_12 ( V_2 , - 1 ) ;
V_6 -> V_198 = - 1 ;
V_2 -> type = V_330 ;
V_2 -> V_331 = ( V_6 -> V_41 & V_332 ) ? V_333 :
V_334 ;
V_2 -> V_335 = F_94 ;
V_2 -> V_336 = NULL ;
V_2 -> V_337 = NULL ;
V_2 -> V_338 = F_71 ;
V_2 -> V_339 = F_90 ;
V_2 -> V_340 = F_89 ;
V_2 -> V_341 = F_77 ;
V_2 -> V_342 = F_91 ;
V_2 -> V_343 = F_97 ;
V_2 -> V_344 = NULL ;
V_2 -> V_345 = NULL ;
V_2 -> V_346 = F_100 ;
V_2 -> V_347 = F_101 ;
V_2 -> V_348 = F_98 ;
V_2 -> V_349 = F_99 ;
V_2 -> V_350 = V_2 -> V_36 ;
V_2 -> V_351 = V_6 -> V_141 . V_155 ;
V_2 -> V_352 = V_6 -> V_141 . V_320 ;
if ( ! V_2 -> V_353 )
V_2 -> V_353 = V_2 -> V_352 ;
if ( V_6 -> V_41 & V_354 )
return 0 ;
return V_6 -> V_257 ( V_2 ) ;
}
int F_126 ( struct V_1 * V_2 , int V_304 )
{
int V_8 ;
if ( ! V_2 -> V_355 && F_127 () ) {
F_128 ( L_43 , V_10 ) ;
F_14 () ;
}
V_8 = F_116 ( V_2 , V_304 , NULL ) ;
if ( ! V_8 )
V_8 = F_119 ( V_2 ) ;
return V_8 ;
}
void F_129 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_141 . V_66 == V_312 )
F_130 ( (struct V_356 * ) V_6 -> V_141 . V_7 ) ;
F_131 ( V_2 ) ;
F_132 ( V_6 -> V_57 ) ;
if ( ! ( V_6 -> V_41 & V_309 ) )
F_132 ( V_6 -> V_150 ) ;
if ( V_6 -> V_357 && V_6 -> V_357 -> V_41
& V_358 )
F_132 ( V_6 -> V_357 ) ;
}
static int T_11 F_133 ( void )
{
F_134 ( L_44 , & V_80 ) ;
return 0 ;
}
static void T_12 F_135 ( void )
{
F_136 ( V_80 ) ;
}
