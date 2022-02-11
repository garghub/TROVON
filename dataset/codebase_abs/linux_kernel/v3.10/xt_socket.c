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
T_2 V_39 ( V_30 ) , V_39 ( V_29 ) ;
T_3 V_39 ( V_40 ) , V_39 ( V_41 ) ;
T_1 V_39 ( V_7 ) ;
#ifdef F_10
struct V_42 const * V_43 ;
enum V_44 V_45 ;
#endif
if ( V_35 -> V_7 == V_27 || V_35 -> V_7 == V_26 ) {
V_38 = F_7 ( V_6 , F_6 ( V_6 ) ,
sizeof( V_37 ) , & V_37 ) ;
if ( V_38 == NULL )
return false ;
V_7 = V_35 -> V_7 ;
V_29 = V_35 -> V_29 ;
V_41 = V_38 -> V_46 ;
V_30 = V_35 -> V_30 ;
V_40 = V_38 -> V_47 ;
} else if ( V_35 -> V_7 == V_48 ) {
if ( F_5 ( V_6 , & V_7 , & V_29 , & V_30 ,
& V_41 , & V_40 ) )
return false ;
} else {
return false ;
}
#ifdef F_10
V_43 = F_11 ( V_6 , & V_45 ) ;
if ( V_43 && ! F_12 ( V_43 ) &&
( ( V_35 -> V_7 != V_48 &&
V_45 == V_49 ) ||
( V_35 -> V_7 == V_48 &&
V_45 == V_50 ) ) &&
( V_43 -> V_51 & V_52 ) ) {
V_30 = V_43 -> V_53 [ V_54 ] . V_55 . V_56 . V_57 . V_58 ;
V_40 = ( V_35 -> V_7 == V_26 ) ?
V_43 -> V_53 [ V_54 ] . V_55 . V_56 . V_59 . V_60 . V_61 :
V_43 -> V_53 [ V_54 ] . V_55 . V_56 . V_59 . V_62 . V_61 ;
}
#endif
V_2 = F_13 ( F_14 ( V_6 -> V_63 ) , V_7 ,
V_29 , V_30 , V_41 , V_40 , V_32 -> V_64 , V_65 ) ;
if ( V_2 != NULL ) {
bool V_66 ;
bool V_67 = true ;
V_66 = ( V_2 -> V_3 != V_4 &&
F_15 ( V_2 ) -> V_68 == 0 ) ;
if ( V_34 && V_34 -> V_69 & V_70 )
V_67 = ( ( V_2 -> V_3 != V_4 &&
F_15 ( V_2 ) -> V_67 ) ||
( V_2 -> V_3 == V_4 &&
F_3 ( V_2 ) -> V_71 ) ) ;
F_1 ( V_2 ) ;
if ( V_66 || ! V_67 )
V_2 = NULL ;
}
F_16 ( L_1 ,
V_7 , & V_29 , F_17 ( V_41 ) ,
& V_30 , F_17 ( V_40 ) ,
& V_35 -> V_30 , V_38 ? F_17 ( V_38 -> V_47 ) : 0 , V_2 ) ;
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
return F_8 ( V_6 , V_32 , V_32 -> V_72 ) ;
}
static int
F_20 ( const struct V_5 * V_6 ,
unsigned int V_12 ,
int * V_7 ,
struct V_73 * * V_8 ,
struct V_73 * * V_9 ,
T_3 * V_10 ,
T_3 * V_11 )
{
struct V_74 * V_14 , V_15 ;
struct V_75 * V_17 , V_18 ;
T_3 * V_19 , V_20 [ 2 ] ;
T_1 V_76 ;
T_3 V_77 ;
int V_78 ;
V_17 = F_7 ( V_6 , V_12 ,
sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL )
return 1 ;
if ( V_17 -> V_79 & V_80 )
return 1 ;
V_14 = F_7 ( V_6 , V_12 + sizeof( V_18 ) , sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL )
return 1 ;
V_76 = V_14 -> V_81 ;
V_78 = F_21 ( V_6 , V_12 + sizeof( V_18 ) + sizeof( V_15 ) ,
& V_76 , & V_77 ) ;
if ( V_78 < 0 )
return 1 ;
if ( V_76 != V_26 &&
V_76 != V_27 )
return 1 ;
V_19 = F_7 ( V_6 , V_78 ,
sizeof( V_20 ) , & V_20 ) ;
if ( V_19 == NULL )
return 1 ;
* V_7 = V_76 ;
* V_9 = & V_14 -> V_29 ;
* V_11 = V_19 [ 0 ] ;
* V_8 = & V_14 -> V_30 ;
* V_10 = V_19 [ 1 ] ;
return 0 ;
}
static bool
F_22 ( const struct V_5 * V_6 , struct V_31 * V_32 )
{
struct V_74 * V_35 = F_23 ( V_6 ) ;
struct V_36 V_37 , * V_38 = NULL ;
struct V_1 * V_2 ;
struct V_73 * V_30 = NULL , * V_29 = NULL ;
T_3 V_39 ( V_40 ) , V_39 ( V_41 ) ;
int V_82 = 0 , V_39 ( V_83 ) ;
const struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_72 ;
V_83 = F_24 ( V_6 , & V_82 , - 1 , NULL , NULL ) ;
if ( V_83 < 0 ) {
F_16 ( L_2 ) ;
return V_84 ;
}
if ( V_83 == V_27 || V_83 == V_26 ) {
V_38 = F_7 ( V_6 , V_82 ,
sizeof( V_37 ) , & V_37 ) ;
if ( V_38 == NULL )
return false ;
V_29 = & V_35 -> V_29 ;
V_41 = V_38 -> V_46 ;
V_30 = & V_35 -> V_30 ;
V_40 = V_38 -> V_47 ;
} else if ( V_83 == V_85 ) {
if ( F_20 ( V_6 , V_82 , & V_83 , & V_29 , & V_30 ,
& V_41 , & V_40 ) )
return false ;
} else {
return false ;
}
V_2 = F_25 ( F_14 ( V_6 -> V_63 ) , V_83 ,
V_29 , V_30 , V_41 , V_40 , V_32 -> V_64 , V_65 ) ;
if ( V_2 != NULL ) {
bool V_66 ;
bool V_67 = true ;
V_66 = ( V_2 -> V_3 != V_4 &&
F_26 ( & F_27 ( V_2 ) -> V_86 ) ) ;
if ( V_34 && V_34 -> V_69 & V_70 )
V_67 = ( ( V_2 -> V_3 != V_4 &&
F_15 ( V_2 ) -> V_67 ) ||
( V_2 -> V_3 == V_4 &&
F_3 ( V_2 ) -> V_71 ) ) ;
F_1 ( V_2 ) ;
if ( V_66 || ! V_67 )
V_2 = NULL ;
}
F_16 ( L_3
L_4 ,
V_83 , V_29 , F_17 ( V_41 ) ,
V_30 , F_17 ( V_40 ) ,
& V_35 -> V_30 , V_38 ? F_17 ( V_38 -> V_47 ) : 0 , V_2 ) ;
return ( V_2 != NULL ) ;
}
static int T_4 F_28 ( void )
{
F_29 () ;
#ifdef F_30
F_31 () ;
#endif
return F_32 ( V_87 , F_33 ( V_87 ) ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( V_87 , F_33 ( V_87 ) ) ;
}
