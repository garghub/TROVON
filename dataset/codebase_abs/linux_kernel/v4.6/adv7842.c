static bool F_1 ( const struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_5 [ V_4 ] . V_6 . V_7 ; V_4 ++ )
if ( F_2 ( V_2 , V_5 + V_4 , 0 , false ) )
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
static inline int F_25 ( struct V_9 * V_10 ,
T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_23 ( V_10 , V_37 , ( F_21 ( V_10 , V_37 ) & ~ V_39 ) | V_38 ) ;
}
static inline int F_26 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_41 , V_37 ) ;
}
static inline int F_27 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_41 , V_37 , V_38 ) ;
}
static inline int F_28 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_42 , V_37 ) ;
}
static inline int F_29 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_42 , V_37 , V_38 ) ;
}
static inline int F_30 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_29 ( V_10 , V_37 , ( F_28 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_31 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_43 , V_37 ) ;
}
static inline int F_32 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_43 , V_37 , V_38 ) ;
}
static inline int F_33 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_44 , V_37 ) ;
}
static inline int F_34 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_44 , V_37 , V_38 ) ;
}
static inline int F_35 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_34 ( V_10 , V_37 , ( F_33 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_36 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_45 , V_37 ) ;
}
static inline int F_37 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_45 , V_37 , V_38 ) ;
}
static inline int F_38 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_37 ( V_10 , V_37 , ( F_36 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_39 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_46 , V_37 ) ;
}
static inline int F_40 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_46 , V_37 , V_38 ) ;
}
static inline int F_41 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_40 ( V_10 , V_37 , ( F_39 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_42 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_47 , V_37 ) ;
}
static inline int F_43 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_47 , V_37 , V_38 ) ;
}
static inline int F_44 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_43 ( V_10 , V_37 , ( F_42 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_45 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_48 , V_37 ) ;
}
static inline int F_46 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_48 , V_37 , V_38 ) ;
}
static inline int F_47 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_49 , V_37 ) ;
}
static inline int F_48 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_49 , V_37 , V_38 ) ;
}
static inline int F_49 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_48 ( V_10 , V_37 , ( F_47 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_50 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_50 , V_37 ) ;
}
static inline int F_51 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_50 , V_37 , V_38 ) ;
}
static inline int F_52 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_51 ( V_10 , V_37 , ( F_50 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_53 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_51 , V_37 ) ;
}
static inline int F_54 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_51 , V_37 , V_38 ) ;
}
static void F_55 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
F_19 ( V_16 , 0xff , 0x80 ) ;
F_57 ( 5 ) ;
}
static const struct V_54 *
V_54 ( struct V_8 * V_40 , T_3 V_55 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_58 ( V_56 ) ; ++ V_4 ) {
if ( V_56 [ V_4 ] . V_55 == V_55 )
return & V_56 [ V_4 ] ;
}
return NULL ;
}
static inline bool F_59 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return ( ( V_40 -> V_57 == V_58 ) ||
( V_40 -> V_57 == V_59 ) ) ;
}
static inline bool F_60 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return V_40 -> V_57 == V_60 ;
}
static inline const struct V_61 *
F_61 ( struct V_9 * V_10 )
{
return F_60 ( V_10 ) ? & V_62 :
& V_63 ;
}
static void F_62 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_63 ( V_65 ) ;
struct V_8 * V_40 = F_4 ( V_67 ,
struct V_8 , V_68 ) ;
struct V_9 * V_10 = & V_40 -> V_10 ;
int V_69 = V_40 -> V_70 . V_69 ;
T_2 V_39 = 0 ;
F_56 ( 2 , V_52 , V_10 , L_6 ,
V_53 , V_69 ) ;
if ( V_69 & ( 0x04 << V_71 ) )
V_39 |= 0x20 ;
if ( V_69 & ( 0x04 << V_72 ) )
V_39 |= 0x10 ;
F_24 ( V_10 , 0x20 , 0xcf , V_39 ) ;
}
static int F_64 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_73 . V_74 ;
int V_30 = 0 ;
int V_4 ;
F_56 ( 2 , V_52 , V_10 , L_7 , V_53 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_44 ( V_10 , 0x7f , 0x7f , 0x00 ) ;
F_44 ( V_10 , 0x77 , 0xef , 0x10 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_20 ( V_40 -> V_48 , V_4 ,
V_34 , V_38 + V_4 ) ;
if ( V_30 )
return V_30 ;
F_44 ( V_10 , 0x7f , 0x7f , 0x80 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_42 ( V_10 , 0x79 ) & 0x20 )
break;
F_57 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_16 ( V_16 , L_8 ) ;
return - V_27 ;
}
F_65 ( V_40 -> V_75 ,
& V_40 -> V_68 , V_76 / 5 ) ;
return 0 ;
}
static int F_66 ( const T_2 * V_74 )
{
T_2 V_77 ;
if ( ( V_74 [ 0x7e ] != 1 ) ||
( V_74 [ 0x80 ] != 0x02 ) ||
( V_74 [ 0x81 ] != 0x03 ) ) {
return - V_78 ;
}
V_77 = V_74 [ 0x82 ] & 0x7f ;
if ( V_77 > 4 ) {
int V_4 = 0x84 ;
int V_79 = 0x80 + V_77 ;
do {
T_2 V_80 = V_74 [ V_4 ] >> 5 ;
T_2 V_81 = V_74 [ V_4 ] & 0x1f ;
if ( ( V_80 == 3 ) && ( V_81 >= 5 ) )
return V_4 + 4 ;
V_4 += V_81 + 1 ;
} while ( V_4 < V_79 );
}
return - V_78 ;
}
static int F_67 ( struct V_9 * V_10 , T_2 V_82 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_70 . V_74 ;
int V_83 = F_66 ( V_38 ) ;
int V_30 = 0 ;
int V_4 ;
F_56 ( 2 , V_52 , V_10 , L_9 ,
V_53 , ( V_82 == V_71 ) ? 'A' : 'B' , V_83 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_44 ( V_10 , 0x77 , 0xf3 , 0x00 ) ;
if ( ! V_40 -> V_70 . V_69 )
return 0 ;
F_44 ( V_10 , 0x77 , 0xef , 0x00 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_20 ( V_40 -> V_48 , V_4 ,
V_34 , V_38 + V_4 ) ;
if ( V_30 )
return V_30 ;
if ( V_83 < 0 )
V_83 = 0xc0 ;
if ( V_82 == V_71 ) {
F_43 ( V_10 , 0x72 , V_38 [ V_83 ] ) ;
F_43 ( V_10 , 0x73 , V_38 [ V_83 + 1 ] ) ;
} else {
F_43 ( V_10 , 0x74 , V_38 [ V_83 ] ) ;
F_43 ( V_10 , 0x75 , V_38 [ V_83 + 1 ] ) ;
}
F_43 ( V_10 , 0x76 , V_83 & 0xff ) ;
F_44 ( V_10 , 0x77 , 0xbf , ( V_83 >> 2 ) & 0x40 ) ;
F_44 ( V_10 , 0x77 , 0xf3 , V_40 -> V_70 . V_69 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_42 ( V_10 , 0x7d ) & V_40 -> V_70 . V_69 )
break;
F_57 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_16 ( V_16 , L_10 ,
( V_82 == V_71 ) ? 'A' : 'B' ) ;
return - V_27 ;
}
F_65 ( V_40 -> V_75 ,
& V_40 -> V_68 , V_76 / 5 ) ;
return 0 ;
}
static void F_68 ( struct V_9 * V_10 )
{
F_69 ( V_10 , L_11 ) ;
F_69 ( V_10 , L_12 ) ;
F_69 ( V_10 , L_13 ) ;
F_69 ( V_10 , L_14 ) ;
F_69 ( V_10 , L_15 ) ;
F_69 ( V_10 , L_16 ) ;
F_69 ( V_10 , L_17 ) ;
F_69 ( V_10 , L_18 ) ;
F_69 ( V_10 , L_19 ) ;
F_69 ( V_10 , L_20 ) ;
F_69 ( V_10 , L_21 ) ;
F_69 ( V_10 , L_22 ) ;
}
static int F_70 ( struct V_9 * V_10 ,
struct V_84 * V_37 )
{
V_37 -> V_85 = 1 ;
switch ( V_37 -> V_37 >> 8 ) {
case 0 :
V_37 -> V_38 = F_21 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 1 :
V_37 -> V_38 = F_26 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 2 :
V_37 -> V_38 = F_28 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 3 :
V_37 -> V_38 = F_31 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 4 :
V_37 -> V_38 = F_33 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 5 :
V_37 -> V_38 = F_36 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 6 :
V_37 -> V_38 = F_39 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 7 :
V_37 -> V_38 = F_42 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 8 :
V_37 -> V_38 = F_45 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 9 :
V_37 -> V_38 = F_47 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 0xa :
V_37 -> V_38 = F_50 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 0xb :
V_37 -> V_38 = F_53 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
default:
F_69 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_68 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_71 ( struct V_9 * V_10 ,
const struct V_84 * V_37 )
{
T_2 V_38 = V_37 -> V_38 & 0xff ;
switch ( V_37 -> V_37 >> 8 ) {
case 0 :
F_23 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 1 :
F_27 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 2 :
F_29 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 3 :
F_32 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 4 :
F_34 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 5 :
F_37 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 6 :
F_40 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 7 :
F_43 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 8 :
F_46 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 9 :
F_48 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 0xa :
F_51 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 0xb :
F_54 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
default:
F_69 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_68 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_72 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_86 = F_73 ( V_40 -> V_87 ) ;
T_2 V_88 = F_21 ( V_10 , 0x6f ) ;
int V_38 = 0 ;
if ( V_88 & 0x02 )
V_38 |= 1 ;
if ( V_88 & 0x01 )
V_38 |= 2 ;
F_56 ( 1 , V_52 , V_10 , L_24 , V_53 , V_86 , V_38 ) ;
if ( V_38 != V_86 )
return F_74 ( V_40 -> V_87 , V_38 ) ;
return 0 ;
}
static int F_75 ( struct V_9 * V_10 ,
T_2 V_89 ,
const struct V_90 * V_91 ,
const struct V_1 * V_92 )
{
int V_4 ;
for ( V_4 = 0 ; V_91 [ V_4 ] . V_92 . V_6 . V_7 ; V_4 ++ ) {
if ( ! F_2 ( V_92 , & V_91 [ V_4 ] . V_92 ,
F_60 ( V_10 ) ? 250000 : 1000000 , false ) )
continue;
F_23 ( V_10 , 0x00 , V_91 [ V_4 ] . V_93 ) ;
F_23 ( V_10 , 0x01 , ( V_91 [ V_4 ] . V_94 << 4 ) + V_89 ) ;
return 0 ;
}
return - 1 ;
}
static int F_76 ( struct V_9 * V_10 ,
struct V_1 * V_92 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 ;
F_56 ( 1 , V_52 , V_10 , L_25 , V_53 ) ;
F_23 ( V_10 , 0x16 , 0x43 ) ;
F_23 ( V_10 , 0x17 , 0x5a ) ;
F_52 ( V_10 , 0x81 , 0xef , 0x00 ) ;
F_51 ( V_10 , 0x26 , 0x00 ) ;
F_51 ( V_10 , 0x27 , 0x00 ) ;
F_51 ( V_10 , 0x28 , 0x00 ) ;
F_51 ( V_10 , 0x29 , 0x00 ) ;
F_51 ( V_10 , 0x8f , 0x40 ) ;
F_51 ( V_10 , 0x90 , 0x00 ) ;
F_51 ( V_10 , 0xa5 , 0x00 ) ;
F_51 ( V_10 , 0xa6 , 0x00 ) ;
F_51 ( V_10 , 0xa7 , 0x00 ) ;
F_51 ( V_10 , 0xab , 0x00 ) ;
F_51 ( V_10 , 0xac , 0x00 ) ;
switch ( V_40 -> V_57 ) {
case V_59 :
case V_58 :
V_30 = F_75 ( V_10 ,
0x01 , V_95 , V_92 ) ;
if ( V_30 )
V_30 = F_75 ( V_10 ,
0x02 , V_96 , V_92 ) ;
break;
case V_60 :
V_30 = F_75 ( V_10 ,
0x05 , V_97 , V_92 ) ;
if ( V_30 )
V_30 = F_75 ( V_10 ,
0x06 , V_98 , V_92 ) ;
break;
default:
F_56 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_57 ) ;
V_30 = - 1 ;
break;
}
return V_30 ;
}
static void F_77 ( struct V_9 * V_10 ,
const struct V_14 * V_6 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_15 * V_16 = F_22 ( V_10 ) ;
T_3 V_7 = F_8 ( V_6 ) ;
T_3 V_99 = F_12 ( V_6 ) ;
T_4 V_100 = V_6 -> V_101 + V_6 -> V_102 - 4 ;
T_4 V_103 = V_7 - V_6 -> V_104 ;
T_4 V_105 = V_99 - V_6 -> V_106 + 1 ;
T_4 V_107 = V_6 -> V_108 + V_6 -> V_109 + 1 ;
T_4 V_110 = ( ( ( T_3 ) V_6 -> V_111 / 100 ) > 0 ) ?
( ( V_7 * ( V_112 / 100 ) ) / ( ( T_3 ) V_6 -> V_111 / 100 ) ) : 0 ;
const T_2 V_113 [ 2 ] = {
0xc0 | ( ( V_7 >> 8 ) & 0x1f ) ,
V_7 & 0xff
} ;
F_56 ( 2 , V_52 , V_10 , L_25 , V_53 ) ;
switch ( V_40 -> V_57 ) {
case V_59 :
case V_58 :
F_23 ( V_10 , 0x00 , 0x07 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_52 ( V_10 , 0x81 , 0xef , 0x10 ) ;
if ( F_20 ( V_16 , 0x16 , 2 , V_113 ) ) {
F_78 ( V_10 , L_27 ) ;
break;
}
F_51 ( V_10 , 0x26 , ( V_100 >> 8 ) & 0xf ) ;
F_51 ( V_10 , 0x27 , ( V_100 & 0xff ) ) ;
F_51 ( V_10 , 0x28 , ( V_103 >> 8 ) & 0xf ) ;
F_51 ( V_10 , 0x29 , ( V_103 & 0xff ) ) ;
F_51 ( V_10 , 0xa5 , ( V_105 >> 4 ) & 0xff ) ;
F_51 ( V_10 , 0xa6 , ( ( V_105 & 0xf ) << 4 ) |
( ( V_107 >> 8 ) & 0xf ) ) ;
F_51 ( V_10 , 0xa7 , V_107 & 0xff ) ;
break;
case V_60 :
F_23 ( V_10 , 0x00 , 0x02 ) ;
F_23 ( V_10 , 0x01 , 0x06 ) ;
break;
default:
F_56 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_57 ) ;
break;
}
F_51 ( V_10 , 0x8f , ( V_110 >> 8 ) & 0x7 ) ;
F_51 ( V_10 , 0x90 , V_110 & 0xff ) ;
F_51 ( V_10 , 0xab , ( V_99 >> 4 ) & 0xff ) ;
F_51 ( V_10 , 0xac , ( V_99 & 0x0f ) << 4 ) ;
}
static void F_79 ( struct V_9 * V_10 , bool V_114 , T_4 V_115 , T_4 V_116 , T_4 V_117 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_118 [ 4 ] ;
if ( V_114 ) {
V_115 = 0x3ff ;
V_116 = 0x3ff ;
V_117 = 0x3ff ;
}
F_56 ( 2 , V_52 , V_10 , L_28 ,
V_53 , V_114 ? L_29 : L_30 ,
V_115 , V_116 , V_117 ) ;
V_118 [ 0 ] = ( F_50 ( V_10 , 0x77 ) & 0xc0 ) | ( ( V_115 & 0x3f0 ) >> 4 ) ;
V_118 [ 1 ] = ( ( V_115 & 0x00f ) << 4 ) | ( ( V_116 & 0x3c0 ) >> 6 ) ;
V_118 [ 2 ] = ( ( V_116 & 0x03f ) << 2 ) | ( ( V_117 & 0x300 ) >> 8 ) ;
V_118 [ 3 ] = V_117 & 0x0ff ;
if ( F_20 ( V_40 -> V_50 , 0x77 , 4 , V_118 ) )
F_78 ( V_10 , L_31 , V_53 ) ;
}
static void F_80 ( struct V_9 * V_10 , bool V_119 , T_4 V_120 , T_4 V_121 , T_4 V_122 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_123 [ 4 ] ;
T_2 V_124 = 1 ;
T_2 V_125 = 1 ;
if ( V_119 ) {
V_124 = 0 ;
V_125 = 0 ;
V_120 = 0x100 ;
V_121 = 0x100 ;
V_122 = 0x100 ;
}
F_56 ( 2 , V_52 , V_10 , L_32 ,
V_53 , V_119 ? L_29 : L_30 ,
V_120 , V_121 , V_122 ) ;
V_123 [ 0 ] = ( ( V_124 << 7 ) | ( V_125 << 6 ) | ( ( V_120 & 0x3f0 ) >> 4 ) ) ;
V_123 [ 1 ] = ( ( ( V_120 & 0x00f ) << 4 ) | ( ( V_121 & 0x3c0 ) >> 6 ) ) ;
V_123 [ 2 ] = ( ( ( V_121 & 0x03f ) << 2 ) | ( ( V_122 & 0x300 ) >> 8 ) ) ;
V_123 [ 3 ] = ( ( V_122 & 0x0ff ) ) ;
if ( F_20 ( V_40 -> V_50 , 0x73 , 4 , V_123 ) )
F_78 ( V_10 , L_33 , V_53 ) ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
bool V_126 = F_21 ( V_10 , 0x02 ) & 0x02 ;
bool V_127 = F_47 ( V_10 , 0x05 ) & 0x80 ;
F_56 ( 2 , V_52 , V_10 , L_34 ,
V_53 , V_40 -> V_128 ,
V_126 , V_127 ) ;
F_80 ( V_10 , true , 0x0 , 0x0 , 0x0 ) ;
F_79 ( V_10 , true , 0x0 , 0x0 , 0x0 ) ;
switch ( V_40 -> V_128 ) {
case V_129 :
if ( V_40 -> V_57 == V_58 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
break;
}
if ( V_40 -> V_57 == V_59 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_127 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_40 -> V_92 . V_6 . V_23 & V_130 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
if ( F_60 ( V_10 ) && V_126 ) {
F_79 ( V_10 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_80 ( V_10 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_79 ( V_10 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_131 :
if ( V_40 -> V_57 == V_59 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x20 ) ;
break;
}
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_132 :
if ( V_40 -> V_57 == V_59 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x60 ) ;
break;
}
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
if ( F_59 ( V_10 ) || V_127 )
break;
if ( V_126 ) {
F_79 ( V_10 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_80 ( V_10 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_79 ( V_10 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_82 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_12 -> V_133 ) {
case V_134 :
F_51 ( V_10 , 0x3c , V_12 -> V_38 ) ;
F_37 ( V_10 , 0x14 , V_12 -> V_38 ) ;
return 0 ;
case V_135 :
F_51 ( V_10 , 0x3a , V_12 -> V_38 ) ;
F_37 ( V_10 , 0x13 , V_12 -> V_38 ) ;
return 0 ;
case V_136 :
F_51 ( V_10 , 0x3b , V_12 -> V_38 ) ;
F_37 ( V_10 , 0x15 , V_12 -> V_38 ) ;
return 0 ;
case V_137 :
F_51 ( V_10 , 0x3d , V_12 -> V_38 ) ;
F_37 ( V_10 , 0x16 , V_12 -> V_38 ) ;
return 0 ;
case V_138 :
F_40 ( V_10 , 0xc8 , V_12 -> V_38 ) ;
return 0 ;
case V_139 :
F_52 ( V_10 , 0xbf , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
F_38 ( V_10 , 0xdd , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
return 0 ;
case V_140 : {
T_2 V_141 = ( V_12 -> V_38 & 0xff0000 ) >> 16 ;
T_2 V_142 = ( V_12 -> V_38 & 0x00ff00 ) >> 8 ;
T_2 V_143 = ( V_12 -> V_38 & 0x0000ff ) ;
int V_144 = 66 * V_141 + 129 * V_142 + 25 * V_143 ;
int V_145 = - 38 * V_141 - 74 * V_142 + 112 * V_143 ;
int V_146 = 112 * V_141 - 94 * V_142 - 18 * V_143 ;
V_144 = ( V_144 + 128 ) >> 8 ;
V_145 = ( V_145 + 128 ) >> 8 ;
V_146 = ( V_146 + 128 ) >> 8 ;
V_144 += 16 ;
V_145 += 128 ;
V_146 += 128 ;
F_56 ( 1 , V_52 , V_10 , L_35 , V_141 , V_142 , V_143 ) ;
F_56 ( 1 , V_52 , V_10 , L_36 , V_144 , V_145 , V_146 ) ;
F_51 ( V_10 , 0xc1 , V_141 ) ;
F_51 ( V_10 , 0xc0 , V_142 ) ;
F_51 ( V_10 , 0xc2 , V_143 ) ;
F_37 ( V_10 , 0xde , V_144 ) ;
F_37 ( V_10 , 0xdf , ( V_146 & 0xf0 ) | ( ( V_145 >> 4 ) & 0x0f ) ) ;
return 0 ;
}
case V_147 :
V_40 -> V_128 = V_12 -> V_38 ;
F_81 ( V_10 ) ;
return 0 ;
}
return - V_78 ;
}
static int F_83 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
if ( V_12 -> V_133 == V_148 ) {
V_12 -> V_38 = V_149 ;
if ( ( F_21 ( V_10 , 0x60 ) & 1 ) && ( F_31 ( V_10 , 0x03 ) & 0x80 ) )
V_12 -> V_38 = ( F_31 ( V_10 , 0x05 ) >> 4 ) & 3 ;
return 0 ;
}
return - V_78 ;
}
static inline bool F_84 ( struct V_9 * V_10 )
{
return F_21 ( V_10 , 0x0c ) & 0x24 ;
}
static inline bool F_85 ( struct V_9 * V_10 )
{
return ( ( F_50 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ) || ! ( F_50 ( V_10 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_86 ( struct V_9 * V_10 )
{
return F_47 ( V_10 , 0x05 ) & 0x80 ;
}
static int F_87 ( struct V_9 * V_10 , T_3 * V_150 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
* V_150 = 0 ;
if ( F_21 ( V_10 , 0x0c ) & 0x24 )
* V_150 |= V_151 ;
if ( V_40 -> V_57 == V_152 ) {
if ( ! ( F_36 ( V_10 , 0x5A ) & 0x01 ) )
* V_150 |= V_153 ;
F_56 ( 1 , V_52 , V_10 , L_37 ,
V_53 , * V_150 ) ;
return 0 ;
}
if ( ( F_50 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ||
! ( F_50 ( V_10 , 0xb1 ) & 0x80 ) )
* V_150 |= V_153 ;
if ( F_60 ( V_10 ) && ( ( F_21 ( V_10 , 0x74 ) & 0x03 ) != 0x03 ) )
* V_150 |= V_153 ;
F_56 ( 1 , V_52 , V_10 , L_38 ,
V_53 , * V_150 ) ;
return 0 ;
}
static int F_88 ( struct V_9 * V_10 ,
struct V_154 * V_155 ,
struct V_1 * V_92 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_3 V_156 = ( V_112 * 8 ) / V_155 -> V_157 ;
T_3 V_158 ;
int V_4 ;
for ( V_4 = 0 ; V_159 [ V_4 ] . V_6 . V_7 ; V_4 ++ ) {
const struct V_14 * V_6 = & V_159 [ V_4 ] . V_6 ;
if ( ! F_89 ( & V_159 [ V_4 ] ,
F_61 ( V_10 ) ,
F_1 , NULL ) )
continue;
if ( F_12 ( V_6 ) != V_155 -> V_160 + 1 )
continue;
if ( V_6 -> V_108 != V_155 -> V_161 )
continue;
V_158 = V_156 * F_8 ( V_6 ) ;
if ( ( V_158 < V_6 -> V_111 + 1000000 ) &&
( V_158 > V_6 -> V_111 - 1000000 ) ) {
* V_92 = V_159 [ V_4 ] ;
return 0 ;
}
}
if ( F_90 ( V_155 -> V_160 + 1 , V_156 , V_155 -> V_161 , 0 ,
( V_155 -> V_162 == '+' ? V_163 : 0 ) |
( V_155 -> V_164 == '+' ? V_165 : 0 ) ,
false , V_92 ) )
return 0 ;
if ( F_91 ( V_155 -> V_160 + 1 , V_156 , V_155 -> V_161 ,
( V_155 -> V_162 == '+' ? V_163 : 0 ) |
( V_155 -> V_164 == '+' ? V_165 : 0 ) ,
false , V_40 -> V_166 , V_92 ) )
return 0 ;
F_56 ( 2 , V_52 , V_10 ,
L_39 ,
V_53 , V_155 -> V_161 , V_155 -> V_160 , V_155 -> V_157 ,
V_155 -> V_162 , V_155 -> V_164 ) ;
return - 1 ;
}
static int F_92 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
T_3 V_150 ;
F_87 ( V_10 , & V_150 ) ;
if ( V_150 & V_153 ) {
F_56 ( 2 , V_52 , V_10 , L_40 , V_53 ) ;
return - V_167 ;
}
V_155 -> V_157 = ( ( F_50 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_50 ( V_10 , 0xb2 ) ;
V_155 -> V_160 = ( ( F_50 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_50 ( V_10 , 0xb4 ) ;
V_155 -> V_161 = F_50 ( V_10 , 0xb3 ) >> 3 ;
if ( ( F_50 ( V_10 , 0xb5 ) & 0x80 ) && ( ( F_50 ( V_10 , 0xb5 ) & 0x03 ) == 0x01 ) ) {
V_155 -> V_162 = ( ( F_50 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_50 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_155 -> V_164 = ( ( F_50 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_50 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_155 -> V_162 = 'x' ;
V_155 -> V_164 = 'x' ;
}
V_155 -> V_168 = ( F_50 ( V_10 , 0xb1 ) & 0x40 ) ? true : false ;
if ( V_155 -> V_160 < 239 || V_155 -> V_157 < 8 || V_155 -> V_157 == 0x3fff ) {
F_56 ( 2 , V_52 , V_10 , L_41 , V_53 ) ;
return - V_167 ;
}
F_56 ( 2 , V_52 , V_10 ,
L_42 ,
V_53 , V_155 -> V_160 , V_155 -> V_157 , V_155 -> V_161 ,
V_155 -> V_162 , V_155 -> V_164 ,
V_155 -> V_168 ? L_43 : L_44 ) ;
return 0 ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_169 * V_92 )
{
if ( V_92 -> V_170 != 0 )
return - V_78 ;
return F_94 ( V_92 ,
F_61 ( V_10 ) , F_1 , NULL ) ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_61 * V_171 )
{
if ( V_171 -> V_170 != 0 )
return - V_78 ;
* V_171 = * F_61 ( V_10 ) ;
return 0 ;
}
static void F_96 ( struct V_9 * V_10 ,
struct V_1 * V_92 )
{
F_97 ( V_92 , F_61 ( V_10 ) ,
F_60 ( V_10 ) ? 250000 : 1000000 ,
F_1 , NULL ) ;
}
static int F_98 ( struct V_9 * V_10 ,
struct V_1 * V_92 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 = & V_92 -> V_6 ;
struct V_154 V_155 = { 0 } ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
memset ( V_92 , 0 , sizeof( struct V_1 ) ) ;
if ( V_40 -> V_57 == V_152 )
return - V_172 ;
if ( F_92 ( V_10 , & V_155 ) ) {
V_40 -> V_173 = true ;
F_56 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return - V_167 ;
}
V_6 -> V_168 = V_155 . V_168 ?
V_174 : V_175 ;
V_6 -> V_176 = V_177 | V_178 |
V_179 | V_180 ;
if ( F_60 ( V_10 ) ) {
T_3 V_181 ;
V_92 -> type = V_182 ;
V_6 -> V_7 = ( F_47 ( V_10 , 0x07 ) & 0x0f ) * 256 + F_47 ( V_10 , 0x08 ) ;
V_6 -> V_99 = ( F_47 ( V_10 , 0x09 ) & 0x0f ) * 256 + F_47 ( V_10 , 0x0a ) ;
V_181 = ( ( F_47 ( V_10 , 0x51 ) << 1 ) + ( F_47 ( V_10 , 0x52 ) >> 7 ) ) * 1000000 ;
V_181 += ( ( F_47 ( V_10 , 0x52 ) & 0x7f ) * 7813 ) ;
if ( F_86 ( V_10 ) ) {
V_181 = V_181 * 8 / ( ( ( F_47 ( V_10 , 0x0b ) & 0xc0 ) >> 6 ) * 2 + 8 ) ;
}
V_6 -> V_111 = V_181 ;
V_6 -> V_104 = ( F_47 ( V_10 , 0x20 ) & 0x03 ) * 256 +
F_47 ( V_10 , 0x21 ) ;
V_6 -> V_101 = ( F_47 ( V_10 , 0x22 ) & 0x03 ) * 256 +
F_47 ( V_10 , 0x23 ) ;
V_6 -> V_102 = ( F_47 ( V_10 , 0x24 ) & 0x03 ) * 256 +
F_47 ( V_10 , 0x25 ) ;
V_6 -> V_106 = ( ( F_47 ( V_10 , 0x2a ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x2b ) ) / 2 ;
V_6 -> V_108 = ( ( F_47 ( V_10 , 0x2e ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x2f ) ) / 2 ;
V_6 -> V_109 = ( ( F_47 ( V_10 , 0x32 ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x33 ) ) / 2 ;
V_6 -> V_183 = ( ( F_47 ( V_10 , 0x05 ) & 0x10 ) ? V_165 : 0 ) |
( ( F_47 ( V_10 , 0x05 ) & 0x20 ) ? V_163 : 0 ) ;
if ( V_6 -> V_168 == V_174 ) {
V_6 -> V_99 += ( F_47 ( V_10 , 0x0b ) & 0x0f ) * 256 +
F_47 ( V_10 , 0x0c ) ;
V_6 -> V_184 = ( ( F_47 ( V_10 , 0x2c ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x2d ) ) / 2 ;
V_6 -> V_185 = ( ( F_47 ( V_10 , 0x30 ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x31 ) ) / 2 ;
V_6 -> V_186 = ( ( F_47 ( V_10 , 0x34 ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x35 ) ) / 2 ;
} else {
V_6 -> V_184 = 0 ;
V_6 -> V_185 = 0 ;
V_6 -> V_186 = 0 ;
}
F_96 ( V_10 , V_92 ) ;
} else {
if ( ! F_88 ( V_10 , & V_155 , V_92 ) )
goto V_187;
V_155 . V_161 += 1 ;
F_56 ( 1 , V_52 , V_10 , L_46 , V_53 , V_155 . V_161 ) ;
if ( ! F_88 ( V_10 , & V_155 , V_92 ) )
goto V_187;
V_155 . V_161 -= 2 ;
F_56 ( 1 , V_52 , V_10 , L_47 , V_53 , V_155 . V_161 ) ;
if ( F_88 ( V_10 , & V_155 , V_92 ) ) {
if ( V_40 -> V_173 ) {
F_56 ( 1 , V_52 , V_10 , L_48 , V_53 ) ;
F_52 ( V_10 , 0x86 , 0xf9 , 0x00 ) ;
F_52 ( V_10 , 0x86 , 0xf9 , 0x04 ) ;
F_52 ( V_10 , 0x86 , 0xf9 , 0x02 ) ;
V_40 -> V_173 = false ;
return - V_167 ;
}
F_56 ( 1 , V_52 , V_10 , L_49 , V_53 ) ;
return - V_188 ;
}
V_40 -> V_173 = true ;
}
V_187:
if ( V_52 > 1 )
F_99 ( V_10 -> V_189 , L_50 ,
V_92 , true ) ;
return 0 ;
}
static int F_100 ( struct V_9 * V_10 ,
struct V_1 * V_92 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 ;
int V_30 ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_57 == V_152 )
return - V_172 ;
if ( F_2 ( & V_40 -> V_92 , V_92 , 0 , false ) ) {
F_56 ( 1 , V_52 , V_10 , L_51 , V_53 ) ;
return 0 ;
}
V_6 = & V_92 -> V_6 ;
if ( ! F_89 ( V_92 , F_61 ( V_10 ) ,
F_1 , NULL ) )
return - V_188 ;
F_96 ( V_10 , V_92 ) ;
V_40 -> V_92 = * V_92 ;
F_51 ( V_10 , 0x91 , V_6 -> V_168 ? 0x40 : 0x00 ) ;
V_30 = F_76 ( V_10 , V_92 ) ;
if ( V_30 ) {
F_77 ( V_10 , V_6 ) ;
}
F_81 ( V_10 ) ;
if ( V_52 > 1 )
F_99 ( V_10 -> V_189 , L_52 ,
V_92 , true ) ;
return 0 ;
}
static int F_101 ( struct V_9 * V_10 ,
struct V_1 * V_92 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_57 == V_152 )
return - V_172 ;
* V_92 = V_40 -> V_92 ;
return 0 ;
}
static void F_102 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_81 ( V_10 ) ;
switch ( V_40 -> V_57 ) {
case V_152 :
case V_59 :
case V_58 :
F_23 ( V_10 , 0x15 , 0xb0 ) ;
break;
case V_60 :
F_48 ( V_10 , 0x01 , 0x00 ) ;
F_23 ( V_10 , 0x15 , 0xa0 ) ;
F_49 ( V_10 , 0x1a , 0xef , 0x00 ) ;
break;
default:
F_56 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_57 ) ;
break;
}
}
static void F_103 ( struct V_9 * V_10 )
{
F_49 ( V_10 , 0x1a , 0xef , 0x10 ) ;
F_104 ( 16 ) ;
F_23 ( V_10 , 0x15 , 0xbe ) ;
F_48 ( V_10 , 0x01 , 0x78 ) ;
}
static void F_105 ( struct V_9 * V_10 ,
const struct V_190 * V_191 )
{
F_35 ( V_10 , 0xe0 , 0xbf , V_191 -> V_192 ? 0x00 : 0x40 ) ;
if ( ! V_191 -> V_192 )
return;
F_35 ( V_10 , 0xe0 , 0x7f , V_191 -> V_193 == 2 ? 0x80 : 0x00 ) ;
F_35 ( V_10 , 0xe0 , 0xe0 , V_191 -> V_194 >> 8 ) ;
F_34 ( V_10 , 0xe1 , V_191 -> V_194 ) ;
F_35 ( V_10 , 0xe2 , 0xe0 , V_191 -> V_195 >> 8 ) ;
F_34 ( V_10 , 0xe3 , V_191 -> V_195 ) ;
F_35 ( V_10 , 0xe4 , 0xe0 , V_191 -> V_196 >> 8 ) ;
F_34 ( V_10 , 0xe5 , V_191 -> V_196 ) ;
F_35 ( V_10 , 0xe6 , 0x80 , V_191 -> V_197 >> 8 ) ;
F_34 ( V_10 , 0xe7 , V_191 -> V_197 ) ;
F_35 ( V_10 , 0xe8 , 0xe0 , V_191 -> V_198 >> 8 ) ;
F_34 ( V_10 , 0xe9 , V_191 -> V_198 ) ;
F_35 ( V_10 , 0xea , 0xe0 , V_191 -> V_199 >> 8 ) ;
F_34 ( V_10 , 0xeb , V_191 -> V_199 ) ;
F_35 ( V_10 , 0xec , 0xe0 , V_191 -> V_200 >> 8 ) ;
F_34 ( V_10 , 0xed , V_191 -> V_200 ) ;
F_35 ( V_10 , 0xee , 0x80 , V_191 -> V_201 >> 8 ) ;
F_34 ( V_10 , 0xef , V_191 -> V_201 ) ;
F_35 ( V_10 , 0xf0 , 0xe0 , V_191 -> V_202 >> 8 ) ;
F_34 ( V_10 , 0xf1 , V_191 -> V_202 ) ;
F_35 ( V_10 , 0xf2 , 0xe0 , V_191 -> V_203 >> 8 ) ;
F_34 ( V_10 , 0xf3 , V_191 -> V_203 ) ;
F_35 ( V_10 , 0xf4 , 0xe0 , V_191 -> V_204 >> 8 ) ;
F_34 ( V_10 , 0xf5 , V_191 -> V_204 ) ;
F_35 ( V_10 , 0xf6 , 0x80 , V_191 -> V_205 >> 8 ) ;
F_34 ( V_10 , 0xf7 , V_191 -> V_205 ) ;
}
static void F_106 ( struct V_9 * V_10 ,
enum V_206 V_207 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_40 -> V_57 ) {
case V_152 :
F_23 ( V_10 , 0x00 , V_207 ) ;
F_23 ( V_10 , 0x01 , 0 ) ;
F_52 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_40 ( V_10 , 0x00 , 0x00 ) ;
F_40 ( V_10 , 0xc8 , 0x00 ) ;
F_23 ( V_10 , 0xdd , 0x90 ) ;
F_41 ( V_10 , 0x02 , 0x7f , 0x80 ) ;
if ( V_207 == V_208 ) {
F_40 ( V_10 , 0x03 , 0xa0 ) ;
F_40 ( V_10 , 0x04 , 0x00 ) ;
} else {
F_40 ( V_10 , 0x03 , 0xa0 ) ;
F_40 ( V_10 , 0x04 , 0xc0 ) ;
}
F_40 ( V_10 , 0x0c , 0x1f ) ;
F_40 ( V_10 , 0x12 , 0x63 ) ;
F_34 ( V_10 , 0xb2 , 0x60 ) ;
F_34 ( V_10 , 0xc8 , 0xe3 ) ;
F_37 ( V_10 , 0x00 , 0x3F ) ;
F_37 ( V_10 , 0x01 , 0x00 ) ;
F_37 ( V_10 , 0x03 , 0xE4 ) ;
F_37 ( V_10 , 0x04 , 0x0B ) ;
F_37 ( V_10 , 0x05 , 0xC3 ) ;
F_37 ( V_10 , 0x06 , 0xFE ) ;
F_37 ( V_10 , 0x12 , 0x0D ) ;
F_37 ( V_10 , 0xA7 , 0x00 ) ;
F_34 ( V_10 , 0xB0 , 0x00 ) ;
F_38 ( V_10 , 0x12 , 0xf6 , 0x09 ) ;
break;
case V_59 :
case V_58 :
F_41 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
F_23 ( V_10 , 0x00 , V_207 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_52 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_40 ( V_10 , 0x00 , 0x00 ) ;
F_40 ( V_10 , 0xc8 , 0x00 ) ;
if ( V_40 -> V_57 == V_59 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x60 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
}
F_40 ( V_10 , 0x0c , 0x1f ) ;
F_40 ( V_10 , 0x12 , 0x63 ) ;
F_51 ( V_10 , 0x73 , 0x10 ) ;
F_51 ( V_10 , 0x74 , 0x04 ) ;
F_51 ( V_10 , 0x75 , 0x01 ) ;
F_51 ( V_10 , 0x76 , 0x00 ) ;
F_51 ( V_10 , 0x3e , 0x04 ) ;
F_51 ( V_10 , 0xc3 , 0x39 ) ;
F_51 ( V_10 , 0x40 , 0x5c ) ;
break;
case V_60 :
F_41 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
if ( V_40 -> V_209 )
F_48 ( V_10 , 0x00 , 0x02 ) ;
else
F_48 ( V_10 , 0x00 , 0x03 ) ;
F_23 ( V_10 , 0x00 , V_207 ) ;
F_23 ( V_10 , 0x01 , 5 ) ;
F_52 ( V_10 , 0x81 , 0xef , 0x00 ) ;
F_48 ( V_10 , 0xc0 , 0x00 ) ;
F_48 ( V_10 , 0x0d , 0x34 ) ;
F_48 ( V_10 , 0x3d , 0x10 ) ;
F_48 ( V_10 , 0x44 , 0x85 ) ;
F_48 ( V_10 , 0x46 , 0x1f ) ;
F_48 ( V_10 , 0x57 , 0xb6 ) ;
F_48 ( V_10 , 0x58 , 0x03 ) ;
F_48 ( V_10 , 0x60 , 0x88 ) ;
F_48 ( V_10 , 0x61 , 0x88 ) ;
F_48 ( V_10 , 0x6c , 0x18 ) ;
F_48 ( V_10 , 0x75 , 0x10 ) ;
F_48 ( V_10 , 0x85 , 0x1f ) ;
F_48 ( V_10 , 0x87 , 0x70 ) ;
F_48 ( V_10 , 0x89 , 0x04 ) ;
F_48 ( V_10 , 0x8a , 0x1e ) ;
F_48 ( V_10 , 0x93 , 0x04 ) ;
F_48 ( V_10 , 0x94 , 0x1e ) ;
F_48 ( V_10 , 0x99 , 0xa1 ) ;
F_48 ( V_10 , 0x9b , 0x09 ) ;
F_48 ( V_10 , 0x9d , 0x02 ) ;
F_40 ( V_10 , 0x00 , 0xff ) ;
F_40 ( V_10 , 0xc8 , 0x40 ) ;
F_51 ( V_10 , 0x73 , 0x10 ) ;
F_51 ( V_10 , 0x74 , 0x04 ) ;
F_51 ( V_10 , 0x75 , 0x01 ) ;
F_51 ( V_10 , 0x76 , 0x00 ) ;
F_40 ( V_10 , 0x12 , 0xfb ) ;
F_40 ( V_10 , 0x0c , 0x0d ) ;
F_51 ( V_10 , 0x3e , 0x00 ) ;
F_51 ( V_10 , 0xc3 , 0x33 ) ;
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
default:
F_56 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_57 ) ;
break;
}
}
static int F_107 ( struct V_9 * V_10 ,
T_3 V_210 , T_3 V_211 , T_3 V_212 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_56 ( 2 , V_52 , V_10 , L_53 , V_53 , V_210 ) ;
switch ( V_210 ) {
case V_213 :
V_40 -> V_57 = V_60 ;
V_40 -> V_207 = V_214 ;
V_40 -> V_209 = true ;
break;
case V_215 :
V_40 -> V_57 = V_60 ;
V_40 -> V_207 = V_214 ;
V_40 -> V_209 = false ;
break;
case V_216 :
V_40 -> V_57 = V_59 ;
V_40 -> V_207 = V_217 ;
break;
case V_218 :
V_40 -> V_57 = V_58 ;
V_40 -> V_207 = V_217 ;
break;
case V_219 :
V_40 -> V_57 = V_152 ;
V_40 -> V_207 = V_208 ;
break;
case V_220 :
V_40 -> V_57 = V_152 ;
V_40 -> V_207 = V_221 ;
break;
default:
return - V_78 ;
}
F_103 ( V_10 ) ;
F_106 ( V_10 , V_40 -> V_207 ) ;
F_102 ( V_10 ) ;
F_108 ( V_10 , & V_222 ) ;
return 0 ;
}
static int F_109 ( struct V_9 * V_10 ,
struct V_223 * V_224 ,
struct V_225 * V_55 )
{
if ( V_55 -> V_226 >= F_58 ( V_56 ) )
return - V_78 ;
V_55 -> V_55 = V_56 [ V_55 -> V_226 ] . V_55 ;
return 0 ;
}
static void F_110 ( struct V_8 * V_40 ,
struct V_227 * V_228 )
{
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
V_228 -> V_7 = V_40 -> V_92 . V_6 . V_7 ;
V_228 -> V_99 = V_40 -> V_92 . V_6 . V_99 ;
V_228 -> V_229 = V_230 ;
V_228 -> V_231 = V_232 ;
if ( V_40 -> V_92 . V_6 . V_23 & V_130 )
V_228 -> V_231 = ( V_40 -> V_92 . V_6 . V_99 <= 576 ) ?
V_233 : V_234 ;
}
static unsigned int F_111 ( struct V_8 * V_40 )
{
#define F_112 ( T_5 , T_6 , V_191 , V_77 , T_7 , T_8 ) { \
ADV7842_OP_CH_SEL_##a, ADV7842_OP_CH_SEL_##b, ADV7842_OP_CH_SEL_##c, \
ADV7842_OP_CH_SEL_##d, ADV7842_OP_CH_SEL_##e, ADV7842_OP_CH_SEL_##f }
#define F_113 ( T_9 ) [ADV7842_BUS_ORDER_##x]
static const unsigned int V_235 [ 6 ] [ 6 ] = {
F_113 ( V_236 ) = F_112 ( V_237 , V_238 , V_239 , V_236 , V_240 , V_241 ) ,
F_113 ( V_238 ) = F_112 ( V_239 , V_236 , V_237 , V_238 , V_241 , V_240 ) ,
F_113 ( V_241 ) = F_112 ( V_238 , V_237 , V_240 , V_241 , V_239 , V_236 ) ,
F_113 ( V_239 ) = F_112 ( V_241 , V_240 , V_236 , V_239 , V_238 , V_237 ) ,
F_113 ( V_240 ) = F_112 ( V_240 , V_241 , V_238 , V_237 , V_236 , V_239 ) ,
F_113 ( V_237 ) = F_112 ( V_236 , V_239 , V_241 , V_240 , V_237 , V_238 ) ,
} ;
return V_235 [ V_40 -> V_242 . V_243 ] [ V_40 -> V_228 -> V_235 >> 5 ] ;
}
static void F_114 ( struct V_8 * V_40 )
{
struct V_9 * V_10 = & V_40 -> V_10 ;
F_25 ( V_10 , 0x02 , 0x02 ,
V_40 -> V_228 -> V_244 ? V_245 : 0 ) ;
F_23 ( V_10 , 0x03 , V_40 -> V_228 -> V_246 |
V_40 -> V_242 . V_247 ) ;
F_25 ( V_10 , 0x04 , 0xe0 , F_111 ( V_40 ) ) ;
F_25 ( V_10 , 0x05 , 0x01 ,
V_40 -> V_228 -> V_248 ? V_249 : 0 ) ;
}
static int F_115 ( struct V_9 * V_10 ,
struct V_223 * V_224 ,
struct V_250 * V_228 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_228 -> V_170 != V_251 )
return - V_78 ;
if ( V_40 -> V_57 == V_152 ) {
if ( ! ( F_36 ( V_10 , 0x5a ) & 0x01 ) )
return - V_78 ;
V_228 -> V_228 . V_55 = V_252 ;
V_228 -> V_228 . V_7 = 720 ;
if ( V_40 -> V_253 & V_254 )
V_228 -> V_228 . V_99 = 480 ;
else
V_228 -> V_228 . V_99 = 576 ;
V_228 -> V_228 . V_231 = V_233 ;
return 0 ;
}
F_110 ( V_40 , & V_228 -> V_228 ) ;
if ( V_228 -> V_255 == V_256 ) {
struct V_227 * V_257 ;
V_257 = F_116 ( V_10 , V_224 , V_228 -> V_170 ) ;
V_228 -> V_228 . V_55 = V_257 -> V_55 ;
} else {
V_228 -> V_228 . V_55 = V_40 -> V_228 -> V_55 ;
}
return 0 ;
}
static int F_117 ( struct V_9 * V_10 ,
struct V_223 * V_224 ,
struct V_250 * V_228 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
const struct V_54 * V_258 ;
if ( V_228 -> V_170 != V_251 )
return - V_78 ;
if ( V_40 -> V_57 == V_152 )
return F_115 ( V_10 , V_224 , V_228 ) ;
V_258 = V_54 ( V_40 , V_228 -> V_228 . V_55 ) ;
if ( V_258 == NULL )
V_258 = V_54 ( V_40 , V_252 ) ;
F_110 ( V_40 , & V_228 -> V_228 ) ;
V_228 -> V_228 . V_55 = V_258 -> V_55 ;
if ( V_228 -> V_255 == V_256 ) {
struct V_227 * V_257 ;
V_257 = F_116 ( V_10 , V_224 , V_228 -> V_170 ) ;
V_257 -> V_55 = V_228 -> V_228 . V_55 ;
} else {
V_40 -> V_228 = V_258 ;
F_114 ( V_40 ) ;
}
return 0 ;
}
static void F_118 ( struct V_9 * V_10 , bool V_259 )
{
if ( V_259 ) {
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
static int F_119 ( struct V_9 * V_10 , T_3 V_150 , bool * V_260 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_261 , V_262 , V_263 ;
T_2 V_264 [ 6 ] ;
F_118 ( V_10 , false ) ;
V_264 [ 0 ] = F_21 ( V_10 , 0x43 ) ;
V_264 [ 1 ] = F_21 ( V_10 , 0x57 ) ;
V_264 [ 2 ] = F_21 ( V_10 , 0x70 ) ;
V_264 [ 3 ] = F_21 ( V_10 , 0x75 ) ;
V_264 [ 4 ] = F_21 ( V_10 , 0x9d ) ;
V_264 [ 5 ] = F_21 ( V_10 , 0x66 ) ;
if ( V_264 [ 0 ] )
F_23 ( V_10 , 0x44 , V_264 [ 0 ] ) ;
if ( V_264 [ 1 ] )
F_23 ( V_10 , 0x58 , V_264 [ 1 ] ) ;
if ( V_264 [ 2 ] )
F_23 ( V_10 , 0x71 , V_264 [ 2 ] ) ;
if ( V_264 [ 3 ] )
F_23 ( V_10 , 0x76 , V_264 [ 3 ] ) ;
if ( V_264 [ 4 ] )
F_23 ( V_10 , 0x9e , V_264 [ 4 ] ) ;
if ( V_264 [ 5 ] )
F_23 ( V_10 , 0x67 , V_264 [ 5 ] ) ;
F_118 ( V_10 , true ) ;
F_56 ( 1 , V_52 , V_10 , L_54 , V_53 ,
V_264 [ 0 ] , V_264 [ 1 ] , V_264 [ 2 ] ,
V_264 [ 3 ] , V_264 [ 4 ] , V_264 [ 5 ] ) ;
V_261 = V_264 [ 0 ] & 0x9c ;
if ( V_40 -> V_57 == V_152 )
V_263 = ( V_264 [ 1 ] & 0x30 ) | ( V_264 [ 4 ] & 0x09 ) ;
else
V_263 = 0 ;
if ( F_60 ( V_10 ) )
V_262 = V_264 [ 3 ] & 0x03 ;
else
V_262 = 0 ;
if ( V_261 || V_262 || V_263 ) {
F_56 ( 1 , V_52 , V_10 ,
L_55 ,
V_53 , V_261 , V_262 ,
V_263 ) ;
F_108 ( V_10 , & V_222 ) ;
if ( V_260 )
* V_260 = true ;
}
if ( V_264 [ 5 ] & 0x08 ) {
F_56 ( 1 , V_52 , V_10 , L_56 , V_53 ,
( F_21 ( V_10 , 0x65 ) & 0x08 ) ? L_57 : L_58 ) ;
F_81 ( V_10 ) ;
if ( V_260 )
* V_260 = true ;
}
if ( V_264 [ 2 ] & 0x3 ) {
F_56 ( 1 , V_52 , V_10 , L_59 , V_53 ) ;
F_72 ( V_10 ) ;
if ( V_260 )
* V_260 = true ;
}
return 0 ;
}
static int F_120 ( struct V_9 * V_10 , struct V_265 * V_74 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 * V_20 = NULL ;
memset ( V_74 -> V_266 , 0 , sizeof( V_74 -> V_266 ) ) ;
switch ( V_74 -> V_170 ) {
case V_71 :
case V_72 :
if ( V_40 -> V_70 . V_69 & ( 0x04 << V_74 -> V_170 ) )
V_20 = V_40 -> V_70 . V_74 ;
break;
case V_267 :
if ( V_40 -> V_73 . V_69 )
V_20 = V_40 -> V_73 . V_74 ;
break;
default:
return - V_78 ;
}
if ( V_74 -> V_268 == 0 && V_74 -> V_269 == 0 ) {
V_74 -> V_269 = V_20 ? 2 : 0 ;
return 0 ;
}
if ( ! V_20 )
return - V_172 ;
if ( V_74 -> V_268 >= 2 )
return - V_78 ;
if ( V_74 -> V_268 + V_74 -> V_269 > 2 )
V_74 -> V_269 = 2 - V_74 -> V_268 ;
memcpy ( V_74 -> V_74 , V_20 + V_74 -> V_268 * 128 , V_74 -> V_269 * 128 ) ;
return 0 ;
}
static int F_121 ( struct V_9 * V_10 , struct V_265 * T_7 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 = 0 ;
memset ( T_7 -> V_266 , 0 , sizeof( T_7 -> V_266 ) ) ;
if ( T_7 -> V_170 > V_267 )
return - V_78 ;
if ( T_7 -> V_268 != 0 )
return - V_78 ;
if ( T_7 -> V_269 > 2 ) {
T_7 -> V_269 = 2 ;
return - V_270 ;
}
V_40 -> V_166 = F_122 ( T_7 -> V_74 [ 0x15 ] ,
T_7 -> V_74 [ 0x16 ] ) ;
switch ( T_7 -> V_170 ) {
case V_267 :
memset ( & V_40 -> V_73 . V_74 , 0 , 256 ) ;
V_40 -> V_73 . V_69 = T_7 -> V_269 ? 0x1 : 0x0 ;
memcpy ( & V_40 -> V_73 . V_74 , T_7 -> V_74 , 128 * T_7 -> V_269 ) ;
V_30 = F_64 ( V_10 ) ;
break;
case V_71 :
case V_72 :
memset ( & V_40 -> V_70 . V_74 , 0 , 256 ) ;
if ( T_7 -> V_269 )
V_40 -> V_70 . V_69 |= 0x04 << T_7 -> V_170 ;
else
V_40 -> V_70 . V_69 &= ~ ( 0x04 << T_7 -> V_170 ) ;
memcpy ( & V_40 -> V_70 . V_74 , T_7 -> V_74 , 128 * T_7 -> V_269 ) ;
V_30 = F_67 ( V_10 , T_7 -> V_170 ) ;
break;
default:
return - V_78 ;
}
if ( V_30 < 0 )
F_78 ( V_10 , L_60 , V_30 , T_7 -> V_170 ) ;
return V_30 ;
}
static void F_123 ( struct V_9 * V_10 , struct V_271 * V_272 )
{
int V_4 ;
T_2 V_273 [ 32 ] ;
union V_274 V_275 ;
T_2 V_81 ;
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_276 * V_277 = & V_16 -> V_277 ;
if ( ! ( F_21 ( V_10 , 0x60 ) & V_272 -> V_278 ) ) {
F_69 ( V_10 , L_61 , V_272 -> V_279 ) ;
return;
}
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ )
V_273 [ V_4 ] = F_31 ( V_10 , V_272 -> V_280 + V_4 ) ;
V_81 = V_273 [ 2 ] + 1 ;
if ( V_81 + 3 > sizeof( V_273 ) ) {
F_78 ( V_10 , L_62 , V_53 , V_272 -> V_279 , V_81 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_81 ; V_4 ++ )
V_273 [ V_4 + 3 ] = F_31 ( V_10 , V_272 -> V_281 + V_4 ) ;
if ( F_124 ( & V_275 , V_273 ) < 0 ) {
F_78 ( V_10 , L_63 , V_53 , V_272 -> V_279 ) ;
return;
}
F_125 ( V_282 , V_277 , & V_275 ) ;
}
static void F_126 ( struct V_9 * V_10 )
{
int V_4 ;
struct V_271 V_272 [] = {
{ L_64 , 0x01 , 0xe0 , 0x00 } ,
{ L_65 , 0x02 , 0xe3 , 0x1c } ,
{ L_66 , 0x04 , 0xe6 , 0x2a } ,
{ L_67 , 0x10 , 0xec , 0x54 }
} ;
if ( ! ( F_47 ( V_10 , 0x05 ) & 0x80 ) ) {
F_69 ( V_10 , L_68 ) ;
return;
}
for ( V_4 = 0 ; V_4 < F_58 ( V_272 ) ; V_4 ++ )
F_123 ( V_10 , & V_272 [ V_4 ] ) ;
}
static int F_127 ( struct V_9 * V_10 )
{
T_2 V_283 = F_36 ( V_10 , 0x5A ) & 0x01 ;
F_69 ( V_10 , L_69 , F_84 ( V_10 ) ? L_70 : L_71 ) ;
F_69 ( V_10 , L_72 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ) ;
F_69 ( V_10 , L_73 ,
( F_36 ( V_10 , 0x56 ) & 0x01 ) ? L_71 : L_70 ) ;
F_69 ( V_10 , L_74 , V_283 ?
L_75 : L_76 ) ;
if ( V_283 ) {
static const char * const V_284 [] = {
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
F_69 ( V_10 , L_93 ,
V_284 [ F_36 ( V_10 , 0x52 ) & 0x0f ] ) ;
F_69 ( V_10 , L_74 ,
( F_36 ( V_10 , 0x59 ) & 0x08 ) ? L_94 : L_95 ) ;
F_69 ( V_10 , L_74 ,
( F_36 ( V_10 , 0x57 ) & 0x08 ) ? L_96 : L_97 ) ;
F_69 ( V_10 , L_98 ,
( F_36 ( V_10 , 0x12 ) & 0x08 ) ? L_99 : L_100 ) ;
F_69 ( V_10 , L_101 ,
( F_33 ( V_10 , 0xe0 ) & 0x40 ) ? L_102 : L_103 ) ;
}
return 0 ;
}
static int F_128 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_1 V_92 ;
T_2 V_285 = F_21 ( V_10 , 0x02 ) ;
T_2 V_286 = F_21 ( V_10 , 0x21 ) ;
T_2 V_287 = F_42 ( V_10 , 0x77 ) ;
T_2 V_288 = F_42 ( V_10 , 0x7d ) ;
bool V_289 = F_47 ( V_10 , 0x04 ) & 0x01 ;
bool V_290 = F_47 ( V_10 , 0x18 ) & 0x01 ;
bool V_291 = F_21 ( V_10 , 0x65 ) & 0x40 ;
static const char * const V_292 [ 16 ] = {
L_104 , L_105 , L_106 , L_107 ,
L_106 , L_108 , L_106 , L_109 ,
L_106 , L_110 , L_111 ,
L_106 , L_106 , L_106 , L_106 , L_103
} ;
static const char * const V_293 [ 16 ] = {
L_112 , L_113 ,
L_114 , L_115 ,
L_116 , L_117 ,
L_118 , L_119 ,
L_120 , L_120 , L_120 , L_120 , L_120 ,
L_120 , L_120 , L_121
} ;
static const char * const V_294 [] = {
L_122 ,
L_112 ,
L_113 ,
} ;
static const char * const V_295 [ 4 ] = {
L_123 ,
L_124 ,
L_125 ,
L_126
} ;
F_69 ( V_10 , L_127 ) ;
F_69 ( V_10 , L_128 , F_84 ( V_10 ) ? L_70 : L_71 ) ;
F_69 ( V_10 , L_129 ,
V_40 -> V_209 ? L_130 : L_131 ) ;
F_69 ( V_10 , L_132 ,
( ( V_288 & 0x04 ) && ( V_287 & 0x04 ) ) ?
L_99 : L_100 ,
( ( V_288 & 0x08 ) && ( V_287 & 0x08 ) ) ?
L_99 : L_100 ) ;
F_69 ( V_10 , L_133 ,
V_286 & 0x02 ? L_99 : L_100 ,
V_286 & 0x01 ? L_99 : L_100 ) ;
F_69 ( V_10 , L_134 , ! ! ( F_28 ( V_10 , 0x2a ) & 0x01 ) ?
L_99 : L_100 ) ;
F_69 ( V_10 , L_135 ) ;
if ( V_40 -> V_209 ) {
F_69 ( V_10 , L_136 ,
F_21 ( V_10 , 0x6f ) & 0x02 ? L_137 : L_138 ) ;
F_69 ( V_10 , L_139 ,
( F_21 ( V_10 , 0x6a ) & 0x02 ) ? L_137 : L_138 ) ;
F_69 ( V_10 , L_140 ,
( F_21 ( V_10 , 0x6a ) & 0x20 ) ? L_137 : L_138 ) ;
} else {
F_69 ( V_10 , L_141 ,
F_21 ( V_10 , 0x6f ) & 0x01 ? L_137 : L_138 ) ;
F_69 ( V_10 , L_139 ,
( F_21 ( V_10 , 0x6a ) & 0x01 ) ? L_137 : L_138 ) ;
F_69 ( V_10 , L_140 ,
( F_21 ( V_10 , 0x6a ) & 0x10 ) ? L_137 : L_138 ) ;
}
F_69 ( V_10 , L_142 ,
( ! ! ( F_50 ( V_10 , 0xff ) & 0x10 ) ? L_71 : L_70 ) ) ;
F_69 ( V_10 , L_143 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ,
( F_21 ( V_10 , 0x01 ) & 0x70 ) >> 4 ) ;
F_69 ( V_10 , L_144 ) ;
if ( F_85 ( V_10 ) ) {
F_69 ( V_10 , L_145 ) ;
} else {
T_3 V_157 = ( ( F_50 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_50 ( V_10 , 0xb2 ) ;
T_3 V_160 = ( ( F_50 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_50 ( V_10 , 0xb4 ) ;
T_3 V_161 = F_50 ( V_10 , 0xb3 ) >> 3 ;
T_3 V_296 = ( ( F_50 ( V_10 , 0xb8 ) & 0x1f ) << 8 ) | F_50 ( V_10 , 0xb9 ) ;
char V_162 = ( ( F_50 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_50 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
char V_164 = ( ( F_50 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_50 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
F_69 ( V_10 ,
L_146 ,
V_160 , V_157 , V_161 , V_296 ,
( F_50 ( V_10 , 0xb1 ) & 0x40 ) ?
L_43 : L_44 ,
V_162 , V_164 ) ;
}
if ( F_98 ( V_10 , & V_92 ) )
F_69 ( V_10 , L_147 ) ;
else
F_99 ( V_10 -> V_189 , L_148 ,
& V_92 , true ) ;
F_99 ( V_10 -> V_189 , L_149 ,
& V_40 -> V_92 , true ) ;
if ( F_85 ( V_10 ) )
return 0 ;
F_69 ( V_10 , L_150 ) ;
F_69 ( V_10 , L_151 ,
V_294 [ V_40 -> V_128 ] ) ;
F_69 ( V_10 , L_152 ,
V_293 [ V_285 >> 4 ] ) ;
F_69 ( V_10 , L_153 ,
( V_285 & 0x02 ) ? L_154 : L_155 ,
( V_285 & 0x04 ) ? L_156 : L_157 ,
( ( V_285 & 0x04 ) ^ ( V_285 & 0x01 ) ) ?
L_99 : L_100 ) ;
F_69 ( V_10 , L_158 ,
V_292 [ F_50 ( V_10 , 0xf4 ) >> 4 ] ) ;
if ( ! F_60 ( V_10 ) )
return 0 ;
F_69 ( V_10 , L_159 , F_86 ( V_10 ) ? L_57 : L_160 ) ;
F_69 ( V_10 , L_161 ,
( F_47 ( V_10 , 0x05 ) & 0x40 ) ? L_137 : L_138 ) ;
F_69 ( V_10 , L_162 ,
( F_47 ( V_10 , 0x04 ) & 0x20 ) ? L_163 : L_164 ,
( F_47 ( V_10 , 0x04 ) & 0x10 ) ? L_165 : L_166 ) ;
if ( ! F_86 ( V_10 ) )
return 0 ;
F_69 ( V_10 , L_167 ,
V_289 ? L_168 : L_169 ,
V_290 ? L_170 : L_171 ,
V_291 ? L_172 : L_99 ) ;
if ( V_289 && V_290 ) {
F_69 ( V_10 , L_173 ,
( F_47 ( V_10 , 0x07 ) & 0x40 ) ? L_174 : L_175 ) ;
}
F_69 ( V_10 , L_176 , ( F_47 ( V_10 , 0x5b ) << 12 ) +
( F_47 ( V_10 , 0x5c ) << 8 ) +
( F_47 ( V_10 , 0x5d ) & 0xf0 ) ) ;
F_69 ( V_10 , L_177 , ( ( F_47 ( V_10 , 0x5d ) & 0x0f ) << 16 ) +
( F_47 ( V_10 , 0x5e ) << 8 ) +
F_47 ( V_10 , 0x5f ) ) ;
F_69 ( V_10 , L_178 ,
( F_47 ( V_10 , 0x04 ) & 0x40 ) ? L_71 : L_70 ) ;
F_69 ( V_10 , L_179 ,
V_295 [ F_47 ( V_10 , 0x0b ) >> 6 ] ) ;
F_126 ( V_10 ) ;
return 0 ;
}
static int F_129 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_57 == V_152 )
return F_127 ( V_10 ) ;
return F_128 ( V_10 ) ;
}
static int F_130 ( struct V_9 * V_10 , T_10 * V_297 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_57 != V_152 )
return - V_172 ;
if ( ! ( F_36 ( V_10 , 0x5A ) & 0x01 ) ) {
* V_297 = 0 ;
F_56 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return 0 ;
}
switch ( F_36 ( V_10 , 0x52 ) & 0x0f ) {
case 0 :
* V_297 &= V_298 ;
break;
case 2 :
* V_297 &= V_299 ;
break;
case 3 :
* V_297 &= V_300 ;
break;
case 4 :
* V_297 &= V_301 ;
break;
case 6 :
* V_297 &= V_302 ;
break;
case 0xc :
* V_297 &= V_303 ;
break;
case 0xe :
* V_297 &= V_304 ;
break;
case 0xf :
* V_297 &= V_300 ;
break;
default:
* V_297 &= V_305 ;
break;
}
return 0 ;
}
static void F_131 ( struct V_9 * V_10 , struct V_306 * V_307 )
{
if ( V_307 && V_307 -> V_308 ) {
F_34 ( V_10 , 0x94 , ( V_307 -> V_309 >> 8 ) & 0xf ) ;
F_34 ( V_10 , 0x95 , V_307 -> V_309 & 0xff ) ;
F_34 ( V_10 , 0x96 , ( V_307 -> V_310 >> 8 ) & 0xf ) ;
F_34 ( V_10 , 0x97 , V_307 -> V_310 & 0xff ) ;
F_34 ( V_10 , 0x98 , ( V_307 -> V_311 >> 8 ) & 0xf ) ;
F_34 ( V_10 , 0x99 , V_307 -> V_311 & 0xff ) ;
F_34 ( V_10 , 0x9a , ( V_307 -> V_312 >> 8 ) & 0xf ) ;
F_34 ( V_10 , 0x9b , V_307 -> V_312 & 0xff ) ;
F_34 ( V_10 , 0xa8 , V_307 -> V_313 ) ;
F_34 ( V_10 , 0xa9 , V_307 -> V_314 ) ;
F_34 ( V_10 , 0xaa , V_307 -> V_315 ) ;
F_34 ( V_10 , 0xab , V_307 -> V_316 ) ;
F_34 ( V_10 , 0xac , V_307 -> V_317 ) ;
F_34 ( V_10 , 0xad , V_307 -> V_318 ) ;
F_34 ( V_10 , 0xae , V_307 -> V_319 ) ;
F_34 ( V_10 , 0xaf , V_307 -> V_320 ) ;
} else {
F_34 ( V_10 , 0x94 , 0x00 ) ;
F_34 ( V_10 , 0x95 , 0x00 ) ;
F_34 ( V_10 , 0x96 , 0x00 ) ;
F_34 ( V_10 , 0x97 , 0x20 ) ;
F_34 ( V_10 , 0x98 , 0x00 ) ;
F_34 ( V_10 , 0x99 , 0x00 ) ;
F_34 ( V_10 , 0x9a , 0x00 ) ;
F_34 ( V_10 , 0x9b , 0x00 ) ;
F_34 ( V_10 , 0xa8 , 0x04 ) ;
F_34 ( V_10 , 0xa9 , 0x04 ) ;
F_34 ( V_10 , 0xaa , 0x04 ) ;
F_34 ( V_10 , 0xab , 0x04 ) ;
F_34 ( V_10 , 0xac , 0x04 ) ;
F_34 ( V_10 , 0xad , 0x04 ) ;
F_34 ( V_10 , 0xae , 0x04 ) ;
F_34 ( V_10 , 0xaf , 0x04 ) ;
}
}
static int F_132 ( struct V_9 * V_10 , T_10 V_253 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_321 * V_242 = & V_40 -> V_242 ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_57 != V_152 )
return - V_172 ;
if ( V_253 & V_322 )
F_131 ( V_10 , & V_242 -> V_323 ) ;
else if ( V_253 & V_254 )
F_131 ( V_10 , & V_242 -> V_324 ) ;
else
F_131 ( V_10 , NULL ) ;
if ( V_253 & V_305 ) {
V_40 -> V_253 = V_253 ;
return 0 ;
}
return - V_78 ;
}
static int F_133 ( struct V_9 * V_10 , T_10 * V_253 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_57 != V_152 )
return - V_172 ;
* V_253 = V_40 -> V_253 ;
return 0 ;
}
static int F_134 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_321 * V_242 = & V_40 -> V_242 ;
F_48 ( V_10 , 0x48 ,
( V_242 -> V_325 ? 0x80 : 0 ) |
( V_242 -> V_326 ? 0x40 : 0 ) ) ;
F_103 ( V_10 ) ;
F_44 ( V_10 , 0x77 , 0xd3 , 0x20 ) ;
F_23 ( V_10 , 0x0c , 0x42 ) ;
F_23 ( V_10 , 0x15 , 0x80 ) ;
F_23 ( V_10 , 0x02 ,
0xf0 |
V_242 -> V_327 << 3 |
V_242 -> V_328 << 2 |
V_242 -> V_329 << 0 ) ;
F_24 ( V_10 , 0x05 , 0xf0 , V_242 -> V_330 << 3 |
V_242 -> V_331 << 2 |
V_242 -> V_332 << 1 ) ;
F_114 ( V_40 ) ;
F_49 ( V_10 , 0x1a , 0xf1 , 0x08 ) ;
F_24 ( V_10 , 0x14 , 0xc0 ,
V_242 -> V_333 << 4 |
V_242 -> V_334 << 2 |
V_242 -> V_335 ) ;
F_52 ( V_10 , 0xba , 0xfc , V_242 -> V_336 |
( V_242 -> V_337 << 1 ) ) ;
F_38 ( V_10 , 0xdd , 0xf0 , V_242 -> V_338 |
( V_242 -> V_339 << 1 ) |
( V_242 -> V_340 << 2 ) |
( V_242 -> V_341 << 3 ) ) ;
F_51 ( V_10 , 0x69 , 0x14 ) ;
F_23 ( V_10 , 0x06 , 0xa6 ) ;
F_51 ( V_10 , 0xf3 , 0xdc ) ;
F_40 ( V_10 , 0xb5 , 0x01 ) ;
F_40 ( V_10 , 0x02 , V_242 -> V_342 ) ;
F_24 ( V_10 , 0x30 , ~ ( 1 << 4 ) , V_242 -> V_343 << 4 ) ;
F_105 ( V_10 , & V_242 -> F_105 ) ;
if ( V_242 -> V_344 >= 128 ) {
F_37 ( V_10 , 0x12 , 0x0d ) ;
if ( V_242 -> V_345 ) {
F_34 ( V_10 , 0x6f , 0x00 ) ;
F_34 ( V_10 , 0x75 , 0x0a ) ;
F_34 ( V_10 , 0x7a , 0xa5 ) ;
F_34 ( V_10 , 0x7b , 0x8f ) ;
F_34 ( V_10 , 0x60 , 0x01 ) ;
} else {
F_34 ( V_10 , 0x75 , 0x0a ) ;
F_34 ( V_10 , 0x74 , 0x00 ) ;
F_34 ( V_10 , 0x79 , 0x33 ) ;
F_34 ( V_10 , 0x6f , 0x01 ) ;
F_34 ( V_10 , 0x7a , 0xa5 ) ;
F_34 ( V_10 , 0x7b , 0x8f ) ;
F_34 ( V_10 , 0x60 , 0x01 ) ;
}
} else {
F_34 ( V_10 , 0x29 , 0x10 ) ;
}
F_106 ( V_10 , V_242 -> V_207 ) ;
F_102 ( V_10 ) ;
if ( V_242 -> V_346 ) {
F_48 ( V_10 , 0x69 , 0x5c ) ;
} else {
F_48 ( V_10 , 0x69 , 0xa3 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
}
F_23 ( V_10 , 0x19 , 0x80 | V_242 -> V_347 ) ;
F_23 ( V_10 , 0x33 , 0x40 ) ;
F_23 ( V_10 , 0x40 , 0xf2 ) ;
F_118 ( V_10 , true ) ;
return F_135 ( V_10 -> V_348 ) ;
}
static int F_136 ( struct V_9 * V_10 )
{
int V_4 ;
int V_349 = 0 ;
int V_350 = 0 ;
int V_351 = 0 ;
F_23 ( V_10 , 0x00 , 0x01 ) ;
F_23 ( V_10 , 0x01 , 0x00 ) ;
F_40 ( V_10 , 0x80 , 0x92 ) ;
F_40 ( V_10 , 0x9B , 0x01 ) ;
F_40 ( V_10 , 0x9C , 0x60 ) ;
F_40 ( V_10 , 0x9E , 0x02 ) ;
F_40 ( V_10 , 0xA0 , 0x0B ) ;
F_40 ( V_10 , 0xC3 , 0x02 ) ;
F_23 ( V_10 , 0x0C , 0x40 ) ;
F_23 ( V_10 , 0x15 , 0xBA ) ;
F_37 ( V_10 , 0x12 , 0x00 ) ;
F_23 ( V_10 , 0xFF , 0x04 ) ;
F_57 ( 5 ) ;
F_37 ( V_10 , 0x12 , 0x00 ) ;
F_34 ( V_10 , 0x2A , 0x01 ) ;
F_34 ( V_10 , 0x7c , 0x19 ) ;
F_34 ( V_10 , 0x80 , 0x87 ) ;
F_34 ( V_10 , 0x81 , 0x4a ) ;
F_34 ( V_10 , 0x82 , 0x2c ) ;
F_34 ( V_10 , 0x83 , 0x0e ) ;
F_34 ( V_10 , 0x84 , 0x94 ) ;
F_34 ( V_10 , 0x85 , 0x62 ) ;
F_34 ( V_10 , 0x7d , 0x00 ) ;
F_34 ( V_10 , 0x7e , 0x1a ) ;
F_57 ( 5 ) ;
F_34 ( V_10 , 0xd9 , 0xd5 ) ;
F_37 ( V_10 , 0x12 , 0x05 ) ;
F_57 ( 20 ) ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
T_2 V_352 = F_33 ( V_10 , 0xdb ) ;
if ( V_352 & 0x10 ) {
V_351 ++ ;
if ( V_352 & 0x20 )
V_350 ++ ;
else
V_349 ++ ;
}
F_57 ( 20 ) ;
}
F_56 ( 1 , V_52 , V_10 ,
L_180 ,
V_351 , V_4 , V_349 , V_350 ) ;
if ( ! V_351 || V_350 )
return - V_27 ;
return 0 ;
}
static void F_137 ( struct V_9 * V_10 ,
struct V_321 * V_242 )
{
F_23 ( V_10 , 0xf1 , V_242 -> V_45 << 1 ) ;
F_23 ( V_10 , 0xf2 , V_242 -> V_44 << 1 ) ;
F_23 ( V_10 , 0xf3 , V_242 -> V_41 << 1 ) ;
F_23 ( V_10 , 0xf4 , V_242 -> V_42 << 1 ) ;
F_23 ( V_10 , 0xf5 , V_242 -> V_43 << 1 ) ;
F_23 ( V_10 , 0xf8 , V_242 -> V_46 << 1 ) ;
F_23 ( V_10 , 0xf9 , V_242 -> V_47 << 1 ) ;
F_23 ( V_10 , 0xfa , V_242 -> V_48 << 1 ) ;
F_23 ( V_10 , 0xfb , V_242 -> V_49 << 1 ) ;
F_23 ( V_10 , 0xfd , V_242 -> V_50 << 1 ) ;
F_23 ( V_10 , 0xfe , V_242 -> V_51 << 1 ) ;
}
static int F_138 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_321 * V_242 = V_16 -> V_277 . V_353 ;
struct V_1 V_92 ;
int V_28 = 0 ;
if ( ! V_242 )
return - V_354 ;
if ( ! V_242 -> V_344 || ! V_242 -> V_345 ) {
F_69 ( V_10 , L_181 ) ;
return - V_78 ;
}
F_55 ( V_10 ) ;
F_137 ( V_10 , V_242 ) ;
V_28 = F_136 ( V_10 ) ;
F_55 ( V_10 ) ;
F_137 ( V_10 , V_242 ) ;
F_134 ( V_10 ) ;
F_103 ( V_10 ) ;
F_106 ( V_10 , V_40 -> V_207 ) ;
F_102 ( V_10 ) ;
F_64 ( V_10 ) ;
F_67 ( V_10 , V_71 ) ;
F_67 ( V_10 , V_72 ) ;
V_92 = V_40 -> V_92 ;
memset ( & V_40 -> V_92 , 0 , sizeof( struct V_1 ) ) ;
F_100 ( V_10 , & V_92 ) ;
return V_28 ;
}
static long F_139 ( struct V_9 * V_10 , unsigned int V_355 , void * V_356 )
{
switch ( V_355 ) {
case V_357 :
return F_138 ( V_10 ) ;
}
return - V_358 ;
}
static int F_140 ( struct V_9 * V_10 ,
struct V_359 * V_360 ,
struct V_361 * V_362 )
{
switch ( V_362 -> type ) {
case V_363 :
return F_141 ( V_10 , V_360 , V_362 ) ;
case V_364 :
return F_142 ( V_10 , V_360 , V_362 ) ;
default:
return - V_78 ;
}
}
static void F_143 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_41 )
F_144 ( V_40 -> V_41 ) ;
if ( V_40 -> V_42 )
F_144 ( V_40 -> V_42 ) ;
if ( V_40 -> V_43 )
F_144 ( V_40 -> V_43 ) ;
if ( V_40 -> V_44 )
F_144 ( V_40 -> V_44 ) ;
if ( V_40 -> V_45 )
F_144 ( V_40 -> V_45 ) ;
if ( V_40 -> V_46 )
F_144 ( V_40 -> V_46 ) ;
if ( V_40 -> V_47 )
F_144 ( V_40 -> V_47 ) ;
if ( V_40 -> V_48 )
F_144 ( V_40 -> V_48 ) ;
if ( V_40 -> V_49 )
F_144 ( V_40 -> V_49 ) ;
if ( V_40 -> V_50 )
F_144 ( V_40 -> V_50 ) ;
if ( V_40 -> V_51 )
F_144 ( V_40 -> V_51 ) ;
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
static struct V_15 * F_145 ( struct V_9 * V_10 , const char * V_279 ,
T_2 V_22 , T_2 V_365 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_15 * V_366 ;
F_23 ( V_10 , V_365 , V_22 << 1 ) ;
if ( V_22 == 0 ) {
F_78 ( V_10 , L_182 , V_279 ) ;
return NULL ;
}
V_366 = F_146 ( V_16 -> V_21 , F_21 ( V_10 , V_365 ) >> 1 ) ;
if ( ! V_366 )
F_78 ( V_10 , L_183 , V_279 , V_22 ) ;
return V_366 ;
}
static int F_147 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_321 * V_242 = & V_40 -> V_242 ;
V_40 -> V_41 = F_145 ( V_10 , L_184 , V_242 -> V_41 , 0xf3 ) ;
V_40 -> V_42 = F_145 ( V_10 , L_185 , V_242 -> V_42 , 0xf4 ) ;
V_40 -> V_43 = F_145 ( V_10 , L_186 , V_242 -> V_43 , 0xf5 ) ;
V_40 -> V_44 = F_145 ( V_10 , L_187 , V_242 -> V_44 , 0xf2 ) ;
V_40 -> V_45 = F_145 ( V_10 , L_188 , V_242 -> V_45 , 0xf1 ) ;
V_40 -> V_46 = F_145 ( V_10 , L_189 , V_242 -> V_46 , 0xf8 ) ;
V_40 -> V_47 = F_145 ( V_10 , L_190 , V_242 -> V_47 , 0xf9 ) ;
V_40 -> V_48 = F_145 ( V_10 , L_191 , V_242 -> V_48 , 0xfa ) ;
V_40 -> V_49 = F_145 ( V_10 , L_192 , V_242 -> V_49 , 0xfb ) ;
V_40 -> V_50 = F_145 ( V_10 , L_193 , V_242 -> V_50 , 0xfd ) ;
V_40 -> V_51 = F_145 ( V_10 , L_194 , V_242 -> V_51 , 0xfe ) ;
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
static int F_148 ( struct V_15 * V_16 ,
const struct V_367 * V_133 )
{
struct V_8 * V_40 ;
static const struct V_1 V_368 =
V_369 ;
struct V_321 * V_242 = V_16 -> V_277 . V_353 ;
struct V_370 * V_3 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
T_4 V_371 ;
int V_30 ;
if ( ! F_149 ( V_16 -> V_21 , V_372 ) )
return - V_27 ;
F_150 ( 1 , V_52 , V_16 , L_195 ,
V_16 -> V_22 << 1 ) ;
if ( ! V_242 ) {
F_16 ( V_16 , L_196 ) ;
return - V_354 ;
}
V_40 = F_151 ( & V_16 -> V_277 , sizeof( struct V_8 ) , V_373 ) ;
if ( ! V_40 ) {
F_16 ( V_16 , L_197 ) ;
return - V_374 ;
}
V_40 -> V_242 = * V_242 ;
V_40 -> V_92 = V_368 ;
V_40 -> V_228 = V_54 ( V_40 , V_252 ) ;
V_10 = & V_40 -> V_10 ;
F_152 ( V_10 , V_16 , & V_375 ) ;
V_10 -> V_23 |= V_376 | V_377 ;
V_40 -> V_57 = V_242 -> V_57 ;
V_40 -> V_209 = V_242 -> V_210 == V_213 ;
V_40 -> V_173 = true ;
V_371 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
if ( V_371 != 0x2012 ) {
F_69 ( V_10 , L_198 , V_371 ) ;
V_371 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
}
if ( V_371 != 0x2012 ) {
F_69 ( V_10 , L_199 ,
V_16 -> V_22 << 1 , V_371 ) ;
return - V_354 ;
}
if ( V_242 -> V_378 )
F_55 ( V_10 ) ;
V_3 = & V_40 -> V_3 ;
F_153 ( V_3 , 6 ) ;
F_154 ( V_3 , & V_379 ,
V_134 , - 128 , 127 , 1 , 0 ) ;
F_154 ( V_3 , & V_379 ,
V_135 , 0 , 255 , 1 , 128 ) ;
F_154 ( V_3 , & V_379 ,
V_136 , 0 , 255 , 1 , 128 ) ;
F_154 ( V_3 , & V_379 ,
V_137 , 0 , 128 , 1 , 0 ) ;
V_12 = F_155 ( V_3 , & V_379 ,
V_148 , V_149 ,
0 , V_149 ) ;
if ( V_12 )
V_12 -> V_23 |= V_380 ;
V_40 -> V_87 = F_154 ( V_3 , NULL ,
V_381 , 0 , 3 , 0 , 0 ) ;
V_40 -> V_382 = F_156 ( V_3 ,
& V_383 , NULL ) ;
V_40 -> V_384 = F_156 ( V_3 ,
& V_385 , NULL ) ;
V_40 -> V_386 = F_156 ( V_3 ,
& V_387 , NULL ) ;
V_40 -> V_388 =
F_155 ( V_3 , & V_379 ,
V_147 , V_132 ,
0 , V_129 ) ;
V_10 -> V_348 = V_3 ;
if ( V_3 -> error ) {
V_30 = V_3 -> error ;
goto V_389;
}
V_40 -> V_87 -> V_390 = true ;
V_40 -> V_388 -> V_390 = true ;
V_40 -> V_382 -> V_390 = true ;
V_40 -> V_384 -> V_390 = true ;
V_40 -> V_386 -> V_390 = true ;
if ( F_72 ( V_10 ) ) {
V_30 = - V_354 ;
goto V_389;
}
if ( F_147 ( V_10 ) < 0 ) {
V_30 = - V_374 ;
F_78 ( V_10 , L_200 ) ;
goto V_391;
}
V_40 -> V_75 = F_157 ( V_16 -> V_189 ) ;
if ( ! V_40 -> V_75 ) {
F_78 ( V_10 , L_201 ) ;
V_30 = - V_374 ;
goto V_391;
}
F_158 ( & V_40 -> V_68 ,
F_62 ) ;
V_40 -> V_170 . V_23 = V_392 ;
V_30 = F_159 ( & V_10 -> V_393 , 1 , & V_40 -> V_170 ) ;
if ( V_30 )
goto V_394;
V_30 = F_134 ( V_10 ) ;
if ( V_30 )
goto V_395;
F_69 ( V_10 , L_202 , V_16 -> V_189 ,
V_16 -> V_22 << 1 , V_16 -> V_21 -> V_189 ) ;
return 0 ;
V_395:
F_160 ( & V_10 -> V_393 ) ;
V_394:
F_161 ( & V_40 -> V_68 ) ;
F_162 ( V_40 -> V_75 ) ;
V_391:
F_143 ( V_10 ) ;
V_389:
F_163 ( V_3 ) ;
return V_30 ;
}
static int F_164 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = F_165 ( V_16 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_118 ( V_10 , false ) ;
F_161 ( & V_40 -> V_68 ) ;
F_162 ( V_40 -> V_75 ) ;
F_166 ( V_10 ) ;
F_160 ( & V_10 -> V_393 ) ;
F_143 ( V_10 ) ;
F_163 ( V_10 -> V_348 ) ;
return 0 ;
}
