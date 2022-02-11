static inline const struct V_1 *
F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( ( V_2 -> V_5 == V_6 || V_2 -> V_5 == V_4 -> V_5 ) &&
( V_2 -> V_7 == V_6 || V_2 -> V_7 == V_4 -> V_7 ) &&
( V_2 -> V_8 == V_6 ||
V_2 -> V_8 == V_4 -> V_9 ) &&
( V_2 -> V_10 == V_6 ||
V_2 -> V_10 == V_4 -> V_11 ) &&
! ( ( V_2 -> V_12 ^ V_4 -> V_12 ) & V_2 -> V_13 ) )
return V_2 ;
return NULL ;
}
static struct V_14 * F_2 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
F_3 (tmp_quirk, &xen_pcibk_quirks, quirks_list)
if ( F_1 ( & V_15 -> V_16 , V_4 ) != NULL )
goto V_17;
V_15 = NULL ;
F_4 (KERN_DEBUG DRV_NAME
L_1 ) ;
V_17:
return V_15 ;
}
static inline void F_5 ( struct V_14 * V_18 )
{
F_6 ( & V_18 -> V_19 , & V_20 ) ;
}
int F_7 ( struct V_3 * V_4 , unsigned int V_21 )
{
int V_22 = 0 ;
struct V_23 * V_24 = F_8 ( V_4 ) ;
struct V_25 * V_26 ;
F_3 (cfg_entry, &dev_data->config_fields, list) {
if ( F_9 ( V_26 ) == V_21 ) {
V_22 = 1 ;
break;
}
}
return V_22 ;
}
int F_10 ( struct V_3 * V_4 , struct V_27
* V_28 )
{
int V_29 = 0 ;
switch ( V_28 -> V_30 ) {
case 1 :
V_28 -> V_31 . V_32 . V_33 = V_34 ;
V_28 -> V_31 . V_32 . V_35 = V_36 ;
break;
case 2 :
V_28 -> V_31 . V_37 . V_33 = V_38 ;
V_28 -> V_31 . V_37 . V_35 = V_39 ;
break;
case 4 :
V_28 -> V_31 . V_40 . V_33 = V_41 ;
V_28 -> V_31 . V_40 . V_35 = V_42 ;
break;
default:
V_29 = - V_43 ;
goto V_17;
}
F_11 ( V_4 , V_28 ) ;
V_17:
return V_29 ;
}
int F_12 ( struct V_3 * V_4 )
{
struct V_14 * V_18 ;
int V_22 = 0 ;
V_18 = F_13 ( sizeof( * V_18 ) , V_44 ) ;
if ( ! V_18 ) {
V_22 = - V_45 ;
goto V_17;
}
V_18 -> V_16 . V_5 = V_4 -> V_5 ;
V_18 -> V_16 . V_7 = V_4 -> V_7 ;
V_18 -> V_16 . V_8 = V_4 -> V_9 ;
V_18 -> V_16 . V_10 = V_4 -> V_11 ;
V_18 -> V_16 . V_12 = 0 ;
V_18 -> V_16 . V_13 = 0 ;
V_18 -> V_16 . V_46 = 0UL ;
V_18 -> V_47 = V_4 ;
F_5 ( V_18 ) ;
V_17:
return V_22 ;
}
void F_14 ( struct V_27 * V_28 )
{
F_15 ( V_28 ) ;
}
int F_16 ( struct V_3 * V_4 )
{
struct V_14 * V_18 ;
int V_22 = 0 ;
V_18 = F_2 ( V_4 ) ;
if ( ! V_18 ) {
V_22 = - V_48 ;
goto V_17;
}
F_17 ( & V_18 -> V_19 ) ;
F_15 ( V_18 ) ;
V_17:
return V_22 ;
}
