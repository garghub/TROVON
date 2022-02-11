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
static int F_8 ( struct V_1 * V_2 ,
int V_9 , T_1 V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 [ V_9 ] ;
int V_14 ;
unsigned int V_15 ;
V_14 = F_9 ( V_2 -> V_16 [ V_9 ] , V_10 , & V_15 ) ;
if ( V_14 ) {
F_10 ( V_12 , L_1 ,
V_12 -> V_17 , V_10 ) ;
return V_14 ;
}
return V_15 ;
}
static int F_11 ( struct V_1 * V_2 , int V_9 ,
unsigned int V_18 , const void * V_15 ,
T_2 V_19 )
{
struct V_16 * V_16 = V_2 -> V_16 [ V_9 ] ;
if ( V_19 > V_20 )
V_19 = V_20 ;
return F_12 ( V_16 , V_18 , V_15 , V_19 ) ;
}
static inline int F_13 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_21 , V_10 ) ;
}
static inline int F_14 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_21 ] , V_10 , V_15 ) ;
}
static inline int F_16 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_22 , T_1 V_15 )
{
return F_14 ( V_6 , V_10 , ( F_13 ( V_6 , V_10 ) & ~ V_22 ) | V_15 ) ;
}
static inline int F_17 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_23 , V_10 ) ;
}
static inline int F_18 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_23 ] , V_10 , V_15 ) ;
}
static inline int F_19 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_24 , V_10 ) ;
}
static inline int F_20 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_24 ] , V_10 , V_15 ) ;
}
static inline int F_21 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_25 , V_10 ) ;
}
static inline int F_22 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_25 ] , V_10 , V_15 ) ;
}
static inline int F_23 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_26 , V_10 ) ;
}
static inline int F_24 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_26 ] , V_10 , V_15 ) ;
}
static inline int F_25 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_27 , V_10 ) ;
}
static inline int F_26 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_27 ] , V_10 , V_15 ) ;
}
static inline int F_27 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_22 , T_1 V_15 )
{
return F_26 ( V_6 , V_10 , ( F_25 ( V_6 , V_10 ) & ~ V_22 ) | V_15 ) ;
}
static inline int F_28 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_28 , V_10 ) ;
}
static inline int F_29 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_28 ] , V_10 , V_15 ) ;
}
static inline int F_30 ( struct V_5 * V_6 ,
unsigned int V_29 , const T_1 * V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_14 = 0 ;
int V_30 = 0 ;
int V_31 = 0 ;
F_31 ( 2 , V_32 , V_6 , L_2 ,
V_33 , V_29 ) ;
while ( ! V_14 && V_30 < V_29 ) {
V_31 = ( V_29 - V_30 ) > V_20 ?
V_20 :
( V_29 - V_30 ) ;
V_14 = F_11 ( V_2 , V_28 ,
V_30 , V_15 + V_30 , V_31 ) ;
V_30 += V_31 ;
}
return V_14 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int V_34 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_3 -> V_35 ; ++ V_30 )
F_33 ( V_2 -> V_36 [ V_30 ] , V_34 & F_34 ( V_30 ) ) ;
F_35 ( & V_2 -> V_6 , V_37 , & V_34 ) ;
}
static void F_36 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_37 ( V_39 ) ;
struct V_1 * V_2 = F_3 ( V_41 , struct V_1 ,
V_42 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_31 ( 2 , V_32 , V_6 , L_3 , V_33 ) ;
F_32 ( V_2 , V_2 -> V_43 . V_44 ) ;
}
static inline int F_38 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_45 , V_10 ) ;
}
static T_3 F_39 ( struct V_5 * V_6 , T_1 V_10 , T_3 V_22 )
{
return ( ( F_38 ( V_6 , V_10 ) << 8 ) | F_38 ( V_6 , V_10 + 1 ) ) & V_22 ;
}
static inline int F_40 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_45 ] , V_10 , V_15 ) ;
}
static inline int F_41 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_22 , T_1 V_15 )
{
return F_40 ( V_6 , V_10 , ( F_38 ( V_6 , V_10 ) & ~ V_22 ) | V_15 ) ;
}
static inline int F_42 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_46 ] , V_10 , V_15 ) ;
}
static inline int F_43 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_47 , V_10 ) ;
}
static T_3 F_44 ( struct V_5 * V_6 , T_1 V_10 , T_3 V_22 )
{
return ( ( F_43 ( V_6 , V_10 ) << 8 ) | F_43 ( V_6 , V_10 + 1 ) ) & V_22 ;
}
static inline int F_45 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_47 ] , V_10 , V_15 ) ;
}
static inline int F_46 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_22 , T_1 V_15 )
{
return F_45 ( V_6 , V_10 , ( F_43 ( V_6 , V_10 ) & ~ V_22 ) | V_15 ) ;
}
static inline int F_47 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_8 ( V_2 , V_48 , V_10 ) ;
}
static inline int F_48 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 -> V_16 [ V_48 ] , V_10 , V_15 ) ;
}
static int F_49 ( struct V_5 * V_6 , unsigned int V_10 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned int V_49 = V_10 >> 8 ;
unsigned int V_15 ;
int V_14 ;
if ( ! ( F_34 ( V_49 ) & V_2 -> V_3 -> V_50 ) )
return - V_51 ;
V_10 &= 0xff ;
V_14 = F_9 ( V_2 -> V_16 [ V_49 ] , V_10 , & V_15 ) ;
return V_14 ? V_14 : V_15 ;
}
static int F_50 ( struct V_5 * V_6 , unsigned int V_10 , T_1 V_15 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned int V_49 = V_10 >> 8 ;
if ( ! ( F_34 ( V_49 ) & V_2 -> V_3 -> V_50 ) )
return - V_51 ;
V_10 &= 0xff ;
return F_15 ( V_2 -> V_16 [ V_49 ] , V_10 , V_15 ) ;
}
static void F_51 ( struct V_5 * V_6 ,
const struct V_52 * V_53 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_53 [ V_30 ] . V_10 != V_54 ; V_30 ++ )
F_50 ( V_6 , V_53 [ V_30 ] . V_10 , V_53 [ V_30 ] . V_15 ) ;
}
static const struct V_55 *
V_55 ( struct V_1 * V_2 , T_4 V_56 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_3 -> V_57 ; ++ V_30 ) {
if ( V_2 -> V_3 -> V_58 [ V_30 ] . V_56 == V_56 )
return & V_2 -> V_3 -> V_58 [ V_30 ] ;
}
return NULL ;
}
static inline bool F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_59 == V_60 ||
V_2 -> V_59 == V_61 ;
}
static inline bool F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_59 == V_62 ||
V_2 -> V_59 == V_63 ||
V_2 -> V_59 == V_64 ||
V_2 -> V_59 == V_65 ;
}
static void F_54 ( struct V_5 * V_6 )
{
F_55 ( V_6 , L_4 ) ;
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
}
static int F_56 ( struct V_5 * V_6 ,
struct V_66 * V_10 )
{
int V_67 ;
V_67 = F_49 ( V_6 , V_10 -> V_10 ) ;
if ( V_67 < 0 ) {
F_55 ( V_6 , L_17 , V_10 -> V_10 ) ;
F_54 ( V_6 ) ;
return V_67 ;
}
V_10 -> V_68 = 1 ;
V_10 -> V_15 = V_67 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
const struct V_66 * V_10 )
{
int V_67 ;
V_67 = F_50 ( V_6 , V_10 -> V_10 , V_10 -> V_15 ) ;
if ( V_67 < 0 ) {
F_55 ( V_6 , L_17 , V_10 -> V_10 ) ;
F_54 ( V_6 ) ;
return V_67 ;
}
return 0 ;
}
static unsigned int F_58 ( struct V_5 * V_6 )
{
T_1 V_69 = F_13 ( V_6 , 0x6f ) ;
return ( ( V_69 & 0x10 ) >> 4 )
| ( ( V_69 & 0x08 ) >> 2 )
| ( ( V_69 & 0x04 ) << 0 )
| ( ( V_69 & 0x02 ) << 2 ) ;
}
static unsigned int F_59 ( struct V_5 * V_6 )
{
T_1 V_69 = F_13 ( V_6 , 0x6f ) ;
return V_69 & 1 ;
}
static unsigned int F_60 ( struct V_5 * V_6 )
{
T_1 V_69 = F_13 ( V_6 , 0x6f ) ;
return V_69 & 1 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
return F_62 ( V_2 -> V_71 ,
V_3 -> V_72 ( V_6 ) ) ;
}
static int F_63 ( struct V_5 * V_6 ,
T_1 V_73 ,
const struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
int V_30 ;
for ( V_30 = 0 ; V_75 [ V_30 ] . V_77 . V_78 . V_79 ; V_30 ++ ) {
if ( ! F_64 ( V_77 , & V_75 [ V_30 ] . V_77 ,
F_53 ( V_6 ) ? 250000 : 1000000 , false ) )
continue;
F_14 ( V_6 , 0x00 , V_75 [ V_30 ] . V_80 ) ;
F_14 ( V_6 , 0x01 , ( V_75 [ V_30 ] . V_81 << 4 ) +
V_73 ) ;
return 0 ;
}
return - 1 ;
}
static int F_65 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_14 ;
F_31 ( 1 , V_32 , V_6 , L_18 , V_33 ) ;
if ( F_1 ( V_2 ) ) {
F_14 ( V_6 , 0x16 , 0x43 ) ;
F_14 ( V_6 , 0x17 , 0x5a ) ;
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
V_14 = F_63 ( V_6 ,
0x01 , V_82 , V_77 ) ;
if ( V_14 )
V_14 = F_63 ( V_6 ,
0x02 , V_83 , V_77 ) ;
} else if ( F_53 ( V_6 ) ) {
V_14 = F_63 ( V_6 ,
0x05 , V_84 , V_77 ) ;
if ( V_14 )
V_14 = F_63 ( V_6 ,
0x06 , V_85 , V_77 ) ;
} else {
F_31 ( 2 , V_32 , V_6 , L_19 ,
V_33 , V_2 -> V_59 ) ;
V_14 = - 1 ;
}
return V_14 ;
}
static void F_66 ( struct V_5 * V_6 ,
const struct V_7 * V_78 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_79 = F_4 ( V_78 ) ;
T_4 V_86 = F_6 ( V_78 ) ;
T_3 V_87 = V_78 -> V_88 + V_78 -> V_89 - 4 ;
T_3 V_90 = V_79 - V_78 -> V_91 ;
T_3 V_92 = V_86 - V_78 -> V_93 ;
T_3 V_94 = V_78 -> V_95 + V_78 -> V_96 ;
T_3 V_97 = ( ( ( T_4 ) V_78 -> V_98 / 100 ) > 0 ) ?
( ( V_79 * ( V_99 / 100 ) ) / ( ( T_4 ) V_78 -> V_98 / 100 ) ) : 0 ;
const T_1 V_100 [ 2 ] = {
0xc0 | ( ( V_79 >> 8 ) & 0x1f ) ,
V_79 & 0xff
} ;
F_31 ( 2 , V_32 , V_6 , L_20 , V_33 ) ;
if ( F_52 ( V_6 ) ) {
F_14 ( V_6 , 0x00 , 0x07 ) ;
F_14 ( V_6 , 0x01 , 0x02 ) ;
F_46 ( V_6 , 0x81 , 0x10 , 0x10 ) ;
if ( F_12 ( V_2 -> V_16 [ V_21 ] ,
0x16 , V_100 , 2 ) )
F_67 ( V_6 , L_21 ) ;
F_45 ( V_6 , 0xa2 , ( V_87 >> 4 ) & 0xff ) ;
F_45 ( V_6 , 0xa3 , ( ( V_87 & 0x0f ) << 4 ) |
( ( V_90 >> 8 ) & 0x0f ) ) ;
F_45 ( V_6 , 0xa4 , V_90 & 0xff ) ;
F_45 ( V_6 , 0xa5 , ( V_92 >> 4 ) & 0xff ) ;
F_45 ( V_6 , 0xa6 , ( ( V_92 & 0xf ) << 4 ) |
( ( V_94 >> 8 ) & 0xf ) ) ;
F_45 ( V_6 , 0xa7 , V_94 & 0xff ) ;
} else if ( F_53 ( V_6 ) ) {
F_14 ( V_6 , 0x00 , 0x02 ) ;
F_14 ( V_6 , 0x01 , 0x06 ) ;
} else {
F_31 ( 2 , V_32 , V_6 , L_19 ,
V_33 , V_2 -> V_59 ) ;
}
F_45 ( V_6 , 0x8f , ( V_97 >> 8 ) & 0x7 ) ;
F_45 ( V_6 , 0x90 , V_97 & 0xff ) ;
F_45 ( V_6 , 0xab , ( V_86 >> 4 ) & 0xff ) ;
F_45 ( V_6 , 0xac , ( V_86 & 0x0f ) << 4 ) ;
}
static void F_68 ( struct V_5 * V_6 , bool V_101 , T_3 V_102 , T_3 V_103 , T_3 V_104 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_1 V_105 [ 4 ] ;
if ( V_101 ) {
V_102 = 0x3ff ;
V_103 = 0x3ff ;
V_104 = 0x3ff ;
}
F_31 ( 2 , V_32 , V_6 , L_22 ,
V_33 , V_101 ? L_23 : L_24 ,
V_102 , V_103 , V_104 ) ;
V_105 [ 0 ] = ( F_43 ( V_6 , 0x77 ) & 0xc0 ) | ( ( V_102 & 0x3f0 ) >> 4 ) ;
V_105 [ 1 ] = ( ( V_102 & 0x00f ) << 4 ) | ( ( V_103 & 0x3c0 ) >> 6 ) ;
V_105 [ 2 ] = ( ( V_103 & 0x03f ) << 2 ) | ( ( V_104 & 0x300 ) >> 8 ) ;
V_105 [ 3 ] = V_104 & 0x0ff ;
if ( F_12 ( V_2 -> V_16 [ V_47 ] ,
0x77 , V_105 , 4 ) )
F_67 ( V_6 , L_25 , V_33 ) ;
}
static void F_69 ( struct V_5 * V_6 , bool V_106 , T_3 V_107 , T_3 V_108 , T_3 V_109 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_1 V_110 [ 4 ] ;
T_1 V_111 = 1 ;
T_1 V_112 = 1 ;
if ( V_106 ) {
V_111 = 0 ;
V_112 = 0 ;
V_107 = 0x100 ;
V_108 = 0x100 ;
V_109 = 0x100 ;
}
F_31 ( 2 , V_32 , V_6 , L_26 ,
V_33 , V_106 ? L_23 : L_24 ,
V_107 , V_108 , V_109 ) ;
V_110 [ 0 ] = ( ( V_111 << 7 ) | ( V_112 << 6 ) | ( ( V_107 & 0x3f0 ) >> 4 ) ) ;
V_110 [ 1 ] = ( ( ( V_107 & 0x00f ) << 4 ) | ( ( V_108 & 0x3c0 ) >> 6 ) ) ;
V_110 [ 2 ] = ( ( ( V_108 & 0x03f ) << 2 ) | ( ( V_109 & 0x300 ) >> 8 ) ) ;
V_110 [ 3 ] = ( ( V_109 & 0x0ff ) ) ;
if ( F_12 ( V_2 -> V_16 [ V_47 ] ,
0x73 , V_110 , 4 ) )
F_67 ( V_6 , L_27 , V_33 ) ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
bool V_113 = F_13 ( V_6 , 0x02 ) & 0x02 ;
bool V_114 = F_38 ( V_6 , 0x05 ) & 0x80 ;
F_31 ( 2 , V_32 , V_6 , L_28 ,
V_33 , V_2 -> V_115 ,
V_113 , V_114 ) ;
F_69 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
F_68 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_2 -> V_115 ) {
case V_116 :
if ( V_2 -> V_59 == V_60 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
break;
}
if ( V_2 -> V_59 == V_61 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_114 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_2 -> V_77 . V_78 . V_117 & V_118 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
} else {
F_16 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_53 ( V_6 ) && V_113 ) {
F_68 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_69 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_68 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_119 :
if ( V_2 -> V_59 == V_61 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x20 ) ;
break;
}
F_16 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
break;
case V_120 :
if ( V_2 -> V_59 == V_61 ) {
F_16 ( V_6 , 0x02 , 0xf0 , 0x60 ) ;
break;
}
F_16 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_52 ( V_6 ) || V_114 )
break;
if ( V_113 ) {
F_68 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_69 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_68 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_71 ( struct V_121 * V_122 )
{
struct V_5 * V_6 =
& F_3 ( V_122 -> V_123 , struct V_1 , V_124 ) -> V_6 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
switch ( V_122 -> V_125 ) {
case V_126 :
F_45 ( V_6 , 0x3c , V_122 -> V_15 ) ;
return 0 ;
case V_127 :
F_45 ( V_6 , 0x3a , V_122 -> V_15 ) ;
return 0 ;
case V_128 :
F_45 ( V_6 , 0x3b , V_122 -> V_15 ) ;
return 0 ;
case V_129 :
F_45 ( V_6 , 0x3d , V_122 -> V_15 ) ;
return 0 ;
case V_130 :
V_2 -> V_115 = V_122 -> V_15 ;
F_70 ( V_6 ) ;
return 0 ;
case V_131 :
if ( ! F_1 ( V_2 ) )
return - V_51 ;
F_24 ( V_6 , 0xc8 , V_122 -> V_15 ) ;
return 0 ;
case V_132 :
F_46 ( V_6 , 0xbf , 0x04 , V_122 -> V_15 << 2 ) ;
return 0 ;
case V_133 :
F_45 ( V_6 , 0xc0 , ( V_122 -> V_15 & 0xff0000 ) >> 16 ) ;
F_45 ( V_6 , 0xc1 , ( V_122 -> V_15 & 0x00ff00 ) >> 8 ) ;
F_45 ( V_6 , 0xc2 , ( T_1 ) ( V_122 -> V_15 & 0x0000ff ) ) ;
return 0 ;
}
return - V_51 ;
}
static inline bool F_72 ( struct V_5 * V_6 )
{
return F_13 ( V_6 , 0x0c ) & 0x24 ;
}
static inline bool F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return ! ( F_13 ( V_6 , 0x6a ) & ( 0x10 >> V_2 -> V_59 ) ) ;
}
static inline bool F_74 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
return ( F_13 ( V_6 , 0x6a ) & V_3 -> V_134 ) != V_3 -> V_134 ;
}
static inline bool F_75 ( struct V_5 * V_6 )
{
return F_38 ( V_6 , 0x05 ) & 0x80 ;
}
static inline bool F_76 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_1 ( V_2 ) )
return false ;
return ( ( F_43 ( V_6 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_77 ( struct V_5 * V_6 )
{
return ! ( F_43 ( V_6 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_78 ( struct V_5 * V_6 )
{
bool V_67 ;
V_67 = F_72 ( V_6 ) ;
V_67 |= F_77 ( V_6 ) ;
V_67 |= F_76 ( V_6 ) ;
if ( F_53 ( V_6 ) ) {
V_67 |= F_74 ( V_6 ) ;
V_67 |= F_73 ( V_6 ) ;
}
return V_67 ;
}
static inline bool F_79 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( ! F_1 ( V_2 ) )
return false ;
return F_13 ( V_6 , 0x12 ) & 0x01 ;
}
static inline bool F_80 ( struct V_5 * V_6 )
{
return F_43 ( V_6 , 0xff ) & 0x10 ;
}
static int F_81 ( struct V_5 * V_6 , T_4 * V_135 )
{
* V_135 = 0 ;
* V_135 |= F_72 ( V_6 ) ? V_136 : 0 ;
* V_135 |= F_78 ( V_6 ) ? V_137 : 0 ;
if ( ! F_80 ( V_6 ) && F_79 ( V_6 ) )
* V_135 |= F_53 ( V_6 ) ?
V_138 : V_139 ;
F_31 ( 1 , V_32 , V_6 , L_29 , V_33 , * V_135 ) ;
return 0 ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_140 * V_141 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_142 = ( V_99 * 8 ) / V_141 -> V_143 ;
T_4 V_144 ;
int V_30 ;
for ( V_30 = 0 ; V_145 [ V_30 ] . V_78 . V_86 ; V_30 ++ ) {
if ( F_6 ( & V_145 [ V_30 ] . V_78 ) != V_141 -> V_146 + 1 )
continue;
if ( V_145 [ V_30 ] . V_78 . V_95 != V_141 -> V_147 )
continue;
V_144 = V_142 * F_4 ( & V_145 [ V_30 ] . V_78 ) ;
if ( ( V_144 < V_145 [ V_30 ] . V_78 . V_98 + 1000000 ) &&
( V_144 > V_145 [ V_30 ] . V_78 . V_98 - 1000000 ) ) {
* V_77 = V_145 [ V_30 ] ;
return 0 ;
}
}
if ( F_83 ( V_141 -> V_146 + 1 , V_142 , V_141 -> V_147 , 0 ,
( V_141 -> V_148 == '+' ? V_149 : 0 ) |
( V_141 -> V_150 == '+' ? V_151 : 0 ) ,
false , V_77 ) )
return 0 ;
if ( F_84 ( V_141 -> V_146 + 1 , V_142 , V_141 -> V_147 ,
( V_141 -> V_148 == '+' ? V_149 : 0 ) |
( V_141 -> V_150 == '+' ? V_151 : 0 ) ,
false , V_2 -> V_152 , V_77 ) )
return 0 ;
F_31 ( 2 , V_32 , V_6 ,
L_30 ,
V_33 , V_141 -> V_147 , V_141 -> V_146 , V_141 -> V_143 ,
V_141 -> V_148 , V_141 -> V_150 ) ;
return - 1 ;
}
static int F_85 ( struct V_5 * V_6 , struct V_140 * V_141 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
T_1 V_153 ;
if ( F_77 ( V_6 ) || F_76 ( V_6 ) ) {
F_31 ( 2 , V_32 , V_6 , L_31 , V_33 ) ;
return - 1 ;
}
V_141 -> V_143 = F_44 ( V_6 , 0xb1 , 0x3fff ) ;
V_141 -> V_146 = F_44 ( V_6 , V_3 -> V_154 , 0x7ff ) ;
V_141 -> V_147 = F_43 ( V_6 , 0xb3 ) >> 3 ;
V_141 -> V_155 = F_13 ( V_6 , 0x12 ) & 0x10 ;
if ( F_1 ( V_2 ) ) {
V_153 = F_43 ( V_6 , 0xb5 ) ;
if ( ( V_153 & 0x03 ) == 0x01 ) {
V_141 -> V_148 = V_153 & 0x10
? ( V_153 & 0x08 ? '+' : '-' ) : 'x' ;
V_141 -> V_150 = V_153 & 0x40
? ( V_153 & 0x20 ? '+' : '-' ) : 'x' ;
} else {
V_141 -> V_148 = 'x' ;
V_141 -> V_150 = 'x' ;
}
} else {
V_153 = F_38 ( V_6 , 0x05 ) ;
V_141 -> V_148 = V_153 & 0x20 ? '+' : '-' ;
V_141 -> V_150 = V_153 & 0x10 ? '+' : '-' ;
}
if ( F_77 ( V_6 ) || F_76 ( V_6 ) ) {
F_31 ( 2 , V_32 , V_6 ,
L_32 , V_33 ) ;
return - 1 ;
}
if ( V_141 -> V_146 < 239 || V_141 -> V_143 < 8 || V_141 -> V_143 == 0x3fff ) {
F_31 ( 2 , V_32 , V_6 , L_33 , V_33 ) ;
memset ( V_141 , 0 , sizeof( struct V_140 ) ) ;
return - 1 ;
}
F_31 ( 2 , V_32 , V_6 ,
L_34 ,
V_33 , V_141 -> V_146 , V_141 -> V_143 , V_141 -> V_147 ,
V_141 -> V_148 , V_141 -> V_150 ,
V_141 -> V_155 ? L_35 : L_36 ) ;
return 0 ;
}
static int F_86 ( struct V_5 * V_6 ,
struct V_156 * V_77 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_77 -> V_157 >= F_87 ( V_145 ) - 1 )
return - V_51 ;
if ( V_77 -> V_158 >= V_2 -> V_159 )
return - V_51 ;
memset ( V_77 -> V_160 , 0 , sizeof( V_77 -> V_160 ) ) ;
V_77 -> V_77 = V_145 [ V_77 -> V_157 ] ;
return 0 ;
}
static int F_88 ( struct V_5 * V_6 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_162 -> V_158 >= V_2 -> V_159 )
return - V_51 ;
V_162 -> type = V_163 ;
V_162 -> V_78 . V_164 = 1920 ;
V_162 -> V_78 . V_165 = 1200 ;
V_162 -> V_78 . V_166 = 25000000 ;
switch ( V_162 -> V_158 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_162 -> V_78 . V_167 = 225000000 ;
break;
case V_60 :
case V_61 :
default:
V_162 -> V_78 . V_167 = 170000000 ;
break;
}
V_162 -> V_78 . V_168 = V_169 | V_170 |
V_171 | V_172 ;
V_162 -> V_78 . V_173 = V_174 |
V_175 | V_176 ;
return 0 ;
}
static void F_89 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
int V_30 ;
for ( V_30 = 0 ; V_145 [ V_30 ] . V_78 . V_79 ; V_30 ++ ) {
if ( F_64 ( V_77 , & V_145 [ V_30 ] ,
F_53 ( V_6 ) ? 250000 : 1000000 , false ) ) {
* V_77 = V_145 [ V_30 ] ;
break;
}
}
}
static unsigned int F_90 ( struct V_5 * V_6 )
{
unsigned int V_177 ;
int V_178 , V_179 ;
V_178 = F_38 ( V_6 , 0x06 ) ;
V_179 = F_38 ( V_6 , 0x3b ) ;
if ( V_178 < 0 || V_179 < 0 )
return 0 ;
V_177 = V_178 * 1000000 + ( ( V_179 & 0x30 ) >> 4 ) * 250000 ;
if ( F_75 ( V_6 ) ) {
unsigned V_180 = ( ( F_38 ( V_6 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_177 = V_177 * 8 / V_180 ;
}
return V_177 ;
}
static unsigned int F_91 ( struct V_5 * V_6 )
{
int V_178 , V_179 ;
V_178 = F_38 ( V_6 , 0x51 ) ;
V_179 = F_38 ( V_6 , 0x52 ) ;
if ( V_178 < 0 || V_179 < 0 )
return 0 ;
return ( ( V_178 << 1 ) | ( V_179 >> 7 ) ) * 1000000 + ( V_179 & 0x7f ) * 1000000 / 128 ;
}
static int F_92 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
struct V_7 * V_78 = & V_77 -> V_78 ;
struct V_140 V_141 ;
if ( ! V_77 )
return - V_51 ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
if ( F_78 ( V_6 ) ) {
V_2 -> V_181 = true ;
F_31 ( 1 , V_32 , V_6 , L_37 , V_33 ) ;
return - V_182 ;
}
if ( F_85 ( V_6 , & V_141 ) ) {
F_31 ( 1 , V_32 , V_6 , L_38 , V_33 ) ;
return - V_182 ;
}
V_78 -> V_155 = V_141 . V_155 ?
V_183 : V_184 ;
if ( F_53 ( V_6 ) ) {
V_77 -> type = V_163 ;
V_78 -> V_79 = F_39 ( V_6 , 0x07 , V_3 -> V_185 ) ;
V_78 -> V_86 = F_39 ( V_6 , 0x09 , V_3 -> V_186 ) ;
V_78 -> V_98 = V_3 -> V_187 ( V_6 ) ;
V_78 -> V_91 = F_39 ( V_6 , 0x20 , V_3 -> V_188 ) ;
V_78 -> V_88 = F_39 ( V_6 , 0x22 , V_3 -> V_189 ) ;
V_78 -> V_89 = F_39 ( V_6 , 0x24 , V_3 -> V_190 ) ;
V_78 -> V_93 = F_39 ( V_6 , 0x2a ,
V_3 -> V_191 ) / 2 ;
V_78 -> V_95 = F_39 ( V_6 , 0x2e , V_3 -> V_192 ) / 2 ;
V_78 -> V_96 = F_39 ( V_6 , 0x32 ,
V_3 -> V_193 ) / 2 ;
V_78 -> V_194 = ( ( F_38 ( V_6 , 0x05 ) & 0x10 ) ? V_151 : 0 ) |
( ( F_38 ( V_6 , 0x05 ) & 0x20 ) ? V_149 : 0 ) ;
if ( V_78 -> V_155 == V_183 ) {
V_78 -> V_86 += F_39 ( V_6 , 0x0b ,
V_3 -> V_195 ) ;
V_78 -> V_196 = F_39 ( V_6 , 0x2c ,
V_3 -> V_197 ) / 2 ;
V_78 -> V_198 = F_39 ( V_6 , 0x30 ,
V_3 -> V_199 ) / 2 ;
V_78 -> V_200 = F_39 ( V_6 , 0x34 ,
V_3 -> V_201 ) / 2 ;
}
F_89 ( V_6 , V_77 ) ;
} else {
if ( ! F_82 ( V_6 , & V_141 , V_77 ) )
goto V_202;
V_141 . V_147 += 1 ;
F_31 ( 1 , V_32 , V_6 , L_39 , V_33 , V_141 . V_147 ) ;
if ( ! F_82 ( V_6 , & V_141 , V_77 ) )
goto V_202;
V_141 . V_147 -= 2 ;
F_31 ( 1 , V_32 , V_6 , L_40 , V_33 , V_141 . V_147 ) ;
if ( F_82 ( V_6 , & V_141 , V_77 ) ) {
if ( V_2 -> V_181 ) {
F_31 ( 1 , V_32 , V_6 , L_41 , V_33 ) ;
F_46 ( V_6 , 0x86 , 0x06 , 0x00 ) ;
F_46 ( V_6 , 0x86 , 0x06 , 0x04 ) ;
F_46 ( V_6 , 0x86 , 0x06 , 0x02 ) ;
V_2 -> V_181 = false ;
return - V_182 ;
}
F_31 ( 1 , V_32 , V_6 , L_42 , V_33 ) ;
return - V_203 ;
}
V_2 -> V_181 = true ;
}
V_202:
if ( F_78 ( V_6 ) ) {
F_31 ( 1 , V_32 , V_6 , L_43 , V_33 ) ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
return - V_182 ;
}
if ( ( F_52 ( V_6 ) && V_78 -> V_98 > 170000000 ) ||
( F_53 ( V_6 ) && V_78 -> V_98 > 225000000 ) ) {
F_31 ( 1 , V_32 , V_6 , L_44 ,
V_33 , ( T_4 ) V_78 -> V_98 ) ;
return - V_203 ;
}
if ( V_32 > 1 )
F_93 ( V_6 -> V_204 , L_45 ,
V_77 , true ) ;
return 0 ;
}
static int F_94 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_7 * V_78 ;
int V_14 ;
if ( ! V_77 )
return - V_51 ;
if ( F_64 ( & V_2 -> V_77 , V_77 , 0 , false ) ) {
F_31 ( 1 , V_32 , V_6 , L_46 , V_33 ) ;
return 0 ;
}
V_78 = & V_77 -> V_78 ;
if ( ( F_52 ( V_6 ) && V_78 -> V_98 > 170000000 ) ||
( F_53 ( V_6 ) && V_78 -> V_98 > 225000000 ) ) {
F_31 ( 1 , V_32 , V_6 , L_44 ,
V_33 , ( T_4 ) V_78 -> V_98 ) ;
return - V_203 ;
}
F_89 ( V_6 , V_77 ) ;
V_2 -> V_77 = * V_77 ;
F_46 ( V_6 , 0x91 , 0x40 , V_78 -> V_155 ? 0x40 : 0x00 ) ;
V_14 = F_65 ( V_6 , V_77 ) ;
if ( V_14 ) {
F_66 ( V_6 , V_78 ) ;
}
F_70 ( V_6 ) ;
if ( V_32 > 1 )
F_93 ( V_6 -> V_204 , L_47 ,
V_77 , true ) ;
return 0 ;
}
static int F_95 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
* V_77 = V_2 -> V_77 ;
return 0 ;
}
static void F_96 ( struct V_5 * V_6 , bool V_205 )
{
F_40 ( V_6 , 0x01 , V_205 ? 0x00 : 0x78 ) ;
}
static void F_97 ( struct V_5 * V_6 , bool V_205 )
{
F_40 ( V_6 , 0x83 , V_205 ? 0xfe : 0xff ) ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_52 ( V_6 ) ) {
F_14 ( V_6 , 0x15 , 0xb0 ) ;
} else if ( F_53 ( V_6 ) ) {
F_41 ( V_6 , 0x00 , 0x03 , V_2 -> V_59 ) ;
V_2 -> V_3 -> V_206 ( V_6 , true ) ;
F_14 ( V_6 , 0x15 , 0xa0 ) ;
F_41 ( V_6 , 0x1a , 0x10 , 0x00 ) ;
} else {
F_31 ( 2 , V_32 , V_6 , L_19 ,
V_33 , V_2 -> V_59 ) ;
}
}
static void F_99 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_41 ( V_6 , 0x1a , 0x10 , 0x10 ) ;
F_100 ( 16 ) ;
F_14 ( V_6 , 0x15 , 0xbe ) ;
V_2 -> V_3 -> V_206 ( V_6 , false ) ;
}
static void F_101 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
if ( F_52 ( V_6 ) ) {
F_51 ( V_6 , V_3 -> V_207 [ 0 ] ) ;
F_24 ( V_6 , 0x00 , 0x08 ) ;
F_24 ( V_6 , 0x01 , 0x06 ) ;
F_24 ( V_6 , 0xc8 , 0x00 ) ;
} else if ( F_53 ( V_6 ) ) {
F_40 ( V_6 , 0x00 , V_2 -> V_59 & 0x03 ) ;
F_51 ( V_6 , V_3 -> V_207 [ 1 ] ) ;
if ( F_1 ( V_2 ) ) {
F_24 ( V_6 , 0x00 , 0xff ) ;
F_24 ( V_6 , 0x01 , 0xfe ) ;
F_24 ( V_6 , 0xc8 , 0x40 ) ;
}
F_45 ( V_6 , 0x3e , 0x00 ) ;
F_45 ( V_6 , 0xc3 , 0x39 ) ;
F_45 ( V_6 , 0x40 , 0x80 ) ;
} else {
F_31 ( 2 , V_32 , V_6 , L_19 ,
V_33 , V_2 -> V_59 ) ;
}
}
static int F_102 ( struct V_5 * V_6 ,
T_4 V_208 , T_4 V_209 , T_4 V_210 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_31 ( 2 , V_32 , V_6 , L_48 ,
V_33 , V_208 , V_2 -> V_59 ) ;
if ( V_208 == V_2 -> V_59 )
return 0 ;
if ( V_208 > V_2 -> V_3 -> V_211 )
return - V_51 ;
V_2 -> V_59 = V_208 ;
F_99 ( V_6 ) ;
F_101 ( V_6 ) ;
F_98 ( V_6 ) ;
F_103 ( V_6 , & V_212 ) ;
return 0 ;
}
static int F_104 ( struct V_5 * V_6 ,
struct V_213 * V_214 ,
struct V_215 * V_56 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_56 -> V_157 >= V_2 -> V_3 -> V_57 )
return - V_51 ;
V_56 -> V_56 = V_2 -> V_3 -> V_58 [ V_56 -> V_157 ] . V_56 ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
V_217 -> V_79 = V_2 -> V_77 . V_78 . V_79 ;
V_217 -> V_86 = V_2 -> V_77 . V_78 . V_86 ;
V_217 -> V_218 = V_219 ;
V_217 -> V_220 = V_221 ;
if ( V_2 -> V_77 . V_78 . V_117 & V_118 )
V_217 -> V_220 = ( V_2 -> V_77 . V_78 . V_86 <= 576 ) ?
V_222 : V_223 ;
}
static unsigned int F_106 ( struct V_1 * V_2 )
{
#define F_107 ( V_178 , V_179 , T_5 , T_6 , T_7 , T_8 ) { \
ADV76XX_OP_CH_SEL_##a, ADV76XX_OP_CH_SEL_##b, ADV76XX_OP_CH_SEL_##c, \
ADV76XX_OP_CH_SEL_##d, ADV76XX_OP_CH_SEL_##e, ADV76XX_OP_CH_SEL_##f }
#define F_108 ( T_9 ) [ADV7604_BUS_ORDER_##x]
static const unsigned int V_224 [ 6 ] [ 6 ] = {
F_108 ( V_225 ) = F_107 ( V_226 , V_227 , V_228 , V_225 , V_229 , V_230 ) ,
F_108 ( V_227 ) = F_107 ( V_228 , V_225 , V_226 , V_227 , V_230 , V_229 ) ,
F_108 ( V_230 ) = F_107 ( V_227 , V_226 , V_229 , V_230 , V_228 , V_225 ) ,
F_108 ( V_228 ) = F_107 ( V_230 , V_229 , V_225 , V_228 , V_227 , V_226 ) ,
F_108 ( V_229 ) = F_107 ( V_229 , V_230 , V_227 , V_226 , V_225 , V_228 ) ,
F_108 ( V_226 ) = F_107 ( V_225 , V_228 , V_230 , V_229 , V_226 , V_227 ) ,
} ;
return V_224 [ V_2 -> V_231 . V_232 ] [ V_2 -> V_217 -> V_224 >> 5 ] ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_16 ( V_6 , 0x02 , 0x02 ,
V_2 -> V_217 -> V_233 ? V_234 : 0 ) ;
F_14 ( V_6 , 0x03 , V_2 -> V_217 -> V_235 |
V_2 -> V_231 . V_236 ) ;
F_16 ( V_6 , 0x04 , 0xe0 , F_106 ( V_2 ) ) ;
F_16 ( V_6 , 0x05 , 0x01 ,
V_2 -> V_217 -> V_237 ? V_238 : 0 ) ;
}
static int F_110 ( struct V_5 * V_6 ,
struct V_213 * V_214 ,
struct V_239 * V_217 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_217 -> V_158 != V_2 -> V_159 )
return - V_51 ;
F_105 ( V_2 , & V_217 -> V_217 ) ;
if ( V_217 -> V_240 == V_241 ) {
struct V_216 * V_242 ;
V_242 = F_111 ( V_6 , V_214 , V_217 -> V_158 ) ;
V_217 -> V_217 . V_56 = V_242 -> V_56 ;
} else {
V_217 -> V_217 . V_56 = V_2 -> V_217 -> V_56 ;
}
return 0 ;
}
static int F_112 ( struct V_5 * V_6 ,
struct V_213 * V_214 ,
struct V_239 * V_217 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_55 * V_3 ;
if ( V_217 -> V_158 != V_2 -> V_159 )
return - V_51 ;
V_3 = V_55 ( V_2 , V_217 -> V_217 . V_56 ) ;
if ( V_3 == NULL )
V_3 = V_55 ( V_2 , V_243 ) ;
F_105 ( V_2 , & V_217 -> V_217 ) ;
V_217 -> V_217 . V_56 = V_3 -> V_56 ;
if ( V_217 -> V_240 == V_241 ) {
struct V_216 * V_242 ;
V_242 = F_111 ( V_6 , V_214 , V_217 -> V_158 ) ;
V_242 -> V_56 = V_217 -> V_217 . V_56 ;
} else {
V_2 -> V_217 = V_3 ;
F_109 ( V_2 ) ;
}
return 0 ;
}
static int F_113 ( struct V_5 * V_6 , T_4 V_135 , bool * V_244 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
const T_1 V_245 = F_13 ( V_6 , 0x43 ) ;
const T_1 V_246 = F_13 ( V_6 , 0x6b ) ;
const T_1 V_247 = F_13 ( V_6 , 0x70 ) ;
T_1 V_248 ;
T_1 V_249 ;
T_1 V_250 ;
if ( V_245 )
F_14 ( V_6 , 0x44 , V_245 ) ;
if ( V_247 )
F_14 ( V_6 , 0x71 , V_247 ) ;
if ( V_246 )
F_14 ( V_6 , 0x6c , V_246 ) ;
F_31 ( 2 , V_32 , V_6 , L_49 , V_33 ) ;
V_249 = V_245 & 0x98 ;
V_248 = F_53 ( V_6 )
? V_246 & V_3 -> V_251
: 0 ;
if ( V_249 || V_248 ) {
F_31 ( 1 , V_32 , V_6 ,
L_50 ,
V_33 , V_249 , V_248 ) ;
F_103 ( V_6 , & V_212 ) ;
if ( V_244 )
* V_244 = true ;
}
if ( V_246 & 0x01 ) {
F_31 ( 1 , V_32 , V_6 , L_51 , V_33 ,
( F_13 ( V_6 , 0x6a ) & 0x01 ) ? L_52 : L_53 ) ;
F_70 ( V_6 ) ;
if ( V_244 )
* V_244 = true ;
}
V_250 = V_247 & V_3 -> V_252 ;
if ( V_250 ) {
F_31 ( 1 , V_32 , V_6 , L_54 , V_33 , V_250 ) ;
F_61 ( V_6 ) ;
if ( V_244 )
* V_244 = true ;
}
return 0 ;
}
static int F_114 ( struct V_5 * V_6 , struct V_253 * V_43 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_1 * V_254 = NULL ;
memset ( V_43 -> V_160 , 0 , sizeof( V_43 -> V_160 ) ) ;
switch ( V_43 -> V_158 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
if ( V_2 -> V_43 . V_44 & ( 1 << V_43 -> V_158 ) )
V_254 = V_2 -> V_43 . V_43 ;
break;
default:
return - V_51 ;
}
if ( V_43 -> V_255 == 0 && V_43 -> V_256 == 0 ) {
V_43 -> V_256 = V_254 ? V_2 -> V_43 . V_256 : 0 ;
return 0 ;
}
if ( V_254 == NULL )
return - V_257 ;
if ( V_43 -> V_255 >= V_2 -> V_43 . V_256 )
return - V_51 ;
if ( V_43 -> V_255 + V_43 -> V_256 > V_2 -> V_43 . V_256 )
V_43 -> V_256 = V_2 -> V_43 . V_256 - V_43 -> V_255 ;
memcpy ( V_43 -> V_43 , V_254 + V_43 -> V_255 * 128 , V_43 -> V_256 * 128 ) ;
return 0 ;
}
static int F_115 ( const T_1 * V_43 )
{
T_1 T_6 ;
if ( ( V_43 [ 0x7e ] != 1 ) ||
( V_43 [ 0x80 ] != 0x02 ) ||
( V_43 [ 0x81 ] != 0x03 ) ) {
return - 1 ;
}
T_6 = V_43 [ 0x82 ] & 0x7f ;
if ( T_6 > 4 ) {
int V_30 = 0x84 ;
int V_258 = 0x80 + T_6 ;
do {
T_1 V_259 = V_43 [ V_30 ] >> 5 ;
T_1 V_31 = V_43 [ V_30 ] & 0x1f ;
if ( ( V_259 == 3 ) && ( V_31 >= 5 ) )
return V_30 + 4 ;
V_30 += V_31 + 1 ;
} while ( V_30 < V_258 );
}
return - 1 ;
}
static int F_116 ( struct V_5 * V_6 , struct V_253 * V_43 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
int V_260 ;
int V_14 ;
int V_30 ;
memset ( V_43 -> V_160 , 0 , sizeof( V_43 -> V_160 ) ) ;
if ( V_43 -> V_158 > V_65 )
return - V_51 ;
if ( V_43 -> V_255 != 0 )
return - V_51 ;
if ( V_43 -> V_256 == 0 ) {
V_2 -> V_43 . V_44 &= ~ ( 1 << V_43 -> V_158 ) ;
F_32 ( V_2 , V_2 -> V_43 . V_44 ) ;
F_27 ( V_6 , V_3 -> V_261 , 0x0f , V_2 -> V_43 . V_44 ) ;
V_2 -> V_152 . V_262 = 16 ;
V_2 -> V_152 . V_263 = 9 ;
if ( ! V_2 -> V_43 . V_44 )
V_2 -> V_43 . V_256 = 0 ;
F_31 ( 2 , V_32 , V_6 , L_55 ,
V_33 , V_43 -> V_158 , V_2 -> V_43 . V_44 ) ;
return 0 ;
}
if ( V_43 -> V_256 > 2 ) {
V_43 -> V_256 = 2 ;
return - V_264 ;
}
F_31 ( 2 , V_32 , V_6 , L_56 ,
V_33 , V_43 -> V_158 , V_2 -> V_43 . V_44 ) ;
F_117 ( & V_2 -> V_42 ) ;
F_32 ( V_2 , 0 ) ;
F_27 ( V_6 , V_3 -> V_261 , 0x0f , 0x00 ) ;
V_260 = F_115 ( V_43 -> V_43 ) ;
if ( V_260 < 0 )
V_260 = 0xc0 ;
switch ( V_43 -> V_158 ) {
case V_62 :
V_2 -> V_265 [ 0 ] = V_43 -> V_43 [ V_260 ] ;
V_2 -> V_265 [ 1 ] = V_43 -> V_43 [ V_260 + 1 ] ;
break;
case V_63 :
F_26 ( V_6 , 0x70 , V_43 -> V_43 [ V_260 ] ) ;
F_26 ( V_6 , 0x71 , V_43 -> V_43 [ V_260 + 1 ] ) ;
break;
case V_64 :
F_26 ( V_6 , 0x72 , V_43 -> V_43 [ V_260 ] ) ;
F_26 ( V_6 , 0x73 , V_43 -> V_43 [ V_260 + 1 ] ) ;
break;
case V_65 :
F_26 ( V_6 , 0x74 , V_43 -> V_43 [ V_260 ] ) ;
F_26 ( V_6 , 0x75 , V_43 -> V_43 [ V_260 + 1 ] ) ;
break;
default:
return - V_51 ;
}
if ( V_3 -> type == V_266 ) {
F_26 ( V_6 , 0x76 , V_260 & 0xff ) ;
F_27 ( V_6 , 0x77 , 0x40 , ( V_260 & 0x100 ) >> 2 ) ;
} else {
F_27 ( V_6 , 0x71 , 0x01 , ( V_260 & 0x100 ) >> 8 ) ;
}
V_43 -> V_43 [ V_260 ] = V_2 -> V_265 [ 0 ] ;
V_43 -> V_43 [ V_260 + 1 ] = V_2 -> V_265 [ 1 ] ;
memcpy ( V_2 -> V_43 . V_43 , V_43 -> V_43 , 128 * V_43 -> V_256 ) ;
V_2 -> V_43 . V_256 = V_43 -> V_256 ;
V_2 -> V_152 = F_118 ( V_43 -> V_43 [ 0x15 ] ,
V_43 -> V_43 [ 0x16 ] ) ;
V_2 -> V_43 . V_44 |= 1 << V_43 -> V_158 ;
V_14 = F_30 ( V_6 , 128 * V_43 -> V_256 , V_2 -> V_43 . V_43 ) ;
if ( V_14 < 0 ) {
F_67 ( V_6 , L_57 , V_14 , V_43 -> V_158 ) ;
return V_14 ;
}
F_27 ( V_6 , V_3 -> V_261 , 0x0f , V_2 -> V_43 . V_44 ) ;
for ( V_30 = 0 ; V_30 < 1000 ; V_30 ++ ) {
if ( F_25 ( V_6 , V_3 -> V_267 ) & V_2 -> V_43 . V_44 )
break;
F_119 ( 1 ) ;
}
if ( V_30 == 1000 ) {
F_67 ( V_6 , L_58 , V_2 -> V_43 . V_44 ) ;
return - V_268 ;
}
F_120 ( V_2 -> V_269 ,
& V_2 -> V_42 , V_270 / 10 ) ;
return 0 ;
}
static int F_121 ( struct V_5 * V_6 , int V_157 ,
union V_271 * V_272 )
{
T_10 V_273 [ 32 ] ;
T_1 V_31 ;
int V_30 ;
if ( ! ( F_13 ( V_6 , 0x60 ) & V_274 [ V_157 ] . V_275 ) ) {
F_55 ( V_6 , L_59 ,
V_274 [ V_157 ] . V_276 ) ;
return - V_277 ;
}
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ )
V_273 [ V_30 ] = F_21 ( V_6 ,
V_274 [ V_157 ] . V_278 + V_30 ) ;
V_31 = V_273 [ 2 ] + 1 ;
if ( V_31 + 3 > sizeof( V_273 ) ) {
F_67 ( V_6 , L_60 , V_33 ,
V_274 [ V_157 ] . V_276 , V_31 ) ;
return - V_277 ;
}
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
V_273 [ V_30 + 3 ] = F_21 ( V_6 ,
V_274 [ V_157 ] . V_279 + V_30 ) ;
if ( F_122 ( V_272 , V_273 ) < 0 ) {
F_67 ( V_6 , L_61 , V_33 ,
V_274 [ V_157 ] . V_276 ) ;
return - V_277 ;
}
return 0 ;
}
static void F_123 ( struct V_5 * V_6 )
{
int V_30 ;
if ( ! F_75 ( V_6 ) ) {
F_55 ( V_6 , L_62 ) ;
return;
}
for ( V_30 = 0 ; V_30 < F_87 ( V_274 ) ; V_30 ++ ) {
union V_271 V_272 ;
struct V_11 * V_12 = F_124 ( V_6 ) ;
if ( F_121 ( V_6 , V_30 , & V_272 ) )
return;
F_125 ( V_280 , & V_12 -> V_281 , & V_272 ) ;
}
}
static int F_126 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
struct V_76 V_77 ;
struct V_140 V_141 ;
T_1 V_282 = F_13 ( V_6 , 0x02 ) ;
T_1 V_283 ;
T_1 V_284 ;
static const char * const V_285 [ 16 ] = {
L_63 , L_64 , L_65 , L_66 ,
L_65 , L_67 , L_65 , L_68 ,
L_65 , L_69 , L_70 ,
L_65 , L_65 , L_65 , L_65 , L_71
} ;
static const char * const V_286 [ 16 ] = {
L_72 , L_73 ,
L_74 , L_75 ,
L_76 , L_77 ,
L_78 , L_79 ,
L_80 , L_80 , L_80 , L_80 , L_80 ,
L_80 , L_80 , L_81
} ;
static const char * const V_287 [ 16 ] = {
L_72 , L_73 ,
L_74 , L_75 ,
L_76 , L_77 ,
L_78 , L_79 ,
L_82 , L_83 , L_84 , L_80 , L_80 ,
L_80 , L_80 , L_80
} ;
static const char * const V_288 [] = {
L_85 ,
L_72 ,
L_73 ,
} ;
static const char * const V_289 [ 4 ] = {
L_86 ,
L_87 ,
L_88 ,
L_89
} ;
F_55 ( V_6 , L_90 ) ;
F_55 ( V_6 , L_91 , F_72 ( V_6 ) ? L_92 : L_93 ) ;
V_283 = F_25 ( V_6 , V_3 -> V_267 ) ;
F_55 ( V_6 , L_94 ,
( ( V_283 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_283 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_283 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_283 & 0x08 ) ? L_95 : L_96 ) ) ;
F_55 ( V_6 , L_97 , ! ! ( F_19 ( V_6 , 0x2a ) & 0x01 ) ?
L_98 : L_99 ) ;
F_55 ( V_6 , L_100 ) ;
V_284 = V_3 -> V_72 ( V_6 ) ;
F_55 ( V_6 , L_101 ,
( ( V_284 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_284 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_284 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_284 & 0x08 ) ? L_95 : L_96 ) ) ;
F_55 ( V_6 , L_102 ,
F_73 ( V_6 ) ? L_103 : L_104 ) ;
F_55 ( V_6 , L_105 ,
F_74 ( V_6 ) ? L_103 : L_104 ) ;
F_55 ( V_6 , L_106 , F_76 ( V_6 ) ? L_103 : L_104 ) ;
F_55 ( V_6 , L_107 , F_77 ( V_6 ) ? L_103 : L_104 ) ;
F_55 ( V_6 , L_108 , F_79 ( V_6 ) ? L_103 : L_104 ) ;
F_55 ( V_6 , L_109 ,
( F_80 ( V_6 ) ) ? L_93 : L_92 ) ;
F_55 ( V_6 , L_110 ,
F_13 ( V_6 , 0x01 ) & 0x0f , F_13 ( V_6 , 0x00 ) & 0x3f ,
( F_13 ( V_6 , 0x01 ) & 0x70 ) >> 4 ) ;
F_55 ( V_6 , L_111 ) ;
if ( F_85 ( V_6 , & V_141 ) )
F_55 ( V_6 , L_112 ) ;
else
F_55 ( V_6 , L_113 ,
V_141 . V_146 , V_141 . V_143 , V_141 . V_147 ,
V_141 . V_155 ? L_35 : L_36 ,
V_141 . V_148 , V_141 . V_150 ) ;
if ( F_92 ( V_6 , & V_77 ) )
F_55 ( V_6 , L_114 ) ;
else
F_93 ( V_6 -> V_204 , L_115 ,
& V_77 , true ) ;
F_93 ( V_6 -> V_204 , L_116 ,
& V_2 -> V_77 , true ) ;
if ( F_78 ( V_6 ) )
return 0 ;
F_55 ( V_6 , L_117 ) ;
F_55 ( V_6 , L_118 ,
V_288 [ V_2 -> V_115 ] ) ;
F_55 ( V_6 , L_119 ,
V_286 [ V_282 >> 4 ] ) ;
F_55 ( V_6 , L_120 ,
( V_282 & 0x02 ) ? L_121 : L_122 ,
( V_282 & 0x04 ) ? L_123 : L_124 ,
( ( ( V_282 >> 2 ) & 0x01 ) ^ ( V_282 & 0x01 ) ) ?
L_98 : L_99 ,
( V_282 & 0x08 ) ? L_98 : L_99 ) ;
F_55 ( V_6 , L_125 ,
V_285 [ F_43 ( V_6 , V_3 -> V_290 ) >> 4 ] ) ;
if ( ! F_53 ( V_6 ) )
return 0 ;
F_55 ( V_6 , L_126 , F_75 ( V_6 ) ? L_52 : L_127 ) ;
F_55 ( V_6 , L_128 ,
( F_38 ( V_6 , 0x00 ) & 0x03 ) + 'A' ) ;
F_55 ( V_6 , L_129 ,
( F_38 ( V_6 , 0x05 ) & 0x40 ) ? L_104 : L_103 ) ;
F_55 ( V_6 , L_130 ,
( F_38 ( V_6 , 0x04 ) & 0x20 ) ? L_131 : L_132 ,
( F_38 ( V_6 , 0x04 ) & 0x10 ) ? L_133 : L_134 ) ;
if ( F_75 ( V_6 ) ) {
bool V_291 = F_38 ( V_6 , 0x04 ) & 0x01 ;
bool V_292 = F_38 ( V_6 , 0x18 ) & 0x01 ;
bool V_293 = F_13 ( V_6 , 0x65 ) & 0x40 ;
F_55 ( V_6 , L_135 ,
V_291 ? L_136 : L_137 ,
V_292 ? L_138 : L_139 ,
V_293 ? L_140 : L_98 ) ;
if ( V_291 && V_292 ) {
F_55 ( V_6 , L_141 ,
( F_38 ( V_6 , 0x07 ) & 0x20 ) ? L_142 : L_143 ) ;
}
F_55 ( V_6 , L_144 , ( F_38 ( V_6 , 0x5b ) << 12 ) +
( F_38 ( V_6 , 0x5c ) << 8 ) +
( F_38 ( V_6 , 0x5d ) & 0xf0 ) ) ;
F_55 ( V_6 , L_145 , ( ( F_38 ( V_6 , 0x5d ) & 0x0f ) << 16 ) +
( F_38 ( V_6 , 0x5e ) << 8 ) +
F_38 ( V_6 , 0x5f ) ) ;
F_55 ( V_6 , L_146 , ( F_38 ( V_6 , 0x04 ) & 0x40 ) ? L_93 : L_92 ) ;
F_55 ( V_6 , L_147 , V_289 [ ( F_38 ( V_6 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_55 ( V_6 , L_148 , V_287 [ F_38 ( V_6 , 0x53 ) & 0xf ] ) ;
F_123 ( V_6 ) ;
}
return 0 ;
}
static int F_127 ( struct V_5 * V_6 ,
struct V_294 * V_295 ,
struct V_296 * V_297 )
{
switch ( V_297 -> type ) {
case V_298 :
return F_128 ( V_6 , V_295 , V_297 ) ;
case V_299 :
return F_129 ( V_6 , V_295 , V_297 ) ;
default:
return - V_51 ;
}
}
static int F_130 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_70 * V_3 = V_2 -> V_3 ;
struct V_300 * V_231 = & V_2 -> V_231 ;
F_40 ( V_6 , 0x48 ,
( V_231 -> V_301 ? 0x80 : 0 ) |
( V_231 -> V_302 ? 0x40 : 0 ) ) ;
F_99 ( V_6 ) ;
if ( V_231 -> V_303 >= 0 &&
V_231 -> V_303 < V_2 -> V_159 ) {
V_2 -> V_59 = V_231 -> V_303 ;
F_101 ( V_6 ) ;
F_98 ( V_6 ) ;
}
F_14 ( V_6 , 0x0c , 0x42 ) ;
F_14 ( V_6 , 0x0b , 0x44 ) ;
F_45 ( V_6 , 0xcf , 0x01 ) ;
F_16 ( V_6 , 0x02 , 0x0f ,
V_231 -> V_304 << 3 |
V_231 -> V_305 << 2 |
V_231 -> V_306 << 0 ) ;
F_16 ( V_6 , 0x05 , 0x0e , V_231 -> V_307 << 3 |
V_231 -> V_308 << 2 |
V_231 -> V_309 << 1 ) ;
F_109 ( V_2 ) ;
F_45 ( V_6 , 0x69 , 0x30 ) ;
F_14 ( V_6 , 0x06 , 0xa0 | V_231 -> V_310 << 2 |
V_231 -> V_311 << 1 | V_231 -> V_312 ) ;
F_14 ( V_6 , 0x14 , 0x40 | V_231 -> V_313 << 4 |
V_231 -> V_314 << 2 |
V_231 -> V_315 ) ;
F_45 ( V_6 , 0xba , ( V_231 -> V_316 << 1 ) | 0x01 ) ;
F_45 ( V_6 , 0xf3 , 0xdc ) ;
F_45 ( V_6 , 0xf9 , 0x23 ) ;
F_45 ( V_6 , 0x45 , 0x23 ) ;
F_45 ( V_6 , 0xc9 , 0x2d ) ;
F_41 ( V_6 , 0x15 , 0x03 , 0x03 ) ;
F_41 ( V_6 , 0x1a , 0x0e , 0x08 ) ;
F_41 ( V_6 , 0x68 , 0x06 , 0x06 ) ;
F_24 ( V_6 , 0xb5 , 0x01 ) ;
if ( F_1 ( V_2 ) ) {
F_24 ( V_6 , 0x02 , V_231 -> V_317 ) ;
F_16 ( V_6 , 0x30 , 1 << 4 , V_231 -> V_318 << 4 ) ;
}
F_14 ( V_6 , 0x40 , 0xc0 | V_231 -> V_319 ) ;
F_14 ( V_6 , 0x46 , 0x98 ) ;
F_14 ( V_6 , 0x6e , V_3 -> V_251 ) ;
F_14 ( V_6 , 0x73 , V_3 -> V_252 ) ;
V_3 -> V_320 ( V_6 ) ;
return F_131 ( V_6 -> V_321 ) ;
}
static void F_132 ( struct V_5 * V_6 )
{
F_14 ( V_6 , 0x41 , 0xd7 ) ;
}
static void F_133 ( struct V_5 * V_6 )
{
F_14 ( V_6 , 0x41 , 0xd0 ) ;
}
static void F_134 ( struct V_5 * V_6 )
{
F_14 ( V_6 , 0x41 , 0xd0 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
unsigned int V_30 ;
for ( V_30 = 1 ; V_30 < F_87 ( V_2 -> V_13 ) ; ++ V_30 ) {
if ( V_2 -> V_13 [ V_30 ] )
F_136 ( V_2 -> V_13 [ V_30 ] ) ;
}
}
static struct V_11 * F_137 ( struct V_5 * V_6 ,
T_1 V_17 , T_1 V_322 )
{
struct V_11 * V_12 = F_124 ( V_6 ) ;
if ( V_17 )
F_14 ( V_6 , V_322 , V_17 << 1 ) ;
return F_138 ( V_12 -> V_323 , F_13 ( V_6 , V_322 ) >> 1 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_324 V_325 ;
struct V_326 * V_327 ;
struct V_326 * V_328 ;
unsigned int V_117 ;
T_4 V_329 ;
V_328 = V_2 -> V_13 [ V_21 ] -> V_281 . V_330 ;
V_327 = F_140 ( V_328 , NULL ) ;
if ( ! V_327 )
return - V_51 ;
F_141 ( V_327 , & V_325 ) ;
if ( ! F_142 ( V_327 , L_149 , & V_329 ) )
V_2 -> V_231 . V_303 = V_329 ;
else
V_2 -> V_231 . V_303 = - 1 ;
F_143 ( V_327 ) ;
V_117 = V_325 . V_331 . V_332 . V_117 ;
if ( V_117 & V_333 )
V_2 -> V_231 . V_311 = 1 ;
if ( V_117 & V_334 )
V_2 -> V_231 . V_310 = 1 ;
if ( V_117 & V_335 )
V_2 -> V_231 . V_312 = 1 ;
if ( V_325 . V_336 == V_337 ) {
V_2 -> V_231 . V_308 = 1 ;
V_2 -> V_231 . V_305 = 1 ;
}
V_2 -> V_231 . V_319 = V_338 ;
V_2 -> V_231 . V_339 [ V_23 ] = 0x42 ;
V_2 -> V_231 . V_339 [ V_24 ] = 0x40 ;
V_2 -> V_231 . V_339 [ V_25 ] = 0x3e ;
V_2 -> V_231 . V_339 [ V_340 ] = 0x38 ;
V_2 -> V_231 . V_339 [ V_341 ] = 0x3c ;
V_2 -> V_231 . V_339 [ V_26 ] = 0x26 ;
V_2 -> V_231 . V_339 [ V_27 ] = 0x32 ;
V_2 -> V_231 . V_339 [ V_28 ] = 0x36 ;
V_2 -> V_231 . V_339 [ V_45 ] = 0x34 ;
V_2 -> V_231 . V_339 [ V_46 ] = 0x30 ;
V_2 -> V_231 . V_339 [ V_47 ] = 0x22 ;
V_2 -> V_231 . V_339 [ V_48 ] = 0x24 ;
V_2 -> V_231 . V_301 = 0 ;
V_2 -> V_231 . V_302 = 0 ;
V_2 -> V_231 . V_307 = 1 ;
V_2 -> V_231 . V_306 = 1 ;
V_2 -> V_231 . V_236 = V_342 ;
V_2 -> V_231 . V_232 = V_343 ;
return 0 ;
}
static int F_144 ( struct V_1 * V_2 , int V_344 )
{
int V_14 ;
if ( ! V_2 -> V_13 [ V_344 ] )
return - V_345 ;
V_2 -> V_16 [ V_344 ] =
F_145 ( V_2 -> V_13 [ V_344 ] ,
& V_346 [ V_344 ] ) ;
if ( F_146 ( V_2 -> V_16 [ V_344 ] ) ) {
V_14 = F_147 ( V_2 -> V_16 [ V_344 ] ) ;
F_10 ( V_2 -> V_13 [ V_344 ] ,
L_150 ,
V_344 , V_14 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_148 ( struct V_1 * V_2 )
{
int V_30 , V_14 ;
for ( V_30 = V_23 ; V_30 < V_347 ; V_30 ++ ) {
V_14 = F_144 ( V_2 , V_30 ) ;
if ( V_14 && ( V_14 != - V_345 ) )
return V_14 ;
}
return 0 ;
}
static int F_149 ( struct V_11 * V_12 ,
const struct V_348 * V_125 )
{
static const struct V_76 V_349 =
V_350 ;
struct V_1 * V_2 ;
struct V_351 * V_124 ;
struct V_5 * V_6 ;
unsigned int V_30 ;
unsigned int V_15 , V_352 ;
int V_14 ;
if ( ! F_150 ( V_12 -> V_323 , V_353 ) )
return - V_268 ;
F_151 ( 1 , V_32 , V_12 , L_151 ,
V_12 -> V_17 << 1 ) ;
V_2 = F_152 ( & V_12 -> V_281 , sizeof( * V_2 ) , V_354 ) ;
if ( ! V_2 ) {
F_10 ( V_12 , L_152 ) ;
return - V_355 ;
}
V_2 -> V_13 [ V_21 ] = V_12 ;
V_2 -> V_181 = true ;
V_2 -> V_59 = ~ 0 ;
if ( F_153 ( V_356 ) && V_12 -> V_281 . V_330 ) {
const struct V_357 * V_358 ;
V_358 = F_154 ( V_359 , V_12 -> V_281 . V_330 ) ;
V_2 -> V_3 = V_358 -> V_254 ;
V_14 = F_139 ( V_2 ) ;
if ( V_14 < 0 ) {
F_10 ( V_12 , L_153 ) ;
return V_14 ;
}
} else if ( V_12 -> V_281 . V_360 ) {
struct V_300 * V_231 = V_12 -> V_281 . V_360 ;
V_2 -> V_3 = ( const struct V_70 * ) V_125 -> V_361 ;
V_2 -> V_231 = * V_231 ;
} else {
F_10 ( V_12 , L_154 ) ;
return - V_345 ;
}
for ( V_30 = 0 ; V_30 < V_2 -> V_3 -> V_35 ; ++ V_30 ) {
V_2 -> V_36 [ V_30 ] =
F_155 ( & V_12 -> V_281 , L_155 , V_30 ,
V_362 ) ;
if ( F_146 ( V_2 -> V_36 [ V_30 ] ) )
return F_147 ( V_2 -> V_36 [ V_30 ] ) ;
if ( V_2 -> V_36 [ V_30 ] )
F_156 ( V_12 , L_156 , V_30 ) ;
}
V_2 -> V_77 = V_349 ;
V_2 -> V_217 = V_55 ( V_2 , V_243 ) ;
V_6 = & V_2 -> V_6 ;
F_157 ( V_6 , V_12 , & V_363 ) ;
snprintf ( V_6 -> V_204 , sizeof( V_6 -> V_204 ) , L_157 ,
V_125 -> V_204 , F_158 ( V_12 -> V_323 ) ,
V_12 -> V_17 ) ;
V_6 -> V_117 |= V_364 | V_365 ;
V_14 = F_144 ( V_2 , V_21 ) ;
if ( V_14 ) {
F_67 ( V_6 , L_158 ) ;
return - V_345 ;
}
switch ( V_2 -> V_3 -> type ) {
case V_266 :
V_14 = F_9 ( V_2 -> V_16 [ V_21 ] , 0xfb , & V_15 ) ;
if ( V_14 ) {
F_67 ( V_6 , L_159 , V_14 ) ;
return - V_345 ;
}
if ( V_15 != 0x68 ) {
F_67 ( V_6 , L_160 ,
V_12 -> V_17 << 1 ) ;
return - V_345 ;
}
break;
case V_366 :
case V_367 :
V_14 = F_9 ( V_2 -> V_16 [ V_21 ] ,
0xea ,
& V_15 ) ;
if ( V_14 ) {
F_67 ( V_6 , L_159 , V_14 ) ;
return - V_345 ;
}
V_352 = V_15 << 8 ;
V_14 = F_9 ( V_2 -> V_16 [ V_21 ] ,
0xeb ,
& V_15 ) ;
if ( V_14 ) {
F_67 ( V_6 , L_159 , V_14 ) ;
return - V_345 ;
}
V_15 |= V_352 ;
if ( ( V_2 -> V_3 -> type == V_366 && V_15 != 0x2051 ) ||
( V_2 -> V_3 -> type == V_367 && V_15 != 0x2041 ) ) {
F_67 ( V_6 , L_161 ,
V_12 -> V_17 << 1 ) ;
return - V_345 ;
}
break;
}
V_124 = & V_2 -> V_124 ;
F_159 ( V_124 , F_1 ( V_2 ) ? 9 : 8 ) ;
F_160 ( V_124 , & V_368 ,
V_126 , - 128 , 127 , 1 , 0 ) ;
F_160 ( V_124 , & V_368 ,
V_127 , 0 , 255 , 1 , 128 ) ;
F_160 ( V_124 , & V_368 ,
V_128 , 0 , 255 , 1 , 128 ) ;
F_160 ( V_124 , & V_368 ,
V_129 , 0 , 128 , 1 , 0 ) ;
V_2 -> V_71 = F_160 ( V_124 , NULL ,
V_369 , 0 ,
( 1 << V_2 -> V_3 -> V_35 ) - 1 , 0 , 0 ) ;
V_2 -> V_370 =
F_161 ( V_124 , & V_368 ,
V_130 , V_120 ,
0 , V_116 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_371 =
F_162 ( V_124 , & V_372 , NULL ) ;
V_2 -> V_373 =
F_162 ( V_124 , & V_374 , NULL ) ;
V_2 -> V_375 =
F_162 ( V_124 , & V_376 , NULL ) ;
V_6 -> V_321 = V_124 ;
if ( V_124 -> error ) {
V_14 = V_124 -> error ;
goto V_377;
}
V_2 -> V_71 -> V_378 = true ;
V_2 -> V_370 -> V_378 = true ;
if ( F_1 ( V_2 ) )
V_2 -> V_371 -> V_378 = true ;
V_2 -> V_373 -> V_378 = true ;
V_2 -> V_375 -> V_378 = true ;
if ( F_61 ( V_6 ) ) {
V_14 = - V_345 ;
goto V_377;
}
for ( V_30 = 1 ; V_30 < V_347 ; ++ V_30 ) {
if ( ! ( F_34 ( V_30 ) & V_2 -> V_3 -> V_50 ) )
continue;
V_2 -> V_13 [ V_30 ] =
F_137 ( V_6 , V_2 -> V_231 . V_339 [ V_30 ] ,
0xf2 + V_30 ) ;
if ( V_2 -> V_13 [ V_30 ] == NULL ) {
V_14 = - V_355 ;
F_67 ( V_6 , L_162 , V_30 ) ;
goto V_379;
}
}
V_2 -> V_269 = F_163 ( V_12 -> V_204 ) ;
if ( ! V_2 -> V_269 ) {
F_67 ( V_6 , L_163 ) ;
V_14 = - V_355 ;
goto V_379;
}
F_164 ( & V_2 -> V_42 ,
F_36 ) ;
V_2 -> V_159 = V_2 -> V_3 -> V_35
+ ( V_2 -> V_3 -> V_4 ? 2 : 0 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_159 ; ++ V_30 )
V_2 -> V_380 [ V_30 ] . V_117 = V_381 ;
V_2 -> V_380 [ V_2 -> V_159 ] . V_117 = V_382 ;
V_14 = F_165 ( & V_6 -> V_383 , V_2 -> V_159 + 1 ,
V_2 -> V_380 ) ;
if ( V_14 )
goto V_384;
V_14 = F_148 ( V_2 ) ;
if ( V_14 )
goto V_385;
V_14 = F_130 ( V_6 ) ;
if ( V_14 )
goto V_385;
F_55 ( V_6 , L_164 , V_12 -> V_204 ,
V_12 -> V_17 << 1 , V_12 -> V_323 -> V_204 ) ;
V_14 = F_166 ( V_6 ) ;
if ( V_14 )
goto V_385;
return 0 ;
V_385:
F_167 ( & V_6 -> V_383 ) ;
V_384:
F_168 ( & V_2 -> V_42 ) ;
F_169 ( V_2 -> V_269 ) ;
V_379:
F_135 ( V_2 ) ;
V_377:
F_170 ( V_124 ) ;
return V_14 ;
}
static int F_171 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_172 ( V_12 ) ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_168 ( & V_2 -> V_42 ) ;
F_169 ( V_2 -> V_269 ) ;
F_173 ( V_6 ) ;
F_167 ( & V_6 -> V_383 ) ;
F_135 ( F_2 ( V_6 ) ) ;
F_170 ( V_6 -> V_321 ) ;
return 0 ;
}
