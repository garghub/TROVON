static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
T_1 V_9 ;
V_9 = 0 ;
if ( F_2 ( V_2 ) -> V_10 >= 6 ) {
F_3 ( V_7 , 0xB0 , & V_9 ) ;
V_9 &= ~ 4095 ;
} else if ( F_2 ( V_2 ) -> V_10 > 3 || F_4 ( V_2 ) ) {
F_3 ( V_7 , 0xA4 , & V_9 ) ;
#if 0
} else if (IS_GEN3(dev)) {
u8 val;
pci_read_config_byte(pdev, 0x9c, &val);
base = val >> 3 << 27;
base -= dev_priv->mm.gtt->stolen_size;
} else {
base = max_low_pfn_mapped << PAGE_SHIFT;
#endif
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 , * V_14 ( V_15 ) ;
V_13 = F_6 ( & V_4 -> V_16 . V_17 ,
V_11 <<= 1 , 4096 , 0 ) ;
if ( ! V_13 )
V_13 = F_6 ( & V_4 -> V_16 . V_17 ,
V_11 >>= 1 , 4096 , 0 ) ;
if ( V_13 )
V_13 = F_7 ( V_13 , V_11 , 4096 ) ;
if ( ! V_13 )
goto V_18;
if ( F_8 ( V_2 ) )
F_9 ( V_19 , V_13 -> V_20 ) ;
else if ( F_10 ( V_2 ) ) {
F_9 ( V_21 , V_13 -> V_20 ) ;
} else {
V_15 = F_6 ( & V_4 -> V_16 . V_17 ,
4096 , 4096 , 0 ) ;
if ( V_15 )
V_15 = F_7 ( V_15 ,
4096 , 4096 ) ;
if ( ! V_15 )
goto V_22;
V_4 -> V_15 = V_15 ;
F_9 ( V_23 ,
V_4 -> V_16 . V_24 + V_13 -> V_20 ) ;
F_9 ( V_25 ,
V_4 -> V_16 . V_24 + V_15 -> V_20 ) ;
}
V_4 -> V_13 = V_13 ;
V_4 -> V_26 = V_11 ;
F_11 ( L_1 ,
V_11 ) ;
return 0 ;
V_22:
F_12 ( V_13 ) ;
V_18:
return - V_27 ;
}
int F_13 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_16 . V_24 == 0 )
return - V_28 ;
if ( V_11 < V_4 -> V_26 )
return 0 ;
F_14 ( V_2 ) ;
return F_5 ( V_2 , V_11 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_26 == 0 )
return;
if ( V_4 -> V_13 )
F_12 ( V_4 -> V_13 ) ;
if ( V_4 -> V_15 )
F_12 ( V_4 -> V_15 ) ;
V_4 -> V_26 = 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_14 ( V_2 ) ;
F_16 ( & V_4 -> V_16 . V_17 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_16 . V_24 = F_1 ( V_2 ) ;
if ( V_4 -> V_16 . V_24 == 0 )
return 0 ;
F_11 ( L_2 ,
V_4 -> V_29 . V_30 , V_4 -> V_16 . V_24 ) ;
F_18 ( & V_4 -> V_16 . V_17 , 0 , V_4 -> V_29 . V_30 ) ;
return 0 ;
}
static struct V_31 *
F_19 ( struct V_1 * V_2 ,
T_1 V_32 , T_1 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_33 ;
struct V_34 * V_35 ;
F_20 ( L_3 , V_32 , V_11 ) ;
F_21 ( V_32 > V_4 -> V_29 . V_30 - V_11 ) ;
V_33 = F_22 ( sizeof( * V_33 ) , V_36 ) ;
if ( V_33 == NULL )
return NULL ;
if ( F_23 ( V_33 , 1 , V_36 ) ) {
F_24 ( V_33 ) ;
return NULL ;
}
V_35 = V_33 -> V_37 ;
V_35 -> V_32 = V_32 ;
V_35 -> V_38 = V_11 ;
F_25 ( V_35 ) = ( V_39 ) V_4 -> V_16 . V_24 + V_32 ;
F_26 ( V_35 ) = V_11 ;
return V_33 ;
}
static int F_27 ( struct V_40 * V_41 )
{
F_28 () ;
return - V_42 ;
}
static void F_29 ( struct V_40 * V_41 )
{
F_30 ( V_41 -> V_43 ) ;
F_24 ( V_41 -> V_43 ) ;
}
static struct V_40 *
F_31 ( struct V_1 * V_2 ,
struct V_12 * V_17 )
{
struct V_40 * V_41 ;
V_41 = F_32 ( V_2 ) ;
if ( V_41 == NULL )
return NULL ;
if ( F_33 ( V_2 , & V_41 -> V_9 , V_17 -> V_11 ) )
goto V_44;
F_34 ( V_41 , & V_45 ) ;
V_41 -> V_43 = F_19 ( V_2 ,
V_17 -> V_20 , V_17 -> V_11 ) ;
if ( V_41 -> V_43 == NULL )
goto V_44;
V_41 -> V_46 = true ;
V_41 -> V_47 = 1 ;
V_41 -> V_17 = V_17 ;
V_41 -> V_9 . V_48 = V_49 ;
V_41 -> V_9 . V_50 = V_49 ;
V_41 -> V_51 = V_52 ;
return V_41 ;
V_44:
F_35 ( V_41 ) ;
return NULL ;
}
struct V_40 *
F_36 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_41 ;
struct V_12 * V_17 ;
if ( V_4 -> V_16 . V_24 == 0 )
return NULL ;
F_11 ( L_4 , V_11 ) ;
if ( V_11 == 0 )
return NULL ;
V_17 = F_6 ( & V_4 -> V_16 . V_17 , V_11 , 4096 , 0 ) ;
if ( V_17 )
V_17 = F_7 ( V_17 , V_11 , 4096 ) ;
if ( V_17 == NULL )
return NULL ;
V_41 = F_31 ( V_2 , V_17 ) ;
if ( V_41 )
return V_41 ;
F_12 ( V_17 ) ;
return NULL ;
}
void
F_37 ( struct V_40 * V_41 )
{
if ( V_41 -> V_17 ) {
F_12 ( V_41 -> V_17 ) ;
V_41 -> V_17 = NULL ;
}
}
