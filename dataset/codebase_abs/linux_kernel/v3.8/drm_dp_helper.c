static int
F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
V_8 = (* V_7 -> V_9 )( V_2 , V_3 ,
V_4 , V_5 ) ;
return V_8 ;
}
static int
F_2 ( struct V_1 * V_2 , T_2 V_10 , bool V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 = V_12 ;
int V_8 ;
if ( V_11 )
V_3 |= V_13 ;
else
V_3 |= V_14 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_15 = true ;
V_8 = F_1 ( V_2 , V_3 , 0 , NULL ) ;
return V_8 ;
}
static void
F_3 ( struct V_1 * V_2 , bool V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 = V_16 ;
if ( V_11 )
V_3 |= V_13 ;
else
V_3 |= V_14 ;
if ( V_7 -> V_15 ) {
( void ) F_1 ( V_2 , V_3 , 0 , NULL ) ;
V_7 -> V_15 = false ;
}
}
static int
F_4 ( struct V_1 * V_2 , T_3 V_17 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_7 -> V_15 )
return - V_18 ;
V_8 = F_1 ( V_2 , V_14 , V_17 , NULL ) ;
return V_8 ;
}
static int
F_5 ( struct V_1 * V_2 , T_3 * V_19 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_7 -> V_15 )
return - V_18 ;
V_8 = F_1 ( V_2 , V_13 , 0 , V_19 ) ;
return V_8 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_22 )
{
int V_8 = 0 ;
bool V_11 = false ;
int V_23 ;
int V_24 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
T_2 V_25 = V_21 [ V_23 ] . V_25 ;
T_3 * V_26 = V_21 [ V_23 ] . V_26 ;
V_11 = ( V_21 [ V_23 ] . V_27 & V_28 ) != 0 ;
V_8 = F_2 ( V_2 , V_21 [ V_23 ] . V_29 , V_11 ) ;
if ( V_8 < 0 )
break;
if ( V_11 ) {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_8 = F_5 ( V_2 , & V_26 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
} else {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_8 = F_4 ( V_2 , V_26 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
}
if ( V_8 < 0 )
break;
}
if ( V_8 >= 0 )
V_8 = V_22 ;
F_3 ( V_2 , V_11 ) ;
F_7 ( L_1 , V_8 ) ;
return V_8 ;
}
static T_4
F_8 ( struct V_1 * V_2 )
{
return V_30 | V_31 |
V_32 |
V_33 |
V_34 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
( void ) F_2 ( V_2 , 0 , false ) ;
( void ) F_3 ( V_2 , false ) ;
}
static int
F_10 ( struct V_1 * V_2 )
{
V_2 -> V_35 = & V_36 ;
V_2 -> V_37 = 3 ;
F_9 ( V_2 ) ;
return 0 ;
}
int
F_11 ( struct V_1 * V_2 )
{
int error ;
error = F_10 ( V_2 ) ;
if ( error )
return error ;
error = F_12 ( V_2 ) ;
return error ;
}
static T_3 F_13 ( T_3 V_38 [ V_39 ] , int V_40 )
{
return V_38 [ V_40 - V_41 ] ;
}
static T_3 F_14 ( T_3 V_38 [ V_39 ] ,
int V_42 )
{
int V_43 = V_41 + ( V_42 >> 1 ) ;
int V_44 = ( V_42 & 1 ) * 4 ;
T_3 V_45 = F_13 ( V_38 , V_43 ) ;
return ( V_45 >> V_44 ) & 0xf ;
}
bool F_15 ( T_3 V_38 [ V_39 ] ,
int V_46 )
{
T_3 V_47 ;
T_3 V_48 ;
int V_42 ;
V_47 = F_13 ( V_38 ,
V_49 ) ;
if ( ( V_47 & V_50 ) == 0 )
return false ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_48 = F_14 ( V_38 , V_42 ) ;
if ( ( V_48 & V_51 ) != V_51 )
return false ;
}
return true ;
}
bool F_16 ( T_3 V_38 [ V_39 ] ,
int V_46 )
{
int V_42 ;
T_3 V_48 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_48 = F_14 ( V_38 , V_42 ) ;
if ( ( V_48 & V_52 ) == 0 )
return false ;
}
return true ;
}
T_3 F_17 ( T_3 V_38 [ V_39 ] ,
int V_42 )
{
int V_43 = V_53 + ( V_42 >> 1 ) ;
int V_44 = ( ( V_42 & 1 ) ?
V_54 :
V_55 ) ;
T_3 V_45 = F_13 ( V_38 , V_43 ) ;
return ( ( V_45 >> V_44 ) & 0x3 ) << V_56 ;
}
T_3 F_18 ( T_3 V_38 [ V_39 ] ,
int V_42 )
{
int V_43 = V_53 + ( V_42 >> 1 ) ;
int V_44 = ( ( V_42 & 1 ) ?
V_57 :
V_58 ) ;
T_3 V_45 = F_13 ( V_38 , V_43 ) ;
return ( ( V_45 >> V_44 ) & 0x3 ) << V_59 ;
}
void F_19 ( T_3 V_60 [ V_61 ] ) {
if ( V_60 [ V_62 ] == 0 )
F_20 ( 100 ) ;
else
F_21 ( V_60 [ V_62 ] * 4 ) ;
}
void F_22 ( T_3 V_60 [ V_61 ] ) {
if ( V_60 [ V_62 ] == 0 )
F_20 ( 400 ) ;
else
F_21 ( V_60 [ V_62 ] * 4 ) ;
}
T_3 F_23 ( int V_63 )
{
switch ( V_63 ) {
case 162000 :
default:
return V_64 ;
case 270000 :
return V_65 ;
case 540000 :
return V_66 ;
}
}
int F_24 ( T_3 V_67 )
{
switch ( V_67 ) {
case V_64 :
default:
return 162000 ;
case V_65 :
return 270000 ;
case V_66 :
return 540000 ;
}
}
