static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 , unsigned int V_8 ,
struct V_9 * V_10 )
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
enum V_27 * V_28 ,
unsigned int V_30 )
{
struct V_9 V_40 , V_41 ;
const struct V_42 * V_43 ;
const struct V_44 * V_45 ;
T_2 V_46 = V_39 ? F_15 ( V_39 ) : V_47 ;
F_16 ( V_7 -> V_48 == NULL ) ;
if ( ! F_17 ( V_7 ,
F_18 ( V_7 ) + F_19 ( V_7 )
+ sizeof( struct V_11 ) ,
V_49 , & V_41 ) ) {
F_12 ( L_3 ) ;
return - V_31 ;
}
V_43 = F_20 ( V_49 , V_41 . V_14 . V_50 ) ;
if ( ! F_21 ( & V_40 , & V_41 ,
& V_51 , V_43 ) ) {
F_12 ( L_4 ) ;
return - V_31 ;
}
* V_28 = V_52 ;
V_45 = F_22 ( V_2 , V_46 , & V_40 ) ;
if ( ! V_45 ) {
F_12 ( L_4 ) ;
return - V_31 ;
}
if ( F_23 ( V_45 ) == V_53 )
* V_28 += V_54 ;
V_7 -> V_48 = & F_24 ( V_45 ) -> V_55 ;
V_7 -> V_56 = * V_28 ;
return V_31 ;
}
static int
F_25 ( struct V_2 * V_2 , struct V_26 * V_39 ,
struct V_6 * V_7 , unsigned int V_8 ,
enum V_27 * V_28 , T_1 V_29 , unsigned int V_30 )
{
const struct V_11 * V_57 ;
struct V_11 V_58 ;
V_57 = F_3 ( V_7 , F_19 ( V_7 ) , sizeof( V_58 ) , & V_58 ) ;
if ( V_57 == NULL ) {
if ( F_26 ( V_2 , V_59 ) )
F_27 ( V_2 , V_49 , 0 , V_7 , NULL , NULL ,
NULL , L_5 ) ;
return - V_31 ;
}
if ( V_2 -> V_3 . V_60 && V_30 == V_61 &&
F_28 ( V_7 , V_30 , V_8 , 0 ) ) {
if ( F_26 ( V_2 , V_59 ) )
F_27 ( V_2 , V_49 , 0 , V_7 , NULL , NULL , NULL ,
L_6 ) ;
return - V_31 ;
}
if ( V_57 -> type > V_62 ) {
if ( F_26 ( V_2 , V_59 ) )
F_27 ( V_2 , V_49 , 0 , V_7 , NULL , NULL , NULL ,
L_7 ) ;
return - V_31 ;
}
if ( V_57 -> type != V_63 &&
V_57 -> type != V_64 &&
V_57 -> type != V_65 &&
V_57 -> type != V_66 &&
V_57 -> type != V_67 )
return V_31 ;
return F_14 ( V_2 , V_39 , V_7 , V_28 , V_30 ) ;
}
static int F_29 ( struct V_6 * V_7 ,
const struct V_9 * V_68 )
{
if ( F_30 ( V_7 , V_69 , V_68 -> V_16 . V_15 . V_5 . V_17 ) ||
F_31 ( V_7 , V_70 , V_68 -> V_14 . V_15 . V_5 . type ) ||
F_31 ( V_7 , V_71 , V_68 -> V_14 . V_15 . V_5 . V_20 ) )
goto V_72;
return 0 ;
V_72:
return - 1 ;
}
static int F_32 ( struct V_73 * V_74 [] ,
struct V_9 * V_10 )
{
if ( ! V_74 [ V_70 ] ||
! V_74 [ V_71 ] ||
! V_74 [ V_69 ] )
return - V_75 ;
V_10 -> V_14 . V_15 . V_5 . type = F_33 ( V_74 [ V_70 ] ) ;
V_10 -> V_14 . V_15 . V_5 . V_20 = F_33 ( V_74 [ V_71 ] ) ;
V_10 -> V_16 . V_15 . V_5 . V_17 = F_34 ( V_74 [ V_69 ] ) ;
if ( V_10 -> V_14 . V_15 . V_5 . type >= sizeof( V_22 ) ||
! V_22 [ V_10 -> V_14 . V_15 . V_5 . type ] )
return - V_75 ;
return 0 ;
}
static int F_35 ( void )
{
return F_36 ( V_76 , V_77 + 1 ) ;
}
static int F_37 ( struct V_73 * V_74 [] ,
struct V_2 * V_2 , void * V_78 )
{
unsigned int * V_25 = V_78 ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
if ( V_74 [ V_80 ] ) {
* V_25 =
F_38 ( F_39 ( V_74 [ V_80 ] ) ) * V_81 ;
} else {
* V_25 = V_79 -> V_25 ;
}
return 0 ;
}
static int
F_40 ( struct V_6 * V_7 , const void * V_78 )
{
const unsigned int * V_25 = V_78 ;
if ( F_41 ( V_7 , V_80 , F_42 ( * V_25 / V_81 ) ) )
goto V_72;
return 0 ;
V_72:
return - V_82 ;
}
static int F_43 ( struct V_83 * V_84 ,
struct V_1 * V_79 )
{
#ifdef F_44
V_84 -> V_85 = F_45 ( V_86 ,
sizeof( V_86 ) ,
V_87 ) ;
if ( ! V_84 -> V_85 )
return - V_88 ;
V_84 -> V_85 [ 0 ] . V_78 = & V_79 -> V_25 ;
#endif
return 0 ;
}
static int F_46 ( struct V_83 * V_84 ,
struct V_1 * V_79 )
{
#ifdef F_44
#ifdef F_47
V_84 -> V_89 = F_45 ( V_90 ,
sizeof( V_90 ) ,
V_87 ) ;
if ( ! V_84 -> V_89 )
return - V_88 ;
V_84 -> V_89 [ 0 ] . V_78 = & V_79 -> V_25 ;
#endif
#endif
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , T_3 V_91 )
{
int V_92 ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
struct V_83 * V_84 = & V_79 -> V_84 ;
V_79 -> V_25 = V_93 ;
V_92 = F_46 ( V_84 , V_79 ) ;
if ( V_92 < 0 )
return V_92 ;
V_92 = F_43 ( V_84 , V_79 ) ;
if ( V_92 < 0 )
F_49 ( V_84 ) ;
return V_92 ;
}
static struct V_83 * F_50 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_84 ;
}
