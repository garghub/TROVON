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
static inline unsigned F_10 ( const struct V_14 * V_2 )
{
return F_11 ( V_2 ) ;
}
static inline unsigned F_12 ( const struct V_14 * V_2 )
{
return F_13 ( V_2 ) ;
}
static T_1 F_14 ( struct V_15 * V_16 ,
T_2 V_17 , bool V_18 )
{
union V_19 V_20 ;
if ( ! F_15 ( V_16 -> V_21 , V_16 -> V_22 , V_16 -> V_23 ,
V_24 , V_17 ,
V_25 , & V_20 ) )
return V_20 . V_26 ;
if ( V_18 )
F_16 ( V_16 , L_1 ,
V_16 -> V_22 , V_17 ) ;
return - V_27 ;
}
static T_1 F_17 ( struct V_15 * V_16 , T_2 V_17 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
int V_28 = F_14 ( V_16 , V_17 , true ) ;
if ( V_28 >= 0 ) {
if ( V_4 )
F_16 ( V_16 , L_2 , V_4 ) ;
return V_28 ;
}
}
F_16 ( V_16 , L_3 ) ;
return - V_27 ;
}
static T_1 F_18 ( struct V_15 * V_16 ,
T_2 V_17 , T_2 V_29 )
{
union V_19 V_20 ;
int V_30 ;
int V_4 ;
V_20 . V_26 = V_29 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
V_30 = F_15 ( V_16 -> V_21 , V_16 -> V_22 ,
V_16 -> V_23 ,
V_31 , V_17 ,
V_25 , & V_20 ) ;
if ( ! V_30 )
break;
}
if ( V_30 < 0 )
F_16 ( V_16 , L_4 ,
V_16 -> V_22 , V_17 , V_29 ) ;
return V_30 ;
}
static void F_19 ( struct V_15 * V_16 ,
T_2 V_17 , T_2 V_29 )
{
union V_19 V_20 ;
V_20 . V_26 = V_29 ;
F_15 ( V_16 -> V_21 , V_16 -> V_22 ,
V_16 -> V_23 ,
V_31 , V_17 ,
V_25 , & V_20 ) ;
}
static T_1 F_20 ( struct V_15 * V_16 ,
T_2 V_17 , unsigned V_32 , const T_2 * V_33 )
{
union V_19 V_20 ;
if ( V_32 > V_34 )
V_32 = V_34 ;
V_20 . V_35 [ 0 ] = V_32 ;
memcpy ( V_20 . V_35 + 1 , V_33 , V_32 ) ;
return F_15 ( V_16 -> V_21 , V_16 -> V_22 , V_16 -> V_23 ,
V_31 , V_17 ,
V_36 , & V_20 ) ;
}
static inline int F_21 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
return F_17 ( V_16 , V_37 ) ;
}
static inline int F_23 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
return F_18 ( V_16 , V_37 , V_38 ) ;
}
static inline int F_24 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_23 ( V_10 , V_37 , ( F_21 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_25 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_41 , V_37 ) ;
}
static inline int F_26 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_41 , V_37 , V_38 ) ;
}
static inline int F_27 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_42 , V_37 ) ;
}
static inline int F_28 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_42 , V_37 , V_38 ) ;
}
static inline int F_29 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_28 ( V_10 , V_37 , ( F_27 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_30 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_43 , V_37 ) ;
}
static inline int F_31 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_43 , V_37 , V_38 ) ;
}
static inline int F_32 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_44 , V_37 ) ;
}
static inline int F_33 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_44 , V_37 , V_38 ) ;
}
static inline int F_34 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_33 ( V_10 , V_37 , ( F_32 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_35 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_45 , V_37 ) ;
}
static inline int F_36 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_45 , V_37 , V_38 ) ;
}
static inline int F_37 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_36 ( V_10 , V_37 , ( F_35 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_38 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_46 , V_37 ) ;
}
static inline int F_39 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_46 , V_37 , V_38 ) ;
}
static inline int F_40 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_39 ( V_10 , V_37 , ( F_38 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_41 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_47 , V_37 ) ;
}
static inline int F_42 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_47 , V_37 , V_38 ) ;
}
static inline int F_43 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_42 ( V_10 , V_37 , ( F_41 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_44 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_48 , V_37 ) ;
}
static inline int F_45 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_48 , V_37 , V_38 ) ;
}
static inline int F_46 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_49 , V_37 ) ;
}
static inline int F_47 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_49 , V_37 , V_38 ) ;
}
static inline int F_48 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_47 ( V_10 , V_37 , ( F_46 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_49 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_50 , V_37 ) ;
}
static inline int F_50 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_50 , V_37 , V_38 ) ;
}
static inline int F_51 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_50 ( V_10 , V_37 , ( F_49 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_52 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_51 , V_37 ) ;
}
static inline int F_53 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_51 , V_37 , V_38 ) ;
}
static void F_54 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
F_19 ( V_16 , 0xff , 0x80 ) ;
F_56 ( 5 ) ;
}
static inline bool F_57 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return ( ( V_40 -> V_54 == V_55 ) ||
( V_40 -> V_54 == V_56 ) ) ;
}
static inline bool F_58 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return V_40 -> V_54 == V_57 ;
}
static inline const struct V_58 *
F_59 ( struct V_9 * V_10 )
{
return F_58 ( V_10 ) ? & V_59 :
& V_60 ;
}
static void F_60 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_61 ( V_62 ) ;
struct V_8 * V_40 = F_4 ( V_64 ,
struct V_8 , V_65 ) ;
struct V_9 * V_10 = & V_40 -> V_10 ;
int V_66 = V_40 -> V_67 . V_66 ;
T_2 V_39 = 0 ;
F_55 ( 2 , V_52 , V_10 , L_6 ,
V_53 , V_66 ) ;
if ( V_66 & ( 0x04 << V_68 ) )
V_39 |= 0x20 ;
if ( V_66 & ( 0x04 << V_69 ) )
V_39 |= 0x10 ;
F_24 ( V_10 , 0x20 , 0xcf , V_39 ) ;
}
static int F_62 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_70 . V_71 ;
int V_30 = 0 ;
int V_4 ;
F_55 ( 2 , V_52 , V_10 , L_7 , V_53 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_43 ( V_10 , 0x7f , 0x7f , 0x00 ) ;
F_43 ( V_10 , 0x77 , 0xef , 0x10 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_20 ( V_40 -> V_48 , V_4 ,
V_34 , V_38 + V_4 ) ;
if ( V_30 )
return V_30 ;
F_43 ( V_10 , 0x7f , 0x7f , 0x80 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_41 ( V_10 , 0x79 ) & 0x20 )
break;
F_56 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_16 ( V_16 , L_8 ) ;
return - V_27 ;
}
F_63 ( V_40 -> V_72 ,
& V_40 -> V_65 , V_73 / 5 ) ;
return 0 ;
}
static int F_64 ( const T_2 * V_71 )
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
static int F_65 ( struct V_9 * V_10 , T_2 V_79 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_67 . V_71 ;
int V_80 = F_64 ( V_38 ) ;
int V_30 = 0 ;
int V_4 ;
F_55 ( 2 , V_52 , V_10 , L_9 ,
V_53 , ( V_79 == V_68 ) ? 'A' : 'B' , V_80 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_43 ( V_10 , 0x77 , 0xf3 , 0x00 ) ;
if ( ! V_40 -> V_67 . V_66 )
return 0 ;
F_43 ( V_10 , 0x77 , 0xef , 0x00 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_20 ( V_40 -> V_48 , V_4 ,
V_34 , V_38 + V_4 ) ;
if ( V_30 )
return V_30 ;
if ( V_80 < 0 )
V_80 = 0xc0 ;
if ( V_79 == V_68 ) {
F_42 ( V_10 , 0x72 , V_38 [ V_80 ] ) ;
F_42 ( V_10 , 0x73 , V_38 [ V_80 + 1 ] ) ;
} else {
F_42 ( V_10 , 0x74 , V_38 [ V_80 ] ) ;
F_42 ( V_10 , 0x75 , V_38 [ V_80 + 1 ] ) ;
}
F_42 ( V_10 , 0x76 , V_80 & 0xff ) ;
F_43 ( V_10 , 0x77 , 0xbf , ( V_80 >> 2 ) & 0x40 ) ;
F_43 ( V_10 , 0x77 , 0xf3 , V_40 -> V_67 . V_66 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_41 ( V_10 , 0x7d ) & V_40 -> V_67 . V_66 )
break;
F_56 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_16 ( V_16 , L_10 ,
( V_79 == V_68 ) ? 'A' : 'B' ) ;
return - V_27 ;
}
F_63 ( V_40 -> V_72 ,
& V_40 -> V_65 , V_73 / 5 ) ;
return 0 ;
}
static void F_66 ( struct V_9 * V_10 )
{
F_67 ( V_10 , L_11 ) ;
F_67 ( V_10 , L_12 ) ;
F_67 ( V_10 , L_13 ) ;
F_67 ( V_10 , L_14 ) ;
F_67 ( V_10 , L_15 ) ;
F_67 ( V_10 , L_16 ) ;
F_67 ( V_10 , L_17 ) ;
F_67 ( V_10 , L_18 ) ;
F_67 ( V_10 , L_19 ) ;
F_67 ( V_10 , L_20 ) ;
F_67 ( V_10 , L_21 ) ;
F_67 ( V_10 , L_22 ) ;
}
static int F_68 ( struct V_9 * V_10 ,
struct V_81 * V_37 )
{
V_37 -> V_82 = 1 ;
switch ( V_37 -> V_37 >> 8 ) {
case 0 :
V_37 -> V_38 = F_21 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 1 :
V_37 -> V_38 = F_25 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 2 :
V_37 -> V_38 = F_27 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 3 :
V_37 -> V_38 = F_30 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 4 :
V_37 -> V_38 = F_32 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 5 :
V_37 -> V_38 = F_35 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 6 :
V_37 -> V_38 = F_38 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 7 :
V_37 -> V_38 = F_41 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 8 :
V_37 -> V_38 = F_44 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 9 :
V_37 -> V_38 = F_46 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 0xa :
V_37 -> V_38 = F_49 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 0xb :
V_37 -> V_38 = F_52 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
default:
F_67 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_66 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_69 ( struct V_9 * V_10 ,
const struct V_81 * V_37 )
{
T_2 V_38 = V_37 -> V_38 & 0xff ;
switch ( V_37 -> V_37 >> 8 ) {
case 0 :
F_23 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 1 :
F_26 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 2 :
F_28 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 3 :
F_31 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 4 :
F_33 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 5 :
F_36 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 6 :
F_39 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 7 :
F_42 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 8 :
F_45 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 9 :
F_47 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 0xa :
F_50 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 0xb :
F_53 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
default:
F_67 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_66 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_70 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_83 = F_71 ( V_40 -> V_84 ) ;
T_2 V_85 = F_21 ( V_10 , 0x6f ) ;
int V_38 = 0 ;
if ( V_85 & 0x02 )
V_38 |= 1 ;
if ( V_85 & 0x01 )
V_38 |= 2 ;
F_55 ( 1 , V_52 , V_10 , L_24 , V_53 , V_83 , V_38 ) ;
if ( V_38 != V_83 )
return F_72 ( V_40 -> V_84 , V_38 ) ;
return 0 ;
}
static int F_73 ( struct V_9 * V_10 ,
T_2 V_86 ,
const struct V_87 * V_88 ,
const struct V_1 * V_89 )
{
int V_4 ;
for ( V_4 = 0 ; V_88 [ V_4 ] . V_89 . V_6 . V_7 ; V_4 ++ ) {
if ( ! F_2 ( V_89 , & V_88 [ V_4 ] . V_89 ,
F_58 ( V_10 ) ? 250000 : 1000000 ) )
continue;
F_23 ( V_10 , 0x00 , V_88 [ V_4 ] . V_90 ) ;
F_23 ( V_10 , 0x01 , ( V_88 [ V_4 ] . V_91 << 4 ) + V_86 ) ;
return 0 ;
}
return - 1 ;
}
static int F_74 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 ;
F_55 ( 1 , V_52 , V_10 , L_25 , V_53 ) ;
F_23 ( V_10 , 0x16 , 0x43 ) ;
F_23 ( V_10 , 0x17 , 0x5a ) ;
F_51 ( V_10 , 0x81 , 0xef , 0x00 ) ;
F_50 ( V_10 , 0x26 , 0x00 ) ;
F_50 ( V_10 , 0x27 , 0x00 ) ;
F_50 ( V_10 , 0x28 , 0x00 ) ;
F_50 ( V_10 , 0x29 , 0x00 ) ;
F_50 ( V_10 , 0x8f , 0x40 ) ;
F_50 ( V_10 , 0x90 , 0x00 ) ;
F_50 ( V_10 , 0xa5 , 0x00 ) ;
F_50 ( V_10 , 0xa6 , 0x00 ) ;
F_50 ( V_10 , 0xa7 , 0x00 ) ;
F_50 ( V_10 , 0xab , 0x00 ) ;
F_50 ( V_10 , 0xac , 0x00 ) ;
switch ( V_40 -> V_54 ) {
case V_56 :
case V_55 :
V_30 = F_73 ( V_10 ,
0x01 , V_92 , V_89 ) ;
if ( V_30 )
V_30 = F_73 ( V_10 ,
0x02 , V_93 , V_89 ) ;
break;
case V_57 :
V_30 = F_73 ( V_10 ,
0x05 , V_94 , V_89 ) ;
if ( V_30 )
V_30 = F_73 ( V_10 ,
0x06 , V_95 , V_89 ) ;
break;
default:
F_55 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
V_30 = - 1 ;
break;
}
return V_30 ;
}
static void F_75 ( struct V_9 * V_10 ,
const struct V_14 * V_6 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_15 * V_16 = F_22 ( V_10 ) ;
T_3 V_7 = F_8 ( V_6 ) ;
T_3 V_96 = F_12 ( V_6 ) ;
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
F_55 ( 2 , V_52 , V_10 , L_25 , V_53 ) ;
switch ( V_40 -> V_54 ) {
case V_56 :
case V_55 :
F_23 ( V_10 , 0x00 , 0x07 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_51 ( V_10 , 0x81 , 0xef , 0x10 ) ;
if ( F_20 ( V_16 , 0x16 , 2 , V_110 ) ) {
F_76 ( V_10 , L_27 ) ;
break;
}
F_50 ( V_10 , 0x26 , ( V_97 >> 8 ) & 0xf ) ;
F_50 ( V_10 , 0x27 , ( V_97 & 0xff ) ) ;
F_50 ( V_10 , 0x28 , ( V_100 >> 8 ) & 0xf ) ;
F_50 ( V_10 , 0x29 , ( V_100 & 0xff ) ) ;
F_50 ( V_10 , 0xa5 , ( V_102 >> 4 ) & 0xff ) ;
F_50 ( V_10 , 0xa6 , ( ( V_102 & 0xf ) << 4 ) |
( ( V_104 >> 8 ) & 0xf ) ) ;
F_50 ( V_10 , 0xa7 , V_104 & 0xff ) ;
break;
case V_57 :
F_23 ( V_10 , 0x00 , 0x02 ) ;
F_23 ( V_10 , 0x01 , 0x06 ) ;
break;
default:
F_55 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
F_50 ( V_10 , 0x8f , ( V_107 >> 8 ) & 0x7 ) ;
F_50 ( V_10 , 0x90 , V_107 & 0xff ) ;
F_50 ( V_10 , 0xab , ( V_96 >> 4 ) & 0xff ) ;
F_50 ( V_10 , 0xac , ( V_96 & 0x0f ) << 4 ) ;
}
static void F_77 ( struct V_9 * V_10 , bool V_111 , T_4 V_112 , T_4 V_113 , T_4 V_114 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_115 [ 4 ] ;
if ( V_111 ) {
V_112 = 0x3ff ;
V_113 = 0x3ff ;
V_114 = 0x3ff ;
}
F_55 ( 2 , V_52 , V_10 , L_28 ,
V_53 , V_111 ? L_29 : L_30 ,
V_112 , V_113 , V_114 ) ;
V_115 [ 0 ] = ( F_49 ( V_10 , 0x77 ) & 0xc0 ) | ( ( V_112 & 0x3f0 ) >> 4 ) ;
V_115 [ 1 ] = ( ( V_112 & 0x00f ) << 4 ) | ( ( V_113 & 0x3c0 ) >> 6 ) ;
V_115 [ 2 ] = ( ( V_113 & 0x03f ) << 2 ) | ( ( V_114 & 0x300 ) >> 8 ) ;
V_115 [ 3 ] = V_114 & 0x0ff ;
if ( F_20 ( V_40 -> V_50 , 0x77 , 4 , V_115 ) )
F_76 ( V_10 , L_31 , V_53 ) ;
}
static void F_78 ( struct V_9 * V_10 , bool V_116 , T_4 V_117 , T_4 V_118 , T_4 V_119 )
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
F_55 ( 2 , V_52 , V_10 , L_32 ,
V_53 , V_116 ? L_29 : L_30 ,
V_117 , V_118 , V_119 ) ;
V_120 [ 0 ] = ( ( V_121 << 7 ) | ( V_122 << 6 ) | ( ( V_117 & 0x3f0 ) >> 4 ) ) ;
V_120 [ 1 ] = ( ( ( V_117 & 0x00f ) << 4 ) | ( ( V_118 & 0x3c0 ) >> 6 ) ) ;
V_120 [ 2 ] = ( ( ( V_118 & 0x03f ) << 2 ) | ( ( V_119 & 0x300 ) >> 8 ) ) ;
V_120 [ 3 ] = ( ( V_119 & 0x0ff ) ) ;
if ( F_20 ( V_40 -> V_50 , 0x73 , 4 , V_120 ) )
F_76 ( V_10 , L_33 , V_53 ) ;
}
static void F_79 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
bool V_123 = F_21 ( V_10 , 0x02 ) & 0x02 ;
bool V_124 = F_46 ( V_10 , 0x05 ) & 0x80 ;
F_55 ( 2 , V_52 , V_10 , L_34 ,
V_53 , V_40 -> V_125 ,
V_123 , V_124 ) ;
F_78 ( V_10 , true , 0x0 , 0x0 , 0x0 ) ;
F_77 ( V_10 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_40 -> V_125 ) {
case V_126 :
if ( V_40 -> V_54 == V_55 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
break;
}
if ( V_40 -> V_54 == V_56 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_124 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_40 -> V_89 . V_6 . V_127 & V_128 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
if ( F_58 ( V_10 ) && V_123 ) {
F_77 ( V_10 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_78 ( V_10 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_77 ( V_10 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_129 :
if ( V_40 -> V_54 == V_56 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x20 ) ;
break;
}
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_130 :
if ( V_40 -> V_54 == V_56 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x60 ) ;
break;
}
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
if ( F_57 ( V_10 ) || V_124 )
break;
if ( V_123 ) {
F_77 ( V_10 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_78 ( V_10 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_77 ( V_10 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_80 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_12 -> V_131 ) {
case V_132 :
F_50 ( V_10 , 0x3c , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x14 , V_12 -> V_38 ) ;
return 0 ;
case V_133 :
F_50 ( V_10 , 0x3a , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x13 , V_12 -> V_38 ) ;
return 0 ;
case V_134 :
F_50 ( V_10 , 0x3b , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x15 , V_12 -> V_38 ) ;
return 0 ;
case V_135 :
F_50 ( V_10 , 0x3d , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x16 , V_12 -> V_38 ) ;
return 0 ;
case V_136 :
F_39 ( V_10 , 0xc8 , V_12 -> V_38 ) ;
return 0 ;
case V_137 :
F_51 ( V_10 , 0xbf , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
F_37 ( V_10 , 0xdd , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
return 0 ;
case V_138 : {
T_2 V_139 = ( V_12 -> V_38 & 0xff0000 ) >> 16 ;
T_2 V_140 = ( V_12 -> V_38 & 0x00ff00 ) >> 8 ;
T_2 V_141 = ( V_12 -> V_38 & 0x0000ff ) ;
int V_142 = 66 * V_139 + 129 * V_140 + 25 * V_141 ;
int V_143 = - 38 * V_139 - 74 * V_140 + 112 * V_141 ;
int V_144 = 112 * V_139 - 94 * V_140 - 18 * V_141 ;
V_142 = ( V_142 + 128 ) >> 8 ;
V_143 = ( V_143 + 128 ) >> 8 ;
V_144 = ( V_144 + 128 ) >> 8 ;
V_142 += 16 ;
V_143 += 128 ;
V_144 += 128 ;
F_55 ( 1 , V_52 , V_10 , L_35 , V_139 , V_140 , V_141 ) ;
F_55 ( 1 , V_52 , V_10 , L_36 , V_142 , V_143 , V_144 ) ;
F_50 ( V_10 , 0xc1 , V_139 ) ;
F_50 ( V_10 , 0xc0 , V_140 ) ;
F_50 ( V_10 , 0xc2 , V_141 ) ;
F_36 ( V_10 , 0xde , V_142 ) ;
F_36 ( V_10 , 0xdf , ( V_144 & 0xf0 ) | ( ( V_143 >> 4 ) & 0x0f ) ) ;
return 0 ;
}
case V_145 :
V_40 -> V_125 = V_12 -> V_38 ;
F_79 ( V_10 ) ;
return 0 ;
}
return - V_75 ;
}
static inline bool F_81 ( struct V_9 * V_10 )
{
return F_21 ( V_10 , 0x0c ) & 0x24 ;
}
static inline bool F_82 ( struct V_9 * V_10 )
{
return ( ( F_49 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ) || ! ( F_49 ( V_10 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_83 ( struct V_9 * V_10 )
{
return F_46 ( V_10 , 0x05 ) & 0x80 ;
}
static int F_84 ( struct V_9 * V_10 , T_3 * V_146 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
* V_146 = 0 ;
if ( F_21 ( V_10 , 0x0c ) & 0x24 )
* V_146 |= V_147 ;
if ( V_40 -> V_54 == V_148 ) {
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) )
* V_146 |= V_149 ;
F_55 ( 1 , V_52 , V_10 , L_37 ,
V_53 , * V_146 ) ;
return 0 ;
}
if ( ( F_49 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ||
! ( F_49 ( V_10 , 0xb1 ) & 0x80 ) )
* V_146 |= V_149 ;
if ( F_58 ( V_10 ) && ( ( F_21 ( V_10 , 0x74 ) & 0x03 ) != 0x03 ) )
* V_146 |= V_149 ;
F_55 ( 1 , V_52 , V_10 , L_38 ,
V_53 , * V_146 ) ;
return 0 ;
}
static int F_85 ( struct V_9 * V_10 ,
struct V_150 * V_151 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_3 V_152 = ( V_109 * 8 ) / V_151 -> V_153 ;
T_3 V_154 ;
int V_4 ;
for ( V_4 = 0 ; V_155 [ V_4 ] . V_6 . V_7 ; V_4 ++ ) {
const struct V_14 * V_6 = & V_155 [ V_4 ] . V_6 ;
if ( ! F_86 ( & V_155 [ V_4 ] ,
F_59 ( V_10 ) ,
F_1 , NULL ) )
continue;
if ( F_12 ( V_6 ) != V_151 -> V_156 + 1 )
continue;
if ( V_6 -> V_105 != V_151 -> V_157 )
continue;
V_154 = V_152 * F_8 ( V_6 ) ;
if ( ( V_154 < V_6 -> V_108 + 1000000 ) &&
( V_154 > V_6 -> V_108 - 1000000 ) ) {
* V_89 = V_155 [ V_4 ] ;
return 0 ;
}
}
if ( F_87 ( V_151 -> V_156 + 1 , V_152 , V_151 -> V_157 ,
( V_151 -> V_158 == '+' ? V_159 : 0 ) |
( V_151 -> V_160 == '+' ? V_161 : 0 ) ,
V_89 ) )
return 0 ;
if ( F_88 ( V_151 -> V_156 + 1 , V_152 , V_151 -> V_157 ,
( V_151 -> V_158 == '+' ? V_159 : 0 ) |
( V_151 -> V_160 == '+' ? V_161 : 0 ) ,
V_40 -> V_162 , V_89 ) )
return 0 ;
F_55 ( 2 , V_52 , V_10 ,
L_39 ,
V_53 , V_151 -> V_157 , V_151 -> V_156 , V_151 -> V_153 ,
V_151 -> V_158 , V_151 -> V_160 ) ;
return - 1 ;
}
static int F_89 ( struct V_9 * V_10 , struct V_150 * V_151 )
{
T_3 V_146 ;
F_84 ( V_10 , & V_146 ) ;
if ( V_146 & V_149 ) {
F_55 ( 2 , V_52 , V_10 , L_40 , V_53 ) ;
return - V_163 ;
}
V_151 -> V_153 = ( ( F_49 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_49 ( V_10 , 0xb2 ) ;
V_151 -> V_156 = ( ( F_49 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_49 ( V_10 , 0xb4 ) ;
V_151 -> V_157 = F_49 ( V_10 , 0xb3 ) >> 3 ;
if ( ( F_49 ( V_10 , 0xb5 ) & 0x80 ) && ( ( F_49 ( V_10 , 0xb5 ) & 0x03 ) == 0x01 ) ) {
V_151 -> V_158 = ( ( F_49 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_49 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_151 -> V_160 = ( ( F_49 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_49 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_151 -> V_158 = 'x' ;
V_151 -> V_160 = 'x' ;
}
V_151 -> V_164 = ( F_49 ( V_10 , 0xb1 ) & 0x40 ) ? true : false ;
if ( V_151 -> V_156 < 239 || V_151 -> V_153 < 8 || V_151 -> V_153 == 0x3fff ) {
F_55 ( 2 , V_52 , V_10 , L_41 , V_53 ) ;
return - V_163 ;
}
F_55 ( 2 , V_52 , V_10 ,
L_42 ,
V_53 , V_151 -> V_156 , V_151 -> V_153 , V_151 -> V_157 ,
V_151 -> V_158 , V_151 -> V_160 ,
V_151 -> V_164 ? L_43 : L_44 ) ;
return 0 ;
}
static int F_90 ( struct V_9 * V_10 ,
struct V_165 * V_89 )
{
if ( V_89 -> V_166 != 0 )
return - V_75 ;
return F_91 ( V_89 ,
F_59 ( V_10 ) , F_1 , NULL ) ;
}
static int F_92 ( struct V_9 * V_10 ,
struct V_58 * V_167 )
{
if ( V_167 -> V_166 != 0 )
return - V_75 ;
* V_167 = * F_59 ( V_10 ) ;
return 0 ;
}
static void F_93 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
F_94 ( V_89 , F_59 ( V_10 ) ,
F_58 ( V_10 ) ? 250000 : 1000000 ,
F_1 , NULL ) ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 = & V_89 -> V_6 ;
struct V_150 V_151 = { 0 } ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
memset ( V_89 , 0 , sizeof( struct V_1 ) ) ;
if ( V_40 -> V_54 == V_148 )
return - V_168 ;
if ( F_89 ( V_10 , & V_151 ) ) {
V_40 -> V_169 = true ;
F_55 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return - V_163 ;
}
V_6 -> V_164 = V_151 . V_164 ?
V_170 : V_171 ;
if ( F_58 ( V_10 ) ) {
T_5 V_172 ;
V_89 -> type = V_173 ;
V_6 -> V_7 = ( F_46 ( V_10 , 0x07 ) & 0x0f ) * 256 + F_46 ( V_10 , 0x08 ) ;
V_6 -> V_96 = ( F_46 ( V_10 , 0x09 ) & 0x0f ) * 256 + F_46 ( V_10 , 0x0a ) ;
V_172 = ( ( F_46 ( V_10 , 0x51 ) << 1 ) + ( F_46 ( V_10 , 0x52 ) >> 7 ) ) * 1000000 ;
V_172 += ( ( F_46 ( V_10 , 0x52 ) & 0x7f ) * 7813 ) ;
if ( F_83 ( V_10 ) ) {
V_172 = V_172 * 8 / ( ( ( F_46 ( V_10 , 0x0b ) & 0xc0 ) >> 6 ) * 2 + 8 ) ;
}
V_6 -> V_108 = V_172 ;
V_6 -> V_101 = ( F_46 ( V_10 , 0x20 ) & 0x03 ) * 256 +
F_46 ( V_10 , 0x21 ) ;
V_6 -> V_98 = ( F_46 ( V_10 , 0x22 ) & 0x03 ) * 256 +
F_46 ( V_10 , 0x23 ) ;
V_6 -> V_99 = ( F_46 ( V_10 , 0x24 ) & 0x03 ) * 256 +
F_46 ( V_10 , 0x25 ) ;
V_6 -> V_103 = ( ( F_46 ( V_10 , 0x2a ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x2b ) ) / 2 ;
V_6 -> V_105 = ( ( F_46 ( V_10 , 0x2e ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x2f ) ) / 2 ;
V_6 -> V_106 = ( ( F_46 ( V_10 , 0x32 ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x33 ) ) / 2 ;
V_6 -> V_174 = ( ( F_46 ( V_10 , 0x05 ) & 0x10 ) ? V_161 : 0 ) |
( ( F_46 ( V_10 , 0x05 ) & 0x20 ) ? V_159 : 0 ) ;
if ( V_6 -> V_164 == V_170 ) {
V_6 -> V_96 += ( F_46 ( V_10 , 0x0b ) & 0x0f ) * 256 +
F_46 ( V_10 , 0x0c ) ;
V_6 -> V_175 = ( ( F_46 ( V_10 , 0x2c ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x2d ) ) / 2 ;
V_6 -> V_176 = ( ( F_46 ( V_10 , 0x30 ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x31 ) ) / 2 ;
V_6 -> V_177 = ( ( F_46 ( V_10 , 0x34 ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x35 ) ) / 2 ;
}
F_93 ( V_10 , V_89 ) ;
} else {
if ( ! F_85 ( V_10 , & V_151 , V_89 ) )
goto V_178;
V_151 . V_157 += 1 ;
F_55 ( 1 , V_52 , V_10 , L_46 , V_53 , V_151 . V_157 ) ;
if ( ! F_85 ( V_10 , & V_151 , V_89 ) )
goto V_178;
V_151 . V_157 -= 2 ;
F_55 ( 1 , V_52 , V_10 , L_47 , V_53 , V_151 . V_157 ) ;
if ( F_85 ( V_10 , & V_151 , V_89 ) ) {
if ( V_40 -> V_169 ) {
F_55 ( 1 , V_52 , V_10 , L_48 , V_53 ) ;
F_51 ( V_10 , 0x86 , 0xf9 , 0x00 ) ;
F_51 ( V_10 , 0x86 , 0xf9 , 0x04 ) ;
F_51 ( V_10 , 0x86 , 0xf9 , 0x02 ) ;
V_40 -> V_169 = false ;
return - V_163 ;
}
F_55 ( 1 , V_52 , V_10 , L_49 , V_53 ) ;
return - V_179 ;
}
V_40 -> V_169 = true ;
}
V_178:
if ( V_52 > 1 )
F_96 ( V_10 -> V_180 , L_50 ,
V_89 , true ) ;
return 0 ;
}
static int F_97 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 ;
int V_30 ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 == V_148 )
return - V_168 ;
if ( F_2 ( & V_40 -> V_89 , V_89 , 0 ) ) {
F_55 ( 1 , V_52 , V_10 , L_51 , V_53 ) ;
return 0 ;
}
V_6 = & V_89 -> V_6 ;
if ( ! F_86 ( V_89 , F_59 ( V_10 ) ,
F_1 , NULL ) )
return - V_179 ;
F_93 ( V_10 , V_89 ) ;
V_40 -> V_89 = * V_89 ;
F_50 ( V_10 , 0x91 , V_6 -> V_164 ? 0x40 : 0x00 ) ;
V_30 = F_74 ( V_10 , V_89 ) ;
if ( V_30 ) {
F_75 ( V_10 , V_6 ) ;
}
F_79 ( V_10 ) ;
if ( V_52 > 1 )
F_96 ( V_10 -> V_180 , L_52 ,
V_89 , true ) ;
return 0 ;
}
static int F_98 ( struct V_9 * V_10 ,
struct V_1 * V_89 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_54 == V_148 )
return - V_168 ;
* V_89 = V_40 -> V_89 ;
return 0 ;
}
static void F_99 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_79 ( V_10 ) ;
switch ( V_40 -> V_54 ) {
case V_148 :
case V_56 :
case V_55 :
F_23 ( V_10 , 0x15 , 0xb0 ) ;
break;
case V_57 :
F_47 ( V_10 , 0x01 , 0x00 ) ;
F_23 ( V_10 , 0x15 , 0xa0 ) ;
F_48 ( V_10 , 0x1a , 0xef , 0x00 ) ;
break;
default:
F_55 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
}
static void F_100 ( struct V_9 * V_10 )
{
F_48 ( V_10 , 0x1a , 0xef , 0x10 ) ;
F_101 ( 16 ) ;
F_23 ( V_10 , 0x15 , 0xbe ) ;
F_47 ( V_10 , 0x01 , 0x78 ) ;
}
static void F_102 ( struct V_9 * V_10 ,
const struct V_181 * V_182 )
{
F_34 ( V_10 , 0xe0 , 0xbf , V_182 -> V_183 ? 0x00 : 0x40 ) ;
if ( ! V_182 -> V_183 )
return;
F_34 ( V_10 , 0xe0 , 0x7f , V_182 -> V_184 == 2 ? 0x80 : 0x00 ) ;
F_34 ( V_10 , 0xe0 , 0xe0 , V_182 -> V_185 >> 8 ) ;
F_33 ( V_10 , 0xe1 , V_182 -> V_185 ) ;
F_34 ( V_10 , 0xe2 , 0xe0 , V_182 -> V_186 >> 8 ) ;
F_33 ( V_10 , 0xe3 , V_182 -> V_186 ) ;
F_34 ( V_10 , 0xe4 , 0xe0 , V_182 -> V_187 >> 8 ) ;
F_33 ( V_10 , 0xe5 , V_182 -> V_187 ) ;
F_34 ( V_10 , 0xe6 , 0x80 , V_182 -> V_188 >> 8 ) ;
F_33 ( V_10 , 0xe7 , V_182 -> V_188 ) ;
F_34 ( V_10 , 0xe8 , 0xe0 , V_182 -> V_189 >> 8 ) ;
F_33 ( V_10 , 0xe9 , V_182 -> V_189 ) ;
F_34 ( V_10 , 0xea , 0xe0 , V_182 -> V_190 >> 8 ) ;
F_33 ( V_10 , 0xeb , V_182 -> V_190 ) ;
F_34 ( V_10 , 0xec , 0xe0 , V_182 -> V_191 >> 8 ) ;
F_33 ( V_10 , 0xed , V_182 -> V_191 ) ;
F_34 ( V_10 , 0xee , 0x80 , V_182 -> V_192 >> 8 ) ;
F_33 ( V_10 , 0xef , V_182 -> V_192 ) ;
F_34 ( V_10 , 0xf0 , 0xe0 , V_182 -> V_193 >> 8 ) ;
F_33 ( V_10 , 0xf1 , V_182 -> V_193 ) ;
F_34 ( V_10 , 0xf2 , 0xe0 , V_182 -> V_194 >> 8 ) ;
F_33 ( V_10 , 0xf3 , V_182 -> V_194 ) ;
F_34 ( V_10 , 0xf4 , 0xe0 , V_182 -> V_195 >> 8 ) ;
F_33 ( V_10 , 0xf5 , V_182 -> V_195 ) ;
F_34 ( V_10 , 0xf6 , 0x80 , V_182 -> V_196 >> 8 ) ;
F_33 ( V_10 , 0xf7 , V_182 -> V_196 ) ;
}
static void F_103 ( struct V_9 * V_10 ,
enum V_197 V_198 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_40 -> V_54 ) {
case V_148 :
F_23 ( V_10 , 0x00 , V_198 ) ;
F_23 ( V_10 , 0x01 , 0 ) ;
F_51 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_39 ( V_10 , 0x00 , 0x00 ) ;
F_39 ( V_10 , 0xc8 , 0x00 ) ;
F_23 ( V_10 , 0xdd , 0x90 ) ;
F_40 ( V_10 , 0x02 , 0x7f , 0x80 ) ;
if ( V_198 == V_199 ) {
F_39 ( V_10 , 0x03 , 0xa0 ) ;
F_39 ( V_10 , 0x04 , 0x00 ) ;
} else {
F_39 ( V_10 , 0x03 , 0xa0 ) ;
F_39 ( V_10 , 0x04 , 0xc0 ) ;
}
F_39 ( V_10 , 0x0c , 0x1f ) ;
F_39 ( V_10 , 0x12 , 0x63 ) ;
F_33 ( V_10 , 0xb2 , 0x60 ) ;
F_33 ( V_10 , 0xc8 , 0xe3 ) ;
F_36 ( V_10 , 0x00 , 0x3F ) ;
F_36 ( V_10 , 0x01 , 0x00 ) ;
F_36 ( V_10 , 0x03 , 0xE4 ) ;
F_36 ( V_10 , 0x04 , 0x0B ) ;
F_36 ( V_10 , 0x05 , 0xC3 ) ;
F_36 ( V_10 , 0x06 , 0xFE ) ;
F_36 ( V_10 , 0x12 , 0x0D ) ;
F_36 ( V_10 , 0xA7 , 0x00 ) ;
F_33 ( V_10 , 0xB0 , 0x00 ) ;
F_37 ( V_10 , 0x12 , 0xf6 , 0x09 ) ;
break;
case V_56 :
case V_55 :
F_40 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
F_23 ( V_10 , 0x00 , V_198 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_51 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_39 ( V_10 , 0x00 , 0x00 ) ;
F_39 ( V_10 , 0xc8 , 0x00 ) ;
if ( V_40 -> V_54 == V_56 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x60 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
}
F_39 ( V_10 , 0x0c , 0x1f ) ;
F_39 ( V_10 , 0x12 , 0x63 ) ;
F_50 ( V_10 , 0x73 , 0x10 ) ;
F_50 ( V_10 , 0x74 , 0x04 ) ;
F_50 ( V_10 , 0x75 , 0x01 ) ;
F_50 ( V_10 , 0x76 , 0x00 ) ;
F_50 ( V_10 , 0x3e , 0x04 ) ;
F_50 ( V_10 , 0xc3 , 0x39 ) ;
F_50 ( V_10 , 0x40 , 0x5c ) ;
break;
case V_57 :
F_40 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
if ( V_40 -> V_200 )
F_47 ( V_10 , 0x00 , 0x02 ) ;
else
F_47 ( V_10 , 0x00 , 0x03 ) ;
F_23 ( V_10 , 0x00 , V_198 ) ;
F_23 ( V_10 , 0x01 , 5 ) ;
F_51 ( V_10 , 0x81 , 0xef , 0x00 ) ;
F_47 ( V_10 , 0xc0 , 0x00 ) ;
F_47 ( V_10 , 0x0d , 0x34 ) ;
F_47 ( V_10 , 0x3d , 0x10 ) ;
F_47 ( V_10 , 0x44 , 0x85 ) ;
F_47 ( V_10 , 0x46 , 0x1f ) ;
F_47 ( V_10 , 0x57 , 0xb6 ) ;
F_47 ( V_10 , 0x58 , 0x03 ) ;
F_47 ( V_10 , 0x60 , 0x88 ) ;
F_47 ( V_10 , 0x61 , 0x88 ) ;
F_47 ( V_10 , 0x6c , 0x18 ) ;
F_47 ( V_10 , 0x75 , 0x10 ) ;
F_47 ( V_10 , 0x85 , 0x1f ) ;
F_47 ( V_10 , 0x87 , 0x70 ) ;
F_47 ( V_10 , 0x89 , 0x04 ) ;
F_47 ( V_10 , 0x8a , 0x1e ) ;
F_47 ( V_10 , 0x93 , 0x04 ) ;
F_47 ( V_10 , 0x94 , 0x1e ) ;
F_47 ( V_10 , 0x99 , 0xa1 ) ;
F_47 ( V_10 , 0x9b , 0x09 ) ;
F_47 ( V_10 , 0x9d , 0x02 ) ;
F_39 ( V_10 , 0x00 , 0xff ) ;
F_39 ( V_10 , 0xc8 , 0x40 ) ;
F_50 ( V_10 , 0x73 , 0x10 ) ;
F_50 ( V_10 , 0x74 , 0x04 ) ;
F_50 ( V_10 , 0x75 , 0x01 ) ;
F_50 ( V_10 , 0x76 , 0x00 ) ;
F_39 ( V_10 , 0x12 , 0xfb ) ;
F_39 ( V_10 , 0x0c , 0x0d ) ;
F_50 ( V_10 , 0x3e , 0x00 ) ;
F_50 ( V_10 , 0xc3 , 0x33 ) ;
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
default:
F_55 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
}
static int F_104 ( struct V_9 * V_10 ,
T_3 V_201 , T_3 V_202 , T_3 V_203 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_55 ( 2 , V_52 , V_10 , L_53 , V_53 , V_201 ) ;
switch ( V_201 ) {
case V_204 :
V_40 -> V_54 = V_57 ;
V_40 -> V_198 = V_205 ;
V_40 -> V_200 = true ;
break;
case V_206 :
V_40 -> V_54 = V_57 ;
V_40 -> V_198 = V_205 ;
V_40 -> V_200 = false ;
break;
case V_207 :
V_40 -> V_54 = V_56 ;
V_40 -> V_198 = V_208 ;
break;
case V_209 :
V_40 -> V_54 = V_55 ;
V_40 -> V_198 = V_208 ;
break;
case V_210 :
V_40 -> V_54 = V_148 ;
V_40 -> V_198 = V_199 ;
break;
case V_211 :
V_40 -> V_54 = V_148 ;
V_40 -> V_198 = V_212 ;
break;
default:
return - V_75 ;
}
F_100 ( V_10 ) ;
F_103 ( V_10 , V_40 -> V_198 ) ;
F_99 ( V_10 ) ;
F_105 ( V_10 , V_213 , NULL ) ;
return 0 ;
}
static int F_106 ( struct V_9 * V_10 , unsigned int V_214 ,
enum V_215 * V_216 )
{
if ( V_214 )
return - V_75 ;
* V_216 = V_217 ;
return 0 ;
}
static int F_107 ( struct V_9 * V_10 ,
struct V_218 * V_219 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
V_219 -> V_7 = V_40 -> V_89 . V_6 . V_7 ;
V_219 -> V_96 = V_40 -> V_89 . V_6 . V_96 ;
V_219 -> V_216 = V_217 ;
V_219 -> V_220 = V_221 ;
if ( V_40 -> V_54 == V_148 ) {
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) )
return - V_75 ;
V_219 -> V_7 = 720 ;
if ( V_40 -> V_222 & V_223 )
V_219 -> V_96 = 480 ;
else
V_219 -> V_96 = 576 ;
V_219 -> V_224 = V_225 ;
return 0 ;
}
if ( V_40 -> V_89 . V_6 . V_127 & V_128 ) {
V_219 -> V_224 = ( V_40 -> V_89 . V_6 . V_96 <= 576 ) ?
V_225 : V_226 ;
}
return 0 ;
}
static void F_108 ( struct V_9 * V_10 , bool V_227 )
{
if ( V_227 ) {
F_23 ( V_10 , 0x46 , 0x9c ) ;
F_23 ( V_10 , 0x5a , 0x10 ) ;
F_23 ( V_10 , 0x73 , 0x03 ) ;
F_23 ( V_10 , 0x78 , 0x03 ) ;
F_23 ( V_10 , 0xa0 , 0x09 ) ;
F_23 ( V_10 , 0x69 , 0x08 ) ;
} else {
F_23 ( V_10 , 0x46 , 0x0 ) ;
F_23 ( V_10 , 0x5a , 0x0 ) ;
F_23 ( V_10 , 0x73 , 0x0 ) ;
F_23 ( V_10 , 0x78 , 0x0 ) ;
F_23 ( V_10 , 0xa0 , 0x0 ) ;
F_23 ( V_10 , 0x69 , 0x0 ) ;
}
}
static int F_109 ( struct V_9 * V_10 , T_3 V_146 , bool * V_228 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_229 , V_230 , V_231 ;
T_2 V_232 [ 6 ] ;
F_108 ( V_10 , false ) ;
V_232 [ 0 ] = F_21 ( V_10 , 0x43 ) ;
V_232 [ 1 ] = F_21 ( V_10 , 0x57 ) ;
V_232 [ 2 ] = F_21 ( V_10 , 0x70 ) ;
V_232 [ 3 ] = F_21 ( V_10 , 0x75 ) ;
V_232 [ 4 ] = F_21 ( V_10 , 0x9d ) ;
V_232 [ 5 ] = F_21 ( V_10 , 0x66 ) ;
if ( V_232 [ 0 ] )
F_23 ( V_10 , 0x44 , V_232 [ 0 ] ) ;
if ( V_232 [ 1 ] )
F_23 ( V_10 , 0x58 , V_232 [ 1 ] ) ;
if ( V_232 [ 2 ] )
F_23 ( V_10 , 0x71 , V_232 [ 2 ] ) ;
if ( V_232 [ 3 ] )
F_23 ( V_10 , 0x76 , V_232 [ 3 ] ) ;
if ( V_232 [ 4 ] )
F_23 ( V_10 , 0x9e , V_232 [ 4 ] ) ;
if ( V_232 [ 5 ] )
F_23 ( V_10 , 0x67 , V_232 [ 5 ] ) ;
F_108 ( V_10 , true ) ;
F_55 ( 1 , V_52 , V_10 , L_54 , V_53 ,
V_232 [ 0 ] , V_232 [ 1 ] , V_232 [ 2 ] ,
V_232 [ 3 ] , V_232 [ 4 ] , V_232 [ 5 ] ) ;
V_229 = V_232 [ 0 ] & 0x9c ;
if ( V_40 -> V_54 == V_148 )
V_231 = ( V_232 [ 1 ] & 0x30 ) | ( V_232 [ 4 ] & 0x09 ) ;
else
V_231 = 0 ;
if ( F_58 ( V_10 ) )
V_230 = V_232 [ 3 ] & 0x03 ;
else
V_230 = 0 ;
if ( V_229 || V_230 || V_231 ) {
F_55 ( 1 , V_52 , V_10 ,
L_55 ,
V_53 , V_229 , V_230 ,
V_231 ) ;
F_105 ( V_10 , V_213 , NULL ) ;
if ( V_228 )
* V_228 = true ;
}
if ( V_232 [ 5 ] & 0x08 ) {
F_55 ( 1 , V_52 , V_10 , L_56 , V_53 ,
( F_21 ( V_10 , 0x65 ) & 0x08 ) ? L_57 : L_58 ) ;
F_79 ( V_10 ) ;
if ( V_228 )
* V_228 = true ;
}
if ( V_232 [ 2 ] & 0x3 ) {
F_55 ( 1 , V_52 , V_10 , L_59 , V_53 ) ;
F_70 ( V_10 ) ;
if ( V_228 )
* V_228 = true ;
}
return 0 ;
}
static int F_110 ( struct V_9 * V_10 , struct V_233 * V_71 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 * V_20 = NULL ;
if ( V_71 -> V_166 > V_234 )
return - V_75 ;
if ( V_71 -> V_235 == 0 )
return - V_75 ;
if ( V_71 -> V_235 > 2 )
return - V_75 ;
if ( V_71 -> V_236 > 1 )
return - V_75 ;
if ( V_71 -> V_236 == 1 )
V_71 -> V_235 = 1 ;
switch ( V_71 -> V_166 ) {
case V_68 :
case V_69 :
if ( V_40 -> V_67 . V_66 & ( 0x04 << V_71 -> V_166 ) )
V_20 = V_40 -> V_67 . V_71 ;
break;
case V_234 :
if ( V_40 -> V_70 . V_66 )
V_20 = V_40 -> V_70 . V_71 ;
break;
default:
return - V_75 ;
}
if ( ! V_20 )
return - V_168 ;
memcpy ( V_71 -> V_71 ,
V_20 + V_71 -> V_236 * 128 ,
V_71 -> V_235 * 128 ) ;
return 0 ;
}
static int F_111 ( struct V_9 * V_10 , struct V_233 * V_237 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 = 0 ;
if ( V_237 -> V_166 > V_234 )
return - V_75 ;
if ( V_237 -> V_236 != 0 )
return - V_75 ;
if ( V_237 -> V_235 > 2 )
return - V_238 ;
V_40 -> V_162 = F_112 ( V_237 -> V_71 [ 0x15 ] ,
V_237 -> V_71 [ 0x16 ] ) ;
switch ( V_237 -> V_166 ) {
case V_234 :
memset ( & V_40 -> V_70 . V_71 , 0 , 256 ) ;
V_40 -> V_70 . V_66 = V_237 -> V_235 ? 0x1 : 0x0 ;
memcpy ( & V_40 -> V_70 . V_71 , V_237 -> V_71 , 128 * V_237 -> V_235 ) ;
V_30 = F_62 ( V_10 ) ;
break;
case V_68 :
case V_69 :
memset ( & V_40 -> V_67 . V_71 , 0 , 256 ) ;
if ( V_237 -> V_235 )
V_40 -> V_67 . V_66 |= 0x04 << V_237 -> V_166 ;
else
V_40 -> V_67 . V_66 &= ~ ( 0x04 << V_237 -> V_166 ) ;
memcpy ( & V_40 -> V_67 . V_71 , V_237 -> V_71 , 128 * V_237 -> V_235 ) ;
V_30 = F_65 ( V_10 , V_237 -> V_166 ) ;
break;
default:
return - V_75 ;
}
if ( V_30 < 0 )
F_76 ( V_10 , L_60 , V_30 , V_237 -> V_166 ) ;
return V_30 ;
}
static void F_113 ( struct V_9 * V_10 , T_6 * V_239 ,
struct V_240 * V_241 )
{
V_241 -> V_242 = ( V_239 [ 1 ] >> 7 ) & 0x1 ;
V_241 -> V_243 = ( V_239 [ 1 ] >> 5 ) & 0x3 ;
V_241 -> V_244 = ( V_239 [ 1 ] >> 4 ) & 0x1 ;
V_241 -> V_245 = ( V_239 [ 1 ] >> 2 ) & 0x3 ;
V_241 -> V_246 = V_239 [ 1 ] & 0x3 ;
V_241 -> V_247 = ( V_239 [ 2 ] >> 6 ) & 0x3 ;
V_241 -> V_248 = ( V_239 [ 2 ] >> 4 ) & 0x3 ;
V_241 -> V_249 = V_239 [ 2 ] & 0xf ;
V_241 -> V_250 = ( V_239 [ 3 ] >> 7 ) & 0x1 ;
V_241 -> V_251 = ( V_239 [ 3 ] >> 4 ) & 0x7 ;
V_241 -> V_252 = ( V_239 [ 3 ] >> 2 ) & 0x3 ;
V_241 -> V_253 = V_239 [ 3 ] & 0x3 ;
V_241 -> V_254 = ( V_239 [ 4 ] >> 7 ) & 0x1 ;
V_241 -> V_255 = V_239 [ 4 ] & 0x7f ;
V_241 -> V_256 = ( V_239 [ 5 ] >> 6 ) & 0x3 ;
V_241 -> V_257 = ( V_239 [ 5 ] >> 4 ) & 0x3 ;
V_241 -> V_258 = V_239 [ 5 ] & 0xf ;
V_241 -> V_259 = V_239 [ 6 ] + 256 * V_239 [ 7 ] ;
V_241 -> V_260 = V_239 [ 8 ] + 256 * V_239 [ 9 ] ;
V_241 -> V_261 = V_239 [ 10 ] + 256 * V_239 [ 11 ] ;
V_241 -> V_262 = V_239 [ 12 ] + 256 * V_239 [ 13 ] ;
}
static void F_114 ( struct V_9 * V_10 )
{
int V_4 ;
T_6 V_239 [ 14 ] ;
T_2 V_263 ;
T_2 V_264 ;
struct V_240 V_241 ;
if ( ! ( F_46 ( V_10 , 0x05 ) & 0x80 ) ) {
F_67 ( V_10 , L_61 ) ;
return;
}
if ( ! ( F_21 ( V_10 , 0x60 ) & 0x01 ) ) {
F_67 ( V_10 , L_62 ) ;
return;
}
if ( F_21 ( V_10 , 0x88 ) & 0x10 ) {
F_67 ( V_10 , L_63 ) ;
F_23 ( V_10 , 0x8a , 0x10 ) ;
if ( F_21 ( V_10 , 0x88 ) & 0x10 ) {
F_67 ( V_10 , L_64 ) ;
F_23 ( V_10 , 0x8a , 0x10 ) ;
}
}
V_263 = F_30 ( V_10 , 0xe2 ) ;
V_264 = F_30 ( V_10 , 0xe1 ) ;
F_67 ( V_10 , L_65 ,
V_264 , V_263 ) ;
if ( V_264 != 0x02 )
return;
for ( V_4 = 0 ; V_4 < 14 ; V_4 ++ )
V_239 [ V_4 ] = F_30 ( V_10 , V_4 ) ;
F_67 ( V_10 , L_66 ,
V_239 [ 0 ] , V_239 [ 1 ] , V_239 [ 2 ] , V_239 [ 3 ] , V_239 [ 4 ] , V_239 [ 5 ] , V_239 [ 6 ] , V_239 [ 7 ] ,
V_239 [ 8 ] , V_239 [ 9 ] , V_239 [ 10 ] , V_239 [ 11 ] , V_239 [ 12 ] , V_239 [ 13 ] ) ;
F_113 ( V_10 , V_239 , & V_241 ) ;
if ( V_241 . V_255 )
F_67 ( V_10 , L_67 , V_241 . V_255 ) ;
if ( V_241 . V_250 )
F_67 ( V_10 , L_68 , V_265 [ V_241 . V_250 ] ) ;
if ( V_241 . V_243 )
F_67 ( V_10 , L_69 , V_266 [ V_241 . V_243 ] , ! V_241 . V_247 ? L_70 :
( V_241 . V_247 == 0x3 ? V_267 [ V_241 . V_251 ] : V_268 [ V_241 . V_247 ] ) ) ;
else
F_67 ( V_10 , L_69 , V_266 [ V_241 . V_243 ] , V_269 [ V_241 . V_252 ] ) ;
}
static int F_115 ( struct V_9 * V_10 )
{
T_6 V_270 = F_35 ( V_10 , 0x5A ) & 0x01 ;
F_67 ( V_10 , L_71 , F_81 ( V_10 ) ? L_72 : L_73 ) ;
F_67 ( V_10 , L_74 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ) ;
F_67 ( V_10 , L_75 ,
( F_35 ( V_10 , 0x56 ) & 0x01 ) ? L_73 : L_72 ) ;
F_67 ( V_10 , L_76 , V_270 ?
L_77 : L_78 ) ;
if ( V_270 ) {
static const char * const V_271 [] = {
L_79 ,
L_80 ,
L_81 ,
L_82 ,
L_83 ,
L_84 ,
L_85 ,
L_86 , L_87 , L_88 , L_89 , L_90 ,
L_91 ,
L_92 ,
L_93 ,
L_94
} ;
F_67 ( V_10 , L_95 ,
V_271 [ F_35 ( V_10 , 0x52 ) & 0x0f ] ) ;
F_67 ( V_10 , L_76 ,
( F_35 ( V_10 , 0x59 ) & 0x08 ) ? L_96 : L_97 ) ;
F_67 ( V_10 , L_76 ,
( F_35 ( V_10 , 0x57 ) & 0x08 ) ? L_98 : L_99 ) ;
F_67 ( V_10 , L_100 ,
( F_35 ( V_10 , 0x12 ) & 0x08 ) ? L_101 : L_102 ) ;
F_67 ( V_10 , L_103 ,
( F_32 ( V_10 , 0xe0 ) & 0x40 ) ? L_104 : L_105 ) ;
}
return 0 ;
}
static int F_116 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_1 V_89 ;
T_6 V_272 = F_21 ( V_10 , 0x02 ) ;
T_6 V_273 = F_21 ( V_10 , 0x21 ) ;
T_6 V_274 = F_41 ( V_10 , 0x77 ) ;
T_6 V_275 = F_41 ( V_10 , 0x7d ) ;
bool V_276 = F_46 ( V_10 , 0x04 ) & 0x01 ;
bool V_277 = F_46 ( V_10 , 0x18 ) & 0x01 ;
bool V_278 = F_21 ( V_10 , 0x65 ) & 0x40 ;
static const char * const V_279 [ 16 ] = {
L_106 , L_107 , L_108 , L_109 ,
L_108 , L_110 , L_108 , L_111 ,
L_108 , L_112 , L_113 ,
L_108 , L_108 , L_108 , L_108 , L_105
} ;
static const char * const V_280 [ 16 ] = {
L_114 , L_115 ,
L_116 , L_117 ,
L_118 , L_119 ,
L_120 , L_121 ,
L_122 , L_122 , L_122 , L_122 , L_122 ,
L_122 , L_122 , L_123
} ;
static const char * const V_281 [] = {
L_124 ,
L_114 ,
L_115 ,
} ;
static const char * const V_282 [ 4 ] = {
L_125 ,
L_126 ,
L_127 ,
L_128
} ;
F_67 ( V_10 , L_129 ) ;
F_67 ( V_10 , L_130 , F_81 ( V_10 ) ? L_72 : L_73 ) ;
F_67 ( V_10 , L_131 ,
V_40 -> V_200 ? L_132 : L_133 ) ;
F_67 ( V_10 , L_134 ,
( ( V_275 & 0x04 ) && ( V_274 & 0x04 ) ) ?
L_101 : L_102 ,
( ( V_275 & 0x08 ) && ( V_274 & 0x08 ) ) ?
L_101 : L_102 ) ;
F_67 ( V_10 , L_135 ,
V_273 & 0x02 ? L_101 : L_102 ,
V_273 & 0x01 ? L_101 : L_102 ) ;
F_67 ( V_10 , L_136 , ! ! ( F_27 ( V_10 , 0x2a ) & 0x01 ) ?
L_101 : L_102 ) ;
F_67 ( V_10 , L_137 ) ;
if ( V_40 -> V_200 ) {
F_67 ( V_10 , L_138 ,
F_21 ( V_10 , 0x6f ) & 0x02 ? L_139 : L_140 ) ;
F_67 ( V_10 , L_141 ,
( F_21 ( V_10 , 0x6a ) & 0x02 ) ? L_139 : L_140 ) ;
F_67 ( V_10 , L_142 ,
( F_21 ( V_10 , 0x6a ) & 0x20 ) ? L_139 : L_140 ) ;
} else {
F_67 ( V_10 , L_143 ,
F_21 ( V_10 , 0x6f ) & 0x01 ? L_139 : L_140 ) ;
F_67 ( V_10 , L_141 ,
( F_21 ( V_10 , 0x6a ) & 0x01 ) ? L_139 : L_140 ) ;
F_67 ( V_10 , L_142 ,
( F_21 ( V_10 , 0x6a ) & 0x10 ) ? L_139 : L_140 ) ;
}
F_67 ( V_10 , L_144 ,
( ! ! ( F_49 ( V_10 , 0xff ) & 0x10 ) ? L_73 : L_72 ) ) ;
F_67 ( V_10 , L_145 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ,
( F_21 ( V_10 , 0x01 ) & 0x70 ) >> 4 ) ;
F_67 ( V_10 , L_146 ) ;
if ( F_82 ( V_10 ) ) {
F_67 ( V_10 , L_147 ) ;
} else {
T_5 V_153 = ( ( F_49 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_49 ( V_10 , 0xb2 ) ;
T_5 V_156 = ( ( F_49 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_49 ( V_10 , 0xb4 ) ;
T_5 V_157 = F_49 ( V_10 , 0xb3 ) >> 3 ;
T_5 V_283 = ( ( F_49 ( V_10 , 0xb8 ) & 0x1f ) << 8 ) | F_49 ( V_10 , 0xb9 ) ;
char V_158 = ( ( F_49 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_49 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
char V_160 = ( ( F_49 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_49 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
F_67 ( V_10 ,
L_148 ,
V_156 , V_153 , V_157 , V_283 ,
( F_49 ( V_10 , 0xb1 ) & 0x40 ) ?
L_43 : L_44 ,
V_158 , V_160 ) ;
}
if ( F_95 ( V_10 , & V_89 ) )
F_67 ( V_10 , L_149 ) ;
else
F_96 ( V_10 -> V_180 , L_150 ,
& V_89 , true ) ;
F_96 ( V_10 -> V_180 , L_151 ,
& V_40 -> V_89 , true ) ;
if ( F_82 ( V_10 ) )
return 0 ;
F_67 ( V_10 , L_152 ) ;
F_67 ( V_10 , L_153 ,
V_281 [ V_40 -> V_125 ] ) ;
F_67 ( V_10 , L_154 ,
V_280 [ V_272 >> 4 ] ) ;
F_67 ( V_10 , L_155 ,
( V_272 & 0x02 ) ? L_156 : L_157 ,
( V_272 & 0x04 ) ? L_158 : L_159 ,
( ( V_272 & 0x04 ) ^ ( V_272 & 0x01 ) ) ?
L_101 : L_102 ) ;
F_67 ( V_10 , L_160 ,
V_279 [ F_49 ( V_10 , 0xf4 ) >> 4 ] ) ;
if ( ! F_58 ( V_10 ) )
return 0 ;
F_67 ( V_10 , L_161 , F_83 ( V_10 ) ? L_57 : L_162 ) ;
F_67 ( V_10 , L_163 ,
( F_46 ( V_10 , 0x05 ) & 0x40 ) ? L_139 : L_140 ) ;
F_67 ( V_10 , L_164 ,
( F_46 ( V_10 , 0x04 ) & 0x20 ) ? L_165 : L_166 ,
( F_46 ( V_10 , 0x04 ) & 0x10 ) ? L_167 : L_70 ) ;
if ( ! F_83 ( V_10 ) )
return 0 ;
F_67 ( V_10 , L_168 ,
V_276 ? L_169 : L_170 ,
V_277 ? L_171 : L_172 ,
V_278 ? L_173 : L_101 ) ;
if ( V_276 && V_277 ) {
F_67 ( V_10 , L_174 ,
( F_46 ( V_10 , 0x07 ) & 0x40 ) ? L_175 : L_176 ) ;
}
F_67 ( V_10 , L_177 , ( F_46 ( V_10 , 0x5b ) << 12 ) +
( F_46 ( V_10 , 0x5c ) << 8 ) +
( F_46 ( V_10 , 0x5d ) & 0xf0 ) ) ;
F_67 ( V_10 , L_178 , ( ( F_46 ( V_10 , 0x5d ) & 0x0f ) << 16 ) +
( F_46 ( V_10 , 0x5e ) << 8 ) +
F_46 ( V_10 , 0x5f ) ) ;
F_67 ( V_10 , L_179 ,
( F_46 ( V_10 , 0x04 ) & 0x40 ) ? L_73 : L_72 ) ;
F_67 ( V_10 , L_180 ,
V_282 [ F_46 ( V_10 , 0x0b ) >> 6 ] ) ;
F_114 ( V_10 ) ;
return 0 ;
}
static int F_117 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_54 == V_148 )
return F_115 ( V_10 ) ;
return F_116 ( V_10 ) ;
}
static int F_118 ( struct V_9 * V_10 , T_7 * V_284 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_148 )
return - V_168 ;
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) ) {
* V_284 = 0 ;
F_55 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return 0 ;
}
switch ( F_35 ( V_10 , 0x52 ) & 0x0f ) {
case 0 :
* V_284 &= V_285 ;
break;
case 2 :
* V_284 &= V_286 ;
break;
case 3 :
* V_284 &= V_287 ;
break;
case 4 :
* V_284 &= V_288 ;
break;
case 6 :
* V_284 &= V_289 ;
break;
case 0xc :
* V_284 &= V_290 ;
break;
case 0xe :
* V_284 &= V_291 ;
break;
case 0xf :
* V_284 &= V_287 ;
break;
default:
* V_284 &= V_292 ;
break;
}
return 0 ;
}
static void F_119 ( struct V_9 * V_10 , struct V_293 * V_294 )
{
if ( V_294 && V_294 -> V_295 ) {
F_33 ( V_10 , 0x94 , ( V_294 -> V_296 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x95 , V_294 -> V_296 & 0xff ) ;
F_33 ( V_10 , 0x96 , ( V_294 -> V_297 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x97 , V_294 -> V_297 & 0xff ) ;
F_33 ( V_10 , 0x98 , ( V_294 -> V_298 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x99 , V_294 -> V_298 & 0xff ) ;
F_33 ( V_10 , 0x9a , ( V_294 -> V_299 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x9b , V_294 -> V_299 & 0xff ) ;
F_33 ( V_10 , 0xa8 , V_294 -> V_300 ) ;
F_33 ( V_10 , 0xa9 , V_294 -> V_301 ) ;
F_33 ( V_10 , 0xaa , V_294 -> V_302 ) ;
F_33 ( V_10 , 0xab , V_294 -> V_303 ) ;
F_33 ( V_10 , 0xac , V_294 -> V_304 ) ;
F_33 ( V_10 , 0xad , V_294 -> V_305 ) ;
F_33 ( V_10 , 0xae , V_294 -> V_306 ) ;
F_33 ( V_10 , 0xaf , V_294 -> V_307 ) ;
} else {
F_33 ( V_10 , 0x94 , 0x00 ) ;
F_33 ( V_10 , 0x95 , 0x00 ) ;
F_33 ( V_10 , 0x96 , 0x00 ) ;
F_33 ( V_10 , 0x97 , 0x20 ) ;
F_33 ( V_10 , 0x98 , 0x00 ) ;
F_33 ( V_10 , 0x99 , 0x00 ) ;
F_33 ( V_10 , 0x9a , 0x00 ) ;
F_33 ( V_10 , 0x9b , 0x00 ) ;
F_33 ( V_10 , 0xa8 , 0x04 ) ;
F_33 ( V_10 , 0xa9 , 0x04 ) ;
F_33 ( V_10 , 0xaa , 0x04 ) ;
F_33 ( V_10 , 0xab , 0x04 ) ;
F_33 ( V_10 , 0xac , 0x04 ) ;
F_33 ( V_10 , 0xad , 0x04 ) ;
F_33 ( V_10 , 0xae , 0x04 ) ;
F_33 ( V_10 , 0xaf , 0x04 ) ;
}
}
static int F_120 ( struct V_9 * V_10 , T_7 V_222 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_308 * V_309 = & V_40 -> V_309 ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_148 )
return - V_168 ;
if ( V_222 & V_310 )
F_119 ( V_10 , & V_309 -> V_311 ) ;
else if ( V_222 & V_223 )
F_119 ( V_10 , & V_309 -> V_312 ) ;
else
F_119 ( V_10 , NULL ) ;
if ( V_222 & V_292 ) {
V_40 -> V_222 = V_222 ;
return 0 ;
}
return - V_75 ;
}
static int F_121 ( struct V_9 * V_10 , T_7 * V_222 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_148 )
return - V_168 ;
* V_222 = V_40 -> V_222 ;
return 0 ;
}
static int F_122 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_308 * V_309 = & V_40 -> V_309 ;
F_47 ( V_10 , 0x48 ,
( V_309 -> V_313 ? 0x80 : 0 ) |
( V_309 -> V_314 ? 0x40 : 0 ) ) ;
F_100 ( V_10 ) ;
F_43 ( V_10 , 0x77 , 0xd3 , 0x20 ) ;
F_23 ( V_10 , 0x0c , 0x42 ) ;
F_23 ( V_10 , 0x15 , 0x80 ) ;
F_23 ( V_10 , 0x02 ,
0xf0 |
V_309 -> V_315 << 3 |
V_309 -> V_316 << 2 |
V_309 -> V_317 << 1 |
V_309 -> V_318 << 0 ) ;
F_23 ( V_10 , 0x03 , V_309 -> V_319 ) ;
F_24 ( V_10 , 0x04 , 0x1f , V_309 -> V_320 << 5 ) ;
F_24 ( V_10 , 0x05 , 0xf0 , V_309 -> V_321 << 3 |
V_309 -> V_322 << 2 |
V_309 -> V_323 << 1 |
V_309 -> V_324 << 0 ) ;
F_48 ( V_10 , 0x1a , 0xf1 , 0x08 ) ;
F_24 ( V_10 , 0x14 , 0xc0 ,
V_309 -> V_325 << 4 |
V_309 -> V_326 << 2 |
V_309 -> V_327 ) ;
F_51 ( V_10 , 0xba , 0xfc , V_309 -> V_328 |
( V_309 -> V_329 << 1 ) ) ;
F_37 ( V_10 , 0xdd , 0xf0 , V_309 -> V_330 |
( V_309 -> V_331 << 1 ) |
( V_309 -> V_332 << 2 ) |
( V_309 -> V_333 << 3 ) ) ;
F_50 ( V_10 , 0x69 , 0x14 ) ;
F_23 ( V_10 , 0x06 , 0xa6 ) ;
F_50 ( V_10 , 0xf3 , 0xdc ) ;
F_39 ( V_10 , 0xb5 , 0x01 ) ;
F_39 ( V_10 , 0x02 , V_309 -> V_334 ) ;
F_24 ( V_10 , 0x30 , ~ ( 1 << 4 ) , V_309 -> V_335 << 4 ) ;
F_102 ( V_10 , & V_309 -> F_102 ) ;
if ( V_309 -> V_336 >= 128 ) {
F_36 ( V_10 , 0x12 , 0x0d ) ;
if ( V_309 -> V_337 ) {
F_33 ( V_10 , 0x6f , 0x00 ) ;
F_33 ( V_10 , 0x75 , 0x0a ) ;
F_33 ( V_10 , 0x7a , 0xa5 ) ;
F_33 ( V_10 , 0x7b , 0x8f ) ;
F_33 ( V_10 , 0x60 , 0x01 ) ;
} else {
F_33 ( V_10 , 0x75 , 0x0a ) ;
F_33 ( V_10 , 0x74 , 0x00 ) ;
F_33 ( V_10 , 0x79 , 0x33 ) ;
F_33 ( V_10 , 0x6f , 0x01 ) ;
F_33 ( V_10 , 0x7a , 0xa5 ) ;
F_33 ( V_10 , 0x7b , 0x8f ) ;
F_33 ( V_10 , 0x60 , 0x01 ) ;
}
} else {
F_33 ( V_10 , 0x29 , 0x10 ) ;
}
F_103 ( V_10 , V_309 -> V_198 ) ;
F_99 ( V_10 ) ;
if ( V_309 -> V_338 ) {
F_47 ( V_10 , 0x69 , 0x5c ) ;
} else {
F_47 ( V_10 , 0x69 , 0xa3 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
}
F_23 ( V_10 , 0x19 , 0x80 | V_309 -> V_339 ) ;
F_23 ( V_10 , 0x33 , 0x40 ) ;
F_23 ( V_10 , 0x40 , 0xf2 ) ;
F_108 ( V_10 , true ) ;
return F_123 ( V_10 -> V_340 ) ;
}
static int F_124 ( struct V_9 * V_10 )
{
int V_4 ;
int V_341 = 0 ;
int V_342 = 0 ;
int V_343 = 0 ;
F_23 ( V_10 , 0x00 , 0x01 ) ;
F_23 ( V_10 , 0x01 , 0x00 ) ;
F_39 ( V_10 , 0x80 , 0x92 ) ;
F_39 ( V_10 , 0x9B , 0x01 ) ;
F_39 ( V_10 , 0x9C , 0x60 ) ;
F_39 ( V_10 , 0x9E , 0x02 ) ;
F_39 ( V_10 , 0xA0 , 0x0B ) ;
F_39 ( V_10 , 0xC3 , 0x02 ) ;
F_23 ( V_10 , 0x0C , 0x40 ) ;
F_23 ( V_10 , 0x15 , 0xBA ) ;
F_36 ( V_10 , 0x12 , 0x00 ) ;
F_23 ( V_10 , 0xFF , 0x04 ) ;
F_56 ( 5 ) ;
F_36 ( V_10 , 0x12 , 0x00 ) ;
F_33 ( V_10 , 0x2A , 0x01 ) ;
F_33 ( V_10 , 0x7c , 0x19 ) ;
F_33 ( V_10 , 0x80 , 0x87 ) ;
F_33 ( V_10 , 0x81 , 0x4a ) ;
F_33 ( V_10 , 0x82 , 0x2c ) ;
F_33 ( V_10 , 0x83 , 0x0e ) ;
F_33 ( V_10 , 0x84 , 0x94 ) ;
F_33 ( V_10 , 0x85 , 0x62 ) ;
F_33 ( V_10 , 0x7d , 0x00 ) ;
F_33 ( V_10 , 0x7e , 0x1a ) ;
F_56 ( 5 ) ;
F_33 ( V_10 , 0xd9 , 0xd5 ) ;
F_36 ( V_10 , 0x12 , 0x05 ) ;
F_56 ( 20 ) ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
T_2 V_344 = F_32 ( V_10 , 0xdb ) ;
if ( V_344 & 0x10 ) {
V_343 ++ ;
if ( V_344 & 0x20 )
V_342 ++ ;
else
V_341 ++ ;
}
F_56 ( 20 ) ;
}
F_55 ( 1 , V_52 , V_10 ,
L_181 ,
V_343 , V_4 , V_341 , V_342 ) ;
if ( ! V_343 || V_342 )
return - V_27 ;
return 0 ;
}
static void F_125 ( struct V_9 * V_10 ,
struct V_308 * V_309 )
{
F_23 ( V_10 , 0xf1 , V_309 -> V_45 << 1 ) ;
F_23 ( V_10 , 0xf2 , V_309 -> V_44 << 1 ) ;
F_23 ( V_10 , 0xf3 , V_309 -> V_41 << 1 ) ;
F_23 ( V_10 , 0xf4 , V_309 -> V_42 << 1 ) ;
F_23 ( V_10 , 0xf5 , V_309 -> V_43 << 1 ) ;
F_23 ( V_10 , 0xf8 , V_309 -> V_46 << 1 ) ;
F_23 ( V_10 , 0xf9 , V_309 -> V_47 << 1 ) ;
F_23 ( V_10 , 0xfa , V_309 -> V_48 << 1 ) ;
F_23 ( V_10 , 0xfb , V_309 -> V_49 << 1 ) ;
F_23 ( V_10 , 0xfd , V_309 -> V_50 << 1 ) ;
F_23 ( V_10 , 0xfe , V_309 -> V_51 << 1 ) ;
}
static int F_126 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_308 * V_309 = V_16 -> V_345 . V_346 ;
struct V_1 V_89 ;
int V_28 = 0 ;
if ( ! V_309 )
return - V_347 ;
if ( ! V_309 -> V_336 || ! V_309 -> V_337 ) {
F_67 ( V_10 , L_182 ) ;
return - V_75 ;
}
F_54 ( V_10 ) ;
F_125 ( V_10 , V_309 ) ;
V_28 = F_124 ( V_10 ) ;
F_54 ( V_10 ) ;
F_125 ( V_10 , V_309 ) ;
F_122 ( V_10 ) ;
F_100 ( V_10 ) ;
F_103 ( V_10 , V_40 -> V_198 ) ;
F_99 ( V_10 ) ;
F_62 ( V_10 ) ;
F_65 ( V_10 , V_68 ) ;
F_65 ( V_10 , V_69 ) ;
V_89 = V_40 -> V_89 ;
memset ( & V_40 -> V_89 , 0 , sizeof( struct V_1 ) ) ;
F_97 ( V_10 , & V_89 ) ;
return V_28 ;
}
static long F_127 ( struct V_9 * V_10 , unsigned int V_348 , void * V_349 )
{
switch ( V_348 ) {
case V_350 :
return F_126 ( V_10 ) ;
}
return - V_351 ;
}
static void F_128 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_41 )
F_129 ( V_40 -> V_41 ) ;
if ( V_40 -> V_42 )
F_129 ( V_40 -> V_42 ) ;
if ( V_40 -> V_43 )
F_129 ( V_40 -> V_43 ) ;
if ( V_40 -> V_44 )
F_129 ( V_40 -> V_44 ) ;
if ( V_40 -> V_45 )
F_129 ( V_40 -> V_45 ) ;
if ( V_40 -> V_46 )
F_129 ( V_40 -> V_46 ) ;
if ( V_40 -> V_47 )
F_129 ( V_40 -> V_47 ) ;
if ( V_40 -> V_48 )
F_129 ( V_40 -> V_48 ) ;
if ( V_40 -> V_49 )
F_129 ( V_40 -> V_49 ) ;
if ( V_40 -> V_50 )
F_129 ( V_40 -> V_50 ) ;
if ( V_40 -> V_51 )
F_129 ( V_40 -> V_51 ) ;
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
static struct V_15 * F_130 ( struct V_9 * V_10 , const char * V_352 ,
T_2 V_22 , T_2 V_353 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_15 * V_354 ;
F_23 ( V_10 , V_353 , V_22 << 1 ) ;
if ( V_22 == 0 ) {
F_76 ( V_10 , L_183 , V_352 ) ;
return NULL ;
}
V_354 = F_131 ( V_16 -> V_21 , F_21 ( V_10 , V_353 ) >> 1 ) ;
if ( ! V_354 )
F_76 ( V_10 , L_184 , V_352 , V_22 ) ;
return V_354 ;
}
static int F_132 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_308 * V_309 = & V_40 -> V_309 ;
V_40 -> V_41 = F_130 ( V_10 , L_185 , V_309 -> V_41 , 0xf3 ) ;
V_40 -> V_42 = F_130 ( V_10 , L_186 , V_309 -> V_42 , 0xf4 ) ;
V_40 -> V_43 = F_130 ( V_10 , L_187 , V_309 -> V_43 , 0xf5 ) ;
V_40 -> V_44 = F_130 ( V_10 , L_188 , V_309 -> V_44 , 0xf2 ) ;
V_40 -> V_45 = F_130 ( V_10 , L_189 , V_309 -> V_45 , 0xf1 ) ;
V_40 -> V_46 = F_130 ( V_10 , L_190 , V_309 -> V_46 , 0xf8 ) ;
V_40 -> V_47 = F_130 ( V_10 , L_191 , V_309 -> V_47 , 0xf9 ) ;
V_40 -> V_48 = F_130 ( V_10 , L_192 , V_309 -> V_48 , 0xfa ) ;
V_40 -> V_49 = F_130 ( V_10 , L_193 , V_309 -> V_49 , 0xfb ) ;
V_40 -> V_50 = F_130 ( V_10 , L_194 , V_309 -> V_50 , 0xfd ) ;
V_40 -> V_51 = F_130 ( V_10 , L_195 , V_309 -> V_51 , 0xfe ) ;
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
static int F_133 ( struct V_15 * V_16 ,
const struct V_355 * V_131 )
{
struct V_8 * V_40 ;
static const struct V_1 V_356 =
V_357 ;
struct V_308 * V_309 = V_16 -> V_345 . V_346 ;
struct V_358 * V_3 ;
struct V_9 * V_10 ;
T_4 V_359 ;
int V_30 ;
if ( ! F_134 ( V_16 -> V_21 , V_360 ) )
return - V_27 ;
F_135 ( 1 , V_52 , V_16 , L_196 ,
V_16 -> V_22 << 1 ) ;
if ( ! V_309 ) {
F_16 ( V_16 , L_197 ) ;
return - V_347 ;
}
V_40 = F_136 ( & V_16 -> V_345 , sizeof( struct V_8 ) , V_361 ) ;
if ( ! V_40 ) {
F_16 ( V_16 , L_198 ) ;
return - V_362 ;
}
V_40 -> V_309 = * V_309 ;
V_40 -> V_89 = V_356 ;
V_10 = & V_40 -> V_10 ;
F_137 ( V_10 , V_16 , & V_363 ) ;
V_10 -> V_23 |= V_364 ;
V_40 -> V_54 = V_309 -> V_54 ;
V_40 -> V_200 = V_309 -> V_201 == V_204 ;
V_40 -> V_169 = true ;
V_359 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
if ( V_359 != 0x2012 ) {
F_67 ( V_10 , L_199 , V_359 ) ;
V_359 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
}
if ( V_359 != 0x2012 ) {
F_67 ( V_10 , L_200 ,
V_16 -> V_22 << 1 , V_359 ) ;
return - V_347 ;
}
if ( V_309 -> V_365 )
F_54 ( V_10 ) ;
V_3 = & V_40 -> V_3 ;
F_138 ( V_3 , 6 ) ;
F_139 ( V_3 , & V_366 ,
V_132 , - 128 , 127 , 1 , 0 ) ;
F_139 ( V_3 , & V_366 ,
V_133 , 0 , 255 , 1 , 128 ) ;
F_139 ( V_3 , & V_366 ,
V_134 , 0 , 255 , 1 , 128 ) ;
F_139 ( V_3 , & V_366 ,
V_135 , 0 , 128 , 1 , 0 ) ;
V_40 -> V_84 = F_139 ( V_3 , NULL ,
V_367 , 0 , 3 , 0 , 0 ) ;
V_40 -> V_368 = F_140 ( V_3 ,
& V_369 , NULL ) ;
V_40 -> V_370 = F_140 ( V_3 ,
& V_371 , NULL ) ;
V_40 -> V_372 = F_140 ( V_3 ,
& V_373 , NULL ) ;
V_40 -> V_374 =
F_141 ( V_3 , & V_366 ,
V_145 , V_130 ,
0 , V_126 ) ;
V_10 -> V_340 = V_3 ;
if ( V_3 -> error ) {
V_30 = V_3 -> error ;
goto V_375;
}
V_40 -> V_84 -> V_376 = true ;
V_40 -> V_374 -> V_376 = true ;
V_40 -> V_368 -> V_376 = true ;
V_40 -> V_370 -> V_376 = true ;
V_40 -> V_372 -> V_376 = true ;
if ( F_70 ( V_10 ) ) {
V_30 = - V_347 ;
goto V_375;
}
if ( F_132 ( V_10 ) < 0 ) {
V_30 = - V_362 ;
F_76 ( V_10 , L_201 ) ;
goto V_377;
}
V_40 -> V_72 = F_142 ( V_16 -> V_180 ) ;
if ( ! V_40 -> V_72 ) {
F_76 ( V_10 , L_202 ) ;
V_30 = - V_362 ;
goto V_377;
}
F_143 ( & V_40 -> V_65 ,
F_60 ) ;
V_40 -> V_166 . V_23 = V_378 ;
V_30 = F_144 ( & V_10 -> V_379 , 1 , & V_40 -> V_166 , 0 ) ;
if ( V_30 )
goto V_380;
V_30 = F_122 ( V_10 ) ;
if ( V_30 )
goto V_381;
F_67 ( V_10 , L_203 , V_16 -> V_180 ,
V_16 -> V_22 << 1 , V_16 -> V_21 -> V_180 ) ;
return 0 ;
V_381:
F_145 ( & V_10 -> V_379 ) ;
V_380:
F_146 ( & V_40 -> V_65 ) ;
F_147 ( V_40 -> V_72 ) ;
V_377:
F_128 ( V_10 ) ;
V_375:
F_148 ( V_3 ) ;
return V_30 ;
}
static int F_149 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = F_150 ( V_16 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_108 ( V_10 , false ) ;
F_146 ( & V_40 -> V_65 ) ;
F_147 ( V_40 -> V_72 ) ;
F_151 ( V_10 ) ;
F_145 ( & V_10 -> V_379 ) ;
F_128 ( V_10 ) ;
F_148 ( V_10 -> V_340 ) ;
return 0 ;
}
