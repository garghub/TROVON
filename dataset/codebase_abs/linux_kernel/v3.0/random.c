static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( ( V_3 -> V_4 & V_5 ) == 0 )
return - V_6 ;
if ( ( V_3 -> V_4 & V_7 ) != 0 )
return - V_6 ;
return 0 ;
}
static T_1 F_2 ( struct V_2 * V_3 , char T_2 * V_8 , T_3 V_9 ,
T_4 * V_10 )
{
T_5 V_11 ;
int V_12 , V_13 = 0 , V_14 ;
while ( V_9 ) {
V_12 = F_3 ( V_15 , & V_11 , sizeof( V_11 ) ) ;
if ( V_12 > 0 ) {
V_14 = V_12 ;
while ( V_14 && V_9 ) {
if ( F_4 ( ( V_16 ) V_11 , V_8 ++ ) ) {
V_13 = V_13 ? : - V_17 ;
break;
}
V_9 -- ;
V_13 ++ ;
V_14 -- ;
V_11 >>= 8 ;
}
}
else if ( V_12 == - V_18 ) {
F_5 ( V_19 , V_20 ) ;
if ( V_3 -> V_21 & V_22 )
return V_13 ? : - V_18 ;
F_6 ( & V_23 ) ;
F_7 ( V_15 , V_24 ) ;
F_8 ( V_15 ) ;
F_9 ( & V_25 , & V_19 ) ;
F_10 ( V_20 , V_26 ) ;
F_11 () ;
F_10 ( V_20 , V_27 ) ;
F_12 ( & V_25 , & V_19 ) ;
if ( F_13 ( & V_23 ) ) {
F_14 ( V_15 ) ;
F_15 ( V_15 , V_24 ) ;
}
}
else
return V_12 ;
if ( F_16 ( V_20 ) )
return V_13 ? : - V_28 ;
}
return V_13 ;
}
static T_6 F_17 ( int V_29 , void * V_11 )
{
F_18 ( & V_25 ) ;
return V_30 ;
}
static int T_7 F_19 ( void )
{
int V_31 ;
V_31 = F_20 ( L_1 , F_21 ( F_22 () ) , 0 ) ;
if ( V_31 < 0 )
goto V_32;
V_15 = V_31 ;
V_31 = F_23 ( V_24 , V_15 , V_33 , F_17 ,
V_34 | V_35 , L_2 ,
NULL ) ;
if ( V_31 )
goto V_36;
F_24 ( V_15 , 1 ) ;
V_31 = F_25 ( & V_37 ) ;
if ( V_31 ) {
F_26 (KERN_ERR RNG_MODULE_NAME L_3
L_4 ) ;
goto V_36;
}
V_32:
return V_31 ;
V_36:
F_27 ( V_15 ) ;
V_15 = - 1 ;
goto V_32;
}
static void T_8 F_28 ( void )
{
F_27 ( V_15 ) ;
F_29 ( & V_37 ) ;
}
