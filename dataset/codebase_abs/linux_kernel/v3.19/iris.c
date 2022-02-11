static void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
F_3 ( 850 ) ;
F_2 ( V_3 , V_2 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
unsigned char V_6 = F_5 ( V_7 ) ;
if ( V_6 == V_8 ) {
F_6 ( V_9 L_1
L_2 ) ;
return - V_10 ;
}
V_11 = V_12 ;
V_12 = & F_1 ;
F_6 ( V_13 L_3 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 )
{
V_12 = V_11 ;
F_6 ( V_13 L_4 ) ;
return 0 ;
}
static int F_8 ( void )
{
int V_14 ;
if ( V_15 != 1 ) {
F_6 ( V_9 L_5
L_6 ) ;
return - V_10 ;
}
V_14 = F_9 ( & V_16 ) ;
if ( V_14 < 0 ) {
F_6 ( V_9 L_7 ,
V_14 ) ;
return V_14 ;
}
V_17 = F_10 ( L_8 , ( - 1 ) ,
V_18 , F_11 ( V_18 ) ) ;
if ( F_12 ( V_17 ) ) {
F_6 ( V_9 L_9 ) ;
F_13 ( & V_16 ) ;
return F_14 ( V_17 ) ;
}
return 0 ;
}
static void F_15 ( void )
{
F_16 ( V_17 ) ;
F_13 ( & V_16 ) ;
}
