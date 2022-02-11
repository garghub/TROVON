static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 = F_3 ( V_7 ) ;
memset ( V_5 , 0 , V_8 * sizeof( T_1 ) ) ;
F_4 ( V_7 , V_4 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 = F_3 ( V_7 ) ;
return V_8 * sizeof( T_1 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( V_7 , V_10 ) ;
V_10 -> V_11 . V_12 = F_10 ( V_2 ) ?
F_11 ( V_7 ) : 0U ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 ,
const struct V_9 * V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_13 ( V_7 , V_10 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_13 * V_14 , T_2 * V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_15 ( V_16 > 8 ) ;
memset ( V_15 , 0 , F_16 ( V_17 ) * sizeof( T_2 ) ) ;
F_17 ( V_7 , V_15 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_19 ( V_7 ) ;
struct V_22 * V_23 = F_20 ( V_2 -> V_24 . V_25 ) ;
T_1 V_26 = F_21 ( V_7 ) ;
T_1 V_8 = F_3 ( V_7 ) ;
F_22 ( V_19 -> V_27 , V_28 , sizeof( V_19 -> V_27 ) ) ;
F_22 ( V_19 -> V_29 , V_30 , sizeof( V_19 -> V_29 ) ) ;
snprintf ( V_19 -> V_31 , sizeof( V_19 -> V_31 ) ,
L_1 , V_26 >> 24 ,
( V_26 >> 16 ) & 0xFFU , V_26 & 0xFFFFU ) ;
F_23 ( V_19 -> V_32 , V_23 ? F_24 ( V_23 ) : L_2 ,
sizeof( V_19 -> V_32 ) ) ;
V_19 -> V_33 = F_16 ( V_17 ) -
( V_16 - V_21 -> V_34 ) * V_35 ;
V_19 -> V_36 = 0 ;
V_19 -> V_37 = V_8 ;
V_19 -> V_38 = 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
T_1 V_39 , T_3 * V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_19 ( V_7 ) ;
if ( V_39 == V_40 )
memcpy ( V_15 , * V_17 ,
sizeof( V_17 ) -
( V_16 - V_21 -> V_34 ) *
V_41 ) ;
}
static int F_26 ( struct V_1 * V_2 , int V_39 )
{
int V_42 = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_19 ( V_7 ) ;
switch ( V_39 ) {
case V_40 :
V_42 = F_16 ( V_17 ) -
( V_16 - V_21 -> V_34 ) *
V_35 ;
break;
default:
V_42 = - V_43 ;
}
return V_42 ;
}
static T_1 F_27 ( struct V_1 * V_2 )
{
return V_44 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_19 ( V_7 ) ;
return sizeof( V_21 -> V_45 . V_46 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_47 , T_3 * V_48 ,
T_3 * V_49 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_19 ( V_7 ) ;
unsigned int V_50 = 0U ;
if ( V_49 )
* V_49 = V_51 ;
if ( V_47 ) {
for ( V_50 = 0 ; V_50 < V_44 ; V_50 ++ )
V_47 [ V_50 ] = V_21 -> V_45 . V_52 [ V_50 ] ;
}
if ( V_48 )
memcpy ( V_48 , V_21 -> V_45 . V_46 ,
sizeof( V_21 -> V_45 . V_46 ) ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_53 * V_10 ,
T_1 * V_54 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_19 ( V_7 ) ;
int V_55 = 0 ;
switch ( V_10 -> V_10 ) {
case V_56 :
V_10 -> V_15 = V_21 -> V_34 ;
break;
default:
V_55 = - V_43 ;
break;
}
return V_55 ;
}
