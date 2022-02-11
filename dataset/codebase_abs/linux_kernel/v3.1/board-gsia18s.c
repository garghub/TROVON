static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , 1 ,
V_2 | V_3 |
V_4 | V_5 |
V_6 | V_7 ) ;
F_3 ( V_8 , 2 ,
V_2 | V_3 ) ;
F_3 ( V_9 , 3 ,
V_2 | V_3 ) ;
F_3 ( V_10 , 4 , V_3 ) ;
F_3 ( V_11 , 5 , 0 ) ;
}
static void T_1 F_4 ( void )
{
F_5 ( & V_12 ) ;
}
static void T_1 F_6 ( void )
{
F_5 ( & V_13 ) ;
F_5 ( & V_14 ) ;
F_5 ( & V_15 ) ;
}
static void T_1 F_7 ( void )
{
F_8 ( V_16 , 1 ) ;
F_9 ( V_16 , 1 ) ;
F_8 ( V_17 , 1 ) ;
F_9 ( V_17 , 1 ) ;
F_8 ( V_18 , 1 ) ;
F_9 ( V_18 , 1 ) ;
F_8 ( V_19 , 0 ) ;
F_9 ( V_19 , 1 ) ;
F_5 ( & V_20 ) ;
}
static int F_10 ( struct V_21 * V_22 , int V_23 ,
unsigned int V_24 , void * V_25 )
{
int V_26 ;
V_26 = F_11 ( V_23 + V_27 , L_1 ) ;
if ( V_26 < 0 ) {
F_12 ( L_2 ,
V_23 + V_27 ) ;
return V_26 ;
}
V_26 = F_13 ( V_23 + V_27 ) ;
if ( V_26 < 0 ) {
F_12 ( L_3 ,
V_23 + V_27 ) ;
return V_26 ;
}
V_26 = F_14 ( V_23 + V_27 , false ) ;
if ( V_26 < 0 ) {
F_12 ( L_4 ,
V_23 + V_27 ) ;
return V_26 ;
}
V_26 = F_15 ( V_23 + V_27 , 1 ) ;
if ( V_26 < 0 ) {
F_12 ( L_5 ,
V_23 + V_27 ) ;
return V_26 ;
}
return 0 ;
}
static int F_16 ( struct V_21 * V_22 , int V_23 ,
unsigned V_24 , void * V_25 )
{
F_17 ( V_23 + V_27 ) ;
return 0 ;
}
static void F_18 ( void )
{
F_19 ( L_6 ) ;
F_20 ( V_28 , 1 ) ;
while ( 1 )
;
}
static int T_1 F_21 ( void )
{
V_29 = F_18 ;
return 0 ;
}
static void T_1 F_22 ( void )
{
F_23 () ;
F_24 ( & V_30 ) ;
F_25 ( & V_31 ) ;
F_26 ( & V_32 ) ;
F_4 () ;
F_6 () ;
F_7 () ;
F_27 ( V_33 ,
F_28 ( V_33 ) ) ;
F_29 ( & V_34 ) ;
F_30 ( V_35 ,
F_28 ( V_35 ) ) ;
F_21 () ;
}
