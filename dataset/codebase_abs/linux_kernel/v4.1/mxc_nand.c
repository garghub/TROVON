static void F_1 ( void * V_1 , const void T_1 * V_2 , T_2 V_3 )
{
int V_4 ;
T_3 * V_5 = V_1 ;
const T_1 T_3 * V_6 = V_2 ;
for ( V_4 = 0 ; V_4 < ( V_3 >> 2 ) ; V_4 ++ )
* V_5 ++ = F_2 ( V_6 ++ ) ;
}
static inline void F_3 ( void T_1 * V_1 , const void * V_2 , int V_3 )
{
F_4 ( V_1 , V_2 , V_3 / 4 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
T_4 V_9 ;
V_9 = F_6 ( V_10 ) ;
if ( ! ( V_9 & V_11 ) )
return 0 ;
V_9 &= ~ V_11 ;
F_7 ( V_9 , V_10 ) ;
return 1 ;
}
static int F_8 ( struct V_7 * V_8 )
{
T_4 V_9 ;
V_9 = F_9 ( V_12 ) ;
if ( ! ( V_9 & V_13 ) )
return 0 ;
if ( ! V_8 -> V_14 -> V_15 )
F_10 ( V_9 & ~ V_13 , V_12 ) ;
return 1 ;
}
static void F_11 ( struct V_7 * V_8 , int V_16 )
{
T_5 V_9 ;
V_9 = F_9 ( V_17 ) ;
if ( V_16 )
V_9 &= ~ V_18 ;
else
V_9 |= V_18 ;
F_10 ( V_9 , V_17 ) ;
}
static void F_12 ( struct V_7 * V_8 , int V_16 )
{
T_4 V_9 ;
V_9 = F_6 ( V_19 ) ;
if ( V_16 )
V_9 &= ~ V_20 ;
else
V_9 |= V_20 ;
F_7 ( V_9 , V_19 ) ;
}
static void F_13 ( struct V_7 * V_8 , int V_16 )
{
if ( V_8 -> V_14 -> V_15 ) {
if ( V_16 )
F_14 ( V_8 -> V_21 ) ;
else
F_15 ( V_8 -> V_21 ) ;
} else {
V_8 -> V_14 -> F_13 ( V_8 , V_16 ) ;
}
}
static T_3 F_16 ( struct V_7 * V_8 )
{
return F_9 ( V_22 ) ;
}
static T_3 F_17 ( struct V_7 * V_8 )
{
return F_6 ( V_22 ) ;
}
static T_3 F_18 ( struct V_7 * V_8 )
{
return F_6 ( V_23 ) ;
}
static T_6 F_19 ( int V_21 , void * V_24 )
{
struct V_7 * V_8 = V_24 ;
if ( ! V_8 -> V_14 -> V_25 ( V_8 ) )
return V_26 ;
F_13 ( V_8 , 0 ) ;
F_20 ( & V_8 -> V_27 ) ;
return V_28 ;
}
static int F_21 ( struct V_7 * V_8 , int V_29 )
{
int V_30 = 0 ;
if ( V_8 -> V_14 -> V_25 ( V_8 ) )
return 0 ;
if ( V_29 ) {
unsigned long V_31 ;
F_22 ( & V_8 -> V_27 ) ;
F_13 ( V_8 , 1 ) ;
V_31 = F_23 ( & V_8 -> V_27 , V_32 ) ;
if ( ! V_31 && ! V_8 -> V_14 -> V_25 ( V_8 ) ) {
F_24 ( V_8 -> V_33 , L_1 ) ;
V_30 = - V_34 ;
}
} else {
int V_35 = 8000 ;
int V_36 ;
do {
F_25 ( 1 ) ;
V_36 = V_8 -> V_14 -> V_25 ( V_8 ) ;
if ( V_36 )
break;
} while ( -- V_35 );
if ( ! V_36 ) {
F_24 ( V_8 -> V_33 , L_2 ) ;
V_30 = - V_34 ;
}
}
F_26 ( V_30 < 0 , L_3 , V_29 ) ;
return V_30 ;
}
static void F_27 ( struct V_7 * V_8 , T_5 V_37 , int V_29 )
{
F_7 ( V_37 , V_38 ) ;
F_7 ( V_39 , V_40 ) ;
F_21 ( V_8 , V_29 ) ;
}
static void F_28 ( struct V_7 * V_8 , T_5 V_37 , int V_29 )
{
F_29 ( L_4 , V_37 , V_29 ) ;
F_10 ( V_37 , V_41 ) ;
F_10 ( V_39 , V_12 ) ;
if ( V_8 -> V_14 -> V_15 && ( V_37 == V_42 ) ) {
int V_35 = 100 ;
while ( V_35 -- > 0 ) {
if ( F_9 ( V_12 ) == 0 ) {
break;
}
F_25 ( 1 ) ;
}
if ( V_35 < 0 )
F_29 ( L_5 , V_43 ) ;
} else {
F_21 ( V_8 , V_29 ) ;
}
}
static void F_30 ( struct V_7 * V_8 , T_5 V_44 , int V_45 )
{
F_7 ( V_44 , V_46 ) ;
F_7 ( V_47 , V_40 ) ;
F_21 ( V_8 , 0 ) ;
}
static void F_31 ( struct V_7 * V_8 , T_5 V_44 , int V_45 )
{
F_29 ( L_6 , V_44 , V_45 ) ;
F_10 ( V_44 , V_48 ) ;
F_10 ( V_47 , V_12 ) ;
F_21 ( V_8 , V_45 ) ;
}
static void F_32 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_4 V_9 ;
V_9 = F_6 ( V_54 ) ;
V_9 &= ~ ( 7 << 4 ) ;
F_7 ( V_9 , V_54 ) ;
F_7 ( V_51 , V_40 ) ;
F_21 ( V_8 , false ) ;
}
static void F_33 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
F_10 ( V_8 -> V_55 << 4 , V_56 ) ;
F_10 ( V_51 , V_12 ) ;
F_21 ( V_8 , true ) ;
}
static void F_34 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
int V_57 , V_4 ;
if ( V_50 -> V_58 > 512 )
V_57 = 4 ;
else
V_57 = 1 ;
for ( V_4 = 0 ; V_4 < V_57 ; V_4 ++ ) {
F_10 ( ( V_8 -> V_55 << 4 ) | V_4 , V_56 ) ;
F_10 ( V_51 , V_12 ) ;
F_21 ( V_8 , true ) ;
}
}
static void F_35 ( struct V_7 * V_8 )
{
F_7 ( V_59 , V_40 ) ;
F_21 ( V_8 , true ) ;
F_1 ( V_8 -> V_60 , V_8 -> V_61 , 16 ) ;
}
static void F_36 ( struct V_7 * V_8 )
{
F_10 ( V_8 -> V_55 << 4 , V_56 ) ;
F_10 ( V_59 , V_12 ) ;
F_21 ( V_8 , true ) ;
F_1 ( V_8 -> V_60 , V_8 -> V_61 , 16 ) ;
}
static T_5 F_37 ( struct V_7 * V_8 )
{
F_10 ( V_62 , V_40 ) ;
F_21 ( V_8 , true ) ;
return F_6 ( V_54 ) >> 16 ;
}
static T_5 F_38 ( struct V_7 * V_8 )
{
void T_1 * V_63 = V_8 -> V_61 ;
T_4 V_64 ;
T_5 V_30 ;
F_10 ( V_8 -> V_55 << 4 , V_56 ) ;
V_64 = F_6 ( V_63 ) ;
F_10 ( V_62 , V_12 ) ;
F_21 ( V_8 , true ) ;
V_30 = F_9 ( V_63 ) ;
F_7 ( V_64 , V_63 ) ;
return V_30 ;
}
static int F_39 ( struct V_49 * V_50 )
{
return 1 ;
}
static void F_40 ( struct V_49 * V_50 , int V_65 )
{
}
static int F_41 ( struct V_49 * V_50 , T_7 * V_66 ,
T_7 * V_67 , T_7 * V_68 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_5 V_69 = F_16 ( V_8 ) ;
if ( ( ( V_69 & 0x3 ) == 2 ) || ( ( V_69 >> 2 ) == 2 ) ) {
F_29 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_42 ( struct V_49 * V_50 , T_7 * V_66 ,
T_7 * V_67 , T_7 * V_68 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_3 V_70 , V_71 ;
int V_72 = 1 ;
int V_30 = 0 ;
T_8 V_73 , V_74 ;
V_73 = ( V_8 -> V_75 == 4 ) ? 0x7 : 0xf ;
V_74 = ( V_8 -> V_75 == 4 ) ? 0x4 : 0x8 ;
V_72 = V_50 -> V_58 >> 9 ;
V_70 = V_8 -> V_14 -> V_76 ( V_8 ) ;
do {
V_71 = V_70 & V_73 ;
if ( V_71 > V_74 ) {
F_43 ( V_77 L_8 ) ;
return - 1 ;
} else {
V_30 += V_71 ;
}
V_70 >>= 4 ;
} while ( -- V_72 );
F_29 ( L_9 , V_30 ) ;
return V_30 ;
}
static int F_44 ( struct V_49 * V_50 , const T_7 * V_66 ,
T_7 * V_78 )
{
return 0 ;
}
static T_7 F_45 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_9 V_30 ;
if ( V_8 -> V_79 )
return V_8 -> V_14 -> V_80 ( V_8 ) & 0xFF ;
if ( V_52 -> V_81 & V_82 ) {
V_30 = * ( T_5 * ) ( V_8 -> V_60 + V_8 -> V_83 ) ;
V_8 -> V_83 += 2 ;
} else {
V_30 = * ( T_9 * ) ( V_8 -> V_60 + V_8 -> V_83 ) ;
V_8 -> V_83 ++ ;
}
F_29 ( L_10 , V_43 , V_30 , V_8 -> V_83 ) ;
return V_30 ;
}
static T_5 F_46 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_5 V_30 ;
V_30 = * ( T_5 * ) ( V_8 -> V_60 + V_8 -> V_83 ) ;
V_8 -> V_83 += 2 ;
return V_30 ;
}
static void F_47 ( struct V_49 * V_50 ,
const T_7 * V_84 , int V_85 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_10 V_86 = V_8 -> V_83 ;
int V_87 = V_50 -> V_88 + V_50 -> V_58 - V_86 ;
V_87 = F_48 ( V_87 , V_85 ) ;
memcpy ( V_8 -> V_60 + V_86 , V_84 , V_87 ) ;
V_8 -> V_83 += V_87 ;
}
static void F_49 ( struct V_49 * V_50 , T_7 * V_84 , int V_85 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_10 V_86 = V_8 -> V_83 ;
int V_87 = V_50 -> V_88 + V_50 -> V_58 - V_86 ;
V_87 = F_48 ( V_87 , V_85 ) ;
memcpy ( V_84 , V_8 -> V_60 + V_86 , V_87 ) ;
V_8 -> V_83 += V_87 ;
}
static void F_50 ( struct V_49 * V_50 , int V_89 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_51 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_52 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
}
static void F_53 ( struct V_49 * V_50 , int V_89 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_51 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_52 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
V_8 -> V_55 = V_89 ;
F_10 ( V_8 -> V_55 << 4 , V_56 ) ;
}
static void F_54 ( struct V_49 * V_50 , bool V_92 )
{
struct V_52 * V_93 = V_50 -> V_53 ;
struct V_7 * V_8 = V_93 -> V_53 ;
T_10 V_4 , V_94 ;
T_10 V_87 = V_50 -> V_58 >> 9 ;
T_8 * V_95 = V_8 -> V_60 + V_50 -> V_58 ;
T_8 T_1 * V_6 = V_8 -> V_96 ;
T_10 V_5 = V_8 -> V_14 -> V_97 ;
V_94 = ( V_50 -> V_88 / V_87 >> 1 ) << 1 ;
if ( V_92 ) {
for ( V_4 = 0 ; V_4 < V_87 - 1 ; V_4 ++ )
F_1 ( V_95 + V_4 * V_94 , V_6 + V_4 * V_5 , V_94 ) ;
F_1 ( V_95 + V_4 * V_94 , V_6 + V_4 * V_5 , V_50 -> V_88 - V_4 * V_94 ) ;
} else {
for ( V_4 = 0 ; V_4 < V_87 - 1 ; V_4 ++ )
F_3 ( & V_6 [ V_4 * V_5 ] , & V_95 [ V_4 * V_94 ] , V_94 ) ;
F_3 ( & V_6 [ V_4 * V_5 ] , & V_95 [ V_4 * V_94 ] , V_50 -> V_88 - V_4 * V_94 ) ;
}
}
static void F_55 ( struct V_49 * V_50 , int V_98 , int V_99 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
if ( V_98 != - 1 ) {
V_8 -> V_14 -> V_100 ( V_8 , V_98 & 0xff ,
V_99 == - 1 ) ;
if ( V_50 -> V_58 > 512 )
V_8 -> V_14 -> V_100 ( V_8 ,
( V_98 >> 8 ) & 0xff ,
false ) ;
}
if ( V_99 != - 1 ) {
V_8 -> V_14 -> V_100 ( V_8 , ( V_99 & 0xff ) , false ) ;
if ( V_50 -> V_58 > 512 ) {
if ( V_50 -> V_3 >= 0x10000000 ) {
V_8 -> V_14 -> V_100 ( V_8 ,
( V_99 >> 8 ) & 0xff ,
false ) ;
V_8 -> V_14 -> V_100 ( V_8 ,
( V_99 >> 16 ) & 0xff ,
true ) ;
} else
V_8 -> V_14 -> V_100 ( V_8 ,
( V_99 >> 8 ) & 0xff , true ) ;
} else {
if ( V_50 -> V_3 >= 0x4000000 ) {
V_8 -> V_14 -> V_100 ( V_8 ,
( V_99 >> 8 ) & 0xff ,
false ) ;
V_8 -> V_14 -> V_100 ( V_8 ,
( V_99 >> 16 ) & 0xff ,
true ) ;
} else
V_8 -> V_14 -> V_100 ( V_8 ,
( V_99 >> 8 ) & 0xff , true ) ;
}
}
}
static int F_56 ( struct V_49 * V_50 )
{
int V_101 = 0 ;
V_101 = V_50 -> V_88 * 512 / V_50 -> V_58 ;
if ( V_101 < 26 )
return 4 ;
else
return 8 ;
}
static void F_57 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_5 V_102 = 0 ;
if ( V_52 -> V_103 . V_65 == V_104 && V_50 -> V_58 )
V_102 |= V_105 ;
if ( ! V_8 -> V_14 -> V_15 )
V_102 |= V_18 ;
V_8 -> V_75 = 1 ;
F_10 ( V_102 , V_17 ) ;
F_10 ( 0x2 , V_106 ) ;
F_10 ( 0x0 , V_107 ) ;
F_10 ( 0xffff , V_108 ) ;
F_10 ( 0x4 , V_109 ) ;
}
static void F_58 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_5 V_102 = 0 ;
V_102 |= V_110 ;
if ( ! V_8 -> V_14 -> V_15 )
V_102 |= V_18 ;
if ( V_50 -> V_58 ) {
T_5 V_111 = V_50 -> V_112 / V_50 -> V_58 ;
if ( V_52 -> V_103 . V_65 == V_104 )
V_102 |= V_105 ;
V_8 -> V_75 = F_56 ( V_50 ) ;
if ( V_8 -> V_75 == 4 )
V_102 |= V_113 ;
V_102 |= F_59 ( F_60 ( V_111 ) - 6 ) ;
} else {
V_8 -> V_75 = 1 ;
}
F_10 ( V_102 , V_17 ) ;
F_10 ( 0x2 , V_106 ) ;
F_10 ( 0x0 , V_114 ) ;
F_10 ( 0x0 , V_115 ) ;
F_10 ( 0x0 , V_116 ) ;
F_10 ( 0x0 , V_117 ) ;
F_10 ( 0xffff , V_118 ) ;
F_10 ( 0xffff , V_119 ) ;
F_10 ( 0xffff , V_120 ) ;
F_10 ( 0xffff , V_121 ) ;
F_10 ( 0x4 , V_109 ) ;
}
static void F_61 ( struct V_49 * V_50 )
{
struct V_52 * V_89 = V_50 -> V_53 ;
struct V_7 * V_8 = V_89 -> V_53 ;
T_4 V_122 , V_123 ;
int V_4 , V_124 ;
F_7 ( F_62 ( 0 ) , V_54 ) ;
F_7 ( V_125 , V_10 ) ;
F_7 ( V_126 | V_127 ,
V_128 ) ;
for ( V_4 = 0 ; V_4 < V_129 ; V_4 ++ )
F_7 ( 0x0 | ( 0xffff << 16 ) ,
V_130 + ( V_4 << 2 ) ) ;
F_7 ( 0 , V_10 ) ;
V_122 = V_131 |
V_132 |
F_63 ( V_50 -> V_88 >> 1 ) |
F_64 ( 0x70 ) |
V_20 |
V_133 ;
V_124 = F_65 ( V_89 -> V_134 ) >> 3 ;
if ( V_50 -> V_58 == 2048 ) {
V_122 |= V_135 ;
V_122 |= F_66 ( V_124 ) ;
} else if ( V_50 -> V_58 == 4096 ) {
V_122 |= V_136 ;
V_122 |= F_66 ( V_124 ) ;
} else {
V_122 |= V_137 ;
V_122 |= F_66 ( V_124 - 1 ) ;
}
if ( V_50 -> V_58 ) {
if ( V_89 -> V_103 . V_65 == V_104 )
V_122 |= V_138 ;
V_122 |= F_67 (
F_60 ( V_50 -> V_112 / V_50 -> V_58 ) - 6 ,
V_8 -> V_14 -> V_139 ) ;
V_8 -> V_75 = F_56 ( V_50 ) ;
if ( V_8 -> V_75 == 8 )
V_122 |= V_140 ;
}
F_7 ( V_122 , V_19 ) ;
V_123 = F_68 ( 0 ) |
V_141 |
V_142 |
F_69 ( 6 ) |
F_70 ( 0 ) ;
if ( ! ( V_89 -> V_81 & V_82 ) )
V_123 |= V_143 ;
F_7 ( V_123 , V_144 ) ;
F_7 ( 0 , V_145 ) ;
}
static void F_71 ( struct V_49 * V_50 , unsigned V_146 ,
int V_98 , int V_99 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
F_29 ( L_11 ,
V_146 , V_98 , V_99 ) ;
V_8 -> V_79 = false ;
switch ( V_146 ) {
case V_42 :
V_8 -> V_14 -> V_147 ( V_50 ) ;
V_8 -> V_14 -> V_148 ( V_8 , V_146 , false ) ;
break;
case V_149 :
V_8 -> V_83 = 0 ;
V_8 -> V_79 = true ;
V_8 -> V_14 -> V_148 ( V_8 , V_146 , true ) ;
F_26 ( V_98 != - 1 || V_99 != - 1 ,
L_12 ,
V_146 , V_98 , V_99 ) ;
F_55 ( V_50 , V_98 , V_99 ) ;
break;
case V_150 :
case V_151 :
if ( V_146 == V_150 )
V_8 -> V_83 = V_98 ;
else
V_8 -> V_83 = V_98 + V_50 -> V_58 ;
V_146 = V_150 ;
V_8 -> V_14 -> V_148 ( V_8 , V_146 , false ) ;
F_26 ( V_98 < 0 ,
L_12 ,
V_146 , V_98 , V_99 ) ;
F_55 ( V_50 , 0 , V_99 ) ;
if ( V_50 -> V_58 > 512 )
V_8 -> V_14 -> V_148 ( V_8 ,
V_152 , true ) ;
V_8 -> V_14 -> V_153 ( V_50 , V_154 ) ;
F_1 ( V_8 -> V_60 , V_8 -> V_61 ,
V_50 -> V_58 ) ;
F_54 ( V_50 , true ) ;
break;
case V_155 :
if ( V_98 >= V_50 -> V_58 )
F_71 ( V_50 , V_150 , 0 , V_99 ) ;
V_8 -> V_83 = V_98 ;
V_8 -> V_14 -> V_148 ( V_8 , V_146 , false ) ;
F_26 ( V_98 < - 1 ,
L_12 ,
V_146 , V_98 , V_99 ) ;
F_55 ( V_50 , 0 , V_99 ) ;
break;
case V_156 :
F_3 ( V_8 -> V_61 , V_8 -> V_60 , V_50 -> V_58 ) ;
F_54 ( V_50 , false ) ;
V_8 -> V_14 -> V_153 ( V_50 , V_157 ) ;
V_8 -> V_14 -> V_148 ( V_8 , V_146 , true ) ;
F_26 ( V_98 != - 1 || V_99 != - 1 ,
L_12 ,
V_146 , V_98 , V_99 ) ;
F_55 ( V_50 , V_98 , V_99 ) ;
break;
case V_158 :
V_8 -> V_14 -> V_148 ( V_8 , V_146 , true ) ;
F_55 ( V_50 , V_98 , V_99 ) ;
V_8 -> V_14 -> V_159 ( V_8 ) ;
V_8 -> V_83 = 0 ;
break;
case V_160 :
case V_161 :
V_8 -> V_14 -> V_148 ( V_8 , V_146 , false ) ;
F_26 ( V_98 != - 1 ,
L_13 ,
V_146 , V_98 ) ;
F_55 ( V_50 , V_98 , V_99 ) ;
break;
case V_162 :
V_8 -> V_14 -> V_148 ( V_8 , V_146 , false ) ;
F_55 ( V_50 , V_98 , V_99 ) ;
V_8 -> V_14 -> V_153 ( V_50 , V_154 ) ;
F_1 ( V_8 -> V_60 , V_8 -> V_61 , 512 ) ;
V_8 -> V_83 = 0 ;
break;
default:
F_26 ( 1 , L_14 ,
V_146 ) ;
break;
}
}
static inline int F_72 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_163 ;
}
static inline int F_73 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_164 ;
}
static inline int F_74 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_165 ;
}
static inline int F_75 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_166 ;
}
static inline int F_76 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_167 ;
}
static int T_11 F_77 ( struct V_7 * V_8 )
{
struct V_168 * V_169 = V_8 -> V_33 -> V_170 ;
struct V_171 * V_172 = & V_8 -> V_172 ;
const struct V_173 * V_174 =
F_78 ( V_175 , V_8 -> V_33 ) ;
int V_176 ;
if ( ! V_169 )
return 1 ;
if ( F_79 ( V_169 ) >= 0 )
V_172 -> V_177 = 1 ;
V_172 -> V_178 = F_80 ( V_169 ) ;
V_176 = F_81 ( V_169 ) ;
if ( V_176 < 0 )
return V_176 ;
V_172 -> V_179 = V_176 / 8 ;
V_8 -> V_14 = V_174 -> V_180 ;
return 0 ;
}
static int T_11 F_77 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_82 ( struct V_181 * V_182 )
{
struct V_52 * V_93 ;
struct V_49 * V_50 ;
struct V_7 * V_8 ;
struct V_183 * V_184 ;
int V_71 = 0 ;
V_8 = F_83 ( & V_182 -> V_33 , sizeof( struct V_7 ) ,
V_185 ) ;
if ( ! V_8 )
return - V_186 ;
V_8 -> V_60 = F_83 ( & V_182 -> V_33 , V_187 , V_185 ) ;
if ( ! V_8 -> V_60 )
return - V_186 ;
V_8 -> V_33 = & V_182 -> V_33 ;
V_93 = & V_8 -> V_188 ;
V_50 = & V_8 -> V_50 ;
V_50 -> V_53 = V_93 ;
V_50 -> V_189 = V_190 ;
V_50 -> V_33 . V_191 = & V_182 -> V_33 ;
V_50 -> V_192 = V_193 ;
V_93 -> V_194 = 5 ;
V_93 -> V_53 = V_8 ;
V_93 -> V_195 = F_39 ;
V_93 -> V_196 = F_71 ;
V_93 -> V_197 = F_45 ;
V_93 -> V_198 = F_46 ;
V_93 -> V_199 = F_47 ;
V_93 -> V_200 = F_49 ;
V_8 -> V_91 = F_84 ( & V_182 -> V_33 , NULL ) ;
if ( F_85 ( V_8 -> V_91 ) )
return F_86 ( V_8 -> V_91 ) ;
V_71 = F_77 ( V_8 ) ;
if ( V_71 > 0 ) {
struct V_171 * V_172 =
F_87 ( & V_182 -> V_33 ) ;
if ( V_172 ) {
V_8 -> V_172 = * V_172 ;
V_8 -> V_14 = (struct V_201 * )
V_182 -> V_202 -> V_203 ;
} else {
V_71 = - V_204 ;
}
}
if ( V_71 < 0 )
return V_71 ;
if ( V_8 -> V_14 -> V_205 ) {
V_184 = F_88 ( V_182 , V_206 , 0 ) ;
V_8 -> V_207 = F_89 ( & V_182 -> V_33 , V_184 ) ;
if ( F_85 ( V_8 -> V_207 ) )
return F_86 ( V_8 -> V_207 ) ;
V_184 = F_88 ( V_182 , V_206 , 1 ) ;
} else {
V_184 = F_88 ( V_182 , V_206 , 0 ) ;
}
V_8 -> V_208 = F_89 ( & V_182 -> V_33 , V_184 ) ;
if ( F_85 ( V_8 -> V_208 ) )
return F_86 ( V_8 -> V_208 ) ;
V_8 -> V_61 = V_8 -> V_208 ;
if ( V_8 -> V_14 -> V_209 )
V_8 -> V_210 = V_8 -> V_208 + V_8 -> V_14 -> V_209 ;
V_8 -> V_96 = V_8 -> V_208 + V_8 -> V_14 -> V_211 ;
if ( V_8 -> V_14 -> V_212 )
V_8 -> V_213 = V_8 -> V_208 + V_8 -> V_14 -> V_212 ;
V_93 -> V_103 . V_214 = V_8 -> V_14 -> V_215 ;
V_8 -> V_75 = V_8 -> V_14 -> V_75 ;
V_93 -> V_216 = V_8 -> V_14 -> V_216 ;
V_93 -> V_103 . V_3 = 512 ;
V_93 -> V_103 . V_217 = V_8 -> V_14 -> V_218 ;
if ( V_8 -> V_172 . V_177 ) {
V_93 -> V_103 . V_219 = F_44 ;
V_93 -> V_103 . V_220 = F_40 ;
V_93 -> V_103 . V_221 = V_8 -> V_14 -> V_222 ;
V_93 -> V_103 . V_65 = V_104 ;
} else {
V_93 -> V_103 . V_65 = V_223 ;
}
if ( V_8 -> V_172 . V_179 == 2 )
V_93 -> V_81 |= V_82 ;
if ( V_8 -> V_172 . V_178 ) {
V_93 -> V_224 = & V_225 ;
V_93 -> V_226 = & V_227 ;
V_93 -> V_228 |= V_229 ;
}
F_90 ( & V_8 -> V_27 ) ;
V_8 -> V_21 = F_91 ( V_182 , 0 ) ;
if ( V_8 -> V_21 < 0 )
return V_8 -> V_21 ;
V_8 -> V_14 -> F_13 ( V_8 , 0 ) ;
V_71 = F_92 ( & V_182 -> V_33 , V_8 -> V_21 , F_19 ,
0 , V_193 , V_8 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_52 ( V_8 -> V_91 ) ;
if ( V_71 )
return V_71 ;
V_8 -> V_90 = 1 ;
if ( V_8 -> V_14 -> V_15 ) {
F_15 ( V_8 -> V_21 ) ;
V_8 -> V_14 -> F_13 ( V_8 , 1 ) ;
}
if ( F_93 ( V_50 , F_74 ( V_8 ) ? 4 : 1 , NULL ) ) {
V_71 = - V_230 ;
goto V_231;
}
F_94 ( & V_182 -> V_33 , ( void * ) V_8 -> V_60 ) ;
V_8 -> V_60 = F_83 ( & V_182 -> V_33 , V_50 -> V_58 + V_50 -> V_88 ,
V_185 ) ;
if ( ! V_8 -> V_60 ) {
V_71 = - V_186 ;
goto V_231;
}
V_8 -> V_14 -> V_147 ( V_50 ) ;
if ( V_50 -> V_58 == 2048 )
V_93 -> V_103 . V_217 = V_8 -> V_14 -> V_232 ;
else if ( V_50 -> V_58 == 4096 )
V_93 -> V_103 . V_217 = V_8 -> V_14 -> V_233 ;
if ( V_93 -> V_103 . V_65 == V_104 ) {
if ( F_72 ( V_8 ) || F_73 ( V_8 ) )
V_93 -> V_103 . V_234 = 1 ;
else
V_93 -> V_103 . V_234 = ( V_8 -> V_75 == 4 ) ? 4 : 8 ;
}
if ( F_95 ( V_50 ) ) {
V_71 = - V_230 ;
goto V_231;
}
F_96 (mtd, part_probes,
&(struct mtd_part_parser_data){
.of_node = pdev->dev.of_node,
},
host->pdata.parts,
host->pdata.nr_parts) ;
F_97 ( V_182 , V_8 ) ;
return 0 ;
V_231:
if ( V_8 -> V_90 )
F_51 ( V_8 -> V_91 ) ;
return V_71 ;
}
static int F_98 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_99 ( V_182 ) ;
F_100 ( & V_8 -> V_50 ) ;
if ( V_8 -> V_90 )
F_51 ( V_8 -> V_91 ) ;
return 0 ;
}
