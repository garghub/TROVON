static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_14 , V_15 ;
int V_16 ;
V_14 = F_3 ( V_4 ) ;
switch ( V_14 ) {
case 64000 :
case 88200 :
case 96000 :
V_15 = 128 * V_14 ;
break;
default:
V_15 = 256 * V_14 ;
break;
}
while ( V_15 < 6000000 )
V_15 *= 2 ;
V_16 = F_4 ( & V_13 -> V_17 , V_14 , V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_1 ) ;
return V_16 ;
}
V_16 = F_6 ( V_9 , 0 , V_15 ,
V_19 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_20 * V_21 ,
struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 = V_21 -> V_26 ;
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( ! F_8 ( V_13 -> V_27 ) )
return 0 ;
F_9 ( V_13 -> V_27 ,
F_10 ( V_24 ) ) ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 = V_21 -> V_26 ;
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( ! F_8 ( V_13 -> V_28 ) )
return 0 ;
F_9 ( V_13 -> V_28 ,
! F_10 ( V_24 ) ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_29 * V_30 = V_9 -> V_30 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( F_8 ( V_13 -> V_31 ) ) {
V_32 . V_33 = V_13 -> V_31 ;
F_13 ( V_6 -> V_11 , L_3 ,
V_34 , & V_35 ,
V_36 ,
F_14 ( V_36 ) ) ;
F_15 ( & V_35 ,
1 ,
& V_32 ) ;
}
F_13 ( V_6 -> V_11 , L_4 , V_37 ,
& V_38 ,
V_39 ,
F_14 ( V_39 ) ) ;
F_16 ( V_30 , & V_38 , V_37 ,
0 ) ;
F_17 ( & V_11 -> V_26 , L_5 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_5 * V_6 =
F_19 ( V_11 , V_11 -> V_40 [ 0 ] . V_41 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_29 * V_30 = V_9 -> V_30 ;
F_16 ( V_30 , NULL , 0 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_18 . V_46 ;
struct V_10 * V_11 = & V_47 ;
struct V_12 * V_13 ;
int V_48 ;
V_13 = F_21 ( & V_43 -> V_18 , sizeof( struct V_12 ) ,
V_49 ) ;
if ( ! V_13 )
return - V_50 ;
V_11 -> V_18 = & V_43 -> V_18 ;
F_22 ( V_11 , V_13 ) ;
V_13 -> V_27 = F_23 ( V_45 , L_6 ,
0 ) ;
if ( V_13 -> V_27 == - V_51 )
return - V_51 ;
if ( F_8 ( V_13 -> V_27 ) ) {
V_48 = F_24 ( & V_43 -> V_18 , V_13 -> V_27 ,
V_52 , L_7 ) ;
if ( V_48 ) {
F_5 ( V_11 -> V_18 , L_8 ) ;
return V_48 ;
}
}
V_13 -> V_28 = F_23 ( V_45 , L_9 ,
0 ) ;
if ( V_13 -> V_28 == - V_51 )
return - V_51 ;
if ( F_8 ( V_13 -> V_28 ) ) {
V_48 = F_24 ( & V_43 -> V_18 , V_13 -> V_28 ,
V_53 , L_10 ) ;
if ( V_48 ) {
F_5 ( V_11 -> V_18 , L_11 ) ;
return V_48 ;
}
}
V_13 -> V_31 = F_23 ( V_45 , L_12 , 0 ) ;
if ( V_13 -> V_31 == - V_51 )
return - V_51 ;
V_13 -> V_54 = F_23 ( V_45 ,
L_13 , 0 ) ;
if ( V_13 -> V_54 == - V_51 )
return - V_51 ;
if ( F_8 ( V_13 -> V_54 ) ) {
V_48 = F_24 ( & V_43 -> V_18 ,
V_13 -> V_54 ,
V_52 , L_14 ) ;
if ( V_48 ) {
F_5 ( V_11 -> V_18 , L_15 ) ;
return V_48 ;
}
}
V_13 -> V_55 = F_23 ( V_45 ,
L_16 , 0 ) ;
if ( V_13 -> V_55 == - V_51 )
return - V_51 ;
if ( F_8 ( V_13 -> V_55 ) ) {
V_48 = F_24 ( & V_43 -> V_18 ,
V_13 -> V_55 ,
V_52 , L_17 ) ;
if ( V_48 ) {
F_5 ( V_11 -> V_18 , L_18 ) ;
return V_48 ;
}
}
V_48 = F_25 ( V_11 , L_19 ) ;
if ( V_48 )
goto V_16;
V_48 = F_26 ( V_11 , L_20 ) ;
if ( V_48 )
goto V_16;
V_56 . V_57 = F_27 ( V_45 ,
L_21 , 0 ) ;
if ( ! V_56 . V_57 ) {
F_5 ( & V_43 -> V_18 ,
L_22 ) ;
V_48 = - V_58 ;
goto V_16;
}
V_56 . V_59 = F_27 ( V_45 ,
L_23 , 0 ) ;
if ( ! V_56 . V_59 ) {
F_5 ( & V_43 -> V_18 ,
L_24 ) ;
V_48 = - V_58 ;
goto V_16;
}
V_56 . V_60 = V_56 . V_59 ;
V_48 = F_28 ( & V_13 -> V_17 , & V_43 -> V_18 ) ;
if ( V_48 )
goto V_16;
V_48 = F_29 ( V_11 ) ;
if ( V_48 ) {
F_5 ( & V_43 -> V_18 , L_25 ,
V_48 ) ;
goto V_61;
}
return 0 ;
V_61:
F_30 ( & V_13 -> V_17 ) ;
V_16:
return V_48 ;
}
static int F_31 ( struct V_42 * V_43 )
{
struct V_10 * V_11 = F_32 ( V_43 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_33 ( V_11 ) ;
F_30 ( & V_13 -> V_17 ) ;
return 0 ;
}
