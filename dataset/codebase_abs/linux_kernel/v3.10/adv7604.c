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
struct V_18 * V_19 = F_15 ( V_3 ) ;
if ( ! F_57 ( V_19 , & V_40 -> V_74 ) )
return - V_75 ;
if ( ! F_58 ( V_76 ) )
return - V_77 ;
V_40 -> V_78 = 1 ;
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
static int F_59 ( struct V_2 * V_3 ,
const struct V_73 * V_40 )
{
struct V_18 * V_19 = F_15 ( V_3 ) ;
if ( ! F_57 ( V_19 , & V_40 -> V_74 ) )
return - V_75 ;
if ( ! F_58 ( V_76 ) )
return - V_77 ;
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
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
return F_61 ( V_43 -> V_79 ,
( ( F_14 ( V_3 , 0x6f ) & 0x10 ) >> 4 ) ) ;
}
static int F_62 ( struct V_2 * V_3 ,
T_2 V_80 ,
const struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
int V_33 ;
for ( V_33 = 0 ; V_82 [ V_33 ] . V_84 . V_85 . V_13 ; V_33 ++ ) {
if ( ! F_63 ( V_84 , & V_82 [ V_33 ] . V_84 ,
V_86 ? 250000 : 1000000 ) )
continue;
F_16 ( V_3 , 0x00 , V_82 [ V_33 ] . V_87 ) ;
F_16 ( V_3 , 0x01 , ( V_82 [ V_33 ] . V_88 << 4 ) +
V_80 ) ;
return 0 ;
}
return - 1 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_83 * V_84 )
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
switch ( V_43 -> V_89 ) {
case V_90 :
case V_91 :
V_32 = F_62 ( V_3 ,
0x01 , V_92 , V_84 ) ;
if ( V_32 )
V_32 = F_62 ( V_3 ,
0x02 , V_93 , V_84 ) ;
break;
case V_94 :
V_32 = F_62 ( V_3 ,
0x05 , V_95 , V_84 ) ;
if ( V_32 )
V_32 = F_62 ( V_3 ,
0x06 , V_96 , V_84 ) ;
break;
default:
F_40 ( 2 , V_64 , V_3 , L_21 ,
V_65 , V_43 -> V_89 ) ;
V_32 = - 1 ;
break;
}
return V_32 ;
}
static void F_65 ( struct V_2 * V_3 ,
const struct V_8 * V_85 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_18 * V_19 = F_15 ( V_3 ) ;
T_3 V_13 = F_5 ( V_85 ) ;
T_3 V_17 = F_7 ( V_85 ) ;
T_4 V_97 = V_85 -> V_11 + V_85 -> V_12 - 4 ;
T_4 V_98 = V_13 - V_85 -> V_10 ;
T_4 V_99 = V_17 - V_85 -> V_14 ;
T_4 V_100 = V_85 -> V_15 + V_85 -> V_16 ;
T_4 V_101 = ( ( ( T_3 ) V_85 -> V_102 / 100 ) > 0 ) ?
( ( V_13 * ( V_103 / 100 ) ) / ( ( T_3 ) V_85 -> V_102 / 100 ) ) : 0 ;
const T_2 V_104 [ 2 ] = {
0xc0 | ( ( V_13 >> 8 ) & 0x1f ) ,
V_13 & 0xff
} ;
F_40 ( 2 , V_64 , V_3 , L_22 , V_65 ) ;
switch ( V_43 -> V_89 ) {
case V_90 :
case V_91 :
F_16 ( V_3 , 0x00 , 0x07 ) ;
F_16 ( V_3 , 0x01 , 0x02 ) ;
F_51 ( V_3 , 0x81 , 0xef , 0x10 ) ;
if ( F_13 ( V_19 , 0x16 , 2 , V_104 ) ) {
F_66 ( V_3 , L_23 ) ;
break;
}
F_50 ( V_3 , 0xa2 , ( V_97 >> 4 ) & 0xff ) ;
F_50 ( V_3 , 0xa3 , ( ( V_97 & 0x0f ) << 4 ) |
( ( V_98 >> 8 ) & 0x0f ) ) ;
F_50 ( V_3 , 0xa4 , V_98 & 0xff ) ;
F_50 ( V_3 , 0xa5 , ( V_99 >> 4 ) & 0xff ) ;
F_50 ( V_3 , 0xa6 , ( ( V_99 & 0xf ) << 4 ) |
( ( V_100 >> 8 ) & 0xf ) ) ;
F_50 ( V_3 , 0xa7 , V_100 & 0xff ) ;
break;
case V_94 :
F_16 ( V_3 , 0x00 , 0x02 ) ;
F_16 ( V_3 , 0x01 , 0x06 ) ;
break;
default:
F_40 ( 2 , V_64 , V_3 , L_21 ,
V_65 , V_43 -> V_89 ) ;
break;
}
F_50 ( V_3 , 0x8f , ( V_101 >> 8 ) & 0x7 ) ;
F_50 ( V_3 , 0x90 , V_101 & 0xff ) ;
F_50 ( V_3 , 0xab , ( V_17 >> 4 ) & 0xff ) ;
F_50 ( V_3 , 0xac , ( V_17 & 0x0f ) << 4 ) ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
switch ( V_43 -> V_105 ) {
case V_106 :
if ( V_86 && ! ( F_45 ( V_3 , 0x05 ) & 0x80 ) ) {
if ( V_43 -> V_84 . V_85 . V_107 & V_108 ) {
F_17 ( V_3 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_17 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
}
} else {
F_17 ( V_3 , 0x02 , 0x0f , 0xf0 ) ;
}
break;
case V_109 :
F_17 ( V_3 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_110 :
F_17 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
break;
}
}
static int F_68 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
switch ( V_5 -> V_111 ) {
case V_112 :
F_50 ( V_3 , 0x3c , V_5 -> V_41 ) ;
return 0 ;
case V_113 :
F_50 ( V_3 , 0x3a , V_5 -> V_41 ) ;
return 0 ;
case V_114 :
F_50 ( V_3 , 0x3b , V_5 -> V_41 ) ;
return 0 ;
case V_115 :
F_50 ( V_3 , 0x3d , V_5 -> V_41 ) ;
return 0 ;
case V_116 :
V_43 -> V_105 = V_5 -> V_41 ;
F_67 ( V_3 ) ;
return 0 ;
case V_117 :
F_30 ( V_3 , 0xc8 , V_5 -> V_41 ) ;
return 0 ;
case V_118 :
F_51 ( V_3 , 0xbf , ~ 0x04 , ( V_5 -> V_41 << 2 ) ) ;
return 0 ;
case V_119 :
F_50 ( V_3 , 0xc0 , ( V_5 -> V_41 & 0xff0000 ) >> 16 ) ;
F_50 ( V_3 , 0xc1 , ( V_5 -> V_41 & 0x00ff00 ) >> 8 ) ;
F_50 ( V_3 , 0xc2 , ( T_2 ) ( V_5 -> V_41 & 0x0000ff ) ) ;
return 0 ;
}
return - V_75 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_120 * V_121 )
{
struct V_18 * V_19 = F_15 ( V_3 ) ;
return F_70 ( V_19 , V_121 , V_122 , 0 ) ;
}
static inline bool F_71 ( struct V_2 * V_3 )
{
return F_14 ( V_3 , 0x0c ) & 0x24 ;
}
static inline bool F_72 ( struct V_2 * V_3 )
{
return ! ( F_14 ( V_3 , 0x6a ) & 0x10 ) ;
}
static inline bool F_73 ( struct V_2 * V_3 )
{
return ( F_14 ( V_3 , 0x6a ) & 0xe0 ) != 0xe0 ;
}
static inline bool F_74 ( struct V_2 * V_3 )
{
return ( ( F_49 ( V_3 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_75 ( struct V_2 * V_3 )
{
return ! ( F_49 ( V_3 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
bool V_123 ;
V_123 = F_71 ( V_3 ) ;
V_123 |= F_75 ( V_3 ) ;
V_123 |= F_74 ( V_3 ) ;
if ( V_86 ) {
V_123 |= F_73 ( V_3 ) ;
V_123 |= F_72 ( V_3 ) ;
}
return V_123 ;
}
static inline bool F_77 ( struct V_2 * V_3 )
{
return F_14 ( V_3 , 0x12 ) & 0x01 ;
}
static int F_78 ( struct V_2 * V_3 , T_3 * V_124 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
* V_124 = 0 ;
* V_124 |= F_71 ( V_3 ) ? V_125 : 0 ;
* V_124 |= F_76 ( V_3 ) ? V_126 : 0 ;
if ( F_77 ( V_3 ) )
* V_124 |= V_86 ? V_127 : V_128 ;
F_40 ( 1 , V_64 , V_3 , L_24 , V_65 , * V_124 ) ;
return 0 ;
}
static void F_79 ( struct V_2 * V_3 ,
struct V_83 * V_84 , const char * V_129 , bool V_130 )
{
struct V_8 * V_85 = & V_84 -> V_85 ;
T_3 V_131 , V_132 ;
if ( V_84 -> type != V_133 )
return;
V_131 = F_5 ( V_85 ) ;
V_132 = F_7 ( V_85 ) ;
F_55 ( V_3 , L_25 ,
V_129 , V_85 -> V_13 , V_85 -> V_17 , V_85 -> V_134 ? L_26 : L_27 ,
( V_131 * V_132 ) > 0 ? ( ( T_3 ) V_85 -> V_102 /
( V_131 * V_132 ) ) : 0 ,
V_131 , V_132 ) ;
if ( V_130 ) {
F_55 ( V_3 , L_28 ,
V_85 -> V_10 ,
( V_85 -> V_135 & V_136 ) ? L_29 : L_30 ,
V_85 -> V_11 , V_85 -> V_12 ) ;
F_55 ( V_3 , L_31 ,
V_85 -> V_14 ,
( V_85 -> V_135 & V_137 ) ? L_29 : L_30 ,
V_85 -> V_15 , V_85 -> V_16 ) ;
F_55 ( V_3 , L_32 ,
V_85 -> V_102 , V_85 -> V_26 , V_85 -> V_107 ) ;
}
}
static int F_80 ( struct V_2 * V_3 ,
struct V_138 * V_139 ,
struct V_83 * V_84 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
T_3 V_140 = ( V_103 * 8 ) / V_139 -> V_141 ;
T_3 V_142 ;
int V_33 ;
for ( V_33 = 0 ; V_143 [ V_33 ] . V_85 . V_17 ; V_33 ++ ) {
if ( F_7 ( & V_143 [ V_33 ] . V_85 ) != V_139 -> V_144 + 1 )
continue;
if ( V_143 [ V_33 ] . V_85 . V_15 != V_139 -> V_145 )
continue;
V_142 = V_140 * F_5 ( & V_143 [ V_33 ] . V_85 ) ;
if ( ( V_142 < V_143 [ V_33 ] . V_85 . V_102 + 1000000 ) &&
( V_142 > V_143 [ V_33 ] . V_85 . V_102 - 1000000 ) ) {
* V_84 = V_143 [ V_33 ] ;
return 0 ;
}
}
if ( F_81 ( V_139 -> V_144 + 1 , V_140 , V_139 -> V_145 ,
( V_139 -> V_146 == '+' ? V_136 : 0 ) |
( V_139 -> V_147 == '+' ? V_137 : 0 ) ,
V_84 ) )
return 0 ;
if ( F_82 ( V_139 -> V_144 + 1 , V_140 , V_139 -> V_145 ,
( V_139 -> V_146 == '+' ? V_136 : 0 ) |
( V_139 -> V_147 == '+' ? V_137 : 0 ) ,
V_43 -> V_148 , V_84 ) )
return 0 ;
F_40 ( 2 , V_64 , V_3 ,
L_33 ,
V_65 , V_139 -> V_145 , V_139 -> V_144 , V_139 -> V_141 ,
V_139 -> V_146 , V_139 -> V_147 ) ;
return - 1 ;
}
static int F_83 ( struct V_2 * V_3 , struct V_138 * V_139 )
{
if ( F_75 ( V_3 ) || F_74 ( V_3 ) ) {
F_40 ( 2 , V_64 , V_3 , L_34 , V_65 ) ;
return - 1 ;
}
V_139 -> V_141 = ( ( F_49 ( V_3 , 0xb1 ) & 0x3f ) << 8 ) | F_49 ( V_3 , 0xb2 ) ;
V_139 -> V_144 = ( ( F_49 ( V_3 , 0xb3 ) & 0x7 ) << 8 ) | F_49 ( V_3 , 0xb4 ) ;
V_139 -> V_145 = F_49 ( V_3 , 0xb3 ) >> 3 ;
V_139 -> V_134 = F_14 ( V_3 , 0x12 ) & 0x10 ;
if ( ( F_49 ( V_3 , 0xb5 ) & 0x03 ) == 0x01 ) {
V_139 -> V_146 = ( ( F_49 ( V_3 , 0xb5 ) & 0x10 ) ?
( ( F_49 ( V_3 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_139 -> V_147 = ( ( F_49 ( V_3 , 0xb5 ) & 0x40 ) ?
( ( F_49 ( V_3 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_139 -> V_146 = 'x' ;
V_139 -> V_147 = 'x' ;
}
if ( F_75 ( V_3 ) || F_74 ( V_3 ) ) {
F_40 ( 2 , V_64 , V_3 ,
L_35 , V_65 ) ;
return - 1 ;
}
if ( V_139 -> V_144 < 239 || V_139 -> V_141 < 8 || V_139 -> V_141 == 0x3fff ) {
F_40 ( 2 , V_64 , V_3 , L_36 , V_65 ) ;
memset ( V_139 , 0 , sizeof( struct V_138 ) ) ;
return - 1 ;
}
F_40 ( 2 , V_64 , V_3 ,
L_37 ,
V_65 , V_139 -> V_144 , V_139 -> V_141 , V_139 -> V_145 ,
V_139 -> V_146 , V_139 -> V_147 ,
V_139 -> V_134 ? L_38 : L_39 ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 ,
struct V_149 * V_84 )
{
if ( V_84 -> V_150 >= F_85 ( V_143 ) - 1 )
return - V_75 ;
memset ( V_84 -> V_151 , 0 , sizeof( V_84 -> V_151 ) ) ;
V_84 -> V_84 = V_143 [ V_84 -> V_150 ] ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_152 * V_153 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
V_153 -> type = V_133 ;
V_153 -> V_85 . V_154 = 1920 ;
V_153 -> V_85 . V_155 = 1200 ;
V_153 -> V_85 . V_156 = 27000000 ;
if ( V_86 )
V_153 -> V_85 . V_157 = 225000000 ;
else
V_153 -> V_85 . V_157 = 170000000 ;
V_153 -> V_85 . V_107 = V_108 | V_158 |
V_159 | V_160 ;
V_153 -> V_85 . V_161 = V_162 |
V_163 | V_164 ;
return 0 ;
}
static void F_87 ( struct V_2 * V_3 ,
struct V_83 * V_84 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
int V_33 ;
for ( V_33 = 0 ; V_143 [ V_33 ] . V_85 . V_13 ; V_33 ++ ) {
if ( F_63 ( V_84 , & V_143 [ V_33 ] ,
V_86 ? 250000 : 1000000 ) ) {
* V_84 = V_143 [ V_33 ] ;
break;
}
}
}
static int F_88 ( struct V_2 * V_3 ,
struct V_83 * V_84 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_8 * V_85 = & V_84 -> V_85 ;
struct V_138 V_139 ;
if ( ! V_84 )
return - V_75 ;
memset ( V_84 , 0 , sizeof( struct V_83 ) ) ;
if ( F_76 ( V_3 ) ) {
F_40 ( 1 , V_64 , V_3 , L_40 , V_65 ) ;
return - V_165 ;
}
if ( F_83 ( V_3 , & V_139 ) ) {
F_40 ( 1 , V_64 , V_3 , L_41 , V_65 ) ;
return - V_165 ;
}
V_85 -> V_134 = V_139 . V_134 ?
V_166 : V_167 ;
if ( V_86 ) {
V_84 -> type = V_133 ;
V_85 -> V_13 = ( F_45 ( V_3 , 0x07 ) & 0x0f ) * 256 + F_45 ( V_3 , 0x08 ) ;
V_85 -> V_17 = ( F_45 ( V_3 , 0x09 ) & 0x0f ) * 256 + F_45 ( V_3 , 0x0a ) ;
V_85 -> V_102 = ( F_45 ( V_3 , 0x06 ) * 1000000 ) +
( ( F_45 ( V_3 , 0x3b ) & 0x30 ) >> 4 ) * 250000 ;
V_85 -> V_10 = ( F_45 ( V_3 , 0x20 ) & 0x03 ) * 256 +
F_45 ( V_3 , 0x21 ) ;
V_85 -> V_11 = ( F_45 ( V_3 , 0x22 ) & 0x03 ) * 256 +
F_45 ( V_3 , 0x23 ) ;
V_85 -> V_12 = ( F_45 ( V_3 , 0x24 ) & 0x03 ) * 256 +
F_45 ( V_3 , 0x25 ) ;
V_85 -> V_14 = ( ( F_45 ( V_3 , 0x2a ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x2b ) ) / 2 ;
V_85 -> V_15 = ( ( F_45 ( V_3 , 0x2e ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x2f ) ) / 2 ;
V_85 -> V_16 = ( ( F_45 ( V_3 , 0x32 ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x33 ) ) / 2 ;
V_85 -> V_135 = ( ( F_45 ( V_3 , 0x05 ) & 0x10 ) ? V_137 : 0 ) |
( ( F_45 ( V_3 , 0x05 ) & 0x20 ) ? V_136 : 0 ) ;
if ( V_85 -> V_134 == V_166 ) {
V_85 -> V_17 += ( F_45 ( V_3 , 0x0b ) & 0x0f ) * 256 +
F_45 ( V_3 , 0x0c ) ;
V_85 -> V_168 = ( ( F_45 ( V_3 , 0x2c ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x2d ) ) / 2 ;
V_85 -> V_169 = ( ( F_45 ( V_3 , 0x30 ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x31 ) ) / 2 ;
V_85 -> V_16 = ( ( F_45 ( V_3 , 0x34 ) & 0x1f ) * 256 +
F_45 ( V_3 , 0x35 ) ) / 2 ;
}
F_87 ( V_3 , V_84 ) ;
} else {
if ( ! F_80 ( V_3 , & V_139 , V_84 ) )
goto V_170;
V_139 . V_145 += 1 ;
F_40 ( 1 , V_64 , V_3 , L_42 , V_65 , V_139 . V_145 ) ;
if ( ! F_80 ( V_3 , & V_139 , V_84 ) )
goto V_170;
V_139 . V_145 -= 2 ;
F_40 ( 1 , V_64 , V_3 , L_43 , V_65 , V_139 . V_145 ) ;
if ( F_80 ( V_3 , & V_139 , V_84 ) ) {
if ( V_43 -> V_171 ) {
F_40 ( 1 , V_64 , V_3 , L_44 , V_65 ) ;
F_51 ( V_3 , 0x86 , 0xf9 , 0x00 ) ;
F_51 ( V_3 , 0x86 , 0xf9 , 0x04 ) ;
F_51 ( V_3 , 0x86 , 0xf9 , 0x02 ) ;
V_43 -> V_171 = false ;
return - V_165 ;
}
F_40 ( 1 , V_64 , V_3 , L_45 , V_65 ) ;
return - V_172 ;
}
V_43 -> V_171 = true ;
}
V_170:
if ( F_76 ( V_3 ) ) {
F_40 ( 1 , V_64 , V_3 , L_46 , V_65 ) ;
memset ( V_84 , 0 , sizeof( struct V_83 ) ) ;
return - V_165 ;
}
if ( ( ! V_86 && V_85 -> V_102 > 170000000 ) ||
( V_86 && V_85 -> V_102 > 225000000 ) ) {
F_40 ( 1 , V_64 , V_3 , L_47 ,
V_65 , ( T_3 ) V_85 -> V_102 ) ;
return - V_172 ;
}
if ( V_64 > 1 )
F_79 ( V_3 , V_84 ,
L_48 , true ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 ,
struct V_83 * V_84 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_8 * V_85 ;
int V_32 ;
if ( ! V_84 )
return - V_75 ;
V_85 = & V_84 -> V_85 ;
if ( ( ! V_86 && V_85 -> V_102 > 170000000 ) ||
( V_86 && V_85 -> V_102 > 225000000 ) ) {
F_40 ( 1 , V_64 , V_3 , L_47 ,
V_65 , ( T_3 ) V_85 -> V_102 ) ;
return - V_172 ;
}
F_87 ( V_3 , V_84 ) ;
V_43 -> V_84 = * V_84 ;
F_50 ( V_3 , 0x91 , V_85 -> V_134 ? 0x50 : 0x10 ) ;
V_32 = F_64 ( V_3 , V_84 ) ;
if ( V_32 ) {
F_65 ( V_3 , V_85 ) ;
}
F_67 ( V_3 ) ;
if ( V_64 > 1 )
F_79 ( V_3 , V_84 ,
L_49 , true ) ;
return 0 ;
}
static int F_90 ( struct V_2 * V_3 ,
struct V_83 * V_84 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
* V_84 = V_43 -> V_84 ;
return 0 ;
}
static void F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
switch ( V_43 -> V_89 ) {
case V_90 :
case V_91 :
F_16 ( V_3 , 0x15 , 0xb0 ) ;
break;
case V_94 :
F_46 ( V_3 , 0x1a , 0x0a ) ;
F_46 ( V_3 , 0x01 , 0x00 ) ;
F_16 ( V_3 , 0x15 , 0xa0 ) ;
break;
default:
F_40 ( 2 , V_64 , V_3 , L_21 ,
V_65 , V_43 -> V_89 ) ;
break;
}
}
static void F_92 ( struct V_2 * V_3 )
{
F_16 ( V_3 , 0x15 , 0xbe ) ;
F_46 ( V_3 , 0x1a , 0x1a ) ;
F_46 ( V_3 , 0x01 , 0x78 ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
switch ( V_43 -> V_89 ) {
case V_90 :
case V_91 :
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
case V_94 :
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
V_65 , V_43 -> V_89 ) ;
break;
}
}
static int F_94 ( struct V_2 * V_3 ,
T_3 V_173 , T_3 V_174 , T_3 V_175 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
F_40 ( 2 , V_64 , V_3 , L_50 , V_65 , V_173 ) ;
V_43 -> V_89 = V_173 ;
F_92 ( V_3 ) ;
F_93 ( V_3 ) ;
F_91 ( V_3 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , unsigned int V_150 ,
enum V_176 * V_177 )
{
if ( V_150 )
return - V_75 ;
* V_177 = V_178 ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 ,
struct V_179 * V_180 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
V_180 -> V_13 = V_43 -> V_84 . V_85 . V_13 ;
V_180 -> V_17 = V_43 -> V_84 . V_85 . V_17 ;
V_180 -> V_177 = V_178 ;
V_180 -> V_181 = V_182 ;
if ( V_43 -> V_84 . V_85 . V_107 & V_108 ) {
V_180 -> V_183 = ( V_43 -> V_84 . V_85 . V_17 <= 576 ) ?
V_184 : V_185 ;
}
return 0 ;
}
static int F_97 ( struct V_2 * V_3 , T_3 V_124 , bool * V_186 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
T_2 V_187 , V_188 , V_189 ;
V_187 = F_14 ( V_3 , 0x43 ) & 0x98 ;
if ( V_187 )
F_16 ( V_3 , 0x44 , V_187 ) ;
V_188 = V_86 ? ( F_14 ( V_3 , 0x6b ) & 0xc0 ) : 0 ;
if ( V_188 )
F_16 ( V_3 , 0x6c , V_188 ) ;
if ( V_187 || V_188 ) {
F_40 ( 1 , V_64 , V_3 ,
L_51 ,
V_65 , V_187 , V_188 ) ;
F_41 ( V_3 , V_190 , NULL ) ;
if ( V_186 )
* V_186 = true ;
}
V_189 = F_14 ( V_3 , 0x70 ) & 0x10 ;
if ( V_189 ) {
F_40 ( 1 , V_64 , V_3 , L_52 , V_65 , V_189 ) ;
F_16 ( V_3 , 0x71 , V_189 ) ;
F_60 ( V_3 ) ;
if ( V_186 )
* V_186 = true ;
}
return 0 ;
}
static int F_98 ( struct V_2 * V_3 , struct V_191 * V_192 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
if ( V_192 -> V_193 != 0 )
return - V_75 ;
if ( V_192 -> V_194 == 0 )
return - V_75 ;
if ( V_192 -> V_195 >= V_43 -> V_196 )
return - V_75 ;
if ( V_192 -> V_195 + V_192 -> V_194 > V_43 -> V_196 )
V_192 -> V_194 = V_43 -> V_196 - V_192 -> V_195 ;
if ( ! V_192 -> V_192 )
return - V_75 ;
memcpy ( V_192 -> V_192 + V_192 -> V_195 * 128 ,
V_43 -> V_192 + V_192 -> V_195 * 128 ,
V_192 -> V_194 * 128 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 , struct V_191 * V_192 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
int V_32 ;
if ( V_192 -> V_193 != 0 )
return - V_75 ;
if ( V_192 -> V_195 != 0 )
return - V_75 ;
if ( V_192 -> V_194 == 0 ) {
F_41 ( V_3 , V_66 , ( void * ) 0 ) ;
F_33 ( V_3 , 0x77 , 0xf0 , 0x0 ) ;
V_43 -> V_196 = 0 ;
V_43 -> V_148 . V_197 = 16 ;
V_43 -> V_148 . V_198 = 9 ;
return 0 ;
}
if ( V_192 -> V_194 > 2 )
return - V_199 ;
if ( ! V_192 -> V_192 )
return - V_75 ;
memcpy ( V_43 -> V_192 , V_192 -> V_192 , 128 * V_192 -> V_194 ) ;
V_43 -> V_196 = V_192 -> V_194 ;
V_43 -> V_148 = F_100 ( V_192 -> V_192 [ 0x15 ] ,
V_192 -> V_192 [ 0x16 ] ) ;
V_32 = F_42 ( V_3 , 128 * V_192 -> V_194 , V_43 -> V_192 ) ;
if ( V_32 < 0 )
F_66 ( V_3 , L_53 , V_32 ) ;
return V_32 ;
}
static void F_101 ( struct V_2 * V_3 )
{
int V_33 ;
T_2 V_57 [ 14 ] ;
T_2 V_200 ;
T_2 V_201 ;
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
V_200 = F_23 ( V_3 , 0xe2 ) ;
V_201 = F_23 ( V_3 , 0xe1 ) ;
F_55 ( V_3 , L_58 ,
V_201 , V_200 ) ;
if ( V_201 != 0x02 )
return;
for ( V_33 = 0 ; V_33 < 14 ; V_33 ++ )
V_57 [ V_33 ] = F_23 ( V_3 , V_33 ) ;
F_55 ( V_3 ,
L_59 ,
V_57 [ 0 ] , V_57 [ 1 ] , V_57 [ 2 ] , V_57 [ 3 ] , V_57 [ 4 ] , V_57 [ 5 ] , V_57 [ 6 ] , V_57 [ 7 ] ,
V_57 [ 8 ] , V_57 [ 9 ] , V_57 [ 10 ] , V_57 [ 11 ] , V_57 [ 12 ] , V_57 [ 13 ] ) ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_83 V_84 ;
struct V_138 V_139 ;
T_2 V_202 = F_14 ( V_3 , 0x02 ) ;
char * V_203 [ 16 ] = {
L_60 , L_61 , L_62 , L_63 ,
L_62 , L_64 , L_62 , L_65 ,
L_62 , L_66 , L_67 ,
L_62 , L_62 , L_62 , L_62 , L_68
} ;
char * V_204 [ 16 ] = {
L_69 , L_70 ,
L_71 , L_72 ,
L_73 , L_74 ,
L_75 , L_76 ,
L_77 , L_77 , L_77 , L_77 , L_77 ,
L_77 , L_77 , L_78
} ;
char * V_205 [] = {
L_79 ,
L_69 ,
L_70 ,
} ;
F_55 ( V_3 , L_80 ) ;
F_55 ( V_3 , L_81 , F_71 ( V_3 ) ? L_82 : L_83 ) ;
F_55 ( V_3 , L_84 , V_43 -> V_206 ?
L_85 : ( V_86 ? L_86 : L_87 ) ) ;
F_55 ( V_3 , L_88 , ( ( F_31 ( V_3 , 0x7d ) & 0x01 ) &&
( F_31 ( V_3 , 0x77 ) & 0x01 ) ) ? L_89 : L_90 ) ;
F_55 ( V_3 , L_91 , ! ! ( F_20 ( V_3 , 0x2a ) & 0x01 ) ?
L_89 : L_92 ) ;
F_55 ( V_3 , L_93 ) ;
F_55 ( V_3 , L_94 ,
( F_14 ( V_3 , 0x6f ) & 0x10 ) ? L_95 : L_96 ) ;
F_55 ( V_3 , L_97 ,
F_72 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_98 ,
F_73 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_99 , F_74 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_100 , F_75 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_101 , F_77 ( V_3 ) ? L_96 : L_95 ) ;
F_55 ( V_3 , L_102 ,
( ! ! ( F_49 ( V_3 , 0xff ) & 0x10 ) ? L_83 : L_82 ) ) ;
F_55 ( V_3 , L_103 ,
F_14 ( V_3 , 0x01 ) & 0x0f , F_14 ( V_3 , 0x00 ) & 0x3f ,
( F_14 ( V_3 , 0x01 ) & 0x70 ) >> 4 ) ;
F_55 ( V_3 , L_104 ) ;
if ( F_83 ( V_3 , & V_139 ) )
F_55 ( V_3 , L_105 ) ;
else
F_55 ( V_3 , L_106 ,
V_139 . V_144 , V_139 . V_141 , V_139 . V_145 ,
V_139 . V_134 ? L_38 : L_39 ,
V_139 . V_146 , V_139 . V_147 ) ;
if ( F_88 ( V_3 , & V_84 ) )
F_55 ( V_3 , L_107 ) ;
else
F_79 ( V_3 , & V_84 , L_108 , true ) ;
F_79 ( V_3 , & V_43 -> V_84 , L_109 , true ) ;
F_55 ( V_3 , L_110 ) ;
F_55 ( V_3 , L_111 ,
V_205 [ V_43 -> V_105 ] ) ;
F_55 ( V_3 , L_112 ,
V_204 [ V_202 >> 4 ] ) ;
F_55 ( V_3 , L_113 ,
( V_202 & 0x02 ) ? L_114 : L_115 ,
( V_202 & 0x04 ) ? L_116 : L_117 ,
( ( V_202 & 0x04 ) ^ ( V_202 & 0x01 ) ) ?
L_89 : L_92 ) ;
F_55 ( V_3 , L_118 ,
V_203 [ F_49 ( V_3 , 0xfc ) >> 4 ] ) ;
if ( V_86 ) {
F_55 ( V_3 , L_119 ) ;
F_55 ( V_3 , L_120 ,
F_45 ( V_3 , 0x05 ) & 0x40 ? L_95 : L_96 ) ;
F_101 ( V_3 ) ;
}
return 0 ;
}
static int F_103 ( struct V_2 * V_3 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_207 * V_208 = & V_43 -> V_208 ;
F_46 ( V_3 , 0x48 ,
( V_208 -> V_209 ? 0x80 : 0 ) |
( V_208 -> V_210 ? 0x40 : 0 ) ) ;
F_92 ( V_3 ) ;
F_16 ( V_3 , 0x0c , 0x42 ) ;
F_16 ( V_3 , 0x0b , 0x44 ) ;
F_50 ( V_3 , 0xcf , 0x01 ) ;
F_17 ( V_3 , 0x02 , 0xf0 ,
V_208 -> V_211 << 3 |
V_208 -> V_212 << 2 |
V_208 -> V_213 << 1 |
V_208 -> V_214 << 0 ) ;
F_16 ( V_3 , 0x03 , V_208 -> V_215 ) ;
F_17 ( V_3 , 0x04 , 0x1f , V_208 -> V_216 << 5 ) ;
F_17 ( V_3 , 0x05 , 0xf0 , V_208 -> V_217 << 3 |
V_208 -> V_218 << 2 |
V_208 -> V_219 << 1 |
V_208 -> V_220 << 0 ) ;
F_50 ( V_3 , 0x69 , 0x30 ) ;
F_16 ( V_3 , 0x06 , 0xa6 ) ;
F_16 ( V_3 , 0x14 , 0x7f ) ;
F_50 ( V_3 , 0xba , ( V_208 -> V_221 << 1 ) | 0x01 ) ;
F_50 ( V_3 , 0xf3 , 0xdc ) ;
F_50 ( V_3 , 0xf9 , 0x23 ) ;
F_50 ( V_3 , 0x45 , 0x23 ) ;
F_50 ( V_3 , 0xc9 , 0x2d ) ;
F_30 ( V_3 , 0xb5 , 0x01 ) ;
F_30 ( V_3 , 0x02 , V_208 -> V_222 ) ;
F_17 ( V_3 , 0x30 , ~ ( 1 << 4 ) , V_208 -> V_223 << 4 ) ;
F_16 ( V_3 , 0x40 , 0xc2 ) ;
F_16 ( V_3 , 0x41 , 0xd7 ) ;
F_16 ( V_3 , 0x46 , 0x98 ) ;
F_16 ( V_3 , 0x6e , 0xc0 ) ;
F_16 ( V_3 , 0x73 , 0x10 ) ;
return F_104 ( V_3 -> V_224 ) ;
}
static void F_105 ( struct V_1 * V_43 )
{
if ( V_43 -> V_44 )
F_106 ( V_43 -> V_44 ) ;
if ( V_43 -> V_45 )
F_106 ( V_43 -> V_45 ) ;
if ( V_43 -> V_46 )
F_106 ( V_43 -> V_46 ) ;
if ( V_43 -> V_47 )
F_106 ( V_43 -> V_47 ) ;
if ( V_43 -> V_48 )
F_106 ( V_43 -> V_48 ) ;
if ( V_43 -> V_49 )
F_106 ( V_43 -> V_49 ) ;
if ( V_43 -> V_50 )
F_106 ( V_43 -> V_50 ) ;
if ( V_43 -> V_51 )
F_106 ( V_43 -> V_51 ) ;
if ( V_43 -> V_69 )
F_106 ( V_43 -> V_69 ) ;
if ( V_43 -> V_70 )
F_106 ( V_43 -> V_70 ) ;
if ( V_43 -> V_71 )
F_106 ( V_43 -> V_71 ) ;
if ( V_43 -> V_72 )
F_106 ( V_43 -> V_72 ) ;
}
static struct V_18 * F_107 ( struct V_2 * V_3 ,
T_2 V_25 , T_2 V_225 )
{
struct V_18 * V_19 = F_15 ( V_3 ) ;
if ( V_25 )
F_16 ( V_3 , V_225 , V_25 << 1 ) ;
return F_108 ( V_19 -> V_24 , F_14 ( V_3 , V_225 ) >> 1 ) ;
}
static int F_109 ( struct V_18 * V_19 ,
const struct V_226 * V_111 )
{
struct V_1 * V_43 ;
struct V_207 * V_208 = V_19 -> V_227 . V_228 ;
struct V_229 * V_7 ;
struct V_2 * V_3 ;
int V_32 ;
if ( ! F_110 ( V_19 -> V_24 , V_230 ) )
return - V_30 ;
F_111 ( 1 , V_64 , V_19 , L_121 ,
V_19 -> V_25 << 1 ) ;
V_43 = F_112 ( sizeof( struct V_1 ) , V_231 ) ;
if ( ! V_43 ) {
F_10 ( V_19 , L_122 ) ;
return - V_232 ;
}
if ( ! V_208 ) {
F_10 ( V_19 , L_123 ) ;
V_32 = - V_233 ;
goto V_234;
}
memcpy ( & V_43 -> V_208 , V_208 , sizeof( V_43 -> V_208 ) ) ;
V_3 = & V_43 -> V_3 ;
F_113 ( V_3 , V_19 , & V_235 ) ;
V_3 -> V_26 |= V_236 ;
V_43 -> V_206 = V_208 -> V_206 ;
if ( F_8 ( V_19 , 0xfb , false ) != 0x68 ) {
F_55 ( V_3 , L_124 ,
V_19 -> V_25 << 1 ) ;
V_32 = - V_233 ;
goto V_234;
}
V_7 = & V_43 -> V_7 ;
F_114 ( V_7 , 9 ) ;
F_115 ( V_7 , & V_237 ,
V_112 , - 128 , 127 , 1 , 0 ) ;
F_115 ( V_7 , & V_237 ,
V_113 , 0 , 255 , 1 , 128 ) ;
F_115 ( V_7 , & V_237 ,
V_114 , 0 , 255 , 1 , 128 ) ;
F_115 ( V_7 , & V_237 ,
V_115 , 0 , 128 , 1 , 0 ) ;
V_43 -> V_79 = F_115 ( V_7 , NULL ,
V_238 , 0 , 1 , 0 , 0 ) ;
V_43 -> V_79 -> V_239 = true ;
V_43 -> V_240 =
F_116 ( V_7 , & V_237 ,
V_116 , V_110 ,
0 , V_106 ) ;
V_43 -> V_240 -> V_239 = true ;
V_43 -> V_241 =
F_117 ( V_7 , & V_242 , NULL ) ;
V_43 -> V_241 -> V_239 = true ;
V_43 -> V_243 =
F_117 ( V_7 , & V_244 , NULL ) ;
V_43 -> V_243 -> V_239 = true ;
V_43 -> V_245 =
F_117 ( V_7 , & V_246 , NULL ) ;
V_43 -> V_245 -> V_239 = true ;
V_3 -> V_224 = V_7 ;
if ( V_7 -> error ) {
V_32 = V_7 -> error ;
goto V_247;
}
if ( F_60 ( V_3 ) ) {
V_32 = - V_233 ;
goto V_247;
}
V_43 -> V_44 = F_107 ( V_3 , V_208 -> V_44 , 0xf3 ) ;
V_43 -> V_45 = F_107 ( V_3 , V_208 -> V_45 , 0xf4 ) ;
V_43 -> V_46 = F_107 ( V_3 , V_208 -> V_46 , 0xf5 ) ;
V_43 -> V_47 = F_107 ( V_3 , V_208 -> V_47 , 0xf6 ) ;
V_43 -> V_48 = F_107 ( V_3 , V_208 -> V_48 , 0xf7 ) ;
V_43 -> V_49 = F_107 ( V_3 , V_208 -> V_49 , 0xf8 ) ;
V_43 -> V_50 = F_107 ( V_3 , V_208 -> V_50 , 0xf9 ) ;
V_43 -> V_51 = F_107 ( V_3 , V_208 -> V_51 , 0xfa ) ;
V_43 -> V_69 = F_107 ( V_3 , V_208 -> V_69 , 0xfb ) ;
V_43 -> V_70 = F_107 ( V_3 , V_208 -> V_70 , 0xfc ) ;
V_43 -> V_71 = F_107 ( V_3 , V_208 -> V_71 , 0xfd ) ;
V_43 -> V_72 = F_107 ( V_3 , V_208 -> V_72 , 0xfe ) ;
if ( ! V_43 -> V_44 || ! V_43 -> V_45 || ! V_43 -> V_46 ||
! V_43 -> V_47 || ! V_43 -> V_48 || ! V_43 -> V_49 ||
! V_43 -> V_50 || ! V_43 -> V_51 || ! V_43 -> V_69 ||
! V_43 -> V_70 || ! V_43 -> V_71 || ! V_43 -> V_72 ) {
V_32 = - V_232 ;
F_66 ( V_3 , L_125 ) ;
goto V_248;
}
V_43 -> V_171 = true ;
V_43 -> V_67 = F_118 ( V_19 -> V_249 ) ;
if ( ! V_43 -> V_67 ) {
F_66 ( V_3 , L_126 ) ;
V_32 = - V_232 ;
goto V_248;
}
F_119 ( & V_43 -> V_63 ,
F_38 ) ;
V_43 -> V_193 . V_26 = V_250 ;
V_32 = F_120 ( & V_3 -> V_251 , 1 , & V_43 -> V_193 , 0 ) ;
if ( V_32 )
goto V_252;
V_32 = F_103 ( V_3 ) ;
if ( V_32 )
goto V_253;
F_55 ( V_3 , L_127 , V_19 -> V_249 ,
V_19 -> V_25 << 1 , V_19 -> V_24 -> V_249 ) ;
return 0 ;
V_253:
F_121 ( & V_3 -> V_251 ) ;
V_252:
F_122 ( & V_43 -> V_63 ) ;
F_123 ( V_43 -> V_67 ) ;
V_248:
F_105 ( V_43 ) ;
V_247:
F_124 ( V_7 ) ;
V_234:
F_125 ( V_43 ) ;
return V_32 ;
}
static int F_126 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_127 ( V_19 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
F_122 ( & V_43 -> V_63 ) ;
F_123 ( V_43 -> V_67 ) ;
F_128 ( V_3 ) ;
F_121 ( & V_3 -> V_251 ) ;
F_105 ( F_1 ( V_3 ) ) ;
F_124 ( V_3 -> V_224 ) ;
F_125 ( F_1 ( V_3 ) ) ;
return 0 ;
}
