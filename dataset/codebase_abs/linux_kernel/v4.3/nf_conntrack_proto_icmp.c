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
const struct V_46 * V_47 ;
struct V_46 V_48 ;
F_15 ( V_7 -> V_49 == NULL ) ;
V_47 = F_16 ( V_39 , V_7 , & V_48 ) ;
if ( ! F_17 ( V_7 ,
F_18 ( V_7 ) + F_19 ( V_7 )
+ sizeof( struct V_11 ) ,
V_50 , & V_41 ) ) {
F_12 ( L_3 ) ;
return - V_31 ;
}
V_43 = F_20 ( V_50 , V_41 . V_14 . V_51 ) ;
if ( ! F_21 ( & V_40 , & V_41 ,
& V_52 , V_43 ) ) {
F_12 ( L_4 ) ;
return - V_31 ;
}
* V_28 = V_53 ;
V_45 = F_22 ( V_2 , V_47 , & V_40 ) ;
if ( ! V_45 ) {
F_12 ( L_4 ) ;
return - V_31 ;
}
if ( F_23 ( V_45 ) == V_54 )
* V_28 += V_55 ;
V_7 -> V_49 = & F_24 ( V_45 ) -> V_56 ;
V_7 -> V_57 = * V_28 ;
return V_31 ;
}
static int
F_25 ( struct V_2 * V_2 , struct V_26 * V_39 ,
struct V_6 * V_7 , unsigned int V_8 ,
enum V_27 * V_28 , T_1 V_29 , unsigned int V_30 )
{
const struct V_11 * V_58 ;
struct V_11 V_59 ;
V_58 = F_3 ( V_7 , F_19 ( V_7 ) , sizeof( V_59 ) , & V_59 ) ;
if ( V_58 == NULL ) {
if ( F_26 ( V_2 , V_60 ) )
F_27 ( V_2 , V_50 , 0 , V_7 , NULL , NULL ,
NULL , L_5 ) ;
return - V_31 ;
}
if ( V_2 -> V_3 . V_61 && V_30 == V_62 &&
F_28 ( V_7 , V_30 , V_8 , 0 ) ) {
if ( F_26 ( V_2 , V_60 ) )
F_27 ( V_2 , V_50 , 0 , V_7 , NULL , NULL , NULL ,
L_6 ) ;
return - V_31 ;
}
if ( V_58 -> type > V_63 ) {
if ( F_26 ( V_2 , V_60 ) )
F_27 ( V_2 , V_50 , 0 , V_7 , NULL , NULL , NULL ,
L_7 ) ;
return - V_31 ;
}
if ( V_58 -> type != V_64 &&
V_58 -> type != V_65 &&
V_58 -> type != V_66 &&
V_58 -> type != V_67 &&
V_58 -> type != V_68 )
return V_31 ;
return F_14 ( V_2 , V_39 , V_7 , V_28 , V_30 ) ;
}
static int F_29 ( struct V_6 * V_7 ,
const struct V_9 * V_69 )
{
if ( F_30 ( V_7 , V_70 , V_69 -> V_16 . V_15 . V_5 . V_17 ) ||
F_31 ( V_7 , V_71 , V_69 -> V_14 . V_15 . V_5 . type ) ||
F_31 ( V_7 , V_72 , V_69 -> V_14 . V_15 . V_5 . V_20 ) )
goto V_73;
return 0 ;
V_73:
return - 1 ;
}
static int F_32 ( struct V_74 * V_75 [] ,
struct V_9 * V_10 )
{
if ( ! V_75 [ V_71 ] ||
! V_75 [ V_72 ] ||
! V_75 [ V_70 ] )
return - V_76 ;
V_10 -> V_14 . V_15 . V_5 . type = F_33 ( V_75 [ V_71 ] ) ;
V_10 -> V_14 . V_15 . V_5 . V_20 = F_33 ( V_75 [ V_72 ] ) ;
V_10 -> V_16 . V_15 . V_5 . V_17 = F_34 ( V_75 [ V_70 ] ) ;
if ( V_10 -> V_14 . V_15 . V_5 . type >= sizeof( V_22 ) ||
! V_22 [ V_10 -> V_14 . V_15 . V_5 . type ] )
return - V_76 ;
return 0 ;
}
static int F_35 ( void )
{
return F_36 ( V_77 , V_78 + 1 ) ;
}
static int F_37 ( struct V_74 * V_75 [] ,
struct V_2 * V_2 , void * V_79 )
{
unsigned int * V_25 = V_79 ;
struct V_1 * V_80 = F_1 ( V_2 ) ;
if ( V_75 [ V_81 ] ) {
* V_25 =
F_38 ( F_39 ( V_75 [ V_81 ] ) ) * V_82 ;
} else {
* V_25 = V_80 -> V_25 ;
}
return 0 ;
}
static int
F_40 ( struct V_6 * V_7 , const void * V_79 )
{
const unsigned int * V_25 = V_79 ;
if ( F_41 ( V_7 , V_81 , F_42 ( * V_25 / V_82 ) ) )
goto V_73;
return 0 ;
V_73:
return - V_83 ;
}
static int F_43 ( struct V_84 * V_85 ,
struct V_1 * V_80 )
{
#ifdef F_44
V_85 -> V_86 = F_45 ( V_87 ,
sizeof( V_87 ) ,
V_88 ) ;
if ( ! V_85 -> V_86 )
return - V_89 ;
V_85 -> V_86 [ 0 ] . V_79 = & V_80 -> V_25 ;
#endif
return 0 ;
}
static int F_46 ( struct V_84 * V_85 ,
struct V_1 * V_80 )
{
#ifdef F_44
#ifdef F_47
V_85 -> V_90 = F_45 ( V_91 ,
sizeof( V_91 ) ,
V_88 ) ;
if ( ! V_85 -> V_90 )
return - V_89 ;
V_85 -> V_90 [ 0 ] . V_79 = & V_80 -> V_25 ;
#endif
#endif
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , T_2 V_92 )
{
int V_93 ;
struct V_1 * V_80 = F_1 ( V_2 ) ;
struct V_84 * V_85 = & V_80 -> V_85 ;
V_80 -> V_25 = V_94 ;
V_93 = F_46 ( V_85 , V_80 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_43 ( V_85 , V_80 ) ;
if ( V_93 < 0 )
F_49 ( V_85 ) ;
return V_93 ;
}
static struct V_84 * F_50 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_85 ;
}
