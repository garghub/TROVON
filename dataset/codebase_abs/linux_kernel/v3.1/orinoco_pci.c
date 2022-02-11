static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_5 ;
T_1 V_6 ;
F_2 ( V_4 , V_7 , V_8 ) ;
F_3 ( V_9 ) ;
F_2 ( V_4 , V_7 , 0x0000 ) ;
F_3 ( V_10 ) ;
V_5 = V_11 + ( V_12 * V_13 / 1000 ) ;
V_6 = F_4 ( V_4 , V_14 ) ;
while ( F_5 ( V_11 , V_5 ) && ( V_6 & V_15 ) ) {
F_3 ( 1 ) ;
V_6 = F_4 ( V_4 , V_14 ) ;
}
if ( V_6 & V_15 ) {
F_6 (KERN_ERR PFX L_1 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
int V_21 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
void T_2 * V_24 ;
V_21 = F_8 ( V_18 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_2 ) ;
return V_21 ;
}
V_21 = F_9 ( V_18 , V_25 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_3 ) ;
goto V_26;
}
V_24 = F_10 ( V_18 , 0 , 0 ) ;
if ( ! V_24 ) {
F_6 (KERN_ERR PFX L_4 ) ;
V_21 = - V_27 ;
goto V_28;
}
V_2 = F_11 ( sizeof( * V_23 ) , & V_18 -> V_29 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
F_6 (KERN_ERR PFX L_5 ) ;
V_21 = - V_30 ;
goto V_31;
}
V_23 = V_2 -> V_23 ;
F_12 ( & V_2 -> V_4 , V_24 , V_32 ) ;
V_21 = F_13 ( V_18 -> V_33 , V_34 , V_35 ,
V_25 , V_2 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_6 , pdev->irq) ;
V_21 = - V_36 ;
goto V_37;
}
V_21 = F_1 ( V_2 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_7 ) ;
goto V_38;
}
V_21 = F_14 ( V_2 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_8 ) ;
goto V_38;
}
V_21 = F_15 ( V_2 , 0 , 0 , NULL ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_9 ) ;
goto V_38;
}
F_16 ( V_18 , V_2 ) ;
return 0 ;
V_38:
F_17 ( V_18 -> V_33 , V_2 ) ;
V_37:
F_16 ( V_18 , NULL ) ;
F_18 ( V_2 ) ;
V_31:
F_19 ( V_18 , V_24 ) ;
V_28:
F_20 ( V_18 ) ;
V_26:
F_21 ( V_18 ) ;
return V_21 ;
}
static void T_3 F_22 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_23 ( V_18 ) ;
F_24 ( V_2 ) ;
F_17 ( V_18 -> V_33 , V_2 ) ;
F_16 ( V_18 , NULL ) ;
F_18 ( V_2 ) ;
F_19 ( V_18 , V_2 -> V_4 . V_39 ) ;
F_20 ( V_18 ) ;
F_21 ( V_18 ) ;
}
static int T_4 F_25 ( void )
{
F_6 ( V_40 L_10 , V_41 ) ;
return F_26 ( & V_42 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_42 ) ;
}
