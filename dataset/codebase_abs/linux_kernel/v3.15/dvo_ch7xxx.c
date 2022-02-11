static char * F_1 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_1 == V_1 )
return V_3 [ V_2 ] . V_4 ;
}
return NULL ;
}
static char * F_3 ( T_1 V_5 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 ) ; V_2 ++ ) {
if ( V_6 [ V_2 ] . V_5 == V_5 )
return V_6 [ V_2 ] . V_4 ;
}
return NULL ;
}
static bool F_4 ( struct V_7 * V_8 , int V_9 , T_1 * V_10 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_14 * V_15 = V_8 -> V_16 ;
T_2 V_17 [ 2 ] ;
T_2 V_18 [ 2 ] ;
struct V_19 V_20 [] = {
{
. V_9 = V_8 -> V_21 ,
. V_22 = 0 ,
. V_23 = 1 ,
. V_24 = V_17 ,
} ,
{
. V_9 = V_8 -> V_21 ,
. V_22 = V_25 ,
. V_23 = 1 ,
. V_24 = V_18 ,
}
} ;
V_17 [ 0 ] = V_9 ;
V_17 [ 1 ] = 0 ;
if ( F_5 ( V_15 , V_20 , 2 ) == 2 ) {
* V_10 = V_18 [ 0 ] ;
return true ;
} ;
if ( ! V_12 -> V_26 ) {
F_6 ( L_1 ,
V_9 , V_15 -> V_4 , V_8 -> V_21 ) ;
}
return false ;
}
static bool F_7 ( struct V_7 * V_8 , int V_9 , T_1 V_10 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_14 * V_15 = V_8 -> V_16 ;
T_1 V_17 [ 2 ] ;
struct V_19 V_27 = {
. V_9 = V_8 -> V_21 ,
. V_22 = 0 ,
. V_23 = 2 ,
. V_24 = V_17 ,
} ;
V_17 [ 0 ] = V_9 ;
V_17 [ 1 ] = V_10 ;
if ( F_5 ( V_15 , & V_27 , 1 ) == 1 )
return true ;
if ( ! V_12 -> V_26 ) {
F_6 ( L_2 ,
V_9 , V_15 -> V_4 , V_8 -> V_21 ) ;
}
return false ;
}
static bool F_8 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
struct V_11 * V_12 ;
T_1 V_28 , V_29 ;
char * V_4 , * V_30 ;
V_12 = F_9 ( sizeof( struct V_11 ) , V_31 ) ;
if ( V_12 == NULL )
return false ;
V_8 -> V_16 = V_15 ;
V_8 -> V_13 = V_12 ;
V_12 -> V_26 = true ;
if ( ! F_4 ( V_8 , V_32 , & V_28 ) )
goto V_33;
V_4 = F_1 ( V_28 ) ;
if ( ! V_4 ) {
F_6 ( L_3
L_4 ,
V_28 , V_15 -> V_4 , V_8 -> V_21 ) ;
goto V_33;
}
if ( ! F_4 ( V_8 , V_34 , & V_29 ) )
goto V_33;
V_30 = F_3 ( V_29 ) ;
if ( ! V_30 ) {
F_6 ( L_3
L_4 ,
V_28 , V_15 -> V_4 , V_8 -> V_21 ) ;
goto V_33;
}
V_12 -> V_26 = false ;
F_6 ( L_5 ,
V_4 , V_28 , V_29 ) ;
return true ;
V_33:
F_10 ( V_12 ) ;
return false ;
}
static enum V_35 F_11 ( struct V_7 * V_8 )
{
T_1 V_36 , V_37 , V_38 ;
F_4 ( V_8 , V_39 , & V_37 ) ;
V_38 = V_37 ;
V_38 &= ~ V_40 ;
V_38 |= V_41 | V_42 ;
F_7 ( V_8 , V_39 , V_38 ) ;
F_4 ( V_8 , V_43 , & V_36 ) ;
F_7 ( V_8 , V_39 , V_37 ) ;
if ( V_36 & V_44 )
return V_45 ;
return V_46 ;
}
static enum V_47 F_12 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
if ( V_49 -> clock > 165000 )
return V_50 ;
return V_51 ;
}
static void F_13 ( struct V_7 * V_8 ,
struct V_48 * V_49 ,
struct V_48 * V_52 )
{
T_1 V_53 , V_54 , V_55 , V_56 , V_57 ;
if ( V_49 -> clock <= 65000 ) {
V_53 = 0x23 ;
V_54 = 0x08 ;
V_55 = 0x16 ;
V_56 = 0x60 ;
} else {
V_53 = 0x2d ;
V_54 = 0x06 ;
V_55 = 0x26 ;
V_56 = 0xa0 ;
}
F_7 ( V_8 , V_58 , 0x00 ) ;
F_7 ( V_8 , V_59 , V_53 ) ;
F_7 ( V_8 , V_60 , V_54 ) ;
F_7 ( V_8 , V_61 , V_55 ) ;
F_7 ( V_8 , V_62 , 0x30 ) ;
F_7 ( V_8 , V_63 , V_56 ) ;
F_7 ( V_8 , V_64 , 0x00 ) ;
F_4 ( V_8 , V_65 , & V_57 ) ;
V_57 &= ~ ( V_66 | V_67 ) ;
if ( V_49 -> V_22 & V_68 )
V_57 |= V_66 ;
if ( V_49 -> V_22 & V_69 )
V_57 |= V_67 ;
F_7 ( V_8 , V_65 , V_57 ) ;
}
static void F_14 ( struct V_7 * V_8 , bool V_70 )
{
if ( V_70 )
F_7 ( V_8 , V_39 , V_41 | V_42 ) ;
else
F_7 ( V_8 , V_39 , V_40 ) ;
}
static bool F_15 ( struct V_7 * V_8 )
{
T_2 V_71 ;
F_4 ( V_8 , V_39 , & V_71 ) ;
if ( V_71 & ( V_41 | V_42 ) )
return true ;
else
return false ;
}
static void F_16 ( struct V_7 * V_8 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_72 ; V_2 ++ ) {
T_1 V_71 ;
if ( ( V_2 % 8 ) == 0 )
F_6 ( L_6 , V_2 ) ;
F_4 ( V_8 , V_2 , & V_71 ) ;
F_6 ( L_7 , V_71 ) ;
}
}
static void F_17 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
if ( V_12 ) {
F_10 ( V_12 ) ;
V_8 -> V_13 = NULL ;
}
}
