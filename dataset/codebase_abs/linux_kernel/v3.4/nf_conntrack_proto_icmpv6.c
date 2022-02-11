static bool F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 )
{
const struct V_6 * V_7 ;
struct V_6 V_8 ;
V_7 = F_2 ( V_2 , V_3 , sizeof( V_8 ) , & V_8 ) ;
if ( V_7 == NULL )
return false ;
V_5 -> V_9 . V_10 . V_11 . type = V_7 -> V_12 ;
V_5 -> V_13 . V_10 . V_11 . V_14 = V_7 -> V_15 ;
V_5 -> V_9 . V_10 . V_11 . V_16 = V_7 -> V_17 ;
return true ;
}
static bool F_3 ( struct V_4 * V_5 ,
const struct V_4 * V_18 )
{
int type = V_18 -> V_9 . V_10 . V_11 . type - 128 ;
if ( type < 0 || type >= sizeof( V_19 ) || ! V_19 [ type ] )
return false ;
V_5 -> V_13 . V_10 . V_11 . V_14 = V_18 -> V_13 . V_10 . V_11 . V_14 ;
V_5 -> V_9 . V_10 . V_11 . type = V_19 [ type ] - 1 ;
V_5 -> V_9 . V_10 . V_11 . V_16 = V_18 -> V_9 . V_10 . V_11 . V_16 ;
return true ;
}
static int F_4 ( struct V_20 * V_21 ,
const struct V_4 * V_5 )
{
return F_5 ( V_21 , L_1 ,
V_5 -> V_9 . V_10 . V_11 . type ,
V_5 -> V_9 . V_10 . V_11 . V_16 ,
F_6 ( V_5 -> V_13 . V_10 . V_11 . V_14 ) ) ;
}
static unsigned int * F_7 ( struct V_22 * V_22 )
{
return & V_23 ;
}
static int F_8 ( struct V_24 * V_25 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_26 V_27 ,
T_1 V_28 ,
unsigned int V_29 ,
unsigned int * V_30 )
{
F_9 ( V_25 , V_27 , V_2 , * V_30 ) ;
return V_31 ;
}
static bool F_10 ( struct V_24 * V_25 , const struct V_1 * V_2 ,
unsigned int V_3 , unsigned int * V_32 )
{
static const T_1 V_33 [] = {
[ V_34 - 128 ] = 1 ,
[ V_35 - 128 ] = 1
} ;
int type = V_25 -> V_36 [ 0 ] . V_5 . V_9 . V_10 . V_11 . type - 128 ;
if ( type < 0 || type >= sizeof( V_33 ) || ! V_33 [ type ] ) {
F_11 ( L_2 ,
type + 128 ) ;
F_12 ( & V_25 -> V_36 [ 0 ] . V_5 ) ;
if ( F_13 ( F_14 ( V_25 ) , V_37 ) )
F_15 ( V_38 , 0 , V_2 , NULL , NULL , NULL ,
L_3 ,
type + 128 ) ;
return false ;
}
return true ;
}
static int
F_16 ( struct V_22 * V_22 , struct V_24 * V_39 ,
struct V_1 * V_2 ,
unsigned int V_40 ,
enum V_26 * V_27 ,
unsigned int V_29 )
{
struct V_4 V_41 , V_42 ;
const struct V_43 * V_44 ;
const struct V_45 * V_46 ;
T_2 V_47 = V_39 ? F_17 ( V_39 ) : V_48 ;
F_18 ( V_2 -> V_49 == NULL ) ;
if ( ! F_19 ( V_2 ,
F_20 ( V_2 )
+ sizeof( struct V_50 )
+ sizeof( struct V_6 ) ,
V_38 , & V_42 ) ) {
F_11 ( L_4 ) ;
return - V_31 ;
}
V_46 = F_21 ( V_38 , V_42 . V_9 . V_51 ) ;
if ( ! F_22 ( & V_41 , & V_42 ,
& V_52 , V_46 ) ) {
F_11 ( L_5 ) ;
return - V_31 ;
}
* V_27 = V_53 ;
V_44 = F_23 ( V_22 , V_47 , & V_41 ) ;
if ( ! V_44 ) {
F_11 ( L_6 ) ;
return - V_31 ;
} else {
if ( F_24 ( V_44 ) == V_54 )
* V_27 += V_55 ;
}
V_2 -> V_49 = & F_25 ( V_44 ) -> V_56 ;
V_2 -> V_57 = * V_27 ;
return V_31 ;
}
static int
F_26 ( struct V_22 * V_22 , struct V_24 * V_39 ,
struct V_1 * V_2 , unsigned int V_3 ,
enum V_26 * V_27 , T_1 V_28 , unsigned int V_29 )
{
const struct V_6 * V_58 ;
struct V_6 V_59 ;
int type ;
V_58 = F_2 ( V_2 , V_3 , sizeof( V_59 ) , & V_59 ) ;
if ( V_58 == NULL ) {
if ( F_13 ( V_22 , V_37 ) )
F_15 ( V_38 , 0 , V_2 , NULL , NULL , NULL ,
L_7 ) ;
return - V_31 ;
}
if ( V_22 -> V_25 . V_60 && V_29 == V_61 &&
F_27 ( V_2 , V_29 , V_3 , V_37 ) ) {
if ( F_13 ( V_22 , V_37 ) )
F_15 ( V_38 , 0 , V_2 , NULL , NULL , NULL ,
L_8 ) ;
return - V_31 ;
}
type = V_58 -> V_12 - 130 ;
if ( type >= 0 && type < sizeof( V_62 ) &&
V_62 [ type ] ) {
V_2 -> V_49 = & F_28 () -> V_56 ;
V_2 -> V_57 = V_63 ;
F_29 ( V_2 -> V_49 ) ;
return V_31 ;
}
if ( V_58 -> V_12 >= 128 )
return V_31 ;
return F_16 ( V_22 , V_39 , V_2 , V_3 , V_27 , V_29 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_4 * V_64 )
{
F_31 ( V_2 , V_65 , V_64 -> V_13 . V_10 . V_11 . V_14 ) ;
F_32 ( V_2 , V_66 , V_64 -> V_9 . V_10 . V_11 . type ) ;
F_32 ( V_2 , V_67 , V_64 -> V_9 . V_10 . V_11 . V_16 ) ;
return 0 ;
V_68:
return - 1 ;
}
static int F_33 ( struct V_69 * V_70 [] ,
struct V_4 * V_5 )
{
if ( ! V_70 [ V_66 ] ||
! V_70 [ V_67 ] ||
! V_70 [ V_65 ] )
return - V_71 ;
V_5 -> V_9 . V_10 . V_11 . type = F_34 ( V_70 [ V_66 ] ) ;
V_5 -> V_9 . V_10 . V_11 . V_16 = F_34 ( V_70 [ V_67 ] ) ;
V_5 -> V_13 . V_10 . V_11 . V_14 = F_35 ( V_70 [ V_65 ] ) ;
if ( V_5 -> V_9 . V_10 . V_11 . type < 128 ||
V_5 -> V_9 . V_10 . V_11 . type - 128 >= sizeof( V_19 ) ||
! V_19 [ V_5 -> V_9 . V_10 . V_11 . type - 128 ] )
return - V_71 ;
return 0 ;
}
static int F_36 ( void )
{
return F_37 ( V_72 , V_73 + 1 ) ;
}
static int F_38 ( struct V_69 * V_70 [] , void * V_74 )
{
unsigned int * V_30 = V_74 ;
if ( V_70 [ V_75 ] ) {
* V_30 =
F_39 ( F_40 ( V_70 [ V_75 ] ) ) * V_76 ;
} else {
* V_30 = V_23 ;
}
return 0 ;
}
static int
F_41 ( struct V_1 * V_2 , const void * V_74 )
{
const unsigned int * V_30 = V_74 ;
F_42 ( V_2 , V_75 , F_43 ( * V_30 / V_76 ) ) ;
return 0 ;
V_68:
return - V_77 ;
}
