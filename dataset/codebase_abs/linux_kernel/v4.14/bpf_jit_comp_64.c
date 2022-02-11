static inline bool F_1 ( unsigned int V_1 )
{
return V_1 + 0x1000 < 0x2000 ;
}
static inline bool F_2 ( unsigned int V_1 )
{
return V_1 + 0x200 < 0x400 ;
}
static inline bool F_3 ( unsigned int V_1 )
{
return V_1 + 0x10 < 0x20 ;
}
static inline bool F_4 ( unsigned int V_1 )
{
return ( V_1 & ~ 0x3fffff ) == 0 ;
}
static void F_5 ( void * V_2 , void * V_3 )
{
if ( V_4 == V_5 ) {
unsigned long V_6 = ( unsigned long ) V_2 ;
unsigned long V_7 = ( unsigned long ) V_3 ;
V_6 &= ~ 7UL ;
V_7 = ( V_7 + 7UL ) & ~ 7UL ;
while ( V_6 < V_7 ) {
F_6 ( V_6 ) ;
V_6 += 32 ;
}
}
}
static T_1 F_7 ( T_1 V_8 )
{
T_1 V_9 = ( ( V_8 >> 2 ) & 0xff ) << 5 ;
V_9 |= ( ( V_8 >> ( 2 + 8 ) ) & 0x03 ) << 19 ;
return V_9 ;
}
static void F_8 ( const T_1 V_10 , struct V_11 * V_12 )
{
if ( V_12 -> V_13 != NULL )
V_12 -> V_13 [ V_12 -> V_14 ] = V_10 ;
V_12 -> V_14 ++ ;
}
static void F_9 ( T_1 * V_15 , struct V_11 * V_12 )
{
if ( V_12 -> V_13 != NULL ) {
void * V_16 = & V_12 -> V_13 [ V_12 -> V_14 ] ;
unsigned int V_8 ;
V_8 = ( void * ) V_15 - V_16 ;
V_12 -> V_13 [ V_12 -> V_14 ] = V_17 | ( ( V_8 >> 2 ) & 0x3fffffff ) ;
}
V_12 -> V_14 ++ ;
}
static void F_10 ( struct V_11 * V_12 )
{
F_8 ( F_11 ( 0 , V_18 ) , V_12 ) ;
}
static void F_12 ( T_1 V_19 , T_1 V_20 , struct V_11 * V_12 )
{
F_8 ( V_21 | F_13 ( V_18 ) | F_14 ( V_19 ) | F_15 ( V_20 ) , V_12 ) ;
}
static void F_16 ( T_2 V_22 , T_1 V_23 , struct V_11 * V_12 )
{
F_8 ( F_11 ( V_22 , V_23 ) , V_12 ) ;
F_8 ( F_17 ( V_22 , V_23 ) , V_12 ) ;
}
static void F_18 ( T_2 V_22 , T_1 V_23 , struct V_11 * V_12 )
{
if ( V_22 >= 0 ) {
F_8 ( F_11 ( V_22 , V_23 ) , V_12 ) ;
F_8 ( F_17 ( V_22 , V_23 ) , V_12 ) ;
} else {
T_1 V_24 = ~ ( T_1 ) V_22 ;
T_1 V_25 = - 0x400 | ( T_1 ) V_22 ;
F_8 ( F_11 ( V_24 , V_23 ) , V_12 ) ;
F_8 ( V_26 | V_27 | F_13 ( V_23 ) | F_19 ( V_25 ) | F_15 ( V_23 ) , V_12 ) ;
}
}
static void F_20 ( T_1 V_28 , T_1 V_29 , T_1 V_30 , struct V_11 * V_12 )
{
F_8 ( V_28 | F_13 ( V_30 ) | F_14 ( V_29 ) | F_15 ( V_30 ) , V_12 ) ;
}
static void F_21 ( T_1 V_28 , T_1 V_31 , T_1 V_32 , T_1 V_33 , struct V_11 * V_12 )
{
F_8 ( V_28 | F_13 ( V_31 ) | F_14 ( V_32 ) | F_15 ( V_33 ) , V_12 ) ;
}
static void F_22 ( unsigned int V_28 , unsigned int V_30 , unsigned int V_34 ,
struct V_11 * V_12 )
{
bool V_35 = F_1 ( V_34 ) ;
unsigned int V_10 = V_28 ;
V_10 |= F_13 ( V_30 ) | F_15 ( V_30 ) ;
if ( V_35 ) {
F_8 ( V_10 | V_27 | F_19 ( V_34 ) , V_12 ) ;
} else {
unsigned int V_36 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_18 ( V_34 , V_36 , V_12 ) ;
F_8 ( V_10 | F_14 ( V_36 ) , V_12 ) ;
}
}
static void F_23 ( unsigned int V_28 , unsigned int V_29 , unsigned int V_34 ,
unsigned int V_30 , struct V_11 * V_12 )
{
bool V_35 = F_1 ( V_34 ) ;
unsigned int V_10 = V_28 ;
V_10 |= F_13 ( V_29 ) | F_15 ( V_30 ) ;
if ( V_35 ) {
F_8 ( V_10 | V_27 | F_19 ( V_34 ) , V_12 ) ;
} else {
unsigned int V_36 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_18 ( V_34 , V_36 , V_12 ) ;
F_8 ( V_10 | F_14 ( V_36 ) , V_12 ) ;
}
}
static void F_24 ( T_2 V_22 , unsigned int V_40 , struct V_11 * V_12 )
{
if ( V_22 >= 0 && F_1 ( V_22 ) ) {
F_8 ( V_21 | V_27 | F_13 ( V_18 ) | F_19 ( V_22 ) | F_15 ( V_40 ) , V_12 ) ;
} else {
F_16 ( V_22 , V_40 , V_12 ) ;
}
}
static void F_25 ( T_2 V_22 , unsigned int V_40 , struct V_11 * V_12 )
{
if ( F_1 ( V_22 ) ) {
F_8 ( V_21 | V_27 | F_13 ( V_18 ) | F_19 ( V_22 ) | F_15 ( V_40 ) , V_12 ) ;
} else {
F_16 ( V_22 , V_40 , V_12 ) ;
}
}
static void F_26 ( T_2 V_22 , unsigned int V_40 , struct V_11 * V_12 )
{
if ( F_1 ( V_22 ) ) {
F_8 ( V_21 | V_27 | F_13 ( V_18 ) | F_19 ( V_22 ) | F_15 ( V_40 ) , V_12 ) ;
} else {
F_18 ( V_22 , V_40 , V_12 ) ;
}
}
static void F_27 ( T_1 V_41 , T_1 V_42 ,
int * V_43 , int * V_44 , int * V_45 )
{
int V_46 , V_47 , V_48 ;
int V_49 ;
V_46 = V_47 = - 1 ;
V_49 = 0 ;
do {
if ( ( V_46 == - 1 ) && ( ( V_42 >> V_49 ) & 1 ) )
V_46 = V_49 ;
if ( ( V_47 == - 1 ) && ( ( V_41 >> ( 32 - V_49 - 1 ) ) & 1 ) )
V_47 = ( 64 - V_49 - 1 ) ;
} while ( ++ V_49 < 32 && ( V_47 == - 1 ||
V_46 == - 1 ) );
if ( V_49 == 32 ) {
V_49 = 0 ;
do {
if ( V_46 == - 1 && ( ( V_41 >> V_49 ) & 1 ) )
V_46 = V_49 + 32 ;
if ( V_47 == - 1 &&
( ( V_42 >> ( 32 - V_49 - 1 ) ) & 1 ) )
V_47 = 32 - V_49 - 1 ;
} while ( ++ V_49 < 32 && ( V_47 == - 1 ||
V_46 == - 1 ) );
}
V_48 = 1 ;
for ( V_49 = V_46 ; V_49 <= V_47 ; V_49 ++ ) {
if ( V_49 < 32 ) {
if ( ( V_42 & ( 1 << V_49 ) ) != 0 )
continue;
} else {
if ( ( V_41 & ( 1 << ( V_49 - 32 ) ) ) != 0 )
continue;
}
V_48 = 0 ;
break;
}
* V_43 = V_47 ;
* V_44 = V_46 ;
* V_45 = V_48 ;
}
static unsigned long F_28 ( unsigned long V_41 ,
unsigned long V_42 ,
int V_46 , int V_50 )
{
long V_51 , V_52 ;
if ( V_46 < 32 ) {
V_52 = ( V_42 >> V_46 ) << V_50 ;
V_51 = ( ( V_41 << ( 32 - V_46 ) ) << V_50 ) ;
} else {
V_52 = 0 ;
V_51 = ( ( V_41 >> ( V_46 - 32 ) ) << V_50 ) ;
}
return V_51 | V_52 ;
}
static bool F_29 ( unsigned long V_41 ,
unsigned long V_42 )
{
int V_47 , V_46 , V_48 ;
if ( V_41 == 0 || V_41 == 0xffffffff )
return true ;
F_27 ( V_41 , V_42 ,
& V_47 , & V_46 ,
& V_48 ) ;
if ( ( V_47 == 63 || V_46 == 0 ) &&
V_48 != 0 )
return true ;
if ( V_47 - V_46 < 21 )
return true ;
return false ;
}
static void F_30 ( unsigned long V_41 ,
unsigned long V_53 ,
unsigned int V_40 ,
int V_54 , struct V_11 * V_12 )
{
F_24 ( V_41 , V_40 , V_12 ) ;
F_22 ( V_55 , V_40 , V_54 , V_12 ) ;
if ( V_53 != 0 )
F_8 ( V_21 | V_27 | F_13 ( V_40 ) | F_19 ( V_53 ) | F_15 ( V_40 ) , V_12 ) ;
}
static void F_31 ( T_3 V_22 , unsigned int V_40 , struct V_11 * V_12 )
{
int V_48 , V_46 , V_47 ;
unsigned int V_36 = V_37 [ V_38 ] ;
T_1 V_42 = ( V_22 & 0xffffffff ) ;
T_1 V_41 = ( V_22 >> 32 ) ;
if ( V_41 == 0xffffffff && ( V_42 & 0x80000000 ) )
return F_26 ( V_22 , V_40 , V_12 ) ;
if ( V_41 == 0x00000000 )
return F_24 ( V_22 , V_40 , V_12 ) ;
F_27 ( V_41 , V_42 , & V_47 ,
& V_46 , & V_48 ) ;
if ( ( ( V_47 == 63 || V_46 == 0 ) &&
V_48 != 0 ) ||
( ( V_47 - V_46 ) < 12 ) ) {
int V_50 = V_46 ;
long V_56 = - 1 ;
if ( ( V_47 != 63 && V_46 != 0 ) ||
V_48 == 0 ) {
V_56 =
F_28 ( V_41 , V_42 ,
V_46 , 0 ) ;
} else if ( V_46 == 0 )
V_50 = - ( 63 - V_47 ) ;
F_8 ( V_21 | V_27 | F_13 ( V_18 ) | F_19 ( V_56 ) | F_15 ( V_40 ) , V_12 ) ;
if ( V_50 > 0 )
F_22 ( V_55 , V_40 , V_50 , V_12 ) ;
else if ( V_50 < 0 )
F_22 ( V_57 , V_40 , - V_50 , V_12 ) ;
return;
}
if ( ( V_47 - V_46 ) < 21 ) {
unsigned long V_58 =
F_28 ( V_41 , V_42 ,
V_46 , 10 ) ;
F_8 ( F_11 ( V_58 , V_40 ) , V_12 ) ;
if ( V_46 < 10 )
F_22 ( V_57 , V_40 , 10 - V_46 , V_12 ) ;
else if ( V_46 > 10 )
F_22 ( V_55 , V_40 , V_46 - 10 , V_12 ) ;
return;
}
if ( V_42 == 0 ) {
F_24 ( V_41 , V_40 , V_12 ) ;
F_22 ( V_55 , V_40 , 32 , V_12 ) ;
return;
}
if ( F_29 ( ( ~ V_41 ) & 0xffffffff ,
( ~ V_42 ) & 0xfffffc00 ) ) {
unsigned long V_59 = V_42 & 0x3ff ;
if ( ( ( ( ~ V_41 ) & 0xffffffff ) == 0 &&
( ( ~ V_42 ) & 0x80000000 ) == 0 ) ||
( ( ( ~ V_41 ) & 0xffffffff ) == 0xffffffff &&
( ( ~ V_42 ) & 0x80000000 ) != 0 ) ) {
unsigned long V_60 = ( ~ V_42 & 0xffffffff ) ;
if ( ( F_4 ( V_60 ) &&
( ~ V_41 & 0xffffffff ) == 0 ) ) {
F_8 ( F_11 ( V_60 , V_40 ) , V_12 ) ;
} else if ( F_1 ( V_60 ) ) {
F_8 ( V_21 | V_27 | F_13 ( V_18 ) | F_19 ( V_60 ) | F_15 ( V_40 ) , V_12 ) ;
} else {
F_31 ( V_60 , V_40 , V_12 ) ;
}
} else {
T_3 V_61 = ( ( ~ V_42 ) & 0xfffffc00 ) |
( ( ( unsigned long ) ( ( ~ V_41 ) & 0xffffffff ) ) << 32 ) ;
F_31 ( V_61 , V_40 , V_12 ) ;
}
V_42 = - 0x400 | V_59 ;
F_8 ( V_26 | V_27 | F_13 ( V_40 ) | F_19 ( V_42 ) | F_15 ( V_40 ) , V_12 ) ;
return;
}
if ( ( V_47 - V_46 ) < 32 ) {
unsigned long V_58 =
F_28 ( V_41 , V_42 ,
V_46 , 0 ) ;
F_30 ( V_58 , 0 , V_40 ,
V_46 , V_12 ) ;
return;
}
if ( F_1 ( V_42 ) && ( ( int ) V_42 > 0 ) ) {
F_30 ( V_41 , V_42 ,
V_40 , 32 , V_12 ) ;
return;
}
V_12 -> V_39 = true ;
F_24 ( V_41 , V_36 , V_12 ) ;
F_24 ( V_42 , V_40 , V_12 ) ;
F_22 ( V_55 , V_36 , 32 , V_12 ) ;
F_8 ( V_21 | F_13 ( V_40 ) | F_14 ( V_36 ) | F_15 ( V_40 ) , V_12 ) ;
}
static void F_32 ( unsigned int V_62 , unsigned int V_63 , unsigned int V_64 ,
struct V_11 * V_12 )
{
unsigned int V_8 = V_64 - V_63 ;
if ( V_62 & V_65 )
F_8 ( V_62 | F_33 ( V_8 << 2 ) , V_12 ) ;
else
F_8 ( V_62 | F_34 ( V_8 << 2 ) , V_12 ) ;
}
static void F_35 ( unsigned int V_66 , unsigned int V_63 , unsigned int V_64 ,
const T_4 V_30 , const T_4 V_29 , struct V_11 * V_12 )
{
unsigned int V_8 = V_64 - V_63 ;
F_8 ( V_66 | F_7 ( V_8 << 2 ) | F_13 ( V_30 ) | F_14 ( V_29 ) , V_12 ) ;
}
static void F_36 ( unsigned int V_66 , unsigned int V_63 , unsigned int V_64 ,
const T_4 V_30 , T_2 V_34 , struct V_11 * V_12 )
{
unsigned int V_8 = V_64 - V_63 ;
F_8 ( V_66 | V_27 | F_7 ( V_8 << 2 ) | F_13 ( V_30 ) | F_37 ( V_34 ) , V_12 ) ;
}
static int F_38 ( const T_4 V_67 , const T_4 V_30 , T_4 V_29 ,
const T_2 V_34 , bool V_68 , int V_69 ,
struct V_11 * V_12 )
{
bool V_70 = ( V_71 & V_72 ) != 0 ;
const T_4 V_36 = V_37 [ V_38 ] ;
V_69 = V_12 -> V_73 [ V_69 ] ;
if ( ! F_2 ( V_69 - V_12 -> V_14 ) ||
F_39 ( V_67 ) == V_74 )
V_70 = false ;
if ( V_68 ) {
bool V_75 = true ;
if ( V_70 ) {
if ( ! F_3 ( V_34 ) )
V_75 = false ;
} else if ( ! F_1 ( V_34 ) ) {
V_75 = false ;
}
if ( ! V_75 ) {
V_12 -> V_39 = true ;
F_26 ( V_34 , V_36 , V_12 ) ;
V_29 = V_36 ;
V_68 = false ;
}
}
if ( ! V_70 ) {
T_1 V_76 ;
if ( F_39 ( V_67 ) == V_74 ) {
if ( V_68 )
F_40 ( V_30 , V_34 , V_12 ) ;
else
F_41 ( V_30 , V_29 , V_12 ) ;
} else {
if ( V_68 )
F_42 ( V_30 , V_34 , V_12 ) ;
else
F_43 ( V_30 , V_29 , V_12 ) ;
}
switch ( F_39 ( V_67 ) ) {
case V_77 :
V_76 = V_78 ;
break;
case V_79 :
V_76 = V_80 ;
break;
case V_81 :
V_76 = V_82 ;
break;
case V_83 :
V_76 = V_84 ;
break;
case V_85 :
V_76 = V_86 ;
break;
case V_74 :
case V_87 :
V_76 = V_88 ;
break;
case V_89 :
V_76 = V_90 ;
break;
case V_91 :
V_76 = V_92 ;
break;
case V_93 :
V_76 = V_94 ;
break;
case V_95 :
V_76 = V_96 ;
break;
default:
return - V_97 ;
}
F_32 ( V_76 , V_12 -> V_14 , V_69 , V_12 ) ;
F_10 ( V_12 ) ;
} else {
T_1 V_98 ;
switch ( F_39 ( V_67 ) ) {
case V_77 :
V_98 = V_99 ;
break;
case V_79 :
V_98 = V_100 ;
break;
case V_81 :
V_98 = V_101 ;
break;
case V_83 :
V_98 = V_102 ;
break;
case V_85 :
V_98 = V_103 ;
break;
case V_87 :
V_98 = V_104 ;
break;
case V_89 :
V_98 = V_105 ;
break;
case V_91 :
V_98 = V_106 ;
break;
case V_93 :
V_98 = V_107 ;
break;
case V_95 :
V_98 = V_108 ;
break;
default:
return - V_97 ;
}
V_98 |= V_109 ;
if ( V_68 )
F_36 ( V_98 , V_12 -> V_14 , V_69 ,
V_30 , V_34 , V_12 ) ;
else
F_35 ( V_98 , V_12 -> V_14 , V_69 ,
V_30 , V_29 , V_12 ) ;
}
return 0 ;
}
static void F_44 ( struct V_11 * V_12 , T_4 V_110 )
{
const T_4 V_111 = V_37 [ V_112 ] ;
const T_4 V_113 = V_37 [ V_114 ] ;
const T_4 V_115 = V_37 [ V_38 ] ;
unsigned int V_8 ;
V_8 = F_45 ( struct V_116 , V_117 ) ;
F_8 ( V_118 | F_13 ( V_110 ) | F_19 ( V_8 ) | F_15 ( V_111 ) , V_12 ) ;
V_8 = F_45 ( struct V_116 , V_119 ) ;
F_8 ( V_118 | F_13 ( V_110 ) | F_19 ( V_8 ) | F_15 ( V_115 ) , V_12 ) ;
F_8 ( V_120 | F_13 ( V_111 ) | F_14 ( V_115 ) | F_15 ( V_111 ) , V_12 ) ;
V_8 = F_45 ( struct V_116 , V_121 ) ;
F_8 ( V_122 | F_13 ( V_110 ) | F_19 ( V_8 ) | F_15 ( V_113 ) , V_12 ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
T_2 V_123 = V_124 ;
if ( V_12 -> V_125 || V_12 -> V_126 ) {
struct V_127 * V_128 = V_12 -> V_128 ;
T_1 V_129 ;
V_129 = V_128 -> V_130 -> V_129 ;
V_123 += F_47 ( V_129 , 16 ) ;
}
if ( V_12 -> V_126 )
V_123 += 8 ;
F_8 ( V_131 | V_27 | F_13 ( V_132 ) | F_19 ( - V_123 ) | F_15 ( V_132 ) , V_12 ) ;
if ( V_12 -> V_126 ) {
T_1 V_8 = V_133 ;
F_8 ( V_134 | V_27 | F_13 ( V_132 ) | F_19 ( V_8 ) | F_15 ( V_18 ) , V_12 ) ;
} else {
F_10 ( V_12 ) ;
}
if ( V_12 -> V_125 ) {
const T_4 V_135 = V_37 [ V_136 ] ;
F_8 ( V_137 | V_27 | F_13 ( V_138 ) | F_19 ( V_139 ) | F_15 ( V_135 ) , V_12 ) ;
}
F_12 ( V_140 , V_141 , V_12 ) ;
if ( V_12 -> V_142 )
F_44 ( V_12 , V_37 [ V_143 ] ) ;
}
static void F_48 ( struct V_11 * V_12 )
{
V_12 -> V_144 = V_12 -> V_14 ;
F_8 ( V_145 | V_27 | F_13 ( V_146 ) | F_19 ( 8 ) | F_15 ( V_18 ) , V_12 ) ;
F_8 ( V_147 | F_13 ( V_37 [ V_148 ] ) | F_14 ( V_18 ) | F_15 ( V_141 ) , V_12 ) ;
}
static void F_49 ( struct V_11 * V_12 )
{
const T_4 V_149 = V_37 [ V_150 ] ;
const T_4 V_151 = V_37 [ V_152 ] ;
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_8 ;
V_12 -> V_126 = true ;
V_8 = F_45 ( struct V_149 , V_153 . V_154 ) ;
F_8 ( V_155 | V_27 | F_13 ( V_149 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_43 ( V_151 , V_36 , V_12 ) ;
#define F_50 17
F_32 ( V_84 , V_12 -> V_14 , V_12 -> V_14 + F_50 , V_12 ) ;
F_10 ( V_12 ) ;
V_8 = V_133 ;
F_8 ( V_155 | V_27 | F_13 ( V_132 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_42 ( V_36 , V_156 , V_12 ) ;
#define F_51 13
F_32 ( V_80 , V_12 -> V_14 , V_12 -> V_14 + F_51 , V_12 ) ;
F_10 ( V_12 ) ;
F_22 ( V_137 , V_36 , 1 , V_12 ) ;
V_8 = V_133 ;
F_8 ( V_134 | V_27 | F_13 ( V_132 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_23 ( V_157 , V_151 , 3 , V_36 , V_12 ) ;
F_20 ( V_137 , V_149 , V_36 , V_12 ) ;
V_8 = F_45 ( struct V_149 , V_158 ) ;
F_8 ( V_159 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_42 ( V_36 , 0 , V_12 ) ;
#define F_52 5
F_32 ( V_78 , V_12 -> V_14 , V_12 -> V_14 + F_52 , V_12 ) ;
F_10 ( V_12 ) ;
V_8 = F_45 ( struct V_127 , V_160 ) ;
F_8 ( V_159 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
V_8 = V_161 ;
F_8 ( V_145 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_18 ) , V_12 ) ;
F_10 ( V_12 ) ;
}
static int F_53 ( const struct V_162 * V_10 , struct V_11 * V_12 )
{
const T_4 V_67 = V_10 -> V_67 ;
const T_4 V_30 = V_37 [ V_10 -> V_163 ] ;
const T_4 V_29 = V_37 [ V_10 -> V_164 ] ;
const int V_49 = V_10 - V_12 -> V_128 -> V_165 ;
const T_5 V_8 = V_10 -> V_8 ;
const T_2 V_34 = V_10 -> V_34 ;
T_1 * V_15 ;
if ( V_10 -> V_164 == V_136 )
V_12 -> V_125 = true ;
switch ( V_67 ) {
case V_166 | V_167 | V_168 :
F_23 ( V_169 , V_29 , 0 , V_30 , V_12 ) ;
break;
case V_170 | V_167 | V_168 :
F_12 ( V_29 , V_30 , V_12 ) ;
break;
case V_166 | V_171 | V_168 :
case V_170 | V_171 | V_168 :
F_20 ( V_137 , V_29 , V_30 , V_12 ) ;
goto V_172;
case V_166 | V_173 | V_168 :
case V_170 | V_173 | V_168 :
F_20 ( V_120 , V_29 , V_30 , V_12 ) ;
goto V_172;
case V_166 | V_174 | V_168 :
case V_170 | V_174 | V_168 :
F_20 ( V_175 , V_29 , V_30 , V_12 ) ;
goto V_172;
case V_166 | V_176 | V_168 :
case V_170 | V_176 | V_168 :
F_20 ( V_21 , V_29 , V_30 , V_12 ) ;
goto V_172;
case V_166 | V_177 | V_168 :
case V_170 | V_177 | V_168 :
F_20 ( V_26 , V_29 , V_30 , V_12 ) ;
goto V_172;
case V_166 | V_178 | V_168 :
F_20 ( V_179 , V_29 , V_30 , V_12 ) ;
goto V_172;
case V_170 | V_178 | V_168 :
F_20 ( V_180 , V_29 , V_30 , V_12 ) ;
break;
case V_166 | V_181 | V_168 :
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_182 , V_12 -> V_14 , V_12 -> V_144 , V_12 ) ;
F_25 ( 0 , V_37 [ V_148 ] , V_12 ) ;
F_54 ( V_18 , V_12 ) ;
F_20 ( DIV , V_29 , V_30 , V_12 ) ;
break;
case V_170 | V_181 | V_168 :
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_182 , V_12 -> V_14 , V_12 -> V_144 , V_12 ) ;
F_25 ( 0 , V_37 [ V_148 ] , V_12 ) ;
F_20 ( V_183 , V_29 , V_30 , V_12 ) ;
break;
case V_166 | V_184 | V_168 : {
const T_4 V_36 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_182 , V_12 -> V_14 , V_12 -> V_144 , V_12 ) ;
F_25 ( 0 , V_37 [ V_148 ] , V_12 ) ;
F_54 ( V_18 , V_12 ) ;
F_21 ( DIV , V_30 , V_29 , V_36 , V_12 ) ;
F_21 ( V_180 , V_36 , V_29 , V_36 , V_12 ) ;
F_21 ( V_120 , V_30 , V_36 , V_30 , V_12 ) ;
goto V_172;
}
case V_170 | V_184 | V_168 : {
const T_4 V_36 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_182 , V_12 -> V_14 , V_12 -> V_144 , V_12 ) ;
F_25 ( 0 , V_37 [ V_148 ] , V_12 ) ;
F_21 ( V_183 , V_30 , V_29 , V_36 , V_12 ) ;
F_21 ( V_180 , V_36 , V_29 , V_36 , V_12 ) ;
F_21 ( V_120 , V_30 , V_36 , V_30 , V_12 ) ;
break;
}
case V_166 | V_185 | V_168 :
F_20 ( V_157 , V_29 , V_30 , V_12 ) ;
goto V_172;
case V_170 | V_185 | V_168 :
F_20 ( V_55 , V_29 , V_30 , V_12 ) ;
break;
case V_166 | V_186 | V_168 :
F_20 ( V_169 , V_29 , V_30 , V_12 ) ;
break;
case V_170 | V_186 | V_168 :
F_20 ( V_57 , V_29 , V_30 , V_12 ) ;
break;
case V_166 | V_187 | V_168 :
F_20 ( V_188 , V_29 , V_30 , V_12 ) ;
goto V_172;
case V_170 | V_187 | V_168 :
F_20 ( V_189 , V_29 , V_30 , V_12 ) ;
break;
case V_166 | V_190 :
case V_170 | V_190 :
F_8 ( V_120 | F_13 ( 0 ) | F_14 ( V_30 ) | F_15 ( V_30 ) , V_12 ) ;
goto V_172;
case V_166 | V_191 | V_192 :
switch ( V_34 ) {
case 16 :
F_22 ( V_157 , V_30 , 16 , V_12 ) ;
F_22 ( V_169 , V_30 , 16 , V_12 ) ;
break;
case 32 :
F_22 ( V_169 , V_30 , 0 , V_12 ) ;
break;
case 64 :
break;
}
break;
case V_166 | V_191 | V_193 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_194 = V_37 [ V_195 ] ;
V_12 -> V_39 = true ;
switch ( V_34 ) {
case 16 :
F_23 ( V_175 , V_30 , 0xff , V_36 , V_12 ) ;
F_23 ( V_169 , V_30 , 8 , V_30 , V_12 ) ;
F_23 ( V_175 , V_30 , 0xff , V_30 , V_12 ) ;
F_23 ( V_157 , V_36 , 8 , V_36 , V_12 ) ;
F_20 ( V_21 , V_36 , V_30 , V_12 ) ;
break;
case 32 :
V_12 -> V_196 = true ;
F_23 ( V_169 , V_30 , 24 , V_36 , V_12 ) ;
F_23 ( V_169 , V_30 , 16 , V_194 , V_12 ) ;
F_23 ( V_175 , V_194 , 0xff , V_194 , V_12 ) ;
F_23 ( V_157 , V_194 , 8 , V_194 , V_12 ) ;
F_20 ( V_21 , V_194 , V_36 , V_12 ) ;
F_23 ( V_169 , V_30 , 8 , V_194 , V_12 ) ;
F_23 ( V_175 , V_194 , 0xff , V_194 , V_12 ) ;
F_23 ( V_157 , V_194 , 16 , V_194 , V_12 ) ;
F_20 ( V_21 , V_194 , V_36 , V_12 ) ;
F_23 ( V_175 , V_30 , 0xff , V_30 , V_12 ) ;
F_23 ( V_157 , V_30 , 24 , V_30 , V_12 ) ;
F_20 ( V_21 , V_36 , V_30 , V_12 ) ;
break;
case 64 :
F_23 ( V_137 , V_132 , V_139 + 128 , V_36 , V_12 ) ;
F_8 ( V_197 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_30 ) , V_12 ) ;
F_8 ( V_198 | F_55 ( V_199 ) | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_30 ) , V_12 ) ;
break;
}
break;
}
case V_166 | V_167 | V_200 :
F_24 ( V_34 , V_30 , V_12 ) ;
break;
case V_170 | V_167 | V_200 :
F_26 ( V_34 , V_30 , V_12 ) ;
break;
case V_166 | V_171 | V_200 :
case V_170 | V_171 | V_200 :
F_22 ( V_137 , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_166 | V_173 | V_200 :
case V_170 | V_173 | V_200 :
F_22 ( V_120 , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_166 | V_174 | V_200 :
case V_170 | V_174 | V_200 :
F_22 ( V_175 , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_166 | V_176 | V_200 :
case V_170 | V_176 | V_200 :
F_22 ( V_21 , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_166 | V_177 | V_200 :
case V_170 | V_177 | V_200 :
F_22 ( V_26 , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_166 | V_178 | V_200 :
F_22 ( V_179 , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_170 | V_178 | V_200 :
F_22 ( V_180 , V_30 , V_34 , V_12 ) ;
break;
case V_166 | V_181 | V_200 :
if ( V_34 == 0 )
return - V_201 ;
F_54 ( V_18 , V_12 ) ;
F_22 ( DIV , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_170 | V_181 | V_200 :
if ( V_34 == 0 )
return - V_201 ;
F_22 ( V_183 , V_30 , V_34 , V_12 ) ;
break;
case V_170 | V_184 | V_200 :
case V_166 | V_184 | V_200 : {
const T_4 V_36 = V_37 [ V_195 ] ;
unsigned int div ;
if ( V_34 == 0 )
return - V_201 ;
div = ( F_56 ( V_67 ) == V_170 ) ? V_183 : DIV ;
V_12 -> V_196 = true ;
if ( F_56 ( V_67 ) != V_170 )
F_54 ( V_18 , V_12 ) ;
if ( F_1 ( V_34 ) ) {
F_8 ( div | V_27 | F_13 ( V_30 ) | F_19 ( V_34 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_180 | V_27 | F_13 ( V_36 ) | F_19 ( V_34 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_120 | F_13 ( V_30 ) | F_14 ( V_36 ) | F_15 ( V_30 ) , V_12 ) ;
} else {
const T_4 V_202 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_18 ( V_34 , V_202 , V_12 ) ;
F_8 ( div | F_13 ( V_30 ) | F_14 ( V_202 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_180 | F_13 ( V_36 ) | F_14 ( V_202 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_120 | F_13 ( V_30 ) | F_14 ( V_36 ) | F_15 ( V_30 ) , V_12 ) ;
}
goto V_172;
}
case V_166 | V_185 | V_200 :
F_22 ( V_157 , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_170 | V_185 | V_200 :
F_22 ( V_55 , V_30 , V_34 , V_12 ) ;
break;
case V_166 | V_186 | V_200 :
F_22 ( V_169 , V_30 , V_34 , V_12 ) ;
break;
case V_170 | V_186 | V_200 :
F_22 ( V_57 , V_30 , V_34 , V_12 ) ;
break;
case V_166 | V_187 | V_200 :
F_22 ( V_188 , V_30 , V_34 , V_12 ) ;
goto V_172;
case V_170 | V_187 | V_200 :
F_22 ( V_189 , V_30 , V_34 , V_12 ) ;
break;
V_172:
if ( F_56 ( V_67 ) == V_166 )
F_22 ( V_169 , V_30 , 0 , V_12 ) ;
break;
case V_203 | V_204 :
F_32 ( V_205 , V_12 -> V_14 , V_12 -> V_73 [ V_49 + V_8 ] , V_12 ) ;
F_10 ( V_12 ) ;
break;
case V_203 | V_77 | V_168 :
case V_203 | V_79 | V_168 :
case V_203 | V_81 | V_168 :
case V_203 | V_83 | V_168 :
case V_203 | V_85 | V_168 :
case V_203 | V_87 | V_168 :
case V_203 | V_89 | V_168 :
case V_203 | V_91 | V_168 :
case V_203 | V_93 | V_168 :
case V_203 | V_95 | V_168 :
case V_203 | V_74 | V_168 : {
int V_206 ;
V_206 = F_38 ( V_67 , V_30 , V_29 , 0 , false , V_49 + V_8 , V_12 ) ;
if ( V_206 )
return V_206 ;
break;
}
case V_203 | V_77 | V_200 :
case V_203 | V_79 | V_200 :
case V_203 | V_81 | V_200 :
case V_203 | V_83 | V_200 :
case V_203 | V_85 | V_200 :
case V_203 | V_87 | V_200 :
case V_203 | V_89 | V_200 :
case V_203 | V_91 | V_200 :
case V_203 | V_93 | V_200 :
case V_203 | V_95 | V_200 :
case V_203 | V_74 | V_200 : {
int V_206 ;
V_206 = F_38 ( V_67 , V_30 , 0 , V_34 , true , V_49 + V_8 , V_12 ) ;
if ( V_206 )
return V_206 ;
break;
}
case V_203 | V_207 :
{
T_4 * V_15 = ( ( T_4 * ) V_208 ) + V_34 ;
V_12 -> V_209 = true ;
F_9 ( ( T_1 * ) V_15 , V_12 ) ;
F_10 ( V_12 ) ;
F_12 ( V_141 , V_37 [ V_148 ] , V_12 ) ;
if ( F_57 ( V_15 ) && V_12 -> V_142 )
F_44 ( V_12 , V_37 [ V_210 ] ) ;
break;
}
case V_203 | V_211 :
F_49 ( V_12 ) ;
break;
case V_203 | V_212 :
if ( V_49 == V_12 -> V_128 -> V_117 - 1 )
break;
F_32 ( V_205 , V_12 -> V_14 , V_12 -> V_144 , V_12 ) ;
F_10 ( V_12 ) ;
break;
case V_213 | V_214 | V_215 :
{
const struct V_162 V_216 = V_10 [ 1 ] ;
T_3 V_217 ;
V_217 = ( T_3 ) V_216 . V_34 << 32 | ( T_1 ) V_34 ;
F_31 ( V_217 , V_30 , V_12 ) ;
return 1 ;
}
case V_218 | V_219 | V_220 :
case V_218 | V_219 | V_221 :
case V_218 | V_219 | V_222 :
case V_218 | V_219 | V_215 : {
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_28 = 0 , V_223 ;
V_12 -> V_39 = true ;
switch ( F_58 ( V_67 ) ) {
case V_220 :
V_28 = V_155 ;
break;
case V_221 :
V_28 = V_224 ;
break;
case V_222 :
V_28 = V_225 ;
break;
case V_215 :
V_28 = V_159 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_223 = F_19 ( V_8 ) ;
} else {
F_25 ( V_8 , V_36 , V_12 ) ;
V_223 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_29 ) | V_223 | F_15 ( V_30 ) , V_12 ) ;
break;
}
case V_226 | V_219 | V_220 :
case V_226 | V_219 | V_221 :
case V_226 | V_219 | V_222 :
case V_226 | V_219 | V_215 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_194 = V_37 [ V_195 ] ;
T_1 V_28 = 0 , V_223 ;
V_12 -> V_196 = true ;
F_25 ( V_34 , V_194 , V_12 ) ;
switch ( F_58 ( V_67 ) ) {
case V_220 :
V_28 = V_134 ;
break;
case V_221 :
V_28 = V_227 ;
break;
case V_222 :
V_28 = V_228 ;
break;
case V_215 :
V_28 = V_197 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_223 = F_19 ( V_8 ) ;
} else {
V_12 -> V_39 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
V_223 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_30 ) | V_223 | F_15 ( V_194 ) , V_12 ) ;
break;
}
case V_229 | V_219 | V_220 :
case V_229 | V_219 | V_221 :
case V_229 | V_219 | V_222 :
case V_229 | V_219 | V_215 : {
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_28 = 0 , V_223 ;
switch ( F_58 ( V_67 ) ) {
case V_220 :
V_28 = V_134 ;
break;
case V_221 :
V_28 = V_227 ;
break;
case V_222 :
V_28 = V_228 ;
break;
case V_215 :
V_28 = V_197 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_223 = F_19 ( V_8 ) ;
} else {
V_12 -> V_39 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
V_223 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_30 ) | V_223 | F_15 ( V_29 ) , V_12 ) ;
break;
}
case V_229 | V_230 | V_220 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_194 = V_37 [ V_195 ] ;
const T_4 V_231 = V_37 [ V_232 ] ;
V_12 -> V_39 = true ;
V_12 -> V_196 = true ;
V_12 -> V_233 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
F_21 ( V_137 , V_30 , V_36 , V_36 , V_12 ) ;
F_8 ( V_155 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_194 ) , V_12 ) ;
F_21 ( V_137 , V_194 , V_29 , V_231 , V_12 ) ;
F_8 ( V_234 | F_55 ( V_235 ) | F_13 ( V_36 ) | F_14 ( V_194 ) | F_15 ( V_231 ) , V_12 ) ;
F_43 ( V_194 , V_231 , V_12 ) ;
F_32 ( V_88 , 4 , 0 , V_12 ) ;
F_10 ( V_12 ) ;
break;
}
case V_229 | V_230 | V_215 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_194 = V_37 [ V_195 ] ;
const T_4 V_231 = V_37 [ V_232 ] ;
V_12 -> V_39 = true ;
V_12 -> V_196 = true ;
V_12 -> V_233 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
F_21 ( V_137 , V_30 , V_36 , V_36 , V_12 ) ;
F_8 ( V_159 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_194 ) , V_12 ) ;
F_21 ( V_137 , V_194 , V_29 , V_231 , V_12 ) ;
F_8 ( V_236 | F_55 ( V_235 ) | F_13 ( V_36 ) | F_14 ( V_194 ) | F_15 ( V_231 ) , V_12 ) ;
F_43 ( V_194 , V_231 , V_12 ) ;
F_32 ( V_88 , 4 , 0 , V_12 ) ;
F_10 ( V_12 ) ;
break;
}
#define F_59 ( V_22 , V_15 ) \
((int)K < 0 ? ((int)K >= SKF_LL_OFF ? func##_negative_offset : func) : func##_positive_offset)
case V_213 | V_237 | V_220 :
V_15 = F_59 ( V_34 , V_238 ) ;
goto V_239;
case V_213 | V_237 | V_221 :
V_15 = F_59 ( V_34 , V_240 ) ;
goto V_239;
case V_213 | V_237 | V_222 :
V_15 = F_59 ( V_34 , V_241 ) ;
goto V_239;
case V_213 | V_242 | V_220 :
V_15 = V_238 ;
goto V_239;
case V_213 | V_242 | V_221 :
V_15 = V_240 ;
goto V_239;
case V_213 | V_242 | V_222 :
V_15 = V_241 ;
V_239:
V_12 -> V_142 = true ;
F_12 ( V_37 [ V_210 ] , V_141 , V_12 ) ;
F_25 ( V_34 , V_243 , V_12 ) ;
if ( F_60 ( V_67 ) == V_242 )
F_20 ( V_137 , V_29 , V_243 , V_12 ) ;
F_9 ( V_15 , V_12 ) ;
F_22 ( V_188 , V_243 , 0 , V_12 ) ;
F_12 ( V_141 , V_37 [ V_148 ] , V_12 ) ;
break;
default:
F_61 ( L_1 , V_67 ) ;
return - V_201 ;
}
return 0 ;
}
static int F_62 ( struct V_11 * V_12 )
{
const struct V_127 * V_128 = V_12 -> V_128 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_128 -> V_117 ; V_49 ++ ) {
const struct V_162 * V_10 = & V_128 -> V_165 [ V_49 ] ;
int V_9 ;
V_9 = F_53 ( V_10 , V_12 ) ;
if ( V_9 > 0 ) {
V_49 ++ ;
V_12 -> V_73 [ V_49 ] = V_12 -> V_14 ;
continue;
}
V_12 -> V_73 [ V_49 ] = V_12 -> V_14 ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static void F_63 ( void * V_244 , unsigned int V_245 )
{
T_1 * V_246 ;
for ( V_246 = V_244 ; V_245 >= sizeof( T_1 ) ; V_245 -= sizeof( T_1 ) )
* V_246 ++ = 0x91d02005 ;
}
struct V_127 * F_64 ( struct V_127 * V_128 )
{
struct V_127 * V_36 , * V_247 = V_128 ;
struct V_248 * V_249 ;
bool V_250 = false ;
struct V_11 V_12 ;
T_1 V_251 ;
T_4 * V_252 ;
int V_253 ;
if ( ! V_254 )
return V_247 ;
V_36 = F_65 ( V_128 ) ;
if ( F_66 ( V_36 ) )
return V_247 ;
if ( V_36 != V_128 ) {
V_250 = true ;
V_128 = V_36 ;
}
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_128 = V_128 ;
V_12 . V_73 = F_67 ( V_128 -> V_117 , sizeof( unsigned int ) , V_255 ) ;
if ( V_12 . V_73 == NULL ) {
V_128 = V_247 ;
goto V_256;
}
if ( F_62 ( & V_12 ) ) {
V_128 = V_247 ;
goto V_257;
}
F_46 ( & V_12 ) ;
F_48 ( & V_12 ) ;
V_251 = sizeof( T_1 ) * V_12 . V_14 ;
V_249 = F_68 ( V_251 , & V_252 ,
sizeof( T_1 ) , F_63 ) ;
if ( V_249 == NULL ) {
V_128 = V_247 ;
goto V_257;
}
V_12 . V_13 = ( T_1 * ) V_252 ;
for ( V_253 = 1 ; V_253 < 3 ; V_253 ++ ) {
V_12 . V_14 = 0 ;
F_46 ( & V_12 ) ;
if ( F_62 ( & V_12 ) ) {
F_69 ( V_249 ) ;
V_128 = V_247 ;
goto V_257;
}
F_48 ( & V_12 ) ;
if ( V_254 > 1 )
F_70 ( L_2 , V_253 ,
V_251 - ( V_12 . V_14 * 4 ) ,
V_12 . V_39 ? '1' : ' ' ,
V_12 . V_196 ? '2' : ' ' ,
V_12 . V_233 ? '3' : ' ' ,
V_12 . V_142 ? 'L' : ' ' ,
V_12 . V_125 ? 'F' : ' ' ,
V_12 . V_209 ? 'C' : ' ' ,
V_12 . V_126 ? 'T' : ' ' ) ;
}
if ( V_254 > 1 )
F_71 ( V_128 -> V_117 , V_251 , V_253 , V_12 . V_13 ) ;
F_5 ( V_249 , ( T_4 * ) V_249 + ( V_249 -> V_258 * V_259 ) ) ;
F_72 ( V_249 ) ;
V_128 -> V_160 = ( void * ) V_12 . V_13 ;
V_128 -> V_260 = 1 ;
V_128 -> V_261 = V_251 ;
V_257:
F_73 ( V_12 . V_73 ) ;
V_256:
if ( V_250 )
F_74 ( V_128 , V_128 == V_247 ?
V_36 : V_247 ) ;
return V_128 ;
}
