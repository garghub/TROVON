static bool F_1 ( const struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
const struct V_6 * V_7 ;
struct V_6 V_8 ;
V_7 = F_2 ( V_2 , V_3 , sizeof( V_8 ) , & V_8 ) ;
if ( V_7 == NULL )
return false ;
V_5 -> V_9 . V_10 . V_11 . type = V_7 -> type ;
V_5 -> V_12 . V_10 . V_11 . V_13 = V_7 -> V_14 . V_15 . V_13 ;
V_5 -> V_9 . V_10 . V_11 . V_16 = V_7 -> V_16 ;
return true ;
}
static bool F_3 ( struct V_4 * V_5 ,
const struct V_4 * V_17 )
{
if ( V_17 -> V_9 . V_10 . V_11 . type >= sizeof( V_18 ) ||
! V_18 [ V_17 -> V_9 . V_10 . V_11 . type ] )
return false ;
V_5 -> V_12 . V_10 . V_11 . V_13 = V_17 -> V_12 . V_10 . V_11 . V_13 ;
V_5 -> V_9 . V_10 . V_11 . type = V_18 [ V_17 -> V_9 . V_10 . V_11 . type ] - 1 ;
V_5 -> V_9 . V_10 . V_11 . V_16 = V_17 -> V_9 . V_10 . V_11 . V_16 ;
return true ;
}
static int F_4 ( struct V_19 * V_20 ,
const struct V_4 * V_5 )
{
return F_5 ( V_20 , L_1 ,
V_5 -> V_9 . V_10 . V_11 . type ,
V_5 -> V_9 . V_10 . V_11 . V_16 ,
F_6 ( V_5 -> V_12 . V_10 . V_11 . V_13 ) ) ;
}
static int F_7 ( struct V_21 * V_22 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_23 V_24 ,
T_1 V_25 ,
unsigned int V_26 )
{
F_8 ( V_22 , V_24 , V_2 , V_27 ) ;
return V_28 ;
}
static bool F_9 ( struct V_21 * V_22 , const struct V_1 * V_2 ,
unsigned int V_3 )
{
static const T_1 V_29 [] = {
[ V_30 ] = 1 ,
[ V_31 ] = 1 ,
[ V_32 ] = 1 ,
[ V_33 ] = 1
} ;
if ( V_22 -> V_34 [ 0 ] . V_5 . V_9 . V_10 . V_11 . type >= sizeof( V_29 ) ||
! V_29 [ V_22 -> V_34 [ 0 ] . V_5 . V_9 . V_10 . V_11 . type ] ) {
F_10 ( L_2 ,
V_22 -> V_34 [ 0 ] . V_5 . V_9 . V_10 . V_11 . type ) ;
F_11 ( & V_22 -> V_34 [ 0 ] . V_5 ) ;
return false ;
}
return true ;
}
static int
F_12 ( struct V_35 * V_35 , struct V_21 * V_36 , struct V_1 * V_2 ,
enum V_23 * V_24 ,
unsigned int V_26 )
{
struct V_4 V_37 , V_38 ;
const struct V_39 * V_40 ;
const struct V_41 * V_42 ;
T_2 V_43 = V_36 ? F_13 ( V_36 ) : V_44 ;
F_14 ( V_2 -> V_45 == NULL ) ;
if ( ! F_15 ( V_2 ,
F_16 ( V_2 ) + F_17 ( V_2 )
+ sizeof( struct V_6 ) ,
V_46 , & V_38 ) ) {
F_10 ( L_3 ) ;
return - V_28 ;
}
V_40 = F_18 ( V_46 , V_38 . V_9 . V_47 ) ;
if ( ! F_19 ( & V_37 , & V_38 ,
& V_48 , V_40 ) ) {
F_10 ( L_4 ) ;
return - V_28 ;
}
* V_24 = V_49 ;
V_42 = F_20 ( V_35 , V_43 , & V_37 ) ;
if ( ! V_42 ) {
F_10 ( L_4 ) ;
return - V_28 ;
}
if ( F_21 ( V_42 ) == V_50 )
* V_24 += V_51 ;
V_2 -> V_45 = & F_22 ( V_42 ) -> V_52 ;
V_2 -> V_53 = * V_24 ;
return V_28 ;
}
static int
F_23 ( struct V_35 * V_35 , struct V_21 * V_36 ,
struct V_1 * V_2 , unsigned int V_3 ,
enum V_23 * V_24 , T_1 V_25 , unsigned int V_26 )
{
const struct V_6 * V_54 ;
struct V_6 V_55 ;
V_54 = F_2 ( V_2 , F_17 ( V_2 ) , sizeof( V_55 ) , & V_55 ) ;
if ( V_54 == NULL ) {
if ( F_24 ( V_35 , V_56 ) )
F_25 ( V_46 , 0 , V_2 , NULL , NULL , NULL ,
L_5 ) ;
return - V_28 ;
}
if ( V_35 -> V_22 . V_57 && V_26 == V_58 &&
F_26 ( V_2 , V_26 , V_3 , 0 ) ) {
if ( F_24 ( V_35 , V_56 ) )
F_25 ( V_46 , 0 , V_2 , NULL , NULL , NULL ,
L_6 ) ;
return - V_28 ;
}
if ( V_54 -> type > V_59 ) {
if ( F_24 ( V_35 , V_56 ) )
F_25 ( V_46 , 0 , V_2 , NULL , NULL , NULL ,
L_7 ) ;
return - V_28 ;
}
if ( V_54 -> type != V_60 &&
V_54 -> type != V_61 &&
V_54 -> type != V_62 &&
V_54 -> type != V_63 &&
V_54 -> type != V_64 )
return V_28 ;
return F_12 ( V_35 , V_36 , V_2 , V_24 , V_26 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_4 * V_65 )
{
F_28 ( V_2 , V_66 , V_65 -> V_12 . V_10 . V_11 . V_13 ) ;
F_29 ( V_2 , V_67 , V_65 -> V_9 . V_10 . V_11 . type ) ;
F_29 ( V_2 , V_68 , V_65 -> V_9 . V_10 . V_11 . V_16 ) ;
return 0 ;
V_69:
return - 1 ;
}
static int F_30 ( struct V_70 * V_71 [] ,
struct V_4 * V_5 )
{
if ( ! V_71 [ V_67 ] ||
! V_71 [ V_68 ] ||
! V_71 [ V_66 ] )
return - V_72 ;
V_5 -> V_9 . V_10 . V_11 . type = F_31 ( V_71 [ V_67 ] ) ;
V_5 -> V_9 . V_10 . V_11 . V_16 = F_31 ( V_71 [ V_68 ] ) ;
V_5 -> V_12 . V_10 . V_11 . V_13 = F_32 ( V_71 [ V_66 ] ) ;
if ( V_5 -> V_9 . V_10 . V_11 . type >= sizeof( V_18 ) ||
! V_18 [ V_5 -> V_9 . V_10 . V_11 . type ] )
return - V_72 ;
return 0 ;
}
static int F_33 ( void )
{
return F_34 ( V_73 , V_74 + 1 ) ;
}
