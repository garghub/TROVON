static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_9 ) ;
int V_10 = 0 ;
switch ( V_4 ) {
case V_11 :
V_6 -> V_12 = F_3 ( V_8 , V_13 ) ;
break;
default:
V_10 = - V_14 ;
break;
}
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_15 ) ;
int V_10 = 0 ;
switch ( V_4 ) {
case V_16 :
V_6 -> V_12 = F_3 ( V_8 , V_17 ) ;
break;
case V_18 :
V_6 -> V_12 = F_3 ( V_8 , V_19 ) ;
break;
case V_20 :
V_6 -> V_12 = F_3 ( V_8 , V_21 ) ;
break;
case V_22 :
V_6 -> V_12 = V_23 ;
break;
case V_24 :
V_6 -> V_12 = F_3 ( V_8 , V_25 ) ;
break;
default:
V_10 = - V_14 ;
break;
}
return V_10 ;
}
static T_1 F_5 ( int V_26 , void * V_27 )
{
unsigned long V_28 ;
struct V_7 * V_8 = V_27 ;
T_2 V_29 ;
F_6 ( & V_8 -> V_30 , V_28 ) ;
V_29 = F_3 ( V_8 , V_31 ) ;
V_29 &= V_32 ;
if ( V_29 & V_33 )
F_7 ( & V_8 -> V_15 ) ;
if ( V_29 & V_34 )
F_7 ( & V_8 -> V_9 ) ;
F_8 ( & V_8 -> V_30 , V_28 ) ;
return V_29 ? V_35 : V_36 ;
}
static int F_9 ( struct V_37 * V_38 )
{
int V_10 ;
struct V_39 * V_40 ;
struct V_7 * V_8 ;
V_8 = F_10 ( & V_38 -> V_41 , sizeof( * V_8 ) , V_42 ) ;
if ( V_8 == NULL )
return - V_43 ;
F_11 ( & V_8 -> V_30 ) ;
V_8 -> V_15 . V_44 = V_45 ;
V_8 -> V_15 . V_46 = F_12 ( V_45 ) ;
V_8 -> V_15 . V_47 = F_4 ;
V_8 -> V_15 . V_48 = L_1 ;
V_8 -> V_15 . type = V_49 ;
V_8 -> V_9 . V_44 = V_50 ;
V_8 -> V_9 . V_46 = F_12 ( V_50 ) ;
V_8 -> V_9 . V_47 = F_1 ;
V_8 -> V_9 . V_48 = L_2 ;
V_8 -> V_9 . type = V_51 ;
V_40 = F_13 ( V_38 , V_52 , 0 ) ;
if ( V_40 == NULL ) {
F_14 ( & V_38 -> V_41 , L_3 ) ;
return - V_53 ;
}
V_8 -> V_54 = F_15 ( & V_38 -> V_41 , V_40 -> V_55 , F_16 ( V_40 ) ) ;
if ( V_8 -> V_54 == NULL ) {
F_14 ( & V_38 -> V_41 , L_4 ) ;
return - V_43 ;
}
V_8 -> V_26 = F_17 ( V_38 , 0 ) ;
if ( V_8 -> V_26 < 0 ) {
F_14 ( & V_38 -> V_41 , L_5 ) ;
return - V_53 ;
}
V_10 = F_18 ( & V_38 -> V_41 , V_8 -> V_26 , F_5 ,
V_56 , V_38 -> V_48 , V_8 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( & V_38 -> V_41 , & V_8 -> V_9 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( & V_38 -> V_41 , & V_8 -> V_15 ) ;
if ( V_10 ) {
F_20 ( & V_8 -> V_9 ) ;
return V_10 ;
}
F_21 ( V_38 , V_8 ) ;
V_57 = V_8 ;
F_22 ( V_8 , V_58 , V_32 ) ;
return 0 ;
}
static int F_23 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = F_24 ( V_38 ) ;
F_20 ( & V_8 -> V_15 ) ;
F_20 ( & V_8 -> V_9 ) ;
V_57 = NULL ;
return 0 ;
}
