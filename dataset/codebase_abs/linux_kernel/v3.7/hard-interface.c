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
struct V_23 * V_24 ;
V_22 = F_14 ( V_18 ) ;
if ( ! V_22 )
goto V_8;
V_24 = V_18 -> V_25 . V_26 -> V_27 ;
V_21 = (struct V_20 * ) V_24 -> V_28 ;
memcpy ( V_21 -> V_29 , V_22 -> V_5 -> V_30 , V_13 ) ;
memcpy ( V_21 -> V_31 ,
V_22 -> V_5 -> V_30 , V_13 ) ;
F_15 ( V_18 , V_22 , V_19 ) ;
V_8:
if ( V_22 )
F_16 ( V_22 ) ;
}
static void F_17 ( struct V_17 * V_18 ,
struct V_3 * V_32 )
{
struct V_3 * V_33 ;
F_18 () ;
if ( V_32 && ! F_8 ( & V_32 -> V_7 ) )
V_32 = NULL ;
V_33 = F_19 ( V_18 -> V_22 , 1 ) ;
F_20 ( V_18 -> V_22 , V_32 ) ;
if ( ! V_32 )
goto V_8;
V_18 -> V_34 -> V_35 ( V_32 ) ;
F_13 ( V_18 , V_33 ) ;
V_8:
if ( V_33 )
F_16 ( V_33 ) ;
}
static bool
F_21 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_9 & V_36 )
return true ;
return false ;
}
static void F_22 ( const struct V_6 * V_5 )
{
const struct V_3 * V_4 ;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_15 != V_16 ) &&
( V_4 -> V_15 != V_37 ) )
continue;
if ( V_4 -> V_5 == V_5 )
continue;
if ( ! F_23 ( V_4 -> V_5 -> V_30 ,
V_5 -> V_30 ) )
continue;
F_24 ( L_1 ,
V_5 -> V_30 , V_4 -> V_5 -> V_38 ) ;
F_24 ( L_2 ) ;
}
F_9 () ;
}
int F_25 ( struct V_6 * V_14 )
{
const struct V_17 * V_18 = F_26 ( V_14 ) ;
const struct V_3 * V_4 ;
int V_39 = V_40 ;
if ( F_27 ( & V_18 -> V_41 ) )
goto V_8;
F_6 () ;
F_7 (hard_iface, &batadv_hardif_list, list) {
if ( ( V_4 -> V_15 != V_16 ) &&
( V_4 -> V_15 != V_37 ) )
continue;
if ( V_4 -> V_14 != V_14 )
continue;
V_39 = F_28 ( int ,
V_4 -> V_5 -> V_42 - V_43 ,
V_39 ) ;
}
F_9 () ;
V_8:
return V_39 ;
}
void F_29 ( struct V_6 * V_14 )
{
int V_39 ;
V_39 = F_25 ( V_14 ) ;
if ( V_14 -> V_42 != V_39 )
V_14 -> V_42 = V_39 ;
}
static void
F_30 ( struct V_3 * V_4 )
{
struct V_17 * V_18 ;
struct V_3 * V_22 = NULL ;
if ( V_4 -> V_15 != V_44 )
goto V_8;
V_18 = F_26 ( V_4 -> V_14 ) ;
V_18 -> V_34 -> V_45 ( V_4 ) ;
V_4 -> V_15 = V_37 ;
V_22 = F_14 ( V_18 ) ;
if ( ! V_22 )
F_17 ( V_18 , V_4 ) ;
F_31 ( V_4 -> V_14 , L_3 ,
V_4 -> V_5 -> V_38 ) ;
F_29 ( V_4 -> V_14 ) ;
V_8:
if ( V_22 )
F_16 ( V_22 ) ;
}
static void
F_32 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_15 != V_16 ) &&
( V_4 -> V_15 != V_37 ) )
return;
V_4 -> V_15 = V_44 ;
F_31 ( V_4 -> V_14 , L_4 ,
V_4 -> V_5 -> V_38 ) ;
F_29 ( V_4 -> V_14 ) ;
}
int F_33 ( struct V_3 * V_4 ,
const char * V_46 )
{
struct V_17 * V_18 ;
struct V_6 * V_14 ;
T_1 V_47 = F_34 ( V_48 ) ;
int V_49 ;
if ( V_4 -> V_15 != V_50 )
goto V_8;
if ( ! F_8 ( & V_4 -> V_7 ) )
goto V_8;
if ( V_4 -> V_5 -> V_51 & V_52 )
F_35 ( L_5 ,
V_4 -> V_5 -> V_38 ) ;
V_14 = F_36 ( & V_53 , V_46 ) ;
if ( ! V_14 ) {
V_14 = F_37 ( V_46 ) ;
if ( ! V_14 ) {
V_49 = - V_54 ;
goto V_55;
}
F_38 ( V_14 ) ;
}
if ( ! F_11 ( V_14 ) ) {
F_35 ( L_6 ,
V_14 -> V_38 ) ;
V_49 = - V_56 ;
goto V_57;
}
V_4 -> V_14 = V_14 ;
V_18 = F_26 ( V_4 -> V_14 ) ;
V_49 = V_18 -> V_34 -> V_58 ( V_4 ) ;
if ( V_49 < 0 )
goto V_57;
V_4 -> V_59 = V_18 -> V_60 ;
V_18 -> V_60 ++ ;
V_4 -> V_15 = V_44 ;
V_49 = F_39 ( V_4 , V_18 -> V_60 ) ;
if ( V_49 < 0 ) {
V_18 -> V_34 -> V_61 ( V_4 ) ;
V_18 -> V_60 -- ;
V_4 -> V_15 = V_50 ;
goto V_57;
}
V_4 -> V_62 . type = V_47 ;
V_4 -> V_62 . V_63 = V_64 ;
V_4 -> V_62 . V_65 = V_4 -> V_5 ;
F_40 ( & V_4 -> V_62 ) ;
F_41 ( & V_4 -> V_66 , 1 ) ;
F_31 ( V_4 -> V_14 , L_7 ,
V_4 -> V_5 -> V_38 ) ;
if ( F_27 ( & V_18 -> V_41 ) &&
V_4 -> V_5 -> V_42 < V_40 + V_43 )
F_31 ( V_4 -> V_14 ,
L_8 ,
V_4 -> V_5 -> V_38 , V_4 -> V_5 -> V_42 ,
V_40 + V_43 ) ;
if ( ! F_27 ( & V_18 -> V_41 ) &&
V_4 -> V_5 -> V_42 < V_40 + V_43 )
F_31 ( V_4 -> V_14 ,
L_9 ,
V_4 -> V_5 -> V_38 , V_4 -> V_5 -> V_42 ,
V_40 + V_43 ) ;
if ( F_21 ( V_4 ) )
F_30 ( V_4 ) ;
else
F_42 ( V_4 -> V_14 ,
L_10 ,
V_4 -> V_5 -> V_38 ) ;
F_43 ( V_4 ) ;
V_8:
return 0 ;
V_57:
F_3 ( V_14 ) ;
V_55:
F_16 ( V_4 ) ;
return V_49 ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = F_26 ( V_4 -> V_14 ) ;
struct V_3 * V_22 = NULL ;
if ( V_4 -> V_15 == V_16 )
F_32 ( V_4 ) ;
if ( V_4 -> V_15 != V_44 )
goto V_8;
F_31 ( V_4 -> V_14 , L_11 ,
V_4 -> V_5 -> V_38 ) ;
F_45 ( & V_4 -> V_62 ) ;
V_18 -> V_60 -- ;
F_46 ( V_4 , V_18 -> V_60 ) ;
V_22 = F_14 ( V_18 ) ;
if ( V_4 == V_22 ) {
struct V_3 * V_67 ;
V_67 = F_12 ( V_4 -> V_14 ) ;
F_17 ( V_18 , V_67 ) ;
if ( V_67 )
F_16 ( V_67 ) ;
}
V_18 -> V_34 -> V_61 ( V_4 ) ;
V_4 -> V_15 = V_50 ;
F_47 ( V_18 ) ;
F_48 ( V_18 , V_4 ) ;
F_3 ( V_4 -> V_14 ) ;
if ( ! V_18 -> V_60 )
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
int V_49 ;
F_18 () ;
V_49 = F_10 ( V_5 ) ;
if ( V_49 != 1 )
goto V_8;
F_38 ( V_5 ) ;
V_4 = F_51 ( sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 )
goto V_69;
V_49 = F_52 ( & V_4 -> V_70 , V_5 ) ;
if ( V_49 )
goto V_71;
V_4 -> V_59 = - 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_14 = NULL ;
V_4 -> V_15 = V_50 ;
F_53 ( & V_4 -> V_72 ) ;
F_41 ( & V_4 -> V_7 , 2 ) ;
F_22 ( V_4 -> V_5 ) ;
F_54 ( & V_4 -> V_72 , & V_73 ) ;
F_41 ( & V_4 -> V_74 , 1 ) ;
V_4 -> V_75 = NULL ;
return V_4 ;
V_71:
F_4 ( V_4 ) ;
V_69:
F_3 ( V_5 ) ;
V_8:
return NULL ;
}
static void F_55 ( struct V_3 * V_4 )
{
F_18 () ;
if ( V_4 -> V_15 != V_50 )
F_44 ( V_4 ) ;
if ( V_4 -> V_15 != V_50 )
return;
V_4 -> V_15 = V_76 ;
F_56 ( & V_4 -> V_70 ) ;
F_16 ( V_4 ) ;
}
void F_57 ( void )
{
struct V_3 * V_4 , * V_77 ;
F_58 () ;
F_59 (hard_iface, hard_iface_tmp,
&batadv_hardif_list, list) {
F_60 ( & V_4 -> V_72 ) ;
F_55 ( V_4 ) ;
}
F_61 () ;
}
static int F_62 ( struct V_78 * V_79 ,
unsigned long V_80 , void * V_81 )
{
struct V_6 * V_5 = V_81 ;
struct V_3 * V_4 ;
struct V_3 * V_22 = NULL ;
struct V_17 * V_18 ;
V_4 = F_5 ( V_5 ) ;
if ( ! V_4 && V_80 == V_82 )
V_4 = F_50 ( V_5 ) ;
if ( ! V_4 )
goto V_8;
switch ( V_80 ) {
case V_83 :
F_30 ( V_4 ) ;
break;
case V_84 :
case V_85 :
F_32 ( V_4 ) ;
break;
case V_86 :
F_60 ( & V_4 -> V_72 ) ;
F_55 ( V_4 ) ;
break;
case V_87 :
if ( V_4 -> V_14 )
F_29 ( V_4 -> V_14 ) ;
break;
case V_88 :
if ( V_4 -> V_15 == V_50 )
goto V_89;
F_22 ( V_4 -> V_5 ) ;
V_18 = F_26 ( V_4 -> V_14 ) ;
V_18 -> V_34 -> V_45 ( V_4 ) ;
V_22 = F_14 ( V_18 ) ;
if ( ! V_22 )
goto V_89;
if ( V_4 == V_22 )
F_13 ( V_18 , NULL ) ;
break;
default:
break;
}
V_89:
F_16 ( V_4 ) ;
V_8:
if ( V_22 )
F_16 ( V_22 ) ;
return V_90 ;
}
bool F_63 ( int V_91 )
{
struct V_6 * V_6 = NULL ;
bool V_49 = false ;
if ( V_91 == V_92 )
goto V_8;
V_6 = F_64 ( & V_53 , V_91 ) ;
if ( ! V_6 )
goto V_8;
#ifdef F_65
if ( V_6 -> V_93 )
V_49 = true ;
else
#endif
if ( V_6 -> V_94 )
V_49 = true ;
V_8:
if ( V_6 )
F_3 ( V_6 ) ;
return V_49 ;
}
