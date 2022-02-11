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
struct V_28 * F_20 ( struct V_11 * V_12 ,
const struct V_1 * V_29 ,
struct V_28 * V_30 )
{
T_1 V_3 ;
if ( ! V_12 -> V_31 )
goto V_32;
if ( ! V_29 ) {
if ( ( V_12 -> V_14 -> V_5 & V_33 ) && V_30 -> V_14 == V_12 -> V_14 ) {
goto V_32;
} else {
F_21 ( V_30 ) ;
return NULL ;
}
}
F_22 ( V_30 , & V_3 ) ;
if ( F_7 ( V_3 , V_29 -> V_8 ) )
V_30 -> V_34 = 0 ;
V_32:
return V_30 ;
}
bool F_23 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_28 * V_30 , T_1 * V_3 )
{
int V_15 ;
if ( ! V_12 -> V_31 )
return true ;
if ( ! V_2 )
goto V_35;
if ( F_24 ( ! F_25 ( V_30 ) &&
( V_30 -> V_36 == F_9 ( V_20 ) ||
V_30 -> V_36 == F_9 ( V_37 ) ) ) ) {
V_30 = F_26 ( V_30 ) ;
if ( F_24 ( ! V_30 ) )
return false ;
}
V_15 = F_22 ( V_30 , V_3 ) ;
if ( ! * V_3 ) {
T_1 V_4 = F_27 ( V_2 ) ;
if ( V_4 == V_25 )
goto V_35;
* V_3 = V_4 ;
if ( F_28 ( V_15 ) )
F_29 ( V_30 , F_9 ( V_20 ) , V_4 ) ;
else
V_30 -> V_34 |= V_4 ;
return true ;
}
if ( F_7 ( * V_3 , V_2 -> V_16 ) )
return true ;
V_35:
F_21 ( V_30 ) ;
return false ;
}
bool F_30 ( struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_28 * V_30 )
{
T_1 V_3 ;
if ( ! V_12 -> V_31 )
return true ;
if ( ! V_2 )
return false ;
F_22 ( V_30 , & V_3 ) ;
if ( F_7 ( V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
bool F_31 ( struct V_9 * V_10 , struct V_28 * V_30 , T_1 * V_3 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_1 * V_2 ;
if ( ! V_12 -> V_31 )
return true ;
V_2 = F_32 ( V_10 -> V_26 ) ;
if ( ! V_2 )
return false ;
F_22 ( V_30 , V_3 ) ;
if ( ! * V_3 ) {
* V_3 = F_27 ( V_2 ) ;
if ( * V_3 == V_25 )
return false ;
return true ;
}
if ( F_7 ( * V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
int F_33 ( struct V_11 * V_12 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_29 = NULL ;
int V_15 ;
F_34 () ;
V_29 = F_35 ( V_12 -> V_26 ) ;
if ( V_29 )
return F_6 ( V_29 , V_3 , V_5 ) ;
V_29 = F_36 ( sizeof( * V_29 ) , V_38 ) ;
if ( ! V_29 )
return - V_39 ;
V_29 -> V_18 . V_12 = V_12 ;
V_15 = F_6 ( V_29 , V_3 , V_5 ) ;
if ( V_15 )
goto V_32;
F_37 ( V_12 -> V_26 , V_29 ) ;
return 0 ;
V_32:
F_38 ( V_29 ) ;
return V_15 ;
}
int F_39 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_29 ;
F_34 () ;
V_29 = F_35 ( V_12 -> V_26 ) ;
if ( ! V_29 )
return - V_24 ;
F_40 ( V_12 , NULL , V_12 -> V_14 -> V_21 , V_3 ) ;
F_13 ( V_29 , V_3 ) ;
return 0 ;
}
void F_41 ( struct V_11 * V_12 )
{
struct V_1 * V_29 ;
F_34 () ;
V_29 = F_35 ( V_12 -> V_26 ) ;
if ( ! V_29 )
return;
F_18 ( V_29 ) ;
}
bool F_42 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_29 ;
bool V_40 = false ;
F_43 () ;
V_29 = F_32 ( V_12 -> V_26 ) ;
if ( ! V_29 )
goto V_32;
if ( F_7 ( V_3 , V_29 -> V_16 ) )
V_40 = true ;
V_32:
F_44 () ;
return V_40 ;
}
int F_45 ( struct V_11 * V_12 , unsigned long V_41 )
{
if ( ! F_46 () )
return F_47 () ;
if ( V_12 -> V_31 == V_41 )
goto V_42;
V_12 -> V_31 = V_41 ;
V_42:
F_48 () ;
return 0 ;
}
int F_49 ( struct V_9 * V_19 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_29 = NULL ;
int V_15 ;
F_34 () ;
V_29 = F_35 ( V_19 -> V_26 ) ;
if ( V_29 )
return F_6 ( V_29 , V_3 , V_5 ) ;
V_29 = F_36 ( sizeof( * V_29 ) , V_38 ) ;
if ( ! V_29 ) {
V_15 = - V_39 ;
goto V_43;
}
V_29 -> V_17 = V_19 -> V_44 ;
V_29 -> V_18 . V_19 = V_19 ;
V_15 = F_6 ( V_29 , V_3 , V_5 ) ;
if ( V_15 )
goto V_43;
F_37 ( V_19 -> V_26 , V_29 ) ;
return 0 ;
V_43:
F_38 ( V_29 ) ;
return V_15 ;
}
int F_50 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_29 ;
F_34 () ;
V_29 = F_35 ( V_19 -> V_26 ) ;
if ( ! V_29 )
return - V_24 ;
F_40 ( V_19 -> V_12 , V_19 , V_19 -> V_14 -> V_21 , V_3 ) ;
return F_13 ( V_29 , V_3 ) ;
}
void F_51 ( struct V_9 * V_19 )
{
struct V_1 * V_29 ;
T_1 V_3 ;
F_34 () ;
V_29 = F_35 ( V_19 -> V_26 ) ;
if ( ! V_29 )
return;
F_52 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_12 ( V_19 -> V_14 , F_9 ( V_20 ) , V_3 ) ;
F_18 ( V_29 ) ;
}
bool F_53 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_29 ;
bool V_40 = false ;
F_43 () ;
V_29 = F_32 ( V_19 -> V_26 ) ;
if ( ! V_29 )
goto V_32;
if ( F_7 ( V_3 , V_29 -> V_16 ) )
V_40 = true ;
V_32:
F_44 () ;
return V_40 ;
}
