static int
F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 ,
int * V_4 ,
const struct V_5 * * V_6 ,
const struct V_5 * * V_7 ,
T_1 * V_8 ,
T_1 * V_9 ,
struct V_10 * V_11 )
{
const struct V_10 * V_12 ;
struct V_13 * V_14 , V_15 ;
T_1 * V_16 , V_17 [ 2 ] ;
T_2 V_18 ;
T_1 V_19 ;
int V_20 ;
V_14 = F_2 ( V_2 , V_3 ,
sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL )
return 1 ;
if ( V_14 -> V_21 & V_22 )
return 1 ;
V_12 = F_2 ( V_2 , V_3 + sizeof( V_15 ) ,
sizeof( * V_11 ) , V_11 ) ;
if ( V_12 == NULL )
return 1 ;
V_18 = V_12 -> V_23 ;
V_20 = F_3 ( V_2 , V_3 + sizeof( V_15 ) +
sizeof( * V_11 ) ,
& V_18 , & V_19 ) ;
if ( V_20 < 0 )
return 1 ;
if ( V_18 != V_24 &&
V_18 != V_25 )
return 1 ;
V_16 = F_2 ( V_2 , V_20 ,
sizeof( V_17 ) , & V_17 ) ;
if ( V_16 == NULL )
return 1 ;
* V_4 = V_18 ;
* V_7 = & V_12 -> V_26 ;
* V_9 = V_16 [ 0 ] ;
* V_6 = & V_12 -> V_27 ;
* V_8 = V_16 [ 1 ] ;
return 0 ;
}
static struct V_28 *
F_4 ( struct V_29 * V_29 , struct V_1 * V_2 , int V_30 ,
const T_2 V_4 ,
const struct V_5 * V_26 , const struct V_5 * V_27 ,
const T_1 V_31 , const T_1 V_32 ,
const struct V_33 * V_34 )
{
switch ( V_4 ) {
case V_24 :
return F_5 ( V_29 , & V_35 , V_2 , V_30 ,
V_26 , V_31 , V_27 , V_32 ,
V_34 -> V_36 ) ;
case V_25 :
return F_6 ( V_29 , V_26 , V_31 , V_27 , V_32 ,
V_34 -> V_36 ) ;
}
return NULL ;
}
struct V_28 * F_7 ( struct V_29 * V_29 , const struct V_1 * V_2 ,
const struct V_33 * V_37 )
{
T_1 V_38 ( V_32 ) , V_38 ( V_31 ) ;
const struct V_5 * V_27 = NULL , * V_26 = NULL ;
struct V_10 * V_39 = F_8 ( V_2 ) ;
struct V_1 * V_40 = NULL ;
int V_30 = 0 ;
int V_41 = 0 , V_42 ;
V_42 = F_9 ( V_2 , & V_41 , - 1 , NULL , NULL ) ;
if ( V_42 < 0 ) {
F_10 ( L_1 ) ;
return NULL ;
}
if ( V_42 == V_25 || V_42 == V_24 ) {
struct V_43 V_44 , * V_45 ;
V_45 = F_2 ( V_2 , V_41 , sizeof( V_44 ) , & V_44 ) ;
if ( V_45 == NULL )
return NULL ;
V_26 = & V_39 -> V_26 ;
V_31 = V_45 -> V_46 ;
V_27 = & V_39 -> V_27 ;
V_32 = V_45 -> V_47 ;
V_40 = (struct V_1 * ) V_2 ;
V_30 = V_42 == V_24 ?
V_41 + F_11 ( (struct V_48 * ) V_45 ) :
V_41 + sizeof( * V_45 ) ;
} else if ( V_42 == V_49 ) {
struct V_10 V_11 ;
if ( F_1 ( V_2 , V_41 , & V_42 , & V_26 , & V_27 ,
& V_31 , & V_32 , & V_11 ) )
return NULL ;
} else {
return NULL ;
}
return F_4 ( V_29 , V_40 , V_30 , V_42 , V_26 , V_27 ,
V_31 , V_32 , V_37 ) ;
}
