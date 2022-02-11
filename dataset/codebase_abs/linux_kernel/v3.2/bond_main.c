const char * F_1 ( int V_1 )
{
static const char * V_2 [] = {
[ V_3 ] = L_1 ,
[ V_4 ] = L_2 ,
[ V_5 ] = L_3 ,
[ V_6 ] = L_4 ,
[ V_7 ] = L_5 ,
[ V_8 ] = L_6 ,
[ V_9 ] = L_7 ,
} ;
if ( V_1 < 0 || V_1 > V_9 )
return L_8 ;
return V_2 [ V_1 ] ;
}
static int F_2 ( struct V_10 * V_11 , unsigned short V_12 )
{
struct V_13 * V_14 ;
F_3 ( L_9 ,
( V_11 ? V_11 -> V_15 -> V_16 : L_10 ) , V_12 ) ;
V_14 = F_4 ( sizeof( struct V_13 ) , V_17 ) ;
if ( ! V_14 )
return - V_18 ;
F_5 ( & V_14 -> V_19 ) ;
V_14 -> V_12 = V_12 ;
F_6 ( & V_11 -> V_20 ) ;
F_7 ( & V_14 -> V_19 , & V_11 -> V_19 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_3 ( L_11 , V_12 , V_11 -> V_15 -> V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 , unsigned short V_12 )
{
struct V_13 * V_14 ;
int V_21 = - V_22 ;
F_3 ( L_9 , V_11 -> V_15 -> V_16 , V_12 ) ;
F_10 () ;
F_6 ( & V_11 -> V_20 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( V_14 -> V_12 == V_12 ) {
F_12 ( & V_14 -> V_19 ) ;
if ( F_13 ( V_11 ) )
F_14 ( V_11 , V_12 ) ;
F_3 ( L_12 ,
V_12 , V_11 -> V_15 -> V_16 ) ;
F_15 ( V_14 ) ;
V_21 = 0 ;
goto V_23;
}
}
F_3 ( L_13 ,
V_12 , V_11 -> V_15 -> V_16 ) ;
V_23:
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return V_21 ;
}
struct V_13 * F_17 ( struct V_10 * V_11 , struct V_13 * V_24 )
{
struct V_13 * V_25 , * V_26 ;
if ( F_18 ( & V_11 -> V_19 ) )
return NULL ;
if ( ! V_24 ) {
V_25 = F_19 ( V_11 -> V_19 . V_25 ,
struct V_13 , V_19 ) ;
} else {
V_26 = F_19 ( V_11 -> V_19 . V_27 ,
struct V_13 , V_19 ) ;
if ( V_26 == V_24 ) {
V_25 = F_19 ( V_11 -> V_19 . V_25 ,
struct V_13 , V_19 ) ;
} else {
V_25 = F_19 ( V_24 -> V_19 . V_25 ,
struct V_13 , V_19 ) ;
}
}
return V_25 ;
}
int F_20 ( struct V_10 * V_11 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_29 -> V_15 = V_31 ;
V_29 -> V_32 = F_21 ( V_29 ) ;
if ( F_22 ( F_23 ( V_31 ) ) )
F_24 ( F_25 ( V_11 , V_31 ) , V_29 ) ;
else
F_26 ( V_29 ) ;
return 0 ;
}
static void F_27 ( struct V_30 * V_33 , T_1 V_34 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_36 , V_21 ;
F_29 (bond, slave, i) {
struct V_30 * V_31 = V_35 -> V_15 ;
const struct V_37 * V_38 = V_31 -> V_39 ;
if ( ( V_31 -> V_40 & V_41 ) &&
V_38 -> V_42 ) {
V_38 -> V_42 ( V_31 , V_34 ) ;
}
}
V_21 = F_2 ( V_11 , V_34 ) ;
if ( V_21 ) {
F_30 ( L_14 ,
V_33 -> V_16 , V_34 ) ;
}
}
static void F_31 ( struct V_30 * V_33 , T_1 V_34 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_36 , V_21 ;
F_29 (bond, slave, i) {
struct V_30 * V_31 = V_35 -> V_15 ;
const struct V_37 * V_38 = V_31 -> V_39 ;
if ( ( V_31 -> V_40 & V_41 ) &&
V_38 -> V_43 ) {
V_38 -> V_43 ( V_31 , V_34 ) ;
}
}
V_21 = F_9 ( V_11 , V_34 ) ;
if ( V_21 ) {
F_30 ( L_15 ,
V_33 -> V_16 , V_34 ) ;
}
}
static void F_32 ( struct V_10 * V_11 , struct V_30 * V_31 )
{
struct V_13 * V_14 ;
const struct V_37 * V_38 = V_31 -> V_39 ;
if ( ! ( V_31 -> V_40 & V_41 ) ||
! ( V_38 -> V_42 ) )
return;
F_11 (vlan, &bond->vlan_list, vlan_list)
V_38 -> V_42 ( V_31 , V_14 -> V_12 ) ;
}
static void F_33 ( struct V_10 * V_11 ,
struct V_30 * V_31 )
{
const struct V_37 * V_38 = V_31 -> V_39 ;
struct V_13 * V_14 ;
if ( ! ( V_31 -> V_40 & V_41 ) ||
! ( V_38 -> V_43 ) )
return;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( ! V_14 -> V_12 )
continue;
V_38 -> V_43 ( V_31 , V_14 -> V_12 ) ;
}
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_36 ;
if ( V_11 -> V_44 == 0 )
goto V_45;
if ( V_11 -> V_46 . V_1 == V_7 )
return F_35 ( V_11 ) ;
F_29 (bond, slave, i) {
if ( V_35 -> V_47 == V_48 ) {
if ( ! F_36 ( V_11 -> V_15 ) ) {
F_37 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
}
V_45:
if ( F_36 ( V_11 -> V_15 ) ) {
F_38 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_35 * V_35 )
{
struct V_30 * V_31 = V_35 -> V_15 ;
struct V_49 V_50 ;
T_2 V_51 ;
int V_21 ;
V_35 -> V_52 = V_53 ;
V_35 -> V_54 = V_55 ;
V_21 = F_40 ( V_31 , & V_50 ) ;
if ( V_21 < 0 )
return - 1 ;
V_51 = F_41 ( & V_50 ) ;
if ( V_51 == 0 || V_51 == ( ( V_56 ) - 1 ) )
return - 1 ;
switch ( V_50 . V_54 ) {
case V_57 :
case V_58 :
break;
default:
return - 1 ;
}
V_35 -> V_52 = V_51 ;
V_35 -> V_54 = V_50 . V_54 ;
return 0 ;
}
static int F_42 ( struct V_10 * V_11 ,
struct V_30 * V_31 , int V_59 )
{
const struct V_37 * V_38 = V_31 -> V_39 ;
int (* F_43)( struct V_30 * , struct V_60 * , int );
struct V_60 V_61 ;
struct V_62 * V_63 ;
if ( ! V_59 && ! F_44 ( V_31 ) )
return 0 ;
if ( V_11 -> V_46 . V_64 )
return F_36 ( V_31 ) ? V_65 : 0 ;
if ( V_31 -> V_66 ) {
if ( V_31 -> V_66 -> V_67 ) {
T_2 V_47 ;
V_47 = V_31 -> V_66 -> V_67 ( V_31 ) ;
return V_47 ? V_65 : 0 ;
}
}
F_43 = V_38 -> V_68 ;
if ( F_43 ) {
strncpy ( V_61 . V_69 , V_31 -> V_16 , V_70 ) ;
V_63 = F_45 ( & V_61 ) ;
if ( F_46 ( V_31 , & V_61 , V_71 ) == 0 ) {
V_63 -> V_72 = V_73 ;
if ( F_46 ( V_31 , & V_61 , V_74 ) == 0 )
return V_63 -> V_75 & V_65 ;
}
}
return V_59 ? - 1 : V_65 ;
}
static int F_47 ( struct V_10 * V_11 , int V_76 )
{
int V_77 = 0 ;
if ( F_48 ( V_11 -> V_46 . V_1 ) ) {
if ( V_11 -> V_78 ) {
V_77 = F_49 ( V_11 -> V_78 -> V_15 ,
V_76 ) ;
}
} else {
struct V_35 * V_35 ;
int V_36 ;
F_29 (bond, slave, i) {
V_77 = F_49 ( V_35 -> V_15 , V_76 ) ;
if ( V_77 )
return V_77 ;
}
}
return V_77 ;
}
static int F_50 ( struct V_10 * V_11 , int V_76 )
{
int V_77 = 0 ;
if ( F_48 ( V_11 -> V_46 . V_1 ) ) {
if ( V_11 -> V_78 ) {
V_77 = F_51 ( V_11 -> V_78 -> V_15 ,
V_76 ) ;
}
} else {
struct V_35 * V_35 ;
int V_36 ;
F_29 (bond, slave, i) {
V_77 = F_51 ( V_35 -> V_15 , V_76 ) ;
if ( V_77 )
return V_77 ;
}
}
return V_77 ;
}
static void F_52 ( struct V_10 * V_11 , void * V_79 )
{
if ( F_48 ( V_11 -> V_46 . V_1 ) ) {
if ( V_11 -> V_78 )
F_53 ( V_11 -> V_78 -> V_15 , V_79 ) ;
} else {
struct V_35 * V_35 ;
int V_36 ;
F_29 (bond, slave, i)
F_53 ( V_35 -> V_15 , V_79 ) ;
}
}
static void F_54 ( struct V_10 * V_11 , void * V_79 )
{
if ( F_48 ( V_11 -> V_46 . V_1 ) ) {
if ( V_11 -> V_78 )
F_55 ( V_11 -> V_78 -> V_15 , V_79 ) ;
} else {
struct V_35 * V_35 ;
int V_36 ;
F_29 (bond, slave, i) {
F_55 ( V_35 -> V_15 , V_79 ) ;
}
}
}
static void F_56 ( struct V_30 * V_15 )
{
struct V_80 * V_81 ;
F_57 () ;
V_81 = F_58 ( V_15 ) ;
if ( V_81 )
F_59 ( V_81 ) ;
F_60 () ;
}
static void F_61 ( struct V_10 * V_11 )
{
struct V_30 * V_82 ;
struct V_13 * V_14 ;
F_62 ( & V_11 -> V_20 ) ;
F_56 ( V_11 -> V_15 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_57 () ;
V_82 = F_63 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_60 () ;
if ( V_82 )
F_56 ( V_82 ) ;
}
if ( -- V_11 -> V_83 > 0 )
F_64 ( V_11 -> V_84 , & V_11 -> V_85 , V_86 / 5 ) ;
F_65 ( & V_11 -> V_20 ) ;
}
static void F_66 ( struct V_87 * V_88 )
{
struct V_10 * V_11 = F_67 ( V_88 , struct V_10 ,
V_85 . V_88 ) ;
F_61 ( V_11 ) ;
}
static void F_68 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_89 * V_90 ;
F_69 (ha, bond_dev)
F_55 ( V_31 , V_90 -> V_79 ) ;
if ( V_11 -> V_46 . V_1 == V_7 ) {
T_3 V_91 [ V_92 ] = V_93 ;
F_55 ( V_31 , V_91 ) ;
}
}
static void F_70 ( struct V_10 * V_11 , struct V_35 * V_94 ,
struct V_35 * V_95 )
{
struct V_89 * V_90 ;
if ( ! F_48 ( V_11 -> V_46 . V_1 ) )
return;
if ( V_95 ) {
if ( V_11 -> V_15 -> V_96 & V_97 )
F_49 ( V_95 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_96 & V_98 )
F_51 ( V_95 -> V_15 , - 1 ) ;
F_69 (ha, bond->dev)
F_55 ( V_95 -> V_15 , V_90 -> V_79 ) ;
}
if ( V_94 ) {
if ( V_11 -> V_15 -> V_96 & V_97 )
F_49 ( V_94 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_96 & V_98 )
F_51 ( V_94 -> V_15 , 1 ) ;
F_69 (ha, bond->dev)
F_53 ( V_94 -> V_15 , V_90 -> V_79 ) ;
}
}
static void F_71 ( struct V_10 * V_11 ,
struct V_35 * V_94 ,
struct V_35 * V_95 )
__releases( &bond->curr_slave_lock
static bool F_72 ( struct V_10 * V_11 )
{
struct V_35 * V_99 = V_11 -> V_100 ;
struct V_35 * V_24 = V_11 -> V_78 ;
if ( ! V_99 || ! V_24 || V_24 -> V_47 != V_48 )
return true ;
if ( V_11 -> V_101 ) {
V_11 -> V_101 = false ;
return true ;
}
if ( V_11 -> V_46 . V_102 == V_103 &&
( V_99 -> V_52 < V_24 -> V_52 ||
( V_99 -> V_52 == V_24 -> V_52 && V_99 -> V_54 <= V_24 -> V_54 ) ) )
return false ;
if ( V_11 -> V_46 . V_102 == V_104 )
return false ;
return true ;
}
static struct V_35 * F_73 ( struct V_10 * V_11 )
{
struct V_35 * V_94 , * V_95 ;
struct V_35 * V_105 = NULL ;
int V_106 = V_11 -> V_46 . V_107 ;
int V_36 ;
V_94 = V_11 -> V_78 ;
if ( ! V_94 ) {
if ( V_11 -> V_44 > 0 )
V_94 = V_11 -> V_108 ;
else
return NULL ;
}
if ( ( V_11 -> V_100 ) &&
V_11 -> V_100 -> V_47 == V_48 &&
F_72 ( V_11 ) ) {
V_94 = V_11 -> V_100 ;
}
V_95 = V_94 ;
F_74 (bond, new_active, i, old_active) {
if ( V_94 -> V_47 == V_48 ) {
return V_94 ;
} else if ( V_94 -> V_47 == V_109 &&
F_75 ( V_94 -> V_15 ) ) {
if ( V_94 -> V_110 < V_106 ) {
V_106 = V_94 -> V_110 ;
V_105 = V_94 ;
}
}
}
return V_105 ;
}
static bool F_76 ( struct V_10 * V_11 )
{
struct V_35 * V_35 = V_11 -> V_78 ;
F_3 ( L_16 ,
V_11 -> V_15 -> V_16 , V_35 ? V_35 -> V_15 -> V_16 : L_17 ) ;
if ( ! V_35 || ! V_11 -> V_111 ||
F_77 ( V_112 , & V_35 -> V_15 -> V_113 ) )
return false ;
V_11 -> V_111 -- ;
return true ;
}
void F_78 ( struct V_10 * V_11 , struct V_35 * V_94 )
{
struct V_35 * V_95 = V_11 -> V_78 ;
if ( V_95 == V_94 )
return;
if ( V_94 ) {
V_94 -> V_114 = V_114 ;
if ( V_94 -> V_47 == V_109 ) {
if ( F_48 ( V_11 -> V_46 . V_1 ) ) {
F_79 ( L_18 ,
V_11 -> V_15 -> V_16 , V_94 -> V_15 -> V_16 ,
( V_11 -> V_46 . V_107 - V_94 -> V_110 ) * V_11 -> V_46 . V_115 ) ;
}
V_94 -> V_110 = 0 ;
V_94 -> V_47 = V_48 ;
if ( V_11 -> V_46 . V_1 == V_7 )
F_80 ( V_94 , V_48 ) ;
if ( F_13 ( V_11 ) )
F_81 ( V_11 , V_94 , V_48 ) ;
} else {
if ( F_48 ( V_11 -> V_46 . V_1 ) ) {
F_79 ( L_19 ,
V_11 -> V_15 -> V_16 , V_94 -> V_15 -> V_16 ) ;
}
}
}
if ( F_48 ( V_11 -> V_46 . V_1 ) )
F_70 ( V_11 , V_94 , V_95 ) ;
if ( F_13 ( V_11 ) ) {
F_82 ( V_11 , V_94 ) ;
if ( V_95 )
F_83 ( V_95 ) ;
if ( V_94 )
F_84 ( V_94 ) ;
} else {
V_11 -> V_78 = V_94 ;
}
if ( V_11 -> V_46 . V_1 == V_4 ) {
if ( V_95 )
F_83 ( V_95 ) ;
if ( V_94 ) {
bool V_116 = false ;
F_84 ( V_94 ) ;
if ( V_11 -> V_46 . V_117 )
F_71 ( V_11 , V_94 ,
V_95 ) ;
if ( F_44 ( V_11 -> V_15 ) ) {
V_11 -> V_111 =
V_11 -> V_46 . V_118 ;
V_116 =
F_76 ( V_11 ) ;
}
F_8 ( & V_11 -> V_119 ) ;
F_65 ( & V_11 -> V_20 ) ;
F_85 ( V_11 -> V_15 , V_120 ) ;
if ( V_116 )
F_85 ( V_11 -> V_15 ,
V_121 ) ;
F_62 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_119 ) ;
}
}
if ( F_44 ( V_11 -> V_15 ) && ( V_11 -> V_46 . V_122 > 0 ) &&
( ( F_48 ( V_11 -> V_46 . V_1 ) && V_94 ) ||
V_11 -> V_46 . V_1 == V_3 ) ) {
V_11 -> V_83 = V_11 -> V_46 . V_122 ;
F_64 ( V_11 -> V_84 , & V_11 -> V_85 , 0 ) ;
}
}
void F_86 ( struct V_10 * V_11 )
{
struct V_35 * V_123 ;
int V_124 ;
V_123 = F_73 ( V_11 ) ;
if ( V_123 != V_11 -> V_78 ) {
F_78 ( V_11 , V_123 ) ;
V_124 = F_34 ( V_11 ) ;
if ( ! V_124 )
return;
if ( F_36 ( V_11 -> V_15 ) ) {
F_79 ( L_20 ,
V_11 -> V_15 -> V_16 ) ;
} else {
F_79 ( L_21 ,
V_11 -> V_15 -> V_16 ) ;
}
}
}
static void F_87 ( struct V_10 * V_11 , struct V_35 * V_125 )
{
if ( V_11 -> V_108 == NULL ) {
V_125 -> V_25 = V_125 ;
V_125 -> V_27 = V_125 ;
V_11 -> V_108 = V_125 ;
} else {
V_125 -> V_25 = V_11 -> V_108 ;
V_125 -> V_27 = V_11 -> V_108 -> V_27 ;
V_125 -> V_25 -> V_27 = V_125 ;
V_125 -> V_27 -> V_25 = V_125 ;
}
V_11 -> V_44 ++ ;
}
static void F_88 ( struct V_10 * V_11 , struct V_35 * V_35 )
{
if ( V_35 -> V_25 )
V_35 -> V_25 -> V_27 = V_35 -> V_27 ;
if ( V_35 -> V_27 )
V_35 -> V_27 -> V_25 = V_35 -> V_25 ;
if ( V_11 -> V_108 == V_35 ) {
if ( V_11 -> V_44 > 1 ) {
V_11 -> V_108 = V_35 -> V_25 ;
} else {
V_11 -> V_108 = NULL ;
}
}
V_35 -> V_25 = NULL ;
V_35 -> V_27 = NULL ;
V_11 -> V_44 -- ;
}
static inline int F_89 ( struct V_35 * V_35 )
{
struct V_126 * V_127 ;
int V_77 = 0 ;
V_127 = F_4 ( sizeof( * V_127 ) , V_17 ) ;
V_77 = - V_18 ;
if ( ! V_127 )
goto V_23;
V_127 -> V_15 = V_35 -> V_15 ;
F_90 ( V_127 -> V_128 , V_35 -> V_15 -> V_16 , V_70 ) ;
V_77 = F_91 ( V_127 ) ;
if ( V_77 ) {
F_15 ( V_127 ) ;
goto V_23;
}
V_35 -> V_127 = V_127 ;
V_23:
return V_77 ;
}
static inline void F_92 ( struct V_35 * V_35 )
{
struct V_126 * V_127 = V_35 -> V_127 ;
if ( ! V_127 )
return;
V_35 -> V_127 = NULL ;
F_93 () ;
F_94 ( V_127 ) ;
F_15 ( V_127 ) ;
}
static inline bool F_95 ( struct V_30 * V_31 )
{
if ( V_31 -> V_129 & V_130 )
return false ;
if ( ! V_31 -> V_39 -> V_131 )
return false ;
return true ;
}
static void F_96 ( struct V_30 * V_33 )
{
}
static void F_97 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_36 ;
F_29 (bond, slave, i)
if ( F_75 ( V_35 -> V_15 ) )
F_92 ( V_35 ) ;
}
static void F_98 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
F_62 ( & V_11 -> V_20 ) ;
F_97 ( V_11 ) ;
F_65 ( & V_11 -> V_20 ) ;
}
static int F_99 ( struct V_30 * V_15 , struct V_132 * V_133 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
struct V_35 * V_35 ;
int V_36 , V_77 = 0 ;
F_62 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
V_77 = F_89 ( V_35 ) ;
if ( V_77 ) {
F_97 ( V_11 ) ;
break;
}
}
F_65 ( & V_11 -> V_20 ) ;
return V_77 ;
}
static struct V_132 * F_100 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_134 ;
}
static inline int F_89 ( struct V_35 * V_35 )
{
return 0 ;
}
static inline void F_92 ( struct V_35 * V_35 )
{
}
static void F_98 ( struct V_30 * V_33 )
{
}
static int F_101 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
F_3 ( L_22 , V_33 ) ;
F_3 ( L_23 , V_31 ) ;
F_3 ( L_24 , V_31 -> V_135 ) ;
memcpy ( V_33 -> V_136 , V_31 -> V_136 , V_31 -> V_135 ) ;
return 0 ;
}
static T_2 F_102 ( struct V_30 * V_15 , T_2 V_40 )
{
struct V_35 * V_35 ;
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_2 V_137 ;
int V_36 ;
F_62 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_108 ) {
V_40 |= V_138 ;
goto V_23;
}
V_137 = V_40 ;
V_40 &= ~ V_139 ;
V_40 |= V_140 ;
F_29 (bond, slave, i) {
V_40 = F_103 ( V_40 ,
V_35 -> V_15 -> V_40 ,
V_137 ) ;
}
V_23:
F_65 ( & V_11 -> V_20 ) ;
return V_40 ;
}
static void F_104 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
struct V_30 * V_33 = V_11 -> V_15 ;
T_2 V_141 = V_142 ;
unsigned short V_143 = V_144 ;
int V_36 ;
F_62 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_108 )
goto V_145;
F_29 (bond, slave, i) {
V_141 = F_103 ( V_141 ,
V_35 -> V_15 -> V_141 , V_142 ) ;
if ( V_35 -> V_15 -> V_146 > V_143 )
V_143 = V_35 -> V_15 -> V_146 ;
}
V_145:
V_33 -> V_141 = V_141 ;
V_33 -> V_146 = V_143 ;
F_65 ( & V_11 -> V_20 ) ;
F_105 ( V_33 ) ;
}
static void F_106 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_33 -> V_147 = V_31 -> V_147 ;
V_33 -> type = V_31 -> type ;
V_33 -> V_146 = V_31 -> V_146 ;
V_33 -> V_135 = V_31 -> V_135 ;
memcpy ( V_33 -> V_148 , V_31 -> V_148 ,
V_31 -> V_135 ) ;
V_11 -> V_149 = 1 ;
}
static bool F_107 ( struct V_28 * V_29 ,
struct V_35 * V_35 ,
struct V_10 * V_11 )
{
if ( F_108 ( V_35 ) ) {
if ( V_11 -> V_46 . V_1 == V_9 &&
V_29 -> V_150 != V_151 &&
V_29 -> V_150 != V_152 )
return false ;
return true ;
}
return false ;
}
static T_4 F_109 ( struct V_28 * * V_153 )
{
struct V_28 * V_29 = * V_153 ;
struct V_35 * V_35 ;
struct V_10 * V_11 ;
void (* F_110)( struct V_28 * , struct V_10 * ,
struct V_35 * );
V_29 = F_111 ( V_29 , V_154 ) ;
if ( F_22 ( ! V_29 ) )
return V_155 ;
* V_153 = V_29 ;
V_35 = F_112 ( V_29 -> V_15 ) ;
V_11 = V_35 -> V_11 ;
if ( V_11 -> V_46 . V_156 )
V_35 -> V_15 -> V_157 = V_114 ;
F_110 = F_113 ( V_11 -> F_110 ) ;
if ( F_110 ) {
struct V_28 * V_158 = F_114 ( V_29 , V_154 ) ;
if ( F_115 ( V_158 ) ) {
F_110 ( V_158 , V_11 , V_35 ) ;
F_116 ( V_158 ) ;
}
}
if ( F_107 ( V_29 , V_35 , V_11 ) ) {
return V_159 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_46 . V_1 == V_9 &&
V_11 -> V_15 -> V_129 & V_160 &&
V_29 -> V_150 == V_161 ) {
if ( F_22 ( F_117 ( V_29 ,
V_29 -> V_162 - F_118 ( V_29 ) ) ) ) {
F_119 ( V_29 ) ;
return V_155 ;
}
memcpy ( F_120 ( V_29 ) -> V_163 , V_11 -> V_15 -> V_136 , V_92 ) ;
}
return V_164 ;
}
int F_121 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
const struct V_37 * V_38 = V_31 -> V_39 ;
struct V_35 * V_125 = NULL ;
struct V_89 * V_90 ;
struct V_165 V_79 ;
int V_166 ;
int V_21 = 0 ;
if ( ! V_11 -> V_46 . V_64 && V_31 -> V_66 == NULL &&
V_38 -> V_68 == NULL ) {
F_122 ( L_25 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_96 & V_167 ) {
F_3 ( L_26 ) ;
return - V_168 ;
}
if ( V_31 -> V_40 & V_138 ) {
F_3 ( L_27 , V_31 -> V_16 ) ;
if ( F_123 ( V_11 ) ) {
F_30 ( L_28 ,
V_33 -> V_16 , V_31 -> V_16 , V_33 -> V_16 ) ;
return - V_169 ;
} else {
F_122 ( L_29 ,
V_33 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_33 -> V_16 ) ;
}
} else {
F_3 ( L_30 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_96 & V_170 ) ) {
F_30 ( L_31 ,
V_31 -> V_16 ) ;
V_21 = - V_169 ;
goto V_171;
}
if ( V_11 -> V_44 == 0 ) {
if ( V_33 -> type != V_31 -> type ) {
F_3 ( L_32 ,
V_33 -> V_16 ,
V_33 -> type , V_31 -> type ) ;
V_21 = F_85 ( V_33 ,
V_172 ) ;
V_21 = F_124 ( V_21 ) ;
if ( V_21 ) {
F_30 ( L_33 ,
V_33 -> V_16 ) ;
V_21 = - V_168 ;
goto V_171;
}
F_125 ( V_33 ) ;
F_126 ( V_33 ) ;
if ( V_31 -> type != V_173 )
F_106 ( V_33 , V_31 ) ;
else {
F_127 ( V_33 ) ;
V_33 -> V_129 &= ~ V_174 ;
}
F_85 ( V_33 ,
V_175 ) ;
}
} else if ( V_33 -> type != V_31 -> type ) {
F_30 ( L_34 ,
V_31 -> V_16 ,
V_31 -> type , V_33 -> type ) ;
V_21 = - V_176 ;
goto V_171;
}
if ( V_38 -> V_177 == NULL ) {
if ( V_11 -> V_44 == 0 ) {
F_122 ( L_35 ,
V_33 -> V_16 ) ;
V_11 -> V_46 . V_117 = V_178 ;
} else if ( V_11 -> V_46 . V_117 != V_178 ) {
F_30 ( L_36 ,
V_33 -> V_16 ) ;
V_21 = - V_179 ;
goto V_171;
}
}
F_128 ( V_180 , V_31 ) ;
if ( F_129 ( V_11 -> V_15 -> V_136 ) )
memcpy ( V_11 -> V_15 -> V_136 , V_31 -> V_136 ,
V_31 -> V_135 ) ;
V_125 = F_4 ( sizeof( struct V_35 ) , V_17 ) ;
if ( ! V_125 ) {
V_21 = - V_18 ;
goto V_171;
}
V_125 -> V_181 = 0 ;
V_125 -> V_182 = V_31 -> V_183 ;
V_21 = F_130 ( V_31 , V_11 -> V_15 -> V_183 ) ;
if ( V_21 ) {
F_3 ( L_37 , V_21 ) ;
goto V_184;
}
memcpy ( V_125 -> V_185 , V_31 -> V_136 , V_92 ) ;
if ( ! V_11 -> V_46 . V_117 ) {
memcpy ( V_79 . V_186 , V_33 -> V_136 , V_33 -> V_135 ) ;
V_79 . V_187 = V_31 -> type ;
V_21 = F_131 ( V_31 , & V_79 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_188;
}
}
V_21 = F_132 ( V_31 , V_33 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_189;
}
V_21 = F_133 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_31 -> V_16 ) ;
goto V_190;
}
V_125 -> V_11 = V_11 ;
V_125 -> V_15 = V_31 ;
V_31 -> V_129 |= V_191 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_134 ( V_11 , V_125 ) ;
if ( V_21 )
goto V_192;
}
if ( ! F_48 ( V_11 -> V_46 . V_1 ) ) {
if ( V_33 -> V_96 & V_97 ) {
V_21 = F_49 ( V_31 , 1 ) ;
if ( V_21 )
goto V_192;
}
if ( V_33 -> V_96 & V_98 ) {
V_21 = F_51 ( V_31 , 1 ) ;
if ( V_21 )
goto V_192;
}
F_135 ( V_33 ) ;
F_69 (ha, bond_dev)
F_53 ( V_31 , V_90 -> V_79 ) ;
F_136 ( V_33 ) ;
}
if ( V_11 -> V_46 . V_1 == V_7 ) {
T_3 V_91 [ V_92 ] = V_93 ;
F_53 ( V_31 , V_91 ) ;
}
F_32 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_87 ( V_11 , V_125 ) ;
V_125 -> V_110 = 0 ;
V_125 -> V_193 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_104 ( V_11 ) ;
F_62 ( & V_11 -> V_20 ) ;
V_125 -> V_194 = V_114 ;
if ( V_11 -> V_46 . V_115 && ! V_11 -> V_46 . V_64 ) {
V_166 = F_42 ( V_11 , V_31 , 1 ) ;
if ( ( V_166 == - 1 ) && ! V_11 -> V_46 . V_156 ) {
F_122 ( L_41 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_166 == - 1 ) {
F_122 ( L_42 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
}
if ( ! V_11 -> V_46 . V_115 ||
( F_42 ( V_11 , V_31 , 0 ) == V_65 ) ) {
if ( V_11 -> V_46 . V_107 ) {
F_3 ( L_43 ) ;
V_125 -> V_47 = V_109 ;
V_125 -> V_110 = V_11 -> V_46 . V_107 ;
} else {
F_3 ( L_44 ) ;
V_125 -> V_47 = V_48 ;
}
V_125 -> V_114 = V_114 ;
} else {
F_3 ( L_45 ) ;
V_125 -> V_47 = V_195 ;
}
F_39 ( V_125 ) ;
if ( F_48 ( V_11 -> V_46 . V_1 ) && V_11 -> V_46 . V_196 [ 0 ] ) {
if ( strcmp ( V_11 -> V_46 . V_196 , V_125 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_100 = V_125 ;
V_11 -> V_101 = true ;
}
}
F_6 ( & V_11 -> V_119 ) ;
switch ( V_11 -> V_46 . V_1 ) {
case V_4 :
F_83 ( V_125 ) ;
F_86 ( V_11 ) ;
break;
case V_7 :
F_83 ( V_125 ) ;
if ( V_11 -> V_44 == 1 ) {
F_137 ( V_125 ) . V_197 = 1 ;
F_138 ( V_11 , 1000 / V_198 ) ;
} else {
F_137 ( V_125 ) . V_197 =
F_137 ( V_125 -> V_27 ) . V_197 + 1 ;
}
F_139 ( V_125 ) ;
break;
case V_8 :
case V_9 :
F_140 ( V_125 ) ;
F_83 ( V_125 ) ;
F_86 ( V_11 ) ;
break;
default:
F_3 ( L_46 ) ;
F_140 ( V_125 ) ;
if ( ! V_11 -> V_78 )
V_11 -> V_78 = V_125 ;
break;
}
F_8 ( & V_11 -> V_119 ) ;
F_34 ( V_11 ) ;
#ifdef F_141
V_31 -> V_134 = F_100 ( V_11 ) ;
if ( V_31 -> V_134 ) {
if ( F_89 ( V_125 ) ) {
F_65 ( & V_11 -> V_20 ) ;
F_79 ( L_47
L_48 ,
V_33 -> V_16 ) ;
V_21 = - V_168 ;
goto V_192;
}
}
#endif
F_65 ( & V_11 -> V_20 ) ;
V_21 = F_142 ( V_33 , V_31 ) ;
if ( V_21 )
goto V_192;
V_21 = F_143 ( V_31 , F_109 ,
V_125 ) ;
if ( V_21 ) {
F_3 ( L_49 , V_21 ) ;
goto V_199;
}
F_79 ( L_50 ,
V_33 -> V_16 , V_31 -> V_16 ,
F_144 ( V_125 ) ? L_51 : L_52 ,
V_125 -> V_47 != V_195 ? L_53 : L_54 ) ;
return 0 ;
V_199:
F_145 ( V_33 , V_31 ) ;
V_192:
F_146 ( V_31 ) ;
V_190:
F_132 ( V_31 , NULL ) ;
V_189:
if ( ! V_11 -> V_46 . V_117 ) {
memcpy ( V_79 . V_186 , V_125 -> V_185 , V_92 ) ;
V_79 . V_187 = V_31 -> type ;
F_131 ( V_31 , & V_79 ) ;
}
V_188:
F_130 ( V_31 , V_125 -> V_182 ) ;
V_184:
F_15 ( V_125 ) ;
V_171:
F_104 ( V_11 ) ;
return V_21 ;
}
int F_147 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_200 ;
struct V_165 V_79 ;
T_2 V_201 = V_33 -> V_40 ;
if ( ! ( V_31 -> V_96 & V_167 ) ||
( V_31 -> V_202 != V_33 ) ) {
F_30 ( L_55 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
return - V_176 ;
}
F_10 () ;
F_85 ( V_33 , V_203 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_35 = F_25 ( V_11 , V_31 ) ;
if ( ! V_35 ) {
F_79 ( L_56 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_176 ;
}
F_148 ( V_31 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_149 () ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_46 . V_117 ) {
if ( ! F_150 ( V_33 -> V_136 , V_35 -> V_185 ) &&
V_11 -> V_44 > 1 )
F_122 ( L_57 ,
V_33 -> V_16 , V_31 -> V_16 ,
V_35 -> V_185 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_46 . V_1 == V_7 ) {
F_151 ( V_35 ) ;
}
F_79 ( L_58 ,
V_33 -> V_16 ,
F_144 ( V_35 ) ? L_59 : L_60 ,
V_31 -> V_16 ) ;
V_200 = V_11 -> V_78 ;
V_11 -> V_204 = NULL ;
F_88 ( V_11 , V_35 ) ;
if ( V_11 -> V_100 == V_35 )
V_11 -> V_100 = NULL ;
if ( V_200 == V_35 )
F_78 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_152 ( V_11 , V_35 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_200 == V_35 ) {
F_8 ( & V_11 -> V_20 ) ;
F_62 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_119 ) ;
F_86 ( V_11 ) ;
F_8 ( & V_11 -> V_119 ) ;
F_65 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_44 == 0 ) {
F_34 ( V_11 ) ;
memset ( V_33 -> V_136 , 0 , V_33 -> V_135 ) ;
if ( F_123 ( V_11 ) ) {
F_122 ( L_61 ,
V_33 -> V_16 , V_33 -> V_16 ) ;
F_122 ( L_62 ,
V_33 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
F_104 ( V_11 ) ;
if ( ! ( V_33 -> V_40 & V_138 ) &&
( V_201 & V_138 ) )
F_79 ( L_63 ,
V_33 -> V_16 , V_31 -> V_16 , V_33 -> V_16 ) ;
F_145 ( V_33 , V_31 ) ;
F_33 ( V_11 , V_31 ) ;
if ( ! F_48 ( V_11 -> V_46 . V_1 ) ) {
if ( V_33 -> V_96 & V_97 )
F_49 ( V_31 , - 1 ) ;
if ( V_33 -> V_96 & V_98 )
F_51 ( V_31 , - 1 ) ;
F_135 ( V_33 ) ;
F_68 ( V_33 , V_31 ) ;
F_136 ( V_33 ) ;
}
F_132 ( V_31 , NULL ) ;
F_92 ( V_35 ) ;
F_146 ( V_31 ) ;
if ( V_11 -> V_46 . V_117 != V_178 ) {
memcpy ( V_79 . V_186 , V_35 -> V_185 , V_92 ) ;
V_79 . V_187 = V_31 -> type ;
F_131 ( V_31 , & V_79 ) ;
}
F_130 ( V_31 , V_35 -> V_182 ) ;
V_31 -> V_129 &= ~ V_191 ;
F_15 ( V_35 ) ;
return 0 ;
}
static int F_153 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
int V_205 ;
V_205 = F_147 ( V_33 , V_31 ) ;
if ( ( V_205 == 0 ) && ( V_11 -> V_44 == 0 ) ) {
V_33 -> V_129 |= V_130 ;
F_79 ( L_64 ,
V_33 -> V_16 , V_33 -> V_16 ) ;
F_154 ( V_33 ) ;
}
return V_205 ;
}
static int F_155 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
struct V_30 * V_31 ;
struct V_165 V_79 ;
F_6 ( & V_11 -> V_20 ) ;
F_38 ( V_33 ) ;
if ( V_11 -> V_44 == 0 )
goto V_23;
V_11 -> V_204 = NULL ;
V_11 -> V_100 = NULL ;
F_78 ( V_11 , NULL ) ;
while ( ( V_35 = V_11 -> V_108 ) != NULL ) {
if ( V_11 -> V_46 . V_1 == V_7 )
F_151 ( V_35 ) ;
V_31 = V_35 -> V_15 ;
F_88 ( V_11 , V_35 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_148 ( V_31 ) ;
F_149 () ;
if ( F_13 ( V_11 ) ) {
F_152 ( V_11 , V_35 ) ;
}
F_145 ( V_33 , V_31 ) ;
F_33 ( V_11 , V_31 ) ;
if ( ! F_48 ( V_11 -> V_46 . V_1 ) ) {
if ( V_33 -> V_96 & V_97 )
F_49 ( V_31 , - 1 ) ;
if ( V_33 -> V_96 & V_98 )
F_51 ( V_31 , - 1 ) ;
F_135 ( V_33 ) ;
F_68 ( V_33 , V_31 ) ;
F_136 ( V_33 ) ;
}
F_132 ( V_31 , NULL ) ;
F_92 ( V_35 ) ;
F_146 ( V_31 ) ;
if ( ! V_11 -> V_46 . V_117 ) {
memcpy ( V_79 . V_186 , V_35 -> V_185 , V_92 ) ;
V_79 . V_187 = V_31 -> type ;
F_131 ( V_31 , & V_79 ) ;
}
F_15 ( V_35 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
memset ( V_33 -> V_136 , 0 , V_33 -> V_135 ) ;
if ( F_123 ( V_11 ) ) {
F_122 ( L_61 ,
V_33 -> V_16 , V_33 -> V_16 ) ;
F_122 ( L_62 ,
V_33 -> V_16 ) ;
}
F_79 ( L_65 , V_33 -> V_16 ) ;
V_23:
F_8 ( & V_11 -> V_20 ) ;
F_104 ( V_11 ) ;
return 0 ;
}
static int F_156 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_95 = NULL ;
struct V_35 * V_94 = NULL ;
int V_21 = 0 ;
if ( ! F_48 ( V_11 -> V_46 . V_1 ) )
return - V_176 ;
if ( ! ( V_31 -> V_96 & V_167 ) || ( V_31 -> V_202 != V_33 ) )
return - V_176 ;
F_62 ( & V_11 -> V_20 ) ;
F_62 ( & V_11 -> V_119 ) ;
V_95 = V_11 -> V_78 ;
F_65 ( & V_11 -> V_119 ) ;
V_94 = F_25 ( V_11 , V_31 ) ;
if ( V_94 && ( V_94 == V_95 ) ) {
F_65 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_94 ) &&
( V_95 ) &&
( V_94 -> V_47 == V_48 ) &&
F_75 ( V_94 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_119 ) ;
F_78 ( V_11 , V_94 ) ;
F_8 ( & V_11 -> V_119 ) ;
F_16 () ;
} else
V_21 = - V_176 ;
F_65 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_157 ( struct V_30 * V_33 , struct V_206 * V_207 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_207 -> V_208 = V_11 -> V_46 . V_1 ;
V_207 -> V_115 = V_11 -> V_46 . V_115 ;
F_62 ( & V_11 -> V_20 ) ;
V_207 -> V_209 = V_11 -> V_44 ;
F_65 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_158 ( struct V_30 * V_33 , struct V_210 * V_207 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_36 , V_21 = - V_22 ;
F_62 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
if ( V_36 == ( int ) V_207 -> V_211 ) {
V_21 = 0 ;
strcpy ( V_207 -> V_212 , V_35 -> V_15 -> V_16 ) ;
V_207 -> V_47 = V_35 -> V_47 ;
V_207 -> V_113 = F_159 ( V_35 ) ;
V_207 -> V_193 = V_35 -> V_193 ;
break;
}
}
F_65 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_160 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_36 , V_213 , V_214 = 0 ;
bool V_215 ;
V_215 = ! V_11 -> V_78 ? true : false ;
F_29 (bond, slave, i) {
V_35 -> V_216 = V_217 ;
V_213 = F_42 ( V_11 , V_35 -> V_15 , 0 ) ;
switch ( V_35 -> V_47 ) {
case V_48 :
if ( V_213 )
continue;
V_35 -> V_47 = V_218 ;
V_35 -> V_110 = V_11 -> V_46 . V_219 ;
if ( V_35 -> V_110 ) {
F_79 ( L_66 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_46 . V_1 ==
V_4 ) ?
( F_144 ( V_35 ) ?
L_67 : L_68 ) : L_69 ,
V_35 -> V_15 -> V_16 ,
V_11 -> V_46 . V_219 * V_11 -> V_46 . V_115 ) ;
}
case V_218 :
if ( V_213 ) {
V_35 -> V_47 = V_48 ;
V_35 -> V_114 = V_114 ;
F_79 ( L_70 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_46 . V_219 - V_35 -> V_110 ) *
V_11 -> V_46 . V_115 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
if ( V_35 -> V_110 <= 0 ) {
V_35 -> V_216 = V_195 ;
V_214 ++ ;
continue;
}
V_35 -> V_110 -- ;
break;
case V_195 :
if ( ! V_213 )
continue;
V_35 -> V_47 = V_109 ;
V_35 -> V_110 = V_11 -> V_46 . V_107 ;
if ( V_35 -> V_110 ) {
F_79 ( L_71 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ,
V_215 ? 0 :
V_11 -> V_46 . V_107 *
V_11 -> V_46 . V_115 ) ;
}
case V_109 :
if ( ! V_213 ) {
V_35 -> V_47 = V_195 ;
F_79 ( L_72 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_46 . V_107 - V_35 -> V_110 ) *
V_11 -> V_46 . V_115 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
if ( V_215 )
V_35 -> V_110 = 0 ;
if ( V_35 -> V_110 <= 0 ) {
V_35 -> V_216 = V_48 ;
V_214 ++ ;
V_215 = false ;
continue;
}
V_35 -> V_110 -- ;
break;
}
}
return V_214 ;
}
static void F_161 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_36 ;
F_29 (bond, slave, i) {
switch ( V_35 -> V_216 ) {
case V_217 :
continue;
case V_48 :
V_35 -> V_47 = V_48 ;
V_35 -> V_114 = V_114 ;
if ( V_11 -> V_46 . V_1 == V_7 ) {
F_162 ( V_35 ) ;
} else if ( V_11 -> V_46 . V_1 != V_4 ) {
F_140 ( V_35 ) ;
} else if ( V_35 != V_11 -> V_100 ) {
F_162 ( V_35 ) ;
}
F_39 ( V_35 ) ;
F_79 ( L_73 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ,
V_35 -> V_52 , V_35 -> V_54 ? L_74 : L_75 ) ;
if ( V_11 -> V_46 . V_1 == V_7 )
F_80 ( V_35 , V_48 ) ;
if ( F_13 ( V_11 ) )
F_81 ( V_11 , V_35 ,
V_48 ) ;
if ( ! V_11 -> V_78 ||
( V_35 == V_11 -> V_100 ) )
goto V_220;
continue;
case V_195 :
if ( V_35 -> V_193 < V_221 )
V_35 -> V_193 ++ ;
V_35 -> V_47 = V_195 ;
if ( V_11 -> V_46 . V_1 == V_4 ||
V_11 -> V_46 . V_1 == V_7 )
F_83 ( V_35 ) ;
F_79 ( L_76 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( V_11 -> V_46 . V_1 == V_7 )
F_80 ( V_35 ,
V_195 ) ;
if ( F_13 ( V_11 ) )
F_81 ( V_11 , V_35 ,
V_195 ) ;
if ( V_35 == V_11 -> V_78 )
goto V_220;
continue;
default:
F_30 ( L_77 ,
V_11 -> V_15 -> V_16 , V_35 -> V_216 ,
V_35 -> V_15 -> V_16 ) ;
V_35 -> V_216 = V_217 ;
continue;
}
V_220:
F_163 () ;
F_10 () ;
F_6 ( & V_11 -> V_119 ) ;
F_86 ( V_11 ) ;
F_8 ( & V_11 -> V_119 ) ;
F_16 () ;
}
F_34 ( V_11 ) ;
}
void F_164 ( struct V_87 * V_88 )
{
struct V_10 * V_11 = F_67 ( V_88 , struct V_10 ,
V_222 . V_88 ) ;
bool V_116 = false ;
unsigned long V_110 ;
F_62 ( & V_11 -> V_20 ) ;
V_110 = F_165 ( V_11 -> V_46 . V_115 ) ;
if ( V_11 -> V_44 == 0 )
goto V_223;
V_116 = F_76 ( V_11 ) ;
if ( F_160 ( V_11 ) ) {
F_65 ( & V_11 -> V_20 ) ;
if ( ! F_166 () ) {
F_62 ( & V_11 -> V_20 ) ;
V_110 = 1 ;
V_116 = false ;
goto V_223;
}
F_62 ( & V_11 -> V_20 ) ;
F_161 ( V_11 ) ;
F_65 ( & V_11 -> V_20 ) ;
F_167 () ;
F_62 ( & V_11 -> V_20 ) ;
}
V_223:
if ( V_11 -> V_46 . V_115 )
F_64 ( V_11 -> V_84 , & V_11 -> V_222 , V_110 ) ;
F_65 ( & V_11 -> V_20 ) ;
if ( V_116 ) {
if ( ! F_166 () ) {
F_62 ( & V_11 -> V_20 ) ;
V_11 -> V_111 ++ ;
F_65 ( & V_11 -> V_20 ) ;
return;
}
F_85 ( V_11 -> V_15 , V_121 ) ;
F_167 () ;
}
}
static int F_168 ( struct V_10 * V_11 , T_5 V_224 )
{
struct V_13 * V_14 ;
if ( V_224 == V_11 -> V_225 )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( V_224 == V_14 -> V_226 )
return 1 ;
}
return 0 ;
}
static void F_169 ( struct V_30 * V_31 , int V_227 , T_5 V_228 , T_5 V_229 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_78 , V_227 ,
V_31 -> V_16 , V_228 , V_229 , V_12 ) ;
V_29 = F_170 ( V_227 , V_230 , V_228 , V_31 , V_229 ,
NULL , V_31 -> V_136 , NULL ) ;
if ( ! V_29 ) {
F_30 ( L_79 ) ;
return;
}
if ( V_12 ) {
V_29 = F_171 ( V_29 , V_12 ) ;
if ( ! V_29 ) {
F_30 ( L_80 ) ;
return;
}
}
F_172 ( V_29 ) ;
}
static void F_173 ( struct V_10 * V_11 , struct V_35 * V_35 )
{
int V_36 , V_12 ;
T_5 * V_231 = V_11 -> V_46 . V_232 ;
struct V_13 * V_14 ;
struct V_30 * V_82 ;
struct V_233 * V_234 ;
for ( V_36 = 0 ; ( V_36 < V_235 ) ; V_36 ++ ) {
if ( ! V_231 [ V_36 ] )
break;
F_3 ( L_81 , V_231 [ V_36 ] ) ;
if ( ! F_123 ( V_11 ) ) {
F_3 ( L_82 ) ;
F_169 ( V_35 -> V_15 , V_236 , V_231 [ V_36 ] ,
V_11 -> V_225 , 0 ) ;
continue;
}
V_234 = F_174 ( F_175 ( V_11 -> V_15 ) , V_231 [ V_36 ] , 0 ,
V_237 , 0 ) ;
if ( F_176 ( V_234 ) ) {
if ( F_177 () ) {
F_122 ( L_83 ,
V_11 -> V_15 -> V_16 , & V_231 [ V_36 ] ) ;
}
continue;
}
if ( V_234 -> V_238 . V_15 == V_11 -> V_15 ) {
F_178 ( V_234 ) ;
F_3 ( L_84 ) ;
F_169 ( V_35 -> V_15 , V_236 , V_231 [ V_36 ] ,
V_11 -> V_225 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_57 () ;
V_82 = F_63 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_60 () ;
if ( V_82 == V_234 -> V_238 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_85 ,
V_82 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 ) {
F_178 ( V_234 ) ;
F_169 ( V_35 -> V_15 , V_236 , V_231 [ V_36 ] ,
V_14 -> V_226 , V_12 ) ;
continue;
}
if ( F_177 () ) {
F_122 ( L_86 ,
V_11 -> V_15 -> V_16 , & V_231 [ V_36 ] ,
V_234 -> V_238 . V_15 ? V_234 -> V_238 . V_15 -> V_16 : L_17 ) ;
}
F_178 ( V_234 ) ;
}
}
static void F_179 ( struct V_10 * V_11 , struct V_35 * V_35 , T_5 V_239 , T_5 V_240 )
{
int V_36 ;
T_5 * V_231 = V_11 -> V_46 . V_232 ;
for ( V_36 = 0 ; ( V_36 < V_235 ) && V_231 [ V_36 ] ; V_36 ++ ) {
F_3 ( L_87 ,
& V_239 , & V_240 , V_36 , & V_231 [ V_36 ] ,
F_168 ( V_11 , V_240 ) ) ;
if ( V_239 == V_231 [ V_36 ] ) {
if ( F_168 ( V_11 , V_240 ) )
V_35 -> V_194 = V_114 ;
return;
}
}
}
static void F_180 ( struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_35 * V_35 )
{
struct V_241 * V_242 ;
unsigned char * V_243 ;
T_5 V_239 , V_240 ;
if ( V_29 -> V_244 != F_181 ( V_230 ) )
return;
F_62 ( & V_11 -> V_20 ) ;
F_3 ( L_88 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( ! F_182 ( V_29 , F_183 ( V_11 -> V_15 ) ) )
goto V_245;
V_242 = F_184 ( V_29 ) ;
if ( V_242 -> V_246 != V_11 -> V_15 -> V_135 ||
V_29 -> V_150 == V_247 ||
V_29 -> V_150 == V_248 ||
V_242 -> V_249 != F_185 ( V_173 ) ||
V_242 -> V_250 != F_185 ( V_251 ) ||
V_242 -> V_252 != 4 )
goto V_245;
V_243 = ( unsigned char * ) ( V_242 + 1 ) ;
V_243 += V_11 -> V_15 -> V_135 ;
memcpy ( & V_239 , V_243 , 4 ) ;
V_243 += 4 + V_11 -> V_15 -> V_135 ;
memcpy ( & V_240 , V_243 , 4 ) ;
F_3 ( L_89 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 , F_159 ( V_35 ) ,
V_11 -> V_46 . V_253 , F_186 ( V_11 , V_35 ) ,
& V_239 , & V_240 ) ;
if ( F_144 ( V_35 ) )
F_179 ( V_11 , V_35 , V_239 , V_240 ) ;
else
F_179 ( V_11 , V_35 , V_240 , V_239 ) ;
V_245:
F_65 ( & V_11 -> V_20 ) ;
}
void F_187 ( struct V_87 * V_88 )
{
struct V_10 * V_11 = F_67 ( V_88 , struct V_10 ,
V_254 . V_88 ) ;
struct V_35 * V_35 , * V_200 ;
int V_220 = 0 ;
int V_255 ;
int V_36 ;
F_62 ( & V_11 -> V_20 ) ;
V_255 = F_165 ( V_11 -> V_46 . V_156 ) ;
if ( V_11 -> V_44 == 0 )
goto V_223;
F_62 ( & V_11 -> V_119 ) ;
V_200 = V_11 -> V_78 ;
F_65 ( & V_11 -> V_119 ) ;
F_29 (bond, slave, i) {
unsigned long V_256 = F_188 ( V_35 -> V_15 ) ;
if ( V_35 -> V_47 != V_48 ) {
if ( F_189 ( V_114 ,
V_256 - V_255 ,
V_256 + V_255 ) &&
F_189 ( V_114 ,
V_35 -> V_15 -> V_157 - V_255 ,
V_35 -> V_15 -> V_157 + V_255 ) ) {
V_35 -> V_47 = V_48 ;
F_140 ( V_35 ) ;
if ( ! V_200 ) {
F_79 ( L_90 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
V_220 = 1 ;
} else {
F_79 ( L_91 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_189 ( V_114 ,
V_256 - V_255 ,
V_256 + 2 * V_255 ) ||
! F_189 ( V_114 ,
V_35 -> V_15 -> V_157 - V_255 ,
V_35 -> V_15 -> V_157 + 2 * V_255 ) ) {
V_35 -> V_47 = V_195 ;
F_162 ( V_35 ) ;
if ( V_35 -> V_193 < V_221 )
V_35 -> V_193 ++ ;
F_79 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
if ( V_35 == V_200 )
V_220 = 1 ;
}
}
if ( F_75 ( V_35 -> V_15 ) )
F_173 ( V_11 , V_35 ) ;
}
if ( V_220 ) {
F_10 () ;
F_6 ( & V_11 -> V_119 ) ;
F_86 ( V_11 ) ;
F_8 ( & V_11 -> V_119 ) ;
F_16 () ;
}
V_223:
if ( V_11 -> V_46 . V_156 )
F_64 ( V_11 -> V_84 , & V_11 -> V_254 , V_255 ) ;
F_65 ( & V_11 -> V_20 ) ;
}
static int F_190 ( struct V_10 * V_11 , int V_255 )
{
struct V_35 * V_35 ;
int V_36 , V_214 = 0 ;
unsigned long V_256 ;
F_29 (bond, slave, i) {
V_35 -> V_216 = V_217 ;
if ( V_35 -> V_47 != V_48 ) {
if ( F_189 ( V_114 ,
F_191 ( V_11 , V_35 ) - V_255 ,
F_191 ( V_11 , V_35 ) + V_255 ) ) {
V_35 -> V_216 = V_48 ;
V_214 ++ ;
}
continue;
}
if ( F_189 ( V_114 ,
V_35 -> V_114 - V_255 ,
V_35 -> V_114 + 2 * V_255 ) )
continue;
if ( ! F_144 ( V_35 ) &&
! V_11 -> V_204 &&
! F_189 ( V_114 ,
F_191 ( V_11 , V_35 ) - V_255 ,
F_191 ( V_11 , V_35 ) + 3 * V_255 ) ) {
V_35 -> V_216 = V_195 ;
V_214 ++ ;
}
V_256 = F_188 ( V_35 -> V_15 ) ;
if ( F_144 ( V_35 ) &&
( ! F_189 ( V_114 ,
V_256 - V_255 ,
V_256 + 2 * V_255 ) ||
! F_189 ( V_114 ,
F_191 ( V_11 , V_35 ) - V_255 ,
F_191 ( V_11 , V_35 ) + 2 * V_255 ) ) ) {
V_35 -> V_216 = V_195 ;
V_214 ++ ;
}
}
return V_214 ;
}
static void F_192 ( struct V_10 * V_11 , int V_255 )
{
struct V_35 * V_35 ;
int V_36 ;
unsigned long V_256 ;
F_29 (bond, slave, i) {
switch ( V_35 -> V_216 ) {
case V_217 :
continue;
case V_48 :
V_256 = F_188 ( V_35 -> V_15 ) ;
if ( ( ! V_11 -> V_78 &&
F_189 ( V_114 ,
V_256 - V_255 ,
V_256 + V_255 ) ) ||
V_11 -> V_78 != V_35 ) {
V_35 -> V_47 = V_48 ;
V_11 -> V_204 = NULL ;
F_79 ( L_93 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_78 ||
( V_35 == V_11 -> V_100 ) )
goto V_220;
}
continue;
case V_195 :
if ( V_35 -> V_193 < V_221 )
V_35 -> V_193 ++ ;
V_35 -> V_47 = V_195 ;
F_83 ( V_35 ) ;
F_79 ( L_76 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( V_35 == V_11 -> V_78 ) {
V_11 -> V_204 = NULL ;
goto V_220;
}
continue;
default:
F_30 ( L_94 ,
V_11 -> V_15 -> V_16 , V_35 -> V_216 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
V_220:
F_163 () ;
F_10 () ;
F_6 ( & V_11 -> V_119 ) ;
F_86 ( V_11 ) ;
F_8 ( & V_11 -> V_119 ) ;
F_16 () ;
}
F_34 ( V_11 ) ;
}
static void F_193 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_36 ;
F_62 ( & V_11 -> V_119 ) ;
if ( V_11 -> V_204 && V_11 -> V_78 )
F_79 ( L_95 ,
V_11 -> V_204 -> V_15 -> V_16 ,
V_11 -> V_78 -> V_15 -> V_16 ) ;
if ( V_11 -> V_78 ) {
F_173 ( V_11 , V_11 -> V_78 ) ;
F_65 ( & V_11 -> V_119 ) ;
return;
}
F_65 ( & V_11 -> V_119 ) ;
if ( ! V_11 -> V_204 ) {
V_11 -> V_204 = V_11 -> V_108 ;
if ( ! V_11 -> V_204 )
return;
}
F_83 ( V_11 -> V_204 ) ;
F_74 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_75 ( V_35 -> V_15 ) ) {
V_35 -> V_47 = V_109 ;
F_84 ( V_35 ) ;
F_173 ( V_11 , V_35 ) ;
V_35 -> V_114 = V_114 ;
V_11 -> V_204 = V_35 ;
break;
}
if ( V_35 -> V_47 == V_48 ) {
V_35 -> V_47 = V_195 ;
if ( V_35 -> V_193 < V_221 )
V_35 -> V_193 ++ ;
F_83 ( V_35 ) ;
F_79 ( L_96 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
}
}
}
void F_194 ( struct V_87 * V_88 )
{
struct V_10 * V_11 = F_67 ( V_88 , struct V_10 ,
V_254 . V_88 ) ;
bool V_116 = false ;
int V_255 ;
F_62 ( & V_11 -> V_20 ) ;
V_255 = F_165 ( V_11 -> V_46 . V_156 ) ;
if ( V_11 -> V_44 == 0 )
goto V_223;
V_116 = F_76 ( V_11 ) ;
if ( F_190 ( V_11 , V_255 ) ) {
F_65 ( & V_11 -> V_20 ) ;
if ( ! F_166 () ) {
F_62 ( & V_11 -> V_20 ) ;
V_255 = 1 ;
V_116 = false ;
goto V_223;
}
F_62 ( & V_11 -> V_20 ) ;
F_192 ( V_11 , V_255 ) ;
F_65 ( & V_11 -> V_20 ) ;
F_167 () ;
F_62 ( & V_11 -> V_20 ) ;
}
F_193 ( V_11 ) ;
V_223:
if ( V_11 -> V_46 . V_156 )
F_64 ( V_11 -> V_84 , & V_11 -> V_254 , V_255 ) ;
F_65 ( & V_11 -> V_20 ) ;
if ( V_116 ) {
if ( ! F_166 () ) {
F_62 ( & V_11 -> V_20 ) ;
V_11 -> V_111 ++ ;
F_65 ( & V_11 -> V_20 ) ;
return;
}
F_85 ( V_11 -> V_15 , V_121 ) ;
F_167 () ;
}
}
static int F_195 ( struct V_10 * V_11 )
{
F_196 ( V_11 ) ;
F_197 ( V_11 ) ;
F_198 ( V_11 ) ;
return V_257 ;
}
static int F_199 ( unsigned long V_258 ,
struct V_30 * V_33 )
{
struct V_10 * V_259 = F_28 ( V_33 ) ;
switch ( V_258 ) {
case V_260 :
return F_195 ( V_259 ) ;
default:
break;
}
return V_257 ;
}
static int F_200 ( unsigned long V_258 ,
struct V_30 * V_31 )
{
struct V_30 * V_33 = V_31 -> V_202 ;
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 = NULL ;
switch ( V_258 ) {
case V_261 :
if ( V_33 ) {
if ( V_11 -> V_149 )
F_153 ( V_33 , V_31 ) ;
else
F_147 ( V_33 , V_31 ) ;
}
break;
case V_262 :
case V_263 :
V_35 = F_25 ( V_11 , V_31 ) ;
if ( V_35 ) {
T_2 V_264 = V_35 -> V_52 ;
T_3 V_265 = V_35 -> V_54 ;
F_39 ( V_35 ) ;
if ( V_11 -> V_46 . V_1 == V_7 ) {
if ( V_264 != V_35 -> V_52 )
F_201 ( V_35 ) ;
if ( V_265 != V_35 -> V_54 )
F_202 ( V_35 ) ;
}
}
break;
case V_266 :
break;
case V_267 :
break;
case V_260 :
break;
case V_268 :
F_104 ( V_11 ) ;
break;
default:
break;
}
return V_257 ;
}
static int F_203 ( struct V_269 * V_270 ,
unsigned long V_258 , void * V_271 )
{
struct V_30 * V_272 = (struct V_30 * ) V_271 ;
F_3 ( L_97 ,
V_272 ? V_272 -> V_16 : L_10 ,
V_258 ) ;
if ( ! ( V_272 -> V_129 & V_191 ) )
return V_257 ;
if ( V_272 -> V_96 & V_273 ) {
F_3 ( L_98 ) ;
return F_199 ( V_258 , V_272 ) ;
}
if ( V_272 -> V_96 & V_167 ) {
F_3 ( L_99 ) ;
return F_200 ( V_258 , V_272 ) ;
}
return V_257 ;
}
static int F_204 ( struct V_269 * V_270 , unsigned long V_258 , void * V_271 )
{
struct V_274 * V_275 = V_271 ;
struct V_30 * V_82 , * V_272 = V_275 -> V_276 -> V_15 ;
struct V_277 * V_278 = F_205 ( F_175 ( V_272 ) , V_279 ) ;
struct V_10 * V_11 ;
struct V_13 * V_14 ;
if( V_275 -> V_280 & V_281 )
return V_257 ;
F_11 (bond, &bn->dev_list, bond_list) {
if ( V_11 -> V_15 == V_272 ) {
switch ( V_258 ) {
case V_262 :
V_11 -> V_225 = V_275 -> V_282 ;
return V_283 ;
case V_266 :
V_11 -> V_225 = 0 ;
return V_283 ;
default:
return V_257 ;
}
}
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_82 = F_63 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
if ( V_82 == V_272 ) {
switch ( V_258 ) {
case V_262 :
V_14 -> V_226 = V_275 -> V_282 ;
return V_283 ;
case V_266 :
V_14 -> V_226 = 0 ;
return V_283 ;
default:
return V_257 ;
}
}
}
}
return V_257 ;
}
static int F_206 ( struct V_28 * V_29 , int V_284 )
{
struct V_285 * V_162 = (struct V_285 * ) V_29 -> V_162 ;
struct V_286 * V_287 = F_207 ( V_29 ) ;
if ( V_29 -> V_244 == F_185 ( V_251 ) ) {
return ( ( F_208 ( V_287 -> V_288 ^ V_287 -> V_289 ) & 0xffff ) ^
( V_162 -> V_163 [ 5 ] ^ V_162 -> V_290 [ 5 ] ) ) % V_284 ;
}
return ( V_162 -> V_163 [ 5 ] ^ V_162 -> V_290 [ 5 ] ) % V_284 ;
}
static int F_209 ( struct V_28 * V_29 , int V_284 )
{
struct V_285 * V_162 = (struct V_285 * ) V_29 -> V_162 ;
struct V_286 * V_287 = F_207 ( V_29 ) ;
T_6 * V_291 = ( T_6 * ) ( ( T_2 * ) V_287 + V_287 -> V_292 ) ;
int V_293 = 0 ;
if ( V_29 -> V_244 == F_185 ( V_251 ) ) {
if ( ! F_210 ( V_287 ) &&
( V_287 -> V_244 == V_294 ||
V_287 -> V_244 == V_295 ) ) {
V_293 = F_211 ( ( * V_291 ^ * ( V_291 + 1 ) ) ) ;
}
return ( V_293 ^
( ( F_208 ( V_287 -> V_288 ^ V_287 -> V_289 ) ) & 0xffff ) ) % V_284 ;
}
return ( V_162 -> V_163 [ 5 ] ^ V_162 -> V_290 [ 5 ] ) % V_284 ;
}
static int F_212 ( struct V_28 * V_29 , int V_284 )
{
struct V_285 * V_162 = (struct V_285 * ) V_29 -> V_162 ;
return ( V_162 -> V_163 [ 5 ] ^ V_162 -> V_290 [ 5 ] ) % V_284 ;
}
static int F_213 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_36 ;
F_62 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_44 > 0 ) {
F_62 ( & V_11 -> V_119 ) ;
F_29 (bond, slave, i) {
if ( ( V_11 -> V_46 . V_1 == V_4 )
&& ( V_35 != V_11 -> V_78 ) ) {
F_83 ( V_35 ) ;
} else {
F_84 ( V_35 ) ;
}
}
F_65 ( & V_11 -> V_119 ) ;
}
F_65 ( & V_11 -> V_20 ) ;
F_214 ( & V_11 -> V_85 , F_66 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_215 ( V_11 , ( V_11 -> V_46 . V_1 == V_9 ) ) ) {
return - V_18 ;
}
F_214 ( & V_11 -> V_296 , V_297 ) ;
F_64 ( V_11 -> V_84 , & V_11 -> V_296 , 0 ) ;
}
if ( V_11 -> V_46 . V_115 ) {
F_214 ( & V_11 -> V_222 , F_164 ) ;
F_64 ( V_11 -> V_84 , & V_11 -> V_222 , 0 ) ;
}
if ( V_11 -> V_46 . V_156 ) {
if ( V_11 -> V_46 . V_1 == V_4 )
F_214 ( & V_11 -> V_254 ,
F_194 ) ;
else
F_214 ( & V_11 -> V_254 ,
F_187 ) ;
F_64 ( V_11 -> V_84 , & V_11 -> V_254 , 0 ) ;
if ( V_11 -> V_46 . V_253 )
V_11 -> F_110 = F_180 ;
}
if ( V_11 -> V_46 . V_1 == V_7 ) {
F_214 ( & V_11 -> V_298 , V_299 ) ;
F_64 ( V_11 -> V_84 , & V_11 -> V_298 , 0 ) ;
V_11 -> F_110 = V_300 ;
F_216 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_217 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_111 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_46 . V_115 ) {
F_218 ( & V_11 -> V_222 ) ;
}
if ( V_11 -> V_46 . V_156 ) {
F_218 ( & V_11 -> V_254 ) ;
}
switch ( V_11 -> V_46 . V_1 ) {
case V_7 :
F_218 ( & V_11 -> V_298 ) ;
break;
case V_8 :
case V_9 :
F_218 ( & V_11 -> V_296 ) ;
break;
default:
break;
}
if ( F_219 ( & V_11 -> V_85 ) )
F_218 ( & V_11 -> V_85 ) ;
if ( F_13 ( V_11 ) ) {
F_220 ( V_11 ) ;
}
V_11 -> F_110 = NULL ;
return 0 ;
}
static struct V_301 * F_221 ( struct V_30 * V_33 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_301 V_303 ;
struct V_35 * V_35 ;
int V_36 ;
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
F_222 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
const struct V_301 * V_304 =
F_223 ( V_35 -> V_15 , & V_303 ) ;
V_302 -> V_305 += V_304 -> V_305 ;
V_302 -> V_306 += V_304 -> V_306 ;
V_302 -> V_307 += V_304 -> V_307 ;
V_302 -> V_308 += V_304 -> V_308 ;
V_302 -> V_309 += V_304 -> V_309 ;
V_302 -> V_310 += V_304 -> V_310 ;
V_302 -> V_311 += V_304 -> V_311 ;
V_302 -> V_312 += V_304 -> V_312 ;
V_302 -> V_313 += V_304 -> V_313 ;
V_302 -> V_314 += V_304 -> V_314 ;
V_302 -> V_315 += V_304 -> V_315 ;
V_302 -> V_316 += V_304 -> V_316 ;
V_302 -> V_317 += V_304 -> V_317 ;
V_302 -> V_318 += V_304 -> V_318 ;
V_302 -> V_319 += V_304 -> V_319 ;
V_302 -> V_320 += V_304 -> V_320 ;
V_302 -> V_321 += V_304 -> V_321 ;
V_302 -> V_322 += V_304 -> V_322 ;
V_302 -> V_323 += V_304 -> V_323 ;
V_302 -> V_324 += V_304 -> V_324 ;
V_302 -> V_325 += V_304 -> V_325 ;
}
F_224 ( & V_11 -> V_20 ) ;
return V_302 ;
}
static int F_225 ( struct V_30 * V_33 , struct V_60 * V_61 , int V_326 )
{
struct V_30 * V_31 = NULL ;
struct V_206 V_327 ;
struct V_206 T_7 * V_328 = NULL ;
struct V_210 V_329 ;
struct V_210 T_7 * V_330 = NULL ;
struct V_62 * V_63 = NULL ;
int V_21 = 0 ;
F_3 ( L_100 , V_33 -> V_16 , V_326 ) ;
switch ( V_326 ) {
case V_71 :
V_63 = F_45 ( V_61 ) ;
if ( ! V_63 )
return - V_176 ;
V_63 -> V_331 = 0 ;
case V_74 :
V_63 = F_45 ( V_61 ) ;
if ( ! V_63 )
return - V_176 ;
if ( V_63 -> V_72 == 1 ) {
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_63 -> V_75 = 0 ;
F_62 ( & V_11 -> V_20 ) ;
F_62 ( & V_11 -> V_119 ) ;
if ( F_36 ( V_11 -> V_15 ) )
V_63 -> V_75 = V_65 ;
F_65 ( & V_11 -> V_119 ) ;
F_65 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_332 :
case V_333 :
V_328 = (struct V_206 T_7 * ) V_61 -> V_334 ;
if ( F_226 ( & V_327 , V_328 , sizeof( V_206 ) ) )
return - V_335 ;
V_21 = F_157 ( V_33 , & V_327 ) ;
if ( V_21 == 0 &&
F_227 ( V_328 , & V_327 , sizeof( V_206 ) ) )
return - V_335 ;
return V_21 ;
case V_336 :
case V_337 :
V_330 = (struct V_210 T_7 * ) V_61 -> V_334 ;
if ( F_226 ( & V_329 , V_330 , sizeof( V_210 ) ) )
return - V_335 ;
V_21 = F_158 ( V_33 , & V_329 ) ;
if ( V_21 == 0 &&
F_227 ( V_330 , & V_329 , sizeof( V_210 ) ) )
return - V_335 ;
return V_21 ;
default:
break;
}
if ( ! F_228 ( V_338 ) )
return - V_169 ;
V_31 = F_229 ( F_175 ( V_33 ) , V_61 -> V_339 ) ;
F_3 ( L_101 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_102 , V_31 -> V_16 ) ;
switch ( V_326 ) {
case V_340 :
case V_341 :
V_21 = F_121 ( V_33 , V_31 ) ;
break;
case V_342 :
case V_343 :
V_21 = F_147 ( V_33 , V_31 ) ;
break;
case V_344 :
case V_345 :
V_21 = F_101 ( V_33 , V_31 ) ;
break;
case V_346 :
case V_347 :
V_21 = F_156 ( V_33 , V_31 ) ;
break;
default:
V_21 = - V_179 ;
}
F_230 ( V_31 ) ;
}
return V_21 ;
}
static bool F_231 ( unsigned char * V_79 ,
struct V_348 * V_349 ,
int V_350 )
{
struct V_89 * V_90 ;
F_232 (ha, list)
if ( ! memcmp ( V_90 -> V_79 , V_79 , V_350 ) )
return true ;
return false ;
}
static void F_233 ( struct V_30 * V_33 , int V_351 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
if ( V_351 & V_97 )
F_47 ( V_11 ,
V_33 -> V_96 & V_97 ? 1 : - 1 ) ;
if ( V_351 & V_98 )
F_50 ( V_11 ,
V_33 -> V_96 & V_98 ? 1 : - 1 ) ;
}
static void F_234 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_89 * V_90 ;
bool V_352 ;
F_62 ( & V_11 -> V_20 ) ;
F_69 (ha, bond_dev) {
V_352 = F_231 ( V_90 -> V_79 , & V_11 -> V_353 ,
V_33 -> V_135 ) ;
if ( ! V_352 )
F_52 ( V_11 , V_90 -> V_79 ) ;
}
F_232 (ha, &bond->mc_list) {
V_352 = F_231 ( V_90 -> V_79 , & V_33 -> V_354 ,
V_33 -> V_135 ) ;
if ( ! V_352 )
F_54 ( V_11 , V_90 -> V_79 ) ;
}
F_235 ( & V_11 -> V_353 ) ;
F_236 ( & V_11 -> V_353 , & V_33 -> V_354 ,
V_33 -> V_135 , V_355 ) ;
F_65 ( & V_11 -> V_20 ) ;
}
static int F_237 ( struct V_30 * V_15 , struct V_356 * V_357 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
struct V_35 * V_35 = V_11 -> V_108 ;
if ( V_35 ) {
const struct V_37 * V_38
= V_35 -> V_15 -> V_39 ;
if ( V_38 -> V_358 )
return V_38 -> V_358 ( V_35 -> V_15 , V_357 ) ;
}
return 0 ;
}
static int F_238 ( struct V_30 * V_33 , int V_359 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_360 ;
int V_21 = 0 ;
int V_36 ;
F_3 ( L_103 , V_11 ,
( V_33 ? V_33 -> V_16 : L_10 ) , V_359 ) ;
F_29 (bond, slave, i) {
F_3 ( L_104 ,
V_35 ,
V_35 -> V_27 ,
V_35 -> V_15 -> V_39 -> V_361 ) ;
V_21 = F_130 ( V_35 -> V_15 , V_359 ) ;
if ( V_21 ) {
F_3 ( L_105 , V_21 , V_35 -> V_15 -> V_16 ) ;
goto V_362;
}
}
V_33 -> V_183 = V_359 ;
return 0 ;
V_362:
V_360 = V_35 ;
F_239 (bond, slave, i, bond->first_slave, stop_at) {
int V_363 ;
V_363 = F_130 ( V_35 -> V_15 , V_33 -> V_183 ) ;
if ( V_363 ) {
F_3 ( L_106 ,
V_363 , V_35 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_240 ( struct V_30 * V_33 , void * V_79 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_165 * V_364 = V_79 , V_365 ;
struct V_35 * V_35 , * V_360 ;
int V_21 = 0 ;
int V_36 ;
if ( V_11 -> V_46 . V_1 == V_9 )
return F_241 ( V_33 , V_79 ) ;
F_3 ( L_107 ,
V_11 , V_33 ? V_33 -> V_16 : L_10 ) ;
if ( V_11 -> V_46 . V_117 == V_178 )
return 0 ;
if ( ! F_242 ( V_364 -> V_186 ) )
return - V_366 ;
F_29 (bond, slave, i) {
const struct V_37 * V_38 = V_35 -> V_15 -> V_39 ;
F_3 ( L_108 , V_35 , V_35 -> V_15 -> V_16 ) ;
if ( V_38 -> V_177 == NULL ) {
V_21 = - V_179 ;
F_3 ( L_109 , V_35 -> V_15 -> V_16 ) ;
goto V_362;
}
V_21 = F_131 ( V_35 -> V_15 , V_79 ) ;
if ( V_21 ) {
F_3 ( L_105 , V_21 , V_35 -> V_15 -> V_16 ) ;
goto V_362;
}
}
memcpy ( V_33 -> V_136 , V_364 -> V_186 , V_33 -> V_135 ) ;
return 0 ;
V_362:
memcpy ( V_365 . V_186 , V_33 -> V_136 , V_33 -> V_135 ) ;
V_365 . V_187 = V_33 -> type ;
V_360 = V_35 ;
F_239 (bond, slave, i, bond->first_slave, stop_at) {
int V_363 ;
V_363 = F_131 ( V_35 -> V_15 , & V_365 ) ;
if ( V_363 ) {
F_3 ( L_106 ,
V_363 , V_35 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_243 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_367 ;
int V_36 , V_368 , V_21 = 1 ;
struct V_286 * V_287 = F_207 ( V_29 ) ;
if ( ( V_287 -> V_244 == V_369 ) &&
( V_29 -> V_244 == F_185 ( V_251 ) ) ) {
F_62 ( & V_11 -> V_119 ) ;
V_35 = V_11 -> V_78 ;
F_65 ( & V_11 -> V_119 ) ;
if ( ! V_35 )
goto V_23;
} else {
V_368 = V_11 -> V_370 ++ % V_11 -> V_44 ;
F_29 (bond, slave, i) {
V_368 -- ;
if ( V_368 < 0 )
break;
}
}
V_367 = V_35 ;
F_74 (bond, slave, i, start_at) {
if ( F_75 ( V_35 -> V_15 ) &&
( V_35 -> V_47 == V_48 ) &&
F_144 ( V_35 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_116 ( V_29 ) ;
}
return V_371 ;
}
static int F_244 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
int V_21 = 1 ;
F_62 ( & V_11 -> V_119 ) ;
if ( V_11 -> V_78 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_78 -> V_15 ) ;
if ( V_21 )
F_116 ( V_29 ) ;
F_65 ( & V_11 -> V_119 ) ;
return V_371 ;
}
static int F_245 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_367 ;
int V_368 ;
int V_36 ;
int V_21 = 1 ;
V_368 = V_11 -> V_372 ( V_29 , V_11 -> V_44 ) ;
F_29 (bond, slave, i) {
V_368 -- ;
if ( V_368 < 0 )
break;
}
V_367 = V_35 ;
F_74 (bond, slave, i, start_at) {
if ( F_75 ( V_35 -> V_15 ) &&
( V_35 -> V_47 == V_48 ) &&
F_144 ( V_35 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_116 ( V_29 ) ;
}
return V_371 ;
}
static int F_246 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_367 ;
struct V_30 * V_373 = NULL ;
int V_36 ;
int V_21 = 1 ;
F_62 ( & V_11 -> V_119 ) ;
V_367 = V_11 -> V_78 ;
F_65 ( & V_11 -> V_119 ) ;
if ( ! V_367 )
goto V_23;
F_74 (bond, slave, i, start_at) {
if ( F_75 ( V_35 -> V_15 ) &&
( V_35 -> V_47 == V_48 ) &&
F_144 ( V_35 ) ) {
if ( V_373 ) {
struct V_28 * V_374 = F_114 ( V_29 , V_154 ) ;
if ( ! V_374 ) {
F_30 ( L_110 ,
V_33 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_374 , V_373 ) ;
if ( V_21 ) {
F_116 ( V_374 ) ;
continue;
}
}
V_373 = V_35 -> V_15 ;
}
}
if ( V_373 )
V_21 = F_20 ( V_11 , V_29 , V_373 ) ;
V_23:
if ( V_21 )
F_116 ( V_29 ) ;
return V_371 ;
}
static void F_247 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_46 . V_375 ) {
case V_376 :
V_11 -> V_372 = F_206 ;
break;
case V_377 :
V_11 -> V_372 = F_209 ;
break;
case V_378 :
default:
V_11 -> V_372 = F_212 ;
break;
}
}
static inline int F_248 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_36 , V_21 = 1 ;
struct V_35 * V_35 = NULL ;
struct V_35 * V_379 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_29 (bond, check_slave, i) {
if ( V_379 -> V_181 == V_29 -> V_32 ) {
V_35 = V_379 ;
break;
}
}
if ( V_35 && V_35 -> V_181 && F_75 ( V_35 -> V_15 ) &&
( V_35 -> V_47 == V_48 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
}
return V_21 ;
}
static T_8 F_249 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_8 V_380 = F_250 ( V_29 ) ? F_251 ( V_29 ) : 0 ;
F_21 ( V_29 ) = V_29 -> V_32 ;
if ( F_22 ( V_380 >= V_15 -> V_381 ) ) {
do {
V_380 -= V_15 -> V_381 ;
} while ( V_380 >= V_15 -> V_381 );
}
return V_380 ;
}
static T_9 F_252 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
if ( F_253 ( V_11 -> V_46 . V_1 ) ) {
if ( ! F_248 ( V_11 , V_29 ) )
return V_371 ;
}
switch ( V_11 -> V_46 . V_1 ) {
case V_3 :
return F_243 ( V_29 , V_15 ) ;
case V_4 :
return F_244 ( V_29 , V_15 ) ;
case V_5 :
return F_245 ( V_29 , V_15 ) ;
case V_6 :
return F_246 ( V_29 , V_15 ) ;
case V_7 :
return F_254 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_255 ( V_29 , V_15 ) ;
default:
F_30 ( L_111 ,
V_15 -> V_16 , V_11 -> V_46 . V_1 ) ;
F_256 ( 1 ) ;
F_116 ( V_29 ) ;
return V_371 ;
}
}
static T_9 F_257 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_9 V_205 = V_371 ;
if ( F_258 ( V_15 ) )
return V_382 ;
F_62 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_44 )
V_205 = F_252 ( V_29 , V_15 ) ;
else
F_116 ( V_29 ) ;
F_65 ( & V_11 -> V_20 ) ;
return V_205 ;
}
void F_259 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_33 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_247 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_247 ( V_11 ) ;
break;
case V_9 :
case V_8 :
break;
default:
F_30 ( L_111 ,
V_33 -> V_16 , V_1 ) ;
break;
}
}
static void F_260 ( struct V_30 * V_33 ,
struct V_383 * V_384 )
{
strncpy ( V_384 -> V_385 , V_386 , 32 ) ;
strncpy ( V_384 -> V_387 , V_388 , 32 ) ;
snprintf ( V_384 -> V_389 , 32 , L_112 , V_390 ) ;
}
static void F_261 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
if ( V_11 -> V_84 )
F_262 ( V_11 -> V_84 ) ;
F_263 ( V_33 ) ;
}
static void F_264 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
F_265 ( & V_11 -> V_20 ) ;
F_265 ( & V_11 -> V_119 ) ;
V_11 -> V_46 = V_391 ;
V_11 -> V_15 = V_33 ;
F_5 ( & V_11 -> V_19 ) ;
F_127 ( V_33 ) ;
V_33 -> V_39 = & V_392 ;
V_33 -> V_66 = & V_393 ;
F_259 ( V_11 , V_11 -> V_46 . V_1 ) ;
V_33 -> V_394 = F_261 ;
V_33 -> V_395 = 0 ;
V_33 -> V_96 |= V_273 | V_396 ;
V_33 -> V_129 |= V_191 ;
V_33 -> V_129 &= ~ ( V_397 | V_174 ) ;
V_33 -> V_40 |= V_138 ;
V_33 -> V_40 |= V_398 ;
V_33 -> V_399 = V_142 |
V_400 |
V_401 |
V_41 ;
V_33 -> V_399 &= ~ ( V_402 & ~ V_403 ) ;
V_33 -> V_40 |= V_33 -> V_399 ;
}
static void F_266 ( struct V_10 * V_11 )
{
if ( V_11 -> V_46 . V_115 && F_219 ( & V_11 -> V_222 ) )
F_218 ( & V_11 -> V_222 ) ;
if ( V_11 -> V_46 . V_156 && F_219 ( & V_11 -> V_254 ) )
F_218 ( & V_11 -> V_254 ) ;
if ( V_11 -> V_46 . V_1 == V_9 &&
F_219 ( & V_11 -> V_296 ) )
F_218 ( & V_11 -> V_296 ) ;
if ( V_11 -> V_46 . V_1 == V_7 &&
F_219 ( & V_11 -> V_298 ) )
F_218 ( & V_11 -> V_298 ) ;
if ( F_219 ( & V_11 -> V_85 ) )
F_218 ( & V_11 -> V_85 ) ;
}
static void F_267 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_13 * V_14 , * V_404 ;
F_98 ( V_33 ) ;
F_155 ( V_33 ) ;
F_12 ( & V_11 -> V_405 ) ;
F_266 ( V_11 ) ;
F_196 ( V_11 ) ;
F_268 ( V_11 ) ;
F_235 ( & V_11 -> V_353 ) ;
F_269 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_270 ( const char * V_406 , const struct V_407 * V_408 )
{
int V_409 = - 1 , V_36 , V_124 ;
char * V_410 , V_411 [ V_412 + 1 ] = { 0 , } ;
for ( V_410 = ( char * ) V_406 ; * V_410 ; V_410 ++ )
if ( ! ( isdigit ( * V_410 ) || isspace ( * V_410 ) ) )
break;
if ( * V_410 )
V_124 = sscanf ( V_406 , L_113 , V_411 ) ;
else
V_124 = sscanf ( V_406 , L_112 , & V_409 ) ;
if ( ! V_124 )
return - 1 ;
for ( V_36 = 0 ; V_408 [ V_36 ] . V_413 ; V_36 ++ ) {
if ( V_409 == V_408 [ V_36 ] . V_1 )
return V_408 [ V_36 ] . V_1 ;
if ( strcmp ( V_411 , V_408 [ V_36 ] . V_413 ) == 0 )
return V_408 [ V_36 ] . V_1 ;
}
return - 1 ;
}
static int F_271 ( struct V_414 * V_46 )
{
int V_415 , V_416 , V_417 ;
if ( V_1 ) {
V_208 = F_270 ( V_1 , V_418 ) ;
if ( V_208 == - 1 ) {
F_30 ( L_114 ,
V_1 == NULL ? L_17 : V_1 ) ;
return - V_176 ;
}
}
if ( V_372 ) {
if ( ( V_208 != V_5 ) &&
( V_208 != V_7 ) ) {
F_79 ( L_115 ,
F_1 ( V_208 ) ) ;
} else {
V_419 = F_270 ( V_372 ,
V_420 ) ;
if ( V_419 == - 1 ) {
F_30 ( L_116 ,
V_372 == NULL ? L_17 :
V_372 ) ;
return - V_176 ;
}
}
}
if ( V_421 ) {
if ( V_208 != V_7 ) {
F_79 ( L_117 ,
F_1 ( V_208 ) ) ;
} else {
V_422 = F_270 ( V_421 , V_423 ) ;
if ( V_422 == - 1 ) {
F_30 ( L_118 ,
V_421 == NULL ? L_17 : V_421 ) ;
return - V_176 ;
}
}
}
if ( V_424 ) {
V_46 -> V_424 = F_270 ( V_424 , V_425 ) ;
if ( V_46 -> V_424 == - 1 ) {
F_30 ( L_119 ,
V_424 == NULL ? L_17 : V_424 ) ;
return - V_176 ;
}
if ( V_208 != V_7 ) {
F_122 ( L_120 ) ;
}
} else {
V_46 -> V_424 = V_426 ;
}
if ( V_427 < 0 ) {
F_122 ( L_121 ,
V_427 , 0 , V_428 , V_429 ) ;
V_427 = V_429 ;
}
if ( V_115 < 0 ) {
F_122 ( L_122 ,
V_115 , V_428 , V_430 ) ;
V_115 = V_430 ;
}
if ( V_107 < 0 ) {
F_122 ( L_123 ,
V_107 , V_428 ) ;
V_107 = 0 ;
}
if ( V_219 < 0 ) {
F_122 ( L_124 ,
V_219 , V_428 ) ;
V_219 = 0 ;
}
if ( ( V_64 != 0 ) && ( V_64 != 1 ) ) {
F_122 ( L_125 ,
V_64 ) ;
V_64 = 1 ;
}
if ( V_118 < 0 || V_118 > 255 ) {
F_122 ( L_126 ,
V_118 ) ;
V_118 = 1 ;
}
if ( V_208 == V_7 ) {
if ( ! V_115 ) {
F_122 ( L_127 ) ;
F_122 ( L_128 ) ;
V_115 = 100 ;
}
}
if ( V_431 < 1 || V_431 > 255 ) {
F_122 ( L_129
L_130 ,
V_431 , V_432 ) ;
V_431 = V_432 ;
}
if ( ( V_433 != 0 ) && ( V_433 != 1 ) ) {
F_122 ( L_131
L_132
L_133 , V_433 ) ;
V_433 = 0 ;
}
if ( V_122 < 0 || V_122 > 255 ) {
F_122 ( L_134
L_135 ,
V_122 , V_434 ) ;
V_122 = V_434 ;
}
if ( ( V_208 == V_8 ) ||
( V_208 == V_9 ) ) {
if ( ! V_115 ) {
F_122 ( L_136 ) ;
F_122 ( L_128 ) ;
V_115 = 100 ;
}
}
if ( V_208 == V_9 ) {
F_272 ( L_137 ,
V_107 ) ;
}
if ( ! V_115 ) {
if ( V_107 || V_219 ) {
F_122 ( L_138 ,
V_107 , V_219 ) ;
}
} else {
if ( V_156 ) {
F_122 ( L_139 ,
V_115 , V_156 ) ;
V_156 = 0 ;
}
if ( ( V_107 % V_115 ) != 0 ) {
F_122 ( L_140 ,
V_107 , V_115 ,
( V_107 / V_115 ) * V_115 ) ;
}
V_107 /= V_115 ;
if ( ( V_219 % V_115 ) != 0 ) {
F_122 ( L_141 ,
V_219 , V_115 ,
( V_219 / V_115 ) * V_115 ) ;
}
V_219 /= V_115 ;
}
if ( V_156 < 0 ) {
F_122 ( L_142 ,
V_156 , V_428 , V_435 ) ;
V_156 = V_435 ;
}
for ( V_436 = 0 ;
( V_436 < V_235 ) && V_437 [ V_436 ] ;
V_436 ++ ) {
if ( ! isdigit ( V_437 [ V_436 ] [ 0 ] ) ) {
F_122 ( L_143 ,
V_437 [ V_436 ] ) ;
V_156 = 0 ;
} else {
T_5 V_224 = F_273 ( V_437 [ V_436 ] ) ;
V_438 [ V_436 ] = V_224 ;
}
}
if ( V_156 && ! V_436 ) {
F_122 ( L_144 ,
V_156 ) ;
V_156 = 0 ;
}
if ( V_253 ) {
if ( V_208 != V_4 ) {
F_30 ( L_145 ) ;
return - V_176 ;
}
if ( ! V_156 ) {
F_30 ( L_146 ) ;
return - V_176 ;
}
V_415 = F_270 ( V_253 ,
V_439 ) ;
if ( V_415 == - 1 ) {
F_30 ( L_147 ,
V_253 == NULL ? L_17 : V_253 ) ;
return - V_176 ;
}
} else
V_415 = 0 ;
if ( V_115 ) {
F_79 ( L_148 , V_115 ) ;
} else if ( V_156 ) {
int V_36 ;
F_79 ( L_149 ,
V_156 ,
V_439 [ V_415 ] . V_413 ,
V_436 ) ;
for ( V_36 = 0 ; V_36 < V_436 ; V_36 ++ )
F_79 ( L_150 , V_437 [ V_36 ] ) ;
F_79 ( L_151 ) ;
} else if ( V_427 ) {
F_3 ( L_152 ) ;
}
if ( V_196 && ! F_48 ( V_208 ) ) {
F_122 ( L_153 ,
V_196 , F_1 ( V_208 ) ) ;
V_196 = NULL ;
}
if ( V_196 && V_102 ) {
V_417 = F_270 ( V_102 ,
V_440 ) ;
if ( V_417 == - 1 ) {
F_30 ( L_154 ,
V_102 ==
NULL ? L_17 : V_102 ) ;
return - V_176 ;
}
} else {
V_417 = V_441 ;
}
if ( V_117 ) {
V_416 = F_270 ( V_117 ,
V_442 ) ;
if ( V_416 == - 1 ) {
F_30 ( L_155 ,
V_253 == NULL ? L_17 : V_253 ) ;
return - V_176 ;
}
if ( V_208 != V_4 )
F_122 ( L_156 ) ;
} else {
V_416 = V_443 ;
}
V_46 -> V_1 = V_208 ;
V_46 -> V_375 = V_419 ;
V_46 -> V_115 = V_115 ;
V_46 -> V_118 = V_118 ;
V_46 -> V_156 = V_156 ;
V_46 -> V_253 = V_415 ;
V_46 -> V_107 = V_107 ;
V_46 -> V_219 = V_219 ;
V_46 -> V_64 = V_64 ;
V_46 -> V_422 = V_422 ;
V_46 -> V_196 [ 0 ] = 0 ;
V_46 -> V_102 = V_417 ;
V_46 -> V_117 = V_416 ;
V_46 -> V_431 = V_431 ;
V_46 -> V_433 = V_433 ;
V_46 -> V_122 = V_122 ;
V_46 -> V_444 = V_444 ;
if ( V_196 ) {
strncpy ( V_46 -> V_196 , V_196 , V_70 ) ;
V_46 -> V_196 [ V_70 - 1 ] = 0 ;
}
memcpy ( V_46 -> V_232 , V_438 , sizeof( V_438 ) ) ;
return 0 ;
}
static void F_274 ( struct V_30 * V_15 ,
struct V_445 * V_380 ,
void * V_446 )
{
F_275 ( & V_380 -> V_447 ,
& V_448 ) ;
}
static void F_276 ( struct V_30 * V_15 )
{
F_275 ( & V_15 -> V_449 ,
& V_450 ) ;
F_277 ( V_15 , F_274 , NULL ) ;
}
static int F_278 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_277 * V_278 = F_205 ( F_175 ( V_33 ) , V_279 ) ;
struct V_451 * V_452 = & ( F_279 ( V_11 ) ) ;
F_3 ( L_157 , V_33 -> V_16 ) ;
F_280 ( & ( V_452 -> V_453 ) ) ;
F_280 ( & ( V_452 -> V_454 ) ) ;
V_11 -> V_84 = F_281 ( V_33 -> V_16 ) ;
if ( ! V_11 -> V_84 )
return - V_18 ;
F_276 ( V_33 ) ;
F_197 ( V_11 ) ;
F_7 ( & V_11 -> V_405 , & V_278 -> V_455 ) ;
F_282 ( V_11 ) ;
F_283 ( V_11 ) ;
F_284 ( & V_11 -> V_353 ) ;
return 0 ;
}
static int F_285 ( struct V_456 * V_457 [] , struct V_456 * V_162 [] )
{
if ( V_457 [ V_458 ] ) {
if ( F_286 ( V_457 [ V_458 ] ) != V_92 )
return - V_176 ;
if ( ! F_242 ( F_287 ( V_457 [ V_458 ] ) ) )
return - V_366 ;
}
return 0 ;
}
static int F_288 ( struct V_459 * V_459 , struct V_456 * V_457 [] ,
unsigned int * V_460 ,
unsigned int * V_461 )
{
* V_460 = V_431 ;
return 0 ;
}
int F_289 ( struct V_459 * V_459 , const char * V_16 )
{
struct V_30 * V_33 ;
int V_21 ;
F_290 () ;
V_33 = F_291 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_158 ,
F_264 , V_431 ) ;
if ( ! V_33 ) {
F_30 ( L_159 , V_16 ) ;
F_167 () ;
return - V_18 ;
}
F_292 ( V_33 , V_459 ) ;
V_33 -> V_462 = & V_463 ;
V_21 = F_293 ( V_33 ) ;
F_38 ( V_33 ) ;
F_167 () ;
if ( V_21 < 0 )
F_261 ( V_33 ) ;
return V_21 ;
}
static int T_10 F_294 ( struct V_459 * V_459 )
{
struct V_277 * V_278 = F_205 ( V_459 , V_279 ) ;
V_278 -> V_459 = V_459 ;
F_5 ( & V_278 -> V_455 ) ;
F_295 ( V_278 ) ;
F_296 ( V_278 ) ;
return 0 ;
}
static void T_11 F_297 ( struct V_459 * V_459 )
{
struct V_277 * V_278 = F_205 ( V_459 , V_279 ) ;
F_298 ( V_278 ) ;
F_299 ( V_278 ) ;
}
static int T_12 F_300 ( void )
{
int V_36 ;
int V_21 ;
F_79 ( L_160 , V_464 ) ;
V_21 = F_271 ( & V_391 ) ;
if ( V_21 )
goto V_23;
V_21 = F_301 ( & V_465 ) ;
if ( V_21 )
goto V_23;
V_21 = F_302 ( & V_463 ) ;
if ( V_21 )
goto V_466;
F_303 () ;
for ( V_36 = 0 ; V_36 < V_427 ; V_36 ++ ) {
V_21 = F_289 ( & V_467 , NULL ) ;
if ( V_21 )
goto V_77;
}
F_304 ( & V_468 ) ;
F_305 ( & V_469 ) ;
V_23:
return V_21 ;
V_77:
F_306 ( & V_463 ) ;
V_466:
F_307 ( & V_465 ) ;
goto V_23;
}
static void T_13 F_308 ( void )
{
F_309 ( & V_468 ) ;
F_310 ( & V_469 ) ;
F_311 () ;
F_306 ( & V_463 ) ;
F_307 ( & V_465 ) ;
#ifdef F_141
F_312 ( F_313 ( & V_470 ) ) ;
#endif
}
