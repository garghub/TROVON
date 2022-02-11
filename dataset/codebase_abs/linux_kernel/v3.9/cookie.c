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
int V_36 ;
F_6 ( L_16 , V_34 , V_3 , V_3 -> V_9 -> V_11 ) ;
F_22 ( & V_3 -> V_4 ) ;
F_30 (object, &cookie->backing_objects,
cookie_link) {
if ( V_32 -> V_34 == V_34 )
goto V_54;
}
F_24 ( & V_3 -> V_4 ) ;
F_7 ( & V_55 ) ;
V_32 = V_34 -> V_56 -> V_57 ( V_34 , V_3 ) ;
F_31 ( & V_55 ) ;
if ( F_32 ( V_32 ) ) {
F_7 ( & V_58 ) ;
V_36 = F_33 ( V_32 ) ;
goto error;
}
F_7 ( & V_59 ) ;
V_32 -> V_60 = F_34 ( & V_61 ) ;
F_20 ( L_17 ,
V_32 -> V_60 , V_3 -> V_9 -> V_11 , V_32 -> V_62 ) ;
V_36 = F_21 ( V_34 , V_3 -> V_7 ) ;
if ( V_36 < 0 )
goto V_63;
if ( F_35 ( V_3 , V_32 ) < 0 ) {
F_7 ( & V_64 ) ;
V_34 -> V_56 -> V_65 ( V_32 ) ;
F_31 ( & V_64 ) ;
}
F_8 ( L_18 ) ;
return 0 ;
V_54:
V_36 = - V_53 ;
if ( V_32 -> V_66 >= V_67 ) {
F_24 ( & V_3 -> V_4 ) ;
goto error;
}
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_19 ) ;
return 0 ;
V_63:
F_7 ( & V_64 ) ;
V_34 -> V_56 -> V_65 ( V_32 ) ;
F_31 ( & V_64 ) ;
error:
F_8 ( L_11 , V_36 ) ;
return V_36 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_31 * V_68 ;
struct V_33 * V_34 = V_32 -> V_34 ;
int V_36 ;
F_6 ( L_20 , V_3 -> V_9 -> V_11 , V_32 -> V_60 ) ;
F_22 ( & V_3 -> V_4 ) ;
V_36 = - V_69 ;
F_30 (p, &cookie->backing_objects, cookie_link) {
if ( V_68 -> V_34 == V_32 -> V_34 ) {
if ( V_68 -> V_66 >= V_67 )
V_36 = - V_53 ;
goto V_70;
}
}
F_36 ( & V_3 -> V_7 -> V_4 , 1 ) ;
F_30 (p, &cookie->parent->backing_objects,
cookie_link) {
if ( V_68 -> V_34 == V_32 -> V_34 ) {
if ( V_68 -> V_66 >= V_67 ) {
V_36 = - V_53 ;
F_24 ( & V_3 -> V_7 -> V_4 ) ;
goto V_70;
}
V_32 -> V_7 = V_68 ;
F_22 ( & V_68 -> V_4 ) ;
V_68 -> V_20 ++ ;
F_24 ( & V_68 -> V_4 ) ;
break;
}
}
F_24 ( & V_3 -> V_7 -> V_4 ) ;
if ( F_17 ( & V_32 -> V_71 ) ) {
F_22 ( & V_34 -> V_72 ) ;
F_37 ( & V_32 -> V_71 , & V_34 -> V_73 ) ;
F_24 ( & V_34 -> V_72 ) ;
}
V_32 -> V_3 = V_3 ;
F_11 ( & V_3 -> V_19 ) ;
F_38 ( & V_32 -> V_49 , & V_3 -> V_6 ) ;
F_39 ( V_32 ) ;
V_36 = 0 ;
V_70:
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_11 , V_36 ) ;
return V_36 ;
}
void F_40 ( struct V_2 * V_3 )
{
struct V_31 * V_32 ;
F_6 ( L_21 , V_3 -> V_9 -> V_11 ) ;
F_7 ( & V_74 ) ;
F_41 ( V_3 -> V_9 -> type , == , V_26 ) ;
F_5 ( ! V_3 -> V_9 -> V_75 ) ;
if ( ! F_23 ( & V_3 -> V_6 ) ) {
F_22 ( & V_3 -> V_4 ) ;
if ( ! F_23 ( & V_3 -> V_6 ) &&
! F_42 ( V_76 ,
& V_3 -> V_21 ) ) {
V_32 = F_25 ( V_3 -> V_6 . V_48 ,
struct V_31 ,
V_49 ) ;
if ( V_32 -> V_66 < V_67 )
F_43 (
V_32 , V_77 ) ;
}
F_24 ( & V_3 -> V_4 ) ;
}
F_8 ( L_7 ) ;
}
void F_44 ( struct V_2 * V_3 )
{
F_6 ( L_22 , V_3 ) ;
F_28 ( & V_3 -> V_21 , V_76 ,
V_78 ,
V_52 ) ;
F_8 ( L_7 ) ;
}
void F_45 ( struct V_2 * V_3 )
{
struct V_31 * V_32 ;
F_7 ( & V_79 ) ;
if ( ! V_3 ) {
F_7 ( & V_80 ) ;
F_8 ( L_23 ) ;
return;
}
F_6 ( L_21 , V_3 -> V_9 -> V_11 ) ;
F_5 ( ! V_3 -> V_9 -> V_75 ) ;
F_22 ( & V_3 -> V_4 ) ;
F_30 (object,
&cookie->backing_objects, cookie_link) {
F_43 ( V_32 , V_81 ) ;
}
F_24 ( & V_3 -> V_4 ) ;
F_8 ( L_7 ) ;
}
void F_46 ( struct V_2 * V_3 , int V_82 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
unsigned long V_83 ;
F_7 ( & V_84 ) ;
if ( V_82 )
F_7 ( & V_85 ) ;
if ( ! V_3 ) {
F_7 ( & V_86 ) ;
F_8 ( L_23 ) ;
return;
}
F_6 ( L_24 ,
V_3 , V_3 -> V_9 -> V_11 , V_3 -> V_10 , V_82 ) ;
if ( F_47 ( & V_3 -> V_20 ) != 0 ) {
F_48 ( V_87 L_25 ,
V_3 -> V_9 -> V_11 ) ;
F_49 () ;
}
if ( F_29 ( V_44 , & V_3 -> V_21 ) ) {
F_7 ( & V_88 ) ;
F_28 ( & V_3 -> V_21 , V_44 ,
V_51 , V_52 ) ;
}
V_83 = V_82 ? V_89 : V_90 ;
V_91:
F_22 ( & V_3 -> V_4 ) ;
while ( ! F_23 ( & V_3 -> V_6 ) ) {
int V_92 ;
V_32 = F_25 ( V_3 -> V_6 . V_48 ,
struct V_31 ,
V_49 ) ;
F_20 ( L_26 , V_32 -> V_60 ) ;
F_50 ( V_93 , & V_3 -> V_21 ) ;
V_92 = F_47 ( & V_32 -> V_92 ) ;
if ( V_92 ) {
int V_94 = V_32 -> V_94 ;
int V_95 = V_32 -> V_95 ;
F_24 ( & V_3 -> V_4 ) ;
F_48 ( V_87 L_27
L_28 ,
V_3 -> V_9 -> V_11 ,
V_92 , V_94 , V_95 ) ;
F_28 ( & V_3 -> V_21 , V_93 ,
V_51 , V_52 ) ;
F_48 ( L_29 ) ;
goto V_91;
}
F_22 ( & V_32 -> V_4 ) ;
F_51 ( & V_32 -> V_49 ) ;
V_34 = V_32 -> V_34 ;
V_32 -> V_3 = NULL ;
F_43 ( V_32 , V_83 ) ;
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
