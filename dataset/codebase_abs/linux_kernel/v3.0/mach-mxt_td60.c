static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 ,
void * V_5 )
{
static int V_6 [] = {
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 1
} ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_6 ) ; ++ V_7 ) {
F_3 ( V_3 + V_7 , L_1 ) ;
if ( V_6 [ V_7 ] < 0 )
F_4 ( V_3 + V_7 ) ;
else
F_5 ( V_3 + V_7 ,
V_6 [ V_7 ] ) ;
F_6 ( V_3 + V_7 , 0 ) ;
}
return 0 ;
}
static int F_7 ( struct V_8 * V_9 , T_1 V_10 ,
void * V_11 )
{
return F_8 ( F_9 ( 8 ) , V_10 , V_12 ,
L_2 , V_11 ) ;
}
static void F_10 ( struct V_8 * V_9 , void * V_11 )
{
F_11 ( F_9 ( 8 ) , V_11 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_13 , F_2 ( V_13 ) ,
L_3 ) ;
F_14 ( & V_14 ) ;
F_15 ( & V_14 ) ;
F_16 ( & V_14 ) ;
F_17 ( & V_15 ) ;
F_18 ( 0 , V_16 ,
F_2 ( V_16 ) ) ;
F_18 ( 1 , V_17 ,
F_2 ( V_17 ) ) ;
F_19 ( 0 , & V_18 ) ;
F_19 ( 1 , & V_19 ) ;
F_20 ( & V_20 ) ;
F_21 ( 0 , & V_21 ) ;
F_22 ( NULL ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( 26000000 ) ;
}
