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
return F_29 ( V_10 , V_37 , ( F_28 ( V_10 , V_37 ) & ~ V_39 ) | V_38 ) ;
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
static T_4 F_62 ( struct V_9 * V_10 )
{
T_2 V_37 = F_21 ( V_10 , 0x6f ) ;
T_4 V_38 = 0 ;
if ( V_37 & 0x02 )
V_38 |= 1 ;
if ( V_37 & 0x01 )
V_38 |= 2 ;
return V_38 ;
}
static void F_63 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_64 ( V_65 ) ;
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
static int F_65 ( struct V_9 * V_10 )
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
F_66 ( & V_40 -> V_68 , V_75 / 5 ) ;
return 0 ;
}
static int F_67 ( struct V_9 * V_10 , T_2 V_76 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
const T_2 * V_74 = V_40 -> V_70 . V_74 ;
int V_77 ;
T_4 V_78 ;
int V_30 = 0 ;
int V_4 ;
F_56 ( 2 , V_52 , V_10 , L_9 ,
V_53 , ( V_76 == V_71 ) ? 'A' : 'B' ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
F_44 ( V_10 , 0x77 , 0xf3 , 0x00 ) ;
if ( ! V_40 -> V_70 . V_69 )
return 0 ;
V_78 = F_68 ( V_74 , 256 , & V_77 ) ;
V_30 = F_69 ( V_78 , & V_78 , NULL ) ;
if ( V_30 )
return V_30 ;
if ( V_77 == 0 )
return - V_79 ;
F_44 ( V_10 , 0x77 , 0xef , 0x00 ) ;
for ( V_4 = 0 ; ! V_30 && V_4 < 256 ; V_4 += V_34 )
V_30 = F_20 ( V_40 -> V_48 , V_4 ,
V_34 , V_74 + V_4 ) ;
if ( V_30 )
return V_30 ;
if ( V_76 == V_71 ) {
F_43 ( V_10 , 0x72 , V_74 [ V_77 ] ) ;
F_43 ( V_10 , 0x73 , V_74 [ V_77 + 1 ] ) ;
} else {
F_43 ( V_10 , 0x74 , V_74 [ V_77 ] ) ;
F_43 ( V_10 , 0x75 , V_74 [ V_77 + 1 ] ) ;
}
F_43 ( V_10 , 0x76 , V_77 & 0xff ) ;
F_44 ( V_10 , 0x77 , 0xbf , ( V_77 >> 2 ) & 0x40 ) ;
F_44 ( V_10 , 0x77 , 0xf3 , V_40 -> V_70 . V_69 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( F_42 ( V_10 , 0x7d ) & V_40 -> V_70 . V_69 )
break;
F_57 ( 1 ) ;
}
if ( V_4 == 1000 ) {
F_16 ( V_16 , L_10 ,
( V_76 == V_71 ) ? 'A' : 'B' ) ;
return - V_27 ;
}
F_70 ( V_40 -> V_80 , V_78 , false ) ;
F_66 ( & V_40 -> V_68 , V_75 / 5 ) ;
return 0 ;
}
static void F_71 ( struct V_9 * V_10 )
{
F_72 ( V_10 , L_11 ) ;
F_72 ( V_10 , L_12 ) ;
F_72 ( V_10 , L_13 ) ;
F_72 ( V_10 , L_14 ) ;
F_72 ( V_10 , L_15 ) ;
F_72 ( V_10 , L_16 ) ;
F_72 ( V_10 , L_17 ) ;
F_72 ( V_10 , L_18 ) ;
F_72 ( V_10 , L_19 ) ;
F_72 ( V_10 , L_20 ) ;
F_72 ( V_10 , L_21 ) ;
F_72 ( V_10 , L_22 ) ;
}
static int F_73 ( struct V_9 * V_10 ,
struct V_81 * V_37 )
{
V_37 -> V_82 = 1 ;
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
F_72 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_71 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_74 ( struct V_9 * V_10 ,
const struct V_81 * V_37 )
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
F_72 ( V_10 , L_23 , V_37 -> V_37 ) ;
F_71 ( V_10 ) ;
break;
}
return 0 ;
}
static int F_75 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_4 V_83 = F_62 ( V_10 ) ;
F_56 ( 1 , V_52 , V_10 , L_24 , V_53 , V_83 ) ;
return F_76 ( V_40 -> V_84 , V_83 ) ;
}
static int F_77 ( struct V_9 * V_10 ,
T_2 V_85 ,
const struct V_86 * V_87 ,
const struct V_1 * V_88 )
{
int V_4 ;
for ( V_4 = 0 ; V_87 [ V_4 ] . V_88 . V_6 . V_7 ; V_4 ++ ) {
if ( ! F_2 ( V_88 , & V_87 [ V_4 ] . V_88 ,
F_60 ( V_10 ) ? 250000 : 1000000 , false ) )
continue;
F_23 ( V_10 , 0x00 , V_87 [ V_4 ] . V_89 ) ;
F_23 ( V_10 , 0x01 , ( V_87 [ V_4 ] . V_90 << 4 ) + V_85 ) ;
return 0 ;
}
return - 1 ;
}
static int F_78 ( struct V_9 * V_10 ,
struct V_1 * V_88 )
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
V_30 = F_77 ( V_10 ,
0x01 , V_91 , V_88 ) ;
if ( V_30 )
V_30 = F_77 ( V_10 ,
0x02 , V_92 , V_88 ) ;
break;
case V_60 :
V_30 = F_77 ( V_10 ,
0x05 , V_93 , V_88 ) ;
if ( V_30 )
V_30 = F_77 ( V_10 ,
0x06 , V_94 , V_88 ) ;
break;
default:
F_56 ( 2 , V_52 , V_10 , L_26 ,
V_53 , V_40 -> V_57 ) ;
V_30 = - 1 ;
break;
}
return V_30 ;
}
static void F_79 ( struct V_9 * V_10 ,
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
F_56 ( 2 , V_52 , V_10 , L_25 , V_53 ) ;
switch ( V_40 -> V_57 ) {
case V_59 :
case V_58 :
F_23 ( V_10 , 0x00 , 0x07 ) ;
F_23 ( V_10 , 0x01 , 0x02 ) ;
F_52 ( V_10 , 0x81 , 0xef , 0x10 ) ;
if ( F_20 ( V_16 , 0x16 , 2 , V_109 ) ) {
F_80 ( V_10 , L_27 ) ;
break;
}
F_51 ( V_10 , 0x26 , ( V_96 >> 8 ) & 0xf ) ;
F_51 ( V_10 , 0x27 , ( V_96 & 0xff ) ) ;
F_51 ( V_10 , 0x28 , ( V_99 >> 8 ) & 0xf ) ;
F_51 ( V_10 , 0x29 , ( V_99 & 0xff ) ) ;
F_51 ( V_10 , 0xa5 , ( V_101 >> 4 ) & 0xff ) ;
F_51 ( V_10 , 0xa6 , ( ( V_101 & 0xf ) << 4 ) |
( ( V_103 >> 8 ) & 0xf ) ) ;
F_51 ( V_10 , 0xa7 , V_103 & 0xff ) ;
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
F_51 ( V_10 , 0x8f , ( V_106 >> 8 ) & 0x7 ) ;
F_51 ( V_10 , 0x90 , V_106 & 0xff ) ;
F_51 ( V_10 , 0xab , ( V_95 >> 4 ) & 0xff ) ;
F_51 ( V_10 , 0xac , ( V_95 & 0x0f ) << 4 ) ;
}
static void F_81 ( struct V_9 * V_10 , bool V_110 , T_4 V_111 , T_4 V_112 , T_4 V_113 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_114 [ 4 ] ;
if ( V_110 ) {
V_111 = 0x3ff ;
V_112 = 0x3ff ;
V_113 = 0x3ff ;
}
F_56 ( 2 , V_52 , V_10 , L_28 ,
V_53 , V_110 ? L_29 : L_30 ,
V_111 , V_112 , V_113 ) ;
V_114 [ 0 ] = ( F_50 ( V_10 , 0x77 ) & 0xc0 ) | ( ( V_111 & 0x3f0 ) >> 4 ) ;
V_114 [ 1 ] = ( ( V_111 & 0x00f ) << 4 ) | ( ( V_112 & 0x3c0 ) >> 6 ) ;
V_114 [ 2 ] = ( ( V_112 & 0x03f ) << 2 ) | ( ( V_113 & 0x300 ) >> 8 ) ;
V_114 [ 3 ] = V_113 & 0x0ff ;
if ( F_20 ( V_40 -> V_50 , 0x77 , 4 , V_114 ) )
F_80 ( V_10 , L_31 , V_53 ) ;
}
static void F_82 ( struct V_9 * V_10 , bool V_115 , T_4 V_116 , T_4 V_117 , T_4 V_118 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_119 [ 4 ] ;
T_2 V_120 = 1 ;
T_2 V_121 = 1 ;
if ( V_115 ) {
V_120 = 0 ;
V_121 = 0 ;
V_116 = 0x100 ;
V_117 = 0x100 ;
V_118 = 0x100 ;
}
F_56 ( 2 , V_52 , V_10 , L_32 ,
V_53 , V_115 ? L_29 : L_30 ,
V_116 , V_117 , V_118 ) ;
V_119 [ 0 ] = ( ( V_120 << 7 ) | ( V_121 << 6 ) | ( ( V_116 & 0x3f0 ) >> 4 ) ) ;
V_119 [ 1 ] = ( ( ( V_116 & 0x00f ) << 4 ) | ( ( V_117 & 0x3c0 ) >> 6 ) ) ;
V_119 [ 2 ] = ( ( ( V_117 & 0x03f ) << 2 ) | ( ( V_118 & 0x300 ) >> 8 ) ) ;
V_119 [ 3 ] = ( ( V_118 & 0x0ff ) ) ;
if ( F_20 ( V_40 -> V_50 , 0x73 , 4 , V_119 ) )
F_80 ( V_10 , L_33 , V_53 ) ;
}
static void F_83 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
bool V_122 = F_21 ( V_10 , 0x02 ) & 0x02 ;
bool V_123 = F_47 ( V_10 , 0x05 ) & 0x80 ;
T_2 V_124 = V_125 ;
if ( V_123 && ( F_21 ( V_10 , 0x60 ) & 1 ) )
V_124 = F_31 ( V_10 , 0x01 ) >> 5 ;
F_56 ( 2 , V_52 , V_10 , L_34 ,
V_53 , V_40 -> V_126 ,
V_122 , V_123 ) ;
F_82 ( V_10 , true , 0x0 , 0x0 , 0x0 ) ;
F_81 ( V_10 , true , 0x0 , 0x0 , 0x0 ) ;
F_25 ( V_10 , 0x02 , 0x04 , V_122 ? 0 : 4 ) ;
switch ( V_40 -> V_126 ) {
case V_127 :
if ( V_40 -> V_57 == V_58 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
break;
}
if ( V_40 -> V_57 == V_59 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_123 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0xf0 ) ;
break;
}
if ( V_40 -> V_88 . V_6 . V_23 & V_128 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
} else {
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
if ( F_60 ( V_10 ) && V_122 ) {
F_81 ( V_10 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_82 ( V_10 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_81 ( V_10 , false , 0x70 , 0x70 , 0x70 ) ;
}
}
break;
case V_129 :
if ( V_40 -> V_57 == V_59 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x20 ) ;
break;
}
if ( V_124 != V_125 )
break;
F_24 ( V_10 , 0x02 , 0x0f , 0x00 ) ;
break;
case V_130 :
if ( V_40 -> V_57 == V_59 ) {
F_24 ( V_10 , 0x02 , 0x0f , 0x60 ) ;
break;
}
if ( V_124 != V_125 )
break;
F_24 ( V_10 , 0x02 , 0x0f , 0x10 ) ;
if ( F_59 ( V_10 ) || V_123 )
break;
if ( V_122 ) {
F_81 ( V_10 , false , 0x40 , 0x40 , 0x40 ) ;
} else {
F_82 ( V_10 , false , 0xe0 , 0xe0 , 0xe0 ) ;
F_81 ( V_10 , false , 0x70 , 0x70 , 0x70 ) ;
}
break;
}
}
static int F_84 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_12 -> V_131 ) {
case V_132 :
F_51 ( V_10 , 0x3c , V_12 -> V_38 ) ;
F_37 ( V_10 , 0x14 , V_12 -> V_38 ) ;
return 0 ;
case V_133 :
F_51 ( V_10 , 0x3a , V_12 -> V_38 ) ;
F_37 ( V_10 , 0x13 , V_12 -> V_38 ) ;
return 0 ;
case V_134 :
F_51 ( V_10 , 0x3b , V_12 -> V_38 ) ;
F_37 ( V_10 , 0x15 , V_12 -> V_38 ) ;
return 0 ;
case V_135 :
F_51 ( V_10 , 0x3d , V_12 -> V_38 ) ;
F_37 ( V_10 , 0x16 , V_12 -> V_38 ) ;
return 0 ;
case V_136 :
F_40 ( V_10 , 0xc8 , V_12 -> V_38 ) ;
return 0 ;
case V_137 :
F_52 ( V_10 , 0xbf , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
F_38 ( V_10 , 0xdd , ~ 0x04 , ( V_12 -> V_38 << 2 ) ) ;
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
F_56 ( 1 , V_52 , V_10 , L_35 , V_139 , V_140 , V_141 ) ;
F_56 ( 1 , V_52 , V_10 , L_36 , V_142 , V_143 , V_144 ) ;
F_51 ( V_10 , 0xc1 , V_139 ) ;
F_51 ( V_10 , 0xc0 , V_140 ) ;
F_51 ( V_10 , 0xc2 , V_141 ) ;
F_37 ( V_10 , 0xde , V_142 ) ;
F_37 ( V_10 , 0xdf , ( V_144 & 0xf0 ) | ( ( V_143 >> 4 ) & 0x0f ) ) ;
return 0 ;
}
case V_145 :
V_40 -> V_126 = V_12 -> V_38 ;
F_83 ( V_10 ) ;
return 0 ;
}
return - V_79 ;
}
static int F_85 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
if ( V_12 -> V_131 == V_146 ) {
V_12 -> V_38 = V_147 ;
if ( ( F_21 ( V_10 , 0x60 ) & 1 ) && ( F_31 ( V_10 , 0x03 ) & 0x80 ) )
V_12 -> V_38 = ( F_31 ( V_10 , 0x05 ) >> 4 ) & 3 ;
return 0 ;
}
return - V_79 ;
}
static inline bool F_86 ( struct V_9 * V_10 )
{
return F_21 ( V_10 , 0x0c ) & 0x24 ;
}
static inline bool F_87 ( struct V_9 * V_10 )
{
return ( ( F_50 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ) || ! ( F_50 ( V_10 , 0xb1 ) & 0x80 ) ;
}
static inline bool F_88 ( struct V_9 * V_10 )
{
return F_47 ( V_10 , 0x05 ) & 0x80 ;
}
static int F_89 ( struct V_9 * V_10 , T_3 * V_148 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
* V_148 = 0 ;
if ( F_21 ( V_10 , 0x0c ) & 0x24 )
* V_148 |= V_149 ;
if ( V_40 -> V_57 == V_150 ) {
if ( ! ( F_36 ( V_10 , 0x5A ) & 0x01 ) )
* V_148 |= V_151 ;
F_56 ( 1 , V_52 , V_10 , L_37 ,
V_53 , * V_148 ) ;
return 0 ;
}
if ( ( F_50 ( V_10 , 0xb5 ) & 0xd0 ) != 0xd0 ||
! ( F_50 ( V_10 , 0xb1 ) & 0x80 ) )
* V_148 |= V_151 ;
if ( F_60 ( V_10 ) && ( ( F_21 ( V_10 , 0x74 ) & 0x03 ) != 0x03 ) )
* V_148 |= V_151 ;
F_56 ( 1 , V_52 , V_10 , L_38 ,
V_53 , * V_148 ) ;
return 0 ;
}
static int F_90 ( struct V_9 * V_10 ,
struct V_152 * V_153 ,
struct V_1 * V_88 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_3 V_154 = ( V_108 * 8 ) / V_153 -> V_155 ;
T_3 V_156 ;
int V_4 ;
for ( V_4 = 0 ; V_157 [ V_4 ] . V_6 . V_7 ; V_4 ++ ) {
const struct V_14 * V_6 = & V_157 [ V_4 ] . V_6 ;
if ( ! F_91 ( & V_157 [ V_4 ] ,
F_61 ( V_10 ) ,
F_1 , NULL ) )
continue;
if ( F_12 ( V_6 ) != V_153 -> V_158 + 1 )
continue;
if ( V_6 -> V_104 != V_153 -> V_159 )
continue;
V_156 = V_154 * F_8 ( V_6 ) ;
if ( ( V_156 < V_6 -> V_107 + 1000000 ) &&
( V_156 > V_6 -> V_107 - 1000000 ) ) {
* V_88 = V_157 [ V_4 ] ;
return 0 ;
}
}
if ( F_92 ( V_153 -> V_158 + 1 , V_154 , V_153 -> V_159 , 0 ,
( V_153 -> V_160 == '+' ? V_161 : 0 ) |
( V_153 -> V_162 == '+' ? V_163 : 0 ) ,
false , V_88 ) )
return 0 ;
if ( F_93 ( V_153 -> V_158 + 1 , V_154 , V_153 -> V_159 ,
( V_153 -> V_160 == '+' ? V_161 : 0 ) |
( V_153 -> V_162 == '+' ? V_163 : 0 ) ,
false , V_40 -> V_164 , V_88 ) )
return 0 ;
F_56 ( 2 , V_52 , V_10 ,
L_39 ,
V_53 , V_153 -> V_159 , V_153 -> V_158 , V_153 -> V_155 ,
V_153 -> V_160 , V_153 -> V_162 ) ;
return - 1 ;
}
static int F_94 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
T_3 V_148 ;
F_89 ( V_10 , & V_148 ) ;
if ( V_148 & V_151 ) {
F_56 ( 2 , V_52 , V_10 , L_40 , V_53 ) ;
return - V_165 ;
}
V_153 -> V_155 = ( ( F_50 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_50 ( V_10 , 0xb2 ) ;
V_153 -> V_158 = ( ( F_50 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_50 ( V_10 , 0xb4 ) ;
V_153 -> V_159 = F_50 ( V_10 , 0xb3 ) >> 3 ;
if ( ( F_50 ( V_10 , 0xb5 ) & 0x80 ) && ( ( F_50 ( V_10 , 0xb5 ) & 0x03 ) == 0x01 ) ) {
V_153 -> V_160 = ( ( F_50 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_50 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
V_153 -> V_162 = ( ( F_50 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_50 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
} else {
V_153 -> V_160 = 'x' ;
V_153 -> V_162 = 'x' ;
}
V_153 -> V_166 = ( F_50 ( V_10 , 0xb1 ) & 0x40 ) ? true : false ;
if ( V_153 -> V_158 < 239 || V_153 -> V_155 < 8 || V_153 -> V_155 == 0x3fff ) {
F_56 ( 2 , V_52 , V_10 , L_41 , V_53 ) ;
return - V_165 ;
}
F_56 ( 2 , V_52 , V_10 ,
L_42 ,
V_53 , V_153 -> V_158 , V_153 -> V_155 , V_153 -> V_159 ,
V_153 -> V_160 , V_153 -> V_162 ,
V_153 -> V_166 ? L_43 : L_44 ) ;
return 0 ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_167 * V_88 )
{
if ( V_88 -> V_168 != 0 )
return - V_79 ;
return F_96 ( V_88 ,
F_61 ( V_10 ) , F_1 , NULL ) ;
}
static int F_97 ( struct V_9 * V_10 ,
struct V_61 * V_169 )
{
if ( V_169 -> V_168 != 0 )
return - V_79 ;
* V_169 = * F_61 ( V_10 ) ;
return 0 ;
}
static void F_98 ( struct V_9 * V_10 ,
struct V_1 * V_88 )
{
F_99 ( V_88 , F_61 ( V_10 ) ,
F_60 ( V_10 ) ? 250000 : 1000000 ,
F_1 , NULL ) ;
}
static int F_100 ( struct V_9 * V_10 ,
struct V_1 * V_88 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 = & V_88 -> V_6 ;
struct V_152 V_153 = { 0 } ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
memset ( V_88 , 0 , sizeof( struct V_1 ) ) ;
if ( V_40 -> V_57 == V_150 )
return - V_170 ;
if ( F_94 ( V_10 , & V_153 ) ) {
V_40 -> V_171 = true ;
F_56 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return - V_165 ;
}
V_6 -> V_166 = V_153 . V_166 ?
V_172 : V_173 ;
V_6 -> V_174 = V_175 | V_176 |
V_177 | V_178 ;
if ( F_60 ( V_10 ) ) {
T_3 V_179 ;
V_88 -> type = V_180 ;
V_6 -> V_7 = ( F_47 ( V_10 , 0x07 ) & 0x0f ) * 256 + F_47 ( V_10 , 0x08 ) ;
V_6 -> V_95 = ( F_47 ( V_10 , 0x09 ) & 0x0f ) * 256 + F_47 ( V_10 , 0x0a ) ;
V_179 = ( ( F_47 ( V_10 , 0x51 ) << 1 ) + ( F_47 ( V_10 , 0x52 ) >> 7 ) ) * 1000000 ;
V_179 += ( ( F_47 ( V_10 , 0x52 ) & 0x7f ) * 7813 ) ;
if ( F_88 ( V_10 ) ) {
V_179 = V_179 * 8 / ( ( ( F_47 ( V_10 , 0x0b ) & 0xc0 ) >> 6 ) * 2 + 8 ) ;
}
V_6 -> V_107 = V_179 ;
V_6 -> V_100 = ( F_47 ( V_10 , 0x20 ) & 0x03 ) * 256 +
F_47 ( V_10 , 0x21 ) ;
V_6 -> V_97 = ( F_47 ( V_10 , 0x22 ) & 0x03 ) * 256 +
F_47 ( V_10 , 0x23 ) ;
V_6 -> V_98 = ( F_47 ( V_10 , 0x24 ) & 0x03 ) * 256 +
F_47 ( V_10 , 0x25 ) ;
V_6 -> V_102 = ( ( F_47 ( V_10 , 0x2a ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x2b ) ) / 2 ;
V_6 -> V_104 = ( ( F_47 ( V_10 , 0x2e ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x2f ) ) / 2 ;
V_6 -> V_105 = ( ( F_47 ( V_10 , 0x32 ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x33 ) ) / 2 ;
V_6 -> V_181 = ( ( F_47 ( V_10 , 0x05 ) & 0x10 ) ? V_163 : 0 ) |
( ( F_47 ( V_10 , 0x05 ) & 0x20 ) ? V_161 : 0 ) ;
if ( V_6 -> V_166 == V_172 ) {
V_6 -> V_95 += ( F_47 ( V_10 , 0x0b ) & 0x0f ) * 256 +
F_47 ( V_10 , 0x0c ) ;
V_6 -> V_182 = ( ( F_47 ( V_10 , 0x2c ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x2d ) ) / 2 ;
V_6 -> V_183 = ( ( F_47 ( V_10 , 0x30 ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x31 ) ) / 2 ;
V_6 -> V_184 = ( ( F_47 ( V_10 , 0x34 ) & 0x1f ) * 256 +
F_47 ( V_10 , 0x35 ) ) / 2 ;
} else {
V_6 -> V_182 = 0 ;
V_6 -> V_183 = 0 ;
V_6 -> V_184 = 0 ;
}
F_98 ( V_10 , V_88 ) ;
} else {
if ( ! F_90 ( V_10 , & V_153 , V_88 ) )
goto V_185;
V_153 . V_159 += 1 ;
F_56 ( 1 , V_52 , V_10 , L_46 , V_53 , V_153 . V_159 ) ;
if ( ! F_90 ( V_10 , & V_153 , V_88 ) )
goto V_185;
V_153 . V_159 -= 2 ;
F_56 ( 1 , V_52 , V_10 , L_47 , V_53 , V_153 . V_159 ) ;
if ( F_90 ( V_10 , & V_153 , V_88 ) ) {
if ( V_40 -> V_171 ) {
F_56 ( 1 , V_52 , V_10 , L_48 , V_53 ) ;
F_52 ( V_10 , 0x86 , 0xf9 , 0x00 ) ;
F_52 ( V_10 , 0x86 , 0xf9 , 0x04 ) ;
F_52 ( V_10 , 0x86 , 0xf9 , 0x02 ) ;
V_40 -> V_171 = false ;
return - V_165 ;
}
F_56 ( 1 , V_52 , V_10 , L_49 , V_53 ) ;
return - V_186 ;
}
V_40 -> V_171 = true ;
}
V_185:
if ( V_52 > 1 )
F_101 ( V_10 -> V_187 , L_50 ,
V_88 , true ) ;
return 0 ;
}
static int F_102 ( struct V_9 * V_10 ,
struct V_1 * V_88 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_14 * V_6 ;
int V_30 ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_57 == V_150 )
return - V_170 ;
if ( F_2 ( & V_40 -> V_88 , V_88 , 0 , false ) ) {
F_56 ( 1 , V_52 , V_10 , L_51 , V_53 ) ;
return 0 ;
}
V_6 = & V_88 -> V_6 ;
if ( ! F_91 ( V_88 , F_61 ( V_10 ) ,
F_1 , NULL ) )
return - V_186 ;
F_98 ( V_10 , V_88 ) ;
V_40 -> V_88 = * V_88 ;
F_51 ( V_10 , 0x91 , V_6 -> V_166 ? 0x40 : 0x00 ) ;
V_30 = F_78 ( V_10 , V_88 ) ;
if ( V_30 ) {
F_79 ( V_10 , V_6 ) ;
}
F_83 ( V_10 ) ;
if ( V_52 > 1 )
F_101 ( V_10 -> V_187 , L_52 ,
V_88 , true ) ;
return 0 ;
}
static int F_103 ( struct V_9 * V_10 ,
struct V_1 * V_88 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_57 == V_150 )
return - V_170 ;
* V_88 = V_40 -> V_88 ;
return 0 ;
}
static void F_104 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_83 ( V_10 ) ;
switch ( V_40 -> V_57 ) {
case V_150 :
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
static void F_105 ( struct V_9 * V_10 )
{
F_49 ( V_10 , 0x1a , 0xef , 0x10 ) ;
F_106 ( 16 ) ;
F_23 ( V_10 , 0x15 , 0xbe ) ;
F_48 ( V_10 , 0x01 , 0x78 ) ;
}
static void F_107 ( struct V_9 * V_10 ,
const struct V_188 * V_189 )
{
F_35 ( V_10 , 0xe0 , 0xbf , V_189 -> V_190 ? 0x00 : 0x40 ) ;
if ( ! V_189 -> V_190 )
return;
F_35 ( V_10 , 0xe0 , 0x7f , V_189 -> V_191 == 2 ? 0x80 : 0x00 ) ;
F_35 ( V_10 , 0xe0 , 0xe0 , V_189 -> V_192 >> 8 ) ;
F_34 ( V_10 , 0xe1 , V_189 -> V_192 ) ;
F_35 ( V_10 , 0xe2 , 0xe0 , V_189 -> V_193 >> 8 ) ;
F_34 ( V_10 , 0xe3 , V_189 -> V_193 ) ;
F_35 ( V_10 , 0xe4 , 0xe0 , V_189 -> V_194 >> 8 ) ;
F_34 ( V_10 , 0xe5 , V_189 -> V_194 ) ;
F_35 ( V_10 , 0xe6 , 0x80 , V_189 -> V_195 >> 8 ) ;
F_34 ( V_10 , 0xe7 , V_189 -> V_195 ) ;
F_35 ( V_10 , 0xe8 , 0xe0 , V_189 -> V_196 >> 8 ) ;
F_34 ( V_10 , 0xe9 , V_189 -> V_196 ) ;
F_35 ( V_10 , 0xea , 0xe0 , V_189 -> V_197 >> 8 ) ;
F_34 ( V_10 , 0xeb , V_189 -> V_197 ) ;
F_35 ( V_10 , 0xec , 0xe0 , V_189 -> V_198 >> 8 ) ;
F_34 ( V_10 , 0xed , V_189 -> V_198 ) ;
F_35 ( V_10 , 0xee , 0x80 , V_189 -> V_199 >> 8 ) ;
F_34 ( V_10 , 0xef , V_189 -> V_199 ) ;
F_35 ( V_10 , 0xf0 , 0xe0 , V_189 -> V_200 >> 8 ) ;
F_34 ( V_10 , 0xf1 , V_189 -> V_200 ) ;
F_35 ( V_10 , 0xf2 , 0xe0 , V_189 -> V_201 >> 8 ) ;
F_34 ( V_10 , 0xf3 , V_189 -> V_201 ) ;
F_35 ( V_10 , 0xf4 , 0xe0 , V_189 -> V_202 >> 8 ) ;
F_34 ( V_10 , 0xf5 , V_189 -> V_202 ) ;
F_35 ( V_10 , 0xf6 , 0x80 , V_189 -> V_203 >> 8 ) ;
F_34 ( V_10 , 0xf7 , V_189 -> V_203 ) ;
}
static void F_108 ( struct V_9 * V_10 ,
enum V_204 V_205 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
switch ( V_40 -> V_57 ) {
case V_150 :
F_23 ( V_10 , 0x00 , V_205 ) ;
F_23 ( V_10 , 0x01 , 0 ) ;
F_52 ( V_10 , 0x81 , 0xef , 0x10 ) ;
F_40 ( V_10 , 0x00 , 0x00 ) ;
F_40 ( V_10 , 0xc8 , 0x00 ) ;
F_23 ( V_10 , 0xdd , 0x90 ) ;
F_41 ( V_10 , 0x02 , 0x7f , 0x80 ) ;
if ( V_205 == V_206 ) {
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
F_23 ( V_10 , 0x00 , V_205 ) ;
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
if ( V_40 -> V_207 )
F_48 ( V_10 , 0x00 , 0x02 ) ;
else
F_48 ( V_10 , 0x00 , 0x03 ) ;
F_23 ( V_10 , 0x00 , V_205 ) ;
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
static int F_109 ( struct V_9 * V_10 ,
T_3 V_208 , T_3 V_209 , T_3 V_210 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_56 ( 2 , V_52 , V_10 , L_53 , V_53 , V_208 ) ;
switch ( V_208 ) {
case V_211 :
V_40 -> V_57 = V_60 ;
V_40 -> V_205 = V_212 ;
V_40 -> V_207 = true ;
break;
case V_213 :
V_40 -> V_57 = V_60 ;
V_40 -> V_205 = V_212 ;
V_40 -> V_207 = false ;
break;
case V_214 :
V_40 -> V_57 = V_59 ;
V_40 -> V_205 = V_215 ;
break;
case V_216 :
V_40 -> V_57 = V_58 ;
V_40 -> V_205 = V_215 ;
break;
case V_217 :
V_40 -> V_57 = V_150 ;
V_40 -> V_205 = V_206 ;
break;
case V_218 :
V_40 -> V_57 = V_150 ;
V_40 -> V_205 = V_219 ;
break;
default:
return - V_79 ;
}
F_105 ( V_10 ) ;
F_108 ( V_10 , V_40 -> V_205 ) ;
F_104 ( V_10 ) ;
F_110 ( V_10 , & V_220 ) ;
return 0 ;
}
static int F_111 ( struct V_9 * V_10 ,
struct V_221 * V_222 ,
struct V_223 * V_55 )
{
if ( V_55 -> V_224 >= F_58 ( V_56 ) )
return - V_79 ;
V_55 -> V_55 = V_56 [ V_55 -> V_224 ] . V_55 ;
return 0 ;
}
static void F_112 ( struct V_8 * V_40 ,
struct V_225 * V_226 )
{
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
V_226 -> V_7 = V_40 -> V_88 . V_6 . V_7 ;
V_226 -> V_95 = V_40 -> V_88 . V_6 . V_95 ;
V_226 -> V_227 = V_228 ;
V_226 -> V_229 = V_230 ;
if ( V_40 -> V_88 . V_6 . V_23 & V_128 )
V_226 -> V_229 = ( V_40 -> V_88 . V_6 . V_95 <= 576 ) ?
V_231 : V_232 ;
}
static unsigned int F_113 ( struct V_8 * V_40 )
{
#define F_114 ( T_5 , T_6 , V_189 , T_7 , T_8 , T_9 ) { \
ADV7842_OP_CH_SEL_##a, ADV7842_OP_CH_SEL_##b, ADV7842_OP_CH_SEL_##c, \
ADV7842_OP_CH_SEL_##d, ADV7842_OP_CH_SEL_##e, ADV7842_OP_CH_SEL_##f }
#define F_115 ( T_10 ) [ADV7842_BUS_ORDER_##x]
static const unsigned int V_233 [ 6 ] [ 6 ] = {
F_115 ( V_234 ) = F_114 ( V_235 , V_236 , V_237 , V_234 , V_238 , V_239 ) ,
F_115 ( V_236 ) = F_114 ( V_237 , V_234 , V_235 , V_236 , V_239 , V_238 ) ,
F_115 ( V_239 ) = F_114 ( V_236 , V_235 , V_238 , V_239 , V_237 , V_234 ) ,
F_115 ( V_237 ) = F_114 ( V_239 , V_238 , V_234 , V_237 , V_236 , V_235 ) ,
F_115 ( V_238 ) = F_114 ( V_238 , V_239 , V_236 , V_235 , V_234 , V_237 ) ,
F_115 ( V_235 ) = F_114 ( V_234 , V_237 , V_239 , V_238 , V_235 , V_236 ) ,
} ;
return V_233 [ V_40 -> V_240 . V_241 ] [ V_40 -> V_226 -> V_233 >> 5 ] ;
}
static void F_116 ( struct V_8 * V_40 )
{
struct V_9 * V_10 = & V_40 -> V_10 ;
F_25 ( V_10 , 0x02 , 0x02 ,
V_40 -> V_226 -> V_242 ? V_243 : 0 ) ;
F_23 ( V_10 , 0x03 , V_40 -> V_226 -> V_244 |
V_40 -> V_240 . V_245 ) ;
F_25 ( V_10 , 0x04 , 0xe0 , F_113 ( V_40 ) ) ;
F_25 ( V_10 , 0x05 , 0x01 ,
V_40 -> V_226 -> V_246 ? V_247 : 0 ) ;
F_83 ( V_10 ) ;
}
static int F_117 ( struct V_9 * V_10 ,
struct V_221 * V_222 ,
struct V_248 * V_226 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_226 -> V_168 != V_249 )
return - V_79 ;
if ( V_40 -> V_57 == V_150 ) {
if ( ! ( F_36 ( V_10 , 0x5a ) & 0x01 ) )
return - V_79 ;
V_226 -> V_226 . V_55 = V_250 ;
V_226 -> V_226 . V_7 = 720 ;
if ( V_40 -> V_251 & V_252 )
V_226 -> V_226 . V_95 = 480 ;
else
V_226 -> V_226 . V_95 = 576 ;
V_226 -> V_226 . V_229 = V_231 ;
return 0 ;
}
F_112 ( V_40 , & V_226 -> V_226 ) ;
if ( V_226 -> V_253 == V_254 ) {
struct V_225 * V_255 ;
V_255 = F_118 ( V_10 , V_222 , V_226 -> V_168 ) ;
V_226 -> V_226 . V_55 = V_255 -> V_55 ;
} else {
V_226 -> V_226 . V_55 = V_40 -> V_226 -> V_55 ;
}
return 0 ;
}
static int F_119 ( struct V_9 * V_10 ,
struct V_221 * V_222 ,
struct V_248 * V_226 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
const struct V_54 * V_256 ;
if ( V_226 -> V_168 != V_249 )
return - V_79 ;
if ( V_40 -> V_57 == V_150 )
return F_117 ( V_10 , V_222 , V_226 ) ;
V_256 = V_54 ( V_40 , V_226 -> V_226 . V_55 ) ;
if ( V_256 == NULL )
V_256 = V_54 ( V_40 , V_250 ) ;
F_112 ( V_40 , & V_226 -> V_226 ) ;
V_226 -> V_226 . V_55 = V_256 -> V_55 ;
if ( V_226 -> V_253 == V_254 ) {
struct V_225 * V_255 ;
V_255 = F_118 ( V_10 , V_222 , V_226 -> V_168 ) ;
V_255 -> V_55 = V_226 -> V_226 . V_55 ;
} else {
V_40 -> V_226 = V_256 ;
F_116 ( V_40 ) ;
}
return 0 ;
}
static void F_120 ( struct V_9 * V_10 , bool V_257 )
{
if ( V_257 ) {
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
static void F_121 ( struct V_9 * V_10 , T_2 V_258 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( ( F_28 ( V_10 , 0x11 ) & 0x01 ) == 0 ) {
F_56 ( 1 , V_52 , V_10 , L_54 , V_53 ) ;
return;
}
if ( V_258 & 0x02 ) {
F_56 ( 1 , V_52 , V_10 , L_55 ,
V_53 ) ;
F_122 ( V_40 -> V_80 , V_259 ,
1 , 0 , 0 , 0 ) ;
return;
}
if ( V_258 & 0x04 ) {
T_2 V_148 ;
T_2 V_260 ;
T_2 V_261 ;
F_56 ( 1 , V_52 , V_10 , L_56 , V_53 ) ;
V_148 = V_262 ;
V_260 = F_28 ( V_10 , 0x14 ) & 0xf ;
if ( V_260 )
V_148 |= V_263 ;
V_261 = F_28 ( V_10 , 0x14 ) >> 4 ;
if ( V_261 )
V_148 |= V_264 ;
F_122 ( V_40 -> V_80 , V_148 ,
0 , V_260 , V_261 , 0 ) ;
return;
}
if ( V_258 & 0x01 ) {
F_56 ( 1 , V_52 , V_10 , L_57 , V_53 ) ;
F_122 ( V_40 -> V_80 , V_265 , 0 , 0 , 0 , 0 ) ;
return;
}
}
static void F_123 ( struct V_9 * V_10 , bool * V_266 )
{
T_2 V_267 ;
V_267 = F_21 ( V_10 , 0x93 ) & 0x0f ;
if ( ! V_267 )
return;
F_56 ( 1 , V_52 , V_10 , L_58 , V_53 , V_267 ) ;
F_121 ( V_10 , V_267 ) ;
if ( V_267 & 0x08 ) {
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_268 V_269 ;
V_269 . V_270 = F_28 ( V_10 , 0x25 ) & 0x1f ;
if ( V_269 . V_270 > 16 )
V_269 . V_270 = 16 ;
if ( V_269 . V_270 ) {
T_2 V_4 ;
for ( V_4 = 0 ; V_4 < V_269 . V_270 ; V_4 ++ )
V_269 . V_269 [ V_4 ] = F_28 ( V_10 , V_4 + 0x15 ) ;
F_29 ( V_10 , 0x26 , 0x01 ) ;
F_124 ( V_40 -> V_80 , & V_269 ) ;
}
}
F_23 ( V_10 , 0x94 , V_267 ) ;
if ( V_266 )
* V_266 = true ;
}
static int F_125 ( struct V_271 * V_272 , bool V_257 )
{
struct V_8 * V_40 = V_272 -> V_273 ;
struct V_9 * V_10 = & V_40 -> V_10 ;
if ( ! V_40 -> V_274 && V_257 ) {
F_30 ( V_10 , 0x2a , 0x01 , 0x01 ) ;
F_29 ( V_10 , 0x2c , 0x01 ) ;
F_30 ( V_10 , 0x11 , 0x01 , 0 ) ;
F_25 ( V_10 , 0x96 , 0x0f , 0x0f ) ;
F_29 ( V_10 , 0x26 , 0x01 ) ;
} else if ( V_40 -> V_274 && ! V_257 ) {
F_25 ( V_10 , 0x96 , 0x0f , 0x00 ) ;
F_30 ( V_10 , 0x27 , 0x70 , 0x00 ) ;
F_30 ( V_10 , 0x2a , 0x01 , 0x00 ) ;
V_40 -> V_275 = 0 ;
}
V_40 -> V_274 = V_257 ;
return 0 ;
}
static int F_126 ( struct V_271 * V_272 , T_2 V_22 )
{
struct V_8 * V_40 = V_272 -> V_273 ;
struct V_9 * V_10 = & V_40 -> V_10 ;
unsigned int V_4 , V_276 = V_277 ;
if ( ! V_40 -> V_274 )
return V_22 == V_278 ? 0 : - V_27 ;
if ( V_22 == V_278 ) {
F_30 ( V_10 , 0x27 , 0x70 , 0 ) ;
V_40 -> V_275 = 0 ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_277 ; V_4 ++ ) {
bool V_279 = V_40 -> V_275 & ( 1 << V_4 ) ;
if ( V_276 == V_277 && ! V_279 )
V_276 = V_4 ;
if ( V_279 && V_40 -> V_280 [ V_4 ] == V_22 )
return 0 ;
}
if ( V_4 == V_277 ) {
V_4 = V_276 ;
if ( V_4 == V_277 )
return - V_281 ;
}
V_40 -> V_280 [ V_4 ] = V_22 ;
V_40 -> V_275 |= 1 << V_4 ;
switch ( V_4 ) {
case 0 :
F_30 ( V_10 , 0x27 , 0x10 , 0x10 ) ;
F_30 ( V_10 , 0x28 , 0x0f , V_22 ) ;
break;
case 1 :
F_30 ( V_10 , 0x27 , 0x20 , 0x20 ) ;
F_30 ( V_10 , 0x28 , 0xf0 , V_22 << 4 ) ;
break;
case 2 :
F_30 ( V_10 , 0x27 , 0x40 , 0x40 ) ;
F_30 ( V_10 , 0x29 , 0x0f , V_22 ) ;
break;
}
return 0 ;
}
static int F_127 ( struct V_271 * V_272 , T_2 V_282 ,
T_3 V_283 , struct V_268 * V_269 )
{
struct V_8 * V_40 = V_272 -> V_273 ;
struct V_9 * V_10 = & V_40 -> V_10 ;
T_2 V_270 = V_269 -> V_270 ;
unsigned int V_4 ;
F_30 ( V_10 , 0x12 , 0x70 , F_128 ( 1 , V_282 - 1 ) << 4 ) ;
if ( V_270 > 16 ) {
F_80 ( V_10 , L_59 , V_53 , V_270 ) ;
return - V_79 ;
}
for ( V_4 = 0 ; V_4 < V_270 ; V_4 ++ )
F_29 ( V_10 , V_4 , V_269 -> V_269 [ V_4 ] ) ;
F_29 ( V_10 , 0x10 , V_270 ) ;
F_29 ( V_10 , 0x11 , 0x01 ) ;
return 0 ;
}
static int F_129 ( struct V_9 * V_10 , T_3 V_148 , bool * V_266 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 V_284 , V_285 , V_286 ;
T_2 V_287 [ 6 ] ;
F_120 ( V_10 , false ) ;
V_287 [ 0 ] = F_21 ( V_10 , 0x43 ) ;
V_287 [ 1 ] = F_21 ( V_10 , 0x57 ) ;
V_287 [ 2 ] = F_21 ( V_10 , 0x70 ) ;
V_287 [ 3 ] = F_21 ( V_10 , 0x75 ) ;
V_287 [ 4 ] = F_21 ( V_10 , 0x9d ) ;
V_287 [ 5 ] = F_21 ( V_10 , 0x66 ) ;
if ( V_287 [ 0 ] )
F_23 ( V_10 , 0x44 , V_287 [ 0 ] ) ;
if ( V_287 [ 1 ] )
F_23 ( V_10 , 0x58 , V_287 [ 1 ] ) ;
if ( V_287 [ 2 ] )
F_23 ( V_10 , 0x71 , V_287 [ 2 ] ) ;
if ( V_287 [ 3 ] )
F_23 ( V_10 , 0x76 , V_287 [ 3 ] ) ;
if ( V_287 [ 4 ] )
F_23 ( V_10 , 0x9e , V_287 [ 4 ] ) ;
if ( V_287 [ 5 ] )
F_23 ( V_10 , 0x67 , V_287 [ 5 ] ) ;
F_120 ( V_10 , true ) ;
F_56 ( 1 , V_52 , V_10 , L_60 , V_53 ,
V_287 [ 0 ] , V_287 [ 1 ] , V_287 [ 2 ] ,
V_287 [ 3 ] , V_287 [ 4 ] , V_287 [ 5 ] ) ;
V_284 = V_287 [ 0 ] & 0x9c ;
if ( V_40 -> V_57 == V_150 )
V_286 = ( V_287 [ 1 ] & 0x30 ) | ( V_287 [ 4 ] & 0x09 ) ;
else
V_286 = 0 ;
if ( F_60 ( V_10 ) )
V_285 = V_287 [ 3 ] & 0x03 ;
else
V_285 = 0 ;
if ( V_284 || V_285 || V_286 ) {
F_56 ( 1 , V_52 , V_10 ,
L_61 ,
V_53 , V_284 , V_285 ,
V_286 ) ;
F_110 ( V_10 , & V_220 ) ;
if ( V_266 )
* V_266 = true ;
}
if ( V_287 [ 5 ] & 0x08 ) {
F_56 ( 1 , V_52 , V_10 , L_62 , V_53 ,
( F_21 ( V_10 , 0x65 ) & 0x08 ) ? L_63 : L_64 ) ;
F_83 ( V_10 ) ;
if ( V_266 )
* V_266 = true ;
}
#if F_130 ( V_288 )
F_123 ( V_10 , V_266 ) ;
#endif
if ( V_287 [ 2 ] & 0x3 ) {
F_56 ( 1 , V_52 , V_10 , L_65 , V_53 ) ;
F_75 ( V_10 ) ;
if ( V_266 )
* V_266 = true ;
}
return 0 ;
}
static int F_131 ( struct V_9 * V_10 , struct V_289 * V_74 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
T_2 * V_20 = NULL ;
memset ( V_74 -> V_290 , 0 , sizeof( V_74 -> V_290 ) ) ;
switch ( V_74 -> V_168 ) {
case V_71 :
case V_72 :
if ( V_40 -> V_70 . V_69 & ( 0x04 << V_74 -> V_168 ) )
V_20 = V_40 -> V_70 . V_74 ;
break;
case V_291 :
if ( V_40 -> V_73 . V_69 )
V_20 = V_40 -> V_73 . V_74 ;
break;
default:
return - V_79 ;
}
if ( V_74 -> V_292 == 0 && V_74 -> V_293 == 0 ) {
V_74 -> V_293 = V_20 ? 2 : 0 ;
return 0 ;
}
if ( ! V_20 )
return - V_170 ;
if ( V_74 -> V_292 >= 2 )
return - V_79 ;
if ( V_74 -> V_292 + V_74 -> V_293 > 2 )
V_74 -> V_293 = 2 - V_74 -> V_292 ;
memcpy ( V_74 -> V_74 , V_20 + V_74 -> V_292 * 128 , V_74 -> V_293 * 128 ) ;
return 0 ;
}
static int F_132 ( struct V_9 * V_10 , struct V_289 * T_8 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 = 0 ;
memset ( T_8 -> V_290 , 0 , sizeof( T_8 -> V_290 ) ) ;
if ( T_8 -> V_168 > V_291 )
return - V_79 ;
if ( T_8 -> V_292 != 0 )
return - V_79 ;
if ( T_8 -> V_293 > 2 ) {
T_8 -> V_293 = 2 ;
return - V_294 ;
}
V_40 -> V_164 = F_133 ( T_8 -> V_74 [ 0x15 ] ,
T_8 -> V_74 [ 0x16 ] ) ;
switch ( T_8 -> V_168 ) {
case V_291 :
memset ( & V_40 -> V_73 . V_74 , 0 , 256 ) ;
V_40 -> V_73 . V_69 = T_8 -> V_293 ? 0x1 : 0x0 ;
memcpy ( & V_40 -> V_73 . V_74 , T_8 -> V_74 , 128 * T_8 -> V_293 ) ;
V_30 = F_65 ( V_10 ) ;
break;
case V_71 :
case V_72 :
memset ( & V_40 -> V_70 . V_74 , 0 , 256 ) ;
if ( T_8 -> V_293 ) {
V_40 -> V_70 . V_69 |= 0x04 << T_8 -> V_168 ;
} else {
V_40 -> V_70 . V_69 &= ~ ( 0x04 << T_8 -> V_168 ) ;
F_75 ( V_10 ) ;
}
memcpy ( & V_40 -> V_70 . V_74 , T_8 -> V_74 , 128 * T_8 -> V_293 ) ;
V_30 = F_67 ( V_10 , T_8 -> V_168 ) ;
break;
default:
return - V_79 ;
}
if ( V_30 < 0 )
F_80 ( V_10 , L_66 , V_30 , T_8 -> V_168 ) ;
return V_30 ;
}
static void F_134 ( struct V_9 * V_10 , struct V_295 * V_296 )
{
int V_4 ;
T_2 V_297 [ 32 ] ;
union V_298 V_299 ;
T_2 V_270 ;
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_300 * V_301 = & V_16 -> V_301 ;
if ( ! ( F_21 ( V_10 , 0x60 ) & V_296 -> V_302 ) ) {
F_72 ( V_10 , L_67 , V_296 -> V_303 ) ;
return;
}
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ )
V_297 [ V_4 ] = F_31 ( V_10 , V_296 -> V_304 + V_4 ) ;
V_270 = V_297 [ 2 ] + 1 ;
if ( V_270 + 3 > sizeof( V_297 ) ) {
F_80 ( V_10 , L_68 , V_53 , V_296 -> V_303 , V_270 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_270 ; V_4 ++ )
V_297 [ V_4 + 3 ] = F_31 ( V_10 , V_296 -> V_305 + V_4 ) ;
if ( F_135 ( & V_299 , V_297 ) < 0 ) {
F_80 ( V_10 , L_69 , V_53 , V_296 -> V_303 ) ;
return;
}
F_136 ( V_306 , V_301 , & V_299 ) ;
}
static void F_137 ( struct V_9 * V_10 )
{
int V_4 ;
struct V_295 V_296 [] = {
{ L_70 , 0x01 , 0xe0 , 0x00 } ,
{ L_71 , 0x02 , 0xe3 , 0x1c } ,
{ L_72 , 0x04 , 0xe6 , 0x2a } ,
{ L_73 , 0x10 , 0xec , 0x54 }
} ;
if ( ! ( F_47 ( V_10 , 0x05 ) & 0x80 ) ) {
F_72 ( V_10 , L_74 ) ;
return;
}
for ( V_4 = 0 ; V_4 < F_58 ( V_296 ) ; V_4 ++ )
F_134 ( V_10 , & V_296 [ V_4 ] ) ;
}
static int F_138 ( struct V_9 * V_10 )
{
T_2 V_307 = F_36 ( V_10 , 0x5A ) & 0x01 ;
F_72 ( V_10 , L_75 , F_86 ( V_10 ) ? L_76 : L_77 ) ;
F_72 ( V_10 , L_78 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ) ;
F_72 ( V_10 , L_79 ,
( F_36 ( V_10 , 0x56 ) & 0x01 ) ? L_77 : L_76 ) ;
F_72 ( V_10 , L_80 , V_307 ?
L_81 : L_82 ) ;
if ( V_307 ) {
static const char * const V_308 [] = {
L_83 ,
L_84 ,
L_85 ,
L_86 ,
L_87 ,
L_88 ,
L_89 ,
L_90 , L_91 , L_92 , L_93 , L_94 ,
L_95 ,
L_96 ,
L_97 ,
L_98
} ;
F_72 ( V_10 , L_99 ,
V_308 [ F_36 ( V_10 , 0x52 ) & 0x0f ] ) ;
F_72 ( V_10 , L_80 ,
( F_36 ( V_10 , 0x59 ) & 0x08 ) ? L_100 : L_101 ) ;
F_72 ( V_10 , L_80 ,
( F_36 ( V_10 , 0x57 ) & 0x08 ) ? L_102 : L_103 ) ;
F_72 ( V_10 , L_104 ,
( F_36 ( V_10 , 0x12 ) & 0x08 ) ? L_105 : L_106 ) ;
F_72 ( V_10 , L_107 ,
( F_33 ( V_10 , 0xe0 ) & 0x40 ) ? L_108 : L_109 ) ;
}
return 0 ;
}
static int F_139 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_1 V_88 ;
T_2 V_309 = F_21 ( V_10 , 0x02 ) ;
T_2 V_310 = F_21 ( V_10 , 0x21 ) ;
T_2 V_311 = F_42 ( V_10 , 0x77 ) ;
T_2 V_312 = F_42 ( V_10 , 0x7d ) ;
bool V_313 = F_47 ( V_10 , 0x04 ) & 0x01 ;
bool V_314 = F_47 ( V_10 , 0x18 ) & 0x01 ;
bool V_315 = F_21 ( V_10 , 0x65 ) & 0x40 ;
static const char * const V_316 [ 16 ] = {
L_110 , L_111 , L_112 , L_113 ,
L_112 , L_114 , L_112 , L_115 ,
L_112 , L_116 , L_117 ,
L_112 , L_112 , L_112 , L_112 , L_109
} ;
static const char * const V_317 [ 16 ] = {
L_118 , L_119 ,
L_120 , L_121 ,
L_122 , L_123 ,
L_124 , L_125 ,
L_126 , L_126 , L_126 , L_126 , L_126 ,
L_126 , L_126 , L_127
} ;
static const char * const V_318 [] = {
L_128 ,
L_118 ,
L_119 ,
} ;
static const char * const V_319 [ 4 ] = {
L_129 ,
L_130 ,
L_131 ,
L_132
} ;
F_72 ( V_10 , L_133 ) ;
F_72 ( V_10 , L_134 , F_86 ( V_10 ) ? L_76 : L_77 ) ;
F_72 ( V_10 , L_135 ,
V_40 -> V_207 ? L_136 : L_137 ) ;
F_72 ( V_10 , L_138 ,
( ( V_312 & 0x04 ) && ( V_311 & 0x04 ) ) ?
L_105 : L_106 ,
( ( V_312 & 0x08 ) && ( V_311 & 0x08 ) ) ?
L_105 : L_106 ) ;
F_72 ( V_10 , L_139 ,
V_310 & 0x02 ? L_105 : L_106 ,
V_310 & 0x01 ? L_105 : L_106 ) ;
F_72 ( V_10 , L_140 , V_40 -> V_274 ?
L_105 : L_106 ) ;
if ( V_40 -> V_274 ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_277 ; V_4 ++ ) {
bool V_279 = V_40 -> V_275 & ( 1 << V_4 ) ;
if ( V_279 )
F_72 ( V_10 , L_141 ,
V_40 -> V_280 [ V_4 ] ) ;
}
}
F_72 ( V_10 , L_142 ) ;
if ( V_40 -> V_207 ) {
F_72 ( V_10 , L_143 ,
F_21 ( V_10 , 0x6f ) & 0x02 ? L_144 : L_145 ) ;
F_72 ( V_10 , L_146 ,
( F_21 ( V_10 , 0x6a ) & 0x02 ) ? L_144 : L_145 ) ;
F_72 ( V_10 , L_147 ,
( F_21 ( V_10 , 0x6a ) & 0x20 ) ? L_144 : L_145 ) ;
} else {
F_72 ( V_10 , L_148 ,
F_21 ( V_10 , 0x6f ) & 0x01 ? L_144 : L_145 ) ;
F_72 ( V_10 , L_146 ,
( F_21 ( V_10 , 0x6a ) & 0x01 ) ? L_144 : L_145 ) ;
F_72 ( V_10 , L_147 ,
( F_21 ( V_10 , 0x6a ) & 0x10 ) ? L_144 : L_145 ) ;
}
F_72 ( V_10 , L_149 ,
( ! ! ( F_50 ( V_10 , 0xff ) & 0x10 ) ? L_77 : L_76 ) ) ;
F_72 ( V_10 , L_150 ,
F_21 ( V_10 , 0x01 ) & 0x0f , F_21 ( V_10 , 0x00 ) & 0x3f ,
( F_21 ( V_10 , 0x01 ) & 0x70 ) >> 4 ) ;
F_72 ( V_10 , L_151 ) ;
if ( F_87 ( V_10 ) ) {
F_72 ( V_10 , L_152 ) ;
} else {
T_3 V_155 = ( ( F_50 ( V_10 , 0xb1 ) & 0x3f ) << 8 ) | F_50 ( V_10 , 0xb2 ) ;
T_3 V_158 = ( ( F_50 ( V_10 , 0xb3 ) & 0x7 ) << 8 ) | F_50 ( V_10 , 0xb4 ) ;
T_3 V_159 = F_50 ( V_10 , 0xb3 ) >> 3 ;
T_3 V_320 = ( ( F_50 ( V_10 , 0xb8 ) & 0x1f ) << 8 ) | F_50 ( V_10 , 0xb9 ) ;
char V_160 = ( ( F_50 ( V_10 , 0xb5 ) & 0x10 ) ?
( ( F_50 ( V_10 , 0xb5 ) & 0x08 ) ? '+' : '-' ) : 'x' ) ;
char V_162 = ( ( F_50 ( V_10 , 0xb5 ) & 0x40 ) ?
( ( F_50 ( V_10 , 0xb5 ) & 0x20 ) ? '+' : '-' ) : 'x' ) ;
F_72 ( V_10 ,
L_153 ,
V_158 , V_155 , V_159 , V_320 ,
( F_50 ( V_10 , 0xb1 ) & 0x40 ) ?
L_43 : L_44 ,
V_160 , V_162 ) ;
}
if ( F_100 ( V_10 , & V_88 ) )
F_72 ( V_10 , L_154 ) ;
else
F_101 ( V_10 -> V_187 , L_155 ,
& V_88 , true ) ;
F_101 ( V_10 -> V_187 , L_156 ,
& V_40 -> V_88 , true ) ;
if ( F_87 ( V_10 ) )
return 0 ;
F_72 ( V_10 , L_157 ) ;
F_72 ( V_10 , L_158 ,
V_318 [ V_40 -> V_126 ] ) ;
F_72 ( V_10 , L_159 ,
V_317 [ V_309 >> 4 ] ) ;
F_72 ( V_10 , L_160 ,
( V_309 & 0x02 ) ? L_161 : L_162 ,
( ( ( V_309 >> 2 ) & 0x01 ) ^ ( V_309 & 0x01 ) ) ?
L_163 : L_164 ,
( V_309 & 0x08 ) ? L_105 : L_106 ) ;
F_72 ( V_10 , L_165 ,
V_316 [ F_50 ( V_10 , 0xf4 ) >> 4 ] ) ;
if ( ! F_60 ( V_10 ) )
return 0 ;
F_72 ( V_10 , L_166 , F_88 ( V_10 ) ? L_63 : L_167 ) ;
F_72 ( V_10 , L_168 ,
( F_47 ( V_10 , 0x05 ) & 0x40 ) ? L_144 : L_145 ) ;
F_72 ( V_10 , L_169 ,
( F_47 ( V_10 , 0x04 ) & 0x20 ) ? L_170 : L_171 ,
( F_47 ( V_10 , 0x04 ) & 0x10 ) ? L_172 : L_173 ) ;
if ( ! F_88 ( V_10 ) )
return 0 ;
F_72 ( V_10 , L_174 ,
V_313 ? L_175 : L_176 ,
V_314 ? L_177 : L_178 ,
V_315 ? L_179 : L_105 ) ;
if ( V_313 && V_314 ) {
F_72 ( V_10 , L_180 ,
( F_47 ( V_10 , 0x07 ) & 0x40 ) ? L_181 : L_182 ) ;
}
F_72 ( V_10 , L_183 , ( F_47 ( V_10 , 0x5b ) << 12 ) +
( F_47 ( V_10 , 0x5c ) << 8 ) +
( F_47 ( V_10 , 0x5d ) & 0xf0 ) ) ;
F_72 ( V_10 , L_184 , ( ( F_47 ( V_10 , 0x5d ) & 0x0f ) << 16 ) +
( F_47 ( V_10 , 0x5e ) << 8 ) +
F_47 ( V_10 , 0x5f ) ) ;
F_72 ( V_10 , L_185 ,
( F_47 ( V_10 , 0x04 ) & 0x40 ) ? L_77 : L_76 ) ;
F_72 ( V_10 , L_186 ,
V_319 [ F_47 ( V_10 , 0x0b ) >> 6 ] ) ;
F_137 ( V_10 ) ;
return 0 ;
}
static int F_140 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_57 == V_150 )
return F_138 ( V_10 ) ;
return F_139 ( V_10 ) ;
}
static int F_141 ( struct V_9 * V_10 , T_11 * V_321 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_57 != V_150 )
return - V_170 ;
if ( ! ( F_36 ( V_10 , 0x5A ) & 0x01 ) ) {
* V_321 = 0 ;
F_56 ( 1 , V_52 , V_10 , L_45 , V_53 ) ;
return 0 ;
}
switch ( F_36 ( V_10 , 0x52 ) & 0x0f ) {
case 0 :
* V_321 &= V_322 ;
break;
case 2 :
* V_321 &= V_323 ;
break;
case 3 :
* V_321 &= V_324 ;
break;
case 4 :
* V_321 &= V_325 ;
break;
case 6 :
* V_321 &= V_326 ;
break;
case 0xc :
* V_321 &= V_327 ;
break;
case 0xe :
* V_321 &= V_328 ;
break;
case 0xf :
* V_321 &= V_324 ;
break;
default:
* V_321 &= V_329 ;
break;
}
return 0 ;
}
static void F_142 ( struct V_9 * V_10 , struct V_330 * V_331 )
{
if ( V_331 && V_331 -> V_332 ) {
F_34 ( V_10 , 0x94 , ( V_331 -> V_333 >> 8 ) & 0xf ) ;
F_34 ( V_10 , 0x95 , V_331 -> V_333 & 0xff ) ;
F_34 ( V_10 , 0x96 , ( V_331 -> V_334 >> 8 ) & 0xf ) ;
F_34 ( V_10 , 0x97 , V_331 -> V_334 & 0xff ) ;
F_34 ( V_10 , 0x98 , ( V_331 -> V_335 >> 8 ) & 0xf ) ;
F_34 ( V_10 , 0x99 , V_331 -> V_335 & 0xff ) ;
F_34 ( V_10 , 0x9a , ( V_331 -> V_336 >> 8 ) & 0xf ) ;
F_34 ( V_10 , 0x9b , V_331 -> V_336 & 0xff ) ;
F_34 ( V_10 , 0xa8 , V_331 -> V_337 ) ;
F_34 ( V_10 , 0xa9 , V_331 -> V_338 ) ;
F_34 ( V_10 , 0xaa , V_331 -> V_339 ) ;
F_34 ( V_10 , 0xab , V_331 -> V_340 ) ;
F_34 ( V_10 , 0xac , V_331 -> V_341 ) ;
F_34 ( V_10 , 0xad , V_331 -> V_342 ) ;
F_34 ( V_10 , 0xae , V_331 -> V_343 ) ;
F_34 ( V_10 , 0xaf , V_331 -> V_344 ) ;
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
static int F_143 ( struct V_9 * V_10 , T_11 V_251 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_345 * V_240 = & V_40 -> V_240 ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_57 != V_150 )
return - V_170 ;
if ( V_251 & V_346 )
F_142 ( V_10 , & V_240 -> V_347 ) ;
else if ( V_251 & V_252 )
F_142 ( V_10 , & V_240 -> V_348 ) ;
else
F_142 ( V_10 , NULL ) ;
if ( V_251 & V_329 ) {
V_40 -> V_251 = V_251 ;
return 0 ;
}
return - V_79 ;
}
static int F_144 ( struct V_9 * V_10 , T_11 * V_251 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_56 ( 1 , V_52 , V_10 , L_5 , V_53 ) ;
if ( V_40 -> V_57 != V_150 )
return - V_170 ;
* V_251 = V_40 -> V_251 ;
return 0 ;
}
static int F_145 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_345 * V_240 = & V_40 -> V_240 ;
F_48 ( V_10 , 0x48 ,
( V_240 -> V_349 ? 0x80 : 0 ) |
( V_240 -> V_350 ? 0x40 : 0 ) ) ;
F_105 ( V_10 ) ;
F_44 ( V_10 , 0x77 , 0xd3 , 0x20 ) ;
F_23 ( V_10 , 0x0c , 0x42 ) ;
F_23 ( V_10 , 0x15 , 0x80 ) ;
F_23 ( V_10 , 0x02 , 0xf0 | V_240 -> V_351 << 3 ) ;
F_24 ( V_10 , 0x05 , 0xf0 , V_240 -> V_352 << 3 |
V_240 -> V_353 << 2 |
V_240 -> V_354 << 1 ) ;
F_116 ( V_40 ) ;
F_49 ( V_10 , 0x1a , 0xf1 , 0x08 ) ;
F_24 ( V_10 , 0x14 , 0xc0 ,
V_240 -> V_355 << 4 |
V_240 -> V_356 << 2 |
V_240 -> V_357 ) ;
F_52 ( V_10 , 0xba , 0xfc , V_240 -> V_358 |
( V_240 -> V_359 << 1 ) ) ;
F_38 ( V_10 , 0xdd , 0xf0 , V_240 -> V_360 |
( V_240 -> V_361 << 1 ) |
( V_240 -> V_362 << 2 ) |
( V_240 -> V_363 << 3 ) ) ;
F_51 ( V_10 , 0x69 , 0x14 ) ;
F_23 ( V_10 , 0x06 , 0xa6 ) ;
F_51 ( V_10 , 0xf3 , 0xdc ) ;
F_40 ( V_10 , 0xb5 , 0x01 ) ;
F_40 ( V_10 , 0x02 , V_240 -> V_364 ) ;
F_24 ( V_10 , 0x30 , ~ ( 1 << 4 ) , V_240 -> V_365 << 4 ) ;
F_107 ( V_10 , & V_240 -> F_107 ) ;
if ( V_240 -> V_366 >= 128 ) {
F_37 ( V_10 , 0x12 , 0x0d ) ;
if ( V_240 -> V_367 ) {
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
F_108 ( V_10 , V_240 -> V_205 ) ;
F_104 ( V_10 ) ;
if ( V_240 -> V_368 ) {
F_48 ( V_10 , 0x69 , 0x5c ) ;
} else {
F_48 ( V_10 , 0x69 , 0xa3 ) ;
F_24 ( V_10 , 0x20 , 0xcf , 0x00 ) ;
}
F_23 ( V_10 , 0x19 , 0x80 | V_240 -> V_369 ) ;
F_23 ( V_10 , 0x33 , 0x40 ) ;
F_23 ( V_10 , 0x40 , 0xf2 ) ;
F_120 ( V_10 , true ) ;
return F_146 ( V_10 -> V_370 ) ;
}
static int F_147 ( struct V_9 * V_10 )
{
int V_4 ;
int V_371 = 0 ;
int V_372 = 0 ;
int V_373 = 0 ;
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
T_2 V_374 = F_33 ( V_10 , 0xdb ) ;
if ( V_374 & 0x10 ) {
V_373 ++ ;
if ( V_374 & 0x20 )
V_372 ++ ;
else
V_371 ++ ;
}
F_57 ( 20 ) ;
}
F_56 ( 1 , V_52 , V_10 ,
L_187 ,
V_373 , V_4 , V_371 , V_372 ) ;
if ( ! V_373 || V_372 )
return - V_27 ;
return 0 ;
}
static void F_148 ( struct V_9 * V_10 ,
struct V_345 * V_240 )
{
F_23 ( V_10 , 0xf1 , V_240 -> V_45 << 1 ) ;
F_23 ( V_10 , 0xf2 , V_240 -> V_44 << 1 ) ;
F_23 ( V_10 , 0xf3 , V_240 -> V_41 << 1 ) ;
F_23 ( V_10 , 0xf4 , V_240 -> V_42 << 1 ) ;
F_23 ( V_10 , 0xf5 , V_240 -> V_43 << 1 ) ;
F_23 ( V_10 , 0xf8 , V_240 -> V_46 << 1 ) ;
F_23 ( V_10 , 0xf9 , V_240 -> V_47 << 1 ) ;
F_23 ( V_10 , 0xfa , V_240 -> V_48 << 1 ) ;
F_23 ( V_10 , 0xfb , V_240 -> V_49 << 1 ) ;
F_23 ( V_10 , 0xfd , V_240 -> V_50 << 1 ) ;
F_23 ( V_10 , 0xfe , V_240 -> V_51 << 1 ) ;
}
static int F_149 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_345 * V_240 = V_16 -> V_301 . V_375 ;
struct V_1 V_88 ;
int V_28 = 0 ;
if ( ! V_240 )
return - V_376 ;
if ( ! V_240 -> V_366 || ! V_240 -> V_367 ) {
F_72 ( V_10 , L_188 ) ;
return - V_79 ;
}
F_55 ( V_10 ) ;
F_148 ( V_10 , V_240 ) ;
V_28 = F_147 ( V_10 ) ;
F_55 ( V_10 ) ;
F_148 ( V_10 , V_240 ) ;
F_145 ( V_10 ) ;
F_105 ( V_10 ) ;
F_108 ( V_10 , V_40 -> V_205 ) ;
F_104 ( V_10 ) ;
F_65 ( V_10 ) ;
F_67 ( V_10 , V_71 ) ;
F_67 ( V_10 , V_72 ) ;
V_88 = V_40 -> V_88 ;
memset ( & V_40 -> V_88 , 0 , sizeof( struct V_1 ) ) ;
F_102 ( V_10 , & V_88 ) ;
return V_28 ;
}
static long F_150 ( struct V_9 * V_10 , unsigned int V_377 , void * V_378 )
{
switch ( V_377 ) {
case V_379 :
return F_149 ( V_10 ) ;
}
return - V_380 ;
}
static int F_151 ( struct V_9 * V_10 ,
struct V_381 * V_382 ,
struct V_383 * V_384 )
{
switch ( V_384 -> type ) {
case V_385 :
return F_152 ( V_10 , V_382 , V_384 ) ;
case V_386 :
return F_153 ( V_10 , V_382 , V_384 ) ;
default:
return - V_79 ;
}
}
static int F_154 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
int V_30 ;
V_30 = F_155 ( V_40 -> V_80 ) ;
if ( V_30 )
F_156 ( V_40 -> V_80 ) ;
return V_30 ;
}
static void F_157 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_158 ( V_40 -> V_80 ) ;
}
static void F_159 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
if ( V_40 -> V_41 )
F_160 ( V_40 -> V_41 ) ;
if ( V_40 -> V_42 )
F_160 ( V_40 -> V_42 ) ;
if ( V_40 -> V_43 )
F_160 ( V_40 -> V_43 ) ;
if ( V_40 -> V_44 )
F_160 ( V_40 -> V_44 ) ;
if ( V_40 -> V_45 )
F_160 ( V_40 -> V_45 ) ;
if ( V_40 -> V_46 )
F_160 ( V_40 -> V_46 ) ;
if ( V_40 -> V_47 )
F_160 ( V_40 -> V_47 ) ;
if ( V_40 -> V_48 )
F_160 ( V_40 -> V_48 ) ;
if ( V_40 -> V_49 )
F_160 ( V_40 -> V_49 ) ;
if ( V_40 -> V_50 )
F_160 ( V_40 -> V_50 ) ;
if ( V_40 -> V_51 )
F_160 ( V_40 -> V_51 ) ;
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
static struct V_15 * F_161 ( struct V_9 * V_10 , const char * V_303 ,
T_2 V_22 , T_2 V_387 )
{
struct V_15 * V_16 = F_22 ( V_10 ) ;
struct V_15 * V_388 ;
F_23 ( V_10 , V_387 , V_22 << 1 ) ;
if ( V_22 == 0 ) {
F_80 ( V_10 , L_189 , V_303 ) ;
return NULL ;
}
V_388 = F_162 ( V_16 -> V_21 , F_21 ( V_10 , V_387 ) >> 1 ) ;
if ( ! V_388 )
F_80 ( V_10 , L_190 , V_303 , V_22 ) ;
return V_388 ;
}
static int F_163 ( struct V_9 * V_10 )
{
struct V_8 * V_40 = F_3 ( V_10 ) ;
struct V_345 * V_240 = & V_40 -> V_240 ;
V_40 -> V_41 = F_161 ( V_10 , L_191 , V_240 -> V_41 , 0xf3 ) ;
V_40 -> V_42 = F_161 ( V_10 , L_192 , V_240 -> V_42 , 0xf4 ) ;
V_40 -> V_43 = F_161 ( V_10 , L_193 , V_240 -> V_43 , 0xf5 ) ;
V_40 -> V_44 = F_161 ( V_10 , L_194 , V_240 -> V_44 , 0xf2 ) ;
V_40 -> V_45 = F_161 ( V_10 , L_195 , V_240 -> V_45 , 0xf1 ) ;
V_40 -> V_46 = F_161 ( V_10 , L_196 , V_240 -> V_46 , 0xf8 ) ;
V_40 -> V_47 = F_161 ( V_10 , L_197 , V_240 -> V_47 , 0xf9 ) ;
V_40 -> V_48 = F_161 ( V_10 , L_198 , V_240 -> V_48 , 0xfa ) ;
V_40 -> V_49 = F_161 ( V_10 , L_199 , V_240 -> V_49 , 0xfb ) ;
V_40 -> V_50 = F_161 ( V_10 , L_200 , V_240 -> V_50 , 0xfd ) ;
V_40 -> V_51 = F_161 ( V_10 , L_201 , V_240 -> V_51 , 0xfe ) ;
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
static int F_164 ( struct V_15 * V_16 ,
const struct V_389 * V_131 )
{
struct V_8 * V_40 ;
static const struct V_1 V_390 =
V_391 ;
struct V_345 * V_240 = V_16 -> V_301 . V_375 ;
struct V_392 * V_3 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
T_4 V_393 ;
int V_30 ;
if ( ! F_165 ( V_16 -> V_21 , V_394 ) )
return - V_27 ;
F_166 ( 1 , V_52 , V_16 , L_202 ,
V_16 -> V_22 << 1 ) ;
if ( ! V_240 ) {
F_16 ( V_16 , L_203 ) ;
return - V_376 ;
}
V_40 = F_167 ( & V_16 -> V_301 , sizeof( struct V_8 ) , V_395 ) ;
if ( ! V_40 ) {
F_16 ( V_16 , L_204 ) ;
return - V_396 ;
}
V_40 -> V_240 = * V_240 ;
V_40 -> V_88 = V_390 ;
V_40 -> V_226 = V_54 ( V_40 , V_250 ) ;
V_10 = & V_40 -> V_10 ;
F_168 ( V_10 , V_16 , & V_397 ) ;
V_10 -> V_23 |= V_398 | V_399 ;
V_10 -> V_400 = & V_401 ;
V_40 -> V_57 = V_240 -> V_57 ;
V_40 -> V_207 = V_240 -> V_208 == V_211 ;
V_40 -> V_171 = true ;
V_393 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
if ( V_393 != 0x2012 ) {
F_72 ( V_10 , L_205 , V_393 ) ;
V_393 = F_14 ( V_16 , 0xea , false ) << 8 |
F_14 ( V_16 , 0xeb , false ) ;
}
if ( V_393 != 0x2012 ) {
F_72 ( V_10 , L_206 ,
V_16 -> V_22 << 1 , V_393 ) ;
return - V_376 ;
}
if ( V_240 -> V_402 )
F_55 ( V_10 ) ;
V_3 = & V_40 -> V_3 ;
F_169 ( V_3 , 6 ) ;
F_170 ( V_3 , & V_403 ,
V_132 , - 128 , 127 , 1 , 0 ) ;
F_170 ( V_3 , & V_403 ,
V_133 , 0 , 255 , 1 , 128 ) ;
F_170 ( V_3 , & V_403 ,
V_134 , 0 , 255 , 1 , 128 ) ;
F_170 ( V_3 , & V_403 ,
V_135 , 0 , 128 , 1 , 0 ) ;
V_12 = F_171 ( V_3 , & V_403 ,
V_146 , V_147 ,
0 , V_147 ) ;
if ( V_12 )
V_12 -> V_23 |= V_404 ;
V_40 -> V_84 = F_170 ( V_3 , NULL ,
V_405 , 0 , 3 , 0 , 0 ) ;
V_40 -> V_406 = F_172 ( V_3 ,
& V_407 , NULL ) ;
V_40 -> V_408 = F_172 ( V_3 ,
& V_409 , NULL ) ;
V_40 -> V_410 = F_172 ( V_3 ,
& V_411 , NULL ) ;
V_40 -> V_412 =
F_171 ( V_3 , & V_403 ,
V_145 , V_130 ,
0 , V_127 ) ;
V_10 -> V_370 = V_3 ;
if ( V_3 -> error ) {
V_30 = V_3 -> error ;
goto V_413;
}
if ( F_75 ( V_10 ) ) {
V_30 = - V_376 ;
goto V_413;
}
if ( F_163 ( V_10 ) < 0 ) {
V_30 = - V_396 ;
F_80 ( V_10 , L_207 ) ;
goto V_414;
}
F_173 ( & V_40 -> V_68 ,
F_63 ) ;
V_40 -> V_168 . V_23 = V_415 ;
V_30 = F_174 ( & V_10 -> V_416 , 1 , & V_40 -> V_168 ) ;
if ( V_30 )
goto V_417;
V_30 = F_145 ( V_10 ) ;
if ( V_30 )
goto V_418;
#if F_130 ( V_288 )
V_40 -> V_80 = F_175 ( & V_419 ,
V_40 , F_176 ( & V_16 -> V_301 ) ,
V_420 | V_421 |
V_422 | V_423 , V_277 ,
& V_16 -> V_301 ) ;
V_30 = F_177 ( V_40 -> V_80 ) ;
if ( V_30 )
goto V_418;
#endif
F_72 ( V_10 , L_208 , V_16 -> V_187 ,
V_16 -> V_22 << 1 , V_16 -> V_21 -> V_187 ) ;
return 0 ;
V_418:
F_178 ( & V_10 -> V_416 ) ;
V_417:
F_179 ( & V_40 -> V_68 ) ;
V_414:
F_159 ( V_10 ) ;
V_413:
F_180 ( V_3 ) ;
return V_30 ;
}
static int F_181 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = F_182 ( V_16 ) ;
struct V_8 * V_40 = F_3 ( V_10 ) ;
F_120 ( V_10 , false ) ;
F_179 ( & V_40 -> V_68 ) ;
F_183 ( V_10 ) ;
F_178 ( & V_10 -> V_416 ) ;
F_159 ( V_10 ) ;
F_180 ( V_10 -> V_370 ) ;
return 0 ;
}
