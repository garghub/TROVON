static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
int V_5 = - 1 ;
switch ( V_3 & V_6 ) {
case V_7 :
case V_8 :
V_5 = V_9 ;
break;
case V_10 :
V_5 = V_11 ;
break;
case V_12 :
V_5 = V_13 ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
if ( ! ( F_2 ( V_2 , F_4 ( V_17 ) ) & V_18 ) )
return 0 ;
if ( ! ( F_2 ( V_2 , V_4 ) & V_19 ) )
return 0 ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , int V_5 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
if ( F_6 ( V_5 < V_9 || V_5 >= V_20 ) )
return - V_21 ;
if ( F_2 ( V_2 , F_4 ( V_5 ) ) & V_18 )
return 1 ;
if ( F_3 ( V_2 ) &&
F_1 ( V_2 ) == V_5 )
return 1 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
F_2 ( V_2 , V_22 ) &= ~ ( V_23 |
V_24 |
V_25 ) ;
if ( F_8 ( V_15 ) )
F_2 ( V_2 , V_22 ) &= ~ ( V_26 |
V_27 ) ;
if ( F_9 ( V_2 , V_28 ) )
F_2 ( V_2 , V_22 ) |= V_23 ;
if ( F_9 ( V_2 , V_29 ) )
F_2 ( V_2 , V_22 ) |= V_24 ;
if ( F_9 ( V_2 , V_30 ) )
F_2 ( V_2 , V_22 ) |= V_25 ;
if ( F_8 ( V_15 ) &&
F_9 ( V_2 , V_31 ) ) {
F_2 ( V_2 , V_22 ) |= V_27 ;
}
if ( F_9 ( V_2 , V_32 ) ) {
if ( F_10 ( V_15 ) )
F_2 ( V_2 , V_33 ) |=
V_34 ;
else
F_2 ( V_2 , V_22 ) |= V_26 ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_35 )
{
struct V_36 * V_37 = V_36 ( V_2 , V_35 ) ;
F_12 ( V_37 -> V_38 ) ;
V_37 -> V_38 = NULL ;
F_12 ( V_37 -> V_39 ) ;
V_37 -> V_39 = NULL ;
}
static int F_13 ( struct V_1 * V_2 , int V_35 ,
int type )
{
struct V_36 * V_37 = V_36 ( V_2 , V_35 ) ;
V_37 -> V_38 = F_14 ( sizeof( * ( V_37 -> V_38 ) ) , V_40 ) ;
if ( ! V_37 -> V_38 )
return - V_41 ;
V_37 -> V_39 = F_14 ( sizeof( * ( V_37 -> V_39 ) ) , V_40 ) ;
if ( ! V_37 -> V_39 ) {
F_12 ( V_37 -> V_38 ) ;
return - V_41 ;
}
memcpy ( V_37 -> V_38 -> V_42 , V_43 ,
V_44 ) ;
V_37 -> V_38 -> V_45 = true ;
memcpy ( V_37 -> V_39 -> V_3 , V_46 , V_47 ) ;
V_37 -> V_39 -> V_45 = true ;
V_37 -> V_39 -> V_3 [ V_48 ] = 0x1 ;
V_37 -> type = type ;
F_7 ( V_2 ) ;
return 0 ;
}
void F_15 ( struct V_49 * V_16 )
{
struct V_50 * V_51 = & V_16 -> V_51 ;
struct V_1 * V_2 ;
bool V_52 = false ;
int V_5 , V_53 ;
if ( F_6 ( ! F_16 ( & V_16 -> V_54 ) ) )
return;
F_17 ( & V_51 -> V_55 . V_56 ) ;
F_18 (gvt, vgpu, id) {
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
V_52 =
F_5 ( V_2 , V_5 ) ;
if ( V_52 )
break;
}
}
if ( V_52 )
F_19 ( & V_51 -> V_55 . V_56 ,
F_20 ( F_21 () , V_51 -> V_55 . V_57 ) ,
V_58 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_5 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
struct V_59 * V_51 = & V_2 -> V_51 ;
int V_60 [] = {
[ V_9 ] = V_61 ,
[ V_11 ] = V_62 ,
[ V_13 ] = V_63 ,
} ;
int V_64 ;
if ( V_5 < V_9 || V_5 > V_13 )
return;
F_23 (event, irq->flip_done_event[pipe],
INTEL_GVT_EVENT_MAX) {
F_24 ( V_64 , V_51 -> V_65 [ V_5 ] ) ;
if ( ! F_5 ( V_2 , V_5 ) )
continue;
F_2 ( V_2 , F_25 ( V_5 ) ) ++ ;
F_26 ( V_2 , V_64 ) ;
}
if ( F_5 ( V_2 , V_5 ) ) {
F_2 ( V_2 , F_27 ( V_5 ) ) ++ ;
F_26 ( V_2 , V_60 [ V_5 ] ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
int V_5 ;
F_29 (vgpu->gvt->dev_priv, pipe)
F_22 ( V_2 , V_5 ) ;
}
void F_30 ( struct V_49 * V_16 )
{
struct V_1 * V_2 ;
int V_53 ;
if ( F_6 ( ! F_16 ( & V_16 -> V_54 ) ) )
return;
F_18 (gvt, vgpu, id)
F_28 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
if ( F_8 ( V_15 ) )
F_11 ( V_2 , V_30 ) ;
else
F_11 ( V_2 , V_28 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
F_33 ( V_2 ) ;
if ( F_8 ( V_15 ) )
return F_13 ( V_2 , V_30 , V_66 ) ;
else
return F_13 ( V_2 , V_28 , V_67 ) ;
}
