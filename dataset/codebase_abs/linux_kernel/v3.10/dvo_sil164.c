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
static bool F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 ;
unsigned char V_4 ;
V_6 = F_6 ( sizeof( struct V_5 ) , V_23 ) ;
if ( V_6 == NULL )
return false ;
V_2 -> V_10 = V_9 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_20 = true ;
if ( ! F_1 ( V_2 , V_24 , & V_4 ) )
goto V_25;
if ( V_4 != ( V_26 & 0xff ) ) {
F_3 ( L_3 ,
V_4 , V_9 -> V_21 , V_2 -> V_15 ) ;
goto V_25;
}
if ( ! F_1 ( V_2 , V_27 , & V_4 ) )
goto V_25;
if ( V_4 != ( V_28 & 0xff ) ) {
F_3 ( L_3 ,
V_4 , V_9 -> V_21 , V_2 -> V_15 ) ;
goto V_25;
}
V_6 -> V_20 = false ;
F_3 ( L_4 ) ;
return true ;
V_25:
F_7 ( V_6 ) ;
return false ;
}
static enum V_29 F_8 ( struct V_1 * V_2 )
{
T_1 V_30 ;
F_1 ( V_2 , V_31 , & V_30 ) ;
if ( V_30 & V_32 )
return V_33 ;
else
return V_34 ;
}
static enum V_35 F_9 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
return V_38 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_36 * V_39 )
{
return;
}
static void F_11 ( struct V_1 * V_2 , bool V_40 )
{
int V_41 ;
unsigned char V_4 ;
V_41 = F_1 ( V_2 , V_42 , & V_4 ) ;
if ( V_41 == false )
return;
if ( V_40 )
V_4 |= V_43 ;
else
V_4 &= ~ V_43 ;
F_4 ( V_2 , V_42 , V_4 ) ;
return;
}
static bool F_12 ( struct V_1 * V_2 )
{
int V_41 ;
unsigned char V_4 ;
V_41 = F_1 ( V_2 , V_42 , & V_4 ) ;
if ( V_41 == false )
return false ;
if ( V_4 & V_43 )
return true ;
else
return false ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_1 ( V_2 , V_45 , & V_44 ) ;
F_14 ( L_5 , V_44 ) ;
F_1 ( V_2 , V_46 , & V_44 ) ;
F_14 ( L_6 , V_44 ) ;
F_1 ( V_2 , V_42 , & V_44 ) ;
F_14 ( L_7 , V_44 ) ;
F_1 ( V_2 , V_31 , & V_44 ) ;
F_14 ( L_8 , V_44 ) ;
F_1 ( V_2 , V_47 , & V_44 ) ;
F_14 ( L_9 , V_44 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
F_7 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
}
