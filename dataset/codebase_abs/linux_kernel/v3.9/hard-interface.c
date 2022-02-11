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
int F_37 ( struct V_3 * V_4 ,
const char * V_51 )
{
struct V_22 * V_23 ;
struct V_6 * V_19 ;
T_1 V_52 = F_38 ( V_53 ) ;
int V_10 ;
if ( V_4 -> V_20 != V_54 )
goto V_8;
if ( ! F_8 ( & V_4 -> V_7 ) )
goto V_8;
if ( V_4 -> V_5 -> V_55 & V_56 )
F_39 ( L_6 ,
V_4 -> V_5 -> V_43 ) ;
V_19 = F_40 ( & V_13 , V_51 ) ;
if ( ! V_19 ) {
V_19 = F_41 ( V_51 ) ;
if ( ! V_19 ) {
V_10 = - V_57 ;
goto V_58;
}
F_42 ( V_19 ) ;
}
if ( ! F_11 ( V_19 ) ) {
F_39 ( L_7 ,
V_19 -> V_43 ) ;
V_10 = - V_59 ;
goto V_60;
}
V_4 -> V_19 = V_19 ;
V_23 = F_30 ( V_4 -> V_19 ) ;
V_10 = V_23 -> V_39 -> V_61 ( V_4 ) ;
if ( V_10 < 0 )
goto V_60;
V_4 -> V_62 = V_23 -> V_63 ;
V_23 -> V_63 ++ ;
V_4 -> V_20 = V_49 ;
V_10 = F_43 ( V_4 , V_23 -> V_63 ) ;
if ( V_10 < 0 ) {
V_23 -> V_39 -> V_64 ( V_4 ) ;
V_23 -> V_63 -- ;
V_4 -> V_20 = V_54 ;
goto V_60;
}
V_4 -> V_65 . type = V_52 ;
V_4 -> V_65 . V_66 = V_67 ;
V_4 -> V_65 . V_68 = V_4 -> V_5 ;
F_44 ( & V_4 -> V_65 ) ;
F_45 ( & V_4 -> V_69 , 1 ) ;
F_35 ( V_4 -> V_19 , L_8 ,
V_4 -> V_5 -> V_43 ) ;
if ( F_31 ( & V_23 -> V_46 ) &&
V_4 -> V_5 -> V_47 < V_45 + V_48 )
F_35 ( V_4 -> V_19 ,
L_9 ,
V_4 -> V_5 -> V_43 , V_4 -> V_5 -> V_47 ,
V_45 + V_48 ) ;
if ( ! F_31 ( & V_23 -> V_46 ) &&
V_4 -> V_5 -> V_47 < V_45 + V_48 )
F_35 ( V_4 -> V_19 ,
L_10 ,
V_4 -> V_5 -> V_43 , V_4 -> V_5 -> V_47 ,
V_45 + V_48 ) ;
if ( F_25 ( V_4 ) )
F_34 ( V_4 ) ;
else
F_46 ( V_4 -> V_19 ,
L_11 ,
V_4 -> V_5 -> V_43 ) ;
F_47 ( V_4 ) ;
V_8:
return 0 ;
V_60:
F_3 ( V_19 ) ;
V_58:
F_20 ( V_4 ) ;
return V_10 ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = F_30 ( V_4 -> V_19 ) ;
struct V_3 * V_27 = NULL ;
if ( V_4 -> V_20 == V_21 )
F_36 ( V_4 ) ;
if ( V_4 -> V_20 != V_49 )
goto V_8;
F_35 ( V_4 -> V_19 , L_12 ,
V_4 -> V_5 -> V_43 ) ;
F_49 ( & V_4 -> V_65 ) ;
V_23 -> V_63 -- ;
F_50 ( V_4 , V_23 -> V_63 ) ;
V_27 = F_17 ( V_23 ) ;
if ( V_4 == V_27 ) {
struct V_3 * V_70 ;
V_70 = F_15 ( V_4 -> V_19 ) ;
F_21 ( V_23 , V_70 ) ;
if ( V_70 )
F_20 ( V_70 ) ;
}
V_23 -> V_39 -> V_64 ( V_4 ) ;
V_4 -> V_20 = V_54 ;
F_51 ( V_23 ) ;
F_52 ( V_23 , V_4 ) ;
F_3 ( V_4 -> V_19 ) ;
if ( ! V_23 -> V_63 )
F_53 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_20 ( V_4 ) ;
V_8:
if ( V_27 )
F_20 ( V_27 ) ;
}
static void F_54 ( struct V_71 * V_72 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_72 , struct V_3 ,
V_73 ) ;
F_55 ( & V_4 -> V_74 ) ;
F_20 ( V_4 ) ;
}
static struct V_3 *
F_56 ( struct V_6 * V_5 )
{
struct V_3 * V_4 ;
int V_10 ;
F_22 () ;
V_10 = F_14 ( V_5 ) ;
if ( V_10 != 1 )
goto V_8;
F_42 ( V_5 ) ;
V_4 = F_57 ( sizeof( * V_4 ) , V_75 ) ;
if ( ! V_4 )
goto V_76;
V_10 = F_58 ( & V_4 -> V_74 , V_5 ) ;
if ( V_10 )
goto V_77;
V_4 -> V_62 = - 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_19 = NULL ;
V_4 -> V_20 = V_54 ;
F_59 ( & V_4 -> V_78 ) ;
F_60 ( & V_4 -> V_73 ,
F_54 ) ;
F_45 ( & V_4 -> V_7 , 2 ) ;
F_26 ( V_4 -> V_5 ) ;
F_61 ( & V_4 -> V_78 , & V_79 ) ;
F_45 ( & V_4 -> V_80 . V_81 , 1 ) ;
V_4 -> V_80 . V_82 = NULL ;
return V_4 ;
V_77:
F_4 ( V_4 ) ;
V_76:
F_3 ( V_5 ) ;
V_8:
return NULL ;
}
static void F_62 ( struct V_3 * V_4 )
{
F_22 () ;
if ( V_4 -> V_20 != V_54 )
F_48 ( V_4 ) ;
if ( V_4 -> V_20 != V_54 )
return;
V_4 -> V_20 = V_83 ;
F_63 ( V_84 , & V_4 -> V_73 ) ;
}
void F_64 ( void )
{
struct V_3 * V_4 , * V_85 ;
F_65 () ;
F_66 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_67 ( & V_4 -> V_78 ) ;
F_62 ( V_4 ) ;
}
F_68 () ;
}
static int F_69 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
struct V_6 * V_5 = V_89 ;
struct V_3 * V_4 ;
struct V_3 * V_27 = NULL ;
struct V_22 * V_23 ;
V_4 = F_5 ( V_5 ) ;
if ( ! V_4 && V_88 == V_90 )
V_4 = F_56 ( V_5 ) ;
if ( ! V_4 )
goto V_8;
switch ( V_88 ) {
case V_91 :
F_34 ( V_4 ) ;
break;
case V_92 :
case V_93 :
F_36 ( V_4 ) ;
break;
case V_94 :
F_67 ( & V_4 -> V_78 ) ;
F_62 ( V_4 ) ;
break;
case V_95 :
if ( V_4 -> V_19 )
F_33 ( V_4 -> V_19 ) ;
break;
case V_96 :
if ( V_4 -> V_20 == V_54 )
goto V_97;
F_26 ( V_4 -> V_5 ) ;
V_23 = F_30 ( V_4 -> V_19 ) ;
V_23 -> V_39 -> V_50 ( V_4 ) ;
V_27 = F_17 ( V_23 ) ;
if ( ! V_27 )
goto V_97;
if ( V_4 == V_27 )
F_16 ( V_23 , NULL ) ;
break;
default:
break;
}
V_97:
F_20 ( V_4 ) ;
V_8:
if ( V_27 )
F_20 ( V_27 ) ;
return V_98 ;
}
bool F_70 ( int V_12 )
{
struct V_6 * V_6 = NULL ;
bool V_10 = false ;
if ( V_12 == V_99 )
goto V_8;
V_6 = F_12 ( & V_13 , V_12 ) ;
if ( ! V_6 )
goto V_8;
#ifdef F_71
if ( V_6 -> V_100 )
V_10 = true ;
else
#endif
if ( V_6 -> V_101 )
V_10 = true ;
V_8:
if ( V_6 )
F_3 ( V_6 ) ;
return V_10 ;
}
