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
int V_38 ;
unsigned int V_100 , V_150 = V_151 ;
F_67 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_112 )
goto V_152;
F_30 (bond, slave, i) {
V_146 = F_106 ( V_146 ,
V_36 -> V_15 -> V_146 , V_147 ) ;
V_150 &= V_36 -> V_15 -> V_84 ;
if ( V_36 -> V_15 -> V_153 > V_148 )
V_148 = V_36 -> V_15 -> V_153 ;
}
V_152:
V_34 -> V_146 = V_146 ;
V_34 -> V_153 = V_148 ;
V_100 = V_34 -> V_84 & ~ V_151 ;
V_34 -> V_84 = V_100 | V_150 ;
F_70 ( & V_11 -> V_20 ) ;
F_108 ( V_34 ) ;
}
static void F_109 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_34 -> V_154 = V_31 -> V_154 ;
V_34 -> type = V_31 -> type ;
V_34 -> V_153 = V_31 -> V_153 ;
V_34 -> V_139 = V_31 -> V_139 ;
memcpy ( V_34 -> V_155 , V_31 -> V_155 ,
V_31 -> V_139 ) ;
V_11 -> V_156 = 1 ;
}
static bool F_110 ( struct V_28 * V_29 ,
struct V_36 * V_36 ,
struct V_10 * V_11 )
{
if ( F_111 ( V_36 ) ) {
if ( V_11 -> V_42 . V_1 == V_9 &&
V_29 -> V_157 != V_158 &&
V_29 -> V_157 != V_159 )
return false ;
return true ;
}
return false ;
}
static T_6 F_112 ( struct V_28 * * V_160 )
{
struct V_28 * V_29 = * V_160 ;
struct V_36 * V_36 ;
struct V_10 * V_11 ;
int (* F_113)( const struct V_28 * , struct V_10 * ,
struct V_36 * );
int V_161 = V_162 ;
V_29 = F_114 ( V_29 , V_132 ) ;
if ( F_23 ( ! V_29 ) )
return V_163 ;
* V_160 = V_29 ;
V_36 = F_115 ( V_29 -> V_15 ) ;
V_11 = V_36 -> V_11 ;
if ( V_11 -> V_42 . V_164 )
V_36 -> V_15 -> V_165 = V_118 ;
F_113 = F_116 ( V_11 -> F_113 ) ;
if ( F_113 ) {
V_161 = F_113 ( V_29 , V_11 , V_36 ) ;
if ( V_161 == V_163 ) {
F_117 ( V_29 ) ;
return V_161 ;
}
}
if ( F_110 ( V_29 , V_36 , V_11 ) ) {
return V_166 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_42 . V_1 == V_9 &&
V_11 -> V_15 -> V_84 & V_86 &&
V_29 -> V_157 == V_167 ) {
if ( F_23 ( F_118 ( V_29 ,
V_29 -> V_168 - F_119 ( V_29 ) ) ) ) {
F_120 ( V_29 ) ;
return V_163 ;
}
memcpy ( F_121 ( V_29 ) -> V_169 , V_11 -> V_15 -> V_140 , V_96 ) ;
}
return V_161 ;
}
int F_122 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
const struct V_56 * V_57 = V_31 -> V_58 ;
struct V_36 * V_129 = NULL ;
struct V_93 * V_94 ;
struct V_170 V_78 ;
int V_171 ;
int V_21 = 0 ;
if ( ! V_11 -> V_42 . V_63 && V_31 -> V_65 == NULL &&
V_57 -> V_67 == NULL ) {
F_37 ( L_26 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_100 & V_172 ) {
F_3 ( L_27 ) ;
return - V_173 ;
}
if ( V_31 -> V_141 & V_143 ) {
F_3 ( L_28 , V_31 -> V_16 ) ;
if ( F_123 ( V_11 ) ) {
F_32 ( L_29 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
return - V_174 ;
} else {
F_37 ( L_30 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_34 -> V_16 ) ;
}
} else {
F_3 ( L_31 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_100 & V_175 ) ) {
F_32 ( L_32 ,
V_31 -> V_16 ) ;
V_21 = - V_174 ;
goto V_176;
}
if ( V_11 -> V_40 == 0 ) {
if ( V_34 -> type != V_31 -> type ) {
F_3 ( L_33 ,
V_34 -> V_16 ,
V_34 -> type , V_31 -> type ) ;
V_21 = F_90 ( V_34 ,
V_177 ) ;
V_21 = F_124 ( V_21 ) ;
if ( V_21 ) {
F_32 ( L_34 ,
V_34 -> V_16 ) ;
V_21 = - V_173 ;
goto V_176;
}
F_125 ( V_34 ) ;
F_126 ( V_34 ) ;
if ( V_31 -> type != V_178 )
F_109 ( V_34 , V_31 ) ;
else {
F_127 ( V_34 ) ;
V_34 -> V_84 &= ~ V_179 ;
}
F_90 ( V_34 ,
V_180 ) ;
}
} else if ( V_34 -> type != V_31 -> type ) {
F_32 ( L_35 ,
V_31 -> V_16 ,
V_31 -> type , V_34 -> type ) ;
V_21 = - V_181 ;
goto V_176;
}
if ( V_57 -> V_182 == NULL ) {
if ( V_11 -> V_40 == 0 ) {
F_37 ( L_36 ,
V_34 -> V_16 ) ;
V_11 -> V_42 . V_121 = V_183 ;
} else if ( V_11 -> V_42 . V_121 != V_183 ) {
F_32 ( L_37 ,
V_34 -> V_16 ) ;
V_21 = - V_184 ;
goto V_176;
}
}
F_128 ( V_185 , V_31 ) ;
if ( F_129 ( V_11 -> V_15 -> V_140 ) )
memcpy ( V_11 -> V_15 -> V_140 , V_31 -> V_140 ,
V_31 -> V_139 ) ;
V_129 = F_4 ( sizeof( struct V_36 ) , V_17 ) ;
if ( ! V_129 ) {
V_21 = - V_18 ;
goto V_176;
}
V_129 -> V_186 = 0 ;
V_129 -> V_187 = V_31 -> V_188 ;
V_21 = F_130 ( V_31 , V_11 -> V_15 -> V_188 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_189;
}
memcpy ( V_129 -> V_190 , V_31 -> V_140 , V_96 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_191 , V_34 -> V_140 , V_34 -> V_139 ) ;
V_78 . V_192 = V_31 -> type ;
V_21 = F_131 ( V_31 , & V_78 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_193;
}
}
V_21 = F_132 ( V_31 , V_34 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_21 ) ;
goto V_194;
}
V_21 = F_133 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_41 , V_31 -> V_16 ) ;
goto V_195;
}
V_129 -> V_11 = V_11 ;
V_129 -> V_15 = V_31 ;
V_31 -> V_84 |= V_196 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_134 ( V_11 , V_129 ) ;
if ( V_21 )
goto V_197;
}
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 ) {
V_21 = F_54 ( V_31 , 1 ) ;
if ( V_21 )
goto V_197;
}
if ( V_34 -> V_100 & V_102 ) {
V_21 = F_56 ( V_31 , 1 ) ;
if ( V_21 )
goto V_197;
}
F_135 ( V_34 ) ;
F_74 (ha, bond_dev)
F_58 ( V_31 , V_94 -> V_78 ) ;
F_136 ( V_34 ) ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
T_3 V_95 [ V_96 ] = V_97 ;
F_58 ( V_31 , V_95 ) ;
}
F_36 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_92 ( V_11 , V_129 ) ;
V_129 -> V_114 = 0 ;
V_129 -> V_198 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_107 ( V_11 ) ;
F_67 ( & V_11 -> V_20 ) ;
V_129 -> V_199 = V_118 -
( F_137 ( V_11 -> V_42 . V_164 ) + 1 ) ;
if ( V_11 -> V_42 . V_119 && ! V_11 -> V_42 . V_63 ) {
V_171 = F_47 ( V_11 , V_31 , 1 ) ;
if ( ( V_171 == - 1 ) && ! V_11 -> V_42 . V_164 ) {
F_37 ( L_42 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_171 == - 1 ) {
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
V_129 -> V_43 = V_200 ;
}
} else if ( V_11 -> V_42 . V_164 ) {
V_129 -> V_43 = ( F_41 ( V_31 ) ?
V_44 : V_200 ) ;
} else {
V_129 -> V_43 = V_44 ;
}
if ( V_129 -> V_43 != V_200 )
V_129 -> V_118 = V_118 ;
F_3 ( L_44 ,
V_129 -> V_43 == V_200 ? L_45 :
( V_129 -> V_43 == V_44 ? L_46 : L_47 ) ) ;
F_44 ( V_129 ) ;
if ( F_53 ( V_11 -> V_42 . V_1 ) && V_11 -> V_42 . V_201 [ 0 ] ) {
if ( strcmp ( V_11 -> V_42 . V_201 , V_129 -> V_15 -> V_16 ) == 0 ) {
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
F_138 ( V_129 ) . V_202 = 1 ;
F_139 ( V_11 , 1000 / V_203 ) ;
} else {
F_138 ( V_129 ) . V_202 =
F_138 ( V_129 -> V_27 ) . V_202 + 1 ;
}
F_140 ( V_129 ) ;
break;
case V_8 :
case V_9 :
F_141 ( V_129 ) ;
F_88 ( V_129 ) ;
F_91 ( V_11 ) ;
break;
default:
F_3 ( L_48 ) ;
F_141 ( V_129 ) ;
if ( ! V_11 -> V_77 )
V_11 -> V_77 = V_129 ;
break;
}
F_8 ( & V_11 -> V_123 ) ;
F_39 ( V_11 ) ;
#ifdef F_142
V_31 -> V_138 = F_103 ( V_11 ) ;
if ( V_31 -> V_138 ) {
if ( F_94 ( V_129 ) ) {
F_70 ( & V_11 -> V_20 ) ;
F_84 ( L_49
L_50 ,
V_34 -> V_16 ) ;
V_21 = - V_173 ;
goto V_204;
}
}
#endif
F_70 ( & V_11 -> V_20 ) ;
V_21 = F_143 ( V_34 , V_31 ) ;
if ( V_21 )
goto V_204;
V_21 = F_144 ( V_31 , F_112 ,
V_129 ) ;
if ( V_21 ) {
F_3 ( L_51 , V_21 ) ;
goto V_205;
}
F_84 ( L_52 ,
V_34 -> V_16 , V_31 -> V_16 ,
F_145 ( V_129 ) ? L_53 : L_54 ,
V_129 -> V_43 != V_200 ? L_55 : L_56 ) ;
return 0 ;
V_205:
F_146 ( V_34 , V_31 ) ;
V_204:
F_6 ( & V_11 -> V_20 ) ;
F_93 ( V_11 , V_129 ) ;
F_8 ( & V_11 -> V_20 ) ;
V_197:
F_147 ( V_31 ) ;
V_195:
F_132 ( V_31 , NULL ) ;
V_194:
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_191 , V_129 -> V_190 , V_96 ) ;
V_78 . V_192 = V_31 -> type ;
F_131 ( V_31 , & V_78 ) ;
}
V_193:
F_130 ( V_31 , V_129 -> V_187 ) ;
V_189:
F_15 ( V_129 ) ;
V_176:
F_107 ( V_11 ) ;
return V_21 ;
}
int F_148 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_206 ;
struct V_170 V_78 ;
T_5 V_207 = V_34 -> V_141 ;
if ( ! ( V_31 -> V_100 & V_172 ) ||
( V_31 -> V_83 != V_34 ) ) {
F_32 ( L_57 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
return - V_181 ;
}
F_10 () ;
F_90 ( V_34 , V_208 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_36 = F_26 ( V_11 , V_31 ) ;
if ( ! V_36 ) {
F_84 ( L_58 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_181 ;
}
F_149 ( V_31 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_150 () ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
if ( F_151 ( V_34 -> V_140 , V_36 -> V_190 ) &&
V_11 -> V_40 > 1 )
F_37 ( L_59 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_36 -> V_190 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_152 ( V_36 ) ;
}
F_84 ( L_60 ,
V_34 -> V_16 ,
F_145 ( V_36 ) ? L_61 : L_62 ,
V_31 -> V_16 ) ;
V_206 = V_11 -> V_77 ;
V_11 -> V_209 = NULL ;
F_93 ( V_11 , V_36 ) ;
if ( V_11 -> V_104 == V_36 )
V_11 -> V_104 = NULL ;
if ( V_206 == V_36 )
F_83 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_153 ( V_11 , V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_206 == V_36 ) {
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
if ( F_123 ( V_11 ) ) {
F_37 ( L_63 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_37 ( L_64 ,
V_34 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
if ( V_11 -> V_40 == 0 )
F_128 ( V_210 , V_11 -> V_15 ) ;
F_107 ( V_11 ) ;
if ( ! ( V_34 -> V_141 & V_143 ) &&
( V_207 & V_143 ) )
F_84 ( L_65 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
F_146 ( V_34 , V_31 ) ;
F_38 ( V_11 , V_31 ) ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 )
F_54 ( V_31 , - 1 ) ;
if ( V_34 -> V_100 & V_102 )
F_56 ( V_31 , - 1 ) ;
F_135 ( V_34 ) ;
F_73 ( V_34 , V_31 ) ;
F_136 ( V_34 ) ;
}
F_132 ( V_31 , NULL ) ;
F_96 ( V_36 ) ;
F_147 ( V_31 ) ;
if ( V_11 -> V_42 . V_121 != V_183 ) {
memcpy ( V_78 . V_191 , V_36 -> V_190 , V_96 ) ;
V_78 . V_192 = V_31 -> type ;
F_131 ( V_31 , & V_78 ) ;
}
F_130 ( V_31 , V_36 -> V_187 ) ;
V_31 -> V_84 &= ~ V_196 ;
F_15 ( V_36 ) ;
return 0 ;
}
static int F_154 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_161 ;
V_161 = F_148 ( V_34 , V_31 ) ;
if ( ( V_161 == 0 ) && ( V_11 -> V_40 == 0 ) ) {
V_34 -> V_84 |= V_133 ;
F_84 ( L_66 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_155 ( V_34 ) ;
}
return V_161 ;
}
static int F_156 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
struct V_30 * V_31 ;
struct V_170 V_78 ;
F_6 ( & V_11 -> V_20 ) ;
F_43 ( V_34 ) ;
if ( V_11 -> V_40 == 0 )
goto V_23;
V_11 -> V_209 = NULL ;
V_11 -> V_104 = NULL ;
F_83 ( V_11 , NULL ) ;
while ( ( V_36 = V_11 -> V_112 ) != NULL ) {
if ( V_11 -> V_42 . V_1 == V_7 )
F_152 ( V_36 ) ;
V_31 = V_36 -> V_15 ;
F_93 ( V_11 , V_36 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_149 ( V_31 ) ;
F_150 () ;
if ( F_13 ( V_11 ) ) {
F_153 ( V_11 , V_36 ) ;
}
F_146 ( V_34 , V_31 ) ;
F_38 ( V_11 , V_31 ) ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) ) {
if ( V_34 -> V_100 & V_101 )
F_54 ( V_31 , - 1 ) ;
if ( V_34 -> V_100 & V_102 )
F_56 ( V_31 , - 1 ) ;
F_135 ( V_34 ) ;
F_73 ( V_34 , V_31 ) ;
F_136 ( V_34 ) ;
}
F_132 ( V_31 , NULL ) ;
F_96 ( V_36 ) ;
F_147 ( V_31 ) ;
if ( ! V_11 -> V_42 . V_121 ) {
memcpy ( V_78 . V_191 , V_36 -> V_190 , V_96 ) ;
V_78 . V_192 = V_31 -> type ;
F_131 ( V_31 , & V_78 ) ;
}
F_15 ( V_36 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
memset ( V_34 -> V_140 , 0 , V_34 -> V_139 ) ;
if ( F_123 ( V_11 ) ) {
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
static int F_157 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_99 = NULL ;
struct V_36 * V_98 = NULL ;
int V_21 = 0 ;
if ( ! F_53 ( V_11 -> V_42 . V_1 ) )
return - V_181 ;
if ( ! ( V_31 -> V_100 & V_172 ) || ( V_31 -> V_83 != V_34 ) )
return - V_181 ;
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
V_21 = - V_181 ;
F_70 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_158 ( struct V_30 * V_34 , struct V_211 * V_212 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_212 -> V_213 = V_11 -> V_42 . V_1 ;
V_212 -> V_119 = V_11 -> V_42 . V_119 ;
F_67 ( & V_11 -> V_20 ) ;
V_212 -> V_214 = V_11 -> V_40 ;
F_70 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_159 ( struct V_30 * V_34 , struct V_215 * V_212 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 ;
int V_38 , V_21 = - V_22 ;
F_67 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
if ( V_38 == ( int ) V_212 -> V_216 ) {
V_21 = 0 ;
strcpy ( V_212 -> V_217 , V_36 -> V_15 -> V_16 ) ;
V_212 -> V_43 = V_36 -> V_43 ;
V_212 -> V_117 = F_160 ( V_36 ) ;
V_212 -> V_198 = V_36 -> V_198 ;
break;
}
}
F_70 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_161 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 , V_218 , V_219 = 0 ;
bool V_220 ;
V_220 = ! V_11 -> V_77 ? true : false ;
F_30 (bond, slave, i) {
V_36 -> V_221 = V_222 ;
V_218 = F_47 ( V_11 , V_36 -> V_15 , 0 ) ;
switch ( V_36 -> V_43 ) {
case V_44 :
if ( V_218 )
continue;
V_36 -> V_43 = V_223 ;
V_36 -> V_114 = V_11 -> V_42 . V_224 ;
if ( V_36 -> V_114 ) {
F_84 ( L_68 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_1 ==
V_4 ) ?
( F_145 ( V_36 ) ?
L_69 : L_70 ) : L_71 ,
V_36 -> V_15 -> V_16 ,
V_11 -> V_42 . V_224 * V_11 -> V_42 . V_119 ) ;
}
case V_223 :
if ( V_218 ) {
V_36 -> V_43 = V_44 ;
V_36 -> V_118 = V_118 ;
F_84 ( L_72 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_224 - V_36 -> V_114 ) *
V_11 -> V_42 . V_119 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_36 -> V_114 <= 0 ) {
V_36 -> V_221 = V_200 ;
V_219 ++ ;
continue;
}
V_36 -> V_114 -- ;
break;
case V_200 :
if ( ! V_218 )
continue;
V_36 -> V_43 = V_113 ;
V_36 -> V_114 = V_11 -> V_42 . V_111 ;
if ( V_36 -> V_114 ) {
F_84 ( L_73 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ,
V_220 ? 0 :
V_11 -> V_42 . V_111 *
V_11 -> V_42 . V_119 ) ;
}
case V_113 :
if ( ! V_218 ) {
V_36 -> V_43 = V_200 ;
F_84 ( L_74 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_42 . V_111 - V_36 -> V_114 ) *
V_11 -> V_42 . V_119 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
if ( V_220 )
V_36 -> V_114 = 0 ;
if ( V_36 -> V_114 <= 0 ) {
V_36 -> V_221 = V_44 ;
V_219 ++ ;
V_220 = false ;
continue;
}
V_36 -> V_114 -- ;
break;
}
}
return V_219 ;
}
static void F_162 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_30 (bond, slave, i) {
switch ( V_36 -> V_221 ) {
case V_222 :
continue;
case V_44 :
V_36 -> V_43 = V_44 ;
V_36 -> V_118 = V_118 ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_163 ( V_36 ) ;
} else if ( V_11 -> V_42 . V_1 != V_4 ) {
F_141 ( V_36 ) ;
} else if ( V_36 != V_11 -> V_104 ) {
F_163 ( V_36 ) ;
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
goto V_225;
continue;
case V_200 :
if ( V_36 -> V_198 < V_226 )
V_36 -> V_198 ++ ;
V_36 -> V_43 = V_200 ;
if ( V_11 -> V_42 . V_1 == V_4 ||
V_11 -> V_42 . V_1 == V_7 )
F_88 ( V_36 ) ;
F_84 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_11 -> V_42 . V_1 == V_7 )
F_85 ( V_36 ,
V_200 ) ;
if ( F_13 ( V_11 ) )
F_86 ( V_11 , V_36 ,
V_200 ) ;
if ( V_36 == V_11 -> V_77 )
goto V_225;
continue;
default:
F_32 ( L_79 ,
V_11 -> V_15 -> V_16 , V_36 -> V_221 ,
V_36 -> V_15 -> V_16 ) ;
V_36 -> V_221 = V_222 ;
continue;
}
V_225:
F_164 () ;
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
F_39 ( V_11 ) ;
}
void F_165 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_227 . V_92 ) ;
bool V_120 = false ;
unsigned long V_114 ;
F_67 ( & V_11 -> V_20 ) ;
V_114 = F_137 ( V_11 -> V_42 . V_119 ) ;
if ( V_11 -> V_40 == 0 )
goto V_228;
V_120 = F_81 ( V_11 ) ;
if ( F_161 ( V_11 ) ) {
F_70 ( & V_11 -> V_20 ) ;
if ( ! F_166 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_114 = 1 ;
V_120 = false ;
goto V_228;
}
F_67 ( & V_11 -> V_20 ) ;
F_162 ( V_11 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_167 () ;
F_67 ( & V_11 -> V_20 ) ;
}
V_228:
if ( V_11 -> V_42 . V_119 )
F_69 ( V_11 -> V_88 , & V_11 -> V_227 , V_114 ) ;
F_70 ( & V_11 -> V_20 ) ;
if ( V_120 ) {
if ( ! F_166 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_11 -> V_115 ++ ;
F_70 ( & V_11 -> V_20 ) ;
return;
}
F_90 ( V_11 -> V_15 , V_125 ) ;
F_167 () ;
}
}
static int F_168 ( struct V_10 * V_11 , T_7 V_229 )
{
struct V_13 * V_14 ;
struct V_30 * V_81 ;
if ( V_229 == F_169 ( V_11 -> V_15 , 0 , V_229 ) )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_62 () ;
V_81 = F_68 ( V_11 -> V_15 , V_14 -> V_12 ) ;
F_65 () ;
if ( V_81 && V_229 == F_169 ( V_81 , 0 , V_229 ) )
return 1 ;
}
return 0 ;
}
static void F_170 ( struct V_30 * V_31 , int V_230 , T_7 V_231 , T_7 V_232 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_80 , V_230 ,
V_31 -> V_16 , V_231 , V_232 , V_12 ) ;
V_29 = F_171 ( V_230 , V_233 , V_231 , V_31 , V_232 ,
NULL , V_31 -> V_140 , NULL ) ;
if ( ! V_29 ) {
F_32 ( L_81 ) ;
return;
}
if ( V_12 ) {
V_29 = F_172 ( V_29 , V_12 ) ;
if ( ! V_29 ) {
F_32 ( L_82 ) ;
return;
}
}
F_173 ( V_29 ) ;
}
static void F_174 ( struct V_10 * V_11 , struct V_36 * V_36 )
{
int V_38 , V_12 ;
T_7 * V_234 = V_11 -> V_42 . V_235 ;
struct V_13 * V_14 ;
struct V_30 * V_81 = NULL ;
struct V_236 * V_237 ;
for ( V_38 = 0 ; ( V_38 < V_238 ) ; V_38 ++ ) {
T_7 V_78 ;
if ( ! V_234 [ V_38 ] )
break;
F_3 ( L_83 , V_234 [ V_38 ] ) ;
if ( ! F_123 ( V_11 ) ) {
F_3 ( L_84 ) ;
V_78 = F_169 ( V_11 -> V_15 , V_234 [ V_38 ] , 0 ) ;
F_170 ( V_36 -> V_15 , V_239 , V_234 [ V_38 ] ,
V_78 , 0 ) ;
continue;
}
V_237 = F_175 ( F_176 ( V_11 -> V_15 ) , V_234 [ V_38 ] , 0 ,
V_240 , 0 ) ;
if ( F_177 ( V_237 ) ) {
if ( F_178 () ) {
F_37 ( L_85 ,
V_11 -> V_15 -> V_16 , & V_234 [ V_38 ] ) ;
}
continue;
}
if ( V_237 -> V_241 . V_15 == V_11 -> V_15 ) {
F_179 ( V_237 ) ;
F_3 ( L_86 ) ;
V_78 = F_169 ( V_11 -> V_15 , V_234 [ V_38 ] , 0 ) ;
F_170 ( V_36 -> V_15 , V_239 , V_234 [ V_38 ] ,
V_78 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_62 () ;
V_81 = F_68 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_65 () ;
if ( V_81 == V_237 -> V_241 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_87 ,
V_81 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 && V_81 ) {
F_179 ( V_237 ) ;
V_78 = F_169 ( V_81 , V_234 [ V_38 ] , 0 ) ;
F_170 ( V_36 -> V_15 , V_239 , V_234 [ V_38 ] ,
V_78 , V_12 ) ;
continue;
}
if ( F_178 () ) {
F_37 ( L_88 ,
V_11 -> V_15 -> V_16 , & V_234 [ V_38 ] ,
V_237 -> V_241 . V_15 ? V_237 -> V_241 . V_15 -> V_16 : L_18 ) ;
}
F_179 ( V_237 ) ;
}
}
static void F_180 ( struct V_10 * V_11 , struct V_36 * V_36 , T_7 V_242 , T_7 V_243 )
{
int V_38 ;
T_7 * V_234 = V_11 -> V_42 . V_235 ;
for ( V_38 = 0 ; ( V_38 < V_238 ) && V_234 [ V_38 ] ; V_38 ++ ) {
F_3 ( L_89 ,
& V_242 , & V_243 , V_38 , & V_234 [ V_38 ] ,
F_168 ( V_11 , V_243 ) ) ;
if ( V_242 == V_234 [ V_38 ] ) {
if ( F_168 ( V_11 , V_243 ) )
V_36 -> V_199 = V_118 ;
return;
}
}
}
static int F_181 ( const struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_36 * V_36 )
{
struct V_244 * V_245 = (struct V_244 * ) V_29 -> V_168 ;
unsigned char * V_246 ;
T_7 V_242 , V_243 ;
int V_247 ;
if ( V_29 -> V_248 != F_182 ( V_233 ) )
return V_162 ;
F_67 ( & V_11 -> V_20 ) ;
V_247 = F_183 ( V_11 -> V_15 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( V_247 > F_184 ( V_29 ) ) {
V_245 = F_185 ( V_247 , V_132 ) ;
if ( ! V_245 )
goto V_249;
if ( F_186 ( V_29 , 0 , V_245 , V_247 ) < 0 )
goto V_249;
}
if ( V_245 -> V_250 != V_11 -> V_15 -> V_139 ||
V_29 -> V_157 == V_251 ||
V_29 -> V_157 == V_252 ||
V_245 -> V_253 != F_187 ( V_178 ) ||
V_245 -> V_254 != F_187 ( V_255 ) ||
V_245 -> V_256 != 4 )
goto V_249;
V_246 = ( unsigned char * ) ( V_245 + 1 ) ;
V_246 += V_11 -> V_15 -> V_139 ;
memcpy ( & V_242 , V_246 , 4 ) ;
V_246 += 4 + V_11 -> V_15 -> V_139 ;
memcpy ( & V_243 , V_246 , 4 ) ;
F_3 ( L_91 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 , F_160 ( V_36 ) ,
V_11 -> V_42 . V_257 , F_188 ( V_11 , V_36 ) ,
& V_242 , & V_243 ) ;
if ( F_145 ( V_36 ) )
F_180 ( V_11 , V_36 , V_242 , V_243 ) ;
else
F_180 ( V_11 , V_36 , V_243 , V_242 ) ;
V_249:
F_70 ( & V_11 -> V_20 ) ;
if ( V_245 != (struct V_244 * ) V_29 -> V_168 )
F_15 ( V_245 ) ;
return V_162 ;
}
void F_189 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_258 . V_92 ) ;
struct V_36 * V_36 , * V_206 ;
int V_225 = 0 ;
int V_259 ;
int V_38 ;
F_67 ( & V_11 -> V_20 ) ;
V_259 = F_137 ( V_11 -> V_42 . V_164 ) ;
if ( V_11 -> V_40 == 0 )
goto V_228;
F_67 ( & V_11 -> V_123 ) ;
V_206 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
F_30 (bond, slave, i) {
unsigned long V_260 = F_190 ( V_36 -> V_15 ) ;
if ( V_36 -> V_43 != V_44 ) {
if ( F_191 ( V_118 ,
V_260 - V_259 ,
V_260 + V_259 ) &&
F_191 ( V_118 ,
V_36 -> V_15 -> V_165 - V_259 ,
V_36 -> V_15 -> V_165 + V_259 ) ) {
V_36 -> V_43 = V_44 ;
F_141 ( V_36 ) ;
if ( ! V_206 ) {
F_84 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
V_225 = 1 ;
} else {
F_84 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_191 ( V_118 ,
V_260 - V_259 ,
V_260 + 2 * V_259 ) ||
! F_191 ( V_118 ,
V_36 -> V_15 -> V_165 - V_259 ,
V_36 -> V_15 -> V_165 + 2 * V_259 ) ) {
V_36 -> V_43 = V_200 ;
F_163 ( V_36 ) ;
if ( V_36 -> V_198 < V_226 )
V_36 -> V_198 ++ ;
F_84 ( L_94 ,
V_11 -> V_15 -> V_16 ,
V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_206 )
V_225 = 1 ;
}
}
if ( F_80 ( V_36 -> V_15 ) )
F_174 ( V_11 , V_36 ) ;
}
if ( V_225 ) {
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
V_228:
if ( V_11 -> V_42 . V_164 )
F_69 ( V_11 -> V_88 , & V_11 -> V_258 , V_259 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_192 ( struct V_10 * V_11 , int V_259 )
{
struct V_36 * V_36 ;
int V_38 , V_219 = 0 ;
unsigned long V_260 ;
F_30 (bond, slave, i) {
V_36 -> V_221 = V_222 ;
if ( V_36 -> V_43 != V_44 ) {
if ( F_191 ( V_118 ,
F_193 ( V_11 , V_36 ) - V_259 ,
F_193 ( V_11 , V_36 ) + V_259 ) ) {
V_36 -> V_221 = V_44 ;
V_219 ++ ;
}
continue;
}
if ( F_191 ( V_118 ,
V_36 -> V_118 - V_259 ,
V_36 -> V_118 + 2 * V_259 ) )
continue;
if ( ! F_145 ( V_36 ) &&
! V_11 -> V_209 &&
! F_191 ( V_118 ,
F_193 ( V_11 , V_36 ) - V_259 ,
F_193 ( V_11 , V_36 ) + 3 * V_259 ) ) {
V_36 -> V_221 = V_200 ;
V_219 ++ ;
}
V_260 = F_190 ( V_36 -> V_15 ) ;
if ( F_145 ( V_36 ) &&
( ! F_191 ( V_118 ,
V_260 - V_259 ,
V_260 + 2 * V_259 ) ||
! F_191 ( V_118 ,
F_193 ( V_11 , V_36 ) - V_259 ,
F_193 ( V_11 , V_36 ) + 2 * V_259 ) ) ) {
V_36 -> V_221 = V_200 ;
V_219 ++ ;
}
}
return V_219 ;
}
static void F_194 ( struct V_10 * V_11 , int V_259 )
{
struct V_36 * V_36 ;
int V_38 ;
unsigned long V_260 ;
F_30 (bond, slave, i) {
switch ( V_36 -> V_221 ) {
case V_222 :
continue;
case V_44 :
V_260 = F_190 ( V_36 -> V_15 ) ;
if ( ( ! V_11 -> V_77 &&
F_191 ( V_118 ,
V_260 - V_259 ,
V_260 + V_259 ) ) ||
V_11 -> V_77 != V_36 ) {
V_36 -> V_43 = V_44 ;
if ( V_11 -> V_209 ) {
F_88 (
V_11 -> V_209 ) ;
V_11 -> V_209 = NULL ;
}
F_84 ( L_95 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_77 ||
( V_36 == V_11 -> V_104 ) )
goto V_225;
}
continue;
case V_200 :
if ( V_36 -> V_198 < V_226 )
V_36 -> V_198 ++ ;
V_36 -> V_43 = V_200 ;
F_88 ( V_36 ) ;
F_84 ( L_78 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
if ( V_36 == V_11 -> V_77 ) {
V_11 -> V_209 = NULL ;
goto V_225;
}
continue;
default:
F_32 ( L_96 ,
V_11 -> V_15 -> V_16 , V_36 -> V_221 ,
V_36 -> V_15 -> V_16 ) ;
continue;
}
V_225:
F_164 () ;
F_10 () ;
F_6 ( & V_11 -> V_123 ) ;
F_91 ( V_11 ) ;
F_8 ( & V_11 -> V_123 ) ;
F_16 () ;
}
F_39 ( V_11 ) ;
}
static void F_195 ( struct V_10 * V_11 )
{
struct V_36 * V_36 ;
int V_38 ;
F_67 ( & V_11 -> V_123 ) ;
if ( V_11 -> V_209 && V_11 -> V_77 )
F_84 ( L_97 ,
V_11 -> V_209 -> V_15 -> V_16 ,
V_11 -> V_77 -> V_15 -> V_16 ) ;
if ( V_11 -> V_77 ) {
F_174 ( V_11 , V_11 -> V_77 ) ;
F_70 ( & V_11 -> V_123 ) ;
return;
}
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_11 -> V_209 ) {
V_11 -> V_209 = V_11 -> V_112 ;
if ( ! V_11 -> V_209 )
return;
}
F_88 ( V_11 -> V_209 ) ;
F_79 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_80 ( V_36 -> V_15 ) ) {
V_36 -> V_43 = V_113 ;
F_89 ( V_36 ) ;
F_174 ( V_11 , V_36 ) ;
V_36 -> V_118 = V_118 ;
V_11 -> V_209 = V_36 ;
break;
}
if ( V_36 -> V_43 == V_44 ) {
V_36 -> V_43 = V_200 ;
if ( V_36 -> V_198 < V_226 )
V_36 -> V_198 ++ ;
F_88 ( V_36 ) ;
F_84 ( L_98 ,
V_11 -> V_15 -> V_16 , V_36 -> V_15 -> V_16 ) ;
}
}
}
void F_196 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_72 ( V_92 , struct V_10 ,
V_258 . V_92 ) ;
bool V_120 = false ;
int V_259 ;
F_67 ( & V_11 -> V_20 ) ;
V_259 = F_137 ( V_11 -> V_42 . V_164 ) ;
if ( V_11 -> V_40 == 0 )
goto V_228;
V_120 = F_81 ( V_11 ) ;
if ( F_192 ( V_11 , V_259 ) ) {
F_70 ( & V_11 -> V_20 ) ;
if ( ! F_166 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_259 = 1 ;
V_120 = false ;
goto V_228;
}
F_67 ( & V_11 -> V_20 ) ;
F_194 ( V_11 , V_259 ) ;
F_70 ( & V_11 -> V_20 ) ;
F_167 () ;
F_67 ( & V_11 -> V_20 ) ;
}
F_195 ( V_11 ) ;
V_228:
if ( V_11 -> V_42 . V_164 )
F_69 ( V_11 -> V_88 , & V_11 -> V_258 , V_259 ) ;
F_70 ( & V_11 -> V_20 ) ;
if ( V_120 ) {
if ( ! F_166 () ) {
F_67 ( & V_11 -> V_20 ) ;
V_11 -> V_115 ++ ;
F_70 ( & V_11 -> V_20 ) ;
return;
}
F_90 ( V_11 -> V_15 , V_125 ) ;
F_167 () ;
}
}
static int F_197 ( struct V_10 * V_11 )
{
F_198 ( V_11 ) ;
F_199 ( V_11 ) ;
F_200 ( V_11 ) ;
return V_261 ;
}
static int F_201 ( unsigned long V_262 ,
struct V_30 * V_34 )
{
struct V_10 * V_263 = F_29 ( V_34 ) ;
switch ( V_262 ) {
case V_264 :
return F_197 ( V_263 ) ;
case V_265 :
F_198 ( V_263 ) ;
break;
case V_266 :
F_199 ( V_263 ) ;
break;
default:
break;
}
return V_261 ;
}
static int F_202 ( unsigned long V_262 ,
struct V_30 * V_31 )
{
struct V_30 * V_34 = V_31 -> V_83 ;
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 = NULL ;
switch ( V_262 ) {
case V_265 :
if ( V_34 ) {
if ( V_11 -> V_156 )
F_154 ( V_34 , V_31 ) ;
else
F_148 ( V_34 , V_31 ) ;
}
break;
case V_267 :
case V_268 :
V_36 = F_26 ( V_11 , V_31 ) ;
if ( V_36 ) {
T_2 V_269 = V_36 -> V_48 ;
T_3 V_270 = V_36 -> V_50 ;
F_44 ( V_36 ) ;
if ( V_11 -> V_42 . V_1 == V_7 ) {
if ( V_269 != V_36 -> V_48 )
F_203 ( V_36 ) ;
if ( V_270 != V_36 -> V_50 )
F_204 ( V_36 ) ;
}
}
break;
case V_271 :
break;
case V_272 :
break;
case V_264 :
break;
case V_273 :
F_107 ( V_11 ) ;
break;
default:
break;
}
return V_261 ;
}
static int F_205 ( struct V_274 * V_275 ,
unsigned long V_262 , void * V_276 )
{
struct V_30 * V_277 = (struct V_30 * ) V_276 ;
F_3 ( L_99 ,
V_277 ? V_277 -> V_16 : L_10 ,
V_262 ) ;
if ( ! ( V_277 -> V_84 & V_196 ) )
return V_261 ;
if ( V_277 -> V_100 & V_278 ) {
F_3 ( L_100 ) ;
return F_201 ( V_262 , V_277 ) ;
}
if ( V_277 -> V_100 & V_172 ) {
F_3 ( L_101 ) ;
return F_202 ( V_262 , V_277 ) ;
}
return V_261 ;
}
static int F_206 ( struct V_28 * V_29 , int V_279 )
{
struct V_280 * V_168 = (struct V_280 * ) V_29 -> V_168 ;
struct V_281 * V_282 = F_207 ( V_29 ) ;
if ( V_29 -> V_248 == F_187 ( V_255 ) ) {
return ( ( F_208 ( V_282 -> V_283 ^ V_282 -> V_284 ) & 0xffff ) ^
( V_168 -> V_169 [ 5 ] ^ V_168 -> V_285 [ 5 ] ) ) % V_279 ;
}
return ( V_168 -> V_169 [ 5 ] ^ V_168 -> V_285 [ 5 ] ) % V_279 ;
}
static int F_209 ( struct V_28 * V_29 , int V_279 )
{
struct V_280 * V_168 = (struct V_280 * ) V_29 -> V_168 ;
struct V_281 * V_282 = F_207 ( V_29 ) ;
T_8 * V_286 = ( T_8 * ) ( ( T_2 * ) V_282 + V_282 -> V_287 ) ;
int V_288 = 0 ;
if ( V_29 -> V_248 == F_187 ( V_255 ) ) {
if ( ! F_210 ( V_282 ) &&
( V_282 -> V_248 == V_289 ||
V_282 -> V_248 == V_290 ) ) {
V_288 = F_211 ( ( * V_286 ^ * ( V_286 + 1 ) ) ) ;
}
return ( V_288 ^
( ( F_208 ( V_282 -> V_283 ^ V_282 -> V_284 ) ) & 0xffff ) ) % V_279 ;
}
return ( V_168 -> V_169 [ 5 ] ^ V_168 -> V_285 [ 5 ] ) % V_279 ;
}
static int F_212 ( struct V_28 * V_29 , int V_279 )
{
struct V_280 * V_168 = (struct V_280 * ) V_29 -> V_168 ;
return ( V_168 -> V_169 [ 5 ] ^ V_168 -> V_285 [ 5 ] ) % V_279 ;
}
static int F_213 ( struct V_30 * V_34 )
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
F_214 ( & V_11 -> V_89 , F_71 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_215 ( V_11 , ( V_11 -> V_42 . V_1 == V_9 ) ) ) {
return - V_18 ;
}
F_214 ( & V_11 -> V_291 , V_292 ) ;
F_69 ( V_11 -> V_88 , & V_11 -> V_291 , 0 ) ;
}
if ( V_11 -> V_42 . V_119 ) {
F_214 ( & V_11 -> V_227 , F_165 ) ;
F_69 ( V_11 -> V_88 , & V_11 -> V_227 , 0 ) ;
}
if ( V_11 -> V_42 . V_164 ) {
if ( V_11 -> V_42 . V_1 == V_4 )
F_214 ( & V_11 -> V_258 ,
F_196 ) ;
else
F_214 ( & V_11 -> V_258 ,
F_189 ) ;
F_69 ( V_11 -> V_88 , & V_11 -> V_258 , 0 ) ;
if ( V_11 -> V_42 . V_257 )
V_11 -> F_113 = F_181 ;
}
if ( V_11 -> V_42 . V_1 == V_7 ) {
F_214 ( & V_11 -> V_293 , V_294 ) ;
F_69 ( V_11 -> V_88 , & V_11 -> V_293 , 0 ) ;
V_11 -> F_113 = V_295 ;
F_216 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_217 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_115 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_42 . V_119 ) {
F_218 ( & V_11 -> V_227 ) ;
}
if ( V_11 -> V_42 . V_164 ) {
F_218 ( & V_11 -> V_258 ) ;
}
switch ( V_11 -> V_42 . V_1 ) {
case V_7 :
F_218 ( & V_11 -> V_293 ) ;
break;
case V_8 :
case V_9 :
F_218 ( & V_11 -> V_291 ) ;
break;
default:
break;
}
if ( F_219 ( & V_11 -> V_89 ) )
F_218 ( & V_11 -> V_89 ) ;
if ( F_13 ( V_11 ) ) {
F_220 ( V_11 ) ;
}
V_11 -> F_113 = NULL ;
return 0 ;
}
static struct V_296 * F_221 ( struct V_30 * V_34 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_296 V_298 ;
struct V_36 * V_36 ;
int V_38 ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
F_222 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
const struct V_296 * V_299 =
F_223 ( V_36 -> V_15 , & V_298 ) ;
V_297 -> V_300 += V_299 -> V_300 ;
V_297 -> V_301 += V_299 -> V_301 ;
V_297 -> V_302 += V_299 -> V_302 ;
V_297 -> V_303 += V_299 -> V_303 ;
V_297 -> V_304 += V_299 -> V_304 ;
V_297 -> V_305 += V_299 -> V_305 ;
V_297 -> V_306 += V_299 -> V_306 ;
V_297 -> V_307 += V_299 -> V_307 ;
V_297 -> V_308 += V_299 -> V_308 ;
V_297 -> V_309 += V_299 -> V_309 ;
V_297 -> V_310 += V_299 -> V_310 ;
V_297 -> V_311 += V_299 -> V_311 ;
V_297 -> V_312 += V_299 -> V_312 ;
V_297 -> V_313 += V_299 -> V_313 ;
V_297 -> V_314 += V_299 -> V_314 ;
V_297 -> V_315 += V_299 -> V_315 ;
V_297 -> V_316 += V_299 -> V_316 ;
V_297 -> V_317 += V_299 -> V_317 ;
V_297 -> V_318 += V_299 -> V_318 ;
V_297 -> V_319 += V_299 -> V_319 ;
V_297 -> V_320 += V_299 -> V_320 ;
}
F_224 ( & V_11 -> V_20 ) ;
return V_297 ;
}
static int F_225 ( struct V_30 * V_34 , struct V_59 * V_60 , int V_321 )
{
struct V_30 * V_31 = NULL ;
struct V_211 V_322 ;
struct V_211 T_9 * V_323 = NULL ;
struct V_215 V_324 ;
struct V_215 T_9 * V_325 = NULL ;
struct V_61 * V_62 = NULL ;
int V_21 = 0 ;
F_3 ( L_102 , V_34 -> V_16 , V_321 ) ;
switch ( V_321 ) {
case V_70 :
V_62 = F_50 ( V_60 ) ;
if ( ! V_62 )
return - V_181 ;
V_62 -> V_326 = 0 ;
case V_73 :
V_62 = F_50 ( V_60 ) ;
if ( ! V_62 )
return - V_181 ;
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
case V_327 :
case V_328 :
V_323 = (struct V_211 T_9 * ) V_60 -> V_329 ;
if ( F_226 ( & V_322 , V_323 , sizeof( V_211 ) ) )
return - V_330 ;
V_21 = F_158 ( V_34 , & V_322 ) ;
if ( V_21 == 0 &&
F_227 ( V_323 , & V_322 , sizeof( V_211 ) ) )
return - V_330 ;
return V_21 ;
case V_331 :
case V_332 :
V_325 = (struct V_215 T_9 * ) V_60 -> V_329 ;
if ( F_226 ( & V_324 , V_325 , sizeof( V_215 ) ) )
return - V_330 ;
V_21 = F_159 ( V_34 , & V_324 ) ;
if ( V_21 == 0 &&
F_227 ( V_325 , & V_324 , sizeof( V_215 ) ) )
return - V_330 ;
return V_21 ;
default:
break;
}
if ( ! F_228 ( V_333 ) )
return - V_174 ;
V_31 = F_229 ( F_176 ( V_34 ) , V_60 -> V_334 ) ;
F_3 ( L_103 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_104 , V_31 -> V_16 ) ;
switch ( V_321 ) {
case V_335 :
case V_336 :
V_21 = F_122 ( V_34 , V_31 ) ;
break;
case V_337 :
case V_338 :
V_21 = F_148 ( V_34 , V_31 ) ;
break;
case V_339 :
case V_340 :
V_21 = F_104 ( V_34 , V_31 ) ;
break;
case V_341 :
case V_342 :
V_21 = F_157 ( V_34 , V_31 ) ;
break;
default:
V_21 = - V_184 ;
}
F_230 ( V_31 ) ;
}
return V_21 ;
}
static bool F_231 ( unsigned char * V_78 ,
struct V_343 * V_344 ,
int V_345 )
{
struct V_93 * V_94 ;
F_232 (ha, list)
if ( ! memcmp ( V_94 -> V_78 , V_78 , V_345 ) )
return true ;
return false ;
}
static void F_233 ( struct V_30 * V_34 , int V_346 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_346 & V_101 )
F_52 ( V_11 ,
V_34 -> V_100 & V_101 ? 1 : - 1 ) ;
if ( V_346 & V_102 )
F_55 ( V_11 ,
V_34 -> V_100 & V_102 ? 1 : - 1 ) ;
}
static void F_234 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_93 * V_94 ;
bool V_347 ;
F_67 ( & V_11 -> V_20 ) ;
F_74 (ha, bond_dev) {
V_347 = F_231 ( V_94 -> V_78 , & V_11 -> V_348 ,
V_34 -> V_139 ) ;
if ( ! V_347 )
F_57 ( V_11 , V_94 -> V_78 ) ;
}
F_232 (ha, &bond->mc_list) {
V_347 = F_231 ( V_94 -> V_78 , & V_34 -> V_349 ,
V_34 -> V_139 ) ;
if ( ! V_347 )
F_59 ( V_11 , V_94 -> V_78 ) ;
}
F_235 ( & V_11 -> V_348 ) ;
F_236 ( & V_11 -> V_348 , & V_34 -> V_349 ,
V_34 -> V_139 , V_350 ) ;
F_70 ( & V_11 -> V_20 ) ;
}
static int F_237 ( struct V_351 * V_352 )
{
struct V_10 * V_11 = F_29 ( V_352 -> V_15 ) ;
struct V_36 * V_36 = V_11 -> V_112 ;
const struct V_56 * V_57 ;
struct V_353 V_354 ;
int V_161 ;
if ( ! V_36 )
return 0 ;
V_57 = V_36 -> V_15 -> V_58 ;
if ( ! V_57 -> V_355 )
return 0 ;
V_354 . V_356 = NULL ;
V_354 . V_357 = NULL ;
V_161 = V_57 -> V_355 ( V_36 -> V_15 , & V_354 ) ;
if ( V_161 )
return V_161 ;
V_352 -> V_354 -> V_357 = V_354 . V_357 ;
if ( ! V_354 . V_356 )
return 0 ;
return V_354 . V_356 ( V_352 ) ;
}
static int F_238 ( struct V_30 * V_15 ,
struct V_353 * V_354 )
{
V_354 -> V_356 = F_237 ;
return 0 ;
}
static int F_239 ( struct V_30 * V_34 , int V_358 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_37 ;
int V_21 = 0 ;
int V_38 ;
F_3 ( L_105 , V_11 ,
( V_34 ? V_34 -> V_16 : L_10 ) , V_358 ) ;
F_30 (bond, slave, i) {
F_3 ( L_106 ,
V_36 ,
V_36 -> V_27 ,
V_36 -> V_15 -> V_58 -> V_359 ) ;
V_21 = F_130 ( V_36 -> V_15 , V_358 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
}
V_34 -> V_188 = V_358 ;
return 0 ;
V_39:
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_360 ;
V_360 = F_130 ( V_36 -> V_15 , V_34 -> V_188 ) ;
if ( V_360 ) {
F_3 ( L_108 ,
V_360 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_240 ( struct V_30 * V_34 , void * V_78 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_170 * V_361 = V_78 , V_362 ;
struct V_36 * V_36 , * V_37 ;
int V_21 = 0 ;
int V_38 ;
if ( V_11 -> V_42 . V_1 == V_9 )
return F_241 ( V_34 , V_78 ) ;
F_3 ( L_109 ,
V_11 , V_34 ? V_34 -> V_16 : L_10 ) ;
if ( V_11 -> V_42 . V_121 == V_183 )
return 0 ;
if ( ! F_242 ( V_361 -> V_191 ) )
return - V_363 ;
F_30 (bond, slave, i) {
const struct V_56 * V_57 = V_36 -> V_15 -> V_58 ;
F_3 ( L_110 , V_36 , V_36 -> V_15 -> V_16 ) ;
if ( V_57 -> V_182 == NULL ) {
V_21 = - V_184 ;
F_3 ( L_111 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
V_21 = F_131 ( V_36 -> V_15 , V_78 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_36 -> V_15 -> V_16 ) ;
goto V_39;
}
}
memcpy ( V_34 -> V_140 , V_361 -> V_191 , V_34 -> V_139 ) ;
return 0 ;
V_39:
memcpy ( V_362 . V_191 , V_34 -> V_140 , V_34 -> V_139 ) ;
V_362 . V_192 = V_34 -> type ;
V_37 = V_36 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_360 ;
V_360 = F_131 ( V_36 -> V_15 , & V_362 ) ;
if ( V_360 ) {
F_3 ( L_108 ,
V_360 , V_36 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_243 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_364 ;
int V_38 , V_365 , V_21 = 1 ;
struct V_281 * V_282 = F_207 ( V_29 ) ;
if ( ( V_282 -> V_248 == V_366 ) &&
( V_29 -> V_248 == F_187 ( V_255 ) ) ) {
F_67 ( & V_11 -> V_123 ) ;
V_36 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_36 )
goto V_23;
} else {
V_365 = V_11 -> V_367 ++ % V_11 -> V_40 ;
F_30 (bond, slave, i) {
V_365 -- ;
if ( V_365 < 0 )
break;
}
}
V_364 = V_36 ;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_145 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_120 ( V_29 ) ;
}
return V_368 ;
}
static int F_244 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_21 = 1 ;
F_67 ( & V_11 -> V_123 ) ;
if ( V_11 -> V_77 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_77 -> V_15 ) ;
F_70 ( & V_11 -> V_123 ) ;
if ( V_21 )
F_120 ( V_29 ) ;
return V_368 ;
}
static int F_245 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_364 ;
int V_365 ;
int V_38 ;
int V_21 = 1 ;
V_365 = V_11 -> V_369 ( V_29 , V_11 -> V_40 ) ;
F_30 (bond, slave, i) {
V_365 -- ;
if ( V_365 < 0 )
break;
}
V_364 = V_36 ;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_145 ( V_36 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_120 ( V_29 ) ;
}
return V_368 ;
}
static int F_246 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_36 * V_36 , * V_364 ;
struct V_30 * V_370 = NULL ;
int V_38 ;
int V_21 = 1 ;
F_67 ( & V_11 -> V_123 ) ;
V_364 = V_11 -> V_77 ;
F_70 ( & V_11 -> V_123 ) ;
if ( ! V_364 )
goto V_23;
F_79 (bond, slave, i, start_at) {
if ( F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) &&
F_145 ( V_36 ) ) {
if ( V_370 ) {
struct V_28 * V_371 = F_247 ( V_29 , V_132 ) ;
if ( ! V_371 ) {
F_32 ( L_112 ,
V_34 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_371 , V_370 ) ;
if ( V_21 ) {
F_120 ( V_371 ) ;
continue;
}
}
V_370 = V_36 -> V_15 ;
}
}
if ( V_370 )
V_21 = F_20 ( V_11 , V_29 , V_370 ) ;
V_23:
if ( V_21 )
F_120 ( V_29 ) ;
return V_368 ;
}
static void F_248 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_42 . V_372 ) {
case V_373 :
V_11 -> V_369 = F_206 ;
break;
case V_374 :
V_11 -> V_369 = F_209 ;
break;
case V_375 :
default:
V_11 -> V_369 = F_212 ;
break;
}
}
static inline int F_249 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_38 , V_21 = 1 ;
struct V_36 * V_36 = NULL ;
struct V_36 * V_376 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_30 (bond, check_slave, i) {
if ( V_376 -> V_186 == V_29 -> V_32 ) {
V_36 = V_376 ;
break;
}
}
if ( V_36 && V_36 -> V_186 && F_80 ( V_36 -> V_15 ) &&
( V_36 -> V_43 == V_44 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_36 -> V_15 ) ;
}
return V_21 ;
}
static T_10 F_250 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_10 V_377 = F_251 ( V_29 ) ? F_252 ( V_29 ) : 0 ;
F_22 ( V_29 ) -> V_33 = V_29 -> V_32 ;
if ( F_23 ( V_377 >= V_15 -> V_378 ) ) {
do {
V_377 -= V_15 -> V_378 ;
} while ( V_377 >= V_15 -> V_378 );
}
return V_377 ;
}
static T_11 F_253 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
if ( F_254 ( V_11 -> V_42 . V_1 ) ) {
if ( ! F_249 ( V_11 , V_29 ) )
return V_368 ;
}
switch ( V_11 -> V_42 . V_1 ) {
case V_3 :
return F_243 ( V_29 , V_15 ) ;
case V_4 :
return F_244 ( V_29 , V_15 ) ;
case V_5 :
return F_245 ( V_29 , V_15 ) ;
case V_6 :
return F_246 ( V_29 , V_15 ) ;
case V_7 :
return F_255 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_256 ( V_29 , V_15 ) ;
default:
F_32 ( L_113 ,
V_15 -> V_16 , V_11 -> V_42 . V_1 ) ;
F_257 ( 1 ) ;
F_120 ( V_29 ) ;
return V_368 ;
}
}
static T_11 F_258 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_11 V_161 = V_368 ;
if ( F_259 ( V_15 ) )
return V_379 ;
F_67 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_40 )
V_161 = F_253 ( V_29 , V_15 ) ;
else
F_120 ( V_29 ) ;
F_70 ( & V_11 -> V_20 ) ;
return V_161 ;
}
void F_260 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_34 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_248 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_248 ( V_11 ) ;
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
static void F_261 ( struct V_30 * V_34 ,
struct V_380 * V_381 )
{
strncpy ( V_381 -> V_382 , V_383 , 32 ) ;
strncpy ( V_381 -> V_384 , V_385 , 32 ) ;
snprintf ( V_381 -> V_386 , 32 , L_114 , V_387 ) ;
}
static void F_262 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_11 -> V_88 )
F_263 ( V_11 -> V_88 ) ;
F_264 ( V_34 ) ;
}
static void F_265 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_266 ( & V_11 -> V_20 ) ;
F_266 ( & V_11 -> V_123 ) ;
V_11 -> V_42 = V_388 ;
V_11 -> V_15 = V_34 ;
F_5 ( & V_11 -> V_19 ) ;
F_127 ( V_34 ) ;
V_34 -> V_58 = & V_389 ;
V_34 -> V_65 = & V_390 ;
F_260 ( V_11 , V_11 -> V_42 . V_1 ) ;
V_34 -> V_391 = F_262 ;
V_34 -> V_392 = 0 ;
V_34 -> V_100 |= V_278 | V_393 ;
V_34 -> V_84 |= V_196 ;
V_34 -> V_84 &= ~ ( V_151 | V_179 ) ;
V_34 -> V_141 |= V_143 ;
V_34 -> V_141 |= V_394 ;
V_34 -> V_395 = V_147 |
V_396 |
V_397 |
V_398 ;
V_34 -> V_395 &= ~ ( V_399 & ~ V_400 ) ;
V_34 -> V_141 |= V_34 -> V_395 ;
}
static void F_267 ( struct V_10 * V_11 )
{
if ( V_11 -> V_42 . V_119 && F_219 ( & V_11 -> V_227 ) )
F_218 ( & V_11 -> V_227 ) ;
if ( V_11 -> V_42 . V_164 && F_219 ( & V_11 -> V_258 ) )
F_218 ( & V_11 -> V_258 ) ;
if ( V_11 -> V_42 . V_1 == V_9 &&
F_219 ( & V_11 -> V_291 ) )
F_218 ( & V_11 -> V_291 ) ;
if ( V_11 -> V_42 . V_1 == V_7 &&
F_219 ( & V_11 -> V_293 ) )
F_218 ( & V_11 -> V_293 ) ;
if ( F_219 ( & V_11 -> V_89 ) )
F_218 ( & V_11 -> V_89 ) ;
}
static void F_268 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_13 * V_14 , * V_401 ;
F_101 ( V_34 ) ;
F_156 ( V_34 ) ;
F_12 ( & V_11 -> V_402 ) ;
F_267 ( V_11 ) ;
F_269 ( V_11 ) ;
F_235 ( & V_11 -> V_348 ) ;
F_270 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_271 ( const char * V_403 , const struct V_404 * V_405 )
{
int V_406 = - 1 , V_38 , V_128 ;
char * V_407 , V_408 [ V_409 + 1 ] = { 0 , } ;
for ( V_407 = ( char * ) V_403 ; * V_407 ; V_407 ++ )
if ( ! ( isdigit ( * V_407 ) || isspace ( * V_407 ) ) )
break;
if ( * V_407 )
V_128 = sscanf ( V_403 , L_115 , V_408 ) ;
else
V_128 = sscanf ( V_403 , L_114 , & V_406 ) ;
if ( ! V_128 )
return - 1 ;
for ( V_38 = 0 ; V_405 [ V_38 ] . V_410 ; V_38 ++ ) {
if ( V_406 == V_405 [ V_38 ] . V_1 )
return V_405 [ V_38 ] . V_1 ;
if ( strcmp ( V_408 , V_405 [ V_38 ] . V_410 ) == 0 )
return V_405 [ V_38 ] . V_1 ;
}
return - 1 ;
}
static int F_272 ( struct V_411 * V_42 )
{
int V_412 , V_413 , V_414 ;
if ( V_1 ) {
V_213 = F_271 ( V_1 , V_415 ) ;
if ( V_213 == - 1 ) {
F_32 ( L_116 ,
V_1 == NULL ? L_18 : V_1 ) ;
return - V_181 ;
}
}
if ( V_369 ) {
if ( ( V_213 != V_5 ) &&
( V_213 != V_7 ) ) {
F_84 ( L_117 ,
F_1 ( V_213 ) ) ;
} else {
V_416 = F_271 ( V_369 ,
V_417 ) ;
if ( V_416 == - 1 ) {
F_32 ( L_118 ,
V_369 == NULL ? L_18 :
V_369 ) ;
return - V_181 ;
}
}
}
if ( V_418 ) {
if ( V_213 != V_7 ) {
F_84 ( L_119 ,
F_1 ( V_213 ) ) ;
} else {
V_419 = F_271 ( V_418 , V_420 ) ;
if ( V_419 == - 1 ) {
F_32 ( L_120 ,
V_418 == NULL ? L_18 : V_418 ) ;
return - V_181 ;
}
}
}
if ( V_421 ) {
V_42 -> V_421 = F_271 ( V_421 , V_422 ) ;
if ( V_42 -> V_421 == - 1 ) {
F_32 ( L_121 ,
V_421 == NULL ? L_18 : V_421 ) ;
return - V_181 ;
}
if ( V_213 != V_7 ) {
F_37 ( L_122 ) ;
}
} else {
V_42 -> V_421 = V_423 ;
}
if ( V_424 < 0 ) {
F_37 ( L_123 ,
V_424 , 0 , V_425 , V_426 ) ;
V_424 = V_426 ;
}
if ( V_119 < 0 ) {
F_37 ( L_124 ,
V_119 , V_425 , V_427 ) ;
V_119 = V_427 ;
}
if ( V_111 < 0 ) {
F_37 ( L_125 ,
V_111 , V_425 ) ;
V_111 = 0 ;
}
if ( V_224 < 0 ) {
F_37 ( L_126 ,
V_224 , V_425 ) ;
V_224 = 0 ;
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
if ( V_213 == V_7 ) {
if ( ! V_119 ) {
F_37 ( L_129 ) ;
F_37 ( L_130 ) ;
V_119 = 100 ;
}
}
if ( V_428 < 1 || V_428 > 255 ) {
F_37 ( L_131
L_132 ,
V_428 , V_429 ) ;
V_428 = V_429 ;
}
if ( ( V_430 != 0 ) && ( V_430 != 1 ) ) {
F_37 ( L_133
L_134
L_135 , V_430 ) ;
V_430 = 0 ;
}
if ( V_126 < 0 || V_126 > 255 ) {
F_37 ( L_136
L_137 ,
V_126 , V_431 ) ;
V_126 = V_431 ;
}
if ( ( V_213 == V_8 ) ||
( V_213 == V_9 ) ) {
if ( ! V_119 ) {
F_37 ( L_138 ) ;
F_37 ( L_130 ) ;
V_119 = 100 ;
}
}
if ( V_213 == V_9 ) {
F_273 ( L_139 ,
V_111 ) ;
}
if ( ! V_119 ) {
if ( V_111 || V_224 ) {
F_37 ( L_140 ,
V_111 , V_224 ) ;
}
} else {
if ( V_164 ) {
F_37 ( L_141 ,
V_119 , V_164 ) ;
V_164 = 0 ;
}
if ( ( V_111 % V_119 ) != 0 ) {
F_37 ( L_142 ,
V_111 , V_119 ,
( V_111 / V_119 ) * V_119 ) ;
}
V_111 /= V_119 ;
if ( ( V_224 % V_119 ) != 0 ) {
F_37 ( L_143 ,
V_224 , V_119 ,
( V_224 / V_119 ) * V_119 ) ;
}
V_224 /= V_119 ;
}
if ( V_164 < 0 ) {
F_37 ( L_144 ,
V_164 , V_425 , V_432 ) ;
V_164 = V_432 ;
}
for ( V_433 = 0 ;
( V_433 < V_238 ) && V_434 [ V_433 ] ;
V_433 ++ ) {
if ( ! isdigit ( V_434 [ V_433 ] [ 0 ] ) ) {
F_37 ( L_145 ,
V_434 [ V_433 ] ) ;
V_164 = 0 ;
} else {
T_7 V_229 = F_274 ( V_434 [ V_433 ] ) ;
V_435 [ V_433 ] = V_229 ;
}
}
if ( V_164 && ! V_433 ) {
F_37 ( L_146 ,
V_164 ) ;
V_164 = 0 ;
}
if ( V_257 ) {
if ( V_213 != V_4 ) {
F_32 ( L_147 ) ;
return - V_181 ;
}
if ( ! V_164 ) {
F_32 ( L_148 ) ;
return - V_181 ;
}
V_412 = F_271 ( V_257 ,
V_436 ) ;
if ( V_412 == - 1 ) {
F_32 ( L_149 ,
V_257 == NULL ? L_18 : V_257 ) ;
return - V_181 ;
}
} else
V_412 = 0 ;
if ( V_119 ) {
F_84 ( L_150 , V_119 ) ;
} else if ( V_164 ) {
int V_38 ;
F_84 ( L_151 ,
V_164 ,
V_436 [ V_412 ] . V_410 ,
V_433 ) ;
for ( V_38 = 0 ; V_38 < V_433 ; V_38 ++ )
F_84 ( L_152 , V_434 [ V_38 ] ) ;
F_84 ( L_153 ) ;
} else if ( V_424 ) {
F_3 ( L_154 ) ;
}
if ( V_201 && ! F_53 ( V_213 ) ) {
F_37 ( L_155 ,
V_201 , F_1 ( V_213 ) ) ;
V_201 = NULL ;
}
if ( V_201 && V_106 ) {
V_414 = F_271 ( V_106 ,
V_437 ) ;
if ( V_414 == - 1 ) {
F_32 ( L_156 ,
V_106 ==
NULL ? L_18 : V_106 ) ;
return - V_181 ;
}
} else {
V_414 = V_438 ;
}
if ( V_121 ) {
V_413 = F_271 ( V_121 ,
V_439 ) ;
if ( V_413 == - 1 ) {
F_32 ( L_157 ,
V_257 == NULL ? L_18 : V_257 ) ;
return - V_181 ;
}
if ( V_213 != V_4 )
F_37 ( L_158 ) ;
} else {
V_413 = V_440 ;
}
V_42 -> V_1 = V_213 ;
V_42 -> V_372 = V_416 ;
V_42 -> V_119 = V_119 ;
V_42 -> V_122 = V_122 ;
V_42 -> V_164 = V_164 ;
V_42 -> V_257 = V_412 ;
V_42 -> V_111 = V_111 ;
V_42 -> V_224 = V_224 ;
V_42 -> V_63 = V_63 ;
V_42 -> V_419 = V_419 ;
V_42 -> V_201 [ 0 ] = 0 ;
V_42 -> V_106 = V_414 ;
V_42 -> V_121 = V_413 ;
V_42 -> V_428 = V_428 ;
V_42 -> V_430 = V_430 ;
V_42 -> V_126 = V_126 ;
V_42 -> V_441 = V_441 ;
if ( V_201 ) {
strncpy ( V_42 -> V_201 , V_201 , V_69 ) ;
V_42 -> V_201 [ V_69 - 1 ] = 0 ;
}
memcpy ( V_42 -> V_235 , V_435 , sizeof( V_435 ) ) ;
return 0 ;
}
static void F_275 ( struct V_30 * V_15 ,
struct V_442 * V_377 ,
void * V_443 )
{
F_276 ( & V_377 -> V_444 ,
& V_445 ) ;
}
static void F_277 ( struct V_30 * V_15 )
{
F_276 ( & V_15 -> V_446 ,
& V_447 ) ;
F_278 ( V_15 , F_275 , NULL ) ;
}
static int F_279 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_448 * V_449 = F_280 ( F_176 ( V_34 ) , V_450 ) ;
struct V_451 * V_452 = & ( F_281 ( V_11 ) ) ;
F_3 ( L_159 , V_34 -> V_16 ) ;
F_282 ( & ( V_452 -> V_453 ) ) ;
F_282 ( & ( V_452 -> V_454 ) ) ;
V_11 -> V_88 = F_283 ( V_34 -> V_16 ) ;
if ( ! V_11 -> V_88 )
return - V_18 ;
F_277 ( V_34 ) ;
F_7 ( & V_11 -> V_402 , & V_449 -> V_455 ) ;
F_284 ( V_11 ) ;
F_285 ( V_11 ) ;
F_286 ( & V_11 -> V_348 ) ;
return 0 ;
}
static int F_287 ( struct V_456 * V_457 [] , struct V_456 * V_168 [] )
{
if ( V_457 [ V_458 ] ) {
if ( F_288 ( V_457 [ V_458 ] ) != V_96 )
return - V_181 ;
if ( ! F_242 ( F_289 ( V_457 [ V_458 ] ) ) )
return - V_363 ;
}
return 0 ;
}
static unsigned int F_290 ( void )
{
return V_428 ;
}
int F_291 ( struct V_459 * V_459 , const char * V_16 )
{
struct V_30 * V_34 ;
int V_21 ;
F_292 () ;
V_34 = F_293 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_160 ,
F_265 , V_428 ) ;
if ( ! V_34 ) {
F_32 ( L_161 , V_16 ) ;
F_167 () ;
return - V_18 ;
}
F_294 ( V_34 , V_459 ) ;
V_34 -> V_460 = & V_461 ;
V_21 = F_295 ( V_34 ) ;
F_43 ( V_34 ) ;
F_167 () ;
if ( V_21 < 0 )
F_262 ( V_34 ) ;
return V_21 ;
}
static int T_12 F_296 ( struct V_459 * V_459 )
{
struct V_448 * V_449 = F_280 ( V_459 , V_450 ) ;
V_449 -> V_459 = V_459 ;
F_5 ( & V_449 -> V_455 ) ;
F_297 ( V_449 ) ;
F_298 ( V_449 ) ;
return 0 ;
}
static void T_13 F_299 ( struct V_459 * V_459 )
{
struct V_448 * V_449 = F_280 ( V_459 , V_450 ) ;
F_300 ( V_449 ) ;
F_301 ( V_449 ) ;
}
static int T_14 F_302 ( void )
{
int V_38 ;
int V_21 ;
F_84 ( L_162 , V_462 ) ;
V_21 = F_272 ( & V_388 ) ;
if ( V_21 )
goto V_23;
V_21 = F_303 ( & V_463 ) ;
if ( V_21 )
goto V_23;
V_21 = F_304 ( & V_461 ) ;
if ( V_21 )
goto V_464;
F_305 () ;
for ( V_38 = 0 ; V_38 < V_424 ; V_38 ++ ) {
V_21 = F_291 ( & V_465 , NULL ) ;
if ( V_21 )
goto V_76;
}
F_306 ( & V_466 ) ;
V_23:
return V_21 ;
V_76:
F_307 ( & V_461 ) ;
V_464:
F_308 ( & V_463 ) ;
goto V_23;
}
static void T_15 F_309 ( void )
{
F_310 ( & V_466 ) ;
F_311 () ;
F_307 ( & V_461 ) ;
F_308 ( & V_463 ) ;
#ifdef F_142
F_312 ( F_313 ( & V_467 ) ) ;
#endif
}
