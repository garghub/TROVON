static unsigned char F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return ( V_1 << 5 ) | ( V_2 << 3 ) |
( ( V_3 & 030 ) << 3 ) | ( V_3 & 007 ) ;
}
static unsigned char F_2 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 ) ;
}
static unsigned char F_3 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 ) ;
}
static inline const struct V_4 *
F_4 ( const struct V_5 * V_6 )
{
return & V_7 [ V_6 -> V_8 ] ;
}
static inline const struct V_4 *
F_5 ( struct V_9 * V_10 )
{
return F_4 ( F_6 ( V_10 ) ) ;
}
static inline bool F_7 ( const struct V_5 * V_6 )
{
return V_11 && V_6 -> V_12 == V_13 ;
}
static inline bool F_8 ( const struct V_5 * V_6 )
{
return V_14 && V_6 -> V_12 == V_15 ;
}
static unsigned char F_9 ( struct V_9 * V_10 ,
unsigned int V_16 )
{
const struct V_5 * V_17 = F_6 ( V_10 ) ;
struct V_18 * V_19 = V_10 -> V_20 ;
V_16 <<= V_17 -> V_21 ;
if ( V_19 -> V_22 . V_23 == V_24 )
return F_10 ( V_19 -> V_22 . V_25 . V_26 + V_16 ) ;
else
return F_11 ( V_19 -> V_22 . V_25 . V_27 + V_16 ) ;
}
static void F_12 ( struct V_9 * V_10 , unsigned int V_16 ,
unsigned char V_28 )
{
const struct V_5 * V_17 = F_6 ( V_10 ) ;
struct V_18 * V_19 = V_10 -> V_20 ;
V_16 <<= V_17 -> V_21 ;
if ( V_19 -> V_22 . V_23 == V_24 )
F_13 ( V_28 , V_19 -> V_22 . V_25 . V_26 + V_16 ) ;
else
F_14 ( V_28 , V_19 -> V_22 . V_25 . V_27 + V_16 ) ;
}
static unsigned int F_15 ( struct V_9 * V_10 ,
unsigned int V_16 )
{
const struct V_5 * V_17 = F_6 ( V_10 ) ;
struct V_18 * V_19 = V_10 -> V_20 ;
V_16 <<= V_17 -> V_21 ;
if ( V_19 -> V_22 . V_23 == V_24 )
return F_16 ( V_19 -> V_22 . V_25 . V_26 + V_16 ) ;
else
return F_17 ( V_19 -> V_22 . V_25 . V_27 + V_16 ) ;
}
static void F_18 ( struct V_9 * V_10 , unsigned int V_16 ,
unsigned int V_28 )
{
const struct V_5 * V_17 = F_6 ( V_10 ) ;
struct V_18 * V_19 = V_10 -> V_20 ;
V_16 <<= V_17 -> V_21 ;
if ( V_19 -> V_22 . V_23 == V_24 )
F_19 ( V_28 , V_19 -> V_22 . V_25 . V_26 + V_16 ) ;
else
F_20 ( V_28 , V_19 -> V_22 . V_25 . V_27 + V_16 ) ;
}
static const struct V_5 *
F_21 ( struct V_29 * V_29 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_22 ( V_31 ) ; V_30 ++ )
if ( F_7 ( & V_31 [ V_30 ] ) &&
V_29 -> V_32 == V_31 [ V_30 ] . V_33 )
return & V_31 [ V_30 ] ;
return NULL ;
}
static int
F_23 ( struct V_9 * V_10 ,
unsigned long V_34 , unsigned long V_35 )
{
if ( ! V_34 || ! F_24 ( V_34 , V_35 , V_36 ) ) {
F_25 ( V_10 -> V_37 , L_1 ,
V_34 , V_35 ) ;
return - V_38 ;
}
return 0 ;
}
static int
F_26 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_41 * V_42 , unsigned int * V_43 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_44 * V_45 = V_40 -> V_20 ;
if ( V_8 -> V_46 ) {
V_43 [ 1 ] = F_9 ( V_10 , V_45 -> V_47 ) & V_45 -> V_48 ;
} else {
V_43 [ 0 ] = 0 ;
}
return V_42 -> V_49 ;
}
static void F_27 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_44 * V_45 = V_40 -> V_20 ;
V_45 -> V_50 = 0 ;
V_45 -> V_51 = 0 ;
if ( V_8 -> V_46 )
F_12 ( V_10 , V_45 -> V_47 , 0 ) ;
}
static int F_28 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
unsigned int V_49 ;
unsigned V_52 ;
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_44 * V_45 = V_40 -> V_20 ;
struct V_53 * V_54 = & V_40 -> V_55 -> V_54 ;
int V_56 = 0 ;
if ( ! V_45 -> V_57 && V_45 -> V_58 == 0 ) {
V_40 -> V_55 -> V_59 |= V_60 ;
V_45 -> V_50 = 0 ;
V_56 = 1 ;
} else {
V_52 = 0 ;
if ( V_54 -> V_61 ) {
for ( V_49 = 0 ; V_49 < V_54 -> V_62 ; V_49 ++ )
V_52 |= ( 1U << F_29 ( V_54 -> V_61 [ V_49 ] ) ) ;
}
V_52 &= V_45 -> V_48 ;
V_45 -> V_51 = V_52 ;
if ( V_8 -> V_46 )
F_12 ( V_10 , V_45 -> V_47 , V_52 ) ;
}
return V_56 ;
}
static int
F_30 ( struct V_9 * V_10 , struct V_39 * V_40 ,
unsigned int V_63 )
{
struct V_44 * V_45 ;
unsigned long V_64 ;
int V_65 = 0 ;
if ( V_63 != 0 )
return - V_66 ;
V_45 = V_40 -> V_20 ;
F_31 ( & V_45 -> V_67 , V_64 ) ;
V_40 -> V_55 -> V_68 = NULL ;
if ( V_45 -> V_50 )
V_65 = F_28 ( V_10 , V_40 ) ;
F_32 ( & V_45 -> V_67 , V_64 ) ;
if ( V_65 )
F_33 ( V_10 , V_40 ) ;
return 1 ;
}
static int F_34 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_44 * V_45 = V_40 -> V_20 ;
unsigned V_69 ;
unsigned V_70 ;
unsigned V_71 ;
unsigned int V_72 ;
unsigned long V_64 ;
V_69 = 0 ;
F_31 ( & V_45 -> V_67 , V_64 ) ;
V_72 = V_40 -> V_55 -> V_59 ;
if ( V_8 -> V_46 ) {
V_71 = V_45 -> V_51 ;
while ( ( V_70 = ( F_9 ( V_10 , V_45 -> V_47 ) &
V_45 -> V_48 & ~ V_69 ) ) != 0 ) {
V_69 |= V_70 ;
V_71 &= ~ V_69 ;
F_12 ( V_10 , V_45 -> V_47 , V_71 ) ;
}
} else {
V_69 = V_45 -> V_51 ;
}
if ( V_69 ) {
V_71 = V_45 -> V_51 ;
if ( V_8 -> V_46 )
F_12 ( V_10 , V_45 -> V_47 , V_71 ) ;
if ( V_45 -> V_50 ) {
if ( V_69 & V_45 -> V_51 ) {
short V_28 ;
unsigned int V_49 , V_73 , V_74 ;
V_28 = 0 ;
V_74 = V_40 -> V_55 -> V_54 . V_62 ;
for ( V_49 = 0 ; V_49 < V_74 ; V_49 ++ ) {
V_73 = F_29 ( V_40 -> V_55 -> V_54 . V_61 [ V_49 ] ) ;
if ( V_69 & ( 1U << V_73 ) )
V_28 |= ( 1U << V_49 ) ;
}
if ( F_35 ( V_40 -> V_55 , V_28 ) ) {
V_40 -> V_55 -> V_59 |= ( V_75 |
V_76 ) ;
} else {
F_27 ( V_10 , V_40 ) ;
V_40 -> V_55 -> V_59 |= V_77
| V_78 ;
F_36 ( V_10 , L_2 ) ;
}
if ( ! V_45 -> V_57 ) {
if ( V_45 -> V_58 > 0 ) {
V_45 -> V_58 -- ;
if ( V_45 -> V_58 == 0 ) {
V_40 -> V_55 -> V_59 |=
V_60 ;
F_27 ( V_10 ,
V_40 ) ;
}
}
}
}
}
}
F_32 ( & V_45 -> V_67 , V_64 ) ;
if ( V_72 != V_40 -> V_55 -> V_59 )
F_33 ( V_10 , V_40 ) ;
return ( V_69 != 0 ) ;
}
static int F_37 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
struct V_44 * V_45 = V_40 -> V_20 ;
unsigned long V_64 ;
F_31 ( & V_45 -> V_67 , V_64 ) ;
if ( V_45 -> V_50 )
F_27 ( V_10 , V_40 ) ;
F_32 ( & V_45 -> V_67 , V_64 ) ;
return 0 ;
}
static int
F_38 ( struct V_9 * V_10 ,
struct V_39 * V_40 , struct V_53 * V_54 )
{
int V_79 = 0 ;
V_79 |= F_39 ( & V_54 -> V_80 , V_81 | V_82 ) ;
V_79 |= F_39 ( & V_54 -> V_83 , V_84 ) ;
V_79 |= F_39 ( & V_54 -> V_85 , V_81 ) ;
V_79 |= F_39 ( & V_54 -> V_86 , V_87 ) ;
V_79 |= F_39 ( & V_54 -> V_88 , V_87 | V_89 ) ;
if ( V_79 )
return 1 ;
V_79 |= F_40 ( V_54 -> V_80 ) ;
V_79 |= F_40 ( V_54 -> V_88 ) ;
if ( V_79 )
return 2 ;
V_79 |= F_41 ( & V_54 -> V_90 , 0 ) ;
V_79 |= F_41 ( & V_54 -> V_91 , 0 ) ;
V_79 |= F_41 ( & V_54 -> V_92 , 0 ) ;
V_79 |= F_41 ( & V_54 -> V_93 , V_54 -> V_62 ) ;
switch ( V_54 -> V_88 ) {
case V_87 :
break;
case V_89 :
V_79 |= F_41 ( & V_54 -> V_94 , 0 ) ;
break;
default:
break;
}
if ( V_79 )
return 3 ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
struct V_53 * V_54 = & V_40 -> V_55 -> V_54 ;
struct V_44 * V_45 = V_40 -> V_20 ;
unsigned long V_64 ;
int V_65 = 0 ;
F_31 ( & V_45 -> V_67 , V_64 ) ;
V_45 -> V_50 = 1 ;
switch ( V_54 -> V_88 ) {
case V_87 :
V_45 -> V_57 = 0 ;
V_45 -> V_58 = V_54 -> V_94 ;
break;
default:
V_45 -> V_57 = 1 ;
V_45 -> V_58 = 0 ;
break;
}
switch ( V_54 -> V_80 ) {
case V_82 :
V_40 -> V_55 -> V_68 = F_30 ;
break;
default:
V_65 = F_28 ( V_10 , V_40 ) ;
break;
}
F_32 ( & V_45 -> V_67 , V_64 ) ;
if ( V_65 )
F_33 ( V_10 , V_40 ) ;
return 0 ;
}
static int
F_43 ( struct V_9 * V_10 , struct V_39 * V_40 ,
unsigned int V_16 , unsigned V_48 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_44 * V_45 ;
V_45 = F_44 ( sizeof( * V_45 ) , V_95 ) ;
if ( ! V_45 ) {
F_25 ( V_10 -> V_37 , L_3 ) ;
return - V_96 ;
}
V_45 -> V_47 = V_16 ;
V_45 -> V_48 = V_48 ;
F_45 ( & V_45 -> V_67 ) ;
if ( V_8 -> V_46 )
F_12 ( V_10 , V_45 -> V_47 , 0 ) ;
V_40 -> V_20 = V_45 ;
V_40 -> type = V_97 ;
V_40 -> V_98 = V_99 | V_100 ;
if ( V_8 -> V_46 ) {
V_40 -> V_101 = V_102 ;
V_40 -> V_103 = V_102 ;
} else {
V_40 -> V_101 = 1 ;
V_40 -> V_103 = 1 ;
}
V_40 -> V_104 = & V_105 ;
V_40 -> V_106 = 1 ;
V_40 -> V_107 = F_26 ;
V_40 -> V_108 = F_38 ;
V_40 -> V_109 = F_42 ;
V_40 -> V_110 = F_37 ;
return 0 ;
}
static void
F_46 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
struct V_44 * V_45 = V_40 -> V_20 ;
F_47 ( V_45 ) ;
}
static T_1 F_48 ( int V_111 , void * V_112 )
{
struct V_9 * V_10 = V_112 ;
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_39 * V_40 ;
int V_113 ;
if ( ! V_10 -> V_114 )
return V_115 ;
if ( V_19 -> V_116 >= 0 ) {
V_40 = & V_10 -> V_117 [ V_19 -> V_116 ] ;
V_113 = F_34 ( V_10 , V_40 ) ;
} else {
V_113 = 0 ;
}
return F_49 ( V_113 ) ;
}
static unsigned int
F_50 ( struct V_9 * V_10 ,
struct V_39 * V_40 , unsigned int V_2 )
{
struct V_118 * V_45 = V_40 -> V_20 ;
unsigned int V_28 ;
V_28 = V_2 << 6 ;
F_12 ( V_10 , V_45 -> V_47 + V_119 , V_28 ) ;
V_28 = F_9 ( V_10 , V_45 -> V_47 + V_2 ) ;
V_28 += F_9 ( V_10 , V_45 -> V_47 + V_2 ) << 8 ;
return V_28 ;
}
static void
F_51 ( struct V_9 * V_10 ,
struct V_39 * V_40 , unsigned int V_2 ,
unsigned int V_120 )
{
struct V_118 * V_45 = V_40 -> V_20 ;
F_12 ( V_10 , V_45 -> V_47 + V_2 , V_120 & 0xff ) ;
F_12 ( V_10 , V_45 -> V_47 + V_2 , ( V_120 >> 8 ) & 0xff ) ;
}
static void
F_52 ( struct V_9 * V_10 ,
struct V_39 * V_40 , unsigned int V_2 ,
unsigned int V_121 )
{
struct V_118 * V_45 = V_40 -> V_20 ;
unsigned int V_122 ;
V_122 = V_2 << 6 ;
V_122 |= 0x30 ;
V_122 |= ( V_121 & 0xf ) ;
F_12 ( V_10 , V_45 -> V_47 + V_119 , V_122 ) ;
}
static unsigned int
F_53 ( struct V_9 * V_10 ,
struct V_39 * V_40 , unsigned int V_2 )
{
struct V_118 * V_45 = V_40 -> V_20 ;
F_12 ( V_10 , V_45 -> V_47 + V_119 ,
0xe0 | ( 2 << V_2 ) ) ;
return F_9 ( V_10 , V_45 -> V_47 + V_2 ) ;
}
static int
F_54 ( struct V_9 * V_10 , struct V_39 * V_40 ,
struct V_41 * V_42 , unsigned int * V_43 )
{
struct V_118 * V_45 = V_40 -> V_20 ;
int V_2 = F_29 ( V_42 -> V_123 ) ;
unsigned int V_49 ;
unsigned long V_64 ;
for ( V_49 = 0 ; V_49 < V_42 -> V_49 ; V_49 ++ ) {
F_31 ( & V_45 -> V_67 , V_64 ) ;
V_43 [ V_49 ] = F_50 ( V_10 , V_40 , V_2 ) ;
F_32 ( & V_45 -> V_67 , V_64 ) ;
}
return V_42 -> V_49 ;
}
static int
F_55 ( struct V_9 * V_10 , struct V_39 * V_40 ,
struct V_41 * V_42 , unsigned int * V_43 )
{
struct V_118 * V_45 = V_40 -> V_20 ;
int V_2 = F_29 ( V_42 -> V_123 ) ;
unsigned int V_49 ;
unsigned long V_64 ;
for ( V_49 = 0 ; V_49 < V_42 -> V_49 ; V_49 ++ ) {
F_31 ( & V_45 -> V_67 , V_64 ) ;
F_51 ( V_10 , V_40 , V_2 , V_43 [ V_49 ] ) ;
F_32 ( & V_45 -> V_67 , V_64 ) ;
}
return V_42 -> V_49 ;
}
static int
F_56 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
unsigned int V_124 ,
unsigned int V_125 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_118 * V_45 = V_40 -> V_20 ;
unsigned char V_122 ;
if ( ! V_8 -> V_126 )
return - 1 ;
if ( V_124 > 2 )
return - 1 ;
if ( V_125 > ( V_8 -> V_127 ? 31 : 7 ) )
return - 1 ;
V_45 -> V_125 [ V_124 ] = V_125 ;
V_122 = F_3 ( V_45 -> V_1 , V_124 , V_125 ) ;
F_12 ( V_10 , V_45 -> V_128 , V_122 ) ;
return 0 ;
}
static int
F_57 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
unsigned int V_124 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_118 * V_45 = V_40 -> V_20 ;
if ( ! V_8 -> V_126 )
return - 1 ;
if ( V_124 > 2 )
return - 1 ;
return V_45 -> V_125 [ V_124 ] ;
}
static int
F_58 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
unsigned int V_124 ,
unsigned int V_129 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_118 * V_45 = V_40 -> V_20 ;
unsigned char V_122 ;
if ( ! V_8 -> V_126 )
return - 1 ;
if ( V_124 > 2 )
return - 1 ;
if ( V_129 > ( V_8 -> V_127 ? 31 : 7 ) )
return - 1 ;
V_45 -> V_129 [ V_124 ] = V_129 ;
V_122 = F_2 ( V_45 -> V_1 , V_124 , V_129 ) ;
F_12 ( V_10 , V_45 -> V_130 , V_122 ) ;
return 0 ;
}
static int
F_59 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
unsigned int V_124 ,
unsigned int * V_131 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_118 * V_45 = V_40 -> V_20 ;
unsigned V_129 ;
if ( ! V_8 -> V_126 )
return - 1 ;
if ( V_124 > 2 )
return - 1 ;
V_129 = V_45 -> V_129 [ V_124 ] ;
* V_131 = V_132 [ V_129 ] ;
return V_129 ;
}
static int
F_60 ( struct V_9 * V_10 , struct V_39 * V_40 ,
struct V_41 * V_42 , unsigned int * V_43 )
{
struct V_118 * V_45 = V_40 -> V_20 ;
int V_133 = 0 ;
int V_2 = F_29 ( V_42 -> V_123 ) ;
unsigned long V_64 ;
F_31 ( & V_45 -> V_67 , V_64 ) ;
switch ( V_43 [ 0 ] ) {
case V_134 :
if ( V_43 [ 1 ] > ( V_135 | V_136 ) )
V_133 = - V_66 ;
else
F_52 ( V_10 , V_40 , V_2 , V_43 [ 1 ] ) ;
break;
case V_137 :
V_43 [ 1 ] = F_53 ( V_10 , V_40 , V_2 ) ;
break;
case V_138 :
V_133 = F_56 ( V_10 , V_40 , V_2 , V_43 [ 2 ] ) ;
if ( V_133 < 0 )
V_133 = - V_66 ;
break;
case V_139 :
V_133 = F_57 ( V_10 , V_40 , V_2 ) ;
if ( V_133 < 0 ) {
V_133 = - V_66 ;
break;
}
V_43 [ 2 ] = V_133 ;
break;
case V_140 :
V_133 = F_58 ( V_10 , V_40 , V_2 , V_43 [ 1 ] ) ;
if ( V_133 < 0 )
V_133 = - V_66 ;
break;
case V_141 :
V_133 = F_59 ( V_10 , V_40 , V_2 , & V_43 [ 2 ] ) ;
if ( V_133 < 0 ) {
V_133 = - V_66 ;
break;
}
V_43 [ 1 ] = V_133 ;
break;
default:
V_133 = - V_66 ;
break;
}
F_32 ( & V_45 -> V_67 , V_64 ) ;
return V_133 < 0 ? V_133 : V_42 -> V_49 ;
}
static int
F_61 ( struct V_9 * V_10 , struct V_39 * V_40 ,
unsigned int V_16 )
{
const struct V_4 * V_8 = F_5 ( V_10 ) ;
struct V_118 * V_45 ;
unsigned int V_2 ;
V_45 = F_44 ( sizeof( * V_45 ) , V_95 ) ;
if ( ! V_45 ) {
F_25 ( V_10 -> V_37 , L_3 ) ;
return - V_96 ;
}
V_40 -> V_20 = V_45 ;
V_40 -> type = V_142 ;
V_40 -> V_98 = V_143 | V_99 ;
V_40 -> V_101 = 3 ;
V_40 -> V_106 = 0xFFFF ;
V_40 -> V_144 = F_54 ;
V_40 -> V_145 = F_55 ;
V_40 -> V_146 = F_60 ;
F_45 ( & V_45 -> V_67 ) ;
V_45 -> V_47 = V_16 ;
if ( V_8 -> V_126 ) {
V_45 -> V_130 = V_147 + ( V_16 >> 3 ) ;
V_45 -> V_128 = V_148 + ( V_16 >> 3 ) ;
V_45 -> V_1 = ( V_16 >> 2 ) & 1 ;
}
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
F_52 ( V_10 , V_40 , V_2 ,
V_149 | V_136 ) ;
if ( V_8 -> V_126 ) {
F_56 ( V_10 , V_40 , V_2 , 0 ) ;
F_58 ( V_10 , V_40 , V_2 , 0 ) ;
}
}
return 0 ;
}
static void
F_62 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
struct V_44 * V_45 = V_40 -> V_20 ;
F_47 ( V_45 ) ;
}
static void F_63 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
struct V_150 * V_45 = V_40 -> V_20 ;
int V_151 ;
V_151 = V_152 ;
if ( ! ( V_40 -> V_153 & 0x0000ff ) )
V_151 |= V_154 ;
if ( ! ( V_40 -> V_153 & 0x00ff00 ) )
V_151 |= V_155 ;
if ( ! ( V_40 -> V_153 & 0x0f0000 ) )
V_151 |= V_156 ;
if ( ! ( V_40 -> V_153 & 0xf00000 ) )
V_151 |= V_157 ;
F_12 ( V_10 , V_45 -> V_47 + 3 , V_151 ) ;
}
static int F_64 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_41 * V_42 , unsigned int * V_43 )
{
struct V_150 * V_45 = V_40 -> V_20 ;
if ( V_43 [ 0 ] ) {
V_40 -> V_158 &= ~ V_43 [ 0 ] ;
V_40 -> V_158 |= ( V_43 [ 0 ] & V_43 [ 1 ] ) ;
if ( V_43 [ 0 ] & 0xff )
F_12 ( V_10 , V_45 -> V_47 , V_40 -> V_158 & 0xff ) ;
if ( V_43 [ 0 ] & 0xff00 )
F_12 ( V_10 , V_45 -> V_47 + 1 ,
( V_40 -> V_158 >> 8 ) & 0xff ) ;
if ( V_43 [ 0 ] & 0xff0000 )
F_12 ( V_10 , V_45 -> V_47 + 2 ,
( V_40 -> V_158 >> 16 ) & 0xff ) ;
}
V_43 [ 1 ] = F_9 ( V_10 , V_45 -> V_47 ) ;
V_43 [ 1 ] |= F_9 ( V_10 , V_45 -> V_47 + 1 ) << 8 ;
V_43 [ 1 ] |= F_9 ( V_10 , V_45 -> V_47 + 2 ) << 16 ;
return 2 ;
}
static int F_65 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned int * V_43 )
{
unsigned int V_159 ;
unsigned int V_160 ;
V_159 = 1 << F_29 ( V_42 -> V_123 ) ;
if ( V_159 & 0x0000ff )
V_160 = 0x0000ff ;
else if ( V_159 & 0x00ff00 )
V_160 = 0x00ff00 ;
else if ( V_159 & 0x0f0000 )
V_160 = 0x0f0000 ;
else
V_160 = 0xf00000 ;
switch ( V_43 [ 0 ] ) {
case V_161 :
V_40 -> V_153 &= ~ V_160 ;
break;
case V_162 :
V_40 -> V_153 |= V_160 ;
break;
case V_163 :
V_43 [ 1 ] = ( V_40 -> V_153 & V_160 ) ? V_164 : V_165 ;
return V_42 -> V_49 ;
break;
default:
return - V_66 ;
}
F_63 ( V_10 , V_40 ) ;
return 1 ;
}
static int F_66 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
unsigned int V_16 )
{
struct V_150 * V_45 ;
V_45 = F_44 ( sizeof( * V_45 ) , V_95 ) ;
if ( ! V_45 )
return - V_96 ;
V_45 -> V_47 = V_16 ;
V_40 -> V_20 = V_45 ;
V_40 -> type = V_166 ;
V_40 -> V_98 = V_99 | V_143 ;
V_40 -> V_101 = 24 ;
V_40 -> V_104 = & V_105 ;
V_40 -> V_106 = 1 ;
V_40 -> V_107 = F_64 ;
V_40 -> V_146 = F_65 ;
V_40 -> V_158 = 0 ;
V_40 -> V_153 = 0 ;
F_63 ( V_10 , V_40 ) ;
return 0 ;
}
static void F_67 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
struct V_150 * V_45 = V_40 -> V_20 ;
F_47 ( V_45 ) ;
}
static int F_68 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned int * V_43 )
{
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < V_42 -> V_49 ; V_49 ++ )
V_43 [ V_49 ] = F_15 ( V_10 , V_167 ) ;
return V_49 ;
}
static void F_69 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
unsigned int clock ;
clock = F_15 ( V_10 , V_168 ) & V_169 ;
F_18 ( V_10 , V_168 , clock | V_170 ) ;
F_18 ( V_10 , V_168 , clock ) ;
}
static void F_70 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
unsigned int * V_171 ,
unsigned int * V_172 )
{
unsigned int V_173 ;
V_173 = F_15 ( V_10 , V_168 ) & V_169 ;
* V_171 = V_173 ;
* V_172 = ( V_173 < F_22 ( V_174 ) ) ?
V_174 [ V_173 ] : 0 ;
}
static int F_71 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
unsigned int V_171 )
{
if ( V_171 > V_175 )
return - V_66 ;
F_18 ( V_10 , V_168 , V_171 ) ;
return 0 ;
}
static int F_72 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned int * V_43 )
{
int V_133 = 0 ;
switch ( V_43 [ 0 ] ) {
case V_176 :
F_69 ( V_10 , V_40 ) ;
break;
case V_140 :
V_133 = F_71 ( V_10 , V_40 , V_43 [ 1 ] ) ;
if ( V_133 < 0 )
V_133 = - V_66 ;
break;
case V_141 :
F_70 ( V_10 , V_40 , & V_43 [ 1 ] , & V_43 [ 2 ] ) ;
break;
default:
V_133 = - V_66 ;
break;
}
return V_133 < 0 ? V_133 : V_42 -> V_49 ;
}
static int F_73 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
V_40 -> type = V_177 ;
V_40 -> V_98 = V_99 | V_178 ;
V_40 -> V_101 = 1 ;
V_40 -> V_106 = 0xFFFFFFFF ;
V_40 -> V_144 = F_68 ;
V_40 -> V_146 = F_72 ;
return 0 ;
}
static void F_74 ( struct V_9 * V_10 ,
struct V_39 * V_40 )
{
}
static int F_75 ( struct V_9 * V_10 )
{
struct V_29 * V_179 = F_76 ( V_10 ) ;
void T_2 * V_180 ;
T_3 V_181 ;
V_181 = F_77 ( V_179 , 0 ) ;
if ( V_181 < 0x4000 ||
! ( F_78 ( V_179 , 0 ) & V_182 ) ) {
F_25 ( V_10 -> V_37 , L_4 ) ;
return - V_66 ;
}
V_180 = F_79 ( F_80 ( V_179 , 0 ) , V_181 ) ;
if ( ! V_180 ) {
F_25 ( V_10 -> V_37 , L_5 ) ;
return - V_96 ;
}
F_20 ( 0x80 , V_180 + 0x50 ) ;
F_81 ( V_180 ) ;
F_12 ( V_10 , V_183 , 1 ) ;
return 0 ;
}
static void F_82 ( struct V_9 * V_10 , unsigned int V_111 )
{
const struct V_5 * V_17 = F_6 ( V_10 ) ;
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_29 * V_179 = F_76 ( V_10 ) ;
char V_184 [ 60 ] ;
int V_185 ;
if ( F_8 ( V_17 ) )
V_185 = F_83 ( V_184 , sizeof( V_184 ) ,
L_6 , V_19 -> V_22 . V_25 . V_26 ) ;
else if ( F_7 ( V_17 ) )
V_185 = F_83 ( V_184 , sizeof( V_184 ) ,
L_7 , F_84 ( V_179 ) ) ;
else
V_185 = 0 ;
if ( V_111 )
V_185 += F_83 ( & V_184 [ V_185 ] , sizeof( V_184 ) - V_185 ,
L_8 , V_111 ,
( V_10 -> V_111 ? L_9 : L_10 ) ) ;
else
V_185 += F_83 ( & V_184 [ V_185 ] , sizeof( V_184 ) - V_185 ,
L_11 ) ;
F_85 ( V_10 -> V_37 , L_12 , V_10 -> V_186 , V_184 ) ;
}
static int F_86 ( struct V_9 * V_10 , unsigned int V_111 ,
unsigned long V_187 )
{
const struct V_5 * V_17 = F_6 ( V_10 ) ;
struct V_18 * V_19 = V_10 -> V_20 ;
const struct V_4 * V_8 = F_4 ( V_17 ) ;
struct V_39 * V_40 ;
int V_188 ;
unsigned int V_49 ;
int V_133 ;
V_19 -> V_116 = - 1 ;
V_10 -> V_186 = V_17 -> V_189 ;
V_133 = F_87 ( V_10 , V_8 -> V_190 ) ;
if ( V_133 )
return V_133 ;
for ( V_49 = 0 ; V_49 < V_10 -> V_191 ; V_49 ++ ) {
V_40 = & V_10 -> V_117 [ V_49 ] ;
switch ( V_8 -> V_192 [ V_49 ] ) {
case V_193 :
V_133 = F_61 ( V_10 , V_40 ,
V_8 -> V_194 [ V_49 ] ) ;
if ( V_133 < 0 )
return V_133 ;
break;
case V_195 :
V_133 = F_66 ( V_10 , V_40 ,
V_8 -> V_194 [ V_49 ] ) ;
if ( V_133 < 0 )
return V_133 ;
break;
case V_196 :
if ( V_111 ) {
V_133 = F_43 ( V_10 , V_40 ,
V_197 ,
V_8 -> V_194 [ V_49 ]
) ;
if ( V_133 < 0 )
return V_133 ;
V_19 -> V_116 = V_49 ;
} else {
V_40 -> type = V_198 ;
}
break;
case V_199 :
if ( V_11 ) {
V_133 = F_73 ( V_10 , V_40 ) ;
if ( V_133 < 0 )
return V_133 ;
} else {
V_40 -> type = V_198 ;
}
break;
default:
V_40 -> type = V_198 ;
break;
}
}
V_188 = V_19 -> V_116 ;
if ( V_188 >= 0 && V_188 < V_10 -> V_191 )
V_10 -> V_200 = & V_10 -> V_117 [ V_188 ] ;
if ( V_111 ) {
if ( F_88 ( V_111 , F_48 , V_187 ,
V_36 , V_10 ) >= 0 ) {
V_10 -> V_111 = V_111 ;
} else {
F_89 ( V_10 -> V_37 ,
L_13 , V_111 ) ;
}
}
F_82 ( V_10 , V_111 ) ;
return 1 ;
}
static int F_90 ( struct V_9 * V_10 , struct V_201 * V_202 )
{
const struct V_5 * V_17 = F_6 ( V_10 ) ;
struct V_18 * V_19 ;
int V_133 ;
F_85 ( V_10 -> V_37 , V_36 L_14 ) ;
V_19 = F_44 ( sizeof( * V_19 ) , V_95 ) ;
if ( ! V_19 )
return - V_96 ;
V_10 -> V_20 = V_19 ;
if ( F_8 ( V_17 ) ) {
unsigned long V_26 ;
unsigned int V_111 ;
V_26 = V_202 -> V_203 [ 0 ] ;
V_111 = V_202 -> V_203 [ 1 ] ;
V_133 = F_23 ( V_10 , V_26 , V_17 -> V_204 ) ;
if ( V_133 < 0 )
return V_133 ;
V_19 -> V_22 . V_25 . V_26 = V_26 ;
V_19 -> V_22 . V_23 = V_24 ;
return F_86 ( V_10 , V_111 , 0 ) ;
} else if ( F_7 ( V_17 ) ) {
F_25 ( V_10 -> V_37 ,
L_15 ,
V_17 -> V_189 ) ;
return - V_38 ;
} else {
F_25 ( V_10 -> V_37 , V_36
L_16 ) ;
return - V_66 ;
}
}
static int F_91 ( struct V_9 * V_10 ,
unsigned long V_205 )
{
struct V_29 * V_29 = F_76 ( V_10 ) ;
const struct V_5 * V_17 ;
struct V_18 * V_19 ;
T_3 V_206 , V_74 ;
unsigned int V_207 ;
int V_133 ;
if ( ! V_11 )
return - V_66 ;
F_85 ( V_10 -> V_37 , V_36 L_17 ,
F_84 ( V_29 ) ) ;
V_19 = F_44 ( sizeof( * V_19 ) , V_95 ) ;
if ( ! V_19 )
return - V_96 ;
V_10 -> V_20 = V_19 ;
V_10 -> V_208 = F_21 ( V_29 ) ;
if ( V_10 -> V_208 == NULL ) {
F_25 ( V_10 -> V_37 , L_18 ) ;
return - V_66 ;
}
V_17 = F_6 ( V_10 ) ;
V_133 = F_92 ( V_29 , V_36 ) ;
if ( V_133 < 0 ) {
F_25 ( V_10 -> V_37 ,
L_19 ) ;
return V_133 ;
}
V_207 = V_17 -> V_209 ;
V_206 = F_80 ( V_29 , V_207 ) ;
V_74 = F_77 ( V_29 , V_207 ) ;
if ( V_74 < V_17 -> V_204 ) {
F_25 ( V_10 -> V_37 , L_20 ) ;
return - V_66 ;
}
if ( ( F_78 ( V_29 , V_207 ) & V_182 ) != 0 ) {
V_19 -> V_22 . V_25 . V_27 = F_79 ( V_206 , V_74 ) ;
if ( ! V_19 -> V_22 . V_25 . V_27 ) {
F_25 ( V_10 -> V_37 ,
L_21 ) ;
return - V_96 ;
}
V_19 -> V_22 . V_23 = V_210 ;
} else {
V_19 -> V_22 . V_25 . V_26 = ( unsigned long ) V_206 ;
V_19 -> V_22 . V_23 = V_24 ;
}
switch ( V_17 -> V_211 )
{
case V_212 :
case V_213 :
case V_214 :
V_133 = F_75 ( V_10 ) ;
if ( V_133 < 0 )
return V_133 ;
break;
default:
break;
}
return F_86 ( V_10 , V_29 -> V_111 , V_215 ) ;
}
static void F_93 ( struct V_9 * V_10 )
{
const struct V_5 * V_17 = F_6 ( V_10 ) ;
struct V_18 * V_19 = V_10 -> V_20 ;
const struct V_4 * V_8 ;
unsigned V_49 ;
if ( ! V_17 || ! V_19 )
return;
if ( V_10 -> V_111 )
F_94 ( V_10 -> V_111 , V_10 ) ;
if ( V_10 -> V_117 ) {
V_8 = F_4 ( V_17 ) ;
for ( V_49 = 0 ; V_49 < V_10 -> V_191 ; V_49 ++ ) {
struct V_39 * V_40 = & V_10 -> V_117 [ V_49 ] ;
switch ( V_8 -> V_192 [ V_49 ] ) {
case V_193 :
F_62 ( V_10 , V_40 ) ;
break;
case V_195 :
F_67 ( V_10 , V_40 ) ;
break;
case V_196 :
F_46 ( V_10 , V_40 ) ;
break;
case V_199 :
if ( V_11 )
F_74 ( V_10 , V_40 ) ;
break;
default:
break;
}
}
}
if ( F_8 ( V_17 ) ) {
if ( V_19 -> V_22 . V_23 == V_24 )
F_95 ( V_19 -> V_22 . V_25 . V_26 ,
V_17 -> V_204 ) ;
} else if ( F_7 ( V_17 ) ) {
struct V_29 * V_179 = F_76 ( V_10 ) ;
if ( V_179 ) {
if ( V_19 -> V_22 . V_23 != V_216 ) {
if ( V_19 -> V_22 . V_23 == V_210 )
F_81 ( V_19 -> V_22 . V_25 . V_27 ) ;
F_96 ( V_179 ) ;
}
}
}
}
static int F_97 ( struct V_29 * V_10 ,
const struct V_217
* V_218 )
{
return F_98 ( V_10 , & V_219 ) ;
}
static void F_99 ( struct V_29 * V_10 )
{
F_100 ( V_10 ) ;
}
