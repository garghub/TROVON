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
F_4 ( struct V_28 * V_28 , struct V_1 * V_2 , const int V_29 ,
const T_1 V_3 ,
const T_2 V_25 , const T_2 V_26 ,
const T_3 V_30 , const T_3 V_31 ,
const struct V_32 * V_33 )
{
switch ( V_3 ) {
case V_22 :
return F_5 ( V_28 , & V_34 , V_2 , V_29 ,
V_25 , V_30 , V_26 , V_31 ,
V_33 -> V_35 ) ;
case V_23 :
return F_6 ( V_28 , V_25 , V_30 , V_26 , V_31 ,
V_33 -> V_35 ) ;
}
return NULL ;
}
static bool F_7 ( struct V_27 * V_36 )
{
switch ( V_36 -> V_37 ) {
case V_38 :
return F_8 ( V_36 ) -> V_39 ;
case V_40 :
return F_9 ( F_10 ( V_36 ) ) -> V_41 ;
default:
return F_11 ( V_36 ) -> V_42 ;
}
}
static struct V_27 * F_12 ( struct V_28 * V_28 ,
const struct V_1 * V_2 ,
const struct V_32 * V_43 )
{
const struct V_9 * V_44 = F_13 ( V_2 ) ;
struct V_1 * V_45 = NULL ;
int V_29 = 0 ;
T_2 V_46 ( V_26 ) , V_46 ( V_25 ) ;
T_3 V_46 ( V_31 ) , V_46 ( V_30 ) ;
T_1 V_46 ( V_3 ) ;
#ifdef F_14
struct V_47 const * V_48 ;
enum V_49 V_50 ;
#endif
if ( V_44 -> V_3 == V_23 || V_44 -> V_3 == V_22 ) {
struct V_51 V_52 , * V_53 ;
V_53 = F_3 ( V_2 , F_2 ( V_2 ) ,
sizeof( V_52 ) , & V_52 ) ;
if ( V_53 == NULL )
return NULL ;
V_3 = V_44 -> V_3 ;
V_25 = V_44 -> V_25 ;
V_30 = V_53 -> V_54 ;
V_26 = V_44 -> V_26 ;
V_31 = V_53 -> V_55 ;
V_45 = (struct V_1 * ) V_2 ;
V_29 = V_44 -> V_3 == V_22 ?
F_2 ( V_2 ) + F_15 ( (struct V_56 * ) V_53 ) :
F_2 ( V_2 ) + sizeof( * V_53 ) ;
} else if ( V_44 -> V_3 == V_57 ) {
if ( F_1 ( V_2 , & V_3 , & V_25 , & V_26 ,
& V_30 , & V_31 ) )
return NULL ;
} else {
return NULL ;
}
#ifdef F_14
V_48 = F_16 ( V_2 , & V_50 ) ;
if ( V_48 && ! F_17 ( V_48 ) &&
( ( V_44 -> V_3 != V_57 &&
V_50 == V_58 ) ||
( V_44 -> V_3 == V_57 &&
V_50 == V_59 ) ) &&
( V_48 -> V_60 & V_61 ) ) {
V_26 = V_48 -> V_62 [ V_63 ] . V_64 . V_65 . V_66 . V_67 ;
V_31 = ( V_44 -> V_3 == V_22 ) ?
V_48 -> V_62 [ V_63 ] . V_64 . V_65 . V_68 . V_69 . V_70 :
V_48 -> V_62 [ V_63 ] . V_64 . V_65 . V_68 . V_71 . V_70 ;
}
#endif
return F_4 ( V_28 , V_45 , V_29 , V_3 , V_25 ,
V_26 , V_30 , V_31 , V_43 ) ;
}
static bool
F_18 ( const struct V_1 * V_2 , struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_1 * V_76 = (struct V_1 * ) V_2 ;
struct V_27 * V_36 = V_2 -> V_36 ;
if ( ! V_36 )
V_36 = F_12 ( V_73 -> V_28 , V_2 , V_73 -> V_33 ) ;
if ( V_36 ) {
bool V_77 ;
bool V_42 = true ;
V_77 = ( ! ( V_75 -> V_78 & V_79 ) &&
F_19 ( V_36 ) &&
F_11 ( V_36 ) -> V_80 == 0 ) ;
if ( V_75 -> V_78 & V_81 )
V_42 = F_7 ( V_36 ) ;
if ( V_75 -> V_78 & V_82 && ! V_77 &&
V_42 )
V_76 -> V_83 = V_36 -> V_84 ;
if ( V_36 != V_2 -> V_36 )
F_20 ( V_36 ) ;
if ( V_77 || ! V_42 )
V_36 = NULL ;
}
return V_36 != NULL ;
}
static bool
F_21 ( const struct V_1 * V_2 , struct V_72 * V_73 )
{
static struct V_74 V_85 = {
. V_78 = 0 ,
} ;
return F_18 ( V_2 , V_73 , & V_85 ) ;
}
static bool
F_22 ( const struct V_1 * V_2 , struct V_72 * V_73 )
{
return F_18 ( V_2 , V_73 , V_73 -> V_86 ) ;
}
static int
F_23 ( const struct V_1 * V_2 ,
unsigned int V_8 ,
int * V_3 ,
const struct V_87 * * V_4 ,
const struct V_87 * * V_5 ,
T_3 * V_6 ,
T_3 * V_7 ,
struct V_88 * V_89 )
{
const struct V_88 * V_10 ;
struct V_90 * V_13 , V_14 ;
T_3 * V_15 , V_16 [ 2 ] ;
T_1 V_91 ;
T_3 V_92 ;
int V_93 ;
V_13 = F_3 ( V_2 , V_8 ,
sizeof( V_14 ) , & V_14 ) ;
if ( V_13 == NULL )
return 1 ;
if ( V_13 -> V_94 & V_95 )
return 1 ;
V_10 = F_3 ( V_2 , V_8 + sizeof( V_14 ) ,
sizeof( * V_89 ) , V_89 ) ;
if ( V_10 == NULL )
return 1 ;
V_91 = V_10 -> V_96 ;
V_93 = F_24 ( V_2 , V_8 + sizeof( V_14 ) +
sizeof( * V_89 ) ,
& V_91 , & V_92 ) ;
if ( V_93 < 0 )
return 1 ;
if ( V_91 != V_22 &&
V_91 != V_23 )
return 1 ;
V_15 = F_3 ( V_2 , V_93 ,
sizeof( V_16 ) , & V_16 ) ;
if ( V_15 == NULL )
return 1 ;
* V_3 = V_91 ;
* V_5 = & V_10 -> V_25 ;
* V_7 = V_15 [ 0 ] ;
* V_4 = & V_10 -> V_26 ;
* V_6 = V_15 [ 1 ] ;
return 0 ;
}
static struct V_27 *
F_25 ( struct V_28 * V_28 , struct V_1 * V_2 , int V_29 ,
const T_1 V_3 ,
const struct V_87 * V_25 , const struct V_87 * V_26 ,
const T_3 V_30 , const T_3 V_31 ,
const struct V_32 * V_33 )
{
switch ( V_3 ) {
case V_22 :
return F_26 ( V_28 , & V_34 , V_2 , V_29 ,
V_25 , V_30 , V_26 , V_31 ,
V_33 -> V_35 ) ;
case V_23 :
return F_27 ( V_28 , V_25 , V_30 , V_26 , V_31 ,
V_33 -> V_35 ) ;
}
return NULL ;
}
static struct V_27 * F_28 ( struct V_28 * V_28 ,
const struct V_1 * V_2 ,
const struct V_32 * V_43 )
{
T_3 V_46 ( V_31 ) , V_46 ( V_30 ) ;
const struct V_87 * V_26 = NULL , * V_25 = NULL ;
struct V_88 * V_44 = F_29 ( V_2 ) ;
struct V_1 * V_45 = NULL ;
int V_29 = 0 ;
int V_97 = 0 , V_98 ;
V_98 = F_30 ( V_2 , & V_97 , - 1 , NULL , NULL ) ;
if ( V_98 < 0 ) {
F_31 ( L_1 ) ;
return NULL ;
}
if ( V_98 == V_23 || V_98 == V_22 ) {
struct V_51 V_52 , * V_53 ;
V_53 = F_3 ( V_2 , V_97 , sizeof( V_52 ) , & V_52 ) ;
if ( V_53 == NULL )
return NULL ;
V_25 = & V_44 -> V_25 ;
V_30 = V_53 -> V_54 ;
V_26 = & V_44 -> V_26 ;
V_31 = V_53 -> V_55 ;
V_45 = (struct V_1 * ) V_2 ;
V_29 = V_98 == V_22 ?
V_97 + F_15 ( (struct V_56 * ) V_53 ) :
V_97 + sizeof( * V_53 ) ;
} else if ( V_98 == V_99 ) {
struct V_88 V_89 ;
if ( F_23 ( V_2 , V_97 , & V_98 , & V_25 , & V_26 ,
& V_30 , & V_31 , & V_89 ) )
return NULL ;
} else {
return NULL ;
}
return F_25 ( V_28 , V_45 , V_29 , V_98 , V_25 , V_26 ,
V_30 , V_31 , V_43 ) ;
}
static bool
F_32 ( const struct V_1 * V_2 , struct V_72 * V_73 )
{
const struct V_74 * V_75 = (struct V_74 * ) V_73 -> V_86 ;
struct V_1 * V_76 = (struct V_1 * ) V_2 ;
struct V_27 * V_36 = V_2 -> V_36 ;
if ( ! V_36 )
V_36 = F_28 ( V_73 -> V_28 , V_2 , V_73 -> V_33 ) ;
if ( V_36 ) {
bool V_77 ;
bool V_42 = true ;
V_77 = ( ! ( V_75 -> V_78 & V_79 ) &&
F_19 ( V_36 ) &&
F_33 ( & V_36 -> V_100 ) ) ;
if ( V_75 -> V_78 & V_81 )
V_42 = F_7 ( V_36 ) ;
if ( V_75 -> V_78 & V_82 && ! V_77 &&
V_42 )
V_76 -> V_83 = V_36 -> V_84 ;
if ( V_36 != V_2 -> V_36 )
F_20 ( V_36 ) ;
if ( V_77 || ! V_42 )
V_36 = NULL ;
}
return V_36 != NULL ;
}
static int F_34 ( const struct V_101 * V_73 )
{
const struct V_74 * V_75 = (struct V_74 * ) V_73 -> V_86 ;
if ( V_75 -> V_78 & ~ V_102 ) {
F_35 ( L_2 , V_75 -> V_78 & ~ V_102 ) ;
return - V_103 ;
}
return 0 ;
}
static int F_36 ( const struct V_101 * V_73 )
{
const struct V_104 * V_75 = (struct V_104 * ) V_73 -> V_86 ;
if ( V_75 -> V_78 & ~ V_105 ) {
F_35 ( L_2 , V_75 -> V_78 & ~ V_105 ) ;
return - V_103 ;
}
return 0 ;
}
static int F_37 ( const struct V_101 * V_73 )
{
const struct V_106 * V_75 =
(struct V_106 * ) V_73 -> V_86 ;
if ( V_75 -> V_78 & ~ V_107 ) {
F_35 ( L_2 ,
V_75 -> V_78 & ~ V_107 ) ;
return - V_103 ;
}
return 0 ;
}
static int T_4 F_38 ( void )
{
F_39 () ;
#ifdef F_40
F_41 () ;
#endif
return F_42 ( V_108 , F_43 ( V_108 ) ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( V_108 , F_43 ( V_108 ) ) ;
}
