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
F_20 ( V_25 ) ;
F_13 ( V_16 ) ;
}
static bool F_21 ( const struct V_3 * V_3 )
{
if ( V_3 -> V_4 -> V_8 & V_27 )
return true ;
return false ;
}
static void F_22 ( const struct V_5 * V_4 )
{
const struct V_3 * V_3 ;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_28 ) )
continue;
if ( V_3 -> V_4 == V_4 )
continue;
if ( ! F_23 ( V_3 -> V_4 -> V_23 ,
V_4 -> V_23 ) )
continue;
F_24 ( L_1
L_2 , V_4 -> V_23 ,
V_3 -> V_4 -> V_29 ) ;
F_24 ( L_3
L_4 ) ;
}
F_9 () ;
}
int F_25 ( struct V_5 * V_13 )
{
const struct V_16 * V_16 = F_26 ( V_13 ) ;
const struct V_3 * V_3 ;
int V_30 = V_31 ;
if ( F_27 ( & V_16 -> V_32 ) )
goto V_7;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_28 ) )
continue;
if ( V_3 -> V_13 != V_13 )
continue;
V_30 = F_28 ( int , V_3 -> V_4 -> V_33 - V_34 ,
V_30 ) ;
}
F_9 () ;
V_7:
return V_30 ;
}
void F_29 ( struct V_5 * V_13 )
{
int V_30 ;
V_30 = F_25 ( V_13 ) ;
if ( V_13 -> V_33 != V_30 )
V_13 -> V_33 = V_30 ;
}
static void F_30 ( struct V_3 * V_3 )
{
struct V_16 * V_16 ;
struct V_3 * V_18 = NULL ;
if ( V_3 -> V_14 != V_35 )
goto V_7;
V_16 = F_26 ( V_3 -> V_13 ) ;
F_31 ( V_3 ) ;
V_3 -> V_14 = V_28 ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
F_16 ( V_16 , V_3 ) ;
F_32 ( V_3 -> V_13 , L_5 ,
V_3 -> V_4 -> V_29 ) ;
F_29 ( V_3 -> V_13 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static void F_33 ( struct V_3 * V_3 )
{
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_28 ) )
return;
V_3 -> V_14 = V_35 ;
F_32 ( V_3 -> V_13 , L_6 ,
V_3 -> V_4 -> V_29 ) ;
F_29 ( V_3 -> V_13 ) ;
}
int F_34 ( struct V_3 * V_3 ,
const char * V_36 )
{
struct V_16 * V_16 ;
struct V_5 * V_13 ;
int V_37 ;
if ( V_3 -> V_14 != V_38 )
goto V_7;
if ( ! F_8 ( & V_3 -> V_6 ) )
goto V_7;
V_13 = F_35 ( & V_39 , V_36 ) ;
if ( ! V_13 ) {
V_13 = F_36 ( V_36 ) ;
if ( ! V_13 ) {
V_37 = - V_40 ;
goto V_41;
}
F_37 ( V_13 ) ;
}
if ( ! F_11 ( V_13 ) ) {
F_38 ( L_7
L_8 ,
V_13 -> V_29 ) ;
F_3 ( V_13 ) ;
V_37 = - V_42 ;
goto V_41;
}
V_3 -> V_13 = V_13 ;
V_16 = F_26 ( V_3 -> V_13 ) ;
F_39 ( V_3 ) ;
if ( ! V_3 -> V_43 ) {
F_40 ( V_3 -> V_13 , L_9
L_10 , V_3 -> V_4 -> V_29 ) ;
V_37 = - V_40 ;
goto V_41;
}
V_3 -> V_44 = V_16 -> V_45 ;
V_16 -> V_45 ++ ;
V_3 -> V_14 = V_35 ;
F_41 ( V_3 , V_16 -> V_45 ) ;
V_3 -> V_46 . type = F_42 ( V_47 ) ;
V_3 -> V_46 . V_48 = V_49 ;
V_3 -> V_46 . V_50 = V_3 -> V_4 ;
F_43 ( & V_3 -> V_46 ) ;
F_44 ( & V_3 -> V_51 , 1 ) ;
F_44 ( & V_3 -> V_52 , 1 ) ;
F_32 ( V_3 -> V_13 , L_11 ,
V_3 -> V_4 -> V_29 ) ;
if ( F_27 ( & V_16 -> V_32 ) && V_3 -> V_4 -> V_33 <
V_31 + V_34 )
F_32 ( V_3 -> V_13 ,
L_12
L_13
L_14
L_15
L_16 ,
V_3 -> V_4 -> V_29 , V_3 -> V_4 -> V_33 ,
V_31 + V_34 ) ;
if ( ! F_27 ( & V_16 -> V_32 ) && V_3 -> V_4 -> V_33 <
V_31 + V_34 )
F_32 ( V_3 -> V_13 ,
L_12
L_17
L_18
L_19 ,
V_3 -> V_4 -> V_29 , V_3 -> V_4 -> V_33 ,
V_31 + V_34 ) ;
if ( F_21 ( V_3 ) )
F_30 ( V_3 ) ;
else
F_40 ( V_3 -> V_13 , L_20
L_21 ,
V_3 -> V_4 -> V_29 ) ;
F_45 ( V_3 ) ;
V_7:
return 0 ;
V_41:
F_15 ( V_3 ) ;
return V_37 ;
}
void F_46 ( struct V_3 * V_3 )
{
struct V_16 * V_16 = F_26 ( V_3 -> V_13 ) ;
struct V_3 * V_18 = NULL ;
if ( V_3 -> V_14 == V_15 )
F_33 ( V_3 ) ;
if ( V_3 -> V_14 != V_35 )
goto V_7;
F_32 ( V_3 -> V_13 , L_22 ,
V_3 -> V_4 -> V_29 ) ;
F_47 ( & V_3 -> V_46 ) ;
V_16 -> V_45 -- ;
F_48 ( V_3 , V_16 -> V_45 ) ;
V_18 = F_14 ( V_16 ) ;
if ( V_3 == V_18 ) {
struct V_3 * V_53 ;
V_53 = F_12 ( V_3 -> V_13 ) ;
F_16 ( V_16 , V_53 ) ;
if ( V_53 )
F_15 ( V_53 ) ;
}
F_4 ( V_3 -> V_43 ) ;
V_3 -> V_43 = NULL ;
V_3 -> V_14 = V_38 ;
F_49 ( V_16 ) ;
F_50 ( V_16 , V_3 ) ;
F_3 ( V_3 -> V_13 ) ;
if ( ! V_16 -> V_45 )
F_51 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_15 ( V_3 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
}
static struct V_3 * F_52 ( struct V_5 * V_4 )
{
struct V_3 * V_3 ;
int V_37 ;
F_17 () ;
V_37 = F_10 ( V_4 ) ;
if ( V_37 != 1 )
goto V_7;
F_37 ( V_4 ) ;
V_3 = F_53 ( sizeof( * V_3 ) , V_54 ) ;
if ( ! V_3 )
goto V_55;
V_37 = F_54 ( & V_3 -> V_56 , V_4 ) ;
if ( V_37 )
goto V_57;
V_3 -> V_44 = - 1 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_13 = NULL ;
V_3 -> V_14 = V_38 ;
F_55 ( & V_3 -> V_58 ) ;
F_44 ( & V_3 -> V_6 , 2 ) ;
F_22 ( V_3 -> V_4 ) ;
F_56 ( & V_3 -> V_58 , & V_59 ) ;
return V_3 ;
V_57:
F_4 ( V_3 ) ;
V_55:
F_3 ( V_4 ) ;
V_7:
return NULL ;
}
static void F_57 ( struct V_3 * V_3 )
{
F_17 () ;
if ( V_3 -> V_14 != V_38 )
F_46 ( V_3 ) ;
if ( V_3 -> V_14 != V_38 )
return;
V_3 -> V_14 = V_60 ;
F_58 ( & V_3 -> V_56 ) ;
F_15 ( V_3 ) ;
}
void F_59 ( void )
{
struct V_3 * V_3 , * V_61 ;
F_60 () ;
F_61 (hard_iface, hard_iface_tmp,
&hardif_list, list) {
F_62 ( & V_3 -> V_58 ) ;
F_57 ( V_3 ) ;
}
F_63 () ;
}
static int F_64 ( struct V_62 * V_63 ,
unsigned long V_64 , void * V_65 )
{
struct V_5 * V_4 = V_65 ;
struct V_3 * V_3 = F_5 ( V_4 ) ;
struct V_3 * V_18 = NULL ;
struct V_16 * V_16 ;
if ( ! V_3 && V_64 == V_66 )
V_3 = F_52 ( V_4 ) ;
if ( ! V_3 )
goto V_7;
switch ( V_64 ) {
case V_67 :
F_30 ( V_3 ) ;
break;
case V_68 :
case V_69 :
F_33 ( V_3 ) ;
break;
case V_70 :
F_62 ( & V_3 -> V_58 ) ;
F_57 ( V_3 ) ;
break;
case V_71 :
if ( V_3 -> V_13 )
F_29 ( V_3 -> V_13 ) ;
break;
case V_72 :
if ( V_3 -> V_14 == V_38 )
goto V_73;
F_22 ( V_3 -> V_4 ) ;
F_31 ( V_3 ) ;
V_16 = F_26 ( V_3 -> V_13 ) ;
V_18 = F_14 ( V_16 ) ;
if ( ! V_18 )
goto V_73;
if ( V_3 == V_18 )
F_13 ( V_16 ) ;
break;
default:
break;
}
V_73:
F_15 ( V_3 ) ;
V_7:
if ( V_18 )
F_15 ( V_18 ) ;
return V_74 ;
}
static int V_49 ( struct V_75 * V_76 , struct V_5 * V_50 ,
struct V_77 * V_78 ,
struct V_5 * V_79 )
{
struct V_16 * V_16 ;
struct V_80 * V_80 ;
struct V_3 * V_3 ;
int V_37 ;
V_3 = F_2 ( V_78 , struct V_3 , V_46 ) ;
V_76 = F_65 ( V_76 , V_54 ) ;
if ( ! V_76 )
goto V_81;
if ( F_66 ( ! F_67 ( V_76 , 2 ) ) )
goto V_82;
if ( F_66 ( V_76 -> V_83 != sizeof( struct V_84 )
|| ! F_68 ( V_76 ) ) )
goto V_82;
if ( ! V_3 -> V_13 )
goto V_82;
V_16 = F_26 ( V_3 -> V_13 ) ;
if ( F_27 ( & V_16 -> V_85 ) != V_86 )
goto V_82;
if ( V_3 -> V_14 != V_15 )
goto V_82;
V_80 = (struct V_80 * ) V_76 -> V_21 ;
if ( V_80 -> V_87 != V_88 ) {
F_69 ( V_89 , V_16 ,
L_23 ,
V_80 -> V_87 ) ;
goto V_82;
}
switch ( V_80 -> V_77 ) {
case V_90 :
V_37 = F_70 ( V_76 , V_3 ) ;
break;
case V_91 :
V_37 = F_71 ( V_76 , V_3 ) ;
break;
case V_92 :
V_37 = F_72 ( V_76 , V_3 ) ;
break;
case V_93 :
V_37 = F_73 ( V_76 , V_3 ) ;
break;
case V_94 :
V_37 = F_74 ( V_76 , V_3 ) ;
break;
case V_95 :
V_37 = F_75 ( V_76 , V_3 ) ;
break;
case V_96 :
V_37 = F_76 ( V_76 , V_3 ) ;
break;
case V_97 :
V_37 = F_77 ( V_76 , V_3 ) ;
break;
default:
V_37 = V_98 ;
}
if ( V_37 == V_98 )
F_78 ( V_76 ) ;
return V_99 ;
V_82:
F_78 ( V_76 ) ;
V_81:
return V_98 ;
}
bool F_79 ( int V_100 )
{
struct V_5 * V_5 = NULL ;
bool V_37 = false ;
if ( V_100 == V_101 )
goto V_7;
V_5 = F_80 ( & V_39 , V_100 ) ;
if ( ! V_5 )
goto V_7;
#ifdef F_81
if ( V_5 -> V_102 )
V_37 = true ;
else
#endif
if ( V_5 -> V_103 )
V_37 = true ;
V_7:
if ( V_5 )
F_3 ( V_5 ) ;
return V_37 ;
}
