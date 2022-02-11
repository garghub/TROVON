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
if ( V_14 ) {
F_5 ( V_4 -> V_31 , L_5 ,
V_11 , V_12 ) ;
}
V_19:
F_6 ( V_8 , & V_4 -> V_15 -> V_8 ) ;
return V_8 ? V_34 : V_35 ;
}
static int F_7 ( struct V_36 * V_37 )
{
struct V_3 * V_4 ;
struct V_38 * V_39 ;
const struct V_40 * V_41 ;
int V_42 , V_1 ;
V_41 = F_8 ( V_43 , & V_37 -> V_31 ) ;
if ( F_9 ( ! V_41 ) )
return - V_44 ;
V_4 = F_10 ( & V_37 -> V_31 , sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return - V_46 ;
V_39 = F_11 ( V_37 , V_47 , 0 ) ;
if ( ! V_39 ) {
F_12 ( & V_37 -> V_31 , L_6 , V_48 ) ;
return - V_49 ;
}
V_4 -> V_50 = F_13 ( & V_37 -> V_31 , V_39 ) ;
if ( F_14 ( V_4 -> V_50 ) ) {
F_12 ( & V_37 -> V_31 , L_7 , V_48 ) ;
return F_15 ( V_4 -> V_50 ) ;
}
V_4 -> V_31 = & V_37 -> V_31 ;
V_4 -> V_20 = V_41 -> V_51 ;
V_4 -> V_15 = V_4 -> V_50 + V_4 -> V_20 -> V_52 ;
F_16 ( & V_37 -> V_31 , V_4 ) ;
V_1 = F_17 ( V_37 , 0 ) ;
if ( ! V_1 ) {
F_12 ( & V_37 -> V_31 , L_8 , V_48 ) ;
return - V_49 ;
}
V_42 = F_18 ( & V_37 -> V_31 , V_1 , F_1 , 0 , V_37 -> V_53 , V_4 ) ;
if ( V_42 ) {
F_12 ( & V_37 -> V_31 , L_9 , V_48 ) ;
return V_42 ;
}
switch ( V_4 -> V_20 -> V_21 ) {
case V_22 :
F_6 ( V_32 | V_33 , & V_4 -> V_15 -> V_54 ) ;
break;
case V_27 :
F_6 ( 0 , & V_4 -> V_15 -> V_54 ) ;
F_6 ( V_32 | V_33 , & V_4 -> V_15 -> V_55 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = F_20 ( & V_37 -> V_31 ) ;
switch ( V_4 -> V_20 -> V_21 ) {
case V_22 :
F_6 ( 0 , & V_4 -> V_15 -> V_54 ) ;
break;
case V_27 :
F_6 ( 0 , & V_4 -> V_15 -> V_55 ) ;
break;
}
return 0 ;
}
