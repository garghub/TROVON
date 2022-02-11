struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( ! V_2 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
F_2 ( ! V_4 ) ;
return V_4 -> V_6 ;
}
static struct V_7 * F_4 ( struct V_2 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( ! V_2 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
F_2 ( ! V_4 ) ;
return & V_4 -> V_8 ;
}
static void F_5 ( struct V_9 * V_10 )
{
F_6 ( * V_10 -> V_11 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
F_8 ( * V_10 -> V_11 ) ;
}
static int F_9 ( struct V_9 * V_10 )
{
int V_12 , V_13 = 0 ;
F_10 (i)
V_13 += * F_11 ( V_10 -> V_11 , V_12 ) ;
return V_13 ;
}
static struct V_9 * F_12 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
struct V_9 * V_16 ;
V_8 = F_4 ( F_13 ( V_15 ) ) ;
F_2 ( ! V_8 ) ;
V_16 = F_14 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_11 = F_15 ( int ) ;
if ( ! V_16 -> V_11 ) {
F_16 ( V_16 ) ;
return NULL ;
}
V_16 -> V_18 = V_15 ;
F_17 ( V_15 ) ;
return V_16 ;
}
static struct V_9 * F_18 ( struct V_14 * V_15 )
{
struct V_7 * V_8 =
F_4 ( F_13 ( V_15 ) ) ;
struct V_9 * V_16 ;
F_2 ( ! V_8 ) ;
F_19 (caifd, &caifdevs->list, list) {
if ( V_16 -> V_18 == V_15 )
return V_16 ;
}
return NULL ;
}
static int F_20 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
int V_23 ;
struct V_9 * V_16 =
F_21 ( V_20 , struct V_9 , V_20 ) ;
struct V_24 * V_25 ;
V_25 = F_22 ( V_22 ) ;
V_25 -> V_15 = V_16 -> V_18 ;
V_23 = F_23 ( V_25 ) ;
if ( V_23 > 0 )
V_23 = - V_26 ;
return V_23 ;
}
static int F_24 ( struct V_24 * V_25 , struct V_14 * V_15 ,
struct V_27 * V_28 , struct V_14 * V_29 )
{
struct V_21 * V_22 ;
struct V_9 * V_16 ;
int V_23 ;
V_22 = F_25 ( V_30 , V_25 ) ;
F_26 () ;
V_16 = F_18 ( V_15 ) ;
if ( ! V_16 || ! V_16 -> V_20 . V_31 || ! V_16 -> V_20 . V_31 -> F_24 ||
! F_27 ( V_16 -> V_18 ) ) {
F_28 () ;
F_29 ( V_25 ) ;
return V_32 ;
}
F_7 ( V_16 ) ;
F_28 () ;
V_23 = V_16 -> V_20 . V_31 -> F_24 ( V_16 -> V_20 . V_31 , V_22 ) ;
if ( V_23 == - V_33 )
F_30 ( V_22 ) ;
F_5 ( V_16 ) ;
return 0 ;
}
static void F_31 ( struct V_14 * V_15 , int V_34 )
{
struct V_9 * V_16 ;
F_26 () ;
V_16 = F_18 ( V_15 ) ;
if ( ! V_16 || ! V_16 -> V_20 . V_31 || ! V_16 -> V_20 . V_31 -> V_35 ) {
F_28 () ;
return;
}
F_7 ( V_16 ) ;
F_28 () ;
V_16 -> V_20 . V_31 -> V_35 ( V_16 -> V_20 . V_31 ,
V_34 ?
V_36 :
V_37 ,
V_16 -> V_20 . V_38 ) ;
F_5 ( V_16 ) ;
}
static int F_32 ( struct V_39 * V_40 , unsigned long V_41 ,
void * V_42 )
{
struct V_14 * V_15 = V_42 ;
struct V_9 * V_16 = NULL ;
struct V_43 * V_44 ;
enum V_45 V_46 ;
enum V_47 V_48 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
if ( V_15 -> type != V_49 )
return 0 ;
V_6 = F_1 ( F_13 ( V_15 ) ) ;
if ( V_6 == NULL )
return 0 ;
V_8 = F_4 ( F_13 ( V_15 ) ) ;
switch ( V_41 ) {
case V_50 :
V_16 = F_12 ( V_15 ) ;
if ( ! V_16 )
return 0 ;
V_44 = F_33 ( V_15 ) ;
V_44 -> V_51 = F_31 ;
V_16 -> V_20 . F_20 = F_20 ;
if ( V_44 -> V_52 )
V_48 = V_53 ;
else
V_48 = V_54 ;
switch ( V_44 -> V_55 ) {
case V_56 :
V_46 = V_57 ;
break;
case V_58 :
V_46 = V_59 ;
break;
default:
V_46 = V_57 ;
break;
}
strncpy ( V_16 -> V_20 . V_60 , V_15 -> V_60 ,
sizeof( V_16 -> V_20 . V_60 ) - 1 ) ;
V_16 -> V_20 . V_60 [ sizeof( V_16 -> V_20 . V_60 ) - 1 ] = 0 ;
F_34 ( & V_8 -> V_61 ) ;
F_35 ( & V_16 -> V_62 , & V_8 -> V_62 ) ;
F_36 ( V_6 ,
V_48 ,
V_15 ,
& V_16 -> V_20 ,
V_46 ,
V_44 -> V_63 ,
V_44 -> V_64 ) ;
F_37 ( & V_8 -> V_61 ) ;
break;
case V_65 :
F_26 () ;
V_16 = F_18 ( V_15 ) ;
if ( V_16 == NULL ) {
F_28 () ;
break;
}
F_38 ( V_6 , & V_16 -> V_20 , true ) ;
F_28 () ;
break;
case V_66 :
F_26 () ;
V_16 = F_18 ( V_15 ) ;
if ( ! V_16 || ! V_16 -> V_20 . V_31 || ! V_16 -> V_20 . V_31 -> V_35 ) {
F_28 () ;
return - V_67 ;
}
F_38 ( V_6 , & V_16 -> V_20 , false ) ;
F_7 ( V_16 ) ;
F_28 () ;
V_16 -> V_20 . V_31 -> V_35 ( V_16 -> V_20 . V_31 ,
V_68 ,
V_16 -> V_20 . V_38 ) ;
F_5 ( V_16 ) ;
break;
case V_69 :
F_34 ( & V_8 -> V_61 ) ;
V_16 = F_18 ( V_15 ) ;
if ( V_16 == NULL ) {
F_37 ( & V_8 -> V_61 ) ;
break;
}
F_39 ( & V_16 -> V_62 ) ;
if ( F_9 ( V_16 ) != 0 ||
F_40 ( V_6 , & V_16 -> V_20 ) != 0 ) {
F_41 ( L_1 ) ;
F_35 ( & V_16 -> V_62 , & V_8 -> V_62 ) ;
F_37 ( & V_8 -> V_61 ) ;
break;
}
F_42 () ;
F_43 ( V_16 -> V_18 ) ;
F_44 ( V_16 -> V_11 ) ;
F_16 ( V_16 ) ;
F_37 ( & V_8 -> V_61 ) ;
break;
}
return 0 ;
}
static int F_45 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 , V_5 ) ;
F_2 ( ! V_4 ) ;
F_46 ( & V_4 -> V_8 . V_62 ) ;
F_47 ( & V_4 -> V_8 . V_61 ) ;
V_4 -> V_6 = F_48 () ;
if ( ! V_4 -> V_6 ) {
F_49 ( L_2 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_50 ( struct V_2 * V_2 )
{
struct V_9 * V_16 , * V_71 ;
struct V_7 * V_8 =
F_4 ( V_2 ) ;
struct V_1 * V_6 ;
F_51 () ;
F_34 ( & V_8 -> V_61 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == NULL ) {
F_37 ( & V_8 -> V_61 ) ;
return;
}
F_52 (caifd, tmp, &caifdevs->list, list) {
int V_12 = 0 ;
F_39 ( & V_16 -> V_62 ) ;
F_38 ( V_6 , & V_16 -> V_20 , false ) ;
while ( V_12 < 10 &&
( F_9 ( V_16 ) != 0 ||
F_40 ( V_6 , & V_16 -> V_20 ) != 0 ) ) {
F_41 ( L_1 ) ;
F_53 ( 250 ) ;
V_12 ++ ;
}
F_42 () ;
F_43 ( V_16 -> V_18 ) ;
F_44 ( V_16 -> V_11 ) ;
F_16 ( V_16 ) ;
}
F_54 ( V_6 ) ;
F_37 ( & V_8 -> V_61 ) ;
F_55 () ;
}
static int T_1 F_56 ( void )
{
int V_72 ;
V_72 = F_57 ( & V_73 ) ;
if ( V_72 )
return V_72 ;
F_58 ( & V_74 ) ;
F_59 ( & V_75 ) ;
return V_72 ;
}
static void T_2 F_60 ( void )
{
F_61 ( & V_73 ) ;
F_62 ( & V_74 ) ;
F_63 ( & V_75 ) ;
}
