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
int V_25 ;
V_6 = F_6 ( sizeof( struct V_5 ) , V_26 ) ;
if ( V_6 == NULL )
return false ;
V_2 -> V_10 = V_9 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_21 = true ;
if ( ! F_1 ( V_2 , V_27 , & V_24 ) )
goto V_28;
V_6 -> V_21 = false ;
if ( ( V_24 & V_29 ) != V_2 -> V_15 ) {
F_3 ( L_4
L_5 ,
( V_24 & V_29 ) , V_2 -> V_15 ) ;
goto V_28;
}
F_1 ( V_2 , V_30 , & V_6 -> V_31 ) ;
F_1 ( V_2 , V_32 , & V_6 -> V_33 ) ;
for ( V_25 = 0 ; V_25 < F_7 ( V_34 ) ; V_25 ++ )
F_1 ( V_2 , V_34 [ V_25 ] , V_6 -> V_35 + V_25 ) ;
F_8 ( V_2 ) ;
return true ;
V_28:
F_9 ( V_6 ) ;
return false ;
}
static enum V_36 F_10 ( struct V_1 * V_2 )
{
return V_37 ;
}
static enum V_38 F_11 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
if ( V_40 -> clock > 112000 )
return V_41 ;
return V_42 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_25 ;
F_3 ( L_6 ) ;
F_4 ( V_2 , V_43 , 0x0000 ) ;
for ( V_25 = 0 ; V_25 < F_7 ( V_34 ) ; V_25 ++ )
F_4 ( V_2 , V_34 [ V_25 ] , V_6 -> V_35 [ V_25 ] ) ;
}
static void F_13 ( struct V_1 * V_2 , bool V_44 )
{
int V_25 ;
T_1 V_45 , V_46 , V_47 ;
F_12 ( V_2 ) ;
if ( ! F_1 ( V_2 , V_48 , & V_45 ) )
return;
if ( V_44 )
V_47 = 1 ;
else
V_47 = 0 ;
F_4 ( V_2 , V_49 , V_47 ) ;
if ( V_44 )
V_45 |= V_50 | V_51 ;
else
V_45 &= ~ ( V_50 | V_51 ) ;
F_4 ( V_2 , V_48 , V_45 ) ;
for ( V_25 = 0 ; V_25 < 100 ; V_25 ++ ) {
if ( ! F_1 ( V_2 , V_52 , & V_46 ) )
break;
if ( ( ( V_46 & V_53 ) != 0 ) == V_44 )
break;
F_14 ( 1000 ) ;
}
F_14 ( 16 * 1000 ) ;
}
static bool F_15 ( struct V_1 * V_2 )
{
T_1 V_45 ;
F_12 ( V_2 ) ;
if ( ! F_1 ( V_2 , V_48 , & V_45 ) )
return false ;
if ( V_45 & V_50 )
return true ;
else
return false ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_39 * V_54 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_55 = 0 ;
T_1 V_45 = 0 ;
T_1 V_56 ;
F_12 ( V_2 ) ;
V_56 = V_6 -> V_35 [ F_7 ( V_34 ) - 1 ] ;
V_56 &= V_57 ;
if ( V_56 == V_58 || V_56 == V_59 )
V_45 = V_60 ;
V_55 = ( V_61 | V_62 |
V_63 ) ;
if ( V_40 -> V_64 != V_54 -> V_64 ||
V_40 -> V_65 != V_54 -> V_65 ) {
T_1 V_66 , V_67 ;
V_45 |= V_68 ;
V_55 |= V_69 ;
V_66 = ( ( ( V_40 -> V_64 - 1 ) << 16 ) /
( V_54 -> V_64 - 1 ) ) >> 2 ;
V_67 = ( ( ( V_40 -> V_65 - 1 ) << 16 ) /
( V_54 -> V_65 - 1 ) ) >> 2 ;
F_4 ( V_2 , V_70 , V_66 ) ;
F_4 ( V_2 , V_71 , V_67 ) ;
} else {
V_45 &= ~ V_68 ;
V_55 &= ~ V_69 ;
}
V_55 &= ~ V_72 ;
F_4 ( V_2 , V_48 , V_45 ) ;
F_4 ( V_2 , V_73 , V_55 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_74 ;
F_1 ( V_2 , V_27 , & V_74 ) ;
F_3 ( L_7 , V_74 ) ;
F_1 ( V_2 , V_48 , & V_74 ) ;
F_3 ( L_8 , V_74 ) ;
F_1 ( V_2 , V_43 , & V_74 ) ;
F_3 ( L_9 , V_74 ) ;
F_1 ( V_2 , V_52 , & V_74 ) ;
F_3 ( L_10 , V_74 ) ;
F_1 ( V_2 , V_73 , & V_74 ) ;
F_3 ( L_11 , V_74 ) ;
F_1 ( V_2 , V_49 , & V_74 ) ;
F_3 ( L_12 , V_74 ) ;
F_1 ( V_2 , V_75 , & V_74 ) ;
F_3 ( L_13 , V_74 ) ;
F_1 ( V_2 , V_76 , & V_74 ) ;
F_3 ( L_14 , V_74 ) ;
F_1 ( V_2 , V_77 , & V_74 ) ;
F_3 ( L_15 , V_74 ) ;
F_1 ( V_2 , V_78 , & V_74 ) ;
F_3 ( L_16 , V_74 ) ;
F_1 ( V_2 , V_79 , & V_74 ) ;
F_3 ( L_17 , V_74 ) ;
F_1 ( V_2 , V_80 , & V_74 ) ;
F_3 ( L_18 , V_74 ) ;
F_1 ( V_2 , V_81 , & V_74 ) ;
F_3 ( L_19 , V_74 ) ;
F_1 ( V_2 , V_82 , & V_74 ) ;
F_3 ( L_20 , V_74 ) ;
F_1 ( V_2 , V_83 , & V_74 ) ;
F_3 ( L_21 , V_74 ) ;
F_1 ( V_2 , V_84 , & V_74 ) ;
F_3 ( L_22 , V_74 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
F_9 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
}
