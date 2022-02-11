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
V_75 ( struct V_1 * V_2 , enum V_76 V_77 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_78 ; ++ V_27 ) {
if ( V_2 -> V_3 -> V_79 [ V_27 ] . V_77 == V_77 )
return & V_2 -> V_3 -> V_79 [ V_27 ] ;
}
return NULL ;
}
static inline bool F_65 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_80 == V_81 ||
V_2 -> V_80 == V_82 ;
}
static inline bool F_66 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
return V_2 -> V_80 == V_83 ||
V_2 -> V_80 == V_84 ||
V_2 -> V_80 == V_85 ||
V_2 -> V_80 == V_86 ;
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
struct V_87 * V_34 )
{
int V_88 ;
V_88 = F_62 ( V_6 , V_34 -> V_34 ) ;
if ( V_88 < 0 ) {
F_68 ( V_6 , L_18 , V_34 -> V_34 ) ;
F_67 ( V_6 ) ;
return V_88 ;
}
V_34 -> V_89 = 1 ;
V_34 -> V_36 = V_88 ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 ,
const struct V_87 * V_34 )
{
int V_88 ;
V_88 = F_63 ( V_6 , V_34 -> V_34 , V_34 -> V_36 ) ;
if ( V_88 < 0 ) {
F_68 ( V_6 , L_18 , V_34 -> V_34 ) ;
F_67 ( V_6 ) ;
return V_88 ;
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
const struct V_90 * V_3 = V_2 -> V_3 ;
return F_74 ( V_2 -> V_91 ,
V_3 -> V_92 ( V_6 ) ) ;
}
static int F_75 ( struct V_5 * V_6 ,
T_2 V_93 ,
const struct V_94 * V_95 ,
const struct V_96 * V_97 )
{
int V_27 ;
for ( V_27 = 0 ; V_95 [ V_27 ] . V_97 . V_98 . V_99 ; V_27 ++ ) {
if ( ! F_76 ( V_97 , & V_95 [ V_27 ] . V_97 ,
F_66 ( V_6 ) ? 250000 : 1000000 ) )
continue;
F_19 ( V_6 , 0x00 , V_95 [ V_27 ] . V_100 ) ;
F_19 ( V_6 , 0x01 , ( V_95 [ V_27 ] . V_101 << 4 ) +
V_93 ) ;
return 0 ;
}
return - 1 ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_96 * V_97 )
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
0x01 , V_102 , V_97 ) ;
if ( V_26 )
V_26 = F_75 ( V_6 ,
0x02 , V_103 , V_97 ) ;
} else if ( F_66 ( V_6 ) ) {
V_26 = F_75 ( V_6 ,
0x05 , V_104 , V_97 ) ;
if ( V_26 )
V_26 = F_75 ( V_6 ,
0x06 , V_105 , V_97 ) ;
} else {
F_42 ( 2 , V_53 , V_6 , L_20 ,
V_54 , V_2 -> V_80 ) ;
V_26 = - 1 ;
}
return V_26 ;
}
static void F_78 ( struct V_5 * V_6 ,
const struct V_7 * V_98 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_99 = F_6 ( V_98 ) ;
T_4 V_106 = F_10 ( V_98 ) ;
T_3 V_107 = V_98 -> V_108 + V_98 -> V_109 - 4 ;
T_3 V_110 = V_99 - V_98 -> V_111 ;
T_3 V_112 = V_106 - V_98 -> V_113 ;
T_3 V_114 = V_98 -> V_115 + V_98 -> V_116 ;
T_3 V_117 = ( ( ( T_4 ) V_98 -> V_118 / 100 ) > 0 ) ?
( ( V_99 * ( V_119 / 100 ) ) / ( ( T_4 ) V_98 -> V_118 / 100 ) ) : 0 ;
const T_2 V_120 [ 2 ] = {
0xc0 | ( ( V_99 >> 8 ) & 0x1f ) ,
V_99 & 0xff
} ;
F_42 ( 2 , V_53 , V_6 , L_21 , V_54 ) ;
if ( F_65 ( V_6 ) ) {
F_19 ( V_6 , 0x00 , 0x07 ) ;
F_19 ( V_6 , 0x01 , 0x02 ) ;
F_59 ( V_6 , 0x81 , 0x10 , 0x10 ) ;
if ( F_17 ( V_2 , V_35 ,
0x16 , 2 , V_120 ) )
F_79 ( V_6 , L_22 ) ;
F_58 ( V_6 , 0xa2 , ( V_107 >> 4 ) & 0xff ) ;
F_58 ( V_6 , 0xa3 , ( ( V_107 & 0x0f ) << 4 ) |
( ( V_110 >> 8 ) & 0x0f ) ) ;
F_58 ( V_6 , 0xa4 , V_110 & 0xff ) ;
F_58 ( V_6 , 0xa5 , ( V_112 >> 4 ) & 0xff ) ;
F_58 ( V_6 , 0xa6 , ( ( V_112 & 0xf ) << 4 ) |
( ( V_114 >> 8 ) & 0xf ) ) ;
F_58 ( V_6 , 0xa7 , V_114 & 0xff ) ;
} else if ( F_66 ( V_6 ) ) {
F_19 ( V_6 , 0x00 , 0x02 ) ;
F_19 ( V_6 , 0x01 , 0x06 ) ;
} else {
F_42 ( 2 , V_53 , V_6 , L_20 ,
V_54 , V_2 -> V_80 ) ;
}
F_58 ( V_6 , 0x8f , ( V_117 >> 8 ) & 0x7 ) ;
F_58 ( V_6 , 0x90 , V_117 & 0xff ) ;
F_58 ( V_6 , 0xab , ( V_106 >> 4 ) & 0xff ) ;
F_58 ( V_6 , 0xac , ( V_106 & 0x0f ) << 4 ) ;
}
static void F_80 ( struct V_5 * V_6 , bool V_121 , T_3 V_122 , T_3 V_123 , T_3 V_124 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 V_125 [ 4 ] ;
if ( V_121 ) {
V_122 = 0x3ff ;
V_123 = 0x3ff ;
V_124 = 0x3ff ;
}
F_42 ( 2 , V_53 , V_6 , L_23 ,
V_54 , V_121 ? L_24 : L_25 ,
V_122 , V_123 , V_124 ) ;
V_125 [ 0 ] = ( F_56 ( V_6 , 0x77 ) & 0xc0 ) | ( ( V_122 & 0x3f0 ) >> 4 ) ;
V_125 [ 1 ] = ( ( V_122 & 0x00f ) << 4 ) | ( ( V_123 & 0x3c0 ) >> 6 ) ;
V_125 [ 2 ] = ( ( V_123 & 0x03f ) << 2 ) | ( ( V_124 & 0x300 ) >> 8 ) ;
V_125 [ 3 ] = V_124 & 0x0ff ;
if ( F_17 ( V_2 , V_68 ,
0x77 , 4 , V_125 ) )
F_79 ( V_6 , L_26 , V_54 ) ;
}
static void F_81 ( struct V_5 * V_6 , bool V_126 , T_3 V_127 , T_3 V_128 , T_3 V_129 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 V_130 [ 4 ] ;
T_2 V_131 = 1 ;
T_2 V_132 = 1 ;
if ( V_126 ) {
V_131 = 0 ;
V_132 = 0 ;
V_127 = 0x100 ;
V_128 = 0x100 ;
V_129 = 0x100 ;
}
F_42 ( 2 , V_53 , V_6 , L_27 ,
V_54 , V_126 ? L_24 : L_25 ,
V_127 , V_128 , V_129 ) ;
V_130 [ 0 ] = ( ( V_131 << 7 ) | ( V_132 << 6 ) | ( ( V_127 & 0x3f0 ) >> 4 ) ) ;
V_130 [ 1 ] = ( ( ( V_127 & 0x00f ) << 4 ) | ( ( V_128 & 0x3c0 ) >> 6 ) ) ;
V_130 [ 2 ] = ( ( ( V_128 & 0x03f ) << 2 ) | ( ( V_129 & 0x300 ) >> 8 ) ) ;
V_130 [ 3 ] = ( ( V_129 & 0x0ff ) ) ;
if ( F_17 ( V_2 , V_68 ,
0x73 , 4 , V_130 ) )
F_79 ( V_6 , L_28 , V_54 ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
bool V_133 = F_18 ( V_6 , 0x02 ) & 0x02 ;
bool V_134 = F_50 ( V_6 , 0x05 ) & 0x80 ;
F_42 ( 2 , V_53 , V_6 , L_29 ,
V_54 , V_2 -> V_135 ,
V_133 , V_134 ) ;
F_81 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
F_80 ( V_6 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_2 -> V_135 ) {
case V_136 :
if ( V_2 -> V_80 == V_81 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
break;
}
if ( V_2 -> V_80 == V_82 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_134 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0xf0 ) ;
break;
}
if ( V_2 -> V_97 . V_98 . V_137 & V_138 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
} else {
F_20 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_66 ( V_6 ) && V_133 ) {
F_80 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_81 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_80 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_139 :
if ( V_2 -> V_80 == V_82 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0x20 ) ;
break;
}
F_20 ( V_6 , 0x02 , 0xf0 , 0x00 ) ;
break;
case V_140 :
if ( V_2 -> V_80 == V_82 ) {
F_20 ( V_6 , 0x02 , 0xf0 , 0x60 ) ;
break;
}
F_20 ( V_6 , 0x02 , 0xf0 , 0x10 ) ;
if ( F_65 ( V_6 ) || V_134 )
break;
if ( V_133 ) {
F_80 ( V_6 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_81 ( V_6 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_80 ( V_6 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_83 ( struct V_141 * V_142 )
{
struct V_5 * V_6 =
& F_3 ( V_142 -> V_143 , struct V_1 , V_144 ) -> V_6 ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
switch ( V_142 -> V_145 ) {
case V_146 :
F_58 ( V_6 , 0x3c , V_142 -> V_36 ) ;
return 0 ;
case V_147 :
F_58 ( V_6 , 0x3a , V_142 -> V_36 ) ;
return 0 ;
case V_148 :
F_58 ( V_6 , 0x3b , V_142 -> V_36 ) ;
return 0 ;
case V_149 :
F_58 ( V_6 , 0x3d , V_142 -> V_36 ) ;
return 0 ;
case V_150 :
V_2 -> V_135 = V_142 -> V_36 ;
F_82 ( V_6 ) ;
return 0 ;
case V_151 :
if ( ! F_1 ( V_2 ) )
return - V_71 ;
F_33 ( V_6 , 0xc8 , V_142 -> V_36 ) ;
return 0 ;
case V_152 :
F_59 ( V_6 , 0xbf , 0x04 , V_142 -> V_36 << 2 ) ;
return 0 ;
case V_153 :
F_58 ( V_6 , 0xc0 , ( V_142 -> V_36 & 0xff0000 ) >> 16 ) ;
F_58 ( V_6 , 0xc1 , ( V_142 -> V_36 & 0x00ff00 ) >> 8 ) ;
F_58 ( V_6 , 0xc2 , ( T_2 ) ( V_142 -> V_36 & 0x0000ff ) ) ;
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
return ! ( F_18 ( V_6 , 0x6a ) & ( 0x10 >> V_2 -> V_80 ) ) ;
}
static inline bool F_86 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_90 * V_3 = V_2 -> V_3 ;
return ( F_18 ( V_6 , 0x6a ) & V_3 -> V_154 ) != V_3 -> V_154 ;
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
bool V_88 ;
V_88 = F_84 ( V_6 ) ;
V_88 |= F_89 ( V_6 ) ;
V_88 |= F_88 ( V_6 ) ;
if ( F_66 ( V_6 ) ) {
V_88 |= F_86 ( V_6 ) ;
V_88 |= F_85 ( V_6 ) ;
}
return V_88 ;
}
static inline bool F_91 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( ! F_1 ( V_2 ) )
return false ;
return F_18 ( V_6 , 0x12 ) & 0x01 ;
}
static int F_92 ( struct V_5 * V_6 , T_4 * V_155 )
{
* V_155 = 0 ;
* V_155 |= F_84 ( V_6 ) ? V_156 : 0 ;
* V_155 |= F_90 ( V_6 ) ? V_157 : 0 ;
if ( F_91 ( V_6 ) )
* V_155 |= F_66 ( V_6 ) ? V_158 : V_159 ;
F_42 ( 1 , V_53 , V_6 , L_30 , V_54 , * V_155 ) ;
return 0 ;
}
static int F_93 ( struct V_5 * V_6 ,
struct V_160 * V_161 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_4 V_162 = ( V_119 * 8 ) / V_161 -> V_163 ;
T_4 V_164 ;
int V_27 ;
for ( V_27 = 0 ; V_165 [ V_27 ] . V_98 . V_106 ; V_27 ++ ) {
if ( F_10 ( & V_165 [ V_27 ] . V_98 ) != V_161 -> V_166 + 1 )
continue;
if ( V_165 [ V_27 ] . V_98 . V_115 != V_161 -> V_167 )
continue;
V_164 = V_162 * F_6 ( & V_165 [ V_27 ] . V_98 ) ;
if ( ( V_164 < V_165 [ V_27 ] . V_98 . V_118 + 1000000 ) &&
( V_164 > V_165 [ V_27 ] . V_98 . V_118 - 1000000 ) ) {
* V_97 = V_165 [ V_27 ] ;
return 0 ;
}
}
if ( F_94 ( V_161 -> V_166 + 1 , V_162 , V_161 -> V_167 ,
( V_161 -> V_168 == '+' ? V_169 : 0 ) |
( V_161 -> V_170 == '+' ? V_171 : 0 ) ,
V_97 ) )
return 0 ;
if ( F_95 ( V_161 -> V_166 + 1 , V_162 , V_161 -> V_167 ,
( V_161 -> V_168 == '+' ? V_169 : 0 ) |
( V_161 -> V_170 == '+' ? V_171 : 0 ) ,
V_2 -> V_172 , V_97 ) )
return 0 ;
F_42 ( 2 , V_53 , V_6 ,
L_31 ,
V_54 , V_161 -> V_167 , V_161 -> V_166 , V_161 -> V_163 ,
V_161 -> V_168 , V_161 -> V_170 ) ;
return - 1 ;
}
static int F_96 ( struct V_5 * V_6 , struct V_160 * V_161 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_90 * V_3 = V_2 -> V_3 ;
T_2 V_173 ;
if ( F_89 ( V_6 ) || F_88 ( V_6 ) ) {
F_42 ( 2 , V_53 , V_6 , L_32 , V_54 ) ;
return - 1 ;
}
V_161 -> V_163 = F_57 ( V_6 , 0xb1 , 0x3fff ) ;
V_161 -> V_166 = F_57 ( V_6 , V_3 -> V_174 , 0x7ff ) ;
V_161 -> V_167 = F_56 ( V_6 , 0xb3 ) >> 3 ;
V_161 -> V_175 = F_18 ( V_6 , 0x12 ) & 0x10 ;
if ( F_1 ( V_2 ) ) {
V_173 = F_56 ( V_6 , 0xb5 ) ;
if ( ( V_173 & 0x03 ) == 0x01 ) {
V_161 -> V_168 = V_173 & 0x10
? ( V_173 & 0x08 ? '+' : '-' ) : 'x' ;
V_161 -> V_170 = V_173 & 0x40
? ( V_173 & 0x20 ? '+' : '-' ) : 'x' ;
} else {
V_161 -> V_168 = 'x' ;
V_161 -> V_170 = 'x' ;
}
} else {
V_173 = F_50 ( V_6 , 0x05 ) ;
V_161 -> V_168 = V_173 & 0x20 ? '+' : '-' ;
V_161 -> V_170 = V_173 & 0x10 ? '+' : '-' ;
}
if ( F_89 ( V_6 ) || F_88 ( V_6 ) ) {
F_42 ( 2 , V_53 , V_6 ,
L_33 , V_54 ) ;
return - 1 ;
}
if ( V_161 -> V_166 < 239 || V_161 -> V_163 < 8 || V_161 -> V_163 == 0x3fff ) {
F_42 ( 2 , V_53 , V_6 , L_34 , V_54 ) ;
memset ( V_161 , 0 , sizeof( struct V_160 ) ) ;
return - 1 ;
}
F_42 ( 2 , V_53 , V_6 ,
L_35 ,
V_54 , V_161 -> V_166 , V_161 -> V_163 , V_161 -> V_167 ,
V_161 -> V_168 , V_161 -> V_170 ,
V_161 -> V_175 ? L_36 : L_37 ) ;
return 0 ;
}
static int F_97 ( struct V_5 * V_6 ,
struct V_176 * V_97 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_97 -> V_177 >= F_98 ( V_165 ) - 1 )
return - V_71 ;
if ( V_97 -> V_178 >= V_2 -> V_179 )
return - V_71 ;
memset ( V_97 -> V_180 , 0 , sizeof( V_97 -> V_180 ) ) ;
V_97 -> V_97 = V_165 [ V_97 -> V_177 ] ;
return 0 ;
}
static int F_99 ( struct V_5 * V_6 ,
struct V_181 * V_182 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_182 -> V_178 >= V_2 -> V_179 )
return - V_71 ;
V_182 -> type = V_183 ;
V_182 -> V_98 . V_184 = 1920 ;
V_182 -> V_98 . V_185 = 1200 ;
V_182 -> V_98 . V_186 = 25000000 ;
switch ( V_182 -> V_178 ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_182 -> V_98 . V_187 = 225000000 ;
break;
case V_81 :
case V_82 :
default:
V_182 -> V_98 . V_187 = 170000000 ;
break;
}
V_182 -> V_98 . V_137 = V_138 | V_188 |
V_189 | V_190 ;
V_182 -> V_98 . V_191 = V_192 |
V_193 | V_194 ;
return 0 ;
}
static void F_100 ( struct V_5 * V_6 ,
struct V_96 * V_97 )
{
int V_27 ;
for ( V_27 = 0 ; V_165 [ V_27 ] . V_98 . V_99 ; V_27 ++ ) {
if ( F_76 ( V_97 , & V_165 [ V_27 ] ,
F_66 ( V_6 ) ? 250000 : 1000000 ) ) {
* V_97 = V_165 [ V_27 ] ;
break;
}
}
}
static unsigned int F_101 ( struct V_5 * V_6 )
{
unsigned int V_195 ;
int V_196 , V_197 ;
V_196 = F_50 ( V_6 , 0x06 ) ;
V_197 = F_50 ( V_6 , 0x3b ) ;
if ( V_196 < 0 || V_197 < 0 )
return 0 ;
V_195 = V_196 * 1000000 + ( ( V_197 & 0x30 ) >> 4 ) * 250000 ;
if ( F_87 ( V_6 ) ) {
unsigned V_198 = ( ( F_50 ( V_6 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_195 = V_195 * 8 / V_198 ;
}
return V_195 ;
}
static unsigned int F_102 ( struct V_5 * V_6 )
{
int V_196 , V_197 ;
V_196 = F_50 ( V_6 , 0x51 ) ;
V_197 = F_50 ( V_6 , 0x52 ) ;
if ( V_196 < 0 || V_197 < 0 )
return 0 ;
return ( ( V_196 << 1 ) | ( V_197 >> 7 ) ) * 1000000 + ( V_197 & 0x7f ) * 1000000 / 128 ;
}
static int F_103 ( struct V_5 * V_6 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_90 * V_3 = V_2 -> V_3 ;
struct V_7 * V_98 = & V_97 -> V_98 ;
struct V_160 V_161 ;
if ( ! V_97 )
return - V_71 ;
memset ( V_97 , 0 , sizeof( struct V_96 ) ) ;
if ( F_90 ( V_6 ) ) {
V_2 -> V_199 = true ;
F_42 ( 1 , V_53 , V_6 , L_38 , V_54 ) ;
return - V_200 ;
}
if ( F_96 ( V_6 , & V_161 ) ) {
F_42 ( 1 , V_53 , V_6 , L_39 , V_54 ) ;
return - V_200 ;
}
V_98 -> V_175 = V_161 . V_175 ?
V_201 : V_202 ;
if ( F_66 ( V_6 ) ) {
V_97 -> type = V_183 ;
V_98 -> V_99 = F_51 ( V_6 , 0x07 , 0xfff ) ;
V_98 -> V_106 = F_51 ( V_6 , 0x09 , 0xfff ) ;
V_98 -> V_118 = V_3 -> V_203 ( V_6 ) ;
V_98 -> V_111 = F_51 ( V_6 , 0x20 , 0x3ff ) ;
V_98 -> V_108 = F_51 ( V_6 , 0x22 , 0x3ff ) ;
V_98 -> V_109 = F_51 ( V_6 , 0x24 , 0x3ff ) ;
V_98 -> V_113 = F_51 ( V_6 , 0x2a , 0x1fff ) / 2 ;
V_98 -> V_115 = F_51 ( V_6 , 0x2e , 0x1fff ) / 2 ;
V_98 -> V_116 = F_51 ( V_6 , 0x32 , 0x1fff ) / 2 ;
V_98 -> V_204 = ( ( F_50 ( V_6 , 0x05 ) & 0x10 ) ? V_171 : 0 ) |
( ( F_50 ( V_6 , 0x05 ) & 0x20 ) ? V_169 : 0 ) ;
if ( V_98 -> V_175 == V_201 ) {
V_98 -> V_106 += F_51 ( V_6 , 0x0b , 0xfff ) ;
V_98 -> V_205 = F_51 ( V_6 , 0x2c , 0x1fff ) / 2 ;
V_98 -> V_206 = F_51 ( V_6 , 0x30 , 0x1fff ) / 2 ;
V_98 -> V_207 = F_51 ( V_6 , 0x34 , 0x1fff ) / 2 ;
}
F_100 ( V_6 , V_97 ) ;
} else {
if ( ! F_93 ( V_6 , & V_161 , V_97 ) )
goto V_208;
V_161 . V_167 += 1 ;
F_42 ( 1 , V_53 , V_6 , L_40 , V_54 , V_161 . V_167 ) ;
if ( ! F_93 ( V_6 , & V_161 , V_97 ) )
goto V_208;
V_161 . V_167 -= 2 ;
F_42 ( 1 , V_53 , V_6 , L_41 , V_54 , V_161 . V_167 ) ;
if ( F_93 ( V_6 , & V_161 , V_97 ) ) {
if ( V_2 -> V_199 ) {
F_42 ( 1 , V_53 , V_6 , L_42 , V_54 ) ;
F_59 ( V_6 , 0x86 , 0x06 , 0x00 ) ;
F_59 ( V_6 , 0x86 , 0x06 , 0x04 ) ;
F_59 ( V_6 , 0x86 , 0x06 , 0x02 ) ;
V_2 -> V_199 = false ;
return - V_200 ;
}
F_42 ( 1 , V_53 , V_6 , L_43 , V_54 ) ;
return - V_209 ;
}
V_2 -> V_199 = true ;
}
V_208:
if ( F_90 ( V_6 ) ) {
F_42 ( 1 , V_53 , V_6 , L_44 , V_54 ) ;
memset ( V_97 , 0 , sizeof( struct V_96 ) ) ;
return - V_200 ;
}
if ( ( F_65 ( V_6 ) && V_98 -> V_118 > 170000000 ) ||
( F_66 ( V_6 ) && V_98 -> V_118 > 225000000 ) ) {
F_42 ( 1 , V_53 , V_6 , L_45 ,
V_54 , ( T_4 ) V_98 -> V_118 ) ;
return - V_209 ;
}
if ( V_53 > 1 )
F_104 ( V_6 -> V_210 , L_46 ,
V_97 , true ) ;
return 0 ;
}
static int F_105 ( struct V_5 * V_6 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
struct V_7 * V_98 ;
int V_26 ;
if ( ! V_97 )
return - V_71 ;
if ( F_76 ( & V_2 -> V_97 , V_97 , 0 ) ) {
F_42 ( 1 , V_53 , V_6 , L_47 , V_54 ) ;
return 0 ;
}
V_98 = & V_97 -> V_98 ;
if ( ( F_65 ( V_6 ) && V_98 -> V_118 > 170000000 ) ||
( F_66 ( V_6 ) && V_98 -> V_118 > 225000000 ) ) {
F_42 ( 1 , V_53 , V_6 , L_45 ,
V_54 , ( T_4 ) V_98 -> V_118 ) ;
return - V_209 ;
}
F_100 ( V_6 , V_97 ) ;
V_2 -> V_97 = * V_97 ;
F_59 ( V_6 , 0x91 , 0x40 , V_98 -> V_175 ? 0x40 : 0x00 ) ;
V_26 = F_77 ( V_6 , V_97 ) ;
if ( V_26 ) {
F_78 ( V_6 , V_98 ) ;
}
F_82 ( V_6 ) ;
if ( V_53 > 1 )
F_104 ( V_6 -> V_210 , L_48 ,
V_97 , true ) ;
return 0 ;
}
static int F_106 ( struct V_5 * V_6 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
* V_97 = V_2 -> V_97 ;
return 0 ;
}
static void F_107 ( struct V_5 * V_6 , bool V_211 )
{
F_52 ( V_6 , 0x01 , V_211 ? 0x00 : 0x78 ) ;
}
static void F_108 ( struct V_5 * V_6 , bool V_211 )
{
F_52 ( V_6 , 0x83 , V_211 ? 0xfe : 0xff ) ;
}
static void F_109 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( F_65 ( V_6 ) ) {
F_19 ( V_6 , 0x15 , 0xb0 ) ;
} else if ( F_66 ( V_6 ) ) {
F_53 ( V_6 , 0x00 , 0x03 , V_2 -> V_80 ) ;
V_2 -> V_3 -> V_212 ( V_6 , true ) ;
F_19 ( V_6 , 0x15 , 0xa0 ) ;
F_53 ( V_6 , 0x1a , 0x10 , 0x00 ) ;
} else {
F_42 ( 2 , V_53 , V_6 , L_20 ,
V_54 , V_2 -> V_80 ) ;
}
}
static void F_110 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_53 ( V_6 , 0x1a , 0x10 , 0x10 ) ;
F_111 ( 16 ) ;
F_19 ( V_6 , 0x15 , 0xbe ) ;
V_2 -> V_3 -> V_212 ( V_6 , false ) ;
}
static void F_112 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_90 * V_3 = V_2 -> V_3 ;
if ( F_65 ( V_6 ) ) {
F_64 ( V_6 , V_3 -> V_213 [ 0 ] ) ;
F_33 ( V_6 , 0x00 , 0x08 ) ;
F_33 ( V_6 , 0x01 , 0x06 ) ;
F_33 ( V_6 , 0xc8 , 0x00 ) ;
} else if ( F_66 ( V_6 ) ) {
F_52 ( V_6 , 0x00 , V_2 -> V_80 & 0x03 ) ;
F_64 ( V_6 , V_3 -> V_213 [ 1 ] ) ;
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
V_54 , V_2 -> V_80 ) ;
}
}
static int F_113 ( struct V_5 * V_6 ,
T_4 V_214 , T_4 V_215 , T_4 V_216 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_42 ( 2 , V_53 , V_6 , L_49 ,
V_54 , V_214 , V_2 -> V_80 ) ;
if ( V_214 == V_2 -> V_80 )
return 0 ;
if ( V_214 > V_2 -> V_3 -> V_217 )
return - V_71 ;
V_2 -> V_80 = V_214 ;
F_110 ( V_6 ) ;
F_112 ( V_6 ) ;
F_109 ( V_6 ) ;
return 0 ;
}
static int F_114 ( struct V_5 * V_6 ,
struct V_218 * V_219 ,
struct V_220 * V_77 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_77 -> V_177 >= V_2 -> V_3 -> V_78 )
return - V_71 ;
V_77 -> V_77 = V_2 -> V_3 -> V_79 [ V_77 -> V_177 ] . V_77 ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_221 * V_222 )
{
memset ( V_222 , 0 , sizeof( * V_222 ) ) ;
V_222 -> V_99 = V_2 -> V_97 . V_98 . V_99 ;
V_222 -> V_106 = V_2 -> V_97 . V_98 . V_106 ;
V_222 -> V_223 = V_224 ;
if ( V_2 -> V_97 . V_98 . V_137 & V_138 )
V_222 -> V_225 = ( V_2 -> V_97 . V_98 . V_106 <= 576 ) ?
V_226 : V_227 ;
}
static unsigned int F_116 ( struct V_1 * V_2 )
{
#define F_117 ( V_196 , V_197 , T_5 , T_6 , T_7 , T_8 ) { \
ADV7604_OP_CH_SEL_##a, ADV7604_OP_CH_SEL_##b, ADV7604_OP_CH_SEL_##c, \
ADV7604_OP_CH_SEL_##d, ADV7604_OP_CH_SEL_##e, ADV7604_OP_CH_SEL_##f }
#define F_118 ( T_9 ) [ADV7604_BUS_ORDER_##x]
static const unsigned int V_228 [ 6 ] [ 6 ] = {
F_118 ( V_229 ) = F_117 ( V_230 , V_231 , V_232 , V_229 , V_233 , V_234 ) ,
F_118 ( V_231 ) = F_117 ( V_232 , V_229 , V_230 , V_231 , V_234 , V_233 ) ,
F_118 ( V_234 ) = F_117 ( V_231 , V_230 , V_233 , V_234 , V_232 , V_229 ) ,
F_118 ( V_232 ) = F_117 ( V_234 , V_233 , V_229 , V_232 , V_231 , V_230 ) ,
F_118 ( V_233 ) = F_117 ( V_233 , V_234 , V_231 , V_230 , V_229 , V_232 ) ,
F_118 ( V_230 ) = F_117 ( V_229 , V_232 , V_234 , V_233 , V_230 , V_231 ) ,
} ;
return V_228 [ V_2 -> V_235 . V_236 ] [ V_2 -> V_222 -> V_228 >> 5 ] ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_20 ( V_6 , 0x02 , 0x02 ,
V_2 -> V_222 -> V_237 ? V_238 : 0 ) ;
F_19 ( V_6 , 0x03 , V_2 -> V_222 -> V_239 |
V_2 -> V_235 . V_240 ) ;
F_20 ( V_6 , 0x04 , 0xe0 , F_116 ( V_2 ) ) ;
F_20 ( V_6 , 0x05 , 0x01 ,
V_2 -> V_222 -> V_241 ? V_242 : 0 ) ;
}
static int F_120 ( struct V_5 * V_6 , struct V_218 * V_219 ,
struct V_243 * V_222 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
if ( V_222 -> V_178 != V_2 -> V_179 )
return - V_71 ;
F_115 ( V_2 , & V_222 -> V_222 ) ;
if ( V_222 -> V_244 == V_245 ) {
struct V_221 * V_246 ;
V_246 = F_121 ( V_219 , V_222 -> V_178 ) ;
V_222 -> V_222 . V_77 = V_246 -> V_77 ;
} else {
V_222 -> V_222 . V_77 = V_2 -> V_222 -> V_77 ;
}
return 0 ;
}
static int F_122 ( struct V_5 * V_6 , struct V_218 * V_219 ,
struct V_243 * V_222 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_75 * V_3 ;
if ( V_222 -> V_178 != V_2 -> V_179 )
return - V_71 ;
V_3 = V_75 ( V_2 , V_222 -> V_222 . V_77 ) ;
if ( V_3 == NULL )
V_3 = V_75 ( V_2 , V_247 ) ;
F_115 ( V_2 , & V_222 -> V_222 ) ;
V_222 -> V_222 . V_77 = V_3 -> V_77 ;
if ( V_222 -> V_244 == V_245 ) {
struct V_221 * V_246 ;
V_246 = F_121 ( V_219 , V_222 -> V_178 ) ;
V_246 -> V_77 = V_222 -> V_222 . V_77 ;
} else {
V_2 -> V_222 = V_3 ;
F_119 ( V_2 ) ;
}
return 0 ;
}
static int F_123 ( struct V_5 * V_6 , T_4 V_155 , bool * V_248 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_90 * V_3 = V_2 -> V_3 ;
const T_2 V_249 = F_18 ( V_6 , 0x43 ) ;
const T_2 V_250 = F_18 ( V_6 , 0x6b ) ;
const T_2 V_251 = F_18 ( V_6 , 0x70 ) ;
T_2 V_252 ;
T_2 V_253 ;
T_2 V_254 ;
if ( V_249 )
F_19 ( V_6 , 0x44 , V_249 ) ;
if ( V_251 )
F_19 ( V_6 , 0x71 , V_251 ) ;
if ( V_250 )
F_19 ( V_6 , 0x6c , V_250 ) ;
F_42 ( 2 , V_53 , V_6 , L_50 , V_54 ) ;
V_253 = V_249 & 0x98 ;
V_252 = F_66 ( V_6 )
? V_250 & V_3 -> V_255
: 0 ;
if ( V_253 || V_252 ) {
F_42 ( 1 , V_53 , V_6 ,
L_51 ,
V_54 , V_253 , V_252 ) ;
F_47 ( V_6 , V_256 , NULL ) ;
if ( V_248 )
* V_248 = true ;
}
if ( V_250 & 0x01 ) {
F_42 ( 1 , V_53 , V_6 , L_52 , V_54 ,
( F_18 ( V_6 , 0x6a ) & 0x01 ) ? L_53 : L_54 ) ;
F_82 ( V_6 ) ;
if ( V_248 )
* V_248 = true ;
}
V_254 = F_18 ( V_6 , 0x70 ) & V_3 -> V_257 ;
if ( V_254 ) {
F_42 ( 1 , V_53 , V_6 , L_55 , V_54 , V_254 ) ;
F_19 ( V_6 , 0x71 , V_254 ) ;
F_73 ( V_6 ) ;
if ( V_248 )
* V_248 = true ;
}
return 0 ;
}
static int F_124 ( struct V_5 * V_6 , struct V_258 * V_64 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
T_2 * V_14 = NULL ;
if ( V_64 -> V_178 > V_86 )
return - V_71 ;
if ( V_64 -> V_259 == 0 )
return - V_71 ;
if ( V_64 -> V_259 > 2 )
return - V_71 ;
if ( V_64 -> V_260 > 1 )
return - V_71 ;
if ( V_64 -> V_260 == 1 )
V_64 -> V_259 = 1 ;
if ( V_64 -> V_259 > V_2 -> V_64 . V_259 )
V_64 -> V_259 = V_2 -> V_64 . V_259 ;
switch ( V_64 -> V_178 ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
if ( V_2 -> V_64 . V_65 & ( 1 << V_64 -> V_178 ) )
V_14 = V_2 -> V_64 . V_64 ;
break;
default:
return - V_71 ;
break;
}
if ( ! V_14 )
return - V_261 ;
memcpy ( V_64 -> V_64 ,
V_14 + V_64 -> V_260 * 128 ,
V_64 -> V_259 * 128 ) ;
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
int V_262 = 0x80 + T_6 ;
do {
T_2 V_263 = V_64 [ V_27 ] >> 5 ;
T_2 V_46 = V_64 [ V_27 ] & 0x1f ;
if ( ( V_263 == 3 ) && ( V_46 >= 5 ) )
return V_27 + 4 ;
V_27 += V_46 + 1 ;
} while ( V_27 < V_262 );
}
return - 1 ;
}
static int F_126 ( struct V_5 * V_6 , struct V_258 * V_64 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_90 * V_3 = V_2 -> V_3 ;
int V_264 ;
int V_26 ;
int V_27 ;
if ( V_64 -> V_178 > V_86 )
return - V_71 ;
if ( V_64 -> V_260 != 0 )
return - V_71 ;
if ( V_64 -> V_259 == 0 ) {
V_2 -> V_64 . V_65 &= ~ ( 1 << V_64 -> V_178 ) ;
F_43 ( V_2 , V_2 -> V_64 . V_65 ) ;
F_36 ( V_6 , V_3 -> V_265 , 0x0f , V_2 -> V_64 . V_65 ) ;
V_2 -> V_172 . V_266 = 16 ;
V_2 -> V_172 . V_267 = 9 ;
if ( ! V_2 -> V_64 . V_65 )
V_2 -> V_64 . V_259 = 0 ;
F_42 ( 2 , V_53 , V_6 , L_56 ,
V_54 , V_64 -> V_178 , V_2 -> V_64 . V_65 ) ;
return 0 ;
}
if ( V_64 -> V_259 > 2 ) {
V_64 -> V_259 = 2 ;
return - V_268 ;
}
F_42 ( 2 , V_53 , V_6 , L_57 ,
V_54 , V_64 -> V_178 , V_2 -> V_64 . V_65 ) ;
F_127 ( & V_2 -> V_63 ) ;
F_43 ( V_2 , 0 ) ;
F_36 ( V_6 , V_3 -> V_265 , 0x0f , 0x00 ) ;
V_264 = F_125 ( V_64 -> V_64 ) ;
if ( V_264 < 0 )
V_264 = 0xc0 ;
switch ( V_64 -> V_178 ) {
case V_83 :
V_2 -> V_269 [ 0 ] = V_64 -> V_64 [ V_264 ] ;
V_2 -> V_269 [ 1 ] = V_64 -> V_64 [ V_264 + 1 ] ;
break;
case V_84 :
F_35 ( V_6 , 0x70 , V_64 -> V_64 [ V_264 ] ) ;
F_35 ( V_6 , 0x71 , V_64 -> V_64 [ V_264 + 1 ] ) ;
break;
case V_85 :
F_35 ( V_6 , 0x72 , V_64 -> V_64 [ V_264 ] ) ;
F_35 ( V_6 , 0x73 , V_64 -> V_64 [ V_264 + 1 ] ) ;
break;
case V_86 :
F_35 ( V_6 , 0x74 , V_64 -> V_64 [ V_264 ] ) ;
F_35 ( V_6 , 0x75 , V_64 -> V_64 [ V_264 + 1 ] ) ;
break;
default:
return - V_71 ;
}
if ( V_3 -> type == V_270 ) {
F_35 ( V_6 , 0x76 , V_264 & 0xff ) ;
F_36 ( V_6 , 0x77 , 0x40 , ( V_264 & 0x100 ) >> 2 ) ;
} else {
F_36 ( V_6 , 0x71 , 0x01 , ( V_264 & 0x100 ) >> 8 ) ;
}
V_64 -> V_64 [ V_264 ] = V_2 -> V_269 [ 0 ] ;
V_64 -> V_64 [ V_264 + 1 ] = V_2 -> V_269 [ 1 ] ;
memcpy ( V_2 -> V_64 . V_64 , V_64 -> V_64 , 128 * V_64 -> V_259 ) ;
V_2 -> V_64 . V_259 = V_64 -> V_259 ;
V_2 -> V_172 = F_128 ( V_64 -> V_64 [ 0x15 ] ,
V_64 -> V_64 [ 0x16 ] ) ;
V_2 -> V_64 . V_65 |= 1 << V_64 -> V_178 ;
V_26 = F_41 ( V_6 , 128 * V_64 -> V_259 , V_2 -> V_64 . V_64 ) ;
if ( V_26 < 0 ) {
F_79 ( V_6 , L_58 , V_26 , V_64 -> V_178 ) ;
return V_26 ;
}
F_36 ( V_6 , V_3 -> V_265 , 0x0f , V_2 -> V_64 . V_65 ) ;
for ( V_27 = 0 ; V_27 < 1000 ; V_27 ++ ) {
if ( F_34 ( V_6 , V_3 -> V_271 ) & V_2 -> V_64 . V_65 )
break;
F_129 ( 1 ) ;
}
if ( V_27 == 1000 ) {
F_79 ( V_6 , L_59 , V_2 -> V_64 . V_65 ) ;
return - V_21 ;
}
F_130 ( V_2 -> V_272 ,
& V_2 -> V_63 , V_273 / 10 ) ;
return 0 ;
}
static void F_131 ( struct V_5 * V_6 )
{
int V_27 ;
T_2 V_51 [ 14 ] ;
T_2 V_274 ;
T_2 V_275 ;
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
V_274 = F_26 ( V_6 , 0xe2 ) ;
V_275 = F_26 ( V_6 , 0xe1 ) ;
F_68 ( V_6 , L_64 ,
V_275 , V_274 ) ;
if ( V_275 != 0x02 )
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
const struct V_90 * V_3 = V_2 -> V_3 ;
struct V_96 V_97 ;
struct V_160 V_161 ;
T_2 V_276 = F_18 ( V_6 , 0x02 ) ;
T_2 V_277 ;
T_2 V_278 ;
static const char * const V_279 [ 16 ] = {
L_66 , L_67 , L_68 , L_69 ,
L_68 , L_70 , L_68 , L_71 ,
L_68 , L_72 , L_73 ,
L_68 , L_68 , L_68 , L_68 , L_74
} ;
static const char * const V_280 [ 16 ] = {
L_75 , L_76 ,
L_77 , L_78 ,
L_79 , L_80 ,
L_81 , L_82 ,
L_83 , L_83 , L_83 , L_83 , L_83 ,
L_83 , L_83 , L_84
} ;
static const char * const V_281 [] = {
L_85 ,
L_75 ,
L_76 ,
} ;
static const char * const V_282 [ 4 ] = {
L_86 ,
L_87 ,
L_88 ,
L_89
} ;
F_68 ( V_6 , L_90 ) ;
F_68 ( V_6 , L_91 , F_84 ( V_6 ) ? L_92 : L_93 ) ;
V_277 = F_34 ( V_6 , V_3 -> V_271 ) ;
F_68 ( V_6 , L_94 ,
( ( V_277 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_277 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_277 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_277 & 0x08 ) ? L_95 : L_96 ) ) ;
F_68 ( V_6 , L_97 , ! ! ( F_23 ( V_6 , 0x2a ) & 0x01 ) ?
L_98 : L_99 ) ;
F_68 ( V_6 , L_100 ) ;
V_278 = V_3 -> V_92 ( V_6 ) ;
F_68 ( V_6 , L_101 ,
( ( V_278 & 0x01 ) ? L_95 : L_96 ) ,
( ( V_278 & 0x02 ) ? L_95 : L_96 ) ,
( ( V_278 & 0x04 ) ? L_95 : L_96 ) ,
( ( V_278 & 0x08 ) ? L_95 : L_96 ) ) ;
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
if ( F_96 ( V_6 , & V_161 ) )
F_68 ( V_6 , L_112 ) ;
else
F_68 ( V_6 , L_113 ,
V_161 . V_166 , V_161 . V_163 , V_161 . V_167 ,
V_161 . V_175 ? L_36 : L_37 ,
V_161 . V_168 , V_161 . V_170 ) ;
if ( F_103 ( V_6 , & V_97 ) )
F_68 ( V_6 , L_114 ) ;
else
F_104 ( V_6 -> V_210 , L_115 ,
& V_97 , true ) ;
F_104 ( V_6 -> V_210 , L_116 ,
& V_2 -> V_97 , true ) ;
if ( F_90 ( V_6 ) )
return 0 ;
F_68 ( V_6 , L_117 ) ;
F_68 ( V_6 , L_118 ,
V_281 [ V_2 -> V_135 ] ) ;
F_68 ( V_6 , L_119 ,
V_280 [ V_276 >> 4 ] ) ;
F_68 ( V_6 , L_120 ,
( V_276 & 0x02 ) ? L_121 : L_122 ,
( V_276 & 0x04 ) ? L_123 : L_124 ,
( ( V_276 & 0x04 ) ^ ( V_276 & 0x01 ) ) ?
L_98 : L_99 ) ;
F_68 ( V_6 , L_125 ,
V_279 [ F_56 ( V_6 , 0xfc ) >> 4 ] ) ;
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
bool V_283 = F_50 ( V_6 , 0x04 ) & 0x01 ;
bool V_284 = F_50 ( V_6 , 0x18 ) & 0x01 ;
bool V_285 = F_18 ( V_6 , 0x65 ) & 0x40 ;
F_68 ( V_6 , L_135 ,
V_283 ? L_136 : L_137 ,
V_284 ? L_138 : L_139 ,
V_285 ? L_140 : L_98 ) ;
if ( V_283 && V_284 ) {
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
F_68 ( V_6 , L_147 , V_282 [ ( F_50 ( V_6 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_131 ( V_6 ) ;
}
return 0 ;
}
static int F_133 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
const struct V_90 * V_3 = V_2 -> V_3 ;
struct V_286 * V_235 = & V_2 -> V_235 ;
F_52 ( V_6 , 0x48 ,
( V_235 -> V_287 ? 0x80 : 0 ) |
( V_235 -> V_288 ? 0x40 : 0 ) ) ;
F_110 ( V_6 ) ;
if ( V_235 -> V_289 >= 0 &&
V_235 -> V_289 < V_2 -> V_179 ) {
V_2 -> V_80 = V_235 -> V_289 ;
F_112 ( V_6 ) ;
F_109 ( V_6 ) ;
}
F_19 ( V_6 , 0x0c , 0x42 ) ;
F_19 ( V_6 , 0x0b , 0x44 ) ;
F_58 ( V_6 , 0xcf , 0x01 ) ;
F_20 ( V_6 , 0x02 , 0x0f ,
V_235 -> V_290 << 3 |
V_235 -> V_291 << 2 |
V_235 -> V_292 << 0 ) ;
F_20 ( V_6 , 0x05 , 0x0e , V_235 -> V_293 << 3 |
V_235 -> V_294 << 2 |
V_235 -> V_295 << 1 ) ;
F_119 ( V_2 ) ;
F_58 ( V_6 , 0x69 , 0x30 ) ;
F_19 ( V_6 , 0x06 , 0xa0 | V_235 -> V_296 << 2 |
V_235 -> V_297 << 1 | V_235 -> V_298 ) ;
F_19 ( V_6 , 0x14 , 0x40 | V_235 -> V_299 << 4 |
V_235 -> V_300 << 2 |
V_235 -> V_301 ) ;
F_58 ( V_6 , 0xba , ( V_235 -> V_302 << 1 ) | 0x01 ) ;
F_58 ( V_6 , 0xf3 , 0xdc ) ;
F_58 ( V_6 , 0xf9 , 0x23 ) ;
F_58 ( V_6 , 0x45 , 0x23 ) ;
F_58 ( V_6 , 0xc9 , 0x2d ) ;
F_53 ( V_6 , 0x15 , 0x03 , 0x03 ) ;
F_53 ( V_6 , 0x1a , 0x0e , 0x08 ) ;
F_53 ( V_6 , 0x68 , 0x06 , 0x06 ) ;
F_33 ( V_6 , 0xb5 , 0x01 ) ;
if ( F_1 ( V_2 ) ) {
F_33 ( V_6 , 0x02 , V_235 -> V_303 ) ;
F_20 ( V_6 , 0x30 , 1 << 4 , V_235 -> V_304 << 4 ) ;
}
F_19 ( V_6 , 0x40 , 0xc0 | V_235 -> V_305 ) ;
F_19 ( V_6 , 0x46 , 0x98 ) ;
F_19 ( V_6 , 0x6e , V_3 -> V_255 ) ;
F_19 ( V_6 , 0x73 , V_3 -> V_257 ) ;
V_3 -> V_306 ( V_6 ) ;
return F_134 ( V_6 -> V_307 ) ;
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
T_2 V_16 , T_2 V_308 )
{
struct V_9 * V_10 = F_140 ( V_6 ) ;
if ( V_16 )
F_19 ( V_6 , V_308 , V_16 << 1 ) ;
return F_141 ( V_10 -> V_15 , F_18 ( V_6 , V_308 ) >> 1 ) ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_309 V_310 ;
struct V_311 * V_312 ;
struct V_311 * V_313 ;
unsigned int V_17 ;
V_313 = V_2 -> V_24 [ V_35 ] -> V_314 . V_315 ;
V_312 = F_143 ( V_313 , NULL ) ;
if ( ! V_312 )
return - V_71 ;
F_144 ( V_312 , & V_310 ) ;
F_145 ( V_312 ) ;
V_17 = V_310 . V_316 . V_317 . V_17 ;
if ( V_17 & V_318 )
V_2 -> V_235 . V_297 = 1 ;
if ( V_17 & V_319 )
V_2 -> V_235 . V_296 = 1 ;
if ( V_17 & V_320 )
V_2 -> V_235 . V_298 = 1 ;
if ( V_310 . V_321 == V_322 ) {
V_2 -> V_235 . V_294 = 1 ;
V_2 -> V_235 . V_291 = 1 ;
}
V_2 -> V_235 . V_305 = V_323 ;
V_2 -> V_235 . V_324 [ V_38 ] = 0x42 ;
V_2 -> V_235 . V_324 [ V_39 ] = 0x40 ;
V_2 -> V_235 . V_324 [ V_40 ] = 0x3e ;
V_2 -> V_235 . V_324 [ V_41 ] = 0x38 ;
V_2 -> V_235 . V_324 [ V_42 ] = 0x3c ;
V_2 -> V_235 . V_324 [ V_43 ] = 0x26 ;
V_2 -> V_235 . V_324 [ V_44 ] = 0x32 ;
V_2 -> V_235 . V_324 [ V_45 ] = 0x36 ;
V_2 -> V_235 . V_324 [ V_66 ] = 0x34 ;
V_2 -> V_235 . V_324 [ V_67 ] = 0x30 ;
V_2 -> V_235 . V_324 [ V_68 ] = 0x22 ;
V_2 -> V_235 . V_324 [ V_69 ] = 0x24 ;
V_2 -> V_235 . V_287 = 0 ;
V_2 -> V_235 . V_288 = 0 ;
V_2 -> V_235 . V_289 = - 1 ;
V_2 -> V_235 . V_293 = 1 ;
V_2 -> V_235 . V_292 = 1 ;
V_2 -> V_235 . V_240 = V_325 ;
V_2 -> V_235 . V_236 = V_326 ;
return 0 ;
}
static int F_146 ( struct V_9 * V_10 ,
const struct V_327 * V_145 )
{
static const struct V_96 V_328 =
V_329 ;
struct V_1 * V_2 ;
struct V_330 * V_144 ;
struct V_5 * V_6 ;
unsigned int V_27 ;
T_3 V_36 ;
int V_26 ;
if ( ! F_147 ( V_10 -> V_15 , V_331 ) )
return - V_21 ;
F_148 ( 1 , V_53 , V_10 , L_148 ,
V_10 -> V_16 << 1 ) ;
V_2 = F_149 ( & V_10 -> V_314 , sizeof( * V_2 ) , V_332 ) ;
if ( ! V_2 ) {
F_14 ( V_10 , L_149 ) ;
return - V_333 ;
}
V_2 -> V_24 [ V_35 ] = V_10 ;
V_2 -> V_199 = true ;
V_2 -> V_80 = ~ 0 ;
if ( F_150 ( V_334 ) && V_10 -> V_314 . V_315 ) {
const struct V_335 * V_336 ;
V_336 = F_151 ( V_337 , V_10 -> V_314 . V_315 ) ;
V_2 -> V_3 = V_336 -> V_14 ;
V_26 = F_142 ( V_2 ) ;
if ( V_26 < 0 ) {
F_14 ( V_10 , L_150 ) ;
return V_26 ;
}
} else if ( V_10 -> V_314 . V_338 ) {
struct V_286 * V_235 = V_10 -> V_314 . V_338 ;
V_2 -> V_3 = ( const struct V_90 * ) V_145 -> V_339 ;
V_2 -> V_235 = * V_235 ;
} else {
F_14 ( V_10 , L_151 ) ;
return - V_340 ;
}
for ( V_27 = 0 ; V_27 < V_2 -> V_3 -> V_56 ; ++ V_27 ) {
V_2 -> V_57 [ V_27 ] =
F_152 ( & V_10 -> V_314 , L_152 , V_27 ) ;
if ( F_44 ( V_2 -> V_57 [ V_27 ] ) )
continue;
F_153 ( V_2 -> V_57 [ V_27 ] , 0 ) ;
F_154 ( V_10 , L_153 , V_27 ) ;
}
V_2 -> V_97 = V_328 ;
V_2 -> V_222 = V_75 ( V_2 , V_247 ) ;
V_6 = & V_2 -> V_6 ;
F_155 ( V_6 , V_10 , & V_341 ) ;
snprintf ( V_6 -> V_210 , sizeof( V_6 -> V_210 ) , L_154 ,
V_145 -> V_210 , F_156 ( V_10 -> V_15 ) ,
V_10 -> V_16 ) ;
V_6 -> V_17 |= V_342 ;
if ( V_2 -> V_3 -> type == V_270 ) {
V_36 = F_12 ( V_10 , 0xfb , false ) ;
if ( V_36 != 0x68 ) {
F_68 ( V_6 , L_155 ,
V_10 -> V_16 << 1 ) ;
return - V_340 ;
}
} else {
V_36 = ( F_12 ( V_10 , 0xea , false ) << 8 )
| ( F_12 ( V_10 , 0xeb , false ) << 0 ) ;
if ( V_36 != 0x2051 ) {
F_68 ( V_6 , L_156 ,
V_10 -> V_16 << 1 ) ;
return - V_340 ;
}
}
V_144 = & V_2 -> V_144 ;
F_157 ( V_144 , F_1 ( V_2 ) ? 9 : 8 ) ;
F_158 ( V_144 , & V_343 ,
V_146 , - 128 , 127 , 1 , 0 ) ;
F_158 ( V_144 , & V_343 ,
V_147 , 0 , 255 , 1 , 128 ) ;
F_158 ( V_144 , & V_343 ,
V_148 , 0 , 255 , 1 , 128 ) ;
F_158 ( V_144 , & V_343 ,
V_149 , 0 , 128 , 1 , 0 ) ;
V_2 -> V_91 = F_158 ( V_144 , NULL ,
V_344 , 0 ,
( 1 << V_2 -> V_3 -> V_56 ) - 1 , 0 , 0 ) ;
V_2 -> V_345 =
F_159 ( V_144 , & V_343 ,
V_150 , V_140 ,
0 , V_136 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_346 =
F_160 ( V_144 , & V_347 , NULL ) ;
V_2 -> V_348 =
F_160 ( V_144 , & V_349 , NULL ) ;
V_2 -> V_350 =
F_160 ( V_144 , & V_351 , NULL ) ;
V_6 -> V_307 = V_144 ;
if ( V_144 -> error ) {
V_26 = V_144 -> error ;
goto V_352;
}
V_2 -> V_91 -> V_353 = true ;
V_2 -> V_345 -> V_353 = true ;
if ( F_1 ( V_2 ) )
V_2 -> V_346 -> V_353 = true ;
V_2 -> V_348 -> V_353 = true ;
V_2 -> V_350 -> V_353 = true ;
if ( F_73 ( V_6 ) ) {
V_26 = - V_340 ;
goto V_352;
}
for ( V_27 = 1 ; V_27 < V_354 ; ++ V_27 ) {
if ( ! ( F_46 ( V_27 ) & V_2 -> V_3 -> V_70 ) )
continue;
V_2 -> V_24 [ V_27 ] =
F_139 ( V_6 , V_2 -> V_235 . V_324 [ V_27 ] ,
0xf2 + V_27 ) ;
if ( V_2 -> V_24 [ V_27 ] == NULL ) {
V_26 = - V_333 ;
F_79 ( V_6 , L_157 , V_27 ) ;
goto V_355;
}
}
V_2 -> V_272 = F_161 ( V_10 -> V_210 ) ;
if ( ! V_2 -> V_272 ) {
F_79 ( V_6 , L_158 ) ;
V_26 = - V_333 ;
goto V_355;
}
F_162 ( & V_2 -> V_63 ,
F_48 ) ;
V_2 -> V_179 = V_2 -> V_3 -> V_56
+ ( V_2 -> V_3 -> V_4 ? 2 : 0 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_179 ; ++ V_27 )
V_2 -> V_356 [ V_27 ] . V_17 = V_357 ;
V_2 -> V_356 [ V_2 -> V_179 ] . V_17 = V_358 ;
V_26 = F_163 ( & V_6 -> V_359 , V_2 -> V_179 + 1 ,
V_2 -> V_356 , 0 ) ;
if ( V_26 )
goto V_360;
V_26 = F_133 ( V_6 ) ;
if ( V_26 )
goto V_361;
F_68 ( V_6 , L_159 , V_10 -> V_210 ,
V_10 -> V_16 << 1 , V_10 -> V_15 -> V_210 ) ;
V_26 = F_164 ( V_6 ) ;
if ( V_26 )
goto V_361;
return 0 ;
V_361:
F_165 ( & V_6 -> V_359 ) ;
V_360:
F_166 ( & V_2 -> V_63 ) ;
F_167 ( V_2 -> V_272 ) ;
V_355:
F_137 ( V_2 ) ;
V_352:
F_168 ( V_144 ) ;
return V_26 ;
}
static int F_169 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = F_170 ( V_10 ) ;
struct V_1 * V_2 = F_2 ( V_6 ) ;
F_166 ( & V_2 -> V_63 ) ;
F_167 ( V_2 -> V_272 ) ;
F_171 ( V_6 ) ;
F_172 ( V_6 ) ;
F_165 ( & V_6 -> V_359 ) ;
F_137 ( F_2 ( V_6 ) ) ;
F_168 ( V_6 -> V_307 ) ;
return 0 ;
}
