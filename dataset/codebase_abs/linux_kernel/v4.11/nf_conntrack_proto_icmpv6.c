static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 ,
unsigned int V_8 ,
struct V_2 * V_2 ,
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
unsigned int V_32 )
{
struct V_9 V_43 , V_44 ;
const struct V_45 * V_46 ;
const struct V_47 * V_48 ;
enum V_29 V_30 ;
struct V_49 V_50 ;
F_18 ( ! F_19 ( V_7 ) ) ;
if ( ! F_20 ( V_7 ,
F_21 ( V_7 )
+ sizeof( struct V_51 )
+ sizeof( struct V_11 ) ,
V_40 , V_2 , & V_44 ) ) {
F_12 ( L_4 ) ;
return - V_33 ;
}
V_48 = F_22 ( V_40 , V_44 . V_14 . V_52 ) ;
if ( ! F_23 ( & V_43 , & V_44 ,
& V_53 , V_48 ) ) {
F_12 ( L_5 ) ;
return - V_33 ;
}
V_30 = V_54 ;
V_46 = F_24 ( V_2 , F_25 ( V_41 , V_7 , & V_50 ) ,
& V_43 ) ;
if ( ! V_46 ) {
F_12 ( L_6 ) ;
return - V_33 ;
} else {
if ( F_26 ( V_46 ) == V_55 )
V_30 += V_56 ;
}
F_27 ( V_7 , F_28 ( V_46 ) , V_30 ) ;
return V_33 ;
}
static int
F_29 ( struct V_2 * V_2 , struct V_28 * V_41 ,
struct V_6 * V_7 , unsigned int V_8 ,
T_2 V_31 , unsigned int V_32 )
{
const struct V_11 * V_57 ;
struct V_11 V_58 ;
int type ;
V_57 = F_3 ( V_7 , V_8 , sizeof( V_58 ) , & V_58 ) ;
if ( V_57 == NULL ) {
if ( F_14 ( V_2 , V_39 ) )
F_16 ( V_2 , V_40 , 0 , V_7 , NULL , NULL , NULL ,
L_7 ) ;
return - V_33 ;
}
if ( V_2 -> V_3 . V_59 && V_32 == V_60 &&
F_30 ( V_7 , V_32 , V_8 , V_39 ) ) {
if ( F_14 ( V_2 , V_39 ) )
F_16 ( V_2 , V_40 , 0 , V_7 , NULL , NULL , NULL ,
L_8 ) ;
return - V_33 ;
}
type = V_57 -> V_17 - 130 ;
if ( type >= 0 && type < sizeof( V_61 ) &&
V_61 [ type ] ) {
F_27 ( V_7 , F_31 () , V_62 ) ;
F_32 ( F_19 ( V_7 ) ) ;
return V_33 ;
}
if ( V_57 -> V_17 >= 128 )
return V_33 ;
return F_17 ( V_2 , V_41 , V_7 , V_8 , V_32 ) ;
}
static int F_33 ( struct V_6 * V_7 ,
const struct V_9 * V_63 )
{
if ( F_34 ( V_7 , V_64 , V_63 -> V_18 . V_15 . V_16 . V_19 ) ||
F_35 ( V_7 , V_65 , V_63 -> V_14 . V_15 . V_16 . type ) ||
F_35 ( V_7 , V_66 , V_63 -> V_14 . V_15 . V_16 . V_21 ) )
goto V_67;
return 0 ;
V_67:
return - 1 ;
}
static int F_36 ( struct V_68 * V_69 [] ,
struct V_9 * V_10 )
{
if ( ! V_69 [ V_65 ] ||
! V_69 [ V_66 ] ||
! V_69 [ V_64 ] )
return - V_70 ;
V_10 -> V_14 . V_15 . V_16 . type = F_37 ( V_69 [ V_65 ] ) ;
V_10 -> V_14 . V_15 . V_16 . V_21 = F_37 ( V_69 [ V_66 ] ) ;
V_10 -> V_18 . V_15 . V_16 . V_19 = F_38 ( V_69 [ V_64 ] ) ;
if ( V_10 -> V_14 . V_15 . V_16 . type < 128 ||
V_10 -> V_14 . V_15 . V_16 . type - 128 >= sizeof( V_24 ) ||
! V_24 [ V_10 -> V_14 . V_15 . V_16 . type - 128 ] )
return - V_70 ;
return 0 ;
}
static int F_39 ( void )
{
return F_40 ( V_71 , V_72 + 1 ) ;
}
static int F_41 ( struct V_68 * V_69 [] ,
struct V_2 * V_2 , void * V_73 )
{
unsigned int * V_27 = V_73 ;
struct V_1 * V_74 = F_1 ( V_2 ) ;
if ( V_69 [ V_75 ] ) {
* V_27 =
F_42 ( F_43 ( V_69 [ V_75 ] ) ) * V_76 ;
} else {
* V_27 = V_74 -> V_27 ;
}
return 0 ;
}
static int
F_44 ( struct V_6 * V_7 , const void * V_73 )
{
const unsigned int * V_27 = V_73 ;
if ( F_45 ( V_7 , V_75 , F_46 ( * V_27 / V_76 ) ) )
goto V_67;
return 0 ;
V_67:
return - V_77 ;
}
static int F_47 ( struct V_78 * V_79 ,
struct V_1 * V_74 )
{
#ifdef F_48
V_79 -> V_80 = F_49 ( V_81 ,
sizeof( V_81 ) ,
V_82 ) ;
if ( ! V_79 -> V_80 )
return - V_83 ;
V_79 -> V_80 [ 0 ] . V_73 = & V_74 -> V_27 ;
#endif
return 0 ;
}
static int F_50 ( struct V_2 * V_2 , T_3 V_84 )
{
struct V_1 * V_74 = F_1 ( V_2 ) ;
struct V_78 * V_79 = & V_74 -> V_79 ;
V_74 -> V_27 = V_85 ;
return F_47 ( V_79 , V_74 ) ;
}
static struct V_78 * F_51 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_79 ;
}
