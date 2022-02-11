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
static bool F_10 ( const struct V_6 * V_5 )
{
struct V_6 * V_9 ;
bool V_10 ;
if ( F_11 ( V_5 ) )
return true ;
if ( F_12 ( V_5 ) == 0 ||
F_12 ( V_5 ) == V_5 -> V_11 )
return false ;
V_9 = F_13 ( & V_12 , F_12 ( V_5 ) ) ;
if ( F_14 ( ! V_9 , L_1 ) )
return false ;
V_10 = F_10 ( V_9 ) ;
return V_10 ;
}
static int F_15 ( const struct V_6 * V_5 )
{
if ( V_5 -> V_13 & V_14 )
return 0 ;
if ( V_5 -> type != V_15 )
return 0 ;
if ( V_5 -> V_16 != V_17 )
return 0 ;
if ( F_10 ( V_5 ) )
return 0 ;
return 1 ;
}
bool F_16 ( struct V_6 * V_6 )
{
if ( ! V_6 )
return false ;
#ifdef F_17
if ( V_6 -> V_18 )
return true ;
#endif
if ( V_6 -> V_19 )
return true ;
return false ;
}
static struct V_3 *
F_18 ( const struct V_6 * V_20 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_20 != V_20 )
continue;
if ( V_4 -> V_21 == V_22 &&
F_8 ( & V_4 -> V_7 ) )
goto V_8;
}
V_4 = NULL ;
V_8:
F_9 () ;
return V_4 ;
}
static void F_19 ( struct V_23 * V_24 ,
struct V_3 * V_25 )
{
struct V_3 * V_26 ;
V_26 = F_20 ( V_24 ) ;
if ( ! V_26 )
goto V_8;
F_21 ( V_24 , V_26 ) ;
F_22 ( V_24 , V_26 , V_25 ) ;
V_8:
if ( V_26 )
F_23 ( V_26 ) ;
}
static void F_24 ( struct V_23 * V_24 ,
struct V_3 * V_27 )
{
struct V_3 * V_28 ;
F_25 () ;
if ( V_27 && ! F_8 ( & V_27 -> V_7 ) )
V_27 = NULL ;
V_28 = F_26 ( V_24 -> V_26 , 1 ) ;
F_27 ( V_24 -> V_26 , V_27 ) ;
if ( ! V_27 )
goto V_8;
V_24 -> V_29 -> V_30 ( V_27 ) ;
F_19 ( V_24 , V_28 ) ;
V_8:
if ( V_28 )
F_23 ( V_28 ) ;
}
static bool
F_28 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_13 & V_31 )
return true ;
return false ;
}
static void F_29 ( const struct V_6 * V_5 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_21 != V_22 ) &&
( V_4 -> V_21 != V_32 ) )
continue;
if ( V_4 -> V_5 == V_5 )
continue;
if ( ! F_30 ( V_4 -> V_5 -> V_33 ,
V_5 -> V_33 ) )
continue;
F_31 ( L_2 ,
V_5 -> V_33 , V_4 -> V_5 -> V_34 ) ;
F_31 ( L_3 ) ;
}
F_9 () ;
}
static void F_32 ( struct V_6 * V_20 )
{
const struct V_3 * V_4 ;
unsigned short V_35 = V_36 ;
unsigned short V_37 = 0 ;
unsigned short V_38 = 0 ;
unsigned short V_39 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_21 == V_40 )
continue;
if ( V_4 -> V_20 != V_20 )
continue;
V_35 = F_33 (unsigned short, lower_header_len,
hard_iface->net_dev->hard_header_len) ;
V_37 = F_33 (unsigned short, lower_headroom,
hard_iface->net_dev->needed_headroom) ;
V_38 = F_33 (unsigned short, lower_tailroom,
hard_iface->net_dev->needed_tailroom) ;
}
F_9 () ;
V_39 = V_37 + ( V_35 - V_36 ) ;
V_39 += F_34 () ;
V_20 -> V_39 = V_39 ;
V_20 -> V_41 = V_38 ;
}
int F_35 ( struct V_6 * V_20 )
{
struct V_23 * V_24 = F_36 ( V_20 ) ;
const struct V_3 * V_4 ;
int V_42 = V_43 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_21 != V_22 ) &&
( V_4 -> V_21 != V_32 ) )
continue;
if ( V_4 -> V_20 != V_20 )
continue;
V_42 = F_37 ( int , V_4 -> V_5 -> V_44 , V_42 ) ;
}
F_9 () ;
if ( F_38 ( & V_24 -> V_45 ) == 0 )
goto V_8;
V_42 = F_37 ( int , V_42 , V_46 ) ;
V_42 -= sizeof( struct V_47 ) ;
V_42 *= V_48 ;
V_8:
F_39 ( & V_24 -> V_49 , V_42 ) ;
return F_37 ( int , V_42 - F_34 () , V_50 ) ;
}
void F_40 ( struct V_6 * V_20 )
{
V_20 -> V_44 = F_35 ( V_20 ) ;
F_41 ( V_20 ) ;
}
static void
F_42 ( struct V_3 * V_4 )
{
struct V_23 * V_24 ;
struct V_3 * V_26 = NULL ;
if ( V_4 -> V_21 != V_51 )
goto V_8;
V_24 = F_36 ( V_4 -> V_20 ) ;
V_24 -> V_29 -> V_52 ( V_4 ) ;
V_4 -> V_21 = V_32 ;
V_26 = F_20 ( V_24 ) ;
if ( ! V_26 )
F_24 ( V_24 , V_4 ) ;
F_43 ( V_4 -> V_20 , L_4 ,
V_4 -> V_5 -> V_34 ) ;
F_40 ( V_4 -> V_20 ) ;
V_8:
if ( V_26 )
F_23 ( V_26 ) ;
}
static void
F_44 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_21 != V_22 ) &&
( V_4 -> V_21 != V_32 ) )
return;
V_4 -> V_21 = V_51 ;
F_43 ( V_4 -> V_20 , L_5 ,
V_4 -> V_5 -> V_34 ) ;
F_40 ( V_4 -> V_20 ) ;
}
static int F_45 ( struct V_3 * V_53 ,
struct V_6 * V_54 )
{
int V_10 ;
if ( ! V_54 )
return 0 ;
V_10 = - V_55 ;
if ( V_54 -> V_56 -> V_57 )
V_10 = V_54 -> V_56 -> V_57 ( V_54 , V_53 -> V_5 ) ;
return V_10 ;
}
int F_46 ( struct V_3 * V_4 ,
const char * V_58 )
{
struct V_23 * V_24 ;
struct V_6 * V_20 , * V_54 ;
T_1 V_59 = F_47 ( V_60 ) ;
int V_61 = F_34 () ;
int V_10 ;
if ( V_4 -> V_21 != V_40 )
goto V_8;
if ( ! F_8 ( & V_4 -> V_7 ) )
goto V_8;
V_20 = F_48 ( & V_12 , V_58 ) ;
if ( ! V_20 ) {
V_20 = F_49 ( V_58 ) ;
if ( ! V_20 ) {
V_10 = - V_62 ;
goto V_63;
}
F_50 ( V_20 ) ;
}
if ( ! F_11 ( V_20 ) ) {
F_51 ( L_6 ,
V_20 -> V_34 ) ;
V_10 = - V_64 ;
goto V_65;
}
V_54 = F_52 ( V_4 -> V_5 ) ;
V_10 = F_45 ( V_4 , V_54 ) ;
if ( V_10 )
goto V_65;
V_4 -> V_20 = V_20 ;
V_24 = F_36 ( V_4 -> V_20 ) ;
V_10 = F_53 ( V_4 -> V_5 , V_20 ) ;
if ( V_10 )
goto V_65;
V_10 = V_24 -> V_29 -> V_66 ( V_4 ) ;
if ( V_10 < 0 )
goto V_67;
V_4 -> V_68 = V_24 -> V_69 ;
V_24 -> V_69 ++ ;
V_4 -> V_21 = V_51 ;
V_10 = F_54 ( V_4 , V_24 -> V_69 ) ;
if ( V_10 < 0 ) {
V_24 -> V_29 -> V_70 ( V_4 ) ;
V_24 -> V_69 -- ;
V_4 -> V_21 = V_40 ;
goto V_67;
}
V_4 -> V_71 . type = V_59 ;
V_4 -> V_71 . V_72 = V_73 ;
V_4 -> V_71 . V_74 = V_4 -> V_5 ;
F_55 ( & V_4 -> V_71 ) ;
F_43 ( V_4 -> V_20 , L_7 ,
V_4 -> V_5 -> V_34 ) ;
if ( F_38 ( & V_24 -> V_45 ) &&
V_4 -> V_5 -> V_44 < V_50 + V_61 )
F_43 ( V_4 -> V_20 ,
L_8 ,
V_4 -> V_5 -> V_34 , V_4 -> V_5 -> V_44 ,
V_50 + V_61 ) ;
if ( ! F_38 ( & V_24 -> V_45 ) &&
V_4 -> V_5 -> V_44 < V_50 + V_61 )
F_43 ( V_4 -> V_20 ,
L_9 ,
V_4 -> V_5 -> V_34 , V_4 -> V_5 -> V_44 ,
V_50 + V_61 ) ;
if ( F_28 ( V_4 ) )
F_42 ( V_4 ) ;
else
F_56 ( V_4 -> V_20 ,
L_10 ,
V_4 -> V_5 -> V_34 ) ;
F_32 ( V_20 ) ;
F_57 ( V_4 ) ;
V_8:
return 0 ;
V_67:
F_58 ( V_4 -> V_5 , V_20 ) ;
V_65:
V_4 -> V_20 = NULL ;
F_3 ( V_20 ) ;
V_63:
F_23 ( V_4 ) ;
return V_10 ;
}
void F_59 ( struct V_3 * V_4 ,
enum V_75 V_76 )
{
struct V_23 * V_24 = F_36 ( V_4 -> V_20 ) ;
struct V_3 * V_26 = NULL ;
if ( V_4 -> V_21 == V_22 )
F_44 ( V_4 ) ;
if ( V_4 -> V_21 != V_51 )
goto V_8;
F_43 ( V_4 -> V_20 , L_11 ,
V_4 -> V_5 -> V_34 ) ;
F_60 ( & V_4 -> V_71 ) ;
V_24 -> V_69 -- ;
F_61 ( V_4 , V_24 -> V_69 ) ;
V_26 = F_20 ( V_24 ) ;
if ( V_4 == V_26 ) {
struct V_3 * V_77 ;
V_77 = F_18 ( V_4 -> V_20 ) ;
F_24 ( V_24 , V_77 ) ;
if ( V_77 )
F_23 ( V_77 ) ;
}
V_24 -> V_29 -> V_70 ( V_4 ) ;
V_4 -> V_21 = V_40 ;
F_62 ( V_24 ) ;
F_63 ( V_24 , V_4 ) ;
F_3 ( V_4 -> V_20 ) ;
F_58 ( V_4 -> V_5 , V_4 -> V_20 ) ;
F_32 ( V_4 -> V_20 ) ;
if ( ! V_24 -> V_69 ) {
F_64 ( V_24 ) ;
if ( V_76 == V_78 )
F_65 ( V_4 -> V_20 ) ;
}
V_4 -> V_20 = NULL ;
F_23 ( V_4 ) ;
V_8:
if ( V_26 )
F_23 ( V_26 ) ;
}
static void F_66 ( struct V_79 * V_80 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_80 , struct V_3 ,
V_81 ) ;
F_67 ( V_4 ) ;
F_68 ( & V_4 -> V_82 ) ;
F_23 ( V_4 ) ;
}
static struct V_3 *
F_69 ( struct V_6 * V_5 )
{
struct V_3 * V_4 ;
int V_10 ;
F_25 () ;
V_10 = F_15 ( V_5 ) ;
if ( V_10 != 1 )
goto V_8;
F_50 ( V_5 ) ;
V_4 = F_70 ( sizeof( * V_4 ) , V_83 ) ;
if ( ! V_4 )
goto V_84;
V_10 = F_71 ( & V_4 -> V_82 , V_5 ) ;
if ( V_10 )
goto V_85;
V_4 -> V_68 = - 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_20 = NULL ;
V_4 -> V_21 = V_40 ;
V_10 = F_72 ( V_4 ) ;
if ( V_10 )
goto V_86;
F_73 ( & V_4 -> V_87 ) ;
F_74 ( & V_4 -> V_81 ,
F_66 ) ;
V_4 -> V_88 = V_89 ;
if ( F_16 ( V_5 ) )
V_4 -> V_88 = V_90 ;
F_39 ( & V_4 -> V_7 , 2 ) ;
F_29 ( V_4 -> V_5 ) ;
F_75 ( & V_4 -> V_87 , & V_91 ) ;
return V_4 ;
V_86:
F_68 ( & V_4 -> V_82 ) ;
V_85:
F_4 ( V_4 ) ;
V_84:
F_3 ( V_5 ) ;
V_8:
return NULL ;
}
static void F_76 ( struct V_3 * V_4 )
{
F_25 () ;
if ( V_4 -> V_21 != V_40 )
F_59 ( V_4 ,
V_78 ) ;
if ( V_4 -> V_21 != V_40 )
return;
V_4 -> V_21 = V_92 ;
F_77 ( V_93 , & V_4 -> V_81 ) ;
}
void F_78 ( void )
{
struct V_3 * V_4 , * V_94 ;
F_79 () ;
F_80 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_81 ( & V_4 -> V_87 ) ;
F_76 ( V_4 ) ;
}
F_82 () ;
}
static int F_83 ( struct V_95 * V_96 ,
unsigned long V_97 , void * V_98 )
{
struct V_6 * V_5 = F_84 ( V_98 ) ;
struct V_3 * V_4 ;
struct V_3 * V_26 = NULL ;
struct V_23 * V_24 ;
if ( F_11 ( V_5 ) && V_97 == V_99 ) {
F_85 ( V_5 ) ;
V_24 = F_36 ( V_5 ) ;
F_86 ( V_24 , V_100 ) ;
return V_101 ;
}
V_4 = F_5 ( V_5 ) ;
if ( ! V_4 && V_97 == V_99 )
V_4 = F_69 ( V_5 ) ;
if ( ! V_4 )
goto V_8;
switch ( V_97 ) {
case V_102 :
F_42 ( V_4 ) ;
break;
case V_103 :
case V_104 :
F_44 ( V_4 ) ;
break;
case V_105 :
F_81 ( & V_4 -> V_87 ) ;
F_76 ( V_4 ) ;
break;
case V_106 :
if ( V_4 -> V_20 )
F_40 ( V_4 -> V_20 ) ;
break;
case V_107 :
if ( V_4 -> V_21 == V_40 )
goto V_108;
F_29 ( V_4 -> V_5 ) ;
V_24 = F_36 ( V_4 -> V_20 ) ;
V_24 -> V_29 -> V_52 ( V_4 ) ;
V_26 = F_20 ( V_24 ) ;
if ( ! V_26 )
goto V_108;
if ( V_4 == V_26 )
F_19 ( V_24 , NULL ) ;
break;
default:
break;
}
V_108:
F_23 ( V_4 ) ;
V_8:
if ( V_26 )
F_23 ( V_26 ) ;
return V_101 ;
}
