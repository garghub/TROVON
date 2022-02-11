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
F_3 ( V_5 , L_3 , & V_2 -> V_35 , & V_2 -> V_36 , NULL ) ;
F_3 ( V_5 , L_4 , & V_2 -> V_37 , & V_2 -> V_38 , NULL ) ;
V_25 = F_11 ( V_5 -> V_2 . V_39 -> V_40 , & V_5 -> V_2 ) ;
if ( V_25 && V_25 -> V_41 )
V_2 -> V_42 |= ( T_1 ) V_25 -> V_41 ;
return 0 ;
}
static inline int F_9 ( struct V_4 * V_5 )
{
return - V_43 ;
}
static int F_12 ( struct V_1 * V_44 , bool V_45 )
{
if ( F_13 ( V_44 -> V_3 ) )
return F_14 ( V_44 -> V_3 ) ;
if ( V_45 )
return F_15 ( V_44 -> V_3 ) ;
F_16 ( V_44 -> V_3 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_46 , V_28 , V_29 ;
V_46 = F_18 ( V_2 ) ;
V_28 = ( ( V_46 >> 16 ) & 0xff ) + 1 ;
V_29 = ( ( V_46 >> 8 ) & 0xff ) + 1 ;
if ( ! V_2 -> V_28 ) {
V_2 -> V_28 = V_28 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_26 . V_27 = V_25 ;
} else if ( V_28 >= 2 ) {
V_2 -> V_28 = F_19 ( T_1 , V_2 -> V_28 ,
V_28 ) ;
V_2 -> V_29 = F_19 ( T_1 , V_2 -> V_29 ,
V_29 ) ;
}
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_47 * V_48 = F_21 ( & V_5 -> V_2 ) ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_53 , V_54 ;
T_1 V_55 , V_56 = 0 ;
V_53 = F_22 ( V_5 , 0 ) ;
if ( V_53 < 0 )
return V_53 ;
V_2 = F_23 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_2 )
return - V_58 ;
V_52 = F_24 ( V_5 , V_59 , 0 ) ;
V_2 -> V_60 = F_25 ( & V_5 -> V_2 , V_52 ) ;
if ( F_13 ( V_2 -> V_60 ) )
return F_14 ( V_2 -> V_60 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_53 = V_53 ;
F_26 ( V_5 , V_2 ) ;
if ( V_48 ) {
V_2 -> V_61 = V_48 -> V_62 ;
} else {
F_27 ( & V_5 -> V_2 , L_5 ,
& V_56 ) ;
F_27 ( & V_5 -> V_2 , L_6 ,
& V_2 -> V_63 ) ;
F_27 ( & V_5 -> V_2 , L_7 ,
& V_2 -> V_64 ) ;
F_27 ( & V_5 -> V_2 , L_8 ,
& V_2 -> V_61 ) ;
}
V_55 = F_28 ( & V_5 -> V_2 ) ;
if ( V_55 && V_2 -> V_61 )
V_2 -> V_61 = F_29 ( V_2 -> V_61 , V_55 ) ;
else if ( V_55 || V_2 -> V_61 )
V_2 -> V_61 = F_30 ( V_2 -> V_61 , V_55 ) ;
else
V_2 -> V_61 = 400000 ;
if ( F_31 ( & V_5 -> V_2 ) )
F_9 ( V_5 ) ;
if ( V_2 -> V_61 != 100000 && V_2 -> V_61 != 400000
&& V_2 -> V_61 != 1000000 && V_2 -> V_61 != 3400000 ) {
F_32 ( & V_5 -> V_2 ,
L_9 ) ;
return - V_65 ;
}
V_54 = F_33 ( V_2 ) ;
if ( V_54 )
return V_54 ;
V_2 -> V_66 = V_67 | V_68 ;
V_2 -> V_69 = V_70 | V_71 |
V_72 ;
switch ( V_2 -> V_61 ) {
case 100000 :
V_2 -> V_69 |= V_73 ;
break;
case 3400000 :
V_2 -> V_69 |= V_74 ;
break;
default:
V_2 -> V_69 |= V_75 ;
}
V_2 -> V_3 = F_34 ( & V_5 -> V_2 , NULL ) ;
if ( ! F_12 ( V_2 , true ) ) {
V_2 -> V_76 = F_1 ;
if ( ! V_2 -> V_34 && V_56 )
V_2 -> V_34 = F_35 (
( V_77 ) V_2 -> V_76 ( V_2 ) * V_56 + 500000 ,
1000000 ) ;
}
F_17 ( V_2 , V_5 -> V_25 ) ;
V_50 = & V_2 -> V_26 ;
V_50 -> V_78 = V_79 ;
V_50 -> V_80 = V_81 ;
F_36 ( & V_50 -> V_2 , F_37 ( & V_5 -> V_2 ) ) ;
V_50 -> V_2 . V_82 = V_5 -> V_2 . V_82 ;
if ( V_2 -> V_83 ) {
F_38 ( & V_5 -> V_2 ) ;
} else {
F_39 ( & V_5 -> V_2 , 1000 ) ;
F_40 ( & V_5 -> V_2 ) ;
F_41 ( & V_5 -> V_2 ) ;
F_42 ( & V_5 -> V_2 ) ;
}
V_54 = F_43 ( V_2 ) ;
if ( V_54 && ! V_2 -> V_83 )
F_44 ( & V_5 -> V_2 ) ;
return V_54 ;
}
static int F_45 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
F_46 ( & V_5 -> V_2 ) ;
F_47 ( & V_2 -> V_26 ) ;
F_48 ( V_2 ) ;
F_49 ( & V_5 -> V_2 ) ;
F_50 ( & V_5 -> V_2 ) ;
if ( ! V_2 -> V_83 )
F_44 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_84 * V_2 )
{
return F_52 ( V_2 ) ;
}
static void F_53 ( struct V_84 * V_2 )
{
if ( V_2 -> V_85 . V_86 )
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_84 * V_2 )
{
struct V_4 * V_5 = F_56 ( V_2 ) ;
struct V_1 * V_44 = F_10 ( V_5 ) ;
F_48 ( V_44 ) ;
F_12 ( V_44 , false ) ;
return 0 ;
}
static int F_57 ( struct V_84 * V_2 )
{
struct V_4 * V_5 = F_56 ( V_2 ) ;
struct V_1 * V_44 = F_10 ( V_5 ) ;
F_12 ( V_44 , true ) ;
if ( ! V_44 -> V_83 )
F_58 ( V_44 ) ;
return 0 ;
}
static int T_4 F_59 ( void )
{
return F_60 ( & V_87 ) ;
}
static void T_5 F_61 ( void )
{
F_62 ( & V_87 ) ;
}
