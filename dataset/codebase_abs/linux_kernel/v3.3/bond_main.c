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
static int F_27 ( struct V_30 * V_33 , T_1 V_34 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_36 ;
int V_37 , V_21 ;
F_29 (bond, slave, i) {
V_21 = F_30 ( V_35 -> V_15 , V_34 ) ;
if ( V_21 )
goto V_38;
}
V_21 = F_2 ( V_11 , V_34 ) ;
if ( V_21 ) {
F_31 ( L_14 ,
V_33 -> V_16 , V_34 ) ;
return V_21 ;
}
return 0 ;
V_38:
V_36 = V_35 ;
F_32 (bond, slave, i, bond->first_slave, stop_at)
F_33 ( V_35 -> V_15 , V_34 ) ;
return V_21 ;
}
static int F_34 ( struct V_30 * V_33 , T_1 V_34 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_37 , V_21 ;
F_29 (bond, slave, i)
F_33 ( V_35 -> V_15 , V_34 ) ;
V_21 = F_9 ( V_11 , V_34 ) ;
if ( V_21 ) {
F_31 ( L_15 ,
V_33 -> V_16 , V_34 ) ;
return V_21 ;
}
return 0 ;
}
static void F_35 ( struct V_10 * V_11 , struct V_30 * V_31 )
{
struct V_13 * V_14 ;
int V_21 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_21 = F_30 ( V_31 , V_14 -> V_12 ) ;
if ( V_21 )
F_36 ( L_16 ,
V_11 -> V_15 -> V_16 , V_14 -> V_12 ,
V_31 -> V_16 ) ;
}
}
static void F_37 ( struct V_10 * V_11 ,
struct V_30 * V_31 )
{
struct V_13 * V_14 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( ! V_14 -> V_12 )
continue;
F_33 ( V_31 , V_14 -> V_12 ) ;
}
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_37 ;
if ( V_11 -> V_39 == 0 )
goto V_40;
if ( V_11 -> V_41 . V_1 == V_7 )
return F_39 ( V_11 ) ;
F_29 (bond, slave, i) {
if ( V_35 -> V_42 == V_43 ) {
if ( ! F_40 ( V_11 -> V_15 ) ) {
F_41 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
}
V_40:
if ( F_40 ( V_11 -> V_15 ) ) {
F_42 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
static int F_43 ( struct V_35 * V_35 )
{
struct V_30 * V_31 = V_35 -> V_15 ;
struct V_44 V_45 ;
T_2 V_46 ;
int V_21 ;
V_35 -> V_47 = V_48 ;
V_35 -> V_49 = V_50 ;
V_21 = F_44 ( V_31 , & V_45 ) ;
if ( V_21 < 0 )
return - 1 ;
V_46 = F_45 ( & V_45 ) ;
if ( V_46 == 0 || V_46 == ( ( V_51 ) - 1 ) )
return - 1 ;
switch ( V_45 . V_49 ) {
case V_52 :
case V_53 :
break;
default:
return - 1 ;
}
V_35 -> V_47 = V_46 ;
V_35 -> V_49 = V_45 . V_49 ;
return 0 ;
}
static int F_46 ( struct V_10 * V_11 ,
struct V_30 * V_31 , int V_54 )
{
const struct V_55 * V_56 = V_31 -> V_57 ;
int (* F_47)( struct V_30 * , struct V_58 * , int );
struct V_58 V_59 ;
struct V_60 * V_61 ;
if ( ! V_54 && ! F_48 ( V_31 ) )
return 0 ;
if ( V_11 -> V_41 . V_62 )
return F_40 ( V_31 ) ? V_63 : 0 ;
if ( V_31 -> V_64 ) {
if ( V_31 -> V_64 -> V_65 ) {
T_2 V_42 ;
V_42 = V_31 -> V_64 -> V_65 ( V_31 ) ;
return V_42 ? V_63 : 0 ;
}
}
F_47 = V_56 -> V_66 ;
if ( F_47 ) {
strncpy ( V_59 . V_67 , V_31 -> V_16 , V_68 ) ;
V_61 = F_49 ( & V_59 ) ;
if ( F_50 ( V_31 , & V_59 , V_69 ) == 0 ) {
V_61 -> V_70 = V_71 ;
if ( F_50 ( V_31 , & V_59 , V_72 ) == 0 )
return V_61 -> V_73 & V_63 ;
}
}
return V_54 ? - 1 : V_63 ;
}
static int F_51 ( struct V_10 * V_11 , int V_74 )
{
int V_75 = 0 ;
if ( F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_11 -> V_76 ) {
V_75 = F_53 ( V_11 -> V_76 -> V_15 ,
V_74 ) ;
}
} else {
struct V_35 * V_35 ;
int V_37 ;
F_29 (bond, slave, i) {
V_75 = F_53 ( V_35 -> V_15 , V_74 ) ;
if ( V_75 )
return V_75 ;
}
}
return V_75 ;
}
static int F_54 ( struct V_10 * V_11 , int V_74 )
{
int V_75 = 0 ;
if ( F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_11 -> V_76 ) {
V_75 = F_55 ( V_11 -> V_76 -> V_15 ,
V_74 ) ;
}
} else {
struct V_35 * V_35 ;
int V_37 ;
F_29 (bond, slave, i) {
V_75 = F_55 ( V_35 -> V_15 , V_74 ) ;
if ( V_75 )
return V_75 ;
}
}
return V_75 ;
}
static void F_56 ( struct V_10 * V_11 , void * V_77 )
{
if ( F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_11 -> V_76 )
F_57 ( V_11 -> V_76 -> V_15 , V_77 ) ;
} else {
struct V_35 * V_35 ;
int V_37 ;
F_29 (bond, slave, i)
F_57 ( V_35 -> V_15 , V_77 ) ;
}
}
static void F_58 ( struct V_10 * V_11 , void * V_77 )
{
if ( F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_11 -> V_76 )
F_59 ( V_11 -> V_76 -> V_15 , V_77 ) ;
} else {
struct V_35 * V_35 ;
int V_37 ;
F_29 (bond, slave, i) {
F_59 ( V_35 -> V_15 , V_77 ) ;
}
}
}
static void F_60 ( struct V_30 * V_15 )
{
struct V_78 * V_79 ;
F_61 () ;
V_79 = F_62 ( V_15 ) ;
if ( V_79 )
F_63 ( V_79 ) ;
F_64 () ;
}
static void F_65 ( struct V_10 * V_11 )
{
struct V_30 * V_80 ;
struct V_13 * V_14 ;
F_66 ( & V_11 -> V_20 ) ;
F_60 ( V_11 -> V_15 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_61 () ;
V_80 = F_67 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_64 () ;
if ( V_80 )
F_60 ( V_80 ) ;
}
if ( -- V_11 -> V_81 > 0 )
F_68 ( V_11 -> V_82 , & V_11 -> V_83 , V_84 / 5 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
static void F_70 ( struct V_85 * V_86 )
{
struct V_10 * V_11 = F_71 ( V_86 , struct V_10 ,
V_83 . V_86 ) ;
F_65 ( V_11 ) ;
}
static void F_72 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_87 * V_88 ;
F_73 (ha, bond_dev)
F_59 ( V_31 , V_88 -> V_77 ) ;
if ( V_11 -> V_41 . V_1 == V_7 ) {
T_3 V_89 [ V_90 ] = V_91 ;
F_59 ( V_31 , V_89 ) ;
}
}
static void F_74 ( struct V_10 * V_11 , struct V_35 * V_92 ,
struct V_35 * V_93 )
{
struct V_87 * V_88 ;
if ( ! F_52 ( V_11 -> V_41 . V_1 ) )
return;
if ( V_93 ) {
if ( V_11 -> V_15 -> V_94 & V_95 )
F_53 ( V_93 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_94 & V_96 )
F_55 ( V_93 -> V_15 , - 1 ) ;
F_73 (ha, bond->dev)
F_59 ( V_93 -> V_15 , V_88 -> V_77 ) ;
}
if ( V_92 ) {
if ( V_11 -> V_15 -> V_94 & V_95 )
F_53 ( V_92 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_94 & V_96 )
F_55 ( V_92 -> V_15 , 1 ) ;
F_73 (ha, bond->dev)
F_57 ( V_92 -> V_15 , V_88 -> V_77 ) ;
}
}
static void F_75 ( struct V_10 * V_11 ,
struct V_35 * V_92 ,
struct V_35 * V_93 )
__releases( &bond->curr_slave_lock
static bool F_76 ( struct V_10 * V_11 )
{
struct V_35 * V_97 = V_11 -> V_98 ;
struct V_35 * V_24 = V_11 -> V_76 ;
if ( ! V_97 || ! V_24 || V_24 -> V_42 != V_43 )
return true ;
if ( V_11 -> V_99 ) {
V_11 -> V_99 = false ;
return true ;
}
if ( V_11 -> V_41 . V_100 == V_101 &&
( V_97 -> V_47 < V_24 -> V_47 ||
( V_97 -> V_47 == V_24 -> V_47 && V_97 -> V_49 <= V_24 -> V_49 ) ) )
return false ;
if ( V_11 -> V_41 . V_100 == V_102 )
return false ;
return true ;
}
static struct V_35 * F_77 ( struct V_10 * V_11 )
{
struct V_35 * V_92 , * V_93 ;
struct V_35 * V_103 = NULL ;
int V_104 = V_11 -> V_41 . V_105 ;
int V_37 ;
V_92 = V_11 -> V_76 ;
if ( ! V_92 ) {
if ( V_11 -> V_39 > 0 )
V_92 = V_11 -> V_106 ;
else
return NULL ;
}
if ( ( V_11 -> V_98 ) &&
V_11 -> V_98 -> V_42 == V_43 &&
F_76 ( V_11 ) ) {
V_92 = V_11 -> V_98 ;
}
V_93 = V_92 ;
F_78 (bond, new_active, i, old_active) {
if ( V_92 -> V_42 == V_43 ) {
return V_92 ;
} else if ( V_92 -> V_42 == V_107 &&
F_79 ( V_92 -> V_15 ) ) {
if ( V_92 -> V_108 < V_104 ) {
V_104 = V_92 -> V_108 ;
V_103 = V_92 ;
}
}
}
return V_103 ;
}
static bool F_80 ( struct V_10 * V_11 )
{
struct V_35 * V_35 = V_11 -> V_76 ;
F_3 ( L_17 ,
V_11 -> V_15 -> V_16 , V_35 ? V_35 -> V_15 -> V_16 : L_18 ) ;
if ( ! V_35 || ! V_11 -> V_109 ||
F_81 ( V_110 , & V_35 -> V_15 -> V_111 ) )
return false ;
V_11 -> V_109 -- ;
return true ;
}
void F_82 ( struct V_10 * V_11 , struct V_35 * V_92 )
{
struct V_35 * V_93 = V_11 -> V_76 ;
if ( V_93 == V_92 )
return;
if ( V_92 ) {
V_92 -> V_112 = V_112 ;
if ( V_92 -> V_42 == V_107 ) {
if ( F_52 ( V_11 -> V_41 . V_1 ) ) {
F_83 ( L_19 ,
V_11 -> V_15 -> V_16 , V_92 -> V_15 -> V_16 ,
( V_11 -> V_41 . V_105 - V_92 -> V_108 ) * V_11 -> V_41 . V_113 ) ;
}
V_92 -> V_108 = 0 ;
V_92 -> V_42 = V_43 ;
if ( V_11 -> V_41 . V_1 == V_7 )
F_84 ( V_92 , V_43 ) ;
if ( F_13 ( V_11 ) )
F_85 ( V_11 , V_92 , V_43 ) ;
} else {
if ( F_52 ( V_11 -> V_41 . V_1 ) ) {
F_83 ( L_20 ,
V_11 -> V_15 -> V_16 , V_92 -> V_15 -> V_16 ) ;
}
}
}
if ( F_52 ( V_11 -> V_41 . V_1 ) )
F_74 ( V_11 , V_92 , V_93 ) ;
if ( F_13 ( V_11 ) ) {
F_86 ( V_11 , V_92 ) ;
if ( V_93 )
F_87 ( V_93 ) ;
if ( V_92 )
F_88 ( V_92 ) ;
} else {
V_11 -> V_76 = V_92 ;
}
if ( V_11 -> V_41 . V_1 == V_4 ) {
if ( V_93 )
F_87 ( V_93 ) ;
if ( V_92 ) {
bool V_114 = false ;
F_88 ( V_92 ) ;
if ( V_11 -> V_41 . V_115 )
F_75 ( V_11 , V_92 ,
V_93 ) ;
if ( F_48 ( V_11 -> V_15 ) ) {
V_11 -> V_109 =
V_11 -> V_41 . V_116 ;
V_114 =
F_80 ( V_11 ) ;
}
F_8 ( & V_11 -> V_117 ) ;
F_69 ( & V_11 -> V_20 ) ;
F_89 ( V_11 -> V_15 , V_118 ) ;
if ( V_114 )
F_89 ( V_11 -> V_15 ,
V_119 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_117 ) ;
}
}
if ( F_48 ( V_11 -> V_15 ) && ( V_11 -> V_41 . V_120 > 0 ) &&
( ( F_52 ( V_11 -> V_41 . V_1 ) && V_92 ) ||
V_11 -> V_41 . V_1 == V_3 ) ) {
V_11 -> V_81 = V_11 -> V_41 . V_120 ;
F_68 ( V_11 -> V_82 , & V_11 -> V_83 , 0 ) ;
}
}
void F_90 ( struct V_10 * V_11 )
{
struct V_35 * V_121 ;
int V_122 ;
V_121 = F_77 ( V_11 ) ;
if ( V_121 != V_11 -> V_76 ) {
F_82 ( V_11 , V_121 ) ;
V_122 = F_38 ( V_11 ) ;
if ( ! V_122 )
return;
if ( F_40 ( V_11 -> V_15 ) ) {
F_83 ( L_21 ,
V_11 -> V_15 -> V_16 ) ;
} else {
F_83 ( L_22 ,
V_11 -> V_15 -> V_16 ) ;
}
}
}
static void F_91 ( struct V_10 * V_11 , struct V_35 * V_123 )
{
if ( V_11 -> V_106 == NULL ) {
V_123 -> V_25 = V_123 ;
V_123 -> V_27 = V_123 ;
V_11 -> V_106 = V_123 ;
} else {
V_123 -> V_25 = V_11 -> V_106 ;
V_123 -> V_27 = V_11 -> V_106 -> V_27 ;
V_123 -> V_25 -> V_27 = V_123 ;
V_123 -> V_27 -> V_25 = V_123 ;
}
V_11 -> V_39 ++ ;
}
static void F_92 ( struct V_10 * V_11 , struct V_35 * V_35 )
{
if ( V_35 -> V_25 )
V_35 -> V_25 -> V_27 = V_35 -> V_27 ;
if ( V_35 -> V_27 )
V_35 -> V_27 -> V_25 = V_35 -> V_25 ;
if ( V_11 -> V_106 == V_35 ) {
if ( V_11 -> V_39 > 1 ) {
V_11 -> V_106 = V_35 -> V_25 ;
} else {
V_11 -> V_106 = NULL ;
}
}
V_35 -> V_25 = NULL ;
V_35 -> V_27 = NULL ;
V_11 -> V_39 -- ;
}
static inline int F_93 ( struct V_35 * V_35 )
{
struct V_124 * V_125 ;
int V_75 = 0 ;
V_125 = F_4 ( sizeof( * V_125 ) , V_17 ) ;
V_75 = - V_18 ;
if ( ! V_125 )
goto V_23;
V_125 -> V_15 = V_35 -> V_15 ;
F_94 ( V_125 -> V_126 , V_35 -> V_15 -> V_16 , V_68 ) ;
V_75 = F_95 ( V_125 ) ;
if ( V_75 ) {
F_15 ( V_125 ) ;
goto V_23;
}
V_35 -> V_125 = V_125 ;
V_23:
return V_75 ;
}
static inline void F_96 ( struct V_35 * V_35 )
{
struct V_124 * V_125 = V_35 -> V_125 ;
if ( ! V_125 )
return;
V_35 -> V_125 = NULL ;
F_97 () ;
F_98 ( V_125 ) ;
F_15 ( V_125 ) ;
}
static inline bool F_99 ( struct V_30 * V_31 )
{
if ( V_31 -> V_127 & V_128 )
return false ;
if ( ! V_31 -> V_57 -> V_129 )
return false ;
return true ;
}
static void F_100 ( struct V_30 * V_33 )
{
}
static void F_101 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_37 ;
F_29 (bond, slave, i)
if ( F_79 ( V_35 -> V_15 ) )
F_96 ( V_35 ) ;
}
static void F_102 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_101 ( V_11 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
static int F_103 ( struct V_30 * V_15 , struct V_130 * V_131 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
struct V_35 * V_35 ;
int V_37 , V_75 = 0 ;
F_66 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
V_75 = F_93 ( V_35 ) ;
if ( V_75 ) {
F_101 ( V_11 ) ;
break;
}
}
F_69 ( & V_11 -> V_20 ) ;
return V_75 ;
}
static struct V_130 * F_104 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_132 ;
}
static inline int F_93 ( struct V_35 * V_35 )
{
return 0 ;
}
static inline void F_96 ( struct V_35 * V_35 )
{
}
static void F_102 ( struct V_30 * V_33 )
{
}
static int F_105 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
F_3 ( L_23 , V_33 ) ;
F_3 ( L_24 , V_31 ) ;
F_3 ( L_25 , V_31 -> V_133 ) ;
memcpy ( V_33 -> V_134 , V_31 -> V_134 , V_31 -> V_133 ) ;
return 0 ;
}
static T_4 F_106 ( struct V_30 * V_15 ,
T_4 V_135 )
{
struct V_35 * V_35 ;
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_4 V_136 ;
int V_37 ;
F_66 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_106 ) {
V_135 |= V_137 ;
goto V_23;
}
V_136 = V_135 ;
V_135 &= ~ V_138 ;
V_135 |= V_139 ;
F_29 (bond, slave, i) {
V_135 = F_107 ( V_135 ,
V_35 -> V_15 -> V_135 ,
V_136 ) ;
}
V_23:
F_69 ( & V_11 -> V_20 ) ;
return V_135 ;
}
static void F_108 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
struct V_30 * V_33 = V_11 -> V_15 ;
T_4 V_140 = V_141 ;
unsigned short V_142 = V_143 ;
int V_37 ;
F_66 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_106 )
goto V_144;
F_29 (bond, slave, i) {
V_140 = F_107 ( V_140 ,
V_35 -> V_15 -> V_140 , V_141 ) ;
if ( V_35 -> V_15 -> V_145 > V_142 )
V_142 = V_35 -> V_15 -> V_145 ;
}
V_144:
V_33 -> V_140 = V_140 ;
V_33 -> V_145 = V_142 ;
F_69 ( & V_11 -> V_20 ) ;
F_109 ( V_33 ) ;
}
static void F_110 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_33 -> V_146 = V_31 -> V_146 ;
V_33 -> type = V_31 -> type ;
V_33 -> V_145 = V_31 -> V_145 ;
V_33 -> V_133 = V_31 -> V_133 ;
memcpy ( V_33 -> V_147 , V_31 -> V_147 ,
V_31 -> V_133 ) ;
V_11 -> V_148 = 1 ;
}
static bool F_111 ( struct V_28 * V_29 ,
struct V_35 * V_35 ,
struct V_10 * V_11 )
{
if ( F_112 ( V_35 ) ) {
if ( V_11 -> V_41 . V_1 == V_9 &&
V_29 -> V_149 != V_150 &&
V_29 -> V_149 != V_151 )
return false ;
return true ;
}
return false ;
}
static T_5 F_113 ( struct V_28 * * V_152 )
{
struct V_28 * V_29 = * V_152 ;
struct V_35 * V_35 ;
struct V_10 * V_11 ;
void (* F_114)( struct V_28 * , struct V_10 * ,
struct V_35 * );
V_29 = F_115 ( V_29 , V_153 ) ;
if ( F_22 ( ! V_29 ) )
return V_154 ;
* V_152 = V_29 ;
V_35 = F_116 ( V_29 -> V_15 ) ;
V_11 = V_35 -> V_11 ;
if ( V_11 -> V_41 . V_155 )
V_35 -> V_15 -> V_156 = V_112 ;
F_114 = F_117 ( V_11 -> F_114 ) ;
if ( F_114 ) {
struct V_28 * V_157 = F_118 ( V_29 , V_153 ) ;
if ( F_119 ( V_157 ) ) {
F_114 ( V_157 , V_11 , V_35 ) ;
F_120 ( V_157 ) ;
}
}
if ( F_111 ( V_29 , V_35 , V_11 ) ) {
return V_158 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_41 . V_1 == V_9 &&
V_11 -> V_15 -> V_127 & V_159 &&
V_29 -> V_149 == V_160 ) {
if ( F_22 ( F_121 ( V_29 ,
V_29 -> V_161 - F_122 ( V_29 ) ) ) ) {
F_123 ( V_29 ) ;
return V_154 ;
}
memcpy ( F_124 ( V_29 ) -> V_162 , V_11 -> V_15 -> V_134 , V_90 ) ;
}
return V_163 ;
}
int F_125 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
const struct V_55 * V_56 = V_31 -> V_57 ;
struct V_35 * V_123 = NULL ;
struct V_87 * V_88 ;
struct V_164 V_77 ;
int V_165 ;
int V_21 = 0 ;
if ( ! V_11 -> V_41 . V_62 && V_31 -> V_64 == NULL &&
V_56 -> V_66 == NULL ) {
F_36 ( L_26 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_94 & V_166 ) {
F_3 ( L_27 ) ;
return - V_167 ;
}
if ( V_31 -> V_135 & V_137 ) {
F_3 ( L_28 , V_31 -> V_16 ) ;
if ( F_126 ( V_11 ) ) {
F_31 ( L_29 ,
V_33 -> V_16 , V_31 -> V_16 , V_33 -> V_16 ) ;
return - V_168 ;
} else {
F_36 ( L_30 ,
V_33 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_33 -> V_16 ) ;
}
} else {
F_3 ( L_31 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_94 & V_169 ) ) {
F_31 ( L_32 ,
V_31 -> V_16 ) ;
V_21 = - V_168 ;
goto V_170;
}
if ( V_11 -> V_39 == 0 ) {
if ( V_33 -> type != V_31 -> type ) {
F_3 ( L_33 ,
V_33 -> V_16 ,
V_33 -> type , V_31 -> type ) ;
V_21 = F_89 ( V_33 ,
V_171 ) ;
V_21 = F_127 ( V_21 ) ;
if ( V_21 ) {
F_31 ( L_34 ,
V_33 -> V_16 ) ;
V_21 = - V_167 ;
goto V_170;
}
F_128 ( V_33 ) ;
F_129 ( V_33 ) ;
if ( V_31 -> type != V_172 )
F_110 ( V_33 , V_31 ) ;
else {
F_130 ( V_33 ) ;
V_33 -> V_127 &= ~ V_173 ;
}
F_89 ( V_33 ,
V_174 ) ;
}
} else if ( V_33 -> type != V_31 -> type ) {
F_31 ( L_35 ,
V_31 -> V_16 ,
V_31 -> type , V_33 -> type ) ;
V_21 = - V_175 ;
goto V_170;
}
if ( V_56 -> V_176 == NULL ) {
if ( V_11 -> V_39 == 0 ) {
F_36 ( L_36 ,
V_33 -> V_16 ) ;
V_11 -> V_41 . V_115 = V_177 ;
} else if ( V_11 -> V_41 . V_115 != V_177 ) {
F_31 ( L_37 ,
V_33 -> V_16 ) ;
V_21 = - V_178 ;
goto V_170;
}
}
F_131 ( V_179 , V_31 ) ;
if ( F_132 ( V_11 -> V_15 -> V_134 ) )
memcpy ( V_11 -> V_15 -> V_134 , V_31 -> V_134 ,
V_31 -> V_133 ) ;
V_123 = F_4 ( sizeof( struct V_35 ) , V_17 ) ;
if ( ! V_123 ) {
V_21 = - V_18 ;
goto V_170;
}
V_123 -> V_180 = 0 ;
V_123 -> V_181 = V_31 -> V_182 ;
V_21 = F_133 ( V_31 , V_11 -> V_15 -> V_182 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_183;
}
memcpy ( V_123 -> V_184 , V_31 -> V_134 , V_90 ) ;
if ( ! V_11 -> V_41 . V_115 ) {
memcpy ( V_77 . V_185 , V_33 -> V_134 , V_33 -> V_133 ) ;
V_77 . V_186 = V_31 -> type ;
V_21 = F_134 ( V_31 , & V_77 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_187;
}
}
V_21 = F_135 ( V_31 , V_33 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_21 ) ;
goto V_188;
}
V_21 = F_136 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_41 , V_31 -> V_16 ) ;
goto V_189;
}
V_123 -> V_11 = V_11 ;
V_123 -> V_15 = V_31 ;
V_31 -> V_127 |= V_190 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_137 ( V_11 , V_123 ) ;
if ( V_21 )
goto V_191;
}
if ( ! F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_33 -> V_94 & V_95 ) {
V_21 = F_53 ( V_31 , 1 ) ;
if ( V_21 )
goto V_191;
}
if ( V_33 -> V_94 & V_96 ) {
V_21 = F_55 ( V_31 , 1 ) ;
if ( V_21 )
goto V_191;
}
F_138 ( V_33 ) ;
F_73 (ha, bond_dev)
F_57 ( V_31 , V_88 -> V_77 ) ;
F_139 ( V_33 ) ;
}
if ( V_11 -> V_41 . V_1 == V_7 ) {
T_3 V_89 [ V_90 ] = V_91 ;
F_57 ( V_31 , V_89 ) ;
}
F_35 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_91 ( V_11 , V_123 ) ;
V_123 -> V_108 = 0 ;
V_123 -> V_192 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_108 ( V_11 ) ;
F_66 ( & V_11 -> V_20 ) ;
V_123 -> V_193 = V_112 ;
if ( V_11 -> V_41 . V_113 && ! V_11 -> V_41 . V_62 ) {
V_165 = F_46 ( V_11 , V_31 , 1 ) ;
if ( ( V_165 == - 1 ) && ! V_11 -> V_41 . V_155 ) {
F_36 ( L_42 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_165 == - 1 ) {
F_36 ( L_43 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
}
if ( ! V_11 -> V_41 . V_113 ||
( F_46 ( V_11 , V_31 , 0 ) == V_63 ) ) {
if ( V_11 -> V_41 . V_105 ) {
F_3 ( L_44 ) ;
V_123 -> V_42 = V_107 ;
V_123 -> V_108 = V_11 -> V_41 . V_105 ;
} else {
F_3 ( L_45 ) ;
V_123 -> V_42 = V_43 ;
}
V_123 -> V_112 = V_112 ;
} else {
F_3 ( L_46 ) ;
V_123 -> V_42 = V_194 ;
}
F_43 ( V_123 ) ;
if ( F_52 ( V_11 -> V_41 . V_1 ) && V_11 -> V_41 . V_195 [ 0 ] ) {
if ( strcmp ( V_11 -> V_41 . V_195 , V_123 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_98 = V_123 ;
V_11 -> V_99 = true ;
}
}
F_6 ( & V_11 -> V_117 ) ;
switch ( V_11 -> V_41 . V_1 ) {
case V_4 :
F_87 ( V_123 ) ;
F_90 ( V_11 ) ;
break;
case V_7 :
F_87 ( V_123 ) ;
if ( V_11 -> V_39 == 1 ) {
F_140 ( V_123 ) . V_196 = 1 ;
F_141 ( V_11 , 1000 / V_197 ) ;
} else {
F_140 ( V_123 ) . V_196 =
F_140 ( V_123 -> V_27 ) . V_196 + 1 ;
}
F_142 ( V_123 ) ;
break;
case V_8 :
case V_9 :
F_143 ( V_123 ) ;
F_87 ( V_123 ) ;
F_90 ( V_11 ) ;
break;
default:
F_3 ( L_47 ) ;
F_143 ( V_123 ) ;
if ( ! V_11 -> V_76 )
V_11 -> V_76 = V_123 ;
break;
}
F_8 ( & V_11 -> V_117 ) ;
F_38 ( V_11 ) ;
#ifdef F_144
V_31 -> V_132 = F_104 ( V_11 ) ;
if ( V_31 -> V_132 ) {
if ( F_93 ( V_123 ) ) {
F_69 ( & V_11 -> V_20 ) ;
F_83 ( L_48
L_49 ,
V_33 -> V_16 ) ;
V_21 = - V_167 ;
goto V_198;
}
}
#endif
F_69 ( & V_11 -> V_20 ) ;
V_21 = F_145 ( V_33 , V_31 ) ;
if ( V_21 )
goto V_198;
V_21 = F_146 ( V_31 , F_113 ,
V_123 ) ;
if ( V_21 ) {
F_3 ( L_50 , V_21 ) ;
goto V_199;
}
F_83 ( L_51 ,
V_33 -> V_16 , V_31 -> V_16 ,
F_147 ( V_123 ) ? L_52 : L_53 ,
V_123 -> V_42 != V_194 ? L_54 : L_55 ) ;
return 0 ;
V_199:
F_148 ( V_33 , V_31 ) ;
V_198:
F_6 ( & V_11 -> V_20 ) ;
F_92 ( V_11 , V_123 ) ;
F_8 ( & V_11 -> V_20 ) ;
V_191:
F_149 ( V_31 ) ;
V_189:
F_135 ( V_31 , NULL ) ;
V_188:
if ( ! V_11 -> V_41 . V_115 ) {
memcpy ( V_77 . V_185 , V_123 -> V_184 , V_90 ) ;
V_77 . V_186 = V_31 -> type ;
F_134 ( V_31 , & V_77 ) ;
}
V_187:
F_133 ( V_31 , V_123 -> V_181 ) ;
V_183:
F_15 ( V_123 ) ;
V_170:
F_108 ( V_11 ) ;
return V_21 ;
}
int F_150 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_200 ;
struct V_164 V_77 ;
T_4 V_201 = V_33 -> V_135 ;
if ( ! ( V_31 -> V_94 & V_166 ) ||
( V_31 -> V_202 != V_33 ) ) {
F_31 ( L_56 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
return - V_175 ;
}
F_10 () ;
F_89 ( V_33 , V_203 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_35 = F_25 ( V_11 , V_31 ) ;
if ( ! V_35 ) {
F_83 ( L_57 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_175 ;
}
F_151 ( V_31 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_152 () ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_41 . V_115 ) {
if ( ! F_153 ( V_33 -> V_134 , V_35 -> V_184 ) &&
V_11 -> V_39 > 1 )
F_36 ( L_58 ,
V_33 -> V_16 , V_31 -> V_16 ,
V_35 -> V_184 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_41 . V_1 == V_7 ) {
F_154 ( V_35 ) ;
}
F_83 ( L_59 ,
V_33 -> V_16 ,
F_147 ( V_35 ) ? L_60 : L_61 ,
V_31 -> V_16 ) ;
V_200 = V_11 -> V_76 ;
V_11 -> V_204 = NULL ;
F_92 ( V_11 , V_35 ) ;
if ( V_11 -> V_98 == V_35 )
V_11 -> V_98 = NULL ;
if ( V_200 == V_35 )
F_82 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_155 ( V_11 , V_35 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_200 == V_35 ) {
F_8 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_117 ) ;
F_90 ( V_11 ) ;
F_8 ( & V_11 -> V_117 ) ;
F_69 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_39 == 0 ) {
F_38 ( V_11 ) ;
memset ( V_33 -> V_134 , 0 , V_33 -> V_133 ) ;
if ( F_126 ( V_11 ) ) {
F_36 ( L_62 ,
V_33 -> V_16 , V_33 -> V_16 ) ;
F_36 ( L_63 ,
V_33 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
F_108 ( V_11 ) ;
if ( ! ( V_33 -> V_135 & V_137 ) &&
( V_201 & V_137 ) )
F_83 ( L_64 ,
V_33 -> V_16 , V_31 -> V_16 , V_33 -> V_16 ) ;
F_148 ( V_33 , V_31 ) ;
F_37 ( V_11 , V_31 ) ;
if ( ! F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_33 -> V_94 & V_95 )
F_53 ( V_31 , - 1 ) ;
if ( V_33 -> V_94 & V_96 )
F_55 ( V_31 , - 1 ) ;
F_138 ( V_33 ) ;
F_72 ( V_33 , V_31 ) ;
F_139 ( V_33 ) ;
}
F_135 ( V_31 , NULL ) ;
F_96 ( V_35 ) ;
F_149 ( V_31 ) ;
if ( V_11 -> V_41 . V_115 != V_177 ) {
memcpy ( V_77 . V_185 , V_35 -> V_184 , V_90 ) ;
V_77 . V_186 = V_31 -> type ;
F_134 ( V_31 , & V_77 ) ;
}
F_133 ( V_31 , V_35 -> V_181 ) ;
V_31 -> V_127 &= ~ V_190 ;
F_15 ( V_35 ) ;
return 0 ;
}
static int F_156 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
int V_205 ;
V_205 = F_150 ( V_33 , V_31 ) ;
if ( ( V_205 == 0 ) && ( V_11 -> V_39 == 0 ) ) {
V_33 -> V_127 |= V_128 ;
F_83 ( L_65 ,
V_33 -> V_16 , V_33 -> V_16 ) ;
F_157 ( V_33 ) ;
}
return V_205 ;
}
static int F_158 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
struct V_30 * V_31 ;
struct V_164 V_77 ;
F_6 ( & V_11 -> V_20 ) ;
F_42 ( V_33 ) ;
if ( V_11 -> V_39 == 0 )
goto V_23;
V_11 -> V_204 = NULL ;
V_11 -> V_98 = NULL ;
F_82 ( V_11 , NULL ) ;
while ( ( V_35 = V_11 -> V_106 ) != NULL ) {
if ( V_11 -> V_41 . V_1 == V_7 )
F_154 ( V_35 ) ;
V_31 = V_35 -> V_15 ;
F_92 ( V_11 , V_35 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_151 ( V_31 ) ;
F_152 () ;
if ( F_13 ( V_11 ) ) {
F_155 ( V_11 , V_35 ) ;
}
F_148 ( V_33 , V_31 ) ;
F_37 ( V_11 , V_31 ) ;
if ( ! F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_33 -> V_94 & V_95 )
F_53 ( V_31 , - 1 ) ;
if ( V_33 -> V_94 & V_96 )
F_55 ( V_31 , - 1 ) ;
F_138 ( V_33 ) ;
F_72 ( V_33 , V_31 ) ;
F_139 ( V_33 ) ;
}
F_135 ( V_31 , NULL ) ;
F_96 ( V_35 ) ;
F_149 ( V_31 ) ;
if ( ! V_11 -> V_41 . V_115 ) {
memcpy ( V_77 . V_185 , V_35 -> V_184 , V_90 ) ;
V_77 . V_186 = V_31 -> type ;
F_134 ( V_31 , & V_77 ) ;
}
F_15 ( V_35 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
memset ( V_33 -> V_134 , 0 , V_33 -> V_133 ) ;
if ( F_126 ( V_11 ) ) {
F_36 ( L_62 ,
V_33 -> V_16 , V_33 -> V_16 ) ;
F_36 ( L_63 ,
V_33 -> V_16 ) ;
}
F_83 ( L_66 , V_33 -> V_16 ) ;
V_23:
F_8 ( & V_11 -> V_20 ) ;
F_108 ( V_11 ) ;
return 0 ;
}
static int F_159 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_93 = NULL ;
struct V_35 * V_92 = NULL ;
int V_21 = 0 ;
if ( ! F_52 ( V_11 -> V_41 . V_1 ) )
return - V_175 ;
if ( ! ( V_31 -> V_94 & V_166 ) || ( V_31 -> V_202 != V_33 ) )
return - V_175 ;
F_66 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_117 ) ;
V_93 = V_11 -> V_76 ;
F_69 ( & V_11 -> V_117 ) ;
V_92 = F_25 ( V_11 , V_31 ) ;
if ( V_92 && ( V_92 == V_93 ) ) {
F_69 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_92 ) &&
( V_93 ) &&
( V_92 -> V_42 == V_43 ) &&
F_79 ( V_92 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_117 ) ;
F_82 ( V_11 , V_92 ) ;
F_8 ( & V_11 -> V_117 ) ;
F_16 () ;
} else
V_21 = - V_175 ;
F_69 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_160 ( struct V_30 * V_33 , struct V_206 * V_207 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_207 -> V_208 = V_11 -> V_41 . V_1 ;
V_207 -> V_113 = V_11 -> V_41 . V_113 ;
F_66 ( & V_11 -> V_20 ) ;
V_207 -> V_209 = V_11 -> V_39 ;
F_69 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_161 ( struct V_30 * V_33 , struct V_210 * V_207 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_37 , V_21 = - V_22 ;
F_66 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
if ( V_37 == ( int ) V_207 -> V_211 ) {
V_21 = 0 ;
strcpy ( V_207 -> V_212 , V_35 -> V_15 -> V_16 ) ;
V_207 -> V_42 = V_35 -> V_42 ;
V_207 -> V_111 = F_162 ( V_35 ) ;
V_207 -> V_192 = V_35 -> V_192 ;
break;
}
}
F_69 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_163 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_37 , V_213 , V_214 = 0 ;
bool V_215 ;
V_215 = ! V_11 -> V_76 ? true : false ;
F_29 (bond, slave, i) {
V_35 -> V_216 = V_217 ;
V_213 = F_46 ( V_11 , V_35 -> V_15 , 0 ) ;
switch ( V_35 -> V_42 ) {
case V_43 :
if ( V_213 )
continue;
V_35 -> V_42 = V_218 ;
V_35 -> V_108 = V_11 -> V_41 . V_219 ;
if ( V_35 -> V_108 ) {
F_83 ( L_67 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_41 . V_1 ==
V_4 ) ?
( F_147 ( V_35 ) ?
L_68 : L_69 ) : L_70 ,
V_35 -> V_15 -> V_16 ,
V_11 -> V_41 . V_219 * V_11 -> V_41 . V_113 ) ;
}
case V_218 :
if ( V_213 ) {
V_35 -> V_42 = V_43 ;
V_35 -> V_112 = V_112 ;
F_83 ( L_71 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_41 . V_219 - V_35 -> V_108 ) *
V_11 -> V_41 . V_113 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
if ( V_35 -> V_108 <= 0 ) {
V_35 -> V_216 = V_194 ;
V_214 ++ ;
continue;
}
V_35 -> V_108 -- ;
break;
case V_194 :
if ( ! V_213 )
continue;
V_35 -> V_42 = V_107 ;
V_35 -> V_108 = V_11 -> V_41 . V_105 ;
if ( V_35 -> V_108 ) {
F_83 ( L_72 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ,
V_215 ? 0 :
V_11 -> V_41 . V_105 *
V_11 -> V_41 . V_113 ) ;
}
case V_107 :
if ( ! V_213 ) {
V_35 -> V_42 = V_194 ;
F_83 ( L_73 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_41 . V_105 - V_35 -> V_108 ) *
V_11 -> V_41 . V_113 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
if ( V_215 )
V_35 -> V_108 = 0 ;
if ( V_35 -> V_108 <= 0 ) {
V_35 -> V_216 = V_43 ;
V_214 ++ ;
V_215 = false ;
continue;
}
V_35 -> V_108 -- ;
break;
}
}
return V_214 ;
}
static void F_164 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_37 ;
F_29 (bond, slave, i) {
switch ( V_35 -> V_216 ) {
case V_217 :
continue;
case V_43 :
V_35 -> V_42 = V_43 ;
V_35 -> V_112 = V_112 ;
if ( V_11 -> V_41 . V_1 == V_7 ) {
F_165 ( V_35 ) ;
} else if ( V_11 -> V_41 . V_1 != V_4 ) {
F_143 ( V_35 ) ;
} else if ( V_35 != V_11 -> V_98 ) {
F_165 ( V_35 ) ;
}
F_43 ( V_35 ) ;
F_83 ( L_74 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ,
V_35 -> V_47 , V_35 -> V_49 ? L_75 : L_76 ) ;
if ( V_11 -> V_41 . V_1 == V_7 )
F_84 ( V_35 , V_43 ) ;
if ( F_13 ( V_11 ) )
F_85 ( V_11 , V_35 ,
V_43 ) ;
if ( ! V_11 -> V_76 ||
( V_35 == V_11 -> V_98 ) )
goto V_220;
continue;
case V_194 :
if ( V_35 -> V_192 < V_221 )
V_35 -> V_192 ++ ;
V_35 -> V_42 = V_194 ;
if ( V_11 -> V_41 . V_1 == V_4 ||
V_11 -> V_41 . V_1 == V_7 )
F_87 ( V_35 ) ;
F_83 ( L_77 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( V_11 -> V_41 . V_1 == V_7 )
F_84 ( V_35 ,
V_194 ) ;
if ( F_13 ( V_11 ) )
F_85 ( V_11 , V_35 ,
V_194 ) ;
if ( V_35 == V_11 -> V_76 )
goto V_220;
continue;
default:
F_31 ( L_78 ,
V_11 -> V_15 -> V_16 , V_35 -> V_216 ,
V_35 -> V_15 -> V_16 ) ;
V_35 -> V_216 = V_217 ;
continue;
}
V_220:
F_166 () ;
F_10 () ;
F_6 ( & V_11 -> V_117 ) ;
F_90 ( V_11 ) ;
F_8 ( & V_11 -> V_117 ) ;
F_16 () ;
}
F_38 ( V_11 ) ;
}
void F_167 ( struct V_85 * V_86 )
{
struct V_10 * V_11 = F_71 ( V_86 , struct V_10 ,
V_222 . V_86 ) ;
bool V_114 = false ;
unsigned long V_108 ;
F_66 ( & V_11 -> V_20 ) ;
V_108 = F_168 ( V_11 -> V_41 . V_113 ) ;
if ( V_11 -> V_39 == 0 )
goto V_223;
V_114 = F_80 ( V_11 ) ;
if ( F_163 ( V_11 ) ) {
F_69 ( & V_11 -> V_20 ) ;
if ( ! F_169 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_108 = 1 ;
V_114 = false ;
goto V_223;
}
F_66 ( & V_11 -> V_20 ) ;
F_164 ( V_11 ) ;
F_69 ( & V_11 -> V_20 ) ;
F_170 () ;
F_66 ( & V_11 -> V_20 ) ;
}
V_223:
if ( V_11 -> V_41 . V_113 )
F_68 ( V_11 -> V_82 , & V_11 -> V_222 , V_108 ) ;
F_69 ( & V_11 -> V_20 ) ;
if ( V_114 ) {
if ( ! F_169 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_11 -> V_109 ++ ;
F_69 ( & V_11 -> V_20 ) ;
return;
}
F_89 ( V_11 -> V_15 , V_119 ) ;
F_170 () ;
}
}
static int F_171 ( struct V_10 * V_11 , T_6 V_224 )
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
static void F_172 ( struct V_30 * V_31 , int V_227 , T_6 V_228 , T_6 V_229 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_79 , V_227 ,
V_31 -> V_16 , V_228 , V_229 , V_12 ) ;
V_29 = F_173 ( V_227 , V_230 , V_228 , V_31 , V_229 ,
NULL , V_31 -> V_134 , NULL ) ;
if ( ! V_29 ) {
F_31 ( L_80 ) ;
return;
}
if ( V_12 ) {
V_29 = F_174 ( V_29 , V_12 ) ;
if ( ! V_29 ) {
F_31 ( L_81 ) ;
return;
}
}
F_175 ( V_29 ) ;
}
static void F_176 ( struct V_10 * V_11 , struct V_35 * V_35 )
{
int V_37 , V_12 ;
T_6 * V_231 = V_11 -> V_41 . V_232 ;
struct V_13 * V_14 ;
struct V_30 * V_80 ;
struct V_233 * V_234 ;
for ( V_37 = 0 ; ( V_37 < V_235 ) ; V_37 ++ ) {
if ( ! V_231 [ V_37 ] )
break;
F_3 ( L_82 , V_231 [ V_37 ] ) ;
if ( ! F_126 ( V_11 ) ) {
F_3 ( L_83 ) ;
F_172 ( V_35 -> V_15 , V_236 , V_231 [ V_37 ] ,
V_11 -> V_225 , 0 ) ;
continue;
}
V_234 = F_177 ( F_178 ( V_11 -> V_15 ) , V_231 [ V_37 ] , 0 ,
V_237 , 0 ) ;
if ( F_179 ( V_234 ) ) {
if ( F_180 () ) {
F_36 ( L_84 ,
V_11 -> V_15 -> V_16 , & V_231 [ V_37 ] ) ;
}
continue;
}
if ( V_234 -> V_238 . V_15 == V_11 -> V_15 ) {
F_181 ( V_234 ) ;
F_3 ( L_85 ) ;
F_172 ( V_35 -> V_15 , V_236 , V_231 [ V_37 ] ,
V_11 -> V_225 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_61 () ;
V_80 = F_67 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_64 () ;
if ( V_80 == V_234 -> V_238 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_86 ,
V_80 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 ) {
F_181 ( V_234 ) ;
F_172 ( V_35 -> V_15 , V_236 , V_231 [ V_37 ] ,
V_14 -> V_226 , V_12 ) ;
continue;
}
if ( F_180 () ) {
F_36 ( L_87 ,
V_11 -> V_15 -> V_16 , & V_231 [ V_37 ] ,
V_234 -> V_238 . V_15 ? V_234 -> V_238 . V_15 -> V_16 : L_18 ) ;
}
F_181 ( V_234 ) ;
}
}
static void F_182 ( struct V_10 * V_11 , struct V_35 * V_35 , T_6 V_239 , T_6 V_240 )
{
int V_37 ;
T_6 * V_231 = V_11 -> V_41 . V_232 ;
for ( V_37 = 0 ; ( V_37 < V_235 ) && V_231 [ V_37 ] ; V_37 ++ ) {
F_3 ( L_88 ,
& V_239 , & V_240 , V_37 , & V_231 [ V_37 ] ,
F_171 ( V_11 , V_240 ) ) ;
if ( V_239 == V_231 [ V_37 ] ) {
if ( F_171 ( V_11 , V_240 ) )
V_35 -> V_193 = V_112 ;
return;
}
}
}
static void F_183 ( struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_35 * V_35 )
{
struct V_241 * V_242 ;
unsigned char * V_243 ;
T_6 V_239 , V_240 ;
if ( V_29 -> V_244 != F_184 ( V_230 ) )
return;
F_66 ( & V_11 -> V_20 ) ;
F_3 ( L_89 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( ! F_185 ( V_29 , F_186 ( V_11 -> V_15 ) ) )
goto V_245;
V_242 = F_187 ( V_29 ) ;
if ( V_242 -> V_246 != V_11 -> V_15 -> V_133 ||
V_29 -> V_149 == V_247 ||
V_29 -> V_149 == V_248 ||
V_242 -> V_249 != F_188 ( V_172 ) ||
V_242 -> V_250 != F_188 ( V_251 ) ||
V_242 -> V_252 != 4 )
goto V_245;
V_243 = ( unsigned char * ) ( V_242 + 1 ) ;
V_243 += V_11 -> V_15 -> V_133 ;
memcpy ( & V_239 , V_243 , 4 ) ;
V_243 += 4 + V_11 -> V_15 -> V_133 ;
memcpy ( & V_240 , V_243 , 4 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 , F_162 ( V_35 ) ,
V_11 -> V_41 . V_253 , F_189 ( V_11 , V_35 ) ,
& V_239 , & V_240 ) ;
if ( F_147 ( V_35 ) )
F_182 ( V_11 , V_35 , V_239 , V_240 ) ;
else
F_182 ( V_11 , V_35 , V_240 , V_239 ) ;
V_245:
F_69 ( & V_11 -> V_20 ) ;
}
void F_190 ( struct V_85 * V_86 )
{
struct V_10 * V_11 = F_71 ( V_86 , struct V_10 ,
V_254 . V_86 ) ;
struct V_35 * V_35 , * V_200 ;
int V_220 = 0 ;
int V_255 ;
int V_37 ;
F_66 ( & V_11 -> V_20 ) ;
V_255 = F_168 ( V_11 -> V_41 . V_155 ) ;
if ( V_11 -> V_39 == 0 )
goto V_223;
F_66 ( & V_11 -> V_117 ) ;
V_200 = V_11 -> V_76 ;
F_69 ( & V_11 -> V_117 ) ;
F_29 (bond, slave, i) {
unsigned long V_256 = F_191 ( V_35 -> V_15 ) ;
if ( V_35 -> V_42 != V_43 ) {
if ( F_192 ( V_112 ,
V_256 - V_255 ,
V_256 + V_255 ) &&
F_192 ( V_112 ,
V_35 -> V_15 -> V_156 - V_255 ,
V_35 -> V_15 -> V_156 + V_255 ) ) {
V_35 -> V_42 = V_43 ;
F_143 ( V_35 ) ;
if ( ! V_200 ) {
F_83 ( L_91 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
V_220 = 1 ;
} else {
F_83 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_192 ( V_112 ,
V_256 - V_255 ,
V_256 + 2 * V_255 ) ||
! F_192 ( V_112 ,
V_35 -> V_15 -> V_156 - V_255 ,
V_35 -> V_15 -> V_156 + 2 * V_255 ) ) {
V_35 -> V_42 = V_194 ;
F_165 ( V_35 ) ;
if ( V_35 -> V_192 < V_221 )
V_35 -> V_192 ++ ;
F_83 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
if ( V_35 == V_200 )
V_220 = 1 ;
}
}
if ( F_79 ( V_35 -> V_15 ) )
F_176 ( V_11 , V_35 ) ;
}
if ( V_220 ) {
F_10 () ;
F_6 ( & V_11 -> V_117 ) ;
F_90 ( V_11 ) ;
F_8 ( & V_11 -> V_117 ) ;
F_16 () ;
}
V_223:
if ( V_11 -> V_41 . V_155 )
F_68 ( V_11 -> V_82 , & V_11 -> V_254 , V_255 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
static int F_193 ( struct V_10 * V_11 , int V_255 )
{
struct V_35 * V_35 ;
int V_37 , V_214 = 0 ;
unsigned long V_256 ;
F_29 (bond, slave, i) {
V_35 -> V_216 = V_217 ;
if ( V_35 -> V_42 != V_43 ) {
if ( F_192 ( V_112 ,
F_194 ( V_11 , V_35 ) - V_255 ,
F_194 ( V_11 , V_35 ) + V_255 ) ) {
V_35 -> V_216 = V_43 ;
V_214 ++ ;
}
continue;
}
if ( F_192 ( V_112 ,
V_35 -> V_112 - V_255 ,
V_35 -> V_112 + 2 * V_255 ) )
continue;
if ( ! F_147 ( V_35 ) &&
! V_11 -> V_204 &&
! F_192 ( V_112 ,
F_194 ( V_11 , V_35 ) - V_255 ,
F_194 ( V_11 , V_35 ) + 3 * V_255 ) ) {
V_35 -> V_216 = V_194 ;
V_214 ++ ;
}
V_256 = F_191 ( V_35 -> V_15 ) ;
if ( F_147 ( V_35 ) &&
( ! F_192 ( V_112 ,
V_256 - V_255 ,
V_256 + 2 * V_255 ) ||
! F_192 ( V_112 ,
F_194 ( V_11 , V_35 ) - V_255 ,
F_194 ( V_11 , V_35 ) + 2 * V_255 ) ) ) {
V_35 -> V_216 = V_194 ;
V_214 ++ ;
}
}
return V_214 ;
}
static void F_195 ( struct V_10 * V_11 , int V_255 )
{
struct V_35 * V_35 ;
int V_37 ;
unsigned long V_256 ;
F_29 (bond, slave, i) {
switch ( V_35 -> V_216 ) {
case V_217 :
continue;
case V_43 :
V_256 = F_191 ( V_35 -> V_15 ) ;
if ( ( ! V_11 -> V_76 &&
F_192 ( V_112 ,
V_256 - V_255 ,
V_256 + V_255 ) ) ||
V_11 -> V_76 != V_35 ) {
V_35 -> V_42 = V_43 ;
V_11 -> V_204 = NULL ;
F_83 ( L_94 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_76 ||
( V_35 == V_11 -> V_98 ) )
goto V_220;
}
continue;
case V_194 :
if ( V_35 -> V_192 < V_221 )
V_35 -> V_192 ++ ;
V_35 -> V_42 = V_194 ;
F_87 ( V_35 ) ;
F_83 ( L_77 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( V_35 == V_11 -> V_76 ) {
V_11 -> V_204 = NULL ;
goto V_220;
}
continue;
default:
F_31 ( L_95 ,
V_11 -> V_15 -> V_16 , V_35 -> V_216 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
V_220:
F_166 () ;
F_10 () ;
F_6 ( & V_11 -> V_117 ) ;
F_90 ( V_11 ) ;
F_8 ( & V_11 -> V_117 ) ;
F_16 () ;
}
F_38 ( V_11 ) ;
}
static void F_196 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_37 ;
F_66 ( & V_11 -> V_117 ) ;
if ( V_11 -> V_204 && V_11 -> V_76 )
F_83 ( L_96 ,
V_11 -> V_204 -> V_15 -> V_16 ,
V_11 -> V_76 -> V_15 -> V_16 ) ;
if ( V_11 -> V_76 ) {
F_176 ( V_11 , V_11 -> V_76 ) ;
F_69 ( & V_11 -> V_117 ) ;
return;
}
F_69 ( & V_11 -> V_117 ) ;
if ( ! V_11 -> V_204 ) {
V_11 -> V_204 = V_11 -> V_106 ;
if ( ! V_11 -> V_204 )
return;
}
F_87 ( V_11 -> V_204 ) ;
F_78 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_79 ( V_35 -> V_15 ) ) {
V_35 -> V_42 = V_107 ;
F_88 ( V_35 ) ;
F_176 ( V_11 , V_35 ) ;
V_35 -> V_112 = V_112 ;
V_11 -> V_204 = V_35 ;
break;
}
if ( V_35 -> V_42 == V_43 ) {
V_35 -> V_42 = V_194 ;
if ( V_35 -> V_192 < V_221 )
V_35 -> V_192 ++ ;
F_87 ( V_35 ) ;
F_83 ( L_97 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
}
}
}
void F_197 ( struct V_85 * V_86 )
{
struct V_10 * V_11 = F_71 ( V_86 , struct V_10 ,
V_254 . V_86 ) ;
bool V_114 = false ;
int V_255 ;
F_66 ( & V_11 -> V_20 ) ;
V_255 = F_168 ( V_11 -> V_41 . V_155 ) ;
if ( V_11 -> V_39 == 0 )
goto V_223;
V_114 = F_80 ( V_11 ) ;
if ( F_193 ( V_11 , V_255 ) ) {
F_69 ( & V_11 -> V_20 ) ;
if ( ! F_169 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_255 = 1 ;
V_114 = false ;
goto V_223;
}
F_66 ( & V_11 -> V_20 ) ;
F_195 ( V_11 , V_255 ) ;
F_69 ( & V_11 -> V_20 ) ;
F_170 () ;
F_66 ( & V_11 -> V_20 ) ;
}
F_196 ( V_11 ) ;
V_223:
if ( V_11 -> V_41 . V_155 )
F_68 ( V_11 -> V_82 , & V_11 -> V_254 , V_255 ) ;
F_69 ( & V_11 -> V_20 ) ;
if ( V_114 ) {
if ( ! F_169 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_11 -> V_109 ++ ;
F_69 ( & V_11 -> V_20 ) ;
return;
}
F_89 ( V_11 -> V_15 , V_119 ) ;
F_170 () ;
}
}
static int F_198 ( struct V_10 * V_11 )
{
F_199 ( V_11 ) ;
F_200 ( V_11 ) ;
F_201 ( V_11 ) ;
return V_257 ;
}
static int F_202 ( unsigned long V_258 ,
struct V_30 * V_33 )
{
struct V_10 * V_259 = F_28 ( V_33 ) ;
switch ( V_258 ) {
case V_260 :
return F_198 ( V_259 ) ;
default:
break;
}
return V_257 ;
}
static int F_203 ( unsigned long V_258 ,
struct V_30 * V_31 )
{
struct V_30 * V_33 = V_31 -> V_202 ;
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 = NULL ;
switch ( V_258 ) {
case V_261 :
if ( V_33 ) {
if ( V_11 -> V_148 )
F_156 ( V_33 , V_31 ) ;
else
F_150 ( V_33 , V_31 ) ;
}
break;
case V_262 :
case V_263 :
V_35 = F_25 ( V_11 , V_31 ) ;
if ( V_35 ) {
T_2 V_264 = V_35 -> V_47 ;
T_3 V_265 = V_35 -> V_49 ;
F_43 ( V_35 ) ;
if ( V_11 -> V_41 . V_1 == V_7 ) {
if ( V_264 != V_35 -> V_47 )
F_204 ( V_35 ) ;
if ( V_265 != V_35 -> V_49 )
F_205 ( V_35 ) ;
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
F_108 ( V_11 ) ;
break;
default:
break;
}
return V_257 ;
}
static int F_206 ( struct V_269 * V_270 ,
unsigned long V_258 , void * V_271 )
{
struct V_30 * V_272 = (struct V_30 * ) V_271 ;
F_3 ( L_98 ,
V_272 ? V_272 -> V_16 : L_10 ,
V_258 ) ;
if ( ! ( V_272 -> V_127 & V_190 ) )
return V_257 ;
if ( V_272 -> V_94 & V_273 ) {
F_3 ( L_99 ) ;
return F_202 ( V_258 , V_272 ) ;
}
if ( V_272 -> V_94 & V_166 ) {
F_3 ( L_100 ) ;
return F_203 ( V_258 , V_272 ) ;
}
return V_257 ;
}
static int F_207 ( struct V_269 * V_270 , unsigned long V_258 , void * V_271 )
{
struct V_274 * V_275 = V_271 ;
struct V_30 * V_80 , * V_272 = V_275 -> V_276 -> V_15 ;
struct V_277 * V_278 = F_208 ( F_178 ( V_272 ) , V_279 ) ;
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
V_80 = F_67 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
if ( V_80 == V_272 ) {
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
static int F_209 ( struct V_28 * V_29 , int V_284 )
{
struct V_285 * V_161 = (struct V_285 * ) V_29 -> V_161 ;
struct V_286 * V_287 = F_210 ( V_29 ) ;
if ( V_29 -> V_244 == F_188 ( V_251 ) ) {
return ( ( F_211 ( V_287 -> V_288 ^ V_287 -> V_289 ) & 0xffff ) ^
( V_161 -> V_162 [ 5 ] ^ V_161 -> V_290 [ 5 ] ) ) % V_284 ;
}
return ( V_161 -> V_162 [ 5 ] ^ V_161 -> V_290 [ 5 ] ) % V_284 ;
}
static int F_212 ( struct V_28 * V_29 , int V_284 )
{
struct V_285 * V_161 = (struct V_285 * ) V_29 -> V_161 ;
struct V_286 * V_287 = F_210 ( V_29 ) ;
T_7 * V_291 = ( T_7 * ) ( ( T_2 * ) V_287 + V_287 -> V_292 ) ;
int V_293 = 0 ;
if ( V_29 -> V_244 == F_188 ( V_251 ) ) {
if ( ! F_213 ( V_287 ) &&
( V_287 -> V_244 == V_294 ||
V_287 -> V_244 == V_295 ) ) {
V_293 = F_214 ( ( * V_291 ^ * ( V_291 + 1 ) ) ) ;
}
return ( V_293 ^
( ( F_211 ( V_287 -> V_288 ^ V_287 -> V_289 ) ) & 0xffff ) ) % V_284 ;
}
return ( V_161 -> V_162 [ 5 ] ^ V_161 -> V_290 [ 5 ] ) % V_284 ;
}
static int F_215 ( struct V_28 * V_29 , int V_284 )
{
struct V_285 * V_161 = (struct V_285 * ) V_29 -> V_161 ;
return ( V_161 -> V_162 [ 5 ] ^ V_161 -> V_290 [ 5 ] ) % V_284 ;
}
static int F_216 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_37 ;
F_66 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_39 > 0 ) {
F_66 ( & V_11 -> V_117 ) ;
F_29 (bond, slave, i) {
if ( ( V_11 -> V_41 . V_1 == V_4 )
&& ( V_35 != V_11 -> V_76 ) ) {
F_87 ( V_35 ) ;
} else {
F_88 ( V_35 ) ;
}
}
F_69 ( & V_11 -> V_117 ) ;
}
F_69 ( & V_11 -> V_20 ) ;
F_217 ( & V_11 -> V_83 , F_70 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_218 ( V_11 , ( V_11 -> V_41 . V_1 == V_9 ) ) ) {
return - V_18 ;
}
F_217 ( & V_11 -> V_296 , V_297 ) ;
F_68 ( V_11 -> V_82 , & V_11 -> V_296 , 0 ) ;
}
if ( V_11 -> V_41 . V_113 ) {
F_217 ( & V_11 -> V_222 , F_167 ) ;
F_68 ( V_11 -> V_82 , & V_11 -> V_222 , 0 ) ;
}
if ( V_11 -> V_41 . V_155 ) {
if ( V_11 -> V_41 . V_1 == V_4 )
F_217 ( & V_11 -> V_254 ,
F_197 ) ;
else
F_217 ( & V_11 -> V_254 ,
F_190 ) ;
F_68 ( V_11 -> V_82 , & V_11 -> V_254 , 0 ) ;
if ( V_11 -> V_41 . V_253 )
V_11 -> F_114 = F_183 ;
}
if ( V_11 -> V_41 . V_1 == V_7 ) {
F_217 ( & V_11 -> V_298 , V_299 ) ;
F_68 ( V_11 -> V_82 , & V_11 -> V_298 , 0 ) ;
V_11 -> F_114 = V_300 ;
F_219 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_220 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_109 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_41 . V_113 ) {
F_221 ( & V_11 -> V_222 ) ;
}
if ( V_11 -> V_41 . V_155 ) {
F_221 ( & V_11 -> V_254 ) ;
}
switch ( V_11 -> V_41 . V_1 ) {
case V_7 :
F_221 ( & V_11 -> V_298 ) ;
break;
case V_8 :
case V_9 :
F_221 ( & V_11 -> V_296 ) ;
break;
default:
break;
}
if ( F_222 ( & V_11 -> V_83 ) )
F_221 ( & V_11 -> V_83 ) ;
if ( F_13 ( V_11 ) ) {
F_223 ( V_11 ) ;
}
V_11 -> F_114 = NULL ;
return 0 ;
}
static struct V_301 * F_224 ( struct V_30 * V_33 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_301 V_303 ;
struct V_35 * V_35 ;
int V_37 ;
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
F_225 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
const struct V_301 * V_304 =
F_226 ( V_35 -> V_15 , & V_303 ) ;
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
F_227 ( & V_11 -> V_20 ) ;
return V_302 ;
}
static int F_228 ( struct V_30 * V_33 , struct V_58 * V_59 , int V_326 )
{
struct V_30 * V_31 = NULL ;
struct V_206 V_327 ;
struct V_206 T_8 * V_328 = NULL ;
struct V_210 V_329 ;
struct V_210 T_8 * V_330 = NULL ;
struct V_60 * V_61 = NULL ;
int V_21 = 0 ;
F_3 ( L_101 , V_33 -> V_16 , V_326 ) ;
switch ( V_326 ) {
case V_69 :
V_61 = F_49 ( V_59 ) ;
if ( ! V_61 )
return - V_175 ;
V_61 -> V_331 = 0 ;
case V_72 :
V_61 = F_49 ( V_59 ) ;
if ( ! V_61 )
return - V_175 ;
if ( V_61 -> V_70 == 1 ) {
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_61 -> V_73 = 0 ;
F_66 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_117 ) ;
if ( F_40 ( V_11 -> V_15 ) )
V_61 -> V_73 = V_63 ;
F_69 ( & V_11 -> V_117 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_332 :
case V_333 :
V_328 = (struct V_206 T_8 * ) V_59 -> V_334 ;
if ( F_229 ( & V_327 , V_328 , sizeof( V_206 ) ) )
return - V_335 ;
V_21 = F_160 ( V_33 , & V_327 ) ;
if ( V_21 == 0 &&
F_230 ( V_328 , & V_327 , sizeof( V_206 ) ) )
return - V_335 ;
return V_21 ;
case V_336 :
case V_337 :
V_330 = (struct V_210 T_8 * ) V_59 -> V_334 ;
if ( F_229 ( & V_329 , V_330 , sizeof( V_210 ) ) )
return - V_335 ;
V_21 = F_161 ( V_33 , & V_329 ) ;
if ( V_21 == 0 &&
F_230 ( V_330 , & V_329 , sizeof( V_210 ) ) )
return - V_335 ;
return V_21 ;
default:
break;
}
if ( ! F_231 ( V_338 ) )
return - V_168 ;
V_31 = F_232 ( F_178 ( V_33 ) , V_59 -> V_339 ) ;
F_3 ( L_102 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_103 , V_31 -> V_16 ) ;
switch ( V_326 ) {
case V_340 :
case V_341 :
V_21 = F_125 ( V_33 , V_31 ) ;
break;
case V_342 :
case V_343 :
V_21 = F_150 ( V_33 , V_31 ) ;
break;
case V_344 :
case V_345 :
V_21 = F_105 ( V_33 , V_31 ) ;
break;
case V_346 :
case V_347 :
V_21 = F_159 ( V_33 , V_31 ) ;
break;
default:
V_21 = - V_178 ;
}
F_233 ( V_31 ) ;
}
return V_21 ;
}
static bool F_234 ( unsigned char * V_77 ,
struct V_348 * V_349 ,
int V_350 )
{
struct V_87 * V_88 ;
F_235 (ha, list)
if ( ! memcmp ( V_88 -> V_77 , V_77 , V_350 ) )
return true ;
return false ;
}
static void F_236 ( struct V_30 * V_33 , int V_351 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
if ( V_351 & V_95 )
F_51 ( V_11 ,
V_33 -> V_94 & V_95 ? 1 : - 1 ) ;
if ( V_351 & V_96 )
F_54 ( V_11 ,
V_33 -> V_94 & V_96 ? 1 : - 1 ) ;
}
static void F_237 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_87 * V_88 ;
bool V_352 ;
F_66 ( & V_11 -> V_20 ) ;
F_73 (ha, bond_dev) {
V_352 = F_234 ( V_88 -> V_77 , & V_11 -> V_353 ,
V_33 -> V_133 ) ;
if ( ! V_352 )
F_56 ( V_11 , V_88 -> V_77 ) ;
}
F_235 (ha, &bond->mc_list) {
V_352 = F_234 ( V_88 -> V_77 , & V_33 -> V_354 ,
V_33 -> V_133 ) ;
if ( ! V_352 )
F_58 ( V_11 , V_88 -> V_77 ) ;
}
F_238 ( & V_11 -> V_353 ) ;
F_239 ( & V_11 -> V_353 , & V_33 -> V_354 ,
V_33 -> V_133 , V_355 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
static int F_240 ( struct V_30 * V_15 , struct V_356 * V_357 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
struct V_35 * V_35 = V_11 -> V_106 ;
if ( V_35 ) {
const struct V_55 * V_56
= V_35 -> V_15 -> V_57 ;
if ( V_56 -> V_358 )
return V_56 -> V_358 ( V_35 -> V_15 , V_357 ) ;
}
return 0 ;
}
static int F_241 ( struct V_30 * V_33 , int V_359 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_36 ;
int V_21 = 0 ;
int V_37 ;
F_3 ( L_104 , V_11 ,
( V_33 ? V_33 -> V_16 : L_10 ) , V_359 ) ;
F_29 (bond, slave, i) {
F_3 ( L_105 ,
V_35 ,
V_35 -> V_27 ,
V_35 -> V_15 -> V_57 -> V_360 ) ;
V_21 = F_133 ( V_35 -> V_15 , V_359 ) ;
if ( V_21 ) {
F_3 ( L_106 , V_21 , V_35 -> V_15 -> V_16 ) ;
goto V_38;
}
}
V_33 -> V_182 = V_359 ;
return 0 ;
V_38:
V_36 = V_35 ;
F_32 (bond, slave, i, bond->first_slave, stop_at) {
int V_361 ;
V_361 = F_133 ( V_35 -> V_15 , V_33 -> V_182 ) ;
if ( V_361 ) {
F_3 ( L_107 ,
V_361 , V_35 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_242 ( struct V_30 * V_33 , void * V_77 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_164 * V_362 = V_77 , V_363 ;
struct V_35 * V_35 , * V_36 ;
int V_21 = 0 ;
int V_37 ;
if ( V_11 -> V_41 . V_1 == V_9 )
return F_243 ( V_33 , V_77 ) ;
F_3 ( L_108 ,
V_11 , V_33 ? V_33 -> V_16 : L_10 ) ;
if ( V_11 -> V_41 . V_115 == V_177 )
return 0 ;
if ( ! F_244 ( V_362 -> V_185 ) )
return - V_364 ;
F_29 (bond, slave, i) {
const struct V_55 * V_56 = V_35 -> V_15 -> V_57 ;
F_3 ( L_109 , V_35 , V_35 -> V_15 -> V_16 ) ;
if ( V_56 -> V_176 == NULL ) {
V_21 = - V_178 ;
F_3 ( L_110 , V_35 -> V_15 -> V_16 ) ;
goto V_38;
}
V_21 = F_134 ( V_35 -> V_15 , V_77 ) ;
if ( V_21 ) {
F_3 ( L_106 , V_21 , V_35 -> V_15 -> V_16 ) ;
goto V_38;
}
}
memcpy ( V_33 -> V_134 , V_362 -> V_185 , V_33 -> V_133 ) ;
return 0 ;
V_38:
memcpy ( V_363 . V_185 , V_33 -> V_134 , V_33 -> V_133 ) ;
V_363 . V_186 = V_33 -> type ;
V_36 = V_35 ;
F_32 (bond, slave, i, bond->first_slave, stop_at) {
int V_361 ;
V_361 = F_134 ( V_35 -> V_15 , & V_363 ) ;
if ( V_361 ) {
F_3 ( L_107 ,
V_361 , V_35 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_245 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_365 ;
int V_37 , V_366 , V_21 = 1 ;
struct V_286 * V_287 = F_210 ( V_29 ) ;
if ( ( V_287 -> V_244 == V_367 ) &&
( V_29 -> V_244 == F_188 ( V_251 ) ) ) {
F_66 ( & V_11 -> V_117 ) ;
V_35 = V_11 -> V_76 ;
F_69 ( & V_11 -> V_117 ) ;
if ( ! V_35 )
goto V_23;
} else {
V_366 = V_11 -> V_368 ++ % V_11 -> V_39 ;
F_29 (bond, slave, i) {
V_366 -- ;
if ( V_366 < 0 )
break;
}
}
V_365 = V_35 ;
F_78 (bond, slave, i, start_at) {
if ( F_79 ( V_35 -> V_15 ) &&
( V_35 -> V_42 == V_43 ) &&
F_147 ( V_35 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_120 ( V_29 ) ;
}
return V_369 ;
}
static int F_246 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
int V_21 = 1 ;
F_66 ( & V_11 -> V_117 ) ;
if ( V_11 -> V_76 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_76 -> V_15 ) ;
if ( V_21 )
F_120 ( V_29 ) ;
F_69 ( & V_11 -> V_117 ) ;
return V_369 ;
}
static int F_247 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_365 ;
int V_366 ;
int V_37 ;
int V_21 = 1 ;
V_366 = V_11 -> V_370 ( V_29 , V_11 -> V_39 ) ;
F_29 (bond, slave, i) {
V_366 -- ;
if ( V_366 < 0 )
break;
}
V_365 = V_35 ;
F_78 (bond, slave, i, start_at) {
if ( F_79 ( V_35 -> V_15 ) &&
( V_35 -> V_42 == V_43 ) &&
F_147 ( V_35 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_120 ( V_29 ) ;
}
return V_369 ;
}
static int F_248 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_365 ;
struct V_30 * V_371 = NULL ;
int V_37 ;
int V_21 = 1 ;
F_66 ( & V_11 -> V_117 ) ;
V_365 = V_11 -> V_76 ;
F_69 ( & V_11 -> V_117 ) ;
if ( ! V_365 )
goto V_23;
F_78 (bond, slave, i, start_at) {
if ( F_79 ( V_35 -> V_15 ) &&
( V_35 -> V_42 == V_43 ) &&
F_147 ( V_35 ) ) {
if ( V_371 ) {
struct V_28 * V_372 = F_118 ( V_29 , V_153 ) ;
if ( ! V_372 ) {
F_31 ( L_111 ,
V_33 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_372 , V_371 ) ;
if ( V_21 ) {
F_120 ( V_372 ) ;
continue;
}
}
V_371 = V_35 -> V_15 ;
}
}
if ( V_371 )
V_21 = F_20 ( V_11 , V_29 , V_371 ) ;
V_23:
if ( V_21 )
F_120 ( V_29 ) ;
return V_369 ;
}
static void F_249 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_41 . V_373 ) {
case V_374 :
V_11 -> V_370 = F_209 ;
break;
case V_375 :
V_11 -> V_370 = F_212 ;
break;
case V_376 :
default:
V_11 -> V_370 = F_215 ;
break;
}
}
static inline int F_250 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_37 , V_21 = 1 ;
struct V_35 * V_35 = NULL ;
struct V_35 * V_377 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_29 (bond, check_slave, i) {
if ( V_377 -> V_180 == V_29 -> V_32 ) {
V_35 = V_377 ;
break;
}
}
if ( V_35 && V_35 -> V_180 && F_79 ( V_35 -> V_15 ) &&
( V_35 -> V_42 == V_43 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
}
return V_21 ;
}
static T_9 F_251 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_9 V_378 = F_252 ( V_29 ) ? F_253 ( V_29 ) : 0 ;
F_21 ( V_29 ) = V_29 -> V_32 ;
if ( F_22 ( V_378 >= V_15 -> V_379 ) ) {
do {
V_378 -= V_15 -> V_379 ;
} while ( V_378 >= V_15 -> V_379 );
}
return V_378 ;
}
static T_10 F_254 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
if ( F_255 ( V_11 -> V_41 . V_1 ) ) {
if ( ! F_250 ( V_11 , V_29 ) )
return V_369 ;
}
switch ( V_11 -> V_41 . V_1 ) {
case V_3 :
return F_245 ( V_29 , V_15 ) ;
case V_4 :
return F_246 ( V_29 , V_15 ) ;
case V_5 :
return F_247 ( V_29 , V_15 ) ;
case V_6 :
return F_248 ( V_29 , V_15 ) ;
case V_7 :
return F_256 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_257 ( V_29 , V_15 ) ;
default:
F_31 ( L_112 ,
V_15 -> V_16 , V_11 -> V_41 . V_1 ) ;
F_258 ( 1 ) ;
F_120 ( V_29 ) ;
return V_369 ;
}
}
static T_10 F_259 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_10 V_205 = V_369 ;
if ( F_260 ( V_15 ) )
return V_380 ;
F_66 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_39 )
V_205 = F_254 ( V_29 , V_15 ) ;
else
F_120 ( V_29 ) ;
F_69 ( & V_11 -> V_20 ) ;
return V_205 ;
}
void F_261 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_33 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_249 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_249 ( V_11 ) ;
break;
case V_9 :
case V_8 :
break;
default:
F_31 ( L_112 ,
V_33 -> V_16 , V_1 ) ;
break;
}
}
static void F_262 ( struct V_30 * V_33 ,
struct V_381 * V_382 )
{
strncpy ( V_382 -> V_383 , V_384 , 32 ) ;
strncpy ( V_382 -> V_385 , V_386 , 32 ) ;
snprintf ( V_382 -> V_387 , 32 , L_113 , V_388 ) ;
}
static void F_263 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
if ( V_11 -> V_82 )
F_264 ( V_11 -> V_82 ) ;
F_265 ( V_33 ) ;
}
static void F_266 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
F_267 ( & V_11 -> V_20 ) ;
F_267 ( & V_11 -> V_117 ) ;
V_11 -> V_41 = V_389 ;
V_11 -> V_15 = V_33 ;
F_5 ( & V_11 -> V_19 ) ;
F_130 ( V_33 ) ;
V_33 -> V_57 = & V_390 ;
V_33 -> V_64 = & V_391 ;
F_261 ( V_11 , V_11 -> V_41 . V_1 ) ;
V_33 -> V_392 = F_263 ;
V_33 -> V_393 = 0 ;
V_33 -> V_94 |= V_273 | V_394 ;
V_33 -> V_127 |= V_190 ;
V_33 -> V_127 &= ~ ( V_395 | V_173 ) ;
V_33 -> V_135 |= V_137 ;
V_33 -> V_135 |= V_396 ;
V_33 -> V_397 = V_141 |
V_398 |
V_399 |
V_400 ;
V_33 -> V_397 &= ~ ( V_401 & ~ V_402 ) ;
V_33 -> V_135 |= V_33 -> V_397 ;
}
static void F_268 ( struct V_10 * V_11 )
{
if ( V_11 -> V_41 . V_113 && F_222 ( & V_11 -> V_222 ) )
F_221 ( & V_11 -> V_222 ) ;
if ( V_11 -> V_41 . V_155 && F_222 ( & V_11 -> V_254 ) )
F_221 ( & V_11 -> V_254 ) ;
if ( V_11 -> V_41 . V_1 == V_9 &&
F_222 ( & V_11 -> V_296 ) )
F_221 ( & V_11 -> V_296 ) ;
if ( V_11 -> V_41 . V_1 == V_7 &&
F_222 ( & V_11 -> V_298 ) )
F_221 ( & V_11 -> V_298 ) ;
if ( F_222 ( & V_11 -> V_83 ) )
F_221 ( & V_11 -> V_83 ) ;
}
static void F_269 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_13 * V_14 , * V_403 ;
F_102 ( V_33 ) ;
F_158 ( V_33 ) ;
F_12 ( & V_11 -> V_404 ) ;
F_268 ( V_11 ) ;
F_199 ( V_11 ) ;
F_270 ( V_11 ) ;
F_238 ( & V_11 -> V_353 ) ;
F_271 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_272 ( const char * V_405 , const struct V_406 * V_407 )
{
int V_408 = - 1 , V_37 , V_122 ;
char * V_409 , V_410 [ V_411 + 1 ] = { 0 , } ;
for ( V_409 = ( char * ) V_405 ; * V_409 ; V_409 ++ )
if ( ! ( isdigit ( * V_409 ) || isspace ( * V_409 ) ) )
break;
if ( * V_409 )
V_122 = sscanf ( V_405 , L_114 , V_410 ) ;
else
V_122 = sscanf ( V_405 , L_113 , & V_408 ) ;
if ( ! V_122 )
return - 1 ;
for ( V_37 = 0 ; V_407 [ V_37 ] . V_412 ; V_37 ++ ) {
if ( V_408 == V_407 [ V_37 ] . V_1 )
return V_407 [ V_37 ] . V_1 ;
if ( strcmp ( V_410 , V_407 [ V_37 ] . V_412 ) == 0 )
return V_407 [ V_37 ] . V_1 ;
}
return - 1 ;
}
static int F_273 ( struct V_413 * V_41 )
{
int V_414 , V_415 , V_416 ;
if ( V_1 ) {
V_208 = F_272 ( V_1 , V_417 ) ;
if ( V_208 == - 1 ) {
F_31 ( L_115 ,
V_1 == NULL ? L_18 : V_1 ) ;
return - V_175 ;
}
}
if ( V_370 ) {
if ( ( V_208 != V_5 ) &&
( V_208 != V_7 ) ) {
F_83 ( L_116 ,
F_1 ( V_208 ) ) ;
} else {
V_418 = F_272 ( V_370 ,
V_419 ) ;
if ( V_418 == - 1 ) {
F_31 ( L_117 ,
V_370 == NULL ? L_18 :
V_370 ) ;
return - V_175 ;
}
}
}
if ( V_420 ) {
if ( V_208 != V_7 ) {
F_83 ( L_118 ,
F_1 ( V_208 ) ) ;
} else {
V_421 = F_272 ( V_420 , V_422 ) ;
if ( V_421 == - 1 ) {
F_31 ( L_119 ,
V_420 == NULL ? L_18 : V_420 ) ;
return - V_175 ;
}
}
}
if ( V_423 ) {
V_41 -> V_423 = F_272 ( V_423 , V_424 ) ;
if ( V_41 -> V_423 == - 1 ) {
F_31 ( L_120 ,
V_423 == NULL ? L_18 : V_423 ) ;
return - V_175 ;
}
if ( V_208 != V_7 ) {
F_36 ( L_121 ) ;
}
} else {
V_41 -> V_423 = V_425 ;
}
if ( V_426 < 0 ) {
F_36 ( L_122 ,
V_426 , 0 , V_427 , V_428 ) ;
V_426 = V_428 ;
}
if ( V_113 < 0 ) {
F_36 ( L_123 ,
V_113 , V_427 , V_429 ) ;
V_113 = V_429 ;
}
if ( V_105 < 0 ) {
F_36 ( L_124 ,
V_105 , V_427 ) ;
V_105 = 0 ;
}
if ( V_219 < 0 ) {
F_36 ( L_125 ,
V_219 , V_427 ) ;
V_219 = 0 ;
}
if ( ( V_62 != 0 ) && ( V_62 != 1 ) ) {
F_36 ( L_126 ,
V_62 ) ;
V_62 = 1 ;
}
if ( V_116 < 0 || V_116 > 255 ) {
F_36 ( L_127 ,
V_116 ) ;
V_116 = 1 ;
}
if ( V_208 == V_7 ) {
if ( ! V_113 ) {
F_36 ( L_128 ) ;
F_36 ( L_129 ) ;
V_113 = 100 ;
}
}
if ( V_430 < 1 || V_430 > 255 ) {
F_36 ( L_130
L_131 ,
V_430 , V_431 ) ;
V_430 = V_431 ;
}
if ( ( V_432 != 0 ) && ( V_432 != 1 ) ) {
F_36 ( L_132
L_133
L_134 , V_432 ) ;
V_432 = 0 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_36 ( L_135
L_136 ,
V_120 , V_433 ) ;
V_120 = V_433 ;
}
if ( ( V_208 == V_8 ) ||
( V_208 == V_9 ) ) {
if ( ! V_113 ) {
F_36 ( L_137 ) ;
F_36 ( L_129 ) ;
V_113 = 100 ;
}
}
if ( V_208 == V_9 ) {
F_274 ( L_138 ,
V_105 ) ;
}
if ( ! V_113 ) {
if ( V_105 || V_219 ) {
F_36 ( L_139 ,
V_105 , V_219 ) ;
}
} else {
if ( V_155 ) {
F_36 ( L_140 ,
V_113 , V_155 ) ;
V_155 = 0 ;
}
if ( ( V_105 % V_113 ) != 0 ) {
F_36 ( L_141 ,
V_105 , V_113 ,
( V_105 / V_113 ) * V_113 ) ;
}
V_105 /= V_113 ;
if ( ( V_219 % V_113 ) != 0 ) {
F_36 ( L_142 ,
V_219 , V_113 ,
( V_219 / V_113 ) * V_113 ) ;
}
V_219 /= V_113 ;
}
if ( V_155 < 0 ) {
F_36 ( L_143 ,
V_155 , V_427 , V_434 ) ;
V_155 = V_434 ;
}
for ( V_435 = 0 ;
( V_435 < V_235 ) && V_436 [ V_435 ] ;
V_435 ++ ) {
if ( ! isdigit ( V_436 [ V_435 ] [ 0 ] ) ) {
F_36 ( L_144 ,
V_436 [ V_435 ] ) ;
V_155 = 0 ;
} else {
T_6 V_224 = F_275 ( V_436 [ V_435 ] ) ;
V_437 [ V_435 ] = V_224 ;
}
}
if ( V_155 && ! V_435 ) {
F_36 ( L_145 ,
V_155 ) ;
V_155 = 0 ;
}
if ( V_253 ) {
if ( V_208 != V_4 ) {
F_31 ( L_146 ) ;
return - V_175 ;
}
if ( ! V_155 ) {
F_31 ( L_147 ) ;
return - V_175 ;
}
V_414 = F_272 ( V_253 ,
V_438 ) ;
if ( V_414 == - 1 ) {
F_31 ( L_148 ,
V_253 == NULL ? L_18 : V_253 ) ;
return - V_175 ;
}
} else
V_414 = 0 ;
if ( V_113 ) {
F_83 ( L_149 , V_113 ) ;
} else if ( V_155 ) {
int V_37 ;
F_83 ( L_150 ,
V_155 ,
V_438 [ V_414 ] . V_412 ,
V_435 ) ;
for ( V_37 = 0 ; V_37 < V_435 ; V_37 ++ )
F_83 ( L_151 , V_436 [ V_37 ] ) ;
F_83 ( L_152 ) ;
} else if ( V_426 ) {
F_3 ( L_153 ) ;
}
if ( V_195 && ! F_52 ( V_208 ) ) {
F_36 ( L_154 ,
V_195 , F_1 ( V_208 ) ) ;
V_195 = NULL ;
}
if ( V_195 && V_100 ) {
V_416 = F_272 ( V_100 ,
V_439 ) ;
if ( V_416 == - 1 ) {
F_31 ( L_155 ,
V_100 ==
NULL ? L_18 : V_100 ) ;
return - V_175 ;
}
} else {
V_416 = V_440 ;
}
if ( V_115 ) {
V_415 = F_272 ( V_115 ,
V_441 ) ;
if ( V_415 == - 1 ) {
F_31 ( L_156 ,
V_253 == NULL ? L_18 : V_253 ) ;
return - V_175 ;
}
if ( V_208 != V_4 )
F_36 ( L_157 ) ;
} else {
V_415 = V_442 ;
}
V_41 -> V_1 = V_208 ;
V_41 -> V_373 = V_418 ;
V_41 -> V_113 = V_113 ;
V_41 -> V_116 = V_116 ;
V_41 -> V_155 = V_155 ;
V_41 -> V_253 = V_414 ;
V_41 -> V_105 = V_105 ;
V_41 -> V_219 = V_219 ;
V_41 -> V_62 = V_62 ;
V_41 -> V_421 = V_421 ;
V_41 -> V_195 [ 0 ] = 0 ;
V_41 -> V_100 = V_416 ;
V_41 -> V_115 = V_415 ;
V_41 -> V_430 = V_430 ;
V_41 -> V_432 = V_432 ;
V_41 -> V_120 = V_120 ;
V_41 -> V_443 = V_443 ;
if ( V_195 ) {
strncpy ( V_41 -> V_195 , V_195 , V_68 ) ;
V_41 -> V_195 [ V_68 - 1 ] = 0 ;
}
memcpy ( V_41 -> V_232 , V_437 , sizeof( V_437 ) ) ;
return 0 ;
}
static void F_276 ( struct V_30 * V_15 ,
struct V_444 * V_378 ,
void * V_445 )
{
F_277 ( & V_378 -> V_446 ,
& V_447 ) ;
}
static void F_278 ( struct V_30 * V_15 )
{
F_277 ( & V_15 -> V_448 ,
& V_449 ) ;
F_279 ( V_15 , F_276 , NULL ) ;
}
static int F_280 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_277 * V_278 = F_208 ( F_178 ( V_33 ) , V_279 ) ;
struct V_450 * V_451 = & ( F_281 ( V_11 ) ) ;
F_3 ( L_158 , V_33 -> V_16 ) ;
F_282 ( & ( V_451 -> V_452 ) ) ;
F_282 ( & ( V_451 -> V_453 ) ) ;
V_11 -> V_82 = F_283 ( V_33 -> V_16 ) ;
if ( ! V_11 -> V_82 )
return - V_18 ;
F_278 ( V_33 ) ;
F_200 ( V_11 ) ;
F_7 ( & V_11 -> V_404 , & V_278 -> V_454 ) ;
F_284 ( V_11 ) ;
F_285 ( V_11 ) ;
F_286 ( & V_11 -> V_353 ) ;
return 0 ;
}
static int F_287 ( struct V_455 * V_456 [] , struct V_455 * V_161 [] )
{
if ( V_456 [ V_457 ] ) {
if ( F_288 ( V_456 [ V_457 ] ) != V_90 )
return - V_175 ;
if ( ! F_244 ( F_289 ( V_456 [ V_457 ] ) ) )
return - V_364 ;
}
return 0 ;
}
static int F_290 ( struct V_458 * V_458 , struct V_455 * V_456 [] ,
unsigned int * V_459 ,
unsigned int * V_460 )
{
* V_459 = V_430 ;
return 0 ;
}
int F_291 ( struct V_458 * V_458 , const char * V_16 )
{
struct V_30 * V_33 ;
int V_21 ;
F_292 () ;
V_33 = F_293 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_159 ,
F_266 , V_430 ) ;
if ( ! V_33 ) {
F_31 ( L_160 , V_16 ) ;
F_170 () ;
return - V_18 ;
}
F_294 ( V_33 , V_458 ) ;
V_33 -> V_461 = & V_462 ;
V_21 = F_295 ( V_33 ) ;
F_42 ( V_33 ) ;
F_170 () ;
if ( V_21 < 0 )
F_263 ( V_33 ) ;
return V_21 ;
}
static int T_11 F_296 ( struct V_458 * V_458 )
{
struct V_277 * V_278 = F_208 ( V_458 , V_279 ) ;
V_278 -> V_458 = V_458 ;
F_5 ( & V_278 -> V_454 ) ;
F_297 ( V_278 ) ;
F_298 ( V_278 ) ;
return 0 ;
}
static void T_12 F_299 ( struct V_458 * V_458 )
{
struct V_277 * V_278 = F_208 ( V_458 , V_279 ) ;
F_300 ( V_278 ) ;
F_301 ( V_278 ) ;
}
static int T_13 F_302 ( void )
{
int V_37 ;
int V_21 ;
F_83 ( L_161 , V_463 ) ;
V_21 = F_273 ( & V_389 ) ;
if ( V_21 )
goto V_23;
V_21 = F_303 ( & V_464 ) ;
if ( V_21 )
goto V_23;
V_21 = F_304 ( & V_462 ) ;
if ( V_21 )
goto V_465;
F_305 () ;
for ( V_37 = 0 ; V_37 < V_426 ; V_37 ++ ) {
V_21 = F_291 ( & V_466 , NULL ) ;
if ( V_21 )
goto V_75;
}
F_306 ( & V_467 ) ;
F_307 ( & V_468 ) ;
V_23:
return V_21 ;
V_75:
F_308 ( & V_462 ) ;
V_465:
F_309 ( & V_464 ) ;
goto V_23;
}
static void T_14 F_310 ( void )
{
F_311 ( & V_467 ) ;
F_312 ( & V_468 ) ;
F_313 () ;
F_308 ( & V_462 ) ;
F_309 ( & V_464 ) ;
#ifdef F_144
F_314 ( F_315 ( & V_469 ) ) ;
#endif
}
