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
static int F_10 ( const struct V_6 * V_5 )
{
if ( V_5 -> V_9 & V_10 )
return 0 ;
if ( V_5 -> type != V_11 )
return 0 ;
if ( V_5 -> V_12 != V_13 )
return 0 ;
if ( F_11 ( V_5 ) )
return 0 ;
return 1 ;
}
static struct V_3 *
F_12 ( const struct V_6 * V_14 )
{
struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( V_4 -> V_14 != V_14 )
continue;
if ( V_4 -> V_15 == V_16 &&
F_8 ( & V_4 -> V_7 ) )
goto V_8;
}
V_4 = NULL ;
V_8:
F_9 () ;
return V_4 ;
}
static void F_13 ( struct V_17 * V_18 ,
struct V_3 * V_19 )
{
struct V_20 * V_21 ;
struct V_3 * V_22 ;
V_22 = F_14 ( V_18 ) ;
if ( ! V_22 )
goto V_8;
V_21 = (struct V_20 * )
V_18 -> V_23 -> V_24 -> V_25 ;
memcpy ( V_21 -> V_26 , V_22 -> V_5 -> V_27 , V_13 ) ;
memcpy ( V_21 -> V_28 ,
V_22 -> V_5 -> V_27 , V_13 ) ;
F_15 ( V_18 , V_22 , V_19 ) ;
V_8:
if ( V_22 )
F_16 ( V_22 ) ;
}
static void F_17 ( struct V_17 * V_18 ,
struct V_3 * V_29 )
{
struct V_3 * V_30 ;
F_18 () ;
if ( V_29 && ! F_8 ( & V_29 -> V_7 ) )
V_29 = NULL ;
V_30 = F_19 ( V_18 -> V_22 , 1 ) ;
F_20 ( V_18 -> V_22 , V_29 ) ;
if ( ! V_29 )
goto V_8;
V_18 -> V_31 -> V_32 ( V_29 ) ;
F_13 ( V_18 , V_30 ) ;
V_8:
if ( V_30 )
F_16 ( V_30 ) ;
}
static bool
F_21 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_9 & V_33 )
return true ;
return false ;
}
static void F_22 ( const struct V_6 * V_5 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_15 != V_16 ) &&
( V_4 -> V_15 != V_34 ) )
continue;
if ( V_4 -> V_5 == V_5 )
continue;
if ( ! F_23 ( V_4 -> V_5 -> V_27 ,
V_5 -> V_27 ) )
continue;
F_24 ( L_1 ,
V_5 -> V_27 , V_4 -> V_5 -> V_35 ) ;
F_24 ( L_2 ) ;
}
F_9 () ;
}
int F_25 ( struct V_6 * V_14 )
{
const struct V_17 * V_18 = F_26 ( V_14 ) ;
const struct V_3 * V_4 ;
int V_36 = V_37 ;
if ( F_27 ( & V_18 -> V_38 ) )
goto V_8;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_15 != V_16 ) &&
( V_4 -> V_15 != V_34 ) )
continue;
if ( V_4 -> V_14 != V_14 )
continue;
V_36 = F_28 ( int ,
V_4 -> V_5 -> V_39 - V_40 ,
V_36 ) ;
}
F_9 () ;
V_8:
return V_36 ;
}
void F_29 ( struct V_6 * V_14 )
{
int V_36 ;
V_36 = F_25 ( V_14 ) ;
if ( V_14 -> V_39 != V_36 )
V_14 -> V_39 = V_36 ;
}
static void
F_30 ( struct V_3 * V_4 )
{
struct V_17 * V_18 ;
struct V_3 * V_22 = NULL ;
if ( V_4 -> V_15 != V_41 )
goto V_8;
V_18 = F_26 ( V_4 -> V_14 ) ;
V_18 -> V_31 -> V_42 ( V_4 ) ;
V_4 -> V_15 = V_34 ;
V_22 = F_14 ( V_18 ) ;
if ( ! V_22 )
F_17 ( V_18 , V_4 ) ;
F_31 ( V_4 -> V_14 , L_3 ,
V_4 -> V_5 -> V_35 ) ;
F_29 ( V_4 -> V_14 ) ;
V_8:
if ( V_22 )
F_16 ( V_22 ) ;
}
static void
F_32 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_15 != V_16 ) &&
( V_4 -> V_15 != V_34 ) )
return;
V_4 -> V_15 = V_41 ;
F_31 ( V_4 -> V_14 , L_4 ,
V_4 -> V_5 -> V_35 ) ;
F_29 ( V_4 -> V_14 ) ;
}
int F_33 ( struct V_3 * V_4 ,
const char * V_43 )
{
struct V_17 * V_18 ;
struct V_6 * V_14 ;
T_1 V_44 = F_34 ( V_45 ) ;
int V_46 ;
if ( V_4 -> V_15 != V_47 )
goto V_8;
if ( ! F_8 ( & V_4 -> V_7 ) )
goto V_8;
if ( V_4 -> V_5 -> V_48 & V_49 )
F_35 ( L_5 ,
V_4 -> V_5 -> V_35 ) ;
V_14 = F_36 ( & V_50 , V_43 ) ;
if ( ! V_14 ) {
V_14 = F_37 ( V_43 ) ;
if ( ! V_14 ) {
V_46 = - V_51 ;
goto V_52;
}
F_38 ( V_14 ) ;
}
if ( ! F_11 ( V_14 ) ) {
F_35 ( L_6 ,
V_14 -> V_35 ) ;
V_46 = - V_53 ;
goto V_54;
}
V_4 -> V_14 = V_14 ;
V_18 = F_26 ( V_4 -> V_14 ) ;
V_46 = V_18 -> V_31 -> V_55 ( V_4 ) ;
if ( V_46 < 0 )
goto V_54;
V_4 -> V_56 = V_18 -> V_57 ;
V_18 -> V_57 ++ ;
V_4 -> V_15 = V_41 ;
F_39 ( V_4 , V_18 -> V_57 ) ;
V_4 -> V_58 . type = V_44 ;
V_4 -> V_58 . V_59 = V_60 ;
V_4 -> V_58 . V_61 = V_4 -> V_5 ;
F_40 ( & V_4 -> V_58 ) ;
F_41 ( & V_4 -> V_62 , 1 ) ;
F_31 ( V_4 -> V_14 , L_7 ,
V_4 -> V_5 -> V_35 ) ;
if ( F_27 ( & V_18 -> V_38 ) &&
V_4 -> V_5 -> V_39 < V_37 + V_40 )
F_31 ( V_4 -> V_14 ,
L_8 ,
V_4 -> V_5 -> V_35 , V_4 -> V_5 -> V_39 ,
V_37 + V_40 ) ;
if ( ! F_27 ( & V_18 -> V_38 ) &&
V_4 -> V_5 -> V_39 < V_37 + V_40 )
F_31 ( V_4 -> V_14 ,
L_9 ,
V_4 -> V_5 -> V_35 , V_4 -> V_5 -> V_39 ,
V_37 + V_40 ) ;
if ( F_21 ( V_4 ) )
F_30 ( V_4 ) ;
else
F_42 ( V_4 -> V_14 ,
L_10 ,
V_4 -> V_5 -> V_35 ) ;
F_43 ( V_4 ) ;
V_8:
return 0 ;
V_54:
F_3 ( V_14 ) ;
V_52:
F_16 ( V_4 ) ;
return V_46 ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = F_26 ( V_4 -> V_14 ) ;
struct V_3 * V_22 = NULL ;
if ( V_4 -> V_15 == V_16 )
F_32 ( V_4 ) ;
if ( V_4 -> V_15 != V_41 )
goto V_8;
F_31 ( V_4 -> V_14 , L_11 ,
V_4 -> V_5 -> V_35 ) ;
F_45 ( & V_4 -> V_58 ) ;
V_18 -> V_57 -- ;
F_46 ( V_4 , V_18 -> V_57 ) ;
V_22 = F_14 ( V_18 ) ;
if ( V_4 == V_22 ) {
struct V_3 * V_63 ;
V_63 = F_12 ( V_4 -> V_14 ) ;
F_17 ( V_18 , V_63 ) ;
if ( V_63 )
F_16 ( V_63 ) ;
}
V_18 -> V_31 -> V_64 ( V_4 ) ;
V_4 -> V_15 = V_47 ;
F_47 ( V_18 ) ;
F_48 ( V_18 , V_4 ) ;
F_3 ( V_4 -> V_14 ) ;
if ( ! V_18 -> V_57 )
F_49 ( V_4 -> V_14 ) ;
V_4 -> V_14 = NULL ;
F_16 ( V_4 ) ;
V_8:
if ( V_22 )
F_16 ( V_22 ) ;
}
static struct V_3 *
F_50 ( struct V_6 * V_5 )
{
struct V_3 * V_4 ;
int V_46 ;
F_18 () ;
V_46 = F_10 ( V_5 ) ;
if ( V_46 != 1 )
goto V_8;
F_38 ( V_5 ) ;
V_4 = F_51 ( sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 )
goto V_66;
V_46 = F_52 ( & V_4 -> V_67 , V_5 ) ;
if ( V_46 )
goto V_68;
V_4 -> V_56 = - 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_14 = NULL ;
V_4 -> V_15 = V_47 ;
F_53 ( & V_4 -> V_69 ) ;
F_41 ( & V_4 -> V_7 , 2 ) ;
F_22 ( V_4 -> V_5 ) ;
F_54 ( & V_4 -> V_69 , & V_70 ) ;
F_41 ( & V_4 -> V_71 , 1 ) ;
V_4 -> V_72 = NULL ;
return V_4 ;
V_68:
F_4 ( V_4 ) ;
V_66:
F_3 ( V_5 ) ;
V_8:
return NULL ;
}
static void F_55 ( struct V_3 * V_4 )
{
F_18 () ;
if ( V_4 -> V_15 != V_47 )
F_44 ( V_4 ) ;
if ( V_4 -> V_15 != V_47 )
return;
V_4 -> V_15 = V_73 ;
F_56 ( & V_4 -> V_67 ) ;
F_16 ( V_4 ) ;
}
void F_57 ( void )
{
struct V_3 * V_4 , * V_74 ;
F_58 () ;
F_59 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_60 ( & V_4 -> V_69 ) ;
F_55 ( V_4 ) ;
}
F_61 () ;
}
static int F_62 ( struct V_75 * V_76 ,
unsigned long V_77 , void * V_78 )
{
struct V_6 * V_5 = V_78 ;
struct V_3 * V_4 ;
struct V_3 * V_22 = NULL ;
struct V_17 * V_18 ;
V_4 = F_5 ( V_5 ) ;
if ( ! V_4 && V_77 == V_79 )
V_4 = F_50 ( V_5 ) ;
if ( ! V_4 )
goto V_8;
switch ( V_77 ) {
case V_80 :
F_30 ( V_4 ) ;
break;
case V_81 :
case V_82 :
F_32 ( V_4 ) ;
break;
case V_83 :
F_60 ( & V_4 -> V_69 ) ;
F_55 ( V_4 ) ;
break;
case V_84 :
if ( V_4 -> V_14 )
F_29 ( V_4 -> V_14 ) ;
break;
case V_85 :
if ( V_4 -> V_15 == V_47 )
goto V_86;
F_22 ( V_4 -> V_5 ) ;
V_18 = F_26 ( V_4 -> V_14 ) ;
V_18 -> V_31 -> V_42 ( V_4 ) ;
V_22 = F_14 ( V_18 ) ;
if ( ! V_22 )
goto V_86;
if ( V_4 == V_22 )
F_13 ( V_18 , NULL ) ;
break;
default:
break;
}
V_86:
F_16 ( V_4 ) ;
V_8:
if ( V_22 )
F_16 ( V_22 ) ;
return V_87 ;
}
bool F_63 ( int V_88 )
{
struct V_6 * V_6 = NULL ;
bool V_46 = false ;
if ( V_88 == V_89 )
goto V_8;
V_6 = F_64 ( & V_50 , V_88 ) ;
if ( ! V_6 )
goto V_8;
#ifdef F_65
if ( V_6 -> V_90 )
V_46 = true ;
else
#endif
if ( V_6 -> V_91 )
V_46 = true ;
V_8:
if ( V_6 )
F_3 ( V_6 ) ;
return V_46 ;
}
