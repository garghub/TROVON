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
static const struct V_10 * F_10 ( const struct V_8 * V_11 ,
const struct V_10 * V_12 )
{
if ( ! V_11 -> V_13 )
return V_12 ;
if ( ! V_11 -> V_13 -> V_14 )
return V_12 ;
return V_11 -> V_13 -> V_14 ( V_11 ) ;
}
static bool F_11 ( const struct V_8 * V_15 ,
const struct V_10 * V_16 ,
const struct V_8 * V_17 ,
const struct V_10 * V_18 )
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
const struct V_10 * V_25 ;
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
bool F_20 ( struct V_8 * V_8 )
{
if ( ! V_8 )
return false ;
#ifdef F_21
if ( V_8 -> V_32 )
return true ;
#endif
if ( V_8 -> V_33 )
return true ;
return false ;
}
static struct V_3 *
F_22 ( const struct V_8 * V_34 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_34 != V_34 )
continue;
if ( V_4 -> V_35 == V_36 &&
F_8 ( & V_4 -> V_5 ) )
goto V_9;
}
V_4 = NULL ;
V_9:
F_9 () ;
return V_4 ;
}
static void F_23 ( struct V_37 * V_38 ,
struct V_3 * V_39 )
{
struct V_3 * V_40 ;
V_40 = F_24 ( V_38 ) ;
if ( ! V_40 )
goto V_9;
F_25 ( V_38 , V_40 ) ;
F_26 ( V_38 , V_40 , V_39 ) ;
V_9:
if ( V_40 )
F_27 ( V_40 ) ;
}
static void F_28 ( struct V_37 * V_38 ,
struct V_3 * V_41 )
{
struct V_3 * V_42 ;
F_29 () ;
if ( V_41 )
F_30 ( & V_41 -> V_5 ) ;
V_42 = F_31 ( V_38 -> V_40 , 1 ) ;
F_32 ( V_38 -> V_40 , V_41 ) ;
if ( ! V_41 )
goto V_9;
V_38 -> V_43 -> V_44 . V_45 ( V_41 ) ;
F_23 ( V_38 , V_42 ) ;
V_9:
if ( V_42 )
F_27 ( V_42 ) ;
}
static bool
F_33 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_6 -> V_27 & V_46 )
return true ;
return false ;
}
static void F_34 ( const struct V_8 * V_6 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_35 != V_36 ) &&
( V_4 -> V_35 != V_47 ) )
continue;
if ( V_4 -> V_6 == V_6 )
continue;
if ( ! F_35 ( V_4 -> V_6 -> V_48 ,
V_6 -> V_48 ) )
continue;
F_36 ( L_2 ,
V_6 -> V_48 , V_4 -> V_6 -> V_49 ) ;
F_36 ( L_3 ) ;
}
F_9 () ;
}
static void F_37 ( struct V_8 * V_34 )
{
const struct V_3 * V_4 ;
unsigned short V_50 = V_51 ;
unsigned short V_52 = 0 ;
unsigned short V_53 = 0 ;
unsigned short V_54 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_35 == V_55 )
continue;
if ( V_4 -> V_34 != V_34 )
continue;
V_50 = F_38 (unsigned short, lower_header_len,
hard_iface->net_dev->hard_header_len) ;
V_52 = F_38 (unsigned short, lower_headroom,
hard_iface->net_dev->needed_headroom) ;
V_53 = F_38 (unsigned short, lower_tailroom,
hard_iface->net_dev->needed_tailroom) ;
}
F_9 () ;
V_54 = V_52 + ( V_50 - V_51 ) ;
V_54 += F_39 () ;
V_34 -> V_54 = V_54 ;
V_34 -> V_56 = V_53 ;
}
int F_40 ( struct V_8 * V_34 )
{
struct V_37 * V_38 = F_41 ( V_34 ) ;
const struct V_3 * V_4 ;
int V_57 = V_58 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_35 != V_36 ) &&
( V_4 -> V_35 != V_47 ) )
continue;
if ( V_4 -> V_34 != V_34 )
continue;
V_57 = F_42 ( int , V_4 -> V_6 -> V_59 , V_57 ) ;
}
F_9 () ;
if ( F_43 ( & V_38 -> V_60 ) == 0 )
goto V_9;
V_57 = F_42 ( int , V_57 , V_61 ) ;
V_57 -= sizeof( struct V_62 ) ;
V_57 *= V_63 ;
V_9:
F_44 ( & V_38 -> V_64 , V_57 ) ;
return F_42 ( int , V_57 - F_39 () , V_65 ) ;
}
void F_45 ( struct V_8 * V_34 )
{
V_34 -> V_59 = F_40 ( V_34 ) ;
F_46 ( V_34 ) ;
}
static void
F_47 ( struct V_3 * V_4 )
{
struct V_37 * V_38 ;
struct V_3 * V_40 = NULL ;
if ( V_4 -> V_35 != V_66 )
goto V_9;
V_38 = F_41 ( V_4 -> V_34 ) ;
V_38 -> V_43 -> V_44 . V_67 ( V_4 ) ;
V_4 -> V_35 = V_47 ;
V_40 = F_24 ( V_38 ) ;
if ( ! V_40 )
F_28 ( V_38 , V_4 ) ;
F_48 ( V_4 -> V_34 , L_4 ,
V_4 -> V_6 -> V_49 ) ;
F_45 ( V_4 -> V_34 ) ;
if ( V_38 -> V_43 -> V_44 . V_68 )
V_38 -> V_43 -> V_44 . V_68 ( V_4 ) ;
V_9:
if ( V_40 )
F_27 ( V_40 ) ;
}
static void
F_49 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_35 != V_36 ) &&
( V_4 -> V_35 != V_47 ) )
return;
V_4 -> V_35 = V_66 ;
F_48 ( V_4 -> V_34 , L_5 ,
V_4 -> V_6 -> V_49 ) ;
F_45 ( V_4 -> V_34 ) ;
}
static int F_50 ( struct V_3 * V_69 ,
struct V_8 * V_70 )
{
int V_26 ;
if ( ! V_70 )
return 0 ;
V_26 = - V_71 ;
if ( V_70 -> V_72 -> V_73 )
V_26 = V_70 -> V_72 -> V_73 ( V_70 , V_69 -> V_6 ) ;
return V_26 ;
}
int F_51 ( struct V_3 * V_4 ,
struct V_10 * V_10 , const char * V_74 )
{
struct V_37 * V_38 ;
struct V_8 * V_34 , * V_70 ;
T_1 V_75 = F_52 ( V_76 ) ;
int V_77 = F_39 () ;
int V_26 ;
if ( V_4 -> V_35 != V_55 )
goto V_9;
F_30 ( & V_4 -> V_5 ) ;
V_34 = F_53 ( V_10 , V_74 ) ;
if ( ! V_34 ) {
V_34 = F_54 ( V_10 , V_74 ) ;
if ( ! V_34 ) {
V_26 = - V_78 ;
goto V_79;
}
F_55 ( V_34 ) ;
}
if ( ! F_16 ( V_34 ) ) {
F_56 ( L_6 ,
V_34 -> V_49 ) ;
V_26 = - V_80 ;
goto V_81;
}
V_70 = F_57 ( V_4 -> V_6 ) ;
V_26 = F_50 ( V_4 , V_70 ) ;
if ( V_26 )
goto V_81;
V_4 -> V_34 = V_34 ;
V_38 = F_41 ( V_4 -> V_34 ) ;
V_26 = F_58 ( V_4 -> V_6 ,
V_34 , NULL , NULL ) ;
if ( V_26 )
goto V_81;
V_26 = V_38 -> V_43 -> V_44 . V_82 ( V_4 ) ;
if ( V_26 < 0 )
goto V_83;
V_4 -> V_84 = V_38 -> V_85 ;
V_38 -> V_85 ++ ;
V_4 -> V_35 = V_66 ;
V_26 = F_59 ( V_4 , V_38 -> V_85 ) ;
if ( V_26 < 0 ) {
V_38 -> V_43 -> V_44 . V_86 ( V_4 ) ;
V_38 -> V_85 -- ;
V_4 -> V_35 = V_55 ;
goto V_83;
}
F_30 ( & V_4 -> V_5 ) ;
V_4 -> V_87 . type = V_75 ;
V_4 -> V_87 . V_88 = V_89 ;
V_4 -> V_87 . V_90 = V_4 -> V_6 ;
F_60 ( & V_4 -> V_87 ) ;
F_48 ( V_4 -> V_34 , L_7 ,
V_4 -> V_6 -> V_49 ) ;
if ( F_43 ( & V_38 -> V_60 ) &&
V_4 -> V_6 -> V_59 < V_65 + V_77 )
F_48 ( V_4 -> V_34 ,
L_8 ,
V_4 -> V_6 -> V_49 , V_4 -> V_6 -> V_59 ,
V_65 + V_77 ) ;
if ( ! F_43 ( & V_38 -> V_60 ) &&
V_4 -> V_6 -> V_59 < V_65 + V_77 )
F_48 ( V_4 -> V_34 ,
L_9 ,
V_4 -> V_6 -> V_49 , V_4 -> V_6 -> V_59 ,
V_65 + V_77 ) ;
if ( F_33 ( V_4 ) )
F_47 ( V_4 ) ;
else
F_61 ( V_4 -> V_34 ,
L_10 ,
V_4 -> V_6 -> V_49 ) ;
F_37 ( V_34 ) ;
V_9:
return 0 ;
V_83:
F_62 ( V_4 -> V_6 , V_34 ) ;
V_81:
V_4 -> V_34 = NULL ;
F_3 ( V_34 ) ;
V_79:
F_27 ( V_4 ) ;
return V_26 ;
}
void F_63 ( struct V_3 * V_4 ,
enum V_91 V_92 )
{
struct V_37 * V_38 = F_41 ( V_4 -> V_34 ) ;
struct V_3 * V_40 = NULL ;
F_49 ( V_4 ) ;
if ( V_4 -> V_35 != V_66 )
goto V_9;
F_48 ( V_4 -> V_34 , L_11 ,
V_4 -> V_6 -> V_49 ) ;
F_64 ( & V_4 -> V_87 ) ;
F_27 ( V_4 ) ;
V_38 -> V_85 -- ;
F_65 ( V_4 , V_38 -> V_85 ) ;
V_40 = F_24 ( V_38 ) ;
if ( V_4 == V_40 ) {
struct V_3 * V_93 ;
V_93 = F_22 ( V_4 -> V_34 ) ;
F_28 ( V_38 , V_93 ) ;
if ( V_93 )
F_27 ( V_93 ) ;
}
V_38 -> V_43 -> V_44 . V_86 ( V_4 ) ;
V_4 -> V_35 = V_55 ;
F_66 ( V_38 ) ;
F_67 ( V_38 , V_4 ) ;
F_3 ( V_4 -> V_34 ) ;
F_62 ( V_4 -> V_6 , V_4 -> V_34 ) ;
F_37 ( V_4 -> V_34 ) ;
if ( ! V_38 -> V_85 ) {
F_68 ( V_38 ) ;
if ( V_92 == V_94 )
F_69 ( V_4 -> V_34 ) ;
}
V_4 -> V_34 = NULL ;
F_27 ( V_4 ) ;
V_9:
if ( V_40 )
F_27 ( V_40 ) ;
}
static struct V_3 *
F_70 ( struct V_8 * V_6 )
{
struct V_3 * V_4 ;
int V_26 ;
F_29 () ;
if ( ! F_19 ( V_6 ) )
goto V_9;
F_55 ( V_6 ) ;
V_4 = F_71 ( sizeof( * V_4 ) , V_95 ) ;
if ( ! V_4 )
goto V_96;
V_26 = F_72 ( & V_4 -> V_97 , V_6 ) ;
if ( V_26 )
goto V_98;
V_4 -> V_84 = - 1 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_34 = NULL ;
V_4 -> V_35 = V_55 ;
V_26 = F_73 ( V_4 ) ;
if ( V_26 )
goto V_99;
F_74 ( & V_4 -> V_100 ) ;
F_75 ( & V_4 -> V_101 ) ;
F_76 ( & V_4 -> V_102 ) ;
F_77 ( & V_4 -> V_5 ) ;
V_4 -> V_103 = V_104 ;
if ( F_20 ( V_6 ) )
V_4 -> V_103 = V_105 ;
F_78 ( V_4 ) ;
F_34 ( V_4 -> V_6 ) ;
F_30 ( & V_4 -> V_5 ) ;
F_79 ( & V_4 -> V_100 , & V_106 ) ;
return V_4 ;
V_99:
F_80 ( & V_4 -> V_97 ) ;
V_98:
F_81 ( V_4 ) ;
V_96:
F_3 ( V_6 ) ;
V_9:
return NULL ;
}
static void F_82 ( struct V_3 * V_4 )
{
F_29 () ;
if ( V_4 -> V_35 != V_55 )
F_63 ( V_4 ,
V_107 ) ;
if ( V_4 -> V_35 != V_55 )
return;
V_4 -> V_35 = V_108 ;
F_83 ( V_4 ) ;
F_80 ( & V_4 -> V_97 ) ;
F_27 ( V_4 ) ;
}
void F_84 ( void )
{
struct V_3 * V_4 , * V_109 ;
F_85 () ;
F_86 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_87 ( & V_4 -> V_100 ) ;
F_82 ( V_4 ) ;
}
F_88 () ;
}
static int F_89 ( struct V_110 * V_111 ,
unsigned long V_112 , void * V_113 )
{
struct V_8 * V_6 = F_90 ( V_113 ) ;
struct V_3 * V_4 ;
struct V_3 * V_40 = NULL ;
struct V_37 * V_38 ;
if ( F_16 ( V_6 ) && V_112 == V_114 ) {
F_91 ( V_6 ) ;
V_38 = F_41 ( V_6 ) ;
F_92 ( V_38 , V_115 ) ;
return V_116 ;
}
V_4 = F_5 ( V_6 ) ;
if ( ! V_4 && ( V_112 == V_114 ||
V_112 == V_117 ) )
V_4 = F_70 ( V_6 ) ;
if ( ! V_4 )
goto V_9;
switch ( V_112 ) {
case V_118 :
F_47 ( V_4 ) ;
break;
case V_119 :
case V_120 :
F_49 ( V_4 ) ;
break;
case V_121 :
case V_122 :
F_87 ( & V_4 -> V_100 ) ;
F_82 ( V_4 ) ;
break;
case V_123 :
if ( V_4 -> V_34 )
F_45 ( V_4 -> V_34 ) ;
break;
case V_124 :
if ( V_4 -> V_35 == V_55 )
goto V_125;
F_34 ( V_4 -> V_6 ) ;
V_38 = F_41 ( V_4 -> V_34 ) ;
V_38 -> V_43 -> V_44 . V_67 ( V_4 ) ;
V_40 = F_24 ( V_38 ) ;
if ( ! V_40 )
goto V_125;
if ( V_4 == V_40 )
F_23 ( V_38 , NULL ) ;
break;
default:
break;
}
V_125:
F_27 ( V_4 ) ;
V_9:
if ( V_40 )
F_27 ( V_40 ) ;
return V_116 ;
}
