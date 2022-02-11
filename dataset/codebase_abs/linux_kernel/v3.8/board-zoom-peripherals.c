static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
int V_5 ;
V_6 [ 0 ] . V_7 = V_3 + 0 ;
F_2 ( V_6 ) ;
V_5 = F_3 ( V_8 , V_9 ,
L_1 ) ;
if ( V_5 )
F_4 ( L_2 ,
V_8 ) ;
return V_5 ;
}
static int T_1 F_5 ( void )
{
F_6 ( & V_10 ,
V_11 | V_12 |
V_13 | V_14 ,
V_15 | V_16 ) ;
if ( F_7 () ) {
struct V_17 * V_18 ;
V_18 = V_10 . V_19 -> V_20 ;
V_18 -> V_21 = 3 ;
V_18 -> V_22 = 1 ;
V_18 -> V_23 = V_24 ;
}
F_8 ( 1 , 2400 , L_3 , 7 + V_25 , & V_10 ) ;
F_9 ( 2 , 400 , NULL , 0 ) ;
F_9 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void F_10 ( void )
{
F_11 ( L_4 ,
V_26 | V_27 ) ;
}
void T_1 F_12 ( void )
{
int V_5 ;
V_28 . V_29 = F_13 ( V_30 ) ;
V_5 = F_14 ( & V_28 ) ;
if ( V_5 )
F_4 ( L_5 , V_5 ) ;
F_15 ( V_6 ) ;
F_5 () ;
F_16 ( & V_31 ) ;
F_17 ( NULL ) ;
F_10 () ;
F_18 () ;
}
