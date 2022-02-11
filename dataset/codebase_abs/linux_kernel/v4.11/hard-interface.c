void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( V_4 , V_7 ) ;
}
struct V_3 *
F_5 ( const struct V_8 * V_6 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_6 == V_6 &&
F_8 ( & V_4 -> V_5 ) )
goto V_9;
}
V_4 = NULL ;
V_9:
F_9 () ;
return V_4 ;
}
static struct V_10 * F_10 ( const struct V_8 * V_11 ,
struct V_10 * V_12 )
{
if ( ! V_11 -> V_13 )
return V_12 ;
if ( ! V_11 -> V_13 -> V_14 )
return V_12 ;
return V_11 -> V_13 -> V_14 ( V_11 ) ;
}
static bool F_11 ( const struct V_8 * V_15 ,
struct V_10 * V_16 ,
const struct V_8 * V_17 ,
struct V_10 * V_18 )
{
int V_19 = F_12 ( V_15 ) ;
int V_20 = F_12 ( V_17 ) ;
const struct V_10 * V_21 ;
const struct V_10 * V_22 ;
V_21 = F_10 ( V_15 , V_16 ) ;
V_22 = F_10 ( V_17 , V_18 ) ;
if ( ! V_19 || ! V_20 )
return false ;
return ( V_19 == V_17 -> V_23 ) &&
( V_20 == V_15 -> V_23 ) &&
F_13 ( V_21 , V_18 ) &&
F_13 ( V_22 , V_16 ) ;
}
static bool F_14 ( const struct V_8 * V_6 )
{
struct V_10 * V_10 = F_15 ( V_6 ) ;
struct V_8 * V_24 ;
struct V_10 * V_25 ;
bool V_26 ;
if ( F_16 ( V_6 ) )
return true ;
if ( F_12 ( V_6 ) == 0 ||
F_12 ( V_6 ) == V_6 -> V_23 )
return false ;
V_25 = F_10 ( V_6 , V_10 ) ;
V_24 = F_17 ( (struct V_10 * ) V_25 ,
F_12 ( V_6 ) ) ;
if ( F_18 ( ! V_24 , L_1 ) )
return false ;
if ( F_11 ( V_6 , V_10 , V_24 , V_25 ) )
return false ;
V_26 = F_14 ( V_24 ) ;
return V_26 ;
}
static bool F_19 ( const struct V_8 * V_6 )
{
if ( V_6 -> V_27 & V_28 )
return false ;
if ( V_6 -> type != V_29 )
return false ;
if ( V_6 -> V_30 != V_31 )
return false ;
if ( F_14 ( V_6 ) )
return false ;
return true ;
}
static struct V_8 * F_20 ( struct V_8 * V_11 )
{
struct V_3 * V_4 = NULL ;
struct V_8 * V_32 = NULL ;
struct V_10 * V_33 ;
struct V_10 * V_10 ;
int V_23 ;
F_21 () ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_23 == F_12 ( V_11 ) ) {
F_22 ( V_11 ) ;
return V_11 ;
}
V_4 = F_5 ( V_11 ) ;
if ( ! V_4 || ! V_4 -> V_34 )
goto V_9;
V_10 = F_15 ( V_4 -> V_34 ) ;
V_23 = F_12 ( V_11 ) ;
V_33 = F_10 ( V_11 , V_10 ) ;
V_32 = F_23 ( V_33 , V_23 ) ;
V_9:
if ( V_4 )
F_24 ( V_4 ) ;
return V_32 ;
}
struct V_8 * F_25 ( struct V_8 * V_8 )
{
struct V_8 * V_32 ;
F_26 () ;
V_32 = F_20 ( V_8 ) ;
F_27 () ;
return V_32 ;
}
static bool F_28 ( struct V_8 * V_8 )
{
if ( ! V_8 )
return false ;
#ifdef F_29
if ( V_8 -> V_35 )
return true ;
#endif
return false ;
}
static bool F_30 ( struct V_8 * V_8 )
{
if ( ! V_8 )
return false ;
if ( V_8 -> V_36 )
return true ;
return false ;
}
static T_1 F_31 ( struct V_8 * V_8 )
{
T_1 V_37 = 0 ;
struct V_8 * V_32 ;
if ( F_28 ( V_8 ) )
V_37 |= V_38 ;
if ( F_30 ( V_8 ) )
V_37 |= V_39 ;
V_32 = F_20 ( V_8 ) ;
if ( ! V_32 )
return V_37 ;
if ( V_32 == V_8 )
goto V_9;
if ( F_28 ( V_32 ) )
V_37 |= V_40 ;
if ( F_30 ( V_32 ) )
V_37 |= V_41 ;
V_9:
F_3 ( V_32 ) ;
return V_37 ;
}
bool F_32 ( struct V_3 * V_4 )
{
T_1 V_42 = 0 ;
V_42 |= V_39 ;
V_42 |= V_41 ;
return ! ! ( V_4 -> V_37 & V_42 ) ;
}
bool F_33 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return false ;
return V_4 -> V_37 != 0 ;
}
int F_34 ( struct V_3 * V_43 ,
T_2 * V_44 , T_2 * V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_26 = V_50 ;
F_6 () ;
V_49 = F_35 ( F_36 ( & V_43 -> V_51 ) ) ;
if ( ! V_49 ) {
V_26 = V_52 ;
goto V_9;
}
if ( F_35 ( F_37 ( V_49 ) ) )
goto V_9;
V_47 = F_38 ( V_49 , struct V_46 ,
V_53 ) ;
if ( V_44 && F_39 ( V_47 -> V_54 , V_44 ) ) {
V_26 = V_55 ;
} else if ( V_45 &&
F_39 ( V_47 -> V_54 , V_45 ) ) {
V_26 = V_56 ;
}
V_9:
F_9 () ;
return V_26 ;
}
static struct V_3 *
F_40 ( const struct V_8 * V_34 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_34 != V_34 )
continue;
if ( V_4 -> V_57 == V_58 &&
F_8 ( & V_4 -> V_5 ) )
goto V_9;
}
V_4 = NULL ;
V_9:
F_9 () ;
return V_4 ;
}
static void F_41 ( struct V_59 * V_60 ,
struct V_3 * V_61 )
{
struct V_3 * V_62 ;
V_62 = F_42 ( V_60 ) ;
if ( ! V_62 )
goto V_9;
F_43 ( V_60 , V_62 ) ;
F_44 ( V_60 , V_62 , V_61 ) ;
V_9:
if ( V_62 )
F_24 ( V_62 ) ;
}
static void F_45 ( struct V_59 * V_60 ,
struct V_3 * V_63 )
{
struct V_3 * V_64 ;
F_21 () ;
if ( V_63 )
F_46 ( & V_63 -> V_5 ) ;
V_64 = F_47 ( V_60 -> V_62 , 1 ) ;
F_48 ( V_60 -> V_62 , V_63 ) ;
if ( ! V_63 )
goto V_9;
V_60 -> V_65 -> V_66 . V_67 ( V_63 ) ;
F_41 ( V_60 , V_64 ) ;
V_9:
if ( V_64 )
F_24 ( V_64 ) ;
}
static bool
F_49 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_6 -> V_27 & V_68 )
return true ;
return false ;
}
static void F_50 ( const struct V_8 * V_6 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_57 != V_58 ) &&
( V_4 -> V_57 != V_69 ) )
continue;
if ( V_4 -> V_6 == V_6 )
continue;
if ( ! F_39 ( V_4 -> V_6 -> V_70 ,
V_6 -> V_70 ) )
continue;
F_51 ( L_2 ,
V_6 -> V_70 , V_4 -> V_6 -> V_71 ) ;
F_51 ( L_3 ) ;
}
F_9 () ;
}
static void F_52 ( struct V_8 * V_34 )
{
const struct V_3 * V_4 ;
unsigned short V_72 = V_73 ;
unsigned short V_74 = 0 ;
unsigned short V_75 = 0 ;
unsigned short V_76 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_57 == V_77 )
continue;
if ( V_4 -> V_34 != V_34 )
continue;
V_72 = F_53 (unsigned short, lower_header_len,
hard_iface->net_dev->hard_header_len) ;
V_74 = F_53 (unsigned short, lower_headroom,
hard_iface->net_dev->needed_headroom) ;
V_75 = F_53 (unsigned short, lower_tailroom,
hard_iface->net_dev->needed_tailroom) ;
}
F_9 () ;
V_76 = V_74 + ( V_72 - V_73 ) ;
V_76 += F_54 () ;
V_34 -> V_76 = V_76 ;
V_34 -> V_78 = V_75 ;
}
int F_55 ( struct V_8 * V_34 )
{
struct V_59 * V_60 = F_56 ( V_34 ) ;
const struct V_3 * V_4 ;
int V_79 = V_80 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_57 != V_58 ) &&
( V_4 -> V_57 != V_69 ) )
continue;
if ( V_4 -> V_34 != V_34 )
continue;
V_79 = F_57 ( int , V_4 -> V_6 -> V_81 , V_79 ) ;
}
F_9 () ;
if ( F_58 ( & V_60 -> V_82 ) == 0 )
goto V_9;
V_79 = F_57 ( int , V_79 , V_83 ) ;
V_79 -= sizeof( struct V_84 ) ;
V_79 *= V_85 ;
V_9:
F_59 ( & V_60 -> V_86 , V_79 ) ;
return F_57 ( int , V_79 - F_54 () , V_87 ) ;
}
void F_60 ( struct V_8 * V_34 )
{
V_34 -> V_81 = F_55 ( V_34 ) ;
F_61 ( V_34 ) ;
}
static void
F_62 ( struct V_3 * V_4 )
{
struct V_59 * V_60 ;
struct V_3 * V_62 = NULL ;
if ( V_4 -> V_57 != V_88 )
goto V_9;
V_60 = F_56 ( V_4 -> V_34 ) ;
V_60 -> V_65 -> V_66 . V_89 ( V_4 ) ;
V_4 -> V_57 = V_69 ;
V_62 = F_42 ( V_60 ) ;
if ( ! V_62 )
F_45 ( V_60 , V_4 ) ;
F_63 ( V_4 -> V_34 , L_4 ,
V_4 -> V_6 -> V_71 ) ;
F_60 ( V_4 -> V_34 ) ;
if ( V_60 -> V_65 -> V_66 . V_90 )
V_60 -> V_65 -> V_66 . V_90 ( V_4 ) ;
V_9:
if ( V_62 )
F_24 ( V_62 ) ;
}
static void
F_64 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_57 != V_58 ) &&
( V_4 -> V_57 != V_69 ) )
return;
V_4 -> V_57 = V_88 ;
F_63 ( V_4 -> V_34 , L_5 ,
V_4 -> V_6 -> V_71 ) ;
F_60 ( V_4 -> V_34 ) ;
}
static int F_65 ( struct V_3 * V_91 ,
struct V_8 * V_92 )
{
int V_26 ;
if ( ! V_92 )
return 0 ;
V_26 = - V_93 ;
if ( V_92 -> V_94 -> V_95 )
V_26 = V_92 -> V_94 -> V_95 ( V_92 , V_91 -> V_6 ) ;
return V_26 ;
}
int F_66 ( struct V_3 * V_4 ,
struct V_10 * V_10 , const char * V_96 )
{
struct V_59 * V_60 ;
struct V_8 * V_34 , * V_92 ;
T_3 V_97 = F_67 ( V_98 ) ;
int V_99 = F_54 () ;
int V_26 ;
if ( V_4 -> V_57 != V_77 )
goto V_9;
F_46 ( & V_4 -> V_5 ) ;
V_34 = F_68 ( V_10 , V_96 ) ;
if ( ! V_34 ) {
V_34 = F_69 ( V_10 , V_96 ) ;
if ( ! V_34 ) {
V_26 = - V_100 ;
goto V_101;
}
F_22 ( V_34 ) ;
}
if ( ! F_16 ( V_34 ) ) {
F_70 ( L_6 ,
V_34 -> V_71 ) ;
V_26 = - V_102 ;
goto V_103;
}
V_92 = F_71 ( V_4 -> V_6 ) ;
V_26 = F_65 ( V_4 , V_92 ) ;
if ( V_26 )
goto V_103;
V_4 -> V_34 = V_34 ;
V_60 = F_56 ( V_4 -> V_34 ) ;
V_26 = F_72 ( V_4 -> V_6 ,
V_34 , NULL , NULL ) ;
if ( V_26 )
goto V_103;
V_26 = V_60 -> V_65 -> V_66 . V_104 ( V_4 ) ;
if ( V_26 < 0 )
goto V_105;
V_4 -> V_106 = V_60 -> V_107 ;
V_60 -> V_107 ++ ;
V_4 -> V_57 = V_88 ;
V_26 = F_73 ( V_4 , V_60 -> V_107 ) ;
if ( V_26 < 0 ) {
V_60 -> V_65 -> V_66 . V_108 ( V_4 ) ;
V_60 -> V_107 -- ;
V_4 -> V_57 = V_77 ;
goto V_105;
}
F_46 ( & V_4 -> V_5 ) ;
V_4 -> V_109 . type = V_97 ;
V_4 -> V_109 . V_110 = V_111 ;
V_4 -> V_109 . V_112 = V_4 -> V_6 ;
F_74 ( & V_4 -> V_109 ) ;
F_63 ( V_4 -> V_34 , L_7 ,
V_4 -> V_6 -> V_71 ) ;
if ( F_58 ( & V_60 -> V_82 ) &&
V_4 -> V_6 -> V_81 < V_87 + V_99 )
F_63 ( V_4 -> V_34 ,
L_8 ,
V_4 -> V_6 -> V_71 , V_4 -> V_6 -> V_81 ,
V_87 + V_99 ) ;
if ( ! F_58 ( & V_60 -> V_82 ) &&
V_4 -> V_6 -> V_81 < V_87 + V_99 )
F_63 ( V_4 -> V_34 ,
L_9 ,
V_4 -> V_6 -> V_71 , V_4 -> V_6 -> V_81 ,
V_87 + V_99 ) ;
if ( F_49 ( V_4 ) )
F_62 ( V_4 ) ;
else
F_75 ( V_4 -> V_34 ,
L_10 ,
V_4 -> V_6 -> V_71 ) ;
F_52 ( V_34 ) ;
V_9:
return 0 ;
V_105:
F_76 ( V_4 -> V_6 , V_34 ) ;
V_103:
V_4 -> V_34 = NULL ;
F_3 ( V_34 ) ;
V_101:
F_24 ( V_4 ) ;
return V_26 ;
}
void F_77 ( struct V_3 * V_4 ,
enum V_113 V_114 )
{
struct V_59 * V_60 = F_56 ( V_4 -> V_34 ) ;
struct V_3 * V_62 = NULL ;
F_64 ( V_4 ) ;
if ( V_4 -> V_57 != V_88 )
goto V_9;
F_63 ( V_4 -> V_34 , L_11 ,
V_4 -> V_6 -> V_71 ) ;
F_78 ( & V_4 -> V_109 ) ;
F_24 ( V_4 ) ;
V_60 -> V_107 -- ;
F_79 ( V_4 , V_60 -> V_107 ) ;
V_62 = F_42 ( V_60 ) ;
if ( V_4 == V_62 ) {
struct V_3 * V_115 ;
V_115 = F_40 ( V_4 -> V_34 ) ;
F_45 ( V_60 , V_115 ) ;
if ( V_115 )
F_24 ( V_115 ) ;
}
V_60 -> V_65 -> V_66 . V_108 ( V_4 ) ;
V_4 -> V_57 = V_77 ;
F_80 ( V_60 ) ;
F_81 ( V_60 , V_4 ) ;
F_3 ( V_4 -> V_34 ) ;
F_76 ( V_4 -> V_6 , V_4 -> V_34 ) ;
F_52 ( V_4 -> V_34 ) ;
if ( ! V_60 -> V_107 ) {
F_82 ( V_60 ) ;
if ( V_114 == V_116 )
F_83 ( V_4 -> V_34 ) ;
}
V_4 -> V_34 = NULL ;
F_24 ( V_4 ) ;
V_9:
if ( V_62 )
F_24 ( V_62 ) ;
}
static struct V_3 *
F_84 ( struct V_8 * V_6 )
{
struct V_3 * V_4 ;
int V_26 ;
F_21 () ;
if ( ! F_19 ( V_6 ) )
goto V_9;
F_22 ( V_6 ) ;
V_4 = F_85 ( sizeof( * V_4 ) , V_117 ) ;
if ( ! V_4 )
goto V_118;
V_26 = F_86 ( & V_4 -> V_119 , V_6 ) ;
if ( V_26 )
goto V_120;
V_4 -> V_106 = - 1 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_34 = NULL ;
V_4 -> V_57 = V_77 ;
V_26 = F_87 ( V_4 ) ;
if ( V_26 )
goto V_121;
F_88 ( & V_4 -> V_53 ) ;
F_89 ( & V_4 -> V_51 ) ;
F_90 ( & V_4 -> V_122 ) ;
F_91 ( & V_4 -> V_5 ) ;
V_4 -> V_123 = V_124 ;
V_4 -> V_37 = F_31 ( V_6 ) ;
if ( F_33 ( V_4 ) )
V_4 -> V_123 = V_125 ;
F_92 ( V_4 ) ;
F_50 ( V_4 -> V_6 ) ;
F_46 ( & V_4 -> V_5 ) ;
F_93 ( & V_4 -> V_53 , & V_126 ) ;
return V_4 ;
V_121:
F_94 ( & V_4 -> V_119 ) ;
V_120:
F_95 ( V_4 ) ;
V_118:
F_3 ( V_6 ) ;
V_9:
return NULL ;
}
static void F_96 ( struct V_3 * V_4 )
{
F_21 () ;
if ( V_4 -> V_57 != V_77 )
F_77 ( V_4 ,
V_127 ) ;
if ( V_4 -> V_57 != V_77 )
return;
V_4 -> V_57 = V_128 ;
F_97 ( V_4 ) ;
F_94 ( & V_4 -> V_119 ) ;
F_24 ( V_4 ) ;
}
void F_98 ( void )
{
struct V_3 * V_4 , * V_129 ;
F_26 () ;
F_99 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_100 ( & V_4 -> V_53 ) ;
F_96 ( V_4 ) ;
}
F_27 () ;
}
static int F_101 ( struct V_130 * V_131 ,
unsigned long V_132 , void * V_133 )
{
struct V_8 * V_6 = F_102 ( V_133 ) ;
struct V_3 * V_4 ;
struct V_3 * V_62 = NULL ;
struct V_59 * V_60 ;
if ( F_16 ( V_6 ) && V_132 == V_134 ) {
F_103 ( V_6 ) ;
V_60 = F_56 ( V_6 ) ;
F_104 ( V_60 , V_135 ) ;
return V_136 ;
}
V_4 = F_5 ( V_6 ) ;
if ( ! V_4 && ( V_132 == V_134 ||
V_132 == V_137 ) )
V_4 = F_84 ( V_6 ) ;
if ( ! V_4 )
goto V_9;
switch ( V_132 ) {
case V_138 :
F_62 ( V_4 ) ;
break;
case V_139 :
case V_140 :
F_64 ( V_4 ) ;
break;
case V_141 :
case V_142 :
F_100 ( & V_4 -> V_53 ) ;
F_96 ( V_4 ) ;
break;
case V_143 :
if ( V_4 -> V_34 )
F_60 ( V_4 -> V_34 ) ;
break;
case V_144 :
if ( V_4 -> V_57 == V_77 )
goto V_145;
F_50 ( V_4 -> V_6 ) ;
V_60 = F_56 ( V_4 -> V_34 ) ;
V_60 -> V_65 -> V_66 . V_89 ( V_4 ) ;
V_62 = F_42 ( V_60 ) ;
if ( ! V_62 )
goto V_145;
if ( V_4 == V_62 )
F_41 ( V_60 , NULL ) ;
break;
case V_146 :
V_4 -> V_37 = F_31 ( V_6 ) ;
if ( F_33 ( V_4 ) )
V_4 -> V_123 = V_125 ;
break;
default:
break;
}
V_145:
F_24 ( V_4 ) ;
V_9:
if ( V_62 )
F_24 ( V_62 ) ;
return V_136 ;
}
