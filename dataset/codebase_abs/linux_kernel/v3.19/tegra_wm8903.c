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
struct V_25 * V_26 = & V_30 -> V_26 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( F_8 ( V_13 -> V_31 ) ) {
V_32 . V_33 = V_13 -> V_31 ;
F_13 ( V_30 , L_3 , V_34 ,
& V_35 ) ;
F_14 ( & V_35 ,
F_15 ( V_36 ) ,
V_36 ) ;
F_16 ( & V_35 ,
1 ,
& V_32 ) ;
}
F_13 ( V_30 , L_4 , V_37 ,
& V_38 ) ;
F_14 ( & V_38 ,
F_15 ( V_39 ) ,
V_39 ) ;
F_17 ( V_30 , & V_38 , V_37 ,
0 ) ;
F_18 ( V_26 , L_5 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = & ( V_11 -> V_6 [ 0 ] ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_29 * V_30 = V_9 -> V_30 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( F_8 ( V_13 -> V_31 ) ) {
F_20 ( & V_35 , 1 ,
& V_32 ) ;
}
F_17 ( V_30 , NULL , 0 , 0 ) ;
return 0 ;
}
static int F_21 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_18 . V_44 ;
struct V_10 * V_11 = & V_45 ;
struct V_12 * V_13 ;
int V_46 ;
V_13 = F_22 ( & V_41 -> V_18 , sizeof( struct V_12 ) ,
V_47 ) ;
if ( ! V_13 ) {
F_5 ( & V_41 -> V_18 , L_6 ) ;
return - V_48 ;
}
V_11 -> V_18 = & V_41 -> V_18 ;
F_23 ( V_41 , V_11 ) ;
F_24 ( V_11 , V_13 ) ;
V_13 -> V_27 = F_25 ( V_43 , L_7 ,
0 ) ;
if ( V_13 -> V_27 == - V_49 )
return - V_49 ;
if ( F_8 ( V_13 -> V_27 ) ) {
V_46 = F_26 ( & V_41 -> V_18 , V_13 -> V_27 ,
V_50 , L_8 ) ;
if ( V_46 ) {
F_5 ( V_11 -> V_18 , L_9 ) ;
return V_46 ;
}
}
V_13 -> V_28 = F_25 ( V_43 , L_10 ,
0 ) ;
if ( V_13 -> V_28 == - V_49 )
return - V_49 ;
if ( F_8 ( V_13 -> V_28 ) ) {
V_46 = F_26 ( & V_41 -> V_18 , V_13 -> V_28 ,
V_51 , L_11 ) ;
if ( V_46 ) {
F_5 ( V_11 -> V_18 , L_12 ) ;
return V_46 ;
}
}
V_13 -> V_31 = F_25 ( V_43 , L_13 , 0 ) ;
if ( V_13 -> V_31 == - V_49 )
return - V_49 ;
V_13 -> V_52 = F_25 ( V_43 ,
L_14 , 0 ) ;
if ( V_13 -> V_52 == - V_49 )
return - V_49 ;
if ( F_8 ( V_13 -> V_52 ) ) {
V_46 = F_26 ( & V_41 -> V_18 ,
V_13 -> V_52 ,
V_50 , L_15 ) ;
if ( V_46 ) {
F_5 ( V_11 -> V_18 , L_16 ) ;
return V_46 ;
}
}
V_13 -> V_53 = F_25 ( V_43 ,
L_17 , 0 ) ;
if ( V_13 -> V_53 == - V_49 )
return - V_49 ;
if ( F_8 ( V_13 -> V_53 ) ) {
V_46 = F_26 ( & V_41 -> V_18 ,
V_13 -> V_53 ,
V_50 , L_18 ) ;
if ( V_46 ) {
F_5 ( V_11 -> V_18 , L_19 ) ;
return V_46 ;
}
}
V_46 = F_27 ( V_11 , L_20 ) ;
if ( V_46 )
goto V_16;
V_46 = F_28 ( V_11 , L_21 ) ;
if ( V_46 )
goto V_16;
V_54 . V_55 = F_29 ( V_43 ,
L_22 , 0 ) ;
if ( ! V_54 . V_55 ) {
F_5 ( & V_41 -> V_18 ,
L_23 ) ;
V_46 = - V_56 ;
goto V_16;
}
V_54 . V_57 = F_29 ( V_43 ,
L_24 , 0 ) ;
if ( ! V_54 . V_57 ) {
F_5 ( & V_41 -> V_18 ,
L_25 ) ;
V_46 = - V_56 ;
goto V_16;
}
V_54 . V_58 = V_54 . V_57 ;
V_46 = F_30 ( & V_13 -> V_17 , & V_41 -> V_18 ) ;
if ( V_46 )
goto V_16;
V_46 = F_31 ( V_11 ) ;
if ( V_46 ) {
F_5 ( & V_41 -> V_18 , L_26 ,
V_46 ) ;
goto V_59;
}
return 0 ;
V_59:
F_32 ( & V_13 -> V_17 ) ;
V_16:
return V_46 ;
}
static int F_33 ( struct V_40 * V_41 )
{
struct V_10 * V_11 = F_34 ( V_41 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_35 ( V_11 ) ;
F_32 ( & V_13 -> V_17 ) ;
return 0 ;
}
