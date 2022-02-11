static int
F_1 ( const struct V_1 * V_2 ,
T_1 * V_3 ,
T_2 * V_4 ,
T_2 * V_5 ,
T_3 * V_6 ,
T_3 * V_7 )
{
unsigned int V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 , V_11 ;
struct V_12 * V_13 , V_14 ;
T_3 * V_15 , V_16 [ 2 ] ;
V_13 = F_3 ( V_2 , V_8 ,
sizeof( V_14 ) , & V_14 ) ;
if ( V_13 == NULL )
return 1 ;
switch ( V_13 -> type ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
break;
default:
return 1 ;
}
V_10 = F_3 ( V_2 , V_8 +
sizeof( struct V_12 ) ,
sizeof( V_11 ) , & V_11 ) ;
if ( V_10 == NULL )
return 1 ;
if ( V_10 -> V_3 != V_22 &&
V_10 -> V_3 != V_23 )
return 1 ;
V_15 = F_3 ( V_2 , V_8 +
sizeof( struct V_12 ) +
( V_10 -> V_24 << 2 ) ,
sizeof( V_16 ) , & V_16 ) ;
if ( V_15 == NULL )
return 1 ;
* V_3 = V_10 -> V_3 ;
* V_5 = V_10 -> V_25 ;
* V_7 = V_15 [ 0 ] ;
* V_4 = V_10 -> V_26 ;
* V_6 = V_15 [ 1 ] ;
return 0 ;
}
static struct V_27 *
F_4 ( struct V_28 * V_28 , const T_1 V_3 ,
const T_2 V_25 , const T_2 V_26 ,
const T_3 V_29 , const T_3 V_30 ,
const struct V_31 * V_32 )
{
switch ( V_3 ) {
case V_22 :
return F_5 ( V_28 , & V_33 ,
V_25 , V_29 , V_26 , V_30 ,
V_32 -> V_34 ) ;
case V_23 :
return F_6 ( V_28 , V_25 , V_29 , V_26 , V_30 ,
V_32 -> V_34 ) ;
}
return NULL ;
}
static bool
F_7 ( const struct V_1 * V_2 , struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
const struct V_9 * V_39 = F_8 ( V_2 ) ;
struct V_40 V_41 , * V_42 = NULL ;
struct V_27 * V_43 = V_2 -> V_43 ;
T_2 V_44 ( V_26 ) , V_44 ( V_25 ) ;
T_3 V_44 ( V_30 ) , V_44 ( V_29 ) ;
T_1 V_44 ( V_3 ) ;
#ifdef F_9
struct V_45 const * V_46 ;
enum V_47 V_48 ;
#endif
if ( V_39 -> V_3 == V_23 || V_39 -> V_3 == V_22 ) {
V_42 = F_3 ( V_2 , F_2 ( V_2 ) ,
sizeof( V_41 ) , & V_41 ) ;
if ( V_42 == NULL )
return false ;
V_3 = V_39 -> V_3 ;
V_25 = V_39 -> V_25 ;
V_29 = V_42 -> V_49 ;
V_26 = V_39 -> V_26 ;
V_30 = V_42 -> V_50 ;
} else if ( V_39 -> V_3 == V_51 ) {
if ( F_1 ( V_2 , & V_3 , & V_25 , & V_26 ,
& V_29 , & V_30 ) )
return false ;
} else {
return false ;
}
#ifdef F_9
V_46 = F_10 ( V_2 , & V_48 ) ;
if ( V_46 && ! F_11 ( V_46 ) &&
( ( V_39 -> V_3 != V_51 &&
V_48 == V_52 ) ||
( V_39 -> V_3 == V_51 &&
V_48 == V_53 ) ) &&
( V_46 -> V_54 & V_55 ) ) {
V_26 = V_46 -> V_56 [ V_57 ] . V_58 . V_59 . V_60 . V_61 ;
V_30 = ( V_39 -> V_3 == V_22 ) ?
V_46 -> V_56 [ V_57 ] . V_58 . V_59 . V_62 . V_63 . V_64 :
V_46 -> V_56 [ V_57 ] . V_58 . V_59 . V_62 . V_65 . V_64 ;
}
#endif
if ( ! V_43 )
V_43 = F_4 ( F_12 ( V_2 -> V_66 ) , V_3 ,
V_25 , V_26 , V_29 , V_30 ,
V_36 -> V_32 ) ;
if ( V_43 ) {
bool V_67 ;
bool V_68 = true ;
V_67 = ( ! ( V_38 -> V_69 & V_70 ) &&
V_43 -> V_71 != V_72 &&
F_13 ( V_43 ) -> V_73 == 0 ) ;
if ( V_38 -> V_69 & V_74 )
V_68 = ( ( V_43 -> V_71 != V_72 &&
F_13 ( V_43 ) -> V_68 ) ||
( V_43 -> V_71 == V_72 &&
F_14 ( V_43 ) -> V_75 ) ) ;
if ( V_43 != V_2 -> V_43 )
F_15 ( V_43 ) ;
if ( V_67 || ! V_68 )
V_43 = NULL ;
}
F_16 ( L_1 ,
V_3 , & V_25 , F_17 ( V_29 ) ,
& V_26 , F_17 ( V_30 ) ,
& V_39 -> V_26 , V_42 ? F_17 ( V_42 -> V_50 ) : 0 , V_43 ) ;
return ( V_43 != NULL ) ;
}
static bool
F_18 ( const struct V_1 * V_2 , struct V_35 * V_36 )
{
static struct V_37 V_76 = {
. V_69 = 0 ,
} ;
return F_7 ( V_2 , V_36 , & V_76 ) ;
}
static bool
F_19 ( const struct V_1 * V_2 , struct V_35 * V_36 )
{
return F_7 ( V_2 , V_36 , V_36 -> V_77 ) ;
}
static int
F_20 ( const struct V_1 * V_2 ,
unsigned int V_8 ,
int * V_3 ,
struct V_78 * * V_4 ,
struct V_78 * * V_5 ,
T_3 * V_6 ,
T_3 * V_7 )
{
struct V_79 * V_10 , V_11 ;
struct V_80 * V_13 , V_14 ;
T_3 * V_15 , V_16 [ 2 ] ;
T_1 V_81 ;
T_3 V_82 ;
int V_83 ;
V_13 = F_3 ( V_2 , V_8 ,
sizeof( V_14 ) , & V_14 ) ;
if ( V_13 == NULL )
return 1 ;
if ( V_13 -> V_84 & V_85 )
return 1 ;
V_10 = F_3 ( V_2 , V_8 + sizeof( V_14 ) , sizeof( V_11 ) , & V_11 ) ;
if ( V_10 == NULL )
return 1 ;
V_81 = V_10 -> V_86 ;
V_83 = F_21 ( V_2 , V_8 + sizeof( V_14 ) + sizeof( V_11 ) ,
& V_81 , & V_82 ) ;
if ( V_83 < 0 )
return 1 ;
if ( V_81 != V_22 &&
V_81 != V_23 )
return 1 ;
V_15 = F_3 ( V_2 , V_83 ,
sizeof( V_16 ) , & V_16 ) ;
if ( V_15 == NULL )
return 1 ;
* V_3 = V_81 ;
* V_5 = & V_10 -> V_25 ;
* V_7 = V_15 [ 0 ] ;
* V_4 = & V_10 -> V_26 ;
* V_6 = V_15 [ 1 ] ;
return 0 ;
}
static struct V_27 *
F_22 ( struct V_28 * V_28 , const T_1 V_3 ,
const struct V_78 * V_25 , const struct V_78 * V_26 ,
const T_3 V_29 , const T_3 V_30 ,
const struct V_31 * V_32 )
{
switch ( V_3 ) {
case V_22 :
return F_23 ( V_28 , & V_33 ,
V_25 , V_29 , V_26 , V_30 ,
V_32 -> V_34 ) ;
case V_23 :
return F_24 ( V_28 , V_25 , V_29 , V_26 , V_30 ,
V_32 -> V_34 ) ;
}
return NULL ;
}
static bool
F_25 ( const struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_79 * V_39 = F_26 ( V_2 ) ;
struct V_40 V_41 , * V_42 = NULL ;
struct V_27 * V_43 = V_2 -> V_43 ;
struct V_78 * V_26 = NULL , * V_25 = NULL ;
T_3 V_44 ( V_30 ) , V_44 ( V_29 ) ;
int V_87 = 0 , V_44 ( V_88 ) ;
const struct V_37 * V_38 = (struct V_37 * ) V_36 -> V_77 ;
V_88 = F_27 ( V_2 , & V_87 , - 1 , NULL , NULL ) ;
if ( V_88 < 0 ) {
F_16 ( L_2 ) ;
return V_89 ;
}
if ( V_88 == V_23 || V_88 == V_22 ) {
V_42 = F_3 ( V_2 , V_87 ,
sizeof( V_41 ) , & V_41 ) ;
if ( V_42 == NULL )
return false ;
V_25 = & V_39 -> V_25 ;
V_29 = V_42 -> V_49 ;
V_26 = & V_39 -> V_26 ;
V_30 = V_42 -> V_50 ;
} else if ( V_88 == V_90 ) {
if ( F_20 ( V_2 , V_87 , & V_88 , & V_25 , & V_26 ,
& V_29 , & V_30 ) )
return false ;
} else {
return false ;
}
if ( ! V_43 )
V_43 = F_22 ( F_12 ( V_2 -> V_66 ) , V_88 ,
V_25 , V_26 , V_29 , V_30 ,
V_36 -> V_32 ) ;
if ( V_43 ) {
bool V_67 ;
bool V_68 = true ;
V_67 = ( ! ( V_38 -> V_69 & V_70 ) &&
V_43 -> V_71 != V_72 &&
F_28 ( & V_43 -> V_91 ) ) ;
if ( V_38 -> V_69 & V_74 )
V_68 = ( ( V_43 -> V_71 != V_72 &&
F_13 ( V_43 ) -> V_68 ) ||
( V_43 -> V_71 == V_72 &&
F_14 ( V_43 ) -> V_75 ) ) ;
if ( V_43 != V_2 -> V_43 )
F_15 ( V_43 ) ;
if ( V_67 || ! V_68 )
V_43 = NULL ;
}
F_16 ( L_3
L_4 ,
V_88 , V_25 , F_17 ( V_29 ) ,
V_26 , F_17 ( V_30 ) ,
& V_39 -> V_26 , V_42 ? F_17 ( V_42 -> V_50 ) : 0 , V_43 ) ;
return ( V_43 != NULL ) ;
}
static int F_29 ( const struct V_92 * V_36 )
{
const struct V_37 * V_38 = (struct V_37 * ) V_36 -> V_77 ;
if ( V_38 -> V_69 & ~ V_93 ) {
F_30 ( L_5 , V_38 -> V_69 & ~ V_93 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_31 ( const struct V_92 * V_36 )
{
const struct V_95 * V_38 = (struct V_95 * ) V_36 -> V_77 ;
if ( V_38 -> V_69 & ~ V_96 ) {
F_30 ( L_5 , V_38 -> V_69 & ~ V_96 ) ;
return - V_94 ;
}
return 0 ;
}
static int T_4 F_32 ( void )
{
F_33 () ;
#ifdef F_34
F_35 () ;
#endif
return F_36 ( V_97 , F_37 ( V_97 ) ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( V_97 , F_37 ( V_97 ) ) ;
}
