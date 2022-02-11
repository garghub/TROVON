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
else
F_3 ( V_2 , V_3 ) ;
if ( V_5 & V_7 )
F_5 ( V_3 , V_2 -> V_8 ) ;
else
F_6 ( V_3 , V_2 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
if ( F_8 ( V_3 , V_2 -> V_16 ) ) {
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
V_15 = F_9 ( V_14 , V_12 -> V_20 , V_3 ) ;
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
F_12 ( V_14 , V_12 -> V_20 , V_3 ) ;
return V_15 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! F_8 ( V_3 , V_2 -> V_16 ) )
return - V_24 ;
F_3 ( V_2 , V_3 ) ;
F_6 ( V_3 , V_2 -> V_8 ) ;
if ( V_2 -> V_17 ) {
struct V_9 * V_10 = V_2 -> V_18 . V_19 ;
F_12 ( V_10 -> V_14 , V_10 -> V_12 -> V_20 , V_3 ) ;
}
F_6 ( V_3 , V_2 -> V_16 ) ;
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
if ( ! F_20 ( V_30 ) -> V_31 )
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
if ( F_8 ( V_3 , V_29 -> V_8 ) )
V_30 -> V_34 = 0 ;
V_32:
return V_30 ;
}
bool F_23 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_28 * V_30 , T_1 * V_3 )
{
bool V_35 ;
T_2 V_36 ;
if ( ! V_12 -> V_37 ) {
F_20 ( V_30 ) -> V_31 = false ;
return true ;
}
if ( ! V_2 )
goto V_38;
F_20 ( V_30 ) -> V_31 = true ;
V_36 = V_12 -> V_20 ;
if ( F_24 ( ! F_25 ( V_30 ) &&
V_30 -> V_39 == V_36 ) ) {
V_30 = F_26 ( V_30 ) ;
if ( F_24 ( ! V_30 ) )
return false ;
}
if ( ! F_22 ( V_30 , V_3 ) ) {
if ( V_30 -> V_20 != V_36 ) {
F_27 ( V_30 , V_40 ) ;
V_30 = F_28 ( V_30 , V_30 -> V_20 ,
F_29 ( V_30 ) ) ;
if ( F_24 ( ! V_30 ) )
return false ;
F_30 ( V_30 , V_40 ) ;
F_31 ( V_30 ) ;
* V_3 = 0 ;
V_35 = false ;
} else {
V_35 = true ;
}
} else {
V_35 = false ;
}
if ( ! * V_3 ) {
T_1 V_4 = F_32 ( V_2 ) ;
if ( ! V_4 )
goto V_38;
* V_3 = V_4 ;
if ( F_33 ( ! V_35 ) )
F_34 ( V_30 , V_36 , V_4 ) ;
else
V_30 -> V_34 |= V_4 ;
return true ;
}
if ( F_8 ( * V_3 , V_2 -> V_16 ) )
return true ;
V_38:
F_21 ( V_30 ) ;
return false ;
}
bool F_35 ( struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_28 * V_30 )
{
T_1 V_3 ;
if ( ! F_20 ( V_30 ) -> V_31 )
return true ;
if ( ! V_2 )
return false ;
F_22 ( V_30 , & V_3 ) ;
if ( F_8 ( V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
bool F_36 ( struct V_9 * V_10 , struct V_28 * V_30 , T_1 * V_3 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_1 * V_2 ;
if ( ! V_12 -> V_37 )
return true ;
V_2 = F_37 ( V_10 -> V_26 ) ;
if ( ! V_2 )
return false ;
if ( ! F_22 ( V_30 , V_3 ) && V_30 -> V_20 != V_12 -> V_20 )
* V_3 = 0 ;
if ( ! * V_3 ) {
* V_3 = F_32 ( V_2 ) ;
if ( ! * V_3 )
return false ;
return true ;
}
if ( F_8 ( * V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
int F_38 ( struct V_11 * V_12 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_29 = NULL ;
int V_15 ;
F_39 () ;
V_29 = F_40 ( V_12 -> V_26 ) ;
if ( V_29 )
return F_7 ( V_29 , V_3 , V_5 ) ;
V_29 = F_41 ( sizeof( * V_29 ) , V_41 ) ;
if ( ! V_29 )
return - V_42 ;
V_29 -> V_18 . V_12 = V_12 ;
V_15 = F_7 ( V_29 , V_3 , V_5 ) ;
if ( V_15 )
goto V_32;
F_42 ( V_12 -> V_26 , V_29 ) ;
return 0 ;
V_32:
F_43 ( V_29 ) ;
return V_15 ;
}
int F_44 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_29 ;
F_39 () ;
V_29 = F_40 ( V_12 -> V_26 ) ;
if ( ! V_29 )
return - V_24 ;
F_45 ( V_12 , NULL , V_12 -> V_14 -> V_21 , V_3 ) ;
F_13 ( V_29 , V_3 ) ;
return 0 ;
}
void F_46 ( struct V_11 * V_12 )
{
struct V_1 * V_29 ;
F_39 () ;
V_29 = F_40 ( V_12 -> V_26 ) ;
if ( ! V_29 )
return;
F_17 ( V_29 ) ;
}
bool F_47 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_29 ;
bool V_43 = false ;
F_48 () ;
V_29 = F_37 ( V_12 -> V_26 ) ;
if ( ! V_29 )
goto V_32;
if ( F_8 ( V_3 , V_29 -> V_16 ) )
V_43 = true ;
V_32:
F_49 () ;
return V_43 ;
}
static void F_50 ( struct V_11 * V_12 )
{
if ( V_12 -> V_44 )
return;
F_51 ( & V_12 -> V_45 ) ;
if ( ! V_12 -> V_37 || V_12 -> V_20 == F_52 ( V_46 ) ) {
V_12 -> V_47 [ 5 ] = 0x00 ;
} else {
V_12 -> V_47 [ 5 ] = 0x08 ;
}
F_53 ( & V_12 -> V_45 ) ;
}
void F_54 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_37 || V_12 -> V_20 == F_52 ( V_46 ) )
V_12 -> V_48 = V_49 ;
else
V_12 -> V_48 = V_50 &
~ ( 1u << V_12 -> V_47 [ 5 ] ) ;
}
int F_55 ( struct V_11 * V_12 , unsigned long V_51 )
{
if ( ! F_56 () )
return F_57 () ;
if ( V_12 -> V_37 == V_51 )
goto V_52;
V_12 -> V_37 = V_51 ;
F_58 ( V_12 ) ;
F_50 ( V_12 ) ;
F_54 ( V_12 ) ;
V_52:
F_59 () ;
return 0 ;
}
int F_60 ( struct V_11 * V_12 , unsigned long V_51 )
{
int V_15 = 0 ;
struct V_9 * V_10 ;
struct V_1 * V_29 ;
T_2 V_36 , V_53 ;
T_1 V_3 , V_54 ;
if ( V_51 != V_46 && V_51 != V_55 )
return - V_56 ;
if ( ! F_56 () )
return F_57 () ;
V_36 = F_52 ( V_51 ) ;
if ( V_12 -> V_20 == V_36 )
goto V_52;
F_61 (p, &br->port_list, list) {
V_29 = F_40 ( V_10 -> V_26 ) ;
if ( ! V_29 )
continue;
F_62 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_15 = F_9 ( V_10 -> V_14 , V_36 , V_3 ) ;
if ( V_15 )
goto V_57;
}
}
V_53 = V_12 -> V_20 ;
V_12 -> V_20 = V_36 ;
F_50 ( V_12 ) ;
F_54 ( V_12 ) ;
F_61 (p, &br->port_list, list) {
V_29 = F_40 ( V_10 -> V_26 ) ;
if ( ! V_29 )
continue;
F_62 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_12 ( V_10 -> V_14 , V_53 , V_3 ) ;
}
V_52:
F_59 () ;
return V_15 ;
V_57:
V_54 = V_3 ;
F_62 (vid, pv->vlan_bitmap, errvid)
F_12 ( V_10 -> V_14 , V_36 , V_3 ) ;
F_63 (p, &br->port_list, list) {
V_29 = F_40 ( V_10 -> V_26 ) ;
if ( ! V_29 )
continue;
F_62 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_12 ( V_10 -> V_14 , V_36 , V_3 ) ;
}
goto V_52;
}
static bool F_64 ( struct V_1 * V_29 , T_1 V_3 )
{
return V_29 && V_3 == V_29 -> V_4 && F_8 ( V_3 , V_29 -> V_8 ) ;
}
static void F_65 ( struct V_11 * V_12 )
{
struct V_9 * V_10 ;
T_1 V_4 = V_12 -> V_58 ;
if ( F_64 ( F_66 ( V_12 ) , V_4 ) )
F_44 ( V_12 , V_4 ) ;
F_61 (p, &br->port_list, list) {
if ( F_64 ( F_67 ( V_10 ) , V_4 ) )
F_68 ( V_10 , V_4 ) ;
}
V_12 -> V_58 = 0 ;
}
static int F_69 ( struct V_11 * V_12 , T_1 V_4 )
{
struct V_9 * V_10 ;
T_1 V_59 ;
int V_15 = 0 ;
unsigned long * V_60 ;
V_60 = F_70 ( F_71 ( V_61 ) , sizeof( unsigned long ) ,
V_41 ) ;
if ( ! V_60 )
return - V_42 ;
V_59 = V_12 -> V_58 ;
if ( ( ! V_59 || F_64 ( F_66 ( V_12 ) , V_59 ) ) &&
! F_47 ( V_12 , V_4 ) ) {
V_15 = F_38 ( V_12 , V_4 ,
V_6 |
V_7 ) ;
if ( V_15 )
goto V_32;
F_44 ( V_12 , V_59 ) ;
F_5 ( 0 , V_60 ) ;
}
F_61 (p, &br->port_list, list) {
if ( ( V_59 &&
! F_64 ( F_67 ( V_10 ) , V_59 ) ) ||
F_72 ( V_10 , V_4 ) )
continue;
V_15 = F_73 ( V_10 , V_4 ,
V_6 |
V_7 ) ;
if ( V_15 )
goto V_62;
F_68 ( V_10 , V_59 ) ;
F_5 ( V_10 -> V_63 , V_60 ) ;
}
V_12 -> V_58 = V_4 ;
V_32:
F_43 ( V_60 ) ;
return V_15 ;
V_62:
F_63 (p, &br->port_list, list) {
if ( ! F_8 ( V_10 -> V_63 , V_60 ) )
continue;
if ( V_59 )
F_73 ( V_10 , V_59 ,
V_6 |
V_7 ) ;
F_68 ( V_10 , V_4 ) ;
}
if ( F_8 ( 0 , V_60 ) ) {
if ( V_59 )
F_38 ( V_12 , V_59 ,
V_6 |
V_7 ) ;
F_44 ( V_12 , V_4 ) ;
}
goto V_32;
}
int F_74 ( struct V_11 * V_12 , unsigned long V_51 )
{
T_1 V_4 = V_51 ;
int V_15 = 0 ;
if ( V_51 >= V_64 )
return - V_24 ;
if ( ! F_56 () )
return F_57 () ;
if ( V_4 == V_12 -> V_58 )
goto V_52;
if ( V_12 -> V_37 ) {
F_75 ( L_3 ) ;
V_15 = - V_65 ;
goto V_52;
}
if ( ! V_4 )
F_65 ( V_12 ) ;
else
V_15 = F_69 ( V_12 , V_4 ) ;
V_52:
F_59 () ;
return V_15 ;
}
int F_76 ( struct V_11 * V_12 )
{
V_12 -> V_20 = F_52 ( V_46 ) ;
V_12 -> V_58 = 1 ;
return F_38 ( V_12 , 1 ,
V_6 | V_7 ) ;
}
int F_73 ( struct V_9 * V_19 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_29 = NULL ;
int V_15 ;
F_39 () ;
V_29 = F_40 ( V_19 -> V_26 ) ;
if ( V_29 )
return F_7 ( V_29 , V_3 , V_5 ) ;
V_29 = F_41 ( sizeof( * V_29 ) , V_41 ) ;
if ( ! V_29 ) {
V_15 = - V_42 ;
goto V_66;
}
V_29 -> V_17 = V_19 -> V_63 ;
V_29 -> V_18 . V_19 = V_19 ;
V_15 = F_7 ( V_29 , V_3 , V_5 ) ;
if ( V_15 )
goto V_66;
F_42 ( V_19 -> V_26 , V_29 ) ;
return 0 ;
V_66:
F_43 ( V_29 ) ;
return V_15 ;
}
int F_68 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_29 ;
F_39 () ;
V_29 = F_40 ( V_19 -> V_26 ) ;
if ( ! V_29 )
return - V_24 ;
F_45 ( V_19 -> V_12 , V_19 , V_19 -> V_14 -> V_21 , V_3 ) ;
return F_13 ( V_29 , V_3 ) ;
}
void F_77 ( struct V_9 * V_19 )
{
struct V_1 * V_29 ;
T_1 V_3 ;
F_39 () ;
V_29 = F_40 ( V_19 -> V_26 ) ;
if ( ! V_29 )
return;
F_62 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_12 ( V_19 -> V_14 , V_19 -> V_12 -> V_20 , V_3 ) ;
F_17 ( V_29 ) ;
}
bool F_72 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_29 ;
bool V_43 = false ;
F_48 () ;
V_29 = F_37 ( V_19 -> V_26 ) ;
if ( ! V_29 )
goto V_32;
if ( F_8 ( V_3 , V_29 -> V_16 ) )
V_43 = true ;
V_32:
F_49 () ;
return V_43 ;
}
int F_78 ( struct V_9 * V_10 )
{
return V_10 -> V_12 -> V_58 ?
F_73 ( V_10 , V_10 -> V_12 -> V_58 ,
V_6 |
V_7 ) :
0 ;
}
