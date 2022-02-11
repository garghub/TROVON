static int
F_1 ( const struct V_1 * V_2 , T_1 * V_3 ,
T_2 * V_4 , T_2 * V_5 ,
T_3 * V_6 , T_3 * V_7 )
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
struct V_27 * F_7 ( struct V_28 * V_28 , const struct V_1 * V_2 ,
const struct V_32 * V_36 )
{
T_2 V_37 ( V_26 ) , V_37 ( V_25 ) ;
T_3 V_37 ( V_31 ) , V_37 ( V_30 ) ;
const struct V_9 * V_38 = F_8 ( V_2 ) ;
struct V_1 * V_39 = NULL ;
T_1 V_37 ( V_3 ) ;
#if F_9 ( V_40 )
enum V_41 V_42 ;
struct V_43 const * V_44 ;
#endif
int V_29 = 0 ;
if ( V_38 -> V_3 == V_23 || V_38 -> V_3 == V_22 ) {
struct V_45 V_46 , * V_47 ;
V_47 = F_3 ( V_2 , F_2 ( V_2 ) ,
sizeof( V_46 ) , & V_46 ) ;
if ( V_47 == NULL )
return NULL ;
V_3 = V_38 -> V_3 ;
V_25 = V_38 -> V_25 ;
V_30 = V_47 -> V_48 ;
V_26 = V_38 -> V_26 ;
V_31 = V_47 -> V_49 ;
V_39 = (struct V_1 * ) V_2 ;
V_29 = V_38 -> V_3 == V_22 ?
F_2 ( V_2 ) + F_10 ( (struct V_50 * ) V_47 ) :
F_2 ( V_2 ) + sizeof( * V_47 ) ;
} else if ( V_38 -> V_3 == V_51 ) {
if ( F_1 ( V_2 , & V_3 , & V_25 , & V_26 ,
& V_30 , & V_31 ) )
return NULL ;
} else {
return NULL ;
}
#if F_9 ( V_40 )
V_44 = F_11 ( V_2 , & V_42 ) ;
if ( V_44 &&
( ( V_38 -> V_3 != V_51 &&
V_42 == V_52 ) ||
( V_38 -> V_3 == V_51 &&
V_42 == V_53 ) ) &&
( V_44 -> V_54 & V_55 ) ) {
V_26 = V_44 -> V_56 [ V_57 ] . V_58 . V_59 . V_60 . V_61 ;
V_31 = ( V_38 -> V_3 == V_22 ) ?
V_44 -> V_56 [ V_57 ] . V_58 . V_59 . V_62 . V_63 . V_64 :
V_44 -> V_56 [ V_57 ] . V_58 . V_59 . V_62 . V_65 . V_64 ;
}
#endif
return F_4 ( V_28 , V_39 , V_29 , V_3 , V_25 ,
V_26 , V_30 , V_31 , V_36 ) ;
}
