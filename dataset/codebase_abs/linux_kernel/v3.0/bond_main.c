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
if ( F_16 ( & V_11 -> V_19 ) &&
( V_11 -> V_23 == 0 ) ) {
V_11 -> V_15 -> V_24 |= V_25 ;
}
V_21 = 0 ;
goto V_26;
}
}
F_3 ( L_13 ,
V_12 , V_11 -> V_15 -> V_16 ) ;
V_26:
F_8 ( & V_11 -> V_20 ) ;
F_17 () ;
return V_21 ;
}
struct V_13 * F_18 ( struct V_10 * V_11 , struct V_13 * V_27 )
{
struct V_13 * V_28 , * V_29 ;
if ( F_16 ( & V_11 -> V_19 ) )
return NULL ;
if ( ! V_27 ) {
V_28 = F_19 ( V_11 -> V_19 . V_28 ,
struct V_13 , V_19 ) ;
} else {
V_29 = F_19 ( V_11 -> V_19 . V_30 ,
struct V_13 , V_19 ) ;
if ( V_29 == V_27 ) {
V_28 = F_19 ( V_11 -> V_19 . V_28 ,
struct V_13 , V_19 ) ;
} else {
V_28 = F_19 ( V_27 -> V_19 . V_28 ,
struct V_13 , V_19 ) ;
}
}
return V_28 ;
}
int F_20 ( struct V_10 * V_11 , struct V_31 * V_32 ,
struct V_33 * V_34 )
{
V_32 -> V_15 = V_34 ;
V_32 -> V_35 = 1 ;
V_32 -> V_36 = F_21 ( V_32 ) ;
if ( F_22 ( F_23 ( V_34 ) ) )
F_24 ( F_25 ( V_11 , V_34 ) , V_32 ) ;
else
F_26 ( V_32 ) ;
return 0 ;
}
static void F_27 ( struct V_33 * V_37 ,
struct V_38 * V_39 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 ;
int V_41 ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_42 = V_39 ;
F_8 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
struct V_33 * V_34 = V_40 -> V_15 ;
const struct V_43 * V_44 = V_34 -> V_45 ;
if ( ( V_34 -> V_24 & V_46 ) &&
V_44 -> V_47 ) {
V_44 -> V_47 ( V_34 , V_39 ) ;
}
}
}
static void F_30 ( struct V_33 * V_37 , T_1 V_48 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 ;
int V_41 , V_21 ;
F_29 (bond, slave, i) {
struct V_33 * V_34 = V_40 -> V_15 ;
const struct V_43 * V_44 = V_34 -> V_45 ;
if ( ( V_34 -> V_24 & V_49 ) &&
V_44 -> V_50 ) {
V_44 -> V_50 ( V_34 , V_48 ) ;
}
}
V_21 = F_2 ( V_11 , V_48 ) ;
if ( V_21 ) {
F_31 ( L_14 ,
V_37 -> V_16 , V_48 ) ;
}
}
static void F_32 ( struct V_33 * V_37 , T_1 V_48 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 ;
struct V_33 * V_51 ;
int V_41 , V_21 ;
F_29 (bond, slave, i) {
struct V_33 * V_34 = V_40 -> V_15 ;
const struct V_43 * V_44 = V_34 -> V_45 ;
if ( ( V_34 -> V_24 & V_49 ) &&
V_44 -> V_52 ) {
V_51 = F_33 ( V_11 -> V_42 , V_48 ) ;
V_44 -> V_52 ( V_34 , V_48 ) ;
F_34 ( V_11 -> V_42 , V_48 , V_51 ) ;
}
}
V_21 = F_9 ( V_11 , V_48 ) ;
if ( V_21 ) {
F_31 ( L_15 ,
V_37 -> V_16 , V_48 ) ;
}
}
static void F_35 ( struct V_10 * V_11 , struct V_33 * V_34 )
{
struct V_13 * V_14 ;
const struct V_43 * V_44 = V_34 -> V_45 ;
if ( ! V_11 -> V_42 )
return;
if ( ( V_34 -> V_24 & V_46 ) &&
V_44 -> V_47 )
V_44 -> V_47 ( V_34 , V_11 -> V_42 ) ;
if ( ! ( V_34 -> V_24 & V_49 ) ||
! ( V_44 -> V_50 ) )
return;
F_11 (vlan, &bond->vlan_list, vlan_list)
V_44 -> V_50 ( V_34 , V_14 -> V_12 ) ;
}
static void F_36 ( struct V_10 * V_11 ,
struct V_33 * V_34 )
{
const struct V_43 * V_44 = V_34 -> V_45 ;
struct V_13 * V_14 ;
struct V_33 * V_51 ;
if ( ! V_11 -> V_42 )
return;
if ( ! ( V_34 -> V_24 & V_49 ) ||
! ( V_44 -> V_52 ) )
goto V_53;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( ! V_14 -> V_12 )
continue;
V_51 = F_33 ( V_11 -> V_42 , V_14 -> V_12 ) ;
V_44 -> V_52 ( V_34 , V_14 -> V_12 ) ;
F_34 ( V_11 -> V_42 , V_14 -> V_12 , V_51 ) ;
}
V_53:
if ( ( V_34 -> V_24 & V_46 ) &&
V_44 -> V_47 )
V_44 -> V_47 ( V_34 , NULL ) ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_40 * V_40 ;
int V_41 ;
if ( V_11 -> V_23 == 0 )
goto V_54;
if ( V_11 -> V_55 . V_1 == V_7 )
return F_38 ( V_11 ) ;
F_29 (bond, slave, i) {
if ( V_40 -> V_56 == V_57 ) {
if ( ! F_39 ( V_11 -> V_15 ) ) {
F_40 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
}
V_54:
if ( F_39 ( V_11 -> V_15 ) ) {
F_41 ( V_11 -> V_15 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_40 * V_40 )
{
struct V_33 * V_34 = V_40 -> V_15 ;
struct V_58 V_59 = { . V_60 = V_61 } ;
T_2 V_62 ;
int V_21 ;
V_40 -> V_63 = V_64 ;
V_40 -> V_65 = V_66 ;
if ( ! V_34 -> V_67 || ! V_34 -> V_67 -> V_68 )
return - 1 ;
V_21 = V_34 -> V_67 -> V_68 ( V_34 , & V_59 ) ;
if ( V_21 < 0 )
return - 1 ;
V_62 = F_43 ( & V_59 ) ;
switch ( V_62 ) {
case V_69 :
case V_64 :
case V_70 :
case V_71 :
break;
default:
return - 1 ;
}
switch ( V_59 . V_65 ) {
case V_66 :
case V_72 :
break;
default:
return - 1 ;
}
V_40 -> V_63 = V_62 ;
V_40 -> V_65 = V_59 . V_65 ;
return 0 ;
}
static int F_44 ( struct V_10 * V_11 ,
struct V_33 * V_34 , int V_73 )
{
const struct V_43 * V_44 = V_34 -> V_45 ;
int (* F_45)( struct V_33 * , struct V_74 * , int );
struct V_74 V_75 ;
struct V_76 * V_77 ;
if ( ! V_73 && ! F_46 ( V_34 ) )
return 0 ;
if ( V_11 -> V_55 . V_78 )
return F_39 ( V_34 ) ? V_79 : 0 ;
if ( V_34 -> V_67 ) {
if ( V_34 -> V_67 -> V_80 ) {
T_2 V_56 ;
V_56 = V_34 -> V_67 -> V_80 ( V_34 ) ;
return V_56 ? V_79 : 0 ;
}
}
F_45 = V_44 -> V_81 ;
if ( F_45 ) {
strncpy ( V_75 . V_82 , V_34 -> V_16 , V_83 ) ;
V_77 = F_47 ( & V_75 ) ;
if ( F_48 ( V_34 , & V_75 , V_84 ) == 0 ) {
V_77 -> V_85 = V_86 ;
if ( F_48 ( V_34 , & V_75 , V_87 ) == 0 )
return V_77 -> V_88 & V_79 ;
}
}
return V_73 ? - 1 : V_79 ;
}
static int F_49 ( struct V_10 * V_11 , int V_89 )
{
int V_90 = 0 ;
if ( F_50 ( V_11 -> V_55 . V_1 ) ) {
if ( V_11 -> V_91 ) {
V_90 = F_51 ( V_11 -> V_91 -> V_15 ,
V_89 ) ;
}
} else {
struct V_40 * V_40 ;
int V_41 ;
F_29 (bond, slave, i) {
V_90 = F_51 ( V_40 -> V_15 , V_89 ) ;
if ( V_90 )
return V_90 ;
}
}
return V_90 ;
}
static int F_52 ( struct V_10 * V_11 , int V_89 )
{
int V_90 = 0 ;
if ( F_50 ( V_11 -> V_55 . V_1 ) ) {
if ( V_11 -> V_91 ) {
V_90 = F_53 ( V_11 -> V_91 -> V_15 ,
V_89 ) ;
}
} else {
struct V_40 * V_40 ;
int V_41 ;
F_29 (bond, slave, i) {
V_90 = F_53 ( V_40 -> V_15 , V_89 ) ;
if ( V_90 )
return V_90 ;
}
}
return V_90 ;
}
static void F_54 ( struct V_10 * V_11 , void * V_92 )
{
if ( F_50 ( V_11 -> V_55 . V_1 ) ) {
if ( V_11 -> V_91 )
F_55 ( V_11 -> V_91 -> V_15 , V_92 ) ;
} else {
struct V_40 * V_40 ;
int V_41 ;
F_29 (bond, slave, i)
F_55 ( V_40 -> V_15 , V_92 ) ;
}
}
static void F_56 ( struct V_10 * V_11 , void * V_92 )
{
if ( F_50 ( V_11 -> V_55 . V_1 ) ) {
if ( V_11 -> V_91 )
F_57 ( V_11 -> V_91 -> V_15 , V_92 ) ;
} else {
struct V_40 * V_40 ;
int V_41 ;
F_29 (bond, slave, i) {
F_57 ( V_40 -> V_15 , V_92 ) ;
}
}
}
static void F_58 ( struct V_33 * V_15 )
{
struct V_93 * V_94 ;
F_59 () ;
V_94 = F_60 ( V_15 ) ;
if ( V_94 )
F_61 ( V_94 ) ;
F_62 () ;
}
static void F_63 ( struct V_10 * V_11 )
{
struct V_33 * V_51 ;
struct V_13 * V_14 ;
F_64 ( & V_11 -> V_20 ) ;
F_58 ( V_11 -> V_15 ) ;
if ( V_11 -> V_42 ) {
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_51 = F_33 ( V_11 -> V_42 ,
V_14 -> V_12 ) ;
if ( V_51 )
F_58 ( V_51 ) ;
}
}
if ( -- V_11 -> V_95 > 0 )
F_65 ( V_11 -> V_96 , & V_11 -> V_97 , V_98 / 5 ) ;
F_66 ( & V_11 -> V_20 ) ;
}
static void F_67 ( struct V_99 * V_100 )
{
struct V_10 * V_11 = F_68 ( V_100 , struct V_10 ,
V_97 . V_100 ) ;
F_63 ( V_11 ) ;
}
static void F_69 ( struct V_33 * V_37 ,
struct V_33 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_101 * V_102 ;
F_70 (ha, bond_dev)
F_57 ( V_34 , V_102 -> V_92 ) ;
if ( V_11 -> V_55 . V_1 == V_7 ) {
T_3 V_103 [ V_104 ] = V_105 ;
F_57 ( V_34 , V_103 ) ;
}
}
static void F_71 ( struct V_10 * V_11 , struct V_40 * V_106 ,
struct V_40 * V_107 )
{
struct V_101 * V_102 ;
if ( ! F_50 ( V_11 -> V_55 . V_1 ) )
return;
if ( V_107 ) {
if ( V_11 -> V_15 -> V_108 & V_109 )
F_51 ( V_107 -> V_15 , - 1 ) ;
if ( V_11 -> V_15 -> V_108 & V_110 )
F_53 ( V_107 -> V_15 , - 1 ) ;
F_70 (ha, bond->dev)
F_57 ( V_107 -> V_15 , V_102 -> V_92 ) ;
}
if ( V_106 ) {
if ( V_11 -> V_15 -> V_108 & V_109 )
F_51 ( V_106 -> V_15 , 1 ) ;
if ( V_11 -> V_15 -> V_108 & V_110 )
F_53 ( V_106 -> V_15 , 1 ) ;
F_70 (ha, bond->dev)
F_55 ( V_106 -> V_15 , V_102 -> V_92 ) ;
}
}
static void F_72 ( struct V_10 * V_11 ,
struct V_40 * V_106 ,
struct V_40 * V_107 )
__releases( &bond->curr_slave_lock
static bool F_73 ( struct V_10 * V_11 )
{
struct V_40 * V_111 = V_11 -> V_112 ;
struct V_40 * V_27 = V_11 -> V_91 ;
if ( ! V_111 || ! V_27 || V_27 -> V_56 != V_57 )
return true ;
if ( V_11 -> V_113 ) {
V_11 -> V_113 = false ;
return true ;
}
if ( V_11 -> V_55 . V_114 == V_115 &&
( V_111 -> V_63 < V_27 -> V_63 ||
( V_111 -> V_63 == V_27 -> V_63 && V_111 -> V_65 <= V_27 -> V_65 ) ) )
return false ;
if ( V_11 -> V_55 . V_114 == V_116 )
return false ;
return true ;
}
static struct V_40 * F_74 ( struct V_10 * V_11 )
{
struct V_40 * V_106 , * V_107 ;
struct V_40 * V_117 = NULL ;
int V_118 = V_11 -> V_55 . V_119 ;
int V_41 ;
V_106 = V_11 -> V_91 ;
if ( ! V_106 ) {
if ( V_11 -> V_23 > 0 )
V_106 = V_11 -> V_120 ;
else
return NULL ;
}
if ( ( V_11 -> V_112 ) &&
V_11 -> V_112 -> V_56 == V_57 &&
F_73 ( V_11 ) ) {
V_106 = V_11 -> V_112 ;
}
V_107 = V_106 ;
F_75 (bond, new_active, i, old_active) {
if ( V_106 -> V_56 == V_57 ) {
return V_106 ;
} else if ( V_106 -> V_56 == V_121 &&
F_76 ( V_106 -> V_15 ) ) {
if ( V_106 -> V_122 < V_118 ) {
V_118 = V_106 -> V_122 ;
V_117 = V_106 ;
}
}
}
return V_117 ;
}
static bool F_77 ( struct V_10 * V_11 )
{
struct V_40 * V_40 = V_11 -> V_91 ;
F_3 ( L_16 ,
V_11 -> V_15 -> V_16 , V_40 ? V_40 -> V_15 -> V_16 : L_17 ) ;
if ( ! V_40 || ! V_11 -> V_123 ||
F_78 ( V_124 , & V_40 -> V_15 -> V_125 ) )
return false ;
V_11 -> V_123 -- ;
return true ;
}
void F_79 ( struct V_10 * V_11 , struct V_40 * V_106 )
{
struct V_40 * V_107 = V_11 -> V_91 ;
if ( V_107 == V_106 )
return;
if ( V_106 ) {
V_106 -> V_126 = V_126 ;
if ( V_106 -> V_56 == V_121 ) {
if ( F_50 ( V_11 -> V_55 . V_1 ) ) {
F_80 ( L_18 ,
V_11 -> V_15 -> V_16 , V_106 -> V_15 -> V_16 ,
( V_11 -> V_55 . V_119 - V_106 -> V_122 ) * V_11 -> V_55 . V_127 ) ;
}
V_106 -> V_122 = 0 ;
V_106 -> V_56 = V_57 ;
if ( V_11 -> V_55 . V_1 == V_7 )
F_81 ( V_106 , V_57 ) ;
if ( F_13 ( V_11 ) )
F_82 ( V_11 , V_106 , V_57 ) ;
} else {
if ( F_50 ( V_11 -> V_55 . V_1 ) ) {
F_80 ( L_19 ,
V_11 -> V_15 -> V_16 , V_106 -> V_15 -> V_16 ) ;
}
}
}
if ( F_50 ( V_11 -> V_55 . V_1 ) )
F_71 ( V_11 , V_106 , V_107 ) ;
if ( F_13 ( V_11 ) ) {
F_83 ( V_11 , V_106 ) ;
if ( V_107 )
F_84 ( V_107 ) ;
if ( V_106 )
F_85 ( V_106 ) ;
} else {
V_11 -> V_91 = V_106 ;
}
if ( V_11 -> V_55 . V_1 == V_4 ) {
if ( V_107 )
F_84 ( V_107 ) ;
if ( V_106 ) {
bool V_128 = false ;
F_85 ( V_106 ) ;
if ( V_11 -> V_55 . V_129 )
F_72 ( V_11 , V_106 ,
V_107 ) ;
if ( F_46 ( V_11 -> V_15 ) ) {
V_11 -> V_123 =
V_11 -> V_55 . V_130 ;
V_128 =
F_77 ( V_11 ) ;
}
F_8 ( & V_11 -> V_131 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_86 ( V_11 -> V_15 , V_132 ) ;
if ( V_128 )
F_86 ( V_11 -> V_15 ,
V_133 ) ;
F_64 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_131 ) ;
}
}
if ( F_46 ( V_11 -> V_15 ) && ( V_11 -> V_55 . V_134 > 0 ) &&
( ( F_50 ( V_11 -> V_55 . V_1 ) && V_106 ) ||
V_11 -> V_55 . V_1 == V_3 ) ) {
V_11 -> V_95 = V_11 -> V_55 . V_134 ;
F_65 ( V_11 -> V_96 , & V_11 -> V_97 , 0 ) ;
}
}
void F_87 ( struct V_10 * V_11 )
{
struct V_40 * V_135 ;
int V_136 ;
V_135 = F_74 ( V_11 ) ;
if ( V_135 != V_11 -> V_91 ) {
F_79 ( V_11 , V_135 ) ;
V_136 = F_37 ( V_11 ) ;
if ( ! V_136 )
return;
if ( F_39 ( V_11 -> V_15 ) ) {
F_80 ( L_20 ,
V_11 -> V_15 -> V_16 ) ;
} else {
F_80 ( L_21 ,
V_11 -> V_15 -> V_16 ) ;
}
}
}
static void F_88 ( struct V_10 * V_11 , struct V_40 * V_137 )
{
if ( V_11 -> V_120 == NULL ) {
V_137 -> V_28 = V_137 ;
V_137 -> V_30 = V_137 ;
V_11 -> V_120 = V_137 ;
} else {
V_137 -> V_28 = V_11 -> V_120 ;
V_137 -> V_30 = V_11 -> V_120 -> V_30 ;
V_137 -> V_28 -> V_30 = V_137 ;
V_137 -> V_30 -> V_28 = V_137 ;
}
V_11 -> V_23 ++ ;
}
static void F_89 ( struct V_10 * V_11 , struct V_40 * V_40 )
{
if ( V_40 -> V_28 )
V_40 -> V_28 -> V_30 = V_40 -> V_30 ;
if ( V_40 -> V_30 )
V_40 -> V_30 -> V_28 = V_40 -> V_28 ;
if ( V_11 -> V_120 == V_40 ) {
if ( V_11 -> V_23 > 1 ) {
V_11 -> V_120 = V_40 -> V_28 ;
} else {
V_11 -> V_120 = NULL ;
}
}
V_40 -> V_28 = NULL ;
V_40 -> V_30 = NULL ;
V_11 -> V_23 -- ;
}
static inline int F_90 ( struct V_40 * V_40 )
{
struct V_138 * V_139 ;
int V_90 = 0 ;
V_139 = F_4 ( sizeof( * V_139 ) , V_17 ) ;
V_90 = - V_18 ;
if ( ! V_139 )
goto V_26;
V_139 -> V_15 = V_40 -> V_15 ;
F_91 ( V_139 -> V_140 , V_40 -> V_15 -> V_16 , V_83 ) ;
V_90 = F_92 ( V_139 ) ;
if ( V_90 ) {
F_15 ( V_139 ) ;
goto V_26;
}
V_40 -> V_139 = V_139 ;
V_26:
return V_90 ;
}
static inline void F_93 ( struct V_40 * V_40 )
{
struct V_138 * V_139 = V_40 -> V_139 ;
if ( ! V_139 )
return;
V_40 -> V_139 = NULL ;
F_94 () ;
F_95 ( V_139 ) ;
F_15 ( V_139 ) ;
}
static inline bool F_96 ( struct V_33 * V_34 )
{
if ( V_34 -> V_141 & V_142 )
return false ;
if ( ! V_34 -> V_45 -> V_143 )
return false ;
return true ;
}
static void F_97 ( struct V_33 * V_37 )
{
}
static void F_98 ( struct V_10 * V_11 )
{
struct V_40 * V_40 ;
int V_41 ;
F_29 (bond, slave, i)
if ( F_76 ( V_40 -> V_15 ) )
F_93 ( V_40 ) ;
}
static void F_99 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
F_64 ( & V_11 -> V_20 ) ;
F_98 ( V_11 ) ;
F_66 ( & V_11 -> V_20 ) ;
}
static int F_100 ( struct V_33 * V_15 , struct V_144 * V_145 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
struct V_40 * V_40 ;
int V_41 , V_90 = 0 ;
F_64 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
V_90 = F_90 ( V_40 ) ;
if ( V_90 ) {
F_98 ( V_11 ) ;
break;
}
}
F_66 ( & V_11 -> V_20 ) ;
return V_90 ;
}
static struct V_144 * F_101 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -> V_146 ;
}
static inline int F_90 ( struct V_40 * V_40 )
{
return 0 ;
}
static inline void F_93 ( struct V_40 * V_40 )
{
}
static void F_99 ( struct V_33 * V_37 )
{
}
static int F_102 ( struct V_33 * V_37 ,
struct V_33 * V_34 )
{
F_3 ( L_22 , V_37 ) ;
F_3 ( L_23 , V_34 ) ;
F_3 ( L_24 , V_34 -> V_147 ) ;
memcpy ( V_37 -> V_148 , V_34 -> V_148 , V_34 -> V_147 ) ;
return 0 ;
}
static T_2 F_103 ( struct V_33 * V_15 , T_2 V_24 )
{
struct V_40 * V_40 ;
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_2 V_149 ;
int V_41 ;
F_64 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_120 ) {
V_24 |= V_25 ;
goto V_26;
}
V_149 = V_24 ;
V_24 &= ~ V_150 ;
V_24 |= V_151 ;
F_29 (bond, slave, i) {
V_24 = F_104 ( V_24 ,
V_40 -> V_15 -> V_24 ,
V_149 ) ;
}
V_26:
F_66 ( & V_11 -> V_20 ) ;
return V_24 ;
}
static void F_105 ( struct V_10 * V_11 )
{
struct V_40 * V_40 ;
struct V_33 * V_37 = V_11 -> V_15 ;
T_2 V_152 = V_153 ;
unsigned short V_154 = V_155 ;
int V_41 ;
F_64 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_120 )
goto V_156;
F_29 (bond, slave, i) {
V_152 = F_104 ( V_152 ,
V_40 -> V_15 -> V_152 , V_153 ) ;
if ( V_40 -> V_15 -> V_157 > V_154 )
V_154 = V_40 -> V_15 -> V_157 ;
}
V_156:
V_37 -> V_152 = V_152 ;
V_37 -> V_157 = V_154 ;
F_66 ( & V_11 -> V_20 ) ;
F_106 ( V_37 ) ;
}
static void F_107 ( struct V_33 * V_37 ,
struct V_33 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
V_37 -> V_158 = V_34 -> V_158 ;
V_37 -> type = V_34 -> type ;
V_37 -> V_157 = V_34 -> V_157 ;
V_37 -> V_147 = V_34 -> V_147 ;
memcpy ( V_37 -> V_159 , V_34 -> V_159 ,
V_34 -> V_147 ) ;
V_11 -> V_160 = 1 ;
}
static bool F_108 ( struct V_31 * V_32 ,
struct V_40 * V_40 ,
struct V_10 * V_11 )
{
if ( F_109 ( V_40 ) ) {
if ( V_11 -> V_55 . V_1 == V_9 &&
V_32 -> V_161 != V_162 &&
V_32 -> V_161 != V_163 )
return false ;
return true ;
}
return false ;
}
static T_4 F_110 ( struct V_31 * * V_164 )
{
struct V_31 * V_32 = * V_164 ;
struct V_40 * V_40 ;
struct V_10 * V_11 ;
V_32 = F_111 ( V_32 , V_165 ) ;
if ( F_22 ( ! V_32 ) )
return V_166 ;
* V_164 = V_32 ;
V_40 = F_112 ( V_32 -> V_15 ) ;
V_11 = V_40 -> V_11 ;
if ( V_11 -> V_55 . V_167 )
V_40 -> V_15 -> V_168 = V_126 ;
if ( V_11 -> V_169 ) {
struct V_31 * V_170 = F_113 ( V_32 , V_165 ) ;
if ( F_114 ( V_170 ) ) {
V_11 -> V_169 ( V_170 , V_11 , V_40 ) ;
F_115 ( V_170 ) ;
}
}
if ( F_108 ( V_32 , V_40 , V_11 ) ) {
return V_171 ;
}
V_32 -> V_15 = V_11 -> V_15 ;
if ( V_11 -> V_55 . V_1 == V_9 &&
V_11 -> V_15 -> V_141 & V_172 &&
V_32 -> V_161 == V_173 ) {
if ( F_22 ( F_116 ( V_32 ,
V_32 -> V_174 - F_117 ( V_32 ) ) ) ) {
F_118 ( V_32 ) ;
return V_166 ;
}
memcpy ( F_119 ( V_32 ) -> V_175 , V_11 -> V_15 -> V_148 , V_104 ) ;
}
return V_176 ;
}
int F_120 ( struct V_33 * V_37 , struct V_33 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
const struct V_43 * V_44 = V_34 -> V_45 ;
struct V_40 * V_137 = NULL ;
struct V_101 * V_102 ;
struct V_177 V_92 ;
int V_178 ;
int V_21 = 0 ;
if ( ! V_11 -> V_55 . V_78 && V_34 -> V_67 == NULL &&
V_44 -> V_81 == NULL ) {
F_121 ( L_25 ,
V_37 -> V_16 , V_34 -> V_16 ) ;
}
if ( V_34 -> V_108 & V_179 ) {
F_3 ( L_26 ) ;
return - V_180 ;
}
if ( V_34 -> V_24 & V_25 ) {
F_3 ( L_27 , V_34 -> V_16 ) ;
if ( V_11 -> V_42 ) {
F_31 ( L_28 ,
V_37 -> V_16 , V_34 -> V_16 , V_37 -> V_16 ) ;
return - V_181 ;
} else {
F_121 ( L_29 ,
V_37 -> V_16 , V_34 -> V_16 ,
V_34 -> V_16 , V_37 -> V_16 ) ;
}
} else {
F_3 ( L_30 , V_34 -> V_16 ) ;
}
if ( ( V_34 -> V_108 & V_182 ) ) {
F_31 ( L_31 ,
V_34 -> V_16 ) ;
V_21 = - V_181 ;
goto V_183;
}
if ( V_11 -> V_23 == 0 ) {
if ( V_37 -> type != V_34 -> type ) {
F_3 ( L_32 ,
V_37 -> V_16 ,
V_37 -> type , V_34 -> type ) ;
V_21 = F_86 ( V_37 ,
V_184 ) ;
V_21 = F_122 ( V_21 ) ;
if ( V_21 ) {
F_31 ( L_33 ,
V_37 -> V_16 ) ;
V_21 = - V_180 ;
goto V_183;
}
F_123 ( V_37 ) ;
F_124 ( V_37 ) ;
if ( V_34 -> type != V_185 )
F_107 ( V_37 , V_34 ) ;
else
F_125 ( V_37 ) ;
F_86 ( V_37 ,
V_186 ) ;
}
} else if ( V_37 -> type != V_34 -> type ) {
F_31 ( L_34 ,
V_34 -> V_16 ,
V_34 -> type , V_37 -> type ) ;
V_21 = - V_187 ;
goto V_183;
}
if ( V_44 -> V_188 == NULL ) {
if ( V_11 -> V_23 == 0 ) {
F_121 ( L_35 ,
V_37 -> V_16 ) ;
V_11 -> V_55 . V_129 = V_189 ;
} else if ( V_11 -> V_55 . V_129 != V_189 ) {
F_31 ( L_36 ,
V_37 -> V_16 ) ;
V_21 = - V_190 ;
goto V_183;
}
}
F_126 ( V_191 , V_34 ) ;
if ( F_127 ( V_11 -> V_15 -> V_148 ) )
memcpy ( V_11 -> V_15 -> V_148 , V_34 -> V_148 ,
V_34 -> V_147 ) ;
V_137 = F_4 ( sizeof( struct V_40 ) , V_17 ) ;
if ( ! V_137 ) {
V_21 = - V_18 ;
goto V_183;
}
V_137 -> V_192 = 0 ;
V_137 -> V_193 = V_34 -> V_194 ;
V_21 = F_128 ( V_34 , V_11 -> V_15 -> V_194 ) ;
if ( V_21 ) {
F_3 ( L_37 , V_21 ) ;
goto V_195;
}
memcpy ( V_137 -> V_196 , V_34 -> V_148 , V_104 ) ;
if ( ! V_11 -> V_55 . V_129 ) {
memcpy ( V_92 . V_197 , V_37 -> V_148 , V_37 -> V_147 ) ;
V_92 . V_198 = V_34 -> type ;
V_21 = F_129 ( V_34 , & V_92 ) ;
if ( V_21 ) {
F_3 ( L_38 , V_21 ) ;
goto V_199;
}
}
V_21 = F_130 ( V_34 , V_37 ) ;
if ( V_21 ) {
F_3 ( L_39 , V_21 ) ;
goto V_200;
}
V_21 = F_131 ( V_34 ) ;
if ( V_21 ) {
F_3 ( L_40 , V_34 -> V_16 ) ;
goto V_201;
}
V_137 -> V_11 = V_11 ;
V_137 -> V_15 = V_34 ;
V_34 -> V_141 |= V_202 ;
if ( F_13 ( V_11 ) ) {
V_21 = F_132 ( V_11 , V_137 ) ;
if ( V_21 )
goto V_203;
}
if ( ! F_50 ( V_11 -> V_55 . V_1 ) ) {
if ( V_37 -> V_108 & V_109 ) {
V_21 = F_51 ( V_34 , 1 ) ;
if ( V_21 )
goto V_203;
}
if ( V_37 -> V_108 & V_110 ) {
V_21 = F_53 ( V_34 , 1 ) ;
if ( V_21 )
goto V_203;
}
F_133 ( V_37 ) ;
F_70 (ha, bond_dev)
F_55 ( V_34 , V_102 -> V_92 ) ;
F_134 ( V_37 ) ;
}
if ( V_11 -> V_55 . V_1 == V_7 ) {
T_3 V_103 [ V_104 ] = V_105 ;
F_55 ( V_34 , V_103 ) ;
}
F_35 ( V_11 , V_34 ) ;
F_6 ( & V_11 -> V_20 ) ;
F_88 ( V_11 , V_137 ) ;
V_137 -> V_122 = 0 ;
V_137 -> V_204 = 0 ;
F_8 ( & V_11 -> V_20 ) ;
F_105 ( V_11 ) ;
F_64 ( & V_11 -> V_20 ) ;
V_137 -> V_205 = V_126 ;
if ( V_11 -> V_55 . V_127 && ! V_11 -> V_55 . V_78 ) {
V_178 = F_44 ( V_11 , V_34 , 1 ) ;
if ( ( V_178 == - 1 ) && ! V_11 -> V_55 . V_167 ) {
F_121 ( L_41 ,
V_37 -> V_16 , V_34 -> V_16 ) ;
} else if ( V_178 == - 1 ) {
F_121 ( L_42 ,
V_37 -> V_16 , V_34 -> V_16 ) ;
}
}
if ( ! V_11 -> V_55 . V_127 ||
( F_44 ( V_11 , V_34 , 0 ) == V_79 ) ) {
if ( V_11 -> V_55 . V_119 ) {
F_3 ( L_43 ) ;
V_137 -> V_56 = V_121 ;
V_137 -> V_122 = V_11 -> V_55 . V_119 ;
} else {
F_3 ( L_44 ) ;
V_137 -> V_56 = V_57 ;
}
V_137 -> V_126 = V_126 ;
} else {
F_3 ( L_45 ) ;
V_137 -> V_56 = V_206 ;
}
if ( F_42 ( V_137 ) &&
( V_137 -> V_56 != V_206 ) ) {
F_121 ( L_46 ,
V_37 -> V_16 , V_137 -> V_15 -> V_16 ) ;
if ( V_11 -> V_55 . V_1 == V_7 ) {
F_121 ( L_47 ,
V_37 -> V_16 ) ;
}
}
if ( F_50 ( V_11 -> V_55 . V_1 ) && V_11 -> V_55 . V_207 [ 0 ] ) {
if ( strcmp ( V_11 -> V_55 . V_207 , V_137 -> V_15 -> V_16 ) == 0 ) {
V_11 -> V_112 = V_137 ;
V_11 -> V_113 = true ;
}
}
F_6 ( & V_11 -> V_131 ) ;
switch ( V_11 -> V_55 . V_1 ) {
case V_4 :
F_84 ( V_137 ) ;
F_87 ( V_11 ) ;
break;
case V_7 :
F_84 ( V_137 ) ;
if ( V_11 -> V_23 == 1 ) {
F_135 ( V_137 ) . V_208 = 1 ;
F_136 ( V_11 , 1000 / V_209 ,
V_11 -> V_55 . V_210 ) ;
} else {
F_135 ( V_137 ) . V_208 =
F_135 ( V_137 -> V_30 ) . V_208 + 1 ;
}
F_137 ( V_137 ) ;
break;
case V_8 :
case V_9 :
F_138 ( V_137 ) ;
F_84 ( V_137 ) ;
F_87 ( V_11 ) ;
break;
default:
F_3 ( L_48 ) ;
F_138 ( V_137 ) ;
if ( ! V_11 -> V_91 )
V_11 -> V_91 = V_137 ;
break;
}
F_8 ( & V_11 -> V_131 ) ;
F_37 ( V_11 ) ;
#ifdef F_139
V_34 -> V_146 = F_101 ( V_11 ) ;
if ( V_34 -> V_146 ) {
if ( F_90 ( V_137 ) ) {
F_66 ( & V_11 -> V_20 ) ;
F_80 ( L_49
L_50 ,
V_37 -> V_16 ) ;
V_21 = - V_180 ;
goto V_203;
}
}
#endif
F_66 ( & V_11 -> V_20 ) ;
V_21 = F_140 ( V_37 , V_34 ) ;
if ( V_21 )
goto V_203;
V_21 = F_141 ( V_34 , F_110 ,
V_137 ) ;
if ( V_21 ) {
F_3 ( L_51 , V_21 ) ;
goto V_211;
}
F_80 ( L_52 ,
V_37 -> V_16 , V_34 -> V_16 ,
F_142 ( V_137 ) ? L_53 : L_54 ,
V_137 -> V_56 != V_206 ? L_55 : L_56 ) ;
return 0 ;
V_211:
F_143 ( V_37 , V_34 ) ;
V_203:
F_144 ( V_34 ) ;
V_201:
F_130 ( V_34 , NULL ) ;
V_200:
if ( ! V_11 -> V_55 . V_129 ) {
memcpy ( V_92 . V_197 , V_137 -> V_196 , V_104 ) ;
V_92 . V_198 = V_34 -> type ;
F_129 ( V_34 , & V_92 ) ;
}
V_199:
F_128 ( V_34 , V_137 -> V_193 ) ;
V_195:
F_15 ( V_137 ) ;
V_183:
F_105 ( V_11 ) ;
return V_21 ;
}
int F_145 ( struct V_33 * V_37 , struct V_33 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 , * V_212 ;
struct V_177 V_92 ;
T_2 V_213 = V_37 -> V_24 ;
if ( ! ( V_34 -> V_108 & V_179 ) ||
( V_34 -> V_214 != V_37 ) ) {
F_31 ( L_57 ,
V_37 -> V_16 , V_34 -> V_16 ) ;
return - V_187 ;
}
F_10 () ;
F_86 ( V_37 , V_215 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_40 = F_25 ( V_11 , V_34 ) ;
if ( ! V_40 ) {
F_80 ( L_58 ,
V_37 -> V_16 , V_34 -> V_16 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_17 () ;
return - V_187 ;
}
F_146 ( V_34 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_147 () ;
F_6 ( & V_11 -> V_20 ) ;
if ( ! V_11 -> V_55 . V_129 ) {
if ( ! F_148 ( V_37 -> V_148 , V_40 -> V_196 ) &&
V_11 -> V_23 > 1 )
F_121 ( L_59 ,
V_37 -> V_16 , V_34 -> V_16 ,
V_40 -> V_196 ,
V_37 -> V_16 , V_34 -> V_16 ) ;
}
if ( V_11 -> V_55 . V_1 == V_7 ) {
F_149 ( V_40 ) ;
}
F_80 ( L_60 ,
V_37 -> V_16 ,
F_142 ( V_40 ) ? L_61 : L_62 ,
V_34 -> V_16 ) ;
V_212 = V_11 -> V_91 ;
V_11 -> V_216 = NULL ;
F_89 ( V_11 , V_40 ) ;
if ( V_11 -> V_112 == V_40 )
V_11 -> V_112 = NULL ;
if ( V_212 == V_40 )
F_79 ( V_11 , NULL ) ;
if ( F_13 ( V_11 ) ) {
F_8 ( & V_11 -> V_20 ) ;
F_150 ( V_11 , V_40 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_212 == V_40 ) {
F_8 ( & V_11 -> V_20 ) ;
F_64 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_131 ) ;
F_87 ( V_11 ) ;
F_8 ( & V_11 -> V_131 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
if ( V_11 -> V_23 == 0 ) {
F_37 ( V_11 ) ;
memset ( V_37 -> V_148 , 0 , V_37 -> V_147 ) ;
if ( V_11 -> V_42 ) {
F_121 ( L_63 ,
V_37 -> V_16 , V_37 -> V_16 ) ;
F_121 ( L_64 ,
V_37 -> V_16 ) ;
}
}
F_8 ( & V_11 -> V_20 ) ;
F_17 () ;
F_105 ( V_11 ) ;
if ( ! ( V_37 -> V_24 & V_25 ) &&
( V_213 & V_25 ) )
F_80 ( L_65 ,
V_37 -> V_16 , V_34 -> V_16 , V_37 -> V_16 ) ;
F_143 ( V_37 , V_34 ) ;
F_36 ( V_11 , V_34 ) ;
if ( ! F_50 ( V_11 -> V_55 . V_1 ) ) {
if ( V_37 -> V_108 & V_109 )
F_51 ( V_34 , - 1 ) ;
if ( V_37 -> V_108 & V_110 )
F_53 ( V_34 , - 1 ) ;
F_133 ( V_37 ) ;
F_69 ( V_37 , V_34 ) ;
F_134 ( V_37 ) ;
}
F_130 ( V_34 , NULL ) ;
F_93 ( V_40 ) ;
F_144 ( V_34 ) ;
if ( V_11 -> V_55 . V_129 != V_189 ) {
memcpy ( V_92 . V_197 , V_40 -> V_196 , V_104 ) ;
V_92 . V_198 = V_34 -> type ;
F_129 ( V_34 , & V_92 ) ;
}
F_128 ( V_34 , V_40 -> V_193 ) ;
V_34 -> V_141 &= ~ V_202 ;
F_15 ( V_40 ) ;
return 0 ;
}
static int F_151 ( struct V_33 * V_37 ,
struct V_33 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
int V_217 ;
V_217 = F_145 ( V_37 , V_34 ) ;
if ( ( V_217 == 0 ) && ( V_11 -> V_23 == 0 ) ) {
V_37 -> V_141 |= V_142 ;
F_80 ( L_66 ,
V_37 -> V_16 , V_37 -> V_16 ) ;
F_152 ( V_37 ) ;
}
return V_217 ;
}
static int F_153 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 ;
struct V_33 * V_34 ;
struct V_177 V_92 ;
F_6 ( & V_11 -> V_20 ) ;
F_41 ( V_37 ) ;
if ( V_11 -> V_23 == 0 )
goto V_26;
V_11 -> V_216 = NULL ;
V_11 -> V_112 = NULL ;
F_79 ( V_11 , NULL ) ;
while ( ( V_40 = V_11 -> V_120 ) != NULL ) {
if ( V_11 -> V_55 . V_1 == V_7 )
F_149 ( V_40 ) ;
V_34 = V_40 -> V_15 ;
F_89 ( V_11 , V_40 ) ;
F_8 ( & V_11 -> V_20 ) ;
F_146 ( V_34 ) ;
F_147 () ;
if ( F_13 ( V_11 ) ) {
F_150 ( V_11 , V_40 ) ;
}
F_143 ( V_37 , V_34 ) ;
F_36 ( V_11 , V_34 ) ;
if ( ! F_50 ( V_11 -> V_55 . V_1 ) ) {
if ( V_37 -> V_108 & V_109 )
F_51 ( V_34 , - 1 ) ;
if ( V_37 -> V_108 & V_110 )
F_53 ( V_34 , - 1 ) ;
F_133 ( V_37 ) ;
F_69 ( V_37 , V_34 ) ;
F_134 ( V_37 ) ;
}
F_130 ( V_34 , NULL ) ;
F_93 ( V_40 ) ;
F_144 ( V_34 ) ;
if ( ! V_11 -> V_55 . V_129 ) {
memcpy ( V_92 . V_197 , V_40 -> V_196 , V_104 ) ;
V_92 . V_198 = V_34 -> type ;
F_129 ( V_34 , & V_92 ) ;
}
F_15 ( V_40 ) ;
F_6 ( & V_11 -> V_20 ) ;
}
memset ( V_37 -> V_148 , 0 , V_37 -> V_147 ) ;
if ( V_11 -> V_42 ) {
F_121 ( L_63 ,
V_37 -> V_16 , V_37 -> V_16 ) ;
F_121 ( L_64 ,
V_37 -> V_16 ) ;
}
F_80 ( L_67 , V_37 -> V_16 ) ;
V_26:
F_8 ( & V_11 -> V_20 ) ;
F_105 ( V_11 ) ;
return 0 ;
}
static int F_154 ( struct V_33 * V_37 , struct V_33 * V_34 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_107 = NULL ;
struct V_40 * V_106 = NULL ;
int V_21 = 0 ;
if ( ! F_50 ( V_11 -> V_55 . V_1 ) )
return - V_187 ;
if ( ! ( V_34 -> V_108 & V_179 ) || ( V_34 -> V_214 != V_37 ) )
return - V_187 ;
F_64 ( & V_11 -> V_20 ) ;
F_64 ( & V_11 -> V_131 ) ;
V_107 = V_11 -> V_91 ;
F_66 ( & V_11 -> V_131 ) ;
V_106 = F_25 ( V_11 , V_34 ) ;
if ( V_106 && ( V_106 == V_107 ) ) {
F_66 ( & V_11 -> V_20 ) ;
return 0 ;
}
if ( ( V_106 ) &&
( V_107 ) &&
( V_106 -> V_56 == V_57 ) &&
F_76 ( V_106 -> V_15 ) ) {
F_10 () ;
F_6 ( & V_11 -> V_131 ) ;
F_79 ( V_11 , V_106 ) ;
F_8 ( & V_11 -> V_131 ) ;
F_17 () ;
} else
V_21 = - V_187 ;
F_66 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_155 ( struct V_33 * V_37 , struct V_218 * V_219 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
V_219 -> V_220 = V_11 -> V_55 . V_1 ;
V_219 -> V_127 = V_11 -> V_55 . V_127 ;
F_64 ( & V_11 -> V_20 ) ;
V_219 -> V_221 = V_11 -> V_23 ;
F_66 ( & V_11 -> V_20 ) ;
return 0 ;
}
static int F_156 ( struct V_33 * V_37 , struct V_222 * V_219 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 ;
int V_41 , V_21 = - V_22 ;
F_64 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
if ( V_41 == ( int ) V_219 -> V_223 ) {
V_21 = 0 ;
strcpy ( V_219 -> V_224 , V_40 -> V_15 -> V_16 ) ;
V_219 -> V_56 = V_40 -> V_56 ;
V_219 -> V_125 = F_157 ( V_40 ) ;
V_219 -> V_204 = V_40 -> V_204 ;
break;
}
}
F_66 ( & V_11 -> V_20 ) ;
return V_21 ;
}
static int F_158 ( struct V_10 * V_11 )
{
struct V_40 * V_40 ;
int V_41 , V_225 , V_226 = 0 ;
bool V_227 ;
V_227 = ! V_11 -> V_91 ? true : false ;
F_29 (bond, slave, i) {
V_40 -> V_228 = V_229 ;
V_225 = F_44 ( V_11 , V_40 -> V_15 , 0 ) ;
switch ( V_40 -> V_56 ) {
case V_57 :
if ( V_225 )
continue;
V_40 -> V_56 = V_230 ;
V_40 -> V_122 = V_11 -> V_55 . V_231 ;
if ( V_40 -> V_122 ) {
F_80 ( L_68 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_55 . V_1 ==
V_4 ) ?
( F_142 ( V_40 ) ?
L_69 : L_70 ) : L_71 ,
V_40 -> V_15 -> V_16 ,
V_11 -> V_55 . V_231 * V_11 -> V_55 . V_127 ) ;
}
case V_230 :
if ( V_225 ) {
V_40 -> V_56 = V_57 ;
V_40 -> V_126 = V_126 ;
F_80 ( L_72 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_55 . V_231 - V_40 -> V_122 ) *
V_11 -> V_55 . V_127 ,
V_40 -> V_15 -> V_16 ) ;
continue;
}
if ( V_40 -> V_122 <= 0 ) {
V_40 -> V_228 = V_206 ;
V_226 ++ ;
continue;
}
V_40 -> V_122 -- ;
break;
case V_206 :
if ( ! V_225 )
continue;
V_40 -> V_56 = V_121 ;
V_40 -> V_122 = V_11 -> V_55 . V_119 ;
if ( V_40 -> V_122 ) {
F_80 ( L_73 ,
V_11 -> V_15 -> V_16 , V_40 -> V_15 -> V_16 ,
V_227 ? 0 :
V_11 -> V_55 . V_119 *
V_11 -> V_55 . V_127 ) ;
}
case V_121 :
if ( ! V_225 ) {
V_40 -> V_56 = V_206 ;
F_80 ( L_74 ,
V_11 -> V_15 -> V_16 ,
( V_11 -> V_55 . V_119 - V_40 -> V_122 ) *
V_11 -> V_55 . V_127 ,
V_40 -> V_15 -> V_16 ) ;
continue;
}
if ( V_227 )
V_40 -> V_122 = 0 ;
if ( V_40 -> V_122 <= 0 ) {
V_40 -> V_228 = V_57 ;
V_226 ++ ;
V_227 = false ;
continue;
}
V_40 -> V_122 -- ;
break;
}
}
return V_226 ;
}
static void F_159 ( struct V_10 * V_11 )
{
struct V_40 * V_40 ;
int V_41 ;
F_29 (bond, slave, i) {
switch ( V_40 -> V_228 ) {
case V_229 :
continue;
case V_57 :
V_40 -> V_56 = V_57 ;
V_40 -> V_126 = V_126 ;
if ( V_11 -> V_55 . V_1 == V_7 ) {
F_160 ( V_40 ) ;
} else if ( V_11 -> V_55 . V_1 != V_4 ) {
F_138 ( V_40 ) ;
} else if ( V_40 != V_11 -> V_112 ) {
F_160 ( V_40 ) ;
}
F_42 ( V_40 ) ;
F_80 ( L_75 ,
V_11 -> V_15 -> V_16 , V_40 -> V_15 -> V_16 ,
V_40 -> V_63 , V_40 -> V_65 ? L_76 : L_77 ) ;
if ( V_11 -> V_55 . V_1 == V_7 )
F_81 ( V_40 , V_57 ) ;
if ( F_13 ( V_11 ) )
F_82 ( V_11 , V_40 ,
V_57 ) ;
if ( ! V_11 -> V_91 ||
( V_40 == V_11 -> V_112 ) )
goto V_232;
continue;
case V_206 :
if ( V_40 -> V_204 < V_233 )
V_40 -> V_204 ++ ;
V_40 -> V_56 = V_206 ;
if ( V_11 -> V_55 . V_1 == V_4 ||
V_11 -> V_55 . V_1 == V_7 )
F_84 ( V_40 ) ;
F_80 ( L_78 ,
V_11 -> V_15 -> V_16 , V_40 -> V_15 -> V_16 ) ;
if ( V_11 -> V_55 . V_1 == V_7 )
F_81 ( V_40 ,
V_206 ) ;
if ( F_13 ( V_11 ) )
F_82 ( V_11 , V_40 ,
V_206 ) ;
if ( V_40 == V_11 -> V_91 )
goto V_232;
continue;
default:
F_31 ( L_79 ,
V_11 -> V_15 -> V_16 , V_40 -> V_228 ,
V_40 -> V_15 -> V_16 ) ;
V_40 -> V_228 = V_229 ;
continue;
}
V_232:
F_161 () ;
F_10 () ;
F_6 ( & V_11 -> V_131 ) ;
F_87 ( V_11 ) ;
F_8 ( & V_11 -> V_131 ) ;
F_17 () ;
}
F_37 ( V_11 ) ;
}
void F_162 ( struct V_99 * V_100 )
{
struct V_10 * V_11 = F_68 ( V_100 , struct V_10 ,
V_234 . V_100 ) ;
bool V_128 = false ;
F_64 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_235 )
goto V_26;
if ( V_11 -> V_23 == 0 )
goto V_236;
V_128 = F_77 ( V_11 ) ;
if ( F_158 ( V_11 ) ) {
F_66 ( & V_11 -> V_20 ) ;
F_163 () ;
F_64 ( & V_11 -> V_20 ) ;
F_159 ( V_11 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_164 () ;
F_64 ( & V_11 -> V_20 ) ;
}
V_236:
if ( V_11 -> V_55 . V_127 )
F_65 ( V_11 -> V_96 , & V_11 -> V_234 ,
F_165 ( V_11 -> V_55 . V_127 ) ) ;
V_26:
F_66 ( & V_11 -> V_20 ) ;
if ( V_128 ) {
F_163 () ;
F_86 ( V_11 -> V_15 , V_133 ) ;
F_164 () ;
}
}
static T_5 F_166 ( struct V_33 * V_15 )
{
struct V_93 * V_237 ;
struct V_238 * V_239 ;
T_5 V_92 = 0 ;
if ( ! V_15 )
return 0 ;
F_59 () ;
V_237 = F_60 ( V_15 ) ;
if ( ! V_237 )
goto V_26;
V_239 = V_237 -> V_240 ;
if ( ! V_239 )
goto V_26;
V_92 = V_239 -> V_241 ;
V_26:
F_62 () ;
return V_92 ;
}
static int F_167 ( struct V_10 * V_11 , T_5 V_242 )
{
struct V_13 * V_14 ;
if ( V_242 == V_11 -> V_243 )
return 1 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( V_242 == V_14 -> V_244 )
return 1 ;
}
return 0 ;
}
static void F_168 ( struct V_33 * V_34 , int V_245 , T_5 V_246 , T_5 V_247 , unsigned short V_12 )
{
struct V_31 * V_32 ;
F_3 ( L_80 , V_245 ,
V_34 -> V_16 , V_246 , V_247 , V_12 ) ;
V_32 = F_169 ( V_245 , V_248 , V_246 , V_34 , V_247 ,
NULL , V_34 -> V_148 , NULL ) ;
if ( ! V_32 ) {
F_31 ( L_81 ) ;
return;
}
if ( V_12 ) {
V_32 = F_170 ( V_32 , V_12 ) ;
if ( ! V_32 ) {
F_31 ( L_82 ) ;
return;
}
}
F_171 ( V_32 ) ;
}
static void F_172 ( struct V_10 * V_11 , struct V_40 * V_40 )
{
int V_41 , V_12 ;
T_5 * V_249 = V_11 -> V_55 . V_250 ;
struct V_13 * V_14 ;
struct V_33 * V_51 ;
struct V_251 * V_252 ;
for ( V_41 = 0 ; ( V_41 < V_253 ) ; V_41 ++ ) {
if ( ! V_249 [ V_41 ] )
break;
F_3 ( L_83 , V_249 [ V_41 ] ) ;
if ( ! V_11 -> V_42 ) {
F_3 ( L_84 ) ;
F_168 ( V_40 -> V_15 , V_254 , V_249 [ V_41 ] ,
V_11 -> V_243 , 0 ) ;
continue;
}
V_252 = F_173 ( F_174 ( V_11 -> V_15 ) , V_249 [ V_41 ] , 0 ,
V_255 , 0 ) ;
if ( F_175 ( V_252 ) ) {
if ( F_176 () ) {
F_121 ( L_85 ,
V_11 -> V_15 -> V_16 , & V_249 [ V_41 ] ) ;
}
continue;
}
if ( V_252 -> V_256 . V_15 == V_11 -> V_15 ) {
F_177 ( V_252 ) ;
F_3 ( L_86 ) ;
F_168 ( V_40 -> V_15 , V_254 , V_249 [ V_41 ] ,
V_11 -> V_243 , 0 ) ;
continue;
}
V_12 = 0 ;
F_11 (vlan, &bond->vlan_list, vlan_list) {
V_51 = F_33 ( V_11 -> V_42 , V_14 -> V_12 ) ;
if ( V_51 == V_252 -> V_256 . V_15 ) {
V_12 = V_14 -> V_12 ;
F_3 ( L_87 ,
V_51 -> V_16 , V_12 ) ;
break;
}
}
if ( V_12 ) {
F_177 ( V_252 ) ;
F_168 ( V_40 -> V_15 , V_254 , V_249 [ V_41 ] ,
V_14 -> V_244 , V_12 ) ;
continue;
}
if ( F_176 () ) {
F_121 ( L_88 ,
V_11 -> V_15 -> V_16 , & V_249 [ V_41 ] ,
V_252 -> V_256 . V_15 ? V_252 -> V_256 . V_15 -> V_16 : L_17 ) ;
}
F_177 ( V_252 ) ;
}
}
static void F_178 ( struct V_10 * V_11 , struct V_40 * V_40 , T_5 V_257 , T_5 V_258 )
{
int V_41 ;
T_5 * V_249 = V_11 -> V_55 . V_250 ;
for ( V_41 = 0 ; ( V_41 < V_253 ) && V_249 [ V_41 ] ; V_41 ++ ) {
F_3 ( L_89 ,
& V_257 , & V_258 , V_41 , & V_249 [ V_41 ] ,
F_167 ( V_11 , V_258 ) ) ;
if ( V_257 == V_249 [ V_41 ] ) {
if ( F_167 ( V_11 , V_258 ) )
V_40 -> V_205 = V_126 ;
return;
}
}
}
static void F_179 ( struct V_31 * V_32 , struct V_10 * V_11 ,
struct V_40 * V_40 )
{
struct V_259 * V_260 ;
unsigned char * V_261 ;
T_5 V_257 , V_258 ;
if ( V_32 -> V_262 != F_180 ( V_248 ) )
return;
F_64 ( & V_11 -> V_20 ) ;
F_3 ( L_90 ,
V_11 -> V_15 -> V_16 , V_32 -> V_15 -> V_16 ) ;
if ( ! F_181 ( V_32 , F_182 ( V_11 -> V_15 ) ) )
goto V_263;
V_260 = F_183 ( V_32 ) ;
if ( V_260 -> V_264 != V_11 -> V_15 -> V_147 ||
V_32 -> V_161 == V_265 ||
V_32 -> V_161 == V_266 ||
V_260 -> V_267 != F_184 ( V_185 ) ||
V_260 -> V_268 != F_184 ( V_269 ) ||
V_260 -> V_270 != 4 )
goto V_263;
V_261 = ( unsigned char * ) ( V_260 + 1 ) ;
V_261 += V_11 -> V_15 -> V_147 ;
memcpy ( & V_257 , V_261 , 4 ) ;
V_261 += 4 + V_11 -> V_15 -> V_147 ;
memcpy ( & V_258 , V_261 , 4 ) ;
F_3 ( L_91 ,
V_11 -> V_15 -> V_16 , V_40 -> V_15 -> V_16 , F_157 ( V_40 ) ,
V_11 -> V_55 . V_271 , F_185 ( V_11 , V_40 ) ,
& V_257 , & V_258 ) ;
if ( F_142 ( V_40 ) )
F_178 ( V_11 , V_40 , V_257 , V_258 ) ;
else
F_178 ( V_11 , V_40 , V_258 , V_257 ) ;
V_263:
F_66 ( & V_11 -> V_20 ) ;
}
void F_186 ( struct V_99 * V_100 )
{
struct V_10 * V_11 = F_68 ( V_100 , struct V_10 ,
V_272 . V_100 ) ;
struct V_40 * V_40 , * V_212 ;
int V_232 = 0 ;
int V_273 ;
int V_41 ;
F_64 ( & V_11 -> V_20 ) ;
V_273 = F_165 ( V_11 -> V_55 . V_167 ) ;
if ( V_11 -> V_235 )
goto V_26;
if ( V_11 -> V_23 == 0 )
goto V_236;
F_64 ( & V_11 -> V_131 ) ;
V_212 = V_11 -> V_91 ;
F_66 ( & V_11 -> V_131 ) ;
F_29 (bond, slave, i) {
unsigned long V_274 = F_187 ( V_40 -> V_15 ) ;
if ( V_40 -> V_56 != V_57 ) {
if ( F_188 ( V_126 ,
V_274 - V_273 ,
V_274 + V_273 ) &&
F_188 ( V_126 ,
V_40 -> V_15 -> V_168 - V_273 ,
V_40 -> V_15 -> V_168 + V_273 ) ) {
V_40 -> V_56 = V_57 ;
F_138 ( V_40 ) ;
if ( ! V_212 ) {
F_80 ( L_92 ,
V_11 -> V_15 -> V_16 ,
V_40 -> V_15 -> V_16 ) ;
V_232 = 1 ;
} else {
F_80 ( L_93 ,
V_11 -> V_15 -> V_16 ,
V_40 -> V_15 -> V_16 ) ;
}
}
} else {
if ( ! F_188 ( V_126 ,
V_274 - V_273 ,
V_274 + 2 * V_273 ) ||
! F_188 ( V_126 ,
V_40 -> V_15 -> V_168 - V_273 ,
V_40 -> V_15 -> V_168 + 2 * V_273 ) ) {
V_40 -> V_56 = V_206 ;
F_160 ( V_40 ) ;
if ( V_40 -> V_204 < V_233 )
V_40 -> V_204 ++ ;
F_80 ( L_94 ,
V_11 -> V_15 -> V_16 ,
V_40 -> V_15 -> V_16 ) ;
if ( V_40 == V_212 )
V_232 = 1 ;
}
}
if ( F_76 ( V_40 -> V_15 ) )
F_172 ( V_11 , V_40 ) ;
}
if ( V_232 ) {
F_10 () ;
F_6 ( & V_11 -> V_131 ) ;
F_87 ( V_11 ) ;
F_8 ( & V_11 -> V_131 ) ;
F_17 () ;
}
V_236:
if ( V_11 -> V_55 . V_167 )
F_65 ( V_11 -> V_96 , & V_11 -> V_272 , V_273 ) ;
V_26:
F_66 ( & V_11 -> V_20 ) ;
}
static int F_189 ( struct V_10 * V_11 , int V_273 )
{
struct V_40 * V_40 ;
int V_41 , V_226 = 0 ;
unsigned long V_274 ;
F_29 (bond, slave, i) {
V_40 -> V_228 = V_229 ;
if ( V_40 -> V_56 != V_57 ) {
if ( F_188 ( V_126 ,
F_190 ( V_11 , V_40 ) - V_273 ,
F_190 ( V_11 , V_40 ) + V_273 ) ) {
V_40 -> V_228 = V_57 ;
V_226 ++ ;
}
continue;
}
if ( F_188 ( V_126 ,
V_40 -> V_126 - V_273 ,
V_40 -> V_126 + 2 * V_273 ) )
continue;
if ( ! F_142 ( V_40 ) &&
! V_11 -> V_216 &&
! F_188 ( V_126 ,
F_190 ( V_11 , V_40 ) - V_273 ,
F_190 ( V_11 , V_40 ) + 3 * V_273 ) ) {
V_40 -> V_228 = V_206 ;
V_226 ++ ;
}
V_274 = F_187 ( V_40 -> V_15 ) ;
if ( F_142 ( V_40 ) &&
( ! F_188 ( V_126 ,
V_274 - V_273 ,
V_274 + 2 * V_273 ) ||
! F_188 ( V_126 ,
F_190 ( V_11 , V_40 ) - V_273 ,
F_190 ( V_11 , V_40 ) + 2 * V_273 ) ) ) {
V_40 -> V_228 = V_206 ;
V_226 ++ ;
}
}
return V_226 ;
}
static void F_191 ( struct V_10 * V_11 , int V_273 )
{
struct V_40 * V_40 ;
int V_41 ;
unsigned long V_274 ;
F_29 (bond, slave, i) {
switch ( V_40 -> V_228 ) {
case V_229 :
continue;
case V_57 :
V_274 = F_187 ( V_40 -> V_15 ) ;
if ( ( ! V_11 -> V_91 &&
F_188 ( V_126 ,
V_274 - V_273 ,
V_274 + V_273 ) ) ||
V_11 -> V_91 != V_40 ) {
V_40 -> V_56 = V_57 ;
V_11 -> V_216 = NULL ;
F_80 ( L_95 ,
V_11 -> V_15 -> V_16 , V_40 -> V_15 -> V_16 ) ;
if ( ! V_11 -> V_91 ||
( V_40 == V_11 -> V_112 ) )
goto V_232;
}
continue;
case V_206 :
if ( V_40 -> V_204 < V_233 )
V_40 -> V_204 ++ ;
V_40 -> V_56 = V_206 ;
F_84 ( V_40 ) ;
F_80 ( L_78 ,
V_11 -> V_15 -> V_16 , V_40 -> V_15 -> V_16 ) ;
if ( V_40 == V_11 -> V_91 ) {
V_11 -> V_216 = NULL ;
goto V_232;
}
continue;
default:
F_31 ( L_96 ,
V_11 -> V_15 -> V_16 , V_40 -> V_228 ,
V_40 -> V_15 -> V_16 ) ;
continue;
}
V_232:
F_161 () ;
F_10 () ;
F_6 ( & V_11 -> V_131 ) ;
F_87 ( V_11 ) ;
F_8 ( & V_11 -> V_131 ) ;
F_17 () ;
}
F_37 ( V_11 ) ;
}
static void F_192 ( struct V_10 * V_11 )
{
struct V_40 * V_40 ;
int V_41 ;
F_64 ( & V_11 -> V_131 ) ;
if ( V_11 -> V_216 && V_11 -> V_91 )
F_80 ( L_97 ,
V_11 -> V_216 -> V_15 -> V_16 ,
V_11 -> V_91 -> V_15 -> V_16 ) ;
if ( V_11 -> V_91 ) {
F_172 ( V_11 , V_11 -> V_91 ) ;
F_66 ( & V_11 -> V_131 ) ;
return;
}
F_66 ( & V_11 -> V_131 ) ;
if ( ! V_11 -> V_216 ) {
V_11 -> V_216 = V_11 -> V_120 ;
if ( ! V_11 -> V_216 )
return;
}
F_84 ( V_11 -> V_216 ) ;
F_75 (bond, slave, i, bond->current_arp_slave->next) {
if ( F_76 ( V_40 -> V_15 ) ) {
V_40 -> V_56 = V_121 ;
F_85 ( V_40 ) ;
F_172 ( V_11 , V_40 ) ;
V_40 -> V_126 = V_126 ;
V_11 -> V_216 = V_40 ;
break;
}
if ( V_40 -> V_56 == V_57 ) {
V_40 -> V_56 = V_206 ;
if ( V_40 -> V_204 < V_233 )
V_40 -> V_204 ++ ;
F_84 ( V_40 ) ;
F_80 ( L_98 ,
V_11 -> V_15 -> V_16 , V_40 -> V_15 -> V_16 ) ;
}
}
}
void F_193 ( struct V_99 * V_100 )
{
struct V_10 * V_11 = F_68 ( V_100 , struct V_10 ,
V_272 . V_100 ) ;
bool V_128 = false ;
int V_273 ;
F_64 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_235 )
goto V_26;
V_273 = F_165 ( V_11 -> V_55 . V_167 ) ;
if ( V_11 -> V_23 == 0 )
goto V_236;
V_128 = F_77 ( V_11 ) ;
if ( F_189 ( V_11 , V_273 ) ) {
F_66 ( & V_11 -> V_20 ) ;
F_163 () ;
F_64 ( & V_11 -> V_20 ) ;
F_191 ( V_11 , V_273 ) ;
F_66 ( & V_11 -> V_20 ) ;
F_164 () ;
F_64 ( & V_11 -> V_20 ) ;
}
F_192 ( V_11 ) ;
V_236:
if ( V_11 -> V_55 . V_167 )
F_65 ( V_11 -> V_96 , & V_11 -> V_272 , V_273 ) ;
V_26:
F_66 ( & V_11 -> V_20 ) ;
if ( V_128 ) {
F_163 () ;
F_86 ( V_11 -> V_15 , V_133 ) ;
F_164 () ;
}
}
static int F_194 ( struct V_10 * V_11 )
{
F_195 ( V_11 ) ;
F_196 ( V_11 ) ;
F_197 ( V_11 ) ;
return V_275 ;
}
static int F_198 ( unsigned long V_276 ,
struct V_33 * V_37 )
{
struct V_10 * V_277 = F_28 ( V_37 ) ;
switch ( V_276 ) {
case V_278 :
return F_194 ( V_277 ) ;
default:
break;
}
return V_275 ;
}
static int F_199 ( unsigned long V_276 ,
struct V_33 * V_34 )
{
struct V_33 * V_37 = V_34 -> V_214 ;
struct V_10 * V_11 = F_28 ( V_37 ) ;
switch ( V_276 ) {
case V_279 :
if ( V_37 ) {
if ( V_11 -> V_160 )
F_151 ( V_37 , V_34 ) ;
else
F_145 ( V_37 , V_34 ) ;
}
break;
case V_280 :
if ( V_11 -> V_55 . V_1 == V_7 || F_13 ( V_11 ) ) {
struct V_40 * V_40 ;
V_40 = F_25 ( V_11 , V_34 ) ;
if ( V_40 ) {
T_2 V_281 = V_40 -> V_63 ;
T_3 V_282 = V_40 -> V_65 ;
F_42 ( V_40 ) ;
if ( F_13 ( V_11 ) )
break;
if ( V_281 != V_40 -> V_63 )
F_200 ( V_40 ) ;
if ( V_282 != V_40 -> V_65 )
F_201 ( V_40 ) ;
}
}
break;
case V_283 :
break;
case V_284 :
break;
case V_278 :
break;
case V_285 :
F_105 ( V_11 ) ;
break;
default:
break;
}
return V_275 ;
}
static int F_202 ( struct V_286 * V_287 ,
unsigned long V_276 , void * V_288 )
{
struct V_33 * V_289 = (struct V_33 * ) V_288 ;
F_3 ( L_99 ,
V_289 ? V_289 -> V_16 : L_10 ,
V_276 ) ;
if ( ! ( V_289 -> V_141 & V_202 ) )
return V_275 ;
if ( V_289 -> V_108 & V_290 ) {
F_3 ( L_100 ) ;
return F_198 ( V_276 , V_289 ) ;
}
if ( V_289 -> V_108 & V_179 ) {
F_3 ( L_101 ) ;
return F_199 ( V_276 , V_289 ) ;
}
return V_275 ;
}
static int F_203 ( struct V_286 * V_287 , unsigned long V_276 , void * V_288 )
{
struct V_238 * V_239 = V_288 ;
struct V_33 * V_51 , * V_289 = V_239 -> V_291 -> V_15 ;
struct V_292 * V_293 = F_204 ( F_174 ( V_289 ) , V_294 ) ;
struct V_10 * V_11 ;
struct V_13 * V_14 ;
F_11 (bond, &bn->dev_list, bond_list) {
if ( V_11 -> V_15 == V_289 ) {
switch ( V_276 ) {
case V_295 :
V_11 -> V_243 = V_239 -> V_241 ;
return V_296 ;
case V_283 :
V_11 -> V_243 = F_166 ( V_11 -> V_15 ) ;
return V_296 ;
default:
return V_275 ;
}
}
F_11 (vlan, &bond->vlan_list, vlan_list) {
if ( ! V_11 -> V_42 )
continue;
V_51 = F_33 ( V_11 -> V_42 , V_14 -> V_12 ) ;
if ( V_51 == V_289 ) {
switch ( V_276 ) {
case V_295 :
V_14 -> V_244 = V_239 -> V_241 ;
return V_296 ;
case V_283 :
V_14 -> V_244 =
F_166 ( V_51 ) ;
return V_296 ;
default:
return V_275 ;
}
}
}
}
return V_275 ;
}
static int F_205 ( struct V_31 * V_32 , int V_297 )
{
struct V_298 * V_174 = (struct V_298 * ) V_32 -> V_174 ;
struct V_299 * V_300 = F_206 ( V_32 ) ;
if ( V_32 -> V_262 == F_184 ( V_269 ) ) {
return ( ( F_207 ( V_300 -> V_301 ^ V_300 -> V_302 ) & 0xffff ) ^
( V_174 -> V_175 [ 5 ] ^ V_174 -> V_303 [ 5 ] ) ) % V_297 ;
}
return ( V_174 -> V_175 [ 5 ] ^ V_174 -> V_303 [ 5 ] ) % V_297 ;
}
static int F_208 ( struct V_31 * V_32 , int V_297 )
{
struct V_298 * V_174 = (struct V_298 * ) V_32 -> V_174 ;
struct V_299 * V_300 = F_206 ( V_32 ) ;
T_6 * V_304 = ( T_6 * ) ( ( T_2 * ) V_300 + V_300 -> V_305 ) ;
int V_306 = 0 ;
if ( V_32 -> V_262 == F_184 ( V_269 ) ) {
if ( ! ( V_300 -> V_307 & F_184 ( V_308 | V_309 ) ) &&
( V_300 -> V_262 == V_310 ||
V_300 -> V_262 == V_311 ) ) {
V_306 = F_209 ( ( * V_304 ^ * ( V_304 + 1 ) ) ) ;
}
return ( V_306 ^
( ( F_207 ( V_300 -> V_301 ^ V_300 -> V_302 ) ) & 0xffff ) ) % V_297 ;
}
return ( V_174 -> V_175 [ 5 ] ^ V_174 -> V_303 [ 5 ] ) % V_297 ;
}
static int F_210 ( struct V_31 * V_32 , int V_297 )
{
struct V_298 * V_174 = (struct V_298 * ) V_32 -> V_174 ;
return ( V_174 -> V_175 [ 5 ] ^ V_174 -> V_303 [ 5 ] ) % V_297 ;
}
static int F_211 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
V_11 -> V_235 = 0 ;
F_212 ( & V_11 -> V_97 , F_67 ) ;
if ( F_13 ( V_11 ) ) {
if ( F_213 ( V_11 , ( V_11 -> V_55 . V_1 == V_9 ) ) ) {
return - V_18 ;
}
F_212 ( & V_11 -> V_312 , V_313 ) ;
F_65 ( V_11 -> V_96 , & V_11 -> V_312 , 0 ) ;
}
if ( V_11 -> V_55 . V_127 ) {
F_212 ( & V_11 -> V_234 , F_162 ) ;
F_65 ( V_11 -> V_96 , & V_11 -> V_234 , 0 ) ;
}
if ( V_11 -> V_55 . V_167 ) {
if ( V_11 -> V_55 . V_1 == V_4 )
F_212 ( & V_11 -> V_272 ,
F_193 ) ;
else
F_212 ( & V_11 -> V_272 ,
F_186 ) ;
F_65 ( V_11 -> V_96 , & V_11 -> V_272 , 0 ) ;
if ( V_11 -> V_55 . V_271 )
V_11 -> V_169 = F_179 ;
}
if ( V_11 -> V_55 . V_1 == V_7 ) {
F_212 ( & V_11 -> V_314 , V_315 ) ;
F_65 ( V_11 -> V_96 , & V_11 -> V_314 , 0 ) ;
V_11 -> V_169 = V_316 ;
F_214 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_215 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_123 = 0 ;
V_11 -> V_235 = 1 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_55 . V_127 ) {
F_216 ( & V_11 -> V_234 ) ;
}
if ( V_11 -> V_55 . V_167 ) {
F_216 ( & V_11 -> V_272 ) ;
}
switch ( V_11 -> V_55 . V_1 ) {
case V_7 :
F_216 ( & V_11 -> V_314 ) ;
break;
case V_8 :
case V_9 :
F_216 ( & V_11 -> V_312 ) ;
break;
default:
break;
}
if ( F_217 ( & V_11 -> V_97 ) )
F_216 ( & V_11 -> V_97 ) ;
if ( F_13 ( V_11 ) ) {
F_218 ( V_11 ) ;
}
V_11 -> V_169 = NULL ;
return 0 ;
}
static struct V_317 * F_219 ( struct V_33 * V_37 ,
struct V_317 * V_318 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_317 V_319 ;
struct V_40 * V_40 ;
int V_41 ;
memset ( V_318 , 0 , sizeof( * V_318 ) ) ;
F_220 ( & V_11 -> V_20 ) ;
F_29 (bond, slave, i) {
const struct V_317 * V_320 =
F_221 ( V_40 -> V_15 , & V_319 ) ;
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
F_222 ( & V_11 -> V_20 ) ;
return V_318 ;
}
static int F_223 ( struct V_33 * V_37 , struct V_74 * V_75 , int V_60 )
{
struct V_33 * V_34 = NULL ;
struct V_218 V_342 ;
struct V_218 T_7 * V_343 = NULL ;
struct V_222 V_344 ;
struct V_222 T_7 * V_345 = NULL ;
struct V_76 * V_77 = NULL ;
int V_21 = 0 ;
F_3 ( L_102 , V_37 -> V_16 , V_60 ) ;
switch ( V_60 ) {
case V_84 :
V_77 = F_47 ( V_75 ) ;
if ( ! V_77 )
return - V_187 ;
V_77 -> V_346 = 0 ;
case V_87 :
V_77 = F_47 ( V_75 ) ;
if ( ! V_77 )
return - V_187 ;
if ( V_77 -> V_85 == 1 ) {
struct V_10 * V_11 = F_28 ( V_37 ) ;
V_77 -> V_88 = 0 ;
F_64 ( & V_11 -> V_20 ) ;
F_64 ( & V_11 -> V_131 ) ;
if ( F_39 ( V_11 -> V_15 ) )
V_77 -> V_88 = V_79 ;
F_66 ( & V_11 -> V_131 ) ;
F_66 ( & V_11 -> V_20 ) ;
}
return 0 ;
case V_347 :
case V_348 :
V_343 = (struct V_218 T_7 * ) V_75 -> V_349 ;
if ( F_224 ( & V_342 , V_343 , sizeof( V_218 ) ) )
return - V_350 ;
V_21 = F_155 ( V_37 , & V_342 ) ;
if ( V_21 == 0 &&
F_225 ( V_343 , & V_342 , sizeof( V_218 ) ) )
return - V_350 ;
return V_21 ;
case V_351 :
case V_352 :
V_345 = (struct V_222 T_7 * ) V_75 -> V_349 ;
if ( F_224 ( & V_344 , V_345 , sizeof( V_222 ) ) )
return - V_350 ;
V_21 = F_156 ( V_37 , & V_344 ) ;
if ( V_21 == 0 &&
F_225 ( V_345 , & V_344 , sizeof( V_222 ) ) )
return - V_350 ;
return V_21 ;
default:
break;
}
if ( ! F_226 ( V_353 ) )
return - V_181 ;
V_34 = F_227 ( F_174 ( V_37 ) , V_75 -> V_354 ) ;
F_3 ( L_103 , V_34 ) ;
if ( ! V_34 )
V_21 = - V_22 ;
else {
F_3 ( L_104 , V_34 -> V_16 ) ;
switch ( V_60 ) {
case V_355 :
case V_356 :
V_21 = F_120 ( V_37 , V_34 ) ;
break;
case V_357 :
case V_358 :
V_21 = F_145 ( V_37 , V_34 ) ;
break;
case V_359 :
case V_360 :
V_21 = F_102 ( V_37 , V_34 ) ;
break;
case V_361 :
case V_362 :
V_21 = F_154 ( V_37 , V_34 ) ;
break;
default:
V_21 = - V_190 ;
}
F_228 ( V_34 ) ;
}
return V_21 ;
}
static bool F_229 ( unsigned char * V_92 ,
struct V_363 * V_364 ,
int V_365 )
{
struct V_101 * V_102 ;
F_230 (ha, list)
if ( ! memcmp ( V_102 -> V_92 , V_92 , V_365 ) )
return true ;
return false ;
}
static void F_231 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_101 * V_102 ;
bool V_366 ;
if ( ( V_37 -> V_108 & V_109 ) && ! ( V_11 -> V_108 & V_109 ) )
F_49 ( V_11 , 1 ) ;
if ( ! ( V_37 -> V_108 & V_109 ) && ( V_11 -> V_108 & V_109 ) )
F_49 ( V_11 , - 1 ) ;
if ( ( V_37 -> V_108 & V_110 ) && ! ( V_11 -> V_108 & V_110 ) )
F_52 ( V_11 , 1 ) ;
if ( ! ( V_37 -> V_108 & V_110 ) && ( V_11 -> V_108 & V_110 ) )
F_52 ( V_11 , - 1 ) ;
F_64 ( & V_11 -> V_20 ) ;
V_11 -> V_108 = V_37 -> V_108 ;
F_70 (ha, bond_dev) {
V_366 = F_229 ( V_102 -> V_92 , & V_11 -> V_367 ,
V_37 -> V_147 ) ;
if ( ! V_366 )
F_54 ( V_11 , V_102 -> V_92 ) ;
}
F_230 (ha, &bond->mc_list) {
V_366 = F_229 ( V_102 -> V_92 , & V_37 -> V_368 ,
V_37 -> V_147 ) ;
if ( ! V_366 )
F_56 ( V_11 , V_102 -> V_92 ) ;
}
F_232 ( & V_11 -> V_367 ) ;
F_233 ( & V_11 -> V_367 , & V_37 -> V_368 ,
V_37 -> V_147 , V_369 ) ;
F_66 ( & V_11 -> V_20 ) ;
}
static int F_234 ( struct V_33 * V_15 , struct V_370 * V_371 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
struct V_40 * V_40 = V_11 -> V_120 ;
if ( V_40 ) {
const struct V_43 * V_44
= V_40 -> V_15 -> V_45 ;
if ( V_44 -> V_372 )
return V_44 -> V_372 ( V_40 -> V_15 , V_371 ) ;
}
return 0 ;
}
static int F_235 ( struct V_33 * V_37 , int V_373 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 , * V_374 ;
int V_21 = 0 ;
int V_41 ;
F_3 ( L_105 , V_11 ,
( V_37 ? V_37 -> V_16 : L_10 ) , V_373 ) ;
F_29 (bond, slave, i) {
F_3 ( L_106 ,
V_40 ,
V_40 -> V_30 ,
V_40 -> V_15 -> V_45 -> V_375 ) ;
V_21 = F_128 ( V_40 -> V_15 , V_373 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_40 -> V_15 -> V_16 ) ;
goto V_376;
}
}
V_37 -> V_194 = V_373 ;
return 0 ;
V_376:
V_374 = V_40 ;
F_236 (bond, slave, i, bond->first_slave, stop_at) {
int V_377 ;
V_377 = F_128 ( V_40 -> V_15 , V_37 -> V_194 ) ;
if ( V_377 ) {
F_3 ( L_108 ,
V_377 , V_40 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_237 ( struct V_33 * V_37 , void * V_92 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_177 * V_378 = V_92 , V_379 ;
struct V_40 * V_40 , * V_374 ;
int V_21 = 0 ;
int V_41 ;
if ( V_11 -> V_55 . V_1 == V_9 )
return F_238 ( V_37 , V_92 ) ;
F_3 ( L_109 ,
V_11 , V_37 ? V_37 -> V_16 : L_10 ) ;
if ( V_11 -> V_55 . V_129 == V_189 )
return 0 ;
if ( ! F_239 ( V_378 -> V_197 ) )
return - V_380 ;
F_29 (bond, slave, i) {
const struct V_43 * V_44 = V_40 -> V_15 -> V_45 ;
F_3 ( L_110 , V_40 , V_40 -> V_15 -> V_16 ) ;
if ( V_44 -> V_188 == NULL ) {
V_21 = - V_190 ;
F_3 ( L_111 , V_40 -> V_15 -> V_16 ) ;
goto V_376;
}
V_21 = F_129 ( V_40 -> V_15 , V_92 ) ;
if ( V_21 ) {
F_3 ( L_107 , V_21 , V_40 -> V_15 -> V_16 ) ;
goto V_376;
}
}
memcpy ( V_37 -> V_148 , V_378 -> V_197 , V_37 -> V_147 ) ;
return 0 ;
V_376:
memcpy ( V_379 . V_197 , V_37 -> V_148 , V_37 -> V_147 ) ;
V_379 . V_198 = V_37 -> type ;
V_374 = V_40 ;
F_236 (bond, slave, i, bond->first_slave, stop_at) {
int V_377 ;
V_377 = F_129 ( V_40 -> V_15 , & V_379 ) ;
if ( V_377 ) {
F_3 ( L_108 ,
V_377 , V_40 -> V_15 -> V_16 ) ;
}
}
return V_21 ;
}
static int F_240 ( struct V_31 * V_32 , struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 , * V_381 ;
int V_41 , V_382 , V_21 = 1 ;
struct V_299 * V_300 = F_206 ( V_32 ) ;
if ( ( V_300 -> V_262 == V_383 ) &&
( V_32 -> V_262 == F_184 ( V_269 ) ) ) {
F_64 ( & V_11 -> V_131 ) ;
V_40 = V_11 -> V_91 ;
F_66 ( & V_11 -> V_131 ) ;
if ( ! V_40 )
goto V_26;
} else {
V_382 = V_11 -> V_384 ++ % V_11 -> V_23 ;
F_29 (bond, slave, i) {
V_382 -- ;
if ( V_382 < 0 )
break;
}
}
V_381 = V_40 ;
F_75 (bond, slave, i, start_at) {
if ( F_76 ( V_40 -> V_15 ) &&
( V_40 -> V_56 == V_57 ) &&
F_142 ( V_40 ) ) {
V_21 = F_20 ( V_11 , V_32 , V_40 -> V_15 ) ;
break;
}
}
V_26:
if ( V_21 ) {
F_115 ( V_32 ) ;
}
return V_385 ;
}
static int F_241 ( struct V_31 * V_32 , struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
int V_21 = 1 ;
F_64 ( & V_11 -> V_131 ) ;
if ( V_11 -> V_91 )
V_21 = F_20 ( V_11 , V_32 ,
V_11 -> V_91 -> V_15 ) ;
if ( V_21 )
F_115 ( V_32 ) ;
F_66 ( & V_11 -> V_131 ) ;
return V_385 ;
}
static int F_242 ( struct V_31 * V_32 , struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 , * V_381 ;
int V_382 ;
int V_41 ;
int V_21 = 1 ;
V_382 = V_11 -> V_386 ( V_32 , V_11 -> V_23 ) ;
F_29 (bond, slave, i) {
V_382 -- ;
if ( V_382 < 0 )
break;
}
V_381 = V_40 ;
F_75 (bond, slave, i, start_at) {
if ( F_76 ( V_40 -> V_15 ) &&
( V_40 -> V_56 == V_57 ) &&
F_142 ( V_40 ) ) {
V_21 = F_20 ( V_11 , V_32 , V_40 -> V_15 ) ;
break;
}
}
if ( V_21 ) {
F_115 ( V_32 ) ;
}
return V_385 ;
}
static int F_243 ( struct V_31 * V_32 , struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_40 * V_40 , * V_381 ;
struct V_33 * V_387 = NULL ;
int V_41 ;
int V_21 = 1 ;
F_64 ( & V_11 -> V_131 ) ;
V_381 = V_11 -> V_91 ;
F_66 ( & V_11 -> V_131 ) ;
if ( ! V_381 )
goto V_26;
F_75 (bond, slave, i, start_at) {
if ( F_76 ( V_40 -> V_15 ) &&
( V_40 -> V_56 == V_57 ) &&
F_142 ( V_40 ) ) {
if ( V_387 ) {
struct V_31 * V_388 = F_113 ( V_32 , V_165 ) ;
if ( ! V_388 ) {
F_31 ( L_112 ,
V_37 -> V_16 ) ;
continue;
}
V_21 = F_20 ( V_11 , V_388 , V_387 ) ;
if ( V_21 ) {
F_115 ( V_388 ) ;
continue;
}
}
V_387 = V_40 -> V_15 ;
}
}
if ( V_387 )
V_21 = F_20 ( V_11 , V_32 , V_387 ) ;
V_26:
if ( V_21 )
F_115 ( V_32 ) ;
return V_385 ;
}
static void F_244 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_55 . V_389 ) {
case V_390 :
V_11 -> V_386 = F_205 ;
break;
case V_391 :
V_11 -> V_386 = F_208 ;
break;
case V_392 :
default:
V_11 -> V_386 = F_210 ;
break;
}
}
static inline int F_245 ( struct V_10 * V_11 ,
struct V_31 * V_32 )
{
int V_41 , V_21 = 1 ;
struct V_40 * V_40 = NULL ;
struct V_40 * V_393 ;
if ( ! V_32 -> V_36 )
return 1 ;
F_29 (bond, check_slave, i) {
if ( V_393 -> V_192 == V_32 -> V_36 ) {
V_40 = V_393 ;
break;
}
}
if ( V_40 && V_40 -> V_192 && F_76 ( V_40 -> V_15 ) &&
( V_40 -> V_56 == V_57 ) ) {
V_21 = F_20 ( V_11 , V_32 , V_40 -> V_15 ) ;
}
return V_21 ;
}
static T_8 F_246 ( struct V_33 * V_15 , struct V_31 * V_32 )
{
T_8 V_394 = F_247 ( V_32 ) ? F_248 ( V_32 ) : 0 ;
F_21 ( V_32 ) = V_32 -> V_36 ;
if ( F_22 ( V_394 >= V_15 -> V_395 ) ) {
do {
V_394 -= V_15 -> V_395 ;
} while ( V_394 >= V_15 -> V_395 );
}
return V_394 ;
}
static T_9 F_249 ( struct V_31 * V_32 , struct V_33 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
if ( F_250 ( V_11 -> V_55 . V_1 ) ) {
if ( ! F_245 ( V_11 , V_32 ) )
return V_385 ;
}
switch ( V_11 -> V_55 . V_1 ) {
case V_3 :
return F_240 ( V_32 , V_15 ) ;
case V_4 :
return F_241 ( V_32 , V_15 ) ;
case V_5 :
return F_242 ( V_32 , V_15 ) ;
case V_6 :
return F_243 ( V_32 , V_15 ) ;
case V_7 :
return F_251 ( V_32 , V_15 ) ;
case V_9 :
case V_8 :
return F_252 ( V_32 , V_15 ) ;
default:
F_31 ( L_113 ,
V_15 -> V_16 , V_11 -> V_55 . V_1 ) ;
F_253 ( 1 ) ;
F_115 ( V_32 ) ;
return V_385 ;
}
}
static T_9 F_254 ( struct V_31 * V_32 , struct V_33 * V_15 )
{
struct V_10 * V_11 = F_28 ( V_15 ) ;
T_9 V_217 = V_385 ;
if ( F_255 ( V_15 ) )
return V_396 ;
F_64 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_23 )
V_217 = F_249 ( V_32 , V_15 ) ;
else
F_115 ( V_32 ) ;
F_66 ( & V_11 -> V_20 ) ;
return V_217 ;
}
void F_256 ( struct V_10 * V_11 , int V_1 )
{
struct V_33 * V_37 = V_11 -> V_15 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_244 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_244 ( V_11 ) ;
break;
case V_9 :
case V_8 :
break;
default:
F_31 ( L_113 ,
V_37 -> V_16 , V_1 ) ;
break;
}
}
static void F_257 ( struct V_33 * V_37 ,
struct V_397 * V_398 )
{
strncpy ( V_398 -> V_399 , V_400 , 32 ) ;
strncpy ( V_398 -> V_401 , V_402 , 32 ) ;
snprintf ( V_398 -> V_403 , 32 , L_114 , V_404 ) ;
}
static void F_258 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
if ( V_11 -> V_96 )
F_259 ( V_11 -> V_96 ) ;
F_260 ( V_37 ) ;
}
static void F_261 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
F_262 ( & V_11 -> V_20 ) ;
F_262 ( & V_11 -> V_131 ) ;
V_11 -> V_55 = V_405 ;
V_11 -> V_15 = V_37 ;
F_5 ( & V_11 -> V_19 ) ;
F_125 ( V_37 ) ;
V_37 -> V_45 = & V_406 ;
V_37 -> V_67 = & V_407 ;
F_256 ( V_11 , V_11 -> V_55 . V_1 ) ;
V_37 -> V_408 = F_258 ;
V_37 -> V_409 = 0 ;
V_37 -> V_108 |= V_290 | V_410 ;
V_37 -> V_141 |= V_202 ;
V_37 -> V_141 &= ~ V_411 ;
V_37 -> V_24 |= V_25 ;
V_37 -> V_24 |= V_412 ;
V_37 -> V_413 = V_153 |
V_414 |
V_46 |
V_49 ;
V_37 -> V_413 &= ~ ( V_415 & ~ V_416 ) ;
V_37 -> V_24 |= V_37 -> V_413 ;
}
static void F_263 ( struct V_10 * V_11 )
{
F_6 ( & V_11 -> V_20 ) ;
V_11 -> V_235 = 1 ;
F_8 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_55 . V_127 && F_217 ( & V_11 -> V_234 ) )
F_216 ( & V_11 -> V_234 ) ;
if ( V_11 -> V_55 . V_167 && F_217 ( & V_11 -> V_272 ) )
F_216 ( & V_11 -> V_272 ) ;
if ( V_11 -> V_55 . V_1 == V_9 &&
F_217 ( & V_11 -> V_312 ) )
F_216 ( & V_11 -> V_312 ) ;
if ( V_11 -> V_55 . V_1 == V_7 &&
F_217 ( & V_11 -> V_314 ) )
F_216 ( & V_11 -> V_314 ) ;
if ( F_217 ( & V_11 -> V_97 ) )
F_216 ( & V_11 -> V_97 ) ;
}
static void F_264 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_13 * V_14 , * V_417 ;
F_99 ( V_37 ) ;
F_153 ( V_37 ) ;
F_12 ( & V_11 -> V_418 ) ;
F_263 ( V_11 ) ;
F_195 ( V_11 ) ;
F_265 ( V_11 ) ;
F_232 ( & V_11 -> V_367 ) ;
F_266 (vlan, tmp, &bond->vlan_list, vlan_list) {
F_12 ( & V_14 -> V_19 ) ;
F_15 ( V_14 ) ;
}
}
int F_267 ( const char * V_419 , const struct V_420 * V_421 )
{
int V_422 = - 1 , V_41 , V_136 ;
char * V_423 , V_424 [ V_425 + 1 ] = { 0 , } ;
for ( V_423 = ( char * ) V_419 ; * V_423 ; V_423 ++ )
if ( ! ( isdigit ( * V_423 ) || isspace ( * V_423 ) ) )
break;
if ( * V_423 )
V_136 = sscanf ( V_419 , L_115 , V_424 ) ;
else
V_136 = sscanf ( V_419 , L_114 , & V_422 ) ;
if ( ! V_136 )
return - 1 ;
for ( V_41 = 0 ; V_421 [ V_41 ] . V_426 ; V_41 ++ ) {
if ( V_422 == V_421 [ V_41 ] . V_1 )
return V_421 [ V_41 ] . V_1 ;
if ( strcmp ( V_424 , V_421 [ V_41 ] . V_426 ) == 0 )
return V_421 [ V_41 ] . V_1 ;
}
return - 1 ;
}
static int F_268 ( struct V_427 * V_55 )
{
int V_428 , V_429 , V_430 ;
if ( V_1 ) {
V_220 = F_267 ( V_1 , V_431 ) ;
if ( V_220 == - 1 ) {
F_31 ( L_116 ,
V_1 == NULL ? L_17 : V_1 ) ;
return - V_187 ;
}
}
if ( V_386 ) {
if ( ( V_220 != V_5 ) &&
( V_220 != V_7 ) ) {
F_80 ( L_117 ,
F_1 ( V_220 ) ) ;
} else {
V_432 = F_267 ( V_386 ,
V_433 ) ;
if ( V_432 == - 1 ) {
F_31 ( L_118 ,
V_386 == NULL ? L_17 :
V_386 ) ;
return - V_187 ;
}
}
}
if ( V_434 ) {
if ( V_220 != V_7 ) {
F_80 ( L_119 ,
F_1 ( V_220 ) ) ;
} else {
V_210 = F_267 ( V_434 , V_435 ) ;
if ( V_210 == - 1 ) {
F_31 ( L_120 ,
V_434 == NULL ? L_17 : V_434 ) ;
return - V_187 ;
}
}
}
if ( V_436 ) {
V_55 -> V_436 = F_267 ( V_436 , V_437 ) ;
if ( V_55 -> V_436 == - 1 ) {
F_31 ( L_121 ,
V_436 == NULL ? L_17 : V_436 ) ;
return - V_187 ;
}
if ( V_220 != V_7 ) {
F_121 ( L_122 ) ;
}
} else {
V_55 -> V_436 = V_438 ;
}
if ( V_439 < 0 ) {
F_121 ( L_123 ,
V_439 , 0 , V_440 , V_441 ) ;
V_439 = V_441 ;
}
if ( V_127 < 0 ) {
F_121 ( L_124 ,
V_127 , V_440 , V_442 ) ;
V_127 = V_442 ;
}
if ( V_119 < 0 ) {
F_121 ( L_125 ,
V_119 , V_440 ) ;
V_119 = 0 ;
}
if ( V_231 < 0 ) {
F_121 ( L_126 ,
V_231 , V_440 ) ;
V_231 = 0 ;
}
if ( ( V_78 != 0 ) && ( V_78 != 1 ) ) {
F_121 ( L_127 ,
V_78 ) ;
V_78 = 1 ;
}
if ( V_130 < 0 || V_130 > 255 ) {
F_121 ( L_128 ,
V_130 ) ;
V_130 = 1 ;
}
if ( V_220 == V_7 ) {
if ( ! V_127 ) {
F_121 ( L_129 ) ;
F_121 ( L_130 ) ;
V_127 = 100 ;
}
}
if ( V_443 < 1 || V_443 > 255 ) {
F_121 ( L_131
L_132 ,
V_443 , V_444 ) ;
V_443 = V_444 ;
}
if ( ( V_445 != 0 ) && ( V_445 != 1 ) ) {
F_121 ( L_133
L_134
L_135 , V_445 ) ;
V_445 = 0 ;
}
if ( V_134 < 0 || V_134 > 255 ) {
F_121 ( L_136
L_137 ,
V_134 , V_446 ) ;
V_134 = V_446 ;
}
if ( ( V_220 == V_8 ) ||
( V_220 == V_9 ) ) {
if ( ! V_127 ) {
F_121 ( L_138 ) ;
F_121 ( L_130 ) ;
V_127 = 100 ;
}
}
if ( V_220 == V_9 ) {
F_269 ( L_139 ,
V_119 ) ;
}
if ( ! V_127 ) {
if ( V_119 || V_231 ) {
F_121 ( L_140 ,
V_119 , V_231 ) ;
}
} else {
if ( V_167 ) {
F_121 ( L_141 ,
V_127 , V_167 ) ;
V_167 = 0 ;
}
if ( ( V_119 % V_127 ) != 0 ) {
F_121 ( L_142 ,
V_119 , V_127 ,
( V_119 / V_127 ) * V_127 ) ;
}
V_119 /= V_127 ;
if ( ( V_231 % V_127 ) != 0 ) {
F_121 ( L_143 ,
V_231 , V_127 ,
( V_231 / V_127 ) * V_127 ) ;
}
V_231 /= V_127 ;
}
if ( V_167 < 0 ) {
F_121 ( L_144 ,
V_167 , V_440 , V_447 ) ;
V_167 = V_447 ;
}
for ( V_448 = 0 ;
( V_448 < V_253 ) && V_449 [ V_448 ] ;
V_448 ++ ) {
if ( ! isdigit ( V_449 [ V_448 ] [ 0 ] ) ) {
F_121 ( L_145 ,
V_449 [ V_448 ] ) ;
V_167 = 0 ;
} else {
T_5 V_242 = F_270 ( V_449 [ V_448 ] ) ;
V_450 [ V_448 ] = V_242 ;
}
}
if ( V_167 && ! V_448 ) {
F_121 ( L_146 ,
V_167 ) ;
V_167 = 0 ;
}
if ( V_271 ) {
if ( V_220 != V_4 ) {
F_31 ( L_147 ) ;
return - V_187 ;
}
if ( ! V_167 ) {
F_31 ( L_148 ) ;
return - V_187 ;
}
V_428 = F_267 ( V_271 ,
V_451 ) ;
if ( V_428 == - 1 ) {
F_31 ( L_149 ,
V_271 == NULL ? L_17 : V_271 ) ;
return - V_187 ;
}
} else
V_428 = 0 ;
if ( V_127 ) {
F_80 ( L_150 , V_127 ) ;
} else if ( V_167 ) {
int V_41 ;
F_80 ( L_151 ,
V_167 ,
V_451 [ V_428 ] . V_426 ,
V_448 ) ;
for ( V_41 = 0 ; V_41 < V_448 ; V_41 ++ )
F_80 ( L_152 , V_449 [ V_41 ] ) ;
F_80 ( L_153 ) ;
} else if ( V_439 ) {
F_121 ( L_154 ) ;
}
if ( V_207 && ! F_50 ( V_220 ) ) {
F_121 ( L_155 ,
V_207 , F_1 ( V_220 ) ) ;
V_207 = NULL ;
}
if ( V_207 && V_114 ) {
V_430 = F_267 ( V_114 ,
V_452 ) ;
if ( V_430 == - 1 ) {
F_31 ( L_156 ,
V_114 ==
NULL ? L_17 : V_114 ) ;
return - V_187 ;
}
} else {
V_430 = V_453 ;
}
if ( V_129 ) {
V_429 = F_267 ( V_129 ,
V_454 ) ;
if ( V_429 == - 1 ) {
F_31 ( L_157 ,
V_271 == NULL ? L_17 : V_271 ) ;
return - V_187 ;
}
if ( V_220 != V_4 )
F_121 ( L_158 ) ;
} else {
V_429 = V_455 ;
}
V_55 -> V_1 = V_220 ;
V_55 -> V_389 = V_432 ;
V_55 -> V_127 = V_127 ;
V_55 -> V_130 = V_130 ;
V_55 -> V_167 = V_167 ;
V_55 -> V_271 = V_428 ;
V_55 -> V_119 = V_119 ;
V_55 -> V_231 = V_231 ;
V_55 -> V_78 = V_78 ;
V_55 -> V_210 = V_210 ;
V_55 -> V_207 [ 0 ] = 0 ;
V_55 -> V_114 = V_430 ;
V_55 -> V_129 = V_429 ;
V_55 -> V_443 = V_443 ;
V_55 -> V_445 = V_445 ;
V_55 -> V_134 = V_134 ;
if ( V_207 ) {
strncpy ( V_55 -> V_207 , V_207 , V_83 ) ;
V_55 -> V_207 [ V_83 - 1 ] = 0 ;
}
memcpy ( V_55 -> V_250 , V_450 , sizeof( V_450 ) ) ;
return 0 ;
}
static void F_271 ( struct V_33 * V_15 ,
struct V_456 * V_394 ,
void * V_457 )
{
F_272 ( & V_394 -> V_458 ,
& V_459 ) ;
}
static void F_273 ( struct V_33 * V_15 )
{
F_272 ( & V_15 -> V_460 ,
& V_461 ) ;
F_274 ( V_15 , F_271 , NULL ) ;
}
static int F_275 ( struct V_33 * V_37 )
{
struct V_10 * V_11 = F_28 ( V_37 ) ;
struct V_292 * V_293 = F_204 ( F_174 ( V_37 ) , V_294 ) ;
struct V_462 * V_463 = & ( F_276 ( V_11 ) ) ;
F_3 ( L_159 , V_37 -> V_16 ) ;
F_277 ( & ( V_463 -> V_464 ) ) ;
F_277 ( & ( V_463 -> V_465 ) ) ;
V_11 -> V_96 = F_278 ( V_37 -> V_16 ) ;
if ( ! V_11 -> V_96 )
return - V_18 ;
F_273 ( V_37 ) ;
F_196 ( V_11 ) ;
F_7 ( & V_11 -> V_418 , & V_293 -> V_466 ) ;
F_279 ( V_11 ) ;
F_280 ( V_11 ) ;
F_281 ( & V_11 -> V_367 ) ;
return 0 ;
}
static int F_282 ( struct V_467 * V_468 [] , struct V_467 * V_174 [] )
{
if ( V_468 [ V_469 ] ) {
if ( F_283 ( V_468 [ V_469 ] ) != V_104 )
return - V_187 ;
if ( ! F_239 ( F_284 ( V_468 [ V_469 ] ) ) )
return - V_380 ;
}
return 0 ;
}
int F_285 ( struct V_470 * V_470 , const char * V_16 )
{
struct V_33 * V_37 ;
int V_21 ;
F_163 () ;
V_37 = F_286 ( sizeof( struct V_10 ) ,
V_16 ? V_16 : L_160 ,
F_261 , V_443 ) ;
if ( ! V_37 ) {
F_31 ( L_161 , V_16 ) ;
F_164 () ;
return - V_18 ;
}
F_287 ( V_37 , V_470 ) ;
V_37 -> V_471 = & V_472 ;
V_21 = F_288 ( V_37 ) ;
F_41 ( V_37 ) ;
F_164 () ;
if ( V_21 < 0 )
F_258 ( V_37 ) ;
return V_21 ;
}
static int T_10 F_289 ( struct V_470 * V_470 )
{
struct V_292 * V_293 = F_204 ( V_470 , V_294 ) ;
V_293 -> V_470 = V_470 ;
F_5 ( & V_293 -> V_466 ) ;
F_290 ( V_293 ) ;
return 0 ;
}
static void T_11 F_291 ( struct V_470 * V_470 )
{
struct V_292 * V_293 = F_204 ( V_470 , V_294 ) ;
F_292 ( V_293 ) ;
}
static int T_12 F_293 ( void )
{
int V_41 ;
int V_21 ;
F_80 ( L_162 , V_473 ) ;
V_21 = F_268 ( & V_405 ) ;
if ( V_21 )
goto V_26;
V_21 = F_294 ( & V_474 ) ;
if ( V_21 )
goto V_26;
V_21 = F_295 ( & V_472 ) ;
if ( V_21 )
goto V_475;
F_296 () ;
for ( V_41 = 0 ; V_41 < V_439 ; V_41 ++ ) {
V_21 = F_285 ( & V_476 , NULL ) ;
if ( V_21 )
goto V_90;
}
V_21 = F_297 () ;
if ( V_21 )
goto V_90;
F_298 ( & V_477 ) ;
F_299 ( & V_478 ) ;
V_26:
return V_21 ;
V_90:
F_300 ( & V_472 ) ;
V_475:
F_301 ( & V_474 ) ;
goto V_26;
}
static void T_13 F_302 ( void )
{
F_303 ( & V_477 ) ;
F_304 ( & V_478 ) ;
F_305 () ;
F_306 () ;
F_300 ( & V_472 ) ;
F_301 ( & V_474 ) ;
#ifdef F_139
F_307 ( F_308 ( & V_479 ) ) ;
#endif
}
