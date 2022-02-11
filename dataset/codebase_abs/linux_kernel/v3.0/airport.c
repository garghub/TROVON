static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 . V_7 ) ;
struct V_8 * V_7 = V_5 -> V_9 ;
struct V_10 * V_11 = V_5 -> V_11 ;
unsigned long V_12 ;
int V_13 ;
F_3 ( V_14 L_1 , V_7 -> V_15 ) ;
V_13 = F_4 ( V_5 , & V_12 ) ;
if ( V_13 ) {
F_3 ( V_16 L_2 ,
V_7 -> V_15 ) ;
return 0 ;
}
F_5 ( V_5 ) ;
F_6 ( V_5 , & V_12 ) ;
F_7 ( V_11 -> V_17 ) ;
F_8 ( V_18 ,
F_9 ( V_2 ) , 0 , 0 ) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 . V_7 ) ;
struct V_8 * V_7 = V_5 -> V_9 ;
struct V_10 * V_11 = V_5 -> V_11 ;
unsigned long V_12 ;
int V_13 ;
F_3 ( V_14 L_3 , V_7 -> V_15 ) ;
F_8 ( V_18 ,
F_9 ( V_2 ) , 0 , 1 ) ;
F_11 ( 200 ) ;
F_12 ( V_11 -> V_17 ) ;
V_5 -> V_19 . V_20 -> V_21 ( & V_5 -> V_22 , & V_12 ) ;
V_13 = F_13 ( V_5 ) ;
V_5 -> V_19 . V_20 -> V_23 ( & V_5 -> V_22 , & V_12 ) ;
return V_13 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 . V_7 ) ;
struct V_10 * V_11 = V_5 -> V_11 ;
if ( V_11 -> V_24 )
F_15 ( V_5 ) ;
V_11 -> V_24 = 0 ;
if ( V_11 -> V_25 )
F_16 ( V_11 -> V_17 , V_5 ) ;
V_11 -> V_25 = 0 ;
if ( V_11 -> V_26 )
F_17 ( V_11 -> V_26 ) ;
V_11 -> V_26 = NULL ;
F_18 ( V_2 , 0 ) ;
F_8 ( V_18 ,
F_9 ( V_2 ) , 0 , 0 ) ;
F_19 ( 1 ) ;
F_20 ( V_2 , NULL ) ;
F_21 ( V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
#if 0
struct airport *card = priv->card;
disable_irq(card->irq);
pmac_call_feature(PMAC_FTR_AIRPORT_ENABLE,
macio_get_of_node(card->mdev), 0, 0);
ssleep(1);
pmac_call_feature(PMAC_FTR_AIRPORT_ENABLE,
macio_get_of_node(card->mdev), 0, 1);
ssleep(1);
enable_irq(card->irq);
ssleep(1);
#endif
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 , const struct V_27 * V_28 )
{
struct V_4 * V_5 ;
struct V_10 * V_11 ;
unsigned long V_29 ;
T_2 * V_19 ;
if ( F_24 ( V_2 ) < 1 || F_25 ( V_2 ) < 1 ) {
F_3 (KERN_ERR PFX L_4 ) ;
return - V_30 ;
}
V_5 = F_26 ( sizeof( * V_11 ) , & V_2 -> V_6 . V_7 ,
F_22 , NULL ) ;
if ( ! V_5 ) {
F_3 (KERN_ERR PFX L_5 ) ;
return - V_30 ;
}
V_11 = V_5 -> V_11 ;
V_19 = & V_5 -> V_19 ;
V_11 -> V_2 = V_2 ;
if ( F_27 ( V_2 , 0 , V_31 ) ) {
F_3 (KERN_ERR PFX L_6 ) ;
F_21 ( V_5 ) ;
return - V_32 ;
}
F_20 ( V_2 , V_5 ) ;
V_11 -> V_17 = F_28 ( V_2 , 0 ) ;
V_29 = F_29 ( V_2 , 0 ) ;
F_3 (KERN_DEBUG PFX L_7 , phys_addr) ;
V_11 -> V_26 = F_30 ( V_29 , V_33 ) ;
if ( ! V_11 -> V_26 ) {
F_3 (KERN_ERR PFX L_8 ) ;
goto V_34;
}
F_31 ( V_19 , V_11 -> V_26 , V_35 ) ;
F_8 ( V_18 ,
F_9 ( V_2 ) , 0 , 1 ) ;
F_19 ( 1 ) ;
V_19 -> V_20 -> V_36 ( V_19 ) ;
if ( F_32 ( V_11 -> V_17 , V_37 , 0 , V_31 , V_5 ) ) {
F_3 (KERN_ERR PFX L_9 , card->irq) ;
goto V_34;
}
V_11 -> V_25 = 1 ;
if ( F_33 ( V_5 ) != 0 ) {
F_3 (KERN_ERR PFX L_10 ) ;
goto V_34;
}
if ( F_34 ( V_5 , V_29 , V_11 -> V_17 , NULL ) != 0 ) {
F_3 (KERN_ERR PFX L_11 ) ;
goto V_34;
}
V_11 -> V_24 = 1 ;
return 0 ;
V_34:
F_14 ( V_2 ) ;
return - V_30 ;
}
static int T_3
F_35 ( void )
{
F_3 ( V_14 L_12 , V_38 ) ;
return F_36 ( & V_39 ) ;
}
static void T_4
F_37 ( void )
{
F_38 ( & V_39 ) ;
}
