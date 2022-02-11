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
* V_6 ++ = F_2 ( F_3 ( & V_15 , V_5 -> V_16 ) ) ;
break;
case V_17 :
* V_6 ++ = F_2 ( F_4 ( & V_15 , V_5 -> V_18 ) ) ;
break;
case V_19 :
* V_6 ++ = F_2 ( F_3 ( & V_15 , V_8 -> V_20 ) ) ;
break;
case V_21 :
* V_6 ++ = F_2 ( F_4 ( & V_15 , V_8 -> V_22 ) ) ;
break;
default:
* V_6 ++ = 0 ;
break;
}
* V_6 ++ = F_2 ( V_8 -> V_23 & V_24 ) ;
return 0 ;
}
int F_5 ( struct V_25 * V_26 , unsigned int V_27 , struct V_28 * V_28 ,
struct V_29 * V_9 , int V_30 , int V_13 )
{
int V_31 = ( V_9 && V_9 -> V_32 ) ? F_6 ( int , V_9 -> V_32 , 4 ) : 0 ;
struct V_4 V_5 = {
. V_2 = {
. V_33 = 12 ,
. V_34 = V_30 ? V_31 : 0 ,
. V_35 = F_1 ,
} ,
. V_9 = V_9 ,
. V_13 = V_13 ,
. V_16 = V_28 -> V_36 ,
. V_18 = V_28 -> V_37 ,
} ;
struct V_38 V_39 ;
int V_40 ;
if ( V_31 > V_41 ||
F_7 ( V_26 , V_27 , V_31 ) )
return - V_42 ;
if ( V_30 && V_9 && V_9 -> V_32 == 3 ) {
struct V_29 * V_43 = & V_39 . V_9 ;
F_8 ( V_43 , 4 ) ;
V_43 -> V_10 [ 0 ] = V_9 -> V_10 [ 0 ] ;
V_43 -> V_10 [ 1 ] = V_9 -> V_10 [ 1 ] ;
V_43 -> V_10 [ 2 ] = V_9 -> V_10 [ 1 ] ;
V_43 -> V_10 [ 2 ] . V_12 = V_44 ;
V_43 -> V_10 [ 3 ] = V_9 -> V_10 [ 2 ] ;
V_5 . V_9 = V_43 ;
}
V_40 = F_9 ( V_26 , V_27 + 4 , & V_5 . V_2 ) ;
if ( ! V_40 )
V_40 = 8 + V_5 . V_2 . V_33 *
V_5 . V_2 . V_34 ;
return V_40 ;
}
static int
F_10 ( struct V_1 * V_2 , void * V_3 )
{
struct V_45 * V_5 =
(struct V_45 * ) V_2 ;
T_1 * V_6 = V_3 ;
struct V_7 * V_8 ;
unsigned int V_46 ;
if ( ! V_5 -> V_9 ) {
if ( V_2 -> V_34 > V_41 )
return - V_42 ;
V_5 -> V_9 = F_11 ( V_2 -> V_34 , V_47 ) ;
if ( ! V_5 -> V_9 )
return - V_48 ;
V_5 -> V_11 = 0 ;
}
V_8 = & V_5 -> V_9 -> V_10 [ V_5 -> V_11 ++ ] ;
V_8 -> V_12 = F_12 ( * V_6 ++ ) & ~ V_49 ;
V_46 = F_12 ( * V_6 ++ ) ;
V_8 -> V_23 = F_12 ( * V_6 ++ ) ;
switch( V_8 -> V_12 ) {
case V_19 :
V_8 -> V_20 = F_13 ( & V_15 , V_46 ) ;
if ( ! F_14 ( V_8 -> V_20 ) )
return - V_42 ;
break;
case V_21 :
V_8 -> V_22 = F_15 ( & V_15 , V_46 ) ;
if ( ! F_16 ( V_8 -> V_22 ) )
return - V_42 ;
break;
case V_14 :
case V_17 :
case V_50 :
if ( V_8 -> V_23 & ~ V_24 )
return - V_42 ;
break;
case V_44 :
V_8 -> V_23 &= V_24 ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int
F_17 ( const void * V_51 , const void * V_52 )
{
const struct V_7 * V_53 = V_51 , * V_54 = V_52 ;
if ( V_53 -> V_12 != V_54 -> V_12 )
return V_53 -> V_12 - V_54 -> V_12 ;
else if ( ( V_53 -> V_12 == V_19 ) && F_18 ( V_53 -> V_20 , V_54 -> V_20 ) )
return 1 ;
else if ( ( V_53 -> V_12 == V_19 ) && F_19 ( V_53 -> V_20 , V_54 -> V_20 ) )
return - 1 ;
else if ( ( V_53 -> V_12 == V_21 ) && F_20 ( V_53 -> V_22 , V_54 -> V_22 ) )
return 1 ;
else if ( ( V_53 -> V_12 == V_21 ) && F_21 ( V_53 -> V_22 , V_54 -> V_22 ) )
return - 1 ;
else
return 0 ;
}
static int
F_22 ( struct V_29 * V_9 )
{
struct V_7 * V_55 , * V_56 ,
* V_57 = NULL , * V_58 = NULL ;
if ( ! V_9 )
return 0 ;
F_23 ( V_9 -> V_10 , V_9 -> V_32 , sizeof( struct V_7 ) ,
F_17 , NULL ) ;
F_24 (pa, acl, pe) {
switch( V_55 -> V_12 ) {
case V_14 :
break;
case V_17 :
V_57 = V_55 ;
break;
case V_44 :
V_58 = V_55 ;
case V_50 :
break;
}
}
if ( V_9 -> V_32 == 4 && V_57 && V_58 &&
V_58 -> V_23 == V_57 -> V_23 ) {
memmove ( V_58 , V_58 + 1 , ( 3 - ( V_58 - V_9 -> V_10 ) ) *
sizeof( struct V_7 ) ) ;
V_9 -> V_32 = 3 ;
}
return 0 ;
}
int F_25 ( struct V_25 * V_26 , unsigned int V_27 , unsigned int * V_59 ,
struct V_29 * * V_60 )
{
struct V_45 V_5 = {
. V_2 = {
. V_33 = 12 ,
. V_35 = V_60 ? F_10 : NULL ,
} ,
} ;
T_2 V_31 ;
int V_40 ;
if ( F_26 ( V_26 , V_27 , & V_31 ) ||
V_31 > V_41 )
return - V_42 ;
V_5 . V_2 . V_61 = V_31 ;
V_40 = F_27 ( V_26 , V_27 + 4 , & V_5 . V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_60 ) {
if ( V_31 != V_5 . V_2 . V_34 ||
F_22 ( V_5 . V_9 ) != 0 ) {
F_28 ( V_5 . V_9 ) ;
return - V_42 ;
}
* V_60 = V_5 . V_9 ;
}
if ( V_59 )
* V_59 = V_31 ;
return 8 + V_5 . V_2 . V_33 *
V_5 . V_2 . V_34 ;
}
