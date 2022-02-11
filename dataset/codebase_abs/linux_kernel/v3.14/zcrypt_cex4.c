static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
int V_5 = 0 ;
switch ( V_2 -> V_6 ) {
case V_7 :
if ( F_2 ( & V_2 -> V_8 , V_9 ) ) {
V_4 = F_3 ( V_10 ) ;
if ( ! V_4 )
return - V_11 ;
V_4 -> V_12 = L_1 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_16 ;
if ( F_2 ( & V_2 -> V_8 , V_17 ) &&
F_2 ( & V_2 -> V_8 , V_18 ) ) {
V_4 -> V_19 =
V_20 ;
V_4 -> V_21 =
V_20 ;
} else {
V_4 -> V_19 =
V_22 ;
V_4 -> V_21 =
V_22 ;
}
V_4 -> V_23 = 1 ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = F_4 ( V_27 ,
V_28 ) ;
} else if ( F_2 ( & V_2 -> V_8 , V_29 ) ) {
V_4 = F_3 ( V_30 ) ;
if ( ! V_4 )
return - V_11 ;
V_4 -> V_12 = L_2 ;
V_4 -> V_13 = V_31 ;
V_4 -> V_15 = V_32 ;
V_4 -> V_19 = V_33 ;
V_4 -> V_21 = V_33 ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = V_34 ;
V_4 -> V_26 = F_4 ( V_35 ,
V_36 ) ;
} else if ( F_2 ( & V_2 -> V_8 , V_37 ) ) {
V_4 = F_3 ( V_30 ) ;
if ( ! V_4 )
return - V_11 ;
V_4 -> V_12 = L_3 ;
V_4 -> V_13 = V_38 ;
V_4 -> V_15 = V_32 ;
V_4 -> V_19 = V_33 ;
V_4 -> V_21 = V_33 ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = V_34 ;
V_4 -> V_26 = F_4 ( V_35 ,
V_39 ) ;
}
break;
}
if ( ! V_4 )
return - V_40 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_41 = 1 ;
V_2 -> V_42 = & V_4 -> V_42 ;
V_2 -> V_43 = V_4 ;
V_5 = F_5 ( V_4 ) ;
if ( V_5 ) {
F_6 ( V_4 -> V_26 ) ;
V_2 -> V_43 = NULL ;
F_7 ( V_4 ) ;
}
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_43 ;
struct V_44 * V_45 ;
if ( V_4 ) {
V_45 = V_4 -> V_26 ;
F_9 ( V_4 ) ;
F_6 ( V_45 ) ;
}
}
int T_1 F_10 ( void )
{
return F_11 ( & V_46 , V_47 , L_4 ) ;
}
void T_2 F_12 ( void )
{
F_13 ( & V_46 ) ;
}
