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
static bool F_7 ( struct V_27 * V_35 )
{
switch ( V_35 -> V_36 ) {
case V_37 :
return F_8 ( V_35 ) -> V_38 ;
case V_39 :
return F_9 ( F_10 ( V_35 ) ) -> V_40 ;
default:
return F_11 ( V_35 ) -> V_41 ;
}
}
static struct V_27 * F_12 ( struct V_28 * V_28 ,
const struct V_1 * V_2 ,
const struct V_31 * V_42 )
{
const struct V_9 * V_43 = F_13 ( V_2 ) ;
T_2 V_44 ( V_26 ) , V_44 ( V_25 ) ;
T_3 V_44 ( V_30 ) , V_44 ( V_29 ) ;
T_1 V_44 ( V_3 ) ;
#ifdef F_14
struct V_45 const * V_46 ;
enum V_47 V_48 ;
#endif
if ( V_43 -> V_3 == V_23 || V_43 -> V_3 == V_22 ) {
struct V_49 V_50 , * V_51 ;
V_51 = F_3 ( V_2 , F_2 ( V_2 ) ,
sizeof( V_50 ) , & V_50 ) ;
if ( V_51 == NULL )
return NULL ;
V_3 = V_43 -> V_3 ;
V_25 = V_43 -> V_25 ;
V_29 = V_51 -> V_52 ;
V_26 = V_43 -> V_26 ;
V_30 = V_51 -> V_53 ;
} else if ( V_43 -> V_3 == V_54 ) {
if ( F_1 ( V_2 , & V_3 , & V_25 , & V_26 ,
& V_29 , & V_30 ) )
return NULL ;
} else {
return NULL ;
}
#ifdef F_14
V_46 = F_15 ( V_2 , & V_48 ) ;
if ( V_46 && ! F_16 ( V_46 ) &&
( ( V_43 -> V_3 != V_54 &&
V_48 == V_55 ) ||
( V_43 -> V_3 == V_54 &&
V_48 == V_56 ) ) &&
( V_46 -> V_57 & V_58 ) ) {
V_26 = V_46 -> V_59 [ V_60 ] . V_61 . V_62 . V_63 . V_64 ;
V_30 = ( V_43 -> V_3 == V_22 ) ?
V_46 -> V_59 [ V_60 ] . V_61 . V_62 . V_65 . V_66 . V_67 :
V_46 -> V_59 [ V_60 ] . V_61 . V_62 . V_65 . V_68 . V_67 ;
}
#endif
return F_4 ( V_28 , V_3 , V_25 , V_26 ,
V_29 , V_30 , V_42 ) ;
}
static bool
F_17 ( const struct V_1 * V_2 , struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
struct V_1 * V_73 = (struct V_1 * ) V_2 ;
struct V_27 * V_35 = V_2 -> V_35 ;
if ( ! V_35 )
V_35 = F_12 ( V_70 -> V_28 , V_2 , V_70 -> V_32 ) ;
if ( V_35 ) {
bool V_74 ;
bool V_41 = true ;
V_74 = ( ! ( V_72 -> V_75 & V_76 ) &&
F_18 ( V_35 ) &&
F_11 ( V_35 ) -> V_77 == 0 ) ;
if ( V_72 -> V_75 & V_78 )
V_41 = F_7 ( V_35 ) ;
if ( V_72 -> V_75 & V_79 && ! V_74 &&
V_41 )
V_73 -> V_80 = V_35 -> V_81 ;
if ( V_35 != V_2 -> V_35 )
F_19 ( V_35 ) ;
if ( V_74 || ! V_41 )
V_35 = NULL ;
}
return V_35 != NULL ;
}
static bool
F_20 ( const struct V_1 * V_2 , struct V_69 * V_70 )
{
static struct V_71 V_82 = {
. V_75 = 0 ,
} ;
return F_17 ( V_2 , V_70 , & V_82 ) ;
}
static bool
F_21 ( const struct V_1 * V_2 , struct V_69 * V_70 )
{
return F_17 ( V_2 , V_70 , V_70 -> V_83 ) ;
}
static int
F_22 ( const struct V_1 * V_2 ,
unsigned int V_8 ,
int * V_3 ,
const struct V_84 * * V_4 ,
const struct V_84 * * V_5 ,
T_3 * V_6 ,
T_3 * V_7 ,
struct V_85 * V_86 )
{
const struct V_85 * V_10 ;
struct V_87 * V_13 , V_14 ;
T_3 * V_15 , V_16 [ 2 ] ;
T_1 V_88 ;
T_3 V_89 ;
int V_90 ;
V_13 = F_3 ( V_2 , V_8 ,
sizeof( V_14 ) , & V_14 ) ;
if ( V_13 == NULL )
return 1 ;
if ( V_13 -> V_91 & V_92 )
return 1 ;
V_10 = F_3 ( V_2 , V_8 + sizeof( V_14 ) ,
sizeof( * V_86 ) , V_86 ) ;
if ( V_10 == NULL )
return 1 ;
V_88 = V_10 -> V_93 ;
V_90 = F_23 ( V_2 , V_8 + sizeof( V_14 ) +
sizeof( * V_86 ) ,
& V_88 , & V_89 ) ;
if ( V_90 < 0 )
return 1 ;
if ( V_88 != V_22 &&
V_88 != V_23 )
return 1 ;
V_15 = F_3 ( V_2 , V_90 ,
sizeof( V_16 ) , & V_16 ) ;
if ( V_15 == NULL )
return 1 ;
* V_3 = V_88 ;
* V_5 = & V_10 -> V_25 ;
* V_7 = V_15 [ 0 ] ;
* V_4 = & V_10 -> V_26 ;
* V_6 = V_15 [ 1 ] ;
return 0 ;
}
static struct V_27 *
F_24 ( struct V_28 * V_28 , const T_1 V_3 ,
const struct V_84 * V_25 , const struct V_84 * V_26 ,
const T_3 V_29 , const T_3 V_30 ,
const struct V_31 * V_32 )
{
switch ( V_3 ) {
case V_22 :
return F_25 ( V_28 , & V_33 ,
V_25 , V_29 , V_26 , V_30 ,
V_32 -> V_34 ) ;
case V_23 :
return F_26 ( V_28 , V_25 , V_29 , V_26 , V_30 ,
V_32 -> V_34 ) ;
}
return NULL ;
}
static struct V_27 * F_27 ( struct V_28 * V_28 ,
const struct V_1 * V_2 ,
const struct V_31 * V_42 )
{
T_3 V_44 ( V_30 ) , V_44 ( V_29 ) ;
const struct V_84 * V_26 = NULL , * V_25 = NULL ;
struct V_85 * V_43 = F_28 ( V_2 ) ;
int V_94 = 0 , V_95 ;
V_95 = F_29 ( V_2 , & V_94 , - 1 , NULL , NULL ) ;
if ( V_95 < 0 ) {
F_30 ( L_1 ) ;
return NULL ;
}
if ( V_95 == V_23 || V_95 == V_22 ) {
struct V_49 V_50 , * V_51 ;
V_51 = F_3 ( V_2 , V_94 , sizeof( V_50 ) , & V_50 ) ;
if ( V_51 == NULL )
return NULL ;
V_25 = & V_43 -> V_25 ;
V_29 = V_51 -> V_52 ;
V_26 = & V_43 -> V_26 ;
V_30 = V_51 -> V_53 ;
} else if ( V_95 == V_96 ) {
struct V_85 V_86 ;
if ( F_22 ( V_2 , V_94 , & V_95 , & V_25 , & V_26 ,
& V_29 , & V_30 , & V_86 ) )
return NULL ;
} else {
return NULL ;
}
return F_24 ( V_28 , V_95 , V_25 , V_26 ,
V_29 , V_30 , V_42 ) ;
}
static bool
F_31 ( const struct V_1 * V_2 , struct V_69 * V_70 )
{
const struct V_71 * V_72 = (struct V_71 * ) V_70 -> V_83 ;
struct V_1 * V_73 = (struct V_1 * ) V_2 ;
struct V_27 * V_35 = V_2 -> V_35 ;
if ( ! V_35 )
V_35 = F_27 ( V_70 -> V_28 , V_2 , V_70 -> V_32 ) ;
if ( V_35 ) {
bool V_74 ;
bool V_41 = true ;
V_74 = ( ! ( V_72 -> V_75 & V_76 ) &&
F_18 ( V_35 ) &&
F_32 ( & V_35 -> V_97 ) ) ;
if ( V_72 -> V_75 & V_78 )
V_41 = F_7 ( V_35 ) ;
if ( V_72 -> V_75 & V_79 && ! V_74 &&
V_41 )
V_73 -> V_80 = V_35 -> V_81 ;
if ( V_35 != V_2 -> V_35 )
F_19 ( V_35 ) ;
if ( V_74 || ! V_41 )
V_35 = NULL ;
}
return V_35 != NULL ;
}
static int F_33 ( const struct V_98 * V_70 )
{
const struct V_71 * V_72 = (struct V_71 * ) V_70 -> V_83 ;
if ( V_72 -> V_75 & ~ V_99 ) {
F_34 ( L_2 , V_72 -> V_75 & ~ V_99 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_35 ( const struct V_98 * V_70 )
{
const struct V_101 * V_72 = (struct V_101 * ) V_70 -> V_83 ;
if ( V_72 -> V_75 & ~ V_102 ) {
F_34 ( L_2 , V_72 -> V_75 & ~ V_102 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_36 ( const struct V_98 * V_70 )
{
const struct V_103 * V_72 =
(struct V_103 * ) V_70 -> V_83 ;
if ( V_72 -> V_75 & ~ V_104 ) {
F_34 ( L_2 ,
V_72 -> V_75 & ~ V_104 ) ;
return - V_100 ;
}
return 0 ;
}
static int T_4 F_37 ( void )
{
F_38 () ;
#ifdef F_39
F_40 () ;
#endif
return F_41 ( V_105 , F_42 ( V_105 ) ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( V_105 , F_42 ( V_105 ) ) ;
}
