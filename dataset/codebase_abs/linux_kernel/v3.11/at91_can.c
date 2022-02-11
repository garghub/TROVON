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
F_23 ( V_2 , V_59 , V_60 ) ;
V_2 -> V_38 . V_61 = V_62 ;
V_56 = F_16 ( V_2 ) | V_63 | V_64 ;
F_23 ( V_2 , V_57 , V_58 ) ;
F_23 ( V_2 , V_65 , V_56 ) ;
}
static void F_39 ( struct V_27 * V_28 , enum V_66 V_61 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_55 ;
F_23 ( V_2 , V_57 , V_58 ) ;
V_55 = F_21 ( V_2 , V_59 ) ;
F_23 ( V_2 , V_59 , V_55 & ~ V_60 ) ;
F_29 ( V_2 , 0 ) ;
V_2 -> V_38 . V_61 = V_61 ;
}
static T_3 F_40 ( struct V_67 * V_68 , struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
struct V_69 * V_70 = & V_28 -> V_70 ;
struct V_71 * V_72 = (struct V_71 * ) V_68 -> V_73 ;
unsigned int V_14 , V_17 ;
T_1 V_19 , V_74 ;
if ( F_41 ( V_28 , V_68 ) )
return V_75 ;
V_14 = F_18 ( V_2 ) ;
V_17 = F_19 ( V_2 ) ;
if ( F_42 ( ! ( F_21 ( V_2 , F_43 ( V_14 ) ) & V_76 ) ) ) {
F_44 ( V_28 ) ;
F_45 ( V_28 , L_2 ) ;
return V_77 ;
}
V_19 = F_28 ( V_72 -> V_18 ) ;
V_74 = ( ( V_72 -> V_18 & V_78 ) ? V_79 : 0 ) |
( V_72 -> V_80 << 16 ) | V_81 ;
F_27 ( V_2 , V_14 , V_31 ) ;
F_23 ( V_2 , F_32 ( V_14 ) , V_19 ) ;
F_25 ( V_2 , V_14 , V_34 , V_17 ) ;
F_23 ( V_2 , F_46 ( V_14 ) , * ( T_1 * ) ( V_72 -> V_73 + 0 ) ) ;
F_23 ( V_2 , F_47 ( V_14 ) , * ( T_1 * ) ( V_72 -> V_73 + 4 ) ) ;
F_23 ( V_2 , F_33 ( V_14 ) , V_74 ) ;
V_70 -> V_82 += V_72 -> V_80 ;
F_48 ( V_68 , V_28 , V_14 - F_10 ( V_2 ) ) ;
V_2 -> V_8 ++ ;
if ( ! ( F_21 ( V_2 , F_43 ( F_18 ( V_2 ) ) ) &
V_76 ) ||
( V_2 -> V_8 & F_15 ( V_2 ) ) == 0 )
F_44 ( V_28 ) ;
F_23 ( V_2 , V_65 , 1 << V_14 ) ;
return V_75 ;
}
static inline void F_49 ( const struct V_1 * V_2 )
{
T_1 V_83 = F_6 ( V_2 ) ;
F_23 ( V_2 , V_84 , V_83 ) ;
}
static inline void F_50 ( const struct V_1 * V_2 ,
unsigned int V_14 )
{
T_1 V_83 = 1 << V_14 ;
F_23 ( V_2 , V_84 , V_83 ) ;
}
static void F_51 ( struct V_27 * V_28 )
{
struct V_69 * V_70 = & V_28 -> V_70 ;
struct V_67 * V_68 ;
struct V_71 * V_72 ;
F_52 ( V_28 , L_3 ) ;
V_70 -> V_85 ++ ;
V_70 -> V_86 ++ ;
V_68 = F_53 ( V_28 , & V_72 ) ;
if ( F_42 ( ! V_68 ) )
return;
V_72 -> V_18 |= V_87 ;
V_72 -> V_73 [ 1 ] = V_88 ;
F_54 ( V_68 ) ;
V_70 -> V_89 ++ ;
V_70 -> V_90 += V_72 -> V_80 ;
}
static void F_55 ( struct V_27 * V_28 , unsigned int V_14 ,
struct V_71 * V_72 )
{
const struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_91 , V_19 ;
V_19 = F_21 ( V_2 , F_32 ( V_14 ) ) ;
if ( V_19 & V_22 )
V_72 -> V_18 = ( ( V_19 >> 0 ) & V_21 ) | V_20 ;
else
V_72 -> V_18 = ( V_19 >> 18 ) & V_23 ;
V_91 = F_21 ( V_2 , F_43 ( V_14 ) ) ;
V_72 -> V_80 = F_56 ( ( V_91 >> 16 ) & 0xf ) ;
if ( V_91 & V_92 )
V_72 -> V_18 |= V_78 ;
else {
* ( T_1 * ) ( V_72 -> V_73 + 0 ) = F_21 ( V_2 , F_46 ( V_14 ) ) ;
* ( T_1 * ) ( V_72 -> V_73 + 4 ) = F_21 ( V_2 , F_47 ( V_14 ) ) ;
}
F_23 ( V_2 , F_32 ( V_14 ) , V_22 ) ;
if ( F_42 ( V_14 == F_2 ( V_2 ) && V_91 & V_93 ) )
F_51 ( V_28 ) ;
}
static void F_57 ( struct V_27 * V_28 , unsigned int V_14 )
{
struct V_69 * V_70 = & V_28 -> V_70 ;
struct V_71 * V_72 ;
struct V_67 * V_68 ;
V_68 = F_58 ( V_28 , & V_72 ) ;
if ( F_42 ( ! V_68 ) ) {
V_70 -> V_94 ++ ;
return;
}
F_55 ( V_28 , V_14 , V_72 ) ;
F_54 ( V_68 ) ;
V_70 -> V_89 ++ ;
V_70 -> V_90 += V_72 -> V_80 ;
F_59 ( V_28 , V_95 ) ;
}
static int F_60 ( struct V_27 * V_28 , int V_96 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_97 = F_21 ( V_2 , V_98 ) ;
const unsigned long * V_99 = ( unsigned long * ) & V_97 ;
unsigned int V_14 ;
int V_100 = 0 ;
if ( V_2 -> V_35 > F_5 ( V_2 ) &&
V_97 & F_6 ( V_2 ) )
F_36 ( V_28 ,
L_4 ) ;
V_101:
for ( V_14 = F_61 ( V_99 , F_10 ( V_2 ) , V_2 -> V_35 ) ;
V_14 < F_10 ( V_2 ) && V_96 > 0 ;
V_97 = F_21 ( V_2 , V_98 ) ,
V_14 = F_61 ( V_99 , F_10 ( V_2 ) , ++ V_2 -> V_35 ) ) {
F_57 ( V_28 , V_14 ) ;
if ( V_14 == F_5 ( V_2 ) )
F_49 ( V_2 ) ;
else if ( V_14 > F_5 ( V_2 ) )
F_50 ( V_2 , V_14 ) ;
V_100 ++ ;
V_96 -- ;
}
if ( V_2 -> V_35 > F_5 ( V_2 ) &&
V_96 > 0 && V_14 > F_2 ( V_2 ) ) {
V_2 -> V_35 = F_1 ( V_2 ) ;
goto V_101;
}
return V_100 ;
}
static void F_62 ( struct V_27 * V_28 ,
struct V_71 * V_72 , T_1 V_97 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
if ( V_97 & V_102 ) {
F_52 ( V_28 , L_5 ) ;
V_28 -> V_70 . V_86 ++ ;
V_2 -> V_38 . V_103 . V_104 ++ ;
V_72 -> V_18 |= V_105 | V_106 ;
}
if ( V_97 & V_107 ) {
F_52 ( V_28 , L_6 ) ;
V_28 -> V_70 . V_86 ++ ;
V_2 -> V_38 . V_103 . V_104 ++ ;
V_72 -> V_18 |= V_105 | V_106 ;
V_72 -> V_73 [ 2 ] |= V_108 ;
}
if ( V_97 & V_109 ) {
F_52 ( V_28 , L_7 ) ;
V_28 -> V_70 . V_110 ++ ;
V_72 -> V_18 |= V_111 ;
}
if ( V_97 & V_112 ) {
F_52 ( V_28 , L_8 ) ;
V_28 -> V_70 . V_86 ++ ;
V_2 -> V_38 . V_103 . V_104 ++ ;
V_72 -> V_18 |= V_105 | V_106 ;
V_72 -> V_73 [ 2 ] |= V_113 ;
}
if ( V_97 & V_114 ) {
F_52 ( V_28 , L_9 ) ;
V_28 -> V_70 . V_110 ++ ;
V_2 -> V_38 . V_103 . V_104 ++ ;
V_72 -> V_18 |= V_105 | V_106 ;
V_72 -> V_73 [ 2 ] |= V_115 ;
}
}
static int F_63 ( struct V_27 * V_28 , int V_96 , T_1 V_97 )
{
struct V_67 * V_68 ;
struct V_71 * V_72 ;
if ( V_96 == 0 )
return 0 ;
V_68 = F_53 ( V_28 , & V_72 ) ;
if ( F_42 ( ! V_68 ) )
return 0 ;
F_62 ( V_28 , V_72 , V_97 ) ;
F_54 ( V_68 ) ;
V_28 -> V_70 . V_89 ++ ;
V_28 -> V_70 . V_90 += V_72 -> V_80 ;
return 1 ;
}
static int F_64 ( struct V_116 * V_117 , int V_96 )
{
struct V_27 * V_28 = V_117 -> V_28 ;
const struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_97 = F_21 ( V_2 , V_98 ) ;
int V_118 = 0 ;
if ( V_97 & F_16 ( V_2 ) )
V_118 += F_60 ( V_28 , V_96 - V_118 ) ;
V_97 |= V_2 -> V_97 ;
if ( V_97 & V_64 )
V_118 += F_63 ( V_28 , V_96 - V_118 , V_97 ) ;
if ( V_118 < V_96 ) {
T_1 V_56 = V_64 ;
V_56 |= F_16 ( V_2 ) & ~ F_7 ( V_2 -> V_35 ) ;
F_65 ( V_117 ) ;
F_23 ( V_2 , V_65 , V_56 ) ;
}
return V_118 ;
}
static void F_66 ( struct V_27 * V_28 , T_1 V_97 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_91 ;
unsigned int V_14 ;
for (; ( V_2 -> V_8 - V_2 -> V_9 ) > 0 ; V_2 -> V_9 ++ ) {
V_14 = F_20 ( V_2 ) ;
if ( ! ( V_97 & ( 1 << V_14 ) ) )
break;
F_23 ( V_2 , V_57 , 1 << V_14 ) ;
V_91 = F_21 ( V_2 , F_43 ( V_14 ) ) ;
if ( F_67 ( V_91 & V_76 &&
~ V_91 & V_119 ) ) {
F_68 ( V_28 , V_14 - F_10 ( V_2 ) ) ;
V_28 -> V_70 . V_120 ++ ;
F_59 ( V_28 , V_121 ) ;
}
}
if ( ( V_2 -> V_8 & F_15 ( V_2 ) ) != 0 ||
( V_2 -> V_9 & F_15 ( V_2 ) ) == 0 )
F_69 ( V_28 ) ;
}
static void F_70 ( struct V_27 * V_28 ,
struct V_71 * V_72 , enum V_66 V_122 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_123 = 0 , V_56 = 0 ;
struct V_49 V_50 ;
F_37 ( V_28 , & V_50 ) ;
switch ( V_2 -> V_38 . V_61 ) {
case V_62 :
if ( V_122 >= V_124 &&
V_122 <= V_125 ) {
F_52 ( V_28 , L_10 ) ;
V_2 -> V_38 . V_103 . V_126 ++ ;
V_72 -> V_18 |= V_87 ;
V_72 -> V_73 [ 1 ] = ( V_50 . V_54 > V_50 . V_53 ) ?
V_127 :
V_128 ;
}
case V_124 :
if ( V_122 >= V_129 &&
V_122 <= V_125 ) {
F_52 ( V_28 , L_11 ) ;
V_2 -> V_38 . V_103 . V_130 ++ ;
V_72 -> V_18 |= V_87 ;
V_72 -> V_73 [ 1 ] = ( V_50 . V_54 > V_50 . V_53 ) ?
V_131 :
V_132 ;
}
break;
case V_125 :
if ( V_122 <= V_129 ) {
V_72 -> V_18 |= V_133 ;
F_52 ( V_28 , L_12 ) ;
V_2 -> V_38 . V_103 . V_134 ++ ;
F_71 ( V_28 ) ;
F_69 ( V_28 ) ;
}
break;
default:
break;
}
switch ( V_122 ) {
case V_62 :
F_52 ( V_28 , L_13 ) ;
V_72 -> V_18 |= V_105 ;
V_72 -> V_73 [ 2 ] = V_135 ;
case V_124 :
V_123 = V_136 | V_137 | V_138 ;
V_56 = V_63 ;
break;
case V_129 :
V_123 = V_136 | V_137 | V_63 ;
V_56 = V_138 ;
break;
case V_125 :
V_123 = V_136 | V_63 |
V_137 | V_138 ;
V_56 = 0 ;
V_72 -> V_18 |= V_139 ;
F_52 ( V_28 , L_14 ) ;
F_72 ( V_28 ) ;
V_2 -> V_38 . V_103 . V_140 ++ ;
if ( ! V_2 -> V_38 . V_141 ) {
F_39 ( V_28 , V_125 ) ;
return;
}
break;
default:
break;
}
F_23 ( V_2 , V_57 , V_123 ) ;
F_23 ( V_2 , V_65 , V_56 ) ;
}
static int F_73 ( const struct V_27 * V_28 ,
enum V_66 * V_61 )
{
struct V_49 V_50 ;
int V_142 ;
V_142 = F_37 ( V_28 , & V_50 ) ;
if ( V_142 )
return V_142 ;
if ( V_50 . V_54 < 96 && V_50 . V_53 < 96 )
* V_61 = V_62 ;
else if ( V_50 . V_54 < 128 && V_50 . V_53 < 128 )
* V_61 = V_124 ;
else if ( V_50 . V_54 < 256 && V_50 . V_53 < 256 )
* V_61 = V_129 ;
else
* V_61 = V_125 ;
return 0 ;
}
static void F_74 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
struct V_67 * V_68 ;
struct V_71 * V_72 ;
enum V_66 V_122 ;
T_1 V_97 ;
int V_142 ;
if ( F_75 ( V_2 ) ) {
V_97 = F_21 ( V_2 , V_98 ) ;
if ( F_42 ( V_97 & V_138 ) )
V_122 = V_125 ;
else if ( F_42 ( V_97 & V_63 ) )
V_122 = V_129 ;
else if ( F_42 ( V_97 & V_137 ) )
V_122 = V_124 ;
else if ( F_67 ( V_97 & V_136 ) )
V_122 = V_62 ;
else {
F_45 ( V_28 , L_15 ) ;
return;
}
} else {
V_142 = F_73 ( V_28 , & V_122 ) ;
if ( V_142 )
return;
}
if ( F_67 ( V_122 == V_2 -> V_38 . V_61 ) )
return;
V_68 = F_53 ( V_28 , & V_72 ) ;
if ( F_42 ( ! V_68 ) )
return;
F_70 ( V_28 , V_72 , V_122 ) ;
F_76 ( V_68 ) ;
V_28 -> V_70 . V_89 ++ ;
V_28 -> V_70 . V_90 += V_72 -> V_80 ;
V_2 -> V_38 . V_61 = V_122 ;
}
static T_4 F_77 ( int V_143 , void * V_144 )
{
struct V_27 * V_28 = V_144 ;
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_4 V_145 = V_146 ;
T_1 V_97 , V_147 ;
V_97 = F_21 ( V_2 , V_98 ) ;
V_147 = F_21 ( V_2 , V_148 ) ;
V_97 &= V_147 ;
if ( ! V_97 )
goto exit;
V_145 = V_149 ;
if ( V_97 & ( F_16 ( V_2 ) | V_64 ) ) {
V_2 -> V_97 = V_97 ;
F_23 ( V_2 , V_57 ,
F_16 ( V_2 ) | V_64 ) ;
F_78 ( & V_2 -> V_117 ) ;
}
if ( V_97 & F_17 ( V_2 ) )
F_66 ( V_28 , V_97 ) ;
F_74 ( V_28 ) ;
exit:
return V_145 ;
}
static int F_79 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
int V_142 ;
F_80 ( V_2 -> V_150 ) ;
V_142 = F_81 ( V_28 ) ;
if ( V_142 )
goto V_151;
if ( F_82 ( V_28 -> V_143 , F_77 , V_152 ,
V_28 -> V_153 , V_28 ) ) {
V_142 = - V_154 ;
goto V_155;
}
F_59 ( V_28 , V_156 ) ;
F_38 ( V_28 ) ;
F_83 ( & V_2 -> V_117 ) ;
F_84 ( V_28 ) ;
return 0 ;
V_155:
F_85 ( V_28 ) ;
V_151:
F_86 ( V_2 -> V_150 ) ;
return V_142 ;
}
static int F_87 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
F_44 ( V_28 ) ;
F_88 ( & V_2 -> V_117 ) ;
F_39 ( V_28 , V_157 ) ;
F_89 ( V_28 -> V_143 , V_28 ) ;
F_86 ( V_2 -> V_150 ) ;
F_85 ( V_28 ) ;
F_59 ( V_28 , V_158 ) ;
return 0 ;
}
static int F_90 ( struct V_27 * V_28 , enum V_159 V_16 )
{
switch ( V_16 ) {
case V_160 :
F_38 ( V_28 ) ;
F_69 ( V_28 ) ;
break;
default:
return - V_161 ;
}
return 0 ;
}
static T_5 F_91 ( struct V_162 * V_28 ,
struct V_163 * V_164 , char * V_165 )
{
struct V_1 * V_2 = F_31 ( F_92 ( V_28 ) ) ;
if ( V_2 -> V_30 & V_20 )
return snprintf ( V_165 , V_166 , L_16 , V_2 -> V_30 ) ;
else
return snprintf ( V_165 , V_166 , L_17 , V_2 -> V_30 ) ;
}
static T_5 F_93 ( struct V_162 * V_28 ,
struct V_163 * V_164 , const char * V_165 , T_6 V_167 )
{
struct V_27 * V_168 = F_92 ( V_28 ) ;
struct V_1 * V_2 = F_31 ( V_168 ) ;
unsigned long V_18 ;
T_5 V_169 ;
int V_142 ;
F_94 () ;
if ( V_168 -> V_170 & V_171 ) {
V_169 = - V_172 ;
goto V_151;
}
V_142 = F_95 ( V_165 , 0 , & V_18 ) ;
if ( V_142 ) {
V_169 = V_142 ;
goto V_151;
}
if ( V_18 & V_20 )
V_18 &= V_21 | V_20 ;
else
V_18 &= V_23 ;
V_2 -> V_30 = V_18 ;
V_169 = V_167 ;
V_151:
F_96 () ;
return V_169 ;
}
static const struct V_173 * F_97 ( struct V_174 * V_175 )
{
if ( V_175 -> V_28 . V_176 ) {
const struct V_177 * V_178 ;
V_178 = F_98 ( V_179 , V_175 -> V_28 . V_176 ) ;
if ( ! V_178 ) {
F_99 ( & V_175 -> V_28 , L_18 ) ;
return NULL ;
}
return ( const struct V_173 * ) V_178 -> V_73 ;
}
return ( const struct V_173 * )
F_100 ( V_175 ) -> V_180 ;
}
static int F_101 ( struct V_174 * V_175 )
{
const struct V_173 * V_3 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_181 * V_182 ;
struct V_150 * V_150 ;
void T_7 * V_99 ;
int V_142 , V_143 ;
V_3 = F_97 ( V_175 ) ;
if ( ! V_3 ) {
F_99 ( & V_175 -> V_28 , L_19 ) ;
V_142 = - V_183 ;
goto exit;
}
V_150 = F_102 ( & V_175 -> V_28 , L_20 ) ;
if ( F_103 ( V_150 ) ) {
F_99 ( & V_175 -> V_28 , L_21 ) ;
V_142 = - V_183 ;
goto exit;
}
V_182 = F_104 ( V_175 , V_184 , 0 ) ;
V_143 = F_105 ( V_175 , 0 ) ;
if ( ! V_182 || V_143 <= 0 ) {
V_142 = - V_183 ;
goto V_185;
}
if ( ! F_106 ( V_182 -> V_186 ,
F_107 ( V_182 ) ,
V_175 -> V_153 ) ) {
V_142 = - V_172 ;
goto V_185;
}
V_99 = F_108 ( V_182 -> V_186 , F_107 ( V_182 ) ) ;
if ( ! V_99 ) {
V_142 = - V_187 ;
goto V_188;
}
V_28 = F_109 ( sizeof( struct V_1 ) ,
1 << V_3 -> V_7 ) ;
if ( ! V_28 ) {
V_142 = - V_187 ;
goto V_189;
}
V_28 -> V_190 = & V_191 ;
V_28 -> V_143 = V_143 ;
V_28 -> V_170 |= V_192 ;
V_2 = F_31 ( V_28 ) ;
V_2 -> V_38 . clock . V_193 = F_110 ( V_150 ) ;
V_2 -> V_38 . V_194 = & V_195 ;
V_2 -> V_38 . V_196 = F_90 ;
V_2 -> V_38 . V_197 = F_37 ;
V_2 -> V_38 . V_198 = V_42 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_12 = V_99 ;
V_2 -> V_3 = * V_3 ;
V_2 -> V_150 = V_150 ;
V_2 -> V_25 = V_175 -> V_28 . V_199 ;
V_2 -> V_30 = 0x7ff ;
F_111 ( V_28 , & V_2 -> V_117 , F_64 , F_4 ( V_2 ) ) ;
if ( F_75 ( V_2 ) )
V_28 -> V_200 [ 0 ] = & V_201 ;
F_112 ( & V_175 -> V_28 , V_28 ) ;
F_113 ( V_28 , & V_175 -> V_28 ) ;
V_142 = F_114 ( V_28 ) ;
if ( V_142 ) {
F_99 ( & V_175 -> V_28 , L_22 ) ;
goto V_202;
}
F_115 ( V_28 ) ;
F_116 ( & V_175 -> V_28 , L_23 ,
V_2 -> V_12 , V_28 -> V_143 ) ;
return 0 ;
V_202:
F_117 ( V_28 ) ;
V_189:
F_118 ( V_99 ) ;
V_188:
F_119 ( V_182 -> V_186 , F_107 ( V_182 ) ) ;
V_185:
F_120 ( V_150 ) ;
exit:
return V_142 ;
}
static int F_121 ( struct V_174 * V_175 )
{
struct V_27 * V_28 = F_122 ( V_175 ) ;
struct V_1 * V_2 = F_31 ( V_28 ) ;
struct V_181 * V_182 ;
F_123 ( V_28 ) ;
F_118 ( V_2 -> V_12 ) ;
V_182 = F_104 ( V_175 , V_184 , 0 ) ;
F_119 ( V_182 -> V_186 , F_107 ( V_182 ) ) ;
F_120 ( V_2 -> V_150 ) ;
F_117 ( V_28 ) ;
return 0 ;
}
