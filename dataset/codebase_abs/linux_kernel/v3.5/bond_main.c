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
if ( F_23 ( F_24 ( V_31 ) ) )
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
if ( V_31 -> V_65 ) {
if ( V_31 -> V_65 -> V_66 ) {
T_2 V_43 ;
V_43 = V_31 -> V_65 -> V_66 ( V_31 ) ;
return V_43 ? V_64 : 0 ;
}
}
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
F_90 ( V_11 -> V_15 , V_124 ) ;
if ( V_120 )
F_90 ( V_11 -> V_15 ,
V_125 ) ;
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
V_131 = F_4 ( sizeof( * V_131 ) , V_17 ) ;
V_76 = - V_18 ;
if ( ! V_131 )
goto V_23;
V_131 -> V_15 = V_36 -> V_15 ;
F_95 ( V_131 -> V_132 , V_36 -> V_15 -> V_16 , V_69 ) ;
V_76 = F_96 ( V_131 ) ;
if ( V_76 ) {
F_15 ( V_131 ) ;
goto V_23;
}
V_36 -> V_131 = V_131 ;
V_23:
return V_76 ;
}
static inline void F_97 ( struct V_36 * V_36 )
{
struct V_130 * V_131 = V_36 -> V_131 ;
if ( ! V_131 )
return;
V_36 -> V_131 = NULL ;
F_98 () ;
F_99 ( V_131 ) ;
F_15 ( V_131 ) ;
}
static inline bool F_100 ( struct V_30 * V_31 )
{
if ( V_31 -> V_84 & V_133 )
return false ;
if ( ! V_31 -> V_58 -> V_134 )
return false ;
return true ;
}
static void F_101 ( struct V_30 * V_34 )
{
}
static void F_102 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i)
if ( F_80 ( V_36 -> V_15 ) )
F_97 ( V_36 ) ;
}
static void F_103 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_67 ( & V_11 -> V_20 ) ;
F_102 ( V_11 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_104 ( struct V_30 * V_15 , struct V_135 * V_136 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
struct V_36 * V_36 ;
int V_38 , V_76 = 0 ;
F_67 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
V_76 = F_94 ( V_36 ) ;
if ( V_76 ) {
F_102 ( V_11 ) ;
break;
}
}
F_70 ( & V_11 -> V_20 ) ;
return V_76 ;
}
static struct V_135 * F_105 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_137 ;
}
static inline int F_94 ( struct V_36 * V_36 )
{
return 0 ;
}
static inline void F_97 ( struct V_36 * V_36 )
{
}
static void F_103 ( struct V_30 * V_34 )
{
}
static int F_106 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_3 ( L_23 , V_34 ) ;
F_3 ( L_24 , V_31 ) ;
F_3 ( L_25 , V_31 -> V_138 ) ;
memcpy ( V_34 -> V_139 , V_31 -> V_139 , V_31 -> V_138 ) ;
return 0 ;
}
static T_4 F_107 ( struct V_30 * V_15 ,
T_4 V_140 )
{
struct V_36 * V_36 ;
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_4 V_141 ;
int V_38 ;
F_67 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_112 ) {
V_140 |= V_142 ;
goto V_23;
}
V_141 = V_140 ;
V_140 &= ~ V_143 ;
V_140 |= V_144 ;
F_30 (bond, slave, i) {
V_140 = F_108 ( V_140 ,
V_36 -> V_15 -> V_140 ,
V_141 ) ;
}
V_23:
F_70 ( & V_11 -> V_20 ) ;
return V_140 ;
}
static void F_109 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
struct V_30 * V_34 = V_11 -> V_15 ;
T_4 V_145 = V_146 ;
unsigned short V_147 = V_148 ;
int V_38 ;
F_67 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_112 )
goto V_149;
F_30 (bond, slave, i) {
V_145 = F_108 ( V_145 ,
V_36 -> V_15 -> V_145 , V_146 ) ;
if ( V_36 -> V_15 -> V_150 > V_147 )
V_147 = V_36 -> V_15 -> V_150 ;
}
V_149:
V_34 -> V_145 = V_145 ;
V_34 -> V_150 = V_147 ;
F_70 ( & V_11 -> V_20 ) ;
F_110 ( V_34 ) ;
}
static void F_111 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_34 -> V_151 = V_31 -> V_151 ;
V_34 -> type = V_31 -> type ;
V_34 -> V_150 = V_31 -> V_150 ;
V_34 -> V_138 = V_31 -> V_138 ;
memcpy ( V_34 -> V_152 , V_31 -> V_152 ,
V_31 -> V_138 ) ;
V_11 -> V_153 = 1 ;
}
static bool F_112 ( struct V_28 * V_29 ,
struct V_36 * V_36 ,
struct V_10 * V_11 )
{
if ( F_113 ( V_36 ) ) {
if ( V_11 -> V_42 . V_1 == V_9 &&
V_29 -> V_154 != V_155 &&
V_29 -> V_154 != V_156 )
return false ;
return true ;
}
return false ;
}
static T_5 F_114 ( struct V_28 * * V_157 )
{
struct V_28 * V_29 = * V_157 ;
struct V_36 * V_36 ;
struct V_10 * V_11 ;
int (* F_115)( struct V_28 * , struct V_10 * ,
struct V_36 * );
int V_158 = V_159 ;
V_29 = F_116 ( V_29 , V_160 ) ;
if ( F_23 ( ! V_29 ) )
return V_161 ;
* V_157 = V_29 ;
V_36 = F_117 ( V_29 -> V_15 ) ;
V_11 = V_36 -> V_11 ;
if ( V_11 -> V_42 . V_162 )
V_36 -> V_15 -> V_163 = V_118 ;
F_115 = F_118 ( V_11 -> F_115 ) ;
if ( F_115 ) {
struct V_28 * V_164 = F_119 ( V_29 , V_160 ) ;
if ( F_120 ( V_164 ) ) {
V_158 = F_115 ( V_164 , V_11 , V_36 ) ;
F_121 ( V_164 ) ;
if ( V_158 == V_161 ) {
F_122 ( V_29 ) ;
return V_158 ;
}
}
}
if ( F_112 ( V_29 , V_36 , V_11 ) ) {
return V_165 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_42 . V_1 == V_9 &&
V_11 -> V_15 -> V_84 & V_86 &&
V_29 -> V_154 == V_166 ) {
if ( F_23 ( F_123 ( V_29 ,
V_29 -> V_167 - F_124 ( V_29 ) ) ) ) {
F_125 ( V_29 ) ;
return V_161 ;
}
memcpy ( F_126 ( V_29 ) -> V_168 , V_11 -> V_15 -> V_139 , V_96 ) ;
}
return V_158 ;
}
int F_127 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
const struct V_56 * V_57 = V_31 -> V_58 ;
struct V_36 * V_129 = NULL ;
struct V_93 * V_94 ;
struct V_169 V_78 ;
int V_170 ;
int V_21 = 0 ;
if ( ! V_11 -> V_42 . V_63 && V_31 -> V_65 == NULL &&
V_57 -> V_67 == NULL ) {
F_37 ( L_26 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_100 & V_171 ) {
F_3 ( L_27 ) ;
return - V_172 ;
}
if ( V_31 -> V_140 & V_142 ) {
F_3 ( L_28 , V_31 -> V_16 ) ;
if ( F_128 ( V_11 ) ) {
F_32 ( L_29 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
return - V_173 ;
} else {
F_37 ( L_30 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_34 -> V_16 ) ;
}
} else {
F_3 ( L_31 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_100 & V_174 ) ) {
F_32 ( L_32 ,
V_31 -> V_16 ) ;
V_21 = - V_173 ;
goto V_175;
}
if ( V_11 -> V_40 == 0 ) {
if ( V_34 -> type != V_31 -> type ) {
F_3 ( L_33 ,
V_34 -> V_16 ,
V_34 -> type , V_31 -> type ) ;
V_21 = F_90 ( V_34 ,
V_176 ) ;
V_21 = F_129 ( V_21 ) ;
if ( V_21 ) {
F_32 ( L_34 ,
V_34 -> V_16 ) ;
V_21 = - V_172 ;
goto V_175;
}
F_130 ( V_34 ) ;
F_131 ( V_34 ) ;
if ( V_31 -> type != V_177 )
F_111 ( V_34 , V_31 ) ;
else {
F_132 ( V_34 ) ;
V_34 -> V_84 &= ~ V_178 ;
}
F_90 ( V_34 ,
V_179 ) ;
}
} else if ( V_34 -> type != V_31 -> type ) {
F_32 ( L_35 ,
V_31 -> V_16 ,
V_31 -> type , V_34 -> type ) ;
V_21 = - V_180 ;
goto V_175;
}
if ( V_57 -> V_181 == NULL ) {
if ( V_11 -> V_40 == 0 ) {
F_37 ( L_36 ,
V_34 -> V_16 ) ;
V_11 -> V_42 . V_121 = V_182 ;
} else if ( V_11 -> V_42 . V_121 != V_182 ) {
F_32 ( L_37 ,
V_34 -> V_16 ) ;
V_21 = - V_183 ;
goto V_175;
}
}
F_133 ( V_184 , V_31 ) ;
if ( F_134 ( V_11 -> V_15 -> V_139 ) )
memcpy ( V_11 -> V_15 -> V_139 , V_31 -> V_139 ,
V_31 -> V_138 ) ;
V_129 = F_4 ( sizeof( struct V_36 ) , V_17 ) ;
if ( ! V_129 ) {
V_21 = - V_18 ;
goto V_175;
}
V_129 -> V_185 = 0 ;
V_129 -> V_186 = V_31 -> V_187 ;
V_21 = F_135 ( V_31 , V_11 -> V_15 -> V_187 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_188;
}
memcpy ( V_129 -> V_189 , V_31 -> V_139 , V_96 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_190 , V_34 -> V_139 , V_34 -> V_138 ) ;
V_78 . V_191 = V_31 -> type ;
V_21 = F_136 ( V_31 , & V_78 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_192;
}
}
V_21 = F_137 ( V_31 , V_34 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_21 ) ;
goto V_193;
}
V_21 = F_138 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_41 , V_31 -> V_16 ) ;
goto V_194;
}
V_129 -> V_11 = V_11 ;
V_129 -> V_15 = V_31 ;
V_31 -> V_84 |= V_195 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_139 ( V_11 , V_129 ) ;
if ( V_21 )
goto V_196;
}
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 ) {
V_21 = F_54 ( V_31 , 1 ) ;
if ( V_21 )
goto V_196;
}
if ( V_34 -> V_100 & V_102 ) {
V_21 = F_56 ( V_31 , 1 ) ;
if ( V_21 )
goto V_196;
}
F_140 ( V_34 ) ;
F_74 (ha, bond_dev)
F_58 ( V_31 , V_94 -> V_78 ) ;
F_141 ( V_34 ) ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
T_3 V_95 [ V_96 ] = V_97 ;
F_58 ( V_31 , V_95 ) ;
}
F_36 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_92 ( V_11 , V_129 ) ;
V_129 -> V_114 = 0 ;
V_129 -> V_197 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_109 ( V_11 ) ;
F_67 ( & V_11 -> V_20 ) ;
V_129 -> V_198 = V_118 -
( F_142 ( V_11 -> V_42 . V_162 ) + 1 ) ;
if ( V_11 -> V_42 . V_119 && ! V_11 -> V_42 . V_63 ) {
V_170 = F_47 ( V_11 , V_31 , 1 ) ;
if ( ( V_170 == - 1 ) && ! V_11 -> V_42 . V_162 ) {
F_37 ( L_42 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_170 == - 1 ) {
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
V_129 -> V_43 = V_199 ;
}
} else if ( V_11 -> V_42 . V_162 ) {
V_129 -> V_43 = ( F_41 ( V_31 ) ?
V_44 : V_199 ) ;
} else {
V_129 -> V_43 = V_44 ;
}
if ( V_129 -> V_43 != V_199 )
V_129 -> V_118 = V_118 ;
F_3 ( L_44 ,
V_129 -> V_43 == V_199 ? L_45 :
( V_129 -> V_43 == V_44 ? L_46 : L_47 ) ) ;
F_44 ( V_129 ) ;
if ( F_53 ( V_11 -> V_42 . V_1 ) && V_11 -> V_42 . V_200 [ 0 ] ) {
if ( strcmp ( V_11 -> V_42 . V_200 , V_129 -> V_15 -> V_16 ) == 0 ) {
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
F_143 ( V_129 ) . V_201 = 1 ;
F_144 ( V_11 , 1000 / V_202 ) ;
} else {
F_143 ( V_129 ) . V_201 =
F_143 ( V_129 -> V_27 ) . V_201 + 1 ;
}
F_145 ( V_129 ) ;
break;
case V_8 :
case V_9 :
F_146 ( V_129 ) ;
F_88 ( V_129 ) ;
F_91 ( V_11 ) ;
break;
default:
F_3 ( L_48 ) ;
F_146 ( V_129 ) ;
if ( ! V_11 -> V_77 )
V_11 -> V_77 = V_129 ;
break;
}
F_8 ( & V_11 -> V_123 ) ;
F_39 ( V_11 ) ;
#ifdef F_147
V_31 -> V_137 = F_105 ( V_11 ) ;
if ( V_31 -> V_137 ) {
if ( F_94 ( V_129 ) ) {
F_70 ( & V_11 -> V_20 ) ;
F_84 ( L_49
L_50 ,
V_34 -> V_16 ) ;
V_21 = - V_172 ;
goto V_203;
}
}
#endif
F_70 ( & V_11 -> V_20 ) ;
V_21 = F_148 ( V_34 , V_31 ) ;
if ( V_21 )
goto V_203;
V_21 = F_149 ( V_31 , F_114 ,
V_129 ) ;
if ( V_21 ) {
F_3 ( L_51 , V_21 ) ;
goto V_204;
}
F_84 ( L_52 ,
V_34 -> V_16 , V_31 -> V_16 ,
F_150 ( V_129 ) ? L_53 : L_54 ,
V_129 -> V_43 != V_199 ? L_55 : L_56 ) ;
return 0 ;
V_204:
F_151 ( V_34 , V_31 ) ;
V_203:
F_6 ( & V_11 -> V_20 ) ;
F_93 ( V_11 , V_129 ) ;
F_8 ( & V_11 -> V_20 ) ;
V_196:
F_152 ( V_31 ) ;
V_194:
F_137 ( V_31 , NULL ) ;
V_193:
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_190 , V_129 -> V_189 , V_96 ) ;
V_78 . V_191 = V_31 -> type ;
F_136 ( V_31 , & V_78 ) ;
}
V_192:
F_135 ( V_31 , V_129 -> V_186 ) ;
V_188:
F_15 ( V_129 ) ;
V_175:
F_109 ( V_11 ) ;
return V_21 ;
}
int F_153 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_205 ;
struct V_169 V_78 ;
T_4 V_206 = V_34 -> V_140 ;
if ( ! ( V_31 -> V_100 & V_171 ) ||
( V_31 -> V_83 != V_34 ) ) {
F_32 ( L_57 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
return - V_180 ;
}
F_10 () ;
F_90 ( V_34 , V_207 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_36 = F_26 ( V_11 , V_31 ) ;
if ( ! V_36 ) {
F_84 ( L_58 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_180 ;
}
F_154 ( V_31 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_155 () ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
if ( F_156 ( V_34 -> V_139 , V_36 -> V_189 ) &&
V_11 -> V_40 > 1 )
F_37 ( L_59 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_36 -> V_189 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_157 ( V_36 ) ;
}
F_84 ( L_60 ,
V_34 -> V_16 ,
F_150 ( V_36 ) ? L_61 : L_62 ,
V_31 -> V_16 ) ;
V_205 = V_11 -> V_77 ;
V_11 -> V_208 = NULL ;
F_93 ( V_11 , V_36 ) ;
if ( V_11 -> V_104 == V_36 )
V_11 -> V_104 = NULL ;
if ( V_205 == V_36 )
F_83 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_158 ( V_11 , V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_205 == V_36 ) {
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
memset ( V_34 -> V_139 , 0 , V_34 -> V_138 ) ;
if ( F_128 ( V_11 ) ) {
F_37 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_37 ( L_64 ,
V_34 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
if ( V_11 -> V_40 == 0 )
F_133 ( V_209 , V_11 -> V_15 ) ;
F_109 ( V_11 ) ;
if ( ! ( V_34 -> V_140 & V_142 ) &&
( V_206 & V_142 ) )
F_84 ( L_65 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
F_151 ( V_34 , V_31 ) ;
F_38 ( V_11 , V_31 ) ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 )
F_54 ( V_31 , - 1 ) ;
if ( V_34 -> V_100 & V_102 )
F_56 ( V_31 , - 1 ) ;
F_140 ( V_34 ) ;
F_73 ( V_34 , V_31 ) ;
F_141 ( V_34 ) ;
}
F_137 ( V_31 , NULL ) ;
F_97 ( V_36 ) ;
F_152 ( V_31 ) ;
if ( V_11 -> V_42 . V_121 != V_182 ) {
memcpy ( V_78 . V_190 , V_36 -> V_189 , V_96 ) ;
V_78 . V_191 = V_31 -> type ;
F_136 ( V_31 , & V_78 ) ;
}
F_135 ( V_31 , V_36 -> V_186 ) ;
V_31 -> V_84 &= ~ V_195 ;
F_15 ( V_36 ) ;
return 0 ;
}
static int F_159 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_158 ;
V_158 = F_153 ( V_34 , V_31 ) ;
if ( ( V_158 == 0 ) && ( V_11 -> V_40 == 0 ) ) {
V_34 -> V_84 |= V_133 ;
F_84 ( L_66 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_160 ( V_34 ) ;
}
return V_158 ;
}
static int F_161 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
struct V_30 * V_31 ;
struct V_169 V_78 ;
F_6 ( & V_11 -> V_20 ) ;
F_43 ( V_34 ) ;
if ( V_11 -> V_40 == 0 )
goto V_23;
V_11 -> V_208 = NULL ;
V_11 -> V_104 = NULL ;
F_83 ( V_11 , NULL ) ;
while ( ( V_36 = V_11 -> V_112 ) != NULL ) {
if ( V_11 -> V_42 . V_1 == V_7 )
F_157 ( V_36 ) ;
V_31 = V_36 -> V_15 ;
F_93 ( V_11 , V_36 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_154 ( V_31 ) ;
F_155 () ;
if ( F_13 ( V_11 ) ) {
F_158 ( V_11 , V_36 ) ;
}
F_151 ( V_34 , V_31 ) ;
F_38 ( V_11 , V_31 ) ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 )
F_54 ( V_31 , - 1 ) ;
if ( V_34 -> V_100 & V_102 )
F_56 ( V_31 , - 1 ) ;
F_140 ( V_34 ) ;
F_73 ( V_34 , V_31 ) ;
F_141 ( V_34 ) ;
}
F_137 ( V_31 , NULL ) ;
F_97 ( V_36 ) ;
F_152 ( V_31 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_190 , V_36 -> V_189 , V_96 ) ;
V_78 . V_191 = V_31 -> type ;
F_136 ( V_31 , & V_78 ) ;
}
F_15 ( V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
memset ( V_34 -> V_139 , 0 , V_34 -> V_138 ) ;
if ( F_128 ( V_11 ) ) {
F_37 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_37 ( L_64 ,
V_34 -> V_16 ) ;
}
F_84 ( L_67 , V_34 -> V_16 ) ;
V_23:
F_8 ( & V_11 -> V_20 ) ;
F_109 ( V_11 ) ;
return 0 ;
}
static int F_162 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_99 = NULL ;
struct V_36 * V_98 = NULL ;
int V_21 = 0 ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) )
return - V_180 ;
if ( ! ( V_31 -> V_100 & V_171 ) || ( V_31 -> V_83 != V_34 ) )
return - V_180 ;
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
V_21 = - V_180 ;
F_70 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_163 ( struct V_30 * V_34 , struct V_210 * V_211 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_211 -> V_212 = V_11 -> V_42 . V_1 ;
V_211 -> V_119 = V_11 -> V_42 . V_119 ;
F_67 ( & V_11 -> V_20 ) ;
V_211 -> V_213 = V_11 -> V_40 ;
F_70 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_164 ( struct V_30 * V_34 , struct V_214 * V_211 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
int V_38 , V_21 = - V_22 ;
F_67 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
if ( V_38 == ( int ) V_211 -> V_215 ) {
V_21 = 0 ;
strcpy ( V_211 -> V_216 , V_36 -> V_15 -> V_16 ) ;
V_211 -> V_43 = V_36 -> V_43 ;
V_211 -> V_117 = F_165 ( V_36 ) ;
V_211 -> V_197 = V_36 -> V_197 ;
break;
}
}
F_70 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_166 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 , V_217 , V_218 = 0 ;
bool V_219 ;
V_219 = ! V_11 -> V_77 ? true : false ;
F_30 (bond, slave, i) {
V_36 -> V_220 = V_221 ;
V_217 = F_47 ( V_11 , V_36 -> V_15 , 0 ) ;
switch ( V_36 -> V_43 ) {
case V_44 :
if ( V_217 )
continue;
V_36 -> V_43 = V_222 ;
V_36 -> V_114 = V_11 -> V_42 . V_223 ;
if ( V_36 -> V_114 ) {
F_84 ( L_68 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_1 ==
V_4 ) ?
( F_150 ( V_36 ) ?
L_69 : L_70 ) : L_71 ,
V_36 -> V_15 -> V_16 ,
V_11 -> V_42 . V_223 * V_11 -> V_42 . V_119 ) ;
}
case V_222 :
if ( V_217 ) {
V_36 -> V_43 = V_44 ;
V_36 -> V_118 = V_118 ;
F_84 ( L_72 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_223 - V_36 -> V_114 ) *
V_11 -> V_42 . V_119 ,
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
V_36 -> V_43 = V_113 ;
V_36 -> V_114 = V_11 -> V_42 . V_111 ;
if ( V_36 -> V_114 ) {
F_84 ( L_73 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ,
V_219 ? 0 :
V_11 -> V_42 . V_111 *
V_11 -> V_42 . V_119 ) ;
}
case V_113 :
if ( ! V_217 ) {
V_36 -> V_43 = V_199 ;
F_84 ( L_74 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_111 - V_36 -> V_114 ) *
V_11 -> V_42 . V_119 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_219 )
V_36 -> V_114 = 0 ;
if ( V_36 -> V_114 <= 0 ) {
V_36 -> V_220 = V_44 ;
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
static void F_167 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i) {
switch ( V_36 -> V_220 ) {
case V_221 :
continue;
case V_44 :
V_36 -> V_43 = V_44 ;
V_36 -> V_118 = V_118 ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_168 ( V_36 ) ;
} else if ( V_11 -> V_42 . V_1 != V_4 ) {
F_146 ( V_36 ) ;
} else if ( V_36 != V_11 -> V_104 ) {
F_168 ( V_36 ) ;
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
goto V_224;
continue;
case V_199 :
if ( V_36 -> V_197 < V_225 )
V_36 -> V_197 ++ ;
V_36 -> V_43 = V_199 ;
if ( V_11 -> V_42 . V_1 == V_4 ||
V_11 -> V_42 . V_1 == V_7 )
F_88 ( V_36 ) ;
F_84 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_11 -> V_42 . V_1 == V_7 )
F_85 ( V_36 ,
V_199 ) ;
if ( F_13 ( V_11 ) )
F_86 ( V_11 , V_36 ,
V_199 ) ;
if ( V_36 == V_11 -> V_77 )
goto V_224;
continue;
default:
F_32 ( L_79 ,
V_11 -> V_15 -> V_16 , V_36 -> V_220 ,
V_36 -> V_15 -> V_16 ) ;
V_36 -> V_220 = V_221 ;
continue;
}
V_224:
F_169 () ;
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
F_39 ( V_11 ) ;
}
void F_170 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_226 . V_92 ) ;
bool V_120 = false ;
unsigned long V_114 ;
F_67 ( & V_11 -> V_20 ) ;
V_114 = F_142 ( V_11 -> V_42 . V_119 ) ;
if ( V_11 -> V_40 == 0 )
goto V_227;
V_120 = F_81 ( V_11 ) ;
if ( F_166 ( V_11 ) ) {
F_70 ( & V_11 -> V_20 ) ;
if ( ! F_171 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_114 = 1 ;
V_120 = false ;
goto V_227;
}
F_67 ( & V_11 -> V_20 ) ;
F_167 ( V_11 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_172 () ;
F_67 ( & V_11 -> V_20 ) ;
}
V_227:
if ( V_11 -> V_42 . V_119 )
F_69 ( V_11 -> V_88 , & V_11 -> V_226 , V_114 ) ;
F_70 ( & V_11 -> V_20 ) ;
if ( V_120 ) {
if ( ! F_171 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_11 -> V_115 ++ ;
F_70 ( & V_11 -> V_20 ) ;
return;
}
F_90 ( V_11 -> V_15 , V_125 ) ;
F_172 () ;
}
}
static int F_173 ( struct V_10 * V_11 , T_6 V_228 )
{
struct V_13 * V_14 ;
struct V_30 * V_81 ;
if ( V_228 == F_174 ( V_11 -> V_15 , 0 , V_228 ) )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_62 () ;
V_81 = F_68 ( V_11 -> V_15 , V_14 -> V_12 ) ;
F_65 () ;
if ( V_81 && V_228 == F_174 ( V_81 , 0 , V_228 ) )
return 1 ;
}
return 0 ;
}
static void F_175 ( struct V_30 * V_31 , int V_229 , T_6 V_230 , T_6 V_231 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_80 , V_229 ,
V_31 -> V_16 , V_230 , V_231 , V_12 ) ;
V_29 = F_176 ( V_229 , V_232 , V_230 , V_31 , V_231 ,
NULL , V_31 -> V_139 , NULL ) ;
if ( ! V_29 ) {
F_32 ( L_81 ) ;
return;
}
if ( V_12 ) {
V_29 = F_177 ( V_29 , V_12 ) ;
if ( ! V_29 ) {
F_32 ( L_82 ) ;
return;
}
}
F_178 ( V_29 ) ;
}
static void F_179 ( struct V_10 * V_11 , struct V_36 * V_36 )
{
int V_38 , V_12 ;
T_6 * V_233 = V_11 -> V_42 . V_234 ;
struct V_13 * V_14 ;
struct V_30 * V_81 = NULL ;
struct V_235 * V_236 ;
for ( V_38 = 0 ; ( V_38 < V_237 ) ; V_38 ++ ) {
T_6 V_78 ;
if ( ! V_233 [ V_38 ] )
break;
F_3 ( L_83 , V_233 [ V_38 ] ) ;
if ( ! F_128 ( V_11 ) ) {
F_3 ( L_84 ) ;
V_78 = F_174 ( V_11 -> V_15 , V_233 [ V_38 ] , 0 ) ;
F_175 ( V_36 -> V_15 , V_238 , V_233 [ V_38 ] ,
V_78 , 0 ) ;
continue;
}
V_236 = F_180 ( F_181 ( V_11 -> V_15 ) , V_233 [ V_38 ] , 0 ,
V_239 , 0 ) ;
if ( F_182 ( V_236 ) ) {
if ( F_183 () ) {
F_37 ( L_85 ,
V_11 -> V_15 -> V_16 , & V_233 [ V_38 ] ) ;
}
continue;
}
if ( V_236 -> V_240 . V_15 == V_11 -> V_15 ) {
F_184 ( V_236 ) ;
F_3 ( L_86 ) ;
V_78 = F_174 ( V_11 -> V_15 , V_233 [ V_38 ] , 0 ) ;
F_175 ( V_36 -> V_15 , V_238 , V_233 [ V_38 ] ,
V_78 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_62 () ;
V_81 = F_68 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_65 () ;
if ( V_81 == V_236 -> V_240 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_87 ,
V_81 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 && V_81 ) {
F_184 ( V_236 ) ;
V_78 = F_174 ( V_81 , V_233 [ V_38 ] , 0 ) ;
F_175 ( V_36 -> V_15 , V_238 , V_233 [ V_38 ] ,
V_78 , V_12 ) ;
continue;
}
if ( F_183 () ) {
F_37 ( L_88 ,
V_11 -> V_15 -> V_16 , & V_233 [ V_38 ] ,
V_236 -> V_240 . V_15 ? V_236 -> V_240 . V_15 -> V_16 : L_18 ) ;
}
F_184 ( V_236 ) ;
}
}
static void F_185 ( struct V_10 * V_11 , struct V_36 * V_36 , T_6 V_241 , T_6 V_242 )
{
int V_38 ;
T_6 * V_233 = V_11 -> V_42 . V_234 ;
for ( V_38 = 0 ; ( V_38 < V_237 ) && V_233 [ V_38 ] ; V_38 ++ ) {
F_3 ( L_89 ,
& V_241 , & V_242 , V_38 , & V_233 [ V_38 ] ,
F_173 ( V_11 , V_242 ) ) ;
if ( V_241 == V_233 [ V_38 ] ) {
if ( F_173 ( V_11 , V_242 ) )
V_36 -> V_198 = V_118 ;
return;
}
}
}
static int F_186 ( struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_36 * V_36 )
{
struct V_243 * V_244 ;
unsigned char * V_245 ;
T_6 V_241 , V_242 ;
if ( V_29 -> V_246 != F_187 ( V_232 ) )
return V_159 ;
F_67 ( & V_11 -> V_20 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( ! F_188 ( V_29 , F_189 ( V_11 -> V_15 ) ) )
goto V_247;
V_244 = F_190 ( V_29 ) ;
if ( V_244 -> V_248 != V_11 -> V_15 -> V_138 ||
V_29 -> V_154 == V_249 ||
V_29 -> V_154 == V_250 ||
V_244 -> V_251 != F_191 ( V_177 ) ||
V_244 -> V_252 != F_191 ( V_253 ) ||
V_244 -> V_254 != 4 )
goto V_247;
V_245 = ( unsigned char * ) ( V_244 + 1 ) ;
V_245 += V_11 -> V_15 -> V_138 ;
memcpy ( & V_241 , V_245 , 4 ) ;
V_245 += 4 + V_11 -> V_15 -> V_138 ;
memcpy ( & V_242 , V_245 , 4 ) ;
F_3 ( L_91 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 , F_165 ( V_36 ) ,
V_11 -> V_42 . V_255 , F_192 ( V_11 , V_36 ) ,
& V_241 , & V_242 ) ;
if ( F_150 ( V_36 ) )
F_185 ( V_11 , V_36 , V_241 , V_242 ) ;
else
F_185 ( V_11 , V_36 , V_242 , V_241 ) ;
V_247:
F_70 ( & V_11 -> V_20 ) ;
return V_159 ;
}
void F_193 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_256 . V_92 ) ;
struct V_36 * V_36 , * V_205 ;
int V_224 = 0 ;
int V_257 ;
int V_38 ;
F_67 ( & V_11 -> V_20 ) ;
V_257 = F_142 ( V_11 -> V_42 . V_162 ) ;
if ( V_11 -> V_40 == 0 )
goto V_227;
F_67 ( & V_11 -> V_123 ) ;
V_205 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
F_30 (bond, slave, i) {
unsigned long V_258 = F_194 ( V_36 -> V_15 ) ;
if ( V_36 -> V_43 != V_44 ) {
if ( F_195 ( V_118 ,
V_258 - V_257 ,
V_258 + V_257 ) &&
F_195 ( V_118 ,
V_36 -> V_15 -> V_163 - V_257 ,
V_36 -> V_15 -> V_163 + V_257 ) ) {
V_36 -> V_43 = V_44 ;
F_146 ( V_36 ) ;
if ( ! V_205 ) {
F_84 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
V_224 = 1 ;
} else {
F_84 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_195 ( V_118 ,
V_258 - V_257 ,
V_258 + 2 * V_257 ) ||
! F_195 ( V_118 ,
V_36 -> V_15 -> V_163 - V_257 ,
V_36 -> V_15 -> V_163 + 2 * V_257 ) ) {
V_36 -> V_43 = V_199 ;
F_168 ( V_36 ) ;
if ( V_36 -> V_197 < V_225 )
V_36 -> V_197 ++ ;
F_84 ( L_94 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_205 )
V_224 = 1 ;
}
}
if ( F_80 ( V_36 -> V_15 ) )
F_179 ( V_11 , V_36 ) ;
}
if ( V_224 ) {
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
V_227:
if ( V_11 -> V_42 . V_162 )
F_69 ( V_11 -> V_88 , & V_11 -> V_256 , V_257 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_196 ( struct V_10 * V_11 , int V_257 )
{
struct V_36 * V_36 ;
int V_38 , V_218 = 0 ;
unsigned long V_258 ;
F_30 (bond, slave, i) {
V_36 -> V_220 = V_221 ;
if ( V_36 -> V_43 != V_44 ) {
if ( F_195 ( V_118 ,
F_197 ( V_11 , V_36 ) - V_257 ,
F_197 ( V_11 , V_36 ) + V_257 ) ) {
V_36 -> V_220 = V_44 ;
V_218 ++ ;
}
continue;
}
if ( F_195 ( V_118 ,
V_36 -> V_118 - V_257 ,
V_36 -> V_118 + 2 * V_257 ) )
continue;
if ( ! F_150 ( V_36 ) &&
! V_11 -> V_208 &&
! F_195 ( V_118 ,
F_197 ( V_11 , V_36 ) - V_257 ,
F_197 ( V_11 , V_36 ) + 3 * V_257 ) ) {
V_36 -> V_220 = V_199 ;
V_218 ++ ;
}
V_258 = F_194 ( V_36 -> V_15 ) ;
if ( F_150 ( V_36 ) &&
( ! F_195 ( V_118 ,
V_258 - V_257 ,
V_258 + 2 * V_257 ) ||
! F_195 ( V_118 ,
F_197 ( V_11 , V_36 ) - V_257 ,
F_197 ( V_11 , V_36 ) + 2 * V_257 ) ) ) {
V_36 -> V_220 = V_199 ;
V_218 ++ ;
}
}
return V_218 ;
}
static void F_198 ( struct V_10 * V_11 , int V_257 )
{
struct V_36 * V_36 ;
int V_38 ;
unsigned long V_258 ;
F_30 (bond, slave, i) {
switch ( V_36 -> V_220 ) {
case V_221 :
continue;
case V_44 :
V_258 = F_194 ( V_36 -> V_15 ) ;
if ( ( ! V_11 -> V_77 &&
F_195 ( V_118 ,
V_258 - V_257 ,
V_258 + V_257 ) ) ||
V_11 -> V_77 != V_36 ) {
V_36 -> V_43 = V_44 ;
if ( V_11 -> V_208 ) {
F_88 (
V_11 -> V_208 ) ;
V_11 -> V_208 = NULL ;
}
F_84 ( L_95 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_77 ||
( V_36 == V_11 -> V_104 ) )
goto V_224;
}
continue;
case V_199 :
if ( V_36 -> V_197 < V_225 )
V_36 -> V_197 ++ ;
V_36 -> V_43 = V_199 ;
F_88 ( V_36 ) ;
F_84 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_11 -> V_77 ) {
V_11 -> V_208 = NULL ;
goto V_224;
}
continue;
default:
F_32 ( L_96 ,
V_11 -> V_15 -> V_16 , V_36 -> V_220 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
V_224:
F_169 () ;
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
F_39 ( V_11 ) ;
}
static void F_199 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_67 ( & V_11 -> V_123 ) ;
if ( V_11 -> V_208 && V_11 -> V_77 )
F_84 ( L_97 ,
V_11 -> V_208 -> V_15 -> V_16 ,
V_11 -> V_77 -> V_15 -> V_16 ) ;
if ( V_11 -> V_77 ) {
F_179 ( V_11 , V_11 -> V_77 ) ;
F_70 ( & V_11 -> V_123 ) ;
return;
}
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_11 -> V_208 ) {
V_11 -> V_208 = V_11 -> V_112 ;
if ( ! V_11 -> V_208 )
return;
}
F_88 ( V_11 -> V_208 ) ;
F_79 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_80 ( V_36 -> V_15 ) ) {
V_36 -> V_43 = V_113 ;
F_89 ( V_36 ) ;
F_179 ( V_11 , V_36 ) ;
V_36 -> V_118 = V_118 ;
V_11 -> V_208 = V_36 ;
break;
}
if ( V_36 -> V_43 == V_44 ) {
V_36 -> V_43 = V_199 ;
if ( V_36 -> V_197 < V_225 )
V_36 -> V_197 ++ ;
F_88 ( V_36 ) ;
F_84 ( L_98 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
}
}
}
void F_200 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_256 . V_92 ) ;
bool V_120 = false ;
int V_257 ;
F_67 ( & V_11 -> V_20 ) ;
V_257 = F_142 ( V_11 -> V_42 . V_162 ) ;
if ( V_11 -> V_40 == 0 )
goto V_227;
V_120 = F_81 ( V_11 ) ;
if ( F_196 ( V_11 , V_257 ) ) {
F_70 ( & V_11 -> V_20 ) ;
if ( ! F_171 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_257 = 1 ;
V_120 = false ;
goto V_227;
}
F_67 ( & V_11 -> V_20 ) ;
F_198 ( V_11 , V_257 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_172 () ;
F_67 ( & V_11 -> V_20 ) ;
}
F_199 ( V_11 ) ;
V_227:
if ( V_11 -> V_42 . V_162 )
F_69 ( V_11 -> V_88 , & V_11 -> V_256 , V_257 ) ;
F_70 ( & V_11 -> V_20 ) ;
if ( V_120 ) {
if ( ! F_171 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_11 -> V_115 ++ ;
F_70 ( & V_11 -> V_20 ) ;
return;
}
F_90 ( V_11 -> V_15 , V_125 ) ;
F_172 () ;
}
}
static int F_201 ( struct V_10 * V_11 )
{
F_202 ( V_11 ) ;
F_203 ( V_11 ) ;
F_204 ( V_11 ) ;
return V_259 ;
}
static int F_205 ( unsigned long V_260 ,
struct V_30 * V_34 )
{
struct V_10 * V_261 = F_29 ( V_34 ) ;
switch ( V_260 ) {
case V_262 :
return F_201 ( V_261 ) ;
case V_263 :
F_202 ( V_261 ) ;
break;
case V_264 :
F_203 ( V_261 ) ;
break;
default:
break;
}
return V_259 ;
}
static int F_206 ( unsigned long V_260 ,
struct V_30 * V_31 )
{
struct V_30 * V_34 = V_31 -> V_83 ;
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 = NULL ;
switch ( V_260 ) {
case V_263 :
if ( V_34 ) {
if ( V_11 -> V_153 )
F_159 ( V_34 , V_31 ) ;
else
F_153 ( V_34 , V_31 ) ;
}
break;
case V_265 :
case V_266 :
V_36 = F_26 ( V_11 , V_31 ) ;
if ( V_36 ) {
T_2 V_267 = V_36 -> V_48 ;
T_3 V_268 = V_36 -> V_50 ;
F_44 ( V_36 ) ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
if ( V_267 != V_36 -> V_48 )
F_207 ( V_36 ) ;
if ( V_268 != V_36 -> V_50 )
F_208 ( V_36 ) ;
}
}
break;
case V_269 :
break;
case V_270 :
break;
case V_262 :
break;
case V_271 :
F_109 ( V_11 ) ;
break;
default:
break;
}
return V_259 ;
}
static int F_209 ( struct V_272 * V_273 ,
unsigned long V_260 , void * V_274 )
{
struct V_30 * V_275 = (struct V_30 * ) V_274 ;
F_3 ( L_99 ,
V_275 ? V_275 -> V_16 : L_10 ,
V_260 ) ;
if ( ! ( V_275 -> V_84 & V_195 ) )
return V_259 ;
if ( V_275 -> V_100 & V_276 ) {
F_3 ( L_100 ) ;
return F_205 ( V_260 , V_275 ) ;
}
if ( V_275 -> V_100 & V_171 ) {
F_3 ( L_101 ) ;
return F_206 ( V_260 , V_275 ) ;
}
return V_259 ;
}
static int F_210 ( struct V_28 * V_29 , int V_277 )
{
struct V_278 * V_167 = (struct V_278 * ) V_29 -> V_167 ;
struct V_279 * V_280 = F_211 ( V_29 ) ;
if ( V_29 -> V_246 == F_191 ( V_253 ) ) {
return ( ( F_212 ( V_280 -> V_281 ^ V_280 -> V_282 ) & 0xffff ) ^
( V_167 -> V_168 [ 5 ] ^ V_167 -> V_283 [ 5 ] ) ) % V_277 ;
}
return ( V_167 -> V_168 [ 5 ] ^ V_167 -> V_283 [ 5 ] ) % V_277 ;
}
static int F_213 ( struct V_28 * V_29 , int V_277 )
{
struct V_278 * V_167 = (struct V_278 * ) V_29 -> V_167 ;
struct V_279 * V_280 = F_211 ( V_29 ) ;
T_7 * V_284 = ( T_7 * ) ( ( T_2 * ) V_280 + V_280 -> V_285 ) ;
int V_286 = 0 ;
if ( V_29 -> V_246 == F_191 ( V_253 ) ) {
if ( ! F_214 ( V_280 ) &&
( V_280 -> V_246 == V_287 ||
V_280 -> V_246 == V_288 ) ) {
V_286 = F_215 ( ( * V_284 ^ * ( V_284 + 1 ) ) ) ;
}
return ( V_286 ^
( ( F_212 ( V_280 -> V_281 ^ V_280 -> V_282 ) ) & 0xffff ) ) % V_277 ;
}
return ( V_167 -> V_168 [ 5 ] ^ V_167 -> V_283 [ 5 ] ) % V_277 ;
}
static int F_216 ( struct V_28 * V_29 , int V_277 )
{
struct V_278 * V_167 = (struct V_278 * ) V_29 -> V_167 ;
return ( V_167 -> V_168 [ 5 ] ^ V_167 -> V_283 [ 5 ] ) % V_277 ;
}
static int F_217 ( struct V_30 * V_34 )
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
F_218 ( & V_11 -> V_89 , F_71 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_219 ( V_11 , ( V_11 -> V_42 . V_1 == V_9 ) ) ) {
return - V_18 ;
}
F_218 ( & V_11 -> V_289 , V_290 ) ;
F_69 ( V_11 -> V_88 , & V_11 -> V_289 , 0 ) ;
}
if ( V_11 -> V_42 . V_119 ) {
F_218 ( & V_11 -> V_226 , F_170 ) ;
F_69 ( V_11 -> V_88 , & V_11 -> V_226 , 0 ) ;
}
if ( V_11 -> V_42 . V_162 ) {
if ( V_11 -> V_42 . V_1 == V_4 )
F_218 ( & V_11 -> V_256 ,
F_200 ) ;
else
F_218 ( & V_11 -> V_256 ,
F_193 ) ;
F_69 ( V_11 -> V_88 , & V_11 -> V_256 , 0 ) ;
if ( V_11 -> V_42 . V_255 )
V_11 -> F_115 = F_186 ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_218 ( & V_11 -> V_291 , V_292 ) ;
F_69 ( V_11 -> V_88 , & V_11 -> V_291 , 0 ) ;
V_11 -> F_115 = V_293 ;
F_220 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_221 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_115 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_42 . V_119 ) {
F_222 ( & V_11 -> V_226 ) ;
}
if ( V_11 -> V_42 . V_162 ) {
F_222 ( & V_11 -> V_256 ) ;
}
switch ( V_11 -> V_42 . V_1 ) {
case V_7 :
F_222 ( & V_11 -> V_291 ) ;
break;
case V_8 :
case V_9 :
F_222 ( & V_11 -> V_289 ) ;
break;
default:
break;
}
if ( F_223 ( & V_11 -> V_89 ) )
F_222 ( & V_11 -> V_89 ) ;
if ( F_13 ( V_11 ) ) {
F_224 ( V_11 ) ;
}
V_11 -> F_115 = NULL ;
return 0 ;
}
static struct V_294 * F_225 ( struct V_30 * V_34 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_294 V_296 ;
struct V_36 * V_36 ;
int V_38 ;
memset ( V_295 , 0 , sizeof( * V_295 ) ) ;
F_226 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
const struct V_294 * V_297 =
F_227 ( V_36 -> V_15 , & V_296 ) ;
V_295 -> V_298 += V_297 -> V_298 ;
V_295 -> V_299 += V_297 -> V_299 ;
V_295 -> V_300 += V_297 -> V_300 ;
V_295 -> V_301 += V_297 -> V_301 ;
V_295 -> V_302 += V_297 -> V_302 ;
V_295 -> V_303 += V_297 -> V_303 ;
V_295 -> V_304 += V_297 -> V_304 ;
V_295 -> V_305 += V_297 -> V_305 ;
V_295 -> V_306 += V_297 -> V_306 ;
V_295 -> V_307 += V_297 -> V_307 ;
V_295 -> V_308 += V_297 -> V_308 ;
V_295 -> V_309 += V_297 -> V_309 ;
V_295 -> V_310 += V_297 -> V_310 ;
V_295 -> V_311 += V_297 -> V_311 ;
V_295 -> V_312 += V_297 -> V_312 ;
V_295 -> V_313 += V_297 -> V_313 ;
V_295 -> V_314 += V_297 -> V_314 ;
V_295 -> V_315 += V_297 -> V_315 ;
V_295 -> V_316 += V_297 -> V_316 ;
V_295 -> V_317 += V_297 -> V_317 ;
V_295 -> V_318 += V_297 -> V_318 ;
}
F_228 ( & V_11 -> V_20 ) ;
return V_295 ;
}
static int F_229 ( struct V_30 * V_34 , struct V_59 * V_60 , int V_319 )
{
struct V_30 * V_31 = NULL ;
struct V_210 V_320 ;
struct V_210 T_8 * V_321 = NULL ;
struct V_214 V_322 ;
struct V_214 T_8 * V_323 = NULL ;
struct V_61 * V_62 = NULL ;
int V_21 = 0 ;
F_3 ( L_102 , V_34 -> V_16 , V_319 ) ;
switch ( V_319 ) {
case V_70 :
V_62 = F_50 ( V_60 ) ;
if ( ! V_62 )
return - V_180 ;
V_62 -> V_324 = 0 ;
case V_73 :
V_62 = F_50 ( V_60 ) ;
if ( ! V_62 )
return - V_180 ;
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
case V_325 :
case V_326 :
V_321 = (struct V_210 T_8 * ) V_60 -> V_327 ;
if ( F_230 ( & V_320 , V_321 , sizeof( V_210 ) ) )
return - V_328 ;
V_21 = F_163 ( V_34 , & V_320 ) ;
if ( V_21 == 0 &&
F_231 ( V_321 , & V_320 , sizeof( V_210 ) ) )
return - V_328 ;
return V_21 ;
case V_329 :
case V_330 :
V_323 = (struct V_214 T_8 * ) V_60 -> V_327 ;
if ( F_230 ( & V_322 , V_323 , sizeof( V_214 ) ) )
return - V_328 ;
V_21 = F_164 ( V_34 , & V_322 ) ;
if ( V_21 == 0 &&
F_231 ( V_323 , & V_322 , sizeof( V_214 ) ) )
return - V_328 ;
return V_21 ;
default:
break;
}
if ( ! F_232 ( V_331 ) )
return - V_173 ;
V_31 = F_233 ( F_181 ( V_34 ) , V_60 -> V_332 ) ;
F_3 ( L_103 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_104 , V_31 -> V_16 ) ;
switch ( V_319 ) {
case V_333 :
case V_334 :
V_21 = F_127 ( V_34 , V_31 ) ;
break;
case V_335 :
case V_336 :
V_21 = F_153 ( V_34 , V_31 ) ;
break;
case V_337 :
case V_338 :
V_21 = F_106 ( V_34 , V_31 ) ;
break;
case V_339 :
case V_340 :
V_21 = F_162 ( V_34 , V_31 ) ;
break;
default:
V_21 = - V_183 ;
}
F_234 ( V_31 ) ;
}
return V_21 ;
}
static bool F_235 ( unsigned char * V_78 ,
struct V_341 * V_342 ,
int V_343 )
{
struct V_93 * V_94 ;
F_236 (ha, list)
if ( ! memcmp ( V_94 -> V_78 , V_78 , V_343 ) )
return true ;
return false ;
}
static void F_237 ( struct V_30 * V_34 , int V_344 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_344 & V_101 )
F_52 ( V_11 ,
V_34 -> V_100 & V_101 ? 1 : - 1 ) ;
if ( V_344 & V_102 )
F_55 ( V_11 ,
V_34 -> V_100 & V_102 ? 1 : - 1 ) ;
}
static void F_238 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_93 * V_94 ;
bool V_345 ;
F_67 ( & V_11 -> V_20 ) ;
F_74 (ha, bond_dev) {
V_345 = F_235 ( V_94 -> V_78 , & V_11 -> V_346 ,
V_34 -> V_138 ) ;
if ( ! V_345 )
F_57 ( V_11 , V_94 -> V_78 ) ;
}
F_236 (ha, &bond->mc_list) {
V_345 = F_235 ( V_94 -> V_78 , & V_34 -> V_347 ,
V_34 -> V_138 ) ;
if ( ! V_345 )
F_59 ( V_11 , V_94 -> V_78 ) ;
}
F_239 ( & V_11 -> V_346 ) ;
F_240 ( & V_11 -> V_346 , & V_34 -> V_347 ,
V_34 -> V_138 , V_348 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_241 ( struct V_349 * V_350 )
{
struct V_10 * V_11 = F_29 ( V_350 -> V_15 ) ;
struct V_36 * V_36 = V_11 -> V_112 ;
const struct V_56 * V_57 ;
struct V_351 V_352 ;
int V_158 ;
if ( ! V_36 )
return 0 ;
V_57 = V_36 -> V_15 -> V_58 ;
if ( ! V_57 -> V_353 )
return 0 ;
V_352 . V_354 = NULL ;
V_352 . V_355 = NULL ;
V_158 = V_57 -> V_353 ( V_36 -> V_15 , & V_352 ) ;
if ( V_158 )
return V_158 ;
V_350 -> V_352 -> V_355 = V_352 . V_355 ;
if ( ! V_352 . V_354 )
return 0 ;
return V_352 . V_354 ( V_350 ) ;
}
static int F_242 ( struct V_30 * V_15 ,
struct V_351 * V_352 )
{
V_352 -> V_354 = F_241 ;
return 0 ;
}
static int F_243 ( struct V_30 * V_34 , int V_356 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_37 ;
int V_21 = 0 ;
int V_38 ;
F_3 ( L_105 , V_11 ,
( V_34 ? V_34 -> V_16 : L_10 ) , V_356 ) ;
F_30 (bond, slave, i) {
F_3 ( L_106 ,
V_36 ,
V_36 -> V_27 ,
V_36 -> V_15 -> V_58 -> V_357 ) ;
V_21 = F_135 ( V_36 -> V_15 , V_356 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
}
V_34 -> V_187 = V_356 ;
return 0 ;
V_39:
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_358 ;
V_358 = F_135 ( V_36 -> V_15 , V_34 -> V_187 ) ;
if ( V_358 ) {
F_3 ( L_108 ,
V_358 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_244 ( struct V_30 * V_34 , void * V_78 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_169 * V_359 = V_78 , V_360 ;
struct V_36 * V_36 , * V_37 ;
int V_21 = 0 ;
int V_38 ;
if ( V_11 -> V_42 . V_1 == V_9 )
return F_245 ( V_34 , V_78 ) ;
F_3 ( L_109 ,
V_11 , V_34 ? V_34 -> V_16 : L_10 ) ;
if ( V_11 -> V_42 . V_121 == V_182 )
return 0 ;
if ( ! F_246 ( V_359 -> V_190 ) )
return - V_361 ;
F_30 (bond, slave, i) {
const struct V_56 * V_57 = V_36 -> V_15 -> V_58 ;
F_3 ( L_110 , V_36 , V_36 -> V_15 -> V_16 ) ;
if ( V_57 -> V_181 == NULL ) {
V_21 = - V_183 ;
F_3 ( L_111 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
V_21 = F_136 ( V_36 -> V_15 , V_78 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
}
memcpy ( V_34 -> V_139 , V_359 -> V_190 , V_34 -> V_138 ) ;
return 0 ;
V_39:
memcpy ( V_360 . V_190 , V_34 -> V_139 , V_34 -> V_138 ) ;
V_360 . V_191 = V_34 -> type ;
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_358 ;
V_358 = F_136 ( V_36 -> V_15 , & V_360 ) ;
if ( V_358 ) {
F_3 ( L_108 ,
V_358 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_247 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_362 ;
int V_38 , V_363 , V_21 = 1 ;
struct V_279 * V_280 = F_211 ( V_29 ) ;
if ( ( V_280 -> V_246 == V_364 ) &&
( V_29 -> V_246 == F_191 ( V_253 ) ) ) {
F_67 ( & V_11 -> V_123 ) ;
V_36 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_36 )
goto V_23;
} else {
V_363 = V_11 -> V_365 ++ % V_11 -> V_40 ;
F_30 (bond, slave, i) {
V_363 -- ;
if ( V_363 < 0 )
break;
}
}
V_362 = V_36 ;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_150 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_121 ( V_29 ) ;
}
return V_366 ;
}
static int F_248 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_21 = 1 ;
F_67 ( & V_11 -> V_123 ) ;
if ( V_11 -> V_77 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_77 -> V_15 ) ;
if ( V_21 )
F_121 ( V_29 ) ;
F_70 ( & V_11 -> V_123 ) ;
return V_366 ;
}
static int F_249 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_362 ;
int V_363 ;
int V_38 ;
int V_21 = 1 ;
V_363 = V_11 -> V_367 ( V_29 , V_11 -> V_40 ) ;
F_30 (bond, slave, i) {
V_363 -- ;
if ( V_363 < 0 )
break;
}
V_362 = V_36 ;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_150 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_121 ( V_29 ) ;
}
return V_366 ;
}
static int F_250 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_362 ;
struct V_30 * V_368 = NULL ;
int V_38 ;
int V_21 = 1 ;
F_67 ( & V_11 -> V_123 ) ;
V_362 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_362 )
goto V_23;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_150 ( V_36 ) ) {
if ( V_368 ) {
struct V_28 * V_369 = F_119 ( V_29 , V_160 ) ;
if ( ! V_369 ) {
F_32 ( L_112 ,
V_34 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_369 , V_368 ) ;
if ( V_21 ) {
F_121 ( V_369 ) ;
continue;
}
}
V_368 = V_36 -> V_15 ;
}
}
if ( V_368 )
V_21 = F_20 ( V_11 , V_29 , V_368 ) ;
V_23:
if ( V_21 )
F_121 ( V_29 ) ;
return V_366 ;
}
static void F_251 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_42 . V_370 ) {
case V_371 :
V_11 -> V_367 = F_210 ;
break;
case V_372 :
V_11 -> V_367 = F_213 ;
break;
case V_373 :
default:
V_11 -> V_367 = F_216 ;
break;
}
}
static inline int F_252 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_38 , V_21 = 1 ;
struct V_36 * V_36 = NULL ;
struct V_36 * V_374 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_30 (bond, check_slave, i) {
if ( V_374 -> V_185 == V_29 -> V_32 ) {
V_36 = V_374 ;
break;
}
}
if ( V_36 && V_36 -> V_185 && F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
}
return V_21 ;
}
static T_9 F_253 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_9 V_375 = F_254 ( V_29 ) ? F_255 ( V_29 ) : 0 ;
F_22 ( V_29 ) -> V_33 = V_29 -> V_32 ;
if ( F_23 ( V_375 >= V_15 -> V_376 ) ) {
do {
V_375 -= V_15 -> V_376 ;
} while ( V_375 >= V_15 -> V_376 );
}
return V_375 ;
}
static T_10 F_256 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
if ( F_257 ( V_11 -> V_42 . V_1 ) ) {
if ( ! F_252 ( V_11 , V_29 ) )
return V_366 ;
}
switch ( V_11 -> V_42 . V_1 ) {
case V_3 :
return F_247 ( V_29 , V_15 ) ;
case V_4 :
return F_248 ( V_29 , V_15 ) ;
case V_5 :
return F_249 ( V_29 , V_15 ) ;
case V_6 :
return F_250 ( V_29 , V_15 ) ;
case V_7 :
return F_258 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_259 ( V_29 , V_15 ) ;
default:
F_32 ( L_113 ,
V_15 -> V_16 , V_11 -> V_42 . V_1 ) ;
F_260 ( 1 ) ;
F_121 ( V_29 ) ;
return V_366 ;
}
}
static T_10 F_261 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_10 V_158 = V_366 ;
if ( F_262 ( V_15 ) )
return V_377 ;
F_67 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_40 )
V_158 = F_256 ( V_29 , V_15 ) ;
else
F_121 ( V_29 ) ;
F_70 ( & V_11 -> V_20 ) ;
return V_158 ;
}
void F_263 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_34 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_251 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_251 ( V_11 ) ;
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
static void F_264 ( struct V_30 * V_34 ,
struct V_378 * V_379 )
{
strncpy ( V_379 -> V_380 , V_381 , 32 ) ;
strncpy ( V_379 -> V_382 , V_383 , 32 ) ;
snprintf ( V_379 -> V_384 , 32 , L_114 , V_385 ) ;
}
static void F_265 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_11 -> V_88 )
F_266 ( V_11 -> V_88 ) ;
F_267 ( V_34 ) ;
}
static void F_268 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_269 ( & V_11 -> V_20 ) ;
F_269 ( & V_11 -> V_123 ) ;
V_11 -> V_42 = V_386 ;
V_11 -> V_15 = V_34 ;
F_5 ( & V_11 -> V_19 ) ;
F_132 ( V_34 ) ;
V_34 -> V_58 = & V_387 ;
V_34 -> V_65 = & V_388 ;
F_263 ( V_11 , V_11 -> V_42 . V_1 ) ;
V_34 -> V_389 = F_265 ;
V_34 -> V_390 = 0 ;
V_34 -> V_100 |= V_276 | V_391 ;
V_34 -> V_84 |= V_195 ;
V_34 -> V_84 &= ~ ( V_392 | V_178 ) ;
V_34 -> V_140 |= V_142 ;
V_34 -> V_140 |= V_393 ;
V_34 -> V_394 = V_146 |
V_395 |
V_396 |
V_397 ;
V_34 -> V_394 &= ~ ( V_398 & ~ V_399 ) ;
V_34 -> V_140 |= V_34 -> V_394 ;
}
static void F_270 ( struct V_10 * V_11 )
{
if ( V_11 -> V_42 . V_119 && F_223 ( & V_11 -> V_226 ) )
F_222 ( & V_11 -> V_226 ) ;
if ( V_11 -> V_42 . V_162 && F_223 ( & V_11 -> V_256 ) )
F_222 ( & V_11 -> V_256 ) ;
if ( V_11 -> V_42 . V_1 == V_9 &&
F_223 ( & V_11 -> V_289 ) )
F_222 ( & V_11 -> V_289 ) ;
if ( V_11 -> V_42 . V_1 == V_7 &&
F_223 ( & V_11 -> V_291 ) )
F_222 ( & V_11 -> V_291 ) ;
if ( F_223 ( & V_11 -> V_89 ) )
F_222 ( & V_11 -> V_89 ) ;
}
static void F_271 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_13 * V_14 , * V_400 ;
F_103 ( V_34 ) ;
F_161 ( V_34 ) ;
F_12 ( & V_11 -> V_401 ) ;
F_270 ( V_11 ) ;
F_272 ( V_11 ) ;
F_239 ( & V_11 -> V_346 ) ;
F_273 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_274 ( const char * V_402 , const struct V_403 * V_404 )
{
int V_405 = - 1 , V_38 , V_128 ;
char * V_406 , V_407 [ V_408 + 1 ] = { 0 , } ;
for ( V_406 = ( char * ) V_402 ; * V_406 ; V_406 ++ )
if ( ! ( isdigit ( * V_406 ) || isspace ( * V_406 ) ) )
break;
if ( * V_406 )
V_128 = sscanf ( V_402 , L_115 , V_407 ) ;
else
V_128 = sscanf ( V_402 , L_114 , & V_405 ) ;
if ( ! V_128 )
return - 1 ;
for ( V_38 = 0 ; V_404 [ V_38 ] . V_409 ; V_38 ++ ) {
if ( V_405 == V_404 [ V_38 ] . V_1 )
return V_404 [ V_38 ] . V_1 ;
if ( strcmp ( V_407 , V_404 [ V_38 ] . V_409 ) == 0 )
return V_404 [ V_38 ] . V_1 ;
}
return - 1 ;
}
static int F_275 ( struct V_410 * V_42 )
{
int V_411 , V_412 , V_413 ;
if ( V_1 ) {
V_212 = F_274 ( V_1 , V_414 ) ;
if ( V_212 == - 1 ) {
F_32 ( L_116 ,
V_1 == NULL ? L_18 : V_1 ) ;
return - V_180 ;
}
}
if ( V_367 ) {
if ( ( V_212 != V_5 ) &&
( V_212 != V_7 ) ) {
F_84 ( L_117 ,
F_1 ( V_212 ) ) ;
} else {
V_415 = F_274 ( V_367 ,
V_416 ) ;
if ( V_415 == - 1 ) {
F_32 ( L_118 ,
V_367 == NULL ? L_18 :
V_367 ) ;
return - V_180 ;
}
}
}
if ( V_417 ) {
if ( V_212 != V_7 ) {
F_84 ( L_119 ,
F_1 ( V_212 ) ) ;
} else {
V_418 = F_274 ( V_417 , V_419 ) ;
if ( V_418 == - 1 ) {
F_32 ( L_120 ,
V_417 == NULL ? L_18 : V_417 ) ;
return - V_180 ;
}
}
}
if ( V_420 ) {
V_42 -> V_420 = F_274 ( V_420 , V_421 ) ;
if ( V_42 -> V_420 == - 1 ) {
F_32 ( L_121 ,
V_420 == NULL ? L_18 : V_420 ) ;
return - V_180 ;
}
if ( V_212 != V_7 ) {
F_37 ( L_122 ) ;
}
} else {
V_42 -> V_420 = V_422 ;
}
if ( V_423 < 0 ) {
F_37 ( L_123 ,
V_423 , 0 , V_424 , V_425 ) ;
V_423 = V_425 ;
}
if ( V_119 < 0 ) {
F_37 ( L_124 ,
V_119 , V_424 , V_426 ) ;
V_119 = V_426 ;
}
if ( V_111 < 0 ) {
F_37 ( L_125 ,
V_111 , V_424 ) ;
V_111 = 0 ;
}
if ( V_223 < 0 ) {
F_37 ( L_126 ,
V_223 , V_424 ) ;
V_223 = 0 ;
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
if ( V_212 == V_7 ) {
if ( ! V_119 ) {
F_37 ( L_129 ) ;
F_37 ( L_130 ) ;
V_119 = 100 ;
}
}
if ( V_427 < 1 || V_427 > 255 ) {
F_37 ( L_131
L_132 ,
V_427 , V_428 ) ;
V_427 = V_428 ;
}
if ( ( V_429 != 0 ) && ( V_429 != 1 ) ) {
F_37 ( L_133
L_134
L_135 , V_429 ) ;
V_429 = 0 ;
}
if ( V_126 < 0 || V_126 > 255 ) {
F_37 ( L_136
L_137 ,
V_126 , V_430 ) ;
V_126 = V_430 ;
}
if ( ( V_212 == V_8 ) ||
( V_212 == V_9 ) ) {
if ( ! V_119 ) {
F_37 ( L_138 ) ;
F_37 ( L_130 ) ;
V_119 = 100 ;
}
}
if ( V_212 == V_9 ) {
F_276 ( L_139 ,
V_111 ) ;
}
if ( ! V_119 ) {
if ( V_111 || V_223 ) {
F_37 ( L_140 ,
V_111 , V_223 ) ;
}
} else {
if ( V_162 ) {
F_37 ( L_141 ,
V_119 , V_162 ) ;
V_162 = 0 ;
}
if ( ( V_111 % V_119 ) != 0 ) {
F_37 ( L_142 ,
V_111 , V_119 ,
( V_111 / V_119 ) * V_119 ) ;
}
V_111 /= V_119 ;
if ( ( V_223 % V_119 ) != 0 ) {
F_37 ( L_143 ,
V_223 , V_119 ,
( V_223 / V_119 ) * V_119 ) ;
}
V_223 /= V_119 ;
}
if ( V_162 < 0 ) {
F_37 ( L_144 ,
V_162 , V_424 , V_431 ) ;
V_162 = V_431 ;
}
for ( V_432 = 0 ;
( V_432 < V_237 ) && V_433 [ V_432 ] ;
V_432 ++ ) {
if ( ! isdigit ( V_433 [ V_432 ] [ 0 ] ) ) {
F_37 ( L_145 ,
V_433 [ V_432 ] ) ;
V_162 = 0 ;
} else {
T_6 V_228 = F_277 ( V_433 [ V_432 ] ) ;
V_434 [ V_432 ] = V_228 ;
}
}
if ( V_162 && ! V_432 ) {
F_37 ( L_146 ,
V_162 ) ;
V_162 = 0 ;
}
if ( V_255 ) {
if ( V_212 != V_4 ) {
F_32 ( L_147 ) ;
return - V_180 ;
}
if ( ! V_162 ) {
F_32 ( L_148 ) ;
return - V_180 ;
}
V_411 = F_274 ( V_255 ,
V_435 ) ;
if ( V_411 == - 1 ) {
F_32 ( L_149 ,
V_255 == NULL ? L_18 : V_255 ) ;
return - V_180 ;
}
} else
V_411 = 0 ;
if ( V_119 ) {
F_84 ( L_150 , V_119 ) ;
} else if ( V_162 ) {
int V_38 ;
F_84 ( L_151 ,
V_162 ,
V_435 [ V_411 ] . V_409 ,
V_432 ) ;
for ( V_38 = 0 ; V_38 < V_432 ; V_38 ++ )
F_84 ( L_152 , V_433 [ V_38 ] ) ;
F_84 ( L_153 ) ;
} else if ( V_423 ) {
F_3 ( L_154 ) ;
}
if ( V_200 && ! F_53 ( V_212 ) ) {
F_37 ( L_155 ,
V_200 , F_1 ( V_212 ) ) ;
V_200 = NULL ;
}
if ( V_200 && V_106 ) {
V_413 = F_274 ( V_106 ,
V_436 ) ;
if ( V_413 == - 1 ) {
F_32 ( L_156 ,
V_106 ==
NULL ? L_18 : V_106 ) ;
return - V_180 ;
}
} else {
V_413 = V_437 ;
}
if ( V_121 ) {
V_412 = F_274 ( V_121 ,
V_438 ) ;
if ( V_412 == - 1 ) {
F_32 ( L_157 ,
V_255 == NULL ? L_18 : V_255 ) ;
return - V_180 ;
}
if ( V_212 != V_4 )
F_37 ( L_158 ) ;
} else {
V_412 = V_439 ;
}
V_42 -> V_1 = V_212 ;
V_42 -> V_370 = V_415 ;
V_42 -> V_119 = V_119 ;
V_42 -> V_122 = V_122 ;
V_42 -> V_162 = V_162 ;
V_42 -> V_255 = V_411 ;
V_42 -> V_111 = V_111 ;
V_42 -> V_223 = V_223 ;
V_42 -> V_63 = V_63 ;
V_42 -> V_418 = V_418 ;
V_42 -> V_200 [ 0 ] = 0 ;
V_42 -> V_106 = V_413 ;
V_42 -> V_121 = V_412 ;
V_42 -> V_427 = V_427 ;
V_42 -> V_429 = V_429 ;
V_42 -> V_126 = V_126 ;
V_42 -> V_440 = V_440 ;
if ( V_200 ) {
strncpy ( V_42 -> V_200 , V_200 , V_69 ) ;
V_42 -> V_200 [ V_69 - 1 ] = 0 ;
}
memcpy ( V_42 -> V_234 , V_434 , sizeof( V_434 ) ) ;
return 0 ;
}
static void F_278 ( struct V_30 * V_15 ,
struct V_441 * V_375 ,
void * V_442 )
{
F_279 ( & V_375 -> V_443 ,
& V_444 ) ;
}
static void F_280 ( struct V_30 * V_15 )
{
F_279 ( & V_15 -> V_445 ,
& V_446 ) ;
F_281 ( V_15 , F_278 , NULL ) ;
}
static int F_282 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_447 * V_448 = F_283 ( F_181 ( V_34 ) , V_449 ) ;
struct V_450 * V_451 = & ( F_284 ( V_11 ) ) ;
F_3 ( L_159 , V_34 -> V_16 ) ;
F_285 ( & ( V_451 -> V_452 ) ) ;
F_285 ( & ( V_451 -> V_453 ) ) ;
V_11 -> V_88 = F_286 ( V_34 -> V_16 ) ;
if ( ! V_11 -> V_88 )
return - V_18 ;
F_280 ( V_34 ) ;
F_7 ( & V_11 -> V_401 , & V_448 -> V_454 ) ;
F_287 ( V_11 ) ;
F_288 ( V_11 ) ;
F_289 ( & V_11 -> V_346 ) ;
return 0 ;
}
static int F_290 ( struct V_455 * V_456 [] , struct V_455 * V_167 [] )
{
if ( V_456 [ V_457 ] ) {
if ( F_291 ( V_456 [ V_457 ] ) != V_96 )
return - V_180 ;
if ( ! F_246 ( F_292 ( V_456 [ V_457 ] ) ) )
return - V_361 ;
}
return 0 ;
}
static int F_293 ( struct V_458 * V_458 , struct V_455 * V_456 [] )
{
return V_427 ;
}
int F_294 ( struct V_458 * V_458 , const char * V_16 )
{
struct V_30 * V_34 ;
int V_21 ;
F_295 () ;
V_34 = F_296 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_160 ,
F_268 , V_427 ) ;
if ( ! V_34 ) {
F_32 ( L_161 , V_16 ) ;
F_172 () ;
return - V_18 ;
}
F_297 ( V_34 , V_458 ) ;
V_34 -> V_459 = & V_460 ;
V_21 = F_298 ( V_34 ) ;
F_43 ( V_34 ) ;
F_172 () ;
if ( V_21 < 0 )
F_265 ( V_34 ) ;
return V_21 ;
}
static int T_11 F_299 ( struct V_458 * V_458 )
{
struct V_447 * V_448 = F_283 ( V_458 , V_449 ) ;
V_448 -> V_458 = V_458 ;
F_5 ( & V_448 -> V_454 ) ;
F_300 ( V_448 ) ;
F_301 ( V_448 ) ;
return 0 ;
}
static void T_12 F_302 ( struct V_458 * V_458 )
{
struct V_447 * V_448 = F_283 ( V_458 , V_449 ) ;
F_303 ( V_448 ) ;
F_304 ( V_448 ) ;
}
static int T_13 F_305 ( void )
{
int V_38 ;
int V_21 ;
F_84 ( L_162 , V_461 ) ;
V_21 = F_275 ( & V_386 ) ;
if ( V_21 )
goto V_23;
V_21 = F_306 ( & V_462 ) ;
if ( V_21 )
goto V_23;
V_21 = F_307 ( & V_460 ) ;
if ( V_21 )
goto V_463;
F_308 () ;
for ( V_38 = 0 ; V_38 < V_423 ; V_38 ++ ) {
V_21 = F_294 ( & V_464 , NULL ) ;
if ( V_21 )
goto V_76;
}
F_309 ( & V_465 ) ;
V_23:
return V_21 ;
V_76:
F_310 ( & V_460 ) ;
V_463:
F_311 ( & V_462 ) ;
goto V_23;
}
static void T_14 F_312 ( void )
{
F_313 ( & V_465 ) ;
F_314 () ;
F_310 ( & V_460 ) ;
F_311 ( & V_462 ) ;
#ifdef F_147
F_315 ( F_316 ( & V_466 ) ) ;
#endif
}
