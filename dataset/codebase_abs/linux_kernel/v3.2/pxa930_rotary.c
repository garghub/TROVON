static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 | V_6 , V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 & ~ V_6 , V_2 -> V_4 + V_5 ) ;
}
static T_2 F_4 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 , V_12 , V_13 ;
V_11 = F_2 ( V_2 -> V_4 + V_14 ) & 0xf ;
F_1 ( V_2 ) ;
V_12 = V_11 - V_2 -> V_15 ;
if ( V_12 == 0 )
return V_16 ;
V_2 -> V_15 = V_11 ;
if ( V_10 -> V_17 && V_10 -> V_18 ) {
V_13 = ( V_12 > 0 ) ? V_10 -> V_17 : V_10 -> V_18 ;
F_5 ( V_2 -> V_19 , V_13 , 1 ) ;
F_6 ( V_2 -> V_19 ) ;
F_5 ( V_2 -> V_19 , V_13 , 0 ) ;
} else
F_7 ( V_2 -> V_19 , V_10 -> V_20 , V_12 ) ;
F_6 ( V_2 -> V_19 ) ;
return V_16 ;
}
static int F_8 ( struct V_19 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_19 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
F_1 ( V_2 ) ;
}
static int T_3 F_11 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = V_23 -> V_21 . V_24 ;
struct V_1 * V_2 ;
struct V_19 * V_19 ;
struct V_25 * V_26 ;
int V_7 ;
int V_27 ;
V_7 = F_12 ( V_23 , 0 ) ;
if ( V_7 < 0 ) {
F_13 ( & V_23 -> V_21 , L_1 ) ;
return - V_28 ;
}
V_26 = F_14 ( V_23 , V_29 , 0 ) ;
if ( ! V_26 ) {
F_13 ( & V_23 -> V_21 , L_2 ) ;
return - V_28 ;
}
if ( ! V_10 ) {
F_13 ( & V_23 -> V_21 , L_3 ) ;
return - V_30 ;
}
V_2 = F_15 ( sizeof( struct V_1 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
V_2 -> V_4 = F_16 ( V_26 -> V_33 , F_17 ( V_26 ) ) ;
if ( V_2 -> V_4 == NULL ) {
F_13 ( & V_23 -> V_21 , L_4 ) ;
V_27 = - V_28 ;
goto V_34;
}
V_2 -> V_10 = V_10 ;
F_18 ( V_23 , V_2 ) ;
V_19 = F_19 () ;
if ( ! V_19 ) {
F_13 ( & V_23 -> V_21 , L_5 ) ;
V_27 = - V_32 ;
goto V_35;
}
V_19 -> V_36 = V_23 -> V_36 ;
V_19 -> V_37 . V_38 = V_39 ;
V_19 -> V_40 = F_8 ;
V_19 -> V_41 = F_10 ;
V_19 -> V_21 . V_42 = & V_23 -> V_21 ;
if ( V_10 -> V_17 && V_10 -> V_18 ) {
F_20 ( V_10 -> V_17 , V_19 -> V_43 ) ;
F_20 ( V_10 -> V_18 , V_19 -> V_43 ) ;
F_20 ( V_44 , V_19 -> V_45 ) ;
} else {
F_20 ( V_10 -> V_20 , V_19 -> V_46 ) ;
F_20 ( V_47 , V_19 -> V_45 ) ;
}
V_2 -> V_19 = V_19 ;
F_21 ( V_19 , V_2 ) ;
V_27 = F_22 ( V_7 , F_4 , 0 ,
L_6 , V_2 ) ;
if ( V_27 ) {
F_13 ( & V_23 -> V_21 , L_7 ) ;
goto V_48;
}
V_27 = F_23 ( V_19 ) ;
if ( V_27 ) {
F_13 ( & V_23 -> V_21 , L_8 ) ;
goto V_49;
}
return 0 ;
V_49:
F_24 ( V_7 , V_2 ) ;
V_48:
F_25 ( V_19 ) ;
V_35:
F_26 ( V_2 -> V_4 ) ;
V_34:
F_27 ( V_2 ) ;
return V_27 ;
}
static int T_4 F_28 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_29 ( V_23 ) ;
F_24 ( F_12 ( V_23 , 0 ) , V_2 ) ;
F_30 ( V_2 -> V_19 ) ;
F_26 ( V_2 -> V_4 ) ;
F_18 ( V_23 , NULL ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int T_5 F_31 ( void )
{
return F_32 ( & V_50 ) ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_50 ) ;
}
