static bool F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_2 V_11 [ 1 ] ;
T_2 V_12 [ 2 ] ;
struct V_13 V_14 [] = {
{
. V_3 = V_2 -> V_15 ,
. V_16 = V_17 ,
. V_18 = 0 ,
} ,
{
. V_3 = 0 ,
. V_16 = V_19 ,
. V_18 = 1 ,
. V_20 = V_11 ,
} ,
{
. V_3 = V_2 -> V_15 ,
. V_16 = V_17 | V_19 ,
. V_18 = 2 ,
. V_20 = V_12 ,
}
} ;
V_11 [ 0 ] = V_3 ;
if ( F_2 ( V_9 , V_14 , 3 ) == 3 ) {
* V_4 = ( V_12 [ 1 ] << 8 ) | V_12 [ 0 ] ;
return true ;
} ;
if ( ! V_6 -> V_21 ) {
F_3 ( L_1
L_2 ,
V_3 , V_9 -> V_22 , V_2 -> V_15 ) ;
}
return false ;
}
static bool F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_2 V_11 [ 3 ] ;
struct V_13 V_23 = {
. V_3 = V_2 -> V_15 ,
. V_16 = 0 ,
. V_18 = 3 ,
. V_20 = V_11 ,
} ;
V_11 [ 0 ] = V_3 ;
V_11 [ 1 ] = V_4 & 0xff ;
V_11 [ 2 ] = V_4 >> 8 ;
if ( F_2 ( V_9 , & V_23 , 1 ) == 1 )
return true ;
if ( ! V_6 -> V_21 ) {
F_3 ( L_3 ,
V_3 , V_9 -> V_22 , V_2 -> V_15 ) ;
}
return false ;
}
static bool F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 ;
T_1 V_24 ;
V_6 = F_6 ( sizeof( struct V_5 ) , V_25 ) ;
if ( V_6 == NULL )
return false ;
V_2 -> V_10 = V_9 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_21 = true ;
if ( ! F_1 ( V_2 , V_26 , & V_24 ) )
goto V_27;
V_6 -> V_21 = false ;
if ( ( V_24 & V_28 ) != V_2 -> V_15 ) {
F_3 ( L_4
L_5 ,
( V_24 & V_28 ) , V_2 -> V_15 ) ;
goto V_27;
}
F_1 ( V_2 , V_29 , & V_6 -> V_30 ) ;
F_1 ( V_2 , V_31 , & V_6 -> V_32 ) ;
return true ;
V_27:
F_7 ( V_6 ) ;
return false ;
}
static enum V_33 F_8 ( struct V_1 * V_2 )
{
return V_34 ;
}
static enum V_35 F_9 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
if ( V_37 -> clock > 112000 )
return V_38 ;
return V_39 ;
}
static void F_10 ( struct V_1 * V_2 , int V_37 )
{
int V_40 ;
T_1 V_41 , V_42 , V_43 ;
if ( ! F_1 ( V_2 , V_44 , & V_41 ) )
return;
if ( V_37 == V_45 )
V_43 = 1 ;
else
V_43 = 0 ;
F_4 ( V_2 , V_46 , V_43 ) ;
if ( V_37 == V_45 )
V_41 |= V_47 | V_48 ;
else
V_41 &= ~ ( V_47 | V_48 ) ;
F_4 ( V_2 , V_44 , V_41 ) ;
for ( V_40 = 0 ; V_40 < 100 ; V_40 ++ ) {
if ( ! F_1 ( V_2 , V_49 , & V_42 ) )
break;
if ( ( ( V_42 & V_50 ) != 0 ) == ( V_37 == V_45 ) )
break;
F_11 ( 1000 ) ;
}
F_11 ( 16 * 1000 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_36 * V_51 )
{
T_1 V_52 = 0 ;
T_1 V_41 ;
V_41 = 0 ;
V_52 = ( V_53 | V_54 |
V_55 ) ;
if ( V_37 -> V_56 != V_51 -> V_56 ||
V_37 -> V_57 != V_51 -> V_57 ) {
T_1 V_58 , V_59 ;
V_41 |= V_60 ;
V_52 |= V_61 ;
V_58 = ( ( ( V_37 -> V_56 - 1 ) << 16 ) /
( V_51 -> V_56 - 1 ) ) >> 2 ;
V_59 = ( ( ( V_37 -> V_57 - 1 ) << 16 ) /
( V_51 -> V_57 - 1 ) ) >> 2 ;
F_4 ( V_2 , V_62 , V_58 ) ;
F_4 ( V_2 , V_63 , V_59 ) ;
} else {
V_41 &= ~ V_60 ;
V_52 &= ~ V_61 ;
}
V_52 &= ~ V_64 ;
F_4 ( V_2 , V_44 , V_41 ) ;
F_4 ( V_2 , V_65 , V_52 ) ;
F_13 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_66 ;
F_1 ( V_2 , V_26 , & V_66 ) ;
F_14 ( L_6 , V_66 ) ;
F_1 ( V_2 , V_44 , & V_66 ) ;
F_14 ( L_7 , V_66 ) ;
F_1 ( V_2 , V_49 , & V_66 ) ;
F_14 ( L_8 , V_66 ) ;
F_1 ( V_2 , V_65 , & V_66 ) ;
F_14 ( L_9 , V_66 ) ;
F_1 ( V_2 , V_46 , & V_66 ) ;
F_14 ( L_10 , V_66 ) ;
F_1 ( V_2 , V_67 , & V_66 ) ;
F_14 ( L_11 , V_66 ) ;
F_1 ( V_2 , V_68 , & V_66 ) ;
F_14 ( L_12 , V_66 ) ;
F_1 ( V_2 , V_69 , & V_66 ) ;
F_14 ( L_13 , V_66 ) ;
F_1 ( V_2 , V_70 , & V_66 ) ;
F_14 ( L_14 , V_66 ) ;
F_1 ( V_2 , V_71 , & V_66 ) ;
F_14 ( L_15 , V_66 ) ;
F_1 ( V_2 , V_72 , & V_66 ) ;
F_14 ( L_16 , V_66 ) ;
F_1 ( V_2 , V_73 , & V_66 ) ;
F_14 ( L_17 , V_66 ) ;
F_1 ( V_2 , V_74 , & V_66 ) ;
F_14 ( L_18 , V_66 ) ;
F_1 ( V_2 , V_75 , & V_66 ) ;
F_14 ( L_19 , V_66 ) ;
F_1 ( V_2 , V_76 , & V_66 ) ;
F_14 ( L_20 , V_66 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
F_7 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
}
