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
V_2 -> V_61 = F_27 ( & V_5 -> V_2 , NULL ) ;
if ( F_13 ( V_2 -> V_61 ) ) {
if ( F_14 ( V_2 -> V_61 ) == - V_62 )
return - V_62 ;
} else {
F_28 ( V_2 -> V_61 ) ;
}
if ( V_48 ) {
V_2 -> V_63 = V_48 -> V_64 ;
} else {
F_29 ( & V_5 -> V_2 , L_5 ,
& V_56 ) ;
F_29 ( & V_5 -> V_2 , L_6 ,
& V_2 -> V_65 ) ;
F_29 ( & V_5 -> V_2 , L_7 ,
& V_2 -> V_66 ) ;
F_29 ( & V_5 -> V_2 , L_8 ,
& V_2 -> V_63 ) ;
}
V_55 = F_30 ( & V_5 -> V_2 ) ;
if ( V_55 && V_2 -> V_63 )
V_2 -> V_63 = F_31 ( V_2 -> V_63 , V_55 ) ;
else if ( V_55 || V_2 -> V_63 )
V_2 -> V_63 = F_32 ( V_2 -> V_63 , V_55 ) ;
else
V_2 -> V_63 = 400000 ;
if ( F_33 ( & V_5 -> V_2 ) )
F_9 ( V_5 ) ;
if ( V_2 -> V_63 != 100000 && V_2 -> V_63 != 400000
&& V_2 -> V_63 != 1000000 && V_2 -> V_63 != 3400000 ) {
F_34 ( & V_5 -> V_2 ,
L_9 ) ;
V_54 = - V_67 ;
goto V_68;
}
V_54 = F_35 ( V_2 ) ;
if ( V_54 )
goto V_68;
V_2 -> V_69 = V_70 | V_71 ;
V_2 -> V_72 = V_73 | V_74 |
V_75 ;
switch ( V_2 -> V_63 ) {
case 100000 :
V_2 -> V_72 |= V_76 ;
break;
case 3400000 :
V_2 -> V_72 |= V_77 ;
break;
default:
V_2 -> V_72 |= V_78 ;
}
V_2 -> V_3 = F_36 ( & V_5 -> V_2 , NULL ) ;
if ( ! F_12 ( V_2 , true ) ) {
V_2 -> V_79 = F_1 ;
if ( ! V_2 -> V_34 && V_56 )
V_2 -> V_34 = F_37 (
( V_80 ) V_2 -> V_79 ( V_2 ) * V_56 + 500000 ,
1000000 ) ;
}
F_17 ( V_2 , V_5 -> V_25 ) ;
V_50 = & V_2 -> V_26 ;
V_50 -> V_81 = V_82 ;
V_50 -> V_83 = V_84 ;
F_38 ( & V_50 -> V_2 , F_39 ( & V_5 -> V_2 ) ) ;
V_50 -> V_2 . V_85 = V_5 -> V_2 . V_85 ;
if ( V_2 -> V_86 ) {
F_40 ( & V_5 -> V_2 ) ;
} else {
F_41 ( & V_5 -> V_2 , 1000 ) ;
F_42 ( & V_5 -> V_2 ) ;
F_43 ( & V_5 -> V_2 ) ;
F_44 ( & V_5 -> V_2 ) ;
}
V_54 = F_45 ( V_2 ) ;
if ( V_54 )
goto V_87;
return V_54 ;
V_87:
if ( ! V_2 -> V_86 )
F_46 ( & V_5 -> V_2 ) ;
V_68:
if ( ! F_47 ( V_2 -> V_61 ) )
F_48 ( V_2 -> V_61 ) ;
return V_54 ;
}
static int F_49 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
F_50 ( & V_5 -> V_2 ) ;
F_51 ( & V_2 -> V_26 ) ;
F_52 ( V_2 ) ;
F_53 ( & V_5 -> V_2 ) ;
F_54 ( & V_5 -> V_2 ) ;
if ( ! V_2 -> V_86 )
F_46 ( & V_5 -> V_2 ) ;
if ( ! F_47 ( V_2 -> V_61 ) )
F_48 ( V_2 -> V_61 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_2 )
{
return F_56 ( V_2 ) ;
}
static void F_57 ( struct V_88 * V_2 )
{
if ( V_2 -> V_89 . V_90 )
F_58 ( V_2 ) ;
}
static int F_59 ( struct V_88 * V_2 )
{
struct V_4 * V_5 = F_60 ( V_2 ) ;
struct V_1 * V_44 = F_10 ( V_5 ) ;
F_52 ( V_44 ) ;
F_12 ( V_44 , false ) ;
return 0 ;
}
static int F_61 ( struct V_88 * V_2 )
{
struct V_4 * V_5 = F_60 ( V_2 ) ;
struct V_1 * V_44 = F_10 ( V_5 ) ;
F_12 ( V_44 , true ) ;
if ( ! V_44 -> V_86 )
F_62 ( V_44 ) ;
return 0 ;
}
static int T_4 F_63 ( void )
{
return F_64 ( & V_91 ) ;
}
static void T_5 F_65 ( void )
{
F_66 ( & V_91 ) ;
}
