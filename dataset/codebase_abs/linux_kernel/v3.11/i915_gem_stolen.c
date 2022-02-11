static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
T_1 V_9 ;
V_9 = 0 ;
if ( F_2 ( V_2 ) ) {
F_3 ( V_2 -> V_7 , 0x5c , & V_9 ) ;
V_9 &= ~ ( ( 1 << 20 ) - 1 ) ;
} else if ( F_4 ( V_2 ) -> V_10 >= 6 ) {
F_3 ( V_7 , 0xB0 , & V_9 ) ;
V_9 &= ~ 4095 ;
} else if ( F_4 ( V_2 ) -> V_10 > 3 || F_5 ( V_2 ) ) {
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
static int F_6 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 , * V_14 ( V_15 ) ;
V_13 = F_7 ( & V_4 -> V_16 . V_17 ,
V_11 <<= 1 , 4096 , 0 ) ;
if ( ! V_13 )
V_13 = F_7 ( & V_4 -> V_16 . V_17 ,
V_11 >>= 1 , 4096 , 0 ) ;
if ( V_13 )
V_13 = F_8 ( V_13 , V_11 , 4096 ) ;
if ( ! V_13 )
goto V_18;
if ( F_9 ( V_2 ) )
F_10 ( V_19 , V_13 -> V_20 ) ;
else if ( F_11 ( V_2 ) ) {
F_10 ( V_21 , V_13 -> V_20 ) ;
} else {
V_15 = F_7 ( & V_4 -> V_16 . V_17 ,
4096 , 4096 , 0 ) ;
if ( V_15 )
V_15 = F_8 ( V_15 ,
4096 , 4096 ) ;
if ( ! V_15 )
goto V_22;
V_4 -> V_15 = V_15 ;
F_10 ( V_23 ,
V_4 -> V_16 . V_24 + V_13 -> V_20 ) ;
F_10 ( V_25 ,
V_4 -> V_16 . V_24 + V_15 -> V_20 ) ;
}
V_4 -> V_13 = V_13 ;
V_4 -> V_26 = V_11 ;
F_12 ( L_1 ,
V_11 ) ;
return 0 ;
V_22:
F_13 ( V_13 ) ;
V_18:
F_14 ( L_2 , V_11 ) ;
return - V_27 ;
}
int F_15 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_16 ( & V_4 -> V_16 . V_17 ) )
return - V_28 ;
if ( V_11 < V_4 -> V_26 )
return 0 ;
F_17 ( V_2 ) ;
return F_6 ( V_2 , V_11 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_26 == 0 )
return;
if ( V_4 -> V_13 )
F_13 ( V_4 -> V_13 ) ;
if ( V_4 -> V_15 )
F_13 ( V_4 -> V_15 ) ;
V_4 -> V_26 = 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_16 ( & V_4 -> V_16 . V_17 ) )
return;
F_17 ( V_2 ) ;
F_19 ( & V_4 -> V_16 . V_17 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_29 = 0 ;
V_4 -> V_16 . V_24 = F_1 ( V_2 ) ;
if ( V_4 -> V_16 . V_24 == 0 )
return 0 ;
F_12 ( L_3 ,
V_4 -> V_30 . V_31 , V_4 -> V_16 . V_24 ) ;
if ( F_2 ( V_2 ) )
V_29 = 1024 * 1024 ;
F_21 ( & V_4 -> V_16 . V_17 , 0 , V_4 -> V_30 . V_31 -
V_29 ) ;
return 0 ;
}
static struct V_32 *
F_22 ( struct V_1 * V_2 ,
T_1 V_33 , T_1 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_34 ;
struct V_35 * V_36 ;
F_23 ( L_4 , V_33 , V_11 ) ;
F_24 ( V_33 > V_4 -> V_30 . V_31 - V_11 ) ;
V_34 = F_25 ( sizeof( * V_34 ) , V_37 ) ;
if ( V_34 == NULL )
return NULL ;
if ( F_26 ( V_34 , 1 , V_37 ) ) {
F_27 ( V_34 ) ;
return NULL ;
}
V_36 = V_34 -> V_38 ;
V_36 -> V_33 = V_33 ;
V_36 -> V_39 = V_11 ;
F_28 ( V_36 ) = ( V_40 ) V_4 -> V_16 . V_24 + V_33 ;
F_29 ( V_36 ) = V_11 ;
return V_34 ;
}
static int F_30 ( struct V_41 * V_42 )
{
F_31 () ;
return - V_43 ;
}
static void F_32 ( struct V_41 * V_42 )
{
F_33 ( V_42 -> V_44 ) ;
F_27 ( V_42 -> V_44 ) ;
}
static struct V_41 *
F_34 ( struct V_1 * V_2 ,
struct V_12 * V_17 )
{
struct V_41 * V_42 ;
V_42 = F_35 ( V_2 ) ;
if ( V_42 == NULL )
return NULL ;
if ( F_36 ( V_2 , & V_42 -> V_9 , V_17 -> V_11 ) )
goto V_45;
F_37 ( V_42 , & V_46 ) ;
V_42 -> V_44 = F_22 ( V_2 ,
V_17 -> V_20 , V_17 -> V_11 ) ;
if ( V_42 -> V_44 == NULL )
goto V_45;
V_42 -> V_47 = true ;
F_38 ( V_42 ) ;
V_42 -> V_17 = V_17 ;
V_42 -> V_9 . V_48 = V_49 ;
V_42 -> V_9 . V_50 = V_49 ;
V_42 -> V_51 = V_52 ;
return V_42 ;
V_45:
F_39 ( V_42 ) ;
return NULL ;
}
struct V_41 *
F_40 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_41 * V_42 ;
struct V_12 * V_17 ;
if ( ! F_16 ( & V_4 -> V_16 . V_17 ) )
return NULL ;
F_12 ( L_5 , V_11 ) ;
if ( V_11 == 0 )
return NULL ;
V_17 = F_7 ( & V_4 -> V_16 . V_17 , V_11 , 4096 , 0 ) ;
if ( V_17 )
V_17 = F_8 ( V_17 , V_11 , 4096 ) ;
if ( V_17 == NULL )
return NULL ;
V_42 = F_34 ( V_2 , V_17 ) ;
if ( V_42 )
return V_42 ;
F_13 ( V_17 ) ;
return NULL ;
}
struct V_41 *
F_41 ( struct V_1 * V_2 ,
T_1 V_53 ,
T_1 V_54 ,
T_1 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_41 * V_42 ;
struct V_12 * V_17 ;
if ( ! F_16 ( & V_4 -> V_16 . V_17 ) )
return NULL ;
F_12 ( L_6 ,
V_53 , V_54 , V_11 ) ;
F_24 ( V_53 & 4095 ) ;
F_24 ( V_11 & 4095 ) ;
if ( F_42 ( V_11 == 0 ) )
return NULL ;
V_17 = F_43 ( & V_4 -> V_16 . V_17 ,
V_53 , V_11 ,
false ) ;
if ( V_17 == NULL ) {
F_12 ( L_7 ) ;
return NULL ;
}
V_42 = F_34 ( V_2 , V_17 ) ;
if ( V_42 == NULL ) {
F_12 ( L_8 ) ;
F_13 ( V_17 ) ;
return NULL ;
}
if ( V_54 == - 1 )
return V_42 ;
if ( F_16 ( & V_4 -> V_16 . V_55 ) ) {
V_42 -> V_55 = F_43 ( & V_4 -> V_16 . V_55 ,
V_54 , V_11 ,
false ) ;
if ( V_42 -> V_55 == NULL ) {
F_12 ( L_9 ) ;
F_44 ( & V_42 -> V_9 ) ;
return NULL ;
}
} else
V_42 -> V_55 = V_56 ;
V_42 -> V_54 = V_54 ;
V_42 -> V_57 = 1 ;
F_45 ( & V_42 -> V_58 , & V_4 -> V_16 . V_59 ) ;
F_45 ( & V_42 -> V_60 , & V_4 -> V_16 . V_61 ) ;
return V_42 ;
}
void
F_46 ( struct V_41 * V_42 )
{
if ( V_42 -> V_17 ) {
F_13 ( V_42 -> V_17 ) ;
V_42 -> V_17 = NULL ;
}
}
