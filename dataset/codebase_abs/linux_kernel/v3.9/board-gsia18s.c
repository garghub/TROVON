static void T_1 F_1 ( void )
{
F_2 () ;
}
static void T_1 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void T_1 F_5 ( void )
{
F_4 ( & V_2 ) ;
F_4 ( & V_3 ) ;
F_4 ( & V_4 ) ;
}
static void T_1 F_6 ( void )
{
F_7 ( V_5 , 1 ) ;
F_8 ( V_5 , 1 ) ;
F_7 ( V_6 , 1 ) ;
F_8 ( V_6 , 1 ) ;
F_7 ( V_7 , 1 ) ;
F_8 ( V_7 , 1 ) ;
F_7 ( V_8 , 0 ) ;
F_8 ( V_8 , 1 ) ;
F_4 ( & V_9 ) ;
}
static int F_9 ( struct V_10 * V_11 , int V_12 ,
unsigned int V_13 , void * V_14 )
{
int V_15 ;
V_15 = F_10 ( V_12 + V_16 , L_1 ) ;
if ( V_15 < 0 ) {
F_11 ( L_2 ,
V_12 + V_16 ) ;
return V_15 ;
}
V_15 = F_12 ( V_12 + V_16 ) ;
if ( V_15 < 0 ) {
F_11 ( L_3 ,
V_12 + V_16 ) ;
return V_15 ;
}
V_15 = F_13 ( V_12 + V_16 , false ) ;
if ( V_15 < 0 ) {
F_11 ( L_4 ,
V_12 + V_16 ) ;
return V_15 ;
}
V_15 = F_14 ( V_12 + V_16 , 1 ) ;
if ( V_15 < 0 ) {
F_11 ( L_5 ,
V_12 + V_16 ) ;
return V_15 ;
}
return 0 ;
}
static int F_15 ( struct V_10 * V_11 , int V_12 ,
unsigned V_13 , void * V_14 )
{
F_16 ( V_12 + V_16 ) ;
return 0 ;
}
static void F_17 ( void )
{
F_18 ( L_6 ) ;
F_19 ( V_17 , 1 ) ;
while ( 1 )
;
}
static int T_1 F_20 ( void )
{
V_18 = F_17 ;
return 0 ;
}
static void T_1 F_21 ( void )
{
F_22 ( V_19 , 1 ,
V_20 | V_21 |
V_22 | V_23 |
V_24 | V_25 ) ;
F_22 ( V_26 , 2 ,
V_20 | V_21 ) ;
F_22 ( V_27 , 3 ,
V_20 | V_21 ) ;
F_22 ( V_28 , 4 , V_21 ) ;
F_22 ( V_29 , 5 , 0 ) ;
F_23 () ;
F_24 ( & V_30 ) ;
F_25 ( & V_31 ) ;
F_26 ( & V_32 ) ;
F_3 () ;
F_5 () ;
F_6 () ;
F_27 ( V_33 ,
F_28 ( V_33 ) ) ;
F_29 ( & V_34 ) ;
F_30 ( V_35 ,
F_28 ( V_35 ) ) ;
F_20 () ;
}
