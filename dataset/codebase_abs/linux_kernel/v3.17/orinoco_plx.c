static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
F_2 ( V_9 | V_10 , V_6 -> V_11 + V_12 ) ;
F_3 ( 1 ) ;
F_2 ( V_9 , V_6 -> V_11 + V_12 ) ;
F_3 ( 1 ) ;
V_7 = V_13 + ( V_14 * V_15 / 1000 ) ;
V_8 = F_4 ( V_4 , V_16 ) ;
while ( F_5 ( V_13 , V_7 ) && ( V_8 & V_17 ) ) {
F_3 ( 1 ) ;
V_8 = F_4 ( V_4 , V_16 ) ;
}
if ( V_8 & V_17 ) {
F_6 (KERN_ERR PFX L_1 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
int V_19 ;
T_2 V_20 ;
static const T_3 V_21 [] = {
0x01 , 0x03 , 0x00 , 0x00 , 0xff , 0x17 , 0x04 , 0x67
} ;
F_6 (KERN_DEBUG PFX L_2 ) ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ )
F_6 ( L_3 , F_8 ( V_6 -> V_11 + ( V_19 << 1 ) ) ) ;
F_6 ( L_4 ) ;
for ( V_19 = 0 ; V_19 < sizeof( V_21 ) ; V_19 ++ ) {
if ( V_21 [ V_19 ] != F_8 ( V_6 -> V_11 + ( V_19 << 1 ) ) ) {
F_6 (KERN_ERR PFX L_5
L_6 ) ;
return - V_22 ;
}
}
V_20 = F_9 ( V_6 -> V_23 + V_24 ) ;
if ( ! ( V_20 & V_25 ) ) {
V_20 |= V_25 ;
F_10 ( V_20 , V_6 -> V_23 + V_24 ) ;
V_20 = F_9 ( V_6 -> V_23 + V_24 ) ;
if ( ! ( V_20 & V_25 ) ) {
F_6 (KERN_ERR PFX L_7 ) ;
return - V_26 ;
}
}
return 0 ;
}
static int F_11 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
int V_31 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
void T_4 * V_32 , * V_11 , * V_23 ;
V_31 = F_12 ( V_28 ) ;
if ( V_31 ) {
F_6 (KERN_ERR PFX L_8 ) ;
return V_31 ;
}
V_31 = F_13 ( V_28 , V_33 ) ;
if ( V_31 ) {
F_6 (KERN_ERR PFX L_9 ) ;
goto V_34;
}
V_23 = F_14 ( V_28 , 1 , 0 ) ;
if ( ! V_23 ) {
F_6 (KERN_ERR PFX L_10 ) ;
V_31 = - V_26 ;
goto V_35;
}
V_11 = F_14 ( V_28 , 2 , 0 ) ;
if ( ! V_11 ) {
F_6 (KERN_ERR PFX L_11 ) ;
V_31 = - V_26 ;
goto V_36;
}
V_32 = F_14 ( V_28 , 3 , 0 ) ;
if ( ! V_32 ) {
F_6 (KERN_ERR PFX L_12 ) ;
V_31 = - V_26 ;
goto V_37;
}
V_2 = F_15 ( sizeof( * V_6 ) , & V_28 -> V_38 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
F_6 (KERN_ERR PFX L_13 ) ;
V_31 = - V_39 ;
goto V_40;
}
V_6 = V_2 -> V_6 ;
V_6 -> V_23 = V_23 ;
V_6 -> V_11 = V_11 ;
F_16 ( & V_2 -> V_4 , V_32 , V_41 ) ;
V_31 = F_17 ( V_28 -> V_42 , V_43 , V_44 ,
V_33 , V_2 ) ;
if ( V_31 ) {
F_6 (KERN_ERR PFX L_14 , pdev->irq) ;
V_31 = - V_45 ;
goto V_46;
}
V_31 = F_7 ( V_6 ) ;
if ( V_31 ) {
F_6 (KERN_ERR PFX L_15 ) ;
goto V_47;
}
V_31 = F_1 ( V_2 ) ;
if ( V_31 ) {
F_6 (KERN_ERR PFX L_16 ) ;
goto V_47;
}
V_31 = F_18 ( V_2 ) ;
if ( V_31 ) {
F_6 (KERN_ERR PFX L_17 ) ;
goto V_47;
}
V_31 = F_19 ( V_2 , 0 , 0 , NULL ) ;
if ( V_31 ) {
F_6 (KERN_ERR PFX L_18 ) ;
goto V_47;
}
F_20 ( V_28 , V_2 ) ;
return 0 ;
V_47:
F_21 ( V_28 -> V_42 , V_2 ) ;
V_46:
F_22 ( V_2 ) ;
V_40:
F_23 ( V_28 , V_32 ) ;
V_37:
F_23 ( V_28 , V_11 ) ;
V_36:
F_23 ( V_28 , V_23 ) ;
V_35:
F_24 ( V_28 ) ;
V_34:
F_25 ( V_28 ) ;
return V_31 ;
}
static void F_26 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_27 ( V_28 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_28 ( V_2 ) ;
F_21 ( V_28 -> V_42 , V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_28 , V_2 -> V_4 . V_48 ) ;
F_23 ( V_28 , V_6 -> V_11 ) ;
F_23 ( V_28 , V_6 -> V_23 ) ;
F_24 ( V_28 ) ;
F_25 ( V_28 ) ;
}
static int T_5 F_29 ( void )
{
F_6 ( V_49 L_19 , V_50 ) ;
return F_30 ( & V_51 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_51 ) ;
}
