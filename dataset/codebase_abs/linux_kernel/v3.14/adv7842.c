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
return V_40 -> V_54 == V_55 ;
}
static inline const struct V_56 *
F_58 ( struct V_9 * V_10 )
{
return F_57 ( V_10 ) ? & V_57 :
& V_58 ;
}
static void F_59 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_60 ( V_60 ) ;
struct V_8 * V_40 = F_4 ( V_62 ,
struct V_8 , V_63 ) ;
struct V_9 * V_10 = & V_40 -> V_10 ;
int V_64 = V_40 -> V_65 . V_64 ;
T_2 V_39 = 0 ;
F_55 ( 2 , V_52 , V_10 , L_6 ,
V_53 , V_64 ) ;
if ( V_64 & ( 0x04 << V_66 ) )
V_39 |= 0x20 ;
if ( V_64 & ( 0x04 << V_67 ) )
V_39 |= 0x10 ;
F_24 ( V_10 , 0x20 , 0xcf , V_39 ) ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_68 . V_69 ;
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
F_62 ( V_40 -> V_70 ,
& V_40 -> V_63 , V_71 / 5 ) ;
return 0 ;
}
static int F_63 ( const T_2 * V_69 )
{
T_2 V_72 ;
if ( ( V_69 [ 0x7e ] != 1 ) ||
( V_69 [ 0x80 ] != 0x02 ) ||
( V_69 [ 0x81 ] != 0x03 ) ) {
return - V_73 ;
}
V_72 = V_69 [ 0x82 ] & 0x7f ;
if ( V_72 > 4 ) {
int V_4 = 0x84 ;
int V_74 = 0x80 + V_72 ;
do {
T_2 V_75 = V_69 [ V_4 ] >> 5 ;
T_2 V_76 = V_69 [ V_4 ] & 0x1f ;
if ( ( V_75 == 3 ) && ( V_76 >= 5 ) )
return V_4 + 4 ;
V_4 += V_76 + 1 ;
} while ( V_4 < V_74 );
}
return - V_73 ;
}
static int F_64 ( struct V_9 * V_10 , T_2 V_77 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_65 . V_69 ;
int V_78 = F_63 ( V_38 ) ;
int V_30 = 0 ;
int V_4 ;
F_55 ( 2 , V_52 , V_10 , L_9 ,
V_53 , ( V_77 == V_66 ) ? 'A' : 'B' , V_78 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_43 ( V_10 , 0x77 , 0xf3 , 0x00 ) ;
if ( ! V_40 -> V_65 . V_64 )
return 0 ;
F_43 ( V_10 , 0x77 , 0xef , 0x00 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_20 ( V_40 -> V_48 , V_4 ,
V_34 , V_38 + V_4 ) ;
if ( V_30 )
return V_30 ;
if ( V_78 < 0 )
V_78 = 0xc0 ;
if ( V_77 == V_66 ) {
F_42 ( V_10 , 0x72 , V_38 [ V_78 ] ) ;
F_42 ( V_10 , 0x73 , V_38 [ V_78 + 1 ] ) ;
} else {
F_42 ( V_10 , 0x74 , V_38 [ V_78 ] ) ;
F_42 ( V_10 , 0x75 , V_38 [ V_78 + 1 ] ) ;
}
F_42 ( V_10 , 0x76 , V_78 & 0xff ) ;
F_43 ( V_10 , 0x77 , 0xbf , ( V_78 >> 2 ) & 0x40 ) ;
F_43 ( V_10 , 0x77 , 0xf3 , V_40 -> V_65 . V_64 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_41 ( V_10 , 0x7d ) & V_40 -> V_65 . V_64 )
break;
F_56 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_16 ( V_16 , L_10 ,
( V_77 == V_66 ) ? 'A' : 'B' ) ;
return - V_27 ;
}
F_62 ( V_40 -> V_70 ,
& V_40 -> V_63 , V_71 / 5 ) ;
return 0 ;
}
static void F_65 ( struct V_9 * V_10 )
{
F_66 ( V_10 , L_11 ) ;
F_66 ( V_10 , L_12 ) ;
F_66 ( V_10 , L_13 ) ;
F_66 ( V_10 , L_14 ) ;
F_66 ( V_10 , L_15 ) ;
F_66 ( V_10 , L_16 ) ;
F_66 ( V_10 , L_17 ) ;
F_66 ( V_10 , L_18 ) ;
F_66 ( V_10 , L_19 ) ;
F_66 ( V_10 , L_20 ) ;
F_66 ( V_10 , L_21 ) ;
F_66 ( V_10 , L_22 ) ;
}
static int F_67 ( struct V_9 * V_10 ,
struct V_79 * V_37 )
{
V_37 -> V_80 = 1 ;
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
F_66 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_65 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_68 ( struct V_9 * V_10 ,
const struct V_79 * V_37 )
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
F_66 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_65 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_69 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_81 = F_70 ( V_40 -> V_82 ) ;
T_2 V_83 = F_21 ( V_10 , 0x6f ) ;
int V_38 = 0 ;
if ( V_83 & 0x02 )
V_38 |= 1 ;
if ( V_83 & 0x01 )
V_38 |= 2 ;
F_55 ( 1 , V_52 , V_10 , L_24 , V_53 , V_81 , V_38 ) ;
if ( V_38 != V_81 )
return F_71 ( V_40 -> V_82 , V_38 ) ;
return 0 ;
}
static int F_72 ( struct V_9 * V_10 ,
T_2 V_84 ,
const struct V_85 * V_86 ,
const struct V_1 * V_87 )
{
int V_4 ;
for ( V_4 = 0 ; V_86 [ V_4 ] . V_87 . V_6 . V_7 ; V_4 ++ ) {
if ( ! F_2 ( V_87 , & V_86 [ V_4 ] . V_87 ,
F_57 ( V_10 ) ? 250000 : 1000000 ) )
continue;
F_23 ( V_10 , 0x00 , V_86 [ V_4 ] . V_88 ) ;
F_23 ( V_10 , 0x01 , ( V_86 [ V_4 ] . V_89 << 4 ) + V_84 ) ;
return 0 ;
}
return - 1 ;
}
static int F_73 ( struct V_9 * V_10 ,
struct V_1 * V_87 )
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
case V_90 :
case V_91 :
V_30 = F_72 ( V_10 ,
0x01 , V_92 , V_87 ) ;
if ( V_30 )
V_30 = F_72 ( V_10 ,
0x02 , V_93 , V_87 ) ;
break;
case V_55 :
V_30 = F_72 ( V_10 ,
0x05 , V_94 , V_87 ) ;
if ( V_30 )
V_30 = F_72 ( V_10 ,
0x06 , V_95 , V_87 ) ;
break;
default:
F_55 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
V_30 = - 1 ;
break;
}
return V_30 ;
}
static void F_74 ( struct V_9 * V_10 ,
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
case V_90 :
case V_91 :
F_23 ( V_10 , 0x00 , 0x07 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_51 ( V_10 , 0x81 , 0xef , 0x10 ) ;
if ( F_20 ( V_16 , 0x16 , 2 , V_110 ) ) {
F_75 ( V_10 , L_27 ) ;
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
case V_55 :
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
static void F_76 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_55 ( 2 , V_52 , V_10 , L_28 ,
V_53 , V_40 -> V_111 ) ;
switch ( V_40 -> V_111 ) {
case V_112 :
if ( V_40 -> V_54 == V_91 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
break;
}
if ( V_40 -> V_54 == V_90 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( F_46 ( V_10 , 0x05 ) & 0x80 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_40 -> V_87 . V_6 . V_113 & V_114 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
}
break;
case V_115 :
if ( V_40 -> V_54 == V_90 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x20 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
}
break;
case V_116 :
if ( V_40 -> V_54 == V_90 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x60 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
}
break;
}
}
static int F_77 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_12 -> V_117 ) {
case V_118 :
F_50 ( V_10 , 0x3c , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x14 , V_12 -> V_38 ) ;
return 0 ;
case V_119 :
F_50 ( V_10 , 0x3a , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x13 , V_12 -> V_38 ) ;
return 0 ;
case V_120 :
F_50 ( V_10 , 0x3b , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x15 , V_12 -> V_38 ) ;
return 0 ;
case V_121 :
F_50 ( V_10 , 0x3d , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x16 , V_12 -> V_38 ) ;
return 0 ;
case V_122 :
F_39 ( V_10 , 0xc8 , V_12 -> V_38 ) ;
return 0 ;
case V_123 :
F_51 ( V_10 , 0xbf , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
F_37 ( V_10 , 0xdd , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
return 0 ;
case V_124 : {
T_2 V_125 = ( V_12 -> V_38 & 0xff0000 ) >> 16 ;
T_2 V_126 = ( V_12 -> V_38 & 0x00ff00 ) >> 8 ;
T_2 V_127 = ( V_12 -> V_38 & 0x0000ff ) ;
int V_128 = 66 * V_125 + 129 * V_126 + 25 * V_127 ;
int V_129 = - 38 * V_125 - 74 * V_126 + 112 * V_127 ;
int V_130 = 112 * V_125 - 94 * V_126 - 18 * V_127 ;
V_128 = ( V_128 + 128 ) >> 8 ;
V_129 = ( V_129 + 128 ) >> 8 ;
V_130 = ( V_130 + 128 ) >> 8 ;
V_128 += 16 ;
V_129 += 128 ;
V_130 += 128 ;
F_55 ( 1 , V_52 , V_10 , L_29 , V_125 , V_126 , V_127 ) ;
F_55 ( 1 , V_52 , V_10 , L_30 , V_128 , V_129 , V_130 ) ;
F_50 ( V_10 , 0xc1 , V_125 ) ;
F_50 ( V_10 , 0xc0 , V_126 ) ;
F_50 ( V_10 , 0xc2 , V_127 ) ;
F_36 ( V_10 , 0xde , V_128 ) ;
F_36 ( V_10 , 0xdf , ( V_130 & 0xf0 ) | ( ( V_129 >> 4 ) & 0x0f ) ) ;
return 0 ;
}
case V_131 :
V_40 -> V_111 = V_12 -> V_38 ;
F_76 ( V_10 ) ;
return 0 ;
}
return - V_73 ;
}
static inline bool F_78 ( struct V_9 * V_10 )
{
return F_21 ( V_10 , 0x0c ) & 0x24 ;
}
static inline bool F_79 ( struct V_9 * V_10 )
{
return ( ( F_49 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ) || ! ( F_49 ( V_10 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_80 ( struct V_9 * V_10 )
{
return F_46 ( V_10 , 0x05 ) & 0x80 ;
}
static int F_81 ( struct V_9 * V_10 , T_3 * V_132 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
* V_132 = 0 ;
if ( F_21 ( V_10 , 0x0c ) & 0x24 )
* V_132 |= V_133 ;
if ( V_40 -> V_54 == V_134 ) {
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) )
* V_132 |= V_135 ;
F_55 ( 1 , V_52 , V_10 , L_31 ,
V_53 , * V_132 ) ;
return 0 ;
}
if ( ( F_49 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ||
! ( F_49 ( V_10 , 0xb1 ) & 0x80 ) )
* V_132 |= V_135 ;
if ( F_57 ( V_10 ) && ( ( F_21 ( V_10 , 0x74 ) & 0x03 ) != 0x03 ) )
* V_132 |= V_135 ;
F_55 ( 1 , V_52 , V_10 , L_32 ,
V_53 , * V_132 ) ;
return 0 ;
}
static int F_82 ( struct V_9 * V_10 ,
struct V_136 * V_137 ,
struct V_1 * V_87 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_3 V_138 = ( V_109 * 8 ) / V_137 -> V_139 ;
T_3 V_140 ;
int V_4 ;
for ( V_4 = 0 ; V_141 [ V_4 ] . V_6 . V_7 ; V_4 ++ ) {
const struct V_14 * V_6 = & V_141 [ V_4 ] . V_6 ;
if ( ! F_83 ( & V_141 [ V_4 ] ,
F_58 ( V_10 ) ,
F_1 , NULL ) )
continue;
if ( F_12 ( V_6 ) != V_137 -> V_142 + 1 )
continue;
if ( V_6 -> V_105 != V_137 -> V_143 )
continue;
V_140 = V_138 * F_8 ( V_6 ) ;
if ( ( V_140 < V_6 -> V_108 + 1000000 ) &&
( V_140 > V_6 -> V_108 - 1000000 ) ) {
* V_87 = V_141 [ V_4 ] ;
return 0 ;
}
}
if ( F_84 ( V_137 -> V_142 + 1 , V_138 , V_137 -> V_143 ,
( V_137 -> V_144 == '+' ? V_145 : 0 ) |
( V_137 -> V_146 == '+' ? V_147 : 0 ) ,
V_87 ) )
return 0 ;
if ( F_85 ( V_137 -> V_142 + 1 , V_138 , V_137 -> V_143 ,
( V_137 -> V_144 == '+' ? V_145 : 0 ) |
( V_137 -> V_146 == '+' ? V_147 : 0 ) ,
V_40 -> V_148 , V_87 ) )
return 0 ;
F_55 ( 2 , V_52 , V_10 ,
L_33 ,
V_53 , V_137 -> V_143 , V_137 -> V_142 , V_137 -> V_139 ,
V_137 -> V_144 , V_137 -> V_146 ) ;
return - 1 ;
}
static int F_86 ( struct V_9 * V_10 , struct V_136 * V_137 )
{
T_3 V_132 ;
F_81 ( V_10 , & V_132 ) ;
if ( V_132 & V_135 ) {
F_55 ( 2 , V_52 , V_10 , L_34 , V_53 ) ;
return - V_149 ;
}
V_137 -> V_139 = ( ( F_49 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_49 ( V_10 , 0xb2 ) ;
V_137 -> V_142 = ( ( F_49 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_49 ( V_10 , 0xb4 ) ;
V_137 -> V_143 = F_49 ( V_10 , 0xb3 ) >> 3 ;
if ( ( F_49 ( V_10 , 0xb5 ) & 0x80 ) && ( ( F_49 ( V_10 , 0xb5 ) & 0x03 ) == 0x01 ) ) {
V_137 -> V_144 = ( ( F_49 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_49 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_137 -> V_146 = ( ( F_49 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_49 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_137 -> V_144 = 'x' ;
V_137 -> V_146 = 'x' ;
}
V_137 -> V_150 = ( F_49 ( V_10 , 0xb1 ) & 0x40 ) ? true : false ;
if ( V_137 -> V_142 < 239 || V_137 -> V_139 < 8 || V_137 -> V_139 == 0x3fff ) {
F_55 ( 2 , V_52 , V_10 , L_35 , V_53 ) ;
return - V_149 ;
}
F_55 ( 2 , V_52 , V_10 ,
L_36 ,
V_53 , V_137 -> V_142 , V_137 -> V_139 , V_137 -> V_143 ,
V_137 -> V_144 , V_137 -> V_146 ,
V_137 -> V_150 ? L_37 : L_38 ) ;
return 0 ;
}
static int F_87 ( struct V_9 * V_10 ,
struct V_151 * V_87 )
{
return F_88 ( V_87 ,
F_58 ( V_10 ) , F_1 , NULL ) ;
}
static int F_89 ( struct V_9 * V_10 ,
struct V_56 * V_152 )
{
* V_152 = * F_58 ( V_10 ) ;
return 0 ;
}
static void F_90 ( struct V_9 * V_10 ,
struct V_1 * V_87 )
{
F_91 ( V_87 , F_58 ( V_10 ) ,
F_57 ( V_10 ) ? 250000 : 1000000 ,
F_1 , NULL ) ;
}
static int F_92 ( struct V_9 * V_10 ,
struct V_1 * V_87 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 = & V_87 -> V_6 ;
struct V_136 V_137 = { 0 } ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 == V_134 )
return - V_153 ;
if ( F_86 ( V_10 , & V_137 ) ) {
V_40 -> V_154 = true ;
F_55 ( 1 , V_52 , V_10 , L_39 , V_53 ) ;
return - V_149 ;
}
V_6 -> V_150 = V_137 . V_150 ?
V_155 : V_156 ;
if ( F_57 ( V_10 ) ) {
T_5 V_157 ;
V_87 -> type = V_158 ;
V_6 -> V_7 = ( F_46 ( V_10 , 0x07 ) & 0x0f ) * 256 + F_46 ( V_10 , 0x08 ) ;
V_6 -> V_96 = ( F_46 ( V_10 , 0x09 ) & 0x0f ) * 256 + F_46 ( V_10 , 0x0a ) ;
V_157 = ( F_46 ( V_10 , 0x06 ) * 1000000 ) +
( ( F_46 ( V_10 , 0x3b ) & 0x30 ) >> 4 ) * 250000 ;
if ( F_80 ( V_10 ) ) {
V_157 = V_157 * 8 / ( ( ( F_46 ( V_10 , 0x0b ) & 0xc0 ) >> 5 ) + 8 ) ;
}
V_6 -> V_108 = V_157 ;
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
V_6 -> V_159 = ( ( F_46 ( V_10 , 0x05 ) & 0x10 ) ? V_147 : 0 ) |
( ( F_46 ( V_10 , 0x05 ) & 0x20 ) ? V_145 : 0 ) ;
if ( V_6 -> V_150 == V_155 ) {
V_6 -> V_96 += ( F_46 ( V_10 , 0x0b ) & 0x0f ) * 256 +
F_46 ( V_10 , 0x0c ) ;
V_6 -> V_160 = ( ( F_46 ( V_10 , 0x2c ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x2d ) ) / 2 ;
V_6 -> V_161 = ( ( F_46 ( V_10 , 0x30 ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x31 ) ) / 2 ;
V_6 -> V_106 = ( ( F_46 ( V_10 , 0x34 ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x35 ) ) / 2 ;
}
F_90 ( V_10 , V_87 ) ;
} else {
if ( ! F_82 ( V_10 , & V_137 , V_87 ) )
goto V_162;
V_137 . V_143 += 1 ;
F_55 ( 1 , V_52 , V_10 , L_40 , V_53 , V_137 . V_143 ) ;
if ( ! F_82 ( V_10 , & V_137 , V_87 ) )
goto V_162;
V_137 . V_143 -= 2 ;
F_55 ( 1 , V_52 , V_10 , L_41 , V_53 , V_137 . V_143 ) ;
if ( F_82 ( V_10 , & V_137 , V_87 ) ) {
if ( V_40 -> V_154 ) {
F_55 ( 1 , V_52 , V_10 , L_42 , V_53 ) ;
F_51 ( V_10 , 0x86 , 0xf9 , 0x00 ) ;
F_51 ( V_10 , 0x86 , 0xf9 , 0x04 ) ;
F_51 ( V_10 , 0x86 , 0xf9 , 0x02 ) ;
V_40 -> V_154 = false ;
return - V_149 ;
}
F_55 ( 1 , V_52 , V_10 , L_43 , V_53 ) ;
return - V_163 ;
}
V_40 -> V_154 = true ;
}
V_162:
if ( V_52 > 1 )
F_93 ( V_10 -> V_164 , L_44 ,
V_87 , true ) ;
return 0 ;
}
static int F_94 ( struct V_9 * V_10 ,
struct V_1 * V_87 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 ;
int V_30 ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 == V_134 )
return - V_153 ;
if ( F_2 ( & V_40 -> V_87 , V_87 , 0 ) ) {
F_55 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return 0 ;
}
V_6 = & V_87 -> V_6 ;
if ( ! F_83 ( V_87 , F_58 ( V_10 ) ,
F_1 , NULL ) )
return - V_163 ;
F_90 ( V_10 , V_87 ) ;
V_40 -> V_87 = * V_87 ;
F_50 ( V_10 , 0x91 , V_6 -> V_150 ? 0x40 : 0x00 ) ;
V_30 = F_73 ( V_10 , V_87 ) ;
if ( V_30 ) {
F_74 ( V_10 , V_6 ) ;
}
F_76 ( V_10 ) ;
if ( V_52 > 1 )
F_93 ( V_10 -> V_164 , L_46 ,
V_87 , true ) ;
return 0 ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_1 * V_87 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_54 == V_134 )
return - V_153 ;
* V_87 = V_40 -> V_87 ;
return 0 ;
}
static void F_96 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_76 ( V_10 ) ;
switch ( V_40 -> V_54 ) {
case V_134 :
case V_90 :
case V_91 :
F_23 ( V_10 , 0x15 , 0xb0 ) ;
break;
case V_55 :
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
static void F_97 ( struct V_9 * V_10 )
{
F_48 ( V_10 , 0x1a , 0xef , 0x10 ) ;
F_98 ( 16 ) ;
F_23 ( V_10 , 0x15 , 0xbe ) ;
F_47 ( V_10 , 0x01 , 0x78 ) ;
}
static void F_99 ( struct V_9 * V_10 ,
const struct V_165 * V_166 )
{
F_34 ( V_10 , 0xe0 , 0xbf , V_166 -> V_167 ? 0x00 : 0x40 ) ;
if ( ! V_166 -> V_167 )
return;
F_34 ( V_10 , 0xe0 , 0x7f , V_166 -> V_168 == 2 ? 0x80 : 0x00 ) ;
F_34 ( V_10 , 0xe0 , 0xe0 , V_166 -> V_169 >> 8 ) ;
F_33 ( V_10 , 0xe1 , V_166 -> V_169 ) ;
F_34 ( V_10 , 0xe2 , 0xe0 , V_166 -> V_170 >> 8 ) ;
F_33 ( V_10 , 0xe3 , V_166 -> V_170 ) ;
F_34 ( V_10 , 0xe4 , 0xe0 , V_166 -> V_171 >> 8 ) ;
F_33 ( V_10 , 0xe5 , V_166 -> V_171 ) ;
F_34 ( V_10 , 0xe6 , 0x80 , V_166 -> V_172 >> 8 ) ;
F_33 ( V_10 , 0xe7 , V_166 -> V_172 ) ;
F_34 ( V_10 , 0xe8 , 0xe0 , V_166 -> V_173 >> 8 ) ;
F_33 ( V_10 , 0xe9 , V_166 -> V_173 ) ;
F_34 ( V_10 , 0xea , 0xe0 , V_166 -> V_174 >> 8 ) ;
F_33 ( V_10 , 0xeb , V_166 -> V_174 ) ;
F_34 ( V_10 , 0xec , 0xe0 , V_166 -> V_175 >> 8 ) ;
F_33 ( V_10 , 0xed , V_166 -> V_175 ) ;
F_34 ( V_10 , 0xee , 0x80 , V_166 -> V_176 >> 8 ) ;
F_33 ( V_10 , 0xef , V_166 -> V_176 ) ;
F_34 ( V_10 , 0xf0 , 0xe0 , V_166 -> V_177 >> 8 ) ;
F_33 ( V_10 , 0xf1 , V_166 -> V_177 ) ;
F_34 ( V_10 , 0xf2 , 0xe0 , V_166 -> V_178 >> 8 ) ;
F_33 ( V_10 , 0xf3 , V_166 -> V_178 ) ;
F_34 ( V_10 , 0xf4 , 0xe0 , V_166 -> V_179 >> 8 ) ;
F_33 ( V_10 , 0xf5 , V_166 -> V_179 ) ;
F_34 ( V_10 , 0xf6 , 0x80 , V_166 -> V_180 >> 8 ) ;
F_33 ( V_10 , 0xf7 , V_166 -> V_180 ) ;
}
static void F_100 ( struct V_9 * V_10 ,
enum V_181 V_182 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_40 -> V_54 ) {
case V_134 :
F_23 ( V_10 , 0x00 , V_182 ) ;
F_23 ( V_10 , 0x01 , 0 ) ;
F_51 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_39 ( V_10 , 0x00 , 0x00 ) ;
F_39 ( V_10 , 0xc8 , 0x00 ) ;
F_23 ( V_10 , 0xdd , 0x90 ) ;
F_40 ( V_10 , 0x02 , 0x7f , 0x80 ) ;
if ( V_182 == V_183 ) {
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
case V_90 :
case V_91 :
F_40 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
F_23 ( V_10 , 0x00 , V_182 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_51 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_39 ( V_10 , 0x00 , 0x00 ) ;
F_39 ( V_10 , 0xc8 , 0x00 ) ;
if ( V_40 -> V_54 == V_90 ) {
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
case V_55 :
F_40 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
if ( V_40 -> V_184 )
F_47 ( V_10 , 0x00 , 0x02 ) ;
else
F_47 ( V_10 , 0x00 , 0x03 ) ;
F_23 ( V_10 , 0x00 , V_182 ) ;
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
F_50 ( V_10 , 0x3e , 0x80 ) ;
F_50 ( V_10 , 0xc3 , 0x33 ) ;
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
default:
F_55 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
}
static int F_101 ( struct V_9 * V_10 ,
T_3 V_185 , T_3 V_186 , T_3 V_187 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_55 ( 2 , V_52 , V_10 , L_47 , V_53 , V_185 ) ;
switch ( V_185 ) {
case V_188 :
V_40 -> V_54 = V_55 ;
V_40 -> V_182 = V_189 ;
V_40 -> V_184 = true ;
break;
case V_190 :
V_40 -> V_54 = V_55 ;
V_40 -> V_182 = V_189 ;
V_40 -> V_184 = false ;
break;
case V_191 :
V_40 -> V_54 = V_90 ;
V_40 -> V_182 = V_192 ;
break;
case V_193 :
V_40 -> V_54 = V_91 ;
V_40 -> V_182 = V_192 ;
break;
case V_194 :
V_40 -> V_54 = V_134 ;
V_40 -> V_182 = V_183 ;
break;
case V_195 :
V_40 -> V_54 = V_134 ;
V_40 -> V_182 = V_196 ;
break;
default:
return - V_73 ;
}
F_97 ( V_10 ) ;
F_100 ( V_10 , V_40 -> V_182 ) ;
F_96 ( V_10 ) ;
F_102 ( V_10 , V_197 , NULL ) ;
return 0 ;
}
static int F_103 ( struct V_9 * V_10 , unsigned int V_198 ,
enum V_199 * V_200 )
{
if ( V_198 )
return - V_73 ;
* V_200 = V_201 ;
return 0 ;
}
static int F_104 ( struct V_9 * V_10 ,
struct V_202 * V_203 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
V_203 -> V_7 = V_40 -> V_87 . V_6 . V_7 ;
V_203 -> V_96 = V_40 -> V_87 . V_6 . V_96 ;
V_203 -> V_200 = V_201 ;
V_203 -> V_204 = V_205 ;
if ( V_40 -> V_54 == V_134 ) {
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) )
return - V_73 ;
V_203 -> V_7 = 720 ;
if ( V_40 -> V_206 & V_207 )
V_203 -> V_96 = 480 ;
else
V_203 -> V_96 = 576 ;
V_203 -> V_208 = V_209 ;
return 0 ;
}
if ( V_40 -> V_87 . V_6 . V_113 & V_114 ) {
V_203 -> V_208 = ( V_40 -> V_87 . V_6 . V_96 <= 576 ) ?
V_209 : V_210 ;
}
return 0 ;
}
static void F_105 ( struct V_9 * V_10 , bool V_211 )
{
if ( V_211 ) {
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
static int F_106 ( struct V_9 * V_10 , T_3 V_132 , bool * V_212 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_213 , V_214 , V_215 ;
T_2 V_216 [ 6 ] ;
F_105 ( V_10 , false ) ;
V_216 [ 0 ] = F_21 ( V_10 , 0x43 ) ;
V_216 [ 1 ] = F_21 ( V_10 , 0x57 ) ;
V_216 [ 2 ] = F_21 ( V_10 , 0x70 ) ;
V_216 [ 3 ] = F_21 ( V_10 , 0x75 ) ;
V_216 [ 4 ] = F_21 ( V_10 , 0x9d ) ;
V_216 [ 5 ] = F_21 ( V_10 , 0x66 ) ;
if ( V_216 [ 0 ] )
F_23 ( V_10 , 0x44 , V_216 [ 0 ] ) ;
if ( V_216 [ 1 ] )
F_23 ( V_10 , 0x58 , V_216 [ 1 ] ) ;
if ( V_216 [ 2 ] )
F_23 ( V_10 , 0x71 , V_216 [ 2 ] ) ;
if ( V_216 [ 3 ] )
F_23 ( V_10 , 0x76 , V_216 [ 3 ] ) ;
if ( V_216 [ 4 ] )
F_23 ( V_10 , 0x9e , V_216 [ 4 ] ) ;
if ( V_216 [ 5 ] )
F_23 ( V_10 , 0x67 , V_216 [ 5 ] ) ;
F_105 ( V_10 , true ) ;
F_55 ( 1 , V_52 , V_10 , L_48 , V_53 ,
V_216 [ 0 ] , V_216 [ 1 ] , V_216 [ 2 ] ,
V_216 [ 3 ] , V_216 [ 4 ] , V_216 [ 5 ] ) ;
V_213 = V_216 [ 0 ] & 0x9c ;
if ( V_40 -> V_54 == V_134 )
V_215 = ( V_216 [ 1 ] & 0x30 ) | ( V_216 [ 4 ] & 0x09 ) ;
else
V_215 = 0 ;
if ( F_57 ( V_10 ) )
V_214 = V_216 [ 3 ] & 0x03 ;
else
V_214 = 0 ;
if ( V_213 || V_214 || V_215 ) {
F_55 ( 1 , V_52 , V_10 ,
L_49 ,
V_53 , V_213 , V_214 ,
V_215 ) ;
F_102 ( V_10 , V_197 , NULL ) ;
if ( V_212 )
* V_212 = true ;
}
if ( V_216 [ 5 ] & 0x08 ) {
F_55 ( 1 , V_52 , V_10 , L_50 , V_53 ,
( F_21 ( V_10 , 0x65 ) & 0x08 ) ? L_51 : L_52 ) ;
if ( V_212 )
* V_212 = true ;
}
if ( V_216 [ 2 ] & 0x3 ) {
F_55 ( 1 , V_52 , V_10 , L_53 , V_53 ) ;
F_69 ( V_10 ) ;
if ( V_212 )
* V_212 = true ;
}
return 0 ;
}
static int F_107 ( struct V_9 * V_10 , struct V_217 * V_69 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 * V_20 = NULL ;
if ( V_69 -> V_218 > V_219 )
return - V_73 ;
if ( V_69 -> V_220 == 0 )
return - V_73 ;
if ( V_69 -> V_220 > 2 )
return - V_73 ;
if ( V_69 -> V_221 > 1 )
return - V_73 ;
if ( V_69 -> V_221 == 1 )
V_69 -> V_220 = 1 ;
if ( ! V_69 -> V_69 )
return - V_73 ;
switch ( V_69 -> V_218 ) {
case V_66 :
case V_67 :
if ( V_40 -> V_65 . V_64 & ( 0x04 << V_69 -> V_218 ) )
V_20 = V_40 -> V_65 . V_69 ;
break;
case V_219 :
if ( V_40 -> V_68 . V_64 )
V_20 = V_40 -> V_68 . V_69 ;
break;
default:
return - V_73 ;
}
if ( ! V_20 )
return - V_153 ;
memcpy ( V_69 -> V_69 ,
V_20 + V_69 -> V_221 * 128 ,
V_69 -> V_220 * 128 ) ;
return 0 ;
}
static int F_108 ( struct V_9 * V_10 , struct V_217 * V_222 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 = 0 ;
if ( V_222 -> V_218 > V_219 )
return - V_73 ;
if ( V_222 -> V_221 != 0 )
return - V_73 ;
if ( V_222 -> V_220 > 2 )
return - V_223 ;
if ( ! V_222 -> V_69 )
return - V_73 ;
V_40 -> V_148 = F_109 ( V_222 -> V_69 [ 0x15 ] ,
V_222 -> V_69 [ 0x16 ] ) ;
switch ( V_222 -> V_218 ) {
case V_219 :
memset ( & V_40 -> V_68 . V_69 , 0 , 256 ) ;
V_40 -> V_68 . V_64 = V_222 -> V_220 ? 0x1 : 0x0 ;
memcpy ( & V_40 -> V_68 . V_69 , V_222 -> V_69 , 128 * V_222 -> V_220 ) ;
V_30 = F_61 ( V_10 ) ;
break;
case V_66 :
case V_67 :
memset ( & V_40 -> V_65 . V_69 , 0 , 256 ) ;
if ( V_222 -> V_220 )
V_40 -> V_65 . V_64 |= 0x04 << V_222 -> V_218 ;
else
V_40 -> V_65 . V_64 &= ~ ( 0x04 << V_222 -> V_218 ) ;
memcpy ( & V_40 -> V_65 . V_69 , V_222 -> V_69 , 128 * V_222 -> V_220 ) ;
V_30 = F_64 ( V_10 , V_222 -> V_218 ) ;
break;
default:
return - V_73 ;
}
if ( V_30 < 0 )
F_75 ( V_10 , L_54 , V_30 , V_222 -> V_218 ) ;
return V_30 ;
}
static void F_110 ( struct V_9 * V_10 , T_6 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> V_227 = ( V_224 [ 1 ] >> 7 ) & 0x1 ;
V_226 -> V_228 = ( V_224 [ 1 ] >> 5 ) & 0x3 ;
V_226 -> V_229 = ( V_224 [ 1 ] >> 4 ) & 0x1 ;
V_226 -> V_230 = ( V_224 [ 1 ] >> 2 ) & 0x3 ;
V_226 -> V_231 = V_224 [ 1 ] & 0x3 ;
V_226 -> V_232 = ( V_224 [ 2 ] >> 6 ) & 0x3 ;
V_226 -> V_233 = ( V_224 [ 2 ] >> 4 ) & 0x3 ;
V_226 -> V_234 = V_224 [ 2 ] & 0xf ;
V_226 -> V_235 = ( V_224 [ 3 ] >> 7 ) & 0x1 ;
V_226 -> V_236 = ( V_224 [ 3 ] >> 4 ) & 0x7 ;
V_226 -> V_237 = ( V_224 [ 3 ] >> 2 ) & 0x3 ;
V_226 -> V_238 = V_224 [ 3 ] & 0x3 ;
V_226 -> V_239 = ( V_224 [ 4 ] >> 7 ) & 0x1 ;
V_226 -> V_240 = V_224 [ 4 ] & 0x7f ;
V_226 -> V_241 = ( V_224 [ 5 ] >> 6 ) & 0x3 ;
V_226 -> V_242 = ( V_224 [ 5 ] >> 4 ) & 0x3 ;
V_226 -> V_243 = V_224 [ 5 ] & 0xf ;
V_226 -> V_244 = V_224 [ 6 ] + 256 * V_224 [ 7 ] ;
V_226 -> V_245 = V_224 [ 8 ] + 256 * V_224 [ 9 ] ;
V_226 -> V_246 = V_224 [ 10 ] + 256 * V_224 [ 11 ] ;
V_226 -> V_247 = V_224 [ 12 ] + 256 * V_224 [ 13 ] ;
}
static void F_111 ( struct V_9 * V_10 )
{
int V_4 ;
T_6 V_224 [ 14 ] ;
T_6 V_248 ;
struct V_225 V_226 ;
if ( ! ( F_46 ( V_10 , 0x05 ) & 0x80 ) ) {
F_66 ( V_10 , L_55 ) ;
return;
}
if ( ! ( F_21 ( V_10 , 0x60 ) & 0x01 ) ) {
F_66 ( V_10 , L_56 ) ;
return;
}
if ( F_21 ( V_10 , 0x88 ) & 0x10 ) {
F_66 ( V_10 , L_57 ) ;
return;
}
V_248 = F_30 ( V_10 , 0xe2 ) ;
F_66 ( V_10 , L_58 ,
F_30 ( V_10 , 0xe1 ) , V_248 ) ;
if ( F_30 ( V_10 , 0xe1 ) != 0x02 )
return;
for ( V_4 = 0 ; V_4 < 14 ; V_4 ++ )
V_224 [ V_4 ] = F_30 ( V_10 , V_4 ) ;
F_66 ( V_10 , L_59 ,
V_224 [ 0 ] , V_224 [ 1 ] , V_224 [ 2 ] , V_224 [ 3 ] , V_224 [ 4 ] , V_224 [ 5 ] , V_224 [ 6 ] , V_224 [ 7 ] ,
V_224 [ 8 ] , V_224 [ 9 ] , V_224 [ 10 ] , V_224 [ 11 ] , V_224 [ 12 ] , V_224 [ 13 ] ) ;
F_110 ( V_10 , V_224 , & V_226 ) ;
if ( V_226 . V_240 )
F_66 ( V_10 , L_60 , V_226 . V_240 ) ;
if ( V_226 . V_235 )
F_66 ( V_10 , L_61 , V_249 [ V_226 . V_235 ] ) ;
if ( V_226 . V_228 )
F_66 ( V_10 , L_62 , V_250 [ V_226 . V_228 ] , ! V_226 . V_232 ? L_63 :
( V_226 . V_232 == 0x3 ? V_251 [ V_226 . V_236 ] : V_252 [ V_226 . V_232 ] ) ) ;
else
F_66 ( V_10 , L_62 , V_250 [ V_226 . V_228 ] , V_253 [ V_226 . V_237 ] ) ;
}
static int F_112 ( struct V_9 * V_10 )
{
T_6 V_254 = F_35 ( V_10 , 0x5A ) & 0x01 ;
F_66 ( V_10 , L_64 , F_78 ( V_10 ) ? L_65 : L_66 ) ;
F_66 ( V_10 , L_67 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ) ;
F_66 ( V_10 , L_68 ,
( F_35 ( V_10 , 0x56 ) & 0x01 ) ? L_66 : L_65 ) ;
F_66 ( V_10 , L_69 , V_254 ?
L_70 : L_71 ) ;
if ( V_254 ) {
static const char * const V_255 [] = {
L_72 ,
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 , L_80 , L_81 , L_82 , L_83 ,
L_84 ,
L_85 ,
L_86 ,
L_87
} ;
F_66 ( V_10 , L_88 ,
V_255 [ F_35 ( V_10 , 0x52 ) & 0x0f ] ) ;
F_66 ( V_10 , L_69 ,
( F_35 ( V_10 , 0x59 ) & 0x08 ) ? L_89 : L_90 ) ;
F_66 ( V_10 , L_69 ,
( F_35 ( V_10 , 0x57 ) & 0x08 ) ? L_91 : L_92 ) ;
F_66 ( V_10 , L_93 ,
( F_35 ( V_10 , 0x12 ) & 0x08 ) ? L_94 : L_95 ) ;
F_66 ( V_10 , L_96 ,
( F_32 ( V_10 , 0xe0 ) & 0x40 ) ? L_97 : L_98 ) ;
}
return 0 ;
}
static int F_113 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_1 V_87 ;
T_6 V_256 = F_21 ( V_10 , 0x02 ) ;
T_6 V_257 = F_21 ( V_10 , 0x21 ) ;
T_6 V_258 = F_41 ( V_10 , 0x77 ) ;
T_6 V_259 = F_41 ( V_10 , 0x7d ) ;
bool V_260 = F_46 ( V_10 , 0x04 ) & 0x01 ;
bool V_261 = F_46 ( V_10 , 0x18 ) & 0x01 ;
bool V_262 = F_21 ( V_10 , 0x65 ) & 0x40 ;
static const char * const V_263 [ 16 ] = {
L_99 , L_100 , L_101 , L_102 ,
L_101 , L_103 , L_101 , L_104 ,
L_101 , L_105 , L_106 ,
L_101 , L_101 , L_101 , L_101 , L_98
} ;
static const char * const V_264 [ 16 ] = {
L_107 , L_108 ,
L_109 , L_110 ,
L_111 , L_112 ,
L_113 , L_114 ,
L_115 , L_115 , L_115 , L_115 , L_115 ,
L_115 , L_115 , L_116
} ;
static const char * const V_265 [] = {
L_117 ,
L_107 ,
L_108 ,
} ;
static const char * const V_266 [ 4 ] = {
L_118 ,
L_119 ,
L_120 ,
L_121
} ;
F_66 ( V_10 , L_122 ) ;
F_66 ( V_10 , L_123 , F_78 ( V_10 ) ? L_65 : L_66 ) ;
F_66 ( V_10 , L_124 ,
V_40 -> V_184 ? L_125 : L_126 ) ;
F_66 ( V_10 , L_127 ,
( ( V_259 & 0x04 ) && ( V_258 & 0x04 ) ) ?
L_94 : L_95 ,
( ( V_259 & 0x08 ) && ( V_258 & 0x08 ) ) ?
L_94 : L_95 ) ;
F_66 ( V_10 , L_128 ,
V_257 & 0x02 ? L_94 : L_95 ,
V_257 & 0x01 ? L_94 : L_95 ) ;
F_66 ( V_10 , L_129 , ! ! ( F_27 ( V_10 , 0x2a ) & 0x01 ) ?
L_94 : L_95 ) ;
F_66 ( V_10 , L_130 ) ;
if ( V_40 -> V_184 ) {
F_66 ( V_10 , L_131 ,
F_21 ( V_10 , 0x6f ) & 0x02 ? L_132 : L_133 ) ;
F_66 ( V_10 , L_134 ,
( F_21 ( V_10 , 0x6a ) & 0x02 ) ? L_132 : L_133 ) ;
F_66 ( V_10 , L_135 ,
( F_21 ( V_10 , 0x6a ) & 0x20 ) ? L_132 : L_133 ) ;
} else {
F_66 ( V_10 , L_136 ,
F_21 ( V_10 , 0x6f ) & 0x01 ? L_132 : L_133 ) ;
F_66 ( V_10 , L_134 ,
( F_21 ( V_10 , 0x6a ) & 0x01 ) ? L_132 : L_133 ) ;
F_66 ( V_10 , L_135 ,
( F_21 ( V_10 , 0x6a ) & 0x10 ) ? L_132 : L_133 ) ;
}
F_66 ( V_10 , L_137 ,
( ! ! ( F_49 ( V_10 , 0xff ) & 0x10 ) ? L_66 : L_65 ) ) ;
F_66 ( V_10 , L_138 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ,
( F_21 ( V_10 , 0x01 ) & 0x70 ) >> 4 ) ;
F_66 ( V_10 , L_139 ) ;
if ( F_79 ( V_10 ) ) {
F_66 ( V_10 , L_140 ) ;
} else {
T_5 V_139 = ( ( F_49 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_49 ( V_10 , 0xb2 ) ;
T_5 V_142 = ( ( F_49 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_49 ( V_10 , 0xb4 ) ;
T_5 V_143 = F_49 ( V_10 , 0xb3 ) >> 3 ;
T_5 V_267 = ( ( F_49 ( V_10 , 0xb8 ) & 0x1f ) << 8 ) | F_49 ( V_10 , 0xb9 ) ;
char V_144 = ( ( F_49 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_49 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
char V_146 = ( ( F_49 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_49 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
F_66 ( V_10 ,
L_141 ,
V_142 , V_139 , V_143 , V_267 ,
( F_49 ( V_10 , 0xb1 ) & 0x40 ) ?
L_37 : L_38 ,
V_144 , V_146 ) ;
}
if ( F_92 ( V_10 , & V_87 ) )
F_66 ( V_10 , L_142 ) ;
else
F_93 ( V_10 -> V_164 , L_143 ,
& V_87 , true ) ;
F_93 ( V_10 -> V_164 , L_144 ,
& V_40 -> V_87 , true ) ;
if ( F_79 ( V_10 ) )
return 0 ;
F_66 ( V_10 , L_145 ) ;
F_66 ( V_10 , L_146 ,
V_265 [ V_40 -> V_111 ] ) ;
F_66 ( V_10 , L_147 ,
V_264 [ V_256 >> 4 ] ) ;
F_66 ( V_10 , L_148 ,
( V_256 & 0x02 ) ? L_149 : L_150 ,
( V_256 & 0x04 ) ? L_151 : L_152 ,
( ( V_256 & 0x04 ) ^ ( V_256 & 0x01 ) ) ?
L_94 : L_95 ) ;
F_66 ( V_10 , L_153 ,
V_263 [ F_49 ( V_10 , 0xf4 ) >> 4 ] ) ;
if ( ! F_57 ( V_10 ) )
return 0 ;
F_66 ( V_10 , L_154 , F_80 ( V_10 ) ? L_51 : L_155 ) ;
F_66 ( V_10 , L_156 ,
( F_46 ( V_10 , 0x05 ) & 0x40 ) ? L_132 : L_133 ) ;
F_66 ( V_10 , L_157 ,
( F_46 ( V_10 , 0x04 ) & 0x20 ) ? L_158 : L_159 ,
( F_46 ( V_10 , 0x04 ) & 0x10 ) ? L_160 : L_63 ) ;
if ( ! F_80 ( V_10 ) )
return 0 ;
F_66 ( V_10 , L_161 ,
V_260 ? L_162 : L_163 ,
V_261 ? L_164 : L_165 ,
V_262 ? L_166 : L_94 ) ;
if ( V_260 && V_261 ) {
F_66 ( V_10 , L_167 ,
( F_46 ( V_10 , 0x07 ) & 0x40 ) ? L_168 : L_169 ) ;
}
F_66 ( V_10 , L_170 , ( F_46 ( V_10 , 0x5b ) << 12 ) +
( F_46 ( V_10 , 0x5c ) << 8 ) +
( F_46 ( V_10 , 0x5d ) & 0xf0 ) ) ;
F_66 ( V_10 , L_171 , ( ( F_46 ( V_10 , 0x5d ) & 0x0f ) << 16 ) +
( F_46 ( V_10 , 0x5e ) << 8 ) +
F_46 ( V_10 , 0x5f ) ) ;
F_66 ( V_10 , L_172 ,
( F_46 ( V_10 , 0x04 ) & 0x40 ) ? L_66 : L_65 ) ;
F_66 ( V_10 , L_173 ,
V_266 [ F_46 ( V_10 , 0x0b ) >> 6 ] ) ;
F_111 ( V_10 ) ;
return 0 ;
}
static int F_114 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_54 == V_134 )
return F_112 ( V_10 ) ;
return F_113 ( V_10 ) ;
}
static int F_115 ( struct V_9 * V_10 , T_7 * V_268 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_134 )
return - V_153 ;
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) ) {
* V_268 = 0 ;
F_55 ( 1 , V_52 , V_10 , L_39 , V_53 ) ;
return 0 ;
}
switch ( F_35 ( V_10 , 0x52 ) & 0x0f ) {
case 0 :
* V_268 &= V_269 ;
break;
case 2 :
* V_268 &= V_270 ;
break;
case 3 :
* V_268 &= V_271 ;
break;
case 4 :
* V_268 &= V_272 ;
break;
case 6 :
* V_268 &= V_273 ;
break;
case 0xc :
* V_268 &= V_274 ;
break;
case 0xe :
* V_268 &= V_275 ;
break;
case 0xf :
* V_268 &= V_271 ;
break;
default:
* V_268 &= V_276 ;
break;
}
return 0 ;
}
static void F_116 ( struct V_9 * V_10 , struct V_277 * V_278 )
{
if ( V_278 && V_278 -> V_279 ) {
F_33 ( V_10 , 0x94 , ( V_278 -> V_280 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x95 , V_278 -> V_280 & 0xff ) ;
F_33 ( V_10 , 0x96 , ( V_278 -> V_281 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x97 , V_278 -> V_281 & 0xff ) ;
F_33 ( V_10 , 0x98 , ( V_278 -> V_282 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x99 , V_278 -> V_282 & 0xff ) ;
F_33 ( V_10 , 0x9a , ( V_278 -> V_283 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x9b , V_278 -> V_283 & 0xff ) ;
F_33 ( V_10 , 0xa8 , V_278 -> V_284 ) ;
F_33 ( V_10 , 0xa9 , V_278 -> V_285 ) ;
F_33 ( V_10 , 0xaa , V_278 -> V_286 ) ;
F_33 ( V_10 , 0xab , V_278 -> V_287 ) ;
F_33 ( V_10 , 0xac , V_278 -> V_288 ) ;
F_33 ( V_10 , 0xad , V_278 -> V_289 ) ;
F_33 ( V_10 , 0xae , V_278 -> V_290 ) ;
F_33 ( V_10 , 0xaf , V_278 -> V_291 ) ;
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
static int F_117 ( struct V_9 * V_10 , T_7 V_206 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_292 * V_293 = & V_40 -> V_293 ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_134 )
return - V_153 ;
if ( V_206 & V_294 )
F_116 ( V_10 , & V_293 -> V_295 ) ;
else if ( V_206 & V_207 )
F_116 ( V_10 , & V_293 -> V_296 ) ;
else
F_116 ( V_10 , NULL ) ;
if ( V_206 & V_276 ) {
V_40 -> V_206 = V_206 ;
return 0 ;
}
return - V_73 ;
}
static int F_118 ( struct V_9 * V_10 , T_7 * V_206 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_55 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_134 )
return - V_153 ;
* V_206 = V_40 -> V_206 ;
return 0 ;
}
static int F_119 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_292 * V_293 = & V_40 -> V_293 ;
F_47 ( V_10 , 0x48 ,
( V_293 -> V_297 ? 0x80 : 0 ) |
( V_293 -> V_298 ? 0x40 : 0 ) ) ;
F_97 ( V_10 ) ;
F_23 ( V_10 , 0x0c , 0x42 ) ;
F_23 ( V_10 , 0x15 , 0x80 ) ;
F_23 ( V_10 , 0x02 ,
0xf0 |
V_293 -> V_299 << 3 |
V_293 -> V_300 << 2 |
V_293 -> V_301 << 1 |
V_293 -> V_302 << 0 ) ;
F_23 ( V_10 , 0x03 , V_293 -> V_303 ) ;
F_24 ( V_10 , 0x04 , 0x1f , V_293 -> V_304 << 5 ) ;
F_24 ( V_10 , 0x05 , 0xf0 , V_293 -> V_305 << 3 |
V_293 -> V_306 << 2 |
V_293 -> V_307 << 1 |
V_293 -> V_308 << 0 ) ;
F_48 ( V_10 , 0x1a , 0xf1 , 0x08 ) ;
F_24 ( V_10 , 0x14 , 0xc0 ,
V_293 -> V_309 << 4 |
V_293 -> V_310 << 2 |
V_293 -> V_311 ) ;
F_51 ( V_10 , 0xba , 0xfc , V_293 -> V_312 |
( V_293 -> V_313 << 1 ) ) ;
F_37 ( V_10 , 0xdd , 0xf0 , V_293 -> V_314 |
( V_293 -> V_315 << 1 ) |
( V_293 -> V_316 << 2 ) |
( V_293 -> V_317 << 3 ) ) ;
F_50 ( V_10 , 0x69 , 0x14 ) ;
F_23 ( V_10 , 0x06 , 0xa6 ) ;
F_50 ( V_10 , 0xf3 , 0xdc ) ;
F_39 ( V_10 , 0xb5 , 0x01 ) ;
F_39 ( V_10 , 0x02 , V_293 -> V_318 ) ;
F_24 ( V_10 , 0x30 , ~ ( 1 << 4 ) , V_293 -> V_319 << 4 ) ;
F_99 ( V_10 , & V_293 -> F_99 ) ;
if ( V_293 -> V_320 >= 128 ) {
F_36 ( V_10 , 0x12 , 0x0d ) ;
if ( V_293 -> V_321 ) {
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
F_100 ( V_10 , V_293 -> V_182 ) ;
F_96 ( V_10 ) ;
F_43 ( V_10 , 0x77 , 0xf3 , 0x00 ) ;
F_47 ( V_10 , 0x69 , 0xa3 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_23 ( V_10 , 0x19 , 0x80 | V_293 -> V_322 ) ;
F_23 ( V_10 , 0x33 , 0x40 ) ;
F_23 ( V_10 , 0x40 , 0xf2 ) ;
F_105 ( V_10 , true ) ;
return F_120 ( V_10 -> V_323 ) ;
}
static int F_121 ( struct V_9 * V_10 )
{
int V_4 ;
int V_324 = 0 ;
int V_325 = 0 ;
int V_326 = 0 ;
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
T_2 V_327 = F_32 ( V_10 , 0xdb ) ;
if ( V_327 & 0x10 ) {
V_326 ++ ;
if ( V_327 & 0x20 )
V_325 ++ ;
else
V_324 ++ ;
}
F_56 ( 20 ) ;
}
F_55 ( 1 , V_52 , V_10 ,
L_174 ,
V_326 , V_4 , V_324 , V_325 ) ;
if ( ! V_326 || V_325 )
return - V_27 ;
return 0 ;
}
static void F_122 ( struct V_9 * V_10 ,
struct V_292 * V_293 )
{
F_23 ( V_10 , 0xf1 , V_293 -> V_45 << 1 ) ;
F_23 ( V_10 , 0xf2 , V_293 -> V_44 << 1 ) ;
F_23 ( V_10 , 0xf3 , V_293 -> V_41 << 1 ) ;
F_23 ( V_10 , 0xf4 , V_293 -> V_42 << 1 ) ;
F_23 ( V_10 , 0xf5 , V_293 -> V_43 << 1 ) ;
F_23 ( V_10 , 0xf8 , V_293 -> V_46 << 1 ) ;
F_23 ( V_10 , 0xf9 , V_293 -> V_47 << 1 ) ;
F_23 ( V_10 , 0xfa , V_293 -> V_48 << 1 ) ;
F_23 ( V_10 , 0xfb , V_293 -> V_49 << 1 ) ;
F_23 ( V_10 , 0xfd , V_293 -> V_50 << 1 ) ;
F_23 ( V_10 , 0xfe , V_293 -> V_51 << 1 ) ;
}
static int F_123 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_292 * V_293 = V_16 -> V_328 . V_329 ;
struct V_1 V_87 ;
int V_28 = 0 ;
if ( ! V_293 )
return - V_330 ;
if ( ! V_293 -> V_320 || ! V_293 -> V_321 ) {
F_66 ( V_10 , L_175 ) ;
return - V_73 ;
}
F_54 ( V_10 ) ;
F_122 ( V_10 , V_293 ) ;
V_28 = F_121 ( V_10 ) ;
F_54 ( V_10 ) ;
F_122 ( V_10 , V_293 ) ;
F_119 ( V_10 ) ;
F_97 ( V_10 ) ;
F_100 ( V_10 , V_40 -> V_182 ) ;
F_96 ( V_10 ) ;
F_61 ( V_10 ) ;
F_64 ( V_10 , V_66 ) ;
F_64 ( V_10 , V_67 ) ;
V_87 = V_40 -> V_87 ;
memset ( & V_40 -> V_87 , 0 , sizeof( struct V_1 ) ) ;
F_94 ( V_10 , & V_87 ) ;
return V_28 ;
}
static long F_124 ( struct V_9 * V_10 , unsigned int V_331 , void * V_332 )
{
switch ( V_331 ) {
case V_333 :
return F_123 ( V_10 ) ;
}
return - V_334 ;
}
static void F_125 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_41 )
F_126 ( V_40 -> V_41 ) ;
if ( V_40 -> V_42 )
F_126 ( V_40 -> V_42 ) ;
if ( V_40 -> V_43 )
F_126 ( V_40 -> V_43 ) ;
if ( V_40 -> V_44 )
F_126 ( V_40 -> V_44 ) ;
if ( V_40 -> V_45 )
F_126 ( V_40 -> V_45 ) ;
if ( V_40 -> V_46 )
F_126 ( V_40 -> V_46 ) ;
if ( V_40 -> V_47 )
F_126 ( V_40 -> V_47 ) ;
if ( V_40 -> V_48 )
F_126 ( V_40 -> V_48 ) ;
if ( V_40 -> V_49 )
F_126 ( V_40 -> V_49 ) ;
if ( V_40 -> V_50 )
F_126 ( V_40 -> V_50 ) ;
if ( V_40 -> V_51 )
F_126 ( V_40 -> V_51 ) ;
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
static struct V_15 * F_127 ( struct V_9 * V_10 , const char * V_335 ,
T_2 V_22 , T_2 V_336 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_15 * V_337 ;
F_23 ( V_10 , V_336 , V_22 << 1 ) ;
if ( V_22 == 0 ) {
F_75 ( V_10 , L_176 , V_335 ) ;
return NULL ;
}
V_337 = F_128 ( V_16 -> V_21 , F_21 ( V_10 , V_336 ) >> 1 ) ;
if ( ! V_337 )
F_75 ( V_10 , L_177 , V_335 , V_22 ) ;
return V_337 ;
}
static int F_129 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_292 * V_293 = & V_40 -> V_293 ;
V_40 -> V_41 = F_127 ( V_10 , L_178 , V_293 -> V_41 , 0xf3 ) ;
V_40 -> V_42 = F_127 ( V_10 , L_179 , V_293 -> V_42 , 0xf4 ) ;
V_40 -> V_43 = F_127 ( V_10 , L_180 , V_293 -> V_43 , 0xf5 ) ;
V_40 -> V_44 = F_127 ( V_10 , L_181 , V_293 -> V_44 , 0xf2 ) ;
V_40 -> V_45 = F_127 ( V_10 , L_182 , V_293 -> V_45 , 0xf1 ) ;
V_40 -> V_46 = F_127 ( V_10 , L_183 , V_293 -> V_46 , 0xf8 ) ;
V_40 -> V_47 = F_127 ( V_10 , L_184 , V_293 -> V_47 , 0xf9 ) ;
V_40 -> V_48 = F_127 ( V_10 , L_185 , V_293 -> V_48 , 0xfa ) ;
V_40 -> V_49 = F_127 ( V_10 , L_186 , V_293 -> V_49 , 0xfb ) ;
V_40 -> V_50 = F_127 ( V_10 , L_187 , V_293 -> V_50 , 0xfd ) ;
V_40 -> V_51 = F_127 ( V_10 , L_188 , V_293 -> V_51 , 0xfe ) ;
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
static int F_130 ( struct V_15 * V_16 ,
const struct V_338 * V_117 )
{
struct V_8 * V_40 ;
static const struct V_1 V_339 =
V_340 ;
struct V_292 * V_293 = V_16 -> V_328 . V_329 ;
struct V_341 * V_3 ;
struct V_9 * V_10 ;
T_4 V_342 ;
int V_30 ;
if ( ! F_131 ( V_16 -> V_21 , V_343 ) )
return - V_27 ;
F_132 ( 1 , V_52 , V_16 , L_189 ,
V_16 -> V_22 << 1 ) ;
if ( ! V_293 ) {
F_16 ( V_16 , L_190 ) ;
return - V_330 ;
}
V_40 = F_133 ( & V_16 -> V_328 , sizeof( struct V_8 ) , V_344 ) ;
if ( ! V_40 ) {
F_16 ( V_16 , L_191 ) ;
return - V_345 ;
}
V_40 -> V_293 = * V_293 ;
V_40 -> V_87 = V_339 ;
V_10 = & V_40 -> V_10 ;
F_134 ( V_10 , V_16 , & V_346 ) ;
V_10 -> V_23 |= V_347 ;
V_40 -> V_54 = V_293 -> V_54 ;
V_40 -> V_184 = V_293 -> V_185 == V_188 ;
V_40 -> V_154 = true ;
V_342 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
if ( V_342 != 0x2012 ) {
F_66 ( V_10 , L_192 , V_342 ) ;
V_342 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
}
if ( V_342 != 0x2012 ) {
F_66 ( V_10 , L_193 ,
V_16 -> V_22 << 1 , V_342 ) ;
return - V_330 ;
}
if ( V_293 -> V_348 )
F_54 ( V_10 ) ;
V_3 = & V_40 -> V_3 ;
F_135 ( V_3 , 6 ) ;
F_136 ( V_3 , & V_349 ,
V_118 , - 128 , 127 , 1 , 0 ) ;
F_136 ( V_3 , & V_349 ,
V_119 , 0 , 255 , 1 , 128 ) ;
F_136 ( V_3 , & V_349 ,
V_120 , 0 , 255 , 1 , 128 ) ;
F_136 ( V_3 , & V_349 ,
V_121 , 0 , 128 , 1 , 0 ) ;
V_40 -> V_82 = F_136 ( V_3 , NULL ,
V_350 , 0 , 3 , 0 , 0 ) ;
V_40 -> V_351 = F_137 ( V_3 ,
& V_352 , NULL ) ;
V_40 -> V_353 = F_137 ( V_3 ,
& V_354 , NULL ) ;
V_40 -> V_355 = F_137 ( V_3 ,
& V_356 , NULL ) ;
V_40 -> V_357 =
F_138 ( V_3 , & V_349 ,
V_131 , V_116 ,
0 , V_112 ) ;
V_10 -> V_323 = V_3 ;
if ( V_3 -> error ) {
V_30 = V_3 -> error ;
goto V_358;
}
V_40 -> V_82 -> V_359 = true ;
V_40 -> V_357 -> V_359 = true ;
V_40 -> V_351 -> V_359 = true ;
V_40 -> V_353 -> V_359 = true ;
V_40 -> V_355 -> V_359 = true ;
if ( F_69 ( V_10 ) ) {
V_30 = - V_330 ;
goto V_358;
}
if ( F_129 ( V_10 ) < 0 ) {
V_30 = - V_345 ;
F_75 ( V_10 , L_194 ) ;
goto V_360;
}
V_40 -> V_70 = F_139 ( V_16 -> V_164 ) ;
if ( ! V_40 -> V_70 ) {
F_75 ( V_10 , L_195 ) ;
V_30 = - V_345 ;
goto V_360;
}
F_140 ( & V_40 -> V_63 ,
F_59 ) ;
V_40 -> V_218 . V_23 = V_361 ;
V_30 = F_141 ( & V_10 -> V_362 , 1 , & V_40 -> V_218 , 0 ) ;
if ( V_30 )
goto V_363;
V_30 = F_119 ( V_10 ) ;
if ( V_30 )
goto V_364;
F_66 ( V_10 , L_196 , V_16 -> V_164 ,
V_16 -> V_22 << 1 , V_16 -> V_21 -> V_164 ) ;
return 0 ;
V_364:
F_142 ( & V_10 -> V_362 ) ;
V_363:
F_143 ( & V_40 -> V_63 ) ;
F_144 ( V_40 -> V_70 ) ;
V_360:
F_125 ( V_10 ) ;
V_358:
F_145 ( V_3 ) ;
return V_30 ;
}
static int F_146 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = F_147 ( V_16 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_105 ( V_10 , false ) ;
F_143 ( & V_40 -> V_63 ) ;
F_144 ( V_40 -> V_70 ) ;
F_148 ( V_10 ) ;
F_142 ( & V_10 -> V_362 ) ;
F_125 ( V_10 ) ;
F_145 ( V_10 -> V_323 ) ;
return 0 ;
}
