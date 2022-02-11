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
return V_9 -> V_10 + V_9 -> V_11 + V_9 -> V_12 ;
}
static inline unsigned F_5 ( const struct V_8 * V_9 )
{
return V_9 -> V_13 + V_9 -> V_10 + V_9 -> V_11 + V_9 -> V_12 ;
}
static inline unsigned F_6 ( const struct V_8 * V_9 )
{
return V_9 -> V_14 + V_9 -> V_15 + V_9 -> V_16 ;
}
static inline unsigned F_7 ( const struct V_8 * V_9 )
{
return V_9 -> V_17 + V_9 -> V_14 + V_9 -> V_15 + V_9 -> V_16 ;
}
static T_1 F_8 ( struct V_18 * V_19 ,
T_2 V_20 , bool V_21 )
{
union V_22 V_23 ;
if ( ! F_9 ( V_19 -> V_24 , V_19 -> V_25 , V_19 -> V_26 ,
V_27 , V_20 ,
V_28 , & V_23 ) )
return V_23 . V_29 ;
if ( V_21 )
F_10 ( V_19 , L_1 ,
V_19 -> V_25 , V_20 ) ;
return - V_30 ;
}
static T_1 F_11 ( struct V_18 * V_19 , T_2 V_20 )
{
return F_8 ( V_19 , V_20 , true ) ;
}
static T_1 F_12 ( struct V_18 * V_19 ,
T_2 V_20 , T_2 V_31 )
{
union V_22 V_23 ;
int V_32 ;
int V_33 ;
V_23 . V_29 = V_31 ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_32 = F_9 ( V_19 -> V_24 , V_19 -> V_25 ,
V_19 -> V_26 ,
V_34 , V_20 ,
V_28 , & V_23 ) ;
if ( ! V_32 )
break;
}
if ( V_32 < 0 )
F_10 ( V_19 , L_2 ,
V_19 -> V_25 , V_20 , V_31 ) ;
return V_32 ;
}
static T_1 F_13 ( struct V_18 * V_19 ,
T_2 V_20 , unsigned V_35 , const T_2 * V_36 )
{
union V_22 V_23 ;
if ( V_35 > V_37 )
V_35 = V_37 ;
V_23 . V_38 [ 0 ] = V_35 ;
memcpy ( V_23 . V_38 + 1 , V_36 , V_35 ) ;
return F_9 ( V_19 -> V_24 , V_19 -> V_25 , V_19 -> V_26 ,
V_34 , V_20 ,
V_39 , & V_23 ) ;
}
static inline int F_14 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_18 * V_19 = F_15 ( V_3 ) ;
return F_11 ( V_19 , V_40 ) ;
}
static inline int F_16 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_18 * V_19 = F_15 ( V_3 ) ;
return F_12 ( V_19 , V_40 , V_41 ) ;
}
static inline int F_17 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_42 , T_2 V_41 )
{
return F_16 ( V_3 , V_40 , ( F_14 ( V_3 , V_40 ) & V_42 ) | V_41 ) ;
}
static inline int F_18 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_44 , V_40 ) ;
}
static inline int F_19 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_44 , V_40 , V_41 ) ;
}
static inline int F_20 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_45 , V_40 ) ;
}
static inline int F_21 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_45 , V_40 , V_41 ) ;
}
static inline int F_22 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_42 , T_2 V_41 )
{
return F_21 ( V_3 , V_40 , ( F_20 ( V_3 , V_40 ) & V_42 ) | V_41 ) ;
}
static inline int F_23 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_46 , V_40 ) ;
}
static inline int F_24 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_46 , V_40 , V_41 ) ;
}
static inline int F_25 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_47 , V_40 ) ;
}
static inline int F_26 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_47 , V_40 , V_41 ) ;
}
static inline int F_27 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_48 , V_40 ) ;
}
static inline int F_28 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_48 , V_40 , V_41 ) ;
}
static inline int F_29 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_49 , V_40 ) ;
}
static inline int F_30 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_49 , V_40 , V_41 ) ;
}
static inline int F_31 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_50 , V_40 ) ;
}
static inline int F_32 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_50 , V_40 , V_41 ) ;
}
static inline int F_33 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_42 , T_2 V_41 )
{
return F_32 ( V_3 , V_40 , ( F_31 ( V_3 , V_40 ) & V_42 ) | V_41 ) ;
}
static inline int F_34 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_51 , V_40 ) ;
}
static inline int F_35 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_51 , V_40 , V_41 ) ;
}
static inline int F_36 ( struct V_2 * V_3 , unsigned V_52 , T_2 * V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_43 -> V_51 ;
T_2 V_53 [ 1 ] = { 0 } ;
T_2 V_54 [ 256 ] ;
struct V_55 V_56 [ 2 ] = {
{
. V_25 = V_19 -> V_25 ,
. V_52 = 1 ,
. V_57 = V_53
} ,
{
. V_25 = V_19 -> V_25 ,
. V_26 = V_58 ,
. V_52 = V_52 ,
. V_57 = V_54
} ,
} ;
if ( F_37 ( V_19 -> V_24 , V_56 , 2 ) < 0 )
return - V_30 ;
memcpy ( V_41 , V_54 , V_52 ) ;
return 0 ;
}
static void F_38 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_39 ( V_60 ) ;
struct V_1 * V_43 = F_2 ( V_62 , struct V_1 ,
V_63 ) ;
struct V_2 * V_3 = & V_43 -> V_3 ;
F_40 ( 2 , V_64 , V_3 , L_3 , V_65 ) ;
F_41 ( V_3 , V_66 , ( void * ) 1 ) ;
}
static inline int F_42 ( struct V_2 * V_3 ,
unsigned V_52 , const T_2 * V_41 )
{
struct V_18 * V_19 = F_15 ( V_3 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
int V_32 = 0 ;
int V_33 ;
F_40 ( 2 , V_64 , V_3 , L_4 , V_65 , V_52 ) ;
F_41 ( V_3 , V_66 , ( void * ) 0 ) ;
F_33 ( V_3 , 0x77 , 0xf0 , 0x0 ) ;
for ( V_33 = 0 ; ! V_32 && V_33 < V_52 ; V_33 += V_37 )
V_32 = F_13 ( V_43 -> V_51 , V_33 ,
V_37 , V_41 + V_33 ) ;
if ( V_32 )
return V_32 ;
F_33 ( V_3 , 0x77 , 0xf0 , 0x1 ) ;
for ( V_33 = 0 ; V_33 < 1000 ; V_33 ++ ) {
if ( F_31 ( V_3 , 0x7d ) & 1 )
break;
F_43 ( 1 ) ;
}
if ( V_33 == 1000 ) {
F_10 ( V_19 , L_5 ) ;
return - V_30 ;
}
F_44 ( V_43 -> V_67 ,
& V_43 -> V_63 , V_68 / 10 ) ;
return 0 ;
}
static inline int F_45 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_69 , V_40 ) ;
}
static inline int F_46 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_69 , V_40 , V_41 ) ;
}
static inline int F_47 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_70 , V_40 ) ;
}
static inline int F_48 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_70 , V_40 , V_41 ) ;
}
static inline int F_49 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_71 , V_40 ) ;
}
static inline int F_50 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_71 , V_40 , V_41 ) ;
}
static inline int F_51 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_42 , T_2 V_41 )
{
return F_50 ( V_3 , V_40 , ( F_49 ( V_3 , V_40 ) & V_42 ) | V_41 ) ;
}
static inline int F_52 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_11 ( V_43 -> V_72 , V_40 ) ;
}
static inline int F_53 ( struct V_2 * V_3 , T_2 V_40 , T_2 V_41 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_12 ( V_43 -> V_72 , V_40 , V_41 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
F_55 ( V_3 , L_6 ) ;
F_55 ( V_3 , L_7 ) ;
F_55 ( V_3 , L_8 ) ;
F_55 ( V_3 , L_9 ) ;
F_55 ( V_3 , L_10 ) ;
F_55 ( V_3 , L_11 ) ;
F_55 ( V_3 , L_12 ) ;
F_55 ( V_3 , L_13 ) ;
F_55 ( V_3 , L_14 ) ;
F_55 ( V_3 , L_15 ) ;
F_55 ( V_3 , L_16 ) ;
F_55 ( V_3 , L_17 ) ;
F_55 ( V_3 , L_18 ) ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_73 * V_40 )
{
V_40 -> V_74 = 1 ;
switch ( V_40 -> V_40 >> 8 ) {
case 0 :
V_40 -> V_41 = F_14 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 1 :
V_40 -> V_41 = F_18 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 2 :
V_40 -> V_41 = F_20 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 3 :
V_40 -> V_41 = F_23 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 4 :
V_40 -> V_41 = F_25 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 5 :
V_40 -> V_41 = F_27 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 6 :
V_40 -> V_41 = F_29 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 7 :
V_40 -> V_41 = F_31 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 8 :
V_40 -> V_41 = F_34 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 9 :
V_40 -> V_41 = F_45 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 0xa :
V_40 -> V_41 = F_47 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 0xb :
V_40 -> V_41 = F_49 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
case 0xc :
V_40 -> V_41 = F_52 ( V_3 , V_40 -> V_40 & 0xff ) ;
break;
default:
F_55 ( V_3 , L_19 , V_40 -> V_40 ) ;
F_54 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_57 ( struct V_2 * V_3 ,
const struct V_73 * V_40 )
{
switch ( V_40 -> V_40 >> 8 ) {
case 0 :
F_16 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 1 :
F_19 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 2 :
F_21 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 3 :
F_24 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 4 :
F_26 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 5 :
F_28 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 6 :
F_30 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 7 :
F_32 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 8 :
F_35 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 9 :
F_46 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 0xa :
F_48 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 0xb :
F_50 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
case 0xc :
F_53 ( V_3 , V_40 -> V_40 & 0xff , V_40 -> V_41 & 0xff ) ;
break;
default:
F_55 ( V_3 , L_19 , V_40 -> V_40 ) ;
F_54 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_59 ( V_43 -> V_75 ,
( ( F_14 ( V_3 , 0x6f ) & 0x10 ) >> 4 ) ) ;
}
static int F_60 ( struct V_2 * V_3 ,
T_2 V_76 ,
const struct V_77 * V_78 ,
const struct V_79 * V_80 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
int V_33 ;
for ( V_33 = 0 ; V_78 [ V_33 ] . V_80 . V_81 . V_13 ; V_33 ++ ) {
if ( ! F_61 ( V_80 , & V_78 [ V_33 ] . V_80 ,
V_82 ? 250000 : 1000000 ) )
continue;
F_16 ( V_3 , 0x00 , V_78 [ V_33 ] . V_83 ) ;
F_16 ( V_3 , 0x01 , ( V_78 [ V_33 ] . V_84 << 4 ) +
V_76 ) ;
return 0 ;
}
return - 1 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
int V_32 ;
F_40 ( 1 , V_64 , V_3 , L_20 , V_65 ) ;
F_16 ( V_3 , 0x16 , 0x43 ) ;
F_16 ( V_3 , 0x17 , 0x5a ) ;
F_51 ( V_3 , 0x81 , 0xef , 0x00 ) ;
F_50 ( V_3 , 0x8f , 0x00 ) ;
F_50 ( V_3 , 0x90 , 0x00 ) ;
F_50 ( V_3 , 0xa2 , 0x00 ) ;
F_50 ( V_3 , 0xa3 , 0x00 ) ;
F_50 ( V_3 , 0xa4 , 0x00 ) ;
F_50 ( V_3 , 0xa5 , 0x00 ) ;
F_50 ( V_3 , 0xa6 , 0x00 ) ;
F_50 ( V_3 , 0xa7 , 0x00 ) ;
F_50 ( V_3 , 0xab , 0x00 ) ;
F_50 ( V_3 , 0xac , 0x00 ) ;
switch ( V_43 -> V_85 ) {
case V_86 :
case V_87 :
V_32 = F_60 ( V_3 ,
0x01 , V_88 , V_80 ) ;
if ( V_32 )
V_32 = F_60 ( V_3 ,
0x02 , V_89 , V_80 ) ;
break;
case V_90 :
V_32 = F_60 ( V_3 ,
0x05 , V_91 , V_80 ) ;
if ( V_32 )
V_32 = F_60 ( V_3 ,
0x06 , V_92 , V_80 ) ;
break;
default:
F_40 ( 2 , V_64 , V_3 , L_21 ,
V_65 , V_43 -> V_85 ) ;
V_32 = - 1 ;
break;
}
return V_32 ;
}
static void F_63 ( struct V_2 * V_3 ,
const struct V_8 * V_81 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_18 * V_19 = F_15 ( V_3 ) ;
T_3 V_13 = F_5 ( V_81 ) ;
T_3 V_17 = F_7 ( V_81 ) ;
T_4 V_93 = V_81 -> V_11 + V_81 -> V_12 - 4 ;
T_4 V_94 = V_13 - V_81 -> V_10 ;
T_4 V_95 = V_17 - V_81 -> V_14 ;
T_4 V_96 = V_81 -> V_15 + V_81 -> V_16 ;
T_4 V_97 = ( ( ( T_3 ) V_81 -> V_98 / 100 ) > 0 ) ?
( ( V_13 * ( V_99 / 100 ) ) / ( ( T_3 ) V_81 -> V_98 / 100 ) ) : 0 ;
const T_2 V_100 [ 2 ] = {
0xc0 | ( ( V_13 >> 8 ) & 0x1f ) ,
V_13 & 0xff
} ;
F_40 ( 2 , V_64 , V_3 , L_22 , V_65 ) ;
switch ( V_43 -> V_85 ) {
case V_86 :
case V_87 :
F_16 ( V_3 , 0x00 , 0x07 ) ;
F_16 ( V_3 , 0x01 , 0x02 ) ;
F_51 ( V_3 , 0x81 , 0xef , 0x10 ) ;
if ( F_13 ( V_19 , 0x16 , 2 , V_100 ) ) {
F_64 ( V_3 , L_23 ) ;
break;
}
F_50 ( V_3 , 0xa2 , ( V_93 >> 4 ) & 0xff ) ;
F_50 ( V_3 , 0xa3 , ( ( V_93 & 0x0f ) << 4 ) |
( ( V_94 >> 8 ) & 0x0f ) ) ;
F_50 ( V_3 , 0xa4 , V_94 & 0xff ) ;
F_50 ( V_3 , 0xa5 , ( V_95 >> 4 ) & 0xff ) ;
F_50 ( V_3 , 0xa6 , ( ( V_95 & 0xf ) << 4 ) |
( ( V_96 >> 8 ) & 0xf ) ) ;
F_50 ( V_3 , 0xa7 , V_96 & 0xff ) ;
break;
case V_90 :
F_16 ( V_3 , 0x00 , 0x02 ) ;
F_16 ( V_3 , 0x01 , 0x06 ) ;
break;
default:
F_40 ( 2 , V_64 , V_3 , L_21 ,
V_65 , V_43 -> V_85 ) ;
break;
}
F_50 ( V_3 , 0x8f , ( V_97 >> 8 ) & 0x7 ) ;
F_50 ( V_3 , 0x90 , V_97 & 0xff ) ;
F_50 ( V_3 , 0xab , ( V_17 >> 4 ) & 0xff ) ;
F_50 ( V_3 , 0xac , ( V_17 & 0x0f ) << 4 ) ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
switch ( V_43 -> V_101 ) {
case V_102 :
if ( V_82 && ! ( F_45 ( V_3 , 0x05 ) & 0x80 ) ) {
if ( V_43 -> V_80 . V_81 . V_103 & V_104 ) {
F_17 ( V_3 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_17 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
}
} else {
F_17 ( V_3 , 0x02 , 0x0f , 0xf0 ) ;
}
break;
case V_105 :
F_17 ( V_3 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_106 :
F_17 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
break;
}
}
static int F_66 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
switch ( V_5 -> V_107 ) {
case V_108 :
F_50 ( V_3 , 0x3c , V_5 -> V_41 ) ;
return 0 ;
case V_109 :
F_50 ( V_3 , 0x3a , V_5 -> V_41 ) ;
return 0 ;
case V_110 :
F_50 ( V_3 , 0x3b , V_5 -> V_41 ) ;
return 0 ;
case V_111 :
F_50 ( V_3 , 0x3d , V_5 -> V_41 ) ;
return 0 ;
case V_112 :
V_43 -> V_101 = V_5 -> V_41 ;
F_65 ( V_3 ) ;
return 0 ;
case V_113 :
F_30 ( V_3 , 0xc8 , V_5 -> V_41 ) ;
return 0 ;
case V_114 :
F_51 ( V_3 , 0xbf , ~ 0x04 , ( V_5 -> V_41 << 2 ) ) ;
return 0 ;
case V_115 :
F_50 ( V_3 , 0xc0 , ( V_5 -> V_41 & 0xff0000 ) >> 16 ) ;
F_50 ( V_3 , 0xc1 , ( V_5 -> V_41 & 0x00ff00 ) >> 8 ) ;
F_50 ( V_3 , 0xc2 , ( T_2 ) ( V_5 -> V_41 & 0x0000ff ) ) ;
return 0 ;
}
return - V_116 ;
}
static inline bool F_67 ( struct V_2 * V_3 )
{
return F_14 ( V_3 , 0x0c ) & 0x24 ;
}
static inline bool F_68 ( struct V_2 * V_3 )
{
return ! ( F_14 ( V_3 , 0x6a ) & 0x10 ) ;
}
static inline bool F_69 ( struct V_2 * V_3 )
{
return ( F_14 ( V_3 , 0x6a ) & 0xe0 ) != 0xe0 ;
}
static inline bool F_70 ( struct V_2 * V_3 )
{
return ( ( F_49 ( V_3 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_71 ( struct V_2 * V_3 )
{
return ! ( F_49 ( V_3 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
bool V_117 ;
V_117 = F_67 ( V_3 ) ;
V_117 |= F_71 ( V_3 ) ;
V_117 |= F_70 ( V_3 ) ;
if ( V_82 ) {
V_117 |= F_69 ( V_3 ) ;
V_117 |= F_68 ( V_3 ) ;
}
return V_117 ;
}
static inline bool F_73 ( struct V_2 * V_3 )
{
return F_14 ( V_3 , 0x12 ) & 0x01 ;
}
static int F_74 ( struct V_2 * V_3 , T_3 * V_118 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
* V_118 = 0 ;
* V_118 |= F_67 ( V_3 ) ? V_119 : 0 ;
* V_118 |= F_72 ( V_3 ) ? V_120 : 0 ;
if ( F_73 ( V_3 ) )
* V_118 |= V_82 ? V_121 : V_122 ;
F_40 ( 1 , V_64 , V_3 , L_24 , V_65 , * V_118 ) ;
return 0 ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_79 * V_80 , const char * V_123 , bool V_124 )
{
struct V_8 * V_81 = & V_80 -> V_81 ;
T_3 V_125 , V_126 ;
if ( V_80 -> type != V_127 )
return;
V_125 = F_5 ( V_81 ) ;
V_126 = F_7 ( V_81 ) ;
F_55 ( V_3 , L_25 ,
V_123 , V_81 -> V_13 , V_81 -> V_17 , V_81 -> V_128 ? L_26 : L_27 ,
( V_125 * V_126 ) > 0 ? ( ( T_3 ) V_81 -> V_98 /
( V_125 * V_126 ) ) : 0 ,
V_125 , V_126 ) ;
if ( V_124 ) {
F_55 ( V_3 , L_28 ,
V_81 -> V_10 ,
( V_81 -> V_129 & V_130 ) ? L_29 : L_30 ,
V_81 -> V_11 , V_81 -> V_12 ) ;
F_55 ( V_3 , L_31 ,
V_81 -> V_14 ,
( V_81 -> V_129 & V_131 ) ? L_29 : L_30 ,
V_81 -> V_15 , V_81 -> V_16 ) ;
F_55 ( V_3 , L_32 ,
V_81 -> V_98 , V_81 -> V_26 , V_81 -> V_103 ) ;
}
}
static int F_76 ( struct V_2 * V_3 ,
struct V_132 * V_133 ,
struct V_79 * V_80 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
T_3 V_134 = ( V_99 * 8 ) / V_133 -> V_135 ;
T_3 V_136 ;
int V_33 ;
for ( V_33 = 0 ; V_137 [ V_33 ] . V_81 . V_17 ; V_33 ++ ) {
if ( F_7 ( & V_137 [ V_33 ] . V_81 ) != V_133 -> V_138 + 1 )
continue;
if ( V_137 [ V_33 ] . V_81 . V_15 != V_133 -> V_139 )
continue;
V_136 = V_134 * F_5 ( & V_137 [ V_33 ] . V_81 ) ;
if ( ( V_136 < V_137 [ V_33 ] . V_81 . V_98 + 1000000 ) &&
( V_136 > V_137 [ V_33 ] . V_81 . V_98 - 1000000 ) ) {
* V_80 = V_137 [ V_33 ] ;
return 0 ;
}
}
if ( F_77 ( V_133 -> V_138 + 1 , V_134 , V_133 -> V_139 ,
( V_133 -> V_140 == '+' ? V_130 : 0 ) |
( V_133 -> V_141 == '+' ? V_131 : 0 ) ,
V_80 ) )
return 0 ;
if ( F_78 ( V_133 -> V_138 + 1 , V_134 , V_133 -> V_139 ,
( V_133 -> V_140 == '+' ? V_130 : 0 ) |
( V_133 -> V_141 == '+' ? V_131 : 0 ) ,
V_43 -> V_142 , V_80 ) )
return 0 ;
F_40 ( 2 , V_64 , V_3 ,
L_33 ,
V_65 , V_133 -> V_139 , V_133 -> V_138 , V_133 -> V_135 ,
V_133 -> V_140 , V_133 -> V_141 ) ;
return - 1 ;
}
static int F_79 ( struct V_2 * V_3 , struct V_132 * V_133 )
{
if ( F_71 ( V_3 ) || F_70 ( V_3 ) ) {
F_40 ( 2 , V_64 , V_3 , L_34 , V_65 ) ;
return - 1 ;
}
V_133 -> V_135 = ( ( F_49 ( V_3 , 0xb1 ) & 0x3f ) << 8 ) | F_49 ( V_3 , 0xb2 ) ;
V_133 -> V_138 = ( ( F_49 ( V_3 , 0xb3 ) & 0x7 ) << 8 ) | F_49 ( V_3 , 0xb4 ) ;
V_133 -> V_139 = F_49 ( V_3 , 0xb3 ) >> 3 ;
V_133 -> V_128 = F_14 ( V_3 , 0x12 ) & 0x10 ;
if ( ( F_49 ( V_3 , 0xb5 ) & 0x03 ) == 0x01 ) {
V_133 -> V_140 = ( ( F_49 ( V_3 , 0xb5 ) & 0x10 ) ?
( ( F_49 ( V_3 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_133 -> V_141 = ( ( F_49 ( V_3 , 0xb5 ) & 0x40 ) ?
( ( F_49 ( V_3 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_133 -> V_140 = 'x' ;
V_133 -> V_141 = 'x' ;
}
if ( F_71 ( V_3 ) || F_70 ( V_3 ) ) {
F_40 ( 2 , V_64 , V_3 ,
L_35 , V_65 ) ;
return - 1 ;
}
if ( V_133 -> V_138 < 239 || V_133 -> V_135 < 8 || V_133 -> V_135 == 0x3fff ) {
F_40 ( 2 , V_64 , V_3 , L_36 , V_65 ) ;
memset ( V_133 , 0 , sizeof( struct V_132 ) ) ;
return - 1 ;
}
F_40 ( 2 , V_64 , V_3 ,
L_37 ,
V_65 , V_133 -> V_138 , V_133 -> V_135 , V_133 -> V_139 ,
V_133 -> V_140 , V_133 -> V_141 ,
V_133 -> V_128 ? L_38 : L_39 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_143 * V_80 )
{
if ( V_80 -> V_144 >= F_81 ( V_137 ) - 1 )
return - V_116 ;
memset ( V_80 -> V_145 , 0 , sizeof( V_80 -> V_145 ) ) ;
V_80 -> V_80 = V_137 [ V_80 -> V_144 ] ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_146 * V_147 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
V_147 -> type = V_127 ;
V_147 -> V_81 . V_148 = 1920 ;
V_147 -> V_81 . V_149 = 1200 ;
V_147 -> V_81 . V_150 = 27000000 ;
if ( V_82 )
V_147 -> V_81 . V_151 = 225000000 ;
else
V_147 -> V_81 . V_151 = 170000000 ;
V_147 -> V_81 . V_103 = V_104 | V_152 |
V_153 | V_154 ;
V_147 -> V_81 . V_155 = V_156 |
V_157 | V_158 ;
return 0 ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
int V_33 ;
for ( V_33 = 0 ; V_137 [ V_33 ] . V_81 . V_13 ; V_33 ++ ) {
if ( F_61 ( V_80 , & V_137 [ V_33 ] ,
V_82 ? 250000 : 1000000 ) ) {
* V_80 = V_137 [ V_33 ] ;
break;
}
}
}
static int F_84 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_8 * V_81 = & V_80 -> V_81 ;
struct V_132 V_133 ;
if ( ! V_80 )
return - V_116 ;
memset ( V_80 , 0 , sizeof( struct V_79 ) ) ;
if ( F_72 ( V_3 ) ) {
F_40 ( 1 , V_64 , V_3 , L_40 , V_65 ) ;
return - V_159 ;
}
if ( F_79 ( V_3 , & V_133 ) ) {
F_40 ( 1 , V_64 , V_3 , L_41 , V_65 ) ;
return - V_159 ;
}
V_81 -> V_128 = V_133 . V_128 ?
V_160 : V_161 ;
if ( V_82 ) {
V_80 -> type = V_127 ;
V_81 -> V_13 = ( F_45 ( V_3 , 0x07 ) & 0x0f ) * 256 + F_45 ( V_3 , 0x08 ) ;
V_81 -> V_17 = ( F_45 ( V_3 , 0x09 ) & 0x0f ) * 256 + F_45 ( V_3 , 0x0a ) ;
V_81 -> V_98 = ( F_45 ( V_3 , 0x06 ) * 1000000 ) +
( ( F_45 ( V_3 , 0x3b ) & 0x30 ) >> 4 ) * 250000 ;
V_81 -> V_10 = ( F_45 ( V_3 , 0x20 ) & 0x03 ) * 256 +
F_45 ( V_3 , 0x21 ) ;
V_81 -> V_11 = ( F_45 ( V_3 , 0x22 ) & 0x03 ) * 256 +
F_45 ( V_3 , 0x23 ) ;
V_81 -> V_12 = ( F_45 ( V_3 , 0x24 ) & 0x03 ) * 256 +
F_45 ( V_3 , 0x25 ) ;
V_81 -> V_14 = ( ( F_45 ( V_3 , 0x2a ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x2b ) ) / 2 ;
V_81 -> V_15 = ( ( F_45 ( V_3 , 0x2e ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x2f ) ) / 2 ;
V_81 -> V_16 = ( ( F_45 ( V_3 , 0x32 ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x33 ) ) / 2 ;
V_81 -> V_129 = ( ( F_45 ( V_3 , 0x05 ) & 0x10 ) ? V_131 : 0 ) |
( ( F_45 ( V_3 , 0x05 ) & 0x20 ) ? V_130 : 0 ) ;
if ( V_81 -> V_128 == V_160 ) {
V_81 -> V_17 += ( F_45 ( V_3 , 0x0b ) & 0x0f ) * 256 +
F_45 ( V_3 , 0x0c ) ;
V_81 -> V_162 = ( ( F_45 ( V_3 , 0x2c ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x2d ) ) / 2 ;
V_81 -> V_163 = ( ( F_45 ( V_3 , 0x30 ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x31 ) ) / 2 ;
V_81 -> V_16 = ( ( F_45 ( V_3 , 0x34 ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x35 ) ) / 2 ;
}
F_83 ( V_3 , V_80 ) ;
} else {
if ( ! F_76 ( V_3 , & V_133 , V_80 ) )
goto V_164;
V_133 . V_139 += 1 ;
F_40 ( 1 , V_64 , V_3 , L_42 , V_65 , V_133 . V_139 ) ;
if ( ! F_76 ( V_3 , & V_133 , V_80 ) )
goto V_164;
V_133 . V_139 -= 2 ;
F_40 ( 1 , V_64 , V_3 , L_43 , V_65 , V_133 . V_139 ) ;
if ( F_76 ( V_3 , & V_133 , V_80 ) ) {
if ( V_43 -> V_165 ) {
F_40 ( 1 , V_64 , V_3 , L_44 , V_65 ) ;
F_51 ( V_3 , 0x86 , 0xf9 , 0x00 ) ;
F_51 ( V_3 , 0x86 , 0xf9 , 0x04 ) ;
F_51 ( V_3 , 0x86 , 0xf9 , 0x02 ) ;
V_43 -> V_165 = false ;
return - V_159 ;
}
F_40 ( 1 , V_64 , V_3 , L_45 , V_65 ) ;
return - V_166 ;
}
V_43 -> V_165 = true ;
}
V_164:
if ( F_72 ( V_3 ) ) {
F_40 ( 1 , V_64 , V_3 , L_46 , V_65 ) ;
memset ( V_80 , 0 , sizeof( struct V_79 ) ) ;
return - V_159 ;
}
if ( ( ! V_82 && V_81 -> V_98 > 170000000 ) ||
( V_82 && V_81 -> V_98 > 225000000 ) ) {
F_40 ( 1 , V_64 , V_3 , L_47 ,
V_65 , ( T_3 ) V_81 -> V_98 ) ;
return - V_166 ;
}
if ( V_64 > 1 )
F_75 ( V_3 , V_80 ,
L_48 , true ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_8 * V_81 ;
int V_32 ;
if ( ! V_80 )
return - V_116 ;
V_81 = & V_80 -> V_81 ;
if ( ( ! V_82 && V_81 -> V_98 > 170000000 ) ||
( V_82 && V_81 -> V_98 > 225000000 ) ) {
F_40 ( 1 , V_64 , V_3 , L_47 ,
V_65 , ( T_3 ) V_81 -> V_98 ) ;
return - V_166 ;
}
F_83 ( V_3 , V_80 ) ;
V_43 -> V_80 = * V_80 ;
F_50 ( V_3 , 0x91 , V_81 -> V_128 ? 0x50 : 0x10 ) ;
V_32 = F_62 ( V_3 , V_80 ) ;
if ( V_32 ) {
F_63 ( V_3 , V_81 ) ;
}
F_65 ( V_3 ) ;
if ( V_64 > 1 )
F_75 ( V_3 , V_80 ,
L_49 , true ) ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
* V_80 = V_43 -> V_80 ;
return 0 ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
switch ( V_43 -> V_85 ) {
case V_86 :
case V_87 :
F_16 ( V_3 , 0x15 , 0xb0 ) ;
break;
case V_90 :
F_46 ( V_3 , 0x1a , 0x0a ) ;
F_46 ( V_3 , 0x01 , 0x00 ) ;
F_16 ( V_3 , 0x15 , 0xa0 ) ;
break;
default:
F_40 ( 2 , V_64 , V_3 , L_21 ,
V_65 , V_43 -> V_85 ) ;
break;
}
}
static void F_88 ( struct V_2 * V_3 )
{
F_16 ( V_3 , 0x15 , 0xbe ) ;
F_46 ( V_3 , 0x1a , 0x1a ) ;
F_46 ( V_3 , 0x01 , 0x78 ) ;
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
switch ( V_43 -> V_85 ) {
case V_86 :
case V_87 :
F_46 ( V_3 , 0x0d , 0x04 ) ;
F_46 ( V_3 , 0x3d , 0x00 ) ;
F_46 ( V_3 , 0x3e , 0x74 ) ;
F_46 ( V_3 , 0x4e , 0x3b ) ;
F_46 ( V_3 , 0x57 , 0x74 ) ;
F_46 ( V_3 , 0x58 , 0x63 ) ;
F_46 ( V_3 , 0x8d , 0x18 ) ;
F_46 ( V_3 , 0x8e , 0x34 ) ;
F_46 ( V_3 , 0x93 , 0x88 ) ;
F_46 ( V_3 , 0x94 , 0x2e ) ;
F_46 ( V_3 , 0x96 , 0x00 ) ;
F_30 ( V_3 , 0x00 , 0x08 ) ;
F_30 ( V_3 , 0x01 , 0x06 ) ;
F_30 ( V_3 , 0xc8 , 0x00 ) ;
F_30 ( V_3 , 0x12 , 0x7b ) ;
F_30 ( V_3 , 0x0c , 0x1f ) ;
F_50 ( V_3 , 0x3e , 0x04 ) ;
F_50 ( V_3 , 0xc3 , 0x39 ) ;
F_50 ( V_3 , 0x40 , 0x5c ) ;
break;
case V_90 :
F_46 ( V_3 , 0x0d , 0x84 ) ;
F_46 ( V_3 , 0x3d , 0x10 ) ;
F_46 ( V_3 , 0x3e , 0x39 ) ;
F_46 ( V_3 , 0x4e , 0x3b ) ;
F_46 ( V_3 , 0x57 , 0xb6 ) ;
F_46 ( V_3 , 0x58 , 0x03 ) ;
F_46 ( V_3 , 0x8d , 0x18 ) ;
F_46 ( V_3 , 0x8e , 0x34 ) ;
F_46 ( V_3 , 0x93 , 0x8b ) ;
F_46 ( V_3 , 0x94 , 0x2d ) ;
F_46 ( V_3 , 0x96 , 0x01 ) ;
F_30 ( V_3 , 0x00 , 0xff ) ;
F_30 ( V_3 , 0x01 , 0xfe ) ;
F_30 ( V_3 , 0xc8 , 0x40 ) ;
F_30 ( V_3 , 0x12 , 0xfb ) ;
F_30 ( V_3 , 0x0c , 0x0d ) ;
F_50 ( V_3 , 0x3e , 0x00 ) ;
F_50 ( V_3 , 0xc3 , 0x39 ) ;
F_50 ( V_3 , 0x40 , 0x80 ) ;
break;
default:
F_40 ( 2 , V_64 , V_3 , L_21 ,
V_65 , V_43 -> V_85 ) ;
break;
}
}
static int F_90 ( struct V_2 * V_3 ,
T_3 V_167 , T_3 V_168 , T_3 V_169 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
F_40 ( 2 , V_64 , V_3 , L_50 , V_65 , V_167 ) ;
V_43 -> V_85 = V_167 ;
F_88 ( V_3 ) ;
F_89 ( V_3 ) ;
F_87 ( V_3 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , unsigned int V_144 ,
enum V_170 * V_171 )
{
if ( V_144 )
return - V_116 ;
* V_171 = V_172 ;
return 0 ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_173 * V_174 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
V_174 -> V_13 = V_43 -> V_80 . V_81 . V_13 ;
V_174 -> V_17 = V_43 -> V_80 . V_81 . V_17 ;
V_174 -> V_171 = V_172 ;
V_174 -> V_175 = V_176 ;
if ( V_43 -> V_80 . V_81 . V_103 & V_104 ) {
V_174 -> V_177 = ( V_43 -> V_80 . V_81 . V_17 <= 576 ) ?
V_178 : V_179 ;
}
return 0 ;
}
static int F_93 ( struct V_2 * V_3 , T_3 V_118 , bool * V_180 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
T_2 V_181 , V_182 , V_183 ;
V_181 = F_14 ( V_3 , 0x43 ) & 0x98 ;
if ( V_181 )
F_16 ( V_3 , 0x44 , V_181 ) ;
V_182 = V_82 ? ( F_14 ( V_3 , 0x6b ) & 0xc0 ) : 0 ;
if ( V_182 )
F_16 ( V_3 , 0x6c , V_182 ) ;
if ( V_181 || V_182 ) {
F_40 ( 1 , V_64 , V_3 ,
L_51 ,
V_65 , V_181 , V_182 ) ;
F_41 ( V_3 , V_184 , NULL ) ;
if ( V_180 )
* V_180 = true ;
}
V_183 = F_14 ( V_3 , 0x70 ) & 0x10 ;
if ( V_183 ) {
F_40 ( 1 , V_64 , V_3 , L_52 , V_65 , V_183 ) ;
F_16 ( V_3 , 0x71 , V_183 ) ;
F_58 ( V_3 ) ;
if ( V_180 )
* V_180 = true ;
}
return 0 ;
}
static int F_94 ( struct V_2 * V_3 , struct V_185 * V_186 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
if ( V_186 -> V_187 != 0 )
return - V_116 ;
if ( V_186 -> V_188 == 0 )
return - V_116 ;
if ( V_186 -> V_189 >= V_43 -> V_190 )
return - V_116 ;
if ( V_186 -> V_189 + V_186 -> V_188 > V_43 -> V_190 )
V_186 -> V_188 = V_43 -> V_190 - V_186 -> V_189 ;
if ( ! V_186 -> V_186 )
return - V_116 ;
memcpy ( V_186 -> V_186 + V_186 -> V_189 * 128 ,
V_43 -> V_186 + V_186 -> V_189 * 128 ,
V_186 -> V_188 * 128 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , struct V_185 * V_186 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
int V_32 ;
if ( V_186 -> V_187 != 0 )
return - V_116 ;
if ( V_186 -> V_189 != 0 )
return - V_116 ;
if ( V_186 -> V_188 == 0 ) {
F_41 ( V_3 , V_66 , ( void * ) 0 ) ;
F_33 ( V_3 , 0x77 , 0xf0 , 0x0 ) ;
V_43 -> V_190 = 0 ;
V_43 -> V_142 . V_191 = 16 ;
V_43 -> V_142 . V_192 = 9 ;
return 0 ;
}
if ( V_186 -> V_188 > 2 )
return - V_193 ;
if ( ! V_186 -> V_186 )
return - V_116 ;
memcpy ( V_43 -> V_186 , V_186 -> V_186 , 128 * V_186 -> V_188 ) ;
V_43 -> V_190 = V_186 -> V_188 ;
V_43 -> V_142 = F_96 ( V_186 -> V_186 [ 0x15 ] ,
V_186 -> V_186 [ 0x16 ] ) ;
V_32 = F_42 ( V_3 , 128 * V_186 -> V_188 , V_43 -> V_186 ) ;
if ( V_32 < 0 )
F_64 ( V_3 , L_53 , V_32 ) ;
return V_32 ;
}
static void F_97 ( struct V_2 * V_3 )
{
int V_33 ;
T_2 V_57 [ 14 ] ;
T_2 V_194 ;
T_2 V_195 ;
if ( ! ( F_45 ( V_3 , 0x05 ) & 0x80 ) ) {
F_55 ( V_3 , L_54 ) ;
return;
}
if ( ! ( F_14 ( V_3 , 0x60 ) & 0x01 ) ) {
F_55 ( V_3 , L_55 ) ;
return;
}
if ( F_14 ( V_3 , 0x83 ) & 0x01 ) {
F_55 ( V_3 , L_56 ) ;
F_16 ( V_3 , 0x85 , 0x01 ) ;
if ( F_14 ( V_3 , 0x83 ) & 0x01 ) {
F_55 ( V_3 , L_57 ) ;
F_16 ( V_3 , 0x85 , 0x01 ) ;
}
}
V_194 = F_23 ( V_3 , 0xe2 ) ;
V_195 = F_23 ( V_3 , 0xe1 ) ;
F_55 ( V_3 , L_58 ,
V_195 , V_194 ) ;
if ( V_195 != 0x02 )
return;
for ( V_33 = 0 ; V_33 < 14 ; V_33 ++ )
V_57 [ V_33 ] = F_23 ( V_3 , V_33 ) ;
F_55 ( V_3 ,
L_59 ,
V_57 [ 0 ] , V_57 [ 1 ] , V_57 [ 2 ] , V_57 [ 3 ] , V_57 [ 4 ] , V_57 [ 5 ] , V_57 [ 6 ] , V_57 [ 7 ] ,
V_57 [ 8 ] , V_57 [ 9 ] , V_57 [ 10 ] , V_57 [ 11 ] , V_57 [ 12 ] , V_57 [ 13 ] ) ;
}
static int F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_79 V_80 ;
struct V_132 V_133 ;
T_2 V_196 = F_14 ( V_3 , 0x02 ) ;
char * V_197 [ 16 ] = {
L_60 , L_61 , L_62 , L_63 ,
L_62 , L_64 , L_62 , L_65 ,
L_62 , L_66 , L_67 ,
L_62 , L_62 , L_62 , L_62 , L_68
} ;
char * V_198 [ 16 ] = {
L_69 , L_70 ,
L_71 , L_72 ,
L_73 , L_74 ,
L_75 , L_76 ,
L_77 , L_77 , L_77 , L_77 , L_77 ,
L_77 , L_77 , L_78
} ;
char * V_199 [] = {
L_79 ,
L_69 ,
L_70 ,
} ;
F_55 ( V_3 , L_80 ) ;
F_55 ( V_3 , L_81 , F_67 ( V_3 ) ? L_82 : L_83 ) ;
F_55 ( V_3 , L_84 , V_43 -> V_200 ?
L_85 : ( V_82 ? L_86 : L_87 ) ) ;
F_55 ( V_3 , L_88 , ( ( F_31 ( V_3 , 0x7d ) & 0x01 ) &&
( F_31 ( V_3 , 0x77 ) & 0x01 ) ) ? L_89 : L_90 ) ;
F_55 ( V_3 , L_91 , ! ! ( F_20 ( V_3 , 0x2a ) & 0x01 ) ?
L_89 : L_92 ) ;
F_55 ( V_3 , L_93 ) ;
F_55 ( V_3 , L_94 ,
( F_14 ( V_3 , 0x6f ) & 0x10 ) ? L_95 : L_96 ) ;
F_55 ( V_3 , L_97 ,
F_68 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_98 ,
F_69 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_99 , F_70 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_100 , F_71 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_101 , F_73 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_102 ,
( ! ! ( F_49 ( V_3 , 0xff ) & 0x10 ) ? L_83 : L_82 ) ) ;
F_55 ( V_3 , L_103 ,
F_14 ( V_3 , 0x01 ) & 0x0f , F_14 ( V_3 , 0x00 ) & 0x3f ,
( F_14 ( V_3 , 0x01 ) & 0x70 ) >> 4 ) ;
F_55 ( V_3 , L_104 ) ;
if ( F_79 ( V_3 , & V_133 ) )
F_55 ( V_3 , L_105 ) ;
else
F_55 ( V_3 , L_106 ,
V_133 . V_138 , V_133 . V_135 , V_133 . V_139 ,
V_133 . V_128 ? L_38 : L_39 ,
V_133 . V_140 , V_133 . V_141 ) ;
if ( F_84 ( V_3 , & V_80 ) )
F_55 ( V_3 , L_107 ) ;
else
F_75 ( V_3 , & V_80 , L_108 , true ) ;
F_75 ( V_3 , & V_43 -> V_80 , L_109 , true ) ;
F_55 ( V_3 , L_110 ) ;
F_55 ( V_3 , L_111 ,
V_199 [ V_43 -> V_101 ] ) ;
F_55 ( V_3 , L_112 ,
V_198 [ V_196 >> 4 ] ) ;
F_55 ( V_3 , L_113 ,
( V_196 & 0x02 ) ? L_114 : L_115 ,
( V_196 & 0x04 ) ? L_116 : L_117 ,
( ( V_196 & 0x04 ) ^ ( V_196 & 0x01 ) ) ?
L_89 : L_92 ) ;
F_55 ( V_3 , L_118 ,
V_197 [ F_49 ( V_3 , 0xfc ) >> 4 ] ) ;
if ( V_82 ) {
F_55 ( V_3 , L_119 ) ;
F_55 ( V_3 , L_120 ,
F_45 ( V_3 , 0x05 ) & 0x40 ? L_95 : L_96 ) ;
F_97 ( V_3 ) ;
}
return 0 ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_201 * V_202 = & V_43 -> V_202 ;
F_46 ( V_3 , 0x48 ,
( V_202 -> V_203 ? 0x80 : 0 ) |
( V_202 -> V_204 ? 0x40 : 0 ) ) ;
F_88 ( V_3 ) ;
F_16 ( V_3 , 0x0c , 0x42 ) ;
F_16 ( V_3 , 0x0b , 0x44 ) ;
F_50 ( V_3 , 0xcf , 0x01 ) ;
F_17 ( V_3 , 0x02 , 0xf0 ,
V_202 -> V_205 << 3 |
V_202 -> V_206 << 2 |
V_202 -> V_207 << 1 |
V_202 -> V_208 << 0 ) ;
F_16 ( V_3 , 0x03 , V_202 -> V_209 ) ;
F_17 ( V_3 , 0x04 , 0x1f , V_202 -> V_210 << 5 ) ;
F_17 ( V_3 , 0x05 , 0xf0 , V_202 -> V_211 << 3 |
V_202 -> V_212 << 2 |
V_202 -> V_213 << 1 |
V_202 -> V_214 << 0 ) ;
F_50 ( V_3 , 0x69 , 0x30 ) ;
F_16 ( V_3 , 0x06 , 0xa6 ) ;
F_16 ( V_3 , 0x14 , 0x7f ) ;
F_50 ( V_3 , 0xba , ( V_202 -> V_215 << 1 ) | 0x01 ) ;
F_50 ( V_3 , 0xf3 , 0xdc ) ;
F_50 ( V_3 , 0xf9 , 0x23 ) ;
F_50 ( V_3 , 0x45 , 0x23 ) ;
F_50 ( V_3 , 0xc9 , 0x2d ) ;
F_30 ( V_3 , 0xb5 , 0x01 ) ;
F_30 ( V_3 , 0x02 , V_202 -> V_216 ) ;
F_17 ( V_3 , 0x30 , ~ ( 1 << 4 ) , V_202 -> V_217 << 4 ) ;
F_16 ( V_3 , 0x40 , 0xc2 ) ;
F_16 ( V_3 , 0x41 , 0xd7 ) ;
F_16 ( V_3 , 0x46 , 0x98 ) ;
F_16 ( V_3 , 0x6e , 0xc0 ) ;
F_16 ( V_3 , 0x73 , 0x10 ) ;
return F_100 ( V_3 -> V_218 ) ;
}
static void F_101 ( struct V_1 * V_43 )
{
if ( V_43 -> V_44 )
F_102 ( V_43 -> V_44 ) ;
if ( V_43 -> V_45 )
F_102 ( V_43 -> V_45 ) ;
if ( V_43 -> V_46 )
F_102 ( V_43 -> V_46 ) ;
if ( V_43 -> V_47 )
F_102 ( V_43 -> V_47 ) ;
if ( V_43 -> V_48 )
F_102 ( V_43 -> V_48 ) ;
if ( V_43 -> V_49 )
F_102 ( V_43 -> V_49 ) ;
if ( V_43 -> V_50 )
F_102 ( V_43 -> V_50 ) ;
if ( V_43 -> V_51 )
F_102 ( V_43 -> V_51 ) ;
if ( V_43 -> V_69 )
F_102 ( V_43 -> V_69 ) ;
if ( V_43 -> V_70 )
F_102 ( V_43 -> V_70 ) ;
if ( V_43 -> V_71 )
F_102 ( V_43 -> V_71 ) ;
if ( V_43 -> V_72 )
F_102 ( V_43 -> V_72 ) ;
}
static struct V_18 * F_103 ( struct V_2 * V_3 ,
T_2 V_25 , T_2 V_219 )
{
struct V_18 * V_19 = F_15 ( V_3 ) ;
if ( V_25 )
F_16 ( V_3 , V_219 , V_25 << 1 ) ;
return F_104 ( V_19 -> V_24 , F_14 ( V_3 , V_219 ) >> 1 ) ;
}
static int F_105 ( struct V_18 * V_19 ,
const struct V_220 * V_107 )
{
struct V_1 * V_43 ;
struct V_201 * V_202 = V_19 -> V_221 . V_222 ;
struct V_223 * V_7 ;
struct V_2 * V_3 ;
int V_32 ;
if ( ! F_106 ( V_19 -> V_24 , V_224 ) )
return - V_30 ;
F_107 ( 1 , V_64 , V_19 , L_121 ,
V_19 -> V_25 << 1 ) ;
V_43 = F_108 ( & V_19 -> V_221 , sizeof( * V_43 ) , V_225 ) ;
if ( ! V_43 ) {
F_10 ( V_19 , L_122 ) ;
return - V_226 ;
}
if ( ! V_202 ) {
F_10 ( V_19 , L_123 ) ;
return - V_227 ;
}
memcpy ( & V_43 -> V_202 , V_202 , sizeof( V_43 -> V_202 ) ) ;
V_3 = & V_43 -> V_3 ;
F_109 ( V_3 , V_19 , & V_228 ) ;
V_3 -> V_26 |= V_229 ;
V_43 -> V_200 = V_202 -> V_200 ;
if ( F_8 ( V_19 , 0xfb , false ) != 0x68 ) {
F_55 ( V_3 , L_124 ,
V_19 -> V_25 << 1 ) ;
return - V_227 ;
}
V_7 = & V_43 -> V_7 ;
F_110 ( V_7 , 9 ) ;
F_111 ( V_7 , & V_230 ,
V_108 , - 128 , 127 , 1 , 0 ) ;
F_111 ( V_7 , & V_230 ,
V_109 , 0 , 255 , 1 , 128 ) ;
F_111 ( V_7 , & V_230 ,
V_110 , 0 , 255 , 1 , 128 ) ;
F_111 ( V_7 , & V_230 ,
V_111 , 0 , 128 , 1 , 0 ) ;
V_43 -> V_75 = F_111 ( V_7 , NULL ,
V_231 , 0 , 1 , 0 , 0 ) ;
V_43 -> V_75 -> V_232 = true ;
V_43 -> V_233 =
F_112 ( V_7 , & V_230 ,
V_112 , V_106 ,
0 , V_102 ) ;
V_43 -> V_233 -> V_232 = true ;
V_43 -> V_234 =
F_113 ( V_7 , & V_235 , NULL ) ;
V_43 -> V_234 -> V_232 = true ;
V_43 -> V_236 =
F_113 ( V_7 , & V_237 , NULL ) ;
V_43 -> V_236 -> V_232 = true ;
V_43 -> V_238 =
F_113 ( V_7 , & V_239 , NULL ) ;
V_43 -> V_238 -> V_232 = true ;
V_3 -> V_218 = V_7 ;
if ( V_7 -> error ) {
V_32 = V_7 -> error ;
goto V_240;
}
if ( F_58 ( V_3 ) ) {
V_32 = - V_227 ;
goto V_240;
}
V_43 -> V_44 = F_103 ( V_3 , V_202 -> V_44 , 0xf3 ) ;
V_43 -> V_45 = F_103 ( V_3 , V_202 -> V_45 , 0xf4 ) ;
V_43 -> V_46 = F_103 ( V_3 , V_202 -> V_46 , 0xf5 ) ;
V_43 -> V_47 = F_103 ( V_3 , V_202 -> V_47 , 0xf6 ) ;
V_43 -> V_48 = F_103 ( V_3 , V_202 -> V_48 , 0xf7 ) ;
V_43 -> V_49 = F_103 ( V_3 , V_202 -> V_49 , 0xf8 ) ;
V_43 -> V_50 = F_103 ( V_3 , V_202 -> V_50 , 0xf9 ) ;
V_43 -> V_51 = F_103 ( V_3 , V_202 -> V_51 , 0xfa ) ;
V_43 -> V_69 = F_103 ( V_3 , V_202 -> V_69 , 0xfb ) ;
V_43 -> V_70 = F_103 ( V_3 , V_202 -> V_70 , 0xfc ) ;
V_43 -> V_71 = F_103 ( V_3 , V_202 -> V_71 , 0xfd ) ;
V_43 -> V_72 = F_103 ( V_3 , V_202 -> V_72 , 0xfe ) ;
if ( ! V_43 -> V_44 || ! V_43 -> V_45 || ! V_43 -> V_46 ||
! V_43 -> V_47 || ! V_43 -> V_48 || ! V_43 -> V_49 ||
! V_43 -> V_50 || ! V_43 -> V_51 || ! V_43 -> V_69 ||
! V_43 -> V_70 || ! V_43 -> V_71 || ! V_43 -> V_72 ) {
V_32 = - V_226 ;
F_64 ( V_3 , L_125 ) ;
goto V_241;
}
V_43 -> V_165 = true ;
V_43 -> V_67 = F_114 ( V_19 -> V_242 ) ;
if ( ! V_43 -> V_67 ) {
F_64 ( V_3 , L_126 ) ;
V_32 = - V_226 ;
goto V_241;
}
F_115 ( & V_43 -> V_63 ,
F_38 ) ;
V_43 -> V_187 . V_26 = V_243 ;
V_32 = F_116 ( & V_3 -> V_244 , 1 , & V_43 -> V_187 , 0 ) ;
if ( V_32 )
goto V_245;
V_32 = F_99 ( V_3 ) ;
if ( V_32 )
goto V_246;
F_55 ( V_3 , L_127 , V_19 -> V_242 ,
V_19 -> V_25 << 1 , V_19 -> V_24 -> V_242 ) ;
return 0 ;
V_246:
F_117 ( & V_3 -> V_244 ) ;
V_245:
F_118 ( & V_43 -> V_63 ) ;
F_119 ( V_43 -> V_67 ) ;
V_241:
F_101 ( V_43 ) ;
V_240:
F_120 ( V_7 ) ;
return V_32 ;
}
static int F_121 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_122 ( V_19 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
F_118 ( & V_43 -> V_63 ) ;
F_119 ( V_43 -> V_67 ) ;
F_123 ( V_3 ) ;
F_117 ( & V_3 -> V_244 ) ;
F_101 ( F_1 ( V_3 ) ) ;
F_120 ( V_3 -> V_218 ) ;
return 0 ;
}
