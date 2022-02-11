static void F_1 ( void * V_1 , const void T_1 * V_2 , T_2 V_3 )
{
int V_4 ;
T_3 * V_5 = V_1 ;
const T_1 T_3 * V_6 = V_2 ;
for ( V_4 = 0 ; V_4 < ( V_3 >> 2 ) ; V_4 ++ )
* V_5 ++ = F_2 ( V_6 ++ ) ;
}
static void F_3 ( void T_1 * V_1 , const void * V_2 , int V_3 )
{
int V_4 ;
T_3 T_1 * V_5 = V_1 ;
const T_3 * V_6 = V_2 ;
for ( V_4 = 0 ; V_4 < ( V_3 >> 2 ) ; V_4 ++ )
F_4 ( * V_6 ++ , V_5 ++ ) ;
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
static void F_21 ( struct V_7 * V_8 , int V_29 )
{
int V_30 = 8000 ;
if ( V_29 ) {
if ( ! V_8 -> V_14 -> V_25 ( V_8 ) ) {
F_22 ( V_8 -> V_27 ) ;
F_13 ( V_8 , 1 ) ;
F_23 ( & V_8 -> V_27 ) ;
}
} else {
while ( V_30 -- > 0 ) {
if ( V_8 -> V_14 -> V_25 ( V_8 ) )
break;
F_24 ( 1 ) ;
}
if ( V_30 < 0 )
F_25 ( L_1 , V_31 ) ;
}
}
static void F_26 ( struct V_7 * V_8 , T_5 V_32 , int V_29 )
{
F_7 ( V_32 , V_33 ) ;
F_7 ( V_34 , V_35 ) ;
F_21 ( V_8 , V_29 ) ;
}
static void F_27 ( struct V_7 * V_8 , T_5 V_32 , int V_29 )
{
F_25 ( L_2 , V_32 , V_29 ) ;
F_10 ( V_32 , V_36 ) ;
F_10 ( V_34 , V_12 ) ;
if ( V_8 -> V_14 -> V_15 && ( V_32 == V_37 ) ) {
int V_30 = 100 ;
while ( V_30 -- > 0 ) {
if ( F_9 ( V_12 ) == 0 ) {
break;
}
F_24 ( 1 ) ;
}
if ( V_30 < 0 )
F_25 ( L_3 , V_31 ) ;
} else {
F_21 ( V_8 , V_29 ) ;
}
}
static void F_28 ( struct V_7 * V_8 , T_5 V_38 , int V_39 )
{
F_7 ( V_38 , V_40 ) ;
F_7 ( V_41 , V_35 ) ;
F_21 ( V_8 , 0 ) ;
}
static void F_29 ( struct V_7 * V_8 , T_5 V_38 , int V_39 )
{
F_25 ( L_4 , V_38 , V_39 ) ;
F_10 ( V_38 , V_42 ) ;
F_10 ( V_41 , V_12 ) ;
F_21 ( V_8 , V_39 ) ;
}
static void F_30 ( struct V_43 * V_44 , unsigned int V_45 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_4 V_9 ;
V_9 = F_6 ( V_48 ) ;
V_9 &= ~ ( 7 << 4 ) ;
F_7 ( V_9 , V_48 ) ;
F_7 ( V_45 , V_35 ) ;
F_21 ( V_8 , false ) ;
}
static void F_31 ( struct V_43 * V_44 , unsigned int V_45 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
F_10 ( V_8 -> V_49 << 4 , V_50 ) ;
F_10 ( V_45 , V_12 ) ;
F_21 ( V_8 , true ) ;
}
static void F_32 ( struct V_43 * V_44 , unsigned int V_45 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
int V_51 , V_4 ;
if ( V_44 -> V_52 > 512 )
V_51 = 4 ;
else
V_51 = 1 ;
for ( V_4 = 0 ; V_4 < V_51 ; V_4 ++ ) {
F_10 ( ( V_8 -> V_49 << 4 ) | V_4 , V_50 ) ;
F_10 ( V_45 , V_12 ) ;
F_21 ( V_8 , true ) ;
}
}
static void F_33 ( struct V_7 * V_8 )
{
F_7 ( V_53 , V_35 ) ;
F_21 ( V_8 , true ) ;
F_1 ( V_8 -> V_54 , V_8 -> V_55 , 16 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
struct V_46 * V_56 = & V_8 -> V_57 ;
F_10 ( V_8 -> V_49 << 4 , V_50 ) ;
F_10 ( V_53 , V_12 ) ;
F_21 ( V_8 , true ) ;
F_1 ( V_8 -> V_54 , V_8 -> V_55 , 16 ) ;
if ( V_56 -> V_58 & V_59 ) {
V_8 -> V_54 [ 1 ] = V_8 -> V_54 [ 2 ] ;
V_8 -> V_54 [ 2 ] = V_8 -> V_54 [ 4 ] ;
V_8 -> V_54 [ 3 ] = V_8 -> V_54 [ 6 ] ;
V_8 -> V_54 [ 4 ] = V_8 -> V_54 [ 8 ] ;
V_8 -> V_54 [ 5 ] = V_8 -> V_54 [ 10 ] ;
}
}
static T_5 F_35 ( struct V_7 * V_8 )
{
F_10 ( V_60 , V_35 ) ;
F_21 ( V_8 , true ) ;
return F_6 ( V_48 ) >> 16 ;
}
static T_5 F_36 ( struct V_7 * V_8 )
{
void T_1 * V_61 = V_8 -> V_55 ;
T_4 V_62 ;
T_5 V_63 ;
F_10 ( V_8 -> V_49 << 4 , V_50 ) ;
V_62 = F_6 ( V_61 ) ;
F_10 ( V_60 , V_12 ) ;
F_21 ( V_8 , true ) ;
V_63 = F_9 ( V_61 ) ;
F_7 ( V_62 , V_61 ) ;
return V_63 ;
}
static int F_37 ( struct V_43 * V_44 )
{
return 1 ;
}
static void F_38 ( struct V_43 * V_44 , int V_64 )
{
}
static int F_39 ( struct V_43 * V_44 , T_7 * V_65 ,
T_7 * V_66 , T_7 * V_67 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_5 V_68 = F_16 ( V_8 ) ;
if ( ( ( V_68 & 0x3 ) == 2 ) || ( ( V_68 >> 2 ) == 2 ) ) {
F_25 ( L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_40 ( struct V_43 * V_44 , T_7 * V_65 ,
T_7 * V_66 , T_7 * V_67 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_3 V_69 , V_70 ;
int V_71 = 1 ;
int V_63 = 0 ;
T_8 V_72 , V_73 ;
V_72 = ( V_8 -> V_74 == 4 ) ? 0x7 : 0xf ;
V_73 = ( V_8 -> V_74 == 4 ) ? 0x4 : 0x8 ;
V_71 = V_44 -> V_52 >> 9 ;
V_69 = V_8 -> V_14 -> V_75 ( V_8 ) ;
do {
V_70 = V_69 & V_72 ;
if ( V_70 > V_73 ) {
F_41 ( V_76 L_6 ) ;
return - 1 ;
} else {
V_63 += V_70 ;
}
V_69 >>= 4 ;
} while ( -- V_71 );
V_44 -> V_77 . V_78 += V_63 ;
F_25 ( L_7 , V_63 ) ;
return V_63 ;
}
static int F_42 ( struct V_43 * V_44 , const T_7 * V_65 ,
T_7 * V_79 )
{
return 0 ;
}
static T_7 F_43 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_9 V_63 ;
if ( V_8 -> V_80 )
return V_8 -> V_14 -> V_81 ( V_8 ) & 0xFF ;
V_63 = * ( T_9 * ) ( V_8 -> V_54 + V_8 -> V_82 ) ;
V_8 -> V_82 ++ ;
return V_63 ;
}
static T_5 F_44 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_5 V_63 ;
V_63 = * ( T_5 * ) ( V_8 -> V_54 + V_8 -> V_82 ) ;
V_8 -> V_82 += 2 ;
return V_63 ;
}
static void F_45 ( struct V_43 * V_44 ,
const T_7 * V_83 , int V_84 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_10 V_85 = V_8 -> V_82 ;
int V_86 = V_44 -> V_87 + V_44 -> V_52 - V_85 ;
V_86 = F_46 ( V_86 , V_84 ) ;
memcpy ( V_8 -> V_54 + V_85 , V_83 , V_86 ) ;
V_8 -> V_82 += V_86 ;
}
static void F_47 ( struct V_43 * V_44 , T_7 * V_83 , int V_84 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_10 V_85 = V_8 -> V_82 ;
int V_86 = V_44 -> V_87 + V_44 -> V_52 - V_85 ;
V_86 = F_46 ( V_86 , V_84 ) ;
memcpy ( V_83 , V_8 -> V_54 + V_85 , V_86 ) ;
V_8 -> V_82 += V_86 ;
}
static int F_48 ( struct V_43 * V_44 ,
const T_7 * V_83 , int V_84 )
{
return - V_88 ;
}
static void F_49 ( struct V_43 * V_44 , int V_89 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_50 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_51 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
}
static void F_52 ( struct V_43 * V_44 , int V_89 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_53 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_54 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
V_8 -> V_49 = V_89 ;
F_10 ( V_8 -> V_49 << 4 , V_50 ) ;
}
static void F_55 ( struct V_43 * V_44 , bool V_92 )
{
struct V_46 * V_56 = V_44 -> V_47 ;
struct V_7 * V_8 = V_56 -> V_47 ;
T_10 V_4 , V_93 ;
T_10 V_86 = V_44 -> V_52 >> 9 ;
T_8 * V_94 = V_8 -> V_54 + V_44 -> V_52 ;
T_8 T_1 * V_6 = V_8 -> V_95 ;
T_10 V_5 = V_8 -> V_14 -> V_96 ;
V_93 = ( V_44 -> V_87 / V_86 >> 1 ) << 1 ;
if ( V_92 ) {
for ( V_4 = 0 ; V_4 < V_86 - 1 ; V_4 ++ )
F_1 ( V_94 + V_4 * V_93 , V_6 + V_4 * V_5 , V_93 ) ;
F_1 ( V_94 + V_4 * V_93 , V_6 + V_4 * V_5 , V_44 -> V_87 - V_4 * V_93 ) ;
} else {
for ( V_4 = 0 ; V_4 < V_86 - 1 ; V_4 ++ )
F_3 ( & V_6 [ V_4 * V_5 ] , & V_94 [ V_4 * V_93 ] , V_93 ) ;
F_3 ( & V_6 [ V_4 * V_5 ] , & V_94 [ V_4 * V_93 ] , V_44 -> V_87 - V_4 * V_93 ) ;
}
}
static void F_56 ( struct V_43 * V_44 , int V_97 , int V_98 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
if ( V_97 != - 1 ) {
V_8 -> V_14 -> V_99 ( V_8 , 0 , V_98 == - 1 ) ;
if ( V_44 -> V_52 > 512 )
V_8 -> V_14 -> V_99 ( V_8 , 0 , false ) ;
}
if ( V_98 != - 1 ) {
V_8 -> V_14 -> V_99 ( V_8 , ( V_98 & 0xff ) , false ) ;
if ( V_44 -> V_52 > 512 ) {
if ( V_44 -> V_3 >= 0x10000000 ) {
V_8 -> V_14 -> V_99 ( V_8 ,
( V_98 >> 8 ) & 0xff ,
false ) ;
V_8 -> V_14 -> V_99 ( V_8 ,
( V_98 >> 16 ) & 0xff ,
true ) ;
} else
V_8 -> V_14 -> V_99 ( V_8 ,
( V_98 >> 8 ) & 0xff , true ) ;
} else {
if ( V_44 -> V_3 >= 0x4000000 ) {
V_8 -> V_14 -> V_99 ( V_8 ,
( V_98 >> 8 ) & 0xff ,
false ) ;
V_8 -> V_14 -> V_99 ( V_8 ,
( V_98 >> 16 ) & 0xff ,
true ) ;
} else
V_8 -> V_14 -> V_99 ( V_8 ,
( V_98 >> 8 ) & 0xff , true ) ;
}
}
}
static int F_57 ( struct V_43 * V_44 )
{
int V_100 = 0 ;
V_100 = V_44 -> V_87 * 512 / V_44 -> V_52 ;
if ( V_100 < 26 )
return 4 ;
else
return 8 ;
}
static void F_58 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_5 V_101 = 0 ;
if ( V_46 -> V_102 . V_64 == V_103 )
V_101 |= V_104 ;
if ( ! V_8 -> V_14 -> V_15 )
V_101 |= V_18 ;
V_8 -> V_74 = 1 ;
F_10 ( V_101 , V_17 ) ;
F_10 ( 0x2 , V_105 ) ;
F_10 ( 0x0 , V_106 ) ;
F_10 ( 0xffff , V_107 ) ;
F_10 ( 0x4 , V_108 ) ;
}
static void F_59 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
T_5 V_101 = 0 ;
if ( V_46 -> V_102 . V_64 == V_103 )
V_101 |= V_104 ;
V_101 |= V_109 ;
if ( ! V_8 -> V_14 -> V_15 )
V_101 |= V_18 ;
if ( V_44 -> V_52 ) {
T_5 V_110 = V_44 -> V_111 / V_44 -> V_52 ;
V_8 -> V_74 = F_57 ( V_44 ) ;
if ( V_8 -> V_74 == 4 )
V_101 |= V_112 ;
V_101 |= F_60 ( F_61 ( V_110 ) - 6 ) ;
} else {
V_8 -> V_74 = 1 ;
}
F_10 ( V_101 , V_17 ) ;
F_10 ( 0x2 , V_105 ) ;
F_10 ( 0x0 , V_113 ) ;
F_10 ( 0x0 , V_114 ) ;
F_10 ( 0x0 , V_115 ) ;
F_10 ( 0x0 , V_116 ) ;
F_10 ( 0xffff , V_117 ) ;
F_10 ( 0xffff , V_118 ) ;
F_10 ( 0xffff , V_119 ) ;
F_10 ( 0xffff , V_120 ) ;
F_10 ( 0x4 , V_108 ) ;
}
static void F_62 ( struct V_43 * V_44 )
{
struct V_46 * V_89 = V_44 -> V_47 ;
struct V_7 * V_8 = V_89 -> V_47 ;
T_4 V_121 , V_122 ;
int V_4 , V_123 ;
F_7 ( F_63 ( 0 ) , V_48 ) ;
F_7 ( V_124 , V_10 ) ;
F_7 ( V_125 | V_126 ,
V_127 ) ;
for ( V_4 = 0 ; V_4 < V_128 ; V_4 ++ )
F_7 ( 0x0 | ( 0xffff << 16 ) ,
V_129 + ( V_4 << 2 ) ) ;
F_7 ( 0 , V_10 ) ;
V_121 = V_130 |
V_131 |
F_64 ( V_44 -> V_87 >> 1 ) |
F_65 ( 0x70 ) |
V_20 |
V_132 ;
if ( V_89 -> V_102 . V_64 == V_103 )
V_121 |= V_133 ;
V_123 = F_66 ( V_89 -> V_134 ) >> 3 ;
if ( V_44 -> V_52 == 2048 ) {
V_121 |= V_135 ;
V_121 |= F_67 ( V_123 ) ;
} else if ( V_44 -> V_52 == 4096 ) {
V_121 |= V_136 ;
V_121 |= F_67 ( V_123 ) ;
} else {
V_121 |= V_137 ;
V_121 |= F_67 ( V_123 - 1 ) ;
}
if ( V_44 -> V_52 ) {
V_121 |= F_68 ( F_61 ( V_44 -> V_111 / V_44 -> V_52 ) - 6 ) ;
V_8 -> V_74 = F_57 ( V_44 ) ;
if ( V_8 -> V_74 == 8 )
V_121 |= V_138 ;
}
F_7 ( V_121 , V_19 ) ;
V_122 = F_69 ( 0 ) |
V_139 |
V_140 |
F_70 ( 6 ) |
F_71 ( 0 ) ;
if ( ! ( V_89 -> V_58 & V_59 ) )
V_122 |= V_141 ;
F_7 ( V_122 , V_142 ) ;
F_7 ( 0 , V_143 ) ;
}
static void F_72 ( struct V_43 * V_44 , unsigned V_144 ,
int V_97 , int V_98 )
{
struct V_46 * V_46 = V_44 -> V_47 ;
struct V_7 * V_8 = V_46 -> V_47 ;
F_25 ( L_8 ,
V_144 , V_97 , V_98 ) ;
V_8 -> V_80 = false ;
switch ( V_144 ) {
case V_37 :
V_8 -> V_14 -> V_145 ( V_44 ) ;
V_8 -> V_14 -> V_146 ( V_8 , V_144 , false ) ;
break;
case V_147 :
V_8 -> V_82 = 0 ;
V_8 -> V_80 = true ;
V_8 -> V_14 -> V_146 ( V_8 , V_144 , true ) ;
F_56 ( V_44 , V_97 , V_98 ) ;
break;
case V_148 :
case V_149 :
if ( V_144 == V_148 )
V_8 -> V_82 = V_97 ;
else
V_8 -> V_82 = V_97 + V_44 -> V_52 ;
V_144 = V_148 ;
V_8 -> V_14 -> V_146 ( V_8 , V_144 , false ) ;
F_56 ( V_44 , V_97 , V_98 ) ;
if ( V_44 -> V_52 > 512 )
V_8 -> V_14 -> V_146 ( V_8 ,
V_150 , true ) ;
V_8 -> V_14 -> V_151 ( V_44 , V_152 ) ;
F_1 ( V_8 -> V_54 , V_8 -> V_55 ,
V_44 -> V_52 ) ;
F_55 ( V_44 , true ) ;
break;
case V_153 :
if ( V_97 >= V_44 -> V_52 )
F_72 ( V_44 , V_148 , 0 , V_98 ) ;
V_8 -> V_82 = V_97 ;
V_8 -> V_14 -> V_146 ( V_8 , V_144 , false ) ;
F_56 ( V_44 , V_97 , V_98 ) ;
break;
case V_154 :
F_3 ( V_8 -> V_55 , V_8 -> V_54 , V_44 -> V_52 ) ;
F_55 ( V_44 , false ) ;
V_8 -> V_14 -> V_151 ( V_44 , V_155 ) ;
V_8 -> V_14 -> V_146 ( V_8 , V_144 , true ) ;
F_56 ( V_44 , V_97 , V_98 ) ;
break;
case V_156 :
V_8 -> V_14 -> V_146 ( V_8 , V_144 , true ) ;
F_56 ( V_44 , V_97 , V_98 ) ;
V_8 -> V_14 -> V_157 ( V_8 ) ;
V_8 -> V_82 = V_97 ;
break;
case V_158 :
case V_159 :
V_8 -> V_14 -> V_146 ( V_8 , V_144 , false ) ;
F_56 ( V_44 , V_97 , V_98 ) ;
break;
}
}
static int T_11 F_73 ( struct V_7 * V_8 )
{
struct V_160 * V_161 = V_8 -> V_162 -> V_163 ;
struct V_164 * V_165 = & V_8 -> V_165 ;
const struct V_166 * V_167 =
F_74 ( V_168 , V_8 -> V_162 ) ;
int V_169 ;
if ( ! V_161 )
return 1 ;
if ( F_75 ( V_161 ) >= 0 )
V_165 -> V_170 = 1 ;
V_165 -> V_171 = F_76 ( V_161 ) ;
V_169 = F_77 ( V_161 ) ;
if ( V_169 < 0 )
return V_169 ;
V_165 -> V_172 = V_169 / 8 ;
V_8 -> V_14 = V_167 -> V_173 ;
return 0 ;
}
static int T_11 F_73 ( struct V_7 * V_8 )
{
return 1 ;
}
static int T_11 F_78 ( struct V_7 * V_8 )
{
struct V_164 * V_165 = V_8 -> V_162 -> V_174 ;
if ( ! V_165 )
return - V_175 ;
V_8 -> V_165 = * V_165 ;
if ( F_79 () ) {
if ( F_80 () )
V_8 -> V_14 = & V_176 ;
else
V_8 -> V_14 = & V_177 ;
} else if ( F_81 () ) {
V_8 -> V_14 = & V_178 ;
} else if ( F_82 () ) {
V_8 -> V_14 = & V_179 ;
} else
F_83 () ;
return 0 ;
}
static int T_11 F_84 ( struct V_180 * V_181 )
{
struct V_46 * V_56 ;
struct V_43 * V_44 ;
struct V_7 * V_8 ;
struct V_182 * V_183 ;
int V_70 = 0 ;
V_8 = F_85 ( sizeof( struct V_7 ) + V_184 +
V_185 , V_186 ) ;
if ( ! V_8 )
return - V_187 ;
V_8 -> V_54 = ( T_9 * ) ( V_8 + 1 ) ;
V_8 -> V_162 = & V_181 -> V_162 ;
V_56 = & V_8 -> V_57 ;
V_44 = & V_8 -> V_44 ;
V_44 -> V_47 = V_56 ;
V_44 -> V_188 = V_189 ;
V_44 -> V_162 . V_190 = & V_181 -> V_162 ;
V_44 -> V_191 = V_192 ;
V_56 -> V_193 = 5 ;
V_56 -> V_47 = V_8 ;
V_56 -> V_194 = F_37 ;
V_56 -> V_195 = F_72 ;
V_56 -> V_196 = F_43 ;
V_56 -> V_197 = F_44 ;
V_56 -> V_198 = F_45 ;
V_56 -> V_199 = F_47 ;
V_56 -> V_200 = F_48 ;
V_8 -> V_91 = F_86 ( & V_181 -> V_162 , L_9 ) ;
if ( F_87 ( V_8 -> V_91 ) ) {
V_70 = F_88 ( V_8 -> V_91 ) ;
goto V_201;
}
F_51 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
V_183 = F_89 ( V_181 , V_202 , 0 ) ;
if ( ! V_183 ) {
V_70 = - V_175 ;
goto V_203;
}
V_8 -> V_204 = F_90 ( V_183 -> V_205 , F_91 ( V_183 ) ) ;
if ( ! V_8 -> V_204 ) {
V_70 = - V_187 ;
goto V_203;
}
V_8 -> V_55 = V_8 -> V_204 ;
V_70 = F_73 ( V_8 ) ;
if ( V_70 > 0 )
V_70 = F_78 ( V_8 ) ;
if ( V_70 < 0 )
goto V_206;
if ( V_8 -> V_14 -> V_207 )
V_8 -> V_208 = V_8 -> V_204 + V_8 -> V_14 -> V_207 ;
V_8 -> V_95 = V_8 -> V_204 + V_8 -> V_14 -> V_209 ;
if ( V_8 -> V_14 -> V_210 )
V_8 -> V_211 = V_8 -> V_204 + V_8 -> V_14 -> V_210 ;
V_56 -> V_102 . V_212 = V_8 -> V_14 -> V_213 ;
V_8 -> V_74 = V_8 -> V_14 -> V_74 ;
V_56 -> V_214 = V_8 -> V_14 -> V_214 ;
V_56 -> V_102 . V_3 = 512 ;
V_56 -> V_102 . V_215 = V_8 -> V_14 -> V_216 ;
if ( V_8 -> V_14 -> V_217 ) {
V_183 = F_89 ( V_181 , V_202 , 1 ) ;
if ( ! V_183 ) {
V_70 = - V_175 ;
goto V_206;
}
V_8 -> V_218 = F_90 ( V_183 -> V_205 , F_91 ( V_183 ) ) ;
if ( ! V_8 -> V_218 ) {
V_70 = - V_187 ;
goto V_206;
}
}
if ( V_8 -> V_165 . V_170 ) {
V_56 -> V_102 . V_219 = F_42 ;
V_56 -> V_102 . V_220 = F_38 ;
V_56 -> V_102 . V_221 = V_8 -> V_14 -> V_222 ;
V_56 -> V_102 . V_64 = V_103 ;
} else {
V_56 -> V_102 . V_64 = V_223 ;
}
if ( V_8 -> V_165 . V_172 == 2 )
V_56 -> V_58 |= V_59 ;
if ( V_8 -> V_165 . V_171 ) {
V_56 -> V_224 = & V_225 ;
V_56 -> V_226 = & V_227 ;
V_56 -> V_228 |= V_229 ;
}
F_92 ( & V_8 -> V_27 ) ;
V_8 -> V_21 = F_93 ( V_181 , 0 ) ;
V_8 -> V_14 -> F_13 ( V_8 , 0 ) ;
V_70 = F_94 ( V_8 -> V_21 , F_19 , V_230 , V_192 , V_8 ) ;
if ( V_70 )
goto V_206;
if ( V_8 -> V_14 -> V_15 ) {
F_15 ( V_8 -> V_21 ) ;
V_8 -> V_14 -> F_13 ( V_8 , 1 ) ;
}
if ( F_95 ( V_44 , F_81 () ? 4 : 1 , NULL ) ) {
V_70 = - V_231 ;
goto V_232;
}
V_8 -> V_14 -> V_145 ( V_44 ) ;
if ( V_44 -> V_52 == 2048 )
V_56 -> V_102 . V_215 = V_8 -> V_14 -> V_233 ;
else if ( V_44 -> V_52 == 4096 )
V_56 -> V_102 . V_215 = V_8 -> V_14 -> V_234 ;
if ( V_56 -> V_102 . V_64 == V_103 ) {
if ( F_79 () )
V_56 -> V_102 . V_235 = 1 ;
else
V_56 -> V_102 . V_235 = ( V_8 -> V_74 == 4 ) ? 4 : 8 ;
}
if ( F_96 ( V_44 ) ) {
V_70 = - V_231 ;
goto V_232;
}
F_97 (mtd, part_probes,
&(struct mtd_part_parser_data){
.of_node = pdev->dev.of_node,
},
host->pdata.parts,
host->pdata.nr_parts) ;
F_98 ( V_181 , V_8 ) ;
return 0 ;
V_232:
F_99 ( V_8 -> V_21 , V_8 ) ;
V_206:
if ( V_8 -> V_218 )
F_100 ( V_8 -> V_218 ) ;
F_100 ( V_8 -> V_204 ) ;
V_203:
F_101 ( V_8 -> V_91 ) ;
V_201:
F_102 ( V_8 ) ;
return V_70 ;
}
static int T_12 F_103 ( struct V_180 * V_181 )
{
struct V_7 * V_8 = F_104 ( V_181 ) ;
F_101 ( V_8 -> V_91 ) ;
F_98 ( V_181 , NULL ) ;
F_105 ( & V_8 -> V_44 ) ;
F_99 ( V_8 -> V_21 , V_8 ) ;
if ( V_8 -> V_218 )
F_100 ( V_8 -> V_218 ) ;
F_100 ( V_8 -> V_204 ) ;
F_102 ( V_8 ) ;
return 0 ;
}
static int T_11 F_106 ( void )
{
return F_107 ( & V_236 , F_84 ) ;
}
static void T_13 F_108 ( void )
{
F_109 ( & V_236 ) ;
}
