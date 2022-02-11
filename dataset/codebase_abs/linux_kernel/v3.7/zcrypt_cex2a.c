static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
int V_5 = 0 ;
switch ( V_2 -> V_6 ) {
case V_7 :
V_4 = F_2 ( V_8 ) ;
if ( ! V_4 )
return - V_9 ;
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = L_1 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = 1 ;
V_4 -> V_18 = V_19 ;
V_4 -> V_20 = V_16 ;
break;
case V_21 :
V_4 = F_2 ( V_22 ) ;
if ( ! V_4 )
return - V_9 ;
V_4 -> V_10 = V_23 ;
V_4 -> V_12 = L_2 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_16 ;
V_4 -> V_20 = V_16 ;
if ( F_3 ( & V_2 -> V_24 , V_25 ) &&
F_3 ( & V_2 -> V_24 , V_26 ) ) {
V_4 -> V_15 = V_27 ;
V_4 -> V_20 = V_27 ;
}
V_4 -> V_17 = 1 ;
V_4 -> V_18 = V_28 ;
break;
}
if ( ! V_4 )
return - V_29 ;
V_4 -> V_30 = F_4 ( V_31 ,
V_32 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_33 = 1 ;
V_2 -> V_34 = & V_4 -> V_34 ;
V_2 -> V_35 = V_4 ;
V_5 = F_5 ( V_4 ) ;
if ( V_5 ) {
V_2 -> V_35 = NULL ;
F_6 ( V_4 -> V_30 ) ;
F_7 ( V_4 ) ;
}
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_35 ;
struct V_36 * V_37 = V_4 -> V_30 ;
F_9 ( V_4 ) ;
F_6 ( V_37 ) ;
}
int T_1 F_10 ( void )
{
return F_11 ( & V_38 , V_39 , L_3 ) ;
}
void T_2 F_12 ( void )
{
F_13 ( & V_38 ) ;
}
