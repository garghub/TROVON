static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 =
(struct V_4 * ) V_2 ;
T_1 * V_6 = V_3 ;
struct V_7 * V_8 =
& V_5 -> V_9 -> V_10 [ V_5 -> V_11 ++ ] ;
* V_6 ++ = F_2 ( V_8 -> V_12 | V_5 -> V_13 ) ;
switch( V_8 -> V_12 ) {
case V_14 :
* V_6 ++ = F_2 ( V_5 -> V_15 ) ;
break;
case V_16 :
* V_6 ++ = F_2 ( V_5 -> V_17 ) ;
break;
case V_18 :
case V_19 :
* V_6 ++ = F_2 ( V_8 -> V_20 ) ;
break;
default:
* V_6 ++ = 0 ;
break;
}
* V_6 ++ = F_2 ( V_8 -> V_21 & V_22 ) ;
return 0 ;
}
int F_3 ( struct V_23 * V_24 , unsigned int V_25 , struct V_26 * V_26 ,
struct V_27 * V_9 , int V_28 , int V_13 )
{
int V_29 = ( V_9 && V_9 -> V_30 ) ? F_4 ( int , V_9 -> V_30 , 4 ) : 0 ;
struct V_4 V_5 = {
. V_2 = {
. V_31 = 12 ,
. V_32 = V_28 ? V_29 : 0 ,
. V_33 = F_1 ,
} ,
. V_9 = V_9 ,
. V_13 = V_13 ,
. V_15 = V_26 -> V_34 ,
. V_17 = V_26 -> V_35 ,
} ;
struct V_36 V_37 ;
int V_38 ;
if ( V_29 > V_39 ||
F_5 ( V_24 , V_25 , V_29 ) )
return - V_40 ;
if ( V_28 && V_9 && V_9 -> V_30 == 3 ) {
struct V_27 * V_41 = & V_37 . V_9 ;
F_6 ( V_41 , 4 ) ;
V_41 -> V_10 [ 0 ] = V_9 -> V_10 [ 0 ] ;
V_41 -> V_10 [ 1 ] = V_9 -> V_10 [ 1 ] ;
V_41 -> V_10 [ 2 ] = V_9 -> V_10 [ 1 ] ;
V_41 -> V_10 [ 2 ] . V_12 = V_42 ;
V_41 -> V_10 [ 3 ] = V_9 -> V_10 [ 2 ] ;
V_5 . V_9 = V_41 ;
}
V_38 = F_7 ( V_24 , V_25 + 4 , & V_5 . V_2 ) ;
if ( ! V_38 )
V_38 = 8 + V_5 . V_2 . V_31 *
V_5 . V_2 . V_32 ;
return V_38 ;
}
static int
F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_43 * V_5 =
(struct V_43 * ) V_2 ;
T_1 * V_6 = V_3 ;
struct V_7 * V_8 ;
if ( ! V_5 -> V_9 ) {
if ( V_2 -> V_32 > V_39 )
return - V_40 ;
V_5 -> V_9 = F_9 ( V_2 -> V_32 , V_44 ) ;
if ( ! V_5 -> V_9 )
return - V_45 ;
V_5 -> V_11 = 0 ;
}
V_8 = & V_5 -> V_9 -> V_10 [ V_5 -> V_11 ++ ] ;
V_8 -> V_12 = F_10 ( * V_6 ++ ) & ~ V_46 ;
V_8 -> V_20 = F_10 ( * V_6 ++ ) ;
V_8 -> V_21 = F_10 ( * V_6 ++ ) ;
switch( V_8 -> V_12 ) {
case V_14 :
case V_18 :
case V_16 :
case V_19 :
case V_47 :
if ( V_8 -> V_21 & ~ V_22 )
return - V_40 ;
break;
case V_42 :
V_8 -> V_21 &= V_22 ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static int
F_11 ( const void * V_48 , const void * V_49 )
{
const struct V_7 * V_50 = V_48 , * V_51 = V_49 ;
if ( V_50 -> V_12 != V_51 -> V_12 )
return V_50 -> V_12 - V_51 -> V_12 ;
else if ( V_50 -> V_20 > V_51 -> V_20 )
return 1 ;
else if ( V_50 -> V_20 < V_51 -> V_20 )
return - 1 ;
else
return 0 ;
}
static int
F_12 ( struct V_27 * V_9 )
{
struct V_7 * V_52 , * V_53 ,
* V_54 = NULL , * V_55 = NULL ;
if ( ! V_9 )
return 0 ;
F_13 ( V_9 -> V_10 , V_9 -> V_30 , sizeof( struct V_7 ) ,
F_11 , NULL ) ;
F_14 (pa, acl, pe) {
switch( V_52 -> V_12 ) {
case V_14 :
V_52 -> V_20 = V_56 ;
break;
case V_16 :
V_52 -> V_20 = V_56 ;
V_54 = V_52 ;
break;
case V_42 :
V_55 = V_52 ;
case V_47 :
V_52 -> V_20 = V_56 ;
break;
}
}
if ( V_9 -> V_30 == 4 && V_54 && V_55 &&
V_55 -> V_21 == V_54 -> V_21 ) {
memmove ( V_55 , V_55 + 1 , ( 3 - ( V_55 - V_9 -> V_10 ) ) *
sizeof( struct V_7 ) ) ;
V_9 -> V_30 = 3 ;
}
return 0 ;
}
int F_15 ( struct V_23 * V_24 , unsigned int V_25 , unsigned int * V_57 ,
struct V_27 * * V_58 )
{
struct V_43 V_5 = {
. V_2 = {
. V_31 = 12 ,
. V_33 = V_58 ? F_8 : NULL ,
} ,
} ;
T_2 V_29 ;
int V_38 ;
if ( F_16 ( V_24 , V_25 , & V_29 ) ||
V_29 > V_39 )
return - V_40 ;
V_5 . V_2 . V_59 = V_29 ;
V_38 = F_17 ( V_24 , V_25 + 4 , & V_5 . V_2 ) ;
if ( V_38 )
return V_38 ;
if ( V_58 ) {
if ( V_29 != V_5 . V_2 . V_32 ||
F_12 ( V_5 . V_9 ) != 0 ) {
F_18 ( V_5 . V_9 ) ;
return - V_40 ;
}
* V_58 = V_5 . V_9 ;
}
if ( V_57 )
* V_57 = V_29 ;
return 8 + V_5 . V_2 . V_31 *
V_5 . V_2 . V_32 ;
}
