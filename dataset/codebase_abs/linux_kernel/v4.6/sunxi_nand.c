static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_7 ) ;
}
static T_1 F_4 ( int V_8 , void * V_9 )
{
struct V_4 * V_10 = V_9 ;
T_2 V_11 = F_5 ( V_10 -> V_12 + V_13 ) ;
T_2 V_14 = F_5 ( V_10 -> V_12 + V_15 ) ;
if ( ! ( V_14 & V_11 ) )
return V_16 ;
if ( ( V_14 & V_11 ) == V_14 )
F_6 ( & V_10 -> F_6 ) ;
F_7 ( V_11 & V_17 , V_10 -> V_12 + V_13 ) ;
F_7 ( ~ V_11 & V_14 & V_17 , V_10 -> V_12 + V_15 ) ;
return V_18 ;
}
static int F_8 ( struct V_4 * V_10 , T_2 V_19 ,
unsigned int V_20 )
{
F_9 ( & V_10 -> F_6 ) ;
F_7 ( V_19 , V_10 -> V_12 + V_15 ) ;
if ( ! V_20 )
V_20 = V_21 ;
if ( ! F_10 ( & V_10 -> F_6 ,
F_11 ( V_20 ) ) ) {
F_12 ( V_10 -> V_22 , L_1 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_13 ( struct V_4 * V_10 )
{
unsigned long V_24 = V_25 +
F_11 ( V_21 ) ;
do {
if ( ! ( F_5 ( V_10 -> V_12 + V_13 ) & V_26 ) )
return 0 ;
} while ( F_14 ( V_25 , V_24 ) );
F_12 ( V_10 -> V_22 , L_2 ) ;
return - V_23 ;
}
static int F_15 ( struct V_4 * V_10 )
{
unsigned long V_24 = V_25 +
F_11 ( V_21 ) ;
F_7 ( 0 , V_10 -> V_12 + V_27 ) ;
F_7 ( V_28 , V_10 -> V_12 + V_29 ) ;
do {
if ( ! ( F_5 ( V_10 -> V_12 + V_29 ) & V_28 ) )
return 0 ;
} while ( F_14 ( V_25 , V_24 ) );
F_12 ( V_10 -> V_22 , L_3 ) ;
return - V_23 ;
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
struct V_33 * V_34 ;
unsigned long V_35 = ( V_32 -> V_3 . V_36 == V_37 ? 400 : 20 ) ;
int V_38 ;
if ( V_32 -> V_39 < 0 )
return 0 ;
V_34 = & V_32 -> V_40 [ V_32 -> V_39 ] . V_34 ;
switch ( V_34 -> type ) {
case V_41 :
V_38 = ! ! ( F_5 ( V_10 -> V_12 + V_13 ) &
F_18 ( V_34 -> V_42 . V_43 ) ) ;
if ( V_38 )
break;
F_8 ( V_10 , V_44 , V_35 ) ;
V_38 = ! ! ( F_5 ( V_10 -> V_12 + V_13 ) &
F_18 ( V_34 -> V_42 . V_43 ) ) ;
break;
case V_45 :
V_38 = F_19 ( V_34 -> V_42 . V_46 ) ;
break;
case V_47 :
default:
V_38 = 0 ;
F_12 ( V_10 -> V_22 , L_4 ) ;
break;
}
return V_38 ;
}
static void F_20 ( struct V_30 * V_31 , int V_48 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
struct V_49 * V_50 ;
T_2 V_51 ;
if ( V_48 > 0 && V_48 >= V_32 -> V_52 )
return;
if ( V_48 == V_32 -> V_39 )
return;
V_51 = F_5 ( V_10 -> V_12 + V_29 ) &
~ ( V_53 | V_54 | V_55 | V_56 ) ;
if ( V_48 >= 0 ) {
V_50 = & V_32 -> V_40 [ V_48 ] ;
V_51 |= F_21 ( V_50 -> V_57 ) | V_56 |
F_22 ( V_3 -> V_58 - 10 ) ;
if ( V_50 -> V_34 . type == V_47 ) {
V_3 -> V_59 = NULL ;
} else {
V_3 -> V_59 = F_16 ;
if ( V_50 -> V_34 . type == V_41 )
V_51 |= F_23 ( V_50 -> V_34 . V_42 . V_43 ) ;
}
F_7 ( V_31 -> V_60 , V_10 -> V_12 + V_61 ) ;
if ( V_10 -> V_62 != V_32 -> V_62 ) {
F_24 ( V_10 -> V_63 , V_32 -> V_62 ) ;
V_10 -> V_62 = V_32 -> V_62 ;
}
}
F_7 ( V_32 -> V_64 , V_10 -> V_12 + V_65 ) ;
F_7 ( V_32 -> V_66 , V_10 -> V_12 + V_67 ) ;
F_7 ( V_51 , V_10 -> V_12 + V_29 ) ;
V_32 -> V_39 = V_48 ;
}
static void F_25 ( struct V_30 * V_31 , T_3 * V_68 , int V_69 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
int V_38 ;
int V_70 ;
int V_71 = 0 ;
T_2 V_72 ;
while ( V_69 > V_71 ) {
V_70 = F_26 ( V_69 - V_71 , V_73 ) ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
break;
F_7 ( V_70 , V_10 -> V_12 + V_74 ) ;
V_72 = V_75 | V_76 ;
F_7 ( V_72 , V_10 -> V_12 + V_77 ) ;
V_38 = F_8 ( V_10 , V_78 , 0 ) ;
if ( V_38 )
break;
if ( V_68 )
F_27 ( V_68 + V_71 , V_10 -> V_12 + V_79 ,
V_70 ) ;
V_71 += V_70 ;
}
}
static void F_28 ( struct V_30 * V_31 , const T_3 * V_68 ,
int V_69 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
int V_38 ;
int V_70 ;
int V_71 = 0 ;
T_2 V_72 ;
while ( V_69 > V_71 ) {
V_70 = F_26 ( V_69 - V_71 , V_73 ) ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
break;
F_7 ( V_70 , V_10 -> V_12 + V_74 ) ;
F_29 ( V_10 -> V_12 + V_79 , V_68 + V_71 , V_70 ) ;
V_72 = V_75 | V_76 |
V_80 ;
F_7 ( V_72 , V_10 -> V_12 + V_77 ) ;
V_38 = F_8 ( V_10 , V_78 , 0 ) ;
if ( V_38 )
break;
V_71 += V_70 ;
}
}
static T_3 F_30 ( struct V_30 * V_31 )
{
T_3 V_38 ;
F_25 ( V_31 , & V_38 , 1 ) ;
return V_38 ;
}
static void F_31 ( struct V_30 * V_31 , int V_81 ,
unsigned int V_6 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
int V_38 ;
T_2 V_72 ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
return;
if ( V_6 & V_82 ) {
V_72 = F_5 ( V_10 -> V_12 + V_29 ) ;
if ( V_6 & V_83 )
V_72 |= V_84 ;
else
V_72 &= ~ V_84 ;
F_7 ( V_72 , V_10 -> V_12 + V_29 ) ;
}
if ( V_81 == V_85 )
return;
if ( V_6 & V_86 ) {
F_7 ( V_87 | V_81 , V_10 -> V_12 + V_77 ) ;
} else {
F_7 ( V_81 , V_10 -> V_12 + V_88 ) ;
F_7 ( V_89 , V_10 -> V_12 + V_77 ) ;
}
F_8 ( V_10 , V_78 , 0 ) ;
}
static T_4 F_32 ( T_4 V_36 , int V_90 )
{
V_36 &= 0x7fff ;
while ( V_90 -- )
V_36 = ( ( V_36 >> 1 ) |
( ( ( V_36 ^ ( V_36 >> 1 ) ) & 1 ) << 14 ) ) & 0x7fff ;
return V_36 ;
}
static T_4 F_33 ( struct V_30 * V_31 , int V_91 , bool V_92 )
{
const T_4 * V_93 = V_94 ;
int V_95 = F_34 ( V_31 -> V_96 , V_31 ) ;
if ( V_95 > F_35 ( V_94 ) )
V_95 = F_35 ( V_94 ) ;
if ( V_92 ) {
if ( V_31 -> V_97 == 512 )
V_93 = V_98 ;
else
V_93 = V_99 ;
}
return V_93 [ V_91 % V_95 ] ;
}
static void F_36 ( struct V_30 * V_31 ,
int V_91 , bool V_92 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
T_2 V_100 = F_5 ( V_10 -> V_12 + V_27 ) ;
T_4 V_36 ;
if ( ! ( V_3 -> V_101 & V_102 ) )
return;
V_100 = F_5 ( V_10 -> V_12 + V_27 ) ;
V_36 = F_33 ( V_31 , V_91 , V_92 ) ;
V_100 = F_5 ( V_10 -> V_12 + V_27 ) & ~ V_103 ;
F_7 ( V_100 | F_37 ( V_36 ) , V_10 -> V_12 + V_27 ) ;
}
static void F_38 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
if ( ! ( V_3 -> V_101 & V_102 ) )
return;
F_7 ( F_5 ( V_10 -> V_12 + V_27 ) | V_104 ,
V_10 -> V_12 + V_27 ) ;
}
static void F_39 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
if ( ! ( V_3 -> V_101 & V_102 ) )
return;
F_7 ( F_5 ( V_10 -> V_12 + V_27 ) & ~ V_104 ,
V_10 -> V_12 + V_27 ) ;
}
static void F_40 ( struct V_30 * V_31 , int V_91 , T_5 * V_105 )
{
T_4 V_36 = F_33 ( V_31 , V_91 , true ) ;
V_105 [ 0 ] ^= V_36 ;
V_105 [ 1 ] ^= F_32 ( V_36 , 8 ) ;
}
static void F_41 ( struct V_30 * V_31 ,
const T_3 * V_68 , int V_69 ,
bool V_92 , int V_91 )
{
F_36 ( V_31 , V_91 , V_92 ) ;
F_38 ( V_31 ) ;
F_28 ( V_31 , V_68 , V_69 ) ;
F_39 ( V_31 ) ;
}
static void F_42 ( struct V_30 * V_31 , T_3 * V_68 ,
int V_69 , bool V_92 , int V_91 )
{
F_36 ( V_31 , V_91 , V_92 ) ;
F_38 ( V_31 ) ;
F_25 ( V_31 , V_68 , V_69 ) ;
F_39 ( V_31 ) ;
}
static void F_43 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_106 * V_107 = V_3 -> V_92 . V_108 ;
T_2 V_100 ;
V_100 = F_5 ( V_10 -> V_12 + V_27 ) ;
V_100 &= ~ ( V_109 | V_110 |
V_111 ) ;
V_100 |= V_112 | F_44 ( V_107 -> V_113 ) | V_114 ;
F_7 ( V_100 , V_10 -> V_12 + V_27 ) ;
}
static void F_45 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
F_7 ( F_5 ( V_10 -> V_12 + V_27 ) & ~ V_112 ,
V_10 -> V_12 + V_27 ) ;
}
static inline void F_46 ( T_2 V_115 , T_5 * V_68 )
{
V_68 [ 0 ] = V_115 ;
V_68 [ 1 ] = V_115 >> 8 ;
V_68 [ 2 ] = V_115 >> 16 ;
V_68 [ 3 ] = V_115 >> 24 ;
}
static int F_47 ( struct V_30 * V_31 ,
T_5 * V_107 , int V_116 ,
T_5 * V_117 , int V_118 ,
int * V_119 ,
unsigned int * V_120 ,
bool V_105 , int V_91 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_121 * V_92 = & V_3 -> V_92 ;
int V_122 = 0 ;
T_2 V_123 ;
int V_38 ;
if ( * V_119 != V_116 )
V_3 -> V_124 ( V_31 , V_125 , V_116 , - 1 ) ;
F_42 ( V_31 , NULL , V_92 -> V_126 , false , V_91 ) ;
if ( V_116 + V_92 -> V_126 != V_118 )
V_3 -> V_124 ( V_31 , V_125 , V_118 , - 1 ) ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
return V_38 ;
F_38 ( V_31 ) ;
F_7 ( V_75 | V_76 | V_127 ,
V_10 -> V_12 + V_77 ) ;
V_38 = F_8 ( V_10 , V_78 , 0 ) ;
F_39 ( V_31 ) ;
if ( V_38 )
return V_38 ;
* V_119 = V_118 + V_92 -> V_128 + 4 ;
V_123 = F_5 ( V_10 -> V_12 + V_129 ) ;
if ( V_123 & F_48 ( 0 ) ) {
T_5 V_130 = 0xff ;
if ( F_49 ( ! ( F_5 ( V_10 -> V_12 + V_131 ) & 0x1 ) ) )
V_130 = 0x0 ;
memset ( V_107 , V_130 , V_92 -> V_126 ) ;
memset ( V_117 , V_130 , V_92 -> V_128 + 4 ) ;
return 1 ;
}
V_38 = F_50 ( 0 , F_5 ( V_10 -> V_12 + F_51 ( 0 ) ) ) ;
F_27 ( V_107 , V_10 -> V_12 + V_79 , V_92 -> V_126 ) ;
V_3 -> V_124 ( V_31 , V_125 , V_118 , - 1 ) ;
F_42 ( V_31 , V_117 , V_92 -> V_128 + 4 , true , V_91 ) ;
if ( V_123 & F_52 ( 0 ) ) {
if ( V_3 -> V_101 & V_102 ) {
V_3 -> V_124 ( V_31 , V_125 , V_116 , - 1 ) ;
V_3 -> V_132 ( V_31 , V_107 , V_92 -> V_126 ) ;
V_3 -> V_124 ( V_31 , V_125 , V_118 , - 1 ) ;
V_3 -> V_132 ( V_31 , V_117 , V_92 -> V_128 + 4 ) ;
}
V_38 = F_53 ( V_107 , V_92 -> V_126 ,
V_117 , V_92 -> V_128 + 4 ,
NULL , 0 , V_92 -> V_133 ) ;
if ( V_38 >= 0 )
V_122 = 1 ;
} else {
F_46 ( F_5 ( V_10 -> V_12 + F_54 ( 0 ) ) ,
V_117 ) ;
if ( V_105 && V_3 -> V_101 & V_102 )
F_40 ( V_31 , V_91 , V_117 ) ;
}
if ( V_38 < 0 ) {
V_31 -> V_134 . V_135 ++ ;
} else {
V_31 -> V_134 . V_136 += V_38 ;
* V_120 = F_55 (unsigned int, *max_bitflips, ret) ;
}
return V_122 ;
}
static void F_56 ( struct V_30 * V_31 ,
T_5 * V_117 , int * V_119 ,
bool V_137 , int V_91 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_121 * V_92 = & V_3 -> V_92 ;
int V_138 = ( ( V_92 -> V_128 + 4 ) * V_92 -> V_139 ) ;
int V_69 = V_31 -> V_140 - V_138 ;
if ( V_69 <= 0 )
return;
if ( * V_119 != V_138 )
V_3 -> V_124 ( V_31 , V_125 ,
V_138 + V_31 -> V_60 , - 1 ) ;
if ( ! V_137 )
F_25 ( V_31 , V_117 + V_138 , V_69 ) ;
else
F_42 ( V_31 , V_117 + V_138 , V_69 ,
false , V_91 ) ;
* V_119 = V_31 -> V_140 + V_31 -> V_60 ;
}
static inline T_2 F_57 ( const T_5 * V_68 )
{
return V_68 [ 0 ] | ( V_68 [ 1 ] << 8 ) | ( V_68 [ 2 ] << 16 ) | ( V_68 [ 3 ] << 24 ) ;
}
static int F_58 ( struct V_30 * V_31 ,
const T_5 * V_107 , int V_116 ,
const T_5 * V_117 , int V_118 ,
int * V_119 , bool V_105 ,
int V_91 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_121 * V_92 = & V_3 -> V_92 ;
int V_38 ;
if ( V_116 != * V_119 )
V_3 -> V_124 ( V_31 , V_141 , V_116 , - 1 ) ;
F_41 ( V_31 , V_107 , V_92 -> V_126 , false , V_91 ) ;
if ( ( V_3 -> V_101 & V_102 ) && V_105 ) {
T_5 V_115 [ 4 ] ;
memcpy ( V_115 , V_117 , 4 ) ;
F_40 ( V_31 , V_91 , V_115 ) ;
F_7 ( F_57 ( V_115 ) ,
V_10 -> V_12 + F_54 ( 0 ) ) ;
} else {
F_7 ( F_57 ( V_117 ) ,
V_10 -> V_12 + F_54 ( 0 ) ) ;
}
if ( V_116 + V_92 -> V_126 != V_118 )
V_3 -> V_124 ( V_31 , V_141 , V_118 , - 1 ) ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
return V_38 ;
F_38 ( V_31 ) ;
F_7 ( V_75 | V_76 |
V_80 | V_127 ,
V_10 -> V_12 + V_77 ) ;
V_38 = F_8 ( V_10 , V_78 , 0 ) ;
F_39 ( V_31 ) ;
if ( V_38 )
return V_38 ;
* V_119 = V_118 + V_92 -> V_128 + 4 ;
return 0 ;
}
static void F_59 ( struct V_30 * V_31 ,
T_5 * V_117 , int * V_119 ,
int V_91 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_121 * V_92 = & V_3 -> V_92 ;
int V_138 = ( ( V_92 -> V_128 + 4 ) * V_92 -> V_139 ) ;
int V_69 = V_31 -> V_140 - V_138 ;
if ( V_69 <= 0 )
return;
if ( * V_119 != V_138 )
V_3 -> V_124 ( V_31 , V_141 ,
V_138 + V_31 -> V_60 , - 1 ) ;
F_41 ( V_31 , V_117 + V_138 , V_69 , false , V_91 ) ;
* V_119 = V_31 -> V_140 + V_31 -> V_60 ;
}
static int F_60 ( struct V_30 * V_31 ,
struct V_2 * V_48 , T_3 * V_68 ,
int V_142 , int V_91 )
{
struct V_121 * V_92 = & V_48 -> V_92 ;
unsigned int V_120 = 0 ;
int V_38 , V_143 , V_119 = 0 ;
bool V_122 = false ;
F_43 ( V_31 ) ;
for ( V_143 = 0 ; V_143 < V_92 -> V_139 ; V_143 ++ ) {
int V_116 = V_143 * V_92 -> V_126 ;
int V_118 = V_143 * ( V_92 -> V_128 + 4 ) ;
T_5 * V_107 = V_68 + V_116 ;
T_5 * V_117 = V_48 -> V_144 + V_118 ;
V_38 = F_47 ( V_31 , V_107 , V_116 , V_117 ,
V_118 + V_31 -> V_60 ,
& V_119 , & V_120 ,
! V_143 , V_91 ) ;
if ( V_38 < 0 )
return V_38 ;
else if ( V_38 )
V_122 = true ;
}
if ( V_142 )
F_56 ( V_31 , V_48 -> V_144 , & V_119 ,
! V_122 , V_91 ) ;
F_45 ( V_31 ) ;
return V_120 ;
}
static int F_61 ( struct V_30 * V_31 ,
struct V_2 * V_48 ,
const T_3 * V_68 , int V_142 ,
int V_91 )
{
struct V_121 * V_92 = & V_48 -> V_92 ;
int V_38 , V_143 , V_119 = 0 ;
F_43 ( V_31 ) ;
for ( V_143 = 0 ; V_143 < V_92 -> V_139 ; V_143 ++ ) {
int V_116 = V_143 * V_92 -> V_126 ;
int V_118 = V_143 * ( V_92 -> V_128 + 4 ) ;
const T_5 * V_107 = V_68 + V_116 ;
const T_5 * V_117 = V_48 -> V_144 + V_118 ;
V_38 = F_58 ( V_31 , V_107 , V_116 , V_117 ,
V_118 + V_31 -> V_60 ,
& V_119 , ! V_143 , V_91 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_142 || ( V_48 -> V_101 & V_102 ) )
F_59 ( V_31 , V_48 -> V_144 ,
& V_119 , V_91 ) ;
F_45 ( V_31 ) ;
return 0 ;
}
static int F_62 ( struct V_30 * V_31 ,
struct V_2 * V_48 ,
T_3 * V_68 , int V_142 ,
int V_91 )
{
struct V_121 * V_92 = & V_48 -> V_92 ;
unsigned int V_120 = 0 ;
int V_38 , V_143 , V_119 = 0 ;
bool V_122 = false ;
F_43 ( V_31 ) ;
for ( V_143 = 0 ; V_143 < V_92 -> V_139 ; V_143 ++ ) {
int V_116 = V_143 * ( V_92 -> V_126 + V_92 -> V_128 + 4 ) ;
int V_118 = V_116 + V_92 -> V_126 ;
T_5 * V_107 = V_68 + ( V_143 * V_92 -> V_126 ) ;
T_5 * V_117 = V_48 -> V_144 + ( V_143 * ( V_92 -> V_128 + 4 ) ) ;
V_38 = F_47 ( V_31 , V_107 , V_116 , V_117 ,
V_118 , & V_119 ,
& V_120 , ! V_143 , V_91 ) ;
if ( V_38 < 0 )
return V_38 ;
else if ( V_38 )
V_122 = true ;
}
if ( V_142 )
F_56 ( V_31 , V_48 -> V_144 , & V_119 ,
! V_122 , V_91 ) ;
F_45 ( V_31 ) ;
return V_120 ;
}
static int F_63 ( struct V_30 * V_31 ,
struct V_2 * V_48 ,
const T_3 * V_68 ,
int V_142 , int V_91 )
{
struct V_121 * V_92 = & V_48 -> V_92 ;
int V_38 , V_143 , V_119 = 0 ;
F_43 ( V_31 ) ;
for ( V_143 = 0 ; V_143 < V_92 -> V_139 ; V_143 ++ ) {
int V_116 = V_143 * ( V_92 -> V_126 + V_92 -> V_128 + 4 ) ;
int V_118 = V_116 + V_92 -> V_126 ;
const T_5 * V_107 = V_68 + ( V_143 * V_92 -> V_126 ) ;
const T_5 * V_117 = V_48 -> V_144 + ( V_143 * ( V_92 -> V_128 + 4 ) ) ;
V_38 = F_58 ( V_31 , V_107 , V_116 ,
V_117 , V_118 , & V_119 ,
false , V_91 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_142 || ( V_48 -> V_101 & V_102 ) )
F_59 ( V_31 , V_48 -> V_144 ,
& V_119 , V_91 ) ;
F_45 ( V_31 ) ;
return 0 ;
}
static int F_64 ( const T_6 * V_145 , int V_146 , T_2 V_147 ,
T_2 V_148 )
{
T_2 V_149 = F_65 ( V_147 , V_148 ) ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_146 ; V_143 ++ ) {
if ( V_149 <= V_145 [ V_143 ] )
return V_143 ;
}
return - V_150 ;
}
static int F_66 ( struct V_1 * V_48 ,
const struct V_151 * V_152 )
{
struct V_4 * V_10 = F_3 ( V_48 -> V_3 . V_7 ) ;
T_2 V_153 = 0 ;
T_6 V_154 , V_155 , V_156 , V_157 , V_158 ;
if ( V_152 -> V_159 > V_153 )
V_153 = V_152 -> V_159 ;
if ( V_152 -> V_160 > V_153 )
V_153 = V_152 -> V_160 ;
if ( V_152 -> V_161 > V_153 )
V_153 = V_152 -> V_161 ;
if ( V_152 -> V_162 > V_153 )
V_153 = V_152 -> V_162 ;
if ( V_152 -> V_163 > V_153 )
V_153 = V_152 -> V_163 ;
if ( V_152 -> V_164 > V_153 )
V_153 = V_152 -> V_164 ;
if ( V_152 -> V_165 > V_153 )
V_153 = V_152 -> V_165 ;
if ( V_152 -> V_166 > V_153 )
V_153 = V_152 -> V_166 ;
if ( V_152 -> V_167 > V_153 )
V_153 = V_152 -> V_167 ;
if ( V_152 -> V_168 > ( V_153 * 3 ) )
V_153 = F_65 ( V_152 -> V_168 , 3 ) ;
if ( V_152 -> V_169 > V_153 )
V_153 = V_152 -> V_169 ;
if ( V_152 -> V_170 > V_153 )
V_153 = V_152 -> V_170 ;
if ( V_152 -> V_171 > V_153 )
V_153 = V_152 -> V_171 ;
if ( V_152 -> V_172 > ( V_153 * 2 ) )
V_153 = F_65 ( V_152 -> V_172 , 2 ) ;
if ( V_152 -> V_173 > ( V_153 * 2 ) )
V_153 = F_65 ( V_152 -> V_173 , 2 ) ;
V_154 = F_67 ( V_174 , V_152 -> V_175 ,
V_153 ) ;
if ( V_154 < 0 ) {
F_12 ( V_10 -> V_22 , L_5 ) ;
return V_154 ;
}
V_155 = F_65 ( V_152 -> V_176 , V_153 ) >> 3 ;
if ( V_155 > 3 ) {
F_12 ( V_10 -> V_22 , L_6 ) ;
return - V_150 ;
}
V_156 = F_65 ( V_152 -> V_177 , V_153 ) >> 3 ;
if ( V_156 > 3 ) {
F_12 ( V_10 -> V_22 , L_7 ) ;
return - V_150 ;
}
V_157 = F_67 ( V_178 , V_152 -> V_179 ,
V_153 ) ;
if ( V_157 < 0 ) {
F_12 ( V_10 -> V_22 , L_8 ) ;
return V_157 ;
}
V_158 = 0x7 ;
V_48 -> V_66 = F_68 ( V_154 , V_155 , V_156 , V_157 , V_158 ) ;
V_48 -> V_64 = ( V_152 -> V_172 < 30000 ) ? V_180 : 0 ;
V_153 = F_65 ( V_153 , 1000 ) ;
V_48 -> V_62 = ( 2 * V_181 ) / V_153 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_48 ,
struct V_182 * V_183 )
{
struct V_30 * V_31 = F_70 ( & V_48 -> V_3 ) ;
const struct V_151 * V_152 ;
int V_38 ;
int V_113 ;
V_113 = F_71 ( & V_48 -> V_3 ) ;
if ( V_113 == V_184 ) {
V_113 = V_48 -> V_3 . V_185 ;
} else {
T_3 V_186 [ V_187 ] = {} ;
int V_143 ;
V_113 = F_72 ( V_113 ) - 1 ;
if ( V_113 < 0 )
V_113 = 0 ;
V_186 [ 0 ] = V_113 ;
for ( V_143 = 0 ; V_143 < V_48 -> V_52 ; V_143 ++ ) {
V_48 -> V_3 . V_188 ( V_31 , V_143 ) ;
V_38 = V_48 -> V_3 . V_189 ( V_31 , & V_48 -> V_3 ,
V_190 ,
V_186 ) ;
V_48 -> V_3 . V_188 ( V_31 , - 1 ) ;
if ( V_38 )
return V_38 ;
}
}
V_152 = F_73 ( V_113 ) ;
if ( F_74 ( V_152 ) )
return F_75 ( V_152 ) ;
return F_66 ( V_48 , V_152 ) ;
}
static int F_76 ( struct V_30 * V_31 ,
struct V_121 * V_92 ,
struct V_182 * V_183 )
{
static const T_5 V_191 [] = { 16 , 24 , 28 , 32 , 40 , 48 , 56 , 60 , 64 } ;
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
struct V_106 * V_107 ;
struct V_192 * V_193 ;
int V_194 ;
int V_38 ;
int V_143 ;
V_107 = F_77 ( sizeof( * V_107 ) , V_195 ) ;
if ( ! V_107 )
return - V_196 ;
for ( V_143 = 0 ; V_143 < F_35 ( V_191 ) ; V_143 ++ ) {
if ( V_92 -> V_133 <= V_191 [ V_143 ] )
break;
}
if ( V_143 >= F_35 ( V_191 ) ) {
F_12 ( V_10 -> V_22 , L_9 ) ;
V_38 = - V_197 ;
goto V_198;
}
V_107 -> V_113 = V_143 ;
V_92 -> V_128 = F_65 ( V_92 -> V_133 * F_72 ( 8 * 1024 ) , 8 ) ;
V_92 -> V_128 = F_78 ( V_92 -> V_128 , 2 ) ;
V_193 = & V_107 -> V_193 ;
V_194 = V_31 -> V_60 / V_92 -> V_126 ;
if ( V_31 -> V_140 < ( ( V_92 -> V_128 + 4 ) * V_194 ) ) {
V_38 = - V_150 ;
goto V_198;
}
V_193 -> V_199 = ( V_92 -> V_128 * V_194 ) ;
V_92 -> V_193 = V_193 ;
V_92 -> V_108 = V_107 ;
return 0 ;
V_198:
F_79 ( V_107 ) ;
return V_38 ;
}
static void F_80 ( struct V_121 * V_92 )
{
F_79 ( V_92 -> V_108 ) ;
}
static int F_81 ( struct V_30 * V_31 ,
struct V_121 * V_92 ,
struct V_182 * V_183 )
{
struct V_192 * V_193 ;
int V_194 ;
int V_143 , V_200 ;
int V_38 ;
V_38 = F_76 ( V_31 , V_92 , V_183 ) ;
if ( V_38 )
return V_38 ;
V_92 -> V_201 = F_60 ;
V_92 -> V_202 = F_61 ;
V_193 = V_92 -> V_193 ;
V_194 = V_31 -> V_60 / V_92 -> V_126 ;
for ( V_143 = 0 ; V_143 < V_194 ; V_143 ++ ) {
if ( V_143 ) {
V_193 -> V_203 [ V_143 ] . V_138 =
V_193 -> V_203 [ V_143 - 1 ] . V_138 +
V_193 -> V_203 [ V_143 - 1 ] . V_204 +
V_92 -> V_128 ;
V_193 -> V_203 [ V_143 ] . V_204 = 4 ;
} else {
V_193 -> V_203 [ V_143 ] . V_204 = 2 ;
V_193 -> V_203 [ V_143 ] . V_138 = 2 ;
}
for ( V_200 = 0 ; V_200 < V_92 -> V_128 ; V_200 ++ )
V_193 -> V_205 [ ( V_92 -> V_128 * V_143 ) + V_200 ] =
V_193 -> V_203 [ V_143 ] . V_138 +
V_193 -> V_203 [ V_143 ] . V_204 + V_200 ;
}
if ( V_31 -> V_140 > ( V_92 -> V_128 + 4 ) * V_194 ) {
V_193 -> V_203 [ V_194 ] . V_138 =
V_193 -> V_203 [ V_194 - 1 ] . V_138 +
V_193 -> V_203 [ V_194 - 1 ] . V_204 +
V_92 -> V_128 ;
V_193 -> V_203 [ V_194 ] . V_204 = V_31 -> V_140 -
( ( V_92 -> V_128 + 4 ) * V_194 ) ;
}
return 0 ;
}
static int F_82 ( struct V_30 * V_31 ,
struct V_121 * V_92 ,
struct V_182 * V_183 )
{
struct V_192 * V_193 ;
int V_194 ;
int V_143 ;
int V_38 ;
V_38 = F_76 ( V_31 , V_92 , V_183 ) ;
if ( V_38 )
return V_38 ;
V_92 -> V_206 = 4 ;
V_92 -> V_201 = F_62 ;
V_92 -> V_202 = F_63 ;
V_193 = V_92 -> V_193 ;
V_194 = V_31 -> V_60 / V_92 -> V_126 ;
for ( V_143 = 0 ; V_143 < ( V_92 -> V_128 * V_194 ) ; V_143 ++ )
V_193 -> V_205 [ V_143 ] = V_143 ;
V_193 -> V_203 [ 0 ] . V_204 = V_31 -> V_140 - V_143 ;
V_193 -> V_203 [ 0 ] . V_138 = V_143 ;
return 0 ;
}
static void F_83 ( struct V_121 * V_92 )
{
switch ( V_92 -> V_113 ) {
case V_207 :
case V_208 :
F_80 ( V_92 ) ;
break;
case V_209 :
F_79 ( V_92 -> V_193 ) ;
default:
break;
}
}
static int F_84 ( struct V_30 * V_31 , struct V_121 * V_92 ,
struct V_182 * V_183 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
int V_38 ;
if ( ! V_92 -> V_126 ) {
V_92 -> V_126 = V_3 -> V_210 ;
V_92 -> V_133 = V_3 -> V_211 ;
}
if ( ! V_92 -> V_126 || ! V_92 -> V_133 )
return - V_150 ;
switch ( V_92 -> V_113 ) {
case V_212 :
break;
case V_207 :
V_38 = F_81 ( V_31 , V_92 , V_183 ) ;
if ( V_38 )
return V_38 ;
break;
case V_208 :
V_38 = F_82 ( V_31 , V_92 , V_183 ) ;
if ( V_38 )
return V_38 ;
break;
case V_209 :
V_92 -> V_193 = F_77 ( sizeof( * V_92 -> V_193 ) , V_195 ) ;
if ( ! V_92 -> V_193 )
return - V_196 ;
V_92 -> V_193 -> V_203 [ 0 ] . V_204 = V_31 -> V_140 ;
case V_213 :
break;
default:
return - V_150 ;
}
return 0 ;
}
static int F_85 ( struct V_214 * V_22 , struct V_4 * V_10 ,
struct V_182 * V_183 )
{
const struct V_151 * V_152 ;
struct V_1 * V_48 ;
struct V_30 * V_31 ;
struct V_2 * V_3 ;
int V_52 ;
int V_38 ;
int V_143 ;
T_2 V_72 ;
if ( ! F_86 ( V_183 , L_10 , & V_52 ) )
return - V_150 ;
V_52 /= sizeof( T_2 ) ;
if ( ! V_52 ) {
F_12 ( V_22 , L_11 ) ;
return - V_150 ;
}
V_48 = F_87 ( V_22 ,
sizeof( * V_48 ) +
( V_52 * sizeof( struct V_49 ) ) ,
V_195 ) ;
if ( ! V_48 ) {
F_12 ( V_22 , L_12 ) ;
return - V_196 ;
}
V_48 -> V_52 = V_52 ;
V_48 -> V_39 = - 1 ;
for ( V_143 = 0 ; V_143 < V_52 ; V_143 ++ ) {
V_38 = F_88 ( V_183 , L_10 , V_143 , & V_72 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_13 ,
V_38 ) ;
return V_38 ;
}
if ( V_72 > V_215 ) {
F_12 ( V_22 ,
L_14 ,
V_72 ) ;
return - V_150 ;
}
if ( F_89 ( V_72 , & V_10 -> V_216 ) ) {
F_12 ( V_22 , L_15 , V_72 ) ;
return - V_150 ;
}
V_48 -> V_40 [ V_143 ] . V_57 = V_72 ;
if ( ! F_88 ( V_183 , L_16 , V_143 , & V_72 ) &&
V_72 < 2 ) {
V_48 -> V_40 [ V_143 ] . V_34 . type = V_41 ;
V_48 -> V_40 [ V_143 ] . V_34 . V_42 . V_43 = V_72 ;
} else {
V_38 = F_90 ( V_183 , L_17 , V_143 ) ;
if ( V_38 >= 0 ) {
V_72 = V_38 ;
V_48 -> V_40 [ V_143 ] . V_34 . type = V_45 ;
V_48 -> V_40 [ V_143 ] . V_34 . V_42 . V_46 = V_72 ;
V_38 = F_91 ( V_22 , V_72 , L_18 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_92 ( V_72 ) ;
if ( V_38 )
return V_38 ;
} else {
V_48 -> V_40 [ V_143 ] . V_34 . type = V_47 ;
}
}
}
V_152 = F_73 ( 0 ) ;
if ( F_74 ( V_152 ) ) {
V_38 = F_75 ( V_152 ) ;
F_12 ( V_22 ,
L_19 ,
V_38 ) ;
return V_38 ;
}
V_38 = F_66 ( V_48 , V_152 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_20 , V_38 ) ;
return V_38 ;
}
V_3 = & V_48 -> V_3 ;
V_3 -> V_217 = 200 ;
V_3 -> V_7 = & V_10 -> V_7 ;
V_3 -> V_92 . V_113 = V_207 ;
F_93 ( V_3 , V_183 ) ;
V_3 -> V_188 = F_20 ;
V_3 -> V_218 = F_31 ;
V_3 -> V_132 = F_25 ;
V_3 -> V_219 = F_28 ;
V_3 -> V_220 = F_30 ;
V_31 = F_70 ( V_3 ) ;
V_31 -> V_22 . V_221 = V_22 ;
V_38 = F_94 ( V_31 , V_52 , NULL ) ;
if ( V_38 )
return V_38 ;
if ( V_3 -> V_222 & V_223 )
V_3 -> V_222 |= V_224 ;
if ( V_3 -> V_101 & V_102 )
V_3 -> V_101 |= V_225 ;
V_38 = F_69 ( V_48 , V_183 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_20 , V_38 ) ;
return V_38 ;
}
V_38 = F_84 ( V_31 , & V_3 -> V_92 , V_183 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_21 , V_38 ) ;
return V_38 ;
}
V_38 = F_95 ( V_31 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_22 , V_38 ) ;
return V_38 ;
}
V_38 = F_96 ( V_31 , NULL , 0 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_23 , V_38 ) ;
F_97 ( V_31 ) ;
return V_38 ;
}
F_98 ( & V_48 -> V_226 , & V_10 -> V_227 ) ;
return 0 ;
}
static int F_99 ( struct V_214 * V_22 , struct V_4 * V_10 )
{
struct V_182 * V_183 = V_22 -> V_228 ;
struct V_182 * V_229 ;
int V_230 = F_100 ( V_183 ) ;
int V_38 ;
if ( V_230 > 8 ) {
F_12 ( V_22 , L_24 , V_230 ) ;
return - V_150 ;
}
F_101 (np, nand_np) {
V_38 = F_85 ( V_22 , V_10 , V_229 ) ;
if ( V_38 ) {
F_102 ( V_229 ) ;
return V_38 ;
}
}
return 0 ;
}
static void F_103 ( struct V_4 * V_10 )
{
struct V_1 * V_48 ;
while ( ! F_104 ( & V_10 -> V_227 ) ) {
V_48 = F_105 ( & V_10 -> V_227 , struct V_1 ,
V_226 ) ;
F_97 ( F_70 ( & V_48 -> V_3 ) ) ;
F_83 ( & V_48 -> V_3 . V_92 ) ;
F_106 ( & V_48 -> V_226 ) ;
}
}
static int F_107 ( struct V_231 * V_232 )
{
struct V_214 * V_22 = & V_232 -> V_22 ;
struct V_233 * V_234 ;
struct V_4 * V_10 ;
int V_8 ;
int V_38 ;
V_10 = F_87 ( V_22 , sizeof( * V_10 ) , V_195 ) ;
if ( ! V_10 )
return - V_196 ;
V_10 -> V_22 = V_22 ;
F_108 ( & V_10 -> V_7 . V_235 ) ;
F_109 ( & V_10 -> V_7 . V_236 ) ;
F_110 ( & V_10 -> V_227 ) ;
V_234 = F_111 ( V_232 , V_237 , 0 ) ;
V_10 -> V_12 = F_112 ( V_22 , V_234 ) ;
if ( F_74 ( V_10 -> V_12 ) )
return F_75 ( V_10 -> V_12 ) ;
V_8 = F_113 ( V_232 , 0 ) ;
if ( V_8 < 0 ) {
F_12 ( V_22 , L_25 ) ;
return V_8 ;
}
V_10 -> V_238 = F_114 ( V_22 , L_26 ) ;
if ( F_74 ( V_10 -> V_238 ) ) {
F_12 ( V_22 , L_27 ) ;
return F_75 ( V_10 -> V_238 ) ;
}
V_38 = F_115 ( V_10 -> V_238 ) ;
if ( V_38 )
return V_38 ;
V_10 -> V_63 = F_114 ( V_22 , L_28 ) ;
if ( F_74 ( V_10 -> V_63 ) ) {
F_12 ( V_22 , L_29 ) ;
V_38 = F_75 ( V_10 -> V_63 ) ;
goto V_239;
}
V_38 = F_115 ( V_10 -> V_63 ) ;
if ( V_38 )
goto V_239;
V_38 = F_15 ( V_10 ) ;
if ( V_38 )
goto V_240;
F_7 ( 0 , V_10 -> V_12 + V_15 ) ;
V_38 = F_116 ( V_22 , V_8 , F_4 ,
0 , L_30 , V_10 ) ;
if ( V_38 )
goto V_240;
F_117 ( V_232 , V_10 ) ;
V_38 = F_99 ( V_22 , V_10 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_31 ) ;
goto V_240;
}
return 0 ;
V_240:
F_118 ( V_10 -> V_63 ) ;
V_239:
F_118 ( V_10 -> V_238 ) ;
return V_38 ;
}
static int F_119 ( struct V_231 * V_232 )
{
struct V_4 * V_10 = F_120 ( V_232 ) ;
F_103 ( V_10 ) ;
return 0 ;
}
