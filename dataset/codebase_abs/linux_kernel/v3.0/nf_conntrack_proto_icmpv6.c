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
static int F_7 ( struct V_22 * V_23 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_24 V_25 ,
T_1 V_26 ,
unsigned int V_27 )
{
F_8 ( V_23 , V_25 , V_2 , V_28 ) ;
return V_29 ;
}
static bool F_9 ( struct V_22 * V_23 , const struct V_1 * V_2 ,
unsigned int V_3 )
{
static const T_1 V_30 [] = {
[ V_31 - 128 ] = 1 ,
[ V_32 - 128 ] = 1
} ;
int type = V_23 -> V_33 [ 0 ] . V_5 . V_9 . V_10 . V_11 . type - 128 ;
if ( type < 0 || type >= sizeof( V_30 ) || ! V_30 [ type ] ) {
F_10 ( L_2 ,
type + 128 ) ;
F_11 ( & V_23 -> V_33 [ 0 ] . V_5 ) ;
if ( F_12 ( F_13 ( V_23 ) , V_34 ) )
F_14 ( V_35 , 0 , V_2 , NULL , NULL , NULL ,
L_3 ,
type + 128 ) ;
return false ;
}
return true ;
}
static int
F_15 ( struct V_36 * V_36 , struct V_22 * V_37 ,
struct V_1 * V_2 ,
unsigned int V_38 ,
enum V_24 * V_25 ,
unsigned int V_27 )
{
struct V_4 V_39 , V_40 ;
const struct V_41 * V_42 ;
const struct V_43 * V_44 ;
T_2 V_45 = V_37 ? F_16 ( V_37 ) : V_46 ;
F_17 ( V_2 -> V_47 == NULL ) ;
if ( ! F_18 ( V_2 ,
F_19 ( V_2 )
+ sizeof( struct V_48 )
+ sizeof( struct V_6 ) ,
V_35 , & V_40 ) ) {
F_10 ( L_4 ) ;
return - V_29 ;
}
V_44 = F_20 ( V_35 , V_40 . V_9 . V_49 ) ;
if ( ! F_21 ( & V_39 , & V_40 ,
& V_50 , V_44 ) ) {
F_10 ( L_5 ) ;
return - V_29 ;
}
* V_25 = V_51 ;
V_42 = F_22 ( V_36 , V_45 , & V_39 ) ;
if ( ! V_42 ) {
F_10 ( L_6 ) ;
return - V_29 ;
} else {
if ( F_23 ( V_42 ) == V_52 )
* V_25 += V_53 ;
}
V_2 -> V_47 = & F_24 ( V_42 ) -> V_54 ;
V_2 -> V_55 = * V_25 ;
return V_29 ;
}
static int
F_25 ( struct V_36 * V_36 , struct V_22 * V_37 ,
struct V_1 * V_2 , unsigned int V_3 ,
enum V_24 * V_25 , T_1 V_26 , unsigned int V_27 )
{
const struct V_6 * V_56 ;
struct V_6 V_57 ;
int type ;
V_56 = F_2 ( V_2 , V_3 , sizeof( V_57 ) , & V_57 ) ;
if ( V_56 == NULL ) {
if ( F_12 ( V_36 , V_34 ) )
F_14 ( V_35 , 0 , V_2 , NULL , NULL , NULL ,
L_7 ) ;
return - V_29 ;
}
if ( V_36 -> V_23 . V_58 && V_27 == V_59 &&
F_26 ( V_2 , V_27 , V_3 , V_34 ) ) {
if ( F_12 ( V_36 , V_34 ) )
F_14 ( V_35 , 0 , V_2 , NULL , NULL , NULL ,
L_8 ) ;
return - V_29 ;
}
type = V_56 -> V_12 - 130 ;
if ( type >= 0 && type < sizeof( V_60 ) &&
V_60 [ type ] ) {
V_2 -> V_47 = & F_27 () -> V_54 ;
V_2 -> V_55 = V_61 ;
F_28 ( V_2 -> V_47 ) ;
return V_29 ;
}
if ( V_56 -> V_12 >= 128 )
return V_29 ;
return F_15 ( V_36 , V_37 , V_2 , V_3 , V_25 , V_27 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_4 * V_62 )
{
F_30 ( V_2 , V_63 , V_62 -> V_13 . V_10 . V_11 . V_14 ) ;
F_31 ( V_2 , V_64 , V_62 -> V_9 . V_10 . V_11 . type ) ;
F_31 ( V_2 , V_65 , V_62 -> V_9 . V_10 . V_11 . V_16 ) ;
return 0 ;
V_66:
return - 1 ;
}
static int F_32 ( struct V_67 * V_68 [] ,
struct V_4 * V_5 )
{
if ( ! V_68 [ V_64 ] ||
! V_68 [ V_65 ] ||
! V_68 [ V_63 ] )
return - V_69 ;
V_5 -> V_9 . V_10 . V_11 . type = F_33 ( V_68 [ V_64 ] ) ;
V_5 -> V_9 . V_10 . V_11 . V_16 = F_33 ( V_68 [ V_65 ] ) ;
V_5 -> V_13 . V_10 . V_11 . V_14 = F_34 ( V_68 [ V_63 ] ) ;
if ( V_5 -> V_9 . V_10 . V_11 . type < 128 ||
V_5 -> V_9 . V_10 . V_11 . type - 128 >= sizeof( V_19 ) ||
! V_19 [ V_5 -> V_9 . V_10 . V_11 . type - 128 ] )
return - V_69 ;
return 0 ;
}
static int F_35 ( void )
{
return F_36 ( V_70 , V_71 + 1 ) ;
}
