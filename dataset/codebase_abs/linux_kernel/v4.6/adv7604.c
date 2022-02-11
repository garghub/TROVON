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
static inline int F_18 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 , T_1 V_21 )
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
static inline int F_23 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_31 , V_16 ) ;
}
static inline int F_24 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_31 ] , V_16 , V_21 ) ;
}
static inline int F_25 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_32 , V_16 ) ;
}
static inline int F_26 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_32 ] , V_16 , V_21 ) ;
}
static inline int F_27 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_33 , V_16 ) ;
}
static inline int F_28 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_33 ] , V_16 , V_21 ) ;
}
static inline int F_29 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 , T_1 V_21 )
{
return F_28 ( V_13 , V_16 , ( F_27 ( V_13 , V_16 ) & ~ V_28 ) | V_21 ) ;
}
static inline int F_30 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_34 , V_16 ) ;
}
static inline int F_31 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_34 ] , V_16 , V_21 ) ;
}
static inline int F_32 ( struct V_12 * V_13 ,
unsigned int V_35 , const T_1 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_20 = 0 ;
int V_8 = 0 ;
int V_36 = 0 ;
F_33 ( 2 , V_37 , V_13 , L_2 ,
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
static void F_34 ( struct V_1 * V_2 , unsigned int V_39 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_40 ; ++ V_8 )
F_35 ( V_2 -> V_41 [ V_8 ] , V_39 & F_36 ( V_8 ) ) ;
F_37 ( & V_2 -> V_13 , V_42 , & V_39 ) ;
}
static void F_38 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_39 ( V_44 ) ;
struct V_1 * V_2 = F_5 ( V_46 , struct V_1 ,
V_47 ) ;
struct V_12 * V_13 = & V_2 -> V_13 ;
F_33 ( 2 , V_37 , V_13 , L_3 , V_38 ) ;
F_34 ( V_2 , V_2 -> V_48 . V_49 ) ;
}
static inline int F_40 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_50 , V_16 ) ;
}
static T_3 F_41 ( struct V_12 * V_13 , T_1 V_16 , T_3 V_28 )
{
return ( ( F_40 ( V_13 , V_16 ) << 8 ) | F_40 ( V_13 , V_16 + 1 ) ) & V_28 ;
}
static inline int F_42 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_50 ] , V_16 , V_21 ) ;
}
static inline int F_43 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 , T_1 V_21 )
{
return F_42 ( V_13 , V_16 , ( F_40 ( V_13 , V_16 ) & ~ V_28 ) | V_21 ) ;
}
static inline int F_44 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_51 ] , V_16 , V_21 ) ;
}
static inline int F_45 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_52 , V_16 ) ;
}
static T_3 F_46 ( struct V_12 * V_13 , T_1 V_16 , T_3 V_28 )
{
return ( ( F_45 ( V_13 , V_16 ) << 8 ) | F_45 ( V_13 , V_16 + 1 ) ) & V_28 ;
}
static inline int F_47 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_52 ] , V_16 , V_21 ) ;
}
static inline int F_48 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_28 , T_1 V_21 )
{
return F_47 ( V_13 , V_16 , ( F_45 ( V_13 , V_16 ) & ~ V_28 ) | V_21 ) ;
}
static inline int F_49 ( struct V_12 * V_13 , T_1 V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_10 ( V_2 , V_53 , V_16 ) ;
}
static inline int F_50 ( struct V_12 * V_13 , T_1 V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return F_17 ( V_2 -> V_22 [ V_53 ] , V_16 , V_21 ) ;
}
static int F_51 ( struct V_12 * V_13 , unsigned int V_16 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
unsigned int V_54 = V_16 >> 8 ;
unsigned int V_21 ;
int V_20 ;
if ( ! ( F_36 ( V_54 ) & V_2 -> V_3 -> V_55 ) )
return - V_56 ;
V_16 &= 0xff ;
V_20 = F_11 ( V_2 -> V_22 [ V_54 ] , V_16 , & V_21 ) ;
return V_20 ? V_20 : V_21 ;
}
static int F_52 ( struct V_12 * V_13 , unsigned int V_16 , T_1 V_21 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
unsigned int V_54 = V_16 >> 8 ;
if ( ! ( F_36 ( V_54 ) & V_2 -> V_3 -> V_55 ) )
return - V_56 ;
V_16 &= 0xff ;
return F_17 ( V_2 -> V_22 [ V_54 ] , V_16 , V_21 ) ;
}
static void F_53 ( struct V_12 * V_13 ,
const struct V_57 * V_58 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_58 [ V_8 ] . V_16 != V_59 ; V_8 ++ )
F_52 ( V_13 , V_58 [ V_8 ] . V_16 , V_58 [ V_8 ] . V_21 ) ;
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
static inline bool F_54 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return V_2 -> V_64 == V_65 ||
V_2 -> V_64 == V_66 ;
}
static inline bool F_55 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return V_2 -> V_64 == V_67 ||
V_2 -> V_64 == V_68 ||
V_2 -> V_64 == V_69 ||
V_2 -> V_64 == V_70 ;
}
static inline const struct V_71 *
F_56 ( struct V_12 * V_13 )
{
return F_55 ( V_13 ) ? & V_72 :
& V_73 ;
}
static void F_57 ( struct V_12 * V_13 )
{
F_58 ( V_13 , L_4 ) ;
F_58 ( V_13 , L_5 ) ;
F_58 ( V_13 , L_6 ) ;
F_58 ( V_13 , L_7 ) ;
F_58 ( V_13 , L_8 ) ;
F_58 ( V_13 , L_9 ) ;
F_58 ( V_13 , L_10 ) ;
F_58 ( V_13 , L_11 ) ;
F_58 ( V_13 , L_12 ) ;
F_58 ( V_13 , L_13 ) ;
F_58 ( V_13 , L_14 ) ;
F_58 ( V_13 , L_15 ) ;
F_58 ( V_13 , L_16 ) ;
}
static int F_59 ( struct V_12 * V_13 ,
struct V_74 * V_16 )
{
int V_75 ;
V_75 = F_51 ( V_13 , V_16 -> V_16 ) ;
if ( V_75 < 0 ) {
F_58 ( V_13 , L_17 , V_16 -> V_16 ) ;
F_57 ( V_13 ) ;
return V_75 ;
}
V_16 -> V_76 = 1 ;
V_16 -> V_21 = V_75 ;
return 0 ;
}
static int F_60 ( struct V_12 * V_13 ,
const struct V_74 * V_16 )
{
int V_75 ;
V_75 = F_52 ( V_13 , V_16 -> V_16 , V_16 -> V_21 ) ;
if ( V_75 < 0 ) {
F_58 ( V_13 , L_17 , V_16 -> V_16 ) ;
F_57 ( V_13 ) ;
return V_75 ;
}
return 0 ;
}
static unsigned int F_61 ( struct V_12 * V_13 )
{
T_1 V_77 = F_15 ( V_13 , 0x6f ) ;
return ( ( V_77 & 0x10 ) >> 4 )
| ( ( V_77 & 0x08 ) >> 2 )
| ( ( V_77 & 0x04 ) << 0 )
| ( ( V_77 & 0x02 ) << 2 ) ;
}
static unsigned int F_62 ( struct V_12 * V_13 )
{
T_1 V_77 = F_15 ( V_13 , 0x6f ) ;
return V_77 & 1 ;
}
static unsigned int F_63 ( struct V_12 * V_13 )
{
T_1 V_77 = F_15 ( V_13 , 0x6f ) ;
return V_77 & 1 ;
}
static int F_64 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
return F_65 ( V_2 -> V_79 ,
V_3 -> V_80 ( V_13 ) ) ;
}
static int F_66 ( struct V_12 * V_13 ,
T_1 V_81 ,
const struct V_82 * V_83 ,
const struct V_5 * V_84 )
{
int V_8 ;
for ( V_8 = 0 ; V_83 [ V_8 ] . V_84 . V_10 . V_11 ; V_8 ++ ) {
if ( ! F_3 ( V_84 , & V_83 [ V_8 ] . V_84 ,
F_55 ( V_13 ) ? 250000 : 1000000 , false ) )
continue;
F_16 ( V_13 , 0x00 , V_83 [ V_8 ] . V_85 ) ;
F_16 ( V_13 , 0x01 , ( V_83 [ V_8 ] . V_86 << 4 ) +
V_81 ) ;
return 0 ;
}
return - 1 ;
}
static int F_67 ( struct V_12 * V_13 ,
struct V_5 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_20 ;
F_33 ( 1 , V_37 , V_13 , L_18 , V_38 ) ;
if ( F_1 ( V_2 ) ) {
F_16 ( V_13 , 0x16 , 0x43 ) ;
F_16 ( V_13 , 0x17 , 0x5a ) ;
}
F_48 ( V_13 , 0x81 , 0x10 , 0x00 ) ;
F_47 ( V_13 , 0x8f , 0x00 ) ;
F_47 ( V_13 , 0x90 , 0x00 ) ;
F_47 ( V_13 , 0xa2 , 0x00 ) ;
F_47 ( V_13 , 0xa3 , 0x00 ) ;
F_47 ( V_13 , 0xa4 , 0x00 ) ;
F_47 ( V_13 , 0xa5 , 0x00 ) ;
F_47 ( V_13 , 0xa6 , 0x00 ) ;
F_47 ( V_13 , 0xa7 , 0x00 ) ;
F_47 ( V_13 , 0xab , 0x00 ) ;
F_47 ( V_13 , 0xac , 0x00 ) ;
if ( F_54 ( V_13 ) ) {
V_20 = F_66 ( V_13 ,
0x01 , V_87 , V_84 ) ;
if ( V_20 )
V_20 = F_66 ( V_13 ,
0x02 , V_88 , V_84 ) ;
} else if ( F_55 ( V_13 ) ) {
V_20 = F_66 ( V_13 ,
0x05 , V_89 , V_84 ) ;
if ( V_20 )
V_20 = F_66 ( V_13 ,
0x06 , V_90 , V_84 ) ;
} else {
F_33 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_64 ) ;
V_20 = - 1 ;
}
return V_20 ;
}
static void F_68 ( struct V_12 * V_13 ,
const struct V_14 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_4 V_11 = F_6 ( V_10 ) ;
T_4 V_91 = F_8 ( V_10 ) ;
T_3 V_92 = V_10 -> V_93 + V_10 -> V_94 - 4 ;
T_3 V_95 = V_11 - V_10 -> V_96 ;
T_3 V_97 = V_91 - V_10 -> V_98 ;
T_3 V_99 = V_10 -> V_100 + V_10 -> V_101 ;
T_3 V_102 = ( ( ( T_4 ) V_10 -> V_103 / 100 ) > 0 ) ?
( ( V_11 * ( V_104 / 100 ) ) / ( ( T_4 ) V_10 -> V_103 / 100 ) ) : 0 ;
const T_1 V_105 [ 2 ] = {
0xc0 | ( ( V_11 >> 8 ) & 0x1f ) ,
V_11 & 0xff
} ;
F_33 ( 2 , V_37 , V_13 , L_20 , V_38 ) ;
if ( F_54 ( V_13 ) ) {
F_16 ( V_13 , 0x00 , 0x07 ) ;
F_16 ( V_13 , 0x01 , 0x02 ) ;
F_48 ( V_13 , 0x81 , 0x10 , 0x10 ) ;
if ( F_14 ( V_2 -> V_22 [ V_27 ] ,
0x16 , V_105 , 2 ) )
F_69 ( V_13 , L_21 ) ;
F_47 ( V_13 , 0xa2 , ( V_92 >> 4 ) & 0xff ) ;
F_47 ( V_13 , 0xa3 , ( ( V_92 & 0x0f ) << 4 ) |
( ( V_95 >> 8 ) & 0x0f ) ) ;
F_47 ( V_13 , 0xa4 , V_95 & 0xff ) ;
F_47 ( V_13 , 0xa5 , ( V_97 >> 4 ) & 0xff ) ;
F_47 ( V_13 , 0xa6 , ( ( V_97 & 0xf ) << 4 ) |
( ( V_99 >> 8 ) & 0xf ) ) ;
F_47 ( V_13 , 0xa7 , V_99 & 0xff ) ;
} else if ( F_55 ( V_13 ) ) {
F_16 ( V_13 , 0x00 , 0x02 ) ;
F_16 ( V_13 , 0x01 , 0x06 ) ;
} else {
F_33 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_64 ) ;
}
F_47 ( V_13 , 0x8f , ( V_102 >> 8 ) & 0x7 ) ;
F_47 ( V_13 , 0x90 , V_102 & 0xff ) ;
F_47 ( V_13 , 0xab , ( V_91 >> 4 ) & 0xff ) ;
F_47 ( V_13 , 0xac , ( V_91 & 0x0f ) << 4 ) ;
}
static void F_70 ( struct V_12 * V_13 , bool V_106 , T_3 V_107 , T_3 V_108 , T_3 V_109 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_110 [ 4 ] ;
if ( V_106 ) {
V_107 = 0x3ff ;
V_108 = 0x3ff ;
V_109 = 0x3ff ;
}
F_33 ( 2 , V_37 , V_13 , L_22 ,
V_38 , V_106 ? L_23 : L_24 ,
V_107 , V_108 , V_109 ) ;
V_110 [ 0 ] = ( F_45 ( V_13 , 0x77 ) & 0xc0 ) | ( ( V_107 & 0x3f0 ) >> 4 ) ;
V_110 [ 1 ] = ( ( V_107 & 0x00f ) << 4 ) | ( ( V_108 & 0x3c0 ) >> 6 ) ;
V_110 [ 2 ] = ( ( V_108 & 0x03f ) << 2 ) | ( ( V_109 & 0x300 ) >> 8 ) ;
V_110 [ 3 ] = V_109 & 0x0ff ;
if ( F_14 ( V_2 -> V_22 [ V_52 ] ,
0x77 , V_110 , 4 ) )
F_69 ( V_13 , L_25 , V_38 ) ;
}
static void F_71 ( struct V_12 * V_13 , bool V_111 , T_3 V_112 , T_3 V_113 , T_3 V_114 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_115 [ 4 ] ;
T_1 V_116 = 1 ;
T_1 V_117 = 1 ;
if ( V_111 ) {
V_116 = 0 ;
V_117 = 0 ;
V_112 = 0x100 ;
V_113 = 0x100 ;
V_114 = 0x100 ;
}
F_33 ( 2 , V_37 , V_13 , L_26 ,
V_38 , V_111 ? L_23 : L_24 ,
V_112 , V_113 , V_114 ) ;
V_115 [ 0 ] = ( ( V_116 << 7 ) | ( V_117 << 6 ) | ( ( V_112 & 0x3f0 ) >> 4 ) ) ;
V_115 [ 1 ] = ( ( ( V_112 & 0x00f ) << 4 ) | ( ( V_113 & 0x3c0 ) >> 6 ) ) ;
V_115 [ 2 ] = ( ( ( V_113 & 0x03f ) << 2 ) | ( ( V_114 & 0x300 ) >> 8 ) ) ;
V_115 [ 3 ] = ( ( V_114 & 0x0ff ) ) ;
if ( F_14 ( V_2 -> V_22 [ V_52 ] ,
0x73 , V_115 , 4 ) )
F_69 ( V_13 , L_27 , V_38 ) ;
}
static void F_72 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
bool V_118 = F_15 ( V_13 , 0x02 ) & 0x02 ;
bool V_119 = F_40 ( V_13 , 0x05 ) & 0x80 ;
F_33 ( 2 , V_37 , V_13 , L_28 ,
V_38 , V_2 -> V_120 ,
V_118 , V_119 ) ;
F_71 ( V_13 , true , 0x0 , 0x0 , 0x0 ) ;
F_70 ( V_13 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_2 -> V_120 ) {
case V_121 :
if ( V_2 -> V_64 == V_65 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
break;
}
if ( V_2 -> V_64 == V_66 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_119 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_2 -> V_84 . V_10 . V_122 & V_123 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x00 ) ;
} else {
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_55 ( V_13 ) && V_118 ) {
F_70 ( V_13 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_71 ( V_13 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_70 ( V_13 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_124 :
if ( V_2 -> V_64 == V_66 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x20 ) ;
break;
}
F_18 ( V_13 , 0x02 , 0xf0 , 0x00 ) ;
break;
case V_125 :
if ( V_2 -> V_64 == V_66 ) {
F_18 ( V_13 , 0x02 , 0xf0 , 0x60 ) ;
break;
}
F_18 ( V_13 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_54 ( V_13 ) || V_119 )
break;
if ( V_118 ) {
F_70 ( V_13 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_71 ( V_13 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_70 ( V_13 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_73 ( struct V_126 * V_127 )
{
struct V_12 * V_13 =
& F_5 ( V_127 -> V_128 , struct V_1 , V_7 ) -> V_13 ;
struct V_1 * V_2 = F_4 ( V_13 ) ;
switch ( V_127 -> V_129 ) {
case V_130 :
F_47 ( V_13 , 0x3c , V_127 -> V_21 ) ;
return 0 ;
case V_131 :
F_47 ( V_13 , 0x3a , V_127 -> V_21 ) ;
return 0 ;
case V_132 :
F_47 ( V_13 , 0x3b , V_127 -> V_21 ) ;
return 0 ;
case V_133 :
F_47 ( V_13 , 0x3d , V_127 -> V_21 ) ;
return 0 ;
case V_134 :
V_2 -> V_120 = V_127 -> V_21 ;
F_72 ( V_13 ) ;
return 0 ;
case V_135 :
if ( ! F_1 ( V_2 ) )
return - V_56 ;
F_26 ( V_13 , 0xc8 , V_127 -> V_21 ) ;
return 0 ;
case V_136 :
F_48 ( V_13 , 0xbf , 0x04 , V_127 -> V_21 << 2 ) ;
return 0 ;
case V_137 :
F_47 ( V_13 , 0xc0 , ( V_127 -> V_21 & 0xff0000 ) >> 16 ) ;
F_47 ( V_13 , 0xc1 , ( V_127 -> V_21 & 0x00ff00 ) >> 8 ) ;
F_47 ( V_13 , 0xc2 , ( T_1 ) ( V_127 -> V_21 & 0x0000ff ) ) ;
return 0 ;
}
return - V_56 ;
}
static int F_74 ( struct V_126 * V_127 )
{
struct V_12 * V_13 =
& F_5 ( V_127 -> V_128 , struct V_1 , V_7 ) -> V_13 ;
if ( V_127 -> V_129 == V_138 ) {
V_127 -> V_21 = V_139 ;
if ( ( F_15 ( V_13 , 0x60 ) & 1 ) && ( F_23 ( V_13 , 0x03 ) & 0x80 ) )
V_127 -> V_21 = ( F_23 ( V_13 , 0x05 ) >> 4 ) & 3 ;
return 0 ;
}
return - V_56 ;
}
static inline bool F_75 ( struct V_12 * V_13 )
{
return F_15 ( V_13 , 0x0c ) & 0x24 ;
}
static inline bool F_76 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
return ! ( F_15 ( V_13 , 0x6a ) & ( 0x10 >> V_2 -> V_64 ) ) ;
}
static inline bool F_77 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
return ( F_15 ( V_13 , 0x6a ) & V_3 -> V_140 ) != V_3 -> V_140 ;
}
static inline bool F_78 ( struct V_12 * V_13 )
{
return F_40 ( V_13 , 0x05 ) & 0x80 ;
}
static inline bool F_79 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( F_1 ( V_2 ) )
return false ;
return ( ( F_45 ( V_13 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_80 ( struct V_12 * V_13 )
{
return ! ( F_45 ( V_13 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_81 ( struct V_12 * V_13 )
{
bool V_75 ;
V_75 = F_75 ( V_13 ) ;
V_75 |= F_80 ( V_13 ) ;
V_75 |= F_79 ( V_13 ) ;
if ( F_55 ( V_13 ) ) {
V_75 |= F_77 ( V_13 ) ;
V_75 |= F_76 ( V_13 ) ;
}
return V_75 ;
}
static inline bool F_82 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( ! F_1 ( V_2 ) )
return false ;
return F_15 ( V_13 , 0x12 ) & 0x01 ;
}
static inline bool F_83 ( struct V_12 * V_13 )
{
return F_45 ( V_13 , 0xff ) & 0x10 ;
}
static int F_84 ( struct V_12 * V_13 , T_4 * V_141 )
{
* V_141 = 0 ;
* V_141 |= F_75 ( V_13 ) ? V_142 : 0 ;
* V_141 |= F_81 ( V_13 ) ? V_143 : 0 ;
if ( ! F_83 ( V_13 ) && F_82 ( V_13 ) )
* V_141 |= F_55 ( V_13 ) ?
V_144 : V_145 ;
F_33 ( 1 , V_37 , V_13 , L_29 , V_38 , * V_141 ) ;
return 0 ;
}
static int F_85 ( struct V_12 * V_13 ,
struct V_146 * V_147 ,
struct V_5 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_4 V_148 = ( V_104 * 8 ) / V_147 -> V_149 ;
T_4 V_150 ;
int V_8 ;
for ( V_8 = 0 ; V_151 [ V_8 ] . V_10 . V_11 ; V_8 ++ ) {
const struct V_14 * V_10 = & V_151 [ V_8 ] . V_10 ;
if ( ! F_86 ( & V_151 [ V_8 ] ,
F_56 ( V_13 ) ,
F_2 , NULL ) )
continue;
if ( F_8 ( V_10 ) != V_147 -> V_152 + 1 )
continue;
if ( V_10 -> V_100 != V_147 -> V_153 )
continue;
V_150 = V_148 * F_6 ( V_10 ) ;
if ( ( V_150 < V_10 -> V_103 + 1000000 ) &&
( V_150 > V_10 -> V_103 - 1000000 ) ) {
* V_84 = V_151 [ V_8 ] ;
return 0 ;
}
}
if ( F_87 ( V_147 -> V_152 + 1 , V_148 , V_147 -> V_153 , 0 ,
( V_147 -> V_154 == '+' ? V_155 : 0 ) |
( V_147 -> V_156 == '+' ? V_157 : 0 ) ,
false , V_84 ) )
return 0 ;
if ( F_88 ( V_147 -> V_152 + 1 , V_148 , V_147 -> V_153 ,
( V_147 -> V_154 == '+' ? V_155 : 0 ) |
( V_147 -> V_156 == '+' ? V_157 : 0 ) ,
false , V_2 -> V_158 , V_84 ) )
return 0 ;
F_33 ( 2 , V_37 , V_13 ,
L_30 ,
V_38 , V_147 -> V_153 , V_147 -> V_152 , V_147 -> V_149 ,
V_147 -> V_154 , V_147 -> V_156 ) ;
return - 1 ;
}
static int F_89 ( struct V_12 * V_13 , struct V_146 * V_147 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
T_1 V_159 ;
if ( F_80 ( V_13 ) || F_79 ( V_13 ) ) {
F_33 ( 2 , V_37 , V_13 , L_31 , V_38 ) ;
return - 1 ;
}
V_147 -> V_149 = F_46 ( V_13 , 0xb1 , 0x3fff ) ;
V_147 -> V_152 = F_46 ( V_13 , V_3 -> V_160 , 0x7ff ) ;
V_147 -> V_153 = F_45 ( V_13 , 0xb3 ) >> 3 ;
V_147 -> V_161 = F_15 ( V_13 , 0x12 ) & 0x10 ;
if ( F_1 ( V_2 ) ) {
V_159 = F_45 ( V_13 , 0xb5 ) ;
if ( ( V_159 & 0x03 ) == 0x01 ) {
V_147 -> V_154 = V_159 & 0x10
? ( V_159 & 0x08 ? '+' : '-' ) : 'x' ;
V_147 -> V_156 = V_159 & 0x40
? ( V_159 & 0x20 ? '+' : '-' ) : 'x' ;
} else {
V_147 -> V_154 = 'x' ;
V_147 -> V_156 = 'x' ;
}
} else {
V_159 = F_40 ( V_13 , 0x05 ) ;
V_147 -> V_154 = V_159 & 0x20 ? '+' : '-' ;
V_147 -> V_156 = V_159 & 0x10 ? '+' : '-' ;
}
if ( F_80 ( V_13 ) || F_79 ( V_13 ) ) {
F_33 ( 2 , V_37 , V_13 ,
L_32 , V_38 ) ;
return - 1 ;
}
if ( V_147 -> V_152 < 239 || V_147 -> V_149 < 8 || V_147 -> V_149 == 0x3fff ) {
F_33 ( 2 , V_37 , V_13 , L_33 , V_38 ) ;
memset ( V_147 , 0 , sizeof( struct V_146 ) ) ;
return - 1 ;
}
F_33 ( 2 , V_37 , V_13 ,
L_34 ,
V_38 , V_147 -> V_152 , V_147 -> V_149 , V_147 -> V_153 ,
V_147 -> V_154 , V_147 -> V_156 ,
V_147 -> V_161 ? L_35 : L_36 ) ;
return 0 ;
}
static int F_90 ( struct V_12 * V_13 ,
struct V_162 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_84 -> V_163 >= V_2 -> V_164 )
return - V_56 ;
return F_91 ( V_84 ,
F_56 ( V_13 ) , F_2 , NULL ) ;
}
static int F_92 ( struct V_12 * V_13 ,
struct V_71 * V_165 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_165 -> V_163 >= V_2 -> V_164 )
return - V_56 ;
* V_165 = * F_56 ( V_13 ) ;
return 0 ;
}
static void F_93 ( struct V_12 * V_13 ,
struct V_5 * V_84 )
{
F_94 ( V_84 , F_56 ( V_13 ) ,
F_55 ( V_13 ) ? 250000 : 1000000 ,
F_2 , NULL ) ;
}
static unsigned int F_95 ( struct V_12 * V_13 )
{
unsigned int V_166 ;
int V_167 , V_168 ;
V_167 = F_40 ( V_13 , 0x06 ) ;
V_168 = F_40 ( V_13 , 0x3b ) ;
if ( V_167 < 0 || V_168 < 0 )
return 0 ;
V_166 = V_167 * 1000000 + ( ( V_168 & 0x30 ) >> 4 ) * 250000 ;
if ( F_78 ( V_13 ) ) {
unsigned V_169 = ( ( F_40 ( V_13 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_166 = V_166 * 8 / V_169 ;
}
return V_166 ;
}
static unsigned int F_96 ( struct V_12 * V_13 )
{
int V_167 , V_168 ;
V_167 = F_40 ( V_13 , 0x51 ) ;
V_168 = F_40 ( V_13 , 0x52 ) ;
if ( V_167 < 0 || V_168 < 0 )
return 0 ;
return ( ( V_167 << 1 ) | ( V_168 >> 7 ) ) * 1000000 + ( V_168 & 0x7f ) * 1000000 / 128 ;
}
static int F_97 ( struct V_12 * V_13 ,
struct V_5 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
struct V_14 * V_10 = & V_84 -> V_10 ;
struct V_146 V_147 ;
if ( ! V_84 )
return - V_56 ;
memset ( V_84 , 0 , sizeof( struct V_5 ) ) ;
if ( F_81 ( V_13 ) ) {
V_2 -> V_170 = true ;
F_33 ( 1 , V_37 , V_13 , L_37 , V_38 ) ;
return - V_171 ;
}
if ( F_89 ( V_13 , & V_147 ) ) {
F_33 ( 1 , V_37 , V_13 , L_38 , V_38 ) ;
return - V_171 ;
}
V_10 -> V_161 = V_147 . V_161 ?
V_172 : V_173 ;
if ( F_55 ( V_13 ) ) {
V_84 -> type = V_174 ;
V_10 -> V_11 = F_41 ( V_13 , 0x07 , V_3 -> V_175 ) ;
V_10 -> V_91 = F_41 ( V_13 , 0x09 , V_3 -> V_176 ) ;
V_10 -> V_103 = V_3 -> V_177 ( V_13 ) ;
V_10 -> V_96 = F_41 ( V_13 , 0x20 , V_3 -> V_178 ) ;
V_10 -> V_93 = F_41 ( V_13 , 0x22 , V_3 -> V_179 ) ;
V_10 -> V_94 = F_41 ( V_13 , 0x24 , V_3 -> V_180 ) ;
V_10 -> V_98 = F_41 ( V_13 , 0x2a ,
V_3 -> V_181 ) / 2 ;
V_10 -> V_100 = F_41 ( V_13 , 0x2e , V_3 -> V_182 ) / 2 ;
V_10 -> V_101 = F_41 ( V_13 , 0x32 ,
V_3 -> V_183 ) / 2 ;
V_10 -> V_184 = ( ( F_40 ( V_13 , 0x05 ) & 0x10 ) ? V_157 : 0 ) |
( ( F_40 ( V_13 , 0x05 ) & 0x20 ) ? V_155 : 0 ) ;
if ( V_10 -> V_161 == V_172 ) {
V_10 -> V_91 += F_41 ( V_13 , 0x0b ,
V_3 -> V_185 ) ;
V_10 -> V_186 = F_41 ( V_13 , 0x2c ,
V_3 -> V_187 ) / 2 ;
V_10 -> V_188 = F_41 ( V_13 , 0x30 ,
V_3 -> V_189 ) / 2 ;
V_10 -> V_190 = F_41 ( V_13 , 0x34 ,
V_3 -> V_191 ) / 2 ;
}
F_93 ( V_13 , V_84 ) ;
} else {
if ( ! F_85 ( V_13 , & V_147 , V_84 ) )
goto V_192;
V_147 . V_153 += 1 ;
F_33 ( 1 , V_37 , V_13 , L_39 , V_38 , V_147 . V_153 ) ;
if ( ! F_85 ( V_13 , & V_147 , V_84 ) )
goto V_192;
V_147 . V_153 -= 2 ;
F_33 ( 1 , V_37 , V_13 , L_40 , V_38 , V_147 . V_153 ) ;
if ( F_85 ( V_13 , & V_147 , V_84 ) ) {
if ( V_2 -> V_170 ) {
F_33 ( 1 , V_37 , V_13 , L_41 , V_38 ) ;
F_48 ( V_13 , 0x86 , 0x06 , 0x00 ) ;
F_48 ( V_13 , 0x86 , 0x06 , 0x04 ) ;
F_48 ( V_13 , 0x86 , 0x06 , 0x02 ) ;
V_2 -> V_170 = false ;
return - V_171 ;
}
F_33 ( 1 , V_37 , V_13 , L_42 , V_38 ) ;
return - V_193 ;
}
V_2 -> V_170 = true ;
}
V_192:
if ( F_81 ( V_13 ) ) {
F_33 ( 1 , V_37 , V_13 , L_43 , V_38 ) ;
memset ( V_84 , 0 , sizeof( struct V_5 ) ) ;
return - V_171 ;
}
if ( ( F_54 ( V_13 ) && V_10 -> V_103 > 170000000 ) ||
( F_55 ( V_13 ) && V_10 -> V_103 > 225000000 ) ) {
F_33 ( 1 , V_37 , V_13 , L_44 ,
V_38 , ( T_4 ) V_10 -> V_103 ) ;
return - V_193 ;
}
if ( V_37 > 1 )
F_98 ( V_13 -> V_194 , L_45 ,
V_84 , true ) ;
return 0 ;
}
static int F_99 ( struct V_12 * V_13 ,
struct V_5 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_14 * V_10 ;
int V_20 ;
if ( ! V_84 )
return - V_56 ;
if ( F_3 ( & V_2 -> V_84 , V_84 , 0 , false ) ) {
F_33 ( 1 , V_37 , V_13 , L_46 , V_38 ) ;
return 0 ;
}
V_10 = & V_84 -> V_10 ;
if ( ! F_86 ( V_84 , F_56 ( V_13 ) ,
F_2 , NULL ) )
return - V_193 ;
F_93 ( V_13 , V_84 ) ;
V_2 -> V_84 = * V_84 ;
F_48 ( V_13 , 0x91 , 0x40 , V_10 -> V_161 ? 0x40 : 0x00 ) ;
V_20 = F_67 ( V_13 , V_84 ) ;
if ( V_20 ) {
F_68 ( V_13 , V_10 ) ;
}
F_72 ( V_13 ) ;
if ( V_37 > 1 )
F_98 ( V_13 -> V_194 , L_47 ,
V_84 , true ) ;
return 0 ;
}
static int F_100 ( struct V_12 * V_13 ,
struct V_5 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
* V_84 = V_2 -> V_84 ;
return 0 ;
}
static void F_101 ( struct V_12 * V_13 , bool V_195 )
{
F_42 ( V_13 , 0x01 , V_195 ? 0x00 : 0x78 ) ;
}
static void F_102 ( struct V_12 * V_13 , bool V_195 )
{
F_42 ( V_13 , 0x83 , V_195 ? 0xfe : 0xff ) ;
}
static void F_103 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( F_54 ( V_13 ) ) {
F_16 ( V_13 , 0x15 , 0xb0 ) ;
} else if ( F_55 ( V_13 ) ) {
F_43 ( V_13 , 0x00 , 0x03 , V_2 -> V_64 ) ;
V_2 -> V_3 -> V_196 ( V_13 , true ) ;
F_16 ( V_13 , 0x15 , 0xa0 ) ;
F_43 ( V_13 , 0x1a , 0x10 , 0x00 ) ;
} else {
F_33 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_64 ) ;
}
}
static void F_104 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_43 ( V_13 , 0x1a , 0x10 , 0x10 ) ;
F_105 ( 16 ) ;
F_16 ( V_13 , 0x15 , 0xbe ) ;
V_2 -> V_3 -> V_196 ( V_13 , false ) ;
}
static void F_106 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
if ( F_54 ( V_13 ) ) {
F_53 ( V_13 , V_3 -> V_197 [ 0 ] ) ;
F_26 ( V_13 , 0x00 , 0x08 ) ;
F_26 ( V_13 , 0x01 , 0x06 ) ;
F_26 ( V_13 , 0xc8 , 0x00 ) ;
} else if ( F_55 ( V_13 ) ) {
F_42 ( V_13 , 0x00 , V_2 -> V_64 & 0x03 ) ;
F_53 ( V_13 , V_3 -> V_197 [ 1 ] ) ;
if ( F_1 ( V_2 ) ) {
F_26 ( V_13 , 0x00 , 0xff ) ;
F_26 ( V_13 , 0x01 , 0xfe ) ;
F_26 ( V_13 , 0xc8 , 0x40 ) ;
}
F_47 ( V_13 , 0x3e , 0x00 ) ;
F_47 ( V_13 , 0xc3 , 0x39 ) ;
F_47 ( V_13 , 0x40 , 0x80 ) ;
} else {
F_33 ( 2 , V_37 , V_13 , L_19 ,
V_38 , V_2 -> V_64 ) ;
}
}
static int F_107 ( struct V_12 * V_13 ,
T_4 V_198 , T_4 V_199 , T_4 V_200 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_33 ( 2 , V_37 , V_13 , L_48 ,
V_38 , V_198 , V_2 -> V_64 ) ;
if ( V_198 == V_2 -> V_64 )
return 0 ;
if ( V_198 > V_2 -> V_3 -> V_201 )
return - V_56 ;
V_2 -> V_64 = V_198 ;
F_104 ( V_13 ) ;
F_106 ( V_13 ) ;
F_103 ( V_13 ) ;
F_108 ( V_13 , & V_202 ) ;
return 0 ;
}
static int F_109 ( struct V_12 * V_13 ,
struct V_203 * V_204 ,
struct V_205 * V_61 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_61 -> V_206 >= V_2 -> V_3 -> V_62 )
return - V_56 ;
V_61 -> V_61 = V_2 -> V_3 -> V_63 [ V_61 -> V_206 ] . V_61 ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_207 * V_208 )
{
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
V_208 -> V_11 = V_2 -> V_84 . V_10 . V_11 ;
V_208 -> V_91 = V_2 -> V_84 . V_10 . V_91 ;
V_208 -> V_209 = V_210 ;
V_208 -> V_211 = V_212 ;
if ( V_2 -> V_84 . V_10 . V_122 & V_123 )
V_208 -> V_211 = ( V_2 -> V_84 . V_10 . V_91 <= 576 ) ?
V_213 : V_214 ;
}
static unsigned int F_111 ( struct V_1 * V_2 )
{
#define F_112 ( V_167 , V_168 , T_5 , T_6 , T_7 , T_8 ) { \
ADV76XX_OP_CH_SEL_##a, ADV76XX_OP_CH_SEL_##b, ADV76XX_OP_CH_SEL_##c, \
ADV76XX_OP_CH_SEL_##d, ADV76XX_OP_CH_SEL_##e, ADV76XX_OP_CH_SEL_##f }
#define F_113 ( T_9 ) [ADV7604_BUS_ORDER_##x]
static const unsigned int V_215 [ 6 ] [ 6 ] = {
F_113 ( V_216 ) = F_112 ( V_217 , V_218 , V_219 , V_216 , V_220 , V_221 ) ,
F_113 ( V_218 ) = F_112 ( V_219 , V_216 , V_217 , V_218 , V_221 , V_220 ) ,
F_113 ( V_221 ) = F_112 ( V_218 , V_217 , V_220 , V_221 , V_219 , V_216 ) ,
F_113 ( V_219 ) = F_112 ( V_221 , V_220 , V_216 , V_219 , V_218 , V_217 ) ,
F_113 ( V_220 ) = F_112 ( V_220 , V_221 , V_218 , V_217 , V_216 , V_219 ) ,
F_113 ( V_217 ) = F_112 ( V_216 , V_219 , V_221 , V_220 , V_217 , V_218 ) ,
} ;
return V_215 [ V_2 -> V_222 . V_223 ] [ V_2 -> V_208 -> V_215 >> 5 ] ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_13 ;
F_18 ( V_13 , 0x02 , 0x02 ,
V_2 -> V_208 -> V_224 ? V_225 : 0 ) ;
F_16 ( V_13 , 0x03 , V_2 -> V_208 -> V_226 |
V_2 -> V_222 . V_227 ) ;
F_18 ( V_13 , 0x04 , 0xe0 , F_111 ( V_2 ) ) ;
F_18 ( V_13 , 0x05 , 0x01 ,
V_2 -> V_208 -> V_228 ? V_229 : 0 ) ;
}
static int F_115 ( struct V_12 * V_13 ,
struct V_203 * V_204 ,
struct V_230 * V_208 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_208 -> V_163 != V_2 -> V_164 )
return - V_56 ;
F_110 ( V_2 , & V_208 -> V_208 ) ;
if ( V_208 -> V_231 == V_232 ) {
struct V_207 * V_233 ;
V_233 = F_116 ( V_13 , V_204 , V_208 -> V_163 ) ;
V_208 -> V_208 . V_61 = V_233 -> V_61 ;
} else {
V_208 -> V_208 . V_61 = V_2 -> V_208 -> V_61 ;
}
return 0 ;
}
static int F_117 ( struct V_12 * V_13 ,
struct V_203 * V_204 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_235 -> V_231 != V_236 )
return - V_56 ;
if ( V_235 -> V_237 > V_238 )
return - V_56 ;
V_235 -> V_239 . V_240 = 0 ;
V_235 -> V_239 . V_241 = 0 ;
V_235 -> V_239 . V_11 = V_2 -> V_84 . V_10 . V_11 ;
V_235 -> V_239 . V_91 = V_2 -> V_84 . V_10 . V_91 ;
return 0 ;
}
static int F_118 ( struct V_12 * V_13 ,
struct V_203 * V_204 ,
struct V_230 * V_208 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_60 * V_3 ;
if ( V_208 -> V_163 != V_2 -> V_164 )
return - V_56 ;
V_3 = V_60 ( V_2 , V_208 -> V_208 . V_61 ) ;
if ( V_3 == NULL )
V_3 = V_60 ( V_2 , V_242 ) ;
F_110 ( V_2 , & V_208 -> V_208 ) ;
V_208 -> V_208 . V_61 = V_3 -> V_61 ;
if ( V_208 -> V_231 == V_232 ) {
struct V_207 * V_233 ;
V_233 = F_116 ( V_13 , V_204 , V_208 -> V_163 ) ;
V_233 -> V_61 = V_208 -> V_208 . V_61 ;
} else {
V_2 -> V_208 = V_3 ;
F_114 ( V_2 ) ;
}
return 0 ;
}
static int F_119 ( struct V_12 * V_13 , T_4 V_141 , bool * V_243 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
const T_1 V_244 = F_15 ( V_13 , 0x43 ) ;
const T_1 V_245 = F_15 ( V_13 , 0x6b ) ;
const T_1 V_246 = F_15 ( V_13 , 0x70 ) ;
T_1 V_247 ;
T_1 V_248 ;
T_1 V_249 ;
if ( V_244 )
F_16 ( V_13 , 0x44 , V_244 ) ;
if ( V_246 )
F_16 ( V_13 , 0x71 , V_246 ) ;
if ( V_245 )
F_16 ( V_13 , 0x6c , V_245 ) ;
F_33 ( 2 , V_37 , V_13 , L_49 , V_38 ) ;
V_248 = V_244 & 0x98 ;
V_247 = F_55 ( V_13 )
? V_245 & V_3 -> V_250
: 0 ;
if ( V_248 || V_247 ) {
F_33 ( 1 , V_37 , V_13 ,
L_50 ,
V_38 , V_248 , V_247 ) ;
F_108 ( V_13 , & V_202 ) ;
if ( V_243 )
* V_243 = true ;
}
if ( V_245 & 0x01 ) {
F_33 ( 1 , V_37 , V_13 , L_51 , V_38 ,
( F_15 ( V_13 , 0x6a ) & 0x01 ) ? L_52 : L_53 ) ;
F_72 ( V_13 ) ;
if ( V_243 )
* V_243 = true ;
}
V_249 = V_246 & V_3 -> V_251 ;
if ( V_249 ) {
F_33 ( 1 , V_37 , V_13 , L_54 , V_38 , V_249 ) ;
F_64 ( V_13 ) ;
if ( V_243 )
* V_243 = true ;
}
return 0 ;
}
static int F_120 ( struct V_12 * V_13 , struct V_252 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 * V_253 = NULL ;
memset ( V_48 -> V_254 , 0 , sizeof( V_48 -> V_254 ) ) ;
switch ( V_48 -> V_163 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
if ( V_2 -> V_48 . V_49 & ( 1 << V_48 -> V_163 ) )
V_253 = V_2 -> V_48 . V_48 ;
break;
default:
return - V_56 ;
}
if ( V_48 -> V_255 == 0 && V_48 -> V_256 == 0 ) {
V_48 -> V_256 = V_253 ? V_2 -> V_48 . V_256 : 0 ;
return 0 ;
}
if ( V_253 == NULL )
return - V_257 ;
if ( V_48 -> V_255 >= V_2 -> V_48 . V_256 )
return - V_56 ;
if ( V_48 -> V_255 + V_48 -> V_256 > V_2 -> V_48 . V_256 )
V_48 -> V_256 = V_2 -> V_48 . V_256 - V_48 -> V_255 ;
memcpy ( V_48 -> V_48 , V_253 + V_48 -> V_255 * 128 , V_48 -> V_256 * 128 ) ;
return 0 ;
}
static int F_121 ( const T_1 * V_48 )
{
T_1 T_6 ;
if ( ( V_48 [ 0x7e ] != 1 ) ||
( V_48 [ 0x80 ] != 0x02 ) ||
( V_48 [ 0x81 ] != 0x03 ) ) {
return - 1 ;
}
T_6 = V_48 [ 0x82 ] & 0x7f ;
if ( T_6 > 4 ) {
int V_8 = 0x84 ;
int V_258 = 0x80 + T_6 ;
do {
T_1 V_259 = V_48 [ V_8 ] >> 5 ;
T_1 V_36 = V_48 [ V_8 ] & 0x1f ;
if ( ( V_259 == 3 ) && ( V_36 >= 5 ) )
return V_8 + 4 ;
V_8 += V_36 + 1 ;
} while ( V_8 < V_258 );
}
return - 1 ;
}
static int F_122 ( struct V_12 * V_13 , struct V_252 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
int V_260 ;
int V_20 ;
int V_8 ;
memset ( V_48 -> V_254 , 0 , sizeof( V_48 -> V_254 ) ) ;
if ( V_48 -> V_163 > V_70 )
return - V_56 ;
if ( V_48 -> V_255 != 0 )
return - V_56 ;
if ( V_48 -> V_256 == 0 ) {
V_2 -> V_48 . V_49 &= ~ ( 1 << V_48 -> V_163 ) ;
F_34 ( V_2 , V_2 -> V_48 . V_49 ) ;
F_29 ( V_13 , V_3 -> V_261 , 0x0f , V_2 -> V_48 . V_49 ) ;
V_2 -> V_158 . V_262 = 16 ;
V_2 -> V_158 . V_263 = 9 ;
if ( ! V_2 -> V_48 . V_49 )
V_2 -> V_48 . V_256 = 0 ;
F_33 ( 2 , V_37 , V_13 , L_55 ,
V_38 , V_48 -> V_163 , V_2 -> V_48 . V_49 ) ;
return 0 ;
}
if ( V_48 -> V_256 > 2 ) {
V_48 -> V_256 = 2 ;
return - V_264 ;
}
F_33 ( 2 , V_37 , V_13 , L_56 ,
V_38 , V_48 -> V_163 , V_2 -> V_48 . V_49 ) ;
F_123 ( & V_2 -> V_47 ) ;
F_34 ( V_2 , 0 ) ;
F_29 ( V_13 , V_3 -> V_261 , 0x0f , 0x00 ) ;
V_260 = F_121 ( V_48 -> V_48 ) ;
if ( V_260 < 0 )
V_260 = 0xc0 ;
switch ( V_48 -> V_163 ) {
case V_67 :
V_2 -> V_265 [ 0 ] = V_48 -> V_48 [ V_260 ] ;
V_2 -> V_265 [ 1 ] = V_48 -> V_48 [ V_260 + 1 ] ;
break;
case V_68 :
F_28 ( V_13 , 0x70 , V_48 -> V_48 [ V_260 ] ) ;
F_28 ( V_13 , 0x71 , V_48 -> V_48 [ V_260 + 1 ] ) ;
break;
case V_69 :
F_28 ( V_13 , 0x72 , V_48 -> V_48 [ V_260 ] ) ;
F_28 ( V_13 , 0x73 , V_48 -> V_48 [ V_260 + 1 ] ) ;
break;
case V_70 :
F_28 ( V_13 , 0x74 , V_48 -> V_48 [ V_260 ] ) ;
F_28 ( V_13 , 0x75 , V_48 -> V_48 [ V_260 + 1 ] ) ;
break;
default:
return - V_56 ;
}
if ( V_3 -> type == V_266 ) {
F_28 ( V_13 , 0x76 , V_260 & 0xff ) ;
F_29 ( V_13 , 0x77 , 0x40 , ( V_260 & 0x100 ) >> 2 ) ;
} else {
F_28 ( V_13 , 0x70 , V_260 & 0xff ) ;
F_29 ( V_13 , 0x71 , 0x01 , ( V_260 & 0x100 ) >> 8 ) ;
}
V_48 -> V_48 [ V_260 ] = V_2 -> V_265 [ 0 ] ;
V_48 -> V_48 [ V_260 + 1 ] = V_2 -> V_265 [ 1 ] ;
memcpy ( V_2 -> V_48 . V_48 , V_48 -> V_48 , 128 * V_48 -> V_256 ) ;
V_2 -> V_48 . V_256 = V_48 -> V_256 ;
V_2 -> V_158 = F_124 ( V_48 -> V_48 [ 0x15 ] ,
V_48 -> V_48 [ 0x16 ] ) ;
V_2 -> V_48 . V_49 |= 1 << V_48 -> V_163 ;
V_20 = F_32 ( V_13 , 128 * V_48 -> V_256 , V_2 -> V_48 . V_48 ) ;
if ( V_20 < 0 ) {
F_69 ( V_13 , L_57 , V_20 , V_48 -> V_163 ) ;
return V_20 ;
}
F_29 ( V_13 , V_3 -> V_261 , 0x0f , V_2 -> V_48 . V_49 ) ;
for ( V_8 = 0 ; V_8 < 1000 ; V_8 ++ ) {
if ( F_27 ( V_13 , V_3 -> V_267 ) & V_2 -> V_48 . V_49 )
break;
F_125 ( 1 ) ;
}
if ( V_8 == 1000 ) {
F_69 ( V_13 , L_58 , V_2 -> V_48 . V_49 ) ;
return - V_268 ;
}
F_126 ( V_2 -> V_269 ,
& V_2 -> V_47 , V_270 / 10 ) ;
return 0 ;
}
static int F_127 ( struct V_12 * V_13 , int V_206 ,
union V_271 * V_272 )
{
T_10 V_273 [ 32 ] ;
T_1 V_36 ;
int V_8 ;
if ( ! ( F_15 ( V_13 , 0x60 ) & V_274 [ V_206 ] . V_275 ) ) {
F_58 ( V_13 , L_59 ,
V_274 [ V_206 ] . V_276 ) ;
return - V_277 ;
}
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
V_273 [ V_8 ] = F_23 ( V_13 ,
V_274 [ V_206 ] . V_278 + V_8 ) ;
V_36 = V_273 [ 2 ] + 1 ;
if ( V_36 + 3 > sizeof( V_273 ) ) {
F_69 ( V_13 , L_60 , V_38 ,
V_274 [ V_206 ] . V_276 , V_36 ) ;
return - V_277 ;
}
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
V_273 [ V_8 + 3 ] = F_23 ( V_13 ,
V_274 [ V_206 ] . V_279 + V_8 ) ;
if ( F_128 ( V_272 , V_273 ) < 0 ) {
F_69 ( V_13 , L_61 , V_38 ,
V_274 [ V_206 ] . V_276 ) ;
return - V_277 ;
}
return 0 ;
}
static void F_129 ( struct V_12 * V_13 )
{
int V_8 ;
if ( ! F_78 ( V_13 ) ) {
F_58 ( V_13 , L_62 ) ;
return;
}
for ( V_8 = 0 ; V_8 < F_130 ( V_274 ) ; V_8 ++ ) {
union V_271 V_272 ;
struct V_17 * V_18 = F_131 ( V_13 ) ;
if ( F_127 ( V_13 , V_8 , & V_272 ) )
return;
F_132 ( V_280 , & V_18 -> V_281 , & V_272 ) ;
}
}
static int F_133 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
struct V_5 V_84 ;
struct V_146 V_147 ;
T_1 V_282 = F_15 ( V_13 , 0x02 ) ;
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
F_58 ( V_13 , L_90 ) ;
F_58 ( V_13 , L_91 , F_75 ( V_13 ) ? L_92 : L_93 ) ;
V_283 = F_27 ( V_13 , V_3 -> V_267 ) ;
F_58 ( V_13 , L_94 ,
( ( V_283 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_283 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_283 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_283 & 0x08 ) ? L_95 : L_96 ) ) ;
F_58 ( V_13 , L_97 , ! ! ( F_21 ( V_13 , 0x2a ) & 0x01 ) ?
L_98 : L_99 ) ;
F_58 ( V_13 , L_100 ) ;
V_284 = V_3 -> V_80 ( V_13 ) ;
F_58 ( V_13 , L_101 ,
( ( V_284 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_284 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_284 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_284 & 0x08 ) ? L_95 : L_96 ) ) ;
F_58 ( V_13 , L_102 ,
F_76 ( V_13 ) ? L_103 : L_104 ) ;
F_58 ( V_13 , L_105 ,
F_77 ( V_13 ) ? L_103 : L_104 ) ;
F_58 ( V_13 , L_106 , F_79 ( V_13 ) ? L_103 : L_104 ) ;
F_58 ( V_13 , L_107 , F_80 ( V_13 ) ? L_103 : L_104 ) ;
F_58 ( V_13 , L_108 , F_82 ( V_13 ) ? L_103 : L_104 ) ;
F_58 ( V_13 , L_109 ,
( F_83 ( V_13 ) ) ? L_93 : L_92 ) ;
F_58 ( V_13 , L_110 ,
F_15 ( V_13 , 0x01 ) & 0x0f , F_15 ( V_13 , 0x00 ) & 0x3f ,
( F_15 ( V_13 , 0x01 ) & 0x70 ) >> 4 ) ;
F_58 ( V_13 , L_111 ) ;
if ( F_89 ( V_13 , & V_147 ) )
F_58 ( V_13 , L_112 ) ;
else
F_58 ( V_13 , L_113 ,
V_147 . V_152 , V_147 . V_149 , V_147 . V_153 ,
V_147 . V_161 ? L_35 : L_36 ,
V_147 . V_154 , V_147 . V_156 ) ;
if ( F_97 ( V_13 , & V_84 ) )
F_58 ( V_13 , L_114 ) ;
else
F_98 ( V_13 -> V_194 , L_115 ,
& V_84 , true ) ;
F_98 ( V_13 -> V_194 , L_116 ,
& V_2 -> V_84 , true ) ;
if ( F_81 ( V_13 ) )
return 0 ;
F_58 ( V_13 , L_117 ) ;
F_58 ( V_13 , L_118 ,
V_288 [ V_2 -> V_120 ] ) ;
F_58 ( V_13 , L_119 ,
V_286 [ V_282 >> 4 ] ) ;
F_58 ( V_13 , L_120 ,
( V_282 & 0x02 ) ? L_121 : L_122 ,
( V_282 & 0x04 ) ? L_123 : L_124 ,
( ( ( V_282 >> 2 ) & 0x01 ) ^ ( V_282 & 0x01 ) ) ?
L_98 : L_99 ,
( V_282 & 0x08 ) ? L_98 : L_99 ) ;
F_58 ( V_13 , L_125 ,
V_285 [ F_45 ( V_13 , V_3 -> V_290 ) >> 4 ] ) ;
if ( ! F_55 ( V_13 ) )
return 0 ;
F_58 ( V_13 , L_126 , F_78 ( V_13 ) ? L_52 : L_127 ) ;
F_58 ( V_13 , L_128 ,
( F_40 ( V_13 , 0x00 ) & 0x03 ) + 'A' ) ;
F_58 ( V_13 , L_129 ,
( F_40 ( V_13 , 0x05 ) & 0x40 ) ? L_104 : L_103 ) ;
F_58 ( V_13 , L_130 ,
( F_40 ( V_13 , 0x04 ) & 0x20 ) ? L_131 : L_132 ,
( F_40 ( V_13 , 0x04 ) & 0x10 ) ? L_133 : L_134 ) ;
if ( F_78 ( V_13 ) ) {
bool V_291 = F_40 ( V_13 , 0x04 ) & 0x01 ;
bool V_292 = F_40 ( V_13 , 0x18 ) & 0x01 ;
bool V_293 = F_15 ( V_13 , 0x65 ) & 0x40 ;
F_58 ( V_13 , L_135 ,
V_291 ? L_136 : L_137 ,
V_292 ? L_138 : L_139 ,
V_293 ? L_140 : L_98 ) ;
if ( V_291 && V_292 ) {
F_58 ( V_13 , L_141 ,
( F_40 ( V_13 , 0x07 ) & 0x20 ) ? L_142 : L_143 ) ;
}
F_58 ( V_13 , L_144 , ( F_40 ( V_13 , 0x5b ) << 12 ) +
( F_40 ( V_13 , 0x5c ) << 8 ) +
( F_40 ( V_13 , 0x5d ) & 0xf0 ) ) ;
F_58 ( V_13 , L_145 , ( ( F_40 ( V_13 , 0x5d ) & 0x0f ) << 16 ) +
( F_40 ( V_13 , 0x5e ) << 8 ) +
F_40 ( V_13 , 0x5f ) ) ;
F_58 ( V_13 , L_146 , ( F_40 ( V_13 , 0x04 ) & 0x40 ) ? L_93 : L_92 ) ;
F_58 ( V_13 , L_147 , V_289 [ ( F_40 ( V_13 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_58 ( V_13 , L_148 , V_287 [ F_40 ( V_13 , 0x53 ) & 0xf ] ) ;
F_129 ( V_13 ) ;
}
return 0 ;
}
static int F_134 ( struct V_12 * V_13 ,
struct V_294 * V_295 ,
struct V_296 * V_297 )
{
switch ( V_297 -> type ) {
case V_298 :
return F_135 ( V_13 , V_295 , V_297 ) ;
case V_299 :
return F_136 ( V_13 , V_295 , V_297 ) ;
default:
return - V_56 ;
}
}
static int F_137 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
const struct V_78 * V_3 = V_2 -> V_3 ;
struct V_300 * V_222 = & V_2 -> V_222 ;
F_42 ( V_13 , 0x48 ,
( V_222 -> V_301 ? 0x80 : 0 ) |
( V_222 -> V_302 ? 0x40 : 0 ) ) ;
F_104 ( V_13 ) ;
if ( V_222 -> V_303 >= 0 &&
V_222 -> V_303 < V_2 -> V_164 ) {
V_2 -> V_64 = V_222 -> V_303 ;
F_106 ( V_13 ) ;
F_103 ( V_13 ) ;
}
F_16 ( V_13 , 0x0c , 0x42 ) ;
F_16 ( V_13 , 0x0b , 0x44 ) ;
F_47 ( V_13 , 0xcf , 0x01 ) ;
F_18 ( V_13 , 0x02 , 0x0f ,
V_222 -> V_304 << 3 |
V_222 -> V_305 << 2 |
V_222 -> V_306 << 0 ) ;
F_18 ( V_13 , 0x05 , 0x0e , V_222 -> V_307 << 3 |
V_222 -> V_308 << 2 |
V_222 -> V_309 << 1 ) ;
F_114 ( V_2 ) ;
F_47 ( V_13 , 0x69 , 0x30 ) ;
F_16 ( V_13 , 0x06 , 0xa0 | V_222 -> V_310 << 2 |
V_222 -> V_311 << 1 | V_222 -> V_312 ) ;
F_16 ( V_13 , 0x14 , 0x40 | V_222 -> V_313 << 4 |
V_222 -> V_314 << 2 |
V_222 -> V_315 ) ;
F_47 ( V_13 , 0xba , ( V_222 -> V_316 << 1 ) | 0x01 ) ;
F_47 ( V_13 , 0xf3 , 0xdc ) ;
F_47 ( V_13 , 0xf9 , 0x23 ) ;
F_47 ( V_13 , 0x45 , 0x23 ) ;
F_47 ( V_13 , 0xc9 , 0x2d ) ;
F_43 ( V_13 , 0x15 , 0x03 , 0x03 ) ;
F_43 ( V_13 , 0x1a , 0x0e , 0x08 ) ;
F_43 ( V_13 , 0x68 , 0x06 , 0x06 ) ;
F_26 ( V_13 , 0xb5 , 0x01 ) ;
if ( F_1 ( V_2 ) ) {
F_26 ( V_13 , 0x02 , V_222 -> V_317 ) ;
F_18 ( V_13 , 0x30 , 1 << 4 , V_222 -> V_318 << 4 ) ;
}
F_16 ( V_13 , 0x40 , 0xc0 | V_222 -> V_319 ) ;
F_16 ( V_13 , 0x46 , 0x98 ) ;
F_16 ( V_13 , 0x6e , V_3 -> V_250 ) ;
F_16 ( V_13 , 0x73 , V_3 -> V_251 ) ;
V_3 -> V_320 ( V_13 ) ;
return F_138 ( V_13 -> V_321 ) ;
}
static void F_139 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd7 ) ;
}
static void F_140 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd0 ) ;
}
static void F_141 ( struct V_12 * V_13 )
{
F_16 ( V_13 , 0x41 , 0xd0 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 1 ; V_8 < F_130 ( V_2 -> V_19 ) ; ++ V_8 ) {
if ( V_2 -> V_19 [ V_8 ] )
F_143 ( V_2 -> V_19 [ V_8 ] ) ;
}
}
static struct V_17 * F_144 ( struct V_12 * V_13 ,
T_1 V_23 , T_1 V_322 )
{
struct V_17 * V_18 = F_131 ( V_13 ) ;
if ( V_23 )
F_16 ( V_13 , V_322 , V_23 << 1 ) ;
return F_145 ( V_18 -> V_323 , F_15 ( V_13 , V_322 ) >> 1 ) ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_324 V_325 ;
struct V_326 * V_327 ;
struct V_326 * V_328 ;
unsigned int V_122 ;
int V_75 ;
T_4 V_329 ;
V_328 = V_2 -> V_19 [ V_27 ] -> V_281 . V_330 ;
V_327 = F_147 ( V_328 , NULL ) ;
if ( ! V_327 )
return - V_56 ;
V_75 = F_148 ( V_327 , & V_325 ) ;
if ( V_75 ) {
F_149 ( V_327 ) ;
return V_75 ;
}
if ( ! F_150 ( V_327 , L_149 , & V_329 ) )
V_2 -> V_222 . V_303 = V_329 ;
else
V_2 -> V_222 . V_303 = - 1 ;
F_149 ( V_327 ) ;
V_122 = V_325 . V_331 . V_332 . V_122 ;
if ( V_122 & V_333 )
V_2 -> V_222 . V_311 = 1 ;
if ( V_122 & V_334 )
V_2 -> V_222 . V_310 = 1 ;
if ( V_122 & V_335 )
V_2 -> V_222 . V_312 = 1 ;
if ( V_325 . V_336 == V_337 ) {
V_2 -> V_222 . V_308 = 1 ;
V_2 -> V_222 . V_305 = 1 ;
}
V_2 -> V_222 . V_319 = V_338 ;
V_2 -> V_222 . V_339 [ V_29 ] = 0x42 ;
V_2 -> V_222 . V_339 [ V_30 ] = 0x40 ;
V_2 -> V_222 . V_339 [ V_31 ] = 0x3e ;
V_2 -> V_222 . V_339 [ V_340 ] = 0x38 ;
V_2 -> V_222 . V_339 [ V_341 ] = 0x3c ;
V_2 -> V_222 . V_339 [ V_32 ] = 0x26 ;
V_2 -> V_222 . V_339 [ V_33 ] = 0x32 ;
V_2 -> V_222 . V_339 [ V_34 ] = 0x36 ;
V_2 -> V_222 . V_339 [ V_50 ] = 0x34 ;
V_2 -> V_222 . V_339 [ V_51 ] = 0x30 ;
V_2 -> V_222 . V_339 [ V_52 ] = 0x22 ;
V_2 -> V_222 . V_339 [ V_53 ] = 0x24 ;
V_2 -> V_222 . V_301 = 0 ;
V_2 -> V_222 . V_302 = 0 ;
V_2 -> V_222 . V_307 = 1 ;
V_2 -> V_222 . V_306 = 1 ;
V_2 -> V_222 . V_227 = V_342 ;
V_2 -> V_222 . V_223 = V_343 ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 , int V_344 )
{
int V_20 ;
if ( ! V_2 -> V_19 [ V_344 ] )
return - V_345 ;
V_2 -> V_22 [ V_344 ] =
F_152 ( V_2 -> V_19 [ V_344 ] ,
& V_346 [ V_344 ] ) ;
if ( F_153 ( V_2 -> V_22 [ V_344 ] ) ) {
V_20 = F_154 ( V_2 -> V_22 [ V_344 ] ) ;
F_12 ( V_2 -> V_19 [ V_344 ] ,
L_150 ,
V_344 , V_20 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_8 , V_20 ;
for ( V_8 = V_29 ; V_8 < V_347 ; V_8 ++ ) {
V_20 = F_151 ( V_2 , V_8 ) ;
if ( V_20 && ( V_20 != - V_345 ) )
return V_20 ;
}
return 0 ;
}
static int F_156 ( struct V_17 * V_18 ,
const struct V_348 * V_129 )
{
static const struct V_5 V_349 =
V_350 ;
struct V_1 * V_2 ;
struct V_351 * V_7 ;
struct V_126 * V_127 ;
struct V_12 * V_13 ;
unsigned int V_8 ;
unsigned int V_21 , V_352 ;
int V_20 ;
if ( ! F_157 ( V_18 -> V_323 , V_353 ) )
return - V_268 ;
F_158 ( 1 , V_37 , V_18 , L_151 ,
V_18 -> V_23 << 1 ) ;
V_2 = F_159 ( & V_18 -> V_281 , sizeof( * V_2 ) , V_354 ) ;
if ( ! V_2 ) {
F_12 ( V_18 , L_152 ) ;
return - V_355 ;
}
V_2 -> V_19 [ V_27 ] = V_18 ;
V_2 -> V_170 = true ;
V_2 -> V_64 = ~ 0 ;
if ( F_160 ( V_356 ) && V_18 -> V_281 . V_330 ) {
const struct V_357 * V_358 ;
V_358 = F_161 ( V_359 , V_18 -> V_281 . V_330 ) ;
V_2 -> V_3 = V_358 -> V_253 ;
V_20 = F_146 ( V_2 ) ;
if ( V_20 < 0 ) {
F_12 ( V_18 , L_153 ) ;
return V_20 ;
}
} else if ( V_18 -> V_281 . V_360 ) {
struct V_300 * V_222 = V_18 -> V_281 . V_360 ;
V_2 -> V_3 = ( const struct V_78 * ) V_129 -> V_361 ;
V_2 -> V_222 = * V_222 ;
} else {
F_12 ( V_18 , L_154 ) ;
return - V_345 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_40 ; ++ V_8 ) {
V_2 -> V_41 [ V_8 ] =
F_162 ( & V_18 -> V_281 , L_155 , V_8 ,
V_362 ) ;
if ( F_153 ( V_2 -> V_41 [ V_8 ] ) )
return F_154 ( V_2 -> V_41 [ V_8 ] ) ;
if ( V_2 -> V_41 [ V_8 ] )
F_163 ( V_18 , L_156 , V_8 ) ;
}
V_2 -> V_84 = V_349 ;
V_2 -> V_208 = V_60 ( V_2 , V_242 ) ;
V_13 = & V_2 -> V_13 ;
F_164 ( V_13 , V_18 , & V_363 ) ;
snprintf ( V_13 -> V_194 , sizeof( V_13 -> V_194 ) , L_157 ,
V_129 -> V_194 , F_165 ( V_18 -> V_323 ) ,
V_18 -> V_23 ) ;
V_13 -> V_122 |= V_364 | V_365 ;
V_20 = F_151 ( V_2 , V_27 ) ;
if ( V_20 ) {
F_69 ( V_13 , L_158 ) ;
return - V_345 ;
}
switch ( V_2 -> V_3 -> type ) {
case V_266 :
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] , 0xfb , & V_21 ) ;
if ( V_20 ) {
F_69 ( V_13 , L_159 , V_20 ) ;
return - V_345 ;
}
if ( V_21 != 0x68 ) {
F_69 ( V_13 , L_160 ,
V_18 -> V_23 << 1 ) ;
return - V_345 ;
}
break;
case V_366 :
case V_367 :
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] ,
0xea ,
& V_21 ) ;
if ( V_20 ) {
F_69 ( V_13 , L_159 , V_20 ) ;
return - V_345 ;
}
V_352 = V_21 << 8 ;
V_20 = F_11 ( V_2 -> V_22 [ V_27 ] ,
0xeb ,
& V_21 ) ;
if ( V_20 ) {
F_69 ( V_13 , L_159 , V_20 ) ;
return - V_345 ;
}
V_21 |= V_352 ;
if ( ( V_2 -> V_3 -> type == V_366 && V_21 != 0x2051 ) ||
( V_2 -> V_3 -> type == V_367 && V_21 != 0x2041 ) ) {
F_69 ( V_13 , L_161 ,
V_18 -> V_23 << 1 ) ;
return - V_345 ;
}
break;
}
V_7 = & V_2 -> V_7 ;
F_166 ( V_7 , F_1 ( V_2 ) ? 9 : 8 ) ;
F_167 ( V_7 , & V_368 ,
V_130 , - 128 , 127 , 1 , 0 ) ;
F_167 ( V_7 , & V_368 ,
V_131 , 0 , 255 , 1 , 128 ) ;
F_167 ( V_7 , & V_368 ,
V_132 , 0 , 255 , 1 , 128 ) ;
F_167 ( V_7 , & V_368 ,
V_133 , 0 , 128 , 1 , 0 ) ;
V_127 = F_168 ( V_7 , & V_368 ,
V_138 , V_139 ,
0 , V_139 ) ;
if ( V_127 )
V_127 -> V_122 |= V_369 ;
V_2 -> V_79 = F_167 ( V_7 , NULL ,
V_370 , 0 ,
( 1 << V_2 -> V_3 -> V_40 ) - 1 , 0 , 0 ) ;
V_2 -> V_371 =
F_168 ( V_7 , & V_368 ,
V_134 , V_125 ,
0 , V_121 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_372 =
F_169 ( V_7 , & V_373 , NULL ) ;
V_2 -> V_374 =
F_169 ( V_7 , & V_375 , NULL ) ;
V_2 -> V_376 =
F_169 ( V_7 , & V_377 , NULL ) ;
V_13 -> V_321 = V_7 ;
if ( V_7 -> error ) {
V_20 = V_7 -> error ;
goto V_378;
}
V_2 -> V_79 -> V_379 = true ;
V_2 -> V_371 -> V_379 = true ;
if ( F_1 ( V_2 ) )
V_2 -> V_372 -> V_379 = true ;
V_2 -> V_374 -> V_379 = true ;
V_2 -> V_376 -> V_379 = true ;
if ( F_64 ( V_13 ) ) {
V_20 = - V_345 ;
goto V_378;
}
for ( V_8 = 1 ; V_8 < V_347 ; ++ V_8 ) {
if ( ! ( F_36 ( V_8 ) & V_2 -> V_3 -> V_55 ) )
continue;
V_2 -> V_19 [ V_8 ] =
F_144 ( V_13 , V_2 -> V_222 . V_339 [ V_8 ] ,
0xf2 + V_8 ) ;
if ( V_2 -> V_19 [ V_8 ] == NULL ) {
V_20 = - V_355 ;
F_69 ( V_13 , L_162 , V_8 ) ;
goto V_380;
}
}
V_2 -> V_269 = F_170 ( V_18 -> V_194 ) ;
if ( ! V_2 -> V_269 ) {
F_69 ( V_13 , L_163 ) ;
V_20 = - V_355 ;
goto V_380;
}
F_171 ( & V_2 -> V_47 ,
F_38 ) ;
V_2 -> V_164 = V_2 -> V_3 -> V_40
+ ( V_2 -> V_3 -> V_4 ? 2 : 0 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_164 ; ++ V_8 )
V_2 -> V_381 [ V_8 ] . V_122 = V_382 ;
V_2 -> V_381 [ V_2 -> V_164 ] . V_122 = V_383 ;
V_20 = F_172 ( & V_13 -> V_384 , V_2 -> V_164 + 1 ,
V_2 -> V_381 ) ;
if ( V_20 )
goto V_385;
V_20 = F_155 ( V_2 ) ;
if ( V_20 )
goto V_386;
V_20 = F_137 ( V_13 ) ;
if ( V_20 )
goto V_386;
F_58 ( V_13 , L_164 , V_18 -> V_194 ,
V_18 -> V_23 << 1 , V_18 -> V_323 -> V_194 ) ;
V_20 = F_173 ( V_13 ) ;
if ( V_20 )
goto V_386;
return 0 ;
V_386:
F_174 ( & V_13 -> V_384 ) ;
V_385:
F_175 ( & V_2 -> V_47 ) ;
F_176 ( V_2 -> V_269 ) ;
V_380:
F_142 ( V_2 ) ;
V_378:
F_177 ( V_7 ) ;
return V_20 ;
}
static int F_178 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_179 ( V_18 ) ;
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_175 ( & V_2 -> V_47 ) ;
F_176 ( V_2 -> V_269 ) ;
F_180 ( V_13 ) ;
F_174 ( & V_13 -> V_384 ) ;
F_142 ( F_4 ( V_13 ) ) ;
F_177 ( V_13 -> V_321 ) ;
return 0 ;
}
