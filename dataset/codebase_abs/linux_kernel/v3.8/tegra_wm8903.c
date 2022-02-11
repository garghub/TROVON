static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_16 , V_17 ;
int V_18 ;
V_16 = F_3 ( V_4 ) ;
switch ( V_16 ) {
case 64000 :
case 88200 :
case 96000 :
V_17 = 128 * V_16 ;
break;
default:
V_17 = 256 * V_16 ;
break;
}
while ( V_17 < 6000000 )
V_17 *= 2 ;
V_18 = F_4 ( & V_15 -> V_19 , V_16 , V_17 ) ;
if ( V_18 < 0 ) {
F_5 ( V_13 -> V_20 , L_1 ) ;
return V_18 ;
}
V_18 = F_6 ( V_9 , 0 , V_17 ,
V_21 ) ;
if ( V_18 < 0 ) {
F_5 ( V_13 -> V_20 , L_2 ) ;
return V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_22 * V_23 ,
struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_28 = V_23 -> V_28 ;
struct V_12 * V_13 = V_28 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
struct V_29 * V_30 = & V_15 -> V_30 ;
if ( ! F_8 ( V_30 -> V_31 ) )
return 0 ;
F_9 ( V_30 -> V_31 ,
F_10 ( V_26 ) ) ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_28 = V_23 -> V_28 ;
struct V_12 * V_13 = V_28 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
struct V_29 * V_30 = & V_15 -> V_30 ;
if ( ! F_8 ( V_30 -> V_32 ) )
return 0 ;
F_9 ( V_30 -> V_32 ,
! F_10 ( V_26 ) ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_27 * V_28 = & V_11 -> V_28 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
struct V_29 * V_30 = & V_15 -> V_30 ;
if ( F_8 ( V_30 -> V_33 ) ) {
V_34 . V_35 = V_30 -> V_33 ;
F_13 ( V_11 , L_3 , V_36 ,
& V_37 ) ;
F_14 ( & V_37 ,
F_15 ( V_38 ) ,
V_38 ) ;
F_16 ( & V_37 ,
1 ,
& V_34 ) ;
}
F_13 ( V_11 , L_4 , V_39 ,
& V_40 ) ;
F_14 ( & V_40 ,
F_15 ( V_41 ) ,
V_41 ) ;
F_17 ( V_11 , & V_40 , V_39 ,
0 ) ;
F_18 ( V_28 , L_5 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = & ( V_13 -> V_6 [ 0 ] ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
F_17 ( V_11 , NULL , 0 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_20 . V_46 ;
struct V_12 * V_13 = & V_47 ;
struct V_14 * V_15 ;
struct V_29 * V_30 ;
int V_48 ;
if ( ! V_43 -> V_20 . V_49 && ! V_43 -> V_20 . V_46 ) {
F_5 ( & V_43 -> V_20 , L_6 ) ;
return - V_50 ;
}
V_15 = F_21 ( & V_43 -> V_20 , sizeof( struct V_14 ) ,
V_51 ) ;
if ( ! V_15 ) {
F_5 ( & V_43 -> V_20 , L_7 ) ;
V_48 = - V_52 ;
goto V_18;
}
V_30 = & V_15 -> V_30 ;
V_13 -> V_20 = & V_43 -> V_20 ;
F_22 ( V_43 , V_13 ) ;
F_23 ( V_13 , V_15 ) ;
if ( V_43 -> V_20 . V_49 ) {
memcpy ( V_30 , V_13 -> V_20 -> V_49 , sizeof( * V_30 ) ) ;
} else if ( V_45 ) {
V_30 -> V_31 = F_24 ( V_45 ,
L_8 , 0 ) ;
if ( V_30 -> V_31 == - V_53 )
return - V_53 ;
V_30 -> V_32 = F_24 ( V_45 ,
L_9 , 0 ) ;
if ( V_30 -> V_32 == - V_53 )
return - V_53 ;
V_30 -> V_33 = F_24 ( V_45 ,
L_10 , 0 ) ;
if ( V_30 -> V_33 == - V_53 )
return - V_53 ;
V_30 -> V_54 = F_24 ( V_45 ,
L_11 , 0 ) ;
if ( V_30 -> V_54 == - V_53 )
return - V_53 ;
V_30 -> V_55 = F_24 ( V_45 ,
L_12 , 0 ) ;
if ( V_30 -> V_55 == - V_53 )
return - V_53 ;
}
if ( V_45 ) {
V_48 = F_25 ( V_13 , L_13 ) ;
if ( V_48 )
goto V_18;
V_48 = F_26 ( V_13 ,
L_14 ) ;
if ( V_48 )
goto V_18;
V_56 . V_57 = NULL ;
V_56 . V_58 = F_27 ( V_45 ,
L_15 , 0 ) ;
if ( ! V_56 . V_58 ) {
F_5 ( & V_43 -> V_20 ,
L_16 ) ;
V_48 = - V_50 ;
goto V_18;
}
V_56 . V_59 = NULL ;
V_56 . V_60 = F_27 ( V_45 ,
L_17 , 0 ) ;
if ( ! V_56 . V_60 ) {
F_5 ( & V_43 -> V_20 ,
L_18 ) ;
V_48 = - V_50 ;
goto V_18;
}
V_56 . V_61 = NULL ;
V_56 . V_62 =
V_56 . V_60 ;
} else {
V_13 -> V_63 = V_64 ;
V_13 -> V_65 = F_15 ( V_64 ) ;
}
if ( F_8 ( V_30 -> V_31 ) ) {
V_48 = F_28 ( & V_43 -> V_20 , V_30 -> V_31 ,
V_66 , L_19 ) ;
if ( V_48 ) {
F_5 ( V_13 -> V_20 , L_20 ) ;
return V_48 ;
}
}
if ( F_8 ( V_30 -> V_32 ) ) {
V_48 = F_28 ( & V_43 -> V_20 , V_30 -> V_32 ,
V_67 , L_21 ) ;
if ( V_48 ) {
F_5 ( V_13 -> V_20 , L_22 ) ;
return V_48 ;
}
}
if ( F_8 ( V_30 -> V_54 ) ) {
V_48 = F_28 ( & V_43 -> V_20 , V_30 -> V_54 ,
V_66 , L_23 ) ;
if ( V_48 ) {
F_5 ( V_13 -> V_20 , L_24 ) ;
return V_48 ;
}
}
if ( F_8 ( V_30 -> V_55 ) ) {
V_48 = F_28 ( & V_43 -> V_20 , V_30 -> V_55 ,
V_66 , L_25 ) ;
if ( V_48 ) {
F_5 ( V_13 -> V_20 , L_26 ) ;
return V_48 ;
}
}
V_48 = F_29 ( & V_15 -> V_19 , & V_43 -> V_20 ) ;
if ( V_48 )
goto V_18;
V_48 = F_30 ( V_13 ) ;
if ( V_48 ) {
F_5 ( & V_43 -> V_20 , L_27 ,
V_48 ) ;
goto V_68;
}
return 0 ;
V_68:
F_31 ( & V_15 -> V_19 ) ;
V_18:
return V_48 ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_12 * V_13 = F_33 ( V_43 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
F_34 ( & V_37 , 1 ,
& V_34 ) ;
F_35 ( V_13 ) ;
F_31 ( & V_15 -> V_19 ) ;
return 0 ;
}
