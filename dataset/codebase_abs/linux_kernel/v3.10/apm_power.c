static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
V_5 -> V_6 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 -> V_7 ) {
V_5 -> main = V_5 -> V_6 ;
return 1 ;
}
if ( ! F_3 ( V_5 -> V_6 , V_8 , & V_5 -> V_9 ) ||
! F_3 ( V_5 -> V_6 , V_10 , & V_5 -> V_9 ) ) {
if ( V_5 -> V_9 . V_11 > V_5 -> V_12 ) {
V_5 -> V_13 = V_5 -> V_6 ;
V_5 -> V_12 = V_5 -> V_9 . V_11 ;
}
} else if ( ! F_3 ( V_5 -> V_6 , V_14 , & V_5 -> V_9 ) ||
! F_3 ( V_5 -> V_6 , V_15 , & V_5 -> V_9 ) ) {
if ( V_5 -> V_9 . V_11 > V_5 -> V_16 ) {
V_5 -> V_17 = V_5 -> V_6 ;
V_5 -> V_16 = V_5 -> V_9 . V_11 ;
}
}
return 0 ;
}
static void F_4 ( void )
{
struct V_4 V_5 ;
int error ;
memset ( & V_5 , 0 , sizeof( struct V_4 ) ) ;
V_18 = NULL ;
V_5 . main = V_18 ;
error = F_5 ( V_19 , NULL , & V_5 ,
F_1 ) ;
if ( error ) {
V_18 = V_5 . main;
return;
}
if ( ( V_5 . V_17 && V_5 . V_13 ) &&
( V_5 . V_17 != V_5 . V_13 ) ) {
if ( ! F_3 ( V_5 . V_13 , V_20 ,
& V_5 . V_9 ) ) {
if ( V_5 . V_16 > V_5 . V_12 * V_5 . V_9 . V_11 )
V_18 = V_5 . V_17 ;
else
V_18 = V_5 . V_13 ;
} else if ( ! F_3 ( V_5 . V_17 , V_20 ,
& V_5 . V_9 ) ) {
if ( V_5 . V_12 > V_5 . V_16 / V_5 . V_9 . V_11 )
V_18 = V_5 . V_13 ;
else
V_18 = V_5 . V_17 ;
} else {
V_18 = V_5 . V_17 ;
}
} else if ( V_5 . V_13 ) {
V_18 = V_5 . V_13 ;
} else if ( V_5 . V_17 ) {
V_18 = V_5 . V_17 ;
} else {
V_18 = V_5 . V_6 ;
}
}
static int F_6 ( int V_21 , enum V_22 V_23 )
{
union V_24 V_9 ;
union V_24 V_25 ;
union V_24 V_26 ;
union V_24 V_27 ;
enum V_28 V_29 ;
enum V_28 V_30 ;
enum V_28 V_31 ;
enum V_28 V_32 ;
enum V_28 V_33 ;
enum V_28 V_34 ;
if ( F_7 ( V_35 , & V_27 ) ) {
if ( F_7 ( V_36 , & V_27 ) )
return - 1 ;
}
if ( ! V_27 . V_11 )
return 0 ;
switch ( V_23 ) {
case V_37 :
V_29 = V_38 ;
V_30 = V_39 ;
V_31 = V_40 ;
V_32 = V_40 ;
V_33 = V_41 ;
V_34 = V_42 ;
break;
case V_43 :
V_29 = V_44 ;
V_30 = V_45 ;
V_31 = V_46 ;
V_32 = V_40 ;
V_33 = V_47 ;
V_34 = V_48 ;
break;
case V_49 :
V_29 = V_50 ;
V_30 = V_51 ;
V_31 = V_52 ;
V_32 = V_53 ;
V_33 = V_54 ;
V_34 = V_55 ;
break;
default:
F_8 ( V_56 L_1 , V_23 ) ;
return - 1 ;
}
if ( F_9 ( V_29 , & V_9 ) ) {
if ( F_9 ( V_30 , & V_9 ) )
return - 1 ;
}
if ( F_9 ( V_31 , & V_25 ) ) {
if ( F_9 ( V_32 , & V_25 ) )
V_25 . V_11 = 0 ;
}
if ( F_9 ( V_33 , & V_26 ) ) {
if ( F_9 ( V_34 , & V_26 ) )
return - 1 ;
}
if ( V_21 == V_57 )
return ( ( V_26 . V_11 - V_9 . V_11 ) * 60L ) / V_27 . V_11 ;
else
return - ( ( V_26 . V_11 - V_25 . V_11 ) * 60L ) / V_27 . V_11 ;
}
static int F_10 ( int V_21 )
{
int time ;
time = F_6 ( V_21 , V_43 ) ;
if ( time != - 1 )
return time ;
time = F_6 ( V_21 , V_37 ) ;
if ( time != - 1 )
return time ;
time = F_6 ( V_21 , V_49 ) ;
if ( time != - 1 )
return time ;
return - 1 ;
}
static int F_11 ( enum V_22 V_23 )
{
enum V_28 V_29 , V_31 ;
enum V_28 V_30 , V_32 ;
enum V_28 V_58 , V_59 ;
union V_24 V_25 , V_9 , V_26 ;
int V_60 ;
switch ( V_23 ) {
case V_37 :
V_29 = V_38 ;
V_31 = V_40 ;
V_30 = V_39 ;
V_32 = V_61 ;
V_58 = V_42 ;
V_59 = V_41 ;
break;
case V_43 :
V_29 = V_44 ;
V_31 = V_46 ;
V_30 = V_45 ;
V_32 = V_62 ;
V_58 = V_48 ;
V_59 = V_47 ;
break;
case V_49 :
V_29 = V_50 ;
V_31 = V_52 ;
V_30 = V_51 ;
V_32 = V_53 ;
V_58 = V_55 ;
V_59 = V_54 ;
break;
default:
F_8 ( V_56 L_1 , V_23 ) ;
return - 1 ;
}
if ( F_9 ( V_29 , & V_9 ) ) {
if ( F_9 ( V_30 , & V_9 ) )
return - 1 ;
}
if ( F_9 ( V_59 , & V_26 ) ) {
if ( F_9 ( V_58 , & V_26 ) )
return - 1 ;
}
if ( F_9 ( V_31 , & V_25 ) ) {
if ( F_9 ( V_32 , & V_25 ) )
V_25 . V_11 = 0 ;
}
if ( V_9 . V_11 - V_25 . V_11 )
V_60 = ( ( V_26 . V_11 - V_25 . V_11 ) * 100L ) /
( V_9 . V_11 - V_25 . V_11 ) ;
else
return - 1 ;
if ( V_60 > 100 )
return 100 ;
else if ( V_60 < 0 )
return 0 ;
return V_60 ;
}
static void F_12 ( struct V_63 * V_64 )
{
union V_24 V_21 ;
union V_24 V_65 , V_66 , V_67 ;
F_13 ( & V_68 ) ;
F_4 () ;
if ( ! V_18 ) {
F_14 ( & V_68 ) ;
return;
}
if ( F_7 ( V_69 , & V_21 ) )
V_21 . V_11 = V_70 ;
if ( ( V_21 . V_11 == V_57 ) ||
( V_21 . V_11 == V_71 ) ||
( V_21 . V_11 == V_72 ) )
V_64 -> V_73 = V_74 ;
else
V_64 -> V_73 = V_75 ;
if ( F_7 ( V_76 , & V_65 ) == 0 ) {
V_64 -> V_77 = V_65 . V_11 ;
} else {
V_64 -> V_77 = F_11 ( V_43 ) ;
if ( V_64 -> V_77 == - 1 )
V_64 -> V_77 = F_11 ( V_37 ) ;
if ( V_64 -> V_77 == - 1 )
V_64 -> V_77 = F_11 ( V_49 ) ;
}
if ( V_21 . V_11 == V_57 ) {
V_64 -> V_78 = V_79 ;
} else {
if ( V_64 -> V_77 > 50 )
V_64 -> V_78 = V_80 ;
else if ( V_64 -> V_77 > 5 )
V_64 -> V_78 = V_81 ;
else
V_64 -> V_78 = V_82 ;
}
V_64 -> V_83 = V_64 -> V_78 ;
V_64 -> V_84 = V_85 ;
if ( V_21 . V_11 == V_57 ) {
if ( ! F_7 ( V_86 , & V_66 ) ||
! F_7 ( V_87 , & V_66 ) )
V_64 -> time = V_66 . V_11 / 60 ;
else
V_64 -> time = F_10 ( V_21 . V_11 ) ;
} else {
if ( ! F_7 ( V_88 , & V_67 ) ||
! F_7 ( V_89 , & V_67 ) )
V_64 -> time = V_67 . V_11 / 60 ;
else
V_64 -> time = F_10 ( V_21 . V_11 ) ;
}
F_14 ( & V_68 ) ;
}
static int T_1 F_15 ( void )
{
F_8 ( V_90 L_2 ) ;
V_91 = F_12 ;
return 0 ;
}
static void T_2 F_16 ( void )
{
V_91 = NULL ;
}
