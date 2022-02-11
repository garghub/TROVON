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
static bool F_10 ( const struct V_8 * V_10 ,
const struct V_8 * V_11 )
{
int V_12 = F_11 ( V_10 ) ;
int V_13 = F_11 ( V_11 ) ;
if ( ! V_12 || ! V_13 )
return false ;
return ( V_12 == V_11 -> V_14 ) &&
( V_13 == V_10 -> V_14 ) ;
}
static bool F_12 ( const struct V_8 * V_6 )
{
struct V_8 * V_15 ;
struct V_16 * V_16 = F_13 ( V_6 ) ;
bool V_17 ;
if ( F_14 ( V_6 ) )
return true ;
if ( F_11 ( V_6 ) == 0 ||
F_11 ( V_6 ) == V_6 -> V_14 )
return false ;
V_15 = F_15 ( V_16 , F_11 ( V_6 ) ) ;
if ( F_16 ( ! V_15 , L_1 ) )
return false ;
if ( F_10 ( V_6 , V_15 ) )
return false ;
V_17 = F_12 ( V_15 ) ;
return V_17 ;
}
static bool F_17 ( const struct V_8 * V_6 )
{
if ( V_6 -> V_18 & V_19 )
return false ;
if ( V_6 -> type != V_20 )
return false ;
if ( V_6 -> V_21 != V_22 )
return false ;
if ( F_12 ( V_6 ) )
return false ;
return true ;
}
bool F_18 ( struct V_8 * V_8 )
{
if ( ! V_8 )
return false ;
#ifdef F_19
if ( V_8 -> V_23 )
return true ;
#endif
if ( V_8 -> V_24 )
return true ;
return false ;
}
static struct V_3 *
F_20 ( const struct V_8 * V_25 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_25 != V_25 )
continue;
if ( V_4 -> V_26 == V_27 &&
F_8 ( & V_4 -> V_5 ) )
goto V_9;
}
V_4 = NULL ;
V_9:
F_9 () ;
return V_4 ;
}
static void F_21 ( struct V_28 * V_29 ,
struct V_3 * V_30 )
{
struct V_3 * V_31 ;
V_31 = F_22 ( V_29 ) ;
if ( ! V_31 )
goto V_9;
F_23 ( V_29 , V_31 ) ;
F_24 ( V_29 , V_31 , V_30 ) ;
V_9:
if ( V_31 )
F_25 ( V_31 ) ;
}
static void F_26 ( struct V_28 * V_29 ,
struct V_3 * V_32 )
{
struct V_3 * V_33 ;
F_27 () ;
if ( V_32 )
F_28 ( & V_32 -> V_5 ) ;
V_33 = F_29 ( V_29 -> V_31 , 1 ) ;
F_30 ( V_29 -> V_31 , V_32 ) ;
if ( ! V_32 )
goto V_9;
V_29 -> V_34 -> V_35 ( V_32 ) ;
F_21 ( V_29 , V_33 ) ;
V_9:
if ( V_33 )
F_25 ( V_33 ) ;
}
static bool
F_31 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_6 -> V_18 & V_36 )
return true ;
return false ;
}
static void F_32 ( const struct V_8 * V_6 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_26 != V_27 ) &&
( V_4 -> V_26 != V_37 ) )
continue;
if ( V_4 -> V_6 == V_6 )
continue;
if ( ! F_33 ( V_4 -> V_6 -> V_38 ,
V_6 -> V_38 ) )
continue;
F_34 ( L_2 ,
V_6 -> V_38 , V_4 -> V_6 -> V_39 ) ;
F_34 ( L_3 ) ;
}
F_9 () ;
}
static void F_35 ( struct V_8 * V_25 )
{
const struct V_3 * V_4 ;
unsigned short V_40 = V_41 ;
unsigned short V_42 = 0 ;
unsigned short V_43 = 0 ;
unsigned short V_44 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_26 == V_45 )
continue;
if ( V_4 -> V_25 != V_25 )
continue;
V_40 = F_36 (unsigned short, lower_header_len,
hard_iface->net_dev->hard_header_len) ;
V_42 = F_36 (unsigned short, lower_headroom,
hard_iface->net_dev->needed_headroom) ;
V_43 = F_36 (unsigned short, lower_tailroom,
hard_iface->net_dev->needed_tailroom) ;
}
F_9 () ;
V_44 = V_42 + ( V_40 - V_41 ) ;
V_44 += F_37 () ;
V_25 -> V_44 = V_44 ;
V_25 -> V_46 = V_43 ;
}
int F_38 ( struct V_8 * V_25 )
{
struct V_28 * V_29 = F_39 ( V_25 ) ;
const struct V_3 * V_4 ;
int V_47 = V_48 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_26 != V_27 ) &&
( V_4 -> V_26 != V_37 ) )
continue;
if ( V_4 -> V_25 != V_25 )
continue;
V_47 = F_40 ( int , V_4 -> V_6 -> V_49 , V_47 ) ;
}
F_9 () ;
if ( F_41 ( & V_29 -> V_50 ) == 0 )
goto V_9;
V_47 = F_40 ( int , V_47 , V_51 ) ;
V_47 -= sizeof( struct V_52 ) ;
V_47 *= V_53 ;
V_9:
F_42 ( & V_29 -> V_54 , V_47 ) ;
return F_40 ( int , V_47 - F_37 () , V_55 ) ;
}
void F_43 ( struct V_8 * V_25 )
{
V_25 -> V_49 = F_38 ( V_25 ) ;
F_44 ( V_25 ) ;
}
static void
F_45 ( struct V_3 * V_4 )
{
struct V_28 * V_29 ;
struct V_3 * V_31 = NULL ;
if ( V_4 -> V_26 != V_56 )
goto V_9;
V_29 = F_39 ( V_4 -> V_25 ) ;
V_29 -> V_34 -> V_57 ( V_4 ) ;
V_4 -> V_26 = V_37 ;
V_31 = F_22 ( V_29 ) ;
if ( ! V_31 )
F_26 ( V_29 , V_4 ) ;
F_46 ( V_4 -> V_25 , L_4 ,
V_4 -> V_6 -> V_39 ) ;
F_43 ( V_4 -> V_25 ) ;
if ( V_29 -> V_34 -> V_58 )
V_29 -> V_34 -> V_58 ( V_4 ) ;
V_9:
if ( V_31 )
F_25 ( V_31 ) ;
}
static void
F_47 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_26 != V_27 ) &&
( V_4 -> V_26 != V_37 ) )
return;
V_4 -> V_26 = V_56 ;
F_46 ( V_4 -> V_25 , L_5 ,
V_4 -> V_6 -> V_39 ) ;
F_43 ( V_4 -> V_25 ) ;
}
static int F_48 ( struct V_3 * V_59 ,
struct V_8 * V_60 )
{
int V_17 ;
if ( ! V_60 )
return 0 ;
V_17 = - V_61 ;
if ( V_60 -> V_62 -> V_63 )
V_17 = V_60 -> V_62 -> V_63 ( V_60 , V_59 -> V_6 ) ;
return V_17 ;
}
int F_49 ( struct V_3 * V_4 ,
struct V_16 * V_16 , const char * V_64 )
{
struct V_28 * V_29 ;
struct V_8 * V_25 , * V_60 ;
T_1 V_65 = F_50 ( V_66 ) ;
int V_67 = F_37 () ;
int V_17 ;
if ( V_4 -> V_26 != V_45 )
goto V_9;
F_28 ( & V_4 -> V_5 ) ;
V_25 = F_51 ( V_16 , V_64 ) ;
if ( ! V_25 ) {
V_25 = F_52 ( V_16 , V_64 ) ;
if ( ! V_25 ) {
V_17 = - V_68 ;
goto V_69;
}
F_53 ( V_25 ) ;
}
if ( ! F_14 ( V_25 ) ) {
F_54 ( L_6 ,
V_25 -> V_39 ) ;
V_17 = - V_70 ;
goto V_71;
}
V_60 = F_55 ( V_4 -> V_6 ) ;
V_17 = F_48 ( V_4 , V_60 ) ;
if ( V_17 )
goto V_71;
V_4 -> V_25 = V_25 ;
V_29 = F_39 ( V_4 -> V_25 ) ;
V_17 = F_56 ( V_4 -> V_6 ,
V_25 , NULL , NULL ) ;
if ( V_17 )
goto V_71;
V_17 = V_29 -> V_34 -> V_72 ( V_4 ) ;
if ( V_17 < 0 )
goto V_73;
V_4 -> V_74 = V_29 -> V_75 ;
V_29 -> V_75 ++ ;
V_4 -> V_26 = V_56 ;
V_17 = F_57 ( V_4 , V_29 -> V_75 ) ;
if ( V_17 < 0 ) {
V_29 -> V_34 -> V_76 ( V_4 ) ;
V_29 -> V_75 -- ;
V_4 -> V_26 = V_45 ;
goto V_73;
}
F_28 ( & V_4 -> V_5 ) ;
V_4 -> V_77 . type = V_65 ;
V_4 -> V_77 . V_78 = V_79 ;
V_4 -> V_77 . V_80 = V_4 -> V_6 ;
F_58 ( & V_4 -> V_77 ) ;
F_46 ( V_4 -> V_25 , L_7 ,
V_4 -> V_6 -> V_39 ) ;
if ( F_41 ( & V_29 -> V_50 ) &&
V_4 -> V_6 -> V_49 < V_55 + V_67 )
F_46 ( V_4 -> V_25 ,
L_8 ,
V_4 -> V_6 -> V_39 , V_4 -> V_6 -> V_49 ,
V_55 + V_67 ) ;
if ( ! F_41 ( & V_29 -> V_50 ) &&
V_4 -> V_6 -> V_49 < V_55 + V_67 )
F_46 ( V_4 -> V_25 ,
L_9 ,
V_4 -> V_6 -> V_39 , V_4 -> V_6 -> V_49 ,
V_55 + V_67 ) ;
if ( F_31 ( V_4 ) )
F_45 ( V_4 ) ;
else
F_59 ( V_4 -> V_25 ,
L_10 ,
V_4 -> V_6 -> V_39 ) ;
F_35 ( V_25 ) ;
F_60 ( V_4 ) ;
V_9:
return 0 ;
V_73:
F_61 ( V_4 -> V_6 , V_25 ) ;
V_71:
V_4 -> V_25 = NULL ;
F_3 ( V_25 ) ;
V_69:
F_25 ( V_4 ) ;
return V_17 ;
}
void F_62 ( struct V_3 * V_4 ,
enum V_81 V_82 )
{
struct V_28 * V_29 = F_39 ( V_4 -> V_25 ) ;
struct V_3 * V_31 = NULL ;
F_47 ( V_4 ) ;
if ( V_4 -> V_26 != V_56 )
goto V_9;
F_46 ( V_4 -> V_25 , L_11 ,
V_4 -> V_6 -> V_39 ) ;
F_63 ( & V_4 -> V_77 ) ;
F_25 ( V_4 ) ;
V_29 -> V_75 -- ;
F_64 ( V_4 , V_29 -> V_75 ) ;
V_31 = F_22 ( V_29 ) ;
if ( V_4 == V_31 ) {
struct V_3 * V_83 ;
V_83 = F_20 ( V_4 -> V_25 ) ;
F_26 ( V_29 , V_83 ) ;
if ( V_83 )
F_25 ( V_83 ) ;
}
V_29 -> V_34 -> V_76 ( V_4 ) ;
V_4 -> V_26 = V_45 ;
F_65 ( V_29 ) ;
F_66 ( V_29 , V_4 ) ;
F_3 ( V_4 -> V_25 ) ;
F_61 ( V_4 -> V_6 , V_4 -> V_25 ) ;
F_35 ( V_4 -> V_25 ) ;
if ( ! V_29 -> V_75 ) {
F_67 ( V_29 ) ;
if ( V_82 == V_84 )
F_68 ( V_4 -> V_25 ) ;
}
V_4 -> V_25 = NULL ;
F_25 ( V_4 ) ;
V_9:
if ( V_31 )
F_25 ( V_31 ) ;
}
static void F_69 ( struct V_85 * V_86 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_86 , struct V_3 ,
V_87 ) ;
F_70 ( V_4 ) ;
F_71 ( & V_4 -> V_88 ) ;
F_25 ( V_4 ) ;
}
static struct V_3 *
F_72 ( struct V_8 * V_6 )
{
struct V_3 * V_4 ;
int V_17 ;
F_27 () ;
if ( ! F_17 ( V_6 ) )
goto V_9;
F_53 ( V_6 ) ;
V_4 = F_73 ( sizeof( * V_4 ) , V_89 ) ;
if ( ! V_4 )
goto V_90;
V_17 = F_74 ( & V_4 -> V_88 , V_6 ) ;
if ( V_17 )
goto V_91;
V_4 -> V_74 = - 1 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_25 = NULL ;
V_4 -> V_26 = V_45 ;
V_17 = F_75 ( V_4 ) ;
if ( V_17 )
goto V_92;
F_76 ( & V_4 -> V_93 ) ;
F_77 ( & V_4 -> V_94 ) ;
F_78 ( & V_4 -> V_87 ,
F_69 ) ;
F_79 ( & V_4 -> V_95 ) ;
V_4 -> V_96 = V_97 ;
if ( F_18 ( V_6 ) )
V_4 -> V_96 = V_98 ;
F_80 ( & V_4 -> V_5 ) ;
F_28 ( & V_4 -> V_5 ) ;
F_32 ( V_4 -> V_6 ) ;
F_81 ( & V_4 -> V_93 , & V_99 ) ;
return V_4 ;
V_92:
F_71 ( & V_4 -> V_88 ) ;
V_91:
F_82 ( V_4 ) ;
V_90:
F_3 ( V_6 ) ;
V_9:
return NULL ;
}
static void F_83 ( struct V_3 * V_4 )
{
F_27 () ;
if ( V_4 -> V_26 != V_45 )
F_62 ( V_4 ,
V_84 ) ;
if ( V_4 -> V_26 != V_45 )
return;
V_4 -> V_26 = V_100 ;
F_84 ( V_101 , & V_4 -> V_87 ) ;
}
void F_85 ( void )
{
struct V_3 * V_4 , * V_102 ;
F_86 () ;
F_87 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_88 ( & V_4 -> V_93 ) ;
F_83 ( V_4 ) ;
}
F_89 () ;
}
static int F_90 ( struct V_103 * V_104 ,
unsigned long V_105 , void * V_106 )
{
struct V_8 * V_6 = F_91 ( V_106 ) ;
struct V_3 * V_4 ;
struct V_3 * V_31 = NULL ;
struct V_28 * V_29 ;
if ( F_14 ( V_6 ) && V_105 == V_107 ) {
F_92 ( V_6 ) ;
V_29 = F_39 ( V_6 ) ;
F_93 ( V_29 , V_108 ) ;
return V_109 ;
}
V_4 = F_5 ( V_6 ) ;
if ( ! V_4 && ( V_105 == V_107 ||
V_105 == V_110 ) )
V_4 = F_72 ( V_6 ) ;
if ( ! V_4 )
goto V_9;
switch ( V_105 ) {
case V_111 :
F_45 ( V_4 ) ;
break;
case V_112 :
case V_113 :
F_47 ( V_4 ) ;
break;
case V_114 :
case V_115 :
F_88 ( & V_4 -> V_93 ) ;
F_83 ( V_4 ) ;
break;
case V_116 :
if ( V_4 -> V_25 )
F_43 ( V_4 -> V_25 ) ;
break;
case V_117 :
if ( V_4 -> V_26 == V_45 )
goto V_118;
F_32 ( V_4 -> V_6 ) ;
V_29 = F_39 ( V_4 -> V_25 ) ;
V_29 -> V_34 -> V_57 ( V_4 ) ;
V_31 = F_22 ( V_29 ) ;
if ( ! V_31 )
goto V_118;
if ( V_4 == V_31 )
F_21 ( V_29 , NULL ) ;
break;
default:
break;
}
V_118:
F_25 ( V_4 ) ;
V_9:
if ( V_31 )
F_25 ( V_31 ) ;
return V_109 ;
}
