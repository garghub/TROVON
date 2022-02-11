static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
int V_17 , V_18 ;
int V_19 ;
V_17 = F_3 ( V_4 ) ;
switch ( V_17 ) {
case 64000 :
case 88200 :
case 96000 :
V_18 = 128 * V_17 ;
break;
default:
V_18 = 256 * V_17 ;
break;
}
while ( V_18 < 6000000 )
V_18 *= 2 ;
V_19 = F_4 ( & V_16 -> V_20 , V_17 , V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_1 ) ;
return V_19 ;
}
V_19 = F_6 ( V_9 ,
V_22 |
V_23 |
V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_2 ) ;
return V_19 ;
}
V_19 = F_6 ( V_10 ,
V_22 |
V_23 |
V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_3 ) ;
return V_19 ;
}
V_19 = F_7 ( V_9 , 0 , V_18 ,
V_25 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_4 ) ;
return V_19 ;
}
return 0 ;
}
static int F_8 ( struct V_26 * V_27 ,
struct V_28 * V_29 , int V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_13 * V_14 = V_32 -> V_14 ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
struct V_33 * V_34 = & V_16 -> V_34 ;
if ( ! ( V_16 -> V_35 & V_36 ) )
return 0 ;
F_9 ( V_34 -> V_37 ,
F_10 ( V_30 ) ) ;
return 0 ;
}
static int F_11 ( struct V_26 * V_27 ,
struct V_28 * V_29 , int V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_13 * V_14 = V_32 -> V_14 ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
struct V_33 * V_34 = & V_16 -> V_34 ;
if ( ! ( V_16 -> V_35 & V_38 ) )
return 0 ;
F_9 ( V_34 -> V_39 ,
! F_10 ( V_30 ) ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_31 * V_32 = & V_12 -> V_32 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
struct V_33 * V_34 = & V_16 -> V_34 ;
struct V_40 * V_41 = V_14 -> V_21 -> V_42 ;
int V_43 ;
if ( V_14 -> V_21 -> V_44 ) {
memcpy ( V_34 , V_14 -> V_21 -> V_44 , sizeof( * V_34 ) ) ;
} else if ( V_41 ) {
V_34 -> V_37 = F_13 ( V_41 ,
L_5 , 0 ) ;
V_34 -> V_39 = F_13 ( V_41 ,
L_6 , 0 ) ;
V_34 -> V_45 = F_13 ( V_41 ,
L_7 , 0 ) ;
V_34 -> V_46 = F_13 ( V_41 ,
L_8 , 0 ) ;
V_34 -> V_47 = F_13 ( V_41 ,
L_9 , 0 ) ;
} else {
F_5 ( V_14 -> V_21 , L_10 ) ;
return - V_48 ;
}
if ( F_14 ( V_34 -> V_37 ) ) {
V_43 = F_15 ( V_34 -> V_37 , L_11 ) ;
if ( V_43 ) {
F_5 ( V_14 -> V_21 , L_12 ) ;
return V_43 ;
}
V_16 -> V_35 |= V_36 ;
F_16 ( V_34 -> V_37 , 0 ) ;
}
if ( F_14 ( V_34 -> V_39 ) ) {
V_43 = F_15 ( V_34 -> V_39 , L_13 ) ;
if ( V_43 ) {
F_5 ( V_14 -> V_21 , L_14 ) ;
return V_43 ;
}
V_16 -> V_35 |= V_38 ;
F_16 ( V_34 -> V_39 , 1 ) ;
}
if ( F_14 ( V_34 -> V_46 ) ) {
V_43 = F_15 ( V_34 -> V_46 , L_15 ) ;
if ( V_43 ) {
F_5 ( V_14 -> V_21 , L_16 ) ;
return V_43 ;
}
V_16 -> V_35 |= V_49 ;
F_16 ( V_34 -> V_46 , 0 ) ;
}
if ( F_14 ( V_34 -> V_47 ) ) {
V_43 = F_15 ( V_34 -> V_47 , L_17 ) ;
if ( V_43 ) {
F_5 ( V_14 -> V_21 , L_18 ) ;
return V_43 ;
}
V_16 -> V_35 |= V_50 ;
F_16 ( V_34 -> V_47 , 0 ) ;
}
if ( F_14 ( V_34 -> V_45 ) ) {
V_51 . V_52 = V_34 -> V_45 ;
F_17 ( V_12 , L_19 , V_53 ,
& V_54 ) ;
F_18 ( & V_54 ,
F_19 ( V_55 ) ,
V_55 ) ;
F_20 ( & V_54 ,
1 ,
& V_51 ) ;
V_16 -> V_35 |= V_56 ;
}
F_17 ( V_12 , L_20 , V_57 ,
& V_58 ) ;
F_18 ( & V_58 ,
F_19 ( V_59 ) ,
V_59 ) ;
F_21 ( V_12 , & V_58 , V_57 ,
0 ) ;
F_22 ( V_32 , L_21 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = & ( V_14 -> V_6 [ 0 ] ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_21 ( V_12 , NULL , 0 , 0 ) ;
return 0 ;
}
static T_1 int F_24 ( struct V_60 * V_61 )
{
struct V_13 * V_14 = & V_62 ;
struct V_15 * V_16 ;
int V_43 ;
if ( ! V_61 -> V_21 . V_44 && ! V_61 -> V_21 . V_42 ) {
F_5 ( & V_61 -> V_21 , L_10 ) ;
return - V_48 ;
}
V_16 = F_25 ( & V_61 -> V_21 , sizeof( struct V_15 ) ,
V_63 ) ;
if ( ! V_16 ) {
F_5 ( & V_61 -> V_21 , L_22 ) ;
V_43 = - V_64 ;
goto V_19;
}
V_14 -> V_21 = & V_61 -> V_21 ;
F_26 ( V_61 , V_14 ) ;
F_27 ( V_14 , V_16 ) ;
if ( V_61 -> V_21 . V_42 ) {
V_43 = F_28 ( V_14 , L_23 ) ;
if ( V_43 )
goto V_19;
V_43 = F_29 ( V_14 ,
L_24 ) ;
if ( V_43 )
goto V_19;
V_65 . V_66 = NULL ;
V_65 . V_67 = F_30 (
V_61 -> V_21 . V_42 , L_25 , 0 ) ;
if ( ! V_65 . V_67 ) {
F_5 ( & V_61 -> V_21 ,
L_26 ) ;
V_43 = - V_48 ;
goto V_19;
}
V_65 . V_68 = NULL ;
V_65 . V_69 = F_30 (
V_61 -> V_21 . V_42 , L_27 , 0 ) ;
if ( ! V_65 . V_69 ) {
F_5 ( & V_61 -> V_21 ,
L_28 ) ;
V_43 = - V_48 ;
goto V_19;
}
V_65 . V_70 = NULL ;
V_65 . V_71 =
V_65 . V_69 ;
} else {
if ( F_31 () ) {
V_14 -> V_72 = V_73 ;
V_14 -> V_74 = F_19 ( V_73 ) ;
} else if ( F_32 () ) {
V_14 -> V_72 = V_75 ;
V_14 -> V_74 = F_19 ( V_75 ) ;
} else if ( F_33 () ) {
V_14 -> V_72 = V_76 ;
V_14 -> V_74 = F_19 ( V_76 ) ;
} else {
V_14 -> V_72 = V_77 ;
V_14 -> V_74 = F_19 ( V_77 ) ;
}
}
V_43 = F_34 ( & V_16 -> V_20 , & V_61 -> V_21 ) ;
if ( V_43 )
goto V_19;
V_43 = F_35 ( V_14 ) ;
if ( V_43 ) {
F_5 ( & V_61 -> V_21 , L_29 ,
V_43 ) ;
goto V_78;
}
return 0 ;
V_78:
F_36 ( & V_16 -> V_20 ) ;
V_19:
return V_43 ;
}
static int T_2 F_37 ( struct V_60 * V_61 )
{
struct V_13 * V_14 = F_38 ( V_61 ) ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
struct V_33 * V_34 = & V_16 -> V_34 ;
if ( V_16 -> V_35 & V_56 )
F_39 ( & V_54 ,
1 ,
& V_51 ) ;
if ( V_16 -> V_35 & V_50 )
F_40 ( V_34 -> V_47 ) ;
if ( V_16 -> V_35 & V_49 )
F_40 ( V_34 -> V_46 ) ;
if ( V_16 -> V_35 & V_38 )
F_40 ( V_34 -> V_39 ) ;
if ( V_16 -> V_35 & V_36 )
F_40 ( V_34 -> V_37 ) ;
V_16 -> V_35 = 0 ;
F_41 ( V_14 ) ;
F_36 ( & V_16 -> V_20 ) ;
return 0 ;
}
