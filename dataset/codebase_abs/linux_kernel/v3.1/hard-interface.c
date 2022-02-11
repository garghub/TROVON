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
struct V_27 * V_27 ;
F_17 () ;
if ( V_25 && ! F_8 ( & V_25 -> V_6 ) )
V_25 = NULL ;
V_26 = F_18 ( V_16 -> V_18 , 1 ) ;
F_19 ( V_16 -> V_18 , V_25 ) ;
if ( V_26 )
F_15 ( V_26 ) ;
if ( ! V_25 )
return;
V_27 = (struct V_27 * ) ( V_25 -> V_28 ) ;
V_27 -> V_8 = V_29 ;
V_27 -> V_30 = V_31 ;
F_13 ( V_16 ) ;
}
static bool F_20 ( const struct V_3 * V_3 )
{
if ( V_3 -> V_4 -> V_8 & V_32 )
return true ;
return false ;
}
static void F_21 ( struct V_3 * V_3 )
{
memcpy ( ( (struct V_27 * ) ( V_3 -> V_28 ) ) -> V_33 ,
V_3 -> V_4 -> V_23 , V_12 ) ;
memcpy ( ( (struct V_27 * ) ( V_3 -> V_28 ) ) -> V_34 ,
V_3 -> V_4 -> V_23 , V_12 ) ;
}
static void F_22 ( const struct V_5 * V_4 )
{
const struct V_3 * V_3 ;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_35 ) )
continue;
if ( V_3 -> V_4 == V_4 )
continue;
if ( ! F_23 ( V_3 -> V_4 -> V_23 ,
V_4 -> V_23 ) )
continue;
F_24 ( L_1
L_2 , V_4 -> V_23 ,
V_3 -> V_4 -> V_36 ) ;
F_24 ( L_3
L_4 ) ;
}
F_9 () ;
}
int F_25 ( struct V_5 * V_13 )
{
const struct V_16 * V_16 = F_26 ( V_13 ) ;
const struct V_3 * V_3 ;
int V_37 = V_38 ;
if ( F_27 ( & V_16 -> V_39 ) )
goto V_7;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_35 ) )
continue;
if ( V_3 -> V_13 != V_13 )
continue;
V_37 = F_28 ( int , V_3 -> V_4 -> V_40 - V_41 ,
V_37 ) ;
}
F_9 () ;
V_7:
return V_37 ;
}
void F_29 ( struct V_5 * V_13 )
{
int V_37 ;
V_37 = F_25 ( V_13 ) ;
if ( V_13 -> V_40 != V_37 )
V_13 -> V_40 = V_37 ;
}
static void F_30 ( struct V_3 * V_3 )
{
struct V_16 * V_16 ;
struct V_3 * V_18 = NULL ;
if ( V_3 -> V_14 != V_42 )
goto V_7;
V_16 = F_26 ( V_3 -> V_13 ) ;
F_21 ( V_3 ) ;
V_3 -> V_14 = V_35 ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
F_16 ( V_16 , V_3 ) ;
F_31 ( V_3 -> V_13 , L_5 ,
V_3 -> V_4 -> V_36 ) ;
F_29 ( V_3 -> V_13 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static void F_32 ( struct V_3 * V_3 )
{
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_35 ) )
return;
V_3 -> V_14 = V_42 ;
F_31 ( V_3 -> V_13 , L_6 ,
V_3 -> V_4 -> V_36 ) ;
F_29 ( V_3 -> V_13 ) ;
}
int F_33 ( struct V_3 * V_3 ,
const char * V_43 )
{
struct V_16 * V_16 ;
struct V_27 * V_27 ;
struct V_5 * V_13 ;
int V_44 ;
if ( V_3 -> V_14 != V_45 )
goto V_7;
if ( ! F_8 ( & V_3 -> V_6 ) )
goto V_7;
V_13 = F_34 ( & V_46 , V_43 ) ;
if ( ! V_13 ) {
V_13 = F_35 ( V_43 ) ;
if ( ! V_13 ) {
V_44 = - V_47 ;
goto V_48;
}
F_36 ( V_13 ) ;
}
if ( ! F_11 ( V_13 ) ) {
F_37 ( L_7
L_8 ,
V_13 -> V_36 ) ;
F_3 ( V_13 ) ;
V_44 = - V_49 ;
goto V_48;
}
V_3 -> V_13 = V_13 ;
V_16 = F_26 ( V_3 -> V_13 ) ;
V_3 -> V_50 = V_51 ;
V_3 -> V_28 = F_38 ( V_3 -> V_50 , V_52 ) ;
if ( ! V_3 -> V_28 ) {
F_39 ( V_3 -> V_13 , L_9
L_10 , V_3 -> V_4 -> V_36 ) ;
V_44 = - V_47 ;
goto V_48;
}
V_27 = (struct V_27 * ) ( V_3 -> V_28 ) ;
V_27 -> V_53 = V_54 ;
V_27 -> V_55 = V_56 ;
V_27 -> V_8 = V_57 ;
V_27 -> V_30 = 2 ;
V_27 -> V_58 = V_59 ;
V_27 -> V_60 = 0 ;
V_27 -> V_61 = 0 ;
V_3 -> V_62 = V_16 -> V_63 ;
V_16 -> V_63 ++ ;
V_3 -> V_14 = V_42 ;
F_40 ( V_3 , V_16 -> V_63 ) ;
V_3 -> V_64 . type = F_41 ( V_65 ) ;
V_3 -> V_64 . V_66 = V_67 ;
V_3 -> V_64 . V_68 = V_3 -> V_4 ;
F_42 ( & V_3 -> V_64 ) ;
F_43 ( & V_3 -> V_69 , 1 ) ;
F_43 ( & V_3 -> V_70 , 1 ) ;
F_31 ( V_3 -> V_13 , L_11 ,
V_3 -> V_4 -> V_36 ) ;
if ( F_27 ( & V_16 -> V_39 ) && V_3 -> V_4 -> V_40 <
V_38 + V_41 )
F_31 ( V_3 -> V_13 ,
L_12
L_13
L_14
L_15
L_16 ,
V_3 -> V_4 -> V_36 , V_3 -> V_4 -> V_40 ,
V_38 + V_41 ) ;
if ( ! F_27 ( & V_16 -> V_39 ) && V_3 -> V_4 -> V_40 <
V_38 + V_41 )
F_31 ( V_3 -> V_13 ,
L_12
L_17
L_18
L_19 ,
V_3 -> V_4 -> V_36 , V_3 -> V_4 -> V_40 ,
V_38 + V_41 ) ;
if ( F_20 ( V_3 ) )
F_30 ( V_3 ) ;
else
F_39 ( V_3 -> V_13 , L_20
L_21 ,
V_3 -> V_4 -> V_36 ) ;
F_44 ( V_3 ) ;
V_7:
return 0 ;
V_48:
F_15 ( V_3 ) ;
return V_44 ;
}
void F_45 ( struct V_3 * V_3 )
{
struct V_16 * V_16 = F_26 ( V_3 -> V_13 ) ;
struct V_3 * V_18 = NULL ;
if ( V_3 -> V_14 == V_15 )
F_32 ( V_3 ) ;
if ( V_3 -> V_14 != V_42 )
goto V_7;
F_31 ( V_3 -> V_13 , L_22 ,
V_3 -> V_4 -> V_36 ) ;
F_46 ( & V_3 -> V_64 ) ;
V_16 -> V_63 -- ;
F_47 ( V_3 , V_16 -> V_63 ) ;
V_18 = F_14 ( V_16 ) ;
if ( V_3 == V_18 ) {
struct V_3 * V_71 ;
V_71 = F_12 ( V_3 -> V_13 ) ;
F_16 ( V_16 , V_71 ) ;
if ( V_71 )
F_15 ( V_71 ) ;
}
F_4 ( V_3 -> V_28 ) ;
V_3 -> V_28 = NULL ;
V_3 -> V_14 = V_45 ;
F_48 ( V_16 ) ;
F_49 ( V_16 , V_3 ) ;
F_3 ( V_3 -> V_13 ) ;
if ( ! V_16 -> V_63 )
F_50 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_15 ( V_3 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static struct V_3 * F_51 ( struct V_5 * V_4 )
{
struct V_3 * V_3 ;
int V_44 ;
F_17 () ;
V_44 = F_10 ( V_4 ) ;
if ( V_44 != 1 )
goto V_7;
F_36 ( V_4 ) ;
V_3 = F_38 ( sizeof( * V_3 ) , V_52 ) ;
if ( ! V_3 ) {
F_37 ( L_23 ,
V_4 -> V_36 ) ;
goto V_72;
}
V_44 = F_52 ( & V_3 -> V_73 , V_4 ) ;
if ( V_44 )
goto V_74;
V_3 -> V_62 = - 1 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_13 = NULL ;
V_3 -> V_14 = V_45 ;
F_53 ( & V_3 -> V_75 ) ;
F_43 ( & V_3 -> V_6 , 2 ) ;
F_22 ( V_3 -> V_4 ) ;
F_54 ( & V_3 -> V_75 , & V_76 ) ;
return V_3 ;
V_74:
F_4 ( V_3 ) ;
V_72:
F_3 ( V_4 ) ;
V_7:
return NULL ;
}
static void F_55 ( struct V_3 * V_3 )
{
F_17 () ;
if ( V_3 -> V_14 != V_45 )
F_45 ( V_3 ) ;
if ( V_3 -> V_14 != V_45 )
return;
V_3 -> V_14 = V_77 ;
F_56 ( & V_3 -> V_73 ) ;
F_15 ( V_3 ) ;
}
void F_57 ( void )
{
struct V_3 * V_3 , * V_78 ;
F_58 () ;
F_59 (hard_iface, hard_iface_tmp,
&hardif_list, list) {
F_60 ( & V_3 -> V_75 ) ;
F_55 ( V_3 ) ;
}
F_61 () ;
}
static int F_62 ( struct V_79 * V_80 ,
unsigned long V_81 , void * V_82 )
{
struct V_5 * V_4 = V_82 ;
struct V_3 * V_3 = F_5 ( V_4 ) ;
struct V_3 * V_18 = NULL ;
struct V_16 * V_16 ;
if ( ! V_3 && V_81 == V_83 )
V_3 = F_51 ( V_4 ) ;
if ( ! V_3 )
goto V_7;
switch ( V_81 ) {
case V_84 :
F_30 ( V_3 ) ;
break;
case V_85 :
case V_86 :
F_32 ( V_3 ) ;
break;
case V_87 :
F_60 ( & V_3 -> V_75 ) ;
F_55 ( V_3 ) ;
break;
case V_88 :
if ( V_3 -> V_13 )
F_29 ( V_3 -> V_13 ) ;
break;
case V_89 :
if ( V_3 -> V_14 == V_45 )
goto V_90;
F_22 ( V_3 -> V_4 ) ;
F_21 ( V_3 ) ;
V_16 = F_26 ( V_3 -> V_13 ) ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
goto V_90;
if ( V_3 == V_18 )
F_13 ( V_16 ) ;
break;
default:
break;
}
V_90:
F_15 ( V_3 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
return V_91 ;
}
static int V_67 ( struct V_92 * V_93 , struct V_5 * V_68 ,
struct V_53 * V_94 ,
struct V_5 * V_95 )
{
struct V_16 * V_16 ;
struct V_27 * V_27 ;
struct V_3 * V_3 ;
int V_44 ;
V_3 = F_2 ( V_94 , struct V_3 , V_64 ) ;
V_93 = F_63 ( V_93 , V_52 ) ;
if ( ! V_93 )
goto V_96;
if ( F_64 ( ! F_65 ( V_93 , 2 ) ) )
goto V_97;
if ( F_64 ( V_93 -> V_98 != sizeof( struct V_99 )
|| ! F_66 ( V_93 ) ) )
goto V_97;
if ( ! V_3 -> V_13 )
goto V_97;
V_16 = F_26 ( V_3 -> V_13 ) ;
if ( F_27 ( & V_16 -> V_100 ) != V_101 )
goto V_97;
if ( V_3 -> V_14 != V_15 )
goto V_97;
V_27 = (struct V_27 * ) V_93 -> V_21 ;
if ( V_27 -> V_55 != V_56 ) {
F_67 ( V_102 , V_16 ,
L_24 ,
V_27 -> V_55 ) ;
goto V_97;
}
switch ( V_27 -> V_53 ) {
case V_54 :
V_44 = F_68 ( V_93 , V_3 ) ;
break;
case V_103 :
V_44 = F_69 ( V_93 , V_3 ) ;
break;
case V_104 :
V_44 = F_70 ( V_93 , V_3 ) ;
break;
case V_105 :
V_44 = F_71 ( V_93 , V_3 ) ;
break;
case V_106 :
V_44 = F_72 ( V_93 , V_3 ) ;
break;
case V_107 :
V_44 = F_73 ( V_93 , V_3 ) ;
break;
case V_108 :
V_44 = F_74 ( V_93 , V_3 ) ;
break;
case V_109 :
V_44 = F_75 ( V_93 , V_3 ) ;
break;
default:
V_44 = V_110 ;
}
if ( V_44 == V_110 )
F_76 ( V_93 ) ;
return V_111 ;
V_97:
F_76 ( V_93 ) ;
V_96:
return V_110 ;
}
