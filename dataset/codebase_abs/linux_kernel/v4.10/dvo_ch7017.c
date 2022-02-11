static bool F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 [] = {
{
. V_3 = V_2 -> V_7 ,
. V_8 = 0 ,
. V_9 = 1 ,
. V_10 = & V_3 ,
} ,
{
. V_3 = V_2 -> V_7 ,
. V_8 = V_11 ,
. V_9 = 1 ,
. V_10 = V_4 ,
}
} ;
return F_2 ( V_2 -> V_12 , V_6 , 2 ) == 2 ;
}
static bool F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_2 V_10 [ 2 ] = { V_3 , V_4 } ;
struct V_5 V_13 = {
. V_3 = V_2 -> V_7 ,
. V_8 = 0 ,
. V_9 = 2 ,
. V_10 = V_10 ,
} ;
return F_2 ( V_2 -> V_12 , & V_13 , 1 ) == 1 ;
}
static bool F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 ;
const char * V_18 ;
T_1 V_4 ;
V_17 = F_5 ( sizeof( struct V_16 ) , V_19 ) ;
if ( V_17 == NULL )
return false ;
V_2 -> V_12 = V_15 ;
V_2 -> V_20 = V_17 ;
if ( ! F_1 ( V_2 , V_21 , & V_4 ) )
goto V_22;
switch ( V_4 ) {
case V_23 :
V_18 = L_1 ;
break;
case V_24 :
V_18 = L_2 ;
break;
case V_25 :
V_18 = L_3 ;
break;
default:
F_6 ( L_4
L_5 ,
V_4 , V_15 -> V_26 , V_2 -> V_7 ) ;
goto V_22;
}
F_6 ( L_6 ,
V_18 , V_15 -> V_26 , V_2 -> V_7 ) ;
return true ;
V_22:
F_7 ( V_17 ) ;
return false ;
}
static enum V_27 F_8 ( struct V_1 * V_2 )
{
return V_28 ;
}
static enum V_29 F_9 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
if ( V_31 -> clock > 160000 )
return V_32 ;
return V_33 ;
}
static void F_10 ( struct V_1 * V_2 ,
const struct V_30 * V_31 ,
const struct V_30 * V_34 )
{
T_2 V_35 , V_36 ;
T_2 V_37 , V_38 , V_39 ;
T_2 V_40 ;
T_2 V_41 , V_42 ;
T_2 V_43 ;
F_6 ( L_7 ) ;
F_11 ( V_2 ) ;
if ( V_31 -> clock < 100000 ) {
V_37 = V_44 | V_45 ;
V_35 = V_46 |
( 2 << V_47 ) |
( 13 << V_48 ) ;
V_36 = V_49 |
( 2 << V_50 ) |
( 3 << V_51 ) ;
V_38 = ( 1 << V_52 ) |
( 0 << V_53 ) ;
} else {
V_37 = V_44 | V_54 ;
V_35 = V_46 |
( 2 << V_47 ) |
( 3 << V_48 ) ;
V_35 = 35 ;
V_38 = ( 3 << V_52 ) |
( 0 << V_53 ) ;
if ( 1 ) {
V_37 |= V_55 ;
V_36 = V_49 |
( 2 << V_50 ) |
( 13 << V_51 ) ;
} else {
V_36 = V_49 |
( 1 << V_50 ) |
( 13 << V_51 ) ;
}
}
V_40 = V_31 -> V_56 & 0x00ff ;
V_42 = V_31 -> V_57 & 0x00ff ;
V_41 = V_31 -> V_56 & 0x00ff ;
V_43 = ( ( V_31 -> V_56 & 0x0700 ) >> 8 ) |
( ( ( V_31 -> V_57 & 0x0700 ) >> 8 ) << 3 ) ;
V_39 = V_58 |
( V_31 -> V_56 & 0x0700 ) >> 8 ;
F_12 ( V_2 , false ) ;
F_3 ( V_2 , V_59 ,
V_40 ) ;
F_3 ( V_2 , V_60 ,
V_41 ) ;
F_3 ( V_2 , V_61 ,
V_42 ) ;
F_3 ( V_2 , V_62 ,
V_43 ) ;
F_3 ( V_2 , V_63 , V_36 ) ;
F_3 ( V_2 , V_64 , V_35 ) ;
F_3 ( V_2 , V_65 , V_38 ) ;
F_3 ( V_2 , V_66 , V_37 ) ;
F_3 ( V_2 , V_67 , V_39 ) ;
F_6 ( L_8 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 , bool V_68 )
{
T_2 V_4 ;
F_1 ( V_2 , V_67 , & V_4 ) ;
F_3 ( V_2 , V_69 ,
V_70 |
V_71 |
V_72 |
V_73 |
V_74 ) ;
if ( V_68 ) {
F_3 ( V_2 , V_67 ,
V_4 & ~ V_75 ) ;
} else {
F_3 ( V_2 , V_67 ,
V_4 | V_75 ) ;
}
F_13 ( 20 ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
T_2 V_4 ;
F_1 ( V_2 , V_67 , & V_4 ) ;
if ( V_4 & V_75 )
return false ;
else
return true ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_2 V_4 ;
#define F_15 ( T_3 ) \
do { \
ch7017_read(dvo, reg, &val); \
DRM_DEBUG_KMS(#reg ": %02x\n", val); \
} while (0)
F_15 ( V_59 ) ;
F_15 ( V_60 ) ;
F_15 ( V_61 ) ;
F_15 ( V_62 ) ;
F_15 ( V_63 ) ;
F_15 ( V_64 ) ;
F_15 ( V_65 ) ;
F_15 ( V_66 ) ;
F_15 ( V_67 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_20 ;
if ( V_17 ) {
F_7 ( V_17 ) ;
V_2 -> V_20 = NULL ;
}
}
