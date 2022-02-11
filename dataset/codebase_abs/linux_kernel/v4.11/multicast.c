static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , & V_2 -> V_4 . V_5 ,
F_3 ( V_6 ) ) ;
}
static struct V_7 * F_4 ( struct V_7 * V_8 )
{
struct V_7 * V_9 = V_8 ;
F_5 () ;
do {
V_9 = F_6 ( V_9 ) ;
} while ( V_9 && ! ( V_9 -> V_10 & V_11 ) );
if ( V_9 )
F_7 ( V_9 ) ;
F_8 () ;
return V_9 ;
}
static int F_9 ( struct V_7 * V_12 ,
struct V_13 * V_14 )
{
struct V_7 * V_15 = F_4 ( V_12 ) ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 = 0 ;
F_10 ( V_15 ? V_15 : V_12 ) ;
F_11 (mc_list_entry, bridge ? bridge : dev) {
V_19 = F_12 ( sizeof( * V_19 ) , V_21 ) ;
if ( ! V_19 ) {
V_20 = - V_22 ;
break;
}
F_13 ( V_19 -> V_23 , V_17 -> V_23 ) ;
F_14 ( & V_19 -> V_24 , V_14 ) ;
V_20 ++ ;
}
F_15 ( V_15 ? V_15 : V_12 ) ;
if ( V_15 )
F_16 ( V_15 ) ;
return V_20 ;
}
static bool F_17 ( T_1 * V_25 ,
struct V_13 * V_14 )
{
struct V_18 * V_26 ;
F_18 (mcast_entry, mcast_list, list)
if ( F_19 ( V_26 -> V_23 , V_25 ) )
return true ;
return false ;
}
static void F_20 ( char * V_27 , const struct V_28 * V_29 )
{
if ( V_29 -> V_30 == F_21 ( V_31 ) )
F_22 ( V_29 -> V_32 . V_33 , V_27 ) ;
#if F_23 ( V_34 )
else if ( V_29 -> V_30 == F_21 ( V_35 ) )
F_24 ( & V_29 -> V_32 . V_36 , V_27 ) ;
#endif
else
F_25 ( V_27 ) ;
}
static int F_26 ( struct V_7 * V_12 ,
struct V_13 * V_14 )
{
struct V_37 V_38 = F_27 ( V_38 ) ;
struct V_39 * V_40 , * V_41 ;
struct V_18 * V_19 ;
T_1 V_25 [ V_42 ] ;
int V_20 ;
V_20 = F_28 ( V_12 , & V_38 ) ;
if ( V_20 < 0 )
goto V_43;
F_29 (br_ip_entry, &bridge_mcast_list, list) {
F_20 ( V_25 , & V_40 -> V_23 ) ;
if ( F_17 ( V_25 , V_14 ) )
continue;
V_19 = F_12 ( sizeof( * V_19 ) , V_21 ) ;
if ( ! V_19 ) {
V_20 = - V_22 ;
break;
}
F_13 ( V_19 -> V_23 , V_25 ) ;
F_14 ( & V_19 -> V_24 , V_14 ) ;
}
V_43:
F_30 (br_ip_entry, tmp, &bridge_mcast_list, list) {
F_31 ( & V_40 -> V_24 ) ;
F_32 ( V_40 ) ;
}
return V_20 ;
}
static void F_33 ( struct V_13 * V_14 )
{
struct V_18 * V_26 ;
struct V_44 * V_41 ;
F_34 (mcast_entry, tmp, mcast_list, list) {
F_35 ( & V_26 -> V_24 ) ;
F_32 ( V_26 ) ;
}
}
static void F_36 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_18 * V_26 ;
struct V_44 * V_41 ;
F_37 ( F_38 ( & V_2 -> V_4 . V_5 ) ) ;
F_34 (mcast_entry, tmp, &bat_priv->mcast.mla_list,
list) {
if ( V_14 &&
F_17 ( V_26 -> V_23 ,
V_14 ) )
continue;
F_39 ( V_2 , V_26 -> V_23 ,
V_45 ,
L_1 , false ) ;
F_35 ( & V_26 -> V_24 ) ;
F_32 ( V_26 ) ;
}
}
static void F_40 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_18 * V_26 ;
struct V_44 * V_41 ;
F_37 ( F_38 ( & V_2 -> V_4 . V_5 ) ) ;
if ( ! V_14 )
return;
F_34 (mcast_entry, tmp, mcast_list, list) {
if ( F_17 ( V_26 -> V_23 ,
& V_2 -> V_4 . V_46 ) )
continue;
if ( ! F_41 ( V_2 -> V_8 ,
V_26 -> V_23 , V_45 ,
V_47 , V_48 ) )
continue;
F_35 ( & V_26 -> V_24 ) ;
F_14 ( & V_26 -> V_24 , & V_2 -> V_4 . V_46 ) ;
}
}
static bool F_42 ( struct V_1 * V_2 )
{
struct V_7 * V_9 = V_2 -> V_8 ;
F_5 () ;
do {
V_9 = F_6 ( V_9 ) ;
} while ( V_9 && ! ( V_9 -> V_10 & V_11 ) );
F_8 () ;
return V_9 ;
}
static void
F_43 ( struct V_1 * V_2 , char * V_49 ,
struct V_50 * V_51 ,
struct V_50 * V_52 )
{
if ( ! V_51 -> V_53 && V_52 -> V_53 )
F_44 ( V_2 -> V_8 , L_2 ,
V_49 ) ;
else if ( V_51 -> V_53 && ! V_52 -> V_53 )
F_44 ( V_2 -> V_8 ,
L_3 ,
V_49 ) ;
else if ( ! V_2 -> V_4 . V_54 && ! V_52 -> V_53 )
F_44 ( V_2 -> V_8 ,
L_4 ,
V_49 ) ;
if ( V_52 -> V_53 ) {
if ( ( ! V_51 -> V_55 && V_52 -> V_55 ) ||
( ! V_51 -> V_53 && V_52 -> V_55 ) )
F_45 ( V_56 , V_2 ,
L_5 ,
V_49 ) ;
else if ( V_51 -> V_55 && ! V_52 -> V_55 )
F_45 ( V_56 , V_2 ,
L_6 ,
V_49 ) ;
}
}
static void
F_46 ( struct V_1 * V_2 , bool V_54 ,
struct V_50 * V_57 ,
struct V_50 * V_58 )
{
if ( ! V_2 -> V_4 . V_54 && V_54 )
F_45 ( V_56 , V_2 ,
L_7 ) ;
else if ( V_2 -> V_4 . V_54 && ! V_54 )
F_45 ( V_56 , V_2 ,
L_8 ) ;
if ( V_54 ) {
F_43 ( V_2 , L_9 ,
& V_2 -> V_4 . V_57 ,
V_57 ) ;
F_43 ( V_2 , L_10 ,
& V_2 -> V_4 . V_58 ,
V_58 ) ;
}
}
static void F_47 ( struct V_1 * V_2 , T_1 V_59 )
{
T_1 V_60 = V_2 -> V_4 . V_59 ;
char V_61 [] = L_11 ;
sprintf ( V_61 , L_12 ,
( V_60 & V_62 ) ? 'U' : '.' ,
( V_60 & V_63 ) ? '4' : '.' ,
( V_60 & V_64 ) ? '6' : '.' ) ;
F_45 ( V_56 , V_2 ,
L_13 ,
V_2 -> V_4 . V_65 ? V_61 : L_14 ,
( V_59 & V_62 ) ? 'U' : '.' ,
( V_59 & V_63 ) ? '4' : '.' ,
( V_59 & V_64 ) ? '6' : '.' ) ;
}
static bool F_48 ( struct V_1 * V_2 )
{
struct V_66 V_67 ;
struct V_50 V_68 = { false , false } ;
struct V_50 V_69 = { false , false } ;
struct V_7 * V_12 = V_2 -> V_8 ;
bool V_54 ;
V_67 . V_59 = V_45 ;
memset ( V_67 . V_70 , 0 , sizeof( V_67 . V_70 ) ) ;
V_54 = F_42 ( V_2 ) ;
if ( ! V_54 )
goto V_71;
#if ! F_23 ( V_72 )
F_49 ( L_15 ) ;
#endif
V_68 . V_53 = F_50 ( V_12 , V_31 ) ;
V_68 . V_55 = F_51 ( V_12 , V_31 ) ;
V_69 . V_53 = F_50 ( V_12 , V_35 ) ;
V_69 . V_55 = F_51 ( V_12 , V_35 ) ;
V_67 . V_59 |= V_62 ;
if ( ! V_68 . V_53 || V_68 . V_55 )
V_67 . V_59 |= V_63 ;
if ( ! V_69 . V_53 || V_69 . V_55 )
V_67 . V_59 |= V_64 ;
V_71:
F_46 ( V_2 , V_54 , & V_68 , & V_69 ) ;
V_2 -> V_4 . V_57 . V_53 = V_68 . V_53 ;
V_2 -> V_4 . V_57 . V_55 = V_68 . V_55 ;
V_2 -> V_4 . V_58 . V_53 = V_69 . V_53 ;
V_2 -> V_4 . V_58 . V_55 = V_69 . V_55 ;
V_2 -> V_4 . V_54 = V_54 ;
if ( ! V_2 -> V_4 . V_65 ||
V_67 . V_59 != V_2 -> V_4 . V_59 ) {
F_47 ( V_2 , V_67 . V_59 ) ;
F_52 ( V_2 , V_73 , 2 ,
& V_67 , sizeof( V_67 ) ) ;
V_2 -> V_4 . V_59 = V_67 . V_59 ;
V_2 -> V_4 . V_65 = true ;
}
return ! ( V_67 . V_59 &
( V_63 | V_64 ) ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_13 V_14 = V_74 ;
int V_20 ;
if ( ! F_48 ( V_2 ) )
goto V_71;
V_20 = F_9 ( V_8 , & V_14 ) ;
if ( V_20 < 0 )
goto V_43;
V_20 = F_26 ( V_8 , & V_14 ) ;
if ( V_20 < 0 )
goto V_43;
V_71:
F_36 ( V_2 , & V_14 ) ;
F_40 ( V_2 , & V_14 ) ;
V_43:
F_33 ( & V_14 ) ;
}
static void F_54 ( struct V_75 * V_5 )
{
struct V_76 * V_76 ;
struct V_77 * V_78 ;
struct V_1 * V_2 ;
V_76 = F_55 ( V_5 ) ;
V_78 = F_56 ( V_76 , struct V_77 , V_5 ) ;
V_2 = F_56 ( V_78 , struct V_1 , V_4 ) ;
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static bool F_57 ( struct V_79 * V_80 )
{
if ( F_58 ( V_80 , NULL ) < 0 )
return false ;
switch ( F_59 ( V_80 ) -> type ) {
case V_81 :
case V_82 :
case V_83 :
return true ;
}
return false ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
bool * V_84 )
{
struct V_85 * V_85 ;
if ( ! F_61 ( V_80 , sizeof( struct V_86 ) + sizeof( * V_85 ) ) )
return - V_22 ;
if ( F_57 ( V_80 ) )
return - V_87 ;
V_85 = F_62 ( V_80 ) ;
if ( ! F_63 ( V_85 -> V_88 ) )
return - V_87 ;
* V_84 = true ;
return 0 ;
}
static bool F_64 ( struct V_79 * V_80 )
{
if ( F_65 ( V_80 , NULL ) < 0 )
return false ;
switch ( F_66 ( V_80 ) -> V_89 ) {
case V_90 :
case V_91 :
return true ;
}
return false ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
bool * V_84 )
{
struct V_92 * V_93 ;
if ( ! F_61 ( V_80 , sizeof( struct V_86 ) + sizeof( * V_93 ) ) )
return - V_22 ;
if ( F_64 ( V_80 ) )
return - V_87 ;
V_93 = F_68 ( V_80 ) ;
if ( F_69 ( & V_93 -> V_88 ) != V_94 )
return - V_87 ;
if ( F_70 ( & V_93 -> V_88 ) )
* V_84 = true ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
bool * V_84 )
{
struct V_86 * V_86 = F_72 ( V_80 ) ;
if ( ! F_73 ( & V_2 -> V_95 ) )
return - V_87 ;
if ( F_73 ( & V_2 -> V_4 . V_96 ) )
return - V_87 ;
switch ( F_74 ( V_86 -> V_97 ) ) {
case V_31 :
return F_60 ( V_2 , V_80 ,
V_84 ) ;
#if F_23 ( V_34 )
case V_35 :
return F_67 ( V_2 , V_80 ,
V_84 ) ;
#endif
default:
return - V_87 ;
}
}
static int F_75 ( struct V_1 * V_2 ,
struct V_86 * V_86 )
{
switch ( F_74 ( V_86 -> V_97 ) ) {
case V_31 :
return F_73 ( & V_2 -> V_4 . V_98 ) ;
case V_35 :
return F_73 ( & V_2 -> V_4 . V_99 ) ;
default:
return 0 ;
}
}
static struct V_100 *
F_76 ( struct V_1 * V_2 ,
struct V_86 * V_86 )
{
return F_77 ( V_2 , V_86 -> V_101 ,
V_86 -> V_102 , V_45 ) ;
}
static struct V_100 *
F_78 ( struct V_1 * V_2 )
{
struct V_100 * V_103 , * V_104 = NULL ;
F_5 () ;
F_79 (tmp_orig_node,
&bat_priv->mcast.want_all_ipv4_list,
mcast_want_all_ipv4_node) {
if ( ! F_80 ( & V_103 -> V_105 ) )
continue;
V_104 = V_103 ;
break;
}
F_8 () ;
return V_104 ;
}
static struct V_100 *
F_81 ( struct V_1 * V_2 )
{
struct V_100 * V_103 , * V_104 = NULL ;
F_5 () ;
F_79 (tmp_orig_node,
&bat_priv->mcast.want_all_ipv6_list,
mcast_want_all_ipv6_node) {
if ( ! F_80 ( & V_103 -> V_105 ) )
continue;
V_104 = V_103 ;
break;
}
F_8 () ;
return V_104 ;
}
static struct V_100 *
F_82 ( struct V_1 * V_2 ,
struct V_86 * V_86 )
{
switch ( F_74 ( V_86 -> V_97 ) ) {
case V_31 :
return F_78 ( V_2 ) ;
case V_35 :
return F_81 ( V_2 ) ;
default:
return NULL ;
}
}
static struct V_100 *
F_83 ( struct V_1 * V_2 )
{
struct V_100 * V_103 , * V_104 = NULL ;
F_5 () ;
F_79 (tmp_orig_node,
&bat_priv->mcast.want_all_unsnoopables_list,
mcast_want_all_unsnoopables_node) {
if ( ! F_80 ( & V_103 -> V_105 ) )
continue;
V_104 = V_103 ;
break;
}
F_8 () ;
return V_104 ;
}
enum V_106
F_84 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_100 * * V_107 )
{
int V_20 , V_108 , V_109 , V_110 , V_111 ;
bool V_84 = false ;
struct V_86 * V_86 ;
V_20 = F_71 ( V_2 , V_80 , & V_84 ) ;
if ( V_20 == - V_22 )
return V_112 ;
else if ( V_20 < 0 )
return V_113 ;
V_86 = F_72 ( V_80 ) ;
V_108 = F_85 ( V_2 , V_86 -> V_102 ,
V_45 ) ;
V_109 = F_75 ( V_2 , V_86 ) ;
V_110 = ! V_84 ? 0 :
F_73 ( & V_2 -> V_4 . V_114 ) ;
V_111 = V_108 + V_109 + V_110 ;
switch ( V_111 ) {
case 1 :
if ( V_108 )
* V_107 = F_76 ( V_2 , V_86 ) ;
else if ( V_109 )
* V_107 = F_82 ( V_2 , V_86 ) ;
else if ( V_110 )
* V_107 = F_83 ( V_2 ) ;
if ( * V_107 )
return V_115 ;
case 0 :
return V_112 ;
default:
return V_113 ;
}
}
static void F_86 ( struct V_1 * V_2 ,
struct V_100 * V_107 ,
T_1 V_116 )
{
struct V_44 * V_117 = & V_107 -> V_118 ;
struct V_13 * V_119 = & V_2 -> V_4 . V_120 ;
F_87 ( & V_107 -> V_121 ) ;
if ( V_116 & V_62 &&
! ( V_107 -> V_116 & V_62 ) ) {
F_88 ( & V_2 -> V_4 . V_114 ) ;
F_89 ( & V_2 -> V_4 . V_122 ) ;
F_37 ( ! F_90 ( V_117 ) ) ;
F_91 ( V_117 , V_119 ) ;
F_92 ( & V_2 -> V_4 . V_122 ) ;
} else if ( ! ( V_116 & V_62 ) &&
V_107 -> V_116 & V_62 ) {
F_93 ( & V_2 -> V_4 . V_114 ) ;
F_89 ( & V_2 -> V_4 . V_122 ) ;
F_37 ( F_90 ( V_117 ) ) ;
F_94 ( V_117 ) ;
F_92 ( & V_2 -> V_4 . V_122 ) ;
}
}
static void F_95 ( struct V_1 * V_2 ,
struct V_100 * V_107 ,
T_1 V_116 )
{
struct V_44 * V_117 = & V_107 -> V_123 ;
struct V_13 * V_119 = & V_2 -> V_4 . V_124 ;
F_87 ( & V_107 -> V_121 ) ;
if ( V_116 & V_63 &&
! ( V_107 -> V_116 & V_63 ) ) {
F_88 ( & V_2 -> V_4 . V_98 ) ;
F_89 ( & V_2 -> V_4 . V_122 ) ;
F_37 ( ! F_90 ( V_117 ) ) ;
F_91 ( V_117 , V_119 ) ;
F_92 ( & V_2 -> V_4 . V_122 ) ;
} else if ( ! ( V_116 & V_63 ) &&
V_107 -> V_116 & V_63 ) {
F_93 ( & V_2 -> V_4 . V_98 ) ;
F_89 ( & V_2 -> V_4 . V_122 ) ;
F_37 ( F_90 ( V_117 ) ) ;
F_94 ( V_117 ) ;
F_92 ( & V_2 -> V_4 . V_122 ) ;
}
}
static void F_96 ( struct V_1 * V_2 ,
struct V_100 * V_107 ,
T_1 V_116 )
{
struct V_44 * V_117 = & V_107 -> V_125 ;
struct V_13 * V_119 = & V_2 -> V_4 . V_126 ;
F_87 ( & V_107 -> V_121 ) ;
if ( V_116 & V_64 &&
! ( V_107 -> V_116 & V_64 ) ) {
F_88 ( & V_2 -> V_4 . V_99 ) ;
F_89 ( & V_2 -> V_4 . V_122 ) ;
F_37 ( ! F_90 ( V_117 ) ) ;
F_91 ( V_117 , V_119 ) ;
F_92 ( & V_2 -> V_4 . V_122 ) ;
} else if ( ! ( V_116 & V_64 ) &&
V_107 -> V_116 & V_64 ) {
F_93 ( & V_2 -> V_4 . V_99 ) ;
F_89 ( & V_2 -> V_4 . V_122 ) ;
F_37 ( F_90 ( V_117 ) ) ;
F_94 ( V_117 ) ;
F_92 ( & V_2 -> V_4 . V_122 ) ;
}
}
static void F_97 ( struct V_1 * V_2 ,
struct V_100 * V_107 ,
T_1 V_59 ,
void * V_127 ,
T_2 V_128 )
{
bool V_129 = ! ( V_59 & V_130 ) ;
T_1 V_116 = V_45 ;
bool V_131 ;
if ( V_129 && V_127 &&
( V_128 >= sizeof( V_116 ) ) )
V_116 = * ( T_1 * ) V_127 ;
F_89 ( & V_107 -> V_121 ) ;
V_131 = F_98 ( V_132 ,
& V_107 -> V_133 ) ;
if ( V_129 &&
! F_98 ( V_132 , & V_107 -> V_134 ) ) {
if ( V_131 )
F_93 ( & V_2 -> V_4 . V_96 ) ;
F_99 ( V_132 , & V_107 -> V_134 ) ;
} else if ( ! V_129 &&
( F_98 ( V_132 , & V_107 -> V_134 ) ||
! V_131 ) ) {
F_88 ( & V_2 -> V_4 . V_96 ) ;
F_100 ( V_132 , & V_107 -> V_134 ) ;
}
F_99 ( V_132 , & V_107 -> V_133 ) ;
F_86 ( V_2 , V_107 , V_116 ) ;
F_95 ( V_2 , V_107 , V_116 ) ;
F_96 ( V_2 , V_107 , V_116 ) ;
V_107 -> V_116 = V_116 ;
F_92 ( & V_107 -> V_121 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
F_102 ( V_2 , F_97 ,
NULL , V_73 , 2 ,
V_130 ) ;
F_103 ( & V_2 -> V_4 . V_5 , F_54 ) ;
F_1 ( V_2 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
T_1 V_59 = V_2 -> V_4 . V_59 ;
char V_68 , V_69 , V_137 , V_138 ;
bool V_54 = V_2 -> V_4 . V_54 ;
if ( V_54 ) {
V_68 = V_2 -> V_4 . V_57 . V_53 ? '.' : '4' ;
V_69 = V_2 -> V_4 . V_58 . V_53 ? '.' : '6' ;
V_137 = V_2 -> V_4 . V_57 . V_55 ? '4' : '.' ;
V_138 = V_2 -> V_4 . V_58 . V_55 ? '6' : '.' ;
} else {
V_68 = '?' ;
V_69 = '?' ;
V_137 = '?' ;
V_138 = '?' ;
}
F_105 ( V_136 , L_16 ,
( V_59 & V_62 ) ? 'U' : '.' ,
( V_59 & V_63 ) ? '4' : '.' ,
( V_59 & V_64 ) ? '6' : '.' ) ;
F_105 ( V_136 , L_17 , V_54 ? 'U' : '.' ) ;
F_105 ( V_136 , L_18 ,
V_68 , V_69 ) ;
F_105 ( V_136 , L_19 ,
V_137 , V_138 ) ;
F_106 ( V_136 , L_20 ) ;
F_105 ( V_136 , L_21 , L_22 , L_23 ) ;
}
int F_107 ( struct V_135 * V_136 , void * V_139 )
{
struct V_7 * V_140 = (struct V_7 * ) V_136 -> V_141 ;
struct V_1 * V_2 = F_108 ( V_140 ) ;
struct V_142 * V_143 ;
struct V_144 * V_145 = V_2 -> V_146 ;
struct V_100 * V_104 ;
struct V_13 * V_119 ;
T_1 V_59 ;
T_3 V_147 ;
V_143 = F_109 ( V_136 ) ;
if ( ! V_143 )
return 0 ;
F_104 ( V_2 , V_136 ) ;
for ( V_147 = 0 ; V_147 < V_145 -> V_148 ; V_147 ++ ) {
V_119 = & V_145 -> V_149 [ V_147 ] ;
F_5 () ;
F_79 (orig_node, head, hash_entry) {
if ( ! F_98 ( V_132 ,
& V_104 -> V_133 ) )
continue;
if ( ! F_98 ( V_132 ,
& V_104 -> V_134 ) ) {
F_105 ( V_136 , L_24 , V_104 -> V_107 ) ;
continue;
}
V_59 = V_104 -> V_116 ;
F_105 ( V_136 , L_25 , V_104 -> V_107 ,
( V_59 & V_62 )
? 'U' : '.' ,
( V_59 & V_63 )
? '4' : '.' ,
( V_59 & V_64 )
? '6' : '.' ) ;
}
F_8 () ;
}
F_110 ( V_143 ) ;
return 0 ;
}
void F_111 ( struct V_1 * V_2 )
{
F_112 ( & V_2 -> V_4 . V_5 ) ;
F_113 ( V_2 , V_73 , 2 ) ;
F_114 ( V_2 , V_73 , 2 ) ;
F_36 ( V_2 , NULL ) ;
}
void F_115 ( struct V_100 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
F_89 ( & V_107 -> V_121 ) ;
if ( ! F_98 ( V_132 , & V_107 -> V_134 ) &&
F_98 ( V_132 , & V_107 -> V_133 ) )
F_93 ( & V_2 -> V_4 . V_96 ) ;
F_86 ( V_2 , V_107 , V_45 ) ;
F_95 ( V_2 , V_107 , V_45 ) ;
F_96 ( V_2 , V_107 , V_45 ) ;
F_92 ( & V_107 -> V_121 ) ;
}
