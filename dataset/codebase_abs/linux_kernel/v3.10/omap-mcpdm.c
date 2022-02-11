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
F_1 ( V_2 , V_9 ,
V_27 | V_28 |
V_29 | V_30 ) ;
if ( V_2 -> V_31 ) {
T_2 V_32 = V_2 -> V_31 ;
F_1 ( V_2 , V_33 , V_32 ) ;
V_32 |= ( V_34 | V_35 ) ;
F_1 ( V_2 , V_33 , V_32 ) ;
}
F_1 ( V_2 , V_18 ,
V_2 -> V_22 [ V_36 ] . V_37 ) ;
F_1 ( V_2 , V_19 ,
V_2 -> V_22 [ V_38 ] . V_37 ) ;
F_1 ( V_2 , V_12 ,
V_39 | V_40 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 ,
V_27 | V_28 ) ;
F_1 ( V_2 , V_13 , V_39 ) ;
F_1 ( V_2 , V_10 ,
V_29 | V_30 ) ;
F_1 ( V_2 , V_13 , V_40 ) ;
if ( V_2 -> V_31 )
F_1 ( V_2 , V_33 , 0 ) ;
}
static T_3 F_12 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
int V_43 ;
V_43 = F_3 ( V_2 , V_8 ) ;
F_1 ( V_2 , V_8 , V_43 ) ;
if ( V_43 & V_28 )
F_6 ( V_2 -> V_6 , L_15 ) ;
if ( V_43 & V_27 )
F_6 ( V_2 -> V_6 , L_16 ) ;
if ( V_43 & V_44 )
F_6 ( V_2 -> V_6 , L_17 ) ;
if ( V_43 & V_30 )
F_6 ( V_2 -> V_6 , L_18 ) ;
if ( V_43 & V_29 )
F_6 ( V_2 -> V_6 , L_19 ) ;
if ( V_43 & V_45 )
F_6 ( V_2 -> V_6 , L_20 ) ;
return V_46 ;
}
static int F_13 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_14 ( V_50 ) ;
F_15 ( & V_2 -> V_51 ) ;
if ( ! V_50 -> V_52 ) {
T_2 V_20 = F_3 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_15 , V_20 | V_53 ) ;
F_10 ( V_2 ) ;
}
F_16 ( & V_2 -> V_51 ) ;
F_17 ( V_50 , V_48 ,
& V_2 -> V_54 [ V_48 -> V_55 ] ) ;
return 0 ;
}
static void F_18 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_14 ( V_50 ) ;
F_15 ( & V_2 -> V_51 ) ;
if ( ! V_50 -> V_52 ) {
if ( F_9 ( V_2 ) ) {
F_8 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_22 [ 0 ] . V_21 = 0 ;
V_2 -> V_22 [ 1 ] . V_21 = 0 ;
}
}
F_16 ( & V_2 -> V_51 ) ;
}
static int F_19 ( struct V_47 * V_48 ,
struct V_56 * V_57 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_14 ( V_50 ) ;
int V_55 = V_48 -> V_55 ;
struct V_58 * V_54 ;
T_2 V_37 ;
int V_59 ;
int V_21 = 0 ;
V_59 = F_20 ( V_57 ) ;
switch ( V_59 ) {
case 5 :
if ( V_55 == V_38 )
return - V_60 ;
V_21 |= 1 << 4 ;
case 4 :
if ( V_55 == V_38 )
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
V_54 = F_21 ( V_50 , V_48 ) ;
V_37 = V_2 -> V_22 [ V_55 ] . V_37 ;
if ( V_55 == V_36 ) {
V_21 <<= 3 ;
if ( ! V_2 -> V_22 [ ! V_55 ] . V_21 )
V_2 -> V_22 [ ! V_55 ] . V_21 = 0x3 ;
V_54 -> V_61 =
( V_62 - V_37 ) * V_59 ;
} else {
if ( ! V_2 -> V_22 [ ! V_55 ] . V_21 )
V_2 -> V_22 [ ! V_55 ] . V_21 = ( 0x3 << 3 ) ;
V_54 -> V_61 = V_37 * V_59 ;
}
if ( V_2 -> V_22 [ V_55 ] . V_21 &&
V_2 -> V_22 [ V_55 ] . V_21 != V_21 )
V_2 -> V_63 = true ;
V_2 -> V_22 [ V_55 ] . V_21 = V_21 ;
return 0 ;
}
static int F_22 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_14 ( V_50 ) ;
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
static int F_23 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_14 ( V_50 ) ;
int V_64 ;
F_24 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_6 ) ;
F_1 ( V_2 , V_15 , 0x00 ) ;
V_64 = F_26 ( V_2 -> V_6 , V_2 -> V_41 , F_12 ,
0 , L_21 , ( void * ) V_2 ) ;
F_27 ( V_2 -> V_6 ) ;
if ( V_64 ) {
F_28 ( V_2 -> V_6 , L_22 ) ;
F_29 ( V_2 -> V_6 ) ;
}
V_2 -> V_22 [ V_36 ] . V_37 = 2 ;
V_2 -> V_22 [ V_38 ] . V_37 =
V_65 - 3 ;
return V_64 ;
}
static int F_30 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_14 ( V_50 ) ;
F_29 ( V_2 -> V_6 ) ;
return 0 ;
}
void F_31 ( struct V_66 * V_67 ,
T_4 V_68 , T_4 V_69 )
{
struct V_1 * V_2 = F_14 ( V_67 -> V_70 ) ;
V_2 -> V_31 = F_32 ( V_68 ) | F_33 ( V_69 ) ;
}
static int F_34 ( struct V_71 * V_72 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 ;
V_2 = F_35 ( & V_72 -> V_6 , sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
F_36 ( V_72 , V_2 ) ;
F_37 ( & V_2 -> V_51 ) ;
V_74 = F_38 ( V_72 , V_77 , L_23 ) ;
if ( V_74 == NULL )
return - V_76 ;
V_2 -> V_54 [ 0 ] . V_78 = V_74 -> V_79 + V_16 ;
V_2 -> V_54 [ 1 ] . V_78 = V_74 -> V_79 + V_17 ;
V_74 = F_38 ( V_72 , V_80 , L_24 ) ;
if ( ! V_74 )
return - V_81 ;
V_2 -> V_82 [ 0 ] = V_74 -> V_79 ;
V_2 -> V_54 [ 0 ] . V_83 = & V_2 -> V_82 [ 0 ] ;
V_74 = F_38 ( V_72 , V_80 , L_25 ) ;
if ( ! V_74 )
return - V_81 ;
V_2 -> V_82 [ 1 ] = V_74 -> V_79 ;
V_2 -> V_54 [ 1 ] . V_83 = & V_2 -> V_82 [ 1 ] ;
V_74 = F_38 ( V_72 , V_77 , L_26 ) ;
if ( V_74 == NULL )
return - V_76 ;
V_2 -> V_5 = F_39 ( & V_72 -> V_6 , V_74 ) ;
if ( F_40 ( V_2 -> V_5 ) )
return F_41 ( V_2 -> V_5 ) ;
V_2 -> V_41 = F_42 ( V_72 , 0 ) ;
if ( V_2 -> V_41 < 0 )
return V_2 -> V_41 ;
V_2 -> V_6 = & V_72 -> V_6 ;
return F_43 ( & V_72 -> V_6 , & V_84 ,
& V_85 , 1 ) ;
}
static int F_44 ( struct V_71 * V_72 )
{
F_45 ( & V_72 -> V_6 ) ;
return 0 ;
}
