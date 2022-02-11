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
case V_74 :
case V_83 :
V_76 = V_84 ;
break;
case V_85 :
V_76 = V_86 ;
break;
case V_87 :
V_76 = V_88 ;
break;
default:
return - V_89 ;
}
F_32 ( V_76 , V_12 -> V_14 , V_69 , V_12 ) ;
F_10 ( V_12 ) ;
} else {
T_1 V_90 ;
switch ( F_39 ( V_67 ) ) {
case V_77 :
V_90 = V_91 ;
break;
case V_79 :
V_90 = V_92 ;
break;
case V_81 :
V_90 = V_93 ;
break;
case V_83 :
V_90 = V_94 ;
break;
case V_85 :
V_90 = V_95 ;
break;
case V_87 :
V_90 = V_96 ;
break;
default:
return - V_89 ;
}
V_90 |= V_97 ;
if ( V_68 )
F_36 ( V_90 , V_12 -> V_14 , V_69 ,
V_30 , V_34 , V_12 ) ;
else
F_35 ( V_90 , V_12 -> V_14 , V_69 ,
V_30 , V_29 , V_12 ) ;
}
return 0 ;
}
static void F_44 ( struct V_11 * V_12 , T_4 V_98 )
{
const T_4 V_99 = V_37 [ V_100 ] ;
const T_4 V_101 = V_37 [ V_102 ] ;
const T_4 V_103 = V_37 [ V_38 ] ;
unsigned int V_8 ;
V_8 = F_45 ( struct V_104 , V_105 ) ;
F_8 ( V_106 | F_13 ( V_98 ) | F_19 ( V_8 ) | F_15 ( V_99 ) , V_12 ) ;
V_8 = F_45 ( struct V_104 , V_107 ) ;
F_8 ( V_106 | F_13 ( V_98 ) | F_19 ( V_8 ) | F_15 ( V_103 ) , V_12 ) ;
F_8 ( V_108 | F_13 ( V_99 ) | F_14 ( V_103 ) | F_15 ( V_99 ) , V_12 ) ;
V_8 = F_45 ( struct V_104 , V_109 ) ;
F_8 ( V_110 | F_13 ( V_98 ) | F_19 ( V_8 ) | F_15 ( V_101 ) , V_12 ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
T_2 V_111 = V_112 ;
if ( V_12 -> V_113 || V_12 -> V_114 )
V_111 += V_115 ;
if ( V_12 -> V_114 )
V_111 += 8 ;
F_8 ( V_116 | V_27 | F_13 ( V_117 ) | F_19 ( - V_111 ) | F_15 ( V_117 ) , V_12 ) ;
if ( V_12 -> V_114 ) {
T_1 V_8 = V_118 ;
F_8 ( V_119 | V_27 | F_13 ( V_117 ) | F_19 ( V_8 ) | F_15 ( V_18 ) , V_12 ) ;
} else {
F_10 ( V_12 ) ;
}
if ( V_12 -> V_113 ) {
const T_4 V_120 = V_37 [ V_121 ] ;
F_8 ( V_122 | V_27 | F_13 ( V_123 ) | F_19 ( V_124 ) | F_15 ( V_120 ) , V_12 ) ;
}
F_12 ( V_125 , V_126 , V_12 ) ;
if ( V_12 -> V_127 )
F_44 ( V_12 , V_37 [ V_128 ] ) ;
}
static void F_47 ( struct V_11 * V_12 )
{
V_12 -> V_129 = V_12 -> V_14 ;
F_8 ( V_130 | V_27 | F_13 ( V_131 ) | F_19 ( 8 ) | F_15 ( V_18 ) , V_12 ) ;
F_8 ( V_132 | F_13 ( V_37 [ V_133 ] ) | F_14 ( V_18 ) | F_15 ( V_126 ) , V_12 ) ;
}
static void F_48 ( struct V_11 * V_12 )
{
const T_4 V_134 = V_37 [ V_135 ] ;
const T_4 V_136 = V_37 [ V_137 ] ;
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_8 ;
V_12 -> V_114 = true ;
V_8 = F_45 ( struct V_134 , V_138 . V_139 ) ;
F_8 ( V_140 | V_27 | F_13 ( V_134 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_43 ( V_136 , V_36 , V_12 ) ;
#define F_49 17
F_32 ( V_82 , V_12 -> V_14 , V_12 -> V_14 + F_49 , V_12 ) ;
F_10 ( V_12 ) ;
V_8 = V_118 ;
F_8 ( V_140 | V_27 | F_13 ( V_117 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_42 ( V_36 , V_141 , V_12 ) ;
#define F_50 13
F_32 ( V_80 , V_12 -> V_14 , V_12 -> V_14 + F_50 , V_12 ) ;
F_10 ( V_12 ) ;
F_22 ( V_122 , V_36 , 1 , V_12 ) ;
V_8 = V_118 ;
F_8 ( V_119 | V_27 | F_13 ( V_117 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_23 ( V_142 , V_136 , 3 , V_36 , V_12 ) ;
F_20 ( V_122 , V_134 , V_36 , V_12 ) ;
V_8 = F_45 ( struct V_134 , V_143 ) ;
F_8 ( V_144 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_42 ( V_36 , 0 , V_12 ) ;
#define F_51 5
F_32 ( V_78 , V_12 -> V_14 , V_12 -> V_14 + F_51 , V_12 ) ;
F_10 ( V_12 ) ;
V_8 = F_45 ( struct V_145 , V_146 ) ;
F_8 ( V_144 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
V_8 = V_147 ;
F_8 ( V_130 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_18 ) , V_12 ) ;
F_10 ( V_12 ) ;
}
static int F_52 ( const struct V_148 * V_10 , struct V_11 * V_12 )
{
const T_4 V_67 = V_10 -> V_67 ;
const T_4 V_30 = V_37 [ V_10 -> V_149 ] ;
const T_4 V_29 = V_37 [ V_10 -> V_150 ] ;
const int V_49 = V_10 - V_12 -> V_151 -> V_152 ;
const T_5 V_8 = V_10 -> V_8 ;
const T_2 V_34 = V_10 -> V_34 ;
T_1 * V_15 ;
if ( V_10 -> V_150 == V_121 )
V_12 -> V_113 = true ;
switch ( V_67 ) {
case V_153 | V_154 | V_155 :
F_23 ( V_156 , V_29 , 0 , V_30 , V_12 ) ;
break;
case V_157 | V_154 | V_155 :
F_12 ( V_29 , V_30 , V_12 ) ;
break;
case V_153 | V_158 | V_155 :
case V_157 | V_158 | V_155 :
F_20 ( V_122 , V_29 , V_30 , V_12 ) ;
goto V_159;
case V_153 | V_160 | V_155 :
case V_157 | V_160 | V_155 :
F_20 ( V_108 , V_29 , V_30 , V_12 ) ;
goto V_159;
case V_153 | V_161 | V_155 :
case V_157 | V_161 | V_155 :
F_20 ( V_162 , V_29 , V_30 , V_12 ) ;
goto V_159;
case V_153 | V_163 | V_155 :
case V_157 | V_163 | V_155 :
F_20 ( V_21 , V_29 , V_30 , V_12 ) ;
goto V_159;
case V_153 | V_164 | V_155 :
case V_157 | V_164 | V_155 :
F_20 ( V_26 , V_29 , V_30 , V_12 ) ;
goto V_159;
case V_153 | V_165 | V_155 :
F_20 ( V_166 , V_29 , V_30 , V_12 ) ;
goto V_159;
case V_157 | V_165 | V_155 :
F_20 ( V_167 , V_29 , V_30 , V_12 ) ;
break;
case V_153 | V_168 | V_155 :
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_169 , V_12 -> V_14 , V_12 -> V_129 , V_12 ) ;
F_25 ( 0 , V_37 [ V_133 ] , V_12 ) ;
F_53 ( V_18 , V_12 ) ;
F_20 ( DIV , V_29 , V_30 , V_12 ) ;
break;
case V_157 | V_168 | V_155 :
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_169 , V_12 -> V_14 , V_12 -> V_129 , V_12 ) ;
F_25 ( 0 , V_37 [ V_133 ] , V_12 ) ;
F_20 ( V_170 , V_29 , V_30 , V_12 ) ;
break;
case V_153 | V_171 | V_155 : {
const T_4 V_36 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_169 , V_12 -> V_14 , V_12 -> V_129 , V_12 ) ;
F_25 ( 0 , V_37 [ V_133 ] , V_12 ) ;
F_53 ( V_18 , V_12 ) ;
F_21 ( DIV , V_30 , V_29 , V_36 , V_12 ) ;
F_21 ( V_167 , V_36 , V_29 , V_36 , V_12 ) ;
F_21 ( V_108 , V_30 , V_36 , V_30 , V_12 ) ;
goto V_159;
}
case V_157 | V_171 | V_155 : {
const T_4 V_36 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_169 , V_12 -> V_14 , V_12 -> V_129 , V_12 ) ;
F_25 ( 0 , V_37 [ V_133 ] , V_12 ) ;
F_21 ( V_170 , V_30 , V_29 , V_36 , V_12 ) ;
F_21 ( V_167 , V_36 , V_29 , V_36 , V_12 ) ;
F_21 ( V_108 , V_30 , V_36 , V_30 , V_12 ) ;
break;
}
case V_153 | V_172 | V_155 :
F_20 ( V_142 , V_29 , V_30 , V_12 ) ;
goto V_159;
case V_157 | V_172 | V_155 :
F_20 ( V_55 , V_29 , V_30 , V_12 ) ;
break;
case V_153 | V_173 | V_155 :
F_20 ( V_156 , V_29 , V_30 , V_12 ) ;
break;
case V_157 | V_173 | V_155 :
F_20 ( V_57 , V_29 , V_30 , V_12 ) ;
break;
case V_153 | V_174 | V_155 :
F_20 ( V_175 , V_29 , V_30 , V_12 ) ;
goto V_159;
case V_157 | V_174 | V_155 :
F_20 ( V_176 , V_29 , V_30 , V_12 ) ;
break;
case V_153 | V_177 :
case V_157 | V_177 :
F_8 ( V_108 | F_13 ( 0 ) | F_14 ( V_30 ) | F_15 ( V_30 ) , V_12 ) ;
goto V_159;
case V_153 | V_178 | V_179 :
switch ( V_34 ) {
case 16 :
F_22 ( V_142 , V_30 , 16 , V_12 ) ;
F_22 ( V_156 , V_30 , 16 , V_12 ) ;
break;
case 32 :
F_22 ( V_156 , V_30 , 0 , V_12 ) ;
break;
case 64 :
break;
}
break;
case V_153 | V_178 | V_180 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_181 = V_37 [ V_182 ] ;
V_12 -> V_39 = true ;
switch ( V_34 ) {
case 16 :
F_23 ( V_162 , V_30 , 0xff , V_36 , V_12 ) ;
F_23 ( V_156 , V_30 , 8 , V_30 , V_12 ) ;
F_23 ( V_162 , V_30 , 0xff , V_30 , V_12 ) ;
F_23 ( V_142 , V_36 , 8 , V_36 , V_12 ) ;
F_20 ( V_21 , V_36 , V_30 , V_12 ) ;
break;
case 32 :
V_12 -> V_183 = true ;
F_23 ( V_156 , V_30 , 24 , V_36 , V_12 ) ;
F_23 ( V_156 , V_30 , 16 , V_181 , V_12 ) ;
F_23 ( V_162 , V_181 , 0xff , V_181 , V_12 ) ;
F_23 ( V_142 , V_181 , 8 , V_181 , V_12 ) ;
F_20 ( V_21 , V_181 , V_36 , V_12 ) ;
F_23 ( V_156 , V_30 , 8 , V_181 , V_12 ) ;
F_23 ( V_162 , V_181 , 0xff , V_181 , V_12 ) ;
F_23 ( V_142 , V_181 , 16 , V_181 , V_12 ) ;
F_20 ( V_21 , V_181 , V_36 , V_12 ) ;
F_23 ( V_162 , V_30 , 0xff , V_30 , V_12 ) ;
F_23 ( V_142 , V_30 , 24 , V_30 , V_12 ) ;
F_20 ( V_21 , V_36 , V_30 , V_12 ) ;
break;
case 64 :
F_23 ( V_122 , V_117 , V_124 + 128 , V_36 , V_12 ) ;
F_8 ( V_184 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_30 ) , V_12 ) ;
F_8 ( V_185 | F_54 ( V_186 ) | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_30 ) , V_12 ) ;
break;
}
break;
}
case V_153 | V_154 | V_187 :
F_24 ( V_34 , V_30 , V_12 ) ;
break;
case V_157 | V_154 | V_187 :
F_26 ( V_34 , V_30 , V_12 ) ;
break;
case V_153 | V_158 | V_187 :
case V_157 | V_158 | V_187 :
F_22 ( V_122 , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_153 | V_160 | V_187 :
case V_157 | V_160 | V_187 :
F_22 ( V_108 , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_153 | V_161 | V_187 :
case V_157 | V_161 | V_187 :
F_22 ( V_162 , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_153 | V_163 | V_187 :
case V_157 | V_163 | V_187 :
F_22 ( V_21 , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_153 | V_164 | V_187 :
case V_157 | V_164 | V_187 :
F_22 ( V_26 , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_153 | V_165 | V_187 :
F_22 ( V_166 , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_157 | V_165 | V_187 :
F_22 ( V_167 , V_30 , V_34 , V_12 ) ;
break;
case V_153 | V_168 | V_187 :
if ( V_34 == 0 )
return - V_188 ;
F_53 ( V_18 , V_12 ) ;
F_22 ( DIV , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_157 | V_168 | V_187 :
if ( V_34 == 0 )
return - V_188 ;
F_22 ( V_170 , V_30 , V_34 , V_12 ) ;
break;
case V_157 | V_171 | V_187 :
case V_153 | V_171 | V_187 : {
const T_4 V_36 = V_37 [ V_182 ] ;
unsigned int div ;
if ( V_34 == 0 )
return - V_188 ;
div = ( F_55 ( V_67 ) == V_157 ) ? V_170 : DIV ;
V_12 -> V_183 = true ;
if ( F_55 ( V_67 ) != V_157 )
F_53 ( V_18 , V_12 ) ;
if ( F_1 ( V_34 ) ) {
F_8 ( div | V_27 | F_13 ( V_30 ) | F_19 ( V_34 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_167 | V_27 | F_13 ( V_36 ) | F_19 ( V_34 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_108 | F_13 ( V_30 ) | F_14 ( V_36 ) | F_15 ( V_30 ) , V_12 ) ;
} else {
const T_4 V_189 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_18 ( V_34 , V_189 , V_12 ) ;
F_8 ( div | F_13 ( V_30 ) | F_14 ( V_189 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_167 | F_13 ( V_36 ) | F_14 ( V_189 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_108 | F_13 ( V_30 ) | F_14 ( V_36 ) | F_15 ( V_30 ) , V_12 ) ;
}
goto V_159;
}
case V_153 | V_172 | V_187 :
F_22 ( V_142 , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_157 | V_172 | V_187 :
F_22 ( V_55 , V_30 , V_34 , V_12 ) ;
break;
case V_153 | V_173 | V_187 :
F_22 ( V_156 , V_30 , V_34 , V_12 ) ;
break;
case V_157 | V_173 | V_187 :
F_22 ( V_57 , V_30 , V_34 , V_12 ) ;
break;
case V_153 | V_174 | V_187 :
F_22 ( V_175 , V_30 , V_34 , V_12 ) ;
goto V_159;
case V_157 | V_174 | V_187 :
F_22 ( V_176 , V_30 , V_34 , V_12 ) ;
break;
V_159:
if ( F_55 ( V_67 ) == V_153 )
F_22 ( V_156 , V_30 , 0 , V_12 ) ;
break;
case V_190 | V_191 :
F_32 ( V_192 , V_12 -> V_14 , V_12 -> V_73 [ V_49 + V_8 ] , V_12 ) ;
F_10 ( V_12 ) ;
break;
case V_190 | V_77 | V_155 :
case V_190 | V_79 | V_155 :
case V_190 | V_81 | V_155 :
case V_190 | V_83 | V_155 :
case V_190 | V_85 | V_155 :
case V_190 | V_87 | V_155 :
case V_190 | V_74 | V_155 : {
int V_193 ;
V_193 = F_38 ( V_67 , V_30 , V_29 , 0 , false , V_49 + V_8 , V_12 ) ;
if ( V_193 )
return V_193 ;
break;
}
case V_190 | V_77 | V_187 :
case V_190 | V_79 | V_187 :
case V_190 | V_81 | V_187 :
case V_190 | V_83 | V_187 :
case V_190 | V_85 | V_187 :
case V_190 | V_87 | V_187 :
case V_190 | V_74 | V_187 : {
int V_193 ;
V_193 = F_38 ( V_67 , V_30 , 0 , V_34 , true , V_49 + V_8 , V_12 ) ;
if ( V_193 )
return V_193 ;
break;
}
case V_190 | V_194 :
{
T_4 * V_15 = ( ( T_4 * ) V_195 ) + V_34 ;
V_12 -> V_196 = true ;
F_9 ( ( T_1 * ) V_15 , V_12 ) ;
F_10 ( V_12 ) ;
F_12 ( V_126 , V_37 [ V_133 ] , V_12 ) ;
if ( F_56 ( V_15 ) && V_12 -> V_127 )
F_44 ( V_12 , V_37 [ V_197 ] ) ;
break;
}
case V_190 | V_194 | V_155 :
F_48 ( V_12 ) ;
break;
case V_190 | V_198 :
if ( V_49 == V_12 -> V_151 -> V_105 - 1 )
break;
F_32 ( V_192 , V_12 -> V_14 , V_12 -> V_129 , V_12 ) ;
F_10 ( V_12 ) ;
break;
case V_199 | V_200 | V_201 :
{
const struct V_148 V_202 = V_10 [ 1 ] ;
T_3 V_203 ;
V_203 = ( T_3 ) V_202 . V_34 << 32 | ( T_1 ) V_34 ;
F_31 ( V_203 , V_30 , V_12 ) ;
return 1 ;
}
case V_204 | V_205 | V_206 :
case V_204 | V_205 | V_207 :
case V_204 | V_205 | V_208 :
case V_204 | V_205 | V_201 : {
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_28 = 0 , V_209 ;
V_12 -> V_39 = true ;
switch ( F_57 ( V_67 ) ) {
case V_206 :
V_28 = V_140 ;
break;
case V_207 :
V_28 = V_210 ;
break;
case V_208 :
V_28 = V_211 ;
break;
case V_201 :
V_28 = V_144 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_209 = F_19 ( V_8 ) ;
} else {
F_25 ( V_8 , V_36 , V_12 ) ;
V_209 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_29 ) | V_209 | F_15 ( V_30 ) , V_12 ) ;
break;
}
case V_212 | V_205 | V_206 :
case V_212 | V_205 | V_207 :
case V_212 | V_205 | V_208 :
case V_212 | V_205 | V_201 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_181 = V_37 [ V_182 ] ;
T_1 V_28 = 0 , V_209 ;
V_12 -> V_183 = true ;
F_25 ( V_34 , V_181 , V_12 ) ;
switch ( F_57 ( V_67 ) ) {
case V_206 :
V_28 = V_119 ;
break;
case V_207 :
V_28 = V_213 ;
break;
case V_208 :
V_28 = V_214 ;
break;
case V_201 :
V_28 = V_184 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_209 = F_19 ( V_8 ) ;
} else {
V_12 -> V_39 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
V_209 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_30 ) | V_209 | F_15 ( V_181 ) , V_12 ) ;
break;
}
case V_215 | V_205 | V_206 :
case V_215 | V_205 | V_207 :
case V_215 | V_205 | V_208 :
case V_215 | V_205 | V_201 : {
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_28 = 0 , V_209 ;
switch ( F_57 ( V_67 ) ) {
case V_206 :
V_28 = V_119 ;
break;
case V_207 :
V_28 = V_213 ;
break;
case V_208 :
V_28 = V_214 ;
break;
case V_201 :
V_28 = V_184 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_209 = F_19 ( V_8 ) ;
} else {
V_12 -> V_39 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
V_209 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_30 ) | V_209 | F_15 ( V_29 ) , V_12 ) ;
break;
}
case V_215 | V_216 | V_206 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_181 = V_37 [ V_182 ] ;
const T_4 V_217 = V_37 [ V_218 ] ;
V_12 -> V_39 = true ;
V_12 -> V_183 = true ;
V_12 -> V_219 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
F_21 ( V_122 , V_30 , V_36 , V_36 , V_12 ) ;
F_8 ( V_140 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_181 ) , V_12 ) ;
F_21 ( V_122 , V_181 , V_29 , V_217 , V_12 ) ;
F_8 ( V_220 | F_54 ( V_221 ) | F_13 ( V_36 ) | F_14 ( V_181 ) | F_15 ( V_217 ) , V_12 ) ;
F_43 ( V_181 , V_217 , V_12 ) ;
F_32 ( V_84 , 4 , 0 , V_12 ) ;
F_10 ( V_12 ) ;
break;
}
case V_215 | V_216 | V_201 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_181 = V_37 [ V_182 ] ;
const T_4 V_217 = V_37 [ V_218 ] ;
V_12 -> V_39 = true ;
V_12 -> V_183 = true ;
V_12 -> V_219 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
F_21 ( V_122 , V_30 , V_36 , V_36 , V_12 ) ;
F_8 ( V_144 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_181 ) , V_12 ) ;
F_21 ( V_122 , V_181 , V_29 , V_217 , V_12 ) ;
F_8 ( V_222 | F_54 ( V_221 ) | F_13 ( V_36 ) | F_14 ( V_181 ) | F_15 ( V_217 ) , V_12 ) ;
F_43 ( V_181 , V_217 , V_12 ) ;
F_32 ( V_84 , 4 , 0 , V_12 ) ;
F_10 ( V_12 ) ;
break;
}
#define F_58 ( V_22 , V_15 ) \
((int)K < 0 ? ((int)K >= SKF_LL_OFF ? func##_negative_offset : func) : func##_positive_offset)
case V_199 | V_223 | V_206 :
V_15 = F_58 ( V_34 , V_224 ) ;
goto V_225;
case V_199 | V_223 | V_207 :
V_15 = F_58 ( V_34 , V_226 ) ;
goto V_225;
case V_199 | V_223 | V_208 :
V_15 = F_58 ( V_34 , V_227 ) ;
goto V_225;
case V_199 | V_228 | V_206 :
V_15 = V_224 ;
goto V_225;
case V_199 | V_228 | V_207 :
V_15 = V_226 ;
goto V_225;
case V_199 | V_228 | V_208 :
V_15 = V_227 ;
V_225:
V_12 -> V_127 = true ;
F_12 ( V_37 [ V_197 ] , V_126 , V_12 ) ;
F_25 ( V_34 , V_229 , V_12 ) ;
if ( F_59 ( V_67 ) == V_228 )
F_20 ( V_122 , V_29 , V_229 , V_12 ) ;
F_9 ( V_15 , V_12 ) ;
F_22 ( V_175 , V_229 , 0 , V_12 ) ;
F_12 ( V_126 , V_37 [ V_133 ] , V_12 ) ;
break;
default:
F_60 ( L_1 , V_67 ) ;
return - V_188 ;
}
return 0 ;
}
static int F_61 ( struct V_11 * V_12 )
{
const struct V_145 * V_151 = V_12 -> V_151 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_151 -> V_105 ; V_49 ++ ) {
const struct V_148 * V_10 = & V_151 -> V_152 [ V_49 ] ;
int V_9 ;
V_9 = F_52 ( V_10 , V_12 ) ;
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
static void F_62 ( void * V_230 , unsigned int V_231 )
{
T_1 * V_232 ;
for ( V_232 = V_230 ; V_231 >= sizeof( T_1 ) ; V_231 -= sizeof( T_1 ) )
* V_232 ++ = 0x91d02005 ;
}
struct V_145 * F_63 ( struct V_145 * V_151 )
{
struct V_145 * V_36 , * V_233 = V_151 ;
struct V_234 * V_235 ;
bool V_236 = false ;
struct V_11 V_12 ;
T_1 V_237 ;
T_4 * V_238 ;
int V_239 ;
if ( ! V_240 )
return V_233 ;
V_36 = F_64 ( V_151 ) ;
if ( F_65 ( V_36 ) )
return V_233 ;
if ( V_36 != V_151 ) {
V_236 = true ;
V_151 = V_36 ;
}
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_151 = V_151 ;
V_12 . V_73 = F_66 ( V_151 -> V_105 , sizeof( unsigned int ) , V_241 ) ;
if ( V_12 . V_73 == NULL ) {
V_151 = V_233 ;
goto V_242;
}
if ( F_61 ( & V_12 ) ) {
V_151 = V_233 ;
goto V_243;
}
F_46 ( & V_12 ) ;
F_47 ( & V_12 ) ;
V_237 = sizeof( T_1 ) * V_12 . V_14 ;
V_235 = F_67 ( V_237 , & V_238 ,
sizeof( T_1 ) , F_62 ) ;
if ( V_235 == NULL ) {
V_151 = V_233 ;
goto V_243;
}
V_12 . V_13 = ( T_1 * ) V_238 ;
for ( V_239 = 1 ; V_239 < 3 ; V_239 ++ ) {
V_12 . V_14 = 0 ;
F_46 ( & V_12 ) ;
if ( F_61 ( & V_12 ) ) {
F_68 ( V_235 ) ;
V_151 = V_233 ;
goto V_243;
}
F_47 ( & V_12 ) ;
if ( V_240 > 1 )
F_69 ( L_2 , V_239 ,
V_237 - ( V_12 . V_14 * 4 ) ,
V_12 . V_39 ? '1' : ' ' ,
V_12 . V_183 ? '2' : ' ' ,
V_12 . V_219 ? '3' : ' ' ,
V_12 . V_127 ? 'L' : ' ' ,
V_12 . V_113 ? 'F' : ' ' ,
V_12 . V_196 ? 'C' : ' ' ,
V_12 . V_114 ? 'T' : ' ' ) ;
}
if ( V_240 > 1 )
F_70 ( V_151 -> V_105 , V_237 , V_239 , V_12 . V_13 ) ;
F_5 ( V_235 , ( T_4 * ) V_235 + ( V_235 -> V_244 * V_245 ) ) ;
F_71 ( V_235 ) ;
V_151 -> V_146 = ( void * ) V_12 . V_13 ;
V_151 -> V_246 = 1 ;
V_243:
F_72 ( V_12 . V_73 ) ;
V_242:
if ( V_236 )
F_73 ( V_151 , V_151 == V_233 ?
V_36 : V_233 ) ;
return V_151 ;
}
