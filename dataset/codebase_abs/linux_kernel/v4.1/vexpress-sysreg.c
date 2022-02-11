void F_1 ( T_1 V_1 )
{
static void T_2 * V_2 ;
if ( ! V_2 ) {
struct V_3 * V_4 = F_2 ( NULL , NULL ,
L_1 ) ;
V_2 = F_3 ( V_4 , 0 ) ;
}
if ( F_4 ( ! V_2 ) )
return;
F_5 ( ~ 0 , V_2 + V_5 ) ;
F_5 ( V_1 , V_2 + V_6 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
void T_2 * V_2 ;
struct V_11 * V_12 ;
int V_13 ;
T_1 V_14 ;
V_10 = F_7 ( V_8 , V_15 , 0 ) ;
if ( ! V_10 )
return - V_16 ;
V_2 = F_8 ( & V_8 -> V_17 , V_10 -> V_18 , F_9 ( V_10 ) ) ;
if ( ! V_2 )
return - V_19 ;
V_13 = F_10 ( V_2 + V_20 ) & V_21 ?
V_22 : V_23 ;
F_11 ( V_13 ) ;
if ( F_12 ( V_24 , L_2 , & V_14 ) == 0 ) {
T_1 V_25 = F_10 ( V_2 + ( V_13 == V_23 ?
V_26 : V_27 ) ) ;
T_1 V_28 = ( V_25 >> V_29 ) & V_30 ;
if ( F_4 ( V_14 != V_28 ) )
F_13 ( & V_8 -> V_17 , L_3 ,
V_14 , V_28 ) ;
}
V_12 = F_14 ( & V_8 -> V_17 , sizeof( * V_12 ) ,
V_31 ) ;
if ( ! V_12 )
return - V_19 ;
F_15 ( V_12 , & V_8 -> V_17 , 0x4 , V_2 + V_32 ,
NULL , NULL , NULL , NULL , 0 ) ;
V_12 -> V_33 . V_34 = 2 ;
F_16 ( & V_12 -> V_33 ) ;
return F_17 ( & V_8 -> V_17 , V_35 ,
V_36 ,
F_18 ( V_36 ) , V_10 , 0 , NULL ) ;
}
static int T_3 F_19 ( void )
{
struct V_3 * V_4 ;
F_20 (node, vexpress_sysreg_match)
F_21 ( V_4 , NULL , NULL ) ;
return F_22 ( & V_37 ) ;
}
