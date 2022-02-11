static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 ,
unsigned int V_8 ,
struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_11 V_13 ;
V_12 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
if ( V_12 == NULL )
return false ;
V_10 -> V_14 . V_15 . V_16 . type = V_12 -> V_17 ;
V_10 -> V_18 . V_15 . V_16 . V_19 = V_12 -> V_20 ;
V_10 -> V_14 . V_15 . V_16 . V_21 = V_12 -> V_22 ;
return true ;
}
static bool F_4 ( struct V_9 * V_10 ,
const struct V_9 * V_23 )
{
int type = V_23 -> V_14 . V_15 . V_16 . type - 128 ;
if ( type < 0 || type >= sizeof( V_24 ) || ! V_24 [ type ] )
return false ;
V_10 -> V_18 . V_15 . V_16 . V_19 = V_23 -> V_18 . V_15 . V_16 . V_19 ;
V_10 -> V_14 . V_15 . V_16 . type = V_24 [ type ] - 1 ;
V_10 -> V_14 . V_15 . V_16 . V_21 = V_23 -> V_14 . V_15 . V_16 . V_21 ;
return true ;
}
static void F_5 ( struct V_25 * V_26 ,
const struct V_9 * V_10 )
{
F_6 ( V_26 , L_1 ,
V_10 -> V_14 . V_15 . V_16 . type ,
V_10 -> V_14 . V_15 . V_16 . V_21 ,
F_7 ( V_10 -> V_18 . V_15 . V_16 . V_19 ) ) ;
}
static unsigned int * F_8 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_27 ;
}
static int F_9 ( struct V_28 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_29 V_30 ,
T_1 V_31 ,
unsigned int V_32 ,
unsigned int * V_27 )
{
F_10 ( V_3 , V_30 , V_7 , * V_27 ) ;
return V_33 ;
}
static bool F_11 ( struct V_28 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_34 )
{
static const T_1 V_35 [] = {
[ V_36 - 128 ] = 1 ,
[ V_37 - 128 ] = 1
} ;
int type = V_3 -> V_38 [ 0 ] . V_10 . V_14 . V_15 . V_16 . type - 128 ;
if ( type < 0 || type >= sizeof( V_35 ) || ! V_35 [ type ] ) {
F_12 ( L_2 ,
type + 128 ) ;
F_13 ( & V_3 -> V_38 [ 0 ] . V_10 ) ;
if ( F_14 ( F_15 ( V_3 ) , V_39 ) )
F_16 ( F_15 ( V_3 ) , V_40 , 0 , V_7 , NULL ,
NULL , NULL ,
L_3 ,
type + 128 ) ;
return false ;
}
return true ;
}
static int
F_17 ( struct V_2 * V_2 , struct V_28 * V_41 ,
struct V_6 * V_7 ,
unsigned int V_42 ,
enum V_29 * V_30 ,
unsigned int V_32 )
{
struct V_9 V_43 , V_44 ;
const struct V_45 * V_46 ;
const struct V_47 * V_48 ;
struct V_49 V_50 ;
F_18 ( V_7 -> V_51 == NULL ) ;
if ( ! F_19 ( V_7 ,
F_20 ( V_7 )
+ sizeof( struct V_52 )
+ sizeof( struct V_11 ) ,
V_40 , & V_44 ) ) {
F_12 ( L_4 ) ;
return - V_33 ;
}
V_48 = F_21 ( V_40 , V_44 . V_14 . V_53 ) ;
if ( ! F_22 ( & V_43 , & V_44 ,
& V_54 , V_48 ) ) {
F_12 ( L_5 ) ;
return - V_33 ;
}
* V_30 = V_55 ;
V_46 = F_23 ( V_2 , F_24 ( V_41 , V_7 , & V_50 ) ,
& V_43 ) ;
if ( ! V_46 ) {
F_12 ( L_6 ) ;
return - V_33 ;
} else {
if ( F_25 ( V_46 ) == V_56 )
* V_30 += V_57 ;
}
V_7 -> V_51 = & F_26 ( V_46 ) -> V_58 ;
V_7 -> V_59 = * V_30 ;
return V_33 ;
}
static int
F_27 ( struct V_2 * V_2 , struct V_28 * V_41 ,
struct V_6 * V_7 , unsigned int V_8 ,
enum V_29 * V_30 , T_1 V_31 , unsigned int V_32 )
{
const struct V_11 * V_60 ;
struct V_11 V_61 ;
int type ;
V_60 = F_3 ( V_7 , V_8 , sizeof( V_61 ) , & V_61 ) ;
if ( V_60 == NULL ) {
if ( F_14 ( V_2 , V_39 ) )
F_16 ( V_2 , V_40 , 0 , V_7 , NULL , NULL , NULL ,
L_7 ) ;
return - V_33 ;
}
if ( V_2 -> V_3 . V_62 && V_32 == V_63 &&
F_28 ( V_7 , V_32 , V_8 , V_39 ) ) {
if ( F_14 ( V_2 , V_39 ) )
F_16 ( V_2 , V_40 , 0 , V_7 , NULL , NULL , NULL ,
L_8 ) ;
return - V_33 ;
}
type = V_60 -> V_17 - 130 ;
if ( type >= 0 && type < sizeof( V_64 ) &&
V_64 [ type ] ) {
V_7 -> V_51 = & F_29 () -> V_58 ;
V_7 -> V_59 = V_65 ;
F_30 ( V_7 -> V_51 ) ;
return V_33 ;
}
if ( V_60 -> V_17 >= 128 )
return V_33 ;
return F_17 ( V_2 , V_41 , V_7 , V_8 , V_30 , V_32 ) ;
}
static int F_31 ( struct V_6 * V_7 ,
const struct V_9 * V_66 )
{
if ( F_32 ( V_7 , V_67 , V_66 -> V_18 . V_15 . V_16 . V_19 ) ||
F_33 ( V_7 , V_68 , V_66 -> V_14 . V_15 . V_16 . type ) ||
F_33 ( V_7 , V_69 , V_66 -> V_14 . V_15 . V_16 . V_21 ) )
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
V_10 -> V_14 . V_15 . V_16 . type = F_35 ( V_72 [ V_68 ] ) ;
V_10 -> V_14 . V_15 . V_16 . V_21 = F_35 ( V_72 [ V_69 ] ) ;
V_10 -> V_18 . V_15 . V_16 . V_19 = F_36 ( V_72 [ V_67 ] ) ;
if ( V_10 -> V_14 . V_15 . V_16 . type < 128 ||
V_10 -> V_14 . V_15 . V_16 . type - 128 >= sizeof( V_24 ) ||
! V_24 [ V_10 -> V_14 . V_15 . V_16 . type - 128 ] )
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
unsigned int * V_27 = V_76 ;
struct V_1 * V_77 = F_1 ( V_2 ) ;
if ( V_72 [ V_78 ] ) {
* V_27 =
F_40 ( F_41 ( V_72 [ V_78 ] ) ) * V_79 ;
} else {
* V_27 = V_77 -> V_27 ;
}
return 0 ;
}
static int
F_42 ( struct V_6 * V_7 , const void * V_76 )
{
const unsigned int * V_27 = V_76 ;
if ( F_43 ( V_7 , V_78 , F_44 ( * V_27 / V_79 ) ) )
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
V_82 -> V_83 [ 0 ] . V_76 = & V_77 -> V_27 ;
#endif
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , T_2 V_87 )
{
struct V_1 * V_77 = F_1 ( V_2 ) ;
struct V_81 * V_82 = & V_77 -> V_82 ;
V_77 -> V_27 = V_88 ;
return F_45 ( V_82 , V_77 ) ;
}
static struct V_81 * F_49 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_82 ;
}
