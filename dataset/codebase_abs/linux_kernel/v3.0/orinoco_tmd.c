static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = & V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_6 ;
T_2 V_7 ;
F_2 ( V_8 | V_9 , V_5 -> V_10 ) ;
F_3 ( 1 ) ;
F_2 ( V_8 , V_5 -> V_10 ) ;
F_3 ( 1 ) ;
V_6 = V_11 + ( V_12 * V_13 / 1000 ) ;
V_7 = F_4 ( V_3 , V_14 ) ;
while ( F_5 ( V_11 , V_6 ) && ( V_7 & V_15 ) ) {
F_3 ( 1 ) ;
V_7 = F_4 ( V_3 , V_14 ) ;
}
if ( V_7 & V_15 ) {
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
struct V_4 * V_5 ;
void T_3 * V_22 , * V_10 ;
V_21 = F_8 ( V_18 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_2 ) ;
return V_21 ;
}
V_21 = F_9 ( V_18 , V_23 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_3 ) ;
goto V_24;
}
V_10 = F_10 ( V_18 , 1 , 0 ) ;
if ( ! V_10 ) {
F_6 (KERN_ERR PFX L_4 ) ;
V_21 = - V_25 ;
goto V_26;
}
V_22 = F_10 ( V_18 , 2 , 0 ) ;
if ( ! V_22 ) {
F_6 (KERN_ERR PFX L_5 ) ;
V_21 = - V_25 ;
goto V_27;
}
V_2 = F_11 ( sizeof( * V_5 ) , & V_18 -> V_28 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
F_6 (KERN_ERR PFX L_6 ) ;
V_21 = - V_29 ;
goto V_30;
}
V_5 = V_2 -> V_5 ;
V_5 -> V_10 = V_10 ;
F_12 ( & V_2 -> V_3 , V_22 , V_31 ) ;
V_21 = F_13 ( V_18 -> V_32 , V_33 , V_34 ,
V_23 , V_2 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_7 , pdev->irq) ;
V_21 = - V_35 ;
goto V_36;
}
V_21 = F_1 ( V_2 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_8 ) ;
goto V_37;
}
V_21 = F_14 ( V_2 ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_9 ) ;
goto V_37;
}
V_21 = F_15 ( V_2 , 0 , 0 , NULL ) ;
if ( V_21 ) {
F_6 (KERN_ERR PFX L_10 ) ;
goto V_37;
}
F_16 ( V_18 , V_2 ) ;
return 0 ;
V_37:
F_17 ( V_18 -> V_32 , V_2 ) ;
V_36:
F_16 ( V_18 , NULL ) ;
F_18 ( V_2 ) ;
V_30:
F_19 ( V_18 , V_22 ) ;
V_27:
F_19 ( V_18 , V_10 ) ;
V_26:
F_20 ( V_18 ) ;
V_24:
F_21 ( V_18 ) ;
return V_21 ;
}
static void T_4 F_22 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_23 ( V_18 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_24 ( V_2 ) ;
F_17 ( V_18 -> V_32 , V_2 ) ;
F_16 ( V_18 , NULL ) ;
F_18 ( V_2 ) ;
F_19 ( V_18 , V_2 -> V_3 . V_38 ) ;
F_19 ( V_18 , V_5 -> V_10 ) ;
F_20 ( V_18 ) ;
F_21 ( V_18 ) ;
}
static int T_5 F_25 ( void )
{
F_6 ( V_39 L_11 , V_40 ) ;
return F_26 ( & V_41 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_41 ) ;
}
