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
static unsigned int * F_5 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_25 ;
}
static int F_6 ( struct V_26 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_27 V_28 ,
T_1 V_29 ,
unsigned int * V_25 )
{
F_7 ( V_3 , V_28 , V_7 , * V_25 ) ;
return V_30 ;
}
static bool F_8 ( struct V_26 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_31 )
{
static const T_1 V_32 [] = {
[ V_33 - 128 ] = 1 ,
[ V_34 - 128 ] = 1
} ;
int type = V_3 -> V_35 [ 0 ] . V_10 . V_14 . V_15 . V_16 . type - 128 ;
if ( type < 0 || type >= sizeof( V_32 ) || ! V_32 [ type ] ) {
F_9 ( L_1 ,
type + 128 ) ;
F_10 ( & V_3 -> V_35 [ 0 ] . V_10 ) ;
return false ;
}
return true ;
}
static int
F_11 ( struct V_2 * V_2 , struct V_26 * V_36 ,
struct V_6 * V_7 ,
unsigned int V_37 )
{
struct V_9 V_38 , V_39 ;
const struct V_40 * V_41 ;
const struct V_42 * V_43 ;
enum V_27 V_28 ;
struct V_44 V_45 ;
F_12 ( F_13 ( V_7 ) ) ;
if ( ! F_14 ( V_7 ,
F_15 ( V_7 )
+ sizeof( struct V_46 )
+ sizeof( struct V_11 ) ,
V_47 , V_2 , & V_39 ) ) {
F_9 ( L_2 ) ;
return - V_30 ;
}
V_43 = F_16 ( V_47 , V_39 . V_14 . V_48 ) ;
if ( ! F_17 ( & V_38 , & V_39 ,
& V_49 , V_43 ) ) {
F_9 ( L_3 ) ;
return - V_30 ;
}
V_28 = V_50 ;
V_41 = F_18 ( V_2 , F_19 ( V_36 , V_7 , & V_45 ) ,
& V_38 ) ;
if ( ! V_41 ) {
F_9 ( L_4 ) ;
return - V_30 ;
} else {
if ( F_20 ( V_41 ) == V_51 )
V_28 += V_52 ;
}
F_21 ( V_7 , F_22 ( V_41 ) , V_28 ) ;
return V_30 ;
}
static int
F_23 ( struct V_2 * V_2 , struct V_26 * V_36 ,
struct V_6 * V_7 , unsigned int V_8 ,
T_2 V_29 , unsigned int V_53 )
{
const struct V_11 * V_54 ;
struct V_11 V_55 ;
int type ;
V_54 = F_3 ( V_7 , V_8 , sizeof( V_55 ) , & V_55 ) ;
if ( V_54 == NULL ) {
if ( F_24 ( V_2 , V_56 ) )
F_25 ( V_2 , V_47 , 0 , V_7 , NULL , NULL , NULL ,
L_5 ) ;
return - V_30 ;
}
if ( V_2 -> V_3 . V_57 && V_53 == V_58 &&
F_26 ( V_7 , V_53 , V_8 , V_56 ) ) {
if ( F_24 ( V_2 , V_56 ) )
F_25 ( V_2 , V_47 , 0 , V_7 , NULL , NULL , NULL ,
L_6 ) ;
return - V_30 ;
}
type = V_54 -> V_17 - 130 ;
if ( type >= 0 && type < sizeof( V_59 ) &&
V_59 [ type ] ) {
F_21 ( V_7 , NULL , V_60 ) ;
return V_30 ;
}
if ( V_54 -> V_17 >= 128 )
return V_30 ;
return F_11 ( V_2 , V_36 , V_7 , V_8 ) ;
}
static int F_27 ( struct V_6 * V_7 ,
const struct V_9 * V_61 )
{
if ( F_28 ( V_7 , V_62 , V_61 -> V_18 . V_15 . V_16 . V_19 ) ||
F_29 ( V_7 , V_63 , V_61 -> V_14 . V_15 . V_16 . type ) ||
F_29 ( V_7 , V_64 , V_61 -> V_14 . V_15 . V_16 . V_21 ) )
goto V_65;
return 0 ;
V_65:
return - 1 ;
}
static int F_30 ( struct V_66 * V_67 [] ,
struct V_9 * V_10 )
{
if ( ! V_67 [ V_63 ] ||
! V_67 [ V_64 ] ||
! V_67 [ V_62 ] )
return - V_68 ;
V_10 -> V_14 . V_15 . V_16 . type = F_31 ( V_67 [ V_63 ] ) ;
V_10 -> V_14 . V_15 . V_16 . V_21 = F_31 ( V_67 [ V_64 ] ) ;
V_10 -> V_18 . V_15 . V_16 . V_19 = F_32 ( V_67 [ V_62 ] ) ;
if ( V_10 -> V_14 . V_15 . V_16 . type < 128 ||
V_10 -> V_14 . V_15 . V_16 . type - 128 >= sizeof( V_24 ) ||
! V_24 [ V_10 -> V_14 . V_15 . V_16 . type - 128 ] )
return - V_68 ;
return 0 ;
}
static int F_33 ( void )
{
return F_34 ( V_69 , V_70 + 1 ) ;
}
static int F_35 ( struct V_66 * V_67 [] ,
struct V_2 * V_2 , void * V_71 )
{
unsigned int * V_25 = V_71 ;
struct V_1 * V_72 = F_1 ( V_2 ) ;
if ( V_67 [ V_73 ] ) {
* V_25 =
F_36 ( F_37 ( V_67 [ V_73 ] ) ) * V_74 ;
} else {
* V_25 = V_72 -> V_25 ;
}
return 0 ;
}
static int
F_38 ( struct V_6 * V_7 , const void * V_71 )
{
const unsigned int * V_25 = V_71 ;
if ( F_39 ( V_7 , V_73 , F_40 ( * V_25 / V_74 ) ) )
goto V_65;
return 0 ;
V_65:
return - V_75 ;
}
static int F_41 ( struct V_76 * V_77 ,
struct V_1 * V_72 )
{
#ifdef F_42
V_77 -> V_78 = F_43 ( V_79 ,
sizeof( V_79 ) ,
V_80 ) ;
if ( ! V_77 -> V_78 )
return - V_81 ;
V_77 -> V_78 [ 0 ] . V_71 = & V_72 -> V_25 ;
#endif
return 0 ;
}
static int F_44 ( struct V_2 * V_2 , T_3 V_82 )
{
struct V_1 * V_72 = F_1 ( V_2 ) ;
struct V_76 * V_77 = & V_72 -> V_77 ;
V_72 -> V_25 = V_83 ;
return F_41 ( V_77 , V_72 ) ;
}
static struct V_76 * F_45 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_77 ;
}
