static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
static F_2 ( V_5 , V_6 ,
V_7 ) ;
T_2 V_8 , V_9 , V_10 ;
T_3 V_11 ;
T_2 V_12 ;
bool V_13 = false ;
bool V_14 = false ;
V_8 = F_3 ( & V_4 -> V_15 -> V_8 ) ;
V_9 = F_3 ( & V_4 -> V_15 -> V_9 ) ;
V_10 = F_3 ( & V_4 -> V_15 -> V_10 ) ;
V_11 = F_3 ( & V_4 -> V_15 -> V_16 ) ;
V_11 |= ( ( T_3 ) ( F_3 ( & V_4 -> V_15 -> V_17 ) &
V_18 ) ) << 32 ;
if ( ! F_4 ( & V_5 ) )
goto V_19;
switch ( V_4 -> V_20 -> V_21 ) {
case V_22 :
if ( V_9 & V_23 ) {
if ( V_9 & V_24 )
V_13 = true ;
V_12 = ( V_9 & V_25 ) >>
V_26 ;
V_14 = true ;
}
break;
case V_27 :
if ( V_8 & V_28 ) {
V_12 = ( V_9 & V_29 ) >>
V_30 ;
V_14 = true ;
}
break;
}
F_5 ( V_4 -> V_31 , L_1 ,
V_8 , V_9 , V_10 ) ;
if ( V_8 & V_32 ) {
if ( V_13 )
F_5 ( V_4 -> V_31 , L_2 ) ;
else
F_5 ( V_4 -> V_31 , L_3 ) ;
}
if ( V_8 & V_33 )
F_5 ( V_4 -> V_31 , L_4 ) ;
if ( V_8 & V_34 )
F_5 ( V_4 -> V_31 , L_5 ) ;
if ( V_8 & V_35 )
F_5 ( V_4 -> V_31 , L_6 ) ;
if ( V_14 ) {
F_5 ( V_4 -> V_31 , L_7 ,
V_11 , V_12 ) ;
}
V_19:
F_6 ( V_8 , & V_4 -> V_15 -> V_8 ) ;
return V_8 ? V_36 : V_37 ;
}
static int F_7 ( struct V_38 * V_39 )
{
struct V_3 * V_4 ;
struct V_40 * V_41 ;
const struct V_42 * V_43 ;
T_2 V_44 ;
int V_45 , V_1 ;
V_43 = F_8 ( V_46 , & V_39 -> V_31 ) ;
if ( F_9 ( ! V_43 ) )
return - V_47 ;
V_4 = F_10 ( & V_39 -> V_31 , sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_41 = F_11 ( V_39 , V_50 , 0 ) ;
if ( ! V_41 ) {
F_12 ( & V_39 -> V_31 , L_8 , V_51 ) ;
return - V_52 ;
}
V_4 -> V_53 = F_13 ( & V_39 -> V_31 , V_41 ) ;
if ( F_14 ( V_4 -> V_53 ) ) {
F_12 ( & V_39 -> V_31 , L_9 , V_51 ) ;
return F_15 ( V_4 -> V_53 ) ;
}
V_4 -> V_31 = & V_39 -> V_31 ;
V_4 -> V_20 = V_43 -> V_54 ;
V_4 -> V_15 = V_4 -> V_53 + V_4 -> V_20 -> V_55 ;
if ( V_4 -> V_20 -> V_56 ) {
T_2 V_57 = F_3 ( V_4 -> V_53 + V_58 ) ;
if ( ( V_57 & V_59 ) == V_60 )
V_4 -> V_61 = true ;
}
F_16 ( & V_39 -> V_31 , V_4 ) ;
V_1 = F_17 ( V_39 , 0 ) ;
if ( ! V_1 ) {
F_12 ( & V_39 -> V_31 , L_10 , V_51 ) ;
return - V_52 ;
}
V_45 = F_18 ( & V_39 -> V_31 , V_1 , F_1 , 0 , V_39 -> V_62 , V_4 ) ;
if ( V_45 ) {
F_12 ( & V_39 -> V_31 , L_11 , V_51 ) ;
return V_45 ;
}
V_44 = V_32 | V_33 ;
if ( V_4 -> V_61 )
V_44 |= V_34 | V_35 ;
switch ( V_4 -> V_20 -> V_21 ) {
case V_22 :
F_6 ( V_44 , & V_4 -> V_15 -> V_63 ) ;
break;
case V_27 :
F_6 ( 0 , & V_4 -> V_15 -> V_63 ) ;
F_6 ( V_44 , & V_4 -> V_15 -> V_44 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_38 * V_39 )
{
struct V_3 * V_4 = F_20 ( & V_39 -> V_31 ) ;
switch ( V_4 -> V_20 -> V_21 ) {
case V_22 :
F_6 ( 0 , & V_4 -> V_15 -> V_63 ) ;
break;
case V_27 :
F_6 ( 0 , & V_4 -> V_15 -> V_44 ) ;
break;
}
return 0 ;
}
