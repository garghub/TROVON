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
void * V_10 ,
bool V_11 )
{
struct V_2 * V_3 ;
F_5 ( ! V_9 ) ;
F_6 ( L_1 ,
V_7 ? ( char * ) V_7 -> V_9 -> V_12 : L_2 ,
V_9 -> V_12 , V_10 , V_11 ) ;
F_7 ( & V_13 ) ;
if ( ! V_7 ) {
F_7 ( & V_14 ) ;
F_8 ( L_3 ) ;
return NULL ;
}
F_5 ( ! V_9 -> V_15 ) ;
F_5 ( ! V_9 -> V_12 [ 0 ] ) ;
F_5 ( V_9 -> type == V_16 &&
V_7 -> V_9 -> type != V_16 ) ;
V_3 = F_9 ( V_17 , V_18 ) ;
if ( ! V_3 ) {
F_7 ( & V_19 ) ;
F_8 ( L_4 ) ;
return NULL ;
}
F_10 ( & V_3 -> V_20 , 1 ) ;
F_10 ( & V_3 -> V_21 , 0 ) ;
F_10 ( & V_3 -> V_22 , 1 ) ;
F_11 ( & V_7 -> V_20 ) ;
F_11 ( & V_7 -> V_21 ) ;
V_3 -> V_9 = V_9 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_23 = ( 1 << V_24 ) ;
F_12 ( & V_3 -> V_25 , V_26 & ~ V_27 ) ;
switch ( V_3 -> V_9 -> type ) {
case V_16 :
F_7 ( & V_28 ) ;
break;
case V_29 :
F_7 ( & V_30 ) ;
break;
default:
F_7 ( & V_31 ) ;
break;
}
if ( V_11 ) {
if ( V_3 -> V_9 -> type != V_16 ) {
if ( F_13 ( V_3 ) == 0 ) {
F_14 ( V_32 , & V_3 -> V_23 ) ;
} else {
F_15 ( & V_7 -> V_21 ) ;
F_16 ( V_3 ) ;
F_7 ( & V_33 ) ;
F_8 ( L_5 ) ;
return NULL ;
}
} else {
F_14 ( V_32 , & V_3 -> V_23 ) ;
}
}
F_7 ( & V_34 ) ;
F_8 ( L_6 , V_3 ) ;
return V_3 ;
}
void F_17 ( struct V_2 * V_3 ,
bool (* F_18)( void * V_35 ) ,
void * V_35 )
{
F_6 ( L_7 , V_3 ) ;
F_19 ( & V_3 -> V_23 , V_36 ,
V_37 ) ;
if ( F_20 ( V_32 , & V_3 -> V_23 ) )
goto V_38;
if ( F_18 && ! F_18 ( V_35 ) ) {
} else if ( V_3 -> V_9 -> type != V_16 ) {
F_21 ( V_3 ) ;
if ( F_13 ( V_3 ) == 0 )
F_14 ( V_32 , & V_3 -> V_23 ) ;
} else {
F_14 ( V_32 , & V_3 -> V_23 ) ;
}
V_38:
F_22 ( V_36 , & V_3 -> V_23 ) ;
F_23 ( & V_3 -> V_23 , V_36 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
T_1 V_43 ;
int V_44 ;
F_6 ( L_8 ) ;
F_14 ( V_45 , & V_3 -> V_23 ) ;
F_24 ( & V_46 ) ;
if ( F_25 ( & V_47 ) ) {
F_26 ( & V_46 ) ;
F_8 ( L_9 ) ;
return 0 ;
}
V_42 = F_27 ( V_3 -> V_7 ) ;
if ( ! V_42 ) {
F_26 ( & V_46 ) ;
F_7 ( & V_48 ) ;
F_8 ( L_10 ) ;
return - V_49 ;
}
F_28 ( L_11 , V_42 -> V_50 -> V_12 ) ;
F_14 ( V_51 , & V_3 -> V_23 ) ;
V_44 = F_29 ( V_42 , V_3 ) ;
if ( V_44 < 0 ) {
F_26 ( & V_46 ) ;
F_8 ( L_12 , V_44 ) ;
return V_44 ;
}
V_3 -> V_9 -> V_52 ( V_3 -> V_10 , & V_43 ) ;
F_30 ( & V_3 -> V_4 ) ;
if ( F_31 ( & V_3 -> V_6 ) ) {
F_32 ( & V_3 -> V_4 ) ;
goto V_53;
}
V_40 = F_33 ( V_3 -> V_6 . V_54 ,
struct V_39 , V_55 ) ;
F_34 ( V_40 , V_43 ) ;
F_35 ( V_40 , V_56 ) ;
F_32 ( & V_3 -> V_4 ) ;
if ( ! V_57 ) {
F_28 ( L_13 , & V_3 -> V_23 ) ;
F_36 ( & V_3 -> V_23 , V_51 ,
V_37 ) ;
F_28 ( L_14 ) ;
if ( F_20 ( V_45 , & V_3 -> V_23 ) )
goto V_53;
}
F_26 ( & V_46 ) ;
F_8 ( L_15 ) ;
return 0 ;
V_53:
F_26 ( & V_46 ) ;
F_8 ( L_16 ) ;
return - V_58 ;
}
static int F_29 ( struct V_41 * V_42 ,
struct V_2 * V_3 )
{
struct V_39 * V_40 ;
int V_44 ;
F_6 ( L_17 , V_42 , V_3 , V_3 -> V_9 -> V_12 ) ;
F_30 ( & V_3 -> V_4 ) ;
F_37 (object, &cookie->backing_objects,
cookie_link) {
if ( V_40 -> V_42 == V_42 )
goto V_59;
}
F_32 ( & V_3 -> V_4 ) ;
F_7 ( & V_60 ) ;
V_40 = V_42 -> V_61 -> V_62 ( V_42 , V_3 ) ;
F_38 ( & V_60 ) ;
if ( F_39 ( V_40 ) ) {
F_7 ( & V_63 ) ;
V_44 = F_40 ( V_40 ) ;
goto error;
}
F_7 ( & V_64 ) ;
V_40 -> V_65 = F_41 ( & V_66 ) ;
F_28 ( L_18 ,
V_40 -> V_65 , V_3 -> V_9 -> V_12 , V_40 -> V_67 ) ;
V_44 = F_29 ( V_42 , V_3 -> V_7 ) ;
if ( V_44 < 0 )
goto V_68;
if ( F_42 ( V_3 , V_40 ) < 0 ) {
F_7 ( & V_69 ) ;
V_42 -> V_61 -> V_70 ( V_40 ) ;
F_38 ( & V_69 ) ;
}
F_8 ( L_19 ) ;
return 0 ;
V_59:
V_44 = - V_58 ;
if ( F_43 ( V_40 ) ||
F_44 ( V_40 ) ) {
F_32 ( & V_3 -> V_4 ) ;
goto error;
}
F_32 ( & V_3 -> V_4 ) ;
F_8 ( L_20 ) ;
return 0 ;
V_68:
F_7 ( & V_69 ) ;
V_42 -> V_61 -> V_70 ( V_40 ) ;
F_38 ( & V_69 ) ;
error:
F_8 ( L_12 , V_44 ) ;
return V_44 ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_39 * V_40 )
{
struct V_39 * V_71 ;
struct V_41 * V_42 = V_40 -> V_42 ;
int V_44 ;
F_6 ( L_21 , V_3 -> V_9 -> V_12 , V_40 -> V_65 ) ;
F_30 ( & V_3 -> V_4 ) ;
V_44 = - V_72 ;
F_37 (p, &cookie->backing_objects, cookie_link) {
if ( V_71 -> V_42 == V_40 -> V_42 ) {
if ( F_43 ( V_71 ) )
V_44 = - V_58 ;
goto V_73;
}
}
F_45 ( & V_3 -> V_7 -> V_4 , 1 ) ;
F_37 (p, &cookie->parent->backing_objects,
cookie_link) {
if ( V_71 -> V_42 == V_40 -> V_42 ) {
if ( F_43 ( V_71 ) ) {
V_44 = - V_58 ;
F_32 ( & V_3 -> V_7 -> V_4 ) ;
goto V_73;
}
V_40 -> V_7 = V_71 ;
F_30 ( & V_71 -> V_4 ) ;
V_71 -> V_21 ++ ;
F_32 ( & V_71 -> V_4 ) ;
break;
}
}
F_32 ( & V_3 -> V_7 -> V_4 ) ;
if ( F_25 ( & V_40 -> V_74 ) ) {
F_30 ( & V_42 -> V_75 ) ;
F_46 ( & V_40 -> V_74 , & V_42 -> V_76 ) ;
F_32 ( & V_42 -> V_75 ) ;
}
V_40 -> V_3 = V_3 ;
F_11 ( & V_3 -> V_20 ) ;
F_47 ( & V_40 -> V_55 , & V_3 -> V_6 ) ;
F_48 ( V_40 ) ;
V_44 = 0 ;
V_73:
F_32 ( & V_3 -> V_4 ) ;
F_8 ( L_12 , V_44 ) ;
return V_44 ;
}
void F_49 ( struct V_2 * V_3 )
{
struct V_39 * V_40 ;
F_6 ( L_22 , V_3 -> V_9 -> V_12 ) ;
F_7 ( & V_77 ) ;
F_50 ( V_3 -> V_9 -> type , == , V_29 ) ;
F_5 ( ! V_3 -> V_9 -> V_78 ) ;
if ( ! F_31 ( & V_3 -> V_6 ) ) {
F_30 ( & V_3 -> V_4 ) ;
if ( F_51 ( V_3 ) &&
! F_31 ( & V_3 -> V_6 ) &&
! F_52 ( V_79 ,
& V_3 -> V_23 ) ) {
V_40 = F_33 ( V_3 -> V_6 . V_54 ,
struct V_39 ,
V_55 ) ;
if ( F_53 ( V_40 ) )
F_35 (
V_40 , V_80 ) ;
}
F_32 ( & V_3 -> V_4 ) ;
}
F_8 ( L_8 ) ;
}
void F_21 ( struct V_2 * V_3 )
{
F_6 ( L_7 , V_3 ) ;
F_36 ( & V_3 -> V_23 , V_79 ,
V_37 ) ;
F_8 ( L_8 ) ;
}
void F_54 ( struct V_2 * V_3 )
{
struct V_39 * V_40 ;
F_7 ( & V_81 ) ;
if ( ! V_3 ) {
F_7 ( & V_82 ) ;
F_8 ( L_23 ) ;
return;
}
F_6 ( L_22 , V_3 -> V_9 -> V_12 ) ;
F_5 ( ! V_3 -> V_9 -> V_78 ) ;
F_30 ( & V_3 -> V_4 ) ;
if ( F_51 ( V_3 ) ) {
F_37 (object,
&cookie->backing_objects, cookie_link) {
F_35 ( V_40 , V_83 ) ;
}
}
F_32 ( & V_3 -> V_4 ) ;
F_8 ( L_8 ) ;
}
void F_55 ( struct V_2 * V_3 , bool V_84 )
{
struct V_39 * V_40 ;
bool V_85 = false ;
F_6 ( L_24 , V_3 , V_84 ) ;
F_50 ( F_56 ( & V_3 -> V_22 ) , > , 0 ) ;
if ( F_56 ( & V_3 -> V_21 ) != 0 ) {
F_57 ( L_25 ,
V_3 -> V_9 -> V_12 ) ;
F_58 () ;
}
F_19 ( & V_3 -> V_23 , V_36 ,
V_37 ) ;
if ( ! F_59 ( V_32 , & V_3 -> V_23 ) )
goto V_86;
F_21 ( V_3 ) ;
F_14 ( V_79 , & V_3 -> V_23 ) ;
F_30 ( & V_3 -> V_4 ) ;
if ( ! F_31 ( & V_3 -> V_6 ) ) {
F_37 (object, &cookie->backing_objects, cookie_link) {
if ( V_84 )
F_14 ( V_87 , & V_40 -> V_23 ) ;
F_60 ( V_88 , & V_40 -> V_23 ) ;
F_35 ( V_40 , V_89 ) ;
}
} else {
if ( F_59 ( V_79 , & V_3 -> V_23 ) )
V_85 = true ;
}
F_32 ( & V_3 -> V_4 ) ;
if ( V_85 )
F_23 ( & V_3 -> V_23 , V_79 ) ;
if ( ! F_61 ( & V_3 -> V_22 ) )
F_62 ( & V_3 -> V_22 , V_90 ,
V_37 ) ;
if ( V_3 -> V_9 -> type != V_16 )
F_63 ( V_3 ) ;
if ( ! F_20 ( V_91 , & V_3 -> V_23 ) ) {
F_11 ( & V_3 -> V_22 ) ;
F_14 ( V_24 , & V_3 -> V_23 ) ;
}
V_86:
F_22 ( V_36 , & V_3 -> V_23 ) ;
F_23 ( & V_3 -> V_23 , V_36 ) ;
F_8 ( L_8 ) ;
}
void F_64 ( struct V_2 * V_3 , bool V_92 )
{
F_7 ( & V_93 ) ;
if ( V_92 )
F_7 ( & V_94 ) ;
if ( ! V_3 ) {
F_7 ( & V_95 ) ;
F_8 ( L_23 ) ;
return;
}
F_6 ( L_26 ,
V_3 , V_3 -> V_9 -> V_12 , V_3 -> V_10 ,
F_56 ( & V_3 -> V_22 ) , V_92 ) ;
F_14 ( V_91 , & V_3 -> V_23 ) ;
F_55 ( V_3 , V_92 ) ;
V_3 -> V_10 = NULL ;
V_3 -> V_9 = NULL ;
F_5 ( V_3 -> V_25 . V_96 ) ;
if ( V_3 -> V_7 ) {
F_50 ( F_56 ( & V_3 -> V_7 -> V_20 ) , > , 0 ) ;
F_50 ( F_56 ( & V_3 -> V_7 -> V_21 ) , > , 0 ) ;
F_15 ( & V_3 -> V_7 -> V_21 ) ;
}
F_50 ( F_56 ( & V_3 -> V_20 ) , > , 0 ) ;
F_65 ( V_3 ) ;
F_8 ( L_8 ) ;
}
void F_16 ( struct V_2 * V_3 )
{
struct V_2 * V_7 ;
F_6 ( L_7 , V_3 ) ;
for (; ; ) {
F_28 ( L_27 , V_3 ) ;
V_7 = V_3 -> V_7 ;
F_5 ( ! F_31 ( & V_3 -> V_6 ) ) ;
F_66 ( V_17 , V_3 ) ;
if ( ! V_7 )
break;
V_3 = V_7 ;
F_5 ( F_56 ( & V_3 -> V_20 ) <= 0 ) ;
if ( ! F_61 ( & V_3 -> V_20 ) )
break;
}
F_8 ( L_8 ) ;
}
int F_67 ( struct V_2 * V_3 )
{
struct V_97 * V_98 ;
struct V_39 * V_40 ;
bool V_99 = false ;
int V_44 ;
F_6 ( L_28 , V_3 ) ;
F_50 ( V_3 -> V_9 -> type , == , V_29 ) ;
if ( F_68 ( V_3 ) < 0 )
return - V_100 ;
if ( F_31 ( & V_3 -> V_6 ) )
return 0 ;
V_98 = F_69 ( sizeof( * V_98 ) , V_101 | V_102 | V_103 ) ;
if ( ! V_98 )
return - V_104 ;
F_70 ( V_98 , NULL , NULL , NULL ) ;
V_98 -> V_23 = V_105 |
( 1 << V_106 ) |
( 1 << V_107 ) ;
F_30 ( & V_3 -> V_4 ) ;
if ( ! F_51 ( V_3 ) ||
F_31 ( & V_3 -> V_6 ) )
goto V_108;
V_40 = F_33 ( V_3 -> V_6 . V_54 ,
struct V_39 , V_55 ) ;
if ( F_20 ( V_109 , & V_40 -> V_42 -> V_23 ) )
goto V_108;
V_98 -> V_65 = F_41 ( & V_110 ) ;
F_71 ( V_3 ) ;
if ( F_72 ( V_40 , V_98 ) < 0 )
goto V_111;
F_32 ( & V_3 -> V_4 ) ;
V_44 = F_73 ( V_40 , V_98 , NULL , NULL ) ;
if ( V_44 == 0 ) {
V_44 = V_40 -> V_42 -> V_61 -> V_112 ( V_98 ) ;
F_74 ( V_98 , false ) ;
} else if ( V_44 == - V_58 ) {
V_44 = 0 ;
}
F_75 ( V_98 ) ;
F_8 ( L_12 , V_44 ) ;
return V_44 ;
V_111:
V_99 = F_76 ( V_3 ) ;
V_108:
F_32 ( & V_3 -> V_4 ) ;
if ( V_99 )
F_77 ( V_3 ) ;
F_78 ( V_98 ) ;
F_8 ( L_29 ) ;
return - V_113 ;
}
