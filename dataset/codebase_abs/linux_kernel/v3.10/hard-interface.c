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
static struct V_3 *
F_15 ( const struct V_6 * V_19 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_19 != V_19 )
continue;
if ( V_4 -> V_20 == V_21 &&
F_8 ( & V_4 -> V_7 ) )
goto V_8;
}
V_4 = NULL ;
V_8:
F_9 () ;
return V_4 ;
}
static void F_16 ( struct V_22 * V_23 ,
struct V_3 * V_24 )
{
struct V_25 * V_26 ;
struct V_3 * V_27 ;
struct V_28 * V_29 ;
V_27 = F_17 ( V_23 ) ;
if ( ! V_27 )
goto V_8;
F_18 ( V_23 , V_27 ) ;
V_29 = V_23 -> V_30 . V_31 -> V_32 ;
V_26 = (struct V_25 * ) V_29 -> V_33 ;
memcpy ( V_26 -> V_34 , V_27 -> V_5 -> V_35 , V_18 ) ;
memcpy ( V_26 -> V_36 ,
V_27 -> V_5 -> V_35 , V_18 ) ;
F_19 ( V_23 , V_27 , V_24 ) ;
V_8:
if ( V_27 )
F_20 ( V_27 ) ;
}
static void F_21 ( struct V_22 * V_23 ,
struct V_3 * V_37 )
{
struct V_3 * V_38 ;
F_22 () ;
if ( V_37 && ! F_8 ( & V_37 -> V_7 ) )
V_37 = NULL ;
V_38 = F_23 ( V_23 -> V_27 , 1 ) ;
F_24 ( V_23 -> V_27 , V_37 ) ;
if ( ! V_37 )
goto V_8;
V_23 -> V_39 -> V_40 ( V_37 ) ;
F_16 ( V_23 , V_38 ) ;
V_8:
if ( V_38 )
F_20 ( V_38 ) ;
}
static bool
F_25 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_14 & V_41 )
return true ;
return false ;
}
static void F_26 ( const struct V_6 * V_5 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_20 != V_21 ) &&
( V_4 -> V_20 != V_42 ) )
continue;
if ( V_4 -> V_5 == V_5 )
continue;
if ( ! F_27 ( V_4 -> V_5 -> V_35 ,
V_5 -> V_35 ) )
continue;
F_28 ( L_2 ,
V_5 -> V_35 , V_4 -> V_5 -> V_43 ) ;
F_28 ( L_3 ) ;
}
F_9 () ;
}
int F_29 ( struct V_6 * V_19 )
{
const struct V_22 * V_23 = F_30 ( V_19 ) ;
const struct V_3 * V_4 ;
int V_44 = V_45 ;
if ( F_31 ( & V_23 -> V_46 ) )
goto V_8;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_20 != V_21 ) &&
( V_4 -> V_20 != V_42 ) )
continue;
if ( V_4 -> V_19 != V_19 )
continue;
V_44 = F_32 ( int ,
V_4 -> V_5 -> V_47 - V_48 ,
V_44 ) ;
}
F_9 () ;
V_8:
return V_44 ;
}
void F_33 ( struct V_6 * V_19 )
{
int V_44 ;
V_44 = F_29 ( V_19 ) ;
if ( V_19 -> V_47 != V_44 )
V_19 -> V_47 = V_44 ;
}
static void
F_34 ( struct V_3 * V_4 )
{
struct V_22 * V_23 ;
struct V_3 * V_27 = NULL ;
if ( V_4 -> V_20 != V_49 )
goto V_8;
V_23 = F_30 ( V_4 -> V_19 ) ;
V_23 -> V_39 -> V_50 ( V_4 ) ;
V_4 -> V_20 = V_42 ;
V_27 = F_17 ( V_23 ) ;
if ( ! V_27 )
F_21 ( V_23 , V_4 ) ;
F_35 ( V_4 -> V_19 , L_4 ,
V_4 -> V_5 -> V_43 ) ;
F_33 ( V_4 -> V_19 ) ;
V_8:
if ( V_27 )
F_20 ( V_27 ) ;
}
static void
F_36 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_20 != V_21 ) &&
( V_4 -> V_20 != V_42 ) )
return;
V_4 -> V_20 = V_49 ;
F_35 ( V_4 -> V_19 , L_5 ,
V_4 -> V_5 -> V_43 ) ;
F_33 ( V_4 -> V_19 ) ;
}
static int F_37 ( struct V_3 * V_51 ,
struct V_6 * V_52 )
{
int V_10 ;
if ( ! V_52 )
return 0 ;
V_10 = - V_53 ;
if ( V_52 -> V_54 -> V_55 )
V_10 = V_52 -> V_54 -> V_55 ( V_52 , V_51 -> V_5 ) ;
return V_10 ;
}
int F_38 ( struct V_3 * V_4 ,
const char * V_56 )
{
struct V_22 * V_23 ;
struct V_6 * V_19 , * V_52 ;
T_1 V_57 = F_39 ( V_58 ) ;
int V_10 ;
if ( V_4 -> V_20 != V_59 )
goto V_8;
if ( ! F_8 ( & V_4 -> V_7 ) )
goto V_8;
V_19 = F_40 ( & V_13 , V_56 ) ;
if ( ! V_19 ) {
V_19 = F_41 ( V_56 ) ;
if ( ! V_19 ) {
V_10 = - V_60 ;
goto V_61;
}
F_42 ( V_19 ) ;
}
if ( ! F_11 ( V_19 ) ) {
F_43 ( L_6 ,
V_19 -> V_43 ) ;
V_10 = - V_62 ;
goto V_63;
}
V_52 = F_44 ( V_4 -> V_5 ) ;
V_10 = F_37 ( V_4 , V_52 ) ;
if ( V_10 )
goto V_63;
V_4 -> V_19 = V_19 ;
V_23 = F_30 ( V_4 -> V_19 ) ;
V_10 = F_45 ( V_4 -> V_5 , V_19 ) ;
if ( V_10 )
goto V_63;
V_10 = V_23 -> V_39 -> V_64 ( V_4 ) ;
if ( V_10 < 0 )
goto V_65;
V_4 -> V_66 = V_23 -> V_67 ;
V_23 -> V_67 ++ ;
V_4 -> V_20 = V_49 ;
V_10 = F_46 ( V_4 , V_23 -> V_67 ) ;
if ( V_10 < 0 ) {
V_23 -> V_39 -> V_68 ( V_4 ) ;
V_23 -> V_67 -- ;
V_4 -> V_20 = V_59 ;
goto V_65;
}
V_4 -> V_69 . type = V_57 ;
V_4 -> V_69 . V_70 = V_71 ;
V_4 -> V_69 . V_72 = V_4 -> V_5 ;
F_47 ( & V_4 -> V_69 ) ;
F_48 ( & V_4 -> V_73 , 1 ) ;
F_35 ( V_4 -> V_19 , L_7 ,
V_4 -> V_5 -> V_43 ) ;
if ( F_31 ( & V_23 -> V_46 ) &&
V_4 -> V_5 -> V_47 < V_45 + V_48 )
F_35 ( V_4 -> V_19 ,
L_8 ,
V_4 -> V_5 -> V_43 , V_4 -> V_5 -> V_47 ,
V_45 + V_48 ) ;
if ( ! F_31 ( & V_23 -> V_46 ) &&
V_4 -> V_5 -> V_47 < V_45 + V_48 )
F_35 ( V_4 -> V_19 ,
L_9 ,
V_4 -> V_5 -> V_43 , V_4 -> V_5 -> V_47 ,
V_45 + V_48 ) ;
if ( F_25 ( V_4 ) )
F_34 ( V_4 ) ;
else
F_49 ( V_4 -> V_19 ,
L_10 ,
V_4 -> V_5 -> V_43 ) ;
F_50 ( V_4 ) ;
V_8:
return 0 ;
V_65:
F_51 ( V_4 -> V_5 , V_19 ) ;
V_63:
V_4 -> V_19 = NULL ;
F_3 ( V_19 ) ;
V_61:
F_20 ( V_4 ) ;
return V_10 ;
}
void F_52 ( struct V_3 * V_4 ,
enum V_74 V_75 )
{
struct V_22 * V_23 = F_30 ( V_4 -> V_19 ) ;
struct V_3 * V_27 = NULL ;
if ( V_4 -> V_20 == V_21 )
F_36 ( V_4 ) ;
if ( V_4 -> V_20 != V_49 )
goto V_8;
F_35 ( V_4 -> V_19 , L_11 ,
V_4 -> V_5 -> V_43 ) ;
F_53 ( & V_4 -> V_69 ) ;
V_23 -> V_67 -- ;
F_54 ( V_4 , V_23 -> V_67 ) ;
V_27 = F_17 ( V_23 ) ;
if ( V_4 == V_27 ) {
struct V_3 * V_76 ;
V_76 = F_15 ( V_4 -> V_19 ) ;
F_21 ( V_23 , V_76 ) ;
if ( V_76 )
F_20 ( V_76 ) ;
}
V_23 -> V_39 -> V_68 ( V_4 ) ;
V_4 -> V_20 = V_59 ;
F_55 ( V_23 ) ;
F_56 ( V_23 , V_4 ) ;
F_3 ( V_4 -> V_19 ) ;
if ( ! V_23 -> V_67 && V_75 == V_77 )
F_57 ( V_4 -> V_19 ) ;
F_51 ( V_4 -> V_5 , V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_20 ( V_4 ) ;
V_8:
if ( V_27 )
F_20 ( V_27 ) ;
}
static void F_58 ( struct V_78 * V_79 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_79 , struct V_3 ,
V_80 ) ;
F_59 ( & V_4 -> V_81 ) ;
F_20 ( V_4 ) ;
}
static struct V_3 *
F_60 ( struct V_6 * V_5 )
{
struct V_3 * V_4 ;
int V_10 ;
F_22 () ;
V_10 = F_14 ( V_5 ) ;
if ( V_10 != 1 )
goto V_8;
F_42 ( V_5 ) ;
V_4 = F_61 ( sizeof( * V_4 ) , V_82 ) ;
if ( ! V_4 )
goto V_83;
V_10 = F_62 ( & V_4 -> V_81 , V_5 ) ;
if ( V_10 )
goto V_84;
V_4 -> V_66 = - 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_19 = NULL ;
V_4 -> V_20 = V_59 ;
F_63 ( & V_4 -> V_85 ) ;
F_64 ( & V_4 -> V_80 ,
F_58 ) ;
F_48 ( & V_4 -> V_7 , 2 ) ;
F_26 ( V_4 -> V_5 ) ;
F_65 ( & V_4 -> V_85 , & V_86 ) ;
F_48 ( & V_4 -> V_87 . V_88 , 1 ) ;
V_4 -> V_87 . V_89 = NULL ;
return V_4 ;
V_84:
F_4 ( V_4 ) ;
V_83:
F_3 ( V_5 ) ;
V_8:
return NULL ;
}
static void F_66 ( struct V_3 * V_4 )
{
F_22 () ;
if ( V_4 -> V_20 != V_59 )
F_52 ( V_4 ,
V_77 ) ;
if ( V_4 -> V_20 != V_59 )
return;
V_4 -> V_20 = V_90 ;
F_67 ( V_91 , & V_4 -> V_80 ) ;
}
void F_68 ( void )
{
struct V_3 * V_4 , * V_92 ;
F_69 () ;
F_70 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_71 ( & V_4 -> V_85 ) ;
F_66 ( V_4 ) ;
}
F_72 () ;
}
static int F_73 ( struct V_93 * V_94 ,
unsigned long V_95 , void * V_96 )
{
struct V_6 * V_5 = V_96 ;
struct V_3 * V_4 ;
struct V_3 * V_27 = NULL ;
struct V_22 * V_23 ;
if ( F_11 ( V_5 ) && V_95 == V_97 ) {
F_74 ( V_5 ) ;
return V_98 ;
}
V_4 = F_5 ( V_5 ) ;
if ( ! V_4 && V_95 == V_97 )
V_4 = F_60 ( V_5 ) ;
if ( ! V_4 )
goto V_8;
switch ( V_95 ) {
case V_99 :
F_34 ( V_4 ) ;
break;
case V_100 :
case V_101 :
F_36 ( V_4 ) ;
break;
case V_102 :
F_71 ( & V_4 -> V_85 ) ;
F_66 ( V_4 ) ;
break;
case V_103 :
if ( V_4 -> V_19 )
F_33 ( V_4 -> V_19 ) ;
break;
case V_104 :
if ( V_4 -> V_20 == V_59 )
goto V_105;
F_26 ( V_4 -> V_5 ) ;
V_23 = F_30 ( V_4 -> V_19 ) ;
V_23 -> V_39 -> V_50 ( V_4 ) ;
V_27 = F_17 ( V_23 ) ;
if ( ! V_27 )
goto V_105;
if ( V_4 == V_27 )
F_16 ( V_23 , NULL ) ;
break;
default:
break;
}
V_105:
F_20 ( V_4 ) ;
V_8:
if ( V_27 )
F_20 ( V_27 ) ;
return V_98 ;
}
bool F_75 ( int V_12 )
{
struct V_6 * V_6 = NULL ;
bool V_10 = false ;
if ( V_12 == V_106 )
goto V_8;
V_6 = F_12 ( & V_13 , V_12 ) ;
if ( ! V_6 )
goto V_8;
#ifdef F_76
if ( V_6 -> V_107 )
V_10 = true ;
else
#endif
if ( V_6 -> V_108 )
V_10 = true ;
V_8:
if ( V_6 )
F_3 ( V_6 ) ;
return V_10 ;
}
