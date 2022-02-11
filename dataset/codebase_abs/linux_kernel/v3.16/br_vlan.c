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
V_15 = F_8 ( V_14 , V_12 -> V_20 , V_3 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_9 ( V_12 , V_10 , V_14 -> V_21 , V_3 ) ;
if ( V_15 ) {
F_10 ( V_12 , L_1
L_2 ) ;
goto V_22;
}
F_5 ( V_3 , V_2 -> V_16 ) ;
V_2 -> V_23 ++ ;
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
V_22:
if ( V_10 )
F_11 ( V_14 , V_12 -> V_20 , V_3 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! F_7 ( V_3 , V_2 -> V_16 ) )
return - V_24 ;
F_3 ( V_2 , V_3 ) ;
F_13 ( V_3 , V_2 -> V_8 ) ;
if ( V_2 -> V_17 ) {
struct V_9 * V_10 = V_2 -> V_18 . V_19 ;
F_11 ( V_10 -> V_14 , V_10 -> V_12 -> V_20 , V_3 ) ;
}
F_13 ( V_3 , V_2 -> V_16 ) ;
V_2 -> V_23 -- ;
if ( F_14 ( V_2 -> V_16 , V_25 ) ) {
if ( V_2 -> V_17 )
F_15 ( V_2 -> V_18 . V_19 -> V_26 , NULL ) ;
else
F_15 ( V_2 -> V_18 . V_12 -> V_26 , NULL ) ;
F_16 ( V_2 , V_27 ) ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_2 () ;
V_2 -> V_4 = 0 ;
F_18 ( V_2 -> V_16 , V_25 ) ;
if ( V_2 -> V_17 )
F_15 ( V_2 -> V_18 . V_19 -> V_26 , NULL ) ;
else
F_15 ( V_2 -> V_18 . V_12 -> V_26 , NULL ) ;
F_16 ( V_2 , V_27 ) ;
}
struct V_28 * F_19 ( struct V_11 * V_12 ,
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
F_20 ( V_30 ) ;
return NULL ;
}
}
F_21 ( V_30 , & V_3 ) ;
if ( F_7 ( V_3 , V_29 -> V_8 ) )
V_30 -> V_34 = 0 ;
V_32:
return V_30 ;
}
bool F_22 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_28 * V_30 , T_1 * V_3 )
{
bool V_35 ;
T_2 V_36 ;
if ( ! V_12 -> V_31 )
return true ;
if ( ! V_2 )
goto V_37;
V_36 = V_12 -> V_20 ;
if ( F_23 ( ! F_24 ( V_30 ) &&
V_30 -> V_38 == V_36 ) ) {
V_30 = F_25 ( V_30 ) ;
if ( F_23 ( ! V_30 ) )
return false ;
}
if ( ! F_21 ( V_30 , V_3 ) ) {
if ( V_30 -> V_20 != V_36 ) {
F_26 ( V_30 , V_39 ) ;
V_30 = F_27 ( V_30 , V_30 -> V_20 ,
F_28 ( V_30 ) ) ;
if ( F_23 ( ! V_30 ) )
return false ;
F_29 ( V_30 , V_39 ) ;
F_30 ( V_30 ) ;
* V_3 = 0 ;
V_35 = false ;
} else {
V_35 = true ;
}
} else {
V_35 = false ;
}
if ( ! * V_3 ) {
T_1 V_4 = F_31 ( V_2 ) ;
if ( V_4 == V_25 )
goto V_37;
* V_3 = V_4 ;
if ( F_32 ( ! V_35 ) )
F_33 ( V_30 , V_36 , V_4 ) ;
else
V_30 -> V_34 |= V_4 ;
return true ;
}
if ( F_7 ( * V_3 , V_2 -> V_16 ) )
return true ;
V_37:
F_20 ( V_30 ) ;
return false ;
}
bool F_34 ( struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_28 * V_30 )
{
T_1 V_3 ;
if ( ! V_12 -> V_31 )
return true ;
if ( ! V_2 )
return false ;
F_21 ( V_30 , & V_3 ) ;
if ( F_7 ( V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
bool F_35 ( struct V_9 * V_10 , struct V_28 * V_30 , T_1 * V_3 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_1 * V_2 ;
if ( ! V_12 -> V_31 )
return true ;
V_2 = F_36 ( V_10 -> V_26 ) ;
if ( ! V_2 )
return false ;
if ( ! F_21 ( V_30 , V_3 ) && V_30 -> V_20 != V_12 -> V_20 )
* V_3 = 0 ;
if ( ! * V_3 ) {
* V_3 = F_31 ( V_2 ) ;
if ( * V_3 == V_25 )
return false ;
return true ;
}
if ( F_7 ( * V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
int F_37 ( struct V_11 * V_12 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_29 = NULL ;
int V_15 ;
F_38 () ;
V_29 = F_39 ( V_12 -> V_26 ) ;
if ( V_29 )
return F_6 ( V_29 , V_3 , V_5 ) ;
V_29 = F_40 ( sizeof( * V_29 ) , V_40 ) ;
if ( ! V_29 )
return - V_41 ;
V_29 -> V_18 . V_12 = V_12 ;
V_15 = F_6 ( V_29 , V_3 , V_5 ) ;
if ( V_15 )
goto V_32;
F_41 ( V_12 -> V_26 , V_29 ) ;
return 0 ;
V_32:
F_42 ( V_29 ) ;
return V_15 ;
}
int F_43 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_29 ;
F_38 () ;
V_29 = F_39 ( V_12 -> V_26 ) ;
if ( ! V_29 )
return - V_24 ;
F_44 ( V_12 , NULL , V_12 -> V_14 -> V_21 , V_3 ) ;
F_12 ( V_29 , V_3 ) ;
return 0 ;
}
void F_45 ( struct V_11 * V_12 )
{
struct V_1 * V_29 ;
F_38 () ;
V_29 = F_39 ( V_12 -> V_26 ) ;
if ( ! V_29 )
return;
F_17 ( V_29 ) ;
}
bool F_46 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_29 ;
bool V_42 = false ;
F_47 () ;
V_29 = F_36 ( V_12 -> V_26 ) ;
if ( ! V_29 )
goto V_32;
if ( F_7 ( V_3 , V_29 -> V_16 ) )
V_42 = true ;
V_32:
F_48 () ;
return V_42 ;
}
static void F_49 ( struct V_11 * V_12 )
{
if ( V_12 -> V_43 )
return;
F_50 ( & V_12 -> V_44 ) ;
if ( ! V_12 -> V_31 || V_12 -> V_20 == F_51 ( V_45 ) ) {
V_12 -> V_46 [ 5 ] = 0x00 ;
} else {
V_12 -> V_46 [ 5 ] = 0x08 ;
}
F_52 ( & V_12 -> V_44 ) ;
}
void F_53 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_31 || V_12 -> V_20 == F_51 ( V_45 ) )
V_12 -> V_47 = V_48 ;
else
V_12 -> V_47 = V_49 &
~ ( 1u << V_12 -> V_46 [ 5 ] ) ;
}
int F_54 ( struct V_11 * V_12 , unsigned long V_50 )
{
if ( ! F_55 () )
return F_56 () ;
if ( V_12 -> V_31 == V_50 )
goto V_51;
V_12 -> V_31 = V_50 ;
F_57 ( V_12 ) ;
F_49 ( V_12 ) ;
F_53 ( V_12 ) ;
V_51:
F_58 () ;
return 0 ;
}
int F_59 ( struct V_11 * V_12 , unsigned long V_50 )
{
int V_15 = 0 ;
struct V_9 * V_10 ;
struct V_1 * V_29 ;
T_2 V_36 , V_52 ;
T_1 V_3 , V_53 ;
if ( V_50 != V_45 && V_50 != V_54 )
return - V_55 ;
if ( ! F_55 () )
return F_56 () ;
V_36 = F_51 ( V_50 ) ;
if ( V_12 -> V_20 == V_36 )
goto V_51;
F_60 (p, &br->port_list, list) {
V_29 = F_39 ( V_10 -> V_26 ) ;
if ( ! V_29 )
continue;
F_61 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_15 = F_8 ( V_10 -> V_14 , V_36 , V_3 ) ;
if ( V_15 )
goto V_56;
}
}
V_52 = V_12 -> V_20 ;
V_12 -> V_20 = V_36 ;
F_49 ( V_12 ) ;
F_53 ( V_12 ) ;
F_60 (p, &br->port_list, list) {
V_29 = F_39 ( V_10 -> V_26 ) ;
if ( ! V_29 )
continue;
F_61 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_11 ( V_10 -> V_14 , V_52 , V_3 ) ;
}
V_51:
F_58 () ;
return V_15 ;
V_56:
V_53 = V_3 ;
F_61 (vid, pv->vlan_bitmap, errvid)
F_11 ( V_10 -> V_14 , V_36 , V_3 ) ;
F_62 (p, &br->port_list, list) {
V_29 = F_39 ( V_10 -> V_26 ) ;
if ( ! V_29 )
continue;
F_61 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_11 ( V_10 -> V_14 , V_36 , V_3 ) ;
}
goto V_51;
}
void F_63 ( struct V_11 * V_12 )
{
V_12 -> V_20 = F_51 ( V_45 ) ;
}
int F_64 ( struct V_9 * V_19 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_29 = NULL ;
int V_15 ;
F_38 () ;
V_29 = F_39 ( V_19 -> V_26 ) ;
if ( V_29 )
return F_6 ( V_29 , V_3 , V_5 ) ;
V_29 = F_40 ( sizeof( * V_29 ) , V_40 ) ;
if ( ! V_29 ) {
V_15 = - V_41 ;
goto V_57;
}
V_29 -> V_17 = V_19 -> V_58 ;
V_29 -> V_18 . V_19 = V_19 ;
V_15 = F_6 ( V_29 , V_3 , V_5 ) ;
if ( V_15 )
goto V_57;
F_41 ( V_19 -> V_26 , V_29 ) ;
return 0 ;
V_57:
F_42 ( V_29 ) ;
return V_15 ;
}
int F_65 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_29 ;
F_38 () ;
V_29 = F_39 ( V_19 -> V_26 ) ;
if ( ! V_29 )
return - V_24 ;
F_44 ( V_19 -> V_12 , V_19 , V_19 -> V_14 -> V_21 , V_3 ) ;
return F_12 ( V_29 , V_3 ) ;
}
void F_66 ( struct V_9 * V_19 )
{
struct V_1 * V_29 ;
T_1 V_3 ;
F_38 () ;
V_29 = F_39 ( V_19 -> V_26 ) ;
if ( ! V_29 )
return;
F_61 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_11 ( V_19 -> V_14 , V_19 -> V_12 -> V_20 , V_3 ) ;
F_17 ( V_29 ) ;
}
bool F_67 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_29 ;
bool V_42 = false ;
F_47 () ;
V_29 = F_36 ( V_19 -> V_26 ) ;
if ( ! V_29 )
goto V_32;
if ( F_7 ( V_3 , V_29 -> V_16 ) )
V_42 = true ;
V_32:
F_48 () ;
return V_42 ;
}
