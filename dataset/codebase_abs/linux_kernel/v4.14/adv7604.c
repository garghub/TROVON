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
if ( V_54 >= V_55 || ! ( F_37 ( V_54 ) & V_2 -> V_3 -> V_56 ) )
return - V_57 ;
V_16 &= 0xff ;
V_20 = F_11 ( V_2 -> V_22 [ V_54 ] , V_16 , & V_21 ) ;
return V_20 ? V_20 : V_21 ;
}
static int F_53 ( struct V_12 * V_13 , unsigned int V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
unsigned int V_54 = V_16 >> 8 ;
if ( V_54 >= V_55 || ! ( F_37 ( V_54 ) & V_2 -> V_3 -> V_56 ) )
return - V_57 ;
V_16 &= 0xff ;
return F_17 ( V_2 -> V_22 [ V_54 ] , V_16 , V_21 ) ;
}
static void F_54 ( struct V_12 * V_13 ,
const struct V_58 * V_59 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_59 [ V_8 ] . V_16 != V_60 ; V_8 ++ )
F_53 ( V_13 , V_59 [ V_8 ] . V_16 , V_59 [ V_8 ] . V_21 ) ;
}
static const struct V_61 *
V_61 ( struct V_1 * V_2 , T_4 V_62 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_63 ; ++ V_8 ) {
if ( V_2 -> V_3 -> V_64 [ V_8 ] . V_62 == V_62 )
return & V_2 -> V_3 -> V_64 [ V_8 ] ;
}
return NULL ;
}
static inline bool F_55 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return V_2 -> V_65 == V_66 ||
V_2 -> V_65 == V_67 ;
}
static inline bool F_56 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return V_2 -> V_65 == V_68 ||
V_2 -> V_65 == V_69 ||
V_2 -> V_65 == V_70 ||
V_2 -> V_65 == V_71 ;
}
static const struct V_72 *
F_57 ( struct V_12 * V_13 , int V_73 )
{
if ( V_73 == - 1 ) {
struct V_1 * V_2 = F_4 ( V_13 ) ;
V_73 = V_2 -> V_65 ;
}
switch ( V_73 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
return & V_74 ;
case V_66 :
case V_67 :
default:
return & V_75 ;
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
struct V_76 * V_16 )
{
int V_77 ;
V_77 = F_52 ( V_13 , V_16 -> V_16 ) ;
if ( V_77 < 0 ) {
F_59 ( V_13 , L_17 , V_16 -> V_16 ) ;
F_58 ( V_13 ) ;
return V_77 ;
}
V_16 -> V_78 = 1 ;
V_16 -> V_21 = V_77 ;
return 0 ;
}
static int F_61 ( struct V_12 * V_13 ,
const struct V_76 * V_16 )
{
int V_77 ;
V_77 = F_53 ( V_13 , V_16 -> V_16 , V_16 -> V_21 ) ;
if ( V_77 < 0 ) {
F_59 ( V_13 , L_17 , V_16 -> V_16 ) ;
F_58 ( V_13 ) ;
return V_77 ;
}
return 0 ;
}
static unsigned int F_62 ( struct V_12 * V_13 )
{
T_1 V_79 = F_15 ( V_13 , 0x6f ) ;
return ( ( V_79 & 0x10 ) >> 4 )
| ( ( V_79 & 0x08 ) >> 2 )
| ( ( V_79 & 0x04 ) << 0 )
| ( ( V_79 & 0x02 ) << 2 ) ;
}
static unsigned int F_63 ( struct V_12 * V_13 )
{
T_1 V_79 = F_15 ( V_13 , 0x6f ) ;
return V_79 & 1 ;
}
static unsigned int F_64 ( struct V_12 * V_13 )
{
T_1 V_79 = F_15 ( V_13 , 0x6f ) ;
return V_79 & 1 ;
}
static int F_65 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
T_3 V_81 = V_3 -> V_82 ( V_13 ) ;
return F_66 ( V_2 -> V_83 , V_81 ) ;
}
static int F_67 ( struct V_12 * V_13 ,
T_1 V_84 ,
const struct V_85 * V_86 ,
const struct V_5 * V_87 )
{
int V_8 ;
for ( V_8 = 0 ; V_86 [ V_8 ] . V_87 . V_10 . V_11 ; V_8 ++ ) {
if ( ! F_3 ( V_87 , & V_86 [ V_8 ] . V_87 ,
F_56 ( V_13 ) ? 250000 : 1000000 , false ) )
continue;
F_16 ( V_13 , 0x00 , V_86 [ V_8 ] . V_88 ) ;
F_16 ( V_13 , 0x01 , ( V_86 [ V_8 ] . V_89 << 4 ) +
V_84 ) ;
return 0 ;
}
return - 1 ;
}
static int F_68 ( struct V_12 * V_13 ,
struct V_5 * V_87 )
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
0x01 , V_90 , V_87 ) ;
if ( V_20 )
V_20 = F_67 ( V_13 ,
0x02 , V_91 , V_87 ) ;
} else if ( F_56 ( V_13 ) ) {
V_20 = F_67 ( V_13 ,
0x05 , V_92 , V_87 ) ;
if ( V_20 )
V_20 = F_67 ( V_13 ,
0x06 , V_93 , V_87 ) ;
} else {
F_34 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_65 ) ;
V_20 = - 1 ;
}
return V_20 ;
}
static void F_69 ( struct V_12 * V_13 ,
const struct V_14 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_4 V_11 = F_6 ( V_10 ) ;
T_4 V_94 = F_8 ( V_10 ) ;
T_3 V_95 = V_10 -> V_96 + V_10 -> V_97 - 4 ;
T_3 V_98 = V_11 - V_10 -> V_99 ;
T_3 V_100 = V_94 - V_10 -> V_101 ;
T_3 V_102 = V_10 -> V_103 + V_10 -> V_104 ;
T_3 V_105 = ( ( ( T_4 ) V_10 -> V_106 / 100 ) > 0 ) ?
( ( V_11 * ( V_107 / 100 ) ) / ( ( T_4 ) V_10 -> V_106 / 100 ) ) : 0 ;
const T_1 V_108 [ 2 ] = {
0xc0 | ( ( V_11 >> 8 ) & 0x1f ) ,
V_11 & 0xff
} ;
F_34 ( 2 , V_37 , V_13 , L_20 , V_38 ) ;
if ( F_55 ( V_13 ) ) {
F_16 ( V_13 , 0x00 , 0x07 ) ;
F_16 ( V_13 , 0x01 , 0x02 ) ;
F_49 ( V_13 , 0x81 , 0x10 , 0x10 ) ;
if ( F_14 ( V_2 -> V_22 [ V_27 ] ,
0x16 , V_108 , 2 ) )
F_70 ( V_13 , L_21 ) ;
F_48 ( V_13 , 0xa2 , ( V_95 >> 4 ) & 0xff ) ;
F_48 ( V_13 , 0xa3 , ( ( V_95 & 0x0f ) << 4 ) |
( ( V_98 >> 8 ) & 0x0f ) ) ;
F_48 ( V_13 , 0xa4 , V_98 & 0xff ) ;
F_48 ( V_13 , 0xa5 , ( V_100 >> 4 ) & 0xff ) ;
F_48 ( V_13 , 0xa6 , ( ( V_100 & 0xf ) << 4 ) |
( ( V_102 >> 8 ) & 0xf ) ) ;
F_48 ( V_13 , 0xa7 , V_102 & 0xff ) ;
} else if ( F_56 ( V_13 ) ) {
F_16 ( V_13 , 0x00 , 0x02 ) ;
F_16 ( V_13 , 0x01 , 0x06 ) ;
} else {
F_34 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_65 ) ;
}
F_48 ( V_13 , 0x8f , ( V_105 >> 8 ) & 0x7 ) ;
F_48 ( V_13 , 0x90 , V_105 & 0xff ) ;
F_48 ( V_13 , 0xab , ( V_94 >> 4 ) & 0xff ) ;
F_48 ( V_13 , 0xac , ( V_94 & 0x0f ) << 4 ) ;
}
static void F_71 ( struct V_12 * V_13 , bool V_109 , T_3 V_110 , T_3 V_111 , T_3 V_112 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_113 [ 4 ] ;
if ( V_109 ) {
V_110 = 0x3ff ;
V_111 = 0x3ff ;
V_112 = 0x3ff ;
}
F_34 ( 2 , V_37 , V_13 , L_22 ,
V_38 , V_109 ? L_23 : L_24 ,
V_110 , V_111 , V_112 ) ;
V_113 [ 0 ] = ( F_46 ( V_13 , 0x77 ) & 0xc0 ) | ( ( V_110 & 0x3f0 ) >> 4 ) ;
V_113 [ 1 ] = ( ( V_110 & 0x00f ) << 4 ) | ( ( V_111 & 0x3c0 ) >> 6 ) ;
V_113 [ 2 ] = ( ( V_111 & 0x03f ) << 2 ) | ( ( V_112 & 0x300 ) >> 8 ) ;
V_113 [ 3 ] = V_112 & 0x0ff ;
if ( F_14 ( V_2 -> V_22 [ V_52 ] ,
0x77 , V_113 , 4 ) )
F_70 ( V_13 , L_25 , V_38 ) ;
}
static void F_72 ( struct V_12 * V_13 , bool V_114 , T_3 V_115 , T_3 V_116 , T_3 V_117 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_118 [ 4 ] ;
T_1 V_119 = 1 ;
T_1 V_120 = 1 ;
if ( V_114 ) {
V_119 = 0 ;
V_120 = 0 ;
V_115 = 0x100 ;
V_116 = 0x100 ;
V_117 = 0x100 ;
}
F_34 ( 2 , V_37 , V_13 , L_26 ,
V_38 , V_114 ? L_23 : L_24 ,
V_115 , V_116 , V_117 ) ;
V_118 [ 0 ] = ( ( V_119 << 7 ) | ( V_120 << 6 ) | ( ( V_115 & 0x3f0 ) >> 4 ) ) ;
V_118 [ 1 ] = ( ( ( V_115 & 0x00f ) << 4 ) | ( ( V_116 & 0x3c0 ) >> 6 ) ) ;
V_118 [ 2 ] = ( ( ( V_116 & 0x03f ) << 2 ) | ( ( V_117 & 0x300 ) >> 8 ) ) ;
V_118 [ 3 ] = ( ( V_117 & 0x0ff ) ) ;
if ( F_14 ( V_2 -> V_22 [ V_52 ] ,
0x73 , V_118 , 4 ) )
F_70 ( V_13 , L_27 , V_38 ) ;
}
static void F_73 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
bool V_121 = F_15 ( V_13 , 0x02 ) & 0x02 ;
bool V_122 = F_41 ( V_13 , 0x05 ) & 0x80 ;
T_1 V_123 = V_124 ;
if ( V_122 && ( F_15 ( V_13 , 0x60 ) & 1 ) )
V_123 = F_24 ( V_13 , 0x01 ) >> 5 ;
F_34 ( 2 , V_37 , V_13 , L_28 ,
V_38 , V_2 -> V_125 ,
V_121 , V_122 ) ;
F_72 ( V_13 , true , 0x0 , 0x0 , 0x0 ) ;
F_71 ( V_13 , true , 0x0 , 0x0 , 0x0 ) ;
F_18 ( V_13 , 0x02 , 0x04 , V_121 ? 0 : 4 ) ;
switch ( V_2 -> V_125 ) {
case V_126 :
if ( V_2 -> V_65 == V_66 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
break;
}
if ( V_2 -> V_65 == V_67 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_122 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_2 -> V_87 . V_10 . V_127 & V_128 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x00 ) ;
} else {
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_56 ( V_13 ) && V_121 ) {
F_71 ( V_13 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_72 ( V_13 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_71 ( V_13 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_129 :
if ( V_2 -> V_65 == V_67 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x20 ) ;
break;
}
if ( V_123 != V_124 )
break;
F_18 ( V_13 , 0x02 , 0xf0 , 0x00 ) ;
break;
case V_130 :
if ( V_2 -> V_65 == V_67 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x60 ) ;
break;
}
if ( V_123 != V_124 )
break;
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_55 ( V_13 ) || V_122 )
break;
if ( V_121 ) {
F_71 ( V_13 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_72 ( V_13 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_71 ( V_13 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_74 ( struct V_131 * V_132 )
{
struct V_12 * V_13 =
& F_5 ( V_132 -> V_133 , struct V_1 , V_7 ) -> V_13 ;
struct V_1 * V_2 = F_4 ( V_13 ) ;
switch ( V_132 -> V_134 ) {
case V_135 :
F_48 ( V_13 , 0x3c , V_132 -> V_21 ) ;
return 0 ;
case V_136 :
F_48 ( V_13 , 0x3a , V_132 -> V_21 ) ;
return 0 ;
case V_137 :
F_48 ( V_13 , 0x3b , V_132 -> V_21 ) ;
return 0 ;
case V_138 :
F_48 ( V_13 , 0x3d , V_132 -> V_21 ) ;
return 0 ;
case V_139 :
V_2 -> V_125 = V_132 -> V_21 ;
F_73 ( V_13 ) ;
return 0 ;
case V_140 :
if ( ! F_1 ( V_2 ) )
return - V_57 ;
F_27 ( V_13 , 0xc8 , V_132 -> V_21 ) ;
return 0 ;
case V_141 :
F_49 ( V_13 , 0xbf , 0x04 , V_132 -> V_21 << 2 ) ;
return 0 ;
case V_142 :
F_48 ( V_13 , 0xc0 , ( V_132 -> V_21 & 0xff0000 ) >> 16 ) ;
F_48 ( V_13 , 0xc1 , ( V_132 -> V_21 & 0x00ff00 ) >> 8 ) ;
F_48 ( V_13 , 0xc2 , ( T_1 ) ( V_132 -> V_21 & 0x0000ff ) ) ;
return 0 ;
}
return - V_57 ;
}
static int F_75 ( struct V_131 * V_132 )
{
struct V_12 * V_13 =
& F_5 ( V_132 -> V_133 , struct V_1 , V_7 ) -> V_13 ;
if ( V_132 -> V_134 == V_143 ) {
V_132 -> V_21 = V_144 ;
if ( ( F_15 ( V_13 , 0x60 ) & 1 ) && ( F_24 ( V_13 , 0x03 ) & 0x80 ) )
V_132 -> V_21 = ( F_24 ( V_13 , 0x05 ) >> 4 ) & 3 ;
return 0 ;
}
return - V_57 ;
}
static inline bool F_76 ( struct V_12 * V_13 )
{
return F_15 ( V_13 , 0x0c ) & 0x24 ;
}
static inline bool F_77 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return ! ( F_15 ( V_13 , 0x6a ) & ( 0x10 >> V_2 -> V_65 ) ) ;
}
static inline bool F_78 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
return ( F_15 ( V_13 , 0x6a ) & V_3 -> V_145 ) != V_3 -> V_145 ;
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
bool V_77 ;
V_77 = F_76 ( V_13 ) ;
V_77 |= F_81 ( V_13 ) ;
V_77 |= F_80 ( V_13 ) ;
if ( F_56 ( V_13 ) ) {
V_77 |= F_78 ( V_13 ) ;
V_77 |= F_77 ( V_13 ) ;
}
return V_77 ;
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
static int F_85 ( struct V_12 * V_13 , T_4 * V_146 )
{
* V_146 = 0 ;
* V_146 |= F_76 ( V_13 ) ? V_147 : 0 ;
* V_146 |= F_82 ( V_13 ) ? V_148 : 0 ;
if ( ! F_84 ( V_13 ) && F_83 ( V_13 ) )
* V_146 |= F_56 ( V_13 ) ?
V_149 : V_150 ;
F_34 ( 1 , V_37 , V_13 , L_29 , V_38 , * V_146 ) ;
return 0 ;
}
static int F_86 ( struct V_12 * V_13 ,
struct V_151 * V_152 ,
struct V_5 * V_87 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_4 V_153 = ( V_107 * 8 ) / V_152 -> V_154 ;
T_4 V_155 ;
int V_8 ;
for ( V_8 = 0 ; V_156 [ V_8 ] . V_10 . V_11 ; V_8 ++ ) {
const struct V_14 * V_10 = & V_156 [ V_8 ] . V_10 ;
if ( ! F_87 ( & V_156 [ V_8 ] ,
F_57 ( V_13 , - 1 ) ,
F_2 , NULL ) )
continue;
if ( F_8 ( V_10 ) != V_152 -> V_157 + 1 )
continue;
if ( V_10 -> V_103 != V_152 -> V_158 )
continue;
V_155 = V_153 * F_6 ( V_10 ) ;
if ( ( V_155 < V_10 -> V_106 + 1000000 ) &&
( V_155 > V_10 -> V_106 - 1000000 ) ) {
* V_87 = V_156 [ V_8 ] ;
return 0 ;
}
}
if ( F_88 ( V_152 -> V_157 + 1 , V_153 , V_152 -> V_158 , 0 ,
( V_152 -> V_159 == '+' ? V_160 : 0 ) |
( V_152 -> V_161 == '+' ? V_162 : 0 ) ,
false , V_87 ) )
return 0 ;
if ( F_89 ( V_152 -> V_157 + 1 , V_153 , V_152 -> V_158 ,
( V_152 -> V_159 == '+' ? V_160 : 0 ) |
( V_152 -> V_161 == '+' ? V_162 : 0 ) ,
false , V_2 -> V_163 , V_87 ) )
return 0 ;
F_34 ( 2 , V_37 , V_13 ,
L_30 ,
V_38 , V_152 -> V_158 , V_152 -> V_157 , V_152 -> V_154 ,
V_152 -> V_159 , V_152 -> V_161 ) ;
return - 1 ;
}
static int F_90 ( struct V_12 * V_13 , struct V_151 * V_152 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
T_1 V_164 ;
if ( F_81 ( V_13 ) || F_80 ( V_13 ) ) {
F_34 ( 2 , V_37 , V_13 , L_31 , V_38 ) ;
return - 1 ;
}
V_152 -> V_154 = F_47 ( V_13 , 0xb1 , 0x3fff ) ;
V_152 -> V_157 = F_47 ( V_13 , V_3 -> V_165 , 0x7ff ) ;
V_152 -> V_158 = F_46 ( V_13 , 0xb3 ) >> 3 ;
V_152 -> V_166 = F_15 ( V_13 , 0x12 ) & 0x10 ;
if ( F_1 ( V_2 ) ) {
V_164 = F_46 ( V_13 , 0xb5 ) ;
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
V_164 = F_41 ( V_13 , 0x05 ) ;
V_152 -> V_159 = V_164 & 0x20 ? '+' : '-' ;
V_152 -> V_161 = V_164 & 0x10 ? '+' : '-' ;
}
if ( F_81 ( V_13 ) || F_80 ( V_13 ) ) {
F_34 ( 2 , V_37 , V_13 ,
L_32 , V_38 ) ;
return - 1 ;
}
if ( V_152 -> V_157 < 239 || V_152 -> V_154 < 8 || V_152 -> V_154 == 0x3fff ) {
F_34 ( 2 , V_37 , V_13 , L_33 , V_38 ) ;
memset ( V_152 , 0 , sizeof( struct V_151 ) ) ;
return - 1 ;
}
F_34 ( 2 , V_37 , V_13 ,
L_34 ,
V_38 , V_152 -> V_157 , V_152 -> V_154 , V_152 -> V_158 ,
V_152 -> V_159 , V_152 -> V_161 ,
V_152 -> V_166 ? L_35 : L_36 ) ;
return 0 ;
}
static int F_91 ( struct V_12 * V_13 ,
struct V_167 * V_87 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_87 -> V_73 >= V_2 -> V_168 )
return - V_57 ;
return F_92 ( V_87 ,
F_57 ( V_13 , V_87 -> V_73 ) ,
F_2 , NULL ) ;
}
static int F_93 ( struct V_12 * V_13 ,
struct V_72 * V_169 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
unsigned int V_73 = V_169 -> V_73 ;
if ( V_169 -> V_73 >= V_2 -> V_168 )
return - V_57 ;
* V_169 = * F_57 ( V_13 , V_73 ) ;
V_169 -> V_73 = V_73 ;
return 0 ;
}
static void F_94 ( struct V_12 * V_13 ,
struct V_5 * V_87 )
{
F_95 ( V_87 , F_57 ( V_13 , - 1 ) ,
F_56 ( V_13 ) ? 250000 : 1000000 ,
F_2 , NULL ) ;
}
static unsigned int F_96 ( struct V_12 * V_13 )
{
unsigned int V_170 ;
int V_171 , V_172 ;
V_171 = F_41 ( V_13 , 0x06 ) ;
V_172 = F_41 ( V_13 , 0x3b ) ;
if ( V_171 < 0 || V_172 < 0 )
return 0 ;
V_170 = V_171 * 1000000 + ( ( V_172 & 0x30 ) >> 4 ) * 250000 ;
if ( F_79 ( V_13 ) ) {
unsigned V_173 = ( ( F_41 ( V_13 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_170 = V_170 * 8 / V_173 ;
}
return V_170 ;
}
static unsigned int F_97 ( struct V_12 * V_13 )
{
int V_171 , V_172 ;
V_171 = F_41 ( V_13 , 0x51 ) ;
V_172 = F_41 ( V_13 , 0x52 ) ;
if ( V_171 < 0 || V_172 < 0 )
return 0 ;
return ( ( V_171 << 1 ) | ( V_172 >> 7 ) ) * 1000000 + ( V_172 & 0x7f ) * 1000000 / 128 ;
}
static int F_98 ( struct V_12 * V_13 ,
struct V_5 * V_87 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
struct V_14 * V_10 = & V_87 -> V_10 ;
struct V_151 V_152 ;
if ( ! V_87 )
return - V_57 ;
memset ( V_87 , 0 , sizeof( struct V_5 ) ) ;
if ( F_82 ( V_13 ) ) {
V_2 -> V_174 = true ;
F_34 ( 1 , V_37 , V_13 , L_37 , V_38 ) ;
return - V_175 ;
}
if ( F_90 ( V_13 , & V_152 ) ) {
F_34 ( 1 , V_37 , V_13 , L_38 , V_38 ) ;
return - V_175 ;
}
V_10 -> V_166 = V_152 . V_166 ?
V_176 : V_177 ;
if ( F_56 ( V_13 ) ) {
bool V_122 = F_41 ( V_13 , 0x05 ) & 0x80 ;
T_1 V_178 = 0 ;
T_4 V_179 , V_180 ;
V_179 = F_42 ( V_13 , 0x07 , V_3 -> V_181 ) ;
V_180 = F_42 ( V_13 , 0x09 , V_3 -> V_182 ) ;
if ( V_122 && ( F_15 ( V_13 , 0x60 ) & 1 ) )
V_178 = F_24 ( V_13 , 0x04 ) ;
if ( V_178 && F_99 ( V_87 , V_178 ) &&
V_10 -> V_11 == V_179 && V_10 -> V_94 == V_180 )
goto V_183;
V_87 -> type = V_184 ;
V_10 -> V_11 = V_179 ;
V_10 -> V_94 = V_180 ;
V_10 -> V_106 = V_3 -> V_185 ( V_13 ) ;
V_10 -> V_99 = F_42 ( V_13 , 0x20 , V_3 -> V_186 ) ;
V_10 -> V_96 = F_42 ( V_13 , 0x22 , V_3 -> V_187 ) ;
V_10 -> V_97 = F_42 ( V_13 , 0x24 , V_3 -> V_188 ) ;
V_10 -> V_101 = F_42 ( V_13 , 0x2a ,
V_3 -> V_189 ) / 2 ;
V_10 -> V_103 = F_42 ( V_13 , 0x2e , V_3 -> V_190 ) / 2 ;
V_10 -> V_104 = F_42 ( V_13 , 0x32 ,
V_3 -> V_191 ) / 2 ;
V_10 -> V_192 = ( ( F_41 ( V_13 , 0x05 ) & 0x10 ) ? V_162 : 0 ) |
( ( F_41 ( V_13 , 0x05 ) & 0x20 ) ? V_160 : 0 ) ;
if ( V_10 -> V_166 == V_176 ) {
V_10 -> V_94 += F_42 ( V_13 , 0x0b ,
V_3 -> V_193 ) ;
V_10 -> V_194 = F_42 ( V_13 , 0x2c ,
V_3 -> V_195 ) / 2 ;
V_10 -> V_196 = F_42 ( V_13 , 0x30 ,
V_3 -> V_197 ) / 2 ;
V_10 -> V_198 = F_42 ( V_13 , 0x34 ,
V_3 -> V_199 ) / 2 ;
}
F_94 ( V_13 , V_87 ) ;
} else {
if ( ! F_86 ( V_13 , & V_152 , V_87 ) )
goto V_183;
V_152 . V_158 += 1 ;
F_34 ( 1 , V_37 , V_13 , L_39 , V_38 , V_152 . V_158 ) ;
if ( ! F_86 ( V_13 , & V_152 , V_87 ) )
goto V_183;
V_152 . V_158 -= 2 ;
F_34 ( 1 , V_37 , V_13 , L_40 , V_38 , V_152 . V_158 ) ;
if ( F_86 ( V_13 , & V_152 , V_87 ) ) {
if ( V_2 -> V_174 ) {
F_34 ( 1 , V_37 , V_13 , L_41 , V_38 ) ;
F_49 ( V_13 , 0x86 , 0x06 , 0x00 ) ;
F_49 ( V_13 , 0x86 , 0x06 , 0x04 ) ;
F_49 ( V_13 , 0x86 , 0x06 , 0x02 ) ;
V_2 -> V_174 = false ;
return - V_175 ;
}
F_34 ( 1 , V_37 , V_13 , L_42 , V_38 ) ;
return - V_200 ;
}
V_2 -> V_174 = true ;
}
V_183:
if ( F_82 ( V_13 ) ) {
F_34 ( 1 , V_37 , V_13 , L_43 , V_38 ) ;
memset ( V_87 , 0 , sizeof( struct V_5 ) ) ;
return - V_175 ;
}
if ( ( F_55 ( V_13 ) && V_10 -> V_106 > 170000000 ) ||
( F_56 ( V_13 ) && V_10 -> V_106 > 225000000 ) ) {
F_34 ( 1 , V_37 , V_13 , L_44 ,
V_38 , ( T_4 ) V_10 -> V_106 ) ;
return - V_200 ;
}
if ( V_37 > 1 )
F_100 ( V_13 -> V_201 , L_45 ,
V_87 , true ) ;
return 0 ;
}
static int F_101 ( struct V_12 * V_13 ,
struct V_5 * V_87 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_14 * V_10 ;
int V_20 ;
if ( ! V_87 )
return - V_57 ;
if ( F_3 ( & V_2 -> V_87 , V_87 , 0 , false ) ) {
F_34 ( 1 , V_37 , V_13 , L_46 , V_38 ) ;
return 0 ;
}
V_10 = & V_87 -> V_10 ;
if ( ! F_87 ( V_87 , F_57 ( V_13 , - 1 ) ,
F_2 , NULL ) )
return - V_200 ;
F_94 ( V_13 , V_87 ) ;
V_2 -> V_87 = * V_87 ;
F_49 ( V_13 , 0x91 , 0x40 , V_10 -> V_166 ? 0x40 : 0x00 ) ;
V_20 = F_68 ( V_13 , V_87 ) ;
if ( V_20 ) {
F_69 ( V_13 , V_10 ) ;
}
F_73 ( V_13 ) ;
if ( V_37 > 1 )
F_100 ( V_13 -> V_201 , L_47 ,
V_87 , true ) ;
return 0 ;
}
static int F_102 ( struct V_12 * V_13 ,
struct V_5 * V_87 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
* V_87 = V_2 -> V_87 ;
return 0 ;
}
static void F_103 ( struct V_12 * V_13 , bool V_202 )
{
F_43 ( V_13 , 0x01 , V_202 ? 0x00 : 0x78 ) ;
}
static void F_104 ( struct V_12 * V_13 , bool V_202 )
{
F_43 ( V_13 , 0x83 , V_202 ? 0xfe : 0xff ) ;
}
static void F_105 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( F_55 ( V_13 ) ) {
F_16 ( V_13 , 0x15 , 0xb0 ) ;
} else if ( F_56 ( V_13 ) ) {
F_44 ( V_13 , 0x00 , 0x03 , V_2 -> V_65 ) ;
V_2 -> V_3 -> V_203 ( V_13 , true ) ;
F_16 ( V_13 , 0x15 , 0xa0 ) ;
F_44 ( V_13 , 0x1a , 0x10 , 0x00 ) ;
} else {
F_34 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_65 ) ;
}
}
static void F_106 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_44 ( V_13 , 0x1a , 0x10 , 0x10 ) ;
F_107 ( 16 ) ;
F_16 ( V_13 , 0x15 , 0xbe ) ;
V_2 -> V_3 -> V_203 ( V_13 , false ) ;
}
static void F_108 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
if ( F_55 ( V_13 ) ) {
F_54 ( V_13 , V_3 -> V_204 [ 0 ] ) ;
F_27 ( V_13 , 0x00 , 0x08 ) ;
F_27 ( V_13 , 0x01 , 0x06 ) ;
F_27 ( V_13 , 0xc8 , 0x00 ) ;
} else if ( F_56 ( V_13 ) ) {
F_43 ( V_13 , 0x00 , V_2 -> V_65 & 0x03 ) ;
F_54 ( V_13 , V_3 -> V_204 [ 1 ] ) ;
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
V_38 , V_2 -> V_65 ) ;
}
}
static int F_109 ( struct V_12 * V_13 ,
T_4 V_205 , T_4 V_206 , T_4 V_207 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_34 ( 2 , V_37 , V_13 , L_48 ,
V_38 , V_205 , V_2 -> V_65 ) ;
if ( V_205 == V_2 -> V_65 )
return 0 ;
if ( V_205 > V_2 -> V_3 -> V_208 )
return - V_57 ;
V_2 -> V_65 = V_205 ;
F_106 ( V_13 ) ;
F_108 ( V_13 ) ;
F_105 ( V_13 ) ;
F_110 ( V_13 , & V_209 ) ;
return 0 ;
}
static int F_111 ( struct V_12 * V_13 ,
struct V_210 * V_211 ,
struct V_212 * V_62 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_62 -> V_213 >= V_2 -> V_3 -> V_63 )
return - V_57 ;
V_62 -> V_62 = V_2 -> V_3 -> V_64 [ V_62 -> V_213 ] . V_62 ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
V_215 -> V_11 = V_2 -> V_87 . V_10 . V_11 ;
V_215 -> V_94 = V_2 -> V_87 . V_10 . V_94 ;
V_215 -> V_216 = V_217 ;
V_215 -> V_218 = V_219 ;
if ( V_2 -> V_87 . V_10 . V_127 & V_128 )
V_215 -> V_218 = ( V_2 -> V_87 . V_10 . V_94 <= 576 ) ?
V_220 : V_221 ;
}
static unsigned int F_113 ( struct V_1 * V_2 )
{
#define F_114 ( V_171 , V_172 , T_5 , T_6 , T_7 , T_8 ) { \
ADV76XX_OP_CH_SEL_##a, ADV76XX_OP_CH_SEL_##b, ADV76XX_OP_CH_SEL_##c, \
ADV76XX_OP_CH_SEL_##d, ADV76XX_OP_CH_SEL_##e, ADV76XX_OP_CH_SEL_##f }
#define F_115 ( T_9 ) [ADV7604_BUS_ORDER_##x]
static const unsigned int V_222 [ 6 ] [ 6 ] = {
F_115 ( V_223 ) = F_114 ( V_224 , V_225 , V_226 , V_223 , V_227 , V_228 ) ,
F_115 ( V_225 ) = F_114 ( V_226 , V_223 , V_224 , V_225 , V_228 , V_227 ) ,
F_115 ( V_228 ) = F_114 ( V_225 , V_224 , V_227 , V_228 , V_226 , V_223 ) ,
F_115 ( V_226 ) = F_114 ( V_228 , V_227 , V_223 , V_226 , V_225 , V_224 ) ,
F_115 ( V_227 ) = F_114 ( V_227 , V_228 , V_225 , V_224 , V_223 , V_226 ) ,
F_115 ( V_224 ) = F_114 ( V_223 , V_226 , V_228 , V_227 , V_224 , V_225 ) ,
} ;
return V_222 [ V_2 -> V_229 . V_230 ] [ V_2 -> V_215 -> V_222 >> 5 ] ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_13 ;
F_18 ( V_13 , 0x02 , 0x02 ,
V_2 -> V_215 -> V_231 ? V_232 : 0 ) ;
F_16 ( V_13 , 0x03 , V_2 -> V_215 -> V_233 |
V_2 -> V_229 . V_234 ) ;
F_18 ( V_13 , 0x04 , 0xe0 , F_113 ( V_2 ) ) ;
F_18 ( V_13 , 0x05 , 0x01 ,
V_2 -> V_215 -> V_235 ? V_236 : 0 ) ;
F_73 ( V_13 ) ;
}
static int F_117 ( struct V_12 * V_13 ,
struct V_210 * V_211 ,
struct V_237 * V_215 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_215 -> V_73 != V_2 -> V_168 )
return - V_57 ;
F_112 ( V_2 , & V_215 -> V_215 ) ;
if ( V_215 -> V_238 == V_239 ) {
struct V_214 * V_240 ;
V_240 = F_118 ( V_13 , V_211 , V_215 -> V_73 ) ;
V_215 -> V_215 . V_62 = V_240 -> V_62 ;
} else {
V_215 -> V_215 . V_62 = V_2 -> V_215 -> V_62 ;
}
return 0 ;
}
static int F_119 ( struct V_12 * V_13 ,
struct V_210 * V_211 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_242 -> V_238 != V_243 )
return - V_57 ;
if ( V_242 -> V_244 > V_245 )
return - V_57 ;
V_242 -> V_246 . V_247 = 0 ;
V_242 -> V_246 . V_248 = 0 ;
V_242 -> V_246 . V_11 = V_2 -> V_87 . V_10 . V_11 ;
V_242 -> V_246 . V_94 = V_2 -> V_87 . V_10 . V_94 ;
return 0 ;
}
static int F_120 ( struct V_12 * V_13 ,
struct V_210 * V_211 ,
struct V_237 * V_215 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_61 * V_3 ;
if ( V_215 -> V_73 != V_2 -> V_168 )
return - V_57 ;
V_3 = V_61 ( V_2 , V_215 -> V_215 . V_62 ) ;
if ( V_3 == NULL )
V_3 = V_61 ( V_2 , V_249 ) ;
F_112 ( V_2 , & V_215 -> V_215 ) ;
V_215 -> V_215 . V_62 = V_3 -> V_62 ;
if ( V_215 -> V_238 == V_239 ) {
struct V_214 * V_240 ;
V_240 = F_118 ( V_13 , V_211 , V_215 -> V_73 ) ;
V_240 -> V_62 = V_215 -> V_215 . V_62 ;
} else {
V_2 -> V_215 = V_3 ;
F_116 ( V_2 ) ;
}
return 0 ;
}
static void F_121 ( struct V_12 * V_13 , T_1 V_250 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( ( F_21 ( V_13 , 0x11 ) & 0x01 ) == 0 ) {
F_34 ( 1 , V_37 , V_13 , L_49 , V_38 ) ;
return;
}
if ( V_250 & 0x02 ) {
F_34 ( 1 , V_37 , V_13 , L_50 ,
V_38 ) ;
F_122 ( V_2 -> V_251 , V_252 ,
1 , 0 , 0 , 0 ) ;
}
if ( V_250 & 0x04 ) {
T_1 V_146 ;
T_1 V_253 ;
T_1 V_254 ;
F_34 ( 1 , V_37 , V_13 , L_51 , V_38 ) ;
V_146 = V_255 ;
V_253 = F_21 ( V_13 , 0x14 ) & 0xf ;
if ( V_253 )
V_146 |= V_256 ;
V_254 = F_21 ( V_13 , 0x14 ) >> 4 ;
if ( V_254 )
V_146 |= V_257 ;
F_122 ( V_2 -> V_251 , V_146 ,
0 , V_253 , V_254 , 0 ) ;
return;
}
if ( V_250 & 0x01 ) {
F_34 ( 1 , V_37 , V_13 , L_52 , V_38 ) ;
F_122 ( V_2 -> V_251 , V_258 , 0 , 0 , 0 , 0 ) ;
return;
}
}
static void F_123 ( struct V_12 * V_13 , bool * V_259 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_260 ;
V_260 = F_15 ( V_13 , 0x4d ) & 0x0f ;
if ( ! V_260 )
return;
F_34 ( 1 , V_37 , V_13 , L_53 , V_38 , V_260 ) ;
F_121 ( V_13 , V_260 ) ;
if ( V_260 & 0x08 ) {
struct V_261 V_262 ;
V_262 . V_36 = F_21 ( V_13 , 0x25 ) & 0x1f ;
if ( V_262 . V_36 > 16 )
V_262 . V_36 = 16 ;
if ( V_262 . V_36 ) {
T_1 V_8 ;
for ( V_8 = 0 ; V_8 < V_262 . V_36 ; V_8 ++ )
V_262 . V_262 [ V_8 ] = F_21 ( V_13 , V_8 + 0x15 ) ;
F_22 ( V_13 , 0x26 , 0x01 ) ;
F_124 ( V_2 -> V_251 , & V_262 ) ;
}
}
V_260 = ( ( V_260 & 0x08 ) >> 3 ) | ( ( V_260 & 0x04 ) >> 1 ) |
( ( V_260 & 0x02 ) << 1 ) | ( ( V_260 & 0x01 ) << 3 ) ;
F_16 ( V_13 , 0x4e , V_260 ) ;
if ( V_259 )
* V_259 = true ;
}
static int F_125 ( struct V_263 * V_264 , bool V_202 )
{
struct V_1 * V_2 = F_126 ( V_264 ) ;
struct V_12 * V_13 = & V_2 -> V_13 ;
if ( ! V_2 -> V_265 && V_202 ) {
F_23 ( V_13 , 0x2a , 0x01 , 0x01 ) ;
F_22 ( V_13 , 0x2c , 0x01 ) ;
F_23 ( V_13 , 0x11 , 0x01 , 0 ) ;
F_18 ( V_13 , 0x50 , 0x0f , 0x0f ) ;
F_22 ( V_13 , 0x26 , 0x01 ) ;
} else if ( V_2 -> V_265 && ! V_202 ) {
F_18 ( V_13 , 0x50 , 0x0f , 0x00 ) ;
F_23 ( V_13 , 0x27 , 0x70 , 0x00 ) ;
F_23 ( V_13 , 0x2a , 0x01 , 0x00 ) ;
V_2 -> V_266 = 0 ;
}
V_2 -> V_265 = V_202 ;
F_65 ( V_13 ) ;
return 0 ;
}
static int F_127 ( struct V_263 * V_264 , T_1 V_23 )
{
struct V_1 * V_2 = F_126 ( V_264 ) ;
struct V_12 * V_13 = & V_2 -> V_13 ;
unsigned int V_8 , V_267 = V_268 ;
if ( ! V_2 -> V_265 )
return V_23 == V_269 ? 0 : - V_270 ;
if ( V_23 == V_269 ) {
F_23 ( V_13 , 0x27 , 0x70 , 0 ) ;
V_2 -> V_266 = 0 ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < V_268 ; V_8 ++ ) {
bool V_271 = V_2 -> V_266 & ( 1 << V_8 ) ;
if ( V_267 == V_268 && ! V_271 )
V_267 = V_8 ;
if ( V_271 && V_2 -> V_272 [ V_8 ] == V_23 )
return 0 ;
}
if ( V_8 == V_268 ) {
V_8 = V_267 ;
if ( V_8 == V_268 )
return - V_273 ;
}
V_2 -> V_272 [ V_8 ] = V_23 ;
V_2 -> V_266 |= 1 << V_8 ;
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
static int F_128 ( struct V_263 * V_264 , T_1 V_274 ,
T_4 V_275 , struct V_261 * V_262 )
{
struct V_1 * V_2 = F_126 ( V_264 ) ;
struct V_12 * V_13 = & V_2 -> V_13 ;
T_1 V_36 = V_262 -> V_36 ;
unsigned int V_8 ;
F_23 ( V_13 , 0x12 , 0x70 , F_129 ( 1 , V_274 - 1 ) << 4 ) ;
if ( V_36 > 16 ) {
F_70 ( V_13 , L_54 , V_38 , V_36 ) ;
return - V_57 ;
}
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
F_22 ( V_13 , V_8 , V_262 -> V_262 [ V_8 ] ) ;
F_22 ( V_13 , 0x10 , V_36 ) ;
F_22 ( V_13 , 0x11 , 0x01 ) ;
return 0 ;
}
static int F_130 ( struct V_12 * V_13 , T_4 V_146 , bool * V_259 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
const T_1 V_276 = F_15 ( V_13 , 0x43 ) ;
const T_1 V_277 = F_15 ( V_13 , 0x6b ) ;
const T_1 V_278 = F_15 ( V_13 , 0x70 ) ;
T_1 V_279 ;
T_1 V_280 ;
T_1 V_281 ;
if ( V_276 )
F_16 ( V_13 , 0x44 , V_276 ) ;
if ( V_278 )
F_16 ( V_13 , 0x71 , V_278 ) ;
if ( V_277 )
F_16 ( V_13 , 0x6c , V_277 ) ;
F_34 ( 2 , V_37 , V_13 , L_55 , V_38 ) ;
V_280 = V_276 & 0x98 ;
V_279 = F_56 ( V_13 )
? V_277 & V_3 -> V_282
: 0 ;
if ( V_280 || V_279 ) {
F_34 ( 1 , V_37 , V_13 ,
L_56 ,
V_38 , V_280 , V_279 ) ;
F_110 ( V_13 , & V_209 ) ;
if ( V_259 )
* V_259 = true ;
}
if ( V_277 & 0x01 ) {
F_34 ( 1 , V_37 , V_13 , L_57 , V_38 ,
( F_15 ( V_13 , 0x6a ) & 0x01 ) ? L_58 : L_59 ) ;
F_73 ( V_13 ) ;
if ( V_259 )
* V_259 = true ;
}
#if F_131 ( V_283 )
F_123 ( V_13 , V_259 ) ;
#endif
V_281 = V_278 & V_3 -> V_284 ;
if ( V_281 ) {
F_34 ( 1 , V_37 , V_13 , L_60 , V_38 , V_281 ) ;
F_65 ( V_13 ) ;
if ( V_259 )
* V_259 = true ;
}
return 0 ;
}
static int F_132 ( struct V_12 * V_13 , struct V_285 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 * V_286 = NULL ;
memset ( V_48 -> V_287 , 0 , sizeof( V_48 -> V_287 ) ) ;
switch ( V_48 -> V_73 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
if ( V_2 -> V_48 . V_49 & ( 1 << V_48 -> V_73 ) )
V_286 = V_2 -> V_48 . V_48 ;
break;
default:
return - V_57 ;
}
if ( V_48 -> V_288 == 0 && V_48 -> V_289 == 0 ) {
V_48 -> V_289 = V_286 ? V_2 -> V_48 . V_289 : 0 ;
return 0 ;
}
if ( V_286 == NULL )
return - V_290 ;
if ( V_48 -> V_288 >= V_2 -> V_48 . V_289 )
return - V_57 ;
if ( V_48 -> V_288 + V_48 -> V_289 > V_2 -> V_48 . V_289 )
V_48 -> V_289 = V_2 -> V_48 . V_289 - V_48 -> V_288 ;
memcpy ( V_48 -> V_48 , V_286 + V_48 -> V_288 * 128 , V_48 -> V_289 * 128 ) ;
return 0 ;
}
static int F_133 ( struct V_12 * V_13 , struct V_285 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
unsigned int V_291 ;
T_3 V_292 ;
int V_20 ;
int V_8 ;
memset ( V_48 -> V_287 , 0 , sizeof( V_48 -> V_287 ) ) ;
if ( V_48 -> V_73 > V_71 )
return - V_57 ;
if ( V_48 -> V_288 != 0 )
return - V_57 ;
if ( V_48 -> V_289 == 0 ) {
V_2 -> V_48 . V_49 &= ~ ( 1 << V_48 -> V_73 ) ;
F_35 ( V_2 , V_2 -> V_48 . V_49 ) ;
F_30 ( V_13 , V_3 -> V_293 , 0x0f , V_2 -> V_48 . V_49 ) ;
V_2 -> V_163 . V_294 = 16 ;
V_2 -> V_163 . V_295 = 9 ;
if ( ! V_2 -> V_48 . V_49 )
V_2 -> V_48 . V_289 = 0 ;
F_34 ( 2 , V_37 , V_13 , L_61 ,
V_38 , V_48 -> V_73 , V_2 -> V_48 . V_49 ) ;
return 0 ;
}
if ( V_48 -> V_289 > 2 ) {
V_48 -> V_289 = 2 ;
return - V_296 ;
}
V_292 = F_134 ( V_48 -> V_48 , V_48 -> V_289 * 128 , & V_291 ) ;
V_20 = F_135 ( V_292 , & V_292 , NULL ) ;
if ( V_20 )
return V_20 ;
F_34 ( 2 , V_37 , V_13 , L_62 ,
V_38 , V_48 -> V_73 , V_2 -> V_48 . V_49 ) ;
F_136 ( & V_2 -> V_47 ) ;
F_35 ( V_2 , 0 ) ;
F_30 ( V_13 , V_3 -> V_293 , 0x0f , 0x00 ) ;
if ( V_291 == 0 )
return - V_57 ;
switch ( V_48 -> V_73 ) {
case V_68 :
V_2 -> V_297 [ 0 ] = V_48 -> V_48 [ V_291 ] ;
V_2 -> V_297 [ 1 ] = V_48 -> V_48 [ V_291 + 1 ] ;
break;
case V_69 :
F_29 ( V_13 , 0x70 , V_48 -> V_48 [ V_291 ] ) ;
F_29 ( V_13 , 0x71 , V_48 -> V_48 [ V_291 + 1 ] ) ;
break;
case V_70 :
F_29 ( V_13 , 0x72 , V_48 -> V_48 [ V_291 ] ) ;
F_29 ( V_13 , 0x73 , V_48 -> V_48 [ V_291 + 1 ] ) ;
break;
case V_71 :
F_29 ( V_13 , 0x74 , V_48 -> V_48 [ V_291 ] ) ;
F_29 ( V_13 , 0x75 , V_48 -> V_48 [ V_291 + 1 ] ) ;
break;
default:
return - V_57 ;
}
if ( V_3 -> type == V_298 ) {
F_29 ( V_13 , 0x76 , V_291 & 0xff ) ;
F_30 ( V_13 , 0x77 , 0x40 , ( V_291 & 0x100 ) >> 2 ) ;
} else {
F_29 ( V_13 , 0x70 , V_291 & 0xff ) ;
F_30 ( V_13 , 0x71 , 0x01 , ( V_291 & 0x100 ) >> 8 ) ;
}
V_48 -> V_48 [ V_291 ] = V_2 -> V_297 [ 0 ] ;
V_48 -> V_48 [ V_291 + 1 ] = V_2 -> V_297 [ 1 ] ;
memcpy ( V_2 -> V_48 . V_48 , V_48 -> V_48 , 128 * V_48 -> V_289 ) ;
V_2 -> V_48 . V_289 = V_48 -> V_289 ;
V_2 -> V_163 = F_137 ( V_48 -> V_48 [ 0x15 ] ,
V_48 -> V_48 [ 0x16 ] ) ;
V_2 -> V_48 . V_49 |= 1 << V_48 -> V_73 ;
V_20 = F_33 ( V_13 , 128 * V_48 -> V_289 , V_2 -> V_48 . V_48 ) ;
if ( V_20 < 0 ) {
F_70 ( V_13 , L_63 , V_20 , V_48 -> V_73 ) ;
return V_20 ;
}
F_30 ( V_13 , V_3 -> V_293 , 0x0f , V_2 -> V_48 . V_49 ) ;
for ( V_8 = 0 ; V_8 < 1000 ; V_8 ++ ) {
if ( F_28 ( V_13 , V_3 -> V_299 ) & V_2 -> V_48 . V_49 )
break;
F_138 ( 1 ) ;
}
if ( V_8 == 1000 ) {
F_70 ( V_13 , L_64 , V_2 -> V_48 . V_49 ) ;
return - V_270 ;
}
F_139 ( V_2 -> V_251 , V_292 , false ) ;
F_140 ( & V_2 -> V_47 , V_300 / 10 ) ;
return 0 ;
}
static int F_141 ( struct V_12 * V_13 , int V_213 ,
union V_301 * V_302 )
{
T_10 V_303 [ 32 ] ;
T_1 V_36 ;
int V_8 ;
if ( ! ( F_15 ( V_13 , 0x60 ) & V_304 [ V_213 ] . V_305 ) ) {
F_59 ( V_13 , L_65 ,
V_304 [ V_213 ] . V_306 ) ;
return - V_307 ;
}
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
V_303 [ V_8 ] = F_24 ( V_13 ,
V_304 [ V_213 ] . V_308 + V_8 ) ;
V_36 = V_303 [ 2 ] + 1 ;
if ( V_36 + 3 > sizeof( V_303 ) ) {
F_70 ( V_13 , L_66 , V_38 ,
V_304 [ V_213 ] . V_306 , V_36 ) ;
return - V_307 ;
}
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
V_303 [ V_8 + 3 ] = F_24 ( V_13 ,
V_304 [ V_213 ] . V_309 + V_8 ) ;
if ( F_142 ( V_302 , V_303 ) < 0 ) {
F_70 ( V_13 , L_67 , V_38 ,
V_304 [ V_213 ] . V_306 ) ;
return - V_307 ;
}
return 0 ;
}
static void F_143 ( struct V_12 * V_13 )
{
int V_8 ;
if ( ! F_79 ( V_13 ) ) {
F_59 ( V_13 , L_68 ) ;
return;
}
for ( V_8 = 0 ; V_8 < F_144 ( V_304 ) ; V_8 ++ ) {
union V_301 V_302 ;
struct V_17 * V_18 = F_145 ( V_13 ) ;
if ( F_141 ( V_13 , V_8 , & V_302 ) )
return;
F_146 ( V_310 , & V_18 -> V_311 , & V_302 ) ;
}
}
static int F_147 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
struct V_5 V_87 ;
struct V_151 V_152 ;
T_1 V_312 = F_15 ( V_13 , 0x02 ) ;
T_1 V_313 ;
T_1 V_81 ;
static const char * const V_314 [ 16 ] = {
L_69 , L_70 , L_71 , L_72 ,
L_71 , L_73 , L_71 , L_74 ,
L_71 , L_75 , L_76 ,
L_71 , L_71 , L_71 , L_71 , L_77
} ;
static const char * const V_315 [ 16 ] = {
L_78 , L_79 ,
L_80 , L_81 ,
L_82 , L_83 ,
L_84 , L_85 ,
L_86 , L_86 , L_86 , L_86 , L_86 ,
L_86 , L_86 , L_87
} ;
static const char * const V_316 [ 16 ] = {
L_78 , L_79 ,
L_80 , L_81 ,
L_82 , L_83 ,
L_84 , L_85 ,
L_88 , L_89 , L_90 , L_86 , L_86 ,
L_86 , L_86 , L_86
} ;
static const char * const V_317 [] = {
L_91 ,
L_78 ,
L_79 ,
} ;
static const char * const V_318 [ 4 ] = {
L_92 ,
L_93 ,
L_94 ,
L_95
} ;
F_59 ( V_13 , L_96 ) ;
F_59 ( V_13 , L_97 , F_76 ( V_13 ) ? L_98 : L_99 ) ;
V_313 = F_28 ( V_13 , V_3 -> V_299 ) ;
F_59 ( V_13 , L_100 ,
( ( V_313 & 0x01 ) ? L_101 : L_102 ) ,
( ( V_313 & 0x02 ) ? L_101 : L_102 ) ,
( ( V_313 & 0x04 ) ? L_101 : L_102 ) ,
( ( V_313 & 0x08 ) ? L_101 : L_102 ) ) ;
F_59 ( V_13 , L_103 , V_2 -> V_265 ?
L_104 : L_105 ) ;
if ( V_2 -> V_265 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_268 ; V_8 ++ ) {
bool V_271 = V_2 -> V_266 & ( 1 << V_8 ) ;
if ( V_271 )
F_59 ( V_13 , L_106 ,
V_2 -> V_272 [ V_8 ] ) ;
}
}
F_59 ( V_13 , L_107 ) ;
V_81 = V_3 -> V_82 ( V_13 ) ;
F_59 ( V_13 , L_108 ,
( ( V_81 & 0x01 ) ? L_101 : L_102 ) ,
( ( V_81 & 0x02 ) ? L_101 : L_102 ) ,
( ( V_81 & 0x04 ) ? L_101 : L_102 ) ,
( ( V_81 & 0x08 ) ? L_101 : L_102 ) ) ;
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
if ( F_90 ( V_13 , & V_152 ) )
F_59 ( V_13 , L_119 ) ;
else
F_59 ( V_13 , L_120 ,
V_152 . V_157 , V_152 . V_154 , V_152 . V_158 ,
V_152 . V_166 ? L_35 : L_36 ,
V_152 . V_159 , V_152 . V_161 ) ;
if ( F_98 ( V_13 , & V_87 ) )
F_59 ( V_13 , L_121 ) ;
else
F_100 ( V_13 -> V_201 , L_122 ,
& V_87 , true ) ;
F_100 ( V_13 -> V_201 , L_123 ,
& V_2 -> V_87 , true ) ;
if ( F_82 ( V_13 ) )
return 0 ;
F_59 ( V_13 , L_124 ) ;
F_59 ( V_13 , L_125 ,
V_317 [ V_2 -> V_125 ] ) ;
F_59 ( V_13 , L_126 ,
V_315 [ V_312 >> 4 ] ) ;
F_59 ( V_13 , L_127 ,
( V_312 & 0x02 ) ? L_128 : L_129 ,
( ( ( V_312 >> 2 ) & 0x01 ) ^ ( V_312 & 0x01 ) ) ?
L_130 : L_131 ,
( V_312 & 0x08 ) ? L_104 : L_105 ) ;
F_59 ( V_13 , L_132 ,
V_314 [ F_46 ( V_13 , V_3 -> V_319 ) >> 4 ] ) ;
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
bool V_320 = F_41 ( V_13 , 0x04 ) & 0x01 ;
bool V_321 = F_41 ( V_13 , 0x18 ) & 0x01 ;
bool V_322 = F_15 ( V_13 , 0x65 ) & 0x40 ;
F_59 ( V_13 , L_142 ,
V_320 ? L_143 : L_144 ,
V_321 ? L_145 : L_146 ,
V_322 ? L_147 : L_104 ) ;
if ( V_320 && V_321 ) {
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
F_59 ( V_13 , L_154 , V_318 [ ( F_41 ( V_13 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_59 ( V_13 , L_155 , V_316 [ F_41 ( V_13 , 0x53 ) & 0xf ] ) ;
F_143 ( V_13 ) ;
}
return 0 ;
}
static int F_148 ( struct V_12 * V_13 ,
struct V_323 * V_324 ,
struct V_325 * V_326 )
{
switch ( V_326 -> type ) {
case V_327 :
return F_149 ( V_13 , V_324 , V_326 ) ;
case V_328 :
return F_150 ( V_13 , V_324 , V_326 ) ;
default:
return - V_57 ;
}
}
static int F_151 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_17 * V_18 = F_145 ( V_13 ) ;
int V_20 ;
V_20 = F_152 ( V_2 -> V_251 , & V_18 -> V_311 ) ;
if ( V_20 )
F_153 ( V_2 -> V_251 ) ;
return V_20 ;
}
static void F_154 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_155 ( V_2 -> V_251 ) ;
}
static int F_156 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_80 * V_3 = V_2 -> V_3 ;
struct V_329 * V_229 = & V_2 -> V_229 ;
F_43 ( V_13 , 0x48 ,
( V_229 -> V_330 ? 0x80 : 0 ) |
( V_229 -> V_331 ? 0x40 : 0 ) ) ;
F_106 ( V_13 ) ;
if ( V_229 -> V_332 >= 0 &&
V_229 -> V_332 < V_2 -> V_168 ) {
V_2 -> V_65 = V_229 -> V_332 ;
F_108 ( V_13 ) ;
F_105 ( V_13 ) ;
}
F_16 ( V_13 , 0x0c , 0x42 ) ;
F_16 ( V_13 , 0x0b , 0x44 ) ;
F_48 ( V_13 , 0xcf , 0x01 ) ;
F_18 ( V_13 , 0x02 , 0x0f , V_229 -> V_333 << 3 ) ;
F_18 ( V_13 , 0x05 , 0x0e , V_229 -> V_334 << 3 |
V_229 -> V_335 << 2 |
V_229 -> V_336 << 1 ) ;
F_116 ( V_2 ) ;
F_48 ( V_13 , 0x69 , 0x30 ) ;
F_16 ( V_13 , 0x06 , 0xa0 | V_229 -> V_337 << 2 |
V_229 -> V_338 << 1 | V_229 -> V_339 ) ;
F_16 ( V_13 , 0x14 , 0x40 | V_229 -> V_340 << 4 |
V_229 -> V_341 << 2 |
V_229 -> V_342 ) ;
F_48 ( V_13 , 0xba , ( V_229 -> V_343 << 1 ) | 0x01 ) ;
F_48 ( V_13 , 0xf3 , 0xdc ) ;
F_48 ( V_13 , 0xf9 , 0x23 ) ;
F_48 ( V_13 , 0x45 , 0x23 ) ;
F_48 ( V_13 , 0xc9 , 0x2d ) ;
F_44 ( V_13 , 0x15 , 0x03 , 0x03 ) ;
F_44 ( V_13 , 0x1a , 0x0e , 0x08 ) ;
F_44 ( V_13 , 0x68 , 0x06 , 0x06 ) ;
F_27 ( V_13 , 0xb5 , 0x01 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( V_13 , 0x02 , V_229 -> V_344 ) ;
F_18 ( V_13 , 0x30 , 1 << 4 , V_229 -> V_345 << 4 ) ;
}
F_16 ( V_13 , 0x40 , 0xc0 | V_229 -> V_346 ) ;
F_16 ( V_13 , 0x46 , 0x98 ) ;
F_16 ( V_13 , 0x6e , V_3 -> V_282 ) ;
F_16 ( V_13 , 0x73 , V_3 -> V_284 ) ;
V_3 -> V_347 ( V_13 ) ;
return F_157 ( V_13 -> V_348 ) ;
}
static void F_158 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd7 ) ;
}
static void F_159 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd0 ) ;
}
static void F_160 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd0 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 1 ; V_8 < F_144 ( V_2 -> V_19 ) ; ++ V_8 ) {
if ( V_2 -> V_19 [ V_8 ] )
F_162 ( V_2 -> V_19 [ V_8 ] ) ;
}
}
static struct V_17 * F_163 ( struct V_12 * V_13 ,
T_1 V_23 , T_1 V_349 )
{
struct V_17 * V_18 = F_145 ( V_13 ) ;
if ( V_23 )
F_16 ( V_13 , V_349 , V_23 << 1 ) ;
return F_164 ( V_18 -> V_350 , F_15 ( V_13 , V_349 ) >> 1 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_351 V_352 ;
struct V_353 * V_354 ;
struct V_353 * V_355 ;
unsigned int V_127 ;
int V_77 ;
T_4 V_356 ;
V_355 = V_2 -> V_19 [ V_27 ] -> V_311 . V_357 ;
V_354 = F_166 ( V_355 , NULL ) ;
if ( ! V_354 )
return - V_57 ;
V_77 = F_167 ( F_168 ( V_354 ) , & V_352 ) ;
if ( V_77 ) {
F_169 ( V_354 ) ;
return V_77 ;
}
F_169 ( V_354 ) ;
if ( ! F_170 ( V_355 , L_156 , & V_356 ) )
V_2 -> V_229 . V_332 = V_356 ;
else
V_2 -> V_229 . V_332 = - 1 ;
V_127 = V_352 . V_358 . V_359 . V_127 ;
if ( V_127 & V_360 )
V_2 -> V_229 . V_338 = 1 ;
if ( V_127 & V_361 )
V_2 -> V_229 . V_337 = 1 ;
if ( V_127 & V_362 )
V_2 -> V_229 . V_339 = 1 ;
if ( V_352 . V_363 == V_364 )
V_2 -> V_229 . V_335 = 1 ;
V_2 -> V_229 . V_346 = V_365 ;
V_2 -> V_229 . V_366 [ V_29 ] = 0x42 ;
V_2 -> V_229 . V_366 [ V_30 ] = 0x40 ;
V_2 -> V_229 . V_366 [ V_31 ] = 0x3e ;
V_2 -> V_229 . V_366 [ V_367 ] = 0x38 ;
V_2 -> V_229 . V_366 [ V_368 ] = 0x3c ;
V_2 -> V_229 . V_366 [ V_32 ] = 0x26 ;
V_2 -> V_229 . V_366 [ V_33 ] = 0x32 ;
V_2 -> V_229 . V_366 [ V_34 ] = 0x36 ;
V_2 -> V_229 . V_366 [ V_50 ] = 0x34 ;
V_2 -> V_229 . V_366 [ V_51 ] = 0x30 ;
V_2 -> V_229 . V_366 [ V_52 ] = 0x22 ;
V_2 -> V_229 . V_366 [ V_53 ] = 0x24 ;
V_2 -> V_229 . V_330 = 0 ;
V_2 -> V_229 . V_331 = 0 ;
V_2 -> V_229 . V_334 = 1 ;
V_2 -> V_229 . V_234 = V_369 ;
V_2 -> V_229 . V_230 = V_370 ;
V_2 -> V_229 . V_340 = V_371 ;
V_2 -> V_229 . V_341 = V_371 ;
V_2 -> V_229 . V_342 = V_371 ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , int V_372 )
{
int V_20 ;
if ( ! V_2 -> V_19 [ V_372 ] )
return - V_373 ;
V_2 -> V_22 [ V_372 ] =
F_172 ( V_2 -> V_19 [ V_372 ] ,
& V_374 [ V_372 ] ) ;
if ( F_173 ( V_2 -> V_22 [ V_372 ] ) ) {
V_20 = F_174 ( V_2 -> V_22 [ V_372 ] ) ;
F_12 ( V_2 -> V_19 [ V_372 ] ,
L_157 ,
V_372 , V_20 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_8 , V_20 ;
for ( V_8 = V_29 ; V_8 < V_55 ; V_8 ++ ) {
V_20 = F_171 ( V_2 , V_8 ) ;
if ( V_20 && ( V_20 != - V_373 ) )
return V_20 ;
}
return 0 ;
}
static void F_176 ( struct V_1 * V_2 )
{
if ( V_2 -> V_375 ) {
F_36 ( V_2 -> V_375 , 0 ) ;
F_177 ( 5000 , 10000 ) ;
F_36 ( V_2 -> V_375 , 1 ) ;
F_177 ( 5000 , 10000 ) ;
}
}
static int F_178 ( struct V_17 * V_18 ,
const struct V_376 * V_134 )
{
static const struct V_5 V_377 =
V_378 ;
struct V_1 * V_2 ;
struct V_379 * V_7 ;
struct V_131 * V_132 ;
struct V_12 * V_13 ;
unsigned int V_8 ;
unsigned int V_21 , V_380 ;
int V_20 ;
if ( ! F_179 ( V_18 -> V_350 , V_381 ) )
return - V_270 ;
F_180 ( 1 , V_37 , V_18 , L_158 ,
V_18 -> V_23 << 1 ) ;
V_2 = F_181 ( & V_18 -> V_311 , sizeof( * V_2 ) , V_382 ) ;
if ( ! V_2 ) {
F_12 ( V_18 , L_159 ) ;
return - V_383 ;
}
V_2 -> V_19 [ V_27 ] = V_18 ;
V_2 -> V_174 = true ;
V_2 -> V_65 = ~ 0 ;
if ( F_131 ( V_384 ) && V_18 -> V_311 . V_357 ) {
const struct V_385 * V_386 ;
V_386 = F_182 ( V_387 , V_18 -> V_311 . V_357 ) ;
V_2 -> V_3 = V_386 -> V_286 ;
V_20 = F_165 ( V_2 ) ;
if ( V_20 < 0 ) {
F_12 ( V_18 , L_160 ) ;
return V_20 ;
}
} else if ( V_18 -> V_311 . V_388 ) {
struct V_329 * V_229 = V_18 -> V_311 . V_388 ;
V_2 -> V_3 = ( const struct V_80 * ) V_134 -> V_389 ;
V_2 -> V_229 = * V_229 ;
} else {
F_12 ( V_18 , L_161 ) ;
return - V_373 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_40 ; ++ V_8 ) {
V_2 -> V_41 [ V_8 ] =
F_183 ( & V_18 -> V_311 , L_162 , V_8 ,
V_390 ) ;
if ( F_173 ( V_2 -> V_41 [ V_8 ] ) )
return F_174 ( V_2 -> V_41 [ V_8 ] ) ;
if ( V_2 -> V_41 [ V_8 ] )
F_184 ( V_18 , L_163 , V_8 ) ;
}
V_2 -> V_375 = F_185 ( & V_18 -> V_311 , L_164 ,
V_391 ) ;
if ( F_173 ( V_2 -> V_375 ) )
return F_174 ( V_2 -> V_375 ) ;
F_176 ( V_2 ) ;
V_2 -> V_87 = V_377 ;
V_2 -> V_215 = V_61 ( V_2 , V_249 ) ;
V_13 = & V_2 -> V_13 ;
F_186 ( V_13 , V_18 , & V_392 ) ;
snprintf ( V_13 -> V_201 , sizeof( V_13 -> V_201 ) , L_165 ,
V_134 -> V_201 , F_187 ( V_18 -> V_350 ) ,
V_18 -> V_23 ) ;
V_13 -> V_127 |= V_393 | V_394 ;
V_13 -> V_395 = & V_396 ;
V_20 = F_171 ( V_2 , V_27 ) ;
if ( V_20 ) {
F_70 ( V_13 , L_166 ) ;
return - V_373 ;
}
switch ( V_2 -> V_3 -> type ) {
case V_298 :
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] , 0xfb , & V_21 ) ;
if ( V_20 ) {
F_70 ( V_13 , L_167 , V_20 ) ;
return - V_373 ;
}
if ( V_21 != 0x68 ) {
F_70 ( V_13 , L_168 ,
V_18 -> V_23 << 1 ) ;
return - V_373 ;
}
break;
case V_397 :
case V_398 :
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] ,
0xea ,
& V_21 ) ;
if ( V_20 ) {
F_70 ( V_13 , L_167 , V_20 ) ;
return - V_373 ;
}
V_380 = V_21 << 8 ;
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] ,
0xeb ,
& V_21 ) ;
if ( V_20 ) {
F_70 ( V_13 , L_167 , V_20 ) ;
return - V_373 ;
}
V_21 |= V_380 ;
if ( ( V_2 -> V_3 -> type == V_397 && V_21 != 0x2051 ) ||
( V_2 -> V_3 -> type == V_398 && V_21 != 0x2041 ) ) {
F_70 ( V_13 , L_169 ,
V_18 -> V_23 << 1 ) ;
return - V_373 ;
}
break;
}
V_7 = & V_2 -> V_7 ;
F_188 ( V_7 , F_1 ( V_2 ) ? 9 : 8 ) ;
F_189 ( V_7 , & V_399 ,
V_135 , - 128 , 127 , 1 , 0 ) ;
F_189 ( V_7 , & V_399 ,
V_136 , 0 , 255 , 1 , 128 ) ;
F_189 ( V_7 , & V_399 ,
V_137 , 0 , 255 , 1 , 128 ) ;
F_189 ( V_7 , & V_399 ,
V_138 , 0 , 128 , 1 , 0 ) ;
V_132 = F_190 ( V_7 , & V_399 ,
V_143 , V_144 ,
0 , V_144 ) ;
if ( V_132 )
V_132 -> V_127 |= V_400 ;
V_2 -> V_83 = F_189 ( V_7 , NULL ,
V_401 , 0 ,
( 1 << V_2 -> V_3 -> V_40 ) - 1 , 0 , 0 ) ;
V_2 -> V_402 =
F_190 ( V_7 , & V_399 ,
V_139 , V_130 ,
0 , V_126 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_403 =
F_191 ( V_7 , & V_404 , NULL ) ;
V_2 -> V_405 =
F_191 ( V_7 , & V_406 , NULL ) ;
V_2 -> V_407 =
F_191 ( V_7 , & V_408 , NULL ) ;
V_13 -> V_348 = V_7 ;
if ( V_7 -> error ) {
V_20 = V_7 -> error ;
goto V_409;
}
if ( F_65 ( V_13 ) ) {
V_20 = - V_373 ;
goto V_409;
}
for ( V_8 = 1 ; V_8 < V_55 ; ++ V_8 ) {
if ( ! ( F_37 ( V_8 ) & V_2 -> V_3 -> V_56 ) )
continue;
V_2 -> V_19 [ V_8 ] =
F_163 ( V_13 , V_2 -> V_229 . V_366 [ V_8 ] ,
0xf2 + V_8 ) ;
if ( V_2 -> V_19 [ V_8 ] == NULL ) {
V_20 = - V_383 ;
F_70 ( V_13 , L_170 , V_8 ) ;
goto V_410;
}
}
F_192 ( & V_2 -> V_47 ,
F_39 ) ;
V_2 -> V_168 = V_2 -> V_3 -> V_40
+ ( V_2 -> V_3 -> V_4 ? 2 : 0 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_168 ; ++ V_8 )
V_2 -> V_411 [ V_8 ] . V_127 = V_412 ;
V_2 -> V_411 [ V_2 -> V_168 ] . V_127 = V_413 ;
V_20 = F_193 ( & V_13 -> V_414 , V_2 -> V_168 + 1 ,
V_2 -> V_411 ) ;
if ( V_20 )
goto V_415;
V_20 = F_175 ( V_2 ) ;
if ( V_20 )
goto V_416;
V_20 = F_156 ( V_13 ) ;
if ( V_20 )
goto V_416;
#if F_131 ( V_283 )
V_2 -> V_251 = F_194 ( & V_417 ,
V_2 , F_195 ( & V_18 -> V_311 ) ,
V_418 , V_268 ) ;
V_20 = F_196 ( V_2 -> V_251 ) ;
if ( V_20 )
goto V_416;
#endif
F_59 ( V_13 , L_171 , V_18 -> V_201 ,
V_18 -> V_23 << 1 , V_18 -> V_350 -> V_201 ) ;
V_20 = F_197 ( V_13 ) ;
if ( V_20 )
goto V_416;
return 0 ;
V_416:
F_198 ( & V_13 -> V_414 ) ;
V_415:
F_199 ( & V_2 -> V_47 ) ;
V_410:
F_161 ( V_2 ) ;
V_409:
F_200 ( V_7 ) ;
return V_20 ;
}
static int F_201 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_202 ( V_18 ) ;
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_16 ( V_13 , 0x40 , 0 ) ;
F_16 ( V_13 , 0x41 , 0 ) ;
F_16 ( V_13 , 0x46 , 0 ) ;
F_16 ( V_13 , 0x6e , 0 ) ;
F_16 ( V_13 , 0x73 , 0 ) ;
F_199 ( & V_2 -> V_47 ) ;
F_203 ( V_13 ) ;
F_198 ( & V_13 -> V_414 ) ;
F_161 ( F_4 ( V_13 ) ) ;
F_200 ( V_13 -> V_348 ) ;
return 0 ;
}
