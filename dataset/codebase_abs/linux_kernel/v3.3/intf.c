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
void F_14 ( struct V_17 * V_10 , enum V_18 type , int V_19 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_5 * V_6 ;
unsigned long V_20 ;
F_15 ( & V_4 -> V_11 , V_20 ) ;
F_8 (dev_ctx, &priv->ctx_list, list)
if ( V_6 -> V_2 -> V_21 )
V_6 -> V_2 -> V_21 ( V_10 , V_6 -> V_8 , type , V_19 ) ;
F_16 ( & V_4 -> V_11 , V_20 ) ;
}
int F_17 ( struct V_17 * V_10 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_1 * V_2 ;
F_11 ( & V_15 ) ;
F_4 ( & V_4 -> V_22 , & V_22 ) ;
F_8 (intf, &intf_list, list)
F_1 ( V_2 , V_4 ) ;
F_12 ( & V_15 ) ;
if ( ! F_18 ( V_10 ) )
F_19 ( V_10 ) ;
return 0 ;
}
void F_20 ( struct V_17 * V_10 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_1 * V_2 ;
if ( ! F_18 ( V_10 ) )
F_21 ( V_10 ) ;
F_11 ( & V_15 ) ;
F_8 (intf, &intf_list, list)
F_7 ( V_2 , V_4 ) ;
F_9 ( & V_4 -> V_22 ) ;
F_12 ( & V_15 ) ;
}
void * F_22 ( struct V_17 * V_10 , enum V_23 V_24 , int V_19 )
{
struct V_3 * V_4 = V_3 ( V_10 ) ;
struct V_5 * V_6 ;
unsigned long V_20 ;
void * V_25 = NULL ;
F_15 ( & V_4 -> V_11 , V_20 ) ;
F_8 (dev_ctx, &priv->ctx_list, list)
if ( V_6 -> V_2 -> V_26 == V_24 && V_6 -> V_2 -> V_27 ) {
V_25 = V_6 -> V_2 -> V_27 ( V_10 , V_6 -> V_8 , V_19 ) ;
break;
}
F_16 ( & V_4 -> V_11 , V_20 ) ;
return V_25 ;
}
