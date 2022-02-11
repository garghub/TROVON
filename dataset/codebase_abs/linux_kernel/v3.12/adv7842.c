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
static inline int F_48 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_50 , V_37 ) ;
}
static inline int F_49 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_50 , V_37 , V_38 ) ;
}
static inline int F_50 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_39 , T_2 V_38 )
{
return F_49 ( V_10 , V_37 , ( F_48 ( V_10 , V_37 ) & V_39 ) | V_38 ) ;
}
static inline int F_51 ( struct V_9 * V_10 , T_2 V_37 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_17 ( V_40 -> V_51 , V_37 ) ;
}
static inline int F_52 ( struct V_9 * V_10 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return F_18 ( V_40 -> V_51 , V_37 , V_38 ) ;
}
static void F_53 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
F_54 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
F_19 ( V_16 , 0xff , 0x80 ) ;
F_55 ( 2 ) ;
}
static inline bool F_56 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
return V_40 -> V_54 == V_55 ;
}
static inline const struct V_56 *
F_57 ( struct V_9 * V_10 )
{
return F_56 ( V_10 ) ? & V_57 :
& V_58 ;
}
static void F_58 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_59 ( V_60 ) ;
struct V_8 * V_40 = F_4 ( V_62 ,
struct V_8 , V_63 ) ;
struct V_9 * V_10 = & V_40 -> V_10 ;
int V_64 = V_40 -> V_65 . V_64 ;
T_2 V_39 = 0 ;
F_54 ( 2 , V_52 , V_10 , L_6 ,
V_53 , V_64 ) ;
if ( V_64 & 0x1 )
V_39 |= 0x20 ;
if ( V_64 & 0x2 )
V_39 |= 0x10 ;
F_24 ( V_10 , 0x20 , 0xcf , V_39 ) ;
}
static int F_60 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_66 . V_67 ;
int V_30 = 0 ;
int V_4 ;
F_54 ( 2 , V_52 , V_10 , L_7 , V_53 ) ;
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
F_55 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_16 ( V_16 , L_8 ) ;
return - V_27 ;
}
F_61 ( V_40 -> V_68 ,
& V_40 -> V_63 , V_69 / 5 ) ;
return 0 ;
}
static int F_62 ( const T_2 * V_67 )
{
T_2 V_70 ;
if ( ( V_67 [ 0x7e ] != 1 ) ||
( V_67 [ 0x80 ] != 0x02 ) ||
( V_67 [ 0x81 ] != 0x03 ) ) {
return - V_71 ;
}
V_70 = V_67 [ 0x82 ] & 0x7f ;
if ( V_70 > 4 ) {
int V_4 = 0x84 ;
int V_72 = 0x80 + V_70 ;
do {
T_2 V_73 = V_67 [ V_4 ] >> 5 ;
T_2 V_74 = V_67 [ V_4 ] & 0x1f ;
if ( ( V_73 == 3 ) && ( V_74 >= 5 ) )
return V_4 + 4 ;
V_4 += V_74 + 1 ;
} while ( V_4 < V_72 );
}
return - V_71 ;
}
static int F_63 ( struct V_9 * V_10 , T_2 V_75 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_38 = V_40 -> V_65 . V_67 ;
T_2 V_76 = F_41 ( V_10 , 0x77 ) & 0x0c ;
T_2 V_39 = V_75 == 0 ? 0x4 : 0x8 ;
int V_77 = F_62 ( V_38 ) ;
int V_30 = 0 ;
int V_4 ;
F_54 ( 2 , V_52 , V_10 , L_9 ,
V_53 , V_75 , V_77 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_43 ( V_10 , 0x77 , 0xf3 , 0x00 ) ;
F_43 ( V_10 , 0x77 , 0xef , 0x00 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_20 ( V_40 -> V_48 , V_4 ,
V_34 , V_38 + V_4 ) ;
if ( V_30 )
return V_30 ;
if ( V_77 > 0 ) {
if ( V_75 == 0 ) {
F_42 ( V_10 , 0x72 , V_38 [ V_77 ] ) ;
F_42 ( V_10 , 0x73 , V_38 [ V_77 + 1 ] ) ;
} else {
F_42 ( V_10 , 0x74 , V_38 [ V_77 ] ) ;
F_42 ( V_10 , 0x75 , V_38 [ V_77 + 1 ] ) ;
}
F_42 ( V_10 , 0x76 , V_77 ) ;
} else {
if ( V_75 == 0 ) {
F_42 ( V_10 , 0x72 , 0 ) ;
F_42 ( V_10 , 0x73 , 0 ) ;
} else {
F_42 ( V_10 , 0x74 , 0 ) ;
F_42 ( V_10 , 0x75 , 0 ) ;
}
F_42 ( V_10 , 0x76 , 0xc0 ) ;
}
F_43 ( V_10 , 0x77 , 0xbf , 0x00 ) ;
F_43 ( V_10 , 0x77 , 0xf3 , V_39 | V_76 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_41 ( V_10 , 0x7d ) & V_39 )
break;
F_55 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_16 ( V_16 , L_10 , V_75 ) ;
return - V_27 ;
}
F_61 ( V_40 -> V_68 ,
& V_40 -> V_63 , V_69 / 5 ) ;
return 0 ;
}
static void F_64 ( struct V_9 * V_10 )
{
F_65 ( V_10 , L_11 ) ;
F_65 ( V_10 , L_12 ) ;
F_65 ( V_10 , L_13 ) ;
F_65 ( V_10 , L_14 ) ;
F_65 ( V_10 , L_15 ) ;
F_65 ( V_10 , L_16 ) ;
F_65 ( V_10 , L_17 ) ;
F_65 ( V_10 , L_18 ) ;
F_65 ( V_10 , L_19 ) ;
F_65 ( V_10 , L_20 ) ;
F_65 ( V_10 , L_21 ) ;
F_65 ( V_10 , L_22 ) ;
}
static int F_66 ( struct V_9 * V_10 ,
struct V_78 * V_37 )
{
V_37 -> V_79 = 1 ;
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
V_37 -> V_38 = F_48 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
case 0xb :
V_37 -> V_38 = F_51 ( V_10 , V_37 -> V_37 & 0xff ) ;
break;
default:
F_65 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_64 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_67 ( struct V_9 * V_10 ,
const struct V_78 * V_37 )
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
F_49 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
case 0xb :
F_52 ( V_10 , V_37 -> V_37 & 0xff , V_38 ) ;
break;
default:
F_65 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_64 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_68 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_80 = F_69 ( V_40 -> V_81 ) ;
T_2 V_82 = F_21 ( V_10 , 0x6f ) ;
int V_38 = 0 ;
if ( V_82 & 0x02 )
V_38 |= 1 ;
if ( V_82 & 0x01 )
V_38 |= 2 ;
F_54 ( 1 , V_52 , V_10 , L_24 , V_53 , V_80 , V_38 ) ;
if ( V_38 != V_80 )
return F_70 ( V_40 -> V_81 , V_38 ) ;
return 0 ;
}
static int F_71 ( struct V_9 * V_10 ,
T_2 V_83 ,
const struct V_84 * V_85 ,
const struct V_1 * V_86 )
{
int V_4 ;
for ( V_4 = 0 ; V_85 [ V_4 ] . V_86 . V_6 . V_7 ; V_4 ++ ) {
if ( ! F_2 ( V_86 , & V_85 [ V_4 ] . V_86 ,
F_56 ( V_10 ) ? 250000 : 1000000 ) )
continue;
F_23 ( V_10 , 0x00 , V_85 [ V_4 ] . V_87 ) ;
F_23 ( V_10 , 0x01 , ( V_85 [ V_4 ] . V_88 << 4 ) + V_83 ) ;
return 0 ;
}
return - 1 ;
}
static int F_72 ( struct V_9 * V_10 ,
struct V_1 * V_86 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 ;
F_54 ( 1 , V_52 , V_10 , L_25 , V_53 ) ;
F_23 ( V_10 , 0x16 , 0x43 ) ;
F_23 ( V_10 , 0x17 , 0x5a ) ;
F_50 ( V_10 , 0x81 , 0xef , 0x00 ) ;
F_49 ( V_10 , 0x26 , 0x00 ) ;
F_49 ( V_10 , 0x27 , 0x00 ) ;
F_49 ( V_10 , 0x28 , 0x00 ) ;
F_49 ( V_10 , 0x29 , 0x00 ) ;
F_49 ( V_10 , 0x8f , 0x00 ) ;
F_49 ( V_10 , 0x90 , 0x00 ) ;
F_49 ( V_10 , 0xa5 , 0x00 ) ;
F_49 ( V_10 , 0xa6 , 0x00 ) ;
F_49 ( V_10 , 0xa7 , 0x00 ) ;
F_49 ( V_10 , 0xab , 0x00 ) ;
F_49 ( V_10 , 0xac , 0x00 ) ;
switch ( V_40 -> V_54 ) {
case V_89 :
case V_90 :
V_30 = F_71 ( V_10 ,
0x01 , V_91 , V_86 ) ;
if ( V_30 )
V_30 = F_71 ( V_10 ,
0x02 , V_92 , V_86 ) ;
break;
case V_55 :
V_30 = F_71 ( V_10 ,
0x05 , V_93 , V_86 ) ;
if ( V_30 )
V_30 = F_71 ( V_10 ,
0x06 , V_94 , V_86 ) ;
break;
default:
F_54 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
V_30 = - 1 ;
break;
}
return V_30 ;
}
static void F_73 ( struct V_9 * V_10 ,
const struct V_14 * V_6 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_15 * V_16 = F_22 ( V_10 ) ;
T_3 V_7 = F_8 ( V_6 ) ;
T_3 V_95 = F_12 ( V_6 ) ;
T_4 V_96 = V_6 -> V_97 + V_6 -> V_98 - 4 ;
T_4 V_99 = V_7 - V_6 -> V_100 ;
T_4 V_101 = V_95 - V_6 -> V_102 + 1 ;
T_4 V_103 = V_6 -> V_104 + V_6 -> V_105 + 1 ;
T_4 V_106 = ( ( ( T_3 ) V_6 -> V_107 / 100 ) > 0 ) ?
( ( V_7 * ( V_108 / 100 ) ) / ( ( T_3 ) V_6 -> V_107 / 100 ) ) : 0 ;
const T_2 V_109 [ 2 ] = {
0xc0 | ( ( V_7 >> 8 ) & 0x1f ) ,
V_7 & 0xff
} ;
F_54 ( 2 , V_52 , V_10 , L_25 , V_53 ) ;
switch ( V_40 -> V_54 ) {
case V_89 :
case V_90 :
F_23 ( V_10 , 0x00 , 0x07 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_50 ( V_10 , 0x81 , 0xef , 0x10 ) ;
if ( F_20 ( V_16 , 0x16 , 2 , V_109 ) ) {
F_74 ( V_10 , L_27 ) ;
break;
}
F_49 ( V_10 , 0x26 , ( V_96 >> 8 ) & 0xf ) ;
F_49 ( V_10 , 0x27 , ( V_96 & 0xff ) ) ;
F_49 ( V_10 , 0x28 , ( V_99 >> 8 ) & 0xf ) ;
F_49 ( V_10 , 0x29 , ( V_99 & 0xff ) ) ;
F_49 ( V_10 , 0xa5 , ( V_101 >> 4 ) & 0xff ) ;
F_49 ( V_10 , 0xa6 , ( ( V_101 & 0xf ) << 4 ) |
( ( V_103 >> 8 ) & 0xf ) ) ;
F_49 ( V_10 , 0xa7 , V_103 & 0xff ) ;
break;
case V_55 :
F_23 ( V_10 , 0x00 , 0x02 ) ;
F_23 ( V_10 , 0x01 , 0x06 ) ;
break;
default:
F_54 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
F_49 ( V_10 , 0x8f , ( V_106 >> 8 ) & 0x7 ) ;
F_49 ( V_10 , 0x90 , V_106 & 0xff ) ;
F_49 ( V_10 , 0xab , ( V_95 >> 4 ) & 0xff ) ;
F_49 ( V_10 , 0xac , ( V_95 & 0x0f ) << 4 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_40 -> V_110 ) {
case V_111 :
if ( F_56 ( V_10 ) && ! ( F_46 ( V_10 , 0x05 ) & 0x80 ) ) {
if ( V_40 -> V_86 . V_6 . V_112 & V_113 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
}
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
}
break;
case V_114 :
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_115 :
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
break;
}
}
static int F_76 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_12 -> V_116 ) {
case V_117 :
F_49 ( V_10 , 0x3c , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x14 , V_12 -> V_38 ) ;
return 0 ;
case V_118 :
F_49 ( V_10 , 0x3a , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x13 , V_12 -> V_38 ) ;
return 0 ;
case V_119 :
F_49 ( V_10 , 0x3b , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x15 , V_12 -> V_38 ) ;
return 0 ;
case V_120 :
F_49 ( V_10 , 0x3d , V_12 -> V_38 ) ;
F_36 ( V_10 , 0x16 , V_12 -> V_38 ) ;
return 0 ;
case V_121 :
F_39 ( V_10 , 0xc8 , V_12 -> V_38 ) ;
return 0 ;
case V_122 :
F_50 ( V_10 , 0xbf , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
F_37 ( V_10 , 0xdd , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
return 0 ;
case V_123 : {
T_2 V_124 = ( V_12 -> V_38 & 0xff0000 ) >> 16 ;
T_2 V_125 = ( V_12 -> V_38 & 0x00ff00 ) >> 8 ;
T_2 V_126 = ( V_12 -> V_38 & 0x0000ff ) ;
int V_127 = 66 * V_124 + 129 * V_125 + 25 * V_126 ;
int V_128 = - 38 * V_124 - 74 * V_125 + 112 * V_126 ;
int V_129 = 112 * V_124 - 94 * V_125 - 18 * V_126 ;
V_127 = ( V_127 + 128 ) >> 8 ;
V_128 = ( V_128 + 128 ) >> 8 ;
V_129 = ( V_129 + 128 ) >> 8 ;
V_127 += 16 ;
V_128 += 128 ;
V_129 += 128 ;
F_54 ( 1 , V_52 , V_10 , L_28 , V_124 , V_125 , V_126 ) ;
F_54 ( 1 , V_52 , V_10 , L_29 , V_127 , V_128 , V_129 ) ;
F_49 ( V_10 , 0xc1 , V_124 ) ;
F_49 ( V_10 , 0xc0 , V_125 ) ;
F_49 ( V_10 , 0xc2 , V_126 ) ;
F_36 ( V_10 , 0xde , V_127 ) ;
F_36 ( V_10 , 0xdf , ( V_129 & 0xf0 ) | ( ( V_128 >> 4 ) & 0x0f ) ) ;
return 0 ;
}
case V_130 :
V_40 -> V_110 = V_12 -> V_38 ;
F_75 ( V_10 ) ;
return 0 ;
}
return - V_71 ;
}
static inline bool F_77 ( struct V_9 * V_10 )
{
return F_21 ( V_10 , 0x0c ) & 0x24 ;
}
static inline bool F_78 ( struct V_9 * V_10 )
{
return ( ( F_48 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ) || ! ( F_48 ( V_10 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_79 ( struct V_9 * V_10 )
{
return F_46 ( V_10 , 0x05 ) & 0x80 ;
}
static int F_80 ( struct V_9 * V_10 , T_3 * V_131 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
* V_131 = 0 ;
if ( F_21 ( V_10 , 0x0c ) & 0x24 )
* V_131 |= V_132 ;
if ( V_40 -> V_54 == V_133 ) {
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) )
* V_131 |= V_134 ;
F_54 ( 1 , V_52 , V_10 , L_30 ,
V_53 , * V_131 ) ;
return 0 ;
}
if ( ( F_48 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ||
! ( F_48 ( V_10 , 0xb1 ) & 0x80 ) )
* V_131 |= V_134 ;
if ( F_56 ( V_10 ) && ( ( F_21 ( V_10 , 0x74 ) & 0x03 ) != 0x03 ) )
* V_131 |= V_134 ;
F_54 ( 1 , V_52 , V_10 , L_31 ,
V_53 , * V_131 ) ;
return 0 ;
}
static int F_81 ( struct V_9 * V_10 ,
struct V_135 * V_136 ,
struct V_1 * V_86 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_3 V_137 = ( V_108 * 8 ) / V_136 -> V_138 ;
T_3 V_139 ;
int V_4 ;
for ( V_4 = 0 ; V_140 [ V_4 ] . V_6 . V_7 ; V_4 ++ ) {
const struct V_14 * V_6 = & V_140 [ V_4 ] . V_6 ;
if ( ! F_82 ( & V_140 [ V_4 ] ,
F_57 ( V_10 ) ,
F_1 , NULL ) )
continue;
if ( F_12 ( V_6 ) != V_136 -> V_141 + 1 )
continue;
if ( V_6 -> V_104 != V_136 -> V_142 )
continue;
V_139 = V_137 * F_8 ( V_6 ) ;
if ( ( V_139 < V_6 -> V_107 + 1000000 ) &&
( V_139 > V_6 -> V_107 - 1000000 ) ) {
* V_86 = V_140 [ V_4 ] ;
return 0 ;
}
}
if ( F_83 ( V_136 -> V_141 + 1 , V_137 , V_136 -> V_142 ,
( V_136 -> V_143 == '+' ? V_144 : 0 ) |
( V_136 -> V_145 == '+' ? V_146 : 0 ) ,
V_86 ) )
return 0 ;
if ( F_84 ( V_136 -> V_141 + 1 , V_137 , V_136 -> V_142 ,
( V_136 -> V_143 == '+' ? V_144 : 0 ) |
( V_136 -> V_145 == '+' ? V_146 : 0 ) ,
V_40 -> V_147 , V_86 ) )
return 0 ;
F_54 ( 2 , V_52 , V_10 ,
L_32 ,
V_53 , V_136 -> V_142 , V_136 -> V_141 , V_136 -> V_138 ,
V_136 -> V_143 , V_136 -> V_145 ) ;
return - 1 ;
}
static int F_85 ( struct V_9 * V_10 , struct V_135 * V_136 )
{
T_3 V_131 ;
F_80 ( V_10 , & V_131 ) ;
if ( V_131 & V_134 ) {
F_54 ( 2 , V_52 , V_10 , L_33 , V_53 ) ;
return - V_148 ;
}
V_136 -> V_138 = ( ( F_48 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_48 ( V_10 , 0xb2 ) ;
V_136 -> V_141 = ( ( F_48 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_48 ( V_10 , 0xb4 ) ;
V_136 -> V_142 = F_48 ( V_10 , 0xb3 ) >> 3 ;
if ( ( F_48 ( V_10 , 0xb5 ) & 0x80 ) && ( ( F_48 ( V_10 , 0xb5 ) & 0x03 ) == 0x01 ) ) {
V_136 -> V_143 = ( ( F_48 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_48 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_136 -> V_145 = ( ( F_48 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_48 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_136 -> V_143 = 'x' ;
V_136 -> V_145 = 'x' ;
}
V_136 -> V_149 = ( F_48 ( V_10 , 0xb1 ) & 0x40 ) ? true : false ;
if ( V_136 -> V_141 < 239 || V_136 -> V_138 < 8 || V_136 -> V_138 == 0x3fff ) {
F_54 ( 2 , V_52 , V_10 , L_34 , V_53 ) ;
return - V_148 ;
}
F_54 ( 2 , V_52 , V_10 ,
L_35 ,
V_53 , V_136 -> V_141 , V_136 -> V_138 , V_136 -> V_142 ,
V_136 -> V_143 , V_136 -> V_145 ,
V_136 -> V_149 ? L_36 : L_37 ) ;
return 0 ;
}
static int F_86 ( struct V_9 * V_10 ,
struct V_150 * V_86 )
{
return F_87 ( V_86 ,
F_57 ( V_10 ) , F_1 , NULL ) ;
}
static int F_88 ( struct V_9 * V_10 ,
struct V_56 * V_151 )
{
* V_151 = * F_57 ( V_10 ) ;
return 0 ;
}
static void F_89 ( struct V_9 * V_10 ,
struct V_1 * V_86 )
{
F_90 ( V_86 , F_57 ( V_10 ) ,
F_56 ( V_10 ) ? 250000 : 1000000 ,
F_1 , NULL ) ;
}
static int F_91 ( struct V_9 * V_10 ,
struct V_1 * V_86 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 = & V_86 -> V_6 ;
struct V_135 V_136 = { 0 } ;
if ( V_40 -> V_54 == V_133 )
return - V_152 ;
if ( F_85 ( V_10 , & V_136 ) ) {
F_54 ( 1 , V_52 , V_10 , L_38 , V_53 ) ;
return - V_148 ;
}
V_6 -> V_149 = V_136 . V_149 ?
V_153 : V_154 ;
V_6 -> V_155 = ( ( F_46 ( V_10 , 0x05 ) & 0x10 ) ? V_146 : 0 ) |
( ( F_46 ( V_10 , 0x05 ) & 0x20 ) ? V_144 : 0 ) ;
V_6 -> V_104 = V_136 . V_142 ;
if ( F_56 ( V_10 ) ) {
bool V_156 = F_46 ( V_10 , 0x04 ) & 0x02 ;
bool V_149 = F_46 ( V_10 , 0x0b ) & 0x20 ;
unsigned V_157 = ( F_46 ( V_10 , 0x07 ) & 0x1f ) * 256 + F_46 ( V_10 , 0x08 ) ;
unsigned V_158 = ( F_46 ( V_10 , 0x09 ) & 0x1f ) * 256 + F_46 ( V_10 , 0x0a ) ;
unsigned V_159 = ( F_46 ( V_10 , 0x1e ) & 0x3f ) * 256 +
F_46 ( V_10 , 0x1f ) ;
unsigned V_160 = ( ( F_46 ( V_10 , 0x26 ) & 0x3f ) * 256 +
F_46 ( V_10 , 0x27 ) ) / 2 ;
unsigned V_161 = ( ( ( F_46 ( V_10 , 0x51 ) << 1 ) +
( F_46 ( V_10 , 0x52 ) >> 7 ) ) * 1000000 ) +
( ( F_46 ( V_10 , 0x52 ) & 0x7f ) * 1000000 ) / 128 ;
int V_4 ;
if ( F_79 ( V_10 ) ) {
V_161 = V_161 * 8 / ( ( ( F_46 ( V_10 , 0x0b ) & 0xc0 ) >> 6 ) * 2 + 8 ) ;
}
if ( ! V_156 ) {
F_54 ( 1 , V_52 , V_10 , L_39 , V_53 ) ;
return - V_162 ;
}
if ( V_149 ) {
F_54 ( 1 , V_52 , V_10 , L_40 , V_53 ) ;
return - V_163 ;
}
for ( V_4 = 0 ; V_140 [ V_4 ] . V_6 . V_7 ; V_4 ++ ) {
const struct V_14 * V_6 = & V_140 [ V_4 ] . V_6 ;
if ( ! F_82 ( & V_140 [ V_4 ] ,
F_57 ( V_10 ) ,
F_1 , NULL ) )
continue;
if ( V_159 != F_8 ( V_6 ) || V_160 != F_12 ( V_6 ) )
continue;
if ( V_157 != V_6 -> V_7 || V_158 != V_6 -> V_95 )
continue;
if ( abs ( V_161 - V_6 -> V_107 ) > 1000000 )
continue;
* V_86 = V_140 [ V_4 ] ;
return 0 ;
}
V_86 -> type = V_164 ;
V_6 -> V_7 = V_157 ;
V_6 -> V_95 = V_158 ;
V_6 -> V_149 = ( F_46 ( V_10 , 0x0b ) & 0x20 ) ?
V_153 : V_154 ;
V_6 -> V_155 = ( ( F_46 ( V_10 , 0x05 ) & 0x10 ) ?
V_146 : 0 ) | ( ( F_46 ( V_10 , 0x05 ) & 0x20 ) ?
V_144 : 0 ) ;
V_6 -> V_107 = ( ( ( F_46 ( V_10 , 0x51 ) << 1 ) +
( F_46 ( V_10 , 0x52 ) >> 7 ) ) * 1000000 ) +
( ( F_46 ( V_10 , 0x52 ) & 0x7f ) * 1000000 ) / 128 ;
V_6 -> V_100 = ( F_46 ( V_10 , 0x20 ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x21 ) ;
V_6 -> V_97 = ( F_46 ( V_10 , 0x22 ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x23 ) ;
V_6 -> V_98 = ( F_46 ( V_10 , 0x24 ) & 0x1f ) * 256 +
F_46 ( V_10 , 0x25 ) ;
V_6 -> V_102 = ( ( F_46 ( V_10 , 0x2a ) & 0x3f ) * 256 +
F_46 ( V_10 , 0x2b ) ) / 2 ;
V_6 -> V_165 = ( ( F_46 ( V_10 , 0x2c ) & 0x3f ) * 256 +
F_46 ( V_10 , 0x2d ) ) / 2 ;
V_6 -> V_104 = ( ( F_46 ( V_10 , 0x2e ) & 0x3f ) * 256 +
F_46 ( V_10 , 0x2f ) ) / 2 ;
V_6 -> V_166 = ( ( F_46 ( V_10 , 0x30 ) & 0x3f ) * 256 +
F_46 ( V_10 , 0x31 ) ) / 2 ;
V_6 -> V_105 = ( ( F_46 ( V_10 , 0x32 ) & 0x3f ) * 256 +
F_46 ( V_10 , 0x33 ) ) / 2 ;
V_6 -> V_167 = ( ( F_46 ( V_10 , 0x34 ) & 0x3f ) * 256 +
F_46 ( V_10 , 0x35 ) ) / 2 ;
V_6 -> V_112 = 0 ;
V_6 -> V_23 = 0 ;
} else {
if ( V_136 . V_149 ) {
F_54 ( 1 , V_52 , V_10 , L_40 , V_53 ) ;
return - V_163 ;
}
if ( F_81 ( V_10 , & V_136 , V_86 ) ) {
F_54 ( 1 , V_52 , V_10 , L_41 , V_53 ) ;
return - V_163 ;
}
}
if ( V_52 > 1 )
F_92 ( V_10 -> V_168 , L_42 ,
V_86 , true ) ;
return 0 ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_1 * V_86 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 ;
int V_30 ;
if ( V_40 -> V_54 == V_133 )
return - V_152 ;
V_6 = & V_86 -> V_6 ;
if ( ! F_82 ( V_86 , F_57 ( V_10 ) ,
F_1 , NULL ) )
return - V_163 ;
F_89 ( V_10 , V_86 ) ;
V_40 -> V_86 = * V_86 ;
F_49 ( V_10 , 0x91 , V_6 -> V_149 ? 0x50 : 0x10 ) ;
V_30 = F_72 ( V_10 , V_86 ) ;
if ( V_30 ) {
F_73 ( V_10 , V_6 ) ;
}
F_75 ( V_10 ) ;
if ( V_52 > 1 )
F_92 ( V_10 -> V_168 , L_43 ,
V_86 , true ) ;
return 0 ;
}
static int F_94 ( struct V_9 * V_10 ,
struct V_1 * V_86 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_54 == V_133 )
return - V_152 ;
* V_86 = V_40 -> V_86 ;
return 0 ;
}
static void F_95 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_40 -> V_54 ) {
case V_133 :
case V_89 :
case V_90 :
F_23 ( V_10 , 0x15 , 0xb0 ) ;
break;
case V_55 :
F_47 ( V_10 , 0x1a , 0x0a ) ;
F_47 ( V_10 , 0x01 , 0x00 ) ;
F_23 ( V_10 , 0x15 , 0xa0 ) ;
break;
default:
F_54 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
}
static void F_96 ( struct V_9 * V_10 )
{
F_23 ( V_10 , 0x15 , 0xbe ) ;
F_47 ( V_10 , 0x1a , 0x1a ) ;
F_47 ( V_10 , 0x01 , 0x78 ) ;
}
static void F_97 ( struct V_9 * V_10 ,
const struct V_169 * V_170 )
{
F_34 ( V_10 , 0xe0 , 0xbf , V_170 -> V_171 ? 0x00 : 0x40 ) ;
if ( ! V_170 -> V_171 )
return;
F_34 ( V_10 , 0xe0 , 0x7f , V_170 -> V_172 == 2 ? 0x80 : 0x00 ) ;
F_34 ( V_10 , 0xe0 , 0xe0 , V_170 -> V_173 >> 8 ) ;
F_33 ( V_10 , 0xe1 , V_170 -> V_173 ) ;
F_34 ( V_10 , 0xe2 , 0xe0 , V_170 -> V_174 >> 8 ) ;
F_33 ( V_10 , 0xe3 , V_170 -> V_174 ) ;
F_34 ( V_10 , 0xe4 , 0xe0 , V_170 -> V_175 >> 8 ) ;
F_33 ( V_10 , 0xe5 , V_170 -> V_175 ) ;
F_34 ( V_10 , 0xe6 , 0x80 , V_170 -> V_176 >> 8 ) ;
F_33 ( V_10 , 0xe7 , V_170 -> V_176 ) ;
F_34 ( V_10 , 0xe8 , 0xe0 , V_170 -> V_177 >> 8 ) ;
F_33 ( V_10 , 0xe9 , V_170 -> V_177 ) ;
F_34 ( V_10 , 0xea , 0xe0 , V_170 -> V_178 >> 8 ) ;
F_33 ( V_10 , 0xeb , V_170 -> V_178 ) ;
F_34 ( V_10 , 0xec , 0xe0 , V_170 -> V_179 >> 8 ) ;
F_33 ( V_10 , 0xed , V_170 -> V_179 ) ;
F_34 ( V_10 , 0xee , 0x80 , V_170 -> V_180 >> 8 ) ;
F_33 ( V_10 , 0xef , V_170 -> V_180 ) ;
F_34 ( V_10 , 0xf0 , 0xe0 , V_170 -> V_181 >> 8 ) ;
F_33 ( V_10 , 0xf1 , V_170 -> V_181 ) ;
F_34 ( V_10 , 0xf2 , 0xe0 , V_170 -> V_182 >> 8 ) ;
F_33 ( V_10 , 0xf3 , V_170 -> V_182 ) ;
F_34 ( V_10 , 0xf4 , 0xe0 , V_170 -> V_183 >> 8 ) ;
F_33 ( V_10 , 0xf5 , V_170 -> V_183 ) ;
F_34 ( V_10 , 0xf6 , 0x80 , V_170 -> V_184 >> 8 ) ;
F_33 ( V_10 , 0xf7 , V_170 -> V_184 ) ;
}
static void F_98 ( struct V_9 * V_10 ,
enum V_185 V_186 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_40 -> V_54 ) {
case V_133 :
F_23 ( V_10 , 0x00 , V_186 ) ;
F_23 ( V_10 , 0x01 , 0 ) ;
F_50 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_39 ( V_10 , 0x00 , 0x00 ) ;
F_39 ( V_10 , 0xc8 , 0x00 ) ;
F_23 ( V_10 , 0x19 , 0x83 ) ;
F_23 ( V_10 , 0x33 , 0x40 ) ;
F_23 ( V_10 , 0xdd , 0x90 ) ;
F_40 ( V_10 , 0x02 , 0x7f , 0x80 ) ;
if ( V_186 == V_187 ) {
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
F_36 ( V_10 , 0xdd , 0x08 ) ;
break;
case V_89 :
case V_90 :
F_40 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
F_23 ( V_10 , 0x00 , V_186 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_50 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_39 ( V_10 , 0x00 , 0x00 ) ;
F_39 ( V_10 , 0xc8 , 0x00 ) ;
F_39 ( V_10 , 0x0c , 0x1f ) ;
F_39 ( V_10 , 0x12 , 0x63 ) ;
F_49 ( V_10 , 0x73 , 0x10 ) ;
F_49 ( V_10 , 0x74 , 0x04 ) ;
F_49 ( V_10 , 0x75 , 0x01 ) ;
F_49 ( V_10 , 0x76 , 0x00 ) ;
F_49 ( V_10 , 0x3e , 0x04 ) ;
F_49 ( V_10 , 0xc3 , 0x39 ) ;
F_49 ( V_10 , 0x40 , 0x5c ) ;
break;
case V_55 :
F_40 ( V_10 , 0x02 , 0x7f , 0x00 ) ;
if ( V_40 -> V_188 )
F_47 ( V_10 , 0x00 , 0x02 ) ;
else
F_47 ( V_10 , 0x00 , 0x03 ) ;
F_23 ( V_10 , 0x00 , V_186 ) ;
F_23 ( V_10 , 0x01 , 5 ) ;
F_50 ( V_10 , 0x81 , 0xef , 0x00 ) ;
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
F_49 ( V_10 , 0x73 , 0x10 ) ;
F_49 ( V_10 , 0x74 , 0x04 ) ;
F_49 ( V_10 , 0x75 , 0x01 ) ;
F_49 ( V_10 , 0x76 , 0x00 ) ;
F_39 ( V_10 , 0x12 , 0xfb ) ;
F_39 ( V_10 , 0x0c , 0x0d ) ;
F_49 ( V_10 , 0x3e , 0x80 ) ;
F_49 ( V_10 , 0xc3 , 0x33 ) ;
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
default:
F_54 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_54 ) ;
break;
}
}
static int F_99 ( struct V_9 * V_10 ,
T_3 V_189 , T_3 V_190 , T_3 V_191 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_54 ( 2 , V_52 , V_10 , L_44 , V_53 , V_189 ) ;
switch ( V_189 ) {
case V_192 :
V_40 -> V_54 = V_55 ;
V_40 -> V_186 = V_193 ;
V_40 -> V_188 = true ;
break;
case V_194 :
V_40 -> V_54 = V_55 ;
V_40 -> V_186 = V_193 ;
V_40 -> V_188 = false ;
break;
case V_195 :
F_65 ( V_10 , L_45 , V_53 ) ;
case V_196 :
V_40 -> V_54 = V_90 ;
V_40 -> V_186 = V_197 ;
break;
case V_198 :
V_40 -> V_54 = V_133 ;
V_40 -> V_186 = V_187 ;
break;
case V_199 :
V_40 -> V_54 = V_133 ;
V_40 -> V_186 = V_200 ;
break;
default:
return - V_71 ;
}
F_96 ( V_10 ) ;
F_98 ( V_10 , V_40 -> V_186 ) ;
F_95 ( V_10 ) ;
F_100 ( V_10 , V_201 , NULL ) ;
return 0 ;
}
static int F_101 ( struct V_9 * V_10 , unsigned int V_202 ,
enum V_203 * V_204 )
{
if ( V_202 )
return - V_71 ;
* V_204 = V_205 ;
return 0 ;
}
static int F_102 ( struct V_9 * V_10 ,
struct V_206 * V_207 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
V_207 -> V_7 = V_40 -> V_86 . V_6 . V_7 ;
V_207 -> V_95 = V_40 -> V_86 . V_6 . V_95 ;
V_207 -> V_204 = V_205 ;
V_207 -> V_208 = V_209 ;
if ( V_40 -> V_54 == V_133 ) {
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) )
return - V_71 ;
V_207 -> V_7 = 720 ;
if ( V_40 -> V_210 & V_211 )
V_207 -> V_95 = 480 ;
else
V_207 -> V_95 = 576 ;
V_207 -> V_212 = V_213 ;
return 0 ;
}
if ( V_40 -> V_86 . V_6 . V_112 & V_113 ) {
V_207 -> V_212 = ( V_40 -> V_86 . V_6 . V_95 <= 576 ) ?
V_213 : V_214 ;
}
return 0 ;
}
static void F_103 ( struct V_9 * V_10 , bool V_215 )
{
if ( V_215 ) {
F_23 ( V_10 , 0x46 , 0x9c ) ;
F_23 ( V_10 , 0x5a , 0x10 ) ;
F_23 ( V_10 , 0x73 , 0x03 ) ;
F_23 ( V_10 , 0x78 , 0x03 ) ;
F_23 ( V_10 , 0xa0 , 0x09 ) ;
} else {
F_23 ( V_10 , 0x46 , 0x0 ) ;
F_23 ( V_10 , 0x5a , 0x0 ) ;
F_23 ( V_10 , 0x73 , 0x0 ) ;
F_23 ( V_10 , 0x78 , 0x0 ) ;
F_23 ( V_10 , 0xa0 , 0x0 ) ;
}
}
static int F_104 ( struct V_9 * V_10 , T_3 V_131 , bool * V_216 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_217 , V_218 , V_219 ;
T_2 V_220 [ 5 ] ;
T_2 V_221 = F_21 ( V_10 , 0x40 ) ;
F_23 ( V_10 , 0x40 , V_221 | 0x3 ) ;
V_220 [ 0 ] = F_21 ( V_10 , 0x43 ) ;
V_220 [ 1 ] = F_21 ( V_10 , 0x57 ) ;
V_220 [ 2 ] = F_21 ( V_10 , 0x70 ) ;
V_220 [ 3 ] = F_21 ( V_10 , 0x75 ) ;
V_220 [ 4 ] = F_21 ( V_10 , 0x9d ) ;
if ( V_220 [ 0 ] )
F_23 ( V_10 , 0x44 , V_220 [ 0 ] ) ;
if ( V_220 [ 1 ] )
F_23 ( V_10 , 0x58 , V_220 [ 1 ] ) ;
if ( V_220 [ 2 ] )
F_23 ( V_10 , 0x71 , V_220 [ 2 ] ) ;
if ( V_220 [ 3 ] )
F_23 ( V_10 , 0x76 , V_220 [ 3 ] ) ;
if ( V_220 [ 4 ] )
F_23 ( V_10 , 0x9e , V_220 [ 4 ] ) ;
F_54 ( 1 , V_52 , V_10 , L_46 , V_53 ,
V_220 [ 0 ] , V_220 [ 1 ] , V_220 [ 2 ] ,
V_220 [ 3 ] , V_220 [ 4 ] ) ;
V_217 = V_220 [ 0 ] & 0x9c ;
if ( V_40 -> V_54 == V_133 )
V_219 = ( V_220 [ 1 ] & 0x30 ) | ( V_220 [ 4 ] & 0x09 ) ;
else
V_219 = 0 ;
if ( F_56 ( V_10 ) )
V_218 = V_220 [ 3 ] & 0x03 ;
else
V_218 = 0 ;
if ( V_217 || V_218 || V_219 ) {
F_54 ( 1 , V_52 , V_10 ,
L_47 ,
V_53 , V_217 , V_218 ,
V_219 ) ;
F_100 ( V_10 , V_201 , NULL ) ;
}
if ( V_220 [ 2 ] )
F_68 ( V_10 ) ;
if ( V_216 )
* V_216 = true ;
F_23 ( V_10 , 0x40 , V_221 ) ;
return 0 ;
}
static int F_105 ( struct V_9 * V_10 , struct V_222 * V_223 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 = 0 ;
if ( V_223 -> V_224 > 2 )
return - V_71 ;
if ( V_223 -> V_225 != 0 )
return - V_71 ;
if ( V_223 -> V_226 > 2 )
return - V_227 ;
if ( ! V_223 -> V_67 )
return - V_71 ;
V_40 -> V_147 = F_106 ( V_223 -> V_67 [ 0x15 ] ,
V_223 -> V_67 [ 0x16 ] ) ;
if ( V_223 -> V_224 == 2 ) {
memset ( & V_40 -> V_66 . V_67 , 0 , 256 ) ;
V_40 -> V_66 . V_64 = V_223 -> V_226 ? 0x1 : 0x0 ;
memcpy ( & V_40 -> V_66 . V_67 , V_223 -> V_67 , 128 * V_223 -> V_226 ) ;
V_30 = F_60 ( V_10 ) ;
} else {
T_3 V_39 = 0x1 << V_223 -> V_224 ;
memset ( & V_40 -> V_65 . V_67 , 0 , 256 ) ;
if ( V_223 -> V_226 )
V_40 -> V_65 . V_64 |= V_39 ;
else
V_40 -> V_65 . V_64 &= ~ V_39 ;
memcpy ( & V_40 -> V_65 . V_67 , V_223 -> V_67 , 128 * V_223 -> V_226 ) ;
V_30 = F_63 ( V_10 , V_223 -> V_224 ) ;
}
if ( V_30 < 0 )
F_74 ( V_10 , L_48 , V_30 , V_223 -> V_224 ) ;
return V_30 ;
}
static void F_107 ( struct V_9 * V_10 , T_5 * V_228 ,
struct V_229 * V_230 )
{
V_230 -> V_231 = ( V_228 [ 1 ] >> 7 ) & 0x1 ;
V_230 -> V_232 = ( V_228 [ 1 ] >> 5 ) & 0x3 ;
V_230 -> V_233 = ( V_228 [ 1 ] >> 4 ) & 0x1 ;
V_230 -> V_234 = ( V_228 [ 1 ] >> 2 ) & 0x3 ;
V_230 -> V_235 = V_228 [ 1 ] & 0x3 ;
V_230 -> V_236 = ( V_228 [ 2 ] >> 6 ) & 0x3 ;
V_230 -> V_237 = ( V_228 [ 2 ] >> 4 ) & 0x3 ;
V_230 -> V_238 = V_228 [ 2 ] & 0xf ;
V_230 -> V_239 = ( V_228 [ 3 ] >> 7 ) & 0x1 ;
V_230 -> V_240 = ( V_228 [ 3 ] >> 4 ) & 0x7 ;
V_230 -> V_241 = ( V_228 [ 3 ] >> 2 ) & 0x3 ;
V_230 -> V_242 = V_228 [ 3 ] & 0x3 ;
V_230 -> V_243 = ( V_228 [ 4 ] >> 7 ) & 0x1 ;
V_230 -> V_244 = V_228 [ 4 ] & 0x7f ;
V_230 -> V_245 = ( V_228 [ 5 ] >> 6 ) & 0x3 ;
V_230 -> V_246 = ( V_228 [ 5 ] >> 4 ) & 0x3 ;
V_230 -> V_247 = V_228 [ 5 ] & 0xf ;
V_230 -> V_248 = V_228 [ 6 ] + 256 * V_228 [ 7 ] ;
V_230 -> V_249 = V_228 [ 8 ] + 256 * V_228 [ 9 ] ;
V_230 -> V_250 = V_228 [ 10 ] + 256 * V_228 [ 11 ] ;
V_230 -> V_251 = V_228 [ 12 ] + 256 * V_228 [ 13 ] ;
}
static void F_108 ( struct V_9 * V_10 )
{
int V_4 ;
T_5 V_228 [ 14 ] ;
T_5 V_252 ;
struct V_229 V_230 ;
if ( ! ( F_46 ( V_10 , 0x05 ) & 0x80 ) ) {
F_65 ( V_10 , L_49 ) ;
return;
}
if ( ! ( F_21 ( V_10 , 0x60 ) & 0x01 ) ) {
F_65 ( V_10 , L_50 ) ;
return;
}
if ( F_21 ( V_10 , 0x88 ) & 0x10 ) {
F_65 ( V_10 , L_51 ) ;
return;
}
V_252 = F_30 ( V_10 , 0xe2 ) ;
F_65 ( V_10 , L_52 ,
F_30 ( V_10 , 0xe1 ) , V_252 ) ;
if ( F_30 ( V_10 , 0xe1 ) != 0x02 )
return;
for ( V_4 = 0 ; V_4 < 14 ; V_4 ++ )
V_228 [ V_4 ] = F_30 ( V_10 , V_4 ) ;
F_65 ( V_10 , L_53 ,
V_228 [ 0 ] , V_228 [ 1 ] , V_228 [ 2 ] , V_228 [ 3 ] , V_228 [ 4 ] , V_228 [ 5 ] , V_228 [ 6 ] , V_228 [ 7 ] ,
V_228 [ 8 ] , V_228 [ 9 ] , V_228 [ 10 ] , V_228 [ 11 ] , V_228 [ 12 ] , V_228 [ 13 ] ) ;
F_107 ( V_10 , V_228 , & V_230 ) ;
if ( V_230 . V_244 )
F_65 ( V_10 , L_54 , V_230 . V_244 ) ;
if ( V_230 . V_239 )
F_65 ( V_10 , L_55 , V_253 [ V_230 . V_239 ] ) ;
if ( V_230 . V_232 )
F_65 ( V_10 , L_56 , V_254 [ V_230 . V_232 ] , ! V_230 . V_236 ? L_57 :
( V_230 . V_236 == 0x3 ? V_255 [ V_230 . V_240 ] : V_256 [ V_230 . V_236 ] ) ) ;
else
F_65 ( V_10 , L_56 , V_254 [ V_230 . V_232 ] , V_257 [ V_230 . V_241 ] ) ;
}
static int F_109 ( struct V_9 * V_10 )
{
T_5 V_258 = F_35 ( V_10 , 0x5A ) & 0x01 ;
F_65 ( V_10 , L_58 , F_77 ( V_10 ) ? L_59 : L_60 ) ;
F_65 ( V_10 , L_61 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ) ;
F_65 ( V_10 , L_62 ,
( F_35 ( V_10 , 0x56 ) & 0x01 ) ? L_60 : L_59 ) ;
F_65 ( V_10 , L_63 , V_258 ?
L_64 : L_65 ) ;
if ( V_258 ) {
static const char * const V_259 [] = {
L_66 ,
L_67 ,
L_68 ,
L_69 ,
L_70 ,
L_71 ,
L_72 ,
L_73 , L_74 , L_75 , L_76 , L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81
} ;
F_65 ( V_10 , L_82 ,
V_259 [ F_35 ( V_10 , 0x52 ) & 0x0f ] ) ;
F_65 ( V_10 , L_63 ,
( F_35 ( V_10 , 0x59 ) & 0x08 ) ? L_83 : L_84 ) ;
F_65 ( V_10 , L_63 ,
( F_35 ( V_10 , 0x57 ) & 0x08 ) ? L_85 : L_86 ) ;
F_65 ( V_10 , L_87 ,
( F_35 ( V_10 , 0x12 ) & 0x08 ) ? L_88 : L_89 ) ;
F_65 ( V_10 , L_90 ,
( F_32 ( V_10 , 0xe0 ) & 0x40 ) ? L_91 : L_92 ) ;
}
return 0 ;
}
static int F_110 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_1 V_86 ;
T_5 V_260 = F_21 ( V_10 , 0x02 ) ;
T_5 V_261 = F_21 ( V_10 , 0x21 ) ;
T_5 V_262 = F_41 ( V_10 , 0x77 ) ;
T_5 V_263 = F_41 ( V_10 , 0x7d ) ;
bool V_264 = F_46 ( V_10 , 0x04 ) & 0x01 ;
bool V_265 = F_46 ( V_10 , 0x18 ) & 0x01 ;
bool V_266 = F_21 ( V_10 , 0x65 ) & 0x40 ;
static const char * const V_267 [ 16 ] = {
L_93 , L_94 , L_95 , L_96 ,
L_95 , L_97 , L_95 , L_98 ,
L_95 , L_99 , L_100 ,
L_95 , L_95 , L_95 , L_95 , L_92
} ;
static const char * const V_268 [ 16 ] = {
L_101 , L_102 ,
L_103 , L_104 ,
L_105 , L_106 ,
L_107 , L_108 ,
L_109 , L_109 , L_109 , L_109 , L_109 ,
L_109 , L_109 , L_110
} ;
static const char * const V_269 [] = {
L_111 ,
L_101 ,
L_102 ,
} ;
static const char * const V_270 [ 4 ] = {
L_112 ,
L_113 ,
L_114 ,
L_115
} ;
F_65 ( V_10 , L_116 ) ;
F_65 ( V_10 , L_117 , F_77 ( V_10 ) ? L_59 : L_60 ) ;
F_65 ( V_10 , L_118 , V_40 -> V_271 ?
L_119 : ( F_56 ( V_10 ) ? L_120 : L_121 ) ) ;
F_65 ( V_10 , L_122 ,
V_40 -> V_188 ? L_123 : L_124 ) ;
F_65 ( V_10 , L_125 ,
( ( V_263 & 0x04 ) && ( V_262 & 0x04 ) ) ?
L_88 : L_89 ,
( ( V_263 & 0x08 ) && ( V_262 & 0x08 ) ) ?
L_88 : L_89 ) ;
F_65 ( V_10 , L_126 ,
V_261 & 0x02 ? L_88 : L_89 ,
V_261 & 0x01 ? L_88 : L_89 ) ;
F_65 ( V_10 , L_127 , ! ! ( F_27 ( V_10 , 0x2a ) & 0x01 ) ?
L_88 : L_89 ) ;
F_65 ( V_10 , L_128 ) ;
if ( V_40 -> V_188 ) {
F_65 ( V_10 , L_129 ,
F_21 ( V_10 , 0x6f ) & 0x02 ? L_130 : L_131 ) ;
F_65 ( V_10 , L_132 ,
( F_21 ( V_10 , 0x6a ) & 0x02 ) ? L_130 : L_131 ) ;
F_65 ( V_10 , L_133 ,
( F_21 ( V_10 , 0x6a ) & 0x20 ) ? L_130 : L_131 ) ;
} else {
F_65 ( V_10 , L_134 ,
F_21 ( V_10 , 0x6f ) & 0x01 ? L_130 : L_131 ) ;
F_65 ( V_10 , L_132 ,
( F_21 ( V_10 , 0x6a ) & 0x01 ) ? L_130 : L_131 ) ;
F_65 ( V_10 , L_133 ,
( F_21 ( V_10 , 0x6a ) & 0x10 ) ? L_130 : L_131 ) ;
}
F_65 ( V_10 , L_135 ,
( ! ! ( F_48 ( V_10 , 0xff ) & 0x10 ) ? L_60 : L_59 ) ) ;
F_65 ( V_10 , L_136 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ,
( F_21 ( V_10 , 0x01 ) & 0x70 ) >> 4 ) ;
F_65 ( V_10 , L_137 ) ;
if ( F_78 ( V_10 ) ) {
F_65 ( V_10 , L_138 ) ;
} else {
T_6 V_138 = ( ( F_48 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_48 ( V_10 , 0xb2 ) ;
T_6 V_141 = ( ( F_48 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_48 ( V_10 , 0xb4 ) ;
T_6 V_142 = F_48 ( V_10 , 0xb3 ) >> 3 ;
T_6 V_272 = ( ( F_48 ( V_10 , 0xb8 ) & 0x1f ) << 8 ) | F_48 ( V_10 , 0xb9 ) ;
char V_143 = ( ( F_48 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_48 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
char V_145 = ( ( F_48 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_48 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
F_65 ( V_10 ,
L_139 ,
V_141 , V_138 , V_142 , V_272 ,
( F_48 ( V_10 , 0xb1 ) & 0x40 ) ?
L_36 : L_37 ,
V_143 , V_145 ) ;
}
if ( F_91 ( V_10 , & V_86 ) )
F_65 ( V_10 , L_140 ) ;
else
F_92 ( V_10 -> V_168 , L_141 ,
& V_86 , true ) ;
F_92 ( V_10 -> V_168 , L_142 ,
& V_40 -> V_86 , true ) ;
if ( F_78 ( V_10 ) )
return 0 ;
F_65 ( V_10 , L_143 ) ;
F_65 ( V_10 , L_144 ,
V_269 [ V_40 -> V_110 ] ) ;
F_65 ( V_10 , L_145 ,
V_268 [ V_260 >> 4 ] ) ;
F_65 ( V_10 , L_146 ,
( V_260 & 0x02 ) ? L_147 : L_148 ,
( V_260 & 0x04 ) ? L_149 : L_150 ,
( ( V_260 & 0x04 ) ^ ( V_260 & 0x01 ) ) ?
L_88 : L_89 ) ;
F_65 ( V_10 , L_151 ,
V_267 [ F_48 ( V_10 , 0xf4 ) >> 4 ] ) ;
if ( ! F_56 ( V_10 ) )
return 0 ;
F_65 ( V_10 , L_152 , F_79 ( V_10 ) ? L_119 : L_120 ) ;
F_65 ( V_10 , L_153 ,
( F_46 ( V_10 , 0x05 ) & 0x40 ) ? L_130 : L_131 ) ;
F_65 ( V_10 , L_154 ,
( F_46 ( V_10 , 0x04 ) & 0x20 ) ? L_155 : L_156 ,
( F_46 ( V_10 , 0x04 ) & 0x10 ) ? L_157 : L_57 ) ;
if ( ! F_79 ( V_10 ) )
return 0 ;
F_65 ( V_10 , L_158 ,
V_264 ? L_159 : L_160 ,
V_265 ? L_161 : L_162 ,
V_266 ? L_163 : L_88 ) ;
if ( V_264 && V_265 ) {
F_65 ( V_10 , L_164 ,
( F_46 ( V_10 , 0x07 ) & 0x40 ) ? L_165 : L_166 ) ;
}
F_65 ( V_10 , L_167 , ( F_46 ( V_10 , 0x5b ) << 12 ) +
( F_46 ( V_10 , 0x5c ) << 8 ) +
( F_46 ( V_10 , 0x5d ) & 0xf0 ) ) ;
F_65 ( V_10 , L_168 , ( ( F_46 ( V_10 , 0x5d ) & 0x0f ) << 16 ) +
( F_46 ( V_10 , 0x5e ) << 8 ) +
F_46 ( V_10 , 0x5f ) ) ;
F_65 ( V_10 , L_169 ,
( F_46 ( V_10 , 0x04 ) & 0x40 ) ? L_60 : L_59 ) ;
F_65 ( V_10 , L_170 ,
V_270 [ F_46 ( V_10 , 0x0b ) >> 6 ] ) ;
F_108 ( V_10 ) ;
return 0 ;
}
static int F_111 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_54 == V_133 )
return F_109 ( V_10 ) ;
return F_110 ( V_10 ) ;
}
static int F_112 ( struct V_9 * V_10 , T_7 * V_273 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_54 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_133 )
return - V_152 ;
if ( ! ( F_35 ( V_10 , 0x5A ) & 0x01 ) ) {
* V_273 = 0 ;
F_54 ( 1 , V_52 , V_10 , L_38 , V_53 ) ;
return 0 ;
}
switch ( F_35 ( V_10 , 0x52 ) & 0x0f ) {
case 0 :
* V_273 &= V_274 ;
break;
case 2 :
* V_273 &= V_275 ;
break;
case 3 :
* V_273 &= V_276 ;
break;
case 4 :
* V_273 &= V_277 ;
break;
case 6 :
* V_273 &= V_278 ;
break;
case 0xc :
* V_273 &= V_279 ;
break;
case 0xe :
* V_273 &= V_280 ;
break;
case 0xf :
* V_273 &= V_276 ;
break;
default:
* V_273 &= V_281 ;
break;
}
return 0 ;
}
static int F_113 ( struct V_9 * V_10 , T_7 V_210 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_54 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_133 )
return - V_152 ;
if ( V_210 & V_281 ) {
V_40 -> V_210 = V_210 ;
return 0 ;
}
return - V_71 ;
}
static int F_114 ( struct V_9 * V_10 , T_7 * V_210 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_54 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_54 != V_133 )
return - V_152 ;
* V_210 = V_40 -> V_210 ;
return 0 ;
}
static int F_115 ( struct V_9 * V_10 ,
const struct V_282 * V_283 )
{
F_47 ( V_10 , 0x48 ,
( V_283 -> V_284 ? 0x80 : 0 ) |
( V_283 -> V_285 ? 0x40 : 0 ) ) ;
F_96 ( V_10 ) ;
F_23 ( V_10 , 0x0c , 0x42 ) ;
F_23 ( V_10 , 0x15 , 0x80 ) ;
F_23 ( V_10 , 0x02 ,
V_283 -> V_286 << 4 |
V_283 -> V_287 << 3 |
V_283 -> V_288 << 2 |
V_283 -> V_289 << 1 |
V_283 -> V_290 << 0 ) ;
F_23 ( V_10 , 0x03 , V_283 -> V_291 ) ;
F_24 ( V_10 , 0x04 , 0x1f , V_283 -> V_292 << 5 ) ;
F_24 ( V_10 , 0x05 , 0xf0 , V_283 -> V_293 << 3 |
V_283 -> V_294 << 2 |
V_283 -> V_295 << 1 |
V_283 -> V_296 << 0 ) ;
F_24 ( V_10 , 0x14 , 0xc0 , V_283 -> V_297 . V_20 << 4 |
V_283 -> V_297 . clock << 2 |
V_283 -> V_297 . V_298 ) ;
F_49 ( V_10 , 0xba , ( V_283 -> V_299 << 1 ) | 0x01 ) ;
F_49 ( V_10 , 0x69 , 0x14 ) ;
F_23 ( V_10 , 0x06 , 0xa6 ) ;
F_49 ( V_10 , 0xf3 , 0xdc ) ;
F_39 ( V_10 , 0xb5 , 0x01 ) ;
F_39 ( V_10 , 0x02 , V_283 -> V_300 ) ;
F_24 ( V_10 , 0x30 , ~ ( 1 << 4 ) , V_283 -> V_301 << 4 ) ;
F_97 ( V_10 , & V_283 -> F_97 ) ;
if ( V_283 -> V_302 . V_303 ) {
const struct V_304 * V_305 = & V_283 -> V_302 ;
F_33 ( V_10 , 0x94 , ( V_305 -> V_306 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x95 , V_305 -> V_306 & 0xff ) ;
F_33 ( V_10 , 0x96 , ( V_305 -> V_307 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x97 , V_305 -> V_307 & 0xff ) ;
F_33 ( V_10 , 0x98 , ( V_305 -> V_308 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x99 , V_305 -> V_308 & 0xff ) ;
F_33 ( V_10 , 0x9a , ( V_305 -> V_309 >> 8 ) & 0xf ) ;
F_33 ( V_10 , 0x9b , V_305 -> V_309 & 0xff ) ;
}
if ( V_283 -> V_310 >= 128 ) {
F_36 ( V_10 , 0x12 , 0x0d ) ;
if ( V_283 -> V_311 ) {
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
F_98 ( V_10 , V_283 -> V_186 ) ;
F_95 ( V_10 ) ;
F_43 ( V_10 , 0x77 , 0xf3 , 0x00 ) ;
F_47 ( V_10 , 0x69 , 0xa3 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_23 ( V_10 , 0x19 , 0x90 ) ;
F_23 ( V_10 , 0x33 , 0x40 ) ;
F_23 ( V_10 , 0x40 , 0xe2 ) ;
F_103 ( V_10 , true ) ;
return F_116 ( V_10 -> V_312 ) ;
}
static int F_117 ( struct V_9 * V_10 )
{
int V_4 ;
int V_313 = 0 ;
int V_314 = 0 ;
int V_315 = 0 ;
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
F_55 ( 5 ) ;
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
F_55 ( 5 ) ;
F_33 ( V_10 , 0xd9 , 0xd5 ) ;
F_36 ( V_10 , 0x12 , 0x05 ) ;
F_55 ( 20 ) ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
T_2 V_316 = F_32 ( V_10 , 0xdb ) ;
if ( V_316 & 0x10 ) {
V_315 ++ ;
if ( V_316 & 0x20 )
V_314 ++ ;
else
V_313 ++ ;
}
F_55 ( 20 ) ;
}
F_54 ( 1 , V_52 , V_10 ,
L_171 ,
V_315 , V_4 , V_313 , V_314 ) ;
if ( ! V_315 || V_314 )
return - V_27 ;
return 0 ;
}
static void F_118 ( struct V_9 * V_10 ,
struct V_282 * V_283 )
{
F_23 ( V_10 , 0xf1 , V_283 -> V_45 << 1 ) ;
F_23 ( V_10 , 0xf2 , V_283 -> V_44 << 1 ) ;
F_23 ( V_10 , 0xf3 , V_283 -> V_41 << 1 ) ;
F_23 ( V_10 , 0xf4 , V_283 -> V_42 << 1 ) ;
F_23 ( V_10 , 0xf5 , V_283 -> V_43 << 1 ) ;
F_23 ( V_10 , 0xf8 , V_283 -> V_46 << 1 ) ;
F_23 ( V_10 , 0xf9 , V_283 -> V_47 << 1 ) ;
F_23 ( V_10 , 0xfa , V_283 -> V_48 << 1 ) ;
F_23 ( V_10 , 0xfb , V_283 -> V_49 << 1 ) ;
F_23 ( V_10 , 0xfd , V_283 -> V_50 << 1 ) ;
F_23 ( V_10 , 0xfe , V_283 -> V_51 << 1 ) ;
}
static int F_119 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_282 * V_283 = V_16 -> V_317 . V_318 ;
int V_28 = 0 ;
if ( ! V_283 )
return - V_319 ;
if ( ! V_283 -> V_310 || ! V_283 -> V_311 ) {
F_65 ( V_10 , L_172 ) ;
return - V_71 ;
}
F_53 ( V_10 ) ;
F_118 ( V_10 , V_283 ) ;
V_28 = F_117 ( V_10 ) ;
F_53 ( V_10 ) ;
F_118 ( V_10 , V_283 ) ;
F_115 ( V_10 , V_283 ) ;
F_96 ( V_10 ) ;
F_98 ( V_10 , V_40 -> V_186 ) ;
F_95 ( V_10 ) ;
F_93 ( V_10 , & V_40 -> V_86 ) ;
F_60 ( V_10 ) ;
F_63 ( V_10 , 0 ) ;
F_63 ( V_10 , 1 ) ;
return V_28 ;
}
static long F_120 ( struct V_9 * V_10 , unsigned int V_320 , void * V_321 )
{
switch ( V_320 ) {
case V_322 :
return F_119 ( V_10 ) ;
}
return - V_323 ;
}
static void F_121 ( struct V_8 * V_40 )
{
if ( V_40 -> V_41 )
F_122 ( V_40 -> V_41 ) ;
if ( V_40 -> V_42 )
F_122 ( V_40 -> V_42 ) ;
if ( V_40 -> V_43 )
F_122 ( V_40 -> V_43 ) ;
if ( V_40 -> V_44 )
F_122 ( V_40 -> V_44 ) ;
if ( V_40 -> V_45 )
F_122 ( V_40 -> V_45 ) ;
if ( V_40 -> V_46 )
F_122 ( V_40 -> V_46 ) ;
if ( V_40 -> V_47 )
F_122 ( V_40 -> V_47 ) ;
if ( V_40 -> V_48 )
F_122 ( V_40 -> V_48 ) ;
if ( V_40 -> V_49 )
F_122 ( V_40 -> V_49 ) ;
if ( V_40 -> V_50 )
F_122 ( V_40 -> V_50 ) ;
if ( V_40 -> V_51 )
F_122 ( V_40 -> V_51 ) ;
}
static struct V_15 * F_123 ( struct V_9 * V_10 ,
T_2 V_22 , T_2 V_324 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
F_23 ( V_10 , V_324 , V_22 << 1 ) ;
return F_124 ( V_16 -> V_21 , F_21 ( V_10 , V_324 ) >> 1 ) ;
}
static int F_125 ( struct V_15 * V_16 ,
const struct V_325 * V_116 )
{
struct V_8 * V_40 ;
struct V_282 * V_283 = V_16 -> V_317 . V_318 ;
struct V_326 * V_3 ;
struct V_9 * V_10 ;
T_4 V_327 ;
int V_30 ;
if ( ! F_126 ( V_16 -> V_21 , V_328 ) )
return - V_27 ;
F_127 ( 1 , V_52 , V_16 , L_173 ,
V_16 -> V_22 << 1 ) ;
if ( ! V_283 ) {
F_16 ( V_16 , L_174 ) ;
return - V_319 ;
}
V_40 = F_128 ( & V_16 -> V_317 , sizeof( struct V_8 ) , V_329 ) ;
if ( ! V_40 ) {
F_16 ( V_16 , L_175 ) ;
return - V_330 ;
}
V_10 = & V_40 -> V_10 ;
F_129 ( V_10 , V_16 , & V_331 ) ;
V_10 -> V_23 |= V_332 ;
V_40 -> V_271 = V_283 -> V_271 ;
V_40 -> V_54 = V_283 -> V_54 ;
V_40 -> V_188 = true ;
V_327 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
if ( V_327 != 0x2012 ) {
F_65 ( V_10 , L_176 , V_327 ) ;
V_327 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
}
if ( V_327 != 0x2012 ) {
F_65 ( V_10 , L_177 ,
V_16 -> V_22 << 1 , V_327 ) ;
return - V_319 ;
}
if ( V_283 -> V_333 )
F_53 ( V_10 ) ;
V_3 = & V_40 -> V_3 ;
F_130 ( V_3 , 6 ) ;
F_131 ( V_3 , & V_334 ,
V_117 , - 128 , 127 , 1 , 0 ) ;
F_131 ( V_3 , & V_334 ,
V_118 , 0 , 255 , 1 , 128 ) ;
F_131 ( V_3 , & V_334 ,
V_119 , 0 , 255 , 1 , 128 ) ;
F_131 ( V_3 , & V_334 ,
V_120 , 0 , 128 , 1 , 0 ) ;
V_40 -> V_81 = F_131 ( V_3 , NULL ,
V_335 , 0 , 3 , 0 , 0 ) ;
V_40 -> V_336 = F_132 ( V_3 ,
& V_337 , NULL ) ;
V_40 -> V_338 = F_132 ( V_3 ,
& V_339 , NULL ) ;
V_40 -> V_340 = F_132 ( V_3 ,
& V_341 , NULL ) ;
V_40 -> V_342 =
F_133 ( V_3 , & V_334 ,
V_130 , V_115 ,
0 , V_111 ) ;
V_10 -> V_312 = V_3 ;
if ( V_3 -> error ) {
V_30 = V_3 -> error ;
goto V_343;
}
V_40 -> V_81 -> V_344 = true ;
V_40 -> V_342 -> V_344 = true ;
V_40 -> V_336 -> V_344 = true ;
V_40 -> V_338 -> V_344 = true ;
V_40 -> V_340 -> V_344 = true ;
if ( F_68 ( V_10 ) ) {
V_30 = - V_319 ;
goto V_343;
}
V_40 -> V_41 = F_123 ( V_10 , V_283 -> V_41 , 0xf3 ) ;
V_40 -> V_42 = F_123 ( V_10 , V_283 -> V_42 , 0xf4 ) ;
V_40 -> V_43 = F_123 ( V_10 , V_283 -> V_43 , 0xf5 ) ;
V_40 -> V_44 = F_123 ( V_10 , V_283 -> V_44 , 0xf2 ) ;
V_40 -> V_45 = F_123 ( V_10 , V_283 -> V_45 , 0xf1 ) ;
V_40 -> V_46 = F_123 ( V_10 , V_283 -> V_46 , 0xf8 ) ;
V_40 -> V_47 = F_123 ( V_10 , V_283 -> V_47 , 0xf9 ) ;
V_40 -> V_48 = F_123 ( V_10 , V_283 -> V_48 , 0xfa ) ;
V_40 -> V_49 = F_123 ( V_10 , V_283 -> V_49 , 0xfb ) ;
V_40 -> V_50 = F_123 ( V_10 , V_283 -> V_50 , 0xfd ) ;
V_40 -> V_51 = F_123 ( V_10 , V_283 -> V_51 , 0xfe ) ;
if ( ! V_40 -> V_41 || ! V_40 -> V_42 || ! V_40 -> V_43 ||
! V_40 -> V_44 || ! V_40 -> V_45 || ! V_40 -> V_46 ||
! V_40 -> V_47 || ! V_40 -> V_48 || ! V_40 -> V_49 ||
! V_40 -> V_50 || ! V_40 -> V_51 ) {
V_30 = - V_330 ;
F_74 ( V_10 , L_178 ) ;
goto V_345;
}
V_40 -> V_68 = F_134 ( V_16 -> V_168 ) ;
if ( ! V_40 -> V_68 ) {
F_74 ( V_10 , L_179 ) ;
V_30 = - V_330 ;
goto V_345;
}
F_135 ( & V_40 -> V_63 ,
F_58 ) ;
V_40 -> V_224 . V_23 = V_346 ;
V_30 = F_136 ( & V_10 -> V_347 , 1 , & V_40 -> V_224 , 0 ) ;
if ( V_30 )
goto V_348;
V_30 = F_115 ( V_10 , V_283 ) ;
if ( V_30 )
goto V_349;
F_65 ( V_10 , L_180 , V_16 -> V_168 ,
V_16 -> V_22 << 1 , V_16 -> V_21 -> V_168 ) ;
return 0 ;
V_349:
F_137 ( & V_10 -> V_347 ) ;
V_348:
F_138 ( & V_40 -> V_63 ) ;
F_139 ( V_40 -> V_68 ) ;
V_345:
F_121 ( V_40 ) ;
V_343:
F_140 ( V_3 ) ;
return V_30 ;
}
static int F_141 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = F_142 ( V_16 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_103 ( V_10 , false ) ;
F_138 ( & V_40 -> V_63 ) ;
F_139 ( V_40 -> V_68 ) ;
F_143 ( V_10 ) ;
F_137 ( & V_10 -> V_347 ) ;
F_121 ( F_3 ( V_10 ) ) ;
F_140 ( V_10 -> V_312 ) ;
return 0 ;
}
