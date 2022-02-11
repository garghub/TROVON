static struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = V_2 ;
F_2 () ;
do {
V_3 = F_3 ( V_3 ) ;
} while ( V_3 && ! ( V_3 -> V_4 & V_5 ) );
if ( V_3 )
F_4 ( V_3 ) ;
F_5 () ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 = F_1 ( V_6 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 = 0 ;
F_7 ( V_9 ? V_9 : V_6 ) ;
F_8 (mc_list_entry, bridge ? bridge : dev) {
V_13 = F_9 ( sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 ) {
V_14 = - V_16 ;
break;
}
F_10 ( V_13 -> V_17 , V_11 -> V_17 ) ;
F_11 ( & V_13 -> V_18 , V_8 ) ;
V_14 ++ ;
}
F_12 ( V_9 ? V_9 : V_6 ) ;
if ( V_9 )
F_13 ( V_9 ) ;
return V_14 ;
}
static bool F_14 ( T_1 * V_19 ,
struct V_7 * V_8 )
{
struct V_12 * V_20 ;
F_15 (mcast_entry, mcast_list, list)
if ( F_16 ( V_20 -> V_17 , V_19 ) )
return true ;
return false ;
}
static void F_17 ( char * V_21 , const struct V_22 * V_23 )
{
if ( V_23 -> V_24 == F_18 ( V_25 ) )
F_19 ( V_23 -> V_26 . V_27 , V_21 ) ;
#if F_20 ( V_28 )
else if ( V_23 -> V_24 == F_18 ( V_29 ) )
F_21 ( & V_23 -> V_26 . V_30 , V_21 ) ;
#endif
else
F_22 ( V_21 ) ;
}
static int F_23 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_31 V_32 = F_24 ( V_32 ) ;
struct V_33 * V_34 , * V_35 ;
struct V_12 * V_13 ;
T_1 V_19 [ V_36 ] ;
int V_14 ;
V_14 = F_25 ( V_6 , & V_32 ) ;
if ( V_14 < 0 )
goto V_37;
F_26 (br_ip_entry, &bridge_mcast_list, list) {
F_17 ( V_19 , & V_34 -> V_17 ) ;
if ( F_14 ( V_19 , V_8 ) )
continue;
V_13 = F_9 ( sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 ) {
V_14 = - V_16 ;
break;
}
F_10 ( V_13 -> V_17 , V_19 ) ;
F_11 ( & V_13 -> V_18 , V_8 ) ;
}
V_37:
F_27 (br_ip_entry, tmp, &bridge_mcast_list, list) {
F_28 ( & V_34 -> V_18 ) ;
F_29 ( V_34 ) ;
}
return V_14 ;
}
static void F_30 ( struct V_38 * V_39 ,
struct V_7 * V_8 )
{
struct V_12 * V_20 ;
struct V_40 * V_35 ;
F_31 ( & V_39 -> V_41 . V_42 ) ;
F_32 (mcast_entry, tmp, mcast_list, list) {
F_33 ( & V_20 -> V_18 ) ;
F_29 ( V_20 ) ;
}
}
static void F_34 ( struct V_38 * V_39 ,
struct V_7 * V_8 )
{
struct V_12 * V_20 ;
struct V_40 * V_35 ;
F_31 ( & V_39 -> V_41 . V_42 ) ;
F_32 (mcast_entry, tmp, &bat_priv->mcast.mla_list,
list) {
if ( V_8 &&
F_14 ( V_20 -> V_17 ,
V_8 ) )
continue;
F_35 ( V_39 , V_20 -> V_17 ,
V_43 ,
L_1 , false ) ;
F_33 ( & V_20 -> V_18 ) ;
F_29 ( V_20 ) ;
}
}
static void F_36 ( struct V_38 * V_39 ,
struct V_7 * V_8 )
{
struct V_12 * V_20 ;
struct V_40 * V_35 ;
F_31 ( & V_39 -> V_41 . V_42 ) ;
if ( ! V_8 )
return;
F_32 (mcast_entry, tmp, mcast_list, list) {
if ( F_14 ( V_20 -> V_17 ,
& V_39 -> V_44 . V_45 ) )
continue;
if ( ! F_37 ( V_39 -> V_2 ,
V_20 -> V_17 , V_43 ,
V_46 , V_47 ) )
continue;
F_33 ( & V_20 -> V_18 ) ;
F_11 ( & V_20 -> V_18 , & V_39 -> V_44 . V_45 ) ;
}
}
static bool F_38 ( struct V_38 * V_39 )
{
struct V_1 * V_3 = V_39 -> V_2 ;
F_2 () ;
do {
V_3 = F_3 ( V_3 ) ;
} while ( V_3 && ! ( V_3 -> V_4 & V_5 ) );
F_5 () ;
return V_3 ;
}
static void
F_39 ( struct V_38 * V_39 , char * V_48 ,
struct V_49 * V_50 ,
struct V_49 * V_51 )
{
if ( ! V_50 -> V_52 && V_51 -> V_52 )
F_40 ( V_39 -> V_2 , L_2 ,
V_48 ) ;
else if ( V_50 -> V_52 && ! V_51 -> V_52 )
F_40 ( V_39 -> V_2 ,
L_3 ,
V_48 ) ;
else if ( ! V_39 -> V_44 . V_53 && ! V_51 -> V_52 )
F_40 ( V_39 -> V_2 ,
L_4 ,
V_48 ) ;
if ( V_51 -> V_52 ) {
if ( ( ! V_50 -> V_54 && V_51 -> V_54 ) ||
( ! V_50 -> V_52 && V_51 -> V_54 ) )
F_41 ( V_55 , V_39 ,
L_5 ,
V_48 ) ;
else if ( V_50 -> V_54 && ! V_51 -> V_54 )
F_41 ( V_55 , V_39 ,
L_6 ,
V_48 ) ;
}
}
static void
F_42 ( struct V_38 * V_39 , bool V_53 ,
struct V_49 * V_56 ,
struct V_49 * V_57 )
{
if ( ! V_39 -> V_44 . V_53 && V_53 )
F_41 ( V_55 , V_39 ,
L_7 ) ;
else if ( V_39 -> V_44 . V_53 && ! V_53 )
F_41 ( V_55 , V_39 ,
L_8 ) ;
if ( V_53 ) {
F_39 ( V_39 , L_9 ,
& V_39 -> V_44 . V_56 ,
V_56 ) ;
F_39 ( V_39 , L_10 ,
& V_39 -> V_44 . V_57 ,
V_57 ) ;
}
}
static void F_43 ( struct V_38 * V_39 , T_1 V_58 )
{
T_1 V_59 = V_39 -> V_44 . V_58 ;
char V_60 [] = L_11 ;
sprintf ( V_60 , L_12 ,
( V_59 & V_61 ) ? 'U' : '.' ,
( V_59 & V_62 ) ? '4' : '.' ,
( V_59 & V_63 ) ? '6' : '.' ) ;
F_41 ( V_55 , V_39 ,
L_13 ,
V_39 -> V_44 . V_64 ? V_60 : L_14 ,
( V_58 & V_61 ) ? 'U' : '.' ,
( V_58 & V_62 ) ? '4' : '.' ,
( V_58 & V_63 ) ? '6' : '.' ) ;
}
static bool F_44 ( struct V_38 * V_39 )
{
struct V_65 V_66 ;
struct V_49 V_67 = { false , false } ;
struct V_49 V_68 = { false , false } ;
struct V_1 * V_6 = V_39 -> V_2 ;
bool V_53 ;
V_66 . V_58 = V_43 ;
memset ( V_66 . V_69 , 0 , sizeof( V_66 . V_69 ) ) ;
V_53 = F_38 ( V_39 ) ;
if ( ! V_53 )
goto V_70;
#if ! F_20 ( V_71 )
F_45 ( L_15 ) ;
#endif
V_67 . V_52 = F_46 ( V_6 , V_25 ) ;
V_67 . V_54 = F_47 ( V_6 , V_25 ) ;
V_68 . V_52 = F_46 ( V_6 , V_29 ) ;
V_68 . V_54 = F_47 ( V_6 , V_29 ) ;
V_66 . V_58 |= V_61 ;
if ( ! V_67 . V_52 || V_67 . V_54 )
V_66 . V_58 |= V_62 ;
if ( ! V_68 . V_52 || V_68 . V_54 )
V_66 . V_58 |= V_63 ;
V_70:
F_42 ( V_39 , V_53 , & V_67 , & V_68 ) ;
V_39 -> V_44 . V_56 . V_52 = V_67 . V_52 ;
V_39 -> V_44 . V_56 . V_54 = V_67 . V_54 ;
V_39 -> V_44 . V_57 . V_52 = V_68 . V_52 ;
V_39 -> V_44 . V_57 . V_54 = V_68 . V_54 ;
V_39 -> V_44 . V_53 = V_53 ;
if ( ! V_39 -> V_44 . V_64 ||
V_66 . V_58 != V_39 -> V_44 . V_58 ) {
F_43 ( V_39 , V_66 . V_58 ) ;
F_48 ( V_39 , V_72 , 2 ,
& V_66 , sizeof( V_66 ) ) ;
V_39 -> V_44 . V_58 = V_66 . V_58 ;
V_39 -> V_44 . V_64 = true ;
}
return ! ( V_66 . V_58 &
( V_62 | V_63 ) ) ;
}
void F_49 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_7 V_8 = V_73 ;
int V_14 ;
if ( ! F_44 ( V_39 ) )
goto V_70;
V_14 = F_6 ( V_2 , & V_8 ) ;
if ( V_14 < 0 )
goto V_37;
V_14 = F_23 ( V_2 , & V_8 ) ;
if ( V_14 < 0 )
goto V_37;
V_70:
F_34 ( V_39 , & V_8 ) ;
F_36 ( V_39 , & V_8 ) ;
V_37:
F_30 ( V_39 , & V_8 ) ;
}
static bool F_50 ( struct V_74 * V_75 )
{
if ( F_51 ( V_75 , NULL ) < 0 )
return false ;
switch ( F_52 ( V_75 ) -> type ) {
case V_76 :
case V_77 :
case V_78 :
return true ;
}
return false ;
}
static int F_53 ( struct V_38 * V_39 ,
struct V_74 * V_75 ,
bool * V_79 )
{
struct V_80 * V_80 ;
if ( ! F_54 ( V_75 , sizeof( struct V_81 ) + sizeof( * V_80 ) ) )
return - V_16 ;
if ( F_50 ( V_75 ) )
return - V_82 ;
V_80 = F_55 ( V_75 ) ;
if ( ! F_56 ( V_80 -> V_83 ) )
return - V_82 ;
* V_79 = true ;
return 0 ;
}
static bool F_57 ( struct V_74 * V_75 )
{
if ( F_58 ( V_75 , NULL ) < 0 )
return false ;
switch ( F_59 ( V_75 ) -> V_84 ) {
case V_85 :
case V_86 :
return true ;
}
return false ;
}
static int F_60 ( struct V_38 * V_39 ,
struct V_74 * V_75 ,
bool * V_79 )
{
struct V_87 * V_88 ;
if ( ! F_54 ( V_75 , sizeof( struct V_81 ) + sizeof( * V_88 ) ) )
return - V_16 ;
if ( F_57 ( V_75 ) )
return - V_82 ;
V_88 = F_61 ( V_75 ) ;
if ( F_62 ( & V_88 -> V_83 ) != V_89 )
return - V_82 ;
if ( F_63 ( & V_88 -> V_83 ) )
* V_79 = true ;
return 0 ;
}
static int F_64 ( struct V_38 * V_39 ,
struct V_74 * V_75 ,
bool * V_79 )
{
struct V_81 * V_81 = F_65 ( V_75 ) ;
if ( ! F_66 ( & V_39 -> V_90 ) )
return - V_82 ;
if ( F_66 ( & V_39 -> V_44 . V_91 ) )
return - V_82 ;
switch ( F_67 ( V_81 -> V_92 ) ) {
case V_25 :
return F_53 ( V_39 , V_75 ,
V_79 ) ;
#if F_20 ( V_28 )
case V_29 :
return F_60 ( V_39 , V_75 ,
V_79 ) ;
#endif
default:
return - V_82 ;
}
}
static int F_68 ( struct V_38 * V_39 ,
struct V_81 * V_81 )
{
switch ( F_67 ( V_81 -> V_92 ) ) {
case V_25 :
return F_66 ( & V_39 -> V_44 . V_93 ) ;
case V_29 :
return F_66 ( & V_39 -> V_44 . V_94 ) ;
default:
return 0 ;
}
}
static struct V_95 *
F_69 ( struct V_38 * V_39 ,
struct V_81 * V_81 )
{
return F_70 ( V_39 , V_81 -> V_96 ,
V_81 -> V_97 , V_43 ) ;
}
static struct V_95 *
F_71 ( struct V_38 * V_39 )
{
struct V_95 * V_98 , * V_99 = NULL ;
F_2 () ;
F_72 (tmp_orig_node,
&bat_priv->mcast.want_all_ipv4_list,
mcast_want_all_ipv4_node) {
if ( ! F_73 ( & V_98 -> V_100 ) )
continue;
V_99 = V_98 ;
break;
}
F_5 () ;
return V_99 ;
}
static struct V_95 *
F_74 ( struct V_38 * V_39 )
{
struct V_95 * V_98 , * V_99 = NULL ;
F_2 () ;
F_72 (tmp_orig_node,
&bat_priv->mcast.want_all_ipv6_list,
mcast_want_all_ipv6_node) {
if ( ! F_73 ( & V_98 -> V_100 ) )
continue;
V_99 = V_98 ;
break;
}
F_5 () ;
return V_99 ;
}
static struct V_95 *
F_75 ( struct V_38 * V_39 ,
struct V_81 * V_81 )
{
switch ( F_67 ( V_81 -> V_92 ) ) {
case V_25 :
return F_71 ( V_39 ) ;
case V_29 :
return F_74 ( V_39 ) ;
default:
return NULL ;
}
}
static struct V_95 *
F_76 ( struct V_38 * V_39 )
{
struct V_95 * V_98 , * V_99 = NULL ;
F_2 () ;
F_72 (tmp_orig_node,
&bat_priv->mcast.want_all_unsnoopables_list,
mcast_want_all_unsnoopables_node) {
if ( ! F_73 ( & V_98 -> V_100 ) )
continue;
V_99 = V_98 ;
break;
}
F_5 () ;
return V_99 ;
}
enum V_101
F_77 ( struct V_38 * V_39 , struct V_74 * V_75 ,
struct V_95 * * V_102 )
{
int V_14 , V_103 , V_104 , V_105 , V_106 ;
bool V_79 = false ;
struct V_81 * V_81 ;
V_14 = F_64 ( V_39 , V_75 , & V_79 ) ;
if ( V_14 == - V_16 )
return V_107 ;
else if ( V_14 < 0 )
return V_108 ;
V_81 = F_65 ( V_75 ) ;
V_103 = F_78 ( V_39 , V_81 -> V_97 ,
V_43 ) ;
V_104 = F_68 ( V_39 , V_81 ) ;
V_105 = ! V_79 ? 0 :
F_66 ( & V_39 -> V_44 . V_109 ) ;
V_106 = V_103 + V_104 + V_105 ;
switch ( V_106 ) {
case 1 :
if ( V_103 )
* V_102 = F_69 ( V_39 , V_81 ) ;
else if ( V_104 )
* V_102 = F_75 ( V_39 , V_81 ) ;
else if ( V_105 )
* V_102 = F_76 ( V_39 ) ;
if ( * V_102 )
return V_110 ;
case 0 :
return V_107 ;
default:
return V_108 ;
}
}
static void F_79 ( struct V_38 * V_39 ,
struct V_95 * V_102 ,
T_1 V_111 )
{
struct V_40 * V_112 = & V_102 -> V_113 ;
struct V_7 * V_114 = & V_39 -> V_44 . V_115 ;
F_31 ( & V_102 -> V_116 ) ;
if ( V_111 & V_61 &&
! ( V_102 -> V_111 & V_61 ) ) {
F_80 ( & V_39 -> V_44 . V_109 ) ;
F_81 ( & V_39 -> V_44 . V_117 ) ;
F_82 ( ! F_83 ( V_112 ) ) ;
F_84 ( V_112 , V_114 ) ;
F_85 ( & V_39 -> V_44 . V_117 ) ;
} else if ( ! ( V_111 & V_61 ) &&
V_102 -> V_111 & V_61 ) {
F_86 ( & V_39 -> V_44 . V_109 ) ;
F_81 ( & V_39 -> V_44 . V_117 ) ;
F_82 ( F_83 ( V_112 ) ) ;
F_87 ( V_112 ) ;
F_85 ( & V_39 -> V_44 . V_117 ) ;
}
}
static void F_88 ( struct V_38 * V_39 ,
struct V_95 * V_102 ,
T_1 V_111 )
{
struct V_40 * V_112 = & V_102 -> V_118 ;
struct V_7 * V_114 = & V_39 -> V_44 . V_119 ;
F_31 ( & V_102 -> V_116 ) ;
if ( V_111 & V_62 &&
! ( V_102 -> V_111 & V_62 ) ) {
F_80 ( & V_39 -> V_44 . V_93 ) ;
F_81 ( & V_39 -> V_44 . V_117 ) ;
F_82 ( ! F_83 ( V_112 ) ) ;
F_84 ( V_112 , V_114 ) ;
F_85 ( & V_39 -> V_44 . V_117 ) ;
} else if ( ! ( V_111 & V_62 ) &&
V_102 -> V_111 & V_62 ) {
F_86 ( & V_39 -> V_44 . V_93 ) ;
F_81 ( & V_39 -> V_44 . V_117 ) ;
F_82 ( F_83 ( V_112 ) ) ;
F_87 ( V_112 ) ;
F_85 ( & V_39 -> V_44 . V_117 ) ;
}
}
static void F_89 ( struct V_38 * V_39 ,
struct V_95 * V_102 ,
T_1 V_111 )
{
struct V_40 * V_112 = & V_102 -> V_120 ;
struct V_7 * V_114 = & V_39 -> V_44 . V_121 ;
F_31 ( & V_102 -> V_116 ) ;
if ( V_111 & V_63 &&
! ( V_102 -> V_111 & V_63 ) ) {
F_80 ( & V_39 -> V_44 . V_94 ) ;
F_81 ( & V_39 -> V_44 . V_117 ) ;
F_82 ( ! F_83 ( V_112 ) ) ;
F_84 ( V_112 , V_114 ) ;
F_85 ( & V_39 -> V_44 . V_117 ) ;
} else if ( ! ( V_111 & V_63 ) &&
V_102 -> V_111 & V_63 ) {
F_86 ( & V_39 -> V_44 . V_94 ) ;
F_81 ( & V_39 -> V_44 . V_117 ) ;
F_82 ( F_83 ( V_112 ) ) ;
F_87 ( V_112 ) ;
F_85 ( & V_39 -> V_44 . V_117 ) ;
}
}
static void F_90 ( struct V_38 * V_39 ,
struct V_95 * V_102 ,
T_1 V_58 ,
void * V_122 ,
T_2 V_123 )
{
bool V_124 = ! ( V_58 & V_125 ) ;
T_1 V_111 = V_43 ;
bool V_126 ;
if ( V_124 && V_122 &&
( V_123 >= sizeof( V_111 ) ) )
V_111 = * ( T_1 * ) V_122 ;
F_81 ( & V_102 -> V_116 ) ;
V_126 = F_91 ( V_127 ,
& V_102 -> V_128 ) ;
if ( V_124 &&
! F_91 ( V_127 , & V_102 -> V_129 ) ) {
if ( V_126 )
F_86 ( & V_39 -> V_44 . V_91 ) ;
F_92 ( V_127 , & V_102 -> V_129 ) ;
} else if ( ! V_124 &&
( F_91 ( V_127 , & V_102 -> V_129 ) ||
! V_126 ) ) {
F_80 ( & V_39 -> V_44 . V_91 ) ;
F_93 ( V_127 , & V_102 -> V_129 ) ;
}
F_92 ( V_127 , & V_102 -> V_128 ) ;
F_79 ( V_39 , V_102 , V_111 ) ;
F_88 ( V_39 , V_102 , V_111 ) ;
F_89 ( V_39 , V_102 , V_111 ) ;
V_102 -> V_111 = V_111 ;
F_85 ( & V_102 -> V_116 ) ;
}
void F_94 ( struct V_38 * V_39 )
{
F_95 ( V_39 , F_90 ,
NULL , V_72 , 2 ,
V_125 ) ;
}
static void F_96 ( struct V_38 * V_39 ,
struct V_130 * V_131 )
{
T_1 V_58 = V_39 -> V_44 . V_58 ;
char V_67 , V_68 , V_132 , V_133 ;
bool V_53 = V_39 -> V_44 . V_53 ;
if ( V_53 ) {
V_67 = V_39 -> V_44 . V_56 . V_52 ? '.' : '4' ;
V_68 = V_39 -> V_44 . V_57 . V_52 ? '.' : '6' ;
V_132 = V_39 -> V_44 . V_56 . V_54 ? '4' : '.' ;
V_133 = V_39 -> V_44 . V_57 . V_54 ? '6' : '.' ;
} else {
V_67 = '?' ;
V_68 = '?' ;
V_132 = '?' ;
V_133 = '?' ;
}
F_97 ( V_131 , L_16 ,
( V_58 & V_61 ) ? 'U' : '.' ,
( V_58 & V_62 ) ? '4' : '.' ,
( V_58 & V_63 ) ? '6' : '.' ) ;
F_97 ( V_131 , L_17 , V_53 ? 'U' : '.' ) ;
F_97 ( V_131 , L_18 ,
V_67 , V_68 ) ;
F_97 ( V_131 , L_19 ,
V_132 , V_133 ) ;
F_98 ( V_131 , L_20 ) ;
F_97 ( V_131 , L_21 , L_22 , L_23 ) ;
}
int F_99 ( struct V_130 * V_131 , void * V_134 )
{
struct V_1 * V_135 = (struct V_1 * ) V_131 -> V_136 ;
struct V_38 * V_39 = F_100 ( V_135 ) ;
struct V_137 * V_138 ;
struct V_139 * V_140 = V_39 -> V_141 ;
struct V_95 * V_99 ;
struct V_7 * V_114 ;
T_1 V_58 ;
T_3 V_142 ;
V_138 = F_101 ( V_131 ) ;
if ( ! V_138 )
return 0 ;
F_96 ( V_39 , V_131 ) ;
for ( V_142 = 0 ; V_142 < V_140 -> V_143 ; V_142 ++ ) {
V_114 = & V_140 -> V_144 [ V_142 ] ;
F_2 () ;
F_72 (orig_node, head, hash_entry) {
if ( ! F_91 ( V_127 ,
& V_99 -> V_128 ) )
continue;
if ( ! F_91 ( V_127 ,
& V_99 -> V_129 ) ) {
F_97 ( V_131 , L_24 , V_99 -> V_102 ) ;
continue;
}
V_58 = V_99 -> V_111 ;
F_97 ( V_131 , L_25 , V_99 -> V_102 ,
( V_58 & V_61 )
? 'U' : '.' ,
( V_58 & V_62 )
? '4' : '.' ,
( V_58 & V_63 )
? '6' : '.' ) ;
}
F_5 () ;
}
F_102 ( V_138 ) ;
return 0 ;
}
void F_103 ( struct V_38 * V_39 )
{
F_104 ( V_39 , V_72 , 2 ) ;
F_105 ( V_39 , V_72 , 2 ) ;
F_81 ( & V_39 -> V_41 . V_42 ) ;
F_34 ( V_39 , NULL ) ;
F_85 ( & V_39 -> V_41 . V_42 ) ;
}
void F_106 ( struct V_95 * V_102 )
{
struct V_38 * V_39 = V_102 -> V_39 ;
F_81 ( & V_102 -> V_116 ) ;
if ( ! F_91 ( V_127 , & V_102 -> V_129 ) &&
F_91 ( V_127 , & V_102 -> V_128 ) )
F_86 ( & V_39 -> V_44 . V_91 ) ;
F_79 ( V_39 , V_102 , V_43 ) ;
F_88 ( V_39 , V_102 , V_43 ) ;
F_89 ( V_39 , V_102 , V_43 ) ;
F_85 ( & V_102 -> V_116 ) ;
}
