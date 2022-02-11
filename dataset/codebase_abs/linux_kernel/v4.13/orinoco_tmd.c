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
V_7 = V_12 + F_4 ( V_13 ) ;
V_8 = F_5 ( V_4 , V_14 ) ;
while ( F_6 ( V_12 , V_7 ) && ( V_8 & V_15 ) ) {
F_3 ( 1 ) ;
V_8 = F_5 ( V_4 , V_14 ) ;
}
if ( V_8 & V_15 ) {
F_7 (KERN_ERR PFX L_1 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_8 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
int V_21 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
void T_2 * V_22 , * V_11 ;
V_21 = F_9 ( V_18 ) ;
if ( V_21 ) {
F_7 (KERN_ERR PFX L_2 ) ;
return V_21 ;
}
V_21 = F_10 ( V_18 , V_23 ) ;
if ( V_21 ) {
F_7 (KERN_ERR PFX L_3 ) ;
goto V_24;
}
V_11 = F_11 ( V_18 , 1 , 0 ) ;
if ( ! V_11 ) {
F_7 (KERN_ERR PFX L_4 ) ;
V_21 = - V_25 ;
goto V_26;
}
V_22 = F_11 ( V_18 , 2 , 0 ) ;
if ( ! V_22 ) {
F_7 (KERN_ERR PFX L_5 ) ;
V_21 = - V_25 ;
goto V_27;
}
V_2 = F_12 ( sizeof( * V_6 ) , & V_18 -> V_28 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
F_7 (KERN_ERR PFX L_6 ) ;
V_21 = - V_29 ;
goto V_30;
}
V_6 = V_2 -> V_6 ;
V_6 -> V_11 = V_11 ;
F_13 ( & V_2 -> V_4 , V_22 , V_31 ) ;
V_21 = F_14 ( V_18 -> V_32 , V_33 , V_34 ,
V_23 , V_2 ) ;
if ( V_21 ) {
F_7 (KERN_ERR PFX L_7 , pdev->irq) ;
V_21 = - V_35 ;
goto V_36;
}
V_21 = F_1 ( V_2 ) ;
if ( V_21 ) {
F_7 (KERN_ERR PFX L_8 ) ;
goto V_37;
}
V_21 = F_15 ( V_2 ) ;
if ( V_21 ) {
F_7 (KERN_ERR PFX L_9 ) ;
goto V_37;
}
V_21 = F_16 ( V_2 , 0 , 0 , NULL ) ;
if ( V_21 ) {
F_7 (KERN_ERR PFX L_10 ) ;
goto V_37;
}
F_17 ( V_18 , V_2 ) ;
return 0 ;
V_37:
F_18 ( V_18 -> V_32 , V_2 ) ;
V_36:
F_19 ( V_2 ) ;
V_30:
F_20 ( V_18 , V_22 ) ;
V_27:
F_20 ( V_18 , V_11 ) ;
V_26:
F_21 ( V_18 ) ;
V_24:
F_22 ( V_18 ) ;
return V_21 ;
}
static void F_23 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_24 ( V_18 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_25 ( V_2 ) ;
F_18 ( V_18 -> V_32 , V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_18 , V_2 -> V_4 . V_38 ) ;
F_20 ( V_18 , V_6 -> V_11 ) ;
F_21 ( V_18 ) ;
F_22 ( V_18 ) ;
}
static int T_3 F_26 ( void )
{
F_7 ( V_39 L_11 , V_40 ) ;
return F_27 ( & V_41 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_41 ) ;
}
