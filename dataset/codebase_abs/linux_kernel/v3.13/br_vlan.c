static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 == V_3 )
return;
F_2 () ;
V_2 -> V_4 = V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 != V_3 )
return;
F_2 () ;
V_2 -> V_4 = 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
if ( V_5 & V_6 )
F_1 ( V_2 , V_3 ) ;
if ( V_5 & V_7 )
F_5 ( V_3 , V_2 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
if ( F_7 ( V_3 , V_2 -> V_16 ) ) {
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
}
if ( V_2 -> V_17 ) {
V_10 = V_2 -> V_18 . V_19 ;
V_12 = V_10 -> V_12 ;
V_14 = V_10 -> V_14 ;
} else {
V_12 = V_2 -> V_18 . V_12 ;
V_14 = V_12 -> V_14 ;
}
if ( V_10 ) {
V_15 = F_8 ( V_14 , F_9 ( V_20 ) , V_3 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_10 ( V_12 , V_10 , V_14 -> V_21 , V_3 ) ;
if ( V_15 ) {
F_11 ( V_12 , L_1
L_2 ) ;
goto V_22;
}
F_5 ( V_3 , V_2 -> V_16 ) ;
V_2 -> V_23 ++ ;
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
V_22:
if ( V_10 )
F_12 ( V_14 , F_9 ( V_20 ) , V_3 ) ;
return V_15 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! F_7 ( V_3 , V_2 -> V_16 ) )
return - V_24 ;
F_3 ( V_2 , V_3 ) ;
F_14 ( V_3 , V_2 -> V_8 ) ;
if ( V_2 -> V_17 )
F_12 ( V_2 -> V_18 . V_19 -> V_14 , F_9 ( V_20 ) , V_3 ) ;
F_14 ( V_3 , V_2 -> V_16 ) ;
V_2 -> V_23 -- ;
if ( F_15 ( V_2 -> V_16 , V_25 ) ) {
if ( V_2 -> V_17 )
F_16 ( V_2 -> V_18 . V_19 -> V_26 , NULL ) ;
else
F_16 ( V_2 -> V_18 . V_12 -> V_26 , NULL ) ;
F_17 ( V_2 , V_27 ) ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_2 () ;
V_2 -> V_4 = 0 ;
F_19 ( V_2 -> V_16 , V_25 ) ;
if ( V_2 -> V_17 )
F_16 ( V_2 -> V_18 . V_19 -> V_26 , NULL ) ;
else
F_16 ( V_2 -> V_18 . V_12 -> V_26 , NULL ) ;
F_17 ( V_2 , V_27 ) ;
}
static struct V_28 * F_20 ( struct V_28 * V_29 )
{
if ( V_29 -> V_30 != F_9 ( V_20 ) ) {
V_29 -> V_31 = 0 ;
return V_29 ;
}
V_29 -> V_31 = 0 ;
V_29 = F_21 ( V_29 ) ;
if ( V_29 )
V_29 -> V_31 = 0 ;
return V_29 ;
}
struct V_28 * F_22 ( struct V_11 * V_12 ,
const struct V_1 * V_32 ,
struct V_28 * V_29 )
{
T_1 V_3 ;
if ( ! V_12 -> V_33 )
goto V_34;
F_23 ( V_29 , & V_3 ) ;
if ( F_7 ( V_3 , V_32 -> V_8 ) )
V_29 = F_20 ( V_29 ) ;
else {
if ( V_29 -> V_30 != F_9 ( V_20 ) &&
V_32 -> V_17 == 0 ) {
F_24 ( V_29 , V_35 ) ;
V_29 = F_25 ( V_29 , V_29 -> V_36 , V_29 -> V_31 ) ;
if ( ! V_29 )
goto V_34;
F_26 ( V_29 , V_35 ) ;
V_29 -> V_31 = 0 ;
}
}
V_34:
return V_29 ;
}
bool F_27 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_28 * V_29 , T_1 * V_3 )
{
int V_15 ;
if ( ! V_12 -> V_33 )
return true ;
if ( ! V_2 )
return false ;
V_15 = F_23 ( V_29 , V_3 ) ;
if ( ! * V_3 ) {
T_1 V_4 = F_28 ( V_2 ) ;
if ( V_4 == V_25 )
return false ;
* V_3 = V_4 ;
if ( F_29 ( V_15 ) )
F_30 ( V_29 , F_9 ( V_20 ) , V_4 ) ;
else
V_29 -> V_31 |= V_4 ;
return true ;
}
if ( F_7 ( * V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
bool F_31 ( struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_28 * V_29 )
{
T_1 V_3 ;
if ( ! V_12 -> V_33 )
return true ;
if ( ! V_2 )
return false ;
F_23 ( V_29 , & V_3 ) ;
if ( F_7 ( V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
int F_32 ( struct V_11 * V_12 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_32 = NULL ;
int V_15 ;
F_33 () ;
V_32 = F_34 ( V_12 -> V_26 ) ;
if ( V_32 )
return F_6 ( V_32 , V_3 , V_5 ) ;
V_32 = F_35 ( sizeof( * V_32 ) , V_37 ) ;
if ( ! V_32 )
return - V_38 ;
V_32 -> V_18 . V_12 = V_12 ;
V_15 = F_6 ( V_32 , V_3 , V_5 ) ;
if ( V_15 )
goto V_34;
F_16 ( V_12 -> V_26 , V_32 ) ;
return 0 ;
V_34:
F_36 ( V_32 ) ;
return V_15 ;
}
int F_37 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_32 ;
F_33 () ;
V_32 = F_34 ( V_12 -> V_26 ) ;
if ( ! V_32 )
return - V_24 ;
F_38 ( & V_12 -> V_39 ) ;
F_39 ( V_12 , V_12 -> V_14 -> V_21 , V_3 ) ;
F_40 ( & V_12 -> V_39 ) ;
F_13 ( V_32 , V_3 ) ;
return 0 ;
}
void F_41 ( struct V_11 * V_12 )
{
struct V_1 * V_32 ;
F_33 () ;
V_32 = F_34 ( V_12 -> V_26 ) ;
if ( ! V_32 )
return;
F_18 ( V_32 ) ;
}
int F_42 ( struct V_11 * V_12 , unsigned long V_40 )
{
if ( ! F_43 () )
return F_44 () ;
if ( V_12 -> V_33 == V_40 )
goto V_41;
V_12 -> V_33 = V_40 ;
V_41:
F_45 () ;
return 0 ;
}
int F_46 ( struct V_9 * V_19 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_32 = NULL ;
int V_15 ;
F_33 () ;
V_32 = F_34 ( V_19 -> V_26 ) ;
if ( V_32 )
return F_6 ( V_32 , V_3 , V_5 ) ;
V_32 = F_35 ( sizeof( * V_32 ) , V_37 ) ;
if ( ! V_32 ) {
V_15 = - V_38 ;
goto V_42;
}
V_32 -> V_17 = V_19 -> V_43 ;
V_32 -> V_18 . V_19 = V_19 ;
V_15 = F_6 ( V_32 , V_3 , V_5 ) ;
if ( V_15 )
goto V_42;
F_16 ( V_19 -> V_26 , V_32 ) ;
return 0 ;
V_42:
F_36 ( V_32 ) ;
return V_15 ;
}
int F_47 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_32 ;
F_33 () ;
V_32 = F_34 ( V_19 -> V_26 ) ;
if ( ! V_32 )
return - V_24 ;
F_38 ( & V_19 -> V_12 -> V_39 ) ;
F_39 ( V_19 -> V_12 , V_19 -> V_14 -> V_21 , V_3 ) ;
F_40 ( & V_19 -> V_12 -> V_39 ) ;
return F_13 ( V_32 , V_3 ) ;
}
void F_48 ( struct V_9 * V_19 )
{
struct V_1 * V_32 ;
T_1 V_3 ;
F_33 () ;
V_32 = F_34 ( V_19 -> V_26 ) ;
if ( ! V_32 )
return;
F_49 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_12 ( V_19 -> V_14 , F_9 ( V_20 ) , V_3 ) ;
F_18 ( V_32 ) ;
}
bool F_50 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_32 ;
bool V_44 = false ;
F_51 () ;
V_32 = F_52 ( V_19 -> V_26 ) ;
if ( ! V_32 )
goto V_34;
if ( F_7 ( V_3 , V_32 -> V_16 ) )
V_44 = true ;
V_34:
F_53 () ;
return V_44 ;
}
