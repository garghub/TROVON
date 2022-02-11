static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 , unsigned int V_8 ,
struct V_2 * V_2 , struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_11 V_13 ;
V_12 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
if ( V_12 == NULL )
return false ;
V_10 -> V_14 . V_15 . V_5 . type = V_12 -> type ;
V_10 -> V_16 . V_15 . V_5 . V_17 = V_12 -> V_18 . V_19 . V_17 ;
V_10 -> V_14 . V_15 . V_5 . V_20 = V_12 -> V_20 ;
return true ;
}
static bool F_4 ( struct V_9 * V_10 ,
const struct V_9 * V_21 )
{
if ( V_21 -> V_14 . V_15 . V_5 . type >= sizeof( V_22 ) ||
! V_22 [ V_21 -> V_14 . V_15 . V_5 . type ] )
return false ;
V_10 -> V_16 . V_15 . V_5 . V_17 = V_21 -> V_16 . V_15 . V_5 . V_17 ;
V_10 -> V_14 . V_15 . V_5 . type = V_22 [ V_21 -> V_14 . V_15 . V_5 . type ] - 1 ;
V_10 -> V_14 . V_15 . V_5 . V_20 = V_21 -> V_14 . V_15 . V_5 . V_20 ;
return true ;
}
static unsigned int * F_5 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_23 ;
}
static int F_6 ( struct V_24 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_25 V_26 ,
T_1 V_27 ,
unsigned int * V_23 )
{
F_7 ( V_3 , V_26 , V_7 , * V_23 ) ;
return V_28 ;
}
static bool F_8 ( struct V_24 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_29 )
{
static const T_1 V_30 [] = {
[ V_31 ] = 1 ,
[ V_32 ] = 1 ,
[ V_33 ] = 1 ,
[ V_34 ] = 1
} ;
if ( V_3 -> V_35 [ 0 ] . V_10 . V_14 . V_15 . V_5 . type >= sizeof( V_30 ) ||
! V_30 [ V_3 -> V_35 [ 0 ] . V_10 . V_14 . V_15 . V_5 . type ] ) {
F_9 ( L_1 ,
V_3 -> V_35 [ 0 ] . V_10 . V_14 . V_15 . V_5 . type ) ;
F_10 ( & V_3 -> V_35 [ 0 ] . V_10 ) ;
return false ;
}
return true ;
}
static int
F_11 ( struct V_2 * V_2 , struct V_24 * V_36 , struct V_6 * V_7 ,
unsigned int V_37 )
{
struct V_9 V_38 , V_39 ;
const struct V_40 * V_41 ;
const struct V_42 * V_43 ;
const struct V_44 * V_45 ;
enum V_25 V_26 ;
struct V_44 V_46 ;
F_12 ( F_13 ( V_7 ) ) ;
V_45 = F_14 ( V_36 , V_7 , & V_46 ) ;
if ( ! F_15 ( V_7 ,
F_16 ( V_7 ) + F_17 ( V_7 )
+ sizeof( struct V_11 ) ,
V_47 , V_2 , & V_39 ) ) {
F_9 ( L_2 ) ;
return - V_28 ;
}
V_41 = F_18 ( V_47 , V_39 . V_14 . V_48 ) ;
if ( ! F_19 ( & V_38 , & V_39 ,
& V_49 , V_41 ) ) {
F_9 ( L_3 ) ;
return - V_28 ;
}
V_26 = V_50 ;
V_43 = F_20 ( V_2 , V_45 , & V_38 ) ;
if ( ! V_43 ) {
F_9 ( L_3 ) ;
return - V_28 ;
}
if ( F_21 ( V_43 ) == V_51 )
V_26 += V_52 ;
F_22 ( V_7 , F_23 ( V_43 ) , V_26 ) ;
return V_28 ;
}
static int
F_24 ( struct V_2 * V_2 , struct V_24 * V_36 ,
struct V_6 * V_7 , unsigned int V_8 ,
T_2 V_27 , unsigned int V_37 )
{
const struct V_11 * V_53 ;
struct V_11 V_54 ;
V_53 = F_3 ( V_7 , F_17 ( V_7 ) , sizeof( V_54 ) , & V_54 ) ;
if ( V_53 == NULL ) {
if ( F_25 ( V_2 , V_55 ) )
F_26 ( V_2 , V_47 , 0 , V_7 , NULL , NULL ,
NULL , L_4 ) ;
return - V_28 ;
}
if ( V_2 -> V_3 . V_56 && V_37 == V_57 &&
F_27 ( V_7 , V_37 , V_8 , 0 ) ) {
if ( F_25 ( V_2 , V_55 ) )
F_26 ( V_2 , V_47 , 0 , V_7 , NULL , NULL , NULL ,
L_5 ) ;
return - V_28 ;
}
if ( V_53 -> type > V_58 ) {
if ( F_25 ( V_2 , V_55 ) )
F_26 ( V_2 , V_47 , 0 , V_7 , NULL , NULL , NULL ,
L_6 ) ;
return - V_28 ;
}
if ( V_53 -> type != V_59 &&
V_53 -> type != V_60 &&
V_53 -> type != V_61 &&
V_53 -> type != V_62 &&
V_53 -> type != V_63 )
return V_28 ;
return F_11 ( V_2 , V_36 , V_7 , V_37 ) ;
}
static int F_28 ( struct V_6 * V_7 ,
const struct V_9 * V_64 )
{
if ( F_29 ( V_7 , V_65 , V_64 -> V_16 . V_15 . V_5 . V_17 ) ||
F_30 ( V_7 , V_66 , V_64 -> V_14 . V_15 . V_5 . type ) ||
F_30 ( V_7 , V_67 , V_64 -> V_14 . V_15 . V_5 . V_20 ) )
goto V_68;
return 0 ;
V_68:
return - 1 ;
}
static int F_31 ( struct V_69 * V_70 [] ,
struct V_9 * V_10 )
{
if ( ! V_70 [ V_66 ] ||
! V_70 [ V_67 ] ||
! V_70 [ V_65 ] )
return - V_71 ;
V_10 -> V_14 . V_15 . V_5 . type = F_32 ( V_70 [ V_66 ] ) ;
V_10 -> V_14 . V_15 . V_5 . V_20 = F_32 ( V_70 [ V_67 ] ) ;
V_10 -> V_16 . V_15 . V_5 . V_17 = F_33 ( V_70 [ V_65 ] ) ;
if ( V_10 -> V_14 . V_15 . V_5 . type >= sizeof( V_22 ) ||
! V_22 [ V_10 -> V_14 . V_15 . V_5 . type ] )
return - V_71 ;
return 0 ;
}
static int F_34 ( void )
{
return F_35 ( V_72 , V_73 + 1 ) ;
}
static int F_36 ( struct V_69 * V_70 [] ,
struct V_2 * V_2 , void * V_74 )
{
unsigned int * V_23 = V_74 ;
struct V_1 * V_75 = F_1 ( V_2 ) ;
if ( V_70 [ V_76 ] ) {
* V_23 =
F_37 ( F_38 ( V_70 [ V_76 ] ) ) * V_77 ;
} else {
* V_23 = V_75 -> V_23 ;
}
return 0 ;
}
static int
F_39 ( struct V_6 * V_7 , const void * V_74 )
{
const unsigned int * V_23 = V_74 ;
if ( F_40 ( V_7 , V_76 , F_41 ( * V_23 / V_77 ) ) )
goto V_68;
return 0 ;
V_68:
return - V_78 ;
}
static int F_42 ( struct V_79 * V_80 ,
struct V_1 * V_75 )
{
#ifdef F_43
V_80 -> V_81 = F_44 ( V_82 ,
sizeof( V_82 ) ,
V_83 ) ;
if ( ! V_80 -> V_81 )
return - V_84 ;
V_80 -> V_81 [ 0 ] . V_74 = & V_75 -> V_23 ;
#endif
return 0 ;
}
static int F_45 ( struct V_2 * V_2 , T_3 V_85 )
{
struct V_1 * V_75 = F_1 ( V_2 ) ;
struct V_79 * V_80 = & V_75 -> V_80 ;
V_75 -> V_23 = V_86 ;
return F_42 ( V_80 , V_75 ) ;
}
static struct V_79 * F_46 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_80 ;
}
