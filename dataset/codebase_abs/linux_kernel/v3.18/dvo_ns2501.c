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
}
if ( ! V_6 -> V_20 ) {
F_3
( L_1 , V_3 ,
V_9 -> V_21 , V_2 -> V_15 ) ;
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
if ( F_2 ( V_9 , & V_22 , 1 ) == 1 ) {
return true ;
}
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
return V_30 ;
}
static enum V_31 F_9 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
F_3
( L_5 ,
V_33 -> V_34 , V_33 -> V_35 , V_33 -> V_36 , V_33 -> V_37 ) ;
if ( ( V_33 -> V_34 == 640 && V_33 -> V_36 == 480 && V_33 -> clock == 25175 ) ||
( V_33 -> V_34 == 800 && V_33 -> V_36 == 600 && V_33 -> clock == 40000 ) ||
( V_33 -> V_34 == 1024 && V_33 -> V_36 == 768 && V_33 -> clock == 65000 ) ) {
return V_38 ;
} else {
return V_39 ;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_32 * V_40 )
{
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
int V_41 , V_42 ;
F_3
( L_6 ,
V_33 -> V_34 , V_33 -> V_35 , V_33 -> V_36 , V_33 -> V_37 ) ;
if ( V_33 -> V_34 == 640 && V_33 -> V_36 == 480 )
V_41 = V_43 ;
else if ( V_33 -> V_34 == 800 && V_33 -> V_36 == 600 )
V_41 = V_44 ;
else if ( V_33 -> V_34 == 1024 && V_33 -> V_36 == 768 )
V_41 = V_45 ;
else
return;
for ( V_42 = 0 ; V_42 < F_11 ( V_46 ) ; V_42 ++ )
F_4 ( V_2 , V_46 [ V_42 ] . V_47 , V_46 [ V_42 ] . V_48 ) ;
V_6 -> V_49 = V_50 [ V_41 ] ;
for ( V_42 = 0 ; V_42 < 84 ; V_42 ++ )
F_4 ( V_2 , V_6 -> V_49 [ V_42 ] . V_47 , V_6 -> V_49 [ V_42 ] . V_48 ) ;
}
static bool F_12 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( ! F_1 ( V_2 , V_51 , & V_4 ) )
return false ;
return V_4 & V_52 ;
}
static void F_13 ( struct V_1 * V_2 , bool V_53 )
{
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
F_3 ( L_7 , V_53 ) ;
if ( V_53 ) {
if ( F_14 ( V_6 -> V_49 [ 83 ] . V_47 != 0x08 ||
V_6 -> V_49 [ 84 ] . V_47 != 0x41 ||
V_6 -> V_49 [ 85 ] . V_47 != 0xc0 ) )
return;
F_4 ( V_2 , 0xc0 , V_6 -> V_49 [ 85 ] . V_48 | 0x08 ) ;
F_4 ( V_2 , 0x41 , V_6 -> V_49 [ 84 ] . V_48 ) ;
F_4 ( V_2 , 0x34 , 0x01 ) ;
F_15 ( 15 ) ;
F_4 ( V_2 , 0x08 , 0x35 ) ;
if ( ! ( V_6 -> V_49 [ 83 ] . V_48 & V_54 ) )
F_4 ( V_2 , 0x08 , 0x31 ) ;
F_15 ( 200 ) ;
F_4 ( V_2 , 0x34 , 0x03 ) ;
F_4 ( V_2 , 0xc0 , V_6 -> V_49 [ 85 ] . V_48 ) ;
} else {
F_4 ( V_2 , 0x34 , 0x01 ) ;
F_15 ( 200 ) ;
F_4 ( V_2 , 0x08 , 0x34 ) ;
F_15 ( 15 ) ;
F_4 ( V_2 , 0x34 , 0x00 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
F_7 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
}
