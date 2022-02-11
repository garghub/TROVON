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
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_5 V_9 ;
V_9 = F_12 ( V_53 ) ;
V_9 &= ~ ( 7 << 4 ) ;
F_13 ( V_9 , V_53 ) ;
F_13 ( V_51 , V_40 ) ;
F_27 ( V_8 , false ) ;
}
static void F_41 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
F_16 ( V_8 -> V_54 << 4 , V_55 ) ;
F_16 ( V_51 , V_12 ) ;
F_27 ( V_8 , true ) ;
}
static void F_42 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
int V_56 , V_4 ;
if ( V_50 -> V_57 > 512 )
V_56 = 4 ;
else
V_56 = 1 ;
for ( V_4 = 0 ; V_4 < V_56 ; V_4 ++ ) {
F_16 ( ( V_8 -> V_54 << 4 ) | V_4 , V_55 ) ;
F_16 ( V_51 , V_12 ) ;
F_27 ( V_8 , true ) ;
}
}
static void F_43 ( struct V_7 * V_8 )
{
F_13 ( V_58 , V_40 ) ;
F_27 ( V_8 , true ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 , 16 ) ;
}
static void F_44 ( struct V_7 * V_8 )
{
F_16 ( V_8 -> V_54 << 4 , V_55 ) ;
F_16 ( V_58 , V_12 ) ;
F_27 ( V_8 , true ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 , 16 ) ;
}
static T_6 F_45 ( struct V_7 * V_8 )
{
F_16 ( V_61 , V_40 ) ;
F_27 ( V_8 , true ) ;
return F_12 ( V_53 ) >> 16 ;
}
static T_6 F_46 ( struct V_7 * V_8 )
{
void T_1 * V_62 = V_8 -> V_60 ;
T_5 V_63 ;
T_6 V_30 ;
F_16 ( V_8 -> V_54 << 4 , V_55 ) ;
V_63 = F_12 ( V_62 ) ;
F_16 ( V_61 , V_12 ) ;
F_27 ( V_8 , true ) ;
V_30 = F_15 ( V_62 ) ;
F_13 ( V_63 , V_62 ) ;
return V_30 ;
}
static int F_47 ( struct V_49 * V_50 )
{
return 1 ;
}
static void F_48 ( struct V_49 * V_50 , int V_64 )
{
}
static int F_49 ( struct V_49 * V_50 , T_8 * V_65 ,
T_8 * V_66 , T_8 * V_67 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_6 V_68 = F_22 ( V_8 ) ;
if ( ( ( V_68 & 0x3 ) == 2 ) || ( ( V_68 >> 2 ) == 2 ) ) {
F_35 ( L_7 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_50 ( struct V_49 * V_50 , T_8 * V_65 ,
T_8 * V_66 , T_8 * V_67 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_3 V_70 , V_71 ;
int V_72 = 1 ;
int V_30 = 0 ;
T_9 V_73 , V_74 ;
V_73 = ( V_8 -> V_75 == 4 ) ? 0x7 : 0xf ;
V_74 = ( V_8 -> V_75 == 4 ) ? 0x4 : 0x8 ;
V_72 = V_50 -> V_57 >> 9 ;
V_70 = V_8 -> V_14 -> V_76 ( V_8 ) ;
do {
V_71 = V_70 & V_73 ;
if ( V_71 > V_74 ) {
F_51 ( V_77 L_8 ) ;
return - V_69 ;
} else {
V_30 += V_71 ;
}
V_70 >>= 4 ;
} while ( -- V_72 );
F_35 ( L_9 , V_30 ) ;
return V_30 ;
}
static int F_52 ( struct V_49 * V_50 , const T_8 * V_65 ,
T_8 * V_78 )
{
return 0 ;
}
static T_8 F_53 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_10 V_30 ;
if ( V_8 -> V_79 )
return V_8 -> V_14 -> V_80 ( V_8 ) & 0xFF ;
if ( V_52 -> V_81 & V_82 ) {
V_30 = * ( T_6 * ) ( V_8 -> V_59 + V_8 -> V_83 ) ;
V_8 -> V_83 += 2 ;
} else {
V_30 = * ( T_10 * ) ( V_8 -> V_59 + V_8 -> V_83 ) ;
V_8 -> V_83 ++ ;
}
F_35 ( L_10 , V_43 , V_30 , V_8 -> V_83 ) ;
return V_30 ;
}
static T_6 F_54 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_6 V_30 ;
V_30 = * ( T_6 * ) ( V_8 -> V_59 + V_8 -> V_83 ) ;
V_8 -> V_83 += 2 ;
return V_30 ;
}
static void F_55 ( struct V_49 * V_50 ,
const T_8 * V_84 , int V_85 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_4 V_86 = V_8 -> V_83 ;
int V_87 = V_50 -> V_88 + V_50 -> V_57 - V_86 ;
V_87 = F_56 ( V_87 , V_85 ) ;
memcpy ( V_8 -> V_59 + V_86 , V_84 , V_87 ) ;
V_8 -> V_83 += V_87 ;
}
static void F_57 ( struct V_49 * V_50 , T_8 * V_84 , int V_85 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_4 V_86 = V_8 -> V_83 ;
int V_87 = V_50 -> V_88 + V_50 -> V_57 - V_86 ;
V_87 = F_56 ( V_87 , V_85 ) ;
memcpy ( V_84 , V_8 -> V_59 + V_86 , V_87 ) ;
V_8 -> V_83 += V_87 ;
}
static void F_58 ( struct V_49 * V_50 , int V_89 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_59 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_60 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
}
static void F_61 ( struct V_49 * V_50 , int V_89 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
if ( V_89 == - 1 ) {
if ( V_8 -> V_90 ) {
F_59 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 0 ;
}
return;
}
if ( ! V_8 -> V_90 ) {
F_60 ( V_8 -> V_91 ) ;
V_8 -> V_90 = 1 ;
}
V_8 -> V_54 = V_89 ;
F_16 ( V_8 -> V_54 << 4 , V_55 ) ;
}
static void F_62 ( struct V_49 * V_50 , bool V_92 )
{
struct V_52 * V_93 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_93 ) ;
T_4 V_4 , V_94 ;
T_4 V_95 = V_50 -> V_57 / 512 ;
T_9 * V_96 = V_8 -> V_59 + V_50 -> V_57 ;
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
F_9 ( & V_6 [ V_4 * V_98 ] ,
& V_96 [ V_4 * V_94 ] ,
V_8 -> V_100 - V_4 * V_94 ) ;
}
}
static void F_63 ( struct V_49 * V_50 , int V_101 , int V_102 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
if ( V_101 != - 1 ) {
V_8 -> V_14 -> V_103 ( V_8 , V_101 & 0xff ,
V_102 == - 1 ) ;
if ( V_50 -> V_57 > 512 )
V_8 -> V_14 -> V_103 ( V_8 ,
( V_101 >> 8 ) & 0xff ,
false ) ;
}
if ( V_102 != - 1 ) {
V_8 -> V_14 -> V_103 ( V_8 , ( V_102 & 0xff ) , false ) ;
if ( V_50 -> V_57 > 512 ) {
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
static int F_64 ( struct V_49 * V_50 , int V_104 ,
struct V_105 * V_106 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
if ( V_104 >= V_52 -> V_107 . V_108 )
return - V_109 ;
V_106 -> V_110 = ( V_104 * 16 ) + 6 ;
V_106 -> V_111 = V_52 -> V_107 . V_112 ;
return 0 ;
}
static int F_65 ( struct V_49 * V_50 , int V_104 ,
struct V_105 * V_106 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
if ( V_104 > V_52 -> V_107 . V_108 )
return - V_109 ;
if ( ! V_104 ) {
if ( V_50 -> V_57 <= 512 ) {
V_106 -> V_110 = 0 ;
V_106 -> V_111 = 5 ;
} else {
V_106 -> V_110 = 2 ;
V_106 -> V_111 = 4 ;
}
} else {
V_106 -> V_110 = ( ( V_104 - 1 ) * 16 ) +
V_52 -> V_107 . V_112 + 6 ;
if ( V_104 < V_52 -> V_107 . V_108 )
V_106 -> V_111 = ( V_104 * 16 ) + 6 -
V_106 -> V_110 ;
else
V_106 -> V_111 = V_50 -> V_88 - V_106 -> V_110 ;
}
return 0 ;
}
static int F_66 ( struct V_49 * V_50 , int V_104 ,
struct V_105 * V_106 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
int V_113 = V_52 -> V_107 . V_112 == 9 ? 16 : 26 ;
if ( V_104 >= V_52 -> V_107 . V_108 )
return - V_109 ;
V_106 -> V_110 = ( V_104 * V_113 ) + 7 ;
V_106 -> V_111 = V_52 -> V_107 . V_112 ;
return 0 ;
}
static int F_67 ( struct V_49 * V_50 , int V_104 ,
struct V_105 * V_106 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
int V_113 = V_52 -> V_107 . V_112 == 9 ? 16 : 26 ;
if ( V_104 >= V_52 -> V_107 . V_108 )
return - V_109 ;
if ( ! V_104 ) {
if ( V_50 -> V_57 <= 512 ) {
V_106 -> V_110 = 0 ;
V_106 -> V_111 = 5 ;
} else {
V_106 -> V_110 = 2 ;
V_106 -> V_111 = 4 ;
}
} else {
V_106 -> V_110 = V_104 * V_113 ;
V_106 -> V_111 = 7 ;
}
return 0 ;
}
static int F_68 ( struct V_49 * V_50 )
{
int V_114 = 0 ;
V_114 = V_50 -> V_88 * 512 / V_50 -> V_57 ;
if ( V_114 < 26 )
return 4 ;
else
return 8 ;
}
static void F_69 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_6 V_115 = 0 ;
if ( V_52 -> V_107 . V_64 == V_116 && V_50 -> V_57 )
V_115 |= V_117 ;
if ( ! V_8 -> V_14 -> V_15 )
V_115 |= V_18 ;
V_8 -> V_75 = 1 ;
F_16 ( V_115 , V_17 ) ;
F_16 ( 0x2 , V_118 ) ;
F_16 ( 0x0 , V_119 ) ;
F_16 ( 0xffff , V_120 ) ;
F_16 ( 0x4 , V_121 ) ;
}
static int F_70 ( struct V_49 * V_50 ,
const struct V_122 * V_123 ,
bool V_124 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
int V_125 , V_126 , V_30 ;
unsigned long V_127 , V_128 ;
const struct V_129 * V_130 ;
T_4 V_115 ;
V_130 = F_71 ( V_123 ) ;
if ( F_72 ( V_130 ) )
return - V_131 ;
V_115 = F_15 ( V_17 ) ;
V_125 = V_130 -> V_132 / 1000 ;
V_127 = 1000000000 / V_125 ;
if ( V_125 < 30 ) {
V_128 = F_73 ( V_8 -> V_91 , V_127 ) ;
V_115 |= V_133 ;
V_126 = 1000000000 / ( V_128 / 1000 ) ;
} else {
V_127 *= 2 ;
V_128 = F_73 ( V_8 -> V_91 , V_127 ) ;
V_115 &= ~ V_133 ;
V_126 = 1000000000 / ( V_128 / 1000 / 2 ) ;
}
if ( V_130 -> V_134 > V_126 - 1000 ||
V_130 -> V_135 > V_126 - 2000 ||
V_130 -> V_136 > V_126 - 1000 ||
V_130 -> V_137 > V_126 - 2000 ||
V_130 -> V_138 > V_126 - 1500 ||
V_130 -> V_139 > V_126 ||
V_130 -> V_140 > V_126 - 3000 ||
V_130 -> V_141 > V_126 ||
V_130 -> V_142 > V_126 - 5000 ||
V_130 -> V_143 > 2 * V_126 ||
V_130 -> V_144 > V_126 - 2500 ||
V_130 -> V_145 > 6 * V_126 ||
V_130 -> V_146 > 3 * V_126 / 2 ||
V_130 -> V_132 > 2 * V_126 ||
V_130 -> V_147 > ( V_126 / 2 ) - 2500 ) {
F_30 ( V_8 -> V_33 , L_11 ) ;
return - V_148 ;
}
if ( V_124 )
return 0 ;
V_30 = F_74 ( V_8 -> V_91 , V_127 ) ;
if ( V_30 )
return V_30 ;
F_16 ( V_115 , V_17 ) ;
F_30 ( V_8 -> V_33 , L_12 , V_128 ,
V_115 & V_133 ? L_13 :
L_14 ) ;
return 0 ;
}
static void F_75 ( struct V_49 * V_50 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
T_6 V_115 = 0 ;
V_115 |= V_149 ;
if ( ! V_8 -> V_14 -> V_15 )
V_115 |= V_18 ;
if ( V_50 -> V_57 ) {
T_6 V_150 = V_50 -> V_151 / V_50 -> V_57 ;
if ( V_52 -> V_107 . V_64 == V_116 )
V_115 |= V_117 ;
V_8 -> V_75 = F_68 ( V_50 ) ;
if ( V_8 -> V_75 == 4 )
V_115 |= V_152 ;
V_115 |= F_76 ( F_77 ( V_150 ) - 6 ) ;
} else {
V_8 -> V_75 = 1 ;
}
F_16 ( V_115 , V_17 ) ;
F_16 ( 0x2 , V_118 ) ;
F_16 ( 0x0 , V_153 ) ;
F_16 ( 0x0 , V_154 ) ;
F_16 ( 0x0 , V_155 ) ;
F_16 ( 0x0 , V_156 ) ;
F_16 ( 0xffff , V_157 ) ;
F_16 ( 0xffff , V_158 ) ;
F_16 ( 0xffff , V_159 ) ;
F_16 ( 0xffff , V_160 ) ;
F_16 ( 0x4 , V_121 ) ;
}
static void F_78 ( struct V_49 * V_50 )
{
struct V_52 * V_89 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_89 ) ;
T_5 V_161 , V_162 ;
int V_4 , V_163 ;
F_13 ( F_79 ( 0 ) , V_53 ) ;
F_13 ( V_164 , V_10 ) ;
F_13 ( V_165 | V_166 ,
V_167 ) ;
for ( V_4 = 0 ; V_4 < V_168 ; V_4 ++ )
F_13 ( 0xffff << 16 , V_169 + ( V_4 << 2 ) ) ;
F_13 ( 0 , V_10 ) ;
V_161 = V_170 |
V_171 |
F_80 ( V_50 -> V_88 >> 1 ) |
F_81 ( 0x70 ) |
V_20 |
V_172 ;
V_163 = F_82 ( V_89 -> V_173 ) >> 3 ;
if ( V_50 -> V_57 == 2048 ) {
V_161 |= V_174 ;
V_161 |= F_83 ( V_163 ) ;
} else if ( V_50 -> V_57 == 4096 ) {
V_161 |= V_175 ;
V_161 |= F_83 ( V_163 ) ;
} else {
V_161 |= V_176 ;
V_161 |= F_83 ( V_163 - 1 ) ;
}
if ( V_50 -> V_57 ) {
if ( V_89 -> V_107 . V_64 == V_116 )
V_161 |= V_177 ;
V_161 |= F_84 (
F_77 ( V_50 -> V_151 / V_50 -> V_57 ) - 6 ,
V_8 -> V_14 -> V_178 ) ;
V_8 -> V_75 = F_68 ( V_50 ) ;
if ( V_8 -> V_75 == 8 )
V_161 |= V_179 ;
}
F_13 ( V_161 , V_19 ) ;
V_162 = F_85 ( 0 ) |
V_180 |
V_181 |
F_86 ( 6 ) |
F_87 ( 0 ) ;
if ( ! ( V_89 -> V_81 & V_82 ) )
V_162 |= V_182 ;
F_13 ( V_162 , V_183 ) ;
F_13 ( 0 , V_184 ) ;
}
static void F_88 ( struct V_49 * V_50 , unsigned V_185 ,
int V_101 , int V_102 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
F_35 ( L_15 ,
V_185 , V_101 , V_102 ) ;
V_8 -> V_79 = false ;
switch ( V_185 ) {
case V_42 :
V_8 -> V_14 -> V_186 ( V_50 ) ;
V_8 -> V_14 -> V_187 ( V_8 , V_185 , false ) ;
break;
case V_188 :
V_8 -> V_83 = 0 ;
V_8 -> V_79 = true ;
V_8 -> V_14 -> V_187 ( V_8 , V_185 , true ) ;
F_32 ( V_101 != - 1 || V_102 != - 1 ,
L_16 ,
V_185 , V_101 , V_102 ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
break;
case V_189 :
case V_190 :
if ( V_185 == V_189 )
V_8 -> V_83 = V_101 ;
else
V_8 -> V_83 = V_101 + V_50 -> V_57 ;
V_185 = V_189 ;
V_8 -> V_14 -> V_187 ( V_8 , V_185 , false ) ;
F_32 ( V_101 < 0 ,
L_16 ,
V_185 , V_101 , V_102 ) ;
F_63 ( V_50 , 0 , V_102 ) ;
if ( V_50 -> V_57 > 512 )
V_8 -> V_14 -> V_187 ( V_8 ,
V_191 , true ) ;
V_8 -> V_14 -> V_192 ( V_50 , V_193 ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 ,
V_50 -> V_57 ) ;
F_62 ( V_50 , true ) ;
break;
case V_194 :
if ( V_101 >= V_50 -> V_57 )
F_88 ( V_50 , V_189 , 0 , V_102 ) ;
V_8 -> V_83 = V_101 ;
V_8 -> V_14 -> V_187 ( V_8 , V_185 , false ) ;
F_32 ( V_101 < - 1 ,
L_16 ,
V_185 , V_101 , V_102 ) ;
F_63 ( V_50 , 0 , V_102 ) ;
break;
case V_195 :
F_7 ( V_8 -> V_60 , V_8 -> V_59 , V_50 -> V_57 ) ;
F_62 ( V_50 , false ) ;
V_8 -> V_14 -> V_192 ( V_50 , V_196 ) ;
V_8 -> V_14 -> V_187 ( V_8 , V_185 , true ) ;
F_32 ( V_101 != - 1 || V_102 != - 1 ,
L_16 ,
V_185 , V_101 , V_102 ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
break;
case V_197 :
V_8 -> V_14 -> V_187 ( V_8 , V_185 , true ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
V_8 -> V_14 -> V_198 ( V_8 ) ;
V_8 -> V_83 = 0 ;
break;
case V_199 :
case V_200 :
V_8 -> V_14 -> V_187 ( V_8 , V_185 , false ) ;
F_32 ( V_101 != - 1 ,
L_17 ,
V_185 , V_101 ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
break;
case V_201 :
V_8 -> V_14 -> V_187 ( V_8 , V_185 , false ) ;
F_63 ( V_50 , V_101 , V_102 ) ;
V_8 -> V_14 -> V_192 ( V_50 , V_193 ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 , 512 ) ;
V_8 -> V_83 = 0 ;
break;
default:
F_32 ( 1 , L_18 ,
V_185 ) ;
break;
}
}
static int F_89 ( struct V_49 * V_50 ,
struct V_52 * V_89 , int V_44 ,
T_9 * V_202 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
int V_4 ;
if ( ! V_89 -> V_203 ||
! ( F_90 ( V_89 -> V_204 . V_205 )
& V_206 ) )
return - V_148 ;
V_8 -> V_83 = 0 ;
for ( V_4 = 0 ; V_4 < V_207 ; ++ V_4 )
V_89 -> V_208 ( V_50 , V_202 [ V_4 ] ) ;
F_7 ( V_8 -> V_60 , V_8 -> V_59 , V_50 -> V_57 ) ;
V_8 -> V_14 -> V_187 ( V_8 , V_209 , false ) ;
F_63 ( V_50 , V_44 , - 1 ) ;
V_8 -> V_14 -> V_192 ( V_50 , V_196 ) ;
return 0 ;
}
static int F_91 ( struct V_49 * V_50 ,
struct V_52 * V_89 , int V_44 ,
T_9 * V_202 )
{
struct V_52 * V_52 = F_39 ( V_50 ) ;
struct V_7 * V_8 = F_40 ( V_52 ) ;
int V_4 ;
if ( ! V_89 -> V_203 ||
! ( F_90 ( V_89 -> V_204 . V_205 )
& V_206 ) )
return - V_148 ;
V_8 -> V_14 -> V_187 ( V_8 , V_210 , false ) ;
F_63 ( V_50 , V_44 , - 1 ) ;
V_8 -> V_14 -> V_192 ( V_50 , V_193 ) ;
F_1 ( V_8 -> V_59 , V_8 -> V_60 , 512 ) ;
V_8 -> V_83 = 0 ;
for ( V_4 = 0 ; V_4 < V_207 ; ++ V_4 )
* V_202 ++ = V_89 -> V_211 ( V_50 ) ;
return 0 ;
}
static inline int F_92 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_212 ;
}
static inline int F_93 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_213 ;
}
static inline int F_94 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_214 ;
}
static inline int F_95 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_215 ;
}
static inline int F_96 ( struct V_7 * V_8 )
{
return V_8 -> V_14 == & V_216 ;
}
static int T_11 F_97 ( struct V_7 * V_8 )
{
struct V_217 * V_218 = V_8 -> V_33 -> V_219 ;
const struct V_220 * V_221 =
F_98 ( V_222 , V_8 -> V_33 ) ;
if ( ! V_218 )
return 1 ;
V_8 -> V_14 = V_221 -> V_223 ;
return 0 ;
}
static int T_11 F_97 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_99 ( struct V_224 * V_225 )
{
struct V_52 * V_93 ;
struct V_49 * V_50 ;
struct V_7 * V_8 ;
struct V_226 * V_227 ;
int V_71 = 0 ;
V_8 = F_100 ( & V_225 -> V_33 , sizeof( struct V_7 ) ,
V_228 ) ;
if ( ! V_8 )
return - V_229 ;
V_8 -> V_59 = F_100 ( & V_225 -> V_33 , V_230 , V_228 ) ;
if ( ! V_8 -> V_59 )
return - V_229 ;
V_8 -> V_33 = & V_225 -> V_33 ;
V_93 = & V_8 -> V_231 ;
V_50 = F_101 ( V_93 ) ;
V_50 -> V_33 . V_232 = & V_225 -> V_33 ;
V_50 -> V_233 = V_234 ;
V_93 -> V_235 = 5 ;
F_102 ( V_93 , V_8 ) ;
F_103 ( V_93 , V_225 -> V_33 . V_219 ) ,
V_93 -> V_236 = F_47 ;
V_93 -> V_237 = F_88 ;
V_93 -> V_211 = F_53 ;
V_93 -> V_238 = F_54 ;
V_93 -> V_239 = F_55 ;
V_93 -> V_240 = F_57 ;
V_93 -> V_241 = F_89 ;
V_93 -> V_242 = F_91 ;
V_8 -> V_91 = F_104 ( & V_225 -> V_33 , NULL ) ;
if ( F_72 ( V_8 -> V_91 ) )
return F_105 ( V_8 -> V_91 ) ;
V_71 = F_97 ( V_8 ) ;
if ( V_71 > 0 ) {
struct V_243 * V_244 =
F_106 ( & V_225 -> V_33 ) ;
if ( V_244 ) {
V_8 -> V_244 = * V_244 ;
V_8 -> V_14 = (struct V_245 * )
V_225 -> V_246 -> V_247 ;
} else {
V_71 = - V_248 ;
}
}
if ( V_71 < 0 )
return V_71 ;
V_93 -> V_249 = V_8 -> V_14 -> V_249 ;
if ( V_8 -> V_14 -> V_250 ) {
V_227 = F_107 ( V_225 , V_251 , 0 ) ;
V_8 -> V_252 = F_108 ( & V_225 -> V_33 , V_227 ) ;
if ( F_72 ( V_8 -> V_252 ) )
return F_105 ( V_8 -> V_252 ) ;
V_227 = F_107 ( V_225 , V_251 , 1 ) ;
} else {
V_227 = F_107 ( V_225 , V_251 , 0 ) ;
}
V_8 -> V_253 = F_108 ( & V_225 -> V_33 , V_227 ) ;
if ( F_72 ( V_8 -> V_253 ) )
return F_105 ( V_8 -> V_253 ) ;
V_8 -> V_60 = V_8 -> V_253 ;
if ( V_8 -> V_14 -> V_254 )
V_8 -> V_255 = V_8 -> V_253 + V_8 -> V_14 -> V_254 ;
V_8 -> V_97 = V_8 -> V_253 + V_8 -> V_14 -> V_256 ;
if ( V_8 -> V_14 -> V_257 )
V_8 -> V_258 = V_8 -> V_253 + V_8 -> V_14 -> V_257 ;
V_93 -> V_107 . V_112 = V_8 -> V_14 -> V_259 ;
V_8 -> V_75 = V_8 -> V_14 -> V_75 ;
V_93 -> V_260 = V_8 -> V_14 -> V_260 ;
V_93 -> V_107 . V_3 = 512 ;
F_109 ( V_50 , V_8 -> V_14 -> V_261 ) ;
if ( V_8 -> V_244 . V_262 ) {
V_93 -> V_107 . V_64 = V_116 ;
} else {
V_93 -> V_107 . V_64 = V_263 ;
V_93 -> V_107 . V_264 = V_265 ;
}
if ( V_8 -> V_244 . V_266 == 2 )
V_93 -> V_81 |= V_82 ;
if ( V_8 -> V_244 . V_267 )
V_93 -> V_268 |= V_269 ;
F_110 ( & V_8 -> V_27 ) ;
V_8 -> V_21 = F_111 ( V_225 , 0 ) ;
if ( V_8 -> V_21 < 0 )
return V_8 -> V_21 ;
V_8 -> V_14 -> F_19 ( V_8 , 0 ) ;
V_71 = F_112 ( & V_225 -> V_33 , V_8 -> V_21 , F_25 ,
0 , V_234 , V_8 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_60 ( V_8 -> V_91 ) ;
if ( V_71 )
return V_71 ;
V_8 -> V_90 = 1 ;
if ( V_8 -> V_14 -> V_15 ) {
F_21 ( V_8 -> V_21 ) ;
V_8 -> V_14 -> F_19 ( V_8 , 1 ) ;
}
V_71 = F_113 ( V_50 , F_94 ( V_8 ) ? 4 : 1 , NULL ) ;
if ( V_71 )
goto V_270;
switch ( V_93 -> V_107 . V_64 ) {
case V_116 :
V_93 -> V_107 . V_271 = F_52 ;
V_93 -> V_107 . V_272 = F_48 ;
V_93 -> V_107 . V_273 = V_8 -> V_14 -> V_274 ;
break;
case V_263 :
break;
default:
V_71 = - V_148 ;
goto V_270;
}
if ( V_93 -> V_268 & V_269 ) {
V_93 -> V_275 = & V_276 ;
V_93 -> V_277 = & V_278 ;
}
F_114 ( & V_225 -> V_33 , ( void * ) V_8 -> V_59 ) ;
V_8 -> V_59 = F_100 ( & V_225 -> V_33 , V_50 -> V_57 + V_50 -> V_88 ,
V_228 ) ;
if ( ! V_8 -> V_59 ) {
V_71 = - V_229 ;
goto V_270;
}
V_8 -> V_14 -> V_186 ( V_50 ) ;
if ( ! V_93 -> V_107 . V_112 ) {
if ( V_8 -> V_75 == 8 )
V_93 -> V_107 . V_112 = 18 ;
else if ( V_8 -> V_75 == 4 )
V_93 -> V_107 . V_112 = 9 ;
}
V_8 -> V_100 = F_56 ( V_50 -> V_88 , 218U ) ;
if ( V_93 -> V_107 . V_64 == V_116 ) {
if ( F_92 ( V_8 ) || F_93 ( V_8 ) )
V_93 -> V_107 . V_279 = 1 ;
else
V_93 -> V_107 . V_279 = ( V_8 -> V_75 == 4 ) ? 4 : 8 ;
}
V_71 = F_115 ( V_50 ) ;
if ( V_71 )
goto V_270;
F_116 ( V_50 , V_280 ,
NULL ,
V_8 -> V_244 . V_281 ,
V_8 -> V_244 . V_282 ) ;
F_117 ( V_225 , V_8 ) ;
return 0 ;
V_270:
if ( V_8 -> V_90 )
F_59 ( V_8 -> V_91 ) ;
return V_71 ;
}
static int F_118 ( struct V_224 * V_225 )
{
struct V_7 * V_8 = F_119 ( V_225 ) ;
F_120 ( F_101 ( & V_8 -> V_231 ) ) ;
if ( V_8 -> V_90 )
F_59 ( V_8 -> V_91 ) ;
return 0 ;
}
