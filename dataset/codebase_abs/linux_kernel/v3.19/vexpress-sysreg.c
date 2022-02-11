static void T_1 * F_1 ( void )
{
if ( ! V_1 ) {
struct V_2 * V_3 = F_2 ( NULL , NULL ,
L_1 ) ;
V_1 = F_3 ( V_3 , 0 ) ;
}
F_4 ( ! V_1 ) ;
return V_1 ;
}
static int F_5 ( void )
{
if ( F_6 ( F_1 () + V_4 ) & V_5 )
return V_6 ;
return V_7 ;
}
void F_7 ( T_2 V_8 )
{
F_8 ( ~ 0 , F_1 () + V_9 ) ;
F_8 ( V_8 , F_1 () + V_10 ) ;
}
unsigned int F_9 ( struct V_11 * V_12 )
{
return F_6 ( F_1 () + V_13 ) & V_14 ;
}
T_2 F_10 ( int V_15 )
{
if ( V_15 == V_16 )
V_15 = F_5 () ;
return F_6 ( F_1 () + ( V_15 == V_7 ?
V_17 : V_18 ) ) ;
}
void T_1 * F_11 ( void )
{
return F_1 () + V_19 ;
}
void T_3 F_12 ( void T_1 * V_20 )
{
V_1 = V_20 ;
F_13 ( F_5 () ) ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
void T_1 * V_20 ;
struct V_25 * V_26 ;
T_2 V_27 ;
V_24 = F_15 ( V_22 , V_28 , 0 ) ;
if ( ! V_24 )
return - V_29 ;
V_20 = F_16 ( & V_22 -> V_12 , V_24 -> V_30 , F_17 ( V_24 ) ) ;
if ( ! V_20 )
return - V_31 ;
F_13 ( F_5 () ) ;
if ( F_18 ( V_32 , L_2 , & V_27 ) == 0 ) {
T_2 V_33 = F_10 ( V_16 ) ;
T_2 V_34 = ( V_33 >> V_35 ) & V_36 ;
if ( F_4 ( V_27 != V_34 ) )
F_19 ( & V_22 -> V_12 , L_3 ,
V_27 , V_34 ) ;
}
V_26 = F_20 ( & V_22 -> V_12 , sizeof( * V_26 ) ,
V_37 ) ;
if ( ! V_26 )
return - V_31 ;
F_21 ( V_26 , & V_22 -> V_12 , 0x4 , V_20 + V_13 ,
NULL , NULL , NULL , NULL , 0 ) ;
V_26 -> V_38 . V_39 = 2 ;
F_22 ( & V_26 -> V_38 ) ;
return F_23 ( & V_22 -> V_12 , V_40 ,
V_41 ,
F_24 ( V_41 ) , V_24 , 0 , NULL ) ;
}
static int T_3 F_25 ( void )
{
struct V_2 * V_3 ;
F_26 (node, vexpress_sysreg_match)
F_27 ( V_3 , NULL , NULL ) ;
return F_28 ( & V_42 ) ;
}
