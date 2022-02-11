void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
}
struct V_3 *
F_5 ( const struct V_6 * V_5 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_5 == V_5 &&
F_8 ( & V_4 -> V_7 ) )
goto V_8;
}
V_4 = NULL ;
V_8:
F_9 () ;
return V_4 ;
}
static bool F_10 ( const struct V_6 * V_9 ,
const struct V_6 * V_10 )
{
int V_11 = F_11 ( V_9 ) ;
int V_12 = F_11 ( V_10 ) ;
if ( ! V_11 || ! V_12 )
return false ;
return ( V_11 == V_10 -> V_13 ) &&
( V_12 == V_9 -> V_13 ) ;
}
static bool F_12 ( const struct V_6 * V_5 )
{
struct V_6 * V_14 ;
bool V_15 ;
if ( F_13 ( V_5 ) )
return true ;
if ( F_11 ( V_5 ) == 0 ||
F_11 ( V_5 ) == V_5 -> V_13 )
return false ;
V_14 = F_14 ( & V_16 , F_11 ( V_5 ) ) ;
if ( F_15 ( ! V_14 , L_1 ) )
return false ;
if ( F_10 ( V_5 , V_14 ) )
return false ;
V_15 = F_12 ( V_14 ) ;
return V_15 ;
}
static int F_16 ( const struct V_6 * V_5 )
{
if ( V_5 -> V_17 & V_18 )
return 0 ;
if ( V_5 -> type != V_19 )
return 0 ;
if ( V_5 -> V_20 != V_21 )
return 0 ;
if ( F_12 ( V_5 ) )
return 0 ;
return 1 ;
}
bool F_17 ( struct V_6 * V_6 )
{
if ( ! V_6 )
return false ;
#ifdef F_18
if ( V_6 -> V_22 )
return true ;
#endif
if ( V_6 -> V_23 )
return true ;
return false ;
}
static struct V_3 *
F_19 ( const struct V_6 * V_24 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_24 != V_24 )
continue;
if ( V_4 -> V_25 == V_26 &&
F_8 ( & V_4 -> V_7 ) )
goto V_8;
}
V_4 = NULL ;
V_8:
F_9 () ;
return V_4 ;
}
static void F_20 ( struct V_27 * V_28 ,
struct V_3 * V_29 )
{
struct V_3 * V_30 ;
V_30 = F_21 ( V_28 ) ;
if ( ! V_30 )
goto V_8;
F_22 ( V_28 , V_30 ) ;
F_23 ( V_28 , V_30 , V_29 ) ;
V_8:
if ( V_30 )
F_24 ( V_30 ) ;
}
static void F_25 ( struct V_27 * V_28 ,
struct V_3 * V_31 )
{
struct V_3 * V_32 ;
F_26 () ;
if ( V_31 && ! F_8 ( & V_31 -> V_7 ) )
V_31 = NULL ;
V_32 = F_27 ( V_28 -> V_30 , 1 ) ;
F_28 ( V_28 -> V_30 , V_31 ) ;
if ( ! V_31 )
goto V_8;
V_28 -> V_33 -> V_34 ( V_31 ) ;
F_20 ( V_28 , V_32 ) ;
V_8:
if ( V_32 )
F_24 ( V_32 ) ;
}
static bool
F_29 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_17 & V_35 )
return true ;
return false ;
}
static void F_30 ( const struct V_6 * V_5 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_25 != V_26 ) &&
( V_4 -> V_25 != V_36 ) )
continue;
if ( V_4 -> V_5 == V_5 )
continue;
if ( ! F_31 ( V_4 -> V_5 -> V_37 ,
V_5 -> V_37 ) )
continue;
F_32 ( L_2 ,
V_5 -> V_37 , V_4 -> V_5 -> V_38 ) ;
F_32 ( L_3 ) ;
}
F_9 () ;
}
static void F_33 ( struct V_6 * V_24 )
{
const struct V_3 * V_4 ;
unsigned short V_39 = V_40 ;
unsigned short V_41 = 0 ;
unsigned short V_42 = 0 ;
unsigned short V_43 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_25 == V_44 )
continue;
if ( V_4 -> V_24 != V_24 )
continue;
V_39 = F_34 (unsigned short, lower_header_len,
hard_iface->net_dev->hard_header_len) ;
V_41 = F_34 (unsigned short, lower_headroom,
hard_iface->net_dev->needed_headroom) ;
V_42 = F_34 (unsigned short, lower_tailroom,
hard_iface->net_dev->needed_tailroom) ;
}
F_9 () ;
V_43 = V_41 + ( V_39 - V_40 ) ;
V_43 += F_35 () ;
V_24 -> V_43 = V_43 ;
V_24 -> V_45 = V_42 ;
}
int F_36 ( struct V_6 * V_24 )
{
struct V_27 * V_28 = F_37 ( V_24 ) ;
const struct V_3 * V_4 ;
int V_46 = V_47 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_25 != V_26 ) &&
( V_4 -> V_25 != V_36 ) )
continue;
if ( V_4 -> V_24 != V_24 )
continue;
V_46 = F_38 ( int , V_4 -> V_5 -> V_48 , V_46 ) ;
}
F_9 () ;
if ( F_39 ( & V_28 -> V_49 ) == 0 )
goto V_8;
V_46 = F_38 ( int , V_46 , V_50 ) ;
V_46 -= sizeof( struct V_51 ) ;
V_46 *= V_52 ;
V_8:
F_40 ( & V_28 -> V_53 , V_46 ) ;
return F_38 ( int , V_46 - F_35 () , V_54 ) ;
}
void F_41 ( struct V_6 * V_24 )
{
V_24 -> V_48 = F_36 ( V_24 ) ;
F_42 ( V_24 ) ;
}
static void
F_43 ( struct V_3 * V_4 )
{
struct V_27 * V_28 ;
struct V_3 * V_30 = NULL ;
if ( V_4 -> V_25 != V_55 )
goto V_8;
V_28 = F_37 ( V_4 -> V_24 ) ;
V_28 -> V_33 -> V_56 ( V_4 ) ;
V_4 -> V_25 = V_36 ;
V_30 = F_21 ( V_28 ) ;
if ( ! V_30 )
F_25 ( V_28 , V_4 ) ;
F_44 ( V_4 -> V_24 , L_4 ,
V_4 -> V_5 -> V_38 ) ;
F_41 ( V_4 -> V_24 ) ;
V_8:
if ( V_30 )
F_24 ( V_30 ) ;
}
static void
F_45 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_25 != V_26 ) &&
( V_4 -> V_25 != V_36 ) )
return;
V_4 -> V_25 = V_55 ;
F_44 ( V_4 -> V_24 , L_5 ,
V_4 -> V_5 -> V_38 ) ;
F_41 ( V_4 -> V_24 ) ;
}
static int F_46 ( struct V_3 * V_57 ,
struct V_6 * V_58 )
{
int V_15 ;
if ( ! V_58 )
return 0 ;
V_15 = - V_59 ;
if ( V_58 -> V_60 -> V_61 )
V_15 = V_58 -> V_60 -> V_61 ( V_58 , V_57 -> V_5 ) ;
return V_15 ;
}
int F_47 ( struct V_3 * V_4 ,
const char * V_62 )
{
struct V_27 * V_28 ;
struct V_6 * V_24 , * V_58 ;
T_1 V_63 = F_48 ( V_64 ) ;
int V_65 = F_35 () ;
int V_15 ;
if ( V_4 -> V_25 != V_44 )
goto V_8;
if ( ! F_8 ( & V_4 -> V_7 ) )
goto V_8;
V_24 = F_49 ( & V_16 , V_62 ) ;
if ( ! V_24 ) {
V_24 = F_50 ( V_62 ) ;
if ( ! V_24 ) {
V_15 = - V_66 ;
goto V_67;
}
F_51 ( V_24 ) ;
}
if ( ! F_13 ( V_24 ) ) {
F_52 ( L_6 ,
V_24 -> V_38 ) ;
V_15 = - V_68 ;
goto V_69;
}
V_58 = F_53 ( V_4 -> V_5 ) ;
V_15 = F_46 ( V_4 , V_58 ) ;
if ( V_15 )
goto V_69;
V_4 -> V_24 = V_24 ;
V_28 = F_37 ( V_4 -> V_24 ) ;
V_15 = F_54 ( V_4 -> V_5 ,
V_24 , NULL , NULL ) ;
if ( V_15 )
goto V_69;
V_15 = V_28 -> V_33 -> V_70 ( V_4 ) ;
if ( V_15 < 0 )
goto V_71;
V_4 -> V_72 = V_28 -> V_73 ;
V_28 -> V_73 ++ ;
V_4 -> V_25 = V_55 ;
V_15 = F_55 ( V_4 , V_28 -> V_73 ) ;
if ( V_15 < 0 ) {
V_28 -> V_33 -> V_74 ( V_4 ) ;
V_28 -> V_73 -- ;
V_4 -> V_25 = V_44 ;
goto V_71;
}
V_4 -> V_75 . type = V_63 ;
V_4 -> V_75 . V_76 = V_77 ;
V_4 -> V_75 . V_78 = V_4 -> V_5 ;
F_56 ( & V_4 -> V_75 ) ;
F_44 ( V_4 -> V_24 , L_7 ,
V_4 -> V_5 -> V_38 ) ;
if ( F_39 ( & V_28 -> V_49 ) &&
V_4 -> V_5 -> V_48 < V_54 + V_65 )
F_44 ( V_4 -> V_24 ,
L_8 ,
V_4 -> V_5 -> V_38 , V_4 -> V_5 -> V_48 ,
V_54 + V_65 ) ;
if ( ! F_39 ( & V_28 -> V_49 ) &&
V_4 -> V_5 -> V_48 < V_54 + V_65 )
F_44 ( V_4 -> V_24 ,
L_9 ,
V_4 -> V_5 -> V_38 , V_4 -> V_5 -> V_48 ,
V_54 + V_65 ) ;
if ( F_29 ( V_4 ) )
F_43 ( V_4 ) ;
else
F_57 ( V_4 -> V_24 ,
L_10 ,
V_4 -> V_5 -> V_38 ) ;
F_33 ( V_24 ) ;
F_58 ( V_4 ) ;
V_8:
return 0 ;
V_71:
F_59 ( V_4 -> V_5 , V_24 ) ;
V_69:
V_4 -> V_24 = NULL ;
F_3 ( V_24 ) ;
V_67:
F_24 ( V_4 ) ;
return V_15 ;
}
void F_60 ( struct V_3 * V_4 ,
enum V_79 V_80 )
{
struct V_27 * V_28 = F_37 ( V_4 -> V_24 ) ;
struct V_3 * V_30 = NULL ;
if ( V_4 -> V_25 == V_26 )
F_45 ( V_4 ) ;
if ( V_4 -> V_25 != V_55 )
goto V_8;
F_44 ( V_4 -> V_24 , L_11 ,
V_4 -> V_5 -> V_38 ) ;
F_61 ( & V_4 -> V_75 ) ;
V_28 -> V_73 -- ;
F_62 ( V_4 , V_28 -> V_73 ) ;
V_30 = F_21 ( V_28 ) ;
if ( V_4 == V_30 ) {
struct V_3 * V_81 ;
V_81 = F_19 ( V_4 -> V_24 ) ;
F_25 ( V_28 , V_81 ) ;
if ( V_81 )
F_24 ( V_81 ) ;
}
V_28 -> V_33 -> V_74 ( V_4 ) ;
V_4 -> V_25 = V_44 ;
F_63 ( V_28 ) ;
F_64 ( V_28 , V_4 ) ;
F_3 ( V_4 -> V_24 ) ;
F_59 ( V_4 -> V_5 , V_4 -> V_24 ) ;
F_33 ( V_4 -> V_24 ) ;
if ( ! V_28 -> V_73 ) {
F_65 ( V_28 ) ;
if ( V_80 == V_82 )
F_66 ( V_4 -> V_24 ) ;
}
V_4 -> V_24 = NULL ;
F_24 ( V_4 ) ;
V_8:
if ( V_30 )
F_24 ( V_30 ) ;
}
static void F_67 ( struct V_83 * V_84 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_84 , struct V_3 ,
V_85 ) ;
F_68 ( V_4 ) ;
F_69 ( & V_4 -> V_86 ) ;
F_24 ( V_4 ) ;
}
static struct V_3 *
F_70 ( struct V_6 * V_5 )
{
struct V_3 * V_4 ;
int V_15 ;
F_26 () ;
V_15 = F_16 ( V_5 ) ;
if ( V_15 != 1 )
goto V_8;
F_51 ( V_5 ) ;
V_4 = F_71 ( sizeof( * V_4 ) , V_87 ) ;
if ( ! V_4 )
goto V_88;
V_15 = F_72 ( & V_4 -> V_86 , V_5 ) ;
if ( V_15 )
goto V_89;
V_4 -> V_72 = - 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_24 = NULL ;
V_4 -> V_25 = V_44 ;
V_15 = F_73 ( V_4 ) ;
if ( V_15 )
goto V_90;
F_74 ( & V_4 -> V_91 ) ;
F_75 ( & V_4 -> V_92 ) ;
F_76 ( & V_4 -> V_85 ,
F_67 ) ;
F_77 ( & V_4 -> V_93 ) ;
V_4 -> V_94 = V_95 ;
if ( F_17 ( V_5 ) )
V_4 -> V_94 = V_96 ;
F_40 ( & V_4 -> V_7 , 2 ) ;
F_30 ( V_4 -> V_5 ) ;
F_78 ( & V_4 -> V_91 , & V_97 ) ;
return V_4 ;
V_90:
F_69 ( & V_4 -> V_86 ) ;
V_89:
F_4 ( V_4 ) ;
V_88:
F_3 ( V_5 ) ;
V_8:
return NULL ;
}
static void F_79 ( struct V_3 * V_4 )
{
F_26 () ;
if ( V_4 -> V_25 != V_44 )
F_60 ( V_4 ,
V_82 ) ;
if ( V_4 -> V_25 != V_44 )
return;
V_4 -> V_25 = V_98 ;
F_80 ( V_99 , & V_4 -> V_85 ) ;
}
void F_81 ( void )
{
struct V_3 * V_4 , * V_100 ;
F_82 () ;
F_83 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_84 ( & V_4 -> V_91 ) ;
F_79 ( V_4 ) ;
}
F_85 () ;
}
static int F_86 ( struct V_101 * V_102 ,
unsigned long V_103 , void * V_104 )
{
struct V_6 * V_5 = F_87 ( V_104 ) ;
struct V_3 * V_4 ;
struct V_3 * V_30 = NULL ;
struct V_27 * V_28 ;
if ( F_13 ( V_5 ) && V_103 == V_105 ) {
F_88 ( V_5 ) ;
V_28 = F_37 ( V_5 ) ;
F_89 ( V_28 , V_106 ) ;
return V_107 ;
}
V_4 = F_5 ( V_5 ) ;
if ( ! V_4 && ( V_103 == V_105 ||
V_103 == V_108 ) )
V_4 = F_70 ( V_5 ) ;
if ( ! V_4 )
goto V_8;
switch ( V_103 ) {
case V_109 :
F_43 ( V_4 ) ;
break;
case V_110 :
case V_111 :
F_45 ( V_4 ) ;
break;
case V_112 :
case V_113 :
F_84 ( & V_4 -> V_91 ) ;
F_79 ( V_4 ) ;
break;
case V_114 :
if ( V_4 -> V_24 )
F_41 ( V_4 -> V_24 ) ;
break;
case V_115 :
if ( V_4 -> V_25 == V_44 )
goto V_116;
F_30 ( V_4 -> V_5 ) ;
V_28 = F_37 ( V_4 -> V_24 ) ;
V_28 -> V_33 -> V_56 ( V_4 ) ;
V_30 = F_21 ( V_28 ) ;
if ( ! V_30 )
goto V_116;
if ( V_4 == V_30 )
F_20 ( V_28 , NULL ) ;
break;
default:
break;
}
V_116:
F_24 ( V_4 ) ;
V_8:
if ( V_30 )
F_24 ( V_30 ) ;
return V_107 ;
}
