static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_7 ;
F_2 ( 0 , V_2 -> V_4 + V_8 ) ;
V_2 -> V_9 = F_4 ( V_2 -> V_4 + V_8 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_9 = V_3 ;
F_2 ( V_3 , V_2 -> V_4 + V_8 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_6 = 0 ;
F_5 ( V_2 , V_2 -> V_7 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_10 )
{
V_2 -> V_7 &= ~ ( V_10 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_11 ;
V_11 = F_4 ( V_2 -> V_4 + V_8 ) ;
V_2 -> V_9 = V_11 & ~ V_3 ;
F_2 ( V_2 -> V_9 , V_2 -> V_4 + V_8 ) ;
F_7 ( V_2 , V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_2 V_10 )
{
V_2 -> V_7 |= V_10 ;
if ( ! V_2 -> V_6 )
F_5 ( V_2 , V_2 -> V_7 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_11 ;
V_11 = F_4 ( V_2 -> V_4 + V_8 ) ;
V_2 -> V_9 = V_11 | V_3 ;
F_2 ( V_2 -> V_9 , V_2 -> V_4 + V_8 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 * V_12 )
{
* V_12 = F_4 ( V_2 -> V_4 + V_5 ) ;
* V_12 = * V_12 & V_2 -> V_9 ;
}
static inline void F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 )
F_6 ( V_2 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
if ( ! V_2 -> V_6 ) {
F_3 ( V_2 ) ;
V_3 = V_2 -> V_6 ;
}
return V_3 ;
}
static inline void F_14 ( struct V_13 * V_14 , union V_15 V_12 )
{
V_12 . V_16 . V_17 = 0 ;
V_14 -> V_18 -> V_19 . V_20 = F_15 ( V_12 . V_20 ) ;
}
static inline void F_16 ( struct V_13 * V_14 )
{
V_14 -> V_21 . V_19 . V_22 . V_17 = 1 ;
if ( V_14 -> V_21 . V_23 != V_14 -> V_21 . V_24 . V_20 ) {
V_14 -> V_21 . V_23 = V_14 -> V_21 . V_24 . V_20 ;
V_14 -> V_18 -> V_24 . V_20 = F_15 ( V_14 -> V_21 . V_24 . V_20 ) ;
}
V_14 -> V_18 -> V_19 . V_20 = F_15 ( V_14 -> V_21 . V_19 . V_20 ) ;
}
static void F_17 ( struct V_25 * V_26 , struct V_13 * * V_14 )
{
* V_14 = & V_26 -> V_27 [ V_26 -> V_28 ] ;
V_26 -> V_28 ++ ;
V_26 -> V_28 &= V_26 -> V_29 ;
V_26 -> V_30 -- ;
( * V_14 ) -> V_21 . V_24 . V_20 &= ~ V_31 ;
}
static inline void F_18 ( struct V_13 * V_14 , T_2 V_32 )
{
V_14 -> V_18 -> V_32 = F_15 ( V_32 ) ;
}
static inline void F_19 ( struct V_13 * V_14 , T_2 V_33 )
{
V_14 -> V_21 . V_24 . V_16 . V_23 = V_33 ;
}
static inline void F_20 ( struct V_25 * V_26 ,
struct V_13 * * V_14 )
{
* V_14 = & V_26 -> V_27 [ V_26 -> V_34 ] ;
V_26 -> V_34 ++ ;
V_26 -> V_34 &= V_26 -> V_29 ;
V_26 -> V_30 -- ;
( * V_14 ) -> V_21 . V_24 . V_20 &= ~ V_35 ;
}
static inline void F_21 ( struct V_13 * V_14 , T_2 V_32 )
{
V_14 -> V_18 -> V_32 = F_15 ( V_32 ) ;
}
static inline void F_22 ( struct V_13 * V_14 , T_2 V_33 )
{
V_14 -> V_21 . V_24 . V_22 . V_23 = V_33 ;
}
static void F_23 ( struct V_1 * V_2 , int V_36 , T_3 V_32 , T_2 * V_20 )
{
T_3 V_37 ;
T_1 V_3 ;
V_37 = ( ( ( V_36 << V_38 ) | V_39 ) << 8 ) | V_32 ;
V_3 = F_13 ( V_2 ) ;
F_24 ( V_37 , V_2 -> V_4 + V_40 ) ;
F_25 ( V_2 , V_40 ) ;
* V_20 = F_4 ( V_2 -> V_4 + V_41 ) ;
F_12 ( V_2 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_36 , T_3 V_32 , T_2 V_42 ,
T_2 V_43 )
{
T_3 V_37 ;
T_1 V_3 ;
V_37 = ( ( V_36 << V_38 ) << 8 ) | V_32 ;
V_3 = F_13 ( V_2 ) ;
F_2 ( V_42 , V_2 -> V_4 + V_44 ) ;
F_2 ( V_43 , V_2 -> V_4 + V_41 ) ;
F_24 ( V_37 , V_2 -> V_4 + V_40 ) ;
F_25 ( V_2 , V_40 ) ;
F_12 ( V_2 , V_3 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_3 V_32 , T_4 * V_45 ,
T_4 V_46 , int V_47 , int V_48 , int V_49 , T_4 V_50 )
{
T_2 V_42 ;
T_2 V_43 ;
V_43 = ( ( T_2 ) V_45 [ 2 ] << 24 ) |
( ( T_2 ) V_45 [ 3 ] << 16 ) |
( ( T_2 ) V_45 [ 4 ] << 8 ) | V_45 [ 5 ] ;
V_42 = ( ( T_2 ) V_45 [ 0 ] << 8 ) | V_45 [ 1 ] ;
V_42 |= ( T_2 ) V_46 << V_51 ;
if ( V_47 )
V_42 |= V_52 ;
if ( V_49 ) {
V_42 |= V_53 ;
V_42 |= ( T_2 ) V_50 << V_54 ;
}
if ( V_48 )
V_42 |= V_55 ;
F_26 ( V_2 , V_56 , V_32 , V_42 , V_43 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_3 V_32 , T_3 * V_57 , T_4 * V_50 ,
T_4 * V_58 )
{
T_2 V_20 ;
F_23 ( V_2 , V_59 , V_32 , & V_20 ) ;
if ( V_20 & V_60 ) {
* V_57 = ( T_3 ) ( V_20 & V_61 ) ;
* V_50 = ( T_4 ) ( ( V_20 & V_62 ) >> V_63 ) ;
* V_58 = ( T_4 ) ( ( V_20 & V_64 ) >>
V_65 ) ;
return 0 ;
}
return - 1 ;
}
static void F_29 ( struct V_1 * V_2 , int V_66 , T_3 V_32 , T_5 * V_67 )
{
T_2 V_20 ;
T_3 V_37 ;
T_1 V_3 ;
int V_68 ;
V_37 = V_32 + V_69 * V_66 ;
V_3 = F_13 ( V_2 ) ;
V_37 |= ( ( ( V_70 << V_38 ) | V_39 ) << 8 ) ;
F_24 ( V_37 , V_2 -> V_4 + V_40 ) ;
F_25 ( V_2 , V_40 ) ;
for ( V_68 = 100 ; V_68 > 0 ; V_68 -- ) {
V_20 = F_4 ( V_2 -> V_4 + V_41 ) ;
if ( V_20 & V_71 ) {
if ( V_20 & V_72 )
* V_67 += V_73 + 1 ;
* V_67 += V_20 & V_73 ;
break;
}
}
F_12 ( V_2 , V_3 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_66 , T_2 * V_28 , T_5 * V_67 )
{
T_2 V_74 ;
T_2 V_20 ;
T_3 V_37 ;
T_1 V_3 ;
int V_75 ;
V_75 = V_76 + V_66 ;
do {
V_3 = F_13 ( V_2 ) ;
V_37 = ( T_3 ) V_75 ;
V_37 |= ( ( ( V_70 << V_38 ) | V_39 )
<< 8 ) ;
F_24 ( V_37 , V_2 -> V_4 + V_40 ) ;
F_25 ( V_2 , V_40 ) ;
V_20 = F_4 ( V_2 -> V_4 + V_41 ) ;
F_12 ( V_2 , V_3 ) ;
V_20 &= V_77 ;
V_74 = * V_28 ;
if ( V_20 != V_74 ) {
* V_28 = V_20 ;
if ( V_20 < V_74 )
V_20 += V_77 + 1 ;
V_20 -= V_74 ;
* V_67 += V_20 ;
}
++ V_28 ;
++ V_67 ;
V_75 -= V_78 -
V_79 + 1 ;
} while ( V_75 >= V_79 + V_66 );
}
static int F_31 ( struct V_1 * V_2 , int V_66 )
{
struct V_80 * V_81 = & V_2 -> V_82 [ V_66 ] ;
if ( V_81 -> V_83 < V_69 )
while ( V_81 -> V_84 < V_69 ) {
F_29 ( V_2 , V_66 , V_81 -> V_84 ,
& V_81 -> V_85 [ V_81 -> V_84 ] ) ;
++ V_81 -> V_84 ;
}
if ( V_2 -> V_86 > V_69 )
F_30 ( V_2 , V_66 , V_81 -> V_87 ,
& V_81 -> V_85 [ V_69 ] ) ;
V_81 -> V_84 = 0 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , int V_66 )
{
struct V_80 * V_81 = & V_2 -> V_82 [ V_66 ] ;
V_81 -> V_84 = 0 ;
if ( V_81 -> V_83 < V_69 )
do {
F_29 ( V_2 , V_66 , V_81 -> V_84 ,
& V_81 -> V_85 [ V_81 -> V_84 ] ) ;
++ V_81 -> V_84 ;
} while ( V_81 -> V_84 < V_69 );
if ( V_2 -> V_86 > V_69 )
F_30 ( V_2 , V_66 , V_81 -> V_87 ,
& V_81 -> V_85 [ V_69 ] ) ;
memset ( ( void * ) V_81 -> V_85 , 0 , sizeof( T_5 ) * V_88 ) ;
V_81 -> V_84 = 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_66 , int V_89 , T_3 V_90 )
{
T_2 V_32 ;
T_3 V_20 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_89 ;
V_20 = F_35 ( V_2 -> V_4 + V_32 ) ;
return ( V_20 & V_90 ) == V_90 ;
}
static void F_36 ( struct V_1 * V_2 , int V_66 , int V_89 , T_3 V_90 ,
int V_91 )
{
T_2 V_32 ;
T_3 V_20 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_89 ;
V_20 = F_35 ( V_2 -> V_4 + V_32 ) ;
if ( V_91 )
V_20 |= V_90 ;
else
V_20 &= ~ V_90 ;
F_24 ( V_20 , V_2 -> V_4 + V_32 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_66 , T_2 V_32 , int V_92 )
{
T_3 V_20 ;
T_3 V_10 = 1 << V_66 ;
V_20 = F_35 ( V_2 -> V_4 + V_32 ) ;
V_20 >>= V_92 ;
return ( V_20 & V_10 ) == V_10 ;
}
static void F_38 ( struct V_1 * V_2 , int V_66 , T_2 V_32 , int V_92 ,
int V_91 )
{
T_3 V_20 ;
T_3 V_90 = 1 << V_66 ;
V_20 = F_35 ( V_2 -> V_4 + V_32 ) ;
V_90 <<= V_92 ;
if ( V_91 )
V_20 |= V_90 ;
else
V_20 &= ~ V_90 ;
F_24 ( V_20 , V_2 -> V_4 + V_32 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_66 , int V_89 , T_4 * V_20 )
{
T_2 V_32 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_89 ;
* V_20 = F_40 ( V_2 -> V_4 + V_32 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_66 , int V_89 , T_3 * V_20 )
{
T_2 V_32 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_89 ;
* V_20 = F_35 ( V_2 -> V_4 + V_32 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_66 , int V_89 , T_3 V_20 )
{
T_2 V_32 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_89 ;
F_24 ( V_20 , V_2 -> V_4 + V_32 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_2 V_32 , T_3 V_90 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_32 ) ;
return ( V_20 & V_90 ) == V_90 ;
}
static void F_44 ( struct V_1 * V_2 , T_2 V_32 , T_3 V_90 , int V_91 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_32 ) ;
if ( V_91 )
V_20 |= V_90 ;
else
V_20 &= ~ V_90 ;
F_24 ( V_20 , V_2 -> V_4 + V_32 ) ;
}
static inline void F_45 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_95 , V_91 ) ;
}
static inline int F_46 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_95 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_4 V_96 )
{
T_3 V_20 ;
T_2 V_97 = ( ( T_2 ) V_98 * ( T_2 ) V_96 / 100 ) ;
if ( V_97 > V_99 )
V_97 = V_99 ;
V_20 = F_35 ( V_2 -> V_4 + V_100 ) ;
V_20 &= ~ ( V_101 | V_102 ) ;
V_20 |= ( ( V_97 & 0x00FF ) << 8 ) | ( ( V_97 & 0xFF00 ) >> 8 ) ;
F_24 ( V_20 , V_2 -> V_4 + V_100 ) ;
}
static void F_48 ( struct V_1 * V_2 , T_4 * V_96 )
{
int V_103 ;
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_100 ) ;
V_103 = ( V_20 & V_102 ) ;
V_103 <<= 8 ;
V_103 |= ( V_20 & V_101 ) >> 8 ;
V_103 = ( V_103 * 100 + V_98 / 2 ) / V_98 ;
* V_96 = ( T_4 ) V_103 ;
}
static void F_49 ( struct V_1 * V_2 , int V_66 )
{
F_45 ( V_2 , V_66 , 0 ) ;
}
static void F_50 ( struct V_1 * V_2 , int V_66 )
{
F_47 ( V_2 , V_2 -> V_104 -> V_105 ) ;
F_45 ( V_2 , V_66 , 1 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_66 ;
V_2 -> V_104 -> V_105 = 1 ;
F_47 ( V_2 , V_2 -> V_104 -> V_105 ) ;
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
F_49 ( V_2 , V_66 ) ;
F_44 ( V_2 , V_107 , V_108 , 1 ) ;
}
static void F_52 ( struct V_1 * V_2 , T_4 V_96 )
{
if ( V_96 > 100 )
V_96 = 100 ;
F_47 ( V_2 , V_96 ) ;
F_48 ( V_2 , & V_96 ) ;
V_2 -> V_104 -> V_105 = V_96 ;
}
static void F_53 ( struct V_1 * V_2 , int V_66 )
{
T_2 V_32 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_109 ;
F_2 ( 0 , V_2 -> V_4 + V_32 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_66 ;
int V_110 ;
struct V_104 * V_21 = V_2 -> V_104 ;
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ ) {
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ ) {
V_21 -> F_36 [ V_66 ] . V_112 [ V_110 ] =
V_21 -> F_36 [ V_66 ] . V_113 [ V_110 ] = 0 ;
}
F_53 ( V_2 , V_66 ) ;
}
}
static inline void F_55 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_115 , V_91 ) ;
}
static inline void F_56 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_116 , V_91 ) ;
}
static inline int F_57 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_114 , V_115 ) ;
}
static inline int F_58 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_114 , V_116 ) ;
}
static inline void F_59 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_117 , V_91 ) ;
}
static inline void F_60 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_118 , V_91 ) ;
}
static inline void F_61 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_119 , V_91 ) ;
}
static inline void F_62 ( struct V_1 * V_2 , int V_91 )
{
F_44 ( V_2 , V_120 , V_121 , V_91 ) ;
}
static inline void F_63 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_122 & V_123 ) ) {
F_62 ( V_2 , 1 ) ;
F_64 ( 1 ) ;
F_62 ( V_2 , 0 ) ;
}
}
static inline void F_65 ( struct V_1 * V_2 , int V_93 , int V_124 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_125 , V_124 ) ;
}
static inline void F_66 ( struct V_1 * V_2 , int V_93 , int remove )
{
F_36 ( V_2 , V_93 ,
V_94 , V_126 , remove ) ;
}
static inline int F_67 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_125 ) ;
}
static inline int F_68 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_126 ) ;
}
static inline void F_69 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_127 , V_91 ) ;
}
static inline void F_70 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_128 , V_91 ) ;
}
static inline int F_71 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_114 , V_127 ) ;
}
static inline int F_72 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_114 , V_128 ) ;
}
static inline void F_73 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_129 , V_91 ) ;
}
static inline void F_74 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_130 , V_91 ) ;
}
static inline void F_75 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_131 , V_91 ) ;
}
static inline void F_76 ( struct V_1 * V_2 , int V_91 )
{
F_44 ( V_2 , V_107 , V_132 , V_91 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ ) {
F_73 ( V_2 , V_66 , 0 ) ;
F_74 ( V_2 , V_66 , 0 ) ;
F_75 ( V_2 , V_66 , 0 ) ;
}
F_76 ( V_2 , 0 ) ;
}
static inline void F_78 ( struct V_1 * V_2 , int V_91 )
{
F_44 ( V_2 , V_133 ,
V_134 , V_91 ) ;
}
static inline int F_79 ( struct V_1 * V_2 )
{
return F_43 ( V_2 , V_133 ,
V_134 ) ;
}
static inline void F_80 ( struct V_1 * V_2 , int V_66 , int V_91 )
{
F_38 ( V_2 , V_66 , V_133 , 0 , V_91 ) ;
}
static inline int F_81 ( struct V_1 * V_2 , int V_66 )
{
return F_37 ( V_2 , V_66 , V_133 , 0 ) ;
}
static inline void F_82 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_135 , V_91 ) ;
}
static inline void F_83 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_136 , V_91 ) ;
}
static inline void F_84 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_137 , V_91 ) ;
}
static inline void F_85 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_138 , V_91 ) ;
}
static inline int F_86 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_135 ) ;
}
static inline int F_87 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_136 ) ;
}
static inline int F_88 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_114 , V_137 ) ;
}
static inline int F_89 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_138 ) ;
}
static void F_90 ( struct V_1 * V_2 , int V_66 )
{
F_82 ( V_2 , V_66 , 0 ) ;
}
static void F_91 ( struct V_1 * V_2 , int V_66 )
{
F_83 ( V_2 , V_66 , 0 ) ;
}
static void F_92 ( struct V_1 * V_2 , int V_91 )
{
F_44 ( V_2 , V_100 , V_139 , V_91 ) ;
}
static void F_93 ( struct V_1 * V_2 , int V_66 , int V_91 )
{
F_84 ( V_2 , V_66 , V_91 ) ;
}
static void F_94 ( struct V_1 * V_2 , int V_66 , T_4 V_110 )
{
T_3 V_20 ;
if ( V_110 > V_140 )
V_110 = V_140 ;
V_2 -> V_104 -> F_36 [ V_66 ] . V_141 = V_110 ;
F_41 ( V_2 , V_66 , V_94 , & V_20 ) ;
V_20 &= ~ V_142 ;
V_20 |= V_110 << V_143 ;
F_42 ( V_2 , V_66 , V_94 , V_20 ) ;
}
static void F_95 ( struct V_1 * V_2 , int V_66 )
{
F_85 ( V_2 , V_66 , 0 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
int V_66 ;
int V_144 ;
struct V_104 * V_21 = V_2 -> V_104 ;
V_21 -> V_145 [ 0 ] = 0 ;
V_21 -> V_145 [ 1 ] = 0 ;
V_21 -> V_145 [ 2 ] = 1 ;
V_21 -> V_145 [ 3 ] = 1 ;
V_21 -> V_145 [ 4 ] = 2 ;
V_21 -> V_145 [ 5 ] = 2 ;
V_21 -> V_145 [ 6 ] = 3 ;
V_21 -> V_145 [ 7 ] = 3 ;
for ( V_144 = 0 ; V_144 < V_146 ; V_144 ++ )
V_21 -> V_147 [ V_144 ] = 0 ;
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ ) {
F_95 ( V_2 , V_66 ) ;
F_90 ( V_2 , V_66 ) ;
F_91 ( V_2 , V_66 ) ;
F_93 ( V_2 , V_66 , 0 ) ;
V_21 -> F_36 [ V_66 ] . V_141 = 0 ;
F_94 ( V_2 , V_66 , V_21 -> F_36 [ V_66 ] . V_141 ) ;
}
F_92 ( V_2 , 0 ) ;
}
static void F_97 ( struct V_1 * V_2 , int V_66 , T_3 * V_57 )
{
T_2 V_32 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_148 ;
* V_57 = F_35 ( V_2 -> V_4 + V_32 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
int V_66 ;
int V_149 ;
struct V_104 * V_21 = V_2 -> V_104 ;
for ( V_149 = 0 ; V_149 < V_150 ; V_149 ++ ) {
F_28 ( V_2 , V_149 ,
& V_21 -> V_151 [ V_149 ] . V_57 ,
& V_21 -> V_151 [ V_149 ] . V_50 ,
& V_21 -> V_151 [ V_149 ] . V_58 ) ;
}
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ ) {
F_97 ( V_2 , V_66 , & V_21 -> F_36 [ V_66 ] . V_57 ) ;
V_21 -> F_36 [ V_66 ] . V_58 = V_152 ;
}
}
static void F_99 ( struct V_1 * V_2 , int V_66 , T_4 V_58 )
{
T_2 V_32 ;
T_4 V_20 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_114 ;
V_20 = F_40 ( V_2 -> V_4 + V_32 ) ;
V_20 &= ~ V_153 ;
V_20 |= ( V_58 & V_152 ) ;
F_100 ( V_20 , V_2 -> V_4 + V_32 ) ;
V_2 -> V_104 -> F_36 [ V_66 ] . V_58 = V_58 ;
}
static inline void F_101 ( struct V_1 * V_2 , T_4 * V_45 )
{
int V_154 ;
for ( V_154 = 0 ; V_154 < 6 ; V_154 += 2 ) {
V_45 [ V_154 ] = F_40 ( V_2 -> V_4 + V_155 + V_154 ) ;
V_45 [ 1 + V_154 ] = F_40 ( V_2 -> V_4 + V_156 + V_154 ) ;
}
}
static void F_102 ( struct V_1 * V_2 , T_4 * V_45 )
{
int V_154 ;
for ( V_154 = 0 ; V_154 < 6 ; V_154 += 2 ) {
F_100 ( V_45 [ V_154 ] , V_2 -> V_4 + V_155 + V_154 ) ;
F_100 ( V_45 [ 1 + V_154 ] , V_2 -> V_4 + V_156 + V_154 ) ;
}
}
static void F_103 ( struct V_1 * V_2 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_100 ) ;
V_20 |= V_157 ;
F_24 ( V_20 , V_2 -> V_4 + V_100 ) ;
V_20 = F_35 ( V_2 -> V_4 + V_120 ) ;
V_20 |= V_158 ;
V_20 |= V_159 ;
V_20 |= V_160 ;
if ( V_2 -> V_122 & V_123 )
V_20 |= V_121 ;
else
V_20 &= ~ V_121 ;
F_24 ( V_20 , V_2 -> V_4 + V_120 ) ;
V_20 = F_35 ( V_2 -> V_4 + V_107 ) ;
V_20 |= V_161 ;
F_24 ( V_20 , V_2 -> V_4 + V_107 ) ;
}
static void F_104 ( struct V_1 * V_2 , int V_66 , int V_162 )
{
T_3 V_20 ;
F_41 ( V_2 , V_66 , V_114 , & V_20 ) ;
switch ( V_162 ) {
case V_163 :
V_20 &= ~ ( V_119 | V_118 ) ;
V_20 |= V_117 ;
break;
case V_164 :
V_20 &= ~ V_119 ;
V_20 |= V_118 ;
V_20 |= V_117 ;
break;
case V_165 :
V_20 &= ~ V_119 ;
V_20 |= V_118 ;
V_20 &= ~ V_117 ;
break;
case V_166 :
V_20 |= ( V_119 | V_118 ) ;
V_20 &= ~ V_117 ;
break;
case V_167 :
V_20 &= ~ ( V_119 | V_118 ) ;
V_20 |= V_117 ;
break;
case V_168 :
V_20 |= ( V_119 | V_118 ) ;
V_20 |= V_117 ;
break;
}
F_42 ( V_2 , V_66 , V_114 , V_20 ) ;
V_2 -> V_104 -> F_36 [ V_66 ] . V_169 = V_162 ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_170 * V_149 ;
int V_154 ;
for ( V_154 = 0 ; V_154 < V_171 ; V_154 ++ ) {
V_149 = & V_2 -> V_104 -> V_172 [ V_154 ] ;
F_27 ( V_2 , V_154 ,
V_149 -> V_45 , V_149 -> V_46 ,
V_149 -> V_47 , 0 ,
V_149 -> V_49 , V_149 -> V_50 ) ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_170 * V_149 ;
V_149 = & V_2 -> V_104 -> V_172 [ V_173 ] ;
V_149 -> V_45 [ 0 ] = 0x01 ;
V_149 -> V_45 [ 1 ] = 0x80 ;
V_149 -> V_45 [ 2 ] = 0xC2 ;
V_149 -> V_45 [ 3 ] = 0x00 ;
V_149 -> V_45 [ 4 ] = 0x00 ;
V_149 -> V_45 [ 5 ] = 0x00 ;
V_149 -> V_46 = V_174 ;
V_149 -> V_47 = 1 ;
V_149 -> V_48 = 1 ;
F_27 ( V_2 , V_173 ,
V_149 -> V_45 , V_149 -> V_46 ,
V_149 -> V_47 , V_149 -> V_48 ,
V_149 -> V_49 , V_149 -> V_50 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_170 * V_149 ;
int V_154 ;
for ( V_154 = V_175 ; V_154 <= V_176 ; V_154 ++ ) {
V_149 = & V_2 -> V_104 -> V_172 [ V_154 ] ;
V_149 -> V_48 = 0 ;
F_27 ( V_2 , V_154 ,
V_149 -> V_45 , V_149 -> V_46 ,
V_149 -> V_47 , V_149 -> V_48 ,
V_149 -> V_49 , V_149 -> V_50 ) ;
}
}
static inline void F_108 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_178 ) ;
}
static inline void F_109 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_178 ) ;
}
static inline void F_110 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_179 ) ;
}
static inline void F_111 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_180 ) ;
}
static inline void F_112 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_180 ) ;
}
static inline void F_113 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_181 ) ;
}
static inline void F_114 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_178 ) ;
}
static inline void F_115 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_178 ) ;
}
static inline void F_116 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_182 ) ;
}
static inline void F_117 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_182 ) ;
}
static inline void F_118 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_183 ) ;
}
static inline void F_119 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_183 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_66 , T_3 V_184 , T_3 * V_185 )
{
int V_177 ;
V_177 = V_186 + V_66 * V_187 + V_184 ;
* V_185 = F_35 ( V_2 -> V_4 + V_177 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_66 , T_3 V_184 , T_3 V_185 )
{
int V_177 ;
V_177 = V_186 + V_66 * V_187 + V_184 ;
F_24 ( V_185 , V_2 -> V_4 + V_177 ) ;
}
static inline void F_122 ( struct V_1 * V_2 , T_4 V_188 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_189 ) ;
V_20 &= ~ V_188 ;
F_24 ( V_20 , V_2 -> V_4 + V_189 ) ;
}
static inline void F_123 ( struct V_1 * V_2 , T_4 V_188 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_189 ) ;
V_20 |= V_188 ;
F_24 ( V_20 , V_2 -> V_4 + V_189 ) ;
}
static inline T_4 F_124 ( struct V_1 * V_2 , T_4 V_188 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_189 ) ;
return ( T_4 ) ( V_20 & V_188 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_123 ( V_2 , V_190 ) ;
F_126 ( V_191 ) ;
F_122 ( V_2 , V_190 ) ;
F_126 ( V_191 ) ;
}
static T_3 F_127 ( struct V_1 * V_2 )
{
int V_154 ;
T_3 V_192 = 0 ;
for ( V_154 = 15 ; V_154 >= 0 ; V_154 -- ) {
F_123 ( V_2 , V_190 ) ;
F_126 ( V_191 ) ;
V_192 |= ( F_124 ( V_2 , V_193 ) ) ? 1 << V_154 : 0 ;
F_122 ( V_2 , V_190 ) ;
F_126 ( V_191 ) ;
}
return V_192 ;
}
static void F_128 ( struct V_1 * V_2 , T_3 V_20 )
{
int V_154 ;
for ( V_154 = 15 ; V_154 >= 0 ; V_154 -- ) {
( V_20 & ( 0x01 << V_154 ) ) ? F_123 ( V_2 , V_194 ) :
F_122 ( V_2 , V_194 ) ;
F_125 ( V_2 ) ;
}
}
static void F_129 ( struct V_1 * V_2 , T_4 V_20 , T_4 V_184 )
{
int V_154 ;
F_123 ( V_2 , V_194 ) ;
F_125 ( V_2 ) ;
for ( V_154 = 1 ; V_154 >= 0 ; V_154 -- ) {
( V_20 & ( 0x01 << V_154 ) ) ? F_123 ( V_2 , V_194 ) :
F_122 ( V_2 , V_194 ) ;
F_125 ( V_2 ) ;
}
for ( V_154 = 5 ; V_154 >= 0 ; V_154 -- ) {
( V_184 & ( 0x01 << V_154 ) ) ? F_123 ( V_2 , V_194 ) :
F_122 ( V_2 , V_194 ) ;
F_125 ( V_2 ) ;
}
}
static T_3 F_130 ( struct V_1 * V_2 , T_4 V_184 )
{
T_3 V_20 ;
F_123 ( V_2 , V_195 | V_196 ) ;
F_129 ( V_2 , V_197 , V_184 ) ;
V_20 = F_127 ( V_2 ) ;
F_122 ( V_2 , V_195 | V_196 ) ;
return V_20 ;
}
static void F_131 ( struct V_1 * V_2 , T_4 V_184 , T_3 V_20 )
{
int V_68 ;
F_123 ( V_2 , V_195 | V_196 ) ;
F_129 ( V_2 , V_198 , V_199 ) ;
F_122 ( V_2 , V_196 ) ;
F_126 ( 1 ) ;
F_123 ( V_2 , V_196 ) ;
F_129 ( V_2 , V_200 , V_184 ) ;
F_122 ( V_2 , V_196 ) ;
F_126 ( 1 ) ;
F_123 ( V_2 , V_196 ) ;
V_68 = 8 ;
F_64 ( 2 ) ;
do {
F_64 ( 1 ) ;
} while ( ! F_124 ( V_2 , V_193 ) && -- V_68 );
F_122 ( V_2 , V_196 ) ;
F_126 ( 1 ) ;
F_123 ( V_2 , V_196 ) ;
F_129 ( V_2 , V_201 , V_184 ) ;
F_128 ( V_2 , V_20 ) ;
F_122 ( V_2 , V_196 ) ;
F_126 ( 1 ) ;
F_123 ( V_2 , V_196 ) ;
V_68 = 8 ;
F_64 ( 2 ) ;
do {
F_64 ( 1 ) ;
} while ( ! F_124 ( V_2 , V_193 ) && -- V_68 );
F_122 ( V_2 , V_196 ) ;
F_126 ( 1 ) ;
F_123 ( V_2 , V_196 ) ;
F_129 ( V_2 , V_198 , V_202 ) ;
F_122 ( V_2 , V_195 | V_196 ) ;
}
static T_3 F_132 ( struct V_203 * V_66 , T_3 V_19 )
{
V_19 &= ~ V_204 ;
switch ( V_66 -> V_205 ) {
case V_206 :
V_19 |= V_204 ;
break;
case V_207 :
case V_208 :
default:
break;
}
return V_19 ;
}
static void F_133 ( struct V_1 * V_2 , int V_16 , int V_22 )
{
T_2 V_209 ;
T_2 V_210 ;
V_209 = V_2 -> V_209 ;
V_210 = V_2 -> V_210 ;
if ( V_16 )
V_2 -> V_209 |= V_211 ;
else
V_2 -> V_209 &= ~ V_211 ;
if ( V_22 )
V_2 -> V_210 |= V_212 ;
else
V_2 -> V_210 &= ~ V_212 ;
if ( V_2 -> V_213 ) {
if ( V_209 != V_2 -> V_209 )
F_2 ( V_2 -> V_209 , V_2 -> V_4 + V_214 ) ;
if ( V_210 != V_2 -> V_210 )
F_2 ( V_2 -> V_210 , V_2 -> V_4 + V_215 ) ;
}
}
static void F_134 ( struct V_1 * V_2 , struct V_203 * V_66 ,
T_3 V_216 , T_3 V_217 )
{
int V_16 ;
int V_22 ;
if ( V_2 -> V_122 & V_218 )
return;
V_16 = V_22 = 0 ;
if ( V_66 -> V_219 )
V_16 = V_22 = 1 ;
if ( V_217 & V_220 ) {
if ( V_216 & V_220 ) {
V_16 = V_22 = 1 ;
} else if ( ( V_217 & V_221 ) &&
( V_216 & V_222 ) ==
V_221 ) {
V_22 = 1 ;
}
} else if ( V_217 & V_221 ) {
if ( ( V_216 & V_222 ) == V_222 )
V_16 = 1 ;
}
if ( ! V_2 -> V_104 )
F_133 ( V_2 , V_16 , V_22 ) ;
}
static inline void F_135 ( struct V_1 * V_2 , struct V_203 * V_66 ,
struct V_223 * V_26 , T_3 V_224 )
{
if ( ( V_2 -> V_225 & V_226 ) &&
! ( V_2 -> V_122 & V_218 ) ) {
T_2 V_227 = V_2 -> V_210 ;
if ( 1 == V_26 -> V_228 )
V_2 -> V_210 &= ~ V_212 ;
if ( V_2 -> V_213 && V_227 != V_2 -> V_210 )
F_2 ( V_2 -> V_210 , V_2 -> V_4 + V_215 ) ;
}
}
static void F_136 ( struct V_203 * V_66 )
{
T_1 V_3 ;
struct V_223 * V_26 ;
struct V_223 * V_229 = NULL ;
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_20 ;
T_3 V_12 ;
T_4 V_216 ;
T_4 V_217 ;
int V_154 ;
int V_93 ;
int V_230 = 0 ;
V_3 = F_13 ( V_2 ) ;
for ( V_154 = 0 , V_93 = V_66 -> V_231 ; V_154 < V_66 -> V_232 ; V_154 ++ , V_93 ++ ) {
V_26 = & V_2 -> V_233 [ V_93 ] ;
F_41 ( V_2 , V_93 , V_234 , & V_20 ) ;
F_41 ( V_2 , V_93 , V_235 , & V_12 ) ;
V_217 = V_12 & ( V_236 |
V_237 ) ;
V_216 = ( T_4 ) V_20 ;
if ( V_216 == V_26 -> V_238 && V_217 == V_26 -> V_239 )
continue;
V_26 -> V_238 = V_216 ;
V_26 -> V_239 = V_217 ;
if ( V_12 & V_237 ) {
if ( ! V_229 )
V_229 = V_26 ;
V_26 -> V_113 = 10 * V_240 ;
if ( V_12 & V_241 )
V_26 -> V_113 = 100 * V_240 ;
V_26 -> V_228 = 1 ;
if ( V_12 & V_242 )
V_26 -> V_228 = 2 ;
if ( V_243 != V_26 -> V_162 ) {
F_120 ( V_2 , V_93 , V_180 ,
& V_20 ) ;
F_120 ( V_2 , V_93 , V_181 ,
& V_12 ) ;
F_134 ( V_2 , V_66 , V_20 , V_12 ) ;
if ( V_2 -> V_104 ) {
F_55 ( V_2 , V_93 ,
( 1 == V_26 -> V_228 ) ) ;
}
V_230 |= 1 << V_154 ;
F_135 ( V_2 , V_66 , V_26 , V_12 ) ;
}
V_26 -> V_162 = V_243 ;
} else {
if ( V_244 != V_26 -> V_162 ) {
V_230 |= 1 << V_154 ;
V_2 -> V_82 [ V_93 ] . V_245 = 1 ;
}
V_26 -> V_162 = V_244 ;
}
V_2 -> V_82 [ V_93 ] . V_162 = ( T_4 ) V_26 -> V_162 ;
}
if ( V_229 && V_244 == V_66 -> V_229 -> V_162 )
V_66 -> V_229 = V_229 ;
F_12 ( V_2 , V_3 ) ;
}
static void F_137 ( struct V_203 * V_66 )
{
struct V_223 * V_26 ;
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_20 ;
T_3 V_227 ;
T_4 V_12 ;
int V_154 ;
int V_93 ;
for ( V_154 = 0 , V_93 = V_66 -> V_231 ; V_154 < V_66 -> V_232 ; V_154 ++ , V_93 ++ ) {
V_26 = & V_2 -> V_233 [ V_93 ] ;
F_41 ( V_2 , V_93 , V_234 , & V_20 ) ;
F_39 ( V_2 , V_93 , V_235 , & V_12 ) ;
V_227 = 0 ;
if ( V_12 & V_237 )
V_227 = V_20 ;
V_20 |= V_246 ;
V_20 = F_132 ( V_66 , V_20 ) ;
V_20 |= V_247 | V_248 |
V_249 | V_250 ;
if ( V_66 -> V_251 || V_66 -> V_228 ) {
if ( 10 == V_66 -> V_251 )
V_20 &= ~ ( V_247 |
V_248 ) ;
else if ( 100 == V_66 -> V_251 )
V_20 &= ~ ( V_249 |
V_250 ) ;
if ( 1 == V_66 -> V_228 )
V_20 &= ~ ( V_247 |
V_249 ) ;
else if ( 2 == V_66 -> V_228 )
V_20 &= ~ ( V_248 |
V_250 ) ;
}
if ( V_20 != V_227 ) {
V_20 |= V_252 ;
F_42 ( V_2 , V_93 , V_234 , V_20 ) ;
}
}
}
static void F_138 ( struct V_203 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_20 ;
int V_154 ;
int V_177 ;
int V_93 ;
for ( V_154 = 0 , V_93 = V_66 -> V_231 ; V_154 < V_66 -> V_232 ; V_154 ++ , V_93 ++ ) {
V_177 = V_186 + V_93 * V_187 ;
F_108 ( V_2 , V_177 , & V_20 ) ;
V_20 &= ~ V_253 ;
if ( 10 == V_66 -> V_251 )
V_20 &= ~ V_254 ;
else if ( 100 == V_66 -> V_251 )
V_20 |= V_254 ;
if ( 1 == V_66 -> V_228 )
V_20 &= ~ V_255 ;
else if ( 2 == V_66 -> V_228 )
V_20 |= V_255 ;
F_109 ( V_2 , V_177 , V_20 ) ;
}
}
static void F_139 ( struct V_203 * V_66 , int V_256 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_154 ;
int V_93 ;
for ( V_154 = 0 , V_93 = V_66 -> V_231 ; V_154 < V_66 -> V_232 ; V_154 ++ , V_93 ++ )
F_36 ( V_2 , V_93 ,
V_234 , V_257 , V_256 ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_258 * V_259 = F_141 ( V_2 , struct V_258 , V_2 ) ;
struct V_260 * V_261 = V_259 -> V_261 ;
T_3 V_20 ;
if ( ! V_261 -> V_262 )
return 0 ;
F_142 ( V_261 , V_261 -> V_262 + V_263 , & V_20 ) ;
return ( V_20 & V_264 ) == V_264 ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_258 * V_259 = F_141 ( V_2 , struct V_258 , V_2 ) ;
struct V_260 * V_261 = V_259 -> V_261 ;
T_3 V_20 ;
if ( ! V_261 -> V_262 )
return;
F_142 ( V_261 , V_261 -> V_262 + V_263 , & V_20 ) ;
V_20 |= V_264 ;
F_144 ( V_261 , V_261 -> V_262 + V_263 , V_20 ) ;
}
static void F_145 ( struct V_1 * V_2 , int V_91 )
{
struct V_258 * V_259 = F_141 ( V_2 , struct V_258 , V_2 ) ;
struct V_260 * V_261 = V_259 -> V_261 ;
T_3 V_20 ;
if ( ! V_261 -> V_262 )
return;
F_142 ( V_261 , V_261 -> V_262 + V_263 , & V_20 ) ;
V_20 &= ~ V_265 ;
if ( V_91 )
V_20 |= V_266 | V_267 ;
else
V_20 &= ~ V_266 ;
F_144 ( V_261 , V_261 -> V_262 + V_263 , V_20 ) ;
}
static void F_146 ( struct V_1 * V_2 , T_3 V_268 , int V_91 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_269 ) ;
if ( V_91 )
V_20 |= V_268 ;
else
V_20 &= ~ V_268 ;
F_24 ( V_20 , V_2 -> V_4 + V_269 ) ;
}
static void F_147 ( struct V_1 * V_2 , int V_154 , T_1 V_270 ,
const T_4 * V_29 , T_1 V_271 , const T_4 * V_272 )
{
int V_90 ;
int V_273 ;
int V_33 ;
int V_274 ;
T_2 V_275 ;
T_4 V_20 [ 64 ] ;
T_4 V_185 = 0 ;
if ( V_271 > V_270 * 8 )
V_271 = V_270 * 8 ;
if ( V_271 > 64 )
V_271 = 64 ;
V_154 *= 0x10 ;
F_2 ( 0 , V_2 -> V_4 + V_276 + V_154 ) ;
F_2 ( 0 , V_2 -> V_4 + V_277 + V_154 ) ;
V_90 = V_33 = V_273 = V_274 = 0 ;
do {
if ( V_90 ) {
if ( ( V_185 & 1 ) )
V_20 [ V_274 ++ ] = V_272 [ V_273 ] ;
V_185 >>= 1 ;
++ V_273 ;
-- V_90 ;
} else {
V_185 = V_29 [ V_33 ] ;
F_100 ( V_185 , V_2 -> V_4 + V_276 + V_154
+ V_33 ) ;
++ V_33 ;
if ( V_185 )
V_90 = 8 ;
else
V_273 += 8 ;
}
} while ( V_273 < ( int ) V_271 );
if ( V_185 ) {
V_90 = V_29 [ V_33 - 1 ] ;
V_185 <<= ( V_273 % 8 ) ;
V_90 &= ~ V_185 ;
F_100 ( V_90 , V_2 -> V_4 + V_276 + V_154 + V_33 -
1 ) ;
}
V_275 = F_148 ( V_274 , V_20 ) ;
F_2 ( V_275 , V_2 -> V_4 + V_278 + V_154 ) ;
}
static void F_149 ( struct V_1 * V_2 , const T_4 * V_279 )
{
static const T_4 V_29 [ 6 ] = { 0x3F , 0xF0 , 0x3F , 0x00 , 0xC0 , 0x03 } ;
T_4 V_272 [ 42 ] = {
0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x08 , 0x06 ,
0x00 , 0x01 , 0x08 , 0x00 , 0x06 , 0x04 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
memcpy ( & V_272 [ 38 ] , V_279 , 4 ) ;
F_147 ( V_2 , 3 , 6 , V_29 , 42 , V_272 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
static const T_4 V_29 [] = { 0x3F } ;
static const T_4 V_272 [] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
F_147 ( V_2 , 2 , 1 , V_29 , V_280 , V_272 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
static const T_4 V_29 [] = { 0x3F } ;
T_4 V_272 [] = { 0x33 , 0x33 , 0xFF , 0x00 , 0x00 , 0x00 } ;
memcpy ( & V_272 [ 3 ] , & V_2 -> V_281 [ 3 ] , 3 ) ;
F_147 ( V_2 , 1 , 1 , V_29 , 6 , V_272 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
static const T_4 V_29 [] = { 0x3F } ;
F_147 ( V_2 , 0 , 1 , V_29 , V_280 , V_2 -> V_281 ) ;
}
static void F_153 ( struct V_1 * V_2 , T_2 V_282 , const T_4 * V_283 )
{
F_146 ( V_2 , V_284 , ( V_282 & V_285 ) ) ;
F_146 ( V_2 , V_286 , ( V_282 & V_287 ) ) ;
F_152 ( V_2 ) ;
F_146 ( V_2 , V_288 , ( V_282 & V_289 ) ) ;
F_151 ( V_2 ) ;
F_146 ( V_2 , V_290 , ( V_282 & V_291 ) ) ;
F_146 ( V_2 , V_292 , ( V_282 & V_293 ) ) ;
F_149 ( V_2 , V_283 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
int V_294 = 0 ;
T_3 V_20 ;
T_3 V_295 ;
F_24 ( V_296 , V_2 -> V_4 + V_297 ) ;
V_20 = F_35 ( V_2 -> V_4 + V_298 ) ;
V_295 = ( V_20 & V_299 ) >> V_300 ;
V_20 &= V_301 ;
if ( V_302 == V_20 )
V_294 = 1 ;
else if ( V_303 == V_20 )
V_294 = 2 ;
else
return 0 ;
if ( V_295 <= 1 ) {
V_2 -> V_225 |= V_304 ;
if ( 1 == V_294 )
V_2 -> V_225 |= V_226 ;
}
return V_294 ;
}
static void F_155 ( struct V_1 * V_2 )
{
F_24 ( V_305 , V_2 -> V_4 + V_306 ) ;
F_64 ( 10 ) ;
F_24 ( 0 , V_2 -> V_4 + V_306 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
#if V_307
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_308 ) ;
V_20 &= ~ V_309 ;
V_20 |= V_307 ;
F_24 ( V_20 , V_2 -> V_4 + V_308 ) ;
#endif
V_2 -> V_210 = ( V_310 | V_311 |
( V_312 << V_313 ) | V_314 ) ;
V_2 -> V_209 = ( V_315 | V_316 |
( V_312 << V_313 ) | V_317 ) ;
V_2 -> V_209 |= V_318 ;
V_2 -> V_209 |= ( V_319 | V_320 ) ;
if ( V_2 -> V_321 )
V_2 -> V_209 |= V_322 ;
if ( V_2 -> V_323 )
V_2 -> V_209 |= V_324 ;
}
static void F_157 ( struct V_1 * V_2 )
{
V_2 -> V_7 = V_325 | V_326 ;
}
static void F_158 ( struct V_25 * V_26 )
{
#define F_159 2
int V_327 = V_26 -> V_327 ;
int V_92 ;
V_92 = 0 ;
while ( ! ( V_327 & 1 ) ) {
V_92 ++ ;
V_327 >>= 1 ;
}
if ( V_327 != 1 || V_92 < F_159 ) {
F_160 ( L_1 ) ;
while ( V_327 ) {
V_92 ++ ;
V_327 >>= 1 ;
}
if ( V_92 < F_159 )
V_92 = F_159 ;
V_327 = 1 << V_92 ;
V_26 -> V_327 = V_327 ;
}
V_26 -> V_29 = V_26 -> V_327 - 1 ;
}
static void F_161 ( struct V_25 * V_328 , int V_329 )
{
int V_154 ;
T_2 V_330 = V_328 -> V_331 ;
struct V_332 * V_14 = V_328 -> V_333 ;
struct V_13 * V_74 = V_328 -> V_27 ;
struct V_13 * V_334 = NULL ;
for ( V_154 = 0 ; V_154 < V_328 -> V_327 ; V_154 ++ ) {
V_74 -> V_18 = V_14 ++ ;
V_330 += V_328 -> V_335 ;
V_334 = V_74 ++ ;
V_334 -> V_18 -> V_34 = F_15 ( V_330 ) ;
}
V_334 -> V_18 -> V_34 = F_15 ( V_328 -> V_331 ) ;
V_334 -> V_21 . V_24 . V_16 . V_336 = 1 ;
V_334 -> V_18 -> V_24 . V_20 = F_15 ( V_334 -> V_21 . V_24 . V_20 ) ;
V_328 -> V_30 = V_328 -> V_327 ;
V_328 -> V_28 = V_328 -> V_34 = 0 ;
V_328 -> V_74 = V_328 -> V_27 ;
}
static void F_162 ( struct V_1 * V_2 , T_2 V_337 , T_2 V_338 )
{
F_2 ( V_337 , V_2 -> V_4 + V_339 ) ;
F_2 ( V_338 , V_2 -> V_4 + V_340 ) ;
}
static void F_163 ( struct V_25 * V_26 )
{
V_26 -> V_74 = V_26 -> V_27 ;
V_26 -> V_30 = V_26 -> V_327 ;
V_26 -> V_28 = V_26 -> V_34 = 0 ;
}
static inline void F_164 ( struct V_1 * V_2 )
{
F_2 ( V_341 , V_2 -> V_4 + V_342 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_209 , V_2 -> V_4 + V_214 ) ;
V_2 -> V_7 |= V_343 ;
F_2 ( V_341 , V_2 -> V_4 + V_342 ) ;
F_1 ( V_2 , V_343 ) ;
V_2 -> V_344 ++ ;
if ( 0 == V_2 -> V_344 )
V_2 -> V_344 = 2 ;
}
static void F_166 ( struct V_1 * V_2 )
{
V_2 -> V_344 = 0 ;
F_8 ( V_2 , V_343 ) ;
F_2 ( ( V_2 -> V_209 & ~ V_317 ) , V_2 -> V_4 + V_214 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_210 , V_2 -> V_4 + V_215 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
F_2 ( ( V_2 -> V_210 & ~ V_314 ) , V_2 -> V_4 + V_215 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
F_166 ( V_2 ) ;
F_168 ( V_2 ) ;
V_2 -> V_213 = 0 ;
}
static void F_170 ( struct V_1 * V_2 )
{
F_167 ( V_2 ) ;
F_165 ( V_2 ) ;
V_2 -> V_213 = 1 ;
}
static int F_171 ( struct V_1 * V_2 , int V_345 , int V_346 )
{
if ( V_2 -> V_347 . V_30 <= 1 )
return 0 ;
F_20 ( & V_2 -> V_347 , & V_2 -> V_347 . V_74 ) ;
V_2 -> V_347 . V_74 -> V_21 . V_24 . V_22 . V_348 = 1 ;
++ V_2 -> V_349 ;
V_2 -> V_350 += V_345 ;
if ( V_2 -> V_350 >= V_351 )
V_2 -> V_349 = V_2 -> V_352 + 1 ;
if ( V_346 > V_2 -> V_347 . V_30 )
return 1 ;
return V_2 -> V_347 . V_30 ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_13 * V_74 = V_2 -> V_347 . V_74 ;
V_74 -> V_21 . V_24 . V_22 . V_353 = 1 ;
if ( V_2 -> V_349 > V_2 -> V_352 ) {
V_74 -> V_21 . V_24 . V_22 . V_354 = 1 ;
V_2 -> V_349 = 0 ;
V_2 -> V_350 = 0 ;
}
V_74 -> V_21 . V_24 . V_22 . V_355 = V_2 -> V_356 ;
F_16 ( V_74 ) ;
F_2 ( 0 , V_2 -> V_4 + V_357 ) ;
}
static int F_173 ( T_4 * V_32 )
{
T_2 * V_358 = ( T_2 * ) V_32 ;
T_3 * V_359 = ( T_3 * ) & V_32 [ 4 ] ;
return 0 == * V_358 && 0 == * V_359 ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_154 ;
for ( V_154 = 0 ; V_154 < V_280 ; V_154 ++ )
F_100 ( V_2 -> V_281 [ F_175 ( V_154 ) ] ,
V_2 -> V_4 + V_360 + V_154 ) ;
F_102 ( V_2 , V_2 -> V_281 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
int V_154 ;
for ( V_154 = 0 ; V_154 < V_280 ; V_154 ++ )
V_2 -> V_361 [ F_175 ( V_154 ) ] = F_40 ( V_2 -> V_4 +
V_360 + V_154 ) ;
if ( ! V_2 -> V_362 ) {
memcpy ( V_2 -> V_281 , V_2 -> V_361 , V_280 ) ;
if ( F_173 ( V_2 -> V_281 ) ) {
memcpy ( V_2 -> V_361 , V_363 ,
V_280 ) ;
memcpy ( V_2 -> V_281 , V_363 ,
V_280 ) ;
V_2 -> V_281 [ 5 ] += V_2 -> V_364 ;
F_174 ( V_2 ) ;
}
}
}
static void F_177 ( struct V_1 * V_2 , int V_75 , T_4 * V_45 )
{
int V_154 ;
T_2 V_365 ;
T_2 V_366 ;
V_366 = 0 ;
for ( V_154 = 0 ; V_154 < 2 ; V_154 ++ ) {
V_366 <<= 8 ;
V_366 |= V_45 [ V_154 ] ;
}
V_366 |= V_367 ;
V_365 = 0 ;
for ( V_154 = 2 ; V_154 < 6 ; V_154 ++ ) {
V_365 <<= 8 ;
V_365 |= V_45 [ V_154 ] ;
}
V_75 *= V_368 ;
F_2 ( V_365 , V_2 -> V_4 + V_75 + V_369 ) ;
F_2 ( V_366 , V_2 -> V_4 + V_75 + V_370 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
int V_154 ;
for ( V_154 = 0 ; V_154 < V_371 ; V_154 ++ ) {
if ( F_173 ( V_2 -> V_372 [ V_154 ] ) )
F_2 ( 0 , V_2 -> V_4 + V_368 * V_154 +
V_370 ) ;
else
F_177 ( V_2 , V_154 , V_2 -> V_372 [ V_154 ] ) ;
}
}
static int F_179 ( struct V_1 * V_2 , T_4 * V_45 )
{
int V_154 ;
int V_373 = V_371 ;
if ( ! memcmp ( V_2 -> V_281 , V_45 , V_280 ) )
return 0 ;
for ( V_154 = 0 ; V_154 < V_2 -> V_374 ; V_154 ++ ) {
if ( ! memcmp ( V_2 -> V_372 [ V_154 ] , V_45 , V_280 ) )
return 0 ;
if ( V_371 == V_373 && F_173 ( V_2 -> V_372 [ V_154 ] ) )
V_373 = V_154 ;
}
if ( V_373 < V_371 ) {
memcpy ( V_2 -> V_372 [ V_373 ] , V_45 , V_280 ) ;
F_177 ( V_2 , V_373 , V_2 -> V_372 [ V_373 ] ) ;
return 0 ;
}
return - 1 ;
}
static int F_180 ( struct V_1 * V_2 , T_4 * V_45 )
{
int V_154 ;
for ( V_154 = 0 ; V_154 < V_2 -> V_374 ; V_154 ++ ) {
if ( ! memcmp ( V_2 -> V_372 [ V_154 ] , V_45 , V_280 ) ) {
memset ( V_2 -> V_372 [ V_154 ] , 0 , V_280 ) ;
F_2 ( 0 , V_2 -> V_4 + V_368 * V_154 +
V_370 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_181 ( struct V_1 * V_2 )
{
int V_154 ;
for ( V_154 = 0 ; V_154 < V_375 ; V_154 ++ ) {
V_2 -> V_376 [ V_154 ] = 0 ;
F_100 ( 0 , V_2 -> V_4 + V_377 + V_154 ) ;
}
}
static void F_182 ( struct V_1 * V_2 )
{
int V_154 ;
int V_75 ;
int V_378 ;
int V_97 ;
memset ( V_2 -> V_376 , 0 , sizeof( T_4 ) * V_375 ) ;
for ( V_154 = 0 ; V_154 < V_2 -> V_379 ; V_154 ++ ) {
V_378 = ( F_148 ( 6 , V_2 -> V_380 [ V_154 ] ) >> 26 ) & 0x3f ;
V_75 = V_378 >> 3 ;
V_97 = 1 << ( V_378 & 7 ) ;
V_2 -> V_376 [ V_75 ] |= ( T_4 ) V_97 ;
}
for ( V_154 = 0 ; V_154 < V_375 ; V_154 ++ )
F_100 ( V_2 -> V_376 [ V_154 ] , V_2 -> V_4 + V_377 +
V_154 ) ;
}
static void F_183 ( struct V_1 * V_2 , T_4 V_381 )
{
F_166 ( V_2 ) ;
if ( V_381 )
V_2 -> V_209 |= V_322 ;
else
V_2 -> V_209 &= ~ V_322 ;
if ( V_2 -> V_213 )
F_165 ( V_2 ) ;
}
static void F_184 ( struct V_1 * V_2 , T_4 V_382 )
{
F_166 ( V_2 ) ;
if ( V_382 )
V_2 -> V_209 |= V_324 ;
else
V_2 -> V_209 &= ~ V_324 ;
if ( V_2 -> V_213 )
F_165 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 , int V_256 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_383 ; V_66 ++ ) {
if ( V_2 -> V_384 > 1 ) {
F_99 ( V_2 , V_66 ,
V_174 | ( 1 << V_66 ) ) ;
F_104 ( V_2 , V_66 , V_163 ) ;
} else {
F_99 ( V_2 , V_66 , V_152 ) ;
F_104 ( V_2 , V_66 , V_166 ) ;
}
}
if ( V_2 -> V_384 > 1 )
F_104 ( V_2 , V_383 , V_168 ) ;
else
F_104 ( V_2 , V_383 , V_166 ) ;
if ( V_256 )
V_256 = V_385 ;
F_24 ( V_256 , V_2 -> V_4 + V_298 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
int V_66 ;
F_103 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 , V_386 ) ;
for ( V_66 = 0 ; V_66 < V_383 ; V_66 ++ )
F_50 ( V_2 , V_66 ) ;
F_96 ( V_2 ) ;
F_77 ( V_2 ) ;
F_54 ( V_2 ) ;
F_98 ( V_2 ) ;
if ( V_2 -> V_225 & V_387 )
F_106 ( V_2 ) ;
if ( ! F_43 ( V_2 , V_120 ,
V_388 | V_389 ) )
V_2 -> V_122 |= V_218 ;
F_185 ( V_2 , 1 ) ;
}
static void F_187 ( struct V_390 * V_26 , int time )
{
V_26 -> V_67 = 0 ;
V_26 -> V_391 . V_392 = V_393 + time ;
F_188 ( & V_26 -> V_391 ) ;
V_26 -> V_394 = - 1 ;
}
static void F_189 ( struct V_390 * V_26 )
{
if ( V_26 -> V_394 ) {
V_26 -> V_394 = 0 ;
F_190 ( & V_26 -> V_391 ) ;
}
}
static void F_191 ( struct V_390 * V_26 , int V_395 ,
void (* F_192)( unsigned long ) , void * V_20 )
{
V_26 -> V_394 = 0 ;
V_26 -> V_395 = V_395 ;
F_193 ( & V_26 -> V_391 ) ;
V_26 -> V_391 . F_192 = F_192 ;
V_26 -> V_391 . V_20 = ( unsigned long ) V_20 ;
}
static void F_194 ( struct V_390 * V_26 )
{
++ V_26 -> V_67 ;
if ( V_26 -> V_394 > 0 ) {
if ( V_26 -> V_67 < V_26 -> V_394 ) {
V_26 -> V_391 . V_392 = V_393 + V_26 -> V_395 ;
F_188 ( & V_26 -> V_391 ) ;
} else
V_26 -> V_394 = 0 ;
} else if ( V_26 -> V_394 < 0 ) {
V_26 -> V_391 . V_392 = V_393 + V_26 -> V_395 ;
F_188 ( & V_26 -> V_391 ) ;
}
}
static int F_195 ( struct V_25 * V_328 , int V_329 )
{
V_328 -> V_27 = F_196 ( sizeof( struct V_13 ) * V_328 -> V_327 ,
V_396 ) ;
if ( ! V_328 -> V_27 )
return 1 ;
memset ( ( void * ) V_328 -> V_27 , 0 ,
sizeof( struct V_13 ) * V_328 -> V_327 ) ;
F_161 ( V_328 , V_329 ) ;
return 0 ;
}
static int F_197 ( struct V_258 * V_397 )
{
struct V_1 * V_2 = & V_397 -> V_2 ;
int V_89 ;
V_397 -> V_398 . V_399 =
V_2 -> V_400 . V_335 * V_2 -> V_400 . V_327 +
V_2 -> V_347 . V_335 * V_2 -> V_347 . V_327 +
V_401 ;
V_397 -> V_398 . V_402 =
F_198 (
V_397 -> V_261 , V_397 -> V_398 . V_399 ,
& V_397 -> V_398 . V_403 ) ;
if ( V_397 -> V_398 . V_402 == NULL ) {
V_397 -> V_398 . V_399 = 0 ;
return 1 ;
}
memset ( V_397 -> V_398 . V_402 , 0 , V_397 -> V_398 . V_399 ) ;
V_89 = ( ( ( V_404 ) V_397 -> V_398 . V_402 % V_401 ) ?
( V_401 -
( ( V_404 ) V_397 -> V_398 . V_402 % V_401 ) ) : 0 ) ;
V_397 -> V_398 . V_405 = V_397 -> V_398 . V_402 + V_89 ;
V_397 -> V_398 . V_330 = V_397 -> V_398 . V_403 + V_89 ;
V_2 -> V_400 . V_333 = (struct V_332 * )
V_397 -> V_398 . V_405 ;
V_2 -> V_400 . V_331 = V_397 -> V_398 . V_330 ;
V_89 = V_2 -> V_400 . V_327 * V_2 -> V_400 . V_335 ;
V_2 -> V_347 . V_333 = (struct V_332 * )
( V_397 -> V_398 . V_405 + V_89 ) ;
V_2 -> V_347 . V_331 = V_397 -> V_398 . V_330 + V_89 ;
if ( F_195 ( & V_2 -> V_400 , 0 ) )
return 1 ;
if ( F_195 ( & V_2 -> V_347 , 1 ) )
return 1 ;
return 0 ;
}
static void F_199 ( struct V_258 * V_397 , struct V_406 * V_407 ,
int V_408 )
{
F_200 ( V_397 -> V_261 , V_407 -> V_409 , V_407 -> V_33 , V_408 ) ;
F_201 ( V_407 -> V_410 ) ;
V_407 -> V_410 = NULL ;
V_407 -> V_409 = 0 ;
}
static void F_202 ( struct V_258 * V_397 )
{
int V_154 ;
struct V_13 * V_14 ;
struct V_406 * V_407 ;
struct V_1 * V_2 = & V_397 -> V_2 ;
struct V_25 * V_26 = & V_2 -> V_400 ;
for ( V_154 = 0 ; V_154 < V_2 -> V_400 . V_327 ; V_154 ++ ) {
F_17 ( V_26 , & V_14 ) ;
V_407 = F_203 ( V_14 ) ;
if ( V_407 -> V_410 && V_407 -> V_33 != V_397 -> V_411 )
F_199 ( V_397 , V_407 , V_412 ) ;
V_407 -> V_33 = V_397 -> V_411 ;
if ( ! V_407 -> V_410 )
V_407 -> V_410 = F_204 ( V_407 -> V_33 , V_413 ) ;
if ( V_407 -> V_410 && ! V_407 -> V_409 ) {
V_407 -> V_410 -> V_414 = V_397 -> V_414 ;
V_407 -> V_409 = F_205 (
V_397 -> V_261 ,
F_206 ( V_407 -> V_410 ) ,
V_407 -> V_33 ,
V_412 ) ;
}
F_18 ( V_14 , V_407 -> V_409 ) ;
F_19 ( V_14 , V_407 -> V_33 ) ;
F_16 ( V_14 ) ;
}
}
static int F_207 ( struct V_258 * V_397 )
{
struct V_1 * V_2 = & V_397 -> V_2 ;
V_2 -> V_400 . V_327 = V_415 ;
V_2 -> V_347 . V_327 = V_416 ;
V_2 -> V_349 = 0 ;
V_2 -> V_352 = V_416 / 4 ;
if ( V_2 -> V_352 > 8 )
V_2 -> V_352 = 8 ;
while ( V_2 -> V_352 ) {
V_2 -> V_349 ++ ;
V_2 -> V_352 >>= 1 ;
}
if ( V_2 -> V_349 ) {
V_2 -> V_352 = ( 1 << ( V_2 -> V_349 - 1 ) ) - 1 ;
V_2 -> V_349 = 0 ;
}
V_2 -> V_400 . V_335 =
( ( ( sizeof( struct V_332 ) + V_401 - 1 ) /
V_401 ) * V_401 ) ;
V_2 -> V_347 . V_335 =
( ( ( sizeof( struct V_332 ) + V_401 - 1 ) /
V_401 ) * V_401 ) ;
if ( V_2 -> V_400 . V_335 != sizeof( struct V_332 ) )
F_160 ( L_2 ) ;
F_158 ( & V_2 -> V_400 ) ;
F_158 ( & V_2 -> V_347 ) ;
if ( F_197 ( V_397 ) )
return 1 ;
return 0 ;
}
static void F_208 ( struct V_258 * V_397 )
{
struct V_1 * V_2 = & V_397 -> V_2 ;
V_2 -> V_400 . V_333 = NULL ;
V_2 -> V_347 . V_333 = NULL ;
V_2 -> V_400 . V_331 = 0 ;
V_2 -> V_347 . V_331 = 0 ;
if ( V_397 -> V_398 . V_402 )
F_209 (
V_397 -> V_261 ,
V_397 -> V_398 . V_399 ,
V_397 -> V_398 . V_402 ,
V_397 -> V_398 . V_403 ) ;
V_397 -> V_398 . V_399 = 0 ;
V_397 -> V_398 . V_402 = NULL ;
F_210 ( V_2 -> V_400 . V_27 ) ;
V_2 -> V_400 . V_27 = NULL ;
F_210 ( V_2 -> V_347 . V_27 ) ;
V_2 -> V_347 . V_27 = NULL ;
}
static void F_211 ( struct V_258 * V_397 ,
struct V_25 * V_328 , int V_408 )
{
int V_154 ;
struct V_406 * V_407 ;
struct V_13 * V_14 = V_328 -> V_27 ;
for ( V_154 = 0 ; V_154 < V_328 -> V_327 ; V_154 ++ ) {
V_407 = F_203 ( V_14 ) ;
if ( V_407 -> V_410 )
F_199 ( V_397 , V_407 , V_408 ) ;
V_14 ++ ;
}
}
static void F_212 ( struct V_258 * V_397 )
{
F_211 ( V_397 , & V_397 -> V_2 . V_347 ,
V_417 ) ;
F_211 ( V_397 , & V_397 -> V_2 . V_400 ,
V_412 ) ;
F_208 ( V_397 ) ;
}
static void F_213 ( struct V_1 * V_2 , int V_418 , int V_67 ,
T_5 * V_85 )
{
int V_154 ;
int V_81 ;
int V_66 ;
struct V_80 * V_82 ;
memset ( V_85 , 0 , sizeof( T_5 ) * V_88 ) ;
for ( V_154 = 0 , V_66 = V_418 ; V_154 < V_67 ; V_154 ++ , V_66 ++ ) {
V_82 = & V_2 -> V_82 [ V_66 ] ;
for ( V_81 = V_82 -> V_83 ; V_81 < V_2 -> V_86 ; V_81 ++ )
V_85 [ V_81 ] += V_82 -> V_85 [ V_81 ] ;
}
}
static void F_214 ( struct V_419 * V_410 , struct V_420 * V_414 )
{
struct V_13 * V_14 ;
struct V_13 * V_418 ;
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_25 * V_26 = & V_2 -> V_347 ;
struct V_406 * V_407 ;
int V_33 ;
int V_423 = F_216 ( V_410 ) -> V_424 ;
if ( V_2 -> V_384 > 1 )
V_2 -> V_356 = 1 << V_422 -> V_66 . V_231 ;
V_33 = V_410 -> V_33 ;
V_418 = V_26 -> V_74 ;
V_14 = V_418 ;
V_407 = F_203 ( V_14 ) ;
if ( V_423 ) {
int V_425 ;
T_6 * V_426 ;
V_407 -> V_33 = F_217 ( V_410 ) ;
V_407 -> V_409 = F_205 (
V_259 -> V_261 , V_410 -> V_20 , V_407 -> V_33 ,
V_417 ) ;
F_21 ( V_14 , V_407 -> V_409 ) ;
F_22 ( V_14 , V_407 -> V_33 ) ;
V_425 = 0 ;
do {
V_426 = & F_216 ( V_410 ) -> V_427 [ V_425 ] ;
F_20 ( V_26 , & V_14 ) ;
++ V_2 -> V_349 ;
V_407 = F_203 ( V_14 ) ;
V_407 -> V_33 = V_426 -> V_335 ;
V_407 -> V_409 = F_205 (
V_259 -> V_261 ,
F_218 ( V_426 -> V_428 ) +
V_426 -> V_429 ,
V_407 -> V_33 ,
V_417 ) ;
F_21 ( V_14 , V_407 -> V_409 ) ;
F_22 ( V_14 , V_407 -> V_33 ) ;
V_425 ++ ;
if ( V_425 == V_423 )
break;
F_16 ( V_14 ) ;
} while ( 1 );
V_26 -> V_74 = V_14 ;
F_16 ( V_418 ) ;
} else {
V_407 -> V_33 = V_33 ;
V_407 -> V_409 = F_205 (
V_259 -> V_261 , V_410 -> V_20 , V_407 -> V_33 ,
V_417 ) ;
F_21 ( V_14 , V_407 -> V_409 ) ;
F_22 ( V_14 , V_407 -> V_33 ) ;
}
if ( V_410 -> V_430 == V_431 ) {
( V_14 ) -> V_21 . V_24 . V_22 . V_432 = 1 ;
( V_14 ) -> V_21 . V_24 . V_22 . V_433 = 1 ;
}
V_407 -> V_410 = V_410 ;
F_172 ( V_2 ) ;
V_414 -> V_434 . V_435 ++ ;
V_414 -> V_434 . V_436 += V_33 ;
}
static void F_219 ( struct V_258 * V_259 , int V_437 )
{
int V_28 ;
union V_15 V_12 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_25 * V_26 = & V_2 -> V_347 ;
struct V_13 * V_14 ;
struct V_406 * V_407 ;
struct V_420 * V_414 = NULL ;
F_220 ( & V_259 -> V_438 ) ;
V_28 = V_26 -> V_28 ;
while ( V_26 -> V_30 < V_26 -> V_327 ) {
V_14 = & V_26 -> V_27 [ V_28 ] ;
V_12 . V_20 = F_221 ( V_14 -> V_18 -> V_19 . V_20 ) ;
if ( V_12 . V_22 . V_17 ) {
if ( V_437 )
break;
else
F_14 ( V_14 , V_12 ) ;
}
V_407 = F_203 ( V_14 ) ;
F_200 (
V_259 -> V_261 , V_407 -> V_409 , V_407 -> V_33 ,
V_417 ) ;
if ( V_407 -> V_410 ) {
V_414 = V_407 -> V_410 -> V_414 ;
F_222 ( V_407 -> V_410 ) ;
V_407 -> V_410 = NULL ;
}
V_28 ++ ;
V_28 &= V_26 -> V_29 ;
V_26 -> V_30 ++ ;
}
V_26 -> V_28 = V_28 ;
F_223 ( & V_259 -> V_438 ) ;
if ( V_414 )
V_414 -> V_439 = V_393 ;
}
static void F_224 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_66 ;
F_219 ( V_259 , 1 ) ;
for ( V_66 = 0 ; V_66 < V_2 -> V_384 ; V_66 ++ ) {
struct V_420 * V_414 = V_2 -> V_233 [ V_66 ] . V_261 ;
if ( F_225 ( V_414 ) && F_226 ( V_414 ) )
F_227 ( V_414 ) ;
}
}
static inline void F_228 ( struct V_419 * V_440 , struct V_419 * V_410 )
{
V_410 -> V_414 = V_440 -> V_414 ;
V_410 -> V_441 = V_440 -> V_441 ;
V_410 -> V_430 = V_440 -> V_430 ;
V_410 -> V_442 = V_440 -> V_442 ;
F_229 ( V_410 , V_443 ) ;
F_201 ( V_440 ) ;
}
static T_7 F_230 ( struct V_419 * V_410 , struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_444 ;
int V_103 = 1 ;
int V_294 = 0 ;
if ( V_2 -> V_225 & V_304 ) {
struct V_419 * V_445 = V_410 ;
if ( V_410 -> V_33 <= 48 ) {
if ( F_231 ( V_410 ) - V_410 -> V_20 >= 50 ) {
memset ( & V_410 -> V_20 [ V_410 -> V_33 ] , 0 , 50 - V_410 -> V_33 ) ;
V_410 -> V_33 = 50 ;
} else {
V_410 = F_232 ( 50 ) ;
if ( ! V_410 )
return V_446 ;
memcpy ( V_410 -> V_20 , V_445 -> V_20 , V_445 -> V_33 ) ;
memset ( & V_410 -> V_20 [ V_445 -> V_33 ] , 0 ,
50 - V_445 -> V_33 ) ;
V_410 -> V_33 = 50 ;
F_228 ( V_445 , V_410 ) ;
}
}
}
F_233 ( & V_259 -> V_438 ) ;
V_103 = F_216 ( V_410 ) -> V_424 + 1 ;
V_444 = F_171 ( V_2 , V_410 -> V_33 , V_103 ) ;
if ( V_444 ) {
if ( V_444 < V_103 ||
( ( V_431 == V_410 -> V_430 ) &&
( V_447 == F_234 ( V_410 -> V_441 ) ) ) ) {
struct V_419 * V_445 = V_410 ;
V_410 = F_232 ( V_445 -> V_33 ) ;
if ( ! V_410 ) {
V_294 = V_446 ;
goto V_448;
}
F_235 ( V_445 , V_410 -> V_20 ) ;
V_445 -> V_430 = V_449 ;
V_410 -> V_33 = V_445 -> V_33 ;
F_228 ( V_445 , V_410 ) ;
}
F_214 ( V_410 , V_414 ) ;
if ( V_444 <= V_103 )
F_236 ( V_414 ) ;
} else {
F_236 ( V_414 ) ;
V_294 = V_446 ;
}
V_448:
F_237 ( & V_259 -> V_438 ) ;
return V_294 ;
}
static void F_238 ( struct V_420 * V_414 )
{
static unsigned long V_450 ;
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_66 ;
if ( V_2 -> V_384 > 1 ) {
if ( V_393 - V_450 <= V_414 -> V_451 )
V_259 = NULL ;
}
V_450 = V_393 ;
if ( V_259 ) {
F_3 ( V_2 ) ;
F_169 ( V_2 ) ;
F_219 ( V_259 , 0 ) ;
F_163 ( & V_2 -> V_400 ) ;
F_163 ( & V_2 -> V_347 ) ;
F_202 ( V_259 ) ;
F_155 ( V_2 ) ;
F_162 ( V_2 ,
V_2 -> V_347 . V_331 ,
V_2 -> V_400 . V_331 ) ;
F_174 ( V_2 ) ;
if ( V_2 -> V_321 )
F_183 ( V_2 , V_2 -> V_321 ) ;
else if ( V_2 -> V_379 )
F_182 ( V_2 ) ;
if ( V_2 -> V_384 > 1 ) {
F_178 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_383 ; V_66 ++ ) {
struct V_420 * V_452 ;
F_104 ( V_2 , V_66 ,
V_163 ) ;
V_452 = V_2 -> V_233 [ V_66 ] . V_261 ;
if ( F_225 ( V_452 ) )
F_104 ( V_2 , V_66 ,
V_168 ) ;
}
}
F_170 ( V_2 ) ;
F_6 ( V_2 ) ;
}
V_414 -> V_439 = V_393 ;
F_227 ( V_414 ) ;
}
static inline void F_239 ( struct V_419 * V_410 )
{
unsigned short V_441 ;
struct V_453 * V_454 ;
V_441 = V_410 -> V_441 ;
F_240 ( V_410 ) ;
V_454 = (struct V_453 * ) F_241 ( V_410 ) ;
if ( V_441 == F_234 ( V_455 ) ) {
V_441 = V_454 -> V_456 ;
F_229 ( V_410 , V_457 ) ;
V_454 = (struct V_453 * ) F_241 ( V_410 ) ;
}
if ( V_441 == F_234 ( V_458 ) ) {
if ( V_454 -> V_441 == V_459 )
V_410 -> V_430 = V_460 ;
}
}
static inline int F_242 ( struct V_420 * V_414 , struct V_1 * V_2 ,
struct V_13 * V_14 , union V_15 V_12 )
{
int V_461 ;
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_406 * V_407 ;
struct V_419 * V_410 ;
int V_462 ;
V_461 = V_12 . V_16 . V_463 - 4 ;
V_407 = F_203 ( V_14 ) ;
F_243 (
V_259 -> V_261 , V_407 -> V_409 , V_461 + 4 ,
V_412 ) ;
do {
V_410 = F_232 ( V_461 + 2 ) ;
if ( ! V_410 ) {
V_414 -> V_434 . V_464 ++ ;
return - V_465 ;
}
F_244 ( V_410 , 2 ) ;
memcpy ( F_245 ( V_410 , V_461 ) ,
V_407 -> V_410 -> V_20 , V_461 ) ;
} while ( 0 );
V_410 -> V_441 = F_246 ( V_410 , V_414 ) ;
if ( V_2 -> V_209 & ( V_466 | V_319 ) )
F_239 ( V_410 ) ;
V_414 -> V_434 . V_467 ++ ;
V_414 -> V_434 . V_468 += V_461 ;
V_462 = F_247 ( V_410 ) ;
return 0 ;
}
static int F_248 ( struct V_258 * V_259 )
{
int V_34 ;
union V_15 V_12 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_420 * V_414 = V_2 -> V_233 [ 0 ] . V_261 ;
struct V_25 * V_26 = & V_2 -> V_400 ;
int V_444 = V_26 -> V_327 ;
struct V_13 * V_14 ;
int V_469 = 0 ;
V_34 = V_26 -> V_34 ;
while ( V_444 -- ) {
V_14 = & V_26 -> V_27 [ V_34 ] ;
V_12 . V_20 = F_221 ( V_14 -> V_18 -> V_19 . V_20 ) ;
if ( V_12 . V_16 . V_17 )
break;
if ( V_12 . V_16 . V_470 && V_12 . V_16 . V_471 ) {
if ( F_242 ( V_414 , V_2 , V_14 , V_12 ) )
goto V_472;
V_469 ++ ;
}
V_472:
F_16 ( V_14 ) ;
V_34 ++ ;
V_34 &= V_26 -> V_29 ;
}
V_26 -> V_34 = V_34 ;
return V_469 ;
}
static int F_249 ( struct V_258 * V_259 )
{
int V_34 ;
union V_15 V_12 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_420 * V_414 = V_2 -> V_233 [ 0 ] . V_261 ;
struct V_25 * V_26 = & V_2 -> V_400 ;
int V_444 = V_26 -> V_327 ;
struct V_13 * V_14 ;
int V_469 = 0 ;
V_34 = V_26 -> V_34 ;
while ( V_444 -- ) {
V_14 = & V_26 -> V_27 [ V_34 ] ;
V_12 . V_20 = F_221 ( V_14 -> V_18 -> V_19 . V_20 ) ;
if ( V_12 . V_16 . V_17 )
break;
if ( V_2 -> V_384 > 1 ) {
int V_93 = F_250 ( V_12 . V_16 . V_473 ) ;
V_414 = V_2 -> V_233 [ V_93 ] . V_261 ;
if ( ! F_225 ( V_414 ) )
goto V_472;
}
if ( V_12 . V_16 . V_470 && V_12 . V_16 . V_471 ) {
if ( F_242 ( V_414 , V_2 , V_14 , V_12 ) )
goto V_472;
V_469 ++ ;
}
V_472:
F_16 ( V_14 ) ;
V_34 ++ ;
V_34 &= V_26 -> V_29 ;
}
V_26 -> V_34 = V_34 ;
return V_469 ;
}
static int F_251 ( struct V_258 * V_259 )
{
int V_34 ;
union V_15 V_12 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_420 * V_414 = V_2 -> V_233 [ 0 ] . V_261 ;
struct V_25 * V_26 = & V_2 -> V_400 ;
int V_444 = V_26 -> V_327 ;
struct V_13 * V_14 ;
int V_469 = 0 ;
V_34 = V_26 -> V_34 ;
while ( V_444 -- ) {
V_14 = & V_26 -> V_27 [ V_34 ] ;
V_12 . V_20 = F_221 ( V_14 -> V_18 -> V_19 . V_20 ) ;
if ( V_12 . V_16 . V_17 )
break;
if ( V_2 -> V_384 > 1 ) {
int V_93 = F_250 ( V_12 . V_16 . V_473 ) ;
V_414 = V_2 -> V_233 [ V_93 ] . V_261 ;
if ( ! F_225 ( V_414 ) )
goto V_472;
}
if ( V_12 . V_16 . V_470 && V_12 . V_16 . V_471 ) {
if ( ! V_12 . V_16 . error || ( V_12 . V_20 &
V_474 ) ==
V_475 ) {
if ( F_242 ( V_414 , V_2 , V_14 , V_12 ) )
goto V_472;
V_469 ++ ;
} else {
struct V_421 * V_422 = F_215 ( V_414 ) ;
V_422 -> V_66 . V_85 [ V_476 ] ++ ;
}
}
V_472:
F_16 ( V_14 ) ;
V_34 ++ ;
V_34 &= V_26 -> V_29 ;
}
V_26 -> V_34 = V_34 ;
return V_469 ;
}
static void F_252 ( unsigned long V_20 )
{
struct V_258 * V_259 = (struct V_258 * ) V_20 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
if ( ! V_2 -> V_213 )
return;
if ( F_253 ( ! V_259 -> V_477 ( V_259 ) ) ) {
F_164 ( V_2 ) ;
F_233 ( & V_259 -> V_438 ) ;
F_9 ( V_2 , V_478 ) ;
F_237 ( & V_259 -> V_438 ) ;
} else {
F_1 ( V_2 , V_479 ) ;
F_254 ( & V_259 -> V_480 ) ;
}
}
static void F_255 ( unsigned long V_20 )
{
struct V_258 * V_259 = (struct V_258 * ) V_20 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
F_1 ( V_2 , V_481 ) ;
F_224 ( V_259 ) ;
F_233 ( & V_259 -> V_438 ) ;
F_9 ( V_2 , V_482 ) ;
F_237 ( & V_259 -> V_438 ) ;
}
static inline void F_256 ( struct V_1 * V_2 )
{
if ( 0 == V_2 -> V_344 )
V_2 -> V_7 &= ~ V_343 ;
else if ( V_2 -> V_344 > 1 ) {
if ( V_2 -> V_213 && ( V_2 -> V_209 & V_317 ) ) {
F_165 ( V_2 ) ;
} else {
V_2 -> V_7 &= ~ V_343 ;
V_2 -> V_344 = 0 ;
}
} else
V_2 -> V_344 ++ ;
}
static T_8 F_257 ( int V_483 , void * V_484 )
{
T_1 V_485 = 0 ;
struct V_420 * V_414 = (struct V_420 * ) V_484 ;
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
F_11 ( V_2 , & V_485 ) ;
if ( ! V_485 )
return V_486 ;
do {
F_1 ( V_2 , V_485 ) ;
V_485 &= V_2 -> V_7 ;
if ( F_253 ( V_485 & V_481 ) ) {
F_7 ( V_2 , V_481 ) ;
F_254 ( & V_259 -> V_487 ) ;
}
if ( F_258 ( V_485 & V_479 ) ) {
F_7 ( V_2 , V_479 ) ;
F_254 ( & V_259 -> V_480 ) ;
}
if ( F_253 ( V_485 & V_326 ) ) {
V_414 -> V_434 . V_488 ++ ;
F_164 ( V_2 ) ;
}
if ( F_253 ( V_485 & V_489 ) ) {
struct V_203 * V_66 = & V_422 -> V_66 ;
V_2 -> V_225 |= V_490 ;
F_136 ( V_66 ) ;
}
if ( F_253 ( V_485 & V_343 ) ) {
F_256 ( V_2 ) ;
break;
}
if ( F_253 ( V_485 & V_491 ) ) {
T_2 V_20 ;
V_2 -> V_7 &= ~ V_491 ;
F_259 ( L_3 ) ;
V_20 = F_4 ( V_2 -> V_4 + V_215 ) ;
if ( ! ( V_20 & V_314 ) )
F_259 ( L_4 ) ;
break;
}
} while ( 0 );
F_6 ( V_2 ) ;
return V_492 ;
}
static void F_260 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
F_3 ( & V_259 -> V_2 ) ;
F_257 ( V_414 -> V_483 , V_414 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
int V_66 ;
T_4 V_58 ;
struct V_104 * V_21 = V_2 -> V_104 ;
if ( ! V_21 -> V_58 ) {
F_104 ( V_2 , V_383 , V_168 ) ;
F_107 ( V_2 ) ;
}
for ( V_66 = 0 ; V_66 < V_383 ; V_66 ++ ) {
if ( V_166 == V_21 -> F_36 [ V_66 ] . V_169 )
V_58 = V_174 | V_21 -> V_58 ;
else
V_58 = V_174 | ( 1 << V_66 ) ;
if ( V_58 != V_21 -> F_36 [ V_66 ] . V_58 )
F_99 ( V_2 , V_66 , V_58 ) ;
}
}
static int F_262 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_493 ;
F_236 ( V_414 ) ;
F_189 ( & V_422 -> V_494 ) ;
if ( V_2 -> V_384 > 1 ) {
F_104 ( V_2 , V_66 -> V_231 , V_163 ) ;
if ( V_2 -> V_225 & V_387 ) {
V_493 = 1 << V_66 -> V_231 ;
if ( V_2 -> V_104 -> V_58 & V_493 ) {
V_2 -> V_104 -> V_58 &= ~ V_493 ;
F_261 ( V_2 ) ;
}
}
}
if ( V_66 -> V_231 > 0 )
F_180 ( V_2 , V_414 -> V_495 ) ;
if ( ! V_259 -> V_282 )
F_139 ( V_66 , true ) ;
if ( V_422 -> V_381 )
-- V_2 -> V_321 ;
if ( V_422 -> V_323 )
-- V_2 -> V_323 ;
V_259 -> V_496 -- ;
if ( ! ( V_259 -> V_496 ) ) {
F_189 ( & V_259 -> V_497 ) ;
F_263 ( & V_259 -> V_498 ) ;
F_3 ( V_2 ) ;
F_169 ( V_2 ) ;
F_181 ( V_2 ) ;
F_264 ( 2000 / V_499 ) ;
F_265 ( & V_259 -> V_480 ) ;
F_265 ( & V_259 -> V_487 ) ;
F_266 ( V_414 -> V_483 , V_259 -> V_414 ) ;
F_219 ( V_259 , 0 ) ;
F_163 ( & V_2 -> V_400 ) ;
F_163 ( & V_2 -> V_347 ) ;
if ( V_2 -> V_225 & V_387 )
F_105 ( V_2 ) ;
}
return 0 ;
}
static void F_267 ( struct V_258 * V_259 , struct V_1 * V_2 )
{
if ( V_2 -> V_104 ) {
T_2 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_107 ) ;
if ( V_2 -> V_225 & V_500 )
V_20 |= V_501 ;
else
V_20 &= ~ V_501 ;
F_24 ( V_20 , V_2 -> V_4 + V_107 ) ;
}
if ( V_2 -> V_225 & V_500 ) {
V_2 -> V_209 |= V_502 ;
V_259 -> V_477 = F_251 ;
} else {
V_2 -> V_209 &= ~ V_502 ;
if ( V_2 -> V_384 > 1 )
V_259 -> V_477 = F_249 ;
else
V_259 -> V_477 = F_248 ;
}
}
static int F_268 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_294 = 0 ;
V_259 -> V_414 = V_414 ;
V_294 = F_269 ( V_414 -> V_483 , F_257 , V_503 , V_414 -> V_504 , V_414 ) ;
if ( V_294 )
return V_294 ;
F_270 ( & V_259 -> V_480 ) ;
F_270 ( & V_259 -> V_487 ) ;
V_2 -> V_323 = 0 ;
V_2 -> V_321 = 0 ;
V_2 -> V_379 = 0 ;
F_155 ( V_2 ) ;
F_162 ( V_2 ,
V_2 -> V_347 . V_331 , V_2 -> V_400 . V_331 ) ;
F_174 ( V_2 ) ;
F_267 ( V_259 , V_2 ) ;
F_202 ( V_259 ) ;
return 0 ;
}
static void F_271 ( struct V_420 * V_414 , int V_505 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
if ( V_505 == V_422 -> V_505 )
F_272 ( V_414 ) ;
else
F_273 ( V_414 ) ;
F_274 ( V_422 , V_506 , V_414 , L_5 ,
V_505 == V_422 -> V_505 ? L_6 : L_7 ) ;
}
static int F_275 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
int V_154 ;
int V_93 ;
int V_294 = 0 ;
V_422 -> V_381 = 0 ;
V_422 -> V_323 = 0 ;
memset ( & V_414 -> V_434 , 0 , sizeof( struct V_507 ) ) ;
memset ( ( void * ) V_66 -> V_85 , 0 ,
( sizeof( T_5 ) * V_508 ) ) ;
if ( ! ( V_259 -> V_496 ) ) {
V_294 = F_268 ( V_414 ) ;
if ( V_294 )
return V_294 ;
for ( V_154 = 0 ; V_154 < V_2 -> V_509 ; V_154 ++ ) {
if ( V_510 < V_393 )
V_510 = V_393 + V_499 * 2 ;
else
V_510 += V_499 * 1 ;
V_259 -> V_85 [ V_154 ] . time = V_510 ;
V_2 -> V_82 [ V_154 ] . V_162 = V_244 ;
F_32 ( V_2 , V_154 ) ;
}
if ( V_2 -> V_104 )
V_2 -> V_82 [ V_511 ] . V_162 = V_243 ;
else {
F_150 ( V_2 ) ;
F_145 ( V_2 , 0 ) ;
F_143 ( & V_259 -> V_2 ) ;
}
}
F_139 ( V_66 , false ) ;
for ( V_154 = 0 , V_93 = V_66 -> V_231 ; V_154 < V_66 -> V_232 ; V_154 ++ , V_93 ++ ) {
V_2 -> V_233 [ V_93 ] . V_239 = 0xFF ;
V_2 -> V_233 [ V_93 ] . V_162 = V_244 ;
}
if ( V_2 -> V_384 > 1 ) {
F_104 ( V_2 , V_66 -> V_231 , V_168 ) ;
if ( V_66 -> V_231 > 0 )
F_179 ( V_2 , V_414 -> V_495 ) ;
}
F_136 ( V_66 ) ;
if ( V_66 -> V_219 )
F_138 ( V_66 ) ;
else
F_137 ( V_66 ) ;
if ( ! ( V_259 -> V_496 ) ) {
F_157 ( V_2 ) ;
F_170 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_509 )
F_187 ( & V_259 -> V_497 ,
V_259 -> V_497 . V_395 ) ;
}
V_259 -> V_496 ++ ;
F_187 ( & V_422 -> V_494 ,
V_422 -> V_494 . V_395 ) ;
V_422 -> V_505 = V_66 -> V_229 -> V_162 ;
F_271 ( V_414 , V_243 ) ;
F_276 ( V_414 ) ;
return 0 ;
}
static struct V_507 * F_277 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_203 * V_66 = & V_422 -> V_66 ;
struct V_1 * V_2 = & V_422 -> V_397 -> V_2 ;
struct V_80 * V_81 ;
int V_154 ;
int V_93 ;
V_414 -> V_434 . V_512 = V_66 -> V_85 [ V_476 ] ;
V_414 -> V_434 . V_513 = V_66 -> V_85 [ V_514 ] ;
V_414 -> V_434 . V_381 = 0 ;
V_414 -> V_434 . V_515 = 0 ;
V_414 -> V_434 . V_516 = 0 ;
V_414 -> V_434 . V_517 = 0 ;
V_414 -> V_434 . V_518 = 0 ;
V_414 -> V_434 . V_519 = 0 ;
for ( V_154 = 0 , V_93 = V_66 -> V_231 ; V_154 < V_66 -> V_509 ; V_154 ++ , V_93 ++ ) {
V_81 = & V_2 -> V_82 [ V_93 ] ;
V_414 -> V_434 . V_381 += ( unsigned long )
V_81 -> V_85 [ V_520 ] ;
V_414 -> V_434 . V_515 += ( unsigned long )
V_81 -> V_85 [ V_521 ] ;
V_414 -> V_434 . V_516 += ( unsigned long ) (
V_81 -> V_85 [ V_522 ] +
V_81 -> V_85 [ V_523 ] +
V_81 -> V_85 [ V_524 ] +
V_81 -> V_85 [ V_525 ] ) ;
V_414 -> V_434 . V_517 += ( unsigned long )
V_81 -> V_85 [ V_526 ] ;
V_414 -> V_434 . V_518 += ( unsigned long ) (
V_81 -> V_85 [ V_527 ] +
V_81 -> V_85 [ V_528 ] ) ;
V_414 -> V_434 . V_519 += ( unsigned long )
V_81 -> V_85 [ V_529 ] ;
}
return & V_414 -> V_434 ;
}
static int F_278 ( struct V_420 * V_414 , void * V_32 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_530 * V_531 = V_32 ;
T_1 V_3 ;
if ( V_422 -> V_66 . V_231 > 0 )
F_180 ( V_2 , V_414 -> V_495 ) ;
else {
V_2 -> V_362 = 1 ;
memcpy ( V_2 -> V_281 , V_531 -> V_532 , V_280 ) ;
}
memcpy ( V_414 -> V_495 , V_531 -> V_532 , V_533 ) ;
V_3 = F_13 ( V_2 ) ;
if ( V_422 -> V_66 . V_231 > 0 )
F_179 ( V_2 , V_414 -> V_495 ) ;
else
F_174 ( V_2 ) ;
F_12 ( V_2 , V_3 ) ;
return 0 ;
}
static void F_279 ( struct V_420 * V_414 , struct V_421 * V_422 ,
struct V_1 * V_2 , int V_323 )
{
if ( V_323 != V_422 -> V_323 ) {
T_4 V_534 = V_2 -> V_323 ;
if ( V_323 )
++ V_2 -> V_323 ;
else
-- V_2 -> V_323 ;
V_422 -> V_323 = V_323 ;
if ( V_2 -> V_323 <= 1 && V_534 <= 1 )
F_184 ( V_2 , V_2 -> V_323 ) ;
if ( ( V_2 -> V_225 & V_387 ) && ! V_323 &&
( V_414 -> V_535 & V_536 ) ) {
struct V_104 * V_21 = V_2 -> V_104 ;
int V_66 = V_422 -> V_66 . V_231 ;
F_104 ( V_2 , V_66 , V_163 ) ;
V_66 = 1 << V_66 ;
if ( V_21 -> V_58 & V_66 ) {
V_21 -> V_58 &= ~ V_66 ;
F_261 ( V_2 ) ;
}
}
}
}
static void F_280 ( struct V_421 * V_422 , struct V_1 * V_2 ,
int V_381 )
{
if ( V_381 != V_422 -> V_381 ) {
T_4 V_321 = V_2 -> V_321 ;
if ( V_381 )
++ V_2 -> V_321 ;
else
-- V_2 -> V_321 ;
V_422 -> V_381 = V_381 ;
if ( V_2 -> V_321 <= 1 && V_321 <= 1 )
F_183 ( V_2 , V_2 -> V_321 ) ;
}
}
static void F_281 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_537 * V_538 ;
int V_381 = ( V_414 -> V_539 & V_540 ) ;
F_279 ( V_414 , V_422 , V_2 , ( V_414 -> V_539 & V_541 ) ) ;
if ( V_259 -> V_2 . V_384 > 1 )
V_381 |= ( V_414 -> V_539 & V_542 ) ;
F_280 ( V_422 , V_2 , V_381 ) ;
if ( V_259 -> V_2 . V_384 > 1 )
return;
if ( ( V_414 -> V_539 & V_542 ) && ! F_282 ( V_414 ) ) {
int V_154 = 0 ;
if ( F_283 ( V_414 ) > V_543 ) {
if ( V_543 != V_2 -> V_379 ) {
V_2 -> V_379 = V_543 ;
++ V_2 -> V_321 ;
F_183 ( V_2 , V_2 -> V_321 ) ;
}
return;
}
F_284 (ha, dev) {
if ( V_154 >= V_543 )
break;
memcpy ( V_2 -> V_380 [ V_154 ++ ] , V_538 -> V_32 , V_280 ) ;
}
V_2 -> V_379 = ( T_4 ) V_154 ;
F_182 ( V_2 ) ;
} else {
if ( V_543 == V_2 -> V_379 ) {
-- V_2 -> V_321 ;
F_183 ( V_2 , V_2 -> V_321 ) ;
}
V_2 -> V_379 = 0 ;
F_181 ( V_2 ) ;
}
}
static int F_285 ( struct V_420 * V_414 , int V_544 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_545 ;
if ( F_225 ( V_414 ) )
return - V_546 ;
if ( V_2 -> V_384 > 1 )
if ( V_414 != V_259 -> V_414 )
return 0 ;
if ( V_544 < 60 )
return - V_547 ;
if ( V_414 -> V_411 != V_544 ) {
V_545 = V_544 + V_548 + 4 ;
if ( V_545 > V_549 )
return - V_547 ;
if ( V_545 > V_550 ) {
V_2 -> V_225 |= V_500 ;
V_545 = V_549 ;
} else {
V_2 -> V_225 &= ~ V_500 ;
V_545 = V_550 ;
}
V_545 = ( V_545 + 3 ) & ~ 3 ;
V_259 -> V_411 = V_545 ;
V_414 -> V_411 = V_544 ;
}
return 0 ;
}
static int F_286 ( struct V_420 * V_414 , struct V_551 * V_552 , int V_553 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
int V_294 ;
int V_554 = 0 ;
struct V_555 * V_20 = F_287 ( V_552 ) ;
if ( F_288 ( & V_422 -> V_556 ) )
return - V_557 ;
V_294 = 0 ;
switch ( V_553 ) {
case V_558 :
V_20 -> V_559 = V_422 -> V_364 ;
case V_560 :
if ( V_20 -> V_559 != V_422 -> V_364 || V_20 -> V_561 >= 6 )
V_554 = - V_562 ;
else
F_120 ( V_2 , V_66 -> V_229 -> V_563 , V_20 -> V_561 ,
& V_20 -> V_564 ) ;
break;
case V_565 :
if ( ! F_289 ( V_566 ) )
V_554 = - V_567 ;
else if ( V_20 -> V_559 != V_422 -> V_364 || V_20 -> V_561 >= 6 )
V_554 = - V_562 ;
else
F_121 ( V_2 , V_66 -> V_229 -> V_563 , V_20 -> V_561 ,
V_20 -> V_568 ) ;
break;
default:
V_554 = - V_569 ;
}
F_290 ( & V_422 -> V_556 ) ;
return V_554 ;
}
static int F_291 ( struct V_420 * V_414 , int V_559 , int V_561 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_203 * V_66 = & V_422 -> V_66 ;
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_564 ;
F_120 ( V_2 , V_66 -> V_229 -> V_563 , V_561 << 1 , & V_564 ) ;
return V_564 ;
}
static void F_292 ( struct V_420 * V_414 , int V_559 , int V_561 , int V_185 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_203 * V_66 = & V_422 -> V_66 ;
struct V_1 * V_2 = V_66 -> V_2 ;
int V_154 ;
int V_493 ;
for ( V_154 = 0 , V_493 = V_66 -> V_231 ; V_154 < V_66 -> V_232 ; V_154 ++ , V_493 ++ )
F_121 ( V_2 , V_493 , V_561 << 1 , V_185 ) ;
}
static int F_293 ( struct V_420 * V_414 , struct V_570 * V_553 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
F_294 ( & V_259 -> V_571 ) ;
F_295 ( & V_422 -> V_572 , V_553 ) ;
V_553 -> V_573 |= V_574 ;
F_296 ( & V_259 -> V_571 ) ;
V_422 -> V_573 = V_553 -> V_573 ;
return 0 ;
}
static int F_297 ( struct V_420 * V_414 , struct V_570 * V_553 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
T_2 V_251 = F_298 ( V_553 ) ;
int V_294 ;
if ( V_553 -> V_575 && V_422 -> V_573 == V_553 -> V_573 ) {
V_553 -> V_573 |= V_576 ;
if ( 10 == V_251 )
V_553 -> V_573 &=
~ ( V_577 |
V_578 ) ;
else if ( 100 == V_251 )
V_553 -> V_573 &=
~ ( V_579 |
V_580 ) ;
if ( 0 == V_553 -> V_228 )
V_553 -> V_573 &=
~ ( V_577 |
V_579 ) ;
else if ( 1 == V_553 -> V_228 )
V_553 -> V_573 &=
~ ( V_578 |
V_580 ) ;
}
F_294 ( & V_259 -> V_571 ) ;
if ( V_553 -> V_575 &&
( V_553 -> V_573 & V_576 ) ==
V_576 ) {
V_66 -> V_228 = 0 ;
V_66 -> V_251 = 0 ;
V_66 -> V_219 = 0 ;
} else {
V_66 -> V_228 = V_553 -> V_228 + 1 ;
if ( 1000 != V_251 )
V_66 -> V_251 = V_251 ;
if ( V_553 -> V_575 )
V_66 -> V_219 = 0 ;
else
V_66 -> V_219 = 1 ;
}
V_294 = F_299 ( & V_422 -> V_572 , V_553 ) ;
F_296 ( & V_259 -> V_571 ) ;
return V_294 ;
}
static int F_300 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
int V_294 ;
F_294 ( & V_259 -> V_571 ) ;
V_294 = F_301 ( & V_422 -> V_572 ) ;
F_296 ( & V_259 -> V_571 ) ;
return V_294 ;
}
static T_2 F_302 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
int V_294 ;
V_294 = F_303 ( & V_422 -> V_572 ) ;
return V_294 ;
}
static void F_304 ( struct V_420 * V_414 ,
struct V_581 * V_26 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
strcpy ( V_26 -> V_582 , V_583 ) ;
strcpy ( V_26 -> V_584 , V_585 ) ;
strcpy ( V_26 -> V_586 , F_305 ( V_259 -> V_261 ) ) ;
}
static int F_306 ( struct V_420 * V_414 )
{
struct V_587 * V_588 = V_589 ;
int V_590 = 0x10 * sizeof( T_2 ) ;
while ( V_588 -> V_591 > V_588 -> V_592 ) {
V_590 += ( V_588 -> V_591 - V_588 -> V_592 + 3 ) / 4 * 4 ;
V_588 ++ ;
}
return V_590 ;
}
static void F_307 ( struct V_420 * V_414 , struct V_593 * V_594 ,
void * V_595 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int * V_24 = ( int * ) V_595 ;
struct V_587 * V_588 = V_589 ;
int V_33 ;
F_294 ( & V_259 -> V_571 ) ;
V_594 -> V_584 = 0 ;
for ( V_33 = 0 ; V_33 < 0x40 ; V_33 += 4 ) {
F_308 ( V_259 -> V_261 , V_33 , V_24 ) ;
V_24 ++ ;
}
while ( V_588 -> V_591 > V_588 -> V_592 ) {
for ( V_33 = V_588 -> V_592 ; V_33 < V_588 -> V_591 ; V_33 += 4 ) {
* V_24 = F_4 ( V_2 -> V_4 + V_33 ) ;
V_24 ++ ;
}
V_588 ++ ;
}
F_296 ( & V_259 -> V_571 ) ;
}
static void F_309 ( struct V_420 * V_414 ,
struct V_596 * V_597 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
V_597 -> V_598 = V_259 -> V_599 ;
V_597 -> V_600 = V_259 -> V_282 ;
memset ( & V_597 -> V_601 , 0 , sizeof( V_597 -> V_601 ) ) ;
}
static int F_310 ( struct V_420 * V_414 ,
struct V_596 * V_597 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
static const T_4 V_283 [] = { 192 , 168 , 1 , 1 } ;
if ( V_597 -> V_600 & ~ V_259 -> V_599 )
return - V_547 ;
V_259 -> V_282 = V_597 -> V_600 ;
if ( V_597 -> V_600 )
V_259 -> V_282 |= V_602 ;
F_153 ( & V_259 -> V_2 , V_259 -> V_282 , V_283 ) ;
return 0 ;
}
static T_2 F_311 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
return V_422 -> V_603 ;
}
static void F_312 ( struct V_420 * V_414 , T_2 V_97 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
V_422 -> V_603 = V_97 ;
}
static int F_313 ( struct V_420 * V_414 )
{
return V_604 * 2 ;
}
static int F_314 ( struct V_420 * V_414 ,
struct V_605 * V_606 , T_4 * V_20 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
T_4 * V_607 = ( T_4 * ) V_608 ;
int V_154 ;
int V_33 ;
V_33 = ( V_606 -> V_89 + V_606 -> V_33 + 1 ) / 2 ;
for ( V_154 = V_606 -> V_89 / 2 ; V_154 < V_33 ; V_154 ++ )
V_608 [ V_154 ] = F_130 ( & V_259 -> V_2 , V_154 ) ;
V_606 -> V_609 = V_610 ;
memcpy ( V_20 , & V_607 [ V_606 -> V_89 ] , V_606 -> V_33 ) ;
return 0 ;
}
static int F_315 ( struct V_420 * V_414 ,
struct V_605 * V_606 , T_4 * V_20 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
T_3 V_611 [ V_604 ] ;
T_4 * V_607 = ( T_4 * ) V_611 ;
int V_154 ;
int V_33 ;
if ( V_606 -> V_609 != V_610 )
return - V_547 ;
V_33 = ( V_606 -> V_89 + V_606 -> V_33 + 1 ) / 2 ;
for ( V_154 = V_606 -> V_89 / 2 ; V_154 < V_33 ; V_154 ++ )
V_608 [ V_154 ] = F_130 ( & V_259 -> V_2 , V_154 ) ;
memcpy ( V_611 , V_608 , V_604 * 2 ) ;
memcpy ( & V_607 [ V_606 -> V_89 ] , V_20 , V_606 -> V_33 ) ;
for ( V_154 = 0 ; V_154 < V_604 ; V_154 ++ )
if ( V_611 [ V_154 ] != V_608 [ V_154 ] ) {
V_608 [ V_154 ] = V_611 [ V_154 ] ;
F_131 ( & V_259 -> V_2 , V_154 , V_608 [ V_154 ] ) ;
}
return 0 ;
}
static void F_316 ( struct V_420 * V_414 ,
struct V_612 * V_613 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
V_613 -> V_575 = ( V_2 -> V_122 & V_218 ) ? 0 : 1 ;
if ( ! V_2 -> V_104 ) {
V_613 -> V_614 =
( V_2 -> V_209 & V_211 ) ? 1 : 0 ;
V_613 -> V_615 =
( V_2 -> V_210 & V_212 ) ? 1 : 0 ;
} else {
V_613 -> V_614 =
( F_43 ( V_2 , V_120 ,
V_389 ) ) ? 1 : 0 ;
V_613 -> V_615 =
( F_43 ( V_2 , V_120 ,
V_388 ) ) ? 1 : 0 ;
}
}
static int F_317 ( struct V_420 * V_414 ,
struct V_612 * V_613 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
F_294 ( & V_259 -> V_571 ) ;
if ( V_613 -> V_575 ) {
if ( ! V_613 -> V_614 && ! V_613 -> V_615 )
V_66 -> V_205 = V_616 ;
else
V_66 -> V_205 = V_206 ;
V_2 -> V_122 &= ~ V_218 ;
V_66 -> V_219 = 0 ;
if ( V_2 -> V_104 ) {
F_44 ( V_2 , V_120 ,
V_389 , 1 ) ;
F_44 ( V_2 , V_120 ,
V_388 , 1 ) ;
}
F_137 ( V_66 ) ;
} else {
V_2 -> V_122 |= V_218 ;
if ( V_2 -> V_104 ) {
F_44 ( V_2 , V_120 ,
V_389 , V_613 -> V_614 ) ;
F_44 ( V_2 , V_120 ,
V_388 , V_613 -> V_615 ) ;
} else
F_133 ( V_2 , V_613 -> V_614 , V_613 -> V_615 ) ;
}
F_296 ( & V_259 -> V_571 ) ;
return 0 ;
}
static void F_318 ( struct V_420 * V_414 ,
struct V_617 * V_27 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
V_27 -> V_618 = ( 1 << 9 ) ;
V_27 -> V_619 = V_2 -> V_347 . V_327 ;
V_27 -> V_620 = ( 1 << 9 ) ;
V_27 -> V_621 = V_2 -> V_400 . V_327 ;
}
static void F_319 ( struct V_420 * V_414 , T_2 V_622 , T_4 * V_24 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
if ( V_623 == V_622 )
memcpy ( V_24 , & V_624 ,
V_625 * V_2 -> V_86 ) ;
}
static int F_320 ( struct V_420 * V_414 , int V_626 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
switch ( V_626 ) {
case V_623 :
return V_2 -> V_86 ;
default:
return - V_569 ;
}
}
static void F_321 ( struct V_420 * V_414 ,
struct V_627 * V_434 , T_5 * V_20 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
int V_628 = V_434 -> V_628 ;
int V_154 ;
int V_629 ;
int V_93 ;
int V_294 ;
T_5 V_85 [ V_88 ] ;
F_294 ( & V_259 -> V_571 ) ;
V_629 = V_383 ;
for ( V_154 = 0 , V_93 = V_66 -> V_231 ; V_154 < V_66 -> V_509 ; V_154 ++ , V_93 ++ ) {
if ( V_243 == V_2 -> V_82 [ V_93 ] . V_162 ) {
V_259 -> V_85 [ V_93 ] . V_630 = 1 ;
if ( V_629 == V_383 )
V_629 = V_93 ;
}
}
F_296 ( & V_259 -> V_571 ) ;
if ( V_629 < V_383 )
F_322 ( & V_259 -> V_498 ) ;
if ( 1 == V_66 -> V_509 && V_629 < V_383 ) {
V_93 = V_629 ;
V_294 = F_323 (
V_259 -> V_85 [ V_93 ] . V_85 ,
2 == V_259 -> V_85 [ V_93 ] . V_630 ,
V_499 * 1 ) ;
} else
for ( V_154 = 0 , V_93 = V_629 ; V_154 < V_66 -> V_509 - V_629 ; V_154 ++ , V_93 ++ ) {
if ( 0 == V_154 ) {
V_294 = F_323 (
V_259 -> V_85 [ V_93 ] . V_85 ,
2 == V_259 -> V_85 [ V_93 ] . V_630 ,
V_499 * 2 ) ;
} else if ( V_2 -> V_82 [ V_93 ] . V_84 ) {
V_294 = F_323 (
V_259 -> V_85 [ V_93 ] . V_85 ,
2 == V_259 -> V_85 [ V_93 ] . V_630 ,
V_499 * 1 ) ;
}
}
F_213 ( V_2 , V_66 -> V_231 , V_66 -> V_509 , V_85 ) ;
V_629 = V_2 -> V_86 ;
if ( V_629 > V_628 )
V_629 = V_628 ;
V_628 -= V_629 ;
for ( V_154 = 0 ; V_154 < V_629 ; V_154 ++ )
* V_20 ++ = V_85 [ V_154 ] ;
}
static int F_324 ( struct V_420 * V_414 , T_2 V_225 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
F_294 ( & V_259 -> V_571 ) ;
if ( V_225 & V_631 )
V_2 -> V_209 |= V_319 | V_320 ;
else
V_2 -> V_209 &= ~ ( V_319 | V_320 ) ;
if ( V_2 -> V_213 )
F_2 ( V_2 -> V_209 , V_2 -> V_4 + V_214 ) ;
F_296 ( & V_259 -> V_571 ) ;
return 0 ;
}
static void F_325 ( struct V_420 * V_414 , struct V_421 * V_422 ,
struct V_203 * V_66 )
{
if ( V_422 -> V_505 != V_66 -> V_229 -> V_162 ) {
V_422 -> V_505 = V_66 -> V_229 -> V_162 ;
if ( F_225 ( V_414 ) )
F_271 ( V_414 , V_243 ) ;
}
}
static void F_326 ( struct V_632 * V_633 )
{
struct V_258 * V_259 =
F_141 ( V_633 , struct V_258 , V_498 ) ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_80 * V_81 ;
int V_154 ;
V_510 = V_393 ;
for ( V_154 = 0 ; V_154 < V_2 -> V_509 ; V_154 ++ ) {
V_81 = & V_2 -> V_82 [ V_154 ] ;
if ( V_81 -> V_84 || 1 == V_259 -> V_85 [ V_154 ] . V_630 ) {
if ( F_31 ( V_2 , V_154 ) )
break;
V_259 -> V_85 [ V_154 ] . V_630 = 0 ;
if ( 0 == V_81 -> V_84 ) {
V_259 -> V_85 [ V_154 ] . V_630 = 2 ;
F_327 (
& V_259 -> V_85 [ V_154 ] . V_85 ) ;
}
} else if ( V_393 >= V_259 -> V_85 [ V_154 ] . time ) {
if ( V_243 == V_81 -> V_162 )
V_259 -> V_85 [ V_154 ] . V_630 = 1 ;
V_510 += V_499 * 1 * V_2 -> V_509 ;
V_259 -> V_85 [ V_154 ] . time = V_510 ;
} else if ( V_81 -> V_245 ) {
V_81 -> V_245 = 0 ;
V_259 -> V_85 [ V_154 ] . V_630 = 1 ;
}
}
}
static void F_328 ( unsigned long V_595 )
{
struct V_258 * V_259 = (struct V_258 * ) V_595 ;
F_326 ( & V_259 -> V_498 ) ;
if ( V_259 -> V_634 ) {
if ( V_259 -> V_634 <= V_393 ) {
F_143 ( & V_259 -> V_2 ) ;
V_259 -> V_634 = 0 ;
}
} else if ( F_140 ( & V_259 -> V_2 ) ) {
V_259 -> V_634 = V_393 + V_499 * 2 ;
}
F_194 ( & V_259 -> V_497 ) ;
}
static void F_329 ( unsigned long V_595 )
{
struct V_420 * V_414 = (struct V_420 * ) V_595 ;
struct V_421 * V_422 = F_215 ( V_414 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
if ( ! ( V_2 -> V_225 & V_490 ) )
F_136 ( V_66 ) ;
F_325 ( V_414 , V_422 , V_66 ) ;
F_194 ( & V_422 -> V_494 ) ;
}
static int T_9 F_330 ( struct V_420 * V_414 )
{
struct V_421 * V_422 = F_215 ( V_414 ) ;
F_191 ( & V_422 -> V_494 , 500 * V_499 / 1000 ,
F_329 , V_414 ) ;
V_414 -> V_451 = V_499 / 2 ;
V_414 -> V_635 = V_636 | V_637 | V_631 ;
V_414 -> V_635 |= V_638 ;
V_414 -> V_225 |= V_414 -> V_635 ;
F_331 ( & V_422 -> V_556 , 1 ) ;
V_422 -> V_572 . V_639 = 0x1 ;
V_422 -> V_572 . V_640 = 0x7 ;
V_422 -> V_572 . V_414 = V_414 ;
V_422 -> V_572 . F_291 = F_291 ;
V_422 -> V_572 . F_292 = F_292 ;
V_422 -> V_572 . V_559 = V_422 -> V_66 . V_231 + 1 ;
V_422 -> V_603 = F_332 ( V_603 ,
( V_641 | V_642 | V_643 ) ) ;
return 0 ;
}
static void F_333 ( struct V_420 * V_414 )
{
if ( V_414 -> V_451 )
F_334 ( V_414 ) ;
F_335 ( V_414 ) ;
}
static void F_336 ( struct V_258 * V_259 , T_4 * V_644 , int V_66 )
{
int V_154 ;
int V_373 ;
int V_645 ;
int V_103 ;
V_154 = V_373 = V_103 = V_645 = 0 ;
while ( V_373 < V_280 ) {
if ( V_644 [ V_154 ] ) {
int V_646 ;
V_645 = 1 ;
V_646 = F_337 ( V_644 [ V_154 ] ) ;
if ( V_646 >= 0 )
V_103 = V_103 * 16 + V_646 ;
else if ( ':' == V_644 [ V_154 ] )
V_645 = 2 ;
else
break;
} else if ( V_645 )
V_645 = 2 ;
else
break;
if ( 2 == V_645 ) {
if ( V_647 == V_66 ) {
V_259 -> V_2 . V_281 [ V_373 ++ ] = ( T_4 ) V_103 ;
V_259 -> V_2 . V_281 [ 5 ] +=
V_259 -> V_2 . V_364 ;
} else {
V_259 -> V_2 . V_104 -> V_648 [ V_373 ++ ] =
( T_4 ) V_103 ;
V_259 -> V_2 . V_104 -> V_648 [ 5 ] +=
V_259 -> V_2 . V_364 ;
}
V_103 = V_645 = 0 ;
}
V_154 ++ ;
}
if ( V_280 == V_373 ) {
if ( V_647 == V_66 )
V_259 -> V_2 . V_362 = 1 ;
}
}
static void F_338 ( struct V_1 * V_2 )
{
int V_154 ;
T_3 V_20 [ 3 ] ;
struct V_104 * V_21 = V_2 -> V_104 ;
for ( V_154 = 0 ; V_154 < 3 ; V_154 ++ )
V_20 [ V_154 ] = F_130 ( V_2 , V_154 + V_649 ) ;
if ( ( V_20 [ 0 ] || V_20 [ 1 ] || V_20 [ 2 ] ) && V_20 [ 0 ] != 0xffff ) {
V_21 -> V_648 [ 5 ] = ( T_4 ) V_20 [ 0 ] ;
V_21 -> V_648 [ 4 ] = ( T_4 ) ( V_20 [ 0 ] >> 8 ) ;
V_21 -> V_648 [ 3 ] = ( T_4 ) V_20 [ 1 ] ;
V_21 -> V_648 [ 2 ] = ( T_4 ) ( V_20 [ 1 ] >> 8 ) ;
V_21 -> V_648 [ 1 ] = ( T_4 ) V_20 [ 2 ] ;
V_21 -> V_648 [ 0 ] = ( T_4 ) ( V_20 [ 2 ] >> 8 ) ;
}
}
static int T_10 F_339 ( struct V_260 * V_261 ,
const struct V_650 * V_364 )
{
struct V_420 * V_414 ;
struct V_421 * V_422 ;
struct V_258 * V_259 ;
struct V_1 * V_2 ;
struct V_651 * V_26 ;
struct V_203 * V_66 ;
unsigned long V_652 ;
unsigned long V_653 ;
int V_67 ;
int V_154 ;
int V_654 ;
int V_493 ;
int V_655 ;
int V_554 ;
char V_656 [ sizeof( V_584 ) ] ;
struct V_104 * V_21 = NULL ;
V_554 = F_340 ( V_261 ) ;
if ( V_554 )
return V_554 ;
V_554 = - V_657 ;
if ( F_341 ( V_261 , F_342 ( 32 ) ) ||
F_343 ( V_261 , F_342 ( 32 ) ) )
return V_554 ;
V_652 = F_344 ( V_261 , 0 ) ;
V_653 = F_345 ( V_261 , 0 ) ;
if ( ( F_346 ( V_261 , 0 ) & V_658 ) != 0 )
return V_554 ;
if ( ! F_347 ( V_652 , V_653 , V_583 ) )
return V_554 ;
F_348 ( V_261 ) ;
V_554 = - V_465 ;
V_26 = F_349 ( sizeof( struct V_651 ) , V_396 ) ;
if ( ! V_26 )
goto V_659;
V_259 = & V_26 -> V_258 ;
V_259 -> V_261 = V_261 ;
V_2 = & V_259 -> V_2 ;
V_2 -> V_4 = F_350 ( V_652 , V_653 ) ;
if ( ! V_2 -> V_4 )
goto V_660;
V_67 = F_154 ( V_2 ) ;
if ( ! V_67 ) {
if ( V_603 & V_642 )
F_160 ( L_8 ) ;
V_554 = - V_657 ;
goto V_661;
}
snprintf ( V_656 , sizeof( V_656 ) , L_9 , V_584 ) ;
V_656 [ 13 ] = V_67 + '0' ;
V_258 ( & V_259 -> V_261 -> V_414 , L_10 , V_656 ) ;
F_351 ( & V_259 -> V_261 -> V_414 , L_11 , V_2 -> V_4 , V_261 -> V_483 ) ;
V_2 -> V_384 = 1 ;
V_655 = 1 ;
V_654 = 1 ;
V_2 -> V_374 = 0 ;
V_2 -> V_86 = V_69 ;
V_2 -> V_509 = 1 ;
if ( 2 == V_67 ) {
if ( V_662 )
V_2 -> V_122 |= V_123 ;
V_2 -> V_86 = V_88 ;
if ( V_663 ) {
V_2 -> V_384 = V_383 ;
V_2 -> V_374 = V_383 - 1 ;
}
if ( 1 == V_2 -> V_384 ) {
V_655 = V_383 ;
V_654 = V_383 ;
}
V_2 -> V_509 = V_106 ;
V_2 -> V_104 = F_349 ( sizeof( struct V_104 ) , V_396 ) ;
if ( ! V_2 -> V_104 )
goto V_661;
V_21 = V_2 -> V_104 ;
}
for ( V_154 = 0 ; V_154 < V_2 -> V_509 ; V_154 ++ )
V_2 -> V_82 [ V_154 ] . V_83 = 0 ;
V_2 -> V_664 = V_259 ;
V_259 -> V_411 = ( V_550 + 3 ) & ~ 3 ;
if ( F_207 ( V_259 ) )
goto V_665;
V_259 -> V_2 . V_364 = V_666 ;
F_352 ( & V_259 -> V_438 ) ;
F_353 ( & V_259 -> V_571 ) ;
F_354 ( & V_259 -> V_480 , F_252 ,
( unsigned long ) V_259 ) ;
F_354 ( & V_259 -> V_487 , F_255 ,
( unsigned long ) V_259 ) ;
F_265 ( & V_259 -> V_480 ) ;
F_265 ( & V_259 -> V_487 ) ;
for ( V_154 = 0 ; V_154 < V_106 ; V_154 ++ )
F_355 ( & V_259 -> V_85 [ V_154 ] . V_85 ) ;
if ( V_644 [ 0 ] != ':' )
F_336 ( V_259 , V_644 , V_647 ) ;
F_176 ( V_2 ) ;
if ( V_2 -> V_384 > 1 ) {
memcpy ( V_21 -> V_648 , V_2 -> V_281 , V_280 ) ;
F_338 ( V_2 ) ;
if ( V_667 [ 0 ] != ':' )
F_336 ( V_259 , V_667 , V_668 ) ;
}
F_156 ( V_2 ) ;
if ( V_2 -> V_104 )
F_186 ( V_2 ) ;
else {
V_259 -> V_599 = V_669 ;
V_259 -> V_282 = 0 ;
}
F_356 ( & V_259 -> V_498 , F_326 ) ;
F_191 ( & V_259 -> V_497 , 500 * V_499 / 1000 ,
F_328 , V_259 ) ;
for ( V_154 = 0 ; V_154 < V_2 -> V_384 ; V_154 ++ ) {
V_414 = F_357 ( sizeof( struct V_421 ) ) ;
if ( ! V_414 )
goto V_670;
V_26 -> V_671 [ V_154 ] = V_414 ;
V_422 = F_215 ( V_414 ) ;
V_422 -> V_397 = V_259 ;
V_422 -> V_364 = V_666 ++ ;
V_66 = & V_422 -> V_66 ;
V_66 -> V_232 = V_655 ;
V_66 -> V_509 = V_654 ;
V_66 -> V_231 = V_154 ;
V_66 -> V_205 = V_206 ;
V_66 -> V_2 = V_2 ;
V_66 -> V_229 = & V_2 -> V_233 [ V_66 -> V_231 ] ;
for ( V_67 = 0 , V_493 = V_154 ; V_67 < V_655 ; V_67 ++ , V_493 ++ ) {
V_2 -> V_233 [ V_493 ] . V_563 = V_493 ;
V_2 -> V_233 [ V_493 ] . V_261 = V_414 ;
V_2 -> V_233 [ V_493 ] . V_162 = V_244 ;
}
V_414 -> V_672 = ( unsigned long ) V_2 -> V_4 ;
V_414 -> V_673 = V_414 -> V_672 + V_653 - 1 ;
V_414 -> V_483 = V_261 -> V_483 ;
if ( V_647 == V_154 )
memcpy ( V_414 -> V_495 , V_259 -> V_2 . V_281 ,
V_280 ) ;
else {
memcpy ( V_414 -> V_495 , V_21 -> V_648 ,
V_280 ) ;
if ( ! memcmp ( V_21 -> V_648 , V_2 -> V_281 ,
V_280 ) )
V_414 -> V_495 [ 5 ] += V_66 -> V_231 ;
}
V_414 -> V_674 = & V_674 ;
F_358 ( V_414 , & V_675 ) ;
if ( F_359 ( V_414 ) )
goto V_670;
F_139 ( V_66 , true ) ;
}
F_360 ( V_259 -> V_261 ) ;
F_361 ( V_261 , V_26 ) ;
return 0 ;
V_670:
for ( V_154 = 0 ; V_154 < V_2 -> V_384 ; V_154 ++ ) {
if ( V_26 -> V_671 [ V_154 ] ) {
F_333 ( V_26 -> V_671 [ V_154 ] ) ;
V_26 -> V_671 [ V_154 ] = NULL ;
}
}
V_665:
F_212 ( V_259 ) ;
F_210 ( V_2 -> V_104 ) ;
V_661:
F_362 ( V_2 -> V_4 ) ;
V_660:
F_210 ( V_26 ) ;
V_659:
F_363 ( V_652 , V_653 ) ;
return V_554 ;
}
static void F_364 ( struct V_260 * V_261 )
{
int V_154 ;
struct V_651 * V_26 = F_365 ( V_261 ) ;
struct V_258 * V_259 = & V_26 -> V_258 ;
F_361 ( V_261 , NULL ) ;
F_363 ( F_344 ( V_261 , 0 ) ,
F_345 ( V_261 , 0 ) ) ;
for ( V_154 = 0 ; V_154 < V_259 -> V_2 . V_384 ; V_154 ++ ) {
if ( V_26 -> V_671 [ V_154 ] )
F_333 ( V_26 -> V_671 [ V_154 ] ) ;
}
if ( V_259 -> V_2 . V_4 )
F_362 ( V_259 -> V_2 . V_4 ) ;
F_212 ( V_259 ) ;
F_210 ( V_259 -> V_2 . V_104 ) ;
F_366 ( V_259 -> V_261 ) ;
F_210 ( V_26 ) ;
}
static int F_367 ( struct V_260 * V_261 )
{
int V_154 ;
struct V_651 * V_26 = F_365 ( V_261 ) ;
struct V_258 * V_259 = & V_26 -> V_258 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
F_368 ( V_261 , V_676 ) ;
F_369 ( V_261 ) ;
F_370 ( V_261 , V_676 , 0 ) ;
if ( V_259 -> V_282 )
F_145 ( V_2 , 0 ) ;
for ( V_154 = 0 ; V_154 < V_2 -> V_384 ; V_154 ++ ) {
if ( V_26 -> V_671 [ V_154 ] ) {
struct V_420 * V_414 = V_26 -> V_671 [ V_154 ] ;
if ( F_225 ( V_414 ) ) {
F_275 ( V_414 ) ;
F_371 ( V_414 ) ;
}
}
}
return 0 ;
}
static int F_372 ( struct V_260 * V_261 , T_11 V_162 )
{
int V_154 ;
struct V_651 * V_26 = F_365 ( V_261 ) ;
struct V_258 * V_259 = & V_26 -> V_258 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
static const T_4 V_283 [] = { 192 , 168 , 1 , 1 } ;
for ( V_154 = 0 ; V_154 < V_2 -> V_384 ; V_154 ++ ) {
if ( V_26 -> V_671 [ V_154 ] ) {
struct V_420 * V_414 = V_26 -> V_671 [ V_154 ] ;
if ( F_225 ( V_414 ) ) {
F_373 ( V_414 ) ;
F_262 ( V_414 ) ;
}
}
}
if ( V_259 -> V_282 ) {
F_153 ( V_2 , V_259 -> V_282 , V_283 ) ;
F_145 ( V_2 , 1 ) ;
}
F_374 ( V_261 ) ;
F_370 ( V_261 , F_375 ( V_261 , V_162 ) , 1 ) ;
F_368 ( V_261 , F_375 ( V_261 , V_162 ) ) ;
return 0 ;
}
static int T_9 F_376 ( void )
{
return F_377 ( & V_677 ) ;
}
static void T_12 F_378 ( void )
{
F_379 ( & V_677 ) ;
}
