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
}
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
static void F_10 ( struct V_1 * V_2 , bool V_40 )
{
int V_41 ;
T_1 V_42 , V_43 , V_44 ;
if ( ! F_1 ( V_2 , V_45 , & V_42 ) )
return;
if ( V_40 )
V_44 = 1 ;
else
V_44 = 0 ;
F_4 ( V_2 , V_46 , V_44 ) ;
if ( V_40 )
V_42 |= V_47 | V_48 ;
else
V_42 &= ~ ( V_47 | V_48 ) ;
F_4 ( V_2 , V_45 , V_42 ) ;
for ( V_41 = 0 ; V_41 < 100 ; V_41 ++ ) {
if ( ! F_1 ( V_2 , V_49 , & V_43 ) )
break;
if ( ( ( V_43 & V_50 ) != 0 ) == V_40 )
break;
F_11 ( 1000 ) ;
}
F_11 ( 16 * 1000 ) ;
}
static bool F_12 ( struct V_1 * V_2 )
{
T_1 V_42 ;
if ( ! F_1 ( V_2 , V_45 , & V_42 ) )
return false ;
if ( V_42 & V_47 )
return true ;
else
return false ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_36 * V_51 )
{
T_1 V_52 = 0 ;
T_1 V_42 = 0 ;
T_1 V_53 ;
F_1 ( V_2 , V_54 , & V_53 ) ;
V_53 &= V_55 ;
if ( V_53 == V_56 || V_53 == V_57 )
V_42 = V_58 ;
V_52 = ( V_59 | V_60 |
V_61 ) ;
if ( V_37 -> V_62 != V_51 -> V_62 ||
V_37 -> V_63 != V_51 -> V_63 ) {
T_1 V_64 , V_65 ;
V_42 |= V_66 ;
V_52 |= V_67 | V_68 ;
V_64 = ( ( ( V_37 -> V_62 - 1 ) << 16 ) /
( V_51 -> V_62 - 1 ) ) >> 2 ;
V_65 = ( ( ( V_37 -> V_63 - 1 ) << 16 ) /
( V_51 -> V_63 - 1 ) ) >> 2 ;
F_4 ( V_2 , V_69 , V_64 ) ;
F_4 ( V_2 , V_70 , V_65 ) ;
} else {
V_42 &= ~ V_66 ;
V_52 &= ~ V_67 ;
}
V_52 &= ~ V_71 ;
F_4 ( V_2 , V_45 , V_42 ) ;
F_4 ( V_2 , V_72 , V_52 ) ;
F_14 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_73 ;
F_1 ( V_2 , V_26 , & V_73 ) ;
F_3 ( L_6 , V_73 ) ;
F_1 ( V_2 , V_45 , & V_73 ) ;
F_3 ( L_7 , V_73 ) ;
F_1 ( V_2 , V_54 , & V_73 ) ;
F_3 ( L_8 , V_73 ) ;
F_1 ( V_2 , V_49 , & V_73 ) ;
F_3 ( L_9 , V_73 ) ;
F_1 ( V_2 , V_72 , & V_73 ) ;
F_3 ( L_10 , V_73 ) ;
F_1 ( V_2 , V_46 , & V_73 ) ;
F_3 ( L_11 , V_73 ) ;
F_1 ( V_2 , V_74 , & V_73 ) ;
F_3 ( L_12 , V_73 ) ;
F_1 ( V_2 , V_75 , & V_73 ) ;
F_3 ( L_13 , V_73 ) ;
F_1 ( V_2 , V_76 , & V_73 ) ;
F_3 ( L_14 , V_73 ) ;
F_1 ( V_2 , V_77 , & V_73 ) ;
F_3 ( L_15 , V_73 ) ;
F_1 ( V_2 , V_78 , & V_73 ) ;
F_3 ( L_16 , V_73 ) ;
F_1 ( V_2 , V_79 , & V_73 ) ;
F_3 ( L_17 , V_73 ) ;
F_1 ( V_2 , V_80 , & V_73 ) ;
F_3 ( L_18 , V_73 ) ;
F_1 ( V_2 , V_81 , & V_73 ) ;
F_3 ( L_19 , V_73 ) ;
F_1 ( V_2 , V_82 , & V_73 ) ;
F_3 ( L_20 , V_73 ) ;
F_1 ( V_2 , V_83 , & V_73 ) ;
F_3 ( L_21 , V_73 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
F_7 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
}
