static void F_1 ( void * V_1 , const void T_1 * V_2 , T_2 V_3 )
{
int V_4 ;
T_3 * V_5 = V_1 ;
const T_1 T_3 * V_6 = V_2 ;
for ( V_4 = 0 ; V_4 < ( V_3 >> 2 ) ; V_4 ++ )
* V_5 ++ = F_2 ( V_6 ++ ) ;
}
static void F_3 ( void * V_1 , const void T_1 * V_2 , T_2 V_3 )
{
int V_4 ;
T_4 * V_5 = V_1 ;
const T_1 T_4 * V_6 = V_2 ;
if ( F_4 ( V_1 , 4 ) == V_1 && F_5 ( V_3 , 4 ) ) {
F_1 ( V_1 , V_2 , V_3 ) ;
return;
}
for ( V_4 = 0 ; V_4 < ( V_3 >> 1 ) ; V_4 ++ )
* V_5 ++ = F_6 ( V_6 ++ ) ;
}
static inline void F_7 ( void T_1 * V_1 , const void * V_2 , int V_3 )
{
F_8 ( V_1 , V_2 , V_3 / 4 ) ;
}
static void F_9 ( void T_1 * V_1 , const void * V_2 , int V_3 )
{
int V_4 ;
T_1 T_4 * V_5 = V_1 ;
const T_4 * V_6 = V_2 ;
if ( F_4 ( V_2 , 4 ) == V_2 && F_5 ( V_3 , 4 ) ) {
F_7 ( V_1 , V_2 , V_3 ) ;
return;
}
for ( V_4 = 0 ; V_4 < ( V_3 >> 1 ) ; V_4 ++ )
F_10 ( * V_6 ++ , V_5 ++ ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
T_5 V_9 ;
V_9 = F_12 ( V_10 ) ;
if ( ! ( V_9 & V_11 ) )
return 0 ;
V_9 &= ~ V_11 ;
F_13 ( V_9 , V_10 ) ;
return 1 ;
}
static int F_14 ( struct V_7 * V_8 )
{
T_5 V_9 ;
V_9 = F_15 ( V_12 ) ;
if ( ! ( V_9 & V_13 ) )
return 0 ;
if ( ! V_8 -> V_14 -> V_15 )
F_16 ( V_9 & ~ V_13 , V_12 ) ;
return 1 ;
}
static void F_17 ( struct V_7 * V_8 , int V_16 )
{
T_6 V_9 ;
V_9 = F_15 ( V_17 ) ;
if ( V_16 )
V_9 &= ~ V_18 ;
else
V_9 |= V_18 ;
F_16 ( V_9 , V_17 ) ;
}
static void F_18 ( struct V_7 * V_8 , int V_16 )
{
T_5 V_9 ;
V_9 = F_12 ( V_19 ) ;
if ( V_16 )
V_9 &= ~ V_20 ;
else
V_9 |= V_20 ;
F_13 ( V_9 , V_19 ) ;
}
static void F_19 ( struct V_7 * V_8 , int V_16 )
{
if ( V_8 -> V_14 -> V_15 ) {
if ( V_16 )
F_20 ( V_8 -> V_21 ) ;
else
F_21 ( V_8 -> V_21 ) ;
} else {
V_8 -> V_14 -> F_19 ( V_8 , V_16 ) ;
}
}
static T_3 F_22 ( struct V_7 * V_8 )
{
return F_15 ( V_22 ) ;
}
static T_3 F_23 ( struct V_7 * V_8 )
{
return F_12 ( V_22 ) ;
}
static T_3 F_24 ( struct V_7 * V_8 )
{
return F_12 ( V_23 ) ;
}
static T_7 F_25 ( int V_21 , void * V_24 )
{
struct V_7 * V_8 = V_24 ;
if ( ! V_8 -> V_14 -> V_25 ( V_8 ) )
return V_26 ;
F_19 ( V_8 , 0 ) ;
F_26 ( & V_8 -> V_27 ) ;
return V_28 ;
}
static int F_27 ( struct V_7 * V_8 , int V_29 )
{
int V_30 = 0 ;
if ( V_8 -> V_14 -> V_25 ( V_8 ) )
return 0 ;
if ( V_29 ) {
unsigned long V_31 ;
F_28 ( & V_8 -> V_27 ) ;
F_19 ( V_8 , 1 ) ;
V_31 = F_29 ( & V_8 -> V_27 , V_32 ) ;
if ( ! V_31 && ! V_8 -> V_14 -> V_25 ( V_8 ) ) {
F_30 ( V_8 -> V_33 , L_1 ) ;
V_30 = - V_34 ;
}
} else {
int V_35 = 8000 ;
int V_36 ;
do {
F_31 ( 1 ) ;
V_36 = V_8 -> V_14 -> V_25 ( V_8 ) ;
if ( V_36 )
break;
} while ( -- V_35 );
if ( ! V_36 ) {
F_30 ( V_8 -> V_33 , L_2 ) ;
V_30 = - V_34 ;
}
}
F_32 ( V_30 < 0 , L_3 , V_29 ) ;
return V_30 ;
}
static void F_33 ( struct V_7 * V_8 , T_6 V_37 , int V_29 )
{
F_13 ( V_37 , V_38 ) ;
F_13 ( V_39 , V_40 ) ;
F_27 ( V_8 , V_29 ) ;
}
static void F_34 ( struct V_7 * V_8 , T_6 V_37 , int V_29 )
{
F_35 ( L_4 , V_37 , V_29 ) ;
F_16 ( V_37 , V_41 ) ;
F_16 ( V_39 , V_12 ) ;
if ( V_8 -> V_14 -> V_15 && ( V_37 == V_42 ) ) {
int V_35 = 100 ;
while ( V_35 -- > 0 ) {
if ( F_15 ( V_12 ) == 0 ) {
break;
}
F_31 ( 1 ) ;
}
if ( V_35 < 0 )
F_35 ( L_5 , V_43 ) ;
} else {
F_27 ( V_8 , V_29 ) ;
}
}
static void F_36 ( struct V_7 * V_8 , T_6 V_44 , int V_45 )
{
F_13 ( V_44 , V_46 ) ;
F_13 ( V_47 , V_40 ) ;
F_27 ( V_8 , 0 ) ;
}
static void F_37 ( struct V_7 * V_8 , T_6 V_44 , int V_45 )
{
F_35 ( L_6 , V_44 , V_45 ) ;
F_16 ( V_44 , V_48 ) ;
F_16 ( V_47 , V_12 ) ;
F_27 ( V_8 , V_45 ) ;
}
static void F_38 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_5 V_9 ;
V_9 = F_12 ( V_54 ) ;
V_9 &= ~ ( 7 << 4 ) ;
F_13 ( V_9 , V_54 ) ;
F_13 ( V_51 , V_40 ) ;
F_27 ( V_8 , false ) ;
}
static void F_39 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
F_16 ( V_8 -> V_55 << 4 , V_56 ) ;
F_16 ( V_51 , V_12 ) ;
F_27 ( V_8 , true ) ;
}
static void F_40 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
int V_57 , V_4 ;
if ( V_50 -> V_58 > 512 )
V_57 = 4 ;
else
V_57 = 1 ;
for ( V_4 = 0 ; V_4 < V_57 ; V_4 ++ ) {
F_16 ( ( V_8 -> V_55 << 4 ) | V_4 , V_56 ) ;
F_16 ( V_51 , V_12 ) ;
F_27 ( V_8 , true ) ;
}
}
static void F_41 ( struct V_7 * V_8 )
{
F_13 ( V_59 , V_40 ) ;
F_27 ( V_8 , true ) ;
F_1 ( V_8 -> V_60 , V_8 -> V_61 , 16 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
F_16 ( V_8 -> V_55 << 4 , V_56 ) ;
F_16 ( V_59 , V_12 ) ;
F_27 ( V_8 , true ) ;
F_1 ( V_8 -> V_60 , V_8 -> V_61 , 16 ) ;
}
static T_6 F_43 ( struct V_7 * V_8 )
{
F_16 ( V_62 , V_40 ) ;
F_27 ( V_8 , true ) ;
return F_12 ( V_54 ) >> 16 ;
}
static T_6 F_44 ( struct V_7 * V_8 )
{
void T_1 * V_63 = V_8 -> V_61 ;
T_5 V_64 ;
T_6 V_30 ;
F_16 ( V_8 -> V_55 << 4 , V_56 ) ;
V_64 = F_12 ( V_63 ) ;
F_16 ( V_62 , V_12 ) ;
F_27 ( V_8 , true ) ;
V_30 = F_15 ( V_63 ) ;
F_13 ( V_64 , V_63 ) ;
return V_30 ;
}
static int F_45 ( struct V_49 * V_50 )
{
return 1 ;
}
static void F_46 ( struct V_49 * V_50 , int V_65 )
{
}
static int F_47 ( struct V_49 * V_50 , T_8 * V_66 ,
T_8 * V_67 , T_8 * V_68 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_6 V_69 = F_22 ( V_8 ) ;
if ( ( ( V_69 & 0x3 ) == 2 ) || ( ( V_69 >> 2 ) == 2 ) ) {
F_35 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( struct V_49 * V_50 , T_8 * V_66 ,
T_8 * V_67 , T_8 * V_68 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_3 V_70 , V_71 ;
int V_72 = 1 ;
int V_30 = 0 ;
T_9 V_73 , V_74 ;
V_73 = ( V_8 -> V_75 == 4 ) ? 0x7 : 0xf ;
V_74 = ( V_8 -> V_75 == 4 ) ? 0x4 : 0x8 ;
V_72 = V_50 -> V_58 >> 9 ;
V_70 = V_8 -> V_14 -> V_76 ( V_8 ) ;
do {
V_71 = V_70 & V_73 ;
if ( V_71 > V_74 ) {
F_49 ( V_77 L_8 ) ;
return - 1 ;
} else {
V_30 += V_71 ;
}
V_70 >>= 4 ;
} while ( -- V_72 );
F_35 ( L_9 , V_30 ) ;
return V_30 ;
}
static int F_50 ( struct V_49 * V_50 , const T_8 * V_66 ,
T_8 * V_78 )
{
return 0 ;
}
static T_8 F_51 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_10 V_30 ;
if ( V_8 -> V_79 )
return V_8 -> V_14 -> V_80 ( V_8 ) & 0xFF ;
if ( V_52 -> V_81 & V_82 ) {
V_30 = * ( T_6 * ) ( V_8 -> V_60 + V_8 -> V_83 ) ;
V_8 -> V_83 += 2 ;
} else {
V_30 = * ( T_10 * ) ( V_8 -> V_60 + V_8 -> V_83 ) ;
V_8 -> V_83 ++ ;
}
F_35 ( L_10 , V_43 , V_30 , V_8 -> V_83 ) ;
return V_30 ;
}
static T_6 F_52 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_6 V_30 ;
V_30 = * ( T_6 * ) ( V_8 -> V_60 + V_8 -> V_83 ) ;
V_8 -> V_83 += 2 ;
return V_30 ;
}
static void F_53 ( struct V_49 * V_50 ,
const T_8 * V_84 , int V_85 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_4 V_86 = V_8 -> V_83 ;
int V_87 = V_50 -> V_88 + V_50 -> V_58 - V_86 ;
V_87 = F_54 ( V_87 , V_85 ) ;
memcpy ( V_8 -> V_60 + V_86 , V_84 , V_87 ) ;
V_8 -> V_83 += V_87 ;
}
static void F_55 ( struct V_49 * V_50 , T_8 * V_84 , int V_85 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_4 V_86 = V_8 -> V_83 ;
int V_87 = V_50 -> V_88 + V_50 -> V_58 - V_86 ;
V_87 = F_54 ( V_87 , V_85 ) ;
memcpy ( V_84 , V_8 -> V_60 + V_86 , V_87 ) ;
V_8 -> V_83 += V_87 ;
}
static void F_56 ( struct V_49 * V_50 , int V_89 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_57 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_58 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
}
static void F_59 ( struct V_49 * V_50 , int V_89 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_57 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_58 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
V_8 -> V_55 = V_89 ;
F_16 ( V_8 -> V_55 << 4 , V_56 ) ;
}
static void F_60 ( struct V_49 * V_50 , bool V_92 )
{
struct V_52 * V_93 = V_50 -> V_53 ;
struct V_7 * V_8 = V_93 -> V_53 ;
T_4 V_4 , V_94 ;
T_4 V_95 = V_50 -> V_58 / 512 ;
T_9 * V_96 = V_8 -> V_60 + V_50 -> V_58 ;
T_9 T_1 * V_6 = V_8 -> V_97 ;
T_4 V_98 = V_8 -> V_14 -> V_99 ;
V_94 = ( V_8 -> V_100 / V_95 ) & ~ 1 ;
if ( V_92 ) {
for ( V_4 = 0 ; V_4 < V_95 - 1 ; V_4 ++ )
F_3 ( V_96 + V_4 * V_94 ,
V_6 + V_4 * V_98 ,
V_94 ) ;
F_3 ( V_96 + V_4 * V_94 ,
V_6 + V_4 * V_98 ,
V_8 -> V_100 - V_4 * V_94 ) ;
} else {
for ( V_4 = 0 ; V_4 < V_95 - 1 ; V_4 ++ )
F_9 ( & V_6 [ V_4 * V_98 ] ,
& V_96 [ V_4 * V_94 ] ,
V_94 ) ;
F_9 ( & V_6 [ V_94 * V_98 ] ,
& V_96 [ V_4 * V_94 ] ,
V_8 -> V_100 - V_4 * V_94 ) ;
}
}
static void F_61 ( struct V_49 * V_50 , int V_101 , int V_102 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
if ( V_101 != - 1 ) {
V_8 -> V_14 -> V_103 ( V_8 , V_101 & 0xff ,
V_102 == - 1 ) ;
if ( V_50 -> V_58 > 512 )
V_8 -> V_14 -> V_103 ( V_8 ,
( V_101 >> 8 ) & 0xff ,
false ) ;
}
if ( V_102 != - 1 ) {
V_8 -> V_14 -> V_103 ( V_8 , ( V_102 & 0xff ) , false ) ;
if ( V_50 -> V_58 > 512 ) {
if ( V_50 -> V_3 >= 0x10000000 ) {
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 8 ) & 0xff ,
false ) ;
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 16 ) & 0xff ,
true ) ;
} else
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 8 ) & 0xff , true ) ;
} else {
if ( V_50 -> V_3 >= 0x4000000 ) {
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 8 ) & 0xff ,
false ) ;
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 16 ) & 0xff ,
true ) ;
} else
V_8 -> V_14 -> V_103 ( V_8 ,
( V_102 >> 8 ) & 0xff , true ) ;
}
}
}
static int F_62 ( struct V_49 * V_50 )
{
int V_104 = 0 ;
V_104 = V_50 -> V_88 * 512 / V_50 -> V_58 ;
if ( V_104 < 26 )
return 4 ;
else
return 8 ;
}
static void F_63 ( struct V_105 * V_106 )
{
int V_4 , V_107 ;
V_106 -> V_108 = 8 * 18 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ )
for ( V_107 = 0 ; V_107 < 18 ; V_107 ++ )
V_106 -> V_109 [ V_4 * 18 + V_107 ] = V_4 * 26 + V_107 + 7 ;
V_106 -> V_110 [ 0 ] . V_111 = 2 ;
V_106 -> V_110 [ 0 ] . V_112 = 4 ;
for ( V_4 = 1 ; V_4 < 8 ; V_4 ++ ) {
V_106 -> V_110 [ V_4 ] . V_111 = V_4 * 26 ;
V_106 -> V_110 [ V_4 ] . V_112 = 7 ;
}
}
static void F_64 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_6 V_113 = 0 ;
if ( V_52 -> V_114 . V_65 == V_115 && V_50 -> V_58 )
V_113 |= V_116 ;
if ( ! V_8 -> V_14 -> V_15 )
V_113 |= V_18 ;
V_8 -> V_75 = 1 ;
F_16 ( V_113 , V_17 ) ;
F_16 ( 0x2 , V_117 ) ;
F_16 ( 0x0 , V_118 ) ;
F_16 ( 0xffff , V_119 ) ;
F_16 ( 0x4 , V_120 ) ;
}
static void F_65 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
T_6 V_113 = 0 ;
V_113 |= V_121 ;
if ( ! V_8 -> V_14 -> V_15 )
V_113 |= V_18 ;
if ( V_50 -> V_58 ) {
T_6 V_122 = V_50 -> V_123 / V_50 -> V_58 ;
if ( V_52 -> V_114 . V_65 == V_115 )
V_113 |= V_116 ;
V_8 -> V_75 = F_62 ( V_50 ) ;
if ( V_8 -> V_75 == 4 )
V_113 |= V_124 ;
V_113 |= F_66 ( F_67 ( V_122 ) - 6 ) ;
} else {
V_8 -> V_75 = 1 ;
}
F_16 ( V_113 , V_17 ) ;
F_16 ( 0x2 , V_117 ) ;
F_16 ( 0x0 , V_125 ) ;
F_16 ( 0x0 , V_126 ) ;
F_16 ( 0x0 , V_127 ) ;
F_16 ( 0x0 , V_128 ) ;
F_16 ( 0xffff , V_129 ) ;
F_16 ( 0xffff , V_130 ) ;
F_16 ( 0xffff , V_131 ) ;
F_16 ( 0xffff , V_132 ) ;
F_16 ( 0x4 , V_120 ) ;
}
static void F_68 ( struct V_49 * V_50 )
{
struct V_52 * V_89 = V_50 -> V_53 ;
struct V_7 * V_8 = V_89 -> V_53 ;
T_5 V_133 , V_134 ;
int V_4 , V_135 ;
F_13 ( F_69 ( 0 ) , V_54 ) ;
F_13 ( V_136 , V_10 ) ;
F_13 ( V_137 | V_138 ,
V_139 ) ;
for ( V_4 = 0 ; V_4 < V_140 ; V_4 ++ )
F_13 ( 0x0 | ( 0xffff << 16 ) ,
V_141 + ( V_4 << 2 ) ) ;
F_13 ( 0 , V_10 ) ;
V_133 = V_142 |
V_143 |
F_70 ( V_50 -> V_88 >> 1 ) |
F_71 ( 0x70 ) |
V_20 |
V_144 ;
V_135 = F_72 ( V_89 -> V_145 ) >> 3 ;
if ( V_50 -> V_58 == 2048 ) {
V_133 |= V_146 ;
V_133 |= F_73 ( V_135 ) ;
} else if ( V_50 -> V_58 == 4096 ) {
V_133 |= V_147 ;
V_133 |= F_73 ( V_135 ) ;
} else {
V_133 |= V_148 ;
V_133 |= F_73 ( V_135 - 1 ) ;
}
if ( V_50 -> V_58 ) {
if ( V_89 -> V_114 . V_65 == V_115 )
V_133 |= V_149 ;
V_133 |= F_74 (
F_67 ( V_50 -> V_123 / V_50 -> V_58 ) - 6 ,
V_8 -> V_14 -> V_150 ) ;
V_8 -> V_75 = F_62 ( V_50 ) ;
if ( V_8 -> V_75 == 8 )
V_133 |= V_151 ;
}
F_13 ( V_133 , V_19 ) ;
V_134 = F_75 ( 0 ) |
V_152 |
V_153 |
F_76 ( 6 ) |
F_77 ( 0 ) ;
if ( ! ( V_89 -> V_81 & V_82 ) )
V_134 |= V_154 ;
F_13 ( V_134 , V_155 ) ;
F_13 ( 0 , V_156 ) ;
}
static void F_78 ( struct V_49 * V_50 , unsigned V_157 ,
int V_101 , int V_102 )
{
struct V_52 * V_52 = V_50 -> V_53 ;
struct V_7 * V_8 = V_52 -> V_53 ;
F_35 ( L_11 ,
V_157 , V_101 , V_102 ) ;
V_8 -> V_79 = false ;
switch ( V_157 ) {
case V_42 :
V_8 -> V_14 -> V_158 ( V_50 ) ;
V_8 -> V_14 -> V_159 ( V_8 , V_157 , false ) ;
break;
case V_160 :
V_8 -> V_83 = 0 ;
V_8 -> V_79 = true ;
V_8 -> V_14 -> V_159 ( V_8 , V_157 , true ) ;
F_32 ( V_101 != - 1 || V_102 != - 1 ,
L_12 ,
V_157 , V_101 , V_102 ) ;
F_61 ( V_50 , V_101 , V_102 ) ;
break;
case V_161 :
case V_162 :
if ( V_157 == V_161 )
V_8 -> V_83 = V_101 ;
else
V_8 -> V_83 = V_101 + V_50 -> V_58 ;
V_157 = V_161 ;
V_8 -> V_14 -> V_159 ( V_8 , V_157 , false ) ;
F_32 ( V_101 < 0 ,
L_12 ,
V_157 , V_101 , V_102 ) ;
F_61 ( V_50 , 0 , V_102 ) ;
if ( V_50 -> V_58 > 512 )
V_8 -> V_14 -> V_159 ( V_8 ,
V_163 , true ) ;
V_8 -> V_14 -> V_164 ( V_50 , V_165 ) ;
F_1 ( V_8 -> V_60 , V_8 -> V_61 ,
V_50 -> V_58 ) ;
F_60 ( V_50 , true ) ;
break;
case V_166 :
if ( V_101 >= V_50 -> V_58 )
F_78 ( V_50 , V_161 , 0 , V_102 ) ;
V_8 -> V_83 = V_101 ;
V_8 -> V_14 -> V_159 ( V_8 , V_157 , false ) ;
F_32 ( V_101 < - 1 ,
L_12 ,
V_157 , V_101 , V_102 ) ;
F_61 ( V_50 , 0 , V_102 ) ;
break;
case V_167 :
F_7 ( V_8 -> V_61 , V_8 -> V_60 , V_50 -> V_58 ) ;
F_60 ( V_50 , false ) ;
V_8 -> V_14 -> V_164 ( V_50 , V_168 ) ;
V_8 -> V_14 -> V_159 ( V_8 , V_157 , true ) ;
F_32 ( V_101 != - 1 || V_102 != - 1 ,
L_12 ,
V_157 , V_101 , V_102 ) ;
F_61 ( V_50 , V_101 , V_102 ) ;
break;
case V_169 :
V_8 -> V_14 -> V_159 ( V_8 , V_157 , true ) ;
F_61 ( V_50 , V_101 , V_102 ) ;
V_8 -> V_14 -> V_170 ( V_8 ) ;
V_8 -> V_83 = 0 ;
break;
case V_171 :
case V_172 :
V_8 -> V_14 -> V_159 ( V_8 , V_157 , false ) ;
F_32 ( V_101 != - 1 ,
L_13 ,
V_157 , V_101 ) ;
F_61 ( V_50 , V_101 , V_102 ) ;
break;
case V_173 :
V_8 -> V_14 -> V_159 ( V_8 , V_157 , false ) ;
F_61 ( V_50 , V_101 , V_102 ) ;
V_8 -> V_14 -> V_164 ( V_50 , V_165 ) ;
F_1 ( V_8 -> V_60 , V_8 -> V_61 , 512 ) ;
V_8 -> V_83 = 0 ;
break;
default:
F_32 ( 1 , L_14 ,
V_157 ) ;
break;
}
}
static inline int F_79 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_174 ;
}
static inline int F_80 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_175 ;
}
static inline int F_81 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_176 ;
}
static inline int F_82 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_177 ;
}
static inline int F_83 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_178 ;
}
static int T_11 F_84 ( struct V_7 * V_8 )
{
struct V_179 * V_180 = V_8 -> V_33 -> V_181 ;
struct V_182 * V_183 = & V_8 -> V_183 ;
const struct V_184 * V_185 =
F_85 ( V_186 , V_8 -> V_33 ) ;
int V_187 ;
if ( ! V_180 )
return 1 ;
if ( F_86 ( V_180 ) >= 0 )
V_183 -> V_188 = 1 ;
V_183 -> V_189 = F_87 ( V_180 ) ;
V_187 = F_88 ( V_180 ) ;
if ( V_187 < 0 )
return V_187 ;
V_183 -> V_190 = V_187 / 8 ;
V_8 -> V_14 = V_185 -> V_191 ;
return 0 ;
}
static int T_11 F_84 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_89 ( struct V_192 * V_193 )
{
struct V_52 * V_93 ;
struct V_49 * V_50 ;
struct V_7 * V_8 ;
struct V_194 * V_195 ;
int V_71 = 0 ;
V_8 = F_90 ( & V_193 -> V_33 , sizeof( struct V_7 ) ,
V_196 ) ;
if ( ! V_8 )
return - V_197 ;
V_8 -> V_60 = F_90 ( & V_193 -> V_33 , V_198 , V_196 ) ;
if ( ! V_8 -> V_60 )
return - V_197 ;
V_8 -> V_33 = & V_193 -> V_33 ;
V_93 = & V_8 -> V_199 ;
V_50 = & V_8 -> V_50 ;
V_50 -> V_53 = V_93 ;
V_50 -> V_200 = V_201 ;
V_50 -> V_33 . V_202 = & V_193 -> V_33 ;
V_50 -> V_203 = V_204 ;
V_93 -> V_205 = 5 ;
V_93 -> V_53 = V_8 ;
V_93 -> V_206 = F_45 ;
V_93 -> V_207 = F_78 ;
V_93 -> V_208 = F_51 ;
V_93 -> V_209 = F_52 ;
V_93 -> V_210 = F_53 ;
V_93 -> V_211 = F_55 ;
V_8 -> V_91 = F_91 ( & V_193 -> V_33 , NULL ) ;
if ( F_92 ( V_8 -> V_91 ) )
return F_93 ( V_8 -> V_91 ) ;
V_71 = F_84 ( V_8 ) ;
if ( V_71 > 0 ) {
struct V_182 * V_183 =
F_94 ( & V_193 -> V_33 ) ;
if ( V_183 ) {
V_8 -> V_183 = * V_183 ;
V_8 -> V_14 = (struct V_212 * )
V_193 -> V_213 -> V_214 ;
} else {
V_71 = - V_215 ;
}
}
if ( V_71 < 0 )
return V_71 ;
if ( V_8 -> V_14 -> V_216 ) {
V_195 = F_95 ( V_193 , V_217 , 0 ) ;
V_8 -> V_218 = F_96 ( & V_193 -> V_33 , V_195 ) ;
if ( F_92 ( V_8 -> V_218 ) )
return F_93 ( V_8 -> V_218 ) ;
V_195 = F_95 ( V_193 , V_217 , 1 ) ;
} else {
V_195 = F_95 ( V_193 , V_217 , 0 ) ;
}
V_8 -> V_219 = F_96 ( & V_193 -> V_33 , V_195 ) ;
if ( F_92 ( V_8 -> V_219 ) )
return F_93 ( V_8 -> V_219 ) ;
V_8 -> V_61 = V_8 -> V_219 ;
if ( V_8 -> V_14 -> V_220 )
V_8 -> V_221 = V_8 -> V_219 + V_8 -> V_14 -> V_220 ;
V_8 -> V_97 = V_8 -> V_219 + V_8 -> V_14 -> V_222 ;
if ( V_8 -> V_14 -> V_223 )
V_8 -> V_224 = V_8 -> V_219 + V_8 -> V_14 -> V_223 ;
V_93 -> V_114 . V_225 = V_8 -> V_14 -> V_108 ;
V_8 -> V_75 = V_8 -> V_14 -> V_75 ;
V_93 -> V_226 = V_8 -> V_14 -> V_226 ;
V_93 -> V_114 . V_3 = 512 ;
V_93 -> V_114 . V_106 = V_8 -> V_14 -> V_227 ;
if ( V_8 -> V_183 . V_188 ) {
V_93 -> V_114 . V_228 = F_50 ;
V_93 -> V_114 . V_229 = F_46 ;
V_93 -> V_114 . V_230 = V_8 -> V_14 -> V_231 ;
V_93 -> V_114 . V_65 = V_115 ;
} else {
V_93 -> V_114 . V_65 = V_232 ;
}
if ( V_8 -> V_183 . V_190 == 2 )
V_93 -> V_81 |= V_82 ;
if ( V_8 -> V_183 . V_189 ) {
V_93 -> V_233 = & V_234 ;
V_93 -> V_235 = & V_236 ;
V_93 -> V_237 |= V_238 ;
}
F_97 ( & V_8 -> V_27 ) ;
V_8 -> V_21 = F_98 ( V_193 , 0 ) ;
if ( V_8 -> V_21 < 0 )
return V_8 -> V_21 ;
V_8 -> V_14 -> F_19 ( V_8 , 0 ) ;
V_71 = F_99 ( & V_193 -> V_33 , V_8 -> V_21 , F_25 ,
0 , V_204 , V_8 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_58 ( V_8 -> V_91 ) ;
if ( V_71 )
return V_71 ;
V_8 -> V_90 = 1 ;
if ( V_8 -> V_14 -> V_15 ) {
F_21 ( V_8 -> V_21 ) ;
V_8 -> V_14 -> F_19 ( V_8 , 1 ) ;
}
if ( F_100 ( V_50 , F_81 ( V_8 ) ? 4 : 1 , NULL ) ) {
V_71 = - V_239 ;
goto V_240;
}
F_101 ( & V_193 -> V_33 , ( void * ) V_8 -> V_60 ) ;
V_8 -> V_60 = F_90 ( & V_193 -> V_33 , V_50 -> V_58 + V_50 -> V_88 ,
V_196 ) ;
if ( ! V_8 -> V_60 ) {
V_71 = - V_197 ;
goto V_240;
}
V_8 -> V_14 -> V_158 ( V_50 ) ;
if ( V_50 -> V_58 == 2048 )
V_93 -> V_114 . V_106 = V_8 -> V_14 -> V_241 ;
else if ( V_50 -> V_58 == 4096 ) {
V_93 -> V_114 . V_106 = V_8 -> V_14 -> V_242 ;
if ( F_62 ( V_50 ) == 8 )
F_63 ( V_93 -> V_114 . V_106 ) ;
}
V_8 -> V_100 = F_54 ( V_50 -> V_88 , 218U ) ;
if ( V_93 -> V_114 . V_65 == V_115 ) {
if ( F_79 ( V_8 ) || F_80 ( V_8 ) )
V_93 -> V_114 . V_243 = 1 ;
else
V_93 -> V_114 . V_243 = ( V_8 -> V_75 == 4 ) ? 4 : 8 ;
}
if ( F_102 ( V_50 ) ) {
V_71 = - V_239 ;
goto V_240;
}
F_103 (mtd, part_probes,
&(struct mtd_part_parser_data){
.of_node = pdev->dev.of_node,
},
host->pdata.parts,
host->pdata.nr_parts) ;
F_104 ( V_193 , V_8 ) ;
return 0 ;
V_240:
if ( V_8 -> V_90 )
F_57 ( V_8 -> V_91 ) ;
return V_71 ;
}
static int F_105 ( struct V_192 * V_193 )
{
struct V_7 * V_8 = F_106 ( V_193 ) ;
F_107 ( & V_8 -> V_50 ) ;
if ( V_8 -> V_90 )
F_57 ( V_8 -> V_91 ) ;
return 0 ;
}
