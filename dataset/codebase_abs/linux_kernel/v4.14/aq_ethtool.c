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
struct V_16 * V_17 = F_15 ( V_7 ) ;
memset ( V_15 , 0 , ( F_16 ( V_18 ) +
F_16 ( V_19 ) *
V_17 -> V_20 ) * sizeof( T_2 ) ) ;
F_17 ( V_7 , V_15 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_15 ( V_7 ) ;
struct V_23 * V_24 = F_19 ( V_2 -> V_25 . V_26 ) ;
T_1 V_27 = F_20 ( V_7 ) ;
T_1 V_8 = F_3 ( V_7 ) ;
F_21 ( V_22 -> V_28 , V_29 , sizeof( V_22 -> V_28 ) ) ;
F_21 ( V_22 -> V_30 , V_31 , sizeof( V_22 -> V_30 ) ) ;
snprintf ( V_22 -> V_32 , sizeof( V_22 -> V_32 ) ,
L_1 , V_27 >> 24 ,
( V_27 >> 16 ) & 0xFFU , V_27 & 0xFFFFU ) ;
F_22 ( V_22 -> V_33 , V_24 ? F_23 ( V_24 ) : L_2 ,
sizeof( V_22 -> V_33 ) ) ;
V_22 -> V_34 = F_16 ( V_18 ) +
V_17 -> V_20 * F_16 ( V_19 ) ;
V_22 -> V_35 = 0 ;
V_22 -> V_36 = V_8 ;
V_22 -> V_37 = 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
T_1 V_38 , T_3 * V_15 )
{
int V_39 , V_40 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_15 ( V_7 ) ;
T_3 * V_5 = V_15 ;
if ( V_38 == V_41 ) {
memcpy ( V_5 , * V_18 ,
sizeof( V_18 ) ) ;
V_5 = V_5 + sizeof( V_18 ) ;
for ( V_39 = 0 ; V_39 < V_17 -> V_20 ; V_39 ++ ) {
for ( V_40 = 0 ;
V_40 < F_16 ( V_19 ) ;
V_40 ++ ) {
snprintf ( V_5 , V_42 ,
V_19 [ V_40 ] , V_39 ) ;
V_5 += V_42 ;
}
}
}
}
static int F_25 ( struct V_1 * V_2 , int V_38 )
{
int V_43 = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_15 ( V_7 ) ;
switch ( V_38 ) {
case V_41 :
V_43 = F_16 ( V_18 ) +
V_17 -> V_20 * F_16 ( V_19 ) ;
break;
default:
V_43 = - V_44 ;
}
return V_43 ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
return V_45 ;
}
static T_1 F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_15 ( V_7 ) ;
return sizeof( V_17 -> V_46 . V_47 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_48 , T_3 * V_49 ,
T_3 * V_50 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_15 ( V_7 ) ;
unsigned int V_39 = 0U ;
if ( V_50 )
* V_50 = V_51 ;
if ( V_48 ) {
for ( V_39 = 0 ; V_39 < V_45 ; V_39 ++ )
V_48 [ V_39 ] = V_17 -> V_46 . V_52 [ V_39 ] ;
}
if ( V_49 )
memcpy ( V_49 , V_17 -> V_46 . V_47 ,
sizeof( V_17 -> V_46 . V_47 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_53 * V_10 ,
T_1 * V_54 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_15 ( V_7 ) ;
int V_55 = 0 ;
switch ( V_10 -> V_10 ) {
case V_56 :
V_10 -> V_15 = V_17 -> V_20 ;
break;
default:
V_55 = - V_44 ;
break;
}
return V_55 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_15 ( V_7 ) ;
if ( V_17 -> V_59 == V_60 ||
V_17 -> V_59 == V_61 ) {
V_58 -> V_62 = V_17 -> V_63 ;
V_58 -> V_64 = V_17 -> V_65 ;
V_58 -> V_66 = 0 ;
V_58 -> V_67 = 0 ;
} else {
V_58 -> V_62 = 0 ;
V_58 -> V_64 = 0 ;
V_58 -> V_66 = 1 ;
V_58 -> V_67 = 1 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_15 ( V_7 ) ;
if ( V_58 -> V_68 || V_58 -> V_69 )
return - V_44 ;
if ( V_58 -> V_66 > 1 ||
V_58 -> V_70 ||
V_58 -> V_71 )
return - V_44 ;
if ( V_58 -> V_67 > 1 ||
V_58 -> V_72 ||
V_58 -> V_73 )
return - V_44 ;
if ( ! ( V_58 -> V_66 == ! V_58 -> V_62 ) )
return - V_44 ;
if ( ! ( V_58 -> V_67 == ! V_58 -> V_64 ) )
return - V_44 ;
if ( V_58 -> V_62 > V_74 ||
V_58 -> V_64 > V_74 )
return - V_75 ;
V_17 -> V_59 = V_60 ;
V_17 -> V_63 = V_58 -> V_62 ;
V_17 -> V_65 = V_58 -> V_64 ;
return F_32 ( V_7 ) ;
}
