static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 ;
}
static inline struct V_1 * F_2 ( struct V_5 * V_6 )
{
return F_3 ( V_6 , struct V_1 , V_6 ) ;
}
static inline unsigned F_4 ( const struct V_7 * V_8 )
{
return F_5 ( V_8 ) ;
}
static inline unsigned F_6 ( const struct V_7 * V_8 )
{
return F_7 ( V_8 ) ;
}
static T_1 F_8 ( struct V_9 * V_10 ,
T_2 V_11 , bool V_12 )
{
union V_13 V_14 ;
if ( ! F_9 ( V_10 -> V_15 , V_10 -> V_16 , V_10 -> V_17 ,
V_18 , V_11 ,
V_19 , & V_14 ) )
return V_14 . V_20 ;
if ( V_12 )
F_10 ( V_10 , L_1 ,
V_10 -> V_16 , V_11 ) ;
return - V_21 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
enum V_22 V_23 , T_2 V_11 )
{
return F_8 ( V_2 -> V_24 [ V_23 ] ,
V_11 , true ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
enum V_22 V_23 , T_2 V_11 ,
T_2 V_25 )
{
struct V_9 * V_10 = V_2 -> V_24 [ V_23 ] ;
union V_13 V_14 ;
int V_26 ;
int V_27 ;
V_14 . V_20 = V_25 ;
for ( V_27 = 0 ; V_27 < 3 ; V_27 ++ ) {
V_26 = F_9 ( V_10 -> V_15 , V_10 -> V_16 ,
V_10 -> V_17 ,
V_28 , V_11 ,
V_19 , & V_14 ) ;
if ( ! V_26 )
break;
}
if ( V_26 < 0 )
F_10 ( V_10 , L_2 ,
V_10 -> V_16 , V_11 , V_25 ) ;
return V_26 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
enum V_22 V_23 , T_2 V_11 ,
unsigned V_29 , const T_2 * V_30 )
{
struct V_9 * V_10 = V_2 -> V_24 [ V_23 ] ;
union V_13 V_14 ;
if ( V_29 > V_31 )
V_29 = V_31 ;
V_14 . V_32 [ 0 ] = V_29 ;
memcpy ( V_14 . V_32 + 1 , V_30 , V_29 ) ;
return F_9 ( V_10 -> V_15 , V_10 -> V_16 , V_10 -> V_17 ,
V_28 , V_11 ,
V_33 , & V_14 ) ;
}
static inline int F_14 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_35 , V_34 ) ;
}
static inline int F_15 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_35 , V_34 , V_36 ) ;
}
static inline int F_16 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_15 ( V_6 , V_34 , ( F_14 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_17 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_38 , V_34 ) ;
}
static inline int F_18 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_38 , V_34 , V_36 ) ;
}
static inline int F_19 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_39 , V_34 ) ;
}
static inline int F_20 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_39 , V_34 , V_36 ) ;
}
static inline int F_21 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_40 , V_34 ) ;
}
static inline int F_22 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_40 ,
V_34 , V_36 ) ;
}
static inline int F_23 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_41 , V_34 ) ;
}
static inline int F_24 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_41 , V_34 , V_36 ) ;
}
static inline int F_25 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_42 , V_34 ) ;
}
static inline int F_26 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_42 , V_34 , V_36 ) ;
}
static inline int F_27 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_26 ( V_6 , V_34 , ( F_25 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_28 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_43 , V_34 ) ;
}
static inline int F_29 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_43 , V_34 , V_36 ) ;
}
static inline int F_30 ( struct V_5 * V_6 ,
unsigned V_44 , const T_2 * V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_26 = 0 ;
int V_27 ;
F_31 ( 2 , V_45 , V_6 , L_3 , V_46 , V_44 ) ;
for ( V_27 = 0 ; ! V_26 && V_27 < V_44 ; V_27 += V_31 )
V_26 = F_13 ( V_2 , V_43 ,
V_27 , V_31 , V_36 + V_27 ) ;
return V_26 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int V_47 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_48 ; ++ V_27 ) {
if ( F_33 ( V_2 -> V_49 [ V_27 ] ) )
continue;
F_34 ( V_2 -> V_49 [ V_27 ] , V_47 & F_35 ( V_27 ) ) ;
}
F_36 ( & V_2 -> V_6 , V_50 , & V_47 ) ;
}
static void F_37 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_38 ( V_52 ) ;
struct V_1 * V_2 = F_3 ( V_54 , struct V_1 ,
V_55 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_31 ( 2 , V_45 , V_6 , L_4 , V_46 ) ;
F_32 ( V_2 , V_2 -> V_56 . V_57 ) ;
}
static inline int F_39 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_58 , V_34 ) ;
}
static T_3 F_40 ( struct V_5 * V_6 , T_2 V_34 , T_3 V_37 )
{
return ( ( F_39 ( V_6 , V_34 ) << 8 ) | F_39 ( V_6 , V_34 + 1 ) ) & V_37 ;
}
static inline int F_41 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_58 , V_34 , V_36 ) ;
}
static inline int F_42 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_41 ( V_6 , V_34 , ( F_39 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_43 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_59 , V_34 , V_36 ) ;
}
static inline int F_44 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_60 , V_34 ) ;
}
static T_3 F_45 ( struct V_5 * V_6 , T_2 V_34 , T_3 V_37 )
{
return ( ( F_44 ( V_6 , V_34 ) << 8 ) | F_44 ( V_6 , V_34 + 1 ) ) & V_37 ;
}
static inline int F_46 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_60 , V_34 , V_36 ) ;
}
static inline int F_47 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_46 ( V_6 , V_34 , ( F_44 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_48 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_61 , V_34 ) ;
}
static inline int F_49 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_61 , V_34 , V_36 ) ;
}
static int F_50 ( struct V_5 * V_6 , unsigned int V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned int V_23 = V_34 >> 8 ;
if ( ! ( F_35 ( V_23 ) & V_2 -> V_3 -> V_62 ) )
return - V_63 ;
V_34 &= 0xff ;
return F_11 ( V_2 , V_23 , V_34 ) ;
}
static int F_51 ( struct V_5 * V_6 , unsigned int V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned int V_23 = V_34 >> 8 ;
if ( ! ( F_35 ( V_23 ) & V_2 -> V_3 -> V_62 ) )
return - V_63 ;
V_34 &= 0xff ;
return F_12 ( V_2 , V_23 , V_34 , V_36 ) ;
}
static void F_52 ( struct V_5 * V_6 ,
const struct V_64 * V_65 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_65 [ V_27 ] . V_34 != V_66 ; V_27 ++ )
F_51 ( V_6 , V_65 [ V_27 ] . V_34 , V_65 [ V_27 ] . V_36 ) ;
}
static const struct V_67 *
V_67 ( struct V_1 * V_2 , T_4 V_68 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_69 ; ++ V_27 ) {
if ( V_2 -> V_3 -> V_70 [ V_27 ] . V_68 == V_68 )
return & V_2 -> V_3 -> V_70 [ V_27 ] ;
}
return NULL ;
}
static inline bool F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_71 == V_72 ||
V_2 -> V_71 == V_73 ;
}
static inline bool F_54 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_71 == V_74 ||
V_2 -> V_71 == V_75 ||
V_2 -> V_71 == V_76 ||
V_2 -> V_71 == V_77 ;
}
static void F_55 ( struct V_5 * V_6 )
{
F_56 ( V_6 , L_5 ) ;
F_56 ( V_6 , L_6 ) ;
F_56 ( V_6 , L_7 ) ;
F_56 ( V_6 , L_8 ) ;
F_56 ( V_6 , L_9 ) ;
F_56 ( V_6 , L_10 ) ;
F_56 ( V_6 , L_11 ) ;
F_56 ( V_6 , L_12 ) ;
F_56 ( V_6 , L_13 ) ;
F_56 ( V_6 , L_14 ) ;
F_56 ( V_6 , L_15 ) ;
F_56 ( V_6 , L_16 ) ;
F_56 ( V_6 , L_17 ) ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_78 * V_34 )
{
int V_79 ;
V_79 = F_50 ( V_6 , V_34 -> V_34 ) ;
if ( V_79 < 0 ) {
F_56 ( V_6 , L_18 , V_34 -> V_34 ) ;
F_55 ( V_6 ) ;
return V_79 ;
}
V_34 -> V_80 = 1 ;
V_34 -> V_36 = V_79 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 ,
const struct V_78 * V_34 )
{
int V_79 ;
V_79 = F_51 ( V_6 , V_34 -> V_34 , V_34 -> V_36 ) ;
if ( V_79 < 0 ) {
F_56 ( V_6 , L_18 , V_34 -> V_34 ) ;
F_55 ( V_6 ) ;
return V_79 ;
}
return 0 ;
}
static unsigned int F_59 ( struct V_5 * V_6 )
{
T_2 V_25 = F_14 ( V_6 , 0x6f ) ;
return ( ( V_25 & 0x10 ) >> 4 )
| ( ( V_25 & 0x08 ) >> 2 )
| ( ( V_25 & 0x04 ) << 0 )
| ( ( V_25 & 0x02 ) << 2 ) ;
}
static unsigned int F_60 ( struct V_5 * V_6 )
{
T_2 V_25 = F_14 ( V_6 , 0x6f ) ;
return V_25 & 1 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
return F_62 ( V_2 -> V_82 ,
V_3 -> V_83 ( V_6 ) ) ;
}
static int F_63 ( struct V_5 * V_6 ,
T_2 V_84 ,
const struct V_85 * V_86 ,
const struct V_87 * V_88 )
{
int V_27 ;
for ( V_27 = 0 ; V_86 [ V_27 ] . V_88 . V_89 . V_90 ; V_27 ++ ) {
if ( ! F_64 ( V_88 , & V_86 [ V_27 ] . V_88 ,
F_54 ( V_6 ) ? 250000 : 1000000 ) )
continue;
F_15 ( V_6 , 0x00 , V_86 [ V_27 ] . V_91 ) ;
F_15 ( V_6 , 0x01 , ( V_86 [ V_27 ] . V_92 << 4 ) +
V_84 ) ;
return 0 ;
}
return - 1 ;
}
static int F_65 ( struct V_5 * V_6 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_26 ;
F_31 ( 1 , V_45 , V_6 , L_19 , V_46 ) ;
if ( F_1 ( V_2 ) ) {
F_15 ( V_6 , 0x16 , 0x43 ) ;
F_15 ( V_6 , 0x17 , 0x5a ) ;
}
F_47 ( V_6 , 0x81 , 0x10 , 0x00 ) ;
F_46 ( V_6 , 0x8f , 0x00 ) ;
F_46 ( V_6 , 0x90 , 0x00 ) ;
F_46 ( V_6 , 0xa2 , 0x00 ) ;
F_46 ( V_6 , 0xa3 , 0x00 ) ;
F_46 ( V_6 , 0xa4 , 0x00 ) ;
F_46 ( V_6 , 0xa5 , 0x00 ) ;
F_46 ( V_6 , 0xa6 , 0x00 ) ;
F_46 ( V_6 , 0xa7 , 0x00 ) ;
F_46 ( V_6 , 0xab , 0x00 ) ;
F_46 ( V_6 , 0xac , 0x00 ) ;
if ( F_53 ( V_6 ) ) {
V_26 = F_63 ( V_6 ,
0x01 , V_93 , V_88 ) ;
if ( V_26 )
V_26 = F_63 ( V_6 ,
0x02 , V_94 , V_88 ) ;
} else if ( F_54 ( V_6 ) ) {
V_26 = F_63 ( V_6 ,
0x05 , V_95 , V_88 ) ;
if ( V_26 )
V_26 = F_63 ( V_6 ,
0x06 , V_96 , V_88 ) ;
} else {
F_31 ( 2 , V_45 , V_6 , L_20 ,
V_46 , V_2 -> V_71 ) ;
V_26 = - 1 ;
}
return V_26 ;
}
static void F_66 ( struct V_5 * V_6 ,
const struct V_7 * V_89 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_90 = F_4 ( V_89 ) ;
T_4 V_97 = F_6 ( V_89 ) ;
T_3 V_98 = V_89 -> V_99 + V_89 -> V_100 - 4 ;
T_3 V_101 = V_90 - V_89 -> V_102 ;
T_3 V_103 = V_97 - V_89 -> V_104 ;
T_3 V_105 = V_89 -> V_106 + V_89 -> V_107 ;
T_3 V_108 = ( ( ( T_4 ) V_89 -> V_109 / 100 ) > 0 ) ?
( ( V_90 * ( V_110 / 100 ) ) / ( ( T_4 ) V_89 -> V_109 / 100 ) ) : 0 ;
const T_2 V_111 [ 2 ] = {
0xc0 | ( ( V_90 >> 8 ) & 0x1f ) ,
V_90 & 0xff
} ;
F_31 ( 2 , V_45 , V_6 , L_21 , V_46 ) ;
if ( F_53 ( V_6 ) ) {
F_15 ( V_6 , 0x00 , 0x07 ) ;
F_15 ( V_6 , 0x01 , 0x02 ) ;
F_47 ( V_6 , 0x81 , 0x10 , 0x10 ) ;
if ( F_13 ( V_2 , V_35 ,
0x16 , 2 , V_111 ) )
F_67 ( V_6 , L_22 ) ;
F_46 ( V_6 , 0xa2 , ( V_98 >> 4 ) & 0xff ) ;
F_46 ( V_6 , 0xa3 , ( ( V_98 & 0x0f ) << 4 ) |
( ( V_101 >> 8 ) & 0x0f ) ) ;
F_46 ( V_6 , 0xa4 , V_101 & 0xff ) ;
F_46 ( V_6 , 0xa5 , ( V_103 >> 4 ) & 0xff ) ;
F_46 ( V_6 , 0xa6 , ( ( V_103 & 0xf ) << 4 ) |
( ( V_105 >> 8 ) & 0xf ) ) ;
F_46 ( V_6 , 0xa7 , V_105 & 0xff ) ;
} else if ( F_54 ( V_6 ) ) {
F_15 ( V_6 , 0x00 , 0x02 ) ;
F_15 ( V_6 , 0x01 , 0x06 ) ;
} else {
F_31 ( 2 , V_45 , V_6 , L_20 ,
V_46 , V_2 -> V_71 ) ;
}
F_46 ( V_6 , 0x8f , ( V_108 >> 8 ) & 0x7 ) ;
F_46 ( V_6 , 0x90 , V_108 & 0xff ) ;
F_46 ( V_6 , 0xab , ( V_97 >> 4 ) & 0xff ) ;
F_46 ( V_6 , 0xac , ( V_97 & 0x0f ) << 4 ) ;
}
static void F_68 ( struct V_5 * V_6 , bool V_112 , T_3 V_113 , T_3 V_114 , T_3 V_115 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 V_116 [ 4 ] ;
if ( V_112 ) {
V_113 = 0x3ff ;
V_114 = 0x3ff ;
V_115 = 0x3ff ;
}
F_31 ( 2 , V_45 , V_6 , L_23 ,
V_46 , V_112 ? L_24 : L_25 ,
V_113 , V_114 , V_115 ) ;
V_116 [ 0 ] = ( F_44 ( V_6 , 0x77 ) & 0xc0 ) | ( ( V_113 & 0x3f0 ) >> 4 ) ;
V_116 [ 1 ] = ( ( V_113 & 0x00f ) << 4 ) | ( ( V_114 & 0x3c0 ) >> 6 ) ;
V_116 [ 2 ] = ( ( V_114 & 0x03f ) << 2 ) | ( ( V_115 & 0x300 ) >> 8 ) ;
V_116 [ 3 ] = V_115 & 0x0ff ;
if ( F_13 ( V_2 , V_60 ,
0x77 , 4 , V_116 ) )
F_67 ( V_6 , L_26 , V_46 ) ;
}
static void F_69 ( struct V_5 * V_6 , bool V_117 , T_3 V_118 , T_3 V_119 , T_3 V_120 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 V_121 [ 4 ] ;
T_2 V_122 = 1 ;
T_2 V_123 = 1 ;
if ( V_117 ) {
V_122 = 0 ;
V_123 = 0 ;
V_118 = 0x100 ;
V_119 = 0x100 ;
V_120 = 0x100 ;
}
F_31 ( 2 , V_45 , V_6 , L_27 ,
V_46 , V_117 ? L_24 : L_25 ,
V_118 , V_119 , V_120 ) ;
V_121 [ 0 ] = ( ( V_122 << 7 ) | ( V_123 << 6 ) | ( ( V_118 & 0x3f0 ) >> 4 ) ) ;
V_121 [ 1 ] = ( ( ( V_118 & 0x00f ) << 4 ) | ( ( V_119 & 0x3c0 ) >> 6 ) ) ;
V_121 [ 2 ] = ( ( ( V_119 & 0x03f ) << 2 ) | ( ( V_120 & 0x300 ) >> 8 ) ) ;
V_121 [ 3 ] = ( ( V_120 & 0x0ff ) ) ;
if ( F_13 ( V_2 , V_60 ,
0x73 , 4 , V_121 ) )
F_67 ( V_6 , L_28 , V_46 ) ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
bool V_124 = F_14 ( V_6 , 0x02 ) & 0x02 ;
bool V_125 = F_39 ( V_6 , 0x05 ) & 0x80 ;
F_31 ( 2 , V_45 , V_6 , L_29 ,
V_46 , V_2 -> V_126 ,
V_124 , V_125 ) ;
F_69 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
F_68 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_2 -> V_126 ) {
case V_127 :
if ( V_2 -> V_71 == V_72 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
break;
}
if ( V_2 -> V_71 == V_73 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_125 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_2 -> V_88 . V_89 . V_128 & V_129 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
} else {
F_16 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_54 ( V_6 ) && V_124 ) {
F_68 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_69 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_68 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_130 :
if ( V_2 -> V_71 == V_73 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x20 ) ;
break;
}
F_16 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
break;
case V_131 :
if ( V_2 -> V_71 == V_73 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x60 ) ;
break;
}
F_16 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_53 ( V_6 ) || V_125 )
break;
if ( V_124 ) {
F_68 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_69 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_68 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_71 ( struct V_132 * V_133 )
{
struct V_5 * V_6 =
& F_3 ( V_133 -> V_134 , struct V_1 , V_135 ) -> V_6 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
switch ( V_133 -> V_136 ) {
case V_137 :
F_46 ( V_6 , 0x3c , V_133 -> V_36 ) ;
return 0 ;
case V_138 :
F_46 ( V_6 , 0x3a , V_133 -> V_36 ) ;
return 0 ;
case V_139 :
F_46 ( V_6 , 0x3b , V_133 -> V_36 ) ;
return 0 ;
case V_140 :
F_46 ( V_6 , 0x3d , V_133 -> V_36 ) ;
return 0 ;
case V_141 :
V_2 -> V_126 = V_133 -> V_36 ;
F_70 ( V_6 ) ;
return 0 ;
case V_142 :
if ( ! F_1 ( V_2 ) )
return - V_63 ;
F_24 ( V_6 , 0xc8 , V_133 -> V_36 ) ;
return 0 ;
case V_143 :
F_47 ( V_6 , 0xbf , 0x04 , V_133 -> V_36 << 2 ) ;
return 0 ;
case V_144 :
F_46 ( V_6 , 0xc0 , ( V_133 -> V_36 & 0xff0000 ) >> 16 ) ;
F_46 ( V_6 , 0xc1 , ( V_133 -> V_36 & 0x00ff00 ) >> 8 ) ;
F_46 ( V_6 , 0xc2 , ( T_2 ) ( V_133 -> V_36 & 0x0000ff ) ) ;
return 0 ;
}
return - V_63 ;
}
static inline bool F_72 ( struct V_5 * V_6 )
{
return F_14 ( V_6 , 0x0c ) & 0x24 ;
}
static inline bool F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return ! ( F_14 ( V_6 , 0x6a ) & ( 0x10 >> V_2 -> V_71 ) ) ;
}
static inline bool F_74 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
return ( F_14 ( V_6 , 0x6a ) & V_3 -> V_145 ) != V_3 -> V_145 ;
}
static inline bool F_75 ( struct V_5 * V_6 )
{
return F_39 ( V_6 , 0x05 ) & 0x80 ;
}
static inline bool F_76 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_1 ( V_2 ) )
return false ;
return ( ( F_44 ( V_6 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_77 ( struct V_5 * V_6 )
{
return ! ( F_44 ( V_6 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_78 ( struct V_5 * V_6 )
{
bool V_79 ;
V_79 = F_72 ( V_6 ) ;
V_79 |= F_77 ( V_6 ) ;
V_79 |= F_76 ( V_6 ) ;
if ( F_54 ( V_6 ) ) {
V_79 |= F_74 ( V_6 ) ;
V_79 |= F_73 ( V_6 ) ;
}
return V_79 ;
}
static inline bool F_79 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( ! F_1 ( V_2 ) )
return false ;
return F_14 ( V_6 , 0x12 ) & 0x01 ;
}
static int F_80 ( struct V_5 * V_6 , T_4 * V_146 )
{
* V_146 = 0 ;
* V_146 |= F_72 ( V_6 ) ? V_147 : 0 ;
* V_146 |= F_78 ( V_6 ) ? V_148 : 0 ;
if ( F_79 ( V_6 ) )
* V_146 |= F_54 ( V_6 ) ? V_149 : V_150 ;
F_31 ( 1 , V_45 , V_6 , L_30 , V_46 , * V_146 ) ;
return 0 ;
}
static int F_81 ( struct V_5 * V_6 ,
struct V_151 * V_152 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_153 = ( V_110 * 8 ) / V_152 -> V_154 ;
T_4 V_155 ;
int V_27 ;
for ( V_27 = 0 ; V_156 [ V_27 ] . V_89 . V_97 ; V_27 ++ ) {
if ( F_6 ( & V_156 [ V_27 ] . V_89 ) != V_152 -> V_157 + 1 )
continue;
if ( V_156 [ V_27 ] . V_89 . V_106 != V_152 -> V_158 )
continue;
V_155 = V_153 * F_4 ( & V_156 [ V_27 ] . V_89 ) ;
if ( ( V_155 < V_156 [ V_27 ] . V_89 . V_109 + 1000000 ) &&
( V_155 > V_156 [ V_27 ] . V_89 . V_109 - 1000000 ) ) {
* V_88 = V_156 [ V_27 ] ;
return 0 ;
}
}
if ( F_82 ( V_152 -> V_157 + 1 , V_153 , V_152 -> V_158 ,
( V_152 -> V_159 == '+' ? V_160 : 0 ) |
( V_152 -> V_161 == '+' ? V_162 : 0 ) ,
V_88 ) )
return 0 ;
if ( F_83 ( V_152 -> V_157 + 1 , V_153 , V_152 -> V_158 ,
( V_152 -> V_159 == '+' ? V_160 : 0 ) |
( V_152 -> V_161 == '+' ? V_162 : 0 ) ,
V_2 -> V_163 , V_88 ) )
return 0 ;
F_31 ( 2 , V_45 , V_6 ,
L_31 ,
V_46 , V_152 -> V_158 , V_152 -> V_157 , V_152 -> V_154 ,
V_152 -> V_159 , V_152 -> V_161 ) ;
return - 1 ;
}
static int F_84 ( struct V_5 * V_6 , struct V_151 * V_152 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
T_2 V_164 ;
if ( F_77 ( V_6 ) || F_76 ( V_6 ) ) {
F_31 ( 2 , V_45 , V_6 , L_32 , V_46 ) ;
return - 1 ;
}
V_152 -> V_154 = F_45 ( V_6 , 0xb1 , 0x3fff ) ;
V_152 -> V_157 = F_45 ( V_6 , V_3 -> V_165 , 0x7ff ) ;
V_152 -> V_158 = F_44 ( V_6 , 0xb3 ) >> 3 ;
V_152 -> V_166 = F_14 ( V_6 , 0x12 ) & 0x10 ;
if ( F_1 ( V_2 ) ) {
V_164 = F_44 ( V_6 , 0xb5 ) ;
if ( ( V_164 & 0x03 ) == 0x01 ) {
V_152 -> V_159 = V_164 & 0x10
? ( V_164 & 0x08 ? '+' : '-' ) : 'x' ;
V_152 -> V_161 = V_164 & 0x40
? ( V_164 & 0x20 ? '+' : '-' ) : 'x' ;
} else {
V_152 -> V_159 = 'x' ;
V_152 -> V_161 = 'x' ;
}
} else {
V_164 = F_39 ( V_6 , 0x05 ) ;
V_152 -> V_159 = V_164 & 0x20 ? '+' : '-' ;
V_152 -> V_161 = V_164 & 0x10 ? '+' : '-' ;
}
if ( F_77 ( V_6 ) || F_76 ( V_6 ) ) {
F_31 ( 2 , V_45 , V_6 ,
L_33 , V_46 ) ;
return - 1 ;
}
if ( V_152 -> V_157 < 239 || V_152 -> V_154 < 8 || V_152 -> V_154 == 0x3fff ) {
F_31 ( 2 , V_45 , V_6 , L_34 , V_46 ) ;
memset ( V_152 , 0 , sizeof( struct V_151 ) ) ;
return - 1 ;
}
F_31 ( 2 , V_45 , V_6 ,
L_35 ,
V_46 , V_152 -> V_157 , V_152 -> V_154 , V_152 -> V_158 ,
V_152 -> V_159 , V_152 -> V_161 ,
V_152 -> V_166 ? L_36 : L_37 ) ;
return 0 ;
}
static int F_85 ( struct V_5 * V_6 ,
struct V_167 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_88 -> V_168 >= F_86 ( V_156 ) - 1 )
return - V_63 ;
if ( V_88 -> V_169 >= V_2 -> V_170 )
return - V_63 ;
memset ( V_88 -> V_171 , 0 , sizeof( V_88 -> V_171 ) ) ;
V_88 -> V_88 = V_156 [ V_88 -> V_168 ] ;
return 0 ;
}
static int F_87 ( struct V_5 * V_6 ,
struct V_172 * V_173 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_173 -> V_169 >= V_2 -> V_170 )
return - V_63 ;
V_173 -> type = V_174 ;
V_173 -> V_89 . V_175 = 1920 ;
V_173 -> V_89 . V_176 = 1200 ;
V_173 -> V_89 . V_177 = 25000000 ;
switch ( V_173 -> V_169 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_173 -> V_89 . V_178 = 225000000 ;
break;
case V_72 :
case V_73 :
default:
V_173 -> V_89 . V_178 = 170000000 ;
break;
}
V_173 -> V_89 . V_128 = V_129 | V_179 |
V_180 | V_181 ;
V_173 -> V_89 . V_182 = V_183 |
V_184 | V_185 ;
return 0 ;
}
static void F_88 ( struct V_5 * V_6 ,
struct V_87 * V_88 )
{
int V_27 ;
for ( V_27 = 0 ; V_156 [ V_27 ] . V_89 . V_90 ; V_27 ++ ) {
if ( F_64 ( V_88 , & V_156 [ V_27 ] ,
F_54 ( V_6 ) ? 250000 : 1000000 ) ) {
* V_88 = V_156 [ V_27 ] ;
break;
}
}
}
static unsigned int F_89 ( struct V_5 * V_6 )
{
unsigned int V_186 ;
int V_187 , V_188 ;
V_187 = F_39 ( V_6 , 0x06 ) ;
V_188 = F_39 ( V_6 , 0x3b ) ;
if ( V_187 < 0 || V_188 < 0 )
return 0 ;
V_186 = V_187 * 1000000 + ( ( V_188 & 0x30 ) >> 4 ) * 250000 ;
if ( F_75 ( V_6 ) ) {
unsigned V_189 = ( ( F_39 ( V_6 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_186 = V_186 * 8 / V_189 ;
}
return V_186 ;
}
static unsigned int F_90 ( struct V_5 * V_6 )
{
int V_187 , V_188 ;
V_187 = F_39 ( V_6 , 0x51 ) ;
V_188 = F_39 ( V_6 , 0x52 ) ;
if ( V_187 < 0 || V_188 < 0 )
return 0 ;
return ( ( V_187 << 1 ) | ( V_188 >> 7 ) ) * 1000000 + ( V_188 & 0x7f ) * 1000000 / 128 ;
}
static int F_91 ( struct V_5 * V_6 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
struct V_7 * V_89 = & V_88 -> V_89 ;
struct V_151 V_152 ;
if ( ! V_88 )
return - V_63 ;
memset ( V_88 , 0 , sizeof( struct V_87 ) ) ;
if ( F_78 ( V_6 ) ) {
V_2 -> V_190 = true ;
F_31 ( 1 , V_45 , V_6 , L_38 , V_46 ) ;
return - V_191 ;
}
if ( F_84 ( V_6 , & V_152 ) ) {
F_31 ( 1 , V_45 , V_6 , L_39 , V_46 ) ;
return - V_191 ;
}
V_89 -> V_166 = V_152 . V_166 ?
V_192 : V_193 ;
if ( F_54 ( V_6 ) ) {
V_88 -> type = V_174 ;
V_89 -> V_90 = F_40 ( V_6 , 0x07 , 0xfff ) ;
V_89 -> V_97 = F_40 ( V_6 , 0x09 , 0xfff ) ;
V_89 -> V_109 = V_3 -> V_194 ( V_6 ) ;
V_89 -> V_102 = F_40 ( V_6 , 0x20 , 0x3ff ) ;
V_89 -> V_99 = F_40 ( V_6 , 0x22 , 0x3ff ) ;
V_89 -> V_100 = F_40 ( V_6 , 0x24 , 0x3ff ) ;
V_89 -> V_104 = F_40 ( V_6 , 0x2a , 0x1fff ) / 2 ;
V_89 -> V_106 = F_40 ( V_6 , 0x2e , 0x1fff ) / 2 ;
V_89 -> V_107 = F_40 ( V_6 , 0x32 , 0x1fff ) / 2 ;
V_89 -> V_195 = ( ( F_39 ( V_6 , 0x05 ) & 0x10 ) ? V_162 : 0 ) |
( ( F_39 ( V_6 , 0x05 ) & 0x20 ) ? V_160 : 0 ) ;
if ( V_89 -> V_166 == V_192 ) {
V_89 -> V_97 += F_40 ( V_6 , 0x0b , 0xfff ) ;
V_89 -> V_196 = F_40 ( V_6 , 0x2c , 0x1fff ) / 2 ;
V_89 -> V_197 = F_40 ( V_6 , 0x30 , 0x1fff ) / 2 ;
V_89 -> V_198 = F_40 ( V_6 , 0x34 , 0x1fff ) / 2 ;
}
F_88 ( V_6 , V_88 ) ;
} else {
if ( ! F_81 ( V_6 , & V_152 , V_88 ) )
goto V_199;
V_152 . V_158 += 1 ;
F_31 ( 1 , V_45 , V_6 , L_40 , V_46 , V_152 . V_158 ) ;
if ( ! F_81 ( V_6 , & V_152 , V_88 ) )
goto V_199;
V_152 . V_158 -= 2 ;
F_31 ( 1 , V_45 , V_6 , L_41 , V_46 , V_152 . V_158 ) ;
if ( F_81 ( V_6 , & V_152 , V_88 ) ) {
if ( V_2 -> V_190 ) {
F_31 ( 1 , V_45 , V_6 , L_42 , V_46 ) ;
F_47 ( V_6 , 0x86 , 0x06 , 0x00 ) ;
F_47 ( V_6 , 0x86 , 0x06 , 0x04 ) ;
F_47 ( V_6 , 0x86 , 0x06 , 0x02 ) ;
V_2 -> V_190 = false ;
return - V_191 ;
}
F_31 ( 1 , V_45 , V_6 , L_43 , V_46 ) ;
return - V_200 ;
}
V_2 -> V_190 = true ;
}
V_199:
if ( F_78 ( V_6 ) ) {
F_31 ( 1 , V_45 , V_6 , L_44 , V_46 ) ;
memset ( V_88 , 0 , sizeof( struct V_87 ) ) ;
return - V_191 ;
}
if ( ( F_53 ( V_6 ) && V_89 -> V_109 > 170000000 ) ||
( F_54 ( V_6 ) && V_89 -> V_109 > 225000000 ) ) {
F_31 ( 1 , V_45 , V_6 , L_45 ,
V_46 , ( T_4 ) V_89 -> V_109 ) ;
return - V_200 ;
}
if ( V_45 > 1 )
F_92 ( V_6 -> V_201 , L_46 ,
V_88 , true ) ;
return 0 ;
}
static int F_93 ( struct V_5 * V_6 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_7 * V_89 ;
int V_26 ;
if ( ! V_88 )
return - V_63 ;
if ( F_64 ( & V_2 -> V_88 , V_88 , 0 ) ) {
F_31 ( 1 , V_45 , V_6 , L_47 , V_46 ) ;
return 0 ;
}
V_89 = & V_88 -> V_89 ;
if ( ( F_53 ( V_6 ) && V_89 -> V_109 > 170000000 ) ||
( F_54 ( V_6 ) && V_89 -> V_109 > 225000000 ) ) {
F_31 ( 1 , V_45 , V_6 , L_45 ,
V_46 , ( T_4 ) V_89 -> V_109 ) ;
return - V_200 ;
}
F_88 ( V_6 , V_88 ) ;
V_2 -> V_88 = * V_88 ;
F_47 ( V_6 , 0x91 , 0x40 , V_89 -> V_166 ? 0x40 : 0x00 ) ;
V_26 = F_65 ( V_6 , V_88 ) ;
if ( V_26 ) {
F_66 ( V_6 , V_89 ) ;
}
F_70 ( V_6 ) ;
if ( V_45 > 1 )
F_92 ( V_6 -> V_201 , L_48 ,
V_88 , true ) ;
return 0 ;
}
static int F_94 ( struct V_5 * V_6 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
* V_88 = V_2 -> V_88 ;
return 0 ;
}
static void F_95 ( struct V_5 * V_6 , bool V_202 )
{
F_41 ( V_6 , 0x01 , V_202 ? 0x00 : 0x78 ) ;
}
static void F_96 ( struct V_5 * V_6 , bool V_202 )
{
F_41 ( V_6 , 0x83 , V_202 ? 0xfe : 0xff ) ;
}
static void F_97 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_53 ( V_6 ) ) {
F_15 ( V_6 , 0x15 , 0xb0 ) ;
} else if ( F_54 ( V_6 ) ) {
F_42 ( V_6 , 0x00 , 0x03 , V_2 -> V_71 ) ;
V_2 -> V_3 -> V_203 ( V_6 , true ) ;
F_15 ( V_6 , 0x15 , 0xa0 ) ;
F_42 ( V_6 , 0x1a , 0x10 , 0x00 ) ;
} else {
F_31 ( 2 , V_45 , V_6 , L_20 ,
V_46 , V_2 -> V_71 ) ;
}
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_42 ( V_6 , 0x1a , 0x10 , 0x10 ) ;
F_99 ( 16 ) ;
F_15 ( V_6 , 0x15 , 0xbe ) ;
V_2 -> V_3 -> V_203 ( V_6 , false ) ;
}
static void F_100 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
if ( F_53 ( V_6 ) ) {
F_52 ( V_6 , V_3 -> V_204 [ 0 ] ) ;
F_24 ( V_6 , 0x00 , 0x08 ) ;
F_24 ( V_6 , 0x01 , 0x06 ) ;
F_24 ( V_6 , 0xc8 , 0x00 ) ;
} else if ( F_54 ( V_6 ) ) {
F_41 ( V_6 , 0x00 , V_2 -> V_71 & 0x03 ) ;
F_52 ( V_6 , V_3 -> V_204 [ 1 ] ) ;
if ( F_1 ( V_2 ) ) {
F_24 ( V_6 , 0x00 , 0xff ) ;
F_24 ( V_6 , 0x01 , 0xfe ) ;
F_24 ( V_6 , 0xc8 , 0x40 ) ;
}
F_46 ( V_6 , 0x3e , 0x00 ) ;
F_46 ( V_6 , 0xc3 , 0x39 ) ;
F_46 ( V_6 , 0x40 , 0x80 ) ;
} else {
F_31 ( 2 , V_45 , V_6 , L_20 ,
V_46 , V_2 -> V_71 ) ;
}
}
static int F_101 ( struct V_5 * V_6 ,
T_4 V_205 , T_4 V_206 , T_4 V_207 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_31 ( 2 , V_45 , V_6 , L_49 ,
V_46 , V_205 , V_2 -> V_71 ) ;
if ( V_205 == V_2 -> V_71 )
return 0 ;
if ( V_205 > V_2 -> V_3 -> V_208 )
return - V_63 ;
V_2 -> V_71 = V_205 ;
F_98 ( V_6 ) ;
F_100 ( V_6 ) ;
F_97 ( V_6 ) ;
return 0 ;
}
static int F_102 ( struct V_5 * V_6 ,
struct V_209 * V_210 ,
struct V_211 * V_68 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_68 -> V_168 >= V_2 -> V_3 -> V_69 )
return - V_63 ;
V_68 -> V_68 = V_2 -> V_3 -> V_70 [ V_68 -> V_168 ] . V_68 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_212 * V_213 )
{
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
V_213 -> V_90 = V_2 -> V_88 . V_89 . V_90 ;
V_213 -> V_97 = V_2 -> V_88 . V_89 . V_97 ;
V_213 -> V_214 = V_215 ;
if ( V_2 -> V_88 . V_89 . V_128 & V_129 )
V_213 -> V_216 = ( V_2 -> V_88 . V_89 . V_97 <= 576 ) ?
V_217 : V_218 ;
}
static unsigned int F_104 ( struct V_1 * V_2 )
{
#define F_105 ( V_187 , V_188 , T_5 , T_6 , T_7 , T_8 ) { \
ADV7604_OP_CH_SEL_##a, ADV7604_OP_CH_SEL_##b, ADV7604_OP_CH_SEL_##c, \
ADV7604_OP_CH_SEL_##d, ADV7604_OP_CH_SEL_##e, ADV7604_OP_CH_SEL_##f }
#define F_106 ( T_9 ) [ADV7604_BUS_ORDER_##x]
static const unsigned int V_219 [ 6 ] [ 6 ] = {
F_106 ( V_220 ) = F_105 ( V_221 , V_222 , V_223 , V_220 , V_224 , V_225 ) ,
F_106 ( V_222 ) = F_105 ( V_223 , V_220 , V_221 , V_222 , V_225 , V_224 ) ,
F_106 ( V_225 ) = F_105 ( V_222 , V_221 , V_224 , V_225 , V_223 , V_220 ) ,
F_106 ( V_223 ) = F_105 ( V_225 , V_224 , V_220 , V_223 , V_222 , V_221 ) ,
F_106 ( V_224 ) = F_105 ( V_224 , V_225 , V_222 , V_221 , V_220 , V_223 ) ,
F_106 ( V_221 ) = F_105 ( V_220 , V_223 , V_225 , V_224 , V_221 , V_222 ) ,
} ;
return V_219 [ V_2 -> V_226 . V_227 ] [ V_2 -> V_213 -> V_219 >> 5 ] ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_16 ( V_6 , 0x02 , 0x02 ,
V_2 -> V_213 -> V_228 ? V_229 : 0 ) ;
F_15 ( V_6 , 0x03 , V_2 -> V_213 -> V_230 |
V_2 -> V_226 . V_231 ) ;
F_16 ( V_6 , 0x04 , 0xe0 , F_104 ( V_2 ) ) ;
F_16 ( V_6 , 0x05 , 0x01 ,
V_2 -> V_213 -> V_232 ? V_233 : 0 ) ;
}
static int F_108 ( struct V_5 * V_6 , struct V_209 * V_210 ,
struct V_234 * V_213 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_213 -> V_169 != V_2 -> V_170 )
return - V_63 ;
F_103 ( V_2 , & V_213 -> V_213 ) ;
if ( V_213 -> V_235 == V_236 ) {
struct V_212 * V_237 ;
V_237 = F_109 ( V_210 , V_213 -> V_169 ) ;
V_213 -> V_213 . V_68 = V_237 -> V_68 ;
} else {
V_213 -> V_213 . V_68 = V_2 -> V_213 -> V_68 ;
}
return 0 ;
}
static int F_110 ( struct V_5 * V_6 , struct V_209 * V_210 ,
struct V_234 * V_213 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_67 * V_3 ;
if ( V_213 -> V_169 != V_2 -> V_170 )
return - V_63 ;
V_3 = V_67 ( V_2 , V_213 -> V_213 . V_68 ) ;
if ( V_3 == NULL )
V_3 = V_67 ( V_2 , V_238 ) ;
F_103 ( V_2 , & V_213 -> V_213 ) ;
V_213 -> V_213 . V_68 = V_3 -> V_68 ;
if ( V_213 -> V_235 == V_236 ) {
struct V_212 * V_237 ;
V_237 = F_109 ( V_210 , V_213 -> V_169 ) ;
V_237 -> V_68 = V_213 -> V_213 . V_68 ;
} else {
V_2 -> V_213 = V_3 ;
F_107 ( V_2 ) ;
}
return 0 ;
}
static int F_111 ( struct V_5 * V_6 , T_4 V_146 , bool * V_239 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
const T_2 V_240 = F_14 ( V_6 , 0x43 ) ;
const T_2 V_241 = F_14 ( V_6 , 0x6b ) ;
const T_2 V_242 = F_14 ( V_6 , 0x70 ) ;
T_2 V_243 ;
T_2 V_244 ;
T_2 V_245 ;
if ( V_240 )
F_15 ( V_6 , 0x44 , V_240 ) ;
if ( V_242 )
F_15 ( V_6 , 0x71 , V_242 ) ;
if ( V_241 )
F_15 ( V_6 , 0x6c , V_241 ) ;
F_31 ( 2 , V_45 , V_6 , L_50 , V_46 ) ;
V_244 = V_240 & 0x98 ;
V_243 = F_54 ( V_6 )
? V_241 & V_3 -> V_246
: 0 ;
if ( V_244 || V_243 ) {
F_31 ( 1 , V_45 , V_6 ,
L_51 ,
V_46 , V_244 , V_243 ) ;
F_36 ( V_6 , V_247 , NULL ) ;
if ( V_239 )
* V_239 = true ;
}
if ( V_241 & 0x01 ) {
F_31 ( 1 , V_45 , V_6 , L_52 , V_46 ,
( F_14 ( V_6 , 0x6a ) & 0x01 ) ? L_53 : L_54 ) ;
F_70 ( V_6 ) ;
if ( V_239 )
* V_239 = true ;
}
V_245 = F_14 ( V_6 , 0x70 ) & V_3 -> V_248 ;
if ( V_245 ) {
F_31 ( 1 , V_45 , V_6 , L_55 , V_46 , V_245 ) ;
F_15 ( V_6 , 0x71 , V_245 ) ;
F_61 ( V_6 ) ;
if ( V_239 )
* V_239 = true ;
}
return 0 ;
}
static int F_112 ( struct V_5 * V_6 , struct V_249 * V_56 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 * V_14 = NULL ;
memset ( V_56 -> V_171 , 0 , sizeof( V_56 -> V_171 ) ) ;
switch ( V_56 -> V_169 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
if ( V_2 -> V_56 . V_57 & ( 1 << V_56 -> V_169 ) )
V_14 = V_2 -> V_56 . V_56 ;
break;
default:
return - V_63 ;
}
if ( V_56 -> V_250 == 0 && V_56 -> V_251 == 0 ) {
V_56 -> V_251 = V_14 ? V_2 -> V_56 . V_251 : 0 ;
return 0 ;
}
if ( V_14 == NULL )
return - V_252 ;
if ( V_56 -> V_250 >= V_2 -> V_56 . V_251 )
return - V_63 ;
if ( V_56 -> V_250 + V_56 -> V_251 > V_2 -> V_56 . V_251 )
V_56 -> V_251 = V_2 -> V_56 . V_251 - V_56 -> V_250 ;
memcpy ( V_56 -> V_56 , V_14 + V_56 -> V_250 * 128 , V_56 -> V_251 * 128 ) ;
return 0 ;
}
static int F_113 ( const T_2 * V_56 )
{
T_2 T_6 ;
if ( ( V_56 [ 0x7e ] != 1 ) ||
( V_56 [ 0x80 ] != 0x02 ) ||
( V_56 [ 0x81 ] != 0x03 ) ) {
return - 1 ;
}
T_6 = V_56 [ 0x82 ] & 0x7f ;
if ( T_6 > 4 ) {
int V_27 = 0x84 ;
int V_253 = 0x80 + T_6 ;
do {
T_2 V_254 = V_56 [ V_27 ] >> 5 ;
T_2 V_44 = V_56 [ V_27 ] & 0x1f ;
if ( ( V_254 == 3 ) && ( V_44 >= 5 ) )
return V_27 + 4 ;
V_27 += V_44 + 1 ;
} while ( V_27 < V_253 );
}
return - 1 ;
}
static int F_114 ( struct V_5 * V_6 , struct V_249 * V_56 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
int V_255 ;
int V_26 ;
int V_27 ;
memset ( V_56 -> V_171 , 0 , sizeof( V_56 -> V_171 ) ) ;
if ( V_56 -> V_169 > V_77 )
return - V_63 ;
if ( V_56 -> V_250 != 0 )
return - V_63 ;
if ( V_56 -> V_251 == 0 ) {
V_2 -> V_56 . V_57 &= ~ ( 1 << V_56 -> V_169 ) ;
F_32 ( V_2 , V_2 -> V_56 . V_57 ) ;
F_27 ( V_6 , V_3 -> V_256 , 0x0f , V_2 -> V_56 . V_57 ) ;
V_2 -> V_163 . V_257 = 16 ;
V_2 -> V_163 . V_258 = 9 ;
if ( ! V_2 -> V_56 . V_57 )
V_2 -> V_56 . V_251 = 0 ;
F_31 ( 2 , V_45 , V_6 , L_56 ,
V_46 , V_56 -> V_169 , V_2 -> V_56 . V_57 ) ;
return 0 ;
}
if ( V_56 -> V_251 > 2 ) {
V_56 -> V_251 = 2 ;
return - V_259 ;
}
F_31 ( 2 , V_45 , V_6 , L_57 ,
V_46 , V_56 -> V_169 , V_2 -> V_56 . V_57 ) ;
F_115 ( & V_2 -> V_55 ) ;
F_32 ( V_2 , 0 ) ;
F_27 ( V_6 , V_3 -> V_256 , 0x0f , 0x00 ) ;
V_255 = F_113 ( V_56 -> V_56 ) ;
if ( V_255 < 0 )
V_255 = 0xc0 ;
switch ( V_56 -> V_169 ) {
case V_74 :
V_2 -> V_260 [ 0 ] = V_56 -> V_56 [ V_255 ] ;
V_2 -> V_260 [ 1 ] = V_56 -> V_56 [ V_255 + 1 ] ;
break;
case V_75 :
F_26 ( V_6 , 0x70 , V_56 -> V_56 [ V_255 ] ) ;
F_26 ( V_6 , 0x71 , V_56 -> V_56 [ V_255 + 1 ] ) ;
break;
case V_76 :
F_26 ( V_6 , 0x72 , V_56 -> V_56 [ V_255 ] ) ;
F_26 ( V_6 , 0x73 , V_56 -> V_56 [ V_255 + 1 ] ) ;
break;
case V_77 :
F_26 ( V_6 , 0x74 , V_56 -> V_56 [ V_255 ] ) ;
F_26 ( V_6 , 0x75 , V_56 -> V_56 [ V_255 + 1 ] ) ;
break;
default:
return - V_63 ;
}
if ( V_3 -> type == V_261 ) {
F_26 ( V_6 , 0x76 , V_255 & 0xff ) ;
F_27 ( V_6 , 0x77 , 0x40 , ( V_255 & 0x100 ) >> 2 ) ;
} else {
F_27 ( V_6 , 0x71 , 0x01 , ( V_255 & 0x100 ) >> 8 ) ;
}
V_56 -> V_56 [ V_255 ] = V_2 -> V_260 [ 0 ] ;
V_56 -> V_56 [ V_255 + 1 ] = V_2 -> V_260 [ 1 ] ;
memcpy ( V_2 -> V_56 . V_56 , V_56 -> V_56 , 128 * V_56 -> V_251 ) ;
V_2 -> V_56 . V_251 = V_56 -> V_251 ;
V_2 -> V_163 = F_116 ( V_56 -> V_56 [ 0x15 ] ,
V_56 -> V_56 [ 0x16 ] ) ;
V_2 -> V_56 . V_57 |= 1 << V_56 -> V_169 ;
V_26 = F_30 ( V_6 , 128 * V_56 -> V_251 , V_2 -> V_56 . V_56 ) ;
if ( V_26 < 0 ) {
F_67 ( V_6 , L_58 , V_26 , V_56 -> V_169 ) ;
return V_26 ;
}
F_27 ( V_6 , V_3 -> V_256 , 0x0f , V_2 -> V_56 . V_57 ) ;
for ( V_27 = 0 ; V_27 < 1000 ; V_27 ++ ) {
if ( F_25 ( V_6 , V_3 -> V_262 ) & V_2 -> V_56 . V_57 )
break;
F_117 ( 1 ) ;
}
if ( V_27 == 1000 ) {
F_67 ( V_6 , L_59 , V_2 -> V_56 . V_57 ) ;
return - V_21 ;
}
F_118 ( V_2 -> V_263 ,
& V_2 -> V_55 , V_264 / 10 ) ;
return 0 ;
}
static void F_119 ( struct V_5 * V_6 )
{
int V_27 ;
T_2 V_265 [ 14 ] ;
T_2 V_266 ;
T_2 V_267 ;
if ( ! F_75 ( V_6 ) ) {
F_56 ( V_6 , L_60 ) ;
return;
}
if ( ! ( F_14 ( V_6 , 0x60 ) & 0x01 ) ) {
F_56 ( V_6 , L_61 ) ;
return;
}
if ( F_14 ( V_6 , 0x83 ) & 0x01 ) {
F_56 ( V_6 , L_62 ) ;
F_15 ( V_6 , 0x85 , 0x01 ) ;
if ( F_14 ( V_6 , 0x83 ) & 0x01 ) {
F_56 ( V_6 , L_63 ) ;
F_15 ( V_6 , 0x85 , 0x01 ) ;
}
}
V_266 = F_21 ( V_6 , 0xe2 ) ;
V_267 = F_21 ( V_6 , 0xe1 ) ;
F_56 ( V_6 , L_64 ,
V_267 , V_266 ) ;
if ( V_267 != 0x02 )
return;
for ( V_27 = 0 ; V_27 < 14 ; V_27 ++ )
V_265 [ V_27 ] = F_21 ( V_6 , V_27 ) ;
F_56 ( V_6 ,
L_65 ,
V_265 [ 0 ] , V_265 [ 1 ] , V_265 [ 2 ] , V_265 [ 3 ] , V_265 [ 4 ] , V_265 [ 5 ] , V_265 [ 6 ] , V_265 [ 7 ] ,
V_265 [ 8 ] , V_265 [ 9 ] , V_265 [ 10 ] , V_265 [ 11 ] , V_265 [ 12 ] , V_265 [ 13 ] ) ;
}
static int F_120 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
struct V_87 V_88 ;
struct V_151 V_152 ;
T_2 V_268 = F_14 ( V_6 , 0x02 ) ;
T_2 V_269 ;
T_2 V_270 ;
static const char * const V_271 [ 16 ] = {
L_66 , L_67 , L_68 , L_69 ,
L_68 , L_70 , L_68 , L_71 ,
L_68 , L_72 , L_73 ,
L_68 , L_68 , L_68 , L_68 , L_74
} ;
static const char * const V_272 [ 16 ] = {
L_75 , L_76 ,
L_77 , L_78 ,
L_79 , L_80 ,
L_81 , L_82 ,
L_83 , L_83 , L_83 , L_83 , L_83 ,
L_83 , L_83 , L_84
} ;
static const char * const V_273 [] = {
L_85 ,
L_75 ,
L_76 ,
} ;
static const char * const V_274 [ 4 ] = {
L_86 ,
L_87 ,
L_88 ,
L_89
} ;
F_56 ( V_6 , L_90 ) ;
F_56 ( V_6 , L_91 , F_72 ( V_6 ) ? L_92 : L_93 ) ;
V_269 = F_25 ( V_6 , V_3 -> V_262 ) ;
F_56 ( V_6 , L_94 ,
( ( V_269 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_269 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_269 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_269 & 0x08 ) ? L_95 : L_96 ) ) ;
F_56 ( V_6 , L_97 , ! ! ( F_19 ( V_6 , 0x2a ) & 0x01 ) ?
L_98 : L_99 ) ;
F_56 ( V_6 , L_100 ) ;
V_270 = V_3 -> V_83 ( V_6 ) ;
F_56 ( V_6 , L_101 ,
( ( V_270 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_270 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_270 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_270 & 0x08 ) ? L_95 : L_96 ) ) ;
F_56 ( V_6 , L_102 ,
F_73 ( V_6 ) ? L_103 : L_104 ) ;
F_56 ( V_6 , L_105 ,
F_74 ( V_6 ) ? L_103 : L_104 ) ;
F_56 ( V_6 , L_106 , F_76 ( V_6 ) ? L_103 : L_104 ) ;
F_56 ( V_6 , L_107 , F_77 ( V_6 ) ? L_103 : L_104 ) ;
F_56 ( V_6 , L_108 , F_79 ( V_6 ) ? L_103 : L_104 ) ;
F_56 ( V_6 , L_109 ,
( ! ! ( F_44 ( V_6 , 0xff ) & 0x10 ) ? L_93 : L_92 ) ) ;
F_56 ( V_6 , L_110 ,
F_14 ( V_6 , 0x01 ) & 0x0f , F_14 ( V_6 , 0x00 ) & 0x3f ,
( F_14 ( V_6 , 0x01 ) & 0x70 ) >> 4 ) ;
F_56 ( V_6 , L_111 ) ;
if ( F_84 ( V_6 , & V_152 ) )
F_56 ( V_6 , L_112 ) ;
else
F_56 ( V_6 , L_113 ,
V_152 . V_157 , V_152 . V_154 , V_152 . V_158 ,
V_152 . V_166 ? L_36 : L_37 ,
V_152 . V_159 , V_152 . V_161 ) ;
if ( F_91 ( V_6 , & V_88 ) )
F_56 ( V_6 , L_114 ) ;
else
F_92 ( V_6 -> V_201 , L_115 ,
& V_88 , true ) ;
F_92 ( V_6 -> V_201 , L_116 ,
& V_2 -> V_88 , true ) ;
if ( F_78 ( V_6 ) )
return 0 ;
F_56 ( V_6 , L_117 ) ;
F_56 ( V_6 , L_118 ,
V_273 [ V_2 -> V_126 ] ) ;
F_56 ( V_6 , L_119 ,
V_272 [ V_268 >> 4 ] ) ;
F_56 ( V_6 , L_120 ,
( V_268 & 0x02 ) ? L_121 : L_122 ,
( V_268 & 0x04 ) ? L_123 : L_124 ,
( ( V_268 & 0x04 ) ^ ( V_268 & 0x01 ) ) ?
L_98 : L_99 ) ;
F_56 ( V_6 , L_125 ,
V_271 [ F_44 ( V_6 , 0xfc ) >> 4 ] ) ;
if ( ! F_54 ( V_6 ) )
return 0 ;
F_56 ( V_6 , L_126 , F_75 ( V_6 ) ? L_53 : L_127 ) ;
F_56 ( V_6 , L_128 ,
( F_39 ( V_6 , 0x00 ) & 0x03 ) + 'A' ) ;
F_56 ( V_6 , L_129 ,
( F_39 ( V_6 , 0x05 ) & 0x40 ) ? L_104 : L_103 ) ;
F_56 ( V_6 , L_130 ,
( F_39 ( V_6 , 0x04 ) & 0x20 ) ? L_131 : L_132 ,
( F_39 ( V_6 , 0x04 ) & 0x10 ) ? L_133 : L_134 ) ;
if ( F_75 ( V_6 ) ) {
bool V_275 = F_39 ( V_6 , 0x04 ) & 0x01 ;
bool V_276 = F_39 ( V_6 , 0x18 ) & 0x01 ;
bool V_277 = F_14 ( V_6 , 0x65 ) & 0x40 ;
F_56 ( V_6 , L_135 ,
V_275 ? L_136 : L_137 ,
V_276 ? L_138 : L_139 ,
V_277 ? L_140 : L_98 ) ;
if ( V_275 && V_276 ) {
F_56 ( V_6 , L_141 ,
( F_39 ( V_6 , 0x07 ) & 0x20 ) ? L_142 : L_143 ) ;
}
F_56 ( V_6 , L_144 , ( F_39 ( V_6 , 0x5b ) << 12 ) +
( F_39 ( V_6 , 0x5c ) << 8 ) +
( F_39 ( V_6 , 0x5d ) & 0xf0 ) ) ;
F_56 ( V_6 , L_145 , ( ( F_39 ( V_6 , 0x5d ) & 0x0f ) << 16 ) +
( F_39 ( V_6 , 0x5e ) << 8 ) +
F_39 ( V_6 , 0x5f ) ) ;
F_56 ( V_6 , L_146 , ( F_39 ( V_6 , 0x04 ) & 0x40 ) ? L_93 : L_92 ) ;
F_56 ( V_6 , L_147 , V_274 [ ( F_39 ( V_6 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_119 ( V_6 ) ;
}
return 0 ;
}
static int F_121 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
struct V_278 * V_226 = & V_2 -> V_226 ;
F_41 ( V_6 , 0x48 ,
( V_226 -> V_279 ? 0x80 : 0 ) |
( V_226 -> V_280 ? 0x40 : 0 ) ) ;
F_98 ( V_6 ) ;
if ( V_226 -> V_281 >= 0 &&
V_226 -> V_281 < V_2 -> V_170 ) {
V_2 -> V_71 = V_226 -> V_281 ;
F_100 ( V_6 ) ;
F_97 ( V_6 ) ;
}
F_15 ( V_6 , 0x0c , 0x42 ) ;
F_15 ( V_6 , 0x0b , 0x44 ) ;
F_46 ( V_6 , 0xcf , 0x01 ) ;
F_16 ( V_6 , 0x02 , 0x0f ,
V_226 -> V_282 << 3 |
V_226 -> V_283 << 2 |
V_226 -> V_284 << 0 ) ;
F_16 ( V_6 , 0x05 , 0x0e , V_226 -> V_285 << 3 |
V_226 -> V_286 << 2 |
V_226 -> V_287 << 1 ) ;
F_107 ( V_2 ) ;
F_46 ( V_6 , 0x69 , 0x30 ) ;
F_15 ( V_6 , 0x06 , 0xa0 | V_226 -> V_288 << 2 |
V_226 -> V_289 << 1 | V_226 -> V_290 ) ;
F_15 ( V_6 , 0x14 , 0x40 | V_226 -> V_291 << 4 |
V_226 -> V_292 << 2 |
V_226 -> V_293 ) ;
F_46 ( V_6 , 0xba , ( V_226 -> V_294 << 1 ) | 0x01 ) ;
F_46 ( V_6 , 0xf3 , 0xdc ) ;
F_46 ( V_6 , 0xf9 , 0x23 ) ;
F_46 ( V_6 , 0x45 , 0x23 ) ;
F_46 ( V_6 , 0xc9 , 0x2d ) ;
F_42 ( V_6 , 0x15 , 0x03 , 0x03 ) ;
F_42 ( V_6 , 0x1a , 0x0e , 0x08 ) ;
F_42 ( V_6 , 0x68 , 0x06 , 0x06 ) ;
F_24 ( V_6 , 0xb5 , 0x01 ) ;
if ( F_1 ( V_2 ) ) {
F_24 ( V_6 , 0x02 , V_226 -> V_295 ) ;
F_16 ( V_6 , 0x30 , 1 << 4 , V_226 -> V_296 << 4 ) ;
}
F_15 ( V_6 , 0x40 , 0xc0 | V_226 -> V_297 ) ;
F_15 ( V_6 , 0x46 , 0x98 ) ;
F_15 ( V_6 , 0x6e , V_3 -> V_246 ) ;
F_15 ( V_6 , 0x73 , V_3 -> V_248 ) ;
V_3 -> V_298 ( V_6 ) ;
return F_122 ( V_6 -> V_299 ) ;
}
static void F_123 ( struct V_5 * V_6 )
{
F_15 ( V_6 , 0x41 , 0xd7 ) ;
}
static void F_124 ( struct V_5 * V_6 )
{
F_15 ( V_6 , 0x41 , 0xd0 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
unsigned int V_27 ;
for ( V_27 = 1 ; V_27 < F_86 ( V_2 -> V_24 ) ; ++ V_27 ) {
if ( V_2 -> V_24 [ V_27 ] )
F_126 ( V_2 -> V_24 [ V_27 ] ) ;
}
}
static struct V_9 * F_127 ( struct V_5 * V_6 ,
T_2 V_16 , T_2 V_300 )
{
struct V_9 * V_10 = F_128 ( V_6 ) ;
if ( V_16 )
F_15 ( V_6 , V_300 , V_16 << 1 ) ;
return F_129 ( V_10 -> V_15 , F_14 ( V_6 , V_300 ) >> 1 ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_301 V_302 ;
struct V_303 * V_304 ;
struct V_303 * V_305 ;
unsigned int V_17 ;
V_305 = V_2 -> V_24 [ V_35 ] -> V_306 . V_307 ;
V_304 = F_131 ( V_305 , NULL ) ;
if ( ! V_304 )
return - V_63 ;
F_132 ( V_304 , & V_302 ) ;
F_133 ( V_304 ) ;
V_17 = V_302 . V_308 . V_309 . V_17 ;
if ( V_17 & V_310 )
V_2 -> V_226 . V_289 = 1 ;
if ( V_17 & V_311 )
V_2 -> V_226 . V_288 = 1 ;
if ( V_17 & V_312 )
V_2 -> V_226 . V_290 = 1 ;
if ( V_302 . V_313 == V_314 ) {
V_2 -> V_226 . V_286 = 1 ;
V_2 -> V_226 . V_283 = 1 ;
}
V_2 -> V_226 . V_297 = V_315 ;
V_2 -> V_226 . V_316 [ V_38 ] = 0x42 ;
V_2 -> V_226 . V_316 [ V_39 ] = 0x40 ;
V_2 -> V_226 . V_316 [ V_40 ] = 0x3e ;
V_2 -> V_226 . V_316 [ V_317 ] = 0x38 ;
V_2 -> V_226 . V_316 [ V_318 ] = 0x3c ;
V_2 -> V_226 . V_316 [ V_41 ] = 0x26 ;
V_2 -> V_226 . V_316 [ V_42 ] = 0x32 ;
V_2 -> V_226 . V_316 [ V_43 ] = 0x36 ;
V_2 -> V_226 . V_316 [ V_58 ] = 0x34 ;
V_2 -> V_226 . V_316 [ V_59 ] = 0x30 ;
V_2 -> V_226 . V_316 [ V_60 ] = 0x22 ;
V_2 -> V_226 . V_316 [ V_61 ] = 0x24 ;
V_2 -> V_226 . V_279 = 0 ;
V_2 -> V_226 . V_280 = 0 ;
V_2 -> V_226 . V_281 = - 1 ;
V_2 -> V_226 . V_285 = 1 ;
V_2 -> V_226 . V_284 = 1 ;
V_2 -> V_226 . V_231 = V_319 ;
V_2 -> V_226 . V_227 = V_320 ;
return 0 ;
}
static int F_134 ( struct V_9 * V_10 ,
const struct V_321 * V_136 )
{
static const struct V_87 V_322 =
V_323 ;
struct V_1 * V_2 ;
struct V_324 * V_135 ;
struct V_5 * V_6 ;
unsigned int V_27 ;
T_3 V_36 ;
int V_26 ;
if ( ! F_135 ( V_10 -> V_15 , V_325 ) )
return - V_21 ;
F_136 ( 1 , V_45 , V_10 , L_148 ,
V_10 -> V_16 << 1 ) ;
V_2 = F_137 ( & V_10 -> V_306 , sizeof( * V_2 ) , V_326 ) ;
if ( ! V_2 ) {
F_10 ( V_10 , L_149 ) ;
return - V_327 ;
}
V_2 -> V_24 [ V_35 ] = V_10 ;
V_2 -> V_190 = true ;
V_2 -> V_71 = ~ 0 ;
if ( F_138 ( V_328 ) && V_10 -> V_306 . V_307 ) {
const struct V_329 * V_330 ;
V_330 = F_139 ( V_331 , V_10 -> V_306 . V_307 ) ;
V_2 -> V_3 = V_330 -> V_14 ;
V_26 = F_130 ( V_2 ) ;
if ( V_26 < 0 ) {
F_10 ( V_10 , L_150 ) ;
return V_26 ;
}
} else if ( V_10 -> V_306 . V_332 ) {
struct V_278 * V_226 = V_10 -> V_306 . V_332 ;
V_2 -> V_3 = ( const struct V_81 * ) V_136 -> V_333 ;
V_2 -> V_226 = * V_226 ;
} else {
F_10 ( V_10 , L_151 ) ;
return - V_334 ;
}
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_48 ; ++ V_27 ) {
V_2 -> V_49 [ V_27 ] =
F_140 ( & V_10 -> V_306 , L_152 , V_27 ) ;
if ( F_33 ( V_2 -> V_49 [ V_27 ] ) )
continue;
F_141 ( V_2 -> V_49 [ V_27 ] , 0 ) ;
F_142 ( V_10 , L_153 , V_27 ) ;
}
V_2 -> V_88 = V_322 ;
V_2 -> V_213 = V_67 ( V_2 , V_238 ) ;
V_6 = & V_2 -> V_6 ;
F_143 ( V_6 , V_10 , & V_335 ) ;
snprintf ( V_6 -> V_201 , sizeof( V_6 -> V_201 ) , L_154 ,
V_136 -> V_201 , F_144 ( V_10 -> V_15 ) ,
V_10 -> V_16 ) ;
V_6 -> V_17 |= V_336 ;
if ( V_2 -> V_3 -> type == V_261 ) {
V_36 = F_8 ( V_10 , 0xfb , false ) ;
if ( V_36 != 0x68 ) {
F_56 ( V_6 , L_155 ,
V_10 -> V_16 << 1 ) ;
return - V_334 ;
}
} else {
V_36 = ( F_8 ( V_10 , 0xea , false ) << 8 )
| ( F_8 ( V_10 , 0xeb , false ) << 0 ) ;
if ( V_36 != 0x2051 ) {
F_56 ( V_6 , L_156 ,
V_10 -> V_16 << 1 ) ;
return - V_334 ;
}
}
V_135 = & V_2 -> V_135 ;
F_145 ( V_135 , F_1 ( V_2 ) ? 9 : 8 ) ;
F_146 ( V_135 , & V_337 ,
V_137 , - 128 , 127 , 1 , 0 ) ;
F_146 ( V_135 , & V_337 ,
V_138 , 0 , 255 , 1 , 128 ) ;
F_146 ( V_135 , & V_337 ,
V_139 , 0 , 255 , 1 , 128 ) ;
F_146 ( V_135 , & V_337 ,
V_140 , 0 , 128 , 1 , 0 ) ;
V_2 -> V_82 = F_146 ( V_135 , NULL ,
V_338 , 0 ,
( 1 << V_2 -> V_3 -> V_48 ) - 1 , 0 , 0 ) ;
V_2 -> V_339 =
F_147 ( V_135 , & V_337 ,
V_141 , V_131 ,
0 , V_127 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_340 =
F_148 ( V_135 , & V_341 , NULL ) ;
V_2 -> V_342 =
F_148 ( V_135 , & V_343 , NULL ) ;
V_2 -> V_344 =
F_148 ( V_135 , & V_345 , NULL ) ;
V_6 -> V_299 = V_135 ;
if ( V_135 -> error ) {
V_26 = V_135 -> error ;
goto V_346;
}
V_2 -> V_82 -> V_347 = true ;
V_2 -> V_339 -> V_347 = true ;
if ( F_1 ( V_2 ) )
V_2 -> V_340 -> V_347 = true ;
V_2 -> V_342 -> V_347 = true ;
V_2 -> V_344 -> V_347 = true ;
if ( F_61 ( V_6 ) ) {
V_26 = - V_334 ;
goto V_346;
}
for ( V_27 = 1 ; V_27 < V_348 ; ++ V_27 ) {
if ( ! ( F_35 ( V_27 ) & V_2 -> V_3 -> V_62 ) )
continue;
V_2 -> V_24 [ V_27 ] =
F_127 ( V_6 , V_2 -> V_226 . V_316 [ V_27 ] ,
0xf2 + V_27 ) ;
if ( V_2 -> V_24 [ V_27 ] == NULL ) {
V_26 = - V_327 ;
F_67 ( V_6 , L_157 , V_27 ) ;
goto V_349;
}
}
V_2 -> V_263 = F_149 ( V_10 -> V_201 ) ;
if ( ! V_2 -> V_263 ) {
F_67 ( V_6 , L_158 ) ;
V_26 = - V_327 ;
goto V_349;
}
F_150 ( & V_2 -> V_55 ,
F_37 ) ;
V_2 -> V_170 = V_2 -> V_3 -> V_48
+ ( V_2 -> V_3 -> V_4 ? 2 : 0 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_170 ; ++ V_27 )
V_2 -> V_350 [ V_27 ] . V_17 = V_351 ;
V_2 -> V_350 [ V_2 -> V_170 ] . V_17 = V_352 ;
V_26 = F_151 ( & V_6 -> V_353 , V_2 -> V_170 + 1 ,
V_2 -> V_350 , 0 ) ;
if ( V_26 )
goto V_354;
V_26 = F_121 ( V_6 ) ;
if ( V_26 )
goto V_355;
F_56 ( V_6 , L_159 , V_10 -> V_201 ,
V_10 -> V_16 << 1 , V_10 -> V_15 -> V_201 ) ;
V_26 = F_152 ( V_6 ) ;
if ( V_26 )
goto V_355;
return 0 ;
V_355:
F_153 ( & V_6 -> V_353 ) ;
V_354:
F_154 ( & V_2 -> V_55 ) ;
F_155 ( V_2 -> V_263 ) ;
V_349:
F_125 ( V_2 ) ;
V_346:
F_156 ( V_135 ) ;
return V_26 ;
}
static int F_157 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = F_158 ( V_10 ) ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_154 ( & V_2 -> V_55 ) ;
F_155 ( V_2 -> V_263 ) ;
F_159 ( V_6 ) ;
F_160 ( V_6 ) ;
F_153 ( & V_6 -> V_353 ) ;
F_125 ( F_2 ( V_6 ) ) ;
F_156 ( V_6 -> V_299 ) ;
return 0 ;
}
