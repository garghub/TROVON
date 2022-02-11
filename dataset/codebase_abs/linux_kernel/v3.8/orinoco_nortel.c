static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( 8 , V_4 -> V_5 + 2 ) ;
F_3 ( V_4 -> V_6 + V_7 ) ;
F_2 ( 0x80 , V_4 -> V_6 + V_7 ) ;
F_4 ( 1 ) ;
F_2 ( 0 , V_4 -> V_6 + V_7 ) ;
F_2 ( 0 , V_4 -> V_6 + V_7 ) ;
F_4 ( 1 ) ;
F_2 ( V_8 , V_4 -> V_6 + V_7 ) ;
F_2 ( V_8 , V_4 -> V_6 + V_7 ) ;
F_4 ( 1 ) ;
F_2 ( 0x228 , V_4 -> V_5 + 2 ) ;
return 0 ;
}
static int F_5 ( struct V_3 * V_4 )
{
int V_9 ;
T_1 V_10 ;
if ( F_3 ( V_4 -> V_5 ) & 1 ) {
F_6 (KERN_ERR PFX L_1 ) ;
return - V_11 ;
}
F_2 ( 0x118 , V_4 -> V_5 + 2 ) ;
F_2 ( 0x108 , V_4 -> V_5 + 2 ) ;
F_4 ( 30 ) ;
F_2 ( 0x8 , V_4 -> V_5 + 2 ) ;
for ( V_9 = 0 ; V_9 < 30 ; V_9 ++ ) {
F_4 ( 30 ) ;
if ( F_3 ( V_4 -> V_5 ) & 0x10 )
break;
}
if ( V_9 == 30 ) {
F_6 (KERN_ERR PFX L_2 ) ;
return - V_11 ;
}
if ( F_3 ( V_4 -> V_6 + V_7 ) & 1 ) {
F_6 (KERN_ERR PFX L_3 ) ;
return - V_11 ;
}
if ( F_3 ( V_4 -> V_6 + V_7 + 2 ) & 1 ) {
F_6 (KERN_ERR PFX L_4 ) ;
return - V_11 ;
}
if ( F_3 ( V_4 -> V_6 + V_7 + 4 ) & 1 ) {
F_6 (KERN_ERR PFX L_5 ) ;
return - V_11 ;
}
F_2 ( V_8 , V_4 -> V_6 + V_7 ) ;
F_4 ( 1 ) ;
V_10 = F_3 ( V_4 -> V_6 + V_7 ) ;
if ( V_10 != V_8 ) {
F_6 (KERN_ERR PFX L_6 ,
reg) ;
return - V_11 ;
}
F_2 ( 1 , V_4 -> V_5 + 10 ) ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
int V_16 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
void T_2 * V_17 , * V_5 , * V_6 ;
V_16 = F_8 ( V_13 ) ;
if ( V_16 ) {
F_6 (KERN_ERR PFX L_7 ) ;
return V_16 ;
}
V_16 = F_9 ( V_13 , V_18 ) ;
if ( V_16 ) {
F_6 (KERN_ERR PFX L_8 ) ;
goto V_19;
}
V_5 = F_10 ( V_13 , 0 , 0 ) ;
if ( ! V_5 ) {
F_6 (KERN_ERR PFX L_9 ) ;
V_16 = - V_20 ;
goto V_21;
}
V_6 = F_10 ( V_13 , 1 , 0 ) ;
if ( ! V_6 ) {
F_6 (KERN_ERR PFX L_10 ) ;
V_16 = - V_20 ;
goto V_22;
}
V_17 = F_10 ( V_13 , 2 , 0 ) ;
if ( ! V_17 ) {
F_6 (KERN_ERR PFX L_11 ) ;
V_16 = - V_20 ;
goto V_23;
}
V_2 = F_11 ( sizeof( * V_4 ) , & V_13 -> V_24 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
F_6 (KERN_ERR PFX L_12 ) ;
V_16 = - V_25 ;
goto V_26;
}
V_4 = V_2 -> V_4 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_6 = V_6 ;
F_12 ( & V_2 -> V_27 , V_17 , V_28 ) ;
V_16 = F_13 ( V_13 -> V_29 , V_30 , V_31 ,
V_18 , V_2 ) ;
if ( V_16 ) {
F_6 (KERN_ERR PFX L_13 , pdev->irq) ;
V_16 = - V_11 ;
goto V_32;
}
V_16 = F_5 ( V_4 ) ;
if ( V_16 ) {
F_6 (KERN_ERR PFX L_14 ) ;
goto V_33;
}
V_16 = F_1 ( V_2 ) ;
if ( V_16 ) {
F_6 (KERN_ERR PFX L_15 ) ;
goto V_33;
}
V_16 = F_14 ( V_2 ) ;
if ( V_16 ) {
F_6 (KERN_ERR PFX L_16 ) ;
goto V_33;
}
V_16 = F_15 ( V_2 , 0 , 0 , NULL ) ;
if ( V_16 ) {
F_6 (KERN_ERR PFX L_17 ) ;
goto V_33;
}
F_16 ( V_13 , V_2 ) ;
return 0 ;
V_33:
F_17 ( V_13 -> V_29 , V_2 ) ;
V_32:
F_16 ( V_13 , NULL ) ;
F_18 ( V_2 ) ;
V_26:
F_19 ( V_13 , V_17 ) ;
V_23:
F_19 ( V_13 , V_6 ) ;
V_22:
F_19 ( V_13 , V_5 ) ;
V_21:
F_20 ( V_13 ) ;
V_19:
F_21 ( V_13 ) ;
return V_16 ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_23 ( V_13 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( 0 , V_4 -> V_5 + 10 ) ;
F_24 ( V_2 ) ;
F_17 ( V_13 -> V_29 , V_2 ) ;
F_16 ( V_13 , NULL ) ;
F_18 ( V_2 ) ;
F_19 ( V_13 , V_2 -> V_27 . V_34 ) ;
F_19 ( V_13 , V_4 -> V_6 ) ;
F_19 ( V_13 , V_4 -> V_5 ) ;
F_20 ( V_13 ) ;
F_21 ( V_13 ) ;
}
static int T_3 F_25 ( void )
{
F_6 ( V_35 L_18 , V_36 ) ;
return F_26 ( & V_37 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_37 ) ;
}
