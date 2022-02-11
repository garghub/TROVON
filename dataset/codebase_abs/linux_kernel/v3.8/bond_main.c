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
F_62 () ;
V_80 = F_63 ( V_15 ) ;
if ( V_80 )
F_64 ( V_80 ) ;
F_65 () ;
}
static void F_66 ( struct V_10 * V_11 )
{
struct V_30 * V_34 , * V_81 , * V_82 ;
struct V_13 * V_14 ;
F_67 ( & V_11 -> V_20 ) ;
V_34 = V_11 -> V_15 ;
F_61 ( V_34 ) ;
V_82 = V_34 -> V_83 ;
if ( V_82 )
if ( ( V_82 -> V_84 & V_85 )
&& ( V_34 -> V_84 & V_86 ) )
F_61 ( V_82 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_62 () ;
V_81 = F_68 ( V_34 ,
V_14 -> V_12 ) ;
F_65 () ;
if ( V_81 )
F_61 ( V_81 ) ;
}
if ( -- V_11 -> V_87 > 0 )
F_69 ( V_11 -> V_88 , & V_11 -> V_89 , V_90 / 5 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static void F_71 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_89 . V_92 ) ;
F_66 ( V_11 ) ;
}
static void F_73 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_93 * V_94 ;
F_74 (ha, bond_dev)
F_60 ( V_31 , V_94 -> V_78 ) ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
T_3 V_95 [ V_96 ] = V_97 ;
F_60 ( V_31 , V_95 ) ;
}
}
static void F_75 ( struct V_10 * V_11 , struct V_36 * V_98 ,
struct V_36 * V_99 )
{
struct V_93 * V_94 ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) )
return;
if ( V_99 ) {
if ( V_11 -> V_15 -> V_100 & V_101 )
F_54 ( V_99 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_100 & V_102 )
F_56 ( V_99 -> V_15 , - 1 ) ;
F_74 (ha, bond->dev)
F_60 ( V_99 -> V_15 , V_94 -> V_78 ) ;
}
if ( V_98 ) {
if ( V_11 -> V_15 -> V_100 & V_101 )
F_54 ( V_98 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_100 & V_102 )
F_56 ( V_98 -> V_15 , 1 ) ;
F_74 (ha, bond->dev)
F_58 ( V_98 -> V_15 , V_94 -> V_78 ) ;
}
}
static void F_76 ( struct V_10 * V_11 ,
struct V_36 * V_98 ,
struct V_36 * V_99 )
__releases( &bond->curr_slave_lock
static bool F_77 ( struct V_10 * V_11 )
{
struct V_36 * V_103 = V_11 -> V_104 ;
struct V_36 * V_24 = V_11 -> V_77 ;
if ( ! V_103 || ! V_24 || V_24 -> V_43 != V_44 )
return true ;
if ( V_11 -> V_105 ) {
V_11 -> V_105 = false ;
return true ;
}
if ( V_11 -> V_42 . V_106 == V_107 &&
( V_103 -> V_48 < V_24 -> V_48 ||
( V_103 -> V_48 == V_24 -> V_48 && V_103 -> V_50 <= V_24 -> V_50 ) ) )
return false ;
if ( V_11 -> V_42 . V_106 == V_108 )
return false ;
return true ;
}
static struct V_36 * F_78 ( struct V_10 * V_11 )
{
struct V_36 * V_98 , * V_99 ;
struct V_36 * V_109 = NULL ;
int V_110 = V_11 -> V_42 . V_111 ;
int V_38 ;
V_98 = V_11 -> V_77 ;
if ( ! V_98 ) {
if ( V_11 -> V_40 > 0 )
V_98 = V_11 -> V_112 ;
else
return NULL ;
}
if ( ( V_11 -> V_104 ) &&
V_11 -> V_104 -> V_43 == V_44 &&
F_77 ( V_11 ) ) {
V_98 = V_11 -> V_104 ;
}
V_99 = V_98 ;
F_79 (bond, new_active, i, old_active) {
if ( V_98 -> V_43 == V_44 ) {
return V_98 ;
} else if ( V_98 -> V_43 == V_113 &&
F_80 ( V_98 -> V_15 ) ) {
if ( V_98 -> V_114 < V_110 ) {
V_110 = V_98 -> V_114 ;
V_109 = V_98 ;
}
}
}
return V_109 ;
}
static bool F_81 ( struct V_10 * V_11 )
{
struct V_36 * V_36 = V_11 -> V_77 ;
F_3 ( L_17 ,
V_11 -> V_15 -> V_16 , V_36 ? V_36 -> V_15 -> V_16 : L_18 ) ;
if ( ! V_36 || ! V_11 -> V_115 ||
F_82 ( V_116 , & V_36 -> V_15 -> V_117 ) )
return false ;
V_11 -> V_115 -- ;
return true ;
}
void F_83 ( struct V_10 * V_11 , struct V_36 * V_98 )
{
struct V_36 * V_99 = V_11 -> V_77 ;
if ( V_99 == V_98 )
return;
if ( V_98 ) {
V_98 -> V_118 = V_118 ;
if ( V_98 -> V_43 == V_113 ) {
if ( F_53 ( V_11 -> V_42 . V_1 ) ) {
F_84 ( L_19 ,
V_11 -> V_15 -> V_16 , V_98 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_111 - V_98 -> V_114 ) * V_11 -> V_42 . V_119 ) ;
}
V_98 -> V_114 = 0 ;
V_98 -> V_43 = V_44 ;
if ( V_11 -> V_42 . V_1 == V_7 )
F_85 ( V_98 , V_44 ) ;
if ( F_13 ( V_11 ) )
F_86 ( V_11 , V_98 , V_44 ) ;
} else {
if ( F_53 ( V_11 -> V_42 . V_1 ) ) {
F_84 ( L_20 ,
V_11 -> V_15 -> V_16 , V_98 -> V_15 -> V_16 ) ;
}
}
}
if ( F_53 ( V_11 -> V_42 . V_1 ) )
F_75 ( V_11 , V_98 , V_99 ) ;
if ( F_13 ( V_11 ) ) {
F_87 ( V_11 , V_98 ) ;
if ( V_99 )
F_88 ( V_99 ) ;
if ( V_98 )
F_89 ( V_98 ) ;
} else {
V_11 -> V_77 = V_98 ;
}
if ( V_11 -> V_42 . V_1 == V_4 ) {
if ( V_99 )
F_88 ( V_99 ) ;
if ( V_98 ) {
bool V_120 = false ;
F_89 ( V_98 ) ;
if ( V_11 -> V_42 . V_121 )
F_76 ( V_11 , V_98 ,
V_99 ) ;
if ( F_49 ( V_11 -> V_15 ) ) {
V_11 -> V_115 =
V_11 -> V_42 . V_122 ;
V_120 =
F_81 ( V_11 ) ;
}
F_8 ( & V_11 -> V_123 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_90 ( V_124 , V_11 -> V_15 ) ;
if ( V_120 )
F_90 ( V_125 ,
V_11 -> V_15 ) ;
F_67 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_123 ) ;
}
}
if ( F_49 ( V_11 -> V_15 ) && ( V_11 -> V_42 . V_126 > 0 ) &&
( ( F_53 ( V_11 -> V_42 . V_1 ) && V_98 ) ||
V_11 -> V_42 . V_1 == V_3 ) ) {
V_11 -> V_87 = V_11 -> V_42 . V_126 ;
F_69 ( V_11 -> V_88 , & V_11 -> V_89 , 0 ) ;
}
}
void F_91 ( struct V_10 * V_11 )
{
struct V_36 * V_127 ;
int V_128 ;
V_127 = F_78 ( V_11 ) ;
if ( V_127 != V_11 -> V_77 ) {
F_83 ( V_11 , V_127 ) ;
V_128 = F_39 ( V_11 ) ;
if ( ! V_128 )
return;
if ( F_41 ( V_11 -> V_15 ) ) {
F_84 ( L_21 ,
V_11 -> V_15 -> V_16 ) ;
} else {
F_84 ( L_22 ,
V_11 -> V_15 -> V_16 ) ;
}
}
}
static void F_92 ( struct V_10 * V_11 , struct V_36 * V_129 )
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
V_11 -> V_40 ++ ;
}
static void F_93 ( struct V_10 * V_11 , struct V_36 * V_36 )
{
if ( V_36 -> V_25 )
V_36 -> V_25 -> V_27 = V_36 -> V_27 ;
if ( V_36 -> V_27 )
V_36 -> V_27 -> V_25 = V_36 -> V_25 ;
if ( V_11 -> V_112 == V_36 ) {
if ( V_11 -> V_40 > 1 ) {
V_11 -> V_112 = V_36 -> V_25 ;
} else {
V_11 -> V_112 = NULL ;
}
}
V_36 -> V_25 = NULL ;
V_36 -> V_27 = NULL ;
V_11 -> V_40 -- ;
}
static inline int F_94 ( struct V_36 * V_36 )
{
struct V_130 * V_131 ;
int V_76 = 0 ;
V_131 = F_4 ( sizeof( * V_131 ) , V_132 ) ;
V_76 = - V_18 ;
if ( ! V_131 )
goto V_23;
V_76 = F_95 ( V_131 , V_36 -> V_15 , V_132 ) ;
if ( V_76 ) {
F_15 ( V_131 ) ;
goto V_23;
}
V_36 -> V_131 = V_131 ;
V_23:
return V_76 ;
}
static inline void F_96 ( struct V_36 * V_36 )
{
struct V_130 * V_131 = V_36 -> V_131 ;
if ( ! V_131 )
return;
V_36 -> V_131 = NULL ;
F_97 ( V_131 ) ;
}
static inline bool F_98 ( struct V_30 * V_31 )
{
if ( V_31 -> V_84 & V_133 )
return false ;
if ( ! V_31 -> V_58 -> V_134 )
return false ;
return true ;
}
static void F_99 ( struct V_30 * V_34 )
{
}
static void F_100 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i)
if ( F_80 ( V_36 -> V_15 ) )
F_96 ( V_36 ) ;
}
static void F_101 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_67 ( & V_11 -> V_20 ) ;
F_100 ( V_11 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_102 ( struct V_30 * V_15 , struct V_135 * V_136 , T_4 V_137 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
struct V_36 * V_36 ;
int V_38 , V_76 = 0 ;
F_67 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
V_76 = F_94 ( V_36 ) ;
if ( V_76 ) {
F_100 ( V_11 ) ;
break;
}
}
F_70 ( & V_11 -> V_20 ) ;
return V_76 ;
}
static struct V_135 * F_103 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_138 ;
}
static inline int F_94 ( struct V_36 * V_36 )
{
return 0 ;
}
static inline void F_96 ( struct V_36 * V_36 )
{
}
static void F_101 ( struct V_30 * V_34 )
{
}
static int F_104 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_3 ( L_23 , V_34 ) ;
F_3 ( L_24 , V_31 ) ;
F_3 ( L_25 , V_31 -> V_139 ) ;
memcpy ( V_34 -> V_140 , V_31 -> V_140 , V_31 -> V_139 ) ;
return 0 ;
}
static T_5 F_105 ( struct V_30 * V_15 ,
T_5 V_141 )
{
struct V_36 * V_36 ;
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_5 V_142 ;
int V_38 ;
F_67 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_112 ) {
V_141 |= V_143 ;
goto V_23;
}
V_142 = V_141 ;
V_141 &= ~ V_144 ;
V_141 |= V_145 ;
F_30 (bond, slave, i) {
V_141 = F_106 ( V_141 ,
V_36 -> V_15 -> V_141 ,
V_142 ) ;
}
V_23:
F_70 ( & V_11 -> V_20 ) ;
return V_141 ;
}
static void F_107 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
struct V_30 * V_34 = V_11 -> V_15 ;
T_5 V_146 = V_147 ;
unsigned short V_148 = V_149 ;
unsigned int V_150 = V_151 ;
T_6 V_152 = V_153 ;
int V_38 ;
unsigned int V_100 , V_154 = V_155 ;
F_67 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_112 )
goto V_156;
F_30 (bond, slave, i) {
V_146 = F_106 ( V_146 ,
V_36 -> V_15 -> V_146 , V_147 ) ;
V_154 &= V_36 -> V_15 -> V_84 ;
if ( V_36 -> V_15 -> V_157 > V_148 )
V_148 = V_36 -> V_15 -> V_157 ;
V_150 = F_108 ( V_150 , V_36 -> V_15 -> V_150 ) ;
V_152 = F_108 ( V_152 , V_36 -> V_15 -> V_152 ) ;
}
V_156:
V_34 -> V_146 = V_146 ;
V_34 -> V_157 = V_148 ;
V_34 -> V_152 = V_152 ;
F_109 ( V_34 , V_150 ) ;
V_100 = V_34 -> V_84 & ~ V_155 ;
V_34 -> V_84 = V_100 | V_154 ;
F_70 ( & V_11 -> V_20 ) ;
F_110 ( V_34 ) ;
}
static void F_111 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_34 -> V_158 = V_31 -> V_158 ;
V_34 -> type = V_31 -> type ;
V_34 -> V_157 = V_31 -> V_157 ;
V_34 -> V_139 = V_31 -> V_139 ;
memcpy ( V_34 -> V_159 , V_31 -> V_159 ,
V_31 -> V_139 ) ;
V_11 -> V_160 = 1 ;
}
static bool F_112 ( struct V_28 * V_29 ,
struct V_36 * V_36 ,
struct V_10 * V_11 )
{
if ( F_113 ( V_36 ) ) {
if ( V_11 -> V_42 . V_1 == V_9 &&
V_29 -> V_161 != V_162 &&
V_29 -> V_161 != V_163 )
return false ;
return true ;
}
return false ;
}
static T_7 F_114 ( struct V_28 * * V_164 )
{
struct V_28 * V_29 = * V_164 ;
struct V_36 * V_36 ;
struct V_10 * V_11 ;
int (* F_115)( const struct V_28 * , struct V_10 * ,
struct V_36 * );
int V_165 = V_166 ;
V_29 = F_116 ( V_29 , V_132 ) ;
if ( F_23 ( ! V_29 ) )
return V_167 ;
* V_164 = V_29 ;
V_36 = F_117 ( V_29 -> V_15 ) ;
V_11 = V_36 -> V_11 ;
if ( V_11 -> V_42 . V_168 )
V_36 -> V_15 -> V_169 = V_118 ;
F_115 = F_118 ( V_11 -> F_115 ) ;
if ( F_115 ) {
V_165 = F_115 ( V_29 , V_11 , V_36 ) ;
if ( V_165 == V_167 ) {
F_119 ( V_29 ) ;
return V_165 ;
}
}
if ( F_112 ( V_29 , V_36 , V_11 ) ) {
return V_170 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_42 . V_1 == V_9 &&
V_11 -> V_15 -> V_84 & V_86 &&
V_29 -> V_161 == V_171 ) {
if ( F_23 ( F_120 ( V_29 ,
V_29 -> V_172 - F_121 ( V_29 ) ) ) ) {
F_122 ( V_29 ) ;
return V_167 ;
}
memcpy ( F_123 ( V_29 ) -> V_173 , V_11 -> V_15 -> V_140 , V_96 ) ;
}
return V_165 ;
}
int F_124 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
const struct V_56 * V_57 = V_31 -> V_58 ;
struct V_36 * V_129 = NULL ;
struct V_93 * V_94 ;
struct V_174 V_78 ;
int V_175 ;
int V_21 = 0 ;
if ( ! V_11 -> V_42 . V_63 &&
V_31 -> V_65 -> V_66 == NULL &&
V_57 -> V_67 == NULL ) {
F_37 ( L_26 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_100 & V_176 ) {
F_3 ( L_27 ) ;
return - V_177 ;
}
if ( V_31 -> V_141 & V_143 ) {
F_3 ( L_28 , V_31 -> V_16 ) ;
if ( F_125 ( V_34 ) ) {
F_32 ( L_29 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
return - V_178 ;
} else {
F_37 ( L_30 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_34 -> V_16 ) ;
}
} else {
F_3 ( L_31 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_100 & V_179 ) ) {
F_32 ( L_32 ,
V_31 -> V_16 ) ;
V_21 = - V_178 ;
goto V_180;
}
if ( V_11 -> V_40 == 0 ) {
if ( V_34 -> type != V_31 -> type ) {
F_3 ( L_33 ,
V_34 -> V_16 ,
V_34 -> type , V_31 -> type ) ;
V_21 = F_90 ( V_181 ,
V_34 ) ;
V_21 = F_126 ( V_21 ) ;
if ( V_21 ) {
F_32 ( L_34 ,
V_34 -> V_16 ) ;
V_21 = - V_177 ;
goto V_180;
}
F_127 ( V_34 ) ;
F_128 ( V_34 ) ;
if ( V_31 -> type != V_182 )
F_111 ( V_34 , V_31 ) ;
else {
F_129 ( V_34 ) ;
V_34 -> V_84 &= ~ V_183 ;
}
F_90 ( V_184 ,
V_34 ) ;
}
} else if ( V_34 -> type != V_31 -> type ) {
F_32 ( L_35 ,
V_31 -> V_16 ,
V_31 -> type , V_34 -> type ) ;
V_21 = - V_185 ;
goto V_180;
}
if ( V_57 -> V_186 == NULL ) {
if ( V_11 -> V_40 == 0 ) {
F_37 ( L_36 ,
V_34 -> V_16 ) ;
V_11 -> V_42 . V_121 = V_187 ;
} else if ( V_11 -> V_42 . V_121 != V_187 ) {
F_32 ( L_37 ,
V_34 -> V_16 ) ;
V_21 = - V_188 ;
goto V_180;
}
}
F_90 ( V_189 , V_31 ) ;
if ( F_130 ( V_11 -> V_15 -> V_140 ) )
memcpy ( V_11 -> V_15 -> V_140 , V_31 -> V_140 ,
V_31 -> V_139 ) ;
V_129 = F_4 ( sizeof( struct V_36 ) , V_17 ) ;
if ( ! V_129 ) {
V_21 = - V_18 ;
goto V_180;
}
V_129 -> V_190 = 0 ;
V_129 -> V_191 = V_31 -> V_192 ;
V_21 = F_131 ( V_31 , V_11 -> V_15 -> V_192 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_193;
}
memcpy ( V_129 -> V_194 , V_31 -> V_140 , V_96 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_195 , V_34 -> V_140 , V_34 -> V_139 ) ;
V_78 . V_196 = V_31 -> type ;
V_21 = F_132 ( V_31 , & V_78 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_197;
}
}
V_21 = F_133 ( V_31 , V_34 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_21 ) ;
goto V_198;
}
V_21 = F_134 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_41 , V_31 -> V_16 ) ;
goto V_199;
}
V_129 -> V_11 = V_11 ;
V_129 -> V_15 = V_31 ;
V_31 -> V_84 |= V_200 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_135 ( V_11 , V_129 ) ;
if ( V_21 )
goto V_201;
}
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 ) {
V_21 = F_54 ( V_31 , 1 ) ;
if ( V_21 )
goto V_201;
}
if ( V_34 -> V_100 & V_102 ) {
V_21 = F_56 ( V_31 , 1 ) ;
if ( V_21 )
goto V_201;
}
F_136 ( V_34 ) ;
F_74 (ha, bond_dev)
F_58 ( V_31 , V_94 -> V_78 ) ;
F_137 ( V_34 ) ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
T_3 V_95 [ V_96 ] = V_97 ;
F_58 ( V_31 , V_95 ) ;
}
F_36 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_92 ( V_11 , V_129 ) ;
V_129 -> V_114 = 0 ;
V_129 -> V_202 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_107 ( V_11 ) ;
F_67 ( & V_11 -> V_20 ) ;
V_129 -> V_203 = V_118 -
( F_138 ( V_11 -> V_42 . V_168 ) + 1 ) ;
if ( V_11 -> V_42 . V_119 && ! V_11 -> V_42 . V_63 ) {
V_175 = F_47 ( V_11 , V_31 , 1 ) ;
if ( ( V_175 == - 1 ) && ! V_11 -> V_42 . V_168 ) {
F_37 ( L_42 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_175 == - 1 ) {
F_37 ( L_43 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
}
if ( V_11 -> V_42 . V_119 ) {
if ( F_47 ( V_11 , V_31 , 0 ) == V_64 ) {
if ( V_11 -> V_42 . V_111 ) {
V_129 -> V_43 = V_113 ;
V_129 -> V_114 = V_11 -> V_42 . V_111 ;
} else {
V_129 -> V_43 = V_44 ;
}
} else {
V_129 -> V_43 = V_204 ;
}
} else if ( V_11 -> V_42 . V_168 ) {
V_129 -> V_43 = ( F_41 ( V_31 ) ?
V_44 : V_204 ) ;
} else {
V_129 -> V_43 = V_44 ;
}
if ( V_129 -> V_43 != V_204 )
V_129 -> V_118 = V_118 ;
F_3 ( L_44 ,
V_129 -> V_43 == V_204 ? L_45 :
( V_129 -> V_43 == V_44 ? L_46 : L_47 ) ) ;
F_44 ( V_129 ) ;
if ( F_53 ( V_11 -> V_42 . V_1 ) && V_11 -> V_42 . V_205 [ 0 ] ) {
if ( strcmp ( V_11 -> V_42 . V_205 , V_129 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_104 = V_129 ;
V_11 -> V_105 = true ;
}
}
F_6 ( & V_11 -> V_123 ) ;
switch ( V_11 -> V_42 . V_1 ) {
case V_4 :
F_88 ( V_129 ) ;
F_91 ( V_11 ) ;
break;
case V_7 :
F_88 ( V_129 ) ;
if ( V_11 -> V_40 == 1 ) {
F_139 ( V_129 ) . V_206 = 1 ;
F_140 ( V_11 , 1000 / V_207 ) ;
} else {
F_139 ( V_129 ) . V_206 =
F_139 ( V_129 -> V_27 ) . V_206 + 1 ;
}
F_141 ( V_129 ) ;
break;
case V_8 :
case V_9 :
F_142 ( V_129 ) ;
F_88 ( V_129 ) ;
F_91 ( V_11 ) ;
break;
default:
F_3 ( L_48 ) ;
F_142 ( V_129 ) ;
if ( ! V_11 -> V_77 && V_129 -> V_43 == V_44 )
V_11 -> V_77 = V_129 ;
break;
}
F_8 ( & V_11 -> V_123 ) ;
F_39 ( V_11 ) ;
#ifdef F_143
V_31 -> V_138 = F_103 ( V_11 ) ;
if ( V_31 -> V_138 ) {
if ( F_94 ( V_129 ) ) {
F_70 ( & V_11 -> V_20 ) ;
F_84 ( L_49
L_50 ,
V_34 -> V_16 ) ;
V_21 = - V_177 ;
goto V_208;
}
}
#endif
F_70 ( & V_11 -> V_20 ) ;
V_21 = F_144 ( V_34 , V_31 ) ;
if ( V_21 )
goto V_208;
V_21 = F_145 ( V_31 , F_114 ,
V_129 ) ;
if ( V_21 ) {
F_3 ( L_51 , V_21 ) ;
goto V_209;
}
F_84 ( L_52 ,
V_34 -> V_16 , V_31 -> V_16 ,
F_146 ( V_129 ) ? L_53 : L_54 ,
V_129 -> V_43 != V_204 ? L_55 : L_56 ) ;
return 0 ;
V_209:
F_147 ( V_34 , V_31 ) ;
V_208:
F_6 ( & V_11 -> V_20 ) ;
F_93 ( V_11 , V_129 ) ;
F_8 ( & V_11 -> V_20 ) ;
V_201:
F_148 ( V_31 ) ;
V_199:
F_133 ( V_31 , NULL ) ;
V_198:
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_195 , V_129 -> V_194 , V_96 ) ;
V_78 . V_196 = V_31 -> type ;
F_132 ( V_31 , & V_78 ) ;
}
V_197:
F_131 ( V_31 , V_129 -> V_191 ) ;
V_193:
F_15 ( V_129 ) ;
V_180:
F_107 ( V_11 ) ;
return V_21 ;
}
int F_149 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_210 ;
struct V_174 V_78 ;
T_5 V_211 = V_34 -> V_141 ;
if ( ! ( V_31 -> V_100 & V_176 ) ||
( V_31 -> V_83 != V_34 ) ) {
F_32 ( L_57 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
return - V_185 ;
}
F_10 () ;
F_90 ( V_212 , V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_36 = F_26 ( V_11 , V_31 ) ;
if ( ! V_36 ) {
F_84 ( L_58 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_185 ;
}
F_150 ( V_31 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_151 () ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
if ( F_152 ( V_34 -> V_140 , V_36 -> V_194 ) &&
V_11 -> V_40 > 1 )
F_37 ( L_59 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_36 -> V_194 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_153 ( V_36 ) ;
}
F_84 ( L_60 ,
V_34 -> V_16 ,
F_146 ( V_36 ) ? L_61 : L_62 ,
V_31 -> V_16 ) ;
V_210 = V_11 -> V_77 ;
V_11 -> V_213 = NULL ;
F_93 ( V_11 , V_36 ) ;
if ( V_11 -> V_104 == V_36 )
V_11 -> V_104 = NULL ;
if ( V_210 == V_36 )
F_83 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_154 ( V_11 , V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_210 == V_36 ) {
F_8 ( & V_11 -> V_20 ) ;
F_67 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_40 == 0 ) {
F_39 ( V_11 ) ;
memset ( V_34 -> V_140 , 0 , V_34 -> V_139 ) ;
if ( F_155 ( V_11 ) ) {
F_37 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_37 ( L_64 ,
V_34 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
if ( V_11 -> V_40 == 0 )
F_90 ( V_214 , V_11 -> V_15 ) ;
F_107 ( V_11 ) ;
if ( ! ( V_34 -> V_141 & V_143 ) &&
( V_211 & V_143 ) )
F_84 ( L_65 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
F_147 ( V_34 , V_31 ) ;
F_38 ( V_11 , V_31 ) ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 )
F_54 ( V_31 , - 1 ) ;
if ( V_34 -> V_100 & V_102 )
F_56 ( V_31 , - 1 ) ;
F_136 ( V_34 ) ;
F_73 ( V_34 , V_31 ) ;
F_137 ( V_34 ) ;
}
F_133 ( V_31 , NULL ) ;
F_96 ( V_36 ) ;
F_148 ( V_31 ) ;
if ( V_11 -> V_42 . V_121 != V_187 ) {
memcpy ( V_78 . V_195 , V_36 -> V_194 , V_96 ) ;
V_78 . V_196 = V_31 -> type ;
F_132 ( V_31 , & V_78 ) ;
}
F_131 ( V_31 , V_36 -> V_191 ) ;
V_31 -> V_84 &= ~ V_200 ;
F_15 ( V_36 ) ;
return 0 ;
}
static int F_156 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_165 ;
V_165 = F_149 ( V_34 , V_31 ) ;
if ( ( V_165 == 0 ) && ( V_11 -> V_40 == 0 ) ) {
V_34 -> V_84 |= V_133 ;
F_84 ( L_66 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_157 ( V_34 ) ;
}
return V_165 ;
}
static int F_158 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
struct V_30 * V_31 ;
struct V_174 V_78 ;
F_6 ( & V_11 -> V_20 ) ;
F_43 ( V_34 ) ;
if ( V_11 -> V_40 == 0 )
goto V_23;
V_11 -> V_213 = NULL ;
V_11 -> V_104 = NULL ;
F_83 ( V_11 , NULL ) ;
while ( ( V_36 = V_11 -> V_112 ) != NULL ) {
if ( V_11 -> V_42 . V_1 == V_7 )
F_153 ( V_36 ) ;
V_31 = V_36 -> V_15 ;
F_93 ( V_11 , V_36 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_150 ( V_31 ) ;
F_151 () ;
if ( F_13 ( V_11 ) ) {
F_154 ( V_11 , V_36 ) ;
}
F_147 ( V_34 , V_31 ) ;
F_38 ( V_11 , V_31 ) ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 )
F_54 ( V_31 , - 1 ) ;
if ( V_34 -> V_100 & V_102 )
F_56 ( V_31 , - 1 ) ;
F_136 ( V_34 ) ;
F_73 ( V_34 , V_31 ) ;
F_137 ( V_34 ) ;
}
F_133 ( V_31 , NULL ) ;
F_96 ( V_36 ) ;
F_148 ( V_31 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_195 , V_36 -> V_194 , V_96 ) ;
V_78 . V_196 = V_31 -> type ;
F_132 ( V_31 , & V_78 ) ;
}
F_15 ( V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
memset ( V_34 -> V_140 , 0 , V_34 -> V_139 ) ;
if ( F_155 ( V_11 ) ) {
F_37 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_37 ( L_64 ,
V_34 -> V_16 ) ;
}
F_84 ( L_67 , V_34 -> V_16 ) ;
V_23:
F_8 ( & V_11 -> V_20 ) ;
F_107 ( V_11 ) ;
return 0 ;
}
static int F_159 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_99 = NULL ;
struct V_36 * V_98 = NULL ;
int V_21 = 0 ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) )
return - V_185 ;
if ( ! ( V_31 -> V_100 & V_176 ) || ( V_31 -> V_83 != V_34 ) )
return - V_185 ;
F_67 ( & V_11 -> V_20 ) ;
F_67 ( & V_11 -> V_123 ) ;
V_99 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
V_98 = F_26 ( V_11 , V_31 ) ;
if ( V_98 && ( V_98 == V_99 ) ) {
F_70 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_98 ) &&
( V_99 ) &&
( V_98 -> V_43 == V_44 ) &&
F_80 ( V_98 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_83 ( V_11 , V_98 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
} else
V_21 = - V_185 ;
F_70 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_160 ( struct V_30 * V_34 , struct V_215 * V_216 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_216 -> V_217 = V_11 -> V_42 . V_1 ;
V_216 -> V_119 = V_11 -> V_42 . V_119 ;
F_67 ( & V_11 -> V_20 ) ;
V_216 -> V_218 = V_11 -> V_40 ;
F_70 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_161 ( struct V_30 * V_34 , struct V_219 * V_216 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
int V_38 , V_21 = - V_22 ;
F_67 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
if ( V_38 == ( int ) V_216 -> V_220 ) {
V_21 = 0 ;
strcpy ( V_216 -> V_221 , V_36 -> V_15 -> V_16 ) ;
V_216 -> V_43 = V_36 -> V_43 ;
V_216 -> V_117 = F_162 ( V_36 ) ;
V_216 -> V_202 = V_36 -> V_202 ;
break;
}
}
F_70 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_163 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 , V_222 , V_223 = 0 ;
bool V_224 ;
V_224 = ! V_11 -> V_77 ? true : false ;
F_30 (bond, slave, i) {
V_36 -> V_225 = V_226 ;
V_222 = F_47 ( V_11 , V_36 -> V_15 , 0 ) ;
switch ( V_36 -> V_43 ) {
case V_44 :
if ( V_222 )
continue;
V_36 -> V_43 = V_227 ;
V_36 -> V_114 = V_11 -> V_42 . V_228 ;
if ( V_36 -> V_114 ) {
F_84 ( L_68 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_1 ==
V_4 ) ?
( F_146 ( V_36 ) ?
L_69 : L_70 ) : L_71 ,
V_36 -> V_15 -> V_16 ,
V_11 -> V_42 . V_228 * V_11 -> V_42 . V_119 ) ;
}
case V_227 :
if ( V_222 ) {
V_36 -> V_43 = V_44 ;
V_36 -> V_118 = V_118 ;
F_84 ( L_72 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_228 - V_36 -> V_114 ) *
V_11 -> V_42 . V_119 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_36 -> V_114 <= 0 ) {
V_36 -> V_225 = V_204 ;
V_223 ++ ;
continue;
}
V_36 -> V_114 -- ;
break;
case V_204 :
if ( ! V_222 )
continue;
V_36 -> V_43 = V_113 ;
V_36 -> V_114 = V_11 -> V_42 . V_111 ;
if ( V_36 -> V_114 ) {
F_84 ( L_73 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ,
V_224 ? 0 :
V_11 -> V_42 . V_111 *
V_11 -> V_42 . V_119 ) ;
}
case V_113 :
if ( ! V_222 ) {
V_36 -> V_43 = V_204 ;
F_84 ( L_74 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_111 - V_36 -> V_114 ) *
V_11 -> V_42 . V_119 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_224 )
V_36 -> V_114 = 0 ;
if ( V_36 -> V_114 <= 0 ) {
V_36 -> V_225 = V_44 ;
V_223 ++ ;
V_224 = false ;
continue;
}
V_36 -> V_114 -- ;
break;
}
}
return V_223 ;
}
static void F_164 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i) {
switch ( V_36 -> V_225 ) {
case V_226 :
continue;
case V_44 :
V_36 -> V_43 = V_44 ;
V_36 -> V_118 = V_118 ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_165 ( V_36 ) ;
} else if ( V_11 -> V_42 . V_1 != V_4 ) {
F_142 ( V_36 ) ;
} else if ( V_36 != V_11 -> V_104 ) {
F_165 ( V_36 ) ;
}
F_44 ( V_36 ) ;
F_84 ( L_75 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ,
V_36 -> V_48 , V_36 -> V_50 ? L_76 : L_77 ) ;
if ( V_11 -> V_42 . V_1 == V_7 )
F_85 ( V_36 , V_44 ) ;
if ( F_13 ( V_11 ) )
F_86 ( V_11 , V_36 ,
V_44 ) ;
if ( ! V_11 -> V_77 ||
( V_36 == V_11 -> V_104 ) )
goto V_229;
continue;
case V_204 :
if ( V_36 -> V_202 < V_230 )
V_36 -> V_202 ++ ;
V_36 -> V_43 = V_204 ;
if ( V_11 -> V_42 . V_1 == V_4 ||
V_11 -> V_42 . V_1 == V_7 )
F_88 ( V_36 ) ;
F_84 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_11 -> V_42 . V_1 == V_7 )
F_85 ( V_36 ,
V_204 ) ;
if ( F_13 ( V_11 ) )
F_86 ( V_11 , V_36 ,
V_204 ) ;
if ( V_36 == V_11 -> V_77 )
goto V_229;
continue;
default:
F_32 ( L_79 ,
V_11 -> V_15 -> V_16 , V_36 -> V_225 ,
V_36 -> V_15 -> V_16 ) ;
V_36 -> V_225 = V_226 ;
continue;
}
V_229:
F_166 () ;
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
F_39 ( V_11 ) ;
}
void F_167 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_231 . V_92 ) ;
bool V_120 = false ;
unsigned long V_114 ;
F_67 ( & V_11 -> V_20 ) ;
V_114 = F_138 ( V_11 -> V_42 . V_119 ) ;
if ( V_11 -> V_40 == 0 )
goto V_232;
V_120 = F_81 ( V_11 ) ;
if ( F_163 ( V_11 ) ) {
F_70 ( & V_11 -> V_20 ) ;
if ( ! F_168 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_114 = 1 ;
V_120 = false ;
goto V_232;
}
F_67 ( & V_11 -> V_20 ) ;
F_164 ( V_11 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_169 () ;
F_67 ( & V_11 -> V_20 ) ;
}
V_232:
if ( V_11 -> V_42 . V_119 )
F_69 ( V_11 -> V_88 , & V_11 -> V_231 , V_114 ) ;
F_70 ( & V_11 -> V_20 ) ;
if ( V_120 ) {
if ( ! F_168 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_11 -> V_115 ++ ;
F_70 ( & V_11 -> V_20 ) ;
return;
}
F_90 ( V_125 , V_11 -> V_15 ) ;
F_169 () ;
}
}
static int F_170 ( struct V_10 * V_11 , T_8 V_233 )
{
struct V_13 * V_14 ;
struct V_30 * V_81 ;
if ( V_233 == F_171 ( V_11 -> V_15 , 0 , V_233 ) )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_62 () ;
V_81 = F_68 ( V_11 -> V_15 , V_14 -> V_12 ) ;
F_65 () ;
if ( V_81 && V_233 == F_171 ( V_81 , 0 , V_233 ) )
return 1 ;
}
return 0 ;
}
static void F_172 ( struct V_30 * V_31 , int V_234 , T_8 V_235 , T_8 V_236 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_80 , V_234 ,
V_31 -> V_16 , V_235 , V_236 , V_12 ) ;
V_29 = F_173 ( V_234 , V_237 , V_235 , V_31 , V_236 ,
NULL , V_31 -> V_140 , NULL ) ;
if ( ! V_29 ) {
F_32 ( L_81 ) ;
return;
}
if ( V_12 ) {
V_29 = F_174 ( V_29 , V_12 ) ;
if ( ! V_29 ) {
F_32 ( L_82 ) ;
return;
}
}
F_175 ( V_29 ) ;
}
static void F_176 ( struct V_10 * V_11 , struct V_36 * V_36 )
{
int V_38 , V_12 ;
T_8 * V_238 = V_11 -> V_42 . V_239 ;
struct V_13 * V_14 ;
struct V_30 * V_81 = NULL ;
struct V_240 * V_241 ;
for ( V_38 = 0 ; ( V_38 < V_242 ) ; V_38 ++ ) {
T_8 V_78 ;
if ( ! V_238 [ V_38 ] )
break;
F_3 ( L_83 , V_238 [ V_38 ] ) ;
if ( ! F_155 ( V_11 ) ) {
F_3 ( L_84 ) ;
V_78 = F_171 ( V_11 -> V_15 , V_238 [ V_38 ] , 0 ) ;
F_172 ( V_36 -> V_15 , V_243 , V_238 [ V_38 ] ,
V_78 , 0 ) ;
continue;
}
V_241 = F_177 ( F_178 ( V_11 -> V_15 ) , V_238 [ V_38 ] , 0 ,
V_244 , 0 ) ;
if ( F_179 ( V_241 ) ) {
if ( F_180 () ) {
F_37 ( L_85 ,
V_11 -> V_15 -> V_16 , & V_238 [ V_38 ] ) ;
}
continue;
}
if ( V_241 -> V_245 . V_15 == V_11 -> V_15 ) {
F_181 ( V_241 ) ;
F_3 ( L_86 ) ;
V_78 = F_171 ( V_11 -> V_15 , V_238 [ V_38 ] , 0 ) ;
F_172 ( V_36 -> V_15 , V_243 , V_238 [ V_38 ] ,
V_78 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_62 () ;
V_81 = F_68 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_65 () ;
if ( V_81 == V_241 -> V_245 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_87 ,
V_81 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 && V_81 ) {
F_181 ( V_241 ) ;
V_78 = F_171 ( V_81 , V_238 [ V_38 ] , 0 ) ;
F_172 ( V_36 -> V_15 , V_243 , V_238 [ V_38 ] ,
V_78 , V_12 ) ;
continue;
}
if ( F_180 () ) {
F_37 ( L_88 ,
V_11 -> V_15 -> V_16 , & V_238 [ V_38 ] ,
V_241 -> V_245 . V_15 ? V_241 -> V_245 . V_15 -> V_16 : L_18 ) ;
}
F_181 ( V_241 ) ;
}
}
static void F_182 ( struct V_10 * V_11 , struct V_36 * V_36 , T_8 V_246 , T_8 V_247 )
{
int V_38 ;
T_8 * V_238 = V_11 -> V_42 . V_239 ;
for ( V_38 = 0 ; ( V_38 < V_242 ) && V_238 [ V_38 ] ; V_38 ++ ) {
F_3 ( L_89 ,
& V_246 , & V_247 , V_38 , & V_238 [ V_38 ] ,
F_170 ( V_11 , V_247 ) ) ;
if ( V_246 == V_238 [ V_38 ] ) {
if ( F_170 ( V_11 , V_247 ) )
V_36 -> V_203 = V_118 ;
return;
}
}
}
static int F_183 ( const struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_36 * V_36 )
{
struct V_248 * V_249 = (struct V_248 * ) V_29 -> V_172 ;
unsigned char * V_250 ;
T_8 V_246 , V_247 ;
int V_251 ;
if ( V_29 -> V_252 != F_184 ( V_237 ) )
return V_166 ;
F_67 ( & V_11 -> V_20 ) ;
V_251 = F_185 ( V_11 -> V_15 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( V_251 > F_186 ( V_29 ) ) {
V_249 = F_187 ( V_251 , V_132 ) ;
if ( ! V_249 )
goto V_253;
if ( F_188 ( V_29 , 0 , V_249 , V_251 ) < 0 )
goto V_253;
}
if ( V_249 -> V_254 != V_11 -> V_15 -> V_139 ||
V_29 -> V_161 == V_255 ||
V_29 -> V_161 == V_256 ||
V_249 -> V_257 != F_189 ( V_182 ) ||
V_249 -> V_258 != F_189 ( V_259 ) ||
V_249 -> V_260 != 4 )
goto V_253;
V_250 = ( unsigned char * ) ( V_249 + 1 ) ;
V_250 += V_11 -> V_15 -> V_139 ;
memcpy ( & V_246 , V_250 , 4 ) ;
V_250 += 4 + V_11 -> V_15 -> V_139 ;
memcpy ( & V_247 , V_250 , 4 ) ;
F_3 ( L_91 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 , F_162 ( V_36 ) ,
V_11 -> V_42 . V_261 , F_190 ( V_11 , V_36 ) ,
& V_246 , & V_247 ) ;
if ( F_146 ( V_36 ) )
F_182 ( V_11 , V_36 , V_246 , V_247 ) ;
else
F_182 ( V_11 , V_36 , V_247 , V_246 ) ;
V_253:
F_70 ( & V_11 -> V_20 ) ;
if ( V_249 != (struct V_248 * ) V_29 -> V_172 )
F_15 ( V_249 ) ;
return V_166 ;
}
void F_191 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_262 . V_92 ) ;
struct V_36 * V_36 , * V_210 ;
int V_229 = 0 ;
int V_263 , V_264 ;
int V_38 ;
F_67 ( & V_11 -> V_20 ) ;
V_263 = F_138 ( V_11 -> V_42 . V_168 ) ;
V_264 = V_263 / 2 ;
if ( V_11 -> V_40 == 0 )
goto V_232;
F_67 ( & V_11 -> V_123 ) ;
V_210 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
F_30 (bond, slave, i) {
unsigned long V_265 = F_192 ( V_36 -> V_15 ) ;
if ( V_36 -> V_43 != V_44 ) {
if ( F_193 ( V_118 ,
V_265 - V_263 ,
V_265 + V_263 + V_264 ) &&
F_193 ( V_118 ,
V_36 -> V_15 -> V_169 - V_263 ,
V_36 -> V_15 -> V_169 + V_263 + V_264 ) ) {
V_36 -> V_43 = V_44 ;
F_142 ( V_36 ) ;
if ( ! V_210 ) {
F_84 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
V_229 = 1 ;
} else {
F_84 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_193 ( V_118 ,
V_265 - V_263 ,
V_265 + 2 * V_263 + V_264 ) ||
! F_193 ( V_118 ,
V_36 -> V_15 -> V_169 - V_263 ,
V_36 -> V_15 -> V_169 + 2 * V_263 + V_264 ) ) {
V_36 -> V_43 = V_204 ;
F_165 ( V_36 ) ;
if ( V_36 -> V_202 < V_230 )
V_36 -> V_202 ++ ;
F_84 ( L_94 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_210 )
V_229 = 1 ;
}
}
if ( F_80 ( V_36 -> V_15 ) )
F_176 ( V_11 , V_36 ) ;
}
if ( V_229 ) {
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
V_232:
if ( V_11 -> V_42 . V_168 )
F_69 ( V_11 -> V_88 , & V_11 -> V_262 , V_263 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_194 ( struct V_10 * V_11 , int V_263 )
{
struct V_36 * V_36 ;
int V_38 , V_223 = 0 ;
unsigned long V_265 ;
int V_264 ;
V_264 = V_263 / 2 ;
F_30 (bond, slave, i) {
V_36 -> V_225 = V_226 ;
if ( V_36 -> V_43 != V_44 ) {
if ( F_193 ( V_118 ,
F_195 ( V_11 , V_36 ) - V_263 ,
F_195 ( V_11 , V_36 ) + V_263 + V_264 ) ) {
V_36 -> V_225 = V_44 ;
V_223 ++ ;
}
continue;
}
if ( F_193 ( V_118 ,
V_36 -> V_118 - V_263 ,
V_36 -> V_118 + 2 * V_263 + V_264 ) )
continue;
if ( ! F_146 ( V_36 ) &&
! V_11 -> V_213 &&
! F_193 ( V_118 ,
F_195 ( V_11 , V_36 ) - V_263 ,
F_195 ( V_11 , V_36 ) + 3 * V_263 + V_264 ) ) {
V_36 -> V_225 = V_204 ;
V_223 ++ ;
}
V_265 = F_192 ( V_36 -> V_15 ) ;
if ( F_146 ( V_36 ) &&
( ! F_193 ( V_118 ,
V_265 - V_263 ,
V_265 + 2 * V_263 + V_264 ) ||
! F_193 ( V_118 ,
F_195 ( V_11 , V_36 ) - V_263 ,
F_195 ( V_11 , V_36 ) + 2 * V_263 + V_264 ) ) ) {
V_36 -> V_225 = V_204 ;
V_223 ++ ;
}
}
return V_223 ;
}
static void F_196 ( struct V_10 * V_11 , int V_263 )
{
struct V_36 * V_36 ;
int V_38 ;
unsigned long V_265 ;
F_30 (bond, slave, i) {
switch ( V_36 -> V_225 ) {
case V_226 :
continue;
case V_44 :
V_265 = F_192 ( V_36 -> V_15 ) ;
if ( ( ! V_11 -> V_77 &&
F_193 ( V_118 ,
V_265 - V_263 ,
V_265 + V_263 + V_263 / 2 ) ) ||
V_11 -> V_77 != V_36 ) {
V_36 -> V_43 = V_44 ;
if ( V_11 -> V_213 ) {
F_88 (
V_11 -> V_213 ) ;
V_11 -> V_213 = NULL ;
}
F_84 ( L_95 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_77 ||
( V_36 == V_11 -> V_104 ) )
goto V_229;
}
continue;
case V_204 :
if ( V_36 -> V_202 < V_230 )
V_36 -> V_202 ++ ;
V_36 -> V_43 = V_204 ;
F_88 ( V_36 ) ;
F_84 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_11 -> V_77 ) {
V_11 -> V_213 = NULL ;
goto V_229;
}
continue;
default:
F_32 ( L_96 ,
V_11 -> V_15 -> V_16 , V_36 -> V_225 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
V_229:
F_166 () ;
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
F_39 ( V_11 ) ;
}
static void F_197 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_67 ( & V_11 -> V_123 ) ;
if ( V_11 -> V_213 && V_11 -> V_77 )
F_84 ( L_97 ,
V_11 -> V_213 -> V_15 -> V_16 ,
V_11 -> V_77 -> V_15 -> V_16 ) ;
if ( V_11 -> V_77 ) {
F_176 ( V_11 , V_11 -> V_77 ) ;
F_70 ( & V_11 -> V_123 ) ;
return;
}
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_11 -> V_213 ) {
V_11 -> V_213 = V_11 -> V_112 ;
if ( ! V_11 -> V_213 )
return;
}
F_88 ( V_11 -> V_213 ) ;
F_79 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_80 ( V_36 -> V_15 ) ) {
V_36 -> V_43 = V_113 ;
F_89 ( V_36 ) ;
F_176 ( V_11 , V_36 ) ;
V_36 -> V_118 = V_118 ;
V_11 -> V_213 = V_36 ;
break;
}
if ( V_36 -> V_43 == V_44 ) {
V_36 -> V_43 = V_204 ;
if ( V_36 -> V_202 < V_230 )
V_36 -> V_202 ++ ;
F_88 ( V_36 ) ;
F_84 ( L_98 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
}
}
}
void F_198 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_262 . V_92 ) ;
bool V_120 = false ;
int V_263 ;
F_67 ( & V_11 -> V_20 ) ;
V_263 = F_138 ( V_11 -> V_42 . V_168 ) ;
if ( V_11 -> V_40 == 0 )
goto V_232;
V_120 = F_81 ( V_11 ) ;
if ( F_194 ( V_11 , V_263 ) ) {
F_70 ( & V_11 -> V_20 ) ;
if ( ! F_168 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_263 = 1 ;
V_120 = false ;
goto V_232;
}
F_67 ( & V_11 -> V_20 ) ;
F_196 ( V_11 , V_263 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_169 () ;
F_67 ( & V_11 -> V_20 ) ;
}
F_197 ( V_11 ) ;
V_232:
if ( V_11 -> V_42 . V_168 )
F_69 ( V_11 -> V_88 , & V_11 -> V_262 , V_263 ) ;
F_70 ( & V_11 -> V_20 ) ;
if ( V_120 ) {
if ( ! F_168 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_11 -> V_115 ++ ;
F_70 ( & V_11 -> V_20 ) ;
return;
}
F_90 ( V_125 , V_11 -> V_15 ) ;
F_169 () ;
}
}
static int F_199 ( struct V_10 * V_11 )
{
F_200 ( V_11 ) ;
F_201 ( V_11 ) ;
F_202 ( V_11 ) ;
return V_266 ;
}
static int F_203 ( unsigned long V_267 ,
struct V_30 * V_34 )
{
struct V_10 * V_268 = F_29 ( V_34 ) ;
switch ( V_267 ) {
case V_269 :
return F_199 ( V_268 ) ;
case V_270 :
F_200 ( V_268 ) ;
break;
case V_271 :
F_201 ( V_268 ) ;
break;
default:
break;
}
return V_266 ;
}
static int F_204 ( unsigned long V_267 ,
struct V_30 * V_31 )
{
struct V_30 * V_34 = V_31 -> V_83 ;
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 = NULL ;
switch ( V_267 ) {
case V_270 :
if ( V_34 ) {
if ( V_11 -> V_160 )
F_156 ( V_34 , V_31 ) ;
else
F_149 ( V_34 , V_31 ) ;
}
break;
case V_272 :
case V_273 :
V_36 = F_26 ( V_11 , V_31 ) ;
if ( V_36 ) {
T_2 V_274 = V_36 -> V_48 ;
T_3 V_275 = V_36 -> V_50 ;
F_44 ( V_36 ) ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
if ( V_274 != V_36 -> V_48 )
F_205 ( V_36 ) ;
if ( V_275 != V_36 -> V_50 )
F_206 ( V_36 ) ;
}
}
break;
case V_276 :
break;
case V_277 :
break;
case V_269 :
break;
case V_278 :
F_107 ( V_11 ) ;
break;
default:
break;
}
return V_266 ;
}
static int F_207 ( struct V_279 * V_280 ,
unsigned long V_267 , void * V_281 )
{
struct V_30 * V_282 = (struct V_30 * ) V_281 ;
F_3 ( L_99 ,
V_282 ? V_282 -> V_16 : L_10 ,
V_267 ) ;
if ( ! ( V_282 -> V_84 & V_200 ) )
return V_266 ;
if ( V_282 -> V_100 & V_283 ) {
F_3 ( L_100 ) ;
return F_203 ( V_267 , V_282 ) ;
}
if ( V_282 -> V_100 & V_176 ) {
F_3 ( L_101 ) ;
return F_204 ( V_267 , V_282 ) ;
}
return V_266 ;
}
static int F_208 ( struct V_28 * V_29 , int V_284 )
{
struct V_285 * V_172 = (struct V_285 * ) V_29 -> V_172 ;
if ( F_186 ( V_29 ) >= F_209 ( struct V_285 , V_286 ) )
return ( V_172 -> V_173 [ 5 ] ^ V_172 -> V_287 [ 5 ] ) % V_284 ;
return 0 ;
}
static int F_210 ( struct V_28 * V_29 , int V_284 )
{
struct V_285 * V_172 = (struct V_285 * ) V_29 -> V_172 ;
struct V_288 * V_289 ;
struct V_290 * V_291 ;
T_2 V_292 ;
T_8 * V_293 , * V_294 ;
if ( V_29 -> V_252 == F_189 ( V_259 ) &&
F_211 ( V_29 ) >= sizeof( * V_289 ) ) {
V_289 = F_212 ( V_29 ) ;
return ( ( F_213 ( V_289 -> V_295 ^ V_289 -> V_296 ) & 0xffff ) ^
( V_172 -> V_173 [ 5 ] ^ V_172 -> V_287 [ 5 ] ) ) % V_284 ;
} else if ( V_29 -> V_252 == F_189 ( V_297 ) &&
F_211 ( V_29 ) >= sizeof( * V_291 ) ) {
V_291 = F_214 ( V_29 ) ;
V_293 = & V_291 -> V_295 . V_298 [ 0 ] ;
V_294 = & V_291 -> V_296 . V_298 [ 0 ] ;
V_292 = ( V_293 [ 1 ] ^ V_294 [ 1 ] ) ^ ( V_293 [ 2 ] ^ V_294 [ 2 ] ) ^ ( V_293 [ 3 ] ^ V_294 [ 3 ] ) ;
V_292 ^= ( V_292 >> 24 ) ^ ( V_292 >> 16 ) ^ ( V_292 >> 8 ) ;
return ( V_292 ^ V_172 -> V_173 [ 5 ] ^ V_172 -> V_287 [ 5 ] ) % V_284 ;
}
return F_208 ( V_29 , V_284 ) ;
}
static int F_215 ( struct V_28 * V_29 , int V_284 )
{
T_2 V_299 = 0 ;
struct V_288 * V_289 ;
struct V_290 * V_291 ;
T_8 * V_293 , * V_294 ;
T_9 * V_300 ;
if ( V_29 -> V_252 == F_189 ( V_259 ) &&
F_211 ( V_29 ) >= sizeof( * V_289 ) ) {
V_289 = F_212 ( V_29 ) ;
if ( ! F_216 ( V_289 ) &&
( V_289 -> V_252 == V_301 ||
V_289 -> V_252 == V_302 ) &&
( F_186 ( V_29 ) - F_217 ( V_29 ) >=
V_289 -> V_303 * sizeof( T_2 ) + sizeof( * V_300 ) * 2 ) ) {
V_300 = ( T_9 * ) ( ( T_2 * ) V_289 + V_289 -> V_303 ) ;
V_299 = F_218 ( * V_300 ^ * ( V_300 + 1 ) ) ;
}
return ( V_299 ^
( ( F_213 ( V_289 -> V_295 ^ V_289 -> V_296 ) ) & 0xffff ) ) % V_284 ;
} else if ( V_29 -> V_252 == F_189 ( V_297 ) &&
F_211 ( V_29 ) >= sizeof( * V_291 ) ) {
V_291 = F_214 ( V_29 ) ;
if ( ( V_291 -> V_304 == V_301 ||
V_291 -> V_304 == V_302 ) &&
( F_186 ( V_29 ) - F_217 ( V_29 ) >=
sizeof( * V_291 ) + sizeof( * V_300 ) * 2 ) ) {
V_300 = ( T_9 * ) ( V_291 + 1 ) ;
V_299 = F_218 ( * V_300 ^ * ( V_300 + 1 ) ) ;
}
V_293 = & V_291 -> V_295 . V_298 [ 0 ] ;
V_294 = & V_291 -> V_296 . V_298 [ 0 ] ;
V_299 ^= ( V_293 [ 1 ] ^ V_294 [ 1 ] ) ^ ( V_293 [ 2 ] ^ V_294 [ 2 ] ) ^ ( V_293 [ 3 ] ^ V_294 [ 3 ] ) ;
V_299 ^= ( V_299 >> 24 ) ^ ( V_299 >> 16 ) ^
( V_299 >> 8 ) ;
return V_299 % V_284 ;
}
return F_208 ( V_29 , V_284 ) ;
}
static void F_219 ( struct V_10 * V_11 )
{
F_220 ( & V_11 -> V_89 ,
F_71 ) ;
F_220 ( & V_11 -> V_305 , V_306 ) ;
F_220 ( & V_11 -> V_231 , F_167 ) ;
if ( V_11 -> V_42 . V_1 == V_4 )
F_220 ( & V_11 -> V_262 , F_198 ) ;
else
F_220 ( & V_11 -> V_262 , F_191 ) ;
F_220 ( & V_11 -> V_307 , V_308 ) ;
}
static void F_221 ( struct V_10 * V_11 )
{
F_222 ( & V_11 -> V_231 ) ;
F_222 ( & V_11 -> V_262 ) ;
F_222 ( & V_11 -> V_305 ) ;
F_222 ( & V_11 -> V_307 ) ;
F_222 ( & V_11 -> V_89 ) ;
}
static int F_223 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
int V_38 ;
F_67 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_40 > 0 ) {
F_67 ( & V_11 -> V_123 ) ;
F_30 (bond, slave, i) {
if ( ( V_11 -> V_42 . V_1 == V_4 )
&& ( V_36 != V_11 -> V_77 ) ) {
F_88 ( V_36 ) ;
} else {
F_89 ( V_36 ) ;
}
}
F_70 ( & V_11 -> V_123 ) ;
}
F_70 ( & V_11 -> V_20 ) ;
F_219 ( V_11 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_224 ( V_11 , ( V_11 -> V_42 . V_1 == V_9 ) ) )
return - V_18 ;
F_69 ( V_11 -> V_88 , & V_11 -> V_305 , 0 ) ;
}
if ( V_11 -> V_42 . V_119 )
F_69 ( V_11 -> V_88 , & V_11 -> V_231 , 0 ) ;
if ( V_11 -> V_42 . V_168 ) {
F_69 ( V_11 -> V_88 , & V_11 -> V_262 , 0 ) ;
if ( V_11 -> V_42 . V_261 )
V_11 -> F_115 = F_183 ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_69 ( V_11 -> V_88 , & V_11 -> V_307 , 0 ) ;
V_11 -> F_115 = V_309 ;
F_225 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_226 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_115 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_221 ( V_11 ) ;
if ( F_13 ( V_11 ) ) {
F_227 ( V_11 ) ;
}
V_11 -> F_115 = NULL ;
return 0 ;
}
static struct V_310 * F_228 ( struct V_30 * V_34 ,
struct V_310 * V_311 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_310 V_312 ;
struct V_36 * V_36 ;
int V_38 ;
memset ( V_311 , 0 , sizeof( * V_311 ) ) ;
F_229 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
const struct V_310 * V_313 =
F_230 ( V_36 -> V_15 , & V_312 ) ;
V_311 -> V_314 += V_313 -> V_314 ;
V_311 -> V_315 += V_313 -> V_315 ;
V_311 -> V_316 += V_313 -> V_316 ;
V_311 -> V_317 += V_313 -> V_317 ;
V_311 -> V_318 += V_313 -> V_318 ;
V_311 -> V_319 += V_313 -> V_319 ;
V_311 -> V_320 += V_313 -> V_320 ;
V_311 -> V_321 += V_313 -> V_321 ;
V_311 -> V_322 += V_313 -> V_322 ;
V_311 -> V_323 += V_313 -> V_323 ;
V_311 -> V_324 += V_313 -> V_324 ;
V_311 -> V_325 += V_313 -> V_325 ;
V_311 -> V_326 += V_313 -> V_326 ;
V_311 -> V_327 += V_313 -> V_327 ;
V_311 -> V_328 += V_313 -> V_328 ;
V_311 -> V_329 += V_313 -> V_329 ;
V_311 -> V_330 += V_313 -> V_330 ;
V_311 -> V_331 += V_313 -> V_331 ;
V_311 -> V_332 += V_313 -> V_332 ;
V_311 -> V_333 += V_313 -> V_333 ;
V_311 -> V_334 += V_313 -> V_334 ;
}
F_231 ( & V_11 -> V_20 ) ;
return V_311 ;
}
static int F_232 ( struct V_30 * V_34 , struct V_59 * V_60 , int V_335 )
{
struct V_30 * V_31 = NULL ;
struct V_215 V_336 ;
struct V_215 T_10 * V_337 = NULL ;
struct V_219 V_338 ;
struct V_219 T_10 * V_339 = NULL ;
struct V_61 * V_62 = NULL ;
int V_21 = 0 ;
F_3 ( L_102 , V_34 -> V_16 , V_335 ) ;
switch ( V_335 ) {
case V_70 :
V_62 = F_50 ( V_60 ) ;
if ( ! V_62 )
return - V_185 ;
V_62 -> V_340 = 0 ;
case V_73 :
V_62 = F_50 ( V_60 ) ;
if ( ! V_62 )
return - V_185 ;
if ( V_62 -> V_71 == 1 ) {
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_62 -> V_74 = 0 ;
F_67 ( & V_11 -> V_20 ) ;
F_67 ( & V_11 -> V_123 ) ;
if ( F_41 ( V_11 -> V_15 ) )
V_62 -> V_74 = V_64 ;
F_70 ( & V_11 -> V_123 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_341 :
case V_342 :
V_337 = (struct V_215 T_10 * ) V_60 -> V_343 ;
if ( F_233 ( & V_336 , V_337 , sizeof( V_215 ) ) )
return - V_344 ;
V_21 = F_160 ( V_34 , & V_336 ) ;
if ( V_21 == 0 &&
F_234 ( V_337 , & V_336 , sizeof( V_215 ) ) )
return - V_344 ;
return V_21 ;
case V_345 :
case V_346 :
V_339 = (struct V_219 T_10 * ) V_60 -> V_343 ;
if ( F_233 ( & V_338 , V_339 , sizeof( V_219 ) ) )
return - V_344 ;
V_21 = F_161 ( V_34 , & V_338 ) ;
if ( V_21 == 0 &&
F_234 ( V_339 , & V_338 , sizeof( V_219 ) ) )
return - V_344 ;
return V_21 ;
default:
break;
}
if ( ! F_235 ( V_347 ) )
return - V_178 ;
V_31 = F_236 ( F_178 ( V_34 ) , V_60 -> V_348 ) ;
F_3 ( L_103 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_104 , V_31 -> V_16 ) ;
switch ( V_335 ) {
case V_349 :
case V_350 :
V_21 = F_124 ( V_34 , V_31 ) ;
break;
case V_351 :
case V_352 :
V_21 = F_149 ( V_34 , V_31 ) ;
break;
case V_353 :
case V_354 :
V_21 = F_104 ( V_34 , V_31 ) ;
break;
case V_355 :
case V_356 :
V_21 = F_159 ( V_34 , V_31 ) ;
break;
default:
V_21 = - V_188 ;
}
F_237 ( V_31 ) ;
}
return V_21 ;
}
static bool F_238 ( unsigned char * V_78 ,
struct V_357 * V_358 ,
int V_359 )
{
struct V_93 * V_94 ;
F_239 (ha, list)
if ( ! memcmp ( V_94 -> V_78 , V_78 , V_359 ) )
return true ;
return false ;
}
static void F_240 ( struct V_30 * V_34 , int V_360 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_360 & V_101 )
F_52 ( V_11 ,
V_34 -> V_100 & V_101 ? 1 : - 1 ) ;
if ( V_360 & V_102 )
F_55 ( V_11 ,
V_34 -> V_100 & V_102 ? 1 : - 1 ) ;
}
static void F_241 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_93 * V_94 ;
bool V_361 ;
F_67 ( & V_11 -> V_20 ) ;
F_74 (ha, bond_dev) {
V_361 = F_238 ( V_94 -> V_78 , & V_11 -> V_362 ,
V_34 -> V_139 ) ;
if ( ! V_361 )
F_57 ( V_11 , V_94 -> V_78 ) ;
}
F_239 (ha, &bond->mc_list) {
V_361 = F_238 ( V_94 -> V_78 , & V_34 -> V_363 ,
V_34 -> V_139 ) ;
if ( ! V_361 )
F_59 ( V_11 , V_94 -> V_78 ) ;
}
F_242 ( & V_11 -> V_362 ) ;
F_243 ( & V_11 -> V_362 , & V_34 -> V_363 ,
V_34 -> V_139 , V_364 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_244 ( struct V_365 * V_366 )
{
struct V_10 * V_11 = F_29 ( V_366 -> V_15 ) ;
struct V_36 * V_36 = V_11 -> V_112 ;
const struct V_56 * V_57 ;
struct V_367 V_368 ;
int V_165 ;
if ( ! V_36 )
return 0 ;
V_57 = V_36 -> V_15 -> V_58 ;
if ( ! V_57 -> V_369 )
return 0 ;
V_368 . V_370 = NULL ;
V_368 . V_371 = NULL ;
V_165 = V_57 -> V_369 ( V_36 -> V_15 , & V_368 ) ;
if ( V_165 )
return V_165 ;
V_366 -> V_368 -> V_371 = V_368 . V_371 ;
if ( ! V_368 . V_370 )
return 0 ;
return V_368 . V_370 ( V_366 ) ;
}
static int F_245 ( struct V_30 * V_15 ,
struct V_367 * V_368 )
{
V_368 -> V_370 = F_244 ;
return 0 ;
}
static int F_246 ( struct V_30 * V_34 , int V_372 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_37 ;
int V_21 = 0 ;
int V_38 ;
F_3 ( L_105 , V_11 ,
( V_34 ? V_34 -> V_16 : L_10 ) , V_372 ) ;
F_30 (bond, slave, i) {
F_3 ( L_106 ,
V_36 ,
V_36 -> V_27 ,
V_36 -> V_15 -> V_58 -> V_373 ) ;
V_21 = F_131 ( V_36 -> V_15 , V_372 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
}
V_34 -> V_192 = V_372 ;
return 0 ;
V_39:
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_374 ;
V_374 = F_131 ( V_36 -> V_15 , V_34 -> V_192 ) ;
if ( V_374 ) {
F_3 ( L_108 ,
V_374 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_247 ( struct V_30 * V_34 , void * V_78 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_174 * V_375 = V_78 , V_376 ;
struct V_36 * V_36 , * V_37 ;
int V_21 = 0 ;
int V_38 ;
if ( V_11 -> V_42 . V_1 == V_9 )
return F_248 ( V_34 , V_78 ) ;
F_3 ( L_109 ,
V_11 , V_34 ? V_34 -> V_16 : L_10 ) ;
if ( V_11 -> V_42 . V_121 == V_187 )
return 0 ;
if ( ! F_249 ( V_375 -> V_195 ) )
return - V_377 ;
F_30 (bond, slave, i) {
const struct V_56 * V_57 = V_36 -> V_15 -> V_58 ;
F_3 ( L_110 , V_36 , V_36 -> V_15 -> V_16 ) ;
if ( V_57 -> V_186 == NULL ) {
V_21 = - V_188 ;
F_3 ( L_111 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
V_21 = F_132 ( V_36 -> V_15 , V_78 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
}
memcpy ( V_34 -> V_140 , V_375 -> V_195 , V_34 -> V_139 ) ;
return 0 ;
V_39:
memcpy ( V_376 . V_195 , V_34 -> V_140 , V_34 -> V_139 ) ;
V_376 . V_196 = V_34 -> type ;
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_374 ;
V_374 = F_132 ( V_36 -> V_15 , & V_376 ) ;
if ( V_374 ) {
F_3 ( L_108 ,
V_374 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_250 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_378 ;
int V_38 , V_379 , V_21 = 1 ;
struct V_288 * V_289 = F_212 ( V_29 ) ;
if ( ( V_289 -> V_252 == V_380 ) &&
( V_29 -> V_252 == F_189 ( V_259 ) ) ) {
F_67 ( & V_11 -> V_123 ) ;
V_36 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_36 )
goto V_23;
} else {
V_379 = V_11 -> V_381 ++ % V_11 -> V_40 ;
F_30 (bond, slave, i) {
V_379 -- ;
if ( V_379 < 0 )
break;
}
}
V_378 = V_36 ;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_146 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_122 ( V_29 ) ;
}
return V_382 ;
}
static int F_251 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_21 = 1 ;
F_67 ( & V_11 -> V_123 ) ;
if ( V_11 -> V_77 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_77 -> V_15 ) ;
F_70 ( & V_11 -> V_123 ) ;
if ( V_21 )
F_122 ( V_29 ) ;
return V_382 ;
}
static int F_252 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_378 ;
int V_379 ;
int V_38 ;
int V_21 = 1 ;
V_379 = V_11 -> V_383 ( V_29 , V_11 -> V_40 ) ;
F_30 (bond, slave, i) {
V_379 -- ;
if ( V_379 < 0 )
break;
}
V_378 = V_36 ;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_146 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_122 ( V_29 ) ;
}
return V_382 ;
}
static int F_253 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_378 ;
struct V_30 * V_384 = NULL ;
int V_38 ;
int V_21 = 1 ;
F_67 ( & V_11 -> V_123 ) ;
V_378 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_378 )
goto V_23;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_146 ( V_36 ) ) {
if ( V_384 ) {
struct V_28 * V_385 = F_254 ( V_29 , V_132 ) ;
if ( ! V_385 ) {
F_32 ( L_112 ,
V_34 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_385 , V_384 ) ;
if ( V_21 ) {
F_122 ( V_385 ) ;
continue;
}
}
V_384 = V_36 -> V_15 ;
}
}
if ( V_384 )
V_21 = F_20 ( V_11 , V_29 , V_384 ) ;
V_23:
if ( V_21 )
F_122 ( V_29 ) ;
return V_382 ;
}
static void F_255 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_42 . V_386 ) {
case V_387 :
V_11 -> V_383 = F_210 ;
break;
case V_388 :
V_11 -> V_383 = F_215 ;
break;
case V_389 :
default:
V_11 -> V_383 = F_208 ;
break;
}
}
static inline int F_256 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_38 , V_21 = 1 ;
struct V_36 * V_36 = NULL ;
struct V_36 * V_390 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_30 (bond, check_slave, i) {
if ( V_390 -> V_190 == V_29 -> V_32 ) {
V_36 = V_390 ;
break;
}
}
if ( V_36 && V_36 -> V_190 && F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
}
return V_21 ;
}
static T_6 F_257 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_6 V_391 = F_258 ( V_29 ) ? F_259 ( V_29 ) : 0 ;
F_22 ( V_29 ) -> V_33 = V_29 -> V_32 ;
if ( F_23 ( V_391 >= V_15 -> V_392 ) ) {
do {
V_391 -= V_15 -> V_392 ;
} while ( V_391 >= V_15 -> V_392 );
}
return V_391 ;
}
static T_11 F_260 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
if ( F_261 ( V_11 -> V_42 . V_1 ) ) {
if ( ! F_256 ( V_11 , V_29 ) )
return V_382 ;
}
switch ( V_11 -> V_42 . V_1 ) {
case V_3 :
return F_250 ( V_29 , V_15 ) ;
case V_4 :
return F_251 ( V_29 , V_15 ) ;
case V_5 :
return F_252 ( V_29 , V_15 ) ;
case V_6 :
return F_253 ( V_29 , V_15 ) ;
case V_7 :
return F_262 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_263 ( V_29 , V_15 ) ;
default:
F_32 ( L_113 ,
V_15 -> V_16 , V_11 -> V_42 . V_1 ) ;
F_264 ( 1 ) ;
F_122 ( V_29 ) ;
return V_382 ;
}
}
static T_11 F_265 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_11 V_165 = V_382 ;
if ( F_266 ( V_15 ) )
return V_393 ;
F_67 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_40 )
V_165 = F_260 ( V_29 , V_15 ) ;
else
F_122 ( V_29 ) ;
F_70 ( & V_11 -> V_20 ) ;
return V_165 ;
}
void F_267 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_34 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_255 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_255 ( V_11 ) ;
break;
case V_9 :
case V_8 :
break;
default:
F_32 ( L_113 ,
V_34 -> V_16 , V_1 ) ;
break;
}
}
static void F_268 ( struct V_30 * V_34 ,
struct V_394 * V_395 )
{
strncpy ( V_395 -> V_396 , V_397 , 32 ) ;
strncpy ( V_395 -> V_398 , V_399 , 32 ) ;
snprintf ( V_395 -> V_400 , 32 , L_114 , V_401 ) ;
}
static void F_269 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_11 -> V_88 )
F_270 ( V_11 -> V_88 ) ;
F_271 ( V_34 ) ;
}
static void F_272 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_273 ( & V_11 -> V_20 ) ;
F_273 ( & V_11 -> V_123 ) ;
V_11 -> V_42 = V_402 ;
V_11 -> V_15 = V_34 ;
F_5 ( & V_11 -> V_19 ) ;
F_129 ( V_34 ) ;
V_34 -> V_58 = & V_403 ;
V_34 -> V_65 = & V_404 ;
F_267 ( V_11 , V_11 -> V_42 . V_1 ) ;
V_34 -> V_405 = F_269 ;
V_34 -> V_406 = 0 ;
V_34 -> V_100 |= V_283 | V_407 ;
V_34 -> V_84 |= V_200 ;
V_34 -> V_84 &= ~ ( V_155 | V_183 ) ;
V_34 -> V_141 |= V_143 ;
V_34 -> V_141 |= V_408 ;
V_34 -> V_409 = V_147 |
V_410 |
V_411 |
V_412 ;
V_34 -> V_409 &= ~ ( V_413 & ~ V_414 ) ;
V_34 -> V_141 |= V_34 -> V_409 ;
}
static void F_274 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_13 * V_14 , * V_415 ;
F_101 ( V_34 ) ;
F_158 ( V_34 ) ;
F_12 ( & V_11 -> V_416 ) ;
F_275 ( V_11 ) ;
F_242 ( & V_11 -> V_362 ) ;
F_276 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_277 ( const char * V_417 , const struct V_418 * V_419 )
{
int V_420 = - 1 , V_38 , V_128 ;
char * V_421 , V_422 [ V_423 + 1 ] = { 0 , } ;
for ( V_421 = ( char * ) V_417 ; * V_421 ; V_421 ++ )
if ( ! ( isdigit ( * V_421 ) || isspace ( * V_421 ) ) )
break;
if ( * V_421 )
V_128 = sscanf ( V_417 , L_115 , V_422 ) ;
else
V_128 = sscanf ( V_417 , L_114 , & V_420 ) ;
if ( ! V_128 )
return - 1 ;
for ( V_38 = 0 ; V_419 [ V_38 ] . V_424 ; V_38 ++ ) {
if ( V_420 == V_419 [ V_38 ] . V_1 )
return V_419 [ V_38 ] . V_1 ;
if ( strcmp ( V_422 , V_419 [ V_38 ] . V_424 ) == 0 )
return V_419 [ V_38 ] . V_1 ;
}
return - 1 ;
}
static int F_278 ( struct V_425 * V_42 )
{
int V_426 , V_427 , V_428 ;
if ( V_1 ) {
V_217 = F_277 ( V_1 , V_429 ) ;
if ( V_217 == - 1 ) {
F_32 ( L_116 ,
V_1 == NULL ? L_18 : V_1 ) ;
return - V_185 ;
}
}
if ( V_383 ) {
if ( ( V_217 != V_5 ) &&
( V_217 != V_7 ) ) {
F_84 ( L_117 ,
F_1 ( V_217 ) ) ;
} else {
V_430 = F_277 ( V_383 ,
V_431 ) ;
if ( V_430 == - 1 ) {
F_32 ( L_118 ,
V_383 == NULL ? L_18 :
V_383 ) ;
return - V_185 ;
}
}
}
if ( V_432 ) {
if ( V_217 != V_7 ) {
F_84 ( L_119 ,
F_1 ( V_217 ) ) ;
} else {
V_433 = F_277 ( V_432 , V_434 ) ;
if ( V_433 == - 1 ) {
F_32 ( L_120 ,
V_432 == NULL ? L_18 : V_432 ) ;
return - V_185 ;
}
}
}
if ( V_435 ) {
V_42 -> V_435 = F_277 ( V_435 , V_436 ) ;
if ( V_42 -> V_435 == - 1 ) {
F_32 ( L_121 ,
V_435 == NULL ? L_18 : V_435 ) ;
return - V_185 ;
}
if ( V_217 != V_7 ) {
F_37 ( L_122 ) ;
}
} else {
V_42 -> V_435 = V_437 ;
}
if ( V_438 < 0 ) {
F_37 ( L_123 ,
V_438 , 0 , V_439 , V_440 ) ;
V_438 = V_440 ;
}
if ( V_119 < 0 ) {
F_37 ( L_124 ,
V_119 , V_439 , V_441 ) ;
V_119 = V_441 ;
}
if ( V_111 < 0 ) {
F_37 ( L_125 ,
V_111 , V_439 ) ;
V_111 = 0 ;
}
if ( V_228 < 0 ) {
F_37 ( L_126 ,
V_228 , V_439 ) ;
V_228 = 0 ;
}
if ( ( V_63 != 0 ) && ( V_63 != 1 ) ) {
F_37 ( L_127 ,
V_63 ) ;
V_63 = 1 ;
}
if ( V_122 < 0 || V_122 > 255 ) {
F_37 ( L_128 ,
V_122 ) ;
V_122 = 1 ;
}
if ( V_217 == V_7 ) {
if ( ! V_119 ) {
F_37 ( L_129 ) ;
F_37 ( L_130 ) ;
V_119 = 100 ;
}
}
if ( V_442 < 1 || V_442 > 255 ) {
F_37 ( L_131
L_132 ,
V_442 , V_443 ) ;
V_442 = V_443 ;
}
if ( ( V_444 != 0 ) && ( V_444 != 1 ) ) {
F_37 ( L_133
L_134
L_135 , V_444 ) ;
V_444 = 0 ;
}
if ( V_126 < 0 || V_126 > 255 ) {
F_37 ( L_136
L_137 ,
V_126 , V_445 ) ;
V_126 = V_445 ;
}
if ( ( V_217 == V_8 ) ||
( V_217 == V_9 ) ) {
if ( ! V_119 ) {
F_37 ( L_138 ) ;
F_37 ( L_130 ) ;
V_119 = 100 ;
}
}
if ( V_217 == V_9 ) {
F_279 ( L_139 ,
V_111 ) ;
}
if ( ! V_119 ) {
if ( V_111 || V_228 ) {
F_37 ( L_140 ,
V_111 , V_228 ) ;
}
} else {
if ( V_168 ) {
F_37 ( L_141 ,
V_119 , V_168 ) ;
V_168 = 0 ;
}
if ( ( V_111 % V_119 ) != 0 ) {
F_37 ( L_142 ,
V_111 , V_119 ,
( V_111 / V_119 ) * V_119 ) ;
}
V_111 /= V_119 ;
if ( ( V_228 % V_119 ) != 0 ) {
F_37 ( L_143 ,
V_228 , V_119 ,
( V_228 / V_119 ) * V_119 ) ;
}
V_228 /= V_119 ;
}
if ( V_168 < 0 ) {
F_37 ( L_144 ,
V_168 , V_439 , V_446 ) ;
V_168 = V_446 ;
}
for ( V_447 = 0 ;
( V_447 < V_242 ) && V_448 [ V_447 ] ;
V_447 ++ ) {
T_8 V_233 = F_280 ( V_448 [ V_447 ] ) ;
if ( ! isdigit ( V_448 [ V_447 ] [ 0 ] ) ||
V_233 == 0 || V_233 == F_281 ( V_449 ) ) {
F_37 ( L_145 ,
V_448 [ V_447 ] ) ;
V_168 = 0 ;
} else {
V_450 [ V_447 ] = V_233 ;
}
}
if ( V_168 && ! V_447 ) {
F_37 ( L_146 ,
V_168 ) ;
V_168 = 0 ;
}
if ( V_261 ) {
if ( V_217 != V_4 ) {
F_32 ( L_147 ) ;
return - V_185 ;
}
if ( ! V_168 ) {
F_32 ( L_148 ) ;
return - V_185 ;
}
V_426 = F_277 ( V_261 ,
V_451 ) ;
if ( V_426 == - 1 ) {
F_32 ( L_149 ,
V_261 == NULL ? L_18 : V_261 ) ;
return - V_185 ;
}
} else
V_426 = 0 ;
if ( V_119 ) {
F_84 ( L_150 , V_119 ) ;
} else if ( V_168 ) {
int V_38 ;
F_84 ( L_151 ,
V_168 ,
V_451 [ V_426 ] . V_424 ,
V_447 ) ;
for ( V_38 = 0 ; V_38 < V_447 ; V_38 ++ )
F_84 ( L_152 , V_448 [ V_38 ] ) ;
F_84 ( L_153 ) ;
} else if ( V_438 ) {
F_3 ( L_154 ) ;
}
if ( V_205 && ! F_53 ( V_217 ) ) {
F_37 ( L_155 ,
V_205 , F_1 ( V_217 ) ) ;
V_205 = NULL ;
}
if ( V_205 && V_106 ) {
V_428 = F_277 ( V_106 ,
V_452 ) ;
if ( V_428 == - 1 ) {
F_32 ( L_156 ,
V_106 ==
NULL ? L_18 : V_106 ) ;
return - V_185 ;
}
} else {
V_428 = V_453 ;
}
if ( V_121 ) {
V_427 = F_277 ( V_121 ,
V_454 ) ;
if ( V_427 == - 1 ) {
F_32 ( L_157 ,
V_261 == NULL ? L_18 : V_261 ) ;
return - V_185 ;
}
if ( V_217 != V_4 )
F_37 ( L_158 ) ;
} else {
V_427 = V_455 ;
}
V_42 -> V_1 = V_217 ;
V_42 -> V_386 = V_430 ;
V_42 -> V_119 = V_119 ;
V_42 -> V_122 = V_122 ;
V_42 -> V_168 = V_168 ;
V_42 -> V_261 = V_426 ;
V_42 -> V_111 = V_111 ;
V_42 -> V_228 = V_228 ;
V_42 -> V_63 = V_63 ;
V_42 -> V_433 = V_433 ;
V_42 -> V_205 [ 0 ] = 0 ;
V_42 -> V_106 = V_428 ;
V_42 -> V_121 = V_427 ;
V_42 -> V_442 = V_442 ;
V_42 -> V_444 = V_444 ;
V_42 -> V_126 = V_126 ;
V_42 -> V_456 = V_456 ;
if ( V_205 ) {
strncpy ( V_42 -> V_205 , V_205 , V_69 ) ;
V_42 -> V_205 [ V_69 - 1 ] = 0 ;
}
memcpy ( V_42 -> V_239 , V_450 , sizeof( V_450 ) ) ;
return 0 ;
}
static void F_282 ( struct V_30 * V_15 ,
struct V_457 * V_391 ,
void * V_458 )
{
F_283 ( & V_391 -> V_459 ,
& V_460 ) ;
}
static void F_284 ( struct V_30 * V_15 )
{
F_283 ( & V_15 -> V_461 ,
& V_462 ) ;
F_285 ( V_15 , F_282 , NULL ) ;
V_15 -> V_463 = & V_464 ;
}
static int F_286 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_465 * V_466 = F_287 ( F_178 ( V_34 ) , V_467 ) ;
struct V_468 * V_469 = & ( F_288 ( V_11 ) ) ;
F_3 ( L_159 , V_34 -> V_16 ) ;
F_289 ( & ( V_469 -> V_470 ) ) ;
F_289 ( & ( V_469 -> V_471 ) ) ;
V_11 -> V_88 = F_290 ( V_34 -> V_16 ) ;
if ( ! V_11 -> V_88 )
return - V_18 ;
F_284 ( V_34 ) ;
F_7 ( & V_11 -> V_416 , & V_466 -> V_472 ) ;
F_291 ( V_11 ) ;
F_292 ( V_11 ) ;
F_293 ( & V_11 -> V_362 ) ;
return 0 ;
}
static int F_294 ( struct V_473 * V_474 [] , struct V_473 * V_172 [] )
{
if ( V_474 [ V_475 ] ) {
if ( F_295 ( V_474 [ V_475 ] ) != V_96 )
return - V_185 ;
if ( ! F_249 ( F_296 ( V_474 [ V_475 ] ) ) )
return - V_377 ;
}
return 0 ;
}
static unsigned int F_297 ( void )
{
return V_442 ;
}
int F_298 ( struct V_476 * V_476 , const char * V_16 )
{
struct V_30 * V_34 ;
int V_21 ;
F_299 () ;
V_34 = F_300 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_160 ,
F_272 , V_442 ) ;
if ( ! V_34 ) {
F_32 ( L_161 , V_16 ) ;
F_169 () ;
return - V_18 ;
}
F_301 ( V_34 , V_476 ) ;
V_34 -> V_477 = & V_478 ;
V_21 = F_302 ( V_34 ) ;
F_43 ( V_34 ) ;
F_169 () ;
if ( V_21 < 0 )
F_269 ( V_34 ) ;
return V_21 ;
}
static int T_12 F_303 ( struct V_476 * V_476 )
{
struct V_465 * V_466 = F_287 ( V_476 , V_467 ) ;
V_466 -> V_476 = V_476 ;
F_5 ( & V_466 -> V_472 ) ;
F_304 ( V_466 ) ;
F_305 ( V_466 ) ;
return 0 ;
}
static void T_13 F_306 ( struct V_476 * V_476 )
{
struct V_465 * V_466 = F_287 ( V_476 , V_467 ) ;
F_307 ( V_466 ) ;
F_308 ( V_466 ) ;
}
static int T_14 F_309 ( void )
{
int V_38 ;
int V_21 ;
F_84 ( L_162 , V_479 ) ;
V_21 = F_278 ( & V_402 ) ;
if ( V_21 )
goto V_23;
V_21 = F_310 ( & V_480 ) ;
if ( V_21 )
goto V_23;
V_21 = F_311 ( & V_478 ) ;
if ( V_21 )
goto V_481;
F_312 () ;
for ( V_38 = 0 ; V_38 < V_438 ; V_38 ++ ) {
V_21 = F_298 ( & V_482 , NULL ) ;
if ( V_21 )
goto V_76;
}
F_313 ( & V_483 ) ;
V_23:
return V_21 ;
V_76:
F_314 ( & V_478 ) ;
V_481:
F_315 ( & V_480 ) ;
goto V_23;
}
static void T_15 F_316 ( void )
{
F_317 ( & V_483 ) ;
F_318 () ;
F_314 ( & V_478 ) ;
F_315 ( & V_480 ) ;
#ifdef F_143
F_319 ( F_320 ( & V_484 ) ) ;
#endif
}
