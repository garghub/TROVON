static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 ;
}
static bool F_2 ( const struct V_5 * V_6 , void * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_9 [ V_8 ] . V_10 . V_11 ; V_8 ++ )
if ( F_3 ( V_6 , V_9 + V_8 , 0 , false ) )
return false ;
return true ;
}
static inline struct V_1 * F_4 ( struct V_12 * V_13 )
{
return F_5 ( V_13 , struct V_1 , V_13 ) ;
}
static inline unsigned F_6 ( const struct V_14 * V_6 )
{
return F_7 ( V_6 ) ;
}
static inline unsigned F_8 ( const struct V_14 * V_6 )
{
return F_9 ( V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_15 , T_1 V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 [ V_15 ] ;
int V_20 ;
unsigned int V_21 ;
V_20 = F_11 ( V_2 -> V_22 [ V_15 ] , V_16 , & V_21 ) ;
if ( V_20 ) {
F_12 ( V_18 , L_1 ,
V_18 -> V_23 , V_16 ) ;
return V_20 ;
}
return V_21 ;
}
static int F_13 ( struct V_1 * V_2 , int V_15 ,
unsigned int V_24 , const void * V_21 ,
T_2 V_25 )
{
struct V_22 * V_22 = V_2 -> V_22 [ V_15 ] ;
if ( V_25 > V_26 )
V_25 = V_26 ;
return F_14 ( V_22 , V_24 , V_21 , V_25 ) ;
}
static inline int F_15 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_27 , V_16 ) ;
}
static inline int F_16 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_27 ] , V_16 , V_21 ) ;
}
static inline int F_18 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 ,
T_1 V_21 )
{
return F_16 ( V_13 , V_16 , ( F_15 ( V_13 , V_16 ) & ~ V_28 ) | V_21 ) ;
}
static inline int F_19 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_29 , V_16 ) ;
}
static inline int F_20 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_29 ] , V_16 , V_21 ) ;
}
static inline int F_21 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_30 , V_16 ) ;
}
static inline int F_22 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_30 ] , V_16 , V_21 ) ;
}
static inline int F_23 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 ,
T_1 V_21 )
{
return F_22 ( V_13 , V_16 , ( F_21 ( V_13 , V_16 ) & ~ V_28 ) | V_21 ) ;
}
static inline int F_24 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_31 , V_16 ) ;
}
static inline int F_25 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_31 ] , V_16 , V_21 ) ;
}
static inline int F_26 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_32 , V_16 ) ;
}
static inline int F_27 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_32 ] , V_16 , V_21 ) ;
}
static inline int F_28 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_33 , V_16 ) ;
}
static inline int F_29 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_33 ] , V_16 , V_21 ) ;
}
static inline int F_30 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 , T_1 V_21 )
{
return F_29 ( V_13 , V_16 , ( F_28 ( V_13 , V_16 ) & ~ V_28 ) | V_21 ) ;
}
static inline int F_31 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_34 , V_16 ) ;
}
static inline int F_32 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_34 ] , V_16 , V_21 ) ;
}
static inline int F_33 ( struct V_12 * V_13 ,
unsigned int V_35 , const T_1 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_20 = 0 ;
int V_8 = 0 ;
int V_36 = 0 ;
F_34 ( 2 , V_37 , V_13 , L_2 ,
V_38 , V_35 ) ;
while ( ! V_20 && V_8 < V_35 ) {
V_36 = ( V_35 - V_8 ) > V_26 ?
V_26 :
( V_35 - V_8 ) ;
V_20 = F_13 ( V_2 , V_34 ,
V_8 , V_21 + V_8 , V_36 ) ;
V_8 += V_36 ;
}
return V_20 ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_39 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_40 ; ++ V_8 )
F_36 ( V_2 -> V_41 [ V_8 ] , V_39 & F_37 ( V_8 ) ) ;
F_38 ( & V_2 -> V_13 , V_42 , & V_39 ) ;
}
static void F_39 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_40 ( V_44 ) ;
struct V_1 * V_2 = F_5 ( V_46 , struct V_1 ,
V_47 ) ;
struct V_12 * V_13 = & V_2 -> V_13 ;
F_34 ( 2 , V_37 , V_13 , L_3 , V_38 ) ;
F_35 ( V_2 , V_2 -> V_48 . V_49 ) ;
}
static inline int F_41 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_50 , V_16 ) ;
}
static T_3 F_42 ( struct V_12 * V_13 , T_1 V_16 , T_3 V_28 )
{
return ( ( F_41 ( V_13 , V_16 ) << 8 ) | F_41 ( V_13 , V_16 + 1 ) ) & V_28 ;
}
static inline int F_43 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_50 ] , V_16 , V_21 ) ;
}
static inline int F_44 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 , T_1 V_21 )
{
return F_43 ( V_13 , V_16 , ( F_41 ( V_13 , V_16 ) & ~ V_28 ) | V_21 ) ;
}
static inline int F_45 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_51 ] , V_16 , V_21 ) ;
}
static inline int F_46 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_52 , V_16 ) ;
}
static T_3 F_47 ( struct V_12 * V_13 , T_1 V_16 , T_3 V_28 )
{
return ( ( F_46 ( V_13 , V_16 ) << 8 ) | F_46 ( V_13 , V_16 + 1 ) ) & V_28 ;
}
static inline int F_48 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_52 ] , V_16 , V_21 ) ;
}
static inline int F_49 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 , T_1 V_21 )
{
return F_48 ( V_13 , V_16 , ( F_46 ( V_13 , V_16 ) & ~ V_28 ) | V_21 ) ;
}
static inline int F_50 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_53 , V_16 ) ;
}
static inline int F_51 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_53 ] , V_16 , V_21 ) ;
}
static int F_52 ( struct V_12 * V_13 , unsigned int V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
unsigned int V_54 = V_16 >> 8 ;
unsigned int V_21 ;
int V_20 ;
if ( ! ( F_37 ( V_54 ) & V_2 -> V_3 -> V_55 ) )
return - V_56 ;
V_16 &= 0xff ;
V_20 = F_11 ( V_2 -> V_22 [ V_54 ] , V_16 , & V_21 ) ;
return V_20 ? V_20 : V_21 ;
}
static int F_53 ( struct V_12 * V_13 , unsigned int V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
unsigned int V_54 = V_16 >> 8 ;
if ( ! ( F_37 ( V_54 ) & V_2 -> V_3 -> V_55 ) )
return - V_56 ;
V_16 &= 0xff ;
return F_17 ( V_2 -> V_22 [ V_54 ] , V_16 , V_21 ) ;
}
static void F_54 ( struct V_12 * V_13 ,
const struct V_57 * V_58 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_58 [ V_8 ] . V_16 != V_59 ; V_8 ++ )
F_53 ( V_13 , V_58 [ V_8 ] . V_16 , V_58 [ V_8 ] . V_21 ) ;
}
static const struct V_60 *
V_60 ( struct V_1 * V_2 , T_4 V_61 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_62 ; ++ V_8 ) {
if ( V_2 -> V_3 -> V_63 [ V_8 ] . V_61 == V_61 )
return & V_2 -> V_3 -> V_63 [ V_8 ] ;
}
return NULL ;
}
static inline bool F_55 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return V_2 -> V_64 == V_65 ||
V_2 -> V_64 == V_66 ;
}
static inline bool F_56 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return V_2 -> V_64 == V_67 ||
V_2 -> V_64 == V_68 ||
V_2 -> V_64 == V_69 ||
V_2 -> V_64 == V_70 ;
}
static const struct V_71 *
F_57 ( struct V_12 * V_13 , int V_72 )
{
if ( V_72 == - 1 ) {
struct V_1 * V_2 = F_4 ( V_13 ) ;
V_72 = V_2 -> V_64 ;
}
switch ( V_72 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return & V_73 ;
case V_65 :
case V_66 :
default:
return & V_74 ;
}
}
static void F_58 ( struct V_12 * V_13 )
{
F_59 ( V_13 , L_4 ) ;
F_59 ( V_13 , L_5 ) ;
F_59 ( V_13 , L_6 ) ;
F_59 ( V_13 , L_7 ) ;
F_59 ( V_13 , L_8 ) ;
F_59 ( V_13 , L_9 ) ;
F_59 ( V_13 , L_10 ) ;
F_59 ( V_13 , L_11 ) ;
F_59 ( V_13 , L_12 ) ;
F_59 ( V_13 , L_13 ) ;
F_59 ( V_13 , L_14 ) ;
F_59 ( V_13 , L_15 ) ;
F_59 ( V_13 , L_16 ) ;
}
static int F_60 ( struct V_12 * V_13 ,
struct V_75 * V_16 )
{
int V_76 ;
V_76 = F_52 ( V_13 , V_16 -> V_16 ) ;
if ( V_76 < 0 ) {
F_59 ( V_13 , L_17 , V_16 -> V_16 ) ;
F_58 ( V_13 ) ;
return V_76 ;
}
V_16 -> V_77 = 1 ;
V_16 -> V_21 = V_76 ;
return 0 ;
}
static int F_61 ( struct V_12 * V_13 ,
const struct V_75 * V_16 )
{
int V_76 ;
V_76 = F_53 ( V_13 , V_16 -> V_16 , V_16 -> V_21 ) ;
if ( V_76 < 0 ) {
F_59 ( V_13 , L_17 , V_16 -> V_16 ) ;
F_58 ( V_13 ) ;
return V_76 ;
}
return 0 ;
}
static unsigned int F_62 ( struct V_12 * V_13 )
{
T_1 V_78 = F_15 ( V_13 , 0x6f ) ;
return ( ( V_78 & 0x10 ) >> 4 )
| ( ( V_78 & 0x08 ) >> 2 )
| ( ( V_78 & 0x04 ) << 0 )
| ( ( V_78 & 0x02 ) << 2 ) ;
}
static unsigned int F_63 ( struct V_12 * V_13 )
{
T_1 V_78 = F_15 ( V_13 , 0x6f ) ;
return V_78 & 1 ;
}
static unsigned int F_64 ( struct V_12 * V_13 )
{
T_1 V_78 = F_15 ( V_13 , 0x6f ) ;
return V_78 & 1 ;
}
static int F_65 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
T_3 V_80 = V_3 -> V_81 ( V_13 ) ;
return F_66 ( V_2 -> V_82 , V_80 ) ;
}
static int F_67 ( struct V_12 * V_13 ,
T_1 V_83 ,
const struct V_84 * V_85 ,
const struct V_5 * V_86 )
{
int V_8 ;
for ( V_8 = 0 ; V_85 [ V_8 ] . V_86 . V_10 . V_11 ; V_8 ++ ) {
if ( ! F_3 ( V_86 , & V_85 [ V_8 ] . V_86 ,
F_56 ( V_13 ) ? 250000 : 1000000 , false ) )
continue;
F_16 ( V_13 , 0x00 , V_85 [ V_8 ] . V_87 ) ;
F_16 ( V_13 , 0x01 , ( V_85 [ V_8 ] . V_88 << 4 ) +
V_83 ) ;
return 0 ;
}
return - 1 ;
}
static int F_68 ( struct V_12 * V_13 ,
struct V_5 * V_86 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_20 ;
F_34 ( 1 , V_37 , V_13 , L_18 , V_38 ) ;
if ( F_1 ( V_2 ) ) {
F_16 ( V_13 , 0x16 , 0x43 ) ;
F_16 ( V_13 , 0x17 , 0x5a ) ;
}
F_49 ( V_13 , 0x81 , 0x10 , 0x00 ) ;
F_48 ( V_13 , 0x8f , 0x00 ) ;
F_48 ( V_13 , 0x90 , 0x00 ) ;
F_48 ( V_13 , 0xa2 , 0x00 ) ;
F_48 ( V_13 , 0xa3 , 0x00 ) ;
F_48 ( V_13 , 0xa4 , 0x00 ) ;
F_48 ( V_13 , 0xa5 , 0x00 ) ;
F_48 ( V_13 , 0xa6 , 0x00 ) ;
F_48 ( V_13 , 0xa7 , 0x00 ) ;
F_48 ( V_13 , 0xab , 0x00 ) ;
F_48 ( V_13 , 0xac , 0x00 ) ;
if ( F_55 ( V_13 ) ) {
V_20 = F_67 ( V_13 ,
0x01 , V_89 , V_86 ) ;
if ( V_20 )
V_20 = F_67 ( V_13 ,
0x02 , V_90 , V_86 ) ;
} else if ( F_56 ( V_13 ) ) {
V_20 = F_67 ( V_13 ,
0x05 , V_91 , V_86 ) ;
if ( V_20 )
V_20 = F_67 ( V_13 ,
0x06 , V_92 , V_86 ) ;
} else {
F_34 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_64 ) ;
V_20 = - 1 ;
}
return V_20 ;
}
static void F_69 ( struct V_12 * V_13 ,
const struct V_14 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_4 V_11 = F_6 ( V_10 ) ;
T_4 V_93 = F_8 ( V_10 ) ;
T_3 V_94 = V_10 -> V_95 + V_10 -> V_96 - 4 ;
T_3 V_97 = V_11 - V_10 -> V_98 ;
T_3 V_99 = V_93 - V_10 -> V_100 ;
T_3 V_101 = V_10 -> V_102 + V_10 -> V_103 ;
T_3 V_104 = ( ( ( T_4 ) V_10 -> V_105 / 100 ) > 0 ) ?
( ( V_11 * ( V_106 / 100 ) ) / ( ( T_4 ) V_10 -> V_105 / 100 ) ) : 0 ;
const T_1 V_107 [ 2 ] = {
0xc0 | ( ( V_11 >> 8 ) & 0x1f ) ,
V_11 & 0xff
} ;
F_34 ( 2 , V_37 , V_13 , L_20 , V_38 ) ;
if ( F_55 ( V_13 ) ) {
F_16 ( V_13 , 0x00 , 0x07 ) ;
F_16 ( V_13 , 0x01 , 0x02 ) ;
F_49 ( V_13 , 0x81 , 0x10 , 0x10 ) ;
if ( F_14 ( V_2 -> V_22 [ V_27 ] ,
0x16 , V_107 , 2 ) )
F_70 ( V_13 , L_21 ) ;
F_48 ( V_13 , 0xa2 , ( V_94 >> 4 ) & 0xff ) ;
F_48 ( V_13 , 0xa3 , ( ( V_94 & 0x0f ) << 4 ) |
( ( V_97 >> 8 ) & 0x0f ) ) ;
F_48 ( V_13 , 0xa4 , V_97 & 0xff ) ;
F_48 ( V_13 , 0xa5 , ( V_99 >> 4 ) & 0xff ) ;
F_48 ( V_13 , 0xa6 , ( ( V_99 & 0xf ) << 4 ) |
( ( V_101 >> 8 ) & 0xf ) ) ;
F_48 ( V_13 , 0xa7 , V_101 & 0xff ) ;
} else if ( F_56 ( V_13 ) ) {
F_16 ( V_13 , 0x00 , 0x02 ) ;
F_16 ( V_13 , 0x01 , 0x06 ) ;
} else {
F_34 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_64 ) ;
}
F_48 ( V_13 , 0x8f , ( V_104 >> 8 ) & 0x7 ) ;
F_48 ( V_13 , 0x90 , V_104 & 0xff ) ;
F_48 ( V_13 , 0xab , ( V_93 >> 4 ) & 0xff ) ;
F_48 ( V_13 , 0xac , ( V_93 & 0x0f ) << 4 ) ;
}
static void F_71 ( struct V_12 * V_13 , bool V_108 , T_3 V_109 , T_3 V_110 , T_3 V_111 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_112 [ 4 ] ;
if ( V_108 ) {
V_109 = 0x3ff ;
V_110 = 0x3ff ;
V_111 = 0x3ff ;
}
F_34 ( 2 , V_37 , V_13 , L_22 ,
V_38 , V_108 ? L_23 : L_24 ,
V_109 , V_110 , V_111 ) ;
V_112 [ 0 ] = ( F_46 ( V_13 , 0x77 ) & 0xc0 ) | ( ( V_109 & 0x3f0 ) >> 4 ) ;
V_112 [ 1 ] = ( ( V_109 & 0x00f ) << 4 ) | ( ( V_110 & 0x3c0 ) >> 6 ) ;
V_112 [ 2 ] = ( ( V_110 & 0x03f ) << 2 ) | ( ( V_111 & 0x300 ) >> 8 ) ;
V_112 [ 3 ] = V_111 & 0x0ff ;
if ( F_14 ( V_2 -> V_22 [ V_52 ] ,
0x77 , V_112 , 4 ) )
F_70 ( V_13 , L_25 , V_38 ) ;
}
static void F_72 ( struct V_12 * V_13 , bool V_113 , T_3 V_114 , T_3 V_115 , T_3 V_116 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_117 [ 4 ] ;
T_1 V_118 = 1 ;
T_1 V_119 = 1 ;
if ( V_113 ) {
V_118 = 0 ;
V_119 = 0 ;
V_114 = 0x100 ;
V_115 = 0x100 ;
V_116 = 0x100 ;
}
F_34 ( 2 , V_37 , V_13 , L_26 ,
V_38 , V_113 ? L_23 : L_24 ,
V_114 , V_115 , V_116 ) ;
V_117 [ 0 ] = ( ( V_118 << 7 ) | ( V_119 << 6 ) | ( ( V_114 & 0x3f0 ) >> 4 ) ) ;
V_117 [ 1 ] = ( ( ( V_114 & 0x00f ) << 4 ) | ( ( V_115 & 0x3c0 ) >> 6 ) ) ;
V_117 [ 2 ] = ( ( ( V_115 & 0x03f ) << 2 ) | ( ( V_116 & 0x300 ) >> 8 ) ) ;
V_117 [ 3 ] = ( ( V_116 & 0x0ff ) ) ;
if ( F_14 ( V_2 -> V_22 [ V_52 ] ,
0x73 , V_117 , 4 ) )
F_70 ( V_13 , L_27 , V_38 ) ;
}
static void F_73 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
bool V_120 = F_15 ( V_13 , 0x02 ) & 0x02 ;
bool V_121 = F_41 ( V_13 , 0x05 ) & 0x80 ;
T_1 V_122 = V_123 ;
if ( V_121 && ( F_15 ( V_13 , 0x60 ) & 1 ) )
V_122 = F_24 ( V_13 , 0x01 ) >> 5 ;
F_34 ( 2 , V_37 , V_13 , L_28 ,
V_38 , V_2 -> V_124 ,
V_120 , V_121 ) ;
F_72 ( V_13 , true , 0x0 , 0x0 , 0x0 ) ;
F_71 ( V_13 , true , 0x0 , 0x0 , 0x0 ) ;
F_18 ( V_13 , 0x02 , 0x04 , V_120 ? 0 : 4 ) ;
switch ( V_2 -> V_124 ) {
case V_125 :
if ( V_2 -> V_64 == V_65 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
break;
}
if ( V_2 -> V_64 == V_66 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_121 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_2 -> V_86 . V_10 . V_126 & V_127 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x00 ) ;
} else {
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_56 ( V_13 ) && V_120 ) {
F_71 ( V_13 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_72 ( V_13 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_71 ( V_13 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_128 :
if ( V_2 -> V_64 == V_66 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x20 ) ;
break;
}
if ( V_122 != V_123 )
break;
F_18 ( V_13 , 0x02 , 0xf0 , 0x00 ) ;
break;
case V_129 :
if ( V_2 -> V_64 == V_66 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x60 ) ;
break;
}
if ( V_122 != V_123 )
break;
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_55 ( V_13 ) || V_121 )
break;
if ( V_120 ) {
F_71 ( V_13 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_72 ( V_13 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_71 ( V_13 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_74 ( struct V_130 * V_131 )
{
struct V_12 * V_13 =
& F_5 ( V_131 -> V_132 , struct V_1 , V_7 ) -> V_13 ;
struct V_1 * V_2 = F_4 ( V_13 ) ;
switch ( V_131 -> V_133 ) {
case V_134 :
F_48 ( V_13 , 0x3c , V_131 -> V_21 ) ;
return 0 ;
case V_135 :
F_48 ( V_13 , 0x3a , V_131 -> V_21 ) ;
return 0 ;
case V_136 :
F_48 ( V_13 , 0x3b , V_131 -> V_21 ) ;
return 0 ;
case V_137 :
F_48 ( V_13 , 0x3d , V_131 -> V_21 ) ;
return 0 ;
case V_138 :
V_2 -> V_124 = V_131 -> V_21 ;
F_73 ( V_13 ) ;
return 0 ;
case V_139 :
if ( ! F_1 ( V_2 ) )
return - V_56 ;
F_27 ( V_13 , 0xc8 , V_131 -> V_21 ) ;
return 0 ;
case V_140 :
F_49 ( V_13 , 0xbf , 0x04 , V_131 -> V_21 << 2 ) ;
return 0 ;
case V_141 :
F_48 ( V_13 , 0xc0 , ( V_131 -> V_21 & 0xff0000 ) >> 16 ) ;
F_48 ( V_13 , 0xc1 , ( V_131 -> V_21 & 0x00ff00 ) >> 8 ) ;
F_48 ( V_13 , 0xc2 , ( T_1 ) ( V_131 -> V_21 & 0x0000ff ) ) ;
return 0 ;
}
return - V_56 ;
}
static int F_75 ( struct V_130 * V_131 )
{
struct V_12 * V_13 =
& F_5 ( V_131 -> V_132 , struct V_1 , V_7 ) -> V_13 ;
if ( V_131 -> V_133 == V_142 ) {
V_131 -> V_21 = V_143 ;
if ( ( F_15 ( V_13 , 0x60 ) & 1 ) && ( F_24 ( V_13 , 0x03 ) & 0x80 ) )
V_131 -> V_21 = ( F_24 ( V_13 , 0x05 ) >> 4 ) & 3 ;
return 0 ;
}
return - V_56 ;
}
static inline bool F_76 ( struct V_12 * V_13 )
{
return F_15 ( V_13 , 0x0c ) & 0x24 ;
}
static inline bool F_77 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return ! ( F_15 ( V_13 , 0x6a ) & ( 0x10 >> V_2 -> V_64 ) ) ;
}
static inline bool F_78 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
return ( F_15 ( V_13 , 0x6a ) & V_3 -> V_144 ) != V_3 -> V_144 ;
}
static inline bool F_79 ( struct V_12 * V_13 )
{
return F_41 ( V_13 , 0x05 ) & 0x80 ;
}
static inline bool F_80 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( F_1 ( V_2 ) )
return false ;
return ( ( F_46 ( V_13 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_81 ( struct V_12 * V_13 )
{
return ! ( F_46 ( V_13 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_82 ( struct V_12 * V_13 )
{
bool V_76 ;
V_76 = F_76 ( V_13 ) ;
V_76 |= F_81 ( V_13 ) ;
V_76 |= F_80 ( V_13 ) ;
if ( F_56 ( V_13 ) ) {
V_76 |= F_78 ( V_13 ) ;
V_76 |= F_77 ( V_13 ) ;
}
return V_76 ;
}
static inline bool F_83 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( ! F_1 ( V_2 ) )
return false ;
return F_15 ( V_13 , 0x12 ) & 0x01 ;
}
static inline bool F_84 ( struct V_12 * V_13 )
{
return F_46 ( V_13 , 0xff ) & 0x10 ;
}
static int F_85 ( struct V_12 * V_13 , T_4 * V_145 )
{
* V_145 = 0 ;
* V_145 |= F_76 ( V_13 ) ? V_146 : 0 ;
* V_145 |= F_82 ( V_13 ) ? V_147 : 0 ;
if ( ! F_84 ( V_13 ) && F_83 ( V_13 ) )
* V_145 |= F_56 ( V_13 ) ?
V_148 : V_149 ;
F_34 ( 1 , V_37 , V_13 , L_29 , V_38 , * V_145 ) ;
return 0 ;
}
static int F_86 ( struct V_12 * V_13 ,
struct V_150 * V_151 ,
struct V_5 * V_86 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_4 V_152 = ( V_106 * 8 ) / V_151 -> V_153 ;
T_4 V_154 ;
int V_8 ;
for ( V_8 = 0 ; V_155 [ V_8 ] . V_10 . V_11 ; V_8 ++ ) {
const struct V_14 * V_10 = & V_155 [ V_8 ] . V_10 ;
if ( ! F_87 ( & V_155 [ V_8 ] ,
F_57 ( V_13 , - 1 ) ,
F_2 , NULL ) )
continue;
if ( F_8 ( V_10 ) != V_151 -> V_156 + 1 )
continue;
if ( V_10 -> V_102 != V_151 -> V_157 )
continue;
V_154 = V_152 * F_6 ( V_10 ) ;
if ( ( V_154 < V_10 -> V_105 + 1000000 ) &&
( V_154 > V_10 -> V_105 - 1000000 ) ) {
* V_86 = V_155 [ V_8 ] ;
return 0 ;
}
}
if ( F_88 ( V_151 -> V_156 + 1 , V_152 , V_151 -> V_157 , 0 ,
( V_151 -> V_158 == '+' ? V_159 : 0 ) |
( V_151 -> V_160 == '+' ? V_161 : 0 ) ,
false , V_86 ) )
return 0 ;
if ( F_89 ( V_151 -> V_156 + 1 , V_152 , V_151 -> V_157 ,
( V_151 -> V_158 == '+' ? V_159 : 0 ) |
( V_151 -> V_160 == '+' ? V_161 : 0 ) ,
false , V_2 -> V_162 , V_86 ) )
return 0 ;
F_34 ( 2 , V_37 , V_13 ,
L_30 ,
V_38 , V_151 -> V_157 , V_151 -> V_156 , V_151 -> V_153 ,
V_151 -> V_158 , V_151 -> V_160 ) ;
return - 1 ;
}
static int F_90 ( struct V_12 * V_13 , struct V_150 * V_151 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
T_1 V_163 ;
if ( F_81 ( V_13 ) || F_80 ( V_13 ) ) {
F_34 ( 2 , V_37 , V_13 , L_31 , V_38 ) ;
return - 1 ;
}
V_151 -> V_153 = F_47 ( V_13 , 0xb1 , 0x3fff ) ;
V_151 -> V_156 = F_47 ( V_13 , V_3 -> V_164 , 0x7ff ) ;
V_151 -> V_157 = F_46 ( V_13 , 0xb3 ) >> 3 ;
V_151 -> V_165 = F_15 ( V_13 , 0x12 ) & 0x10 ;
if ( F_1 ( V_2 ) ) {
V_163 = F_46 ( V_13 , 0xb5 ) ;
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
V_163 = F_41 ( V_13 , 0x05 ) ;
V_151 -> V_158 = V_163 & 0x20 ? '+' : '-' ;
V_151 -> V_160 = V_163 & 0x10 ? '+' : '-' ;
}
if ( F_81 ( V_13 ) || F_80 ( V_13 ) ) {
F_34 ( 2 , V_37 , V_13 ,
L_32 , V_38 ) ;
return - 1 ;
}
if ( V_151 -> V_156 < 239 || V_151 -> V_153 < 8 || V_151 -> V_153 == 0x3fff ) {
F_34 ( 2 , V_37 , V_13 , L_33 , V_38 ) ;
memset ( V_151 , 0 , sizeof( struct V_150 ) ) ;
return - 1 ;
}
F_34 ( 2 , V_37 , V_13 ,
L_34 ,
V_38 , V_151 -> V_156 , V_151 -> V_153 , V_151 -> V_157 ,
V_151 -> V_158 , V_151 -> V_160 ,
V_151 -> V_165 ? L_35 : L_36 ) ;
return 0 ;
}
static int F_91 ( struct V_12 * V_13 ,
struct V_166 * V_86 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_86 -> V_72 >= V_2 -> V_167 )
return - V_56 ;
return F_92 ( V_86 ,
F_57 ( V_13 , V_86 -> V_72 ) ,
F_2 , NULL ) ;
}
static int F_93 ( struct V_12 * V_13 ,
struct V_71 * V_168 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
unsigned int V_72 = V_168 -> V_72 ;
if ( V_168 -> V_72 >= V_2 -> V_167 )
return - V_56 ;
* V_168 = * F_57 ( V_13 , V_72 ) ;
V_168 -> V_72 = V_72 ;
return 0 ;
}
static void F_94 ( struct V_12 * V_13 ,
struct V_5 * V_86 )
{
F_95 ( V_86 , F_57 ( V_13 , - 1 ) ,
F_56 ( V_13 ) ? 250000 : 1000000 ,
F_2 , NULL ) ;
}
static unsigned int F_96 ( struct V_12 * V_13 )
{
unsigned int V_169 ;
int V_170 , V_171 ;
V_170 = F_41 ( V_13 , 0x06 ) ;
V_171 = F_41 ( V_13 , 0x3b ) ;
if ( V_170 < 0 || V_171 < 0 )
return 0 ;
V_169 = V_170 * 1000000 + ( ( V_171 & 0x30 ) >> 4 ) * 250000 ;
if ( F_79 ( V_13 ) ) {
unsigned V_172 = ( ( F_41 ( V_13 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_169 = V_169 * 8 / V_172 ;
}
return V_169 ;
}
static unsigned int F_97 ( struct V_12 * V_13 )
{
int V_170 , V_171 ;
V_170 = F_41 ( V_13 , 0x51 ) ;
V_171 = F_41 ( V_13 , 0x52 ) ;
if ( V_170 < 0 || V_171 < 0 )
return 0 ;
return ( ( V_170 << 1 ) | ( V_171 >> 7 ) ) * 1000000 + ( V_171 & 0x7f ) * 1000000 / 128 ;
}
static int F_98 ( struct V_12 * V_13 ,
struct V_5 * V_86 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
struct V_14 * V_10 = & V_86 -> V_10 ;
struct V_150 V_151 ;
if ( ! V_86 )
return - V_56 ;
memset ( V_86 , 0 , sizeof( struct V_5 ) ) ;
if ( F_82 ( V_13 ) ) {
V_2 -> V_173 = true ;
F_34 ( 1 , V_37 , V_13 , L_37 , V_38 ) ;
return - V_174 ;
}
if ( F_90 ( V_13 , & V_151 ) ) {
F_34 ( 1 , V_37 , V_13 , L_38 , V_38 ) ;
return - V_174 ;
}
V_10 -> V_165 = V_151 . V_165 ?
V_175 : V_176 ;
if ( F_56 ( V_13 ) ) {
V_86 -> type = V_177 ;
V_10 -> V_11 = F_42 ( V_13 , 0x07 , V_3 -> V_178 ) ;
V_10 -> V_93 = F_42 ( V_13 , 0x09 , V_3 -> V_179 ) ;
V_10 -> V_105 = V_3 -> V_180 ( V_13 ) ;
V_10 -> V_98 = F_42 ( V_13 , 0x20 , V_3 -> V_181 ) ;
V_10 -> V_95 = F_42 ( V_13 , 0x22 , V_3 -> V_182 ) ;
V_10 -> V_96 = F_42 ( V_13 , 0x24 , V_3 -> V_183 ) ;
V_10 -> V_100 = F_42 ( V_13 , 0x2a ,
V_3 -> V_184 ) / 2 ;
V_10 -> V_102 = F_42 ( V_13 , 0x2e , V_3 -> V_185 ) / 2 ;
V_10 -> V_103 = F_42 ( V_13 , 0x32 ,
V_3 -> V_186 ) / 2 ;
V_10 -> V_187 = ( ( F_41 ( V_13 , 0x05 ) & 0x10 ) ? V_161 : 0 ) |
( ( F_41 ( V_13 , 0x05 ) & 0x20 ) ? V_159 : 0 ) ;
if ( V_10 -> V_165 == V_175 ) {
V_10 -> V_93 += F_42 ( V_13 , 0x0b ,
V_3 -> V_188 ) ;
V_10 -> V_189 = F_42 ( V_13 , 0x2c ,
V_3 -> V_190 ) / 2 ;
V_10 -> V_191 = F_42 ( V_13 , 0x30 ,
V_3 -> V_192 ) / 2 ;
V_10 -> V_193 = F_42 ( V_13 , 0x34 ,
V_3 -> V_194 ) / 2 ;
}
F_94 ( V_13 , V_86 ) ;
} else {
if ( ! F_86 ( V_13 , & V_151 , V_86 ) )
goto V_195;
V_151 . V_157 += 1 ;
F_34 ( 1 , V_37 , V_13 , L_39 , V_38 , V_151 . V_157 ) ;
if ( ! F_86 ( V_13 , & V_151 , V_86 ) )
goto V_195;
V_151 . V_157 -= 2 ;
F_34 ( 1 , V_37 , V_13 , L_40 , V_38 , V_151 . V_157 ) ;
if ( F_86 ( V_13 , & V_151 , V_86 ) ) {
if ( V_2 -> V_173 ) {
F_34 ( 1 , V_37 , V_13 , L_41 , V_38 ) ;
F_49 ( V_13 , 0x86 , 0x06 , 0x00 ) ;
F_49 ( V_13 , 0x86 , 0x06 , 0x04 ) ;
F_49 ( V_13 , 0x86 , 0x06 , 0x02 ) ;
V_2 -> V_173 = false ;
return - V_174 ;
}
F_34 ( 1 , V_37 , V_13 , L_42 , V_38 ) ;
return - V_196 ;
}
V_2 -> V_173 = true ;
}
V_195:
if ( F_82 ( V_13 ) ) {
F_34 ( 1 , V_37 , V_13 , L_43 , V_38 ) ;
memset ( V_86 , 0 , sizeof( struct V_5 ) ) ;
return - V_174 ;
}
if ( ( F_55 ( V_13 ) && V_10 -> V_105 > 170000000 ) ||
( F_56 ( V_13 ) && V_10 -> V_105 > 225000000 ) ) {
F_34 ( 1 , V_37 , V_13 , L_44 ,
V_38 , ( T_4 ) V_10 -> V_105 ) ;
return - V_196 ;
}
if ( V_37 > 1 )
F_99 ( V_13 -> V_197 , L_45 ,
V_86 , true ) ;
return 0 ;
}
static int F_100 ( struct V_12 * V_13 ,
struct V_5 * V_86 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_14 * V_10 ;
int V_20 ;
if ( ! V_86 )
return - V_56 ;
if ( F_3 ( & V_2 -> V_86 , V_86 , 0 , false ) ) {
F_34 ( 1 , V_37 , V_13 , L_46 , V_38 ) ;
return 0 ;
}
V_10 = & V_86 -> V_10 ;
if ( ! F_87 ( V_86 , F_57 ( V_13 , - 1 ) ,
F_2 , NULL ) )
return - V_196 ;
F_94 ( V_13 , V_86 ) ;
V_2 -> V_86 = * V_86 ;
F_49 ( V_13 , 0x91 , 0x40 , V_10 -> V_165 ? 0x40 : 0x00 ) ;
V_20 = F_68 ( V_13 , V_86 ) ;
if ( V_20 ) {
F_69 ( V_13 , V_10 ) ;
}
F_73 ( V_13 ) ;
if ( V_37 > 1 )
F_99 ( V_13 -> V_197 , L_47 ,
V_86 , true ) ;
return 0 ;
}
static int F_101 ( struct V_12 * V_13 ,
struct V_5 * V_86 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
* V_86 = V_2 -> V_86 ;
return 0 ;
}
static void F_102 ( struct V_12 * V_13 , bool V_198 )
{
F_43 ( V_13 , 0x01 , V_198 ? 0x00 : 0x78 ) ;
}
static void F_103 ( struct V_12 * V_13 , bool V_198 )
{
F_43 ( V_13 , 0x83 , V_198 ? 0xfe : 0xff ) ;
}
static void F_104 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( F_55 ( V_13 ) ) {
F_16 ( V_13 , 0x15 , 0xb0 ) ;
} else if ( F_56 ( V_13 ) ) {
F_44 ( V_13 , 0x00 , 0x03 , V_2 -> V_64 ) ;
V_2 -> V_3 -> V_199 ( V_13 , true ) ;
F_16 ( V_13 , 0x15 , 0xa0 ) ;
F_44 ( V_13 , 0x1a , 0x10 , 0x00 ) ;
} else {
F_34 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_64 ) ;
}
}
static void F_105 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_44 ( V_13 , 0x1a , 0x10 , 0x10 ) ;
F_106 ( 16 ) ;
F_16 ( V_13 , 0x15 , 0xbe ) ;
V_2 -> V_3 -> V_199 ( V_13 , false ) ;
}
static void F_107 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
if ( F_55 ( V_13 ) ) {
F_54 ( V_13 , V_3 -> V_200 [ 0 ] ) ;
F_27 ( V_13 , 0x00 , 0x08 ) ;
F_27 ( V_13 , 0x01 , 0x06 ) ;
F_27 ( V_13 , 0xc8 , 0x00 ) ;
} else if ( F_56 ( V_13 ) ) {
F_43 ( V_13 , 0x00 , V_2 -> V_64 & 0x03 ) ;
F_54 ( V_13 , V_3 -> V_200 [ 1 ] ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( V_13 , 0x00 , 0xff ) ;
F_27 ( V_13 , 0x01 , 0xfe ) ;
F_27 ( V_13 , 0xc8 , 0x40 ) ;
}
F_48 ( V_13 , 0x3e , 0x00 ) ;
F_48 ( V_13 , 0xc3 , 0x39 ) ;
F_48 ( V_13 , 0x40 , 0x80 ) ;
} else {
F_34 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_64 ) ;
}
}
static int F_108 ( struct V_12 * V_13 ,
T_4 V_201 , T_4 V_202 , T_4 V_203 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_34 ( 2 , V_37 , V_13 , L_48 ,
V_38 , V_201 , V_2 -> V_64 ) ;
if ( V_201 == V_2 -> V_64 )
return 0 ;
if ( V_201 > V_2 -> V_3 -> V_204 )
return - V_56 ;
V_2 -> V_64 = V_201 ;
F_105 ( V_13 ) ;
F_107 ( V_13 ) ;
F_104 ( V_13 ) ;
F_109 ( V_13 , & V_205 ) ;
return 0 ;
}
static int F_110 ( struct V_12 * V_13 ,
struct V_206 * V_207 ,
struct V_208 * V_61 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_61 -> V_209 >= V_2 -> V_3 -> V_62 )
return - V_56 ;
V_61 -> V_61 = V_2 -> V_3 -> V_63 [ V_61 -> V_209 ] . V_61 ;
return 0 ;
}
static void F_111 ( struct V_1 * V_2 ,
struct V_210 * V_211 )
{
memset ( V_211 , 0 , sizeof( * V_211 ) ) ;
V_211 -> V_11 = V_2 -> V_86 . V_10 . V_11 ;
V_211 -> V_93 = V_2 -> V_86 . V_10 . V_93 ;
V_211 -> V_212 = V_213 ;
V_211 -> V_214 = V_215 ;
if ( V_2 -> V_86 . V_10 . V_126 & V_127 )
V_211 -> V_214 = ( V_2 -> V_86 . V_10 . V_93 <= 576 ) ?
V_216 : V_217 ;
}
static unsigned int F_112 ( struct V_1 * V_2 )
{
#define F_113 ( V_170 , V_171 , T_5 , T_6 , T_7 , T_8 ) { \
ADV76XX_OP_CH_SEL_##a, ADV76XX_OP_CH_SEL_##b, ADV76XX_OP_CH_SEL_##c, \
ADV76XX_OP_CH_SEL_##d, ADV76XX_OP_CH_SEL_##e, ADV76XX_OP_CH_SEL_##f }
#define F_114 ( T_9 ) [ADV7604_BUS_ORDER_##x]
static const unsigned int V_218 [ 6 ] [ 6 ] = {
F_114 ( V_219 ) = F_113 ( V_220 , V_221 , V_222 , V_219 , V_223 , V_224 ) ,
F_114 ( V_221 ) = F_113 ( V_222 , V_219 , V_220 , V_221 , V_224 , V_223 ) ,
F_114 ( V_224 ) = F_113 ( V_221 , V_220 , V_223 , V_224 , V_222 , V_219 ) ,
F_114 ( V_222 ) = F_113 ( V_224 , V_223 , V_219 , V_222 , V_221 , V_220 ) ,
F_114 ( V_223 ) = F_113 ( V_223 , V_224 , V_221 , V_220 , V_219 , V_222 ) ,
F_114 ( V_220 ) = F_113 ( V_219 , V_222 , V_224 , V_223 , V_220 , V_221 ) ,
} ;
return V_218 [ V_2 -> V_225 . V_226 ] [ V_2 -> V_211 -> V_218 >> 5 ] ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_13 ;
F_18 ( V_13 , 0x02 , 0x02 ,
V_2 -> V_211 -> V_227 ? V_228 : 0 ) ;
F_16 ( V_13 , 0x03 , V_2 -> V_211 -> V_229 |
V_2 -> V_225 . V_230 ) ;
F_18 ( V_13 , 0x04 , 0xe0 , F_112 ( V_2 ) ) ;
F_18 ( V_13 , 0x05 , 0x01 ,
V_2 -> V_211 -> V_231 ? V_232 : 0 ) ;
F_73 ( V_13 ) ;
}
static int F_116 ( struct V_12 * V_13 ,
struct V_206 * V_207 ,
struct V_233 * V_211 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_211 -> V_72 != V_2 -> V_167 )
return - V_56 ;
F_111 ( V_2 , & V_211 -> V_211 ) ;
if ( V_211 -> V_234 == V_235 ) {
struct V_210 * V_236 ;
V_236 = F_117 ( V_13 , V_207 , V_211 -> V_72 ) ;
V_211 -> V_211 . V_61 = V_236 -> V_61 ;
} else {
V_211 -> V_211 . V_61 = V_2 -> V_211 -> V_61 ;
}
return 0 ;
}
static int F_118 ( struct V_12 * V_13 ,
struct V_206 * V_207 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_238 -> V_234 != V_239 )
return - V_56 ;
if ( V_238 -> V_240 > V_241 )
return - V_56 ;
V_238 -> V_242 . V_243 = 0 ;
V_238 -> V_242 . V_244 = 0 ;
V_238 -> V_242 . V_11 = V_2 -> V_86 . V_10 . V_11 ;
V_238 -> V_242 . V_93 = V_2 -> V_86 . V_10 . V_93 ;
return 0 ;
}
static int F_119 ( struct V_12 * V_13 ,
struct V_206 * V_207 ,
struct V_233 * V_211 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_60 * V_3 ;
if ( V_211 -> V_72 != V_2 -> V_167 )
return - V_56 ;
V_3 = V_60 ( V_2 , V_211 -> V_211 . V_61 ) ;
if ( V_3 == NULL )
V_3 = V_60 ( V_2 , V_245 ) ;
F_111 ( V_2 , & V_211 -> V_211 ) ;
V_211 -> V_211 . V_61 = V_3 -> V_61 ;
if ( V_211 -> V_234 == V_235 ) {
struct V_210 * V_236 ;
V_236 = F_117 ( V_13 , V_207 , V_211 -> V_72 ) ;
V_236 -> V_61 = V_211 -> V_211 . V_61 ;
} else {
V_2 -> V_211 = V_3 ;
F_115 ( V_2 ) ;
}
return 0 ;
}
static void F_120 ( struct V_12 * V_13 , T_1 V_246 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( ( F_21 ( V_13 , 0x11 ) & 0x01 ) == 0 ) {
F_34 ( 1 , V_37 , V_13 , L_49 , V_38 ) ;
return;
}
if ( V_246 & 0x02 ) {
F_34 ( 1 , V_37 , V_13 , L_50 ,
V_38 ) ;
F_121 ( V_2 -> V_247 , V_248 ,
1 , 0 , 0 , 0 ) ;
}
if ( V_246 & 0x04 ) {
T_1 V_145 ;
T_1 V_249 ;
T_1 V_250 ;
F_34 ( 1 , V_37 , V_13 , L_51 , V_38 ) ;
V_145 = V_251 ;
V_249 = F_21 ( V_13 , 0x14 ) & 0xf ;
if ( V_249 )
V_145 |= V_252 ;
V_250 = F_21 ( V_13 , 0x14 ) >> 4 ;
if ( V_250 )
V_145 |= V_253 ;
F_121 ( V_2 -> V_247 , V_145 ,
0 , V_249 , V_250 , 0 ) ;
return;
}
if ( V_246 & 0x01 ) {
F_34 ( 1 , V_37 , V_13 , L_52 , V_38 ) ;
F_121 ( V_2 -> V_247 , V_254 , 0 , 0 , 0 , 0 ) ;
return;
}
}
static void F_122 ( struct V_12 * V_13 , bool * V_255 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_256 ;
V_256 = F_15 ( V_13 , 0x4d ) & 0x0f ;
if ( ! V_256 )
return;
F_34 ( 1 , V_37 , V_13 , L_53 , V_38 , V_256 ) ;
F_120 ( V_13 , V_256 ) ;
if ( V_256 & 0x08 ) {
struct V_257 V_258 ;
V_258 . V_36 = F_21 ( V_13 , 0x25 ) & 0x1f ;
if ( V_258 . V_36 > 16 )
V_258 . V_36 = 16 ;
if ( V_258 . V_36 ) {
T_1 V_8 ;
for ( V_8 = 0 ; V_8 < V_258 . V_36 ; V_8 ++ )
V_258 . V_258 [ V_8 ] = F_21 ( V_13 , V_8 + 0x15 ) ;
F_22 ( V_13 , 0x26 , 0x01 ) ;
F_123 ( V_2 -> V_247 , & V_258 ) ;
}
}
V_256 = ( ( V_256 & 0x08 ) >> 3 ) | ( ( V_256 & 0x04 ) >> 1 ) |
( ( V_256 & 0x02 ) << 1 ) | ( ( V_256 & 0x01 ) << 3 ) ;
F_16 ( V_13 , 0x4e , V_256 ) ;
if ( V_255 )
* V_255 = true ;
}
static int F_124 ( struct V_259 * V_260 , bool V_198 )
{
struct V_1 * V_2 = V_260 -> V_261 ;
struct V_12 * V_13 = & V_2 -> V_13 ;
if ( ! V_2 -> V_262 && V_198 ) {
F_23 ( V_13 , 0x2a , 0x01 , 0x01 ) ;
F_22 ( V_13 , 0x2c , 0x01 ) ;
F_23 ( V_13 , 0x11 , 0x01 , 0 ) ;
F_18 ( V_13 , 0x50 , 0x0f , 0x0f ) ;
F_22 ( V_13 , 0x26 , 0x01 ) ;
} else if ( V_2 -> V_262 && ! V_198 ) {
F_18 ( V_13 , 0x50 , 0x0f , 0x00 ) ;
F_23 ( V_13 , 0x27 , 0x70 , 0x00 ) ;
F_23 ( V_13 , 0x2a , 0x01 , 0x00 ) ;
V_2 -> V_263 = 0 ;
}
V_2 -> V_262 = V_198 ;
F_65 ( V_13 ) ;
return 0 ;
}
static int F_125 ( struct V_259 * V_260 , T_1 V_23 )
{
struct V_1 * V_2 = V_260 -> V_261 ;
struct V_12 * V_13 = & V_2 -> V_13 ;
unsigned int V_8 , V_264 = V_265 ;
if ( ! V_2 -> V_262 )
return V_23 == V_266 ? 0 : - V_267 ;
if ( V_23 == V_266 ) {
F_23 ( V_13 , 0x27 , 0x70 , 0 ) ;
V_2 -> V_263 = 0 ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < V_265 ; V_8 ++ ) {
bool V_268 = V_2 -> V_263 & ( 1 << V_8 ) ;
if ( V_264 == V_265 && ! V_268 )
V_264 = V_8 ;
if ( V_268 && V_2 -> V_269 [ V_8 ] == V_23 )
return 0 ;
}
if ( V_8 == V_265 ) {
V_8 = V_264 ;
if ( V_8 == V_265 )
return - V_270 ;
}
V_2 -> V_269 [ V_8 ] = V_23 ;
V_2 -> V_263 |= 1 << V_8 ;
switch ( V_8 ) {
case 0 :
F_23 ( V_13 , 0x27 , 0x10 , 0x10 ) ;
F_23 ( V_13 , 0x28 , 0x0f , V_23 ) ;
break;
case 1 :
F_23 ( V_13 , 0x27 , 0x20 , 0x20 ) ;
F_23 ( V_13 , 0x28 , 0xf0 , V_23 << 4 ) ;
break;
case 2 :
F_23 ( V_13 , 0x27 , 0x40 , 0x40 ) ;
F_23 ( V_13 , 0x29 , 0x0f , V_23 ) ;
break;
}
return 0 ;
}
static int F_126 ( struct V_259 * V_260 , T_1 V_271 ,
T_4 V_272 , struct V_257 * V_258 )
{
struct V_1 * V_2 = V_260 -> V_261 ;
struct V_12 * V_13 = & V_2 -> V_13 ;
T_1 V_36 = V_258 -> V_36 ;
unsigned int V_8 ;
F_23 ( V_13 , 0x12 , 0x70 , F_127 ( 1 , V_271 - 1 ) << 4 ) ;
if ( V_36 > 16 ) {
F_70 ( V_13 , L_54 , V_38 , V_36 ) ;
return - V_56 ;
}
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
F_22 ( V_13 , V_8 , V_258 -> V_258 [ V_8 ] ) ;
F_22 ( V_13 , 0x10 , V_36 ) ;
F_22 ( V_13 , 0x11 , 0x01 ) ;
return 0 ;
}
static int F_128 ( struct V_12 * V_13 , T_4 V_145 , bool * V_255 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
const T_1 V_273 = F_15 ( V_13 , 0x43 ) ;
const T_1 V_274 = F_15 ( V_13 , 0x6b ) ;
const T_1 V_275 = F_15 ( V_13 , 0x70 ) ;
T_1 V_276 ;
T_1 V_277 ;
T_1 V_278 ;
if ( V_273 )
F_16 ( V_13 , 0x44 , V_273 ) ;
if ( V_275 )
F_16 ( V_13 , 0x71 , V_275 ) ;
if ( V_274 )
F_16 ( V_13 , 0x6c , V_274 ) ;
F_34 ( 2 , V_37 , V_13 , L_55 , V_38 ) ;
V_277 = V_273 & 0x98 ;
V_276 = F_56 ( V_13 )
? V_274 & V_3 -> V_279
: 0 ;
if ( V_277 || V_276 ) {
F_34 ( 1 , V_37 , V_13 ,
L_56 ,
V_38 , V_277 , V_276 ) ;
F_109 ( V_13 , & V_205 ) ;
if ( V_255 )
* V_255 = true ;
}
if ( V_274 & 0x01 ) {
F_34 ( 1 , V_37 , V_13 , L_57 , V_38 ,
( F_15 ( V_13 , 0x6a ) & 0x01 ) ? L_58 : L_59 ) ;
F_73 ( V_13 ) ;
if ( V_255 )
* V_255 = true ;
}
#if F_129 ( V_280 )
F_122 ( V_13 , V_255 ) ;
#endif
V_278 = V_275 & V_3 -> V_281 ;
if ( V_278 ) {
F_34 ( 1 , V_37 , V_13 , L_60 , V_38 , V_278 ) ;
F_65 ( V_13 ) ;
if ( V_255 )
* V_255 = true ;
}
return 0 ;
}
static int F_130 ( struct V_12 * V_13 , struct V_282 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 * V_283 = NULL ;
memset ( V_48 -> V_284 , 0 , sizeof( V_48 -> V_284 ) ) ;
switch ( V_48 -> V_72 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
if ( V_2 -> V_48 . V_49 & ( 1 << V_48 -> V_72 ) )
V_283 = V_2 -> V_48 . V_48 ;
break;
default:
return - V_56 ;
}
if ( V_48 -> V_285 == 0 && V_48 -> V_286 == 0 ) {
V_48 -> V_286 = V_283 ? V_2 -> V_48 . V_286 : 0 ;
return 0 ;
}
if ( V_283 == NULL )
return - V_287 ;
if ( V_48 -> V_285 >= V_2 -> V_48 . V_286 )
return - V_56 ;
if ( V_48 -> V_285 + V_48 -> V_286 > V_2 -> V_48 . V_286 )
V_48 -> V_286 = V_2 -> V_48 . V_286 - V_48 -> V_285 ;
memcpy ( V_48 -> V_48 , V_283 + V_48 -> V_285 * 128 , V_48 -> V_286 * 128 ) ;
return 0 ;
}
static int F_131 ( struct V_12 * V_13 , struct V_282 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
unsigned int V_288 ;
T_3 V_289 ;
int V_20 ;
int V_8 ;
memset ( V_48 -> V_284 , 0 , sizeof( V_48 -> V_284 ) ) ;
if ( V_48 -> V_72 > V_70 )
return - V_56 ;
if ( V_48 -> V_285 != 0 )
return - V_56 ;
if ( V_48 -> V_286 == 0 ) {
V_2 -> V_48 . V_49 &= ~ ( 1 << V_48 -> V_72 ) ;
F_35 ( V_2 , V_2 -> V_48 . V_49 ) ;
F_30 ( V_13 , V_3 -> V_290 , 0x0f , V_2 -> V_48 . V_49 ) ;
V_2 -> V_162 . V_291 = 16 ;
V_2 -> V_162 . V_292 = 9 ;
if ( ! V_2 -> V_48 . V_49 )
V_2 -> V_48 . V_286 = 0 ;
F_34 ( 2 , V_37 , V_13 , L_61 ,
V_38 , V_48 -> V_72 , V_2 -> V_48 . V_49 ) ;
return 0 ;
}
if ( V_48 -> V_286 > 2 ) {
V_48 -> V_286 = 2 ;
return - V_293 ;
}
V_289 = F_132 ( V_48 -> V_48 , V_48 -> V_286 * 128 , & V_288 ) ;
V_20 = F_133 ( V_289 , & V_289 , NULL ) ;
if ( V_20 )
return V_20 ;
F_34 ( 2 , V_37 , V_13 , L_62 ,
V_38 , V_48 -> V_72 , V_2 -> V_48 . V_49 ) ;
F_134 ( & V_2 -> V_47 ) ;
F_35 ( V_2 , 0 ) ;
F_30 ( V_13 , V_3 -> V_290 , 0x0f , 0x00 ) ;
if ( V_288 == 0 )
return - V_56 ;
switch ( V_48 -> V_72 ) {
case V_67 :
V_2 -> V_294 [ 0 ] = V_48 -> V_48 [ V_288 ] ;
V_2 -> V_294 [ 1 ] = V_48 -> V_48 [ V_288 + 1 ] ;
break;
case V_68 :
F_29 ( V_13 , 0x70 , V_48 -> V_48 [ V_288 ] ) ;
F_29 ( V_13 , 0x71 , V_48 -> V_48 [ V_288 + 1 ] ) ;
break;
case V_69 :
F_29 ( V_13 , 0x72 , V_48 -> V_48 [ V_288 ] ) ;
F_29 ( V_13 , 0x73 , V_48 -> V_48 [ V_288 + 1 ] ) ;
break;
case V_70 :
F_29 ( V_13 , 0x74 , V_48 -> V_48 [ V_288 ] ) ;
F_29 ( V_13 , 0x75 , V_48 -> V_48 [ V_288 + 1 ] ) ;
break;
default:
return - V_56 ;
}
if ( V_3 -> type == V_295 ) {
F_29 ( V_13 , 0x76 , V_288 & 0xff ) ;
F_30 ( V_13 , 0x77 , 0x40 , ( V_288 & 0x100 ) >> 2 ) ;
} else {
F_29 ( V_13 , 0x70 , V_288 & 0xff ) ;
F_30 ( V_13 , 0x71 , 0x01 , ( V_288 & 0x100 ) >> 8 ) ;
}
V_48 -> V_48 [ V_288 ] = V_2 -> V_294 [ 0 ] ;
V_48 -> V_48 [ V_288 + 1 ] = V_2 -> V_294 [ 1 ] ;
memcpy ( V_2 -> V_48 . V_48 , V_48 -> V_48 , 128 * V_48 -> V_286 ) ;
V_2 -> V_48 . V_286 = V_48 -> V_286 ;
V_2 -> V_162 = F_135 ( V_48 -> V_48 [ 0x15 ] ,
V_48 -> V_48 [ 0x16 ] ) ;
V_2 -> V_48 . V_49 |= 1 << V_48 -> V_72 ;
V_20 = F_33 ( V_13 , 128 * V_48 -> V_286 , V_2 -> V_48 . V_48 ) ;
if ( V_20 < 0 ) {
F_70 ( V_13 , L_63 , V_20 , V_48 -> V_72 ) ;
return V_20 ;
}
F_30 ( V_13 , V_3 -> V_290 , 0x0f , V_2 -> V_48 . V_49 ) ;
for ( V_8 = 0 ; V_8 < 1000 ; V_8 ++ ) {
if ( F_28 ( V_13 , V_3 -> V_296 ) & V_2 -> V_48 . V_49 )
break;
F_136 ( 1 ) ;
}
if ( V_8 == 1000 ) {
F_70 ( V_13 , L_64 , V_2 -> V_48 . V_49 ) ;
return - V_267 ;
}
F_137 ( V_2 -> V_247 , V_289 , false ) ;
F_138 ( & V_2 -> V_47 , V_297 / 10 ) ;
return 0 ;
}
static int F_139 ( struct V_12 * V_13 , int V_209 ,
union V_298 * V_299 )
{
T_10 V_300 [ 32 ] ;
T_1 V_36 ;
int V_8 ;
if ( ! ( F_15 ( V_13 , 0x60 ) & V_301 [ V_209 ] . V_302 ) ) {
F_59 ( V_13 , L_65 ,
V_301 [ V_209 ] . V_303 ) ;
return - V_304 ;
}
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
V_300 [ V_8 ] = F_24 ( V_13 ,
V_301 [ V_209 ] . V_305 + V_8 ) ;
V_36 = V_300 [ 2 ] + 1 ;
if ( V_36 + 3 > sizeof( V_300 ) ) {
F_70 ( V_13 , L_66 , V_38 ,
V_301 [ V_209 ] . V_303 , V_36 ) ;
return - V_304 ;
}
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
V_300 [ V_8 + 3 ] = F_24 ( V_13 ,
V_301 [ V_209 ] . V_306 + V_8 ) ;
if ( F_140 ( V_299 , V_300 ) < 0 ) {
F_70 ( V_13 , L_67 , V_38 ,
V_301 [ V_209 ] . V_303 ) ;
return - V_304 ;
}
return 0 ;
}
static void F_141 ( struct V_12 * V_13 )
{
int V_8 ;
if ( ! F_79 ( V_13 ) ) {
F_59 ( V_13 , L_68 ) ;
return;
}
for ( V_8 = 0 ; V_8 < F_142 ( V_301 ) ; V_8 ++ ) {
union V_298 V_299 ;
struct V_17 * V_18 = F_143 ( V_13 ) ;
if ( F_139 ( V_13 , V_8 , & V_299 ) )
return;
F_144 ( V_307 , & V_18 -> V_308 , & V_299 ) ;
}
}
static int F_145 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
struct V_5 V_86 ;
struct V_150 V_151 ;
T_1 V_309 = F_15 ( V_13 , 0x02 ) ;
T_1 V_310 ;
T_1 V_80 ;
static const char * const V_311 [ 16 ] = {
L_69 , L_70 , L_71 , L_72 ,
L_71 , L_73 , L_71 , L_74 ,
L_71 , L_75 , L_76 ,
L_71 , L_71 , L_71 , L_71 , L_77
} ;
static const char * const V_312 [ 16 ] = {
L_78 , L_79 ,
L_80 , L_81 ,
L_82 , L_83 ,
L_84 , L_85 ,
L_86 , L_86 , L_86 , L_86 , L_86 ,
L_86 , L_86 , L_87
} ;
static const char * const V_313 [ 16 ] = {
L_78 , L_79 ,
L_80 , L_81 ,
L_82 , L_83 ,
L_84 , L_85 ,
L_88 , L_89 , L_90 , L_86 , L_86 ,
L_86 , L_86 , L_86
} ;
static const char * const V_314 [] = {
L_91 ,
L_78 ,
L_79 ,
} ;
static const char * const V_315 [ 4 ] = {
L_92 ,
L_93 ,
L_94 ,
L_95
} ;
F_59 ( V_13 , L_96 ) ;
F_59 ( V_13 , L_97 , F_76 ( V_13 ) ? L_98 : L_99 ) ;
V_310 = F_28 ( V_13 , V_3 -> V_296 ) ;
F_59 ( V_13 , L_100 ,
( ( V_310 & 0x01 ) ? L_101 : L_102 ) ,
( ( V_310 & 0x02 ) ? L_101 : L_102 ) ,
( ( V_310 & 0x04 ) ? L_101 : L_102 ) ,
( ( V_310 & 0x08 ) ? L_101 : L_102 ) ) ;
F_59 ( V_13 , L_103 , V_2 -> V_262 ?
L_104 : L_105 ) ;
if ( V_2 -> V_262 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_265 ; V_8 ++ ) {
bool V_268 = V_2 -> V_263 & ( 1 << V_8 ) ;
if ( V_268 )
F_59 ( V_13 , L_106 ,
V_2 -> V_269 [ V_8 ] ) ;
}
}
F_59 ( V_13 , L_107 ) ;
V_80 = V_3 -> V_81 ( V_13 ) ;
F_59 ( V_13 , L_108 ,
( ( V_80 & 0x01 ) ? L_101 : L_102 ) ,
( ( V_80 & 0x02 ) ? L_101 : L_102 ) ,
( ( V_80 & 0x04 ) ? L_101 : L_102 ) ,
( ( V_80 & 0x08 ) ? L_101 : L_102 ) ) ;
F_59 ( V_13 , L_109 ,
F_77 ( V_13 ) ? L_110 : L_111 ) ;
F_59 ( V_13 , L_112 ,
F_78 ( V_13 ) ? L_110 : L_111 ) ;
F_59 ( V_13 , L_113 , F_80 ( V_13 ) ? L_110 : L_111 ) ;
F_59 ( V_13 , L_114 , F_81 ( V_13 ) ? L_110 : L_111 ) ;
F_59 ( V_13 , L_115 , F_83 ( V_13 ) ? L_110 : L_111 ) ;
F_59 ( V_13 , L_116 ,
( F_84 ( V_13 ) ) ? L_99 : L_98 ) ;
F_59 ( V_13 , L_117 ,
F_15 ( V_13 , 0x01 ) & 0x0f , F_15 ( V_13 , 0x00 ) & 0x3f ,
( F_15 ( V_13 , 0x01 ) & 0x70 ) >> 4 ) ;
F_59 ( V_13 , L_118 ) ;
if ( F_90 ( V_13 , & V_151 ) )
F_59 ( V_13 , L_119 ) ;
else
F_59 ( V_13 , L_120 ,
V_151 . V_156 , V_151 . V_153 , V_151 . V_157 ,
V_151 . V_165 ? L_35 : L_36 ,
V_151 . V_158 , V_151 . V_160 ) ;
if ( F_98 ( V_13 , & V_86 ) )
F_59 ( V_13 , L_121 ) ;
else
F_99 ( V_13 -> V_197 , L_122 ,
& V_86 , true ) ;
F_99 ( V_13 -> V_197 , L_123 ,
& V_2 -> V_86 , true ) ;
if ( F_82 ( V_13 ) )
return 0 ;
F_59 ( V_13 , L_124 ) ;
F_59 ( V_13 , L_125 ,
V_314 [ V_2 -> V_124 ] ) ;
F_59 ( V_13 , L_126 ,
V_312 [ V_309 >> 4 ] ) ;
F_59 ( V_13 , L_127 ,
( V_309 & 0x02 ) ? L_128 : L_129 ,
( ( ( V_309 >> 2 ) & 0x01 ) ^ ( V_309 & 0x01 ) ) ?
L_130 : L_131 ,
( V_309 & 0x08 ) ? L_104 : L_105 ) ;
F_59 ( V_13 , L_132 ,
V_311 [ F_46 ( V_13 , V_3 -> V_316 ) >> 4 ] ) ;
if ( ! F_56 ( V_13 ) )
return 0 ;
F_59 ( V_13 , L_133 , F_79 ( V_13 ) ? L_58 : L_134 ) ;
F_59 ( V_13 , L_135 ,
( F_41 ( V_13 , 0x00 ) & 0x03 ) + 'A' ) ;
F_59 ( V_13 , L_136 ,
( F_41 ( V_13 , 0x05 ) & 0x40 ) ? L_111 : L_110 ) ;
F_59 ( V_13 , L_137 ,
( F_41 ( V_13 , 0x04 ) & 0x20 ) ? L_138 : L_139 ,
( F_41 ( V_13 , 0x04 ) & 0x10 ) ? L_140 : L_141 ) ;
if ( F_79 ( V_13 ) ) {
bool V_317 = F_41 ( V_13 , 0x04 ) & 0x01 ;
bool V_318 = F_41 ( V_13 , 0x18 ) & 0x01 ;
bool V_319 = F_15 ( V_13 , 0x65 ) & 0x40 ;
F_59 ( V_13 , L_142 ,
V_317 ? L_143 : L_144 ,
V_318 ? L_145 : L_146 ,
V_319 ? L_147 : L_104 ) ;
if ( V_317 && V_318 ) {
F_59 ( V_13 , L_148 ,
( F_41 ( V_13 , 0x07 ) & 0x20 ) ? L_149 : L_150 ) ;
}
F_59 ( V_13 , L_151 , ( F_41 ( V_13 , 0x5b ) << 12 ) +
( F_41 ( V_13 , 0x5c ) << 8 ) +
( F_41 ( V_13 , 0x5d ) & 0xf0 ) ) ;
F_59 ( V_13 , L_152 , ( ( F_41 ( V_13 , 0x5d ) & 0x0f ) << 16 ) +
( F_41 ( V_13 , 0x5e ) << 8 ) +
F_41 ( V_13 , 0x5f ) ) ;
F_59 ( V_13 , L_153 , ( F_41 ( V_13 , 0x04 ) & 0x40 ) ? L_99 : L_98 ) ;
F_59 ( V_13 , L_154 , V_315 [ ( F_41 ( V_13 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_59 ( V_13 , L_155 , V_313 [ F_41 ( V_13 , 0x53 ) & 0xf ] ) ;
F_141 ( V_13 ) ;
}
return 0 ;
}
static int F_146 ( struct V_12 * V_13 ,
struct V_320 * V_321 ,
struct V_322 * V_323 )
{
switch ( V_323 -> type ) {
case V_324 :
return F_147 ( V_13 , V_321 , V_323 ) ;
case V_325 :
return F_148 ( V_13 , V_321 , V_323 ) ;
default:
return - V_56 ;
}
}
static int F_149 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_20 ;
V_20 = F_150 ( V_2 -> V_247 ) ;
if ( V_20 )
F_151 ( V_2 -> V_247 ) ;
return V_20 ;
}
static void F_152 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_153 ( V_2 -> V_247 ) ;
}
static int F_154 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_79 * V_3 = V_2 -> V_3 ;
struct V_326 * V_225 = & V_2 -> V_225 ;
F_43 ( V_13 , 0x48 ,
( V_225 -> V_327 ? 0x80 : 0 ) |
( V_225 -> V_328 ? 0x40 : 0 ) ) ;
F_105 ( V_13 ) ;
if ( V_225 -> V_329 >= 0 &&
V_225 -> V_329 < V_2 -> V_167 ) {
V_2 -> V_64 = V_225 -> V_329 ;
F_107 ( V_13 ) ;
F_104 ( V_13 ) ;
}
F_16 ( V_13 , 0x0c , 0x42 ) ;
F_16 ( V_13 , 0x0b , 0x44 ) ;
F_48 ( V_13 , 0xcf , 0x01 ) ;
F_18 ( V_13 , 0x02 , 0x0f , V_225 -> V_330 << 3 ) ;
F_18 ( V_13 , 0x05 , 0x0e , V_225 -> V_331 << 3 |
V_225 -> V_332 << 2 |
V_225 -> V_333 << 1 ) ;
F_115 ( V_2 ) ;
F_48 ( V_13 , 0x69 , 0x30 ) ;
F_16 ( V_13 , 0x06 , 0xa0 | V_225 -> V_334 << 2 |
V_225 -> V_335 << 1 | V_225 -> V_336 ) ;
F_16 ( V_13 , 0x14 , 0x40 | V_225 -> V_337 << 4 |
V_225 -> V_338 << 2 |
V_225 -> V_339 ) ;
F_48 ( V_13 , 0xba , ( V_225 -> V_340 << 1 ) | 0x01 ) ;
F_48 ( V_13 , 0xf3 , 0xdc ) ;
F_48 ( V_13 , 0xf9 , 0x23 ) ;
F_48 ( V_13 , 0x45 , 0x23 ) ;
F_48 ( V_13 , 0xc9 , 0x2d ) ;
F_44 ( V_13 , 0x15 , 0x03 , 0x03 ) ;
F_44 ( V_13 , 0x1a , 0x0e , 0x08 ) ;
F_44 ( V_13 , 0x68 , 0x06 , 0x06 ) ;
F_27 ( V_13 , 0xb5 , 0x01 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( V_13 , 0x02 , V_225 -> V_341 ) ;
F_18 ( V_13 , 0x30 , 1 << 4 , V_225 -> V_342 << 4 ) ;
}
F_16 ( V_13 , 0x40 , 0xc0 | V_225 -> V_343 ) ;
F_16 ( V_13 , 0x46 , 0x98 ) ;
F_16 ( V_13 , 0x6e , V_3 -> V_279 ) ;
F_16 ( V_13 , 0x73 , V_3 -> V_281 ) ;
V_3 -> V_344 ( V_13 ) ;
return F_155 ( V_13 -> V_345 ) ;
}
static void F_156 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd7 ) ;
}
static void F_157 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd0 ) ;
}
static void F_158 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd0 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 1 ; V_8 < F_142 ( V_2 -> V_19 ) ; ++ V_8 ) {
if ( V_2 -> V_19 [ V_8 ] )
F_160 ( V_2 -> V_19 [ V_8 ] ) ;
}
}
static struct V_17 * F_161 ( struct V_12 * V_13 ,
T_1 V_23 , T_1 V_346 )
{
struct V_17 * V_18 = F_143 ( V_13 ) ;
if ( V_23 )
F_16 ( V_13 , V_346 , V_23 << 1 ) ;
return F_162 ( V_18 -> V_347 , F_15 ( V_13 , V_346 ) >> 1 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_348 V_349 ;
struct V_350 * V_351 ;
struct V_350 * V_352 ;
unsigned int V_126 ;
int V_76 ;
T_4 V_353 ;
V_352 = V_2 -> V_19 [ V_27 ] -> V_308 . V_354 ;
V_351 = F_164 ( V_352 , NULL ) ;
if ( ! V_351 )
return - V_56 ;
V_76 = F_165 ( V_351 , & V_349 ) ;
if ( V_76 ) {
F_166 ( V_351 ) ;
return V_76 ;
}
if ( ! F_167 ( V_351 , L_156 , & V_353 ) )
V_2 -> V_225 . V_329 = V_353 ;
else
V_2 -> V_225 . V_329 = - 1 ;
F_166 ( V_351 ) ;
V_126 = V_349 . V_355 . V_356 . V_126 ;
if ( V_126 & V_357 )
V_2 -> V_225 . V_335 = 1 ;
if ( V_126 & V_358 )
V_2 -> V_225 . V_334 = 1 ;
if ( V_126 & V_359 )
V_2 -> V_225 . V_336 = 1 ;
if ( V_349 . V_360 == V_361 )
V_2 -> V_225 . V_332 = 1 ;
V_2 -> V_225 . V_343 = V_362 ;
V_2 -> V_225 . V_363 [ V_29 ] = 0x42 ;
V_2 -> V_225 . V_363 [ V_30 ] = 0x40 ;
V_2 -> V_225 . V_363 [ V_31 ] = 0x3e ;
V_2 -> V_225 . V_363 [ V_364 ] = 0x38 ;
V_2 -> V_225 . V_363 [ V_365 ] = 0x3c ;
V_2 -> V_225 . V_363 [ V_32 ] = 0x26 ;
V_2 -> V_225 . V_363 [ V_33 ] = 0x32 ;
V_2 -> V_225 . V_363 [ V_34 ] = 0x36 ;
V_2 -> V_225 . V_363 [ V_50 ] = 0x34 ;
V_2 -> V_225 . V_363 [ V_51 ] = 0x30 ;
V_2 -> V_225 . V_363 [ V_52 ] = 0x22 ;
V_2 -> V_225 . V_363 [ V_53 ] = 0x24 ;
V_2 -> V_225 . V_327 = 0 ;
V_2 -> V_225 . V_328 = 0 ;
V_2 -> V_225 . V_331 = 1 ;
V_2 -> V_225 . V_230 = V_366 ;
V_2 -> V_225 . V_226 = V_367 ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 , int V_368 )
{
int V_20 ;
if ( ! V_2 -> V_19 [ V_368 ] )
return - V_369 ;
V_2 -> V_22 [ V_368 ] =
F_169 ( V_2 -> V_19 [ V_368 ] ,
& V_370 [ V_368 ] ) ;
if ( F_170 ( V_2 -> V_22 [ V_368 ] ) ) {
V_20 = F_171 ( V_2 -> V_22 [ V_368 ] ) ;
F_12 ( V_2 -> V_19 [ V_368 ] ,
L_157 ,
V_368 , V_20 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_172 ( struct V_1 * V_2 )
{
int V_8 , V_20 ;
for ( V_8 = V_29 ; V_8 < V_371 ; V_8 ++ ) {
V_20 = F_168 ( V_2 , V_8 ) ;
if ( V_20 && ( V_20 != - V_369 ) )
return V_20 ;
}
return 0 ;
}
static void F_173 ( struct V_1 * V_2 )
{
if ( V_2 -> V_372 ) {
F_36 ( V_2 -> V_372 , 0 ) ;
F_174 ( 5000 , 10000 ) ;
F_36 ( V_2 -> V_372 , 1 ) ;
F_174 ( 5000 , 10000 ) ;
}
}
static int F_175 ( struct V_17 * V_18 ,
const struct V_373 * V_133 )
{
static const struct V_5 V_374 =
V_375 ;
struct V_1 * V_2 ;
struct V_376 * V_7 ;
struct V_130 * V_131 ;
struct V_12 * V_13 ;
unsigned int V_8 ;
unsigned int V_21 , V_377 ;
int V_20 ;
if ( ! F_176 ( V_18 -> V_347 , V_378 ) )
return - V_267 ;
F_177 ( 1 , V_37 , V_18 , L_158 ,
V_18 -> V_23 << 1 ) ;
V_2 = F_178 ( & V_18 -> V_308 , sizeof( * V_2 ) , V_379 ) ;
if ( ! V_2 ) {
F_12 ( V_18 , L_159 ) ;
return - V_380 ;
}
V_2 -> V_19 [ V_27 ] = V_18 ;
V_2 -> V_173 = true ;
V_2 -> V_64 = ~ 0 ;
if ( F_129 ( V_381 ) && V_18 -> V_308 . V_354 ) {
const struct V_382 * V_383 ;
V_383 = F_179 ( V_384 , V_18 -> V_308 . V_354 ) ;
V_2 -> V_3 = V_383 -> V_283 ;
V_20 = F_163 ( V_2 ) ;
if ( V_20 < 0 ) {
F_12 ( V_18 , L_160 ) ;
return V_20 ;
}
} else if ( V_18 -> V_308 . V_385 ) {
struct V_326 * V_225 = V_18 -> V_308 . V_385 ;
V_2 -> V_3 = ( const struct V_79 * ) V_133 -> V_386 ;
V_2 -> V_225 = * V_225 ;
} else {
F_12 ( V_18 , L_161 ) ;
return - V_369 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_40 ; ++ V_8 ) {
V_2 -> V_41 [ V_8 ] =
F_180 ( & V_18 -> V_308 , L_162 , V_8 ,
V_387 ) ;
if ( F_170 ( V_2 -> V_41 [ V_8 ] ) )
return F_171 ( V_2 -> V_41 [ V_8 ] ) ;
if ( V_2 -> V_41 [ V_8 ] )
F_181 ( V_18 , L_163 , V_8 ) ;
}
V_2 -> V_372 = F_182 ( & V_18 -> V_308 , L_164 ,
V_388 ) ;
if ( F_170 ( V_2 -> V_372 ) )
return F_171 ( V_2 -> V_372 ) ;
F_173 ( V_2 ) ;
V_2 -> V_86 = V_374 ;
V_2 -> V_211 = V_60 ( V_2 , V_245 ) ;
V_13 = & V_2 -> V_13 ;
F_183 ( V_13 , V_18 , & V_389 ) ;
snprintf ( V_13 -> V_197 , sizeof( V_13 -> V_197 ) , L_165 ,
V_133 -> V_197 , F_184 ( V_18 -> V_347 ) ,
V_18 -> V_23 ) ;
V_13 -> V_126 |= V_390 | V_391 ;
V_13 -> V_392 = & V_393 ;
V_20 = F_168 ( V_2 , V_27 ) ;
if ( V_20 ) {
F_70 ( V_13 , L_166 ) ;
return - V_369 ;
}
switch ( V_2 -> V_3 -> type ) {
case V_295 :
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] , 0xfb , & V_21 ) ;
if ( V_20 ) {
F_70 ( V_13 , L_167 , V_20 ) ;
return - V_369 ;
}
if ( V_21 != 0x68 ) {
F_70 ( V_13 , L_168 ,
V_18 -> V_23 << 1 ) ;
return - V_369 ;
}
break;
case V_394 :
case V_395 :
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] ,
0xea ,
& V_21 ) ;
if ( V_20 ) {
F_70 ( V_13 , L_167 , V_20 ) ;
return - V_369 ;
}
V_377 = V_21 << 8 ;
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] ,
0xeb ,
& V_21 ) ;
if ( V_20 ) {
F_70 ( V_13 , L_167 , V_20 ) ;
return - V_369 ;
}
V_21 |= V_377 ;
if ( ( V_2 -> V_3 -> type == V_394 && V_21 != 0x2051 ) ||
( V_2 -> V_3 -> type == V_395 && V_21 != 0x2041 ) ) {
F_70 ( V_13 , L_169 ,
V_18 -> V_23 << 1 ) ;
return - V_369 ;
}
break;
}
V_7 = & V_2 -> V_7 ;
F_185 ( V_7 , F_1 ( V_2 ) ? 9 : 8 ) ;
F_186 ( V_7 , & V_396 ,
V_134 , - 128 , 127 , 1 , 0 ) ;
F_186 ( V_7 , & V_396 ,
V_135 , 0 , 255 , 1 , 128 ) ;
F_186 ( V_7 , & V_396 ,
V_136 , 0 , 255 , 1 , 128 ) ;
F_186 ( V_7 , & V_396 ,
V_137 , 0 , 128 , 1 , 0 ) ;
V_131 = F_187 ( V_7 , & V_396 ,
V_142 , V_143 ,
0 , V_143 ) ;
if ( V_131 )
V_131 -> V_126 |= V_397 ;
V_2 -> V_82 = F_186 ( V_7 , NULL ,
V_398 , 0 ,
( 1 << V_2 -> V_3 -> V_40 ) - 1 , 0 , 0 ) ;
V_2 -> V_399 =
F_187 ( V_7 , & V_396 ,
V_138 , V_129 ,
0 , V_125 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_400 =
F_188 ( V_7 , & V_401 , NULL ) ;
V_2 -> V_402 =
F_188 ( V_7 , & V_403 , NULL ) ;
V_2 -> V_404 =
F_188 ( V_7 , & V_405 , NULL ) ;
V_13 -> V_345 = V_7 ;
if ( V_7 -> error ) {
V_20 = V_7 -> error ;
goto V_406;
}
if ( F_65 ( V_13 ) ) {
V_20 = - V_369 ;
goto V_406;
}
for ( V_8 = 1 ; V_8 < V_371 ; ++ V_8 ) {
if ( ! ( F_37 ( V_8 ) & V_2 -> V_3 -> V_55 ) )
continue;
V_2 -> V_19 [ V_8 ] =
F_161 ( V_13 , V_2 -> V_225 . V_363 [ V_8 ] ,
0xf2 + V_8 ) ;
if ( V_2 -> V_19 [ V_8 ] == NULL ) {
V_20 = - V_380 ;
F_70 ( V_13 , L_170 , V_8 ) ;
goto V_407;
}
}
F_189 ( & V_2 -> V_47 ,
F_39 ) ;
V_2 -> V_167 = V_2 -> V_3 -> V_40
+ ( V_2 -> V_3 -> V_4 ? 2 : 0 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_167 ; ++ V_8 )
V_2 -> V_408 [ V_8 ] . V_126 = V_409 ;
V_2 -> V_408 [ V_2 -> V_167 ] . V_126 = V_410 ;
V_20 = F_190 ( & V_13 -> V_411 , V_2 -> V_167 + 1 ,
V_2 -> V_408 ) ;
if ( V_20 )
goto V_412;
V_20 = F_172 ( V_2 ) ;
if ( V_20 )
goto V_413;
V_20 = F_154 ( V_13 ) ;
if ( V_20 )
goto V_413;
#if F_129 ( V_280 )
V_2 -> V_247 = F_191 ( & V_414 ,
V_2 , F_192 ( & V_18 -> V_308 ) ,
V_415 | V_416 |
V_417 | V_418 , V_265 ,
& V_18 -> V_308 ) ;
V_20 = F_193 ( V_2 -> V_247 ) ;
if ( V_20 )
goto V_413;
#endif
F_59 ( V_13 , L_171 , V_18 -> V_197 ,
V_18 -> V_23 << 1 , V_18 -> V_347 -> V_197 ) ;
V_20 = F_194 ( V_13 ) ;
if ( V_20 )
goto V_413;
return 0 ;
V_413:
F_195 ( & V_13 -> V_411 ) ;
V_412:
F_196 ( & V_2 -> V_47 ) ;
V_407:
F_159 ( V_2 ) ;
V_406:
F_197 ( V_7 ) ;
return V_20 ;
}
static int F_198 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_199 ( V_18 ) ;
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_16 ( V_13 , 0x40 , 0 ) ;
F_16 ( V_13 , 0x41 , 0 ) ;
F_16 ( V_13 , 0x46 , 0 ) ;
F_16 ( V_13 , 0x6e , 0 ) ;
F_16 ( V_13 , 0x73 , 0 ) ;
F_196 ( & V_2 -> V_47 ) ;
F_200 ( V_13 ) ;
F_195 ( & V_13 -> V_411 ) ;
F_159 ( F_4 ( V_13 ) ) ;
F_197 ( V_13 -> V_345 ) ;
return 0 ;
}
