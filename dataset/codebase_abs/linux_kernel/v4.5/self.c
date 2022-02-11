static int F_1 ( struct V_1 * V_1 , char T_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
char V_10 [ V_11 ] ;
if ( ! V_8 )
return - V_12 ;
sprintf ( V_10 , L_1 , V_8 ) ;
return F_3 ( V_2 , V_3 , V_10 ) ;
}
static const char * F_4 ( struct V_1 * V_1 ,
struct V_13 * V_13 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_13 -> V_16 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
char * V_17 ;
if ( ! V_8 )
return F_5 ( - V_12 ) ;
V_17 = F_6 ( 12 , V_1 ? V_18 : V_19 ) ;
if ( F_7 ( ! V_17 ) )
return V_1 ? F_5 ( - V_20 ) : F_5 ( - V_21 ) ;
sprintf ( V_17 , L_1 , V_8 ) ;
F_8 ( V_15 , V_22 , V_17 ) ;
return V_17 ;
}
int F_9 ( struct V_23 * V_24 )
{
struct V_13 * V_25 = F_10 ( V_24 -> V_26 ) ;
struct V_4 * V_5 = V_24 -> V_7 ;
struct V_1 * V_27 ;
F_11 ( V_25 ) ;
V_27 = F_12 ( V_24 -> V_26 , L_2 ) ;
if ( V_27 ) {
struct V_13 * V_13 = F_13 ( V_24 ) ;
if ( V_13 ) {
V_13 -> V_28 = V_29 ;
V_13 -> V_30 = V_13 -> V_31 = V_13 -> V_32 = V_33 ;
V_13 -> V_34 = V_35 | V_36 ;
V_13 -> V_37 = V_38 ;
V_13 -> V_39 = V_40 ;
V_13 -> V_41 = & V_42 ;
F_14 ( V_27 , V_13 ) ;
} else {
F_15 ( V_27 ) ;
V_27 = F_5 ( - V_20 ) ;
}
} else {
V_27 = F_5 ( - V_20 ) ;
}
F_16 ( V_25 ) ;
if ( F_17 ( V_27 ) ) {
F_18 ( L_3 ) ;
return F_19 ( V_27 ) ;
}
V_5 -> V_43 = V_27 ;
return 0 ;
}
void T_3 F_20 ( void )
{
F_21 ( & V_29 ) ;
}
