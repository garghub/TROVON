static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned short V_5 , V_6 , V_7 ;
F_2 ( V_8 , V_9 ) ;
if ( F_3 ( V_10 ) ) {
F_4 ( V_4 , V_11 , 0 ) ;
} else {
F_2 ( V_12 , V_9 ) ;
V_5 = F_3 ( V_10 ) ;
F_2 ( V_13 , V_9 ) ;
V_6 = F_3 ( V_10 ) ;
F_2 ( V_14 , V_9 ) ;
V_7 = F_3 ( V_10 ) ;
V_5 = V_15 - ( ( V_5 * 8 ) + ( ( V_7 >> 4 ) & 0xf ) ) ;
V_6 = ( V_6 * 8 ) + ( V_7 & 0xf ) ;
if ( V_16 )
V_5 = V_15 - V_5 ;
if ( V_17 )
V_6 = V_18 - V_6 ;
if ( V_5 != V_15 && V_5 != 0 ) {
F_4 ( V_4 , V_11 , 1 ) ;
F_5 ( V_4 , V_19 , V_5 ) ;
F_5 ( V_4 , V_20 , V_6 ) ;
}
}
F_6 ( V_4 ) ;
F_3 ( V_21 ) ;
return V_22 ;
}
static int F_7 ( struct V_3 * V_23 )
{
F_2 ( V_24 , V_25 ) ;
return 0 ;
}
static void F_8 ( struct V_3 * V_23 )
{
F_2 ( V_26 , V_25 ) ;
F_9 ( V_27 ) ;
}
static int F_10 ( struct V_28 * V_23 , unsigned int V_29 )
{
struct V_3 * V_4 ;
int V_30 = - V_31 ;
if ( ! F_11 ( V_21 , 1 , L_1 ) ) {
F_12 ( V_32 L_2 ,
V_21 ) ;
goto V_33;
}
if ( ! F_11 ( V_25 , 1 , L_1 ) ) {
F_12 ( V_32 L_2 ,
V_25 ) ;
goto V_34;
}
if ( ! F_11 ( V_9 , 2 , L_1 ) ) {
F_12 ( V_32 L_2 ,
V_9 ) ;
goto V_35;
}
V_4 = F_13 () ;
if ( ! V_4 ) {
F_12 ( V_32 L_3 ) ;
V_30 = - V_36 ;
goto V_37;
}
V_4 -> V_38 = L_4 ;
V_4 -> V_29 . V_39 = V_40 ;
V_4 -> V_41 [ 0 ] = F_14 ( V_42 ) | F_14 ( V_43 ) ;
V_4 -> V_44 [ F_15 ( V_11 ) ] = F_14 ( V_11 ) ;
F_16 ( V_4 , V_19 , 0 , V_15 , 0 , 0 ) ;
F_16 ( V_4 , V_20 , 0 , V_18 , 0 , 0 ) ;
V_4 -> V_45 = F_7 ;
V_4 -> V_46 = F_8 ;
V_30 = F_17 ( V_27 , F_1 , 0 , L_1 ,
V_4 ) ;
if ( V_30 ) {
F_12 ( V_32 L_5 ) ;
goto V_47;
}
F_3 ( V_21 ) ;
V_30 = F_18 ( V_4 ) ;
if ( V_30 )
goto V_48;
F_19 ( V_23 , V_4 ) ;
return 0 ;
V_48:
F_20 ( V_27 , V_4 ) ;
V_47:
F_21 ( V_4 ) ;
V_37:
F_22 ( V_9 , 2 ) ;
V_35:
F_22 ( V_25 , 1 ) ;
V_34:
F_22 ( V_21 , 1 ) ;
V_33:
return V_30 ;
}
static int F_23 ( struct V_28 * V_23 , unsigned int V_29 )
{
struct V_3 * V_4 = F_24 ( V_23 ) ;
F_25 ( V_4 ) ;
F_20 ( V_27 , V_4 ) ;
F_22 ( V_9 , 2 ) ;
F_22 ( V_25 , 1 ) ;
F_22 ( V_21 , 1 ) ;
return 0 ;
}
static int F_26 ( struct V_28 * V_23 , unsigned int V_49 ,
T_2 V_50 )
{
F_2 ( V_26 , V_25 ) ;
return 0 ;
}
static int F_27 ( struct V_28 * V_23 , unsigned int V_49 )
{
F_2 ( V_24 , V_25 ) ;
return 0 ;
}
static int T_3 F_28 ( void )
{
if ( ! F_29 ( V_51 ) )
return - V_52 ;
return F_30 ( & V_53 , 1 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_53 ) ;
}
