static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
F_2 ( V_9 | V_10 , V_6 -> V_11 ) ;
F_3 ( 1 ) ;
F_2 ( V_9 , V_6 -> V_11 ) ;
F_3 ( 1 ) ;
V_7 = V_12 + ( V_13 * V_14 / 1000 ) ;
V_8 = F_4 ( V_4 , V_15 ) ;
while ( F_5 ( V_12 , V_7 ) && ( V_8 & V_16 ) ) {
F_3 ( 1 ) ;
V_8 = F_4 ( V_4 , V_15 ) ;
}
if ( V_8 & V_16 ) {
F_6 (KERN_ERR PFX L_1 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_7 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
int V_22 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
void T_2 * V_23 , * V_11 ;
V_22 = F_8 ( V_19 ) ;
if ( V_22 ) {
F_6 (KERN_ERR PFX L_2 ) ;
return V_22 ;
}
V_22 = F_9 ( V_19 , V_24 ) ;
if ( V_22 ) {
F_6 (KERN_ERR PFX L_3 ) ;
goto V_25;
}
V_11 = F_10 ( V_19 , 1 , 0 ) ;
if ( ! V_11 ) {
F_6 (KERN_ERR PFX L_4 ) ;
V_22 = - V_26 ;
goto V_27;
}
V_23 = F_10 ( V_19 , 2 , 0 ) ;
if ( ! V_23 ) {
F_6 (KERN_ERR PFX L_5 ) ;
V_22 = - V_26 ;
goto V_28;
}
V_2 = F_11 ( sizeof( * V_6 ) , & V_19 -> V_29 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
F_6 (KERN_ERR PFX L_6 ) ;
V_22 = - V_30 ;
goto V_31;
}
V_6 = V_2 -> V_6 ;
V_6 -> V_11 = V_11 ;
F_12 ( & V_2 -> V_4 , V_23 , V_32 ) ;
V_22 = F_13 ( V_19 -> V_33 , V_34 , V_35 ,
V_24 , V_2 ) ;
if ( V_22 ) {
F_6 (KERN_ERR PFX L_7 , pdev->irq) ;
V_22 = - V_36 ;
goto V_37;
}
V_22 = F_1 ( V_2 ) ;
if ( V_22 ) {
F_6 (KERN_ERR PFX L_8 ) ;
goto V_38;
}
V_22 = F_14 ( V_2 ) ;
if ( V_22 ) {
F_6 (KERN_ERR PFX L_9 ) ;
goto V_38;
}
V_22 = F_15 ( V_2 , 0 , 0 , NULL ) ;
if ( V_22 ) {
F_6 (KERN_ERR PFX L_10 ) ;
goto V_38;
}
F_16 ( V_19 , V_2 ) ;
return 0 ;
V_38:
F_17 ( V_19 -> V_33 , V_2 ) ;
V_37:
F_16 ( V_19 , NULL ) ;
F_18 ( V_2 ) ;
V_31:
F_19 ( V_19 , V_23 ) ;
V_28:
F_19 ( V_19 , V_11 ) ;
V_27:
F_20 ( V_19 ) ;
V_25:
F_21 ( V_19 ) ;
return V_22 ;
}
static void F_22 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_23 ( V_19 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_24 ( V_2 ) ;
F_17 ( V_19 -> V_33 , V_2 ) ;
F_16 ( V_19 , NULL ) ;
F_18 ( V_2 ) ;
F_19 ( V_19 , V_2 -> V_4 . V_39 ) ;
F_19 ( V_19 , V_6 -> V_11 ) ;
F_20 ( V_19 ) ;
F_21 ( V_19 ) ;
}
static int T_3 F_25 ( void )
{
F_6 ( V_40 L_11 , V_41 ) ;
return F_26 ( & V_42 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_42 ) ;
}
