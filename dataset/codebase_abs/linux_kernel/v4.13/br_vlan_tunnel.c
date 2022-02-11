static inline int F_1 ( struct V_1 * V_2 ,
const void * V_3 )
{
const struct V_4 * V_5 = V_3 ;
T_1 V_6 = * ( T_1 * ) V_2 -> V_7 ;
return V_5 -> V_8 . V_9 != V_6 ;
}
static struct V_4 * F_2 ( struct V_10 * V_11 ,
T_2 V_9 )
{
return F_3 ( V_11 , & V_9 ,
V_12 ) ;
}
void F_4 ( struct V_13 * V_14 ,
struct V_4 * V_15 )
{
if ( ! V_15 -> V_8 . V_16 )
return;
F_5 ( & V_14 -> V_17 , & V_15 -> V_18 ,
V_12 ) ;
V_15 -> V_8 . V_9 = 0 ;
F_6 ( & V_15 -> V_8 . V_16 -> V_19 ) ;
V_15 -> V_8 . V_16 = NULL ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_4 * V_15 , T_3 V_20 )
{
struct V_21 * V_22 = NULL ;
T_1 V_7 = F_8 ( F_9 ( V_20 ) ) ;
int V_23 ;
if ( V_15 -> V_8 . V_16 )
return - V_24 ;
V_22 = F_10 ( 0 , 0 , 0 , 0 , 0 , V_25 ,
V_7 , 0 ) ;
if ( ! V_22 )
return - V_26 ;
V_22 -> V_27 . V_28 . V_29 |= V_30 | V_31 ;
V_15 -> V_8 . V_16 = V_22 ;
V_15 -> V_8 . V_9 = V_7 ;
V_23 = F_11 ( & V_14 -> V_17 , & V_15 -> V_18 ,
V_12 ) ;
if ( V_23 )
goto V_32;
return 0 ;
V_32:
F_6 ( & V_15 -> V_8 . V_16 -> V_19 ) ;
V_15 -> V_8 . V_16 = NULL ;
V_15 -> V_8 . V_9 = 0 ;
return V_23 ;
}
int F_12 ( struct V_33 * V_34 , T_4 V_35 , T_3 V_20 )
{
struct V_13 * V_14 ;
struct V_4 * V_15 ;
F_13 () ;
V_14 = F_14 ( V_34 ) ;
V_15 = F_15 ( V_14 , V_35 ) ;
if ( ! V_15 )
return - V_26 ;
return F_7 ( V_14 , V_15 , V_20 ) ;
}
int F_16 ( struct V_33 * V_34 , T_4 V_35 )
{
struct V_13 * V_14 ;
struct V_4 * V_36 ;
F_13 () ;
V_14 = F_14 ( V_34 ) ;
V_36 = F_15 ( V_14 , V_35 ) ;
if ( ! V_36 )
return - V_37 ;
F_4 ( V_14 , V_36 ) ;
return 0 ;
}
static void F_17 ( struct V_13 * V_14 )
{
struct V_4 * V_15 , * V_38 ;
F_18 (vlan, tmp, &vg->vlan_list, vlist)
F_4 ( V_14 , V_15 ) ;
}
void F_19 ( struct V_33 * V_34 )
{
struct V_13 * V_14 ;
F_13 () ;
V_14 = F_14 ( V_34 ) ;
F_17 ( V_14 ) ;
}
int F_20 ( struct V_13 * V_14 )
{
return F_21 ( & V_14 -> V_17 , & V_12 ) ;
}
void F_22 ( struct V_13 * V_14 )
{
F_23 ( & V_14 -> V_17 ) ;
}
int F_24 ( struct V_39 * V_40 ,
struct V_33 * V_41 ,
struct V_13 * V_14 )
{
struct V_42 * V_8 = F_25 ( V_40 ) ;
struct V_4 * V_15 ;
if ( ! V_14 || ! V_8 )
return 0 ;
if ( F_26 ( V_40 ) )
return 0 ;
V_15 = F_2 ( & V_14 -> V_17 , V_8 -> V_7 . V_20 ) ;
if ( ! V_15 )
return 0 ;
F_27 ( V_40 ) ;
F_28 ( V_40 , V_41 -> V_43 -> V_44 , V_15 -> V_35 ) ;
return 0 ;
}
int F_29 ( struct V_39 * V_40 ,
struct V_4 * V_15 )
{
int V_23 ;
if ( ! V_15 || ! V_15 -> V_8 . V_9 )
return 0 ;
if ( F_30 ( ! F_31 ( V_40 ) ) )
return 0 ;
F_27 ( V_40 ) ;
V_23 = F_32 ( V_40 ) ;
if ( V_23 )
return V_23 ;
F_33 ( V_40 , F_34 ( & V_15 -> V_8 . V_16 -> V_19 ) ) ;
return 0 ;
}
