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
static inline void F_61 ( struct V_1 * V_2 , int V_91 )
{
F_44 ( V_2 , V_119 , V_120 , V_91 ) ;
}
static inline void F_62 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_121 & V_122 ) ) {
F_61 ( V_2 , 1 ) ;
F_63 ( 1 ) ;
F_61 ( V_2 , 0 ) ;
}
}
static inline void F_64 ( struct V_1 * V_2 , int V_93 , int V_123 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_124 , V_123 ) ;
}
static inline void F_65 ( struct V_1 * V_2 , int V_93 , int remove )
{
F_36 ( V_2 , V_93 ,
V_94 , V_125 , remove ) ;
}
static inline int F_66 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_124 ) ;
}
static inline int F_67 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_125 ) ;
}
static inline void F_68 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_126 , V_91 ) ;
}
static inline void F_69 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_127 , V_91 ) ;
}
static inline int F_70 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_114 , V_126 ) ;
}
static inline int F_71 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_114 , V_127 ) ;
}
static inline void F_72 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_128 , V_91 ) ;
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
static inline void F_75 ( struct V_1 * V_2 , int V_91 )
{
F_44 ( V_2 , V_107 , V_131 , V_91 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ ) {
F_72 ( V_2 , V_66 , 0 ) ;
F_73 ( V_2 , V_66 , 0 ) ;
F_74 ( V_2 , V_66 , 0 ) ;
}
F_75 ( V_2 , 0 ) ;
}
static inline void F_77 ( struct V_1 * V_2 , int V_91 )
{
F_44 ( V_2 , V_132 ,
V_133 , V_91 ) ;
}
static inline int F_78 ( struct V_1 * V_2 )
{
return F_43 ( V_2 , V_132 ,
V_133 ) ;
}
static inline void F_79 ( struct V_1 * V_2 , int V_66 , int V_91 )
{
F_38 ( V_2 , V_66 , V_132 , 0 , V_91 ) ;
}
static inline int F_80 ( struct V_1 * V_2 , int V_66 )
{
return F_37 ( V_2 , V_66 , V_132 , 0 ) ;
}
static inline void F_81 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_134 , V_91 ) ;
}
static inline void F_82 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_135 , V_91 ) ;
}
static inline void F_83 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_114 , V_136 , V_91 ) ;
}
static inline void F_84 ( struct V_1 * V_2 , int V_93 , int V_91 )
{
F_36 ( V_2 , V_93 ,
V_94 , V_137 , V_91 ) ;
}
static inline int F_85 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_134 ) ;
}
static inline int F_86 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_135 ) ;
}
static inline int F_87 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_114 , V_136 ) ;
}
static inline int F_88 ( struct V_1 * V_2 , int V_93 )
{
return F_33 ( V_2 , V_93 ,
V_94 , V_137 ) ;
}
static void F_89 ( struct V_1 * V_2 , int V_66 )
{
F_81 ( V_2 , V_66 , 0 ) ;
}
static void F_90 ( struct V_1 * V_2 , int V_66 )
{
F_82 ( V_2 , V_66 , 0 ) ;
}
static void F_91 ( struct V_1 * V_2 , int V_91 )
{
F_44 ( V_2 , V_100 , V_138 , V_91 ) ;
}
static void F_92 ( struct V_1 * V_2 , int V_66 , int V_91 )
{
F_83 ( V_2 , V_66 , V_91 ) ;
}
static void F_93 ( struct V_1 * V_2 , int V_66 , T_4 V_110 )
{
T_3 V_20 ;
if ( V_110 > V_139 )
V_110 = V_139 ;
V_2 -> V_104 -> F_36 [ V_66 ] . V_140 = V_110 ;
F_41 ( V_2 , V_66 , V_94 , & V_20 ) ;
V_20 &= ~ V_141 ;
V_20 |= V_110 << V_142 ;
F_42 ( V_2 , V_66 , V_94 , V_20 ) ;
}
static void F_94 ( struct V_1 * V_2 , int V_66 )
{
F_84 ( V_2 , V_66 , 0 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
int V_66 ;
int V_143 ;
struct V_104 * V_21 = V_2 -> V_104 ;
V_21 -> V_144 [ 0 ] = 0 ;
V_21 -> V_144 [ 1 ] = 0 ;
V_21 -> V_144 [ 2 ] = 1 ;
V_21 -> V_144 [ 3 ] = 1 ;
V_21 -> V_144 [ 4 ] = 2 ;
V_21 -> V_144 [ 5 ] = 2 ;
V_21 -> V_144 [ 6 ] = 3 ;
V_21 -> V_144 [ 7 ] = 3 ;
for ( V_143 = 0 ; V_143 < V_145 ; V_143 ++ )
V_21 -> V_146 [ V_143 ] = 0 ;
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ ) {
F_94 ( V_2 , V_66 ) ;
F_89 ( V_2 , V_66 ) ;
F_90 ( V_2 , V_66 ) ;
F_92 ( V_2 , V_66 , 0 ) ;
V_21 -> F_36 [ V_66 ] . V_140 = 0 ;
F_93 ( V_2 , V_66 , V_21 -> F_36 [ V_66 ] . V_140 ) ;
}
F_91 ( V_2 , 0 ) ;
}
static void F_96 ( struct V_1 * V_2 , int V_66 , T_3 * V_57 )
{
T_2 V_32 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_147 ;
* V_57 = F_35 ( V_2 -> V_4 + V_32 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_66 ;
int V_148 ;
struct V_104 * V_21 = V_2 -> V_104 ;
for ( V_148 = 0 ; V_148 < V_149 ; V_148 ++ ) {
F_28 ( V_2 , V_148 ,
& V_21 -> V_150 [ V_148 ] . V_57 ,
& V_21 -> V_150 [ V_148 ] . V_50 ,
& V_21 -> V_150 [ V_148 ] . V_58 ) ;
}
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ ) {
F_96 ( V_2 , V_66 , & V_21 -> F_36 [ V_66 ] . V_57 ) ;
V_21 -> F_36 [ V_66 ] . V_58 = V_151 ;
}
}
static void F_98 ( struct V_1 * V_2 , int V_66 , T_4 V_58 )
{
T_2 V_32 ;
T_4 V_20 ;
F_34 ( V_66 , V_32 ) ;
V_32 += V_114 ;
V_20 = F_40 ( V_2 -> V_4 + V_32 ) ;
V_20 &= ~ V_152 ;
V_20 |= ( V_58 & V_151 ) ;
F_99 ( V_20 , V_2 -> V_4 + V_32 ) ;
V_2 -> V_104 -> F_36 [ V_66 ] . V_58 = V_58 ;
}
static inline void F_100 ( struct V_1 * V_2 , T_4 * V_45 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < 6 ; V_153 += 2 ) {
V_45 [ V_153 ] = F_40 ( V_2 -> V_4 + V_154 + V_153 ) ;
V_45 [ 1 + V_153 ] = F_40 ( V_2 -> V_4 + V_155 + V_153 ) ;
}
}
static void F_101 ( struct V_1 * V_2 , T_4 * V_45 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < 6 ; V_153 += 2 ) {
F_99 ( V_45 [ V_153 ] , V_2 -> V_4 + V_154 + V_153 ) ;
F_99 ( V_45 [ 1 + V_153 ] , V_2 -> V_4 + V_155 + V_153 ) ;
}
}
static void F_102 ( struct V_1 * V_2 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_100 ) ;
V_20 |= V_156 ;
F_24 ( V_20 , V_2 -> V_4 + V_100 ) ;
V_20 = F_35 ( V_2 -> V_4 + V_119 ) ;
V_20 |= V_157 ;
V_20 |= V_158 ;
V_20 |= V_159 ;
if ( V_2 -> V_121 & V_122 )
V_20 |= V_120 ;
else
V_20 &= ~ V_120 ;
F_24 ( V_20 , V_2 -> V_4 + V_119 ) ;
V_20 = F_35 ( V_2 -> V_4 + V_107 ) ;
V_20 |= V_160 ;
F_24 ( V_20 , V_2 -> V_4 + V_107 ) ;
}
static void F_103 ( struct V_1 * V_2 , int V_66 , int V_161 )
{
T_3 V_20 ;
F_41 ( V_2 , V_66 , V_114 , & V_20 ) ;
switch ( V_161 ) {
case V_162 :
V_20 &= ~ ( V_118 | V_117 ) ;
V_20 |= V_163 ;
break;
case V_164 :
V_20 &= ~ V_118 ;
V_20 |= V_117 ;
V_20 |= V_163 ;
break;
case V_165 :
V_20 &= ~ V_118 ;
V_20 |= V_117 ;
V_20 &= ~ V_163 ;
break;
case V_166 :
V_20 |= ( V_118 | V_117 ) ;
V_20 &= ~ V_163 ;
break;
case V_167 :
V_20 &= ~ ( V_118 | V_117 ) ;
V_20 |= V_163 ;
break;
case V_168 :
V_20 |= ( V_118 | V_117 ) ;
V_20 |= V_163 ;
break;
}
F_42 ( V_2 , V_66 , V_114 , V_20 ) ;
V_2 -> V_104 -> F_36 [ V_66 ] . V_169 = V_161 ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_170 * V_148 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < V_171 ; V_153 ++ ) {
V_148 = & V_2 -> V_104 -> V_172 [ V_153 ] ;
F_27 ( V_2 , V_153 ,
V_148 -> V_45 , V_148 -> V_46 ,
V_148 -> V_47 , 0 ,
V_148 -> V_49 , V_148 -> V_50 ) ;
}
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_170 * V_148 ;
V_148 = & V_2 -> V_104 -> V_172 [ V_173 ] ;
V_148 -> V_45 [ 0 ] = 0x01 ;
V_148 -> V_45 [ 1 ] = 0x80 ;
V_148 -> V_45 [ 2 ] = 0xC2 ;
V_148 -> V_45 [ 3 ] = 0x00 ;
V_148 -> V_45 [ 4 ] = 0x00 ;
V_148 -> V_45 [ 5 ] = 0x00 ;
V_148 -> V_46 = V_174 ;
V_148 -> V_47 = 1 ;
V_148 -> V_48 = 1 ;
F_27 ( V_2 , V_173 ,
V_148 -> V_45 , V_148 -> V_46 ,
V_148 -> V_47 , V_148 -> V_48 ,
V_148 -> V_49 , V_148 -> V_50 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_170 * V_148 ;
int V_153 ;
for ( V_153 = V_175 ; V_153 <= V_176 ; V_153 ++ ) {
V_148 = & V_2 -> V_104 -> V_172 [ V_153 ] ;
V_148 -> V_48 = 0 ;
F_27 ( V_2 , V_153 ,
V_148 -> V_45 , V_148 -> V_46 ,
V_148 -> V_47 , V_148 -> V_48 ,
V_148 -> V_49 , V_148 -> V_50 ) ;
}
}
static inline void F_107 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_178 ) ;
}
static inline void F_108 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_178 ) ;
}
static inline void F_109 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_179 ) ;
}
static inline void F_110 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_180 ) ;
}
static inline void F_111 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_180 ) ;
}
static inline void F_112 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_181 ) ;
}
static inline void F_113 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_178 ) ;
}
static inline void F_114 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_178 ) ;
}
static inline void F_115 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_182 ) ;
}
static inline void F_116 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_182 ) ;
}
static inline void F_117 ( struct V_1 * V_2 , int V_177 , T_3 * V_20 )
{
* V_20 = F_35 ( V_2 -> V_4 + V_177 + V_183 ) ;
}
static inline void F_118 ( struct V_1 * V_2 , int V_177 , T_3 V_20 )
{
F_24 ( V_20 , V_2 -> V_4 + V_177 + V_183 ) ;
}
static void F_119 ( struct V_1 * V_2 , int V_66 , T_3 V_184 , T_3 * V_185 )
{
int V_177 ;
V_177 = V_186 + V_66 * V_187 + V_184 ;
* V_185 = F_35 ( V_2 -> V_4 + V_177 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_66 , T_3 V_184 , T_3 V_185 )
{
int V_177 ;
V_177 = V_186 + V_66 * V_187 + V_184 ;
F_24 ( V_185 , V_2 -> V_4 + V_177 ) ;
}
static inline void F_121 ( struct V_1 * V_2 , T_4 V_188 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_189 ) ;
V_20 &= ~ V_188 ;
F_24 ( V_20 , V_2 -> V_4 + V_189 ) ;
}
static inline void F_122 ( struct V_1 * V_2 , T_4 V_188 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_189 ) ;
V_20 |= V_188 ;
F_24 ( V_20 , V_2 -> V_4 + V_189 ) ;
}
static inline T_4 F_123 ( struct V_1 * V_2 , T_4 V_188 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_189 ) ;
return ( T_4 ) ( V_20 & V_188 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_122 ( V_2 , V_190 ) ;
F_125 ( V_191 ) ;
F_121 ( V_2 , V_190 ) ;
F_125 ( V_191 ) ;
}
static T_3 F_126 ( struct V_1 * V_2 )
{
int V_153 ;
T_3 V_192 = 0 ;
for ( V_153 = 15 ; V_153 >= 0 ; V_153 -- ) {
F_122 ( V_2 , V_190 ) ;
F_125 ( V_191 ) ;
V_192 |= ( F_123 ( V_2 , V_193 ) ) ? 1 << V_153 : 0 ;
F_121 ( V_2 , V_190 ) ;
F_125 ( V_191 ) ;
}
return V_192 ;
}
static void F_127 ( struct V_1 * V_2 , T_3 V_20 )
{
int V_153 ;
for ( V_153 = 15 ; V_153 >= 0 ; V_153 -- ) {
( V_20 & ( 0x01 << V_153 ) ) ? F_122 ( V_2 , V_194 ) :
F_121 ( V_2 , V_194 ) ;
F_124 ( V_2 ) ;
}
}
static void F_128 ( struct V_1 * V_2 , T_4 V_20 , T_4 V_184 )
{
int V_153 ;
F_122 ( V_2 , V_194 ) ;
F_124 ( V_2 ) ;
for ( V_153 = 1 ; V_153 >= 0 ; V_153 -- ) {
( V_20 & ( 0x01 << V_153 ) ) ? F_122 ( V_2 , V_194 ) :
F_121 ( V_2 , V_194 ) ;
F_124 ( V_2 ) ;
}
for ( V_153 = 5 ; V_153 >= 0 ; V_153 -- ) {
( V_184 & ( 0x01 << V_153 ) ) ? F_122 ( V_2 , V_194 ) :
F_121 ( V_2 , V_194 ) ;
F_124 ( V_2 ) ;
}
}
static T_3 F_129 ( struct V_1 * V_2 , T_4 V_184 )
{
T_3 V_20 ;
F_122 ( V_2 , V_195 | V_196 ) ;
F_128 ( V_2 , V_197 , V_184 ) ;
V_20 = F_126 ( V_2 ) ;
F_121 ( V_2 , V_195 | V_196 ) ;
return V_20 ;
}
static void F_130 ( struct V_1 * V_2 , T_4 V_184 , T_3 V_20 )
{
int V_68 ;
F_122 ( V_2 , V_195 | V_196 ) ;
F_128 ( V_2 , V_198 , V_199 ) ;
F_121 ( V_2 , V_196 ) ;
F_125 ( 1 ) ;
F_122 ( V_2 , V_196 ) ;
F_128 ( V_2 , V_200 , V_184 ) ;
F_121 ( V_2 , V_196 ) ;
F_125 ( 1 ) ;
F_122 ( V_2 , V_196 ) ;
V_68 = 8 ;
F_63 ( 2 ) ;
do {
F_63 ( 1 ) ;
} while ( ! F_123 ( V_2 , V_193 ) && -- V_68 );
F_121 ( V_2 , V_196 ) ;
F_125 ( 1 ) ;
F_122 ( V_2 , V_196 ) ;
F_128 ( V_2 , V_201 , V_184 ) ;
F_127 ( V_2 , V_20 ) ;
F_121 ( V_2 , V_196 ) ;
F_125 ( 1 ) ;
F_122 ( V_2 , V_196 ) ;
V_68 = 8 ;
F_63 ( 2 ) ;
do {
F_63 ( 1 ) ;
} while ( ! F_123 ( V_2 , V_193 ) && -- V_68 );
F_121 ( V_2 , V_196 ) ;
F_125 ( 1 ) ;
F_122 ( V_2 , V_196 ) ;
F_128 ( V_2 , V_198 , V_202 ) ;
F_121 ( V_2 , V_195 | V_196 ) ;
}
static T_3 F_131 ( struct V_203 * V_66 , T_3 V_19 )
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
static void F_132 ( struct V_1 * V_2 , int V_16 , int V_22 )
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
static void F_133 ( struct V_1 * V_2 , struct V_203 * V_66 ,
T_3 V_216 , T_3 V_217 )
{
int V_16 ;
int V_22 ;
if ( V_2 -> V_121 & V_218 )
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
F_132 ( V_2 , V_16 , V_22 ) ;
}
static inline void F_134 ( struct V_1 * V_2 , struct V_203 * V_66 ,
struct V_223 * V_26 , T_3 V_224 )
{
if ( ( V_2 -> V_225 & V_226 ) &&
! ( V_2 -> V_121 & V_218 ) ) {
T_2 V_227 = V_2 -> V_210 ;
if ( 1 == V_26 -> V_228 )
V_2 -> V_210 &= ~ V_212 ;
if ( V_2 -> V_213 && V_227 != V_2 -> V_210 )
F_2 ( V_2 -> V_210 , V_2 -> V_4 + V_215 ) ;
}
}
static void F_135 ( struct V_203 * V_66 )
{
T_1 V_3 ;
struct V_223 * V_26 ;
struct V_223 * V_229 = NULL ;
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_20 ;
T_3 V_12 ;
T_4 V_216 ;
T_4 V_217 ;
int V_153 ;
int V_93 ;
int V_230 = 0 ;
V_3 = F_13 ( V_2 ) ;
for ( V_153 = 0 , V_93 = V_66 -> V_231 ; V_153 < V_66 -> V_232 ; V_153 ++ , V_93 ++ ) {
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
if ( V_243 != V_26 -> V_161 ) {
F_119 ( V_2 , V_93 , V_180 ,
& V_20 ) ;
F_119 ( V_2 , V_93 , V_181 ,
& V_12 ) ;
F_133 ( V_2 , V_66 , V_20 , V_12 ) ;
if ( V_2 -> V_104 ) {
F_55 ( V_2 , V_93 ,
( 1 == V_26 -> V_228 ) ) ;
}
V_230 |= 1 << V_153 ;
F_134 ( V_2 , V_66 , V_26 , V_12 ) ;
}
V_26 -> V_161 = V_243 ;
} else {
if ( V_244 != V_26 -> V_161 ) {
V_230 |= 1 << V_153 ;
V_2 -> V_82 [ V_93 ] . V_245 = 1 ;
}
V_26 -> V_161 = V_244 ;
}
V_2 -> V_82 [ V_93 ] . V_161 = ( T_4 ) V_26 -> V_161 ;
}
if ( V_229 && V_244 == V_66 -> V_229 -> V_161 )
V_66 -> V_229 = V_229 ;
F_12 ( V_2 , V_3 ) ;
}
static void F_136 ( struct V_203 * V_66 )
{
struct V_223 * V_26 ;
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_20 ;
T_3 V_227 ;
T_4 V_12 ;
int V_153 ;
int V_93 ;
for ( V_153 = 0 , V_93 = V_66 -> V_231 ; V_153 < V_66 -> V_232 ; V_153 ++ , V_93 ++ ) {
V_26 = & V_2 -> V_233 [ V_93 ] ;
F_41 ( V_2 , V_93 , V_234 , & V_20 ) ;
F_39 ( V_2 , V_93 , V_235 , & V_12 ) ;
V_227 = 0 ;
if ( V_12 & V_237 )
V_227 = V_20 ;
V_20 |= V_246 ;
V_20 = F_131 ( V_66 , V_20 ) ;
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
static void F_137 ( struct V_203 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_20 ;
int V_153 ;
int V_177 ;
int V_93 ;
for ( V_153 = 0 , V_93 = V_66 -> V_231 ; V_153 < V_66 -> V_232 ; V_153 ++ , V_93 ++ ) {
V_177 = V_186 + V_93 * V_187 ;
F_107 ( V_2 , V_177 , & V_20 ) ;
V_20 &= ~ V_253 ;
if ( 10 == V_66 -> V_251 )
V_20 &= ~ V_254 ;
else if ( 100 == V_66 -> V_251 )
V_20 |= V_254 ;
if ( 1 == V_66 -> V_228 )
V_20 &= ~ V_255 ;
else if ( 2 == V_66 -> V_228 )
V_20 |= V_255 ;
F_108 ( V_2 , V_177 , V_20 ) ;
}
}
static void F_138 ( struct V_203 * V_66 , int V_256 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_153 ;
int V_93 ;
for ( V_153 = 0 , V_93 = V_66 -> V_231 ; V_153 < V_66 -> V_232 ; V_153 ++ , V_93 ++ )
F_36 ( V_2 , V_93 ,
V_234 , V_257 , V_256 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_258 * V_259 = F_140 ( V_2 , struct V_258 , V_2 ) ;
struct V_260 * V_261 = V_259 -> V_261 ;
T_3 V_20 ;
if ( ! V_261 -> V_262 )
return 0 ;
F_141 ( V_261 , V_261 -> V_262 + V_263 , & V_20 ) ;
return ( V_20 & V_264 ) == V_264 ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_258 * V_259 = F_140 ( V_2 , struct V_258 , V_2 ) ;
struct V_260 * V_261 = V_259 -> V_261 ;
T_3 V_20 ;
if ( ! V_261 -> V_262 )
return;
F_141 ( V_261 , V_261 -> V_262 + V_263 , & V_20 ) ;
V_20 |= V_264 ;
F_143 ( V_261 , V_261 -> V_262 + V_263 , V_20 ) ;
}
static void F_144 ( struct V_1 * V_2 , int V_91 )
{
struct V_258 * V_259 = F_140 ( V_2 , struct V_258 , V_2 ) ;
struct V_260 * V_261 = V_259 -> V_261 ;
T_3 V_20 ;
if ( ! V_261 -> V_262 )
return;
F_141 ( V_261 , V_261 -> V_262 + V_263 , & V_20 ) ;
V_20 &= ~ V_265 ;
if ( V_91 )
V_20 |= V_266 | V_267 ;
else
V_20 &= ~ V_266 ;
F_143 ( V_261 , V_261 -> V_262 + V_263 , V_20 ) ;
}
static void F_145 ( struct V_1 * V_2 , T_3 V_268 , int V_91 )
{
T_3 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_269 ) ;
if ( V_91 )
V_20 |= V_268 ;
else
V_20 &= ~ V_268 ;
F_24 ( V_20 , V_2 -> V_4 + V_269 ) ;
}
static void F_146 ( struct V_1 * V_2 , int V_153 , T_1 V_270 ,
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
V_153 *= 0x10 ;
F_2 ( 0 , V_2 -> V_4 + V_276 + V_153 ) ;
F_2 ( 0 , V_2 -> V_4 + V_277 + V_153 ) ;
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
F_99 ( V_185 , V_2 -> V_4 + V_276 + V_153
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
F_99 ( V_90 , V_2 -> V_4 + V_276 + V_153 + V_33 -
1 ) ;
}
V_275 = F_147 ( V_274 , V_20 ) ;
F_2 ( V_275 , V_2 -> V_4 + V_278 + V_153 ) ;
}
static void F_148 ( struct V_1 * V_2 , const T_4 * V_279 )
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
F_146 ( V_2 , 3 , 6 , V_29 , 42 , V_272 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
static const T_4 V_29 [] = { 0x3F } ;
static const T_4 V_272 [] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
F_146 ( V_2 , 2 , 1 , V_29 , V_280 , V_272 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
static const T_4 V_29 [] = { 0x3F } ;
T_4 V_272 [] = { 0x33 , 0x33 , 0xFF , 0x00 , 0x00 , 0x00 } ;
memcpy ( & V_272 [ 3 ] , & V_2 -> V_281 [ 3 ] , 3 ) ;
F_146 ( V_2 , 1 , 1 , V_29 , 6 , V_272 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
static const T_4 V_29 [] = { 0x3F } ;
F_146 ( V_2 , 0 , 1 , V_29 , V_280 , V_2 -> V_281 ) ;
}
static void F_152 ( struct V_1 * V_2 , T_2 V_282 , const T_4 * V_283 )
{
F_145 ( V_2 , V_284 , ( V_282 & V_285 ) ) ;
F_145 ( V_2 , V_286 , ( V_282 & V_287 ) ) ;
F_151 ( V_2 ) ;
F_145 ( V_2 , V_288 , ( V_282 & V_289 ) ) ;
F_150 ( V_2 ) ;
F_145 ( V_2 , V_290 , ( V_282 & V_291 ) ) ;
F_145 ( V_2 , V_292 , ( V_282 & V_293 ) ) ;
F_148 ( V_2 , V_283 ) ;
}
static int F_153 ( struct V_1 * V_2 )
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
static void F_154 ( struct V_1 * V_2 )
{
F_24 ( V_305 , V_2 -> V_4 + V_306 ) ;
F_63 ( 10 ) ;
F_24 ( 0 , V_2 -> V_4 + V_306 ) ;
}
static void F_155 ( struct V_1 * V_2 )
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
static void F_156 ( struct V_1 * V_2 )
{
V_2 -> V_7 = V_325 | V_326 ;
}
static void F_157 ( struct V_25 * V_26 )
{
#define F_158 2
int V_327 = V_26 -> V_327 ;
int V_92 ;
V_92 = 0 ;
while ( ! ( V_327 & 1 ) ) {
V_92 ++ ;
V_327 >>= 1 ;
}
if ( V_327 != 1 || V_92 < F_158 ) {
F_159 ( L_1 ) ;
while ( V_327 ) {
V_92 ++ ;
V_327 >>= 1 ;
}
if ( V_92 < F_158 )
V_92 = F_158 ;
V_327 = 1 << V_92 ;
V_26 -> V_327 = V_327 ;
}
V_26 -> V_29 = V_26 -> V_327 - 1 ;
}
static void F_160 ( struct V_25 * V_328 , int V_329 )
{
int V_153 ;
T_2 V_330 = V_328 -> V_331 ;
struct V_332 * V_14 = V_328 -> V_333 ;
struct V_13 * V_74 = V_328 -> V_27 ;
struct V_13 * V_334 = NULL ;
for ( V_153 = 0 ; V_153 < V_328 -> V_327 ; V_153 ++ ) {
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
static void F_161 ( struct V_1 * V_2 , T_2 V_337 , T_2 V_338 )
{
F_2 ( V_337 , V_2 -> V_4 + V_339 ) ;
F_2 ( V_338 , V_2 -> V_4 + V_340 ) ;
}
static void F_162 ( struct V_25 * V_26 )
{
V_26 -> V_74 = V_26 -> V_27 ;
V_26 -> V_30 = V_26 -> V_327 ;
V_26 -> V_28 = V_26 -> V_34 = 0 ;
}
static inline void F_163 ( struct V_1 * V_2 )
{
F_2 ( V_341 , V_2 -> V_4 + V_342 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_209 , V_2 -> V_4 + V_214 ) ;
V_2 -> V_7 |= V_343 ;
F_2 ( V_341 , V_2 -> V_4 + V_342 ) ;
F_1 ( V_2 , V_343 ) ;
V_2 -> V_344 ++ ;
if ( 0 == V_2 -> V_344 )
V_2 -> V_344 = 2 ;
}
static void F_165 ( struct V_1 * V_2 )
{
V_2 -> V_344 = 0 ;
F_8 ( V_2 , V_343 ) ;
F_2 ( ( V_2 -> V_209 & ~ V_317 ) , V_2 -> V_4 + V_214 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_210 , V_2 -> V_4 + V_215 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
F_2 ( ( V_2 -> V_210 & ~ V_314 ) , V_2 -> V_4 + V_215 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
F_165 ( V_2 ) ;
F_167 ( V_2 ) ;
V_2 -> V_213 = 0 ;
}
static void F_169 ( struct V_1 * V_2 )
{
F_166 ( V_2 ) ;
F_164 ( V_2 ) ;
V_2 -> V_213 = 1 ;
}
static int F_170 ( struct V_1 * V_2 , int V_345 , int V_346 )
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
static void F_171 ( struct V_1 * V_2 )
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
static int F_172 ( T_4 * V_32 )
{
T_2 * V_358 = ( T_2 * ) V_32 ;
T_3 * V_359 = ( T_3 * ) & V_32 [ 4 ] ;
return 0 == * V_358 && 0 == * V_359 ;
}
static void F_173 ( struct V_1 * V_2 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_280 ; V_153 ++ )
F_99 ( V_2 -> V_281 [ F_174 ( V_153 ) ] ,
V_2 -> V_4 + V_360 + V_153 ) ;
F_101 ( V_2 , V_2 -> V_281 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_280 ; V_153 ++ )
V_2 -> V_361 [ F_174 ( V_153 ) ] = F_40 ( V_2 -> V_4 +
V_360 + V_153 ) ;
if ( ! V_2 -> V_362 ) {
memcpy ( V_2 -> V_281 , V_2 -> V_361 , V_280 ) ;
if ( F_172 ( V_2 -> V_281 ) ) {
memcpy ( V_2 -> V_361 , V_363 , V_280 ) ;
memcpy ( V_2 -> V_281 , V_363 ,
V_280 ) ;
V_2 -> V_281 [ 5 ] += V_2 -> V_364 ;
F_173 ( V_2 ) ;
}
}
}
static void F_176 ( struct V_1 * V_2 , int V_75 , T_4 * V_45 )
{
int V_153 ;
T_2 V_365 ;
T_2 V_366 ;
V_366 = 0 ;
for ( V_153 = 0 ; V_153 < 2 ; V_153 ++ ) {
V_366 <<= 8 ;
V_366 |= V_45 [ V_153 ] ;
}
V_366 |= V_367 ;
V_365 = 0 ;
for ( V_153 = 2 ; V_153 < 6 ; V_153 ++ ) {
V_365 <<= 8 ;
V_365 |= V_45 [ V_153 ] ;
}
V_75 *= V_368 ;
F_2 ( V_365 , V_2 -> V_4 + V_75 + V_369 ) ;
F_2 ( V_366 , V_2 -> V_4 + V_75 + V_370 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_371 ; V_153 ++ ) {
if ( F_172 ( V_2 -> V_372 [ V_153 ] ) )
F_2 ( 0 , V_2 -> V_4 + V_368 * V_153 +
V_370 ) ;
else
F_176 ( V_2 , V_153 , V_2 -> V_372 [ V_153 ] ) ;
}
}
static int F_178 ( struct V_1 * V_2 , T_4 * V_45 )
{
int V_153 ;
int V_373 = V_371 ;
if ( F_179 ( V_2 -> V_281 , V_45 ) )
return 0 ;
for ( V_153 = 0 ; V_153 < V_2 -> V_374 ; V_153 ++ ) {
if ( F_179 ( V_2 -> V_372 [ V_153 ] , V_45 ) )
return 0 ;
if ( V_371 == V_373 && F_172 ( V_2 -> V_372 [ V_153 ] ) )
V_373 = V_153 ;
}
if ( V_373 < V_371 ) {
memcpy ( V_2 -> V_372 [ V_373 ] , V_45 , V_280 ) ;
F_176 ( V_2 , V_373 , V_2 -> V_372 [ V_373 ] ) ;
return 0 ;
}
return - 1 ;
}
static int F_180 ( struct V_1 * V_2 , T_4 * V_45 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_2 -> V_374 ; V_153 ++ ) {
if ( F_179 ( V_2 -> V_372 [ V_153 ] , V_45 ) ) {
F_181 ( V_2 -> V_372 [ V_153 ] ) ;
F_2 ( 0 , V_2 -> V_4 + V_368 * V_153 +
V_370 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_182 ( struct V_1 * V_2 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_375 ; V_153 ++ ) {
V_2 -> V_376 [ V_153 ] = 0 ;
F_99 ( 0 , V_2 -> V_4 + V_377 + V_153 ) ;
}
}
static void F_183 ( struct V_1 * V_2 )
{
int V_153 ;
int V_75 ;
int V_378 ;
int V_97 ;
memset ( V_2 -> V_376 , 0 , sizeof( T_4 ) * V_375 ) ;
for ( V_153 = 0 ; V_153 < V_2 -> V_379 ; V_153 ++ ) {
V_378 = ( F_147 ( 6 , V_2 -> V_380 [ V_153 ] ) >> 26 ) & 0x3f ;
V_75 = V_378 >> 3 ;
V_97 = 1 << ( V_378 & 7 ) ;
V_2 -> V_376 [ V_75 ] |= ( T_4 ) V_97 ;
}
for ( V_153 = 0 ; V_153 < V_375 ; V_153 ++ )
F_99 ( V_2 -> V_376 [ V_153 ] , V_2 -> V_4 + V_377 +
V_153 ) ;
}
static void F_184 ( struct V_1 * V_2 , T_4 V_381 )
{
F_165 ( V_2 ) ;
if ( V_381 )
V_2 -> V_209 |= V_322 ;
else
V_2 -> V_209 &= ~ V_322 ;
if ( V_2 -> V_213 )
F_164 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 , T_4 V_382 )
{
F_165 ( V_2 ) ;
if ( V_382 )
V_2 -> V_209 |= V_324 ;
else
V_2 -> V_209 &= ~ V_324 ;
if ( V_2 -> V_213 )
F_164 ( V_2 ) ;
}
static void F_186 ( struct V_1 * V_2 , int V_256 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_383 ; V_66 ++ ) {
if ( V_2 -> V_384 > 1 ) {
F_98 ( V_2 , V_66 ,
V_174 | ( 1 << V_66 ) ) ;
F_103 ( V_2 , V_66 , V_162 ) ;
} else {
F_98 ( V_2 , V_66 , V_151 ) ;
F_103 ( V_2 , V_66 , V_166 ) ;
}
}
if ( V_2 -> V_384 > 1 )
F_103 ( V_2 , V_383 , V_168 ) ;
else
F_103 ( V_2 , V_383 , V_166 ) ;
if ( V_256 )
V_256 = V_385 ;
F_24 ( V_256 , V_2 -> V_4 + V_298 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
int V_66 ;
F_102 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 , V_386 ) ;
for ( V_66 = 0 ; V_66 < V_383 ; V_66 ++ )
F_50 ( V_2 , V_66 ) ;
F_95 ( V_2 ) ;
F_76 ( V_2 ) ;
F_54 ( V_2 ) ;
F_97 ( V_2 ) ;
if ( V_2 -> V_225 & V_387 )
F_105 ( V_2 ) ;
if ( ! F_43 ( V_2 , V_119 ,
V_388 | V_389 ) )
V_2 -> V_121 |= V_218 ;
F_186 ( V_2 , 1 ) ;
}
static void F_188 ( struct V_390 * V_26 , int time )
{
V_26 -> V_67 = 0 ;
V_26 -> V_391 . V_392 = V_393 + time ;
F_189 ( & V_26 -> V_391 ) ;
V_26 -> V_394 = - 1 ;
}
static void F_190 ( struct V_390 * V_26 )
{
if ( V_26 -> V_394 ) {
V_26 -> V_394 = 0 ;
F_191 ( & V_26 -> V_391 ) ;
}
}
static void F_192 ( struct V_390 * V_26 , int V_395 ,
void (* F_193)( unsigned long ) , void * V_20 )
{
V_26 -> V_394 = 0 ;
V_26 -> V_395 = V_395 ;
F_194 ( & V_26 -> V_391 , F_193 , ( unsigned long ) V_20 ) ;
}
static void F_195 ( struct V_390 * V_26 )
{
++ V_26 -> V_67 ;
if ( V_26 -> V_394 > 0 ) {
if ( V_26 -> V_67 < V_26 -> V_394 ) {
V_26 -> V_391 . V_392 = V_393 + V_26 -> V_395 ;
F_189 ( & V_26 -> V_391 ) ;
} else
V_26 -> V_394 = 0 ;
} else if ( V_26 -> V_394 < 0 ) {
V_26 -> V_391 . V_392 = V_393 + V_26 -> V_395 ;
F_189 ( & V_26 -> V_391 ) ;
}
}
static int F_196 ( struct V_25 * V_328 , int V_329 )
{
V_328 -> V_27 = F_197 ( sizeof( struct V_13 ) * V_328 -> V_327 ,
V_396 ) ;
if ( ! V_328 -> V_27 )
return 1 ;
F_160 ( V_328 , V_329 ) ;
return 0 ;
}
static int F_198 ( struct V_258 * V_397 )
{
struct V_1 * V_2 = & V_397 -> V_2 ;
int V_89 ;
V_397 -> V_398 . V_399 =
V_2 -> V_400 . V_335 * V_2 -> V_400 . V_327 +
V_2 -> V_347 . V_335 * V_2 -> V_347 . V_327 +
V_401 ;
V_397 -> V_398 . V_402 =
F_199 ( V_397 -> V_261 ,
V_397 -> V_398 . V_399 ,
& V_397 -> V_398 . V_403 ) ;
if ( V_397 -> V_398 . V_402 == NULL ) {
V_397 -> V_398 . V_399 = 0 ;
return 1 ;
}
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
if ( F_196 ( & V_2 -> V_400 , 0 ) )
return 1 ;
if ( F_196 ( & V_2 -> V_347 , 1 ) )
return 1 ;
return 0 ;
}
static void F_200 ( struct V_258 * V_397 , struct V_406 * V_407 ,
int V_408 )
{
F_201 ( V_397 -> V_261 , V_407 -> V_409 , V_407 -> V_33 , V_408 ) ;
F_202 ( V_407 -> V_410 ) ;
V_407 -> V_410 = NULL ;
V_407 -> V_409 = 0 ;
}
static void F_203 ( struct V_258 * V_397 )
{
int V_153 ;
struct V_13 * V_14 ;
struct V_406 * V_407 ;
struct V_1 * V_2 = & V_397 -> V_2 ;
struct V_25 * V_26 = & V_2 -> V_400 ;
for ( V_153 = 0 ; V_153 < V_2 -> V_400 . V_327 ; V_153 ++ ) {
F_17 ( V_26 , & V_14 ) ;
V_407 = F_204 ( V_14 ) ;
if ( V_407 -> V_410 && V_407 -> V_33 != V_397 -> V_411 )
F_200 ( V_397 , V_407 , V_412 ) ;
V_407 -> V_33 = V_397 -> V_411 ;
if ( ! V_407 -> V_410 )
V_407 -> V_410 = F_205 ( V_407 -> V_33 , V_413 ) ;
if ( V_407 -> V_410 && ! V_407 -> V_409 )
V_407 -> V_409 = F_206 (
V_397 -> V_261 ,
F_207 ( V_407 -> V_410 ) ,
V_407 -> V_33 ,
V_412 ) ;
F_18 ( V_14 , V_407 -> V_409 ) ;
F_19 ( V_14 , V_407 -> V_33 ) ;
F_16 ( V_14 ) ;
}
}
static int F_208 ( struct V_258 * V_397 )
{
struct V_1 * V_2 = & V_397 -> V_2 ;
V_2 -> V_400 . V_327 = V_414 ;
V_2 -> V_347 . V_327 = V_415 ;
V_2 -> V_349 = 0 ;
V_2 -> V_352 = V_415 / 4 ;
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
F_159 ( L_2 ) ;
F_157 ( & V_2 -> V_400 ) ;
F_157 ( & V_2 -> V_347 ) ;
if ( F_198 ( V_397 ) )
return 1 ;
return 0 ;
}
static void F_209 ( struct V_258 * V_397 )
{
struct V_1 * V_2 = & V_397 -> V_2 ;
V_2 -> V_400 . V_333 = NULL ;
V_2 -> V_347 . V_333 = NULL ;
V_2 -> V_400 . V_331 = 0 ;
V_2 -> V_347 . V_331 = 0 ;
if ( V_397 -> V_398 . V_402 )
F_210 (
V_397 -> V_261 ,
V_397 -> V_398 . V_399 ,
V_397 -> V_398 . V_402 ,
V_397 -> V_398 . V_403 ) ;
V_397 -> V_398 . V_399 = 0 ;
V_397 -> V_398 . V_402 = NULL ;
F_211 ( V_2 -> V_400 . V_27 ) ;
V_2 -> V_400 . V_27 = NULL ;
F_211 ( V_2 -> V_347 . V_27 ) ;
V_2 -> V_347 . V_27 = NULL ;
}
static void F_212 ( struct V_258 * V_397 ,
struct V_25 * V_328 , int V_408 )
{
int V_153 ;
struct V_406 * V_407 ;
struct V_13 * V_14 = V_328 -> V_27 ;
for ( V_153 = 0 ; V_153 < V_328 -> V_327 ; V_153 ++ ) {
V_407 = F_204 ( V_14 ) ;
if ( V_407 -> V_410 )
F_200 ( V_397 , V_407 , V_408 ) ;
V_14 ++ ;
}
}
static void F_213 ( struct V_258 * V_397 )
{
F_212 ( V_397 , & V_397 -> V_2 . V_347 ,
V_416 ) ;
F_212 ( V_397 , & V_397 -> V_2 . V_400 ,
V_412 ) ;
F_209 ( V_397 ) ;
}
static void F_214 ( struct V_1 * V_2 , int V_417 , int V_67 ,
T_5 * V_85 )
{
int V_153 ;
int V_81 ;
int V_66 ;
struct V_80 * V_82 ;
memset ( V_85 , 0 , sizeof( T_5 ) * V_88 ) ;
for ( V_153 = 0 , V_66 = V_417 ; V_153 < V_67 ; V_153 ++ , V_66 ++ ) {
V_82 = & V_2 -> V_82 [ V_66 ] ;
for ( V_81 = V_82 -> V_83 ; V_81 < V_2 -> V_86 ; V_81 ++ )
V_85 [ V_81 ] += V_82 -> V_85 [ V_81 ] ;
}
}
static void F_215 ( struct V_418 * V_410 , struct V_419 * V_420 )
{
struct V_13 * V_14 ;
struct V_13 * V_417 ;
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_25 * V_26 = & V_2 -> V_347 ;
struct V_406 * V_407 ;
int V_33 ;
int V_423 = F_217 ( V_410 ) -> V_424 ;
if ( V_2 -> V_384 > 1 )
V_2 -> V_356 = 1 << V_422 -> V_66 . V_231 ;
V_33 = V_410 -> V_33 ;
V_417 = V_26 -> V_74 ;
V_14 = V_417 ;
V_407 = F_204 ( V_14 ) ;
if ( V_423 ) {
int V_425 ;
T_6 * V_426 ;
V_407 -> V_33 = F_218 ( V_410 ) ;
V_407 -> V_409 = F_206 (
V_259 -> V_261 , V_410 -> V_20 , V_407 -> V_33 ,
V_416 ) ;
F_21 ( V_14 , V_407 -> V_409 ) ;
F_22 ( V_14 , V_407 -> V_33 ) ;
V_425 = 0 ;
do {
V_426 = & F_217 ( V_410 ) -> V_427 [ V_425 ] ;
F_20 ( V_26 , & V_14 ) ;
++ V_2 -> V_349 ;
V_407 = F_204 ( V_14 ) ;
V_407 -> V_33 = F_219 ( V_426 ) ;
V_407 -> V_409 = F_206 (
V_259 -> V_261 ,
F_220 ( V_426 ) ,
V_407 -> V_33 ,
V_416 ) ;
F_21 ( V_14 , V_407 -> V_409 ) ;
F_22 ( V_14 , V_407 -> V_33 ) ;
V_425 ++ ;
if ( V_425 == V_423 )
break;
F_16 ( V_14 ) ;
} while ( 1 );
V_26 -> V_74 = V_14 ;
F_16 ( V_417 ) ;
} else {
V_407 -> V_33 = V_33 ;
V_407 -> V_409 = F_206 (
V_259 -> V_261 , V_410 -> V_20 , V_407 -> V_33 ,
V_416 ) ;
F_21 ( V_14 , V_407 -> V_409 ) ;
F_22 ( V_14 , V_407 -> V_33 ) ;
}
if ( V_410 -> V_428 == V_429 ) {
( V_14 ) -> V_21 . V_24 . V_22 . V_430 = 1 ;
( V_14 ) -> V_21 . V_24 . V_22 . V_431 = 1 ;
}
V_407 -> V_410 = V_410 ;
F_171 ( V_2 ) ;
V_420 -> V_432 . V_433 ++ ;
V_420 -> V_432 . V_434 += V_33 ;
}
static void F_221 ( struct V_258 * V_259 , int V_435 )
{
int V_28 ;
union V_15 V_12 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_25 * V_26 = & V_2 -> V_347 ;
struct V_13 * V_14 ;
struct V_406 * V_407 ;
struct V_419 * V_420 = NULL ;
F_222 ( & V_259 -> V_436 ) ;
V_28 = V_26 -> V_28 ;
while ( V_26 -> V_30 < V_26 -> V_327 ) {
V_14 = & V_26 -> V_27 [ V_28 ] ;
V_12 . V_20 = F_223 ( V_14 -> V_18 -> V_19 . V_20 ) ;
if ( V_12 . V_22 . V_17 ) {
if ( V_435 )
break;
else
F_14 ( V_14 , V_12 ) ;
}
V_407 = F_204 ( V_14 ) ;
F_201 (
V_259 -> V_261 , V_407 -> V_409 , V_407 -> V_33 ,
V_416 ) ;
if ( V_407 -> V_410 ) {
V_420 = V_407 -> V_410 -> V_420 ;
F_224 ( V_407 -> V_410 ) ;
V_407 -> V_410 = NULL ;
}
V_28 ++ ;
V_28 &= V_26 -> V_29 ;
V_26 -> V_30 ++ ;
}
V_26 -> V_28 = V_28 ;
F_225 ( & V_259 -> V_436 ) ;
if ( V_420 )
V_420 -> V_437 = V_393 ;
}
static void F_226 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_66 ;
F_221 ( V_259 , 1 ) ;
for ( V_66 = 0 ; V_66 < V_2 -> V_384 ; V_66 ++ ) {
struct V_419 * V_420 = V_2 -> V_233 [ V_66 ] . V_261 ;
if ( F_227 ( V_420 ) && F_228 ( V_420 ) )
F_229 ( V_420 ) ;
}
}
static inline void F_230 ( struct V_418 * V_438 , struct V_418 * V_410 )
{
V_410 -> V_420 = V_438 -> V_420 ;
V_410 -> V_439 = V_438 -> V_439 ;
V_410 -> V_428 = V_438 -> V_428 ;
V_410 -> V_440 = V_438 -> V_440 ;
F_231 ( V_410 , V_441 ) ;
F_232 ( V_438 ) ;
}
static T_7 F_233 ( struct V_418 * V_410 , struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_442 ;
int V_103 = 1 ;
int V_294 = 0 ;
if ( V_2 -> V_225 & V_304 ) {
struct V_418 * V_443 = V_410 ;
if ( V_410 -> V_33 <= 48 ) {
if ( F_234 ( V_410 ) - V_410 -> V_20 >= 50 ) {
memset ( & V_410 -> V_20 [ V_410 -> V_33 ] , 0 , 50 - V_410 -> V_33 ) ;
V_410 -> V_33 = 50 ;
} else {
V_410 = F_235 ( V_420 , 50 ) ;
if ( ! V_410 )
return V_444 ;
memcpy ( V_410 -> V_20 , V_443 -> V_20 , V_443 -> V_33 ) ;
memset ( & V_410 -> V_20 [ V_443 -> V_33 ] , 0 ,
50 - V_443 -> V_33 ) ;
V_410 -> V_33 = 50 ;
F_230 ( V_443 , V_410 ) ;
}
}
}
F_222 ( & V_259 -> V_436 ) ;
V_103 = F_217 ( V_410 ) -> V_424 + 1 ;
V_442 = F_170 ( V_2 , V_410 -> V_33 , V_103 ) ;
if ( V_442 ) {
if ( V_442 < V_103 ||
( V_429 == V_410 -> V_428 &&
V_410 -> V_439 == F_236 ( V_445 ) ) ) {
struct V_418 * V_443 = V_410 ;
V_410 = F_235 ( V_420 , V_443 -> V_33 ) ;
if ( ! V_410 ) {
V_294 = V_444 ;
goto V_446;
}
F_237 ( V_443 , V_410 -> V_20 ) ;
V_443 -> V_428 = V_447 ;
V_410 -> V_33 = V_443 -> V_33 ;
F_230 ( V_443 , V_410 ) ;
}
F_215 ( V_410 , V_420 ) ;
if ( V_442 <= V_103 )
F_238 ( V_420 ) ;
} else {
F_238 ( V_420 ) ;
V_294 = V_444 ;
}
V_446:
F_225 ( & V_259 -> V_436 ) ;
return V_294 ;
}
static void F_239 ( struct V_419 * V_420 )
{
static unsigned long V_448 ;
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_66 ;
if ( V_2 -> V_384 > 1 ) {
if ( F_240 ( V_393 , V_448 + V_420 -> V_449 ) )
V_259 = NULL ;
}
V_448 = V_393 ;
if ( V_259 ) {
F_3 ( V_2 ) ;
F_168 ( V_2 ) ;
F_221 ( V_259 , 0 ) ;
F_162 ( & V_2 -> V_400 ) ;
F_162 ( & V_2 -> V_347 ) ;
F_203 ( V_259 ) ;
F_154 ( V_2 ) ;
F_161 ( V_2 ,
V_2 -> V_347 . V_331 ,
V_2 -> V_400 . V_331 ) ;
F_173 ( V_2 ) ;
if ( V_2 -> V_321 )
F_184 ( V_2 , V_2 -> V_321 ) ;
else if ( V_2 -> V_379 )
F_183 ( V_2 ) ;
if ( V_2 -> V_384 > 1 ) {
F_177 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_383 ; V_66 ++ ) {
struct V_419 * V_450 ;
F_103 ( V_2 , V_66 ,
V_162 ) ;
V_450 = V_2 -> V_233 [ V_66 ] . V_261 ;
if ( F_227 ( V_450 ) )
F_103 ( V_2 , V_66 ,
V_168 ) ;
}
}
F_169 ( V_2 ) ;
F_6 ( V_2 ) ;
}
V_420 -> V_437 = V_393 ;
F_229 ( V_420 ) ;
}
static inline void F_241 ( struct V_418 * V_410 )
{
unsigned short V_439 ;
struct V_451 * V_452 ;
V_439 = V_410 -> V_439 ;
F_242 ( V_410 ) ;
V_452 = (struct V_451 * ) F_243 ( V_410 ) ;
if ( V_439 == F_236 ( V_453 ) ) {
V_439 = V_452 -> V_454 ;
F_231 ( V_410 , V_455 ) ;
V_452 = (struct V_451 * ) F_243 ( V_410 ) ;
}
if ( V_439 == F_236 ( V_456 ) ) {
if ( V_452 -> V_439 == V_457 )
V_410 -> V_428 = V_458 ;
}
}
static inline int F_244 ( struct V_419 * V_420 , struct V_1 * V_2 ,
struct V_13 * V_14 , union V_15 V_12 )
{
int V_459 ;
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_406 * V_407 ;
struct V_418 * V_410 ;
int V_460 ;
V_459 = V_12 . V_16 . V_461 - 4 ;
V_407 = F_204 ( V_14 ) ;
F_245 (
V_259 -> V_261 , V_407 -> V_409 , V_459 + 4 ,
V_412 ) ;
do {
V_410 = F_235 ( V_420 , V_459 + 2 ) ;
if ( ! V_410 ) {
V_420 -> V_432 . V_462 ++ ;
return - V_463 ;
}
F_246 ( V_410 , 2 ) ;
memcpy ( F_247 ( V_410 , V_459 ) ,
V_407 -> V_410 -> V_20 , V_459 ) ;
} while ( 0 );
V_410 -> V_439 = F_248 ( V_410 , V_420 ) ;
if ( V_2 -> V_209 & ( V_464 | V_319 ) )
F_241 ( V_410 ) ;
V_420 -> V_432 . V_465 ++ ;
V_420 -> V_432 . V_466 += V_459 ;
V_460 = F_249 ( V_410 ) ;
return 0 ;
}
static int F_250 ( struct V_258 * V_259 )
{
int V_34 ;
union V_15 V_12 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_419 * V_420 = V_2 -> V_233 [ 0 ] . V_261 ;
struct V_25 * V_26 = & V_2 -> V_400 ;
int V_442 = V_26 -> V_327 ;
struct V_13 * V_14 ;
int V_467 = 0 ;
V_34 = V_26 -> V_34 ;
while ( V_442 -- ) {
V_14 = & V_26 -> V_27 [ V_34 ] ;
V_12 . V_20 = F_223 ( V_14 -> V_18 -> V_19 . V_20 ) ;
if ( V_12 . V_16 . V_17 )
break;
if ( V_12 . V_16 . V_468 && V_12 . V_16 . V_469 ) {
if ( F_244 ( V_420 , V_2 , V_14 , V_12 ) )
goto V_470;
V_467 ++ ;
}
V_470:
F_16 ( V_14 ) ;
V_34 ++ ;
V_34 &= V_26 -> V_29 ;
}
V_26 -> V_34 = V_34 ;
return V_467 ;
}
static int F_251 ( struct V_258 * V_259 )
{
int V_34 ;
union V_15 V_12 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_419 * V_420 = V_2 -> V_233 [ 0 ] . V_261 ;
struct V_25 * V_26 = & V_2 -> V_400 ;
int V_442 = V_26 -> V_327 ;
struct V_13 * V_14 ;
int V_467 = 0 ;
V_34 = V_26 -> V_34 ;
while ( V_442 -- ) {
V_14 = & V_26 -> V_27 [ V_34 ] ;
V_12 . V_20 = F_223 ( V_14 -> V_18 -> V_19 . V_20 ) ;
if ( V_12 . V_16 . V_17 )
break;
if ( V_2 -> V_384 > 1 ) {
int V_93 = F_252 ( V_12 . V_16 . V_471 ) ;
V_420 = V_2 -> V_233 [ V_93 ] . V_261 ;
if ( ! F_227 ( V_420 ) )
goto V_470;
}
if ( V_12 . V_16 . V_468 && V_12 . V_16 . V_469 ) {
if ( F_244 ( V_420 , V_2 , V_14 , V_12 ) )
goto V_470;
V_467 ++ ;
}
V_470:
F_16 ( V_14 ) ;
V_34 ++ ;
V_34 &= V_26 -> V_29 ;
}
V_26 -> V_34 = V_34 ;
return V_467 ;
}
static int F_253 ( struct V_258 * V_259 )
{
int V_34 ;
union V_15 V_12 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_419 * V_420 = V_2 -> V_233 [ 0 ] . V_261 ;
struct V_25 * V_26 = & V_2 -> V_400 ;
int V_442 = V_26 -> V_327 ;
struct V_13 * V_14 ;
int V_467 = 0 ;
V_34 = V_26 -> V_34 ;
while ( V_442 -- ) {
V_14 = & V_26 -> V_27 [ V_34 ] ;
V_12 . V_20 = F_223 ( V_14 -> V_18 -> V_19 . V_20 ) ;
if ( V_12 . V_16 . V_17 )
break;
if ( V_2 -> V_384 > 1 ) {
int V_93 = F_252 ( V_12 . V_16 . V_471 ) ;
V_420 = V_2 -> V_233 [ V_93 ] . V_261 ;
if ( ! F_227 ( V_420 ) )
goto V_470;
}
if ( V_12 . V_16 . V_468 && V_12 . V_16 . V_469 ) {
if ( ! V_12 . V_16 . error || ( V_12 . V_20 &
V_472 ) ==
V_473 ) {
if ( F_244 ( V_420 , V_2 , V_14 , V_12 ) )
goto V_470;
V_467 ++ ;
} else {
struct V_421 * V_422 = F_216 ( V_420 ) ;
V_422 -> V_66 . V_85 [ V_474 ] ++ ;
}
}
V_470:
F_16 ( V_14 ) ;
V_34 ++ ;
V_34 &= V_26 -> V_29 ;
}
V_26 -> V_34 = V_34 ;
return V_467 ;
}
static void F_254 ( unsigned long V_20 )
{
struct V_258 * V_259 = (struct V_258 * ) V_20 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
if ( ! V_2 -> V_213 )
return;
if ( F_255 ( ! V_259 -> V_475 ( V_259 ) ) ) {
F_163 ( V_2 ) ;
F_222 ( & V_259 -> V_436 ) ;
F_9 ( V_2 , V_476 ) ;
F_225 ( & V_259 -> V_436 ) ;
} else {
F_1 ( V_2 , V_477 ) ;
F_256 ( & V_259 -> V_478 ) ;
}
}
static void F_257 ( unsigned long V_20 )
{
struct V_258 * V_259 = (struct V_258 * ) V_20 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
F_1 ( V_2 , V_479 ) ;
F_226 ( V_259 ) ;
F_222 ( & V_259 -> V_436 ) ;
F_9 ( V_2 , V_480 ) ;
F_225 ( & V_259 -> V_436 ) ;
}
static inline void F_258 ( struct V_1 * V_2 )
{
if ( 0 == V_2 -> V_344 )
V_2 -> V_7 &= ~ V_343 ;
else if ( V_2 -> V_344 > 1 ) {
if ( V_2 -> V_213 && ( V_2 -> V_209 & V_317 ) ) {
F_164 ( V_2 ) ;
} else {
V_2 -> V_7 &= ~ V_343 ;
V_2 -> V_344 = 0 ;
}
} else
V_2 -> V_344 ++ ;
}
static T_8 F_259 ( int V_481 , void * V_482 )
{
T_1 V_483 = 0 ;
struct V_419 * V_420 = (struct V_419 * ) V_482 ;
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
F_260 ( & V_259 -> V_436 ) ;
F_11 ( V_2 , & V_483 ) ;
if ( ! V_483 ) {
F_261 ( & V_259 -> V_436 ) ;
return V_484 ;
}
do {
F_1 ( V_2 , V_483 ) ;
V_483 &= V_2 -> V_7 ;
if ( F_255 ( V_483 & V_479 ) ) {
F_7 ( V_2 , V_479 ) ;
F_256 ( & V_259 -> V_485 ) ;
}
if ( F_262 ( V_483 & V_477 ) ) {
F_7 ( V_2 , V_477 ) ;
F_256 ( & V_259 -> V_478 ) ;
}
if ( F_255 ( V_483 & V_326 ) ) {
V_420 -> V_432 . V_486 ++ ;
F_163 ( V_2 ) ;
}
if ( F_255 ( V_483 & V_487 ) ) {
struct V_203 * V_66 = & V_422 -> V_66 ;
V_2 -> V_225 |= V_488 ;
F_135 ( V_66 ) ;
}
if ( F_255 ( V_483 & V_343 ) ) {
F_258 ( V_2 ) ;
break;
}
if ( F_255 ( V_483 & V_489 ) ) {
T_2 V_20 ;
V_2 -> V_7 &= ~ V_489 ;
F_263 ( L_3 ) ;
V_20 = F_4 ( V_2 -> V_4 + V_215 ) ;
if ( ! ( V_20 & V_314 ) )
F_263 ( L_4 ) ;
break;
}
} while ( 0 );
F_6 ( V_2 ) ;
F_261 ( & V_259 -> V_436 ) ;
return V_490 ;
}
static void F_264 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
F_3 ( & V_259 -> V_2 ) ;
F_259 ( V_420 -> V_481 , V_420 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
int V_66 ;
T_4 V_58 ;
struct V_104 * V_21 = V_2 -> V_104 ;
if ( ! V_21 -> V_58 ) {
F_103 ( V_2 , V_383 , V_168 ) ;
F_106 ( V_2 ) ;
}
for ( V_66 = 0 ; V_66 < V_383 ; V_66 ++ ) {
if ( V_166 == V_21 -> F_36 [ V_66 ] . V_169 )
V_58 = V_174 | V_21 -> V_58 ;
else
V_58 = V_174 | ( 1 << V_66 ) ;
if ( V_58 != V_21 -> F_36 [ V_66 ] . V_58 )
F_98 ( V_2 , V_66 , V_58 ) ;
}
}
static int F_266 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_491 ;
F_238 ( V_420 ) ;
F_190 ( & V_422 -> V_492 ) ;
if ( V_2 -> V_384 > 1 ) {
F_103 ( V_2 , V_66 -> V_231 , V_162 ) ;
if ( V_2 -> V_225 & V_387 ) {
V_491 = 1 << V_66 -> V_231 ;
if ( V_2 -> V_104 -> V_58 & V_491 ) {
V_2 -> V_104 -> V_58 &= ~ V_491 ;
F_265 ( V_2 ) ;
}
}
}
if ( V_66 -> V_231 > 0 )
F_180 ( V_2 , V_420 -> V_493 ) ;
if ( ! V_259 -> V_282 )
F_138 ( V_66 , true ) ;
if ( V_422 -> V_381 )
-- V_2 -> V_321 ;
if ( V_422 -> V_323 )
-- V_2 -> V_323 ;
V_259 -> V_494 -- ;
if ( ! ( V_259 -> V_494 ) ) {
F_190 ( & V_259 -> V_495 ) ;
F_267 ( & V_259 -> V_496 ) ;
F_3 ( V_2 ) ;
F_168 ( V_2 ) ;
F_182 ( V_2 ) ;
F_268 ( 2000 / V_497 ) ;
F_269 ( & V_259 -> V_478 ) ;
F_269 ( & V_259 -> V_485 ) ;
F_270 ( V_420 -> V_481 , V_259 -> V_420 ) ;
F_221 ( V_259 , 0 ) ;
F_162 ( & V_2 -> V_400 ) ;
F_162 ( & V_2 -> V_347 ) ;
if ( V_2 -> V_225 & V_387 )
F_104 ( V_2 ) ;
}
return 0 ;
}
static void F_271 ( struct V_258 * V_259 , struct V_1 * V_2 )
{
if ( V_2 -> V_104 ) {
T_2 V_20 ;
V_20 = F_35 ( V_2 -> V_4 + V_107 ) ;
if ( V_2 -> V_225 & V_498 )
V_20 |= V_499 ;
else
V_20 &= ~ V_499 ;
F_24 ( V_20 , V_2 -> V_4 + V_107 ) ;
}
if ( V_2 -> V_225 & V_498 ) {
V_2 -> V_209 |= V_500 ;
V_259 -> V_475 = F_253 ;
} else {
V_2 -> V_209 &= ~ V_500 ;
if ( V_2 -> V_384 > 1 )
V_259 -> V_475 = F_251 ;
else
V_259 -> V_475 = F_250 ;
}
}
static int F_272 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_294 = 0 ;
V_259 -> V_420 = V_420 ;
V_294 = F_273 ( V_420 -> V_481 , F_259 , V_501 , V_420 -> V_502 , V_420 ) ;
if ( V_294 )
return V_294 ;
F_274 ( & V_259 -> V_478 , F_254 ,
( unsigned long ) V_259 ) ;
F_274 ( & V_259 -> V_485 , F_257 ,
( unsigned long ) V_259 ) ;
V_2 -> V_323 = 0 ;
V_2 -> V_321 = 0 ;
V_2 -> V_379 = 0 ;
F_154 ( V_2 ) ;
F_161 ( V_2 ,
V_2 -> V_347 . V_331 , V_2 -> V_400 . V_331 ) ;
F_173 ( V_2 ) ;
F_271 ( V_259 , V_2 ) ;
F_203 ( V_259 ) ;
return 0 ;
}
static void F_275 ( struct V_419 * V_420 , int V_503 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
if ( V_503 == V_422 -> V_503 )
F_276 ( V_420 ) ;
else
F_277 ( V_420 ) ;
F_278 ( V_422 , V_504 , V_420 , L_5 ,
V_503 == V_422 -> V_503 ? L_6 : L_7 ) ;
}
static int F_279 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
int V_153 ;
int V_93 ;
int V_294 = 0 ;
V_422 -> V_381 = 0 ;
V_422 -> V_323 = 0 ;
memset ( & V_420 -> V_432 , 0 , sizeof( struct V_505 ) ) ;
memset ( ( void * ) V_66 -> V_85 , 0 ,
( sizeof( T_5 ) * V_506 ) ) ;
if ( ! ( V_259 -> V_494 ) ) {
V_294 = F_272 ( V_420 ) ;
if ( V_294 )
return V_294 ;
for ( V_153 = 0 ; V_153 < V_2 -> V_507 ; V_153 ++ ) {
if ( V_508 < V_393 )
V_508 = V_393 + V_497 * 2 ;
else
V_508 += V_497 * 1 ;
V_259 -> V_85 [ V_153 ] . time = V_508 ;
V_2 -> V_82 [ V_153 ] . V_161 = V_244 ;
F_32 ( V_2 , V_153 ) ;
}
if ( V_2 -> V_104 )
V_2 -> V_82 [ V_509 ] . V_161 = V_243 ;
else {
F_149 ( V_2 ) ;
F_144 ( V_2 , 0 ) ;
F_142 ( & V_259 -> V_2 ) ;
}
}
F_138 ( V_66 , false ) ;
for ( V_153 = 0 , V_93 = V_66 -> V_231 ; V_153 < V_66 -> V_232 ; V_153 ++ , V_93 ++ ) {
V_2 -> V_233 [ V_93 ] . V_239 = 0xFF ;
V_2 -> V_233 [ V_93 ] . V_161 = V_244 ;
}
if ( V_2 -> V_384 > 1 ) {
F_103 ( V_2 , V_66 -> V_231 , V_168 ) ;
if ( V_66 -> V_231 > 0 )
F_178 ( V_2 , V_420 -> V_493 ) ;
}
F_135 ( V_66 ) ;
if ( V_66 -> V_219 )
F_137 ( V_66 ) ;
else
F_136 ( V_66 ) ;
if ( ! ( V_259 -> V_494 ) ) {
F_156 ( V_2 ) ;
F_169 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_507 )
F_188 ( & V_259 -> V_495 ,
V_259 -> V_495 . V_395 ) ;
}
V_259 -> V_494 ++ ;
F_188 ( & V_422 -> V_492 ,
V_422 -> V_492 . V_395 ) ;
V_422 -> V_503 = V_66 -> V_229 -> V_161 ;
F_275 ( V_420 , V_243 ) ;
F_280 ( V_420 ) ;
return 0 ;
}
static struct V_505 * F_281 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_203 * V_66 = & V_422 -> V_66 ;
struct V_1 * V_2 = & V_422 -> V_397 -> V_2 ;
struct V_80 * V_81 ;
int V_153 ;
int V_93 ;
V_420 -> V_432 . V_510 = V_66 -> V_85 [ V_474 ] ;
V_420 -> V_432 . V_511 = V_66 -> V_85 [ V_512 ] ;
V_420 -> V_432 . V_381 = 0 ;
V_420 -> V_432 . V_513 = 0 ;
V_420 -> V_432 . V_514 = 0 ;
V_420 -> V_432 . V_515 = 0 ;
V_420 -> V_432 . V_516 = 0 ;
V_420 -> V_432 . V_517 = 0 ;
for ( V_153 = 0 , V_93 = V_66 -> V_231 ; V_153 < V_66 -> V_507 ; V_153 ++ , V_93 ++ ) {
V_81 = & V_2 -> V_82 [ V_93 ] ;
V_420 -> V_432 . V_381 += ( unsigned long )
V_81 -> V_85 [ V_518 ] ;
V_420 -> V_432 . V_513 += ( unsigned long )
V_81 -> V_85 [ V_519 ] ;
V_420 -> V_432 . V_514 += ( unsigned long ) (
V_81 -> V_85 [ V_520 ] +
V_81 -> V_85 [ V_521 ] +
V_81 -> V_85 [ V_522 ] +
V_81 -> V_85 [ V_523 ] ) ;
V_420 -> V_432 . V_515 += ( unsigned long )
V_81 -> V_85 [ V_524 ] ;
V_420 -> V_432 . V_516 += ( unsigned long ) (
V_81 -> V_85 [ V_525 ] +
V_81 -> V_85 [ V_526 ] ) ;
V_420 -> V_432 . V_517 += ( unsigned long )
V_81 -> V_85 [ V_527 ] ;
}
return & V_420 -> V_432 ;
}
static int F_282 ( struct V_419 * V_420 , void * V_32 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_528 * V_529 = V_32 ;
T_1 V_3 ;
if ( V_422 -> V_66 . V_231 > 0 )
F_180 ( V_2 , V_420 -> V_493 ) ;
else {
V_2 -> V_362 = 1 ;
memcpy ( V_2 -> V_281 , V_529 -> V_530 , V_280 ) ;
}
memcpy ( V_420 -> V_493 , V_529 -> V_530 , V_280 ) ;
V_3 = F_13 ( V_2 ) ;
if ( V_422 -> V_66 . V_231 > 0 )
F_178 ( V_2 , V_420 -> V_493 ) ;
else
F_173 ( V_2 ) ;
F_12 ( V_2 , V_3 ) ;
return 0 ;
}
static void F_283 ( struct V_419 * V_420 , struct V_421 * V_422 ,
struct V_1 * V_2 , int V_323 )
{
if ( V_323 != V_422 -> V_323 ) {
T_4 V_531 = V_2 -> V_323 ;
if ( V_323 )
++ V_2 -> V_323 ;
else
-- V_2 -> V_323 ;
V_422 -> V_323 = V_323 ;
if ( V_2 -> V_323 <= 1 && V_531 <= 1 )
F_185 ( V_2 , V_2 -> V_323 ) ;
if ( ( V_2 -> V_225 & V_387 ) && ! V_323 &&
( V_420 -> V_532 & V_533 ) ) {
struct V_104 * V_21 = V_2 -> V_104 ;
int V_66 = V_422 -> V_66 . V_231 ;
F_103 ( V_2 , V_66 , V_162 ) ;
V_66 = 1 << V_66 ;
if ( V_21 -> V_58 & V_66 ) {
V_21 -> V_58 &= ~ V_66 ;
F_265 ( V_2 ) ;
}
}
}
}
static void F_284 ( struct V_421 * V_422 , struct V_1 * V_2 ,
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
F_184 ( V_2 , V_2 -> V_321 ) ;
}
}
static void F_285 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_534 * V_535 ;
int V_381 = ( V_420 -> V_536 & V_537 ) ;
F_283 ( V_420 , V_422 , V_2 , ( V_420 -> V_536 & V_538 ) ) ;
if ( V_259 -> V_2 . V_384 > 1 )
V_381 |= ( V_420 -> V_536 & V_539 ) ;
F_284 ( V_422 , V_2 , V_381 ) ;
if ( V_259 -> V_2 . V_384 > 1 )
return;
if ( ( V_420 -> V_536 & V_539 ) && ! F_286 ( V_420 ) ) {
int V_153 = 0 ;
if ( F_287 ( V_420 ) > V_540 ) {
if ( V_540 != V_2 -> V_379 ) {
V_2 -> V_379 = V_540 ;
++ V_2 -> V_321 ;
F_184 ( V_2 , V_2 -> V_321 ) ;
}
return;
}
F_288 (ha, dev) {
if ( V_153 >= V_540 )
break;
memcpy ( V_2 -> V_380 [ V_153 ++ ] , V_535 -> V_32 , V_280 ) ;
}
V_2 -> V_379 = ( T_4 ) V_153 ;
F_183 ( V_2 ) ;
} else {
if ( V_540 == V_2 -> V_379 ) {
-- V_2 -> V_321 ;
F_184 ( V_2 , V_2 -> V_321 ) ;
}
V_2 -> V_379 = 0 ;
F_182 ( V_2 ) ;
}
}
static int F_289 ( struct V_419 * V_420 , int V_541 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int V_542 ;
if ( F_227 ( V_420 ) )
return - V_543 ;
if ( V_2 -> V_384 > 1 )
if ( V_420 != V_259 -> V_420 )
return 0 ;
if ( V_541 < 60 )
return - V_544 ;
if ( V_420 -> V_411 != V_541 ) {
V_542 = V_541 + V_545 + 4 ;
if ( V_542 > V_546 )
return - V_544 ;
if ( V_542 > V_547 ) {
V_2 -> V_225 |= V_498 ;
V_542 = V_546 ;
} else {
V_2 -> V_225 &= ~ V_498 ;
V_542 = V_547 ;
}
V_542 = ( V_542 + 3 ) & ~ 3 ;
V_259 -> V_411 = V_542 ;
V_420 -> V_411 = V_541 ;
}
return 0 ;
}
static int F_290 ( struct V_419 * V_420 , struct V_548 * V_549 , int V_550 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
int V_551 = 0 ;
struct V_552 * V_20 = F_291 ( V_549 ) ;
if ( F_292 ( & V_422 -> V_553 ) )
return - V_554 ;
switch ( V_550 ) {
case V_555 :
V_20 -> V_556 = V_422 -> V_364 ;
case V_557 :
if ( V_20 -> V_556 != V_422 -> V_364 || V_20 -> V_558 >= 6 )
V_551 = - V_559 ;
else
F_119 ( V_2 , V_66 -> V_229 -> V_560 , V_20 -> V_558 ,
& V_20 -> V_561 ) ;
break;
case V_562 :
if ( ! F_293 ( V_563 ) )
V_551 = - V_564 ;
else if ( V_20 -> V_556 != V_422 -> V_364 || V_20 -> V_558 >= 6 )
V_551 = - V_559 ;
else
F_120 ( V_2 , V_66 -> V_229 -> V_560 , V_20 -> V_558 ,
V_20 -> V_565 ) ;
break;
default:
V_551 = - V_566 ;
}
F_294 ( & V_422 -> V_553 ) ;
return V_551 ;
}
static int F_295 ( struct V_419 * V_420 , int V_556 , int V_558 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_203 * V_66 = & V_422 -> V_66 ;
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_561 ;
F_119 ( V_2 , V_66 -> V_229 -> V_560 , V_558 << 1 , & V_561 ) ;
return V_561 ;
}
static void F_296 ( struct V_419 * V_420 , int V_556 , int V_558 , int V_185 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_203 * V_66 = & V_422 -> V_66 ;
struct V_1 * V_2 = V_66 -> V_2 ;
int V_153 ;
int V_491 ;
for ( V_153 = 0 , V_491 = V_66 -> V_231 ; V_153 < V_66 -> V_232 ; V_153 ++ , V_491 ++ )
F_120 ( V_2 , V_491 , V_558 << 1 , V_185 ) ;
}
static int F_297 ( struct V_419 * V_420 , struct V_567 * V_550 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
F_298 ( & V_259 -> V_568 ) ;
F_299 ( & V_422 -> V_569 , V_550 ) ;
V_550 -> V_570 |= V_571 ;
F_300 ( & V_259 -> V_568 ) ;
V_422 -> V_570 = V_550 -> V_570 ;
return 0 ;
}
static int F_301 ( struct V_419 * V_420 , struct V_567 * V_550 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
T_2 V_251 = F_302 ( V_550 ) ;
int V_294 ;
if ( V_550 -> V_572 && V_422 -> V_570 == V_550 -> V_570 ) {
V_550 -> V_570 |= V_573 ;
if ( 10 == V_251 )
V_550 -> V_570 &=
~ ( V_574 |
V_575 ) ;
else if ( 100 == V_251 )
V_550 -> V_570 &=
~ ( V_576 |
V_577 ) ;
if ( 0 == V_550 -> V_228 )
V_550 -> V_570 &=
~ ( V_574 |
V_576 ) ;
else if ( 1 == V_550 -> V_228 )
V_550 -> V_570 &=
~ ( V_575 |
V_577 ) ;
}
F_298 ( & V_259 -> V_568 ) ;
if ( V_550 -> V_572 &&
( V_550 -> V_570 & V_573 ) ==
V_573 ) {
V_66 -> V_228 = 0 ;
V_66 -> V_251 = 0 ;
V_66 -> V_219 = 0 ;
} else {
V_66 -> V_228 = V_550 -> V_228 + 1 ;
if ( 1000 != V_251 )
V_66 -> V_251 = V_251 ;
if ( V_550 -> V_572 )
V_66 -> V_219 = 0 ;
else
V_66 -> V_219 = 1 ;
}
V_294 = F_303 ( & V_422 -> V_569 , V_550 ) ;
F_300 ( & V_259 -> V_568 ) ;
return V_294 ;
}
static int F_304 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
int V_294 ;
F_298 ( & V_259 -> V_568 ) ;
V_294 = F_305 ( & V_422 -> V_569 ) ;
F_300 ( & V_259 -> V_568 ) ;
return V_294 ;
}
static T_2 F_306 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
int V_294 ;
V_294 = F_307 ( & V_422 -> V_569 ) ;
return V_294 ;
}
static void F_308 ( struct V_419 * V_420 ,
struct V_578 * V_26 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
F_309 ( V_26 -> V_579 , V_580 , sizeof( V_26 -> V_579 ) ) ;
F_309 ( V_26 -> V_581 , V_582 , sizeof( V_26 -> V_581 ) ) ;
F_309 ( V_26 -> V_583 , F_310 ( V_259 -> V_261 ) ,
sizeof( V_26 -> V_583 ) ) ;
}
static int F_311 ( struct V_419 * V_420 )
{
struct V_584 * V_585 = V_586 ;
int V_587 = 0x10 * sizeof( T_2 ) ;
while ( V_585 -> V_588 > V_585 -> V_589 ) {
V_587 += ( V_585 -> V_588 - V_585 -> V_589 + 3 ) / 4 * 4 ;
V_585 ++ ;
}
return V_587 ;
}
static void F_312 ( struct V_419 * V_420 , struct V_590 * V_591 ,
void * V_592 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
int * V_24 = ( int * ) V_592 ;
struct V_584 * V_585 = V_586 ;
int V_33 ;
F_298 ( & V_259 -> V_568 ) ;
V_591 -> V_581 = 0 ;
for ( V_33 = 0 ; V_33 < 0x40 ; V_33 += 4 ) {
F_313 ( V_259 -> V_261 , V_33 , V_24 ) ;
V_24 ++ ;
}
while ( V_585 -> V_588 > V_585 -> V_589 ) {
for ( V_33 = V_585 -> V_589 ; V_33 < V_585 -> V_588 ; V_33 += 4 ) {
* V_24 = F_4 ( V_2 -> V_4 + V_33 ) ;
V_24 ++ ;
}
V_585 ++ ;
}
F_300 ( & V_259 -> V_568 ) ;
}
static void F_314 ( struct V_419 * V_420 ,
struct V_593 * V_594 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
V_594 -> V_595 = V_259 -> V_596 ;
V_594 -> V_597 = V_259 -> V_282 ;
memset ( & V_594 -> V_598 , 0 , sizeof( V_594 -> V_598 ) ) ;
}
static int F_315 ( struct V_419 * V_420 ,
struct V_593 * V_594 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
static const T_4 V_283 [] = { 192 , 168 , 1 , 1 } ;
if ( V_594 -> V_597 & ~ V_259 -> V_596 )
return - V_544 ;
V_259 -> V_282 = V_594 -> V_597 ;
if ( V_594 -> V_597 )
V_259 -> V_282 |= V_599 ;
F_152 ( & V_259 -> V_2 , V_259 -> V_282 , V_283 ) ;
return 0 ;
}
static T_2 F_316 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
return V_422 -> V_600 ;
}
static void F_317 ( struct V_419 * V_420 , T_2 V_97 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
V_422 -> V_600 = V_97 ;
}
static int F_318 ( struct V_419 * V_420 )
{
return V_601 * 2 ;
}
static int F_319 ( struct V_419 * V_420 ,
struct V_602 * V_603 , T_4 * V_20 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
T_4 * V_604 = ( T_4 * ) V_605 ;
int V_153 ;
int V_33 ;
V_33 = ( V_603 -> V_89 + V_603 -> V_33 + 1 ) / 2 ;
for ( V_153 = V_603 -> V_89 / 2 ; V_153 < V_33 ; V_153 ++ )
V_605 [ V_153 ] = F_129 ( & V_259 -> V_2 , V_153 ) ;
V_603 -> V_606 = V_607 ;
memcpy ( V_20 , & V_604 [ V_603 -> V_89 ] , V_603 -> V_33 ) ;
return 0 ;
}
static int F_320 ( struct V_419 * V_420 ,
struct V_602 * V_603 , T_4 * V_20 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
T_3 V_608 [ V_601 ] ;
T_4 * V_604 = ( T_4 * ) V_608 ;
int V_153 ;
int V_33 ;
if ( V_603 -> V_606 != V_607 )
return - V_544 ;
V_33 = ( V_603 -> V_89 + V_603 -> V_33 + 1 ) / 2 ;
for ( V_153 = V_603 -> V_89 / 2 ; V_153 < V_33 ; V_153 ++ )
V_605 [ V_153 ] = F_129 ( & V_259 -> V_2 , V_153 ) ;
memcpy ( V_608 , V_605 , V_601 * 2 ) ;
memcpy ( & V_604 [ V_603 -> V_89 ] , V_20 , V_603 -> V_33 ) ;
for ( V_153 = 0 ; V_153 < V_601 ; V_153 ++ )
if ( V_608 [ V_153 ] != V_605 [ V_153 ] ) {
V_605 [ V_153 ] = V_608 [ V_153 ] ;
F_130 ( & V_259 -> V_2 , V_153 , V_605 [ V_153 ] ) ;
}
return 0 ;
}
static void F_321 ( struct V_419 * V_420 ,
struct V_609 * V_610 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
V_610 -> V_572 = ( V_2 -> V_121 & V_218 ) ? 0 : 1 ;
if ( ! V_2 -> V_104 ) {
V_610 -> V_611 =
( V_2 -> V_209 & V_211 ) ? 1 : 0 ;
V_610 -> V_612 =
( V_2 -> V_210 & V_212 ) ? 1 : 0 ;
} else {
V_610 -> V_611 =
( F_43 ( V_2 , V_119 ,
V_389 ) ) ? 1 : 0 ;
V_610 -> V_612 =
( F_43 ( V_2 , V_119 ,
V_388 ) ) ? 1 : 0 ;
}
}
static int F_322 ( struct V_419 * V_420 ,
struct V_609 * V_610 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
F_298 ( & V_259 -> V_568 ) ;
if ( V_610 -> V_572 ) {
if ( ! V_610 -> V_611 && ! V_610 -> V_612 )
V_66 -> V_205 = V_613 ;
else
V_66 -> V_205 = V_206 ;
V_2 -> V_121 &= ~ V_218 ;
V_66 -> V_219 = 0 ;
if ( V_2 -> V_104 ) {
F_44 ( V_2 , V_119 ,
V_389 , 1 ) ;
F_44 ( V_2 , V_119 ,
V_388 , 1 ) ;
}
F_136 ( V_66 ) ;
} else {
V_2 -> V_121 |= V_218 ;
if ( V_2 -> V_104 ) {
F_44 ( V_2 , V_119 ,
V_389 , V_610 -> V_611 ) ;
F_44 ( V_2 , V_119 ,
V_388 , V_610 -> V_612 ) ;
} else
F_132 ( V_2 , V_610 -> V_611 , V_610 -> V_612 ) ;
}
F_300 ( & V_259 -> V_568 ) ;
return 0 ;
}
static void F_323 ( struct V_419 * V_420 ,
struct V_614 * V_27 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
V_27 -> V_615 = ( 1 << 9 ) ;
V_27 -> V_616 = V_2 -> V_347 . V_327 ;
V_27 -> V_617 = ( 1 << 9 ) ;
V_27 -> V_618 = V_2 -> V_400 . V_327 ;
}
static void F_324 ( struct V_419 * V_420 , T_2 V_619 , T_4 * V_24 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
if ( V_620 == V_619 )
memcpy ( V_24 , & V_621 ,
V_622 * V_2 -> V_86 ) ;
}
static int F_325 ( struct V_419 * V_420 , int V_623 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
switch ( V_623 ) {
case V_620 :
return V_2 -> V_86 ;
default:
return - V_566 ;
}
}
static void F_326 ( struct V_419 * V_420 ,
struct V_624 * V_432 , T_5 * V_20 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
int V_625 = V_432 -> V_625 ;
int V_153 ;
int V_626 ;
int V_93 ;
int V_294 ;
T_5 V_85 [ V_88 ] ;
F_298 ( & V_259 -> V_568 ) ;
V_626 = V_383 ;
for ( V_153 = 0 , V_93 = V_66 -> V_231 ; V_153 < V_66 -> V_507 ; V_153 ++ , V_93 ++ ) {
if ( V_243 == V_2 -> V_82 [ V_93 ] . V_161 ) {
V_259 -> V_85 [ V_93 ] . V_627 = 1 ;
if ( V_626 == V_383 )
V_626 = V_93 ;
}
}
F_300 ( & V_259 -> V_568 ) ;
if ( V_626 < V_383 )
F_327 ( & V_259 -> V_496 ) ;
if ( 1 == V_66 -> V_507 && V_626 < V_383 ) {
V_93 = V_626 ;
V_294 = F_328 (
V_259 -> V_85 [ V_93 ] . V_85 ,
2 == V_259 -> V_85 [ V_93 ] . V_627 ,
V_497 * 1 ) ;
} else
for ( V_153 = 0 , V_93 = V_626 ; V_153 < V_66 -> V_507 - V_626 ; V_153 ++ , V_93 ++ ) {
if ( 0 == V_153 ) {
V_294 = F_328 (
V_259 -> V_85 [ V_93 ] . V_85 ,
2 == V_259 -> V_85 [ V_93 ] . V_627 ,
V_497 * 2 ) ;
} else if ( V_2 -> V_82 [ V_93 ] . V_84 ) {
V_294 = F_328 (
V_259 -> V_85 [ V_93 ] . V_85 ,
2 == V_259 -> V_85 [ V_93 ] . V_627 ,
V_497 * 1 ) ;
}
}
F_214 ( V_2 , V_66 -> V_231 , V_66 -> V_507 , V_85 ) ;
V_626 = V_2 -> V_86 ;
if ( V_626 > V_625 )
V_626 = V_625 ;
V_625 -= V_626 ;
for ( V_153 = 0 ; V_153 < V_626 ; V_153 ++ )
* V_20 ++ = V_85 [ V_153 ] ;
}
static int F_329 ( struct V_419 * V_420 ,
T_9 V_225 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
F_298 ( & V_259 -> V_568 ) ;
if ( V_225 & V_628 )
V_2 -> V_209 |= V_319 | V_320 ;
else
V_2 -> V_209 &= ~ ( V_319 | V_320 ) ;
if ( V_2 -> V_213 )
F_2 ( V_2 -> V_209 , V_2 -> V_4 + V_214 ) ;
F_300 ( & V_259 -> V_568 ) ;
return 0 ;
}
static void F_330 ( struct V_419 * V_420 , struct V_421 * V_422 ,
struct V_203 * V_66 )
{
if ( V_422 -> V_503 != V_66 -> V_229 -> V_161 ) {
V_422 -> V_503 = V_66 -> V_229 -> V_161 ;
if ( F_227 ( V_420 ) )
F_275 ( V_420 , V_243 ) ;
}
}
static void F_331 ( struct V_629 * V_630 )
{
struct V_258 * V_259 =
F_140 ( V_630 , struct V_258 , V_496 ) ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_80 * V_81 ;
int V_153 ;
V_508 = V_393 ;
for ( V_153 = 0 ; V_153 < V_2 -> V_507 ; V_153 ++ ) {
V_81 = & V_2 -> V_82 [ V_153 ] ;
if ( V_81 -> V_84 || 1 == V_259 -> V_85 [ V_153 ] . V_627 ) {
if ( F_31 ( V_2 , V_153 ) )
break;
V_259 -> V_85 [ V_153 ] . V_627 = 0 ;
if ( 0 == V_81 -> V_84 ) {
V_259 -> V_85 [ V_153 ] . V_627 = 2 ;
F_332 (
& V_259 -> V_85 [ V_153 ] . V_85 ) ;
}
} else if ( V_393 >= V_259 -> V_85 [ V_153 ] . time ) {
if ( V_243 == V_81 -> V_161 )
V_259 -> V_85 [ V_153 ] . V_627 = 1 ;
V_508 += V_497 * 1 * V_2 -> V_507 ;
V_259 -> V_85 [ V_153 ] . time = V_508 ;
} else if ( V_81 -> V_245 ) {
V_81 -> V_245 = 0 ;
V_259 -> V_85 [ V_153 ] . V_627 = 1 ;
}
}
}
static void F_333 ( unsigned long V_592 )
{
struct V_258 * V_259 = (struct V_258 * ) V_592 ;
F_331 ( & V_259 -> V_496 ) ;
if ( V_259 -> V_631 ) {
if ( V_259 -> V_631 <= V_393 ) {
F_142 ( & V_259 -> V_2 ) ;
V_259 -> V_631 = 0 ;
}
} else if ( F_139 ( & V_259 -> V_2 ) ) {
V_259 -> V_631 = V_393 + V_497 * 2 ;
}
F_195 ( & V_259 -> V_495 ) ;
}
static void F_334 ( unsigned long V_592 )
{
struct V_419 * V_420 = (struct V_419 * ) V_592 ;
struct V_421 * V_422 = F_216 ( V_420 ) ;
struct V_258 * V_259 = V_422 -> V_397 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
struct V_203 * V_66 = & V_422 -> V_66 ;
if ( ! ( V_2 -> V_225 & V_488 ) )
F_135 ( V_66 ) ;
F_330 ( V_420 , V_422 , V_66 ) ;
F_195 ( & V_422 -> V_492 ) ;
}
static int T_10 F_335 ( struct V_419 * V_420 )
{
struct V_421 * V_422 = F_216 ( V_420 ) ;
F_192 ( & V_422 -> V_492 , 500 * V_497 / 1000 ,
F_334 , V_420 ) ;
V_420 -> V_449 = V_497 / 2 ;
V_420 -> V_632 = V_633 | V_634 | V_628 ;
V_420 -> V_632 |= V_635 ;
V_420 -> V_225 |= V_420 -> V_632 ;
F_336 ( & V_422 -> V_553 , 1 ) ;
V_422 -> V_569 . V_636 = 0x1 ;
V_422 -> V_569 . V_637 = 0x7 ;
V_422 -> V_569 . V_420 = V_420 ;
V_422 -> V_569 . F_295 = F_295 ;
V_422 -> V_569 . F_296 = F_296 ;
V_422 -> V_569 . V_556 = V_422 -> V_66 . V_231 + 1 ;
V_422 -> V_600 = F_337 ( V_600 ,
( V_638 | V_639 | V_640 ) ) ;
return 0 ;
}
static void F_338 ( struct V_419 * V_420 )
{
if ( V_420 -> V_449 )
F_339 ( V_420 ) ;
F_340 ( V_420 ) ;
}
static void F_341 ( struct V_258 * V_259 , T_4 * V_641 , int V_66 )
{
int V_153 ;
int V_373 ;
int V_642 ;
int V_103 ;
V_153 = V_373 = V_103 = V_642 = 0 ;
while ( V_373 < V_280 ) {
if ( V_641 [ V_153 ] ) {
int V_643 ;
V_642 = 1 ;
V_643 = F_342 ( V_641 [ V_153 ] ) ;
if ( V_643 >= 0 )
V_103 = V_103 * 16 + V_643 ;
else if ( ':' == V_641 [ V_153 ] )
V_642 = 2 ;
else
break;
} else if ( V_642 )
V_642 = 2 ;
else
break;
if ( 2 == V_642 ) {
if ( V_644 == V_66 ) {
V_259 -> V_2 . V_281 [ V_373 ++ ] = ( T_4 ) V_103 ;
V_259 -> V_2 . V_281 [ 5 ] +=
V_259 -> V_2 . V_364 ;
} else {
V_259 -> V_2 . V_104 -> V_645 [ V_373 ++ ] =
( T_4 ) V_103 ;
V_259 -> V_2 . V_104 -> V_645 [ 5 ] +=
V_259 -> V_2 . V_364 ;
}
V_103 = V_642 = 0 ;
}
V_153 ++ ;
}
if ( V_280 == V_373 ) {
if ( V_644 == V_66 )
V_259 -> V_2 . V_362 = 1 ;
}
}
static void F_343 ( struct V_1 * V_2 )
{
int V_153 ;
T_3 V_20 [ 3 ] ;
struct V_104 * V_21 = V_2 -> V_104 ;
for ( V_153 = 0 ; V_153 < 3 ; V_153 ++ )
V_20 [ V_153 ] = F_129 ( V_2 , V_153 + V_646 ) ;
if ( ( V_20 [ 0 ] || V_20 [ 1 ] || V_20 [ 2 ] ) && V_20 [ 0 ] != 0xffff ) {
V_21 -> V_645 [ 5 ] = ( T_4 ) V_20 [ 0 ] ;
V_21 -> V_645 [ 4 ] = ( T_4 ) ( V_20 [ 0 ] >> 8 ) ;
V_21 -> V_645 [ 3 ] = ( T_4 ) V_20 [ 1 ] ;
V_21 -> V_645 [ 2 ] = ( T_4 ) ( V_20 [ 1 ] >> 8 ) ;
V_21 -> V_645 [ 1 ] = ( T_4 ) V_20 [ 2 ] ;
V_21 -> V_645 [ 0 ] = ( T_4 ) ( V_20 [ 2 ] >> 8 ) ;
}
}
static int F_344 ( struct V_260 * V_261 , const struct V_647 * V_364 )
{
struct V_419 * V_420 ;
struct V_421 * V_422 ;
struct V_258 * V_259 ;
struct V_1 * V_2 ;
struct V_648 * V_26 ;
struct V_203 * V_66 ;
unsigned long V_649 ;
unsigned long V_650 ;
int V_67 ;
int V_153 ;
int V_651 ;
int V_491 ;
int V_652 ;
int V_551 ;
char V_653 [ sizeof( V_581 ) ] ;
struct V_104 * V_21 = NULL ;
V_551 = F_345 ( V_261 ) ;
if ( V_551 )
return V_551 ;
V_551 = - V_654 ;
if ( F_346 ( V_261 , F_347 ( 32 ) ) ||
F_348 ( V_261 , F_347 ( 32 ) ) )
return V_551 ;
V_649 = F_349 ( V_261 , 0 ) ;
V_650 = F_350 ( V_261 , 0 ) ;
if ( ( F_351 ( V_261 , 0 ) & V_655 ) != 0 )
return V_551 ;
if ( ! F_352 ( V_649 , V_650 , V_580 ) )
return V_551 ;
F_353 ( V_261 ) ;
V_551 = - V_463 ;
V_26 = F_197 ( sizeof( struct V_648 ) , V_396 ) ;
if ( ! V_26 )
goto V_656;
V_259 = & V_26 -> V_258 ;
V_259 -> V_261 = V_261 ;
V_2 = & V_259 -> V_2 ;
V_2 -> V_4 = F_354 ( V_649 , V_650 ) ;
if ( ! V_2 -> V_4 )
goto V_657;
V_67 = F_153 ( V_2 ) ;
if ( ! V_67 ) {
if ( V_600 & V_639 )
F_159 ( L_8 ) ;
V_551 = - V_654 ;
goto V_658;
}
snprintf ( V_653 , sizeof( V_653 ) , L_9 , V_581 ) ;
V_653 [ 13 ] = V_67 + '0' ;
V_258 ( & V_259 -> V_261 -> V_420 , L_10 , V_653 ) ;
F_355 ( & V_259 -> V_261 -> V_420 , L_11 , V_2 -> V_4 , V_261 -> V_481 ) ;
V_2 -> V_384 = 1 ;
V_652 = 1 ;
V_651 = 1 ;
V_2 -> V_374 = 0 ;
V_2 -> V_86 = V_69 ;
V_2 -> V_507 = 1 ;
if ( 2 == V_67 ) {
if ( V_659 )
V_2 -> V_121 |= V_122 ;
V_2 -> V_86 = V_88 ;
if ( V_660 ) {
V_2 -> V_384 = V_383 ;
V_2 -> V_374 = V_383 - 1 ;
}
if ( 1 == V_2 -> V_384 ) {
V_652 = V_383 ;
V_651 = V_383 ;
}
V_2 -> V_507 = V_106 ;
V_2 -> V_104 = F_197 ( sizeof( struct V_104 ) , V_396 ) ;
if ( ! V_2 -> V_104 )
goto V_658;
V_21 = V_2 -> V_104 ;
}
for ( V_153 = 0 ; V_153 < V_2 -> V_507 ; V_153 ++ )
V_2 -> V_82 [ V_153 ] . V_83 = 0 ;
V_2 -> V_661 = V_259 ;
V_259 -> V_411 = ( V_547 + 3 ) & ~ 3 ;
if ( F_208 ( V_259 ) )
goto V_662;
V_259 -> V_2 . V_364 = V_663 ;
F_356 ( & V_259 -> V_436 ) ;
F_357 ( & V_259 -> V_568 ) ;
for ( V_153 = 0 ; V_153 < V_106 ; V_153 ++ )
F_358 ( & V_259 -> V_85 [ V_153 ] . V_85 ) ;
if ( V_641 [ 0 ] != ':' )
F_341 ( V_259 , V_641 , V_644 ) ;
F_175 ( V_2 ) ;
if ( V_2 -> V_384 > 1 ) {
memcpy ( V_21 -> V_645 , V_2 -> V_281 , V_280 ) ;
F_343 ( V_2 ) ;
if ( V_664 [ 0 ] != ':' )
F_341 ( V_259 , V_664 , V_665 ) ;
}
F_155 ( V_2 ) ;
if ( V_2 -> V_104 )
F_187 ( V_2 ) ;
else {
V_259 -> V_596 = V_666 ;
V_259 -> V_282 = 0 ;
}
F_359 ( & V_259 -> V_496 , F_331 ) ;
F_192 ( & V_259 -> V_495 , 500 * V_497 / 1000 ,
F_333 , V_259 ) ;
for ( V_153 = 0 ; V_153 < V_2 -> V_384 ; V_153 ++ ) {
V_420 = F_360 ( sizeof( struct V_421 ) ) ;
if ( ! V_420 )
goto V_667;
F_361 ( V_420 , & V_261 -> V_420 ) ;
V_26 -> V_668 [ V_153 ] = V_420 ;
V_422 = F_216 ( V_420 ) ;
V_422 -> V_397 = V_259 ;
V_422 -> V_364 = V_663 ++ ;
V_66 = & V_422 -> V_66 ;
V_66 -> V_232 = V_652 ;
V_66 -> V_507 = V_651 ;
V_66 -> V_231 = V_153 ;
V_66 -> V_205 = V_206 ;
V_66 -> V_2 = V_2 ;
V_66 -> V_229 = & V_2 -> V_233 [ V_66 -> V_231 ] ;
for ( V_67 = 0 , V_491 = V_153 ; V_67 < V_652 ; V_67 ++ , V_491 ++ ) {
V_2 -> V_233 [ V_491 ] . V_560 = V_491 ;
V_2 -> V_233 [ V_491 ] . V_261 = V_420 ;
V_2 -> V_233 [ V_491 ] . V_161 = V_244 ;
}
V_420 -> V_669 = ( unsigned long ) V_2 -> V_4 ;
V_420 -> V_670 = V_420 -> V_669 + V_650 - 1 ;
V_420 -> V_481 = V_261 -> V_481 ;
if ( V_644 == V_153 )
memcpy ( V_420 -> V_493 , V_259 -> V_2 . V_281 ,
V_280 ) ;
else {
memcpy ( V_420 -> V_493 , V_21 -> V_645 , V_280 ) ;
if ( F_179 ( V_21 -> V_645 , V_2 -> V_281 ) )
V_420 -> V_493 [ 5 ] += V_66 -> V_231 ;
}
V_420 -> V_671 = & V_671 ;
V_420 -> V_672 = & V_673 ;
if ( F_362 ( V_420 ) )
goto V_667;
F_138 ( V_66 , true ) ;
}
F_363 ( V_259 -> V_261 ) ;
F_364 ( V_261 , V_26 ) ;
return 0 ;
V_667:
for ( V_153 = 0 ; V_153 < V_2 -> V_384 ; V_153 ++ ) {
if ( V_26 -> V_668 [ V_153 ] ) {
F_338 ( V_26 -> V_668 [ V_153 ] ) ;
V_26 -> V_668 [ V_153 ] = NULL ;
}
}
V_662:
F_213 ( V_259 ) ;
F_211 ( V_2 -> V_104 ) ;
V_658:
F_365 ( V_2 -> V_4 ) ;
V_657:
F_211 ( V_26 ) ;
V_656:
F_366 ( V_649 , V_650 ) ;
return V_551 ;
}
static void F_367 ( struct V_260 * V_261 )
{
int V_153 ;
struct V_648 * V_26 = F_368 ( V_261 ) ;
struct V_258 * V_259 = & V_26 -> V_258 ;
F_366 ( F_349 ( V_261 , 0 ) ,
F_350 ( V_261 , 0 ) ) ;
for ( V_153 = 0 ; V_153 < V_259 -> V_2 . V_384 ; V_153 ++ ) {
if ( V_26 -> V_668 [ V_153 ] )
F_338 ( V_26 -> V_668 [ V_153 ] ) ;
}
if ( V_259 -> V_2 . V_4 )
F_365 ( V_259 -> V_2 . V_4 ) ;
F_213 ( V_259 ) ;
F_211 ( V_259 -> V_2 . V_104 ) ;
F_369 ( V_259 -> V_261 ) ;
F_211 ( V_26 ) ;
}
static int F_370 ( struct V_260 * V_261 )
{
int V_153 ;
struct V_648 * V_26 = F_368 ( V_261 ) ;
struct V_258 * V_259 = & V_26 -> V_258 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
F_371 ( V_261 , V_674 ) ;
F_372 ( V_261 ) ;
F_373 ( V_261 , V_674 , 0 ) ;
if ( V_259 -> V_282 )
F_144 ( V_2 , 0 ) ;
for ( V_153 = 0 ; V_153 < V_2 -> V_384 ; V_153 ++ ) {
if ( V_26 -> V_668 [ V_153 ] ) {
struct V_419 * V_420 = V_26 -> V_668 [ V_153 ] ;
if ( F_227 ( V_420 ) ) {
F_279 ( V_420 ) ;
F_374 ( V_420 ) ;
}
}
}
return 0 ;
}
static int F_375 ( struct V_260 * V_261 , T_11 V_161 )
{
int V_153 ;
struct V_648 * V_26 = F_368 ( V_261 ) ;
struct V_258 * V_259 = & V_26 -> V_258 ;
struct V_1 * V_2 = & V_259 -> V_2 ;
static const T_4 V_283 [] = { 192 , 168 , 1 , 1 } ;
for ( V_153 = 0 ; V_153 < V_2 -> V_384 ; V_153 ++ ) {
if ( V_26 -> V_668 [ V_153 ] ) {
struct V_419 * V_420 = V_26 -> V_668 [ V_153 ] ;
if ( F_227 ( V_420 ) ) {
F_376 ( V_420 ) ;
F_266 ( V_420 ) ;
}
}
}
if ( V_259 -> V_282 ) {
F_152 ( V_2 , V_259 -> V_282 , V_283 ) ;
F_144 ( V_2 , 1 ) ;
}
F_377 ( V_261 ) ;
F_373 ( V_261 , F_378 ( V_261 , V_161 ) , 1 ) ;
F_371 ( V_261 , F_378 ( V_261 , V_161 ) ) ;
return 0 ;
}
