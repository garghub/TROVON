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
static void F_13 ( struct V_16 * V_16 ,
struct V_3 * V_17 )
{
struct V_18 * V_18 ;
struct V_3 * V_19 ;
V_19 = F_14 ( V_16 ) ;
if ( ! V_19 )
goto V_7;
V_18 = (struct V_18 * )
V_16 -> V_20 -> V_21 -> V_22 ;
memcpy ( V_18 -> V_23 , V_19 -> V_4 -> V_24 , V_12 ) ;
memcpy ( V_18 -> V_25 ,
V_19 -> V_4 -> V_24 , V_12 ) ;
F_15 ( V_16 , V_19 , V_17 ) ;
V_7:
if ( V_19 )
F_16 ( V_19 ) ;
}
static void F_17 ( struct V_16 * V_16 ,
struct V_3 * V_26 )
{
struct V_3 * V_27 ;
F_18 () ;
if ( V_26 && ! F_8 ( & V_26 -> V_6 ) )
V_26 = NULL ;
V_27 = F_19 ( V_16 -> V_19 , 1 ) ;
F_20 ( V_16 -> V_19 , V_26 ) ;
if ( ! V_26 )
goto V_7;
V_16 -> V_28 -> V_29 ( V_26 ) ;
F_13 ( V_16 , V_27 ) ;
V_7:
if ( V_27 )
F_16 ( V_27 ) ;
}
static bool F_21 ( const struct V_3 * V_3 )
{
if ( V_3 -> V_4 -> V_8 & V_30 )
return true ;
return false ;
}
static void F_22 ( const struct V_5 * V_4 )
{
const struct V_3 * V_3 ;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_31 ) )
continue;
if ( V_3 -> V_4 == V_4 )
continue;
if ( ! F_23 ( V_3 -> V_4 -> V_24 ,
V_4 -> V_24 ) )
continue;
F_24 ( L_1 ,
V_4 -> V_24 , V_3 -> V_4 -> V_32 ) ;
F_24 ( L_2 ) ;
}
F_9 () ;
}
int F_25 ( struct V_5 * V_13 )
{
const struct V_16 * V_16 = F_26 ( V_13 ) ;
const struct V_3 * V_3 ;
int V_33 = V_34 ;
if ( F_27 ( & V_16 -> V_35 ) )
goto V_7;
F_6 () ;
F_7 (hard_iface, &hardif_list, list) {
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_31 ) )
continue;
if ( V_3 -> V_13 != V_13 )
continue;
V_33 = F_28 ( int , V_3 -> V_4 -> V_36 - V_37 ,
V_33 ) ;
}
F_9 () ;
V_7:
return V_33 ;
}
void F_29 ( struct V_5 * V_13 )
{
int V_33 ;
V_33 = F_25 ( V_13 ) ;
if ( V_13 -> V_36 != V_33 )
V_13 -> V_36 = V_33 ;
}
static void F_30 ( struct V_3 * V_3 )
{
struct V_16 * V_16 ;
struct V_3 * V_19 = NULL ;
if ( V_3 -> V_14 != V_38 )
goto V_7;
V_16 = F_26 ( V_3 -> V_13 ) ;
V_16 -> V_28 -> V_39 ( V_3 ) ;
V_3 -> V_14 = V_31 ;
V_19 = F_14 ( V_16 ) ;
if ( ! V_19 )
F_17 ( V_16 , V_3 ) ;
F_31 ( V_3 -> V_13 , L_3 ,
V_3 -> V_4 -> V_32 ) ;
F_29 ( V_3 -> V_13 ) ;
V_7:
if ( V_19 )
F_16 ( V_19 ) ;
}
static void F_32 ( struct V_3 * V_3 )
{
if ( ( V_3 -> V_14 != V_15 ) &&
( V_3 -> V_14 != V_31 ) )
return;
V_3 -> V_14 = V_38 ;
F_31 ( V_3 -> V_13 , L_4 ,
V_3 -> V_4 -> V_32 ) ;
F_29 ( V_3 -> V_13 ) ;
}
int F_33 ( struct V_3 * V_3 ,
const char * V_40 )
{
struct V_16 * V_16 ;
struct V_5 * V_13 ;
int V_41 ;
if ( V_3 -> V_14 != V_42 )
goto V_7;
if ( ! F_8 ( & V_3 -> V_6 ) )
goto V_7;
if ( V_3 -> V_4 -> V_43 & V_44 )
F_34 ( L_5 ,
V_3 -> V_4 -> V_32 ) ;
V_13 = F_35 ( & V_45 , V_40 ) ;
if ( ! V_13 ) {
V_13 = F_36 ( V_40 ) ;
if ( ! V_13 ) {
V_41 = - V_46 ;
goto V_47;
}
F_37 ( V_13 ) ;
}
if ( ! F_11 ( V_13 ) ) {
F_34 ( L_6 ,
V_13 -> V_32 ) ;
V_41 = - V_48 ;
goto V_49;
}
V_3 -> V_13 = V_13 ;
V_16 = F_26 ( V_3 -> V_13 ) ;
V_41 = V_16 -> V_28 -> V_50 ( V_3 ) ;
if ( V_41 < 0 ) {
V_41 = - V_46 ;
goto V_49;
}
V_3 -> V_51 = V_16 -> V_52 ;
V_16 -> V_52 ++ ;
V_3 -> V_14 = V_38 ;
F_38 ( V_3 , V_16 -> V_52 ) ;
V_3 -> V_53 . type = F_39 ( V_54 ) ;
V_3 -> V_53 . V_55 = V_56 ;
V_3 -> V_53 . V_57 = V_3 -> V_4 ;
F_40 ( & V_3 -> V_53 ) ;
F_41 ( & V_3 -> V_58 , 1 ) ;
F_31 ( V_3 -> V_13 , L_7 ,
V_3 -> V_4 -> V_32 ) ;
if ( F_27 ( & V_16 -> V_35 ) && V_3 -> V_4 -> V_36 <
V_34 + V_37 )
F_31 ( V_3 -> V_13 ,
L_8 ,
V_3 -> V_4 -> V_32 , V_3 -> V_4 -> V_36 ,
V_34 + V_37 ) ;
if ( ! F_27 ( & V_16 -> V_35 ) && V_3 -> V_4 -> V_36 <
V_34 + V_37 )
F_31 ( V_3 -> V_13 ,
L_9 ,
V_3 -> V_4 -> V_32 , V_3 -> V_4 -> V_36 ,
V_34 + V_37 ) ;
if ( F_21 ( V_3 ) )
F_30 ( V_3 ) ;
else
F_42 ( V_3 -> V_13 ,
L_10 ,
V_3 -> V_4 -> V_32 ) ;
F_43 ( V_3 ) ;
V_7:
return 0 ;
V_49:
F_3 ( V_13 ) ;
V_47:
F_16 ( V_3 ) ;
return V_41 ;
}
void F_44 ( struct V_3 * V_3 )
{
struct V_16 * V_16 = F_26 ( V_3 -> V_13 ) ;
struct V_3 * V_19 = NULL ;
if ( V_3 -> V_14 == V_15 )
F_32 ( V_3 ) ;
if ( V_3 -> V_14 != V_38 )
goto V_7;
F_31 ( V_3 -> V_13 , L_11 ,
V_3 -> V_4 -> V_32 ) ;
F_45 ( & V_3 -> V_53 ) ;
V_16 -> V_52 -- ;
F_46 ( V_3 , V_16 -> V_52 ) ;
V_19 = F_14 ( V_16 ) ;
if ( V_3 == V_19 ) {
struct V_3 * V_59 ;
V_59 = F_12 ( V_3 -> V_13 ) ;
F_17 ( V_16 , V_59 ) ;
if ( V_59 )
F_16 ( V_59 ) ;
}
V_16 -> V_28 -> V_60 ( V_3 ) ;
V_3 -> V_14 = V_42 ;
F_47 ( V_16 ) ;
F_48 ( V_16 , V_3 ) ;
F_3 ( V_3 -> V_13 ) ;
if ( ! V_16 -> V_52 )
F_49 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_16 ( V_3 ) ;
V_7:
if ( V_19 )
F_16 ( V_19 ) ;
}
static struct V_3 * F_50 ( struct V_5 * V_4 )
{
struct V_3 * V_3 ;
int V_41 ;
F_18 () ;
V_41 = F_10 ( V_4 ) ;
if ( V_41 != 1 )
goto V_7;
F_37 ( V_4 ) ;
V_3 = F_51 ( sizeof( * V_3 ) , V_61 ) ;
if ( ! V_3 )
goto V_62;
V_41 = F_52 ( & V_3 -> V_63 , V_4 ) ;
if ( V_41 )
goto V_64;
V_3 -> V_51 = - 1 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_13 = NULL ;
V_3 -> V_14 = V_42 ;
F_53 ( & V_3 -> V_65 ) ;
F_41 ( & V_3 -> V_6 , 2 ) ;
F_22 ( V_3 -> V_4 ) ;
F_54 ( & V_3 -> V_65 , & V_66 ) ;
F_41 ( & V_3 -> V_67 , 1 ) ;
V_3 -> V_68 = NULL ;
return V_3 ;
V_64:
F_4 ( V_3 ) ;
V_62:
F_3 ( V_4 ) ;
V_7:
return NULL ;
}
static void F_55 ( struct V_3 * V_3 )
{
F_18 () ;
if ( V_3 -> V_14 != V_42 )
F_44 ( V_3 ) ;
if ( V_3 -> V_14 != V_42 )
return;
V_3 -> V_14 = V_69 ;
F_56 ( & V_3 -> V_63 ) ;
F_16 ( V_3 ) ;
}
void F_57 ( void )
{
struct V_3 * V_3 , * V_70 ;
F_58 () ;
F_59 (hard_iface, hard_iface_tmp,
&hardif_list, list) {
F_60 ( & V_3 -> V_65 ) ;
F_55 ( V_3 ) ;
}
F_61 () ;
}
static int F_62 ( struct V_71 * V_72 ,
unsigned long V_73 , void * V_74 )
{
struct V_5 * V_4 = V_74 ;
struct V_3 * V_3 = F_5 ( V_4 ) ;
struct V_3 * V_19 = NULL ;
struct V_16 * V_16 ;
if ( ! V_3 && V_73 == V_75 )
V_3 = F_50 ( V_4 ) ;
if ( ! V_3 )
goto V_7;
switch ( V_73 ) {
case V_76 :
F_30 ( V_3 ) ;
break;
case V_77 :
case V_78 :
F_32 ( V_3 ) ;
break;
case V_79 :
F_60 ( & V_3 -> V_65 ) ;
F_55 ( V_3 ) ;
break;
case V_80 :
if ( V_3 -> V_13 )
F_29 ( V_3 -> V_13 ) ;
break;
case V_81 :
if ( V_3 -> V_14 == V_42 )
goto V_82;
F_22 ( V_3 -> V_4 ) ;
V_16 = F_26 ( V_3 -> V_13 ) ;
V_16 -> V_28 -> V_39 ( V_3 ) ;
V_19 = F_14 ( V_16 ) ;
if ( ! V_19 )
goto V_82;
if ( V_3 == V_19 )
F_13 ( V_16 , NULL ) ;
break;
default:
break;
}
V_82:
F_16 ( V_3 ) ;
V_7:
if ( V_19 )
F_16 ( V_19 ) ;
return V_83 ;
}
bool F_63 ( int V_84 )
{
struct V_5 * V_5 = NULL ;
bool V_41 = false ;
if ( V_84 == V_85 )
goto V_7;
V_5 = F_64 ( & V_45 , V_84 ) ;
if ( ! V_5 )
goto V_7;
#ifdef F_65
if ( V_5 -> V_86 )
V_41 = true ;
else
#endif
if ( V_5 -> V_87 )
V_41 = true ;
V_7:
if ( V_5 )
F_3 ( V_5 ) ;
return V_41 ;
}
