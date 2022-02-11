static inline unsigned int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 ;
}
static inline unsigned int F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_5 ;
}
static inline unsigned int F_3 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_6 ;
}
static inline unsigned int F_4 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 ) - F_1 ( V_2 ) + 1 ;
}
static inline unsigned int F_5 ( const struct V_1 * V_2 )
{
return F_3 ( V_2 ) - 1 ;
}
static inline unsigned int F_6 ( const struct V_1 * V_2 )
{
return F_7 ( F_3 ( V_2 ) ) &
~ F_7 ( F_1 ( V_2 ) ) ;
}
static inline unsigned int F_8 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_7 ;
}
static inline unsigned int F_9 ( const struct V_1 * V_2 )
{
return 1 << F_8 ( V_2 ) ;
}
static inline unsigned int F_10 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 ) + 1 ;
}
static inline unsigned int F_11 ( const struct V_1 * V_2 )
{
return F_10 ( V_2 ) + F_9 ( V_2 ) - 1 ;
}
static inline unsigned int F_12 ( const struct V_1 * V_2 )
{
return F_8 ( V_2 ) ;
}
static inline unsigned int F_13 ( const struct V_1 * V_2 )
{
return 0xf << F_8 ( V_2 ) ;
}
static inline unsigned int F_14 ( const struct V_1 * V_2 )
{
return F_7 ( F_8 ( V_2 ) ) ;
}
static inline unsigned int F_15 ( const struct V_1 * V_2 )
{
return F_14 ( V_2 ) | F_13 ( V_2 ) ;
}
static inline unsigned int F_16 ( const struct V_1 * V_2 )
{
return F_7 ( F_2 ( V_2 ) + 1 ) &
~ F_7 ( F_1 ( V_2 ) ) ;
}
static inline unsigned int F_17 ( const struct V_1 * V_2 )
{
return F_7 ( F_11 ( V_2 ) + 1 ) &
~ F_7 ( F_10 ( V_2 ) ) ;
}
static inline unsigned int F_18 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_8 & F_14 ( V_2 ) ) + F_10 ( V_2 ) ;
}
static inline unsigned int F_19 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_8 >> F_12 ( V_2 ) ) & 0xf ;
}
static inline unsigned int F_20 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_9 & F_14 ( V_2 ) ) + F_10 ( V_2 ) ;
}
static inline T_1 F_21 ( const struct V_1 * V_2 , enum V_10 V_11 )
{
return F_22 ( V_2 -> V_12 + V_11 ) ;
}
static inline void F_23 ( const struct V_1 * V_2 , enum V_10 V_11 ,
T_1 V_13 )
{
F_24 ( V_13 , V_2 -> V_12 + V_11 ) ;
}
static inline void F_25 ( const struct V_1 * V_2 ,
unsigned int V_14 , enum V_15 V_16 , int V_17 )
{
F_23 ( V_2 , F_26 ( V_14 ) , ( V_16 << 24 ) | ( V_17 << 16 ) ) ;
}
static inline void F_27 ( const struct V_1 * V_2 , unsigned int V_14 ,
enum V_15 V_16 )
{
F_25 ( V_2 , V_14 , V_16 , 0 ) ;
}
static inline T_1 F_28 ( T_2 V_18 )
{
T_1 V_19 ;
if ( V_18 & V_20 )
V_19 = ( V_18 & V_21 ) | V_22 ;
else
V_19 = ( V_18 & V_23 ) << 18 ;
return V_19 ;
}
static void F_29 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
unsigned int V_26 ;
T_1 V_19 ;
V_19 = F_28 ( V_2 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < F_1 ( V_2 ) ; V_26 ++ ) {
F_27 ( V_2 , V_26 , V_28 ) ;
F_23 ( V_2 , F_31 ( V_26 ) , V_19 ) ;
F_23 ( V_2 , F_32 ( V_26 ) , 0x0 ) ;
}
for ( V_26 = F_1 ( V_2 ) ; V_26 < F_2 ( V_2 ) ; V_26 ++ )
F_27 ( V_2 , V_26 , V_29 ) ;
F_27 ( V_2 , F_2 ( V_2 ) , V_30 ) ;
for ( V_26 = F_1 ( V_2 ) ; V_26 <= F_2 ( V_2 ) ; V_26 ++ ) {
F_23 ( V_2 , F_33 ( V_26 ) , 0x0 ) ;
F_23 ( V_2 , F_31 ( V_26 ) , V_22 ) ;
}
for ( V_26 = F_10 ( V_2 ) ; V_26 <= F_11 ( V_2 ) ; V_26 ++ )
F_25 ( V_2 , V_26 , V_31 , 0 ) ;
V_2 -> V_8 = V_2 -> V_9 = 0 ;
V_2 -> V_32 = F_1 ( V_2 ) ;
}
static int F_34 ( struct V_24 * V_25 )
{
const struct V_1 * V_2 = F_30 ( V_25 ) ;
const struct V_33 * V_34 = & V_2 -> V_35 . V_36 ;
T_1 V_37 ;
V_37 = ( ( V_2 -> V_35 . V_38 & V_39 ) ? 1 << 24 : 0 ) |
( ( V_34 -> V_40 - 1 ) << 16 ) | ( ( V_34 -> V_41 - 1 ) << 12 ) |
( ( V_34 -> V_42 - 1 ) << 8 ) | ( ( V_34 -> V_43 - 1 ) << 4 ) |
( ( V_34 -> V_44 - 1 ) << 0 ) ;
F_35 ( V_25 , L_1 , V_37 ) ;
F_23 ( V_2 , V_45 , V_37 ) ;
return 0 ;
}
static int F_36 ( const struct V_24 * V_25 ,
struct V_46 * V_47 )
{
const struct V_1 * V_2 = F_30 ( V_25 ) ;
T_1 V_48 = F_21 ( V_2 , V_49 ) ;
V_47 -> V_50 = V_48 & 0xff ;
V_47 -> V_51 = V_48 >> 16 ;
return 0 ;
}
static void F_37 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
T_1 V_52 , V_53 ;
F_23 ( V_2 , V_54 , V_55 ) ;
V_52 = F_21 ( V_2 , V_56 ) ;
F_23 ( V_2 , V_56 , V_52 & ~ V_57 ) ;
F_34 ( V_25 ) ;
F_29 ( V_25 ) ;
if ( V_2 -> V_35 . V_38 & V_58 )
V_52 = V_57 | V_59 ;
else
V_52 = V_57 ;
F_23 ( V_2 , V_56 , V_52 ) ;
V_2 -> V_35 . V_60 = V_61 ;
V_53 = F_16 ( V_2 ) | V_62 | V_63 ;
F_23 ( V_2 , V_54 , V_55 ) ;
F_23 ( V_2 , V_64 , V_53 ) ;
}
static void F_38 ( struct V_24 * V_25 , enum V_65 V_60 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
T_1 V_52 ;
F_23 ( V_2 , V_54 , V_55 ) ;
V_52 = F_21 ( V_2 , V_56 ) ;
F_23 ( V_2 , V_56 , V_52 & ~ V_57 ) ;
V_2 -> V_35 . V_60 = V_60 ;
}
static T_3 F_39 ( struct V_66 * V_67 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
struct V_68 * V_69 = & V_25 -> V_69 ;
struct V_70 * V_71 = (struct V_70 * ) V_67 -> V_72 ;
unsigned int V_14 , V_17 ;
T_1 V_19 , V_73 ;
if ( F_40 ( V_25 , V_67 ) )
return V_74 ;
V_14 = F_18 ( V_2 ) ;
V_17 = F_19 ( V_2 ) ;
if ( F_41 ( ! ( F_21 ( V_2 , F_42 ( V_14 ) ) & V_75 ) ) ) {
F_43 ( V_25 ) ;
F_44 ( V_25 , L_2 ) ;
return V_76 ;
}
V_19 = F_28 ( V_71 -> V_18 ) ;
V_73 = ( ( V_71 -> V_18 & V_77 ) ? V_78 : 0 ) |
( V_71 -> V_79 << 16 ) | V_80 ;
F_27 ( V_2 , V_14 , V_28 ) ;
F_23 ( V_2 , F_31 ( V_14 ) , V_19 ) ;
F_25 ( V_2 , V_14 , V_31 , V_17 ) ;
F_23 ( V_2 , F_45 ( V_14 ) , * ( T_1 * ) ( V_71 -> V_72 + 0 ) ) ;
F_23 ( V_2 , F_46 ( V_14 ) , * ( T_1 * ) ( V_71 -> V_72 + 4 ) ) ;
F_23 ( V_2 , F_32 ( V_14 ) , V_73 ) ;
V_69 -> V_81 += V_71 -> V_79 ;
F_47 ( V_67 , V_25 , V_14 - F_10 ( V_2 ) ) ;
V_2 -> V_8 ++ ;
if ( ! ( F_21 ( V_2 , F_42 ( F_18 ( V_2 ) ) ) &
V_75 ) ||
( V_2 -> V_8 & F_15 ( V_2 ) ) == 0 )
F_43 ( V_25 ) ;
F_23 ( V_2 , V_64 , 1 << V_14 ) ;
return V_74 ;
}
static inline void F_48 ( const struct V_1 * V_2 )
{
T_1 V_82 = F_6 ( V_2 ) ;
F_23 ( V_2 , V_83 , V_82 ) ;
}
static inline void F_49 ( const struct V_1 * V_2 ,
unsigned int V_14 )
{
T_1 V_82 = 1 << V_14 ;
F_23 ( V_2 , V_83 , V_82 ) ;
}
static void F_50 ( struct V_24 * V_25 )
{
struct V_68 * V_69 = & V_25 -> V_69 ;
struct V_66 * V_67 ;
struct V_70 * V_71 ;
F_51 ( V_25 , L_3 ) ;
V_69 -> V_84 ++ ;
V_69 -> V_85 ++ ;
V_67 = F_52 ( V_25 , & V_71 ) ;
if ( F_41 ( ! V_67 ) )
return;
V_71 -> V_18 |= V_86 ;
V_71 -> V_72 [ 1 ] = V_87 ;
V_69 -> V_88 ++ ;
V_69 -> V_89 += V_71 -> V_79 ;
F_53 ( V_67 ) ;
}
static void F_54 ( struct V_24 * V_25 , unsigned int V_14 ,
struct V_70 * V_71 )
{
const struct V_1 * V_2 = F_30 ( V_25 ) ;
T_1 V_90 , V_19 ;
V_19 = F_21 ( V_2 , F_31 ( V_14 ) ) ;
if ( V_19 & V_22 )
V_71 -> V_18 = ( ( V_19 >> 0 ) & V_21 ) | V_20 ;
else
V_71 -> V_18 = ( V_19 >> 18 ) & V_23 ;
V_90 = F_21 ( V_2 , F_42 ( V_14 ) ) ;
V_71 -> V_79 = F_55 ( ( V_90 >> 16 ) & 0xf ) ;
if ( V_90 & V_91 )
V_71 -> V_18 |= V_77 ;
else {
* ( T_1 * ) ( V_71 -> V_72 + 0 ) = F_21 ( V_2 , F_45 ( V_14 ) ) ;
* ( T_1 * ) ( V_71 -> V_72 + 4 ) = F_21 ( V_2 , F_46 ( V_14 ) ) ;
}
F_23 ( V_2 , F_31 ( V_14 ) , V_22 ) ;
if ( F_41 ( V_14 == F_2 ( V_2 ) && V_90 & V_92 ) )
F_50 ( V_25 ) ;
}
static void F_56 ( struct V_24 * V_25 , unsigned int V_14 )
{
struct V_68 * V_69 = & V_25 -> V_69 ;
struct V_70 * V_71 ;
struct V_66 * V_67 ;
V_67 = F_57 ( V_25 , & V_71 ) ;
if ( F_41 ( ! V_67 ) ) {
V_69 -> V_93 ++ ;
return;
}
F_54 ( V_25 , V_14 , V_71 ) ;
V_69 -> V_88 ++ ;
V_69 -> V_89 += V_71 -> V_79 ;
F_53 ( V_67 ) ;
F_58 ( V_25 , V_94 ) ;
}
static int F_59 ( struct V_24 * V_25 , int V_95 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
T_1 V_96 = F_21 ( V_2 , V_97 ) ;
const unsigned long * V_98 = ( unsigned long * ) & V_96 ;
unsigned int V_14 ;
int V_99 = 0 ;
if ( V_2 -> V_32 > F_5 ( V_2 ) &&
V_96 & F_6 ( V_2 ) )
F_35 ( V_25 ,
L_4 ) ;
V_100:
for ( V_14 = F_60 ( V_98 , F_10 ( V_2 ) , V_2 -> V_32 ) ;
V_14 < F_10 ( V_2 ) && V_95 > 0 ;
V_96 = F_21 ( V_2 , V_97 ) ,
V_14 = F_60 ( V_98 , F_10 ( V_2 ) , ++ V_2 -> V_32 ) ) {
F_56 ( V_25 , V_14 ) ;
if ( V_14 == F_5 ( V_2 ) )
F_48 ( V_2 ) ;
else if ( V_14 > F_5 ( V_2 ) )
F_49 ( V_2 , V_14 ) ;
V_99 ++ ;
V_95 -- ;
}
if ( V_2 -> V_32 > F_5 ( V_2 ) &&
V_14 > F_2 ( V_2 ) ) {
V_2 -> V_32 = F_1 ( V_2 ) ;
if ( V_95 > 0 )
goto V_100;
}
return V_99 ;
}
static void F_61 ( struct V_24 * V_25 ,
struct V_70 * V_71 , T_1 V_96 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
if ( V_96 & V_101 ) {
F_51 ( V_25 , L_5 ) ;
V_25 -> V_69 . V_85 ++ ;
V_2 -> V_35 . V_102 . V_103 ++ ;
V_71 -> V_18 |= V_104 | V_105 ;
}
if ( V_96 & V_106 ) {
F_51 ( V_25 , L_6 ) ;
V_25 -> V_69 . V_85 ++ ;
V_2 -> V_35 . V_102 . V_103 ++ ;
V_71 -> V_18 |= V_104 | V_105 ;
V_71 -> V_72 [ 2 ] |= V_107 ;
}
if ( V_96 & V_108 ) {
F_51 ( V_25 , L_7 ) ;
V_25 -> V_69 . V_109 ++ ;
V_71 -> V_18 |= V_110 ;
}
if ( V_96 & V_111 ) {
F_51 ( V_25 , L_8 ) ;
V_25 -> V_69 . V_85 ++ ;
V_2 -> V_35 . V_102 . V_103 ++ ;
V_71 -> V_18 |= V_104 | V_105 ;
V_71 -> V_72 [ 2 ] |= V_112 ;
}
if ( V_96 & V_113 ) {
F_51 ( V_25 , L_9 ) ;
V_25 -> V_69 . V_109 ++ ;
V_2 -> V_35 . V_102 . V_103 ++ ;
V_71 -> V_18 |= V_104 | V_105 ;
V_71 -> V_72 [ 2 ] |= V_114 ;
}
}
static int F_62 ( struct V_24 * V_25 , int V_95 , T_1 V_96 )
{
struct V_66 * V_67 ;
struct V_70 * V_71 ;
if ( V_95 == 0 )
return 0 ;
V_67 = F_52 ( V_25 , & V_71 ) ;
if ( F_41 ( ! V_67 ) )
return 0 ;
F_61 ( V_25 , V_71 , V_96 ) ;
V_25 -> V_69 . V_88 ++ ;
V_25 -> V_69 . V_89 += V_71 -> V_79 ;
F_53 ( V_67 ) ;
return 1 ;
}
static int F_63 ( struct V_115 * V_116 , int V_95 )
{
struct V_24 * V_25 = V_116 -> V_25 ;
const struct V_1 * V_2 = F_30 ( V_25 ) ;
T_1 V_96 = F_21 ( V_2 , V_97 ) ;
int V_117 = 0 ;
if ( V_96 & F_16 ( V_2 ) )
V_117 += F_59 ( V_25 , V_95 - V_117 ) ;
V_96 |= V_2 -> V_96 ;
if ( V_96 & V_63 )
V_117 += F_62 ( V_25 , V_95 - V_117 , V_96 ) ;
if ( V_117 < V_95 ) {
T_1 V_53 = V_63 ;
V_53 |= F_16 ( V_2 ) & ~ F_7 ( V_2 -> V_32 ) ;
F_64 ( V_116 ) ;
F_23 ( V_2 , V_64 , V_53 ) ;
}
return V_117 ;
}
static void F_65 ( struct V_24 * V_25 , T_1 V_96 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
T_1 V_90 ;
unsigned int V_14 ;
for (; ( V_2 -> V_8 - V_2 -> V_9 ) > 0 ; V_2 -> V_9 ++ ) {
V_14 = F_20 ( V_2 ) ;
if ( ! ( V_96 & ( 1 << V_14 ) ) )
break;
F_23 ( V_2 , V_54 , 1 << V_14 ) ;
V_90 = F_21 ( V_2 , F_42 ( V_14 ) ) ;
if ( F_66 ( V_90 & V_75 &&
~ V_90 & V_118 ) ) {
F_67 ( V_25 , V_14 - F_10 ( V_2 ) ) ;
V_25 -> V_69 . V_119 ++ ;
F_58 ( V_25 , V_120 ) ;
}
}
if ( ( V_2 -> V_8 & F_15 ( V_2 ) ) != 0 ||
( V_2 -> V_9 & F_15 ( V_2 ) ) == 0 )
F_68 ( V_25 ) ;
}
static void F_69 ( struct V_24 * V_25 ,
struct V_70 * V_71 , enum V_65 V_121 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
T_1 V_122 = 0 , V_53 = 0 ;
struct V_46 V_47 ;
F_36 ( V_25 , & V_47 ) ;
switch ( V_2 -> V_35 . V_60 ) {
case V_61 :
if ( V_121 >= V_123 &&
V_121 <= V_124 ) {
F_51 ( V_25 , L_10 ) ;
V_2 -> V_35 . V_102 . V_125 ++ ;
V_71 -> V_18 |= V_86 ;
V_71 -> V_72 [ 1 ] = ( V_47 . V_51 > V_47 . V_50 ) ?
V_126 :
V_127 ;
}
case V_123 :
if ( V_121 >= V_128 &&
V_121 <= V_124 ) {
F_51 ( V_25 , L_11 ) ;
V_2 -> V_35 . V_102 . V_129 ++ ;
V_71 -> V_18 |= V_86 ;
V_71 -> V_72 [ 1 ] = ( V_47 . V_51 > V_47 . V_50 ) ?
V_130 :
V_131 ;
}
break;
case V_124 :
if ( V_121 <= V_128 ) {
V_71 -> V_18 |= V_132 ;
F_51 ( V_25 , L_12 ) ;
V_2 -> V_35 . V_102 . V_133 ++ ;
F_70 ( V_25 ) ;
F_68 ( V_25 ) ;
}
break;
default:
break;
}
switch ( V_121 ) {
case V_61 :
F_51 ( V_25 , L_13 ) ;
V_71 -> V_18 |= V_104 ;
V_71 -> V_72 [ 2 ] = V_134 ;
case V_123 :
V_122 = V_135 | V_136 | V_137 ;
V_53 = V_62 ;
break;
case V_128 :
V_122 = V_135 | V_136 | V_62 ;
V_53 = V_137 ;
break;
case V_124 :
V_122 = V_135 | V_62 |
V_136 | V_137 ;
V_53 = 0 ;
V_71 -> V_18 |= V_138 ;
F_51 ( V_25 , L_14 ) ;
F_71 ( V_25 ) ;
V_2 -> V_35 . V_102 . V_139 ++ ;
if ( ! V_2 -> V_35 . V_140 ) {
F_38 ( V_25 , V_124 ) ;
return;
}
break;
default:
break;
}
F_23 ( V_2 , V_54 , V_122 ) ;
F_23 ( V_2 , V_64 , V_53 ) ;
}
static int F_72 ( const struct V_24 * V_25 ,
enum V_65 * V_60 )
{
struct V_46 V_47 ;
int V_141 ;
V_141 = F_36 ( V_25 , & V_47 ) ;
if ( V_141 )
return V_141 ;
if ( V_47 . V_51 < 96 && V_47 . V_50 < 96 )
* V_60 = V_61 ;
else if ( V_47 . V_51 < 128 && V_47 . V_50 < 128 )
* V_60 = V_123 ;
else if ( V_47 . V_51 < 256 && V_47 . V_50 < 256 )
* V_60 = V_128 ;
else
* V_60 = V_124 ;
return 0 ;
}
static void F_73 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
struct V_66 * V_67 ;
struct V_70 * V_71 ;
enum V_65 V_121 ;
T_1 V_96 ;
int V_141 ;
if ( F_74 ( V_2 ) ) {
V_96 = F_21 ( V_2 , V_97 ) ;
if ( F_41 ( V_96 & V_137 ) )
V_121 = V_124 ;
else if ( F_41 ( V_96 & V_62 ) )
V_121 = V_128 ;
else if ( F_41 ( V_96 & V_136 ) )
V_121 = V_123 ;
else if ( F_66 ( V_96 & V_135 ) )
V_121 = V_61 ;
else {
F_44 ( V_25 , L_15 ) ;
return;
}
} else {
V_141 = F_72 ( V_25 , & V_121 ) ;
if ( V_141 )
return;
}
if ( F_66 ( V_121 == V_2 -> V_35 . V_60 ) )
return;
V_67 = F_52 ( V_25 , & V_71 ) ;
if ( F_41 ( ! V_67 ) )
return;
F_69 ( V_25 , V_71 , V_121 ) ;
V_25 -> V_69 . V_88 ++ ;
V_25 -> V_69 . V_89 += V_71 -> V_79 ;
F_75 ( V_67 ) ;
V_2 -> V_35 . V_60 = V_121 ;
}
static T_4 F_76 ( int V_142 , void * V_143 )
{
struct V_24 * V_25 = V_143 ;
struct V_1 * V_2 = F_30 ( V_25 ) ;
T_4 V_144 = V_145 ;
T_1 V_96 , V_146 ;
V_96 = F_21 ( V_2 , V_97 ) ;
V_146 = F_21 ( V_2 , V_147 ) ;
V_96 &= V_146 ;
if ( ! V_96 )
goto exit;
V_144 = V_148 ;
if ( V_96 & ( F_16 ( V_2 ) | V_63 ) ) {
V_2 -> V_96 = V_96 ;
F_23 ( V_2 , V_54 ,
F_16 ( V_2 ) | V_63 ) ;
F_77 ( & V_2 -> V_116 ) ;
}
if ( V_96 & F_17 ( V_2 ) )
F_65 ( V_25 , V_96 ) ;
F_73 ( V_25 ) ;
exit:
return V_144 ;
}
static int F_78 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
int V_141 ;
V_141 = F_79 ( V_2 -> V_149 ) ;
if ( V_141 )
return V_141 ;
V_141 = F_80 ( V_25 ) ;
if ( V_141 )
goto V_150;
if ( F_81 ( V_25 -> V_142 , F_76 , V_151 ,
V_25 -> V_152 , V_25 ) ) {
V_141 = - V_153 ;
goto V_154;
}
F_58 ( V_25 , V_155 ) ;
F_37 ( V_25 ) ;
F_82 ( & V_2 -> V_116 ) ;
F_83 ( V_25 ) ;
return 0 ;
V_154:
F_84 ( V_25 ) ;
V_150:
F_85 ( V_2 -> V_149 ) ;
return V_141 ;
}
static int F_86 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_30 ( V_25 ) ;
F_43 ( V_25 ) ;
F_87 ( & V_2 -> V_116 ) ;
F_38 ( V_25 , V_156 ) ;
F_88 ( V_25 -> V_142 , V_25 ) ;
F_85 ( V_2 -> V_149 ) ;
F_84 ( V_25 ) ;
F_58 ( V_25 , V_157 ) ;
return 0 ;
}
static int F_89 ( struct V_24 * V_25 , enum V_158 V_16 )
{
switch ( V_16 ) {
case V_159 :
F_37 ( V_25 ) ;
F_68 ( V_25 ) ;
break;
default:
return - V_160 ;
}
return 0 ;
}
static T_5 F_90 ( struct V_161 * V_25 ,
struct V_162 * V_163 , char * V_164 )
{
struct V_1 * V_2 = F_30 ( F_91 ( V_25 ) ) ;
if ( V_2 -> V_27 & V_20 )
return snprintf ( V_164 , V_165 , L_16 , V_2 -> V_27 ) ;
else
return snprintf ( V_164 , V_165 , L_17 , V_2 -> V_27 ) ;
}
static T_5 F_92 ( struct V_161 * V_25 ,
struct V_162 * V_163 , const char * V_164 , T_6 V_166 )
{
struct V_24 * V_167 = F_91 ( V_25 ) ;
struct V_1 * V_2 = F_30 ( V_167 ) ;
unsigned long V_18 ;
T_5 V_168 ;
int V_141 ;
F_93 () ;
if ( V_167 -> V_169 & V_170 ) {
V_168 = - V_171 ;
goto V_150;
}
V_141 = F_94 ( V_164 , 0 , & V_18 ) ;
if ( V_141 ) {
V_168 = V_141 ;
goto V_150;
}
if ( V_18 & V_20 )
V_18 &= V_21 | V_20 ;
else
V_18 &= V_23 ;
V_2 -> V_27 = V_18 ;
V_168 = V_166 ;
V_150:
F_95 () ;
return V_168 ;
}
static const struct V_172 * F_96 ( struct V_173 * V_174 )
{
if ( V_174 -> V_25 . V_175 ) {
const struct V_176 * V_177 ;
V_177 = F_97 ( V_178 , V_174 -> V_25 . V_175 ) ;
if ( ! V_177 ) {
F_98 ( & V_174 -> V_25 , L_18 ) ;
return NULL ;
}
return ( const struct V_172 * ) V_177 -> V_72 ;
}
return ( const struct V_172 * )
F_99 ( V_174 ) -> V_179 ;
}
static int F_100 ( struct V_173 * V_174 )
{
const struct V_172 * V_3 ;
struct V_24 * V_25 ;
struct V_1 * V_2 ;
struct V_180 * V_181 ;
struct V_149 * V_149 ;
void T_7 * V_98 ;
int V_141 , V_142 ;
V_3 = F_96 ( V_174 ) ;
if ( ! V_3 ) {
F_98 ( & V_174 -> V_25 , L_19 ) ;
V_141 = - V_182 ;
goto exit;
}
V_149 = F_101 ( & V_174 -> V_25 , L_20 ) ;
if ( F_102 ( V_149 ) ) {
F_98 ( & V_174 -> V_25 , L_21 ) ;
V_141 = - V_182 ;
goto exit;
}
V_181 = F_103 ( V_174 , V_183 , 0 ) ;
V_142 = F_104 ( V_174 , 0 ) ;
if ( ! V_181 || V_142 <= 0 ) {
V_141 = - V_182 ;
goto V_184;
}
if ( ! F_105 ( V_181 -> V_185 ,
F_106 ( V_181 ) ,
V_174 -> V_152 ) ) {
V_141 = - V_171 ;
goto V_184;
}
V_98 = F_107 ( V_181 -> V_185 , F_106 ( V_181 ) ) ;
if ( ! V_98 ) {
V_141 = - V_186 ;
goto V_187;
}
V_25 = F_108 ( sizeof( struct V_1 ) ,
1 << V_3 -> V_7 ) ;
if ( ! V_25 ) {
V_141 = - V_186 ;
goto V_188;
}
V_25 -> V_189 = & V_190 ;
V_25 -> V_142 = V_142 ;
V_25 -> V_169 |= V_191 ;
V_2 = F_30 ( V_25 ) ;
V_2 -> V_35 . clock . V_192 = F_109 ( V_149 ) ;
V_2 -> V_35 . V_193 = & V_194 ;
V_2 -> V_35 . V_195 = F_89 ;
V_2 -> V_35 . V_196 = F_36 ;
V_2 -> V_35 . V_197 = V_39 |
V_58 ;
V_2 -> V_12 = V_98 ;
V_2 -> V_3 = * V_3 ;
V_2 -> V_149 = V_149 ;
V_2 -> V_198 = F_110 ( & V_174 -> V_25 ) ;
V_2 -> V_27 = 0x7ff ;
F_111 ( V_25 , & V_2 -> V_116 , F_63 , F_4 ( V_2 ) ) ;
if ( F_74 ( V_2 ) )
V_25 -> V_199 [ 0 ] = & V_200 ;
F_112 ( V_174 , V_25 ) ;
F_113 ( V_25 , & V_174 -> V_25 ) ;
V_141 = F_114 ( V_25 ) ;
if ( V_141 ) {
F_98 ( & V_174 -> V_25 , L_22 ) ;
goto V_201;
}
F_115 ( V_25 ) ;
F_116 ( & V_174 -> V_25 , L_23 ,
V_2 -> V_12 , V_25 -> V_142 ) ;
return 0 ;
V_201:
F_117 ( V_25 ) ;
V_188:
F_118 ( V_98 ) ;
V_187:
F_119 ( V_181 -> V_185 , F_106 ( V_181 ) ) ;
V_184:
F_120 ( V_149 ) ;
exit:
return V_141 ;
}
static int F_121 ( struct V_173 * V_174 )
{
struct V_24 * V_25 = F_122 ( V_174 ) ;
struct V_1 * V_2 = F_30 ( V_25 ) ;
struct V_180 * V_181 ;
F_123 ( V_25 ) ;
F_118 ( V_2 -> V_12 ) ;
V_181 = F_103 ( V_174 , V_183 , 0 ) ;
F_119 ( V_181 -> V_185 , F_106 ( V_181 ) ) ;
F_120 ( V_2 -> V_149 ) ;
F_117 ( V_25 ) ;
return 0 ;
}
