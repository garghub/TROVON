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
static unsigned int * F_7 ( struct V_21 * V_21 )
{
return & V_22 ;
}
static int F_8 ( struct V_23 * V_24 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_25 V_26 ,
T_1 V_27 ,
unsigned int V_28 ,
unsigned int * V_29 )
{
F_9 ( V_24 , V_26 , V_2 , * V_29 ) ;
return V_30 ;
}
static bool F_10 ( struct V_23 * V_24 , const struct V_1 * V_2 ,
unsigned int V_3 , unsigned int * V_31 )
{
static const T_1 V_32 [] = {
[ V_33 ] = 1 ,
[ V_34 ] = 1 ,
[ V_35 ] = 1 ,
[ V_36 ] = 1
} ;
if ( V_24 -> V_37 [ 0 ] . V_5 . V_9 . V_10 . V_11 . type >= sizeof( V_32 ) ||
! V_32 [ V_24 -> V_37 [ 0 ] . V_5 . V_9 . V_10 . V_11 . type ] ) {
F_11 ( L_2 ,
V_24 -> V_37 [ 0 ] . V_5 . V_9 . V_10 . V_11 . type ) ;
F_12 ( & V_24 -> V_37 [ 0 ] . V_5 ) ;
return false ;
}
return true ;
}
static int
F_13 ( struct V_21 * V_21 , struct V_23 * V_38 , struct V_1 * V_2 ,
enum V_25 * V_26 ,
unsigned int V_28 )
{
struct V_4 V_39 , V_40 ;
const struct V_41 * V_42 ;
const struct V_43 * V_44 ;
T_2 V_45 = V_38 ? F_14 ( V_38 ) : V_46 ;
F_15 ( V_2 -> V_47 == NULL ) ;
if ( ! F_16 ( V_2 ,
F_17 ( V_2 ) + F_18 ( V_2 )
+ sizeof( struct V_6 ) ,
V_48 , & V_40 ) ) {
F_11 ( L_3 ) ;
return - V_30 ;
}
V_42 = F_19 ( V_48 , V_40 . V_9 . V_49 ) ;
if ( ! F_20 ( & V_39 , & V_40 ,
& V_50 , V_42 ) ) {
F_11 ( L_4 ) ;
return - V_30 ;
}
* V_26 = V_51 ;
V_44 = F_21 ( V_21 , V_45 , & V_39 ) ;
if ( ! V_44 ) {
F_11 ( L_4 ) ;
return - V_30 ;
}
if ( F_22 ( V_44 ) == V_52 )
* V_26 += V_53 ;
V_2 -> V_47 = & F_23 ( V_44 ) -> V_54 ;
V_2 -> V_55 = * V_26 ;
return V_30 ;
}
static int
F_24 ( struct V_21 * V_21 , struct V_23 * V_38 ,
struct V_1 * V_2 , unsigned int V_3 ,
enum V_25 * V_26 , T_1 V_27 , unsigned int V_28 )
{
const struct V_6 * V_56 ;
struct V_6 V_57 ;
V_56 = F_2 ( V_2 , F_18 ( V_2 ) , sizeof( V_57 ) , & V_57 ) ;
if ( V_56 == NULL ) {
if ( F_25 ( V_21 , V_58 ) )
F_26 ( V_48 , 0 , V_2 , NULL , NULL , NULL ,
L_5 ) ;
return - V_30 ;
}
if ( V_21 -> V_24 . V_59 && V_28 == V_60 &&
F_27 ( V_2 , V_28 , V_3 , 0 ) ) {
if ( F_25 ( V_21 , V_58 ) )
F_26 ( V_48 , 0 , V_2 , NULL , NULL , NULL ,
L_6 ) ;
return - V_30 ;
}
if ( V_56 -> type > V_61 ) {
if ( F_25 ( V_21 , V_58 ) )
F_26 ( V_48 , 0 , V_2 , NULL , NULL , NULL ,
L_7 ) ;
return - V_30 ;
}
if ( V_56 -> type != V_62 &&
V_56 -> type != V_63 &&
V_56 -> type != V_64 &&
V_56 -> type != V_65 &&
V_56 -> type != V_66 )
return V_30 ;
return F_13 ( V_21 , V_38 , V_2 , V_26 , V_28 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_4 * V_67 )
{
if ( F_29 ( V_2 , V_68 , V_67 -> V_12 . V_10 . V_11 . V_13 ) ||
F_30 ( V_2 , V_69 , V_67 -> V_9 . V_10 . V_11 . type ) ||
F_30 ( V_2 , V_70 , V_67 -> V_9 . V_10 . V_11 . V_16 ) )
goto V_71;
return 0 ;
V_71:
return - 1 ;
}
static int F_31 ( struct V_72 * V_73 [] ,
struct V_4 * V_5 )
{
if ( ! V_73 [ V_69 ] ||
! V_73 [ V_70 ] ||
! V_73 [ V_68 ] )
return - V_74 ;
V_5 -> V_9 . V_10 . V_11 . type = F_32 ( V_73 [ V_69 ] ) ;
V_5 -> V_9 . V_10 . V_11 . V_16 = F_32 ( V_73 [ V_70 ] ) ;
V_5 -> V_12 . V_10 . V_11 . V_13 = F_33 ( V_73 [ V_68 ] ) ;
if ( V_5 -> V_9 . V_10 . V_11 . type >= sizeof( V_18 ) ||
! V_18 [ V_5 -> V_9 . V_10 . V_11 . type ] )
return - V_74 ;
return 0 ;
}
static int F_34 ( void )
{
return F_35 ( V_75 , V_76 + 1 ) ;
}
static int F_36 ( struct V_72 * V_73 [] , void * V_77 )
{
unsigned int * V_29 = V_77 ;
if ( V_73 [ V_78 ] ) {
* V_29 =
F_37 ( F_38 ( V_73 [ V_78 ] ) ) * V_79 ;
} else {
* V_29 = V_22 ;
}
return 0 ;
}
static int
F_39 ( struct V_1 * V_2 , const void * V_77 )
{
const unsigned int * V_29 = V_77 ;
if ( F_40 ( V_2 , V_78 , F_41 ( * V_29 / V_79 ) ) )
goto V_71;
return 0 ;
V_71:
return - V_80 ;
}
