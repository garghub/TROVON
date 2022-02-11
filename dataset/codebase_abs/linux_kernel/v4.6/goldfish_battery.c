static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 = 0 ;
switch ( V_4 ) {
case V_10 :
V_6 -> V_11 = F_3 ( V_8 , V_12 ) ;
break;
default:
V_9 = - V_13 ;
break;
}
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 = 0 ;
switch ( V_4 ) {
case V_14 :
V_6 -> V_11 = F_3 ( V_8 , V_15 ) ;
break;
case V_16 :
V_6 -> V_11 = F_3 ( V_8 , V_17 ) ;
break;
case V_18 :
V_6 -> V_11 = F_3 ( V_8 , V_19 ) ;
break;
case V_20 :
V_6 -> V_11 = V_21 ;
break;
case V_22 :
V_6 -> V_11 = F_3 ( V_8 , V_23 ) ;
break;
default:
V_9 = - V_13 ;
break;
}
return V_9 ;
}
static T_1 F_5 ( int V_24 , void * V_25 )
{
unsigned long V_26 ;
struct V_7 * V_8 = V_25 ;
T_2 V_27 ;
F_6 ( & V_8 -> V_28 , V_26 ) ;
V_27 = F_3 ( V_8 , V_29 ) ;
V_27 &= V_30 ;
if ( V_27 & V_31 )
F_7 ( V_8 -> V_32 ) ;
if ( V_27 & V_33 )
F_7 ( V_8 -> V_34 ) ;
F_8 ( & V_8 -> V_28 , V_26 ) ;
return V_27 ? V_35 : V_36 ;
}
static int F_9 ( struct V_37 * V_38 )
{
int V_9 ;
struct V_39 * V_40 ;
struct V_7 * V_8 ;
struct V_41 V_42 = {} ;
V_8 = F_10 ( & V_38 -> V_43 , sizeof( * V_8 ) , V_44 ) ;
if ( V_8 == NULL )
return - V_45 ;
F_11 ( & V_8 -> V_28 ) ;
V_40 = F_12 ( V_38 , V_46 , 0 ) ;
if ( V_40 == NULL ) {
F_13 ( & V_38 -> V_43 , L_1 ) ;
return - V_47 ;
}
V_8 -> V_48 = F_14 ( & V_38 -> V_43 , V_40 -> V_49 , F_15 ( V_40 ) ) ;
if ( V_8 -> V_48 == NULL ) {
F_13 ( & V_38 -> V_43 , L_2 ) ;
return - V_45 ;
}
V_8 -> V_24 = F_16 ( V_38 , 0 ) ;
if ( V_8 -> V_24 < 0 ) {
F_13 ( & V_38 -> V_43 , L_3 ) ;
return - V_47 ;
}
V_9 = F_17 ( & V_38 -> V_43 , V_8 -> V_24 , F_5 ,
V_50 , V_38 -> V_51 , V_8 ) ;
if ( V_9 )
return V_9 ;
V_42 . V_52 = V_8 ;
V_8 -> V_34 = F_18 ( & V_38 -> V_43 , & V_53 , & V_42 ) ;
if ( F_19 ( V_8 -> V_34 ) )
return F_20 ( V_8 -> V_34 ) ;
V_8 -> V_32 = F_18 ( & V_38 -> V_43 , & V_54 ,
& V_42 ) ;
if ( F_19 ( V_8 -> V_32 ) ) {
F_21 ( V_8 -> V_34 ) ;
return F_20 ( V_8 -> V_32 ) ;
}
F_22 ( V_38 , V_8 ) ;
V_55 = V_8 ;
F_23 ( V_8 , V_56 , V_30 ) ;
return 0 ;
}
static int F_24 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = F_25 ( V_38 ) ;
F_21 ( V_8 -> V_32 ) ;
F_21 ( V_8 -> V_34 ) ;
V_55 = NULL ;
return 0 ;
}
