static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
int V_5 = 0 ;
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
if ( F_2 ( & V_2 -> V_9 , V_10 ) ) {
V_4 = F_3 ( V_11 ) ;
if ( ! V_4 )
return - V_12 ;
if ( V_2 -> V_6 == V_7 ) {
V_4 -> V_13 = L_1 ;
V_4 -> V_14 = V_15 ;
} else {
V_4 -> V_13 = L_2 ;
V_4 -> V_14 = V_16 ;
}
V_4 -> V_17 = V_18 ;
V_4 -> V_19 = V_20 ;
if ( F_2 ( & V_2 -> V_9 , V_21 ) &&
F_2 ( & V_2 -> V_9 , V_22 ) ) {
V_4 -> V_23 =
V_24 ;
V_4 -> V_25 =
V_24 ;
} else {
V_4 -> V_23 =
V_26 ;
V_4 -> V_25 =
V_26 ;
}
V_4 -> V_27 = 1 ;
V_4 -> V_28 = F_4 ( V_29 ,
V_30 ) ;
} else if ( F_2 ( & V_2 -> V_9 , V_31 ) ) {
V_4 = F_3 ( V_32 ) ;
if ( ! V_4 )
return - V_12 ;
if ( V_2 -> V_6 == V_7 ) {
V_4 -> V_13 = L_3 ;
V_4 -> V_14 = V_33 ;
} else {
V_4 -> V_13 = L_4 ;
V_4 -> V_14 = V_34 ;
}
V_4 -> V_17 = V_35 ;
V_4 -> V_19 = V_36 ;
V_4 -> V_23 = V_37 ;
V_4 -> V_25 = V_37 ;
V_4 -> V_27 = 0 ;
V_4 -> V_28 = F_4 ( V_38 ,
V_39 ) ;
} else if ( F_2 ( & V_2 -> V_9 , V_40 ) ) {
V_4 = F_3 ( V_32 ) ;
if ( ! V_4 )
return - V_12 ;
if ( V_2 -> V_6 == V_7 ) {
V_4 -> V_13 = L_5 ;
V_4 -> V_14 = V_41 ;
} else {
V_4 -> V_13 = L_6 ;
V_4 -> V_14 = V_42 ;
}
V_4 -> V_17 = V_43 ;
V_4 -> V_19 = V_36 ;
V_4 -> V_23 = V_37 ;
V_4 -> V_25 = V_37 ;
V_4 -> V_27 = 0 ;
V_4 -> V_28 = F_4 ( V_38 ,
V_44 ) ;
}
break;
}
if ( ! V_4 )
return - V_45 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_46 = 1 ;
F_5 ( V_2 , & V_4 -> V_47 ) ;
V_2 -> V_48 = V_4 ;
V_5 = F_6 ( V_4 ) ;
if ( V_5 ) {
F_7 ( V_4 -> V_28 ) ;
V_2 -> V_48 = NULL ;
F_8 ( V_4 ) ;
}
return V_5 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_48 ;
struct V_49 * V_50 ;
if ( V_4 ) {
V_50 = V_4 -> V_28 ;
F_10 ( V_4 ) ;
F_7 ( V_50 ) ;
}
}
int T_1 F_11 ( void )
{
return F_12 ( & V_51 , V_52 , L_7 ) ;
}
void T_2 F_13 ( void )
{
F_14 ( & V_51 ) ;
}
