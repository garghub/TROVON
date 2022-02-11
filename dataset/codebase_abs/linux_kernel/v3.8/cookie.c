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
F_11 ( & V_7 -> V_19 ) ;
F_11 ( & V_7 -> V_20 ) ;
V_3 -> V_9 = V_9 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_21 = 0 ;
F_12 ( & V_3 -> V_22 , V_23 & ~ V_24 ) ;
switch ( V_3 -> V_9 -> type ) {
case V_15 :
F_7 ( & V_25 ) ;
break;
case V_26 :
F_7 ( & V_27 ) ;
break;
default:
F_7 ( & V_28 ) ;
break;
}
if ( V_3 -> V_9 -> type != V_15 ) {
if ( F_13 ( V_3 ) < 0 ) {
F_14 ( & V_7 -> V_20 ) ;
F_15 ( V_3 ) ;
F_7 ( & V_29 ) ;
F_8 ( L_5 ) ;
return NULL ;
}
}
F_7 ( & V_30 ) ;
F_8 ( L_6 , V_3 ) ;
return V_3 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_1 V_35 ;
int V_36 ;
F_6 ( L_7 ) ;
V_3 -> V_21 = 1 << V_37 ;
F_16 ( & V_38 ) ;
if ( F_17 ( & V_39 ) ) {
F_18 ( & V_38 ) ;
F_8 ( L_8 ) ;
return 0 ;
}
V_34 = F_19 ( V_3 -> V_7 ) ;
if ( ! V_34 ) {
F_18 ( & V_38 ) ;
F_7 ( & V_40 ) ;
F_8 ( L_9 ) ;
return - V_41 ;
}
F_20 ( L_10 , V_34 -> V_42 -> V_11 ) ;
V_3 -> V_21 =
( 1 << V_43 ) |
( 1 << V_44 ) |
( 1 << V_45 ) ;
V_36 = F_21 ( V_34 , V_3 ) ;
if ( V_36 < 0 ) {
F_18 ( & V_38 ) ;
F_8 ( L_11 , V_36 ) ;
return V_36 ;
}
V_3 -> V_9 -> V_46 ( V_3 -> V_10 , & V_35 ) ;
F_22 ( & V_3 -> V_4 ) ;
if ( F_23 ( & V_3 -> V_6 ) ) {
F_24 ( & V_3 -> V_4 ) ;
goto V_47;
}
V_32 = F_25 ( V_3 -> V_6 . V_48 ,
struct V_31 , V_49 ) ;
F_26 ( V_32 , V_35 ) ;
F_27 ( V_32 ) ;
F_24 ( & V_3 -> V_4 ) ;
if ( ! V_50 ) {
F_20 ( L_12 , & V_3 -> V_21 ) ;
F_28 ( & V_3 -> V_21 , V_43 ,
V_51 , V_52 ) ;
F_20 ( L_13 ) ;
if ( F_29 ( V_37 , & V_3 -> V_21 ) )
goto V_47;
}
F_18 ( & V_38 ) ;
F_8 ( L_14 ) ;
return 0 ;
V_47:
F_18 ( & V_38 ) ;
F_8 ( L_15 ) ;
return - V_53 ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 ;
struct V_54 * V_55 ;
int V_36 ;
F_6 ( L_16 , V_34 , V_3 , V_3 -> V_9 -> V_11 ) ;
F_22 ( & V_3 -> V_4 ) ;
F_30 (object, _n, &cookie->backing_objects,
cookie_link) {
if ( V_32 -> V_34 == V_34 )
goto V_56;
}
F_24 ( & V_3 -> V_4 ) ;
F_7 ( & V_57 ) ;
V_32 = V_34 -> V_58 -> V_59 ( V_34 , V_3 ) ;
F_31 ( & V_57 ) ;
if ( F_32 ( V_32 ) ) {
F_7 ( & V_60 ) ;
V_36 = F_33 ( V_32 ) ;
goto error;
}
F_7 ( & V_61 ) ;
V_32 -> V_62 = F_34 ( & V_63 ) ;
F_20 ( L_17 ,
V_32 -> V_62 , V_3 -> V_9 -> V_11 , V_32 -> V_64 ) ;
V_36 = F_21 ( V_34 , V_3 -> V_7 ) ;
if ( V_36 < 0 )
goto V_65;
if ( F_35 ( V_3 , V_32 ) < 0 ) {
F_7 ( & V_66 ) ;
V_34 -> V_58 -> V_67 ( V_32 ) ;
F_31 ( & V_66 ) ;
}
F_8 ( L_18 ) ;
return 0 ;
V_56:
V_36 = - V_53 ;
if ( V_32 -> V_68 >= V_69 ) {
F_24 ( & V_3 -> V_4 ) ;
goto error;
}
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_19 ) ;
return 0 ;
V_65:
F_7 ( & V_66 ) ;
V_34 -> V_58 -> V_67 ( V_32 ) ;
F_31 ( & V_66 ) ;
error:
F_8 ( L_11 , V_36 ) ;
return V_36 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_31 * V_70 ;
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_54 * V_55 ;
int V_36 ;
F_6 ( L_20 , V_3 -> V_9 -> V_11 , V_32 -> V_62 ) ;
F_22 ( & V_3 -> V_4 ) ;
V_36 = - V_71 ;
F_30 (p, _n, &cookie->backing_objects, cookie_link) {
if ( V_70 -> V_34 == V_32 -> V_34 ) {
if ( V_70 -> V_68 >= V_69 )
V_36 = - V_53 ;
goto V_72;
}
}
F_36 ( & V_3 -> V_7 -> V_4 , 1 ) ;
F_30 (p, _n, &cookie->parent->backing_objects,
cookie_link) {
if ( V_70 -> V_34 == V_32 -> V_34 ) {
if ( V_70 -> V_68 >= V_69 ) {
V_36 = - V_53 ;
F_24 ( & V_3 -> V_7 -> V_4 ) ;
goto V_72;
}
V_32 -> V_7 = V_70 ;
F_22 ( & V_70 -> V_4 ) ;
V_70 -> V_20 ++ ;
F_24 ( & V_70 -> V_4 ) ;
break;
}
}
F_24 ( & V_3 -> V_7 -> V_4 ) ;
if ( F_17 ( & V_32 -> V_73 ) ) {
F_22 ( & V_34 -> V_74 ) ;
F_37 ( & V_32 -> V_73 , & V_34 -> V_75 ) ;
F_24 ( & V_34 -> V_74 ) ;
}
V_32 -> V_3 = V_3 ;
F_11 ( & V_3 -> V_19 ) ;
F_38 ( & V_32 -> V_49 , & V_3 -> V_6 ) ;
F_39 ( V_32 ) ;
V_36 = 0 ;
V_72:
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_11 , V_36 ) ;
return V_36 ;
}
void F_40 ( struct V_2 * V_3 )
{
struct V_31 * V_32 ;
F_6 ( L_21 , V_3 -> V_9 -> V_11 ) ;
F_7 ( & V_76 ) ;
F_41 ( V_3 -> V_9 -> type , == , V_26 ) ;
F_5 ( ! V_3 -> V_9 -> V_77 ) ;
if ( ! F_23 ( & V_3 -> V_6 ) ) {
F_22 ( & V_3 -> V_4 ) ;
if ( ! F_23 ( & V_3 -> V_6 ) &&
! F_42 ( V_78 ,
& V_3 -> V_21 ) ) {
V_32 = F_25 ( V_3 -> V_6 . V_48 ,
struct V_31 ,
V_49 ) ;
if ( V_32 -> V_68 < V_69 )
F_43 (
V_32 , V_79 ) ;
}
F_24 ( & V_3 -> V_4 ) ;
}
F_8 ( L_7 ) ;
}
void F_44 ( struct V_2 * V_3 )
{
F_6 ( L_22 , V_3 ) ;
F_28 ( & V_3 -> V_21 , V_78 ,
V_80 ,
V_52 ) ;
F_8 ( L_7 ) ;
}
void F_45 ( struct V_2 * V_3 )
{
struct V_31 * V_32 ;
struct V_54 * V_81 ;
F_7 ( & V_82 ) ;
if ( ! V_3 ) {
F_7 ( & V_83 ) ;
F_8 ( L_23 ) ;
return;
}
F_6 ( L_21 , V_3 -> V_9 -> V_11 ) ;
F_5 ( ! V_3 -> V_9 -> V_77 ) ;
F_22 ( & V_3 -> V_4 ) ;
F_30 (object, _p,
&cookie->backing_objects, cookie_link) {
F_43 ( V_32 , V_84 ) ;
}
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_7 ) ;
}
void F_46 ( struct V_2 * V_3 , int V_85 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
unsigned long V_86 ;
F_7 ( & V_87 ) ;
if ( V_85 )
F_7 ( & V_88 ) ;
if ( ! V_3 ) {
F_7 ( & V_89 ) ;
F_8 ( L_23 ) ;
return;
}
F_6 ( L_24 ,
V_3 , V_3 -> V_9 -> V_11 , V_3 -> V_10 , V_85 ) ;
if ( F_47 ( & V_3 -> V_20 ) != 0 ) {
F_48 ( V_90 L_25 ,
V_3 -> V_9 -> V_11 ) ;
F_49 () ;
}
if ( F_29 ( V_44 , & V_3 -> V_21 ) ) {
F_7 ( & V_91 ) ;
F_28 ( & V_3 -> V_21 , V_44 ,
V_51 , V_52 ) ;
}
V_86 = V_85 ? V_92 : V_93 ;
V_94:
F_22 ( & V_3 -> V_4 ) ;
while ( ! F_23 ( & V_3 -> V_6 ) ) {
int V_95 ;
V_32 = F_25 ( V_3 -> V_6 . V_48 ,
struct V_31 ,
V_49 ) ;
F_20 ( L_26 , V_32 -> V_62 ) ;
F_50 ( V_96 , & V_3 -> V_21 ) ;
V_95 = F_47 ( & V_32 -> V_95 ) ;
if ( V_95 ) {
int V_97 = V_32 -> V_97 ;
int V_98 = V_32 -> V_98 ;
F_24 ( & V_3 -> V_4 ) ;
F_48 ( V_90 L_27
L_28 ,
V_3 -> V_9 -> V_11 ,
V_95 , V_97 , V_98 ) ;
F_28 ( & V_3 -> V_21 , V_96 ,
V_51 , V_52 ) ;
F_48 ( L_29 ) ;
goto V_94;
}
F_22 ( & V_32 -> V_4 ) ;
F_51 ( & V_32 -> V_49 ) ;
V_34 = V_32 -> V_34 ;
V_32 -> V_3 = NULL ;
F_43 ( V_32 , V_86 ) ;
F_24 ( & V_32 -> V_4 ) ;
if ( F_52 ( & V_3 -> V_19 ) )
F_49 () ;
}
V_3 -> V_10 = NULL ;
V_3 -> V_9 = NULL ;
F_24 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_7 ) {
F_41 ( F_47 ( & V_3 -> V_7 -> V_19 ) , > , 0 ) ;
F_41 ( F_47 ( & V_3 -> V_7 -> V_20 ) , > , 0 ) ;
F_14 ( & V_3 -> V_7 -> V_20 ) ;
}
F_41 ( F_47 ( & V_3 -> V_19 ) , > , 0 ) ;
F_53 ( V_3 ) ;
F_8 ( L_7 ) ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_2 * V_7 ;
F_6 ( L_22 , V_3 ) ;
for (; ; ) {
F_20 ( L_30 , V_3 ) ;
V_7 = V_3 -> V_7 ;
F_5 ( ! F_23 ( & V_3 -> V_6 ) ) ;
F_54 ( V_16 , V_3 ) ;
if ( ! V_7 )
break;
V_3 = V_7 ;
F_5 ( F_47 ( & V_3 -> V_19 ) <= 0 ) ;
if ( ! F_52 ( & V_3 -> V_19 ) )
break;
}
F_8 ( L_7 ) ;
}
