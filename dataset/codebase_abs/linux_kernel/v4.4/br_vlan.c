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
. V_24 . V_25 = V_26 ,
. V_15 = V_15 ,
. V_27 = V_6 ,
. V_28 = V_6 ,
} ;
int V_29 ;
V_29 = F_12 ( V_21 , & V_14 . V_24 ) ;
if ( V_29 == - V_30 )
return F_13 ( V_21 , V_16 -> V_31 , V_6 ) ;
return V_29 ;
}
static void F_14 ( struct V_4 * V_14 )
{
struct V_11 * V_12 ;
struct V_32 * V_33 , * V_34 ;
struct V_4 * V_35 ;
if ( F_8 ( V_14 ) )
V_12 = F_9 ( V_14 -> V_16 ) ;
else
V_12 = F_10 ( V_14 -> V_17 ) ;
V_33 = & V_12 -> V_36 ;
F_15 (hpos, headp) {
V_35 = F_16 ( V_34 , struct V_4 , V_37 ) ;
if ( V_14 -> V_6 < V_35 -> V_6 )
continue;
else
break;
}
F_17 ( & V_14 -> V_37 , V_34 ) ;
}
static void F_18 ( struct V_4 * V_14 )
{
F_19 ( & V_14 -> V_37 ) ;
}
static int F_20 ( struct V_20 * V_21 , struct V_22 * V_16 ,
T_1 V_6 )
{
struct V_23 V_14 = {
. V_24 . V_25 = V_26 ,
. V_27 = V_6 ,
. V_28 = V_6 ,
} ;
int V_29 ;
V_29 = F_21 ( V_21 , & V_14 . V_24 ) ;
if ( V_29 == - V_30 ) {
F_22 ( V_21 , V_16 -> V_31 , V_6 ) ;
return 0 ;
}
return V_29 ;
}
static struct V_4 * F_23 ( struct V_22 * V_16 , T_1 V_6 )
{
struct V_11 * V_12 ;
struct V_4 * V_38 ;
V_12 = F_9 ( V_16 ) ;
V_38 = F_24 ( V_12 , V_6 ) ;
if ( ! V_38 ) {
if ( F_25 ( V_16 , V_6 , 0 ) )
return NULL ;
V_38 = F_24 ( V_12 , V_6 ) ;
if ( F_26 ( ! V_38 ) )
return NULL ;
}
F_27 ( & V_38 -> V_39 ) ;
return V_38 ;
}
static void F_28 ( struct V_4 * V_38 )
{
struct V_11 * V_12 ;
if ( ! F_8 ( V_38 ) )
return;
V_12 = F_9 ( V_38 -> V_16 ) ;
if ( F_29 ( & V_38 -> V_39 ) ) {
F_30 ( & V_12 -> V_40 ,
& V_38 -> V_41 , V_10 ) ;
F_18 ( V_38 ) ;
F_31 ( V_38 , V_42 ) ;
}
}
static int F_32 ( struct V_4 * V_14 , T_1 V_15 )
{
struct V_4 * V_38 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_11 * V_12 ;
struct V_20 * V_21 ;
struct V_22 * V_16 ;
int V_29 ;
if ( F_8 ( V_14 ) ) {
V_16 = V_14 -> V_16 ;
V_21 = V_16 -> V_21 ;
V_12 = F_9 ( V_16 ) ;
} else {
V_44 = V_14 -> V_17 ;
V_16 = V_44 -> V_16 ;
V_21 = V_44 -> V_21 ;
V_12 = F_10 ( V_44 ) ;
}
if ( V_44 ) {
V_29 = F_11 ( V_21 , V_16 , V_14 -> V_6 , V_15 ) ;
if ( V_29 )
goto V_45;
if ( V_15 & V_46 ) {
V_29 = F_25 ( V_16 , V_14 -> V_6 , V_15 |
V_47 ) ;
if ( V_29 )
goto V_48;
}
V_38 = F_23 ( V_16 , V_14 -> V_6 ) ;
if ( ! V_38 )
goto V_48;
V_14 -> V_49 = V_38 ;
}
if ( F_33 ( V_14 ) ) {
V_29 = F_34 ( V_16 , V_44 , V_21 -> V_50 , V_14 -> V_6 ) ;
if ( V_29 ) {
F_35 ( V_16 , L_1 ) ;
goto V_48;
}
V_12 -> V_51 ++ ;
}
V_29 = F_36 ( & V_12 -> V_40 , & V_14 -> V_41 ,
V_10 ) ;
if ( V_29 )
goto V_52;
F_14 ( V_14 ) ;
F_7 ( V_14 , V_15 ) ;
V_45:
return V_29 ;
V_52:
if ( F_33 ( V_14 ) ) {
F_37 ( V_16 , V_44 , V_21 -> V_50 , V_14 -> V_6 ) ;
V_12 -> V_51 -- ;
}
V_48:
if ( V_44 ) {
F_20 ( V_21 , V_16 , V_14 -> V_6 ) ;
if ( V_38 ) {
F_28 ( V_38 ) ;
V_14 -> V_49 = NULL ;
}
}
goto V_45;
}
static int F_38 ( struct V_4 * V_14 )
{
struct V_4 * V_38 = V_14 ;
struct V_11 * V_12 ;
struct V_43 * V_44 = NULL ;
int V_29 = 0 ;
if ( F_8 ( V_14 ) ) {
V_12 = F_9 ( V_14 -> V_16 ) ;
} else {
V_44 = V_14 -> V_17 ;
V_12 = F_10 ( V_14 -> V_17 ) ;
V_38 = V_14 -> V_49 ;
}
F_6 ( V_12 , V_14 -> V_6 ) ;
if ( V_44 ) {
V_29 = F_20 ( V_44 -> V_21 , V_44 -> V_16 , V_14 -> V_6 ) ;
if ( V_29 )
goto V_45;
}
if ( F_33 ( V_14 ) ) {
V_14 -> V_15 &= ~ V_47 ;
V_12 -> V_51 -- ;
}
if ( V_38 != V_14 ) {
F_30 ( & V_12 -> V_40 , & V_14 -> V_41 ,
V_10 ) ;
F_18 ( V_14 ) ;
F_31 ( V_14 , V_42 ) ;
}
F_28 ( V_38 ) ;
V_45:
return V_29 ;
}
static void F_39 ( struct V_11 * V_12 )
{
F_26 ( ! F_40 ( & V_12 -> V_36 ) ) ;
F_41 ( & V_12 -> V_40 ) ;
F_42 ( V_12 ) ;
}
static void F_43 ( struct V_11 * V_12 )
{
struct V_4 * V_53 , * V_54 ;
F_6 ( V_12 , V_12 -> V_13 ) ;
F_44 (vlan, tmp, &vg->vlan_list, vlist)
F_38 ( V_53 ) ;
}
struct V_55 * F_45 ( struct V_22 * V_16 ,
struct V_11 * V_12 ,
struct V_55 * V_56 )
{
struct V_4 * V_14 ;
T_1 V_6 ;
if ( ! F_46 ( V_56 ) -> V_57 )
goto V_45;
F_47 ( V_56 , & V_6 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( ! V_14 || ! F_33 ( V_14 ) ) {
if ( ( V_16 -> V_21 -> V_15 & V_58 ) && V_56 -> V_21 == V_16 -> V_21 ) {
goto V_45;
} else {
F_48 ( V_56 ) ;
return NULL ;
}
}
if ( V_14 -> V_15 & V_19 )
V_56 -> V_59 = 0 ;
V_45:
return V_56 ;
}
static bool F_49 ( struct V_11 * V_12 , T_2 V_60 ,
struct V_55 * V_56 , T_1 * V_6 )
{
const struct V_4 * V_14 ;
bool V_61 ;
F_46 ( V_56 ) -> V_57 = true ;
if ( F_50 ( ! F_51 ( V_56 ) &&
V_56 -> V_62 == V_60 ) ) {
V_56 = F_52 ( V_56 ) ;
if ( F_50 ( ! V_56 ) )
return false ;
}
if ( ! F_47 ( V_56 , V_6 ) ) {
if ( V_56 -> V_31 != V_60 ) {
F_53 ( V_56 , V_63 ) ;
V_56 = F_54 ( V_56 , V_56 -> V_31 ,
F_55 ( V_56 ) ) ;
if ( F_50 ( ! V_56 ) )
return false ;
F_56 ( V_56 , V_63 ) ;
F_57 ( V_56 ) ;
* V_6 = 0 ;
V_61 = false ;
} else {
V_61 = true ;
}
} else {
V_61 = false ;
}
if ( ! * V_6 ) {
T_1 V_13 = F_58 ( V_12 ) ;
if ( ! V_13 )
goto V_64;
* V_6 = V_13 ;
if ( F_59 ( ! V_61 ) )
F_60 ( V_56 , V_60 , V_13 ) ;
else
V_56 -> V_59 |= V_13 ;
return true ;
}
V_14 = F_24 ( V_12 , * V_6 ) ;
if ( V_14 && F_33 ( V_14 ) )
return true ;
V_64:
F_48 ( V_56 ) ;
return false ;
}
bool F_61 ( const struct V_22 * V_16 ,
struct V_11 * V_12 , struct V_55 * V_56 ,
T_1 * V_6 )
{
if ( ! V_16 -> V_65 ) {
F_46 ( V_56 ) -> V_57 = false ;
return true ;
}
return F_49 ( V_12 , V_16 -> V_31 , V_56 , V_6 ) ;
}
bool F_62 ( struct V_11 * V_12 ,
const struct V_55 * V_56 )
{
const struct V_4 * V_14 ;
T_1 V_6 ;
if ( ! F_46 ( V_56 ) -> V_57 )
return true ;
F_47 ( V_56 , & V_6 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( V_14 && F_33 ( V_14 ) )
return true ;
return false ;
}
bool F_63 ( struct V_43 * V_44 , struct V_55 * V_56 , T_1 * V_6 )
{
struct V_11 * V_12 ;
struct V_22 * V_16 = V_44 -> V_16 ;
if ( ! V_16 -> V_65 )
return true ;
V_12 = F_64 ( V_44 ) ;
if ( ! V_12 || ! V_12 -> V_51 )
return false ;
if ( ! F_47 ( V_56 , V_6 ) && V_56 -> V_31 != V_16 -> V_31 )
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
struct V_4 * V_53 ;
int V_66 ;
F_65 () ;
V_12 = F_9 ( V_16 ) ;
V_53 = F_24 ( V_12 , V_6 ) ;
if ( V_53 ) {
if ( ! F_66 ( V_53 ) ) {
if ( ! ( V_15 & V_47 ) )
return - V_67 ;
V_66 = F_34 ( V_16 , NULL , V_16 -> V_21 -> V_50 ,
V_53 -> V_6 ) ;
if ( V_66 ) {
F_35 ( V_16 , L_1 ) ;
return V_66 ;
}
F_27 ( & V_53 -> V_39 ) ;
V_53 -> V_15 |= V_47 ;
V_12 -> V_51 ++ ;
}
F_7 ( V_53 , V_15 ) ;
return 0 ;
}
V_53 = F_67 ( sizeof( * V_53 ) , V_68 ) ;
if ( ! V_53 )
return - V_69 ;
V_53 -> V_6 = V_6 ;
V_53 -> V_15 = V_15 | V_46 ;
V_53 -> V_15 &= ~ V_18 ;
V_53 -> V_16 = V_16 ;
if ( V_15 & V_47 )
F_68 ( & V_53 -> V_39 , 1 ) ;
V_66 = F_32 ( V_53 , V_15 ) ;
if ( V_66 )
F_42 ( V_53 ) ;
return V_66 ;
}
int F_69 ( struct V_22 * V_16 , T_1 V_6 )
{
struct V_11 * V_12 ;
struct V_4 * V_14 ;
F_65 () ;
V_12 = F_9 ( V_16 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( ! V_14 || ! F_66 ( V_14 ) )
return - V_70 ;
F_37 ( V_16 , NULL , V_16 -> V_21 -> V_50 , V_6 ) ;
F_70 ( V_16 , NULL , V_6 , 0 ) ;
return F_38 ( V_14 ) ;
}
void F_71 ( struct V_22 * V_16 )
{
struct V_11 * V_12 ;
F_65 () ;
V_12 = F_9 ( V_16 ) ;
F_43 ( V_12 ) ;
F_72 ( V_16 -> V_71 , NULL ) ;
F_73 () ;
F_39 ( V_12 ) ;
}
struct V_4 * F_24 ( struct V_11 * V_12 , T_1 V_6 )
{
if ( ! V_12 )
return NULL ;
return F_2 ( & V_12 -> V_40 , V_6 ) ;
}
static void F_74 ( struct V_22 * V_16 )
{
if ( V_16 -> V_72 )
return;
F_75 ( & V_16 -> V_73 ) ;
if ( ! V_16 -> V_65 || V_16 -> V_31 == F_76 ( V_74 ) ) {
V_16 -> V_75 [ 5 ] = 0x00 ;
} else {
V_16 -> V_75 [ 5 ] = 0x08 ;
}
F_77 ( & V_16 -> V_73 ) ;
}
void F_78 ( struct V_22 * V_16 )
{
if ( ! V_16 -> V_65 || V_16 -> V_31 == F_76 ( V_74 ) )
V_16 -> V_76 = V_77 ;
else
V_16 -> V_76 = V_78 &
~ ( 1u << V_16 -> V_75 [ 5 ] ) ;
}
int F_79 ( struct V_22 * V_16 , unsigned long V_79 )
{
if ( V_16 -> V_65 == V_79 )
return 0 ;
V_16 -> V_65 = V_79 ;
F_80 ( V_16 ) ;
F_74 ( V_16 ) ;
F_78 ( V_16 ) ;
return 0 ;
}
int F_81 ( struct V_22 * V_16 , unsigned long V_79 )
{
if ( ! F_82 () )
return F_83 () ;
F_79 ( V_16 , V_79 ) ;
F_84 () ;
return 0 ;
}
int F_85 ( struct V_22 * V_16 , T_2 V_60 )
{
int V_29 = 0 ;
struct V_43 * V_44 ;
struct V_4 * V_53 ;
struct V_11 * V_12 ;
T_2 V_80 ;
if ( V_16 -> V_31 == V_60 )
return 0 ;
F_86 (p, &br->port_list, list) {
V_12 = F_10 ( V_44 ) ;
F_86 (vlan, &vg->vlan_list, vlist) {
V_29 = F_13 ( V_44 -> V_21 , V_60 , V_53 -> V_6 ) ;
if ( V_29 )
goto V_81;
}
}
V_80 = V_16 -> V_31 ;
V_16 -> V_31 = V_60 ;
F_74 ( V_16 ) ;
F_78 ( V_16 ) ;
F_86 (p, &br->port_list, list) {
V_12 = F_10 ( V_44 ) ;
F_86 (vlan, &vg->vlan_list, vlist)
F_22 ( V_44 -> V_21 , V_80 , V_53 -> V_6 ) ;
}
return 0 ;
V_81:
F_87 (vlan, &vg->vlan_list, vlist)
F_22 ( V_44 -> V_21 , V_60 , V_53 -> V_6 ) ;
F_87 (p, &br->port_list, list) {
V_12 = F_10 ( V_44 ) ;
F_86 (vlan, &vg->vlan_list, vlist)
F_22 ( V_44 -> V_21 , V_60 , V_53 -> V_6 ) ;
}
return V_29 ;
}
int F_88 ( struct V_22 * V_16 , unsigned long V_79 )
{
int V_29 ;
if ( V_79 != V_74 && V_79 != V_82 )
return - V_83 ;
if ( ! F_82 () )
return F_83 () ;
V_29 = F_85 ( V_16 , F_76 ( V_79 ) ) ;
F_84 () ;
return V_29 ;
}
static bool F_89 ( struct V_11 * V_12 , T_1 V_6 )
{
struct V_4 * V_14 ;
if ( V_6 != V_12 -> V_13 )
return false ;
V_14 = F_2 ( & V_12 -> V_40 , V_6 ) ;
if ( V_14 && F_33 ( V_14 ) &&
( V_14 -> V_15 & V_19 ) )
return true ;
return false ;
}
static void F_90 ( struct V_22 * V_16 )
{
struct V_43 * V_44 ;
T_1 V_13 = V_16 -> V_84 ;
if ( F_89 ( F_9 ( V_16 ) , V_13 ) )
F_69 ( V_16 , V_13 ) ;
F_86 (p, &br->port_list, list) {
if ( F_89 ( F_10 ( V_44 ) , V_13 ) )
F_91 ( V_44 , V_13 ) ;
}
V_16 -> V_84 = 0 ;
}
int F_92 ( struct V_22 * V_16 , T_1 V_13 )
{
const struct V_4 * V_85 ;
struct V_11 * V_12 ;
struct V_43 * V_44 ;
T_1 V_86 ;
int V_29 = 0 ;
unsigned long * V_87 ;
if ( ! V_13 ) {
F_90 ( V_16 ) ;
return 0 ;
}
V_87 = F_93 ( F_94 ( V_88 ) , sizeof( unsigned long ) ,
V_68 ) ;
if ( ! V_87 )
return - V_69 ;
V_86 = V_16 -> V_84 ;
V_12 = F_9 ( V_16 ) ;
V_85 = F_24 ( V_12 , V_13 ) ;
if ( ( ! V_86 || F_89 ( V_12 , V_86 ) ) &&
( ! V_85 || ! F_33 ( V_85 ) ) ) {
V_29 = F_25 ( V_16 , V_13 ,
V_18 |
V_19 |
V_47 ) ;
if ( V_29 )
goto V_45;
F_69 ( V_16 , V_86 ) ;
F_95 ( 0 , V_87 ) ;
}
F_86 (p, &br->port_list, list) {
V_12 = F_10 ( V_44 ) ;
if ( ( V_86 &&
! F_89 ( V_12 , V_86 ) ) ||
F_24 ( V_12 , V_13 ) )
continue;
V_29 = F_96 ( V_44 , V_13 ,
V_18 |
V_19 ) ;
if ( V_29 )
goto V_89;
F_91 ( V_44 , V_86 ) ;
F_95 ( V_44 -> V_90 , V_87 ) ;
}
V_16 -> V_84 = V_13 ;
V_45:
F_42 ( V_87 ) ;
return V_29 ;
V_89:
F_87 (p, &br->port_list, list) {
if ( ! F_97 ( V_44 -> V_90 , V_87 ) )
continue;
if ( V_86 )
F_96 ( V_44 , V_86 ,
V_18 |
V_19 ) ;
F_91 ( V_44 , V_13 ) ;
}
if ( F_97 ( 0 , V_87 ) ) {
if ( V_86 )
F_25 ( V_16 , V_86 ,
V_18 |
V_19 |
V_47 ) ;
F_69 ( V_16 , V_13 ) ;
}
goto V_45;
}
int F_98 ( struct V_22 * V_16 , unsigned long V_79 )
{
T_1 V_13 = V_79 ;
int V_29 = 0 ;
if ( V_79 >= V_91 )
return - V_67 ;
if ( ! F_82 () )
return F_83 () ;
if ( V_13 == V_16 -> V_84 )
goto V_92;
if ( V_16 -> V_65 ) {
F_99 ( L_2 ) ;
V_29 = - V_93 ;
goto V_92;
}
V_29 = F_92 ( V_16 , V_13 ) ;
V_92:
F_84 () ;
return V_29 ;
}
int F_100 ( struct V_22 * V_16 )
{
struct V_11 * V_12 ;
int V_66 = - V_69 ;
V_12 = F_67 ( sizeof( * V_12 ) , V_68 ) ;
if ( ! V_12 )
goto V_45;
V_66 = F_101 ( & V_12 -> V_40 , & V_10 ) ;
if ( V_66 )
goto V_94;
F_102 ( & V_12 -> V_36 ) ;
V_16 -> V_31 = F_76 ( V_74 ) ;
V_16 -> V_84 = 1 ;
F_103 ( V_16 -> V_71 , V_12 ) ;
V_66 = F_25 ( V_16 , 1 ,
V_18 | V_19 |
V_47 ) ;
if ( V_66 )
goto V_95;
V_45:
return V_66 ;
V_95:
F_41 ( & V_12 -> V_40 ) ;
V_94:
F_42 ( V_12 ) ;
goto V_45;
}
int F_104 ( struct V_43 * V_44 )
{
struct V_11 * V_12 ;
int V_66 = - V_69 ;
V_12 = F_67 ( sizeof( struct V_11 ) , V_68 ) ;
if ( ! V_12 )
goto V_45;
V_66 = F_101 ( & V_12 -> V_40 , & V_10 ) ;
if ( V_66 )
goto V_94;
F_102 ( & V_12 -> V_36 ) ;
F_103 ( V_44 -> V_71 , V_12 ) ;
if ( V_44 -> V_16 -> V_84 ) {
V_66 = F_96 ( V_44 , V_44 -> V_16 -> V_84 ,
V_18 |
V_19 ) ;
if ( V_66 )
goto V_95;
}
V_45:
return V_66 ;
V_95:
F_72 ( V_44 -> V_71 , NULL ) ;
F_73 () ;
F_41 ( & V_12 -> V_40 ) ;
V_94:
F_42 ( V_12 ) ;
goto V_45;
}
int F_96 ( struct V_43 * V_17 , T_1 V_6 , T_1 V_15 )
{
struct V_4 * V_53 ;
int V_66 ;
F_65 () ;
V_53 = F_24 ( F_10 ( V_17 ) , V_6 ) ;
if ( V_53 ) {
F_7 ( V_53 , V_15 ) ;
return 0 ;
}
V_53 = F_67 ( sizeof( * V_53 ) , V_68 ) ;
if ( ! V_53 )
return - V_69 ;
V_53 -> V_6 = V_6 ;
V_53 -> V_17 = V_17 ;
V_66 = F_32 ( V_53 , V_15 ) ;
if ( V_66 )
F_42 ( V_53 ) ;
return V_66 ;
}
int F_91 ( struct V_43 * V_17 , T_1 V_6 )
{
struct V_4 * V_14 ;
F_65 () ;
V_14 = F_24 ( F_10 ( V_17 ) , V_6 ) ;
if ( ! V_14 )
return - V_70 ;
F_37 ( V_17 -> V_16 , V_17 , V_17 -> V_21 -> V_50 , V_6 ) ;
F_70 ( V_17 -> V_16 , V_17 , V_6 , 0 ) ;
return F_38 ( V_14 ) ;
}
void F_105 ( struct V_43 * V_17 )
{
struct V_11 * V_12 ;
F_65 () ;
V_12 = F_10 ( V_17 ) ;
F_43 ( V_12 ) ;
F_72 ( V_17 -> V_71 , NULL ) ;
F_73 () ;
F_39 ( V_12 ) ;
}
