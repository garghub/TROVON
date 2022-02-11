static void F_1 ( void )
{
F_2 ( 0x0A , V_1 ) ;
F_3 ( 100 ) ;
F_2 ( 0x0B , V_1 ) ;
F_3 ( 100 ) ;
F_2 ( V_2 , V_1 ) ;
F_3 ( 100 ) ;
}
static void F_4 ( void )
{
F_2 ( V_3 , V_4 ) ;
}
static void F_5 ( void )
{
F_2 ( 0 , V_1 ) ;
}
static T_1 F_6 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
if ( V_7 ) {
if ( ! V_9 ) {
T_3 V_10 ;
V_11 = 0 ;
for ( V_10 = 0 ; V_10 != V_7 ; V_10 ++ ) {
char V_12 ;
if ( F_7 ( V_12 , V_6 + V_10 ) )
return - V_13 ;
if ( V_12 == 'V' )
V_11 = 42 ;
}
}
F_4 () ;
}
return V_7 ;
}
static int F_8 ( struct V_14 * V_14 , struct V_5 * V_5 )
{
if ( F_9 ( 0 , & V_15 ) )
return - V_16 ;
if ( V_9 )
F_10 ( V_17 ) ;
F_1 () ;
F_4 () ;
return F_11 ( V_14 , V_5 ) ;
}
static int F_12 ( struct V_14 * V_14 , struct V_5 * V_5 )
{
if ( V_11 == 42 )
F_5 () ;
else
F_13 (KERN_CRIT PFX L_1
L_2 ) ;
F_14 ( 0 , & V_15 ) ;
V_11 = 0 ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 , unsigned long V_20 ,
void * V_21 )
{
if ( V_20 == V_22 || V_20 == V_23 )
F_5 () ;
return V_24 ;
}
static int T_5 F_16 ( void )
{
int V_25 ;
unsigned long int V_26 = 60000 ;
if ( V_27 < 0 || V_27 > 63 ) {
F_13 (KERN_ERR PFX L_3 ) ;
V_25 = - V_28 ;
goto V_29;
}
if ( ! F_17 ( V_1 , 1 , L_4 ) ) {
F_13 (KERN_ERR PFX L_5 ,
SBC8360_ENABLE) ;
V_25 = - V_30 ;
goto V_29;
}
if ( ! F_17 ( V_4 , 1 , L_4 ) ) {
F_13 (KERN_ERR PFX
L_6 ,
SBC8360_BASETIME) ;
V_25 = - V_30 ;
goto V_31;
}
V_25 = F_18 ( & V_32 ) ;
if ( V_25 ) {
F_13 (KERN_ERR PFX L_7 ) ;
goto V_33;
}
V_25 = F_19 ( & V_34 ) ;
if ( V_25 ) {
F_13 (KERN_ERR PFX L_8 ) ;
goto V_35;
}
V_3 = V_36 [ V_27 ] [ 0 ] ;
V_2 = V_36 [ V_27 ] [ 1 ] ;
if ( V_2 == 1 )
V_26 = ( V_3 + 1 ) * 500 ;
else if ( V_2 == 2 )
V_26 = ( V_3 + 1 ) * 5000 ;
else if ( V_2 == 3 )
V_26 = ( V_3 + 1 ) * 50000 ;
else if ( V_2 == 4 )
V_26 = ( V_3 + 1 ) * 100000 ;
F_13 (KERN_INFO PFX L_9 , mseconds) ;
return 0 ;
V_35:
F_20 ( & V_32 ) ;
V_33:
F_21 ( V_4 , 1 ) ;
V_31:
F_21 ( V_1 , 1 ) ;
V_29:
return V_25 ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_34 ) ;
F_20 ( & V_32 ) ;
F_21 ( V_1 , 1 ) ;
F_21 ( V_4 , 1 ) ;
}
