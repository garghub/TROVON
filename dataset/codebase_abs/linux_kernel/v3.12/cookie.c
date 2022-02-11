void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_2 ( & V_3 -> V_4 ) ;
F_2 ( & V_3 -> V_5 ) ;
F_3 ( & V_3 -> V_6 ) ;
}
struct V_2 * F_4 (
struct V_2 * V_7 ,
const struct V_8 * V_9 ,
void * V_10 )
{
struct V_2 * V_3 ;
F_5 ( ! V_9 ) ;
F_6 ( L_1 ,
V_7 ? ( char * ) V_7 -> V_9 -> V_11 : L_2 ,
V_9 -> V_11 , V_10 ) ;
F_7 ( & V_12 ) ;
if ( ! V_7 ) {
F_7 ( & V_13 ) ;
F_8 ( L_3 ) ;
return NULL ;
}
F_5 ( ! V_9 -> V_14 ) ;
F_5 ( ! V_9 -> V_11 [ 0 ] ) ;
F_5 ( V_9 -> type == V_15 &&
V_7 -> V_9 -> type != V_15 ) ;
V_3 = F_9 ( V_16 , V_17 ) ;
if ( ! V_3 ) {
F_7 ( & V_18 ) ;
F_8 ( L_4 ) ;
return NULL ;
}
F_10 ( & V_3 -> V_19 , 1 ) ;
F_10 ( & V_3 -> V_20 , 0 ) ;
F_10 ( & V_3 -> V_21 , 1 ) ;
F_11 ( & V_7 -> V_19 ) ;
F_11 ( & V_7 -> V_20 ) ;
V_3 -> V_9 = V_9 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_22 = 0 ;
F_12 ( & V_3 -> V_23 , V_24 & ~ V_25 ) ;
switch ( V_3 -> V_9 -> type ) {
case V_15 :
F_7 ( & V_26 ) ;
break;
case V_27 :
F_7 ( & V_28 ) ;
break;
default:
F_7 ( & V_29 ) ;
break;
}
if ( V_3 -> V_9 -> type != V_15 ) {
if ( F_13 ( V_3 ) < 0 ) {
F_14 ( & V_7 -> V_20 ) ;
F_15 ( V_3 ) ;
F_7 ( & V_30 ) ;
F_8 ( L_5 ) ;
return NULL ;
}
}
F_7 ( & V_31 ) ;
F_8 ( L_6 , V_3 ) ;
return V_3 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_1 V_36 ;
int V_37 ;
F_6 ( L_7 ) ;
V_3 -> V_22 = 1 << V_38 ;
F_16 ( & V_39 ) ;
if ( F_17 ( & V_40 ) ) {
F_18 ( & V_39 ) ;
F_8 ( L_8 ) ;
return 0 ;
}
V_35 = F_19 ( V_3 -> V_7 ) ;
if ( ! V_35 ) {
F_18 ( & V_39 ) ;
F_7 ( & V_41 ) ;
F_8 ( L_9 ) ;
return - V_42 ;
}
F_20 ( L_10 , V_35 -> V_43 -> V_11 ) ;
V_3 -> V_22 =
( 1 << V_44 ) |
( 1 << V_45 ) ;
V_37 = F_21 ( V_35 , V_3 ) ;
if ( V_37 < 0 ) {
F_18 ( & V_39 ) ;
F_8 ( L_11 , V_37 ) ;
return V_37 ;
}
V_3 -> V_9 -> V_46 ( V_3 -> V_10 , & V_36 ) ;
F_22 ( & V_3 -> V_4 ) ;
if ( F_23 ( & V_3 -> V_6 ) ) {
F_24 ( & V_3 -> V_4 ) ;
goto V_47;
}
V_33 = F_25 ( V_3 -> V_6 . V_48 ,
struct V_32 , V_49 ) ;
F_26 ( V_33 , V_36 ) ;
F_27 ( V_33 , V_50 ) ;
F_24 ( & V_3 -> V_4 ) ;
if ( ! V_51 ) {
F_20 ( L_12 , & V_3 -> V_22 ) ;
F_28 ( & V_3 -> V_22 , V_44 ,
V_52 , V_53 ) ;
F_20 ( L_13 ) ;
if ( F_29 ( V_38 , & V_3 -> V_22 ) )
goto V_47;
}
F_18 ( & V_39 ) ;
F_8 ( L_14 ) ;
return 0 ;
V_47:
F_18 ( & V_39 ) ;
F_8 ( L_15 ) ;
return - V_54 ;
}
static int F_21 ( struct V_34 * V_35 ,
struct V_2 * V_3 )
{
struct V_32 * V_33 ;
int V_37 ;
F_6 ( L_16 , V_35 , V_3 , V_3 -> V_9 -> V_11 ) ;
F_22 ( & V_3 -> V_4 ) ;
F_30 (object, &cookie->backing_objects,
cookie_link) {
if ( V_33 -> V_35 == V_35 )
goto V_55;
}
F_24 ( & V_3 -> V_4 ) ;
F_7 ( & V_56 ) ;
V_33 = V_35 -> V_57 -> V_58 ( V_35 , V_3 ) ;
F_31 ( & V_56 ) ;
if ( F_32 ( V_33 ) ) {
F_7 ( & V_59 ) ;
V_37 = F_33 ( V_33 ) ;
goto error;
}
F_7 ( & V_60 ) ;
V_33 -> V_61 = F_34 ( & V_62 ) ;
F_20 ( L_17 ,
V_33 -> V_61 , V_3 -> V_9 -> V_11 , V_33 -> V_63 ) ;
V_37 = F_21 ( V_35 , V_3 -> V_7 ) ;
if ( V_37 < 0 )
goto V_64;
if ( F_35 ( V_3 , V_33 ) < 0 ) {
F_7 ( & V_65 ) ;
V_35 -> V_57 -> V_66 ( V_33 ) ;
F_31 ( & V_65 ) ;
}
F_8 ( L_18 ) ;
return 0 ;
V_55:
V_37 = - V_54 ;
if ( F_36 ( V_33 ) ) {
F_24 ( & V_3 -> V_4 ) ;
goto error;
}
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_19 ) ;
return 0 ;
V_64:
F_7 ( & V_65 ) ;
V_35 -> V_57 -> V_66 ( V_33 ) ;
F_31 ( & V_65 ) ;
error:
F_8 ( L_11 , V_37 ) ;
return V_37 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_32 * V_33 )
{
struct V_32 * V_67 ;
struct V_34 * V_35 = V_33 -> V_35 ;
int V_37 ;
F_6 ( L_20 , V_3 -> V_9 -> V_11 , V_33 -> V_61 ) ;
F_22 ( & V_3 -> V_4 ) ;
V_37 = - V_68 ;
F_30 (p, &cookie->backing_objects, cookie_link) {
if ( V_67 -> V_35 == V_33 -> V_35 ) {
if ( F_37 ( V_67 ) )
V_37 = - V_54 ;
goto V_69;
}
}
F_38 ( & V_3 -> V_7 -> V_4 , 1 ) ;
F_30 (p, &cookie->parent->backing_objects,
cookie_link) {
if ( V_67 -> V_35 == V_33 -> V_35 ) {
if ( F_37 ( V_67 ) ) {
V_37 = - V_54 ;
F_24 ( & V_3 -> V_7 -> V_4 ) ;
goto V_69;
}
V_33 -> V_7 = V_67 ;
F_22 ( & V_67 -> V_4 ) ;
V_67 -> V_20 ++ ;
F_24 ( & V_67 -> V_4 ) ;
break;
}
}
F_24 ( & V_3 -> V_7 -> V_4 ) ;
if ( F_17 ( & V_33 -> V_70 ) ) {
F_22 ( & V_35 -> V_71 ) ;
F_39 ( & V_33 -> V_70 , & V_35 -> V_72 ) ;
F_24 ( & V_35 -> V_71 ) ;
}
V_33 -> V_3 = V_3 ;
F_11 ( & V_3 -> V_19 ) ;
F_40 ( & V_33 -> V_49 , & V_3 -> V_6 ) ;
F_41 ( V_33 ) ;
V_37 = 0 ;
V_69:
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_11 , V_37 ) ;
return V_37 ;
}
void F_42 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
F_6 ( L_21 , V_3 -> V_9 -> V_11 ) ;
F_7 ( & V_73 ) ;
F_43 ( V_3 -> V_9 -> type , == , V_27 ) ;
F_5 ( ! V_3 -> V_9 -> V_74 ) ;
if ( ! F_23 ( & V_3 -> V_6 ) ) {
F_22 ( & V_3 -> V_4 ) ;
if ( ! F_23 ( & V_3 -> V_6 ) &&
! F_44 ( V_75 ,
& V_3 -> V_22 ) ) {
V_33 = F_25 ( V_3 -> V_6 . V_48 ,
struct V_32 ,
V_49 ) ;
if ( F_45 ( V_33 ) )
F_27 (
V_33 , V_76 ) ;
}
F_24 ( & V_3 -> V_4 ) ;
}
F_8 ( L_7 ) ;
}
void F_46 ( struct V_2 * V_3 )
{
F_6 ( L_22 , V_3 ) ;
F_28 ( & V_3 -> V_22 , V_75 ,
V_77 ,
V_53 ) ;
F_8 ( L_7 ) ;
}
void F_47 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
F_7 ( & V_78 ) ;
if ( ! V_3 ) {
F_7 ( & V_79 ) ;
F_8 ( L_23 ) ;
return;
}
F_6 ( L_21 , V_3 -> V_9 -> V_11 ) ;
F_5 ( ! V_3 -> V_9 -> V_74 ) ;
F_22 ( & V_3 -> V_4 ) ;
F_30 (object,
&cookie->backing_objects, cookie_link) {
F_27 ( V_33 , V_80 ) ;
}
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_7 ) ;
}
void F_48 ( struct V_2 * V_3 , int V_81 )
{
struct V_32 * V_33 ;
F_7 ( & V_82 ) ;
if ( V_81 )
F_7 ( & V_83 ) ;
if ( ! V_3 ) {
F_7 ( & V_84 ) ;
F_8 ( L_23 ) ;
return;
}
F_6 ( L_24 ,
V_3 , V_3 -> V_9 -> V_11 , V_3 -> V_10 ,
F_49 ( & V_3 -> V_21 ) , V_81 ) ;
F_43 ( F_49 ( & V_3 -> V_21 ) , > , 0 ) ;
if ( F_49 ( & V_3 -> V_20 ) != 0 ) {
F_50 ( V_85 L_25 ,
V_3 -> V_9 -> V_11 ) ;
F_51 () ;
}
F_52 ( V_86 , & V_3 -> V_22 ) ;
if ( V_81 )
F_52 ( V_87 , & V_3 -> V_22 ) ;
F_22 ( & V_3 -> V_4 ) ;
F_30 (object, &cookie->backing_objects, cookie_link) {
F_27 ( V_33 , V_88 ) ;
}
F_24 ( & V_3 -> V_4 ) ;
if ( ! F_53 ( & V_3 -> V_21 ) )
F_54 ( & V_3 -> V_21 , V_89 ,
V_53 ) ;
V_3 -> V_10 = NULL ;
V_3 -> V_9 = NULL ;
F_5 ( V_3 -> V_23 . V_90 ) ;
if ( V_3 -> V_7 ) {
F_43 ( F_49 ( & V_3 -> V_7 -> V_19 ) , > , 0 ) ;
F_43 ( F_49 ( & V_3 -> V_7 -> V_20 ) , > , 0 ) ;
F_14 ( & V_3 -> V_7 -> V_20 ) ;
}
F_43 ( F_49 ( & V_3 -> V_19 ) , > , 0 ) ;
F_55 ( V_3 ) ;
F_8 ( L_7 ) ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_2 * V_7 ;
F_6 ( L_22 , V_3 ) ;
for (; ; ) {
F_20 ( L_26 , V_3 ) ;
V_7 = V_3 -> V_7 ;
F_5 ( ! F_23 ( & V_3 -> V_6 ) ) ;
F_56 ( V_16 , V_3 ) ;
if ( ! V_7 )
break;
V_3 = V_7 ;
F_5 ( F_49 ( & V_3 -> V_19 ) <= 0 ) ;
if ( ! F_53 ( & V_3 -> V_19 ) )
break;
}
F_8 ( L_7 ) ;
}
int F_57 ( struct V_2 * V_3 )
{
struct V_91 * V_92 ;
struct V_32 * V_33 ;
int V_37 ;
F_6 ( L_27 , V_3 ) ;
F_43 ( V_3 -> V_9 -> type , == , V_27 ) ;
if ( F_58 ( V_3 ) < 0 )
return - V_93 ;
if ( F_23 ( & V_3 -> V_6 ) )
return 0 ;
V_92 = F_59 ( sizeof( * V_92 ) , V_94 | V_95 | V_96 ) ;
if ( ! V_92 )
return - V_97 ;
F_60 ( V_92 , NULL , NULL ) ;
V_92 -> V_22 = V_98 |
( 1 << V_99 ) |
( 1 << V_100 ) ;
F_22 ( & V_3 -> V_4 ) ;
if ( F_23 ( & V_3 -> V_6 ) )
goto V_101;
V_33 = F_25 ( V_3 -> V_6 . V_48 ,
struct V_32 , V_49 ) ;
if ( F_29 ( V_102 , & V_33 -> V_35 -> V_22 ) )
goto V_101;
V_92 -> V_61 = F_34 ( & V_103 ) ;
F_11 ( & V_3 -> V_21 ) ;
if ( F_61 ( V_33 , V_92 ) < 0 )
goto V_104;
F_24 ( & V_3 -> V_4 ) ;
V_37 = F_62 ( V_33 , V_92 ,
NULL , NULL , NULL ) ;
if ( V_37 == 0 ) {
V_37 = V_33 -> V_35 -> V_57 -> V_105 ( V_92 ) ;
F_63 ( V_92 , false ) ;
} else if ( V_37 == - V_54 ) {
V_37 = 0 ;
}
F_64 ( V_92 ) ;
F_8 ( L_11 , V_37 ) ;
return V_37 ;
V_104:
F_14 ( & V_3 -> V_21 ) ;
V_101:
F_24 ( & V_3 -> V_4 ) ;
F_65 ( V_92 ) ;
F_8 ( L_28 ) ;
return - V_106 ;
}
