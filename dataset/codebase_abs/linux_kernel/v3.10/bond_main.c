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
static int F_28 ( struct V_30 * V_34 ,
T_1 V_35 , T_2 V_36 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_38 ;
int V_39 , V_21 ;
F_30 (bond, slave, i) {
V_21 = F_31 ( V_37 -> V_15 , V_35 , V_36 ) ;
if ( V_21 )
goto V_40;
}
V_21 = F_2 ( V_11 , V_36 ) ;
if ( V_21 ) {
F_32 ( L_14 ,
V_34 -> V_16 , V_36 ) ;
return V_21 ;
}
return 0 ;
V_40:
V_38 = V_37 ;
F_33 (bond, slave, i, bond->first_slave, stop_at)
F_34 ( V_37 -> V_15 , V_35 , V_36 ) ;
return V_21 ;
}
static int F_35 ( struct V_30 * V_34 ,
T_1 V_35 , T_2 V_36 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 ;
int V_39 , V_21 ;
F_30 (bond, slave, i)
F_34 ( V_37 -> V_15 , V_35 , V_36 ) ;
V_21 = F_9 ( V_11 , V_36 ) ;
if ( V_21 ) {
F_32 ( L_15 ,
V_34 -> V_16 , V_36 ) ;
return V_21 ;
}
return 0 ;
}
static void F_36 ( struct V_10 * V_11 , struct V_30 * V_31 )
{
struct V_13 * V_14 ;
int V_21 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_21 = F_31 ( V_31 , F_37 ( V_41 ) ,
V_14 -> V_12 ) ;
if ( V_21 )
F_38 ( L_16 ,
V_11 -> V_15 -> V_16 , V_14 -> V_12 ,
V_31 -> V_16 ) ;
}
}
static void F_39 ( struct V_10 * V_11 ,
struct V_30 * V_31 )
{
struct V_13 * V_14 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( ! V_14 -> V_12 )
continue;
F_34 ( V_31 , F_37 ( V_41 ) , V_14 -> V_12 ) ;
}
}
static int F_40 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 ;
if ( V_11 -> V_42 == 0 )
goto V_43;
if ( V_11 -> V_44 . V_1 == V_7 )
return F_41 ( V_11 ) ;
F_30 (bond, slave, i) {
if ( V_37 -> V_45 == V_46 ) {
if ( ! F_42 ( V_11 -> V_15 ) ) {
F_43 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
}
V_43:
if ( F_42 ( V_11 -> V_15 ) ) {
F_44 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
static void F_45 ( struct V_37 * V_37 )
{
struct V_30 * V_31 = V_37 -> V_15 ;
struct V_47 V_48 ;
T_3 V_49 ;
int V_21 ;
V_37 -> V_50 = V_51 ;
V_37 -> V_52 = V_53 ;
V_21 = F_46 ( V_31 , & V_48 ) ;
if ( V_21 < 0 )
return;
V_49 = F_47 ( & V_48 ) ;
if ( V_49 == 0 || V_49 == ( ( V_54 ) - 1 ) )
return;
switch ( V_48 . V_52 ) {
case V_55 :
case V_56 :
break;
default:
return;
}
V_37 -> V_50 = V_49 ;
V_37 -> V_52 = V_48 . V_52 ;
return;
}
static int F_48 ( struct V_10 * V_11 ,
struct V_30 * V_31 , int V_57 )
{
const struct V_58 * V_59 = V_31 -> V_60 ;
int (* F_49)( struct V_30 * , struct V_61 * , int );
struct V_61 V_62 ;
struct V_63 * V_64 ;
if ( ! V_57 && ! F_50 ( V_31 ) )
return 0 ;
if ( V_11 -> V_44 . V_65 )
return F_42 ( V_31 ) ? V_66 : 0 ;
if ( V_31 -> V_67 -> V_68 )
return V_31 -> V_67 -> V_68 ( V_31 ) ?
V_66 : 0 ;
F_49 = V_59 -> V_69 ;
if ( F_49 ) {
strncpy ( V_62 . V_70 , V_31 -> V_16 , V_71 ) ;
V_64 = F_51 ( & V_62 ) ;
if ( F_52 ( V_31 , & V_62 , V_72 ) == 0 ) {
V_64 -> V_73 = V_74 ;
if ( F_52 ( V_31 , & V_62 , V_75 ) == 0 )
return V_64 -> V_76 & V_66 ;
}
}
return V_57 ? - 1 : V_66 ;
}
static int F_53 ( struct V_10 * V_11 , int V_77 )
{
int V_78 = 0 ;
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
if ( V_11 -> V_79 ) {
V_78 = F_55 ( V_11 -> V_79 -> V_15 ,
V_77 ) ;
}
} else {
struct V_37 * V_37 ;
int V_39 ;
F_30 (bond, slave, i) {
V_78 = F_55 ( V_37 -> V_15 , V_77 ) ;
if ( V_78 )
return V_78 ;
}
}
return V_78 ;
}
static int F_56 ( struct V_10 * V_11 , int V_77 )
{
int V_78 = 0 ;
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
if ( V_11 -> V_79 ) {
V_78 = F_57 ( V_11 -> V_79 -> V_15 ,
V_77 ) ;
}
} else {
struct V_37 * V_37 ;
int V_39 ;
F_30 (bond, slave, i) {
V_78 = F_57 ( V_37 -> V_15 , V_77 ) ;
if ( V_78 )
return V_78 ;
}
}
return V_78 ;
}
static void F_58 ( struct V_10 * V_11 , void * V_80 )
{
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
if ( V_11 -> V_79 )
F_59 ( V_11 -> V_79 -> V_15 , V_80 ) ;
} else {
struct V_37 * V_37 ;
int V_39 ;
F_30 (bond, slave, i)
F_59 ( V_37 -> V_15 , V_80 ) ;
}
}
static void F_60 ( struct V_10 * V_11 , void * V_80 )
{
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
if ( V_11 -> V_79 )
F_61 ( V_11 -> V_79 -> V_15 , V_80 ) ;
} else {
struct V_37 * V_37 ;
int V_39 ;
F_30 (bond, slave, i) {
F_61 ( V_37 -> V_15 , V_80 ) ;
}
}
}
static void F_62 ( struct V_30 * V_15 )
{
struct V_81 * V_82 ;
V_82 = F_63 ( V_15 ) ;
if ( V_82 )
F_64 ( V_82 ) ;
}
static void F_65 ( struct V_10 * V_11 )
{
struct V_30 * V_34 , * V_83 , * V_84 ;
struct V_13 * V_14 ;
F_66 ( & V_11 -> V_20 ) ;
F_67 () ;
V_34 = V_11 -> V_15 ;
F_62 ( V_34 ) ;
V_84 = F_68 ( V_34 ) ;
if ( V_84 && V_84 -> V_85 & V_86 )
F_62 ( V_84 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_83 = F_69 ( V_34 , F_37 ( V_41 ) ,
V_14 -> V_12 ) ;
if ( V_83 )
F_62 ( V_83 ) ;
}
F_70 () ;
F_6 ( & V_11 -> V_87 ) ;
if ( V_11 -> V_88 > 1 ) {
V_11 -> V_88 -- ;
F_71 ( V_11 -> V_89 , & V_11 -> V_90 , V_91 / 5 ) ;
}
F_8 ( & V_11 -> V_87 ) ;
F_72 ( & V_11 -> V_20 ) ;
}
static void F_73 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = F_74 ( V_93 , struct V_10 ,
V_90 . V_93 ) ;
F_65 ( V_11 ) ;
}
static void F_75 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_94 * V_95 ;
F_76 (ha, bond_dev)
F_61 ( V_31 , V_95 -> V_80 ) ;
if ( V_11 -> V_44 . V_1 == V_7 ) {
T_4 V_96 [ V_97 ] = V_98 ;
F_61 ( V_31 , V_96 ) ;
}
}
static void F_77 ( struct V_10 * V_11 , struct V_37 * V_99 ,
struct V_37 * V_100 )
{
struct V_94 * V_95 ;
if ( ! F_54 ( V_11 -> V_44 . V_1 ) )
return;
if ( V_100 ) {
if ( V_11 -> V_15 -> V_101 & V_102 )
F_55 ( V_100 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_101 & V_103 )
F_57 ( V_100 -> V_15 , - 1 ) ;
F_78 ( V_11 -> V_15 ) ;
F_76 (ha, bond->dev)
F_61 ( V_100 -> V_15 , V_95 -> V_80 ) ;
F_79 ( V_11 -> V_15 ) ;
}
if ( V_99 ) {
if ( V_11 -> V_15 -> V_101 & V_102 )
F_55 ( V_99 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_101 & V_103 )
F_57 ( V_99 -> V_15 , 1 ) ;
F_78 ( V_11 -> V_15 ) ;
F_76 (ha, bond->dev)
F_59 ( V_99 -> V_15 , V_95 -> V_80 ) ;
F_79 ( V_11 -> V_15 ) ;
}
}
static void F_80 ( struct V_10 * V_11 ,
struct V_37 * V_99 ,
struct V_37 * V_100 )
__releases( &bond->curr_slave_lock
static bool F_81 ( struct V_10 * V_11 )
{
struct V_37 * V_104 = V_11 -> V_105 ;
struct V_37 * V_24 = V_11 -> V_79 ;
if ( ! V_104 || ! V_24 || V_24 -> V_45 != V_46 )
return true ;
if ( V_11 -> V_106 ) {
V_11 -> V_106 = false ;
return true ;
}
if ( V_11 -> V_44 . V_107 == V_108 &&
( V_104 -> V_50 < V_24 -> V_50 ||
( V_104 -> V_50 == V_24 -> V_50 && V_104 -> V_52 <= V_24 -> V_52 ) ) )
return false ;
if ( V_11 -> V_44 . V_107 == V_109 )
return false ;
return true ;
}
static struct V_37 * F_82 ( struct V_10 * V_11 )
{
struct V_37 * V_99 , * V_100 ;
struct V_37 * V_110 = NULL ;
int V_111 = V_11 -> V_44 . V_112 ;
int V_39 ;
V_99 = V_11 -> V_79 ;
if ( ! V_99 ) {
if ( V_11 -> V_42 > 0 )
V_99 = V_11 -> V_113 ;
else
return NULL ;
}
if ( ( V_11 -> V_105 ) &&
V_11 -> V_105 -> V_45 == V_46 &&
F_81 ( V_11 ) ) {
V_99 = V_11 -> V_105 ;
}
V_100 = V_99 ;
F_83 (bond, new_active, i, old_active) {
if ( V_99 -> V_45 == V_46 ) {
return V_99 ;
} else if ( V_99 -> V_45 == V_114 &&
F_84 ( V_99 -> V_15 ) ) {
if ( V_99 -> V_115 < V_111 ) {
V_111 = V_99 -> V_115 ;
V_110 = V_99 ;
}
}
}
return V_110 ;
}
static bool F_85 ( struct V_10 * V_11 )
{
struct V_37 * V_37 = V_11 -> V_79 ;
F_3 ( L_17 ,
V_11 -> V_15 -> V_16 , V_37 ? V_37 -> V_15 -> V_16 : L_18 ) ;
if ( ! V_37 || ! V_11 -> V_116 ||
F_86 ( V_117 , & V_37 -> V_15 -> V_118 ) )
return false ;
V_11 -> V_116 -- ;
return true ;
}
void F_87 ( struct V_10 * V_11 , struct V_37 * V_99 )
{
struct V_37 * V_100 = V_11 -> V_79 ;
if ( V_100 == V_99 )
return;
if ( V_99 ) {
V_99 -> V_119 = V_119 ;
if ( V_99 -> V_45 == V_114 ) {
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
F_88 ( L_19 ,
V_11 -> V_15 -> V_16 , V_99 -> V_15 -> V_16 ,
( V_11 -> V_44 . V_112 - V_99 -> V_115 ) * V_11 -> V_44 . V_120 ) ;
}
V_99 -> V_115 = 0 ;
V_99 -> V_45 = V_46 ;
if ( V_11 -> V_44 . V_1 == V_7 )
F_89 ( V_99 , V_46 ) ;
if ( F_13 ( V_11 ) )
F_90 ( V_11 , V_99 , V_46 ) ;
} else {
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
F_88 ( L_20 ,
V_11 -> V_15 -> V_16 , V_99 -> V_15 -> V_16 ) ;
}
}
}
if ( F_54 ( V_11 -> V_44 . V_1 ) )
F_77 ( V_11 , V_99 , V_100 ) ;
if ( F_13 ( V_11 ) ) {
F_91 ( V_11 , V_99 ) ;
if ( V_100 )
F_92 ( V_100 ) ;
if ( V_99 )
F_93 ( V_99 ) ;
} else {
V_11 -> V_79 = V_99 ;
}
if ( V_11 -> V_44 . V_1 == V_4 ) {
if ( V_100 )
F_92 ( V_100 ) ;
if ( V_99 ) {
bool V_121 = false ;
F_93 ( V_99 ) ;
if ( V_11 -> V_44 . V_122 )
F_80 ( V_11 , V_99 ,
V_100 ) ;
if ( F_50 ( V_11 -> V_15 ) ) {
V_11 -> V_116 =
V_11 -> V_44 . V_123 ;
V_121 =
F_85 ( V_11 ) ;
}
F_8 ( & V_11 -> V_87 ) ;
F_72 ( & V_11 -> V_20 ) ;
F_94 ( V_124 , V_11 -> V_15 ) ;
if ( V_121 )
F_94 ( V_125 ,
V_11 -> V_15 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_87 ) ;
}
}
if ( F_50 ( V_11 -> V_15 ) && ( V_11 -> V_44 . V_126 > 0 ) &&
( ( F_54 ( V_11 -> V_44 . V_1 ) && V_99 ) ||
V_11 -> V_44 . V_1 == V_3 ) ) {
V_11 -> V_88 = V_11 -> V_44 . V_126 ;
F_71 ( V_11 -> V_89 , & V_11 -> V_90 , 0 ) ;
}
}
void F_95 ( struct V_10 * V_11 )
{
struct V_37 * V_127 ;
int V_128 ;
V_127 = F_82 ( V_11 ) ;
if ( V_127 != V_11 -> V_79 ) {
F_87 ( V_11 , V_127 ) ;
V_128 = F_40 ( V_11 ) ;
if ( ! V_128 )
return;
if ( F_42 ( V_11 -> V_15 ) ) {
F_88 ( L_21 ,
V_11 -> V_15 -> V_16 ) ;
} else {
F_88 ( L_22 ,
V_11 -> V_15 -> V_16 ) ;
}
}
}
static void F_96 ( struct V_10 * V_11 , struct V_37 * V_129 )
{
if ( V_11 -> V_113 == NULL ) {
V_129 -> V_25 = V_129 ;
V_129 -> V_27 = V_129 ;
V_11 -> V_113 = V_129 ;
} else {
V_129 -> V_25 = V_11 -> V_113 ;
V_129 -> V_27 = V_11 -> V_113 -> V_27 ;
V_129 -> V_25 -> V_27 = V_129 ;
V_129 -> V_27 -> V_25 = V_129 ;
}
V_11 -> V_42 ++ ;
}
static void F_97 ( struct V_10 * V_11 , struct V_37 * V_37 )
{
if ( V_37 -> V_25 )
V_37 -> V_25 -> V_27 = V_37 -> V_27 ;
if ( V_37 -> V_27 )
V_37 -> V_27 -> V_25 = V_37 -> V_25 ;
if ( V_11 -> V_113 == V_37 ) {
if ( V_11 -> V_42 > 1 ) {
V_11 -> V_113 = V_37 -> V_25 ;
} else {
V_11 -> V_113 = NULL ;
}
}
V_37 -> V_25 = NULL ;
V_37 -> V_27 = NULL ;
V_11 -> V_42 -- ;
}
static inline int F_98 ( struct V_37 * V_37 )
{
struct V_130 * V_131 ;
int V_78 = 0 ;
V_131 = F_4 ( sizeof( * V_131 ) , V_132 ) ;
V_78 = - V_18 ;
if ( ! V_131 )
goto V_23;
V_78 = F_99 ( V_131 , V_37 -> V_15 , V_132 ) ;
if ( V_78 ) {
F_15 ( V_131 ) ;
goto V_23;
}
V_37 -> V_131 = V_131 ;
V_23:
return V_78 ;
}
static inline void F_100 ( struct V_37 * V_37 )
{
struct V_130 * V_131 = V_37 -> V_131 ;
if ( ! V_131 )
return;
V_37 -> V_131 = NULL ;
F_101 ( V_131 ) ;
}
static inline bool F_102 ( struct V_30 * V_31 )
{
if ( V_31 -> V_85 & V_133 )
return false ;
if ( ! V_31 -> V_60 -> V_134 )
return false ;
return true ;
}
static void F_103 ( struct V_30 * V_34 )
{
}
static void F_104 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 ;
F_30 (bond, slave, i)
if ( F_84 ( V_37 -> V_15 ) )
F_100 ( V_37 ) ;
}
static void F_105 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_104 ( V_11 ) ;
F_72 ( & V_11 -> V_20 ) ;
}
static int F_106 ( struct V_30 * V_15 , struct V_135 * V_136 , T_5 V_137 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
struct V_37 * V_37 ;
int V_39 , V_78 = 0 ;
F_66 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
V_78 = F_98 ( V_37 ) ;
if ( V_78 ) {
F_104 ( V_11 ) ;
break;
}
}
F_72 ( & V_11 -> V_20 ) ;
return V_78 ;
}
static struct V_135 * F_107 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_138 ;
}
static inline int F_98 ( struct V_37 * V_37 )
{
return 0 ;
}
static inline void F_100 ( struct V_37 * V_37 )
{
}
static void F_105 ( struct V_30 * V_34 )
{
}
static void F_108 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_3 ( L_23 , V_34 ) ;
F_3 ( L_24 , V_31 ) ;
F_3 ( L_25 , V_31 -> V_139 ) ;
memcpy ( V_34 -> V_140 , V_31 -> V_140 , V_31 -> V_139 ) ;
V_34 -> V_141 = V_142 ;
F_94 ( V_143 , V_34 ) ;
}
static T_6 F_109 ( struct V_30 * V_15 ,
T_6 V_144 )
{
struct V_37 * V_37 ;
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_6 V_145 ;
int V_39 ;
F_66 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_113 ) {
V_144 |= V_146 ;
goto V_23;
}
V_145 = V_144 ;
V_144 &= ~ V_147 ;
V_144 |= V_148 ;
F_30 (bond, slave, i) {
V_144 = F_110 ( V_144 ,
V_37 -> V_15 -> V_144 ,
V_145 ) ;
}
V_144 = F_111 ( V_144 , V_145 ) ;
V_23:
F_72 ( & V_11 -> V_20 ) ;
return V_144 ;
}
static void F_112 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
struct V_30 * V_34 = V_11 -> V_15 ;
T_6 V_149 = V_150 ;
unsigned short V_151 = V_152 ;
unsigned int V_153 = V_154 ;
T_2 V_155 = V_156 ;
int V_39 ;
unsigned int V_101 , V_157 = V_158 ;
F_66 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_113 )
goto V_159;
F_30 (bond, slave, i) {
V_149 = F_110 ( V_149 ,
V_37 -> V_15 -> V_149 , V_150 ) ;
V_157 &= V_37 -> V_15 -> V_85 ;
if ( V_37 -> V_15 -> V_160 > V_151 )
V_151 = V_37 -> V_15 -> V_160 ;
V_153 = F_113 ( V_153 , V_37 -> V_15 -> V_153 ) ;
V_155 = F_113 ( V_155 , V_37 -> V_15 -> V_155 ) ;
}
V_159:
V_34 -> V_149 = V_149 ;
V_34 -> V_160 = V_151 ;
V_34 -> V_155 = V_155 ;
F_114 ( V_34 , V_153 ) ;
V_101 = V_34 -> V_85 & ~ V_158 ;
V_34 -> V_85 = V_101 | V_157 ;
F_72 ( & V_11 -> V_20 ) ;
F_115 ( V_34 ) ;
}
static void F_116 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_34 -> V_161 = V_31 -> V_161 ;
V_34 -> type = V_31 -> type ;
V_34 -> V_160 = V_31 -> V_160 ;
V_34 -> V_139 = V_31 -> V_139 ;
memcpy ( V_34 -> V_162 , V_31 -> V_162 ,
V_31 -> V_139 ) ;
V_11 -> V_163 = 1 ;
}
static bool F_117 ( struct V_28 * V_29 ,
struct V_37 * V_37 ,
struct V_10 * V_11 )
{
if ( F_118 ( V_37 ) ) {
if ( V_11 -> V_44 . V_1 == V_9 &&
V_29 -> V_164 != V_165 &&
V_29 -> V_164 != V_166 )
return false ;
return true ;
}
return false ;
}
static T_7 F_119 ( struct V_28 * * V_167 )
{
struct V_28 * V_29 = * V_167 ;
struct V_37 * V_37 ;
struct V_10 * V_11 ;
int (* F_120)( const struct V_28 * , struct V_10 * ,
struct V_37 * );
int V_168 = V_169 ;
V_29 = F_121 ( V_29 , V_132 ) ;
if ( F_23 ( ! V_29 ) )
return V_170 ;
* V_167 = V_29 ;
V_37 = F_122 ( V_29 -> V_15 ) ;
V_11 = V_37 -> V_11 ;
if ( V_11 -> V_44 . V_171 )
V_37 -> V_15 -> V_172 = V_119 ;
F_120 = F_123 ( V_11 -> F_120 ) ;
if ( F_120 ) {
V_168 = F_120 ( V_29 , V_11 , V_37 ) ;
if ( V_168 == V_170 ) {
F_124 ( V_29 ) ;
return V_168 ;
}
}
if ( F_117 ( V_29 , V_37 , V_11 ) ) {
return V_173 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_44 . V_1 == V_9 &&
V_11 -> V_15 -> V_85 & V_174 &&
V_29 -> V_164 == V_175 ) {
if ( F_23 ( F_125 ( V_29 ,
V_29 -> V_176 - F_126 ( V_29 ) ) ) ) {
F_127 ( V_29 ) ;
return V_170 ;
}
memcpy ( F_128 ( V_29 ) -> V_177 , V_11 -> V_15 -> V_140 , V_97 ) ;
}
return V_168 ;
}
static int F_129 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
int V_78 ;
V_78 = F_130 ( V_31 , V_34 ) ;
if ( V_78 )
return V_78 ;
V_31 -> V_101 |= V_178 ;
F_131 ( V_179 , V_31 , V_178 ) ;
return 0 ;
}
static void F_132 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_133 ( V_31 , V_34 ) ;
V_31 -> V_101 &= ~ V_178 ;
F_131 ( V_179 , V_31 , V_178 ) ;
}
int F_134 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
const struct V_58 * V_59 = V_31 -> V_60 ;
struct V_37 * V_129 = NULL ;
struct V_94 * V_95 ;
struct V_180 V_80 ;
int V_181 ;
int V_21 = 0 ;
if ( ! V_11 -> V_44 . V_65 &&
V_31 -> V_67 -> V_68 == NULL &&
V_59 -> V_69 == NULL ) {
F_38 ( L_26 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_101 & V_178 ) {
F_3 ( L_27 ) ;
return - V_182 ;
}
if ( V_31 -> V_144 & V_146 ) {
F_3 ( L_28 , V_31 -> V_16 ) ;
if ( F_135 ( V_34 ) ) {
F_32 ( L_29 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
return - V_183 ;
} else {
F_38 ( L_30 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_34 -> V_16 ) ;
}
} else {
F_3 ( L_31 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_101 & V_184 ) ) {
F_32 ( L_32 ,
V_31 -> V_16 ) ;
V_21 = - V_183 ;
goto V_185;
}
if ( V_11 -> V_42 == 0 ) {
if ( V_34 -> type != V_31 -> type ) {
F_3 ( L_33 ,
V_34 -> V_16 ,
V_34 -> type , V_31 -> type ) ;
V_21 = F_94 ( V_186 ,
V_34 ) ;
V_21 = F_136 ( V_21 ) ;
if ( V_21 ) {
F_32 ( L_34 ,
V_34 -> V_16 ) ;
V_21 = - V_182 ;
goto V_185;
}
F_137 ( V_34 ) ;
F_138 ( V_34 ) ;
if ( V_31 -> type != V_187 )
F_116 ( V_34 , V_31 ) ;
else {
F_139 ( V_34 ) ;
V_34 -> V_85 &= ~ V_188 ;
}
F_94 ( V_189 ,
V_34 ) ;
}
} else if ( V_34 -> type != V_31 -> type ) {
F_32 ( L_35 ,
V_31 -> V_16 ,
V_31 -> type , V_34 -> type ) ;
V_21 = - V_190 ;
goto V_185;
}
if ( V_59 -> V_191 == NULL ) {
if ( V_11 -> V_42 == 0 ) {
F_38 ( L_36 ,
V_34 -> V_16 ) ;
V_11 -> V_44 . V_122 = V_192 ;
} else if ( V_11 -> V_44 . V_122 != V_192 ) {
F_32 ( L_37 ,
V_34 -> V_16 ) ;
V_21 = - V_193 ;
goto V_185;
}
}
F_94 ( V_194 , V_31 ) ;
if ( V_11 -> V_42 == 0 && V_11 -> V_195 )
F_108 ( V_11 -> V_15 , V_31 ) ;
V_129 = F_4 ( sizeof( struct V_37 ) , V_17 ) ;
if ( ! V_129 ) {
V_21 = - V_18 ;
goto V_185;
}
V_129 -> V_196 = 0 ;
V_129 -> V_197 = V_31 -> V_198 ;
V_21 = F_140 ( V_31 , V_11 -> V_15 -> V_198 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_199;
}
memcpy ( V_129 -> V_200 , V_31 -> V_140 , V_97 ) ;
if ( ! V_11 -> V_44 . V_122 ) {
memcpy ( V_80 . V_201 , V_34 -> V_140 , V_34 -> V_139 ) ;
V_80 . V_202 = V_31 -> type ;
V_21 = F_141 ( V_31 , & V_80 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_203;
}
}
V_21 = F_129 ( V_34 , V_31 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_21 ) ;
goto V_204;
}
V_21 = F_142 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_41 , V_31 -> V_16 ) ;
goto V_205;
}
V_129 -> V_11 = V_11 ;
V_129 -> V_15 = V_31 ;
V_31 -> V_85 |= V_206 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_143 ( V_11 , V_129 ) ;
if ( V_21 )
goto V_207;
}
if ( ! F_54 ( V_11 -> V_44 . V_1 ) ) {
if ( V_34 -> V_101 & V_102 ) {
V_21 = F_55 ( V_31 , 1 ) ;
if ( V_21 )
goto V_207;
}
if ( V_34 -> V_101 & V_103 ) {
V_21 = F_57 ( V_31 , 1 ) ;
if ( V_21 )
goto V_207;
}
F_78 ( V_34 ) ;
F_76 (ha, bond_dev)
F_59 ( V_31 , V_95 -> V_80 ) ;
F_79 ( V_34 ) ;
}
if ( V_11 -> V_44 . V_1 == V_7 ) {
T_4 V_96 [ V_97 ] = V_98 ;
F_59 ( V_31 , V_96 ) ;
}
F_36 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_96 ( V_11 , V_129 ) ;
V_129 -> V_115 = 0 ;
V_129 -> V_208 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_112 ( V_11 ) ;
F_45 ( V_129 ) ;
F_66 ( & V_11 -> V_20 ) ;
V_129 -> V_209 = V_119 -
( F_144 ( V_11 -> V_44 . V_171 ) + 1 ) ;
if ( V_11 -> V_44 . V_120 && ! V_11 -> V_44 . V_65 ) {
V_181 = F_48 ( V_11 , V_31 , 1 ) ;
if ( ( V_181 == - 1 ) && ! V_11 -> V_44 . V_171 ) {
F_38 ( L_42 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_181 == - 1 ) {
F_38 ( L_43 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
}
if ( V_11 -> V_44 . V_120 ) {
if ( F_48 ( V_11 , V_31 , 0 ) == V_66 ) {
if ( V_11 -> V_44 . V_112 ) {
V_129 -> V_45 = V_114 ;
V_129 -> V_115 = V_11 -> V_44 . V_112 ;
} else {
V_129 -> V_45 = V_46 ;
}
} else {
V_129 -> V_45 = V_210 ;
}
} else if ( V_11 -> V_44 . V_171 ) {
V_129 -> V_45 = ( F_42 ( V_31 ) ?
V_46 : V_210 ) ;
} else {
V_129 -> V_45 = V_46 ;
}
if ( V_129 -> V_45 != V_210 )
V_129 -> V_119 = V_119 ;
F_3 ( L_44 ,
V_129 -> V_45 == V_210 ? L_45 :
( V_129 -> V_45 == V_46 ? L_46 : L_47 ) ) ;
if ( F_54 ( V_11 -> V_44 . V_1 ) && V_11 -> V_44 . V_211 [ 0 ] ) {
if ( strcmp ( V_11 -> V_44 . V_211 , V_129 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_105 = V_129 ;
V_11 -> V_106 = true ;
}
}
F_6 ( & V_11 -> V_87 ) ;
switch ( V_11 -> V_44 . V_1 ) {
case V_4 :
F_92 ( V_129 ) ;
F_95 ( V_11 ) ;
break;
case V_7 :
F_92 ( V_129 ) ;
if ( V_11 -> V_42 == 1 ) {
F_145 ( V_129 ) . V_212 = 1 ;
F_146 ( V_11 , 1000 / V_213 ) ;
} else {
F_145 ( V_129 ) . V_212 =
F_145 ( V_129 -> V_27 ) . V_212 + 1 ;
}
F_147 ( V_129 ) ;
break;
case V_8 :
case V_9 :
F_148 ( V_129 ) ;
F_92 ( V_129 ) ;
F_95 ( V_11 ) ;
break;
default:
F_3 ( L_48 ) ;
F_148 ( V_129 ) ;
if ( ! V_11 -> V_79 && V_129 -> V_45 == V_46 )
V_11 -> V_79 = V_129 ;
break;
}
F_8 ( & V_11 -> V_87 ) ;
F_40 ( V_11 ) ;
#ifdef F_149
V_31 -> V_138 = F_107 ( V_11 ) ;
if ( V_31 -> V_138 ) {
if ( F_98 ( V_129 ) ) {
F_72 ( & V_11 -> V_20 ) ;
F_88 ( L_49
L_50 ,
V_34 -> V_16 ) ;
V_21 = - V_182 ;
goto V_214;
}
}
#endif
F_72 ( & V_11 -> V_20 ) ;
V_21 = F_150 ( V_34 , V_31 ) ;
if ( V_21 )
goto V_214;
V_21 = F_151 ( V_31 , F_119 ,
V_129 ) ;
if ( V_21 ) {
F_3 ( L_51 , V_21 ) ;
goto V_215;
}
F_88 ( L_52 ,
V_34 -> V_16 , V_31 -> V_16 ,
F_152 ( V_129 ) ? L_53 : L_54 ,
V_129 -> V_45 != V_210 ? L_55 : L_56 ) ;
return 0 ;
V_215:
F_153 ( V_34 , V_31 ) ;
V_214:
if ( ! F_54 ( V_11 -> V_44 . V_1 ) ) {
F_78 ( V_34 ) ;
F_75 ( V_34 , V_31 ) ;
F_79 ( V_34 ) ;
}
F_39 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_97 ( V_11 , V_129 ) ;
if ( V_11 -> V_105 == V_129 )
V_11 -> V_105 = NULL ;
if ( V_11 -> V_79 == V_129 ) {
F_87 ( V_11 , NULL ) ;
F_8 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_87 ) ;
F_95 ( V_11 ) ;
F_8 ( & V_11 -> V_87 ) ;
F_72 ( & V_11 -> V_20 ) ;
} else {
F_8 ( & V_11 -> V_20 ) ;
}
F_100 ( V_129 ) ;
V_207:
V_31 -> V_85 &= ~ V_206 ;
F_154 ( V_31 ) ;
V_205:
F_132 ( V_34 , V_31 ) ;
V_204:
if ( ! V_11 -> V_44 . V_122 ) {
memcpy ( V_80 . V_201 , V_129 -> V_200 , V_97 ) ;
V_80 . V_202 = V_31 -> type ;
F_141 ( V_31 , & V_80 ) ;
}
V_203:
F_140 ( V_31 , V_129 -> V_197 ) ;
V_199:
F_15 ( V_129 ) ;
V_185:
F_112 ( V_11 ) ;
if ( V_11 -> V_42 == 0 &&
F_155 ( V_34 -> V_140 , V_31 -> V_140 ) )
F_156 ( V_34 ) ;
return V_21 ;
}
static int F_157 ( struct V_30 * V_34 ,
struct V_30 * V_31 ,
bool V_216 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_217 ;
struct V_180 V_80 ;
T_6 V_218 = V_34 -> V_144 ;
if ( ! ( V_31 -> V_101 & V_178 ) ||
! F_158 ( V_31 , V_34 ) ) {
F_32 ( L_57 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
return - V_190 ;
}
F_10 () ;
F_6 ( & V_11 -> V_20 ) ;
V_37 = F_26 ( V_11 , V_31 ) ;
if ( ! V_37 ) {
F_88 ( L_58 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_190 ;
}
F_8 ( & V_11 -> V_20 ) ;
F_159 ( V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_216 && ! V_11 -> V_44 . V_122 ) {
if ( F_155 ( V_34 -> V_140 , V_37 -> V_200 ) &&
V_11 -> V_42 > 1 )
F_38 ( L_59 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_37 -> V_200 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_44 . V_1 == V_7 ) {
F_160 ( V_37 ) ;
}
F_88 ( L_60 ,
V_34 -> V_16 ,
F_152 ( V_37 ) ? L_61 : L_62 ,
V_31 -> V_16 ) ;
V_217 = V_11 -> V_79 ;
V_11 -> V_219 = NULL ;
F_97 ( V_11 , V_37 ) ;
if ( V_11 -> V_105 == V_37 )
V_11 -> V_105 = NULL ;
if ( V_217 == V_37 )
F_87 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_161 ( V_11 , V_37 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_216 ) {
V_11 -> V_79 = NULL ;
} else if ( V_217 == V_37 ) {
F_8 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_87 ) ;
F_95 ( V_11 ) ;
F_8 ( & V_11 -> V_87 ) ;
F_72 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_42 == 0 ) {
F_40 ( V_11 ) ;
F_156 ( V_34 ) ;
V_11 -> V_195 = true ;
if ( F_162 ( V_11 ) ) {
F_38 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_38 ( L_64 ,
V_34 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
if ( V_11 -> V_42 == 0 ) {
F_94 ( V_143 , V_11 -> V_15 ) ;
F_94 ( V_220 , V_11 -> V_15 ) ;
}
F_112 ( V_11 ) ;
if ( ! ( V_34 -> V_144 & V_146 ) &&
( V_218 & V_146 ) )
F_88 ( L_65 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
F_153 ( V_34 , V_31 ) ;
F_39 ( V_11 , V_31 ) ;
if ( ! F_54 ( V_11 -> V_44 . V_1 ) ) {
if ( V_34 -> V_101 & V_102 )
F_55 ( V_31 , - 1 ) ;
if ( V_34 -> V_101 & V_103 )
F_57 ( V_31 , - 1 ) ;
F_78 ( V_34 ) ;
F_75 ( V_34 , V_31 ) ;
F_79 ( V_34 ) ;
}
F_132 ( V_34 , V_31 ) ;
F_100 ( V_37 ) ;
F_154 ( V_31 ) ;
if ( V_11 -> V_44 . V_122 != V_192 ) {
memcpy ( V_80 . V_201 , V_37 -> V_200 , V_97 ) ;
V_80 . V_202 = V_31 -> type ;
F_141 ( V_31 , & V_80 ) ;
}
F_140 ( V_31 , V_37 -> V_197 ) ;
V_31 -> V_85 &= ~ V_206 ;
F_15 ( V_37 ) ;
return 0 ;
}
int F_163 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
return F_157 ( V_34 , V_31 , false ) ;
}
static int F_164 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_168 ;
V_168 = F_163 ( V_34 , V_31 ) ;
if ( ( V_168 == 0 ) && ( V_11 -> V_42 == 0 ) ) {
V_34 -> V_85 |= V_133 ;
F_88 ( L_66 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_165 ( V_34 ) ;
}
return V_168 ;
}
static int F_166 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_100 = NULL ;
struct V_37 * V_99 = NULL ;
int V_21 = 0 ;
if ( ! F_54 ( V_11 -> V_44 . V_1 ) )
return - V_190 ;
if ( ! ( V_31 -> V_101 & V_178 ) ||
! F_158 ( V_31 , V_34 ) )
return - V_190 ;
F_66 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_87 ) ;
V_100 = V_11 -> V_79 ;
F_72 ( & V_11 -> V_87 ) ;
V_99 = F_26 ( V_11 , V_31 ) ;
if ( V_99 && ( V_99 == V_100 ) ) {
F_72 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_99 ) &&
( V_100 ) &&
( V_99 -> V_45 == V_46 ) &&
F_84 ( V_99 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_87 ) ;
F_87 ( V_11 , V_99 ) ;
F_8 ( & V_11 -> V_87 ) ;
F_16 () ;
} else
V_21 = - V_190 ;
F_72 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_167 ( struct V_30 * V_34 , struct V_221 * V_222 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_222 -> V_223 = V_11 -> V_44 . V_1 ;
V_222 -> V_120 = V_11 -> V_44 . V_120 ;
F_66 ( & V_11 -> V_20 ) ;
V_222 -> V_224 = V_11 -> V_42 ;
F_72 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_168 ( struct V_30 * V_34 , struct V_225 * V_222 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 ;
int V_39 , V_21 = - V_22 ;
F_66 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
if ( V_39 == ( int ) V_222 -> V_226 ) {
V_21 = 0 ;
strcpy ( V_222 -> V_227 , V_37 -> V_15 -> V_16 ) ;
V_222 -> V_45 = V_37 -> V_45 ;
V_222 -> V_118 = F_169 ( V_37 ) ;
V_222 -> V_208 = V_37 -> V_208 ;
break;
}
}
F_72 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_170 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 , V_228 , V_229 = 0 ;
bool V_230 ;
V_230 = ! V_11 -> V_79 ? true : false ;
F_30 (bond, slave, i) {
V_37 -> V_231 = V_232 ;
V_228 = F_48 ( V_11 , V_37 -> V_15 , 0 ) ;
switch ( V_37 -> V_45 ) {
case V_46 :
if ( V_228 )
continue;
V_37 -> V_45 = V_233 ;
V_37 -> V_115 = V_11 -> V_44 . V_234 ;
if ( V_37 -> V_115 ) {
F_88 ( L_67 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_44 . V_1 ==
V_4 ) ?
( F_152 ( V_37 ) ?
L_68 : L_69 ) : L_70 ,
V_37 -> V_15 -> V_16 ,
V_11 -> V_44 . V_234 * V_11 -> V_44 . V_120 ) ;
}
case V_233 :
if ( V_228 ) {
V_37 -> V_45 = V_46 ;
V_37 -> V_119 = V_119 ;
F_88 ( L_71 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_44 . V_234 - V_37 -> V_115 ) *
V_11 -> V_44 . V_120 ,
V_37 -> V_15 -> V_16 ) ;
continue;
}
if ( V_37 -> V_115 <= 0 ) {
V_37 -> V_231 = V_210 ;
V_229 ++ ;
continue;
}
V_37 -> V_115 -- ;
break;
case V_210 :
if ( ! V_228 )
continue;
V_37 -> V_45 = V_114 ;
V_37 -> V_115 = V_11 -> V_44 . V_112 ;
if ( V_37 -> V_115 ) {
F_88 ( L_72 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ,
V_230 ? 0 :
V_11 -> V_44 . V_112 *
V_11 -> V_44 . V_120 ) ;
}
case V_114 :
if ( ! V_228 ) {
V_37 -> V_45 = V_210 ;
F_88 ( L_73 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_44 . V_112 - V_37 -> V_115 ) *
V_11 -> V_44 . V_120 ,
V_37 -> V_15 -> V_16 ) ;
continue;
}
if ( V_230 )
V_37 -> V_115 = 0 ;
if ( V_37 -> V_115 <= 0 ) {
V_37 -> V_231 = V_46 ;
V_229 ++ ;
V_230 = false ;
continue;
}
V_37 -> V_115 -- ;
break;
}
}
return V_229 ;
}
static void F_171 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 ;
F_30 (bond, slave, i) {
switch ( V_37 -> V_231 ) {
case V_232 :
continue;
case V_46 :
V_37 -> V_45 = V_46 ;
V_37 -> V_119 = V_119 ;
if ( V_11 -> V_44 . V_1 == V_7 ) {
F_172 ( V_37 ) ;
} else if ( V_11 -> V_44 . V_1 != V_4 ) {
F_148 ( V_37 ) ;
} else if ( V_37 != V_11 -> V_105 ) {
F_172 ( V_37 ) ;
}
F_88 ( L_74 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ,
V_37 -> V_50 == V_51 ? 0 : V_37 -> V_50 ,
V_37 -> V_52 ? L_75 : L_76 ) ;
if ( V_11 -> V_44 . V_1 == V_7 )
F_89 ( V_37 , V_46 ) ;
if ( F_13 ( V_11 ) )
F_90 ( V_11 , V_37 ,
V_46 ) ;
if ( ! V_11 -> V_79 ||
( V_37 == V_11 -> V_105 ) )
goto V_235;
continue;
case V_210 :
if ( V_37 -> V_208 < V_236 )
V_37 -> V_208 ++ ;
V_37 -> V_45 = V_210 ;
if ( V_11 -> V_44 . V_1 == V_4 ||
V_11 -> V_44 . V_1 == V_7 )
F_92 ( V_37 ) ;
F_88 ( L_77 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ) ;
if ( V_11 -> V_44 . V_1 == V_7 )
F_89 ( V_37 ,
V_210 ) ;
if ( F_13 ( V_11 ) )
F_90 ( V_11 , V_37 ,
V_210 ) ;
if ( V_37 == V_11 -> V_79 )
goto V_235;
continue;
default:
F_32 ( L_78 ,
V_11 -> V_15 -> V_16 , V_37 -> V_231 ,
V_37 -> V_15 -> V_16 ) ;
V_37 -> V_231 = V_232 ;
continue;
}
V_235:
F_173 () ;
F_10 () ;
F_6 ( & V_11 -> V_87 ) ;
F_95 ( V_11 ) ;
F_8 ( & V_11 -> V_87 ) ;
F_16 () ;
}
F_40 ( V_11 ) ;
}
void F_174 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = F_74 ( V_93 , struct V_10 ,
V_237 . V_93 ) ;
bool V_121 = false ;
unsigned long V_115 ;
F_66 ( & V_11 -> V_20 ) ;
V_115 = F_144 ( V_11 -> V_44 . V_120 ) ;
if ( V_11 -> V_42 == 0 )
goto V_238;
V_121 = F_85 ( V_11 ) ;
if ( F_170 ( V_11 ) ) {
F_72 ( & V_11 -> V_20 ) ;
if ( ! F_175 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_115 = 1 ;
V_121 = false ;
goto V_238;
}
F_66 ( & V_11 -> V_20 ) ;
F_171 ( V_11 ) ;
F_72 ( & V_11 -> V_20 ) ;
F_176 () ;
F_66 ( & V_11 -> V_20 ) ;
}
V_238:
if ( V_11 -> V_44 . V_120 )
F_71 ( V_11 -> V_89 , & V_11 -> V_237 , V_115 ) ;
F_72 ( & V_11 -> V_20 ) ;
if ( V_121 ) {
if ( ! F_175 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_11 -> V_116 ++ ;
F_72 ( & V_11 -> V_20 ) ;
return;
}
F_94 ( V_125 , V_11 -> V_15 ) ;
F_176 () ;
}
}
static int F_177 ( struct V_10 * V_11 , T_8 V_239 )
{
struct V_13 * V_14 ;
struct V_30 * V_83 ;
if ( V_239 == F_178 ( V_11 -> V_15 , 0 , V_239 ) )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_67 () ;
V_83 = F_69 ( V_11 -> V_15 , F_37 ( V_41 ) ,
V_14 -> V_12 ) ;
F_70 () ;
if ( V_83 && V_239 == F_178 ( V_83 , 0 , V_239 ) )
return 1 ;
}
return 0 ;
}
static void F_179 ( struct V_30 * V_31 , int V_240 , T_8 V_241 , T_8 V_242 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_79 , V_240 ,
V_31 -> V_16 , & V_241 , & V_242 , V_12 ) ;
V_29 = F_180 ( V_240 , V_243 , V_241 , V_31 , V_242 ,
NULL , V_31 -> V_140 , NULL ) ;
if ( ! V_29 ) {
F_32 ( L_80 ) ;
return;
}
if ( V_12 ) {
V_29 = F_181 ( V_29 , F_37 ( V_41 ) , V_12 ) ;
if ( ! V_29 ) {
F_32 ( L_81 ) ;
return;
}
}
F_182 ( V_29 ) ;
}
static void F_183 ( struct V_10 * V_11 , struct V_37 * V_37 )
{
int V_39 , V_12 ;
T_8 * V_244 = V_11 -> V_44 . V_245 ;
struct V_13 * V_14 ;
struct V_30 * V_83 = NULL ;
struct V_246 * V_247 ;
for ( V_39 = 0 ; ( V_39 < V_248 ) ; V_39 ++ ) {
T_8 V_80 ;
if ( ! V_244 [ V_39 ] )
break;
F_3 ( L_82 , & V_244 [ V_39 ] ) ;
if ( ! F_162 ( V_11 ) ) {
F_3 ( L_83 ) ;
V_80 = F_178 ( V_11 -> V_15 , V_244 [ V_39 ] , 0 ) ;
F_179 ( V_37 -> V_15 , V_249 , V_244 [ V_39 ] ,
V_80 , 0 ) ;
continue;
}
V_247 = F_184 ( F_185 ( V_11 -> V_15 ) , V_244 [ V_39 ] , 0 ,
V_250 , 0 ) ;
if ( F_186 ( V_247 ) ) {
if ( F_187 () ) {
F_38 ( L_84 ,
V_11 -> V_15 -> V_16 , & V_244 [ V_39 ] ) ;
}
continue;
}
if ( V_247 -> V_251 . V_15 == V_11 -> V_15 ) {
F_188 ( V_247 ) ;
F_3 ( L_85 ) ;
V_80 = F_178 ( V_11 -> V_15 , V_244 [ V_39 ] , 0 ) ;
F_179 ( V_37 -> V_15 , V_249 , V_244 [ V_39 ] ,
V_80 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_67 () ;
V_83 = F_69 ( V_11 -> V_15 ,
F_37 ( V_41 ) ,
V_14 -> V_12 ) ;
F_70 () ;
if ( V_83 == V_247 -> V_251 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_86 ,
V_83 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 && V_83 ) {
F_188 ( V_247 ) ;
V_80 = F_178 ( V_83 , V_244 [ V_39 ] , 0 ) ;
F_179 ( V_37 -> V_15 , V_249 , V_244 [ V_39 ] ,
V_80 , V_12 ) ;
continue;
}
if ( F_187 () ) {
F_38 ( L_87 ,
V_11 -> V_15 -> V_16 , & V_244 [ V_39 ] ,
V_247 -> V_251 . V_15 ? V_247 -> V_251 . V_15 -> V_16 : L_18 ) ;
}
F_188 ( V_247 ) ;
}
}
static void F_189 ( struct V_10 * V_11 , struct V_37 * V_37 , T_8 V_252 , T_8 V_253 )
{
int V_39 ;
T_8 * V_244 = V_11 -> V_44 . V_245 ;
for ( V_39 = 0 ; ( V_39 < V_248 ) && V_244 [ V_39 ] ; V_39 ++ ) {
F_3 ( L_88 ,
& V_252 , & V_253 , V_39 , & V_244 [ V_39 ] ,
F_177 ( V_11 , V_253 ) ) ;
if ( V_252 == V_244 [ V_39 ] ) {
if ( F_177 ( V_11 , V_253 ) )
V_37 -> V_209 = V_119 ;
return;
}
}
}
static int F_190 ( const struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_37 * V_37 )
{
struct V_254 * V_255 = (struct V_254 * ) V_29 -> V_176 ;
unsigned char * V_256 ;
T_8 V_252 , V_253 ;
int V_257 ;
if ( V_29 -> V_258 != F_191 ( V_243 ) )
return V_169 ;
F_66 ( & V_11 -> V_20 ) ;
V_257 = F_192 ( V_11 -> V_15 ) ;
F_3 ( L_89 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( V_257 > F_193 ( V_29 ) ) {
V_255 = F_194 ( V_257 , V_132 ) ;
if ( ! V_255 )
goto V_259;
if ( F_195 ( V_29 , 0 , V_255 , V_257 ) < 0 )
goto V_259;
}
if ( V_255 -> V_260 != V_11 -> V_15 -> V_139 ||
V_29 -> V_164 == V_261 ||
V_29 -> V_164 == V_262 ||
V_255 -> V_263 != F_37 ( V_187 ) ||
V_255 -> V_264 != F_37 ( V_265 ) ||
V_255 -> V_266 != 4 )
goto V_259;
V_256 = ( unsigned char * ) ( V_255 + 1 ) ;
V_256 += V_11 -> V_15 -> V_139 ;
memcpy ( & V_252 , V_256 , 4 ) ;
V_256 += 4 + V_11 -> V_15 -> V_139 ;
memcpy ( & V_253 , V_256 , 4 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 , F_169 ( V_37 ) ,
V_11 -> V_44 . V_267 , F_196 ( V_11 , V_37 ) ,
& V_252 , & V_253 ) ;
if ( F_152 ( V_37 ) )
F_189 ( V_11 , V_37 , V_252 , V_253 ) ;
else
F_189 ( V_11 , V_37 , V_253 , V_252 ) ;
V_259:
F_72 ( & V_11 -> V_20 ) ;
if ( V_255 != (struct V_254 * ) V_29 -> V_176 )
F_15 ( V_255 ) ;
return V_169 ;
}
void F_197 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = F_74 ( V_93 , struct V_10 ,
V_268 . V_93 ) ;
struct V_37 * V_37 , * V_217 ;
int V_235 = 0 ;
int V_269 , V_270 ;
int V_39 ;
F_66 ( & V_11 -> V_20 ) ;
V_269 = F_144 ( V_11 -> V_44 . V_171 ) ;
V_270 = V_269 / 2 ;
if ( V_11 -> V_42 == 0 )
goto V_238;
F_66 ( & V_11 -> V_87 ) ;
V_217 = V_11 -> V_79 ;
F_72 ( & V_11 -> V_87 ) ;
F_30 (bond, slave, i) {
unsigned long V_271 = F_198 ( V_37 -> V_15 ) ;
if ( V_37 -> V_45 != V_46 ) {
if ( F_199 ( V_119 ,
V_271 - V_269 ,
V_271 + V_269 + V_270 ) &&
F_199 ( V_119 ,
V_37 -> V_15 -> V_172 - V_269 ,
V_37 -> V_15 -> V_172 + V_269 + V_270 ) ) {
V_37 -> V_45 = V_46 ;
F_148 ( V_37 ) ;
if ( ! V_217 ) {
F_88 ( L_91 ,
V_11 -> V_15 -> V_16 ,
V_37 -> V_15 -> V_16 ) ;
V_235 = 1 ;
} else {
F_88 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_37 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_199 ( V_119 ,
V_271 - V_269 ,
V_271 + 2 * V_269 + V_270 ) ||
! F_199 ( V_119 ,
V_37 -> V_15 -> V_172 - V_269 ,
V_37 -> V_15 -> V_172 + 2 * V_269 + V_270 ) ) {
V_37 -> V_45 = V_210 ;
F_172 ( V_37 ) ;
if ( V_37 -> V_208 < V_236 )
V_37 -> V_208 ++ ;
F_88 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_37 -> V_15 -> V_16 ) ;
if ( V_37 == V_217 )
V_235 = 1 ;
}
}
if ( F_84 ( V_37 -> V_15 ) )
F_183 ( V_11 , V_37 ) ;
}
if ( V_235 ) {
F_10 () ;
F_6 ( & V_11 -> V_87 ) ;
F_95 ( V_11 ) ;
F_8 ( & V_11 -> V_87 ) ;
F_16 () ;
}
V_238:
if ( V_11 -> V_44 . V_171 )
F_71 ( V_11 -> V_89 , & V_11 -> V_268 , V_269 ) ;
F_72 ( & V_11 -> V_20 ) ;
}
static int F_200 ( struct V_10 * V_11 , int V_269 )
{
struct V_37 * V_37 ;
int V_39 , V_229 = 0 ;
unsigned long V_271 ;
int V_270 ;
V_270 = V_269 / 2 ;
F_30 (bond, slave, i) {
V_37 -> V_231 = V_232 ;
if ( V_37 -> V_45 != V_46 ) {
if ( F_199 ( V_119 ,
F_201 ( V_11 , V_37 ) - V_269 ,
F_201 ( V_11 , V_37 ) + V_269 + V_270 ) ) {
V_37 -> V_231 = V_46 ;
V_229 ++ ;
}
continue;
}
if ( F_199 ( V_119 ,
V_37 -> V_119 - V_269 ,
V_37 -> V_119 + 2 * V_269 + V_270 ) )
continue;
if ( ! F_152 ( V_37 ) &&
! V_11 -> V_219 &&
! F_199 ( V_119 ,
F_201 ( V_11 , V_37 ) - V_269 ,
F_201 ( V_11 , V_37 ) + 3 * V_269 + V_270 ) ) {
V_37 -> V_231 = V_210 ;
V_229 ++ ;
}
V_271 = F_198 ( V_37 -> V_15 ) ;
if ( F_152 ( V_37 ) &&
( ! F_199 ( V_119 ,
V_271 - V_269 ,
V_271 + 2 * V_269 + V_270 ) ||
! F_199 ( V_119 ,
F_201 ( V_11 , V_37 ) - V_269 ,
F_201 ( V_11 , V_37 ) + 2 * V_269 + V_270 ) ) ) {
V_37 -> V_231 = V_210 ;
V_229 ++ ;
}
}
return V_229 ;
}
static void F_202 ( struct V_10 * V_11 , int V_269 )
{
struct V_37 * V_37 ;
int V_39 ;
unsigned long V_271 ;
F_30 (bond, slave, i) {
switch ( V_37 -> V_231 ) {
case V_232 :
continue;
case V_46 :
V_271 = F_198 ( V_37 -> V_15 ) ;
if ( ( ! V_11 -> V_79 &&
F_199 ( V_119 ,
V_271 - V_269 ,
V_271 + V_269 + V_269 / 2 ) ) ||
V_11 -> V_79 != V_37 ) {
V_37 -> V_45 = V_46 ;
if ( V_11 -> V_219 ) {
F_92 (
V_11 -> V_219 ) ;
V_11 -> V_219 = NULL ;
}
F_88 ( L_94 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_79 ||
( V_37 == V_11 -> V_105 ) )
goto V_235;
}
continue;
case V_210 :
if ( V_37 -> V_208 < V_236 )
V_37 -> V_208 ++ ;
V_37 -> V_45 = V_210 ;
F_92 ( V_37 ) ;
F_88 ( L_77 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ) ;
if ( V_37 == V_11 -> V_79 ) {
V_11 -> V_219 = NULL ;
goto V_235;
}
continue;
default:
F_32 ( L_95 ,
V_11 -> V_15 -> V_16 , V_37 -> V_231 ,
V_37 -> V_15 -> V_16 ) ;
continue;
}
V_235:
F_173 () ;
F_10 () ;
F_6 ( & V_11 -> V_87 ) ;
F_95 ( V_11 ) ;
F_8 ( & V_11 -> V_87 ) ;
F_16 () ;
}
F_40 ( V_11 ) ;
}
static void F_203 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 ;
F_66 ( & V_11 -> V_87 ) ;
if ( V_11 -> V_219 && V_11 -> V_79 )
F_88 ( L_96 ,
V_11 -> V_219 -> V_15 -> V_16 ,
V_11 -> V_79 -> V_15 -> V_16 ) ;
if ( V_11 -> V_79 ) {
F_183 ( V_11 , V_11 -> V_79 ) ;
F_72 ( & V_11 -> V_87 ) ;
return;
}
F_72 ( & V_11 -> V_87 ) ;
if ( ! V_11 -> V_219 ) {
V_11 -> V_219 = V_11 -> V_113 ;
if ( ! V_11 -> V_219 )
return;
}
F_92 ( V_11 -> V_219 ) ;
F_83 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_84 ( V_37 -> V_15 ) ) {
V_37 -> V_45 = V_114 ;
F_93 ( V_37 ) ;
F_183 ( V_11 , V_37 ) ;
V_37 -> V_119 = V_119 ;
V_11 -> V_219 = V_37 ;
break;
}
if ( V_37 -> V_45 == V_46 ) {
V_37 -> V_45 = V_210 ;
if ( V_37 -> V_208 < V_236 )
V_37 -> V_208 ++ ;
F_92 ( V_37 ) ;
F_88 ( L_97 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ) ;
}
}
}
void F_204 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = F_74 ( V_93 , struct V_10 ,
V_268 . V_93 ) ;
bool V_121 = false ;
int V_269 ;
F_66 ( & V_11 -> V_20 ) ;
V_269 = F_144 ( V_11 -> V_44 . V_171 ) ;
if ( V_11 -> V_42 == 0 )
goto V_238;
V_121 = F_85 ( V_11 ) ;
if ( F_200 ( V_11 , V_269 ) ) {
F_72 ( & V_11 -> V_20 ) ;
if ( ! F_175 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_269 = 1 ;
V_121 = false ;
goto V_238;
}
F_66 ( & V_11 -> V_20 ) ;
F_202 ( V_11 , V_269 ) ;
F_72 ( & V_11 -> V_20 ) ;
F_176 () ;
F_66 ( & V_11 -> V_20 ) ;
}
F_203 ( V_11 ) ;
V_238:
if ( V_11 -> V_44 . V_171 )
F_71 ( V_11 -> V_89 , & V_11 -> V_268 , V_269 ) ;
F_72 ( & V_11 -> V_20 ) ;
if ( V_121 ) {
if ( ! F_175 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_11 -> V_116 ++ ;
F_72 ( & V_11 -> V_20 ) ;
return;
}
F_94 ( V_125 , V_11 -> V_15 ) ;
F_176 () ;
}
}
static int F_205 ( struct V_10 * V_11 )
{
F_206 ( V_11 ) ;
F_207 ( V_11 ) ;
F_208 ( V_11 ) ;
return V_272 ;
}
static int F_209 ( unsigned long V_273 ,
struct V_30 * V_34 )
{
struct V_10 * V_274 = F_29 ( V_34 ) ;
switch ( V_273 ) {
case V_275 :
return F_205 ( V_274 ) ;
case V_276 :
F_206 ( V_274 ) ;
break;
case V_277 :
F_207 ( V_274 ) ;
break;
default:
break;
}
return V_272 ;
}
static int F_210 ( unsigned long V_273 ,
struct V_30 * V_31 )
{
struct V_37 * V_37 = F_211 ( V_31 ) ;
struct V_10 * V_11 ;
struct V_30 * V_34 ;
T_3 V_278 ;
T_4 V_279 ;
if ( ! V_37 )
return V_272 ;
V_34 = V_37 -> V_11 -> V_15 ;
V_11 = V_37 -> V_11 ;
switch ( V_273 ) {
case V_276 :
if ( V_11 -> V_163 )
F_164 ( V_34 , V_31 ) ;
else
F_163 ( V_34 , V_31 ) ;
break;
case V_280 :
case V_281 :
V_278 = V_37 -> V_50 ;
V_279 = V_37 -> V_52 ;
F_45 ( V_37 ) ;
if ( V_11 -> V_44 . V_1 == V_7 ) {
if ( V_278 != V_37 -> V_50 )
F_212 ( V_37 ) ;
if ( V_279 != V_37 -> V_52 )
F_213 ( V_37 ) ;
}
break;
case V_282 :
break;
case V_283 :
break;
case V_275 :
break;
case V_284 :
F_112 ( V_11 ) ;
break;
default:
break;
}
return V_272 ;
}
static int F_214 ( struct V_285 * V_286 ,
unsigned long V_273 , void * V_287 )
{
struct V_30 * V_288 = (struct V_30 * ) V_287 ;
F_3 ( L_98 ,
V_288 ? V_288 -> V_16 : L_10 ,
V_273 ) ;
if ( ! ( V_288 -> V_85 & V_206 ) )
return V_272 ;
if ( V_288 -> V_101 & V_289 ) {
F_3 ( L_99 ) ;
return F_209 ( V_273 , V_288 ) ;
}
if ( V_288 -> V_101 & V_178 ) {
F_3 ( L_100 ) ;
return F_210 ( V_273 , V_288 ) ;
}
return V_272 ;
}
static int F_215 ( struct V_28 * V_29 , int V_290 )
{
struct V_291 * V_176 = (struct V_291 * ) V_29 -> V_176 ;
if ( F_193 ( V_29 ) >= F_216 ( struct V_291 , V_292 ) )
return ( V_176 -> V_177 [ 5 ] ^ V_176 -> V_293 [ 5 ] ) % V_290 ;
return 0 ;
}
static int F_217 ( struct V_28 * V_29 , int V_290 )
{
const struct V_291 * V_176 ;
const struct V_294 * V_295 ;
const struct V_296 * V_297 ;
T_3 V_298 ;
const T_8 * V_299 , * V_300 ;
if ( V_29 -> V_258 == F_37 ( V_265 ) &&
F_218 ( V_29 , sizeof( * V_295 ) ) ) {
V_295 = F_219 ( V_29 ) ;
V_176 = (struct V_291 * ) V_29 -> V_176 ;
return ( ( F_220 ( V_295 -> V_301 ^ V_295 -> V_302 ) & 0xffff ) ^
( V_176 -> V_177 [ 5 ] ^ V_176 -> V_293 [ 5 ] ) ) % V_290 ;
} else if ( V_29 -> V_258 == F_37 ( V_303 ) &&
F_218 ( V_29 , sizeof( * V_297 ) ) ) {
V_297 = F_221 ( V_29 ) ;
V_176 = (struct V_291 * ) V_29 -> V_176 ;
V_299 = & V_297 -> V_301 . V_304 [ 0 ] ;
V_300 = & V_297 -> V_302 . V_304 [ 0 ] ;
V_298 = ( V_299 [ 1 ] ^ V_300 [ 1 ] ) ^ ( V_299 [ 2 ] ^ V_300 [ 2 ] ) ^ ( V_299 [ 3 ] ^ V_300 [ 3 ] ) ;
V_298 ^= ( V_298 >> 24 ) ^ ( V_298 >> 16 ) ^ ( V_298 >> 8 ) ;
return ( V_298 ^ V_176 -> V_177 [ 5 ] ^ V_176 -> V_293 [ 5 ] ) % V_290 ;
}
return F_215 ( V_29 , V_290 ) ;
}
static int F_222 ( struct V_28 * V_29 , int V_290 )
{
T_3 V_305 = 0 ;
const struct V_294 * V_295 ;
const struct V_296 * V_297 ;
const T_8 * V_299 , * V_300 ;
const T_1 * V_306 = NULL ;
T_1 V_307 [ 2 ] ;
int V_308 = F_223 ( V_29 ) ;
int V_309 ;
if ( V_29 -> V_258 == F_37 ( V_265 ) &&
F_224 ( V_29 , V_308 + sizeof( * V_295 ) ) ) {
V_295 = F_219 ( V_29 ) ;
V_309 = F_225 ( V_295 -> V_258 ) ;
if ( ! F_226 ( V_295 ) && V_309 >= 0 ) {
V_306 = F_227 ( V_29 , V_308 + ( V_295 -> V_310 << 2 ) + V_309 ,
sizeof( V_307 ) , & V_307 ) ;
if ( V_306 )
V_305 = F_228 ( V_306 [ 0 ] ^ V_306 [ 1 ] ) ;
}
return ( V_305 ^
( ( F_220 ( V_295 -> V_301 ^ V_295 -> V_302 ) ) & 0xffff ) ) % V_290 ;
} else if ( V_29 -> V_258 == F_37 ( V_303 ) &&
F_224 ( V_29 , V_308 + sizeof( * V_297 ) ) ) {
V_297 = F_221 ( V_29 ) ;
V_309 = F_225 ( V_297 -> V_311 ) ;
if ( V_309 >= 0 ) {
V_306 = F_227 ( V_29 , V_308 + sizeof( * V_297 ) + V_309 ,
sizeof( V_307 ) , & V_307 ) ;
if ( V_306 )
V_305 = F_228 ( V_306 [ 0 ] ^ V_306 [ 1 ] ) ;
}
V_299 = & V_297 -> V_301 . V_304 [ 0 ] ;
V_300 = & V_297 -> V_302 . V_304 [ 0 ] ;
V_305 ^= ( V_299 [ 1 ] ^ V_300 [ 1 ] ) ^ ( V_299 [ 2 ] ^ V_300 [ 2 ] ) ^ ( V_299 [ 3 ] ^ V_300 [ 3 ] ) ;
V_305 ^= ( V_305 >> 24 ) ^ ( V_305 >> 16 ) ^
( V_305 >> 8 ) ;
return V_305 % V_290 ;
}
return F_215 ( V_29 , V_290 ) ;
}
static void F_229 ( struct V_10 * V_11 )
{
F_230 ( & V_11 -> V_90 ,
F_73 ) ;
F_230 ( & V_11 -> V_312 , V_313 ) ;
F_230 ( & V_11 -> V_237 , F_174 ) ;
if ( V_11 -> V_44 . V_1 == V_4 )
F_230 ( & V_11 -> V_268 , F_204 ) ;
else
F_230 ( & V_11 -> V_268 , F_197 ) ;
F_230 ( & V_11 -> V_314 , V_315 ) ;
}
static void F_231 ( struct V_10 * V_11 )
{
F_232 ( & V_11 -> V_237 ) ;
F_232 ( & V_11 -> V_268 ) ;
F_232 ( & V_11 -> V_312 ) ;
F_232 ( & V_11 -> V_314 ) ;
F_232 ( & V_11 -> V_90 ) ;
}
static int F_233 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 ;
int V_39 ;
F_66 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_42 > 0 ) {
F_66 ( & V_11 -> V_87 ) ;
F_30 (bond, slave, i) {
if ( ( V_11 -> V_44 . V_1 == V_4 )
&& ( V_37 != V_11 -> V_79 ) ) {
F_92 ( V_37 ) ;
} else {
F_93 ( V_37 ) ;
}
}
F_72 ( & V_11 -> V_87 ) ;
}
F_72 ( & V_11 -> V_20 ) ;
F_229 ( V_11 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_234 ( V_11 , ( V_11 -> V_44 . V_1 == V_9 ) ) )
return - V_18 ;
F_71 ( V_11 -> V_89 , & V_11 -> V_312 , 0 ) ;
}
if ( V_11 -> V_44 . V_120 )
F_71 ( V_11 -> V_89 , & V_11 -> V_237 , 0 ) ;
if ( V_11 -> V_44 . V_171 ) {
F_71 ( V_11 -> V_89 , & V_11 -> V_268 , 0 ) ;
if ( V_11 -> V_44 . V_267 )
V_11 -> F_120 = F_190 ;
}
if ( V_11 -> V_44 . V_1 == V_7 ) {
F_71 ( V_11 -> V_89 , & V_11 -> V_314 , 0 ) ;
V_11 -> F_120 = V_316 ;
F_235 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_236 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_116 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_231 ( V_11 ) ;
if ( F_13 ( V_11 ) ) {
F_237 ( V_11 ) ;
}
V_11 -> F_120 = NULL ;
return 0 ;
}
static struct V_317 * F_238 ( struct V_30 * V_34 ,
struct V_317 * V_318 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_317 V_319 ;
struct V_37 * V_37 ;
int V_39 ;
memset ( V_318 , 0 , sizeof( * V_318 ) ) ;
F_239 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
const struct V_317 * V_320 =
F_240 ( V_37 -> V_15 , & V_319 ) ;
V_318 -> V_321 += V_320 -> V_321 ;
V_318 -> V_322 += V_320 -> V_322 ;
V_318 -> V_323 += V_320 -> V_323 ;
V_318 -> V_324 += V_320 -> V_324 ;
V_318 -> V_325 += V_320 -> V_325 ;
V_318 -> V_326 += V_320 -> V_326 ;
V_318 -> V_327 += V_320 -> V_327 ;
V_318 -> V_328 += V_320 -> V_328 ;
V_318 -> V_329 += V_320 -> V_329 ;
V_318 -> V_330 += V_320 -> V_330 ;
V_318 -> V_331 += V_320 -> V_331 ;
V_318 -> V_332 += V_320 -> V_332 ;
V_318 -> V_333 += V_320 -> V_333 ;
V_318 -> V_334 += V_320 -> V_334 ;
V_318 -> V_335 += V_320 -> V_335 ;
V_318 -> V_336 += V_320 -> V_336 ;
V_318 -> V_337 += V_320 -> V_337 ;
V_318 -> V_338 += V_320 -> V_338 ;
V_318 -> V_339 += V_320 -> V_339 ;
V_318 -> V_340 += V_320 -> V_340 ;
V_318 -> V_341 += V_320 -> V_341 ;
}
F_241 ( & V_11 -> V_20 ) ;
return V_318 ;
}
static int F_242 ( struct V_30 * V_34 , struct V_61 * V_62 , int V_342 )
{
struct V_30 * V_31 = NULL ;
struct V_221 V_343 ;
struct V_221 T_9 * V_344 = NULL ;
struct V_225 V_345 ;
struct V_225 T_9 * V_346 = NULL ;
struct V_63 * V_64 = NULL ;
struct V_347 * V_347 ;
int V_21 = 0 ;
F_3 ( L_101 , V_34 -> V_16 , V_342 ) ;
switch ( V_342 ) {
case V_72 :
V_64 = F_51 ( V_62 ) ;
if ( ! V_64 )
return - V_190 ;
V_64 -> V_348 = 0 ;
case V_75 :
V_64 = F_51 ( V_62 ) ;
if ( ! V_64 )
return - V_190 ;
if ( V_64 -> V_73 == 1 ) {
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_64 -> V_76 = 0 ;
F_66 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_87 ) ;
if ( F_42 ( V_11 -> V_15 ) )
V_64 -> V_76 = V_66 ;
F_72 ( & V_11 -> V_87 ) ;
F_72 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_349 :
case V_350 :
V_344 = (struct V_221 T_9 * ) V_62 -> V_351 ;
if ( F_243 ( & V_343 , V_344 , sizeof( V_221 ) ) )
return - V_352 ;
V_21 = F_167 ( V_34 , & V_343 ) ;
if ( V_21 == 0 &&
F_244 ( V_344 , & V_343 , sizeof( V_221 ) ) )
return - V_352 ;
return V_21 ;
case V_353 :
case V_354 :
V_346 = (struct V_225 T_9 * ) V_62 -> V_351 ;
if ( F_243 ( & V_345 , V_346 , sizeof( V_225 ) ) )
return - V_352 ;
V_21 = F_168 ( V_34 , & V_345 ) ;
if ( V_21 == 0 &&
F_244 ( V_346 , & V_345 , sizeof( V_225 ) ) )
return - V_352 ;
return V_21 ;
default:
break;
}
V_347 = F_185 ( V_34 ) ;
if ( ! F_245 ( V_347 -> V_355 , V_356 ) )
return - V_183 ;
V_31 = F_246 ( V_347 , V_62 -> V_357 ) ;
F_3 ( L_102 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_103 , V_31 -> V_16 ) ;
switch ( V_342 ) {
case V_358 :
case V_359 :
V_21 = F_134 ( V_34 , V_31 ) ;
break;
case V_360 :
case V_361 :
V_21 = F_163 ( V_34 , V_31 ) ;
break;
case V_362 :
case V_363 :
F_108 ( V_34 , V_31 ) ;
V_21 = 0 ;
break;
case V_364 :
case V_365 :
V_21 = F_166 ( V_34 , V_31 ) ;
break;
default:
V_21 = - V_193 ;
}
F_247 ( V_31 ) ;
}
return V_21 ;
}
static bool F_248 ( unsigned char * V_80 ,
struct V_366 * V_367 ,
int V_368 )
{
struct V_94 * V_95 ;
F_249 (ha, list)
if ( ! memcmp ( V_95 -> V_80 , V_80 , V_368 ) )
return true ;
return false ;
}
static void F_250 ( struct V_30 * V_34 , int V_369 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_369 & V_102 )
F_53 ( V_11 ,
V_34 -> V_101 & V_102 ? 1 : - 1 ) ;
if ( V_369 & V_103 )
F_56 ( V_11 ,
V_34 -> V_101 & V_103 ? 1 : - 1 ) ;
}
static void F_251 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_94 * V_95 ;
bool V_370 ;
F_66 ( & V_11 -> V_20 ) ;
F_76 (ha, bond_dev) {
V_370 = F_248 ( V_95 -> V_80 , & V_11 -> V_371 ,
V_34 -> V_139 ) ;
if ( ! V_370 )
F_58 ( V_11 , V_95 -> V_80 ) ;
}
F_249 (ha, &bond->mc_list) {
V_370 = F_248 ( V_95 -> V_80 , & V_34 -> V_372 ,
V_34 -> V_139 ) ;
if ( ! V_370 )
F_60 ( V_11 , V_95 -> V_80 ) ;
}
F_252 ( & V_11 -> V_371 ) ;
F_253 ( & V_11 -> V_371 , & V_34 -> V_372 ,
V_34 -> V_139 , V_373 ) ;
F_72 ( & V_11 -> V_20 ) ;
}
static int F_254 ( struct V_374 * V_375 )
{
struct V_10 * V_11 = F_29 ( V_375 -> V_15 ) ;
struct V_37 * V_37 = V_11 -> V_113 ;
const struct V_58 * V_59 ;
struct V_376 V_377 ;
int V_168 ;
if ( ! V_37 )
return 0 ;
V_59 = V_37 -> V_15 -> V_60 ;
if ( ! V_59 -> V_378 )
return 0 ;
V_377 . V_379 = NULL ;
V_377 . V_380 = NULL ;
V_168 = V_59 -> V_378 ( V_37 -> V_15 , & V_377 ) ;
if ( V_168 )
return V_168 ;
V_375 -> V_377 -> V_380 = V_377 . V_380 ;
if ( ! V_377 . V_379 )
return 0 ;
return V_377 . V_379 ( V_375 ) ;
}
static int F_255 ( struct V_30 * V_15 ,
struct V_376 * V_377 )
{
V_377 -> V_379 = F_254 ;
return 0 ;
}
static int F_256 ( struct V_30 * V_34 , int V_381 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_38 ;
int V_21 = 0 ;
int V_39 ;
F_3 ( L_104 , V_11 ,
( V_34 ? V_34 -> V_16 : L_10 ) , V_381 ) ;
F_30 (bond, slave, i) {
F_3 ( L_105 ,
V_37 ,
V_37 -> V_27 ,
V_37 -> V_15 -> V_60 -> V_382 ) ;
V_21 = F_140 ( V_37 -> V_15 , V_381 ) ;
if ( V_21 ) {
F_3 ( L_106 , V_21 , V_37 -> V_15 -> V_16 ) ;
goto V_40;
}
}
V_34 -> V_198 = V_381 ;
return 0 ;
V_40:
V_38 = V_37 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_383 ;
V_383 = F_140 ( V_37 -> V_15 , V_34 -> V_198 ) ;
if ( V_383 ) {
F_3 ( L_107 ,
V_383 , V_37 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_257 ( struct V_30 * V_34 , void * V_80 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_180 * V_384 = V_80 , V_385 ;
struct V_37 * V_37 , * V_38 ;
int V_21 = 0 ;
int V_39 ;
if ( V_11 -> V_44 . V_1 == V_9 )
return F_258 ( V_34 , V_80 ) ;
F_3 ( L_108 ,
V_11 , V_34 ? V_34 -> V_16 : L_10 ) ;
if ( V_11 -> V_44 . V_122 == V_192 )
return 0 ;
if ( ! F_259 ( V_384 -> V_201 ) )
return - V_386 ;
F_30 (bond, slave, i) {
const struct V_58 * V_59 = V_37 -> V_15 -> V_60 ;
F_3 ( L_109 , V_37 , V_37 -> V_15 -> V_16 ) ;
if ( V_59 -> V_191 == NULL ) {
V_21 = - V_193 ;
F_3 ( L_110 , V_37 -> V_15 -> V_16 ) ;
goto V_40;
}
V_21 = F_141 ( V_37 -> V_15 , V_80 ) ;
if ( V_21 ) {
F_3 ( L_106 , V_21 , V_37 -> V_15 -> V_16 ) ;
goto V_40;
}
}
memcpy ( V_34 -> V_140 , V_384 -> V_201 , V_34 -> V_139 ) ;
return 0 ;
V_40:
memcpy ( V_385 . V_201 , V_34 -> V_140 , V_34 -> V_139 ) ;
V_385 . V_202 = V_34 -> type ;
V_38 = V_37 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_383 ;
V_383 = F_141 ( V_37 -> V_15 , & V_385 ) ;
if ( V_383 ) {
F_3 ( L_107 ,
V_383 , V_37 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_260 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_387 ;
int V_39 , V_388 , V_21 = 1 ;
struct V_294 * V_295 = F_219 ( V_29 ) ;
if ( ( V_295 -> V_258 == V_389 ) &&
( V_29 -> V_258 == F_37 ( V_265 ) ) ) {
F_66 ( & V_11 -> V_87 ) ;
V_37 = V_11 -> V_79 ;
F_72 ( & V_11 -> V_87 ) ;
if ( ! V_37 )
goto V_23;
} else {
V_388 = V_11 -> V_390 ++ % V_11 -> V_42 ;
F_30 (bond, slave, i) {
V_388 -- ;
if ( V_388 < 0 )
break;
}
}
V_387 = V_37 ;
F_83 (bond, slave, i, start_at) {
if ( F_84 ( V_37 -> V_15 ) &&
( V_37 -> V_45 == V_46 ) &&
F_152 ( V_37 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_37 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_127 ( V_29 ) ;
}
return V_391 ;
}
static int F_261 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_21 = 1 ;
F_66 ( & V_11 -> V_87 ) ;
if ( V_11 -> V_79 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_79 -> V_15 ) ;
F_72 ( & V_11 -> V_87 ) ;
if ( V_21 )
F_127 ( V_29 ) ;
return V_391 ;
}
static int F_262 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_387 ;
int V_388 ;
int V_39 ;
int V_21 = 1 ;
V_388 = V_11 -> V_392 ( V_29 , V_11 -> V_42 ) ;
F_30 (bond, slave, i) {
V_388 -- ;
if ( V_388 < 0 )
break;
}
V_387 = V_37 ;
F_83 (bond, slave, i, start_at) {
if ( F_84 ( V_37 -> V_15 ) &&
( V_37 -> V_45 == V_46 ) &&
F_152 ( V_37 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_37 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_127 ( V_29 ) ;
}
return V_391 ;
}
static int F_263 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_387 ;
struct V_30 * V_393 = NULL ;
int V_39 ;
int V_21 = 1 ;
F_66 ( & V_11 -> V_87 ) ;
V_387 = V_11 -> V_79 ;
F_72 ( & V_11 -> V_87 ) ;
if ( ! V_387 )
goto V_23;
F_83 (bond, slave, i, start_at) {
if ( F_84 ( V_37 -> V_15 ) &&
( V_37 -> V_45 == V_46 ) &&
F_152 ( V_37 ) ) {
if ( V_393 ) {
struct V_28 * V_394 = F_264 ( V_29 , V_132 ) ;
if ( ! V_394 ) {
F_32 ( L_111 ,
V_34 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_394 , V_393 ) ;
if ( V_21 ) {
F_127 ( V_394 ) ;
continue;
}
}
V_393 = V_37 -> V_15 ;
}
}
if ( V_393 )
V_21 = F_20 ( V_11 , V_29 , V_393 ) ;
V_23:
if ( V_21 )
F_127 ( V_29 ) ;
return V_391 ;
}
static void F_265 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_44 . V_395 ) {
case V_396 :
V_11 -> V_392 = F_217 ;
break;
case V_397 :
V_11 -> V_392 = F_222 ;
break;
case V_398 :
default:
V_11 -> V_392 = F_215 ;
break;
}
}
static inline int F_266 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_39 , V_21 = 1 ;
struct V_37 * V_37 = NULL ;
struct V_37 * V_399 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_30 (bond, check_slave, i) {
if ( V_399 -> V_196 == V_29 -> V_32 ) {
V_37 = V_399 ;
break;
}
}
if ( V_37 && V_37 -> V_196 && F_84 ( V_37 -> V_15 ) &&
( V_37 -> V_45 == V_46 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_37 -> V_15 ) ;
}
return V_21 ;
}
static T_2 F_267 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_2 V_400 = F_268 ( V_29 ) ? F_269 ( V_29 ) : 0 ;
F_22 ( V_29 ) -> V_33 = V_29 -> V_32 ;
if ( F_23 ( V_400 >= V_15 -> V_401 ) ) {
do {
V_400 -= V_15 -> V_401 ;
} while ( V_400 >= V_15 -> V_401 );
}
return V_400 ;
}
static T_10 F_270 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
if ( F_271 ( V_11 -> V_44 . V_1 ) ) {
if ( ! F_266 ( V_11 , V_29 ) )
return V_391 ;
}
switch ( V_11 -> V_44 . V_1 ) {
case V_3 :
return F_260 ( V_29 , V_15 ) ;
case V_4 :
return F_261 ( V_29 , V_15 ) ;
case V_5 :
return F_262 ( V_29 , V_15 ) ;
case V_6 :
return F_263 ( V_29 , V_15 ) ;
case V_7 :
return F_272 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_273 ( V_29 , V_15 ) ;
default:
F_32 ( L_112 ,
V_15 -> V_16 , V_11 -> V_44 . V_1 ) ;
F_274 ( 1 ) ;
F_127 ( V_29 ) ;
return V_391 ;
}
}
static T_10 F_275 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_10 V_168 = V_391 ;
if ( F_276 ( V_15 ) )
return V_402 ;
F_66 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_42 )
V_168 = F_270 ( V_29 , V_15 ) ;
else
F_127 ( V_29 ) ;
F_72 ( & V_11 -> V_20 ) ;
return V_168 ;
}
void F_277 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_34 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_265 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_265 ( V_11 ) ;
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
static int F_278 ( struct V_30 * V_34 ,
struct V_47 * V_48 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 ;
int V_39 ;
unsigned long V_50 = 0 ;
V_48 -> V_52 = V_53 ;
V_48 -> V_403 = V_404 ;
F_66 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
if ( F_279 ( V_37 ) ) {
if ( V_37 -> V_50 != V_51 )
V_50 += V_37 -> V_50 ;
if ( V_48 -> V_52 == V_53 &&
V_37 -> V_52 != V_53 )
V_48 -> V_52 = V_37 -> V_52 ;
}
}
F_280 ( V_48 , V_50 ? : V_51 ) ;
F_72 ( & V_11 -> V_20 ) ;
return 0 ;
}
static void F_281 ( struct V_30 * V_34 ,
struct V_405 * V_406 )
{
F_282 ( V_406 -> V_407 , V_408 , sizeof( V_406 -> V_407 ) ) ;
F_282 ( V_406 -> V_409 , V_410 , sizeof( V_406 -> V_409 ) ) ;
snprintf ( V_406 -> V_411 , sizeof( V_406 -> V_411 ) , L_113 ,
V_412 ) ;
}
static void F_283 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_11 -> V_89 )
F_284 ( V_11 -> V_89 ) ;
F_285 ( V_34 ) ;
}
static void F_286 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_287 ( & V_11 -> V_20 ) ;
F_287 ( & V_11 -> V_87 ) ;
V_11 -> V_44 = V_413 ;
V_11 -> V_15 = V_34 ;
F_5 ( & V_11 -> V_19 ) ;
F_139 ( V_34 ) ;
V_34 -> V_60 = & V_414 ;
V_34 -> V_67 = & V_415 ;
F_277 ( V_11 , V_11 -> V_44 . V_1 ) ;
V_34 -> V_416 = F_283 ;
F_288 ( V_34 , & V_417 ) ;
V_34 -> V_418 = 0 ;
V_34 -> V_101 |= V_289 | V_419 ;
V_34 -> V_85 |= V_206 ;
V_34 -> V_85 &= ~ ( V_158 | V_188 ) ;
V_34 -> V_144 |= V_146 ;
V_34 -> V_144 |= V_420 ;
V_34 -> V_421 = V_150 |
V_422 |
V_423 |
V_424 ;
V_34 -> V_421 &= ~ ( V_425 & ~ V_426 ) ;
V_34 -> V_144 |= V_34 -> V_421 ;
}
static void F_289 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_13 * V_14 , * V_427 ;
F_105 ( V_34 ) ;
while ( V_11 -> V_113 != NULL )
F_157 ( V_34 , V_11 -> V_113 -> V_15 , true ) ;
F_88 ( L_114 , V_34 -> V_16 ) ;
F_12 ( & V_11 -> V_428 ) ;
F_290 ( V_11 ) ;
F_252 ( & V_11 -> V_371 ) ;
F_291 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_292 ( const char * V_429 , const struct V_430 * V_431 )
{
int V_432 = - 1 , V_39 , V_128 ;
char * V_433 , V_434 [ V_435 + 1 ] = { 0 , } ;
for ( V_433 = ( char * ) V_429 ; * V_433 ; V_433 ++ )
if ( ! ( isdigit ( * V_433 ) || isspace ( * V_433 ) ) )
break;
if ( * V_433 )
V_128 = sscanf ( V_429 , L_115 , V_434 ) ;
else
V_128 = sscanf ( V_429 , L_113 , & V_432 ) ;
if ( ! V_128 )
return - 1 ;
for ( V_39 = 0 ; V_431 [ V_39 ] . V_436 ; V_39 ++ ) {
if ( V_432 == V_431 [ V_39 ] . V_1 )
return V_431 [ V_39 ] . V_1 ;
if ( strcmp ( V_434 , V_431 [ V_39 ] . V_436 ) == 0 )
return V_431 [ V_39 ] . V_1 ;
}
return - 1 ;
}
static int F_293 ( struct V_437 * V_44 )
{
int V_438 , V_439 , V_440 , V_39 ;
if ( V_1 ) {
V_223 = F_292 ( V_1 , V_441 ) ;
if ( V_223 == - 1 ) {
F_32 ( L_116 ,
V_1 == NULL ? L_18 : V_1 ) ;
return - V_190 ;
}
}
if ( V_392 ) {
if ( ( V_223 != V_5 ) &&
( V_223 != V_7 ) ) {
F_88 ( L_117 ,
F_1 ( V_223 ) ) ;
} else {
V_442 = F_292 ( V_392 ,
V_443 ) ;
if ( V_442 == - 1 ) {
F_32 ( L_118 ,
V_392 == NULL ? L_18 :
V_392 ) ;
return - V_190 ;
}
}
}
if ( V_444 ) {
if ( V_223 != V_7 ) {
F_88 ( L_119 ,
F_1 ( V_223 ) ) ;
} else {
V_445 = F_292 ( V_444 , V_446 ) ;
if ( V_445 == - 1 ) {
F_32 ( L_120 ,
V_444 == NULL ? L_18 : V_444 ) ;
return - V_190 ;
}
}
}
if ( V_447 ) {
V_44 -> V_447 = F_292 ( V_447 , V_448 ) ;
if ( V_44 -> V_447 == - 1 ) {
F_32 ( L_121 ,
V_447 == NULL ? L_18 : V_447 ) ;
return - V_190 ;
}
if ( V_223 != V_7 ) {
F_38 ( L_122 ) ;
}
} else {
V_44 -> V_447 = V_449 ;
}
if ( V_450 < 0 ) {
F_38 ( L_123 ,
V_450 , 0 , V_451 , V_452 ) ;
V_450 = V_452 ;
}
if ( V_120 < 0 ) {
F_38 ( L_124 ,
V_120 , V_451 , V_453 ) ;
V_120 = V_453 ;
}
if ( V_112 < 0 ) {
F_38 ( L_125 ,
V_112 , V_451 ) ;
V_112 = 0 ;
}
if ( V_234 < 0 ) {
F_38 ( L_126 ,
V_234 , V_451 ) ;
V_234 = 0 ;
}
if ( ( V_65 != 0 ) && ( V_65 != 1 ) ) {
F_38 ( L_127 ,
V_65 ) ;
V_65 = 1 ;
}
if ( V_123 < 0 || V_123 > 255 ) {
F_38 ( L_128 ,
V_123 ) ;
V_123 = 1 ;
}
if ( V_223 == V_7 ) {
if ( ! V_120 ) {
F_38 ( L_129 ) ;
F_38 ( L_130 ) ;
V_120 = 100 ;
}
}
if ( V_454 < 1 || V_454 > 255 ) {
F_38 ( L_131
L_132 ,
V_454 , V_455 ) ;
V_454 = V_455 ;
}
if ( ( V_456 != 0 ) && ( V_456 != 1 ) ) {
F_38 ( L_133
L_134
L_135 , V_456 ) ;
V_456 = 0 ;
}
if ( V_126 < 0 || V_126 > 255 ) {
F_38 ( L_136
L_137 ,
V_126 , V_457 ) ;
V_126 = V_457 ;
}
if ( ( V_223 == V_8 ) ||
( V_223 == V_9 ) ) {
if ( ! V_120 ) {
F_38 ( L_138 ) ;
F_38 ( L_130 ) ;
V_120 = 100 ;
}
}
if ( V_223 == V_9 ) {
F_294 ( L_139 ,
V_112 ) ;
}
if ( ! V_120 ) {
if ( V_112 || V_234 ) {
F_38 ( L_140 ,
V_112 , V_234 ) ;
}
} else {
if ( V_171 ) {
F_38 ( L_141 ,
V_120 , V_171 ) ;
V_171 = 0 ;
}
if ( ( V_112 % V_120 ) != 0 ) {
F_38 ( L_142 ,
V_112 , V_120 ,
( V_112 / V_120 ) * V_120 ) ;
}
V_112 /= V_120 ;
if ( ( V_234 % V_120 ) != 0 ) {
F_38 ( L_143 ,
V_234 , V_120 ,
( V_234 / V_120 ) * V_120 ) ;
}
V_234 /= V_120 ;
}
if ( V_171 < 0 ) {
F_38 ( L_144 ,
V_171 , V_451 , V_458 ) ;
V_171 = V_458 ;
}
for ( V_459 = 0 , V_39 = 0 ;
( V_459 < V_248 ) && V_460 [ V_39 ] ; V_39 ++ ) {
T_8 V_239 = F_295 ( V_460 [ V_39 ] ) ;
if ( ! isdigit ( V_460 [ V_39 ] [ 0 ] ) || V_239 == 0 ||
V_239 == F_296 ( V_461 ) ) {
F_38 ( L_145 ,
V_460 [ V_39 ] ) ;
V_171 = 0 ;
} else {
V_462 [ V_459 ++ ] = V_239 ;
}
}
if ( V_171 && ! V_459 ) {
F_38 ( L_146 ,
V_171 ) ;
V_171 = 0 ;
}
if ( V_267 ) {
if ( V_223 != V_4 ) {
F_32 ( L_147 ) ;
return - V_190 ;
}
if ( ! V_171 ) {
F_32 ( L_148 ) ;
return - V_190 ;
}
V_438 = F_292 ( V_267 ,
V_463 ) ;
if ( V_438 == - 1 ) {
F_32 ( L_149 ,
V_267 == NULL ? L_18 : V_267 ) ;
return - V_190 ;
}
} else
V_438 = 0 ;
if ( V_120 ) {
F_88 ( L_150 , V_120 ) ;
} else if ( V_171 ) {
F_88 ( L_151 ,
V_171 ,
V_463 [ V_438 ] . V_436 ,
V_459 ) ;
for ( V_39 = 0 ; V_39 < V_459 ; V_39 ++ )
F_88 ( L_152 , V_460 [ V_39 ] ) ;
F_88 ( L_153 ) ;
} else if ( V_450 ) {
F_3 ( L_154 ) ;
}
if ( V_211 && ! F_54 ( V_223 ) ) {
F_38 ( L_155 ,
V_211 , F_1 ( V_223 ) ) ;
V_211 = NULL ;
}
if ( V_211 && V_107 ) {
V_440 = F_292 ( V_107 ,
V_464 ) ;
if ( V_440 == - 1 ) {
F_32 ( L_156 ,
V_107 ==
NULL ? L_18 : V_107 ) ;
return - V_190 ;
}
} else {
V_440 = V_465 ;
}
if ( V_122 ) {
V_439 = F_292 ( V_122 ,
V_466 ) ;
if ( V_439 == - 1 ) {
F_32 ( L_157 ,
V_267 == NULL ? L_18 : V_267 ) ;
return - V_190 ;
}
if ( V_223 != V_4 )
F_38 ( L_158 ) ;
} else {
V_439 = V_467 ;
}
V_44 -> V_1 = V_223 ;
V_44 -> V_395 = V_442 ;
V_44 -> V_120 = V_120 ;
V_44 -> V_123 = V_123 ;
V_44 -> V_171 = V_171 ;
V_44 -> V_267 = V_438 ;
V_44 -> V_112 = V_112 ;
V_44 -> V_234 = V_234 ;
V_44 -> V_65 = V_65 ;
V_44 -> V_445 = V_445 ;
V_44 -> V_211 [ 0 ] = 0 ;
V_44 -> V_107 = V_440 ;
V_44 -> V_122 = V_439 ;
V_44 -> V_454 = V_454 ;
V_44 -> V_456 = V_456 ;
V_44 -> V_126 = V_126 ;
V_44 -> V_468 = V_468 ;
if ( V_211 ) {
strncpy ( V_44 -> V_211 , V_211 , V_71 ) ;
V_44 -> V_211 [ V_71 - 1 ] = 0 ;
}
memcpy ( V_44 -> V_245 , V_462 , sizeof( V_462 ) ) ;
return 0 ;
}
static void F_297 ( struct V_30 * V_15 ,
struct V_469 * V_400 ,
void * V_470 )
{
F_298 ( & V_400 -> V_471 ,
& V_472 ) ;
}
static void F_299 ( struct V_30 * V_15 )
{
F_298 ( & V_15 -> V_473 ,
& V_474 ) ;
F_300 ( V_15 , F_297 , NULL ) ;
V_15 -> V_475 = & V_476 ;
}
static int F_301 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_477 * V_478 = F_302 ( F_185 ( V_34 ) , V_479 ) ;
struct V_480 * V_481 = & ( F_303 ( V_11 ) ) ;
F_3 ( L_159 , V_34 -> V_16 ) ;
F_304 ( & ( V_481 -> V_482 ) ) ;
F_304 ( & ( V_481 -> V_483 ) ) ;
V_11 -> V_89 = F_305 ( V_34 -> V_16 ) ;
if ( ! V_11 -> V_89 )
return - V_18 ;
F_299 ( V_34 ) ;
F_7 ( & V_11 -> V_428 , & V_478 -> V_484 ) ;
F_306 ( V_11 ) ;
F_307 ( V_11 ) ;
if ( F_308 ( V_34 -> V_140 ) &&
V_34 -> V_141 == V_485 ) {
F_156 ( V_34 ) ;
V_11 -> V_195 = true ;
}
F_309 ( & V_11 -> V_371 ) ;
return 0 ;
}
static int F_310 ( struct V_486 * V_487 [] , struct V_486 * V_176 [] )
{
if ( V_487 [ V_488 ] ) {
if ( F_311 ( V_487 [ V_488 ] ) != V_97 )
return - V_190 ;
if ( ! F_259 ( F_312 ( V_487 [ V_488 ] ) ) )
return - V_386 ;
}
return 0 ;
}
static unsigned int F_313 ( void )
{
return V_454 ;
}
int F_314 ( struct V_347 * V_347 , const char * V_16 )
{
struct V_30 * V_34 ;
int V_21 ;
F_315 () ;
V_34 = F_316 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_160 ,
F_286 , V_454 ) ;
if ( ! V_34 ) {
F_32 ( L_161 , V_16 ) ;
F_176 () ;
return - V_18 ;
}
F_317 ( V_34 , V_347 ) ;
V_34 -> V_489 = & V_490 ;
V_21 = F_318 ( V_34 ) ;
F_44 ( V_34 ) ;
F_176 () ;
if ( V_21 < 0 )
F_283 ( V_34 ) ;
return V_21 ;
}
static int T_11 F_319 ( struct V_347 * V_347 )
{
struct V_477 * V_478 = F_302 ( V_347 , V_479 ) ;
V_478 -> V_347 = V_347 ;
F_5 ( & V_478 -> V_484 ) ;
F_320 ( V_478 ) ;
F_321 ( V_478 ) ;
return 0 ;
}
static void T_12 F_322 ( struct V_347 * V_347 )
{
struct V_477 * V_478 = F_302 ( V_347 , V_479 ) ;
struct V_10 * V_11 , * V_491 ;
F_323 ( V_367 ) ;
F_324 ( V_478 ) ;
F_325 ( V_478 ) ;
F_315 () ;
F_291 (bond, tmp_bond, &bn->dev_list, bond_list)
F_326 ( V_11 -> V_15 , & V_367 ) ;
F_327 ( & V_367 ) ;
F_176 () ;
}
static int T_13 F_328 ( void )
{
int V_39 ;
int V_21 ;
F_88 ( L_162 , V_492 ) ;
V_21 = F_293 ( & V_413 ) ;
if ( V_21 )
goto V_23;
V_21 = F_329 ( & V_493 ) ;
if ( V_21 )
goto V_23;
V_21 = F_330 ( & V_490 ) ;
if ( V_21 )
goto V_494;
F_331 () ;
for ( V_39 = 0 ; V_39 < V_450 ; V_39 ++ ) {
V_21 = F_314 ( & V_495 , NULL ) ;
if ( V_21 )
goto V_78;
}
F_332 ( & V_496 ) ;
V_23:
return V_21 ;
V_78:
F_333 ( & V_490 ) ;
V_494:
F_334 ( & V_493 ) ;
goto V_23;
}
static void T_14 F_335 ( void )
{
F_336 ( & V_496 ) ;
F_337 () ;
F_333 ( & V_490 ) ;
F_334 ( & V_493 ) ;
#ifdef F_149
F_338 ( F_339 ( & V_497 ) ) ;
#endif
}
