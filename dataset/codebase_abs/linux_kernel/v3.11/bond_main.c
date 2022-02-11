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
static void F_58 ( struct V_30 * V_15 )
{
struct V_80 * V_81 ;
V_81 = F_59 ( V_15 ) ;
if ( V_81 )
F_60 ( V_81 ) ;
}
static void F_61 ( struct V_10 * V_11 )
{
struct V_30 * V_34 , * V_82 , * V_83 ;
struct V_13 * V_14 ;
F_62 ( & V_11 -> V_20 ) ;
F_63 () ;
V_34 = V_11 -> V_15 ;
F_58 ( V_34 ) ;
V_83 = F_64 ( V_34 ) ;
if ( V_83 && V_83 -> V_84 & V_85 )
F_58 ( V_83 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_82 = F_65 ( V_34 , F_37 ( V_41 ) ,
V_14 -> V_12 ) ;
if ( V_82 )
F_58 ( V_82 ) ;
}
F_66 () ;
F_6 ( & V_11 -> V_86 ) ;
if ( V_11 -> V_87 > 1 ) {
V_11 -> V_87 -- ;
F_67 ( V_11 -> V_88 , & V_11 -> V_89 , V_90 / 5 ) ;
}
F_8 ( & V_11 -> V_86 ) ;
F_68 ( & V_11 -> V_20 ) ;
}
static void F_69 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_70 ( V_92 , struct V_10 ,
V_89 . V_92 ) ;
F_61 ( V_11 ) ;
}
static void F_71 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_72 ( V_31 , V_34 ) ;
F_73 ( V_31 , V_34 ) ;
if ( V_11 -> V_44 . V_1 == V_7 ) {
T_4 V_93 [ V_94 ] = V_95 ;
F_74 ( V_31 , V_93 ) ;
}
}
static void F_75 ( struct V_10 * V_11 , struct V_37 * V_96 ,
struct V_37 * V_97 )
{
if ( V_97 ) {
if ( V_11 -> V_15 -> V_98 & V_99 )
F_55 ( V_97 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_98 & V_100 )
F_57 ( V_97 -> V_15 , - 1 ) ;
F_71 ( V_11 -> V_15 , V_97 -> V_15 ) ;
}
if ( V_96 ) {
if ( V_11 -> V_15 -> V_98 & V_99 )
F_55 ( V_96 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_98 & V_100 )
F_57 ( V_96 -> V_15 , 1 ) ;
F_76 ( V_11 -> V_15 ) ;
F_77 ( V_96 -> V_15 , V_11 -> V_15 ) ;
F_78 ( V_96 -> V_15 , V_11 -> V_15 ) ;
F_79 ( V_11 -> V_15 ) ;
}
}
static void F_80 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_3 ( L_17 ,
V_34 , V_31 , V_31 -> V_101 ) ;
memcpy ( V_34 -> V_102 , V_31 -> V_102 , V_31 -> V_101 ) ;
V_34 -> V_103 = V_104 ;
F_81 ( V_105 , V_34 ) ;
}
static void F_82 ( struct V_10 * V_11 ,
struct V_37 * V_96 ,
struct V_37 * V_97 )
__releases( &bond->curr_slave_lock
static bool F_83 ( struct V_10 * V_11 )
{
struct V_37 * V_106 = V_11 -> V_107 ;
struct V_37 * V_24 = V_11 -> V_79 ;
if ( ! V_106 || ! V_24 || V_24 -> V_45 != V_46 )
return true ;
if ( V_11 -> V_108 ) {
V_11 -> V_108 = false ;
return true ;
}
if ( V_11 -> V_44 . V_109 == V_110 &&
( V_106 -> V_50 < V_24 -> V_50 ||
( V_106 -> V_50 == V_24 -> V_50 && V_106 -> V_52 <= V_24 -> V_52 ) ) )
return false ;
if ( V_11 -> V_44 . V_109 == V_111 )
return false ;
return true ;
}
static struct V_37 * F_84 ( struct V_10 * V_11 )
{
struct V_37 * V_96 , * V_97 ;
struct V_37 * V_112 = NULL ;
int V_113 = V_11 -> V_44 . V_114 ;
int V_39 ;
V_96 = V_11 -> V_79 ;
if ( ! V_96 ) {
if ( V_11 -> V_42 > 0 )
V_96 = V_11 -> V_115 ;
else
return NULL ;
}
if ( ( V_11 -> V_107 ) &&
V_11 -> V_107 -> V_45 == V_46 &&
F_83 ( V_11 ) ) {
V_96 = V_11 -> V_107 ;
}
V_97 = V_96 ;
F_85 (bond, new_active, i, old_active) {
if ( V_96 -> V_45 == V_46 ) {
return V_96 ;
} else if ( V_96 -> V_45 == V_116 &&
F_86 ( V_96 -> V_15 ) ) {
if ( V_96 -> V_117 < V_113 ) {
V_113 = V_96 -> V_117 ;
V_112 = V_96 ;
}
}
}
return V_112 ;
}
static bool F_87 ( struct V_10 * V_11 )
{
struct V_37 * V_37 = V_11 -> V_79 ;
F_3 ( L_18 ,
V_11 -> V_15 -> V_16 , V_37 ? V_37 -> V_15 -> V_16 : L_19 ) ;
if ( ! V_37 || ! V_11 -> V_118 ||
F_88 ( V_119 , & V_37 -> V_15 -> V_120 ) )
return false ;
V_11 -> V_118 -- ;
return true ;
}
void F_89 ( struct V_10 * V_11 , struct V_37 * V_96 )
{
struct V_37 * V_97 = V_11 -> V_79 ;
if ( V_97 == V_96 )
return;
if ( V_96 ) {
V_96 -> V_121 = V_121 ;
if ( V_96 -> V_45 == V_116 ) {
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
F_90 ( L_20 ,
V_11 -> V_15 -> V_16 , V_96 -> V_15 -> V_16 ,
( V_11 -> V_44 . V_114 - V_96 -> V_117 ) * V_11 -> V_44 . V_122 ) ;
}
V_96 -> V_117 = 0 ;
V_96 -> V_45 = V_46 ;
if ( V_11 -> V_44 . V_1 == V_7 )
F_91 ( V_96 , V_46 ) ;
if ( F_13 ( V_11 ) )
F_92 ( V_11 , V_96 , V_46 ) ;
} else {
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
F_90 ( L_21 ,
V_11 -> V_15 -> V_16 , V_96 -> V_15 -> V_16 ) ;
}
}
}
if ( F_54 ( V_11 -> V_44 . V_1 ) )
F_75 ( V_11 , V_96 , V_97 ) ;
if ( F_13 ( V_11 ) ) {
F_93 ( V_11 , V_96 ) ;
if ( V_97 )
F_94 ( V_97 ) ;
if ( V_96 )
F_95 ( V_96 ) ;
} else {
V_11 -> V_79 = V_96 ;
}
if ( V_11 -> V_44 . V_1 == V_4 ) {
if ( V_97 )
F_94 ( V_97 ) ;
if ( V_96 ) {
bool V_123 = false ;
F_95 ( V_96 ) ;
if ( V_11 -> V_44 . V_124 )
F_82 ( V_11 , V_96 ,
V_97 ) ;
if ( F_50 ( V_11 -> V_15 ) ) {
V_11 -> V_118 =
V_11 -> V_44 . V_125 ;
V_123 =
F_87 ( V_11 ) ;
}
F_8 ( & V_11 -> V_86 ) ;
F_68 ( & V_11 -> V_20 ) ;
F_81 ( V_126 , V_11 -> V_15 ) ;
if ( V_123 )
F_81 ( V_127 ,
V_11 -> V_15 ) ;
F_62 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_86 ) ;
}
}
if ( F_50 ( V_11 -> V_15 ) && ( V_11 -> V_44 . V_128 > 0 ) &&
( ( F_54 ( V_11 -> V_44 . V_1 ) && V_96 ) ||
V_11 -> V_44 . V_1 == V_3 ) ) {
V_11 -> V_87 = V_11 -> V_44 . V_128 ;
F_67 ( V_11 -> V_88 , & V_11 -> V_89 , 0 ) ;
}
}
void F_96 ( struct V_10 * V_11 )
{
struct V_37 * V_129 ;
int V_130 ;
V_129 = F_84 ( V_11 ) ;
if ( V_129 != V_11 -> V_79 ) {
F_89 ( V_11 , V_129 ) ;
V_130 = F_40 ( V_11 ) ;
if ( ! V_130 )
return;
if ( F_42 ( V_11 -> V_15 ) ) {
F_90 ( L_22 ,
V_11 -> V_15 -> V_16 ) ;
} else {
F_90 ( L_23 ,
V_11 -> V_15 -> V_16 ) ;
}
}
}
static void F_97 ( struct V_10 * V_11 , struct V_37 * V_131 )
{
if ( V_11 -> V_115 == NULL ) {
V_131 -> V_25 = V_131 ;
V_131 -> V_27 = V_131 ;
V_11 -> V_115 = V_131 ;
} else {
V_131 -> V_25 = V_11 -> V_115 ;
V_131 -> V_27 = V_11 -> V_115 -> V_27 ;
V_131 -> V_25 -> V_27 = V_131 ;
V_131 -> V_27 -> V_25 = V_131 ;
}
V_11 -> V_42 ++ ;
}
static void F_98 ( struct V_10 * V_11 , struct V_37 * V_37 )
{
if ( V_37 -> V_25 )
V_37 -> V_25 -> V_27 = V_37 -> V_27 ;
if ( V_37 -> V_27 )
V_37 -> V_27 -> V_25 = V_37 -> V_25 ;
if ( V_11 -> V_115 == V_37 ) {
if ( V_11 -> V_42 > 1 ) {
V_11 -> V_115 = V_37 -> V_25 ;
} else {
V_11 -> V_115 = NULL ;
}
}
V_37 -> V_25 = NULL ;
V_37 -> V_27 = NULL ;
V_11 -> V_42 -- ;
}
static inline int F_99 ( struct V_37 * V_37 )
{
struct V_132 * V_133 ;
int V_78 = 0 ;
V_133 = F_4 ( sizeof( * V_133 ) , V_134 ) ;
V_78 = - V_18 ;
if ( ! V_133 )
goto V_23;
V_78 = F_100 ( V_133 , V_37 -> V_15 , V_134 ) ;
if ( V_78 ) {
F_15 ( V_133 ) ;
goto V_23;
}
V_37 -> V_133 = V_133 ;
V_23:
return V_78 ;
}
static inline void F_101 ( struct V_37 * V_37 )
{
struct V_132 * V_133 = V_37 -> V_133 ;
if ( ! V_133 )
return;
V_37 -> V_133 = NULL ;
F_102 ( V_133 ) ;
}
static inline bool F_103 ( struct V_30 * V_31 )
{
if ( V_31 -> V_84 & V_135 )
return false ;
if ( ! V_31 -> V_60 -> V_136 )
return false ;
return true ;
}
static void F_104 ( struct V_30 * V_34 )
{
}
static void F_105 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 ;
F_30 (bond, slave, i)
if ( F_86 ( V_37 -> V_15 ) )
F_101 ( V_37 ) ;
}
static void F_106 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_62 ( & V_11 -> V_20 ) ;
F_105 ( V_11 ) ;
F_68 ( & V_11 -> V_20 ) ;
}
static int F_107 ( struct V_30 * V_15 , struct V_137 * V_138 , T_5 V_139 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
struct V_37 * V_37 ;
int V_39 , V_78 = 0 ;
F_62 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
V_78 = F_99 ( V_37 ) ;
if ( V_78 ) {
F_105 ( V_11 ) ;
break;
}
}
F_68 ( & V_11 -> V_20 ) ;
return V_78 ;
}
static struct V_137 * F_108 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_140 ;
}
static inline int F_99 ( struct V_37 * V_37 )
{
return 0 ;
}
static inline void F_101 ( struct V_37 * V_37 )
{
}
static void F_106 ( struct V_30 * V_34 )
{
}
static T_6 F_109 ( struct V_30 * V_15 ,
T_6 V_141 )
{
struct V_37 * V_37 ;
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_6 V_142 ;
int V_39 ;
F_62 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_115 ) {
V_141 |= V_143 ;
goto V_23;
}
V_142 = V_141 ;
V_141 &= ~ V_144 ;
V_141 |= V_145 ;
F_30 (bond, slave, i) {
V_141 = F_110 ( V_141 ,
V_37 -> V_15 -> V_141 ,
V_142 ) ;
}
V_141 = F_111 ( V_141 , V_142 ) ;
V_23:
F_68 ( & V_11 -> V_20 ) ;
return V_141 ;
}
static void F_112 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
struct V_30 * V_34 = V_11 -> V_15 ;
T_6 V_146 = V_147 ;
unsigned short V_148 = V_149 ;
unsigned int V_150 = V_151 ;
T_2 V_152 = V_153 ;
int V_39 ;
unsigned int V_98 , V_154 = V_155 ;
F_62 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_115 )
goto V_156;
F_30 (bond, slave, i) {
V_146 = F_110 ( V_146 ,
V_37 -> V_15 -> V_146 , V_147 ) ;
V_154 &= V_37 -> V_15 -> V_84 ;
if ( V_37 -> V_15 -> V_157 > V_148 )
V_148 = V_37 -> V_15 -> V_157 ;
V_150 = F_113 ( V_150 , V_37 -> V_15 -> V_150 ) ;
V_152 = F_113 ( V_152 , V_37 -> V_15 -> V_152 ) ;
}
V_156:
V_34 -> V_146 = V_146 ;
V_34 -> V_157 = V_148 ;
V_34 -> V_152 = V_152 ;
F_114 ( V_34 , V_150 ) ;
V_98 = V_34 -> V_84 & ~ V_155 ;
V_34 -> V_84 = V_98 | V_154 ;
F_68 ( & V_11 -> V_20 ) ;
F_115 ( V_34 ) ;
}
static void F_116 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
V_34 -> V_158 = V_31 -> V_158 ;
V_34 -> type = V_31 -> type ;
V_34 -> V_157 = V_31 -> V_157 ;
V_34 -> V_101 = V_31 -> V_101 ;
memcpy ( V_34 -> V_159 , V_31 -> V_159 ,
V_31 -> V_101 ) ;
}
static bool F_117 ( struct V_28 * V_29 ,
struct V_37 * V_37 ,
struct V_10 * V_11 )
{
if ( F_118 ( V_37 ) ) {
if ( V_11 -> V_44 . V_1 == V_9 &&
V_29 -> V_160 != V_161 &&
V_29 -> V_160 != V_162 )
return false ;
return true ;
}
return false ;
}
static T_7 F_119 ( struct V_28 * * V_163 )
{
struct V_28 * V_29 = * V_163 ;
struct V_37 * V_37 ;
struct V_10 * V_11 ;
int (* F_120)( const struct V_28 * , struct V_10 * ,
struct V_37 * );
int V_164 = V_165 ;
V_29 = F_121 ( V_29 , V_134 ) ;
if ( F_23 ( ! V_29 ) )
return V_166 ;
* V_163 = V_29 ;
V_37 = F_122 ( V_29 -> V_15 ) ;
V_11 = V_37 -> V_11 ;
if ( V_11 -> V_44 . V_167 )
V_37 -> V_15 -> V_168 = V_121 ;
F_120 = F_123 ( V_11 -> F_120 ) ;
if ( F_120 ) {
V_164 = F_120 ( V_29 , V_11 , V_37 ) ;
if ( V_164 == V_166 ) {
F_124 ( V_29 ) ;
return V_164 ;
}
}
if ( F_117 ( V_29 , V_37 , V_11 ) ) {
return V_169 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_44 . V_1 == V_9 &&
V_11 -> V_15 -> V_84 & V_170 &&
V_29 -> V_160 == V_171 ) {
if ( F_23 ( F_125 ( V_29 ,
V_29 -> V_172 - F_126 ( V_29 ) ) ) ) {
F_127 ( V_29 ) ;
return V_166 ;
}
memcpy ( F_128 ( V_29 ) -> V_173 , V_11 -> V_15 -> V_102 , V_94 ) ;
}
return V_164 ;
}
static int F_129 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
int V_78 ;
V_78 = F_130 ( V_31 , V_34 ) ;
if ( V_78 )
return V_78 ;
V_31 -> V_98 |= V_174 ;
F_131 ( V_175 , V_31 , V_174 ) ;
return 0 ;
}
static void F_132 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
F_133 ( V_31 , V_34 ) ;
V_31 -> V_98 &= ~ V_174 ;
F_131 ( V_175 , V_31 , V_174 ) ;
}
int F_134 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
const struct V_58 * V_59 = V_31 -> V_60 ;
struct V_37 * V_131 = NULL ;
struct V_176 V_177 ;
int V_178 ;
int V_21 = 0 , V_39 ;
if ( ! V_11 -> V_44 . V_65 &&
V_31 -> V_67 -> V_68 == NULL &&
V_59 -> V_69 == NULL ) {
F_38 ( L_24 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_98 & V_174 ) {
F_3 ( L_25 ) ;
return - V_179 ;
}
if ( V_31 -> V_141 & V_143 ) {
F_3 ( L_26 , V_31 -> V_16 ) ;
if ( F_135 ( V_34 ) ) {
F_32 ( L_27 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
return - V_180 ;
} else {
F_38 ( L_28 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_34 -> V_16 ) ;
}
} else {
F_3 ( L_29 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_98 & V_181 ) ) {
F_32 ( L_30 ,
V_31 -> V_16 ) ;
V_21 = - V_180 ;
goto V_182;
}
if ( V_11 -> V_42 == 0 ) {
if ( V_34 -> type != V_31 -> type ) {
F_3 ( L_31 ,
V_34 -> V_16 ,
V_34 -> type , V_31 -> type ) ;
V_21 = F_81 ( V_183 ,
V_34 ) ;
V_21 = F_136 ( V_21 ) ;
if ( V_21 ) {
F_32 ( L_32 ,
V_34 -> V_16 ) ;
V_21 = - V_179 ;
goto V_182;
}
F_137 ( V_34 ) ;
F_138 ( V_34 ) ;
if ( V_31 -> type != V_184 )
F_116 ( V_34 , V_31 ) ;
else {
F_139 ( V_34 ) ;
V_34 -> V_84 &= ~ V_185 ;
}
F_81 ( V_186 ,
V_34 ) ;
}
} else if ( V_34 -> type != V_31 -> type ) {
F_32 ( L_33 ,
V_31 -> V_16 ,
V_31 -> type , V_34 -> type ) ;
V_21 = - V_187 ;
goto V_182;
}
if ( V_59 -> V_188 == NULL ) {
if ( V_11 -> V_42 == 0 ) {
F_38 ( L_34 ,
V_34 -> V_16 ) ;
V_11 -> V_44 . V_124 = V_189 ;
} else if ( V_11 -> V_44 . V_124 != V_189 ) {
F_32 ( L_35 ,
V_34 -> V_16 ) ;
V_21 = - V_190 ;
goto V_182;
}
}
F_81 ( V_191 , V_31 ) ;
if ( ! V_11 -> V_42 && V_11 -> V_15 -> V_103 == V_192 )
F_80 ( V_11 -> V_15 , V_31 ) ;
V_131 = F_4 ( sizeof( struct V_37 ) , V_17 ) ;
if ( ! V_131 ) {
V_21 = - V_18 ;
goto V_182;
}
V_131 -> V_193 = 0 ;
V_131 -> V_194 = V_31 -> V_195 ;
V_21 = F_140 ( V_31 , V_11 -> V_15 -> V_195 ) ;
if ( V_21 ) {
F_3 ( L_36 , V_21 ) ;
goto V_196;
}
memcpy ( V_131 -> V_197 , V_31 -> V_102 , V_94 ) ;
if ( ! V_11 -> V_44 . V_124 ) {
memcpy ( V_177 . V_198 , V_34 -> V_102 , V_34 -> V_101 ) ;
V_177 . V_199 = V_31 -> type ;
V_21 = F_141 ( V_31 , & V_177 ) ;
if ( V_21 ) {
F_3 ( L_37 , V_21 ) ;
goto V_200;
}
}
V_21 = F_129 ( V_34 , V_31 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_201;
}
V_21 = F_142 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_31 -> V_16 ) ;
goto V_202;
}
V_131 -> V_11 = V_11 ;
V_131 -> V_15 = V_31 ;
V_31 -> V_84 |= V_203 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_143 ( V_11 , V_131 ) ;
if ( V_21 )
goto V_204;
}
if ( ! F_54 ( V_11 -> V_44 . V_1 ) ) {
if ( V_34 -> V_98 & V_99 ) {
V_21 = F_55 ( V_31 , 1 ) ;
if ( V_21 )
goto V_204;
}
if ( V_34 -> V_98 & V_100 ) {
V_21 = F_57 ( V_31 , 1 ) ;
if ( V_21 )
goto V_204;
}
F_76 ( V_34 ) ;
F_144 ( V_31 , V_34 ) ;
F_145 ( V_31 , V_34 ) ;
F_79 ( V_34 ) ;
}
if ( V_11 -> V_44 . V_1 == V_7 ) {
T_4 V_93 [ V_94 ] = V_95 ;
F_146 ( V_31 , V_93 ) ;
}
F_36 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_97 ( V_11 , V_131 ) ;
V_131 -> V_117 = 0 ;
V_131 -> V_205 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_112 ( V_11 ) ;
F_45 ( V_131 ) ;
F_62 ( & V_11 -> V_20 ) ;
V_131 -> V_206 = V_121 -
( F_147 ( V_11 -> V_44 . V_167 ) + 1 ) ;
for ( V_39 = 0 ; V_39 < V_207 ; V_39 ++ )
V_131 -> V_208 [ V_39 ] = V_131 -> V_206 ;
if ( V_11 -> V_44 . V_122 && ! V_11 -> V_44 . V_65 ) {
V_178 = F_48 ( V_11 , V_31 , 1 ) ;
if ( ( V_178 == - 1 ) && ! V_11 -> V_44 . V_167 ) {
F_38 ( L_40 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_178 == - 1 ) {
F_38 ( L_41 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
}
if ( V_11 -> V_44 . V_122 ) {
if ( F_48 ( V_11 , V_31 , 0 ) == V_66 ) {
if ( V_11 -> V_44 . V_114 ) {
V_131 -> V_45 = V_116 ;
V_131 -> V_117 = V_11 -> V_44 . V_114 ;
} else {
V_131 -> V_45 = V_46 ;
}
} else {
V_131 -> V_45 = V_209 ;
}
} else if ( V_11 -> V_44 . V_167 ) {
V_131 -> V_45 = ( F_42 ( V_31 ) ?
V_46 : V_209 ) ;
} else {
V_131 -> V_45 = V_46 ;
}
if ( V_131 -> V_45 != V_209 )
V_131 -> V_121 = V_121 ;
F_3 ( L_42 ,
V_131 -> V_45 == V_209 ? L_43 :
( V_131 -> V_45 == V_46 ? L_44 : L_45 ) ) ;
if ( F_54 ( V_11 -> V_44 . V_1 ) && V_11 -> V_44 . V_210 [ 0 ] ) {
if ( strcmp ( V_11 -> V_44 . V_210 , V_131 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_107 = V_131 ;
V_11 -> V_108 = true ;
}
}
F_6 ( & V_11 -> V_86 ) ;
switch ( V_11 -> V_44 . V_1 ) {
case V_4 :
F_94 ( V_131 ) ;
F_96 ( V_11 ) ;
break;
case V_7 :
F_94 ( V_131 ) ;
if ( V_11 -> V_42 == 1 ) {
F_148 ( V_131 ) . V_211 = 1 ;
F_149 ( V_11 , 1000 / V_212 ) ;
} else {
F_148 ( V_131 ) . V_211 =
F_148 ( V_131 -> V_27 ) . V_211 + 1 ;
}
F_150 ( V_131 ) ;
break;
case V_8 :
case V_9 :
F_151 ( V_131 ) ;
F_94 ( V_131 ) ;
F_96 ( V_11 ) ;
break;
default:
F_3 ( L_46 ) ;
F_151 ( V_131 ) ;
if ( ! V_11 -> V_79 && V_131 -> V_45 == V_46 )
V_11 -> V_79 = V_131 ;
break;
}
F_8 ( & V_11 -> V_86 ) ;
F_40 ( V_11 ) ;
#ifdef F_152
V_31 -> V_140 = F_108 ( V_11 ) ;
if ( V_31 -> V_140 ) {
if ( F_99 ( V_131 ) ) {
F_68 ( & V_11 -> V_20 ) ;
F_90 ( L_47
L_48 ,
V_34 -> V_16 ) ;
V_21 = - V_179 ;
goto V_213;
}
}
#endif
F_68 ( & V_11 -> V_20 ) ;
V_21 = F_153 ( V_34 , V_31 ) ;
if ( V_21 )
goto V_213;
V_21 = F_154 ( V_31 , F_119 ,
V_131 ) ;
if ( V_21 ) {
F_3 ( L_49 , V_21 ) ;
goto V_214;
}
F_90 ( L_50 ,
V_34 -> V_16 , V_31 -> V_16 ,
F_155 ( V_131 ) ? L_51 : L_52 ,
V_131 -> V_45 != V_209 ? L_53 : L_54 ) ;
return 0 ;
V_214:
F_156 ( V_34 , V_31 ) ;
V_213:
if ( ! F_54 ( V_11 -> V_44 . V_1 ) )
F_71 ( V_34 , V_31 ) ;
F_39 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_98 ( V_11 , V_131 ) ;
if ( V_11 -> V_107 == V_131 )
V_11 -> V_107 = NULL ;
if ( V_11 -> V_79 == V_131 ) {
F_89 ( V_11 , NULL ) ;
F_8 ( & V_11 -> V_20 ) ;
F_62 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_86 ) ;
F_96 ( V_11 ) ;
F_8 ( & V_11 -> V_86 ) ;
F_68 ( & V_11 -> V_20 ) ;
} else {
F_8 ( & V_11 -> V_20 ) ;
}
F_101 ( V_131 ) ;
V_204:
V_31 -> V_84 &= ~ V_203 ;
F_157 ( V_31 ) ;
V_202:
F_132 ( V_34 , V_31 ) ;
V_201:
if ( ! V_11 -> V_44 . V_124 ) {
memcpy ( V_177 . V_198 , V_131 -> V_197 , V_94 ) ;
V_177 . V_199 = V_31 -> type ;
F_141 ( V_31 , & V_177 ) ;
}
V_200:
F_140 ( V_31 , V_131 -> V_194 ) ;
V_196:
F_15 ( V_131 ) ;
V_182:
F_112 ( V_11 ) ;
if ( V_11 -> V_42 == 0 &&
F_158 ( V_34 -> V_102 , V_31 -> V_102 ) )
F_159 ( V_34 ) ;
return V_21 ;
}
static int F_160 ( struct V_30 * V_34 ,
struct V_30 * V_31 ,
bool V_215 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_216 ;
struct V_176 V_177 ;
T_6 V_217 = V_34 -> V_141 ;
if ( ! ( V_31 -> V_98 & V_174 ) ||
! F_161 ( V_31 , V_34 ) ) {
F_32 ( L_55 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
return - V_187 ;
}
F_10 () ;
F_6 ( & V_11 -> V_20 ) ;
V_37 = F_26 ( V_11 , V_31 ) ;
if ( ! V_37 ) {
F_90 ( L_56 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_187 ;
}
F_8 ( & V_11 -> V_20 ) ;
F_162 ( V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_215 && ! V_11 -> V_44 . V_124 ) {
if ( F_158 ( V_34 -> V_102 , V_37 -> V_197 ) &&
V_11 -> V_42 > 1 )
F_38 ( L_57 ,
V_34 -> V_16 , V_31 -> V_16 ,
V_37 -> V_197 ,
V_34 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_44 . V_1 == V_7 ) {
F_163 ( V_37 ) ;
}
F_90 ( L_58 ,
V_34 -> V_16 ,
F_155 ( V_37 ) ? L_59 : L_60 ,
V_31 -> V_16 ) ;
V_216 = V_11 -> V_79 ;
V_11 -> V_218 = NULL ;
F_98 ( V_11 , V_37 ) ;
if ( V_11 -> V_107 == V_37 )
V_11 -> V_107 = NULL ;
if ( V_216 == V_37 )
F_89 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_164 ( V_11 , V_37 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_215 ) {
V_11 -> V_79 = NULL ;
} else if ( V_216 == V_37 ) {
F_8 ( & V_11 -> V_20 ) ;
F_62 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_86 ) ;
F_96 ( V_11 ) ;
F_8 ( & V_11 -> V_86 ) ;
F_68 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_42 == 0 ) {
F_40 ( V_11 ) ;
F_159 ( V_34 ) ;
if ( F_165 ( V_11 ) ) {
F_38 ( L_61 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_38 ( L_62 ,
V_34 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
if ( V_11 -> V_42 == 0 ) {
F_81 ( V_105 , V_11 -> V_15 ) ;
F_81 ( V_219 , V_11 -> V_15 ) ;
}
F_112 ( V_11 ) ;
if ( ! ( V_34 -> V_141 & V_143 ) &&
( V_217 & V_143 ) )
F_90 ( L_63 ,
V_34 -> V_16 , V_31 -> V_16 , V_34 -> V_16 ) ;
F_156 ( V_34 , V_31 ) ;
F_39 ( V_11 , V_31 ) ;
if ( ! F_54 ( V_11 -> V_44 . V_1 ) ) {
if ( V_34 -> V_98 & V_99 )
F_55 ( V_31 , - 1 ) ;
if ( V_34 -> V_98 & V_100 )
F_57 ( V_31 , - 1 ) ;
F_71 ( V_34 , V_31 ) ;
}
F_132 ( V_34 , V_31 ) ;
F_101 ( V_37 ) ;
F_157 ( V_31 ) ;
if ( V_11 -> V_44 . V_124 != V_189 ) {
memcpy ( V_177 . V_198 , V_37 -> V_197 , V_94 ) ;
V_177 . V_199 = V_31 -> type ;
F_141 ( V_31 , & V_177 ) ;
}
F_140 ( V_31 , V_37 -> V_194 ) ;
V_31 -> V_84 &= ~ V_203 ;
F_15 ( V_37 ) ;
return 0 ;
}
int F_166 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
return F_160 ( V_34 , V_31 , false ) ;
}
static int F_167 ( struct V_30 * V_34 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_164 ;
V_164 = F_166 ( V_34 , V_31 ) ;
if ( ( V_164 == 0 ) && ( V_11 -> V_42 == 0 ) ) {
V_34 -> V_84 |= V_135 ;
F_90 ( L_64 ,
V_34 -> V_16 , V_34 -> V_16 ) ;
F_168 ( V_34 ) ;
}
return V_164 ;
}
static int F_169 ( struct V_30 * V_34 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_97 = NULL ;
struct V_37 * V_96 = NULL ;
int V_21 = 0 ;
if ( ! F_54 ( V_11 -> V_44 . V_1 ) )
return - V_187 ;
if ( ! ( V_31 -> V_98 & V_174 ) ||
! F_161 ( V_31 , V_34 ) )
return - V_187 ;
F_62 ( & V_11 -> V_20 ) ;
F_62 ( & V_11 -> V_86 ) ;
V_97 = V_11 -> V_79 ;
F_68 ( & V_11 -> V_86 ) ;
V_96 = F_26 ( V_11 , V_31 ) ;
if ( V_96 && ( V_96 == V_97 ) ) {
F_68 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_96 ) &&
( V_97 ) &&
( V_96 -> V_45 == V_46 ) &&
F_86 ( V_96 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_86 ) ;
F_89 ( V_11 , V_96 ) ;
F_8 ( & V_11 -> V_86 ) ;
F_16 () ;
} else
V_21 = - V_187 ;
F_68 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_170 ( struct V_30 * V_34 , struct V_220 * V_221 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_221 -> V_222 = V_11 -> V_44 . V_1 ;
V_221 -> V_122 = V_11 -> V_44 . V_122 ;
F_62 ( & V_11 -> V_20 ) ;
V_221 -> V_223 = V_11 -> V_42 ;
F_68 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_171 ( struct V_30 * V_34 , struct V_224 * V_221 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 ;
int V_39 , V_21 = - V_22 ;
F_62 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
if ( V_39 == ( int ) V_221 -> V_225 ) {
V_21 = 0 ;
strcpy ( V_221 -> V_226 , V_37 -> V_15 -> V_16 ) ;
V_221 -> V_45 = V_37 -> V_45 ;
V_221 -> V_120 = F_172 ( V_37 ) ;
V_221 -> V_205 = V_37 -> V_205 ;
break;
}
}
F_68 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_173 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 , V_227 , V_228 = 0 ;
bool V_229 ;
V_229 = ! V_11 -> V_79 ? true : false ;
F_30 (bond, slave, i) {
V_37 -> V_230 = V_231 ;
V_227 = F_48 ( V_11 , V_37 -> V_15 , 0 ) ;
switch ( V_37 -> V_45 ) {
case V_46 :
if ( V_227 )
continue;
V_37 -> V_45 = V_232 ;
V_37 -> V_117 = V_11 -> V_44 . V_233 ;
if ( V_37 -> V_117 ) {
F_90 ( L_65 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_44 . V_1 ==
V_4 ) ?
( F_155 ( V_37 ) ?
L_66 : L_67 ) : L_68 ,
V_37 -> V_15 -> V_16 ,
V_11 -> V_44 . V_233 * V_11 -> V_44 . V_122 ) ;
}
case V_232 :
if ( V_227 ) {
V_37 -> V_45 = V_46 ;
V_37 -> V_121 = V_121 ;
F_90 ( L_69 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_44 . V_233 - V_37 -> V_117 ) *
V_11 -> V_44 . V_122 ,
V_37 -> V_15 -> V_16 ) ;
continue;
}
if ( V_37 -> V_117 <= 0 ) {
V_37 -> V_230 = V_209 ;
V_228 ++ ;
continue;
}
V_37 -> V_117 -- ;
break;
case V_209 :
if ( ! V_227 )
continue;
V_37 -> V_45 = V_116 ;
V_37 -> V_117 = V_11 -> V_44 . V_114 ;
if ( V_37 -> V_117 ) {
F_90 ( L_70 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ,
V_229 ? 0 :
V_11 -> V_44 . V_114 *
V_11 -> V_44 . V_122 ) ;
}
case V_116 :
if ( ! V_227 ) {
V_37 -> V_45 = V_209 ;
F_90 ( L_71 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_44 . V_114 - V_37 -> V_117 ) *
V_11 -> V_44 . V_122 ,
V_37 -> V_15 -> V_16 ) ;
continue;
}
if ( V_229 )
V_37 -> V_117 = 0 ;
if ( V_37 -> V_117 <= 0 ) {
V_37 -> V_230 = V_46 ;
V_228 ++ ;
V_229 = false ;
continue;
}
V_37 -> V_117 -- ;
break;
}
}
return V_228 ;
}
static void F_174 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 ;
F_30 (bond, slave, i) {
switch ( V_37 -> V_230 ) {
case V_231 :
continue;
case V_46 :
V_37 -> V_45 = V_46 ;
V_37 -> V_121 = V_121 ;
if ( V_11 -> V_44 . V_1 == V_7 ) {
F_175 ( V_37 ) ;
} else if ( V_11 -> V_44 . V_1 != V_4 ) {
F_151 ( V_37 ) ;
} else if ( V_37 != V_11 -> V_107 ) {
F_175 ( V_37 ) ;
}
F_90 ( L_72 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ,
V_37 -> V_50 == V_51 ? 0 : V_37 -> V_50 ,
V_37 -> V_52 ? L_73 : L_74 ) ;
if ( V_11 -> V_44 . V_1 == V_7 )
F_91 ( V_37 , V_46 ) ;
if ( F_13 ( V_11 ) )
F_92 ( V_11 , V_37 ,
V_46 ) ;
if ( ! V_11 -> V_79 ||
( V_37 == V_11 -> V_107 ) )
goto V_234;
continue;
case V_209 :
if ( V_37 -> V_205 < V_235 )
V_37 -> V_205 ++ ;
V_37 -> V_45 = V_209 ;
if ( V_11 -> V_44 . V_1 == V_4 ||
V_11 -> V_44 . V_1 == V_7 )
F_94 ( V_37 ) ;
F_90 ( L_75 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ) ;
if ( V_11 -> V_44 . V_1 == V_7 )
F_91 ( V_37 ,
V_209 ) ;
if ( F_13 ( V_11 ) )
F_92 ( V_11 , V_37 ,
V_209 ) ;
if ( V_37 == V_11 -> V_79 )
goto V_234;
continue;
default:
F_32 ( L_76 ,
V_11 -> V_15 -> V_16 , V_37 -> V_230 ,
V_37 -> V_15 -> V_16 ) ;
V_37 -> V_230 = V_231 ;
continue;
}
V_234:
F_176 () ;
F_10 () ;
F_6 ( & V_11 -> V_86 ) ;
F_96 ( V_11 ) ;
F_8 ( & V_11 -> V_86 ) ;
F_16 () ;
}
F_40 ( V_11 ) ;
}
void F_177 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_70 ( V_92 , struct V_10 ,
V_236 . V_92 ) ;
bool V_123 = false ;
unsigned long V_117 ;
F_62 ( & V_11 -> V_20 ) ;
V_117 = F_147 ( V_11 -> V_44 . V_122 ) ;
if ( V_11 -> V_42 == 0 )
goto V_237;
V_123 = F_87 ( V_11 ) ;
if ( F_173 ( V_11 ) ) {
F_68 ( & V_11 -> V_20 ) ;
if ( ! F_178 () ) {
F_62 ( & V_11 -> V_20 ) ;
V_117 = 1 ;
V_123 = false ;
goto V_237;
}
F_62 ( & V_11 -> V_20 ) ;
F_174 ( V_11 ) ;
F_68 ( & V_11 -> V_20 ) ;
F_179 () ;
F_62 ( & V_11 -> V_20 ) ;
}
V_237:
if ( V_11 -> V_44 . V_122 )
F_67 ( V_11 -> V_88 , & V_11 -> V_236 , V_117 ) ;
F_68 ( & V_11 -> V_20 ) ;
if ( V_123 ) {
if ( ! F_178 () ) {
F_62 ( & V_11 -> V_20 ) ;
V_11 -> V_118 ++ ;
F_68 ( & V_11 -> V_20 ) ;
return;
}
F_81 ( V_127 , V_11 -> V_15 ) ;
F_179 () ;
}
}
static int F_180 ( struct V_10 * V_11 , T_8 V_238 )
{
struct V_13 * V_14 ;
struct V_30 * V_82 ;
if ( V_238 == F_181 ( V_11 -> V_15 , 0 , V_238 ) )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_63 () ;
V_82 = F_65 ( V_11 -> V_15 , F_37 ( V_41 ) ,
V_14 -> V_12 ) ;
F_66 () ;
if ( V_82 && V_238 == F_181 ( V_82 , 0 , V_238 ) )
return 1 ;
}
return 0 ;
}
static void F_182 ( struct V_30 * V_31 , int V_239 , T_8 V_240 , T_8 V_241 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_77 , V_239 ,
V_31 -> V_16 , & V_240 , & V_241 , V_12 ) ;
V_29 = F_183 ( V_239 , V_242 , V_240 , V_31 , V_241 ,
NULL , V_31 -> V_102 , NULL ) ;
if ( ! V_29 ) {
F_32 ( L_78 ) ;
return;
}
if ( V_12 ) {
V_29 = F_184 ( V_29 , F_37 ( V_41 ) , V_12 ) ;
if ( ! V_29 ) {
F_32 ( L_79 ) ;
return;
}
}
F_185 ( V_29 ) ;
}
static void F_186 ( struct V_10 * V_11 , struct V_37 * V_37 )
{
int V_39 , V_12 ;
T_8 * V_243 = V_11 -> V_44 . V_244 ;
struct V_13 * V_14 ;
struct V_30 * V_82 = NULL ;
struct V_245 * V_246 ;
for ( V_39 = 0 ; ( V_39 < V_207 ) ; V_39 ++ ) {
T_8 V_177 ;
if ( ! V_243 [ V_39 ] )
break;
F_3 ( L_80 , & V_243 [ V_39 ] ) ;
if ( ! F_165 ( V_11 ) ) {
F_3 ( L_81 ) ;
V_177 = F_181 ( V_11 -> V_15 , V_243 [ V_39 ] , 0 ) ;
F_182 ( V_37 -> V_15 , V_247 , V_243 [ V_39 ] ,
V_177 , 0 ) ;
continue;
}
V_246 = F_187 ( F_188 ( V_11 -> V_15 ) , V_243 [ V_39 ] , 0 ,
V_248 , 0 ) ;
if ( F_189 ( V_246 ) ) {
if ( F_190 () ) {
F_38 ( L_82 ,
V_11 -> V_15 -> V_16 , & V_243 [ V_39 ] ) ;
}
continue;
}
if ( V_246 -> V_249 . V_15 == V_11 -> V_15 ) {
F_191 ( V_246 ) ;
F_3 ( L_83 ) ;
V_177 = F_181 ( V_11 -> V_15 , V_243 [ V_39 ] , 0 ) ;
F_182 ( V_37 -> V_15 , V_247 , V_243 [ V_39 ] ,
V_177 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_63 () ;
V_82 = F_65 ( V_11 -> V_15 ,
F_37 ( V_41 ) ,
V_14 -> V_12 ) ;
F_66 () ;
if ( V_82 == V_246 -> V_249 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_84 ,
V_82 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 && V_82 ) {
F_191 ( V_246 ) ;
V_177 = F_181 ( V_82 , V_243 [ V_39 ] , 0 ) ;
F_182 ( V_37 -> V_15 , V_247 , V_243 [ V_39 ] ,
V_177 , V_12 ) ;
continue;
}
if ( F_190 () ) {
F_38 ( L_85 ,
V_11 -> V_15 -> V_16 , & V_243 [ V_39 ] ,
V_246 -> V_249 . V_15 ? V_246 -> V_249 . V_15 -> V_16 : L_19 ) ;
}
F_191 ( V_246 ) ;
}
}
static void F_192 ( struct V_10 * V_11 , struct V_37 * V_37 , T_8 V_250 , T_8 V_251 )
{
int V_39 ;
if ( ! V_250 || ! F_180 ( V_11 , V_251 ) ) {
F_3 ( L_86 , & V_250 , & V_251 ) ;
return;
}
V_39 = F_193 ( V_11 -> V_44 . V_244 , V_250 ) ;
if ( V_39 == - 1 ) {
F_3 ( L_87 , & V_250 ) ;
return;
}
V_37 -> V_206 = V_121 ;
V_37 -> V_208 [ V_39 ] = V_121 ;
}
static int F_194 ( const struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_37 * V_37 )
{
struct V_252 * V_253 = (struct V_252 * ) V_29 -> V_172 ;
unsigned char * V_254 ;
T_8 V_250 , V_251 ;
int V_255 ;
if ( V_29 -> V_256 != F_195 ( V_242 ) )
return V_165 ;
F_62 ( & V_11 -> V_20 ) ;
if ( ! F_196 ( V_11 , V_37 ) )
goto V_257;
V_255 = F_197 ( V_11 -> V_15 ) ;
F_3 ( L_88 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( V_255 > F_198 ( V_29 ) ) {
V_253 = F_199 ( V_255 , V_134 ) ;
if ( ! V_253 )
goto V_257;
if ( F_200 ( V_29 , 0 , V_253 , V_255 ) < 0 )
goto V_257;
}
if ( V_253 -> V_258 != V_11 -> V_15 -> V_101 ||
V_29 -> V_160 == V_259 ||
V_29 -> V_160 == V_260 ||
V_253 -> V_261 != F_37 ( V_184 ) ||
V_253 -> V_262 != F_37 ( V_263 ) ||
V_253 -> V_264 != 4 )
goto V_257;
V_254 = ( unsigned char * ) ( V_253 + 1 ) ;
V_254 += V_11 -> V_15 -> V_101 ;
memcpy ( & V_250 , V_254 , 4 ) ;
V_254 += 4 + V_11 -> V_15 -> V_101 ;
memcpy ( & V_251 , V_254 , 4 ) ;
F_3 ( L_89 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 , F_172 ( V_37 ) ,
V_11 -> V_44 . V_265 , F_196 ( V_11 , V_37 ) ,
& V_250 , & V_251 ) ;
if ( F_155 ( V_37 ) )
F_192 ( V_11 , V_37 , V_250 , V_251 ) ;
else if ( V_11 -> V_79 &&
F_201 ( F_202 ( V_11 , V_11 -> V_79 ) ,
V_11 -> V_79 -> V_121 ) )
F_192 ( V_11 , V_37 , V_251 , V_250 ) ;
V_257:
F_68 ( & V_11 -> V_20 ) ;
if ( V_253 != (struct V_252 * ) V_29 -> V_172 )
F_15 ( V_253 ) ;
return V_165 ;
}
void F_203 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_70 ( V_92 , struct V_10 ,
V_266 . V_92 ) ;
struct V_37 * V_37 , * V_216 ;
int V_234 = 0 ;
int V_267 , V_268 ;
int V_39 ;
F_62 ( & V_11 -> V_20 ) ;
V_267 = F_147 ( V_11 -> V_44 . V_167 ) ;
V_268 = V_267 / 2 ;
if ( V_11 -> V_42 == 0 )
goto V_237;
F_62 ( & V_11 -> V_86 ) ;
V_216 = V_11 -> V_79 ;
F_68 ( & V_11 -> V_86 ) ;
F_30 (bond, slave, i) {
unsigned long V_269 = F_204 ( V_37 -> V_15 ) ;
if ( V_37 -> V_45 != V_46 ) {
if ( F_205 ( V_121 ,
V_269 - V_267 ,
V_269 + V_267 + V_268 ) &&
F_205 ( V_121 ,
V_37 -> V_15 -> V_168 - V_267 ,
V_37 -> V_15 -> V_168 + V_267 + V_268 ) ) {
V_37 -> V_45 = V_46 ;
F_151 ( V_37 ) ;
if ( ! V_216 ) {
F_90 ( L_90 ,
V_11 -> V_15 -> V_16 ,
V_37 -> V_15 -> V_16 ) ;
V_234 = 1 ;
} else {
F_90 ( L_91 ,
V_11 -> V_15 -> V_16 ,
V_37 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_205 ( V_121 ,
V_269 - V_267 ,
V_269 + 2 * V_267 + V_268 ) ||
! F_205 ( V_121 ,
V_37 -> V_15 -> V_168 - V_267 ,
V_37 -> V_15 -> V_168 + 2 * V_267 + V_268 ) ) {
V_37 -> V_45 = V_209 ;
F_175 ( V_37 ) ;
if ( V_37 -> V_205 < V_235 )
V_37 -> V_205 ++ ;
F_90 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_37 -> V_15 -> V_16 ) ;
if ( V_37 == V_216 )
V_234 = 1 ;
}
}
if ( F_86 ( V_37 -> V_15 ) )
F_186 ( V_11 , V_37 ) ;
}
if ( V_234 ) {
F_10 () ;
F_6 ( & V_11 -> V_86 ) ;
F_96 ( V_11 ) ;
F_8 ( & V_11 -> V_86 ) ;
F_16 () ;
}
V_237:
if ( V_11 -> V_44 . V_167 )
F_67 ( V_11 -> V_88 , & V_11 -> V_266 , V_267 ) ;
F_68 ( & V_11 -> V_20 ) ;
}
static int F_206 ( struct V_10 * V_11 , int V_267 )
{
struct V_37 * V_37 ;
int V_39 , V_228 = 0 ;
unsigned long V_269 ;
int V_268 ;
V_268 = V_267 / 2 ;
F_30 (bond, slave, i) {
V_37 -> V_230 = V_231 ;
if ( V_37 -> V_45 != V_46 ) {
if ( F_205 ( V_121 ,
F_202 ( V_11 , V_37 ) - V_267 ,
F_202 ( V_11 , V_37 ) + V_267 + V_268 ) ) {
V_37 -> V_230 = V_46 ;
V_228 ++ ;
}
continue;
}
if ( F_205 ( V_121 ,
V_37 -> V_121 - V_267 ,
V_37 -> V_121 + 2 * V_267 + V_268 ) )
continue;
if ( ! F_155 ( V_37 ) &&
! V_11 -> V_218 &&
! F_205 ( V_121 ,
F_202 ( V_11 , V_37 ) - V_267 ,
F_202 ( V_11 , V_37 ) + 3 * V_267 + V_268 ) ) {
V_37 -> V_230 = V_209 ;
V_228 ++ ;
}
V_269 = F_204 ( V_37 -> V_15 ) ;
if ( F_155 ( V_37 ) &&
( ! F_205 ( V_121 ,
V_269 - V_267 ,
V_269 + 2 * V_267 + V_268 ) ||
! F_205 ( V_121 ,
F_202 ( V_11 , V_37 ) - V_267 ,
F_202 ( V_11 , V_37 ) + 2 * V_267 + V_268 ) ) ) {
V_37 -> V_230 = V_209 ;
V_228 ++ ;
}
}
return V_228 ;
}
static void F_207 ( struct V_10 * V_11 , int V_267 )
{
struct V_37 * V_37 ;
int V_39 ;
unsigned long V_269 ;
F_30 (bond, slave, i) {
switch ( V_37 -> V_230 ) {
case V_231 :
continue;
case V_46 :
V_269 = F_204 ( V_37 -> V_15 ) ;
if ( ( ! V_11 -> V_79 &&
F_205 ( V_121 ,
V_269 - V_267 ,
V_269 + V_267 + V_267 / 2 ) ) ||
V_11 -> V_79 != V_37 ) {
V_37 -> V_45 = V_46 ;
if ( V_11 -> V_218 ) {
F_94 (
V_11 -> V_218 ) ;
V_11 -> V_218 = NULL ;
}
F_90 ( L_93 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_79 ||
( V_37 == V_11 -> V_107 ) )
goto V_234;
}
continue;
case V_209 :
if ( V_37 -> V_205 < V_235 )
V_37 -> V_205 ++ ;
V_37 -> V_45 = V_209 ;
F_94 ( V_37 ) ;
F_90 ( L_75 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ) ;
if ( V_37 == V_11 -> V_79 ) {
V_11 -> V_218 = NULL ;
goto V_234;
}
continue;
default:
F_32 ( L_94 ,
V_11 -> V_15 -> V_16 , V_37 -> V_230 ,
V_37 -> V_15 -> V_16 ) ;
continue;
}
V_234:
F_176 () ;
F_10 () ;
F_6 ( & V_11 -> V_86 ) ;
F_96 ( V_11 ) ;
F_8 ( & V_11 -> V_86 ) ;
F_16 () ;
}
F_40 ( V_11 ) ;
}
static void F_208 ( struct V_10 * V_11 )
{
struct V_37 * V_37 ;
int V_39 ;
F_62 ( & V_11 -> V_86 ) ;
if ( V_11 -> V_218 && V_11 -> V_79 )
F_90 ( L_95 ,
V_11 -> V_218 -> V_15 -> V_16 ,
V_11 -> V_79 -> V_15 -> V_16 ) ;
if ( V_11 -> V_79 ) {
F_186 ( V_11 , V_11 -> V_79 ) ;
F_68 ( & V_11 -> V_86 ) ;
return;
}
F_68 ( & V_11 -> V_86 ) ;
if ( ! V_11 -> V_218 ) {
V_11 -> V_218 = V_11 -> V_115 ;
if ( ! V_11 -> V_218 )
return;
}
F_94 ( V_11 -> V_218 ) ;
F_85 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_86 ( V_37 -> V_15 ) ) {
V_37 -> V_45 = V_116 ;
F_95 ( V_37 ) ;
F_186 ( V_11 , V_37 ) ;
V_37 -> V_121 = V_121 ;
V_11 -> V_218 = V_37 ;
break;
}
if ( V_37 -> V_45 == V_46 ) {
V_37 -> V_45 = V_209 ;
if ( V_37 -> V_205 < V_235 )
V_37 -> V_205 ++ ;
F_94 ( V_37 ) ;
F_90 ( L_96 ,
V_11 -> V_15 -> V_16 , V_37 -> V_15 -> V_16 ) ;
}
}
}
void F_209 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = F_70 ( V_92 , struct V_10 ,
V_266 . V_92 ) ;
bool V_123 = false ;
int V_267 ;
F_62 ( & V_11 -> V_20 ) ;
V_267 = F_147 ( V_11 -> V_44 . V_167 ) ;
if ( V_11 -> V_42 == 0 )
goto V_237;
V_123 = F_87 ( V_11 ) ;
if ( F_206 ( V_11 , V_267 ) ) {
F_68 ( & V_11 -> V_20 ) ;
if ( ! F_178 () ) {
F_62 ( & V_11 -> V_20 ) ;
V_267 = 1 ;
V_123 = false ;
goto V_237;
}
F_62 ( & V_11 -> V_20 ) ;
F_207 ( V_11 , V_267 ) ;
F_68 ( & V_11 -> V_20 ) ;
F_179 () ;
F_62 ( & V_11 -> V_20 ) ;
}
F_208 ( V_11 ) ;
V_237:
if ( V_11 -> V_44 . V_167 )
F_67 ( V_11 -> V_88 , & V_11 -> V_266 , V_267 ) ;
F_68 ( & V_11 -> V_20 ) ;
if ( V_123 ) {
if ( ! F_178 () ) {
F_62 ( & V_11 -> V_20 ) ;
V_11 -> V_118 ++ ;
F_68 ( & V_11 -> V_20 ) ;
return;
}
F_81 ( V_127 , V_11 -> V_15 ) ;
F_179 () ;
}
}
static int F_210 ( struct V_10 * V_11 )
{
F_211 ( V_11 ) ;
F_212 ( V_11 ) ;
F_213 ( V_11 ) ;
return V_270 ;
}
static int F_214 ( unsigned long V_271 ,
struct V_30 * V_34 )
{
struct V_10 * V_272 = F_29 ( V_34 ) ;
switch ( V_271 ) {
case V_273 :
return F_210 ( V_272 ) ;
case V_274 :
F_211 ( V_272 ) ;
break;
case V_275 :
F_212 ( V_272 ) ;
break;
default:
break;
}
return V_270 ;
}
static int F_215 ( unsigned long V_271 ,
struct V_30 * V_31 )
{
struct V_37 * V_37 = F_216 ( V_31 ) ;
struct V_10 * V_11 ;
struct V_30 * V_34 ;
T_3 V_276 ;
T_4 V_277 ;
if ( ! V_37 )
return V_270 ;
V_34 = V_37 -> V_11 -> V_15 ;
V_11 = V_37 -> V_11 ;
switch ( V_271 ) {
case V_274 :
if ( V_34 -> type != V_184 )
F_167 ( V_34 , V_31 ) ;
else
F_166 ( V_34 , V_31 ) ;
break;
case V_278 :
case V_279 :
V_276 = V_37 -> V_50 ;
V_277 = V_37 -> V_52 ;
F_45 ( V_37 ) ;
if ( V_11 -> V_44 . V_1 == V_7 ) {
if ( V_276 != V_37 -> V_50 )
F_217 ( V_37 ) ;
if ( V_277 != V_37 -> V_52 )
F_218 ( V_37 ) ;
}
break;
case V_280 :
break;
case V_281 :
break;
case V_273 :
break;
case V_282 :
F_112 ( V_11 ) ;
break;
default:
break;
}
return V_270 ;
}
static int F_219 ( struct V_283 * V_284 ,
unsigned long V_271 , void * V_285 )
{
struct V_30 * V_286 = F_220 ( V_285 ) ;
F_3 ( L_97 ,
V_286 ? V_286 -> V_16 : L_10 ,
V_271 ) ;
if ( ! ( V_286 -> V_84 & V_203 ) )
return V_270 ;
if ( V_286 -> V_98 & V_287 ) {
F_3 ( L_98 ) ;
return F_214 ( V_271 , V_286 ) ;
}
if ( V_286 -> V_98 & V_174 ) {
F_3 ( L_99 ) ;
return F_215 ( V_271 , V_286 ) ;
}
return V_270 ;
}
static int F_221 ( struct V_28 * V_29 , int V_288 )
{
struct V_289 * V_172 = (struct V_289 * ) V_29 -> V_172 ;
if ( F_198 ( V_29 ) >= F_222 ( struct V_289 , V_290 ) )
return ( V_172 -> V_173 [ 5 ] ^ V_172 -> V_291 [ 5 ] ) % V_288 ;
return 0 ;
}
static int F_223 ( struct V_28 * V_29 , int V_288 )
{
const struct V_289 * V_172 ;
const struct V_292 * V_293 ;
const struct V_294 * V_295 ;
T_3 V_296 ;
const T_8 * V_297 , * V_298 ;
if ( V_29 -> V_256 == F_37 ( V_263 ) &&
F_224 ( V_29 , sizeof( * V_293 ) ) ) {
V_293 = F_225 ( V_29 ) ;
V_172 = (struct V_289 * ) V_29 -> V_172 ;
return ( ( F_226 ( V_293 -> V_299 ^ V_293 -> V_300 ) & 0xffff ) ^
( V_172 -> V_173 [ 5 ] ^ V_172 -> V_291 [ 5 ] ) ) % V_288 ;
} else if ( V_29 -> V_256 == F_37 ( V_301 ) &&
F_224 ( V_29 , sizeof( * V_295 ) ) ) {
V_295 = F_227 ( V_29 ) ;
V_172 = (struct V_289 * ) V_29 -> V_172 ;
V_297 = & V_295 -> V_299 . V_302 [ 0 ] ;
V_298 = & V_295 -> V_300 . V_302 [ 0 ] ;
V_296 = ( V_297 [ 1 ] ^ V_298 [ 1 ] ) ^ ( V_297 [ 2 ] ^ V_298 [ 2 ] ) ^ ( V_297 [ 3 ] ^ V_298 [ 3 ] ) ;
V_296 ^= ( V_296 >> 24 ) ^ ( V_296 >> 16 ) ^ ( V_296 >> 8 ) ;
return ( V_296 ^ V_172 -> V_173 [ 5 ] ^ V_172 -> V_291 [ 5 ] ) % V_288 ;
}
return F_221 ( V_29 , V_288 ) ;
}
static int F_228 ( struct V_28 * V_29 , int V_288 )
{
T_3 V_303 = 0 ;
const struct V_292 * V_293 ;
const struct V_294 * V_295 ;
const T_8 * V_297 , * V_298 ;
const T_1 * V_304 = NULL ;
T_1 V_305 [ 2 ] ;
int V_306 = F_229 ( V_29 ) ;
int V_307 ;
if ( V_29 -> V_256 == F_37 ( V_263 ) &&
F_230 ( V_29 , V_306 + sizeof( * V_293 ) ) ) {
V_293 = F_225 ( V_29 ) ;
V_307 = F_231 ( V_293 -> V_256 ) ;
if ( ! F_232 ( V_293 ) && V_307 >= 0 ) {
V_304 = F_233 ( V_29 , V_306 + ( V_293 -> V_308 << 2 ) + V_307 ,
sizeof( V_305 ) , & V_305 ) ;
if ( V_304 )
V_303 = F_234 ( V_304 [ 0 ] ^ V_304 [ 1 ] ) ;
}
return ( V_303 ^
( ( F_226 ( V_293 -> V_299 ^ V_293 -> V_300 ) ) & 0xffff ) ) % V_288 ;
} else if ( V_29 -> V_256 == F_37 ( V_301 ) &&
F_230 ( V_29 , V_306 + sizeof( * V_295 ) ) ) {
V_295 = F_227 ( V_29 ) ;
V_307 = F_231 ( V_295 -> V_309 ) ;
if ( V_307 >= 0 ) {
V_304 = F_233 ( V_29 , V_306 + sizeof( * V_295 ) + V_307 ,
sizeof( V_305 ) , & V_305 ) ;
if ( V_304 )
V_303 = F_234 ( V_304 [ 0 ] ^ V_304 [ 1 ] ) ;
}
V_297 = & V_295 -> V_299 . V_302 [ 0 ] ;
V_298 = & V_295 -> V_300 . V_302 [ 0 ] ;
V_303 ^= ( V_297 [ 1 ] ^ V_298 [ 1 ] ) ^ ( V_297 [ 2 ] ^ V_298 [ 2 ] ) ^ ( V_297 [ 3 ] ^ V_298 [ 3 ] ) ;
V_303 ^= ( V_303 >> 24 ) ^ ( V_303 >> 16 ) ^
( V_303 >> 8 ) ;
return V_303 % V_288 ;
}
return F_221 ( V_29 , V_288 ) ;
}
static void F_235 ( struct V_10 * V_11 )
{
F_236 ( & V_11 -> V_89 ,
F_69 ) ;
F_236 ( & V_11 -> V_310 , V_311 ) ;
F_236 ( & V_11 -> V_236 , F_177 ) ;
if ( V_11 -> V_44 . V_1 == V_4 )
F_236 ( & V_11 -> V_266 , F_209 ) ;
else
F_236 ( & V_11 -> V_266 , F_203 ) ;
F_236 ( & V_11 -> V_312 , V_313 ) ;
}
static void F_237 ( struct V_10 * V_11 )
{
F_238 ( & V_11 -> V_236 ) ;
F_238 ( & V_11 -> V_266 ) ;
F_238 ( & V_11 -> V_310 ) ;
F_238 ( & V_11 -> V_312 ) ;
F_238 ( & V_11 -> V_89 ) ;
}
static int F_239 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 ;
int V_39 ;
F_62 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_42 > 0 ) {
F_62 ( & V_11 -> V_86 ) ;
F_30 (bond, slave, i) {
if ( ( V_11 -> V_44 . V_1 == V_4 )
&& ( V_37 != V_11 -> V_79 ) ) {
F_94 ( V_37 ) ;
} else {
F_95 ( V_37 ) ;
}
}
F_68 ( & V_11 -> V_86 ) ;
}
F_68 ( & V_11 -> V_20 ) ;
F_235 ( V_11 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_240 ( V_11 , ( V_11 -> V_44 . V_1 == V_9 ) ) )
return - V_18 ;
F_67 ( V_11 -> V_88 , & V_11 -> V_310 , 0 ) ;
}
if ( V_11 -> V_44 . V_122 )
F_67 ( V_11 -> V_88 , & V_11 -> V_236 , 0 ) ;
if ( V_11 -> V_44 . V_167 ) {
F_67 ( V_11 -> V_88 , & V_11 -> V_266 , 0 ) ;
if ( V_11 -> V_44 . V_265 )
V_11 -> F_120 = F_194 ;
}
if ( V_11 -> V_44 . V_1 == V_7 ) {
F_67 ( V_11 -> V_88 , & V_11 -> V_312 , 0 ) ;
V_11 -> F_120 = V_314 ;
F_241 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_242 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_118 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_237 ( V_11 ) ;
if ( F_13 ( V_11 ) ) {
F_243 ( V_11 ) ;
}
V_11 -> F_120 = NULL ;
return 0 ;
}
static struct V_315 * F_244 ( struct V_30 * V_34 ,
struct V_315 * V_316 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_315 V_317 ;
struct V_37 * V_37 ;
int V_39 ;
memset ( V_316 , 0 , sizeof( * V_316 ) ) ;
F_245 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
const struct V_315 * V_318 =
F_246 ( V_37 -> V_15 , & V_317 ) ;
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
F_247 ( & V_11 -> V_20 ) ;
return V_316 ;
}
static int F_248 ( struct V_30 * V_34 , struct V_61 * V_62 , int V_340 )
{
struct V_30 * V_31 = NULL ;
struct V_220 V_341 ;
struct V_220 T_9 * V_342 = NULL ;
struct V_224 V_343 ;
struct V_224 T_9 * V_344 = NULL ;
struct V_63 * V_64 = NULL ;
struct V_345 * V_345 ;
int V_21 = 0 ;
F_3 ( L_100 , V_34 -> V_16 , V_340 ) ;
switch ( V_340 ) {
case V_72 :
V_64 = F_51 ( V_62 ) ;
if ( ! V_64 )
return - V_187 ;
V_64 -> V_346 = 0 ;
case V_75 :
V_64 = F_51 ( V_62 ) ;
if ( ! V_64 )
return - V_187 ;
if ( V_64 -> V_73 == 1 ) {
struct V_10 * V_11 = F_29 ( V_34 ) ;
V_64 -> V_76 = 0 ;
F_62 ( & V_11 -> V_20 ) ;
F_62 ( & V_11 -> V_86 ) ;
if ( F_42 ( V_11 -> V_15 ) )
V_64 -> V_76 = V_66 ;
F_68 ( & V_11 -> V_86 ) ;
F_68 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_347 :
case V_348 :
V_342 = (struct V_220 T_9 * ) V_62 -> V_349 ;
if ( F_249 ( & V_341 , V_342 , sizeof( V_220 ) ) )
return - V_350 ;
V_21 = F_170 ( V_34 , & V_341 ) ;
if ( V_21 == 0 &&
F_250 ( V_342 , & V_341 , sizeof( V_220 ) ) )
return - V_350 ;
return V_21 ;
case V_351 :
case V_352 :
V_344 = (struct V_224 T_9 * ) V_62 -> V_349 ;
if ( F_249 ( & V_343 , V_344 , sizeof( V_224 ) ) )
return - V_350 ;
V_21 = F_171 ( V_34 , & V_343 ) ;
if ( V_21 == 0 &&
F_250 ( V_344 , & V_343 , sizeof( V_224 ) ) )
return - V_350 ;
return V_21 ;
default:
break;
}
V_345 = F_188 ( V_34 ) ;
if ( ! F_251 ( V_345 -> V_353 , V_354 ) )
return - V_180 ;
V_31 = F_252 ( V_345 , V_62 -> V_355 ) ;
F_3 ( L_101 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_102 , V_31 -> V_16 ) ;
switch ( V_340 ) {
case V_356 :
case V_357 :
V_21 = F_134 ( V_34 , V_31 ) ;
break;
case V_358 :
case V_359 :
V_21 = F_166 ( V_34 , V_31 ) ;
break;
case V_360 :
case V_361 :
F_80 ( V_34 , V_31 ) ;
V_21 = 0 ;
break;
case V_362 :
case V_363 :
V_21 = F_169 ( V_34 , V_31 ) ;
break;
default:
V_21 = - V_190 ;
}
F_253 ( V_31 ) ;
}
return V_21 ;
}
static void F_254 ( struct V_30 * V_34 , int V_364 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_364 & V_99 )
F_53 ( V_11 ,
V_34 -> V_98 & V_99 ? 1 : - 1 ) ;
if ( V_364 & V_100 )
F_56 ( V_11 ,
V_34 -> V_98 & V_100 ? 1 : - 1 ) ;
}
static void F_255 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 ;
int V_39 ;
F_62 ( & V_11 -> V_20 ) ;
if ( F_54 ( V_11 -> V_44 . V_1 ) ) {
F_62 ( & V_11 -> V_86 ) ;
V_37 = V_11 -> V_79 ;
if ( V_37 ) {
F_77 ( V_37 -> V_15 , V_34 ) ;
F_78 ( V_37 -> V_15 , V_34 ) ;
}
F_68 ( & V_11 -> V_86 ) ;
} else {
F_30 (bond, slave, i) {
F_145 ( V_37 -> V_15 , V_34 ) ;
F_144 ( V_37 -> V_15 , V_34 ) ;
}
}
F_68 ( & V_11 -> V_20 ) ;
}
static int F_256 ( struct V_365 * V_366 )
{
struct V_10 * V_11 = F_29 ( V_366 -> V_15 ) ;
struct V_37 * V_37 = V_11 -> V_115 ;
const struct V_58 * V_59 ;
struct V_367 V_368 ;
int V_164 ;
if ( ! V_37 )
return 0 ;
V_59 = V_37 -> V_15 -> V_60 ;
if ( ! V_59 -> V_369 )
return 0 ;
V_368 . V_370 = NULL ;
V_368 . V_371 = NULL ;
V_164 = V_59 -> V_369 ( V_37 -> V_15 , & V_368 ) ;
if ( V_164 )
return V_164 ;
V_366 -> V_368 -> V_371 = V_368 . V_371 ;
if ( ! V_368 . V_370 )
return 0 ;
return V_368 . V_370 ( V_366 ) ;
}
static int F_257 ( struct V_30 * V_15 ,
struct V_367 * V_368 )
{
if ( V_368 -> V_15 == V_15 )
V_368 -> V_370 = F_256 ;
return 0 ;
}
static int F_258 ( struct V_30 * V_34 , int V_372 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_38 ;
int V_21 = 0 ;
int V_39 ;
F_3 ( L_103 , V_11 ,
( V_34 ? V_34 -> V_16 : L_10 ) , V_372 ) ;
F_30 (bond, slave, i) {
F_3 ( L_104 ,
V_37 ,
V_37 -> V_27 ,
V_37 -> V_15 -> V_60 -> V_373 ) ;
V_21 = F_140 ( V_37 -> V_15 , V_372 ) ;
if ( V_21 ) {
F_3 ( L_105 , V_21 , V_37 -> V_15 -> V_16 ) ;
goto V_40;
}
}
V_34 -> V_195 = V_372 ;
return 0 ;
V_40:
V_38 = V_37 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_374 ;
V_374 = F_140 ( V_37 -> V_15 , V_34 -> V_195 ) ;
if ( V_374 ) {
F_3 ( L_106 ,
V_374 , V_37 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_259 ( struct V_30 * V_34 , void * V_177 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_176 * V_375 = V_177 , V_376 ;
struct V_37 * V_37 , * V_38 ;
int V_21 = 0 ;
int V_39 ;
if ( V_11 -> V_44 . V_1 == V_9 )
return F_260 ( V_34 , V_177 ) ;
F_3 ( L_107 ,
V_11 , V_34 ? V_34 -> V_16 : L_10 ) ;
if ( V_11 -> V_44 . V_124 )
return 0 ;
if ( ! F_261 ( V_375 -> V_198 ) )
return - V_377 ;
F_30 (bond, slave, i) {
const struct V_58 * V_59 = V_37 -> V_15 -> V_60 ;
F_3 ( L_108 , V_37 , V_37 -> V_15 -> V_16 ) ;
if ( V_59 -> V_188 == NULL ) {
V_21 = - V_190 ;
F_3 ( L_109 , V_37 -> V_15 -> V_16 ) ;
goto V_40;
}
V_21 = F_141 ( V_37 -> V_15 , V_177 ) ;
if ( V_21 ) {
F_3 ( L_105 , V_21 , V_37 -> V_15 -> V_16 ) ;
goto V_40;
}
}
memcpy ( V_34 -> V_102 , V_375 -> V_198 , V_34 -> V_101 ) ;
return 0 ;
V_40:
memcpy ( V_376 . V_198 , V_34 -> V_102 , V_34 -> V_101 ) ;
V_376 . V_199 = V_34 -> type ;
V_38 = V_37 ;
F_33 (bond, slave, i, bond->first_slave, stop_at) {
int V_374 ;
V_374 = F_141 ( V_37 -> V_15 , & V_376 ) ;
if ( V_374 ) {
F_3 ( L_106 ,
V_374 , V_37 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_262 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_378 ;
int V_39 , V_379 , V_21 = 1 ;
struct V_292 * V_293 = F_225 ( V_29 ) ;
if ( ( V_293 -> V_256 == V_380 ) &&
( V_29 -> V_256 == F_37 ( V_263 ) ) ) {
F_62 ( & V_11 -> V_86 ) ;
V_37 = V_11 -> V_79 ;
F_68 ( & V_11 -> V_86 ) ;
if ( ! V_37 )
goto V_23;
} else {
V_379 = V_11 -> V_381 ++ % V_11 -> V_42 ;
F_30 (bond, slave, i) {
V_379 -- ;
if ( V_379 < 0 )
break;
}
}
V_378 = V_37 ;
F_85 (bond, slave, i, start_at) {
if ( F_86 ( V_37 -> V_15 ) &&
( V_37 -> V_45 == V_46 ) &&
F_155 ( V_37 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_37 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_127 ( V_29 ) ;
}
return V_382 ;
}
static int F_263 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
int V_21 = 1 ;
F_62 ( & V_11 -> V_86 ) ;
if ( V_11 -> V_79 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_79 -> V_15 ) ;
F_68 ( & V_11 -> V_86 ) ;
if ( V_21 )
F_127 ( V_29 ) ;
return V_382 ;
}
static int F_264 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_378 ;
int V_379 ;
int V_39 ;
int V_21 = 1 ;
V_379 = V_11 -> V_383 ( V_29 , V_11 -> V_42 ) ;
F_30 (bond, slave, i) {
V_379 -- ;
if ( V_379 < 0 )
break;
}
V_378 = V_37 ;
F_85 (bond, slave, i, start_at) {
if ( F_86 ( V_37 -> V_15 ) &&
( V_37 -> V_45 == V_46 ) &&
F_155 ( V_37 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_37 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_127 ( V_29 ) ;
}
return V_382 ;
}
static int F_265 ( struct V_28 * V_29 , struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 , * V_378 ;
struct V_30 * V_384 = NULL ;
int V_39 ;
int V_21 = 1 ;
F_62 ( & V_11 -> V_86 ) ;
V_378 = V_11 -> V_79 ;
F_68 ( & V_11 -> V_86 ) ;
if ( ! V_378 )
goto V_23;
F_85 (bond, slave, i, start_at) {
if ( F_86 ( V_37 -> V_15 ) &&
( V_37 -> V_45 == V_46 ) &&
F_155 ( V_37 ) ) {
if ( V_384 ) {
struct V_28 * V_385 = F_266 ( V_29 , V_134 ) ;
if ( ! V_385 ) {
F_32 ( L_110 ,
V_34 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_385 , V_384 ) ;
if ( V_21 ) {
F_127 ( V_385 ) ;
continue;
}
}
V_384 = V_37 -> V_15 ;
}
}
if ( V_384 )
V_21 = F_20 ( V_11 , V_29 , V_384 ) ;
V_23:
if ( V_21 )
F_127 ( V_29 ) ;
return V_382 ;
}
static void F_267 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_44 . V_386 ) {
case V_387 :
V_11 -> V_383 = F_223 ;
break;
case V_388 :
V_11 -> V_383 = F_228 ;
break;
case V_389 :
default:
V_11 -> V_383 = F_221 ;
break;
}
}
static inline int F_268 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_39 , V_21 = 1 ;
struct V_37 * V_37 = NULL ;
struct V_37 * V_390 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_30 (bond, check_slave, i) {
if ( V_390 -> V_193 == V_29 -> V_32 ) {
V_37 = V_390 ;
break;
}
}
if ( V_37 && V_37 -> V_193 && F_86 ( V_37 -> V_15 ) &&
( V_37 -> V_45 == V_46 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_37 -> V_15 ) ;
}
return V_21 ;
}
static T_2 F_269 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_2 V_391 = F_270 ( V_29 ) ? F_271 ( V_29 ) : 0 ;
F_22 ( V_29 ) -> V_33 = V_29 -> V_32 ;
if ( F_23 ( V_391 >= V_15 -> V_392 ) ) {
do {
V_391 -= V_15 -> V_392 ;
} while ( V_391 >= V_15 -> V_392 );
}
return V_391 ;
}
static T_10 F_272 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
if ( F_273 ( V_11 -> V_44 . V_1 ) ) {
if ( ! F_268 ( V_11 , V_29 ) )
return V_382 ;
}
switch ( V_11 -> V_44 . V_1 ) {
case V_3 :
return F_262 ( V_29 , V_15 ) ;
case V_4 :
return F_263 ( V_29 , V_15 ) ;
case V_5 :
return F_264 ( V_29 , V_15 ) ;
case V_6 :
return F_265 ( V_29 , V_15 ) ;
case V_7 :
return F_274 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_275 ( V_29 , V_15 ) ;
default:
F_32 ( L_111 ,
V_15 -> V_16 , V_11 -> V_44 . V_1 ) ;
F_276 ( 1 ) ;
F_127 ( V_29 ) ;
return V_382 ;
}
}
static T_10 F_277 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_29 ( V_15 ) ;
T_10 V_164 = V_382 ;
if ( F_278 ( V_15 ) )
return V_393 ;
F_62 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_42 )
V_164 = F_272 ( V_29 , V_15 ) ;
else
F_127 ( V_29 ) ;
F_68 ( & V_11 -> V_20 ) ;
return V_164 ;
}
void F_279 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_34 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_267 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_267 ( V_11 ) ;
break;
case V_9 :
case V_8 :
break;
default:
F_32 ( L_111 ,
V_34 -> V_16 , V_1 ) ;
break;
}
}
static int F_280 ( struct V_30 * V_34 ,
struct V_47 * V_48 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_37 * V_37 ;
int V_39 ;
unsigned long V_50 = 0 ;
V_48 -> V_52 = V_53 ;
V_48 -> V_394 = V_395 ;
F_62 ( & V_11 -> V_20 ) ;
F_30 (bond, slave, i) {
if ( F_281 ( V_37 ) ) {
if ( V_37 -> V_50 != V_51 )
V_50 += V_37 -> V_50 ;
if ( V_48 -> V_52 == V_53 &&
V_37 -> V_52 != V_53 )
V_48 -> V_52 = V_37 -> V_52 ;
}
}
F_282 ( V_48 , V_50 ? : V_51 ) ;
F_68 ( & V_11 -> V_20 ) ;
return 0 ;
}
static void F_283 ( struct V_30 * V_34 ,
struct V_396 * V_397 )
{
F_284 ( V_397 -> V_398 , V_399 , sizeof( V_397 -> V_398 ) ) ;
F_284 ( V_397 -> V_400 , V_401 , sizeof( V_397 -> V_400 ) ) ;
snprintf ( V_397 -> V_402 , sizeof( V_397 -> V_402 ) , L_112 ,
V_403 ) ;
}
static void F_285 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
if ( V_11 -> V_88 )
F_286 ( V_11 -> V_88 ) ;
F_287 ( V_34 ) ;
}
static void F_288 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
F_289 ( & V_11 -> V_20 ) ;
F_289 ( & V_11 -> V_86 ) ;
V_11 -> V_44 = V_404 ;
V_11 -> V_15 = V_34 ;
F_5 ( & V_11 -> V_19 ) ;
F_139 ( V_34 ) ;
V_34 -> V_60 = & V_405 ;
V_34 -> V_67 = & V_406 ;
F_279 ( V_11 , V_11 -> V_44 . V_1 ) ;
V_34 -> V_407 = F_285 ;
F_290 ( V_34 , & V_408 ) ;
V_34 -> V_409 = 0 ;
V_34 -> V_98 |= V_287 | V_410 ;
V_34 -> V_84 |= V_203 ;
V_34 -> V_84 &= ~ ( V_155 | V_185 ) ;
V_34 -> V_141 |= V_143 ;
V_34 -> V_141 |= V_411 ;
V_34 -> V_412 = V_147 |
V_413 |
V_414 |
V_415 ;
V_34 -> V_412 &= ~ ( V_416 & ~ V_417 ) ;
V_34 -> V_141 |= V_34 -> V_412 ;
}
static void F_291 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_13 * V_14 , * V_418 ;
F_106 ( V_34 ) ;
while ( V_11 -> V_115 != NULL )
F_160 ( V_34 , V_11 -> V_115 -> V_15 , true ) ;
F_90 ( L_113 , V_34 -> V_16 ) ;
F_12 ( & V_11 -> V_419 ) ;
F_292 ( V_11 ) ;
F_293 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_294 ( const char * V_420 , const struct V_421 * V_422 )
{
int V_423 = - 1 , V_39 , V_130 ;
char * V_424 , V_425 [ V_426 + 1 ] = { 0 , } ;
for ( V_424 = ( char * ) V_420 ; * V_424 ; V_424 ++ )
if ( ! ( isdigit ( * V_424 ) || isspace ( * V_424 ) ) )
break;
if ( * V_424 )
V_130 = sscanf ( V_420 , L_114 , V_425 ) ;
else
V_130 = sscanf ( V_420 , L_112 , & V_423 ) ;
if ( ! V_130 )
return - 1 ;
for ( V_39 = 0 ; V_422 [ V_39 ] . V_427 ; V_39 ++ ) {
if ( V_423 == V_422 [ V_39 ] . V_1 )
return V_422 [ V_39 ] . V_1 ;
if ( strcmp ( V_425 , V_422 [ V_39 ] . V_427 ) == 0 )
return V_422 [ V_39 ] . V_1 ;
}
return - 1 ;
}
static int F_295 ( struct V_428 * V_44 )
{
int V_429 , V_430 , V_431 , V_39 ;
int V_432 ;
if ( V_1 ) {
V_222 = F_294 ( V_1 , V_433 ) ;
if ( V_222 == - 1 ) {
F_32 ( L_115 ,
V_1 == NULL ? L_19 : V_1 ) ;
return - V_187 ;
}
}
if ( V_383 ) {
if ( ( V_222 != V_5 ) &&
( V_222 != V_7 ) ) {
F_90 ( L_116 ,
F_1 ( V_222 ) ) ;
} else {
V_434 = F_294 ( V_383 ,
V_435 ) ;
if ( V_434 == - 1 ) {
F_32 ( L_117 ,
V_383 == NULL ? L_19 :
V_383 ) ;
return - V_187 ;
}
}
}
if ( V_436 ) {
if ( V_222 != V_7 ) {
F_90 ( L_118 ,
F_1 ( V_222 ) ) ;
} else {
V_437 = F_294 ( V_436 , V_438 ) ;
if ( V_437 == - 1 ) {
F_32 ( L_119 ,
V_436 == NULL ? L_19 : V_436 ) ;
return - V_187 ;
}
}
}
if ( V_439 ) {
V_44 -> V_439 = F_294 ( V_439 , V_440 ) ;
if ( V_44 -> V_439 == - 1 ) {
F_32 ( L_120 ,
V_439 == NULL ? L_19 : V_439 ) ;
return - V_187 ;
}
if ( V_222 != V_7 ) {
F_38 ( L_121 ) ;
}
} else {
V_44 -> V_439 = V_441 ;
}
if ( V_442 < 0 ) {
F_38 ( L_122 ,
V_442 , 0 , V_443 , V_444 ) ;
V_442 = V_444 ;
}
if ( V_122 < 0 ) {
F_38 ( L_123 ,
V_122 , V_443 , V_445 ) ;
V_122 = V_445 ;
}
if ( V_114 < 0 ) {
F_38 ( L_124 ,
V_114 , V_443 ) ;
V_114 = 0 ;
}
if ( V_233 < 0 ) {
F_38 ( L_125 ,
V_233 , V_443 ) ;
V_233 = 0 ;
}
if ( ( V_65 != 0 ) && ( V_65 != 1 ) ) {
F_38 ( L_126 ,
V_65 ) ;
V_65 = 1 ;
}
if ( V_125 < 0 || V_125 > 255 ) {
F_38 ( L_127 ,
V_125 ) ;
V_125 = 1 ;
}
if ( V_222 == V_7 ) {
if ( ! V_122 ) {
F_38 ( L_128 ) ;
F_38 ( L_129 ) ;
V_122 = 100 ;
}
}
if ( V_446 < 1 || V_446 > 255 ) {
F_38 ( L_130
L_131 ,
V_446 , V_447 ) ;
V_446 = V_447 ;
}
if ( ( V_448 != 0 ) && ( V_448 != 1 ) ) {
F_38 ( L_132
L_133
L_134 , V_448 ) ;
V_448 = 0 ;
}
if ( V_128 < 0 || V_128 > 255 ) {
F_38 ( L_135
L_136 ,
V_128 , V_449 ) ;
V_128 = V_449 ;
}
if ( ( V_222 == V_8 ) ||
( V_222 == V_9 ) ) {
if ( ! V_122 ) {
F_38 ( L_137 ) ;
F_38 ( L_129 ) ;
V_122 = 100 ;
}
}
if ( V_222 == V_9 ) {
F_296 ( L_138 ,
V_114 ) ;
}
if ( ! V_122 ) {
if ( V_114 || V_233 ) {
F_38 ( L_139 ,
V_114 , V_233 ) ;
}
} else {
if ( V_167 ) {
F_38 ( L_140 ,
V_122 , V_167 ) ;
V_167 = 0 ;
}
if ( ( V_114 % V_122 ) != 0 ) {
F_38 ( L_141 ,
V_114 , V_122 ,
( V_114 / V_122 ) * V_122 ) ;
}
V_114 /= V_122 ;
if ( ( V_233 % V_122 ) != 0 ) {
F_38 ( L_142 ,
V_233 , V_122 ,
( V_233 / V_122 ) * V_122 ) ;
}
V_233 /= V_122 ;
}
if ( V_167 < 0 ) {
F_38 ( L_143 ,
V_167 , V_443 , V_450 ) ;
V_167 = V_450 ;
}
for ( V_451 = 0 , V_39 = 0 ;
( V_451 < V_207 ) && V_452 [ V_39 ] ; V_39 ++ ) {
T_8 V_238 = F_297 ( V_452 [ V_39 ] ) ;
if ( ! isdigit ( V_452 [ V_39 ] [ 0 ] ) || V_238 == 0 ||
V_238 == F_298 ( V_453 ) ) {
F_38 ( L_144 ,
V_452 [ V_39 ] ) ;
V_167 = 0 ;
} else {
if ( F_193 ( V_454 , V_238 ) == - 1 )
V_454 [ V_451 ++ ] = V_238 ;
else
F_38 ( L_145 ,
& V_238 ) ;
}
}
if ( V_167 && ! V_451 ) {
F_38 ( L_146 ,
V_167 ) ;
V_167 = 0 ;
}
if ( V_265 ) {
if ( V_222 != V_4 ) {
F_32 ( L_147 ) ;
return - V_187 ;
}
if ( ! V_167 ) {
F_32 ( L_148 ) ;
return - V_187 ;
}
V_429 = F_294 ( V_265 ,
V_455 ) ;
if ( V_429 == - 1 ) {
F_32 ( L_149 ,
V_265 == NULL ? L_19 : V_265 ) ;
return - V_187 ;
}
} else
V_429 = 0 ;
V_432 = 0 ;
if ( V_456 ) {
V_432 = F_294 ( V_456 ,
V_457 ) ;
if ( V_432 == - 1 ) {
F_32 ( L_150 ,
V_456 ) ;
V_432 = 0 ;
}
}
if ( V_122 ) {
F_90 ( L_151 , V_122 ) ;
} else if ( V_167 ) {
F_90 ( L_152 ,
V_167 ,
V_455 [ V_429 ] . V_427 ,
V_451 ) ;
for ( V_39 = 0 ; V_39 < V_451 ; V_39 ++ )
F_90 ( L_153 , V_452 [ V_39 ] ) ;
F_90 ( L_154 ) ;
} else if ( V_442 ) {
F_3 ( L_155 ) ;
}
if ( V_210 && ! F_54 ( V_222 ) ) {
F_38 ( L_156 ,
V_210 , F_1 ( V_222 ) ) ;
V_210 = NULL ;
}
if ( V_210 && V_109 ) {
V_431 = F_294 ( V_109 ,
V_458 ) ;
if ( V_431 == - 1 ) {
F_32 ( L_157 ,
V_109 ==
NULL ? L_19 : V_109 ) ;
return - V_187 ;
}
} else {
V_431 = V_459 ;
}
if ( V_124 ) {
V_430 = F_294 ( V_124 ,
V_460 ) ;
if ( V_430 == - 1 ) {
F_32 ( L_158 ,
V_265 == NULL ? L_19 : V_265 ) ;
return - V_187 ;
}
if ( V_222 != V_4 )
F_38 ( L_159 ) ;
} else {
V_430 = V_461 ;
}
V_44 -> V_1 = V_222 ;
V_44 -> V_386 = V_434 ;
V_44 -> V_122 = V_122 ;
V_44 -> V_125 = V_125 ;
V_44 -> V_167 = V_167 ;
V_44 -> V_265 = V_429 ;
V_44 -> V_456 = V_432 ;
V_44 -> V_114 = V_114 ;
V_44 -> V_233 = V_233 ;
V_44 -> V_65 = V_65 ;
V_44 -> V_437 = V_437 ;
V_44 -> V_210 [ 0 ] = 0 ;
V_44 -> V_109 = V_431 ;
V_44 -> V_124 = V_430 ;
V_44 -> V_446 = V_446 ;
V_44 -> V_448 = V_448 ;
V_44 -> V_128 = V_128 ;
V_44 -> V_462 = V_462 ;
if ( V_210 ) {
strncpy ( V_44 -> V_210 , V_210 , V_71 ) ;
V_44 -> V_210 [ V_71 - 1 ] = 0 ;
}
memcpy ( V_44 -> V_244 , V_454 , sizeof( V_454 ) ) ;
return 0 ;
}
static void F_299 ( struct V_30 * V_15 ,
struct V_463 * V_391 ,
void * V_464 )
{
F_300 ( & V_391 -> V_465 ,
& V_466 ) ;
}
static void F_301 ( struct V_30 * V_15 )
{
F_300 ( & V_15 -> V_467 ,
& V_468 ) ;
F_302 ( V_15 , F_299 , NULL ) ;
V_15 -> V_469 = & V_470 ;
}
static int F_303 ( struct V_30 * V_34 )
{
struct V_10 * V_11 = F_29 ( V_34 ) ;
struct V_471 * V_472 = F_304 ( F_188 ( V_34 ) , V_473 ) ;
struct V_474 * V_475 = & ( F_305 ( V_11 ) ) ;
F_3 ( L_160 , V_34 -> V_16 ) ;
F_306 ( & ( V_475 -> V_476 ) ) ;
F_306 ( & ( V_475 -> V_477 ) ) ;
V_11 -> V_88 = F_307 ( V_34 -> V_16 ) ;
if ( ! V_11 -> V_88 )
return - V_18 ;
F_301 ( V_34 ) ;
F_7 ( & V_11 -> V_419 , & V_472 -> V_478 ) ;
F_308 ( V_11 ) ;
F_309 ( V_11 ) ;
if ( F_310 ( V_34 -> V_102 ) &&
V_34 -> V_103 == V_479 )
F_159 ( V_34 ) ;
return 0 ;
}
static int F_311 ( struct V_480 * V_481 [] , struct V_480 * V_172 [] )
{
if ( V_481 [ V_482 ] ) {
if ( F_312 ( V_481 [ V_482 ] ) != V_94 )
return - V_187 ;
if ( ! F_261 ( F_313 ( V_481 [ V_482 ] ) ) )
return - V_377 ;
}
return 0 ;
}
static unsigned int F_314 ( void )
{
return V_446 ;
}
int F_315 ( struct V_345 * V_345 , const char * V_16 )
{
struct V_30 * V_34 ;
int V_21 ;
F_316 () ;
V_34 = F_317 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_161 ,
F_288 , V_446 ) ;
if ( ! V_34 ) {
F_32 ( L_162 , V_16 ) ;
F_179 () ;
return - V_18 ;
}
F_318 ( V_34 , V_345 ) ;
V_34 -> V_483 = & V_484 ;
V_21 = F_319 ( V_34 ) ;
F_44 ( V_34 ) ;
F_179 () ;
if ( V_21 < 0 )
F_285 ( V_34 ) ;
return V_21 ;
}
static int T_11 F_320 ( struct V_345 * V_345 )
{
struct V_471 * V_472 = F_304 ( V_345 , V_473 ) ;
V_472 -> V_345 = V_345 ;
F_5 ( & V_472 -> V_478 ) ;
F_321 ( V_472 ) ;
F_322 ( V_472 ) ;
return 0 ;
}
static void T_12 F_323 ( struct V_345 * V_345 )
{
struct V_471 * V_472 = F_304 ( V_345 , V_473 ) ;
struct V_10 * V_11 , * V_485 ;
F_324 ( V_486 ) ;
F_325 ( V_472 ) ;
F_326 ( V_472 ) ;
F_316 () ;
F_293 (bond, tmp_bond, &bn->dev_list, bond_list)
F_327 ( V_11 -> V_15 , & V_486 ) ;
F_328 ( & V_486 ) ;
F_179 () ;
}
static int T_13 F_329 ( void )
{
int V_39 ;
int V_21 ;
F_90 ( L_163 , V_487 ) ;
V_21 = F_295 ( & V_404 ) ;
if ( V_21 )
goto V_23;
V_21 = F_330 ( & V_488 ) ;
if ( V_21 )
goto V_23;
V_21 = F_331 ( & V_484 ) ;
if ( V_21 )
goto V_489;
F_332 () ;
for ( V_39 = 0 ; V_39 < V_442 ; V_39 ++ ) {
V_21 = F_315 ( & V_490 , NULL ) ;
if ( V_21 )
goto V_78;
}
F_333 ( & V_491 ) ;
V_23:
return V_21 ;
V_78:
F_334 ( & V_484 ) ;
V_489:
F_335 ( & V_488 ) ;
goto V_23;
}
static void T_14 F_336 ( void )
{
F_337 ( & V_491 ) ;
F_338 () ;
F_334 ( & V_484 ) ;
F_335 ( & V_488 ) ;
#ifdef F_152
F_339 ( F_340 ( & V_492 ) ) ;
#endif
}
