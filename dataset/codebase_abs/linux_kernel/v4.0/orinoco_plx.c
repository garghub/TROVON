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
V_7 = V_13 + F_4 ( V_14 ) ;
V_8 = F_5 ( V_4 , V_15 ) ;
while ( F_6 ( V_13 , V_7 ) && ( V_8 & V_16 ) ) {
F_3 ( 1 ) ;
V_8 = F_5 ( V_4 , V_15 ) ;
}
if ( V_8 & V_16 ) {
F_7 (KERN_ERR PFX L_1 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
int V_18 ;
T_2 V_19 ;
static const T_3 V_20 [] = {
0x01 , 0x03 , 0x00 , 0x00 , 0xff , 0x17 , 0x04 , 0x67
} ;
F_7 (KERN_DEBUG PFX L_2 ) ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ )
F_7 ( L_3 , F_9 ( V_6 -> V_11 + ( V_18 << 1 ) ) ) ;
F_7 ( L_4 ) ;
for ( V_18 = 0 ; V_18 < sizeof( V_20 ) ; V_18 ++ ) {
if ( V_20 [ V_18 ] != F_9 ( V_6 -> V_11 + ( V_18 << 1 ) ) ) {
F_7 (KERN_ERR PFX L_5
L_6 ) ;
return - V_21 ;
}
}
V_19 = F_10 ( V_6 -> V_22 + V_23 ) ;
if ( ! ( V_19 & V_24 ) ) {
V_19 |= V_24 ;
F_11 ( V_19 , V_6 -> V_22 + V_23 ) ;
V_19 = F_10 ( V_6 -> V_22 + V_23 ) ;
if ( ! ( V_19 & V_24 ) ) {
F_7 (KERN_ERR PFX L_7 ) ;
return - V_25 ;
}
}
return 0 ;
}
static int F_12 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
int V_30 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
void T_4 * V_31 , * V_11 , * V_22 ;
V_30 = F_13 ( V_27 ) ;
if ( V_30 ) {
F_7 (KERN_ERR PFX L_8 ) ;
return V_30 ;
}
V_30 = F_14 ( V_27 , V_32 ) ;
if ( V_30 ) {
F_7 (KERN_ERR PFX L_9 ) ;
goto V_33;
}
V_22 = F_15 ( V_27 , 1 , 0 ) ;
if ( ! V_22 ) {
F_7 (KERN_ERR PFX L_10 ) ;
V_30 = - V_25 ;
goto V_34;
}
V_11 = F_15 ( V_27 , 2 , 0 ) ;
if ( ! V_11 ) {
F_7 (KERN_ERR PFX L_11 ) ;
V_30 = - V_25 ;
goto V_35;
}
V_31 = F_15 ( V_27 , 3 , 0 ) ;
if ( ! V_31 ) {
F_7 (KERN_ERR PFX L_12 ) ;
V_30 = - V_25 ;
goto V_36;
}
V_2 = F_16 ( sizeof( * V_6 ) , & V_27 -> V_37 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
F_7 (KERN_ERR PFX L_13 ) ;
V_30 = - V_38 ;
goto V_39;
}
V_6 = V_2 -> V_6 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_11 = V_11 ;
F_17 ( & V_2 -> V_4 , V_31 , V_40 ) ;
V_30 = F_18 ( V_27 -> V_41 , V_42 , V_43 ,
V_32 , V_2 ) ;
if ( V_30 ) {
F_7 (KERN_ERR PFX L_14 , pdev->irq) ;
V_30 = - V_44 ;
goto V_45;
}
V_30 = F_8 ( V_6 ) ;
if ( V_30 ) {
F_7 (KERN_ERR PFX L_15 ) ;
goto V_46;
}
V_30 = F_1 ( V_2 ) ;
if ( V_30 ) {
F_7 (KERN_ERR PFX L_16 ) ;
goto V_46;
}
V_30 = F_19 ( V_2 ) ;
if ( V_30 ) {
F_7 (KERN_ERR PFX L_17 ) ;
goto V_46;
}
V_30 = F_20 ( V_2 , 0 , 0 , NULL ) ;
if ( V_30 ) {
F_7 (KERN_ERR PFX L_18 ) ;
goto V_46;
}
F_21 ( V_27 , V_2 ) ;
return 0 ;
V_46:
F_22 ( V_27 -> V_41 , V_2 ) ;
V_45:
F_23 ( V_2 ) ;
V_39:
F_24 ( V_27 , V_31 ) ;
V_36:
F_24 ( V_27 , V_11 ) ;
V_35:
F_24 ( V_27 , V_22 ) ;
V_34:
F_25 ( V_27 ) ;
V_33:
F_26 ( V_27 ) ;
return V_30 ;
}
static void F_27 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_28 ( V_27 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_29 ( V_2 ) ;
F_22 ( V_27 -> V_41 , V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_27 , V_2 -> V_4 . V_47 ) ;
F_24 ( V_27 , V_6 -> V_11 ) ;
F_24 ( V_27 , V_6 -> V_22 ) ;
F_25 ( V_27 ) ;
F_26 ( V_27 ) ;
}
static int T_5 F_30 ( void )
{
F_7 ( V_48 L_19 , V_49 ) ;
return F_31 ( & V_50 ) ;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_50 ) ;
}
