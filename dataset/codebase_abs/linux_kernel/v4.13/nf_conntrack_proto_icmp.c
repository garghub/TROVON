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
static void F_5 ( struct V_23 * V_24 ,
const struct V_9 * V_10 )
{
F_6 ( V_24 , L_1 ,
V_10 -> V_14 . V_15 . V_5 . type ,
V_10 -> V_14 . V_15 . V_5 . V_20 ,
F_7 ( V_10 -> V_16 . V_15 . V_5 . V_17 ) ) ;
}
static unsigned int * F_8 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_25 ;
}
static int F_9 ( struct V_26 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_27 V_28 ,
T_1 V_29 ,
unsigned int V_30 ,
unsigned int * V_25 )
{
F_10 ( V_3 , V_28 , V_7 , * V_25 ) ;
return V_31 ;
}
static bool F_11 ( struct V_26 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_32 )
{
static const T_1 V_33 [] = {
[ V_34 ] = 1 ,
[ V_35 ] = 1 ,
[ V_36 ] = 1 ,
[ V_37 ] = 1
} ;
if ( V_3 -> V_38 [ 0 ] . V_10 . V_14 . V_15 . V_5 . type >= sizeof( V_33 ) ||
! V_33 [ V_3 -> V_38 [ 0 ] . V_10 . V_14 . V_15 . V_5 . type ] ) {
F_12 ( L_2 ,
V_3 -> V_38 [ 0 ] . V_10 . V_14 . V_15 . V_5 . type ) ;
F_13 ( & V_3 -> V_38 [ 0 ] . V_10 ) ;
return false ;
}
return true ;
}
static int
F_14 ( struct V_2 * V_2 , struct V_26 * V_39 , struct V_6 * V_7 ,
unsigned int V_30 )
{
struct V_9 V_40 , V_41 ;
const struct V_42 * V_43 ;
const struct V_44 * V_45 ;
const struct V_46 * V_47 ;
enum V_27 V_28 ;
struct V_46 V_48 ;
F_15 ( ! F_16 ( V_7 ) ) ;
V_47 = F_17 ( V_39 , V_7 , & V_48 ) ;
if ( ! F_18 ( V_7 ,
F_19 ( V_7 ) + F_20 ( V_7 )
+ sizeof( struct V_11 ) ,
V_49 , V_2 , & V_41 ) ) {
F_12 ( L_3 ) ;
return - V_31 ;
}
V_43 = F_21 ( V_49 , V_41 . V_14 . V_50 ) ;
if ( ! F_22 ( & V_40 , & V_41 ,
& V_51 , V_43 ) ) {
F_12 ( L_4 ) ;
return - V_31 ;
}
V_28 = V_52 ;
V_45 = F_23 ( V_2 , V_47 , & V_40 ) ;
if ( ! V_45 ) {
F_12 ( L_4 ) ;
return - V_31 ;
}
if ( F_24 ( V_45 ) == V_53 )
V_28 += V_54 ;
F_25 ( V_7 , F_26 ( V_45 ) , V_28 ) ;
return V_31 ;
}
static int
F_27 ( struct V_2 * V_2 , struct V_26 * V_39 ,
struct V_6 * V_7 , unsigned int V_8 ,
T_2 V_29 , unsigned int V_30 )
{
const struct V_11 * V_55 ;
struct V_11 V_56 ;
V_55 = F_3 ( V_7 , F_20 ( V_7 ) , sizeof( V_56 ) , & V_56 ) ;
if ( V_55 == NULL ) {
if ( F_28 ( V_2 , V_57 ) )
F_29 ( V_2 , V_49 , 0 , V_7 , NULL , NULL ,
NULL , L_5 ) ;
return - V_31 ;
}
if ( V_2 -> V_3 . V_58 && V_30 == V_59 &&
F_30 ( V_7 , V_30 , V_8 , 0 ) ) {
if ( F_28 ( V_2 , V_57 ) )
F_29 ( V_2 , V_49 , 0 , V_7 , NULL , NULL , NULL ,
L_6 ) ;
return - V_31 ;
}
if ( V_55 -> type > V_60 ) {
if ( F_28 ( V_2 , V_57 ) )
F_29 ( V_2 , V_49 , 0 , V_7 , NULL , NULL , NULL ,
L_7 ) ;
return - V_31 ;
}
if ( V_55 -> type != V_61 &&
V_55 -> type != V_62 &&
V_55 -> type != V_63 &&
V_55 -> type != V_64 &&
V_55 -> type != V_65 )
return V_31 ;
return F_14 ( V_2 , V_39 , V_7 , V_30 ) ;
}
static int F_31 ( struct V_6 * V_7 ,
const struct V_9 * V_66 )
{
if ( F_32 ( V_7 , V_67 , V_66 -> V_16 . V_15 . V_5 . V_17 ) ||
F_33 ( V_7 , V_68 , V_66 -> V_14 . V_15 . V_5 . type ) ||
F_33 ( V_7 , V_69 , V_66 -> V_14 . V_15 . V_5 . V_20 ) )
goto V_70;
return 0 ;
V_70:
return - 1 ;
}
static int F_34 ( struct V_71 * V_72 [] ,
struct V_9 * V_10 )
{
if ( ! V_72 [ V_68 ] ||
! V_72 [ V_69 ] ||
! V_72 [ V_67 ] )
return - V_73 ;
V_10 -> V_14 . V_15 . V_5 . type = F_35 ( V_72 [ V_68 ] ) ;
V_10 -> V_14 . V_15 . V_5 . V_20 = F_35 ( V_72 [ V_69 ] ) ;
V_10 -> V_16 . V_15 . V_5 . V_17 = F_36 ( V_72 [ V_67 ] ) ;
if ( V_10 -> V_14 . V_15 . V_5 . type >= sizeof( V_22 ) ||
! V_22 [ V_10 -> V_14 . V_15 . V_5 . type ] )
return - V_73 ;
return 0 ;
}
static int F_37 ( void )
{
return F_38 ( V_74 , V_75 + 1 ) ;
}
static int F_39 ( struct V_71 * V_72 [] ,
struct V_2 * V_2 , void * V_76 )
{
unsigned int * V_25 = V_76 ;
struct V_1 * V_77 = F_1 ( V_2 ) ;
if ( V_72 [ V_78 ] ) {
* V_25 =
F_40 ( F_41 ( V_72 [ V_78 ] ) ) * V_79 ;
} else {
* V_25 = V_77 -> V_25 ;
}
return 0 ;
}
static int
F_42 ( struct V_6 * V_7 , const void * V_76 )
{
const unsigned int * V_25 = V_76 ;
if ( F_43 ( V_7 , V_78 , F_44 ( * V_25 / V_79 ) ) )
goto V_70;
return 0 ;
V_70:
return - V_80 ;
}
static int F_45 ( struct V_81 * V_82 ,
struct V_1 * V_77 )
{
#ifdef F_46
V_82 -> V_83 = F_47 ( V_84 ,
sizeof( V_84 ) ,
V_85 ) ;
if ( ! V_82 -> V_83 )
return - V_86 ;
V_82 -> V_83 [ 0 ] . V_76 = & V_77 -> V_25 ;
#endif
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , T_3 V_87 )
{
struct V_1 * V_77 = F_1 ( V_2 ) ;
struct V_81 * V_82 = & V_77 -> V_82 ;
V_77 -> V_25 = V_88 ;
return F_45 ( V_82 , V_77 ) ;
}
static struct V_81 * F_49 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_82 ;
}
