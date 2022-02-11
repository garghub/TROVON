static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) / 1000 ;
}
static void F_3 ( struct V_4 * V_5 , char V_6 [] ,
T_2 * V_7 , T_2 * V_8 , T_1 * V_9 )
{
struct V_10 V_11 = { V_12 } ;
T_3 V_13 = F_4 ( & V_5 -> V_2 ) ;
union V_14 * V_15 ;
if ( F_5 ( V_16 ) )
return;
if ( F_6 ( F_7 ( V_13 , V_6 , NULL , & V_11 ) ) )
return;
V_15 = (union V_14 * ) V_11 . V_17 ;
if ( V_15 -> type == V_18 && V_15 -> V_19 . V_20 == 3 ) {
const union V_14 * V_21 = V_15 -> V_19 . V_22 ;
* V_7 = ( T_2 ) V_21 [ 0 ] . integer . V_23 ;
* V_8 = ( T_2 ) V_21 [ 1 ] . integer . V_23 ;
if ( V_9 )
* V_9 = ( T_1 ) V_21 [ 2 ] . integer . V_23 ;
}
F_8 ( V_11 . V_17 ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
const struct V_24 * V_25 ;
V_2 -> V_26 . V_27 = - 1 ;
V_2 -> V_28 = 32 ;
V_2 -> V_29 = 32 ;
F_3 ( V_5 , L_1 , & V_2 -> V_30 , & V_2 -> V_31 , NULL ) ;
F_3 ( V_5 , L_2 , & V_2 -> V_32 , & V_2 -> V_33 ,
& V_2 -> V_34 ) ;
V_25 = F_11 ( V_5 -> V_2 . V_35 -> V_36 , & V_5 -> V_2 ) ;
if ( V_25 && V_25 -> V_37 )
V_2 -> V_38 |= ( T_1 ) V_25 -> V_37 ;
return 0 ;
}
static inline int F_9 ( struct V_4 * V_5 )
{
return - V_39 ;
}
static int F_12 ( struct V_1 * V_40 , bool V_41 )
{
if ( F_13 ( V_40 -> V_3 ) )
return F_14 ( V_40 -> V_3 ) ;
if ( V_41 )
return F_15 ( V_40 -> V_3 ) ;
F_16 ( V_40 -> V_3 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_42 * V_43 = F_18 ( & V_5 -> V_2 ) ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_48 , V_49 ;
T_1 V_50 , V_51 = 0 ;
V_48 = F_19 ( V_5 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_2 = F_20 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_47 = F_21 ( V_5 , V_54 , 0 ) ;
V_2 -> V_55 = F_22 ( & V_5 -> V_2 , V_47 ) ;
if ( F_13 ( V_2 -> V_55 ) )
return F_14 ( V_2 -> V_55 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_48 = V_48 ;
F_23 ( V_5 , V_2 ) ;
V_50 = 400000 ;
if ( V_43 ) {
V_50 = V_43 -> V_56 ;
} else {
F_24 ( & V_5 -> V_2 , L_3 ,
& V_51 ) ;
F_24 ( & V_5 -> V_2 , L_4 ,
& V_2 -> V_57 ) ;
F_24 ( & V_5 -> V_2 , L_5 ,
& V_2 -> V_58 ) ;
F_24 ( & V_5 -> V_2 , L_6 ,
& V_50 ) ;
}
if ( F_25 ( & V_5 -> V_2 ) )
F_9 ( V_5 ) ;
if ( V_50 != 100000 && V_50 != 400000 ) {
F_26 ( & V_5 -> V_2 , L_7 ) ;
return - V_59 ;
}
V_49 = F_27 ( V_2 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_60 =
V_61 |
V_62 |
V_63 |
V_64 |
V_65 |
V_66 ;
if ( V_50 == 100000 )
V_2 -> V_67 = V_68 | V_69 |
V_70 | V_71 ;
else
V_2 -> V_67 = V_68 | V_69 |
V_70 | V_72 ;
V_2 -> V_3 = F_28 ( & V_5 -> V_2 , NULL ) ;
if ( ! F_12 ( V_2 , true ) ) {
V_2 -> V_73 = F_1 ;
if ( ! V_2 -> V_34 && V_51 )
V_2 -> V_34 = F_29 (
( V_74 ) V_2 -> V_73 ( V_2 ) * V_51 + 500000 ,
1000000 ) ;
}
if ( ! V_2 -> V_28 ) {
T_1 V_75 = F_30 ( V_2 ) ;
V_2 -> V_28 = ( ( V_75 >> 16 ) & 0xff ) + 1 ;
V_2 -> V_29 = ( ( V_75 >> 8 ) & 0xff ) + 1 ;
V_2 -> V_26 . V_27 = V_5 -> V_25 ;
}
V_45 = & V_2 -> V_26 ;
V_45 -> V_76 = V_77 ;
V_45 -> V_78 = V_79 ;
F_31 ( & V_45 -> V_2 , F_32 ( & V_5 -> V_2 ) ) ;
V_45 -> V_2 . V_80 = V_5 -> V_2 . V_80 ;
if ( V_2 -> V_81 ) {
F_33 ( & V_5 -> V_2 ) ;
} else {
F_34 ( & V_5 -> V_2 , 1000 ) ;
F_35 ( & V_5 -> V_2 ) ;
F_36 ( & V_5 -> V_2 ) ;
F_37 ( & V_5 -> V_2 ) ;
}
V_49 = F_38 ( V_2 ) ;
if ( V_49 && ! V_2 -> V_81 )
F_39 ( & V_5 -> V_2 ) ;
return V_49 ;
}
static int F_40 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
F_41 ( & V_5 -> V_2 ) ;
F_42 ( & V_2 -> V_26 ) ;
F_43 ( V_2 ) ;
F_44 ( & V_5 -> V_2 ) ;
F_45 ( & V_5 -> V_2 ) ;
if ( ! V_2 -> V_81 )
F_39 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_82 * V_2 )
{
return F_47 ( V_2 ) ;
}
static void F_48 ( struct V_82 * V_2 )
{
if ( V_2 -> V_83 . V_84 )
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_82 * V_2 )
{
struct V_4 * V_5 = F_51 ( V_2 ) ;
struct V_1 * V_40 = F_10 ( V_5 ) ;
F_43 ( V_40 ) ;
F_12 ( V_40 , false ) ;
return 0 ;
}
static int F_52 ( struct V_82 * V_2 )
{
struct V_4 * V_5 = F_51 ( V_2 ) ;
struct V_1 * V_40 = F_10 ( V_5 ) ;
F_12 ( V_40 , true ) ;
if ( ! V_40 -> V_81 )
F_53 ( V_40 ) ;
return 0 ;
}
static int T_4 F_54 ( void )
{
return F_55 ( & V_85 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_85 ) ;
}
