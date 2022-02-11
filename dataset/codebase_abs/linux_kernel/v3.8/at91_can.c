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
}
static int F_59 ( struct V_27 * V_28 , int V_95 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_96 = F_21 ( V_2 , V_97 ) ;
const unsigned long * V_98 = ( unsigned long * ) & V_96 ;
unsigned int V_14 ;
int V_99 = 0 ;
if ( V_2 -> V_35 > F_5 ( V_2 ) &&
V_96 & F_6 ( V_2 ) )
F_36 ( V_28 ,
L_4 ) ;
V_100:
for ( V_14 = F_60 ( V_98 , F_10 ( V_2 ) , V_2 -> V_35 ) ;
V_14 < F_10 ( V_2 ) && V_95 > 0 ;
V_96 = F_21 ( V_2 , V_97 ) ,
V_14 = F_60 ( V_98 , F_10 ( V_2 ) , ++ V_2 -> V_35 ) ) {
F_57 ( V_28 , V_14 ) ;
if ( V_14 == F_5 ( V_2 ) )
F_49 ( V_2 ) ;
else if ( V_14 > F_5 ( V_2 ) )
F_50 ( V_2 , V_14 ) ;
V_99 ++ ;
V_95 -- ;
}
if ( V_2 -> V_35 > F_5 ( V_2 ) &&
V_95 > 0 && V_14 > F_2 ( V_2 ) ) {
V_2 -> V_35 = F_1 ( V_2 ) ;
goto V_100;
}
return V_99 ;
}
static void F_61 ( struct V_27 * V_28 ,
struct V_71 * V_72 , T_1 V_96 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
if ( V_96 & V_101 ) {
F_52 ( V_28 , L_5 ) ;
V_28 -> V_70 . V_86 ++ ;
V_2 -> V_38 . V_102 . V_103 ++ ;
V_72 -> V_18 |= V_104 | V_105 ;
}
if ( V_96 & V_106 ) {
F_52 ( V_28 , L_6 ) ;
V_28 -> V_70 . V_86 ++ ;
V_2 -> V_38 . V_102 . V_103 ++ ;
V_72 -> V_18 |= V_104 | V_105 ;
V_72 -> V_73 [ 2 ] |= V_107 ;
}
if ( V_96 & V_108 ) {
F_52 ( V_28 , L_7 ) ;
V_28 -> V_70 . V_109 ++ ;
V_72 -> V_18 |= V_110 ;
}
if ( V_96 & V_111 ) {
F_52 ( V_28 , L_8 ) ;
V_28 -> V_70 . V_86 ++ ;
V_2 -> V_38 . V_102 . V_103 ++ ;
V_72 -> V_18 |= V_104 | V_105 ;
V_72 -> V_73 [ 2 ] |= V_112 ;
}
if ( V_96 & V_113 ) {
F_52 ( V_28 , L_9 ) ;
V_28 -> V_70 . V_109 ++ ;
V_2 -> V_38 . V_102 . V_103 ++ ;
V_72 -> V_18 |= V_104 | V_105 ;
V_72 -> V_73 [ 2 ] |= V_114 ;
}
}
static int F_62 ( struct V_27 * V_28 , int V_95 , T_1 V_96 )
{
struct V_67 * V_68 ;
struct V_71 * V_72 ;
if ( V_95 == 0 )
return 0 ;
V_68 = F_53 ( V_28 , & V_72 ) ;
if ( F_42 ( ! V_68 ) )
return 0 ;
F_61 ( V_28 , V_72 , V_96 ) ;
F_54 ( V_68 ) ;
V_28 -> V_70 . V_89 ++ ;
V_28 -> V_70 . V_90 += V_72 -> V_80 ;
return 1 ;
}
static int F_63 ( struct V_115 * V_116 , int V_95 )
{
struct V_27 * V_28 = V_116 -> V_28 ;
const struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_96 = F_21 ( V_2 , V_97 ) ;
int V_117 = 0 ;
if ( V_96 & F_16 ( V_2 ) )
V_117 += F_59 ( V_28 , V_95 - V_117 ) ;
V_96 |= V_2 -> V_96 ;
if ( V_96 & V_64 )
V_117 += F_62 ( V_28 , V_95 - V_117 , V_96 ) ;
if ( V_117 < V_95 ) {
T_1 V_56 = V_64 ;
V_56 |= F_16 ( V_2 ) & ~ F_7 ( V_2 -> V_35 ) ;
F_64 ( V_116 ) ;
F_23 ( V_2 , V_65 , V_56 ) ;
}
return V_117 ;
}
static void F_65 ( struct V_27 * V_28 , T_1 V_96 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_91 ;
unsigned int V_14 ;
for (; ( V_2 -> V_8 - V_2 -> V_9 ) > 0 ; V_2 -> V_9 ++ ) {
V_14 = F_20 ( V_2 ) ;
if ( ! ( V_96 & ( 1 << V_14 ) ) )
break;
F_23 ( V_2 , V_57 , 1 << V_14 ) ;
V_91 = F_21 ( V_2 , F_43 ( V_14 ) ) ;
if ( F_66 ( V_91 & V_76 &&
~ V_91 & V_118 ) ) {
F_67 ( V_28 , V_14 - F_10 ( V_2 ) ) ;
V_28 -> V_70 . V_119 ++ ;
}
}
if ( ( V_2 -> V_8 & F_15 ( V_2 ) ) != 0 ||
( V_2 -> V_9 & F_15 ( V_2 ) ) == 0 )
F_68 ( V_28 ) ;
}
static void F_69 ( struct V_27 * V_28 ,
struct V_71 * V_72 , enum V_66 V_120 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_1 V_121 = 0 , V_56 = 0 ;
struct V_49 V_50 ;
F_37 ( V_28 , & V_50 ) ;
switch ( V_2 -> V_38 . V_61 ) {
case V_62 :
if ( V_120 >= V_122 &&
V_120 <= V_123 ) {
F_52 ( V_28 , L_10 ) ;
V_2 -> V_38 . V_102 . V_124 ++ ;
V_72 -> V_18 |= V_87 ;
V_72 -> V_73 [ 1 ] = ( V_50 . V_54 > V_50 . V_53 ) ?
V_125 :
V_126 ;
}
case V_122 :
if ( V_120 >= V_127 &&
V_120 <= V_123 ) {
F_52 ( V_28 , L_11 ) ;
V_2 -> V_38 . V_102 . V_128 ++ ;
V_72 -> V_18 |= V_87 ;
V_72 -> V_73 [ 1 ] = ( V_50 . V_54 > V_50 . V_53 ) ?
V_129 :
V_130 ;
}
break;
case V_123 :
if ( V_120 <= V_127 ) {
V_72 -> V_18 |= V_131 ;
F_52 ( V_28 , L_12 ) ;
V_2 -> V_38 . V_102 . V_132 ++ ;
F_70 ( V_28 ) ;
F_68 ( V_28 ) ;
}
break;
default:
break;
}
switch ( V_120 ) {
case V_62 :
F_52 ( V_28 , L_13 ) ;
V_72 -> V_18 |= V_104 ;
V_72 -> V_73 [ 2 ] = V_133 ;
case V_122 :
V_121 = V_134 | V_135 | V_136 ;
V_56 = V_63 ;
break;
case V_127 :
V_121 = V_134 | V_135 | V_63 ;
V_56 = V_136 ;
break;
case V_123 :
V_121 = V_134 | V_63 |
V_135 | V_136 ;
V_56 = 0 ;
V_72 -> V_18 |= V_137 ;
F_52 ( V_28 , L_14 ) ;
F_71 ( V_28 ) ;
V_2 -> V_38 . V_102 . V_138 ++ ;
if ( ! V_2 -> V_38 . V_139 ) {
F_39 ( V_28 , V_123 ) ;
return;
}
break;
default:
break;
}
F_23 ( V_2 , V_57 , V_121 ) ;
F_23 ( V_2 , V_65 , V_56 ) ;
}
static int F_72 ( const struct V_27 * V_28 ,
enum V_66 * V_61 )
{
struct V_49 V_50 ;
int V_140 ;
V_140 = F_37 ( V_28 , & V_50 ) ;
if ( V_140 )
return V_140 ;
if ( V_50 . V_54 < 96 && V_50 . V_53 < 96 )
* V_61 = V_62 ;
else if ( V_50 . V_54 < 128 && V_50 . V_53 < 128 )
* V_61 = V_122 ;
else if ( V_50 . V_54 < 256 && V_50 . V_53 < 256 )
* V_61 = V_127 ;
else
* V_61 = V_123 ;
return 0 ;
}
static void F_73 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
struct V_67 * V_68 ;
struct V_71 * V_72 ;
enum V_66 V_120 ;
T_1 V_96 ;
int V_140 ;
if ( F_74 ( V_2 ) ) {
V_96 = F_21 ( V_2 , V_97 ) ;
if ( F_42 ( V_96 & V_136 ) )
V_120 = V_123 ;
else if ( F_42 ( V_96 & V_63 ) )
V_120 = V_127 ;
else if ( F_42 ( V_96 & V_135 ) )
V_120 = V_122 ;
else if ( F_66 ( V_96 & V_134 ) )
V_120 = V_62 ;
else {
F_45 ( V_28 , L_15 ) ;
return;
}
} else {
V_140 = F_72 ( V_28 , & V_120 ) ;
if ( V_140 )
return;
}
if ( F_66 ( V_120 == V_2 -> V_38 . V_61 ) )
return;
V_68 = F_53 ( V_28 , & V_72 ) ;
if ( F_42 ( ! V_68 ) )
return;
F_69 ( V_28 , V_72 , V_120 ) ;
F_75 ( V_68 ) ;
V_28 -> V_70 . V_89 ++ ;
V_28 -> V_70 . V_90 += V_72 -> V_80 ;
V_2 -> V_38 . V_61 = V_120 ;
}
static T_4 F_76 ( int V_141 , void * V_142 )
{
struct V_27 * V_28 = V_142 ;
struct V_1 * V_2 = F_31 ( V_28 ) ;
T_4 V_143 = V_144 ;
T_1 V_96 , V_145 ;
V_96 = F_21 ( V_2 , V_97 ) ;
V_145 = F_21 ( V_2 , V_146 ) ;
V_96 &= V_145 ;
if ( ! V_96 )
goto exit;
V_143 = V_147 ;
if ( V_96 & ( F_16 ( V_2 ) | V_64 ) ) {
V_2 -> V_96 = V_96 ;
F_23 ( V_2 , V_57 ,
F_16 ( V_2 ) | V_64 ) ;
F_77 ( & V_2 -> V_116 ) ;
}
if ( V_96 & F_17 ( V_2 ) )
F_65 ( V_28 , V_96 ) ;
F_73 ( V_28 ) ;
exit:
return V_143 ;
}
static int F_78 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
int V_140 ;
F_79 ( V_2 -> V_148 ) ;
V_140 = F_80 ( V_28 ) ;
if ( V_140 )
goto V_149;
if ( F_81 ( V_28 -> V_141 , F_76 , V_150 ,
V_28 -> V_151 , V_28 ) ) {
V_140 = - V_152 ;
goto V_153;
}
F_38 ( V_28 ) ;
F_82 ( & V_2 -> V_116 ) ;
F_83 ( V_28 ) ;
return 0 ;
V_153:
F_84 ( V_28 ) ;
V_149:
F_85 ( V_2 -> V_148 ) ;
return V_140 ;
}
static int F_86 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_31 ( V_28 ) ;
F_44 ( V_28 ) ;
F_87 ( & V_2 -> V_116 ) ;
F_39 ( V_28 , V_154 ) ;
F_88 ( V_28 -> V_141 , V_28 ) ;
F_85 ( V_2 -> V_148 ) ;
F_84 ( V_28 ) ;
return 0 ;
}
static int F_89 ( struct V_27 * V_28 , enum V_155 V_16 )
{
switch ( V_16 ) {
case V_156 :
F_38 ( V_28 ) ;
F_68 ( V_28 ) ;
break;
default:
return - V_157 ;
}
return 0 ;
}
static T_5 F_90 ( struct V_158 * V_28 ,
struct V_159 * V_160 , char * V_161 )
{
struct V_1 * V_2 = F_31 ( F_91 ( V_28 ) ) ;
if ( V_2 -> V_30 & V_20 )
return snprintf ( V_161 , V_162 , L_16 , V_2 -> V_30 ) ;
else
return snprintf ( V_161 , V_162 , L_17 , V_2 -> V_30 ) ;
}
static T_5 F_92 ( struct V_158 * V_28 ,
struct V_159 * V_160 , const char * V_161 , T_6 V_163 )
{
struct V_27 * V_164 = F_91 ( V_28 ) ;
struct V_1 * V_2 = F_31 ( V_164 ) ;
unsigned long V_18 ;
T_5 V_165 ;
int V_140 ;
F_93 () ;
if ( V_164 -> V_166 & V_167 ) {
V_165 = - V_168 ;
goto V_149;
}
V_140 = F_94 ( V_161 , 0 , & V_18 ) ;
if ( V_140 ) {
V_165 = V_140 ;
goto V_149;
}
if ( V_18 & V_20 )
V_18 &= V_21 | V_20 ;
else
V_18 &= V_23 ;
V_2 -> V_30 = V_18 ;
V_165 = V_163 ;
V_149:
F_95 () ;
return V_165 ;
}
static int F_96 ( struct V_169 * V_170 )
{
const struct V_171 * V_3 ;
enum V_172 V_173 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_174 * V_175 ;
struct V_148 * V_148 ;
void T_7 * V_98 ;
int V_140 , V_141 ;
V_173 = V_170 -> V_176 -> V_177 ;
V_3 = & V_171 [ V_173 ] ;
V_148 = F_97 ( & V_170 -> V_28 , L_18 ) ;
if ( F_98 ( V_148 ) ) {
F_99 ( & V_170 -> V_28 , L_19 ) ;
V_140 = - V_178 ;
goto exit;
}
V_175 = F_100 ( V_170 , V_179 , 0 ) ;
V_141 = F_101 ( V_170 , 0 ) ;
if ( ! V_175 || V_141 <= 0 ) {
V_140 = - V_178 ;
goto V_180;
}
if ( ! F_102 ( V_175 -> V_181 ,
F_103 ( V_175 ) ,
V_170 -> V_151 ) ) {
V_140 = - V_168 ;
goto V_180;
}
V_98 = F_104 ( V_175 -> V_181 , F_103 ( V_175 ) ) ;
if ( ! V_98 ) {
V_140 = - V_182 ;
goto V_183;
}
V_28 = F_105 ( sizeof( struct V_1 ) ,
1 << V_3 -> V_7 ) ;
if ( ! V_28 ) {
V_140 = - V_182 ;
goto V_184;
}
V_28 -> V_185 = & V_186 ;
V_28 -> V_141 = V_141 ;
V_28 -> V_166 |= V_187 ;
V_2 = F_31 ( V_28 ) ;
V_2 -> V_38 . clock . V_188 = F_106 ( V_148 ) ;
V_2 -> V_38 . V_189 = & V_190 ;
V_2 -> V_38 . V_191 = F_89 ;
V_2 -> V_38 . V_192 = F_37 ;
V_2 -> V_38 . V_193 = V_42 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_12 = V_98 ;
V_2 -> V_3 = * V_3 ;
V_2 -> V_3 . type = V_173 ;
V_2 -> V_148 = V_148 ;
V_2 -> V_25 = V_170 -> V_28 . V_194 ;
V_2 -> V_30 = 0x7ff ;
F_107 ( V_28 , & V_2 -> V_116 , F_63 , F_4 ( V_2 ) ) ;
if ( F_74 ( V_2 ) )
V_28 -> V_195 [ 0 ] = & V_196 ;
F_108 ( & V_170 -> V_28 , V_28 ) ;
F_109 ( V_28 , & V_170 -> V_28 ) ;
V_140 = F_110 ( V_28 ) ;
if ( V_140 ) {
F_99 ( & V_170 -> V_28 , L_20 ) ;
goto V_197;
}
F_111 ( & V_170 -> V_28 , L_21 ,
V_2 -> V_12 , V_28 -> V_141 ) ;
return 0 ;
V_197:
F_112 ( V_28 ) ;
V_184:
F_113 ( V_98 ) ;
V_183:
F_114 ( V_175 -> V_181 , F_103 ( V_175 ) ) ;
V_180:
F_115 ( V_148 ) ;
exit:
return V_140 ;
}
static int F_116 ( struct V_169 * V_170 )
{
struct V_27 * V_28 = F_117 ( V_170 ) ;
struct V_1 * V_2 = F_31 ( V_28 ) ;
struct V_174 * V_175 ;
F_118 ( V_28 ) ;
F_119 ( V_170 , NULL ) ;
F_113 ( V_2 -> V_12 ) ;
V_175 = F_100 ( V_170 , V_179 , 0 ) ;
F_114 ( V_175 -> V_181 , F_103 ( V_175 ) ) ;
F_115 ( V_2 -> V_148 ) ;
F_112 ( V_28 ) ;
return 0 ;
}
