static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline unsigned F_4 ( const struct V_8 * V_9 )
{
return F_5 ( V_9 ) ;
}
static inline unsigned F_6 ( const struct V_8 * V_9 )
{
return F_7 ( V_9 ) ;
}
static inline unsigned F_8 ( const struct V_8 * V_9 )
{
return F_9 ( V_9 ) ;
}
static inline unsigned F_10 ( const struct V_8 * V_9 )
{
return F_11 ( V_9 ) ;
}
static T_1 F_12 ( struct V_10 * V_11 ,
T_2 V_12 , bool V_13 )
{
union V_14 V_15 ;
if ( ! F_13 ( V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 ,
V_19 , V_12 ,
V_20 , & V_15 ) )
return V_15 . V_21 ;
if ( V_13 )
F_14 ( V_11 , L_1 ,
V_11 -> V_17 , V_12 ) ;
return - V_22 ;
}
static T_1 F_15 ( struct V_10 * V_11 , T_2 V_12 )
{
return F_12 ( V_11 , V_12 , true ) ;
}
static T_1 F_16 ( struct V_10 * V_11 ,
T_2 V_12 , T_2 V_23 )
{
union V_14 V_15 ;
int V_24 ;
int V_25 ;
V_15 . V_21 = V_23 ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
V_24 = F_13 ( V_11 -> V_16 , V_11 -> V_17 ,
V_11 -> V_18 ,
V_26 , V_12 ,
V_20 , & V_15 ) ;
if ( ! V_24 )
break;
}
if ( V_24 < 0 )
F_14 ( V_11 , L_2 ,
V_11 -> V_17 , V_12 , V_23 ) ;
return V_24 ;
}
static T_1 F_17 ( struct V_10 * V_11 ,
T_2 V_12 , unsigned V_27 , const T_2 * V_28 )
{
union V_14 V_15 ;
if ( V_27 > V_29 )
V_27 = V_29 ;
V_15 . V_30 [ 0 ] = V_27 ;
memcpy ( V_15 . V_30 + 1 , V_28 , V_27 ) ;
return F_13 ( V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 ,
V_26 , V_12 ,
V_31 , & V_15 ) ;
}
static inline int F_18 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_10 * V_11 = F_19 ( V_3 ) ;
return F_15 ( V_11 , V_32 ) ;
}
static inline int F_20 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_10 * V_11 = F_19 ( V_3 ) ;
return F_16 ( V_11 , V_32 , V_33 ) ;
}
static inline int F_21 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_34 , T_2 V_33 )
{
return F_20 ( V_3 , V_32 , ( F_18 ( V_3 , V_32 ) & V_34 ) | V_33 ) ;
}
static inline int F_22 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_36 , V_32 ) ;
}
static inline int F_23 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_36 , V_32 , V_33 ) ;
}
static inline int F_24 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_37 , V_32 ) ;
}
static inline int F_25 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_37 , V_32 , V_33 ) ;
}
static inline int F_26 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_34 , T_2 V_33 )
{
return F_25 ( V_3 , V_32 , ( F_24 ( V_3 , V_32 ) & V_34 ) | V_33 ) ;
}
static inline int F_27 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_38 , V_32 ) ;
}
static inline int F_28 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_38 , V_32 , V_33 ) ;
}
static inline int F_29 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_39 , V_32 ) ;
}
static inline int F_30 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_39 , V_32 , V_33 ) ;
}
static inline int F_31 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_40 , V_32 ) ;
}
static inline int F_32 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_40 , V_32 , V_33 ) ;
}
static inline int F_33 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_41 , V_32 ) ;
}
static inline int F_34 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_41 , V_32 , V_33 ) ;
}
static inline int F_35 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_42 , V_32 ) ;
}
static inline int F_36 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_42 , V_32 , V_33 ) ;
}
static inline int F_37 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_34 , T_2 V_33 )
{
return F_36 ( V_3 , V_32 , ( F_35 ( V_3 , V_32 ) & V_34 ) | V_33 ) ;
}
static inline int F_38 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_43 , V_32 ) ;
}
static inline int F_39 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_43 , V_32 , V_33 ) ;
}
static inline int F_40 ( struct V_2 * V_3 , unsigned V_44 , T_2 * V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_35 -> V_43 ;
T_2 V_45 [ 1 ] = { 0 } ;
T_2 V_46 [ 256 ] ;
struct V_47 V_48 [ 2 ] = {
{
. V_17 = V_11 -> V_17 ,
. V_44 = 1 ,
. V_49 = V_45
} ,
{
. V_17 = V_11 -> V_17 ,
. V_18 = V_50 ,
. V_44 = V_44 ,
. V_49 = V_46
} ,
} ;
if ( F_41 ( V_11 -> V_16 , V_48 , 2 ) < 0 )
return - V_22 ;
memcpy ( V_33 , V_46 , V_44 ) ;
return 0 ;
}
static inline int F_42 ( struct V_2 * V_3 ,
unsigned V_44 , const T_2 * V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_24 = 0 ;
int V_25 ;
F_43 ( 2 , V_51 , V_3 , L_3 , V_52 , V_44 ) ;
for ( V_25 = 0 ; ! V_24 && V_25 < V_44 ; V_25 += V_29 )
V_24 = F_17 ( V_35 -> V_43 , V_25 ,
V_29 , V_33 + V_25 ) ;
return V_24 ;
}
static void F_44 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_45 ( V_54 ) ;
struct V_1 * V_35 = F_2 ( V_56 , struct V_1 ,
V_57 ) ;
struct V_2 * V_3 = & V_35 -> V_3 ;
F_43 ( 2 , V_51 , V_3 , L_4 , V_52 ) ;
F_46 ( V_3 , V_58 , ( void * ) & V_35 -> V_59 . V_60 ) ;
}
static inline int F_47 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_61 , V_32 ) ;
}
static inline int F_48 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_61 , V_32 , V_33 ) ;
}
static inline int F_49 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_34 , T_2 V_33 )
{
return F_48 ( V_3 , V_32 , ( F_47 ( V_3 , V_32 ) & V_34 ) | V_33 ) ;
}
static inline int F_50 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_62 , V_32 ) ;
}
static inline int F_51 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_62 , V_32 , V_33 ) ;
}
static inline int F_52 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_63 , V_32 ) ;
}
static inline int F_53 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_63 , V_32 , V_33 ) ;
}
static inline int F_54 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_34 , T_2 V_33 )
{
return F_53 ( V_3 , V_32 , ( F_52 ( V_3 , V_32 ) & V_34 ) | V_33 ) ;
}
static inline int F_55 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_64 , V_32 ) ;
}
static inline int F_56 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_64 , V_32 , V_33 ) ;
}
static inline bool F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return V_35 -> V_65 == V_66 ||
V_35 -> V_65 == V_67 ;
}
static inline bool F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return V_35 -> V_65 == V_68 ||
V_35 -> V_65 == V_69 ||
V_35 -> V_65 == V_70 ||
V_35 -> V_65 == V_71 ;
}
static void F_59 ( struct V_2 * V_3 )
{
F_60 ( V_3 , L_5 ) ;
F_60 ( V_3 , L_6 ) ;
F_60 ( V_3 , L_7 ) ;
F_60 ( V_3 , L_8 ) ;
F_60 ( V_3 , L_9 ) ;
F_60 ( V_3 , L_10 ) ;
F_60 ( V_3 , L_11 ) ;
F_60 ( V_3 , L_12 ) ;
F_60 ( V_3 , L_13 ) ;
F_60 ( V_3 , L_14 ) ;
F_60 ( V_3 , L_15 ) ;
F_60 ( V_3 , L_16 ) ;
F_60 ( V_3 , L_17 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_72 * V_32 )
{
V_32 -> V_73 = 1 ;
switch ( V_32 -> V_32 >> 8 ) {
case 0 :
V_32 -> V_33 = F_18 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 1 :
V_32 -> V_33 = F_22 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 2 :
V_32 -> V_33 = F_24 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 3 :
V_32 -> V_33 = F_27 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 4 :
V_32 -> V_33 = F_29 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 5 :
V_32 -> V_33 = F_31 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 6 :
V_32 -> V_33 = F_33 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 7 :
V_32 -> V_33 = F_35 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 8 :
V_32 -> V_33 = F_38 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 9 :
V_32 -> V_33 = F_47 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 0xa :
V_32 -> V_33 = F_50 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 0xb :
V_32 -> V_33 = F_52 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 0xc :
V_32 -> V_33 = F_55 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
default:
F_60 ( V_3 , L_18 , V_32 -> V_32 ) ;
F_59 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_62 ( struct V_2 * V_3 ,
const struct V_72 * V_32 )
{
T_2 V_33 = V_32 -> V_33 & 0xff ;
switch ( V_32 -> V_32 >> 8 ) {
case 0 :
F_20 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 1 :
F_23 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 2 :
F_25 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 3 :
F_28 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 4 :
F_30 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 5 :
F_32 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 6 :
F_34 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 7 :
F_36 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 8 :
F_39 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 9 :
F_48 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 0xa :
F_51 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 0xb :
F_53 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
case 0xc :
F_56 ( V_3 , V_32 -> V_32 & 0xff , V_33 ) ;
break;
default:
F_60 ( V_3 , L_18 , V_32 -> V_32 ) ;
F_59 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_2 V_74 = F_18 ( V_3 , 0x6f ) ;
return F_64 ( V_35 -> V_75 ,
( ( V_74 & 0x10 ) >> 4 ) |
( ( V_74 & 0x08 ) >> 2 ) |
( V_74 & 0x04 ) |
( ( V_74 & 0x02 ) << 2 ) ) ;
}
static int F_65 ( struct V_2 * V_3 ,
T_2 V_76 ,
const struct V_77 * V_78 ,
const struct V_79 * V_80 )
{
int V_25 ;
for ( V_25 = 0 ; V_78 [ V_25 ] . V_80 . V_81 . V_82 ; V_25 ++ ) {
if ( ! F_66 ( V_80 , & V_78 [ V_25 ] . V_80 ,
F_58 ( V_3 ) ? 250000 : 1000000 ) )
continue;
F_20 ( V_3 , 0x00 , V_78 [ V_25 ] . V_83 ) ;
F_20 ( V_3 , 0x01 , ( V_78 [ V_25 ] . V_84 << 4 ) +
V_76 ) ;
return 0 ;
}
return - 1 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_24 ;
F_43 ( 1 , V_51 , V_3 , L_19 , V_52 ) ;
F_20 ( V_3 , 0x16 , 0x43 ) ;
F_20 ( V_3 , 0x17 , 0x5a ) ;
F_54 ( V_3 , 0x81 , 0xef , 0x00 ) ;
F_53 ( V_3 , 0x8f , 0x00 ) ;
F_53 ( V_3 , 0x90 , 0x00 ) ;
F_53 ( V_3 , 0xa2 , 0x00 ) ;
F_53 ( V_3 , 0xa3 , 0x00 ) ;
F_53 ( V_3 , 0xa4 , 0x00 ) ;
F_53 ( V_3 , 0xa5 , 0x00 ) ;
F_53 ( V_3 , 0xa6 , 0x00 ) ;
F_53 ( V_3 , 0xa7 , 0x00 ) ;
F_53 ( V_3 , 0xab , 0x00 ) ;
F_53 ( V_3 , 0xac , 0x00 ) ;
if ( F_57 ( V_3 ) ) {
V_24 = F_65 ( V_3 ,
0x01 , V_85 , V_80 ) ;
if ( V_24 )
V_24 = F_65 ( V_3 ,
0x02 , V_86 , V_80 ) ;
} else if ( F_58 ( V_3 ) ) {
V_24 = F_65 ( V_3 ,
0x05 , V_87 , V_80 ) ;
if ( V_24 )
V_24 = F_65 ( V_3 ,
0x06 , V_88 , V_80 ) ;
} else {
F_43 ( 2 , V_51 , V_3 , L_20 ,
V_52 , V_35 -> V_65 ) ;
V_24 = - 1 ;
}
return V_24 ;
}
static void F_68 ( struct V_2 * V_3 ,
const struct V_8 * V_81 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_19 ( V_3 ) ;
T_3 V_82 = F_6 ( V_81 ) ;
T_3 V_89 = F_10 ( V_81 ) ;
T_4 V_90 = V_81 -> V_91 + V_81 -> V_92 - 4 ;
T_4 V_93 = V_82 - V_81 -> V_94 ;
T_4 V_95 = V_89 - V_81 -> V_96 ;
T_4 V_97 = V_81 -> V_98 + V_81 -> V_99 ;
T_4 V_100 = ( ( ( T_3 ) V_81 -> V_101 / 100 ) > 0 ) ?
( ( V_82 * ( V_102 / 100 ) ) / ( ( T_3 ) V_81 -> V_101 / 100 ) ) : 0 ;
const T_2 V_103 [ 2 ] = {
0xc0 | ( ( V_82 >> 8 ) & 0x1f ) ,
V_82 & 0xff
} ;
F_43 ( 2 , V_51 , V_3 , L_21 , V_52 ) ;
if ( F_57 ( V_3 ) ) {
F_20 ( V_3 , 0x00 , 0x07 ) ;
F_20 ( V_3 , 0x01 , 0x02 ) ;
F_54 ( V_3 , 0x81 , 0xef , 0x10 ) ;
if ( F_17 ( V_11 , 0x16 , 2 , V_103 ) )
F_69 ( V_3 , L_22 ) ;
F_53 ( V_3 , 0xa2 , ( V_90 >> 4 ) & 0xff ) ;
F_53 ( V_3 , 0xa3 , ( ( V_90 & 0x0f ) << 4 ) |
( ( V_93 >> 8 ) & 0x0f ) ) ;
F_53 ( V_3 , 0xa4 , V_93 & 0xff ) ;
F_53 ( V_3 , 0xa5 , ( V_95 >> 4 ) & 0xff ) ;
F_53 ( V_3 , 0xa6 , ( ( V_95 & 0xf ) << 4 ) |
( ( V_97 >> 8 ) & 0xf ) ) ;
F_53 ( V_3 , 0xa7 , V_97 & 0xff ) ;
} else if ( F_58 ( V_3 ) ) {
F_20 ( V_3 , 0x00 , 0x02 ) ;
F_20 ( V_3 , 0x01 , 0x06 ) ;
} else {
F_43 ( 2 , V_51 , V_3 , L_20 ,
V_52 , V_35 -> V_65 ) ;
}
F_53 ( V_3 , 0x8f , ( V_100 >> 8 ) & 0x7 ) ;
F_53 ( V_3 , 0x90 , V_100 & 0xff ) ;
F_53 ( V_3 , 0xab , ( V_89 >> 4 ) & 0xff ) ;
F_53 ( V_3 , 0xac , ( V_89 & 0x0f ) << 4 ) ;
}
static void F_70 ( struct V_2 * V_3 , bool V_104 , T_4 V_105 , T_4 V_106 , T_4 V_107 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_2 V_108 [ 4 ] ;
if ( V_104 ) {
V_105 = 0x3ff ;
V_106 = 0x3ff ;
V_107 = 0x3ff ;
}
F_43 ( 2 , V_51 , V_3 , L_23 ,
V_52 , V_104 ? L_24 : L_25 ,
V_105 , V_106 , V_107 ) ;
V_108 [ 0 ] = ( F_52 ( V_3 , 0x77 ) & 0xc0 ) | ( ( V_105 & 0x3f0 ) >> 4 ) ;
V_108 [ 1 ] = ( ( V_105 & 0x00f ) << 4 ) | ( ( V_106 & 0x3c0 ) >> 6 ) ;
V_108 [ 2 ] = ( ( V_106 & 0x03f ) << 2 ) | ( ( V_107 & 0x300 ) >> 8 ) ;
V_108 [ 3 ] = V_107 & 0x0ff ;
if ( F_17 ( V_35 -> V_63 , 0x77 , 4 , V_108 ) )
F_69 ( V_3 , L_26 , V_52 ) ;
}
static void F_71 ( struct V_2 * V_3 , bool V_109 , T_4 V_110 , T_4 V_111 , T_4 V_112 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_2 V_113 [ 4 ] ;
T_2 V_114 = 1 ;
T_2 V_115 = 1 ;
if ( V_109 ) {
V_114 = 0 ;
V_115 = 0 ;
V_110 = 0x100 ;
V_111 = 0x100 ;
V_112 = 0x100 ;
}
F_43 ( 2 , V_51 , V_3 , L_27 ,
V_52 , V_109 ? L_24 : L_25 ,
V_110 , V_111 , V_112 ) ;
V_113 [ 0 ] = ( ( V_114 << 7 ) | ( V_115 << 6 ) | ( ( V_110 & 0x3f0 ) >> 4 ) ) ;
V_113 [ 1 ] = ( ( ( V_110 & 0x00f ) << 4 ) | ( ( V_111 & 0x3c0 ) >> 6 ) ) ;
V_113 [ 2 ] = ( ( ( V_111 & 0x03f ) << 2 ) | ( ( V_112 & 0x300 ) >> 8 ) ) ;
V_113 [ 3 ] = ( ( V_112 & 0x0ff ) ) ;
if ( F_17 ( V_35 -> V_63 , 0x73 , 4 , V_113 ) )
F_69 ( V_3 , L_28 , V_52 ) ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
bool V_116 = F_18 ( V_3 , 0x02 ) & 0x02 ;
bool V_117 = F_47 ( V_3 , 0x05 ) & 0x80 ;
F_43 ( 2 , V_51 , V_3 , L_29 ,
V_52 , V_35 -> V_118 ,
V_116 , V_117 ) ;
F_71 ( V_3 , true , 0x0 , 0x0 , 0x0 ) ;
F_70 ( V_3 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_35 -> V_118 ) {
case V_119 :
if ( V_35 -> V_65 == V_66 ) {
F_21 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
break;
}
if ( V_35 -> V_65 == V_67 ) {
F_21 ( V_3 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_117 ) {
F_21 ( V_3 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_35 -> V_80 . V_81 . V_120 & V_121 ) {
F_21 ( V_3 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_21 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
if ( F_58 ( V_3 ) && V_116 ) {
F_70 ( V_3 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_71 ( V_3 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_70 ( V_3 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_122 :
if ( V_35 -> V_65 == V_67 ) {
F_21 ( V_3 , 0x02 , 0x0f , 0x20 ) ;
break;
}
F_21 ( V_3 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_123 :
if ( V_35 -> V_65 == V_67 ) {
F_21 ( V_3 , 0x02 , 0x0f , 0x60 ) ;
break;
}
F_21 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
if ( F_57 ( V_3 ) || V_117 )
break;
if ( V_116 ) {
F_70 ( V_3 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_71 ( V_3 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_70 ( V_3 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_73 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
switch ( V_5 -> V_124 ) {
case V_125 :
F_53 ( V_3 , 0x3c , V_5 -> V_33 ) ;
return 0 ;
case V_126 :
F_53 ( V_3 , 0x3a , V_5 -> V_33 ) ;
return 0 ;
case V_127 :
F_53 ( V_3 , 0x3b , V_5 -> V_33 ) ;
return 0 ;
case V_128 :
F_53 ( V_3 , 0x3d , V_5 -> V_33 ) ;
return 0 ;
case V_129 :
V_35 -> V_118 = V_5 -> V_33 ;
F_72 ( V_3 ) ;
return 0 ;
case V_130 :
F_34 ( V_3 , 0xc8 , V_5 -> V_33 ) ;
return 0 ;
case V_131 :
F_54 ( V_3 , 0xbf , ~ 0x04 , ( V_5 -> V_33 << 2 ) ) ;
return 0 ;
case V_132 :
F_53 ( V_3 , 0xc0 , ( V_5 -> V_33 & 0xff0000 ) >> 16 ) ;
F_53 ( V_3 , 0xc1 , ( V_5 -> V_33 & 0x00ff00 ) >> 8 ) ;
F_53 ( V_3 , 0xc2 , ( T_2 ) ( V_5 -> V_33 & 0x0000ff ) ) ;
return 0 ;
}
return - V_133 ;
}
static inline bool F_74 ( struct V_2 * V_3 )
{
return F_18 ( V_3 , 0x0c ) & 0x24 ;
}
static inline bool F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return ! ( F_18 ( V_3 , 0x6a ) & ( 0x10 >> V_35 -> V_65 ) ) ;
}
static inline bool F_76 ( struct V_2 * V_3 )
{
return ( F_18 ( V_3 , 0x6a ) & 0xe0 ) != 0xe0 ;
}
static inline bool F_77 ( struct V_2 * V_3 )
{
return F_47 ( V_3 , 0x05 ) & 0x80 ;
}
static inline bool F_78 ( struct V_2 * V_3 )
{
return ( ( F_52 ( V_3 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_79 ( struct V_2 * V_3 )
{
return ! ( F_52 ( V_3 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_80 ( struct V_2 * V_3 )
{
bool V_134 ;
V_134 = F_74 ( V_3 ) ;
V_134 |= F_79 ( V_3 ) ;
V_134 |= F_78 ( V_3 ) ;
if ( F_58 ( V_3 ) ) {
V_134 |= F_76 ( V_3 ) ;
V_134 |= F_75 ( V_3 ) ;
}
return V_134 ;
}
static inline bool F_81 ( struct V_2 * V_3 )
{
return F_18 ( V_3 , 0x12 ) & 0x01 ;
}
static int F_82 ( struct V_2 * V_3 , T_3 * V_135 )
{
* V_135 = 0 ;
* V_135 |= F_74 ( V_3 ) ? V_136 : 0 ;
* V_135 |= F_80 ( V_3 ) ? V_137 : 0 ;
if ( F_81 ( V_3 ) )
* V_135 |= F_58 ( V_3 ) ? V_138 : V_139 ;
F_43 ( 1 , V_51 , V_3 , L_30 , V_52 , * V_135 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 ,
struct V_140 * V_141 ,
struct V_79 * V_80 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_3 V_142 = ( V_102 * 8 ) / V_141 -> V_143 ;
T_3 V_144 ;
int V_25 ;
for ( V_25 = 0 ; V_145 [ V_25 ] . V_81 . V_89 ; V_25 ++ ) {
if ( F_10 ( & V_145 [ V_25 ] . V_81 ) != V_141 -> V_146 + 1 )
continue;
if ( V_145 [ V_25 ] . V_81 . V_98 != V_141 -> V_147 )
continue;
V_144 = V_142 * F_6 ( & V_145 [ V_25 ] . V_81 ) ;
if ( ( V_144 < V_145 [ V_25 ] . V_81 . V_101 + 1000000 ) &&
( V_144 > V_145 [ V_25 ] . V_81 . V_101 - 1000000 ) ) {
* V_80 = V_145 [ V_25 ] ;
return 0 ;
}
}
if ( F_84 ( V_141 -> V_146 + 1 , V_142 , V_141 -> V_147 ,
( V_141 -> V_148 == '+' ? V_149 : 0 ) |
( V_141 -> V_150 == '+' ? V_151 : 0 ) ,
V_80 ) )
return 0 ;
if ( F_85 ( V_141 -> V_146 + 1 , V_142 , V_141 -> V_147 ,
( V_141 -> V_148 == '+' ? V_149 : 0 ) |
( V_141 -> V_150 == '+' ? V_151 : 0 ) ,
V_35 -> V_152 , V_80 ) )
return 0 ;
F_43 ( 2 , V_51 , V_3 ,
L_31 ,
V_52 , V_141 -> V_147 , V_141 -> V_146 , V_141 -> V_143 ,
V_141 -> V_148 , V_141 -> V_150 ) ;
return - 1 ;
}
static int F_86 ( struct V_2 * V_3 , struct V_140 * V_141 )
{
if ( F_79 ( V_3 ) || F_78 ( V_3 ) ) {
F_43 ( 2 , V_51 , V_3 , L_32 , V_52 ) ;
return - 1 ;
}
V_141 -> V_143 = ( ( F_52 ( V_3 , 0xb1 ) & 0x3f ) << 8 ) | F_52 ( V_3 , 0xb2 ) ;
V_141 -> V_146 = ( ( F_52 ( V_3 , 0xb3 ) & 0x7 ) << 8 ) | F_52 ( V_3 , 0xb4 ) ;
V_141 -> V_147 = F_52 ( V_3 , 0xb3 ) >> 3 ;
V_141 -> V_153 = F_18 ( V_3 , 0x12 ) & 0x10 ;
if ( ( F_52 ( V_3 , 0xb5 ) & 0x03 ) == 0x01 ) {
V_141 -> V_148 = ( ( F_52 ( V_3 , 0xb5 ) & 0x10 ) ?
( ( F_52 ( V_3 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_141 -> V_150 = ( ( F_52 ( V_3 , 0xb5 ) & 0x40 ) ?
( ( F_52 ( V_3 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_141 -> V_148 = 'x' ;
V_141 -> V_150 = 'x' ;
}
if ( F_79 ( V_3 ) || F_78 ( V_3 ) ) {
F_43 ( 2 , V_51 , V_3 ,
L_33 , V_52 ) ;
return - 1 ;
}
if ( V_141 -> V_146 < 239 || V_141 -> V_143 < 8 || V_141 -> V_143 == 0x3fff ) {
F_43 ( 2 , V_51 , V_3 , L_34 , V_52 ) ;
memset ( V_141 , 0 , sizeof( struct V_140 ) ) ;
return - 1 ;
}
F_43 ( 2 , V_51 , V_3 ,
L_35 ,
V_52 , V_141 -> V_146 , V_141 -> V_143 , V_141 -> V_147 ,
V_141 -> V_148 , V_141 -> V_150 ,
V_141 -> V_153 ? L_36 : L_37 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_154 * V_80 )
{
if ( V_80 -> V_155 >= F_88 ( V_145 ) - 1 )
return - V_133 ;
memset ( V_80 -> V_156 , 0 , sizeof( V_80 -> V_156 ) ) ;
V_80 -> V_80 = V_145 [ V_80 -> V_155 ] ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 ,
struct V_157 * V_158 )
{
V_158 -> type = V_159 ;
V_158 -> V_81 . V_160 = 1920 ;
V_158 -> V_81 . V_161 = 1200 ;
V_158 -> V_81 . V_162 = 25000000 ;
if ( F_58 ( V_3 ) )
V_158 -> V_81 . V_163 = 225000000 ;
else
V_158 -> V_81 . V_163 = 170000000 ;
V_158 -> V_81 . V_120 = V_121 | V_164 |
V_165 | V_166 ;
V_158 -> V_81 . V_167 = V_168 |
V_169 | V_170 ;
return 0 ;
}
static void F_90 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
int V_25 ;
for ( V_25 = 0 ; V_145 [ V_25 ] . V_81 . V_82 ; V_25 ++ ) {
if ( F_66 ( V_80 , & V_145 [ V_25 ] ,
F_58 ( V_3 ) ? 250000 : 1000000 ) ) {
* V_80 = V_145 [ V_25 ] ;
break;
}
}
}
static int F_91 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_8 * V_81 = & V_80 -> V_81 ;
struct V_140 V_141 ;
if ( ! V_80 )
return - V_133 ;
memset ( V_80 , 0 , sizeof( struct V_79 ) ) ;
if ( F_80 ( V_3 ) ) {
V_35 -> V_171 = true ;
F_43 ( 1 , V_51 , V_3 , L_38 , V_52 ) ;
return - V_172 ;
}
if ( F_86 ( V_3 , & V_141 ) ) {
F_43 ( 1 , V_51 , V_3 , L_39 , V_52 ) ;
return - V_172 ;
}
V_81 -> V_153 = V_141 . V_153 ?
V_173 : V_174 ;
if ( F_58 ( V_3 ) ) {
T_5 V_175 ;
V_80 -> type = V_159 ;
V_81 -> V_82 = ( F_47 ( V_3 , 0x07 ) & 0x0f ) * 256 + F_47 ( V_3 , 0x08 ) ;
V_81 -> V_89 = ( F_47 ( V_3 , 0x09 ) & 0x0f ) * 256 + F_47 ( V_3 , 0x0a ) ;
V_175 = ( F_47 ( V_3 , 0x06 ) * 1000000 ) +
( ( F_47 ( V_3 , 0x3b ) & 0x30 ) >> 4 ) * 250000 ;
if ( F_77 ( V_3 ) ) {
unsigned V_176 = ( ( F_47 ( V_3 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_175 = V_175 * 8 / V_176 ;
}
V_81 -> V_101 = V_175 ;
V_81 -> V_94 = ( F_47 ( V_3 , 0x20 ) & 0x03 ) * 256 +
F_47 ( V_3 , 0x21 ) ;
V_81 -> V_91 = ( F_47 ( V_3 , 0x22 ) & 0x03 ) * 256 +
F_47 ( V_3 , 0x23 ) ;
V_81 -> V_92 = ( F_47 ( V_3 , 0x24 ) & 0x03 ) * 256 +
F_47 ( V_3 , 0x25 ) ;
V_81 -> V_96 = ( ( F_47 ( V_3 , 0x2a ) & 0x1f ) * 256 +
F_47 ( V_3 , 0x2b ) ) / 2 ;
V_81 -> V_98 = ( ( F_47 ( V_3 , 0x2e ) & 0x1f ) * 256 +
F_47 ( V_3 , 0x2f ) ) / 2 ;
V_81 -> V_99 = ( ( F_47 ( V_3 , 0x32 ) & 0x1f ) * 256 +
F_47 ( V_3 , 0x33 ) ) / 2 ;
V_81 -> V_177 = ( ( F_47 ( V_3 , 0x05 ) & 0x10 ) ? V_151 : 0 ) |
( ( F_47 ( V_3 , 0x05 ) & 0x20 ) ? V_149 : 0 ) ;
if ( V_81 -> V_153 == V_173 ) {
V_81 -> V_89 += ( F_47 ( V_3 , 0x0b ) & 0x0f ) * 256 +
F_47 ( V_3 , 0x0c ) ;
V_81 -> V_178 = ( ( F_47 ( V_3 , 0x2c ) & 0x1f ) * 256 +
F_47 ( V_3 , 0x2d ) ) / 2 ;
V_81 -> V_179 = ( ( F_47 ( V_3 , 0x30 ) & 0x1f ) * 256 +
F_47 ( V_3 , 0x31 ) ) / 2 ;
V_81 -> V_99 = ( ( F_47 ( V_3 , 0x34 ) & 0x1f ) * 256 +
F_47 ( V_3 , 0x35 ) ) / 2 ;
}
F_90 ( V_3 , V_80 ) ;
} else {
if ( ! F_83 ( V_3 , & V_141 , V_80 ) )
goto V_180;
V_141 . V_147 += 1 ;
F_43 ( 1 , V_51 , V_3 , L_40 , V_52 , V_141 . V_147 ) ;
if ( ! F_83 ( V_3 , & V_141 , V_80 ) )
goto V_180;
V_141 . V_147 -= 2 ;
F_43 ( 1 , V_51 , V_3 , L_41 , V_52 , V_141 . V_147 ) ;
if ( F_83 ( V_3 , & V_141 , V_80 ) ) {
if ( V_35 -> V_171 ) {
F_43 ( 1 , V_51 , V_3 , L_42 , V_52 ) ;
F_54 ( V_3 , 0x86 , 0xf9 , 0x00 ) ;
F_54 ( V_3 , 0x86 , 0xf9 , 0x04 ) ;
F_54 ( V_3 , 0x86 , 0xf9 , 0x02 ) ;
V_35 -> V_171 = false ;
return - V_172 ;
}
F_43 ( 1 , V_51 , V_3 , L_43 , V_52 ) ;
return - V_181 ;
}
V_35 -> V_171 = true ;
}
V_180:
if ( F_80 ( V_3 ) ) {
F_43 ( 1 , V_51 , V_3 , L_44 , V_52 ) ;
memset ( V_80 , 0 , sizeof( struct V_79 ) ) ;
return - V_172 ;
}
if ( ( F_57 ( V_3 ) && V_81 -> V_101 > 170000000 ) ||
( F_58 ( V_3 ) && V_81 -> V_101 > 225000000 ) ) {
F_43 ( 1 , V_51 , V_3 , L_45 ,
V_52 , ( T_3 ) V_81 -> V_101 ) ;
return - V_181 ;
}
if ( V_51 > 1 )
F_92 ( V_3 -> V_182 , L_46 ,
V_80 , true ) ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_8 * V_81 ;
int V_24 ;
if ( ! V_80 )
return - V_133 ;
if ( F_66 ( & V_35 -> V_80 , V_80 , 0 ) ) {
F_43 ( 1 , V_51 , V_3 , L_47 , V_52 ) ;
return 0 ;
}
V_81 = & V_80 -> V_81 ;
if ( ( F_57 ( V_3 ) && V_81 -> V_101 > 170000000 ) ||
( F_58 ( V_3 ) && V_81 -> V_101 > 225000000 ) ) {
F_43 ( 1 , V_51 , V_3 , L_45 ,
V_52 , ( T_3 ) V_81 -> V_101 ) ;
return - V_181 ;
}
F_90 ( V_3 , V_80 ) ;
V_35 -> V_80 = * V_80 ;
F_53 ( V_3 , 0x91 , V_81 -> V_153 ? 0x50 : 0x10 ) ;
V_24 = F_67 ( V_3 , V_80 ) ;
if ( V_24 ) {
F_68 ( V_3 , V_81 ) ;
}
F_72 ( V_3 ) ;
if ( V_51 > 1 )
F_92 ( V_3 -> V_182 , L_48 ,
V_80 , true ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
* V_80 = V_35 -> V_80 ;
return 0 ;
}
static void F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
if ( F_57 ( V_3 ) ) {
F_20 ( V_3 , 0x15 , 0xb0 ) ;
} else if ( F_58 ( V_3 ) ) {
F_49 ( V_3 , 0x00 , 0xfc , V_35 -> V_65 ) ;
F_48 ( V_3 , 0x01 , 0x00 ) ;
F_20 ( V_3 , 0x15 , 0xa0 ) ;
F_49 ( V_3 , 0x1a , 0xef , 0x00 ) ;
} else {
F_43 ( 2 , V_51 , V_3 , L_20 ,
V_52 , V_35 -> V_65 ) ;
}
}
static void F_96 ( struct V_2 * V_3 )
{
F_49 ( V_3 , 0x1a , 0xef , 0x10 ) ;
F_97 ( 16 ) ;
F_20 ( V_3 , 0x15 , 0xbe ) ;
F_48 ( V_3 , 0x01 , 0x78 ) ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
if ( F_57 ( V_3 ) ) {
F_48 ( V_3 , 0x0d , 0x04 ) ;
F_48 ( V_3 , 0x3d , 0x00 ) ;
F_48 ( V_3 , 0x3e , 0x74 ) ;
F_48 ( V_3 , 0x4e , 0x3b ) ;
F_48 ( V_3 , 0x57 , 0x74 ) ;
F_48 ( V_3 , 0x58 , 0x63 ) ;
F_48 ( V_3 , 0x8d , 0x18 ) ;
F_48 ( V_3 , 0x8e , 0x34 ) ;
F_48 ( V_3 , 0x93 , 0x88 ) ;
F_48 ( V_3 , 0x94 , 0x2e ) ;
F_48 ( V_3 , 0x96 , 0x00 ) ;
F_34 ( V_3 , 0x00 , 0x08 ) ;
F_34 ( V_3 , 0x01 , 0x06 ) ;
F_34 ( V_3 , 0xc8 , 0x00 ) ;
F_34 ( V_3 , 0x12 , 0x7b ) ;
F_34 ( V_3 , 0x0c , 0x1f ) ;
F_53 ( V_3 , 0x3e , 0x04 ) ;
F_53 ( V_3 , 0xc3 , 0x39 ) ;
F_53 ( V_3 , 0x40 , 0x5c ) ;
} else if ( F_58 ( V_3 ) ) {
F_48 ( V_3 , 0x00 , V_35 -> V_65 & 0x03 ) ;
F_48 ( V_3 , 0x0d , 0x84 ) ;
F_48 ( V_3 , 0x3d , 0x10 ) ;
F_48 ( V_3 , 0x3e , 0x39 ) ;
F_48 ( V_3 , 0x4e , 0x3b ) ;
F_48 ( V_3 , 0x57 , 0xb6 ) ;
F_48 ( V_3 , 0x58 , 0x03 ) ;
F_48 ( V_3 , 0x8d , 0x18 ) ;
F_48 ( V_3 , 0x8e , 0x34 ) ;
F_48 ( V_3 , 0x93 , 0x8b ) ;
F_48 ( V_3 , 0x94 , 0x2d ) ;
F_48 ( V_3 , 0x96 , 0x01 ) ;
F_34 ( V_3 , 0x00 , 0xff ) ;
F_34 ( V_3 , 0x01 , 0xfe ) ;
F_34 ( V_3 , 0xc8 , 0x40 ) ;
F_34 ( V_3 , 0x12 , 0xfb ) ;
F_34 ( V_3 , 0x0c , 0x0d ) ;
F_53 ( V_3 , 0x3e , 0x00 ) ;
F_53 ( V_3 , 0xc3 , 0x39 ) ;
F_53 ( V_3 , 0x40 , 0x80 ) ;
} else {
F_43 ( 2 , V_51 , V_3 , L_20 ,
V_52 , V_35 -> V_65 ) ;
}
}
static int F_99 ( struct V_2 * V_3 ,
T_3 V_183 , T_3 V_184 , T_3 V_185 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
F_43 ( 2 , V_51 , V_3 , L_49 ,
V_52 , V_183 , V_35 -> V_65 ) ;
if ( V_183 == V_35 -> V_65 )
return 0 ;
V_35 -> V_65 = V_183 ;
F_96 ( V_3 ) ;
F_98 ( V_3 ) ;
F_95 ( V_3 ) ;
return 0 ;
}
static int F_100 ( struct V_2 * V_3 , unsigned int V_155 ,
enum V_186 * V_187 )
{
if ( V_155 )
return - V_133 ;
* V_187 = V_188 ;
return 0 ;
}
static int F_101 ( struct V_2 * V_3 ,
struct V_189 * V_190 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
V_190 -> V_82 = V_35 -> V_80 . V_81 . V_82 ;
V_190 -> V_89 = V_35 -> V_80 . V_81 . V_89 ;
V_190 -> V_187 = V_188 ;
V_190 -> V_191 = V_192 ;
if ( V_35 -> V_80 . V_81 . V_120 & V_121 ) {
V_190 -> V_193 = ( V_35 -> V_80 . V_81 . V_89 <= 576 ) ?
V_194 : V_195 ;
}
return 0 ;
}
static int F_102 ( struct V_2 * V_3 , T_3 V_135 , bool * V_196 )
{
const T_2 V_197 = F_18 ( V_3 , 0x43 ) ;
const T_2 V_198 = F_18 ( V_3 , 0x6b ) ;
const T_2 V_199 = F_18 ( V_3 , 0x70 ) ;
T_2 V_200 ;
T_2 V_201 ;
T_2 V_202 ;
if ( V_197 )
F_20 ( V_3 , 0x44 , V_197 ) ;
if ( V_199 )
F_20 ( V_3 , 0x71 , V_199 ) ;
if ( V_198 )
F_20 ( V_3 , 0x6c , V_198 ) ;
F_43 ( 2 , V_51 , V_3 , L_50 , V_52 ) ;
V_201 = V_197 & 0x98 ;
V_200 = F_58 ( V_3 ) ? ( V_198 & 0xc0 ) : 0 ;
if ( V_201 || V_200 ) {
F_43 ( 1 , V_51 , V_3 ,
L_51 ,
V_52 , V_201 , V_200 ) ;
F_46 ( V_3 , V_203 , NULL ) ;
if ( V_196 )
* V_196 = true ;
}
if ( V_198 & 0x01 ) {
F_43 ( 1 , V_51 , V_3 , L_52 , V_52 ,
( F_18 ( V_3 , 0x6a ) & 0x01 ) ? L_53 : L_54 ) ;
F_72 ( V_3 ) ;
if ( V_196 )
* V_196 = true ;
}
V_202 = F_18 ( V_3 , 0x70 ) & 0x1e ;
if ( V_202 ) {
F_43 ( 1 , V_51 , V_3 , L_55 , V_52 , V_202 ) ;
F_20 ( V_3 , 0x71 , V_202 ) ;
F_63 ( V_3 ) ;
if ( V_196 )
* V_196 = true ;
}
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , struct V_204 * V_59 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_2 * V_15 = NULL ;
if ( V_59 -> V_205 > V_206 )
return - V_133 ;
if ( V_59 -> V_207 == 0 )
return - V_133 ;
if ( V_59 -> V_207 > 2 )
return - V_133 ;
if ( V_59 -> V_208 > 1 )
return - V_133 ;
if ( V_59 -> V_208 == 1 )
V_59 -> V_207 = 1 ;
if ( ! V_59 -> V_59 )
return - V_133 ;
if ( V_59 -> V_207 > V_35 -> V_59 . V_207 )
V_59 -> V_207 = V_35 -> V_59 . V_207 ;
switch ( V_59 -> V_205 ) {
case V_209 :
case V_210 :
case V_211 :
case V_206 :
if ( V_35 -> V_59 . V_60 & ( 1 << V_59 -> V_205 ) )
V_15 = V_35 -> V_59 . V_59 ;
break;
default:
return - V_133 ;
break;
}
if ( ! V_15 )
return - V_212 ;
memcpy ( V_59 -> V_59 ,
V_15 + V_59 -> V_208 * 128 ,
V_59 -> V_207 * 128 ) ;
return 0 ;
}
static int F_104 ( const T_2 * V_59 )
{
T_2 V_213 ;
if ( ( V_59 [ 0x7e ] != 1 ) ||
( V_59 [ 0x80 ] != 0x02 ) ||
( V_59 [ 0x81 ] != 0x03 ) ) {
return - 1 ;
}
V_213 = V_59 [ 0x82 ] & 0x7f ;
if ( V_213 > 4 ) {
int V_25 = 0x84 ;
int V_214 = 0x80 + V_213 ;
do {
T_2 V_215 = V_59 [ V_25 ] >> 5 ;
T_2 V_44 = V_59 [ V_25 ] & 0x1f ;
if ( ( V_215 == 3 ) && ( V_44 >= 5 ) )
return V_25 + 4 ;
V_25 += V_44 + 1 ;
} while ( V_25 < V_214 );
}
return - 1 ;
}
static int F_105 ( struct V_2 * V_3 , struct V_204 * V_59 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_216 ;
int V_217 = 0 ;
int V_24 ;
int V_25 ;
if ( V_59 -> V_205 > V_206 )
return - V_133 ;
if ( V_59 -> V_208 != 0 )
return - V_133 ;
if ( V_59 -> V_207 == 0 ) {
V_35 -> V_59 . V_60 &= ~ ( 1 << V_59 -> V_205 ) ;
F_46 ( V_3 , V_58 , ( void * ) & V_35 -> V_59 . V_60 ) ;
F_37 ( V_3 , 0x77 , 0xf0 , V_35 -> V_59 . V_60 ) ;
V_35 -> V_152 . V_218 = 16 ;
V_35 -> V_152 . V_219 = 9 ;
if ( ! V_35 -> V_59 . V_60 )
V_35 -> V_59 . V_207 = 0 ;
F_43 ( 2 , V_51 , V_3 , L_56 ,
V_52 , V_59 -> V_205 , V_35 -> V_59 . V_60 ) ;
return 0 ;
}
if ( V_59 -> V_207 > 2 ) {
V_59 -> V_207 = 2 ;
return - V_220 ;
}
if ( ! V_59 -> V_59 )
return - V_133 ;
F_43 ( 2 , V_51 , V_3 , L_57 ,
V_52 , V_59 -> V_205 , V_35 -> V_59 . V_60 ) ;
F_106 ( & V_35 -> V_57 ) ;
F_46 ( V_3 , V_58 , ( void * ) & V_217 ) ;
F_37 ( V_3 , 0x77 , 0xf0 , 0x00 ) ;
V_216 = F_104 ( V_59 -> V_59 ) ;
if ( V_216 < 0 )
V_216 = 0xc0 ;
switch ( V_59 -> V_205 ) {
case V_209 :
V_35 -> V_221 [ 0 ] = V_59 -> V_59 [ V_216 ] ;
V_35 -> V_221 [ 1 ] = V_59 -> V_59 [ V_216 + 1 ] ;
break;
case V_210 :
F_36 ( V_3 , 0x70 , V_59 -> V_59 [ V_216 ] ) ;
F_36 ( V_3 , 0x71 , V_59 -> V_59 [ V_216 + 1 ] ) ;
break;
case V_211 :
F_36 ( V_3 , 0x72 , V_59 -> V_59 [ V_216 ] ) ;
F_36 ( V_3 , 0x73 , V_59 -> V_59 [ V_216 + 1 ] ) ;
break;
case V_206 :
F_36 ( V_3 , 0x74 , V_59 -> V_59 [ V_216 ] ) ;
F_36 ( V_3 , 0x75 , V_59 -> V_59 [ V_216 + 1 ] ) ;
break;
default:
return - V_133 ;
}
F_36 ( V_3 , 0x76 , V_216 & 0xff ) ;
F_37 ( V_3 , 0x77 , 0xbf , ( V_216 >> 2 ) & 0x40 ) ;
V_59 -> V_59 [ V_216 ] = V_35 -> V_221 [ 0 ] ;
V_59 -> V_59 [ V_216 + 1 ] = V_35 -> V_221 [ 1 ] ;
memcpy ( V_35 -> V_59 . V_59 , V_59 -> V_59 , 128 * V_59 -> V_207 ) ;
V_35 -> V_59 . V_207 = V_59 -> V_207 ;
V_35 -> V_152 = F_107 ( V_59 -> V_59 [ 0x15 ] ,
V_59 -> V_59 [ 0x16 ] ) ;
V_35 -> V_59 . V_60 |= 1 << V_59 -> V_205 ;
V_24 = F_42 ( V_3 , 128 * V_59 -> V_207 , V_35 -> V_59 . V_59 ) ;
if ( V_24 < 0 ) {
F_69 ( V_3 , L_58 , V_24 , V_59 -> V_205 ) ;
return V_24 ;
}
F_37 ( V_3 , 0x77 , 0xf0 , V_35 -> V_59 . V_60 ) ;
for ( V_25 = 0 ; V_25 < 1000 ; V_25 ++ ) {
if ( F_35 ( V_3 , 0x7d ) & V_35 -> V_59 . V_60 )
break;
F_108 ( 1 ) ;
}
if ( V_25 == 1000 ) {
F_69 ( V_3 , L_59 , V_35 -> V_59 . V_60 ) ;
return - V_22 ;
}
F_109 ( V_35 -> V_222 ,
& V_35 -> V_57 , V_223 / 10 ) ;
return 0 ;
}
static void F_110 ( struct V_2 * V_3 )
{
int V_25 ;
T_2 V_49 [ 14 ] ;
T_2 V_224 ;
T_2 V_225 ;
if ( ! F_77 ( V_3 ) ) {
F_60 ( V_3 , L_60 ) ;
return;
}
if ( ! ( F_18 ( V_3 , 0x60 ) & 0x01 ) ) {
F_60 ( V_3 , L_61 ) ;
return;
}
if ( F_18 ( V_3 , 0x83 ) & 0x01 ) {
F_60 ( V_3 , L_62 ) ;
F_20 ( V_3 , 0x85 , 0x01 ) ;
if ( F_18 ( V_3 , 0x83 ) & 0x01 ) {
F_60 ( V_3 , L_63 ) ;
F_20 ( V_3 , 0x85 , 0x01 ) ;
}
}
V_224 = F_27 ( V_3 , 0xe2 ) ;
V_225 = F_27 ( V_3 , 0xe1 ) ;
F_60 ( V_3 , L_64 ,
V_225 , V_224 ) ;
if ( V_225 != 0x02 )
return;
for ( V_25 = 0 ; V_25 < 14 ; V_25 ++ )
V_49 [ V_25 ] = F_27 ( V_3 , V_25 ) ;
F_60 ( V_3 ,
L_65 ,
V_49 [ 0 ] , V_49 [ 1 ] , V_49 [ 2 ] , V_49 [ 3 ] , V_49 [ 4 ] , V_49 [ 5 ] , V_49 [ 6 ] , V_49 [ 7 ] ,
V_49 [ 8 ] , V_49 [ 9 ] , V_49 [ 10 ] , V_49 [ 11 ] , V_49 [ 12 ] , V_49 [ 13 ] ) ;
}
static int F_111 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_79 V_80 ;
struct V_140 V_141 ;
T_2 V_226 = F_18 ( V_3 , 0x02 ) ;
char * V_227 [ 16 ] = {
L_66 , L_67 , L_68 , L_69 ,
L_68 , L_70 , L_68 , L_71 ,
L_68 , L_72 , L_73 ,
L_68 , L_68 , L_68 , L_68 , L_74
} ;
char * V_228 [ 16 ] = {
L_75 , L_76 ,
L_77 , L_78 ,
L_79 , L_80 ,
L_81 , L_82 ,
L_83 , L_83 , L_83 , L_83 , L_83 ,
L_83 , L_83 , L_84
} ;
char * V_229 [] = {
L_85 ,
L_75 ,
L_76 ,
} ;
char * V_230 [ 4 ] = {
L_86 ,
L_87 ,
L_88 ,
L_89
} ;
F_60 ( V_3 , L_90 ) ;
F_60 ( V_3 , L_91 , F_74 ( V_3 ) ? L_92 : L_93 ) ;
F_60 ( V_3 , L_94 ,
( ( F_35 ( V_3 , 0x7d ) & 0x01 ) ? L_95 : L_96 ) ,
( ( F_35 ( V_3 , 0x7d ) & 0x02 ) ? L_95 : L_96 ) ,
( ( F_35 ( V_3 , 0x7d ) & 0x04 ) ? L_95 : L_96 ) ,
( ( F_35 ( V_3 , 0x7d ) & 0x08 ) ? L_95 : L_96 ) ) ;
F_60 ( V_3 , L_97 , ! ! ( F_24 ( V_3 , 0x2a ) & 0x01 ) ?
L_98 : L_99 ) ;
F_60 ( V_3 , L_100 ) ;
F_60 ( V_3 , L_101 ,
( ( F_18 ( V_3 , 0x6f ) & 0x10 ) ? L_95 : L_96 ) ,
( ( F_18 ( V_3 , 0x6f ) & 0x08 ) ? L_95 : L_96 ) ,
( ( F_18 ( V_3 , 0x6f ) & 0x04 ) ? L_95 : L_96 ) ,
( ( F_18 ( V_3 , 0x6f ) & 0x02 ) ? L_95 : L_96 ) ) ;
F_60 ( V_3 , L_102 ,
F_75 ( V_3 ) ? L_103 : L_104 ) ;
F_60 ( V_3 , L_105 ,
F_76 ( V_3 ) ? L_103 : L_104 ) ;
F_60 ( V_3 , L_106 , F_78 ( V_3 ) ? L_103 : L_104 ) ;
F_60 ( V_3 , L_107 , F_79 ( V_3 ) ? L_103 : L_104 ) ;
F_60 ( V_3 , L_108 , F_81 ( V_3 ) ? L_103 : L_104 ) ;
F_60 ( V_3 , L_109 ,
( ! ! ( F_52 ( V_3 , 0xff ) & 0x10 ) ? L_93 : L_92 ) ) ;
F_60 ( V_3 , L_110 ,
F_18 ( V_3 , 0x01 ) & 0x0f , F_18 ( V_3 , 0x00 ) & 0x3f ,
( F_18 ( V_3 , 0x01 ) & 0x70 ) >> 4 ) ;
F_60 ( V_3 , L_111 ) ;
if ( F_86 ( V_3 , & V_141 ) )
F_60 ( V_3 , L_112 ) ;
else
F_60 ( V_3 , L_113 ,
V_141 . V_146 , V_141 . V_143 , V_141 . V_147 ,
V_141 . V_153 ? L_36 : L_37 ,
V_141 . V_148 , V_141 . V_150 ) ;
if ( F_91 ( V_3 , & V_80 ) )
F_60 ( V_3 , L_114 ) ;
else
F_92 ( V_3 -> V_182 , L_115 ,
& V_80 , true ) ;
F_92 ( V_3 -> V_182 , L_116 ,
& V_35 -> V_80 , true ) ;
if ( F_80 ( V_3 ) )
return 0 ;
F_60 ( V_3 , L_117 ) ;
F_60 ( V_3 , L_118 ,
V_229 [ V_35 -> V_118 ] ) ;
F_60 ( V_3 , L_119 ,
V_228 [ V_226 >> 4 ] ) ;
F_60 ( V_3 , L_120 ,
( V_226 & 0x02 ) ? L_121 : L_122 ,
( V_226 & 0x04 ) ? L_123 : L_124 ,
( ( V_226 & 0x04 ) ^ ( V_226 & 0x01 ) ) ?
L_98 : L_99 ) ;
F_60 ( V_3 , L_125 ,
V_227 [ F_52 ( V_3 , 0xfc ) >> 4 ] ) ;
if ( ! F_58 ( V_3 ) )
return 0 ;
F_60 ( V_3 , L_126 , F_77 ( V_3 ) ? L_53 : L_127 ) ;
F_60 ( V_3 , L_128 ,
( F_47 ( V_3 , 0x00 ) & 0x03 ) + 'A' ) ;
F_60 ( V_3 , L_129 ,
( F_47 ( V_3 , 0x05 ) & 0x40 ) ? L_104 : L_103 ) ;
F_60 ( V_3 , L_130 ,
( F_47 ( V_3 , 0x04 ) & 0x20 ) ? L_131 : L_132 ,
( F_47 ( V_3 , 0x04 ) & 0x10 ) ? L_133 : L_134 ) ;
if ( ! F_77 ( V_3 ) ) {
bool V_231 = F_47 ( V_3 , 0x04 ) & 0x01 ;
bool V_232 = F_47 ( V_3 , 0x18 ) & 0x01 ;
bool V_233 = F_18 ( V_3 , 0x65 ) & 0x40 ;
F_60 ( V_3 , L_135 ,
V_231 ? L_136 : L_137 ,
V_232 ? L_138 : L_139 ,
V_233 ? L_140 : L_98 ) ;
if ( V_231 && V_232 ) {
F_60 ( V_3 , L_141 ,
( F_47 ( V_3 , 0x07 ) & 0x20 ) ? L_142 : L_143 ) ;
}
F_60 ( V_3 , L_144 , ( F_47 ( V_3 , 0x5b ) << 12 ) +
( F_47 ( V_3 , 0x5c ) << 8 ) +
( F_47 ( V_3 , 0x5d ) & 0xf0 ) ) ;
F_60 ( V_3 , L_145 , ( ( F_47 ( V_3 , 0x5d ) & 0x0f ) << 16 ) +
( F_47 ( V_3 , 0x5e ) << 8 ) +
F_47 ( V_3 , 0x5f ) ) ;
F_60 ( V_3 , L_146 , ( F_47 ( V_3 , 0x04 ) & 0x40 ) ? L_93 : L_92 ) ;
F_60 ( V_3 , L_147 , V_230 [ ( F_47 ( V_3 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_110 ( V_3 ) ;
}
return 0 ;
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_234 * V_235 = & V_35 -> V_235 ;
F_48 ( V_3 , 0x48 ,
( V_235 -> V_236 ? 0x80 : 0 ) |
( V_235 -> V_237 ? 0x40 : 0 ) ) ;
F_96 ( V_3 ) ;
F_20 ( V_3 , 0x0c , 0x42 ) ;
F_20 ( V_3 , 0x0b , 0x44 ) ;
F_53 ( V_3 , 0xcf , 0x01 ) ;
F_21 ( V_3 , 0x02 , 0xf0 ,
V_235 -> V_238 << 3 |
V_235 -> V_239 << 2 |
V_235 -> V_240 << 1 |
V_235 -> V_241 << 0 ) ;
F_20 ( V_3 , 0x03 , V_235 -> V_242 ) ;
F_21 ( V_3 , 0x04 , 0x1f , V_235 -> V_243 << 5 ) ;
F_21 ( V_3 , 0x05 , 0xf0 , V_235 -> V_244 << 3 |
V_235 -> V_245 << 2 |
V_235 -> V_246 << 1 |
V_235 -> V_247 << 0 ) ;
F_53 ( V_3 , 0x69 , 0x30 ) ;
F_20 ( V_3 , 0x06 , 0xa0 | V_235 -> V_248 << 2 | V_235 -> V_249 << 1 ) ;
F_20 ( V_3 , 0x14 , 0x40 | V_235 -> V_250 << 4 |
V_235 -> V_251 << 2 |
V_235 -> V_252 ) ;
F_53 ( V_3 , 0xba , ( V_235 -> V_253 << 1 ) | 0x01 ) ;
F_53 ( V_3 , 0xf3 , 0xdc ) ;
F_53 ( V_3 , 0xf9 , 0x23 ) ;
F_53 ( V_3 , 0x45 , 0x23 ) ;
F_53 ( V_3 , 0xc9 , 0x2d ) ;
F_49 ( V_3 , 0x15 , 0xfc , 0x03 ) ;
F_49 ( V_3 , 0x1a , 0xf1 , 0x08 ) ;
F_49 ( V_3 , 0x68 , 0xf9 , 0x06 ) ;
F_34 ( V_3 , 0xb5 , 0x01 ) ;
F_34 ( V_3 , 0x02 , V_235 -> V_254 ) ;
F_21 ( V_3 , 0x30 , ~ ( 1 << 4 ) , V_235 -> V_255 << 4 ) ;
F_20 ( V_3 , 0x40 , 0xc2 ) ;
F_20 ( V_3 , 0x41 , 0xd7 ) ;
F_20 ( V_3 , 0x46 , 0x98 ) ;
F_20 ( V_3 , 0x6e , 0xc1 ) ;
F_20 ( V_3 , 0x73 , 0x1e ) ;
return F_113 ( V_3 -> V_256 ) ;
}
static void F_114 ( struct V_1 * V_35 )
{
if ( V_35 -> V_36 )
F_115 ( V_35 -> V_36 ) ;
if ( V_35 -> V_37 )
F_115 ( V_35 -> V_37 ) ;
if ( V_35 -> V_38 )
F_115 ( V_35 -> V_38 ) ;
if ( V_35 -> V_39 )
F_115 ( V_35 -> V_39 ) ;
if ( V_35 -> V_40 )
F_115 ( V_35 -> V_40 ) ;
if ( V_35 -> V_41 )
F_115 ( V_35 -> V_41 ) ;
if ( V_35 -> V_42 )
F_115 ( V_35 -> V_42 ) ;
if ( V_35 -> V_43 )
F_115 ( V_35 -> V_43 ) ;
if ( V_35 -> V_61 )
F_115 ( V_35 -> V_61 ) ;
if ( V_35 -> V_62 )
F_115 ( V_35 -> V_62 ) ;
if ( V_35 -> V_63 )
F_115 ( V_35 -> V_63 ) ;
if ( V_35 -> V_64 )
F_115 ( V_35 -> V_64 ) ;
}
static struct V_10 * F_116 ( struct V_2 * V_3 ,
T_2 V_17 , T_2 V_257 )
{
struct V_10 * V_11 = F_19 ( V_3 ) ;
if ( V_17 )
F_20 ( V_3 , V_257 , V_17 << 1 ) ;
return F_117 ( V_11 -> V_16 , F_18 ( V_3 , V_257 ) >> 1 ) ;
}
static int F_118 ( struct V_10 * V_11 ,
const struct V_258 * V_124 )
{
static const struct V_79 V_259 =
V_260 ;
struct V_1 * V_35 ;
struct V_234 * V_235 = V_11 -> V_261 . V_262 ;
struct V_263 * V_7 ;
struct V_2 * V_3 ;
int V_24 ;
if ( ! F_119 ( V_11 -> V_16 , V_264 ) )
return - V_22 ;
F_120 ( 1 , V_51 , V_11 , L_148 ,
V_11 -> V_17 << 1 ) ;
V_35 = F_121 ( & V_11 -> V_261 , sizeof( * V_35 ) , V_265 ) ;
if ( ! V_35 ) {
F_14 ( V_11 , L_149 ) ;
return - V_266 ;
}
V_35 -> V_171 = true ;
V_35 -> V_65 = ~ 0 ;
if ( ! V_235 ) {
F_14 ( V_11 , L_150 ) ;
return - V_267 ;
}
V_35 -> V_235 = * V_235 ;
V_35 -> V_80 = V_259 ;
V_3 = & V_35 -> V_3 ;
F_122 ( V_3 , V_11 , & V_268 ) ;
V_3 -> V_18 |= V_269 ;
if ( F_12 ( V_11 , 0xfb , false ) != 0x68 ) {
F_60 ( V_3 , L_151 ,
V_11 -> V_17 << 1 ) ;
return - V_267 ;
}
V_7 = & V_35 -> V_7 ;
F_123 ( V_7 , 9 ) ;
F_124 ( V_7 , & V_270 ,
V_125 , - 128 , 127 , 1 , 0 ) ;
F_124 ( V_7 , & V_270 ,
V_126 , 0 , 255 , 1 , 128 ) ;
F_124 ( V_7 , & V_270 ,
V_127 , 0 , 255 , 1 , 128 ) ;
F_124 ( V_7 , & V_270 ,
V_128 , 0 , 128 , 1 , 0 ) ;
V_35 -> V_75 = F_124 ( V_7 , NULL ,
V_271 , 0 , 0x0f , 0 , 0 ) ;
V_35 -> V_272 =
F_125 ( V_7 , & V_270 ,
V_129 , V_123 ,
0 , V_119 ) ;
V_35 -> V_273 =
F_126 ( V_7 , & V_274 , NULL ) ;
V_35 -> V_275 =
F_126 ( V_7 , & V_276 , NULL ) ;
V_35 -> V_277 =
F_126 ( V_7 , & V_278 , NULL ) ;
V_3 -> V_256 = V_7 ;
if ( V_7 -> error ) {
V_24 = V_7 -> error ;
goto V_279;
}
V_35 -> V_75 -> V_280 = true ;
V_35 -> V_272 -> V_280 = true ;
V_35 -> V_273 -> V_280 = true ;
V_35 -> V_275 -> V_280 = true ;
V_35 -> V_277 -> V_280 = true ;
if ( F_63 ( V_3 ) ) {
V_24 = - V_267 ;
goto V_279;
}
V_35 -> V_36 = F_116 ( V_3 , V_235 -> V_36 , 0xf3 ) ;
V_35 -> V_37 = F_116 ( V_3 , V_235 -> V_37 , 0xf4 ) ;
V_35 -> V_38 = F_116 ( V_3 , V_235 -> V_38 , 0xf5 ) ;
V_35 -> V_39 = F_116 ( V_3 , V_235 -> V_39 , 0xf6 ) ;
V_35 -> V_40 = F_116 ( V_3 , V_235 -> V_40 , 0xf7 ) ;
V_35 -> V_41 = F_116 ( V_3 , V_235 -> V_41 , 0xf8 ) ;
V_35 -> V_42 = F_116 ( V_3 , V_235 -> V_42 , 0xf9 ) ;
V_35 -> V_43 = F_116 ( V_3 , V_235 -> V_43 , 0xfa ) ;
V_35 -> V_61 = F_116 ( V_3 , V_235 -> V_61 , 0xfb ) ;
V_35 -> V_62 = F_116 ( V_3 , V_235 -> V_62 , 0xfc ) ;
V_35 -> V_63 = F_116 ( V_3 , V_235 -> V_63 , 0xfd ) ;
V_35 -> V_64 = F_116 ( V_3 , V_235 -> V_64 , 0xfe ) ;
if ( ! V_35 -> V_36 || ! V_35 -> V_37 || ! V_35 -> V_38 ||
! V_35 -> V_39 || ! V_35 -> V_40 || ! V_35 -> V_41 ||
! V_35 -> V_42 || ! V_35 -> V_43 || ! V_35 -> V_61 ||
! V_35 -> V_62 || ! V_35 -> V_63 || ! V_35 -> V_64 ) {
V_24 = - V_266 ;
F_69 ( V_3 , L_152 ) ;
goto V_281;
}
V_35 -> V_222 = F_127 ( V_11 -> V_182 ) ;
if ( ! V_35 -> V_222 ) {
F_69 ( V_3 , L_153 ) ;
V_24 = - V_266 ;
goto V_281;
}
F_128 ( & V_35 -> V_57 ,
F_44 ) ;
V_35 -> V_205 . V_18 = V_282 ;
V_24 = F_129 ( & V_3 -> V_283 , 1 , & V_35 -> V_205 , 0 ) ;
if ( V_24 )
goto V_284;
V_24 = F_112 ( V_3 ) ;
if ( V_24 )
goto V_285;
F_60 ( V_3 , L_154 , V_11 -> V_182 ,
V_11 -> V_17 << 1 , V_11 -> V_16 -> V_182 ) ;
return 0 ;
V_285:
F_130 ( & V_3 -> V_283 ) ;
V_284:
F_131 ( & V_35 -> V_57 ) ;
F_132 ( V_35 -> V_222 ) ;
V_281:
F_114 ( V_35 ) ;
V_279:
F_133 ( V_7 ) ;
return V_24 ;
}
static int F_134 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_135 ( V_11 ) ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
F_131 ( & V_35 -> V_57 ) ;
F_132 ( V_35 -> V_222 ) ;
F_136 ( V_3 ) ;
F_130 ( & V_3 -> V_283 ) ;
F_114 ( F_1 ( V_3 ) ) ;
F_133 ( V_3 -> V_256 ) ;
return 0 ;
}
