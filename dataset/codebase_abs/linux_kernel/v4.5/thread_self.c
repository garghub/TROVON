static int F_1 ( struct V_1 * V_1 , char T_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
T_2 V_10 = F_3 ( V_9 , V_5 ) ;
char V_11 [ V_12 + 6 + V_12 ] ;
if ( ! V_10 )
return - V_13 ;
sprintf ( V_11 , L_1 , V_8 , V_10 ) ;
return F_4 ( V_2 , V_3 , V_11 ) ;
}
static const char * F_5 ( struct V_1 * V_1 ,
struct V_14 * V_14 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = V_14 -> V_17 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
T_2 V_10 = F_3 ( V_9 , V_5 ) ;
char * V_18 ;
if ( ! V_10 )
return F_6 ( - V_13 ) ;
V_18 = F_7 ( V_12 + 6 + V_12 ,
V_1 ? V_19 : V_20 ) ;
if ( F_8 ( ! V_18 ) )
return V_1 ? F_6 ( - V_21 ) : F_6 ( - V_22 ) ;
sprintf ( V_18 , L_1 , V_8 , V_10 ) ;
F_9 ( V_16 , V_23 , V_18 ) ;
return V_18 ;
}
int F_10 ( struct V_24 * V_25 )
{
struct V_14 * V_26 = F_11 ( V_25 -> V_27 ) ;
struct V_4 * V_5 = V_25 -> V_7 ;
struct V_1 * V_28 ;
F_12 ( V_26 ) ;
V_28 = F_13 ( V_25 -> V_27 , L_2 ) ;
if ( V_28 ) {
struct V_14 * V_14 = F_14 ( V_25 ) ;
if ( V_14 ) {
V_14 -> V_29 = V_30 ;
V_14 -> V_31 = V_14 -> V_32 = V_14 -> V_33 = V_34 ;
V_14 -> V_35 = V_36 | V_37 ;
V_14 -> V_38 = V_39 ;
V_14 -> V_40 = V_41 ;
V_14 -> V_42 = & V_43 ;
F_15 ( V_28 , V_14 ) ;
} else {
F_16 ( V_28 ) ;
V_28 = F_6 ( - V_21 ) ;
}
} else {
V_28 = F_6 ( - V_21 ) ;
}
F_17 ( V_26 ) ;
if ( F_18 ( V_28 ) ) {
F_19 ( L_3 ) ;
return F_20 ( V_28 ) ;
}
V_5 -> V_44 = V_28 ;
return 0 ;
}
void T_3 F_21 ( void )
{
F_22 ( & V_30 ) ;
}
