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
static void F_42 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_43 ( V_52 ) ;
struct V_1 * V_35 = F_2 ( V_54 , struct V_1 ,
V_55 ) ;
struct V_2 * V_3 = & V_35 -> V_3 ;
F_44 ( 2 , V_56 , V_3 , L_3 , V_57 ) ;
F_45 ( V_3 , V_58 , ( void * ) 1 ) ;
}
static inline int F_46 ( struct V_2 * V_3 ,
unsigned V_44 , const T_2 * V_33 )
{
struct V_10 * V_11 = F_19 ( V_3 ) ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_24 = 0 ;
int V_25 ;
F_44 ( 2 , V_56 , V_3 , L_4 , V_57 , V_44 ) ;
F_45 ( V_3 , V_58 , ( void * ) 0 ) ;
F_37 ( V_3 , 0x77 , 0xf0 , 0x0 ) ;
for ( V_25 = 0 ; ! V_24 && V_25 < V_44 ; V_25 += V_29 )
V_24 = F_17 ( V_35 -> V_43 , V_25 ,
V_29 , V_33 + V_25 ) ;
if ( V_24 )
return V_24 ;
F_37 ( V_3 , 0x77 , 0xf0 , 0x1 ) ;
for ( V_25 = 0 ; V_25 < 1000 ; V_25 ++ ) {
if ( F_35 ( V_3 , 0x7d ) & 1 )
break;
F_47 ( 1 ) ;
}
if ( V_25 == 1000 ) {
F_14 ( V_11 , L_5 ) ;
return - V_22 ;
}
F_48 ( V_35 -> V_59 ,
& V_35 -> V_55 , V_60 / 10 ) ;
return 0 ;
}
static inline int F_49 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_61 , V_32 ) ;
}
static inline int F_50 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_61 , V_32 , V_33 ) ;
}
static inline int F_51 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_62 , V_32 ) ;
}
static inline int F_52 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_62 , V_32 , V_33 ) ;
}
static inline int F_53 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_63 , V_32 ) ;
}
static inline int F_54 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_63 , V_32 , V_33 ) ;
}
static inline int F_55 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_34 , T_2 V_33 )
{
return F_54 ( V_3 , V_32 , ( F_53 ( V_3 , V_32 ) & V_34 ) | V_33 ) ;
}
static inline int F_56 ( struct V_2 * V_3 , T_2 V_32 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_15 ( V_35 -> V_64 , V_32 ) ;
}
static inline int F_57 ( struct V_2 * V_3 , T_2 V_32 , T_2 V_33 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_16 ( V_35 -> V_64 , V_32 , V_33 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_59 ( V_3 , L_6 ) ;
F_59 ( V_3 , L_7 ) ;
F_59 ( V_3 , L_8 ) ;
F_59 ( V_3 , L_9 ) ;
F_59 ( V_3 , L_10 ) ;
F_59 ( V_3 , L_11 ) ;
F_59 ( V_3 , L_12 ) ;
F_59 ( V_3 , L_13 ) ;
F_59 ( V_3 , L_14 ) ;
F_59 ( V_3 , L_15 ) ;
F_59 ( V_3 , L_16 ) ;
F_59 ( V_3 , L_17 ) ;
F_59 ( V_3 , L_18 ) ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_65 * V_32 )
{
V_32 -> V_66 = 1 ;
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
V_32 -> V_33 = F_49 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 0xa :
V_32 -> V_33 = F_51 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 0xb :
V_32 -> V_33 = F_53 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
case 0xc :
V_32 -> V_33 = F_56 ( V_3 , V_32 -> V_32 & 0xff ) ;
break;
default:
F_59 ( V_3 , L_19 , V_32 -> V_32 ) ;
F_58 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 ,
const struct V_65 * V_32 )
{
switch ( V_32 -> V_32 >> 8 ) {
case 0 :
F_20 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 1 :
F_23 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 2 :
F_25 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 3 :
F_28 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 4 :
F_30 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 5 :
F_32 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 6 :
F_34 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 7 :
F_36 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 8 :
F_39 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 9 :
F_50 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 0xa :
F_52 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 0xb :
F_54 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
case 0xc :
F_57 ( V_3 , V_32 -> V_32 & 0xff , V_32 -> V_33 & 0xff ) ;
break;
default:
F_59 ( V_3 , L_19 , V_32 -> V_32 ) ;
F_58 ( V_3 ) ;
break;
}
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
return F_63 ( V_35 -> V_67 ,
( ( F_18 ( V_3 , 0x6f ) & 0x10 ) >> 4 ) ) ;
}
static int F_64 ( struct V_2 * V_3 ,
T_2 V_68 ,
const struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_25 ;
for ( V_25 = 0 ; V_70 [ V_25 ] . V_72 . V_73 . V_74 ; V_25 ++ ) {
if ( ! F_65 ( V_72 , & V_70 [ V_25 ] . V_72 ,
V_75 ? 250000 : 1000000 ) )
continue;
F_20 ( V_3 , 0x00 , V_70 [ V_25 ] . V_76 ) ;
F_20 ( V_3 , 0x01 , ( V_70 [ V_25 ] . V_77 << 4 ) +
V_68 ) ;
return 0 ;
}
return - 1 ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_24 ;
F_44 ( 1 , V_56 , V_3 , L_20 , V_57 ) ;
F_20 ( V_3 , 0x16 , 0x43 ) ;
F_20 ( V_3 , 0x17 , 0x5a ) ;
F_55 ( V_3 , 0x81 , 0xef , 0x00 ) ;
F_54 ( V_3 , 0x8f , 0x00 ) ;
F_54 ( V_3 , 0x90 , 0x00 ) ;
F_54 ( V_3 , 0xa2 , 0x00 ) ;
F_54 ( V_3 , 0xa3 , 0x00 ) ;
F_54 ( V_3 , 0xa4 , 0x00 ) ;
F_54 ( V_3 , 0xa5 , 0x00 ) ;
F_54 ( V_3 , 0xa6 , 0x00 ) ;
F_54 ( V_3 , 0xa7 , 0x00 ) ;
F_54 ( V_3 , 0xab , 0x00 ) ;
F_54 ( V_3 , 0xac , 0x00 ) ;
switch ( V_35 -> V_78 ) {
case V_79 :
case V_80 :
V_24 = F_64 ( V_3 ,
0x01 , V_81 , V_72 ) ;
if ( V_24 )
V_24 = F_64 ( V_3 ,
0x02 , V_82 , V_72 ) ;
break;
case V_83 :
V_24 = F_64 ( V_3 ,
0x05 , V_84 , V_72 ) ;
if ( V_24 )
V_24 = F_64 ( V_3 ,
0x06 , V_85 , V_72 ) ;
break;
default:
F_44 ( 2 , V_56 , V_3 , L_21 ,
V_57 , V_35 -> V_78 ) ;
V_24 = - 1 ;
break;
}
return V_24 ;
}
static void F_67 ( struct V_2 * V_3 ,
const struct V_8 * V_73 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_19 ( V_3 ) ;
T_3 V_74 = F_6 ( V_73 ) ;
T_3 V_86 = F_10 ( V_73 ) ;
T_4 V_87 = V_73 -> V_88 + V_73 -> V_89 - 4 ;
T_4 V_90 = V_74 - V_73 -> V_91 ;
T_4 V_92 = V_86 - V_73 -> V_93 ;
T_4 V_94 = V_73 -> V_95 + V_73 -> V_96 ;
T_4 V_97 = ( ( ( T_3 ) V_73 -> V_98 / 100 ) > 0 ) ?
( ( V_74 * ( V_99 / 100 ) ) / ( ( T_3 ) V_73 -> V_98 / 100 ) ) : 0 ;
const T_2 V_100 [ 2 ] = {
0xc0 | ( ( V_74 >> 8 ) & 0x1f ) ,
V_74 & 0xff
} ;
F_44 ( 2 , V_56 , V_3 , L_22 , V_57 ) ;
switch ( V_35 -> V_78 ) {
case V_79 :
case V_80 :
F_20 ( V_3 , 0x00 , 0x07 ) ;
F_20 ( V_3 , 0x01 , 0x02 ) ;
F_55 ( V_3 , 0x81 , 0xef , 0x10 ) ;
if ( F_17 ( V_11 , 0x16 , 2 , V_100 ) ) {
F_68 ( V_3 , L_23 ) ;
break;
}
F_54 ( V_3 , 0xa2 , ( V_87 >> 4 ) & 0xff ) ;
F_54 ( V_3 , 0xa3 , ( ( V_87 & 0x0f ) << 4 ) |
( ( V_90 >> 8 ) & 0x0f ) ) ;
F_54 ( V_3 , 0xa4 , V_90 & 0xff ) ;
F_54 ( V_3 , 0xa5 , ( V_92 >> 4 ) & 0xff ) ;
F_54 ( V_3 , 0xa6 , ( ( V_92 & 0xf ) << 4 ) |
( ( V_94 >> 8 ) & 0xf ) ) ;
F_54 ( V_3 , 0xa7 , V_94 & 0xff ) ;
break;
case V_83 :
F_20 ( V_3 , 0x00 , 0x02 ) ;
F_20 ( V_3 , 0x01 , 0x06 ) ;
break;
default:
F_44 ( 2 , V_56 , V_3 , L_21 ,
V_57 , V_35 -> V_78 ) ;
break;
}
F_54 ( V_3 , 0x8f , ( V_97 >> 8 ) & 0x7 ) ;
F_54 ( V_3 , 0x90 , V_97 & 0xff ) ;
F_54 ( V_3 , 0xab , ( V_86 >> 4 ) & 0xff ) ;
F_54 ( V_3 , 0xac , ( V_86 & 0x0f ) << 4 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
switch ( V_35 -> V_101 ) {
case V_102 :
if ( V_75 && ! ( F_49 ( V_3 , 0x05 ) & 0x80 ) ) {
if ( V_35 -> V_72 . V_73 . V_103 & V_104 ) {
F_21 ( V_3 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_21 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
}
} else {
F_21 ( V_3 , 0x02 , 0x0f , 0xf0 ) ;
}
break;
case V_105 :
F_21 ( V_3 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_106 :
F_21 ( V_3 , 0x02 , 0x0f , 0x10 ) ;
break;
}
}
static int F_70 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
switch ( V_5 -> V_107 ) {
case V_108 :
F_54 ( V_3 , 0x3c , V_5 -> V_33 ) ;
return 0 ;
case V_109 :
F_54 ( V_3 , 0x3a , V_5 -> V_33 ) ;
return 0 ;
case V_110 :
F_54 ( V_3 , 0x3b , V_5 -> V_33 ) ;
return 0 ;
case V_111 :
F_54 ( V_3 , 0x3d , V_5 -> V_33 ) ;
return 0 ;
case V_112 :
V_35 -> V_101 = V_5 -> V_33 ;
F_69 ( V_3 ) ;
return 0 ;
case V_113 :
F_34 ( V_3 , 0xc8 , V_5 -> V_33 ) ;
return 0 ;
case V_114 :
F_55 ( V_3 , 0xbf , ~ 0x04 , ( V_5 -> V_33 << 2 ) ) ;
return 0 ;
case V_115 :
F_54 ( V_3 , 0xc0 , ( V_5 -> V_33 & 0xff0000 ) >> 16 ) ;
F_54 ( V_3 , 0xc1 , ( V_5 -> V_33 & 0x00ff00 ) >> 8 ) ;
F_54 ( V_3 , 0xc2 , ( T_2 ) ( V_5 -> V_33 & 0x0000ff ) ) ;
return 0 ;
}
return - V_116 ;
}
static inline bool F_71 ( struct V_2 * V_3 )
{
return F_18 ( V_3 , 0x0c ) & 0x24 ;
}
static inline bool F_72 ( struct V_2 * V_3 )
{
return ! ( F_18 ( V_3 , 0x6a ) & 0x10 ) ;
}
static inline bool F_73 ( struct V_2 * V_3 )
{
return ( F_18 ( V_3 , 0x6a ) & 0xe0 ) != 0xe0 ;
}
static inline bool F_74 ( struct V_2 * V_3 )
{
return F_49 ( V_3 , 0x05 ) & 0x80 ;
}
static inline bool F_75 ( struct V_2 * V_3 )
{
return ( ( F_53 ( V_3 , 0xb5 ) & 0xd0 ) != 0xd0 ) ;
}
static inline bool F_76 ( struct V_2 * V_3 )
{
return ! ( F_53 ( V_3 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_77 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
bool V_117 ;
V_117 = F_71 ( V_3 ) ;
V_117 |= F_76 ( V_3 ) ;
V_117 |= F_75 ( V_3 ) ;
if ( V_75 ) {
V_117 |= F_73 ( V_3 ) ;
V_117 |= F_72 ( V_3 ) ;
}
return V_117 ;
}
static inline bool F_78 ( struct V_2 * V_3 )
{
return F_18 ( V_3 , 0x12 ) & 0x01 ;
}
static int F_79 ( struct V_2 * V_3 , T_3 * V_118 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
* V_118 = 0 ;
* V_118 |= F_71 ( V_3 ) ? V_119 : 0 ;
* V_118 |= F_77 ( V_3 ) ? V_120 : 0 ;
if ( F_78 ( V_3 ) )
* V_118 |= V_75 ? V_121 : V_122 ;
F_44 ( 1 , V_56 , V_3 , L_24 , V_57 , * V_118 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_71 * V_72 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_3 V_125 = ( V_99 * 8 ) / V_124 -> V_126 ;
T_3 V_127 ;
int V_25 ;
for ( V_25 = 0 ; V_128 [ V_25 ] . V_73 . V_86 ; V_25 ++ ) {
if ( F_10 ( & V_128 [ V_25 ] . V_73 ) != V_124 -> V_129 + 1 )
continue;
if ( V_128 [ V_25 ] . V_73 . V_95 != V_124 -> V_130 )
continue;
V_127 = V_125 * F_6 ( & V_128 [ V_25 ] . V_73 ) ;
if ( ( V_127 < V_128 [ V_25 ] . V_73 . V_98 + 1000000 ) &&
( V_127 > V_128 [ V_25 ] . V_73 . V_98 - 1000000 ) ) {
* V_72 = V_128 [ V_25 ] ;
return 0 ;
}
}
if ( F_81 ( V_124 -> V_129 + 1 , V_125 , V_124 -> V_130 ,
( V_124 -> V_131 == '+' ? V_132 : 0 ) |
( V_124 -> V_133 == '+' ? V_134 : 0 ) ,
V_72 ) )
return 0 ;
if ( F_82 ( V_124 -> V_129 + 1 , V_125 , V_124 -> V_130 ,
( V_124 -> V_131 == '+' ? V_132 : 0 ) |
( V_124 -> V_133 == '+' ? V_134 : 0 ) ,
V_35 -> V_135 , V_72 ) )
return 0 ;
F_44 ( 2 , V_56 , V_3 ,
L_25 ,
V_57 , V_124 -> V_130 , V_124 -> V_129 , V_124 -> V_126 ,
V_124 -> V_131 , V_124 -> V_133 ) ;
return - 1 ;
}
static int F_83 ( struct V_2 * V_3 , struct V_123 * V_124 )
{
if ( F_76 ( V_3 ) || F_75 ( V_3 ) ) {
F_44 ( 2 , V_56 , V_3 , L_26 , V_57 ) ;
return - 1 ;
}
V_124 -> V_126 = ( ( F_53 ( V_3 , 0xb1 ) & 0x3f ) << 8 ) | F_53 ( V_3 , 0xb2 ) ;
V_124 -> V_129 = ( ( F_53 ( V_3 , 0xb3 ) & 0x7 ) << 8 ) | F_53 ( V_3 , 0xb4 ) ;
V_124 -> V_130 = F_53 ( V_3 , 0xb3 ) >> 3 ;
V_124 -> V_136 = F_18 ( V_3 , 0x12 ) & 0x10 ;
if ( ( F_53 ( V_3 , 0xb5 ) & 0x03 ) == 0x01 ) {
V_124 -> V_131 = ( ( F_53 ( V_3 , 0xb5 ) & 0x10 ) ?
( ( F_53 ( V_3 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_124 -> V_133 = ( ( F_53 ( V_3 , 0xb5 ) & 0x40 ) ?
( ( F_53 ( V_3 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_124 -> V_131 = 'x' ;
V_124 -> V_133 = 'x' ;
}
if ( F_76 ( V_3 ) || F_75 ( V_3 ) ) {
F_44 ( 2 , V_56 , V_3 ,
L_27 , V_57 ) ;
return - 1 ;
}
if ( V_124 -> V_129 < 239 || V_124 -> V_126 < 8 || V_124 -> V_126 == 0x3fff ) {
F_44 ( 2 , V_56 , V_3 , L_28 , V_57 ) ;
memset ( V_124 , 0 , sizeof( struct V_123 ) ) ;
return - 1 ;
}
F_44 ( 2 , V_56 , V_3 ,
L_29 ,
V_57 , V_124 -> V_129 , V_124 -> V_126 , V_124 -> V_130 ,
V_124 -> V_131 , V_124 -> V_133 ,
V_124 -> V_136 ? L_30 : L_31 ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 ,
struct V_137 * V_72 )
{
if ( V_72 -> V_138 >= F_85 ( V_128 ) - 1 )
return - V_116 ;
memset ( V_72 -> V_139 , 0 , sizeof( V_72 -> V_139 ) ) ;
V_72 -> V_72 = V_128 [ V_72 -> V_138 ] ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_140 * V_141 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
V_141 -> type = V_142 ;
V_141 -> V_73 . V_143 = 1920 ;
V_141 -> V_73 . V_144 = 1200 ;
V_141 -> V_73 . V_145 = 25000000 ;
if ( V_75 )
V_141 -> V_73 . V_146 = 225000000 ;
else
V_141 -> V_73 . V_146 = 170000000 ;
V_141 -> V_73 . V_103 = V_104 | V_147 |
V_148 | V_149 ;
V_141 -> V_73 . V_150 = V_151 |
V_152 | V_153 ;
return 0 ;
}
static void F_87 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_25 ;
for ( V_25 = 0 ; V_128 [ V_25 ] . V_73 . V_74 ; V_25 ++ ) {
if ( F_65 ( V_72 , & V_128 [ V_25 ] ,
V_75 ? 250000 : 1000000 ) ) {
* V_72 = V_128 [ V_25 ] ;
break;
}
}
}
static int F_88 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_8 * V_73 = & V_72 -> V_73 ;
struct V_123 V_124 ;
if ( ! V_72 )
return - V_116 ;
memset ( V_72 , 0 , sizeof( struct V_71 ) ) ;
if ( F_77 ( V_3 ) ) {
F_44 ( 1 , V_56 , V_3 , L_32 , V_57 ) ;
return - V_154 ;
}
if ( F_83 ( V_3 , & V_124 ) ) {
F_44 ( 1 , V_56 , V_3 , L_33 , V_57 ) ;
return - V_154 ;
}
V_73 -> V_136 = V_124 . V_136 ?
V_155 : V_156 ;
if ( V_75 ) {
T_5 V_157 ;
V_72 -> type = V_142 ;
V_73 -> V_74 = ( F_49 ( V_3 , 0x07 ) & 0x0f ) * 256 + F_49 ( V_3 , 0x08 ) ;
V_73 -> V_86 = ( F_49 ( V_3 , 0x09 ) & 0x0f ) * 256 + F_49 ( V_3 , 0x0a ) ;
V_157 = ( F_49 ( V_3 , 0x06 ) * 1000000 ) +
( ( F_49 ( V_3 , 0x3b ) & 0x30 ) >> 4 ) * 250000 ;
if ( F_74 ( V_3 ) ) {
unsigned V_158 = ( ( F_49 ( V_3 , 0x0b ) & 0x60 ) >> 4 ) + 8 ;
V_157 = V_157 * 8 / V_158 ;
}
V_73 -> V_98 = V_157 ;
V_73 -> V_91 = ( F_49 ( V_3 , 0x20 ) & 0x03 ) * 256 +
F_49 ( V_3 , 0x21 ) ;
V_73 -> V_88 = ( F_49 ( V_3 , 0x22 ) & 0x03 ) * 256 +
F_49 ( V_3 , 0x23 ) ;
V_73 -> V_89 = ( F_49 ( V_3 , 0x24 ) & 0x03 ) * 256 +
F_49 ( V_3 , 0x25 ) ;
V_73 -> V_93 = ( ( F_49 ( V_3 , 0x2a ) & 0x1f ) * 256 +
F_49 ( V_3 , 0x2b ) ) / 2 ;
V_73 -> V_95 = ( ( F_49 ( V_3 , 0x2e ) & 0x1f ) * 256 +
F_49 ( V_3 , 0x2f ) ) / 2 ;
V_73 -> V_96 = ( ( F_49 ( V_3 , 0x32 ) & 0x1f ) * 256 +
F_49 ( V_3 , 0x33 ) ) / 2 ;
V_73 -> V_159 = ( ( F_49 ( V_3 , 0x05 ) & 0x10 ) ? V_134 : 0 ) |
( ( F_49 ( V_3 , 0x05 ) & 0x20 ) ? V_132 : 0 ) ;
if ( V_73 -> V_136 == V_155 ) {
V_73 -> V_86 += ( F_49 ( V_3 , 0x0b ) & 0x0f ) * 256 +
F_49 ( V_3 , 0x0c ) ;
V_73 -> V_160 = ( ( F_49 ( V_3 , 0x2c ) & 0x1f ) * 256 +
F_49 ( V_3 , 0x2d ) ) / 2 ;
V_73 -> V_161 = ( ( F_49 ( V_3 , 0x30 ) & 0x1f ) * 256 +
F_49 ( V_3 , 0x31 ) ) / 2 ;
V_73 -> V_96 = ( ( F_49 ( V_3 , 0x34 ) & 0x1f ) * 256 +
F_49 ( V_3 , 0x35 ) ) / 2 ;
}
F_87 ( V_3 , V_72 ) ;
} else {
if ( ! F_80 ( V_3 , & V_124 , V_72 ) )
goto V_162;
V_124 . V_130 += 1 ;
F_44 ( 1 , V_56 , V_3 , L_34 , V_57 , V_124 . V_130 ) ;
if ( ! F_80 ( V_3 , & V_124 , V_72 ) )
goto V_162;
V_124 . V_130 -= 2 ;
F_44 ( 1 , V_56 , V_3 , L_35 , V_57 , V_124 . V_130 ) ;
if ( F_80 ( V_3 , & V_124 , V_72 ) ) {
if ( V_35 -> V_163 ) {
F_44 ( 1 , V_56 , V_3 , L_36 , V_57 ) ;
F_55 ( V_3 , 0x86 , 0xf9 , 0x00 ) ;
F_55 ( V_3 , 0x86 , 0xf9 , 0x04 ) ;
F_55 ( V_3 , 0x86 , 0xf9 , 0x02 ) ;
V_35 -> V_163 = false ;
return - V_154 ;
}
F_44 ( 1 , V_56 , V_3 , L_37 , V_57 ) ;
return - V_164 ;
}
V_35 -> V_163 = true ;
}
V_162:
if ( F_77 ( V_3 ) ) {
F_44 ( 1 , V_56 , V_3 , L_38 , V_57 ) ;
memset ( V_72 , 0 , sizeof( struct V_71 ) ) ;
return - V_154 ;
}
if ( ( ! V_75 && V_73 -> V_98 > 170000000 ) ||
( V_75 && V_73 -> V_98 > 225000000 ) ) {
F_44 ( 1 , V_56 , V_3 , L_39 ,
V_57 , ( T_3 ) V_73 -> V_98 ) ;
return - V_164 ;
}
if ( V_56 > 1 )
F_89 ( V_3 -> V_165 , L_40 ,
V_72 , true ) ;
return 0 ;
}
static int F_90 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_8 * V_73 ;
int V_24 ;
if ( ! V_72 )
return - V_116 ;
V_73 = & V_72 -> V_73 ;
if ( ( ! V_75 && V_73 -> V_98 > 170000000 ) ||
( V_75 && V_73 -> V_98 > 225000000 ) ) {
F_44 ( 1 , V_56 , V_3 , L_39 ,
V_57 , ( T_3 ) V_73 -> V_98 ) ;
return - V_164 ;
}
F_87 ( V_3 , V_72 ) ;
V_35 -> V_72 = * V_72 ;
F_54 ( V_3 , 0x91 , V_73 -> V_136 ? 0x50 : 0x10 ) ;
V_24 = F_66 ( V_3 , V_72 ) ;
if ( V_24 ) {
F_67 ( V_3 , V_73 ) ;
}
F_69 ( V_3 ) ;
if ( V_56 > 1 )
F_89 ( V_3 -> V_165 , L_41 ,
V_72 , true ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
* V_72 = V_35 -> V_72 ;
return 0 ;
}
static void F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
switch ( V_35 -> V_78 ) {
case V_79 :
case V_80 :
F_20 ( V_3 , 0x15 , 0xb0 ) ;
break;
case V_83 :
F_50 ( V_3 , 0x1a , 0x0a ) ;
F_50 ( V_3 , 0x01 , 0x00 ) ;
F_20 ( V_3 , 0x15 , 0xa0 ) ;
break;
default:
F_44 ( 2 , V_56 , V_3 , L_21 ,
V_57 , V_35 -> V_78 ) ;
break;
}
}
static void F_93 ( struct V_2 * V_3 )
{
F_20 ( V_3 , 0x15 , 0xbe ) ;
F_50 ( V_3 , 0x1a , 0x1a ) ;
F_50 ( V_3 , 0x01 , 0x78 ) ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
switch ( V_35 -> V_78 ) {
case V_79 :
case V_80 :
F_50 ( V_3 , 0x0d , 0x04 ) ;
F_50 ( V_3 , 0x3d , 0x00 ) ;
F_50 ( V_3 , 0x3e , 0x74 ) ;
F_50 ( V_3 , 0x4e , 0x3b ) ;
F_50 ( V_3 , 0x57 , 0x74 ) ;
F_50 ( V_3 , 0x58 , 0x63 ) ;
F_50 ( V_3 , 0x8d , 0x18 ) ;
F_50 ( V_3 , 0x8e , 0x34 ) ;
F_50 ( V_3 , 0x93 , 0x88 ) ;
F_50 ( V_3 , 0x94 , 0x2e ) ;
F_50 ( V_3 , 0x96 , 0x00 ) ;
F_34 ( V_3 , 0x00 , 0x08 ) ;
F_34 ( V_3 , 0x01 , 0x06 ) ;
F_34 ( V_3 , 0xc8 , 0x00 ) ;
F_34 ( V_3 , 0x12 , 0x7b ) ;
F_34 ( V_3 , 0x0c , 0x1f ) ;
F_54 ( V_3 , 0x3e , 0x04 ) ;
F_54 ( V_3 , 0xc3 , 0x39 ) ;
F_54 ( V_3 , 0x40 , 0x5c ) ;
break;
case V_83 :
F_50 ( V_3 , 0x0d , 0x84 ) ;
F_50 ( V_3 , 0x3d , 0x10 ) ;
F_50 ( V_3 , 0x3e , 0x39 ) ;
F_50 ( V_3 , 0x4e , 0x3b ) ;
F_50 ( V_3 , 0x57 , 0xb6 ) ;
F_50 ( V_3 , 0x58 , 0x03 ) ;
F_50 ( V_3 , 0x8d , 0x18 ) ;
F_50 ( V_3 , 0x8e , 0x34 ) ;
F_50 ( V_3 , 0x93 , 0x8b ) ;
F_50 ( V_3 , 0x94 , 0x2d ) ;
F_50 ( V_3 , 0x96 , 0x01 ) ;
F_34 ( V_3 , 0x00 , 0xff ) ;
F_34 ( V_3 , 0x01 , 0xfe ) ;
F_34 ( V_3 , 0xc8 , 0x40 ) ;
F_34 ( V_3 , 0x12 , 0xfb ) ;
F_34 ( V_3 , 0x0c , 0x0d ) ;
F_54 ( V_3 , 0x3e , 0x00 ) ;
F_54 ( V_3 , 0xc3 , 0x39 ) ;
F_54 ( V_3 , 0x40 , 0x80 ) ;
break;
default:
F_44 ( 2 , V_56 , V_3 , L_21 ,
V_57 , V_35 -> V_78 ) ;
break;
}
}
static int F_95 ( struct V_2 * V_3 ,
T_3 V_166 , T_3 V_167 , T_3 V_168 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
F_44 ( 2 , V_56 , V_3 , L_42 , V_57 , V_166 ) ;
V_35 -> V_78 = V_166 ;
F_93 ( V_3 ) ;
F_94 ( V_3 ) ;
F_92 ( V_3 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , unsigned int V_138 ,
enum V_169 * V_170 )
{
if ( V_138 )
return - V_116 ;
* V_170 = V_171 ;
return 0 ;
}
static int F_97 ( struct V_2 * V_3 ,
struct V_172 * V_173 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
V_173 -> V_74 = V_35 -> V_72 . V_73 . V_74 ;
V_173 -> V_86 = V_35 -> V_72 . V_73 . V_86 ;
V_173 -> V_170 = V_171 ;
V_173 -> V_174 = V_175 ;
if ( V_35 -> V_72 . V_73 . V_103 & V_104 ) {
V_173 -> V_176 = ( V_35 -> V_72 . V_73 . V_86 <= 576 ) ?
V_177 : V_178 ;
}
return 0 ;
}
static int F_98 ( struct V_2 * V_3 , T_3 V_118 , bool * V_179 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
T_2 V_180 , V_181 , V_182 ;
T_3 V_183 ;
V_180 = F_18 ( V_3 , 0x43 ) & 0x98 ;
if ( V_180 )
F_20 ( V_3 , 0x44 , V_180 ) ;
V_181 = V_75 ? ( F_18 ( V_3 , 0x6b ) & 0xc0 ) : 0 ;
if ( V_181 )
F_20 ( V_3 , 0x6c , V_181 ) ;
if ( V_180 || V_181 ) {
F_44 ( 1 , V_56 , V_3 ,
L_43 ,
V_57 , V_180 , V_181 ) ;
F_79 ( V_3 , & V_183 ) ;
if ( V_183 != V_35 -> V_184 ) {
F_44 ( 1 , V_56 , V_3 ,
L_44 ,
V_57 , V_183 , V_35 -> V_184 ) ;
V_35 -> V_184 = V_183 ;
F_45 ( V_3 , V_185 , NULL ) ;
}
if ( V_179 )
* V_179 = true ;
}
V_182 = F_18 ( V_3 , 0x70 ) & 0x10 ;
if ( V_182 ) {
F_44 ( 1 , V_56 , V_3 , L_45 , V_57 , V_182 ) ;
F_20 ( V_3 , 0x71 , V_182 ) ;
F_62 ( V_3 ) ;
if ( V_179 )
* V_179 = true ;
}
return 0 ;
}
static int F_99 ( struct V_2 * V_3 , struct V_186 * V_187 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
if ( V_187 -> V_188 != 0 )
return - V_116 ;
if ( V_187 -> V_189 == 0 )
return - V_116 ;
if ( V_187 -> V_190 >= V_35 -> V_191 )
return - V_116 ;
if ( V_187 -> V_190 + V_187 -> V_189 > V_35 -> V_191 )
V_187 -> V_189 = V_35 -> V_191 - V_187 -> V_190 ;
if ( ! V_187 -> V_187 )
return - V_116 ;
memcpy ( V_187 -> V_187 + V_187 -> V_190 * 128 ,
V_35 -> V_187 + V_187 -> V_190 * 128 ,
V_187 -> V_189 * 128 ) ;
return 0 ;
}
static int F_100 ( struct V_2 * V_3 , struct V_186 * V_187 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_24 ;
if ( V_187 -> V_188 != 0 )
return - V_116 ;
if ( V_187 -> V_190 != 0 )
return - V_116 ;
if ( V_187 -> V_189 == 0 ) {
F_45 ( V_3 , V_58 , ( void * ) 0 ) ;
F_37 ( V_3 , 0x77 , 0xf0 , 0x0 ) ;
V_35 -> V_191 = 0 ;
V_35 -> V_135 . V_192 = 16 ;
V_35 -> V_135 . V_193 = 9 ;
return 0 ;
}
if ( V_187 -> V_189 > 2 )
return - V_194 ;
if ( ! V_187 -> V_187 )
return - V_116 ;
memcpy ( V_35 -> V_187 , V_187 -> V_187 , 128 * V_187 -> V_189 ) ;
V_35 -> V_191 = V_187 -> V_189 ;
V_35 -> V_135 = F_101 ( V_187 -> V_187 [ 0x15 ] ,
V_187 -> V_187 [ 0x16 ] ) ;
V_24 = F_46 ( V_3 , 128 * V_187 -> V_189 , V_35 -> V_187 ) ;
if ( V_24 < 0 )
F_68 ( V_3 , L_46 , V_24 ) ;
return V_24 ;
}
static void F_102 ( struct V_2 * V_3 )
{
int V_25 ;
T_2 V_49 [ 14 ] ;
T_2 V_195 ;
T_2 V_196 ;
if ( ! F_74 ( V_3 ) ) {
F_59 ( V_3 , L_47 ) ;
return;
}
if ( ! ( F_18 ( V_3 , 0x60 ) & 0x01 ) ) {
F_59 ( V_3 , L_48 ) ;
return;
}
if ( F_18 ( V_3 , 0x83 ) & 0x01 ) {
F_59 ( V_3 , L_49 ) ;
F_20 ( V_3 , 0x85 , 0x01 ) ;
if ( F_18 ( V_3 , 0x83 ) & 0x01 ) {
F_59 ( V_3 , L_50 ) ;
F_20 ( V_3 , 0x85 , 0x01 ) ;
}
}
V_195 = F_27 ( V_3 , 0xe2 ) ;
V_196 = F_27 ( V_3 , 0xe1 ) ;
F_59 ( V_3 , L_51 ,
V_196 , V_195 ) ;
if ( V_196 != 0x02 )
return;
for ( V_25 = 0 ; V_25 < 14 ; V_25 ++ )
V_49 [ V_25 ] = F_27 ( V_3 , V_25 ) ;
F_59 ( V_3 ,
L_52 ,
V_49 [ 0 ] , V_49 [ 1 ] , V_49 [ 2 ] , V_49 [ 3 ] , V_49 [ 4 ] , V_49 [ 5 ] , V_49 [ 6 ] , V_49 [ 7 ] ,
V_49 [ 8 ] , V_49 [ 9 ] , V_49 [ 10 ] , V_49 [ 11 ] , V_49 [ 12 ] , V_49 [ 13 ] ) ;
}
static int F_103 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_71 V_72 ;
struct V_123 V_124 ;
T_2 V_197 = F_18 ( V_3 , 0x02 ) ;
char * V_198 [ 16 ] = {
L_53 , L_54 , L_55 , L_56 ,
L_55 , L_57 , L_55 , L_58 ,
L_55 , L_59 , L_60 ,
L_55 , L_55 , L_55 , L_55 , L_61
} ;
char * V_199 [ 16 ] = {
L_62 , L_63 ,
L_64 , L_65 ,
L_66 , L_67 ,
L_68 , L_69 ,
L_70 , L_70 , L_70 , L_70 , L_70 ,
L_70 , L_70 , L_71
} ;
char * V_200 [] = {
L_72 ,
L_62 ,
L_63 ,
} ;
char * V_201 [ 4 ] = {
L_73 ,
L_74 ,
L_75 ,
L_76
} ;
F_59 ( V_3 , L_77 ) ;
F_59 ( V_3 , L_78 , F_71 ( V_3 ) ? L_79 : L_80 ) ;
F_59 ( V_3 , L_81 , V_35 -> V_202 ?
L_82 : ( V_75 ? L_83 : L_84 ) ) ;
F_59 ( V_3 , L_85 , ( ( F_35 ( V_3 , 0x7d ) & 0x01 ) &&
( F_35 ( V_3 , 0x77 ) & 0x01 ) ) ? L_86 : L_87 ) ;
F_59 ( V_3 , L_88 , ! ! ( F_24 ( V_3 , 0x2a ) & 0x01 ) ?
L_86 : L_89 ) ;
F_59 ( V_3 , L_90 ) ;
F_59 ( V_3 , L_91 ,
( F_18 ( V_3 , 0x6f ) & 0x10 ) ? L_92 : L_93 ) ;
F_59 ( V_3 , L_94 ,
F_72 ( V_3 ) ? L_93 : L_92 ) ;
F_59 ( V_3 , L_95 ,
F_73 ( V_3 ) ? L_93 : L_92 ) ;
F_59 ( V_3 , L_96 , F_75 ( V_3 ) ? L_93 : L_92 ) ;
F_59 ( V_3 , L_97 , F_76 ( V_3 ) ? L_93 : L_92 ) ;
F_59 ( V_3 , L_98 , F_78 ( V_3 ) ? L_93 : L_92 ) ;
F_59 ( V_3 , L_99 ,
( ! ! ( F_53 ( V_3 , 0xff ) & 0x10 ) ? L_80 : L_79 ) ) ;
F_59 ( V_3 , L_100 ,
F_18 ( V_3 , 0x01 ) & 0x0f , F_18 ( V_3 , 0x00 ) & 0x3f ,
( F_18 ( V_3 , 0x01 ) & 0x70 ) >> 4 ) ;
F_59 ( V_3 , L_101 ) ;
if ( F_83 ( V_3 , & V_124 ) )
F_59 ( V_3 , L_102 ) ;
else
F_59 ( V_3 , L_103 ,
V_124 . V_129 , V_124 . V_126 , V_124 . V_130 ,
V_124 . V_136 ? L_30 : L_31 ,
V_124 . V_131 , V_124 . V_133 ) ;
if ( F_88 ( V_3 , & V_72 ) )
F_59 ( V_3 , L_104 ) ;
else
F_89 ( V_3 -> V_165 , L_105 ,
& V_72 , true ) ;
F_89 ( V_3 -> V_165 , L_106 ,
& V_35 -> V_72 , true ) ;
if ( F_77 ( V_3 ) )
return 0 ;
F_59 ( V_3 , L_107 ) ;
F_59 ( V_3 , L_108 ,
V_200 [ V_35 -> V_101 ] ) ;
F_59 ( V_3 , L_109 ,
V_199 [ V_197 >> 4 ] ) ;
F_59 ( V_3 , L_110 ,
( V_197 & 0x02 ) ? L_111 : L_112 ,
( V_197 & 0x04 ) ? L_113 : L_114 ,
( ( V_197 & 0x04 ) ^ ( V_197 & 0x01 ) ) ?
L_86 : L_89 ) ;
F_59 ( V_3 , L_115 ,
V_198 [ F_53 ( V_3 , 0xfc ) >> 4 ] ) ;
if ( ! V_75 )
return 0 ;
F_59 ( V_3 , L_116 , F_74 ( V_3 ) ? L_82 : L_83 ) ;
F_59 ( V_3 , L_117 , ( F_49 ( V_3 , 0x05 ) & 0x40 ) ? L_92 : L_93 ) ;
F_59 ( V_3 , L_118 ,
( F_49 ( V_3 , 0x04 ) & 0x20 ) ? L_119 : L_120 ,
( F_49 ( V_3 , 0x04 ) & 0x10 ) ? L_121 : L_122 ) ;
if ( ! F_74 ( V_3 ) ) {
bool V_203 = F_49 ( V_3 , 0x04 ) & 0x01 ;
bool V_204 = F_49 ( V_3 , 0x18 ) & 0x01 ;
bool V_205 = F_18 ( V_3 , 0x65 ) & 0x40 ;
F_59 ( V_3 , L_123 ,
V_203 ? L_124 : L_125 ,
V_204 ? L_126 : L_127 ,
V_205 ? L_128 : L_86 ) ;
if ( V_203 && V_204 ) {
F_59 ( V_3 , L_129 ,
( F_49 ( V_3 , 0x07 ) & 0x20 ) ? L_130 : L_131 ) ;
}
F_59 ( V_3 , L_132 , ( F_49 ( V_3 , 0x5b ) << 12 ) +
( F_49 ( V_3 , 0x5c ) << 8 ) +
( F_49 ( V_3 , 0x5d ) & 0xf0 ) ) ;
F_59 ( V_3 , L_133 , ( ( F_49 ( V_3 , 0x5d ) & 0x0f ) << 16 ) +
( F_49 ( V_3 , 0x5e ) << 8 ) +
F_49 ( V_3 , 0x5f ) ) ;
F_59 ( V_3 , L_134 , ( F_49 ( V_3 , 0x04 ) & 0x40 ) ? L_80 : L_79 ) ;
F_59 ( V_3 , L_135 , V_201 [ ( F_49 ( V_3 , 0x0b ) & 0x60 ) >> 5 ] ) ;
F_102 ( V_3 ) ;
}
return 0 ;
}
static int F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_206 * V_207 = & V_35 -> V_207 ;
F_50 ( V_3 , 0x48 ,
( V_207 -> V_208 ? 0x80 : 0 ) |
( V_207 -> V_209 ? 0x40 : 0 ) ) ;
F_93 ( V_3 ) ;
F_20 ( V_3 , 0x0c , 0x42 ) ;
F_20 ( V_3 , 0x0b , 0x44 ) ;
F_54 ( V_3 , 0xcf , 0x01 ) ;
F_21 ( V_3 , 0x02 , 0xf0 ,
V_207 -> V_210 << 3 |
V_207 -> V_211 << 2 |
V_207 -> V_212 << 1 |
V_207 -> V_213 << 0 ) ;
F_20 ( V_3 , 0x03 , V_207 -> V_214 ) ;
F_21 ( V_3 , 0x04 , 0x1f , V_207 -> V_215 << 5 ) ;
F_21 ( V_3 , 0x05 , 0xf0 , V_207 -> V_216 << 3 |
V_207 -> V_217 << 2 |
V_207 -> V_218 << 1 |
V_207 -> V_219 << 0 ) ;
F_54 ( V_3 , 0x69 , 0x30 ) ;
F_20 ( V_3 , 0x06 , 0xa6 ) ;
F_20 ( V_3 , 0x14 , 0x7f ) ;
F_54 ( V_3 , 0xba , ( V_207 -> V_220 << 1 ) | 0x01 ) ;
F_54 ( V_3 , 0xf3 , 0xdc ) ;
F_54 ( V_3 , 0xf9 , 0x23 ) ;
F_54 ( V_3 , 0x45 , 0x23 ) ;
F_54 ( V_3 , 0xc9 , 0x2d ) ;
F_34 ( V_3 , 0xb5 , 0x01 ) ;
F_34 ( V_3 , 0x02 , V_207 -> V_221 ) ;
F_21 ( V_3 , 0x30 , ~ ( 1 << 4 ) , V_207 -> V_222 << 4 ) ;
F_20 ( V_3 , 0x40 , 0xc2 ) ;
F_20 ( V_3 , 0x41 , 0xd7 ) ;
F_20 ( V_3 , 0x46 , 0x98 ) ;
F_20 ( V_3 , 0x6e , 0xc0 ) ;
F_20 ( V_3 , 0x73 , 0x10 ) ;
return F_105 ( V_3 -> V_223 ) ;
}
static void F_106 ( struct V_1 * V_35 )
{
if ( V_35 -> V_36 )
F_107 ( V_35 -> V_36 ) ;
if ( V_35 -> V_37 )
F_107 ( V_35 -> V_37 ) ;
if ( V_35 -> V_38 )
F_107 ( V_35 -> V_38 ) ;
if ( V_35 -> V_39 )
F_107 ( V_35 -> V_39 ) ;
if ( V_35 -> V_40 )
F_107 ( V_35 -> V_40 ) ;
if ( V_35 -> V_41 )
F_107 ( V_35 -> V_41 ) ;
if ( V_35 -> V_42 )
F_107 ( V_35 -> V_42 ) ;
if ( V_35 -> V_43 )
F_107 ( V_35 -> V_43 ) ;
if ( V_35 -> V_61 )
F_107 ( V_35 -> V_61 ) ;
if ( V_35 -> V_62 )
F_107 ( V_35 -> V_62 ) ;
if ( V_35 -> V_63 )
F_107 ( V_35 -> V_63 ) ;
if ( V_35 -> V_64 )
F_107 ( V_35 -> V_64 ) ;
}
static struct V_10 * F_108 ( struct V_2 * V_3 ,
T_2 V_17 , T_2 V_224 )
{
struct V_10 * V_11 = F_19 ( V_3 ) ;
if ( V_17 )
F_20 ( V_3 , V_224 , V_17 << 1 ) ;
return F_109 ( V_11 -> V_16 , F_18 ( V_3 , V_224 ) >> 1 ) ;
}
static int F_110 ( struct V_10 * V_11 ,
const struct V_225 * V_107 )
{
struct V_1 * V_35 ;
struct V_206 * V_207 = V_11 -> V_226 . V_227 ;
struct V_228 * V_7 ;
struct V_2 * V_3 ;
int V_24 ;
if ( ! F_111 ( V_11 -> V_16 , V_229 ) )
return - V_22 ;
F_112 ( 1 , V_56 , V_11 , L_136 ,
V_11 -> V_17 << 1 ) ;
V_35 = F_113 ( & V_11 -> V_226 , sizeof( * V_35 ) , V_230 ) ;
if ( ! V_35 ) {
F_14 ( V_11 , L_137 ) ;
return - V_231 ;
}
V_35 -> V_163 = true ;
V_35 -> V_184 = ~ 0 ;
if ( ! V_207 ) {
F_14 ( V_11 , L_138 ) ;
return - V_232 ;
}
memcpy ( & V_35 -> V_207 , V_207 , sizeof( V_35 -> V_207 ) ) ;
V_3 = & V_35 -> V_3 ;
F_114 ( V_3 , V_11 , & V_233 ) ;
V_3 -> V_18 |= V_234 ;
V_35 -> V_202 = V_207 -> V_202 ;
if ( F_12 ( V_11 , 0xfb , false ) != 0x68 ) {
F_59 ( V_3 , L_139 ,
V_11 -> V_17 << 1 ) ;
return - V_232 ;
}
V_7 = & V_35 -> V_7 ;
F_115 ( V_7 , 9 ) ;
F_116 ( V_7 , & V_235 ,
V_108 , - 128 , 127 , 1 , 0 ) ;
F_116 ( V_7 , & V_235 ,
V_109 , 0 , 255 , 1 , 128 ) ;
F_116 ( V_7 , & V_235 ,
V_110 , 0 , 255 , 1 , 128 ) ;
F_116 ( V_7 , & V_235 ,
V_111 , 0 , 128 , 1 , 0 ) ;
V_35 -> V_67 = F_116 ( V_7 , NULL ,
V_236 , 0 , 1 , 0 , 0 ) ;
V_35 -> V_237 =
F_117 ( V_7 , & V_235 ,
V_112 , V_106 ,
0 , V_102 ) ;
V_35 -> V_238 =
F_118 ( V_7 , & V_239 , NULL ) ;
V_35 -> V_240 =
F_118 ( V_7 , & V_241 , NULL ) ;
V_35 -> V_242 =
F_118 ( V_7 , & V_243 , NULL ) ;
V_3 -> V_223 = V_7 ;
if ( V_7 -> error ) {
V_24 = V_7 -> error ;
goto V_244;
}
V_35 -> V_67 -> V_245 = true ;
V_35 -> V_237 -> V_245 = true ;
V_35 -> V_238 -> V_245 = true ;
V_35 -> V_240 -> V_245 = true ;
V_35 -> V_242 -> V_245 = true ;
if ( F_62 ( V_3 ) ) {
V_24 = - V_232 ;
goto V_244;
}
V_35 -> V_36 = F_108 ( V_3 , V_207 -> V_36 , 0xf3 ) ;
V_35 -> V_37 = F_108 ( V_3 , V_207 -> V_37 , 0xf4 ) ;
V_35 -> V_38 = F_108 ( V_3 , V_207 -> V_38 , 0xf5 ) ;
V_35 -> V_39 = F_108 ( V_3 , V_207 -> V_39 , 0xf6 ) ;
V_35 -> V_40 = F_108 ( V_3 , V_207 -> V_40 , 0xf7 ) ;
V_35 -> V_41 = F_108 ( V_3 , V_207 -> V_41 , 0xf8 ) ;
V_35 -> V_42 = F_108 ( V_3 , V_207 -> V_42 , 0xf9 ) ;
V_35 -> V_43 = F_108 ( V_3 , V_207 -> V_43 , 0xfa ) ;
V_35 -> V_61 = F_108 ( V_3 , V_207 -> V_61 , 0xfb ) ;
V_35 -> V_62 = F_108 ( V_3 , V_207 -> V_62 , 0xfc ) ;
V_35 -> V_63 = F_108 ( V_3 , V_207 -> V_63 , 0xfd ) ;
V_35 -> V_64 = F_108 ( V_3 , V_207 -> V_64 , 0xfe ) ;
if ( ! V_35 -> V_36 || ! V_35 -> V_37 || ! V_35 -> V_38 ||
! V_35 -> V_39 || ! V_35 -> V_40 || ! V_35 -> V_41 ||
! V_35 -> V_42 || ! V_35 -> V_43 || ! V_35 -> V_61 ||
! V_35 -> V_62 || ! V_35 -> V_63 || ! V_35 -> V_64 ) {
V_24 = - V_231 ;
F_68 ( V_3 , L_140 ) ;
goto V_246;
}
V_35 -> V_59 = F_119 ( V_11 -> V_165 ) ;
if ( ! V_35 -> V_59 ) {
F_68 ( V_3 , L_141 ) ;
V_24 = - V_231 ;
goto V_246;
}
F_120 ( & V_35 -> V_55 ,
F_42 ) ;
V_35 -> V_188 . V_18 = V_247 ;
V_24 = F_121 ( & V_3 -> V_248 , 1 , & V_35 -> V_188 , 0 ) ;
if ( V_24 )
goto V_249;
V_24 = F_104 ( V_3 ) ;
if ( V_24 )
goto V_250;
F_59 ( V_3 , L_142 , V_11 -> V_165 ,
V_11 -> V_17 << 1 , V_11 -> V_16 -> V_165 ) ;
return 0 ;
V_250:
F_122 ( & V_3 -> V_248 ) ;
V_249:
F_123 ( & V_35 -> V_55 ) ;
F_124 ( V_35 -> V_59 ) ;
V_246:
F_106 ( V_35 ) ;
V_244:
F_125 ( V_7 ) ;
return V_24 ;
}
static int F_126 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_127 ( V_11 ) ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
F_123 ( & V_35 -> V_55 ) ;
F_124 ( V_35 -> V_59 ) ;
F_128 ( V_3 ) ;
F_122 ( & V_3 -> V_248 ) ;
F_106 ( F_1 ( V_3 ) ) ;
F_125 ( V_3 -> V_223 ) ;
return 0 ;
}
