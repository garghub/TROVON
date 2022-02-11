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
F_21 ( sizeof( V_29 -> V_32 ) !=
sizeof( F_22 ( V_29 ) -> V_33 ) ) ;
V_29 -> V_32 = F_22 ( V_29 ) -> V_33 ;
if ( F_23 ( F_24 ( V_11 -> V_15 ) ) )
F_25 ( F_26 ( V_11 , V_31 ) , V_29 ) ;
else
F_27 ( V_29 ) ;
return 0 ;
}
static int F_28 ( struct V_30 * V_34 , T_1 V_35 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_37 ;
int V_38 , V_21 ;
F_30 (bond, slave, i) {
V_21 = F_31 ( V_36 -> V_15 , V_35 ) ;
if ( V_21 )
goto V_39;
}
V_21 = F_2 ( V_11 , V_35 ) ;
if ( V_21 ) {
F_32 ( L_14 ,
V_34 -> V_16 , V_35 ) ;
return V_21 ;
}
return 0 ;
V_39:
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at)
F_34 ( V_36 -> V_15 , V_35 ) ;
return V_21 ;
}
static int F_35 ( struct V_30 * V_34 , T_1 V_35 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
int V_38 , V_21 ;
F_30 (bond, slave, i)
F_34 ( V_36 -> V_15 , V_35 ) ;
V_21 = F_9 ( V_11 , V_35 ) ;
if ( V_21 ) {
F_32 ( L_15 ,
V_34 -> V_16 , V_35 ) ;
return V_21 ;
}
return 0 ;
}
static void F_36 ( struct V_10 * V_11 , struct V_30 * V_31 )
{
struct V_13 * V_14 ;
int V_21 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_21 = F_31 ( V_31 , V_14 -> V_12 ) ;
if ( V_21 )
F_37 ( L_16 ,
V_11 -> V_15 -> V_16 , V_14 -> V_12 ,
V_31 -> V_16 ) ;
}
}
static void F_38 ( struct V_10 * V_11 ,
struct V_30 * V_31 )
{
struct V_13 * V_14 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( ! V_14 -> V_12 )
continue;
F_34 ( V_31 , V_14 -> V_12 ) ;
}
}
static int F_39 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
if ( V_11 -> V_40 == 0 )
goto V_41;
if ( V_11 -> V_42 . V_1 == V_7 )
return F_40 ( V_11 ) ;
F_30 (bond, slave, i) {
if ( V_36 -> V_43 == V_44 ) {
if ( ! F_41 ( V_11 -> V_15 ) ) {
F_42 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
}
V_41:
if ( F_41 ( V_11 -> V_15 ) ) {
F_43 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
static void F_44 ( struct V_36 * V_36 )
{
struct V_30 * V_31 = V_36 -> V_15 ;
struct V_45 V_46 ;
T_2 V_47 ;
int V_21 ;
V_36 -> V_48 = V_49 ;
V_36 -> V_50 = V_51 ;
V_21 = F_45 ( V_31 , & V_46 ) ;
if ( V_21 < 0 )
return;
V_47 = F_46 ( & V_46 ) ;
if ( V_47 == 0 || V_47 == ( ( V_52 ) - 1 ) )
return;
switch ( V_46 . V_50 ) {
case V_53 :
case V_54 :
break;
default:
return;
}
V_36 -> V_48 = V_47 ;
V_36 -> V_50 = V_46 . V_50 ;
return;
}
static int F_47 ( struct V_10 * V_11 ,
struct V_30 * V_31 , int V_55 )
{
const struct V_56 * V_57 = V_31 -> V_58 ;
int (* F_48)( struct V_30 * , struct V_59 * , int );
struct V_59 V_60 ;
struct V_61 * V_62 ;
if ( ! V_55 && ! F_49 ( V_31 ) )
return 0 ;
if ( V_11 -> V_42 . V_63 )
return F_41 ( V_31 ) ? V_64 : 0 ;
if ( V_31 -> V_65 -> V_66 )
return V_31 -> V_65 -> V_66 ( V_31 ) ?
V_64 : 0 ;
F_48 = V_57 -> V_67 ;
if ( F_48 ) {
strncpy ( V_60 . V_68 , V_31 -> V_16 , V_69 ) ;
V_62 = F_50 ( & V_60 ) ;
if ( F_51 ( V_31 , & V_60 , V_70 ) == 0 ) {
V_62 -> V_71 = V_72 ;
if ( F_51 ( V_31 , & V_60 , V_73 ) == 0 )
return V_62 -> V_74 & V_64 ;
}
}
return V_55 ? - 1 : V_64 ;
}
static int F_52 ( struct V_10 * V_11 , int V_75 )
{
int V_76 = 0 ;
if ( F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_11 -> V_77 ) {
V_76 = F_54 ( V_11 -> V_77 -> V_15 ,
V_75 ) ;
}
} else {
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i) {
V_76 = F_54 ( V_36 -> V_15 , V_75 ) ;
if ( V_76 )
return V_76 ;
}
}
return V_76 ;
}
static int F_55 ( struct V_10 * V_11 , int V_75 )
{
int V_76 = 0 ;
if ( F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_11 -> V_77 ) {
V_76 = F_56 ( V_11 -> V_77 -> V_15 ,
V_75 ) ;
}
} else {
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i) {
V_76 = F_56 ( V_36 -> V_15 , V_75 ) ;
if ( V_76 )
return V_76 ;
}
}
return V_76 ;
}
static void F_57 ( struct V_10 * V_11 , void * V_78 )
{
if ( F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_11 -> V_77 )
F_58 ( V_11 -> V_77 -> V_15 , V_78 ) ;
} else {
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i)
F_58 ( V_36 -> V_15 , V_78 ) ;
}
}
static void F_59 ( struct V_10 * V_11 , void * V_78 )
{
if ( F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_11 -> V_77 )
F_60 ( V_11 -> V_77 -> V_15 , V_78 ) ;
} else {
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i) {
F_60 ( V_36 -> V_15 , V_78 ) ;
}
}
}
static void F_61 ( struct V_30 * V_15 )
{
struct V_79 * V_80 ;
V_80 = F_62 ( V_15 ) ;
if ( V_80 )
F_63 ( V_80 ) ;
}
static void F_64 ( struct V_10 * V_11 )
{
struct V_30 * V_34 , * V_81 , * V_82 ;
struct V_13 * V_14 ;
F_65 () ;
F_66 ( & V_11 -> V_20 ) ;
V_34 = V_11 -> V_15 ;
F_61 ( V_34 ) ;
V_82 = F_67 ( V_34 ) ;
if ( V_82 && V_82 -> V_83 & V_84 )
F_61 ( V_82 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_81 = F_68 ( V_34 ,
V_14 -> V_12 ) ;
if ( V_81 )
F_61 ( V_81 ) ;
}
if ( -- V_11 -> V_85 > 0 )
F_69 ( V_11 -> V_86 , & V_11 -> V_87 , V_88 / 5 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_71 () ;
}
static void F_72 ( struct V_89 * V_90 )
{
struct V_10 * V_11 = F_73 ( V_90 , struct V_10 ,
V_87 . V_90 ) ;
F_65 () ;
F_64 ( V_11 ) ;
F_71 () ;
}
static void F_74 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_91 * V_92 ;
F_75 (ha, bond_dev)
F_60 ( V_31 , V_92 -> V_78 ) ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
T_3 V_93 [ V_94 ] = V_95 ;
F_60 ( V_31 , V_93 ) ;
}
}
static void F_76 ( struct V_10 * V_11 , struct V_36 * V_96 ,
struct V_36 * V_97 )
{
struct V_91 * V_92 ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) )
return;
if ( V_97 ) {
if ( V_11 -> V_15 -> V_98 & V_99 )
F_54 ( V_97 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_98 & V_100 )
F_56 ( V_97 -> V_15 , - 1 ) ;
F_77 ( V_11 -> V_15 ) ;
F_75 (ha, bond->dev)
F_60 ( V_97 -> V_15 , V_92 -> V_78 ) ;
F_78 ( V_11 -> V_15 ) ;
}
if ( V_96 ) {
if ( V_11 -> V_15 -> V_98 & V_99 )
F_54 ( V_96 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_98 & V_100 )
F_56 ( V_96 -> V_15 , 1 ) ;
F_77 ( V_11 -> V_15 ) ;
F_75 (ha, bond->dev)
F_58 ( V_96 -> V_15 , V_92 -> V_78 ) ;
F_78 ( V_11 -> V_15 ) ;
}
}
static void F_79 ( struct V_10 * V_11 ,
struct V_36 * V_96 ,
struct V_36 * V_97 )
__releases( &bond->curr_slave_lock
static bool F_80 ( struct V_10 * V_11 )
{
struct V_36 * V_101 = V_11 -> V_102 ;
struct V_36 * V_24 = V_11 -> V_77 ;
if ( ! V_101 || ! V_24 || V_24 -> V_43 != V_44 )
return true ;
if ( V_11 -> V_103 ) {
V_11 -> V_103 = false ;
return true ;
}
if ( V_11 -> V_42 . V_104 == V_105 &&
( V_101 -> V_48 < V_24 -> V_48 ||
( V_101 -> V_48 == V_24 -> V_48 && V_101 -> V_50 <= V_24 -> V_50 ) ) )
return false ;
if ( V_11 -> V_42 . V_104 == V_106 )
return false ;
return true ;
}
static struct V_36 * F_81 ( struct V_10 * V_11 )
{
struct V_36 * V_96 , * V_97 ;
struct V_36 * V_107 = NULL ;
int V_108 = V_11 -> V_42 . V_109 ;
int V_38 ;
V_96 = V_11 -> V_77 ;
if ( ! V_96 ) {
if ( V_11 -> V_40 > 0 )
V_96 = V_11 -> V_110 ;
else
return NULL ;
}
if ( ( V_11 -> V_102 ) &&
V_11 -> V_102 -> V_43 == V_44 &&
F_80 ( V_11 ) ) {
V_96 = V_11 -> V_102 ;
}
V_97 = V_96 ;
F_82 (bond, new_active, i, old_active) {
if ( V_96 -> V_43 == V_44 ) {
return V_96 ;
} else if ( V_96 -> V_43 == V_111 &&
F_83 ( V_96 -> V_15 ) ) {
if ( V_96 -> V_112 < V_108 ) {
V_108 = V_96 -> V_112 ;
V_107 = V_96 ;
}
}
}
return V_107 ;
}
static bool F_84 ( struct V_10 * V_11 )
{
struct V_36 * V_36 = V_11 -> V_77 ;
F_3 ( L_17 ,
V_11 -> V_15 -> V_16 , V_36 ? V_36 -> V_15 -> V_16 : L_18 ) ;
if ( ! V_36 || ! V_11 -> V_113 ||
F_85 ( V_114 , & V_36 -> V_15 -> V_115 ) )
return false ;
V_11 -> V_113 -- ;
return true ;
}
void F_86 ( struct V_10 * V_11 , struct V_36 * V_96 )
{
struct V_36 * V_97 = V_11 -> V_77 ;
if ( V_97 == V_96 )
return;
if ( V_96 ) {
V_96 -> V_116 = V_116 ;
if ( V_96 -> V_43 == V_111 ) {
if ( F_53 ( V_11 -> V_42 . V_1 ) ) {
F_87 ( L_19 ,
V_11 -> V_15 -> V_16 , V_96 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_109 - V_96 -> V_112 ) * V_11 -> V_42 . V_117 ) ;
}
V_96 -> V_112 = 0 ;
V_96 -> V_43 = V_44 ;
if ( V_11 -> V_42 . V_1 == V_7 )
F_88 ( V_96 , V_44 ) ;
if ( F_13 ( V_11 ) )
F_89 ( V_11 , V_96 , V_44 ) ;
} else {
if ( F_53 ( V_11 -> V_42 . V_1 ) ) {
F_87 ( L_20 ,
V_11 -> V_15 -> V_16 , V_96 -> V_15 -> V_16 ) ;
}
}
}
if ( F_53 ( V_11 -> V_42 . V_1 ) )
F_76 ( V_11 , V_96 , V_97 ) ;
if ( F_13 ( V_11 ) ) {
F_90 ( V_11 , V_96 ) ;
if ( V_97 )
F_91 ( V_97 ) ;
if ( V_96 )
F_92 ( V_96 ) ;
} else {
V_11 -> V_77 = V_96 ;
}
if ( V_11 -> V_42 . V_1 == V_4 ) {
if ( V_97 )
F_91 ( V_97 ) ;
if ( V_96 ) {
bool V_118 = false ;
F_92 ( V_96 ) ;
if ( V_11 -> V_42 . V_119 )
F_79 ( V_11 , V_96 ,
V_97 ) ;
if ( F_49 ( V_11 -> V_15 ) ) {
V_11 -> V_113 =
V_11 -> V_42 . V_120 ;
V_118 =
F_84 ( V_11 ) ;
}
F_8 ( & V_11 -> V_121 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_93 ( V_122 , V_11 -> V_15 ) ;
if ( V_118 )
F_93 ( V_123 ,
V_11 -> V_15 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_121 ) ;
}
}
if ( F_49 ( V_11 -> V_15 ) && ( V_11 -> V_42 . V_124 > 0 ) &&
( ( F_53 ( V_11 -> V_42 . V_1 ) && V_96 ) ||
V_11 -> V_42 . V_1 == V_3 ) ) {
V_11 -> V_85 = V_11 -> V_42 . V_124 ;
F_69 ( V_11 -> V_86 , & V_11 -> V_87 , 0 ) ;
}
}
void F_94 ( struct V_10 * V_11 )
{
struct V_36 * V_125 ;
int V_126 ;
V_125 = F_81 ( V_11 ) ;
if ( V_125 != V_11 -> V_77 ) {
F_86 ( V_11 , V_125 ) ;
V_126 = F_39 ( V_11 ) ;
if ( ! V_126 )
return;
if ( F_41 ( V_11 -> V_15 ) ) {
F_87 ( L_21 ,
V_11 -> V_15 -> V_16 ) ;
} else {
F_87 ( L_22 ,
V_11 -> V_15 -> V_16 ) ;
}
}
}
static void F_95 ( struct V_10 * V_11 , struct V_36 * V_127 )
{
if ( V_11 -> V_110 == NULL ) {
V_127 -> V_25 = V_127 ;
V_127 -> V_27 = V_127 ;
V_11 -> V_110 = V_127 ;
} else {
V_127 -> V_25 = V_11 -> V_110 ;
V_127 -> V_27 = V_11 -> V_110 -> V_27 ;
V_127 -> V_25 -> V_27 = V_127 ;
V_127 -> V_27 -> V_25 = V_127 ;
}
V_11 -> V_40 ++ ;
}
static void F_96 ( struct V_10 * V_11 , struct V_36 * V_36 )
{
if ( V_36 -> V_25 )
V_36 -> V_25 -> V_27 = V_36 -> V_27 ;
if ( V_36 -> V_27 )
V_36 -> V_27 -> V_25 = V_36 -> V_25 ;
if ( V_11 -> V_110 == V_36 ) {
if ( V_11 -> V_40 > 1 ) {
V_11 -> V_110 = V_36 -> V_25 ;
} else {
V_11 -> V_110 = NULL ;
}
}
V_36 -> V_25 = NULL ;
V_36 -> V_27 = NULL ;
V_11 -> V_40 -- ;
}
static inline int F_97 ( struct V_36 * V_36 )
{
struct V_128 * V_129 ;
int V_76 = 0 ;
V_129 = F_4 ( sizeof( * V_129 ) , V_130 ) ;
V_76 = - V_18 ;
if ( ! V_129 )
goto V_23;
V_76 = F_98 ( V_129 , V_36 -> V_15 , V_130 ) ;
if ( V_76 ) {
F_15 ( V_129 ) ;
goto V_23;
}
V_36 -> V_129 = V_129 ;
V_23:
return V_76 ;
}
static inline void F_99 ( struct V_36 * V_36 )
{
struct V_128 * V_129 = V_36 -> V_129 ;
if ( ! V_129 )
return;
V_36 -> V_129 = NULL ;
F_100 ( V_129 ) ;
}
static inline bool F_101 ( struct V_30 * V_31 )
{
if ( V_31 -> V_83 & V_131 )
return false ;
if ( ! V_31 -> V_58 -> V_132 )
return false ;
return true ;
}
static void F_102 ( struct V_30 * V_34 )
{
}
static void F_103 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i)
if ( F_83 ( V_36 -> V_15 ) )
F_99 ( V_36 ) ;
}
static void F_104 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_103 ( V_11 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_105 ( struct V_30 * V_15 , struct V_133 * V_134 , T_4 V_135 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
struct V_36 * V_36 ;
int V_38 , V_76 = 0 ;
F_66 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
V_76 = F_97 ( V_36 ) ;
if ( V_76 ) {
F_103 ( V_11 ) ;
break;
}
}
F_70 ( & V_11 -> V_20 ) ;
return V_76 ;
}
static struct V_133 * F_106 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_136 ;
}
static inline int F_97 ( struct V_36 * V_36 )
{
return 0 ;
}
static inline void F_99 ( struct V_36 * V_36 )
{
}
static void F_104 ( struct V_30 * V_34 )
{
}
static void F_107 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_3 ( L_23 , V_34 ) ;
F_3 ( L_24 , V_31 ) ;
F_3 ( L_25 , V_31 -> V_137 ) ;
memcpy ( V_34 -> V_138 , V_31 -> V_138 , V_31 -> V_137 ) ;
V_34 -> V_139 = V_140 ;
F_93 ( V_141 , V_34 ) ;
}
static T_5 F_108 ( struct V_30 * V_15 ,
T_5 V_142 )
{
struct V_36 * V_36 ;
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_5 V_143 ;
int V_38 ;
F_66 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_110 ) {
V_142 |= V_144 ;
goto V_23;
}
V_143 = V_142 ;
V_142 &= ~ V_145 ;
V_142 |= V_146 ;
F_30 (bond, slave, i) {
V_142 = F_109 ( V_142 ,
V_36 -> V_15 -> V_142 ,
V_143 ) ;
}
V_23:
F_70 ( & V_11 -> V_20 ) ;
return V_142 ;
}
static void F_110 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
struct V_30 * V_34 = V_11 -> V_15 ;
T_5 V_147 = V_148 ;
unsigned short V_149 = V_150 ;
unsigned int V_151 = V_152 ;
T_6 V_153 = V_154 ;
int V_38 ;
unsigned int V_98 , V_155 = V_156 ;
F_66 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_110 )
goto V_157;
F_30 (bond, slave, i) {
V_147 = F_109 ( V_147 ,
V_36 -> V_15 -> V_147 , V_148 ) ;
V_155 &= V_36 -> V_15 -> V_83 ;
if ( V_36 -> V_15 -> V_158 > V_149 )
V_149 = V_36 -> V_15 -> V_158 ;
V_151 = F_111 ( V_151 , V_36 -> V_15 -> V_151 ) ;
V_153 = F_111 ( V_153 , V_36 -> V_15 -> V_153 ) ;
}
V_157:
V_34 -> V_147 = V_147 ;
V_34 -> V_158 = V_149 ;
V_34 -> V_153 = V_153 ;
F_112 ( V_34 , V_151 ) ;
V_98 = V_34 -> V_83 & ~ V_156 ;
V_34 -> V_83 = V_98 | V_155 ;
F_70 ( & V_11 -> V_20 ) ;
F_113 ( V_34 ) ;
}
static void F_114 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_34 -> V_159 = V_31 -> V_159 ;
V_34 -> type = V_31 -> type ;
V_34 -> V_158 = V_31 -> V_158 ;
V_34 -> V_137 = V_31 -> V_137 ;
memcpy ( V_34 -> V_160 , V_31 -> V_160 ,
V_31 -> V_137 ) ;
V_11 -> V_161 = 1 ;
}
static bool F_115 ( struct V_28 * V_29 ,
struct V_36 * V_36 ,
struct V_10 * V_11 )
{
if ( F_116 ( V_36 ) ) {
if ( V_11 -> V_42 . V_1 == V_9 &&
V_29 -> V_162 != V_163 &&
V_29 -> V_162 != V_164 )
return false ;
return true ;
}
return false ;
}
static T_7 F_117 ( struct V_28 * * V_165 )
{
struct V_28 * V_29 = * V_165 ;
struct V_36 * V_36 ;
struct V_10 * V_11 ;
int (* F_118)( const struct V_28 * , struct V_10 * ,
struct V_36 * );
int V_166 = V_167 ;
V_29 = F_119 ( V_29 , V_130 ) ;
if ( F_23 ( ! V_29 ) )
return V_168 ;
* V_165 = V_29 ;
V_36 = F_120 ( V_29 -> V_15 ) ;
V_11 = V_36 -> V_11 ;
if ( V_11 -> V_42 . V_169 )
V_36 -> V_15 -> V_170 = V_116 ;
F_118 = F_121 ( V_11 -> F_118 ) ;
if ( F_118 ) {
V_166 = F_118 ( V_29 , V_11 , V_36 ) ;
if ( V_166 == V_168 ) {
F_122 ( V_29 ) ;
return V_166 ;
}
}
if ( F_115 ( V_29 , V_36 , V_11 ) ) {
return V_171 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_42 . V_1 == V_9 &&
V_11 -> V_15 -> V_83 & V_172 &&
V_29 -> V_162 == V_173 ) {
if ( F_23 ( F_123 ( V_29 ,
V_29 -> V_174 - F_124 ( V_29 ) ) ) ) {
F_125 ( V_29 ) ;
return V_168 ;
}
memcpy ( F_126 ( V_29 ) -> V_175 , V_11 -> V_15 -> V_138 , V_94 ) ;
}
return V_166 ;
}
static int F_127 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
int V_76 ;
V_76 = F_128 ( V_31 , V_34 ) ;
if ( V_76 )
return V_76 ;
V_31 -> V_98 |= V_176 ;
F_129 ( V_177 , V_31 , V_176 ) ;
return 0 ;
}
static void F_130 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_131 ( V_31 , V_34 ) ;
V_31 -> V_98 &= ~ V_176 ;
F_129 ( V_177 , V_31 , V_176 ) ;
}
int F_132 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
const struct V_56 * V_57 = V_31 -> V_58 ;
struct V_36 * V_127 = NULL ;
struct V_91 * V_92 ;
struct V_178 V_78 ;
int V_179 ;
int V_21 = 0 ;
if ( ! V_11 -> V_42 . V_63 &&
V_31 -> V_65 -> V_66 == NULL &&
V_57 -> V_67 == NULL ) {
F_37 ( L_26 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_98 & V_176 ) {
F_3 ( L_27 ) ;
return - V_180 ;
}
if ( V_31 -> V_142 & V_144 ) {
F_3 ( L_28 , V_31 -> V_16 ) ;
if ( F_133 ( V_34 ) ) {
F_32 ( L_29 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
return - V_181 ;
} else {
F_37 ( L_30 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_34 -> V_16 ) ;
}
} else {
F_3 ( L_31 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_98 & V_182 ) ) {
F_32 ( L_32 ,
V_31 -> V_16 ) ;
V_21 = - V_181 ;
goto V_183;
}
if ( V_11 -> V_40 == 0 ) {
if ( V_34 -> type != V_31 -> type ) {
F_3 ( L_33 ,
V_34 -> V_16 ,
V_34 -> type , V_31 -> type ) ;
V_21 = F_93 ( V_184 ,
V_34 ) ;
V_21 = F_134 ( V_21 ) ;
if ( V_21 ) {
F_32 ( L_34 ,
V_34 -> V_16 ) ;
V_21 = - V_180 ;
goto V_183;
}
F_135 ( V_34 ) ;
F_136 ( V_34 ) ;
if ( V_31 -> type != V_185 )
F_114 ( V_34 , V_31 ) ;
else {
F_137 ( V_34 ) ;
V_34 -> V_83 &= ~ V_186 ;
}
F_93 ( V_187 ,
V_34 ) ;
}
} else if ( V_34 -> type != V_31 -> type ) {
F_32 ( L_35 ,
V_31 -> V_16 ,
V_31 -> type , V_34 -> type ) ;
V_21 = - V_188 ;
goto V_183;
}
if ( V_57 -> V_189 == NULL ) {
if ( V_11 -> V_40 == 0 ) {
F_37 ( L_36 ,
V_34 -> V_16 ) ;
V_11 -> V_42 . V_119 = V_190 ;
} else if ( V_11 -> V_42 . V_119 != V_190 ) {
F_32 ( L_37 ,
V_34 -> V_16 ) ;
V_21 = - V_191 ;
goto V_183;
}
}
F_93 ( V_192 , V_31 ) ;
if ( V_11 -> V_40 == 0 && V_11 -> V_193 )
F_107 ( V_11 -> V_15 , V_31 ) ;
V_127 = F_4 ( sizeof( struct V_36 ) , V_17 ) ;
if ( ! V_127 ) {
V_21 = - V_18 ;
goto V_183;
}
V_127 -> V_194 = 0 ;
V_127 -> V_195 = V_31 -> V_196 ;
V_21 = F_138 ( V_31 , V_11 -> V_15 -> V_196 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_197;
}
memcpy ( V_127 -> V_198 , V_31 -> V_138 , V_94 ) ;
if ( ! V_11 -> V_42 . V_119 ) {
memcpy ( V_78 . V_199 , V_34 -> V_138 , V_34 -> V_137 ) ;
V_78 . V_200 = V_31 -> type ;
V_21 = F_139 ( V_31 , & V_78 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_201;
}
}
V_21 = F_127 ( V_34 , V_31 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_21 ) ;
goto V_202;
}
V_21 = F_140 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_41 , V_31 -> V_16 ) ;
goto V_203;
}
V_127 -> V_11 = V_11 ;
V_127 -> V_15 = V_31 ;
V_31 -> V_83 |= V_204 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_141 ( V_11 , V_127 ) ;
if ( V_21 )
goto V_205;
}
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_98 & V_99 ) {
V_21 = F_54 ( V_31 , 1 ) ;
if ( V_21 )
goto V_205;
}
if ( V_34 -> V_98 & V_100 ) {
V_21 = F_56 ( V_31 , 1 ) ;
if ( V_21 )
goto V_205;
}
F_77 ( V_34 ) ;
F_75 (ha, bond_dev)
F_58 ( V_31 , V_92 -> V_78 ) ;
F_78 ( V_34 ) ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
T_3 V_93 [ V_94 ] = V_95 ;
F_58 ( V_31 , V_93 ) ;
}
F_36 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_95 ( V_11 , V_127 ) ;
V_127 -> V_112 = 0 ;
V_127 -> V_206 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_110 ( V_11 ) ;
F_44 ( V_127 ) ;
F_66 ( & V_11 -> V_20 ) ;
V_127 -> V_207 = V_116 -
( F_142 ( V_11 -> V_42 . V_169 ) + 1 ) ;
if ( V_11 -> V_42 . V_117 && ! V_11 -> V_42 . V_63 ) {
V_179 = F_47 ( V_11 , V_31 , 1 ) ;
if ( ( V_179 == - 1 ) && ! V_11 -> V_42 . V_169 ) {
F_37 ( L_42 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_179 == - 1 ) {
F_37 ( L_43 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
}
if ( V_11 -> V_42 . V_117 ) {
if ( F_47 ( V_11 , V_31 , 0 ) == V_64 ) {
if ( V_11 -> V_42 . V_109 ) {
V_127 -> V_43 = V_111 ;
V_127 -> V_112 = V_11 -> V_42 . V_109 ;
} else {
V_127 -> V_43 = V_44 ;
}
} else {
V_127 -> V_43 = V_208 ;
}
} else if ( V_11 -> V_42 . V_169 ) {
V_127 -> V_43 = ( F_41 ( V_31 ) ?
V_44 : V_208 ) ;
} else {
V_127 -> V_43 = V_44 ;
}
if ( V_127 -> V_43 != V_208 )
V_127 -> V_116 = V_116 ;
F_3 ( L_44 ,
V_127 -> V_43 == V_208 ? L_45 :
( V_127 -> V_43 == V_44 ? L_46 : L_47 ) ) ;
if ( F_53 ( V_11 -> V_42 . V_1 ) && V_11 -> V_42 . V_209 [ 0 ] ) {
if ( strcmp ( V_11 -> V_42 . V_209 , V_127 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_102 = V_127 ;
V_11 -> V_103 = true ;
}
}
F_6 ( & V_11 -> V_121 ) ;
switch ( V_11 -> V_42 . V_1 ) {
case V_4 :
F_91 ( V_127 ) ;
F_94 ( V_11 ) ;
break;
case V_7 :
F_91 ( V_127 ) ;
if ( V_11 -> V_40 == 1 ) {
F_143 ( V_127 ) . V_210 = 1 ;
F_144 ( V_11 , 1000 / V_211 ) ;
} else {
F_143 ( V_127 ) . V_210 =
F_143 ( V_127 -> V_27 ) . V_210 + 1 ;
}
F_145 ( V_127 ) ;
break;
case V_8 :
case V_9 :
F_146 ( V_127 ) ;
F_91 ( V_127 ) ;
F_94 ( V_11 ) ;
break;
default:
F_3 ( L_48 ) ;
F_146 ( V_127 ) ;
if ( ! V_11 -> V_77 && V_127 -> V_43 == V_44 )
V_11 -> V_77 = V_127 ;
break;
}
F_8 ( & V_11 -> V_121 ) ;
F_39 ( V_11 ) ;
#ifdef F_147
V_31 -> V_136 = F_106 ( V_11 ) ;
if ( V_31 -> V_136 ) {
if ( F_97 ( V_127 ) ) {
F_70 ( & V_11 -> V_20 ) ;
F_87 ( L_49
L_50 ,
V_34 -> V_16 ) ;
V_21 = - V_180 ;
goto V_212;
}
}
#endif
F_70 ( & V_11 -> V_20 ) ;
V_21 = F_148 ( V_34 , V_31 ) ;
if ( V_21 )
goto V_212;
V_21 = F_149 ( V_31 , F_117 ,
V_127 ) ;
if ( V_21 ) {
F_3 ( L_51 , V_21 ) ;
goto V_213;
}
F_87 ( L_52 ,
V_34 -> V_16 , V_31 -> V_16 ,
F_150 ( V_127 ) ? L_53 : L_54 ,
V_127 -> V_43 != V_208 ? L_55 : L_56 ) ;
return 0 ;
V_213:
F_151 ( V_34 , V_31 ) ;
V_212:
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
F_77 ( V_34 ) ;
F_74 ( V_34 , V_31 ) ;
F_78 ( V_34 ) ;
}
F_38 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_96 ( V_11 , V_127 ) ;
if ( V_11 -> V_102 == V_127 )
V_11 -> V_102 = NULL ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_77 == V_127 ) {
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_121 ) ;
F_86 ( V_11 , NULL ) ;
F_94 ( V_11 ) ;
F_8 ( & V_11 -> V_121 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
F_99 ( V_127 ) ;
V_205:
V_31 -> V_83 &= ~ V_204 ;
F_152 ( V_31 ) ;
V_203:
F_130 ( V_34 , V_31 ) ;
V_202:
if ( ! V_11 -> V_42 . V_119 ) {
memcpy ( V_78 . V_199 , V_127 -> V_198 , V_94 ) ;
V_78 . V_200 = V_31 -> type ;
F_139 ( V_31 , & V_78 ) ;
}
V_201:
F_138 ( V_31 , V_127 -> V_195 ) ;
V_197:
F_15 ( V_127 ) ;
V_183:
F_110 ( V_11 ) ;
return V_21 ;
}
static int F_153 ( struct V_30 * V_34 ,
struct V_30 * V_31 ,
bool V_214 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_215 ;
struct V_178 V_78 ;
T_5 V_216 = V_34 -> V_142 ;
if ( ! ( V_31 -> V_98 & V_176 ) ||
! F_154 ( V_31 , V_34 ) ) {
F_32 ( L_57 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
return - V_188 ;
}
F_10 () ;
F_6 ( & V_11 -> V_20 ) ;
V_36 = F_26 ( V_11 , V_31 ) ;
if ( ! V_36 ) {
F_87 ( L_58 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_188 ;
}
F_8 ( & V_11 -> V_20 ) ;
F_155 ( V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_214 && ! V_11 -> V_42 . V_119 ) {
if ( F_156 ( V_34 -> V_138 , V_36 -> V_198 ) &&
V_11 -> V_40 > 1 )
F_37 ( L_59 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_36 -> V_198 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_157 ( V_36 ) ;
}
F_87 ( L_60 ,
V_34 -> V_16 ,
F_150 ( V_36 ) ? L_61 : L_62 ,
V_31 -> V_16 ) ;
V_215 = V_11 -> V_77 ;
V_11 -> V_217 = NULL ;
F_96 ( V_11 , V_36 ) ;
if ( V_11 -> V_102 == V_36 )
V_11 -> V_102 = NULL ;
if ( V_215 == V_36 )
F_86 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_158 ( V_11 , V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_214 ) {
V_11 -> V_77 = NULL ;
} else if ( V_215 == V_36 ) {
F_8 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_121 ) ;
F_94 ( V_11 ) ;
F_8 ( & V_11 -> V_121 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_40 == 0 ) {
F_39 ( V_11 ) ;
F_159 ( V_34 ) ;
V_11 -> V_193 = true ;
if ( F_160 ( V_11 ) ) {
F_37 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_37 ( L_64 ,
V_34 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
if ( V_11 -> V_40 == 0 ) {
F_93 ( V_141 , V_11 -> V_15 ) ;
F_93 ( V_218 , V_11 -> V_15 ) ;
}
F_110 ( V_11 ) ;
if ( ! ( V_34 -> V_142 & V_144 ) &&
( V_216 & V_144 ) )
F_87 ( L_65 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
F_151 ( V_34 , V_31 ) ;
F_38 ( V_11 , V_31 ) ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_98 & V_99 )
F_54 ( V_31 , - 1 ) ;
if ( V_34 -> V_98 & V_100 )
F_56 ( V_31 , - 1 ) ;
F_77 ( V_34 ) ;
F_74 ( V_34 , V_31 ) ;
F_78 ( V_34 ) ;
}
F_130 ( V_34 , V_31 ) ;
F_99 ( V_36 ) ;
F_152 ( V_31 ) ;
if ( V_11 -> V_42 . V_119 != V_190 ) {
memcpy ( V_78 . V_199 , V_36 -> V_198 , V_94 ) ;
V_78 . V_200 = V_31 -> type ;
F_139 ( V_31 , & V_78 ) ;
}
F_138 ( V_31 , V_36 -> V_195 ) ;
V_31 -> V_83 &= ~ V_204 ;
F_15 ( V_36 ) ;
return 0 ;
}
int F_161 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
return F_153 ( V_34 , V_31 , false ) ;
}
static int F_162 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_166 ;
V_166 = F_161 ( V_34 , V_31 ) ;
if ( ( V_166 == 0 ) && ( V_11 -> V_40 == 0 ) ) {
V_34 -> V_83 |= V_131 ;
F_87 ( L_66 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_163 ( V_34 ) ;
}
return V_166 ;
}
static int F_164 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_97 = NULL ;
struct V_36 * V_96 = NULL ;
int V_21 = 0 ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) )
return - V_188 ;
if ( ! ( V_31 -> V_98 & V_176 ) ||
! F_154 ( V_31 , V_34 ) )
return - V_188 ;
F_66 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_121 ) ;
V_97 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_121 ) ;
V_96 = F_26 ( V_11 , V_31 ) ;
if ( V_96 && ( V_96 == V_97 ) ) {
F_70 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_96 ) &&
( V_97 ) &&
( V_96 -> V_43 == V_44 ) &&
F_83 ( V_96 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_121 ) ;
F_86 ( V_11 , V_96 ) ;
F_8 ( & V_11 -> V_121 ) ;
F_16 () ;
} else
V_21 = - V_188 ;
F_70 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_165 ( struct V_30 * V_34 , struct V_219 * V_220 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_220 -> V_221 = V_11 -> V_42 . V_1 ;
V_220 -> V_117 = V_11 -> V_42 . V_117 ;
F_66 ( & V_11 -> V_20 ) ;
V_220 -> V_222 = V_11 -> V_40 ;
F_70 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_166 ( struct V_30 * V_34 , struct V_223 * V_220 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
int V_38 , V_21 = - V_22 ;
F_66 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
if ( V_38 == ( int ) V_220 -> V_224 ) {
V_21 = 0 ;
strcpy ( V_220 -> V_225 , V_36 -> V_15 -> V_16 ) ;
V_220 -> V_43 = V_36 -> V_43 ;
V_220 -> V_115 = F_167 ( V_36 ) ;
V_220 -> V_206 = V_36 -> V_206 ;
break;
}
}
F_70 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_168 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 , V_226 , V_227 = 0 ;
bool V_228 ;
V_228 = ! V_11 -> V_77 ? true : false ;
F_30 (bond, slave, i) {
V_36 -> V_229 = V_230 ;
V_226 = F_47 ( V_11 , V_36 -> V_15 , 0 ) ;
switch ( V_36 -> V_43 ) {
case V_44 :
if ( V_226 )
continue;
V_36 -> V_43 = V_231 ;
V_36 -> V_112 = V_11 -> V_42 . V_232 ;
if ( V_36 -> V_112 ) {
F_87 ( L_67 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_1 ==
V_4 ) ?
( F_150 ( V_36 ) ?
L_68 : L_69 ) : L_70 ,
V_36 -> V_15 -> V_16 ,
V_11 -> V_42 . V_232 * V_11 -> V_42 . V_117 ) ;
}
case V_231 :
if ( V_226 ) {
V_36 -> V_43 = V_44 ;
V_36 -> V_116 = V_116 ;
F_87 ( L_71 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_232 - V_36 -> V_112 ) *
V_11 -> V_42 . V_117 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_36 -> V_112 <= 0 ) {
V_36 -> V_229 = V_208 ;
V_227 ++ ;
continue;
}
V_36 -> V_112 -- ;
break;
case V_208 :
if ( ! V_226 )
continue;
V_36 -> V_43 = V_111 ;
V_36 -> V_112 = V_11 -> V_42 . V_109 ;
if ( V_36 -> V_112 ) {
F_87 ( L_72 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ,
V_228 ? 0 :
V_11 -> V_42 . V_109 *
V_11 -> V_42 . V_117 ) ;
}
case V_111 :
if ( ! V_226 ) {
V_36 -> V_43 = V_208 ;
F_87 ( L_73 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_109 - V_36 -> V_112 ) *
V_11 -> V_42 . V_117 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_228 )
V_36 -> V_112 = 0 ;
if ( V_36 -> V_112 <= 0 ) {
V_36 -> V_229 = V_44 ;
V_227 ++ ;
V_228 = false ;
continue;
}
V_36 -> V_112 -- ;
break;
}
}
return V_227 ;
}
static void F_169 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i) {
switch ( V_36 -> V_229 ) {
case V_230 :
continue;
case V_44 :
V_36 -> V_43 = V_44 ;
V_36 -> V_116 = V_116 ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_170 ( V_36 ) ;
} else if ( V_11 -> V_42 . V_1 != V_4 ) {
F_146 ( V_36 ) ;
} else if ( V_36 != V_11 -> V_102 ) {
F_170 ( V_36 ) ;
}
F_87 ( L_74 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ,
V_36 -> V_48 , V_36 -> V_50 ? L_75 : L_76 ) ;
if ( V_11 -> V_42 . V_1 == V_7 )
F_88 ( V_36 , V_44 ) ;
if ( F_13 ( V_11 ) )
F_89 ( V_11 , V_36 ,
V_44 ) ;
if ( ! V_11 -> V_77 ||
( V_36 == V_11 -> V_102 ) )
goto V_233;
continue;
case V_208 :
if ( V_36 -> V_206 < V_234 )
V_36 -> V_206 ++ ;
V_36 -> V_43 = V_208 ;
if ( V_11 -> V_42 . V_1 == V_4 ||
V_11 -> V_42 . V_1 == V_7 )
F_91 ( V_36 ) ;
F_87 ( L_77 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_11 -> V_42 . V_1 == V_7 )
F_88 ( V_36 ,
V_208 ) ;
if ( F_13 ( V_11 ) )
F_89 ( V_11 , V_36 ,
V_208 ) ;
if ( V_36 == V_11 -> V_77 )
goto V_233;
continue;
default:
F_32 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_229 ,
V_36 -> V_15 -> V_16 ) ;
V_36 -> V_229 = V_230 ;
continue;
}
V_233:
F_171 () ;
F_10 () ;
F_6 ( & V_11 -> V_121 ) ;
F_94 ( V_11 ) ;
F_8 ( & V_11 -> V_121 ) ;
F_16 () ;
}
F_39 ( V_11 ) ;
}
void F_172 ( struct V_89 * V_90 )
{
struct V_10 * V_11 = F_73 ( V_90 , struct V_10 ,
V_235 . V_90 ) ;
bool V_118 = false ;
unsigned long V_112 ;
F_66 ( & V_11 -> V_20 ) ;
V_112 = F_142 ( V_11 -> V_42 . V_117 ) ;
if ( V_11 -> V_40 == 0 )
goto V_236;
V_118 = F_84 ( V_11 ) ;
if ( F_168 ( V_11 ) ) {
F_70 ( & V_11 -> V_20 ) ;
if ( ! F_173 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_112 = 1 ;
V_118 = false ;
goto V_236;
}
F_66 ( & V_11 -> V_20 ) ;
F_169 ( V_11 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_174 () ;
F_66 ( & V_11 -> V_20 ) ;
}
V_236:
if ( V_11 -> V_42 . V_117 )
F_69 ( V_11 -> V_86 , & V_11 -> V_235 , V_112 ) ;
F_70 ( & V_11 -> V_20 ) ;
if ( V_118 ) {
if ( ! F_173 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_11 -> V_113 ++ ;
F_70 ( & V_11 -> V_20 ) ;
return;
}
F_93 ( V_123 , V_11 -> V_15 ) ;
F_174 () ;
}
}
static int F_175 ( struct V_10 * V_11 , T_8 V_237 )
{
struct V_13 * V_14 ;
struct V_30 * V_81 ;
if ( V_237 == F_176 ( V_11 -> V_15 , 0 , V_237 ) )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_65 () ;
V_81 = F_68 ( V_11 -> V_15 , V_14 -> V_12 ) ;
F_71 () ;
if ( V_81 && V_237 == F_176 ( V_81 , 0 , V_237 ) )
return 1 ;
}
return 0 ;
}
static void F_177 ( struct V_30 * V_31 , int V_238 , T_8 V_239 , T_8 V_240 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_79 , V_238 ,
V_31 -> V_16 , V_239 , V_240 , V_12 ) ;
V_29 = F_178 ( V_238 , V_241 , V_239 , V_31 , V_240 ,
NULL , V_31 -> V_138 , NULL ) ;
if ( ! V_29 ) {
F_32 ( L_80 ) ;
return;
}
if ( V_12 ) {
V_29 = F_179 ( V_29 , V_12 ) ;
if ( ! V_29 ) {
F_32 ( L_81 ) ;
return;
}
}
F_180 ( V_29 ) ;
}
static void F_181 ( struct V_10 * V_11 , struct V_36 * V_36 )
{
int V_38 , V_12 ;
T_8 * V_242 = V_11 -> V_42 . V_243 ;
struct V_13 * V_14 ;
struct V_30 * V_81 = NULL ;
struct V_244 * V_245 ;
for ( V_38 = 0 ; ( V_38 < V_246 ) ; V_38 ++ ) {
T_8 V_78 ;
if ( ! V_242 [ V_38 ] )
break;
F_3 ( L_82 , V_242 [ V_38 ] ) ;
if ( ! F_160 ( V_11 ) ) {
F_3 ( L_83 ) ;
V_78 = F_176 ( V_11 -> V_15 , V_242 [ V_38 ] , 0 ) ;
F_177 ( V_36 -> V_15 , V_247 , V_242 [ V_38 ] ,
V_78 , 0 ) ;
continue;
}
V_245 = F_182 ( F_183 ( V_11 -> V_15 ) , V_242 [ V_38 ] , 0 ,
V_248 , 0 ) ;
if ( F_184 ( V_245 ) ) {
if ( F_185 () ) {
F_37 ( L_84 ,
V_11 -> V_15 -> V_16 , & V_242 [ V_38 ] ) ;
}
continue;
}
if ( V_245 -> V_249 . V_15 == V_11 -> V_15 ) {
F_186 ( V_245 ) ;
F_3 ( L_85 ) ;
V_78 = F_176 ( V_11 -> V_15 , V_242 [ V_38 ] , 0 ) ;
F_177 ( V_36 -> V_15 , V_247 , V_242 [ V_38 ] ,
V_78 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_65 () ;
V_81 = F_68 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_71 () ;
if ( V_81 == V_245 -> V_249 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_86 ,
V_81 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 && V_81 ) {
F_186 ( V_245 ) ;
V_78 = F_176 ( V_81 , V_242 [ V_38 ] , 0 ) ;
F_177 ( V_36 -> V_15 , V_247 , V_242 [ V_38 ] ,
V_78 , V_12 ) ;
continue;
}
if ( F_185 () ) {
F_37 ( L_87 ,
V_11 -> V_15 -> V_16 , & V_242 [ V_38 ] ,
V_245 -> V_249 . V_15 ? V_245 -> V_249 . V_15 -> V_16 : L_18 ) ;
}
F_186 ( V_245 ) ;
}
}
static void F_187 ( struct V_10 * V_11 , struct V_36 * V_36 , T_8 V_250 , T_8 V_251 )
{
int V_38 ;
T_8 * V_242 = V_11 -> V_42 . V_243 ;
for ( V_38 = 0 ; ( V_38 < V_246 ) && V_242 [ V_38 ] ; V_38 ++ ) {
F_3 ( L_88 ,
& V_250 , & V_251 , V_38 , & V_242 [ V_38 ] ,
F_175 ( V_11 , V_251 ) ) ;
if ( V_250 == V_242 [ V_38 ] ) {
if ( F_175 ( V_11 , V_251 ) )
V_36 -> V_207 = V_116 ;
return;
}
}
}
static int F_188 ( const struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_36 * V_36 )
{
struct V_252 * V_253 = (struct V_252 * ) V_29 -> V_174 ;
unsigned char * V_254 ;
T_8 V_250 , V_251 ;
int V_255 ;
if ( V_29 -> V_256 != F_189 ( V_241 ) )
return V_167 ;
F_66 ( & V_11 -> V_20 ) ;
V_255 = F_190 ( V_11 -> V_15 ) ;
F_3 ( L_89 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( V_255 > F_191 ( V_29 ) ) {
V_253 = F_192 ( V_255 , V_130 ) ;
if ( ! V_253 )
goto V_257;
if ( F_193 ( V_29 , 0 , V_253 , V_255 ) < 0 )
goto V_257;
}
if ( V_253 -> V_258 != V_11 -> V_15 -> V_137 ||
V_29 -> V_162 == V_259 ||
V_29 -> V_162 == V_260 ||
V_253 -> V_261 != F_194 ( V_185 ) ||
V_253 -> V_262 != F_194 ( V_263 ) ||
V_253 -> V_264 != 4 )
goto V_257;
V_254 = ( unsigned char * ) ( V_253 + 1 ) ;
V_254 += V_11 -> V_15 -> V_137 ;
memcpy ( & V_250 , V_254 , 4 ) ;
V_254 += 4 + V_11 -> V_15 -> V_137 ;
memcpy ( & V_251 , V_254 , 4 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 , F_167 ( V_36 ) ,
V_11 -> V_42 . V_265 , F_195 ( V_11 , V_36 ) ,
& V_250 , & V_251 ) ;
if ( F_150 ( V_36 ) )
F_187 ( V_11 , V_36 , V_250 , V_251 ) ;
else
F_187 ( V_11 , V_36 , V_251 , V_250 ) ;
V_257:
F_70 ( & V_11 -> V_20 ) ;
if ( V_253 != (struct V_252 * ) V_29 -> V_174 )
F_15 ( V_253 ) ;
return V_167 ;
}
void F_196 ( struct V_89 * V_90 )
{
struct V_10 * V_11 = F_73 ( V_90 , struct V_10 ,
V_266 . V_90 ) ;
struct V_36 * V_36 , * V_215 ;
int V_233 = 0 ;
int V_267 , V_268 ;
int V_38 ;
F_66 ( & V_11 -> V_20 ) ;
V_267 = F_142 ( V_11 -> V_42 . V_169 ) ;
V_268 = V_267 / 2 ;
if ( V_11 -> V_40 == 0 )
goto V_236;
F_66 ( & V_11 -> V_121 ) ;
V_215 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_121 ) ;
F_30 (bond, slave, i) {
unsigned long V_269 = F_197 ( V_36 -> V_15 ) ;
if ( V_36 -> V_43 != V_44 ) {
if ( F_198 ( V_116 ,
V_269 - V_267 ,
V_269 + V_267 + V_268 ) &&
F_198 ( V_116 ,
V_36 -> V_15 -> V_170 - V_267 ,
V_36 -> V_15 -> V_170 + V_267 + V_268 ) ) {
V_36 -> V_43 = V_44 ;
F_146 ( V_36 ) ;
if ( ! V_215 ) {
F_87 ( L_91 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
V_233 = 1 ;
} else {
F_87 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_198 ( V_116 ,
V_269 - V_267 ,
V_269 + 2 * V_267 + V_268 ) ||
! F_198 ( V_116 ,
V_36 -> V_15 -> V_170 - V_267 ,
V_36 -> V_15 -> V_170 + 2 * V_267 + V_268 ) ) {
V_36 -> V_43 = V_208 ;
F_170 ( V_36 ) ;
if ( V_36 -> V_206 < V_234 )
V_36 -> V_206 ++ ;
F_87 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_215 )
V_233 = 1 ;
}
}
if ( F_83 ( V_36 -> V_15 ) )
F_181 ( V_11 , V_36 ) ;
}
if ( V_233 ) {
F_10 () ;
F_6 ( & V_11 -> V_121 ) ;
F_94 ( V_11 ) ;
F_8 ( & V_11 -> V_121 ) ;
F_16 () ;
}
V_236:
if ( V_11 -> V_42 . V_169 )
F_69 ( V_11 -> V_86 , & V_11 -> V_266 , V_267 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_199 ( struct V_10 * V_11 , int V_267 )
{
struct V_36 * V_36 ;
int V_38 , V_227 = 0 ;
unsigned long V_269 ;
int V_268 ;
V_268 = V_267 / 2 ;
F_30 (bond, slave, i) {
V_36 -> V_229 = V_230 ;
if ( V_36 -> V_43 != V_44 ) {
if ( F_198 ( V_116 ,
F_200 ( V_11 , V_36 ) - V_267 ,
F_200 ( V_11 , V_36 ) + V_267 + V_268 ) ) {
V_36 -> V_229 = V_44 ;
V_227 ++ ;
}
continue;
}
if ( F_198 ( V_116 ,
V_36 -> V_116 - V_267 ,
V_36 -> V_116 + 2 * V_267 + V_268 ) )
continue;
if ( ! F_150 ( V_36 ) &&
! V_11 -> V_217 &&
! F_198 ( V_116 ,
F_200 ( V_11 , V_36 ) - V_267 ,
F_200 ( V_11 , V_36 ) + 3 * V_267 + V_268 ) ) {
V_36 -> V_229 = V_208 ;
V_227 ++ ;
}
V_269 = F_197 ( V_36 -> V_15 ) ;
if ( F_150 ( V_36 ) &&
( ! F_198 ( V_116 ,
V_269 - V_267 ,
V_269 + 2 * V_267 + V_268 ) ||
! F_198 ( V_116 ,
F_200 ( V_11 , V_36 ) - V_267 ,
F_200 ( V_11 , V_36 ) + 2 * V_267 + V_268 ) ) ) {
V_36 -> V_229 = V_208 ;
V_227 ++ ;
}
}
return V_227 ;
}
static void F_201 ( struct V_10 * V_11 , int V_267 )
{
struct V_36 * V_36 ;
int V_38 ;
unsigned long V_269 ;
F_30 (bond, slave, i) {
switch ( V_36 -> V_229 ) {
case V_230 :
continue;
case V_44 :
V_269 = F_197 ( V_36 -> V_15 ) ;
if ( ( ! V_11 -> V_77 &&
F_198 ( V_116 ,
V_269 - V_267 ,
V_269 + V_267 + V_267 / 2 ) ) ||
V_11 -> V_77 != V_36 ) {
V_36 -> V_43 = V_44 ;
if ( V_11 -> V_217 ) {
F_91 (
V_11 -> V_217 ) ;
V_11 -> V_217 = NULL ;
}
F_87 ( L_94 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_77 ||
( V_36 == V_11 -> V_102 ) )
goto V_233;
}
continue;
case V_208 :
if ( V_36 -> V_206 < V_234 )
V_36 -> V_206 ++ ;
V_36 -> V_43 = V_208 ;
F_91 ( V_36 ) ;
F_87 ( L_77 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_11 -> V_77 ) {
V_11 -> V_217 = NULL ;
goto V_233;
}
continue;
default:
F_32 ( L_95 ,
V_11 -> V_15 -> V_16 , V_36 -> V_229 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
V_233:
F_171 () ;
F_10 () ;
F_6 ( & V_11 -> V_121 ) ;
F_94 ( V_11 ) ;
F_8 ( & V_11 -> V_121 ) ;
F_16 () ;
}
F_39 ( V_11 ) ;
}
static void F_202 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_66 ( & V_11 -> V_121 ) ;
if ( V_11 -> V_217 && V_11 -> V_77 )
F_87 ( L_96 ,
V_11 -> V_217 -> V_15 -> V_16 ,
V_11 -> V_77 -> V_15 -> V_16 ) ;
if ( V_11 -> V_77 ) {
F_181 ( V_11 , V_11 -> V_77 ) ;
F_70 ( & V_11 -> V_121 ) ;
return;
}
F_70 ( & V_11 -> V_121 ) ;
if ( ! V_11 -> V_217 ) {
V_11 -> V_217 = V_11 -> V_110 ;
if ( ! V_11 -> V_217 )
return;
}
F_91 ( V_11 -> V_217 ) ;
F_82 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_83 ( V_36 -> V_15 ) ) {
V_36 -> V_43 = V_111 ;
F_92 ( V_36 ) ;
F_181 ( V_11 , V_36 ) ;
V_36 -> V_116 = V_116 ;
V_11 -> V_217 = V_36 ;
break;
}
if ( V_36 -> V_43 == V_44 ) {
V_36 -> V_43 = V_208 ;
if ( V_36 -> V_206 < V_234 )
V_36 -> V_206 ++ ;
F_91 ( V_36 ) ;
F_87 ( L_97 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
}
}
}
void F_203 ( struct V_89 * V_90 )
{
struct V_10 * V_11 = F_73 ( V_90 , struct V_10 ,
V_266 . V_90 ) ;
bool V_118 = false ;
int V_267 ;
F_66 ( & V_11 -> V_20 ) ;
V_267 = F_142 ( V_11 -> V_42 . V_169 ) ;
if ( V_11 -> V_40 == 0 )
goto V_236;
V_118 = F_84 ( V_11 ) ;
if ( F_199 ( V_11 , V_267 ) ) {
F_70 ( & V_11 -> V_20 ) ;
if ( ! F_173 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_267 = 1 ;
V_118 = false ;
goto V_236;
}
F_66 ( & V_11 -> V_20 ) ;
F_201 ( V_11 , V_267 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_174 () ;
F_66 ( & V_11 -> V_20 ) ;
}
F_202 ( V_11 ) ;
V_236:
if ( V_11 -> V_42 . V_169 )
F_69 ( V_11 -> V_86 , & V_11 -> V_266 , V_267 ) ;
F_70 ( & V_11 -> V_20 ) ;
if ( V_118 ) {
if ( ! F_173 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_11 -> V_113 ++ ;
F_70 ( & V_11 -> V_20 ) ;
return;
}
F_93 ( V_123 , V_11 -> V_15 ) ;
F_174 () ;
}
}
static int F_204 ( struct V_10 * V_11 )
{
F_205 ( V_11 ) ;
F_206 ( V_11 ) ;
F_207 ( V_11 ) ;
return V_270 ;
}
static int F_208 ( unsigned long V_271 ,
struct V_30 * V_34 )
{
struct V_10 * V_272 = F_29 ( V_34 ) ;
switch ( V_271 ) {
case V_273 :
return F_204 ( V_272 ) ;
case V_274 :
F_205 ( V_272 ) ;
break;
case V_275 :
F_206 ( V_272 ) ;
break;
default:
break;
}
return V_270 ;
}
static int F_209 ( unsigned long V_271 ,
struct V_30 * V_31 )
{
struct V_36 * V_36 = F_210 ( V_31 ) ;
struct V_10 * V_11 ;
struct V_30 * V_34 ;
T_2 V_276 ;
T_3 V_277 ;
if ( ! V_36 )
return V_270 ;
V_34 = V_36 -> V_11 -> V_15 ;
V_11 = V_36 -> V_11 ;
switch ( V_271 ) {
case V_274 :
if ( V_11 -> V_161 )
F_162 ( V_34 , V_31 ) ;
else
F_161 ( V_34 , V_31 ) ;
break;
case V_278 :
case V_279 :
V_276 = V_36 -> V_48 ;
V_277 = V_36 -> V_50 ;
F_44 ( V_36 ) ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
if ( V_276 != V_36 -> V_48 )
F_211 ( V_36 ) ;
if ( V_277 != V_36 -> V_50 )
F_212 ( V_36 ) ;
}
break;
case V_280 :
break;
case V_281 :
break;
case V_273 :
break;
case V_282 :
F_110 ( V_11 ) ;
break;
default:
break;
}
return V_270 ;
}
static int F_213 ( struct V_283 * V_284 ,
unsigned long V_271 , void * V_285 )
{
struct V_30 * V_286 = (struct V_30 * ) V_285 ;
F_3 ( L_98 ,
V_286 ? V_286 -> V_16 : L_10 ,
V_271 ) ;
if ( ! ( V_286 -> V_83 & V_204 ) )
return V_270 ;
if ( V_286 -> V_98 & V_287 ) {
F_3 ( L_99 ) ;
return F_208 ( V_271 , V_286 ) ;
}
if ( V_286 -> V_98 & V_176 ) {
F_3 ( L_100 ) ;
return F_209 ( V_271 , V_286 ) ;
}
return V_270 ;
}
static int F_214 ( struct V_28 * V_29 , int V_288 )
{
struct V_289 * V_174 = (struct V_289 * ) V_29 -> V_174 ;
if ( F_191 ( V_29 ) >= F_215 ( struct V_289 , V_290 ) )
return ( V_174 -> V_175 [ 5 ] ^ V_174 -> V_291 [ 5 ] ) % V_288 ;
return 0 ;
}
static int F_216 ( struct V_28 * V_29 , int V_288 )
{
const struct V_289 * V_174 ;
const struct V_292 * V_293 ;
const struct V_294 * V_295 ;
T_2 V_296 ;
const T_8 * V_297 , * V_298 ;
if ( V_29 -> V_256 == F_194 ( V_263 ) &&
F_217 ( V_29 , sizeof( * V_293 ) ) ) {
V_293 = F_218 ( V_29 ) ;
V_174 = (struct V_289 * ) V_29 -> V_174 ;
return ( ( F_219 ( V_293 -> V_299 ^ V_293 -> V_300 ) & 0xffff ) ^
( V_174 -> V_175 [ 5 ] ^ V_174 -> V_291 [ 5 ] ) ) % V_288 ;
} else if ( V_29 -> V_256 == F_194 ( V_301 ) &&
F_217 ( V_29 , sizeof( * V_295 ) ) ) {
V_295 = F_220 ( V_29 ) ;
V_174 = (struct V_289 * ) V_29 -> V_174 ;
V_297 = & V_295 -> V_299 . V_302 [ 0 ] ;
V_298 = & V_295 -> V_300 . V_302 [ 0 ] ;
V_296 = ( V_297 [ 1 ] ^ V_298 [ 1 ] ) ^ ( V_297 [ 2 ] ^ V_298 [ 2 ] ) ^ ( V_297 [ 3 ] ^ V_298 [ 3 ] ) ;
V_296 ^= ( V_296 >> 24 ) ^ ( V_296 >> 16 ) ^ ( V_296 >> 8 ) ;
return ( V_296 ^ V_174 -> V_175 [ 5 ] ^ V_174 -> V_291 [ 5 ] ) % V_288 ;
}
return F_214 ( V_29 , V_288 ) ;
}
static int F_221 ( struct V_28 * V_29 , int V_288 )
{
T_2 V_303 = 0 ;
const struct V_292 * V_293 ;
const struct V_294 * V_295 ;
const T_8 * V_297 , * V_298 ;
const T_9 * V_304 = NULL ;
T_9 V_305 [ 2 ] ;
int V_306 = F_222 ( V_29 ) ;
int V_307 ;
if ( V_29 -> V_256 == F_194 ( V_263 ) &&
F_223 ( V_29 , V_306 + sizeof( * V_293 ) ) ) {
V_293 = F_218 ( V_29 ) ;
V_307 = F_224 ( V_293 -> V_256 ) ;
if ( ! F_225 ( V_293 ) && V_307 >= 0 ) {
V_304 = F_226 ( V_29 , V_306 + ( V_293 -> V_308 << 2 ) + V_307 ,
sizeof( V_305 ) , & V_305 ) ;
if ( V_304 )
V_303 = F_227 ( V_304 [ 0 ] ^ V_304 [ 1 ] ) ;
}
return ( V_303 ^
( ( F_219 ( V_293 -> V_299 ^ V_293 -> V_300 ) ) & 0xffff ) ) % V_288 ;
} else if ( V_29 -> V_256 == F_194 ( V_301 ) &&
F_223 ( V_29 , V_306 + sizeof( * V_295 ) ) ) {
V_295 = F_220 ( V_29 ) ;
V_307 = F_224 ( V_295 -> V_309 ) ;
if ( V_307 >= 0 ) {
V_304 = F_226 ( V_29 , V_306 + sizeof( * V_295 ) + V_307 ,
sizeof( V_305 ) , & V_305 ) ;
if ( V_304 )
V_303 = F_227 ( V_304 [ 0 ] ^ V_304 [ 1 ] ) ;
}
V_297 = & V_295 -> V_299 . V_302 [ 0 ] ;
V_298 = & V_295 -> V_300 . V_302 [ 0 ] ;
V_303 ^= ( V_297 [ 1 ] ^ V_298 [ 1 ] ) ^ ( V_297 [ 2 ] ^ V_298 [ 2 ] ) ^ ( V_297 [ 3 ] ^ V_298 [ 3 ] ) ;
V_303 ^= ( V_303 >> 24 ) ^ ( V_303 >> 16 ) ^
( V_303 >> 8 ) ;
return V_303 % V_288 ;
}
return F_214 ( V_29 , V_288 ) ;
}
static void F_228 ( struct V_10 * V_11 )
{
F_229 ( & V_11 -> V_87 ,
F_72 ) ;
F_229 ( & V_11 -> V_310 , V_311 ) ;
F_229 ( & V_11 -> V_235 , F_172 ) ;
if ( V_11 -> V_42 . V_1 == V_4 )
F_229 ( & V_11 -> V_266 , F_203 ) ;
else
F_229 ( & V_11 -> V_266 , F_196 ) ;
F_229 ( & V_11 -> V_312 , V_313 ) ;
}
static void F_230 ( struct V_10 * V_11 )
{
F_231 ( & V_11 -> V_235 ) ;
F_231 ( & V_11 -> V_266 ) ;
F_231 ( & V_11 -> V_310 ) ;
F_231 ( & V_11 -> V_312 ) ;
F_231 ( & V_11 -> V_87 ) ;
}
static int F_232 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
int V_38 ;
F_66 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_40 > 0 ) {
F_66 ( & V_11 -> V_121 ) ;
F_30 (bond, slave, i) {
if ( ( V_11 -> V_42 . V_1 == V_4 )
&& ( V_36 != V_11 -> V_77 ) ) {
F_91 ( V_36 ) ;
} else {
F_92 ( V_36 ) ;
}
}
F_70 ( & V_11 -> V_121 ) ;
}
F_70 ( & V_11 -> V_20 ) ;
F_228 ( V_11 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_233 ( V_11 , ( V_11 -> V_42 . V_1 == V_9 ) ) )
return - V_18 ;
F_69 ( V_11 -> V_86 , & V_11 -> V_310 , 0 ) ;
}
if ( V_11 -> V_42 . V_117 )
F_69 ( V_11 -> V_86 , & V_11 -> V_235 , 0 ) ;
if ( V_11 -> V_42 . V_169 ) {
F_69 ( V_11 -> V_86 , & V_11 -> V_266 , 0 ) ;
if ( V_11 -> V_42 . V_265 )
V_11 -> F_118 = F_188 ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_69 ( V_11 -> V_86 , & V_11 -> V_312 , 0 ) ;
V_11 -> F_118 = V_314 ;
F_234 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_235 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_113 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_230 ( V_11 ) ;
if ( F_13 ( V_11 ) ) {
F_236 ( V_11 ) ;
}
V_11 -> F_118 = NULL ;
return 0 ;
}
static struct V_315 * F_237 ( struct V_30 * V_34 ,
struct V_315 * V_316 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_315 V_317 ;
struct V_36 * V_36 ;
int V_38 ;
memset ( V_316 , 0 , sizeof( * V_316 ) ) ;
F_238 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
const struct V_315 * V_318 =
F_239 ( V_36 -> V_15 , & V_317 ) ;
V_316 -> V_319 += V_318 -> V_319 ;
V_316 -> V_320 += V_318 -> V_320 ;
V_316 -> V_321 += V_318 -> V_321 ;
V_316 -> V_322 += V_318 -> V_322 ;
V_316 -> V_323 += V_318 -> V_323 ;
V_316 -> V_324 += V_318 -> V_324 ;
V_316 -> V_325 += V_318 -> V_325 ;
V_316 -> V_326 += V_318 -> V_326 ;
V_316 -> V_327 += V_318 -> V_327 ;
V_316 -> V_328 += V_318 -> V_328 ;
V_316 -> V_329 += V_318 -> V_329 ;
V_316 -> V_330 += V_318 -> V_330 ;
V_316 -> V_331 += V_318 -> V_331 ;
V_316 -> V_332 += V_318 -> V_332 ;
V_316 -> V_333 += V_318 -> V_333 ;
V_316 -> V_334 += V_318 -> V_334 ;
V_316 -> V_335 += V_318 -> V_335 ;
V_316 -> V_336 += V_318 -> V_336 ;
V_316 -> V_337 += V_318 -> V_337 ;
V_316 -> V_338 += V_318 -> V_338 ;
V_316 -> V_339 += V_318 -> V_339 ;
}
F_240 ( & V_11 -> V_20 ) ;
return V_316 ;
}
static int F_241 ( struct V_30 * V_34 , struct V_59 * V_60 , int V_340 )
{
struct V_30 * V_31 = NULL ;
struct V_219 V_341 ;
struct V_219 T_10 * V_342 = NULL ;
struct V_223 V_343 ;
struct V_223 T_10 * V_344 = NULL ;
struct V_61 * V_62 = NULL ;
struct V_345 * V_345 ;
int V_21 = 0 ;
F_3 ( L_101 , V_34 -> V_16 , V_340 ) ;
switch ( V_340 ) {
case V_70 :
V_62 = F_50 ( V_60 ) ;
if ( ! V_62 )
return - V_188 ;
V_62 -> V_346 = 0 ;
case V_73 :
V_62 = F_50 ( V_60 ) ;
if ( ! V_62 )
return - V_188 ;
if ( V_62 -> V_71 == 1 ) {
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_62 -> V_74 = 0 ;
F_66 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_121 ) ;
if ( F_41 ( V_11 -> V_15 ) )
V_62 -> V_74 = V_64 ;
F_70 ( & V_11 -> V_121 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_347 :
case V_348 :
V_342 = (struct V_219 T_10 * ) V_60 -> V_349 ;
if ( F_242 ( & V_341 , V_342 , sizeof( V_219 ) ) )
return - V_350 ;
V_21 = F_165 ( V_34 , & V_341 ) ;
if ( V_21 == 0 &&
F_243 ( V_342 , & V_341 , sizeof( V_219 ) ) )
return - V_350 ;
return V_21 ;
case V_351 :
case V_352 :
V_344 = (struct V_223 T_10 * ) V_60 -> V_349 ;
if ( F_242 ( & V_343 , V_344 , sizeof( V_223 ) ) )
return - V_350 ;
V_21 = F_166 ( V_34 , & V_343 ) ;
if ( V_21 == 0 &&
F_243 ( V_344 , & V_343 , sizeof( V_223 ) ) )
return - V_350 ;
return V_21 ;
default:
break;
}
V_345 = F_183 ( V_34 ) ;
if ( ! F_244 ( V_345 -> V_353 , V_354 ) )
return - V_181 ;
V_31 = F_245 ( V_345 , V_60 -> V_355 ) ;
F_3 ( L_102 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_103 , V_31 -> V_16 ) ;
switch ( V_340 ) {
case V_356 :
case V_357 :
V_21 = F_132 ( V_34 , V_31 ) ;
break;
case V_358 :
case V_359 :
V_21 = F_161 ( V_34 , V_31 ) ;
break;
case V_360 :
case V_361 :
F_107 ( V_34 , V_31 ) ;
V_21 = 0 ;
break;
case V_362 :
case V_363 :
V_21 = F_164 ( V_34 , V_31 ) ;
break;
default:
V_21 = - V_191 ;
}
F_246 ( V_31 ) ;
}
return V_21 ;
}
static bool F_247 ( unsigned char * V_78 ,
struct V_364 * V_365 ,
int V_366 )
{
struct V_91 * V_92 ;
F_248 (ha, list)
if ( ! memcmp ( V_92 -> V_78 , V_78 , V_366 ) )
return true ;
return false ;
}
static void F_249 ( struct V_30 * V_34 , int V_367 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_367 & V_99 )
F_52 ( V_11 ,
V_34 -> V_98 & V_99 ? 1 : - 1 ) ;
if ( V_367 & V_100 )
F_55 ( V_11 ,
V_34 -> V_98 & V_100 ? 1 : - 1 ) ;
}
static void F_250 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_91 * V_92 ;
bool V_368 ;
F_66 ( & V_11 -> V_20 ) ;
F_75 (ha, bond_dev) {
V_368 = F_247 ( V_92 -> V_78 , & V_11 -> V_369 ,
V_34 -> V_137 ) ;
if ( ! V_368 )
F_57 ( V_11 , V_92 -> V_78 ) ;
}
F_248 (ha, &bond->mc_list) {
V_368 = F_247 ( V_92 -> V_78 , & V_34 -> V_370 ,
V_34 -> V_137 ) ;
if ( ! V_368 )
F_59 ( V_11 , V_92 -> V_78 ) ;
}
F_251 ( & V_11 -> V_369 ) ;
F_252 ( & V_11 -> V_369 , & V_34 -> V_370 ,
V_34 -> V_137 , V_371 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_253 ( struct V_372 * V_373 )
{
struct V_10 * V_11 = F_29 ( V_373 -> V_15 ) ;
struct V_36 * V_36 = V_11 -> V_110 ;
const struct V_56 * V_57 ;
struct V_374 V_375 ;
int V_166 ;
if ( ! V_36 )
return 0 ;
V_57 = V_36 -> V_15 -> V_58 ;
if ( ! V_57 -> V_376 )
return 0 ;
V_375 . V_377 = NULL ;
V_375 . V_378 = NULL ;
V_166 = V_57 -> V_376 ( V_36 -> V_15 , & V_375 ) ;
if ( V_166 )
return V_166 ;
V_373 -> V_375 -> V_378 = V_375 . V_378 ;
if ( ! V_375 . V_377 )
return 0 ;
return V_375 . V_377 ( V_373 ) ;
}
static int F_254 ( struct V_30 * V_15 ,
struct V_374 * V_375 )
{
V_375 -> V_377 = F_253 ;
return 0 ;
}
static int F_255 ( struct V_30 * V_34 , int V_379 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_37 ;
int V_21 = 0 ;
int V_38 ;
F_3 ( L_104 , V_11 ,
( V_34 ? V_34 -> V_16 : L_10 ) , V_379 ) ;
F_30 (bond, slave, i) {
F_3 ( L_105 ,
V_36 ,
V_36 -> V_27 ,
V_36 -> V_15 -> V_58 -> V_380 ) ;
V_21 = F_138 ( V_36 -> V_15 , V_379 ) ;
if ( V_21 ) {
F_3 ( L_106 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
}
V_34 -> V_196 = V_379 ;
return 0 ;
V_39:
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_381 ;
V_381 = F_138 ( V_36 -> V_15 , V_34 -> V_196 ) ;
if ( V_381 ) {
F_3 ( L_107 ,
V_381 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_256 ( struct V_30 * V_34 , void * V_78 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_178 * V_382 = V_78 , V_383 ;
struct V_36 * V_36 , * V_37 ;
int V_21 = 0 ;
int V_38 ;
if ( V_11 -> V_42 . V_1 == V_9 )
return F_257 ( V_34 , V_78 ) ;
F_3 ( L_108 ,
V_11 , V_34 ? V_34 -> V_16 : L_10 ) ;
if ( V_11 -> V_42 . V_119 == V_190 )
return 0 ;
if ( ! F_258 ( V_382 -> V_199 ) )
return - V_384 ;
F_30 (bond, slave, i) {
const struct V_56 * V_57 = V_36 -> V_15 -> V_58 ;
F_3 ( L_109 , V_36 , V_36 -> V_15 -> V_16 ) ;
if ( V_57 -> V_189 == NULL ) {
V_21 = - V_191 ;
F_3 ( L_110 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
V_21 = F_139 ( V_36 -> V_15 , V_78 ) ;
if ( V_21 ) {
F_3 ( L_106 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
}
memcpy ( V_34 -> V_138 , V_382 -> V_199 , V_34 -> V_137 ) ;
return 0 ;
V_39:
memcpy ( V_383 . V_199 , V_34 -> V_138 , V_34 -> V_137 ) ;
V_383 . V_200 = V_34 -> type ;
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_381 ;
V_381 = F_139 ( V_36 -> V_15 , & V_383 ) ;
if ( V_381 ) {
F_3 ( L_107 ,
V_381 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_259 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_385 ;
int V_38 , V_386 , V_21 = 1 ;
struct V_292 * V_293 = F_218 ( V_29 ) ;
if ( ( V_293 -> V_256 == V_387 ) &&
( V_29 -> V_256 == F_194 ( V_263 ) ) ) {
F_66 ( & V_11 -> V_121 ) ;
V_36 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_121 ) ;
if ( ! V_36 )
goto V_23;
} else {
V_386 = V_11 -> V_388 ++ % V_11 -> V_40 ;
F_30 (bond, slave, i) {
V_386 -- ;
if ( V_386 < 0 )
break;
}
}
V_385 = V_36 ;
F_82 (bond, slave, i, start_at) {
if ( F_83 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_150 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_125 ( V_29 ) ;
}
return V_389 ;
}
static int F_260 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_21 = 1 ;
F_66 ( & V_11 -> V_121 ) ;
if ( V_11 -> V_77 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_77 -> V_15 ) ;
F_70 ( & V_11 -> V_121 ) ;
if ( V_21 )
F_125 ( V_29 ) ;
return V_389 ;
}
static int F_261 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_385 ;
int V_386 ;
int V_38 ;
int V_21 = 1 ;
V_386 = V_11 -> V_390 ( V_29 , V_11 -> V_40 ) ;
F_30 (bond, slave, i) {
V_386 -- ;
if ( V_386 < 0 )
break;
}
V_385 = V_36 ;
F_82 (bond, slave, i, start_at) {
if ( F_83 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_150 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_125 ( V_29 ) ;
}
return V_389 ;
}
static int F_262 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_385 ;
struct V_30 * V_391 = NULL ;
int V_38 ;
int V_21 = 1 ;
F_66 ( & V_11 -> V_121 ) ;
V_385 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_121 ) ;
if ( ! V_385 )
goto V_23;
F_82 (bond, slave, i, start_at) {
if ( F_83 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_150 ( V_36 ) ) {
if ( V_391 ) {
struct V_28 * V_392 = F_263 ( V_29 , V_130 ) ;
if ( ! V_392 ) {
F_32 ( L_111 ,
V_34 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_392 , V_391 ) ;
if ( V_21 ) {
F_125 ( V_392 ) ;
continue;
}
}
V_391 = V_36 -> V_15 ;
}
}
if ( V_391 )
V_21 = F_20 ( V_11 , V_29 , V_391 ) ;
V_23:
if ( V_21 )
F_125 ( V_29 ) ;
return V_389 ;
}
static void F_264 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_42 . V_393 ) {
case V_394 :
V_11 -> V_390 = F_216 ;
break;
case V_395 :
V_11 -> V_390 = F_221 ;
break;
case V_396 :
default:
V_11 -> V_390 = F_214 ;
break;
}
}
static inline int F_265 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_38 , V_21 = 1 ;
struct V_36 * V_36 = NULL ;
struct V_36 * V_397 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_30 (bond, check_slave, i) {
if ( V_397 -> V_194 == V_29 -> V_32 ) {
V_36 = V_397 ;
break;
}
}
if ( V_36 && V_36 -> V_194 && F_83 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
}
return V_21 ;
}
static T_6 F_266 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_6 V_398 = F_267 ( V_29 ) ? F_268 ( V_29 ) : 0 ;
F_22 ( V_29 ) -> V_33 = V_29 -> V_32 ;
if ( F_23 ( V_398 >= V_15 -> V_399 ) ) {
do {
V_398 -= V_15 -> V_399 ;
} while ( V_398 >= V_15 -> V_399 );
}
return V_398 ;
}
static T_11 F_269 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
if ( F_270 ( V_11 -> V_42 . V_1 ) ) {
if ( ! F_265 ( V_11 , V_29 ) )
return V_389 ;
}
switch ( V_11 -> V_42 . V_1 ) {
case V_3 :
return F_259 ( V_29 , V_15 ) ;
case V_4 :
return F_260 ( V_29 , V_15 ) ;
case V_5 :
return F_261 ( V_29 , V_15 ) ;
case V_6 :
return F_262 ( V_29 , V_15 ) ;
case V_7 :
return F_271 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_272 ( V_29 , V_15 ) ;
default:
F_32 ( L_112 ,
V_15 -> V_16 , V_11 -> V_42 . V_1 ) ;
F_273 ( 1 ) ;
F_125 ( V_29 ) ;
return V_389 ;
}
}
static T_11 F_274 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_11 V_166 = V_389 ;
if ( F_275 ( V_15 ) )
return V_400 ;
F_66 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_40 )
V_166 = F_269 ( V_29 , V_15 ) ;
else
F_125 ( V_29 ) ;
F_70 ( & V_11 -> V_20 ) ;
return V_166 ;
}
void F_276 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_34 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_264 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_264 ( V_11 ) ;
break;
case V_9 :
case V_8 :
break;
default:
F_32 ( L_112 ,
V_34 -> V_16 , V_1 ) ;
break;
}
}
static void F_277 ( struct V_30 * V_34 ,
struct V_401 * V_402 )
{
F_278 ( V_402 -> V_403 , V_404 , sizeof( V_402 -> V_403 ) ) ;
F_278 ( V_402 -> V_405 , V_406 , sizeof( V_402 -> V_405 ) ) ;
snprintf ( V_402 -> V_407 , sizeof( V_402 -> V_407 ) , L_113 ,
V_408 ) ;
}
static void F_279 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_11 -> V_86 )
F_280 ( V_11 -> V_86 ) ;
F_281 ( V_34 ) ;
}
static void F_282 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_283 ( & V_11 -> V_20 ) ;
F_283 ( & V_11 -> V_121 ) ;
V_11 -> V_42 = V_409 ;
V_11 -> V_15 = V_34 ;
F_5 ( & V_11 -> V_19 ) ;
F_137 ( V_34 ) ;
V_34 -> V_58 = & V_410 ;
V_34 -> V_65 = & V_411 ;
F_276 ( V_11 , V_11 -> V_42 . V_1 ) ;
V_34 -> V_412 = F_279 ;
F_284 ( V_34 , & V_413 ) ;
V_34 -> V_414 = 0 ;
V_34 -> V_98 |= V_287 | V_415 ;
V_34 -> V_83 |= V_204 ;
V_34 -> V_83 &= ~ ( V_156 | V_186 ) ;
V_34 -> V_142 |= V_144 ;
V_34 -> V_142 |= V_416 ;
V_34 -> V_417 = V_148 |
V_418 |
V_419 |
V_420 ;
V_34 -> V_417 &= ~ ( V_421 & ~ V_422 ) ;
V_34 -> V_142 |= V_34 -> V_417 ;
}
static void F_285 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_13 * V_14 , * V_423 ;
F_104 ( V_34 ) ;
while ( V_11 -> V_110 != NULL )
F_153 ( V_34 , V_11 -> V_110 -> V_15 , true ) ;
F_87 ( L_114 , V_34 -> V_16 ) ;
F_12 ( & V_11 -> V_424 ) ;
F_286 ( V_11 ) ;
F_251 ( & V_11 -> V_369 ) ;
F_287 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_288 ( const char * V_425 , const struct V_426 * V_427 )
{
int V_428 = - 1 , V_38 , V_126 ;
char * V_429 , V_430 [ V_431 + 1 ] = { 0 , } ;
for ( V_429 = ( char * ) V_425 ; * V_429 ; V_429 ++ )
if ( ! ( isdigit ( * V_429 ) || isspace ( * V_429 ) ) )
break;
if ( * V_429 )
V_126 = sscanf ( V_425 , L_115 , V_430 ) ;
else
V_126 = sscanf ( V_425 , L_113 , & V_428 ) ;
if ( ! V_126 )
return - 1 ;
for ( V_38 = 0 ; V_427 [ V_38 ] . V_432 ; V_38 ++ ) {
if ( V_428 == V_427 [ V_38 ] . V_1 )
return V_427 [ V_38 ] . V_1 ;
if ( strcmp ( V_430 , V_427 [ V_38 ] . V_432 ) == 0 )
return V_427 [ V_38 ] . V_1 ;
}
return - 1 ;
}
static int F_289 ( struct V_433 * V_42 )
{
int V_434 , V_435 , V_436 ;
if ( V_1 ) {
V_221 = F_288 ( V_1 , V_437 ) ;
if ( V_221 == - 1 ) {
F_32 ( L_116 ,
V_1 == NULL ? L_18 : V_1 ) ;
return - V_188 ;
}
}
if ( V_390 ) {
if ( ( V_221 != V_5 ) &&
( V_221 != V_7 ) ) {
F_87 ( L_117 ,
F_1 ( V_221 ) ) ;
} else {
V_438 = F_288 ( V_390 ,
V_439 ) ;
if ( V_438 == - 1 ) {
F_32 ( L_118 ,
V_390 == NULL ? L_18 :
V_390 ) ;
return - V_188 ;
}
}
}
if ( V_440 ) {
if ( V_221 != V_7 ) {
F_87 ( L_119 ,
F_1 ( V_221 ) ) ;
} else {
V_441 = F_288 ( V_440 , V_442 ) ;
if ( V_441 == - 1 ) {
F_32 ( L_120 ,
V_440 == NULL ? L_18 : V_440 ) ;
return - V_188 ;
}
}
}
if ( V_443 ) {
V_42 -> V_443 = F_288 ( V_443 , V_444 ) ;
if ( V_42 -> V_443 == - 1 ) {
F_32 ( L_121 ,
V_443 == NULL ? L_18 : V_443 ) ;
return - V_188 ;
}
if ( V_221 != V_7 ) {
F_37 ( L_122 ) ;
}
} else {
V_42 -> V_443 = V_445 ;
}
if ( V_446 < 0 ) {
F_37 ( L_123 ,
V_446 , 0 , V_447 , V_448 ) ;
V_446 = V_448 ;
}
if ( V_117 < 0 ) {
F_37 ( L_124 ,
V_117 , V_447 , V_449 ) ;
V_117 = V_449 ;
}
if ( V_109 < 0 ) {
F_37 ( L_125 ,
V_109 , V_447 ) ;
V_109 = 0 ;
}
if ( V_232 < 0 ) {
F_37 ( L_126 ,
V_232 , V_447 ) ;
V_232 = 0 ;
}
if ( ( V_63 != 0 ) && ( V_63 != 1 ) ) {
F_37 ( L_127 ,
V_63 ) ;
V_63 = 1 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_37 ( L_128 ,
V_120 ) ;
V_120 = 1 ;
}
if ( V_221 == V_7 ) {
if ( ! V_117 ) {
F_37 ( L_129 ) ;
F_37 ( L_130 ) ;
V_117 = 100 ;
}
}
if ( V_450 < 1 || V_450 > 255 ) {
F_37 ( L_131
L_132 ,
V_450 , V_451 ) ;
V_450 = V_451 ;
}
if ( ( V_452 != 0 ) && ( V_452 != 1 ) ) {
F_37 ( L_133
L_134
L_135 , V_452 ) ;
V_452 = 0 ;
}
if ( V_124 < 0 || V_124 > 255 ) {
F_37 ( L_136
L_137 ,
V_124 , V_453 ) ;
V_124 = V_453 ;
}
if ( ( V_221 == V_8 ) ||
( V_221 == V_9 ) ) {
if ( ! V_117 ) {
F_37 ( L_138 ) ;
F_37 ( L_130 ) ;
V_117 = 100 ;
}
}
if ( V_221 == V_9 ) {
F_290 ( L_139 ,
V_109 ) ;
}
if ( ! V_117 ) {
if ( V_109 || V_232 ) {
F_37 ( L_140 ,
V_109 , V_232 ) ;
}
} else {
if ( V_169 ) {
F_37 ( L_141 ,
V_117 , V_169 ) ;
V_169 = 0 ;
}
if ( ( V_109 % V_117 ) != 0 ) {
F_37 ( L_142 ,
V_109 , V_117 ,
( V_109 / V_117 ) * V_117 ) ;
}
V_109 /= V_117 ;
if ( ( V_232 % V_117 ) != 0 ) {
F_37 ( L_143 ,
V_232 , V_117 ,
( V_232 / V_117 ) * V_117 ) ;
}
V_232 /= V_117 ;
}
if ( V_169 < 0 ) {
F_37 ( L_144 ,
V_169 , V_447 , V_454 ) ;
V_169 = V_454 ;
}
for ( V_455 = 0 ;
( V_455 < V_246 ) && V_456 [ V_455 ] ;
V_455 ++ ) {
T_8 V_237 = F_291 ( V_456 [ V_455 ] ) ;
if ( ! isdigit ( V_456 [ V_455 ] [ 0 ] ) ||
V_237 == 0 || V_237 == F_292 ( V_457 ) ) {
F_37 ( L_145 ,
V_456 [ V_455 ] ) ;
V_169 = 0 ;
} else {
V_458 [ V_455 ] = V_237 ;
}
}
if ( V_169 && ! V_455 ) {
F_37 ( L_146 ,
V_169 ) ;
V_169 = 0 ;
}
if ( V_265 ) {
if ( V_221 != V_4 ) {
F_32 ( L_147 ) ;
return - V_188 ;
}
if ( ! V_169 ) {
F_32 ( L_148 ) ;
return - V_188 ;
}
V_434 = F_288 ( V_265 ,
V_459 ) ;
if ( V_434 == - 1 ) {
F_32 ( L_149 ,
V_265 == NULL ? L_18 : V_265 ) ;
return - V_188 ;
}
} else
V_434 = 0 ;
if ( V_117 ) {
F_87 ( L_150 , V_117 ) ;
} else if ( V_169 ) {
int V_38 ;
F_87 ( L_151 ,
V_169 ,
V_459 [ V_434 ] . V_432 ,
V_455 ) ;
for ( V_38 = 0 ; V_38 < V_455 ; V_38 ++ )
F_87 ( L_152 , V_456 [ V_38 ] ) ;
F_87 ( L_153 ) ;
} else if ( V_446 ) {
F_3 ( L_154 ) ;
}
if ( V_209 && ! F_53 ( V_221 ) ) {
F_37 ( L_155 ,
V_209 , F_1 ( V_221 ) ) ;
V_209 = NULL ;
}
if ( V_209 && V_104 ) {
V_436 = F_288 ( V_104 ,
V_460 ) ;
if ( V_436 == - 1 ) {
F_32 ( L_156 ,
V_104 ==
NULL ? L_18 : V_104 ) ;
return - V_188 ;
}
} else {
V_436 = V_461 ;
}
if ( V_119 ) {
V_435 = F_288 ( V_119 ,
V_462 ) ;
if ( V_435 == - 1 ) {
F_32 ( L_157 ,
V_265 == NULL ? L_18 : V_265 ) ;
return - V_188 ;
}
if ( V_221 != V_4 )
F_37 ( L_158 ) ;
} else {
V_435 = V_463 ;
}
V_42 -> V_1 = V_221 ;
V_42 -> V_393 = V_438 ;
V_42 -> V_117 = V_117 ;
V_42 -> V_120 = V_120 ;
V_42 -> V_169 = V_169 ;
V_42 -> V_265 = V_434 ;
V_42 -> V_109 = V_109 ;
V_42 -> V_232 = V_232 ;
V_42 -> V_63 = V_63 ;
V_42 -> V_441 = V_441 ;
V_42 -> V_209 [ 0 ] = 0 ;
V_42 -> V_104 = V_436 ;
V_42 -> V_119 = V_435 ;
V_42 -> V_450 = V_450 ;
V_42 -> V_452 = V_452 ;
V_42 -> V_124 = V_124 ;
V_42 -> V_464 = V_464 ;
if ( V_209 ) {
strncpy ( V_42 -> V_209 , V_209 , V_69 ) ;
V_42 -> V_209 [ V_69 - 1 ] = 0 ;
}
memcpy ( V_42 -> V_243 , V_458 , sizeof( V_458 ) ) ;
return 0 ;
}
static void F_293 ( struct V_30 * V_15 ,
struct V_465 * V_398 ,
void * V_466 )
{
F_294 ( & V_398 -> V_467 ,
& V_468 ) ;
}
static void F_295 ( struct V_30 * V_15 )
{
F_294 ( & V_15 -> V_469 ,
& V_470 ) ;
F_296 ( V_15 , F_293 , NULL ) ;
V_15 -> V_471 = & V_472 ;
}
static int F_297 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_473 * V_474 = F_298 ( F_183 ( V_34 ) , V_475 ) ;
struct V_476 * V_477 = & ( F_299 ( V_11 ) ) ;
F_3 ( L_159 , V_34 -> V_16 ) ;
F_300 ( & ( V_477 -> V_478 ) ) ;
F_300 ( & ( V_477 -> V_479 ) ) ;
V_11 -> V_86 = F_301 ( V_34 -> V_16 ) ;
if ( ! V_11 -> V_86 )
return - V_18 ;
F_295 ( V_34 ) ;
F_7 ( & V_11 -> V_424 , & V_474 -> V_480 ) ;
F_302 ( V_11 ) ;
F_303 ( V_11 ) ;
if ( F_304 ( V_34 -> V_138 ) &&
V_34 -> V_139 == V_481 ) {
F_159 ( V_34 ) ;
V_11 -> V_193 = true ;
}
F_305 ( & V_11 -> V_369 ) ;
return 0 ;
}
static int F_306 ( struct V_482 * V_483 [] , struct V_482 * V_174 [] )
{
if ( V_483 [ V_484 ] ) {
if ( F_307 ( V_483 [ V_484 ] ) != V_94 )
return - V_188 ;
if ( ! F_258 ( F_308 ( V_483 [ V_484 ] ) ) )
return - V_384 ;
}
return 0 ;
}
static unsigned int F_309 ( void )
{
return V_450 ;
}
int F_310 ( struct V_345 * V_345 , const char * V_16 )
{
struct V_30 * V_34 ;
int V_21 ;
F_311 () ;
V_34 = F_312 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_160 ,
F_282 , V_450 ) ;
if ( ! V_34 ) {
F_32 ( L_161 , V_16 ) ;
F_174 () ;
return - V_18 ;
}
F_313 ( V_34 , V_345 ) ;
V_34 -> V_485 = & V_486 ;
V_21 = F_314 ( V_34 ) ;
F_43 ( V_34 ) ;
F_174 () ;
if ( V_21 < 0 )
F_279 ( V_34 ) ;
return V_21 ;
}
static int T_12 F_315 ( struct V_345 * V_345 )
{
struct V_473 * V_474 = F_298 ( V_345 , V_475 ) ;
V_474 -> V_345 = V_345 ;
F_5 ( & V_474 -> V_480 ) ;
F_316 ( V_474 ) ;
F_317 ( V_474 ) ;
return 0 ;
}
static void T_13 F_318 ( struct V_345 * V_345 )
{
struct V_473 * V_474 = F_298 ( V_345 , V_475 ) ;
struct V_10 * V_11 , * V_487 ;
F_319 ( V_365 ) ;
F_320 ( V_474 ) ;
F_321 ( V_474 ) ;
F_311 () ;
F_287 (bond, tmp_bond, &bn->dev_list, bond_list)
F_322 ( V_11 -> V_15 , & V_365 ) ;
F_323 ( & V_365 ) ;
F_174 () ;
}
static int T_14 F_324 ( void )
{
int V_38 ;
int V_21 ;
F_87 ( L_162 , V_488 ) ;
V_21 = F_289 ( & V_409 ) ;
if ( V_21 )
goto V_23;
V_21 = F_325 ( & V_489 ) ;
if ( V_21 )
goto V_23;
V_21 = F_326 ( & V_486 ) ;
if ( V_21 )
goto V_490;
F_327 () ;
for ( V_38 = 0 ; V_38 < V_446 ; V_38 ++ ) {
V_21 = F_310 ( & V_491 , NULL ) ;
if ( V_21 )
goto V_76;
}
F_328 ( & V_492 ) ;
V_23:
return V_21 ;
V_76:
F_329 ( & V_486 ) ;
V_490:
F_330 ( & V_489 ) ;
goto V_23;
}
static void T_15 F_331 ( void )
{
F_332 ( & V_492 ) ;
F_333 () ;
F_329 ( & V_486 ) ;
F_330 ( & V_489 ) ;
#ifdef F_147
F_334 ( F_335 ( & V_493 ) ) ;
#endif
}
