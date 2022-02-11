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
V_29 -> V_32 = 1 ;
V_29 -> V_33 = F_21 ( V_29 ) ;
if ( F_22 ( F_23 ( V_31 ) ) )
F_24 ( F_25 ( V_11 , V_31 ) , V_29 ) ;
else
F_26 ( V_29 ) ;
return 0 ;
}
static void F_27 ( struct V_30 * V_34 , T_1 V_35 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 ;
int V_37 , V_21 ;
F_29 (bond, slave, i) {
struct V_30 * V_31 = V_36 -> V_15 ;
const struct V_38 * V_39 = V_31 -> V_40 ;
if ( ( V_31 -> V_41 & V_42 ) &&
V_39 -> V_43 ) {
V_39 -> V_43 ( V_31 , V_35 ) ;
}
}
V_21 = F_2 ( V_11 , V_35 ) ;
if ( V_21 ) {
F_30 ( L_14 ,
V_34 -> V_16 , V_35 ) ;
}
}
static void F_31 ( struct V_30 * V_34 , T_1 V_35 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 ;
int V_37 , V_21 ;
F_29 (bond, slave, i) {
struct V_30 * V_31 = V_36 -> V_15 ;
const struct V_38 * V_39 = V_31 -> V_40 ;
if ( ( V_31 -> V_41 & V_42 ) &&
V_39 -> V_44 ) {
V_39 -> V_44 ( V_31 , V_35 ) ;
}
}
V_21 = F_9 ( V_11 , V_35 ) ;
if ( V_21 ) {
F_30 ( L_15 ,
V_34 -> V_16 , V_35 ) ;
}
}
static void F_32 ( struct V_10 * V_11 , struct V_30 * V_31 )
{
struct V_13 * V_14 ;
const struct V_38 * V_39 = V_31 -> V_40 ;
if ( ! ( V_31 -> V_41 & V_42 ) ||
! ( V_39 -> V_43 ) )
return;
F_11 (vlan, &bond->vlan_list, vlan_list)
V_39 -> V_43 ( V_31 , V_14 -> V_12 ) ;
}
static void F_33 ( struct V_10 * V_11 ,
struct V_30 * V_31 )
{
const struct V_38 * V_39 = V_31 -> V_40 ;
struct V_13 * V_14 ;
if ( ! ( V_31 -> V_41 & V_42 ) ||
! ( V_39 -> V_44 ) )
return;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( ! V_14 -> V_12 )
continue;
V_39 -> V_44 ( V_31 , V_14 -> V_12 ) ;
}
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_37 ;
if ( V_11 -> V_45 == 0 )
goto V_46;
if ( V_11 -> V_47 . V_1 == V_7 )
return F_35 ( V_11 ) ;
F_29 (bond, slave, i) {
if ( V_36 -> V_48 == V_49 ) {
if ( ! F_36 ( V_11 -> V_15 ) ) {
F_37 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
}
V_46:
if ( F_36 ( V_11 -> V_15 ) ) {
F_38 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_36 * V_36 )
{
struct V_30 * V_31 = V_36 -> V_15 ;
struct V_50 V_51 = { . V_52 = V_53 } ;
T_2 V_54 ;
int V_21 ;
V_36 -> V_55 = V_56 ;
V_36 -> V_57 = V_58 ;
if ( ! V_31 -> V_59 || ! V_31 -> V_59 -> V_60 )
return - 1 ;
V_21 = V_31 -> V_59 -> V_60 ( V_31 , & V_51 ) ;
if ( V_21 < 0 )
return - 1 ;
V_54 = F_40 ( & V_51 ) ;
if ( V_54 == 0 || V_54 == ( ( V_61 ) - 1 ) )
return - 1 ;
switch ( V_51 . V_57 ) {
case V_58 :
case V_62 :
break;
default:
return - 1 ;
}
V_36 -> V_55 = V_54 ;
V_36 -> V_57 = V_51 . V_57 ;
return 0 ;
}
static int F_41 ( struct V_10 * V_11 ,
struct V_30 * V_31 , int V_63 )
{
const struct V_38 * V_39 = V_31 -> V_40 ;
int (* F_42)( struct V_30 * , struct V_64 * , int );
struct V_64 V_65 ;
struct V_66 * V_67 ;
if ( ! V_63 && ! F_43 ( V_31 ) )
return 0 ;
if ( V_11 -> V_47 . V_68 )
return F_36 ( V_31 ) ? V_69 : 0 ;
if ( V_31 -> V_59 ) {
if ( V_31 -> V_59 -> V_70 ) {
T_2 V_48 ;
V_48 = V_31 -> V_59 -> V_70 ( V_31 ) ;
return V_48 ? V_69 : 0 ;
}
}
F_42 = V_39 -> V_71 ;
if ( F_42 ) {
strncpy ( V_65 . V_72 , V_31 -> V_16 , V_73 ) ;
V_67 = F_44 ( & V_65 ) ;
if ( F_45 ( V_31 , & V_65 , V_74 ) == 0 ) {
V_67 -> V_75 = V_76 ;
if ( F_45 ( V_31 , & V_65 , V_77 ) == 0 )
return V_67 -> V_78 & V_69 ;
}
}
return V_63 ? - 1 : V_69 ;
}
static int F_46 ( struct V_10 * V_11 , int V_79 )
{
int V_80 = 0 ;
if ( F_47 ( V_11 -> V_47 . V_1 ) ) {
if ( V_11 -> V_81 ) {
V_80 = F_48 ( V_11 -> V_81 -> V_15 ,
V_79 ) ;
}
} else {
struct V_36 * V_36 ;
int V_37 ;
F_29 (bond, slave, i) {
V_80 = F_48 ( V_36 -> V_15 , V_79 ) ;
if ( V_80 )
return V_80 ;
}
}
return V_80 ;
}
static int F_49 ( struct V_10 * V_11 , int V_79 )
{
int V_80 = 0 ;
if ( F_47 ( V_11 -> V_47 . V_1 ) ) {
if ( V_11 -> V_81 ) {
V_80 = F_50 ( V_11 -> V_81 -> V_15 ,
V_79 ) ;
}
} else {
struct V_36 * V_36 ;
int V_37 ;
F_29 (bond, slave, i) {
V_80 = F_50 ( V_36 -> V_15 , V_79 ) ;
if ( V_80 )
return V_80 ;
}
}
return V_80 ;
}
static void F_51 ( struct V_10 * V_11 , void * V_82 )
{
if ( F_47 ( V_11 -> V_47 . V_1 ) ) {
if ( V_11 -> V_81 )
F_52 ( V_11 -> V_81 -> V_15 , V_82 ) ;
} else {
struct V_36 * V_36 ;
int V_37 ;
F_29 (bond, slave, i)
F_52 ( V_36 -> V_15 , V_82 ) ;
}
}
static void F_53 ( struct V_10 * V_11 , void * V_82 )
{
if ( F_47 ( V_11 -> V_47 . V_1 ) ) {
if ( V_11 -> V_81 )
F_54 ( V_11 -> V_81 -> V_15 , V_82 ) ;
} else {
struct V_36 * V_36 ;
int V_37 ;
F_29 (bond, slave, i) {
F_54 ( V_36 -> V_15 , V_82 ) ;
}
}
}
static void F_55 ( struct V_30 * V_15 )
{
struct V_83 * V_84 ;
F_56 () ;
V_84 = F_57 ( V_15 ) ;
if ( V_84 )
F_58 ( V_84 ) ;
F_59 () ;
}
static void F_60 ( struct V_10 * V_11 )
{
struct V_30 * V_85 ;
struct V_13 * V_14 ;
F_61 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_86 )
goto V_23;
F_55 ( V_11 -> V_15 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_56 () ;
V_85 = F_62 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_59 () ;
if ( V_85 )
F_55 ( V_85 ) ;
}
if ( ( -- V_11 -> V_87 > 0 ) && ! V_11 -> V_86 )
F_63 ( V_11 -> V_88 , & V_11 -> V_89 , V_90 / 5 ) ;
V_23:
F_64 ( & V_11 -> V_20 ) ;
}
static void F_65 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_66 ( V_92 , struct V_10 ,
V_89 . V_92 ) ;
F_60 ( V_11 ) ;
}
static void F_67 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_93 * V_94 ;
F_68 (ha, bond_dev)
F_54 ( V_31 , V_94 -> V_82 ) ;
if ( V_11 -> V_47 . V_1 == V_7 ) {
T_3 V_95 [ V_96 ] = V_97 ;
F_54 ( V_31 , V_95 ) ;
}
}
static void F_69 ( struct V_10 * V_11 , struct V_36 * V_98 ,
struct V_36 * V_99 )
{
struct V_93 * V_94 ;
if ( ! F_47 ( V_11 -> V_47 . V_1 ) )
return;
if ( V_99 ) {
if ( V_11 -> V_15 -> V_100 & V_101 )
F_48 ( V_99 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_100 & V_102 )
F_50 ( V_99 -> V_15 , - 1 ) ;
F_68 (ha, bond->dev)
F_54 ( V_99 -> V_15 , V_94 -> V_82 ) ;
}
if ( V_98 ) {
if ( V_11 -> V_15 -> V_100 & V_101 )
F_48 ( V_98 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_100 & V_102 )
F_50 ( V_98 -> V_15 , 1 ) ;
F_68 (ha, bond->dev)
F_52 ( V_98 -> V_15 , V_94 -> V_82 ) ;
}
}
static void F_70 ( struct V_10 * V_11 ,
struct V_36 * V_98 ,
struct V_36 * V_99 )
__releases( &bond->curr_slave_lock
static bool F_71 ( struct V_10 * V_11 )
{
struct V_36 * V_103 = V_11 -> V_104 ;
struct V_36 * V_24 = V_11 -> V_81 ;
if ( ! V_103 || ! V_24 || V_24 -> V_48 != V_49 )
return true ;
if ( V_11 -> V_105 ) {
V_11 -> V_105 = false ;
return true ;
}
if ( V_11 -> V_47 . V_106 == V_107 &&
( V_103 -> V_55 < V_24 -> V_55 ||
( V_103 -> V_55 == V_24 -> V_55 && V_103 -> V_57 <= V_24 -> V_57 ) ) )
return false ;
if ( V_11 -> V_47 . V_106 == V_108 )
return false ;
return true ;
}
static struct V_36 * F_72 ( struct V_10 * V_11 )
{
struct V_36 * V_98 , * V_99 ;
struct V_36 * V_109 = NULL ;
int V_110 = V_11 -> V_47 . V_111 ;
int V_37 ;
V_98 = V_11 -> V_81 ;
if ( ! V_98 ) {
if ( V_11 -> V_45 > 0 )
V_98 = V_11 -> V_112 ;
else
return NULL ;
}
if ( ( V_11 -> V_104 ) &&
V_11 -> V_104 -> V_48 == V_49 &&
F_71 ( V_11 ) ) {
V_98 = V_11 -> V_104 ;
}
V_99 = V_98 ;
F_73 (bond, new_active, i, old_active) {
if ( V_98 -> V_48 == V_49 ) {
return V_98 ;
} else if ( V_98 -> V_48 == V_113 &&
F_74 ( V_98 -> V_15 ) ) {
if ( V_98 -> V_114 < V_110 ) {
V_110 = V_98 -> V_114 ;
V_109 = V_98 ;
}
}
}
return V_109 ;
}
static bool F_75 ( struct V_10 * V_11 )
{
struct V_36 * V_36 = V_11 -> V_81 ;
F_3 ( L_16 ,
V_11 -> V_15 -> V_16 , V_36 ? V_36 -> V_15 -> V_16 : L_17 ) ;
if ( ! V_36 || ! V_11 -> V_115 ||
F_76 ( V_116 , & V_36 -> V_15 -> V_117 ) )
return false ;
V_11 -> V_115 -- ;
return true ;
}
void F_77 ( struct V_10 * V_11 , struct V_36 * V_98 )
{
struct V_36 * V_99 = V_11 -> V_81 ;
if ( V_99 == V_98 )
return;
if ( V_98 ) {
V_98 -> V_118 = V_118 ;
if ( V_98 -> V_48 == V_113 ) {
if ( F_47 ( V_11 -> V_47 . V_1 ) ) {
F_78 ( L_18 ,
V_11 -> V_15 -> V_16 , V_98 -> V_15 -> V_16 ,
( V_11 -> V_47 . V_111 - V_98 -> V_114 ) * V_11 -> V_47 . V_119 ) ;
}
V_98 -> V_114 = 0 ;
V_98 -> V_48 = V_49 ;
if ( V_11 -> V_47 . V_1 == V_7 )
F_79 ( V_98 , V_49 ) ;
if ( F_13 ( V_11 ) )
F_80 ( V_11 , V_98 , V_49 ) ;
} else {
if ( F_47 ( V_11 -> V_47 . V_1 ) ) {
F_78 ( L_19 ,
V_11 -> V_15 -> V_16 , V_98 -> V_15 -> V_16 ) ;
}
}
}
if ( F_47 ( V_11 -> V_47 . V_1 ) )
F_69 ( V_11 , V_98 , V_99 ) ;
if ( F_13 ( V_11 ) ) {
F_81 ( V_11 , V_98 ) ;
if ( V_99 )
F_82 ( V_99 ) ;
if ( V_98 )
F_83 ( V_98 ) ;
} else {
V_11 -> V_81 = V_98 ;
}
if ( V_11 -> V_47 . V_1 == V_4 ) {
if ( V_99 )
F_82 ( V_99 ) ;
if ( V_98 ) {
bool V_120 = false ;
F_83 ( V_98 ) ;
if ( V_11 -> V_47 . V_121 )
F_70 ( V_11 , V_98 ,
V_99 ) ;
if ( F_43 ( V_11 -> V_15 ) ) {
V_11 -> V_115 =
V_11 -> V_47 . V_122 ;
V_120 =
F_75 ( V_11 ) ;
}
F_8 ( & V_11 -> V_123 ) ;
F_64 ( & V_11 -> V_20 ) ;
F_84 ( V_11 -> V_15 , V_124 ) ;
if ( V_120 )
F_84 ( V_11 -> V_15 ,
V_125 ) ;
F_61 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_123 ) ;
}
}
if ( F_43 ( V_11 -> V_15 ) && ( V_11 -> V_47 . V_126 > 0 ) &&
( ( F_47 ( V_11 -> V_47 . V_1 ) && V_98 ) ||
V_11 -> V_47 . V_1 == V_3 ) ) {
V_11 -> V_87 = V_11 -> V_47 . V_126 ;
F_63 ( V_11 -> V_88 , & V_11 -> V_89 , 0 ) ;
}
}
void F_85 ( struct V_10 * V_11 )
{
struct V_36 * V_127 ;
int V_128 ;
V_127 = F_72 ( V_11 ) ;
if ( V_127 != V_11 -> V_81 ) {
F_77 ( V_11 , V_127 ) ;
V_128 = F_34 ( V_11 ) ;
if ( ! V_128 )
return;
if ( F_36 ( V_11 -> V_15 ) ) {
F_78 ( L_20 ,
V_11 -> V_15 -> V_16 ) ;
} else {
F_78 ( L_21 ,
V_11 -> V_15 -> V_16 ) ;
}
}
}
static void F_86 ( struct V_10 * V_11 , struct V_36 * V_129 )
{
if ( V_11 -> V_112 == NULL ) {
V_129 -> V_25 = V_129 ;
V_129 -> V_27 = V_129 ;
V_11 -> V_112 = V_129 ;
} else {
V_129 -> V_25 = V_11 -> V_112 ;
V_129 -> V_27 = V_11 -> V_112 -> V_27 ;
V_129 -> V_25 -> V_27 = V_129 ;
V_129 -> V_27 -> V_25 = V_129 ;
}
V_11 -> V_45 ++ ;
}
static void F_87 ( struct V_10 * V_11 , struct V_36 * V_36 )
{
if ( V_36 -> V_25 )
V_36 -> V_25 -> V_27 = V_36 -> V_27 ;
if ( V_36 -> V_27 )
V_36 -> V_27 -> V_25 = V_36 -> V_25 ;
if ( V_11 -> V_112 == V_36 ) {
if ( V_11 -> V_45 > 1 ) {
V_11 -> V_112 = V_36 -> V_25 ;
} else {
V_11 -> V_112 = NULL ;
}
}
V_36 -> V_25 = NULL ;
V_36 -> V_27 = NULL ;
V_11 -> V_45 -- ;
}
static inline int F_88 ( struct V_36 * V_36 )
{
struct V_130 * V_131 ;
int V_80 = 0 ;
V_131 = F_4 ( sizeof( * V_131 ) , V_17 ) ;
V_80 = - V_18 ;
if ( ! V_131 )
goto V_23;
V_131 -> V_15 = V_36 -> V_15 ;
F_89 ( V_131 -> V_132 , V_36 -> V_15 -> V_16 , V_73 ) ;
V_80 = F_90 ( V_131 ) ;
if ( V_80 ) {
F_15 ( V_131 ) ;
goto V_23;
}
V_36 -> V_131 = V_131 ;
V_23:
return V_80 ;
}
static inline void F_91 ( struct V_36 * V_36 )
{
struct V_130 * V_131 = V_36 -> V_131 ;
if ( ! V_131 )
return;
V_36 -> V_131 = NULL ;
F_92 () ;
F_93 ( V_131 ) ;
F_15 ( V_131 ) ;
}
static inline bool F_94 ( struct V_30 * V_31 )
{
if ( V_31 -> V_133 & V_134 )
return false ;
if ( ! V_31 -> V_40 -> V_135 )
return false ;
return true ;
}
static void F_95 ( struct V_30 * V_34 )
{
}
static void F_96 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_37 ;
F_29 (bond, slave, i)
if ( F_74 ( V_36 -> V_15 ) )
F_91 ( V_36 ) ;
}
static void F_97 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
F_61 ( & V_11 -> V_20 ) ;
F_96 ( V_11 ) ;
F_64 ( & V_11 -> V_20 ) ;
}
static int F_98 ( struct V_30 * V_15 , struct V_136 * V_137 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
struct V_36 * V_36 ;
int V_37 , V_80 = 0 ;
F_61 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
V_80 = F_88 ( V_36 ) ;
if ( V_80 ) {
F_96 ( V_11 ) ;
break;
}
}
F_64 ( & V_11 -> V_20 ) ;
return V_80 ;
}
static struct V_136 * F_99 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_138 ;
}
static inline int F_88 ( struct V_36 * V_36 )
{
return 0 ;
}
static inline void F_91 ( struct V_36 * V_36 )
{
}
static void F_97 ( struct V_30 * V_34 )
{
}
static int F_100 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_3 ( L_22 , V_34 ) ;
F_3 ( L_23 , V_31 ) ;
F_3 ( L_24 , V_31 -> V_139 ) ;
memcpy ( V_34 -> V_140 , V_31 -> V_140 , V_31 -> V_139 ) ;
return 0 ;
}
static T_2 F_101 ( struct V_30 * V_15 , T_2 V_41 )
{
struct V_36 * V_36 ;
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_2 V_141 ;
int V_37 ;
F_61 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_112 ) {
V_41 |= V_142 ;
goto V_23;
}
V_141 = V_41 ;
V_41 &= ~ V_143 ;
V_41 |= V_144 ;
F_29 (bond, slave, i) {
V_41 = F_102 ( V_41 ,
V_36 -> V_15 -> V_41 ,
V_141 ) ;
}
V_23:
F_64 ( & V_11 -> V_20 ) ;
return V_41 ;
}
static void F_103 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
struct V_30 * V_34 = V_11 -> V_15 ;
T_2 V_145 = V_146 ;
unsigned short V_147 = V_148 ;
int V_37 ;
F_61 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_112 )
goto V_149;
F_29 (bond, slave, i) {
V_145 = F_102 ( V_145 ,
V_36 -> V_15 -> V_145 , V_146 ) ;
if ( V_36 -> V_15 -> V_150 > V_147 )
V_147 = V_36 -> V_15 -> V_150 ;
}
V_149:
V_34 -> V_145 = V_145 ;
V_34 -> V_150 = V_147 ;
F_64 ( & V_11 -> V_20 ) ;
F_104 ( V_34 ) ;
}
static void F_105 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
V_34 -> V_151 = V_31 -> V_151 ;
V_34 -> type = V_31 -> type ;
V_34 -> V_150 = V_31 -> V_150 ;
V_34 -> V_139 = V_31 -> V_139 ;
memcpy ( V_34 -> V_152 , V_31 -> V_152 ,
V_31 -> V_139 ) ;
V_11 -> V_153 = 1 ;
}
static bool F_106 ( struct V_28 * V_29 ,
struct V_36 * V_36 ,
struct V_10 * V_11 )
{
if ( F_107 ( V_36 ) ) {
if ( V_11 -> V_47 . V_1 == V_9 &&
V_29 -> V_154 != V_155 &&
V_29 -> V_154 != V_156 )
return false ;
return true ;
}
return false ;
}
static T_4 F_108 ( struct V_28 * * V_157 )
{
struct V_28 * V_29 = * V_157 ;
struct V_36 * V_36 ;
struct V_10 * V_11 ;
void (* F_109)( struct V_28 * , struct V_10 * ,
struct V_36 * );
V_29 = F_110 ( V_29 , V_158 ) ;
if ( F_22 ( ! V_29 ) )
return V_159 ;
* V_157 = V_29 ;
V_36 = F_111 ( V_29 -> V_15 ) ;
V_11 = V_36 -> V_11 ;
if ( V_11 -> V_47 . V_160 )
V_36 -> V_15 -> V_161 = V_118 ;
F_109 = F_112 ( V_11 -> F_109 ) ;
if ( F_109 ) {
struct V_28 * V_162 = F_113 ( V_29 , V_158 ) ;
if ( F_114 ( V_162 ) ) {
F_109 ( V_162 , V_11 , V_36 ) ;
F_115 ( V_162 ) ;
}
}
if ( F_106 ( V_29 , V_36 , V_11 ) ) {
return V_163 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_47 . V_1 == V_9 &&
V_11 -> V_15 -> V_133 & V_164 &&
V_29 -> V_154 == V_165 ) {
if ( F_22 ( F_116 ( V_29 ,
V_29 -> V_166 - F_117 ( V_29 ) ) ) ) {
F_118 ( V_29 ) ;
return V_159 ;
}
memcpy ( F_119 ( V_29 ) -> V_167 , V_11 -> V_15 -> V_140 , V_96 ) ;
}
return V_168 ;
}
int F_120 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
const struct V_38 * V_39 = V_31 -> V_40 ;
struct V_36 * V_129 = NULL ;
struct V_93 * V_94 ;
struct V_169 V_82 ;
int V_170 ;
int V_21 = 0 ;
if ( ! V_11 -> V_47 . V_68 && V_31 -> V_59 == NULL &&
V_39 -> V_71 == NULL ) {
F_121 ( L_25 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_100 & V_171 ) {
F_3 ( L_26 ) ;
return - V_172 ;
}
if ( V_31 -> V_41 & V_142 ) {
F_3 ( L_27 , V_31 -> V_16 ) ;
if ( F_122 ( V_11 ) ) {
F_30 ( L_28 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
return - V_173 ;
} else {
F_121 ( L_29 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_34 -> V_16 ) ;
}
} else {
F_3 ( L_30 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_100 & V_174 ) ) {
F_30 ( L_31 ,
V_31 -> V_16 ) ;
V_21 = - V_173 ;
goto V_175;
}
if ( V_11 -> V_45 == 0 ) {
if ( V_34 -> type != V_31 -> type ) {
F_3 ( L_32 ,
V_34 -> V_16 ,
V_34 -> type , V_31 -> type ) ;
V_21 = F_84 ( V_34 ,
V_176 ) ;
V_21 = F_123 ( V_21 ) ;
if ( V_21 ) {
F_30 ( L_33 ,
V_34 -> V_16 ) ;
V_21 = - V_172 ;
goto V_175;
}
F_124 ( V_34 ) ;
F_125 ( V_34 ) ;
if ( V_31 -> type != V_177 )
F_105 ( V_34 , V_31 ) ;
else {
F_126 ( V_34 ) ;
V_34 -> V_133 &= ~ V_178 ;
}
F_84 ( V_34 ,
V_179 ) ;
}
} else if ( V_34 -> type != V_31 -> type ) {
F_30 ( L_34 ,
V_31 -> V_16 ,
V_31 -> type , V_34 -> type ) ;
V_21 = - V_180 ;
goto V_175;
}
if ( V_39 -> V_181 == NULL ) {
if ( V_11 -> V_45 == 0 ) {
F_121 ( L_35 ,
V_34 -> V_16 ) ;
V_11 -> V_47 . V_121 = V_182 ;
} else if ( V_11 -> V_47 . V_121 != V_182 ) {
F_30 ( L_36 ,
V_34 -> V_16 ) ;
V_21 = - V_183 ;
goto V_175;
}
}
F_127 ( V_184 , V_31 ) ;
if ( F_128 ( V_11 -> V_15 -> V_140 ) )
memcpy ( V_11 -> V_15 -> V_140 , V_31 -> V_140 ,
V_31 -> V_139 ) ;
V_129 = F_4 ( sizeof( struct V_36 ) , V_17 ) ;
if ( ! V_129 ) {
V_21 = - V_18 ;
goto V_175;
}
V_129 -> V_185 = 0 ;
V_129 -> V_186 = V_31 -> V_187 ;
V_21 = F_129 ( V_31 , V_11 -> V_15 -> V_187 ) ;
if ( V_21 ) {
F_3 ( L_37 , V_21 ) ;
goto V_188;
}
memcpy ( V_129 -> V_189 , V_31 -> V_140 , V_96 ) ;
if ( ! V_11 -> V_47 . V_121 ) {
memcpy ( V_82 . V_190 , V_34 -> V_140 , V_34 -> V_139 ) ;
V_82 . V_191 = V_31 -> type ;
V_21 = F_130 ( V_31 , & V_82 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_192;
}
}
V_21 = F_131 ( V_31 , V_34 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_193;
}
V_21 = F_132 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_31 -> V_16 ) ;
goto V_194;
}
V_129 -> V_11 = V_11 ;
V_129 -> V_15 = V_31 ;
V_31 -> V_133 |= V_195 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_133 ( V_11 , V_129 ) ;
if ( V_21 )
goto V_196;
}
if ( ! F_47 ( V_11 -> V_47 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 ) {
V_21 = F_48 ( V_31 , 1 ) ;
if ( V_21 )
goto V_196;
}
if ( V_34 -> V_100 & V_102 ) {
V_21 = F_50 ( V_31 , 1 ) ;
if ( V_21 )
goto V_196;
}
F_134 ( V_34 ) ;
F_68 (ha, bond_dev)
F_52 ( V_31 , V_94 -> V_82 ) ;
F_135 ( V_34 ) ;
}
if ( V_11 -> V_47 . V_1 == V_7 ) {
T_3 V_95 [ V_96 ] = V_97 ;
F_52 ( V_31 , V_95 ) ;
}
F_32 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_86 ( V_11 , V_129 ) ;
V_129 -> V_114 = 0 ;
V_129 -> V_197 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_103 ( V_11 ) ;
F_61 ( & V_11 -> V_20 ) ;
V_129 -> V_198 = V_118 ;
if ( V_11 -> V_47 . V_119 && ! V_11 -> V_47 . V_68 ) {
V_170 = F_41 ( V_11 , V_31 , 1 ) ;
if ( ( V_170 == - 1 ) && ! V_11 -> V_47 . V_160 ) {
F_121 ( L_41 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_170 == - 1 ) {
F_121 ( L_42 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
}
if ( ! V_11 -> V_47 . V_119 ||
( F_41 ( V_11 , V_31 , 0 ) == V_69 ) ) {
if ( V_11 -> V_47 . V_111 ) {
F_3 ( L_43 ) ;
V_129 -> V_48 = V_113 ;
V_129 -> V_114 = V_11 -> V_47 . V_111 ;
} else {
F_3 ( L_44 ) ;
V_129 -> V_48 = V_49 ;
}
V_129 -> V_118 = V_118 ;
} else {
F_3 ( L_45 ) ;
V_129 -> V_48 = V_199 ;
}
if ( F_39 ( V_129 ) &&
( V_129 -> V_48 != V_199 ) ) {
F_121 ( L_46 ,
V_34 -> V_16 , V_129 -> V_15 -> V_16 ) ;
if ( V_11 -> V_47 . V_1 == V_7 ) {
F_121 ( L_47 ,
V_34 -> V_16 ) ;
}
}
if ( F_47 ( V_11 -> V_47 . V_1 ) && V_11 -> V_47 . V_200 [ 0 ] ) {
if ( strcmp ( V_11 -> V_47 . V_200 , V_129 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_104 = V_129 ;
V_11 -> V_105 = true ;
}
}
F_6 ( & V_11 -> V_123 ) ;
switch ( V_11 -> V_47 . V_1 ) {
case V_4 :
F_82 ( V_129 ) ;
F_85 ( V_11 ) ;
break;
case V_7 :
F_82 ( V_129 ) ;
if ( V_11 -> V_45 == 1 ) {
F_136 ( V_129 ) . V_201 = 1 ;
F_137 ( V_11 , 1000 / V_202 ) ;
} else {
F_136 ( V_129 ) . V_201 =
F_136 ( V_129 -> V_27 ) . V_201 + 1 ;
}
F_138 ( V_129 ) ;
break;
case V_8 :
case V_9 :
F_139 ( V_129 ) ;
F_82 ( V_129 ) ;
F_85 ( V_11 ) ;
break;
default:
F_3 ( L_48 ) ;
F_139 ( V_129 ) ;
if ( ! V_11 -> V_81 )
V_11 -> V_81 = V_129 ;
break;
}
F_8 ( & V_11 -> V_123 ) ;
F_34 ( V_11 ) ;
#ifdef F_140
V_31 -> V_138 = F_99 ( V_11 ) ;
if ( V_31 -> V_138 ) {
if ( F_88 ( V_129 ) ) {
F_64 ( & V_11 -> V_20 ) ;
F_78 ( L_49
L_50 ,
V_34 -> V_16 ) ;
V_21 = - V_172 ;
goto V_196;
}
}
#endif
F_64 ( & V_11 -> V_20 ) ;
V_21 = F_141 ( V_34 , V_31 ) ;
if ( V_21 )
goto V_196;
V_21 = F_142 ( V_31 , F_108 ,
V_129 ) ;
if ( V_21 ) {
F_3 ( L_51 , V_21 ) ;
goto V_203;
}
F_78 ( L_52 ,
V_34 -> V_16 , V_31 -> V_16 ,
F_143 ( V_129 ) ? L_53 : L_54 ,
V_129 -> V_48 != V_199 ? L_55 : L_56 ) ;
return 0 ;
V_203:
F_144 ( V_34 , V_31 ) ;
V_196:
F_145 ( V_31 ) ;
V_194:
F_131 ( V_31 , NULL ) ;
V_193:
if ( ! V_11 -> V_47 . V_121 ) {
memcpy ( V_82 . V_190 , V_129 -> V_189 , V_96 ) ;
V_82 . V_191 = V_31 -> type ;
F_130 ( V_31 , & V_82 ) ;
}
V_192:
F_129 ( V_31 , V_129 -> V_186 ) ;
V_188:
F_15 ( V_129 ) ;
V_175:
F_103 ( V_11 ) ;
return V_21 ;
}
int F_146 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 , * V_204 ;
struct V_169 V_82 ;
T_2 V_205 = V_34 -> V_41 ;
if ( ! ( V_31 -> V_100 & V_171 ) ||
( V_31 -> V_206 != V_34 ) ) {
F_30 ( L_57 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
return - V_180 ;
}
F_10 () ;
F_84 ( V_34 , V_207 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_36 = F_25 ( V_11 , V_31 ) ;
if ( ! V_36 ) {
F_78 ( L_58 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_180 ;
}
F_147 ( V_31 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_148 () ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_47 . V_121 ) {
if ( ! F_149 ( V_34 -> V_140 , V_36 -> V_189 ) &&
V_11 -> V_45 > 1 )
F_121 ( L_59 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_36 -> V_189 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_47 . V_1 == V_7 ) {
F_150 ( V_36 ) ;
}
F_78 ( L_60 ,
V_34 -> V_16 ,
F_143 ( V_36 ) ? L_61 : L_62 ,
V_31 -> V_16 ) ;
V_204 = V_11 -> V_81 ;
V_11 -> V_208 = NULL ;
F_87 ( V_11 , V_36 ) ;
if ( V_11 -> V_104 == V_36 )
V_11 -> V_104 = NULL ;
if ( V_204 == V_36 )
F_77 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_151 ( V_11 , V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_204 == V_36 ) {
F_8 ( & V_11 -> V_20 ) ;
F_61 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_123 ) ;
F_85 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_64 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_45 == 0 ) {
F_34 ( V_11 ) ;
memset ( V_34 -> V_140 , 0 , V_34 -> V_139 ) ;
if ( F_122 ( V_11 ) ) {
F_121 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_121 ( L_64 ,
V_34 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
F_103 ( V_11 ) ;
if ( ! ( V_34 -> V_41 & V_142 ) &&
( V_205 & V_142 ) )
F_78 ( L_65 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
F_144 ( V_34 , V_31 ) ;
F_33 ( V_11 , V_31 ) ;
if ( ! F_47 ( V_11 -> V_47 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 )
F_48 ( V_31 , - 1 ) ;
if ( V_34 -> V_100 & V_102 )
F_50 ( V_31 , - 1 ) ;
F_134 ( V_34 ) ;
F_67 ( V_34 , V_31 ) ;
F_135 ( V_34 ) ;
}
F_131 ( V_31 , NULL ) ;
F_91 ( V_36 ) ;
F_145 ( V_31 ) ;
if ( V_11 -> V_47 . V_121 != V_182 ) {
memcpy ( V_82 . V_190 , V_36 -> V_189 , V_96 ) ;
V_82 . V_191 = V_31 -> type ;
F_130 ( V_31 , & V_82 ) ;
}
F_129 ( V_31 , V_36 -> V_186 ) ;
V_31 -> V_133 &= ~ V_195 ;
F_15 ( V_36 ) ;
return 0 ;
}
static int F_152 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
int V_209 ;
V_209 = F_146 ( V_34 , V_31 ) ;
if ( ( V_209 == 0 ) && ( V_11 -> V_45 == 0 ) ) {
V_34 -> V_133 |= V_134 ;
F_78 ( L_66 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_153 ( V_34 ) ;
}
return V_209 ;
}
static int F_154 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 ;
struct V_30 * V_31 ;
struct V_169 V_82 ;
F_6 ( & V_11 -> V_20 ) ;
F_38 ( V_34 ) ;
if ( V_11 -> V_45 == 0 )
goto V_23;
V_11 -> V_208 = NULL ;
V_11 -> V_104 = NULL ;
F_77 ( V_11 , NULL ) ;
while ( ( V_36 = V_11 -> V_112 ) != NULL ) {
if ( V_11 -> V_47 . V_1 == V_7 )
F_150 ( V_36 ) ;
V_31 = V_36 -> V_15 ;
F_87 ( V_11 , V_36 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_147 ( V_31 ) ;
F_148 () ;
if ( F_13 ( V_11 ) ) {
F_151 ( V_11 , V_36 ) ;
}
F_144 ( V_34 , V_31 ) ;
F_33 ( V_11 , V_31 ) ;
if ( ! F_47 ( V_11 -> V_47 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 )
F_48 ( V_31 , - 1 ) ;
if ( V_34 -> V_100 & V_102 )
F_50 ( V_31 , - 1 ) ;
F_134 ( V_34 ) ;
F_67 ( V_34 , V_31 ) ;
F_135 ( V_34 ) ;
}
F_131 ( V_31 , NULL ) ;
F_91 ( V_36 ) ;
F_145 ( V_31 ) ;
if ( ! V_11 -> V_47 . V_121 ) {
memcpy ( V_82 . V_190 , V_36 -> V_189 , V_96 ) ;
V_82 . V_191 = V_31 -> type ;
F_130 ( V_31 , & V_82 ) ;
}
F_15 ( V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
memset ( V_34 -> V_140 , 0 , V_34 -> V_139 ) ;
if ( F_122 ( V_11 ) ) {
F_121 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_121 ( L_64 ,
V_34 -> V_16 ) ;
}
F_78 ( L_67 , V_34 -> V_16 ) ;
V_23:
F_8 ( & V_11 -> V_20 ) ;
F_103 ( V_11 ) ;
return 0 ;
}
static int F_155 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_99 = NULL ;
struct V_36 * V_98 = NULL ;
int V_21 = 0 ;
if ( ! F_47 ( V_11 -> V_47 . V_1 ) )
return - V_180 ;
if ( ! ( V_31 -> V_100 & V_171 ) || ( V_31 -> V_206 != V_34 ) )
return - V_180 ;
F_61 ( & V_11 -> V_20 ) ;
F_61 ( & V_11 -> V_123 ) ;
V_99 = V_11 -> V_81 ;
F_64 ( & V_11 -> V_123 ) ;
V_98 = F_25 ( V_11 , V_31 ) ;
if ( V_98 && ( V_98 == V_99 ) ) {
F_64 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_98 ) &&
( V_99 ) &&
( V_98 -> V_48 == V_49 ) &&
F_74 ( V_98 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_77 ( V_11 , V_98 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
} else
V_21 = - V_180 ;
F_64 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_156 ( struct V_30 * V_34 , struct V_210 * V_211 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
V_211 -> V_212 = V_11 -> V_47 . V_1 ;
V_211 -> V_119 = V_11 -> V_47 . V_119 ;
F_61 ( & V_11 -> V_20 ) ;
V_211 -> V_213 = V_11 -> V_45 ;
F_64 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_157 ( struct V_30 * V_34 , struct V_214 * V_211 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 ;
int V_37 , V_21 = - V_22 ;
F_61 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
if ( V_37 == ( int ) V_211 -> V_215 ) {
V_21 = 0 ;
strcpy ( V_211 -> V_216 , V_36 -> V_15 -> V_16 ) ;
V_211 -> V_48 = V_36 -> V_48 ;
V_211 -> V_117 = F_158 ( V_36 ) ;
V_211 -> V_197 = V_36 -> V_197 ;
break;
}
}
F_64 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_159 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_37 , V_217 , V_218 = 0 ;
bool V_219 ;
V_219 = ! V_11 -> V_81 ? true : false ;
F_29 (bond, slave, i) {
V_36 -> V_220 = V_221 ;
V_217 = F_41 ( V_11 , V_36 -> V_15 , 0 ) ;
switch ( V_36 -> V_48 ) {
case V_49 :
if ( V_217 )
continue;
V_36 -> V_48 = V_222 ;
V_36 -> V_114 = V_11 -> V_47 . V_223 ;
if ( V_36 -> V_114 ) {
F_78 ( L_68 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_47 . V_1 ==
V_4 ) ?
( F_143 ( V_36 ) ?
L_69 : L_70 ) : L_71 ,
V_36 -> V_15 -> V_16 ,
V_11 -> V_47 . V_223 * V_11 -> V_47 . V_119 ) ;
}
case V_222 :
if ( V_217 ) {
V_36 -> V_48 = V_49 ;
V_36 -> V_118 = V_118 ;
F_78 ( L_72 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_47 . V_223 - V_36 -> V_114 ) *
V_11 -> V_47 . V_119 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_36 -> V_114 <= 0 ) {
V_36 -> V_220 = V_199 ;
V_218 ++ ;
continue;
}
V_36 -> V_114 -- ;
break;
case V_199 :
if ( ! V_217 )
continue;
V_36 -> V_48 = V_113 ;
V_36 -> V_114 = V_11 -> V_47 . V_111 ;
if ( V_36 -> V_114 ) {
F_78 ( L_73 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ,
V_219 ? 0 :
V_11 -> V_47 . V_111 *
V_11 -> V_47 . V_119 ) ;
}
case V_113 :
if ( ! V_217 ) {
V_36 -> V_48 = V_199 ;
F_78 ( L_74 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_47 . V_111 - V_36 -> V_114 ) *
V_11 -> V_47 . V_119 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_219 )
V_36 -> V_114 = 0 ;
if ( V_36 -> V_114 <= 0 ) {
V_36 -> V_220 = V_49 ;
V_218 ++ ;
V_219 = false ;
continue;
}
V_36 -> V_114 -- ;
break;
}
}
return V_218 ;
}
static void F_160 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_37 ;
F_29 (bond, slave, i) {
switch ( V_36 -> V_220 ) {
case V_221 :
continue;
case V_49 :
V_36 -> V_48 = V_49 ;
V_36 -> V_118 = V_118 ;
if ( V_11 -> V_47 . V_1 == V_7 ) {
F_161 ( V_36 ) ;
} else if ( V_11 -> V_47 . V_1 != V_4 ) {
F_139 ( V_36 ) ;
} else if ( V_36 != V_11 -> V_104 ) {
F_161 ( V_36 ) ;
}
F_39 ( V_36 ) ;
F_78 ( L_75 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ,
V_36 -> V_55 , V_36 -> V_57 ? L_76 : L_77 ) ;
if ( V_11 -> V_47 . V_1 == V_7 )
F_79 ( V_36 , V_49 ) ;
if ( F_13 ( V_11 ) )
F_80 ( V_11 , V_36 ,
V_49 ) ;
if ( ! V_11 -> V_81 ||
( V_36 == V_11 -> V_104 ) )
goto V_224;
continue;
case V_199 :
if ( V_36 -> V_197 < V_225 )
V_36 -> V_197 ++ ;
V_36 -> V_48 = V_199 ;
if ( V_11 -> V_47 . V_1 == V_4 ||
V_11 -> V_47 . V_1 == V_7 )
F_82 ( V_36 ) ;
F_78 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_11 -> V_47 . V_1 == V_7 )
F_79 ( V_36 ,
V_199 ) ;
if ( F_13 ( V_11 ) )
F_80 ( V_11 , V_36 ,
V_199 ) ;
if ( V_36 == V_11 -> V_81 )
goto V_224;
continue;
default:
F_30 ( L_79 ,
V_11 -> V_15 -> V_16 , V_36 -> V_220 ,
V_36 -> V_15 -> V_16 ) ;
V_36 -> V_220 = V_221 ;
continue;
}
V_224:
F_162 () ;
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_85 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
F_34 ( V_11 ) ;
}
void F_163 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_66 ( V_92 , struct V_10 ,
V_226 . V_92 ) ;
bool V_120 = false ;
F_61 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_86 )
goto V_23;
if ( V_11 -> V_45 == 0 )
goto V_227;
V_120 = F_75 ( V_11 ) ;
if ( F_159 ( V_11 ) ) {
F_64 ( & V_11 -> V_20 ) ;
F_164 () ;
F_61 ( & V_11 -> V_20 ) ;
F_160 ( V_11 ) ;
F_64 ( & V_11 -> V_20 ) ;
F_165 () ;
F_61 ( & V_11 -> V_20 ) ;
}
V_227:
if ( V_11 -> V_47 . V_119 && ! V_11 -> V_86 )
F_63 ( V_11 -> V_88 , & V_11 -> V_226 ,
F_166 ( V_11 -> V_47 . V_119 ) ) ;
V_23:
F_64 ( & V_11 -> V_20 ) ;
if ( V_120 ) {
F_164 () ;
F_84 ( V_11 -> V_15 , V_125 ) ;
F_165 () ;
}
}
static T_5 F_167 ( struct V_30 * V_15 )
{
struct V_83 * V_228 ;
struct V_229 * V_230 ;
T_5 V_82 = 0 ;
if ( ! V_15 )
return 0 ;
F_56 () ;
V_228 = F_57 ( V_15 ) ;
if ( ! V_228 )
goto V_23;
V_230 = V_228 -> V_231 ;
if ( ! V_230 )
goto V_23;
V_82 = V_230 -> V_232 ;
V_23:
F_59 () ;
return V_82 ;
}
static int F_168 ( struct V_10 * V_11 , T_5 V_233 )
{
struct V_13 * V_14 ;
if ( V_233 == V_11 -> V_234 )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( V_233 == V_14 -> V_235 )
return 1 ;
}
return 0 ;
}
static void F_169 ( struct V_30 * V_31 , int V_236 , T_5 V_237 , T_5 V_238 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_80 , V_236 ,
V_31 -> V_16 , V_237 , V_238 , V_12 ) ;
V_29 = F_170 ( V_236 , V_239 , V_237 , V_31 , V_238 ,
NULL , V_31 -> V_140 , NULL ) ;
if ( ! V_29 ) {
F_30 ( L_81 ) ;
return;
}
if ( V_12 ) {
V_29 = F_171 ( V_29 , V_12 ) ;
if ( ! V_29 ) {
F_30 ( L_82 ) ;
return;
}
}
F_172 ( V_29 ) ;
}
static void F_173 ( struct V_10 * V_11 , struct V_36 * V_36 )
{
int V_37 , V_12 ;
T_5 * V_240 = V_11 -> V_47 . V_241 ;
struct V_13 * V_14 ;
struct V_30 * V_85 ;
struct V_242 * V_243 ;
for ( V_37 = 0 ; ( V_37 < V_244 ) ; V_37 ++ ) {
if ( ! V_240 [ V_37 ] )
break;
F_3 ( L_83 , V_240 [ V_37 ] ) ;
if ( ! F_122 ( V_11 ) ) {
F_3 ( L_84 ) ;
F_169 ( V_36 -> V_15 , V_245 , V_240 [ V_37 ] ,
V_11 -> V_234 , 0 ) ;
continue;
}
V_243 = F_174 ( F_175 ( V_11 -> V_15 ) , V_240 [ V_37 ] , 0 ,
V_246 , 0 ) ;
if ( F_176 ( V_243 ) ) {
if ( F_177 () ) {
F_121 ( L_85 ,
V_11 -> V_15 -> V_16 , & V_240 [ V_37 ] ) ;
}
continue;
}
if ( V_243 -> V_247 . V_15 == V_11 -> V_15 ) {
F_178 ( V_243 ) ;
F_3 ( L_86 ) ;
F_169 ( V_36 -> V_15 , V_245 , V_240 [ V_37 ] ,
V_11 -> V_234 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_56 () ;
V_85 = F_62 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_59 () ;
if ( V_85 == V_243 -> V_247 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_87 ,
V_85 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 ) {
F_178 ( V_243 ) ;
F_169 ( V_36 -> V_15 , V_245 , V_240 [ V_37 ] ,
V_14 -> V_235 , V_12 ) ;
continue;
}
if ( F_177 () ) {
F_121 ( L_88 ,
V_11 -> V_15 -> V_16 , & V_240 [ V_37 ] ,
V_243 -> V_247 . V_15 ? V_243 -> V_247 . V_15 -> V_16 : L_17 ) ;
}
F_178 ( V_243 ) ;
}
}
static void F_179 ( struct V_10 * V_11 , struct V_36 * V_36 , T_5 V_248 , T_5 V_249 )
{
int V_37 ;
T_5 * V_240 = V_11 -> V_47 . V_241 ;
for ( V_37 = 0 ; ( V_37 < V_244 ) && V_240 [ V_37 ] ; V_37 ++ ) {
F_3 ( L_89 ,
& V_248 , & V_249 , V_37 , & V_240 [ V_37 ] ,
F_168 ( V_11 , V_249 ) ) ;
if ( V_248 == V_240 [ V_37 ] ) {
if ( F_168 ( V_11 , V_249 ) )
V_36 -> V_198 = V_118 ;
return;
}
}
}
static void F_180 ( struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_36 * V_36 )
{
struct V_250 * V_251 ;
unsigned char * V_252 ;
T_5 V_248 , V_249 ;
if ( V_29 -> V_253 != F_181 ( V_239 ) )
return;
F_61 ( & V_11 -> V_20 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( ! F_182 ( V_29 , F_183 ( V_11 -> V_15 ) ) )
goto V_254;
V_251 = F_184 ( V_29 ) ;
if ( V_251 -> V_255 != V_11 -> V_15 -> V_139 ||
V_29 -> V_154 == V_256 ||
V_29 -> V_154 == V_257 ||
V_251 -> V_258 != F_185 ( V_177 ) ||
V_251 -> V_259 != F_185 ( V_260 ) ||
V_251 -> V_261 != 4 )
goto V_254;
V_252 = ( unsigned char * ) ( V_251 + 1 ) ;
V_252 += V_11 -> V_15 -> V_139 ;
memcpy ( & V_248 , V_252 , 4 ) ;
V_252 += 4 + V_11 -> V_15 -> V_139 ;
memcpy ( & V_249 , V_252 , 4 ) ;
F_3 ( L_91 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 , F_158 ( V_36 ) ,
V_11 -> V_47 . V_262 , F_186 ( V_11 , V_36 ) ,
& V_248 , & V_249 ) ;
if ( F_143 ( V_36 ) )
F_179 ( V_11 , V_36 , V_248 , V_249 ) ;
else
F_179 ( V_11 , V_36 , V_249 , V_248 ) ;
V_254:
F_64 ( & V_11 -> V_20 ) ;
}
void F_187 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_66 ( V_92 , struct V_10 ,
V_263 . V_92 ) ;
struct V_36 * V_36 , * V_204 ;
int V_224 = 0 ;
int V_264 ;
int V_37 ;
F_61 ( & V_11 -> V_20 ) ;
V_264 = F_166 ( V_11 -> V_47 . V_160 ) ;
if ( V_11 -> V_86 )
goto V_23;
if ( V_11 -> V_45 == 0 )
goto V_227;
F_61 ( & V_11 -> V_123 ) ;
V_204 = V_11 -> V_81 ;
F_64 ( & V_11 -> V_123 ) ;
F_29 (bond, slave, i) {
unsigned long V_265 = F_188 ( V_36 -> V_15 ) ;
if ( V_36 -> V_48 != V_49 ) {
if ( F_189 ( V_118 ,
V_265 - V_264 ,
V_265 + V_264 ) &&
F_189 ( V_118 ,
V_36 -> V_15 -> V_161 - V_264 ,
V_36 -> V_15 -> V_161 + V_264 ) ) {
V_36 -> V_48 = V_49 ;
F_139 ( V_36 ) ;
if ( ! V_204 ) {
F_78 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
V_224 = 1 ;
} else {
F_78 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_189 ( V_118 ,
V_265 - V_264 ,
V_265 + 2 * V_264 ) ||
! F_189 ( V_118 ,
V_36 -> V_15 -> V_161 - V_264 ,
V_36 -> V_15 -> V_161 + 2 * V_264 ) ) {
V_36 -> V_48 = V_199 ;
F_161 ( V_36 ) ;
if ( V_36 -> V_197 < V_225 )
V_36 -> V_197 ++ ;
F_78 ( L_94 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_204 )
V_224 = 1 ;
}
}
if ( F_74 ( V_36 -> V_15 ) )
F_173 ( V_11 , V_36 ) ;
}
if ( V_224 ) {
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_85 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
V_227:
if ( V_11 -> V_47 . V_160 && ! V_11 -> V_86 )
F_63 ( V_11 -> V_88 , & V_11 -> V_263 , V_264 ) ;
V_23:
F_64 ( & V_11 -> V_20 ) ;
}
static int F_190 ( struct V_10 * V_11 , int V_264 )
{
struct V_36 * V_36 ;
int V_37 , V_218 = 0 ;
unsigned long V_265 ;
F_29 (bond, slave, i) {
V_36 -> V_220 = V_221 ;
if ( V_36 -> V_48 != V_49 ) {
if ( F_189 ( V_118 ,
F_191 ( V_11 , V_36 ) - V_264 ,
F_191 ( V_11 , V_36 ) + V_264 ) ) {
V_36 -> V_220 = V_49 ;
V_218 ++ ;
}
continue;
}
if ( F_189 ( V_118 ,
V_36 -> V_118 - V_264 ,
V_36 -> V_118 + 2 * V_264 ) )
continue;
if ( ! F_143 ( V_36 ) &&
! V_11 -> V_208 &&
! F_189 ( V_118 ,
F_191 ( V_11 , V_36 ) - V_264 ,
F_191 ( V_11 , V_36 ) + 3 * V_264 ) ) {
V_36 -> V_220 = V_199 ;
V_218 ++ ;
}
V_265 = F_188 ( V_36 -> V_15 ) ;
if ( F_143 ( V_36 ) &&
( ! F_189 ( V_118 ,
V_265 - V_264 ,
V_265 + 2 * V_264 ) ||
! F_189 ( V_118 ,
F_191 ( V_11 , V_36 ) - V_264 ,
F_191 ( V_11 , V_36 ) + 2 * V_264 ) ) ) {
V_36 -> V_220 = V_199 ;
V_218 ++ ;
}
}
return V_218 ;
}
static void F_192 ( struct V_10 * V_11 , int V_264 )
{
struct V_36 * V_36 ;
int V_37 ;
unsigned long V_265 ;
F_29 (bond, slave, i) {
switch ( V_36 -> V_220 ) {
case V_221 :
continue;
case V_49 :
V_265 = F_188 ( V_36 -> V_15 ) ;
if ( ( ! V_11 -> V_81 &&
F_189 ( V_118 ,
V_265 - V_264 ,
V_265 + V_264 ) ) ||
V_11 -> V_81 != V_36 ) {
V_36 -> V_48 = V_49 ;
V_11 -> V_208 = NULL ;
F_78 ( L_95 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_81 ||
( V_36 == V_11 -> V_104 ) )
goto V_224;
}
continue;
case V_199 :
if ( V_36 -> V_197 < V_225 )
V_36 -> V_197 ++ ;
V_36 -> V_48 = V_199 ;
F_82 ( V_36 ) ;
F_78 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_11 -> V_81 ) {
V_11 -> V_208 = NULL ;
goto V_224;
}
continue;
default:
F_30 ( L_96 ,
V_11 -> V_15 -> V_16 , V_36 -> V_220 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
V_224:
F_162 () ;
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_85 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
F_34 ( V_11 ) ;
}
static void F_193 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_37 ;
F_61 ( & V_11 -> V_123 ) ;
if ( V_11 -> V_208 && V_11 -> V_81 )
F_78 ( L_97 ,
V_11 -> V_208 -> V_15 -> V_16 ,
V_11 -> V_81 -> V_15 -> V_16 ) ;
if ( V_11 -> V_81 ) {
F_173 ( V_11 , V_11 -> V_81 ) ;
F_64 ( & V_11 -> V_123 ) ;
return;
}
F_64 ( & V_11 -> V_123 ) ;
if ( ! V_11 -> V_208 ) {
V_11 -> V_208 = V_11 -> V_112 ;
if ( ! V_11 -> V_208 )
return;
}
F_82 ( V_11 -> V_208 ) ;
F_73 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_74 ( V_36 -> V_15 ) ) {
V_36 -> V_48 = V_113 ;
F_83 ( V_36 ) ;
F_173 ( V_11 , V_36 ) ;
V_36 -> V_118 = V_118 ;
V_11 -> V_208 = V_36 ;
break;
}
if ( V_36 -> V_48 == V_49 ) {
V_36 -> V_48 = V_199 ;
if ( V_36 -> V_197 < V_225 )
V_36 -> V_197 ++ ;
F_82 ( V_36 ) ;
F_78 ( L_98 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
}
}
}
void F_194 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_66 ( V_92 , struct V_10 ,
V_263 . V_92 ) ;
bool V_120 = false ;
int V_264 ;
F_61 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_86 )
goto V_23;
V_264 = F_166 ( V_11 -> V_47 . V_160 ) ;
if ( V_11 -> V_45 == 0 )
goto V_227;
V_120 = F_75 ( V_11 ) ;
if ( F_190 ( V_11 , V_264 ) ) {
F_64 ( & V_11 -> V_20 ) ;
F_164 () ;
F_61 ( & V_11 -> V_20 ) ;
F_192 ( V_11 , V_264 ) ;
F_64 ( & V_11 -> V_20 ) ;
F_165 () ;
F_61 ( & V_11 -> V_20 ) ;
}
F_193 ( V_11 ) ;
V_227:
if ( V_11 -> V_47 . V_160 && ! V_11 -> V_86 )
F_63 ( V_11 -> V_88 , & V_11 -> V_263 , V_264 ) ;
V_23:
F_64 ( & V_11 -> V_20 ) ;
if ( V_120 ) {
F_164 () ;
F_84 ( V_11 -> V_15 , V_125 ) ;
F_165 () ;
}
}
static int F_195 ( struct V_10 * V_11 )
{
F_196 ( V_11 ) ;
F_197 ( V_11 ) ;
F_198 ( V_11 ) ;
return V_266 ;
}
static int F_199 ( unsigned long V_267 ,
struct V_30 * V_34 )
{
struct V_10 * V_268 = F_28 ( V_34 ) ;
switch ( V_267 ) {
case V_269 :
return F_195 ( V_268 ) ;
default:
break;
}
return V_266 ;
}
static int F_200 ( unsigned long V_267 ,
struct V_30 * V_31 )
{
struct V_30 * V_34 = V_31 -> V_206 ;
struct V_10 * V_11 = F_28 ( V_34 ) ;
switch ( V_267 ) {
case V_270 :
if ( V_34 ) {
if ( V_11 -> V_153 )
F_152 ( V_34 , V_31 ) ;
else
F_146 ( V_34 , V_31 ) ;
}
break;
case V_271 :
if ( V_11 -> V_47 . V_1 == V_7 || F_13 ( V_11 ) ) {
struct V_36 * V_36 ;
V_36 = F_25 ( V_11 , V_31 ) ;
if ( V_36 ) {
T_2 V_272 = V_36 -> V_55 ;
T_3 V_273 = V_36 -> V_57 ;
F_39 ( V_36 ) ;
if ( F_13 ( V_11 ) )
break;
if ( V_272 != V_36 -> V_55 )
F_201 ( V_36 ) ;
if ( V_273 != V_36 -> V_57 )
F_202 ( V_36 ) ;
}
}
break;
case V_274 :
break;
case V_275 :
break;
case V_269 :
break;
case V_276 :
F_103 ( V_11 ) ;
break;
default:
break;
}
return V_266 ;
}
static int F_203 ( struct V_277 * V_278 ,
unsigned long V_267 , void * V_279 )
{
struct V_30 * V_280 = (struct V_30 * ) V_279 ;
F_3 ( L_99 ,
V_280 ? V_280 -> V_16 : L_10 ,
V_267 ) ;
if ( ! ( V_280 -> V_133 & V_195 ) )
return V_266 ;
if ( V_280 -> V_100 & V_281 ) {
F_3 ( L_100 ) ;
return F_199 ( V_267 , V_280 ) ;
}
if ( V_280 -> V_100 & V_171 ) {
F_3 ( L_101 ) ;
return F_200 ( V_267 , V_280 ) ;
}
return V_266 ;
}
static int F_204 ( struct V_277 * V_278 , unsigned long V_267 , void * V_279 )
{
struct V_229 * V_230 = V_279 ;
struct V_30 * V_85 , * V_280 = V_230 -> V_282 -> V_15 ;
struct V_283 * V_284 = F_205 ( F_175 ( V_280 ) , V_285 ) ;
struct V_10 * V_11 ;
struct V_13 * V_14 ;
F_11 (bond, &bn->dev_list, bond_list) {
if ( V_11 -> V_15 == V_280 ) {
switch ( V_267 ) {
case V_286 :
V_11 -> V_234 = V_230 -> V_232 ;
return V_287 ;
case V_274 :
V_11 -> V_234 = F_167 ( V_11 -> V_15 ) ;
return V_287 ;
default:
return V_266 ;
}
}
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_85 = F_62 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
if ( V_85 == V_280 ) {
switch ( V_267 ) {
case V_286 :
V_14 -> V_235 = V_230 -> V_232 ;
return V_287 ;
case V_274 :
V_14 -> V_235 =
F_167 ( V_85 ) ;
return V_287 ;
default:
return V_266 ;
}
}
}
}
return V_266 ;
}
static int F_206 ( struct V_28 * V_29 , int V_288 )
{
struct V_289 * V_166 = (struct V_289 * ) V_29 -> V_166 ;
struct V_290 * V_291 = F_207 ( V_29 ) ;
if ( V_29 -> V_253 == F_185 ( V_260 ) ) {
return ( ( F_208 ( V_291 -> V_292 ^ V_291 -> V_293 ) & 0xffff ) ^
( V_166 -> V_167 [ 5 ] ^ V_166 -> V_294 [ 5 ] ) ) % V_288 ;
}
return ( V_166 -> V_167 [ 5 ] ^ V_166 -> V_294 [ 5 ] ) % V_288 ;
}
static int F_209 ( struct V_28 * V_29 , int V_288 )
{
struct V_289 * V_166 = (struct V_289 * ) V_29 -> V_166 ;
struct V_290 * V_291 = F_207 ( V_29 ) ;
T_6 * V_295 = ( T_6 * ) ( ( T_2 * ) V_291 + V_291 -> V_296 ) ;
int V_297 = 0 ;
if ( V_29 -> V_253 == F_185 ( V_260 ) ) {
if ( ! F_210 ( V_291 ) &&
( V_291 -> V_253 == V_298 ||
V_291 -> V_253 == V_299 ) ) {
V_297 = F_211 ( ( * V_295 ^ * ( V_295 + 1 ) ) ) ;
}
return ( V_297 ^
( ( F_208 ( V_291 -> V_292 ^ V_291 -> V_293 ) ) & 0xffff ) ) % V_288 ;
}
return ( V_166 -> V_167 [ 5 ] ^ V_166 -> V_294 [ 5 ] ) % V_288 ;
}
static int F_212 ( struct V_28 * V_29 , int V_288 )
{
struct V_289 * V_166 = (struct V_289 * ) V_29 -> V_166 ;
return ( V_166 -> V_167 [ 5 ] ^ V_166 -> V_294 [ 5 ] ) % V_288 ;
}
static int F_213 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 ;
int V_37 ;
V_11 -> V_86 = 0 ;
F_61 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_45 > 0 ) {
F_61 ( & V_11 -> V_123 ) ;
F_29 (bond, slave, i) {
if ( ( V_11 -> V_47 . V_1 == V_4 )
&& ( V_36 != V_11 -> V_81 ) ) {
F_82 ( V_36 ) ;
} else {
F_83 ( V_36 ) ;
}
}
F_64 ( & V_11 -> V_123 ) ;
}
F_64 ( & V_11 -> V_20 ) ;
F_214 ( & V_11 -> V_89 , F_65 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_215 ( V_11 , ( V_11 -> V_47 . V_1 == V_9 ) ) ) {
return - V_18 ;
}
F_214 ( & V_11 -> V_300 , V_301 ) ;
F_63 ( V_11 -> V_88 , & V_11 -> V_300 , 0 ) ;
}
if ( V_11 -> V_47 . V_119 ) {
F_214 ( & V_11 -> V_226 , F_163 ) ;
F_63 ( V_11 -> V_88 , & V_11 -> V_226 , 0 ) ;
}
if ( V_11 -> V_47 . V_160 ) {
if ( V_11 -> V_47 . V_1 == V_4 )
F_214 ( & V_11 -> V_263 ,
F_194 ) ;
else
F_214 ( & V_11 -> V_263 ,
F_187 ) ;
F_63 ( V_11 -> V_88 , & V_11 -> V_263 , 0 ) ;
if ( V_11 -> V_47 . V_262 )
V_11 -> F_109 = F_180 ;
}
if ( V_11 -> V_47 . V_1 == V_7 ) {
F_214 ( & V_11 -> V_302 , V_303 ) ;
F_63 ( V_11 -> V_88 , & V_11 -> V_302 , 0 ) ;
V_11 -> F_109 = V_304 ;
F_216 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_217 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_115 = 0 ;
V_11 -> V_86 = 1 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_47 . V_119 ) {
F_218 ( & V_11 -> V_226 ) ;
}
if ( V_11 -> V_47 . V_160 ) {
F_218 ( & V_11 -> V_263 ) ;
}
switch ( V_11 -> V_47 . V_1 ) {
case V_7 :
F_218 ( & V_11 -> V_302 ) ;
break;
case V_8 :
case V_9 :
F_218 ( & V_11 -> V_300 ) ;
break;
default:
break;
}
if ( F_219 ( & V_11 -> V_89 ) )
F_218 ( & V_11 -> V_89 ) ;
if ( F_13 ( V_11 ) ) {
F_220 ( V_11 ) ;
}
V_11 -> F_109 = NULL ;
return 0 ;
}
static struct V_305 * F_221 ( struct V_30 * V_34 ,
struct V_305 * V_306 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_305 V_307 ;
struct V_36 * V_36 ;
int V_37 ;
memset ( V_306 , 0 , sizeof( * V_306 ) ) ;
F_222 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
const struct V_305 * V_308 =
F_223 ( V_36 -> V_15 , & V_307 ) ;
V_306 -> V_309 += V_308 -> V_309 ;
V_306 -> V_310 += V_308 -> V_310 ;
V_306 -> V_311 += V_308 -> V_311 ;
V_306 -> V_312 += V_308 -> V_312 ;
V_306 -> V_313 += V_308 -> V_313 ;
V_306 -> V_314 += V_308 -> V_314 ;
V_306 -> V_315 += V_308 -> V_315 ;
V_306 -> V_316 += V_308 -> V_316 ;
V_306 -> V_317 += V_308 -> V_317 ;
V_306 -> V_318 += V_308 -> V_318 ;
V_306 -> V_319 += V_308 -> V_319 ;
V_306 -> V_320 += V_308 -> V_320 ;
V_306 -> V_321 += V_308 -> V_321 ;
V_306 -> V_322 += V_308 -> V_322 ;
V_306 -> V_323 += V_308 -> V_323 ;
V_306 -> V_324 += V_308 -> V_324 ;
V_306 -> V_325 += V_308 -> V_325 ;
V_306 -> V_326 += V_308 -> V_326 ;
V_306 -> V_327 += V_308 -> V_327 ;
V_306 -> V_328 += V_308 -> V_328 ;
V_306 -> V_329 += V_308 -> V_329 ;
}
F_224 ( & V_11 -> V_20 ) ;
return V_306 ;
}
static int F_225 ( struct V_30 * V_34 , struct V_64 * V_65 , int V_52 )
{
struct V_30 * V_31 = NULL ;
struct V_210 V_330 ;
struct V_210 T_7 * V_331 = NULL ;
struct V_214 V_332 ;
struct V_214 T_7 * V_333 = NULL ;
struct V_66 * V_67 = NULL ;
int V_21 = 0 ;
F_3 ( L_102 , V_34 -> V_16 , V_52 ) ;
switch ( V_52 ) {
case V_74 :
V_67 = F_44 ( V_65 ) ;
if ( ! V_67 )
return - V_180 ;
V_67 -> V_334 = 0 ;
case V_77 :
V_67 = F_44 ( V_65 ) ;
if ( ! V_67 )
return - V_180 ;
if ( V_67 -> V_75 == 1 ) {
struct V_10 * V_11 = F_28 ( V_34 ) ;
V_67 -> V_78 = 0 ;
F_61 ( & V_11 -> V_20 ) ;
F_61 ( & V_11 -> V_123 ) ;
if ( F_36 ( V_11 -> V_15 ) )
V_67 -> V_78 = V_69 ;
F_64 ( & V_11 -> V_123 ) ;
F_64 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_335 :
case V_336 :
V_331 = (struct V_210 T_7 * ) V_65 -> V_337 ;
if ( F_226 ( & V_330 , V_331 , sizeof( V_210 ) ) )
return - V_338 ;
V_21 = F_156 ( V_34 , & V_330 ) ;
if ( V_21 == 0 &&
F_227 ( V_331 , & V_330 , sizeof( V_210 ) ) )
return - V_338 ;
return V_21 ;
case V_339 :
case V_340 :
V_333 = (struct V_214 T_7 * ) V_65 -> V_337 ;
if ( F_226 ( & V_332 , V_333 , sizeof( V_214 ) ) )
return - V_338 ;
V_21 = F_157 ( V_34 , & V_332 ) ;
if ( V_21 == 0 &&
F_227 ( V_333 , & V_332 , sizeof( V_214 ) ) )
return - V_338 ;
return V_21 ;
default:
break;
}
if ( ! F_228 ( V_341 ) )
return - V_173 ;
V_31 = F_229 ( F_175 ( V_34 ) , V_65 -> V_342 ) ;
F_3 ( L_103 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_104 , V_31 -> V_16 ) ;
switch ( V_52 ) {
case V_343 :
case V_344 :
V_21 = F_120 ( V_34 , V_31 ) ;
break;
case V_345 :
case V_346 :
V_21 = F_146 ( V_34 , V_31 ) ;
break;
case V_347 :
case V_348 :
V_21 = F_100 ( V_34 , V_31 ) ;
break;
case V_349 :
case V_350 :
V_21 = F_155 ( V_34 , V_31 ) ;
break;
default:
V_21 = - V_183 ;
}
F_230 ( V_31 ) ;
}
return V_21 ;
}
static bool F_231 ( unsigned char * V_82 ,
struct V_351 * V_352 ,
int V_353 )
{
struct V_93 * V_94 ;
F_232 (ha, list)
if ( ! memcmp ( V_94 -> V_82 , V_82 , V_353 ) )
return true ;
return false ;
}
static void F_233 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_93 * V_94 ;
bool V_354 ;
if ( ( V_34 -> V_100 & V_101 ) && ! ( V_11 -> V_100 & V_101 ) )
F_46 ( V_11 , 1 ) ;
if ( ! ( V_34 -> V_100 & V_101 ) && ( V_11 -> V_100 & V_101 ) )
F_46 ( V_11 , - 1 ) ;
if ( ( V_34 -> V_100 & V_102 ) && ! ( V_11 -> V_100 & V_102 ) )
F_49 ( V_11 , 1 ) ;
if ( ! ( V_34 -> V_100 & V_102 ) && ( V_11 -> V_100 & V_102 ) )
F_49 ( V_11 , - 1 ) ;
F_61 ( & V_11 -> V_20 ) ;
V_11 -> V_100 = V_34 -> V_100 ;
F_68 (ha, bond_dev) {
V_354 = F_231 ( V_94 -> V_82 , & V_11 -> V_355 ,
V_34 -> V_139 ) ;
if ( ! V_354 )
F_51 ( V_11 , V_94 -> V_82 ) ;
}
F_232 (ha, &bond->mc_list) {
V_354 = F_231 ( V_94 -> V_82 , & V_34 -> V_356 ,
V_34 -> V_139 ) ;
if ( ! V_354 )
F_53 ( V_11 , V_94 -> V_82 ) ;
}
F_234 ( & V_11 -> V_355 ) ;
F_235 ( & V_11 -> V_355 , & V_34 -> V_356 ,
V_34 -> V_139 , V_357 ) ;
F_64 ( & V_11 -> V_20 ) ;
}
static int F_236 ( struct V_30 * V_15 , struct V_358 * V_359 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
struct V_36 * V_36 = V_11 -> V_112 ;
if ( V_36 ) {
const struct V_38 * V_39
= V_36 -> V_15 -> V_40 ;
if ( V_39 -> V_360 )
return V_39 -> V_360 ( V_36 -> V_15 , V_359 ) ;
}
return 0 ;
}
static int F_237 ( struct V_30 * V_34 , int V_361 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 , * V_362 ;
int V_21 = 0 ;
int V_37 ;
F_3 ( L_105 , V_11 ,
( V_34 ? V_34 -> V_16 : L_10 ) , V_361 ) ;
F_29 (bond, slave, i) {
F_3 ( L_106 ,
V_36 ,
V_36 -> V_27 ,
V_36 -> V_15 -> V_40 -> V_363 ) ;
V_21 = F_129 ( V_36 -> V_15 , V_361 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_364;
}
}
V_34 -> V_187 = V_361 ;
return 0 ;
V_364:
V_362 = V_36 ;
F_238 (bond, slave, i, bond->first_slave, stop_at) {
int V_365 ;
V_365 = F_129 ( V_36 -> V_15 , V_34 -> V_187 ) ;
if ( V_365 ) {
F_3 ( L_108 ,
V_365 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_239 ( struct V_30 * V_34 , void * V_82 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_169 * V_366 = V_82 , V_367 ;
struct V_36 * V_36 , * V_362 ;
int V_21 = 0 ;
int V_37 ;
if ( V_11 -> V_47 . V_1 == V_9 )
return F_240 ( V_34 , V_82 ) ;
F_3 ( L_109 ,
V_11 , V_34 ? V_34 -> V_16 : L_10 ) ;
if ( V_11 -> V_47 . V_121 == V_182 )
return 0 ;
if ( ! F_241 ( V_366 -> V_190 ) )
return - V_368 ;
F_29 (bond, slave, i) {
const struct V_38 * V_39 = V_36 -> V_15 -> V_40 ;
F_3 ( L_110 , V_36 , V_36 -> V_15 -> V_16 ) ;
if ( V_39 -> V_181 == NULL ) {
V_21 = - V_183 ;
F_3 ( L_111 , V_36 -> V_15 -> V_16 ) ;
goto V_364;
}
V_21 = F_130 ( V_36 -> V_15 , V_82 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_364;
}
}
memcpy ( V_34 -> V_140 , V_366 -> V_190 , V_34 -> V_139 ) ;
return 0 ;
V_364:
memcpy ( V_367 . V_190 , V_34 -> V_140 , V_34 -> V_139 ) ;
V_367 . V_191 = V_34 -> type ;
V_362 = V_36 ;
F_238 (bond, slave, i, bond->first_slave, stop_at) {
int V_365 ;
V_365 = F_130 ( V_36 -> V_15 , & V_367 ) ;
if ( V_365 ) {
F_3 ( L_108 ,
V_365 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_242 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 , * V_369 ;
int V_37 , V_370 , V_21 = 1 ;
struct V_290 * V_291 = F_207 ( V_29 ) ;
if ( ( V_291 -> V_253 == V_371 ) &&
( V_29 -> V_253 == F_185 ( V_260 ) ) ) {
F_61 ( & V_11 -> V_123 ) ;
V_36 = V_11 -> V_81 ;
F_64 ( & V_11 -> V_123 ) ;
if ( ! V_36 )
goto V_23;
} else {
V_370 = V_11 -> V_372 ++ % V_11 -> V_45 ;
F_29 (bond, slave, i) {
V_370 -- ;
if ( V_370 < 0 )
break;
}
}
V_369 = V_36 ;
F_73 (bond, slave, i, start_at) {
if ( F_74 ( V_36 -> V_15 ) &&
( V_36 -> V_48 == V_49 ) &&
F_143 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_115 ( V_29 ) ;
}
return V_373 ;
}
static int F_243 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
int V_21 = 1 ;
F_61 ( & V_11 -> V_123 ) ;
if ( V_11 -> V_81 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_81 -> V_15 ) ;
if ( V_21 )
F_115 ( V_29 ) ;
F_64 ( & V_11 -> V_123 ) ;
return V_373 ;
}
static int F_244 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 , * V_369 ;
int V_370 ;
int V_37 ;
int V_21 = 1 ;
V_370 = V_11 -> V_374 ( V_29 , V_11 -> V_45 ) ;
F_29 (bond, slave, i) {
V_370 -- ;
if ( V_370 < 0 )
break;
}
V_369 = V_36 ;
F_73 (bond, slave, i, start_at) {
if ( F_74 ( V_36 -> V_15 ) &&
( V_36 -> V_48 == V_49 ) &&
F_143 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_115 ( V_29 ) ;
}
return V_373 ;
}
static int F_245 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_36 * V_36 , * V_369 ;
struct V_30 * V_375 = NULL ;
int V_37 ;
int V_21 = 1 ;
F_61 ( & V_11 -> V_123 ) ;
V_369 = V_11 -> V_81 ;
F_64 ( & V_11 -> V_123 ) ;
if ( ! V_369 )
goto V_23;
F_73 (bond, slave, i, start_at) {
if ( F_74 ( V_36 -> V_15 ) &&
( V_36 -> V_48 == V_49 ) &&
F_143 ( V_36 ) ) {
if ( V_375 ) {
struct V_28 * V_376 = F_113 ( V_29 , V_158 ) ;
if ( ! V_376 ) {
F_30 ( L_112 ,
V_34 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_376 , V_375 ) ;
if ( V_21 ) {
F_115 ( V_376 ) ;
continue;
}
}
V_375 = V_36 -> V_15 ;
}
}
if ( V_375 )
V_21 = F_20 ( V_11 , V_29 , V_375 ) ;
V_23:
if ( V_21 )
F_115 ( V_29 ) ;
return V_373 ;
}
static void F_246 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_47 . V_377 ) {
case V_378 :
V_11 -> V_374 = F_206 ;
break;
case V_379 :
V_11 -> V_374 = F_209 ;
break;
case V_380 :
default:
V_11 -> V_374 = F_212 ;
break;
}
}
static inline int F_247 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_37 , V_21 = 1 ;
struct V_36 * V_36 = NULL ;
struct V_36 * V_381 ;
if ( ! V_29 -> V_33 )
return 1 ;
F_29 (bond, check_slave, i) {
if ( V_381 -> V_185 == V_29 -> V_33 ) {
V_36 = V_381 ;
break;
}
}
if ( V_36 && V_36 -> V_185 && F_74 ( V_36 -> V_15 ) &&
( V_36 -> V_48 == V_49 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
}
return V_21 ;
}
static T_8 F_248 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_8 V_382 = F_249 ( V_29 ) ? F_250 ( V_29 ) : 0 ;
F_21 ( V_29 ) = V_29 -> V_33 ;
if ( F_22 ( V_382 >= V_15 -> V_383 ) ) {
do {
V_382 -= V_15 -> V_383 ;
} while ( V_382 >= V_15 -> V_383 );
}
return V_382 ;
}
static T_9 F_251 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
if ( F_252 ( V_11 -> V_47 . V_1 ) ) {
if ( ! F_247 ( V_11 , V_29 ) )
return V_373 ;
}
switch ( V_11 -> V_47 . V_1 ) {
case V_3 :
return F_242 ( V_29 , V_15 ) ;
case V_4 :
return F_243 ( V_29 , V_15 ) ;
case V_5 :
return F_244 ( V_29 , V_15 ) ;
case V_6 :
return F_245 ( V_29 , V_15 ) ;
case V_7 :
return F_253 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_254 ( V_29 , V_15 ) ;
default:
F_30 ( L_113 ,
V_15 -> V_16 , V_11 -> V_47 . V_1 ) ;
F_255 ( 1 ) ;
F_115 ( V_29 ) ;
return V_373 ;
}
}
static T_9 F_256 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_9 V_209 = V_373 ;
if ( F_257 ( V_15 ) )
return V_384 ;
F_61 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_45 )
V_209 = F_251 ( V_29 , V_15 ) ;
else
F_115 ( V_29 ) ;
F_64 ( & V_11 -> V_20 ) ;
return V_209 ;
}
void F_258 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_34 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_246 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_246 ( V_11 ) ;
break;
case V_9 :
case V_8 :
break;
default:
F_30 ( L_113 ,
V_34 -> V_16 , V_1 ) ;
break;
}
}
static void F_259 ( struct V_30 * V_34 ,
struct V_385 * V_386 )
{
strncpy ( V_386 -> V_387 , V_388 , 32 ) ;
strncpy ( V_386 -> V_389 , V_390 , 32 ) ;
snprintf ( V_386 -> V_391 , 32 , L_114 , V_392 ) ;
}
static void F_260 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
if ( V_11 -> V_88 )
F_261 ( V_11 -> V_88 ) ;
F_262 ( V_34 ) ;
}
static void F_263 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
F_264 ( & V_11 -> V_20 ) ;
F_264 ( & V_11 -> V_123 ) ;
V_11 -> V_47 = V_393 ;
V_11 -> V_15 = V_34 ;
F_5 ( & V_11 -> V_19 ) ;
F_126 ( V_34 ) ;
V_34 -> V_40 = & V_394 ;
V_34 -> V_59 = & V_395 ;
F_258 ( V_11 , V_11 -> V_47 . V_1 ) ;
V_34 -> V_396 = F_260 ;
V_34 -> V_397 = 0 ;
V_34 -> V_100 |= V_281 | V_398 ;
V_34 -> V_133 |= V_195 ;
V_34 -> V_133 &= ~ ( V_399 | V_178 ) ;
V_34 -> V_41 |= V_142 ;
V_34 -> V_41 |= V_400 ;
V_34 -> V_401 = V_146 |
V_402 |
V_403 |
V_42 ;
V_34 -> V_401 &= ~ ( V_404 & ~ V_405 ) ;
V_34 -> V_41 |= V_34 -> V_401 ;
}
static void F_265 ( struct V_10 * V_11 )
{
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_86 = 1 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_47 . V_119 && F_219 ( & V_11 -> V_226 ) )
F_218 ( & V_11 -> V_226 ) ;
if ( V_11 -> V_47 . V_160 && F_219 ( & V_11 -> V_263 ) )
F_218 ( & V_11 -> V_263 ) ;
if ( V_11 -> V_47 . V_1 == V_9 &&
F_219 ( & V_11 -> V_300 ) )
F_218 ( & V_11 -> V_300 ) ;
if ( V_11 -> V_47 . V_1 == V_7 &&
F_219 ( & V_11 -> V_302 ) )
F_218 ( & V_11 -> V_302 ) ;
if ( F_219 ( & V_11 -> V_89 ) )
F_218 ( & V_11 -> V_89 ) ;
}
static void F_266 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_13 * V_14 , * V_406 ;
F_97 ( V_34 ) ;
F_154 ( V_34 ) ;
F_12 ( & V_11 -> V_407 ) ;
F_265 ( V_11 ) ;
F_196 ( V_11 ) ;
F_267 ( V_11 ) ;
F_234 ( & V_11 -> V_355 ) ;
F_268 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_269 ( const char * V_408 , const struct V_409 * V_410 )
{
int V_411 = - 1 , V_37 , V_128 ;
char * V_412 , V_413 [ V_414 + 1 ] = { 0 , } ;
for ( V_412 = ( char * ) V_408 ; * V_412 ; V_412 ++ )
if ( ! ( isdigit ( * V_412 ) || isspace ( * V_412 ) ) )
break;
if ( * V_412 )
V_128 = sscanf ( V_408 , L_115 , V_413 ) ;
else
V_128 = sscanf ( V_408 , L_114 , & V_411 ) ;
if ( ! V_128 )
return - 1 ;
for ( V_37 = 0 ; V_410 [ V_37 ] . V_415 ; V_37 ++ ) {
if ( V_411 == V_410 [ V_37 ] . V_1 )
return V_410 [ V_37 ] . V_1 ;
if ( strcmp ( V_413 , V_410 [ V_37 ] . V_415 ) == 0 )
return V_410 [ V_37 ] . V_1 ;
}
return - 1 ;
}
static int F_270 ( struct V_416 * V_47 )
{
int V_417 , V_418 , V_419 ;
if ( V_1 ) {
V_212 = F_269 ( V_1 , V_420 ) ;
if ( V_212 == - 1 ) {
F_30 ( L_116 ,
V_1 == NULL ? L_17 : V_1 ) ;
return - V_180 ;
}
}
if ( V_374 ) {
if ( ( V_212 != V_5 ) &&
( V_212 != V_7 ) ) {
F_78 ( L_117 ,
F_1 ( V_212 ) ) ;
} else {
V_421 = F_269 ( V_374 ,
V_422 ) ;
if ( V_421 == - 1 ) {
F_30 ( L_118 ,
V_374 == NULL ? L_17 :
V_374 ) ;
return - V_180 ;
}
}
}
if ( V_423 ) {
if ( V_212 != V_7 ) {
F_78 ( L_119 ,
F_1 ( V_212 ) ) ;
} else {
V_424 = F_269 ( V_423 , V_425 ) ;
if ( V_424 == - 1 ) {
F_30 ( L_120 ,
V_423 == NULL ? L_17 : V_423 ) ;
return - V_180 ;
}
}
}
if ( V_426 ) {
V_47 -> V_426 = F_269 ( V_426 , V_427 ) ;
if ( V_47 -> V_426 == - 1 ) {
F_30 ( L_121 ,
V_426 == NULL ? L_17 : V_426 ) ;
return - V_180 ;
}
if ( V_212 != V_7 ) {
F_121 ( L_122 ) ;
}
} else {
V_47 -> V_426 = V_428 ;
}
if ( V_429 < 0 ) {
F_121 ( L_123 ,
V_429 , 0 , V_430 , V_431 ) ;
V_429 = V_431 ;
}
if ( V_119 < 0 ) {
F_121 ( L_124 ,
V_119 , V_430 , V_432 ) ;
V_119 = V_432 ;
}
if ( V_111 < 0 ) {
F_121 ( L_125 ,
V_111 , V_430 ) ;
V_111 = 0 ;
}
if ( V_223 < 0 ) {
F_121 ( L_126 ,
V_223 , V_430 ) ;
V_223 = 0 ;
}
if ( ( V_68 != 0 ) && ( V_68 != 1 ) ) {
F_121 ( L_127 ,
V_68 ) ;
V_68 = 1 ;
}
if ( V_122 < 0 || V_122 > 255 ) {
F_121 ( L_128 ,
V_122 ) ;
V_122 = 1 ;
}
if ( V_212 == V_7 ) {
if ( ! V_119 ) {
F_121 ( L_129 ) ;
F_121 ( L_130 ) ;
V_119 = 100 ;
}
}
if ( V_433 < 1 || V_433 > 255 ) {
F_121 ( L_131
L_132 ,
V_433 , V_434 ) ;
V_433 = V_434 ;
}
if ( ( V_435 != 0 ) && ( V_435 != 1 ) ) {
F_121 ( L_133
L_134
L_135 , V_435 ) ;
V_435 = 0 ;
}
if ( V_126 < 0 || V_126 > 255 ) {
F_121 ( L_136
L_137 ,
V_126 , V_436 ) ;
V_126 = V_436 ;
}
if ( ( V_212 == V_8 ) ||
( V_212 == V_9 ) ) {
if ( ! V_119 ) {
F_121 ( L_138 ) ;
F_121 ( L_130 ) ;
V_119 = 100 ;
}
}
if ( V_212 == V_9 ) {
F_271 ( L_139 ,
V_111 ) ;
}
if ( ! V_119 ) {
if ( V_111 || V_223 ) {
F_121 ( L_140 ,
V_111 , V_223 ) ;
}
} else {
if ( V_160 ) {
F_121 ( L_141 ,
V_119 , V_160 ) ;
V_160 = 0 ;
}
if ( ( V_111 % V_119 ) != 0 ) {
F_121 ( L_142 ,
V_111 , V_119 ,
( V_111 / V_119 ) * V_119 ) ;
}
V_111 /= V_119 ;
if ( ( V_223 % V_119 ) != 0 ) {
F_121 ( L_143 ,
V_223 , V_119 ,
( V_223 / V_119 ) * V_119 ) ;
}
V_223 /= V_119 ;
}
if ( V_160 < 0 ) {
F_121 ( L_144 ,
V_160 , V_430 , V_437 ) ;
V_160 = V_437 ;
}
for ( V_438 = 0 ;
( V_438 < V_244 ) && V_439 [ V_438 ] ;
V_438 ++ ) {
if ( ! isdigit ( V_439 [ V_438 ] [ 0 ] ) ) {
F_121 ( L_145 ,
V_439 [ V_438 ] ) ;
V_160 = 0 ;
} else {
T_5 V_233 = F_272 ( V_439 [ V_438 ] ) ;
V_440 [ V_438 ] = V_233 ;
}
}
if ( V_160 && ! V_438 ) {
F_121 ( L_146 ,
V_160 ) ;
V_160 = 0 ;
}
if ( V_262 ) {
if ( V_212 != V_4 ) {
F_30 ( L_147 ) ;
return - V_180 ;
}
if ( ! V_160 ) {
F_30 ( L_148 ) ;
return - V_180 ;
}
V_417 = F_269 ( V_262 ,
V_441 ) ;
if ( V_417 == - 1 ) {
F_30 ( L_149 ,
V_262 == NULL ? L_17 : V_262 ) ;
return - V_180 ;
}
} else
V_417 = 0 ;
if ( V_119 ) {
F_78 ( L_150 , V_119 ) ;
} else if ( V_160 ) {
int V_37 ;
F_78 ( L_151 ,
V_160 ,
V_441 [ V_417 ] . V_415 ,
V_438 ) ;
for ( V_37 = 0 ; V_37 < V_438 ; V_37 ++ )
F_78 ( L_152 , V_439 [ V_37 ] ) ;
F_78 ( L_153 ) ;
} else if ( V_429 ) {
F_3 ( L_154 ) ;
}
if ( V_200 && ! F_47 ( V_212 ) ) {
F_121 ( L_155 ,
V_200 , F_1 ( V_212 ) ) ;
V_200 = NULL ;
}
if ( V_200 && V_106 ) {
V_419 = F_269 ( V_106 ,
V_442 ) ;
if ( V_419 == - 1 ) {
F_30 ( L_156 ,
V_106 ==
NULL ? L_17 : V_106 ) ;
return - V_180 ;
}
} else {
V_419 = V_443 ;
}
if ( V_121 ) {
V_418 = F_269 ( V_121 ,
V_444 ) ;
if ( V_418 == - 1 ) {
F_30 ( L_157 ,
V_262 == NULL ? L_17 : V_262 ) ;
return - V_180 ;
}
if ( V_212 != V_4 )
F_121 ( L_158 ) ;
} else {
V_418 = V_445 ;
}
V_47 -> V_1 = V_212 ;
V_47 -> V_377 = V_421 ;
V_47 -> V_119 = V_119 ;
V_47 -> V_122 = V_122 ;
V_47 -> V_160 = V_160 ;
V_47 -> V_262 = V_417 ;
V_47 -> V_111 = V_111 ;
V_47 -> V_223 = V_223 ;
V_47 -> V_68 = V_68 ;
V_47 -> V_424 = V_424 ;
V_47 -> V_200 [ 0 ] = 0 ;
V_47 -> V_106 = V_419 ;
V_47 -> V_121 = V_418 ;
V_47 -> V_433 = V_433 ;
V_47 -> V_435 = V_435 ;
V_47 -> V_126 = V_126 ;
V_47 -> V_446 = V_446 ;
if ( V_200 ) {
strncpy ( V_47 -> V_200 , V_200 , V_73 ) ;
V_47 -> V_200 [ V_73 - 1 ] = 0 ;
}
memcpy ( V_47 -> V_241 , V_440 , sizeof( V_440 ) ) ;
return 0 ;
}
static void F_273 ( struct V_30 * V_15 ,
struct V_447 * V_382 ,
void * V_448 )
{
F_274 ( & V_382 -> V_449 ,
& V_450 ) ;
}
static void F_275 ( struct V_30 * V_15 )
{
F_274 ( & V_15 -> V_451 ,
& V_452 ) ;
F_276 ( V_15 , F_273 , NULL ) ;
}
static int F_277 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_34 ) ;
struct V_283 * V_284 = F_205 ( F_175 ( V_34 ) , V_285 ) ;
struct V_453 * V_454 = & ( F_278 ( V_11 ) ) ;
F_3 ( L_159 , V_34 -> V_16 ) ;
F_279 ( & ( V_454 -> V_455 ) ) ;
F_279 ( & ( V_454 -> V_456 ) ) ;
V_11 -> V_88 = F_280 ( V_34 -> V_16 ) ;
if ( ! V_11 -> V_88 )
return - V_18 ;
F_275 ( V_34 ) ;
F_197 ( V_11 ) ;
F_7 ( & V_11 -> V_407 , & V_284 -> V_457 ) ;
F_281 ( V_11 ) ;
F_282 ( V_11 ) ;
F_283 ( & V_11 -> V_355 ) ;
return 0 ;
}
static int F_284 ( struct V_458 * V_459 [] , struct V_458 * V_166 [] )
{
if ( V_459 [ V_460 ] ) {
if ( F_285 ( V_459 [ V_460 ] ) != V_96 )
return - V_180 ;
if ( ! F_241 ( F_286 ( V_459 [ V_460 ] ) ) )
return - V_368 ;
}
return 0 ;
}
int F_287 ( struct V_461 * V_461 , const char * V_16 )
{
struct V_30 * V_34 ;
int V_21 ;
F_164 () ;
V_34 = F_288 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_160 ,
F_263 , V_433 ) ;
if ( ! V_34 ) {
F_30 ( L_161 , V_16 ) ;
F_165 () ;
return - V_18 ;
}
F_289 ( V_34 , V_461 ) ;
V_34 -> V_462 = & V_463 ;
V_21 = F_290 ( V_34 ) ;
F_38 ( V_34 ) ;
F_165 () ;
if ( V_21 < 0 )
F_260 ( V_34 ) ;
return V_21 ;
}
static int T_10 F_291 ( struct V_461 * V_461 )
{
struct V_283 * V_284 = F_205 ( V_461 , V_285 ) ;
V_284 -> V_461 = V_461 ;
F_5 ( & V_284 -> V_457 ) ;
F_292 ( V_284 ) ;
return 0 ;
}
static void T_11 F_293 ( struct V_461 * V_461 )
{
struct V_283 * V_284 = F_205 ( V_461 , V_285 ) ;
F_294 ( V_284 ) ;
}
static int T_12 F_295 ( void )
{
int V_37 ;
int V_21 ;
F_78 ( L_162 , V_464 ) ;
V_21 = F_270 ( & V_393 ) ;
if ( V_21 )
goto V_23;
V_21 = F_296 ( & V_465 ) ;
if ( V_21 )
goto V_23;
V_21 = F_297 ( & V_463 ) ;
if ( V_21 )
goto V_466;
F_298 () ;
for ( V_37 = 0 ; V_37 < V_429 ; V_37 ++ ) {
V_21 = F_287 ( & V_467 , NULL ) ;
if ( V_21 )
goto V_80;
}
V_21 = F_299 () ;
if ( V_21 )
goto V_80;
F_300 ( & V_468 ) ;
F_301 ( & V_469 ) ;
V_23:
return V_21 ;
V_80:
F_302 ( & V_463 ) ;
V_466:
F_303 ( & V_465 ) ;
goto V_23;
}
static void T_13 F_304 ( void )
{
F_305 ( & V_468 ) ;
F_306 ( & V_469 ) ;
F_307 () ;
F_308 () ;
F_302 ( & V_463 ) ;
F_303 ( & V_465 ) ;
#ifdef F_140
F_309 ( F_310 ( & V_470 ) ) ;
#endif
}
