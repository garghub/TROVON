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
static void F_29 ( const struct V_1 * V_2 , int V_24 )
{
if ( V_2 -> V_25 && V_2 -> V_25 -> V_26 )
V_2 -> V_25 -> V_26 ( V_24 ) ;
}
static void F_30 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
unsigned int V_29 ;
T_1 V_19 ;
V_19 = F_28 ( V_2 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < F_1 ( V_2 ) ; V_29 ++ ) {
F_27 ( V_2 , V_29 , V_31 ) ;
F_23 ( V_2 , F_32 ( V_29 ) , V_19 ) ;
F_23 ( V_2 , F_33 ( V_29 ) , 0x0 ) ;
}
for ( V_29 = F_1 ( V_2 ) ; V_29 < F_2 ( V_2 ) ; V_29 ++ )
F_27 ( V_2 , V_29 , V_32 ) ;
F_27 ( V_2 , F_2 ( V_2 ) , V_33 ) ;
for ( V_29 = F_1 ( V_2 ) ; V_29 <= F_2 ( V_2 ) ; V_29 ++ ) {
F_23 ( V_2 , F_34 ( V_29 ) , 0x0 ) ;
F_23 ( V_2 , F_32 ( V_29 ) , V_22 ) ;
}
for ( V_29 = F_10 ( V_2 ) ; V_29 <= F_11 ( V_2 ) ; V_29 ++ )
F_25 ( V_2 , V_29 , V_34 , 0 ) ;
V_2 -> V_8 = V_2 -> V_9 = 0 ;
V_2 -> V_35 = F_1 ( V_2 ) ;
}
static int F_35 ( struct V_27 * V_28 )
{
const struct V_1 * V_2 = F_31 ( V_28 ) ;
const struct V_36 * V_37 = & V_2 -> V_38 . V_39 ;
T_1 V_40 ;
V_40 = ( ( V_2 -> V_38 . V_41 & V_42 ) ? 1 << 24 : 0 ) |
( ( V_37 -> V_43 - 1 ) << 16 ) | ( ( V_37 -> V_44 - 1 ) << 12 ) |
( ( V_37 -> V_45 - 1 ) << 8 ) | ( ( V_37 -> V_46 - 1 ) << 4 ) |
( ( V_37 -> V_47 - 1 ) << 0 ) ;
F_36 ( V_28 , L_1 , V_40 ) ;
F_23 ( V_2 , V_48 , V_40 ) ;
return 0 ;
}
static int F_37 ( const struct V_27 * V_28 ,
struct V_49 * V_50 )
{
const struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_51 = F_21 ( V_2 , V_52 ) ;
V_50 -> V_53 = V_51 & 0xff ;
V_50 -> V_54 = V_51 >> 16 ;
return 0 ;
}
static void F_38 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_55 , V_56 ;
F_23 ( V_2 , V_57 , V_58 ) ;
V_55 = F_21 ( V_2 , V_59 ) ;
F_23 ( V_2 , V_59 , V_55 & ~ V_60 ) ;
F_35 ( V_28 ) ;
F_30 ( V_28 ) ;
F_29 ( V_2 , 1 ) ;
if ( V_2 -> V_38 . V_41 & V_61 )
V_55 = V_60 | V_62 ;
else
V_55 = V_60 ;
F_23 ( V_2 , V_59 , V_55 ) ;
V_2 -> V_38 . V_63 = V_64 ;
V_56 = F_16 ( V_2 ) | V_65 | V_66 ;
F_23 ( V_2 , V_57 , V_58 ) ;
F_23 ( V_2 , V_67 , V_56 ) ;
}
static void F_39 ( struct V_27 * V_28 , enum V_68 V_63 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_55 ;
F_23 ( V_2 , V_57 , V_58 ) ;
V_55 = F_21 ( V_2 , V_59 ) ;
F_23 ( V_2 , V_59 , V_55 & ~ V_60 ) ;
F_29 ( V_2 , 0 ) ;
V_2 -> V_38 . V_63 = V_63 ;
}
static T_3 F_40 ( struct V_69 * V_70 , struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
struct V_71 * V_72 = & V_28 -> V_72 ;
struct V_73 * V_74 = (struct V_73 * ) V_70 -> V_75 ;
unsigned int V_14 , V_17 ;
T_1 V_19 , V_76 ;
if ( F_41 ( V_28 , V_70 ) )
return V_77 ;
V_14 = F_18 ( V_2 ) ;
V_17 = F_19 ( V_2 ) ;
if ( F_42 ( ! ( F_21 ( V_2 , F_43 ( V_14 ) ) & V_78 ) ) ) {
F_44 ( V_28 ) ;
F_45 ( V_28 , L_2 ) ;
return V_79 ;
}
V_19 = F_28 ( V_74 -> V_18 ) ;
V_76 = ( ( V_74 -> V_18 & V_80 ) ? V_81 : 0 ) |
( V_74 -> V_82 << 16 ) | V_83 ;
F_27 ( V_2 , V_14 , V_31 ) ;
F_23 ( V_2 , F_32 ( V_14 ) , V_19 ) ;
F_25 ( V_2 , V_14 , V_34 , V_17 ) ;
F_23 ( V_2 , F_46 ( V_14 ) , * ( T_1 * ) ( V_74 -> V_75 + 0 ) ) ;
F_23 ( V_2 , F_47 ( V_14 ) , * ( T_1 * ) ( V_74 -> V_75 + 4 ) ) ;
F_23 ( V_2 , F_33 ( V_14 ) , V_76 ) ;
V_72 -> V_84 += V_74 -> V_82 ;
F_48 ( V_70 , V_28 , V_14 - F_10 ( V_2 ) ) ;
V_2 -> V_8 ++ ;
if ( ! ( F_21 ( V_2 , F_43 ( F_18 ( V_2 ) ) ) &
V_78 ) ||
( V_2 -> V_8 & F_15 ( V_2 ) ) == 0 )
F_44 ( V_28 ) ;
F_23 ( V_2 , V_67 , 1 << V_14 ) ;
return V_77 ;
}
static inline void F_49 ( const struct V_1 * V_2 )
{
T_1 V_85 = F_6 ( V_2 ) ;
F_23 ( V_2 , V_86 , V_85 ) ;
}
static inline void F_50 ( const struct V_1 * V_2 ,
unsigned int V_14 )
{
T_1 V_85 = 1 << V_14 ;
F_23 ( V_2 , V_86 , V_85 ) ;
}
static void F_51 ( struct V_27 * V_28 )
{
struct V_71 * V_72 = & V_28 -> V_72 ;
struct V_69 * V_70 ;
struct V_73 * V_74 ;
F_52 ( V_28 , L_3 ) ;
V_72 -> V_87 ++ ;
V_72 -> V_88 ++ ;
V_70 = F_53 ( V_28 , & V_74 ) ;
if ( F_42 ( ! V_70 ) )
return;
V_74 -> V_18 |= V_89 ;
V_74 -> V_75 [ 1 ] = V_90 ;
F_54 ( V_70 ) ;
V_72 -> V_91 ++ ;
V_72 -> V_92 += V_74 -> V_82 ;
}
static void F_55 ( struct V_27 * V_28 , unsigned int V_14 ,
struct V_73 * V_74 )
{
const struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_93 , V_19 ;
V_19 = F_21 ( V_2 , F_32 ( V_14 ) ) ;
if ( V_19 & V_22 )
V_74 -> V_18 = ( ( V_19 >> 0 ) & V_21 ) | V_20 ;
else
V_74 -> V_18 = ( V_19 >> 18 ) & V_23 ;
V_93 = F_21 ( V_2 , F_43 ( V_14 ) ) ;
V_74 -> V_82 = F_56 ( ( V_93 >> 16 ) & 0xf ) ;
if ( V_93 & V_94 )
V_74 -> V_18 |= V_80 ;
else {
* ( T_1 * ) ( V_74 -> V_75 + 0 ) = F_21 ( V_2 , F_46 ( V_14 ) ) ;
* ( T_1 * ) ( V_74 -> V_75 + 4 ) = F_21 ( V_2 , F_47 ( V_14 ) ) ;
}
F_23 ( V_2 , F_32 ( V_14 ) , V_22 ) ;
if ( F_42 ( V_14 == F_2 ( V_2 ) && V_93 & V_95 ) )
F_51 ( V_28 ) ;
}
static void F_57 ( struct V_27 * V_28 , unsigned int V_14 )
{
struct V_71 * V_72 = & V_28 -> V_72 ;
struct V_73 * V_74 ;
struct V_69 * V_70 ;
V_70 = F_58 ( V_28 , & V_74 ) ;
if ( F_42 ( ! V_70 ) ) {
V_72 -> V_96 ++ ;
return;
}
F_55 ( V_28 , V_14 , V_74 ) ;
F_54 ( V_70 ) ;
V_72 -> V_91 ++ ;
V_72 -> V_92 += V_74 -> V_82 ;
F_59 ( V_28 , V_97 ) ;
}
static int F_60 ( struct V_27 * V_28 , int V_98 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_99 = F_21 ( V_2 , V_100 ) ;
const unsigned long * V_101 = ( unsigned long * ) & V_99 ;
unsigned int V_14 ;
int V_102 = 0 ;
if ( V_2 -> V_35 > F_5 ( V_2 ) &&
V_99 & F_6 ( V_2 ) )
F_36 ( V_28 ,
L_4 ) ;
V_103:
for ( V_14 = F_61 ( V_101 , F_10 ( V_2 ) , V_2 -> V_35 ) ;
V_14 < F_10 ( V_2 ) && V_98 > 0 ;
V_99 = F_21 ( V_2 , V_100 ) ,
V_14 = F_61 ( V_101 , F_10 ( V_2 ) , ++ V_2 -> V_35 ) ) {
F_57 ( V_28 , V_14 ) ;
if ( V_14 == F_5 ( V_2 ) )
F_49 ( V_2 ) ;
else if ( V_14 > F_5 ( V_2 ) )
F_50 ( V_2 , V_14 ) ;
V_102 ++ ;
V_98 -- ;
}
if ( V_2 -> V_35 > F_5 ( V_2 ) &&
V_98 > 0 && V_14 > F_2 ( V_2 ) ) {
V_2 -> V_35 = F_1 ( V_2 ) ;
goto V_103;
}
return V_102 ;
}
static void F_62 ( struct V_27 * V_28 ,
struct V_73 * V_74 , T_1 V_99 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
if ( V_99 & V_104 ) {
F_52 ( V_28 , L_5 ) ;
V_28 -> V_72 . V_88 ++ ;
V_2 -> V_38 . V_105 . V_106 ++ ;
V_74 -> V_18 |= V_107 | V_108 ;
}
if ( V_99 & V_109 ) {
F_52 ( V_28 , L_6 ) ;
V_28 -> V_72 . V_88 ++ ;
V_2 -> V_38 . V_105 . V_106 ++ ;
V_74 -> V_18 |= V_107 | V_108 ;
V_74 -> V_75 [ 2 ] |= V_110 ;
}
if ( V_99 & V_111 ) {
F_52 ( V_28 , L_7 ) ;
V_28 -> V_72 . V_112 ++ ;
V_74 -> V_18 |= V_113 ;
}
if ( V_99 & V_114 ) {
F_52 ( V_28 , L_8 ) ;
V_28 -> V_72 . V_88 ++ ;
V_2 -> V_38 . V_105 . V_106 ++ ;
V_74 -> V_18 |= V_107 | V_108 ;
V_74 -> V_75 [ 2 ] |= V_115 ;
}
if ( V_99 & V_116 ) {
F_52 ( V_28 , L_9 ) ;
V_28 -> V_72 . V_112 ++ ;
V_2 -> V_38 . V_105 . V_106 ++ ;
V_74 -> V_18 |= V_107 | V_108 ;
V_74 -> V_75 [ 2 ] |= V_117 ;
}
}
static int F_63 ( struct V_27 * V_28 , int V_98 , T_1 V_99 )
{
struct V_69 * V_70 ;
struct V_73 * V_74 ;
if ( V_98 == 0 )
return 0 ;
V_70 = F_53 ( V_28 , & V_74 ) ;
if ( F_42 ( ! V_70 ) )
return 0 ;
F_62 ( V_28 , V_74 , V_99 ) ;
F_54 ( V_70 ) ;
V_28 -> V_72 . V_91 ++ ;
V_28 -> V_72 . V_92 += V_74 -> V_82 ;
return 1 ;
}
static int F_64 ( struct V_118 * V_119 , int V_98 )
{
struct V_27 * V_28 = V_119 -> V_28 ;
const struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_99 = F_21 ( V_2 , V_100 ) ;
int V_120 = 0 ;
if ( V_99 & F_16 ( V_2 ) )
V_120 += F_60 ( V_28 , V_98 - V_120 ) ;
V_99 |= V_2 -> V_99 ;
if ( V_99 & V_66 )
V_120 += F_63 ( V_28 , V_98 - V_120 , V_99 ) ;
if ( V_120 < V_98 ) {
T_1 V_56 = V_66 ;
V_56 |= F_16 ( V_2 ) & ~ F_7 ( V_2 -> V_35 ) ;
F_65 ( V_119 ) ;
F_23 ( V_2 , V_67 , V_56 ) ;
}
return V_120 ;
}
static void F_66 ( struct V_27 * V_28 , T_1 V_99 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_93 ;
unsigned int V_14 ;
for (; ( V_2 -> V_8 - V_2 -> V_9 ) > 0 ; V_2 -> V_9 ++ ) {
V_14 = F_20 ( V_2 ) ;
if ( ! ( V_99 & ( 1 << V_14 ) ) )
break;
F_23 ( V_2 , V_57 , 1 << V_14 ) ;
V_93 = F_21 ( V_2 , F_43 ( V_14 ) ) ;
if ( F_67 ( V_93 & V_78 &&
~ V_93 & V_121 ) ) {
F_68 ( V_28 , V_14 - F_10 ( V_2 ) ) ;
V_28 -> V_72 . V_122 ++ ;
F_59 ( V_28 , V_123 ) ;
}
}
if ( ( V_2 -> V_8 & F_15 ( V_2 ) ) != 0 ||
( V_2 -> V_9 & F_15 ( V_2 ) ) == 0 )
F_69 ( V_28 ) ;
}
static void F_70 ( struct V_27 * V_28 ,
struct V_73 * V_74 , enum V_68 V_124 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_125 = 0 , V_56 = 0 ;
struct V_49 V_50 ;
F_37 ( V_28 , & V_50 ) ;
switch ( V_2 -> V_38 . V_63 ) {
case V_64 :
if ( V_124 >= V_126 &&
V_124 <= V_127 ) {
F_52 ( V_28 , L_10 ) ;
V_2 -> V_38 . V_105 . V_128 ++ ;
V_74 -> V_18 |= V_89 ;
V_74 -> V_75 [ 1 ] = ( V_50 . V_54 > V_50 . V_53 ) ?
V_129 :
V_130 ;
}
case V_126 :
if ( V_124 >= V_131 &&
V_124 <= V_127 ) {
F_52 ( V_28 , L_11 ) ;
V_2 -> V_38 . V_105 . V_132 ++ ;
V_74 -> V_18 |= V_89 ;
V_74 -> V_75 [ 1 ] = ( V_50 . V_54 > V_50 . V_53 ) ?
V_133 :
V_134 ;
}
break;
case V_127 :
if ( V_124 <= V_131 ) {
V_74 -> V_18 |= V_135 ;
F_52 ( V_28 , L_12 ) ;
V_2 -> V_38 . V_105 . V_136 ++ ;
F_71 ( V_28 ) ;
F_69 ( V_28 ) ;
}
break;
default:
break;
}
switch ( V_124 ) {
case V_64 :
F_52 ( V_28 , L_13 ) ;
V_74 -> V_18 |= V_107 ;
V_74 -> V_75 [ 2 ] = V_137 ;
case V_126 :
V_125 = V_138 | V_139 | V_140 ;
V_56 = V_65 ;
break;
case V_131 :
V_125 = V_138 | V_139 | V_65 ;
V_56 = V_140 ;
break;
case V_127 :
V_125 = V_138 | V_65 |
V_139 | V_140 ;
V_56 = 0 ;
V_74 -> V_18 |= V_141 ;
F_52 ( V_28 , L_14 ) ;
F_72 ( V_28 ) ;
V_2 -> V_38 . V_105 . V_142 ++ ;
if ( ! V_2 -> V_38 . V_143 ) {
F_39 ( V_28 , V_127 ) ;
return;
}
break;
default:
break;
}
F_23 ( V_2 , V_57 , V_125 ) ;
F_23 ( V_2 , V_67 , V_56 ) ;
}
static int F_73 ( const struct V_27 * V_28 ,
enum V_68 * V_63 )
{
struct V_49 V_50 ;
int V_144 ;
V_144 = F_37 ( V_28 , & V_50 ) ;
if ( V_144 )
return V_144 ;
if ( V_50 . V_54 < 96 && V_50 . V_53 < 96 )
* V_63 = V_64 ;
else if ( V_50 . V_54 < 128 && V_50 . V_53 < 128 )
* V_63 = V_126 ;
else if ( V_50 . V_54 < 256 && V_50 . V_53 < 256 )
* V_63 = V_131 ;
else
* V_63 = V_127 ;
return 0 ;
}
static void F_74 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
struct V_69 * V_70 ;
struct V_73 * V_74 ;
enum V_68 V_124 ;
T_1 V_99 ;
int V_144 ;
if ( F_75 ( V_2 ) ) {
V_99 = F_21 ( V_2 , V_100 ) ;
if ( F_42 ( V_99 & V_140 ) )
V_124 = V_127 ;
else if ( F_42 ( V_99 & V_65 ) )
V_124 = V_131 ;
else if ( F_42 ( V_99 & V_139 ) )
V_124 = V_126 ;
else if ( F_67 ( V_99 & V_138 ) )
V_124 = V_64 ;
else {
F_45 ( V_28 , L_15 ) ;
return;
}
} else {
V_144 = F_73 ( V_28 , & V_124 ) ;
if ( V_144 )
return;
}
if ( F_67 ( V_124 == V_2 -> V_38 . V_63 ) )
return;
V_70 = F_53 ( V_28 , & V_74 ) ;
if ( F_42 ( ! V_70 ) )
return;
F_70 ( V_28 , V_74 , V_124 ) ;
F_76 ( V_70 ) ;
V_28 -> V_72 . V_91 ++ ;
V_28 -> V_72 . V_92 += V_74 -> V_82 ;
V_2 -> V_38 . V_63 = V_124 ;
}
static T_4 F_77 ( int V_145 , void * V_146 )
{
struct V_27 * V_28 = V_146 ;
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_4 V_147 = V_148 ;
T_1 V_99 , V_149 ;
V_99 = F_21 ( V_2 , V_100 ) ;
V_149 = F_21 ( V_2 , V_150 ) ;
V_99 &= V_149 ;
if ( ! V_99 )
goto exit;
V_147 = V_151 ;
if ( V_99 & ( F_16 ( V_2 ) | V_66 ) ) {
V_2 -> V_99 = V_99 ;
F_23 ( V_2 , V_57 ,
F_16 ( V_2 ) | V_66 ) ;
F_78 ( & V_2 -> V_119 ) ;
}
if ( V_99 & F_17 ( V_2 ) )
F_66 ( V_28 , V_99 ) ;
F_74 ( V_28 ) ;
exit:
return V_147 ;
}
static int F_79 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
int V_144 ;
V_144 = F_80 ( V_2 -> V_152 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_81 ( V_28 ) ;
if ( V_144 )
goto V_153;
if ( F_82 ( V_28 -> V_145 , F_77 , V_154 ,
V_28 -> V_155 , V_28 ) ) {
V_144 = - V_156 ;
goto V_157;
}
F_59 ( V_28 , V_158 ) ;
F_38 ( V_28 ) ;
F_83 ( & V_2 -> V_119 ) ;
F_84 ( V_28 ) ;
return 0 ;
V_157:
F_85 ( V_28 ) ;
V_153:
F_86 ( V_2 -> V_152 ) ;
return V_144 ;
}
static int F_87 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
F_44 ( V_28 ) ;
F_88 ( & V_2 -> V_119 ) ;
F_39 ( V_28 , V_159 ) ;
F_89 ( V_28 -> V_145 , V_28 ) ;
F_86 ( V_2 -> V_152 ) ;
F_85 ( V_28 ) ;
F_59 ( V_28 , V_160 ) ;
return 0 ;
}
static int F_90 ( struct V_27 * V_28 , enum V_161 V_16 )
{
switch ( V_16 ) {
case V_162 :
F_38 ( V_28 ) ;
F_69 ( V_28 ) ;
break;
default:
return - V_163 ;
}
return 0 ;
}
static T_5 F_91 ( struct V_164 * V_28 ,
struct V_165 * V_166 , char * V_167 )
{
struct V_1 * V_2 = F_31 ( F_92 ( V_28 ) ) ;
if ( V_2 -> V_30 & V_20 )
return snprintf ( V_167 , V_168 , L_16 , V_2 -> V_30 ) ;
else
return snprintf ( V_167 , V_168 , L_17 , V_2 -> V_30 ) ;
}
static T_5 F_93 ( struct V_164 * V_28 ,
struct V_165 * V_166 , const char * V_167 , T_6 V_169 )
{
struct V_27 * V_170 = F_92 ( V_28 ) ;
struct V_1 * V_2 = F_31 ( V_170 ) ;
unsigned long V_18 ;
T_5 V_171 ;
int V_144 ;
F_94 () ;
if ( V_170 -> V_172 & V_173 ) {
V_171 = - V_174 ;
goto V_153;
}
V_144 = F_95 ( V_167 , 0 , & V_18 ) ;
if ( V_144 ) {
V_171 = V_144 ;
goto V_153;
}
if ( V_18 & V_20 )
V_18 &= V_21 | V_20 ;
else
V_18 &= V_23 ;
V_2 -> V_30 = V_18 ;
V_171 = V_169 ;
V_153:
F_96 () ;
return V_171 ;
}
static const struct V_175 * F_97 ( struct V_176 * V_177 )
{
if ( V_177 -> V_28 . V_178 ) {
const struct V_179 * V_180 ;
V_180 = F_98 ( V_181 , V_177 -> V_28 . V_178 ) ;
if ( ! V_180 ) {
F_99 ( & V_177 -> V_28 , L_18 ) ;
return NULL ;
}
return ( const struct V_175 * ) V_180 -> V_75 ;
}
return ( const struct V_175 * )
F_100 ( V_177 ) -> V_182 ;
}
static int F_101 ( struct V_176 * V_177 )
{
const struct V_175 * V_3 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_183 * V_184 ;
struct V_152 * V_152 ;
void T_7 * V_101 ;
int V_144 , V_145 ;
V_3 = F_97 ( V_177 ) ;
if ( ! V_3 ) {
F_99 ( & V_177 -> V_28 , L_19 ) ;
V_144 = - V_185 ;
goto exit;
}
V_152 = F_102 ( & V_177 -> V_28 , L_20 ) ;
if ( F_103 ( V_152 ) ) {
F_99 ( & V_177 -> V_28 , L_21 ) ;
V_144 = - V_185 ;
goto exit;
}
V_184 = F_104 ( V_177 , V_186 , 0 ) ;
V_145 = F_105 ( V_177 , 0 ) ;
if ( ! V_184 || V_145 <= 0 ) {
V_144 = - V_185 ;
goto V_187;
}
if ( ! F_106 ( V_184 -> V_188 ,
F_107 ( V_184 ) ,
V_177 -> V_155 ) ) {
V_144 = - V_174 ;
goto V_187;
}
V_101 = F_108 ( V_184 -> V_188 , F_107 ( V_184 ) ) ;
if ( ! V_101 ) {
V_144 = - V_189 ;
goto V_190;
}
V_28 = F_109 ( sizeof( struct V_1 ) ,
1 << V_3 -> V_7 ) ;
if ( ! V_28 ) {
V_144 = - V_189 ;
goto V_191;
}
V_28 -> V_192 = & V_193 ;
V_28 -> V_145 = V_145 ;
V_28 -> V_172 |= V_194 ;
V_2 = F_31 ( V_28 ) ;
V_2 -> V_38 . clock . V_195 = F_110 ( V_152 ) ;
V_2 -> V_38 . V_196 = & V_197 ;
V_2 -> V_38 . V_198 = F_90 ;
V_2 -> V_38 . V_199 = F_37 ;
V_2 -> V_38 . V_200 = V_42 |
V_61 ;
V_2 -> V_12 = V_101 ;
V_2 -> V_3 = * V_3 ;
V_2 -> V_152 = V_152 ;
V_2 -> V_25 = F_111 ( & V_177 -> V_28 ) ;
V_2 -> V_30 = 0x7ff ;
F_112 ( V_28 , & V_2 -> V_119 , F_64 , F_4 ( V_2 ) ) ;
if ( F_75 ( V_2 ) )
V_28 -> V_201 [ 0 ] = & V_202 ;
F_113 ( V_177 , V_28 ) ;
F_114 ( V_28 , & V_177 -> V_28 ) ;
V_144 = F_115 ( V_28 ) ;
if ( V_144 ) {
F_99 ( & V_177 -> V_28 , L_22 ) ;
goto V_203;
}
F_116 ( V_28 ) ;
F_117 ( & V_177 -> V_28 , L_23 ,
V_2 -> V_12 , V_28 -> V_145 ) ;
return 0 ;
V_203:
F_118 ( V_28 ) ;
V_191:
F_119 ( V_101 ) ;
V_190:
F_120 ( V_184 -> V_188 , F_107 ( V_184 ) ) ;
V_187:
F_121 ( V_152 ) ;
exit:
return V_144 ;
}
static int F_122 ( struct V_176 * V_177 )
{
struct V_27 * V_28 = F_123 ( V_177 ) ;
struct V_1 * V_2 = F_31 ( V_28 ) ;
struct V_183 * V_184 ;
F_124 ( V_28 ) ;
F_119 ( V_2 -> V_12 ) ;
V_184 = F_104 ( V_177 , V_186 , 0 ) ;
F_120 ( V_184 -> V_188 , F_107 ( V_184 ) ) ;
F_121 ( V_2 -> V_152 ) ;
F_118 ( V_28 ) ;
return 0 ;
}
