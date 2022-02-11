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
if ( F_9 ( V_2 , V_28 ) ) {
F_2 ( V_2 , V_22 ) |= V_23 ;
F_2 ( V_2 , V_29 ) |= V_30 ;
}
if ( F_9 ( V_2 , V_31 ) ) {
F_2 ( V_2 , V_22 ) |= V_24 ;
F_2 ( V_2 , V_29 ) |= V_32 ;
}
if ( F_9 ( V_2 , V_33 ) ) {
F_2 ( V_2 , V_22 ) |= V_25 ;
F_2 ( V_2 , V_29 ) |= V_34 ;
}
if ( F_8 ( V_15 ) &&
F_9 ( V_2 , V_35 ) ) {
F_2 ( V_2 , V_22 ) |= V_27 ;
}
if ( F_9 ( V_2 , V_36 ) ) {
if ( F_10 ( V_15 ) )
F_2 ( V_2 , V_37 ) |=
V_38 ;
else
F_2 ( V_2 , V_22 ) |= V_26 ;
F_2 ( V_2 , F_11 ( V_36 ) ) |= V_39 ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_40 )
{
struct V_41 * V_42 = V_41 ( V_2 , V_40 ) ;
F_13 ( V_42 -> V_43 ) ;
V_42 -> V_43 = NULL ;
F_13 ( V_42 -> V_44 ) ;
V_42 -> V_44 = NULL ;
}
static int F_14 ( struct V_1 * V_2 , int V_40 ,
int type , unsigned int V_45 )
{
struct V_41 * V_42 = V_41 ( V_2 , V_40 ) ;
if ( F_6 ( V_45 >= V_46 ) )
return - V_21 ;
V_42 -> V_43 = F_15 ( sizeof( * ( V_42 -> V_43 ) ) , V_47 ) ;
if ( ! V_42 -> V_43 )
return - V_48 ;
V_42 -> V_44 = F_15 ( sizeof( * ( V_42 -> V_44 ) ) , V_47 ) ;
if ( ! V_42 -> V_44 ) {
F_13 ( V_42 -> V_43 ) ;
return - V_48 ;
}
memcpy ( V_42 -> V_43 -> V_49 , V_50 [ V_45 ] ,
V_51 ) ;
V_42 -> V_43 -> V_52 = true ;
memcpy ( V_42 -> V_44 -> V_3 , V_53 , V_54 ) ;
V_42 -> V_44 -> V_52 = true ;
V_42 -> V_44 -> V_3 [ V_55 ] = 0x1 ;
V_42 -> type = type ;
F_7 ( V_2 ) ;
return 0 ;
}
void F_16 ( struct V_56 * V_16 )
{
struct V_57 * V_58 = & V_16 -> V_58 ;
struct V_1 * V_2 ;
bool V_59 = false ;
int V_5 , V_60 ;
if ( F_6 ( ! F_17 ( & V_16 -> V_61 ) ) )
return;
F_18 ( & V_58 -> V_62 . V_63 ) ;
F_19 (gvt, vgpu, id) {
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
V_59 =
F_5 ( V_2 , V_5 ) ;
if ( V_59 )
break;
}
}
if ( V_59 )
F_20 ( & V_58 -> V_62 . V_63 ,
F_21 ( F_22 () , V_58 -> V_62 . V_64 ) ,
V_65 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_5 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
struct V_66 * V_58 = & V_2 -> V_58 ;
int V_67 [] = {
[ V_9 ] = V_68 ,
[ V_11 ] = V_69 ,
[ V_13 ] = V_70 ,
} ;
int V_71 ;
if ( V_5 < V_9 || V_5 > V_13 )
return;
F_24 (event, irq->flip_done_event[pipe],
INTEL_GVT_EVENT_MAX) {
F_25 ( V_71 , V_58 -> V_72 [ V_5 ] ) ;
if ( ! F_5 ( V_2 , V_5 ) )
continue;
F_2 ( V_2 , F_26 ( V_5 ) ) ++ ;
F_27 ( V_2 , V_71 ) ;
}
if ( F_5 ( V_2 , V_5 ) ) {
F_2 ( V_2 , F_28 ( V_5 ) ) ++ ;
F_27 ( V_2 , V_67 [ V_5 ] ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
int V_5 ;
F_30 (vgpu->gvt->dev_priv, pipe)
F_23 ( V_2 , V_5 ) ;
}
void F_31 ( struct V_56 * V_16 )
{
struct V_1 * V_2 ;
int V_60 ;
if ( F_6 ( ! F_17 ( & V_16 -> V_61 ) ) )
return;
F_19 (gvt, vgpu, id)
F_29 ( V_2 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
if ( F_8 ( V_15 ) )
F_12 ( V_2 , V_33 ) ;
else
F_12 ( V_2 , V_28 ) ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_45 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
F_34 ( V_2 ) ;
if ( F_8 ( V_15 ) )
return F_14 ( V_2 , V_33 , V_73 ,
V_45 ) ;
else
return F_14 ( V_2 , V_28 , V_74 ,
V_45 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
