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
static void F_28 ( struct V_41 * V_42 )
{
struct V_4 * V_14 ;
V_14 = F_29 ( V_42 , struct V_4 , V_42 ) ;
F_26 ( ! F_8 ( V_14 ) ) ;
F_30 ( V_14 -> V_43 ) ;
V_14 -> V_43 = NULL ;
F_31 ( V_14 ) ;
}
static void F_32 ( struct V_4 * V_39 )
{
struct V_11 * V_12 ;
if ( ! F_8 ( V_39 ) )
return;
V_12 = F_9 ( V_39 -> V_16 ) ;
if ( F_33 ( & V_39 -> V_40 ) ) {
F_34 ( & V_12 -> V_44 ,
& V_39 -> V_45 , V_10 ) ;
F_18 ( V_39 ) ;
F_35 ( & V_39 -> V_42 , F_28 ) ;
}
}
static int F_36 ( struct V_4 * V_14 , T_1 V_15 )
{
struct V_4 * V_39 = NULL ;
struct V_46 * V_47 = NULL ;
struct V_11 * V_12 ;
struct V_20 * V_21 ;
struct V_22 * V_16 ;
int V_30 ;
if ( F_8 ( V_14 ) ) {
V_16 = V_14 -> V_16 ;
V_21 = V_16 -> V_21 ;
V_12 = F_9 ( V_16 ) ;
} else {
V_47 = V_14 -> V_17 ;
V_16 = V_47 -> V_16 ;
V_21 = V_47 -> V_21 ;
V_12 = F_10 ( V_47 ) ;
}
if ( V_47 ) {
V_30 = F_11 ( V_21 , V_16 , V_14 -> V_6 , V_15 ) ;
if ( V_30 )
goto V_48;
if ( V_15 & V_49 ) {
V_30 = F_25 ( V_16 , V_14 -> V_6 , V_15 |
V_50 ) ;
if ( V_30 )
goto V_51;
}
V_39 = F_23 ( V_16 , V_14 -> V_6 ) ;
if ( ! V_39 )
goto V_51;
V_14 -> V_52 = V_39 ;
V_14 -> V_43 = V_39 -> V_43 ;
}
if ( F_37 ( V_14 ) ) {
V_30 = F_38 ( V_16 , V_47 , V_21 -> V_53 , V_14 -> V_6 ) ;
if ( V_30 ) {
F_39 ( V_16 , L_1 ) ;
goto V_51;
}
V_12 -> V_54 ++ ;
}
V_30 = F_40 ( & V_12 -> V_44 , & V_14 -> V_45 ,
V_10 ) ;
if ( V_30 )
goto V_55;
F_14 ( V_14 ) ;
F_7 ( V_14 , V_15 ) ;
V_48:
return V_30 ;
V_55:
if ( F_37 ( V_14 ) ) {
F_41 ( V_16 , V_47 , V_21 -> V_53 , V_14 -> V_6 ) ;
V_12 -> V_54 -- ;
}
V_51:
if ( V_47 ) {
F_20 ( V_21 , V_16 , V_14 -> V_6 ) ;
if ( V_39 ) {
F_32 ( V_39 ) ;
V_14 -> V_52 = NULL ;
}
}
goto V_48;
}
static int F_42 ( struct V_4 * V_14 )
{
struct V_4 * V_39 = V_14 ;
struct V_11 * V_12 ;
struct V_46 * V_47 = NULL ;
int V_30 = 0 ;
if ( F_8 ( V_14 ) ) {
V_12 = F_9 ( V_14 -> V_16 ) ;
} else {
V_47 = V_14 -> V_17 ;
V_12 = F_10 ( V_14 -> V_17 ) ;
V_39 = V_14 -> V_52 ;
}
F_6 ( V_12 , V_14 -> V_6 ) ;
if ( V_47 ) {
V_30 = F_20 ( V_47 -> V_21 , V_47 -> V_16 , V_14 -> V_6 ) ;
if ( V_30 )
goto V_48;
}
if ( F_37 ( V_14 ) ) {
V_14 -> V_15 &= ~ V_50 ;
V_12 -> V_54 -- ;
}
if ( V_39 != V_14 ) {
F_34 ( & V_12 -> V_44 , & V_14 -> V_45 ,
V_10 ) ;
F_18 ( V_14 ) ;
F_43 ( V_14 , V_42 ) ;
}
F_32 ( V_39 ) ;
V_48:
return V_30 ;
}
static void F_44 ( struct V_11 * V_12 )
{
F_26 ( ! F_45 ( & V_12 -> V_37 ) ) ;
F_46 ( & V_12 -> V_44 ) ;
F_31 ( V_12 ) ;
}
static void F_47 ( struct V_11 * V_12 )
{
struct V_4 * V_56 , * V_57 ;
F_6 ( V_12 , V_12 -> V_13 ) ;
F_48 (vlan, tmp, &vg->vlan_list, vlist)
F_42 ( V_56 ) ;
}
struct V_58 * F_49 ( struct V_22 * V_16 ,
struct V_11 * V_12 ,
struct V_58 * V_59 )
{
struct V_60 * V_43 ;
struct V_4 * V_14 ;
T_1 V_6 ;
if ( ! F_50 ( V_59 ) -> V_61 )
goto V_48;
F_51 ( V_59 , & V_6 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( ! V_14 || ! F_37 ( V_14 ) ) {
if ( ( V_16 -> V_21 -> V_15 & V_62 ) && V_59 -> V_21 == V_16 -> V_21 ) {
goto V_48;
} else {
F_52 ( V_59 ) ;
return NULL ;
}
}
if ( V_16 -> V_63 ) {
V_43 = F_53 ( V_14 -> V_43 ) ;
F_54 ( & V_43 -> V_64 ) ;
V_43 -> V_65 += V_59 -> V_66 ;
V_43 -> V_67 ++ ;
F_55 ( & V_43 -> V_64 ) ;
}
if ( V_14 -> V_15 & V_19 )
V_59 -> V_68 = 0 ;
V_48:
return V_59 ;
}
static bool F_56 ( const struct V_22 * V_16 ,
struct V_11 * V_12 ,
struct V_58 * V_59 , T_1 * V_6 )
{
struct V_60 * V_43 ;
struct V_4 * V_14 ;
bool V_69 ;
F_50 ( V_59 ) -> V_61 = true ;
if ( F_57 ( ! F_58 ( V_59 ) &&
V_59 -> V_70 == V_16 -> V_32 ) ) {
V_59 = F_59 ( V_59 ) ;
if ( F_57 ( ! V_59 ) )
return false ;
}
if ( ! F_51 ( V_59 , V_6 ) ) {
if ( V_59 -> V_32 != V_16 -> V_32 ) {
F_60 ( V_59 , V_71 ) ;
V_59 = F_61 ( V_59 , V_59 -> V_32 ,
F_62 ( V_59 ) ) ;
if ( F_57 ( ! V_59 ) )
return false ;
F_63 ( V_59 , V_71 ) ;
F_64 ( V_59 ) ;
* V_6 = 0 ;
V_69 = false ;
} else {
V_69 = true ;
}
} else {
V_69 = false ;
}
if ( ! * V_6 ) {
T_1 V_13 = F_65 ( V_12 ) ;
if ( ! V_13 )
goto V_72;
* V_6 = V_13 ;
if ( F_66 ( ! V_69 ) )
F_67 ( V_59 , V_16 -> V_32 , V_13 ) ;
else
V_59 -> V_68 |= V_13 ;
if ( ! V_16 -> V_63 )
return true ;
}
V_14 = F_24 ( V_12 , * V_6 ) ;
if ( ! V_14 || ! F_37 ( V_14 ) )
goto V_72;
if ( V_16 -> V_63 ) {
V_43 = F_53 ( V_14 -> V_43 ) ;
F_54 ( & V_43 -> V_64 ) ;
V_43 -> V_73 += V_59 -> V_66 ;
V_43 -> V_74 ++ ;
F_55 ( & V_43 -> V_64 ) ;
}
return true ;
V_72:
F_52 ( V_59 ) ;
return false ;
}
bool F_68 ( const struct V_22 * V_16 ,
struct V_11 * V_12 , struct V_58 * V_59 ,
T_1 * V_6 )
{
if ( ! V_16 -> V_75 ) {
F_50 ( V_59 ) -> V_61 = false ;
return true ;
}
return F_56 ( V_16 , V_12 , V_59 , V_6 ) ;
}
bool F_69 ( struct V_11 * V_12 ,
const struct V_58 * V_59 )
{
const struct V_4 * V_14 ;
T_1 V_6 ;
if ( ! F_50 ( V_59 ) -> V_61 )
return true ;
F_51 ( V_59 , & V_6 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( V_14 && F_37 ( V_14 ) )
return true ;
return false ;
}
bool F_70 ( struct V_46 * V_47 , struct V_58 * V_59 , T_1 * V_6 )
{
struct V_11 * V_12 ;
struct V_22 * V_16 = V_47 -> V_16 ;
if ( ! V_16 -> V_75 )
return true ;
V_12 = F_71 ( V_47 ) ;
if ( ! V_12 || ! V_12 -> V_54 )
return false ;
if ( ! F_51 ( V_59 , V_6 ) && V_59 -> V_32 != V_16 -> V_32 )
* V_6 = 0 ;
if ( ! * V_6 ) {
* V_6 = F_65 ( V_12 ) ;
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
struct V_4 * V_56 ;
int V_76 ;
F_72 () ;
V_12 = F_9 ( V_16 ) ;
V_56 = F_24 ( V_12 , V_6 ) ;
if ( V_56 ) {
if ( ! F_73 ( V_56 ) ) {
if ( ! ( V_15 & V_50 ) )
return - V_77 ;
V_76 = F_38 ( V_16 , NULL , V_16 -> V_21 -> V_53 ,
V_56 -> V_6 ) ;
if ( V_76 ) {
F_39 ( V_16 , L_1 ) ;
return V_76 ;
}
F_27 ( & V_56 -> V_40 ) ;
V_56 -> V_15 |= V_50 ;
V_12 -> V_54 ++ ;
}
F_7 ( V_56 , V_15 ) ;
return 0 ;
}
V_56 = F_74 ( sizeof( * V_56 ) , V_78 ) ;
if ( ! V_56 )
return - V_79 ;
V_56 -> V_43 = F_75 ( struct V_60 ) ;
if ( ! V_56 -> V_43 ) {
F_31 ( V_56 ) ;
return - V_79 ;
}
V_56 -> V_6 = V_6 ;
V_56 -> V_15 = V_15 | V_49 ;
V_56 -> V_15 &= ~ V_18 ;
V_56 -> V_16 = V_16 ;
if ( V_15 & V_50 )
F_76 ( & V_56 -> V_40 , 1 ) ;
V_76 = F_36 ( V_56 , V_15 ) ;
if ( V_76 ) {
F_30 ( V_56 -> V_43 ) ;
F_31 ( V_56 ) ;
}
return V_76 ;
}
int F_77 ( struct V_22 * V_16 , T_1 V_6 )
{
struct V_11 * V_12 ;
struct V_4 * V_14 ;
F_72 () ;
V_12 = F_9 ( V_16 ) ;
V_14 = F_24 ( V_12 , V_6 ) ;
if ( ! V_14 || ! F_73 ( V_14 ) )
return - V_80 ;
F_41 ( V_16 , NULL , V_16 -> V_21 -> V_53 , V_6 ) ;
F_78 ( V_16 , NULL , V_6 , 0 ) ;
return F_42 ( V_14 ) ;
}
void F_79 ( struct V_22 * V_16 )
{
struct V_11 * V_12 ;
F_72 () ;
V_12 = F_9 ( V_16 ) ;
F_47 ( V_12 ) ;
F_80 ( V_16 -> V_81 , NULL ) ;
F_81 () ;
F_44 ( V_12 ) ;
}
struct V_4 * F_24 ( struct V_11 * V_12 , T_1 V_6 )
{
if ( ! V_12 )
return NULL ;
return F_2 ( & V_12 -> V_44 , V_6 ) ;
}
static void F_82 ( struct V_22 * V_16 )
{
if ( V_16 -> V_82 )
return;
F_83 ( & V_16 -> V_83 ) ;
if ( ! V_16 -> V_75 || V_16 -> V_32 == F_84 ( V_84 ) ) {
V_16 -> V_85 [ 5 ] = 0x00 ;
} else {
V_16 -> V_85 [ 5 ] = 0x08 ;
}
F_85 ( & V_16 -> V_83 ) ;
}
void F_86 ( struct V_22 * V_16 )
{
if ( ! V_16 -> V_75 || V_16 -> V_32 == F_84 ( V_84 ) )
V_16 -> V_86 = V_87 ;
else
V_16 -> V_86 = V_88 &
~ ( 1u << V_16 -> V_85 [ 5 ] ) ;
}
int F_87 ( struct V_22 * V_16 , unsigned long V_89 )
{
struct V_90 V_91 = {
. V_25 = V_16 -> V_21 ,
. V_26 = V_92 ,
. V_15 = V_93 ,
. V_94 . V_95 = V_89 ,
} ;
int V_30 ;
if ( V_16 -> V_75 == V_89 )
return 0 ;
V_30 = F_88 ( V_16 -> V_21 , & V_91 ) ;
if ( V_30 && V_30 != - V_31 )
return V_30 ;
V_16 -> V_75 = V_89 ;
F_89 ( V_16 ) ;
F_82 ( V_16 ) ;
F_86 ( V_16 ) ;
return 0 ;
}
int F_90 ( struct V_22 * V_16 , unsigned long V_89 )
{
return F_87 ( V_16 , V_89 ) ;
}
int F_91 ( struct V_22 * V_16 , T_2 V_96 )
{
int V_30 = 0 ;
struct V_46 * V_47 ;
struct V_4 * V_56 ;
struct V_11 * V_12 ;
T_2 V_97 ;
if ( V_16 -> V_32 == V_96 )
return 0 ;
F_92 (p, &br->port_list, list) {
V_12 = F_10 ( V_47 ) ;
F_92 (vlan, &vg->vlan_list, vlist) {
V_30 = F_13 ( V_47 -> V_21 , V_96 , V_56 -> V_6 ) ;
if ( V_30 )
goto V_98;
}
}
V_97 = V_16 -> V_32 ;
V_16 -> V_32 = V_96 ;
F_82 ( V_16 ) ;
F_86 ( V_16 ) ;
F_92 (p, &br->port_list, list) {
V_12 = F_10 ( V_47 ) ;
F_92 (vlan, &vg->vlan_list, vlist)
F_22 ( V_47 -> V_21 , V_97 , V_56 -> V_6 ) ;
}
return 0 ;
V_98:
F_93 (vlan, &vg->vlan_list, vlist)
F_22 ( V_47 -> V_21 , V_96 , V_56 -> V_6 ) ;
F_93 (p, &br->port_list, list) {
V_12 = F_10 ( V_47 ) ;
F_92 (vlan, &vg->vlan_list, vlist)
F_22 ( V_47 -> V_21 , V_96 , V_56 -> V_6 ) ;
}
return V_30 ;
}
int F_94 ( struct V_22 * V_16 , unsigned long V_89 )
{
if ( V_89 != V_84 && V_89 != V_99 )
return - V_100 ;
return F_91 ( V_16 , F_84 ( V_89 ) ) ;
}
int F_95 ( struct V_22 * V_16 , unsigned long V_89 )
{
switch ( V_89 ) {
case 0 :
case 1 :
V_16 -> V_63 = V_89 ;
break;
default:
return - V_77 ;
}
return 0 ;
}
static bool F_96 ( struct V_11 * V_12 , T_1 V_6 )
{
struct V_4 * V_14 ;
if ( V_6 != V_12 -> V_13 )
return false ;
V_14 = F_2 ( & V_12 -> V_44 , V_6 ) ;
if ( V_14 && F_37 ( V_14 ) &&
( V_14 -> V_15 & V_19 ) )
return true ;
return false ;
}
static void F_97 ( struct V_22 * V_16 )
{
struct V_46 * V_47 ;
T_1 V_13 = V_16 -> V_101 ;
if ( F_96 ( F_9 ( V_16 ) , V_13 ) )
F_77 ( V_16 , V_13 ) ;
F_92 (p, &br->port_list, list) {
if ( F_96 ( F_10 ( V_47 ) , V_13 ) )
F_98 ( V_47 , V_13 ) ;
}
V_16 -> V_101 = 0 ;
}
int F_99 ( struct V_22 * V_16 , T_1 V_13 )
{
const struct V_4 * V_102 ;
struct V_11 * V_12 ;
struct V_46 * V_47 ;
T_1 V_103 ;
int V_30 = 0 ;
unsigned long * V_104 ;
if ( ! V_13 ) {
F_97 ( V_16 ) ;
return 0 ;
}
V_104 = F_100 ( F_101 ( V_105 ) , sizeof( unsigned long ) ,
V_78 ) ;
if ( ! V_104 )
return - V_79 ;
V_103 = V_16 -> V_101 ;
V_12 = F_9 ( V_16 ) ;
V_102 = F_24 ( V_12 , V_13 ) ;
if ( ( ! V_103 || F_96 ( V_12 , V_103 ) ) &&
( ! V_102 || ! F_37 ( V_102 ) ) ) {
V_30 = F_25 ( V_16 , V_13 ,
V_18 |
V_19 |
V_50 ) ;
if ( V_30 )
goto V_48;
F_77 ( V_16 , V_103 ) ;
F_102 ( 0 , V_104 ) ;
}
F_92 (p, &br->port_list, list) {
V_12 = F_10 ( V_47 ) ;
if ( ( V_103 &&
! F_96 ( V_12 , V_103 ) ) ||
F_24 ( V_12 , V_13 ) )
continue;
V_30 = F_103 ( V_47 , V_13 ,
V_18 |
V_19 ) ;
if ( V_30 )
goto V_106;
F_98 ( V_47 , V_103 ) ;
F_102 ( V_47 -> V_107 , V_104 ) ;
}
V_16 -> V_101 = V_13 ;
V_48:
F_31 ( V_104 ) ;
return V_30 ;
V_106:
F_93 (p, &br->port_list, list) {
if ( ! F_104 ( V_47 -> V_107 , V_104 ) )
continue;
if ( V_103 )
F_103 ( V_47 , V_103 ,
V_18 |
V_19 ) ;
F_98 ( V_47 , V_13 ) ;
}
if ( F_104 ( 0 , V_104 ) ) {
if ( V_103 )
F_25 ( V_16 , V_103 ,
V_18 |
V_19 |
V_50 ) ;
F_77 ( V_16 , V_13 ) ;
}
goto V_48;
}
int F_105 ( struct V_22 * V_16 , unsigned long V_89 )
{
T_1 V_13 = V_89 ;
int V_30 = 0 ;
if ( V_89 >= V_108 )
return - V_77 ;
if ( V_13 == V_16 -> V_101 )
goto V_48;
if ( V_16 -> V_75 ) {
F_106 ( L_2 ) ;
V_30 = - V_109 ;
goto V_48;
}
V_30 = F_99 ( V_16 , V_13 ) ;
V_48:
return V_30 ;
}
int F_107 ( struct V_22 * V_16 )
{
struct V_11 * V_12 ;
int V_76 = - V_79 ;
V_12 = F_74 ( sizeof( * V_12 ) , V_78 ) ;
if ( ! V_12 )
goto V_48;
V_76 = F_108 ( & V_12 -> V_44 , & V_10 ) ;
if ( V_76 )
goto V_110;
F_109 ( & V_12 -> V_37 ) ;
V_16 -> V_32 = F_84 ( V_84 ) ;
V_16 -> V_101 = 1 ;
F_110 ( V_16 -> V_81 , V_12 ) ;
V_76 = F_25 ( V_16 , 1 ,
V_18 | V_19 |
V_50 ) ;
if ( V_76 )
goto V_111;
V_48:
return V_76 ;
V_111:
F_46 ( & V_12 -> V_44 ) ;
V_110:
F_31 ( V_12 ) ;
goto V_48;
}
int F_111 ( struct V_46 * V_47 )
{
struct V_90 V_91 = {
. V_25 = V_47 -> V_16 -> V_21 ,
. V_26 = V_92 ,
. V_15 = V_93 ,
. V_94 . V_95 = V_47 -> V_16 -> V_75 ,
} ;
struct V_11 * V_12 ;
int V_76 = - V_79 ;
V_12 = F_74 ( sizeof( struct V_11 ) , V_78 ) ;
if ( ! V_12 )
goto V_48;
V_76 = F_88 ( V_47 -> V_21 , & V_91 ) ;
if ( V_76 && V_76 != - V_31 )
goto V_112;
V_76 = F_108 ( & V_12 -> V_44 , & V_10 ) ;
if ( V_76 )
goto V_110;
F_109 ( & V_12 -> V_37 ) ;
F_110 ( V_47 -> V_81 , V_12 ) ;
if ( V_47 -> V_16 -> V_101 ) {
V_76 = F_103 ( V_47 , V_47 -> V_16 -> V_101 ,
V_18 |
V_19 ) ;
if ( V_76 )
goto V_111;
}
V_48:
return V_76 ;
V_111:
F_80 ( V_47 -> V_81 , NULL ) ;
F_81 () ;
F_46 ( & V_12 -> V_44 ) ;
V_112:
V_110:
F_31 ( V_12 ) ;
goto V_48;
}
int F_103 ( struct V_46 * V_17 , T_1 V_6 , T_1 V_15 )
{
struct V_23 V_14 = {
. V_24 . V_25 = V_17 -> V_21 ,
. V_24 . V_26 = V_27 ,
. V_15 = V_15 ,
. V_28 = V_6 ,
. V_29 = V_6 ,
} ;
struct V_4 * V_56 ;
int V_76 ;
F_72 () ;
V_56 = F_24 ( F_10 ( V_17 ) , V_6 ) ;
if ( V_56 ) {
V_76 = F_12 ( V_17 -> V_21 , & V_14 . V_24 ) ;
if ( V_76 && V_76 != - V_31 )
return V_76 ;
F_7 ( V_56 , V_15 ) ;
return 0 ;
}
V_56 = F_74 ( sizeof( * V_56 ) , V_78 ) ;
if ( ! V_56 )
return - V_79 ;
V_56 -> V_6 = V_6 ;
V_56 -> V_17 = V_17 ;
V_76 = F_36 ( V_56 , V_15 ) ;
if ( V_76 )
F_31 ( V_56 ) ;
return V_76 ;
}
int F_98 ( struct V_46 * V_17 , T_1 V_6 )
{
struct V_4 * V_14 ;
F_72 () ;
V_14 = F_24 ( F_10 ( V_17 ) , V_6 ) ;
if ( ! V_14 )
return - V_80 ;
F_41 ( V_17 -> V_16 , V_17 , V_17 -> V_21 -> V_53 , V_6 ) ;
F_78 ( V_17 -> V_16 , V_17 , V_6 , 0 ) ;
return F_42 ( V_14 ) ;
}
void F_112 ( struct V_46 * V_17 )
{
struct V_11 * V_12 ;
F_72 () ;
V_12 = F_10 ( V_17 ) ;
F_47 ( V_12 ) ;
F_80 ( V_17 -> V_81 , NULL ) ;
F_81 () ;
F_44 ( V_12 ) ;
}
void F_113 ( const struct V_4 * V_14 ,
struct V_60 * V_43 )
{
int V_113 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
F_114 (i) {
T_3 V_114 , V_115 , V_116 , V_117 ;
struct V_60 * V_118 ;
unsigned int V_119 ;
V_118 = F_115 ( V_14 -> V_43 , V_113 ) ;
do {
V_119 = F_116 ( & V_118 -> V_64 ) ;
V_114 = V_118 -> V_74 ;
V_115 = V_118 -> V_73 ;
V_117 = V_118 -> V_65 ;
V_116 = V_118 -> V_67 ;
} while ( F_117 ( & V_118 -> V_64 , V_119 ) );
V_43 -> V_74 += V_114 ;
V_43 -> V_73 += V_115 ;
V_43 -> V_65 += V_117 ;
V_43 -> V_67 += V_116 ;
}
}
