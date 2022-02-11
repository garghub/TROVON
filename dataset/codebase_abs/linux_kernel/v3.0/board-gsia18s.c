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
F_5 ( NULL ) ;
}
static void T_1 F_6 ( void )
{
F_7 ( & V_12 ) ;
}
static void T_1 F_8 ( void )
{
F_7 ( & V_13 ) ;
F_7 ( & V_14 ) ;
F_7 ( & V_15 ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_16 , 1 ) ;
F_11 ( V_16 , 1 ) ;
F_10 ( V_17 , 1 ) ;
F_11 ( V_17 , 1 ) ;
F_10 ( V_18 , 1 ) ;
F_11 ( V_18 , 1 ) ;
F_10 ( V_19 , 0 ) ;
F_11 ( V_19 , 1 ) ;
F_7 ( & V_20 ) ;
}
static int F_12 ( struct V_21 * V_22 , int V_23 ,
unsigned int V_24 , void * V_25 )
{
int V_26 ;
V_26 = F_13 ( V_23 + V_27 , L_1 ) ;
if ( V_26 < 0 ) {
F_14 ( L_2 ,
V_23 + V_27 ) ;
return V_26 ;
}
V_26 = F_15 ( V_23 + V_27 ) ;
if ( V_26 < 0 ) {
F_14 ( L_3 ,
V_23 + V_27 ) ;
return V_26 ;
}
V_26 = F_16 ( V_23 + V_27 , false ) ;
if ( V_26 < 0 ) {
F_14 ( L_4 ,
V_23 + V_27 ) ;
return V_26 ;
}
V_26 = F_17 ( V_23 + V_27 , 1 ) ;
if ( V_26 < 0 ) {
F_14 ( L_5 ,
V_23 + V_27 ) ;
return V_26 ;
}
return 0 ;
}
static int F_18 ( struct V_21 * V_22 , int V_23 ,
unsigned V_24 , void * V_25 )
{
F_19 ( V_23 + V_27 ) ;
return 0 ;
}
static void F_20 ( void )
{
F_21 ( L_6 ) ;
F_22 ( V_28 , 1 ) ;
while ( 1 )
;
}
static int T_1 F_23 ( void )
{
V_29 = F_20 ;
return 0 ;
}
static void T_1 F_24 ( void )
{
F_25 () ;
F_26 ( & V_30 ) ;
F_27 ( & V_31 ) ;
F_28 ( & V_32 ) ;
F_6 () ;
F_8 () ;
F_9 () ;
F_29 ( V_33 ,
F_30 ( V_33 ) ) ;
F_31 ( & V_34 ) ;
F_32 ( V_35 ,
F_30 ( V_35 ) ) ;
F_23 () ;
}
