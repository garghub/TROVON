static bool F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_2 V_11 [ 2 ] ;
T_2 V_12 [ 2 ] ;
struct V_13 V_14 [] = {
{
. V_3 = V_2 -> V_15 ,
. V_16 = 0 ,
. V_17 = 1 ,
. V_18 = V_11 ,
} ,
{
. V_3 = V_2 -> V_15 ,
. V_16 = V_19 ,
. V_17 = 1 ,
. V_18 = V_12 ,
}
} ;
V_11 [ 0 ] = V_3 ;
V_11 [ 1 ] = 0 ;
if ( F_2 ( V_9 , V_14 , 2 ) == 2 ) {
* V_4 = V_12 [ 0 ] ;
return true ;
} ;
if ( ! V_6 -> V_20 ) {
F_3 ( L_1 ,
V_3 , V_9 -> V_21 , V_2 -> V_15 ) ;
}
return false ;
}
static bool F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_11 [ 2 ] ;
struct V_13 V_22 = {
. V_3 = V_2 -> V_15 ,
. V_16 = 0 ,
. V_17 = 2 ,
. V_18 = V_11 ,
} ;
V_11 [ 0 ] = V_3 ;
V_11 [ 1 ] = V_4 ;
if ( F_2 ( V_9 , & V_22 , 1 ) == 1 )
return true ;
if ( ! V_6 -> V_20 ) {
F_3 ( L_2 ,
V_3 , V_9 -> V_21 , V_2 -> V_15 ) ;
}
return false ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_23 , V_24 ;
if ( F_1 ( V_2 , V_3 + 0 , & V_23 ) &&
F_1 ( V_2 , V_3 + 1 , & V_24 ) )
return ( ( V_24 << 8 ) & 0xFF00 ) | ( V_23 & 0x00FF ) ;
return - 1 ;
}
static bool F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 ;
int V_25 ;
V_6 = F_7 ( sizeof( struct V_5 ) , V_26 ) ;
if ( V_6 == NULL )
return false ;
V_2 -> V_10 = V_9 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_20 = true ;
if ( ( V_25 = F_5 ( V_2 , V_27 ) ) != V_28 ) {
F_3 ( L_3
L_4 ,
V_25 , V_9 -> V_21 , V_2 -> V_15 ) ;
goto V_29;
}
if ( ( V_25 = F_5 ( V_2 , V_30 ) ) != V_31 ) {
F_3 ( L_5
L_4 ,
V_25 , V_9 -> V_21 , V_2 -> V_15 ) ;
goto V_29;
}
V_6 -> V_20 = false ;
return true ;
V_29:
F_8 ( V_6 ) ;
return false ;
}
static enum V_32 F_9 ( struct V_1 * V_2 )
{
enum V_32 V_33 = V_34 ;
T_1 V_35 ;
if ( F_1 ( V_2 , V_36 , & V_35 ) ) {
if ( V_35 & V_37 )
V_33 = V_38 ;
else
V_33 = V_34 ;
}
return V_33 ;
}
static enum V_39 F_10 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
return V_42 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_43 )
{
return;
}
static void F_12 ( struct V_1 * V_2 , int V_41 )
{
T_1 V_44 ;
if ( ! F_1 ( V_2 , V_45 , & V_44 ) )
return;
if ( V_41 == V_46 )
V_44 |= V_47 ;
else
V_44 &= ~ V_47 ;
F_4 ( V_2 , V_45 , V_44 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_48 , V_49 ;
F_1 ( V_2 , V_50 , & V_48 ) ;
F_14 ( L_6 , V_48 ) ;
F_1 ( V_2 , V_45 , & V_48 ) ;
F_14 ( L_7 , V_48 ) ;
F_1 ( V_2 , V_36 , & V_48 ) ;
F_14 ( L_8 , V_48 ) ;
F_1 ( V_2 , V_51 , & V_48 ) ;
F_14 ( L_9 , V_48 ) ;
F_1 ( V_2 , V_52 , & V_48 ) ;
F_14 ( L_10 , V_48 ) ;
F_1 ( V_2 , V_53 , & V_48 ) ;
F_14 ( L_11 , V_48 ) ;
F_1 ( V_2 , V_54 , & V_48 ) ;
F_14 ( L_12 , V_48 ) ;
F_1 ( V_2 , V_55 , & V_48 ) ;
F_14 ( L_13 , V_48 ) ;
F_1 ( V_2 , V_56 , & V_48 ) ;
F_1 ( V_2 , V_57 , & V_49 ) ;
F_14 ( L_14 , V_49 , V_48 ) ;
F_1 ( V_2 , V_58 , & V_48 ) ;
F_1 ( V_2 , V_59 , & V_49 ) ;
F_14 ( L_15 , V_49 , V_48 ) ;
F_1 ( V_2 , V_60 , & V_48 ) ;
F_1 ( V_2 , V_61 , & V_49 ) ;
F_14 ( L_16 , V_49 , V_48 ) ;
F_1 ( V_2 , V_62 , & V_48 ) ;
F_1 ( V_2 , V_63 , & V_49 ) ;
F_14 ( L_17 , V_49 , V_48 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
F_8 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
}
