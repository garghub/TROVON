static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof *V_6 , V_7 ) ;
if ( ! V_6 )
return;
V_6 -> V_2 = V_2 ;
V_6 -> V_8 = V_2 -> V_9 ( & V_4 -> V_10 ) ;
if ( V_6 -> V_8 ) {
F_3 ( & V_4 -> V_11 ) ;
F_4 ( & V_6 -> V_12 , & V_4 -> V_13 ) ;
F_5 ( & V_4 -> V_11 ) ;
} else
F_6 ( V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_8 (dev_ctx, &priv->ctx_list, list)
if ( V_6 -> V_2 == V_2 ) {
F_3 ( & V_4 -> V_11 ) ;
F_9 ( & V_6 -> V_12 ) ;
F_5 ( & V_4 -> V_11 ) ;
V_2 -> remove ( & V_4 -> V_10 , V_6 -> V_8 ) ;
F_6 ( V_6 ) ;
return;
}
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_9 || ! V_2 -> remove )
return - V_14 ;
F_11 ( & V_15 ) ;
F_4 ( & V_2 -> V_12 , & V_16 ) ;
F_8 (priv, &dev_list, dev_list)
F_1 ( V_2 , V_4 ) ;
F_12 ( & V_15 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_11 ( & V_15 ) ;
F_8 (priv, &dev_list, dev_list)
F_7 ( V_2 , V_4 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_12 ( & V_15 ) ;
}
int F_14 ( struct V_17 * V_10 , bool V_18 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_5 * V_6 = NULL , * V_19 ;
unsigned long V_20 ;
int V_21 ;
F_15 ( V_22 ) ;
if ( ! ( V_10 -> V_23 . V_24 & V_25 ) )
return - V_26 ;
V_21 = F_16 ( V_10 , V_18 ) ;
if ( V_21 ) {
F_17 ( V_10 , L_1 ,
V_18 ? L_2 : L_3 ) ;
return V_21 ;
}
if ( V_18 ) {
V_10 -> V_20 |= V_27 ;
} else {
V_21 = F_18 ( V_10 , 1 , 2 ) ;
if ( V_21 ) {
F_17 ( V_10 , L_4 ) ;
return V_21 ;
}
V_10 -> V_20 &= ~ V_27 ;
}
F_19 ( & V_4 -> V_11 , V_20 ) ;
F_20 (dev_ctx, temp_dev_ctx, &priv->ctx_list, list) {
if ( V_6 -> V_2 -> V_20 & V_28 ) {
F_4 ( & V_6 -> V_22 , & V_22 ) ;
F_9 ( & V_6 -> V_12 ) ;
}
}
F_21 ( & V_4 -> V_11 , V_20 ) ;
F_8 (dev_ctx, &bond_list, bond_list) {
V_6 -> V_2 -> remove ( V_10 , V_6 -> V_8 ) ;
V_6 -> V_8 = V_6 -> V_2 -> V_9 ( V_10 ) ;
F_19 ( & V_4 -> V_11 , V_20 ) ;
F_4 ( & V_6 -> V_12 , & V_4 -> V_13 ) ;
F_21 ( & V_4 -> V_11 , V_20 ) ;
F_22 ( V_10 , L_5 ,
V_6 -> V_2 -> V_29 , V_18 ?
L_6 : L_7 ) ;
}
return 0 ;
}
void F_23 ( struct V_17 * V_10 , enum V_30 type ,
unsigned long V_31 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_5 * V_6 ;
unsigned long V_20 ;
F_19 ( & V_4 -> V_11 , V_20 ) ;
F_8 (dev_ctx, &priv->ctx_list, list)
if ( V_6 -> V_2 -> V_32 )
V_6 -> V_2 -> V_32 ( V_10 , V_6 -> V_8 , type , V_31 ) ;
F_21 ( & V_4 -> V_11 , V_20 ) ;
}
int F_24 ( struct V_17 * V_10 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_1 * V_2 ;
F_11 ( & V_15 ) ;
V_10 -> V_33 -> V_34 |= V_35 ;
F_4 ( & V_4 -> V_36 , & V_36 ) ;
F_8 (intf, &intf_list, list)
F_1 ( V_2 , V_4 ) ;
F_12 ( & V_15 ) ;
F_25 ( V_10 ) ;
return 0 ;
}
void F_26 ( struct V_17 * V_10 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_1 * V_2 ;
F_27 ( V_10 ) ;
F_11 ( & V_15 ) ;
F_8 (intf, &intf_list, list)
F_7 ( V_2 , V_4 ) ;
F_9 ( & V_4 -> V_36 ) ;
V_10 -> V_33 -> V_34 &= ~ V_35 ;
F_12 ( & V_15 ) ;
}
void * F_28 ( struct V_17 * V_10 , enum V_37 V_38 , int V_39 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_5 * V_6 ;
unsigned long V_20 ;
void * V_40 = NULL ;
F_19 ( & V_4 -> V_11 , V_20 ) ;
F_8 (dev_ctx, &priv->ctx_list, list)
if ( V_6 -> V_2 -> V_29 == V_38 && V_6 -> V_2 -> V_41 ) {
V_40 = V_6 -> V_2 -> V_41 ( V_10 , V_6 -> V_8 , V_39 ) ;
break;
}
F_21 ( & V_4 -> V_11 , V_20 ) ;
return V_40 ;
}
