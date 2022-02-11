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
if ( V_5 -> V_11 == V_5 -> V_12 )
return false ;
V_9 = F_12 ( & V_13 , V_5 -> V_11 ) ;
if ( F_13 ( ! V_9 , L_1 ) )
return false ;
V_10 = F_10 ( V_9 ) ;
if ( V_9 )
F_3 ( V_9 ) ;
return V_10 ;
}
static int F_14 ( const struct V_6 * V_5 )
{
if ( V_5 -> V_14 & V_15 )
return 0 ;
if ( V_5 -> type != V_16 )
return 0 ;
if ( V_5 -> V_17 != V_18 )
return 0 ;
if ( F_10 ( V_5 ) )
return 0 ;
return 1 ;
}
static bool F_15 ( struct V_6 * V_6 )
{
#ifdef F_16
if ( V_6 -> V_19 )
return true ;
#endif
if ( V_6 -> V_20 )
return true ;
return false ;
}
bool F_17 ( int V_12 )
{
struct V_6 * V_6 = NULL ;
bool V_10 = false ;
if ( V_12 == V_21 )
goto V_8;
V_6 = F_12 ( & V_13 , V_12 ) ;
if ( ! V_6 )
goto V_8;
V_10 = F_15 ( V_6 ) ;
V_8:
if ( V_6 )
F_3 ( V_6 ) ;
return V_10 ;
}
static struct V_3 *
F_18 ( const struct V_6 * V_22 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_22 != V_22 )
continue;
if ( V_4 -> V_23 == V_24 &&
F_8 ( & V_4 -> V_7 ) )
goto V_8;
}
V_4 = NULL ;
V_8:
F_9 () ;
return V_4 ;
}
static void F_19 ( struct V_25 * V_26 ,
struct V_3 * V_27 )
{
struct V_28 * V_29 ;
struct V_3 * V_30 ;
struct V_31 * V_32 ;
V_30 = F_20 ( V_26 ) ;
if ( ! V_30 )
goto V_8;
F_21 ( V_26 , V_30 ) ;
V_32 = V_26 -> V_33 . V_34 -> V_35 ;
V_29 = (struct V_28 * ) V_32 -> V_36 ;
memcpy ( V_29 -> V_37 , V_30 -> V_5 -> V_38 , V_18 ) ;
memcpy ( V_29 -> V_39 ,
V_30 -> V_5 -> V_38 , V_18 ) ;
F_22 ( V_26 , V_30 , V_27 ) ;
V_8:
if ( V_30 )
F_23 ( V_30 ) ;
}
static void F_24 ( struct V_25 * V_26 ,
struct V_3 * V_40 )
{
struct V_3 * V_41 ;
F_25 () ;
if ( V_40 && ! F_8 ( & V_40 -> V_7 ) )
V_40 = NULL ;
V_41 = F_26 ( V_26 -> V_30 , 1 ) ;
F_27 ( V_26 -> V_30 , V_40 ) ;
if ( ! V_40 )
goto V_8;
V_26 -> V_42 -> V_43 ( V_40 ) ;
F_19 ( V_26 , V_41 ) ;
V_8:
if ( V_41 )
F_23 ( V_41 ) ;
}
static bool
F_28 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_14 & V_44 )
return true ;
return false ;
}
static void F_29 ( const struct V_6 * V_5 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_23 != V_24 ) &&
( V_4 -> V_23 != V_45 ) )
continue;
if ( V_4 -> V_5 == V_5 )
continue;
if ( ! F_30 ( V_4 -> V_5 -> V_38 ,
V_5 -> V_38 ) )
continue;
F_31 ( L_2 ,
V_5 -> V_38 , V_4 -> V_5 -> V_46 ) ;
F_31 ( L_3 ) ;
}
F_9 () ;
}
int F_32 ( struct V_6 * V_22 )
{
const struct V_25 * V_26 = F_33 ( V_22 ) ;
const struct V_3 * V_4 ;
int V_47 = V_48 ;
if ( F_34 ( & V_26 -> V_49 ) )
goto V_8;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_23 != V_24 ) &&
( V_4 -> V_23 != V_45 ) )
continue;
if ( V_4 -> V_22 != V_22 )
continue;
V_47 = F_35 ( int ,
V_4 -> V_5 -> V_50 - V_51 ,
V_47 ) ;
}
F_9 () ;
V_8:
return V_47 ;
}
void F_36 ( struct V_6 * V_22 )
{
int V_47 ;
V_47 = F_32 ( V_22 ) ;
if ( V_22 -> V_50 != V_47 )
V_22 -> V_50 = V_47 ;
}
static void
F_37 ( struct V_3 * V_4 )
{
struct V_25 * V_26 ;
struct V_3 * V_30 = NULL ;
if ( V_4 -> V_23 != V_52 )
goto V_8;
V_26 = F_33 ( V_4 -> V_22 ) ;
V_26 -> V_42 -> V_53 ( V_4 ) ;
V_4 -> V_23 = V_45 ;
V_30 = F_20 ( V_26 ) ;
if ( ! V_30 )
F_24 ( V_26 , V_4 ) ;
F_38 ( V_4 -> V_22 , L_4 ,
V_4 -> V_5 -> V_46 ) ;
F_36 ( V_4 -> V_22 ) ;
V_8:
if ( V_30 )
F_23 ( V_30 ) ;
}
static void
F_39 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_23 != V_24 ) &&
( V_4 -> V_23 != V_45 ) )
return;
V_4 -> V_23 = V_52 ;
F_38 ( V_4 -> V_22 , L_5 ,
V_4 -> V_5 -> V_46 ) ;
F_36 ( V_4 -> V_22 ) ;
}
static int F_40 ( struct V_3 * V_54 ,
struct V_6 * V_55 )
{
int V_10 ;
if ( ! V_55 )
return 0 ;
V_10 = - V_56 ;
if ( V_55 -> V_57 -> V_58 )
V_10 = V_55 -> V_57 -> V_58 ( V_55 , V_54 -> V_5 ) ;
return V_10 ;
}
int F_41 ( struct V_3 * V_4 ,
const char * V_59 )
{
struct V_25 * V_26 ;
struct V_6 * V_22 , * V_55 ;
T_1 V_60 = F_42 ( V_61 ) ;
int V_10 ;
if ( V_4 -> V_23 != V_62 )
goto V_8;
if ( ! F_8 ( & V_4 -> V_7 ) )
goto V_8;
V_22 = F_43 ( & V_13 , V_59 ) ;
if ( ! V_22 ) {
V_22 = F_44 ( V_59 ) ;
if ( ! V_22 ) {
V_10 = - V_63 ;
goto V_64;
}
F_45 ( V_22 ) ;
}
if ( ! F_11 ( V_22 ) ) {
F_46 ( L_6 ,
V_22 -> V_46 ) ;
V_10 = - V_65 ;
goto V_66;
}
V_55 = F_47 ( V_4 -> V_5 ) ;
V_10 = F_40 ( V_4 , V_55 ) ;
if ( V_10 )
goto V_66;
V_4 -> V_22 = V_22 ;
V_26 = F_33 ( V_4 -> V_22 ) ;
V_10 = F_48 ( V_4 -> V_5 , V_22 ) ;
if ( V_10 )
goto V_66;
V_10 = V_26 -> V_42 -> V_67 ( V_4 ) ;
if ( V_10 < 0 )
goto V_68;
V_4 -> V_69 = V_26 -> V_70 ;
V_26 -> V_70 ++ ;
V_4 -> V_23 = V_52 ;
V_10 = F_49 ( V_4 , V_26 -> V_70 ) ;
if ( V_10 < 0 ) {
V_26 -> V_42 -> V_71 ( V_4 ) ;
V_26 -> V_70 -- ;
V_4 -> V_23 = V_62 ;
goto V_68;
}
V_4 -> V_72 . type = V_60 ;
V_4 -> V_72 . V_73 = V_74 ;
V_4 -> V_72 . V_75 = V_4 -> V_5 ;
F_50 ( & V_4 -> V_72 ) ;
F_51 ( & V_4 -> V_76 , 1 ) ;
F_38 ( V_4 -> V_22 , L_7 ,
V_4 -> V_5 -> V_46 ) ;
if ( F_34 ( & V_26 -> V_49 ) &&
V_4 -> V_5 -> V_50 < V_48 + V_51 )
F_38 ( V_4 -> V_22 ,
L_8 ,
V_4 -> V_5 -> V_46 , V_4 -> V_5 -> V_50 ,
V_48 + V_51 ) ;
if ( ! F_34 ( & V_26 -> V_49 ) &&
V_4 -> V_5 -> V_50 < V_48 + V_51 )
F_38 ( V_4 -> V_22 ,
L_9 ,
V_4 -> V_5 -> V_46 , V_4 -> V_5 -> V_50 ,
V_48 + V_51 ) ;
if ( F_28 ( V_4 ) )
F_37 ( V_4 ) ;
else
F_52 ( V_4 -> V_22 ,
L_10 ,
V_4 -> V_5 -> V_46 ) ;
F_53 ( V_4 ) ;
V_8:
return 0 ;
V_68:
F_54 ( V_4 -> V_5 , V_22 ) ;
V_66:
V_4 -> V_22 = NULL ;
F_3 ( V_22 ) ;
V_64:
F_23 ( V_4 ) ;
return V_10 ;
}
void F_55 ( struct V_3 * V_4 ,
enum V_77 V_78 )
{
struct V_25 * V_26 = F_33 ( V_4 -> V_22 ) ;
struct V_3 * V_30 = NULL ;
if ( V_4 -> V_23 == V_24 )
F_39 ( V_4 ) ;
if ( V_4 -> V_23 != V_52 )
goto V_8;
F_38 ( V_4 -> V_22 , L_11 ,
V_4 -> V_5 -> V_46 ) ;
F_56 ( & V_4 -> V_72 ) ;
V_26 -> V_70 -- ;
F_57 ( V_4 , V_26 -> V_70 ) ;
V_30 = F_20 ( V_26 ) ;
if ( V_4 == V_30 ) {
struct V_3 * V_79 ;
V_79 = F_18 ( V_4 -> V_22 ) ;
F_24 ( V_26 , V_79 ) ;
if ( V_79 )
F_23 ( V_79 ) ;
}
V_26 -> V_42 -> V_71 ( V_4 ) ;
V_4 -> V_23 = V_62 ;
F_58 ( V_26 ) ;
F_59 ( V_26 , V_4 ) ;
F_3 ( V_4 -> V_22 ) ;
if ( ! V_26 -> V_70 && V_78 == V_80 )
F_60 ( V_4 -> V_22 ) ;
F_54 ( V_4 -> V_5 , V_4 -> V_22 ) ;
V_4 -> V_22 = NULL ;
F_23 ( V_4 ) ;
V_8:
if ( V_30 )
F_23 ( V_30 ) ;
}
static void F_61 ( struct V_81 * V_82 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_82 , struct V_3 ,
V_83 ) ;
F_62 ( & V_4 -> V_84 ) ;
F_23 ( V_4 ) ;
}
static struct V_3 *
F_63 ( struct V_6 * V_5 )
{
struct V_3 * V_4 ;
int V_10 ;
F_25 () ;
V_10 = F_14 ( V_5 ) ;
if ( V_10 != 1 )
goto V_8;
F_45 ( V_5 ) ;
V_4 = F_64 ( sizeof( * V_4 ) , V_85 ) ;
if ( ! V_4 )
goto V_86;
V_10 = F_65 ( & V_4 -> V_84 , V_5 ) ;
if ( V_10 )
goto V_87;
V_4 -> V_69 = - 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_22 = NULL ;
V_4 -> V_23 = V_62 ;
F_66 ( & V_4 -> V_88 ) ;
F_67 ( & V_4 -> V_83 ,
F_61 ) ;
V_4 -> V_89 = V_90 ;
if ( F_15 ( V_5 ) )
V_4 -> V_89 = V_91 ;
F_51 ( & V_4 -> V_7 , 2 ) ;
F_29 ( V_4 -> V_5 ) ;
F_68 ( & V_4 -> V_88 , & V_92 ) ;
return V_4 ;
V_87:
F_4 ( V_4 ) ;
V_86:
F_3 ( V_5 ) ;
V_8:
return NULL ;
}
static void F_69 ( struct V_3 * V_4 )
{
F_25 () ;
if ( V_4 -> V_23 != V_62 )
F_55 ( V_4 ,
V_80 ) ;
if ( V_4 -> V_23 != V_62 )
return;
V_4 -> V_23 = V_93 ;
F_70 ( V_94 , & V_4 -> V_83 ) ;
}
void F_71 ( void )
{
struct V_3 * V_4 , * V_95 ;
F_72 () ;
F_73 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_74 ( & V_4 -> V_88 ) ;
F_69 ( V_4 ) ;
}
F_75 () ;
}
static int F_76 ( struct V_96 * V_97 ,
unsigned long V_98 , void * V_99 )
{
struct V_6 * V_5 = F_77 ( V_99 ) ;
struct V_3 * V_4 ;
struct V_3 * V_30 = NULL ;
struct V_25 * V_26 ;
if ( F_11 ( V_5 ) && V_98 == V_100 ) {
F_78 ( V_5 ) ;
return V_101 ;
}
V_4 = F_5 ( V_5 ) ;
if ( ! V_4 && V_98 == V_100 )
V_4 = F_63 ( V_5 ) ;
if ( ! V_4 )
goto V_8;
switch ( V_98 ) {
case V_102 :
F_37 ( V_4 ) ;
break;
case V_103 :
case V_104 :
F_39 ( V_4 ) ;
break;
case V_105 :
F_74 ( & V_4 -> V_88 ) ;
F_69 ( V_4 ) ;
break;
case V_106 :
if ( V_4 -> V_22 )
F_36 ( V_4 -> V_22 ) ;
break;
case V_107 :
if ( V_4 -> V_23 == V_62 )
goto V_108;
F_29 ( V_4 -> V_5 ) ;
V_26 = F_33 ( V_4 -> V_22 ) ;
V_26 -> V_42 -> V_53 ( V_4 ) ;
V_30 = F_20 ( V_26 ) ;
if ( ! V_30 )
goto V_108;
if ( V_4 == V_30 )
F_19 ( V_26 , NULL ) ;
break;
default:
break;
}
V_108:
F_23 ( V_4 ) ;
V_8:
if ( V_30 )
F_23 ( V_30 ) ;
return V_101 ;
}
