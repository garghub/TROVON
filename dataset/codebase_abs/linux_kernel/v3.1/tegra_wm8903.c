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
struct V_33 * V_34 = V_16 -> V_34 ;
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
struct V_33 * V_34 = V_16 -> V_34 ;
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
struct V_33 * V_34 = V_16 -> V_34 ;
int V_40 ;
if ( F_13 ( V_34 -> V_37 ) ) {
V_40 = F_14 ( V_34 -> V_37 , L_5 ) ;
if ( V_40 ) {
F_5 ( V_14 -> V_21 , L_6 ) ;
return V_40 ;
}
V_16 -> V_35 |= V_36 ;
F_15 ( V_34 -> V_37 , 0 ) ;
}
if ( F_13 ( V_34 -> V_39 ) ) {
V_40 = F_14 ( V_34 -> V_39 , L_7 ) ;
if ( V_40 ) {
F_5 ( V_14 -> V_21 , L_8 ) ;
return V_40 ;
}
V_16 -> V_35 |= V_38 ;
F_15 ( V_34 -> V_39 , 1 ) ;
}
if ( F_13 ( V_34 -> V_41 ) ) {
V_40 = F_14 ( V_34 -> V_41 , L_9 ) ;
if ( V_40 ) {
F_5 ( V_14 -> V_21 , L_10 ) ;
return V_40 ;
}
V_16 -> V_35 |= V_42 ;
F_15 ( V_34 -> V_41 , 0 ) ;
}
if ( F_13 ( V_34 -> V_43 ) ) {
V_40 = F_14 ( V_34 -> V_43 , L_11 ) ;
if ( V_40 ) {
F_5 ( V_14 -> V_21 , L_12 ) ;
return V_40 ;
}
V_16 -> V_35 |= V_44 ;
F_15 ( V_34 -> V_43 , 0 ) ;
}
if ( F_13 ( V_34 -> V_45 ) ) {
V_46 . V_47 = V_34 -> V_45 ;
F_16 ( V_12 , L_13 , V_48 ,
& V_49 ) ;
F_17 ( & V_49 ,
F_18 ( V_50 ) ,
V_50 ) ;
F_19 ( & V_49 ,
1 ,
& V_46 ) ;
V_16 -> V_35 |= V_51 ;
}
F_16 ( V_12 , L_14 , V_52 ,
& V_53 ) ;
F_17 ( & V_53 ,
F_18 ( V_54 ) ,
V_54 ) ;
F_20 ( V_12 , & V_53 , V_52 ,
0 ) ;
F_21 ( V_32 , L_15 ) ;
if ( ! F_22 () )
F_23 ( V_32 , L_16 ) ;
if ( ! F_24 () && ! F_25 () )
F_23 ( V_32 , L_17 ) ;
F_23 ( V_32 , L_18 ) ;
if ( ! F_26 () )
F_23 ( V_32 , L_19 ) ;
F_23 ( V_32 , L_20 ) ;
F_23 ( V_32 , L_21 ) ;
if ( F_25 () ) {
F_23 ( V_32 , L_22 ) ;
F_23 ( V_32 , L_23 ) ;
F_23 ( V_32 , L_24 ) ;
F_23 ( V_32 , L_25 ) ;
} else {
F_23 ( V_32 , L_26 ) ;
F_23 ( V_32 , L_27 ) ;
}
F_27 ( V_32 ) ;
return 0 ;
}
static T_1 int F_28 ( struct V_55 * V_56 )
{
struct V_13 * V_14 = & V_57 ;
struct V_15 * V_16 ;
struct V_33 * V_34 ;
int V_40 ;
V_34 = V_56 -> V_21 . V_58 ;
if ( ! V_34 ) {
F_5 ( & V_56 -> V_21 , L_28 ) ;
return - V_59 ;
}
V_16 = F_29 ( sizeof( struct V_15 ) , V_60 ) ;
if ( ! V_16 ) {
F_5 ( & V_56 -> V_21 , L_29 ) ;
return - V_61 ;
}
V_16 -> V_34 = V_34 ;
V_40 = F_30 ( & V_16 -> V_20 , & V_56 -> V_21 ) ;
if ( V_40 )
goto V_62;
V_14 -> V_21 = & V_56 -> V_21 ;
F_31 ( V_56 , V_14 ) ;
F_32 ( V_14 , V_16 ) ;
if ( F_22 () ) {
V_14 -> V_63 = V_64 ;
V_14 -> V_65 = F_18 ( V_64 ) ;
} else if ( F_24 () ) {
V_14 -> V_63 = V_66 ;
V_14 -> V_65 = F_18 ( V_66 ) ;
} else if ( F_26 () ) {
V_14 -> V_63 = V_67 ;
V_14 -> V_65 = F_18 ( V_67 ) ;
} else {
V_14 -> V_63 = V_68 ;
V_14 -> V_65 = F_18 ( V_68 ) ;
}
V_40 = F_33 ( V_14 ) ;
if ( V_40 ) {
F_5 ( & V_56 -> V_21 , L_30 ,
V_40 ) ;
goto V_69;
}
return 0 ;
V_69:
F_34 ( & V_16 -> V_20 ) ;
V_62:
F_35 ( V_16 ) ;
return V_40 ;
}
static int T_2 F_36 ( struct V_55 * V_56 )
{
struct V_13 * V_14 = F_37 ( V_56 ) ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
struct V_33 * V_34 = V_16 -> V_34 ;
if ( V_16 -> V_35 & V_51 )
F_38 ( & V_49 ,
1 ,
& V_46 ) ;
if ( V_16 -> V_35 & V_44 )
F_39 ( V_34 -> V_43 ) ;
if ( V_16 -> V_35 & V_42 )
F_39 ( V_34 -> V_41 ) ;
if ( V_16 -> V_35 & V_38 )
F_39 ( V_34 -> V_39 ) ;
if ( V_16 -> V_35 & V_36 )
F_39 ( V_34 -> V_37 ) ;
V_16 -> V_35 = 0 ;
F_40 ( V_14 ) ;
F_34 ( & V_16 -> V_20 ) ;
F_35 ( V_16 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_70 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_70 ) ;
}
