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
if ( V_12 -> V_113 || V_12 -> V_114 ) {
struct V_115 * V_116 = V_12 -> V_116 ;
T_1 V_117 ;
V_117 = V_116 -> V_118 -> V_117 ;
V_111 += F_47 ( V_117 , 16 ) ;
}
if ( V_12 -> V_114 )
V_111 += 8 ;
F_8 ( V_119 | V_27 | F_13 ( V_120 ) | F_19 ( - V_111 ) | F_15 ( V_120 ) , V_12 ) ;
if ( V_12 -> V_114 ) {
T_1 V_8 = V_121 ;
F_8 ( V_122 | V_27 | F_13 ( V_120 ) | F_19 ( V_8 ) | F_15 ( V_18 ) , V_12 ) ;
} else {
F_10 ( V_12 ) ;
}
if ( V_12 -> V_113 ) {
const T_4 V_123 = V_37 [ V_124 ] ;
F_8 ( V_125 | V_27 | F_13 ( V_126 ) | F_19 ( V_127 ) | F_15 ( V_123 ) , V_12 ) ;
}
F_12 ( V_128 , V_129 , V_12 ) ;
if ( V_12 -> V_130 )
F_44 ( V_12 , V_37 [ V_131 ] ) ;
}
static void F_48 ( struct V_11 * V_12 )
{
V_12 -> V_132 = V_12 -> V_14 ;
F_8 ( V_133 | V_27 | F_13 ( V_134 ) | F_19 ( 8 ) | F_15 ( V_18 ) , V_12 ) ;
F_8 ( V_135 | F_13 ( V_37 [ V_136 ] ) | F_14 ( V_18 ) | F_15 ( V_129 ) , V_12 ) ;
}
static void F_49 ( struct V_11 * V_12 )
{
const T_4 V_137 = V_37 [ V_138 ] ;
const T_4 V_139 = V_37 [ V_140 ] ;
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_8 ;
V_12 -> V_114 = true ;
V_8 = F_45 ( struct V_137 , V_141 . V_142 ) ;
F_8 ( V_143 | V_27 | F_13 ( V_137 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_43 ( V_139 , V_36 , V_12 ) ;
#define F_50 17
F_32 ( V_82 , V_12 -> V_14 , V_12 -> V_14 + F_50 , V_12 ) ;
F_10 ( V_12 ) ;
V_8 = V_121 ;
F_8 ( V_143 | V_27 | F_13 ( V_120 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_42 ( V_36 , V_144 , V_12 ) ;
#define F_51 13
F_32 ( V_80 , V_12 -> V_14 , V_12 -> V_14 + F_51 , V_12 ) ;
F_10 ( V_12 ) ;
F_22 ( V_125 , V_36 , 1 , V_12 ) ;
V_8 = V_121 ;
F_8 ( V_122 | V_27 | F_13 ( V_120 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_23 ( V_145 , V_139 , 3 , V_36 , V_12 ) ;
F_20 ( V_125 , V_137 , V_36 , V_12 ) ;
V_8 = F_45 ( struct V_137 , V_146 ) ;
F_8 ( V_147 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
F_42 ( V_36 , 0 , V_12 ) ;
#define F_52 5
F_32 ( V_78 , V_12 -> V_14 , V_12 -> V_14 + F_52 , V_12 ) ;
F_10 ( V_12 ) ;
V_8 = F_45 ( struct V_115 , V_148 ) ;
F_8 ( V_147 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_36 ) , V_12 ) ;
V_8 = V_149 ;
F_8 ( V_133 | V_27 | F_13 ( V_36 ) | F_19 ( V_8 ) | F_15 ( V_18 ) , V_12 ) ;
F_10 ( V_12 ) ;
}
static int F_53 ( const struct V_150 * V_10 , struct V_11 * V_12 )
{
const T_4 V_67 = V_10 -> V_67 ;
const T_4 V_30 = V_37 [ V_10 -> V_151 ] ;
const T_4 V_29 = V_37 [ V_10 -> V_152 ] ;
const int V_49 = V_10 - V_12 -> V_116 -> V_153 ;
const T_5 V_8 = V_10 -> V_8 ;
const T_2 V_34 = V_10 -> V_34 ;
T_1 * V_15 ;
if ( V_10 -> V_152 == V_124 )
V_12 -> V_113 = true ;
switch ( V_67 ) {
case V_154 | V_155 | V_156 :
F_23 ( V_157 , V_29 , 0 , V_30 , V_12 ) ;
break;
case V_158 | V_155 | V_156 :
F_12 ( V_29 , V_30 , V_12 ) ;
break;
case V_154 | V_159 | V_156 :
case V_158 | V_159 | V_156 :
F_20 ( V_125 , V_29 , V_30 , V_12 ) ;
goto V_160;
case V_154 | V_161 | V_156 :
case V_158 | V_161 | V_156 :
F_20 ( V_108 , V_29 , V_30 , V_12 ) ;
goto V_160;
case V_154 | V_162 | V_156 :
case V_158 | V_162 | V_156 :
F_20 ( V_163 , V_29 , V_30 , V_12 ) ;
goto V_160;
case V_154 | V_164 | V_156 :
case V_158 | V_164 | V_156 :
F_20 ( V_21 , V_29 , V_30 , V_12 ) ;
goto V_160;
case V_154 | V_165 | V_156 :
case V_158 | V_165 | V_156 :
F_20 ( V_26 , V_29 , V_30 , V_12 ) ;
goto V_160;
case V_154 | V_166 | V_156 :
F_20 ( V_167 , V_29 , V_30 , V_12 ) ;
goto V_160;
case V_158 | V_166 | V_156 :
F_20 ( V_168 , V_29 , V_30 , V_12 ) ;
break;
case V_154 | V_169 | V_156 :
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_170 , V_12 -> V_14 , V_12 -> V_132 , V_12 ) ;
F_25 ( 0 , V_37 [ V_136 ] , V_12 ) ;
F_54 ( V_18 , V_12 ) ;
F_20 ( DIV , V_29 , V_30 , V_12 ) ;
break;
case V_158 | V_169 | V_156 :
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_170 , V_12 -> V_14 , V_12 -> V_132 , V_12 ) ;
F_25 ( 0 , V_37 [ V_136 ] , V_12 ) ;
F_20 ( V_171 , V_29 , V_30 , V_12 ) ;
break;
case V_154 | V_172 | V_156 : {
const T_4 V_36 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_170 , V_12 -> V_14 , V_12 -> V_132 , V_12 ) ;
F_25 ( 0 , V_37 [ V_136 ] , V_12 ) ;
F_54 ( V_18 , V_12 ) ;
F_21 ( DIV , V_30 , V_29 , V_36 , V_12 ) ;
F_21 ( V_168 , V_36 , V_29 , V_36 , V_12 ) ;
F_21 ( V_108 , V_30 , V_36 , V_30 , V_12 ) ;
goto V_160;
}
case V_158 | V_172 | V_156 : {
const T_4 V_36 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_43 ( V_29 , V_18 , V_12 ) ;
F_32 ( V_78 | V_170 , V_12 -> V_14 , V_12 -> V_132 , V_12 ) ;
F_25 ( 0 , V_37 [ V_136 ] , V_12 ) ;
F_21 ( V_171 , V_30 , V_29 , V_36 , V_12 ) ;
F_21 ( V_168 , V_36 , V_29 , V_36 , V_12 ) ;
F_21 ( V_108 , V_30 , V_36 , V_30 , V_12 ) ;
break;
}
case V_154 | V_173 | V_156 :
F_20 ( V_145 , V_29 , V_30 , V_12 ) ;
goto V_160;
case V_158 | V_173 | V_156 :
F_20 ( V_55 , V_29 , V_30 , V_12 ) ;
break;
case V_154 | V_174 | V_156 :
F_20 ( V_157 , V_29 , V_30 , V_12 ) ;
break;
case V_158 | V_174 | V_156 :
F_20 ( V_57 , V_29 , V_30 , V_12 ) ;
break;
case V_154 | V_175 | V_156 :
F_20 ( V_176 , V_29 , V_30 , V_12 ) ;
goto V_160;
case V_158 | V_175 | V_156 :
F_20 ( V_177 , V_29 , V_30 , V_12 ) ;
break;
case V_154 | V_178 :
case V_158 | V_178 :
F_8 ( V_108 | F_13 ( 0 ) | F_14 ( V_30 ) | F_15 ( V_30 ) , V_12 ) ;
goto V_160;
case V_154 | V_179 | V_180 :
switch ( V_34 ) {
case 16 :
F_22 ( V_145 , V_30 , 16 , V_12 ) ;
F_22 ( V_157 , V_30 , 16 , V_12 ) ;
break;
case 32 :
F_22 ( V_157 , V_30 , 0 , V_12 ) ;
break;
case 64 :
break;
}
break;
case V_154 | V_179 | V_181 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_182 = V_37 [ V_183 ] ;
V_12 -> V_39 = true ;
switch ( V_34 ) {
case 16 :
F_23 ( V_163 , V_30 , 0xff , V_36 , V_12 ) ;
F_23 ( V_157 , V_30 , 8 , V_30 , V_12 ) ;
F_23 ( V_163 , V_30 , 0xff , V_30 , V_12 ) ;
F_23 ( V_145 , V_36 , 8 , V_36 , V_12 ) ;
F_20 ( V_21 , V_36 , V_30 , V_12 ) ;
break;
case 32 :
V_12 -> V_184 = true ;
F_23 ( V_157 , V_30 , 24 , V_36 , V_12 ) ;
F_23 ( V_157 , V_30 , 16 , V_182 , V_12 ) ;
F_23 ( V_163 , V_182 , 0xff , V_182 , V_12 ) ;
F_23 ( V_145 , V_182 , 8 , V_182 , V_12 ) ;
F_20 ( V_21 , V_182 , V_36 , V_12 ) ;
F_23 ( V_157 , V_30 , 8 , V_182 , V_12 ) ;
F_23 ( V_163 , V_182 , 0xff , V_182 , V_12 ) ;
F_23 ( V_145 , V_182 , 16 , V_182 , V_12 ) ;
F_20 ( V_21 , V_182 , V_36 , V_12 ) ;
F_23 ( V_163 , V_30 , 0xff , V_30 , V_12 ) ;
F_23 ( V_145 , V_30 , 24 , V_30 , V_12 ) ;
F_20 ( V_21 , V_36 , V_30 , V_12 ) ;
break;
case 64 :
F_23 ( V_125 , V_120 , V_127 + 128 , V_36 , V_12 ) ;
F_8 ( V_185 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_30 ) , V_12 ) ;
F_8 ( V_186 | F_55 ( V_187 ) | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_30 ) , V_12 ) ;
break;
}
break;
}
case V_154 | V_155 | V_188 :
F_24 ( V_34 , V_30 , V_12 ) ;
break;
case V_158 | V_155 | V_188 :
F_26 ( V_34 , V_30 , V_12 ) ;
break;
case V_154 | V_159 | V_188 :
case V_158 | V_159 | V_188 :
F_22 ( V_125 , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_154 | V_161 | V_188 :
case V_158 | V_161 | V_188 :
F_22 ( V_108 , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_154 | V_162 | V_188 :
case V_158 | V_162 | V_188 :
F_22 ( V_163 , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_154 | V_164 | V_188 :
case V_158 | V_164 | V_188 :
F_22 ( V_21 , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_154 | V_165 | V_188 :
case V_158 | V_165 | V_188 :
F_22 ( V_26 , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_154 | V_166 | V_188 :
F_22 ( V_167 , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_158 | V_166 | V_188 :
F_22 ( V_168 , V_30 , V_34 , V_12 ) ;
break;
case V_154 | V_169 | V_188 :
if ( V_34 == 0 )
return - V_189 ;
F_54 ( V_18 , V_12 ) ;
F_22 ( DIV , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_158 | V_169 | V_188 :
if ( V_34 == 0 )
return - V_189 ;
F_22 ( V_171 , V_30 , V_34 , V_12 ) ;
break;
case V_158 | V_172 | V_188 :
case V_154 | V_172 | V_188 : {
const T_4 V_36 = V_37 [ V_183 ] ;
unsigned int div ;
if ( V_34 == 0 )
return - V_189 ;
div = ( F_56 ( V_67 ) == V_158 ) ? V_171 : DIV ;
V_12 -> V_184 = true ;
if ( F_56 ( V_67 ) != V_158 )
F_54 ( V_18 , V_12 ) ;
if ( F_1 ( V_34 ) ) {
F_8 ( div | V_27 | F_13 ( V_30 ) | F_19 ( V_34 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_168 | V_27 | F_13 ( V_36 ) | F_19 ( V_34 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_108 | F_13 ( V_30 ) | F_14 ( V_36 ) | F_15 ( V_30 ) , V_12 ) ;
} else {
const T_4 V_190 = V_37 [ V_38 ] ;
V_12 -> V_39 = true ;
F_18 ( V_34 , V_190 , V_12 ) ;
F_8 ( div | F_13 ( V_30 ) | F_14 ( V_190 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_168 | F_13 ( V_36 ) | F_14 ( V_190 ) | F_15 ( V_36 ) , V_12 ) ;
F_8 ( V_108 | F_13 ( V_30 ) | F_14 ( V_36 ) | F_15 ( V_30 ) , V_12 ) ;
}
goto V_160;
}
case V_154 | V_173 | V_188 :
F_22 ( V_145 , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_158 | V_173 | V_188 :
F_22 ( V_55 , V_30 , V_34 , V_12 ) ;
break;
case V_154 | V_174 | V_188 :
F_22 ( V_157 , V_30 , V_34 , V_12 ) ;
break;
case V_158 | V_174 | V_188 :
F_22 ( V_57 , V_30 , V_34 , V_12 ) ;
break;
case V_154 | V_175 | V_188 :
F_22 ( V_176 , V_30 , V_34 , V_12 ) ;
goto V_160;
case V_158 | V_175 | V_188 :
F_22 ( V_177 , V_30 , V_34 , V_12 ) ;
break;
V_160:
if ( F_56 ( V_67 ) == V_154 )
F_22 ( V_157 , V_30 , 0 , V_12 ) ;
break;
case V_191 | V_192 :
F_32 ( V_193 , V_12 -> V_14 , V_12 -> V_73 [ V_49 + V_8 ] , V_12 ) ;
F_10 ( V_12 ) ;
break;
case V_191 | V_77 | V_156 :
case V_191 | V_79 | V_156 :
case V_191 | V_81 | V_156 :
case V_191 | V_83 | V_156 :
case V_191 | V_85 | V_156 :
case V_191 | V_87 | V_156 :
case V_191 | V_74 | V_156 : {
int V_194 ;
V_194 = F_38 ( V_67 , V_30 , V_29 , 0 , false , V_49 + V_8 , V_12 ) ;
if ( V_194 )
return V_194 ;
break;
}
case V_191 | V_77 | V_188 :
case V_191 | V_79 | V_188 :
case V_191 | V_81 | V_188 :
case V_191 | V_83 | V_188 :
case V_191 | V_85 | V_188 :
case V_191 | V_87 | V_188 :
case V_191 | V_74 | V_188 : {
int V_194 ;
V_194 = F_38 ( V_67 , V_30 , 0 , V_34 , true , V_49 + V_8 , V_12 ) ;
if ( V_194 )
return V_194 ;
break;
}
case V_191 | V_195 :
{
T_4 * V_15 = ( ( T_4 * ) V_196 ) + V_34 ;
V_12 -> V_197 = true ;
F_9 ( ( T_1 * ) V_15 , V_12 ) ;
F_10 ( V_12 ) ;
F_12 ( V_129 , V_37 [ V_136 ] , V_12 ) ;
if ( F_57 ( V_15 ) && V_12 -> V_130 )
F_44 ( V_12 , V_37 [ V_198 ] ) ;
break;
}
case V_191 | V_199 :
F_49 ( V_12 ) ;
break;
case V_191 | V_200 :
if ( V_49 == V_12 -> V_116 -> V_105 - 1 )
break;
F_32 ( V_193 , V_12 -> V_14 , V_12 -> V_132 , V_12 ) ;
F_10 ( V_12 ) ;
break;
case V_201 | V_202 | V_203 :
{
const struct V_150 V_204 = V_10 [ 1 ] ;
T_3 V_205 ;
V_205 = ( T_3 ) V_204 . V_34 << 32 | ( T_1 ) V_34 ;
F_31 ( V_205 , V_30 , V_12 ) ;
return 1 ;
}
case V_206 | V_207 | V_208 :
case V_206 | V_207 | V_209 :
case V_206 | V_207 | V_210 :
case V_206 | V_207 | V_203 : {
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_28 = 0 , V_211 ;
V_12 -> V_39 = true ;
switch ( F_58 ( V_67 ) ) {
case V_208 :
V_28 = V_143 ;
break;
case V_209 :
V_28 = V_212 ;
break;
case V_210 :
V_28 = V_213 ;
break;
case V_203 :
V_28 = V_147 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_211 = F_19 ( V_8 ) ;
} else {
F_25 ( V_8 , V_36 , V_12 ) ;
V_211 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_29 ) | V_211 | F_15 ( V_30 ) , V_12 ) ;
break;
}
case V_214 | V_207 | V_208 :
case V_214 | V_207 | V_209 :
case V_214 | V_207 | V_210 :
case V_214 | V_207 | V_203 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_182 = V_37 [ V_183 ] ;
T_1 V_28 = 0 , V_211 ;
V_12 -> V_184 = true ;
F_25 ( V_34 , V_182 , V_12 ) ;
switch ( F_58 ( V_67 ) ) {
case V_208 :
V_28 = V_122 ;
break;
case V_209 :
V_28 = V_215 ;
break;
case V_210 :
V_28 = V_216 ;
break;
case V_203 :
V_28 = V_185 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_211 = F_19 ( V_8 ) ;
} else {
V_12 -> V_39 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
V_211 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_30 ) | V_211 | F_15 ( V_182 ) , V_12 ) ;
break;
}
case V_217 | V_207 | V_208 :
case V_217 | V_207 | V_209 :
case V_217 | V_207 | V_210 :
case V_217 | V_207 | V_203 : {
const T_4 V_36 = V_37 [ V_38 ] ;
T_1 V_28 = 0 , V_211 ;
switch ( F_58 ( V_67 ) ) {
case V_208 :
V_28 = V_122 ;
break;
case V_209 :
V_28 = V_215 ;
break;
case V_210 :
V_28 = V_216 ;
break;
case V_203 :
V_28 = V_185 ;
break;
}
if ( F_1 ( V_8 ) ) {
V_28 |= V_27 ;
V_211 = F_19 ( V_8 ) ;
} else {
V_12 -> V_39 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
V_211 = F_14 ( V_36 ) ;
}
F_8 ( V_28 | F_13 ( V_30 ) | V_211 | F_15 ( V_29 ) , V_12 ) ;
break;
}
case V_217 | V_218 | V_208 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_182 = V_37 [ V_183 ] ;
const T_4 V_219 = V_37 [ V_220 ] ;
V_12 -> V_39 = true ;
V_12 -> V_184 = true ;
V_12 -> V_221 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
F_21 ( V_125 , V_30 , V_36 , V_36 , V_12 ) ;
F_8 ( V_143 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_182 ) , V_12 ) ;
F_21 ( V_125 , V_182 , V_29 , V_219 , V_12 ) ;
F_8 ( V_222 | F_55 ( V_223 ) | F_13 ( V_36 ) | F_14 ( V_182 ) | F_15 ( V_219 ) , V_12 ) ;
F_43 ( V_182 , V_219 , V_12 ) ;
F_32 ( V_84 , 4 , 0 , V_12 ) ;
F_10 ( V_12 ) ;
break;
}
case V_217 | V_218 | V_203 : {
const T_4 V_36 = V_37 [ V_38 ] ;
const T_4 V_182 = V_37 [ V_183 ] ;
const T_4 V_219 = V_37 [ V_220 ] ;
V_12 -> V_39 = true ;
V_12 -> V_184 = true ;
V_12 -> V_221 = true ;
F_25 ( V_8 , V_36 , V_12 ) ;
F_21 ( V_125 , V_30 , V_36 , V_36 , V_12 ) ;
F_8 ( V_147 | F_13 ( V_36 ) | F_14 ( V_18 ) | F_15 ( V_182 ) , V_12 ) ;
F_21 ( V_125 , V_182 , V_29 , V_219 , V_12 ) ;
F_8 ( V_224 | F_55 ( V_223 ) | F_13 ( V_36 ) | F_14 ( V_182 ) | F_15 ( V_219 ) , V_12 ) ;
F_43 ( V_182 , V_219 , V_12 ) ;
F_32 ( V_84 , 4 , 0 , V_12 ) ;
F_10 ( V_12 ) ;
break;
}
#define F_59 ( V_22 , V_15 ) \
((int)K < 0 ? ((int)K >= SKF_LL_OFF ? func##_negative_offset : func) : func##_positive_offset)
case V_201 | V_225 | V_208 :
V_15 = F_59 ( V_34 , V_226 ) ;
goto V_227;
case V_201 | V_225 | V_209 :
V_15 = F_59 ( V_34 , V_228 ) ;
goto V_227;
case V_201 | V_225 | V_210 :
V_15 = F_59 ( V_34 , V_229 ) ;
goto V_227;
case V_201 | V_230 | V_208 :
V_15 = V_226 ;
goto V_227;
case V_201 | V_230 | V_209 :
V_15 = V_228 ;
goto V_227;
case V_201 | V_230 | V_210 :
V_15 = V_229 ;
V_227:
V_12 -> V_130 = true ;
F_12 ( V_37 [ V_198 ] , V_129 , V_12 ) ;
F_25 ( V_34 , V_231 , V_12 ) ;
if ( F_60 ( V_67 ) == V_230 )
F_20 ( V_125 , V_29 , V_231 , V_12 ) ;
F_9 ( V_15 , V_12 ) ;
F_22 ( V_176 , V_231 , 0 , V_12 ) ;
F_12 ( V_129 , V_37 [ V_136 ] , V_12 ) ;
break;
default:
F_61 ( L_1 , V_67 ) ;
return - V_189 ;
}
return 0 ;
}
static int F_62 ( struct V_11 * V_12 )
{
const struct V_115 * V_116 = V_12 -> V_116 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_116 -> V_105 ; V_49 ++ ) {
const struct V_150 * V_10 = & V_116 -> V_153 [ V_49 ] ;
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
static void F_63 ( void * V_232 , unsigned int V_233 )
{
T_1 * V_234 ;
for ( V_234 = V_232 ; V_233 >= sizeof( T_1 ) ; V_233 -= sizeof( T_1 ) )
* V_234 ++ = 0x91d02005 ;
}
struct V_115 * F_64 ( struct V_115 * V_116 )
{
struct V_115 * V_36 , * V_235 = V_116 ;
struct V_236 * V_237 ;
bool V_238 = false ;
struct V_11 V_12 ;
T_1 V_239 ;
T_4 * V_240 ;
int V_241 ;
if ( ! V_242 )
return V_235 ;
V_36 = F_65 ( V_116 ) ;
if ( F_66 ( V_36 ) )
return V_235 ;
if ( V_36 != V_116 ) {
V_238 = true ;
V_116 = V_36 ;
}
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_116 = V_116 ;
V_12 . V_73 = F_67 ( V_116 -> V_105 , sizeof( unsigned int ) , V_243 ) ;
if ( V_12 . V_73 == NULL ) {
V_116 = V_235 ;
goto V_244;
}
if ( F_62 ( & V_12 ) ) {
V_116 = V_235 ;
goto V_245;
}
F_46 ( & V_12 ) ;
F_48 ( & V_12 ) ;
V_239 = sizeof( T_1 ) * V_12 . V_14 ;
V_237 = F_68 ( V_239 , & V_240 ,
sizeof( T_1 ) , F_63 ) ;
if ( V_237 == NULL ) {
V_116 = V_235 ;
goto V_245;
}
V_12 . V_13 = ( T_1 * ) V_240 ;
for ( V_241 = 1 ; V_241 < 3 ; V_241 ++ ) {
V_12 . V_14 = 0 ;
F_46 ( & V_12 ) ;
if ( F_62 ( & V_12 ) ) {
F_69 ( V_237 ) ;
V_116 = V_235 ;
goto V_245;
}
F_48 ( & V_12 ) ;
if ( V_242 > 1 )
F_70 ( L_2 , V_241 ,
V_239 - ( V_12 . V_14 * 4 ) ,
V_12 . V_39 ? '1' : ' ' ,
V_12 . V_184 ? '2' : ' ' ,
V_12 . V_221 ? '3' : ' ' ,
V_12 . V_130 ? 'L' : ' ' ,
V_12 . V_113 ? 'F' : ' ' ,
V_12 . V_197 ? 'C' : ' ' ,
V_12 . V_114 ? 'T' : ' ' ) ;
}
if ( V_242 > 1 )
F_71 ( V_116 -> V_105 , V_239 , V_241 , V_12 . V_13 ) ;
F_5 ( V_237 , ( T_4 * ) V_237 + ( V_237 -> V_246 * V_247 ) ) ;
F_72 ( V_237 ) ;
V_116 -> V_148 = ( void * ) V_12 . V_13 ;
V_116 -> V_248 = 1 ;
V_116 -> V_249 = V_239 ;
V_245:
F_73 ( V_12 . V_73 ) ;
V_244:
if ( V_238 )
F_74 ( V_116 , V_116 == V_235 ?
V_36 : V_235 ) ;
return V_116 ;
}
