static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_6 , L_1 ) ;
F_6 ( V_2 -> V_6 , L_2 ,
F_3 ( V_2 , V_7 ) ) ;
F_6 ( V_2 -> V_6 , L_3 ,
F_3 ( V_2 , V_8 ) ) ;
F_6 ( V_2 -> V_6 , L_4 ,
F_3 ( V_2 , V_9 ) ) ;
F_6 ( V_2 -> V_6 , L_5 ,
F_3 ( V_2 , V_10 ) ) ;
F_6 ( V_2 -> V_6 , L_6 ,
F_3 ( V_2 , V_11 ) ) ;
F_6 ( V_2 -> V_6 , L_7 ,
F_3 ( V_2 , V_12 ) ) ;
F_6 ( V_2 -> V_6 , L_8 ,
F_3 ( V_2 , V_13 ) ) ;
F_6 ( V_2 -> V_6 , L_9 ,
F_3 ( V_2 , V_14 ) ) ;
F_6 ( V_2 -> V_6 , L_10 ,
F_3 ( V_2 , V_15 ) ) ;
F_6 ( V_2 -> V_6 , L_11 ,
F_3 ( V_2 , V_16 ) ) ;
F_6 ( V_2 -> V_6 , L_12 ,
F_3 ( V_2 , V_17 ) ) ;
F_6 ( V_2 -> V_6 , L_13 ,
F_3 ( V_2 , V_18 ) ) ;
F_6 ( V_2 -> V_6 , L_14 ,
F_3 ( V_2 , V_19 ) ) ;
F_6 ( V_2 -> V_6 , L_1 ) ;
}
static void F_5 ( struct V_1 * V_2 ) {}
static void F_7 ( struct V_1 * V_2 )
{
T_2 V_20 = F_3 ( V_2 , V_15 ) ;
T_2 V_21 = V_2 -> V_22 [ 0 ] . V_21 | V_2 -> V_22 [ 1 ] . V_21 ;
V_20 |= ( V_23 | V_24 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
V_20 |= V_21 ;
F_1 ( V_2 , V_15 , V_20 ) ;
V_20 &= ~ ( V_23 | V_24 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_20 = F_3 ( V_2 , V_15 ) ;
T_2 V_21 = V_25 | V_26 ;
V_20 |= ( V_23 | V_24 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
V_20 &= ~ ( V_21 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
V_20 &= ~ ( V_23 | V_24 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_15 ) &
( V_25 | V_26 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_2 V_20 = F_3 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_15 , V_20 | V_27 ) ;
F_1 ( V_2 , V_9 ,
V_28 | V_29 |
V_30 | V_31 ) ;
if ( V_2 -> V_32 ) {
T_2 V_33 = V_2 -> V_32 ;
F_1 ( V_2 , V_34 , V_33 ) ;
V_33 |= ( V_35 | V_36 ) ;
F_1 ( V_2 , V_34 , V_33 ) ;
}
F_1 ( V_2 , V_18 ,
V_2 -> V_22 [ V_37 ] . V_38 ) ;
F_1 ( V_2 , V_19 ,
V_2 -> V_22 [ V_39 ] . V_38 ) ;
F_1 ( V_2 , V_12 ,
V_40 | V_41 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 ,
V_28 | V_29 ) ;
F_1 ( V_2 , V_13 , V_40 ) ;
F_1 ( V_2 , V_10 ,
V_30 | V_31 ) ;
F_1 ( V_2 , V_13 , V_41 ) ;
if ( V_2 -> V_32 )
F_1 ( V_2 , V_34 , 0 ) ;
}
static T_3 F_12 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
int V_44 ;
V_44 = F_3 ( V_2 , V_8 ) ;
F_1 ( V_2 , V_8 , V_44 ) ;
if ( V_44 & V_29 )
F_6 ( V_2 -> V_6 , L_15 ) ;
if ( V_44 & V_28 )
F_6 ( V_2 -> V_6 , L_16 ) ;
if ( V_44 & V_45 )
F_6 ( V_2 -> V_6 , L_17 ) ;
if ( V_44 & V_31 )
F_6 ( V_2 -> V_6 , L_18 ) ;
if ( V_44 & V_30 )
F_6 ( V_2 -> V_6 , L_19 ) ;
if ( V_44 & V_46 )
F_6 ( V_2 -> V_6 , L_20 ) ;
return V_47 ;
}
static int F_13 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
F_15 ( & V_2 -> V_52 ) ;
if ( ! V_51 -> V_53 )
F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_52 ) ;
return 0 ;
}
static void F_17 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
F_15 ( & V_2 -> V_52 ) ;
if ( ! V_51 -> V_53 ) {
if ( F_9 ( V_2 ) ) {
F_8 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_22 [ 0 ] . V_21 = 0 ;
V_2 -> V_22 [ 1 ] . V_21 = 0 ;
}
}
F_16 ( & V_2 -> V_52 ) ;
}
static int F_18 ( struct V_48 * V_49 ,
struct V_54 * V_55 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
int V_56 = V_49 -> V_56 ;
struct V_57 * V_58 ;
T_2 V_38 ;
int V_59 ;
int V_21 = 0 ;
V_59 = F_19 ( V_55 ) ;
switch ( V_59 ) {
case 5 :
if ( V_56 == V_39 )
return - V_60 ;
V_21 |= 1 << 4 ;
case 4 :
if ( V_56 == V_39 )
return - V_60 ;
V_21 |= 1 << 3 ;
case 3 :
V_21 |= 1 << 2 ;
case 2 :
V_21 |= 1 << 1 ;
case 1 :
V_21 |= 1 << 0 ;
break;
default:
return - V_60 ;
}
V_58 = F_20 ( V_51 , V_49 ) ;
V_38 = V_2 -> V_22 [ V_56 ] . V_38 ;
if ( V_56 == V_37 ) {
V_21 <<= 3 ;
if ( ! V_2 -> V_22 [ ! V_56 ] . V_21 )
V_2 -> V_22 [ ! V_56 ] . V_21 = 0x3 ;
V_58 -> V_61 =
( V_62 - V_38 ) * V_59 ;
} else {
if ( ! V_2 -> V_22 [ ! V_56 ] . V_21 )
V_2 -> V_22 [ ! V_56 ] . V_21 = ( 0x3 << 3 ) ;
V_58 -> V_61 = V_38 * V_59 ;
}
if ( V_2 -> V_22 [ V_56 ] . V_21 &&
V_2 -> V_22 [ V_56 ] . V_21 != V_21 )
V_2 -> V_63 = true ;
V_2 -> V_22 [ V_56 ] . V_21 = V_21 ;
return 0 ;
}
static int F_21 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
if ( ! F_9 ( V_2 ) ) {
F_7 ( V_2 ) ;
F_5 ( V_2 ) ;
} else if ( V_2 -> V_63 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
V_2 -> V_63 = false ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static int F_22 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
int V_64 ;
F_23 ( V_2 -> V_6 ) ;
F_24 ( V_2 -> V_6 ) ;
F_1 ( V_2 , V_15 , 0x00 ) ;
V_64 = F_25 ( V_2 -> V_42 , F_12 , 0 , L_21 ,
( void * ) V_2 ) ;
F_26 ( V_2 -> V_6 ) ;
if ( V_64 ) {
F_27 ( V_2 -> V_6 , L_22 ) ;
F_28 ( V_2 -> V_6 ) ;
}
V_2 -> V_22 [ V_37 ] . V_38 = 2 ;
V_2 -> V_22 [ V_39 ] . V_38 =
V_65 - 3 ;
F_29 ( V_51 ,
& V_2 -> V_58 [ V_37 ] ,
& V_2 -> V_58 [ V_39 ] ) ;
return V_64 ;
}
static int F_30 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
F_31 ( V_2 -> V_42 , ( void * ) V_2 ) ;
F_28 ( V_2 -> V_6 ) ;
return 0 ;
}
static int F_32 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
if ( V_51 -> V_53 ) {
F_8 ( V_2 ) ;
F_11 ( V_2 ) ;
}
V_2 -> V_66 = 0 ;
while ( F_33 ( V_2 -> V_6 ) ) {
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_66 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
if ( V_2 -> V_66 ) {
while ( V_2 -> V_66 -- )
F_24 ( V_2 -> V_6 ) ;
if ( V_51 -> V_53 ) {
F_10 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
return 0 ;
}
void F_35 ( struct V_67 * V_68 ,
T_4 V_69 , T_4 V_70 )
{
struct V_1 * V_2 = F_14 ( V_68 -> V_71 ) ;
V_2 -> V_32 = F_36 ( V_69 ) | F_37 ( V_70 ) ;
}
static int F_38 ( struct V_72 * V_73 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
int V_64 ;
V_2 = F_39 ( & V_73 -> V_6 , sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_2 )
return - V_77 ;
F_40 ( V_73 , V_2 ) ;
F_41 ( & V_2 -> V_52 ) ;
V_75 = F_42 ( V_73 , V_78 , L_23 ) ;
if ( V_75 == NULL )
return - V_77 ;
V_2 -> V_58 [ 0 ] . V_79 = V_75 -> V_80 + V_16 ;
V_2 -> V_58 [ 1 ] . V_79 = V_75 -> V_80 + V_17 ;
V_2 -> V_58 [ 0 ] . V_81 = L_24 ;
V_2 -> V_58 [ 1 ] . V_81 = L_25 ;
V_75 = F_42 ( V_73 , V_78 , L_26 ) ;
V_2 -> V_5 = F_43 ( & V_73 -> V_6 , V_75 ) ;
if ( F_44 ( V_2 -> V_5 ) )
return F_45 ( V_2 -> V_5 ) ;
V_2 -> V_42 = F_46 ( V_73 , 0 ) ;
if ( V_2 -> V_42 < 0 )
return V_2 -> V_42 ;
V_2 -> V_6 = & V_73 -> V_6 ;
V_64 = F_47 ( & V_73 -> V_6 ,
& V_82 ,
& V_83 , 1 ) ;
if ( V_64 )
return V_64 ;
return F_48 ( & V_73 -> V_6 ) ;
}
