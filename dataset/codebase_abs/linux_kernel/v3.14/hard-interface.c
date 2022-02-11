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
bool F_15 ( struct V_6 * V_6 )
{
if ( ! V_6 )
return false ;
#ifdef F_16
if ( V_6 -> V_19 )
return true ;
#endif
if ( V_6 -> V_20 )
return true ;
return false ;
}
static struct V_3 *
F_17 ( const struct V_6 * V_21 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_21 != V_21 )
continue;
if ( V_4 -> V_22 == V_23 &&
F_8 ( & V_4 -> V_7 ) )
goto V_8;
}
V_4 = NULL ;
V_8:
F_9 () ;
return V_4 ;
}
static void F_18 ( struct V_24 * V_25 ,
struct V_3 * V_26 )
{
struct V_3 * V_27 ;
V_27 = F_19 ( V_25 ) ;
if ( ! V_27 )
goto V_8;
F_20 ( V_25 , V_27 ) ;
F_21 ( V_25 , V_27 , V_26 ) ;
V_8:
if ( V_27 )
F_22 ( V_27 ) ;
}
static void F_23 ( struct V_24 * V_25 ,
struct V_3 * V_28 )
{
struct V_3 * V_29 ;
F_24 () ;
if ( V_28 && ! F_8 ( & V_28 -> V_7 ) )
V_28 = NULL ;
V_29 = F_25 ( V_25 -> V_27 , 1 ) ;
F_26 ( V_25 -> V_27 , V_28 ) ;
if ( ! V_28 )
goto V_8;
V_25 -> V_30 -> V_31 ( V_28 ) ;
F_18 ( V_25 , V_29 ) ;
V_8:
if ( V_29 )
F_22 ( V_29 ) ;
}
static bool
F_27 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_14 & V_32 )
return true ;
return false ;
}
static void F_28 ( const struct V_6 * V_5 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_22 != V_23 ) &&
( V_4 -> V_22 != V_33 ) )
continue;
if ( V_4 -> V_5 == V_5 )
continue;
if ( ! F_29 ( V_4 -> V_5 -> V_34 ,
V_5 -> V_34 ) )
continue;
F_30 ( L_2 ,
V_5 -> V_34 , V_4 -> V_5 -> V_35 ) ;
F_30 ( L_3 ) ;
}
F_9 () ;
}
int F_31 ( struct V_6 * V_21 )
{
struct V_24 * V_25 = F_32 ( V_21 ) ;
const struct V_3 * V_4 ;
int V_36 = V_37 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_22 != V_23 ) &&
( V_4 -> V_22 != V_33 ) )
continue;
if ( V_4 -> V_21 != V_21 )
continue;
V_36 = F_33 ( int , V_4 -> V_5 -> V_38 , V_36 ) ;
}
F_9 () ;
if ( F_34 ( & V_25 -> V_39 ) == 0 )
goto V_8;
V_36 = F_33 ( int , V_36 , V_40 ) ;
V_36 -= sizeof( struct V_41 ) ;
V_36 *= V_42 ;
V_8:
F_35 ( & V_25 -> V_43 , V_36 ) ;
return F_33 ( int , V_36 - F_36 () , V_44 ) ;
}
void F_37 ( struct V_6 * V_21 )
{
V_21 -> V_38 = F_31 ( V_21 ) ;
F_38 ( V_21 ) ;
}
static void
F_39 ( struct V_3 * V_4 )
{
struct V_24 * V_25 ;
struct V_3 * V_27 = NULL ;
if ( V_4 -> V_22 != V_45 )
goto V_8;
V_25 = F_32 ( V_4 -> V_21 ) ;
V_25 -> V_30 -> V_46 ( V_4 ) ;
V_4 -> V_22 = V_33 ;
V_27 = F_19 ( V_25 ) ;
if ( ! V_27 )
F_23 ( V_25 , V_4 ) ;
F_40 ( V_4 -> V_21 , L_4 ,
V_4 -> V_5 -> V_35 ) ;
F_37 ( V_4 -> V_21 ) ;
V_8:
if ( V_27 )
F_22 ( V_27 ) ;
}
static void
F_41 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_22 != V_23 ) &&
( V_4 -> V_22 != V_33 ) )
return;
V_4 -> V_22 = V_45 ;
F_40 ( V_4 -> V_21 , L_5 ,
V_4 -> V_5 -> V_35 ) ;
F_37 ( V_4 -> V_21 ) ;
}
static int F_42 ( struct V_3 * V_47 ,
struct V_6 * V_48 )
{
int V_10 ;
if ( ! V_48 )
return 0 ;
V_10 = - V_49 ;
if ( V_48 -> V_50 -> V_51 )
V_10 = V_48 -> V_50 -> V_51 ( V_48 , V_47 -> V_5 ) ;
return V_10 ;
}
int F_43 ( struct V_3 * V_4 ,
const char * V_52 )
{
struct V_24 * V_25 ;
struct V_6 * V_21 , * V_48 ;
T_1 V_53 = F_44 ( V_54 ) ;
int V_55 = F_36 () ;
int V_10 ;
if ( V_4 -> V_22 != V_56 )
goto V_8;
if ( ! F_8 ( & V_4 -> V_7 ) )
goto V_8;
V_21 = F_45 ( & V_13 , V_52 ) ;
if ( ! V_21 ) {
V_21 = F_46 ( V_52 ) ;
if ( ! V_21 ) {
V_10 = - V_57 ;
goto V_58;
}
F_47 ( V_21 ) ;
}
if ( ! F_11 ( V_21 ) ) {
F_48 ( L_6 ,
V_21 -> V_35 ) ;
V_10 = - V_59 ;
goto V_60;
}
V_48 = F_49 ( V_4 -> V_5 ) ;
V_10 = F_42 ( V_4 , V_48 ) ;
if ( V_10 )
goto V_60;
V_4 -> V_21 = V_21 ;
V_25 = F_32 ( V_4 -> V_21 ) ;
V_10 = F_50 ( V_4 -> V_5 , V_21 ) ;
if ( V_10 )
goto V_60;
V_10 = V_25 -> V_30 -> V_61 ( V_4 ) ;
if ( V_10 < 0 )
goto V_62;
V_4 -> V_63 = V_25 -> V_64 ;
V_25 -> V_64 ++ ;
V_4 -> V_22 = V_45 ;
V_10 = F_51 ( V_4 , V_25 -> V_64 ) ;
if ( V_10 < 0 ) {
V_25 -> V_30 -> V_65 ( V_4 ) ;
V_25 -> V_64 -- ;
V_4 -> V_22 = V_56 ;
goto V_62;
}
V_4 -> V_66 . type = V_53 ;
V_4 -> V_66 . V_67 = V_68 ;
V_4 -> V_66 . V_69 = V_4 -> V_5 ;
F_52 ( & V_4 -> V_66 ) ;
F_40 ( V_4 -> V_21 , L_7 ,
V_4 -> V_5 -> V_35 ) ;
if ( F_34 ( & V_25 -> V_39 ) &&
V_4 -> V_5 -> V_38 < V_44 + V_55 )
F_40 ( V_4 -> V_21 ,
L_8 ,
V_4 -> V_5 -> V_35 , V_4 -> V_5 -> V_38 ,
V_44 + V_55 ) ;
if ( ! F_34 ( & V_25 -> V_39 ) &&
V_4 -> V_5 -> V_38 < V_44 + V_55 )
F_40 ( V_4 -> V_21 ,
L_9 ,
V_4 -> V_5 -> V_35 , V_4 -> V_5 -> V_38 ,
V_44 + V_55 ) ;
if ( F_27 ( V_4 ) )
F_39 ( V_4 ) ;
else
F_53 ( V_4 -> V_21 ,
L_10 ,
V_4 -> V_5 -> V_35 ) ;
F_54 ( V_4 ) ;
V_8:
return 0 ;
V_62:
F_55 ( V_4 -> V_5 , V_21 ) ;
V_60:
V_4 -> V_21 = NULL ;
F_3 ( V_21 ) ;
V_58:
F_22 ( V_4 ) ;
return V_10 ;
}
void F_56 ( struct V_3 * V_4 ,
enum V_70 V_71 )
{
struct V_24 * V_25 = F_32 ( V_4 -> V_21 ) ;
struct V_3 * V_27 = NULL ;
if ( V_4 -> V_22 == V_23 )
F_41 ( V_4 ) ;
if ( V_4 -> V_22 != V_45 )
goto V_8;
F_40 ( V_4 -> V_21 , L_11 ,
V_4 -> V_5 -> V_35 ) ;
F_57 ( & V_4 -> V_66 ) ;
V_25 -> V_64 -- ;
F_58 ( V_4 , V_25 -> V_64 ) ;
V_27 = F_19 ( V_25 ) ;
if ( V_4 == V_27 ) {
struct V_3 * V_72 ;
V_72 = F_17 ( V_4 -> V_21 ) ;
F_23 ( V_25 , V_72 ) ;
if ( V_72 )
F_22 ( V_72 ) ;
}
V_25 -> V_30 -> V_65 ( V_4 ) ;
V_4 -> V_22 = V_56 ;
F_59 ( V_25 ) ;
F_60 ( V_25 , V_4 ) ;
F_3 ( V_4 -> V_21 ) ;
if ( ! V_25 -> V_64 ) {
F_61 ( V_25 ) ;
if ( V_71 == V_73 )
F_62 ( V_4 -> V_21 ) ;
}
F_55 ( V_4 -> V_5 , V_4 -> V_21 ) ;
V_4 -> V_21 = NULL ;
F_22 ( V_4 ) ;
V_8:
if ( V_27 )
F_22 ( V_27 ) ;
}
static void F_63 ( struct V_74 * V_75 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_75 , struct V_3 ,
V_76 ) ;
F_64 ( V_4 ) ;
F_65 ( & V_4 -> V_77 ) ;
F_22 ( V_4 ) ;
}
static struct V_3 *
F_66 ( struct V_6 * V_5 )
{
struct V_3 * V_4 ;
int V_10 ;
F_24 () ;
V_10 = F_14 ( V_5 ) ;
if ( V_10 != 1 )
goto V_8;
F_47 ( V_5 ) ;
V_4 = F_67 ( sizeof( * V_4 ) , V_78 ) ;
if ( ! V_4 )
goto V_79;
V_10 = F_68 ( & V_4 -> V_77 , V_5 ) ;
if ( V_10 )
goto V_80;
V_4 -> V_63 = - 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_21 = NULL ;
V_4 -> V_22 = V_56 ;
V_10 = F_69 ( V_4 ) ;
if ( V_10 )
goto V_81;
F_70 ( & V_4 -> V_82 ) ;
F_71 ( & V_4 -> V_76 ,
F_63 ) ;
V_4 -> V_83 = V_84 ;
if ( F_15 ( V_5 ) )
V_4 -> V_83 = V_85 ;
F_35 ( & V_4 -> V_7 , 2 ) ;
F_28 ( V_4 -> V_5 ) ;
F_72 ( & V_4 -> V_82 , & V_86 ) ;
return V_4 ;
V_81:
F_65 ( & V_4 -> V_77 ) ;
V_80:
F_4 ( V_4 ) ;
V_79:
F_3 ( V_5 ) ;
V_8:
return NULL ;
}
static void F_73 ( struct V_3 * V_4 )
{
F_24 () ;
if ( V_4 -> V_22 != V_56 )
F_56 ( V_4 ,
V_73 ) ;
if ( V_4 -> V_22 != V_56 )
return;
V_4 -> V_22 = V_87 ;
F_74 ( V_88 , & V_4 -> V_76 ) ;
}
void F_75 ( void )
{
struct V_3 * V_4 , * V_89 ;
F_76 () ;
F_77 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_78 ( & V_4 -> V_82 ) ;
F_73 ( V_4 ) ;
}
F_79 () ;
}
static int F_80 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
struct V_6 * V_5 = F_81 ( V_93 ) ;
struct V_3 * V_4 ;
struct V_3 * V_27 = NULL ;
struct V_24 * V_25 ;
if ( F_11 ( V_5 ) && V_92 == V_94 ) {
F_82 ( V_5 ) ;
V_25 = F_32 ( V_5 ) ;
F_83 ( V_25 , V_95 ) ;
return V_96 ;
}
V_4 = F_5 ( V_5 ) ;
if ( ! V_4 && V_92 == V_94 )
V_4 = F_66 ( V_5 ) ;
if ( ! V_4 )
goto V_8;
switch ( V_92 ) {
case V_97 :
F_39 ( V_4 ) ;
break;
case V_98 :
case V_99 :
F_41 ( V_4 ) ;
break;
case V_100 :
F_78 ( & V_4 -> V_82 ) ;
F_73 ( V_4 ) ;
break;
case V_101 :
if ( V_4 -> V_21 )
F_37 ( V_4 -> V_21 ) ;
break;
case V_102 :
if ( V_4 -> V_22 == V_56 )
goto V_103;
F_28 ( V_4 -> V_5 ) ;
V_25 = F_32 ( V_4 -> V_21 ) ;
V_25 -> V_30 -> V_46 ( V_4 ) ;
V_27 = F_19 ( V_25 ) ;
if ( ! V_27 )
goto V_103;
if ( V_4 == V_27 )
F_18 ( V_25 , NULL ) ;
break;
default:
break;
}
V_103:
F_22 ( V_4 ) ;
V_8:
if ( V_27 )
F_22 ( V_27 ) ;
return V_96 ;
}
