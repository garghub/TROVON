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
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_48 ; ++ V_27 )
F_33 ( V_2 -> V_49 [ V_27 ] , V_47 & F_34 ( V_27 ) ) ;
F_35 ( & V_2 -> V_6 , V_50 , & V_47 ) ;
}
static void F_36 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_37 ( V_52 ) ;
struct V_1 * V_2 = F_3 ( V_54 , struct V_1 ,
V_55 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_31 ( 2 , V_45 , V_6 , L_4 , V_46 ) ;
F_32 ( V_2 , V_2 -> V_56 . V_57 ) ;
}
static inline int F_38 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_58 , V_34 ) ;
}
static T_3 F_39 ( struct V_5 * V_6 , T_2 V_34 , T_3 V_37 )
{
return ( ( F_38 ( V_6 , V_34 ) << 8 ) | F_38 ( V_6 , V_34 + 1 ) ) & V_37 ;
}
static inline int F_40 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_58 , V_34 , V_36 ) ;
}
static inline int F_41 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_40 ( V_6 , V_34 , ( F_38 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_42 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_59 , V_34 , V_36 ) ;
}
static inline int F_43 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_60 , V_34 ) ;
}
static T_3 F_44 ( struct V_5 * V_6 , T_2 V_34 , T_3 V_37 )
{
return ( ( F_43 ( V_6 , V_34 ) << 8 ) | F_43 ( V_6 , V_34 + 1 ) ) & V_37 ;
}
static inline int F_45 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_60 , V_34 , V_36 ) ;
}
static inline int F_46 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_45 ( V_6 , V_34 , ( F_43 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_47 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_11 ( V_2 , V_61 , V_34 ) ;
}
static inline int F_48 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_12 ( V_2 , V_61 , V_34 , V_36 ) ;
}
static int F_49 ( struct V_5 * V_6 , unsigned int V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned int V_23 = V_34 >> 8 ;
if ( ! ( F_34 ( V_23 ) & V_2 -> V_3 -> V_62 ) )
return - V_63 ;
V_34 &= 0xff ;
return F_11 ( V_2 , V_23 , V_34 ) ;
}
static int F_50 ( struct V_5 * V_6 , unsigned int V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned int V_23 = V_34 >> 8 ;
if ( ! ( F_34 ( V_23 ) & V_2 -> V_3 -> V_62 ) )
return - V_63 ;
V_34 &= 0xff ;
return F_12 ( V_2 , V_23 , V_34 , V_36 ) ;
}
static void F_51 ( struct V_5 * V_6 ,
const struct V_64 * V_65 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_65 [ V_27 ] . V_34 != V_66 ; V_27 ++ )
F_50 ( V_6 , V_65 [ V_27 ] . V_34 , V_65 [ V_27 ] . V_36 ) ;
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
static inline bool F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_71 == V_72 ||
V_2 -> V_71 == V_73 ;
}
static inline bool F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_71 == V_74 ||
V_2 -> V_71 == V_75 ||
V_2 -> V_71 == V_76 ||
V_2 -> V_71 == V_77 ;
}
static void F_54 ( struct V_5 * V_6 )
{
F_55 ( V_6 , L_5 ) ;
F_55 ( V_6 , L_6 ) ;
F_55 ( V_6 , L_7 ) ;
F_55 ( V_6 , L_8 ) ;
F_55 ( V_6 , L_9 ) ;
F_55 ( V_6 , L_10 ) ;
F_55 ( V_6 , L_11 ) ;
F_55 ( V_6 , L_12 ) ;
F_55 ( V_6 , L_13 ) ;
F_55 ( V_6 , L_14 ) ;
F_55 ( V_6 , L_15 ) ;
F_55 ( V_6 , L_16 ) ;
F_55 ( V_6 , L_17 ) ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_78 * V_34 )
{
int V_79 ;
V_79 = F_49 ( V_6 , V_34 -> V_34 ) ;
if ( V_79 < 0 ) {
F_55 ( V_6 , L_18 , V_34 -> V_34 ) ;
F_54 ( V_6 ) ;
return V_79 ;
}
V_34 -> V_80 = 1 ;
V_34 -> V_36 = V_79 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
const struct V_78 * V_34 )
{
int V_79 ;
V_79 = F_50 ( V_6 , V_34 -> V_34 , V_34 -> V_36 ) ;
if ( V_79 < 0 ) {
F_55 ( V_6 , L_18 , V_34 -> V_34 ) ;
F_54 ( V_6 ) ;
return V_79 ;
}
return 0 ;
}
static unsigned int F_58 ( struct V_5 * V_6 )
{
T_2 V_25 = F_14 ( V_6 , 0x6f ) ;
return ( ( V_25 & 0x10 ) >> 4 )
| ( ( V_25 & 0x08 ) >> 2 )
| ( ( V_25 & 0x04 ) << 0 )
| ( ( V_25 & 0x02 ) << 2 ) ;
}
static unsigned int F_59 ( struct V_5 * V_6 )
{
T_2 V_25 = F_14 ( V_6 , 0x6f ) ;
return V_25 & 1 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
return F_61 ( V_2 -> V_82 ,
V_3 -> V_83 ( V_6 ) ) ;
}
static int F_62 ( struct V_5 * V_6 ,
T_2 V_84 ,
const struct V_85 * V_86 ,
const struct V_87 * V_88 )
{
int V_27 ;
for ( V_27 = 0 ; V_86 [ V_27 ] . V_88 . V_89 . V_90 ; V_27 ++ ) {
if ( ! F_63 ( V_88 , & V_86 [ V_27 ] . V_88 ,
F_53 ( V_6 ) ? 250000 : 1000000 ) )
continue;
F_15 ( V_6 , 0x00 , V_86 [ V_27 ] . V_91 ) ;
F_15 ( V_6 , 0x01 , ( V_86 [ V_27 ] . V_92 << 4 ) +
V_84 ) ;
return 0 ;
}
return - 1 ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_26 ;
F_31 ( 1 , V_45 , V_6 , L_19 , V_46 ) ;
if ( F_1 ( V_2 ) ) {
F_15 ( V_6 , 0x16 , 0x43 ) ;
F_15 ( V_6 , 0x17 , 0x5a ) ;
}
F_46 ( V_6 , 0x81 , 0x10 , 0x00 ) ;
F_45 ( V_6 , 0x8f , 0x00 ) ;
F_45 ( V_6 , 0x90 , 0x00 ) ;
F_45 ( V_6 , 0xa2 , 0x00 ) ;
F_45 ( V_6 , 0xa3 , 0x00 ) ;
F_45 ( V_6 , 0xa4 , 0x00 ) ;
F_45 ( V_6 , 0xa5 , 0x00 ) ;
F_45 ( V_6 , 0xa6 , 0x00 ) ;
F_45 ( V_6 , 0xa7 , 0x00 ) ;
F_45 ( V_6 , 0xab , 0x00 ) ;
F_45 ( V_6 , 0xac , 0x00 ) ;
if ( F_52 ( V_6 ) ) {
V_26 = F_62 ( V_6 ,
0x01 , V_93 , V_88 ) ;
if ( V_26 )
V_26 = F_62 ( V_6 ,
0x02 , V_94 , V_88 ) ;
} else if ( F_53 ( V_6 ) ) {
V_26 = F_62 ( V_6 ,
0x05 , V_95 , V_88 ) ;
if ( V_26 )
V_26 = F_62 ( V_6 ,
0x06 , V_96 , V_88 ) ;
} else {
F_31 ( 2 , V_45 , V_6 , L_20 ,
V_46 , V_2 -> V_71 ) ;
V_26 = - 1 ;
}
return V_26 ;
}
static void F_65 ( struct V_5 * V_6 ,
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
if ( F_52 ( V_6 ) ) {
F_15 ( V_6 , 0x00 , 0x07 ) ;
F_15 ( V_6 , 0x01 , 0x02 ) ;
F_46 ( V_6 , 0x81 , 0x10 , 0x10 ) ;
if ( F_13 ( V_2 , V_35 ,
0x16 , 2 , V_111 ) )
F_66 ( V_6 , L_22 ) ;
F_45 ( V_6 , 0xa2 , ( V_98 >> 4 ) & 0xff ) ;
F_45 ( V_6 , 0xa3 , ( ( V_98 & 0x0f ) << 4 ) |
( ( V_101 >> 8 ) & 0x0f ) ) ;
F_45 ( V_6 , 0xa4 , V_101 & 0xff ) ;
F_45 ( V_6 , 0xa5 , ( V_103 >> 4 ) & 0xff ) ;
F_45 ( V_6 , 0xa6 , ( ( V_103 & 0xf ) << 4 ) |
( ( V_105 >> 8 ) & 0xf ) ) ;
F_45 ( V_6 , 0xa7 , V_105 & 0xff ) ;
} else if ( F_53 ( V_6 ) ) {
F_15 ( V_6 , 0x00 , 0x02 ) ;
F_15 ( V_6 , 0x01 , 0x06 ) ;
} else {
F_31 ( 2 , V_45 , V_6 , L_20 ,
V_46 , V_2 -> V_71 ) ;
}
F_45 ( V_6 , 0x8f , ( V_108 >> 8 ) & 0x7 ) ;
F_45 ( V_6 , 0x90 , V_108 & 0xff ) ;
F_45 ( V_6 , 0xab , ( V_97 >> 4 ) & 0xff ) ;
F_45 ( V_6 , 0xac , ( V_97 & 0x0f ) << 4 ) ;
}
static void F_67 ( struct V_5 * V_6 , bool V_112 , T_3 V_113 , T_3 V_114 , T_3 V_115 )
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
V_116 [ 0 ] = ( F_43 ( V_6 , 0x77 ) & 0xc0 ) | ( ( V_113 & 0x3f0 ) >> 4 ) ;
V_116 [ 1 ] = ( ( V_113 & 0x00f ) << 4 ) | ( ( V_114 & 0x3c0 ) >> 6 ) ;
V_116 [ 2 ] = ( ( V_114 & 0x03f ) << 2 ) | ( ( V_115 & 0x300 ) >> 8 ) ;
V_116 [ 3 ] = V_115 & 0x0ff ;
if ( F_13 ( V_2 , V_60 ,
0x77 , 4 , V_116 ) )
F_66 ( V_6 , L_26 , V_46 ) ;
}
static void F_68 ( struct V_5 * V_6 , bool V_117 , T_3 V_118 , T_3 V_119 , T_3 V_120 )
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
F_66 ( V_6 , L_28 , V_46 ) ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
bool V_124 = F_14 ( V_6 , 0x02 ) & 0x02 ;
bool V_125 = F_38 ( V_6 , 0x05 ) & 0x80 ;
F_31 ( 2 , V_45 , V_6 , L_29 ,
V_46 , V_2 -> V_126 ,
V_124 , V_125 ) ;
F_68 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
F_67 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
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
if ( V_2 -> V_88 . V_89 . V_17 & V_128 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
} else {
F_16 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_53 ( V_6 ) && V_124 ) {
F_67 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_68 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_67 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_129 :
if ( V_2 -> V_71 == V_73 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x20 ) ;
break;
}
F_16 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
break;
case V_130 :
if ( V_2 -> V_71 == V_73 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x60 ) ;
break;
}
F_16 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_52 ( V_6 ) || V_125 )
break;
if ( V_124 ) {
F_67 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_68 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_67 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_70 ( struct V_131 * V_132 )
{
struct V_5 * V_6 =
& F_3 ( V_132 -> V_133 , struct V_1 , V_134 ) -> V_6 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
switch ( V_132 -> V_135 ) {
case V_136 :
F_45 ( V_6 , 0x3c , V_132 -> V_36 ) ;
return 0 ;
case V_137 :
F_45 ( V_6 , 0x3a , V_132 -> V_36 ) ;
return 0 ;
case V_138 :
F_45 ( V_6 , 0x3b , V_132 -> V_36 ) ;
return 0 ;
case V_139 :
F_45 ( V_6 , 0x3d , V_132 -> V_36 ) ;
return 0 ;
case V_140 :
V_2 -> V_126 = V_132 -> V_36 ;
F_69 ( V_6 ) ;
return 0 ;
case V_141 :
if ( ! F_1 ( V_2 ) )
return - V_63 ;
F_24 ( V_6 , 0xc8 , V_132 -> V_36 ) ;
return 0 ;
case V_142 :
F_46 ( V_6 , 0xbf , 0x04 , V_132 -> V_36 << 2 ) ;
return 0 ;
case V_143 :
F_45 ( V_6 , 0xc0 , ( V_132 -> V_36 & 0xff0000 ) >> 16 ) ;
F_45 ( V_6 , 0xc1 , ( V_132 -> V_36 & 0x00ff00 ) >> 8 ) ;
F_45 ( V_6 , 0xc2 , ( T_2 ) ( V_132 -> V_36 & 0x0000ff ) ) ;
return 0 ;
}
return - V_63 ;
}
static inline bool F_71 ( struct V_5 * V_6 )
{
return F_14 ( V_6 , 0x0c ) & 0x24 ;
}
static inline bool F_72 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return ! ( F_14 ( V_6 , 0x6a ) & ( 0x10 >> V_2 -> V_71 ) ) ;
}
static inline bool F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
return ( F_14 ( V_6 , 0x6a ) & V_3 -> V_144 ) != V_3 -> V_144 ;
}
static inline bool F_74 ( struct V_5 * V_6 )
{
return F_38 ( V_6 , 0x05 ) & 0x80 ;
}
static inline bool F_75 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_1 ( V_2 ) )
return false ;
return ( ( F_43 ( V_6 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_76 ( struct V_5 * V_6 )
{
return ! ( F_43 ( V_6 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_77 ( struct V_5 * V_6 )
{
bool V_79 ;
V_79 = F_71 ( V_6 ) ;
V_79 |= F_76 ( V_6 ) ;
V_79 |= F_75 ( V_6 ) ;
if ( F_53 ( V_6 ) ) {
V_79 |= F_73 ( V_6 ) ;
V_79 |= F_72 ( V_6 ) ;
}
return V_79 ;
}
static inline bool F_78 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( ! F_1 ( V_2 ) )
return false ;
return F_14 ( V_6 , 0x12 ) & 0x01 ;
}
static inline bool F_79 ( struct V_5 * V_6 )
{
return F_43 ( V_6 , 0xff ) & 0x10 ;
}
static int F_80 ( struct V_5 * V_6 , T_4 * V_145 )
{
* V_145 = 0 ;
* V_145 |= F_71 ( V_6 ) ? V_146 : 0 ;
* V_145 |= F_77 ( V_6 ) ? V_147 : 0 ;
if ( ! F_79 ( V_6 ) && F_78 ( V_6 ) )
* V_145 |= F_53 ( V_6 ) ?
V_148 : V_149 ;
F_31 ( 1 , V_45 , V_6 , L_30 , V_46 , * V_145 ) ;
return 0 ;
}
static int F_81 ( struct V_5 * V_6 ,
struct V_150 * V_151 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_152 = ( V_110 * 8 ) / V_151 -> V_153 ;
T_4 V_154 ;
int V_27 ;
for ( V_27 = 0 ; V_155 [ V_27 ] . V_89 . V_97 ; V_27 ++ ) {
if ( F_6 ( & V_155 [ V_27 ] . V_89 ) != V_151 -> V_156 + 1 )
continue;
if ( V_155 [ V_27 ] . V_89 . V_106 != V_151 -> V_157 )
continue;
V_154 = V_152 * F_4 ( & V_155 [ V_27 ] . V_89 ) ;
if ( ( V_154 < V_155 [ V_27 ] . V_89 . V_109 + 1000000 ) &&
( V_154 > V_155 [ V_27 ] . V_89 . V_109 - 1000000 ) ) {
* V_88 = V_155 [ V_27 ] ;
return 0 ;
}
}
if ( F_82 ( V_151 -> V_156 + 1 , V_152 , V_151 -> V_157 ,
( V_151 -> V_158 == '+' ? V_159 : 0 ) |
( V_151 -> V_160 == '+' ? V_161 : 0 ) ,
false , V_88 ) )
return 0 ;
if ( F_83 ( V_151 -> V_156 + 1 , V_152 , V_151 -> V_157 ,
( V_151 -> V_158 == '+' ? V_159 : 0 ) |
( V_151 -> V_160 == '+' ? V_161 : 0 ) ,
false , V_2 -> V_162 , V_88 ) )
return 0 ;
F_31 ( 2 , V_45 , V_6 ,
L_31 ,
V_46 , V_151 -> V_157 , V_151 -> V_156 , V_151 -> V_153 ,
V_151 -> V_158 , V_151 -> V_160 ) ;
return - 1 ;
}
static int F_84 ( struct V_5 * V_6 , struct V_150 * V_151 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
T_2 V_163 ;
if ( F_76 ( V_6 ) || F_75 ( V_6 ) ) {
F_31 ( 2 , V_45 , V_6 , L_32 , V_46 ) ;
return - 1 ;
}
V_151 -> V_153 = F_44 ( V_6 , 0xb1 , 0x3fff ) ;
V_151 -> V_156 = F_44 ( V_6 , V_3 -> V_164 , 0x7ff ) ;
V_151 -> V_157 = F_43 ( V_6 , 0xb3 ) >> 3 ;
V_151 -> V_165 = F_14 ( V_6 , 0x12 ) & 0x10 ;
if ( F_1 ( V_2 ) ) {
V_163 = F_43 ( V_6 , 0xb5 ) ;
if ( ( V_163 & 0x03 ) == 0x01 ) {
V_151 -> V_158 = V_163 & 0x10
? ( V_163 & 0x08 ? '+' : '-' ) : 'x' ;
V_151 -> V_160 = V_163 & 0x40
? ( V_163 & 0x20 ? '+' : '-' ) : 'x' ;
} else {
V_151 -> V_158 = 'x' ;
V_151 -> V_160 = 'x' ;
}
} else {
V_163 = F_38 ( V_6 , 0x05 ) ;
V_151 -> V_158 = V_163 & 0x20 ? '+' : '-' ;
V_151 -> V_160 = V_163 & 0x10 ? '+' : '-' ;
}
if ( F_76 ( V_6 ) || F_75 ( V_6 ) ) {
F_31 ( 2 , V_45 , V_6 ,
L_33 , V_46 ) ;
return - 1 ;
}
if ( V_151 -> V_156 < 239 || V_151 -> V_153 < 8 || V_151 -> V_153 == 0x3fff ) {
F_31 ( 2 , V_45 , V_6 , L_34 , V_46 ) ;
memset ( V_151 , 0 , sizeof( struct V_150 ) ) ;
return - 1 ;
}
F_31 ( 2 , V_45 , V_6 ,
L_35 ,
V_46 , V_151 -> V_156 , V_151 -> V_153 , V_151 -> V_157 ,
V_151 -> V_158 , V_151 -> V_160 ,
V_151 -> V_165 ? L_36 : L_37 ) ;
return 0 ;
}
static int F_85 ( struct V_5 * V_6 ,
struct V_166 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_88 -> V_167 >= F_86 ( V_155 ) - 1 )
return - V_63 ;
if ( V_88 -> V_168 >= V_2 -> V_169 )
return - V_63 ;
memset ( V_88 -> V_170 , 0 , sizeof( V_88 -> V_170 ) ) ;
V_88 -> V_88 = V_155 [ V_88 -> V_167 ] ;
return 0 ;
}
static int F_87 ( struct V_5 * V_6 ,
struct V_171 * V_172 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_172 -> V_168 >= V_2 -> V_169 )
return - V_63 ;
V_172 -> type = V_173 ;
V_172 -> V_89 . V_174 = 1920 ;
V_172 -> V_89 . V_175 = 1200 ;
V_172 -> V_89 . V_176 = 25000000 ;
switch ( V_172 -> V_168 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_172 -> V_89 . V_177 = 225000000 ;
break;
case V_72 :
case V_73 :
default:
V_172 -> V_89 . V_177 = 170000000 ;
break;
}
V_172 -> V_89 . V_178 = V_179 | V_180 |
V_181 | V_182 ;
V_172 -> V_89 . V_183 = V_184 |
V_185 | V_186 ;
return 0 ;
}
static void F_88 ( struct V_5 * V_6 ,
struct V_87 * V_88 )
{
int V_27 ;
for ( V_27 = 0 ; V_155 [ V_27 ] . V_89 . V_90 ; V_27 ++ ) {
if ( F_63 ( V_88 , & V_155 [ V_27 ] ,
F_53 ( V_6 ) ? 250000 : 1000000 ) ) {
* V_88 = V_155 [ V_27 ] ;
break;
}
}
}
static unsigned int F_89 ( struct V_5 * V_6 )
{
unsigned int V_187 ;
int V_188 , V_189 ;
V_188 = F_38 ( V_6 , 0x06 ) ;
V_189 = F_38 ( V_6 , 0x3b ) ;
if ( V_188 < 0 || V_189 < 0 )
return 0 ;
V_187 = V_188 * 1000000 + ( ( V_189 & 0x30 ) >> 4 ) * 250000 ;
if ( F_74 ( V_6 ) ) {
unsigned V_190 = ( ( F_38 ( V_6 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_187 = V_187 * 8 / V_190 ;
}
return V_187 ;
}
static unsigned int F_90 ( struct V_5 * V_6 )
{
int V_188 , V_189 ;
V_188 = F_38 ( V_6 , 0x51 ) ;
V_189 = F_38 ( V_6 , 0x52 ) ;
if ( V_188 < 0 || V_189 < 0 )
return 0 ;
return ( ( V_188 << 1 ) | ( V_189 >> 7 ) ) * 1000000 + ( V_189 & 0x7f ) * 1000000 / 128 ;
}
static int F_91 ( struct V_5 * V_6 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
struct V_7 * V_89 = & V_88 -> V_89 ;
struct V_150 V_151 ;
if ( ! V_88 )
return - V_63 ;
memset ( V_88 , 0 , sizeof( struct V_87 ) ) ;
if ( F_77 ( V_6 ) ) {
V_2 -> V_191 = true ;
F_31 ( 1 , V_45 , V_6 , L_38 , V_46 ) ;
return - V_192 ;
}
if ( F_84 ( V_6 , & V_151 ) ) {
F_31 ( 1 , V_45 , V_6 , L_39 , V_46 ) ;
return - V_192 ;
}
V_89 -> V_165 = V_151 . V_165 ?
V_193 : V_194 ;
if ( F_53 ( V_6 ) ) {
V_88 -> type = V_173 ;
V_89 -> V_90 = F_39 ( V_6 , 0x07 , V_3 -> V_195 ) ;
V_89 -> V_97 = F_39 ( V_6 , 0x09 , V_3 -> V_196 ) ;
V_89 -> V_109 = V_3 -> V_197 ( V_6 ) ;
V_89 -> V_102 = F_39 ( V_6 , 0x20 , V_3 -> V_198 ) ;
V_89 -> V_99 = F_39 ( V_6 , 0x22 , V_3 -> V_199 ) ;
V_89 -> V_100 = F_39 ( V_6 , 0x24 , V_3 -> V_200 ) ;
V_89 -> V_104 = F_39 ( V_6 , 0x2a ,
V_3 -> V_201 ) / 2 ;
V_89 -> V_106 = F_39 ( V_6 , 0x2e , V_3 -> V_202 ) / 2 ;
V_89 -> V_107 = F_39 ( V_6 , 0x32 ,
V_3 -> V_203 ) / 2 ;
V_89 -> V_204 = ( ( F_38 ( V_6 , 0x05 ) & 0x10 ) ? V_161 : 0 ) |
( ( F_38 ( V_6 , 0x05 ) & 0x20 ) ? V_159 : 0 ) ;
if ( V_89 -> V_165 == V_193 ) {
V_89 -> V_97 += F_39 ( V_6 , 0x0b ,
V_3 -> V_205 ) ;
V_89 -> V_206 = F_39 ( V_6 , 0x2c ,
V_3 -> V_207 ) / 2 ;
V_89 -> V_208 = F_39 ( V_6 , 0x30 ,
V_3 -> V_209 ) / 2 ;
V_89 -> V_210 = F_39 ( V_6 , 0x34 ,
V_3 -> V_211 ) / 2 ;
}
F_88 ( V_6 , V_88 ) ;
} else {
if ( ! F_81 ( V_6 , & V_151 , V_88 ) )
goto V_212;
V_151 . V_157 += 1 ;
F_31 ( 1 , V_45 , V_6 , L_40 , V_46 , V_151 . V_157 ) ;
if ( ! F_81 ( V_6 , & V_151 , V_88 ) )
goto V_212;
V_151 . V_157 -= 2 ;
F_31 ( 1 , V_45 , V_6 , L_41 , V_46 , V_151 . V_157 ) ;
if ( F_81 ( V_6 , & V_151 , V_88 ) ) {
if ( V_2 -> V_191 ) {
F_31 ( 1 , V_45 , V_6 , L_42 , V_46 ) ;
F_46 ( V_6 , 0x86 , 0x06 , 0x00 ) ;
F_46 ( V_6 , 0x86 , 0x06 , 0x04 ) ;
F_46 ( V_6 , 0x86 , 0x06 , 0x02 ) ;
V_2 -> V_191 = false ;
return - V_192 ;
}
F_31 ( 1 , V_45 , V_6 , L_43 , V_46 ) ;
return - V_213 ;
}
V_2 -> V_191 = true ;
}
V_212:
if ( F_77 ( V_6 ) ) {
F_31 ( 1 , V_45 , V_6 , L_44 , V_46 ) ;
memset ( V_88 , 0 , sizeof( struct V_87 ) ) ;
return - V_192 ;
}
if ( ( F_52 ( V_6 ) && V_89 -> V_109 > 170000000 ) ||
( F_53 ( V_6 ) && V_89 -> V_109 > 225000000 ) ) {
F_31 ( 1 , V_45 , V_6 , L_45 ,
V_46 , ( T_4 ) V_89 -> V_109 ) ;
return - V_213 ;
}
if ( V_45 > 1 )
F_92 ( V_6 -> V_214 , L_46 ,
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
if ( F_63 ( & V_2 -> V_88 , V_88 , 0 ) ) {
F_31 ( 1 , V_45 , V_6 , L_47 , V_46 ) ;
return 0 ;
}
V_89 = & V_88 -> V_89 ;
if ( ( F_52 ( V_6 ) && V_89 -> V_109 > 170000000 ) ||
( F_53 ( V_6 ) && V_89 -> V_109 > 225000000 ) ) {
F_31 ( 1 , V_45 , V_6 , L_45 ,
V_46 , ( T_4 ) V_89 -> V_109 ) ;
return - V_213 ;
}
F_88 ( V_6 , V_88 ) ;
V_2 -> V_88 = * V_88 ;
F_46 ( V_6 , 0x91 , 0x40 , V_89 -> V_165 ? 0x40 : 0x00 ) ;
V_26 = F_64 ( V_6 , V_88 ) ;
if ( V_26 ) {
F_65 ( V_6 , V_89 ) ;
}
F_69 ( V_6 ) ;
if ( V_45 > 1 )
F_92 ( V_6 -> V_214 , L_48 ,
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
static void F_95 ( struct V_5 * V_6 , bool V_215 )
{
F_40 ( V_6 , 0x01 , V_215 ? 0x00 : 0x78 ) ;
}
static void F_96 ( struct V_5 * V_6 , bool V_215 )
{
F_40 ( V_6 , 0x83 , V_215 ? 0xfe : 0xff ) ;
}
static void F_97 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_52 ( V_6 ) ) {
F_15 ( V_6 , 0x15 , 0xb0 ) ;
} else if ( F_53 ( V_6 ) ) {
F_41 ( V_6 , 0x00 , 0x03 , V_2 -> V_71 ) ;
V_2 -> V_3 -> V_216 ( V_6 , true ) ;
F_15 ( V_6 , 0x15 , 0xa0 ) ;
F_41 ( V_6 , 0x1a , 0x10 , 0x00 ) ;
} else {
F_31 ( 2 , V_45 , V_6 , L_20 ,
V_46 , V_2 -> V_71 ) ;
}
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_41 ( V_6 , 0x1a , 0x10 , 0x10 ) ;
F_99 ( 16 ) ;
F_15 ( V_6 , 0x15 , 0xbe ) ;
V_2 -> V_3 -> V_216 ( V_6 , false ) ;
}
static void F_100 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
if ( F_52 ( V_6 ) ) {
F_51 ( V_6 , V_3 -> V_217 [ 0 ] ) ;
F_24 ( V_6 , 0x00 , 0x08 ) ;
F_24 ( V_6 , 0x01 , 0x06 ) ;
F_24 ( V_6 , 0xc8 , 0x00 ) ;
} else if ( F_53 ( V_6 ) ) {
F_40 ( V_6 , 0x00 , V_2 -> V_71 & 0x03 ) ;
F_51 ( V_6 , V_3 -> V_217 [ 1 ] ) ;
if ( F_1 ( V_2 ) ) {
F_24 ( V_6 , 0x00 , 0xff ) ;
F_24 ( V_6 , 0x01 , 0xfe ) ;
F_24 ( V_6 , 0xc8 , 0x40 ) ;
}
F_45 ( V_6 , 0x3e , 0x00 ) ;
F_45 ( V_6 , 0xc3 , 0x39 ) ;
F_45 ( V_6 , 0x40 , 0x80 ) ;
} else {
F_31 ( 2 , V_45 , V_6 , L_20 ,
V_46 , V_2 -> V_71 ) ;
}
}
static int F_101 ( struct V_5 * V_6 ,
T_4 V_218 , T_4 V_219 , T_4 V_220 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_31 ( 2 , V_45 , V_6 , L_49 ,
V_46 , V_218 , V_2 -> V_71 ) ;
if ( V_218 == V_2 -> V_71 )
return 0 ;
if ( V_218 > V_2 -> V_3 -> V_221 )
return - V_63 ;
V_2 -> V_71 = V_218 ;
F_98 ( V_6 ) ;
F_100 ( V_6 ) ;
F_97 ( V_6 ) ;
F_35 ( V_6 , V_222 ,
( void * ) & V_223 ) ;
return 0 ;
}
static int F_102 ( struct V_5 * V_6 ,
struct V_224 * V_225 ,
struct V_226 * V_68 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_68 -> V_167 >= V_2 -> V_3 -> V_69 )
return - V_63 ;
V_68 -> V_68 = V_2 -> V_3 -> V_70 [ V_68 -> V_167 ] . V_68 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_227 * V_228 )
{
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
V_228 -> V_90 = V_2 -> V_88 . V_89 . V_90 ;
V_228 -> V_97 = V_2 -> V_88 . V_89 . V_97 ;
V_228 -> V_229 = V_230 ;
V_228 -> V_231 = V_232 ;
if ( V_2 -> V_88 . V_89 . V_17 & V_128 )
V_228 -> V_231 = ( V_2 -> V_88 . V_89 . V_97 <= 576 ) ?
V_233 : V_234 ;
}
static unsigned int F_104 ( struct V_1 * V_2 )
{
#define F_105 ( V_188 , V_189 , T_5 , T_6 , T_7 , T_8 ) { \
ADV76XX_OP_CH_SEL_##a, ADV76XX_OP_CH_SEL_##b, ADV76XX_OP_CH_SEL_##c, \
ADV76XX_OP_CH_SEL_##d, ADV76XX_OP_CH_SEL_##e, ADV76XX_OP_CH_SEL_##f }
#define F_106 ( T_9 ) [ADV7604_BUS_ORDER_##x]
static const unsigned int V_235 [ 6 ] [ 6 ] = {
F_106 ( V_236 ) = F_105 ( V_237 , V_238 , V_239 , V_236 , V_240 , V_241 ) ,
F_106 ( V_238 ) = F_105 ( V_239 , V_236 , V_237 , V_238 , V_241 , V_240 ) ,
F_106 ( V_241 ) = F_105 ( V_238 , V_237 , V_240 , V_241 , V_239 , V_236 ) ,
F_106 ( V_239 ) = F_105 ( V_241 , V_240 , V_236 , V_239 , V_238 , V_237 ) ,
F_106 ( V_240 ) = F_105 ( V_240 , V_241 , V_238 , V_237 , V_236 , V_239 ) ,
F_106 ( V_237 ) = F_105 ( V_236 , V_239 , V_241 , V_240 , V_237 , V_238 ) ,
} ;
return V_235 [ V_2 -> V_242 . V_243 ] [ V_2 -> V_228 -> V_235 >> 5 ] ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_16 ( V_6 , 0x02 , 0x02 ,
V_2 -> V_228 -> V_244 ? V_245 : 0 ) ;
F_15 ( V_6 , 0x03 , V_2 -> V_228 -> V_246 |
V_2 -> V_242 . V_247 ) ;
F_16 ( V_6 , 0x04 , 0xe0 , F_104 ( V_2 ) ) ;
F_16 ( V_6 , 0x05 , 0x01 ,
V_2 -> V_228 -> V_248 ? V_249 : 0 ) ;
}
static int F_108 ( struct V_5 * V_6 ,
struct V_224 * V_225 ,
struct V_250 * V_228 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_228 -> V_168 != V_2 -> V_169 )
return - V_63 ;
F_103 ( V_2 , & V_228 -> V_228 ) ;
if ( V_228 -> V_251 == V_252 ) {
struct V_227 * V_253 ;
V_253 = F_109 ( V_6 , V_225 , V_228 -> V_168 ) ;
V_228 -> V_228 . V_68 = V_253 -> V_68 ;
} else {
V_228 -> V_228 . V_68 = V_2 -> V_228 -> V_68 ;
}
return 0 ;
}
static int F_110 ( struct V_5 * V_6 ,
struct V_224 * V_225 ,
struct V_250 * V_228 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_67 * V_3 ;
if ( V_228 -> V_168 != V_2 -> V_169 )
return - V_63 ;
V_3 = V_67 ( V_2 , V_228 -> V_228 . V_68 ) ;
if ( V_3 == NULL )
V_3 = V_67 ( V_2 , V_254 ) ;
F_103 ( V_2 , & V_228 -> V_228 ) ;
V_228 -> V_228 . V_68 = V_3 -> V_68 ;
if ( V_228 -> V_251 == V_252 ) {
struct V_227 * V_253 ;
V_253 = F_109 ( V_6 , V_225 , V_228 -> V_168 ) ;
V_253 -> V_68 = V_228 -> V_228 . V_68 ;
} else {
V_2 -> V_228 = V_3 ;
F_107 ( V_2 ) ;
}
return 0 ;
}
static int F_111 ( struct V_5 * V_6 , T_4 V_145 , bool * V_255 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
const T_2 V_256 = F_14 ( V_6 , 0x43 ) ;
const T_2 V_257 = F_14 ( V_6 , 0x6b ) ;
const T_2 V_258 = F_14 ( V_6 , 0x70 ) ;
T_2 V_259 ;
T_2 V_260 ;
T_2 V_261 ;
if ( V_256 )
F_15 ( V_6 , 0x44 , V_256 ) ;
if ( V_258 )
F_15 ( V_6 , 0x71 , V_258 ) ;
if ( V_257 )
F_15 ( V_6 , 0x6c , V_257 ) ;
F_31 ( 2 , V_45 , V_6 , L_50 , V_46 ) ;
V_260 = V_256 & 0x98 ;
V_259 = F_53 ( V_6 )
? V_257 & V_3 -> V_262
: 0 ;
if ( V_260 || V_259 ) {
F_31 ( 1 , V_45 , V_6 ,
L_51 ,
V_46 , V_260 , V_259 ) ;
F_35 ( V_6 , V_222 ,
( void * ) & V_223 ) ;
if ( V_255 )
* V_255 = true ;
}
if ( V_257 & 0x01 ) {
F_31 ( 1 , V_45 , V_6 , L_52 , V_46 ,
( F_14 ( V_6 , 0x6a ) & 0x01 ) ? L_53 : L_54 ) ;
F_69 ( V_6 ) ;
if ( V_255 )
* V_255 = true ;
}
V_261 = F_14 ( V_6 , 0x70 ) & V_3 -> V_263 ;
if ( V_261 ) {
F_31 ( 1 , V_45 , V_6 , L_55 , V_46 , V_261 ) ;
F_15 ( V_6 , 0x71 , V_261 ) ;
F_60 ( V_6 ) ;
if ( V_255 )
* V_255 = true ;
}
return 0 ;
}
static int F_112 ( struct V_5 * V_6 , struct V_264 * V_56 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 * V_14 = NULL ;
memset ( V_56 -> V_170 , 0 , sizeof( V_56 -> V_170 ) ) ;
switch ( V_56 -> V_168 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
if ( V_2 -> V_56 . V_57 & ( 1 << V_56 -> V_168 ) )
V_14 = V_2 -> V_56 . V_56 ;
break;
default:
return - V_63 ;
}
if ( V_56 -> V_265 == 0 && V_56 -> V_266 == 0 ) {
V_56 -> V_266 = V_14 ? V_2 -> V_56 . V_266 : 0 ;
return 0 ;
}
if ( V_14 == NULL )
return - V_267 ;
if ( V_56 -> V_265 >= V_2 -> V_56 . V_266 )
return - V_63 ;
if ( V_56 -> V_265 + V_56 -> V_266 > V_2 -> V_56 . V_266 )
V_56 -> V_266 = V_2 -> V_56 . V_266 - V_56 -> V_265 ;
memcpy ( V_56 -> V_56 , V_14 + V_56 -> V_265 * 128 , V_56 -> V_266 * 128 ) ;
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
int V_268 = 0x80 + T_6 ;
do {
T_2 V_269 = V_56 [ V_27 ] >> 5 ;
T_2 V_44 = V_56 [ V_27 ] & 0x1f ;
if ( ( V_269 == 3 ) && ( V_44 >= 5 ) )
return V_27 + 4 ;
V_27 += V_44 + 1 ;
} while ( V_27 < V_268 );
}
return - 1 ;
}
static int F_114 ( struct V_5 * V_6 , struct V_264 * V_56 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
int V_270 ;
int V_26 ;
int V_27 ;
memset ( V_56 -> V_170 , 0 , sizeof( V_56 -> V_170 ) ) ;
if ( V_56 -> V_168 > V_77 )
return - V_63 ;
if ( V_56 -> V_265 != 0 )
return - V_63 ;
if ( V_56 -> V_266 == 0 ) {
V_2 -> V_56 . V_57 &= ~ ( 1 << V_56 -> V_168 ) ;
F_32 ( V_2 , V_2 -> V_56 . V_57 ) ;
F_27 ( V_6 , V_3 -> V_271 , 0x0f , V_2 -> V_56 . V_57 ) ;
V_2 -> V_162 . V_272 = 16 ;
V_2 -> V_162 . V_273 = 9 ;
if ( ! V_2 -> V_56 . V_57 )
V_2 -> V_56 . V_266 = 0 ;
F_31 ( 2 , V_45 , V_6 , L_56 ,
V_46 , V_56 -> V_168 , V_2 -> V_56 . V_57 ) ;
return 0 ;
}
if ( V_56 -> V_266 > 2 ) {
V_56 -> V_266 = 2 ;
return - V_274 ;
}
F_31 ( 2 , V_45 , V_6 , L_57 ,
V_46 , V_56 -> V_168 , V_2 -> V_56 . V_57 ) ;
F_115 ( & V_2 -> V_55 ) ;
F_32 ( V_2 , 0 ) ;
F_27 ( V_6 , V_3 -> V_271 , 0x0f , 0x00 ) ;
V_270 = F_113 ( V_56 -> V_56 ) ;
if ( V_270 < 0 )
V_270 = 0xc0 ;
switch ( V_56 -> V_168 ) {
case V_74 :
V_2 -> V_275 [ 0 ] = V_56 -> V_56 [ V_270 ] ;
V_2 -> V_275 [ 1 ] = V_56 -> V_56 [ V_270 + 1 ] ;
break;
case V_75 :
F_26 ( V_6 , 0x70 , V_56 -> V_56 [ V_270 ] ) ;
F_26 ( V_6 , 0x71 , V_56 -> V_56 [ V_270 + 1 ] ) ;
break;
case V_76 :
F_26 ( V_6 , 0x72 , V_56 -> V_56 [ V_270 ] ) ;
F_26 ( V_6 , 0x73 , V_56 -> V_56 [ V_270 + 1 ] ) ;
break;
case V_77 :
F_26 ( V_6 , 0x74 , V_56 -> V_56 [ V_270 ] ) ;
F_26 ( V_6 , 0x75 , V_56 -> V_56 [ V_270 + 1 ] ) ;
break;
default:
return - V_63 ;
}
if ( V_3 -> type == V_276 ) {
F_26 ( V_6 , 0x76 , V_270 & 0xff ) ;
F_27 ( V_6 , 0x77 , 0x40 , ( V_270 & 0x100 ) >> 2 ) ;
} else {
F_27 ( V_6 , 0x71 , 0x01 , ( V_270 & 0x100 ) >> 8 ) ;
}
V_56 -> V_56 [ V_270 ] = V_2 -> V_275 [ 0 ] ;
V_56 -> V_56 [ V_270 + 1 ] = V_2 -> V_275 [ 1 ] ;
memcpy ( V_2 -> V_56 . V_56 , V_56 -> V_56 , 128 * V_56 -> V_266 ) ;
V_2 -> V_56 . V_266 = V_56 -> V_266 ;
V_2 -> V_162 = F_116 ( V_56 -> V_56 [ 0x15 ] ,
V_56 -> V_56 [ 0x16 ] ) ;
V_2 -> V_56 . V_57 |= 1 << V_56 -> V_168 ;
V_26 = F_30 ( V_6 , 128 * V_56 -> V_266 , V_2 -> V_56 . V_56 ) ;
if ( V_26 < 0 ) {
F_66 ( V_6 , L_58 , V_26 , V_56 -> V_168 ) ;
return V_26 ;
}
F_27 ( V_6 , V_3 -> V_271 , 0x0f , V_2 -> V_56 . V_57 ) ;
for ( V_27 = 0 ; V_27 < 1000 ; V_27 ++ ) {
if ( F_25 ( V_6 , V_3 -> V_277 ) & V_2 -> V_56 . V_57 )
break;
F_117 ( 1 ) ;
}
if ( V_27 == 1000 ) {
F_66 ( V_6 , L_59 , V_2 -> V_56 . V_57 ) ;
return - V_21 ;
}
F_118 ( V_2 -> V_278 ,
& V_2 -> V_55 , V_279 / 10 ) ;
return 0 ;
}
static int F_119 ( struct V_5 * V_6 , int V_167 ,
union V_280 * V_281 )
{
T_10 V_282 [ 32 ] ;
T_2 V_44 ;
int V_27 ;
if ( ! ( F_14 ( V_6 , 0x60 ) & V_283 [ V_167 ] . V_284 ) ) {
F_55 ( V_6 , L_60 ,
V_283 [ V_167 ] . V_285 ) ;
return - V_286 ;
}
for ( V_27 = 0 ; V_27 < 3 ; V_27 ++ )
V_282 [ V_27 ] = F_21 ( V_6 ,
V_283 [ V_167 ] . V_287 + V_27 ) ;
V_44 = V_282 [ 2 ] + 1 ;
if ( V_44 + 3 > sizeof( V_282 ) ) {
F_66 ( V_6 , L_61 , V_46 ,
V_283 [ V_167 ] . V_285 , V_44 ) ;
return - V_286 ;
}
for ( V_27 = 0 ; V_27 < V_44 ; V_27 ++ )
V_282 [ V_27 + 3 ] = F_21 ( V_6 ,
V_283 [ V_167 ] . V_288 + V_27 ) ;
if ( F_120 ( V_281 , V_282 ) < 0 ) {
F_66 ( V_6 , L_62 , V_46 ,
V_283 [ V_167 ] . V_285 ) ;
return - V_286 ;
}
return 0 ;
}
static void F_121 ( struct V_5 * V_6 )
{
int V_27 ;
if ( ! F_74 ( V_6 ) ) {
F_55 ( V_6 , L_63 ) ;
return;
}
for ( V_27 = 0 ; V_27 < F_86 ( V_283 ) ; V_27 ++ ) {
union V_280 V_281 ;
struct V_9 * V_10 = F_122 ( V_6 ) ;
if ( F_119 ( V_6 , V_27 , & V_281 ) )
return;
F_123 ( V_289 , & V_10 -> V_290 , & V_281 ) ;
}
}
static int F_124 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
struct V_87 V_88 ;
struct V_150 V_151 ;
T_2 V_291 = F_14 ( V_6 , 0x02 ) ;
T_2 V_292 ;
T_2 V_293 ;
static const char * const V_294 [ 16 ] = {
L_64 , L_65 , L_66 , L_67 ,
L_66 , L_68 , L_66 , L_69 ,
L_66 , L_70 , L_71 ,
L_66 , L_66 , L_66 , L_66 , L_72
} ;
static const char * const V_295 [ 16 ] = {
L_73 , L_74 ,
L_75 , L_76 ,
L_77 , L_78 ,
L_79 , L_80 ,
L_81 , L_81 , L_81 , L_81 , L_81 ,
L_81 , L_81 , L_82
} ;
static const char * const V_296 [ 16 ] = {
L_73 , L_74 ,
L_75 , L_76 ,
L_77 , L_78 ,
L_79 , L_80 ,
L_83 , L_84 , L_85 , L_81 , L_81 ,
L_81 , L_81 , L_81
} ;
static const char * const V_297 [] = {
L_86 ,
L_73 ,
L_74 ,
} ;
static const char * const V_298 [ 4 ] = {
L_87 ,
L_88 ,
L_89 ,
L_90
} ;
F_55 ( V_6 , L_91 ) ;
F_55 ( V_6 , L_92 , F_71 ( V_6 ) ? L_93 : L_94 ) ;
V_292 = F_25 ( V_6 , V_3 -> V_277 ) ;
F_55 ( V_6 , L_95 ,
( ( V_292 & 0x01 ) ? L_96 : L_97 ) ,
( ( V_292 & 0x02 ) ? L_96 : L_97 ) ,
( ( V_292 & 0x04 ) ? L_96 : L_97 ) ,
( ( V_292 & 0x08 ) ? L_96 : L_97 ) ) ;
F_55 ( V_6 , L_98 , ! ! ( F_19 ( V_6 , 0x2a ) & 0x01 ) ?
L_99 : L_100 ) ;
F_55 ( V_6 , L_101 ) ;
V_293 = V_3 -> V_83 ( V_6 ) ;
F_55 ( V_6 , L_102 ,
( ( V_293 & 0x01 ) ? L_96 : L_97 ) ,
( ( V_293 & 0x02 ) ? L_96 : L_97 ) ,
( ( V_293 & 0x04 ) ? L_96 : L_97 ) ,
( ( V_293 & 0x08 ) ? L_96 : L_97 ) ) ;
F_55 ( V_6 , L_103 ,
F_72 ( V_6 ) ? L_104 : L_105 ) ;
F_55 ( V_6 , L_106 ,
F_73 ( V_6 ) ? L_104 : L_105 ) ;
F_55 ( V_6 , L_107 , F_75 ( V_6 ) ? L_104 : L_105 ) ;
F_55 ( V_6 , L_108 , F_76 ( V_6 ) ? L_104 : L_105 ) ;
F_55 ( V_6 , L_109 , F_78 ( V_6 ) ? L_104 : L_105 ) ;
F_55 ( V_6 , L_110 ,
( F_79 ( V_6 ) ) ? L_94 : L_93 ) ;
F_55 ( V_6 , L_111 ,
F_14 ( V_6 , 0x01 ) & 0x0f , F_14 ( V_6 , 0x00 ) & 0x3f ,
( F_14 ( V_6 , 0x01 ) & 0x70 ) >> 4 ) ;
F_55 ( V_6 , L_112 ) ;
if ( F_84 ( V_6 , & V_151 ) )
F_55 ( V_6 , L_113 ) ;
else
F_55 ( V_6 , L_114 ,
V_151 . V_156 , V_151 . V_153 , V_151 . V_157 ,
V_151 . V_165 ? L_36 : L_37 ,
V_151 . V_158 , V_151 . V_160 ) ;
if ( F_91 ( V_6 , & V_88 ) )
F_55 ( V_6 , L_115 ) ;
else
F_92 ( V_6 -> V_214 , L_116 ,
& V_88 , true ) ;
F_92 ( V_6 -> V_214 , L_117 ,
& V_2 -> V_88 , true ) ;
if ( F_77 ( V_6 ) )
return 0 ;
F_55 ( V_6 , L_118 ) ;
F_55 ( V_6 , L_119 ,
V_297 [ V_2 -> V_126 ] ) ;
F_55 ( V_6 , L_120 ,
V_295 [ V_291 >> 4 ] ) ;
F_55 ( V_6 , L_121 ,
( V_291 & 0x02 ) ? L_122 : L_123 ,
( V_291 & 0x04 ) ? L_124 : L_125 ,
( ( ( V_291 >> 2 ) & 0x01 ) ^ ( V_291 & 0x01 ) ) ?
L_99 : L_100 ,
( V_291 & 0x08 ) ? L_99 : L_100 ) ;
F_55 ( V_6 , L_126 ,
V_294 [ F_43 ( V_6 , V_3 -> V_299 ) >> 4 ] ) ;
if ( ! F_53 ( V_6 ) )
return 0 ;
F_55 ( V_6 , L_127 , F_74 ( V_6 ) ? L_53 : L_128 ) ;
F_55 ( V_6 , L_129 ,
( F_38 ( V_6 , 0x00 ) & 0x03 ) + 'A' ) ;
F_55 ( V_6 , L_130 ,
( F_38 ( V_6 , 0x05 ) & 0x40 ) ? L_105 : L_104 ) ;
F_55 ( V_6 , L_131 ,
( F_38 ( V_6 , 0x04 ) & 0x20 ) ? L_132 : L_133 ,
( F_38 ( V_6 , 0x04 ) & 0x10 ) ? L_134 : L_135 ) ;
if ( F_74 ( V_6 ) ) {
bool V_300 = F_38 ( V_6 , 0x04 ) & 0x01 ;
bool V_301 = F_38 ( V_6 , 0x18 ) & 0x01 ;
bool V_302 = F_14 ( V_6 , 0x65 ) & 0x40 ;
F_55 ( V_6 , L_136 ,
V_300 ? L_137 : L_138 ,
V_301 ? L_139 : L_140 ,
V_302 ? L_141 : L_99 ) ;
if ( V_300 && V_301 ) {
F_55 ( V_6 , L_142 ,
( F_38 ( V_6 , 0x07 ) & 0x20 ) ? L_143 : L_144 ) ;
}
F_55 ( V_6 , L_145 , ( F_38 ( V_6 , 0x5b ) << 12 ) +
( F_38 ( V_6 , 0x5c ) << 8 ) +
( F_38 ( V_6 , 0x5d ) & 0xf0 ) ) ;
F_55 ( V_6 , L_146 , ( ( F_38 ( V_6 , 0x5d ) & 0x0f ) << 16 ) +
( F_38 ( V_6 , 0x5e ) << 8 ) +
F_38 ( V_6 , 0x5f ) ) ;
F_55 ( V_6 , L_147 , ( F_38 ( V_6 , 0x04 ) & 0x40 ) ? L_94 : L_93 ) ;
F_55 ( V_6 , L_148 , V_298 [ ( F_38 ( V_6 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_55 ( V_6 , L_149 , V_296 [ F_38 ( V_6 , 0x53 ) & 0xf ] ) ;
F_121 ( V_6 ) ;
}
return 0 ;
}
static int F_125 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_81 * V_3 = V_2 -> V_3 ;
struct V_303 * V_242 = & V_2 -> V_242 ;
F_40 ( V_6 , 0x48 ,
( V_242 -> V_304 ? 0x80 : 0 ) |
( V_242 -> V_305 ? 0x40 : 0 ) ) ;
F_98 ( V_6 ) ;
if ( V_242 -> V_306 >= 0 &&
V_242 -> V_306 < V_2 -> V_169 ) {
V_2 -> V_71 = V_242 -> V_306 ;
F_100 ( V_6 ) ;
F_97 ( V_6 ) ;
}
F_15 ( V_6 , 0x0c , 0x42 ) ;
F_15 ( V_6 , 0x0b , 0x44 ) ;
F_45 ( V_6 , 0xcf , 0x01 ) ;
F_16 ( V_6 , 0x02 , 0x0f ,
V_242 -> V_307 << 3 |
V_242 -> V_308 << 2 |
V_242 -> V_309 << 0 ) ;
F_16 ( V_6 , 0x05 , 0x0e , V_242 -> V_310 << 3 |
V_242 -> V_311 << 2 |
V_242 -> V_312 << 1 ) ;
F_107 ( V_2 ) ;
F_45 ( V_6 , 0x69 , 0x30 ) ;
F_15 ( V_6 , 0x06 , 0xa0 | V_242 -> V_313 << 2 |
V_242 -> V_314 << 1 | V_242 -> V_315 ) ;
F_15 ( V_6 , 0x14 , 0x40 | V_242 -> V_316 << 4 |
V_242 -> V_317 << 2 |
V_242 -> V_318 ) ;
F_45 ( V_6 , 0xba , ( V_242 -> V_319 << 1 ) | 0x01 ) ;
F_45 ( V_6 , 0xf3 , 0xdc ) ;
F_45 ( V_6 , 0xf9 , 0x23 ) ;
F_45 ( V_6 , 0x45 , 0x23 ) ;
F_45 ( V_6 , 0xc9 , 0x2d ) ;
F_41 ( V_6 , 0x15 , 0x03 , 0x03 ) ;
F_41 ( V_6 , 0x1a , 0x0e , 0x08 ) ;
F_41 ( V_6 , 0x68 , 0x06 , 0x06 ) ;
F_24 ( V_6 , 0xb5 , 0x01 ) ;
if ( F_1 ( V_2 ) ) {
F_24 ( V_6 , 0x02 , V_242 -> V_320 ) ;
F_16 ( V_6 , 0x30 , 1 << 4 , V_242 -> V_321 << 4 ) ;
}
F_15 ( V_6 , 0x40 , 0xc0 | V_242 -> V_322 ) ;
F_15 ( V_6 , 0x46 , 0x98 ) ;
F_15 ( V_6 , 0x6e , V_3 -> V_262 ) ;
F_15 ( V_6 , 0x73 , V_3 -> V_263 ) ;
V_3 -> V_323 ( V_6 ) ;
return F_126 ( V_6 -> V_324 ) ;
}
static void F_127 ( struct V_5 * V_6 )
{
F_15 ( V_6 , 0x41 , 0xd7 ) ;
}
static void F_128 ( struct V_5 * V_6 )
{
F_15 ( V_6 , 0x41 , 0xd0 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
unsigned int V_27 ;
for ( V_27 = 1 ; V_27 < F_86 ( V_2 -> V_24 ) ; ++ V_27 ) {
if ( V_2 -> V_24 [ V_27 ] )
F_130 ( V_2 -> V_24 [ V_27 ] ) ;
}
}
static struct V_9 * F_131 ( struct V_5 * V_6 ,
T_2 V_16 , T_2 V_325 )
{
struct V_9 * V_10 = F_122 ( V_6 ) ;
if ( V_16 )
F_15 ( V_6 , V_325 , V_16 << 1 ) ;
return F_132 ( V_10 -> V_15 , F_14 ( V_6 , V_325 ) >> 1 ) ;
}
static int F_133 ( struct V_1 * V_2 )
{
struct V_326 V_327 ;
struct V_328 * V_329 ;
struct V_328 * V_330 ;
unsigned int V_17 ;
V_330 = V_2 -> V_24 [ V_35 ] -> V_290 . V_331 ;
V_329 = F_134 ( V_330 , NULL ) ;
if ( ! V_329 )
return - V_63 ;
F_135 ( V_329 , & V_327 ) ;
F_136 ( V_329 ) ;
V_17 = V_327 . V_332 . V_333 . V_17 ;
if ( V_17 & V_334 )
V_2 -> V_242 . V_314 = 1 ;
if ( V_17 & V_335 )
V_2 -> V_242 . V_313 = 1 ;
if ( V_17 & V_336 )
V_2 -> V_242 . V_315 = 1 ;
if ( V_327 . V_337 == V_338 ) {
V_2 -> V_242 . V_311 = 1 ;
V_2 -> V_242 . V_308 = 1 ;
}
V_2 -> V_242 . V_322 = V_339 ;
V_2 -> V_242 . V_340 [ V_38 ] = 0x42 ;
V_2 -> V_242 . V_340 [ V_39 ] = 0x40 ;
V_2 -> V_242 . V_340 [ V_40 ] = 0x3e ;
V_2 -> V_242 . V_340 [ V_341 ] = 0x38 ;
V_2 -> V_242 . V_340 [ V_342 ] = 0x3c ;
V_2 -> V_242 . V_340 [ V_41 ] = 0x26 ;
V_2 -> V_242 . V_340 [ V_42 ] = 0x32 ;
V_2 -> V_242 . V_340 [ V_43 ] = 0x36 ;
V_2 -> V_242 . V_340 [ V_58 ] = 0x34 ;
V_2 -> V_242 . V_340 [ V_59 ] = 0x30 ;
V_2 -> V_242 . V_340 [ V_60 ] = 0x22 ;
V_2 -> V_242 . V_340 [ V_61 ] = 0x24 ;
V_2 -> V_242 . V_304 = 0 ;
V_2 -> V_242 . V_305 = 0 ;
V_2 -> V_242 . V_306 = - 1 ;
V_2 -> V_242 . V_310 = 1 ;
V_2 -> V_242 . V_309 = 1 ;
V_2 -> V_242 . V_247 = V_343 ;
V_2 -> V_242 . V_243 = V_344 ;
return 0 ;
}
static int F_137 ( struct V_9 * V_10 ,
const struct V_345 * V_135 )
{
static const struct V_87 V_346 =
V_347 ;
struct V_1 * V_2 ;
struct V_348 * V_134 ;
struct V_5 * V_6 ;
unsigned int V_27 ;
T_3 V_36 ;
int V_26 ;
if ( ! F_138 ( V_10 -> V_15 , V_349 ) )
return - V_21 ;
F_139 ( 1 , V_45 , V_10 , L_150 ,
V_10 -> V_16 << 1 ) ;
V_2 = F_140 ( & V_10 -> V_290 , sizeof( * V_2 ) , V_350 ) ;
if ( ! V_2 ) {
F_10 ( V_10 , L_151 ) ;
return - V_351 ;
}
V_2 -> V_24 [ V_35 ] = V_10 ;
V_2 -> V_191 = true ;
V_2 -> V_71 = ~ 0 ;
if ( F_141 ( V_352 ) && V_10 -> V_290 . V_331 ) {
const struct V_353 * V_354 ;
V_354 = F_142 ( V_355 , V_10 -> V_290 . V_331 ) ;
V_2 -> V_3 = V_354 -> V_14 ;
V_26 = F_133 ( V_2 ) ;
if ( V_26 < 0 ) {
F_10 ( V_10 , L_152 ) ;
return V_26 ;
}
} else if ( V_10 -> V_290 . V_356 ) {
struct V_303 * V_242 = V_10 -> V_290 . V_356 ;
V_2 -> V_3 = ( const struct V_81 * ) V_135 -> V_357 ;
V_2 -> V_242 = * V_242 ;
} else {
F_10 ( V_10 , L_153 ) ;
return - V_358 ;
}
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_48 ; ++ V_27 ) {
V_2 -> V_49 [ V_27 ] =
F_143 ( & V_10 -> V_290 , L_154 , V_27 ,
V_359 ) ;
if ( F_144 ( V_2 -> V_49 [ V_27 ] ) )
return F_145 ( V_2 -> V_49 [ V_27 ] ) ;
if ( V_2 -> V_49 [ V_27 ] )
F_146 ( V_10 , L_155 , V_27 ) ;
}
V_2 -> V_88 = V_346 ;
V_2 -> V_228 = V_67 ( V_2 , V_254 ) ;
V_6 = & V_2 -> V_6 ;
F_147 ( V_6 , V_10 , & V_360 ) ;
snprintf ( V_6 -> V_214 , sizeof( V_6 -> V_214 ) , L_156 ,
V_135 -> V_214 , F_148 ( V_10 -> V_15 ) ,
V_10 -> V_16 ) ;
V_6 -> V_17 |= V_361 ;
if ( V_2 -> V_3 -> type == V_276 ) {
V_36 = F_8 ( V_10 , 0xfb , false ) ;
if ( V_36 != 0x68 ) {
F_55 ( V_6 , L_157 ,
V_10 -> V_16 << 1 ) ;
return - V_358 ;
}
} else {
V_36 = ( F_8 ( V_10 , 0xea , false ) << 8 )
| ( F_8 ( V_10 , 0xeb , false ) << 0 ) ;
if ( V_36 != 0x2051 ) {
F_55 ( V_6 , L_158 ,
V_10 -> V_16 << 1 ) ;
return - V_358 ;
}
}
V_134 = & V_2 -> V_134 ;
F_149 ( V_134 , F_1 ( V_2 ) ? 9 : 8 ) ;
F_150 ( V_134 , & V_362 ,
V_136 , - 128 , 127 , 1 , 0 ) ;
F_150 ( V_134 , & V_362 ,
V_137 , 0 , 255 , 1 , 128 ) ;
F_150 ( V_134 , & V_362 ,
V_138 , 0 , 255 , 1 , 128 ) ;
F_150 ( V_134 , & V_362 ,
V_139 , 0 , 128 , 1 , 0 ) ;
V_2 -> V_82 = F_150 ( V_134 , NULL ,
V_363 , 0 ,
( 1 << V_2 -> V_3 -> V_48 ) - 1 , 0 , 0 ) ;
V_2 -> V_364 =
F_151 ( V_134 , & V_362 ,
V_140 , V_130 ,
0 , V_127 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_365 =
F_152 ( V_134 , & V_366 , NULL ) ;
V_2 -> V_367 =
F_152 ( V_134 , & V_368 , NULL ) ;
V_2 -> V_369 =
F_152 ( V_134 , & V_370 , NULL ) ;
V_6 -> V_324 = V_134 ;
if ( V_134 -> error ) {
V_26 = V_134 -> error ;
goto V_371;
}
V_2 -> V_82 -> V_372 = true ;
V_2 -> V_364 -> V_372 = true ;
if ( F_1 ( V_2 ) )
V_2 -> V_365 -> V_372 = true ;
V_2 -> V_367 -> V_372 = true ;
V_2 -> V_369 -> V_372 = true ;
if ( F_60 ( V_6 ) ) {
V_26 = - V_358 ;
goto V_371;
}
for ( V_27 = 1 ; V_27 < V_373 ; ++ V_27 ) {
if ( ! ( F_34 ( V_27 ) & V_2 -> V_3 -> V_62 ) )
continue;
V_2 -> V_24 [ V_27 ] =
F_131 ( V_6 , V_2 -> V_242 . V_340 [ V_27 ] ,
0xf2 + V_27 ) ;
if ( V_2 -> V_24 [ V_27 ] == NULL ) {
V_26 = - V_351 ;
F_66 ( V_6 , L_159 , V_27 ) ;
goto V_374;
}
}
V_2 -> V_278 = F_153 ( V_10 -> V_214 ) ;
if ( ! V_2 -> V_278 ) {
F_66 ( V_6 , L_160 ) ;
V_26 = - V_351 ;
goto V_374;
}
F_154 ( & V_2 -> V_55 ,
F_36 ) ;
V_2 -> V_169 = V_2 -> V_3 -> V_48
+ ( V_2 -> V_3 -> V_4 ? 2 : 0 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_169 ; ++ V_27 )
V_2 -> V_375 [ V_27 ] . V_17 = V_376 ;
V_2 -> V_375 [ V_2 -> V_169 ] . V_17 = V_377 ;
V_26 = F_155 ( & V_6 -> V_378 , V_2 -> V_169 + 1 ,
V_2 -> V_375 , 0 ) ;
if ( V_26 )
goto V_379;
V_26 = F_125 ( V_6 ) ;
if ( V_26 )
goto V_380;
F_55 ( V_6 , L_161 , V_10 -> V_214 ,
V_10 -> V_16 << 1 , V_10 -> V_15 -> V_214 ) ;
V_26 = F_156 ( V_6 ) ;
if ( V_26 )
goto V_380;
return 0 ;
V_380:
F_157 ( & V_6 -> V_378 ) ;
V_379:
F_158 ( & V_2 -> V_55 ) ;
F_159 ( V_2 -> V_278 ) ;
V_374:
F_129 ( V_2 ) ;
V_371:
F_160 ( V_134 ) ;
return V_26 ;
}
static int F_161 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = F_162 ( V_10 ) ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_158 ( & V_2 -> V_55 ) ;
F_159 ( V_2 -> V_278 ) ;
F_163 ( V_6 ) ;
F_157 ( & V_6 -> V_378 ) ;
F_129 ( F_2 ( V_6 ) ) ;
F_160 ( V_6 -> V_324 ) ;
return 0 ;
}
