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
static const char * F_4 ( struct V_1 * V_1 , void * * V_13 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
char * V_14 ;
if ( ! V_8 )
return F_5 ( - V_12 ) ;
V_14 = F_6 ( 12 , V_15 ) ;
if ( ! V_14 )
return F_5 ( - V_16 ) ;
sprintf ( V_14 , L_1 , V_8 ) ;
return * V_13 = V_14 ;
}
int F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_8 ( V_18 -> V_21 ) ;
struct V_4 * V_5 = V_18 -> V_7 ;
struct V_1 * V_22 ;
F_9 ( & V_20 -> V_23 ) ;
V_22 = F_10 ( V_18 -> V_21 , L_2 ) ;
if ( V_22 ) {
struct V_19 * V_19 = F_11 ( V_18 ) ;
if ( V_19 ) {
V_19 -> V_24 = V_25 ;
V_19 -> V_26 = V_19 -> V_27 = V_19 -> V_28 = V_29 ;
V_19 -> V_30 = V_31 | V_32 ;
V_19 -> V_33 = V_34 ;
V_19 -> V_35 = V_36 ;
V_19 -> V_37 = & V_38 ;
F_12 ( V_22 , V_19 ) ;
} else {
F_13 ( V_22 ) ;
V_22 = F_5 ( - V_16 ) ;
}
} else {
V_22 = F_5 ( - V_16 ) ;
}
F_14 ( & V_20 -> V_23 ) ;
if ( F_15 ( V_22 ) ) {
F_16 ( L_3 ) ;
return F_17 ( V_22 ) ;
}
V_5 -> V_39 = V_22 ;
return 0 ;
}
void T_3 F_18 ( void )
{
F_19 ( & V_25 ) ;
}
