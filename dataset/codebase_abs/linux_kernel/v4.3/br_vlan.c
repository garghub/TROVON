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
static int F_7 ( struct V_9 * V_10 , struct V_11 * V_12 ,
T_1 V_3 , T_1 V_5 )
{
const struct V_13 * V_14 = V_10 -> V_15 ;
int V_16 ;
if ( V_14 -> V_17 ) {
V_16 = F_8 ( V_10 , V_12 -> V_18 , V_3 ) ;
} else {
struct V_19 V_20 = {
. V_21 = V_22 ,
. V_23 . V_24 = {
. V_5 = V_5 ,
. V_25 = V_3 ,
. V_26 = V_3 ,
} ,
} ;
V_16 = F_9 ( V_10 , & V_20 ) ;
if ( V_16 == - V_27 )
V_16 = 0 ;
}
return V_16 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
struct V_28 * V_29 = NULL ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
int V_16 ;
if ( F_11 ( V_3 , V_2 -> V_30 ) ) {
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
}
if ( V_2 -> V_31 ) {
V_29 = V_2 -> V_32 . V_33 ;
V_12 = V_29 -> V_12 ;
V_10 = V_29 -> V_10 ;
} else {
V_12 = V_2 -> V_32 . V_12 ;
V_10 = V_12 -> V_10 ;
}
if ( V_29 ) {
V_16 = F_7 ( V_10 , V_12 , V_3 , V_5 ) ;
if ( V_16 )
return V_16 ;
}
V_16 = F_12 ( V_12 , V_29 , V_10 -> V_34 , V_3 ) ;
if ( V_16 ) {
F_13 ( V_12 , L_1
L_2 ) ;
goto V_35;
}
F_5 ( V_3 , V_2 -> V_30 ) ;
V_2 -> V_36 ++ ;
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
V_35:
if ( V_29 )
F_14 ( V_10 , V_12 -> V_18 , V_3 ) ;
return V_16 ;
}
static int F_15 ( struct V_9 * V_10 , struct V_11 * V_12 ,
T_1 V_3 )
{
const struct V_13 * V_14 = V_10 -> V_15 ;
int V_16 = 0 ;
if ( V_14 -> V_37 ) {
F_14 ( V_10 , V_12 -> V_18 , V_3 ) ;
} else {
struct V_19 V_20 = {
. V_21 = V_22 ,
. V_23 . V_24 = {
. V_25 = V_3 ,
. V_26 = V_3 ,
} ,
} ;
V_16 = F_16 ( V_10 , & V_20 ) ;
if ( V_16 == - V_27 )
V_16 = 0 ;
}
return V_16 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! F_11 ( V_3 , V_2 -> V_30 ) )
return - V_38 ;
F_3 ( V_2 , V_3 ) ;
F_6 ( V_3 , V_2 -> V_8 ) ;
if ( V_2 -> V_31 ) {
struct V_28 * V_29 = V_2 -> V_32 . V_33 ;
int V_16 ;
V_16 = F_15 ( V_29 -> V_10 , V_29 -> V_12 , V_3 ) ;
if ( V_16 )
return V_16 ;
}
F_6 ( V_3 , V_2 -> V_30 ) ;
V_2 -> V_36 -- ;
if ( F_18 ( V_2 -> V_30 , V_39 ) ) {
if ( V_2 -> V_31 )
F_19 ( V_2 -> V_32 . V_33 -> V_40 , NULL ) ;
else
F_19 ( V_2 -> V_32 . V_12 -> V_40 , NULL ) ;
F_20 ( V_2 , V_41 ) ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_2 () ;
V_2 -> V_4 = 0 ;
F_22 ( V_2 -> V_30 , V_39 ) ;
if ( V_2 -> V_31 )
F_19 ( V_2 -> V_32 . V_33 -> V_40 , NULL ) ;
else
F_19 ( V_2 -> V_32 . V_12 -> V_40 , NULL ) ;
F_20 ( V_2 , V_41 ) ;
}
struct V_42 * F_23 ( struct V_11 * V_12 ,
const struct V_1 * V_43 ,
struct V_42 * V_44 )
{
T_1 V_3 ;
if ( ! F_24 ( V_44 ) -> V_45 )
goto V_46;
if ( ! V_43 ) {
if ( ( V_12 -> V_10 -> V_5 & V_47 ) && V_44 -> V_10 == V_12 -> V_10 ) {
goto V_46;
} else {
F_25 ( V_44 ) ;
return NULL ;
}
}
F_26 ( V_44 , & V_3 ) ;
if ( F_11 ( V_3 , V_43 -> V_8 ) )
V_44 -> V_48 = 0 ;
V_46:
return V_44 ;
}
bool F_27 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_42 * V_44 , T_1 * V_3 )
{
bool V_49 ;
T_2 V_50 ;
if ( ! V_12 -> V_51 ) {
F_24 ( V_44 ) -> V_45 = false ;
return true ;
}
if ( ! V_2 )
goto V_52;
F_24 ( V_44 ) -> V_45 = true ;
V_50 = V_12 -> V_18 ;
if ( F_28 ( ! F_29 ( V_44 ) &&
V_44 -> V_53 == V_50 ) ) {
V_44 = F_30 ( V_44 ) ;
if ( F_28 ( ! V_44 ) )
return false ;
}
if ( ! F_26 ( V_44 , V_3 ) ) {
if ( V_44 -> V_18 != V_50 ) {
F_31 ( V_44 , V_54 ) ;
V_44 = F_32 ( V_44 , V_44 -> V_18 ,
F_33 ( V_44 ) ) ;
if ( F_28 ( ! V_44 ) )
return false ;
F_34 ( V_44 , V_54 ) ;
F_35 ( V_44 ) ;
* V_3 = 0 ;
V_49 = false ;
} else {
V_49 = true ;
}
} else {
V_49 = false ;
}
if ( ! * V_3 ) {
T_1 V_4 = F_36 ( V_2 ) ;
if ( ! V_4 )
goto V_52;
* V_3 = V_4 ;
if ( F_37 ( ! V_49 ) )
F_38 ( V_44 , V_50 , V_4 ) ;
else
V_44 -> V_48 |= V_4 ;
return true ;
}
if ( F_11 ( * V_3 , V_2 -> V_30 ) )
return true ;
V_52:
F_25 ( V_44 ) ;
return false ;
}
bool F_39 ( struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_42 * V_44 )
{
T_1 V_3 ;
if ( ! F_24 ( V_44 ) -> V_45 )
return true ;
if ( ! V_2 )
return false ;
F_26 ( V_44 , & V_3 ) ;
if ( F_11 ( V_3 , V_2 -> V_30 ) )
return true ;
return false ;
}
bool F_40 ( struct V_28 * V_29 , struct V_42 * V_44 , T_1 * V_3 )
{
struct V_11 * V_12 = V_29 -> V_12 ;
struct V_1 * V_2 ;
if ( ! V_12 -> V_51 )
return true ;
V_2 = F_41 ( V_29 -> V_40 ) ;
if ( ! V_2 )
return false ;
if ( ! F_26 ( V_44 , V_3 ) && V_44 -> V_18 != V_12 -> V_18 )
* V_3 = 0 ;
if ( ! * V_3 ) {
* V_3 = F_36 ( V_2 ) ;
if ( ! * V_3 )
return false ;
return true ;
}
if ( F_11 ( * V_3 , V_2 -> V_30 ) )
return true ;
return false ;
}
int F_42 ( struct V_11 * V_12 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_43 = NULL ;
int V_16 ;
F_43 () ;
V_43 = F_44 ( V_12 -> V_40 ) ;
if ( V_43 )
return F_10 ( V_43 , V_3 , V_5 ) ;
V_43 = F_45 ( sizeof( * V_43 ) , V_55 ) ;
if ( ! V_43 )
return - V_56 ;
V_43 -> V_32 . V_12 = V_12 ;
V_16 = F_10 ( V_43 , V_3 , V_5 ) ;
if ( V_16 )
goto V_46;
F_46 ( V_12 -> V_40 , V_43 ) ;
return 0 ;
V_46:
F_47 ( V_43 ) ;
return V_16 ;
}
int F_48 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_43 ;
F_43 () ;
V_43 = F_44 ( V_12 -> V_40 ) ;
if ( ! V_43 )
return - V_38 ;
F_49 ( V_12 , NULL , V_12 -> V_10 -> V_34 , V_3 ) ;
F_17 ( V_43 , V_3 ) ;
return 0 ;
}
void F_50 ( struct V_11 * V_12 )
{
struct V_1 * V_43 ;
F_43 () ;
V_43 = F_44 ( V_12 -> V_40 ) ;
if ( ! V_43 )
return;
F_21 ( V_43 ) ;
}
bool F_51 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_43 ;
bool V_57 = false ;
F_52 () ;
V_43 = F_41 ( V_12 -> V_40 ) ;
if ( ! V_43 )
goto V_46;
if ( F_11 ( V_3 , V_43 -> V_30 ) )
V_57 = true ;
V_46:
F_53 () ;
return V_57 ;
}
static void F_54 ( struct V_11 * V_12 )
{
if ( V_12 -> V_58 )
return;
F_55 ( & V_12 -> V_59 ) ;
if ( ! V_12 -> V_51 || V_12 -> V_18 == F_56 ( V_60 ) ) {
V_12 -> V_61 [ 5 ] = 0x00 ;
} else {
V_12 -> V_61 [ 5 ] = 0x08 ;
}
F_57 ( & V_12 -> V_59 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_51 || V_12 -> V_18 == F_56 ( V_60 ) )
V_12 -> V_62 = V_63 ;
else
V_12 -> V_62 = V_64 &
~ ( 1u << V_12 -> V_61 [ 5 ] ) ;
}
int F_59 ( struct V_11 * V_12 , unsigned long V_65 )
{
if ( V_12 -> V_51 == V_65 )
return 0 ;
V_12 -> V_51 = V_65 ;
F_60 ( V_12 ) ;
F_54 ( V_12 ) ;
F_58 ( V_12 ) ;
return 0 ;
}
int F_61 ( struct V_11 * V_12 , unsigned long V_65 )
{
if ( ! F_62 () )
return F_63 () ;
F_59 ( V_12 , V_65 ) ;
F_64 () ;
return 0 ;
}
int F_65 ( struct V_11 * V_12 , T_2 V_50 )
{
int V_16 = 0 ;
struct V_28 * V_29 ;
struct V_1 * V_43 ;
T_2 V_66 ;
T_1 V_3 , V_67 ;
if ( V_12 -> V_18 == V_50 )
return 0 ;
F_66 (p, &br->port_list, list) {
V_43 = F_44 ( V_29 -> V_40 ) ;
if ( ! V_43 )
continue;
F_67 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_16 = F_8 ( V_29 -> V_10 , V_50 , V_3 ) ;
if ( V_16 )
goto V_68;
}
}
V_66 = V_12 -> V_18 ;
V_12 -> V_18 = V_50 ;
F_54 ( V_12 ) ;
F_58 ( V_12 ) ;
F_66 (p, &br->port_list, list) {
V_43 = F_44 ( V_29 -> V_40 ) ;
if ( ! V_43 )
continue;
F_67 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_14 ( V_29 -> V_10 , V_66 , V_3 ) ;
}
return 0 ;
V_68:
V_67 = V_3 ;
F_67 (vid, pv->vlan_bitmap, errvid)
F_14 ( V_29 -> V_10 , V_50 , V_3 ) ;
F_68 (p, &br->port_list, list) {
V_43 = F_44 ( V_29 -> V_40 ) ;
if ( ! V_43 )
continue;
F_67 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_14 ( V_29 -> V_10 , V_50 , V_3 ) ;
}
return V_16 ;
}
int F_69 ( struct V_11 * V_12 , unsigned long V_65 )
{
int V_16 ;
if ( V_65 != V_60 && V_65 != V_69 )
return - V_70 ;
if ( ! F_62 () )
return F_63 () ;
V_16 = F_65 ( V_12 , F_56 ( V_65 ) ) ;
F_64 () ;
return V_16 ;
}
static bool F_70 ( struct V_1 * V_43 , T_1 V_3 )
{
return V_43 && V_3 == V_43 -> V_4 && F_11 ( V_3 , V_43 -> V_8 ) ;
}
static void F_71 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
T_1 V_4 = V_12 -> V_71 ;
if ( F_70 ( F_72 ( V_12 ) , V_4 ) )
F_48 ( V_12 , V_4 ) ;
F_66 (p, &br->port_list, list) {
if ( F_70 ( F_73 ( V_29 ) , V_4 ) )
F_74 ( V_29 , V_4 ) ;
}
V_12 -> V_71 = 0 ;
}
static int F_75 ( struct V_11 * V_12 , T_1 V_4 )
{
struct V_28 * V_29 ;
T_1 V_72 ;
int V_16 = 0 ;
unsigned long * V_73 ;
V_73 = F_76 ( F_77 ( V_74 ) , sizeof( unsigned long ) ,
V_55 ) ;
if ( ! V_73 )
return - V_56 ;
V_72 = V_12 -> V_71 ;
if ( ( ! V_72 || F_70 ( F_72 ( V_12 ) , V_72 ) ) &&
! F_51 ( V_12 , V_4 ) ) {
V_16 = F_42 ( V_12 , V_4 ,
V_6 |
V_7 ) ;
if ( V_16 )
goto V_46;
F_48 ( V_12 , V_72 ) ;
F_5 ( 0 , V_73 ) ;
}
F_66 (p, &br->port_list, list) {
if ( ( V_72 &&
! F_70 ( F_73 ( V_29 ) , V_72 ) ) ||
F_78 ( V_29 , V_4 ) )
continue;
V_16 = F_79 ( V_29 , V_4 ,
V_6 |
V_7 ) ;
if ( V_16 )
goto V_75;
F_74 ( V_29 , V_72 ) ;
F_5 ( V_29 -> V_76 , V_73 ) ;
}
V_12 -> V_71 = V_4 ;
V_46:
F_47 ( V_73 ) ;
return V_16 ;
V_75:
F_68 (p, &br->port_list, list) {
if ( ! F_11 ( V_29 -> V_76 , V_73 ) )
continue;
if ( V_72 )
F_79 ( V_29 , V_72 ,
V_6 |
V_7 ) ;
F_74 ( V_29 , V_4 ) ;
}
if ( F_11 ( 0 , V_73 ) ) {
if ( V_72 )
F_42 ( V_12 , V_72 ,
V_6 |
V_7 ) ;
F_48 ( V_12 , V_4 ) ;
}
goto V_46;
}
int F_80 ( struct V_11 * V_12 , unsigned long V_65 )
{
T_1 V_4 = V_65 ;
int V_16 = 0 ;
if ( V_65 >= V_77 )
return - V_38 ;
if ( ! F_62 () )
return F_63 () ;
if ( V_4 == V_12 -> V_71 )
goto V_78;
if ( V_12 -> V_51 ) {
F_81 ( L_3 ) ;
V_16 = - V_79 ;
goto V_78;
}
if ( ! V_4 )
F_71 ( V_12 ) ;
else
V_16 = F_75 ( V_12 , V_4 ) ;
V_78:
F_64 () ;
return V_16 ;
}
int F_82 ( struct V_11 * V_12 )
{
V_12 -> V_18 = F_56 ( V_60 ) ;
V_12 -> V_71 = 1 ;
return F_42 ( V_12 , 1 ,
V_6 | V_7 ) ;
}
int F_79 ( struct V_28 * V_33 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_43 = NULL ;
int V_16 ;
F_43 () ;
V_43 = F_44 ( V_33 -> V_40 ) ;
if ( V_43 )
return F_10 ( V_43 , V_3 , V_5 ) ;
V_43 = F_45 ( sizeof( * V_43 ) , V_55 ) ;
if ( ! V_43 ) {
V_16 = - V_56 ;
goto V_80;
}
V_43 -> V_31 = V_33 -> V_76 ;
V_43 -> V_32 . V_33 = V_33 ;
V_16 = F_10 ( V_43 , V_3 , V_5 ) ;
if ( V_16 )
goto V_80;
F_46 ( V_33 -> V_40 , V_43 ) ;
return 0 ;
V_80:
F_47 ( V_43 ) ;
return V_16 ;
}
int F_74 ( struct V_28 * V_33 , T_1 V_3 )
{
struct V_1 * V_43 ;
F_43 () ;
V_43 = F_44 ( V_33 -> V_40 ) ;
if ( ! V_43 )
return - V_38 ;
F_49 ( V_33 -> V_12 , V_33 , V_33 -> V_10 -> V_34 , V_3 ) ;
F_83 ( V_33 -> V_12 , V_33 , V_3 , 0 ) ;
return F_17 ( V_43 , V_3 ) ;
}
void F_84 ( struct V_28 * V_33 )
{
struct V_1 * V_43 ;
T_1 V_3 ;
F_43 () ;
V_43 = F_44 ( V_33 -> V_40 ) ;
if ( ! V_43 )
return;
F_67 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_14 ( V_33 -> V_10 , V_33 -> V_12 -> V_18 , V_3 ) ;
F_21 ( V_43 ) ;
}
bool F_78 ( struct V_28 * V_33 , T_1 V_3 )
{
struct V_1 * V_43 ;
bool V_57 = false ;
F_52 () ;
V_43 = F_41 ( V_33 -> V_40 ) ;
if ( ! V_43 )
goto V_46;
if ( F_11 ( V_3 , V_43 -> V_30 ) )
V_57 = true ;
V_46:
F_53 () ;
return V_57 ;
}
int F_85 ( struct V_28 * V_29 )
{
return V_29 -> V_12 -> V_71 ?
F_79 ( V_29 , V_29 -> V_12 -> V_71 ,
V_6 |
V_7 ) :
0 ;
}
