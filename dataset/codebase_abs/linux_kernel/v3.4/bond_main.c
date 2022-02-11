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
struct V_30 * V_33 , * V_80 , * V_81 ;
struct V_13 * V_14 ;
F_66 ( & V_11 -> V_20 ) ;
V_33 = V_11 -> V_15 ;
F_60 ( V_33 ) ;
V_81 = V_33 -> V_82 ;
if ( V_81 )
if ( ( V_81 -> V_83 & V_84 )
&& ( V_33 -> V_83 & V_85 ) )
F_60 ( V_81 ) ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_61 () ;
V_80 = F_67 ( V_33 ,
V_14 -> V_12 ) ;
F_64 () ;
if ( V_80 )
F_60 ( V_80 ) ;
}
if ( -- V_11 -> V_86 > 0 )
F_68 ( V_11 -> V_87 , & V_11 -> V_88 , V_89 / 5 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
static void F_70 ( struct V_90 * V_91 )
{
struct V_10 * V_11 = F_71 ( V_91 , struct V_10 ,
V_88 . V_91 ) ;
F_65 ( V_11 ) ;
}
static void F_72 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_92 * V_93 ;
F_73 (ha, bond_dev)
F_59 ( V_31 , V_93 -> V_77 ) ;
if ( V_11 -> V_41 . V_1 == V_7 ) {
T_3 V_94 [ V_95 ] = V_96 ;
F_59 ( V_31 , V_94 ) ;
}
}
static void F_74 ( struct V_10 * V_11 , struct V_35 * V_97 ,
struct V_35 * V_98 )
{
struct V_92 * V_93 ;
if ( ! F_52 ( V_11 -> V_41 . V_1 ) )
return;
if ( V_98 ) {
if ( V_11 -> V_15 -> V_99 & V_100 )
F_53 ( V_98 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_99 & V_101 )
F_55 ( V_98 -> V_15 , - 1 ) ;
F_73 (ha, bond->dev)
F_59 ( V_98 -> V_15 , V_93 -> V_77 ) ;
}
if ( V_97 ) {
if ( V_11 -> V_15 -> V_99 & V_100 )
F_53 ( V_97 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_99 & V_101 )
F_55 ( V_97 -> V_15 , 1 ) ;
F_73 (ha, bond->dev)
F_57 ( V_97 -> V_15 , V_93 -> V_77 ) ;
}
}
static void F_75 ( struct V_10 * V_11 ,
struct V_35 * V_97 ,
struct V_35 * V_98 )
__releases( &bond->curr_slave_lock
static bool F_76 ( struct V_10 * V_11 )
{
struct V_35 * V_102 = V_11 -> V_103 ;
struct V_35 * V_24 = V_11 -> V_76 ;
if ( ! V_102 || ! V_24 || V_24 -> V_42 != V_43 )
return true ;
if ( V_11 -> V_104 ) {
V_11 -> V_104 = false ;
return true ;
}
if ( V_11 -> V_41 . V_105 == V_106 &&
( V_102 -> V_47 < V_24 -> V_47 ||
( V_102 -> V_47 == V_24 -> V_47 && V_102 -> V_49 <= V_24 -> V_49 ) ) )
return false ;
if ( V_11 -> V_41 . V_105 == V_107 )
return false ;
return true ;
}
static struct V_35 * F_77 ( struct V_10 * V_11 )
{
struct V_35 * V_97 , * V_98 ;
struct V_35 * V_108 = NULL ;
int V_109 = V_11 -> V_41 . V_110 ;
int V_37 ;
V_97 = V_11 -> V_76 ;
if ( ! V_97 ) {
if ( V_11 -> V_39 > 0 )
V_97 = V_11 -> V_111 ;
else
return NULL ;
}
if ( ( V_11 -> V_103 ) &&
V_11 -> V_103 -> V_42 == V_43 &&
F_76 ( V_11 ) ) {
V_97 = V_11 -> V_103 ;
}
V_98 = V_97 ;
F_78 (bond, new_active, i, old_active) {
if ( V_97 -> V_42 == V_43 ) {
return V_97 ;
} else if ( V_97 -> V_42 == V_112 &&
F_79 ( V_97 -> V_15 ) ) {
if ( V_97 -> V_113 < V_109 ) {
V_109 = V_97 -> V_113 ;
V_108 = V_97 ;
}
}
}
return V_108 ;
}
static bool F_80 ( struct V_10 * V_11 )
{
struct V_35 * V_35 = V_11 -> V_76 ;
F_3 ( L_17 ,
V_11 -> V_15 -> V_16 , V_35 ? V_35 -> V_15 -> V_16 : L_18 ) ;
if ( ! V_35 || ! V_11 -> V_114 ||
F_81 ( V_115 , & V_35 -> V_15 -> V_116 ) )
return false ;
V_11 -> V_114 -- ;
return true ;
}
void F_82 ( struct V_10 * V_11 , struct V_35 * V_97 )
{
struct V_35 * V_98 = V_11 -> V_76 ;
if ( V_98 == V_97 )
return;
if ( V_97 ) {
V_97 -> V_117 = V_117 ;
if ( V_97 -> V_42 == V_112 ) {
if ( F_52 ( V_11 -> V_41 . V_1 ) ) {
F_83 ( L_19 ,
V_11 -> V_15 -> V_16 , V_97 -> V_15 -> V_16 ,
( V_11 -> V_41 . V_110 - V_97 -> V_113 ) * V_11 -> V_41 . V_118 ) ;
}
V_97 -> V_113 = 0 ;
V_97 -> V_42 = V_43 ;
if ( V_11 -> V_41 . V_1 == V_7 )
F_84 ( V_97 , V_43 ) ;
if ( F_13 ( V_11 ) )
F_85 ( V_11 , V_97 , V_43 ) ;
} else {
if ( F_52 ( V_11 -> V_41 . V_1 ) ) {
F_83 ( L_20 ,
V_11 -> V_15 -> V_16 , V_97 -> V_15 -> V_16 ) ;
}
}
}
if ( F_52 ( V_11 -> V_41 . V_1 ) )
F_74 ( V_11 , V_97 , V_98 ) ;
if ( F_13 ( V_11 ) ) {
F_86 ( V_11 , V_97 ) ;
if ( V_98 )
F_87 ( V_98 ) ;
if ( V_97 )
F_88 ( V_97 ) ;
} else {
V_11 -> V_76 = V_97 ;
}
if ( V_11 -> V_41 . V_1 == V_4 ) {
if ( V_98 )
F_87 ( V_98 ) ;
if ( V_97 ) {
bool V_119 = false ;
F_88 ( V_97 ) ;
if ( V_11 -> V_41 . V_120 )
F_75 ( V_11 , V_97 ,
V_98 ) ;
if ( F_48 ( V_11 -> V_15 ) ) {
V_11 -> V_114 =
V_11 -> V_41 . V_121 ;
V_119 =
F_80 ( V_11 ) ;
}
F_8 ( & V_11 -> V_122 ) ;
F_69 ( & V_11 -> V_20 ) ;
F_89 ( V_11 -> V_15 , V_123 ) ;
if ( V_119 )
F_89 ( V_11 -> V_15 ,
V_124 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_122 ) ;
}
}
if ( F_48 ( V_11 -> V_15 ) && ( V_11 -> V_41 . V_125 > 0 ) &&
( ( F_52 ( V_11 -> V_41 . V_1 ) && V_97 ) ||
V_11 -> V_41 . V_1 == V_3 ) ) {
V_11 -> V_86 = V_11 -> V_41 . V_125 ;
F_68 ( V_11 -> V_87 , & V_11 -> V_88 , 0 ) ;
}
}
void F_90 ( struct V_10 * V_11 )
{
struct V_35 * V_126 ;
int V_127 ;
V_126 = F_77 ( V_11 ) ;
if ( V_126 != V_11 -> V_76 ) {
F_82 ( V_11 , V_126 ) ;
V_127 = F_38 ( V_11 ) ;
if ( ! V_127 )
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
static void F_91 ( struct V_10 * V_11 , struct V_35 * V_128 )
{
if ( V_11 -> V_111 == NULL ) {
V_128 -> V_25 = V_128 ;
V_128 -> V_27 = V_128 ;
V_11 -> V_111 = V_128 ;
} else {
V_128 -> V_25 = V_11 -> V_111 ;
V_128 -> V_27 = V_11 -> V_111 -> V_27 ;
V_128 -> V_25 -> V_27 = V_128 ;
V_128 -> V_27 -> V_25 = V_128 ;
}
V_11 -> V_39 ++ ;
}
static void F_92 ( struct V_10 * V_11 , struct V_35 * V_35 )
{
if ( V_35 -> V_25 )
V_35 -> V_25 -> V_27 = V_35 -> V_27 ;
if ( V_35 -> V_27 )
V_35 -> V_27 -> V_25 = V_35 -> V_25 ;
if ( V_11 -> V_111 == V_35 ) {
if ( V_11 -> V_39 > 1 ) {
V_11 -> V_111 = V_35 -> V_25 ;
} else {
V_11 -> V_111 = NULL ;
}
}
V_35 -> V_25 = NULL ;
V_35 -> V_27 = NULL ;
V_11 -> V_39 -- ;
}
static inline int F_93 ( struct V_35 * V_35 )
{
struct V_129 * V_130 ;
int V_75 = 0 ;
V_130 = F_4 ( sizeof( * V_130 ) , V_17 ) ;
V_75 = - V_18 ;
if ( ! V_130 )
goto V_23;
V_130 -> V_15 = V_35 -> V_15 ;
F_94 ( V_130 -> V_131 , V_35 -> V_15 -> V_16 , V_68 ) ;
V_75 = F_95 ( V_130 ) ;
if ( V_75 ) {
F_15 ( V_130 ) ;
goto V_23;
}
V_35 -> V_130 = V_130 ;
V_23:
return V_75 ;
}
static inline void F_96 ( struct V_35 * V_35 )
{
struct V_129 * V_130 = V_35 -> V_130 ;
if ( ! V_130 )
return;
V_35 -> V_130 = NULL ;
F_97 () ;
F_98 ( V_130 ) ;
F_15 ( V_130 ) ;
}
static inline bool F_99 ( struct V_30 * V_31 )
{
if ( V_31 -> V_83 & V_132 )
return false ;
if ( ! V_31 -> V_57 -> V_133 )
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
static int F_103 ( struct V_30 * V_15 , struct V_134 * V_135 )
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
static struct V_134 * F_104 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_136 ;
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
F_3 ( L_25 , V_31 -> V_137 ) ;
memcpy ( V_33 -> V_138 , V_31 -> V_138 , V_31 -> V_137 ) ;
return 0 ;
}
static T_4 F_106 ( struct V_30 * V_15 ,
T_4 V_139 )
{
struct V_35 * V_35 ;
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_4 V_140 ;
int V_37 ;
F_66 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_111 ) {
V_139 |= V_141 ;
goto V_23;
}
V_140 = V_139 ;
V_139 &= ~ V_142 ;
V_139 |= V_143 ;
F_29 (bond, slave, i) {
V_139 = F_107 ( V_139 ,
V_35 -> V_15 -> V_139 ,
V_140 ) ;
}
V_23:
F_69 ( & V_11 -> V_20 ) ;
return V_139 ;
}
static void F_108 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
struct V_30 * V_33 = V_11 -> V_15 ;
T_4 V_144 = V_145 ;
unsigned short V_146 = V_147 ;
int V_37 ;
F_66 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_111 )
goto V_148;
F_29 (bond, slave, i) {
V_144 = F_107 ( V_144 ,
V_35 -> V_15 -> V_144 , V_145 ) ;
if ( V_35 -> V_15 -> V_149 > V_146 )
V_146 = V_35 -> V_15 -> V_149 ;
}
V_148:
V_33 -> V_144 = V_144 ;
V_33 -> V_149 = V_146 ;
F_69 ( & V_11 -> V_20 ) ;
F_109 ( V_33 ) ;
}
static void F_110 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_33 -> V_150 = V_31 -> V_150 ;
V_33 -> type = V_31 -> type ;
V_33 -> V_149 = V_31 -> V_149 ;
V_33 -> V_137 = V_31 -> V_137 ;
memcpy ( V_33 -> V_151 , V_31 -> V_151 ,
V_31 -> V_137 ) ;
V_11 -> V_152 = 1 ;
}
static bool F_111 ( struct V_28 * V_29 ,
struct V_35 * V_35 ,
struct V_10 * V_11 )
{
if ( F_112 ( V_35 ) ) {
if ( V_11 -> V_41 . V_1 == V_9 &&
V_29 -> V_153 != V_154 &&
V_29 -> V_153 != V_155 )
return false ;
return true ;
}
return false ;
}
static T_5 F_113 ( struct V_28 * * V_156 )
{
struct V_28 * V_29 = * V_156 ;
struct V_35 * V_35 ;
struct V_10 * V_11 ;
int (* F_114)( struct V_28 * , struct V_10 * ,
struct V_35 * );
int V_157 = V_158 ;
V_29 = F_115 ( V_29 , V_159 ) ;
if ( F_22 ( ! V_29 ) )
return V_160 ;
* V_156 = V_29 ;
V_35 = F_116 ( V_29 -> V_15 ) ;
V_11 = V_35 -> V_11 ;
if ( V_11 -> V_41 . V_161 )
V_35 -> V_15 -> V_162 = V_117 ;
F_114 = F_117 ( V_11 -> F_114 ) ;
if ( F_114 ) {
struct V_28 * V_163 = F_118 ( V_29 , V_159 ) ;
if ( F_119 ( V_163 ) ) {
V_157 = F_114 ( V_163 , V_11 , V_35 ) ;
F_120 ( V_163 ) ;
if ( V_157 == V_160 ) {
F_121 ( V_29 ) ;
return V_157 ;
}
}
}
if ( F_111 ( V_29 , V_35 , V_11 ) ) {
return V_164 ;
}
V_29 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_41 . V_1 == V_9 &&
V_11 -> V_15 -> V_83 & V_85 &&
V_29 -> V_153 == V_165 ) {
if ( F_22 ( F_122 ( V_29 ,
V_29 -> V_166 - F_123 ( V_29 ) ) ) ) {
F_124 ( V_29 ) ;
return V_160 ;
}
memcpy ( F_125 ( V_29 ) -> V_167 , V_11 -> V_15 -> V_138 , V_95 ) ;
}
return V_157 ;
}
int F_126 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
const struct V_55 * V_56 = V_31 -> V_57 ;
struct V_35 * V_128 = NULL ;
struct V_92 * V_93 ;
struct V_168 V_77 ;
int V_169 ;
int V_21 = 0 ;
if ( ! V_11 -> V_41 . V_62 && V_31 -> V_64 == NULL &&
V_56 -> V_66 == NULL ) {
F_36 ( L_26 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_31 -> V_99 & V_170 ) {
F_3 ( L_27 ) ;
return - V_171 ;
}
if ( V_31 -> V_139 & V_141 ) {
F_3 ( L_28 , V_31 -> V_16 ) ;
if ( F_127 ( V_11 ) ) {
F_31 ( L_29 ,
V_33 -> V_16 , V_31 -> V_16 , V_33 -> V_16 ) ;
return - V_172 ;
} else {
F_36 ( L_30 ,
V_33 -> V_16 , V_31 -> V_16 ,
V_31 -> V_16 , V_33 -> V_16 ) ;
}
} else {
F_3 ( L_31 , V_31 -> V_16 ) ;
}
if ( ( V_31 -> V_99 & V_173 ) ) {
F_31 ( L_32 ,
V_31 -> V_16 ) ;
V_21 = - V_172 ;
goto V_174;
}
if ( V_11 -> V_39 == 0 ) {
if ( V_33 -> type != V_31 -> type ) {
F_3 ( L_33 ,
V_33 -> V_16 ,
V_33 -> type , V_31 -> type ) ;
V_21 = F_89 ( V_33 ,
V_175 ) ;
V_21 = F_128 ( V_21 ) ;
if ( V_21 ) {
F_31 ( L_34 ,
V_33 -> V_16 ) ;
V_21 = - V_171 ;
goto V_174;
}
F_129 ( V_33 ) ;
F_130 ( V_33 ) ;
if ( V_31 -> type != V_176 )
F_110 ( V_33 , V_31 ) ;
else {
F_131 ( V_33 ) ;
V_33 -> V_83 &= ~ V_177 ;
}
F_89 ( V_33 ,
V_178 ) ;
}
} else if ( V_33 -> type != V_31 -> type ) {
F_31 ( L_35 ,
V_31 -> V_16 ,
V_31 -> type , V_33 -> type ) ;
V_21 = - V_179 ;
goto V_174;
}
if ( V_56 -> V_180 == NULL ) {
if ( V_11 -> V_39 == 0 ) {
F_36 ( L_36 ,
V_33 -> V_16 ) ;
V_11 -> V_41 . V_120 = V_181 ;
} else if ( V_11 -> V_41 . V_120 != V_181 ) {
F_31 ( L_37 ,
V_33 -> V_16 ) ;
V_21 = - V_182 ;
goto V_174;
}
}
F_132 ( V_183 , V_31 ) ;
if ( F_133 ( V_11 -> V_15 -> V_138 ) )
memcpy ( V_11 -> V_15 -> V_138 , V_31 -> V_138 ,
V_31 -> V_137 ) ;
V_128 = F_4 ( sizeof( struct V_35 ) , V_17 ) ;
if ( ! V_128 ) {
V_21 = - V_18 ;
goto V_174;
}
V_128 -> V_184 = 0 ;
V_128 -> V_185 = V_31 -> V_186 ;
V_21 = F_134 ( V_31 , V_11 -> V_15 -> V_186 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_187;
}
memcpy ( V_128 -> V_188 , V_31 -> V_138 , V_95 ) ;
if ( ! V_11 -> V_41 . V_120 ) {
memcpy ( V_77 . V_189 , V_33 -> V_138 , V_33 -> V_137 ) ;
V_77 . V_190 = V_31 -> type ;
V_21 = F_135 ( V_31 , & V_77 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_191;
}
}
V_21 = F_136 ( V_31 , V_33 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_21 ) ;
goto V_192;
}
V_21 = F_137 ( V_31 ) ;
if ( V_21 ) {
F_3 ( L_41 , V_31 -> V_16 ) ;
goto V_193;
}
V_128 -> V_11 = V_11 ;
V_128 -> V_15 = V_31 ;
V_31 -> V_83 |= V_194 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_138 ( V_11 , V_128 ) ;
if ( V_21 )
goto V_195;
}
if ( ! F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_33 -> V_99 & V_100 ) {
V_21 = F_53 ( V_31 , 1 ) ;
if ( V_21 )
goto V_195;
}
if ( V_33 -> V_99 & V_101 ) {
V_21 = F_55 ( V_31 , 1 ) ;
if ( V_21 )
goto V_195;
}
F_139 ( V_33 ) ;
F_73 (ha, bond_dev)
F_57 ( V_31 , V_93 -> V_77 ) ;
F_140 ( V_33 ) ;
}
if ( V_11 -> V_41 . V_1 == V_7 ) {
T_3 V_94 [ V_95 ] = V_96 ;
F_57 ( V_31 , V_94 ) ;
}
F_35 ( V_11 , V_31 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_91 ( V_11 , V_128 ) ;
V_128 -> V_113 = 0 ;
V_128 -> V_196 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_108 ( V_11 ) ;
F_66 ( & V_11 -> V_20 ) ;
V_128 -> V_197 = V_117 ;
if ( V_11 -> V_41 . V_118 && ! V_11 -> V_41 . V_62 ) {
V_169 = F_46 ( V_11 , V_31 , 1 ) ;
if ( ( V_169 == - 1 ) && ! V_11 -> V_41 . V_161 ) {
F_36 ( L_42 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
} else if ( V_169 == - 1 ) {
F_36 ( L_43 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
}
if ( ! V_11 -> V_41 . V_118 ||
( F_46 ( V_11 , V_31 , 0 ) == V_63 ) ) {
if ( V_11 -> V_41 . V_110 ) {
F_3 ( L_44 ) ;
V_128 -> V_42 = V_112 ;
V_128 -> V_113 = V_11 -> V_41 . V_110 ;
} else {
F_3 ( L_45 ) ;
V_128 -> V_42 = V_43 ;
}
V_128 -> V_117 = V_117 ;
} else {
F_3 ( L_46 ) ;
V_128 -> V_42 = V_198 ;
}
F_43 ( V_128 ) ;
if ( F_52 ( V_11 -> V_41 . V_1 ) && V_11 -> V_41 . V_199 [ 0 ] ) {
if ( strcmp ( V_11 -> V_41 . V_199 , V_128 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_103 = V_128 ;
V_11 -> V_104 = true ;
}
}
F_6 ( & V_11 -> V_122 ) ;
switch ( V_11 -> V_41 . V_1 ) {
case V_4 :
F_87 ( V_128 ) ;
F_90 ( V_11 ) ;
break;
case V_7 :
F_87 ( V_128 ) ;
if ( V_11 -> V_39 == 1 ) {
F_141 ( V_128 ) . V_200 = 1 ;
F_142 ( V_11 , 1000 / V_201 ) ;
} else {
F_141 ( V_128 ) . V_200 =
F_141 ( V_128 -> V_27 ) . V_200 + 1 ;
}
F_143 ( V_128 ) ;
break;
case V_8 :
case V_9 :
F_144 ( V_128 ) ;
F_87 ( V_128 ) ;
F_90 ( V_11 ) ;
break;
default:
F_3 ( L_47 ) ;
F_144 ( V_128 ) ;
if ( ! V_11 -> V_76 )
V_11 -> V_76 = V_128 ;
break;
}
F_8 ( & V_11 -> V_122 ) ;
F_38 ( V_11 ) ;
#ifdef F_145
V_31 -> V_136 = F_104 ( V_11 ) ;
if ( V_31 -> V_136 ) {
if ( F_93 ( V_128 ) ) {
F_69 ( & V_11 -> V_20 ) ;
F_83 ( L_48
L_49 ,
V_33 -> V_16 ) ;
V_21 = - V_171 ;
goto V_202;
}
}
#endif
F_69 ( & V_11 -> V_20 ) ;
V_21 = F_146 ( V_33 , V_31 ) ;
if ( V_21 )
goto V_202;
V_21 = F_147 ( V_31 , F_113 ,
V_128 ) ;
if ( V_21 ) {
F_3 ( L_50 , V_21 ) ;
goto V_203;
}
F_83 ( L_51 ,
V_33 -> V_16 , V_31 -> V_16 ,
F_148 ( V_128 ) ? L_52 : L_53 ,
V_128 -> V_42 != V_198 ? L_54 : L_55 ) ;
return 0 ;
V_203:
F_149 ( V_33 , V_31 ) ;
V_202:
F_6 ( & V_11 -> V_20 ) ;
F_92 ( V_11 , V_128 ) ;
F_8 ( & V_11 -> V_20 ) ;
V_195:
F_150 ( V_31 ) ;
V_193:
F_136 ( V_31 , NULL ) ;
V_192:
if ( ! V_11 -> V_41 . V_120 ) {
memcpy ( V_77 . V_189 , V_128 -> V_188 , V_95 ) ;
V_77 . V_190 = V_31 -> type ;
F_135 ( V_31 , & V_77 ) ;
}
V_191:
F_134 ( V_31 , V_128 -> V_185 ) ;
V_187:
F_15 ( V_128 ) ;
V_174:
F_108 ( V_11 ) ;
return V_21 ;
}
int F_151 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_204 ;
struct V_168 V_77 ;
T_4 V_205 = V_33 -> V_139 ;
if ( ! ( V_31 -> V_99 & V_170 ) ||
( V_31 -> V_82 != V_33 ) ) {
F_31 ( L_56 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
return - V_179 ;
}
F_10 () ;
F_89 ( V_33 , V_206 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_35 = F_25 ( V_11 , V_31 ) ;
if ( ! V_35 ) {
F_83 ( L_57 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
return - V_179 ;
}
F_152 ( V_31 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_153 () ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_41 . V_120 ) {
if ( ! F_154 ( V_33 -> V_138 , V_35 -> V_188 ) &&
V_11 -> V_39 > 1 )
F_36 ( L_58 ,
V_33 -> V_16 , V_31 -> V_16 ,
V_35 -> V_188 ,
V_33 -> V_16 , V_31 -> V_16 ) ;
}
if ( V_11 -> V_41 . V_1 == V_7 ) {
F_155 ( V_35 ) ;
}
F_83 ( L_59 ,
V_33 -> V_16 ,
F_148 ( V_35 ) ? L_60 : L_61 ,
V_31 -> V_16 ) ;
V_204 = V_11 -> V_76 ;
V_11 -> V_207 = NULL ;
F_92 ( V_11 , V_35 ) ;
if ( V_11 -> V_103 == V_35 )
V_11 -> V_103 = NULL ;
if ( V_204 == V_35 )
F_82 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_156 ( V_11 , V_35 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_204 == V_35 ) {
F_8 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_122 ) ;
F_90 ( V_11 ) ;
F_8 ( & V_11 -> V_122 ) ;
F_69 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_39 == 0 ) {
F_38 ( V_11 ) ;
memset ( V_33 -> V_138 , 0 , V_33 -> V_137 ) ;
if ( F_127 ( V_11 ) ) {
F_36 ( L_62 ,
V_33 -> V_16 , V_33 -> V_16 ) ;
F_36 ( L_63 ,
V_33 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_16 () ;
if ( V_11 -> V_39 == 0 )
F_132 ( V_208 , V_11 -> V_15 ) ;
F_108 ( V_11 ) ;
if ( ! ( V_33 -> V_139 & V_141 ) &&
( V_205 & V_141 ) )
F_83 ( L_64 ,
V_33 -> V_16 , V_31 -> V_16 , V_33 -> V_16 ) ;
F_149 ( V_33 , V_31 ) ;
F_37 ( V_11 , V_31 ) ;
if ( ! F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_33 -> V_99 & V_100 )
F_53 ( V_31 , - 1 ) ;
if ( V_33 -> V_99 & V_101 )
F_55 ( V_31 , - 1 ) ;
F_139 ( V_33 ) ;
F_72 ( V_33 , V_31 ) ;
F_140 ( V_33 ) ;
}
F_136 ( V_31 , NULL ) ;
F_96 ( V_35 ) ;
F_150 ( V_31 ) ;
if ( V_11 -> V_41 . V_120 != V_181 ) {
memcpy ( V_77 . V_189 , V_35 -> V_188 , V_95 ) ;
V_77 . V_190 = V_31 -> type ;
F_135 ( V_31 , & V_77 ) ;
}
F_134 ( V_31 , V_35 -> V_185 ) ;
V_31 -> V_83 &= ~ V_194 ;
F_15 ( V_35 ) ;
return 0 ;
}
static int F_157 ( struct V_30 * V_33 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
int V_157 ;
V_157 = F_151 ( V_33 , V_31 ) ;
if ( ( V_157 == 0 ) && ( V_11 -> V_39 == 0 ) ) {
V_33 -> V_83 |= V_132 ;
F_83 ( L_65 ,
V_33 -> V_16 , V_33 -> V_16 ) ;
F_158 ( V_33 ) ;
}
return V_157 ;
}
static int F_159 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
struct V_30 * V_31 ;
struct V_168 V_77 ;
F_6 ( & V_11 -> V_20 ) ;
F_42 ( V_33 ) ;
if ( V_11 -> V_39 == 0 )
goto V_23;
V_11 -> V_207 = NULL ;
V_11 -> V_103 = NULL ;
F_82 ( V_11 , NULL ) ;
while ( ( V_35 = V_11 -> V_111 ) != NULL ) {
if ( V_11 -> V_41 . V_1 == V_7 )
F_155 ( V_35 ) ;
V_31 = V_35 -> V_15 ;
F_92 ( V_11 , V_35 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_152 ( V_31 ) ;
F_153 () ;
if ( F_13 ( V_11 ) ) {
F_156 ( V_11 , V_35 ) ;
}
F_149 ( V_33 , V_31 ) ;
F_37 ( V_11 , V_31 ) ;
if ( ! F_52 ( V_11 -> V_41 . V_1 ) ) {
if ( V_33 -> V_99 & V_100 )
F_53 ( V_31 , - 1 ) ;
if ( V_33 -> V_99 & V_101 )
F_55 ( V_31 , - 1 ) ;
F_139 ( V_33 ) ;
F_72 ( V_33 , V_31 ) ;
F_140 ( V_33 ) ;
}
F_136 ( V_31 , NULL ) ;
F_96 ( V_35 ) ;
F_150 ( V_31 ) ;
if ( ! V_11 -> V_41 . V_120 ) {
memcpy ( V_77 . V_189 , V_35 -> V_188 , V_95 ) ;
V_77 . V_190 = V_31 -> type ;
F_135 ( V_31 , & V_77 ) ;
}
F_15 ( V_35 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
memset ( V_33 -> V_138 , 0 , V_33 -> V_137 ) ;
if ( F_127 ( V_11 ) ) {
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
static int F_160 ( struct V_30 * V_33 , struct V_30 * V_31 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_98 = NULL ;
struct V_35 * V_97 = NULL ;
int V_21 = 0 ;
if ( ! F_52 ( V_11 -> V_41 . V_1 ) )
return - V_179 ;
if ( ! ( V_31 -> V_99 & V_170 ) || ( V_31 -> V_82 != V_33 ) )
return - V_179 ;
F_66 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_122 ) ;
V_98 = V_11 -> V_76 ;
F_69 ( & V_11 -> V_122 ) ;
V_97 = F_25 ( V_11 , V_31 ) ;
if ( V_97 && ( V_97 == V_98 ) ) {
F_69 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_97 ) &&
( V_98 ) &&
( V_97 -> V_42 == V_43 ) &&
F_79 ( V_97 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_122 ) ;
F_82 ( V_11 , V_97 ) ;
F_8 ( & V_11 -> V_122 ) ;
F_16 () ;
} else
V_21 = - V_179 ;
F_69 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_161 ( struct V_30 * V_33 , struct V_209 * V_210 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_210 -> V_211 = V_11 -> V_41 . V_1 ;
V_210 -> V_118 = V_11 -> V_41 . V_118 ;
F_66 ( & V_11 -> V_20 ) ;
V_210 -> V_212 = V_11 -> V_39 ;
F_69 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_162 ( struct V_30 * V_33 , struct V_213 * V_210 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_37 , V_21 = - V_22 ;
F_66 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
if ( V_37 == ( int ) V_210 -> V_214 ) {
V_21 = 0 ;
strcpy ( V_210 -> V_215 , V_35 -> V_15 -> V_16 ) ;
V_210 -> V_42 = V_35 -> V_42 ;
V_210 -> V_116 = F_163 ( V_35 ) ;
V_210 -> V_196 = V_35 -> V_196 ;
break;
}
}
F_69 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_164 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_37 , V_216 , V_217 = 0 ;
bool V_218 ;
V_218 = ! V_11 -> V_76 ? true : false ;
F_29 (bond, slave, i) {
V_35 -> V_219 = V_220 ;
V_216 = F_46 ( V_11 , V_35 -> V_15 , 0 ) ;
switch ( V_35 -> V_42 ) {
case V_43 :
if ( V_216 )
continue;
V_35 -> V_42 = V_221 ;
V_35 -> V_113 = V_11 -> V_41 . V_222 ;
if ( V_35 -> V_113 ) {
F_83 ( L_67 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_41 . V_1 ==
V_4 ) ?
( F_148 ( V_35 ) ?
L_68 : L_69 ) : L_70 ,
V_35 -> V_15 -> V_16 ,
V_11 -> V_41 . V_222 * V_11 -> V_41 . V_118 ) ;
}
case V_221 :
if ( V_216 ) {
V_35 -> V_42 = V_43 ;
V_35 -> V_117 = V_117 ;
F_83 ( L_71 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_41 . V_222 - V_35 -> V_113 ) *
V_11 -> V_41 . V_118 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
if ( V_35 -> V_113 <= 0 ) {
V_35 -> V_219 = V_198 ;
V_217 ++ ;
continue;
}
V_35 -> V_113 -- ;
break;
case V_198 :
if ( ! V_216 )
continue;
V_35 -> V_42 = V_112 ;
V_35 -> V_113 = V_11 -> V_41 . V_110 ;
if ( V_35 -> V_113 ) {
F_83 ( L_72 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ,
V_218 ? 0 :
V_11 -> V_41 . V_110 *
V_11 -> V_41 . V_118 ) ;
}
case V_112 :
if ( ! V_216 ) {
V_35 -> V_42 = V_198 ;
F_83 ( L_73 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_41 . V_110 - V_35 -> V_113 ) *
V_11 -> V_41 . V_118 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
if ( V_218 )
V_35 -> V_113 = 0 ;
if ( V_35 -> V_113 <= 0 ) {
V_35 -> V_219 = V_43 ;
V_217 ++ ;
V_218 = false ;
continue;
}
V_35 -> V_113 -- ;
break;
}
}
return V_217 ;
}
static void F_165 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_37 ;
F_29 (bond, slave, i) {
switch ( V_35 -> V_219 ) {
case V_220 :
continue;
case V_43 :
V_35 -> V_42 = V_43 ;
V_35 -> V_117 = V_117 ;
if ( V_11 -> V_41 . V_1 == V_7 ) {
F_166 ( V_35 ) ;
} else if ( V_11 -> V_41 . V_1 != V_4 ) {
F_144 ( V_35 ) ;
} else if ( V_35 != V_11 -> V_103 ) {
F_166 ( V_35 ) ;
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
( V_35 == V_11 -> V_103 ) )
goto V_223;
continue;
case V_198 :
if ( V_35 -> V_196 < V_224 )
V_35 -> V_196 ++ ;
V_35 -> V_42 = V_198 ;
if ( V_11 -> V_41 . V_1 == V_4 ||
V_11 -> V_41 . V_1 == V_7 )
F_87 ( V_35 ) ;
F_83 ( L_77 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( V_11 -> V_41 . V_1 == V_7 )
F_84 ( V_35 ,
V_198 ) ;
if ( F_13 ( V_11 ) )
F_85 ( V_11 , V_35 ,
V_198 ) ;
if ( V_35 == V_11 -> V_76 )
goto V_223;
continue;
default:
F_31 ( L_78 ,
V_11 -> V_15 -> V_16 , V_35 -> V_219 ,
V_35 -> V_15 -> V_16 ) ;
V_35 -> V_219 = V_220 ;
continue;
}
V_223:
F_167 () ;
F_10 () ;
F_6 ( & V_11 -> V_122 ) ;
F_90 ( V_11 ) ;
F_8 ( & V_11 -> V_122 ) ;
F_16 () ;
}
F_38 ( V_11 ) ;
}
void F_168 ( struct V_90 * V_91 )
{
struct V_10 * V_11 = F_71 ( V_91 , struct V_10 ,
V_225 . V_91 ) ;
bool V_119 = false ;
unsigned long V_113 ;
F_66 ( & V_11 -> V_20 ) ;
V_113 = F_169 ( V_11 -> V_41 . V_118 ) ;
if ( V_11 -> V_39 == 0 )
goto V_226;
V_119 = F_80 ( V_11 ) ;
if ( F_164 ( V_11 ) ) {
F_69 ( & V_11 -> V_20 ) ;
if ( ! F_170 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_113 = 1 ;
V_119 = false ;
goto V_226;
}
F_66 ( & V_11 -> V_20 ) ;
F_165 ( V_11 ) ;
F_69 ( & V_11 -> V_20 ) ;
F_171 () ;
F_66 ( & V_11 -> V_20 ) ;
}
V_226:
if ( V_11 -> V_41 . V_118 )
F_68 ( V_11 -> V_87 , & V_11 -> V_225 , V_113 ) ;
F_69 ( & V_11 -> V_20 ) ;
if ( V_119 ) {
if ( ! F_170 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_11 -> V_114 ++ ;
F_69 ( & V_11 -> V_20 ) ;
return;
}
F_89 ( V_11 -> V_15 , V_124 ) ;
F_171 () ;
}
}
static int F_172 ( struct V_10 * V_11 , T_6 V_227 )
{
struct V_13 * V_14 ;
struct V_30 * V_80 ;
if ( V_227 == F_173 ( V_11 -> V_15 , 0 , V_227 ) )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_61 () ;
V_80 = F_67 ( V_11 -> V_15 , V_14 -> V_12 ) ;
F_64 () ;
if ( V_80 && V_227 == F_173 ( V_80 , 0 , V_227 ) )
return 1 ;
}
return 0 ;
}
static void F_174 ( struct V_30 * V_31 , int V_228 , T_6 V_229 , T_6 V_230 , unsigned short V_12 )
{
struct V_28 * V_29 ;
F_3 ( L_79 , V_228 ,
V_31 -> V_16 , V_229 , V_230 , V_12 ) ;
V_29 = F_175 ( V_228 , V_231 , V_229 , V_31 , V_230 ,
NULL , V_31 -> V_138 , NULL ) ;
if ( ! V_29 ) {
F_31 ( L_80 ) ;
return;
}
if ( V_12 ) {
V_29 = F_176 ( V_29 , V_12 ) ;
if ( ! V_29 ) {
F_31 ( L_81 ) ;
return;
}
}
F_177 ( V_29 ) ;
}
static void F_178 ( struct V_10 * V_11 , struct V_35 * V_35 )
{
int V_37 , V_12 ;
T_6 * V_232 = V_11 -> V_41 . V_233 ;
struct V_13 * V_14 ;
struct V_30 * V_80 = NULL ;
struct V_234 * V_235 ;
for ( V_37 = 0 ; ( V_37 < V_236 ) ; V_37 ++ ) {
T_6 V_77 ;
if ( ! V_232 [ V_37 ] )
break;
F_3 ( L_82 , V_232 [ V_37 ] ) ;
if ( ! F_127 ( V_11 ) ) {
F_3 ( L_83 ) ;
V_77 = F_173 ( V_11 -> V_15 , V_232 [ V_37 ] , 0 ) ;
F_174 ( V_35 -> V_15 , V_237 , V_232 [ V_37 ] ,
V_77 , 0 ) ;
continue;
}
V_235 = F_179 ( F_180 ( V_11 -> V_15 ) , V_232 [ V_37 ] , 0 ,
V_238 , 0 ) ;
if ( F_181 ( V_235 ) ) {
if ( F_182 () ) {
F_36 ( L_84 ,
V_11 -> V_15 -> V_16 , & V_232 [ V_37 ] ) ;
}
continue;
}
if ( V_235 -> V_239 . V_15 == V_11 -> V_15 ) {
F_183 ( V_235 ) ;
F_3 ( L_85 ) ;
V_77 = F_173 ( V_11 -> V_15 , V_232 [ V_37 ] , 0 ) ;
F_174 ( V_35 -> V_15 , V_237 , V_232 [ V_37 ] ,
V_77 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
F_61 () ;
V_80 = F_67 ( V_11 -> V_15 ,
V_14 -> V_12 ) ;
F_64 () ;
if ( V_80 == V_235 -> V_239 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_86 ,
V_80 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 && V_80 ) {
F_183 ( V_235 ) ;
V_77 = F_173 ( V_80 , V_232 [ V_37 ] , 0 ) ;
F_174 ( V_35 -> V_15 , V_237 , V_232 [ V_37 ] ,
V_77 , V_12 ) ;
continue;
}
if ( F_182 () ) {
F_36 ( L_87 ,
V_11 -> V_15 -> V_16 , & V_232 [ V_37 ] ,
V_235 -> V_239 . V_15 ? V_235 -> V_239 . V_15 -> V_16 : L_18 ) ;
}
F_183 ( V_235 ) ;
}
}
static void F_184 ( struct V_10 * V_11 , struct V_35 * V_35 , T_6 V_240 , T_6 V_241 )
{
int V_37 ;
T_6 * V_232 = V_11 -> V_41 . V_233 ;
for ( V_37 = 0 ; ( V_37 < V_236 ) && V_232 [ V_37 ] ; V_37 ++ ) {
F_3 ( L_88 ,
& V_240 , & V_241 , V_37 , & V_232 [ V_37 ] ,
F_172 ( V_11 , V_241 ) ) ;
if ( V_240 == V_232 [ V_37 ] ) {
if ( F_172 ( V_11 , V_241 ) )
V_35 -> V_197 = V_117 ;
return;
}
}
}
static int F_185 ( struct V_28 * V_29 , struct V_10 * V_11 ,
struct V_35 * V_35 )
{
struct V_242 * V_243 ;
unsigned char * V_244 ;
T_6 V_240 , V_241 ;
if ( V_29 -> V_245 != F_186 ( V_231 ) )
return V_158 ;
F_66 ( & V_11 -> V_20 ) ;
F_3 ( L_89 ,
V_11 -> V_15 -> V_16 , V_29 -> V_15 -> V_16 ) ;
if ( ! F_187 ( V_29 , F_188 ( V_11 -> V_15 ) ) )
goto V_246;
V_243 = F_189 ( V_29 ) ;
if ( V_243 -> V_247 != V_11 -> V_15 -> V_137 ||
V_29 -> V_153 == V_248 ||
V_29 -> V_153 == V_249 ||
V_243 -> V_250 != F_190 ( V_176 ) ||
V_243 -> V_251 != F_190 ( V_252 ) ||
V_243 -> V_253 != 4 )
goto V_246;
V_244 = ( unsigned char * ) ( V_243 + 1 ) ;
V_244 += V_11 -> V_15 -> V_137 ;
memcpy ( & V_240 , V_244 , 4 ) ;
V_244 += 4 + V_11 -> V_15 -> V_137 ;
memcpy ( & V_241 , V_244 , 4 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 , F_163 ( V_35 ) ,
V_11 -> V_41 . V_254 , F_191 ( V_11 , V_35 ) ,
& V_240 , & V_241 ) ;
if ( F_148 ( V_35 ) )
F_184 ( V_11 , V_35 , V_240 , V_241 ) ;
else
F_184 ( V_11 , V_35 , V_241 , V_240 ) ;
V_246:
F_69 ( & V_11 -> V_20 ) ;
return V_158 ;
}
void F_192 ( struct V_90 * V_91 )
{
struct V_10 * V_11 = F_71 ( V_91 , struct V_10 ,
V_255 . V_91 ) ;
struct V_35 * V_35 , * V_204 ;
int V_223 = 0 ;
int V_256 ;
int V_37 ;
F_66 ( & V_11 -> V_20 ) ;
V_256 = F_169 ( V_11 -> V_41 . V_161 ) ;
if ( V_11 -> V_39 == 0 )
goto V_226;
F_66 ( & V_11 -> V_122 ) ;
V_204 = V_11 -> V_76 ;
F_69 ( & V_11 -> V_122 ) ;
F_29 (bond, slave, i) {
unsigned long V_257 = F_193 ( V_35 -> V_15 ) ;
if ( V_35 -> V_42 != V_43 ) {
if ( F_194 ( V_117 ,
V_257 - V_256 ,
V_257 + V_256 ) &&
F_194 ( V_117 ,
V_35 -> V_15 -> V_162 - V_256 ,
V_35 -> V_15 -> V_162 + V_256 ) ) {
V_35 -> V_42 = V_43 ;
F_144 ( V_35 ) ;
if ( ! V_204 ) {
F_83 ( L_91 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
V_223 = 1 ;
} else {
F_83 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_194 ( V_117 ,
V_257 - V_256 ,
V_257 + 2 * V_256 ) ||
! F_194 ( V_117 ,
V_35 -> V_15 -> V_162 - V_256 ,
V_35 -> V_15 -> V_162 + 2 * V_256 ) ) {
V_35 -> V_42 = V_198 ;
F_166 ( V_35 ) ;
if ( V_35 -> V_196 < V_224 )
V_35 -> V_196 ++ ;
F_83 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_35 -> V_15 -> V_16 ) ;
if ( V_35 == V_204 )
V_223 = 1 ;
}
}
if ( F_79 ( V_35 -> V_15 ) )
F_178 ( V_11 , V_35 ) ;
}
if ( V_223 ) {
F_10 () ;
F_6 ( & V_11 -> V_122 ) ;
F_90 ( V_11 ) ;
F_8 ( & V_11 -> V_122 ) ;
F_16 () ;
}
V_226:
if ( V_11 -> V_41 . V_161 )
F_68 ( V_11 -> V_87 , & V_11 -> V_255 , V_256 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
static int F_195 ( struct V_10 * V_11 , int V_256 )
{
struct V_35 * V_35 ;
int V_37 , V_217 = 0 ;
unsigned long V_257 ;
F_29 (bond, slave, i) {
V_35 -> V_219 = V_220 ;
if ( V_35 -> V_42 != V_43 ) {
if ( F_194 ( V_117 ,
F_196 ( V_11 , V_35 ) - V_256 ,
F_196 ( V_11 , V_35 ) + V_256 ) ) {
V_35 -> V_219 = V_43 ;
V_217 ++ ;
}
continue;
}
if ( F_194 ( V_117 ,
V_35 -> V_117 - V_256 ,
V_35 -> V_117 + 2 * V_256 ) )
continue;
if ( ! F_148 ( V_35 ) &&
! V_11 -> V_207 &&
! F_194 ( V_117 ,
F_196 ( V_11 , V_35 ) - V_256 ,
F_196 ( V_11 , V_35 ) + 3 * V_256 ) ) {
V_35 -> V_219 = V_198 ;
V_217 ++ ;
}
V_257 = F_193 ( V_35 -> V_15 ) ;
if ( F_148 ( V_35 ) &&
( ! F_194 ( V_117 ,
V_257 - V_256 ,
V_257 + 2 * V_256 ) ||
! F_194 ( V_117 ,
F_196 ( V_11 , V_35 ) - V_256 ,
F_196 ( V_11 , V_35 ) + 2 * V_256 ) ) ) {
V_35 -> V_219 = V_198 ;
V_217 ++ ;
}
}
return V_217 ;
}
static void F_197 ( struct V_10 * V_11 , int V_256 )
{
struct V_35 * V_35 ;
int V_37 ;
unsigned long V_257 ;
F_29 (bond, slave, i) {
switch ( V_35 -> V_219 ) {
case V_220 :
continue;
case V_43 :
V_257 = F_193 ( V_35 -> V_15 ) ;
if ( ( ! V_11 -> V_76 &&
F_194 ( V_117 ,
V_257 - V_256 ,
V_257 + V_256 ) ) ||
V_11 -> V_76 != V_35 ) {
V_35 -> V_42 = V_43 ;
if ( V_11 -> V_207 ) {
F_87 (
V_11 -> V_207 ) ;
V_11 -> V_207 = NULL ;
}
F_83 ( L_94 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_76 ||
( V_35 == V_11 -> V_103 ) )
goto V_223;
}
continue;
case V_198 :
if ( V_35 -> V_196 < V_224 )
V_35 -> V_196 ++ ;
V_35 -> V_42 = V_198 ;
F_87 ( V_35 ) ;
F_83 ( L_77 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
if ( V_35 == V_11 -> V_76 ) {
V_11 -> V_207 = NULL ;
goto V_223;
}
continue;
default:
F_31 ( L_95 ,
V_11 -> V_15 -> V_16 , V_35 -> V_219 ,
V_35 -> V_15 -> V_16 ) ;
continue;
}
V_223:
F_167 () ;
F_10 () ;
F_6 ( & V_11 -> V_122 ) ;
F_90 ( V_11 ) ;
F_8 ( & V_11 -> V_122 ) ;
F_16 () ;
}
F_38 ( V_11 ) ;
}
static void F_198 ( struct V_10 * V_11 )
{
struct V_35 * V_35 ;
int V_37 ;
F_66 ( & V_11 -> V_122 ) ;
if ( V_11 -> V_207 && V_11 -> V_76 )
F_83 ( L_96 ,
V_11 -> V_207 -> V_15 -> V_16 ,
V_11 -> V_76 -> V_15 -> V_16 ) ;
if ( V_11 -> V_76 ) {
F_178 ( V_11 , V_11 -> V_76 ) ;
F_69 ( & V_11 -> V_122 ) ;
return;
}
F_69 ( & V_11 -> V_122 ) ;
if ( ! V_11 -> V_207 ) {
V_11 -> V_207 = V_11 -> V_111 ;
if ( ! V_11 -> V_207 )
return;
}
F_87 ( V_11 -> V_207 ) ;
F_78 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_79 ( V_35 -> V_15 ) ) {
V_35 -> V_42 = V_112 ;
F_88 ( V_35 ) ;
F_178 ( V_11 , V_35 ) ;
V_35 -> V_117 = V_117 ;
V_11 -> V_207 = V_35 ;
break;
}
if ( V_35 -> V_42 == V_43 ) {
V_35 -> V_42 = V_198 ;
if ( V_35 -> V_196 < V_224 )
V_35 -> V_196 ++ ;
F_87 ( V_35 ) ;
F_83 ( L_97 ,
V_11 -> V_15 -> V_16 , V_35 -> V_15 -> V_16 ) ;
}
}
}
void F_199 ( struct V_90 * V_91 )
{
struct V_10 * V_11 = F_71 ( V_91 , struct V_10 ,
V_255 . V_91 ) ;
bool V_119 = false ;
int V_256 ;
F_66 ( & V_11 -> V_20 ) ;
V_256 = F_169 ( V_11 -> V_41 . V_161 ) ;
if ( V_11 -> V_39 == 0 )
goto V_226;
V_119 = F_80 ( V_11 ) ;
if ( F_195 ( V_11 , V_256 ) ) {
F_69 ( & V_11 -> V_20 ) ;
if ( ! F_170 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_256 = 1 ;
V_119 = false ;
goto V_226;
}
F_66 ( & V_11 -> V_20 ) ;
F_197 ( V_11 , V_256 ) ;
F_69 ( & V_11 -> V_20 ) ;
F_171 () ;
F_66 ( & V_11 -> V_20 ) ;
}
F_198 ( V_11 ) ;
V_226:
if ( V_11 -> V_41 . V_161 )
F_68 ( V_11 -> V_87 , & V_11 -> V_255 , V_256 ) ;
F_69 ( & V_11 -> V_20 ) ;
if ( V_119 ) {
if ( ! F_170 () ) {
F_66 ( & V_11 -> V_20 ) ;
V_11 -> V_114 ++ ;
F_69 ( & V_11 -> V_20 ) ;
return;
}
F_89 ( V_11 -> V_15 , V_124 ) ;
F_171 () ;
}
}
static int F_200 ( struct V_10 * V_11 )
{
F_201 ( V_11 ) ;
F_202 ( V_11 ) ;
F_203 ( V_11 ) ;
return V_258 ;
}
static int F_204 ( unsigned long V_259 ,
struct V_30 * V_33 )
{
struct V_10 * V_260 = F_28 ( V_33 ) ;
switch ( V_259 ) {
case V_261 :
return F_200 ( V_260 ) ;
default:
break;
}
return V_258 ;
}
static int F_205 ( unsigned long V_259 ,
struct V_30 * V_31 )
{
struct V_30 * V_33 = V_31 -> V_82 ;
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 = NULL ;
switch ( V_259 ) {
case V_262 :
if ( V_33 ) {
if ( V_11 -> V_152 )
F_157 ( V_33 , V_31 ) ;
else
F_151 ( V_33 , V_31 ) ;
}
break;
case V_263 :
case V_264 :
V_35 = F_25 ( V_11 , V_31 ) ;
if ( V_35 ) {
T_2 V_265 = V_35 -> V_47 ;
T_3 V_266 = V_35 -> V_49 ;
F_43 ( V_35 ) ;
if ( V_11 -> V_41 . V_1 == V_7 ) {
if ( V_265 != V_35 -> V_47 )
F_206 ( V_35 ) ;
if ( V_266 != V_35 -> V_49 )
F_207 ( V_35 ) ;
}
}
break;
case V_267 :
break;
case V_268 :
break;
case V_261 :
break;
case V_269 :
F_108 ( V_11 ) ;
break;
default:
break;
}
return V_258 ;
}
static int F_208 ( struct V_270 * V_271 ,
unsigned long V_259 , void * V_272 )
{
struct V_30 * V_273 = (struct V_30 * ) V_272 ;
F_3 ( L_98 ,
V_273 ? V_273 -> V_16 : L_10 ,
V_259 ) ;
if ( ! ( V_273 -> V_83 & V_194 ) )
return V_258 ;
if ( V_273 -> V_99 & V_274 ) {
F_3 ( L_99 ) ;
return F_204 ( V_259 , V_273 ) ;
}
if ( V_273 -> V_99 & V_170 ) {
F_3 ( L_100 ) ;
return F_205 ( V_259 , V_273 ) ;
}
return V_258 ;
}
static int F_209 ( struct V_28 * V_29 , int V_275 )
{
struct V_276 * V_166 = (struct V_276 * ) V_29 -> V_166 ;
struct V_277 * V_278 = F_210 ( V_29 ) ;
if ( V_29 -> V_245 == F_190 ( V_252 ) ) {
return ( ( F_211 ( V_278 -> V_279 ^ V_278 -> V_280 ) & 0xffff ) ^
( V_166 -> V_167 [ 5 ] ^ V_166 -> V_281 [ 5 ] ) ) % V_275 ;
}
return ( V_166 -> V_167 [ 5 ] ^ V_166 -> V_281 [ 5 ] ) % V_275 ;
}
static int F_212 ( struct V_28 * V_29 , int V_275 )
{
struct V_276 * V_166 = (struct V_276 * ) V_29 -> V_166 ;
struct V_277 * V_278 = F_210 ( V_29 ) ;
T_7 * V_282 = ( T_7 * ) ( ( T_2 * ) V_278 + V_278 -> V_283 ) ;
int V_284 = 0 ;
if ( V_29 -> V_245 == F_190 ( V_252 ) ) {
if ( ! F_213 ( V_278 ) &&
( V_278 -> V_245 == V_285 ||
V_278 -> V_245 == V_286 ) ) {
V_284 = F_214 ( ( * V_282 ^ * ( V_282 + 1 ) ) ) ;
}
return ( V_284 ^
( ( F_211 ( V_278 -> V_279 ^ V_278 -> V_280 ) ) & 0xffff ) ) % V_275 ;
}
return ( V_166 -> V_167 [ 5 ] ^ V_166 -> V_281 [ 5 ] ) % V_275 ;
}
static int F_215 ( struct V_28 * V_29 , int V_275 )
{
struct V_276 * V_166 = (struct V_276 * ) V_29 -> V_166 ;
return ( V_166 -> V_167 [ 5 ] ^ V_166 -> V_281 [ 5 ] ) % V_275 ;
}
static int F_216 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 ;
int V_37 ;
F_66 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_39 > 0 ) {
F_66 ( & V_11 -> V_122 ) ;
F_29 (bond, slave, i) {
if ( ( V_11 -> V_41 . V_1 == V_4 )
&& ( V_35 != V_11 -> V_76 ) ) {
F_87 ( V_35 ) ;
} else {
F_88 ( V_35 ) ;
}
}
F_69 ( & V_11 -> V_122 ) ;
}
F_69 ( & V_11 -> V_20 ) ;
F_217 ( & V_11 -> V_88 , F_70 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_218 ( V_11 , ( V_11 -> V_41 . V_1 == V_9 ) ) ) {
return - V_18 ;
}
F_217 ( & V_11 -> V_287 , V_288 ) ;
F_68 ( V_11 -> V_87 , & V_11 -> V_287 , 0 ) ;
}
if ( V_11 -> V_41 . V_118 ) {
F_217 ( & V_11 -> V_225 , F_168 ) ;
F_68 ( V_11 -> V_87 , & V_11 -> V_225 , 0 ) ;
}
if ( V_11 -> V_41 . V_161 ) {
if ( V_11 -> V_41 . V_1 == V_4 )
F_217 ( & V_11 -> V_255 ,
F_199 ) ;
else
F_217 ( & V_11 -> V_255 ,
F_192 ) ;
F_68 ( V_11 -> V_87 , & V_11 -> V_255 , 0 ) ;
if ( V_11 -> V_41 . V_254 )
V_11 -> F_114 = F_185 ;
}
if ( V_11 -> V_41 . V_1 == V_7 ) {
F_217 ( & V_11 -> V_289 , V_290 ) ;
F_68 ( V_11 -> V_87 , & V_11 -> V_289 , 0 ) ;
V_11 -> F_114 = V_291 ;
F_219 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_220 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_114 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_41 . V_118 ) {
F_221 ( & V_11 -> V_225 ) ;
}
if ( V_11 -> V_41 . V_161 ) {
F_221 ( & V_11 -> V_255 ) ;
}
switch ( V_11 -> V_41 . V_1 ) {
case V_7 :
F_221 ( & V_11 -> V_289 ) ;
break;
case V_8 :
case V_9 :
F_221 ( & V_11 -> V_287 ) ;
break;
default:
break;
}
if ( F_222 ( & V_11 -> V_88 ) )
F_221 ( & V_11 -> V_88 ) ;
if ( F_13 ( V_11 ) ) {
F_223 ( V_11 ) ;
}
V_11 -> F_114 = NULL ;
return 0 ;
}
static struct V_292 * F_224 ( struct V_30 * V_33 ,
struct V_292 * V_293 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_292 V_294 ;
struct V_35 * V_35 ;
int V_37 ;
memset ( V_293 , 0 , sizeof( * V_293 ) ) ;
F_225 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
const struct V_292 * V_295 =
F_226 ( V_35 -> V_15 , & V_294 ) ;
V_293 -> V_296 += V_295 -> V_296 ;
V_293 -> V_297 += V_295 -> V_297 ;
V_293 -> V_298 += V_295 -> V_298 ;
V_293 -> V_299 += V_295 -> V_299 ;
V_293 -> V_300 += V_295 -> V_300 ;
V_293 -> V_301 += V_295 -> V_301 ;
V_293 -> V_302 += V_295 -> V_302 ;
V_293 -> V_303 += V_295 -> V_303 ;
V_293 -> V_304 += V_295 -> V_304 ;
V_293 -> V_305 += V_295 -> V_305 ;
V_293 -> V_306 += V_295 -> V_306 ;
V_293 -> V_307 += V_295 -> V_307 ;
V_293 -> V_308 += V_295 -> V_308 ;
V_293 -> V_309 += V_295 -> V_309 ;
V_293 -> V_310 += V_295 -> V_310 ;
V_293 -> V_311 += V_295 -> V_311 ;
V_293 -> V_312 += V_295 -> V_312 ;
V_293 -> V_313 += V_295 -> V_313 ;
V_293 -> V_314 += V_295 -> V_314 ;
V_293 -> V_315 += V_295 -> V_315 ;
V_293 -> V_316 += V_295 -> V_316 ;
}
F_227 ( & V_11 -> V_20 ) ;
return V_293 ;
}
static int F_228 ( struct V_30 * V_33 , struct V_58 * V_59 , int V_317 )
{
struct V_30 * V_31 = NULL ;
struct V_209 V_318 ;
struct V_209 T_8 * V_319 = NULL ;
struct V_213 V_320 ;
struct V_213 T_8 * V_321 = NULL ;
struct V_60 * V_61 = NULL ;
int V_21 = 0 ;
F_3 ( L_101 , V_33 -> V_16 , V_317 ) ;
switch ( V_317 ) {
case V_69 :
V_61 = F_49 ( V_59 ) ;
if ( ! V_61 )
return - V_179 ;
V_61 -> V_322 = 0 ;
case V_72 :
V_61 = F_49 ( V_59 ) ;
if ( ! V_61 )
return - V_179 ;
if ( V_61 -> V_70 == 1 ) {
struct V_10 * V_11 = F_28 ( V_33 ) ;
V_61 -> V_73 = 0 ;
F_66 ( & V_11 -> V_20 ) ;
F_66 ( & V_11 -> V_122 ) ;
if ( F_40 ( V_11 -> V_15 ) )
V_61 -> V_73 = V_63 ;
F_69 ( & V_11 -> V_122 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_323 :
case V_324 :
V_319 = (struct V_209 T_8 * ) V_59 -> V_325 ;
if ( F_229 ( & V_318 , V_319 , sizeof( V_209 ) ) )
return - V_326 ;
V_21 = F_161 ( V_33 , & V_318 ) ;
if ( V_21 == 0 &&
F_230 ( V_319 , & V_318 , sizeof( V_209 ) ) )
return - V_326 ;
return V_21 ;
case V_327 :
case V_328 :
V_321 = (struct V_213 T_8 * ) V_59 -> V_325 ;
if ( F_229 ( & V_320 , V_321 , sizeof( V_213 ) ) )
return - V_326 ;
V_21 = F_162 ( V_33 , & V_320 ) ;
if ( V_21 == 0 &&
F_230 ( V_321 , & V_320 , sizeof( V_213 ) ) )
return - V_326 ;
return V_21 ;
default:
break;
}
if ( ! F_231 ( V_329 ) )
return - V_172 ;
V_31 = F_232 ( F_180 ( V_33 ) , V_59 -> V_330 ) ;
F_3 ( L_102 , V_31 ) ;
if ( ! V_31 )
V_21 = - V_22 ;
else {
F_3 ( L_103 , V_31 -> V_16 ) ;
switch ( V_317 ) {
case V_331 :
case V_332 :
V_21 = F_126 ( V_33 , V_31 ) ;
break;
case V_333 :
case V_334 :
V_21 = F_151 ( V_33 , V_31 ) ;
break;
case V_335 :
case V_336 :
V_21 = F_105 ( V_33 , V_31 ) ;
break;
case V_337 :
case V_338 :
V_21 = F_160 ( V_33 , V_31 ) ;
break;
default:
V_21 = - V_182 ;
}
F_233 ( V_31 ) ;
}
return V_21 ;
}
static bool F_234 ( unsigned char * V_77 ,
struct V_339 * V_340 ,
int V_341 )
{
struct V_92 * V_93 ;
F_235 (ha, list)
if ( ! memcmp ( V_93 -> V_77 , V_77 , V_341 ) )
return true ;
return false ;
}
static void F_236 ( struct V_30 * V_33 , int V_342 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
if ( V_342 & V_100 )
F_51 ( V_11 ,
V_33 -> V_99 & V_100 ? 1 : - 1 ) ;
if ( V_342 & V_101 )
F_54 ( V_11 ,
V_33 -> V_99 & V_101 ? 1 : - 1 ) ;
}
static void F_237 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_92 * V_93 ;
bool V_343 ;
F_66 ( & V_11 -> V_20 ) ;
F_73 (ha, bond_dev) {
V_343 = F_234 ( V_93 -> V_77 , & V_11 -> V_344 ,
V_33 -> V_137 ) ;
if ( ! V_343 )
F_56 ( V_11 , V_93 -> V_77 ) ;
}
F_235 (ha, &bond->mc_list) {
V_343 = F_234 ( V_93 -> V_77 , & V_33 -> V_345 ,
V_33 -> V_137 ) ;
if ( ! V_343 )
F_58 ( V_11 , V_93 -> V_77 ) ;
}
F_238 ( & V_11 -> V_344 ) ;
F_239 ( & V_11 -> V_344 , & V_33 -> V_345 ,
V_33 -> V_137 , V_346 ) ;
F_69 ( & V_11 -> V_20 ) ;
}
static int F_240 ( struct V_347 * V_348 )
{
struct V_10 * V_11 = F_28 ( V_348 -> V_15 ) ;
struct V_35 * V_35 = V_11 -> V_111 ;
const struct V_55 * V_56 ;
struct V_349 V_350 ;
int V_157 ;
if ( ! V_35 )
return 0 ;
V_56 = V_35 -> V_15 -> V_57 ;
if ( ! V_56 -> V_351 )
return 0 ;
V_350 . V_352 = NULL ;
V_350 . V_353 = NULL ;
V_157 = V_56 -> V_351 ( V_35 -> V_15 , & V_350 ) ;
if ( V_157 )
return V_157 ;
V_348 -> V_350 -> V_353 = V_350 . V_353 ;
if ( ! V_350 . V_352 )
return 0 ;
return V_350 . V_352 ( V_348 ) ;
}
static int F_241 ( struct V_30 * V_15 ,
struct V_349 * V_350 )
{
V_350 -> V_352 = F_240 ;
return 0 ;
}
static int F_242 ( struct V_30 * V_33 , int V_354 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_36 ;
int V_21 = 0 ;
int V_37 ;
F_3 ( L_104 , V_11 ,
( V_33 ? V_33 -> V_16 : L_10 ) , V_354 ) ;
F_29 (bond, slave, i) {
F_3 ( L_105 ,
V_35 ,
V_35 -> V_27 ,
V_35 -> V_15 -> V_57 -> V_355 ) ;
V_21 = F_134 ( V_35 -> V_15 , V_354 ) ;
if ( V_21 ) {
F_3 ( L_106 , V_21 , V_35 -> V_15 -> V_16 ) ;
goto V_38;
}
}
V_33 -> V_186 = V_354 ;
return 0 ;
V_38:
V_36 = V_35 ;
F_32 (bond, slave, i, bond->first_slave, stop_at) {
int V_356 ;
V_356 = F_134 ( V_35 -> V_15 , V_33 -> V_186 ) ;
if ( V_356 ) {
F_3 ( L_107 ,
V_356 , V_35 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_243 ( struct V_30 * V_33 , void * V_77 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_168 * V_357 = V_77 , V_358 ;
struct V_35 * V_35 , * V_36 ;
int V_21 = 0 ;
int V_37 ;
if ( V_11 -> V_41 . V_1 == V_9 )
return F_244 ( V_33 , V_77 ) ;
F_3 ( L_108 ,
V_11 , V_33 ? V_33 -> V_16 : L_10 ) ;
if ( V_11 -> V_41 . V_120 == V_181 )
return 0 ;
if ( ! F_245 ( V_357 -> V_189 ) )
return - V_359 ;
F_29 (bond, slave, i) {
const struct V_55 * V_56 = V_35 -> V_15 -> V_57 ;
F_3 ( L_109 , V_35 , V_35 -> V_15 -> V_16 ) ;
if ( V_56 -> V_180 == NULL ) {
V_21 = - V_182 ;
F_3 ( L_110 , V_35 -> V_15 -> V_16 ) ;
goto V_38;
}
V_21 = F_135 ( V_35 -> V_15 , V_77 ) ;
if ( V_21 ) {
F_3 ( L_106 , V_21 , V_35 -> V_15 -> V_16 ) ;
goto V_38;
}
}
memcpy ( V_33 -> V_138 , V_357 -> V_189 , V_33 -> V_137 ) ;
return 0 ;
V_38:
memcpy ( V_358 . V_189 , V_33 -> V_138 , V_33 -> V_137 ) ;
V_358 . V_190 = V_33 -> type ;
V_36 = V_35 ;
F_32 (bond, slave, i, bond->first_slave, stop_at) {
int V_356 ;
V_356 = F_135 ( V_35 -> V_15 , & V_358 ) ;
if ( V_356 ) {
F_3 ( L_107 ,
V_356 , V_35 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_246 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_360 ;
int V_37 , V_361 , V_21 = 1 ;
struct V_277 * V_278 = F_210 ( V_29 ) ;
if ( ( V_278 -> V_245 == V_362 ) &&
( V_29 -> V_245 == F_190 ( V_252 ) ) ) {
F_66 ( & V_11 -> V_122 ) ;
V_35 = V_11 -> V_76 ;
F_69 ( & V_11 -> V_122 ) ;
if ( ! V_35 )
goto V_23;
} else {
V_361 = V_11 -> V_363 ++ % V_11 -> V_39 ;
F_29 (bond, slave, i) {
V_361 -- ;
if ( V_361 < 0 )
break;
}
}
V_360 = V_35 ;
F_78 (bond, slave, i, start_at) {
if ( F_79 ( V_35 -> V_15 ) &&
( V_35 -> V_42 == V_43 ) &&
F_148 ( V_35 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
break;
}
}
V_23:
if ( V_21 ) {
F_120 ( V_29 ) ;
}
return V_364 ;
}
static int F_247 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
int V_21 = 1 ;
F_66 ( & V_11 -> V_122 ) ;
if ( V_11 -> V_76 )
V_21 = F_20 ( V_11 , V_29 ,
V_11 -> V_76 -> V_15 ) ;
if ( V_21 )
F_120 ( V_29 ) ;
F_69 ( & V_11 -> V_122 ) ;
return V_364 ;
}
static int F_248 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_360 ;
int V_361 ;
int V_37 ;
int V_21 = 1 ;
V_361 = V_11 -> V_365 ( V_29 , V_11 -> V_39 ) ;
F_29 (bond, slave, i) {
V_361 -- ;
if ( V_361 < 0 )
break;
}
V_360 = V_35 ;
F_78 (bond, slave, i, start_at) {
if ( F_79 ( V_35 -> V_15 ) &&
( V_35 -> V_42 == V_43 ) &&
F_148 ( V_35 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_120 ( V_29 ) ;
}
return V_364 ;
}
static int F_249 ( struct V_28 * V_29 , struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_35 * V_35 , * V_360 ;
struct V_30 * V_366 = NULL ;
int V_37 ;
int V_21 = 1 ;
F_66 ( & V_11 -> V_122 ) ;
V_360 = V_11 -> V_76 ;
F_69 ( & V_11 -> V_122 ) ;
if ( ! V_360 )
goto V_23;
F_78 (bond, slave, i, start_at) {
if ( F_79 ( V_35 -> V_15 ) &&
( V_35 -> V_42 == V_43 ) &&
F_148 ( V_35 ) ) {
if ( V_366 ) {
struct V_28 * V_367 = F_118 ( V_29 , V_159 ) ;
if ( ! V_367 ) {
F_31 ( L_111 ,
V_33 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_367 , V_366 ) ;
if ( V_21 ) {
F_120 ( V_367 ) ;
continue;
}
}
V_366 = V_35 -> V_15 ;
}
}
if ( V_366 )
V_21 = F_20 ( V_11 , V_29 , V_366 ) ;
V_23:
if ( V_21 )
F_120 ( V_29 ) ;
return V_364 ;
}
static void F_250 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_41 . V_368 ) {
case V_369 :
V_11 -> V_365 = F_209 ;
break;
case V_370 :
V_11 -> V_365 = F_212 ;
break;
case V_371 :
default:
V_11 -> V_365 = F_215 ;
break;
}
}
static inline int F_251 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
int V_37 , V_21 = 1 ;
struct V_35 * V_35 = NULL ;
struct V_35 * V_372 ;
if ( ! V_29 -> V_32 )
return 1 ;
F_29 (bond, check_slave, i) {
if ( V_372 -> V_184 == V_29 -> V_32 ) {
V_35 = V_372 ;
break;
}
}
if ( V_35 && V_35 -> V_184 && F_79 ( V_35 -> V_15 ) &&
( V_35 -> V_42 == V_43 ) ) {
V_21 = F_20 ( V_11 , V_29 , V_35 -> V_15 ) ;
}
return V_21 ;
}
static T_9 F_252 ( struct V_30 * V_15 , struct V_28 * V_29 )
{
T_9 V_373 = F_253 ( V_29 ) ? F_254 ( V_29 ) : 0 ;
F_21 ( V_29 ) = V_29 -> V_32 ;
if ( F_22 ( V_373 >= V_15 -> V_374 ) ) {
do {
V_373 -= V_15 -> V_374 ;
} while ( V_373 >= V_15 -> V_374 );
}
return V_373 ;
}
static T_10 F_255 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
if ( F_256 ( V_11 -> V_41 . V_1 ) ) {
if ( ! F_251 ( V_11 , V_29 ) )
return V_364 ;
}
switch ( V_11 -> V_41 . V_1 ) {
case V_3 :
return F_246 ( V_29 , V_15 ) ;
case V_4 :
return F_247 ( V_29 , V_15 ) ;
case V_5 :
return F_248 ( V_29 , V_15 ) ;
case V_6 :
return F_249 ( V_29 , V_15 ) ;
case V_7 :
return F_257 ( V_29 , V_15 ) ;
case V_9 :
case V_8 :
return F_258 ( V_29 , V_15 ) ;
default:
F_31 ( L_112 ,
V_15 -> V_16 , V_11 -> V_41 . V_1 ) ;
F_259 ( 1 ) ;
F_120 ( V_29 ) ;
return V_364 ;
}
}
static T_10 F_260 ( struct V_28 * V_29 , struct V_30 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_10 V_157 = V_364 ;
if ( F_261 ( V_15 ) )
return V_375 ;
F_66 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_39 )
V_157 = F_255 ( V_29 , V_15 ) ;
else
F_120 ( V_29 ) ;
F_69 ( & V_11 -> V_20 ) ;
return V_157 ;
}
void F_262 ( struct V_10 * V_11 , int V_1 )
{
struct V_30 * V_33 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_250 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_250 ( V_11 ) ;
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
static void F_263 ( struct V_30 * V_33 ,
struct V_376 * V_377 )
{
strncpy ( V_377 -> V_378 , V_379 , 32 ) ;
strncpy ( V_377 -> V_380 , V_381 , 32 ) ;
snprintf ( V_377 -> V_382 , 32 , L_113 , V_383 ) ;
}
static void F_264 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
if ( V_11 -> V_87 )
F_265 ( V_11 -> V_87 ) ;
F_266 ( V_33 ) ;
}
static void F_267 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
F_268 ( & V_11 -> V_20 ) ;
F_268 ( & V_11 -> V_122 ) ;
V_11 -> V_41 = V_384 ;
V_11 -> V_15 = V_33 ;
F_5 ( & V_11 -> V_19 ) ;
F_131 ( V_33 ) ;
V_33 -> V_57 = & V_385 ;
V_33 -> V_64 = & V_386 ;
F_262 ( V_11 , V_11 -> V_41 . V_1 ) ;
V_33 -> V_387 = F_264 ;
V_33 -> V_388 = 0 ;
V_33 -> V_99 |= V_274 | V_389 ;
V_33 -> V_83 |= V_194 ;
V_33 -> V_83 &= ~ ( V_390 | V_177 ) ;
V_33 -> V_139 |= V_141 ;
V_33 -> V_139 |= V_391 ;
V_33 -> V_392 = V_145 |
V_393 |
V_394 |
V_395 ;
V_33 -> V_392 &= ~ ( V_396 & ~ V_397 ) ;
V_33 -> V_139 |= V_33 -> V_392 ;
}
static void F_269 ( struct V_10 * V_11 )
{
if ( V_11 -> V_41 . V_118 && F_222 ( & V_11 -> V_225 ) )
F_221 ( & V_11 -> V_225 ) ;
if ( V_11 -> V_41 . V_161 && F_222 ( & V_11 -> V_255 ) )
F_221 ( & V_11 -> V_255 ) ;
if ( V_11 -> V_41 . V_1 == V_9 &&
F_222 ( & V_11 -> V_287 ) )
F_221 ( & V_11 -> V_287 ) ;
if ( V_11 -> V_41 . V_1 == V_7 &&
F_222 ( & V_11 -> V_289 ) )
F_221 ( & V_11 -> V_289 ) ;
if ( F_222 ( & V_11 -> V_88 ) )
F_221 ( & V_11 -> V_88 ) ;
}
static void F_270 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_13 * V_14 , * V_398 ;
F_102 ( V_33 ) ;
F_159 ( V_33 ) ;
F_12 ( & V_11 -> V_399 ) ;
F_269 ( V_11 ) ;
F_201 ( V_11 ) ;
F_271 ( V_11 ) ;
F_238 ( & V_11 -> V_344 ) ;
F_272 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_273 ( const char * V_400 , const struct V_401 * V_402 )
{
int V_403 = - 1 , V_37 , V_127 ;
char * V_404 , V_405 [ V_406 + 1 ] = { 0 , } ;
for ( V_404 = ( char * ) V_400 ; * V_404 ; V_404 ++ )
if ( ! ( isdigit ( * V_404 ) || isspace ( * V_404 ) ) )
break;
if ( * V_404 )
V_127 = sscanf ( V_400 , L_114 , V_405 ) ;
else
V_127 = sscanf ( V_400 , L_113 , & V_403 ) ;
if ( ! V_127 )
return - 1 ;
for ( V_37 = 0 ; V_402 [ V_37 ] . V_407 ; V_37 ++ ) {
if ( V_403 == V_402 [ V_37 ] . V_1 )
return V_402 [ V_37 ] . V_1 ;
if ( strcmp ( V_405 , V_402 [ V_37 ] . V_407 ) == 0 )
return V_402 [ V_37 ] . V_1 ;
}
return - 1 ;
}
static int F_274 ( struct V_408 * V_41 )
{
int V_409 , V_410 , V_411 ;
if ( V_1 ) {
V_211 = F_273 ( V_1 , V_412 ) ;
if ( V_211 == - 1 ) {
F_31 ( L_115 ,
V_1 == NULL ? L_18 : V_1 ) ;
return - V_179 ;
}
}
if ( V_365 ) {
if ( ( V_211 != V_5 ) &&
( V_211 != V_7 ) ) {
F_83 ( L_116 ,
F_1 ( V_211 ) ) ;
} else {
V_413 = F_273 ( V_365 ,
V_414 ) ;
if ( V_413 == - 1 ) {
F_31 ( L_117 ,
V_365 == NULL ? L_18 :
V_365 ) ;
return - V_179 ;
}
}
}
if ( V_415 ) {
if ( V_211 != V_7 ) {
F_83 ( L_118 ,
F_1 ( V_211 ) ) ;
} else {
V_416 = F_273 ( V_415 , V_417 ) ;
if ( V_416 == - 1 ) {
F_31 ( L_119 ,
V_415 == NULL ? L_18 : V_415 ) ;
return - V_179 ;
}
}
}
if ( V_418 ) {
V_41 -> V_418 = F_273 ( V_418 , V_419 ) ;
if ( V_41 -> V_418 == - 1 ) {
F_31 ( L_120 ,
V_418 == NULL ? L_18 : V_418 ) ;
return - V_179 ;
}
if ( V_211 != V_7 ) {
F_36 ( L_121 ) ;
}
} else {
V_41 -> V_418 = V_420 ;
}
if ( V_421 < 0 ) {
F_36 ( L_122 ,
V_421 , 0 , V_422 , V_423 ) ;
V_421 = V_423 ;
}
if ( V_118 < 0 ) {
F_36 ( L_123 ,
V_118 , V_422 , V_424 ) ;
V_118 = V_424 ;
}
if ( V_110 < 0 ) {
F_36 ( L_124 ,
V_110 , V_422 ) ;
V_110 = 0 ;
}
if ( V_222 < 0 ) {
F_36 ( L_125 ,
V_222 , V_422 ) ;
V_222 = 0 ;
}
if ( ( V_62 != 0 ) && ( V_62 != 1 ) ) {
F_36 ( L_126 ,
V_62 ) ;
V_62 = 1 ;
}
if ( V_121 < 0 || V_121 > 255 ) {
F_36 ( L_127 ,
V_121 ) ;
V_121 = 1 ;
}
if ( V_211 == V_7 ) {
if ( ! V_118 ) {
F_36 ( L_128 ) ;
F_36 ( L_129 ) ;
V_118 = 100 ;
}
}
if ( V_425 < 1 || V_425 > 255 ) {
F_36 ( L_130
L_131 ,
V_425 , V_426 ) ;
V_425 = V_426 ;
}
if ( ( V_427 != 0 ) && ( V_427 != 1 ) ) {
F_36 ( L_132
L_133
L_134 , V_427 ) ;
V_427 = 0 ;
}
if ( V_125 < 0 || V_125 > 255 ) {
F_36 ( L_135
L_136 ,
V_125 , V_428 ) ;
V_125 = V_428 ;
}
if ( ( V_211 == V_8 ) ||
( V_211 == V_9 ) ) {
if ( ! V_118 ) {
F_36 ( L_137 ) ;
F_36 ( L_129 ) ;
V_118 = 100 ;
}
}
if ( V_211 == V_9 ) {
F_275 ( L_138 ,
V_110 ) ;
}
if ( ! V_118 ) {
if ( V_110 || V_222 ) {
F_36 ( L_139 ,
V_110 , V_222 ) ;
}
} else {
if ( V_161 ) {
F_36 ( L_140 ,
V_118 , V_161 ) ;
V_161 = 0 ;
}
if ( ( V_110 % V_118 ) != 0 ) {
F_36 ( L_141 ,
V_110 , V_118 ,
( V_110 / V_118 ) * V_118 ) ;
}
V_110 /= V_118 ;
if ( ( V_222 % V_118 ) != 0 ) {
F_36 ( L_142 ,
V_222 , V_118 ,
( V_222 / V_118 ) * V_118 ) ;
}
V_222 /= V_118 ;
}
if ( V_161 < 0 ) {
F_36 ( L_143 ,
V_161 , V_422 , V_429 ) ;
V_161 = V_429 ;
}
for ( V_430 = 0 ;
( V_430 < V_236 ) && V_431 [ V_430 ] ;
V_430 ++ ) {
if ( ! isdigit ( V_431 [ V_430 ] [ 0 ] ) ) {
F_36 ( L_144 ,
V_431 [ V_430 ] ) ;
V_161 = 0 ;
} else {
T_6 V_227 = F_276 ( V_431 [ V_430 ] ) ;
V_432 [ V_430 ] = V_227 ;
}
}
if ( V_161 && ! V_430 ) {
F_36 ( L_145 ,
V_161 ) ;
V_161 = 0 ;
}
if ( V_254 ) {
if ( V_211 != V_4 ) {
F_31 ( L_146 ) ;
return - V_179 ;
}
if ( ! V_161 ) {
F_31 ( L_147 ) ;
return - V_179 ;
}
V_409 = F_273 ( V_254 ,
V_433 ) ;
if ( V_409 == - 1 ) {
F_31 ( L_148 ,
V_254 == NULL ? L_18 : V_254 ) ;
return - V_179 ;
}
} else
V_409 = 0 ;
if ( V_118 ) {
F_83 ( L_149 , V_118 ) ;
} else if ( V_161 ) {
int V_37 ;
F_83 ( L_150 ,
V_161 ,
V_433 [ V_409 ] . V_407 ,
V_430 ) ;
for ( V_37 = 0 ; V_37 < V_430 ; V_37 ++ )
F_83 ( L_151 , V_431 [ V_37 ] ) ;
F_83 ( L_152 ) ;
} else if ( V_421 ) {
F_3 ( L_153 ) ;
}
if ( V_199 && ! F_52 ( V_211 ) ) {
F_36 ( L_154 ,
V_199 , F_1 ( V_211 ) ) ;
V_199 = NULL ;
}
if ( V_199 && V_105 ) {
V_411 = F_273 ( V_105 ,
V_434 ) ;
if ( V_411 == - 1 ) {
F_31 ( L_155 ,
V_105 ==
NULL ? L_18 : V_105 ) ;
return - V_179 ;
}
} else {
V_411 = V_435 ;
}
if ( V_120 ) {
V_410 = F_273 ( V_120 ,
V_436 ) ;
if ( V_410 == - 1 ) {
F_31 ( L_156 ,
V_254 == NULL ? L_18 : V_254 ) ;
return - V_179 ;
}
if ( V_211 != V_4 )
F_36 ( L_157 ) ;
} else {
V_410 = V_437 ;
}
V_41 -> V_1 = V_211 ;
V_41 -> V_368 = V_413 ;
V_41 -> V_118 = V_118 ;
V_41 -> V_121 = V_121 ;
V_41 -> V_161 = V_161 ;
V_41 -> V_254 = V_409 ;
V_41 -> V_110 = V_110 ;
V_41 -> V_222 = V_222 ;
V_41 -> V_62 = V_62 ;
V_41 -> V_416 = V_416 ;
V_41 -> V_199 [ 0 ] = 0 ;
V_41 -> V_105 = V_411 ;
V_41 -> V_120 = V_410 ;
V_41 -> V_425 = V_425 ;
V_41 -> V_427 = V_427 ;
V_41 -> V_125 = V_125 ;
V_41 -> V_438 = V_438 ;
if ( V_199 ) {
strncpy ( V_41 -> V_199 , V_199 , V_68 ) ;
V_41 -> V_199 [ V_68 - 1 ] = 0 ;
}
memcpy ( V_41 -> V_233 , V_432 , sizeof( V_432 ) ) ;
return 0 ;
}
static void F_277 ( struct V_30 * V_15 ,
struct V_439 * V_373 ,
void * V_440 )
{
F_278 ( & V_373 -> V_441 ,
& V_442 ) ;
}
static void F_279 ( struct V_30 * V_15 )
{
F_278 ( & V_15 -> V_443 ,
& V_444 ) ;
F_280 ( V_15 , F_277 , NULL ) ;
}
static int F_281 ( struct V_30 * V_33 )
{
struct V_10 * V_11 = F_28 ( V_33 ) ;
struct V_445 * V_446 = F_282 ( F_180 ( V_33 ) , V_447 ) ;
struct V_448 * V_449 = & ( F_283 ( V_11 ) ) ;
F_3 ( L_158 , V_33 -> V_16 ) ;
F_284 ( & ( V_449 -> V_450 ) ) ;
F_284 ( & ( V_449 -> V_451 ) ) ;
V_11 -> V_87 = F_285 ( V_33 -> V_16 ) ;
if ( ! V_11 -> V_87 )
return - V_18 ;
F_279 ( V_33 ) ;
F_202 ( V_11 ) ;
F_7 ( & V_11 -> V_399 , & V_446 -> V_452 ) ;
F_286 ( V_11 ) ;
F_287 ( V_11 ) ;
F_288 ( & V_11 -> V_344 ) ;
return 0 ;
}
static int F_289 ( struct V_453 * V_454 [] , struct V_453 * V_166 [] )
{
if ( V_454 [ V_455 ] ) {
if ( F_290 ( V_454 [ V_455 ] ) != V_95 )
return - V_179 ;
if ( ! F_245 ( F_291 ( V_454 [ V_455 ] ) ) )
return - V_359 ;
}
return 0 ;
}
static int F_292 ( struct V_456 * V_456 , struct V_453 * V_454 [] ,
unsigned int * V_457 ,
unsigned int * V_458 )
{
* V_457 = V_425 ;
return 0 ;
}
int F_293 ( struct V_456 * V_456 , const char * V_16 )
{
struct V_30 * V_33 ;
int V_21 ;
F_294 () ;
V_33 = F_295 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_159 ,
F_267 , V_425 ) ;
if ( ! V_33 ) {
F_31 ( L_160 , V_16 ) ;
F_171 () ;
return - V_18 ;
}
F_296 ( V_33 , V_456 ) ;
V_33 -> V_459 = & V_460 ;
V_21 = F_297 ( V_33 ) ;
F_42 ( V_33 ) ;
F_171 () ;
if ( V_21 < 0 )
F_264 ( V_33 ) ;
return V_21 ;
}
static int T_11 F_298 ( struct V_456 * V_456 )
{
struct V_445 * V_446 = F_282 ( V_456 , V_447 ) ;
V_446 -> V_456 = V_456 ;
F_5 ( & V_446 -> V_452 ) ;
F_299 ( V_446 ) ;
F_300 ( V_446 ) ;
return 0 ;
}
static void T_12 F_301 ( struct V_456 * V_456 )
{
struct V_445 * V_446 = F_282 ( V_456 , V_447 ) ;
F_302 ( V_446 ) ;
F_303 ( V_446 ) ;
}
static int T_13 F_304 ( void )
{
int V_37 ;
int V_21 ;
F_83 ( L_161 , V_461 ) ;
V_21 = F_274 ( & V_384 ) ;
if ( V_21 )
goto V_23;
V_21 = F_305 ( & V_462 ) ;
if ( V_21 )
goto V_23;
V_21 = F_306 ( & V_460 ) ;
if ( V_21 )
goto V_463;
F_307 () ;
for ( V_37 = 0 ; V_37 < V_421 ; V_37 ++ ) {
V_21 = F_293 ( & V_464 , NULL ) ;
if ( V_21 )
goto V_75;
}
F_308 ( & V_465 ) ;
V_23:
return V_21 ;
V_75:
F_309 ( & V_460 ) ;
V_463:
F_310 ( & V_462 ) ;
goto V_23;
}
static void T_14 F_311 ( void )
{
F_312 ( & V_465 ) ;
F_313 () ;
F_309 ( & V_460 ) ;
F_310 ( & V_462 ) ;
#ifdef F_145
F_314 ( F_315 ( & V_466 ) ) ;
#endif
}
