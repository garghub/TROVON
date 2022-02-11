static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = & V_2 -> V_3 ;
unsigned long V_4 ;
T_2 V_5 ;
F_2 ( V_3 , V_6 , V_7 ) ;
F_3 ( V_8 ) ;
F_2 ( V_3 , V_6 , 0x0000 ) ;
F_3 ( V_9 ) ;
V_4 = V_10 + ( V_11 * V_12 / 1000 ) ;
V_5 = F_4 ( V_3 , V_13 ) ;
while ( F_5 ( V_10 , V_4 ) && ( V_5 & V_14 ) ) {
F_3 ( 1 ) ;
V_5 = F_4 ( V_3 , V_13 ) ;
}
if ( V_5 & V_14 ) {
F_6 (KERN_ERR PFX L_1 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
int V_20 ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
void T_3 * V_23 ;
V_20 = F_8 ( V_17 ) ;
if ( V_20 ) {
F_6 (KERN_ERR PFX L_2 ) ;
return V_20 ;
}
V_20 = F_9 ( V_17 , V_24 ) ;
if ( V_20 ) {
F_6 (KERN_ERR PFX L_3 ) ;
goto V_25;
}
V_23 = F_10 ( V_17 , 0 , 0 ) ;
if ( ! V_23 ) {
F_6 (KERN_ERR PFX L_4 ) ;
V_20 = - V_26 ;
goto V_27;
}
V_2 = F_11 ( sizeof( * V_22 ) , & V_17 -> V_28 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
F_6 (KERN_ERR PFX L_5 ) ;
V_20 = - V_29 ;
goto V_30;
}
V_22 = V_2 -> V_22 ;
F_12 ( & V_2 -> V_3 , V_23 , V_31 ) ;
V_20 = F_13 ( V_17 -> V_32 , V_33 , V_34 ,
V_24 , V_2 ) ;
if ( V_20 ) {
F_6 (KERN_ERR PFX L_6 , pdev->irq) ;
V_20 = - V_35 ;
goto V_36;
}
V_20 = F_1 ( V_2 ) ;
if ( V_20 ) {
F_6 (KERN_ERR PFX L_7 ) ;
goto V_37;
}
V_20 = F_14 ( V_2 ) ;
if ( V_20 ) {
F_6 (KERN_ERR PFX L_8 ) ;
goto V_37;
}
V_20 = F_15 ( V_2 , 0 , 0 , NULL ) ;
if ( V_20 ) {
F_6 (KERN_ERR PFX L_9 ) ;
goto V_37;
}
F_16 ( V_17 , V_2 ) ;
return 0 ;
V_37:
F_17 ( V_17 -> V_32 , V_2 ) ;
V_36:
F_16 ( V_17 , NULL ) ;
F_18 ( V_2 ) ;
V_30:
F_19 ( V_17 , V_23 ) ;
V_27:
F_20 ( V_17 ) ;
V_25:
F_21 ( V_17 ) ;
return V_20 ;
}
static void T_4 F_22 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_23 ( V_17 ) ;
F_24 ( V_2 ) ;
F_17 ( V_17 -> V_32 , V_2 ) ;
F_16 ( V_17 , NULL ) ;
F_18 ( V_2 ) ;
F_19 ( V_17 , V_2 -> V_3 . V_38 ) ;
F_20 ( V_17 ) ;
F_21 ( V_17 ) ;
}
static int T_5 F_25 ( void )
{
F_6 ( V_39 L_10 , V_40 ) ;
return F_26 ( & V_41 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_41 ) ;
}
