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
static bool
F_8 ( const struct V_5 * V_6 , struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
const struct V_13 * V_35 = F_9 ( V_6 ) ;
struct V_36 V_37 , * V_38 = NULL ;
struct V_1 * V_2 ;
T_2 V_30 , V_29 ;
T_3 V_39 , V_40 ;
T_1 V_7 ;
#ifdef F_10
struct V_41 const * V_42 ;
enum V_43 V_44 ;
#endif
if ( V_35 -> V_7 == V_27 || V_35 -> V_7 == V_26 ) {
V_38 = F_7 ( V_6 , F_6 ( V_6 ) ,
sizeof( V_37 ) , & V_37 ) ;
if ( V_38 == NULL )
return false ;
V_7 = V_35 -> V_7 ;
V_29 = V_35 -> V_29 ;
V_40 = V_38 -> V_45 ;
V_30 = V_35 -> V_30 ;
V_39 = V_38 -> V_46 ;
} else if ( V_35 -> V_7 == V_47 ) {
if ( F_5 ( V_6 , & V_7 , & V_29 , & V_30 ,
& V_40 , & V_39 ) )
return false ;
} else {
return false ;
}
#ifdef F_10
V_42 = F_11 ( V_6 , & V_44 ) ;
if ( V_42 && ! F_12 ( V_42 ) &&
( ( V_35 -> V_7 != V_47 &&
V_44 == V_48 ) ||
( V_35 -> V_7 == V_47 &&
V_44 == V_49 ) ) &&
( V_42 -> V_50 & V_51 ) ) {
V_30 = V_42 -> V_52 [ V_53 ] . V_54 . V_55 . V_56 . V_57 ;
V_39 = ( V_35 -> V_7 == V_26 ) ?
V_42 -> V_52 [ V_53 ] . V_54 . V_55 . V_58 . V_59 . V_60 :
V_42 -> V_52 [ V_53 ] . V_54 . V_55 . V_58 . V_61 . V_60 ;
}
#endif
V_2 = F_13 ( F_14 ( V_6 -> V_62 ) , V_7 ,
V_29 , V_30 , V_40 , V_39 , V_32 -> V_63 , V_64 ) ;
if ( V_2 != NULL ) {
bool V_65 ;
bool V_66 = true ;
V_65 = ( V_2 -> V_3 != V_4 &&
F_15 ( V_2 ) -> V_67 == 0 ) ;
if ( V_34 && V_34 -> V_68 & V_69 )
V_66 = ( ( V_2 -> V_3 != V_4 &&
F_15 ( V_2 ) -> V_66 ) ||
( V_2 -> V_3 == V_4 &&
F_3 ( V_2 ) -> V_70 ) ) ;
F_1 ( V_2 ) ;
if ( V_65 || ! V_66 )
V_2 = NULL ;
}
F_16 ( L_1 ,
V_7 , & V_29 , F_17 ( V_40 ) ,
& V_30 , F_17 ( V_39 ) ,
& V_35 -> V_30 , V_38 ? F_17 ( V_38 -> V_46 ) : 0 , V_2 ) ;
return ( V_2 != NULL ) ;
}
static bool
F_18 ( const struct V_5 * V_6 , struct V_31 * V_32 )
{
return F_8 ( V_6 , V_32 , NULL ) ;
}
static bool
F_19 ( const struct V_5 * V_6 , struct V_31 * V_32 )
{
return F_8 ( V_6 , V_32 , V_32 -> V_71 ) ;
}
static int
F_20 ( const struct V_5 * V_6 ,
unsigned int V_12 ,
int * V_7 ,
struct V_72 * * V_8 ,
struct V_72 * * V_9 ,
T_3 * V_10 ,
T_3 * V_11 )
{
struct V_73 * V_14 , V_15 ;
struct V_74 * V_17 , V_18 ;
T_3 * V_19 , V_20 [ 2 ] ;
T_1 V_75 ;
T_3 V_76 ;
int V_77 ;
V_17 = F_7 ( V_6 , V_12 ,
sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL )
return 1 ;
if ( V_17 -> V_78 & V_79 )
return 1 ;
V_14 = F_7 ( V_6 , V_12 + sizeof( V_18 ) , sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL )
return 1 ;
V_75 = V_14 -> V_80 ;
V_77 = F_21 ( V_6 , V_12 + sizeof( V_18 ) + sizeof( V_15 ) ,
& V_75 , & V_76 ) ;
if ( V_77 < 0 )
return 1 ;
if ( V_75 != V_26 &&
V_75 != V_27 )
return 1 ;
V_19 = F_7 ( V_6 , V_77 ,
sizeof( V_20 ) , & V_20 ) ;
if ( V_19 == NULL )
return 1 ;
* V_7 = V_75 ;
* V_9 = & V_14 -> V_29 ;
* V_11 = V_19 [ 0 ] ;
* V_8 = & V_14 -> V_30 ;
* V_10 = V_19 [ 1 ] ;
return 0 ;
}
static bool
F_22 ( const struct V_5 * V_6 , struct V_31 * V_32 )
{
struct V_73 * V_35 = F_23 ( V_6 ) ;
struct V_36 V_37 , * V_38 = NULL ;
struct V_1 * V_2 ;
struct V_72 * V_30 , * V_29 ;
T_3 V_39 , V_40 ;
int V_81 = 0 , V_82 ;
const struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_71 ;
V_82 = F_24 ( V_6 , & V_81 , - 1 , NULL , NULL ) ;
if ( V_82 < 0 ) {
F_16 ( L_2 ) ;
return V_83 ;
}
if ( V_82 == V_27 || V_82 == V_26 ) {
V_38 = F_7 ( V_6 , V_81 ,
sizeof( V_37 ) , & V_37 ) ;
if ( V_38 == NULL )
return false ;
V_29 = & V_35 -> V_29 ;
V_40 = V_38 -> V_45 ;
V_30 = & V_35 -> V_30 ;
V_39 = V_38 -> V_46 ;
} else if ( V_82 == V_84 ) {
if ( F_20 ( V_6 , V_81 , & V_82 , & V_29 , & V_30 ,
& V_40 , & V_39 ) )
return false ;
} else {
return false ;
}
V_2 = F_25 ( F_14 ( V_6 -> V_62 ) , V_82 ,
V_29 , V_30 , V_40 , V_39 , V_32 -> V_63 , V_64 ) ;
if ( V_2 != NULL ) {
bool V_65 ;
bool V_66 = true ;
V_65 = ( V_2 -> V_3 != V_4 &&
F_26 ( & F_27 ( V_2 ) -> V_85 ) ) ;
if ( V_34 && V_34 -> V_68 & V_69 )
V_66 = ( ( V_2 -> V_3 != V_4 &&
F_15 ( V_2 ) -> V_66 ) ||
( V_2 -> V_3 == V_4 &&
F_3 ( V_2 ) -> V_70 ) ) ;
F_1 ( V_2 ) ;
if ( V_65 || ! V_66 )
V_2 = NULL ;
}
F_16 ( L_3
L_4 ,
V_82 , V_29 , F_17 ( V_40 ) ,
V_30 , F_17 ( V_39 ) ,
& V_35 -> V_30 , V_38 ? F_17 ( V_38 -> V_46 ) : 0 , V_2 ) ;
return ( V_2 != NULL ) ;
}
static int T_4 F_28 ( void )
{
F_29 () ;
#ifdef F_30
F_31 () ;
#endif
return F_32 ( V_86 , F_33 ( V_86 ) ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( V_86 , F_33 ( V_86 ) ) ;
}
