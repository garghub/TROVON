static inline int F_1 ( struct V_1 * V_2 ,
const void * V_3 )
{
const struct V_4 * V_5 = V_3 ;
T_1 V_6 = * ( T_1 * ) V_2 -> V_7 ;
return V_5 -> V_6 != V_6 ;
}
static struct V_4 * F_2 ( struct V_8 * V_9 , T_1 V_6 )
{
return F_3 ( V_9 , & V_6 , V_10 ) ;
}
static void F_4 ( struct V_11 * V_12 , T_1 V_6 )
{
if ( V_12 -> V_13 == V_6 )
return;
F_5 () ;
V_12 -> V_13 = V_6 ;
}
static void F_6 ( struct V_11 * V_12 , T_1 V_6 )
{
if ( V_12 -> V_13 != V_6 )
return;
F_5 () ;
V_12 -> V_13 = 0 ;
}
static void F_7 ( struct V_4 * V_14 , T_1 V_15 )
{
struct V_11 * V_12 ;
if ( F_8 ( V_14 ) )
V_12 = F_9 ( V_14 -> V_16 ) ;
else
V_12 = F_10 ( V_14 -> V_17 ) ;
if ( V_15 & V_18 )
F_4 ( V_12 , V_14 -> V_6 ) ;
else
F_6 ( V_12 , V_14 -> V_6 ) ;
if ( V_15 & V_19 )
V_14 -> V_15 |= V_19 ;
else
V_14 -> V_15 &= ~ V_19 ;
}
static int F_11 ( struct V_20 * V_21 , struct V_22 * V_16 ,
T_1 V_6 , T_1 V_15 )
{
struct V_23 V_14 = {
. V_24 . V_25 = V_21 ,
. V_24 . V_26 = V_27 ,
. V_15 = V_15 ,
. V_28 = V_6 ,
. V_29 = V_6 ,
} ;
int V_30 ;
V_30 = F_12 ( V_21 , & V_14 . V_24 ) ;
if ( V_30 == - V_31 )
return F_13 ( V_21 , V_16 -> V_32 , V_6 ) ;
return V_30 ;
}
static void F_14 ( struct V_4 * V_14 )
{
struct V_11 * V_12 ;
struct V_33 * V_34 , * V_35 ;
struct V_4 * V_36 ;
if ( F_8 ( V_14 ) )
V_12 = F_9 ( V_14 -> V_16 ) ;
else
V_12 = F_10 ( V_14 -> V_17 ) ;
V_34 = & V_12 -> V_37 ;
F_15 (hpos, headp) {
V_36 = F_16 ( V_35 , struct V_4 , V_38 ) ;
if ( V_14 -> V_6 < V_36 -> V_6 )
continue;
else
break;
}
F_17 ( & V_14 -> V_38 , V_35 ) ;
}
static void F_18 ( struct V_4 * V_14 )
{
F_19 ( & V_14 -> V_38 ) ;
}
static int F_20 ( struct V_20 * V_21 , struct V_22 * V_16 ,
T_1 V_6 )
{
struct V_23 V_14 = {
. V_24 . V_25 = V_21 ,
. V_24 . V_26 = V_27 ,
. V_28 = V_6 ,
. V_29 = V_6 ,
} ;
int V_30 ;
V_30 = F_21 ( V_21 , & V_14 . V_24 ) ;
if ( V_30 == - V_31 ) {
F_22 ( V_21 , V_16 -> V_32 , V_6 ) ;
return 0 ;
}
return V_30 ;
}
static struct V_4 * F_23 ( struct V_22 * V_16 , T_1 V_6 )
{
struct V_11 * V_12 ;
struct V_4 * V_39 ;
V_12 = F_9 ( V_16 ) ;
V_39 = F_24 ( V_12 , V_6 ) ;
if ( ! V_39 ) {
if ( F_25 ( V_16 , V_6 , 0 ) )
return NULL ;
V_39 = F_24 ( V_12 , V_6 ) ;
if ( F_26 ( ! V_39 ) )
return NULL ;
}
F_27 ( & V_39 -> V_40 ) ;
return V_39 ;
}
static void F_28 ( struct V_4 * V_39 )
{
struct V_11 * V_12 ;
if ( ! F_8 ( V_39 ) )
return;
V_12 = F_9 ( V_39 -> V_16 ) ;
if ( F_29 ( & V_39 -> V_40 ) ) {
F_30 ( & V_12 -> V_41 ,
& V_39 -> V_42 , V_10 ) ;
F_18 ( V_39 ) ;
F_31 ( V_39 , V_43 ) ;
}
}
static int F_32 ( struct V_4 * V_14 , T_1 V_15 )
{
struct V_4 * V_39 = NULL ;
struct V_44 * V_45 = NULL ;
struct V_11 * V_12 ;
struct V_20 * V_21 ;
struct V_22 * V_16 ;
int V_30 ;
if ( F_8 ( V_14 ) ) {
V_16 = V_14 -> V_16 ;
V_21 = V_16 -> V_21 ;
V_12 = F_9 ( V_16 ) ;
} else {
V_45 = V_14 -> V_17 ;
V_16 = V_45 -> V_16 ;
V_21 = V_45 -> V_21 ;
V_12 = F_10 ( V_45 ) ;
}
if ( V_45 ) {
V_30 = F_11 ( V_21 , V_16 , V_14 -> V_6 , V_15 ) ;
if ( V_30 )
goto V_46;
if ( V_15 & V_47 ) {
V_30 = F_25 ( V_16 , V_14 -> V_6 , V_15 |
V_48 ) ;
if ( V_30 )
goto V_49;
}
V_39 = F_23 ( V_16 , V_14 -> V_6 ) ;
if ( ! V_39 )
goto V_49;
V_14 -> V_50 = V_39 ;
}
if ( F_33 ( V_14 ) ) {
V_30 = F_34 ( V_16 , V_45 , V_21 -> V_51 , V_14 -> V_6 ) ;
if ( V_30 ) {
F_35 ( V_16 , L_1 ) ;
goto V_49;
}
V_12 -> V_52 ++ ;
}
V_30 = F_36 ( & V_12 -> V_41 , & V_14 -> V_42 ,
V_10 ) ;
if ( V_30 )
goto V_53;
F_14 ( V_14 ) ;
F_7 ( V_14 , V_15 ) ;
V_46:
return V_30 ;
V_53:
if ( F_33 ( V_14 ) ) {
F_37 ( V_16 , V_45 , V_21 -> V_51 , V_14 -> V_6 ) ;
V_12 -> V_52 -- ;
}
V_49:
if ( V_45 ) {
F_20 ( V_21 , V_16 , V_14 -> V_6 ) ;
if ( V_39 ) {
F_28 ( V_39 ) ;
V_14 -> V_50 = NULL ;
}
}
goto V_46;
}
static int F_38 ( struct V_4 * V_14 )
{
struct V_4 * V_39 = V_14 ;
struct V_11 * V_12 ;
struct V_44 * V_45 = NULL ;
int V_30 = 0 ;
if ( F_8 ( V_14 ) ) {
V_12 = F_9 ( V_14 -> V_16 ) ;
} else {
V_45 = V_14 -> V_17 ;
V_12 = F_10 ( V_14 -> V_17 ) ;
V_39 = V_14 -> V_50 ;
}
F_6 ( V_12 , V_14 -> V_6 ) ;
if ( V_45 ) {
V_30 = F_20 ( V_45 -> V_21 , V_45 -> V_16 , V_14 -> V_6 ) ;
if ( V_30 )
goto V_46;
}
if ( F_33 ( V_14 ) ) {
V_14 -> V_15 &= ~ V_48 ;
V_12 -> V_52 -- ;
}
if ( V_39 != V_14 ) {
F_30 ( & V_12 -> V_41 , & V_14 -> V_42 ,
V_10 ) ;
F_18 ( V_14 ) ;
F_31 ( V_14 , V_43 ) ;
}
F_28 ( V_39 ) ;
V_46:
return V_30 ;
}
static void F_39 ( struct V_11 * V_12 )
{
F_26 ( ! F_40 ( & V_12 -> V_37 ) ) ;
F_41 ( & V_12 -> V_41 ) ;
F_42 ( V_12 ) ;
}
static void F_43 ( struct V_11 * V_12 )
{
struct V_4 * V_54 , * V_55 ;
F_6 ( V_12 , V_12 -> V_13 ) ;
F_44 (vlan, tmp, &vg->vlan_list, vlist)
F_38 ( V_54 ) ;
}
struct V_56 * F_45 ( struct V_22 * V_16 ,
struct V_11 * V_12 ,
struct V_56 * V_57 )
{
struct V_4 * V_14 ;
T_1 V_6 ;
if ( ! F_46 ( V_57 ) -> V_58 )
goto V_46;
F_47 ( V_57 , & V_6 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( ! V_14 || ! F_33 ( V_14 ) ) {
if ( ( V_16 -> V_21 -> V_15 & V_59 ) && V_57 -> V_21 == V_16 -> V_21 ) {
goto V_46;
} else {
F_48 ( V_57 ) ;
return NULL ;
}
}
if ( V_14 -> V_15 & V_19 )
V_57 -> V_60 = 0 ;
V_46:
return V_57 ;
}
static bool F_49 ( struct V_11 * V_12 , T_2 V_61 ,
struct V_56 * V_57 , T_1 * V_6 )
{
const struct V_4 * V_14 ;
bool V_62 ;
F_46 ( V_57 ) -> V_58 = true ;
if ( F_50 ( ! F_51 ( V_57 ) &&
V_57 -> V_63 == V_61 ) ) {
V_57 = F_52 ( V_57 ) ;
if ( F_50 ( ! V_57 ) )
return false ;
}
if ( ! F_47 ( V_57 , V_6 ) ) {
if ( V_57 -> V_32 != V_61 ) {
F_53 ( V_57 , V_64 ) ;
V_57 = F_54 ( V_57 , V_57 -> V_32 ,
F_55 ( V_57 ) ) ;
if ( F_50 ( ! V_57 ) )
return false ;
F_56 ( V_57 , V_64 ) ;
F_57 ( V_57 ) ;
* V_6 = 0 ;
V_62 = false ;
} else {
V_62 = true ;
}
} else {
V_62 = false ;
}
if ( ! * V_6 ) {
T_1 V_13 = F_58 ( V_12 ) ;
if ( ! V_13 )
goto V_65;
* V_6 = V_13 ;
if ( F_59 ( ! V_62 ) )
F_60 ( V_57 , V_61 , V_13 ) ;
else
V_57 -> V_60 |= V_13 ;
return true ;
}
V_14 = F_24 ( V_12 , * V_6 ) ;
if ( V_14 && F_33 ( V_14 ) )
return true ;
V_65:
F_48 ( V_57 ) ;
return false ;
}
bool F_61 ( const struct V_22 * V_16 ,
struct V_11 * V_12 , struct V_56 * V_57 ,
T_1 * V_6 )
{
if ( ! V_16 -> V_66 ) {
F_46 ( V_57 ) -> V_58 = false ;
return true ;
}
return F_49 ( V_12 , V_16 -> V_32 , V_57 , V_6 ) ;
}
bool F_62 ( struct V_11 * V_12 ,
const struct V_56 * V_57 )
{
const struct V_4 * V_14 ;
T_1 V_6 ;
if ( ! F_46 ( V_57 ) -> V_58 )
return true ;
F_47 ( V_57 , & V_6 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( V_14 && F_33 ( V_14 ) )
return true ;
return false ;
}
bool F_63 ( struct V_44 * V_45 , struct V_56 * V_57 , T_1 * V_6 )
{
struct V_11 * V_12 ;
struct V_22 * V_16 = V_45 -> V_16 ;
if ( ! V_16 -> V_66 )
return true ;
V_12 = F_64 ( V_45 ) ;
if ( ! V_12 || ! V_12 -> V_52 )
return false ;
if ( ! F_47 ( V_57 , V_6 ) && V_57 -> V_32 != V_16 -> V_32 )
* V_6 = 0 ;
if ( ! * V_6 ) {
* V_6 = F_58 ( V_12 ) ;
if ( ! * V_6 )
return false ;
return true ;
}
if ( F_24 ( V_12 , * V_6 ) )
return true ;
return false ;
}
int F_25 ( struct V_22 * V_16 , T_1 V_6 , T_1 V_15 )
{
struct V_11 * V_12 ;
struct V_4 * V_54 ;
int V_67 ;
F_65 () ;
V_12 = F_9 ( V_16 ) ;
V_54 = F_24 ( V_12 , V_6 ) ;
if ( V_54 ) {
if ( ! F_66 ( V_54 ) ) {
if ( ! ( V_15 & V_48 ) )
return - V_68 ;
V_67 = F_34 ( V_16 , NULL , V_16 -> V_21 -> V_51 ,
V_54 -> V_6 ) ;
if ( V_67 ) {
F_35 ( V_16 , L_1 ) ;
return V_67 ;
}
F_27 ( & V_54 -> V_40 ) ;
V_54 -> V_15 |= V_48 ;
V_12 -> V_52 ++ ;
}
F_7 ( V_54 , V_15 ) ;
return 0 ;
}
V_54 = F_67 ( sizeof( * V_54 ) , V_69 ) ;
if ( ! V_54 )
return - V_70 ;
V_54 -> V_6 = V_6 ;
V_54 -> V_15 = V_15 | V_47 ;
V_54 -> V_15 &= ~ V_18 ;
V_54 -> V_16 = V_16 ;
if ( V_15 & V_48 )
F_68 ( & V_54 -> V_40 , 1 ) ;
V_67 = F_32 ( V_54 , V_15 ) ;
if ( V_67 )
F_42 ( V_54 ) ;
return V_67 ;
}
int F_69 ( struct V_22 * V_16 , T_1 V_6 )
{
struct V_11 * V_12 ;
struct V_4 * V_14 ;
F_65 () ;
V_12 = F_9 ( V_16 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( ! V_14 || ! F_66 ( V_14 ) )
return - V_71 ;
F_37 ( V_16 , NULL , V_16 -> V_21 -> V_51 , V_6 ) ;
F_70 ( V_16 , NULL , V_6 , 0 ) ;
return F_38 ( V_14 ) ;
}
void F_71 ( struct V_22 * V_16 )
{
struct V_11 * V_12 ;
F_65 () ;
V_12 = F_9 ( V_16 ) ;
F_43 ( V_12 ) ;
F_72 ( V_16 -> V_72 , NULL ) ;
F_73 () ;
F_39 ( V_12 ) ;
}
struct V_4 * F_24 ( struct V_11 * V_12 , T_1 V_6 )
{
if ( ! V_12 )
return NULL ;
return F_2 ( & V_12 -> V_41 , V_6 ) ;
}
static void F_74 ( struct V_22 * V_16 )
{
if ( V_16 -> V_73 )
return;
F_75 ( & V_16 -> V_74 ) ;
if ( ! V_16 -> V_66 || V_16 -> V_32 == F_76 ( V_75 ) ) {
V_16 -> V_76 [ 5 ] = 0x00 ;
} else {
V_16 -> V_76 [ 5 ] = 0x08 ;
}
F_77 ( & V_16 -> V_74 ) ;
}
void F_78 ( struct V_22 * V_16 )
{
if ( ! V_16 -> V_66 || V_16 -> V_32 == F_76 ( V_75 ) )
V_16 -> V_77 = V_78 ;
else
V_16 -> V_77 = V_79 &
~ ( 1u << V_16 -> V_76 [ 5 ] ) ;
}
int F_79 ( struct V_22 * V_16 , unsigned long V_80 )
{
struct V_81 V_82 = {
. V_25 = V_16 -> V_21 ,
. V_26 = V_83 ,
. V_15 = V_84 ,
. V_85 . V_86 = V_80 ,
} ;
int V_30 ;
if ( V_16 -> V_66 == V_80 )
return 0 ;
V_30 = F_80 ( V_16 -> V_21 , & V_82 ) ;
if ( V_30 && V_30 != - V_31 )
return V_30 ;
V_16 -> V_66 = V_80 ;
F_81 ( V_16 ) ;
F_74 ( V_16 ) ;
F_78 ( V_16 ) ;
return 0 ;
}
int F_82 ( struct V_22 * V_16 , unsigned long V_80 )
{
int V_30 ;
if ( ! F_83 () )
return F_84 () ;
V_30 = F_79 ( V_16 , V_80 ) ;
F_85 () ;
return V_30 ;
}
int F_86 ( struct V_22 * V_16 , T_2 V_61 )
{
int V_30 = 0 ;
struct V_44 * V_45 ;
struct V_4 * V_54 ;
struct V_11 * V_12 ;
T_2 V_87 ;
if ( V_16 -> V_32 == V_61 )
return 0 ;
F_87 (p, &br->port_list, list) {
V_12 = F_10 ( V_45 ) ;
F_87 (vlan, &vg->vlan_list, vlist) {
V_30 = F_13 ( V_45 -> V_21 , V_61 , V_54 -> V_6 ) ;
if ( V_30 )
goto V_88;
}
}
V_87 = V_16 -> V_32 ;
V_16 -> V_32 = V_61 ;
F_74 ( V_16 ) ;
F_78 ( V_16 ) ;
F_87 (p, &br->port_list, list) {
V_12 = F_10 ( V_45 ) ;
F_87 (vlan, &vg->vlan_list, vlist)
F_22 ( V_45 -> V_21 , V_87 , V_54 -> V_6 ) ;
}
return 0 ;
V_88:
F_88 (vlan, &vg->vlan_list, vlist)
F_22 ( V_45 -> V_21 , V_61 , V_54 -> V_6 ) ;
F_88 (p, &br->port_list, list) {
V_12 = F_10 ( V_45 ) ;
F_87 (vlan, &vg->vlan_list, vlist)
F_22 ( V_45 -> V_21 , V_61 , V_54 -> V_6 ) ;
}
return V_30 ;
}
int F_89 ( struct V_22 * V_16 , unsigned long V_80 )
{
int V_30 ;
if ( V_80 != V_75 && V_80 != V_89 )
return - V_90 ;
if ( ! F_83 () )
return F_84 () ;
V_30 = F_86 ( V_16 , F_76 ( V_80 ) ) ;
F_85 () ;
return V_30 ;
}
static bool F_90 ( struct V_11 * V_12 , T_1 V_6 )
{
struct V_4 * V_14 ;
if ( V_6 != V_12 -> V_13 )
return false ;
V_14 = F_2 ( & V_12 -> V_41 , V_6 ) ;
if ( V_14 && F_33 ( V_14 ) &&
( V_14 -> V_15 & V_19 ) )
return true ;
return false ;
}
static void F_91 ( struct V_22 * V_16 )
{
struct V_44 * V_45 ;
T_1 V_13 = V_16 -> V_91 ;
if ( F_90 ( F_9 ( V_16 ) , V_13 ) )
F_69 ( V_16 , V_13 ) ;
F_87 (p, &br->port_list, list) {
if ( F_90 ( F_10 ( V_45 ) , V_13 ) )
F_92 ( V_45 , V_13 ) ;
}
V_16 -> V_91 = 0 ;
}
int F_93 ( struct V_22 * V_16 , T_1 V_13 )
{
const struct V_4 * V_92 ;
struct V_11 * V_12 ;
struct V_44 * V_45 ;
T_1 V_93 ;
int V_30 = 0 ;
unsigned long * V_94 ;
if ( ! V_13 ) {
F_91 ( V_16 ) ;
return 0 ;
}
V_94 = F_94 ( F_95 ( V_95 ) , sizeof( unsigned long ) ,
V_69 ) ;
if ( ! V_94 )
return - V_70 ;
V_93 = V_16 -> V_91 ;
V_12 = F_9 ( V_16 ) ;
V_92 = F_24 ( V_12 , V_13 ) ;
if ( ( ! V_93 || F_90 ( V_12 , V_93 ) ) &&
( ! V_92 || ! F_33 ( V_92 ) ) ) {
V_30 = F_25 ( V_16 , V_13 ,
V_18 |
V_19 |
V_48 ) ;
if ( V_30 )
goto V_46;
F_69 ( V_16 , V_93 ) ;
F_96 ( 0 , V_94 ) ;
}
F_87 (p, &br->port_list, list) {
V_12 = F_10 ( V_45 ) ;
if ( ( V_93 &&
! F_90 ( V_12 , V_93 ) ) ||
F_24 ( V_12 , V_13 ) )
continue;
V_30 = F_97 ( V_45 , V_13 ,
V_18 |
V_19 ) ;
if ( V_30 )
goto V_96;
F_92 ( V_45 , V_93 ) ;
F_96 ( V_45 -> V_97 , V_94 ) ;
}
V_16 -> V_91 = V_13 ;
V_46:
F_42 ( V_94 ) ;
return V_30 ;
V_96:
F_88 (p, &br->port_list, list) {
if ( ! F_98 ( V_45 -> V_97 , V_94 ) )
continue;
if ( V_93 )
F_97 ( V_45 , V_93 ,
V_18 |
V_19 ) ;
F_92 ( V_45 , V_13 ) ;
}
if ( F_98 ( 0 , V_94 ) ) {
if ( V_93 )
F_25 ( V_16 , V_93 ,
V_18 |
V_19 |
V_48 ) ;
F_69 ( V_16 , V_13 ) ;
}
goto V_46;
}
int F_99 ( struct V_22 * V_16 , unsigned long V_80 )
{
T_1 V_13 = V_80 ;
int V_30 = 0 ;
if ( V_80 >= V_98 )
return - V_68 ;
if ( ! F_83 () )
return F_84 () ;
if ( V_13 == V_16 -> V_91 )
goto V_99;
if ( V_16 -> V_66 ) {
F_100 ( L_2 ) ;
V_30 = - V_100 ;
goto V_99;
}
V_30 = F_93 ( V_16 , V_13 ) ;
V_99:
F_85 () ;
return V_30 ;
}
int F_101 ( struct V_22 * V_16 )
{
struct V_11 * V_12 ;
int V_67 = - V_70 ;
V_12 = F_67 ( sizeof( * V_12 ) , V_69 ) ;
if ( ! V_12 )
goto V_46;
V_67 = F_102 ( & V_12 -> V_41 , & V_10 ) ;
if ( V_67 )
goto V_101;
F_103 ( & V_12 -> V_37 ) ;
V_16 -> V_32 = F_76 ( V_75 ) ;
V_16 -> V_91 = 1 ;
F_104 ( V_16 -> V_72 , V_12 ) ;
V_67 = F_25 ( V_16 , 1 ,
V_18 | V_19 |
V_48 ) ;
if ( V_67 )
goto V_102;
V_46:
return V_67 ;
V_102:
F_41 ( & V_12 -> V_41 ) ;
V_101:
F_42 ( V_12 ) ;
goto V_46;
}
int F_105 ( struct V_44 * V_45 )
{
struct V_81 V_82 = {
. V_25 = V_45 -> V_16 -> V_21 ,
. V_26 = V_83 ,
. V_15 = V_84 ,
. V_85 . V_86 = V_45 -> V_16 -> V_66 ,
} ;
struct V_11 * V_12 ;
int V_67 = - V_70 ;
V_12 = F_67 ( sizeof( struct V_11 ) , V_69 ) ;
if ( ! V_12 )
goto V_46;
V_67 = F_80 ( V_45 -> V_21 , & V_82 ) ;
if ( V_67 && V_67 != - V_31 )
goto V_103;
V_67 = F_102 ( & V_12 -> V_41 , & V_10 ) ;
if ( V_67 )
goto V_101;
F_103 ( & V_12 -> V_37 ) ;
F_104 ( V_45 -> V_72 , V_12 ) ;
if ( V_45 -> V_16 -> V_91 ) {
V_67 = F_97 ( V_45 , V_45 -> V_16 -> V_91 ,
V_18 |
V_19 ) ;
if ( V_67 )
goto V_102;
}
V_46:
return V_67 ;
V_102:
F_72 ( V_45 -> V_72 , NULL ) ;
F_73 () ;
F_41 ( & V_12 -> V_41 ) ;
V_103:
V_101:
F_42 ( V_12 ) ;
goto V_46;
}
int F_97 ( struct V_44 * V_17 , T_1 V_6 , T_1 V_15 )
{
struct V_23 V_14 = {
. V_24 . V_25 = V_17 -> V_21 ,
. V_24 . V_26 = V_27 ,
. V_15 = V_15 ,
. V_28 = V_6 ,
. V_29 = V_6 ,
} ;
struct V_4 * V_54 ;
int V_67 ;
F_65 () ;
V_54 = F_24 ( F_10 ( V_17 ) , V_6 ) ;
if ( V_54 ) {
V_67 = F_12 ( V_17 -> V_21 , & V_14 . V_24 ) ;
if ( V_67 && V_67 != - V_31 )
return V_67 ;
F_7 ( V_54 , V_15 ) ;
return 0 ;
}
V_54 = F_67 ( sizeof( * V_54 ) , V_69 ) ;
if ( ! V_54 )
return - V_70 ;
V_54 -> V_6 = V_6 ;
V_54 -> V_17 = V_17 ;
V_67 = F_32 ( V_54 , V_15 ) ;
if ( V_67 )
F_42 ( V_54 ) ;
return V_67 ;
}
int F_92 ( struct V_44 * V_17 , T_1 V_6 )
{
struct V_4 * V_14 ;
F_65 () ;
V_14 = F_24 ( F_10 ( V_17 ) , V_6 ) ;
if ( ! V_14 )
return - V_71 ;
F_37 ( V_17 -> V_16 , V_17 , V_17 -> V_21 -> V_51 , V_6 ) ;
F_70 ( V_17 -> V_16 , V_17 , V_6 , 0 ) ;
return F_38 ( V_14 ) ;
}
void F_106 ( struct V_44 * V_17 )
{
struct V_11 * V_12 ;
F_65 () ;
V_12 = F_10 ( V_17 ) ;
F_43 ( V_12 ) ;
F_72 ( V_17 -> V_72 , NULL ) ;
F_73 () ;
F_39 ( V_12 ) ;
}
