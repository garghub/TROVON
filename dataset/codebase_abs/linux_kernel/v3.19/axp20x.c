static void F_1 ( void )
{
if ( V_1 -> V_2 == V_3 )
return;
F_2 ( V_1 -> V_4 , V_5 ,
V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
const struct V_13 * V_14 ;
if ( V_10 -> V_15 ) {
V_14 = F_4 ( V_16 , V_10 ) ;
if ( ! V_14 ) {
F_5 ( V_10 , L_1 ) ;
return - V_17 ;
}
V_8 -> V_2 = ( long ) V_14 -> V_18 ;
} else {
V_12 = F_6 ( V_10 -> V_19 -> V_20 , V_10 ) ;
if ( ! V_12 || ! V_12 -> V_21 ) {
F_5 ( V_10 , L_2 ) ;
return - V_17 ;
}
V_8 -> V_2 = ( long ) V_12 -> V_21 ;
}
switch ( V_8 -> V_2 ) {
case V_22 :
case V_23 :
V_8 -> V_24 = F_7 ( V_25 ) ;
V_8 -> V_26 = V_25 ;
V_8 -> V_27 = & V_28 ;
V_8 -> V_29 = & V_30 ;
break;
case V_3 :
V_8 -> V_26 = V_31 ;
V_8 -> V_24 = F_7 ( V_31 ) ;
V_8 -> V_27 = & V_32 ;
V_8 -> V_29 = & V_33 ;
break;
default:
F_5 ( V_10 , L_3 , V_8 -> V_2 ) ;
return - V_34 ;
}
F_8 ( V_10 , L_4 ,
V_35 [ V_8 -> V_2 ] ) ;
return 0 ;
}
static int F_9 ( struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
struct V_7 * V_8 ;
int V_40 ;
V_8 = F_10 ( & V_37 -> V_10 , sizeof( * V_8 ) , V_41 ) ;
if ( ! V_8 )
return - V_42 ;
V_40 = F_3 ( V_8 , & V_37 -> V_10 ) ;
if ( V_40 )
return V_40 ;
V_8 -> V_36 = V_37 ;
V_8 -> V_10 = & V_37 -> V_10 ;
F_11 ( V_8 -> V_10 , V_8 ) ;
V_8 -> V_4 = F_12 ( V_37 , V_8 -> V_27 ) ;
if ( F_13 ( V_8 -> V_4 ) ) {
V_40 = F_14 ( V_8 -> V_4 ) ;
F_5 ( & V_37 -> V_10 , L_5 , V_40 ) ;
return V_40 ;
}
V_40 = F_15 ( V_8 -> V_4 , V_37 -> V_43 ,
V_44 | V_45 , - 1 ,
V_8 -> V_29 ,
& V_8 -> V_46 ) ;
if ( V_40 ) {
F_5 ( & V_37 -> V_10 , L_6 , V_40 ) ;
return V_40 ;
}
V_40 = F_16 ( V_8 -> V_10 , - 1 , V_8 -> V_26 ,
V_8 -> V_24 , NULL , 0 , NULL ) ;
if ( V_40 ) {
F_5 ( & V_37 -> V_10 , L_7 , V_40 ) ;
F_17 ( V_37 -> V_43 , V_8 -> V_46 ) ;
return V_40 ;
}
if ( ! V_47 ) {
V_1 = V_8 ;
V_47 = F_1 ;
}
F_8 ( & V_37 -> V_10 , L_8 ) ;
return 0 ;
}
static int F_18 ( struct V_36 * V_37 )
{
struct V_7 * V_8 = F_19 ( V_37 ) ;
if ( V_8 == V_1 ) {
V_1 = NULL ;
V_47 = NULL ;
}
F_20 ( V_8 -> V_10 ) ;
F_17 ( V_8 -> V_36 -> V_43 , V_8 -> V_46 ) ;
return 0 ;
}
