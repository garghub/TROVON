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
if ( V_2 -> V_14 )
V_2 -> V_14 ( & V_4 -> V_10 , V_6 -> V_8 ) ;
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
return - V_15 ;
F_11 ( & V_16 ) ;
F_4 ( & V_2 -> V_12 , & V_17 ) ;
F_8 (priv, &dev_list, dev_list) {
if ( F_12 ( & V_4 -> V_10 ) && ( V_2 -> V_18 & V_19 ) ) {
F_13 ( & V_4 -> V_10 ,
L_1 , V_2 -> V_20 ) ;
V_2 -> V_18 &= ~ V_19 ;
}
F_1 ( V_2 , V_4 ) ;
}
F_14 ( & V_16 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_11 ( & V_16 ) ;
F_8 (priv, &dev_list, dev_list)
F_7 ( V_2 , V_4 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_14 ( & V_16 ) ;
}
int F_16 ( struct V_21 * V_10 , bool V_22 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_5 * V_6 = NULL , * V_23 ;
unsigned long V_18 ;
int V_24 ;
F_17 ( V_25 ) ;
if ( ! ( V_10 -> V_26 . V_27 & V_28 ) )
return - V_29 ;
V_24 = F_18 ( V_10 , V_22 ) ;
if ( V_24 ) {
F_19 ( V_10 , L_2 ,
V_22 ? L_3 : L_4 ) ;
return V_24 ;
}
if ( V_22 ) {
V_10 -> V_18 |= V_30 ;
} else {
V_24 = F_20 ( V_10 , 1 , 2 ) ;
if ( V_24 ) {
F_19 ( V_10 , L_5 ) ;
return V_24 ;
}
V_10 -> V_18 &= ~ V_30 ;
}
F_21 ( & V_4 -> V_11 , V_18 ) ;
F_22 (dev_ctx, temp_dev_ctx, &priv->ctx_list, list) {
if ( V_6 -> V_2 -> V_18 & V_19 ) {
F_4 ( & V_6 -> V_25 , & V_25 ) ;
F_9 ( & V_6 -> V_12 ) ;
}
}
F_23 ( & V_4 -> V_11 , V_18 ) ;
F_8 (dev_ctx, &bond_list, bond_list) {
V_6 -> V_2 -> remove ( V_10 , V_6 -> V_8 ) ;
V_6 -> V_8 = V_6 -> V_2 -> V_9 ( V_10 ) ;
F_21 ( & V_4 -> V_11 , V_18 ) ;
F_4 ( & V_6 -> V_12 , & V_4 -> V_13 ) ;
F_23 ( & V_4 -> V_11 , V_18 ) ;
F_13 ( V_10 , L_6 ,
V_6 -> V_2 -> V_20 , V_22 ?
L_7 : L_8 ) ;
}
return 0 ;
}
void F_24 ( struct V_21 * V_10 , enum V_31 type ,
unsigned long V_32 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_5 * V_6 ;
unsigned long V_18 ;
F_21 ( & V_4 -> V_11 , V_18 ) ;
F_8 (dev_ctx, &priv->ctx_list, list)
if ( V_6 -> V_2 -> V_33 )
V_6 -> V_2 -> V_33 ( V_10 , V_6 -> V_8 , type , V_32 ) ;
F_23 ( & V_4 -> V_11 , V_18 ) ;
}
int F_25 ( struct V_21 * V_10 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_1 * V_2 ;
F_11 ( & V_16 ) ;
V_10 -> V_34 -> V_35 |= V_36 ;
F_4 ( & V_4 -> V_37 , & V_37 ) ;
F_8 (intf, &intf_list, list)
F_1 ( V_2 , V_4 ) ;
F_14 ( & V_16 ) ;
F_26 ( V_10 ) ;
return 0 ;
}
void F_27 ( struct V_21 * V_10 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_1 * V_2 ;
if ( ! ( V_10 -> V_34 -> V_35 & V_36 ) )
return;
F_28 ( V_10 ) ;
if ( V_10 -> V_34 -> V_35 & V_38 &&
F_29 ( V_10 ) ) {
T_1 V_39 =
F_30 ( F_31 ( & V_3 ( V_10 ) -> V_40 . V_41 -> V_39 ) ) ;
if ( F_32 ( V_39 ) ) {
F_13 ( V_10 , L_9 ,
V_42 ) ;
F_33 ( V_10 -> V_34 ) ;
}
}
F_11 ( & V_16 ) ;
F_8 (intf, &intf_list, list)
F_7 ( V_2 , V_4 ) ;
F_9 ( & V_4 -> V_37 ) ;
V_10 -> V_34 -> V_35 &= ~ V_36 ;
F_14 ( & V_16 ) ;
}
void * F_34 ( struct V_21 * V_10 , enum V_43 V_44 , int V_45 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_5 * V_6 ;
unsigned long V_18 ;
void * V_46 = NULL ;
F_21 ( & V_4 -> V_11 , V_18 ) ;
F_8 (dev_ctx, &priv->ctx_list, list)
if ( V_6 -> V_2 -> V_20 == V_44 && V_6 -> V_2 -> V_47 ) {
V_46 = V_6 -> V_2 -> V_47 ( V_10 , V_6 -> V_8 , V_45 ) ;
break;
}
F_23 ( & V_4 -> V_11 , V_18 ) ;
return V_46 ;
}
struct V_48 * F_35 ( struct V_21 * V_10 , int V_45 )
{
struct V_49 * V_50 = & V_3 ( V_10 ) -> V_45 [ V_45 ] ;
return & V_50 -> V_48 ;
}
