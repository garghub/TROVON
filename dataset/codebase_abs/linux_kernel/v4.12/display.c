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
if ( F_8 ( V_15 ) || F_9 ( V_15 ) ) {
F_2 ( V_2 , V_22 ) &= ~ ( V_26 |
V_27 ) ;
F_2 ( V_2 , V_28 ) |=
V_29 |
V_30 |
V_31 |
V_32 ;
F_2 ( V_2 , V_33 ) |=
V_34 |
V_35 ;
F_2 ( V_2 , V_36 ) |= V_34 ;
}
if ( F_10 ( V_2 , V_37 ) ) {
F_2 ( V_2 , V_38 ) |= V_39 ;
F_2 ( V_2 , F_11 ( V_40 ) ) &=
~ ( V_41 | V_42 |
V_43 ) ;
F_2 ( V_2 , F_11 ( V_40 ) ) |=
( V_44 | V_45 |
( V_37 << V_46 ) |
V_19 ) ;
F_2 ( V_2 , F_12 ( V_37 ) ) |= V_47 ;
F_2 ( V_2 , F_12 ( V_37 ) ) &= ~ V_48 ;
F_2 ( V_2 , V_22 ) |= V_23 ;
}
if ( F_10 ( V_2 , V_49 ) ) {
F_2 ( V_2 , V_22 ) |= V_24 ;
F_2 ( V_2 , F_11 ( V_40 ) ) &=
~ ( V_41 | V_42 |
V_43 ) ;
F_2 ( V_2 , F_11 ( V_40 ) ) |=
( V_44 | V_45 |
( V_49 << V_46 ) |
V_19 ) ;
F_2 ( V_2 , F_12 ( V_49 ) ) |= V_47 ;
F_2 ( V_2 , F_12 ( V_49 ) ) &= ~ V_48 ;
F_2 ( V_2 , V_38 ) |= V_50 ;
}
if ( F_10 ( V_2 , V_51 ) ) {
F_2 ( V_2 , V_22 ) |= V_25 ;
F_2 ( V_2 , F_11 ( V_40 ) ) &=
~ ( V_41 | V_42 |
V_43 ) ;
F_2 ( V_2 , F_11 ( V_40 ) ) |=
( V_44 | V_45 |
( V_51 << V_46 ) |
V_19 ) ;
F_2 ( V_2 , F_12 ( V_51 ) ) |= V_47 ;
F_2 ( V_2 , F_12 ( V_51 ) ) &= ~ V_48 ;
F_2 ( V_2 , V_38 ) |= V_52 ;
}
if ( ( F_8 ( V_15 ) || F_9 ( V_15 ) ) &&
F_10 ( V_2 , V_53 ) ) {
F_2 ( V_2 , V_22 ) |= V_27 ;
}
if ( F_10 ( V_2 , V_54 ) ) {
if ( F_13 ( V_15 ) )
F_2 ( V_2 , V_55 ) |=
V_56 ;
else
F_2 ( V_2 , V_22 ) |= V_26 ;
F_2 ( V_2 , F_12 ( V_54 ) ) |= V_57 ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_58 )
{
struct V_59 * V_60 = V_59 ( V_2 , V_58 ) ;
F_15 ( V_60 -> V_61 ) ;
V_60 -> V_61 = NULL ;
F_15 ( V_60 -> V_62 ) ;
V_60 -> V_62 = NULL ;
}
static int F_16 ( struct V_1 * V_2 , int V_58 ,
int type , unsigned int V_63 )
{
struct V_59 * V_60 = V_59 ( V_2 , V_58 ) ;
if ( F_6 ( V_63 >= V_64 ) )
return - V_21 ;
V_60 -> V_61 = F_17 ( sizeof( * ( V_60 -> V_61 ) ) , V_65 ) ;
if ( ! V_60 -> V_61 )
return - V_66 ;
V_60 -> V_62 = F_17 ( sizeof( * ( V_60 -> V_62 ) ) , V_65 ) ;
if ( ! V_60 -> V_62 ) {
F_15 ( V_60 -> V_61 ) ;
return - V_66 ;
}
memcpy ( V_60 -> V_61 -> V_67 , V_68 [ V_63 ] ,
V_69 ) ;
V_60 -> V_61 -> V_70 = true ;
memcpy ( V_60 -> V_62 -> V_3 , V_71 , V_72 ) ;
V_60 -> V_62 -> V_70 = true ;
V_60 -> V_62 -> V_3 [ V_73 ] = 0x1 ;
V_60 -> type = type ;
F_7 ( V_2 ) ;
return 0 ;
}
void F_18 ( struct V_74 * V_16 )
{
struct V_75 * V_76 = & V_16 -> V_76 ;
struct V_1 * V_2 ;
bool V_77 = false ;
int V_5 , V_78 ;
if ( F_6 ( ! F_19 ( & V_16 -> V_79 ) ) )
return;
F_20 ( & V_76 -> V_80 . V_81 ) ;
F_21 (gvt, vgpu, id) {
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
V_77 =
F_5 ( V_2 , V_5 ) ;
if ( V_77 )
break;
}
}
if ( V_77 )
F_22 ( & V_76 -> V_80 . V_81 ,
F_23 ( F_24 () , V_76 -> V_80 . V_82 ) ,
V_83 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_5 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
struct V_84 * V_76 = & V_2 -> V_76 ;
int V_85 [] = {
[ V_9 ] = V_86 ,
[ V_11 ] = V_87 ,
[ V_13 ] = V_88 ,
} ;
int V_89 ;
if ( V_5 < V_9 || V_5 > V_13 )
return;
F_26 (event, irq->flip_done_event[pipe],
INTEL_GVT_EVENT_MAX) {
F_27 ( V_89 , V_76 -> V_90 [ V_5 ] ) ;
if ( ! F_5 ( V_2 , V_5 ) )
continue;
F_2 ( V_2 , F_28 ( V_5 ) ) ++ ;
F_29 ( V_2 , V_89 ) ;
}
if ( F_5 ( V_2 , V_5 ) ) {
F_2 ( V_2 , F_30 ( V_5 ) ) ++ ;
F_29 ( V_2 , V_85 [ V_5 ] ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
int V_5 ;
F_32 (vgpu->gvt->dev_priv, pipe)
F_25 ( V_2 , V_5 ) ;
}
void F_33 ( struct V_74 * V_16 )
{
struct V_1 * V_2 ;
int V_78 ;
if ( F_6 ( ! F_19 ( & V_16 -> V_79 ) ) )
return;
F_21 (gvt, vgpu, id)
F_31 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
if ( F_8 ( V_15 ) || F_9 ( V_15 ) )
F_14 ( V_2 , V_51 ) ;
else
F_14 ( V_2 , V_37 ) ;
}
int F_35 ( struct V_1 * V_2 , T_2 V_63 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_15 ;
F_36 ( V_2 ) ;
if ( F_8 ( V_15 ) || F_9 ( V_15 ) )
return F_16 ( V_2 , V_51 , V_91 ,
V_63 ) ;
else
return F_16 ( V_2 , V_37 , V_92 ,
V_63 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
