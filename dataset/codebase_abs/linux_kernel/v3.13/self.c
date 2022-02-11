static int F_1 ( struct V_1 * V_1 , char T_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
char V_10 [ V_11 ] ;
if ( ! V_8 )
return - V_12 ;
sprintf ( V_10 , L_1 , V_8 ) ;
return F_3 ( V_1 , V_2 , V_3 , V_10 ) ;
}
static void * F_4 ( struct V_1 * V_1 , struct V_13 * V_14 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
char * V_15 = F_5 ( - V_12 ) ;
if ( V_8 ) {
V_15 = F_6 ( 12 , V_16 ) ;
if ( ! V_15 )
V_15 = F_5 ( - V_17 ) ;
else
sprintf ( V_15 , L_1 , V_8 ) ;
}
F_7 ( V_14 , V_15 ) ;
return NULL ;
}
int F_8 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 -> V_23 ;
struct V_4 * V_5 = V_19 -> V_7 ;
struct V_1 * V_24 ;
F_9 ( & V_21 -> V_25 ) ;
V_24 = F_10 ( V_19 -> V_22 , L_2 ) ;
if ( V_24 ) {
struct V_20 * V_20 = F_11 ( V_19 ) ;
if ( V_20 ) {
V_20 -> V_26 = V_27 ;
V_20 -> V_28 = V_20 -> V_29 = V_20 -> V_30 = V_31 ;
V_20 -> V_32 = V_33 | V_34 ;
V_20 -> V_35 = V_36 ;
V_20 -> V_37 = V_38 ;
V_20 -> V_39 = & V_40 ;
F_12 ( V_24 , V_20 ) ;
} else {
F_13 ( V_24 ) ;
V_24 = F_5 ( - V_17 ) ;
}
} else {
V_24 = F_5 ( - V_17 ) ;
}
F_14 ( & V_21 -> V_25 ) ;
if ( F_15 ( V_24 ) ) {
F_16 ( L_3 ) ;
return F_17 ( V_24 ) ;
}
V_5 -> V_41 = V_24 ;
return 0 ;
}
void T_3 F_18 ( void )
{
F_19 ( & V_27 ) ;
}
