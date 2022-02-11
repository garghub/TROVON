static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
V_5 -> V_6 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 -> V_7 -> V_8 ) {
V_5 -> main = V_5 -> V_6 ;
return 1 ;
}
if ( ! F_3 ( V_5 -> V_6 , V_9 , & V_5 -> V_10 ) ||
! F_3 ( V_5 -> V_6 , V_11 , & V_5 -> V_10 ) ) {
if ( V_5 -> V_10 . V_12 > V_5 -> V_13 ) {
V_5 -> V_14 = V_5 -> V_6 ;
V_5 -> V_13 = V_5 -> V_10 . V_12 ;
}
} else if ( ! F_3 ( V_5 -> V_6 , V_15 , & V_5 -> V_10 ) ||
! F_3 ( V_5 -> V_6 , V_16 , & V_5 -> V_10 ) ) {
if ( V_5 -> V_10 . V_12 > V_5 -> V_17 ) {
V_5 -> V_18 = V_5 -> V_6 ;
V_5 -> V_17 = V_5 -> V_10 . V_12 ;
}
}
return 0 ;
}
static void F_4 ( void )
{
struct V_4 V_5 ;
int error ;
memset ( & V_5 , 0 , sizeof( struct V_4 ) ) ;
V_19 = NULL ;
V_5 . main = V_19 ;
error = F_5 ( V_20 , NULL , & V_5 ,
F_1 ) ;
if ( error ) {
V_19 = V_5 . main;
return;
}
if ( ( V_5 . V_18 && V_5 . V_14 ) &&
( V_5 . V_18 != V_5 . V_14 ) ) {
if ( ! F_3 ( V_5 . V_14 , V_21 ,
& V_5 . V_10 ) ) {
if ( V_5 . V_17 > V_5 . V_13 * V_5 . V_10 . V_12 )
V_19 = V_5 . V_18 ;
else
V_19 = V_5 . V_14 ;
} else if ( ! F_3 ( V_5 . V_18 , V_21 ,
& V_5 . V_10 ) ) {
if ( V_5 . V_13 > V_5 . V_17 / V_5 . V_10 . V_12 )
V_19 = V_5 . V_14 ;
else
V_19 = V_5 . V_18 ;
} else {
V_19 = V_5 . V_18 ;
}
} else if ( V_5 . V_14 ) {
V_19 = V_5 . V_14 ;
} else if ( V_5 . V_18 ) {
V_19 = V_5 . V_18 ;
} else {
V_19 = V_5 . V_6 ;
}
}
static int F_6 ( int V_22 , enum V_23 V_24 )
{
union V_25 V_10 ;
union V_25 V_26 ;
union V_25 V_27 ;
union V_25 V_28 ;
enum V_29 V_30 ;
enum V_29 V_31 ;
enum V_29 V_32 ;
enum V_29 V_33 ;
enum V_29 V_34 ;
enum V_29 V_35 ;
if ( F_7 ( V_36 , & V_28 ) ) {
if ( F_7 ( V_37 , & V_28 ) )
return - 1 ;
}
if ( ! V_28 . V_12 )
return 0 ;
switch ( V_24 ) {
case V_38 :
V_30 = V_39 ;
V_31 = V_40 ;
V_32 = V_41 ;
V_33 = V_41 ;
V_34 = V_42 ;
V_35 = V_43 ;
break;
case V_44 :
V_30 = V_45 ;
V_31 = V_46 ;
V_32 = V_47 ;
V_33 = V_41 ;
V_34 = V_48 ;
V_35 = V_49 ;
break;
case V_50 :
V_30 = V_51 ;
V_31 = V_52 ;
V_32 = V_53 ;
V_33 = V_54 ;
V_34 = V_55 ;
V_35 = V_56 ;
break;
default:
F_8 ( V_57 L_1 , V_24 ) ;
return - 1 ;
}
if ( F_9 ( V_30 , & V_10 ) ) {
if ( F_9 ( V_31 , & V_10 ) )
return - 1 ;
}
if ( F_9 ( V_32 , & V_26 ) ) {
if ( F_9 ( V_33 , & V_26 ) )
V_26 . V_12 = 0 ;
}
if ( F_9 ( V_34 , & V_27 ) ) {
if ( F_9 ( V_35 , & V_27 ) )
return - 1 ;
}
if ( V_22 == V_58 )
return ( ( V_27 . V_12 - V_10 . V_12 ) * 60L ) / V_28 . V_12 ;
else
return - ( ( V_27 . V_12 - V_26 . V_12 ) * 60L ) / V_28 . V_12 ;
}
static int F_10 ( int V_22 )
{
int time ;
time = F_6 ( V_22 , V_44 ) ;
if ( time != - 1 )
return time ;
time = F_6 ( V_22 , V_38 ) ;
if ( time != - 1 )
return time ;
time = F_6 ( V_22 , V_50 ) ;
if ( time != - 1 )
return time ;
return - 1 ;
}
static int F_11 ( enum V_23 V_24 )
{
enum V_29 V_30 , V_32 ;
enum V_29 V_31 , V_33 ;
enum V_29 V_59 , V_60 ;
union V_25 V_26 , V_10 , V_27 ;
int V_61 ;
switch ( V_24 ) {
case V_38 :
V_30 = V_39 ;
V_32 = V_41 ;
V_31 = V_40 ;
V_33 = V_62 ;
V_59 = V_43 ;
V_60 = V_42 ;
break;
case V_44 :
V_30 = V_45 ;
V_32 = V_47 ;
V_31 = V_46 ;
V_33 = V_63 ;
V_59 = V_49 ;
V_60 = V_48 ;
break;
case V_50 :
V_30 = V_51 ;
V_32 = V_53 ;
V_31 = V_52 ;
V_33 = V_54 ;
V_59 = V_56 ;
V_60 = V_55 ;
break;
default:
F_8 ( V_57 L_1 , V_24 ) ;
return - 1 ;
}
if ( F_9 ( V_30 , & V_10 ) ) {
if ( F_9 ( V_31 , & V_10 ) )
return - 1 ;
}
if ( F_9 ( V_60 , & V_27 ) ) {
if ( F_9 ( V_59 , & V_27 ) )
return - 1 ;
}
if ( F_9 ( V_32 , & V_26 ) ) {
if ( F_9 ( V_33 , & V_26 ) )
V_26 . V_12 = 0 ;
}
if ( V_10 . V_12 - V_26 . V_12 )
V_61 = ( ( V_27 . V_12 - V_26 . V_12 ) * 100L ) /
( V_10 . V_12 - V_26 . V_12 ) ;
else
return - 1 ;
if ( V_61 > 100 )
return 100 ;
else if ( V_61 < 0 )
return 0 ;
return V_61 ;
}
static void F_12 ( struct V_64 * V_65 )
{
union V_25 V_22 ;
union V_25 V_66 , V_67 , V_68 ;
F_13 ( & V_69 ) ;
F_4 () ;
if ( ! V_19 ) {
F_14 ( & V_69 ) ;
return;
}
if ( F_7 ( V_70 , & V_22 ) )
V_22 . V_12 = V_71 ;
if ( ( V_22 . V_12 == V_58 ) ||
( V_22 . V_12 == V_72 ) ||
( V_22 . V_12 == V_73 ) )
V_65 -> V_74 = V_75 ;
else
V_65 -> V_74 = V_76 ;
if ( F_7 ( V_77 , & V_66 ) == 0 ) {
V_65 -> V_78 = V_66 . V_12 ;
} else {
V_65 -> V_78 = F_11 ( V_44 ) ;
if ( V_65 -> V_78 == - 1 )
V_65 -> V_78 = F_11 ( V_38 ) ;
if ( V_65 -> V_78 == - 1 )
V_65 -> V_78 = F_11 ( V_50 ) ;
}
if ( V_22 . V_12 == V_58 ) {
V_65 -> V_79 = V_80 ;
} else {
if ( V_65 -> V_78 > 50 )
V_65 -> V_79 = V_81 ;
else if ( V_65 -> V_78 > 5 )
V_65 -> V_79 = V_82 ;
else
V_65 -> V_79 = V_83 ;
}
V_65 -> V_84 = V_65 -> V_79 ;
V_65 -> V_85 = V_86 ;
if ( V_22 . V_12 == V_58 ) {
if ( ! F_7 ( V_87 , & V_67 ) ||
! F_7 ( V_88 , & V_67 ) )
V_65 -> time = V_67 . V_12 / 60 ;
else
V_65 -> time = F_10 ( V_22 . V_12 ) ;
} else {
if ( ! F_7 ( V_89 , & V_68 ) ||
! F_7 ( V_90 , & V_68 ) )
V_65 -> time = V_68 . V_12 / 60 ;
else
V_65 -> time = F_10 ( V_22 . V_12 ) ;
}
F_14 ( & V_69 ) ;
}
static int T_1 F_15 ( void )
{
F_8 ( V_91 L_2 ) ;
V_92 = F_12 ;
return 0 ;
}
static void T_2 F_16 ( void )
{
V_92 = NULL ;
}
