void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_3 -> V_4 ) ;
F_4 ( V_3 ) ;
}
struct V_3 * F_5 ( const struct V_5 * V_4 )
{
struct V_3 * V_3 ;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( V_3 -> V_4 == V_4 &&
F_8 ( & V_3 -> V_6 ) )
goto V_7;
}
V_3 = NULL ;
V_7:
F_9 () ;
return V_3 ;
}
static int F_10 ( const struct V_5 * V_4 )
{
if ( V_4 -> V_8 & V_9 )
return 0 ;
if ( V_4 -> type != V_10 )
return 0 ;
if ( V_4 -> V_11 != V_12 )
return 0 ;
if ( F_11 ( V_4 ) )
return 0 ;
return 1 ;
}
static struct V_3 * F_12 ( const struct V_5 * V_13 )
{
struct V_3 * V_3 ;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( V_3 -> V_13 != V_13 )
continue;
if ( V_3 -> V_14 == V_15 &&
F_8 ( & V_3 -> V_6 ) )
goto V_7;
}
V_3 = NULL ;
V_7:
F_9 () ;
return V_3 ;
}
static void F_13 ( struct V_16 * V_16 )
{
struct V_17 * V_17 ;
struct V_3 * V_18 ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
goto V_7;
V_17 = (struct V_17 * )
V_16 -> V_19 -> V_20 -> V_21 ;
memcpy ( V_17 -> V_22 , V_18 -> V_4 -> V_23 , V_12 ) ;
memcpy ( V_17 -> V_24 ,
V_18 -> V_4 -> V_23 , V_12 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static void F_16 ( struct V_16 * V_16 ,
struct V_3 * V_25 )
{
struct V_3 * V_26 ;
F_17 () ;
if ( V_25 && ! F_8 ( & V_25 -> V_6 ) )
V_25 = NULL ;
V_26 = F_18 ( V_16 -> V_18 , 1 ) ;
F_19 ( V_16 -> V_18 , V_25 ) ;
if ( V_26 )
F_15 ( V_26 ) ;
if ( ! V_25 )
return;
V_16 -> V_27 -> V_28 ( V_25 ) ;
F_13 ( V_16 ) ;
}
static bool F_20 ( const struct V_3 * V_3 )
{
if ( V_3 -> V_4 -> V_8 & V_29 )
return true ;
return false ;
}
static void F_21 ( const struct V_5 * V_4 )
{
const struct V_3 * V_3 ;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_30 ) )
continue;
if ( V_3 -> V_4 == V_4 )
continue;
if ( ! F_22 ( V_3 -> V_4 -> V_23 ,
V_4 -> V_23 ) )
continue;
F_23 ( L_1 ,
V_4 -> V_23 , V_3 -> V_4 -> V_31 ) ;
F_23 ( L_2 ) ;
}
F_9 () ;
}
int F_24 ( struct V_5 * V_13 )
{
const struct V_16 * V_16 = F_25 ( V_13 ) ;
const struct V_3 * V_3 ;
int V_32 = V_33 ;
if ( F_26 ( & V_16 -> V_34 ) )
goto V_7;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_30 ) )
continue;
if ( V_3 -> V_13 != V_13 )
continue;
V_32 = F_27 ( int , V_3 -> V_4 -> V_35 - V_36 ,
V_32 ) ;
}
F_9 () ;
V_7:
return V_32 ;
}
void F_28 ( struct V_5 * V_13 )
{
int V_32 ;
V_32 = F_24 ( V_13 ) ;
if ( V_13 -> V_35 != V_32 )
V_13 -> V_35 = V_32 ;
}
static void F_29 ( struct V_3 * V_3 )
{
struct V_16 * V_16 ;
struct V_3 * V_18 = NULL ;
if ( V_3 -> V_14 != V_37 )
goto V_7;
V_16 = F_25 ( V_3 -> V_13 ) ;
V_16 -> V_27 -> V_38 ( V_3 ) ;
V_3 -> V_14 = V_30 ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
F_16 ( V_16 , V_3 ) ;
F_30 ( V_3 -> V_13 , L_3 ,
V_3 -> V_4 -> V_31 ) ;
F_28 ( V_3 -> V_13 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static void F_31 ( struct V_3 * V_3 )
{
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_30 ) )
return;
V_3 -> V_14 = V_37 ;
F_30 ( V_3 -> V_13 , L_4 ,
V_3 -> V_4 -> V_31 ) ;
F_28 ( V_3 -> V_13 ) ;
}
int F_32 ( struct V_3 * V_3 ,
const char * V_39 )
{
struct V_16 * V_16 ;
struct V_5 * V_13 ;
int V_40 ;
if ( V_3 -> V_14 != V_41 )
goto V_7;
if ( ! F_8 ( & V_3 -> V_6 ) )
goto V_7;
if ( V_3 -> V_4 -> V_42 & V_43 )
F_33 ( L_5 ,
V_3 -> V_4 -> V_31 ) ;
V_13 = F_34 ( & V_44 , V_39 ) ;
if ( ! V_13 ) {
V_13 = F_35 ( V_39 ) ;
if ( ! V_13 ) {
V_40 = - V_45 ;
goto V_46;
}
F_36 ( V_13 ) ;
}
if ( ! F_11 ( V_13 ) ) {
F_33 ( L_6 ,
V_13 -> V_31 ) ;
F_3 ( V_13 ) ;
V_40 = - V_47 ;
goto V_46;
}
V_3 -> V_13 = V_13 ;
V_16 = F_25 ( V_3 -> V_13 ) ;
V_16 -> V_27 -> V_48 ( V_3 ) ;
if ( ! V_3 -> V_49 ) {
F_37 ( V_3 -> V_13 ,
L_7 ,
V_3 -> V_4 -> V_31 ) ;
V_40 = - V_45 ;
goto V_46;
}
V_3 -> V_50 = V_16 -> V_51 ;
V_16 -> V_51 ++ ;
V_3 -> V_14 = V_37 ;
F_38 ( V_3 , V_16 -> V_51 ) ;
V_3 -> V_52 . type = F_39 ( V_53 ) ;
V_3 -> V_52 . V_54 = V_55 ;
V_3 -> V_52 . V_56 = V_3 -> V_4 ;
F_40 ( & V_3 -> V_52 ) ;
F_41 ( & V_3 -> V_57 , 1 ) ;
F_41 ( & V_3 -> V_58 , 1 ) ;
F_30 ( V_3 -> V_13 , L_8 ,
V_3 -> V_4 -> V_31 ) ;
if ( F_26 ( & V_16 -> V_34 ) && V_3 -> V_4 -> V_35 <
V_33 + V_36 )
F_30 ( V_3 -> V_13 ,
L_9 ,
V_3 -> V_4 -> V_31 , V_3 -> V_4 -> V_35 ,
V_33 + V_36 ) ;
if ( ! F_26 ( & V_16 -> V_34 ) && V_3 -> V_4 -> V_35 <
V_33 + V_36 )
F_30 ( V_3 -> V_13 ,
L_10 ,
V_3 -> V_4 -> V_31 , V_3 -> V_4 -> V_35 ,
V_33 + V_36 ) ;
if ( F_20 ( V_3 ) )
F_29 ( V_3 ) ;
else
F_37 ( V_3 -> V_13 ,
L_11 ,
V_3 -> V_4 -> V_31 ) ;
F_42 ( V_3 ) ;
V_7:
return 0 ;
V_46:
F_15 ( V_3 ) ;
return V_40 ;
}
void F_43 ( struct V_3 * V_3 )
{
struct V_16 * V_16 = F_25 ( V_3 -> V_13 ) ;
struct V_3 * V_18 = NULL ;
if ( V_3 -> V_14 == V_15 )
F_31 ( V_3 ) ;
if ( V_3 -> V_14 != V_37 )
goto V_7;
F_30 ( V_3 -> V_13 , L_12 ,
V_3 -> V_4 -> V_31 ) ;
F_44 ( & V_3 -> V_52 ) ;
V_16 -> V_51 -- ;
F_45 ( V_3 , V_16 -> V_51 ) ;
V_18 = F_14 ( V_16 ) ;
if ( V_3 == V_18 ) {
struct V_3 * V_59 ;
V_59 = F_12 ( V_3 -> V_13 ) ;
F_16 ( V_16 , V_59 ) ;
if ( V_59 )
F_15 ( V_59 ) ;
}
F_4 ( V_3 -> V_49 ) ;
V_3 -> V_49 = NULL ;
V_3 -> V_14 = V_41 ;
F_46 ( V_16 ) ;
F_47 ( V_16 , V_3 ) ;
F_3 ( V_3 -> V_13 ) ;
if ( ! V_16 -> V_51 )
F_48 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_15 ( V_3 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static struct V_3 * F_49 ( struct V_5 * V_4 )
{
struct V_3 * V_3 ;
int V_40 ;
F_17 () ;
V_40 = F_10 ( V_4 ) ;
if ( V_40 != 1 )
goto V_7;
F_36 ( V_4 ) ;
V_3 = F_50 ( sizeof( * V_3 ) , V_60 ) ;
if ( ! V_3 )
goto V_61;
V_40 = F_51 ( & V_3 -> V_62 , V_4 ) ;
if ( V_40 )
goto V_63;
V_3 -> V_50 = - 1 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_13 = NULL ;
V_3 -> V_14 = V_41 ;
F_52 ( & V_3 -> V_64 ) ;
F_41 ( & V_3 -> V_6 , 2 ) ;
F_21 ( V_3 -> V_4 ) ;
F_53 ( & V_3 -> V_64 , & V_65 ) ;
return V_3 ;
V_63:
F_4 ( V_3 ) ;
V_61:
F_3 ( V_4 ) ;
V_7:
return NULL ;
}
static void F_54 ( struct V_3 * V_3 )
{
F_17 () ;
if ( V_3 -> V_14 != V_41 )
F_43 ( V_3 ) ;
if ( V_3 -> V_14 != V_41 )
return;
V_3 -> V_14 = V_66 ;
F_55 ( & V_3 -> V_62 ) ;
F_15 ( V_3 ) ;
}
void F_56 ( void )
{
struct V_3 * V_3 , * V_67 ;
F_57 () ;
F_58 (hard_iface, hard_iface_tmp,
&hardif_list, list) {
F_59 ( & V_3 -> V_64 ) ;
F_54 ( V_3 ) ;
}
F_60 () ;
}
static int F_61 ( struct V_68 * V_69 ,
unsigned long V_70 , void * V_71 )
{
struct V_5 * V_4 = V_71 ;
struct V_3 * V_3 = F_5 ( V_4 ) ;
struct V_3 * V_18 = NULL ;
struct V_16 * V_16 ;
if ( ! V_3 && V_70 == V_72 )
V_3 = F_49 ( V_4 ) ;
if ( ! V_3 )
goto V_7;
switch ( V_70 ) {
case V_73 :
F_29 ( V_3 ) ;
break;
case V_74 :
case V_75 :
F_31 ( V_3 ) ;
break;
case V_76 :
F_59 ( & V_3 -> V_64 ) ;
F_54 ( V_3 ) ;
break;
case V_77 :
if ( V_3 -> V_13 )
F_28 ( V_3 -> V_13 ) ;
break;
case V_78 :
if ( V_3 -> V_14 == V_41 )
goto V_79;
F_21 ( V_3 -> V_4 ) ;
V_16 = F_25 ( V_3 -> V_13 ) ;
V_16 -> V_27 -> V_38 ( V_3 ) ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
goto V_79;
if ( V_3 == V_18 )
F_13 ( V_16 ) ;
break;
default:
break;
}
V_79:
F_15 ( V_3 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
return V_80 ;
}
static int V_55 ( struct V_81 * V_82 , struct V_5 * V_56 ,
struct V_83 * V_84 ,
struct V_5 * V_85 )
{
struct V_16 * V_16 ;
struct V_86 * V_86 ;
struct V_3 * V_3 ;
int V_40 ;
V_3 = F_2 ( V_84 , struct V_3 , V_52 ) ;
V_82 = F_62 ( V_82 , V_60 ) ;
if ( ! V_82 )
goto V_87;
if ( F_63 ( ! F_64 ( V_82 , 2 ) ) )
goto V_88;
if ( F_63 ( V_82 -> V_89 != sizeof( struct V_90 ) ||
! F_65 ( V_82 ) ) )
goto V_88;
if ( ! V_3 -> V_13 )
goto V_88;
V_16 = F_25 ( V_3 -> V_13 ) ;
if ( F_26 ( & V_16 -> V_91 ) != V_92 )
goto V_88;
if ( V_3 -> V_14 != V_15 )
goto V_88;
V_86 = (struct V_86 * ) V_82 -> V_21 ;
if ( V_86 -> V_93 . V_94 != V_95 ) {
F_66 ( V_96 , V_16 ,
L_13 ,
V_86 -> V_93 . V_94 ) ;
goto V_88;
}
switch ( V_86 -> V_93 . V_83 ) {
case V_97 :
V_40 = F_67 ( V_82 , V_3 ) ;
break;
case V_98 :
V_40 = F_68 ( V_82 , V_3 ) ;
break;
case V_99 :
V_40 = F_69 ( V_82 , V_3 ) ;
break;
case V_100 :
V_40 = F_70 ( V_82 , V_3 ) ;
break;
case V_101 :
V_40 = F_71 ( V_82 , V_3 ) ;
break;
case V_102 :
V_40 = F_72 ( V_82 , V_3 ) ;
break;
case V_103 :
V_40 = F_73 ( V_82 , V_3 ) ;
break;
case V_104 :
V_40 = F_74 ( V_82 , V_3 ) ;
break;
default:
V_40 = V_105 ;
}
if ( V_40 == V_105 )
F_75 ( V_82 ) ;
return V_106 ;
V_88:
F_75 ( V_82 ) ;
V_87:
return V_105 ;
}
bool F_76 ( int V_107 )
{
struct V_5 * V_5 = NULL ;
bool V_40 = false ;
if ( V_107 == V_108 )
goto V_7;
V_5 = F_77 ( & V_44 , V_107 ) ;
if ( ! V_5 )
goto V_7;
#ifdef F_78
if ( V_5 -> V_109 )
V_40 = true ;
else
#endif
if ( V_5 -> V_110 )
V_40 = true ;
V_7:
if ( V_5 )
F_3 ( V_5 ) ;
return V_40 ;
}
