void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_3 -> V_4 ) ;
F_4 ( V_3 ) ;
}
struct V_3 * F_5 ( struct V_5 * V_4 )
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
static int F_10 ( struct V_5 * V_4 )
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
static struct V_3 * F_12 ( struct V_5 * V_13 )
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
V_26 = V_16 -> V_18 ;
F_18 ( V_16 -> V_18 , V_25 ) ;
if ( V_26 )
F_15 ( V_26 ) ;
if ( ! V_25 )
return;
V_27 = (struct V_27 * ) ( V_25 -> V_28 ) ;
V_27 -> V_8 = V_29 ;
V_27 -> V_30 = V_31 ;
F_13 ( V_16 ) ;
F_19 ( & V_16 -> V_32 , 1 ) ;
}
static bool F_20 ( struct V_3 * V_3 )
{
if ( V_3 -> V_4 -> V_8 & V_33 )
return true ;
return false ;
}
static void F_21 ( struct V_3 * V_3 )
{
memcpy ( ( (struct V_27 * ) ( V_3 -> V_28 ) ) -> V_34 ,
V_3 -> V_4 -> V_23 , V_12 ) ;
memcpy ( ( (struct V_27 * ) ( V_3 -> V_28 ) ) -> V_35 ,
V_3 -> V_4 -> V_23 , V_12 ) ;
}
static void F_22 ( struct V_5 * V_4 )
{
struct V_3 * V_3 ;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_36 ) )
continue;
if ( V_3 -> V_4 == V_4 )
continue;
if ( ! F_23 ( V_3 -> V_4 -> V_23 ,
V_4 -> V_23 ) )
continue;
F_24 ( L_1
L_2 , V_4 -> V_23 ,
V_3 -> V_4 -> V_37 ) ;
F_24 ( L_3
L_4 ) ;
}
F_9 () ;
}
int F_25 ( struct V_5 * V_13 )
{
struct V_16 * V_16 = F_26 ( V_13 ) ;
struct V_3 * V_3 ;
int V_38 = V_39 ;
if ( F_27 ( & V_16 -> V_40 ) )
goto V_7;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_36 ) )
continue;
if ( V_3 -> V_13 != V_13 )
continue;
V_38 = F_28 ( int , V_3 -> V_4 -> V_41 - V_42 ,
V_38 ) ;
}
F_9 () ;
V_7:
return V_38 ;
}
void F_29 ( struct V_5 * V_13 )
{
int V_38 ;
V_38 = F_25 ( V_13 ) ;
if ( V_13 -> V_41 != V_38 )
V_13 -> V_41 = V_38 ;
}
static void F_30 ( struct V_3 * V_3 )
{
struct V_16 * V_16 ;
struct V_3 * V_18 = NULL ;
if ( V_3 -> V_14 != V_43 )
goto V_7;
V_16 = F_26 ( V_3 -> V_13 ) ;
F_21 ( V_3 ) ;
V_3 -> V_14 = V_36 ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
F_16 ( V_16 , V_3 ) ;
F_31 ( V_3 -> V_13 , L_5 ,
V_3 -> V_4 -> V_37 ) ;
F_29 ( V_3 -> V_13 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static void F_32 ( struct V_3 * V_3 )
{
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_36 ) )
return;
V_3 -> V_14 = V_43 ;
F_31 ( V_3 -> V_13 , L_6 ,
V_3 -> V_4 -> V_37 ) ;
F_29 ( V_3 -> V_13 ) ;
}
int F_33 ( struct V_3 * V_3 , char * V_44 )
{
struct V_16 * V_16 ;
struct V_27 * V_27 ;
struct V_5 * V_13 ;
int V_45 ;
if ( V_3 -> V_14 != V_46 )
goto V_7;
if ( ! F_8 ( & V_3 -> V_6 ) )
goto V_7;
V_13 = F_34 ( & V_47 , V_44 ) ;
if ( ! V_13 ) {
V_13 = F_35 ( V_44 ) ;
if ( ! V_13 ) {
V_45 = - V_48 ;
goto V_49;
}
F_36 ( V_13 ) ;
}
if ( ! F_11 ( V_13 ) ) {
F_37 ( L_7
L_8 ,
V_13 -> V_37 ) ;
F_3 ( V_13 ) ;
V_45 = - V_50 ;
goto V_49;
}
V_3 -> V_13 = V_13 ;
V_16 = F_26 ( V_3 -> V_13 ) ;
V_3 -> V_51 = V_52 ;
V_3 -> V_28 = F_38 ( V_3 -> V_51 , V_53 ) ;
if ( ! V_3 -> V_28 ) {
F_39 ( V_3 -> V_13 , L_9
L_10 , V_3 -> V_4 -> V_37 ) ;
V_45 = - V_48 ;
goto V_49;
}
V_27 = (struct V_27 * ) ( V_3 -> V_28 ) ;
V_27 -> V_54 = V_55 ;
V_27 -> V_56 = V_57 ;
V_27 -> V_8 = 0 ;
V_27 -> V_30 = 2 ;
V_27 -> V_58 = V_59 ;
V_27 -> V_60 = 0 ;
V_3 -> V_61 = V_16 -> V_62 ;
V_16 -> V_62 ++ ;
V_3 -> V_14 = V_43 ;
F_40 ( V_3 , V_16 -> V_62 ) ;
V_3 -> V_63 . type = F_41 ( V_64 ) ;
V_3 -> V_63 . V_65 = V_66 ;
V_3 -> V_63 . V_67 = V_3 -> V_4 ;
F_42 ( & V_3 -> V_63 ) ;
F_19 ( & V_3 -> V_68 , 1 ) ;
F_19 ( & V_3 -> V_69 , 1 ) ;
F_31 ( V_3 -> V_13 , L_11 ,
V_3 -> V_4 -> V_37 ) ;
if ( F_27 ( & V_16 -> V_40 ) && V_3 -> V_4 -> V_41 <
V_39 + V_42 )
F_31 ( V_3 -> V_13 ,
L_12
L_13
L_14
L_15
L_16 ,
V_3 -> V_4 -> V_37 , V_3 -> V_4 -> V_41 ,
V_39 + V_42 ) ;
if ( ! F_27 ( & V_16 -> V_40 ) && V_3 -> V_4 -> V_41 <
V_39 + V_42 )
F_31 ( V_3 -> V_13 ,
L_12
L_17
L_18
L_19 ,
V_3 -> V_4 -> V_37 , V_3 -> V_4 -> V_41 ,
V_39 + V_42 ) ;
if ( F_20 ( V_3 ) )
F_30 ( V_3 ) ;
else
F_39 ( V_3 -> V_13 , L_20
L_21 ,
V_3 -> V_4 -> V_37 ) ;
F_43 ( V_3 ) ;
V_7:
return 0 ;
V_49:
F_15 ( V_3 ) ;
return V_45 ;
}
void F_44 ( struct V_3 * V_3 )
{
struct V_16 * V_16 = F_26 ( V_3 -> V_13 ) ;
struct V_3 * V_18 = NULL ;
if ( V_3 -> V_14 == V_15 )
F_32 ( V_3 ) ;
if ( V_3 -> V_14 != V_43 )
goto V_7;
F_31 ( V_3 -> V_13 , L_22 ,
V_3 -> V_4 -> V_37 ) ;
F_45 ( & V_3 -> V_63 ) ;
V_16 -> V_62 -- ;
F_46 ( V_3 , V_16 -> V_62 ) ;
V_18 = F_14 ( V_16 ) ;
if ( V_3 == V_18 ) {
struct V_3 * V_70 ;
V_70 = F_12 ( V_3 -> V_13 ) ;
F_16 ( V_16 , V_70 ) ;
if ( V_70 )
F_15 ( V_70 ) ;
}
F_4 ( V_3 -> V_28 ) ;
V_3 -> V_28 = NULL ;
V_3 -> V_14 = V_46 ;
F_47 ( V_16 ) ;
F_48 ( V_16 , V_3 ) ;
F_3 ( V_3 -> V_13 ) ;
if ( ! V_16 -> V_62 )
F_49 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_15 ( V_3 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static struct V_3 * F_50 ( struct V_5 * V_4 )
{
struct V_3 * V_3 ;
int V_45 ;
F_17 () ;
V_45 = F_10 ( V_4 ) ;
if ( V_45 != 1 )
goto V_7;
F_36 ( V_4 ) ;
V_3 = F_38 ( sizeof( struct V_3 ) , V_53 ) ;
if ( ! V_3 ) {
F_37 ( L_23 ,
V_4 -> V_37 ) ;
goto V_71;
}
V_45 = F_51 ( & V_3 -> V_72 , V_4 ) ;
if ( V_45 )
goto V_73;
V_3 -> V_61 = - 1 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_13 = NULL ;
V_3 -> V_14 = V_46 ;
F_52 ( & V_3 -> V_74 ) ;
F_19 ( & V_3 -> V_6 , 2 ) ;
F_22 ( V_3 -> V_4 ) ;
F_53 ( & V_3 -> V_74 , & V_75 ) ;
return V_3 ;
V_73:
F_4 ( V_3 ) ;
V_71:
F_3 ( V_4 ) ;
V_7:
return NULL ;
}
static void F_54 ( struct V_3 * V_3 )
{
F_17 () ;
if ( V_3 -> V_14 != V_46 )
F_44 ( V_3 ) ;
if ( V_3 -> V_14 != V_46 )
return;
V_3 -> V_14 = V_76 ;
F_55 ( & V_3 -> V_72 ) ;
F_15 ( V_3 ) ;
}
void F_56 ( void )
{
struct V_3 * V_3 , * V_77 ;
F_57 () ;
F_58 (hard_iface, hard_iface_tmp,
&hardif_list, list) {
F_59 ( & V_3 -> V_74 ) ;
F_54 ( V_3 ) ;
}
F_60 () ;
}
static int F_61 ( struct V_78 * V_79 ,
unsigned long V_80 , void * V_81 )
{
struct V_5 * V_4 = (struct V_5 * ) V_81 ;
struct V_3 * V_3 = F_5 ( V_4 ) ;
struct V_3 * V_18 = NULL ;
struct V_16 * V_16 ;
if ( ! V_3 && V_80 == V_82 )
V_3 = F_50 ( V_4 ) ;
if ( ! V_3 )
goto V_7;
switch ( V_80 ) {
case V_83 :
F_30 ( V_3 ) ;
break;
case V_84 :
case V_85 :
F_32 ( V_3 ) ;
break;
case V_86 :
F_59 ( & V_3 -> V_74 ) ;
F_54 ( V_3 ) ;
break;
case V_87 :
if ( V_3 -> V_13 )
F_29 ( V_3 -> V_13 ) ;
break;
case V_88 :
if ( V_3 -> V_14 == V_46 )
goto V_89;
F_22 ( V_3 -> V_4 ) ;
F_21 ( V_3 ) ;
V_16 = F_26 ( V_3 -> V_13 ) ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
goto V_89;
if ( V_3 == V_18 )
F_13 ( V_16 ) ;
break;
default:
break;
} ;
V_89:
F_15 ( V_3 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
return V_90 ;
}
static int V_66 ( struct V_91 * V_92 , struct V_5 * V_67 ,
struct V_54 * V_93 ,
struct V_5 * V_94 )
{
struct V_16 * V_16 ;
struct V_27 * V_27 ;
struct V_3 * V_3 ;
int V_45 ;
V_3 = F_2 ( V_93 , struct V_3 , V_63 ) ;
V_92 = F_62 ( V_92 , V_53 ) ;
if ( ! V_92 )
goto V_95;
if ( F_63 ( ! F_64 ( V_92 , 2 ) ) )
goto V_96;
if ( F_63 ( V_92 -> V_97 != sizeof( struct V_98 )
|| ! F_65 ( V_92 ) ) )
goto V_96;
if ( ! V_3 -> V_13 )
goto V_96;
V_16 = F_26 ( V_3 -> V_13 ) ;
if ( F_27 ( & V_16 -> V_99 ) != V_100 )
goto V_96;
if ( V_3 -> V_14 != V_15 )
goto V_96;
V_27 = (struct V_27 * ) V_92 -> V_21 ;
if ( V_27 -> V_56 != V_57 ) {
F_66 ( V_101 , V_16 ,
L_24 ,
V_27 -> V_56 ) ;
goto V_96;
}
switch ( V_27 -> V_54 ) {
case V_55 :
V_45 = F_67 ( V_92 , V_3 ) ;
break;
case V_102 :
V_45 = F_68 ( V_92 , V_3 ) ;
break;
case V_103 :
V_45 = F_69 ( V_92 , V_3 ) ;
break;
case V_104 :
V_45 = F_70 ( V_92 , V_3 ) ;
break;
case V_105 :
V_45 = F_71 ( V_92 , V_3 ) ;
break;
case V_106 :
V_45 = F_72 ( V_92 , V_3 ) ;
break;
default:
V_45 = V_107 ;
}
if ( V_45 == V_107 )
F_73 ( V_92 ) ;
return V_108 ;
V_96:
F_73 ( V_92 ) ;
V_95:
return V_107 ;
}
