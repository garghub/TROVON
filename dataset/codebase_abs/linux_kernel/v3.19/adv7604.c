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
static inline unsigned F_8 ( const struct V_7 * V_8 )
{
return F_9 ( V_8 ) ;
}
static inline unsigned F_10 ( const struct V_7 * V_8 )
{
return F_11 ( V_8 ) ;
}
static T_1 F_12 ( struct V_9 * V_10 ,
T_2 V_11 , bool V_12 )
{
union V_13 V_14 ;
if ( ! F_13 ( V_10 -> V_15 , V_10 -> V_16 , V_10 -> V_17 ,
V_18 , V_11 ,
V_19 , & V_14 ) )
return V_14 . V_20 ;
if ( V_12 )
F_14 ( V_10 , L_1 ,
V_10 -> V_16 , V_11 ) ;
return - V_21 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
enum V_22 V_23 , T_2 V_11 )
{
return F_12 ( V_2 -> V_24 [ V_23 ] ,
V_11 , true ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
enum V_22 V_23 , T_2 V_11 ,
T_2 V_25 )
{
struct V_9 * V_10 = V_2 -> V_24 [ V_23 ] ;
union V_13 V_14 ;
int V_26 ;
int V_27 ;
V_14 . V_20 = V_25 ;
for ( V_27 = 0 ; V_27 < 3 ; V_27 ++ ) {
V_26 = F_13 ( V_10 -> V_15 , V_10 -> V_16 ,
V_10 -> V_17 ,
V_28 , V_11 ,
V_19 , & V_14 ) ;
if ( ! V_26 )
break;
}
if ( V_26 < 0 )
F_14 ( V_10 , L_2 ,
V_10 -> V_16 , V_11 , V_25 ) ;
return V_26 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
enum V_22 V_23 , T_2 V_11 ,
unsigned V_29 , const T_2 * V_30 )
{
struct V_9 * V_10 = V_2 -> V_24 [ V_23 ] ;
union V_13 V_14 ;
if ( V_29 > V_31 )
V_29 = V_31 ;
V_14 . V_32 [ 0 ] = V_29 ;
memcpy ( V_14 . V_32 + 1 , V_30 , V_29 ) ;
return F_13 ( V_10 -> V_15 , V_10 -> V_16 , V_10 -> V_17 ,
V_28 , V_11 ,
V_33 , & V_14 ) ;
}
static inline int F_18 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_35 , V_34 ) ;
}
static inline int F_19 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_35 , V_34 , V_36 ) ;
}
static inline int F_20 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_19 ( V_6 , V_34 , ( F_18 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_21 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_38 , V_34 ) ;
}
static inline int F_22 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_38 , V_34 , V_36 ) ;
}
static inline int F_23 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_39 , V_34 ) ;
}
static inline int F_24 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_39 , V_34 , V_36 ) ;
}
static inline int F_25 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_24 ( V_6 , V_34 , ( F_23 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_26 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_40 , V_34 ) ;
}
static inline int F_27 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_40 ,
V_34 , V_36 ) ;
}
static inline int F_28 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_41 , V_34 ) ;
}
static inline int F_29 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_41 , V_34 , V_36 ) ;
}
static inline int F_30 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_42 , V_34 ) ;
}
static inline int F_31 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_42 , V_34 , V_36 ) ;
}
static inline int F_32 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_43 , V_34 ) ;
}
static inline int F_33 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_43 , V_34 , V_36 ) ;
}
static inline int F_34 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_44 , V_34 ) ;
}
static inline int F_35 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_44 , V_34 , V_36 ) ;
}
static inline int F_36 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_35 ( V_6 , V_34 , ( F_34 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_37 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_45 , V_34 ) ;
}
static inline int F_38 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_45 , V_34 , V_36 ) ;
}
static inline int F_39 ( struct V_5 * V_6 , unsigned V_46 , T_2 * V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_9 * V_10 = V_2 -> V_24 [ V_45 ] ;
T_2 V_47 [ 1 ] = { 0 } ;
T_2 V_48 [ 256 ] ;
struct V_49 V_50 [ 2 ] = {
{
. V_16 = V_10 -> V_16 ,
. V_46 = 1 ,
. V_51 = V_47
} ,
{
. V_16 = V_10 -> V_16 ,
. V_17 = V_52 ,
. V_46 = V_46 ,
. V_51 = V_48
} ,
} ;
if ( F_40 ( V_10 -> V_15 , V_50 , 2 ) < 0 )
return - V_21 ;
memcpy ( V_36 , V_48 , V_46 ) ;
return 0 ;
}
static inline int F_41 ( struct V_5 * V_6 ,
unsigned V_46 , const T_2 * V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_26 = 0 ;
int V_27 ;
F_42 ( 2 , V_53 , V_6 , L_3 , V_54 , V_46 ) ;
for ( V_27 = 0 ; ! V_26 && V_27 < V_46 ; V_27 += V_31 )
V_26 = F_17 ( V_2 , V_45 ,
V_27 , V_31 , V_36 + V_27 ) ;
return V_26 ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_55 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_56 ; ++ V_27 ) {
if ( F_44 ( V_2 -> V_57 [ V_27 ] ) )
continue;
F_45 ( V_2 -> V_57 [ V_27 ] , V_55 & F_46 ( V_27 ) ) ;
}
F_47 ( & V_2 -> V_6 , V_58 , & V_55 ) ;
}
static void F_48 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_49 ( V_60 ) ;
struct V_1 * V_2 = F_3 ( V_62 , struct V_1 ,
V_63 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_42 ( 2 , V_53 , V_6 , L_4 , V_54 ) ;
F_43 ( V_2 , V_2 -> V_64 . V_65 ) ;
}
static inline int F_50 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_66 , V_34 ) ;
}
static T_3 F_51 ( struct V_5 * V_6 , T_2 V_34 , T_3 V_37 )
{
return ( ( F_50 ( V_6 , V_34 ) << 8 ) | F_50 ( V_6 , V_34 + 1 ) ) & V_37 ;
}
static inline int F_52 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_66 , V_34 , V_36 ) ;
}
static inline int F_53 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_52 ( V_6 , V_34 , ( F_50 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_54 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_67 , V_34 ) ;
}
static inline int F_55 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_67 , V_34 , V_36 ) ;
}
static inline int F_56 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_68 , V_34 ) ;
}
static T_3 F_57 ( struct V_5 * V_6 , T_2 V_34 , T_3 V_37 )
{
return ( ( F_56 ( V_6 , V_34 ) << 8 ) | F_56 ( V_6 , V_34 + 1 ) ) & V_37 ;
}
static inline int F_58 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_68 , V_34 , V_36 ) ;
}
static inline int F_59 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_37 , T_2 V_36 )
{
return F_58 ( V_6 , V_34 , ( F_56 ( V_6 , V_34 ) & ~ V_37 ) | V_36 ) ;
}
static inline int F_60 ( struct V_5 * V_6 , T_2 V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_15 ( V_2 , V_69 , V_34 ) ;
}
static inline int F_61 ( struct V_5 * V_6 , T_2 V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return F_16 ( V_2 , V_69 , V_34 , V_36 ) ;
}
static int F_62 ( struct V_5 * V_6 , unsigned int V_34 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned int V_23 = V_34 >> 8 ;
if ( ! ( F_46 ( V_23 ) & V_2 -> V_3 -> V_70 ) )
return - V_71 ;
V_34 &= 0xff ;
return F_15 ( V_2 , V_23 , V_34 ) ;
}
static int F_63 ( struct V_5 * V_6 , unsigned int V_34 , T_2 V_36 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
unsigned int V_23 = V_34 >> 8 ;
if ( ! ( F_46 ( V_23 ) & V_2 -> V_3 -> V_70 ) )
return - V_71 ;
V_34 &= 0xff ;
return F_16 ( V_2 , V_23 , V_34 , V_36 ) ;
}
static void F_64 ( struct V_5 * V_6 ,
const struct V_72 * V_73 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_73 [ V_27 ] . V_34 != V_74 ; V_27 ++ )
F_63 ( V_6 , V_73 [ V_27 ] . V_34 , V_73 [ V_27 ] . V_36 ) ;
}
static const struct V_75 *
V_75 ( struct V_1 * V_2 , T_4 V_76 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_77 ; ++ V_27 ) {
if ( V_2 -> V_3 -> V_78 [ V_27 ] . V_76 == V_76 )
return & V_2 -> V_3 -> V_78 [ V_27 ] ;
}
return NULL ;
}
static inline bool F_65 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_79 == V_80 ||
V_2 -> V_79 == V_81 ;
}
static inline bool F_66 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_79 == V_82 ||
V_2 -> V_79 == V_83 ||
V_2 -> V_79 == V_84 ||
V_2 -> V_79 == V_85 ;
}
static void F_67 ( struct V_5 * V_6 )
{
F_68 ( V_6 , L_5 ) ;
F_68 ( V_6 , L_6 ) ;
F_68 ( V_6 , L_7 ) ;
F_68 ( V_6 , L_8 ) ;
F_68 ( V_6 , L_9 ) ;
F_68 ( V_6 , L_10 ) ;
F_68 ( V_6 , L_11 ) ;
F_68 ( V_6 , L_12 ) ;
F_68 ( V_6 , L_13 ) ;
F_68 ( V_6 , L_14 ) ;
F_68 ( V_6 , L_15 ) ;
F_68 ( V_6 , L_16 ) ;
F_68 ( V_6 , L_17 ) ;
}
static int F_69 ( struct V_5 * V_6 ,
struct V_86 * V_34 )
{
int V_87 ;
V_87 = F_62 ( V_6 , V_34 -> V_34 ) ;
if ( V_87 < 0 ) {
F_68 ( V_6 , L_18 , V_34 -> V_34 ) ;
F_67 ( V_6 ) ;
return V_87 ;
}
V_34 -> V_88 = 1 ;
V_34 -> V_36 = V_87 ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 ,
const struct V_86 * V_34 )
{
int V_87 ;
V_87 = F_63 ( V_6 , V_34 -> V_34 , V_34 -> V_36 ) ;
if ( V_87 < 0 ) {
F_68 ( V_6 , L_18 , V_34 -> V_34 ) ;
F_67 ( V_6 ) ;
return V_87 ;
}
return 0 ;
}
static unsigned int F_71 ( struct V_5 * V_6 )
{
T_2 V_25 = F_18 ( V_6 , 0x6f ) ;
return ( ( V_25 & 0x10 ) >> 4 )
| ( ( V_25 & 0x08 ) >> 2 )
| ( ( V_25 & 0x04 ) << 0 )
| ( ( V_25 & 0x02 ) << 2 ) ;
}
static unsigned int F_72 ( struct V_5 * V_6 )
{
T_2 V_25 = F_18 ( V_6 , 0x6f ) ;
return V_25 & 1 ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
return F_74 ( V_2 -> V_90 ,
V_3 -> V_91 ( V_6 ) ) ;
}
static int F_75 ( struct V_5 * V_6 ,
T_2 V_92 ,
const struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
int V_27 ;
for ( V_27 = 0 ; V_94 [ V_27 ] . V_96 . V_97 . V_98 ; V_27 ++ ) {
if ( ! F_76 ( V_96 , & V_94 [ V_27 ] . V_96 ,
F_66 ( V_6 ) ? 250000 : 1000000 ) )
continue;
F_19 ( V_6 , 0x00 , V_94 [ V_27 ] . V_99 ) ;
F_19 ( V_6 , 0x01 , ( V_94 [ V_27 ] . V_100 << 4 ) +
V_92 ) ;
return 0 ;
}
return - 1 ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_26 ;
F_42 ( 1 , V_53 , V_6 , L_19 , V_54 ) ;
if ( F_1 ( V_2 ) ) {
F_19 ( V_6 , 0x16 , 0x43 ) ;
F_19 ( V_6 , 0x17 , 0x5a ) ;
}
F_59 ( V_6 , 0x81 , 0x10 , 0x00 ) ;
F_58 ( V_6 , 0x8f , 0x00 ) ;
F_58 ( V_6 , 0x90 , 0x00 ) ;
F_58 ( V_6 , 0xa2 , 0x00 ) ;
F_58 ( V_6 , 0xa3 , 0x00 ) ;
F_58 ( V_6 , 0xa4 , 0x00 ) ;
F_58 ( V_6 , 0xa5 , 0x00 ) ;
F_58 ( V_6 , 0xa6 , 0x00 ) ;
F_58 ( V_6 , 0xa7 , 0x00 ) ;
F_58 ( V_6 , 0xab , 0x00 ) ;
F_58 ( V_6 , 0xac , 0x00 ) ;
if ( F_65 ( V_6 ) ) {
V_26 = F_75 ( V_6 ,
0x01 , V_101 , V_96 ) ;
if ( V_26 )
V_26 = F_75 ( V_6 ,
0x02 , V_102 , V_96 ) ;
} else if ( F_66 ( V_6 ) ) {
V_26 = F_75 ( V_6 ,
0x05 , V_103 , V_96 ) ;
if ( V_26 )
V_26 = F_75 ( V_6 ,
0x06 , V_104 , V_96 ) ;
} else {
F_42 ( 2 , V_53 , V_6 , L_20 ,
V_54 , V_2 -> V_79 ) ;
V_26 = - 1 ;
}
return V_26 ;
}
static void F_78 ( struct V_5 * V_6 ,
const struct V_7 * V_97 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_98 = F_6 ( V_97 ) ;
T_4 V_105 = F_10 ( V_97 ) ;
T_3 V_106 = V_97 -> V_107 + V_97 -> V_108 - 4 ;
T_3 V_109 = V_98 - V_97 -> V_110 ;
T_3 V_111 = V_105 - V_97 -> V_112 ;
T_3 V_113 = V_97 -> V_114 + V_97 -> V_115 ;
T_3 V_116 = ( ( ( T_4 ) V_97 -> V_117 / 100 ) > 0 ) ?
( ( V_98 * ( V_118 / 100 ) ) / ( ( T_4 ) V_97 -> V_117 / 100 ) ) : 0 ;
const T_2 V_119 [ 2 ] = {
0xc0 | ( ( V_98 >> 8 ) & 0x1f ) ,
V_98 & 0xff
} ;
F_42 ( 2 , V_53 , V_6 , L_21 , V_54 ) ;
if ( F_65 ( V_6 ) ) {
F_19 ( V_6 , 0x00 , 0x07 ) ;
F_19 ( V_6 , 0x01 , 0x02 ) ;
F_59 ( V_6 , 0x81 , 0x10 , 0x10 ) ;
if ( F_17 ( V_2 , V_35 ,
0x16 , 2 , V_119 ) )
F_79 ( V_6 , L_22 ) ;
F_58 ( V_6 , 0xa2 , ( V_106 >> 4 ) & 0xff ) ;
F_58 ( V_6 , 0xa3 , ( ( V_106 & 0x0f ) << 4 ) |
( ( V_109 >> 8 ) & 0x0f ) ) ;
F_58 ( V_6 , 0xa4 , V_109 & 0xff ) ;
F_58 ( V_6 , 0xa5 , ( V_111 >> 4 ) & 0xff ) ;
F_58 ( V_6 , 0xa6 , ( ( V_111 & 0xf ) << 4 ) |
( ( V_113 >> 8 ) & 0xf ) ) ;
F_58 ( V_6 , 0xa7 , V_113 & 0xff ) ;
} else if ( F_66 ( V_6 ) ) {
F_19 ( V_6 , 0x00 , 0x02 ) ;
F_19 ( V_6 , 0x01 , 0x06 ) ;
} else {
F_42 ( 2 , V_53 , V_6 , L_20 ,
V_54 , V_2 -> V_79 ) ;
}
F_58 ( V_6 , 0x8f , ( V_116 >> 8 ) & 0x7 ) ;
F_58 ( V_6 , 0x90 , V_116 & 0xff ) ;
F_58 ( V_6 , 0xab , ( V_105 >> 4 ) & 0xff ) ;
F_58 ( V_6 , 0xac , ( V_105 & 0x0f ) << 4 ) ;
}
static void F_80 ( struct V_5 * V_6 , bool V_120 , T_3 V_121 , T_3 V_122 , T_3 V_123 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 V_124 [ 4 ] ;
if ( V_120 ) {
V_121 = 0x3ff ;
V_122 = 0x3ff ;
V_123 = 0x3ff ;
}
F_42 ( 2 , V_53 , V_6 , L_23 ,
V_54 , V_120 ? L_24 : L_25 ,
V_121 , V_122 , V_123 ) ;
V_124 [ 0 ] = ( F_56 ( V_6 , 0x77 ) & 0xc0 ) | ( ( V_121 & 0x3f0 ) >> 4 ) ;
V_124 [ 1 ] = ( ( V_121 & 0x00f ) << 4 ) | ( ( V_122 & 0x3c0 ) >> 6 ) ;
V_124 [ 2 ] = ( ( V_122 & 0x03f ) << 2 ) | ( ( V_123 & 0x300 ) >> 8 ) ;
V_124 [ 3 ] = V_123 & 0x0ff ;
if ( F_17 ( V_2 , V_68 ,
0x77 , 4 , V_124 ) )
F_79 ( V_6 , L_26 , V_54 ) ;
}
static void F_81 ( struct V_5 * V_6 , bool V_125 , T_3 V_126 , T_3 V_127 , T_3 V_128 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 V_129 [ 4 ] ;
T_2 V_130 = 1 ;
T_2 V_131 = 1 ;
if ( V_125 ) {
V_130 = 0 ;
V_131 = 0 ;
V_126 = 0x100 ;
V_127 = 0x100 ;
V_128 = 0x100 ;
}
F_42 ( 2 , V_53 , V_6 , L_27 ,
V_54 , V_125 ? L_24 : L_25 ,
V_126 , V_127 , V_128 ) ;
V_129 [ 0 ] = ( ( V_130 << 7 ) | ( V_131 << 6 ) | ( ( V_126 & 0x3f0 ) >> 4 ) ) ;
V_129 [ 1 ] = ( ( ( V_126 & 0x00f ) << 4 ) | ( ( V_127 & 0x3c0 ) >> 6 ) ) ;
V_129 [ 2 ] = ( ( ( V_127 & 0x03f ) << 2 ) | ( ( V_128 & 0x300 ) >> 8 ) ) ;
V_129 [ 3 ] = ( ( V_128 & 0x0ff ) ) ;
if ( F_17 ( V_2 , V_68 ,
0x73 , 4 , V_129 ) )
F_79 ( V_6 , L_28 , V_54 ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
bool V_132 = F_18 ( V_6 , 0x02 ) & 0x02 ;
bool V_133 = F_50 ( V_6 , 0x05 ) & 0x80 ;
F_42 ( 2 , V_53 , V_6 , L_29 ,
V_54 , V_2 -> V_134 ,
V_132 , V_133 ) ;
F_81 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
F_80 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_2 -> V_134 ) {
case V_135 :
if ( V_2 -> V_79 == V_80 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
break;
}
if ( V_2 -> V_79 == V_81 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_133 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_2 -> V_96 . V_97 . V_136 & V_137 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
} else {
F_20 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_66 ( V_6 ) && V_132 ) {
F_80 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_81 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_80 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_138 :
if ( V_2 -> V_79 == V_81 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0x20 ) ;
break;
}
F_20 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
break;
case V_139 :
if ( V_2 -> V_79 == V_81 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0x60 ) ;
break;
}
F_20 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_65 ( V_6 ) || V_133 )
break;
if ( V_132 ) {
F_80 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_81 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_80 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_83 ( struct V_140 * V_141 )
{
struct V_5 * V_6 =
& F_3 ( V_141 -> V_142 , struct V_1 , V_143 ) -> V_6 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
switch ( V_141 -> V_144 ) {
case V_145 :
F_58 ( V_6 , 0x3c , V_141 -> V_36 ) ;
return 0 ;
case V_146 :
F_58 ( V_6 , 0x3a , V_141 -> V_36 ) ;
return 0 ;
case V_147 :
F_58 ( V_6 , 0x3b , V_141 -> V_36 ) ;
return 0 ;
case V_148 :
F_58 ( V_6 , 0x3d , V_141 -> V_36 ) ;
return 0 ;
case V_149 :
V_2 -> V_134 = V_141 -> V_36 ;
F_82 ( V_6 ) ;
return 0 ;
case V_150 :
if ( ! F_1 ( V_2 ) )
return - V_71 ;
F_33 ( V_6 , 0xc8 , V_141 -> V_36 ) ;
return 0 ;
case V_151 :
F_59 ( V_6 , 0xbf , 0x04 , V_141 -> V_36 << 2 ) ;
return 0 ;
case V_152 :
F_58 ( V_6 , 0xc0 , ( V_141 -> V_36 & 0xff0000 ) >> 16 ) ;
F_58 ( V_6 , 0xc1 , ( V_141 -> V_36 & 0x00ff00 ) >> 8 ) ;
F_58 ( V_6 , 0xc2 , ( T_2 ) ( V_141 -> V_36 & 0x0000ff ) ) ;
return 0 ;
}
return - V_71 ;
}
static inline bool F_84 ( struct V_5 * V_6 )
{
return F_18 ( V_6 , 0x0c ) & 0x24 ;
}
static inline bool F_85 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return ! ( F_18 ( V_6 , 0x6a ) & ( 0x10 >> V_2 -> V_79 ) ) ;
}
static inline bool F_86 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
return ( F_18 ( V_6 , 0x6a ) & V_3 -> V_153 ) != V_3 -> V_153 ;
}
static inline bool F_87 ( struct V_5 * V_6 )
{
return F_50 ( V_6 , 0x05 ) & 0x80 ;
}
static inline bool F_88 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_1 ( V_2 ) )
return false ;
return ( ( F_56 ( V_6 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_89 ( struct V_5 * V_6 )
{
return ! ( F_56 ( V_6 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_90 ( struct V_5 * V_6 )
{
bool V_87 ;
V_87 = F_84 ( V_6 ) ;
V_87 |= F_89 ( V_6 ) ;
V_87 |= F_88 ( V_6 ) ;
if ( F_66 ( V_6 ) ) {
V_87 |= F_86 ( V_6 ) ;
V_87 |= F_85 ( V_6 ) ;
}
return V_87 ;
}
static inline bool F_91 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( ! F_1 ( V_2 ) )
return false ;
return F_18 ( V_6 , 0x12 ) & 0x01 ;
}
static int F_92 ( struct V_5 * V_6 , T_4 * V_154 )
{
* V_154 = 0 ;
* V_154 |= F_84 ( V_6 ) ? V_155 : 0 ;
* V_154 |= F_90 ( V_6 ) ? V_156 : 0 ;
if ( F_91 ( V_6 ) )
* V_154 |= F_66 ( V_6 ) ? V_157 : V_158 ;
F_42 ( 1 , V_53 , V_6 , L_30 , V_54 , * V_154 ) ;
return 0 ;
}
static int F_93 ( struct V_5 * V_6 ,
struct V_159 * V_160 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_161 = ( V_118 * 8 ) / V_160 -> V_162 ;
T_4 V_163 ;
int V_27 ;
for ( V_27 = 0 ; V_164 [ V_27 ] . V_97 . V_105 ; V_27 ++ ) {
if ( F_10 ( & V_164 [ V_27 ] . V_97 ) != V_160 -> V_165 + 1 )
continue;
if ( V_164 [ V_27 ] . V_97 . V_114 != V_160 -> V_166 )
continue;
V_163 = V_161 * F_6 ( & V_164 [ V_27 ] . V_97 ) ;
if ( ( V_163 < V_164 [ V_27 ] . V_97 . V_117 + 1000000 ) &&
( V_163 > V_164 [ V_27 ] . V_97 . V_117 - 1000000 ) ) {
* V_96 = V_164 [ V_27 ] ;
return 0 ;
}
}
if ( F_94 ( V_160 -> V_165 + 1 , V_161 , V_160 -> V_166 ,
( V_160 -> V_167 == '+' ? V_168 : 0 ) |
( V_160 -> V_169 == '+' ? V_170 : 0 ) ,
V_96 ) )
return 0 ;
if ( F_95 ( V_160 -> V_165 + 1 , V_161 , V_160 -> V_166 ,
( V_160 -> V_167 == '+' ? V_168 : 0 ) |
( V_160 -> V_169 == '+' ? V_170 : 0 ) ,
V_2 -> V_171 , V_96 ) )
return 0 ;
F_42 ( 2 , V_53 , V_6 ,
L_31 ,
V_54 , V_160 -> V_166 , V_160 -> V_165 , V_160 -> V_162 ,
V_160 -> V_167 , V_160 -> V_169 ) ;
return - 1 ;
}
static int F_96 ( struct V_5 * V_6 , struct V_159 * V_160 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
T_2 V_172 ;
if ( F_89 ( V_6 ) || F_88 ( V_6 ) ) {
F_42 ( 2 , V_53 , V_6 , L_32 , V_54 ) ;
return - 1 ;
}
V_160 -> V_162 = F_57 ( V_6 , 0xb1 , 0x3fff ) ;
V_160 -> V_165 = F_57 ( V_6 , V_3 -> V_173 , 0x7ff ) ;
V_160 -> V_166 = F_56 ( V_6 , 0xb3 ) >> 3 ;
V_160 -> V_174 = F_18 ( V_6 , 0x12 ) & 0x10 ;
if ( F_1 ( V_2 ) ) {
V_172 = F_56 ( V_6 , 0xb5 ) ;
if ( ( V_172 & 0x03 ) == 0x01 ) {
V_160 -> V_167 = V_172 & 0x10
? ( V_172 & 0x08 ? '+' : '-' ) : 'x' ;
V_160 -> V_169 = V_172 & 0x40
? ( V_172 & 0x20 ? '+' : '-' ) : 'x' ;
} else {
V_160 -> V_167 = 'x' ;
V_160 -> V_169 = 'x' ;
}
} else {
V_172 = F_50 ( V_6 , 0x05 ) ;
V_160 -> V_167 = V_172 & 0x20 ? '+' : '-' ;
V_160 -> V_169 = V_172 & 0x10 ? '+' : '-' ;
}
if ( F_89 ( V_6 ) || F_88 ( V_6 ) ) {
F_42 ( 2 , V_53 , V_6 ,
L_33 , V_54 ) ;
return - 1 ;
}
if ( V_160 -> V_165 < 239 || V_160 -> V_162 < 8 || V_160 -> V_162 == 0x3fff ) {
F_42 ( 2 , V_53 , V_6 , L_34 , V_54 ) ;
memset ( V_160 , 0 , sizeof( struct V_159 ) ) ;
return - 1 ;
}
F_42 ( 2 , V_53 , V_6 ,
L_35 ,
V_54 , V_160 -> V_165 , V_160 -> V_162 , V_160 -> V_166 ,
V_160 -> V_167 , V_160 -> V_169 ,
V_160 -> V_174 ? L_36 : L_37 ) ;
return 0 ;
}
static int F_97 ( struct V_5 * V_6 ,
struct V_175 * V_96 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_96 -> V_176 >= F_98 ( V_164 ) - 1 )
return - V_71 ;
if ( V_96 -> V_177 >= V_2 -> V_178 )
return - V_71 ;
memset ( V_96 -> V_179 , 0 , sizeof( V_96 -> V_179 ) ) ;
V_96 -> V_96 = V_164 [ V_96 -> V_176 ] ;
return 0 ;
}
static int F_99 ( struct V_5 * V_6 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_181 -> V_177 >= V_2 -> V_178 )
return - V_71 ;
V_181 -> type = V_182 ;
V_181 -> V_97 . V_183 = 1920 ;
V_181 -> V_97 . V_184 = 1200 ;
V_181 -> V_97 . V_185 = 25000000 ;
switch ( V_181 -> V_177 ) {
case V_82 :
case V_83 :
case V_84 :
case V_85 :
V_181 -> V_97 . V_186 = 225000000 ;
break;
case V_80 :
case V_81 :
default:
V_181 -> V_97 . V_186 = 170000000 ;
break;
}
V_181 -> V_97 . V_136 = V_137 | V_187 |
V_188 | V_189 ;
V_181 -> V_97 . V_190 = V_191 |
V_192 | V_193 ;
return 0 ;
}
static void F_100 ( struct V_5 * V_6 ,
struct V_95 * V_96 )
{
int V_27 ;
for ( V_27 = 0 ; V_164 [ V_27 ] . V_97 . V_98 ; V_27 ++ ) {
if ( F_76 ( V_96 , & V_164 [ V_27 ] ,
F_66 ( V_6 ) ? 250000 : 1000000 ) ) {
* V_96 = V_164 [ V_27 ] ;
break;
}
}
}
static unsigned int F_101 ( struct V_5 * V_6 )
{
unsigned int V_194 ;
int V_195 , V_196 ;
V_195 = F_50 ( V_6 , 0x06 ) ;
V_196 = F_50 ( V_6 , 0x3b ) ;
if ( V_195 < 0 || V_196 < 0 )
return 0 ;
V_194 = V_195 * 1000000 + ( ( V_196 & 0x30 ) >> 4 ) * 250000 ;
if ( F_87 ( V_6 ) ) {
unsigned V_197 = ( ( F_50 ( V_6 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_194 = V_194 * 8 / V_197 ;
}
return V_194 ;
}
static unsigned int F_102 ( struct V_5 * V_6 )
{
int V_195 , V_196 ;
V_195 = F_50 ( V_6 , 0x51 ) ;
V_196 = F_50 ( V_6 , 0x52 ) ;
if ( V_195 < 0 || V_196 < 0 )
return 0 ;
return ( ( V_195 << 1 ) | ( V_196 >> 7 ) ) * 1000000 + ( V_196 & 0x7f ) * 1000000 / 128 ;
}
static int F_103 ( struct V_5 * V_6 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
struct V_7 * V_97 = & V_96 -> V_97 ;
struct V_159 V_160 ;
if ( ! V_96 )
return - V_71 ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
if ( F_90 ( V_6 ) ) {
V_2 -> V_198 = true ;
F_42 ( 1 , V_53 , V_6 , L_38 , V_54 ) ;
return - V_199 ;
}
if ( F_96 ( V_6 , & V_160 ) ) {
F_42 ( 1 , V_53 , V_6 , L_39 , V_54 ) ;
return - V_199 ;
}
V_97 -> V_174 = V_160 . V_174 ?
V_200 : V_201 ;
if ( F_66 ( V_6 ) ) {
V_96 -> type = V_182 ;
V_97 -> V_98 = F_51 ( V_6 , 0x07 , 0xfff ) ;
V_97 -> V_105 = F_51 ( V_6 , 0x09 , 0xfff ) ;
V_97 -> V_117 = V_3 -> V_202 ( V_6 ) ;
V_97 -> V_110 = F_51 ( V_6 , 0x20 , 0x3ff ) ;
V_97 -> V_107 = F_51 ( V_6 , 0x22 , 0x3ff ) ;
V_97 -> V_108 = F_51 ( V_6 , 0x24 , 0x3ff ) ;
V_97 -> V_112 = F_51 ( V_6 , 0x2a , 0x1fff ) / 2 ;
V_97 -> V_114 = F_51 ( V_6 , 0x2e , 0x1fff ) / 2 ;
V_97 -> V_115 = F_51 ( V_6 , 0x32 , 0x1fff ) / 2 ;
V_97 -> V_203 = ( ( F_50 ( V_6 , 0x05 ) & 0x10 ) ? V_170 : 0 ) |
( ( F_50 ( V_6 , 0x05 ) & 0x20 ) ? V_168 : 0 ) ;
if ( V_97 -> V_174 == V_200 ) {
V_97 -> V_105 += F_51 ( V_6 , 0x0b , 0xfff ) ;
V_97 -> V_204 = F_51 ( V_6 , 0x2c , 0x1fff ) / 2 ;
V_97 -> V_205 = F_51 ( V_6 , 0x30 , 0x1fff ) / 2 ;
V_97 -> V_206 = F_51 ( V_6 , 0x34 , 0x1fff ) / 2 ;
}
F_100 ( V_6 , V_96 ) ;
} else {
if ( ! F_93 ( V_6 , & V_160 , V_96 ) )
goto V_207;
V_160 . V_166 += 1 ;
F_42 ( 1 , V_53 , V_6 , L_40 , V_54 , V_160 . V_166 ) ;
if ( ! F_93 ( V_6 , & V_160 , V_96 ) )
goto V_207;
V_160 . V_166 -= 2 ;
F_42 ( 1 , V_53 , V_6 , L_41 , V_54 , V_160 . V_166 ) ;
if ( F_93 ( V_6 , & V_160 , V_96 ) ) {
if ( V_2 -> V_198 ) {
F_42 ( 1 , V_53 , V_6 , L_42 , V_54 ) ;
F_59 ( V_6 , 0x86 , 0x06 , 0x00 ) ;
F_59 ( V_6 , 0x86 , 0x06 , 0x04 ) ;
F_59 ( V_6 , 0x86 , 0x06 , 0x02 ) ;
V_2 -> V_198 = false ;
return - V_199 ;
}
F_42 ( 1 , V_53 , V_6 , L_43 , V_54 ) ;
return - V_208 ;
}
V_2 -> V_198 = true ;
}
V_207:
if ( F_90 ( V_6 ) ) {
F_42 ( 1 , V_53 , V_6 , L_44 , V_54 ) ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
return - V_199 ;
}
if ( ( F_65 ( V_6 ) && V_97 -> V_117 > 170000000 ) ||
( F_66 ( V_6 ) && V_97 -> V_117 > 225000000 ) ) {
F_42 ( 1 , V_53 , V_6 , L_45 ,
V_54 , ( T_4 ) V_97 -> V_117 ) ;
return - V_208 ;
}
if ( V_53 > 1 )
F_104 ( V_6 -> V_209 , L_46 ,
V_96 , true ) ;
return 0 ;
}
static int F_105 ( struct V_5 * V_6 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_7 * V_97 ;
int V_26 ;
if ( ! V_96 )
return - V_71 ;
if ( F_76 ( & V_2 -> V_96 , V_96 , 0 ) ) {
F_42 ( 1 , V_53 , V_6 , L_47 , V_54 ) ;
return 0 ;
}
V_97 = & V_96 -> V_97 ;
if ( ( F_65 ( V_6 ) && V_97 -> V_117 > 170000000 ) ||
( F_66 ( V_6 ) && V_97 -> V_117 > 225000000 ) ) {
F_42 ( 1 , V_53 , V_6 , L_45 ,
V_54 , ( T_4 ) V_97 -> V_117 ) ;
return - V_208 ;
}
F_100 ( V_6 , V_96 ) ;
V_2 -> V_96 = * V_96 ;
F_59 ( V_6 , 0x91 , 0x40 , V_97 -> V_174 ? 0x40 : 0x00 ) ;
V_26 = F_77 ( V_6 , V_96 ) ;
if ( V_26 ) {
F_78 ( V_6 , V_97 ) ;
}
F_82 ( V_6 ) ;
if ( V_53 > 1 )
F_104 ( V_6 -> V_209 , L_48 ,
V_96 , true ) ;
return 0 ;
}
static int F_106 ( struct V_5 * V_6 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
* V_96 = V_2 -> V_96 ;
return 0 ;
}
static void F_107 ( struct V_5 * V_6 , bool V_210 )
{
F_52 ( V_6 , 0x01 , V_210 ? 0x00 : 0x78 ) ;
}
static void F_108 ( struct V_5 * V_6 , bool V_210 )
{
F_52 ( V_6 , 0x83 , V_210 ? 0xfe : 0xff ) ;
}
static void F_109 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_65 ( V_6 ) ) {
F_19 ( V_6 , 0x15 , 0xb0 ) ;
} else if ( F_66 ( V_6 ) ) {
F_53 ( V_6 , 0x00 , 0x03 , V_2 -> V_79 ) ;
V_2 -> V_3 -> V_211 ( V_6 , true ) ;
F_19 ( V_6 , 0x15 , 0xa0 ) ;
F_53 ( V_6 , 0x1a , 0x10 , 0x00 ) ;
} else {
F_42 ( 2 , V_53 , V_6 , L_20 ,
V_54 , V_2 -> V_79 ) ;
}
}
static void F_110 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_53 ( V_6 , 0x1a , 0x10 , 0x10 ) ;
F_111 ( 16 ) ;
F_19 ( V_6 , 0x15 , 0xbe ) ;
V_2 -> V_3 -> V_211 ( V_6 , false ) ;
}
static void F_112 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
if ( F_65 ( V_6 ) ) {
F_64 ( V_6 , V_3 -> V_212 [ 0 ] ) ;
F_33 ( V_6 , 0x00 , 0x08 ) ;
F_33 ( V_6 , 0x01 , 0x06 ) ;
F_33 ( V_6 , 0xc8 , 0x00 ) ;
} else if ( F_66 ( V_6 ) ) {
F_52 ( V_6 , 0x00 , V_2 -> V_79 & 0x03 ) ;
F_64 ( V_6 , V_3 -> V_212 [ 1 ] ) ;
if ( F_1 ( V_2 ) ) {
F_33 ( V_6 , 0x00 , 0xff ) ;
F_33 ( V_6 , 0x01 , 0xfe ) ;
F_33 ( V_6 , 0xc8 , 0x40 ) ;
}
F_58 ( V_6 , 0x3e , 0x00 ) ;
F_58 ( V_6 , 0xc3 , 0x39 ) ;
F_58 ( V_6 , 0x40 , 0x80 ) ;
} else {
F_42 ( 2 , V_53 , V_6 , L_20 ,
V_54 , V_2 -> V_79 ) ;
}
}
static int F_113 ( struct V_5 * V_6 ,
T_4 V_213 , T_4 V_214 , T_4 V_215 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_42 ( 2 , V_53 , V_6 , L_49 ,
V_54 , V_213 , V_2 -> V_79 ) ;
if ( V_213 == V_2 -> V_79 )
return 0 ;
if ( V_213 > V_2 -> V_3 -> V_216 )
return - V_71 ;
V_2 -> V_79 = V_213 ;
F_110 ( V_6 ) ;
F_112 ( V_6 ) ;
F_109 ( V_6 ) ;
return 0 ;
}
static int F_114 ( struct V_5 * V_6 ,
struct V_217 * V_218 ,
struct V_219 * V_76 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_76 -> V_176 >= V_2 -> V_3 -> V_77 )
return - V_71 ;
V_76 -> V_76 = V_2 -> V_3 -> V_78 [ V_76 -> V_176 ] . V_76 ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_220 * V_221 )
{
memset ( V_221 , 0 , sizeof( * V_221 ) ) ;
V_221 -> V_98 = V_2 -> V_96 . V_97 . V_98 ;
V_221 -> V_105 = V_2 -> V_96 . V_97 . V_105 ;
V_221 -> V_222 = V_223 ;
if ( V_2 -> V_96 . V_97 . V_136 & V_137 )
V_221 -> V_224 = ( V_2 -> V_96 . V_97 . V_105 <= 576 ) ?
V_225 : V_226 ;
}
static unsigned int F_116 ( struct V_1 * V_2 )
{
#define F_117 ( V_195 , V_196 , T_5 , T_6 , T_7 , T_8 ) { \
ADV7604_OP_CH_SEL_##a, ADV7604_OP_CH_SEL_##b, ADV7604_OP_CH_SEL_##c, \
ADV7604_OP_CH_SEL_##d, ADV7604_OP_CH_SEL_##e, ADV7604_OP_CH_SEL_##f }
#define F_118 ( T_9 ) [ADV7604_BUS_ORDER_##x]
static const unsigned int V_227 [ 6 ] [ 6 ] = {
F_118 ( V_228 ) = F_117 ( V_229 , V_230 , V_231 , V_228 , V_232 , V_233 ) ,
F_118 ( V_230 ) = F_117 ( V_231 , V_228 , V_229 , V_230 , V_233 , V_232 ) ,
F_118 ( V_233 ) = F_117 ( V_230 , V_229 , V_232 , V_233 , V_231 , V_228 ) ,
F_118 ( V_231 ) = F_117 ( V_233 , V_232 , V_228 , V_231 , V_230 , V_229 ) ,
F_118 ( V_232 ) = F_117 ( V_232 , V_233 , V_230 , V_229 , V_228 , V_231 ) ,
F_118 ( V_229 ) = F_117 ( V_228 , V_231 , V_233 , V_232 , V_229 , V_230 ) ,
} ;
return V_227 [ V_2 -> V_234 . V_235 ] [ V_2 -> V_221 -> V_227 >> 5 ] ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_20 ( V_6 , 0x02 , 0x02 ,
V_2 -> V_221 -> V_236 ? V_237 : 0 ) ;
F_19 ( V_6 , 0x03 , V_2 -> V_221 -> V_238 |
V_2 -> V_234 . V_239 ) ;
F_20 ( V_6 , 0x04 , 0xe0 , F_116 ( V_2 ) ) ;
F_20 ( V_6 , 0x05 , 0x01 ,
V_2 -> V_221 -> V_240 ? V_241 : 0 ) ;
}
static int F_120 ( struct V_5 * V_6 , struct V_217 * V_218 ,
struct V_242 * V_221 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_221 -> V_177 != V_2 -> V_178 )
return - V_71 ;
F_115 ( V_2 , & V_221 -> V_221 ) ;
if ( V_221 -> V_243 == V_244 ) {
struct V_220 * V_245 ;
V_245 = F_121 ( V_218 , V_221 -> V_177 ) ;
V_221 -> V_221 . V_76 = V_245 -> V_76 ;
} else {
V_221 -> V_221 . V_76 = V_2 -> V_221 -> V_76 ;
}
return 0 ;
}
static int F_122 ( struct V_5 * V_6 , struct V_217 * V_218 ,
struct V_242 * V_221 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_75 * V_3 ;
if ( V_221 -> V_177 != V_2 -> V_178 )
return - V_71 ;
V_3 = V_75 ( V_2 , V_221 -> V_221 . V_76 ) ;
if ( V_3 == NULL )
V_3 = V_75 ( V_2 , V_246 ) ;
F_115 ( V_2 , & V_221 -> V_221 ) ;
V_221 -> V_221 . V_76 = V_3 -> V_76 ;
if ( V_221 -> V_243 == V_244 ) {
struct V_220 * V_245 ;
V_245 = F_121 ( V_218 , V_221 -> V_177 ) ;
V_245 -> V_76 = V_221 -> V_221 . V_76 ;
} else {
V_2 -> V_221 = V_3 ;
F_119 ( V_2 ) ;
}
return 0 ;
}
static int F_123 ( struct V_5 * V_6 , T_4 V_154 , bool * V_247 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
const T_2 V_248 = F_18 ( V_6 , 0x43 ) ;
const T_2 V_249 = F_18 ( V_6 , 0x6b ) ;
const T_2 V_250 = F_18 ( V_6 , 0x70 ) ;
T_2 V_251 ;
T_2 V_252 ;
T_2 V_253 ;
if ( V_248 )
F_19 ( V_6 , 0x44 , V_248 ) ;
if ( V_250 )
F_19 ( V_6 , 0x71 , V_250 ) ;
if ( V_249 )
F_19 ( V_6 , 0x6c , V_249 ) ;
F_42 ( 2 , V_53 , V_6 , L_50 , V_54 ) ;
V_252 = V_248 & 0x98 ;
V_251 = F_66 ( V_6 )
? V_249 & V_3 -> V_254
: 0 ;
if ( V_252 || V_251 ) {
F_42 ( 1 , V_53 , V_6 ,
L_51 ,
V_54 , V_252 , V_251 ) ;
F_47 ( V_6 , V_255 , NULL ) ;
if ( V_247 )
* V_247 = true ;
}
if ( V_249 & 0x01 ) {
F_42 ( 1 , V_53 , V_6 , L_52 , V_54 ,
( F_18 ( V_6 , 0x6a ) & 0x01 ) ? L_53 : L_54 ) ;
F_82 ( V_6 ) ;
if ( V_247 )
* V_247 = true ;
}
V_253 = F_18 ( V_6 , 0x70 ) & V_3 -> V_256 ;
if ( V_253 ) {
F_42 ( 1 , V_53 , V_6 , L_55 , V_54 , V_253 ) ;
F_19 ( V_6 , 0x71 , V_253 ) ;
F_73 ( V_6 ) ;
if ( V_247 )
* V_247 = true ;
}
return 0 ;
}
static int F_124 ( struct V_5 * V_6 , struct V_257 * V_64 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 * V_14 = NULL ;
memset ( V_64 -> V_179 , 0 , sizeof( V_64 -> V_179 ) ) ;
switch ( V_64 -> V_177 ) {
case V_82 :
case V_83 :
case V_84 :
case V_85 :
if ( V_2 -> V_64 . V_65 & ( 1 << V_64 -> V_177 ) )
V_14 = V_2 -> V_64 . V_64 ;
break;
default:
return - V_71 ;
}
if ( V_64 -> V_258 == 0 && V_64 -> V_259 == 0 ) {
V_64 -> V_259 = V_14 ? V_2 -> V_64 . V_259 : 0 ;
return 0 ;
}
if ( V_14 == NULL )
return - V_260 ;
if ( V_64 -> V_258 >= V_2 -> V_64 . V_259 )
return - V_71 ;
if ( V_64 -> V_258 + V_64 -> V_259 > V_2 -> V_64 . V_259 )
V_64 -> V_259 = V_2 -> V_64 . V_259 - V_64 -> V_258 ;
memcpy ( V_64 -> V_64 , V_14 + V_64 -> V_258 * 128 , V_64 -> V_259 * 128 ) ;
return 0 ;
}
static int F_125 ( const T_2 * V_64 )
{
T_2 T_6 ;
if ( ( V_64 [ 0x7e ] != 1 ) ||
( V_64 [ 0x80 ] != 0x02 ) ||
( V_64 [ 0x81 ] != 0x03 ) ) {
return - 1 ;
}
T_6 = V_64 [ 0x82 ] & 0x7f ;
if ( T_6 > 4 ) {
int V_27 = 0x84 ;
int V_261 = 0x80 + T_6 ;
do {
T_2 V_262 = V_64 [ V_27 ] >> 5 ;
T_2 V_46 = V_64 [ V_27 ] & 0x1f ;
if ( ( V_262 == 3 ) && ( V_46 >= 5 ) )
return V_27 + 4 ;
V_27 += V_46 + 1 ;
} while ( V_27 < V_261 );
}
return - 1 ;
}
static int F_126 ( struct V_5 * V_6 , struct V_257 * V_64 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
int V_263 ;
int V_26 ;
int V_27 ;
memset ( V_64 -> V_179 , 0 , sizeof( V_64 -> V_179 ) ) ;
if ( V_64 -> V_177 > V_85 )
return - V_71 ;
if ( V_64 -> V_258 != 0 )
return - V_71 ;
if ( V_64 -> V_259 == 0 ) {
V_2 -> V_64 . V_65 &= ~ ( 1 << V_64 -> V_177 ) ;
F_43 ( V_2 , V_2 -> V_64 . V_65 ) ;
F_36 ( V_6 , V_3 -> V_264 , 0x0f , V_2 -> V_64 . V_65 ) ;
V_2 -> V_171 . V_265 = 16 ;
V_2 -> V_171 . V_266 = 9 ;
if ( ! V_2 -> V_64 . V_65 )
V_2 -> V_64 . V_259 = 0 ;
F_42 ( 2 , V_53 , V_6 , L_56 ,
V_54 , V_64 -> V_177 , V_2 -> V_64 . V_65 ) ;
return 0 ;
}
if ( V_64 -> V_259 > 2 ) {
V_64 -> V_259 = 2 ;
return - V_267 ;
}
F_42 ( 2 , V_53 , V_6 , L_57 ,
V_54 , V_64 -> V_177 , V_2 -> V_64 . V_65 ) ;
F_127 ( & V_2 -> V_63 ) ;
F_43 ( V_2 , 0 ) ;
F_36 ( V_6 , V_3 -> V_264 , 0x0f , 0x00 ) ;
V_263 = F_125 ( V_64 -> V_64 ) ;
if ( V_263 < 0 )
V_263 = 0xc0 ;
switch ( V_64 -> V_177 ) {
case V_82 :
V_2 -> V_268 [ 0 ] = V_64 -> V_64 [ V_263 ] ;
V_2 -> V_268 [ 1 ] = V_64 -> V_64 [ V_263 + 1 ] ;
break;
case V_83 :
F_35 ( V_6 , 0x70 , V_64 -> V_64 [ V_263 ] ) ;
F_35 ( V_6 , 0x71 , V_64 -> V_64 [ V_263 + 1 ] ) ;
break;
case V_84 :
F_35 ( V_6 , 0x72 , V_64 -> V_64 [ V_263 ] ) ;
F_35 ( V_6 , 0x73 , V_64 -> V_64 [ V_263 + 1 ] ) ;
break;
case V_85 :
F_35 ( V_6 , 0x74 , V_64 -> V_64 [ V_263 ] ) ;
F_35 ( V_6 , 0x75 , V_64 -> V_64 [ V_263 + 1 ] ) ;
break;
default:
return - V_71 ;
}
if ( V_3 -> type == V_269 ) {
F_35 ( V_6 , 0x76 , V_263 & 0xff ) ;
F_36 ( V_6 , 0x77 , 0x40 , ( V_263 & 0x100 ) >> 2 ) ;
} else {
F_36 ( V_6 , 0x71 , 0x01 , ( V_263 & 0x100 ) >> 8 ) ;
}
V_64 -> V_64 [ V_263 ] = V_2 -> V_268 [ 0 ] ;
V_64 -> V_64 [ V_263 + 1 ] = V_2 -> V_268 [ 1 ] ;
memcpy ( V_2 -> V_64 . V_64 , V_64 -> V_64 , 128 * V_64 -> V_259 ) ;
V_2 -> V_64 . V_259 = V_64 -> V_259 ;
V_2 -> V_171 = F_128 ( V_64 -> V_64 [ 0x15 ] ,
V_64 -> V_64 [ 0x16 ] ) ;
V_2 -> V_64 . V_65 |= 1 << V_64 -> V_177 ;
V_26 = F_41 ( V_6 , 128 * V_64 -> V_259 , V_2 -> V_64 . V_64 ) ;
if ( V_26 < 0 ) {
F_79 ( V_6 , L_58 , V_26 , V_64 -> V_177 ) ;
return V_26 ;
}
F_36 ( V_6 , V_3 -> V_264 , 0x0f , V_2 -> V_64 . V_65 ) ;
for ( V_27 = 0 ; V_27 < 1000 ; V_27 ++ ) {
if ( F_34 ( V_6 , V_3 -> V_270 ) & V_2 -> V_64 . V_65 )
break;
F_129 ( 1 ) ;
}
if ( V_27 == 1000 ) {
F_79 ( V_6 , L_59 , V_2 -> V_64 . V_65 ) ;
return - V_21 ;
}
F_130 ( V_2 -> V_271 ,
& V_2 -> V_63 , V_272 / 10 ) ;
return 0 ;
}
static void F_131 ( struct V_5 * V_6 )
{
int V_27 ;
T_2 V_51 [ 14 ] ;
T_2 V_273 ;
T_2 V_274 ;
if ( ! F_87 ( V_6 ) ) {
F_68 ( V_6 , L_60 ) ;
return;
}
if ( ! ( F_18 ( V_6 , 0x60 ) & 0x01 ) ) {
F_68 ( V_6 , L_61 ) ;
return;
}
if ( F_18 ( V_6 , 0x83 ) & 0x01 ) {
F_68 ( V_6 , L_62 ) ;
F_19 ( V_6 , 0x85 , 0x01 ) ;
if ( F_18 ( V_6 , 0x83 ) & 0x01 ) {
F_68 ( V_6 , L_63 ) ;
F_19 ( V_6 , 0x85 , 0x01 ) ;
}
}
V_273 = F_26 ( V_6 , 0xe2 ) ;
V_274 = F_26 ( V_6 , 0xe1 ) ;
F_68 ( V_6 , L_64 ,
V_274 , V_273 ) ;
if ( V_274 != 0x02 )
return;
for ( V_27 = 0 ; V_27 < 14 ; V_27 ++ )
V_51 [ V_27 ] = F_26 ( V_6 , V_27 ) ;
F_68 ( V_6 ,
L_65 ,
V_51 [ 0 ] , V_51 [ 1 ] , V_51 [ 2 ] , V_51 [ 3 ] , V_51 [ 4 ] , V_51 [ 5 ] , V_51 [ 6 ] , V_51 [ 7 ] ,
V_51 [ 8 ] , V_51 [ 9 ] , V_51 [ 10 ] , V_51 [ 11 ] , V_51 [ 12 ] , V_51 [ 13 ] ) ;
}
static int F_132 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
struct V_95 V_96 ;
struct V_159 V_160 ;
T_2 V_275 = F_18 ( V_6 , 0x02 ) ;
T_2 V_276 ;
T_2 V_277 ;
static const char * const V_278 [ 16 ] = {
L_66 , L_67 , L_68 , L_69 ,
L_68 , L_70 , L_68 , L_71 ,
L_68 , L_72 , L_73 ,
L_68 , L_68 , L_68 , L_68 , L_74
} ;
static const char * const V_279 [ 16 ] = {
L_75 , L_76 ,
L_77 , L_78 ,
L_79 , L_80 ,
L_81 , L_82 ,
L_83 , L_83 , L_83 , L_83 , L_83 ,
L_83 , L_83 , L_84
} ;
static const char * const V_280 [] = {
L_85 ,
L_75 ,
L_76 ,
} ;
static const char * const V_281 [ 4 ] = {
L_86 ,
L_87 ,
L_88 ,
L_89
} ;
F_68 ( V_6 , L_90 ) ;
F_68 ( V_6 , L_91 , F_84 ( V_6 ) ? L_92 : L_93 ) ;
V_276 = F_34 ( V_6 , V_3 -> V_270 ) ;
F_68 ( V_6 , L_94 ,
( ( V_276 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_276 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_276 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_276 & 0x08 ) ? L_95 : L_96 ) ) ;
F_68 ( V_6 , L_97 , ! ! ( F_23 ( V_6 , 0x2a ) & 0x01 ) ?
L_98 : L_99 ) ;
F_68 ( V_6 , L_100 ) ;
V_277 = V_3 -> V_91 ( V_6 ) ;
F_68 ( V_6 , L_101 ,
( ( V_277 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_277 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_277 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_277 & 0x08 ) ? L_95 : L_96 ) ) ;
F_68 ( V_6 , L_102 ,
F_85 ( V_6 ) ? L_103 : L_104 ) ;
F_68 ( V_6 , L_105 ,
F_86 ( V_6 ) ? L_103 : L_104 ) ;
F_68 ( V_6 , L_106 , F_88 ( V_6 ) ? L_103 : L_104 ) ;
F_68 ( V_6 , L_107 , F_89 ( V_6 ) ? L_103 : L_104 ) ;
F_68 ( V_6 , L_108 , F_91 ( V_6 ) ? L_103 : L_104 ) ;
F_68 ( V_6 , L_109 ,
( ! ! ( F_56 ( V_6 , 0xff ) & 0x10 ) ? L_93 : L_92 ) ) ;
F_68 ( V_6 , L_110 ,
F_18 ( V_6 , 0x01 ) & 0x0f , F_18 ( V_6 , 0x00 ) & 0x3f ,
( F_18 ( V_6 , 0x01 ) & 0x70 ) >> 4 ) ;
F_68 ( V_6 , L_111 ) ;
if ( F_96 ( V_6 , & V_160 ) )
F_68 ( V_6 , L_112 ) ;
else
F_68 ( V_6 , L_113 ,
V_160 . V_165 , V_160 . V_162 , V_160 . V_166 ,
V_160 . V_174 ? L_36 : L_37 ,
V_160 . V_167 , V_160 . V_169 ) ;
if ( F_103 ( V_6 , & V_96 ) )
F_68 ( V_6 , L_114 ) ;
else
F_104 ( V_6 -> V_209 , L_115 ,
& V_96 , true ) ;
F_104 ( V_6 -> V_209 , L_116 ,
& V_2 -> V_96 , true ) ;
if ( F_90 ( V_6 ) )
return 0 ;
F_68 ( V_6 , L_117 ) ;
F_68 ( V_6 , L_118 ,
V_280 [ V_2 -> V_134 ] ) ;
F_68 ( V_6 , L_119 ,
V_279 [ V_275 >> 4 ] ) ;
F_68 ( V_6 , L_120 ,
( V_275 & 0x02 ) ? L_121 : L_122 ,
( V_275 & 0x04 ) ? L_123 : L_124 ,
( ( V_275 & 0x04 ) ^ ( V_275 & 0x01 ) ) ?
L_98 : L_99 ) ;
F_68 ( V_6 , L_125 ,
V_278 [ F_56 ( V_6 , 0xfc ) >> 4 ] ) ;
if ( ! F_66 ( V_6 ) )
return 0 ;
F_68 ( V_6 , L_126 , F_87 ( V_6 ) ? L_53 : L_127 ) ;
F_68 ( V_6 , L_128 ,
( F_50 ( V_6 , 0x00 ) & 0x03 ) + 'A' ) ;
F_68 ( V_6 , L_129 ,
( F_50 ( V_6 , 0x05 ) & 0x40 ) ? L_104 : L_103 ) ;
F_68 ( V_6 , L_130 ,
( F_50 ( V_6 , 0x04 ) & 0x20 ) ? L_131 : L_132 ,
( F_50 ( V_6 , 0x04 ) & 0x10 ) ? L_133 : L_134 ) ;
if ( F_87 ( V_6 ) ) {
bool V_282 = F_50 ( V_6 , 0x04 ) & 0x01 ;
bool V_283 = F_50 ( V_6 , 0x18 ) & 0x01 ;
bool V_284 = F_18 ( V_6 , 0x65 ) & 0x40 ;
F_68 ( V_6 , L_135 ,
V_282 ? L_136 : L_137 ,
V_283 ? L_138 : L_139 ,
V_284 ? L_140 : L_98 ) ;
if ( V_282 && V_283 ) {
F_68 ( V_6 , L_141 ,
( F_50 ( V_6 , 0x07 ) & 0x20 ) ? L_142 : L_143 ) ;
}
F_68 ( V_6 , L_144 , ( F_50 ( V_6 , 0x5b ) << 12 ) +
( F_50 ( V_6 , 0x5c ) << 8 ) +
( F_50 ( V_6 , 0x5d ) & 0xf0 ) ) ;
F_68 ( V_6 , L_145 , ( ( F_50 ( V_6 , 0x5d ) & 0x0f ) << 16 ) +
( F_50 ( V_6 , 0x5e ) << 8 ) +
F_50 ( V_6 , 0x5f ) ) ;
F_68 ( V_6 , L_146 , ( F_50 ( V_6 , 0x04 ) & 0x40 ) ? L_93 : L_92 ) ;
F_68 ( V_6 , L_147 , V_281 [ ( F_50 ( V_6 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_131 ( V_6 ) ;
}
return 0 ;
}
static int F_133 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_89 * V_3 = V_2 -> V_3 ;
struct V_285 * V_234 = & V_2 -> V_234 ;
F_52 ( V_6 , 0x48 ,
( V_234 -> V_286 ? 0x80 : 0 ) |
( V_234 -> V_287 ? 0x40 : 0 ) ) ;
F_110 ( V_6 ) ;
if ( V_234 -> V_288 >= 0 &&
V_234 -> V_288 < V_2 -> V_178 ) {
V_2 -> V_79 = V_234 -> V_288 ;
F_112 ( V_6 ) ;
F_109 ( V_6 ) ;
}
F_19 ( V_6 , 0x0c , 0x42 ) ;
F_19 ( V_6 , 0x0b , 0x44 ) ;
F_58 ( V_6 , 0xcf , 0x01 ) ;
F_20 ( V_6 , 0x02 , 0x0f ,
V_234 -> V_289 << 3 |
V_234 -> V_290 << 2 |
V_234 -> V_291 << 0 ) ;
F_20 ( V_6 , 0x05 , 0x0e , V_234 -> V_292 << 3 |
V_234 -> V_293 << 2 |
V_234 -> V_294 << 1 ) ;
F_119 ( V_2 ) ;
F_58 ( V_6 , 0x69 , 0x30 ) ;
F_19 ( V_6 , 0x06 , 0xa0 | V_234 -> V_295 << 2 |
V_234 -> V_296 << 1 | V_234 -> V_297 ) ;
F_19 ( V_6 , 0x14 , 0x40 | V_234 -> V_298 << 4 |
V_234 -> V_299 << 2 |
V_234 -> V_300 ) ;
F_58 ( V_6 , 0xba , ( V_234 -> V_301 << 1 ) | 0x01 ) ;
F_58 ( V_6 , 0xf3 , 0xdc ) ;
F_58 ( V_6 , 0xf9 , 0x23 ) ;
F_58 ( V_6 , 0x45 , 0x23 ) ;
F_58 ( V_6 , 0xc9 , 0x2d ) ;
F_53 ( V_6 , 0x15 , 0x03 , 0x03 ) ;
F_53 ( V_6 , 0x1a , 0x0e , 0x08 ) ;
F_53 ( V_6 , 0x68 , 0x06 , 0x06 ) ;
F_33 ( V_6 , 0xb5 , 0x01 ) ;
if ( F_1 ( V_2 ) ) {
F_33 ( V_6 , 0x02 , V_234 -> V_302 ) ;
F_20 ( V_6 , 0x30 , 1 << 4 , V_234 -> V_303 << 4 ) ;
}
F_19 ( V_6 , 0x40 , 0xc0 | V_234 -> V_304 ) ;
F_19 ( V_6 , 0x46 , 0x98 ) ;
F_19 ( V_6 , 0x6e , V_3 -> V_254 ) ;
F_19 ( V_6 , 0x73 , V_3 -> V_256 ) ;
V_3 -> V_305 ( V_6 ) ;
return F_134 ( V_6 -> V_306 ) ;
}
static void F_135 ( struct V_5 * V_6 )
{
F_19 ( V_6 , 0x41 , 0xd7 ) ;
}
static void F_136 ( struct V_5 * V_6 )
{
F_19 ( V_6 , 0x41 , 0xd0 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
unsigned int V_27 ;
for ( V_27 = 1 ; V_27 < F_98 ( V_2 -> V_24 ) ; ++ V_27 ) {
if ( V_2 -> V_24 [ V_27 ] )
F_138 ( V_2 -> V_24 [ V_27 ] ) ;
}
}
static struct V_9 * F_139 ( struct V_5 * V_6 ,
T_2 V_16 , T_2 V_307 )
{
struct V_9 * V_10 = F_140 ( V_6 ) ;
if ( V_16 )
F_19 ( V_6 , V_307 , V_16 << 1 ) ;
return F_141 ( V_10 -> V_15 , F_18 ( V_6 , V_307 ) >> 1 ) ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_308 V_309 ;
struct V_310 * V_311 ;
struct V_310 * V_312 ;
unsigned int V_17 ;
V_312 = V_2 -> V_24 [ V_35 ] -> V_313 . V_314 ;
V_311 = F_143 ( V_312 , NULL ) ;
if ( ! V_311 )
return - V_71 ;
F_144 ( V_311 , & V_309 ) ;
F_145 ( V_311 ) ;
V_17 = V_309 . V_315 . V_316 . V_17 ;
if ( V_17 & V_317 )
V_2 -> V_234 . V_296 = 1 ;
if ( V_17 & V_318 )
V_2 -> V_234 . V_295 = 1 ;
if ( V_17 & V_319 )
V_2 -> V_234 . V_297 = 1 ;
if ( V_309 . V_320 == V_321 ) {
V_2 -> V_234 . V_293 = 1 ;
V_2 -> V_234 . V_290 = 1 ;
}
V_2 -> V_234 . V_304 = V_322 ;
V_2 -> V_234 . V_323 [ V_38 ] = 0x42 ;
V_2 -> V_234 . V_323 [ V_39 ] = 0x40 ;
V_2 -> V_234 . V_323 [ V_40 ] = 0x3e ;
V_2 -> V_234 . V_323 [ V_41 ] = 0x38 ;
V_2 -> V_234 . V_323 [ V_42 ] = 0x3c ;
V_2 -> V_234 . V_323 [ V_43 ] = 0x26 ;
V_2 -> V_234 . V_323 [ V_44 ] = 0x32 ;
V_2 -> V_234 . V_323 [ V_45 ] = 0x36 ;
V_2 -> V_234 . V_323 [ V_66 ] = 0x34 ;
V_2 -> V_234 . V_323 [ V_67 ] = 0x30 ;
V_2 -> V_234 . V_323 [ V_68 ] = 0x22 ;
V_2 -> V_234 . V_323 [ V_69 ] = 0x24 ;
V_2 -> V_234 . V_286 = 0 ;
V_2 -> V_234 . V_287 = 0 ;
V_2 -> V_234 . V_288 = - 1 ;
V_2 -> V_234 . V_292 = 1 ;
V_2 -> V_234 . V_291 = 1 ;
V_2 -> V_234 . V_239 = V_324 ;
V_2 -> V_234 . V_235 = V_325 ;
return 0 ;
}
static int F_146 ( struct V_9 * V_10 ,
const struct V_326 * V_144 )
{
static const struct V_95 V_327 =
V_328 ;
struct V_1 * V_2 ;
struct V_329 * V_143 ;
struct V_5 * V_6 ;
unsigned int V_27 ;
T_3 V_36 ;
int V_26 ;
if ( ! F_147 ( V_10 -> V_15 , V_330 ) )
return - V_21 ;
F_148 ( 1 , V_53 , V_10 , L_148 ,
V_10 -> V_16 << 1 ) ;
V_2 = F_149 ( & V_10 -> V_313 , sizeof( * V_2 ) , V_331 ) ;
if ( ! V_2 ) {
F_14 ( V_10 , L_149 ) ;
return - V_332 ;
}
V_2 -> V_24 [ V_35 ] = V_10 ;
V_2 -> V_198 = true ;
V_2 -> V_79 = ~ 0 ;
if ( F_150 ( V_333 ) && V_10 -> V_313 . V_314 ) {
const struct V_334 * V_335 ;
V_335 = F_151 ( V_336 , V_10 -> V_313 . V_314 ) ;
V_2 -> V_3 = V_335 -> V_14 ;
V_26 = F_142 ( V_2 ) ;
if ( V_26 < 0 ) {
F_14 ( V_10 , L_150 ) ;
return V_26 ;
}
} else if ( V_10 -> V_313 . V_337 ) {
struct V_285 * V_234 = V_10 -> V_313 . V_337 ;
V_2 -> V_3 = ( const struct V_89 * ) V_144 -> V_338 ;
V_2 -> V_234 = * V_234 ;
} else {
F_14 ( V_10 , L_151 ) ;
return - V_339 ;
}
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_56 ; ++ V_27 ) {
V_2 -> V_57 [ V_27 ] =
F_152 ( & V_10 -> V_313 , L_152 , V_27 ) ;
if ( F_44 ( V_2 -> V_57 [ V_27 ] ) )
continue;
F_153 ( V_2 -> V_57 [ V_27 ] , 0 ) ;
F_154 ( V_10 , L_153 , V_27 ) ;
}
V_2 -> V_96 = V_327 ;
V_2 -> V_221 = V_75 ( V_2 , V_246 ) ;
V_6 = & V_2 -> V_6 ;
F_155 ( V_6 , V_10 , & V_340 ) ;
snprintf ( V_6 -> V_209 , sizeof( V_6 -> V_209 ) , L_154 ,
V_144 -> V_209 , F_156 ( V_10 -> V_15 ) ,
V_10 -> V_16 ) ;
V_6 -> V_17 |= V_341 ;
if ( V_2 -> V_3 -> type == V_269 ) {
V_36 = F_12 ( V_10 , 0xfb , false ) ;
if ( V_36 != 0x68 ) {
F_68 ( V_6 , L_155 ,
V_10 -> V_16 << 1 ) ;
return - V_339 ;
}
} else {
V_36 = ( F_12 ( V_10 , 0xea , false ) << 8 )
| ( F_12 ( V_10 , 0xeb , false ) << 0 ) ;
if ( V_36 != 0x2051 ) {
F_68 ( V_6 , L_156 ,
V_10 -> V_16 << 1 ) ;
return - V_339 ;
}
}
V_143 = & V_2 -> V_143 ;
F_157 ( V_143 , F_1 ( V_2 ) ? 9 : 8 ) ;
F_158 ( V_143 , & V_342 ,
V_145 , - 128 , 127 , 1 , 0 ) ;
F_158 ( V_143 , & V_342 ,
V_146 , 0 , 255 , 1 , 128 ) ;
F_158 ( V_143 , & V_342 ,
V_147 , 0 , 255 , 1 , 128 ) ;
F_158 ( V_143 , & V_342 ,
V_148 , 0 , 128 , 1 , 0 ) ;
V_2 -> V_90 = F_158 ( V_143 , NULL ,
V_343 , 0 ,
( 1 << V_2 -> V_3 -> V_56 ) - 1 , 0 , 0 ) ;
V_2 -> V_344 =
F_159 ( V_143 , & V_342 ,
V_149 , V_139 ,
0 , V_135 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_345 =
F_160 ( V_143 , & V_346 , NULL ) ;
V_2 -> V_347 =
F_160 ( V_143 , & V_348 , NULL ) ;
V_2 -> V_349 =
F_160 ( V_143 , & V_350 , NULL ) ;
V_6 -> V_306 = V_143 ;
if ( V_143 -> error ) {
V_26 = V_143 -> error ;
goto V_351;
}
V_2 -> V_90 -> V_352 = true ;
V_2 -> V_344 -> V_352 = true ;
if ( F_1 ( V_2 ) )
V_2 -> V_345 -> V_352 = true ;
V_2 -> V_347 -> V_352 = true ;
V_2 -> V_349 -> V_352 = true ;
if ( F_73 ( V_6 ) ) {
V_26 = - V_339 ;
goto V_351;
}
for ( V_27 = 1 ; V_27 < V_353 ; ++ V_27 ) {
if ( ! ( F_46 ( V_27 ) & V_2 -> V_3 -> V_70 ) )
continue;
V_2 -> V_24 [ V_27 ] =
F_139 ( V_6 , V_2 -> V_234 . V_323 [ V_27 ] ,
0xf2 + V_27 ) ;
if ( V_2 -> V_24 [ V_27 ] == NULL ) {
V_26 = - V_332 ;
F_79 ( V_6 , L_157 , V_27 ) ;
goto V_354;
}
}
V_2 -> V_271 = F_161 ( V_10 -> V_209 ) ;
if ( ! V_2 -> V_271 ) {
F_79 ( V_6 , L_158 ) ;
V_26 = - V_332 ;
goto V_354;
}
F_162 ( & V_2 -> V_63 ,
F_48 ) ;
V_2 -> V_178 = V_2 -> V_3 -> V_56
+ ( V_2 -> V_3 -> V_4 ? 2 : 0 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_178 ; ++ V_27 )
V_2 -> V_355 [ V_27 ] . V_17 = V_356 ;
V_2 -> V_355 [ V_2 -> V_178 ] . V_17 = V_357 ;
V_26 = F_163 ( & V_6 -> V_358 , V_2 -> V_178 + 1 ,
V_2 -> V_355 , 0 ) ;
if ( V_26 )
goto V_359;
V_26 = F_133 ( V_6 ) ;
if ( V_26 )
goto V_360;
F_68 ( V_6 , L_159 , V_10 -> V_209 ,
V_10 -> V_16 << 1 , V_10 -> V_15 -> V_209 ) ;
V_26 = F_164 ( V_6 ) ;
if ( V_26 )
goto V_360;
return 0 ;
V_360:
F_165 ( & V_6 -> V_358 ) ;
V_359:
F_166 ( & V_2 -> V_63 ) ;
F_167 ( V_2 -> V_271 ) ;
V_354:
F_137 ( V_2 ) ;
V_351:
F_168 ( V_143 ) ;
return V_26 ;
}
static int F_169 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = F_170 ( V_10 ) ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_166 ( & V_2 -> V_63 ) ;
F_167 ( V_2 -> V_271 ) ;
F_171 ( V_6 ) ;
F_172 ( V_6 ) ;
F_165 ( & V_6 -> V_358 ) ;
F_137 ( F_2 ( V_6 ) ) ;
F_168 ( V_6 -> V_306 ) ;
return 0 ;
}
