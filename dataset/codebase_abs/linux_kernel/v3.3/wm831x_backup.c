static int F_1 ( struct V_1 * V_1 ,
enum V_2 V_3 ,
union V_4 * V_5 )
{
int V_6 ;
V_6 = F_2 ( V_1 , V_3 ) ;
if ( V_6 >= 0 )
V_5 -> V_7 = V_6 ;
return V_6 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_8 * V_8 = V_1 -> V_9 -> V_10 ;
struct V_11 * V_12 ;
int V_6 , V_13 ;
if ( ! V_8 || ! V_8 -> V_14 ) {
F_4 ( V_1 -> V_9 ,
L_1 ) ;
return;
}
V_12 = V_8 -> V_14 ;
V_13 = 0 ;
if ( V_12 -> V_15 )
V_13 |= V_16 | V_17 ;
if ( V_12 -> V_18 )
V_13 |= V_19 ;
switch ( V_12 -> V_20 ) {
case 2500 :
break;
case 3100 :
V_13 |= V_21 ;
break;
default:
F_5 ( V_1 -> V_9 , L_2 ,
V_12 -> V_20 ) ;
}
switch ( V_12 -> V_22 ) {
case 100 :
break;
case 200 :
V_13 |= 1 ;
break;
case 300 :
V_13 |= 2 ;
break;
case 400 :
V_13 |= 3 ;
break;
default:
F_5 ( V_1 -> V_9 , L_3 ,
V_12 -> V_22 ) ;
}
V_6 = F_6 ( V_1 ) ;
if ( V_6 != 0 ) {
F_5 ( V_1 -> V_9 , L_4 , V_6 ) ;
return;
}
V_6 = F_7 ( V_1 , V_23 ,
V_24 |
V_25 |
V_26 |
V_27 |
V_28 ,
V_13 ) ;
if ( V_6 != 0 )
F_5 ( V_1 -> V_9 ,
L_5 , V_6 ) ;
F_8 ( V_1 ) ;
}
static int F_9 ( struct V_29 * V_30 ,
enum V_31 V_32 ,
union V_4 * V_5 )
{
struct V_33 * V_34 = F_10 ( V_30 -> V_9 -> V_35 ) ;
struct V_1 * V_1 = V_34 -> V_1 ;
int V_6 = 0 ;
V_6 = F_11 ( V_1 , V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_32 ) {
case V_36 :
if ( V_6 & V_37 )
V_5 -> V_7 = V_38 ;
else
V_5 -> V_7 = V_39 ;
break;
case V_40 :
V_6 = F_1 ( V_1 , V_41 ,
V_5 ) ;
break;
case V_42 :
if ( V_6 & V_37 )
V_5 -> V_7 = 1 ;
else
V_5 -> V_7 = 0 ;
break;
default:
V_6 = - V_43 ;
break;
}
return V_6 ;
}
static T_1 int F_12 ( struct V_44 * V_45 )
{
struct V_1 * V_1 = F_10 ( V_45 -> V_9 . V_35 ) ;
struct V_8 * V_8 = V_1 -> V_9 -> V_10 ;
struct V_33 * V_34 ;
struct V_29 * V_14 ;
int V_6 ;
V_34 = F_13 ( sizeof( struct V_33 ) , V_46 ) ;
if ( V_34 == NULL )
return - V_47 ;
V_34 -> V_1 = V_1 ;
F_14 ( V_45 , V_34 ) ;
V_14 = & V_34 -> V_14 ;
F_3 ( V_1 ) ;
if ( V_8 && V_8 -> V_48 )
snprintf ( V_34 -> V_49 , sizeof( V_34 -> V_49 ) ,
L_6 , V_8 -> V_48 ) ;
else
snprintf ( V_34 -> V_49 , sizeof( V_34 -> V_49 ) ,
L_7 ) ;
V_14 -> V_49 = V_34 -> V_49 ;
V_14 -> type = V_50 ;
V_14 -> V_51 = V_52 ;
V_14 -> V_53 = F_15 ( V_52 ) ;
V_14 -> V_54 = F_9 ;
V_6 = F_16 ( & V_45 -> V_9 , V_14 ) ;
if ( V_6 )
goto V_55;
return V_6 ;
V_55:
F_17 ( V_34 ) ;
return V_6 ;
}
static T_2 int F_18 ( struct V_44 * V_45 )
{
struct V_33 * V_34 = F_19 ( V_45 ) ;
F_20 ( & V_34 -> V_14 ) ;
F_17 ( V_34 -> V_14 . V_49 ) ;
F_17 ( V_34 ) ;
return 0 ;
}
