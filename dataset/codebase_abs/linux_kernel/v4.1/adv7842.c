static bool F_1 ( const struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_5 [ V_4 ] . V_6 . V_7 ; V_4 ++ )
if ( F_2 ( V_2 , V_5 + V_4 , 0 ) )
return false ;
return true ;
}
static inline struct V_8 * F_3 ( struct V_9 * V_10 )
{
return F_4 ( V_10 , struct V_8 , V_10 ) ;
}
static inline struct V_9 * F_5 ( struct V_11 * V_12 )
{
return & F_4 ( V_12 -> V_13 , struct V_8 , V_3 ) -> V_10 ;
}
static inline unsigned F_6 ( const struct V_14 * V_2 )
{
return F_7 ( V_2 ) ;
}
static inline unsigned F_8 ( const struct V_14 * V_2 )
{
return F_9 ( V_2 ) ;
}
static T_1 F_10 ( struct V_15 * V_16 ,
T_2 V_17 , bool V_18 )
{
union V_19 V_20 ;
if ( ! F_11 ( V_16 -> V_21 , V_16 -> V_22 , V_16 -> V_23 ,
V_24 , V_17 ,
V_25 , & V_20 ) )
return V_20 . V_26 ;
if ( V_18 )
F_12 ( V_16 , L_1 ,
V_16 -> V_22 , V_17 ) ;
return - V_27 ;
}
static T_1 F_13 ( struct V_15 * V_16 , T_2 V_17 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
int V_28 = F_10 ( V_16 , V_17 , true ) ;
if ( V_28 >= 0 ) {
if ( V_4 )
F_12 ( V_16 , L_2 , V_4 ) ;
return V_28 ;
}
}
F_12 ( V_16 , L_3 ) ;
return - V_27 ;
}
static T_1 F_14 ( struct V_15 * V_16 ,
T_2 V_17 , T_2 V_29 )
{
union V_19 V_20 ;
int V_30 ;
int V_4 ;
V_20 . V_26 = V_29 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
V_30 = F_11 ( V_16 -> V_21 , V_16 -> V_22 ,
V_16 -> V_23 ,
V_31 , V_17 ,
V_25 , & V_20 ) ;
if ( ! V_30 )
break;
}
if ( V_30 < 0 )
F_12 ( V_16 , L_4 ,
V_16 -> V_22 , V_17 , V_29 ) ;
return V_30 ;
}
static void F_15 ( struct V_15 * V_16 ,
T_2 V_17 , T_2 V_29 )
{
union V_19 V_20 ;
V_20 . V_26 = V_29 ;
F_11 ( V_16 -> V_21 , V_16 -> V_22 ,
V_16 -> V_23 ,
V_31 , V_17 ,
V_25 , & V_20 ) ;
}
static T_1 F_16 ( struct V_15 * V_16 ,
T_2 V_17 , unsigned V_32 , const T_2 * V_33 )
{
union V_19 V_20 ;
if ( V_32 > V_34 )
V_32 = V_34 ;
V_20 . V_35 [ 0 ] = V_32 ;
memcpy ( V_20 . V_35 + 1 , V_33 , V_32 ) ;
return F_11 ( V_16 -> V_21 , V_16 -> V_22 , V_16 -> V_23 ,
V_31 , V_17 ,
V_36 , & V_20 ) ;
}
static inline int F_17 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_15 * V_16 = F_18 ( V_10 ) ;
return F_13 ( V_16 , V_37 ) ;
}
static inline int F_19 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_15 * V_16 = F_18 ( V_10 ) ;
return F_14 ( V_16 , V_37 , V_38 ) ;
}
static inline int F_20 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_19 ( V_10 , V_37 , ( F_17 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_21 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_41 , V_37 ) ;
}
static inline int F_22 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_41 , V_37 , V_38 ) ;
}
static inline int F_23 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_42 , V_37 ) ;
}
static inline int F_24 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_42 , V_37 , V_38 ) ;
}
static inline int F_25 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_24 ( V_10 , V_37 , ( F_23 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_26 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_43 , V_37 ) ;
}
static inline int F_27 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_43 , V_37 , V_38 ) ;
}
static inline int F_28 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_44 , V_37 ) ;
}
static inline int F_29 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_44 , V_37 , V_38 ) ;
}
static inline int F_30 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_29 ( V_10 , V_37 , ( F_28 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_31 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_45 , V_37 ) ;
}
static inline int F_32 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_45 , V_37 , V_38 ) ;
}
static inline int F_33 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_32 ( V_10 , V_37 , ( F_31 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_34 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_46 , V_37 ) ;
}
static inline int F_35 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_46 , V_37 , V_38 ) ;
}
static inline int F_36 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_35 ( V_10 , V_37 , ( F_34 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_37 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_47 , V_37 ) ;
}
static inline int F_38 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_47 , V_37 , V_38 ) ;
}
static inline int F_39 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_38 ( V_10 , V_37 , ( F_37 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_40 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_48 , V_37 ) ;
}
static inline int F_41 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_48 , V_37 , V_38 ) ;
}
static inline int F_42 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_49 , V_37 ) ;
}
static inline int F_43 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_49 , V_37 , V_38 ) ;
}
static inline int F_44 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_43 ( V_10 , V_37 , ( F_42 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_45 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_50 , V_37 ) ;
}
static inline int F_46 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_50 , V_37 , V_38 ) ;
}
static inline int F_47 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_46 ( V_10 , V_37 , ( F_45 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_48 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_13 ( V_40 -> V_51 , V_37 ) ;
}
static inline int F_49 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_14 ( V_40 -> V_51 , V_37 , V_38 ) ;
}
static void F_50 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_18 ( V_10 ) ;
F_51 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
F_15 ( V_16 , 0xff , 0x80 ) ;
F_52 ( 5 ) ;
}
static inline bool F_53 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return ( ( V_40 -> V_54 == V_55 ) ||
( V_40 -> V_54 == V_56 ) ) ;
}
static inline bool F_54 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return V_40 -> V_54 == V_57 ;
}
static inline const struct V_58 *
F_55 ( struct V_9 * V_10 )
{
return F_54 ( V_10 ) ? & V_59 :
& V_60 ;
}
static void F_56 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_57 ( V_62 ) ;
struct V_8 * V_40 = F_4 ( V_64 ,
struct V_8 , V_65 ) ;
struct V_9 * V_10 = & V_40 -> V_10 ;
int V_66 = V_40 -> V_67 . V_66 ;
T_2 V_39 = 0 ;
F_51 ( 2 , V_52 , V_10 , L_6 ,
V_53 , V_66 ) ;
if ( V_66 & ( 0x04 << V_68 ) )
V_39 |= 0x20 ;
if ( V_66 & ( 0x04 << V_69 ) )
V_39 |= 0x10 ;
F_20 ( V_10 , 0x20 , 0xcf , V_39 ) ;
}
static int F_58 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_18 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_70 . V_71 ;
int V_30 = 0 ;
int V_4 ;
F_51 ( 2 , V_52 , V_10 , L_7 , V_53 ) ;
F_20 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_39 ( V_10 , 0x7f , 0x7f , 0x00 ) ;
F_39 ( V_10 , 0x77 , 0xef , 0x10 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_16 ( V_40 -> V_48 , V_4 ,
V_34 , V_38 + V_4 ) ;
if ( V_30 )
return V_30 ;
F_39 ( V_10 , 0x7f , 0x7f , 0x80 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_37 ( V_10 , 0x79 ) & 0x20 )
break;
F_52 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_12 ( V_16 , L_8 ) ;
return - V_27 ;
}
F_59 ( V_40 -> V_72 ,
& V_40 -> V_65 , V_73 / 5 ) ;
return 0 ;
}
static int F_60 ( const T_2 * V_71 )
{
T_2 V_74 ;
if ( ( V_71 [ 0x7e ] != 1 ) ||
( V_71 [ 0x80 ] != 0x02 ) ||
( V_71 [ 0x81 ] != 0x03 ) ) {
return - V_75 ;
}
V_74 = V_71 [ 0x82 ] & 0x7f ;
if ( V_74 > 4 ) {
int V_4 = 0x84 ;
int V_76 = 0x80 + V_74 ;
do {
T_2 V_77 = V_71 [ V_4 ] >> 5 ;
T_2 V_78 = V_71 [ V_4 ] & 0x1f ;
if ( ( V_77 == 3 ) && ( V_78 >= 5 ) )
return V_4 + 4 ;
V_4 += V_78 + 1 ;
} while ( V_4 < V_76 );
}
return - V_75 ;
}
static int F_61 ( struct V_9 * V_10 , T_2 V_79 )
{
struct V_15 * V_16 = F_18 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_67 . V_71 ;
int V_80 = F_60 ( V_38 ) ;
int V_30 = 0 ;
int V_4 ;
F_51 ( 2 , V_52 , V_10 , L_9 ,
V_53 , ( V_79 == V_68 ) ? 'A' : 'B' , V_80 ) ;
F_20 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_39 ( V_10 , 0x77 , 0xf3 , 0x00 ) ;
if ( ! V_40 -> V_67 . V_66 )
return 0 ;
F_39 ( V_10 , 0x77 , 0xef , 0x00 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_16 ( V_40 -> V_48 , V_4 ,
V_34 , V_38 + V_4 ) ;
if ( V_30 )
return V_30 ;
if ( V_80 < 0 )
V_80 = 0xc0 ;
if ( V_79 == V_68 ) {
F_38 ( V_10 , 0x72 , V_38 [ V_80 ] ) ;
F_38 ( V_10 , 0x73 , V_38 [ V_80 + 1 ] ) ;
} else {
F_38 ( V_10 , 0x74 , V_38 [ V_80 ] ) ;
F_38 ( V_10 , 0x75 , V_38 [ V_80 + 1 ] ) ;
}
F_38 ( V_10 , 0x76 , V_80 & 0xff ) ;
F_39 ( V_10 , 0x77 , 0xbf , ( V_80 >> 2 ) & 0x40 ) ;
F_39 ( V_10 , 0x77 , 0xf3 , V_40 -> V_67 . V_66 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_37 ( V_10 , 0x7d ) & V_40 -> V_67 . V_66 )
break;
F_52 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_12 ( V_16 , L_10 ,
( V_79 == V_68 ) ? 'A' : 'B' ) ;
return - V_27 ;
}
F_59 ( V_40 -> V_72 ,
& V_40 -> V_65 , V_73 / 5 ) ;
return 0 ;
}
static void F_62 ( struct V_9 * V_10 )
{
F_63 ( V_10 , L_11 ) ;
F_63 ( V_10 , L_12 ) ;
F_63 ( V_10 , L_13 ) ;
F_63 ( V_10 , L_14 ) ;
F_63 ( V_10 , L_15 ) ;
F_63 ( V_10 , L_16 ) ;
F_63 ( V_10 , L_17 ) ;
F_63 ( V_10 , L_18 ) ;
F_63 ( V_10 , L_19 ) ;
F_63 ( V_10 , L_20 ) ;
F_63 ( V_10 , L_21 ) ;
F_63 ( V_10 , L_22 ) ;
}
static int F_64 ( struct V_9 * V_10 ,
struct V_81 * V_37 )
{
V_37 -> V_82 = 1 ;
switch ( V_37 -> V_37 >> 8 ) {
case 0 :
V_37 -> V_38 = F_17 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 1 :
V_37 -> V_38 = F_21 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 2 :
V_37 -> V_38 = F_23 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 3 :
V_37 -> V_38 = F_26 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 4 :
V_37 -> V_38 = F_28 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 5 :
V_37 -> V_38 = F_31 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 6 :
V_37 -> V_38 = F_34 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 7 :
V_37 -> V_38 = F_37 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 8 :
V_37 -> V_38 = F_40 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 9 :
V_37 -> V_38 = F_42 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 0xa :
V_37 -> V_38 = F_45 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 0xb :
V_37 -> V_38 = F_48 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
default:
F_63 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_62 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_65 ( struct V_9 * V_10 ,
const struct V_81 * V_37 )
{
T_2 V_38 = V_37 -> V_38 & 0xff ;
switch ( V_37 -> V_37 >> 8 ) {
case 0 :
F_19 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 1 :
F_22 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 2 :
F_24 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 3 :
F_27 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 4 :
F_29 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 5 :
F_32 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 6 :
F_35 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 7 :
F_38 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 8 :
F_41 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 9 :
F_43 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 0xa :
F_46 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 0xb :
F_49 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
default:
F_63 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_62 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_66 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_83 = F_67 ( V_40 -> V_84 ) ;
T_2 V_85 = F_17 ( V_10 , 0x6f ) ;
int V_38 = 0 ;
if ( V_85 & 0x02 )
V_38 |= 1 ;
if ( V_85 & 0x01 )
V_38 |= 2 ;
F_51 ( 1 , V_52 , V_10 , L_24 , V_53 , V_83 , V_38 ) ;
if ( V_38 != V_83 )
return F_68 ( V_40 -> V_84 , V_38 ) ;
return 0 ;
}
static int F_69 ( struct V_9 * V_10 ,
T_2 V_86 ,
const struct V_87 * V_88 ,
const struct V_1 * V_89 )
{
int V_4 ;
for ( V_4 = 0 ; V_88 [ V_4 ] . V_89 . V_6 . V_7 ; V_4 ++ ) {
if ( ! F_2 ( V_89 , & V_88 [ V_4 ] . V_89 ,
F_54 ( V_10 ) ? 250000 : 1000000 ) )
continue;
F_19 ( V_10 , 0x00 , V_88 [ V_4 ] . V_90 ) ;
F_19 ( V_10 , 0x01 , ( V_88 [ V_4 ] . V_91 << 4 ) + V_86 ) ;
return 0 ;
}
return - 1 ;
}
static int F_70 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 ;
F_51 ( 1 , V_52 , V_10 , L_25 , V_53 ) ;
F_19 ( V_10 , 0x16 , 0x43 ) ;
F_19 ( V_10 , 0x17 , 0x5a ) ;
F_47 ( V_10 , 0x81 , 0xef , 0x00 ) ;
F_46 ( V_10 , 0x26 , 0x00 ) ;
F_46 ( V_10 , 0x27 , 0x00 ) ;
F_46 ( V_10 , 0x28 , 0x00 ) ;
F_46 ( V_10 , 0x29 , 0x00 ) ;
F_46 ( V_10 , 0x8f , 0x40 ) ;
F_46 ( V_10 , 0x90 , 0x00 ) ;
F_46 ( V_10 , 0xa5 , 0x00 ) ;
F_46 ( V_10 , 0xa6 , 0x00 ) ;
F_46 ( V_10 , 0xa7 , 0x00 ) ;
F_46 ( V_10 , 0xab , 0x00 ) ;
F_46 ( V_10 , 0xac , 0x00 ) ;
switch ( V_40 -> V_54 ) {
case V_56 :
case V_55 :
V_30 = F_69 ( V_10 ,
0x01 , V_92 , V_89 ) ;
if ( V_30 )
V_30 = F_69 ( V_10 ,
0x02 , V_93 , V_89 ) ;
break;
case V_57 :
V_30 = F_69 ( V_10 ,
0x05 , V_94 , V_89 ) ;
if ( V_30 )
V_30 = F_69 ( V_10 ,
0x06 , V_95 , V_89 ) ;
break;
default:
F_51 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
V_30 = - 1 ;
break;
}
return V_30 ;
}
static void F_71 ( struct V_9 * V_10 ,
const struct V_14 * V_6 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_15 * V_16 = F_18 ( V_10 ) ;
T_3 V_7 = F_6 ( V_6 ) ;
T_3 V_96 = F_8 ( V_6 ) ;
T_4 V_97 = V_6 -> V_98 + V_6 -> V_99 - 4 ;
T_4 V_100 = V_7 - V_6 -> V_101 ;
T_4 V_102 = V_96 - V_6 -> V_103 + 1 ;
T_4 V_104 = V_6 -> V_105 + V_6 -> V_106 + 1 ;
T_4 V_107 = ( ( ( T_3 ) V_6 -> V_108 / 100 ) > 0 ) ?
( ( V_7 * ( V_109 / 100 ) ) / ( ( T_3 ) V_6 -> V_108 / 100 ) ) : 0 ;
const T_2 V_110 [ 2 ] = {
0xc0 | ( ( V_7 >> 8 ) & 0x1f ) ,
V_7 & 0xff
} ;
F_51 ( 2 , V_52 , V_10 , L_25 , V_53 ) ;
switch ( V_40 -> V_54 ) {
case V_56 :
case V_55 :
F_19 ( V_10 , 0x00 , 0x07 ) ;
F_19 ( V_10 , 0x01 , 0x02 ) ;
F_47 ( V_10 , 0x81 , 0xef , 0x10 ) ;
if ( F_16 ( V_16 , 0x16 , 2 , V_110 ) ) {
F_72 ( V_10 , L_27 ) ;
break;
}
F_46 ( V_10 , 0x26 , ( V_97 >> 8 ) & 0xf ) ;
F_46 ( V_10 , 0x27 , ( V_97 & 0xff ) ) ;
F_46 ( V_10 , 0x28 , ( V_100 >> 8 ) & 0xf ) ;
F_46 ( V_10 , 0x29 , ( V_100 & 0xff ) ) ;
F_46 ( V_10 , 0xa5 , ( V_102 >> 4 ) & 0xff ) ;
F_46 ( V_10 , 0xa6 , ( ( V_102 & 0xf ) << 4 ) |
( ( V_104 >> 8 ) & 0xf ) ) ;
F_46 ( V_10 , 0xa7 , V_104 & 0xff ) ;
break;
case V_57 :
F_19 ( V_10 , 0x00 , 0x02 ) ;
F_19 ( V_10 , 0x01 , 0x06 ) ;
break;
default:
F_51 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
F_46 ( V_10 , 0x8f , ( V_107 >> 8 ) & 0x7 ) ;
F_46 ( V_10 , 0x90 , V_107 & 0xff ) ;
F_46 ( V_10 , 0xab , ( V_96 >> 4 ) & 0xff ) ;
F_46 ( V_10 , 0xac , ( V_96 & 0x0f ) << 4 ) ;
}
static void F_73 ( struct V_9 * V_10 , bool V_111 , T_4 V_112 , T_4 V_113 , T_4 V_114 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_115 [ 4 ] ;
if ( V_111 ) {
V_112 = 0x3ff ;
V_113 = 0x3ff ;
V_114 = 0x3ff ;
}
F_51 ( 2 , V_52 , V_10 , L_28 ,
V_53 , V_111 ? L_29 : L_30 ,
V_112 , V_113 , V_114 ) ;
V_115 [ 0 ] = ( F_45 ( V_10 , 0x77 ) & 0xc0 ) | ( ( V_112 & 0x3f0 ) >> 4 ) ;
V_115 [ 1 ] = ( ( V_112 & 0x00f ) << 4 ) | ( ( V_113 & 0x3c0 ) >> 6 ) ;
V_115 [ 2 ] = ( ( V_113 & 0x03f ) << 2 ) | ( ( V_114 & 0x300 ) >> 8 ) ;
V_115 [ 3 ] = V_114 & 0x0ff ;
if ( F_16 ( V_40 -> V_50 , 0x77 , 4 , V_115 ) )
F_72 ( V_10 , L_31 , V_53 ) ;
}
static void F_74 ( struct V_9 * V_10 , bool V_116 , T_4 V_117 , T_4 V_118 , T_4 V_119 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_120 [ 4 ] ;
T_2 V_121 = 1 ;
T_2 V_122 = 1 ;
if ( V_116 ) {
V_121 = 0 ;
V_122 = 0 ;
V_117 = 0x100 ;
V_118 = 0x100 ;
V_119 = 0x100 ;
}
F_51 ( 2 , V_52 , V_10 , L_32 ,
V_53 , V_116 ? L_29 : L_30 ,
V_117 , V_118 , V_119 ) ;
V_120 [ 0 ] = ( ( V_121 << 7 ) | ( V_122 << 6 ) | ( ( V_117 & 0x3f0 ) >> 4 ) ) ;
V_120 [ 1 ] = ( ( ( V_117 & 0x00f ) << 4 ) | ( ( V_118 & 0x3c0 ) >> 6 ) ) ;
V_120 [ 2 ] = ( ( ( V_118 & 0x03f ) << 2 ) | ( ( V_119 & 0x300 ) >> 8 ) ) ;
V_120 [ 3 ] = ( ( V_119 & 0x0ff ) ) ;
if ( F_16 ( V_40 -> V_50 , 0x73 , 4 , V_120 ) )
F_72 ( V_10 , L_33 , V_53 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
bool V_123 = F_17 ( V_10 , 0x02 ) & 0x02 ;
bool V_124 = F_42 ( V_10 , 0x05 ) & 0x80 ;
F_51 ( 2 , V_52 , V_10 , L_34 ,
V_53 , V_40 -> V_125 ,
V_123 , V_124 ) ;
F_74 ( V_10 , true , 0x0 , 0x0 , 0x0 ) ;
F_73 ( V_10 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_40 -> V_125 ) {
case V_126 :
if ( V_40 -> V_54 == V_55 ) {
F_20 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
break;
}
if ( V_40 -> V_54 == V_56 ) {
F_20 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_124 ) {
F_20 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_40 -> V_89 . V_6 . V_23 & V_127 ) {
F_20 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_20 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
if ( F_54 ( V_10 ) && V_123 ) {
F_73 ( V_10 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_74 ( V_10 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_73 ( V_10 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_128 :
if ( V_40 -> V_54 == V_56 ) {
F_20 ( V_10 , 0x02 , 0x0f , 0x20 ) ;
break;
}
F_20 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_129 :
if ( V_40 -> V_54 == V_56 ) {
F_20 ( V_10 , 0x02 , 0x0f , 0x60 ) ;
break;
}
F_20 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
if ( F_53 ( V_10 ) || V_124 )
break;
if ( V_123 ) {
F_73 ( V_10 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_74 ( V_10 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_73 ( V_10 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_76 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_12 -> V_130 ) {
case V_131 :
F_46 ( V_10 , 0x3c , V_12 -> V_38 ) ;
F_32 ( V_10 , 0x14 , V_12 -> V_38 ) ;
return 0 ;
case V_132 :
F_46 ( V_10 , 0x3a , V_12 -> V_38 ) ;
F_32 ( V_10 , 0x13 , V_12 -> V_38 ) ;
return 0 ;
case V_133 :
F_46 ( V_10 , 0x3b , V_12 -> V_38 ) ;
F_32 ( V_10 , 0x15 , V_12 -> V_38 ) ;
return 0 ;
case V_134 :
F_46 ( V_10 , 0x3d , V_12 -> V_38 ) ;
F_32 ( V_10 , 0x16 , V_12 -> V_38 ) ;
return 0 ;
case V_135 :
F_35 ( V_10 , 0xc8 , V_12 -> V_38 ) ;
return 0 ;
case V_136 :
F_47 ( V_10 , 0xbf , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
F_33 ( V_10 , 0xdd , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
return 0 ;
case V_137 : {
T_2 V_138 = ( V_12 -> V_38 & 0xff0000 ) >> 16 ;
T_2 V_139 = ( V_12 -> V_38 & 0x00ff00 ) >> 8 ;
T_2 V_140 = ( V_12 -> V_38 & 0x0000ff ) ;
int V_141 = 66 * V_138 + 129 * V_139 + 25 * V_140 ;
int V_142 = - 38 * V_138 - 74 * V_139 + 112 * V_140 ;
int V_143 = 112 * V_138 - 94 * V_139 - 18 * V_140 ;
V_141 = ( V_141 + 128 ) >> 8 ;
V_142 = ( V_142 + 128 ) >> 8 ;
V_143 = ( V_143 + 128 ) >> 8 ;
V_141 += 16 ;
V_142 += 128 ;
V_143 += 128 ;
F_51 ( 1 , V_52 , V_10 , L_35 , V_138 , V_139 , V_140 ) ;
F_51 ( 1 , V_52 , V_10 , L_36 , V_141 , V_142 , V_143 ) ;
F_46 ( V_10 , 0xc1 , V_138 ) ;
F_46 ( V_10 , 0xc0 , V_139 ) ;
F_46 ( V_10 , 0xc2 , V_140 ) ;
F_32 ( V_10 , 0xde , V_141 ) ;
F_32 ( V_10 , 0xdf , ( V_143 & 0xf0 ) | ( ( V_142 >> 4 ) & 0x0f ) ) ;
return 0 ;
}
case V_144 :
V_40 -> V_125 = V_12 -> V_38 ;
F_75 ( V_10 ) ;
return 0 ;
}
return - V_75 ;
}
static inline bool F_77 ( struct V_9 * V_10 )
{
return F_17 ( V_10 , 0x0c ) & 0x24 ;
}
static inline bool F_78 ( struct V_9 * V_10 )
{
return ( ( F_45 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ) || ! ( F_45 ( V_10 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_79 ( struct V_9 * V_10 )
{
return F_42 ( V_10 , 0x05 ) & 0x80 ;
}
static int F_80 ( struct V_9 * V_10 , T_3 * V_145 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
* V_145 = 0 ;
if ( F_17 ( V_10 , 0x0c ) & 0x24 )
* V_145 |= V_146 ;
if ( V_40 -> V_54 == V_147 ) {
if ( ! ( F_31 ( V_10 , 0x5A ) & 0x01 ) )
* V_145 |= V_148 ;
F_51 ( 1 , V_52 , V_10 , L_37 ,
V_53 , * V_145 ) ;
return 0 ;
}
if ( ( F_45 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ||
! ( F_45 ( V_10 , 0xb1 ) & 0x80 ) )
* V_145 |= V_148 ;
if ( F_54 ( V_10 ) && ( ( F_17 ( V_10 , 0x74 ) & 0x03 ) != 0x03 ) )
* V_145 |= V_148 ;
F_51 ( 1 , V_52 , V_10 , L_38 ,
V_53 , * V_145 ) ;
return 0 ;
}
static int F_81 ( struct V_9 * V_10 ,
struct V_149 * V_150 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_3 V_151 = ( V_109 * 8 ) / V_150 -> V_152 ;
T_3 V_153 ;
int V_4 ;
for ( V_4 = 0 ; V_154 [ V_4 ] . V_6 . V_7 ; V_4 ++ ) {
const struct V_14 * V_6 = & V_154 [ V_4 ] . V_6 ;
if ( ! F_82 ( & V_154 [ V_4 ] ,
F_55 ( V_10 ) ,
F_1 , NULL ) )
continue;
if ( F_8 ( V_6 ) != V_150 -> V_155 + 1 )
continue;
if ( V_6 -> V_105 != V_150 -> V_156 )
continue;
V_153 = V_151 * F_6 ( V_6 ) ;
if ( ( V_153 < V_6 -> V_108 + 1000000 ) &&
( V_153 > V_6 -> V_108 - 1000000 ) ) {
* V_89 = V_154 [ V_4 ] ;
return 0 ;
}
}
if ( F_83 ( V_150 -> V_155 + 1 , V_151 , V_150 -> V_156 ,
( V_150 -> V_157 == '+' ? V_158 : 0 ) |
( V_150 -> V_159 == '+' ? V_160 : 0 ) ,
V_89 ) )
return 0 ;
if ( F_84 ( V_150 -> V_155 + 1 , V_151 , V_150 -> V_156 ,
( V_150 -> V_157 == '+' ? V_158 : 0 ) |
( V_150 -> V_159 == '+' ? V_160 : 0 ) ,
V_40 -> V_161 , V_89 ) )
return 0 ;
F_51 ( 2 , V_52 , V_10 ,
L_39 ,
V_53 , V_150 -> V_156 , V_150 -> V_155 , V_150 -> V_152 ,
V_150 -> V_157 , V_150 -> V_159 ) ;
return - 1 ;
}
static int F_85 ( struct V_9 * V_10 , struct V_149 * V_150 )
{
T_3 V_145 ;
F_80 ( V_10 , & V_145 ) ;
if ( V_145 & V_148 ) {
F_51 ( 2 , V_52 , V_10 , L_40 , V_53 ) ;
return - V_162 ;
}
V_150 -> V_152 = ( ( F_45 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_45 ( V_10 , 0xb2 ) ;
V_150 -> V_155 = ( ( F_45 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_45 ( V_10 , 0xb4 ) ;
V_150 -> V_156 = F_45 ( V_10 , 0xb3 ) >> 3 ;
if ( ( F_45 ( V_10 , 0xb5 ) & 0x80 ) && ( ( F_45 ( V_10 , 0xb5 ) & 0x03 ) == 0x01 ) ) {
V_150 -> V_157 = ( ( F_45 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_45 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_150 -> V_159 = ( ( F_45 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_45 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_150 -> V_157 = 'x' ;
V_150 -> V_159 = 'x' ;
}
V_150 -> V_163 = ( F_45 ( V_10 , 0xb1 ) & 0x40 ) ? true : false ;
if ( V_150 -> V_155 < 239 || V_150 -> V_152 < 8 || V_150 -> V_152 == 0x3fff ) {
F_51 ( 2 , V_52 , V_10 , L_41 , V_53 ) ;
return - V_162 ;
}
F_51 ( 2 , V_52 , V_10 ,
L_42 ,
V_53 , V_150 -> V_155 , V_150 -> V_152 , V_150 -> V_156 ,
V_150 -> V_157 , V_150 -> V_159 ,
V_150 -> V_163 ? L_43 : L_44 ) ;
return 0 ;
}
static int F_86 ( struct V_9 * V_10 ,
struct V_164 * V_89 )
{
if ( V_89 -> V_165 != 0 )
return - V_75 ;
return F_87 ( V_89 ,
F_55 ( V_10 ) , F_1 , NULL ) ;
}
static int F_88 ( struct V_9 * V_10 ,
struct V_58 * V_166 )
{
if ( V_166 -> V_165 != 0 )
return - V_75 ;
* V_166 = * F_55 ( V_10 ) ;
return 0 ;
}
static void F_89 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
F_90 ( V_89 , F_55 ( V_10 ) ,
F_54 ( V_10 ) ? 250000 : 1000000 ,
F_1 , NULL ) ;
}
static int F_91 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 = & V_89 -> V_6 ;
struct V_149 V_150 = { 0 } ;
F_51 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
memset ( V_89 , 0 , sizeof( struct V_1 ) ) ;
if ( V_40 -> V_54 == V_147 )
return - V_167 ;
if ( F_85 ( V_10 , & V_150 ) ) {
V_40 -> V_168 = true ;
F_51 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return - V_162 ;
}
V_6 -> V_163 = V_150 . V_163 ?
V_169 : V_170 ;
if ( F_54 ( V_10 ) ) {
T_5 V_171 ;
V_89 -> type = V_172 ;
V_6 -> V_7 = ( F_42 ( V_10 , 0x07 ) & 0x0f ) * 256 + F_42 ( V_10 , 0x08 ) ;
V_6 -> V_96 = ( F_42 ( V_10 , 0x09 ) & 0x0f ) * 256 + F_42 ( V_10 , 0x0a ) ;
V_171 = ( ( F_42 ( V_10 , 0x51 ) << 1 ) + ( F_42 ( V_10 , 0x52 ) >> 7 ) ) * 1000000 ;
V_171 += ( ( F_42 ( V_10 , 0x52 ) & 0x7f ) * 7813 ) ;
if ( F_79 ( V_10 ) ) {
V_171 = V_171 * 8 / ( ( ( F_42 ( V_10 , 0x0b ) & 0xc0 ) >> 6 ) * 2 + 8 ) ;
}
V_6 -> V_108 = V_171 ;
V_6 -> V_101 = ( F_42 ( V_10 , 0x20 ) & 0x03 ) * 256 +
F_42 ( V_10 , 0x21 ) ;
V_6 -> V_98 = ( F_42 ( V_10 , 0x22 ) & 0x03 ) * 256 +
F_42 ( V_10 , 0x23 ) ;
V_6 -> V_99 = ( F_42 ( V_10 , 0x24 ) & 0x03 ) * 256 +
F_42 ( V_10 , 0x25 ) ;
V_6 -> V_103 = ( ( F_42 ( V_10 , 0x2a ) & 0x1f ) * 256 +
F_42 ( V_10 , 0x2b ) ) / 2 ;
V_6 -> V_105 = ( ( F_42 ( V_10 , 0x2e ) & 0x1f ) * 256 +
F_42 ( V_10 , 0x2f ) ) / 2 ;
V_6 -> V_106 = ( ( F_42 ( V_10 , 0x32 ) & 0x1f ) * 256 +
F_42 ( V_10 , 0x33 ) ) / 2 ;
V_6 -> V_173 = ( ( F_42 ( V_10 , 0x05 ) & 0x10 ) ? V_160 : 0 ) |
( ( F_42 ( V_10 , 0x05 ) & 0x20 ) ? V_158 : 0 ) ;
if ( V_6 -> V_163 == V_169 ) {
V_6 -> V_96 += ( F_42 ( V_10 , 0x0b ) & 0x0f ) * 256 +
F_42 ( V_10 , 0x0c ) ;
V_6 -> V_174 = ( ( F_42 ( V_10 , 0x2c ) & 0x1f ) * 256 +
F_42 ( V_10 , 0x2d ) ) / 2 ;
V_6 -> V_175 = ( ( F_42 ( V_10 , 0x30 ) & 0x1f ) * 256 +
F_42 ( V_10 , 0x31 ) ) / 2 ;
V_6 -> V_176 = ( ( F_42 ( V_10 , 0x34 ) & 0x1f ) * 256 +
F_42 ( V_10 , 0x35 ) ) / 2 ;
}
F_89 ( V_10 , V_89 ) ;
} else {
if ( ! F_81 ( V_10 , & V_150 , V_89 ) )
goto V_177;
V_150 . V_156 += 1 ;
F_51 ( 1 , V_52 , V_10 , L_46 , V_53 , V_150 . V_156 ) ;
if ( ! F_81 ( V_10 , & V_150 , V_89 ) )
goto V_177;
V_150 . V_156 -= 2 ;
F_51 ( 1 , V_52 , V_10 , L_47 , V_53 , V_150 . V_156 ) ;
if ( F_81 ( V_10 , & V_150 , V_89 ) ) {
if ( V_40 -> V_168 ) {
F_51 ( 1 , V_52 , V_10 , L_48 , V_53 ) ;
F_47 ( V_10 , 0x86 , 0xf9 , 0x00 ) ;
F_47 ( V_10 , 0x86 , 0xf9 , 0x04 ) ;
F_47 ( V_10 , 0x86 , 0xf9 , 0x02 ) ;
V_40 -> V_168 = false ;
return - V_162 ;
}
F_51 ( 1 , V_52 , V_10 , L_49 , V_53 ) ;
return - V_178 ;
}
V_40 -> V_168 = true ;
}
V_177:
if ( V_52 > 1 )
F_92 ( V_10 -> V_179 , L_50 ,
V_89 , true ) ;
return 0 ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 ;
int V_30 ;
F_51 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 == V_147 )
return - V_167 ;
if ( F_2 ( & V_40 -> V_89 , V_89 , 0 ) ) {
F_51 ( 1 , V_52 , V_10 , L_51 , V_53 ) ;
return 0 ;
}
V_6 = & V_89 -> V_6 ;
if ( ! F_82 ( V_89 , F_55 ( V_10 ) ,
F_1 , NULL ) )
return - V_178 ;
F_89 ( V_10 , V_89 ) ;
V_40 -> V_89 = * V_89 ;
F_46 ( V_10 , 0x91 , V_6 -> V_163 ? 0x40 : 0x00 ) ;
V_30 = F_70 ( V_10 , V_89 ) ;
if ( V_30 ) {
F_71 ( V_10 , V_6 ) ;
}
F_75 ( V_10 ) ;
if ( V_52 > 1 )
F_92 ( V_10 -> V_179 , L_52 ,
V_89 , true ) ;
return 0 ;
}
static int F_94 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_54 == V_147 )
return - V_167 ;
* V_89 = V_40 -> V_89 ;
return 0 ;
}
static void F_95 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_75 ( V_10 ) ;
switch ( V_40 -> V_54 ) {
case V_147 :
case V_56 :
case V_55 :
F_19 ( V_10 , 0x15 , 0xb0 ) ;
break;
case V_57 :
F_43 ( V_10 , 0x01 , 0x00 ) ;
F_19 ( V_10 , 0x15 , 0xa0 ) ;
F_44 ( V_10 , 0x1a , 0xef , 0x00 ) ;
break;
default:
F_51 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
}
static void F_96 ( struct V_9 * V_10 )
{
F_44 ( V_10 , 0x1a , 0xef , 0x10 ) ;
F_97 ( 16 ) ;
F_19 ( V_10 , 0x15 , 0xbe ) ;
F_43 ( V_10 , 0x01 , 0x78 ) ;
}
static void F_98 ( struct V_9 * V_10 ,
const struct V_180 * V_181 )
{
F_30 ( V_10 , 0xe0 , 0xbf , V_181 -> V_182 ? 0x00 : 0x40 ) ;
if ( ! V_181 -> V_182 )
return;
F_30 ( V_10 , 0xe0 , 0x7f , V_181 -> V_183 == 2 ? 0x80 : 0x00 ) ;
F_30 ( V_10 , 0xe0 , 0xe0 , V_181 -> V_184 >> 8 ) ;
F_29 ( V_10 , 0xe1 , V_181 -> V_184 ) ;
F_30 ( V_10 , 0xe2 , 0xe0 , V_181 -> V_185 >> 8 ) ;
F_29 ( V_10 , 0xe3 , V_181 -> V_185 ) ;
F_30 ( V_10 , 0xe4 , 0xe0 , V_181 -> V_186 >> 8 ) ;
F_29 ( V_10 , 0xe5 , V_181 -> V_186 ) ;
F_30 ( V_10 , 0xe6 , 0x80 , V_181 -> V_187 >> 8 ) ;
F_29 ( V_10 , 0xe7 , V_181 -> V_187 ) ;
F_30 ( V_10 , 0xe8 , 0xe0 , V_181 -> V_188 >> 8 ) ;
F_29 ( V_10 , 0xe9 , V_181 -> V_188 ) ;
F_30 ( V_10 , 0xea , 0xe0 , V_181 -> V_189 >> 8 ) ;
F_29 ( V_10 , 0xeb , V_181 -> V_189 ) ;
F_30 ( V_10 , 0xec , 0xe0 , V_181 -> V_190 >> 8 ) ;
F_29 ( V_10 , 0xed , V_181 -> V_190 ) ;
F_30 ( V_10 , 0xee , 0x80 , V_181 -> V_191 >> 8 ) ;
F_29 ( V_10 , 0xef , V_181 -> V_191 ) ;
F_30 ( V_10 , 0xf0 , 0xe0 , V_181 -> V_192 >> 8 ) ;
F_29 ( V_10 , 0xf1 , V_181 -> V_192 ) ;
F_30 ( V_10 , 0xf2 , 0xe0 , V_181 -> V_193 >> 8 ) ;
F_29 ( V_10 , 0xf3 , V_181 -> V_193 ) ;
F_30 ( V_10 , 0xf4 , 0xe0 , V_181 -> V_194 >> 8 ) ;
F_29 ( V_10 , 0xf5 , V_181 -> V_194 ) ;
F_30 ( V_10 , 0xf6 , 0x80 , V_181 -> V_195 >> 8 ) ;
F_29 ( V_10 , 0xf7 , V_181 -> V_195 ) ;
}
static void F_99 ( struct V_9 * V_10 ,
enum V_196 V_197 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_40 -> V_54 ) {
case V_147 :
F_19 ( V_10 , 0x00 , V_197 ) ;
F_19 ( V_10 , 0x01 , 0 ) ;
F_47 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_35 ( V_10 , 0x00 , 0x00 ) ;
F_35 ( V_10 , 0xc8 , 0x00 ) ;
F_19 ( V_10 , 0xdd , 0x90 ) ;
F_36 ( V_10 , 0x02 , 0x7f , 0x80 ) ;
if ( V_197 == V_198 ) {
F_35 ( V_10 , 0x03 , 0xa0 ) ;
F_35 ( V_10 , 0x04 , 0x00 ) ;
} else {
F_35 ( V_10 , 0x03 , 0xa0 ) ;
F_35 ( V_10 , 0x04 , 0xc0 ) ;
}
F_35 ( V_10 , 0x0c , 0x1f ) ;
F_35 ( V_10 , 0x12 , 0x63 ) ;
F_29 ( V_10 , 0xb2 , 0x60 ) ;
F_29 ( V_10 , 0xc8 , 0xe3 ) ;
F_32 ( V_10 , 0x00 , 0x3F ) ;
F_32 ( V_10 , 0x01 , 0x00 ) ;
F_32 ( V_10 , 0x03 , 0xE4 ) ;
F_32 ( V_10 , 0x04 , 0x0B ) ;
F_32 ( V_10 , 0x05 , 0xC3 ) ;
F_32 ( V_10 , 0x06 , 0xFE ) ;
F_32 ( V_10 , 0x12 , 0x0D ) ;
F_32 ( V_10 , 0xA7 , 0x00 ) ;
F_29 ( V_10 , 0xB0 , 0x00 ) ;
F_33 ( V_10 , 0x12 , 0xf6 , 0x09 ) ;
break;
case V_56 :
case V_55 :
F_36 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
F_19 ( V_10 , 0x00 , V_197 ) ;
F_19 ( V_10 , 0x01 , 0x02 ) ;
F_47 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_35 ( V_10 , 0x00 , 0x00 ) ;
F_35 ( V_10 , 0xc8 , 0x00 ) ;
if ( V_40 -> V_54 == V_56 ) {
F_20 ( V_10 , 0x02 , 0x0f , 0x60 ) ;
} else {
F_20 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
}
F_35 ( V_10 , 0x0c , 0x1f ) ;
F_35 ( V_10 , 0x12 , 0x63 ) ;
F_46 ( V_10 , 0x73 , 0x10 ) ;
F_46 ( V_10 , 0x74 , 0x04 ) ;
F_46 ( V_10 , 0x75 , 0x01 ) ;
F_46 ( V_10 , 0x76 , 0x00 ) ;
F_46 ( V_10 , 0x3e , 0x04 ) ;
F_46 ( V_10 , 0xc3 , 0x39 ) ;
F_46 ( V_10 , 0x40 , 0x5c ) ;
break;
case V_57 :
F_36 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
if ( V_40 -> V_199 )
F_43 ( V_10 , 0x00 , 0x02 ) ;
else
F_43 ( V_10 , 0x00 , 0x03 ) ;
F_19 ( V_10 , 0x00 , V_197 ) ;
F_19 ( V_10 , 0x01 , 5 ) ;
F_47 ( V_10 , 0x81 , 0xef , 0x00 ) ;
F_43 ( V_10 , 0xc0 , 0x00 ) ;
F_43 ( V_10 , 0x0d , 0x34 ) ;
F_43 ( V_10 , 0x3d , 0x10 ) ;
F_43 ( V_10 , 0x44 , 0x85 ) ;
F_43 ( V_10 , 0x46 , 0x1f ) ;
F_43 ( V_10 , 0x57 , 0xb6 ) ;
F_43 ( V_10 , 0x58 , 0x03 ) ;
F_43 ( V_10 , 0x60 , 0x88 ) ;
F_43 ( V_10 , 0x61 , 0x88 ) ;
F_43 ( V_10 , 0x6c , 0x18 ) ;
F_43 ( V_10 , 0x75 , 0x10 ) ;
F_43 ( V_10 , 0x85 , 0x1f ) ;
F_43 ( V_10 , 0x87 , 0x70 ) ;
F_43 ( V_10 , 0x89 , 0x04 ) ;
F_43 ( V_10 , 0x8a , 0x1e ) ;
F_43 ( V_10 , 0x93 , 0x04 ) ;
F_43 ( V_10 , 0x94 , 0x1e ) ;
F_43 ( V_10 , 0x99 , 0xa1 ) ;
F_43 ( V_10 , 0x9b , 0x09 ) ;
F_43 ( V_10 , 0x9d , 0x02 ) ;
F_35 ( V_10 , 0x00 , 0xff ) ;
F_35 ( V_10 , 0xc8 , 0x40 ) ;
F_46 ( V_10 , 0x73 , 0x10 ) ;
F_46 ( V_10 , 0x74 , 0x04 ) ;
F_46 ( V_10 , 0x75 , 0x01 ) ;
F_46 ( V_10 , 0x76 , 0x00 ) ;
F_35 ( V_10 , 0x12 , 0xfb ) ;
F_35 ( V_10 , 0x0c , 0x0d ) ;
F_46 ( V_10 , 0x3e , 0x00 ) ;
F_46 ( V_10 , 0xc3 , 0x33 ) ;
F_20 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
default:
F_51 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
}
static int F_100 ( struct V_9 * V_10 ,
T_3 V_200 , T_3 V_201 , T_3 V_202 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_51 ( 2 , V_52 , V_10 , L_53 , V_53 , V_200 ) ;
switch ( V_200 ) {
case V_203 :
V_40 -> V_54 = V_57 ;
V_40 -> V_197 = V_204 ;
V_40 -> V_199 = true ;
break;
case V_205 :
V_40 -> V_54 = V_57 ;
V_40 -> V_197 = V_204 ;
V_40 -> V_199 = false ;
break;
case V_206 :
V_40 -> V_54 = V_56 ;
V_40 -> V_197 = V_207 ;
break;
case V_208 :
V_40 -> V_54 = V_55 ;
V_40 -> V_197 = V_207 ;
break;
case V_209 :
V_40 -> V_54 = V_147 ;
V_40 -> V_197 = V_198 ;
break;
case V_210 :
V_40 -> V_54 = V_147 ;
V_40 -> V_197 = V_211 ;
break;
default:
return - V_75 ;
}
F_96 ( V_10 ) ;
F_99 ( V_10 , V_40 -> V_197 ) ;
F_95 ( V_10 ) ;
F_101 ( V_10 , V_212 , NULL ) ;
return 0 ;
}
static int F_102 ( struct V_9 * V_10 , unsigned int V_213 ,
T_3 * V_214 )
{
if ( V_213 )
return - V_75 ;
* V_214 = V_215 ;
return 0 ;
}
static int F_103 ( struct V_9 * V_10 ,
struct V_216 * V_217 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
V_217 -> V_7 = V_40 -> V_89 . V_6 . V_7 ;
V_217 -> V_96 = V_40 -> V_89 . V_6 . V_96 ;
V_217 -> V_214 = V_215 ;
V_217 -> V_218 = V_219 ;
if ( V_40 -> V_54 == V_147 ) {
if ( ! ( F_31 ( V_10 , 0x5A ) & 0x01 ) )
return - V_75 ;
V_217 -> V_7 = 720 ;
if ( V_40 -> V_220 & V_221 )
V_217 -> V_96 = 480 ;
else
V_217 -> V_96 = 576 ;
V_217 -> V_222 = V_223 ;
return 0 ;
}
V_217 -> V_222 = V_224 ;
if ( V_40 -> V_89 . V_6 . V_23 & V_127 ) {
V_217 -> V_222 = ( V_40 -> V_89 . V_6 . V_96 <= 576 ) ?
V_223 : V_225 ;
}
return 0 ;
}
static void F_104 ( struct V_9 * V_10 , bool V_226 )
{
if ( V_226 ) {
F_19 ( V_10 , 0x46 , 0x9c ) ;
F_19 ( V_10 , 0x5a , 0x10 ) ;
F_19 ( V_10 , 0x73 , 0x03 ) ;
F_19 ( V_10 , 0x78 , 0x03 ) ;
F_19 ( V_10 , 0xa0 , 0x09 ) ;
F_19 ( V_10 , 0x69 , 0x08 ) ;
} else {
F_19 ( V_10 , 0x46 , 0x0 ) ;
F_19 ( V_10 , 0x5a , 0x0 ) ;
F_19 ( V_10 , 0x73 , 0x0 ) ;
F_19 ( V_10 , 0x78 , 0x0 ) ;
F_19 ( V_10 , 0xa0 , 0x0 ) ;
F_19 ( V_10 , 0x69 , 0x0 ) ;
}
}
static int F_105 ( struct V_9 * V_10 , T_3 V_145 , bool * V_227 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_228 , V_229 , V_230 ;
T_2 V_231 [ 6 ] ;
F_104 ( V_10 , false ) ;
V_231 [ 0 ] = F_17 ( V_10 , 0x43 ) ;
V_231 [ 1 ] = F_17 ( V_10 , 0x57 ) ;
V_231 [ 2 ] = F_17 ( V_10 , 0x70 ) ;
V_231 [ 3 ] = F_17 ( V_10 , 0x75 ) ;
V_231 [ 4 ] = F_17 ( V_10 , 0x9d ) ;
V_231 [ 5 ] = F_17 ( V_10 , 0x66 ) ;
if ( V_231 [ 0 ] )
F_19 ( V_10 , 0x44 , V_231 [ 0 ] ) ;
if ( V_231 [ 1 ] )
F_19 ( V_10 , 0x58 , V_231 [ 1 ] ) ;
if ( V_231 [ 2 ] )
F_19 ( V_10 , 0x71 , V_231 [ 2 ] ) ;
if ( V_231 [ 3 ] )
F_19 ( V_10 , 0x76 , V_231 [ 3 ] ) ;
if ( V_231 [ 4 ] )
F_19 ( V_10 , 0x9e , V_231 [ 4 ] ) ;
if ( V_231 [ 5 ] )
F_19 ( V_10 , 0x67 , V_231 [ 5 ] ) ;
F_104 ( V_10 , true ) ;
F_51 ( 1 , V_52 , V_10 , L_54 , V_53 ,
V_231 [ 0 ] , V_231 [ 1 ] , V_231 [ 2 ] ,
V_231 [ 3 ] , V_231 [ 4 ] , V_231 [ 5 ] ) ;
V_228 = V_231 [ 0 ] & 0x9c ;
if ( V_40 -> V_54 == V_147 )
V_230 = ( V_231 [ 1 ] & 0x30 ) | ( V_231 [ 4 ] & 0x09 ) ;
else
V_230 = 0 ;
if ( F_54 ( V_10 ) )
V_229 = V_231 [ 3 ] & 0x03 ;
else
V_229 = 0 ;
if ( V_228 || V_229 || V_230 ) {
F_51 ( 1 , V_52 , V_10 ,
L_55 ,
V_53 , V_228 , V_229 ,
V_230 ) ;
F_101 ( V_10 , V_212 , NULL ) ;
if ( V_227 )
* V_227 = true ;
}
if ( V_231 [ 5 ] & 0x08 ) {
F_51 ( 1 , V_52 , V_10 , L_56 , V_53 ,
( F_17 ( V_10 , 0x65 ) & 0x08 ) ? L_57 : L_58 ) ;
F_75 ( V_10 ) ;
if ( V_227 )
* V_227 = true ;
}
if ( V_231 [ 2 ] & 0x3 ) {
F_51 ( 1 , V_52 , V_10 , L_59 , V_53 ) ;
F_66 ( V_10 ) ;
if ( V_227 )
* V_227 = true ;
}
return 0 ;
}
static int F_106 ( struct V_9 * V_10 , struct V_232 * V_71 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 * V_20 = NULL ;
memset ( V_71 -> V_233 , 0 , sizeof( V_71 -> V_233 ) ) ;
switch ( V_71 -> V_165 ) {
case V_68 :
case V_69 :
if ( V_40 -> V_67 . V_66 & ( 0x04 << V_71 -> V_165 ) )
V_20 = V_40 -> V_67 . V_71 ;
break;
case V_234 :
if ( V_40 -> V_70 . V_66 )
V_20 = V_40 -> V_70 . V_71 ;
break;
default:
return - V_75 ;
}
if ( V_71 -> V_235 == 0 && V_71 -> V_236 == 0 ) {
V_71 -> V_236 = V_20 ? 2 : 0 ;
return 0 ;
}
if ( ! V_20 )
return - V_167 ;
if ( V_71 -> V_235 >= 2 )
return - V_75 ;
if ( V_71 -> V_235 + V_71 -> V_236 > 2 )
V_71 -> V_236 = 2 - V_71 -> V_235 ;
memcpy ( V_71 -> V_71 , V_20 + V_71 -> V_235 * 128 , V_71 -> V_236 * 128 ) ;
return 0 ;
}
static int F_107 ( struct V_9 * V_10 , struct V_232 * V_237 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 = 0 ;
memset ( V_237 -> V_233 , 0 , sizeof( V_237 -> V_233 ) ) ;
if ( V_237 -> V_165 > V_234 )
return - V_75 ;
if ( V_237 -> V_235 != 0 )
return - V_75 ;
if ( V_237 -> V_236 > 2 ) {
V_237 -> V_236 = 2 ;
return - V_238 ;
}
V_40 -> V_161 = F_108 ( V_237 -> V_71 [ 0x15 ] ,
V_237 -> V_71 [ 0x16 ] ) ;
switch ( V_237 -> V_165 ) {
case V_234 :
memset ( & V_40 -> V_70 . V_71 , 0 , 256 ) ;
V_40 -> V_70 . V_66 = V_237 -> V_236 ? 0x1 : 0x0 ;
memcpy ( & V_40 -> V_70 . V_71 , V_237 -> V_71 , 128 * V_237 -> V_236 ) ;
V_30 = F_58 ( V_10 ) ;
break;
case V_68 :
case V_69 :
memset ( & V_40 -> V_67 . V_71 , 0 , 256 ) ;
if ( V_237 -> V_236 )
V_40 -> V_67 . V_66 |= 0x04 << V_237 -> V_165 ;
else
V_40 -> V_67 . V_66 &= ~ ( 0x04 << V_237 -> V_165 ) ;
memcpy ( & V_40 -> V_67 . V_71 , V_237 -> V_71 , 128 * V_237 -> V_236 ) ;
V_30 = F_61 ( V_10 , V_237 -> V_165 ) ;
break;
default:
return - V_75 ;
}
if ( V_30 < 0 )
F_72 ( V_10 , L_60 , V_30 , V_237 -> V_165 ) ;
return V_30 ;
}
static void F_109 ( struct V_9 * V_10 , struct V_239 * V_240 )
{
int V_4 ;
T_6 V_241 [ 32 ] ;
union V_242 V_243 ;
T_2 V_78 ;
struct V_15 * V_16 = F_18 ( V_10 ) ;
struct V_244 * V_245 = & V_16 -> V_245 ;
if ( ! ( F_17 ( V_10 , 0x60 ) & V_240 -> V_246 ) ) {
F_63 ( V_10 , L_61 , V_240 -> V_247 ) ;
return;
}
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ )
V_241 [ V_4 ] = F_26 ( V_10 , V_240 -> V_248 + V_4 ) ;
V_78 = V_241 [ 2 ] + 1 ;
if ( V_78 + 3 > sizeof( V_241 ) ) {
F_72 ( V_10 , L_62 , V_53 , V_240 -> V_247 , V_78 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_78 ; V_4 ++ )
V_241 [ V_4 + 3 ] = F_26 ( V_10 , V_240 -> V_249 + V_4 ) ;
if ( F_110 ( & V_243 , V_241 ) < 0 ) {
F_72 ( V_10 , L_63 , V_53 , V_240 -> V_247 ) ;
return;
}
F_111 ( V_250 , V_245 , & V_243 ) ;
}
static void F_112 ( struct V_9 * V_10 )
{
int V_4 ;
struct V_239 V_240 [] = {
{ L_64 , 0x01 , 0xe0 , 0x00 } ,
{ L_65 , 0x02 , 0xe3 , 0x1c } ,
{ L_66 , 0x04 , 0xe6 , 0x2a } ,
{ L_67 , 0x10 , 0xec , 0x54 }
} ;
if ( ! ( F_42 ( V_10 , 0x05 ) & 0x80 ) ) {
F_63 ( V_10 , L_68 ) ;
return;
}
for ( V_4 = 0 ; V_4 < F_113 ( V_240 ) ; V_4 ++ )
F_109 ( V_10 , & V_240 [ V_4 ] ) ;
}
static int F_114 ( struct V_9 * V_10 )
{
T_6 V_251 = F_31 ( V_10 , 0x5A ) & 0x01 ;
F_63 ( V_10 , L_69 , F_77 ( V_10 ) ? L_70 : L_71 ) ;
F_63 ( V_10 , L_72 ,
F_17 ( V_10 , 0x01 ) & 0x0f , F_17 ( V_10 , 0x00 ) & 0x3f ) ;
F_63 ( V_10 , L_73 ,
( F_31 ( V_10 , 0x56 ) & 0x01 ) ? L_71 : L_70 ) ;
F_63 ( V_10 , L_74 , V_251 ?
L_75 : L_76 ) ;
if ( V_251 ) {
static const char * const V_252 [] = {
L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
L_82 ,
L_83 ,
L_84 , L_85 , L_86 , L_87 , L_88 ,
L_89 ,
L_90 ,
L_91 ,
L_92
} ;
F_63 ( V_10 , L_93 ,
V_252 [ F_31 ( V_10 , 0x52 ) & 0x0f ] ) ;
F_63 ( V_10 , L_74 ,
( F_31 ( V_10 , 0x59 ) & 0x08 ) ? L_94 : L_95 ) ;
F_63 ( V_10 , L_74 ,
( F_31 ( V_10 , 0x57 ) & 0x08 ) ? L_96 : L_97 ) ;
F_63 ( V_10 , L_98 ,
( F_31 ( V_10 , 0x12 ) & 0x08 ) ? L_99 : L_100 ) ;
F_63 ( V_10 , L_101 ,
( F_28 ( V_10 , 0xe0 ) & 0x40 ) ? L_102 : L_103 ) ;
}
return 0 ;
}
static int F_115 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_1 V_89 ;
T_6 V_253 = F_17 ( V_10 , 0x02 ) ;
T_6 V_254 = F_17 ( V_10 , 0x21 ) ;
T_6 V_255 = F_37 ( V_10 , 0x77 ) ;
T_6 V_256 = F_37 ( V_10 , 0x7d ) ;
bool V_257 = F_42 ( V_10 , 0x04 ) & 0x01 ;
bool V_258 = F_42 ( V_10 , 0x18 ) & 0x01 ;
bool V_259 = F_17 ( V_10 , 0x65 ) & 0x40 ;
static const char * const V_260 [ 16 ] = {
L_104 , L_105 , L_106 , L_107 ,
L_106 , L_108 , L_106 , L_109 ,
L_106 , L_110 , L_111 ,
L_106 , L_106 , L_106 , L_106 , L_103
} ;
static const char * const V_261 [ 16 ] = {
L_112 , L_113 ,
L_114 , L_115 ,
L_116 , L_117 ,
L_118 , L_119 ,
L_120 , L_120 , L_120 , L_120 , L_120 ,
L_120 , L_120 , L_121
} ;
static const char * const V_262 [] = {
L_122 ,
L_112 ,
L_113 ,
} ;
static const char * const V_263 [ 4 ] = {
L_123 ,
L_124 ,
L_125 ,
L_126
} ;
F_63 ( V_10 , L_127 ) ;
F_63 ( V_10 , L_128 , F_77 ( V_10 ) ? L_70 : L_71 ) ;
F_63 ( V_10 , L_129 ,
V_40 -> V_199 ? L_130 : L_131 ) ;
F_63 ( V_10 , L_132 ,
( ( V_256 & 0x04 ) && ( V_255 & 0x04 ) ) ?
L_99 : L_100 ,
( ( V_256 & 0x08 ) && ( V_255 & 0x08 ) ) ?
L_99 : L_100 ) ;
F_63 ( V_10 , L_133 ,
V_254 & 0x02 ? L_99 : L_100 ,
V_254 & 0x01 ? L_99 : L_100 ) ;
F_63 ( V_10 , L_134 , ! ! ( F_23 ( V_10 , 0x2a ) & 0x01 ) ?
L_99 : L_100 ) ;
F_63 ( V_10 , L_135 ) ;
if ( V_40 -> V_199 ) {
F_63 ( V_10 , L_136 ,
F_17 ( V_10 , 0x6f ) & 0x02 ? L_137 : L_138 ) ;
F_63 ( V_10 , L_139 ,
( F_17 ( V_10 , 0x6a ) & 0x02 ) ? L_137 : L_138 ) ;
F_63 ( V_10 , L_140 ,
( F_17 ( V_10 , 0x6a ) & 0x20 ) ? L_137 : L_138 ) ;
} else {
F_63 ( V_10 , L_141 ,
F_17 ( V_10 , 0x6f ) & 0x01 ? L_137 : L_138 ) ;
F_63 ( V_10 , L_139 ,
( F_17 ( V_10 , 0x6a ) & 0x01 ) ? L_137 : L_138 ) ;
F_63 ( V_10 , L_140 ,
( F_17 ( V_10 , 0x6a ) & 0x10 ) ? L_137 : L_138 ) ;
}
F_63 ( V_10 , L_142 ,
( ! ! ( F_45 ( V_10 , 0xff ) & 0x10 ) ? L_71 : L_70 ) ) ;
F_63 ( V_10 , L_143 ,
F_17 ( V_10 , 0x01 ) & 0x0f , F_17 ( V_10 , 0x00 ) & 0x3f ,
( F_17 ( V_10 , 0x01 ) & 0x70 ) >> 4 ) ;
F_63 ( V_10 , L_144 ) ;
if ( F_78 ( V_10 ) ) {
F_63 ( V_10 , L_145 ) ;
} else {
T_5 V_152 = ( ( F_45 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_45 ( V_10 , 0xb2 ) ;
T_5 V_155 = ( ( F_45 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_45 ( V_10 , 0xb4 ) ;
T_5 V_156 = F_45 ( V_10 , 0xb3 ) >> 3 ;
T_5 V_264 = ( ( F_45 ( V_10 , 0xb8 ) & 0x1f ) << 8 ) | F_45 ( V_10 , 0xb9 ) ;
char V_157 = ( ( F_45 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_45 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
char V_159 = ( ( F_45 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_45 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
F_63 ( V_10 ,
L_146 ,
V_155 , V_152 , V_156 , V_264 ,
( F_45 ( V_10 , 0xb1 ) & 0x40 ) ?
L_43 : L_44 ,
V_157 , V_159 ) ;
}
if ( F_91 ( V_10 , & V_89 ) )
F_63 ( V_10 , L_147 ) ;
else
F_92 ( V_10 -> V_179 , L_148 ,
& V_89 , true ) ;
F_92 ( V_10 -> V_179 , L_149 ,
& V_40 -> V_89 , true ) ;
if ( F_78 ( V_10 ) )
return 0 ;
F_63 ( V_10 , L_150 ) ;
F_63 ( V_10 , L_151 ,
V_262 [ V_40 -> V_125 ] ) ;
F_63 ( V_10 , L_152 ,
V_261 [ V_253 >> 4 ] ) ;
F_63 ( V_10 , L_153 ,
( V_253 & 0x02 ) ? L_154 : L_155 ,
( V_253 & 0x04 ) ? L_156 : L_157 ,
( ( V_253 & 0x04 ) ^ ( V_253 & 0x01 ) ) ?
L_99 : L_100 ) ;
F_63 ( V_10 , L_158 ,
V_260 [ F_45 ( V_10 , 0xf4 ) >> 4 ] ) ;
if ( ! F_54 ( V_10 ) )
return 0 ;
F_63 ( V_10 , L_159 , F_79 ( V_10 ) ? L_57 : L_160 ) ;
F_63 ( V_10 , L_161 ,
( F_42 ( V_10 , 0x05 ) & 0x40 ) ? L_137 : L_138 ) ;
F_63 ( V_10 , L_162 ,
( F_42 ( V_10 , 0x04 ) & 0x20 ) ? L_163 : L_164 ,
( F_42 ( V_10 , 0x04 ) & 0x10 ) ? L_165 : L_166 ) ;
if ( ! F_79 ( V_10 ) )
return 0 ;
F_63 ( V_10 , L_167 ,
V_257 ? L_168 : L_169 ,
V_258 ? L_170 : L_171 ,
V_259 ? L_172 : L_99 ) ;
if ( V_257 && V_258 ) {
F_63 ( V_10 , L_173 ,
( F_42 ( V_10 , 0x07 ) & 0x40 ) ? L_174 : L_175 ) ;
}
F_63 ( V_10 , L_176 , ( F_42 ( V_10 , 0x5b ) << 12 ) +
( F_42 ( V_10 , 0x5c ) << 8 ) +
( F_42 ( V_10 , 0x5d ) & 0xf0 ) ) ;
F_63 ( V_10 , L_177 , ( ( F_42 ( V_10 , 0x5d ) & 0x0f ) << 16 ) +
( F_42 ( V_10 , 0x5e ) << 8 ) +
F_42 ( V_10 , 0x5f ) ) ;
F_63 ( V_10 , L_178 ,
( F_42 ( V_10 , 0x04 ) & 0x40 ) ? L_71 : L_70 ) ;
F_63 ( V_10 , L_179 ,
V_263 [ F_42 ( V_10 , 0x0b ) >> 6 ] ) ;
F_112 ( V_10 ) ;
return 0 ;
}
static int F_116 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_54 == V_147 )
return F_114 ( V_10 ) ;
return F_115 ( V_10 ) ;
}
static int F_117 ( struct V_9 * V_10 , T_7 * V_265 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_51 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_147 )
return - V_167 ;
if ( ! ( F_31 ( V_10 , 0x5A ) & 0x01 ) ) {
* V_265 = 0 ;
F_51 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return 0 ;
}
switch ( F_31 ( V_10 , 0x52 ) & 0x0f ) {
case 0 :
* V_265 &= V_266 ;
break;
case 2 :
* V_265 &= V_267 ;
break;
case 3 :
* V_265 &= V_268 ;
break;
case 4 :
* V_265 &= V_269 ;
break;
case 6 :
* V_265 &= V_270 ;
break;
case 0xc :
* V_265 &= V_271 ;
break;
case 0xe :
* V_265 &= V_272 ;
break;
case 0xf :
* V_265 &= V_268 ;
break;
default:
* V_265 &= V_273 ;
break;
}
return 0 ;
}
static void F_118 ( struct V_9 * V_10 , struct V_274 * V_275 )
{
if ( V_275 && V_275 -> V_276 ) {
F_29 ( V_10 , 0x94 , ( V_275 -> V_277 >> 8 ) & 0xf ) ;
F_29 ( V_10 , 0x95 , V_275 -> V_277 & 0xff ) ;
F_29 ( V_10 , 0x96 , ( V_275 -> V_278 >> 8 ) & 0xf ) ;
F_29 ( V_10 , 0x97 , V_275 -> V_278 & 0xff ) ;
F_29 ( V_10 , 0x98 , ( V_275 -> V_279 >> 8 ) & 0xf ) ;
F_29 ( V_10 , 0x99 , V_275 -> V_279 & 0xff ) ;
F_29 ( V_10 , 0x9a , ( V_275 -> V_280 >> 8 ) & 0xf ) ;
F_29 ( V_10 , 0x9b , V_275 -> V_280 & 0xff ) ;
F_29 ( V_10 , 0xa8 , V_275 -> V_281 ) ;
F_29 ( V_10 , 0xa9 , V_275 -> V_282 ) ;
F_29 ( V_10 , 0xaa , V_275 -> V_283 ) ;
F_29 ( V_10 , 0xab , V_275 -> V_284 ) ;
F_29 ( V_10 , 0xac , V_275 -> V_285 ) ;
F_29 ( V_10 , 0xad , V_275 -> V_286 ) ;
F_29 ( V_10 , 0xae , V_275 -> V_287 ) ;
F_29 ( V_10 , 0xaf , V_275 -> V_288 ) ;
} else {
F_29 ( V_10 , 0x94 , 0x00 ) ;
F_29 ( V_10 , 0x95 , 0x00 ) ;
F_29 ( V_10 , 0x96 , 0x00 ) ;
F_29 ( V_10 , 0x97 , 0x20 ) ;
F_29 ( V_10 , 0x98 , 0x00 ) ;
F_29 ( V_10 , 0x99 , 0x00 ) ;
F_29 ( V_10 , 0x9a , 0x00 ) ;
F_29 ( V_10 , 0x9b , 0x00 ) ;
F_29 ( V_10 , 0xa8 , 0x04 ) ;
F_29 ( V_10 , 0xa9 , 0x04 ) ;
F_29 ( V_10 , 0xaa , 0x04 ) ;
F_29 ( V_10 , 0xab , 0x04 ) ;
F_29 ( V_10 , 0xac , 0x04 ) ;
F_29 ( V_10 , 0xad , 0x04 ) ;
F_29 ( V_10 , 0xae , 0x04 ) ;
F_29 ( V_10 , 0xaf , 0x04 ) ;
}
}
static int F_119 ( struct V_9 * V_10 , T_7 V_220 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_289 * V_290 = & V_40 -> V_290 ;
F_51 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_147 )
return - V_167 ;
if ( V_220 & V_291 )
F_118 ( V_10 , & V_290 -> V_292 ) ;
else if ( V_220 & V_221 )
F_118 ( V_10 , & V_290 -> V_293 ) ;
else
F_118 ( V_10 , NULL ) ;
if ( V_220 & V_273 ) {
V_40 -> V_220 = V_220 ;
return 0 ;
}
return - V_75 ;
}
static int F_120 ( struct V_9 * V_10 , T_7 * V_220 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_51 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_147 )
return - V_167 ;
* V_220 = V_40 -> V_220 ;
return 0 ;
}
static int F_121 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_289 * V_290 = & V_40 -> V_290 ;
F_43 ( V_10 , 0x48 ,
( V_290 -> V_294 ? 0x80 : 0 ) |
( V_290 -> V_295 ? 0x40 : 0 ) ) ;
F_96 ( V_10 ) ;
F_39 ( V_10 , 0x77 , 0xd3 , 0x20 ) ;
F_19 ( V_10 , 0x0c , 0x42 ) ;
F_19 ( V_10 , 0x15 , 0x80 ) ;
F_19 ( V_10 , 0x02 ,
0xf0 |
V_290 -> V_296 << 3 |
V_290 -> V_297 << 2 |
V_290 -> V_298 << 1 |
V_290 -> V_299 << 0 ) ;
F_19 ( V_10 , 0x03 , V_290 -> V_300 ) ;
F_20 ( V_10 , 0x04 , 0x1f , V_290 -> V_301 << 5 ) ;
F_20 ( V_10 , 0x05 , 0xf0 , V_290 -> V_302 << 3 |
V_290 -> V_303 << 2 |
V_290 -> V_304 << 1 |
V_290 -> V_305 << 0 ) ;
F_44 ( V_10 , 0x1a , 0xf1 , 0x08 ) ;
F_20 ( V_10 , 0x14 , 0xc0 ,
V_290 -> V_306 << 4 |
V_290 -> V_307 << 2 |
V_290 -> V_308 ) ;
F_47 ( V_10 , 0xba , 0xfc , V_290 -> V_309 |
( V_290 -> V_310 << 1 ) ) ;
F_33 ( V_10 , 0xdd , 0xf0 , V_290 -> V_311 |
( V_290 -> V_312 << 1 ) |
( V_290 -> V_313 << 2 ) |
( V_290 -> V_314 << 3 ) ) ;
F_46 ( V_10 , 0x69 , 0x14 ) ;
F_19 ( V_10 , 0x06 , 0xa6 ) ;
F_46 ( V_10 , 0xf3 , 0xdc ) ;
F_35 ( V_10 , 0xb5 , 0x01 ) ;
F_35 ( V_10 , 0x02 , V_290 -> V_315 ) ;
F_20 ( V_10 , 0x30 , ~ ( 1 << 4 ) , V_290 -> V_316 << 4 ) ;
F_98 ( V_10 , & V_290 -> F_98 ) ;
if ( V_290 -> V_317 >= 128 ) {
F_32 ( V_10 , 0x12 , 0x0d ) ;
if ( V_290 -> V_318 ) {
F_29 ( V_10 , 0x6f , 0x00 ) ;
F_29 ( V_10 , 0x75 , 0x0a ) ;
F_29 ( V_10 , 0x7a , 0xa5 ) ;
F_29 ( V_10 , 0x7b , 0x8f ) ;
F_29 ( V_10 , 0x60 , 0x01 ) ;
} else {
F_29 ( V_10 , 0x75 , 0x0a ) ;
F_29 ( V_10 , 0x74 , 0x00 ) ;
F_29 ( V_10 , 0x79 , 0x33 ) ;
F_29 ( V_10 , 0x6f , 0x01 ) ;
F_29 ( V_10 , 0x7a , 0xa5 ) ;
F_29 ( V_10 , 0x7b , 0x8f ) ;
F_29 ( V_10 , 0x60 , 0x01 ) ;
}
} else {
F_29 ( V_10 , 0x29 , 0x10 ) ;
}
F_99 ( V_10 , V_290 -> V_197 ) ;
F_95 ( V_10 ) ;
if ( V_290 -> V_319 ) {
F_43 ( V_10 , 0x69 , 0x5c ) ;
} else {
F_43 ( V_10 , 0x69 , 0xa3 ) ;
F_20 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
}
F_19 ( V_10 , 0x19 , 0x80 | V_290 -> V_320 ) ;
F_19 ( V_10 , 0x33 , 0x40 ) ;
F_19 ( V_10 , 0x40 , 0xf2 ) ;
F_104 ( V_10 , true ) ;
return F_122 ( V_10 -> V_321 ) ;
}
static int F_123 ( struct V_9 * V_10 )
{
int V_4 ;
int V_322 = 0 ;
int V_323 = 0 ;
int V_324 = 0 ;
F_19 ( V_10 , 0x00 , 0x01 ) ;
F_19 ( V_10 , 0x01 , 0x00 ) ;
F_35 ( V_10 , 0x80 , 0x92 ) ;
F_35 ( V_10 , 0x9B , 0x01 ) ;
F_35 ( V_10 , 0x9C , 0x60 ) ;
F_35 ( V_10 , 0x9E , 0x02 ) ;
F_35 ( V_10 , 0xA0 , 0x0B ) ;
F_35 ( V_10 , 0xC3 , 0x02 ) ;
F_19 ( V_10 , 0x0C , 0x40 ) ;
F_19 ( V_10 , 0x15 , 0xBA ) ;
F_32 ( V_10 , 0x12 , 0x00 ) ;
F_19 ( V_10 , 0xFF , 0x04 ) ;
F_52 ( 5 ) ;
F_32 ( V_10 , 0x12 , 0x00 ) ;
F_29 ( V_10 , 0x2A , 0x01 ) ;
F_29 ( V_10 , 0x7c , 0x19 ) ;
F_29 ( V_10 , 0x80 , 0x87 ) ;
F_29 ( V_10 , 0x81 , 0x4a ) ;
F_29 ( V_10 , 0x82 , 0x2c ) ;
F_29 ( V_10 , 0x83 , 0x0e ) ;
F_29 ( V_10 , 0x84 , 0x94 ) ;
F_29 ( V_10 , 0x85 , 0x62 ) ;
F_29 ( V_10 , 0x7d , 0x00 ) ;
F_29 ( V_10 , 0x7e , 0x1a ) ;
F_52 ( 5 ) ;
F_29 ( V_10 , 0xd9 , 0xd5 ) ;
F_32 ( V_10 , 0x12 , 0x05 ) ;
F_52 ( 20 ) ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
T_2 V_325 = F_28 ( V_10 , 0xdb ) ;
if ( V_325 & 0x10 ) {
V_324 ++ ;
if ( V_325 & 0x20 )
V_323 ++ ;
else
V_322 ++ ;
}
F_52 ( 20 ) ;
}
F_51 ( 1 , V_52 , V_10 ,
L_180 ,
V_324 , V_4 , V_322 , V_323 ) ;
if ( ! V_324 || V_323 )
return - V_27 ;
return 0 ;
}
static void F_124 ( struct V_9 * V_10 ,
struct V_289 * V_290 )
{
F_19 ( V_10 , 0xf1 , V_290 -> V_45 << 1 ) ;
F_19 ( V_10 , 0xf2 , V_290 -> V_44 << 1 ) ;
F_19 ( V_10 , 0xf3 , V_290 -> V_41 << 1 ) ;
F_19 ( V_10 , 0xf4 , V_290 -> V_42 << 1 ) ;
F_19 ( V_10 , 0xf5 , V_290 -> V_43 << 1 ) ;
F_19 ( V_10 , 0xf8 , V_290 -> V_46 << 1 ) ;
F_19 ( V_10 , 0xf9 , V_290 -> V_47 << 1 ) ;
F_19 ( V_10 , 0xfa , V_290 -> V_48 << 1 ) ;
F_19 ( V_10 , 0xfb , V_290 -> V_49 << 1 ) ;
F_19 ( V_10 , 0xfd , V_290 -> V_50 << 1 ) ;
F_19 ( V_10 , 0xfe , V_290 -> V_51 << 1 ) ;
}
static int F_125 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_18 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_289 * V_290 = V_16 -> V_245 . V_326 ;
struct V_1 V_89 ;
int V_28 = 0 ;
if ( ! V_290 )
return - V_327 ;
if ( ! V_290 -> V_317 || ! V_290 -> V_318 ) {
F_63 ( V_10 , L_181 ) ;
return - V_75 ;
}
F_50 ( V_10 ) ;
F_124 ( V_10 , V_290 ) ;
V_28 = F_123 ( V_10 ) ;
F_50 ( V_10 ) ;
F_124 ( V_10 , V_290 ) ;
F_121 ( V_10 ) ;
F_96 ( V_10 ) ;
F_99 ( V_10 , V_40 -> V_197 ) ;
F_95 ( V_10 ) ;
F_58 ( V_10 ) ;
F_61 ( V_10 , V_68 ) ;
F_61 ( V_10 , V_69 ) ;
V_89 = V_40 -> V_89 ;
memset ( & V_40 -> V_89 , 0 , sizeof( struct V_1 ) ) ;
F_93 ( V_10 , & V_89 ) ;
return V_28 ;
}
static long F_126 ( struct V_9 * V_10 , unsigned int V_328 , void * V_329 )
{
switch ( V_328 ) {
case V_330 :
return F_125 ( V_10 ) ;
}
return - V_331 ;
}
static void F_127 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_41 )
F_128 ( V_40 -> V_41 ) ;
if ( V_40 -> V_42 )
F_128 ( V_40 -> V_42 ) ;
if ( V_40 -> V_43 )
F_128 ( V_40 -> V_43 ) ;
if ( V_40 -> V_44 )
F_128 ( V_40 -> V_44 ) ;
if ( V_40 -> V_45 )
F_128 ( V_40 -> V_45 ) ;
if ( V_40 -> V_46 )
F_128 ( V_40 -> V_46 ) ;
if ( V_40 -> V_47 )
F_128 ( V_40 -> V_47 ) ;
if ( V_40 -> V_48 )
F_128 ( V_40 -> V_48 ) ;
if ( V_40 -> V_49 )
F_128 ( V_40 -> V_49 ) ;
if ( V_40 -> V_50 )
F_128 ( V_40 -> V_50 ) ;
if ( V_40 -> V_51 )
F_128 ( V_40 -> V_51 ) ;
V_40 -> V_41 = NULL ;
V_40 -> V_42 = NULL ;
V_40 -> V_43 = NULL ;
V_40 -> V_44 = NULL ;
V_40 -> V_45 = NULL ;
V_40 -> V_46 = NULL ;
V_40 -> V_47 = NULL ;
V_40 -> V_48 = NULL ;
V_40 -> V_49 = NULL ;
V_40 -> V_50 = NULL ;
V_40 -> V_51 = NULL ;
}
static struct V_15 * F_129 ( struct V_9 * V_10 , const char * V_247 ,
T_2 V_22 , T_2 V_332 )
{
struct V_15 * V_16 = F_18 ( V_10 ) ;
struct V_15 * V_333 ;
F_19 ( V_10 , V_332 , V_22 << 1 ) ;
if ( V_22 == 0 ) {
F_72 ( V_10 , L_182 , V_247 ) ;
return NULL ;
}
V_333 = F_130 ( V_16 -> V_21 , F_17 ( V_10 , V_332 ) >> 1 ) ;
if ( ! V_333 )
F_72 ( V_10 , L_183 , V_247 , V_22 ) ;
return V_333 ;
}
static int F_131 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_289 * V_290 = & V_40 -> V_290 ;
V_40 -> V_41 = F_129 ( V_10 , L_184 , V_290 -> V_41 , 0xf3 ) ;
V_40 -> V_42 = F_129 ( V_10 , L_185 , V_290 -> V_42 , 0xf4 ) ;
V_40 -> V_43 = F_129 ( V_10 , L_186 , V_290 -> V_43 , 0xf5 ) ;
V_40 -> V_44 = F_129 ( V_10 , L_187 , V_290 -> V_44 , 0xf2 ) ;
V_40 -> V_45 = F_129 ( V_10 , L_188 , V_290 -> V_45 , 0xf1 ) ;
V_40 -> V_46 = F_129 ( V_10 , L_189 , V_290 -> V_46 , 0xf8 ) ;
V_40 -> V_47 = F_129 ( V_10 , L_190 , V_290 -> V_47 , 0xf9 ) ;
V_40 -> V_48 = F_129 ( V_10 , L_191 , V_290 -> V_48 , 0xfa ) ;
V_40 -> V_49 = F_129 ( V_10 , L_192 , V_290 -> V_49 , 0xfb ) ;
V_40 -> V_50 = F_129 ( V_10 , L_193 , V_290 -> V_50 , 0xfd ) ;
V_40 -> V_51 = F_129 ( V_10 , L_194 , V_290 -> V_51 , 0xfe ) ;
if ( ! V_40 -> V_41 ||
! V_40 -> V_42 ||
! V_40 -> V_43 ||
! V_40 -> V_44 ||
! V_40 -> V_45 ||
! V_40 -> V_46 ||
! V_40 -> V_47 ||
! V_40 -> V_48 ||
! V_40 -> V_49 ||
! V_40 -> V_50 ||
! V_40 -> V_51 )
return - 1 ;
return 0 ;
}
static int F_132 ( struct V_15 * V_16 ,
const struct V_334 * V_130 )
{
struct V_8 * V_40 ;
static const struct V_1 V_335 =
V_336 ;
struct V_289 * V_290 = V_16 -> V_245 . V_326 ;
struct V_337 * V_3 ;
struct V_9 * V_10 ;
T_4 V_338 ;
int V_30 ;
if ( ! F_133 ( V_16 -> V_21 , V_339 ) )
return - V_27 ;
F_134 ( 1 , V_52 , V_16 , L_195 ,
V_16 -> V_22 << 1 ) ;
if ( ! V_290 ) {
F_12 ( V_16 , L_196 ) ;
return - V_327 ;
}
V_40 = F_135 ( & V_16 -> V_245 , sizeof( struct V_8 ) , V_340 ) ;
if ( ! V_40 ) {
F_12 ( V_16 , L_197 ) ;
return - V_341 ;
}
V_40 -> V_290 = * V_290 ;
V_40 -> V_89 = V_335 ;
V_10 = & V_40 -> V_10 ;
F_136 ( V_10 , V_16 , & V_342 ) ;
V_10 -> V_23 |= V_343 ;
V_40 -> V_54 = V_290 -> V_54 ;
V_40 -> V_199 = V_290 -> V_200 == V_203 ;
V_40 -> V_168 = true ;
V_338 = F_10 ( V_16 , 0xea , false ) << 8 |
F_10 ( V_16 , 0xeb , false ) ;
if ( V_338 != 0x2012 ) {
F_63 ( V_10 , L_198 , V_338 ) ;
V_338 = F_10 ( V_16 , 0xea , false ) << 8 |
F_10 ( V_16 , 0xeb , false ) ;
}
if ( V_338 != 0x2012 ) {
F_63 ( V_10 , L_199 ,
V_16 -> V_22 << 1 , V_338 ) ;
return - V_327 ;
}
if ( V_290 -> V_344 )
F_50 ( V_10 ) ;
V_3 = & V_40 -> V_3 ;
F_137 ( V_3 , 6 ) ;
F_138 ( V_3 , & V_345 ,
V_131 , - 128 , 127 , 1 , 0 ) ;
F_138 ( V_3 , & V_345 ,
V_132 , 0 , 255 , 1 , 128 ) ;
F_138 ( V_3 , & V_345 ,
V_133 , 0 , 255 , 1 , 128 ) ;
F_138 ( V_3 , & V_345 ,
V_134 , 0 , 128 , 1 , 0 ) ;
V_40 -> V_84 = F_138 ( V_3 , NULL ,
V_346 , 0 , 3 , 0 , 0 ) ;
V_40 -> V_347 = F_139 ( V_3 ,
& V_348 , NULL ) ;
V_40 -> V_349 = F_139 ( V_3 ,
& V_350 , NULL ) ;
V_40 -> V_351 = F_139 ( V_3 ,
& V_352 , NULL ) ;
V_40 -> V_353 =
F_140 ( V_3 , & V_345 ,
V_144 , V_129 ,
0 , V_126 ) ;
V_10 -> V_321 = V_3 ;
if ( V_3 -> error ) {
V_30 = V_3 -> error ;
goto V_354;
}
V_40 -> V_84 -> V_355 = true ;
V_40 -> V_353 -> V_355 = true ;
V_40 -> V_347 -> V_355 = true ;
V_40 -> V_349 -> V_355 = true ;
V_40 -> V_351 -> V_355 = true ;
if ( F_66 ( V_10 ) ) {
V_30 = - V_327 ;
goto V_354;
}
if ( F_131 ( V_10 ) < 0 ) {
V_30 = - V_341 ;
F_72 ( V_10 , L_200 ) ;
goto V_356;
}
V_40 -> V_72 = F_141 ( V_16 -> V_179 ) ;
if ( ! V_40 -> V_72 ) {
F_72 ( V_10 , L_201 ) ;
V_30 = - V_341 ;
goto V_356;
}
F_142 ( & V_40 -> V_65 ,
F_56 ) ;
V_40 -> V_165 . V_23 = V_357 ;
V_30 = F_143 ( & V_10 -> V_358 , 1 , & V_40 -> V_165 , 0 ) ;
if ( V_30 )
goto V_359;
V_30 = F_121 ( V_10 ) ;
if ( V_30 )
goto V_360;
F_63 ( V_10 , L_202 , V_16 -> V_179 ,
V_16 -> V_22 << 1 , V_16 -> V_21 -> V_179 ) ;
return 0 ;
V_360:
F_144 ( & V_10 -> V_358 ) ;
V_359:
F_145 ( & V_40 -> V_65 ) ;
F_146 ( V_40 -> V_72 ) ;
V_356:
F_127 ( V_10 ) ;
V_354:
F_147 ( V_3 ) ;
return V_30 ;
}
static int F_148 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = F_149 ( V_16 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_104 ( V_10 , false ) ;
F_145 ( & V_40 -> V_65 ) ;
F_146 ( V_40 -> V_72 ) ;
F_150 ( V_10 ) ;
F_144 ( & V_10 -> V_358 ) ;
F_127 ( V_10 ) ;
F_147 ( V_10 -> V_321 ) ;
return 0 ;
}
