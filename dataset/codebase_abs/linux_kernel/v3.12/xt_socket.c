static void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 )
F_2 ( F_3 ( V_2 ) ) ;
else
F_4 ( V_2 ) ;
}
static int
F_5 ( const struct V_5 * V_6 ,
T_1 * V_7 ,
T_2 * V_8 ,
T_2 * V_9 ,
T_3 * V_10 ,
T_3 * V_11 )
{
unsigned int V_12 = F_6 ( V_6 ) ;
struct V_13 * V_14 , V_15 ;
struct V_16 * V_17 , V_18 ;
T_3 * V_19 , V_20 [ 2 ] ;
V_17 = F_7 ( V_6 , V_12 ,
sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL )
return 1 ;
switch ( V_17 -> type ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
break;
default:
return 1 ;
}
V_14 = F_7 ( V_6 , V_12 +
sizeof( struct V_16 ) ,
sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL )
return 1 ;
if ( V_14 -> V_7 != V_26 &&
V_14 -> V_7 != V_27 )
return 1 ;
V_19 = F_7 ( V_6 , V_12 +
sizeof( struct V_16 ) +
( V_14 -> V_28 << 2 ) ,
sizeof( V_20 ) , & V_20 ) ;
if ( V_19 == NULL )
return 1 ;
* V_7 = V_14 -> V_7 ;
* V_9 = V_14 -> V_29 ;
* V_11 = V_19 [ 0 ] ;
* V_8 = V_14 -> V_30 ;
* V_10 = V_19 [ 1 ] ;
return 0 ;
}
static struct V_1 *
F_8 ( struct V_31 * V_31 , const T_1 V_7 ,
const T_2 V_29 , const T_2 V_30 ,
const T_3 V_32 , const T_3 V_33 ,
const struct V_34 * V_35 )
{
switch ( V_7 ) {
case V_26 :
return F_9 ( V_31 , & V_36 ,
V_29 , V_32 , V_30 , V_33 ,
V_35 -> V_37 ) ;
case V_27 :
return F_10 ( V_31 , V_29 , V_32 , V_30 , V_33 ,
V_35 -> V_37 ) ;
}
return NULL ;
}
static bool
F_11 ( const struct V_5 * V_6 , struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
const struct V_13 * V_42 = F_12 ( V_6 ) ;
struct V_43 V_44 , * V_45 = NULL ;
struct V_1 * V_2 = V_6 -> V_2 ;
T_2 V_46 ( V_30 ) , V_46 ( V_29 ) ;
T_3 V_46 ( V_33 ) , V_46 ( V_32 ) ;
T_1 V_46 ( V_7 ) ;
#ifdef F_13
struct V_47 const * V_48 ;
enum V_49 V_50 ;
#endif
if ( V_42 -> V_7 == V_27 || V_42 -> V_7 == V_26 ) {
V_45 = F_7 ( V_6 , F_6 ( V_6 ) ,
sizeof( V_44 ) , & V_44 ) ;
if ( V_45 == NULL )
return false ;
V_7 = V_42 -> V_7 ;
V_29 = V_42 -> V_29 ;
V_32 = V_45 -> V_51 ;
V_30 = V_42 -> V_30 ;
V_33 = V_45 -> V_52 ;
} else if ( V_42 -> V_7 == V_53 ) {
if ( F_5 ( V_6 , & V_7 , & V_29 , & V_30 ,
& V_32 , & V_33 ) )
return false ;
} else {
return false ;
}
#ifdef F_13
V_48 = F_14 ( V_6 , & V_50 ) ;
if ( V_48 && ! F_15 ( V_48 ) &&
( ( V_42 -> V_7 != V_53 &&
V_50 == V_54 ) ||
( V_42 -> V_7 == V_53 &&
V_50 == V_55 ) ) &&
( V_48 -> V_56 & V_57 ) ) {
V_30 = V_48 -> V_58 [ V_59 ] . V_60 . V_61 . V_62 . V_63 ;
V_33 = ( V_42 -> V_7 == V_26 ) ?
V_48 -> V_58 [ V_59 ] . V_60 . V_61 . V_64 . V_65 . V_66 :
V_48 -> V_58 [ V_59 ] . V_60 . V_61 . V_64 . V_67 . V_66 ;
}
#endif
if ( ! V_2 )
V_2 = F_8 ( F_16 ( V_6 -> V_68 ) , V_7 ,
V_29 , V_30 , V_32 , V_33 ,
V_39 -> V_35 ) ;
if ( V_2 ) {
bool V_69 ;
bool V_70 = true ;
V_69 = ( ! ( V_41 -> V_71 & V_72 ) &&
V_2 -> V_3 != V_4 &&
F_17 ( V_2 ) -> V_73 == 0 ) ;
if ( V_41 -> V_71 & V_74 )
V_70 = ( ( V_2 -> V_3 != V_4 &&
F_17 ( V_2 ) -> V_70 ) ||
( V_2 -> V_3 == V_4 &&
F_3 ( V_2 ) -> V_75 ) ) ;
if ( V_2 != V_6 -> V_2 )
F_1 ( V_2 ) ;
if ( V_69 || ! V_70 )
V_2 = NULL ;
}
F_18 ( L_1 ,
V_7 , & V_29 , F_19 ( V_32 ) ,
& V_30 , F_19 ( V_33 ) ,
& V_42 -> V_30 , V_45 ? F_19 ( V_45 -> V_52 ) : 0 , V_2 ) ;
return ( V_2 != NULL ) ;
}
static bool
F_20 ( const struct V_5 * V_6 , struct V_38 * V_39 )
{
static struct V_40 V_76 = {
. V_71 = 0 ,
} ;
return F_11 ( V_6 , V_39 , & V_76 ) ;
}
static bool
F_21 ( const struct V_5 * V_6 , struct V_38 * V_39 )
{
return F_11 ( V_6 , V_39 , V_39 -> V_77 ) ;
}
static int
F_22 ( const struct V_5 * V_6 ,
unsigned int V_12 ,
int * V_7 ,
struct V_78 * * V_8 ,
struct V_78 * * V_9 ,
T_3 * V_10 ,
T_3 * V_11 )
{
struct V_79 * V_14 , V_15 ;
struct V_80 * V_17 , V_18 ;
T_3 * V_19 , V_20 [ 2 ] ;
T_1 V_81 ;
T_3 V_82 ;
int V_83 ;
V_17 = F_7 ( V_6 , V_12 ,
sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL )
return 1 ;
if ( V_17 -> V_84 & V_85 )
return 1 ;
V_14 = F_7 ( V_6 , V_12 + sizeof( V_18 ) , sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL )
return 1 ;
V_81 = V_14 -> V_86 ;
V_83 = F_23 ( V_6 , V_12 + sizeof( V_18 ) + sizeof( V_15 ) ,
& V_81 , & V_82 ) ;
if ( V_83 < 0 )
return 1 ;
if ( V_81 != V_26 &&
V_81 != V_27 )
return 1 ;
V_19 = F_7 ( V_6 , V_83 ,
sizeof( V_20 ) , & V_20 ) ;
if ( V_19 == NULL )
return 1 ;
* V_7 = V_81 ;
* V_9 = & V_14 -> V_29 ;
* V_11 = V_19 [ 0 ] ;
* V_8 = & V_14 -> V_30 ;
* V_10 = V_19 [ 1 ] ;
return 0 ;
}
static struct V_1 *
F_24 ( struct V_31 * V_31 , const T_1 V_7 ,
const struct V_78 * V_29 , const struct V_78 * V_30 ,
const T_3 V_32 , const T_3 V_33 ,
const struct V_34 * V_35 )
{
switch ( V_7 ) {
case V_26 :
return F_25 ( V_31 , & V_36 ,
V_29 , V_32 , V_30 , V_33 ,
V_35 -> V_37 ) ;
case V_27 :
return F_26 ( V_31 , V_29 , V_32 , V_30 , V_33 ,
V_35 -> V_37 ) ;
}
return NULL ;
}
static bool
F_27 ( const struct V_5 * V_6 , struct V_38 * V_39 )
{
struct V_79 * V_42 = F_28 ( V_6 ) ;
struct V_43 V_44 , * V_45 = NULL ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_78 * V_30 = NULL , * V_29 = NULL ;
T_3 V_46 ( V_33 ) , V_46 ( V_32 ) ;
int V_87 = 0 , V_46 ( V_88 ) ;
const struct V_40 * V_41 = (struct V_40 * ) V_39 -> V_77 ;
V_88 = F_29 ( V_6 , & V_87 , - 1 , NULL , NULL ) ;
if ( V_88 < 0 ) {
F_18 ( L_2 ) ;
return V_89 ;
}
if ( V_88 == V_27 || V_88 == V_26 ) {
V_45 = F_7 ( V_6 , V_87 ,
sizeof( V_44 ) , & V_44 ) ;
if ( V_45 == NULL )
return false ;
V_29 = & V_42 -> V_29 ;
V_32 = V_45 -> V_51 ;
V_30 = & V_42 -> V_30 ;
V_33 = V_45 -> V_52 ;
} else if ( V_88 == V_90 ) {
if ( F_22 ( V_6 , V_87 , & V_88 , & V_29 , & V_30 ,
& V_32 , & V_33 ) )
return false ;
} else {
return false ;
}
if ( ! V_2 )
V_2 = F_24 ( F_16 ( V_6 -> V_68 ) , V_88 ,
V_29 , V_30 , V_32 , V_33 ,
V_39 -> V_35 ) ;
if ( V_2 ) {
bool V_69 ;
bool V_70 = true ;
V_69 = ( ! ( V_41 -> V_71 & V_72 ) &&
V_2 -> V_3 != V_4 &&
F_30 ( & F_31 ( V_2 ) -> V_91 ) ) ;
if ( V_41 -> V_71 & V_74 )
V_70 = ( ( V_2 -> V_3 != V_4 &&
F_17 ( V_2 ) -> V_70 ) ||
( V_2 -> V_3 == V_4 &&
F_3 ( V_2 ) -> V_75 ) ) ;
if ( V_2 != V_6 -> V_2 )
F_1 ( V_2 ) ;
if ( V_69 || ! V_70 )
V_2 = NULL ;
}
F_18 ( L_3
L_4 ,
V_88 , V_29 , F_19 ( V_32 ) ,
V_30 , F_19 ( V_33 ) ,
& V_42 -> V_30 , V_45 ? F_19 ( V_45 -> V_52 ) : 0 , V_2 ) ;
return ( V_2 != NULL ) ;
}
static int F_32 ( const struct V_92 * V_39 )
{
const struct V_40 * V_41 = (struct V_40 * ) V_39 -> V_77 ;
if ( V_41 -> V_71 & ~ V_93 ) {
F_33 ( L_5 , V_41 -> V_71 & ~ V_93 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_34 ( const struct V_92 * V_39 )
{
const struct V_95 * V_41 = (struct V_95 * ) V_39 -> V_77 ;
if ( V_41 -> V_71 & ~ V_96 ) {
F_33 ( L_5 , V_41 -> V_71 & ~ V_96 ) ;
return - V_94 ;
}
return 0 ;
}
static int T_4 F_35 ( void )
{
F_36 () ;
#ifdef F_37
F_38 () ;
#endif
return F_39 ( V_97 , F_40 ( V_97 ) ) ;
}
static void T_5 F_41 ( void )
{
F_42 ( V_97 , F_40 ( V_97 ) ) ;
}
